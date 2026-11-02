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
int vf3_away_batch98_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c038fe0u: goto P_0c038fe0;
case 0x0c038fe2u: goto P_0c038fe2;
case 0x0c038fe4u: goto P_0c038fe4;
case 0x0c038fe6u: goto P_0c038fe6;
case 0x0c038fe8u: goto P_0c038fe8;
case 0x0c038feau: goto P_0c038fea;
case 0x0c038fecu: goto P_0c038fec;
case 0x0c038feeu: goto P_0c038fee;
case 0x0c038ff0u: goto P_0c038ff0;
case 0x0c038ff2u: goto P_0c038ff2;
case 0x0c038ff4u: goto P_0c038ff4;
case 0x0c038ff6u: goto P_0c038ff6;
case 0x0c038ff8u: goto P_0c038ff8;
case 0x0c038ffau: goto P_0c038ffa;
case 0x0c038ffcu: goto P_0c038ffc;
case 0x0c038ffeu: goto P_0c038ffe;
case 0x0c039000u: goto P_0c039000;
case 0x0c039002u: goto P_0c039002;
case 0x0c039004u: goto P_0c039004;
case 0x0c039006u: goto P_0c039006;
case 0x0c039008u: goto P_0c039008;
case 0x0c03900au: goto P_0c03900a;
case 0x0c03900cu: goto P_0c03900c;
case 0x0c03900eu: goto P_0c03900e;
case 0x0c039010u: goto P_0c039010;
case 0x0c039012u: goto P_0c039012;
case 0x0c039014u: goto P_0c039014;
case 0x0c039016u: goto P_0c039016;
case 0x0c039018u: goto P_0c039018;
case 0x0c03901au: goto P_0c03901a;
case 0x0c03901cu: goto P_0c03901c;
case 0x0c03901eu: goto P_0c03901e;
case 0x0c039020u: goto P_0c039020;
case 0x0c039022u: goto P_0c039022;
case 0x0c039024u: goto P_0c039024;
case 0x0c039030u: goto P_0c039030;
case 0x0c039032u: goto P_0c039032;
case 0x0c039034u: goto P_0c039034;
case 0x0c039036u: goto P_0c039036;
case 0x0c039038u: goto P_0c039038;
case 0x0c03903au: goto P_0c03903a;
case 0x0c03903cu: goto P_0c03903c;
case 0x0c03903eu: goto P_0c03903e;
case 0x0c039040u: goto P_0c039040;
case 0x0c039042u: goto P_0c039042;
case 0x0c039044u: goto P_0c039044;
case 0x0c039046u: goto P_0c039046;
case 0x0c039048u: goto P_0c039048;
case 0x0c03904au: goto P_0c03904a;
case 0x0c03904cu: goto P_0c03904c;
case 0x0c03904eu: goto P_0c03904e;
case 0x0c039050u: goto P_0c039050;
case 0x0c039052u: goto P_0c039052;
case 0x0c039054u: goto P_0c039054;
case 0x0c039056u: goto P_0c039056;
case 0x0c039058u: goto P_0c039058;
case 0x0c03905au: goto P_0c03905a;
case 0x0c03905cu: goto P_0c03905c;
case 0x0c03905eu: goto P_0c03905e;
case 0x0c039060u: goto P_0c039060;
case 0x0c039062u: goto P_0c039062;
case 0x0c039064u: goto P_0c039064;
case 0x0c039066u: goto P_0c039066;
case 0x0c039068u: goto P_0c039068;
case 0x0c03906au: goto P_0c03906a;
case 0x0c03906cu: goto P_0c03906c;
case 0x0c03906eu: goto P_0c03906e;
case 0x0c039070u: goto P_0c039070;
case 0x0c039072u: goto P_0c039072;
case 0x0c039074u: goto P_0c039074;
case 0x0c039076u: goto P_0c039076;
case 0x0c039078u: goto P_0c039078;
case 0x0c03907au: goto P_0c03907a;
case 0x0c03907cu: goto P_0c03907c;
case 0x0c03907eu: goto P_0c03907e;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c038fe0: /* original 2fc6, guest PC 0x0c038fe0 */
if(!s->budget--) { s->failed_pc=0x0c038fe0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038fe2;
P_0c038fe2: /* original e004, guest PC 0x0c038fe2 */
if(!s->budget--) { s->failed_pc=0x0c038fe2u; return 0; }
r[0]=0x00000004u;
goto P_0c038fe4;
P_0c038fe4: /* original 4f22, guest PC 0x0c038fe4 */
if(!s->budget--) { s->failed_pc=0x0c038fe4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038fe6;
P_0c038fe6: /* original d74c, guest PC 0x0c038fe6 */
if(!s->budget--) { s->failed_pc=0x0c038fe6u; return 0; }
r[7]=read(ram,0x0c039118u,4);
goto P_0c038fe8;
P_0c038fe8: /* original 7f94, guest PC 0x0c038fe8 */
if(!s->budget--) { s->failed_pc=0x0c038fe8u; return 0; }
r[15]+=0xffffff94u;
goto P_0c038fea;
P_0c038fea: /* original 2742, guest PC 0x0c038fea */
if(!s->budget--) { s->failed_pc=0x0c038feau; return 0; }
write(ram,r[7],r[4],4);
goto P_0c038fec;
P_0c038fec: /* original 1751, guest PC 0x0c038fec */
if(!s->budget--) { s->failed_pc=0x0c038fecu; return 0; }
write(ram,r[7]+4,r[5],4);
goto P_0c038fee;
P_0c038fee: /* original 1762, guest PC 0x0c038fee */
if(!s->budget--) { s->failed_pc=0x0c038feeu; return 0; }
write(ram,r[7]+8,r[6],4);
goto P_0c038ff0;
P_0c038ff0: /* original 67f3, guest PC 0x0c038ff0 */
if(!s->budget--) { s->failed_pc=0x0c038ff0u; return 0; }
r[7]=r[15];
goto P_0c038ff2;
P_0c038ff2: /* original 770c, guest PC 0x0c038ff2 */
if(!s->budget--) { s->failed_pc=0x0c038ff2u; return 0; }
r[7]+=0x0000000cu;
goto P_0c038ff4;
P_0c038ff4: /* original d349, guest PC 0x0c038ff4 */
if(!s->budget--) { s->failed_pc=0x0c038ff4u; return 0; }
r[3]=read(ram,0x0c03911cu,4);
goto P_0c038ff6;
P_0c038ff6: /* original 6273, guest PC 0x0c038ff6 */
if(!s->budget--) { s->failed_pc=0x0c038ff6u; return 0; }
r[2]=r[7];
goto P_0c038ff8;
P_0c038ff8: /* original 6123, guest PC 0x0c038ff8 */
if(!s->budget--) { s->failed_pc=0x0c038ff8u; return 0; }
r[1]=r[2];
goto P_0c038ffa;
P_0c038ffa: /* original 7120, guest PC 0x0c038ffa */
if(!s->budget--) { s->failed_pc=0x0c038ffau; return 0; }
r[1]+=0x00000020u;
goto P_0c038ffc;
P_0c038ffc: /* original 2232, guest PC 0x0c038ffc */
if(!s->budget--) { s->failed_pc=0x0c038ffcu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c038ffe;
P_0c038ffe: /* original f48d, guest PC 0x0c038ffe */
if(!s->budget--) { s->failed_pc=0x0c038ffeu; return 0; }
fr[4]=0;
goto P_0c039000;
P_0c039000: /* original f247, guest PC 0x0c039000 */
if(!s->budget--) { s->failed_pc=0x0c039000u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039002;
P_0c039002: /* original e008, guest PC 0x0c039002 */
if(!s->budget--) { s->failed_pc=0x0c039002u; return 0; }
r[0]=0x00000008u;
goto P_0c039004;
P_0c039004: /* original f247, guest PC 0x0c039004 */
if(!s->budget--) { s->failed_pc=0x0c039004u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039006;
P_0c039006: /* original c746, guest PC 0x0c039006 */
if(!s->budget--) { s->failed_pc=0x0c039006u; return 0; }
r[0]=code_base|0x00039120u;
goto P_0c039008;
P_0c039008: /* original f508, guest PC 0x0c039008 */
if(!s->budget--) { s->failed_pc=0x0c039008u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03900a;
P_0c03900a: /* original e00c, guest PC 0x0c03900a */
if(!s->budget--) { s->failed_pc=0x0c03900au; return 0; }
r[0]=0x0000000cu;
goto P_0c03900c;
P_0c03900c: /* original f257, guest PC 0x0c03900c */
if(!s->budget--) { s->failed_pc=0x0c03900cu; return 0; }
vf3_matrix_store(s,ram,5,r[2]+r[0]);
goto P_0c03900e;
P_0c03900e: /* original 1244, guest PC 0x0c03900e */
if(!s->budget--) { s->failed_pc=0x0c03900eu; return 0; }
write(ram,r[2]+16,r[4],4);
goto P_0c039010;
P_0c039010: /* original 1246, guest PC 0x0c039010 */
if(!s->budget--) { s->failed_pc=0x0c039010u; return 0; }
write(ram,r[2]+24,r[4],4);
goto P_0c039012;
P_0c039012: /* original 2132, guest PC 0x0c039012 */
if(!s->budget--) { s->failed_pc=0x0c039012u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c039014;
P_0c039014: /* original dc43, guest PC 0x0c039014 */
if(!s->budget--) { s->failed_pc=0x0c039014u; return 0; }
r[12]=read(ram,0x0c039124u,4);
goto P_0c039016;
P_0c039016: /* original 85c2, guest PC 0x0c039016 */
if(!s->budget--) { s->failed_pc=0x0c039016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+4,2);
goto P_0c039018;
P_0c039018: /* original 6403, guest PC 0x0c039018 */
if(!s->budget--) { s->failed_pc=0x0c039018u; return 0; }
r[4]=r[0];
goto P_0c03901a;
P_0c03901a: /* original 85c5, guest PC 0x0c03901a */
if(!s->budget--) { s->failed_pc=0x0c03901au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+10,2);
goto P_0c03901c;
P_0c03901c: /* original 2008, guest PC 0x0c03901c */
if(!s->budget--) { s->failed_pc=0x0c03901cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03901e;
P_0c03901e: /* original 8907, guest PC 0x0c03901e */
if(!s->budget--) { s->failed_pc=0x0c03901eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039030; }
goto P_0c039020;
P_0c039020: /* original 644f, guest PC 0x0c039020 */
if(!s->budget--) { s->failed_pc=0x0c039020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039022;
P_0c039022: /* original a006, guest PC 0x0c039022 */
if(!s->budget--) { s->failed_pc=0x0c039022u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c039032;
P_0c039024: /* original 4400, guest PC 0x0c039024 */
if(!s->budget--) { s->failed_pc=0x0c039024u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
if(!vf3_matrix_family(0x0c039026u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039026u; return 0; } return 1;
P_0c039030: /* original 644f, guest PC 0x0c039030 */
if(!s->budget--) { s->failed_pc=0x0c039030u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039032;
P_0c039032: /* original 445a, guest PC 0x0c039032 */
if(!s->budget--) { s->failed_pc=0x0c039032u; return 0; }
r[53]=r[4];
goto P_0c039034;
P_0c039034: /* original e004, guest PC 0x0c039034 */
if(!s->budget--) { s->failed_pc=0x0c039034u; return 0; }
r[0]=0x00000004u;
goto P_0c039036;
P_0c039036: /* original 6473, guest PC 0x0c039036 */
if(!s->budget--) { s->failed_pc=0x0c039036u; return 0; }
r[4]=r[7];
goto P_0c039038;
P_0c039038: /* original 7440, guest PC 0x0c039038 */
if(!s->budget--) { s->failed_pc=0x0c039038u; return 0; }
r[4]+=0x00000040u;
goto P_0c03903a;
P_0c03903a: /* original f32d, guest PC 0x0c03903a */
if(!s->budget--) { s->failed_pc=0x0c03903au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03903c;
P_0c03903c: /* original f137, guest PC 0x0c03903c */
if(!s->budget--) { s->failed_pc=0x0c03903cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]+r[0]);
goto P_0c03903e;
P_0c03903e: /* original e008, guest PC 0x0c03903e */
if(!s->budget--) { s->failed_pc=0x0c03903eu; return 0; }
r[0]=0x00000008u;
goto P_0c039040;
P_0c039040: /* original f147, guest PC 0x0c039040 */
if(!s->budget--) { s->failed_pc=0x0c039040u; return 0; }
vf3_matrix_store(s,ram,4,r[1]+r[0]);
goto P_0c039042;
P_0c039042: /* original e00c, guest PC 0x0c039042 */
if(!s->budget--) { s->failed_pc=0x0c039042u; return 0; }
r[0]=0x0000000cu;
goto P_0c039044;
P_0c039044: /* original f157, guest PC 0x0c039044 */
if(!s->budget--) { s->failed_pc=0x0c039044u; return 0; }
vf3_matrix_store(s,ram,5,r[1]+r[0]);
goto P_0c039046;
P_0c039046: /* original e004, guest PC 0x0c039046 */
if(!s->budget--) { s->failed_pc=0x0c039046u; return 0; }
r[0]=0x00000004u;
goto P_0c039048;
P_0c039048: /* original 1154, guest PC 0x0c039048 */
if(!s->budget--) { s->failed_pc=0x0c039048u; return 0; }
write(ram,r[1]+16,r[5],4);
goto P_0c03904a;
P_0c03904a: /* original 1156, guest PC 0x0c03904a */
if(!s->budget--) { s->failed_pc=0x0c03904au; return 0; }
write(ram,r[1]+24,r[5],4);
goto P_0c03904c;
P_0c03904c: /* original e500, guest PC 0x0c03904c */
if(!s->budget--) { s->failed_pc=0x0c03904cu; return 0; }
r[5]=0x00000000u;
goto P_0c03904e;
P_0c03904e: /* original d336, guest PC 0x0c03904e */
if(!s->budget--) { s->failed_pc=0x0c03904eu; return 0; }
r[3]=read(ram,0x0c039128u,4);
goto P_0c039050;
P_0c039050: /* original 2432, guest PC 0x0c039050 */
if(!s->budget--) { s->failed_pc=0x0c039050u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c039052;
P_0c039052: /* original f447, guest PC 0x0c039052 */
if(!s->budget--) { s->failed_pc=0x0c039052u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c039054;
P_0c039054: /* original 85c3, guest PC 0x0c039054 */
if(!s->budget--) { s->failed_pc=0x0c039054u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c039056;
P_0c039056: /* original 6cf3, guest PC 0x0c039056 */
if(!s->budget--) { s->failed_pc=0x0c039056u; return 0; }
r[12]=r[15];
goto P_0c039058;
P_0c039058: /* original 6303, guest PC 0x0c039058 */
if(!s->budget--) { s->failed_pc=0x0c039058u; return 0; }
r[3]=r[0];
goto P_0c03905a;
P_0c03905a: /* original 435a, guest PC 0x0c03905a */
if(!s->budget--) { s->failed_pc=0x0c03905au; return 0; }
r[53]=r[3];
goto P_0c03905c;
P_0c03905c: /* original e008, guest PC 0x0c03905c */
if(!s->budget--) { s->failed_pc=0x0c03905cu; return 0; }
r[0]=0x00000008u;
goto P_0c03905e;
P_0c03905e: /* original f32d, guest PC 0x0c03905e */
if(!s->budget--) { s->failed_pc=0x0c03905eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039060;
P_0c039060: /* original f437, guest PC 0x0c039060 */
if(!s->budget--) { s->failed_pc=0x0c039060u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c039062;
P_0c039062: /* original e00c, guest PC 0x0c039062 */
if(!s->budget--) { s->failed_pc=0x0c039062u; return 0; }
r[0]=0x0000000cu;
goto P_0c039064;
P_0c039064: /* original f457, guest PC 0x0c039064 */
if(!s->budget--) { s->failed_pc=0x0c039064u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c039066;
P_0c039066: /* original 1464, guest PC 0x0c039066 */
if(!s->budget--) { s->failed_pc=0x0c039066u; return 0; }
write(ram,r[4]+16,r[6],4);
goto P_0c039068;
P_0c039068: /* original 1466, guest PC 0x0c039068 */
if(!s->budget--) { s->failed_pc=0x0c039068u; return 0; }
write(ram,r[4]+24,r[6],4);
goto P_0c03906a;
P_0c03906a: /* original e620, guest PC 0x0c03906a */
if(!s->budget--) { s->failed_pc=0x0c03906au; return 0; }
r[6]=0x00000020u;
goto P_0c03906c;
P_0c03906c: /* original 2c22, guest PC 0x0c03906c */
if(!s->budget--) { s->failed_pc=0x0c03906cu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c03906e;
P_0c03906e: /* original 1c11, guest PC 0x0c03906e */
if(!s->budget--) { s->failed_pc=0x0c03906eu; return 0; }
write(ram,r[12]+4,r[1],4);
goto P_0c039070;
P_0c039070: /* original 1c42, guest PC 0x0c039070 */
if(!s->budget--) { s->failed_pc=0x0c039070u; return 0; }
write(ram,r[12]+8,r[4],4);
goto P_0c039072;
P_0c039072: /* original d32e, guest PC 0x0c039072 */
if(!s->budget--) { s->failed_pc=0x0c039072u; return 0; }
r[3]=read(ram,0x0c03912cu,4);
goto P_0c039074;
P_0c039074: /* original 430b, guest PC 0x0c039074 */
if(!s->budget--) { s->failed_pc=0x0c039074u; return 0; }
target=r[3];
r[16]=code_base|0x0c039078u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039078u) { target=s->pc; goto dispatch; }
goto P_0c039078;
P_0c039076: /* original 64c3, guest PC 0x0c039076 */
if(!s->budget--) { s->failed_pc=0x0c039076u; return 0; }
r[4]=r[12];
goto P_0c039078;
P_0c039078: /* original 7f6c, guest PC 0x0c039078 */
if(!s->budget--) { s->failed_pc=0x0c039078u; return 0; }
r[15]+=0x0000006cu;
goto P_0c03907a;
P_0c03907a: /* original 4f26, guest PC 0x0c03907a */
if(!s->budget--) { s->failed_pc=0x0c03907au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03907c;
P_0c03907c: /* original 000b, guest PC 0x0c03907c */
if(!s->budget--) { s->failed_pc=0x0c03907cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c03907e: /* original 6cf6, guest PC 0x0c03907e */
if(!s->budget--) { s->failed_pc=0x0c03907eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
if(!vf3_matrix_family(0x0c039080u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039080u; return 0; } return 1;
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
return vf3_matrix_family(0x0c0396c0u,s,ram);
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
unsupported: s->failed_pc=target; return 0;
}
