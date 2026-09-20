//Apply Vf3ScoreSeeds CSV verdicts to the program (idempotent, non-destructive):
//  JUNK  -> rename junk_<hex>  + plate comment with score/reasons
//  MAYBE -> keep name, add plate comment (audit trail only)
//  REAL  -> untouched (pardon)
//CSV from $VF3_OUT/seed_verdict_<prog>.csv (override with VF3_VERDICT_CSV).
//@category VF3
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class Vf3ApplySeedVerdicts extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outdir = System.getenv("VF3_OUT");
        if (outdir == null) outdir = ".";
        String prog = currentProgram.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
        String csv = System.getenv("VF3_VERDICT_CSV");
        if (csv == null) csv = outdir + File.separator + "seed_verdict_" + prog + ".csv";

        int junk = 0, maybe = 0, skipped = 0;
        try (BufferedReader r = new BufferedReader(new FileReader(csv))) {
            String line = r.readLine(); // header
            while ((line = r.readLine()) != null) {
                String[] f = line.split(",", -1);
                if (f.length < 3) continue;
                String addrS = f[0], score = f[1], tier = f[2];
                String reasons = f.length > 3 ? f[3] : "";
                Address a = toAddr(addrS);
                Function fn = currentProgram.getFunctionManager().getFunctionAt(a);
                if (fn == null) { skipped++; continue; }
                if (tier.equals("JUNK")) {
                    String nm = "junk_" + a;
                    if (!fn.getName().equals(nm)) {
                        fn.setName(nm, SourceType.ANALYSIS);
                    }
                    currentProgram.getListing().setComment(
                            a, CodeUnit.PLATE_COMMENT,
                            "seed verdict JUNK score=" + score + " reasons=" + reasons);
                    junk++;
                } else if (tier.equals("MAYBE")) {
                    currentProgram.getListing().setComment(
                            a, CodeUnit.PLATE_COMMENT,
                            "seed verdict MAYBE score=" + score + " reasons=" + reasons);
                    maybe++;
                }
            }
        }
        println("Vf3ApplySeedVerdicts: junk=" + junk + " maybe=" + maybe + " skipped=" + skipped);
    }
}
