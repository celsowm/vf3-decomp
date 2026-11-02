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
int vf3_away_batch104_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
case 0x0c03a750u: goto P_0c03a750;
case 0x0c03a752u: goto P_0c03a752;
case 0x0c03a754u: goto P_0c03a754;
case 0x0c03a756u: goto P_0c03a756;
case 0x0c0cc13au: goto P_0c0cc13a;
case 0x0c0cc13cu: goto P_0c0cc13c;
case 0x0c0cc13eu: goto P_0c0cc13e;
case 0x0c0cc140u: goto P_0c0cc140;
case 0x0c0cc142u: goto P_0c0cc142;
case 0x0c0cc144u: goto P_0c0cc144;
case 0x0c0cc146u: goto P_0c0cc146;
case 0x0c0cc148u: goto P_0c0cc148;
case 0x0c0cc14au: goto P_0c0cc14a;
case 0x0c0cc14cu: goto P_0c0cc14c;
case 0x0c0cc14eu: goto P_0c0cc14e;
case 0x0c0cc150u: goto P_0c0cc150;
case 0x0c0cc152u: goto P_0c0cc152;
case 0x0c0cc154u: goto P_0c0cc154;
case 0x0c0cc156u: goto P_0c0cc156;
case 0x0c0cc158u: goto P_0c0cc158;
case 0x0c0cc15au: goto P_0c0cc15a;
case 0x0c0cc15cu: goto P_0c0cc15c;
case 0x0c0cc15eu: goto P_0c0cc15e;
case 0x0c0cc160u: goto P_0c0cc160;
case 0x0c0cc162u: goto P_0c0cc162;
case 0x0c0cc164u: goto P_0c0cc164;
case 0x0c0cc166u: goto P_0c0cc166;
case 0x0c0cc168u: goto P_0c0cc168;
case 0x0c0cc16au: goto P_0c0cc16a;
case 0x0c0cc16cu: goto P_0c0cc16c;
case 0x0c0cc16eu: goto P_0c0cc16e;
case 0x0c0cc170u: goto P_0c0cc170;
case 0x0c0cc172u: goto P_0c0cc172;
case 0x0c0cc174u: goto P_0c0cc174;
case 0x0c0cc176u: goto P_0c0cc176;
case 0x0c0cc178u: goto P_0c0cc178;
case 0x0c0cc17au: goto P_0c0cc17a;
case 0x0c0cc17cu: goto P_0c0cc17c;
case 0x0c0cc17eu: goto P_0c0cc17e;
case 0x0c0cc180u: goto P_0c0cc180;
case 0x0c0cc182u: goto P_0c0cc182;
case 0x0c0cc184u: goto P_0c0cc184;
case 0x0c0cc186u: goto P_0c0cc186;
case 0x0c0cc188u: goto P_0c0cc188;
case 0x0c0cc18au: goto P_0c0cc18a;
case 0x0c0cc18cu: goto P_0c0cc18c;
case 0x0c0cc18eu: goto P_0c0cc18e;
case 0x0c0cc190u: goto P_0c0cc190;
case 0x0c0cc192u: goto P_0c0cc192;
case 0x0c0cc194u: goto P_0c0cc194;
case 0x0c0cc196u: goto P_0c0cc196;
case 0x0c0cc198u: goto P_0c0cc198;
case 0x0c0cc19au: goto P_0c0cc19a;
case 0x0c0cc19cu: goto P_0c0cc19c;
case 0x0c0cc19eu: goto P_0c0cc19e;
case 0x0c0cc1a0u: goto P_0c0cc1a0;
case 0x0c0cc1a2u: goto P_0c0cc1a2;
case 0x0c0cc1a4u: goto P_0c0cc1a4;
case 0x0c0cc1a6u: goto P_0c0cc1a6;
case 0x0c0cc1a8u: goto P_0c0cc1a8;
case 0x0c0cc1aau: goto P_0c0cc1aa;
case 0x0c0cc1acu: goto P_0c0cc1ac;
case 0x0c0cc1aeu: goto P_0c0cc1ae;
case 0x0c0cc1b0u: goto P_0c0cc1b0;
case 0x0c0cc1b2u: goto P_0c0cc1b2;
case 0x0c0cc1b4u: goto P_0c0cc1b4;
case 0x0c0cc1b6u: goto P_0c0cc1b6;
case 0x0c0cc1b8u: goto P_0c0cc1b8;
case 0x0c0cc1bau: goto P_0c0cc1ba;
case 0x0c0cc1bcu: goto P_0c0cc1bc;
case 0x0c0cc1beu: goto P_0c0cc1be;
case 0x0c0cc1c0u: goto P_0c0cc1c0;
case 0x0c0cc1c2u: goto P_0c0cc1c2;
case 0x0c0cc1c4u: goto P_0c0cc1c4;
case 0x0c0cc1c6u: goto P_0c0cc1c6;
case 0x0c0cc1c8u: goto P_0c0cc1c8;
case 0x0c0cc1cau: goto P_0c0cc1ca;
case 0x0c0cc1ccu: goto P_0c0cc1cc;
case 0x0c0cc1ceu: goto P_0c0cc1ce;
case 0x0c0cc1d0u: goto P_0c0cc1d0;
case 0x0c0cc1d2u: goto P_0c0cc1d2;
case 0x0c0cc1d4u: goto P_0c0cc1d4;
case 0x0c0cc1d6u: goto P_0c0cc1d6;
case 0x0c0cc1d8u: goto P_0c0cc1d8;
case 0x0c0cc1dau: goto P_0c0cc1da;
case 0x0c0cc1dcu: goto P_0c0cc1dc;
case 0x0c0cc1deu: goto P_0c0cc1de;
case 0x0c0cc1e0u: goto P_0c0cc1e0;
case 0x0c0cc1e2u: goto P_0c0cc1e2;
case 0x0c0cc1e4u: goto P_0c0cc1e4;
case 0x0c0cc1e6u: goto P_0c0cc1e6;
case 0x0c0cc1e8u: goto P_0c0cc1e8;
case 0x0c0cc1eau: goto P_0c0cc1ea;
case 0x0c0cc1ecu: goto P_0c0cc1ec;
case 0x0c0cc1eeu: goto P_0c0cc1ee;
case 0x0c0cc1f0u: goto P_0c0cc1f0;
case 0x0c0cc1f2u: goto P_0c0cc1f2;
case 0x0c0cc1f4u: goto P_0c0cc1f4;
case 0x0c0cc1f6u: goto P_0c0cc1f6;
case 0x0c0cc1f8u: goto P_0c0cc1f8;
case 0x0c0cc1fau: goto P_0c0cc1fa;
case 0x0c0cc1fcu: goto P_0c0cc1fc;
case 0x0c0cc1feu: goto P_0c0cc1fe;
case 0x0c0cc200u: goto P_0c0cc200;
case 0x0c0cc202u: goto P_0c0cc202;
case 0x0c0cc204u: goto P_0c0cc204;
case 0x0c0cc206u: goto P_0c0cc206;
case 0x0c0cc208u: goto P_0c0cc208;
case 0x0c0cc20au: goto P_0c0cc20a;
case 0x0c0cc20cu: goto P_0c0cc20c;
case 0x0c0cc20eu: goto P_0c0cc20e;
case 0x0c0cc210u: goto P_0c0cc210;
case 0x0c0cc212u: goto P_0c0cc212;
case 0x0c0cc214u: goto P_0c0cc214;
case 0x0c0cc216u: goto P_0c0cc216;
case 0x0c0cc218u: goto P_0c0cc218;
case 0x0c0cc21au: goto P_0c0cc21a;
case 0x0c0cc21cu: goto P_0c0cc21c;
case 0x0c0cc21eu: goto P_0c0cc21e;
case 0x0c0cc220u: goto P_0c0cc220;
case 0x0c0cc222u: goto P_0c0cc222;
case 0x0c0cc224u: goto P_0c0cc224;
case 0x0c0cc226u: goto P_0c0cc226;
case 0x0c0cc228u: goto P_0c0cc228;
case 0x0c0cc22au: goto P_0c0cc22a;
case 0x0c0cc22cu: goto P_0c0cc22c;
case 0x0c0cc22eu: goto P_0c0cc22e;
case 0x0c0cc230u: goto P_0c0cc230;
case 0x0c0cc232u: goto P_0c0cc232;
case 0x0c0cc234u: goto P_0c0cc234;
case 0x0c0cc236u: goto P_0c0cc236;
case 0x0c0cc238u: goto P_0c0cc238;
case 0x0c0cc23au: goto P_0c0cc23a;
case 0x0c0cc23cu: goto P_0c0cc23c;
case 0x0c0cc23eu: goto P_0c0cc23e;
case 0x0c0cc240u: goto P_0c0cc240;
case 0x0c0cc242u: goto P_0c0cc242;
case 0x0c0cc244u: goto P_0c0cc244;
case 0x0c0cc246u: goto P_0c0cc246;
case 0x0c0cc248u: goto P_0c0cc248;
case 0x0c0cc24au: goto P_0c0cc24a;
case 0x0c0cc24cu: goto P_0c0cc24c;
case 0x0c0cc24eu: goto P_0c0cc24e;
case 0x0c0cc250u: goto P_0c0cc250;
case 0x0c0cc252u: goto P_0c0cc252;
case 0x0c0cc254u: goto P_0c0cc254;
case 0x0c0cc256u: goto P_0c0cc256;
case 0x0c0cc258u: goto P_0c0cc258;
case 0x0c0cc25au: goto P_0c0cc25a;
case 0x0c0cc25cu: goto P_0c0cc25c;
case 0x0c0cc25eu: goto P_0c0cc25e;
case 0x0c0cc260u: goto P_0c0cc260;
case 0x0c0cc262u: goto P_0c0cc262;
case 0x0c0cc264u: goto P_0c0cc264;
case 0x0c0cc266u: goto P_0c0cc266;
case 0x0c0cc268u: goto P_0c0cc268;
case 0x0c0cc26au: goto P_0c0cc26a;
case 0x0c0cc26cu: goto P_0c0cc26c;
case 0x0c0cc26eu: goto P_0c0cc26e;
case 0x0c0cc270u: goto P_0c0cc270;
case 0x0c0cc272u: goto P_0c0cc272;
case 0x0c0cc274u: goto P_0c0cc274;
case 0x0c0cc276u: goto P_0c0cc276;
case 0x0c0cc278u: goto P_0c0cc278;
case 0x0c0cc27au: goto P_0c0cc27a;
case 0x0c0cc27cu: goto P_0c0cc27c;
case 0x0c0cc27eu: goto P_0c0cc27e;
case 0x0c0cc280u: goto P_0c0cc280;
case 0x0c0cc282u: goto P_0c0cc282;
case 0x0c0cc284u: goto P_0c0cc284;
case 0x0c0cc286u: goto P_0c0cc286;
case 0x0c0cc288u: goto P_0c0cc288;
case 0x0c0cc28au: goto P_0c0cc28a;
case 0x0c0cc28cu: goto P_0c0cc28c;
case 0x0c0cc28eu: goto P_0c0cc28e;
case 0x0c0cc290u: goto P_0c0cc290;
case 0x0c0cc292u: goto P_0c0cc292;
case 0x0c0cc294u: goto P_0c0cc294;
case 0x0c0cc296u: goto P_0c0cc296;
case 0x0c0cc298u: goto P_0c0cc298;
case 0x0c0cc29au: goto P_0c0cc29a;
case 0x0c0cc29cu: goto P_0c0cc29c;
case 0x0c0cc29eu: goto P_0c0cc29e;
case 0x0c0cc2a0u: goto P_0c0cc2a0;
case 0x0c0cc2a2u: goto P_0c0cc2a2;
case 0x0c0cc2a4u: goto P_0c0cc2a4;
case 0x0c0cc2a6u: goto P_0c0cc2a6;
case 0x0c0cc2a8u: goto P_0c0cc2a8;
case 0x0c0cc2aau: goto P_0c0cc2aa;
case 0x0c0cc2acu: goto P_0c0cc2ac;
case 0x0c0cc2aeu: goto P_0c0cc2ae;
case 0x0c0cc2b0u: goto P_0c0cc2b0;
case 0x0c0cc2b2u: goto P_0c0cc2b2;
case 0x0c0cc2b4u: goto P_0c0cc2b4;
case 0x0c0cc2b6u: goto P_0c0cc2b6;
case 0x0c0cc2b8u: goto P_0c0cc2b8;
case 0x0c0cc2bau: goto P_0c0cc2ba;
case 0x0c0cc2bcu: goto P_0c0cc2bc;
case 0x0c0cc2beu: goto P_0c0cc2be;
case 0x0c0cc2c0u: goto P_0c0cc2c0;
case 0x0c0cc2c2u: goto P_0c0cc2c2;
case 0x0c0cc2c4u: goto P_0c0cc2c4;
case 0x0c0cc2c6u: goto P_0c0cc2c6;
case 0x0c0cc2c8u: goto P_0c0cc2c8;
case 0x0c0cc2cau: goto P_0c0cc2ca;
case 0x0c0cc2ccu: goto P_0c0cc2cc;
case 0x0c0cc2ceu: goto P_0c0cc2ce;
case 0x0c0cc2d0u: goto P_0c0cc2d0;
case 0x0c0cc2d2u: goto P_0c0cc2d2;
case 0x0c0cc2d4u: goto P_0c0cc2d4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { goto P_0c03a750; }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
P_0c03a750: /* original f04c, guest PC 0x0c03a750 */
if(!s->budget--) { s->failed_pc=0x0c03a750u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a752;
P_0c03a752: /* original f04d, guest PC 0x0c03a752 */
if(!s->budget--) { s->failed_pc=0x0c03a752u; return 0; }
fr[0]^=0x80000000u;
goto P_0c03a754;
P_0c03a754: /* original 000b, guest PC 0x0c03a754 */
if(!s->budget--) { s->failed_pc=0x0c03a754u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a756: /* original 0009, guest PC 0x0c03a756 */
if(!s->budget--) { s->failed_pc=0x0c03a756u; return 0; }
if(!vf3_matrix_family(0x0c03a758u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a758u; return 0; } return 1;
P_0c0cc13a: /* original 2fe6, guest PC 0x0c0cc13a */
if(!s->budget--) { s->failed_pc=0x0c0cc13au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc13c;
P_0c0cc13c: /* original e004, guest PC 0x0c0cc13c */
if(!s->budget--) { s->failed_pc=0x0c0cc13cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cc13e;
P_0c0cc13e: /* original 2fd6, guest PC 0x0c0cc13e */
if(!s->budget--) { s->failed_pc=0x0c0cc13eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc140;
P_0c0cc140: /* original 6d43, guest PC 0x0c0cc140 */
if(!s->budget--) { s->failed_pc=0x0c0cc140u; return 0; }
r[13]=r[4];
goto P_0c0cc142;
P_0c0cc142: /* original 2fc6, guest PC 0x0c0cc142 */
if(!s->budget--) { s->failed_pc=0x0c0cc142u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc144;
P_0c0cc144: /* original 6e53, guest PC 0x0c0cc144 */
if(!s->budget--) { s->failed_pc=0x0c0cc144u; return 0; }
r[14]=r[5];
goto P_0c0cc146;
P_0c0cc146: /* original fffb, guest PC 0x0c0cc146 */
if(!s->budget--) { s->failed_pc=0x0c0cc146u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cc148;
P_0c0cc148: /* original 4f22, guest PC 0x0c0cc148 */
if(!s->budget--) { s->failed_pc=0x0c0cc148u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc14a;
P_0c0cc14a: /* original 7ff4, guest PC 0x0c0cc14a */
if(!s->budget--) { s->failed_pc=0x0c0cc14au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0cc14c;
P_0c0cc14c: /* original 2f62, guest PC 0x0c0cc14c */
if(!s->budget--) { s->failed_pc=0x0c0cc14cu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0cc14e;
P_0c0cc14e: /* original ff47, guest PC 0x0c0cc14e */
if(!s->budget--) { s->failed_pc=0x0c0cc14eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0cc150;
P_0c0cc150: /* original 5cf8, guest PC 0x0c0cc150 */
if(!s->budget--) { s->failed_pc=0x0c0cc150u; return 0; }
r[12]=read(ram,r[15]+32,4);
goto P_0c0cc152;
P_0c0cc152: /* original d385, guest PC 0x0c0cc152 */
if(!s->budget--) { s->failed_pc=0x0c0cc152u; return 0; }
r[3]=read(ram,0x0c0cc368u,4);
goto P_0c0cc154;
P_0c0cc154: /* original 64cf, guest PC 0x0c0cc154 */
if(!s->budget--) { s->failed_pc=0x0c0cc154u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0cc156;
P_0c0cc156: /* original 430b, guest PC 0x0c0cc156 */
if(!s->budget--) { s->failed_pc=0x0c0cc156u; return 0; }
target=r[3];
r[16]=code_base|0x0c0cc15au;
write(ram,r[15]+8,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc15au) { target=s->pc; goto dispatch; }
goto P_0c0cc15a;
P_0c0cc158: /* original 1f42, guest PC 0x0c0cc158 */
if(!s->budget--) { s->failed_pc=0x0c0cc158u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0cc15a;
P_0c0cc15a: /* original d384, guest PC 0x0c0cc15a */
if(!s->budget--) { s->failed_pc=0x0c0cc15au; return 0; }
r[3]=read(ram,0x0c0cc36cu,4);
goto P_0c0cc15c;
P_0c0cc15c: /* original ff0c, guest PC 0x0c0cc15c */
if(!s->budget--) { s->failed_pc=0x0c0cc15cu; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0cc15e;
P_0c0cc15e: /* original 430b, guest PC 0x0c0cc15e */
if(!s->budget--) { s->failed_pc=0x0c0cc15eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0cc162u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc162u) { target=s->pc; goto dispatch; }
goto P_0c0cc162;
P_0c0cc160: /* original 54f2, guest PC 0x0c0cc160 */
if(!s->budget--) { s->failed_pc=0x0c0cc160u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0cc162;
P_0c0cc162: /* original e018, guest PC 0x0c0cc162 */
if(!s->budget--) { s->failed_pc=0x0c0cc162u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc164;
P_0c0cc164: /* original f40c, guest PC 0x0c0cc164 */
if(!s->budget--) { s->failed_pc=0x0c0cc164u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cc166;
P_0c0cc166: /* original f5e6, guest PC 0x0c0cc166 */
if(!s->budget--) { s->failed_pc=0x0c0cc166u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0cc168;
P_0c0cc168: /* original e020, guest PC 0x0c0cc168 */
if(!s->budget--) { s->failed_pc=0x0c0cc168u; return 0; }
r[0]=0x00000020u;
goto P_0c0cc16a;
P_0c0cc16a: /* original f30c, guest PC 0x0c0cc16a */
if(!s->budget--) { s->failed_pc=0x0c0cc16au; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0cc16c;
P_0c0cc16c: /* original e40f, guest PC 0x0c0cc16c */
if(!s->budget--) { s->failed_pc=0x0c0cc16cu; return 0; }
r[4]=0x0000000fu;
goto P_0c0cc16e;
P_0c0cc16e: /* original f65c, guest PC 0x0c0cc16e */
if(!s->budget--) { s->failed_pc=0x0c0cc16eu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0cc170;
P_0c0cc170: /* original f642, guest PC 0x0c0cc170 */
if(!s->budget--) { s->failed_pc=0x0c0cc170u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0cc172;
P_0c0cc172: /* original f85c, guest PC 0x0c0cc172 */
if(!s->budget--) { s->failed_pc=0x0c0cc172u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0cc174;
P_0c0cc174: /* original f8f2, guest PC 0x0c0cc174 */
if(!s->budget--) { s->failed_pc=0x0c0cc174u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c0cc176;
P_0c0cc176: /* original f5e6, guest PC 0x0c0cc176 */
if(!s->budget--) { s->failed_pc=0x0c0cc176u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0cc178;
P_0c0cc178: /* original 24c9, guest PC 0x0c0cc178 */
if(!s->budget--) { s->failed_pc=0x0c0cc178u; return 0; }
r[4]&=r[12];
goto P_0c0cc17a;
P_0c0cc17a: /* original e018, guest PC 0x0c0cc17a */
if(!s->budget--) { s->failed_pc=0x0c0cc17au; return 0; }
r[0]=0x00000018u;
goto P_0c0cc17c;
P_0c0cc17c: /* original 6543, guest PC 0x0c0cc17c */
if(!s->budget--) { s->failed_pc=0x0c0cc17cu; return 0; }
r[5]=r[4];
goto P_0c0cc17e;
P_0c0cc17e: /* original f75c, guest PC 0x0c0cc17e */
if(!s->budget--) { s->failed_pc=0x0c0cc17eu; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c0cc180;
P_0c0cc180: /* original f7f2, guest PC 0x0c0cc180 */
if(!s->budget--) { s->failed_pc=0x0c0cc180u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'*');
goto P_0c0cc182;
P_0c0cc182: /* original f45c, guest PC 0x0c0cc182 */
if(!s->budget--) { s->failed_pc=0x0c0cc182u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0cc184;
P_0c0cc184: /* original f432, guest PC 0x0c0cc184 */
if(!s->budget--) { s->failed_pc=0x0c0cc184u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cc186;
P_0c0cc186: /* original 7512, guest PC 0x0c0cc186 */
if(!s->budget--) { s->failed_pc=0x0c0cc186u; return 0; }
r[5]+=0x00000012u;
goto P_0c0cc188;
P_0c0cc188: /* original f671, guest PC 0x0c0cc188 */
if(!s->budget--) { s->failed_pc=0x0c0cc188u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
goto P_0c0cc18a;
P_0c0cc18a: /* original f840, guest PC 0x0c0cc18a */
if(!s->budget--) { s->failed_pc=0x0c0cc18au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'+');
goto P_0c0cc18c;
P_0c0cc18c: /* original fe67, guest PC 0x0c0cc18c */
if(!s->budget--) { s->failed_pc=0x0c0cc18cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0cc18e;
P_0c0cc18e: /* original e020, guest PC 0x0c0cc18e */
if(!s->budget--) { s->failed_pc=0x0c0cc18eu; return 0; }
r[0]=0x00000020u;
goto P_0c0cc190;
P_0c0cc190: /* original fe87, guest PC 0x0c0cc190 */
if(!s->budget--) { s->failed_pc=0x0c0cc190u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c0cc192;
P_0c0cc192: /* original 6053, guest PC 0x0c0cc192 */
if(!s->budget--) { s->failed_pc=0x0c0cc192u; return 0; }
r[0]=r[5];
goto P_0c0cc194;
P_0c0cc194: /* original f49d, guest PC 0x0c0cc194 */
if(!s->budget--) { s->failed_pc=0x0c0cc194u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0cc196;
P_0c0cc196: /* original 81df, guest PC 0x0c0cc196 */
if(!s->budget--) { s->failed_pc=0x0c0cc196u; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c0cc198;
P_0c0cc198: /* original c775, guest PC 0x0c0cc198 */
if(!s->budget--) { s->failed_pc=0x0c0cc198u; return 0; }
r[0]=code_base|0x000cc370u;
goto P_0c0cc19a;
P_0c0cc19a: /* original 445a, guest PC 0x0c0cc19a */
if(!s->budget--) { s->failed_pc=0x0c0cc19au; return 0; }
r[53]=r[4];
goto P_0c0cc19c;
P_0c0cc19c: /* original f24c, guest PC 0x0c0cc19c */
if(!s->budget--) { s->failed_pc=0x0c0cc19cu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0cc19e;
P_0c0cc19e: /* original f32d, guest PC 0x0c0cc19e */
if(!s->budget--) { s->failed_pc=0x0c0cc19eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc1a0;
P_0c0cc1a0: /* original f53c, guest PC 0x0c0cc1a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a0u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cc1a2;
P_0c0cc1a2: /* original f008, guest PC 0x0c0cc1a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a2u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c0cc1a4;
P_0c0cc1a4: /* original e024, guest PC 0x0c0cc1a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a4u; return 0; }
r[0]=0x00000024u;
goto P_0c0cc1a6;
P_0c0cc1a6: /* original f3e6, guest PC 0x0c0cc1a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc1a8;
P_0c0cc1a8: /* original e018, guest PC 0x0c0cc1a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1a8u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc1aa;
P_0c0cc1aa: /* original f25e, guest PC 0x0c0cc1aa */
if(!s->budget--) { s->failed_pc=0x0c0cc1aau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c0cc1ac;
P_0c0cc1ac: /* original 63f2, guest PC 0x0c0cc1ac */
if(!s->budget--) { s->failed_pc=0x0c0cc1acu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0cc1ae;
P_0c0cc1ae: /* original 64cc, guest PC 0x0c0cc1ae */
if(!s->budget--) { s->failed_pc=0x0c0cc1aeu; return 0; }
r[4]=r[12]&255u;
goto P_0c0cc1b0;
P_0c0cc1b0: /* original f538, guest PC 0x0c0cc1b0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b0u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c0cc1b2;
P_0c0cc1b2: /* original f42c, guest PC 0x0c0cc1b2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b2u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0cc1b4;
P_0c0cc1b4: /* original f432, guest PC 0x0c0cc1b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cc1b6;
P_0c0cc1b6: /* original f3e6, guest PC 0x0c0cc1b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc1b8;
P_0c0cc1b8: /* original e008, guest PC 0x0c0cc1b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1b8u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc1ba;
P_0c0cc1ba: /* original f04c, guest PC 0x0c0cc1ba */
if(!s->budget--) { s->failed_pc=0x0c0cc1bau; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0cc1bc;
P_0c0cc1bc: /* original f53e, guest PC 0x0c0cc1bc */
if(!s->budget--) { s->failed_pc=0x0c0cc1bcu; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[3],fr[5],r[18]);
goto P_0c0cc1be;
P_0c0cc1be: /* original f336, guest PC 0x0c0cc1be */
if(!s->budget--) { s->failed_pc=0x0c0cc1beu; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0cc1c0;
P_0c0cc1c0: /* original e020, guest PC 0x0c0cc1c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c0u; return 0; }
r[0]=0x00000020u;
goto P_0c0cc1c2;
P_0c0cc1c2: /* original f2e6, guest PC 0x0c0cc1c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c2u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0cc1c4;
P_0c0cc1c4: /* original e004, guest PC 0x0c0cc1c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c4u; return 0; }
r[0]=0x00000004u;
goto P_0c0cc1c6;
P_0c0cc1c6: /* original f32e, guest PC 0x0c0cc1c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0cc1c8;
P_0c0cc1c8: /* original f43c, guest PC 0x0c0cc1c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1c8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cc1ca;
P_0c0cc1ca: /* original fd5a, guest PC 0x0c0cc1ca */
if(!s->budget--) { s->failed_pc=0x0c0cc1cau; return 0; }
vf3_matrix_store(s,ram,5,r[13]);
goto P_0c0cc1cc;
P_0c0cc1cc: /* original f3f6, guest PC 0x0c0cc1cc */
if(!s->budget--) { s->failed_pc=0x0c0cc1ccu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cc1ce;
P_0c0cc1ce: /* original e004, guest PC 0x0c0cc1ce */
if(!s->budget--) { s->failed_pc=0x0c0cc1ceu; return 0; }
r[0]=0x00000004u;
goto P_0c0cc1d0;
P_0c0cc1d0: /* original fd37, guest PC 0x0c0cc1d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d0u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0cc1d2;
P_0c0cc1d2: /* original e008, guest PC 0x0c0cc1d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d2u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc1d4;
P_0c0cc1d4: /* original f44d, guest PC 0x0c0cc1d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d4u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0cc1d6;
P_0c0cc1d6: /* original fd47, guest PC 0x0c0cc1d6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d6u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0cc1d8;
P_0c0cc1d8: /* original c766, guest PC 0x0c0cc1d8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1d8u; return 0; }
r[0]=code_base|0x000cc374u;
goto P_0c0cc1da;
P_0c0cc1da: /* original 445a, guest PC 0x0c0cc1da */
if(!s->budget--) { s->failed_pc=0x0c0cc1dau; return 0; }
r[53]=r[4];
goto P_0c0cc1dc;
P_0c0cc1dc: /* original f508, guest PC 0x0c0cc1dc */
if(!s->budget--) { s->failed_pc=0x0c0cc1dcu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0cc1de;
P_0c0cc1de: /* original f32d, guest PC 0x0c0cc1de */
if(!s->budget--) { s->failed_pc=0x0c0cc1deu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc1e0;
P_0c0cc1e0: /* original f43c, guest PC 0x0c0cc1e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e0u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cc1e2;
P_0c0cc1e2: /* original f35c, guest PC 0x0c0cc1e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cc1e4;
P_0c0cc1e4: /* original c764, guest PC 0x0c0cc1e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e4u; return 0; }
r[0]=code_base|0x000cc378u;
goto P_0c0cc1e6;
P_0c0cc1e6: /* original f54c, guest PC 0x0c0cc1e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e6u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cc1e8;
P_0c0cc1e8: /* original f532, guest PC 0x0c0cc1e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1e8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc1ea;
P_0c0cc1ea: /* original f408, guest PC 0x0c0cc1ea */
if(!s->budget--) { s->failed_pc=0x0c0cc1eau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0cc1ec;
P_0c0cc1ec: /* original e018, guest PC 0x0c0cc1ec */
if(!s->budget--) { s->failed_pc=0x0c0cc1ecu; return 0; }
r[0]=0x00000018u;
goto P_0c0cc1ee;
P_0c0cc1ee: /* original f3e6, guest PC 0x0c0cc1ee */
if(!s->budget--) { s->failed_pc=0x0c0cc1eeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc1f0;
P_0c0cc1f0: /* original e00c, guest PC 0x0c0cc1f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cc1f2;
P_0c0cc1f2: /* original 7f0c, guest PC 0x0c0cc1f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0cc1f4;
P_0c0cc1f4: /* original f450, guest PC 0x0c0cc1f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c0cc1f6;
P_0c0cc1f6: /* original 4f26, guest PC 0x0c0cc1f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc1f8;
P_0c0cc1f8: /* original f342, guest PC 0x0c0cc1f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc1f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0cc1fa;
P_0c0cc1fa: /* original fd37, guest PC 0x0c0cc1fa */
if(!s->budget--) { s->failed_pc=0x0c0cc1fau; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0cc1fc;
P_0c0cc1fc: /* original e01c, guest PC 0x0c0cc1fc */
if(!s->budget--) { s->failed_pc=0x0c0cc1fcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc1fe;
P_0c0cc1fe: /* original f3e6, guest PC 0x0c0cc1fe */
if(!s->budget--) { s->failed_pc=0x0c0cc1feu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc200;
P_0c0cc200: /* original e010, guest PC 0x0c0cc200 */
if(!s->budget--) { s->failed_pc=0x0c0cc200u; return 0; }
r[0]=0x00000010u;
goto P_0c0cc202;
P_0c0cc202: /* original f342, guest PC 0x0c0cc202 */
if(!s->budget--) { s->failed_pc=0x0c0cc202u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0cc204;
P_0c0cc204: /* original fd37, guest PC 0x0c0cc204 */
if(!s->budget--) { s->failed_pc=0x0c0cc204u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0cc206;
P_0c0cc206: /* original e020, guest PC 0x0c0cc206 */
if(!s->budget--) { s->failed_pc=0x0c0cc206u; return 0; }
r[0]=0x00000020u;
goto P_0c0cc208;
P_0c0cc208: /* original f3e6, guest PC 0x0c0cc208 */
if(!s->budget--) { s->failed_pc=0x0c0cc208u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cc20a;
P_0c0cc20a: /* original e014, guest PC 0x0c0cc20a */
if(!s->budget--) { s->failed_pc=0x0c0cc20au; return 0; }
r[0]=0x00000014u;
goto P_0c0cc20c;
P_0c0cc20c: /* original f342, guest PC 0x0c0cc20c */
if(!s->budget--) { s->failed_pc=0x0c0cc20cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0cc20e;
P_0c0cc20e: /* original fd37, guest PC 0x0c0cc20e */
if(!s->budget--) { s->failed_pc=0x0c0cc20eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0cc210;
P_0c0cc210: /* original fff9, guest PC 0x0c0cc210 */
if(!s->budget--) { s->failed_pc=0x0c0cc210u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cc212;
P_0c0cc212: /* original 6cf6, guest PC 0x0c0cc212 */
if(!s->budget--) { s->failed_pc=0x0c0cc212u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc214;
P_0c0cc214: /* original 6df6, guest PC 0x0c0cc214 */
if(!s->budget--) { s->failed_pc=0x0c0cc214u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc216;
P_0c0cc216: /* original 000b, guest PC 0x0c0cc216 */
if(!s->budget--) { s->failed_pc=0x0c0cc216u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc218: /* original 6ef6, guest PC 0x0c0cc218 */
if(!s->budget--) { s->failed_pc=0x0c0cc218u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cc21a;
P_0c0cc21a: /* original 2fe6, guest PC 0x0c0cc21a */
if(!s->budget--) { s->failed_pc=0x0c0cc21au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc21c;
P_0c0cc21c: /* original ee1f, guest PC 0x0c0cc21c */
if(!s->budget--) { s->failed_pc=0x0c0cc21cu; return 0; }
r[14]=0x0000001fu;
goto P_0c0cc21e;
P_0c0cc21e: /* original 7ffc, guest PC 0x0c0cc21e */
if(!s->budget--) { s->failed_pc=0x0c0cc21eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0cc220;
P_0c0cc220: /* original 5253, guest PC 0x0c0cc220 */
if(!s->budget--) { s->failed_pc=0x0c0cc220u; return 0; }
r[2]=read(ram,r[5]+12,4);
goto P_0c0cc222;
P_0c0cc222: /* original 56f2, guest PC 0x0c0cc222 */
if(!s->budget--) { s->failed_pc=0x0c0cc222u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0cc224;
P_0c0cc224: /* original c752, guest PC 0x0c0cc224 */
if(!s->budget--) { s->failed_pc=0x0c0cc224u; return 0; }
r[0]=code_base|0x000cc370u;
goto P_0c0cc226;
P_0c0cc226: /* original f508, guest PC 0x0c0cc226 */
if(!s->budget--) { s->failed_pc=0x0c0cc226u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0cc228;
P_0c0cc228: /* original e3fb, guest PC 0x0c0cc228 */
if(!s->budget--) { s->failed_pc=0x0c0cc228u; return 0; }
r[3]=0xfffffffbu;
goto P_0c0cc22a;
P_0c0cc22a: /* original 6163, guest PC 0x0c0cc22a */
if(!s->budget--) { s->failed_pc=0x0c0cc22au; return 0; }
r[1]=r[6];
goto P_0c0cc22c;
P_0c0cc22c: /* original 21e9, guest PC 0x0c0cc22c */
if(!s->budget--) { s->failed_pc=0x0c0cc22cu; return 0; }
r[1]&=r[14];
goto P_0c0cc22e;
P_0c0cc22e: /* original 71f0, guest PC 0x0c0cc22e */
if(!s->budget--) { s->failed_pc=0x0c0cc22eu; return 0; }
r[1]+=0xfffffff0u;
goto P_0c0cc230;
P_0c0cc230: /* original 6063, guest PC 0x0c0cc230 */
if(!s->budget--) { s->failed_pc=0x0c0cc230u; return 0; }
r[0]=r[6];
goto P_0c0cc232;
P_0c0cc232: /* original 415a, guest PC 0x0c0cc232 */
if(!s->budget--) { s->failed_pc=0x0c0cc232u; return 0; }
r[53]=r[1];
goto P_0c0cc234;
P_0c0cc234: /* original 2228, guest PC 0x0c0cc234 */
if(!s->budget--) { s->failed_pc=0x0c0cc234u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0cc236;
P_0c0cc236: /* original 403c, guest PC 0x0c0cc236 */
if(!s->budget--) { s->failed_pc=0x0c0cc236u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c0cc238;
P_0c0cc238: /* original e10f, guest PC 0x0c0cc238 */
if(!s->budget--) { s->failed_pc=0x0c0cc238u; return 0; }
r[1]=0x0000000fu;
goto P_0c0cc23a;
P_0c0cc23a: /* original f32d, guest PC 0x0c0cc23a */
if(!s->budget--) { s->failed_pc=0x0c0cc23au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc23c;
P_0c0cc23c: /* original f43c, guest PC 0x0c0cc23c */
if(!s->budget--) { s->failed_pc=0x0c0cc23cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cc23e;
P_0c0cc23e: /* original f452, guest PC 0x0c0cc23e */
if(!s->budget--) { s->failed_pc=0x0c0cc23eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0cc240;
P_0c0cc240: /* original 8f02, guest PC 0x0c0cc240 */
if(!s->budget--) { s->failed_pc=0x0c0cc240u; return 0; }
cond=r[17]&1u;
r[1]&=r[0];
if(!cond) { goto P_0c0cc248; }
goto P_0c0cc244;
P_0c0cc242: /* original 2109, guest PC 0x0c0cc242 */
if(!s->budget--) { s->failed_pc=0x0c0cc242u; return 0; }
r[1]&=r[0];
goto P_0c0cc244;
P_0c0cc244: /* original a001, guest PC 0x0c0cc244 */
if(!s->budget--) { s->failed_pc=0x0c0cc244u; return 0; }
r[0]=0x00000007u;
goto P_0c0cc24a;
P_0c0cc246: /* original e007, guest PC 0x0c0cc246 */
if(!s->budget--) { s->failed_pc=0x0c0cc246u; return 0; }
r[0]=0x00000007u;
goto P_0c0cc248;
P_0c0cc248: /* original e0f1, guest PC 0x0c0cc248 */
if(!s->budget--) { s->failed_pc=0x0c0cc248u; return 0; }
r[0]=0xfffffff1u;
goto P_0c0cc24a;
P_0c0cc24a: /* original 310c, guest PC 0x0c0cc24a */
if(!s->budget--) { s->failed_pc=0x0c0cc24au; return 0; }
r[1]+=r[0];
goto P_0c0cc24c;
P_0c0cc24c: /* original 415a, guest PC 0x0c0cc24c */
if(!s->budget--) { s->failed_pc=0x0c0cc24cu; return 0; }
r[53]=r[1];
goto P_0c0cc24e;
P_0c0cc24e: /* original 6163, guest PC 0x0c0cc24e */
if(!s->budget--) { s->failed_pc=0x0c0cc24eu; return 0; }
r[1]=r[6];
goto P_0c0cc250;
P_0c0cc250: /* original e3f6, guest PC 0x0c0cc250 */
if(!s->budget--) { s->failed_pc=0x0c0cc250u; return 0; }
r[3]=0xfffffff6u;
goto P_0c0cc252;
P_0c0cc252: /* original 413c, guest PC 0x0c0cc252 */
if(!s->budget--) { s->failed_pc=0x0c0cc252u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c0cc254;
P_0c0cc254: /* original f32d, guest PC 0x0c0cc254 */
if(!s->budget--) { s->failed_pc=0x0c0cc254u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc256;
P_0c0cc256: /* original 21e9, guest PC 0x0c0cc256 */
if(!s->budget--) { s->failed_pc=0x0c0cc256u; return 0; }
r[1]&=r[14];
goto P_0c0cc258;
P_0c0cc258: /* original 71f0, guest PC 0x0c0cc258 */
if(!s->budget--) { s->failed_pc=0x0c0cc258u; return 0; }
r[1]+=0xfffffff0u;
goto P_0c0cc25a;
P_0c0cc25a: /* original 415a, guest PC 0x0c0cc25a */
if(!s->budget--) { s->failed_pc=0x0c0cc25au; return 0; }
r[53]=r[1];
goto P_0c0cc25c;
P_0c0cc25c: /* original 636c, guest PC 0x0c0cc25c */
if(!s->budget--) { s->failed_pc=0x0c0cc25cu; return 0; }
r[3]=r[6]&255u;
goto P_0c0cc25e;
P_0c0cc25e: /* original c745, guest PC 0x0c0cc25e */
if(!s->budget--) { s->failed_pc=0x0c0cc25eu; return 0; }
r[0]=code_base|0x000cc374u;
goto P_0c0cc260;
P_0c0cc260: /* original f73c, guest PC 0x0c0cc260 */
if(!s->budget--) { s->failed_pc=0x0c0cc260u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c0cc262;
P_0c0cc262: /* original f32d, guest PC 0x0c0cc262 */
if(!s->budget--) { s->failed_pc=0x0c0cc262u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc264;
P_0c0cc264: /* original f752, guest PC 0x0c0cc264 */
if(!s->budget--) { s->failed_pc=0x0c0cc264u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0cc266;
P_0c0cc266: /* original f63c, guest PC 0x0c0cc266 */
if(!s->budget--) { s->failed_pc=0x0c0cc266u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0cc268;
P_0c0cc268: /* original f652, guest PC 0x0c0cc268 */
if(!s->budget--) { s->failed_pc=0x0c0cc268u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0cc26a;
P_0c0cc26a: /* original 2f32, guest PC 0x0c0cc26a */
if(!s->budget--) { s->failed_pc=0x0c0cc26au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cc26c;
P_0c0cc26c: /* original 435a, guest PC 0x0c0cc26c */
if(!s->budget--) { s->failed_pc=0x0c0cc26cu; return 0; }
r[53]=r[3];
goto P_0c0cc26e;
P_0c0cc26e: /* original f32d, guest PC 0x0c0cc26e */
if(!s->budget--) { s->failed_pc=0x0c0cc26eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc270;
P_0c0cc270: /* original f53c, guest PC 0x0c0cc270 */
if(!s->budget--) { s->failed_pc=0x0c0cc270u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cc272;
P_0c0cc272: /* original f308, guest PC 0x0c0cc272 */
if(!s->budget--) { s->failed_pc=0x0c0cc272u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cc274;
P_0c0cc274: /* original e018, guest PC 0x0c0cc274 */
if(!s->budget--) { s->failed_pc=0x0c0cc274u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc276;
P_0c0cc276: /* original f856, guest PC 0x0c0cc276 */
if(!s->budget--) { s->failed_pc=0x0c0cc276u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c0cc278;
P_0c0cc278: /* original e01c, guest PC 0x0c0cc278 */
if(!s->budget--) { s->failed_pc=0x0c0cc278u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc27a;
P_0c0cc27a: /* original f532, guest PC 0x0c0cc27a */
if(!s->budget--) { s->failed_pc=0x0c0cc27au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc27c;
P_0c0cc27c: /* original f956, guest PC 0x0c0cc27c */
if(!s->budget--) { s->failed_pc=0x0c0cc27cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]+r[0]);
goto P_0c0cc27e;
P_0c0cc27e: /* original e020, guest PC 0x0c0cc27e */
if(!s->budget--) { s->failed_pc=0x0c0cc27eu; return 0; }
r[0]=0x00000020u;
goto P_0c0cc280;
P_0c0cc280: /* original f25c, guest PC 0x0c0cc280 */
if(!s->budget--) { s->failed_pc=0x0c0cc280u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0cc282;
P_0c0cc282: /* original f952, guest PC 0x0c0cc282 */
if(!s->budget--) { s->failed_pc=0x0c0cc282u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[5],r[18],'*');
goto P_0c0cc284;
P_0c0cc284: /* original f852, guest PC 0x0c0cc284 */
if(!s->budget--) { s->failed_pc=0x0c0cc284u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c0cc286;
P_0c0cc286: /* original f556, guest PC 0x0c0cc286 */
if(!s->budget--) { s->failed_pc=0x0c0cc286u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0cc288;
P_0c0cc288: /* original f522, guest PC 0x0c0cc288 */
if(!s->budget--) { s->failed_pc=0x0c0cc288u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c0cc28a;
P_0c0cc28a: /* original e00c, guest PC 0x0c0cc28a */
if(!s->budget--) { s->failed_pc=0x0c0cc28au; return 0; }
r[0]=0x0000000cu;
goto P_0c0cc28c;
P_0c0cc28c: /* original f480, guest PC 0x0c0cc28c */
if(!s->budget--) { s->failed_pc=0x0c0cc28cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'+');
goto P_0c0cc28e;
P_0c0cc28e: /* original f487, guest PC 0x0c0cc28e */
if(!s->budget--) { s->failed_pc=0x0c0cc28eu; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0cc290;
P_0c0cc290: /* original e010, guest PC 0x0c0cc290 */
if(!s->budget--) { s->failed_pc=0x0c0cc290u; return 0; }
r[0]=0x00000010u;
goto P_0c0cc292;
P_0c0cc292: /* original f497, guest PC 0x0c0cc292 */
if(!s->budget--) { s->failed_pc=0x0c0cc292u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c0cc294;
P_0c0cc294: /* original e014, guest PC 0x0c0cc294 */
if(!s->budget--) { s->failed_pc=0x0c0cc294u; return 0; }
r[0]=0x00000014u;
goto P_0c0cc296;
P_0c0cc296: /* original f790, guest PC 0x0c0cc296 */
if(!s->budget--) { s->failed_pc=0x0c0cc296u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'+');
goto P_0c0cc298;
P_0c0cc298: /* original f457, guest PC 0x0c0cc298 */
if(!s->budget--) { s->failed_pc=0x0c0cc298u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0cc29a;
P_0c0cc29a: /* original f278, guest PC 0x0c0cc29a */
if(!s->budget--) { s->failed_pc=0x0c0cc29au; return 0; }
vf3_matrix_load(s,ram,2,r[7]);
goto P_0c0cc29c;
P_0c0cc29c: /* original e004, guest PC 0x0c0cc29c */
if(!s->budget--) { s->failed_pc=0x0c0cc29cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cc29e;
P_0c0cc29e: /* original f650, guest PC 0x0c0cc29e */
if(!s->budget--) { s->failed_pc=0x0c0cc29eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'+');
goto P_0c0cc2a0;
P_0c0cc2a0: /* original e3f8, guest PC 0x0c0cc2a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a0u; return 0; }
r[3]=0xfffffff8u;
goto P_0c0cc2a2;
P_0c0cc2a2: /* original f420, guest PC 0x0c0cc2a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c0cc2a4;
P_0c0cc2a4: /* original 463c, guest PC 0x0c0cc2a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a4u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c0cc2a6;
P_0c0cc2a6: /* original e201, guest PC 0x0c0cc2a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a6u; return 0; }
r[2]=0x00000001u;
goto P_0c0cc2a8;
P_0c0cc2a8: /* original 26e9, guest PC 0x0c0cc2a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a8u; return 0; }
r[6]&=r[14];
goto P_0c0cc2aa;
P_0c0cc2aa: /* original f44a, guest PC 0x0c0cc2aa */
if(!s->budget--) { s->failed_pc=0x0c0cc2aau; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c0cc2ac;
P_0c0cc2ac: /* original f276, guest PC 0x0c0cc2ac */
if(!s->budget--) { s->failed_pc=0x0c0cc2acu; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0cc2ae;
P_0c0cc2ae: /* original f720, guest PC 0x0c0cc2ae */
if(!s->budget--) { s->failed_pc=0x0c0cc2aeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'+');
goto P_0c0cc2b0;
P_0c0cc2b0: /* original f477, guest PC 0x0c0cc2b0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b0u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c0cc2b2;
P_0c0cc2b2: /* original e008, guest PC 0x0c0cc2b2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b2u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc2b4;
P_0c0cc2b4: /* original f276, guest PC 0x0c0cc2b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b4u; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0cc2b6;
P_0c0cc2b6: /* original f64d, guest PC 0x0c0cc2b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b6u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0cc2b8;
P_0c0cc2b8: /* original f621, guest PC 0x0c0cc2b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c0cc2ba;
P_0c0cc2ba: /* original f467, guest PC 0x0c0cc2ba */
if(!s->budget--) { s->failed_pc=0x0c0cc2bau; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0cc2bc;
P_0c0cc2bc: /* original 5353, guest PC 0x0c0cc2bc */
if(!s->budget--) { s->failed_pc=0x0c0cc2bcu; return 0; }
r[3]=read(ram,r[5]+12,4);
goto P_0c0cc2be;
P_0c0cc2be: /* original 3327, guest PC 0x0c0cc2be */
if(!s->budget--) { s->failed_pc=0x0c0cc2beu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c0cc2c0;
P_0c0cc2c0: /* original 8f04, guest PC 0x0c0cc2c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c0cc2cc; }
goto P_0c0cc2c4;
P_0c0cc2c2: /* original 7604, guest PC 0x0c0cc2c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0cc2c4;
P_0c0cc2c4: /* original e01c, guest PC 0x0c0cc2c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc2c6;
P_0c0cc2c6: /* original 3607, guest PC 0x0c0cc2c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[0])!=0);
goto P_0c0cc2c8;
P_0c0cc2c8: /* original 8b00, guest PC 0x0c0cc2c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc2cc; }
goto P_0c0cc2ca;
P_0c0cc2ca: /* original e61c, guest PC 0x0c0cc2ca */
if(!s->budget--) { s->failed_pc=0x0c0cc2cau; return 0; }
r[6]=0x0000001cu;
goto P_0c0cc2cc;
P_0c0cc2cc: /* original 6063, guest PC 0x0c0cc2cc */
if(!s->budget--) { s->failed_pc=0x0c0cc2ccu; return 0; }
r[0]=r[6];
goto P_0c0cc2ce;
P_0c0cc2ce: /* original 7f04, guest PC 0x0c0cc2ce */
if(!s->budget--) { s->failed_pc=0x0c0cc2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0cc2d0;
P_0c0cc2d0: /* original 814f, guest PC 0x0c0cc2d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d0u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c0cc2d2;
P_0c0cc2d2: /* original 000b, guest PC 0x0c0cc2d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc2d4: /* original 6ef6, guest PC 0x0c0cc2d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0cc2d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cc2d6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
