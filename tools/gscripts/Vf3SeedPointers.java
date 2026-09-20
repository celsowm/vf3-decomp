//VF3 literal-pool pointer seeding — adapted from dream-recomp's SeedFromPointers.java
//(github.com/phobos665/dream-recomp, GPL-2.0; tools/ghidra/SeedFromPointers.java).
//
//Rationale: SH-4 code reaches functions through 32-bit pointers in literal pools
//(MOV.L @(disp,PC),Rn ; JSR @Rn) and function tables, so recursive descent stalls.
//Every aligned 32-bit word that points at still-undefined bytes inside the image at
//an even address is treated as a code pointer: disassemble, create function,
//re-analyze, repeat until a round adds nothing.
//
//VF3 adaptations vs upstream:
//  - P2 alias handling: tables may hold 0x0Cxxxxxx aliases (physical view) of our
//    0x8Cxxxxxx P1 image; try V, then V|0x80000000 when V is in 0x0C000000-0x0CFFFFFF.
//  - Sanity bounds: only accept targets inside the initialized image blocks.
//  - Writes created-address CSV to $VF3_OUT/seed_<prog>.csv for the spiders.
//
//Usage: python tools/ghidra_run.py run 1ST_READ.unsc.bin -p Vf3SeedPointers.java
//@category VF3
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Vf3SeedPointers extends GhidraScript {
    private static final int MAX_ROUNDS = 8;

    private Address mapTarget(Memory mem, long v) {
        if ((v & 1) != 0) return null;
        // Direct target?
        Address a = toAddr(v);
        MemoryBlock b = mem.getBlock(a);
        if (b != null && b.isInitialized()) return a;
        // P2 alias of P1: 0x0Cxxxxxx -> 0x8Cxxxxxx
        if (v >= 0x0C000000L && v <= 0x0CFFFFFFL) {
            a = toAddr(v | 0x80000000L);
            b = mem.getBlock(a);
            if (b != null && b.isInitialized()) return a;
        }
        return null;
    }

    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        ArrayList<String> createdList = new ArrayList<>();

        int totalCreated = 0;
        for (int round = 1; round <= MAX_ROUNDS; round++) {
            int candidates = 0, created = 0;
            // Walk each initialised block separately: blocks are not contiguous and
            // reading across a gap throws.
            for (MemoryBlock blk : mem.getBlocks()) {
                if (!blk.isInitialized()) continue;
                long loOff = blk.getStart().getOffset();
                long hiOff = blk.getEnd().getOffset();
                for (long off = loOff; off + 4 <= hiOff; off += 4) {
                    if (monitor.isCancelled()) return;
                    Address a = toAddr(off);
                    // A pointer lives in data, not inside an instruction.
                    if (currentProgram.getListing().getInstructionContaining(a) != null) continue;
                    long v = mem.getInt(a) & 0xFFFFFFFFL;
                    Address target = mapTarget(mem, v);
                    if (target == null) continue;
                    if (getInstructionAt(target) != null
                            || currentProgram.getListing().getDefinedDataAt(target) != null) continue;
                    if (currentProgram.getListing().getInstructionContaining(target) != null) continue;
                    candidates++;
                    if (!disassemble(target)) continue;
                    if (getInstructionAt(target) == null) continue;
                    if (createFunction(target, null) != null) {
                        created++;
                        createdList.add(target.toString());
                    }
                }
            }
            println("Vf3SeedPointers: round " + round + ": " + candidates
                    + " pointer targets, " + created + " functions created");
            totalCreated += created;
            if (created == 0) break;
            analyzeChanges(currentProgram);
        }
        println("Vf3SeedPointers: total " + totalCreated + " functions seeded, "
                + currentProgram.getFunctionManager().getFunctionCount() + " functions now");

        String outdir = System.getenv("VF3_OUT");
        if (outdir == null) outdir = ".";
        new File(outdir).mkdirs();
        String csv = outdir + File.separator + "seed_"
                + currentProgram.getName().replaceAll("[^A-Za-z0-9_.-]", "_") + ".csv";
        try (PrintWriter w = new PrintWriter(csv)) {
            w.println("entry");
            for (String s : createdList) w.println(s);
        }
        println("csv: " + csv);
    }
}
