//Diagnostic probe for prologue-based function creation
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.mem.MemoryBlock;

public class Vf3Probe extends GhidraScript {

    private static boolean isPushWord(int w) {
        if (w == 0x4F22) return true;
        if ((w & 0xF0FF) == 0x2F06) { int m = (w >> 8) & 0xF; return m >= 8 && m <= 14; }
        if ((w & 0xF0FF) == 0xF00B) return true;
        return false;
    }

    @Override
    public void run() throws Exception {
        MemoryBlock block = currentProgram.getMemory().getBlocks()[0];
        byte[] bytes = new byte[(int) block.getSize()];
        block.getBytes(block.getStart(), bytes);
        long base = block.getStart().getOffset();
        int shown = 0;
        int totalRuns = 0, nullCU = 0;
        for (int i = 0; i < bytes.length - 8 && shown < 1_000_000; i += 2) {
            int w = (bytes[i] & 0xFF) | ((bytes[i + 1] & 0xFF) << 8);
            if (!isPushWord(w)) continue;
            // start of run
            if (i >= 2) {
                int pw = (bytes[i - 2] & 0xFF) | ((bytes[i - 1] & 0xFF) << 8);
                if (isPushWord(pw)) continue; // mid-run
            }
            totalRuns++;
            Address a = toAddr(base + i);
            CodeUnit cu = currentProgram.getListing().getCodeUnitAt(a);
            boolean isNull = (cu == null);
            if (!isNull) nullCU++; // count non-null too
            if (shown < 30) {
                boolean instr = cu != null && cu instanceof ghidra.program.model.listing.Instruction;
                println(String.format("cand 0x%X w=%04X cu=%s instr=%s minFn=%s",
                        base + i, w,
                        (cu == null ? "null" : cu.getClass().getSimpleName() + ":" + cu.toString()),
                        instr,
                        (currentProgram.getFunctionManager().getFunctionContaining(a) != null)));
                shown++;
            }
        }
        println("totalRuns=" + totalRuns + " codeUnit!=null=" + nullCU);
    }
}
