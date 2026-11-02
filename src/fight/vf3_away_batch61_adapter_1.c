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
int vf3_away_batch61_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08d158u: goto P_0c08d158;
case 0x0c08d15au: goto P_0c08d15a;
case 0x0c08d15cu: goto P_0c08d15c;
case 0x0c08d15eu: goto P_0c08d15e;
case 0x0c08d160u: goto P_0c08d160;
case 0x0c08d162u: goto P_0c08d162;
case 0x0c08d164u: goto P_0c08d164;
case 0x0c08d166u: goto P_0c08d166;
case 0x0c08d168u: goto P_0c08d168;
case 0x0c08d16au: goto P_0c08d16a;
case 0x0c08d16cu: goto P_0c08d16c;
case 0x0c08d16eu: goto P_0c08d16e;
case 0x0c08d170u: goto P_0c08d170;
case 0x0c08d172u: goto P_0c08d172;
case 0x0c08d174u: goto P_0c08d174;
case 0x0c08d176u: goto P_0c08d176;
case 0x0c08d178u: goto P_0c08d178;
case 0x0c08d17au: goto P_0c08d17a;
case 0x0c08d17cu: goto P_0c08d17c;
case 0x0c08d17eu: goto P_0c08d17e;
case 0x0c08d180u: goto P_0c08d180;
case 0x0c08d182u: goto P_0c08d182;
case 0x0c08d184u: goto P_0c08d184;
case 0x0c08d186u: goto P_0c08d186;
case 0x0c08d188u: goto P_0c08d188;
case 0x0c08d18au: goto P_0c08d18a;
case 0x0c08d18cu: goto P_0c08d18c;
case 0x0c08d18eu: goto P_0c08d18e;
case 0x0c08d190u: goto P_0c08d190;
case 0x0c08d240u: goto P_0c08d240;
case 0x0c08d242u: goto P_0c08d242;
case 0x0c08d244u: goto P_0c08d244;
case 0x0c08d246u: goto P_0c08d246;
case 0x0c08d248u: goto P_0c08d248;
case 0x0c08d24au: goto P_0c08d24a;
case 0x0c08d24cu: goto P_0c08d24c;
case 0x0c08d24eu: goto P_0c08d24e;
case 0x0c08d250u: goto P_0c08d250;
case 0x0c08d252u: goto P_0c08d252;
case 0x0c08d254u: goto P_0c08d254;
case 0x0c08d256u: goto P_0c08d256;
case 0x0c08d258u: goto P_0c08d258;
case 0x0c08d25au: goto P_0c08d25a;
case 0x0c08d25cu: goto P_0c08d25c;
case 0x0c08d25eu: goto P_0c08d25e;
case 0x0c08d260u: goto P_0c08d260;
case 0x0c08d262u: goto P_0c08d262;
case 0x0c08d264u: goto P_0c08d264;
case 0x0c08d266u: goto P_0c08d266;
case 0x0c08d268u: goto P_0c08d268;
case 0x0c08d26au: goto P_0c08d26a;
case 0x0c08d26cu: goto P_0c08d26c;
case 0x0c08d26eu: goto P_0c08d26e;
case 0x0c08d270u: goto P_0c08d270;
case 0x0c08d272u: goto P_0c08d272;
case 0x0c08d274u: goto P_0c08d274;
case 0x0c08d276u: goto P_0c08d276;
case 0x0c08d278u: goto P_0c08d278;
case 0x0c08d27au: goto P_0c08d27a;
case 0x0c08d27cu: goto P_0c08d27c;
case 0x0c08d27eu: goto P_0c08d27e;
case 0x0c08d280u: goto P_0c08d280;
case 0x0c08d282u: goto P_0c08d282;
case 0x0c08d284u: goto P_0c08d284;
case 0x0c08d286u: goto P_0c08d286;
case 0x0c08d288u: goto P_0c08d288;
case 0x0c08d28au: goto P_0c08d28a;
case 0x0c08d28cu: goto P_0c08d28c;
case 0x0c08d28eu: goto P_0c08d28e;
case 0x0c08d290u: goto P_0c08d290;
case 0x0c08d292u: goto P_0c08d292;
case 0x0c08d294u: goto P_0c08d294;
case 0x0c08d296u: goto P_0c08d296;
case 0x0c08d298u: goto P_0c08d298;
case 0x0c08d29au: goto P_0c08d29a;
case 0x0c08d29cu: goto P_0c08d29c;
case 0x0c08d29eu: goto P_0c08d29e;
case 0x0c08d2a0u: goto P_0c08d2a0;
case 0x0c08d2a2u: goto P_0c08d2a2;
case 0x0c08d2a4u: goto P_0c08d2a4;
case 0x0c08d2a6u: goto P_0c08d2a6;
case 0x0c08d2a8u: goto P_0c08d2a8;
case 0x0c08d2aau: goto P_0c08d2aa;
case 0x0c08d2acu: goto P_0c08d2ac;
case 0x0c08d2aeu: goto P_0c08d2ae;
case 0x0c08d2b0u: goto P_0c08d2b0;
case 0x0c08d2b2u: goto P_0c08d2b2;
case 0x0c08d2b4u: goto P_0c08d2b4;
case 0x0c08d2b6u: goto P_0c08d2b6;
case 0x0c08d2b8u: goto P_0c08d2b8;
case 0x0c08d2bau: goto P_0c08d2ba;
case 0x0c08d2bcu: goto P_0c08d2bc;
case 0x0c08d2beu: goto P_0c08d2be;
case 0x0c08d2c0u: goto P_0c08d2c0;
case 0x0c08d2c2u: goto P_0c08d2c2;
case 0x0c08d2c4u: goto P_0c08d2c4;
case 0x0c08d2c6u: goto P_0c08d2c6;
case 0x0c08d2c8u: goto P_0c08d2c8;
case 0x0c08d2cau: goto P_0c08d2ca;
case 0x0c08d2ccu: goto P_0c08d2cc;
case 0x0c08d2ceu: goto P_0c08d2ce;
case 0x0c08d3fcu: goto P_0c08d3fc;
case 0x0c08d3feu: goto P_0c08d3fe;
case 0x0c08d400u: goto P_0c08d400;
case 0x0c08d402u: goto P_0c08d402;
case 0x0c08d404u: goto P_0c08d404;
case 0x0c08d406u: goto P_0c08d406;
case 0x0c08d408u: goto P_0c08d408;
case 0x0c08d40au: goto P_0c08d40a;
case 0x0c08d40cu: goto P_0c08d40c;
case 0x0c08d40eu: goto P_0c08d40e;
case 0x0c08d410u: goto P_0c08d410;
case 0x0c08d412u: goto P_0c08d412;
case 0x0c08d414u: goto P_0c08d414;
case 0x0c08d416u: goto P_0c08d416;
case 0x0c08d418u: goto P_0c08d418;
case 0x0c08d41au: goto P_0c08d41a;
case 0x0c08d41cu: goto P_0c08d41c;
case 0x0c08d41eu: goto P_0c08d41e;
case 0x0c08d420u: goto P_0c08d420;
case 0x0c08d422u: goto P_0c08d422;
case 0x0c08d424u: goto P_0c08d424;
case 0x0c08d426u: goto P_0c08d426;
case 0x0c08d428u: goto P_0c08d428;
case 0x0c08d42au: goto P_0c08d42a;
case 0x0c08d42cu: goto P_0c08d42c;
case 0x0c08d42eu: goto P_0c08d42e;
case 0x0c08d430u: goto P_0c08d430;
case 0x0c08d432u: goto P_0c08d432;
case 0x0c08d434u: goto P_0c08d434;
case 0x0c08d436u: goto P_0c08d436;
case 0x0c08d438u: goto P_0c08d438;
case 0x0c08d43au: goto P_0c08d43a;
case 0x0c08d43cu: goto P_0c08d43c;
case 0x0c08d43eu: goto P_0c08d43e;
case 0x0c08d440u: goto P_0c08d440;
case 0x0c08d442u: goto P_0c08d442;
case 0x0c08d444u: goto P_0c08d444;
case 0x0c08d446u: goto P_0c08d446;
case 0x0c08d448u: goto P_0c08d448;
case 0x0c08d44au: goto P_0c08d44a;
case 0x0c08d460u: goto P_0c08d460;
case 0x0c08d462u: goto P_0c08d462;
case 0x0c08d464u: goto P_0c08d464;
case 0x0c08d466u: goto P_0c08d466;
case 0x0c08d468u: goto P_0c08d468;
case 0x0c08d46au: goto P_0c08d46a;
case 0x0c08d46cu: goto P_0c08d46c;
case 0x0c08d46eu: goto P_0c08d46e;
case 0x0c08d470u: goto P_0c08d470;
case 0x0c08d472u: goto P_0c08d472;
case 0x0c08d474u: goto P_0c08d474;
case 0x0c08d476u: goto P_0c08d476;
case 0x0c08d478u: goto P_0c08d478;
case 0x0c08d47au: goto P_0c08d47a;
case 0x0c08d47cu: goto P_0c08d47c;
case 0x0c08d47eu: goto P_0c08d47e;
case 0x0c08d480u: goto P_0c08d480;
case 0x0c08d482u: goto P_0c08d482;
case 0x0c08d484u: goto P_0c08d484;
case 0x0c08d486u: goto P_0c08d486;
case 0x0c08d488u: goto P_0c08d488;
case 0x0c08d48au: goto P_0c08d48a;
case 0x0c08d48cu: goto P_0c08d48c;
case 0x0c08d48eu: goto P_0c08d48e;
case 0x0c08d490u: goto P_0c08d490;
case 0x0c08d492u: goto P_0c08d492;
case 0x0c08d494u: goto P_0c08d494;
case 0x0c08d496u: goto P_0c08d496;
case 0x0c08d498u: goto P_0c08d498;
case 0x0c08d49au: goto P_0c08d49a;
case 0x0c08d49cu: goto P_0c08d49c;
case 0x0c08d49eu: goto P_0c08d49e;
case 0x0c08d4a0u: goto P_0c08d4a0;
case 0x0c08d4a2u: goto P_0c08d4a2;
case 0x0c08d4a4u: goto P_0c08d4a4;
case 0x0c08d4a6u: goto P_0c08d4a6;
case 0x0c08d4a8u: goto P_0c08d4a8;
case 0x0c08d4aau: goto P_0c08d4aa;
case 0x0c08d4acu: goto P_0c08d4ac;
case 0x0c08d4aeu: goto P_0c08d4ae;
case 0x0c08d4b0u: goto P_0c08d4b0;
case 0x0c08d4b2u: goto P_0c08d4b2;
case 0x0c08d4b4u: goto P_0c08d4b4;
case 0x0c08d4b6u: goto P_0c08d4b6;
case 0x0c08d4b8u: goto P_0c08d4b8;
case 0x0c08d4bau: goto P_0c08d4ba;
case 0x0c08d4bcu: goto P_0c08d4bc;
case 0x0c08d4beu: goto P_0c08d4be;
case 0x0c08d4c0u: goto P_0c08d4c0;
case 0x0c08d4c2u: goto P_0c08d4c2;
case 0x0c08d4c4u: goto P_0c08d4c4;
case 0x0c08d4c6u: goto P_0c08d4c6;
case 0x0c08d4c8u: goto P_0c08d4c8;
case 0x0c08d4cau: goto P_0c08d4ca;
case 0x0c08d4ccu: goto P_0c08d4cc;
case 0x0c08d4ceu: goto P_0c08d4ce;
case 0x0c08d4d0u: goto P_0c08d4d0;
case 0x0c08d4d2u: goto P_0c08d4d2;
case 0x0c08d4d4u: goto P_0c08d4d4;
case 0x0c08d4d6u: goto P_0c08d4d6;
case 0x0c08d4d8u: goto P_0c08d4d8;
case 0x0c08d4dau: goto P_0c08d4da;
case 0x0c08d4dcu: goto P_0c08d4dc;
case 0x0c08d4deu: goto P_0c08d4de;
case 0x0c08d4e0u: goto P_0c08d4e0;
case 0x0c08d4e2u: goto P_0c08d4e2;
case 0x0c08d4e4u: goto P_0c08d4e4;
case 0x0c08d4e6u: goto P_0c08d4e6;
case 0x0c08d4e8u: goto P_0c08d4e8;
case 0x0c08d4eau: goto P_0c08d4ea;
case 0x0c08d4ecu: goto P_0c08d4ec;
case 0x0c08d4eeu: goto P_0c08d4ee;
case 0x0c08d4f0u: goto P_0c08d4f0;
case 0x0c08d4f2u: goto P_0c08d4f2;
case 0x0c08d4f4u: goto P_0c08d4f4;
case 0x0c08d4f6u: goto P_0c08d4f6;
case 0x0c08d4f8u: goto P_0c08d4f8;
case 0x0c08d4fau: goto P_0c08d4fa;
case 0x0c08d4fcu: goto P_0c08d4fc;
case 0x0c08d4feu: goto P_0c08d4fe;
case 0x0c08d500u: goto P_0c08d500;
case 0x0c08d502u: goto P_0c08d502;
case 0x0c08d504u: goto P_0c08d504;
case 0x0c08d506u: goto P_0c08d506;
case 0x0c08d508u: goto P_0c08d508;
case 0x0c08d50au: goto P_0c08d50a;
case 0x0c08d50cu: goto P_0c08d50c;
case 0x0c08d50eu: goto P_0c08d50e;
case 0x0c08d510u: goto P_0c08d510;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08d158: /* original d335, guest PC 0x0c08d158 */
if(!s->budget--) { s->failed_pc=0x0c08d158u; return 0; }
r[3]=read(ram,0x0c08d230u,4);
goto P_0c08d15a;
P_0c08d15a: /* original 7ffc, guest PC 0x0c08d15a */
if(!s->budget--) { s->failed_pc=0x0c08d15au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08d15c;
P_0c08d15c: /* original 554d, guest PC 0x0c08d15c */
if(!s->budget--) { s->failed_pc=0x0c08d15cu; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c08d15e;
P_0c08d15e: /* original e040, guest PC 0x0c08d15e */
if(!s->budget--) { s->failed_pc=0x0c08d15eu; return 0; }
r[0]=0x00000040u;
goto P_0c08d160;
P_0c08d160: /* original d732, guest PC 0x0c08d160 */
if(!s->budget--) { s->failed_pc=0x0c08d160u; return 0; }
r[7]=read(ram,0x0c08d22cu,4);
goto P_0c08d162;
P_0c08d162: /* original 4508, guest PC 0x0c08d162 */
if(!s->budget--) { s->failed_pc=0x0c08d162u; return 0; }
r[5]<<=2;
goto P_0c08d164;
P_0c08d164: /* original 064e, guest PC 0x0c08d164 */
if(!s->budget--) { s->failed_pc=0x0c08d164u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c08d166;
P_0c08d166: /* original 2f32, guest PC 0x0c08d166 */
if(!s->budget--) { s->failed_pc=0x0c08d166u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08d168;
P_0c08d168: /* original 335c, guest PC 0x0c08d168 */
if(!s->budget--) { s->failed_pc=0x0c08d168u; return 0; }
r[3]+=r[5];
goto P_0c08d16a;
P_0c08d16a: /* original 375c, guest PC 0x0c08d16a */
if(!s->budget--) { s->failed_pc=0x0c08d16au; return 0; }
r[7]+=r[5];
goto P_0c08d16c;
P_0c08d16c: /* original 6232, guest PC 0x0c08d16c */
if(!s->budget--) { s->failed_pc=0x0c08d16cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c08d16e;
P_0c08d16e: /* original 6772, guest PC 0x0c08d16e */
if(!s->budget--) { s->failed_pc=0x0c08d16eu; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c08d170;
P_0c08d170: /* original e040, guest PC 0x0c08d170 */
if(!s->budget--) { s->failed_pc=0x0c08d170u; return 0; }
r[0]=0x00000040u;
goto P_0c08d172;
P_0c08d172: /* original 6323, guest PC 0x0c08d172 */
if(!s->budget--) { s->failed_pc=0x0c08d172u; return 0; }
r[3]=r[2];
goto P_0c08d174;
P_0c08d174: /* original 336c, guest PC 0x0c08d174 */
if(!s->budget--) { s->failed_pc=0x0c08d174u; return 0; }
r[3]+=r[6];
goto P_0c08d176;
P_0c08d176: /* original 376c, guest PC 0x0c08d176 */
if(!s->budget--) { s->failed_pc=0x0c08d176u; return 0; }
r[7]+=r[6];
goto P_0c08d178;
P_0c08d178: /* original 2f22, guest PC 0x0c08d178 */
if(!s->budget--) { s->failed_pc=0x0c08d178u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d17a;
P_0c08d17a: /* original 6230, guest PC 0x0c08d17a */
if(!s->budget--) { s->failed_pc=0x0c08d17au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c08d17c;
P_0c08d17c: /* original 6770, guest PC 0x0c08d17c */
if(!s->budget--) { s->failed_pc=0x0c08d17cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c08d17e;
P_0c08d17e: /* original 622c, guest PC 0x0c08d17e */
if(!s->budget--) { s->failed_pc=0x0c08d17eu; return 0; }
r[2]=r[2]&255u;
goto P_0c08d180;
P_0c08d180: /* original 677c, guest PC 0x0c08d180 */
if(!s->budget--) { s->failed_pc=0x0c08d180u; return 0; }
r[7]=r[7]&255u;
goto P_0c08d182;
P_0c08d182: /* original 2f22, guest PC 0x0c08d182 */
if(!s->budget--) { s->failed_pc=0x0c08d182u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d184;
P_0c08d184: /* original 145d, guest PC 0x0c08d184 */
if(!s->budget--) { s->failed_pc=0x0c08d184u; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c08d186;
P_0c08d186: /* original 0466, guest PC 0x0c08d186 */
if(!s->budget--) { s->failed_pc=0x0c08d186u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c08d188;
P_0c08d188: /* original 147e, guest PC 0x0c08d188 */
if(!s->budget--) { s->failed_pc=0x0c08d188u; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c08d18a;
P_0c08d18a: /* original 63f2, guest PC 0x0c08d18a */
if(!s->budget--) { s->failed_pc=0x0c08d18au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08d18c;
P_0c08d18c: /* original 143f, guest PC 0x0c08d18c */
if(!s->budget--) { s->failed_pc=0x0c08d18cu; return 0; }
write(ram,r[4]+60,r[3],4);
goto P_0c08d18e;
P_0c08d18e: /* original 000b, guest PC 0x0c08d18e */
if(!s->budget--) { s->failed_pc=0x0c08d18eu; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c08d190: /* original 7f04, guest PC 0x0c08d190 */
if(!s->budget--) { s->failed_pc=0x0c08d190u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c08d192u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d192u; return 0; } return 1;
P_0c08d240: /* original 2fe6, guest PC 0x0c08d240 */
if(!s->budget--) { s->failed_pc=0x0c08d240u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d242;
P_0c08d242: /* original 6e53, guest PC 0x0c08d242 */
if(!s->budget--) { s->failed_pc=0x0c08d242u; return 0; }
r[14]=r[5];
goto P_0c08d244;
P_0c08d244: /* original 2fd6, guest PC 0x0c08d244 */
if(!s->budget--) { s->failed_pc=0x0c08d244u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d246;
P_0c08d246: /* original e048, guest PC 0x0c08d246 */
if(!s->budget--) { s->failed_pc=0x0c08d246u; return 0; }
r[0]=0x00000048u;
goto P_0c08d248;
P_0c08d248: /* original 6d43, guest PC 0x0c08d248 */
if(!s->budget--) { s->failed_pc=0x0c08d248u; return 0; }
r[13]=r[4];
goto P_0c08d24a;
P_0c08d24a: /* original 2fc6, guest PC 0x0c08d24a */
if(!s->budget--) { s->failed_pc=0x0c08d24au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d24c;
P_0c08d24c: /* original 04ee, guest PC 0x0c08d24c */
if(!s->budget--) { s->failed_pc=0x0c08d24cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08d24e;
P_0c08d24e: /* original e061, guest PC 0x0c08d24e */
if(!s->budget--) { s->failed_pc=0x0c08d24eu; return 0; }
r[0]=0x00000061u;
goto P_0c08d250;
P_0c08d250: /* original 4f22, guest PC 0x0c08d250 */
if(!s->budget--) { s->failed_pc=0x0c08d250u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d252;
P_0c08d252: /* original 044c, guest PC 0x0c08d252 */
if(!s->budget--) { s->failed_pc=0x0c08d252u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08d254;
P_0c08d254: /* original 6043, guest PC 0x0c08d254 */
if(!s->budget--) { s->failed_pc=0x0c08d254u; return 0; }
r[0]=r[4];
goto P_0c08d256;
P_0c08d256: /* original 80e8, guest PC 0x0c08d256 */
if(!s->budget--) { s->failed_pc=0x0c08d256u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c08d258;
P_0c08d258: /* original e048, guest PC 0x0c08d258 */
if(!s->budget--) { s->failed_pc=0x0c08d258u; return 0; }
r[0]=0x00000048u;
goto P_0c08d25a;
P_0c08d25a: /* original 00dc, guest PC 0x0c08d25a */
if(!s->budget--) { s->failed_pc=0x0c08d25au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d25c;
P_0c08d25c: /* original 8801, guest PC 0x0c08d25c */
if(!s->budget--) { s->failed_pc=0x0c08d25cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d25e;
P_0c08d25e: /* original 8932, guest PC 0x0c08d25e */
if(!s->budget--) { s->failed_pc=0x0c08d25eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d2c6; }
goto P_0c08d260;
P_0c08d260: /* original 60e2, guest PC 0x0c08d260 */
if(!s->budget--) { s->failed_pc=0x0c08d260u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08d262;
P_0c08d262: /* original cb01, guest PC 0x0c08d262 */
if(!s->budget--) { s->failed_pc=0x0c08d262u; return 0; }
r[0]|=1u;
goto P_0c08d264;
P_0c08d264: /* original 2e02, guest PC 0x0c08d264 */
if(!s->budget--) { s->failed_pc=0x0c08d264u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08d266;
P_0c08d266: /* original d231, guest PC 0x0c08d266 */
if(!s->budget--) { s->failed_pc=0x0c08d266u; return 0; }
r[2]=read(ram,0x0c08d32cu,4);
goto P_0c08d268;
P_0c08d268: /* original 420b, guest PC 0x0c08d268 */
if(!s->budget--) { s->failed_pc=0x0c08d268u; return 0; }
target=r[2];
r[16]=code_base|0x0c08d26cu;
r[12]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d26cu) { target=s->pc; goto dispatch; }
goto P_0c08d26c;
P_0c08d26a: /* original ec03, guest PC 0x0c08d26a */
if(!s->budget--) { s->failed_pc=0x0c08d26au; return 0; }
r[12]=0x00000003u;
goto P_0c08d26c;
P_0c08d26c: /* original d330, guest PC 0x0c08d26c */
if(!s->budget--) { s->failed_pc=0x0c08d26cu; return 0; }
r[3]=read(ram,0x0c08d330u,4);
goto P_0c08d26e;
P_0c08d26e: /* original 6103, guest PC 0x0c08d26e */
if(!s->budget--) { s->failed_pc=0x0c08d26eu; return 0; }
r[1]=r[0];
goto P_0c08d270;
P_0c08d270: /* original 430b, guest PC 0x0c08d270 */
if(!s->budget--) { s->failed_pc=0x0c08d270u; return 0; }
target=r[3];
r[16]=code_base|0x0c08d274u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d274u) { target=s->pc; goto dispatch; }
goto P_0c08d274;
P_0c08d272: /* original 60c3, guest PC 0x0c08d272 */
if(!s->budget--) { s->failed_pc=0x0c08d272u; return 0; }
r[0]=r[12];
goto P_0c08d274;
P_0c08d274: /* original e34e, guest PC 0x0c08d274 */
if(!s->budget--) { s->failed_pc=0x0c08d274u; return 0; }
r[3]=0x0000004eu;
goto P_0c08d276;
P_0c08d276: /* original 6403, guest PC 0x0c08d276 */
if(!s->budget--) { s->failed_pc=0x0c08d276u; return 0; }
r[4]=r[0];
goto P_0c08d278;
P_0c08d278: /* original 33dc, guest PC 0x0c08d278 */
if(!s->budget--) { s->failed_pc=0x0c08d278u; return 0; }
r[3]+=r[13];
goto P_0c08d27a;
P_0c08d27a: /* original 84e8, guest PC 0x0c08d27a */
if(!s->budget--) { s->failed_pc=0x0c08d27au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08d27c;
P_0c08d27c: /* original 6330, guest PC 0x0c08d27c */
if(!s->budget--) { s->failed_pc=0x0c08d27cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c08d27e;
P_0c08d27e: /* original 600c, guest PC 0x0c08d27e */
if(!s->budget--) { s->failed_pc=0x0c08d27eu; return 0; }
r[0]=r[0]&255u;
goto P_0c08d280;
P_0c08d280: /* original 6233, guest PC 0x0c08d280 */
if(!s->budget--) { s->failed_pc=0x0c08d280u; return 0; }
r[2]=r[3];
goto P_0c08d282;
P_0c08d282: /* original 4208, guest PC 0x0c08d282 */
if(!s->budget--) { s->failed_pc=0x0c08d282u; return 0; }
r[2]<<=2;
goto P_0c08d284;
P_0c08d284: /* original 4008, guest PC 0x0c08d284 */
if(!s->budget--) { s->failed_pc=0x0c08d284u; return 0; }
r[0]<<=2;
goto P_0c08d286;
P_0c08d286: /* original 4008, guest PC 0x0c08d286 */
if(!s->budget--) { s->failed_pc=0x0c08d286u; return 0; }
r[0]<<=2;
goto P_0c08d288;
P_0c08d288: /* original 4000, guest PC 0x0c08d288 */
if(!s->budget--) { s->failed_pc=0x0c08d288u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c08d28a;
P_0c08d28a: /* original 4300, guest PC 0x0c08d28a */
if(!s->budget--) { s->failed_pc=0x0c08d28au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c08d28c;
P_0c08d28c: /* original 332c, guest PC 0x0c08d28c */
if(!s->budget--) { s->failed_pc=0x0c08d28cu; return 0; }
r[3]+=r[2];
goto P_0c08d28e;
P_0c08d28e: /* original d229, guest PC 0x0c08d28e */
if(!s->budget--) { s->failed_pc=0x0c08d28eu; return 0; }
r[2]=read(ram,0x0c08d334u,4);
goto P_0c08d290;
P_0c08d290: /* original 633e, guest PC 0x0c08d290 */
if(!s->budget--) { s->failed_pc=0x0c08d290u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c08d292;
P_0c08d292: /* original 302c, guest PC 0x0c08d292 */
if(!s->budget--) { s->failed_pc=0x0c08d292u; return 0; }
r[0]+=r[2];
goto P_0c08d294;
P_0c08d294: /* original 4400, guest PC 0x0c08d294 */
if(!s->budget--) { s->failed_pc=0x0c08d294u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08d296;
P_0c08d296: /* original 303c, guest PC 0x0c08d296 */
if(!s->budget--) { s->failed_pc=0x0c08d296u; return 0; }
r[0]+=r[3];
goto P_0c08d298;
P_0c08d298: /* original 044d, guest PC 0x0c08d298 */
if(!s->budget--) { s->failed_pc=0x0c08d298u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08d29a;
P_0c08d29a: /* original e028, guest PC 0x0c08d29a */
if(!s->budget--) { s->failed_pc=0x0c08d29au; return 0; }
r[0]=0x00000028u;
goto P_0c08d29c;
P_0c08d29c: /* original e300, guest PC 0x0c08d29c */
if(!s->budget--) { s->failed_pc=0x0c08d29cu; return 0; }
r[3]=0x00000000u;
goto P_0c08d29e;
P_0c08d29e: /* original 644d, guest PC 0x0c08d29e */
if(!s->budget--) { s->failed_pc=0x0c08d29eu; return 0; }
r[4]=r[4]&65535u;
goto P_0c08d2a0;
P_0c08d2a0: /* original 0d45, guest PC 0x0c08d2a0 */
if(!s->budget--) { s->failed_pc=0x0c08d2a0u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08d2a2;
P_0c08d2a2: /* original e040, guest PC 0x0c08d2a2 */
if(!s->budget--) { s->failed_pc=0x0c08d2a2u; return 0; }
r[0]=0x00000040u;
goto P_0c08d2a4;
P_0c08d2a4: /* original 1e4d, guest PC 0x0c08d2a4 */
if(!s->budget--) { s->failed_pc=0x0c08d2a4u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08d2a6;
P_0c08d2a6: /* original 0e36, guest PC 0x0c08d2a6 */
if(!s->budget--) { s->failed_pc=0x0c08d2a6u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c08d2a8;
P_0c08d2a8: /* original bf56, guest PC 0x0c08d2a8 */
if(!s->budget--) { s->failed_pc=0x0c08d2a8u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08d2acu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d2acu) { target=s->pc; goto dispatch; }
goto P_0c08d2ac;
P_0c08d2aa: /* original 64e3, guest PC 0x0c08d2aa */
if(!s->budget--) { s->failed_pc=0x0c08d2aau; return 0; }
r[4]=r[14];
goto P_0c08d2ac;
P_0c08d2ac: /* original e200, guest PC 0x0c08d2ac */
if(!s->budget--) { s->failed_pc=0x0c08d2acu; return 0; }
r[2]=0x00000000u;
goto P_0c08d2ae;
P_0c08d2ae: /* original 55ee, guest PC 0x0c08d2ae */
if(!s->budget--) { s->failed_pc=0x0c08d2aeu; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08d2b0;
P_0c08d2b0: /* original e02c, guest PC 0x0c08d2b0 */
if(!s->budget--) { s->failed_pc=0x0c08d2b0u; return 0; }
r[0]=0x0000002cu;
goto P_0c08d2b2;
P_0c08d2b2: /* original 54ef, guest PC 0x0c08d2b2 */
if(!s->budget--) { s->failed_pc=0x0c08d2b2u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08d2b4;
P_0c08d2b4: /* original 0d24, guest PC 0x0c08d2b4 */
if(!s->budget--) { s->failed_pc=0x0c08d2b4u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08d2b6;
P_0c08d2b6: /* original e02d, guest PC 0x0c08d2b6 */
if(!s->budget--) { s->failed_pc=0x0c08d2b6u; return 0; }
r[0]=0x0000002du;
goto P_0c08d2b8;
P_0c08d2b8: /* original 0d54, guest PC 0x0c08d2b8 */
if(!s->budget--) { s->failed_pc=0x0c08d2b8u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08d2ba;
P_0c08d2ba: /* original 6043, guest PC 0x0c08d2ba */
if(!s->budget--) { s->failed_pc=0x0c08d2bau; return 0; }
r[0]=r[4];
goto P_0c08d2bc;
P_0c08d2bc: /* original 81da, guest PC 0x0c08d2bc */
if(!s->budget--) { s->failed_pc=0x0c08d2bcu; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08d2be;
P_0c08d2be: /* original e048, guest PC 0x0c08d2be */
if(!s->budget--) { s->failed_pc=0x0c08d2beu; return 0; }
r[0]=0x00000048u;
goto P_0c08d2c0;
P_0c08d2c0: /* original 03dc, guest PC 0x0c08d2c0 */
if(!s->budget--) { s->failed_pc=0x0c08d2c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d2c2;
P_0c08d2c2: /* original 7301, guest PC 0x0c08d2c2 */
if(!s->budget--) { s->failed_pc=0x0c08d2c2u; return 0; }
r[3]+=0x00000001u;
goto P_0c08d2c4;
P_0c08d2c4: /* original 0d34, guest PC 0x0c08d2c4 */
if(!s->budget--) { s->failed_pc=0x0c08d2c4u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08d2c6;
P_0c08d2c6: /* original 4f26, guest PC 0x0c08d2c6 */
if(!s->budget--) { s->failed_pc=0x0c08d2c6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d2c8;
P_0c08d2c8: /* original 6cf6, guest PC 0x0c08d2c8 */
if(!s->budget--) { s->failed_pc=0x0c08d2c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08d2ca;
P_0c08d2ca: /* original 6df6, guest PC 0x0c08d2ca */
if(!s->budget--) { s->failed_pc=0x0c08d2cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d2cc;
P_0c08d2cc: /* original 000b, guest PC 0x0c08d2cc */
if(!s->budget--) { s->failed_pc=0x0c08d2ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d2ce: /* original 6ef6, guest PC 0x0c08d2ce */
if(!s->budget--) { s->failed_pc=0x0c08d2ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08d2d0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d2d0u; return 0; } return 1;
P_0c08d3fc: /* original 2fe6, guest PC 0x0c08d3fc */
if(!s->budget--) { s->failed_pc=0x0c08d3fcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d3fe;
P_0c08d3fe: /* original 6e43, guest PC 0x0c08d3fe */
if(!s->budget--) { s->failed_pc=0x0c08d3feu; return 0; }
r[14]=r[4];
goto P_0c08d400;
P_0c08d400: /* original e048, guest PC 0x0c08d400 */
if(!s->budget--) { s->failed_pc=0x0c08d400u; return 0; }
r[0]=0x00000048u;
goto P_0c08d402;
P_0c08d402: /* original 2fd6, guest PC 0x0c08d402 */
if(!s->budget--) { s->failed_pc=0x0c08d402u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d404;
P_0c08d404: /* original 00ec, guest PC 0x0c08d404 */
if(!s->budget--) { s->failed_pc=0x0c08d404u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08d406;
P_0c08d406: /* original 4f22, guest PC 0x0c08d406 */
if(!s->budget--) { s->failed_pc=0x0c08d406u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d408;
P_0c08d408: /* original 8801, guest PC 0x0c08d408 */
if(!s->budget--) { s->failed_pc=0x0c08d408u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d40a;
P_0c08d40a: /* original 8d1b, guest PC 0x0c08d40a */
if(!s->budget--) { s->failed_pc=0x0c08d40au; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08d444; }
goto P_0c08d40e;
P_0c08d40c: /* original 6d53, guest PC 0x0c08d40c */
if(!s->budget--) { s->failed_pc=0x0c08d40cu; return 0; }
r[13]=r[5];
goto P_0c08d40e;
P_0c08d40e: /* original 60d2, guest PC 0x0c08d40e */
if(!s->budget--) { s->failed_pc=0x0c08d40eu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08d410;
P_0c08d410: /* original cb01, guest PC 0x0c08d410 */
if(!s->budget--) { s->failed_pc=0x0c08d410u; return 0; }
r[0]|=1u;
goto P_0c08d412;
P_0c08d412: /* original 2d02, guest PC 0x0c08d412 */
if(!s->budget--) { s->failed_pc=0x0c08d412u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08d414;
P_0c08d414: /* original e028, guest PC 0x0c08d414 */
if(!s->budget--) { s->failed_pc=0x0c08d414u; return 0; }
r[0]=0x00000028u;
goto P_0c08d416;
P_0c08d416: /* original 921b, guest PC 0x0c08d416 */
if(!s->budget--) { s->failed_pc=0x0c08d416u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d450u,2);
goto P_0c08d418;
P_0c08d418: /* original 0e25, guest PC 0x0c08d418 */
if(!s->budget--) { s->failed_pc=0x0c08d418u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08d41a;
P_0c08d41a: /* original e200, guest PC 0x0c08d41a */
if(!s->budget--) { s->failed_pc=0x0c08d41au; return 0; }
r[2]=0x00000000u;
goto P_0c08d41c;
P_0c08d41c: /* original 03ed, guest PC 0x0c08d41c */
if(!s->budget--) { s->failed_pc=0x0c08d41cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08d41e;
P_0c08d41e: /* original e040, guest PC 0x0c08d41e */
if(!s->budget--) { s->failed_pc=0x0c08d41eu; return 0; }
r[0]=0x00000040u;
goto P_0c08d420;
P_0c08d420: /* original 633d, guest PC 0x0c08d420 */
if(!s->budget--) { s->failed_pc=0x0c08d420u; return 0; }
r[3]=r[3]&65535u;
goto P_0c08d422;
P_0c08d422: /* original 1d3d, guest PC 0x0c08d422 */
if(!s->budget--) { s->failed_pc=0x0c08d422u; return 0; }
write(ram,r[13]+52,r[3],4);
goto P_0c08d424;
P_0c08d424: /* original 0d26, guest PC 0x0c08d424 */
if(!s->budget--) { s->failed_pc=0x0c08d424u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c08d426;
P_0c08d426: /* original be97, guest PC 0x0c08d426 */
if(!s->budget--) { s->failed_pc=0x0c08d426u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08d42au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d42au) { target=s->pc; goto dispatch; }
goto P_0c08d42a;
P_0c08d428: /* original 64d3, guest PC 0x0c08d428 */
if(!s->budget--) { s->failed_pc=0x0c08d428u; return 0; }
r[4]=r[13];
goto P_0c08d42a;
P_0c08d42a: /* original e200, guest PC 0x0c08d42a */
if(!s->budget--) { s->failed_pc=0x0c08d42au; return 0; }
r[2]=0x00000000u;
goto P_0c08d42c;
P_0c08d42c: /* original 54de, guest PC 0x0c08d42c */
if(!s->budget--) { s->failed_pc=0x0c08d42cu; return 0; }
r[4]=read(ram,r[13]+56,4);
goto P_0c08d42e;
P_0c08d42e: /* original e02c, guest PC 0x0c08d42e */
if(!s->budget--) { s->failed_pc=0x0c08d42eu; return 0; }
r[0]=0x0000002cu;
goto P_0c08d430;
P_0c08d430: /* original 55df, guest PC 0x0c08d430 */
if(!s->budget--) { s->failed_pc=0x0c08d430u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c08d432;
P_0c08d432: /* original 0e24, guest PC 0x0c08d432 */
if(!s->budget--) { s->failed_pc=0x0c08d432u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08d434;
P_0c08d434: /* original e02d, guest PC 0x0c08d434 */
if(!s->budget--) { s->failed_pc=0x0c08d434u; return 0; }
r[0]=0x0000002du;
goto P_0c08d436;
P_0c08d436: /* original 0e44, guest PC 0x0c08d436 */
if(!s->budget--) { s->failed_pc=0x0c08d436u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08d438;
P_0c08d438: /* original 6053, guest PC 0x0c08d438 */
if(!s->budget--) { s->failed_pc=0x0c08d438u; return 0; }
r[0]=r[5];
goto P_0c08d43a;
P_0c08d43a: /* original 81ea, guest PC 0x0c08d43a */
if(!s->budget--) { s->failed_pc=0x0c08d43au; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08d43c;
P_0c08d43c: /* original e048, guest PC 0x0c08d43c */
if(!s->budget--) { s->failed_pc=0x0c08d43cu; return 0; }
r[0]=0x00000048u;
goto P_0c08d43e;
P_0c08d43e: /* original 03ec, guest PC 0x0c08d43e */
if(!s->budget--) { s->failed_pc=0x0c08d43eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08d440;
P_0c08d440: /* original 7301, guest PC 0x0c08d440 */
if(!s->budget--) { s->failed_pc=0x0c08d440u; return 0; }
r[3]+=0x00000001u;
goto P_0c08d442;
P_0c08d442: /* original 0e34, guest PC 0x0c08d442 */
if(!s->budget--) { s->failed_pc=0x0c08d442u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08d444;
P_0c08d444: /* original 4f26, guest PC 0x0c08d444 */
if(!s->budget--) { s->failed_pc=0x0c08d444u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d446;
P_0c08d446: /* original 6df6, guest PC 0x0c08d446 */
if(!s->budget--) { s->failed_pc=0x0c08d446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d448;
P_0c08d448: /* original 000b, guest PC 0x0c08d448 */
if(!s->budget--) { s->failed_pc=0x0c08d448u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d44a: /* original 6ef6, guest PC 0x0c08d44a */
if(!s->budget--) { s->failed_pc=0x0c08d44au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08d44cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d44cu; return 0; } return 1;
P_0c08d460: /* original 2fe6, guest PC 0x0c08d460 */
if(!s->budget--) { s->failed_pc=0x0c08d460u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d462;
P_0c08d462: /* original 6e43, guest PC 0x0c08d462 */
if(!s->budget--) { s->failed_pc=0x0c08d462u; return 0; }
r[14]=r[4];
goto P_0c08d464;
P_0c08d464: /* original 2fd6, guest PC 0x0c08d464 */
if(!s->budget--) { s->failed_pc=0x0c08d464u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d466;
P_0c08d466: /* original 6d53, guest PC 0x0c08d466 */
if(!s->budget--) { s->failed_pc=0x0c08d466u; return 0; }
r[13]=r[5];
goto P_0c08d468;
P_0c08d468: /* original 2fc6, guest PC 0x0c08d468 */
if(!s->budget--) { s->failed_pc=0x0c08d468u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d46a;
P_0c08d46a: /* original dc44, guest PC 0x0c08d46a */
if(!s->budget--) { s->failed_pc=0x0c08d46au; return 0; }
r[12]=read(ram,0x0c08d57cu,4);
goto P_0c08d46c;
P_0c08d46c: /* original 9083, guest PC 0x0c08d46c */
if(!s->budget--) { s->failed_pc=0x0c08d46cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d576u,2);
goto P_0c08d46e;
P_0c08d46e: /* original 4f22, guest PC 0x0c08d46e */
if(!s->budget--) { s->failed_pc=0x0c08d46eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d470;
P_0c08d470: /* original 04cc, guest PC 0x0c08d470 */
if(!s->budget--) { s->failed_pc=0x0c08d470u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08d472;
P_0c08d472: /* original d043, guest PC 0x0c08d472 */
if(!s->budget--) { s->failed_pc=0x0c08d472u; return 0; }
r[0]=read(ram,0x0c08d580u,4);
goto P_0c08d474;
P_0c08d474: /* original 4f12, guest PC 0x0c08d474 */
if(!s->budget--) { s->failed_pc=0x0c08d474u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c08d476;
P_0c08d476: /* original 044c, guest PC 0x0c08d476 */
if(!s->budget--) { s->failed_pc=0x0c08d476u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08d478;
P_0c08d478: /* original e026, guest PC 0x0c08d478 */
if(!s->budget--) { s->failed_pc=0x0c08d478u; return 0; }
r[0]=0x00000026u;
goto P_0c08d47a;
P_0c08d47a: /* original d342, guest PC 0x0c08d47a */
if(!s->budget--) { s->failed_pc=0x0c08d47au; return 0; }
r[3]=read(ram,0x0c08d584u,4);
goto P_0c08d47c;
P_0c08d47c: /* original 01ed, guest PC 0x0c08d47c */
if(!s->budget--) { s->failed_pc=0x0c08d47cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08d47e;
P_0c08d47e: /* original 430b, guest PC 0x0c08d47e */
if(!s->budget--) { s->failed_pc=0x0c08d47eu; return 0; }
target=r[3];
r[16]=code_base|0x0c08d482u;
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d482u) { target=s->pc; goto dispatch; }
goto P_0c08d482;
P_0c08d480: /* original 604e, guest PC 0x0c08d480 */
if(!s->budget--) { s->failed_pc=0x0c08d480u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08d482;
P_0c08d482: /* original 2008, guest PC 0x0c08d482 */
if(!s->budget--) { s->failed_pc=0x0c08d482u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c08d484;
P_0c08d484: /* original 8b3f, guest PC 0x0c08d484 */
if(!s->budget--) { s->failed_pc=0x0c08d484u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d506; }
goto P_0c08d486;
P_0c08d486: /* original e048, guest PC 0x0c08d486 */
if(!s->budget--) { s->failed_pc=0x0c08d486u; return 0; }
r[0]=0x00000048u;
goto P_0c08d488;
P_0c08d488: /* original 04de, guest PC 0x0c08d488 */
if(!s->budget--) { s->failed_pc=0x0c08d488u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c08d48a;
P_0c08d48a: /* original e061, guest PC 0x0c08d48a */
if(!s->budget--) { s->failed_pc=0x0c08d48au; return 0; }
r[0]=0x00000061u;
goto P_0c08d48c;
P_0c08d48c: /* original 044c, guest PC 0x0c08d48c */
if(!s->budget--) { s->failed_pc=0x0c08d48cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08d48e;
P_0c08d48e: /* original 6043, guest PC 0x0c08d48e */
if(!s->budget--) { s->failed_pc=0x0c08d48eu; return 0; }
r[0]=r[4];
goto P_0c08d490;
P_0c08d490: /* original 80d8, guest PC 0x0c08d490 */
if(!s->budget--) { s->failed_pc=0x0c08d490u; return 0; }
write(ram,r[13]+8,r[0],1);
goto P_0c08d492;
P_0c08d492: /* original e048, guest PC 0x0c08d492 */
if(!s->budget--) { s->failed_pc=0x0c08d492u; return 0; }
r[0]=0x00000048u;
goto P_0c08d494;
P_0c08d494: /* original 00ec, guest PC 0x0c08d494 */
if(!s->budget--) { s->failed_pc=0x0c08d494u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08d496;
P_0c08d496: /* original 8801, guest PC 0x0c08d496 */
if(!s->budget--) { s->failed_pc=0x0c08d496u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d498;
P_0c08d498: /* original 8d35, guest PC 0x0c08d498 */
if(!s->budget--) { s->failed_pc=0x0c08d498u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c08d506; }
goto P_0c08d49c;
P_0c08d49a: /* original 6503, guest PC 0x0c08d49a */
if(!s->budget--) { s->failed_pc=0x0c08d49au; return 0; }
r[5]=r[0];
goto P_0c08d49c;
P_0c08d49c: /* original 60d2, guest PC 0x0c08d49c */
if(!s->budget--) { s->failed_pc=0x0c08d49cu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08d49e;
P_0c08d49e: /* original e31a, guest PC 0x0c08d49e */
if(!s->budget--) { s->failed_pc=0x0c08d49eu; return 0; }
r[3]=0x0000001au;
goto P_0c08d4a0;
P_0c08d4a0: /* original 644c, guest PC 0x0c08d4a0 */
if(!s->budget--) { s->failed_pc=0x0c08d4a0u; return 0; }
r[4]=r[4]&255u;
goto P_0c08d4a2;
P_0c08d4a2: /* original cb01, guest PC 0x0c08d4a2 */
if(!s->budget--) { s->failed_pc=0x0c08d4a2u; return 0; }
r[0]|=1u;
goto P_0c08d4a4;
P_0c08d4a4: /* original 2d02, guest PC 0x0c08d4a4 */
if(!s->budget--) { s->failed_pc=0x0c08d4a4u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08d4a6;
P_0c08d4a6: /* original 4400, guest PC 0x0c08d4a6 */
if(!s->budget--) { s->failed_pc=0x0c08d4a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08d4a8;
P_0c08d4a8: /* original 9066, guest PC 0x0c08d4a8 */
if(!s->budget--) { s->failed_pc=0x0c08d4a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d578u,2);
goto P_0c08d4aa;
P_0c08d4aa: /* original d237, guest PC 0x0c08d4aa */
if(!s->budget--) { s->failed_pc=0x0c08d4aau; return 0; }
r[2]=read(ram,0x0c08d588u,4);
goto P_0c08d4ac;
P_0c08d4ac: /* original 00cc, guest PC 0x0c08d4ac */
if(!s->budget--) { s->failed_pc=0x0c08d4acu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08d4ae;
P_0c08d4ae: /* original 70ff, guest PC 0x0c08d4ae */
if(!s->budget--) { s->failed_pc=0x0c08d4aeu; return 0; }
r[0]+=0xffffffffu;
goto P_0c08d4b0;
P_0c08d4b0: /* original 203f, guest PC 0x0c08d4b0 */
if(!s->budget--) { s->failed_pc=0x0c08d4b0u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[3]);
goto P_0c08d4b2;
P_0c08d4b2: /* original 001a, guest PC 0x0c08d4b2 */
if(!s->budget--) { s->failed_pc=0x0c08d4b2u; return 0; }
r[0]=r[19];
goto P_0c08d4b4;
P_0c08d4b4: /* original 600f, guest PC 0x0c08d4b4 */
if(!s->budget--) { s->failed_pc=0x0c08d4b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c08d4b6;
P_0c08d4b6: /* original 320c, guest PC 0x0c08d4b6 */
if(!s->budget--) { s->failed_pc=0x0c08d4b6u; return 0; }
r[2]+=r[0];
goto P_0c08d4b8;
P_0c08d4b8: /* original 342c, guest PC 0x0c08d4b8 */
if(!s->budget--) { s->failed_pc=0x0c08d4b8u; return 0; }
r[4]+=r[2];
goto P_0c08d4ba;
P_0c08d4ba: /* original e028, guest PC 0x0c08d4ba */
if(!s->budget--) { s->failed_pc=0x0c08d4bau; return 0; }
r[0]=0x00000028u;
goto P_0c08d4bc;
P_0c08d4bc: /* original 6141, guest PC 0x0c08d4bc */
if(!s->budget--) { s->failed_pc=0x0c08d4bcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[1]=tmp;
goto P_0c08d4be;
P_0c08d4be: /* original 0e15, guest PC 0x0c08d4be */
if(!s->budget--) { s->failed_pc=0x0c08d4beu; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c08d4c0;
P_0c08d4c0: /* original e100, guest PC 0x0c08d4c0 */
if(!s->budget--) { s->failed_pc=0x0c08d4c0u; return 0; }
r[1]=0x00000000u;
goto P_0c08d4c2;
P_0c08d4c2: /* original 02ed, guest PC 0x0c08d4c2 */
if(!s->budget--) { s->failed_pc=0x0c08d4c2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08d4c4;
P_0c08d4c4: /* original e040, guest PC 0x0c08d4c4 */
if(!s->budget--) { s->failed_pc=0x0c08d4c4u; return 0; }
r[0]=0x00000040u;
goto P_0c08d4c6;
P_0c08d4c6: /* original 622d, guest PC 0x0c08d4c6 */
if(!s->budget--) { s->failed_pc=0x0c08d4c6u; return 0; }
r[2]=r[2]&65535u;
goto P_0c08d4c8;
P_0c08d4c8: /* original 1d2d, guest PC 0x0c08d4c8 */
if(!s->budget--) { s->failed_pc=0x0c08d4c8u; return 0; }
write(ram,r[13]+52,r[2],4);
goto P_0c08d4ca;
P_0c08d4ca: /* original 0d16, guest PC 0x0c08d4ca */
if(!s->budget--) { s->failed_pc=0x0c08d4cau; return 0; }
write(ram,r[13]+r[0],r[1],4);
goto P_0c08d4cc;
P_0c08d4cc: /* original be44, guest PC 0x0c08d4cc */
if(!s->budget--) { s->failed_pc=0x0c08d4ccu; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08d4d0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d4d0u) { target=s->pc; goto dispatch; }
goto P_0c08d4d0;
P_0c08d4ce: /* original 64d3, guest PC 0x0c08d4ce */
if(!s->budget--) { s->failed_pc=0x0c08d4ceu; return 0; }
r[4]=r[13];
goto P_0c08d4d0;
P_0c08d4d0: /* original e300, guest PC 0x0c08d4d0 */
if(!s->budget--) { s->failed_pc=0x0c08d4d0u; return 0; }
r[3]=0x00000000u;
goto P_0c08d4d2;
P_0c08d4d2: /* original 55de, guest PC 0x0c08d4d2 */
if(!s->budget--) { s->failed_pc=0x0c08d4d2u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c08d4d4;
P_0c08d4d4: /* original e02c, guest PC 0x0c08d4d4 */
if(!s->budget--) { s->failed_pc=0x0c08d4d4u; return 0; }
r[0]=0x0000002cu;
goto P_0c08d4d6;
P_0c08d4d6: /* original 54df, guest PC 0x0c08d4d6 */
if(!s->budget--) { s->failed_pc=0x0c08d4d6u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c08d4d8;
P_0c08d4d8: /* original 0e34, guest PC 0x0c08d4d8 */
if(!s->budget--) { s->failed_pc=0x0c08d4d8u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08d4da;
P_0c08d4da: /* original e02d, guest PC 0x0c08d4da */
if(!s->budget--) { s->failed_pc=0x0c08d4dau; return 0; }
r[0]=0x0000002du;
goto P_0c08d4dc;
P_0c08d4dc: /* original 0e54, guest PC 0x0c08d4dc */
if(!s->budget--) { s->failed_pc=0x0c08d4dcu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08d4de;
P_0c08d4de: /* original 904b, guest PC 0x0c08d4de */
if(!s->budget--) { s->failed_pc=0x0c08d4deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d578u,2);
goto P_0c08d4e0;
P_0c08d4e0: /* original 00cc, guest PC 0x0c08d4e0 */
if(!s->budget--) { s->failed_pc=0x0c08d4e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08d4e2;
P_0c08d4e2: /* original 8801, guest PC 0x0c08d4e2 */
if(!s->budget--) { s->failed_pc=0x0c08d4e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d4e4;
P_0c08d4e4: /* original 8d06, guest PC 0x0c08d4e4 */
if(!s->budget--) { s->failed_pc=0x0c08d4e4u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c08d4f4; }
goto P_0c08d4e8;
P_0c08d4e6: /* original 6503, guest PC 0x0c08d4e6 */
if(!s->budget--) { s->failed_pc=0x0c08d4e6u; return 0; }
r[5]=r[0];
goto P_0c08d4e8;
P_0c08d4e8: /* original 6053, guest PC 0x0c08d4e8 */
if(!s->budget--) { s->failed_pc=0x0c08d4e8u; return 0; }
r[0]=r[5];
goto P_0c08d4ea;
P_0c08d4ea: /* original 8802, guest PC 0x0c08d4ea */
if(!s->budget--) { s->failed_pc=0x0c08d4eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08d4ec;
P_0c08d4ec: /* original 8902, guest PC 0x0c08d4ec */
if(!s->budget--) { s->failed_pc=0x0c08d4ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d4f4; }
goto P_0c08d4ee;
P_0c08d4ee: /* original 6053, guest PC 0x0c08d4ee */
if(!s->budget--) { s->failed_pc=0x0c08d4eeu; return 0; }
r[0]=r[5];
goto P_0c08d4f0;
P_0c08d4f0: /* original 8803, guest PC 0x0c08d4f0 */
if(!s->budget--) { s->failed_pc=0x0c08d4f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c08d4f2;
P_0c08d4f2: /* original 8b02, guest PC 0x0c08d4f2 */
if(!s->budget--) { s->failed_pc=0x0c08d4f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d4fa; }
goto P_0c08d4f4;
P_0c08d4f4: /* original 9041, guest PC 0x0c08d4f4 */
if(!s->budget--) { s->failed_pc=0x0c08d4f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d57au,2);
goto P_0c08d4f6;
P_0c08d4f6: /* original a001, guest PC 0x0c08d4f6 */
if(!s->budget--) { s->failed_pc=0x0c08d4f6u; return 0; }
goto P_0c08d4fc;
P_0c08d4f8: /* original 0009, guest PC 0x0c08d4f8 */
if(!s->budget--) { s->failed_pc=0x0c08d4f8u; return 0; }
goto P_0c08d4fa;
P_0c08d4fa: /* original 6043, guest PC 0x0c08d4fa */
if(!s->budget--) { s->failed_pc=0x0c08d4fau; return 0; }
r[0]=r[4];
goto P_0c08d4fc;
P_0c08d4fc: /* original 81ea, guest PC 0x0c08d4fc */
if(!s->budget--) { s->failed_pc=0x0c08d4fcu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08d4fe;
P_0c08d4fe: /* original e048, guest PC 0x0c08d4fe */
if(!s->budget--) { s->failed_pc=0x0c08d4feu; return 0; }
r[0]=0x00000048u;
goto P_0c08d500;
P_0c08d500: /* original 03ec, guest PC 0x0c08d500 */
if(!s->budget--) { s->failed_pc=0x0c08d500u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08d502;
P_0c08d502: /* original 7301, guest PC 0x0c08d502 */
if(!s->budget--) { s->failed_pc=0x0c08d502u; return 0; }
r[3]+=0x00000001u;
goto P_0c08d504;
P_0c08d504: /* original 0e34, guest PC 0x0c08d504 */
if(!s->budget--) { s->failed_pc=0x0c08d504u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08d506;
P_0c08d506: /* original 4f16, guest PC 0x0c08d506 */
if(!s->budget--) { s->failed_pc=0x0c08d506u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d508;
P_0c08d508: /* original 4f26, guest PC 0x0c08d508 */
if(!s->budget--) { s->failed_pc=0x0c08d508u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d50a;
P_0c08d50a: /* original 6cf6, guest PC 0x0c08d50a */
if(!s->budget--) { s->failed_pc=0x0c08d50au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08d50c;
P_0c08d50c: /* original 6df6, guest PC 0x0c08d50c */
if(!s->budget--) { s->failed_pc=0x0c08d50cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d50e;
P_0c08d50e: /* original 000b, guest PC 0x0c08d50e */
if(!s->budget--) { s->failed_pc=0x0c08d50eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d510: /* original 6ef6, guest PC 0x0c08d510 */
if(!s->budget--) { s->failed_pc=0x0c08d510u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08d512u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
