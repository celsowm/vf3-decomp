//Score functions created by Vf3SeedPointers (listed in $VF3_OUT/seed_<prog>.csv,
//override with VF3_SEED_CSV) and write a verdict CSV to $VF3_OUT/seed_verdict_<prog>.csv:
//  entry,score,tier,reasons,n_instr,body_bytes,max_run,ascii_pct,exit_kind
//
//Tiers: REAL (>=40), JUNK (<20), MAYBE otherwise. Pure read of listing — no edits.
//@category VF3
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.RefType;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Vf3ScoreSeeds extends GhidraScript {

    private static boolean isExitMnemonic(String m) {
        return m.equals("rts") || m.equals("jmp") || m.equals("bra")
                || m.equals("rte") || m.equals("braf");
    }

    private static class Feat {
        int bodyBytes, nInstr, maxRun, ascii, pushes, callsKnown;
        String exitKind = "falls-off";
    }

    private Feat features(Function f) throws Exception {
        Feat ft = new Feat();
        ft.bodyBytes = (int) f.getBody().getNumAddresses();
        int prevRun = 1;
        int prevWord = -1;
        Instruction entryIns = null, last1 = null, last2 = null;
        for (Instruction ins : currentProgram.getListing().getInstructions(f.getBody(), true)) {
            ft.nInstr++;
            if (entryIns == null) entryIns = ins;
            byte[] b = ins.getBytes();
            int w = ((b[0] & 0xFF) | ((b[1] & 0xFF) << 8));
            // identical-word run tracking (data tables decoded as code)
            if (w == prevWord) { prevRun++; } else { prevRun = 1; prevWord = w; }
            if (prevRun > ft.maxRun) ft.maxRun = prevRun;
            // ascii-ish word?
            int lo = w & 0xFF, hi = (w >> 8) & 0xFF;
            if (lo >= 0x20 && lo <= 0x7E && hi >= 0x20 && hi <= 0x7E) ft.ascii++;
            String mn = ins.getMnemonicString();
            // prologue push at entry: mov.l Rn,@-r15 / sts.l PR,@-r15 / fmov @-r15
            if (ft.nInstr <= 4) {
                String s = ins.toString();
                if (s.contains("@-r15")) ft.pushes++;
                if (s.contains("add #0x") && s.contains("r15")) ft.pushes++; // frame reserve
            }
            // call to a known function (incl. via literal-deref'd operand 0)
            if (ins.getFlowType().isCall()) {
                Address[] flows = ins.getFlows();
                for (Address t : flows) {
                    Function g = currentProgram.getFunctionManager().getFunctionAt(t);
                    if (g != null && g != f) { ft.callsKnown++; break; }
                }
            }
            last2 = last1;
            last1 = ins;
        }
        // exit kind from last (and second-to-last: delay slot) instructions
        String e1 = last1 != null ? last1.getMnemonicString() : null;
        String e2 = last2 != null ? last2.getMnemonicString() : null;
        if (e1 != null && isExitMnemonic(e1)) ft.exitKind = e1;
        else if (e2 != null && isExitMnemonic(e2)) ft.exitKind = e2 + "+slot";
        if (entryIns != null && isExitMnemonic(entryIns.getMnemonicString()))
            ft.exitKind = entryIns.getMnemonicString(); // rts-thunk etc.
        // falls-off the body, but the next address is already an instruction —
        // i.e. a real code fragment abutting other analyzed code, not dead data
        if ("falls-off".equals(ft.exitKind) && last1 != null
                && !last1.getFlowType().isTerminal() && !last1.getFlowType().isJump()) {
            Instruction nxt = currentProgram.getListing()
                    .getInstructionAfter(f.getBody().getMaxAddress());
            if (nxt != null) ft.exitKind = "continues";
        }
        return ft;
    }

    @Override
    public void run() throws Exception {
        String outdir = System.getenv("VF3_OUT");
        if (outdir == null) outdir = ".";
        String prog = currentProgram.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
        String seedCsv = System.getenv("VF3_SEED_CSV");
        if (seedCsv == null) seedCsv = outdir + File.separator + "seed_" + prog + ".csv";

        ArrayList<String> entries = new ArrayList<>();
        try (BufferedReader r = new BufferedReader(new FileReader(seedCsv))) {
            String line = r.readLine(); // header
            while ((line = r.readLine()) != null) {
                line = line.trim();
                if (!line.isEmpty()) entries.add(line);
            }
        }

        int real = 0, maybe = 0, junk = 0;
        File out = new File(outdir, "seed_verdict_" + prog + ".csv");
        try (PrintWriter w = new PrintWriter(out)) {
            w.println("entry,score,tier,reasons,n_instr,body_bytes,max_run,ascii_pct,exit_kind");
            for (String s : entries) {
                Address a = toAddr(s);
                Function f = currentProgram.getFunctionManager().getFunctionAt(a);
                if (f == null) {
                    w.println(s + ",0,JUNK,no-function,,,,,");
                    junk++;
                    continue;
                }
                Feat ft = features(f);
                int asciiPct = ft.nInstr == 0 ? 0 : (ft.ascii * 100 / ft.nInstr);
                boolean cleanExit = !ft.exitKind.equals("falls-off") && !ft.exitKind.equals("continues");
                int score = 0;
                StringBuilder why = new StringBuilder();
                if (cleanExit) { score += 40; why.append("+exit:").append(ft.exitKind).append(' '); }
                else if (ft.exitKind.equals("continues")) { score += 20; why.append("+continues "); }
                if (ft.pushes > 0) { score += 15; why.append("+pushes "); }
                if (ft.nInstr >= 10) { score += 10; why.append("+size "); }
                if (ft.callsKnown > 0) { score += 10; why.append("+calls "); }
                if (ft.maxRun >= 6) { score -= 50; why.append("-run:").append(ft.maxRun).append(' '); }
                if (asciiPct > 60) { score -= 60; why.append("-ascii:").append(asciiPct).append(' '); }
                if (ft.nInstr <= 2 && !cleanExit) { score -= 25; why.append("-tiny-noexit "); }
                String tier = score >= 40 ? "REAL" : (score < 20 ? "JUNK" : "MAYBE");
                if (tier.equals("REAL")) real++;
                else if (tier.equals("JUNK")) junk++;
                else maybe++;
                w.printf("%s,%d,%s,%s,%d,%d,%d,%d,%s%n",
                        s, score, tier, why.toString().trim().replace(',', ';'),
                        ft.nInstr, ft.bodyBytes, ft.maxRun, asciiPct, ft.exitKind);
            }
        }
        println("Vf3ScoreSeeds: REAL=" + real + " MAYBE=" + maybe + " JUNK=" + junk
                + " of " + entries.size() + " -> " + out.getAbsolutePath());
    }
}
