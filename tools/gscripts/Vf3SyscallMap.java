//Syscall region mapping for Dreamcast:
// - creates a read-only block at 0x8C000000..0x8C00FFFF (low RAM area the
//   boot ROM writes the syscall vector block into: 0x8C0000B0 region)
// - defines named labels for the known vector slots
// - reports every instruction in the program that references 0x8C0000A0-0x8C0000FF
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import java.util.TreeMap;

public class Vf3SyscallMap extends GhidraScript {

    private static final Object[][] SLOTS = {
        {0x8C0000B0L, "SYS_SYSTEM"},
        {0x8C0000B4L, "SYS_FONT"},
        {0x8C0000B8L, "SYS_FLASHGD"},
        {0x8C0000BCL, "SYS_MISC"},
    };

    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        if (mem.getBlock("lowram") == null) {
            MemoryBlock b = mem.createUninitializedBlock(
                    "lowram", toAddr(0x8C000000L), 0x10000, false);
            b.setRead(true);
            b.setWrite(false);
            b.setExecute(false);
        }
        var st = currentProgram.getSymbolTable();
        for (Object[] s : SLOTS) {
            long addr = (Long) s[0];
            String name = (String) s[1];
            Address a = toAddr(addr);
            try {
                if (currentProgram.getSymbolTable().getSymbols(a).length == 0)
                    createLabel(a, name, false);
            } catch (Exception e) {
                println("label fail " + name + ": " + e);
            }
            // u32 pointer data at that slot
            clearListing(a, a);
            try { createData(a, ghidra.program.model.data.PointerDataType.dataType); } catch (Exception e) {}
        }

        // scan all instructions for operand references into 0x8C0000A0..0x8C0000FF
        TreeMap<Long, Integer> hits = new TreeMap<>();
        TreeMap<Long, Address> firstRef = new TreeMap<>();
        InstructionIterator it = currentProgram.getListing().getInstructions(true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            for (int op = 0; op < ins.getNumOperands(); op++) {
                for (ghidra.program.model.symbol.Reference ref : ins.getOperandReferences(op)) {
                    long off = ref.getToAddress().getOffset();
                    if (off >= 0x8C0000A0L && off <= 0x8C0000FFL) {
                        hits.merge(off, 1, Integer::sum);
                        firstRef.putIfAbsent(off, ins.getMinAddress());
                    }
                }
            }
        }
        println("== syscall region references (slot -> count, first ref site) ==");
        for (var e : hits.entrySet()) {
            println(String.format("0x%08X  %4d  first at %s", e.getKey(), e.getValue(), firstRef.get(e.getKey())));
        }
        if (hits.isEmpty()) println("(no references found - xsrefs may need analysis)");
    }
}
