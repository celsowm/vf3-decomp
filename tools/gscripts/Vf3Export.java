//Export per-function disassembly skeletons for cross-build diffing.
//Writes to $VF3_OUT/export_<program>.txt with lines:
//  FN addr size ninstr hash
//  OP <mnemonic>   (one per instruction, mnemonics only - operands stripped)
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.zip.CRC32;

public class Vf3Export extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outdir = System.getenv("VF3_OUT");
        if (outdir == null) outdir = ".";
        new File(outdir).mkdirs();
        String prog = currentProgram.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
        File out = new File(outdir, "export_" + prog + ".txt");
        int n = 0;
        try (BufferedWriter w = new BufferedWriter(new FileWriter(out))) {
            FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
            while (fit.hasNext()) {
                Function f = fit.next();
                StringBuilder sb = new StringBuilder();
                CRC32 crc = new CRC32();
                Instruction prev = null;
                for (Instruction ins : currentProgram.getListing().getInstructions(f.getBody(), true)) {
                    String mn = ins.getMnemonicString();
                    sb.append(mn).append('\n');
                    crc.update(mn.getBytes("ASCII"));
                    prev = ins;
                }
                String ops = sb.toString();
                w.write(String.format("FN %s %d %d %08x%n",
                        f.getEntryPoint(), f.getBody().getNumAddresses(),
                        ops.split("\n").length, crc.getValue() & 0xFFFFFFFFL));
                w.write(ops);
            }
            n = currentProgram.getFunctionManager().getFunctionCount();
        }
        println("Vf3Export: " + prog + " functions=" + n + " -> " + out.getAbsolutePath());
    }
}
