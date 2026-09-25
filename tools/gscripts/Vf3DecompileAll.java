// Decompile EVERY function in the program into VF3_OUT/decomp_all/f_<addr>.c
// (M31 batch inventory). Also writes decomp_all/_index.csv with
// entry,name,size,c_chars,ok for the stats tool.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;

public class Vf3DecompileAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        String out = System.getenv("VF3_OUT");
        if (out == null) out = ".";
        java.io.File dir = new java.io.File(out);
        dir.mkdirs();

        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        java.io.PrintWriter idx = new java.io.PrintWriter(
                new java.io.File(dir, "_index.csv"));
        idx.println("entry,name,size,c_chars,ok");

        int n = 0, ok = 0;
        for (Function f : currentProgram.getFunctionManager()
                .getFunctions(true)) {
            n++;
            String c = null;
            String err = "";
            try {
                DecompileResults res = ifc.decompileFunction(f, 120, monitor);
                if (res.decompileCompleted()
                        && res.getDecompiledFunction() != null)
                    c = res.getDecompiledFunction().getC();
                else
                    err = res.getErrorMessage();
            } catch (Throwable t) {
                err = t.toString();
            }
            long size = f.getBody().getNumAddresses();
            if (c != null) {
                ok++;
                try (java.io.PrintWriter pw = new java.io.PrintWriter(
                        new java.io.File(dir, "f_" + f.getEntryPoint()
                                + ".c"))) {
                    pw.println(c);
                }
            } else {
                println("FAIL " + f.getEntryPoint() + " " + f.getName()
                        + " err=" + err);
            }
            idx.println(f.getEntryPoint() + "," + f.getName() + "," + size
                    + "," + (c == null ? 0 : c.length()) + ","
                    + (c == null ? "0" : "1"));
            if (n % 200 == 0) println("... " + n + " functions, " + ok + " ok");
            if (monitor.isCancelled()) break;
        }
        idx.close();
        ifc.dispose();
        println("Vf3DecompileAll done: " + n + " functions, " + ok + " decompiled");
    }
}
