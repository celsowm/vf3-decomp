//Trace-guided function split (M7 P1). CSV of traced entry addrs; any traced
//entry found strictly inside an existing function forces that function to be
//deleted and re-created as contiguous segments cut at the traced entries.
//Report: extract/analysis/split_report.txt (env VF3_SPLIT_* overrides).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.SourceType;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.TreeMap;

public class Vf3TraceSplit extends GhidraScript {
    static class Entry {
        long off; Address a; String name;
    }

    @Override
    public void run() throws Exception {
        String csvPath = System.getenv().getOrDefault("VF3_SPLIT_CSV",
                "E:/vf3-decomp/extract/analysis/fight_names.csv");
        String repPath = System.getenv().getOrDefault("VF3_SPLIT_REPORT",
                "E:/vf3-decomp/extract/analysis/split_report.txt");
        List<Entry> entries = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line; boolean header = true;
            while ((line = br.readLine()) != null) {
                if (header) { header = false; continue; }
                if (line.isBlank()) continue;
                String[] t = line.split(",");
                Entry e = new Entry();
                e.off = Long.parseLong(t[0].trim().replace("0x", ""), 16);
                e.name = t.length > 1 ? t[1].trim() : "ts_" + Long.toHexString(e.off);
                e.a = toAddr(e.off);
                entries.add(e);
            }
        }
        FunctionManager fm = currentProgram.getFunctionManager();
        PrintWriter rep = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(repPath), StandardCharsets.UTF_8));

        int already = 0, notInstr = 0, newFn = 0, splitFns = 0, segments = 0, fails = 0;
        // group mid-function entries by containing function entrypoint
        TreeMap<Long, List<Entry>> byOwner = new TreeMap<>();
        LinkedHashMap<Long, String> ownerName = new LinkedHashMap<>();
        LinkedHashMap<Long, Address> ownerMax = new LinkedHashMap<>();

        for (Entry e : entries) {
            if (currentProgram.getListing().getInstructionAt(e.a) == null) {
                disassemble(e.a);
            }
            if (currentProgram.getListing().getInstructionAt(e.a) == null) {
                rep.println("NOTINSTR 0x" + Long.toHexString(e.off));
                notInstr++;
                continue;
            }
            Function f = fm.getFunctionContaining(e.a);
            if (f == null) { // will handle later individually
                byOwner.computeIfAbsent(-1L, k -> new ArrayList<>()).add(e);
                continue;
            }
            long head = f.getEntryPoint().getOffset();
            if (head == e.off) { already++; continue; }
            if (!ownerName.containsKey(head)) {
                ownerName.put(head, f.getName(true));
                ownerMax.put(head, f.getBody().getMaxAddress());
            }
            byOwner.computeIfAbsent(head, k -> new ArrayList<>()).add(e);
        }

        int tx = currentProgram.startTransaction("tracesplit");
        try {
            // Phase A: split multi-entry functions into traced segments
            for (long head : ownerName.keySet()) {
                List<Entry> inner = byOwner.get(head);
                if (inner == null) inner = new ArrayList<>();
                inner.sort((x, y) -> Long.compare(x.off, y.off));
                Function headFn = fm.getFunctionAt(toAddr(head));
                if (headFn == null) { rep.println("SKIP owner gone 0x" + Long.toHexString(head)); continue; }
                String headName = headFn.getName();
                Address max = headFn.getBody().getMaxAddress();
                fm.removeFunction(headFn.getEntryPoint()); // listing survives
                splitFns++;
                // segment boundaries: [head, e1, e2, ..., end]
                List<Long> bounds = new ArrayList<>();
                bounds.add(head);
                for (Entry e : inner) bounds.add(e.off);
                bounds.add(max.getOffset() + 2); // exclusive cap (SH4 2-byte)
                for (int i = 0; i + 1 < bounds.size(); i++) {
                    long lo = bounds.get(i), hi = bounds.get(i + 1);
                    AddressSet body = new AddressSet(toAddr(lo), toAddr(hi - 2));
                    String nm = (i == 0) ? headName : inner.get(i - 1).name;
                    try {
                        Function nf = fm.createFunction(nm, toAddr(lo), body,
                                SourceType.USER_DEFINED);
                        if (nf == null) { rep.println("FAIL seg 0x" + Long.toHexString(lo)); fails++; }
                        else segments++;
                    } catch (Exception ex) {
                        rep.println("FAIL seg 0x" + Long.toHexString(lo) + ": " + ex.getMessage());
                        fails++;
                    }
                }
                rep.println("SPLIT 0x" + Long.toHexString(head) + " -> "
                        + (bounds.size() - 1) + " segments");
            }
            // Phase B: lone traced entries with no containing function
            List<Entry> lonely = byOwner.get(-1L);
            if (lonely != null) {
                for (Entry e : lonely) {
                    Function f = fm.getFunctionContaining(e.a);
                    if (f != null) continue; // picked up by a segment above
                    try {
                        Function nf = createFunction(e.a, e.name);
                        if (nf != null) { if (!nf.getName().equals(e.name)) nf.setName(e.name, SourceType.USER_DEFINED); newFn++; }
                        else { rep.println("FAIL new 0x" + Long.toHexString(e.off)); fails++; }
                    } catch (Exception ex) {
                        rep.println("FAIL new 0x" + Long.toHexString(e.off) + ": " + ex.getMessage());
                        fails++;
                    }
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        rep.println("SUMMARY already=" + already + " splitFns=" + splitFns
                + " segments=" + segments + " newFn=" + newFn
                + " notInstr=" + notInstr + " fail=" + fails);
        rep.close();
        println("Vf3TraceSplit: already=" + already + " splitFns=" + splitFns
                + " segments=" + segments + " newFn=" + newFn
                + " notInstr=" + notInstr + " fail=" + fails);
    }
}
