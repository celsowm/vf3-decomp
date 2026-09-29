import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;

public class Vf3DisasmAt extends GhidraScript {
    @Override
    public void run() throws Exception {
        String list = System.getenv("VF3_CHECK_ADDRS");
        int count = Integer.parseInt(System.getenv().getOrDefault("VF3_COUNT", "32"));
        if (list == null) {
            println("VF3_CHECK_ADDRS not set");
            return;
        }
        for (String item : list.split(",")) {
            Address start = toAddr(Long.parseLong(item.trim().replace("0x", ""), 16));
            println("== " + start + " ==");
            Address cur = start;
            for (int i = 0; i < count; i++) {
                Instruction ins = currentProgram.getListing().getInstructionAt(cur);
                if (ins == null) {
                    if (!disassemble(cur)) {
                        println("   <undecodable at " + cur + ">");
                        cur = cur.add(2);
                        continue;
                    }
                    ins = currentProgram.getListing().getInstructionAt(cur);
                }
                if (ins == null) {
                    println("   <no instruction at " + cur + ">");
                    cur = cur.add(2);
                    continue;
                }
                println("   " + ins.getMinAddress() + "  " + ins);
                cur = ins.getMaxAddress().add(1);
            }
        }
    }
}
