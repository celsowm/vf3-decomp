# Native TA and VRAM reference path

`src/render/pvr_ta.c` is an independent C99 implementation of a deliberately
limited PVR data path. It consumes the original game's store-queue output and
guest-addressed VRAM writes. It does not invent geometry from a POL bounding
box, replay a picture, or depend on an emulator renderer. It is not yet a
complete or pixel-exact Dreamcast renderer, and these tests do not establish
playable or visually equivalent VF3tb.

## Integration and lifetime

Create a caller-owned `vf3_pvr`, then use `vf3_native_attach_pvr(pvr)` after
`vf3_native_reset()`. The adapter forwards accesses from the native device
bus. PVR state persists across native function calls, independently of the
legacy per-invocation TA diagnostic buffer. Detach or reset the native session
before destroying the PVR. An individual PVR instance contains all its state.

Bus reads/writes return **1 handled, 0 unhandled, -1 error**. Errors retain the
first code, address, PCW, packet number and static explanatory message.
`vf3_pvr_begin_frame()` clears the scene and error but retains VRAM, registers
and the last successful framebuffer; `vf3_pvr_reset()` also clears those.
TA_LIST_INIT bit 31 starts a scene. STARTRENDER invokes the renderer. Both
complete material validation and packet completeness checks precede changing
the visible image. Failed rendering retains the last successful image and
returns an error; callers must report that failure, not present it as a new
successful frame.

The framebuffer is a borrowed 640x480 `0xAARRGGBB` array compatible with the
SDL presentation interface. Call `vf3_pvr_framebuffer()` after rendering rather
than retaining its pointer across rendering: the two image buffers swap.
`vf3_pvr_get_stats()` and `vf3_pvr_triangle_at()` expose decoded diagnostics.
`vf3_pvr_texel()` checks individual fixture texels through the same decoder.

Native DMA scheduling is separate. A DMA owner must copy its actual guest RAM
payload through `vf3_pvr_write_block()` at the programmed destination before
signalling completion. Merely raising a DMA interrupt does not populate VRAM
or feed TA. This module does not synthesize DMA completion or PVR interrupts.

## Addressed writes

Physical addresses are obtained with `address & 0x1fffffff`, so cached and
uncached SH-4 aliases reach the same device. Scalar VRAM accesses accept 1, 2
or 4 little-endian bytes; registers and scalar FIFO writes require aligned
32-bit words. FIFO blocks can be split at any byte boundary, including in the
middle of a 64-byte header. VRAM blocks advance their address and are checked
before writing; a cross-boundary write fails without partially writing VRAM.

| Physical range | Interpretation |
| --- | --- |
| `04000000..047fffff`, `06000000..067fffff` | canonical 64-bit-interleaved 8 MiB VRAM view |
| `05000000..057fffff`, `07000000..077fffff` | 32-bit bank view of the same storage |
| upper 8 MiB of each above 16 MiB window | rejected unmapped view |
| `10000000..107fffff`, `12000000..127fffff` | TA FIFO; address chooses port, not packet offset |
| `10800000..10ffffff`, `12800000..12ffffff` | unsupported YUV converter, explicit error |
| `11000000..11ffffff`, `13000000..13ffffff` | direct VRAM writes, mirrored at 8 MiB |
| `005f6884`, `005f6888` | direct-path bank mode for the two texture windows |
| `005f8000..005f9fff` | raw register latches and the commands described above |

For a 32-bit-view byte offset `a`, canonical offset is
`((a & 0x3ffffc) << 1) | ((a & 0x400000) >> 20) | (a & 3)`.
Thus 32-bit words at bank offsets 0 and 0x400000 become adjacent words in the
canonical 64-bit view. Direct-path mode 0 selects the canonical view, mode 1
the bank view. Other mode bits are rejected.

Readback is available for written register latches, ID and revision. Unwritten
registers are **unhandled**, not fabricated zero status. SPG_STATUS
`005f810c` is always unhandled, even if a raw value was written: the native
runtime owns beam timing. Register latching alone does not implement the
effect of every PVR register; this reference renders a fixed host surface,
not a packed/interlaced video-output framebuffer.

