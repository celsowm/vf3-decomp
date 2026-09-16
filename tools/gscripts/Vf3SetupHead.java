//Fixes the program head for Katana 1ST_READ layout:
//  DSGLH @0x8C010000 (0x60 bytes data), DSGLE @0x8C010060 (0x20 bytes data),
//  code ("P" section) starts at 0x8C010080.
//Clears the bogus disassembly at file start and creates the real entry
//function as "_entry" @0x8C010080 (marked as program entry point).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.SourceType;

public class Vf3SetupHead extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address head = toAddr(0x8C010000L);
        Address code = toAddr(0x8C010080L);
        // drop the bogus function created at file start by earlier experiments
        var stale = currentProgram.getFunctionManager().getFunctionAt(head);
        if (stale != null && "_start".equals(stale.getName())) {
            currentProgram.getFunctionManager().removeFunction(head);
            println("removed stale _start at " + head);
        }
        // clear the (mis-)disassembled pseudo-code at file start
        clearListing(head, code);
        // label the DSGLH data header
        try {
            if (currentProgram.getSymbolTable().getSymbols(head).length == 0)
                createLabel(head, "DSGLH", false);
        } catch (Exception e) { /* exists */ }
        disassemble(code);
        var f = createFunction(code, "_entry");
        if (f != null) {
            try { f.setName("_entry", SourceType.USER_DEFINED); } catch (Exception ignored) {}
            println("entry function created at " + code);
        } else {
            var existing = currentProgram.getFunctionManager().getFunctionAt(code);
            println("entry function already exists: " + (existing != null ? existing.getName() : "none"));
        }
        // mark as program entry point
        try {
            currentProgram.getSymbolTable().addExternalEntryPoint(code);
            println("entry point registered");
        } catch (Exception e) {
            println("entry point registration failed: " + e);
        }
    }
}
