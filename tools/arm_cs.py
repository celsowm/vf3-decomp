import sys, capstone

data = open('extract/gamedata/SNDDRV.BIN','rb').read()
lo = int(sys.argv[1],0)
hi = int(sys.argv[2],0)
md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
md.detail = False
for ins in md.disasm(data[lo:hi], lo):
    print('%06x: %08x  %-8s %s' % (ins.address, int.from_bytes(data[ins.address:ins.address+4],'little'), ins.mnemonic, ins.op_str))
