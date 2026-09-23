//Extend truncated fight function bodies: for each traced entry the flow-based
//createFunction() stopped at the first indirect jsr; rebuild each body as
//[entry, min(next traced entry, next fn head)) and report size changes.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.FileReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

public class Vf3TraceExtend extends GhidraScript {
    @Override
    public void run() throws Exception {
        String csvPath = System.getenv().getOrDefault("VF3_SPLIT_CSV",
                "E:/vf3-decomp/extract/analysis/fight_names.csv");
        String repPath = System.getenv().getOrDefault("VF3_EXTEND_REPORT",
                "E:/vf3-decomp/extract/analysis/extend_report.txt");
        List<long[]> rows = new ArrayList<>(); // {addr}
        List<String> names = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line; boolean header = true;
            while ((line = br.readLine()) != null) {
                if (header) { header = false; continue; }
                if (line.isBlank()) continue;
                String[] t = line.split(",");
                rows.add(new long[]{Long.parseLong(t[0].trim().replace("0x",""),16)});
                names.add(t.length > 1 ? t[1].trim() : "");
            }
        }
        // CSV is hit-sorted; sort by address so next-row bounds are meaningful
        class KV { long a; String n; }
        List<KV> kv = new ArrayList<>();
        for (int i = 0; i < rows.size(); i++) { KV k = new KV(); k.a = rows.get(i)[0]; k.n = names.get(i); kv.add(k); }
        kv.sort((x, y) -> Long.compare(x.a, y.a));
        rows = new ArrayList<>(); names = new ArrayList<>();
        for (KV k : kv) { rows.add(new long[]{k.a}); names.add(k.n); }
        FunctionManager fm = currentProgram.getFunctionManager();
        PrintWriter rep = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(repPath), StandardCharsets.UTF_8));
        int extended = 0, kept = 0, shrinkSkip = 0, fail = 0;
        int tx = currentProgram.startTransaction("traceextend");
        try {
            for (int i = 0; i < rows.size(); i++) {
                long e = rows.get(i)[0];
                String nm = names.get(i);
                Address ea = toAddr(e);
                if (currentProgram.getListing().getInstructionAt(ea) == null) {
                    rep.println("NOTINSTR 0x" + Long.toHexString(e)); continue;
                }
                Function f = fm.getFunctionAt(ea);
                // upper bound: next traced addr, else next fn head, else +0x400
                long nxt = (i + 1 < rows.size()) ? rows.get(i + 1)[0] : 0;
                long headHi = Long.MAX_VALUE;
                {
                    java.util.Iterator<Function> gi = fm.getFunctions(ea, true);
                    if (gi.hasNext()) { Function g = gi.next();
                        if (g.getEntryPoint().getOffset() > e) headHi = g.getEntryPoint().getOffset();
                        else if (gi.hasNext()) headHi = gi.next().getEntryPoint().getOffset();
                    }
                }
                long lim = e + 0x400;
                if (nxt != 0) lim = Math.min(lim, nxt);
                lim = Math.min(lim, headHi);
                // natural end = last rts before lim (+ its delay slot)
                long lastRts = -1;
                ghidra.program.model.listing.Instruction inst =
                        currentProgram.getListing().getInstructionAt(ea);
                while (inst != null && inst.getAddress().getOffset() < lim) {
                    if ("rts".equalsIgnoreCase(inst.getMnemonicString()))
                        lastRts = inst.getAddress().getOffset();
                    inst = inst.getNext();
                }
                long bound = (lastRts >= 0) ? lastRts + 4 : lim;
                if (bound <= e) { rep.println("BOUND-LOW 0x" + Long.toHexString(e)); continue; }
                long oldMax = (f != null) ? f.getBody().getMaxAddress().getOffset() : -1;
                if (f != null && oldMax == bound - 2) {
                    kept++; continue; // exactly natural size already
                }
                if (f == null) {
                    rep.println("NOFN 0x" + Long.toHexString(e));
                    fail++; continue;
                }
                fm.removeFunction(ea);
                AddressSet body = new AddressSet(toAddr(e), toAddr(bound - 2));
                try {
                    Function nf = fm.createFunction(nm, ea, body, SourceType.USER_DEFINED);
                    if (nf == null) { rep.println("FAIL 0x" + Long.toHexString(e)); fail++; }
                    else { extended++; }
                } catch (Exception ex) {
                    rep.println("FAIL 0x" + Long.toHexString(e) + ": " + ex.getMessage());
                    fail++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        rep.println("SUMMARY extended=" + extended + " kept=" + kept
                + " shrinkSkip=" + shrinkSkip + " fail=" + fail);
        rep.close();
        println("Vf3TraceExtend: extended=" + extended + " kept=" + kept
                + " fail=" + fail);
    }
}
