// Dumps all references FROM code instructions (xrefs) to CSV:
//   from_addr, to_addr, type, opindex
// plus a compact table of references INTO each address range
// (which functions read which data tables - Phase B glue).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.address.AddressSetView;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Vf3Xrefs2 extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outPath = System.getenv("VF3_XREFS_CSV");
        if (outPath == null) {
            outPath = "E:/vf3-decomp/extract/analysis/xrefs_" +
                    currentProgram.getName() + ".csv";
        }
        PrintWriter w = new PrintWriter(new FileWriter(outPath));
        w.println("from,to,type,opindex");
        AddressSetView body =
                currentProgram.getMemory().getExecuteSet();
        Instruction inst = currentProgram.getListing()
                .getInstructionAt(body.getMinAddress());
        long n = 0;
        var lit = currentProgram.getListing();
        if (inst == null) {
            inst = lit.getInstructions(body, true).iterator().next();
        }
        var it = lit.getInstructions(body, true);
        while (it.hasNext()) {
            Instruction in = it.next();
            Reference[] refs = in.getReferencesFrom();
            for (Reference r : refs) {
                w.println("0x" + in.getAddress().toString() + ",0x" +
                        r.getToAddress().toString() + "," +
                        r.getReferenceType().getName() + "," + r.getOperandIndex());
                n++;
            }
        }
        w.close();
        println("Vf3Xrefs2: wrote " + n + " refs -> " + outPath);
    }
}
