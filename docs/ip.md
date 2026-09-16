# IP.BIN header

| offset | field | value |
|---|---|---|
| 0x000 | Hardware ID | `SEGA SEGAKATANA` |
| 0x010 | Maker ID | `SEGA ENTERPRISES` |
| 0x020 | CRC (hex ascii) | `A053` |
| 0x024 | Device info | `GD-ROM1/1` |
| 0x030 | Area codes | `U` |
| 0x038 | Compatible peripherals | `01BB810` |
| 0x040 | Product number | `MK-51001` |
| 0x04A | Version | `V1.002` |
| 0x050 | Release date | `19990820` |
| 0x058 | (padding) | `''` |
| 0x060 | Boot filename | `1ST_READ.BIN` |
| 0x070 | Software maker | `SEGA ENTERPRISES` |
| 0x080 | Title | `VF3TB` |

## Words at 0x300-0x33F (IP init area: entry/stack/settings)

| offset | LE u32 | hex |
|---|---|---|
| 0x300 | 3507015687 | 0xD108D007 |
| 0x304 | 3741650967 | 0xDF051017 |
| 0x308 | 3507015687 | 0xD108D007 |
| 0x30C | 1076576554 | 0x402B412A |
| 0x310 | 1129512969 | 0x43530009 |
| 0x314 | 942684227 | 0x38303843 |
| 0x318 | 602419 | 0x00093133 |
| 0x31C | 2113933312 | 0x7E001000 |
| 0x320 | 4278190080 | 0xFF000000 |
| 0x324 | 2347 | 0x0000092B |
| 0x328 | 2348843944 | 0x8C0083A8 |
| 0x32C | 2885728000 | 0xAC00B700 |
| 0x330 | 3523989770 | 0xD20BD10A |
| 0x334 | 3607876364 | 0xD70BD30C |
| 0x338 | 1158178083 | 0x45086523 |
| 0x33C | 1159214380 | 0x4518352C |

Note: retail games are loaded and entered at 0x8C010000 via 1ST_READ.BIN.
