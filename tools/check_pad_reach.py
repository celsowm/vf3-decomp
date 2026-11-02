#!/usr/bin/env python3
"""check_pad_reach.py - does the host's button reach the guest?

The chain is:

    the host's pad  ->  vf3_native_set_maple_pad  ->  the Maple model's
    answer  ->  the guest's Maple buffer

The guest asks the Maple model for the pad's state with a GET_CONDITION
request, and the model writes the answer into the receive address the
request named.  The Maple model's log names that address
(`VF3_MAPLELOG=1` prints "recv"), so this tool takes it from the log.

The answer's layout (the Maple wire):

    +0   the reply's header
    +4   the function code
    +8   the buttons (u16, active low: a zero bit is a pressed button)
    +10  the right trigger, +11 the left trigger
    +12  the X axis, +13 the Y axis, +14 and +15 the second D-pad

    python tools/check_pad_reach.py --ram build/ram.bin --log build/boot.log \\
        --press 8
"""
from __future__ import annotations

import argparse
import re
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

RAM_BASE = 0x0C000000
RAM_LEN = 0x01000000

# The Maple wire's numbers (the KOS numbering the reference uses).
BTN_C = 0x0001
BTN_B = 0x0002
BTN_A = 0x0004
BTN_START = 0x0008
BTN_UP = 0x0010
BTN_DOWN = 0x0020
BTN_LEFT = 0x0040
BTN_RIGHT = 0x0080
BTN_Y = 0x0200
BTN_X = 0x0400

NAMES = {
    BTN_C: "C", BTN_B: "B", BTN_A: "A", BTN_START: "START",
    BTN_UP: "UP", BTN_DOWN: "DOWN", BTN_LEFT: "LEFT", BTN_RIGHT: "RIGHT",
    BTN_Y: "Y", BTN_X: "X",
}

# The reference's mask: the buttons a standard pad has no button for always
# read as released (flycast's maple_sega_controller::getButtonState).
PAD_MASK = 0xF901

# The Maple model's log line for a GET_CONDITION request: the frame's command
# is 9, so the frame word ends with 09.
GETCOND = re.compile(r"block at [0-9a-f]+ head [0-9a-f]+ recv ([0-9a-f]+) frame [0-9a-f]*09\b")


def find_recv(log: Path) -> int | None:
    """The receive address of the last GET_CONDITION request in the log."""
    recv = None
    try:
        text = log.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return None
    for m in GETCOND.finditer(text):
        recv = int(m.group(1), 16)
    return recv


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n")[0])
    ap.add_argument("--ram", type=Path, required=True,
                    help="the RAM the port dumped (--dump-ram)")
    ap.add_argument("--log", type=Path, required=True,
                    help="the port's log (VF3_MAPLELOG=1 names the receive address)")
    ap.add_argument("--press", type=lambda s: int(s, 0), default=0,
                    help="the button mask the host held down")
    ap.add_argument("--recv", type=lambda s: int(s, 0), default=None,
                    help="the receive address (default: the last GET_CONDITION in the log)")
    args = ap.parse_args()

    data = args.ram.read_bytes()
    if len(data) < RAM_LEN:
        print(f"check_pad_reach: the dump is {len(data)} B, the RAM window is {RAM_LEN} B")
        return 2

    recv = args.recv
    if recv is None:
        recv = find_recv(args.log)
    if recv is None:
        print("check_pad_reach: no GET_CONDITION request in the log - run with VF3_MAPLELOG=1")
        return 2

    off = recv - RAM_BASE
    (buttons,) = struct.unpack_from("<H", data, off + 8)
    axes = data[off + 10:off + 16]
    pressed = [name for bit, name in sorted(NAMES.items()) if not (buttons & bit)]
    print(f"the Maple answer at {recv:08x}: buttons {buttons:04x}, "
          f"axes {' '.join('%02x' % b for b in axes)}")
    print("  pressed: " + (", ".join(pressed) if pressed else "nothing"))

    want = ((~args.press) | PAD_MASK) & 0xFFFF
    if buttons != want:
        print(f"check_pad_reach: FAIL - the answer carries {buttons:04x}, want {want:04x}")
        return 1
    print("check_pad_reach: the host's button reached the guest")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
