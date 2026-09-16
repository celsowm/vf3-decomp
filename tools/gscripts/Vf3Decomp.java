//Print decompiled C pseudo-code for functions containing target addresses.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class Vf3Decomp extends GhidraScript {
    @Override
    public void run() throws Exception {
        String list = System.getenv("VF3_CHECK_ADDRS");
        if (list == null) { println("VF3_CHECK_ADDRS not set"); return; }
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.setSimplificationStyle("decompile");
        if (!ifc.openProgram(currentProgram)) {
            println("decompiler open failed");
            return;
        }
        for (String s : list.split(",")) {
            long v = Long.parseLong(s.trim().replace("0x", ""), 16);
            Address a = toAddr(v);
            Function f = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (f == null) { println("== " + s + ": no containing function"); continue; }
            println("== " + s + " in " + f.getName() + " @ " + f.getEntryPoint() + " ==");
            DecompileResults res = ifc.decompileFunction(f, 90, monitor);
            if (res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("decompile failed: " + res.getErrorMessage());
            }
        }
        ifc.dispose();
    }
}
