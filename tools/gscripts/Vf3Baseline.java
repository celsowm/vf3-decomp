//Ghidra headless postScript: dump function inventory + memory map for VF3.
//Run via analyzeHeadless with -scriptPath tools/ghidra_scripts
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.mem.MemoryBlock;
import java.io.File;
import java.io.PrintWriter;

public class Vf3Baseline extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outdir = System.getenv("VF3_OUT");
        if (outdir == null) {
            outdir = ".";
        }
        new File(outdir).mkdirs();

        StringBuilder blockInfo = new StringBuilder();
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            blockInfo.append(String.format("%-12s %-12s size=0x%X%n",
                    b.getStart(), b.getName(), b.getSize()));
        }

        String csvPath = outdir + File.separator + "funcs_" +
                currentProgram.getName().replaceAll("[^A-Za-z0-9_.-]", "_") + ".csv";
        int n = 0;
        long bodies = 0;
        try (PrintWriter csv = new PrintWriter(csvPath)) {
            csv.println("entry,size,name");
            FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
            while (it.hasNext()) {
                Function f = it.next();
                csv.println(f.getEntryPoint() + "," + f.getBody().getNumAddresses() + "," + f.getName());
                n++;
                bodies += f.getBody().getNumAddresses();
            }
        }

        println("=== VF3 baseline ===");
        println("blocks:\n" + blockInfo);
        println("functions: " + n + ", total body bytes: " + bodies);
        println("csv: " + csvPath);
    }
}
