"""Probe the resident menu's alternate configured-event and task-flag paths."""
import json
from pathlib import Path

from tenpp_probe_plan import generate


ROOT = Path(__file__).resolve().parents[2]
ENTRY = 0x8C09B36C
OWNER = 0x8C09B37E
COUNT = 256


def prepare() -> None:
    name = "coverage_65_batch_resident_dev_v4"
    directory = ROOT / "tools/oracle/percentage_inputs"
    memory_path = directory / "coverage_65_batch_resident_dev_v2_memory.json"
    register_path = directory / "coverage_65_batch_resident_dev_v2_registers.json"
    fields = dict(json.loads(memory_path.read_text())[hex(ENTRY)])
    registers = json.loads(register_path.read_text())[hex(ENTRY)]

    # The event helper uses the configured byte at 0xc11e507 only when the
    # original UI mode byte at 0xc29b86c is 3. The byte is encoded in the high
    # lane of the aligned little-endian word at 0xc11e504.
    fields["0xc29b86c"] = 3
    fields["0xc11e504"] = 0x04000000

    # These values reach the owner tail's existing counter clamp and task
    # swap checks through the original R4 task object.
    fields["0xc400008"] = 0x10000000
    fields["0xc29ba68"] = 49

    watch = ROOT / f"tools/oracle/{name}_watch.txt"
    owners = ROOT / f"tools/oracle/{name}_owners.json"
    watch.write_text(f"pc {hex(ENTRY)}\n")
    owners.write_text(json.dumps({hex(ENTRY): hex(OWNER)}, indent=2) + "\n")
    memory = {hex(ENTRY): fields}
    (directory / f"{name}_memory.json").write_text(json.dumps(memory, indent=2) + "\n")
    (directory / f"{name}_registers.json").write_text(
        json.dumps({hex(ENTRY): registers}, indent=2) + "\n"
    )
    generate(
        watch,
        ROOT / f"extract/analysis/{name}.patch",
        0x8C0432E2,
        COUNT,
        fpscr=0x40001,
        bounded_arguments=True,
        preserve_fields=True,
        register_overrides={hex(ENTRY): registers},
        memory_overrides=memory,
    )


if __name__ == "__main__":
    prepare()
