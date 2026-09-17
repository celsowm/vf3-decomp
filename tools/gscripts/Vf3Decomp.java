//Decompile functions containing comma-separated addresses (env VF3_CHECK_ADDRS)
//into a UTF-8 text file (env VF3_DECOMP_OUT, default extract/analysis/decomp.txt).
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;

public class Vf3Decomp extends GhidraScript {
    @Override
    public void run() throws Exception {
        String list = System.getenv("VF3_CHECK_ADDRS");
        if (list == null) { println("VF3_CHECK_ADDRS not set"); return; }
        String outPath = System.getenv("VF3_DECOMP_OUT");
        if (outPath == null) {
            outPath = "E:/vf3-decomp/extract/analysis/decomp.txt";
        }
        PrintWriter w = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(outPath, true), StandardCharsets.UTF_8));
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
            Function f = currentProgram.getFunctionManager()
                    .getFunctionContaining(a);
            if (f == null) { w.println("== " + s + ": no containing function");
                continue; }
            w.println("\n===== " + f.getName() + " @ " + f.getEntryPoint()
                    + " (query " + s + ") =====");
            DecompileResults res = ifc.decompileFunction(f, 90, monitor);
            if (res.decompileCompleted()) {
                w.println(res.getDecompiledFunction().getC());
            } else {
                w.println("DECOMPILE-FAILED: " + res.getErrorMessage());
            }
        }
        w.flush();
        w.close();
        ifc.dispose();
        println("Vf3Decomp: wrote " + outPath);
    }
}
