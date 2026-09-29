# 0x8C09D9EC captured FPU setup path

## Boundary and dataflow

The baseline span is 50 bytes. It saves PR, calls the setup kernel at
`0x0C03CCB0`, loads the object at `r14`, then calls `0x0C03C880`,
`0x0C03C940`, and `0x0C03C880` with the halfwords at offsets `+0x1E`,
`+0x1F50`, and `+0x1F52`. It loads the halfword at `+0x1F54`, restores PR,
and tail-jumps to `0x0C03C6C0`; the jump delay slot restores r14.

The helper-step probe recorded 324 paired samples at the entry and after each
call. In the captured path, the entry XF matrix is identity in all 64 unique
cases. The three setup calls leave the rotation from `r14+0x1E` in FR0/2/4/6
and in XF entries 0/2/8/10. The offsets `+0x1F50` and `+0x1F52` are zero in
all cases; `+0x1F54` is copied to r4 immediately before the tail jump. The
boundary output has r0=`0x1F54`, r3=`0x0C03C6C0`, and r15 advanced by four.

## Oracle replay

`tools/watch/vf3_d9ec_port.txt` captures a tail-boundary exit, ten RAM windows
(including both observed stack positions), and the XF sidecars. The capture
has 340 paired invocations, 64 unique entry/exit vectors, and no unpaired
records. The replay checks registers, all ten RAM windows, and both 16-word XF
matrices. The bounded FSCA table contains the three observed angle inputs:
`0x663D`, `0xCC16`, and `0xCC17`. Other angles, nonzero `+0x1F50/+0x1F52`
fields, non-identity XF input, and other FPSCR modes are rejected by the port;
they remain uncovered paths.
