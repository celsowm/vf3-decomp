"""Probe the resident menu's >48 clamp and task-stack flag gate."""
import json
from pathlib import Path

from tenpp_probe_plan import generate


ROOT = Path(__file__).resolve().parents[2]
ENTRY = 0x8C09B36C
OWNER = 0x8C09B37E
COUNT = 256


def prepare() -> None:
    name = "coverage_65_batch_resident_dev_v5"
    directory = ROOT / "tools/oracle/percentage_inputs"
    fields = dict(json.loads((directory / "coverage_65_batch_resident_dev_v2_memory.json").read_text())[hex(ENTRY)])
    registers = json.loads((directory / "coverage_65_batch_resident_dev_v2_registers.json").read_text())[hex(ENTRY)]
    fields["0xc29b86c"] = 3
    fields["0xc11e504"] = 0x04000000
    fields["0xc29ba68"] = 0x1000
    # At this callable prefix the reserved stack word is the task pointer
    # consumed by the tail at 0x8c09b64c; give it a bounded real RAM object.
    fields["0xc40dfdc"] = 0x0c400000
    fields["0xc400008"] = 0x10000000

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
