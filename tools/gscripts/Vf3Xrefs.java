//Print xrefs to each address in VF3_CHECK_ADDRS (comma-separated hex),
//with containing function names.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.Reference;

public class Vf3Xrefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String list = System.getenv("VF3_CHECK_ADDRS");
        if (list == null) { println("VF3_CHECK_ADDRS not set"); return; }
        for (String s : list.split(",")) {
            long v = Long.parseLong(s.trim().replace("0x", ""), 16);
            Address a = toAddr(v);
            println("== " + s + " ==");
            int c = 0;
            for (Reference r : currentProgram.getReferenceManager().getReferencesTo(a)) {
                var f = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
                println("   " + r.getFromAddress() + " in " + (f != null ? f.getName() : "(none)"));
                c++;
            }
            if (c == 0) println("   (no refs)");
        }
    }
}
