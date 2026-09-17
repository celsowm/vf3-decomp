//Decompile every function with entry inside [VF3_RANGE_LO, VF3_RANGE_HI)
//to file (env VF3_DECOMP_OUT). One function per "===== name @ entry =====" block.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;

public class Vf3DecompRange extends GhidraScript {
    @Override
    public void run() throws Exception {
        long lo = Long.parseLong(
                System.getenv().getOrDefault("VF3_RANGE_LO", "8c010000"), 16);
        long hi = Long.parseLong(
                System.getenv().getOrDefault("VF3_RANGE_HI", "8c020000"), 16);
        String outPath = System.getenv("VF3_DECOMP_OUT");
        if (outPath == null) {
            outPath = "E:/vf3-decomp/extract/analysis/decomp_range.txt";
        }
        PrintWriter w = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(outPath), StandardCharsets.UTF_8));
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.setSimplificationStyle("decompile");
        if (!ifc.openProgram(currentProgram)) {
            println("decompiler open failed");
            return;
        }
        FunctionIterator it = currentProgram.getFunctionManager()
                .getFunctions(true);
        int n = 0, fail = 0;
        while (it.hasNext()) {
            Function f = it.next();
            long e = f.getEntryPoint().getOffset();
            if (e < lo || e >= hi) continue;
            w.println("\n===== " + f.getName() + " @ 0x" +
                    Long.toHexString(e) + " =====");
            DecompileResults res = ifc.decompileFunction(f, 60, monitor);
            if (res.decompileCompleted()) {
                w.println(res.getDecompiledFunction().getC());
                n++;
            } else {
                w.println("// DECOMPILE-FAILED: " + res.getErrorMessage());
                fail++;
            }
        }
        w.flush();
        w.close();
        ifc.dispose();
        println("Vf3DecompRange: decompiled=" + n + " failed=" + fail +
                " -> " + outPath);
    }
}
