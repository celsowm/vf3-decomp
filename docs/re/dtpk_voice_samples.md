# DTPK voice sample spans

`tools/dtpk_samples.py` inspects candidate spans in the final section of a
DTPK `VO_*` package and optionally decodes a selected span to WAV. It is an
offline diagnostic for extracted files; WAV output is not proof that a span is
an independently playable sample or a known fight sound.

The layout is a candidate, observed in `VO_AKI.BIN` and `VO_JAC.BIN`:

- The section begins with 16-byte descriptors.
- Descriptor word 0 is a byte length. The low 24 bits of word 1 identify that
  sample's package-file end offset.
- The first candidate span begins after the descriptor table, sometimes with a
  short prefix gap. Each following span begins at the preceding end offset.
- The two trailing descriptor words are retained as raw metadata. Their field
  meanings and the relationship between sample indices and fight events are
  unresolved.

Inspect a package or extract selected samples:

```powershell
python tools/dtpk_samples.py extract/gamedata/VO_AKI.BIN
python tools/dtpk_samples.py extract/gamedata/VO_AKI.BIN --sample 1 --sample 2 --wav-dir extract/analysis/vo_aki_samples
python tools/dtpk_samples.py extract/gamedata/VO_JAC.BIN --json
```

For `VO_AKI.BIN`, the scan finds 20 descriptors with no prefix gap. For
`VO_JAC.BIN`, it finds 14 descriptors and a six-byte prefix gap. In both,
sample end offsets are contiguous after the first sample. The trailing section
bytes after the last listed sample are not classified. The tool rejects a
package whose final section does not satisfy these bounds; for example, the
`ST_JAC.BIN` audio section uses a different layout.

The tool rejects other package families such as `ST_*`; their audio sections
use a different layout. Even for the `VO_*` examples, the spans do not identify
which data belongs to a punch, hit, guard, announcer cue, or other game event.
The native runtime should not select samples from these candidates until the
sound-ID relationship is recovered.
