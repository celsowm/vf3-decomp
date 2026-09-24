//Decompile the function containing each address in VF3_CHECK_ADDRS.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class Vf3Decompile extends GhidraScript {
    @Override
    public void run() throws Exception {
        String list = System.getenv("VF3_CHECK_ADDRS");
        if (list == null) { println("VF3_CHECK_ADDRS not set"); return; }
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        for (String s : list.split(",")) {
            long v = Long.parseLong(s.trim().replace("0x", ""), 16);
            Address a = toAddr(v);
            println("== " + s.trim() + " ==");
            Function f = currentProgram.getFunctionManager()
                    .getFunctionContaining(a);
            if (f == null) { println("   NO FUNCTION at " + a); continue; }
            println("   fn: " + f.getName() + " body " + f.getBody().getNumAddresses());
            DecompileResults res = ifc.decompileFunction(f, 60, monitor);
            println("   completed=" + res.decompileCompleted()
                    + " err=" + res.getErrorMessage());
            if (res.getDecompiledFunction() != null) {
                String c = res.getDecompiledFunction().getC();
                String out = System.getenv("VF3_OUT");
                if (out == null) out = ".";
                String path = out + java.io.File.separator + "decomp_"
                        + f.getEntryPoint() + ".c";
                try (java.io.PrintWriter pw = new java.io.PrintWriter(path)) {
                    pw.println(c);
                }
                println("   wrote " + path + " (" + c.length() + " chars)");
            } else {
                println("   no decompiled function object");
            }
        }
        ifc.dispose();
    }
}
