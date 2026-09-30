// Read-only address ranges for honest union coverage of fragmented bodies.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressRangeIterator;
import java.io.File;
import java.io.PrintWriter;

public class Vf3BodyRanges extends GhidraScript {
    public void run() throws Exception {
        String out = System.getenv("VF3_OUT");
        if (out == null) out = "extract/analysis";
        new File(out).mkdirs();
        try (PrintWriter csv = new PrintWriter(new File(out, "function_body_ranges.csv"))) {
            csv.println("entry,start,end");
            FunctionIterator funcs = currentProgram.getFunctionManager().getFunctions(true);
            while (funcs.hasNext()) {
                Function f = funcs.next();
                AddressRangeIterator ranges = f.getBody().getAddressRanges();
                while (ranges.hasNext()) {
                    AddressRange r = ranges.next();
                    csv.println(f.getEntryPoint() + "," + r.getMinAddress() + "," +
                        Long.toHexString(r.getMaxAddress().getOffset() + 1));
                }
            }
        }
        println("Read-only body range export complete");
    }
}
