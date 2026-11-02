import struct, sys
def low(path, n=0x10000):
    f = open(path, 'rb'); f.seek(8 * (1 + 37 + 1 + 16 + 1 + 3)); d = f.read(n); f.close(); return d
a = low(sys.argv[1]); b = low(sys.argv[2])
print('same low:', a == b)
for i in range(0, 0x10000, 4):
    if a[i:i+4] != b[i:i+4]:
        print('first diff', hex(i), a[i:i+4].hex(), b[i:i+4].hex()); break
print('nonzero a', sum(1 for x in a if x), 'nonzero b', sum(1 for x in b if x))
# registers
def regs(path):
    f = open(path, 'rb'); f.seek(8); d = struct.unpack('<37Q', f.read(8*37)); f.close(); return d
ra = regs(sys.argv[1]); rb = regs(sys.argv[2])
print('regs equal:', ra == rb)
for i, (x, y) in enumerate(zip(ra, rb)):
    if x != y:
        print(' reg', i, hex(x), hex(y))
