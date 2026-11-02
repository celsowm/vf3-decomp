/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
#define pref vf3_matrix_pref
void vf3_matrix_pref(const vf3_ram_map*,uint32_t);
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_away_batch19_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03fc90u: goto P_0c03fc90;
case 0x0c03fc92u: goto P_0c03fc92;
case 0x0c03fc94u: goto P_0c03fc94;
case 0x0c03fc96u: goto P_0c03fc96;
case 0x0c03fc98u: goto P_0c03fc98;
case 0x0c03fc9au: goto P_0c03fc9a;
case 0x0c03fc9cu: goto P_0c03fc9c;
case 0x0c03fc9eu: goto P_0c03fc9e;
case 0x0c03fca0u: goto P_0c03fca0;
case 0x0c03fca2u: goto P_0c03fca2;
case 0x0c03fca4u: goto P_0c03fca4;
case 0x0c03fca6u: goto P_0c03fca6;
case 0x0c03fca8u: goto P_0c03fca8;
case 0x0c03fcaau: goto P_0c03fcaa;
case 0x0c03fcacu: goto P_0c03fcac;
case 0x0c03fcaeu: goto P_0c03fcae;
case 0x0c03fcb0u: goto P_0c03fcb0;
case 0x0c03fcb2u: goto P_0c03fcb2;
case 0x0c03fcb4u: goto P_0c03fcb4;
case 0x0c03fcb6u: goto P_0c03fcb6;
case 0x0c03fcb8u: goto P_0c03fcb8;
case 0x0c03fcbau: goto P_0c03fcba;
case 0x0c03fcbcu: goto P_0c03fcbc;
case 0x0c03fcbeu: goto P_0c03fcbe;
case 0x0c03fcc0u: goto P_0c03fcc0;
case 0x0c03fcc2u: goto P_0c03fcc2;
case 0x0c03fcc4u: goto P_0c03fcc4;
case 0x0c03fcc6u: goto P_0c03fcc6;
case 0x0c03fcc8u: goto P_0c03fcc8;
case 0x0c03fccau: goto P_0c03fcca;
case 0x0c03fcccu: goto P_0c03fccc;
case 0x0c03fcceu: goto P_0c03fcce;
case 0x0c03fcd0u: goto P_0c03fcd0;
case 0x0c03fcd2u: goto P_0c03fcd2;
case 0x0c03fcd4u: goto P_0c03fcd4;
case 0x0c03fcd6u: goto P_0c03fcd6;
case 0x0c03fcd8u: goto P_0c03fcd8;
case 0x0c03fcdau: goto P_0c03fcda;
case 0x0c03fcdcu: goto P_0c03fcdc;
case 0x0c03fcdeu: goto P_0c03fcde;
case 0x0c03fce0u: goto P_0c03fce0;
case 0x0c03fce2u: goto P_0c03fce2;
case 0x0c03fce4u: goto P_0c03fce4;
case 0x0c03fce6u: goto P_0c03fce6;
case 0x0c03fce8u: goto P_0c03fce8;
case 0x0c03fceau: goto P_0c03fcea;
case 0x0c03fcecu: goto P_0c03fcec;
case 0x0c03fcf0u: goto P_0c03fcf0;
case 0x0c03fcf2u: goto P_0c03fcf2;
case 0x0c03fcf4u: goto P_0c03fcf4;
case 0x0c03fcf6u: goto P_0c03fcf6;
case 0x0c03fcf8u: goto P_0c03fcf8;
case 0x0c03fcfau: goto P_0c03fcfa;
case 0x0c03fcfcu: goto P_0c03fcfc;
case 0x0c03fcfeu: goto P_0c03fcfe;
case 0x0c03fd00u: goto P_0c03fd00;
case 0x0c03fd02u: goto P_0c03fd02;
case 0x0c03fd04u: goto P_0c03fd04;
case 0x0c03fd06u: goto P_0c03fd06;
case 0x0c03fd08u: goto P_0c03fd08;
case 0x0c03fd0au: goto P_0c03fd0a;
case 0x0c03fd10u: goto P_0c03fd10;
case 0x0c03fd12u: goto P_0c03fd12;
case 0x0c03fd14u: goto P_0c03fd14;
case 0x0c03fd16u: goto P_0c03fd16;
case 0x0c03fd18u: goto P_0c03fd18;
case 0x0c03fd1au: goto P_0c03fd1a;
case 0x0c03fd1cu: goto P_0c03fd1c;
case 0x0c03fd1eu: goto P_0c03fd1e;
case 0x0c03fd20u: goto P_0c03fd20;
case 0x0c03fd22u: goto P_0c03fd22;
case 0x0c03fd24u: goto P_0c03fd24;
case 0x0c03fd26u: goto P_0c03fd26;
case 0x0c03fd28u: goto P_0c03fd28;
case 0x0c03fd2au: goto P_0c03fd2a;
case 0x0c03fd2cu: goto P_0c03fd2c;
case 0x0c03fd2eu: goto P_0c03fd2e;
case 0x0c03fd30u: goto P_0c03fd30;
case 0x0c03fd32u: goto P_0c03fd32;
case 0x0c03fd34u: goto P_0c03fd34;
case 0x0c03fd36u: goto P_0c03fd36;
case 0x0c03fd38u: goto P_0c03fd38;
case 0x0c03fd3au: goto P_0c03fd3a;
case 0x0c03fd3cu: goto P_0c03fd3c;
case 0x0c03fd3eu: goto P_0c03fd3e;
case 0x0c03fd40u: goto P_0c03fd40;
case 0x0c03fd42u: goto P_0c03fd42;
case 0x0c03fd44u: goto P_0c03fd44;
case 0x0c03fd70u: goto P_0c03fd70;
case 0x0c03fd72u: goto P_0c03fd72;
case 0x0c03fd74u: goto P_0c03fd74;
case 0x0c03fd76u: goto P_0c03fd76;
case 0x0c03fd78u: goto P_0c03fd78;
case 0x0c03fd7au: goto P_0c03fd7a;
case 0x0c03fd7cu: goto P_0c03fd7c;
case 0x0c03fd7eu: goto P_0c03fd7e;
case 0x0c03fd80u: goto P_0c03fd80;
case 0x0c03fd82u: goto P_0c03fd82;
case 0x0c03fd84u: goto P_0c03fd84;
case 0x0c03fd86u: goto P_0c03fd86;
case 0x0c03fd88u: goto P_0c03fd88;
case 0x0c03fd8au: goto P_0c03fd8a;
case 0x0c03fd8cu: goto P_0c03fd8c;
case 0x0c03fd8eu: goto P_0c03fd8e;
case 0x0c03fd90u: goto P_0c03fd90;
case 0x0c03fd92u: goto P_0c03fd92;
case 0x0c03fd94u: goto P_0c03fd94;
case 0x0c03fda0u: goto P_0c03fda0;
case 0x0c03fda2u: goto P_0c03fda2;
case 0x0c03fda4u: goto P_0c03fda4;
case 0x0c03fda6u: goto P_0c03fda6;
case 0x0c03fda8u: goto P_0c03fda8;
case 0x0c03fdaau: goto P_0c03fdaa;
case 0x0c03fdacu: goto P_0c03fdac;
case 0x0c03fdaeu: goto P_0c03fdae;
case 0x0c03fdb0u: goto P_0c03fdb0;
case 0x0c03fdb2u: goto P_0c03fdb2;
case 0x0c03fdb4u: goto P_0c03fdb4;
case 0x0c03fdb6u: goto P_0c03fdb6;
case 0x0c03fdb8u: goto P_0c03fdb8;
case 0x0c03fdbau: goto P_0c03fdba;
case 0x0c03fdbcu: goto P_0c03fdbc;
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03fc90: /* original 2fe6, guest PC 0x0c03fc90 */
if(!s->budget--) { s->failed_pc=0x0c03fc90u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fc92;
P_0c03fc92: /* original 6e43, guest PC 0x0c03fc92 */
if(!s->budget--) { s->failed_pc=0x0c03fc92u; return 0; }
r[14]=r[4];
goto P_0c03fc94;
P_0c03fc94: /* original d32d, guest PC 0x0c03fc94 */
if(!s->budget--) { s->failed_pc=0x0c03fc94u; return 0; }
r[3]=read(ram,0x0c03fd4cu,4);
goto P_0c03fc96;
P_0c03fc96: /* original 4f22, guest PC 0x0c03fc96 */
if(!s->budget--) { s->failed_pc=0x0c03fc96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fc98;
P_0c03fc98: /* original 2e32, guest PC 0x0c03fc98 */
if(!s->budget--) { s->failed_pc=0x0c03fc98u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c03fc9a;
P_0c03fc9a: /* original d22d, guest PC 0x0c03fc9a */
if(!s->budget--) { s->failed_pc=0x0c03fc9au; return 0; }
r[2]=read(ram,0x0c03fd50u,4);
goto P_0c03fc9c;
P_0c03fc9c: /* original 1e21, guest PC 0x0c03fc9c */
if(!s->budget--) { s->failed_pc=0x0c03fc9cu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c03fc9e;
P_0c03fc9e: /* original e200, guest PC 0x0c03fc9e */
if(!s->budget--) { s->failed_pc=0x0c03fc9eu; return 0; }
r[2]=0x00000000u;
goto P_0c03fca0;
P_0c03fca0: /* original 9352, guest PC 0x0c03fca0 */
if(!s->budget--) { s->failed_pc=0x0c03fca0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03fd48u,2);
goto P_0c03fca2;
P_0c03fca2: /* original 1e32, guest PC 0x0c03fca2 */
if(!s->budget--) { s->failed_pc=0x0c03fca2u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c03fca4;
P_0c03fca4: /* original 1e23, guest PC 0x0c03fca4 */
if(!s->budget--) { s->failed_pc=0x0c03fca4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03fca6;
P_0c03fca6: /* original d32b, guest PC 0x0c03fca6 */
if(!s->budget--) { s->failed_pc=0x0c03fca6u; return 0; }
r[3]=read(ram,0x0c03fd54u,4);
goto P_0c03fca8;
P_0c03fca8: /* original 430b, guest PC 0x0c03fca8 */
if(!s->budget--) { s->failed_pc=0x0c03fca8u; return 0; }
target=r[3];
r[16]=code_base|0x0c03fcacu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03fcacu) { target=s->pc; goto dispatch; }
goto P_0c03fcac;
P_0c03fcaa: /* original 64e3, guest PC 0x0c03fcaa */
if(!s->budget--) { s->failed_pc=0x0c03fcaau; return 0; }
r[4]=r[14];
goto P_0c03fcac;
P_0c03fcac: /* original 55e3, guest PC 0x0c03fcac */
if(!s->budget--) { s->failed_pc=0x0c03fcacu; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c03fcae;
P_0c03fcae: /* original e3e5, guest PC 0x0c03fcae */
if(!s->budget--) { s->failed_pc=0x0c03fcaeu; return 0; }
r[3]=0xffffffe5u;
goto P_0c03fcb0;
P_0c03fcb0: /* original e407, guest PC 0x0c03fcb0 */
if(!s->budget--) { s->failed_pc=0x0c03fcb0u; return 0; }
r[4]=0x00000007u;
goto P_0c03fcb2;
P_0c03fcb2: /* original 453d, guest PC 0x0c03fcb2 */
if(!s->budget--) { s->failed_pc=0x0c03fcb2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c03fcb4;
P_0c03fcb4: /* original 2549, guest PC 0x0c03fcb4 */
if(!s->budget--) { s->failed_pc=0x0c03fcb4u; return 0; }
r[5]&=r[4];
goto P_0c03fcb6;
P_0c03fcb6: /* original 2558, guest PC 0x0c03fcb6 */
if(!s->budget--) { s->failed_pc=0x0c03fcb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03fcb8;
P_0c03fcb8: /* original e200, guest PC 0x0c03fcb8 */
if(!s->budget--) { s->failed_pc=0x0c03fcb8u; return 0; }
r[2]=0x00000000u;
goto P_0c03fcba;
P_0c03fcba: /* original 8d04, guest PC 0x0c03fcba */
if(!s->budget--) { s->failed_pc=0x0c03fcbau; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[2],4);
if(cond) { goto P_0c03fcc6; }
goto P_0c03fcbe;
P_0c03fcbc: /* original 1e25, guest PC 0x0c03fcbc */
if(!s->budget--) { s->failed_pc=0x0c03fcbcu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c03fcbe;
P_0c03fcbe: /* original 6053, guest PC 0x0c03fcbe */
if(!s->budget--) { s->failed_pc=0x0c03fcbeu; return 0; }
r[0]=r[5];
goto P_0c03fcc0;
P_0c03fcc0: /* original 0009, guest PC 0x0c03fcc0 */
if(!s->budget--) { s->failed_pc=0x0c03fcc0u; return 0; }
goto P_0c03fcc2;
P_0c03fcc2: /* original 8802, guest PC 0x0c03fcc2 */
if(!s->budget--) { s->failed_pc=0x0c03fcc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03fcc4;
P_0c03fcc4: /* original 8b01, guest PC 0x0c03fcc4 */
if(!s->budget--) { s->failed_pc=0x0c03fcc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fcca; }
goto P_0c03fcc6;
P_0c03fcc6: /* original e301, guest PC 0x0c03fcc6 */
if(!s->budget--) { s->failed_pc=0x0c03fcc6u; return 0; }
r[3]=0x00000001u;
goto P_0c03fcc8;
P_0c03fcc8: /* original 1e35, guest PC 0x0c03fcc8 */
if(!s->budget--) { s->failed_pc=0x0c03fcc8u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c03fcca;
P_0c03fcca: /* original 50e2, guest PC 0x0c03fcca */
if(!s->budget--) { s->failed_pc=0x0c03fccau; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fccc;
P_0c03fccc: /* original d522, guest PC 0x0c03fccc */
if(!s->budget--) { s->failed_pc=0x0c03fcccu; return 0; }
r[5]=read(ram,0x0c03fd58u,4);
goto P_0c03fcce;
P_0c03fcce: /* original 4009, guest PC 0x0c03fcce */
if(!s->budget--) { s->failed_pc=0x0c03fcceu; return 0; }
r[0]>>=2;
goto P_0c03fcd0;
P_0c03fcd0: /* original 4001, guest PC 0x0c03fcd0 */
if(!s->budget--) { s->failed_pc=0x0c03fcd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c03fcd2;
P_0c03fcd2: /* original 2049, guest PC 0x0c03fcd2 */
if(!s->budget--) { s->failed_pc=0x0c03fcd2u; return 0; }
r[0]&=r[4];
goto P_0c03fcd4;
P_0c03fcd4: /* original 4008, guest PC 0x0c03fcd4 */
if(!s->budget--) { s->failed_pc=0x0c03fcd4u; return 0; }
r[0]<<=2;
goto P_0c03fcd6;
P_0c03fcd6: /* original f356, guest PC 0x0c03fcd6 */
if(!s->budget--) { s->failed_pc=0x0c03fcd6u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fcd8;
P_0c03fcd8: /* original e018, guest PC 0x0c03fcd8 */
if(!s->budget--) { s->failed_pc=0x0c03fcd8u; return 0; }
r[0]=0x00000018u;
goto P_0c03fcda;
P_0c03fcda: /* original 4f26, guest PC 0x0c03fcda */
if(!s->budget--) { s->failed_pc=0x0c03fcdau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fcdc;
P_0c03fcdc: /* original fe37, guest PC 0x0c03fcdc */
if(!s->budget--) { s->failed_pc=0x0c03fcdcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcde;
P_0c03fcde: /* original 50e2, guest PC 0x0c03fcde */
if(!s->budget--) { s->failed_pc=0x0c03fcdeu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fce0;
P_0c03fce0: /* original 2049, guest PC 0x0c03fce0 */
if(!s->budget--) { s->failed_pc=0x0c03fce0u; return 0; }
r[0]&=r[4];
goto P_0c03fce2;
P_0c03fce2: /* original 4008, guest PC 0x0c03fce2 */
if(!s->budget--) { s->failed_pc=0x0c03fce2u; return 0; }
r[0]<<=2;
goto P_0c03fce4;
P_0c03fce4: /* original f356, guest PC 0x0c03fce4 */
if(!s->budget--) { s->failed_pc=0x0c03fce4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fce6;
P_0c03fce6: /* original e01c, guest PC 0x0c03fce6 */
if(!s->budget--) { s->failed_pc=0x0c03fce6u; return 0; }
r[0]=0x0000001cu;
goto P_0c03fce8;
P_0c03fce8: /* original fe37, guest PC 0x0c03fce8 */
if(!s->budget--) { s->failed_pc=0x0c03fce8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcea;
P_0c03fcea: /* original 000b, guest PC 0x0c03fcea */
if(!s->budget--) { s->failed_pc=0x0c03fceau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fcec: /* original 6ef6, guest PC 0x0c03fcec */
if(!s->budget--) { s->failed_pc=0x0c03fcecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fceeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fceeu; return 0; } return 1;
P_0c03fcf0: /* original 2fe6, guest PC 0x0c03fcf0 */
if(!s->budget--) { s->failed_pc=0x0c03fcf0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf2;
P_0c03fcf2: /* original 2fd6, guest PC 0x0c03fcf2 */
if(!s->budget--) { s->failed_pc=0x0c03fcf2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf4;
P_0c03fcf4: /* original 2fb6, guest PC 0x0c03fcf4 */
if(!s->budget--) { s->failed_pc=0x0c03fcf4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf6;
P_0c03fcf6: /* original eb00, guest PC 0x0c03fcf6 */
if(!s->budget--) { s->failed_pc=0x0c03fcf6u; return 0; }
r[11]=0x00000000u;
goto P_0c03fcf8;
P_0c03fcf8: /* original 2fa6, guest PC 0x0c03fcf8 */
if(!s->budget--) { s->failed_pc=0x0c03fcf8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfa;
P_0c03fcfa: /* original ea01, guest PC 0x0c03fcfa */
if(!s->budget--) { s->failed_pc=0x0c03fcfau; return 0; }
r[10]=0x00000001u;
goto P_0c03fcfc;
P_0c03fcfc: /* original 2f96, guest PC 0x0c03fcfc */
if(!s->budget--) { s->failed_pc=0x0c03fcfcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfe;
P_0c03fcfe: /* original e920, guest PC 0x0c03fcfe */
if(!s->budget--) { s->failed_pc=0x0c03fcfeu; return 0; }
r[9]=0x00000020u;
goto P_0c03fd00;
P_0c03fd00: /* original 2f86, guest PC 0x0c03fd00 */
if(!s->budget--) { s->failed_pc=0x0c03fd00u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fd02;
P_0c03fd02: /* original 4f22, guest PC 0x0c03fd02 */
if(!s->budget--) { s->failed_pc=0x0c03fd02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fd04;
P_0c03fd04: /* original d716, guest PC 0x0c03fd04 */
if(!s->budget--) { s->failed_pc=0x0c03fd04u; return 0; }
r[7]=read(ram,0x0c03fd60u,4);
goto P_0c03fd06;
P_0c03fd06: /* original d815, guest PC 0x0c03fd06 */
if(!s->budget--) { s->failed_pc=0x0c03fd06u; return 0; }
r[8]=read(ram,0x0c03fd5cu,4);
goto P_0c03fd08;
P_0c03fd08: /* original a033, guest PC 0x0c03fd08 */
if(!s->budget--) { s->failed_pc=0x0c03fd08u; return 0; }
r[5]=r[11];
goto P_0c03fd72;
P_0c03fd0a: /* original 65b3, guest PC 0x0c03fd0a */
if(!s->budget--) { s->failed_pc=0x0c03fd0au; return 0; }
r[5]=r[11];
if(!vf3_matrix_family(0x0c03fd0cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd0cu; return 0; } return 1;
P_0c03fd10: /* original 6072, guest PC 0x0c03fd10 */
if(!s->budget--) { s->failed_pc=0x0c03fd10u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd12;
P_0c03fd12: /* original 6e53, guest PC 0x0c03fd12 */
if(!s->budget--) { s->failed_pc=0x0c03fd12u; return 0; }
r[14]=r[5];
goto P_0c03fd14;
P_0c03fd14: /* original 4e08, guest PC 0x0c03fd14 */
if(!s->budget--) { s->failed_pc=0x0c03fd14u; return 0; }
r[14]<<=2;
goto P_0c03fd16;
P_0c03fd16: /* original 00ee, guest PC 0x0c03fd16 */
if(!s->budget--) { s->failed_pc=0x0c03fd16u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c03fd18;
P_0c03fd18: /* original 88ff, guest PC 0x0c03fd18 */
if(!s->budget--) { s->failed_pc=0x0c03fd18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03fd1a;
P_0c03fd1a: /* original 8d29, guest PC 0x0c03fd1a */
if(!s->budget--) { s->failed_pc=0x0c03fd1au; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c03fd70; }
goto P_0c03fd1e;
P_0c03fd1c: /* original 6d03, guest PC 0x0c03fd1c */
if(!s->budget--) { s->failed_pc=0x0c03fd1cu; return 0; }
r[13]=r[0];
goto P_0c03fd1e;
P_0c03fd1e: /* original 6153, guest PC 0x0c03fd1e */
if(!s->budget--) { s->failed_pc=0x0c03fd1eu; return 0; }
r[1]=r[5];
goto P_0c03fd20;
P_0c03fd20: /* original 4108, guest PC 0x0c03fd20 */
if(!s->budget--) { s->failed_pc=0x0c03fd20u; return 0; }
r[1]<<=2;
goto P_0c03fd22;
P_0c03fd22: /* original 4108, guest PC 0x0c03fd22 */
if(!s->budget--) { s->failed_pc=0x0c03fd22u; return 0; }
r[1]<<=2;
goto P_0c03fd24;
P_0c03fd24: /* original 66b3, guest PC 0x0c03fd24 */
if(!s->budget--) { s->failed_pc=0x0c03fd24u; return 0; }
r[6]=r[11];
goto P_0c03fd26;
P_0c03fd26: /* original 4100, guest PC 0x0c03fd26 */
if(!s->budget--) { s->failed_pc=0x0c03fd26u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c03fd28;
P_0c03fd28: /* original 64a3, guest PC 0x0c03fd28 */
if(!s->budget--) { s->failed_pc=0x0c03fd28u; return 0; }
r[4]=r[10];
goto P_0c03fd2a;
P_0c03fd2a: /* original 62d3, guest PC 0x0c03fd2a */
if(!s->budget--) { s->failed_pc=0x0c03fd2au; return 0; }
r[2]=r[13];
goto P_0c03fd2c;
P_0c03fd2c: /* original 2248, guest PC 0x0c03fd2c */
if(!s->budget--) { s->failed_pc=0x0c03fd2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c03fd2e;
P_0c03fd2e: /* original 8b07, guest PC 0x0c03fd2e */
if(!s->budget--) { s->failed_pc=0x0c03fd2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd40; }
goto P_0c03fd30;
P_0c03fd30: /* original 6072, guest PC 0x0c03fd30 */
if(!s->budget--) { s->failed_pc=0x0c03fd30u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd32;
P_0c03fd32: /* original 02ee, guest PC 0x0c03fd32 */
if(!s->budget--) { s->failed_pc=0x0c03fd32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c03fd34;
P_0c03fd34: /* original 224b, guest PC 0x0c03fd34 */
if(!s->budget--) { s->failed_pc=0x0c03fd34u; return 0; }
r[2]|=r[4];
goto P_0c03fd36;
P_0c03fd36: /* original 0e26, guest PC 0x0c03fd36 */
if(!s->budget--) { s->failed_pc=0x0c03fd36u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03fd38;
P_0c03fd38: /* original 6013, guest PC 0x0c03fd38 */
if(!s->budget--) { s->failed_pc=0x0c03fd38u; return 0; }
r[0]=r[1];
goto P_0c03fd3a;
P_0c03fd3a: /* original 0009, guest PC 0x0c03fd3a */
if(!s->budget--) { s->failed_pc=0x0c03fd3au; return 0; }
goto P_0c03fd3c;
P_0c03fd3c: /* original a023, guest PC 0x0c03fd3c */
if(!s->budget--) { s->failed_pc=0x0c03fd3cu; return 0; }
r[0]+=r[6];
goto P_0c03fd86;
P_0c03fd3e: /* original 306c, guest PC 0x0c03fd3e */
if(!s->budget--) { s->failed_pc=0x0c03fd3eu; return 0; }
r[0]+=r[6];
goto P_0c03fd40;
P_0c03fd40: /* original 4400, guest PC 0x0c03fd40 */
if(!s->budget--) { s->failed_pc=0x0c03fd40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03fd42;
P_0c03fd42: /* original aff2, guest PC 0x0c03fd42 */
if(!s->budget--) { s->failed_pc=0x0c03fd42u; return 0; }
r[6]+=0x00000001u;
goto P_0c03fd2a;
P_0c03fd44: /* original 7601, guest PC 0x0c03fd44 */
if(!s->budget--) { s->failed_pc=0x0c03fd44u; return 0; }
r[6]+=0x00000001u;
if(!vf3_matrix_family(0x0c03fd46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd46u; return 0; } return 1;
P_0c03fd70: /* original 7501, guest PC 0x0c03fd70 */
if(!s->budget--) { s->failed_pc=0x0c03fd70u; return 0; }
r[5]+=0x00000001u;
goto P_0c03fd72;
P_0c03fd72: /* original 6182, guest PC 0x0c03fd72 */
if(!s->budget--) { s->failed_pc=0x0c03fd72u; return 0; }
tmp=read(ram,r[8],4);
r[1]=tmp;
goto P_0c03fd74;
P_0c03fd74: /* original 711f, guest PC 0x0c03fd74 */
if(!s->budget--) { s->failed_pc=0x0c03fd74u; return 0; }
r[1]+=0x0000001fu;
goto P_0c03fd76;
P_0c03fd76: /* original 6093, guest PC 0x0c03fd76 */
if(!s->budget--) { s->failed_pc=0x0c03fd76u; return 0; }
r[0]=r[9];
goto P_0c03fd78;
P_0c03fd78: /* original 0009, guest PC 0x0c03fd78 */
if(!s->budget--) { s->failed_pc=0x0c03fd78u; return 0; }
goto P_0c03fd7a;
P_0c03fd7a: /* original d311, guest PC 0x0c03fd7a */
if(!s->budget--) { s->failed_pc=0x0c03fd7au; return 0; }
r[3]=read(ram,0x0c03fdc0u,4);
goto P_0c03fd7c;
P_0c03fd7c: /* original 430b, guest PC 0x0c03fd7c */
if(!s->budget--) { s->failed_pc=0x0c03fd7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c03fd80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03fd80u) { target=s->pc; goto dispatch; }
goto P_0c03fd80;
P_0c03fd7e: /* original 0009, guest PC 0x0c03fd7e */
if(!s->budget--) { s->failed_pc=0x0c03fd7eu; return 0; }
goto P_0c03fd80;
P_0c03fd80: /* original 3503, guest PC 0x0c03fd80 */
if(!s->budget--) { s->failed_pc=0x0c03fd80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[0])!=0);
goto P_0c03fd82;
P_0c03fd82: /* original 8bc5, guest PC 0x0c03fd82 */
if(!s->budget--) { s->failed_pc=0x0c03fd82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd10; }
goto P_0c03fd84;
P_0c03fd84: /* original e0ff, guest PC 0x0c03fd84 */
if(!s->budget--) { s->failed_pc=0x0c03fd84u; return 0; }
r[0]=0xffffffffu;
goto P_0c03fd86;
P_0c03fd86: /* original 4f26, guest PC 0x0c03fd86 */
if(!s->budget--) { s->failed_pc=0x0c03fd86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fd88;
P_0c03fd88: /* original 68f6, guest PC 0x0c03fd88 */
if(!s->budget--) { s->failed_pc=0x0c03fd88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03fd8a;
P_0c03fd8a: /* original 69f6, guest PC 0x0c03fd8a */
if(!s->budget--) { s->failed_pc=0x0c03fd8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03fd8c;
P_0c03fd8c: /* original 6af6, guest PC 0x0c03fd8c */
if(!s->budget--) { s->failed_pc=0x0c03fd8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03fd8e;
P_0c03fd8e: /* original 6bf6, guest PC 0x0c03fd8e */
if(!s->budget--) { s->failed_pc=0x0c03fd8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03fd90;
P_0c03fd90: /* original 6df6, guest PC 0x0c03fd90 */
if(!s->budget--) { s->failed_pc=0x0c03fd90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03fd92;
P_0c03fd92: /* original 000b, guest PC 0x0c03fd92 */
if(!s->budget--) { s->failed_pc=0x0c03fd92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fd94: /* original 6ef6, guest PC 0x0c03fd94 */
if(!s->budget--) { s->failed_pc=0x0c03fd94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fd96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd96u; return 0; } return 1;
P_0c03fda0: /* original e31f, guest PC 0x0c03fda0 */
if(!s->budget--) { s->failed_pc=0x0c03fda0u; return 0; }
r[3]=0x0000001fu;
goto P_0c03fda2;
P_0c03fda2: /* original d208, guest PC 0x0c03fda2 */
if(!s->budget--) { s->failed_pc=0x0c03fda2u; return 0; }
r[2]=read(ram,0x0c03fdc4u,4);
goto P_0c03fda4;
P_0c03fda4: /* original e501, guest PC 0x0c03fda4 */
if(!s->budget--) { s->failed_pc=0x0c03fda4u; return 0; }
r[5]=0x00000001u;
goto P_0c03fda6;
P_0c03fda6: /* original 2349, guest PC 0x0c03fda6 */
if(!s->budget--) { s->failed_pc=0x0c03fda6u; return 0; }
r[3]&=r[4];
goto P_0c03fda8;
P_0c03fda8: /* original 6022, guest PC 0x0c03fda8 */
if(!s->budget--) { s->failed_pc=0x0c03fda8u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c03fdaa;
P_0c03fdaa: /* original 453c, guest PC 0x0c03fdaa */
if(!s->budget--) { s->failed_pc=0x0c03fdaau; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c03fdac;
P_0c03fdac: /* original e3fb, guest PC 0x0c03fdac */
if(!s->budget--) { s->failed_pc=0x0c03fdacu; return 0; }
r[3]=0xfffffffbu;
goto P_0c03fdae;
P_0c03fdae: /* original 443c, guest PC 0x0c03fdae */
if(!s->budget--) { s->failed_pc=0x0c03fdaeu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c03fdb0;
P_0c03fdb0: /* original 6343, guest PC 0x0c03fdb0 */
if(!s->budget--) { s->failed_pc=0x0c03fdb0u; return 0; }
r[3]=r[4];
goto P_0c03fdb2;
P_0c03fdb2: /* original 4308, guest PC 0x0c03fdb2 */
if(!s->budget--) { s->failed_pc=0x0c03fdb2u; return 0; }
r[3]<<=2;
goto P_0c03fdb4;
P_0c03fdb4: /* original 013e, guest PC 0x0c03fdb4 */
if(!s->budget--) { s->failed_pc=0x0c03fdb4u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c03fdb6;
P_0c03fdb6: /* original 6557, guest PC 0x0c03fdb6 */
if(!s->budget--) { s->failed_pc=0x0c03fdb6u; return 0; }
r[5]=~r[5];
goto P_0c03fdb8;
P_0c03fdb8: /* original 2159, guest PC 0x0c03fdb8 */
if(!s->budget--) { s->failed_pc=0x0c03fdb8u; return 0; }
r[1]&=r[5];
goto P_0c03fdba;
P_0c03fdba: /* original 000b, guest PC 0x0c03fdba */
if(!s->budget--) { s->failed_pc=0x0c03fdbau; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[1],4);
s->pc=target; return ram->oob==0;
P_0c03fdbc: /* original 0316, guest PC 0x0c03fdbc */
if(!s->budget--) { s->failed_pc=0x0c03fdbcu; return 0; }
write(ram,r[3]+r[0],r[1],4);
if(!vf3_matrix_family(0x0c03fdbeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fdbeu; return 0; } return 1;
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
if(!vf3_matrix_family(0x0c040f68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040f68u; return 0; } return 1;
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c042cc0u,s,ram); }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
return vf3_matrix_family(0x0c042cc0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
