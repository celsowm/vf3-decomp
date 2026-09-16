//Print N instructions starting at each address listed in VF3_CHECK_ADDRS (comma-sep hex)
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;

public class Vf3Disasm extends GhidraScript {
    @Override
    public void run() throws Exception {
        String list = System.getenv("VF3_CHECK_ADDRS");
        if (list == null) { println("VF3_CHECK_ADDRS not set"); return; }
        for (String s : list.split(",")) {
            long v = Long.parseLong(s.trim().replace("0x", ""), 16);
            Address a = toAddr(v);
            println("== " + s + " ==");
            Address cur = a;
            for (int i = 0; i < 8; i++) {
                Instruction ins = currentProgram.getListing().getInstructionAt(cur);
                if (ins == null) { println("   <no instr at " + cur + ">"); break; }
                println("   " + ins.getMinAddress() + "  " + ins.toString());
                cur = ins.getMaxAddress().add(1);
            }
        }
    }
}
