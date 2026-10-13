"""Exercise the resident menu's remaining progress and task-flag paths.

Builds on the typed resident-menu v2 fixture while varying the caller's real
task flag at R4+8 and the menu's progress counter. These are original RAM
inputs; ROM lookup tables and expected outputs remain untouched.
"""
import json
from pathlib import Path

from tenpp_probe_plan import generate


ROOT = Path(__file__).resolve().parents[2]
ENTRY = 0x8C09B36C
OWNER = 0x8C09B37E
COUNT = 256


def prepare() -> None:
    name = "coverage_65_batch_resident_dev_v3"
    directory = ROOT / "tools/oracle/percentage_inputs"
    source = directory / "coverage_65_batch_resident_dev_v2_memory.json"
    registers_source = directory / "coverage_65_batch_resident_dev_v2_registers.json"
    memory_fields = json.loads(source.read_text())[hex(ENTRY)]
    registers = json.loads(registers_source.read_text())[hex(ENTRY)]

    fields = dict(memory_fields)
    # The menu reads R4+8 when it considers swapping the two selected slots.
    fields["0xc400008"] = [
        0x10000000 if (i // 8) % 2 else 0 for i in range(COUNT)
    ]
    # This counter controls the >48 clamp branch near the end of the owner.
    fields["0xc29ba68"] = [
        (0, 48, 49, 64)[(i // 16) % 4] for i in range(COUNT)
    ]
    # Keep distinct typed menu events in the same set, including the bit-4
    # event that reaches the task-flag-controlled swap.
    fields["0xc2cf83c"] = [
        (0, 16, 32, 64)[i % 4] for i in range(COUNT)
    ]
    fields["0xc29ba54"] = [i // 8 % 4 for i in range(COUNT)]
    fields["0xc29ba58"] = [[0, 5, 6, 7, 8, 9][i // 32 % 6] for i in range(COUNT)]
    fields["0xc29ba5c"] = [i // 128 % 2 for i in range(COUNT)]
    fields["0xc29ba6c"] = 5
    fields["0xc29ba60"] = 22
    fields["0xc29ba64"] = 22
    fields["0xc29bccc"] = 0
    fields["0xc2cf844"] = [[0, 8, 0x400, 0x408][i // 32 % 4] for i in range(COUNT)]
    fields["0xc29b870"] = 0
    fields["0xc29ba80"] = 0

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
