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
int vf3_away_batch25_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0400c0u: goto P_0c0400c0;
case 0x0c0400c2u: goto P_0c0400c2;
case 0x0c0400c4u: goto P_0c0400c4;
case 0x0c0400c6u: goto P_0c0400c6;
case 0x0c0400c8u: goto P_0c0400c8;
case 0x0c0400cau: goto P_0c0400ca;
case 0x0c0400ccu: goto P_0c0400cc;
case 0x0c0400ceu: goto P_0c0400ce;
case 0x0c0400d0u: goto P_0c0400d0;
case 0x0c0400d2u: goto P_0c0400d2;
case 0x0c0400d4u: goto P_0c0400d4;
case 0x0c0400d6u: goto P_0c0400d6;
case 0x0c0400d8u: goto P_0c0400d8;
case 0x0c0400dau: goto P_0c0400da;
case 0x0c0400dcu: goto P_0c0400dc;
case 0x0c0400deu: goto P_0c0400de;
case 0x0c0400e0u: goto P_0c0400e0;
case 0x0c0400e2u: goto P_0c0400e2;
case 0x0c0400e4u: goto P_0c0400e4;
case 0x0c0400e6u: goto P_0c0400e6;
case 0x0c0400e8u: goto P_0c0400e8;
case 0x0c0400eau: goto P_0c0400ea;
case 0x0c0400ecu: goto P_0c0400ec;
case 0x0c0400eeu: goto P_0c0400ee;
case 0x0c0400f0u: goto P_0c0400f0;
case 0x0c0400f2u: goto P_0c0400f2;
case 0x0c0400f4u: goto P_0c0400f4;
case 0x0c0400f6u: goto P_0c0400f6;
case 0x0c0400f8u: goto P_0c0400f8;
case 0x0c0400fau: goto P_0c0400fa;
case 0x0c0400fcu: goto P_0c0400fc;
case 0x0c0400feu: goto P_0c0400fe;
case 0x0c040100u: goto P_0c040100;
case 0x0c040102u: goto P_0c040102;
case 0x0c040104u: goto P_0c040104;
case 0x0c040106u: goto P_0c040106;
case 0x0c040108u: goto P_0c040108;
case 0x0c04010au: goto P_0c04010a;
case 0x0c04010cu: goto P_0c04010c;
case 0x0c04010eu: goto P_0c04010e;
case 0x0c040110u: goto P_0c040110;
case 0x0c040112u: goto P_0c040112;
case 0x0c040114u: goto P_0c040114;
case 0x0c040116u: goto P_0c040116;
case 0x0c04013cu: goto P_0c04013c;
case 0x0c04013eu: goto P_0c04013e;
case 0x0c040140u: goto P_0c040140;
case 0x0c040142u: goto P_0c040142;
case 0x0c040144u: goto P_0c040144;
case 0x0c040146u: goto P_0c040146;
case 0x0c040148u: goto P_0c040148;
case 0x0c04014au: goto P_0c04014a;
case 0x0c04014cu: goto P_0c04014c;
case 0x0c04014eu: goto P_0c04014e;
case 0x0c040154u: goto P_0c040154;
case 0x0c040156u: goto P_0c040156;
case 0x0c040158u: goto P_0c040158;
case 0x0c04015au: goto P_0c04015a;
case 0x0c04015cu: goto P_0c04015c;
case 0x0c04015eu: goto P_0c04015e;
case 0x0c040160u: goto P_0c040160;
case 0x0c040162u: goto P_0c040162;
case 0x0c040164u: goto P_0c040164;
case 0x0c040166u: goto P_0c040166;
case 0x0c040168u: goto P_0c040168;
case 0x0c04016au: goto P_0c04016a;
case 0x0c04016cu: goto P_0c04016c;
case 0x0c04016eu: goto P_0c04016e;
case 0x0c040174u: goto P_0c040174;
case 0x0c040176u: goto P_0c040176;
case 0x0c040178u: goto P_0c040178;
case 0x0c04017au: goto P_0c04017a;
case 0x0c04017cu: goto P_0c04017c;
case 0x0c04017eu: goto P_0c04017e;
case 0x0c040180u: goto P_0c040180;
case 0x0c040182u: goto P_0c040182;
case 0x0c040184u: goto P_0c040184;
case 0x0c040186u: goto P_0c040186;
case 0x0c040188u: goto P_0c040188;
case 0x0c04018au: goto P_0c04018a;
case 0x0c04018cu: goto P_0c04018c;
case 0x0c04018eu: goto P_0c04018e;
case 0x0c040190u: goto P_0c040190;
case 0x0c040192u: goto P_0c040192;
case 0x0c040194u: goto P_0c040194;
case 0x0c040196u: goto P_0c040196;
case 0x0c040198u: goto P_0c040198;
case 0x0c04019au: goto P_0c04019a;
case 0x0c04019cu: goto P_0c04019c;
case 0x0c04019eu: goto P_0c04019e;
case 0x0c0401a0u: goto P_0c0401a0;
case 0x0c0401a2u: goto P_0c0401a2;
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
P_0c0400c0: /* original 2fe6, guest PC 0x0c0400c0 */
if(!s->budget--) { s->failed_pc=0x0c0400c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0400c2;
P_0c0400c2: /* original 4f22, guest PC 0x0c0400c2 */
if(!s->budget--) { s->failed_pc=0x0c0400c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0400c4;
P_0c0400c4: /* original 7ff4, guest PC 0x0c0400c4 */
if(!s->budget--) { s->failed_pc=0x0c0400c4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0400c6;
P_0c0400c6: /* original 1f42, guest PC 0x0c0400c6 */
if(!s->budget--) { s->failed_pc=0x0c0400c6u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0400c8;
P_0c0400c8: /* original 1f51, guest PC 0x0c0400c8 */
if(!s->budget--) { s->failed_pc=0x0c0400c8u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0400ca;
P_0c0400ca: /* original 2f62, guest PC 0x0c0400ca */
if(!s->budget--) { s->failed_pc=0x0c0400cau; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0400cc;
P_0c0400cc: /* original d315, guest PC 0x0c0400cc */
if(!s->budget--) { s->failed_pc=0x0c0400ccu; return 0; }
r[3]=read(ram,0x0c040124u,4);
goto P_0c0400ce;
P_0c0400ce: /* original 52f2, guest PC 0x0c0400ce */
if(!s->budget--) { s->failed_pc=0x0c0400ceu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0400d0;
P_0c0400d0: /* original 323c, guest PC 0x0c0400d0 */
if(!s->budget--) { s->failed_pc=0x0c0400d0u; return 0; }
r[2]+=r[3];
goto P_0c0400d2;
P_0c0400d2: /* original d115, guest PC 0x0c0400d2 */
if(!s->budget--) { s->failed_pc=0x0c0400d2u; return 0; }
r[1]=read(ram,0x0c040128u,4);
goto P_0c0400d4;
P_0c0400d4: /* original 2122, guest PC 0x0c0400d4 */
if(!s->budget--) { s->failed_pc=0x0c0400d4u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0400d6;
P_0c0400d6: /* original 50f1, guest PC 0x0c0400d6 */
if(!s->budget--) { s->failed_pc=0x0c0400d6u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0400d8;
P_0c0400d8: /* original 330c, guest PC 0x0c0400d8 */
if(!s->budget--) { s->failed_pc=0x0c0400d8u; return 0; }
r[3]+=r[0];
goto P_0c0400da;
P_0c0400da: /* original d214, guest PC 0x0c0400da */
if(!s->budget--) { s->failed_pc=0x0c0400dau; return 0; }
r[2]=read(ram,0x0c04012cu,4);
goto P_0c0400dc;
P_0c0400dc: /* original 2232, guest PC 0x0c0400dc */
if(!s->budget--) { s->failed_pc=0x0c0400dcu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0400de;
P_0c0400de: /* original 60f2, guest PC 0x0c0400de */
if(!s->budget--) { s->failed_pc=0x0c0400deu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0400e0;
P_0c0400e0: /* original d313, guest PC 0x0c0400e0 */
if(!s->budget--) { s->failed_pc=0x0c0400e0u; return 0; }
r[3]=read(ram,0x0c040130u,4);
goto P_0c0400e2;
P_0c0400e2: /* original 2302, guest PC 0x0c0400e2 */
if(!s->budget--) { s->failed_pc=0x0c0400e2u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c0400e4;
P_0c0400e4: /* original ee00, guest PC 0x0c0400e4 */
if(!s->budget--) { s->failed_pc=0x0c0400e4u; return 0; }
r[14]=0x00000000u;
goto P_0c0400e6;
P_0c0400e6: /* original a008, guest PC 0x0c0400e6 */
if(!s->budget--) { s->failed_pc=0x0c0400e6u; return 0; }
goto P_0c0400fa;
P_0c0400e8: /* original 0009, guest PC 0x0c0400e8 */
if(!s->budget--) { s->failed_pc=0x0c0400e8u; return 0; }
goto P_0c0400ea;
P_0c0400ea: /* original d412, guest PC 0x0c0400ea */
if(!s->budget--) { s->failed_pc=0x0c0400eau; return 0; }
r[4]=read(ram,0x0c040134u,4);
goto P_0c0400ec;
P_0c0400ec: /* original b717, guest PC 0x0c0400ec */
if(!s->budget--) { s->failed_pc=0x0c0400ecu; return 0; }
target=code_base|0x0c040f1eu; r[16]=code_base|0x0c0400f0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0400f0u) { target=s->pc; goto dispatch; }
goto P_0c0400f0;
P_0c0400ee: /* original 0009, guest PC 0x0c0400ee */
if(!s->budget--) { s->failed_pc=0x0c0400eeu; return 0; }
goto P_0c0400f0;
P_0c0400f0: /* original 2008, guest PC 0x0c0400f0 */
if(!s->budget--) { s->failed_pc=0x0c0400f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0400f2;
P_0c0400f2: /* original 8b01, guest PC 0x0c0400f2 */
if(!s->budget--) { s->failed_pc=0x0c0400f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0400f8; }
goto P_0c0400f4;
P_0c0400f4: /* original a00a, guest PC 0x0c0400f4 */
if(!s->budget--) { s->failed_pc=0x0c0400f4u; return 0; }
goto P_0c04010c;
P_0c0400f6: /* original 0009, guest PC 0x0c0400f6 */
if(!s->budget--) { s->failed_pc=0x0c0400f6u; return 0; }
goto P_0c0400f8;
P_0c0400f8: /* original 7e01, guest PC 0x0c0400f8 */
if(!s->budget--) { s->failed_pc=0x0c0400f8u; return 0; }
r[14]+=0x00000001u;
goto P_0c0400fa;
P_0c0400fa: /* original d20f, guest PC 0x0c0400fa */
if(!s->budget--) { s->failed_pc=0x0c0400fau; return 0; }
r[2]=read(ram,0x0c040138u,4);
goto P_0c0400fc;
P_0c0400fc: /* original 3e23, guest PC 0x0c0400fc */
if(!s->budget--) { s->failed_pc=0x0c0400fcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c0400fe;
P_0c0400fe: /* original 8bf4, guest PC 0x0c0400fe */
if(!s->budget--) { s->failed_pc=0x0c0400feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0400ea; }
goto P_0c040100;
P_0c040100: /* original 900f, guest PC 0x0c040100 */
if(!s->budget--) { s->failed_pc=0x0c040100u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040122u,2);
goto P_0c040102;
P_0c040102: /* original 7f0c, guest PC 0x0c040102 */
if(!s->budget--) { s->failed_pc=0x0c040102u; return 0; }
r[15]+=0x0000000cu;
goto P_0c040104;
P_0c040104: /* original 4f26, guest PC 0x0c040104 */
if(!s->budget--) { s->failed_pc=0x0c040104u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040106;
P_0c040106: /* original 6ef6, guest PC 0x0c040106 */
if(!s->budget--) { s->failed_pc=0x0c040106u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c040108;
P_0c040108: /* original 000b, guest PC 0x0c040108 */
if(!s->budget--) { s->failed_pc=0x0c040108u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04010a: /* original 0009, guest PC 0x0c04010a */
if(!s->budget--) { s->failed_pc=0x0c04010au; return 0; }
goto P_0c04010c;
P_0c04010c: /* original e000, guest PC 0x0c04010c */
if(!s->budget--) { s->failed_pc=0x0c04010cu; return 0; }
r[0]=0x00000000u;
goto P_0c04010e;
P_0c04010e: /* original 7f0c, guest PC 0x0c04010e */
if(!s->budget--) { s->failed_pc=0x0c04010eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c040110;
P_0c040110: /* original 4f26, guest PC 0x0c040110 */
if(!s->budget--) { s->failed_pc=0x0c040110u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040112;
P_0c040112: /* original 6ef6, guest PC 0x0c040112 */
if(!s->budget--) { s->failed_pc=0x0c040112u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c040114;
P_0c040114: /* original 000b, guest PC 0x0c040114 */
if(!s->budget--) { s->failed_pc=0x0c040114u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040116: /* original 0009, guest PC 0x0c040116 */
if(!s->budget--) { s->failed_pc=0x0c040116u; return 0; }
if(!vf3_matrix_family(0x0c040118u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040118u; return 0; } return 1;
P_0c04013c: /* original d20c, guest PC 0x0c04013c */
if(!s->budget--) { s->failed_pc=0x0c04013cu; return 0; }
r[2]=read(ram,0x0c040170u,4);
goto P_0c04013e;
P_0c04013e: /* original 6322, guest PC 0x0c04013e */
if(!s->budget--) { s->failed_pc=0x0c04013eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c040140;
P_0c040140: /* original 2338, guest PC 0x0c040140 */
if(!s->budget--) { s->failed_pc=0x0c040140u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c040142;
P_0c040142: /* original 8902, guest PC 0x0c040142 */
if(!s->budget--) { s->failed_pc=0x0c040142u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04014a; }
goto P_0c040144;
P_0c040144: /* original e001, guest PC 0x0c040144 */
if(!s->budget--) { s->failed_pc=0x0c040144u; return 0; }
r[0]=0x00000001u;
goto P_0c040146;
P_0c040146: /* original 000b, guest PC 0x0c040146 */
if(!s->budget--) { s->failed_pc=0x0c040146u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040148: /* original 0009, guest PC 0x0c040148 */
if(!s->budget--) { s->failed_pc=0x0c040148u; return 0; }
goto P_0c04014a;
P_0c04014a: /* original e000, guest PC 0x0c04014a */
if(!s->budget--) { s->failed_pc=0x0c04014au; return 0; }
r[0]=0x00000000u;
goto P_0c04014c;
P_0c04014c: /* original 000b, guest PC 0x0c04014c */
if(!s->budget--) { s->failed_pc=0x0c04014cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04014e: /* original 0009, guest PC 0x0c04014e */
if(!s->budget--) { s->failed_pc=0x0c04014eu; return 0; }
if(!vf3_matrix_family(0x0c040150u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040150u; return 0; } return 1;
P_0c040154: /* original 7fe0, guest PC 0x0c040154 */
if(!s->budget--) { s->failed_pc=0x0c040154u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c040156;
P_0c040156: /* original 1f47, guest PC 0x0c040156 */
if(!s->budget--) { s->failed_pc=0x0c040156u; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c040158;
P_0c040158: /* original 1f56, guest PC 0x0c040158 */
if(!s->budget--) { s->failed_pc=0x0c040158u; return 0; }
write(ram,r[15]+24,r[5],4);
goto P_0c04015a;
P_0c04015a: /* original 53f6, guest PC 0x0c04015a */
if(!s->budget--) { s->failed_pc=0x0c04015au; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04015c;
P_0c04015c: /* original 4311, guest PC 0x0c04015c */
if(!s->budget--) { s->failed_pc=0x0c04015cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c04015e;
P_0c04015e: /* original 8b03, guest PC 0x0c04015e */
if(!s->budget--) { s->failed_pc=0x0c04015eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040168; }
goto P_0c040160;
P_0c040160: /* original e108, guest PC 0x0c040160 */
if(!s->budget--) { s->failed_pc=0x0c040160u; return 0; }
r[1]=0x00000008u;
goto P_0c040162;
P_0c040162: /* original 52f6, guest PC 0x0c040162 */
if(!s->budget--) { s->failed_pc=0x0c040162u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c040164;
P_0c040164: /* original 3213, guest PC 0x0c040164 */
if(!s->budget--) { s->failed_pc=0x0c040164u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c040166;
P_0c040166: /* original 8b05, guest PC 0x0c040166 */
if(!s->budget--) { s->failed_pc=0x0c040166u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040174; }
goto P_0c040168;
P_0c040168: /* original e0ff, guest PC 0x0c040168 */
if(!s->budget--) { s->failed_pc=0x0c040168u; return 0; }
r[0]=0xffffffffu;
goto P_0c04016a;
P_0c04016a: /* original 7f20, guest PC 0x0c04016a */
if(!s->budget--) { s->failed_pc=0x0c04016au; return 0; }
r[15]+=0x00000020u;
goto P_0c04016c;
P_0c04016c: /* original 000b, guest PC 0x0c04016c */
if(!s->budget--) { s->failed_pc=0x0c04016cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04016e: /* original 0009, guest PC 0x0c04016e */
if(!s->budget--) { s->failed_pc=0x0c04016eu; return 0; }
if(!vf3_matrix_family(0x0c040170u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040170u; return 0; } return 1;
P_0c040174: /* original 52f7, guest PC 0x0c040174 */
if(!s->budget--) { s->failed_pc=0x0c040174u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c040176;
P_0c040176: /* original 1f21, guest PC 0x0c040176 */
if(!s->budget--) { s->failed_pc=0x0c040176u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c040178;
P_0c040178: /* original d323, guest PC 0x0c040178 */
if(!s->budget--) { s->failed_pc=0x0c040178u; return 0; }
r[3]=read(ram,0x0c040208u,4);
goto P_0c04017a;
P_0c04017a: /* original 2f32, guest PC 0x0c04017a */
if(!s->budget--) { s->failed_pc=0x0c04017au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04017c;
P_0c04017c: /* original e200, guest PC 0x0c04017c */
if(!s->budget--) { s->failed_pc=0x0c04017cu; return 0; }
r[2]=0x00000000u;
goto P_0c04017e;
P_0c04017e: /* original 1f23, guest PC 0x0c04017e */
if(!s->budget--) { s->failed_pc=0x0c04017eu; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c040180;
P_0c040180: /* original a013, guest PC 0x0c040180 */
if(!s->budget--) { s->failed_pc=0x0c040180u; return 0; }
return vf3_matrix_family(0x0c0401aau,s,ram);
P_0c040182: /* original 0009, guest PC 0x0c040182 */
if(!s->budget--) { s->failed_pc=0x0c040182u; return 0; }
goto P_0c040184;
P_0c040184: /* original 51f1, guest PC 0x0c040184 */
if(!s->budget--) { s->failed_pc=0x0c040184u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c040186;
P_0c040186: /* original 7101, guest PC 0x0c040186 */
if(!s->budget--) { s->failed_pc=0x0c040186u; return 0; }
r[1]+=0x00000001u;
goto P_0c040188;
P_0c040188: /* original 1f11, guest PC 0x0c040188 */
if(!s->budget--) { s->failed_pc=0x0c040188u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c04018a;
P_0c04018a: /* original 71ff, guest PC 0x0c04018a */
if(!s->budget--) { s->failed_pc=0x0c04018au; return 0; }
r[1]+=0xffffffffu;
goto P_0c04018c;
P_0c04018c: /* original 6310, guest PC 0x0c04018c */
if(!s->budget--) { s->failed_pc=0x0c04018cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c04018e;
P_0c04018e: /* original 62f2, guest PC 0x0c04018e */
if(!s->budget--) { s->failed_pc=0x0c04018eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c040190;
P_0c040190: /* original 7201, guest PC 0x0c040190 */
if(!s->budget--) { s->failed_pc=0x0c040190u; return 0; }
r[2]+=0x00000001u;
goto P_0c040192;
P_0c040192: /* original 2f22, guest PC 0x0c040192 */
if(!s->budget--) { s->failed_pc=0x0c040192u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c040194;
P_0c040194: /* original 72ff, guest PC 0x0c040194 */
if(!s->budget--) { s->failed_pc=0x0c040194u; return 0; }
r[2]+=0xffffffffu;
goto P_0c040196;
P_0c040196: /* original 6120, guest PC 0x0c040196 */
if(!s->budget--) { s->failed_pc=0x0c040196u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c040198;
P_0c040198: /* original 3310, guest PC 0x0c040198 */
if(!s->budget--) { s->failed_pc=0x0c040198u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c04019a;
P_0c04019a: /* original 8903, guest PC 0x0c04019a */
if(!s->budget--) { s->failed_pc=0x0c04019au; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c0401a4u,s,ram); }
goto P_0c04019c;
P_0c04019c: /* original e0fe, guest PC 0x0c04019c */
if(!s->budget--) { s->failed_pc=0x0c04019cu; return 0; }
r[0]=0xfffffffeu;
goto P_0c04019e;
P_0c04019e: /* original 7f20, guest PC 0x0c04019e */
if(!s->budget--) { s->failed_pc=0x0c04019eu; return 0; }
r[15]+=0x00000020u;
goto P_0c0401a0;
P_0c0401a0: /* original 000b, guest PC 0x0c0401a0 */
if(!s->budget--) { s->failed_pc=0x0c0401a0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401a2: /* original 0009, guest PC 0x0c0401a2 */
if(!s->budget--) { s->failed_pc=0x0c0401a2u; return 0; }
return vf3_matrix_family(0x0c0401a4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
