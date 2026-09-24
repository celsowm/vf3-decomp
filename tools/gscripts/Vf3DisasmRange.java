//Dump full instruction range for each address in VF3_CHECK_ADDRS.
//Count from VF3_COUNT (default 80). Includes operand refs + literals.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;

public class Vf3DisasmRange extends GhidraScript {
    @Override
    public void run() throws Exception {
        String list = System.getenv("VF3_CHECK_ADDRS");
        if (list == null) { println("VF3_CHECK_ADDRS not set"); return; }
        int count = 80;
        String cs = System.getenv("VF3_COUNT");
        if (cs != null) count = Integer.parseInt(cs.trim());
        for (String s : list.split(",")) {
            long v = Long.parseLong(s.trim().replace("0x", ""), 16);
            Address a = toAddr(v);
            println("== " + s + " ==");
            Address cur = a;
            for (int i = 0; i < count; i++) {
                Instruction ins = currentProgram.getListing().getInstructionAt(cur);
                if (ins == null) {
                    println("   <no instr at " + cur + ">");
                    // skip one word and continue — data islands mid-function
                    cur = cur.add(2);
                    continue;
                }
                StringBuilder sb = new StringBuilder();
                sb.append("   ").append(ins.getMinAddress()).append("  ");
                sb.append(ins.toString());
                for (int op = 0; op < ins.getNumOperands(); op++) {
                    for (Reference ref : ins.getOperandReferences(op)) {
                        Address to = ref.getToAddress();
                        if (to != null && !to.equals(ins.getMinAddress()))
                            sb.append("  ; ->").append(to);
                    }
                }
                println(sb.toString());
                cur = ins.getMaxAddress().add(1);
            }
        }
    }
}
