# Fight audio transition and real callback

Callable `0x8c099060` saves r14/r13 and establishes the scene/input registers.
Frozen owner `0x8c099070` covers 232 bytes; its earlier campaign captured only
66 of them. The new source is `src/fight/audio_fight.c`, with separately
recovered scene and rendering dependencies in `audio_fight_scene.c` and
`audio_fight_render.c`.

The input word comes from scene `0x0c29b864 + 0x138`. Mode 1 uses its low word;
mode 3 combines the original word with its arithmetic shift by eight; other
modes select the shifted word. Bit `0x800` increments the signed word at
`0x0c29bcc4 + 0x3e2`. A positive scene +12 skips the audio/publication path.
Otherwise a counter greater than 16 sets object flag `0x800`; two float words
come from the object pointer at +`0x1c8`, offsets +`0x430` and +`0x438`, and are
copied into +`0x3e4` and +`0x3e8`.

Mode selects an actor. Flag 4 instead selects its override byte at +`0x415` or
+`0x41a`. The caller publishes the raw style and subtracts 13 once when needed,
copies both actors' +`0x201c` bytes and +70 words, clears the counter, disables
the referenced object at the pointer-table +80 slot, invokes the general
request wrapper with `0x000300a0`, submits both actor styles and increments the
scene byte +11. The bit-accurate register model retains all temporary and saved
state, not just these publication effects.

The caller then restores PR/r13/r14 and tail-jumps physically to `0x0c097ff4`.
Flag `0x20000`, or the absence of both `0x10000000` and `0x20000000`, returns.
Other paths update scene fields and select callback index 10 through the real
dispatcher `0x0c0968d0`. The immutable table at `0x0c10baa8` supplies
`0x0c09a284`; it is read and checked rather than patched or replaced.

Callback 10 submits ID 51, changes referenced objects' active bits, publishes
scene fields, updates the style-count bytes through `0x0c0c3b40`, and invokes
the actual rendering dependencies. These publish a three-vertex packet,
write the PVR background-color register `0xa05f80b0`, initialize an overlay,
and register its later handler. The overlay helper is explicitly restricted
to this callback's zero integer/float arguments and single-width FPU state.
Its clear loop stores **129** float words, including the final iteration after
the count reaches 128. Other interpolation arguments and table-dispatch
targets fail explicitly; no generic renderer or all-callback implementation
is claimed. The registered later handler is not executed by this invocation.

The first two eight-case native pilots execute all 232 frozen body bytes and
match, including real callback paths and bounded style-count loops. An initial
native mismatch exposed an incorrect float source base; the implementation
was corrected to use the pointer at +`0x1c8`. Failed pilot evidence is retained.
A fresh eight-pair live pilot matches the complete original/C invocation and
all device checkpoints. Executables and sources were frozen before the larger
development and independently held-out acceptance campaigns.

Both larger campaigns pass: **64/64 development and 64/64 acceptance cases**
match strict live original/C comparison and native replay, with zero skips,
rejected specimens or quarantined entries. Development uses states 26/27;
acceptance uses states 28/29, stack `0x0c3fd000`, relocated owned actors and
float-source objects, and changed modes, masks, counters and styles. Each
corpus executes all 232 frozen body bytes. All 128 live comparisons cross real
AICA events; **80** execute callback 10 and the PVR write. A deliberate real
C queue-word corruption fails the strict comparison as expected.

The independent evidence auditor checks original opcode bytes, complete
prefix/body execution, saved-register and stack invariants, immutable table
bytes, real callback execution, PVR accesses and the disjoint held-out inputs.
It seals `tools/oracle/audio_fight_live_v1_manifest.json`. Existing encoder,
request, selection input, cleanup and submission/style native corpora pass
against the same frozen executable. The 39 freshly linked native suites,
86 tool checks and complete percentage milestone hash chain pass. The accepted
1,364-binding baseline is reused with these focused checks; adding this
uncredited callable brings the inventory to 1,365. Evidence is sealed in
`tools/oracle/audio_fight_live_v1_regression_scope.json`. No repeated full
inventory run is claimed. Default-runner verification also passes both
historical audio fragments and all 64 fight-caller acceptance cases.

## Promotion boundary

The retail image contains `0x0c099060` at table slot `0x0c10bb84`, index 55.
There are no direct BSR calls to this entry in the retail image. The current
`tools/callable_body.py` gate requires two original BSR callers and supports
only a single saved-register prefix. This entry has a 16-byte prefix saving
two registers and setting up scene inputs. Its full-call evidence therefore
does not satisfy that gate. The rules remain unchanged; this milestone keeps
the callable uncredited, and adds no reused helper bytes. Formal support for
table-dispatched entries and multiple register saves is a separate milestone.
Readable coverage therefore remains **258,502 / 434,656 (59.47%)**.

Song/reset attribution, other callback targets, general overlay interpolation
and standalone ARM/DSP playback remain open.
