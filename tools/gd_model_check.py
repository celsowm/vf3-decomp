#!/usr/bin/env python3
"""gd_model_check.py - check the GD-ROM model against recorded loader invocations.

Joins a VF3CAP6 capsule (extract/analysis/capsule_<name>_s<N>.bin) with the observer's VF3_GDLOG file (the REIOS command
state at each watched entry/exit, keyed by invocation id) and, for the syscall stubs, compares what the C model
(src/sys/gdrom_hle.c) would do with the recorded exit state and r0:

  0x8C0430A0  GET_CMD_STAT (r4 = request id): state advances as vf3_gd_get_cmd_stat does
  0x8C0432DE  its wrapper: r0 is the status mapped to 0 / 4 / 1 (idle / busy / complete)
  0x8C0430B4  EXEC_SERVER: state unchanged unless a DMA read is BUSY (then it arms once)

  python tools/gd_model_check.py extract/analysis/capsule_loader_gd42_s42.bin extract/analysis/gdlog_s42.txt
"""
import struct
import sys

PAGE = 4096
OK, BUSY, COMPLETE, CONTINUE = 0, 1, 2, 3
FIELDS = ['last_request_id', 'next_request_id', 'status', 'command', 'p0', 'p1', 'p2', 'p3',
          'r0', 'r1', 'r2', 'r3', 'cur_sector', 'multi_read_sector', 'multi_read_offset', 'multi_read_count']


def signed(v):
    return v - (1 << 32) if v & 0x80000000 else v


def read_capsule(path):
    data = open(path, 'rb').read()
    assert data[:8] == b'VF3CAP6\0', data[:8]
    pos, out = 8, []
    while pos + 36 <= len(data):
        inv_id = struct.unpack_from('<Q', data, pos)[0]
        entry, exitpc, flags, npages, nops, nregs, ndev = struct.unpack_from('<7I', data, pos + 8)
        pos += 8 + 28
        regs_in = struct.unpack_from('<63I', data, pos)
        regs_out = struct.unpack_from('<63I', data, pos + 252)
        pos += 504 + npages * (4 + 2 * PAGE) + nops * 8 + ndev * 16
        out.append((inv_id, entry, exitpc, flags, regs_in, regs_out))
    return out


def read_gdlog(path):
    rec = {}
    for line in open(path):
        f = line.split()
        if len(f) != 3 + 16:
            continue
        rec[(f[0], int(f[1]))] = [int(x, 16) for x in f[3:]]
    return rec


def model_get_cmd_stat(state, request_id):
    st = dict(zip(FIELDS, state))
    ret = signed(st['status'])
    if ret in (OK, BUSY):
        return ret, st
    if request_id != st['last_request_id']:
        return OK, st
    if ret == CONTINUE and st['multi_read_count'] == 0:
        st['status'] = COMPLETE
        st['r3'] = 0
    elif ret != CONTINUE:
        st['status'] = OK
        st['last_request_id'] = 0xFFFFFFFF
    return ret, st


def main():
    cap, log = read_capsule(sys.argv[1]), read_gdlog(sys.argv[2])
    stats = {}
    for inv_id, entry, exitpc, flags, rin, rout in cap:
        if (entry & 0x1FFFFFFF) not in (0x0C0430A0, 0x0C0430B4, 0x0C0432DE) or flags:
            continue
        s, e = log.get(('S', inv_id)), log.get(('E', inv_id))
        if s is None or e is None:
            continue
        key = hex(entry & 0x1FFFFFFF)
        row = stats.setdefault(key, [0, 0, 0])
        row[0] += 1
        if (entry & 0x1FFFFFFF) in (0x0C0430A0, 0x0C0432DE):
            # the stub's jmp returns straight to its caller, so its capsule exit is the outer return: for 0x8C0430A0
            # only the state is checked; the 0x8C0432DE wrapper maps the status to its own code (BUSY -> 4)
            ret, st = model_get_cmd_stat(s, rin[4])
            wrapper = {OK: 0, BUSY: 4, COMPLETE: 1}
            ok_ret = (entry & 0x1FFFFFFF) == 0x0C0430A0 or wrapper.get(ret) == rout[0]
            ok_state = [st[k] for k in FIELDS] == e
        else:
            ok_ret = True          # EXEC_SERVER's r0 is not the model's output
            ok_state = s == e or signed(s[2]) == BUSY
        row[1] += ok_ret
        row[2] += ok_state
    for key, (n, r, s) in sorted(stats.items()):
        print(f'{key}: {n} invocations, r0 matches {r}, exit state matches {s}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
