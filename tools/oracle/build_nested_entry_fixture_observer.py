#!/usr/bin/env python3
"""Build a separate Flycast observer that permits rollback-scoped child fixtures.

The original executable, linked objects, and source tree are read-only. The
only changed object is a temporary patched copy of vf3oracle.cpp; the resulting
observer is diagnostic and must not be used for coverage acceptance.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import shlex
import subprocess
from pathlib import Path

from ram_clipping_batch_audit import reference

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path("C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence")
BUILD = ROOT / "tools/emu/flycast-build"
ORIGINAL_SHA256 = "b84119778244e85e247a85481900a0de9f9b11e99dd0b85830136942bf2fb3c2"
OLD = '''            if (fixture!=entryPatches.end()) {
                if (!active.empty()) {
                    std::fprintf(stderr,"[vf3oracle] nested entry fixture at %08x\\n",canon);
                    std::abort();
                }
                for (const auto &word:fixture->second)
                    std::memcpy(&mem_b[word[0]&0x00ffffffu],&word[1],4);
            }'''
NEW = '''            if (fixture!=entryPatches.end()) {
                /* A watched child fixture is safe only inside the single live
                 * synthetic parent whose complete RAM image is restored at
                 * finish(). Flush and invalidate the guest cache line before
                 * changing main RAM so the child observes the seeded word. */
                if (!active.empty()) {
                    const bool rollbackParent = observingProbe && active.size()==1
                        && active.front().synthetic && !active.front().aborted;
                    if (!rollbackParent) {
                        std::fprintf(stderr,"[vf3oracle] nested entry fixture outside rollback parent at %08x\\n",canon);
                        std::abort();
                    }
                }
                for (const auto &word:fixture->second) {
                    const unsigned line=word[0]&0x00ffffffu;
                    ocache.WriteBack(0x8C000000u+line,true,true);
                    std::memcpy(&mem_b[line],&word[1],4);
                }
            }'''


def digest(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def response_paths(path: Path) -> list[Path]:
    return [Path(value.strip('"')) for value in shlex.split(path.read_text(), posix=False)]


def build(out_dir: Path) -> Path:
    baseline = CACHE / "task_return_boundary_v1_linked_sources/manifest.json"
    original = json.loads(baseline.read_text())
    original_exe = Path(original["executable"])
    assert digest(original_exe) == ORIGINAL_SHA256 == original["sha256"]
    source = ROOT / "tools/emu/flycast/core/vf3oracle.cpp"
    oracle_copy = ROOT / "tools/oracle/vf3oracle.cpp"
    source_sha = digest(source)
    assert source_sha == digest(oracle_copy), "working Flycast oracle source is no longer baseline"
    for row in original["files"]:
        assert digest(ROOT / row["path"]) == row["sha256"], f"changed linked source: {row['path']}"
        assert digest(baseline.parent / row["path"]) == row["sha256"], f"changed source archive: {row['path']}"

    text = source.read_text()
    assert text.count(OLD) == 1, "expected fixture block changed; inspect before patching"
    patched = text.replace(OLD, NEW)
    assert "rollbackParent = observingProbe" in patched
    out_dir = out_dir.resolve()
    if out_dir.exists():
        raise FileExistsError(f"refusing to overwrite observer build directory: {out_dir}")
    out_dir.mkdir(parents=True)
    changed_source = out_dir / "vf3oracle.cpp"
    changed_source.write_text(patched)

    flags_path = BUILD / "CMakeFiles/flycast.dir/flags.make"
    objects_path = BUILD / "CMakeFiles/flycast.dir/objects1.rsp"
    includes_path = BUILD / "CMakeFiles/flycast.dir/includes_CXX.rsp"
    libraries_path = BUILD / "CMakeFiles/flycast.dir/linkLibs.rsp"
    objects = [(BUILD / path).resolve() for path in response_paths(objects_path)]
    replaced = [path for path in objects if path.name == "vf3oracle.cpp.obj"]
    assert len(replaced) == 1
    libraries = [(BUILD / path).resolve() for path in response_paths(libraries_path)
                 if str(path).endswith(".a")]
    inputs = [baseline, original_exe, source, oracle_copy, flags_path, objects_path,
              includes_path, libraries_path, *objects, *libraries,
              *[ROOT / row["path"] for row in original["files"]]]
    expected = {str(path): digest(path) for path in inputs}

    definitions = re.search(r"^CXX_DEFINES = (.*)$", flags_path.read_text(), re.M).group(1).split()
    options = re.search(r"^CXX_FLAGS = (.*)$", flags_path.read_text(), re.M).group(1).split()
    compiler = "C:/msys64/ucrt64/bin/c++.exe"
    changed_object = out_dir / "vf3oracle.cpp.obj"
    compile_command = [compiler, *definitions, "@"+str(includes_path), *options,
                       "-MD", "-MF", str(out_dir/"vf3oracle.cpp.obj.d"),
                       "-c", str(changed_source), "-o", str(changed_object)]
    subprocess.run(compile_command, cwd=BUILD, check=True)
    response = out_dir / "objects.rsp"
    response.write_text(" ".join('"'+str(changed_object if path == replaced[0] else path).replace("\\", "/")+'"'
                                 for path in objects))
    archive = out_dir / "objects.a"
    subprocess.run(["C:/msys64/ucrt64/bin/ar.exe", "qc", str(archive), "@"+str(response)],
                   cwd=BUILD, check=True)
    executable = out_dir / "flycast_nested_entry_fixture.exe"
    link_command = [compiler, "-DVF3_HEADLESS", "-DVF3_ALWAYS_INTERPRETER", "-O2", "-g",
                    "-DNDEBUG", "-mconsole", "-mwindows", "-fopenmp", "-static",
                    "-Wl,--whole-archive", str(archive), "-Wl,--no-whole-archive",
                    "-o", str(executable), "@"+str(libraries_path)]
    subprocess.run(link_command, cwd=BUILD, check=True)
    for path, expected_sha in expected.items():
        assert digest(Path(path)) == expected_sha, f"baseline input changed during build: {path}"
    manifest = {
        "coverage_credit": False,
        "diagnostic_observer_only": True,
        "executable": str(executable),
        "executable_sha256": digest(executable),
        "original_executable": str(original_exe),
        "original_executable_sha256": ORIGINAL_SHA256,
        "source_change": "allow one watched child RAM fixture inside a single active synthetic parent; flush/invalidate each affected SH-4 cache line before seeding",
        "source_sha256": digest(changed_source),
        "compile_command": compile_command,
        "link_command": link_command,
        "baseline_inputs": {path: sha for path, sha in expected.items()},
    }
    (out_dir / "manifest.json").write_text(json.dumps(manifest, indent=2)+"\n")
    return executable


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out-dir", type=Path, required=True)
    args = parser.parse_args()
    print(build(args.out_dir))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