## Original stream format and supported subset

The first model header in the supplied `MKAO_AKI.POL` is at `0x35b30`:

```
8000002c 83000000 20082440 04000000
```

The same prefix exists in ST01; GEN_DMY5 uses a related TSP word. These are
material records, not complete captured TA lists. The live header emitter
`poly_header_sq.c` (entry `0x0c055e00`) supplies the remaining header from the
shading template at `0x0c16b820`, emitting two 32-byte store queues for this
PCW. `vertex_emit.c` (entry `0x0c048be0`) emits each transformed vertex.

| Packet | Words, in guest order |
| --- | --- |
| VF3 intensity + offset header, 64 bytes | 0 PCW, 1 ISP, 2 TSP, 3 TCW; 4..7 reserved; 8..11 face A/R/G/B float; 12..15 offset A/R/G/B float |
| Supported vertex, 32 bytes | 0 control; 1 X, 2 Y, 3 inverse Z; 4 U, 5 V; 6 base ARGB or intensity; 7 offset ARGB or intensity |
| End of list, 32 bytes | parameter type 0 in word 0; remaining words ignored |

The type field is PCW bits 29..31. A vertex is type 7; bit 28 terminates the
strip. The original emitter can produce controls such as `e0000040` and
`f000004a`, not just constant `e0000000`/`f0000000`. Both the raw control and
every raw header word are retained. Intensity multiplies RGB; alpha comes
from the face color. Colors are clamped and quantized to 8 bits before
rasterization. Strip winding alternates; flat shading uses the third vertex.

Additional parsed headers are 32-byte packed-color, 32-byte intensity without
offset, and previous-intensity reuse after an intensity header. A new header
cannot interrupt an unfinished strip; an end-of-list must follow a completed
strip. A list cannot change identity without an end marker. Floating vertex
colors, 16-bit UV, sprites and modifier-volume formats fail explicitly.
The diagnostic parser accepts translucent headers, but the renderer rejects
them until sorting is implemented.

Texture support covers RGB565, ARGB1555 and ARGB4444, in linear row order or
square/rectangular twiddled order, with dimensions `8 << exponent` from TSP.
Twiddle interleaves **Y in even bits, X in odd bits**. Rectangles are a sequence
of squares whose side is the shorter dimension. This differs from the
experimental `tools/tex_peek.py` axis order; that script is not the authority
for the native decoder. Texture addresses are VRAM byte offsets `(TCW &
0xfffff) << 3`; reads outside the 8 MiB store fail. VQ, mipmaps, stride,
palettes, YUV and bump formats fail instead of substituting white textures.

The scalar renderer implements opaque and punch-through lists, alternating
triangle strips, viewport clipping, fixed 8-bit subpixel edge tests and the
top-left fill rule. It includes reciprocal-depth comparisons/write disable,
culling, flat/Gouraud colors, perspective UV, point/bilinear sampling,
repeat/mirror/clamp, the four texture environments, RGB offset addition,
the blend factors and punch-through alpha reference. Opaque lists precede
punch-through lists. The reference clear is opaque black at inverse depth 0.

Unsupported active material states return an error: translucency/sorting,
user clipping, fog, color clamp, supersampling, secondary accumulation and
trilinear filtering. Nonzero background-plane configuration,
render-to-texture, and list-continuation commands also fail. In particular,
the **unmodified AKI header requests table fog and is rejected for rendering**;
the parser fixture uses it unchanged, while raster tests explicitly select
no fog and known RGB565 texture state. No test claims that altered material
is a golden VF3 frame.

The host reference does not model ISP/TSP rounding bit-for-bit, full video
output/scaling, background parameter memory, tile allocation, interrupt
timing or arbitrary register effects. Those remain work for a full native
port. Fixed dimensions and reference precision are explicit API constraints.
Use IEEE binary32 floats, compile without fast-math or FP contraction. No SDL,
graphics driver or platform intrinsic is needed by the module itself.

## Evidence and validation

