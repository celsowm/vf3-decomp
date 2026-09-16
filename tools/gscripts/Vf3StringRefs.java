//Find all references to embedded "*.BIN" filename strings and report
//stringAddr, string, refAddress, containing function -> CSV at $VF3_OUT/stringrefs_<program>.csv
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Vf3StringRefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        Pattern pat = Pattern.compile("[A-Z0-9_]{2,18}\\.BIN");
        MemoryBlock ram = null;
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (b.isExecute() && b.isInitialized()) { ram = b; break; }
        }
        if (ram == null) { println("no exec block"); return; }
        byte[] bytes = new byte[(int) ram.getSize()];
        ram.getBytes(ram.getStart(), bytes);
        long base = ram.getStart().getOffset();

        StringBuilder ascii = new StringBuilder();
        Map<Long, String> found = new TreeMap<>();
        for (int i = 0; i < bytes.length; ) {
            int j = i;
            StringBuilder sb = new StringBuilder();
            while (j < bytes.length && bytes[j] >= 0x20 && bytes[j] < 0x7F) {
                sb.append((char) bytes[j]); j++;
            }
            if (j - i >= 4) {
                String s = sb.toString();
                Matcher m = pat.matcher(s);
                int last = -1;
                while (m.find()) last = m.start();
                if (last >= 0) {
                    String name = s.substring(last);
                    // guard: must end cleanly (with NUL)
                    int end = i + last + name.length();
                    if (end < bytes.length && bytes[end] == 0) {
                        found.put(base + i + last, name);
                    }
                }
            }
            i = Math.max(j + 1, i + 1);
        }

        String outdir = System.getenv("VF3_OUT"); if (outdir == null) outdir = ".";
        String prog = currentProgram.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
        File out = new File(outdir, "stringrefs_" + prog + ".csv");
        int withRef = 0;
        try (PrintWriter w = new PrintWriter(out)) {
            w.println("str_addr,string,ref_addr,function");
            for (Map.Entry<Long, String> e : found.entrySet()) {
                Address sa = toAddr(e.getKey());
                String fn = "";
                int refn = 0;
                Address firstRef = null;
                for (Reference r : currentProgram.getReferenceManager().getReferencesTo(sa)) {
                    Address fa = r.getFromAddress();
                    Function f = currentProgram.getFunctionManager().getFunctionContaining(fa);
                    if (refn == 0) { firstRef = fa; fn = f != null ? f.getName() : ""; }
                    refn++;
                }
                if (refn > 0) withRef++;
                w.println(String.format("0x%X,%s,%s,%s", e.getKey(), e.getValue(),
                        firstRef == null ? "" : "0x" + firstRef, fn));
            }
        }
        println("Vf3StringRefs: strings=" + found.size() + " withRefs=" + withRef + " -> " + out);
    }
}
