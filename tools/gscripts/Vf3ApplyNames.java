//Applies fingerprint matches (CSV) to the current program.
//CSV columns: addr(hex 0x...),name,span. span>0 => full-body match (direct
//name), span==0 => normalized match ("an_"), span<0 => prefix only ("cand_").
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.SourceType;
import java.io.BufferedReader;
import java.io.FileReader;

public class Vf3ApplyNames extends GhidraScript {
    @Override
    public void run() throws Exception {
        String csvPath = System.getenv("VF3_NAMES_CSV");
        if (csvPath == null) {
            System.out.println("VF3_NAMES_CSV not set");
            return;
        }
        int applied = 0, skippedInFn = 0, bad = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean header = true;
            while ((line = br.readLine()) != null) {
                if (header) { header = false; continue; }
                String[] t = line.split(",");
                if (t.length < 3) continue;
                long off;
                try { off = Long.parseLong(t[0].trim().replace("0x", ""), 16); }
                catch (Exception e) { bad++; continue; }
                String name = t[1].trim();
                boolean normOnly = name.contains("[norm]");
                boolean prefixOnly = name.contains("[prefix]");
                name = name.replace(" [norm]", "").replace(" [prefix]", "");
                long span = Long.parseLong(t[2].trim());
                if (normOnly) name = "an" + name;
                else if (prefixOnly || span < 0) name = "cand" + name;
                if (normOnly || prefixOnly || span < 0) {
                    // candidates keep lowercase tag prefix
                }
                Address a = toAddr(off);
                var existing = currentProgram.getFunctionManager().getFunctionAt(a);
                var sym = getSymbolAt(a);
                if (existing != null) {
                    existing.setName(name, SourceType.ANALYSIS);
                    applied++;
                } else if (sym == null || sym.getName(true).length() == 0) {
                    createLabel(a, name, false);
                    applied++;
                } else {
                    skippedInFn++;
                }
            }
        }
        println("Vf3ApplyNames: applied=" + applied + " skipped=" + skippedInFn + " bad=" + bad);
    }
}
