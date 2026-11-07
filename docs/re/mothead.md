# MOTHEAD.BIN structural inspection

`MOTHEAD.BIN` is 168,391 bytes. `tools/mothead_inspect.py` is a read-only
diagnostic for its candidate leading table of little-endian u32 offsets and
the bounded byte spans those offsets select. It does not assign action,
character, or motion meanings to rows or record fields.

For the extracted file, the current structural scan finds a 2,959-row prefix
(`0x2e3c` bytes), no zero rows, and 2,644 unique in-file offsets. The first
nonzero word outside the file occurs at row 2,959, which is used as the
candidate table boundary. This is an observed heuristic, not a proven format
marker. Duplicate table rows can point to the same offset; each displayed
record span ends at the next unique offset, or at EOF for the last span.

Use the default short listing to inspect the table and first 24 records, or
request a specific record by its file offset:

```powershell
python tools/mothead_inspect.py extract/gamedata/MOTHEAD.BIN
python tools/mothead_inspect.py extract/gamedata/MOTHEAD.BIN --record 0x5b38
```

`--limit 0 --json` emits table statistics without record bodies. `--all` emits
every unique record, which can produce a large report. Search for candidate
little-endian u16 values with repeatable `--find-u16`; each result includes its
record offset, relative offset, table rows, and surrounding bytes:

```powershell
python tools/mothead_inspect.py extract/gamedata/MOTHEAD.BIN --limit 0 --find-u16 0x41a --find-u16 0x956
```

These matches are byte-pattern leads only. They do not prove that the values
are motion IDs or establish an action-to-motion table. The four motion IDs
profiled in `docs/re/mt_fields.md` still lack semantic labels.

Searching candidate spans for aligned u16 values `0x41A` and `0x956` currently
finds six `0x41A` byte-pattern matches and no `0x956` matches. The `0x41A`
matches occur inside small record payloads with other packed values nearby;
they do not connect a MOTHEAD row to a captured actor or an MT pack. Keep the
action-to-motion mapping open.
