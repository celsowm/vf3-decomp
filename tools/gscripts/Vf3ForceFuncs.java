//Force function creation at env-supplied addresses (VF3_FORCE_FUNCS=hex,hex)
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.SourceType;

public class Vf3ForceFuncs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String list = System.getenv("VF3_FORCE_FUNCS");
        if (list == null) { println("VF3_FORCE_FUNCS not set"); return; }
        String names = System.getenv("VF3_FORCE_NAMES"); // optional parallel names
        String[] nameArr = names != null ? names.split(",") : null;
        int i = 0;
        for (String s : list.split(",")) {
            long v = Long.parseLong(s.trim().replace("0x", ""), 16);
            Address a = toAddr(v);
            String nm = (nameArr != null && i < nameArr.length) ? nameArr[i].trim() : "f_" + a;
            try {
                if (currentProgram.getListing().getCodeUnitAt(a) == null ||
                    !(currentProgram.getListing().getCodeUnitAt(a) instanceof ghidra.program.model.listing.Instruction)) {
                    clearListing(a, a);
                }
                disassemble(a);
                var f = createFunction(a, nm);
                if (f != null) {
                    try { f.setName(nm, SourceType.USER_DEFINED); } catch (Exception ignored) {}
                    println("created " + nm + " @ " + a);
                } else println("non-null? existing @ " + a);
            } catch (Exception e) {
                println("fail " + s + ": " + e.getMessage());
            }
            i++;
        }
    }
}