`tests/pvr_ta_test.c` is ROM-free by default. CMake links the real native runtime
and original C emitters with `VF3_PVR_TEST_EMITTERS=1`. Tests cover every byte
split of a representative 192-byte header/triangle/list stream; incomplete
and malformed streams; raw EOS controls; intensity alpha; VRAM aliases and
bank modes; boundary failure and sticky errors; twiddle axes and rectangles;
texture formats; depth comparison modes; last-frame retention after error;
a 32x32 strip square covered exactly once; culling and provoking color;
bilinear, wrap, mirror, clamp, perspective texture sampling; and punch-through.

The integration fixture runs the **actual** header and vertex emitter C
functions both directly through the SQ model and through separate
`vf3_native_tick_run()` calls. The header survives three subsequent vertex
calls although the old per-call TA diagnostics restart at each call. A reset
probe fills both real SQ buffers, verifies both PREF destinations/payloads,
resets the native session, and verifies zero buffers and zero QACR areas.
Fixture coordinates, template colors and register seeds are synthetic and
identified as such; no synthetic snapshot is labelled game capture evidence.

```
cmake --build build --target vf3pvrtest
ctest --test-dir build -R '^pvr_ta$' --output-on-failure
build/vf3pvrtest --assets extract/gamedata
```

The optional assets test checks the actual AKI material prefix and three
independently decoded texels from its first 64x64 RGB565 texture. Assets are
read from the user's local extraction; none are copied into source control.
This adds asset-byte evidence, not an end-to-end screenshot comparison.

| Local fixture | Bytes | SHA-256 |
| --- | ---: | --- |
| MKAO_AKI.POL | 312752 | `817d838eb326dd58d1aa869a52fce51a8be876a9a2ac7369da368ba640e94581` |
| MKAO_AKI.TEX | 155648 | `a78e8ba6fd59319faaad0dfd29a99653cefc1d46941a02f2bde9d38c482e7357` |

No complete paired TA/VRAM/frame capture was available in the supplied
analysis import for this work. The imported tick report records failures for
missing golden snapshots. Existing per-function traces do not supply a full
render comparison. A valid next milestone needs a complete real command
stream, matching VRAM, all active rendering state, and a reference image;
new formats must be supported and tested before that stream can succeed.

## Format provenance and public-source retrieval

The implementation was written independently from register/format definitions
and local VF3 emitters. No Flycast or other GPL renderer implementation was
copied or linked. Public primary SDK references inspected on 2026-10-21:

- [KallistiOS PVR header fields](https://kos-docs.dreamcast.wiki/pvr__header_8h_source.html)
  and the [SDK header source](https://github.com/KallistiOS/KallistiOS/blob/master/kernel/arch/dreamcast/include/dc/pvr/pvr_header.h):
  PCW/ISP/TSP/TCW fields and enum meanings.
- [KallistiOS PVR register definitions](https://kos-docs.dreamcast.wiki/pvr__regs_8h_source.html):
  register addresses and control meanings.
- [KallistiOS PVR public interface](https://kos-docs.dreamcast.wiki/pvr_8h_source.html):
  vertex/material structures.
- [KallistiOS texture upload source](https://github.com/KallistiOS/KallistiOS/blob/master/kernel/arch/dreamcast/hardware/pvr/pvr_texture.c):
  checked only to resolve twiddle axis order and rectangular square tiling;
  decoder/raster code here is an independent implementation.
- Local `src/fight/poly_header_sq.c`, `src/fight/vertex_emit.c` and
  `src/fight/matrix_family.c`: exact game packet construction and SQ burst path.

Source-discovery note: the SDK documentation is public static HTML and the
GitHub files have public raw text endpoints. A few direct HTTP reads were
sufficient; no login, pagination, crawling or browser automation was needed.
The Sega manual mirror at
`https://segaretro.org/images/7/78/DreamcastDevBoxSystemArchitecture.pdf`
returned HTTP 403; it was not bypassed or represented as a fully read manual.
Search-index excerpts helped cross-check intensity/flat shading, but they
are not complete specification evidence or proof of pixel equivalence.
