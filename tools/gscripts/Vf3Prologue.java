//Ghidra headless postScript: SHC prologue sweep. Clears undefined '??' data
//at prologue starts (run begins), disassembles, and creates functions.
//Works in both -import (with default analysis) and -process modes.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.MemoryBlock;

public class Vf3Prologue extends GhidraScript {

    private static boolean isPush(int w) {
        if (w == 0x4F22) { // sts.l pr,@-r15
            return true;
        }
        if ((w & 0xF0FF) == 0x2F06) { // mov.l r8..r14,@-r15
            int m = (w >> 8) & 0xF;
            return m >= 8 && m <= 14;
        }
        if ((w & 0xF0FF) == 0xF00B) { // fmov.s frN,@-r15 (0xFFxB)
            return true;
        }
        return false;
    }

    @Override
    public void run() throws Exception {
        long runs = 0, cleared = 0, created = 0, already = 0;
        long zeroRun = 0, zeroCleared = 0;
        for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
            if (!block.isExecute()) {
                continue;
            }
            byte[] bytes = new byte[(int) block.getSize()];
            block.getBytes(block.getStart(), bytes);
            long base = block.getStart().getOffset();
            int n = bytes.length;
            int i = 0;
            while (i < n - 8) {
                int w = (bytes[i] & 0xFF) | ((bytes[i + 1] & 0xFF) << 8);
                if (!isPush(w)) { i += 2; continue; }
                if (i >= 2) {
                    int pw = (bytes[i - 2] & 0xFF) | ((bytes[i - 1] & 0xFF) << 8);
                    if (isPush(pw)) { i += 2; continue; } // mid-run
                }
                runs++;
                Address a = toAddr(base + i);
                CodeUnit cu = currentProgram.getListing().getCodeUnitAt(a);
                if (cu instanceof Instruction) {
                    if (currentProgram.getFunctionManager().getFunctionAt(a) == null) {
                        ghidra.program.model.listing.Function f = createFunction(a, "f_" + a);
                        if (f != null) created++; else already++;
                    } else already++;
                    i += 2; continue;
                }
                // undefined '??' data word -> clear before disassembling
                if (cu != null) {
                    clearListing(a, a);
                    cleared++;
                    if (w == 0x4F22) zeroCleared++; else zeroRun++;
                }
                try {
                    disassemble(a);
                    ghidra.program.model.listing.Function f = createFunction(a, "f_" + a);
                    if (f != null) created++;
                } catch (Exception e) {
                    // ignore bad candidates
                }
                i += 2;
            }
        }
        println("Vf3Prologue: runs=" + runs + " cleared=" + cleared +
                " (sts " + zeroCleared + ", other " + zeroRun + ") created=" + created +
                " alreadyFnNoCreate=" + already);
    }
}
