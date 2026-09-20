//Purge auto-seeded micro-functions (size<=6B, f_/FUN_ name, no call refs, no
//named refs) which are pointer-scan false positives fragmenting real bodies.
//After purge, clears the bytes (no re-analysis here; caller may follow with
//Ghidra auto-analyze pass).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class Vf3PurgeTinyJunk extends GhidraScript {
    @Override
    public void run() throws Exception {
        var fm = currentProgram.getFunctionManager();
        var rm = currentProgram.getReferenceManager();
        var listing = currentProgram.getListing();
        int purged = 0;
        int kept = 0;
        var toRemove = new java.util.ArrayList<Function>();
        for (FunctionIterator it = fm.getFunctions(true); it.hasNext(); ) {
            Function f = it.next();
            long size = f.getBody().getNumAddresses();
            String nm = f.getName();
            boolean auto = nm.startsWith("f_8c") || nm.startsWith("FUN_");
            boolean junk = nm.startsWith("junk_");
            if (size <= 6 && (auto || junk)) {
                ReferenceIterator ri = rm.getReferencesTo(f.getEntryPoint());
                boolean hasCall = false, hasAny = false;
                while (ri.hasNext()) {
                    Reference r = ri.next();
                    if (r.getReferenceType().isCall()) {
                        hasCall = true;
                        break;
                    }
                    // data refs only protect f_/FUN_ (they may be seed junk)
                    if (!junk) hasAny = true;
                }
                // fall-through safety: does the instruction just before end here?
                var prevIns = listing.getInstructionBefore(f.getEntryPoint());
                boolean fallthru = prevIns != null && prevIns.getFlowType().isFallthrough();
                if (!hasCall && !hasAny && !fallthru) {
                    toRemove.add(f);
                } else {
                    kept++;
                }
            }
        }
        for (Function f : toRemove) {
            long s = f.getBody().getNumAddresses();
            currentProgram.getListing().clearCodeUnits(f.getEntryPoint(),
                    f.getEntryPoint().add(f.getBody().getMaxAddress().getOffset()
                            - f.getEntryPoint().getOffset()), false);
            purged++;
        }
        println("Vf3PurgeTinyJunk: purged=" + purged + " kept(referenced)=" + kept);
    }
}
