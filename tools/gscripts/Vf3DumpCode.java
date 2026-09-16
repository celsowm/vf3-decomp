//Full disassembly dump of executable blocks for offline analysis.
//Writes $VF3_OUT/disasm_<program>.asm with "addr;bytes;mnemonic;ops" lines.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.MemoryBlock;
import java.io.*;

public class Vf3DumpCode extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outdir = System.getenv("VF3_OUT"); if (outdir == null) outdir = ".";
        new File(outdir).mkdirs();
        String prog = currentProgram.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
        File out = new File(outdir, "disasm_" + prog + ".asm");
        int n = 0;
        try (PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(out), 1 << 20))) {
            for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
                if (!b.isExecute() || !b.isInitialized()) continue;
                ghidra.program.model.address.AddressSet as =
                        new ghidra.program.model.address.AddressSet(b.getStart(), b.getEnd());
                InstructionIterator it = currentProgram.getListing().getInstructions(as, true);
                while (it.hasNext()) {
                    Instruction ins = it.next();
                    w.println(String.format("%s\t%s\t%s\t%s",
                            ins.getMinAddress(),
                            bytesToHex(ins.getBytes()),
                            ins.getMnemonicString(),
                            ins.toString()));
                    n++;
                }
            }
        }
        println("Vf3DumpCode: " + prog + " instructions=" + n + " -> " + out);
    }

    private static String bytesToHex(byte[] b) {
        StringBuilder sb = new StringBuilder();
        for (byte x : b) sb.append(String.format("%02x", x & 0xFF));
        return sb.toString();
    }
}
