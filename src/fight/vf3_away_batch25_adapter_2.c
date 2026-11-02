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
int vf3_away_batch25_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c039540u: goto P_0c039540;
case 0x0c039542u: goto P_0c039542;
case 0x0c039544u: goto P_0c039544;
case 0x0c039546u: goto P_0c039546;
case 0x0c039548u: goto P_0c039548;
case 0x0c03954au: goto P_0c03954a;
case 0x0c03954cu: goto P_0c03954c;
case 0x0c03954eu: goto P_0c03954e;
case 0x0c039550u: goto P_0c039550;
case 0x0c039552u: goto P_0c039552;
case 0x0c039554u: goto P_0c039554;
case 0x0c039556u: goto P_0c039556;
case 0x0c039558u: goto P_0c039558;
case 0x0c03955au: goto P_0c03955a;
case 0x0c03955cu: goto P_0c03955c;
case 0x0c03955eu: goto P_0c03955e;
case 0x0c039560u: goto P_0c039560;
case 0x0c039562u: goto P_0c039562;
case 0x0c039564u: goto P_0c039564;
case 0x0c039566u: goto P_0c039566;
case 0x0c039568u: goto P_0c039568;
case 0x0c03956au: goto P_0c03956a;
case 0x0c03956cu: goto P_0c03956c;
case 0x0c03956eu: goto P_0c03956e;
case 0x0c039570u: goto P_0c039570;
case 0x0c039572u: goto P_0c039572;
case 0x0c039574u: goto P_0c039574;
case 0x0c039576u: goto P_0c039576;
case 0x0c039578u: goto P_0c039578;
case 0x0c03957au: goto P_0c03957a;
case 0x0c03957cu: goto P_0c03957c;
case 0x0c03957eu: goto P_0c03957e;
case 0x0c039580u: goto P_0c039580;
case 0x0c039582u: goto P_0c039582;
case 0x0c039584u: goto P_0c039584;
case 0x0c039586u: goto P_0c039586;
case 0x0c039588u: goto P_0c039588;
case 0x0c03958au: goto P_0c03958a;
case 0x0c03958cu: goto P_0c03958c;
case 0x0c03958eu: goto P_0c03958e;
case 0x0c039590u: goto P_0c039590;
case 0x0c0395e0u: goto P_0c0395e0;
case 0x0c0395e2u: goto P_0c0395e2;
case 0x0c0395e4u: goto P_0c0395e4;
case 0x0c0395e6u: goto P_0c0395e6;
case 0x0c0395e8u: goto P_0c0395e8;
case 0x0c0395eau: goto P_0c0395ea;
case 0x0c0395ecu: goto P_0c0395ec;
case 0x0c0395eeu: goto P_0c0395ee;
case 0x0c0395f0u: goto P_0c0395f0;
case 0x0c0395f2u: goto P_0c0395f2;
case 0x0c0395f4u: goto P_0c0395f4;
case 0x0c0395f6u: goto P_0c0395f6;
case 0x0c0395f8u: goto P_0c0395f8;
case 0x0c0395fau: goto P_0c0395fa;
case 0x0c0395fcu: goto P_0c0395fc;
case 0x0c0395feu: goto P_0c0395fe;
case 0x0c039600u: goto P_0c039600;
case 0x0c039602u: goto P_0c039602;
case 0x0c039604u: goto P_0c039604;
case 0x0c039606u: goto P_0c039606;
case 0x0c039608u: goto P_0c039608;
case 0x0c03960au: goto P_0c03960a;
case 0x0c03960cu: goto P_0c03960c;
case 0x0c03960eu: goto P_0c03960e;
case 0x0c039610u: goto P_0c039610;
case 0x0c039612u: goto P_0c039612;
case 0x0c039614u: goto P_0c039614;
case 0x0c039616u: goto P_0c039616;
case 0x0c039618u: goto P_0c039618;
case 0x0c03961au: goto P_0c03961a;
case 0x0c03961cu: goto P_0c03961c;
case 0x0c03961eu: goto P_0c03961e;
case 0x0c039620u: goto P_0c039620;
case 0x0c039622u: goto P_0c039622;
case 0x0c039624u: goto P_0c039624;
case 0x0c039626u: goto P_0c039626;
case 0x0c039628u: goto P_0c039628;
case 0x0c03962au: goto P_0c03962a;
case 0x0c03962cu: goto P_0c03962c;
case 0x0c03962eu: goto P_0c03962e;
case 0x0c039630u: goto P_0c039630;
case 0x0c039632u: goto P_0c039632;
case 0x0c039634u: goto P_0c039634;
case 0x0c039636u: goto P_0c039636;
case 0x0c039638u: goto P_0c039638;
case 0x0c03963au: goto P_0c03963a;
case 0x0c03963cu: goto P_0c03963c;
case 0x0c03963eu: goto P_0c03963e;
case 0x0c039640u: goto P_0c039640;
case 0x0c039642u: goto P_0c039642;
case 0x0c039644u: goto P_0c039644;
case 0x0c039646u: goto P_0c039646;
case 0x0c039648u: goto P_0c039648;
case 0x0c03964au: goto P_0c03964a;
case 0x0c03964cu: goto P_0c03964c;
case 0x0c03964eu: goto P_0c03964e;
case 0x0c039650u: goto P_0c039650;
case 0x0c039652u: goto P_0c039652;
case 0x0c039654u: goto P_0c039654;
case 0x0c039656u: goto P_0c039656;
case 0x0c039658u: goto P_0c039658;
case 0x0c03965au: goto P_0c03965a;
case 0x0c03965cu: goto P_0c03965c;
case 0x0c03965eu: goto P_0c03965e;
case 0x0c039660u: goto P_0c039660;
case 0x0c039662u: goto P_0c039662;
case 0x0c039664u: goto P_0c039664;
case 0x0c039666u: goto P_0c039666;
case 0x0c039668u: goto P_0c039668;
case 0x0c03966au: goto P_0c03966a;
case 0x0c03966cu: goto P_0c03966c;
case 0x0c03966eu: goto P_0c03966e;
case 0x0c039670u: goto P_0c039670;
case 0x0c039672u: goto P_0c039672;
case 0x0c039674u: goto P_0c039674;
case 0x0c039676u: goto P_0c039676;
case 0x0c039678u: goto P_0c039678;
case 0x0c03967au: goto P_0c03967a;
case 0x0c03967cu: goto P_0c03967c;
case 0x0c03967eu: goto P_0c03967e;
case 0x0c039680u: goto P_0c039680;
case 0x0c039682u: goto P_0c039682;
case 0x0c039684u: goto P_0c039684;
case 0x0c039686u: goto P_0c039686;
case 0x0c039688u: goto P_0c039688;
case 0x0c03968au: goto P_0c03968a;
case 0x0c03968cu: goto P_0c03968c;
case 0x0c03968eu: goto P_0c03968e;
case 0x0c039690u: goto P_0c039690;
case 0x0c039692u: goto P_0c039692;
case 0x0c039694u: goto P_0c039694;
case 0x0c039696u: goto P_0c039696;
case 0x0c039698u: goto P_0c039698;
case 0x0c03969au: goto P_0c03969a;
case 0x0c03969cu: goto P_0c03969c;
case 0x0c03969eu: goto P_0c03969e;
case 0x0c0396a0u: goto P_0c0396a0;
case 0x0c0396a2u: goto P_0c0396a2;
case 0x0c0396b0u: goto P_0c0396b0;
case 0x0c0396b2u: goto P_0c0396b2;
case 0x0c0396b4u: goto P_0c0396b4;
case 0x0c0396b6u: goto P_0c0396b6;
case 0x0c0396b8u: goto P_0c0396b8;
case 0x0c0396bau: goto P_0c0396ba;
case 0x0c0396bcu: goto P_0c0396bc;
case 0x0c0396c0u: goto P_0c0396c0;
case 0x0c0396c2u: goto P_0c0396c2;
case 0x0c0396c4u: goto P_0c0396c4;
case 0x0c0396c6u: goto P_0c0396c6;
case 0x0c0396c8u: goto P_0c0396c8;
case 0x0c0396cau: goto P_0c0396ca;
case 0x0c0396ccu: goto P_0c0396cc;
case 0x0c0396ceu: goto P_0c0396ce;
case 0x0c0396d0u: goto P_0c0396d0;
case 0x0c0396d2u: goto P_0c0396d2;
case 0x0c0396d4u: goto P_0c0396d4;
case 0x0c0396d6u: goto P_0c0396d6;
case 0x0c0396d8u: goto P_0c0396d8;
case 0x0c0396dau: goto P_0c0396da;
case 0x0c0396dcu: goto P_0c0396dc;
case 0x0c0396deu: goto P_0c0396de;
case 0x0c0396e0u: goto P_0c0396e0;
case 0x0c0396e2u: goto P_0c0396e2;
case 0x0c0396e4u: goto P_0c0396e4;
case 0x0c0396e6u: goto P_0c0396e6;
case 0x0c0396e8u: goto P_0c0396e8;
case 0x0c0396eau: goto P_0c0396ea;
case 0x0c0396f0u: goto P_0c0396f0;
case 0x0c0396f2u: goto P_0c0396f2;
case 0x0c039700u: goto P_0c039700;
case 0x0c039702u: goto P_0c039702;
case 0x0c039704u: goto P_0c039704;
case 0x0c039706u: goto P_0c039706;
case 0x0c039708u: goto P_0c039708;
case 0x0c03970au: goto P_0c03970a;
case 0x0c03970cu: goto P_0c03970c;
case 0x0c03970eu: goto P_0c03970e;
case 0x0c039710u: goto P_0c039710;
case 0x0c039712u: goto P_0c039712;
case 0x0c039714u: goto P_0c039714;
case 0x0c039716u: goto P_0c039716;
case 0x0c039718u: goto P_0c039718;
case 0x0c03971au: goto P_0c03971a;
case 0x0c03971cu: goto P_0c03971c;
case 0x0c03971eu: goto P_0c03971e;
case 0x0c039720u: goto P_0c039720;
case 0x0c039722u: goto P_0c039722;
case 0x0c039724u: goto P_0c039724;
case 0x0c039726u: goto P_0c039726;
case 0x0c039728u: goto P_0c039728;
case 0x0c03972au: goto P_0c03972a;
case 0x0c03972cu: goto P_0c03972c;
case 0x0c03972eu: goto P_0c03972e;
case 0x0c039730u: goto P_0c039730;
case 0x0c039fd0u: goto P_0c039fd0;
case 0x0c039fd2u: goto P_0c039fd2;
case 0x0c039fd4u: goto P_0c039fd4;
case 0x0c039fd6u: goto P_0c039fd6;
case 0x0c039fd8u: goto P_0c039fd8;
case 0x0c039fdau: goto P_0c039fda;
case 0x0c039fdcu: goto P_0c039fdc;
case 0x0c039fdeu: goto P_0c039fde;
case 0x0c039fe0u: goto P_0c039fe0;
case 0x0c039fe2u: goto P_0c039fe2;
case 0x0c039fe4u: goto P_0c039fe4;
case 0x0c039fe6u: goto P_0c039fe6;
case 0x0c039fe8u: goto P_0c039fe8;
case 0x0c039feau: goto P_0c039fea;
case 0x0c039fecu: goto P_0c039fec;
case 0x0c039feeu: goto P_0c039fee;
case 0x0c039ff0u: goto P_0c039ff0;
case 0x0c039ff2u: goto P_0c039ff2;
case 0x0c039ff4u: goto P_0c039ff4;
case 0x0c039ff6u: goto P_0c039ff6;
case 0x0c039ff8u: goto P_0c039ff8;
case 0x0c039ffau: goto P_0c039ffa;
case 0x0c039ffcu: goto P_0c039ffc;
case 0x0c039ffeu: goto P_0c039ffe;
case 0x0c03a000u: goto P_0c03a000;
case 0x0c03a002u: goto P_0c03a002;
case 0x0c03a004u: goto P_0c03a004;
case 0x0c03a006u: goto P_0c03a006;
case 0x0c03a008u: goto P_0c03a008;
case 0x0c03a00au: goto P_0c03a00a;
case 0x0c03a00cu: goto P_0c03a00c;
case 0x0c03a00eu: goto P_0c03a00e;
case 0x0c03a010u: goto P_0c03a010;
case 0x0c03a012u: goto P_0c03a012;
case 0x0c03a014u: goto P_0c03a014;
case 0x0c03a016u: goto P_0c03a016;
case 0x0c03a018u: goto P_0c03a018;
case 0x0c03a01au: goto P_0c03a01a;
case 0x0c03a01cu: goto P_0c03a01c;
case 0x0c03a01eu: goto P_0c03a01e;
case 0x0c03a020u: goto P_0c03a020;
case 0x0c03a022u: goto P_0c03a022;
case 0x0c03a024u: goto P_0c03a024;
case 0x0c03a026u: goto P_0c03a026;
case 0x0c03a028u: goto P_0c03a028;
case 0x0c03a02au: goto P_0c03a02a;
case 0x0c03a02cu: goto P_0c03a02c;
case 0x0c03a02eu: goto P_0c03a02e;
case 0x0c03a030u: goto P_0c03a030;
case 0x0c03a032u: goto P_0c03a032;
case 0x0c03a034u: goto P_0c03a034;
case 0x0c03a040u: goto P_0c03a040;
case 0x0c03a042u: goto P_0c03a042;
case 0x0c03a044u: goto P_0c03a044;
case 0x0c03a046u: goto P_0c03a046;
case 0x0c03a048u: goto P_0c03a048;
case 0x0c03a04au: goto P_0c03a04a;
case 0x0c03a04cu: goto P_0c03a04c;
case 0x0c03a04eu: goto P_0c03a04e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c039540: /* original 2fe6, guest PC 0x0c039540 */
if(!s->budget--) { s->failed_pc=0x0c039540u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039542;
P_0c039542: /* original 2fd6, guest PC 0x0c039542 */
if(!s->budget--) { s->failed_pc=0x0c039542u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039544;
P_0c039544: /* original ed00, guest PC 0x0c039544 */
if(!s->budget--) { s->failed_pc=0x0c039544u; return 0; }
r[13]=0x00000000u;
goto P_0c039546;
P_0c039546: /* original 2fc6, guest PC 0x0c039546 */
if(!s->budget--) { s->failed_pc=0x0c039546u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039548;
P_0c039548: /* original ec01, guest PC 0x0c039548 */
if(!s->budget--) { s->failed_pc=0x0c039548u; return 0; }
r[12]=0x00000001u;
goto P_0c03954a;
P_0c03954a: /* original 2fb6, guest PC 0x0c03954a */
if(!s->budget--) { s->failed_pc=0x0c03954au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03954c;
P_0c03954c: /* original eb05, guest PC 0x0c03954c */
if(!s->budget--) { s->failed_pc=0x0c03954cu; return 0; }
r[11]=0x00000005u;
goto P_0c03954e;
P_0c03954e: /* original 2fa6, guest PC 0x0c03954e */
if(!s->budget--) { s->failed_pc=0x0c03954eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039550;
P_0c039550: /* original 4f22, guest PC 0x0c039550 */
if(!s->budget--) { s->failed_pc=0x0c039550u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c039552;
P_0c039552: /* original 7ff0, guest PC 0x0c039552 */
if(!s->budget--) { s->failed_pc=0x0c039552u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c039554;
P_0c039554: /* original 1f42, guest PC 0x0c039554 */
if(!s->budget--) { s->failed_pc=0x0c039554u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c039556;
P_0c039556: /* original 1f51, guest PC 0x0c039556 */
if(!s->budget--) { s->failed_pc=0x0c039556u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c039558;
P_0c039558: /* original 2f62, guest PC 0x0c039558 */
if(!s->budget--) { s->failed_pc=0x0c039558u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c03955a;
P_0c03955a: /* original 1f73, guest PC 0x0c03955a */
if(!s->budget--) { s->failed_pc=0x0c03955au; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c03955c;
P_0c03955c: /* original da1d, guest PC 0x0c03955c */
if(!s->budget--) { s->failed_pc=0x0c03955cu; return 0; }
r[10]=read(ram,0x0c0395d4u,4);
goto P_0c03955e;
P_0c03955e: /* original 5efa, guest PC 0x0c03955e */
if(!s->budget--) { s->failed_pc=0x0c03955eu; return 0; }
r[14]=read(ram,r[15]+40,4);
goto P_0c039560;
P_0c039560: /* original 63e3, guest PC 0x0c039560 */
if(!s->budget--) { s->failed_pc=0x0c039560u; return 0; }
r[3]=r[14];
goto P_0c039562;
P_0c039562: /* original 23c8, guest PC 0x0c039562 */
if(!s->budget--) { s->failed_pc=0x0c039562u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c039564;
P_0c039564: /* original 8909, guest PC 0x0c039564 */
if(!s->budget--) { s->failed_pc=0x0c039564u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03957a; }
goto P_0c039566;
P_0c039566: /* original 51f3, guest PC 0x0c039566 */
if(!s->budget--) { s->failed_pc=0x0c039566u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c039568;
P_0c039568: /* original 2f16, guest PC 0x0c039568 */
if(!s->budget--) { s->failed_pc=0x0c039568u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03956a;
P_0c03956a: /* original 53f1, guest PC 0x0c03956a */
if(!s->budget--) { s->failed_pc=0x0c03956au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c03956c;
P_0c03956c: /* original 2f36, guest PC 0x0c03956c */
if(!s->budget--) { s->failed_pc=0x0c03956cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03956e;
P_0c03956e: /* original d41a, guest PC 0x0c03956e */
if(!s->budget--) { s->failed_pc=0x0c03956eu; return 0; }
r[4]=read(ram,0x0c0395d8u,4);
goto P_0c039570;
P_0c039570: /* original 56f4, guest PC 0x0c039570 */
if(!s->budget--) { s->failed_pc=0x0c039570u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c039572;
P_0c039572: /* original 57f3, guest PC 0x0c039572 */
if(!s->budget--) { s->failed_pc=0x0c039572u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c039574;
P_0c039574: /* original 4a0b, guest PC 0x0c039574 */
if(!s->budget--) { s->failed_pc=0x0c039574u; return 0; }
target=r[10];
r[16]=code_base|0x0c039578u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039578u) { target=s->pc; goto dispatch; }
goto P_0c039578;
P_0c039576: /* original 65d3, guest PC 0x0c039576 */
if(!s->budget--) { s->failed_pc=0x0c039576u; return 0; }
r[5]=r[13];
goto P_0c039578;
P_0c039578: /* original 7f08, guest PC 0x0c039578 */
if(!s->budget--) { s->failed_pc=0x0c039578u; return 0; }
r[15]+=0x00000008u;
goto P_0c03957a;
P_0c03957a: /* original 7d01, guest PC 0x0c03957a */
if(!s->budget--) { s->failed_pc=0x0c03957au; return 0; }
r[13]+=0x00000001u;
goto P_0c03957c;
P_0c03957c: /* original 4e21, guest PC 0x0c03957c */
if(!s->budget--) { s->failed_pc=0x0c03957cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]&1)!=0);
r[14]=(uint32_t)((int32_t)r[14]>>1);
goto P_0c03957e;
P_0c03957e: /* original 3db3, guest PC 0x0c03957e */
if(!s->budget--) { s->failed_pc=0x0c03957eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c039580;
P_0c039580: /* original 8bee, guest PC 0x0c039580 */
if(!s->budget--) { s->failed_pc=0x0c039580u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c039560; }
goto P_0c039582;
P_0c039582: /* original 7f10, guest PC 0x0c039582 */
if(!s->budget--) { s->failed_pc=0x0c039582u; return 0; }
r[15]+=0x00000010u;
goto P_0c039584;
P_0c039584: /* original 4f26, guest PC 0x0c039584 */
if(!s->budget--) { s->failed_pc=0x0c039584u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c039586;
P_0c039586: /* original 6af6, guest PC 0x0c039586 */
if(!s->budget--) { s->failed_pc=0x0c039586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c039588;
P_0c039588: /* original 6bf6, guest PC 0x0c039588 */
if(!s->budget--) { s->failed_pc=0x0c039588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03958a;
P_0c03958a: /* original 6cf6, guest PC 0x0c03958a */
if(!s->budget--) { s->failed_pc=0x0c03958au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03958c;
P_0c03958c: /* original 6df6, guest PC 0x0c03958c */
if(!s->budget--) { s->failed_pc=0x0c03958cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03958e;
P_0c03958e: /* original 000b, guest PC 0x0c03958e */
if(!s->budget--) { s->failed_pc=0x0c03958eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c039590: /* original 6ef6, guest PC 0x0c039590 */
if(!s->budget--) { s->failed_pc=0x0c039590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c039592u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039592u; return 0; } return 1;
P_0c0395e0: /* original 2fe6, guest PC 0x0c0395e0 */
if(!s->budget--) { s->failed_pc=0x0c0395e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395e2;
P_0c0395e2: /* original e301, guest PC 0x0c0395e2 */
if(!s->budget--) { s->failed_pc=0x0c0395e2u; return 0; }
r[3]=0x00000001u;
goto P_0c0395e4;
P_0c0395e4: /* original 2fd6, guest PC 0x0c0395e4 */
if(!s->budget--) { s->failed_pc=0x0c0395e4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395e6;
P_0c0395e6: /* original 2fc6, guest PC 0x0c0395e6 */
if(!s->budget--) { s->failed_pc=0x0c0395e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395e8;
P_0c0395e8: /* original 2fb6, guest PC 0x0c0395e8 */
if(!s->budget--) { s->failed_pc=0x0c0395e8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395ea;
P_0c0395ea: /* original 6b53, guest PC 0x0c0395ea */
if(!s->budget--) { s->failed_pc=0x0c0395eau; return 0; }
r[11]=r[5];
goto P_0c0395ec;
P_0c0395ec: /* original 2fa6, guest PC 0x0c0395ec */
if(!s->budget--) { s->failed_pc=0x0c0395ecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395ee;
P_0c0395ee: /* original 6a43, guest PC 0x0c0395ee */
if(!s->budget--) { s->failed_pc=0x0c0395eeu; return 0; }
r[10]=r[4];
goto P_0c0395f0;
P_0c0395f0: /* original 4f22, guest PC 0x0c0395f0 */
if(!s->budget--) { s->failed_pc=0x0c0395f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0395f2;
P_0c0395f2: /* original de8e, guest PC 0x0c0395f2 */
if(!s->budget--) { s->failed_pc=0x0c0395f2u; return 0; }
r[14]=read(ram,0x0c03982cu,4);
goto P_0c0395f4;
P_0c0395f4: /* original 23a8, guest PC 0x0c0395f4 */
if(!s->budget--) { s->failed_pc=0x0c0395f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0395f6;
P_0c0395f6: /* original dd8c, guest PC 0x0c0395f6 */
if(!s->budget--) { s->failed_pc=0x0c0395f6u; return 0; }
r[13]=read(ram,0x0c039828u,4);
goto P_0c0395f8;
P_0c0395f8: /* original 8d09, guest PC 0x0c0395f8 */
if(!s->budget--) { s->failed_pc=0x0c0395f8u; return 0; }
cond=r[17]&1u;
r[11]<<=16;
if(cond) { goto P_0c03960e; }
goto P_0c0395fc;
P_0c0395fa: /* original 4b28, guest PC 0x0c0395fa */
if(!s->budget--) { s->failed_pc=0x0c0395fau; return 0; }
r[11]<<=16;
goto P_0c0395fc;
P_0c0395fc: /* original 64d3, guest PC 0x0c0395fc */
if(!s->budget--) { s->failed_pc=0x0c0395fcu; return 0; }
r[4]=r[13];
goto P_0c0395fe;
P_0c0395fe: /* original 6342, guest PC 0x0c0395fe */
if(!s->budget--) { s->failed_pc=0x0c0395feu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c039600;
P_0c039600: /* original 6543, guest PC 0x0c039600 */
if(!s->budget--) { s->failed_pc=0x0c039600u; return 0; }
r[5]=r[4];
goto P_0c039602;
P_0c039602: /* original e604, guest PC 0x0c039602 */
if(!s->budget--) { s->failed_pc=0x0c039602u; return 0; }
r[6]=0x00000004u;
goto P_0c039604;
P_0c039604: /* original 23e9, guest PC 0x0c039604 */
if(!s->budget--) { s->failed_pc=0x0c039604u; return 0; }
r[3]&=r[14];
goto P_0c039606;
P_0c039606: /* original 23bb, guest PC 0x0c039606 */
if(!s->budget--) { s->failed_pc=0x0c039606u; return 0; }
r[3]|=r[11];
goto P_0c039608;
P_0c039608: /* original 2432, guest PC 0x0c039608 */
if(!s->budget--) { s->failed_pc=0x0c039608u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c03960a;
P_0c03960a: /* original b059, guest PC 0x0c03960a */
if(!s->budget--) { s->failed_pc=0x0c03960au; return 0; }
target=code_base|0x0c0396c0u; r[16]=code_base|0x0c03960eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03960eu) { target=s->pc; goto dispatch; }
goto P_0c03960e;
P_0c03960c: /* original e400, guest PC 0x0c03960c */
if(!s->budget--) { s->failed_pc=0x0c03960cu; return 0; }
r[4]=0x00000000u;
goto P_0c03960e;
P_0c03960e: /* original e302, guest PC 0x0c03960e */
if(!s->budget--) { s->failed_pc=0x0c03960eu; return 0; }
r[3]=0x00000002u;
goto P_0c039610;
P_0c039610: /* original dc87, guest PC 0x0c039610 */
if(!s->budget--) { s->failed_pc=0x0c039610u; return 0; }
r[12]=read(ram,0x0c039830u,4);
goto P_0c039612;
P_0c039612: /* original 23a8, guest PC 0x0c039612 */
if(!s->budget--) { s->failed_pc=0x0c039612u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c039614;
P_0c039614: /* original 8910, guest PC 0x0c039614 */
if(!s->budget--) { s->failed_pc=0x0c039614u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039638; }
goto P_0c039616;
P_0c039616: /* original 65c3, guest PC 0x0c039616 */
if(!s->budget--) { s->failed_pc=0x0c039616u; return 0; }
r[5]=r[12];
goto P_0c039618;
P_0c039618: /* original 6352, guest PC 0x0c039618 */
if(!s->budget--) { s->failed_pc=0x0c039618u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c03961a;
P_0c03961a: /* original d486, guest PC 0x0c03961a */
if(!s->budget--) { s->failed_pc=0x0c03961au; return 0; }
r[4]=read(ram,0x0c039834u,4);
goto P_0c03961c;
P_0c03961c: /* original e606, guest PC 0x0c03961c */
if(!s->budget--) { s->failed_pc=0x0c03961cu; return 0; }
r[6]=0x00000006u;
goto P_0c03961e;
P_0c03961e: /* original 23e9, guest PC 0x0c03961e */
if(!s->budget--) { s->failed_pc=0x0c03961eu; return 0; }
r[3]&=r[14];
goto P_0c039620;
P_0c039620: /* original 23bb, guest PC 0x0c039620 */
if(!s->budget--) { s->failed_pc=0x0c039620u; return 0; }
r[3]|=r[11];
goto P_0c039622;
P_0c039622: /* original 234b, guest PC 0x0c039622 */
if(!s->budget--) { s->failed_pc=0x0c039622u; return 0; }
r[3]|=r[4];
goto P_0c039624;
P_0c039624: /* original 2532, guest PC 0x0c039624 */
if(!s->budget--) { s->failed_pc=0x0c039624u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c039626;
P_0c039626: /* original 7560, guest PC 0x0c039626 */
if(!s->budget--) { s->failed_pc=0x0c039626u; return 0; }
r[5]+=0x00000060u;
goto P_0c039628;
P_0c039628: /* original 6252, guest PC 0x0c039628 */
if(!s->budget--) { s->failed_pc=0x0c039628u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c03962a;
P_0c03962a: /* original 22e9, guest PC 0x0c03962a */
if(!s->budget--) { s->failed_pc=0x0c03962au; return 0; }
r[2]&=r[14];
goto P_0c03962c;
P_0c03962c: /* original 22bb, guest PC 0x0c03962c */
if(!s->budget--) { s->failed_pc=0x0c03962cu; return 0; }
r[2]|=r[11];
goto P_0c03962e;
P_0c03962e: /* original 224b, guest PC 0x0c03962e */
if(!s->budget--) { s->failed_pc=0x0c03962eu; return 0; }
r[2]|=r[4];
goto P_0c039630;
P_0c039630: /* original 2522, guest PC 0x0c039630 */
if(!s->budget--) { s->failed_pc=0x0c039630u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c039632;
P_0c039632: /* original 65c3, guest PC 0x0c039632 */
if(!s->budget--) { s->failed_pc=0x0c039632u; return 0; }
r[5]=r[12];
goto P_0c039634;
P_0c039634: /* original b044, guest PC 0x0c039634 */
if(!s->budget--) { s->failed_pc=0x0c039634u; return 0; }
target=code_base|0x0c0396c0u; r[16]=code_base|0x0c039638u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039638u) { target=s->pc; goto dispatch; }
goto P_0c039638;
P_0c039636: /* original e401, guest PC 0x0c039636 */
if(!s->budget--) { s->failed_pc=0x0c039636u; return 0; }
r[4]=0x00000001u;
goto P_0c039638;
P_0c039638: /* original e204, guest PC 0x0c039638 */
if(!s->budget--) { s->failed_pc=0x0c039638u; return 0; }
r[2]=0x00000004u;
goto P_0c03963a;
P_0c03963a: /* original 22a8, guest PC 0x0c03963a */
if(!s->budget--) { s->failed_pc=0x0c03963au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c03963c;
P_0c03963c: /* original 890a, guest PC 0x0c03963c */
if(!s->budget--) { s->failed_pc=0x0c03963cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039654; }
goto P_0c03963e;
P_0c03963e: /* original 64d3, guest PC 0x0c03963e */
if(!s->budget--) { s->failed_pc=0x0c03963eu; return 0; }
r[4]=r[13];
goto P_0c039640;
P_0c039640: /* original 6242, guest PC 0x0c039640 */
if(!s->budget--) { s->failed_pc=0x0c039640u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c039642;
P_0c039642: /* original d37d, guest PC 0x0c039642 */
if(!s->budget--) { s->failed_pc=0x0c039642u; return 0; }
r[3]=read(ram,0x0c039838u,4);
goto P_0c039644;
P_0c039644: /* original 6543, guest PC 0x0c039644 */
if(!s->budget--) { s->failed_pc=0x0c039644u; return 0; }
r[5]=r[4];
goto P_0c039646;
P_0c039646: /* original 22e9, guest PC 0x0c039646 */
if(!s->budget--) { s->failed_pc=0x0c039646u; return 0; }
r[2]&=r[14];
goto P_0c039648;
P_0c039648: /* original 22bb, guest PC 0x0c039648 */
if(!s->budget--) { s->failed_pc=0x0c039648u; return 0; }
r[2]|=r[11];
goto P_0c03964a;
P_0c03964a: /* original 223b, guest PC 0x0c03964a */
if(!s->budget--) { s->failed_pc=0x0c03964au; return 0; }
r[2]|=r[3];
goto P_0c03964c;
P_0c03964c: /* original e604, guest PC 0x0c03964c */
if(!s->budget--) { s->failed_pc=0x0c03964cu; return 0; }
r[6]=0x00000004u;
goto P_0c03964e;
P_0c03964e: /* original 2422, guest PC 0x0c03964e */
if(!s->budget--) { s->failed_pc=0x0c03964eu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c039650;
P_0c039650: /* original b036, guest PC 0x0c039650 */
if(!s->budget--) { s->failed_pc=0x0c039650u; return 0; }
target=code_base|0x0c0396c0u; r[16]=code_base|0x0c039654u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039654u) { target=s->pc; goto dispatch; }
goto P_0c039654;
P_0c039652: /* original e402, guest PC 0x0c039652 */
if(!s->budget--) { s->failed_pc=0x0c039652u; return 0; }
r[4]=0x00000002u;
goto P_0c039654;
P_0c039654: /* original e308, guest PC 0x0c039654 */
if(!s->budget--) { s->failed_pc=0x0c039654u; return 0; }
r[3]=0x00000008u;
goto P_0c039656;
P_0c039656: /* original 23a8, guest PC 0x0c039656 */
if(!s->budget--) { s->failed_pc=0x0c039656u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c039658;
P_0c039658: /* original 8910, guest PC 0x0c039658 */
if(!s->budget--) { s->failed_pc=0x0c039658u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03967c; }
goto P_0c03965a;
P_0c03965a: /* original 65c3, guest PC 0x0c03965a */
if(!s->budget--) { s->failed_pc=0x0c03965au; return 0; }
r[5]=r[12];
goto P_0c03965c;
P_0c03965c: /* original 6352, guest PC 0x0c03965c */
if(!s->budget--) { s->failed_pc=0x0c03965cu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c03965e;
P_0c03965e: /* original d477, guest PC 0x0c03965e */
if(!s->budget--) { s->failed_pc=0x0c03965eu; return 0; }
r[4]=read(ram,0x0c03983cu,4);
goto P_0c039660;
P_0c039660: /* original e606, guest PC 0x0c039660 */
if(!s->budget--) { s->failed_pc=0x0c039660u; return 0; }
r[6]=0x00000006u;
goto P_0c039662;
P_0c039662: /* original 23e9, guest PC 0x0c039662 */
if(!s->budget--) { s->failed_pc=0x0c039662u; return 0; }
r[3]&=r[14];
goto P_0c039664;
P_0c039664: /* original 23bb, guest PC 0x0c039664 */
if(!s->budget--) { s->failed_pc=0x0c039664u; return 0; }
r[3]|=r[11];
goto P_0c039666;
P_0c039666: /* original 234b, guest PC 0x0c039666 */
if(!s->budget--) { s->failed_pc=0x0c039666u; return 0; }
r[3]|=r[4];
goto P_0c039668;
P_0c039668: /* original 2532, guest PC 0x0c039668 */
if(!s->budget--) { s->failed_pc=0x0c039668u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c03966a;
P_0c03966a: /* original 7560, guest PC 0x0c03966a */
if(!s->budget--) { s->failed_pc=0x0c03966au; return 0; }
r[5]+=0x00000060u;
goto P_0c03966c;
P_0c03966c: /* original 6252, guest PC 0x0c03966c */
if(!s->budget--) { s->failed_pc=0x0c03966cu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c03966e;
P_0c03966e: /* original 22e9, guest PC 0x0c03966e */
if(!s->budget--) { s->failed_pc=0x0c03966eu; return 0; }
r[2]&=r[14];
goto P_0c039670;
P_0c039670: /* original 22bb, guest PC 0x0c039670 */
if(!s->budget--) { s->failed_pc=0x0c039670u; return 0; }
r[2]|=r[11];
goto P_0c039672;
P_0c039672: /* original 224b, guest PC 0x0c039672 */
if(!s->budget--) { s->failed_pc=0x0c039672u; return 0; }
r[2]|=r[4];
goto P_0c039674;
P_0c039674: /* original 2522, guest PC 0x0c039674 */
if(!s->budget--) { s->failed_pc=0x0c039674u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c039676;
P_0c039676: /* original 65c3, guest PC 0x0c039676 */
if(!s->budget--) { s->failed_pc=0x0c039676u; return 0; }
r[5]=r[12];
goto P_0c039678;
P_0c039678: /* original b022, guest PC 0x0c039678 */
if(!s->budget--) { s->failed_pc=0x0c039678u; return 0; }
target=code_base|0x0c0396c0u; r[16]=code_base|0x0c03967cu;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03967cu) { target=s->pc; goto dispatch; }
goto P_0c03967c;
P_0c03967a: /* original e403, guest PC 0x0c03967a */
if(!s->budget--) { s->failed_pc=0x0c03967au; return 0; }
r[4]=0x00000003u;
goto P_0c03967c;
P_0c03967c: /* original e210, guest PC 0x0c03967c */
if(!s->budget--) { s->failed_pc=0x0c03967cu; return 0; }
r[2]=0x00000010u;
goto P_0c03967e;
P_0c03967e: /* original 2a28, guest PC 0x0c03967e */
if(!s->budget--) { s->failed_pc=0x0c03967eu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c039680;
P_0c039680: /* original 8916, guest PC 0x0c039680 */
if(!s->budget--) { s->failed_pc=0x0c039680u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0396b0; }
goto P_0c039682;
P_0c039682: /* original 4f26, guest PC 0x0c039682 */
if(!s->budget--) { s->failed_pc=0x0c039682u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c039684;
P_0c039684: /* original 64d3, guest PC 0x0c039684 */
if(!s->budget--) { s->failed_pc=0x0c039684u; return 0; }
r[4]=r[13];
goto P_0c039686;
P_0c039686: /* original 6142, guest PC 0x0c039686 */
if(!s->budget--) { s->failed_pc=0x0c039686u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c039688;
P_0c039688: /* original d36d, guest PC 0x0c039688 */
if(!s->budget--) { s->failed_pc=0x0c039688u; return 0; }
r[3]=read(ram,0x0c039840u,4);
goto P_0c03968a;
P_0c03968a: /* original e604, guest PC 0x0c03968a */
if(!s->budget--) { s->failed_pc=0x0c03968au; return 0; }
r[6]=0x00000004u;
goto P_0c03968c;
P_0c03968c: /* original 2e19, guest PC 0x0c03968c */
if(!s->budget--) { s->failed_pc=0x0c03968cu; return 0; }
r[14]&=r[1];
goto P_0c03968e;
P_0c03968e: /* original 6543, guest PC 0x0c03968e */
if(!s->budget--) { s->failed_pc=0x0c03968eu; return 0; }
r[5]=r[4];
goto P_0c039690;
P_0c039690: /* original 2ebb, guest PC 0x0c039690 */
if(!s->budget--) { s->failed_pc=0x0c039690u; return 0; }
r[14]|=r[11];
goto P_0c039692;
P_0c039692: /* original 2e3b, guest PC 0x0c039692 */
if(!s->budget--) { s->failed_pc=0x0c039692u; return 0; }
r[14]|=r[3];
goto P_0c039694;
P_0c039694: /* original 24e2, guest PC 0x0c039694 */
if(!s->budget--) { s->failed_pc=0x0c039694u; return 0; }
write(ram,r[4],r[14],4);
goto P_0c039696;
P_0c039696: /* original 6463, guest PC 0x0c039696 */
if(!s->budget--) { s->failed_pc=0x0c039696u; return 0; }
r[4]=r[6];
goto P_0c039698;
P_0c039698: /* original 6af6, guest PC 0x0c039698 */
if(!s->budget--) { s->failed_pc=0x0c039698u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03969a;
P_0c03969a: /* original 6bf6, guest PC 0x0c03969a */
if(!s->budget--) { s->failed_pc=0x0c03969au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03969c;
P_0c03969c: /* original 6cf6, guest PC 0x0c03969c */
if(!s->budget--) { s->failed_pc=0x0c03969cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03969e;
P_0c03969e: /* original 6df6, guest PC 0x0c03969e */
if(!s->budget--) { s->failed_pc=0x0c03969eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0396a0;
P_0c0396a0: /* original a00e, guest PC 0x0c0396a0 */
if(!s->budget--) { s->failed_pc=0x0c0396a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0396c0;
P_0c0396a2: /* original 6ef6, guest PC 0x0c0396a2 */
if(!s->budget--) { s->failed_pc=0x0c0396a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0396a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396a4u; return 0; } return 1;
P_0c0396b0: /* original 4f26, guest PC 0x0c0396b0 */
if(!s->budget--) { s->failed_pc=0x0c0396b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0396b2;
P_0c0396b2: /* original 6af6, guest PC 0x0c0396b2 */
if(!s->budget--) { s->failed_pc=0x0c0396b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0396b4;
P_0c0396b4: /* original 6bf6, guest PC 0x0c0396b4 */
if(!s->budget--) { s->failed_pc=0x0c0396b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0396b6;
P_0c0396b6: /* original 6cf6, guest PC 0x0c0396b6 */
if(!s->budget--) { s->failed_pc=0x0c0396b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0396b8;
P_0c0396b8: /* original 6df6, guest PC 0x0c0396b8 */
if(!s->budget--) { s->failed_pc=0x0c0396b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0396ba;
P_0c0396ba: /* original 000b, guest PC 0x0c0396ba */
if(!s->budget--) { s->failed_pc=0x0c0396bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0396bc: /* original 6ef6, guest PC 0x0c0396bc */
if(!s->budget--) { s->failed_pc=0x0c0396bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0396beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396beu; return 0; } return 1;
P_0c0396c0: /* original 2fd6, guest PC 0x0c0396c0 */
if(!s->budget--) { s->failed_pc=0x0c0396c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0396c2;
P_0c0396c2: /* original 4408, guest PC 0x0c0396c2 */
if(!s->budget--) { s->failed_pc=0x0c0396c2u; return 0; }
r[4]<<=2;
goto P_0c0396c4;
P_0c0396c4: /* original 7ffc, guest PC 0x0c0396c4 */
if(!s->budget--) { s->failed_pc=0x0c0396c4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0396c6;
P_0c0396c6: /* original 2f42, guest PC 0x0c0396c6 */
if(!s->budget--) { s->failed_pc=0x0c0396c6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0396c8;
P_0c0396c8: /* original d35e, guest PC 0x0c0396c8 */
if(!s->budget--) { s->failed_pc=0x0c0396c8u; return 0; }
r[3]=read(ram,0x0c039844u,4);
goto P_0c0396ca;
P_0c0396ca: /* original d15f, guest PC 0x0c0396ca */
if(!s->budget--) { s->failed_pc=0x0c0396cau; return 0; }
r[1]=read(ram,0x0c039848u,4);
goto P_0c0396cc;
P_0c0396cc: /* original 6032, guest PC 0x0c0396cc */
if(!s->budget--) { s->failed_pc=0x0c0396ccu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0396ce;
P_0c0396ce: /* original 044e, guest PC 0x0c0396ce */
if(!s->budget--) { s->failed_pc=0x0c0396ceu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0396d0;
P_0c0396d0: /* original 6243, guest PC 0x0c0396d0 */
if(!s->budget--) { s->failed_pc=0x0c0396d0u; return 0; }
r[2]=r[4];
goto P_0c0396d2;
P_0c0396d2: /* original 4229, guest PC 0x0c0396d2 */
if(!s->budget--) { s->failed_pc=0x0c0396d2u; return 0; }
r[2]>>=16;
goto P_0c0396d4;
P_0c0396d4: /* original 4219, guest PC 0x0c0396d4 */
if(!s->budget--) { s->failed_pc=0x0c0396d4u; return 0; }
r[2]>>=8;
goto P_0c0396d6;
P_0c0396d6: /* original 2122, guest PC 0x0c0396d6 */
if(!s->budget--) { s->failed_pc=0x0c0396d6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0396d8;
P_0c0396d8: /* original e100, guest PC 0x0c0396d8 */
if(!s->budget--) { s->failed_pc=0x0c0396d8u; return 0; }
r[1]=0x00000000u;
goto P_0c0396da;
P_0c0396da: /* original d35c, guest PC 0x0c0396da */
if(!s->budget--) { s->failed_pc=0x0c0396dau; return 0; }
r[3]=read(ram,0x0c03984cu,4);
goto P_0c0396dc;
P_0c0396dc: /* original 2322, guest PC 0x0c0396dc */
if(!s->budget--) { s->failed_pc=0x0c0396dcu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0396de;
P_0c0396de: /* original d75c, guest PC 0x0c0396de */
if(!s->budget--) { s->failed_pc=0x0c0396deu; return 0; }
r[7]=read(ram,0x0c039850u,4);
goto P_0c0396e0;
P_0c0396e0: /* original d25c, guest PC 0x0c0396e0 */
if(!s->budget--) { s->failed_pc=0x0c0396e0u; return 0; }
r[2]=read(ram,0x0c039854u,4);
goto P_0c0396e2;
P_0c0396e2: /* original 2749, guest PC 0x0c0396e2 */
if(!s->budget--) { s->failed_pc=0x0c0396e2u; return 0; }
r[7]&=r[4];
goto P_0c0396e4;
P_0c0396e4: /* original 272b, guest PC 0x0c0396e4 */
if(!s->budget--) { s->failed_pc=0x0c0396e4u; return 0; }
r[7]|=r[2];
goto P_0c0396e6;
P_0c0396e6: /* original 6d73, guest PC 0x0c0396e6 */
if(!s->budget--) { s->failed_pc=0x0c0396e6u; return 0; }
r[13]=r[7];
goto P_0c0396e8;
P_0c0396e8: /* original a013, guest PC 0x0c0396e8 */
if(!s->budget--) { s->failed_pc=0x0c0396e8u; return 0; }
r[0]=0x00000008u;
goto P_0c039712;
P_0c0396ea: /* original e008, guest PC 0x0c0396ea */
if(!s->budget--) { s->failed_pc=0x0c0396eau; return 0; }
r[0]=0x00000008u;
if(!vf3_matrix_family(0x0c0396ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396ecu; return 0; } return 1;
P_0c0396f0: /* original a00a, guest PC 0x0c0396f0 */
if(!s->budget--) { s->failed_pc=0x0c0396f0u; return 0; }
r[4]=r[0];
goto P_0c039708;
P_0c0396f2: /* original 6403, guest PC 0x0c0396f2 */
if(!s->budget--) { s->failed_pc=0x0c0396f2u; return 0; }
r[4]=r[0];
if(!vf3_matrix_family(0x0c0396f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396f4u; return 0; } return 1;
P_0c039700: /* original 6256, guest PC 0x0c039700 */
if(!s->budget--) { s->failed_pc=0x0c039700u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[2]=tmp;
goto P_0c039702;
P_0c039702: /* original 74ff, guest PC 0x0c039702 */
if(!s->budget--) { s->failed_pc=0x0c039702u; return 0; }
r[4]+=0xffffffffu;
goto P_0c039704;
P_0c039704: /* original 2d22, guest PC 0x0c039704 */
if(!s->budget--) { s->failed_pc=0x0c039704u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c039706;
P_0c039706: /* original 7d04, guest PC 0x0c039706 */
if(!s->budget--) { s->failed_pc=0x0c039706u; return 0; }
r[13]+=0x00000004u;
goto P_0c039708;
P_0c039708: /* original 2448, guest PC 0x0c039708 */
if(!s->budget--) { s->failed_pc=0x0c039708u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03970a;
P_0c03970a: /* original 8bf9, guest PC 0x0c03970a */
if(!s->budget--) { s->failed_pc=0x0c03970au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c039700; }
goto P_0c03970c;
P_0c03970c: /* original 0783, guest PC 0x0c03970c */
if(!s->budget--) { s->failed_pc=0x0c03970cu; return 0; }
if((r[7]&0xFC000000u)==0xE0000000u) pref(ram,r[7]);
goto P_0c03970e;
P_0c03970e: /* original 7101, guest PC 0x0c03970e */
if(!s->budget--) { s->failed_pc=0x0c03970eu; return 0; }
r[1]+=0x00000001u;
goto P_0c039710;
P_0c039710: /* original 7720, guest PC 0x0c039710 */
if(!s->budget--) { s->failed_pc=0x0c039710u; return 0; }
r[7]+=0x00000020u;
goto P_0c039712;
P_0c039712: /* original 3163, guest PC 0x0c039712 */
if(!s->budget--) { s->failed_pc=0x0c039712u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[6])!=0);
goto P_0c039714;
P_0c039714: /* original 8bec, guest PC 0x0c039714 */
if(!s->budget--) { s->failed_pc=0x0c039714u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0396f0; }
goto P_0c039716;
P_0c039716: /* original d24b, guest PC 0x0c039716 */
if(!s->budget--) { s->failed_pc=0x0c039716u; return 0; }
r[2]=read(ram,0x0c039844u,4);
goto P_0c039718;
P_0c039718: /* original 64f2, guest PC 0x0c039718 */
if(!s->budget--) { s->failed_pc=0x0c039718u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03971a;
P_0c03971a: /* original 7f04, guest PC 0x0c03971a */
if(!s->budget--) { s->failed_pc=0x0c03971au; return 0; }
r[15]+=0x00000004u;
goto P_0c03971c;
P_0c03971c: /* original 6322, guest PC 0x0c03971c */
if(!s->budget--) { s->failed_pc=0x0c03971cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03971e;
P_0c03971e: /* original d14e, guest PC 0x0c03971e */
if(!s->budget--) { s->failed_pc=0x0c03971eu; return 0; }
r[1]=read(ram,0x0c039858u,4);
goto P_0c039720;
P_0c039720: /* original 343c, guest PC 0x0c039720 */
if(!s->budget--) { s->failed_pc=0x0c039720u; return 0; }
r[4]+=r[3];
goto P_0c039722;
P_0c039722: /* original d34b, guest PC 0x0c039722 */
if(!s->budget--) { s->failed_pc=0x0c039722u; return 0; }
r[3]=read(ram,0x0c039850u,4);
goto P_0c039724;
P_0c039724: /* original 6042, guest PC 0x0c039724 */
if(!s->budget--) { s->failed_pc=0x0c039724u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c039726;
P_0c039726: /* original 2739, guest PC 0x0c039726 */
if(!s->budget--) { s->failed_pc=0x0c039726u; return 0; }
r[7]&=r[3];
goto P_0c039728;
P_0c039728: /* original 2019, guest PC 0x0c039728 */
if(!s->budget--) { s->failed_pc=0x0c039728u; return 0; }
r[0]&=r[1];
goto P_0c03972a;
P_0c03972a: /* original 207b, guest PC 0x0c03972a */
if(!s->budget--) { s->failed_pc=0x0c03972au; return 0; }
r[0]|=r[7];
goto P_0c03972c;
P_0c03972c: /* original 2402, guest PC 0x0c03972c */
if(!s->budget--) { s->failed_pc=0x0c03972cu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c03972e;
P_0c03972e: /* original 000b, guest PC 0x0c03972e */
if(!s->budget--) { s->failed_pc=0x0c03972eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c039730: /* original 6df6, guest PC 0x0c039730 */
if(!s->budget--) { s->failed_pc=0x0c039730u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c039732u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039732u; return 0; } return 1;
P_0c039fd0: /* original f34c, guest PC 0x0c039fd0 */
if(!s->budget--) { s->failed_pc=0x0c039fd0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c039fd2;
P_0c039fd2: /* original f35d, guest PC 0x0c039fd2 */
if(!s->budget--) { s->failed_pc=0x0c039fd2u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c039fd4;
P_0c039fd4: /* original f69d, guest PC 0x0c039fd4 */
if(!s->budget--) { s->failed_pc=0x0c039fd4u; return 0; }
fr[6]=0x3f800000u;
goto P_0c039fd6;
P_0c039fd6: /* original f365, guest PC 0x0c039fd6 */
if(!s->budget--) { s->failed_pc=0x0c039fd6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c039fd8;
P_0c039fd8: /* original 8d02, guest PC 0x0c039fd8 */
if(!s->budget--) { s->failed_pc=0x0c039fd8u; return 0; }
cond=r[17]&1u;
fr[7]=0;
if(cond) { goto P_0c039fe0; }
goto P_0c039fdc;
P_0c039fda: /* original f78d, guest PC 0x0c039fda */
if(!s->budget--) { s->failed_pc=0x0c039fdau; return 0; }
fr[7]=0;
goto P_0c039fdc;
P_0c039fdc: /* original a002, guest PC 0x0c039fdc */
if(!s->budget--) { s->failed_pc=0x0c039fdcu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe4;
P_0c039fde: /* original f54c, guest PC 0x0c039fde */
if(!s->budget--) { s->failed_pc=0x0c039fdeu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe0;
P_0c039fe0: /* original f56c, guest PC 0x0c039fe0 */
if(!s->budget--) { s->failed_pc=0x0c039fe0u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c039fe2;
P_0c039fe2: /* original f543, guest PC 0x0c039fe2 */
if(!s->budget--) { s->failed_pc=0x0c039fe2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c039fe4;
P_0c039fe4: /* original e40d, guest PC 0x0c039fe4 */
if(!s->budget--) { s->failed_pc=0x0c039fe4u; return 0; }
r[4]=0x0000000du;
goto P_0c039fe6;
P_0c039fe6: /* original e501, guest PC 0x0c039fe6 */
if(!s->budget--) { s->failed_pc=0x0c039fe6u; return 0; }
r[5]=0x00000001u;
goto P_0c039fe8;
P_0c039fe8: /* original 445a, guest PC 0x0c039fe8 */
if(!s->budget--) { s->failed_pc=0x0c039fe8u; return 0; }
r[53]=r[4];
goto P_0c039fea;
P_0c039fea: /* original 6343, guest PC 0x0c039fea */
if(!s->budget--) { s->failed_pc=0x0c039feau; return 0; }
r[3]=r[4];
goto P_0c039fec;
P_0c039fec: /* original 4300, guest PC 0x0c039fec */
if(!s->budget--) { s->failed_pc=0x0c039fecu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c039fee;
P_0c039fee: /* original 74ff, guest PC 0x0c039fee */
if(!s->budget--) { s->failed_pc=0x0c039feeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c039ff0;
P_0c039ff0: /* original f32d, guest PC 0x0c039ff0 */
if(!s->budget--) { s->failed_pc=0x0c039ff0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff2;
P_0c039ff2: /* original 435a, guest PC 0x0c039ff2 */
if(!s->budget--) { s->failed_pc=0x0c039ff2u; return 0; }
r[53]=r[3];
goto P_0c039ff4;
P_0c039ff4: /* original 3453, guest PC 0x0c039ff4 */
if(!s->budget--) { s->failed_pc=0x0c039ff4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c039ff6;
P_0c039ff6: /* original f22d, guest PC 0x0c039ff6 */
if(!s->budget--) { s->failed_pc=0x0c039ff6u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff8;
P_0c039ff8: /* original f83c, guest PC 0x0c039ff8 */
if(!s->budget--) { s->failed_pc=0x0c039ff8u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c039ffa;
P_0c039ffa: /* original f382, guest PC 0x0c039ffa */
if(!s->budget--) { s->failed_pc=0x0c039ffau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c039ffc;
P_0c039ffc: /* original f270, guest PC 0x0c039ffc */
if(!s->budget--) { s->failed_pc=0x0c039ffcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'+');
goto P_0c039ffe;
P_0c039ffe: /* original f352, guest PC 0x0c039ffe */
if(!s->budget--) { s->failed_pc=0x0c039ffeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a000;
P_0c03a000: /* original f260, guest PC 0x0c03a000 */
if(!s->budget--) { s->failed_pc=0x0c03a000u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'+');
goto P_0c03a002;
P_0c03a002: /* original f352, guest PC 0x0c03a002 */
if(!s->budget--) { s->failed_pc=0x0c03a002u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a004;
P_0c03a004: /* original f73c, guest PC 0x0c03a004 */
if(!s->budget--) { s->failed_pc=0x0c03a004u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c03a006;
P_0c03a006: /* original 8def, guest PC 0x0c03a006 */
if(!s->budget--) { s->failed_pc=0x0c03a006u; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
if(cond) { goto P_0c039fe8; }
goto P_0c03a00a;
P_0c03a008: /* original f723, guest PC 0x0c03a008 */
if(!s->budget--) { s->failed_pc=0x0c03a008u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
goto P_0c03a00a;
P_0c03a00a: /* original f760, guest PC 0x0c03a00a */
if(!s->budget--) { s->failed_pc=0x0c03a00au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'+');
goto P_0c03a00c;
P_0c03a00c: /* original c713, guest PC 0x0c03a00c */
if(!s->budget--) { s->failed_pc=0x0c03a00cu; return 0; }
r[0]=code_base|0x0003a05cu;
goto P_0c03a00e;
P_0c03a00e: /* original f465, guest PC 0x0c03a00e */
if(!s->budget--) { s->failed_pc=0x0c03a00eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c03a010;
P_0c03a010: /* original d315, guest PC 0x0c03a010 */
if(!s->budget--) { s->failed_pc=0x0c03a010u; return 0; }
r[3]=read(ram,0x0c03a068u,4);
goto P_0c03a012;
P_0c03a012: /* original f573, guest PC 0x0c03a012 */
if(!s->budget--) { s->failed_pc=0x0c03a012u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'/');
goto P_0c03a014;
P_0c03a014: /* original f708, guest PC 0x0c03a014 */
if(!s->budget--) { s->failed_pc=0x0c03a014u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a016;
P_0c03a016: /* original c712, guest PC 0x0c03a016 */
if(!s->budget--) { s->failed_pc=0x0c03a016u; return 0; }
r[0]=code_base|0x0003a060u;
goto P_0c03a018;
P_0c03a018: /* original f208, guest PC 0x0c03a018 */
if(!s->budget--) { s->failed_pc=0x0c03a018u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a01a;
P_0c03a01a: /* original c712, guest PC 0x0c03a01a */
if(!s->budget--) { s->failed_pc=0x0c03a01au; return 0; }
r[0]=code_base|0x0003a064u;
goto P_0c03a01c;
P_0c03a01c: /* original f108, guest PC 0x0c03a01c */
if(!s->budget--) { s->failed_pc=0x0c03a01cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a01e;
P_0c03a01e: /* original f35c, guest PC 0x0c03a01e */
if(!s->budget--) { s->failed_pc=0x0c03a01eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03a020;
P_0c03a020: /* original f370, guest PC 0x0c03a020 */
if(!s->budget--) { s->failed_pc=0x0c03a020u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c03a022;
P_0c03a022: /* original f322, guest PC 0x0c03a022 */
if(!s->budget--) { s->failed_pc=0x0c03a022u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a024;
P_0c03a024: /* original f373, guest PC 0x0c03a024 */
if(!s->budget--) { s->failed_pc=0x0c03a024u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'/');
goto P_0c03a026;
P_0c03a026: /* original f310, guest PC 0x0c03a026 */
if(!s->budget--) { s->failed_pc=0x0c03a026u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'+');
goto P_0c03a028;
P_0c03a028: /* original f33d, guest PC 0x0c03a028 */
if(!s->budget--) { s->failed_pc=0x0c03a028u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a02a;
P_0c03a02a: /* original 045a, guest PC 0x0c03a02a */
if(!s->budget--) { s->failed_pc=0x0c03a02au; return 0; }
r[4]=r[53];
goto P_0c03a02c;
P_0c03a02c: /* original 8f08, guest PC 0x0c03a02c */
if(!s->budget--) { s->failed_pc=0x0c03a02cu; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(!cond) { goto P_0c03a040; }
goto P_0c03a030;
P_0c03a02e: /* original 2439, guest PC 0x0c03a02e */
if(!s->budget--) { s->failed_pc=0x0c03a02eu; return 0; }
r[4]&=r[3];
goto P_0c03a030;
P_0c03a030: /* original 9011, guest PC 0x0c03a030 */
if(!s->budget--) { s->failed_pc=0x0c03a030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a056u,2);
goto P_0c03a032;
P_0c03a032: /* original a00a, guest PC 0x0c03a032 */
if(!s->budget--) { s->failed_pc=0x0c03a032u; return 0; }
goto P_0c03a04a;
P_0c03a034: /* original 0009, guest PC 0x0c03a034 */
if(!s->budget--) { s->failed_pc=0x0c03a034u; return 0; }
if(!vf3_matrix_family(0x0c03a036u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a036u; return 0; } return 1;
P_0c03a040: /* original c70a, guest PC 0x0c03a040 */
if(!s->budget--) { s->failed_pc=0x0c03a040u; return 0; }
r[0]=code_base|0x0003a06cu;
goto P_0c03a042;
P_0c03a042: /* original f308, guest PC 0x0c03a042 */
if(!s->budget--) { s->failed_pc=0x0c03a042u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a044;
P_0c03a044: /* original f345, guest PC 0x0c03a044 */
if(!s->budget--) { s->failed_pc=0x0c03a044u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c03a046;
P_0c03a046: /* original 8b03, guest PC 0x0c03a046 */
if(!s->budget--) { s->failed_pc=0x0c03a046u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c03a050u,s,ram); }
goto P_0c03a048;
P_0c03a048: /* original d003, guest PC 0x0c03a048 */
if(!s->budget--) { s->failed_pc=0x0c03a048u; return 0; }
r[0]=read(ram,0x0c03a058u,4);
goto P_0c03a04a;
P_0c03a04a: /* original 3048, guest PC 0x0c03a04a */
if(!s->budget--) { s->failed_pc=0x0c03a04au; return 0; }
r[0]-=r[4];
goto P_0c03a04c;
P_0c03a04c: /* original 000b, guest PC 0x0c03a04c */
if(!s->budget--) { s->failed_pc=0x0c03a04cu; return 0; }
target=r[16];
r[0]=r[0]&65535u;
s->pc=target; return ram->oob==0;
P_0c03a04e: /* original 600d, guest PC 0x0c03a04e */
if(!s->budget--) { s->failed_pc=0x0c03a04eu; return 0; }
r[0]=r[0]&65535u;
return vf3_matrix_family(0x0c03a050u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
