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
int vf3_away_batch14_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0875b0u: goto P_0c0875b0;
case 0x0c0875b2u: goto P_0c0875b2;
case 0x0c0875b4u: goto P_0c0875b4;
case 0x0c0875b6u: goto P_0c0875b6;
case 0x0c0875b8u: goto P_0c0875b8;
case 0x0c0875bau: goto P_0c0875ba;
case 0x0c0875bcu: goto P_0c0875bc;
case 0x0c0875beu: goto P_0c0875be;
case 0x0c0875c0u: goto P_0c0875c0;
case 0x0c0875c2u: goto P_0c0875c2;
case 0x0c0875c4u: goto P_0c0875c4;
case 0x0c0875c6u: goto P_0c0875c6;
case 0x0c0875c8u: goto P_0c0875c8;
case 0x0c0875cau: goto P_0c0875ca;
case 0x0c0875ccu: goto P_0c0875cc;
case 0x0c0875ceu: goto P_0c0875ce;
case 0x0c0875d0u: goto P_0c0875d0;
case 0x0c0875d2u: goto P_0c0875d2;
case 0x0c0875d4u: goto P_0c0875d4;
case 0x0c0875d6u: goto P_0c0875d6;
case 0x0c0875d8u: goto P_0c0875d8;
case 0x0c0875dau: goto P_0c0875da;
case 0x0c0875dcu: goto P_0c0875dc;
case 0x0c0875deu: goto P_0c0875de;
case 0x0c0875e0u: goto P_0c0875e0;
case 0x0c0875e2u: goto P_0c0875e2;
case 0x0c0875e4u: goto P_0c0875e4;
case 0x0c0875e6u: goto P_0c0875e6;
case 0x0c0875e8u: goto P_0c0875e8;
case 0x0c0875eau: goto P_0c0875ea;
case 0x0c0875ecu: goto P_0c0875ec;
case 0x0c0875eeu: goto P_0c0875ee;
case 0x0c0875f0u: goto P_0c0875f0;
case 0x0c0875f2u: goto P_0c0875f2;
case 0x0c0875f4u: goto P_0c0875f4;
case 0x0c0875f6u: goto P_0c0875f6;
case 0x0c0875f8u: goto P_0c0875f8;
case 0x0c0875fau: goto P_0c0875fa;
case 0x0c0875fcu: goto P_0c0875fc;
case 0x0c0875feu: goto P_0c0875fe;
case 0x0c087600u: goto P_0c087600;
case 0x0c087602u: goto P_0c087602;
case 0x0c087604u: goto P_0c087604;
case 0x0c087606u: goto P_0c087606;
case 0x0c087608u: goto P_0c087608;
case 0x0c08760au: goto P_0c08760a;
case 0x0c08760cu: goto P_0c08760c;
case 0x0c08760eu: goto P_0c08760e;
case 0x0c087610u: goto P_0c087610;
case 0x0c087612u: goto P_0c087612;
case 0x0c087614u: goto P_0c087614;
case 0x0c087616u: goto P_0c087616;
case 0x0c087618u: goto P_0c087618;
case 0x0c08761au: goto P_0c08761a;
case 0x0c08761cu: goto P_0c08761c;
case 0x0c08761eu: goto P_0c08761e;
case 0x0c087620u: goto P_0c087620;
case 0x0c087622u: goto P_0c087622;
case 0x0c087624u: goto P_0c087624;
case 0x0c087626u: goto P_0c087626;
case 0x0c087628u: goto P_0c087628;
case 0x0c08762au: goto P_0c08762a;
case 0x0c08762cu: goto P_0c08762c;
case 0x0c08762eu: goto P_0c08762e;
case 0x0c087630u: goto P_0c087630;
case 0x0c087632u: goto P_0c087632;
case 0x0c087634u: goto P_0c087634;
case 0x0c087636u: goto P_0c087636;
case 0x0c087638u: goto P_0c087638;
case 0x0c08763au: goto P_0c08763a;
case 0x0c08763cu: goto P_0c08763c;
case 0x0c08763eu: goto P_0c08763e;
case 0x0c087640u: goto P_0c087640;
case 0x0c087642u: goto P_0c087642;
case 0x0c087644u: goto P_0c087644;
case 0x0c087646u: goto P_0c087646;
case 0x0c087648u: goto P_0c087648;
case 0x0c08764au: goto P_0c08764a;
case 0x0c08764cu: goto P_0c08764c;
case 0x0c08764eu: goto P_0c08764e;
case 0x0c087650u: goto P_0c087650;
case 0x0c087652u: goto P_0c087652;
case 0x0c087654u: goto P_0c087654;
case 0x0c087656u: goto P_0c087656;
case 0x0c087658u: goto P_0c087658;
case 0x0c08765au: goto P_0c08765a;
case 0x0c08765cu: goto P_0c08765c;
case 0x0c08765eu: goto P_0c08765e;
case 0x0c087660u: goto P_0c087660;
case 0x0c087662u: goto P_0c087662;
case 0x0c087664u: goto P_0c087664;
case 0x0c087666u: goto P_0c087666;
case 0x0c087668u: goto P_0c087668;
case 0x0c08766au: goto P_0c08766a;
case 0x0c08766cu: goto P_0c08766c;
case 0x0c08766eu: goto P_0c08766e;
case 0x0c087670u: goto P_0c087670;
case 0x0c087672u: goto P_0c087672;
case 0x0c087674u: goto P_0c087674;
case 0x0c087676u: goto P_0c087676;
case 0x0c087678u: goto P_0c087678;
case 0x0c08767au: goto P_0c08767a;
case 0x0c08767cu: goto P_0c08767c;
case 0x0c08767eu: goto P_0c08767e;
case 0x0c087680u: goto P_0c087680;
case 0x0c087682u: goto P_0c087682;
case 0x0c087684u: goto P_0c087684;
case 0x0c087686u: goto P_0c087686;
case 0x0c087688u: goto P_0c087688;
case 0x0c08768au: goto P_0c08768a;
case 0x0c08768cu: goto P_0c08768c;
case 0x0c08768eu: goto P_0c08768e;
case 0x0c087690u: goto P_0c087690;
case 0x0c087692u: goto P_0c087692;
case 0x0c087694u: goto P_0c087694;
case 0x0c087696u: goto P_0c087696;
case 0x0c087698u: goto P_0c087698;
case 0x0c08769au: goto P_0c08769a;
case 0x0c08769cu: goto P_0c08769c;
case 0x0c08769eu: goto P_0c08769e;
case 0x0c0876a0u: goto P_0c0876a0;
case 0x0c0876a2u: goto P_0c0876a2;
case 0x0c0876a4u: goto P_0c0876a4;
case 0x0c0876a6u: goto P_0c0876a6;
case 0x0c0876a8u: goto P_0c0876a8;
case 0x0c0876aau: goto P_0c0876aa;
case 0x0c0876acu: goto P_0c0876ac;
case 0x0c0876aeu: goto P_0c0876ae;
case 0x0c0876b0u: goto P_0c0876b0;
case 0x0c0876b2u: goto P_0c0876b2;
case 0x0c0876b4u: goto P_0c0876b4;
case 0x0c0876b6u: goto P_0c0876b6;
case 0x0c0876b8u: goto P_0c0876b8;
case 0x0c0876bau: goto P_0c0876ba;
case 0x0c0876bcu: goto P_0c0876bc;
case 0x0c0876beu: goto P_0c0876be;
case 0x0c0876c0u: goto P_0c0876c0;
case 0x0c0876c2u: goto P_0c0876c2;
case 0x0c0876c4u: goto P_0c0876c4;
case 0x0c0876c6u: goto P_0c0876c6;
case 0x0c0876c8u: goto P_0c0876c8;
case 0x0c0876cau: goto P_0c0876ca;
case 0x0c0876ccu: goto P_0c0876cc;
case 0x0c0876ceu: goto P_0c0876ce;
case 0x0c0876d0u: goto P_0c0876d0;
case 0x0c0876d2u: goto P_0c0876d2;
case 0x0c0876d4u: goto P_0c0876d4;
case 0x0c0876d6u: goto P_0c0876d6;
case 0x0c0876d8u: goto P_0c0876d8;
case 0x0c0876dau: goto P_0c0876da;
case 0x0c0876dcu: goto P_0c0876dc;
case 0x0c0876deu: goto P_0c0876de;
case 0x0c0876e0u: goto P_0c0876e0;
case 0x0c0876e2u: goto P_0c0876e2;
case 0x0c0876e4u: goto P_0c0876e4;
case 0x0c0876e6u: goto P_0c0876e6;
case 0x0c0876e8u: goto P_0c0876e8;
case 0x0c0876eau: goto P_0c0876ea;
case 0x0c0876ecu: goto P_0c0876ec;
case 0x0c0876eeu: goto P_0c0876ee;
case 0x0c0876f0u: goto P_0c0876f0;
case 0x0c0876f2u: goto P_0c0876f2;
case 0x0c0876f4u: goto P_0c0876f4;
case 0x0c0876f6u: goto P_0c0876f6;
case 0x0c0876f8u: goto P_0c0876f8;
case 0x0c0876fau: goto P_0c0876fa;
case 0x0c0876fcu: goto P_0c0876fc;
case 0x0c0876feu: goto P_0c0876fe;
case 0x0c087700u: goto P_0c087700;
case 0x0c087702u: goto P_0c087702;
case 0x0c087704u: goto P_0c087704;
case 0x0c087706u: goto P_0c087706;
case 0x0c087708u: goto P_0c087708;
case 0x0c08770au: goto P_0c08770a;
case 0x0c08770cu: goto P_0c08770c;
case 0x0c08770eu: goto P_0c08770e;
case 0x0c087710u: goto P_0c087710;
case 0x0c087712u: goto P_0c087712;
case 0x0c087714u: goto P_0c087714;
case 0x0c087716u: goto P_0c087716;
case 0x0c087718u: goto P_0c087718;
case 0x0c08771au: goto P_0c08771a;
case 0x0c08771cu: goto P_0c08771c;
case 0x0c08771eu: goto P_0c08771e;
case 0x0c087720u: goto P_0c087720;
case 0x0c087722u: goto P_0c087722;
case 0x0c087724u: goto P_0c087724;
case 0x0c087726u: goto P_0c087726;
case 0x0c087728u: goto P_0c087728;
case 0x0c08772au: goto P_0c08772a;
case 0x0c08772cu: goto P_0c08772c;
case 0x0c08772eu: goto P_0c08772e;
case 0x0c087730u: goto P_0c087730;
case 0x0c087732u: goto P_0c087732;
case 0x0c087734u: goto P_0c087734;
case 0x0c087736u: goto P_0c087736;
case 0x0c087738u: goto P_0c087738;
case 0x0c08773au: goto P_0c08773a;
case 0x0c08773cu: goto P_0c08773c;
case 0x0c08773eu: goto P_0c08773e;
case 0x0c087740u: goto P_0c087740;
case 0x0c087742u: goto P_0c087742;
case 0x0c087744u: goto P_0c087744;
case 0x0c087746u: goto P_0c087746;
case 0x0c087748u: goto P_0c087748;
case 0x0c08774au: goto P_0c08774a;
case 0x0c08774cu: goto P_0c08774c;
case 0x0c08774eu: goto P_0c08774e;
case 0x0c087750u: goto P_0c087750;
case 0x0c087752u: goto P_0c087752;
case 0x0c087754u: goto P_0c087754;
case 0x0c087756u: goto P_0c087756;
case 0x0c087758u: goto P_0c087758;
case 0x0c08775au: goto P_0c08775a;
case 0x0c08775cu: goto P_0c08775c;
case 0x0c08775eu: goto P_0c08775e;
case 0x0c087760u: goto P_0c087760;
case 0x0c087762u: goto P_0c087762;
case 0x0c087764u: goto P_0c087764;
case 0x0c087766u: goto P_0c087766;
case 0x0c087768u: goto P_0c087768;
case 0x0c08776au: goto P_0c08776a;
case 0x0c08776cu: goto P_0c08776c;
case 0x0c08776eu: goto P_0c08776e;
case 0x0c087770u: goto P_0c087770;
case 0x0c087772u: goto P_0c087772;
case 0x0c087774u: goto P_0c087774;
case 0x0c087776u: goto P_0c087776;
case 0x0c087778u: goto P_0c087778;
case 0x0c08777au: goto P_0c08777a;
case 0x0c08777cu: goto P_0c08777c;
case 0x0c08777eu: goto P_0c08777e;
case 0x0c087780u: goto P_0c087780;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0875b0: /* original 364c, guest PC 0x0c0875b0 */
if(!s->budget--) { s->failed_pc=0x0c0875b0u; return 0; }
r[6]+=r[4];
goto P_0c0875b2;
P_0c0875b2: /* original e0ff, guest PC 0x0c0875b2 */
if(!s->budget--) { s->failed_pc=0x0c0875b2u; return 0; }
r[0]=0xffffffffu;
goto P_0c0875b4;
P_0c0875b4: /* original 2402, guest PC 0x0c0875b4 */
if(!s->budget--) { s->failed_pc=0x0c0875b4u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c0875b6;
P_0c0875b6: /* original 1461, guest PC 0x0c0875b6 */
if(!s->budget--) { s->failed_pc=0x0c0875b6u; return 0; }
write(ram,r[4]+4,r[6],4);
goto P_0c0875b8;
P_0c0875b8: /* original 6463, guest PC 0x0c0875b8 */
if(!s->budget--) { s->failed_pc=0x0c0875b8u; return 0; }
r[4]=r[6];
goto P_0c0875ba;
P_0c0875ba: /* original 345c, guest PC 0x0c0875ba */
if(!s->budget--) { s->failed_pc=0x0c0875bau; return 0; }
r[4]+=r[5];
goto P_0c0875bc;
P_0c0875bc: /* original 2778, guest PC 0x0c0875bc */
if(!s->budget--) { s->failed_pc=0x0c0875bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0875be;
P_0c0875be: /* original 2642, guest PC 0x0c0875be */
if(!s->budget--) { s->failed_pc=0x0c0875beu; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0875c0;
P_0c0875c0: /* original 8d02, guest PC 0x0c0875c0 */
if(!s->budget--) { s->failed_pc=0x0c0875c0u; return 0; }
cond=r[17]&1u;
r[6]+=r[5];
if(cond) { goto P_0c0875c8; }
goto P_0c0875c4;
P_0c0875c2: /* original 365c, guest PC 0x0c0875c2 */
if(!s->budget--) { s->failed_pc=0x0c0875c2u; return 0; }
r[6]+=r[5];
goto P_0c0875c4;
P_0c0875c4: /* original aff9, guest PC 0x0c0875c4 */
if(!s->budget--) { s->failed_pc=0x0c0875c4u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0875ba;
P_0c0875c6: /* original 77ff, guest PC 0x0c0875c6 */
if(!s->budget--) { s->failed_pc=0x0c0875c6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0875c8;
P_0c0875c8: /* original 2602, guest PC 0x0c0875c8 */
if(!s->budget--) { s->failed_pc=0x0c0875c8u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c0875ca;
P_0c0875ca: /* original 000b, guest PC 0x0c0875ca */
if(!s->budget--) { s->failed_pc=0x0c0875cau; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c0875cc: /* original 6063, guest PC 0x0c0875cc */
if(!s->budget--) { s->failed_pc=0x0c0875ccu; return 0; }
r[0]=r[6];
goto P_0c0875ce;
P_0c0875ce: /* original 5341, guest PC 0x0c0875ce */
if(!s->budget--) { s->failed_pc=0x0c0875ceu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0875d0;
P_0c0875d0: /* original 7ff8, guest PC 0x0c0875d0 */
if(!s->budget--) { s->failed_pc=0x0c0875d0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0875d2;
P_0c0875d2: /* original 2f32, guest PC 0x0c0875d2 */
if(!s->budget--) { s->failed_pc=0x0c0875d2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0875d4;
P_0c0875d4: /* original 6752, guest PC 0x0c0875d4 */
if(!s->budget--) { s->failed_pc=0x0c0875d4u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c0875d6;
P_0c0875d6: /* original 5651, guest PC 0x0c0875d6 */
if(!s->budget--) { s->failed_pc=0x0c0875d6u; return 0; }
r[6]=read(ram,r[5]+4,4);
goto P_0c0875d8;
P_0c0875d8: /* original 6073, guest PC 0x0c0875d8 */
if(!s->budget--) { s->failed_pc=0x0c0875d8u; return 0; }
r[0]=r[7];
goto P_0c0875da;
P_0c0875da: /* original 88ff, guest PC 0x0c0875da */
if(!s->budget--) { s->failed_pc=0x0c0875dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0875dc;
P_0c0875dc: /* original 1f71, guest PC 0x0c0875dc */
if(!s->budget--) { s->failed_pc=0x0c0875dcu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0875de;
P_0c0875de: /* original 8900, guest PC 0x0c0875de */
if(!s->budget--) { s->failed_pc=0x0c0875deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0875e2; }
goto P_0c0875e0;
P_0c0875e0: /* original 1761, guest PC 0x0c0875e0 */
if(!s->budget--) { s->failed_pc=0x0c0875e0u; return 0; }
write(ram,r[7]+4,r[6],4);
goto P_0c0875e2;
P_0c0875e2: /* original 6063, guest PC 0x0c0875e2 */
if(!s->budget--) { s->failed_pc=0x0c0875e2u; return 0; }
r[0]=r[6];
goto P_0c0875e4;
P_0c0875e4: /* original 2672, guest PC 0x0c0875e4 */
if(!s->budget--) { s->failed_pc=0x0c0875e4u; return 0; }
write(ram,r[6],r[7],4);
goto P_0c0875e6;
P_0c0875e6: /* original 62f2, guest PC 0x0c0875e6 */
if(!s->budget--) { s->failed_pc=0x0c0875e6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0875e8;
P_0c0875e8: /* original 2522, guest PC 0x0c0875e8 */
if(!s->budget--) { s->failed_pc=0x0c0875e8u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0875ea;
P_0c0875ea: /* original 1451, guest PC 0x0c0875ea */
if(!s->budget--) { s->failed_pc=0x0c0875eau; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c0875ec;
P_0c0875ec: /* original 000b, guest PC 0x0c0875ec */
if(!s->budget--) { s->failed_pc=0x0c0875ecu; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c0875ee: /* original 7f08, guest PC 0x0c0875ee */
if(!s->budget--) { s->failed_pc=0x0c0875eeu; return 0; }
r[15]+=0x00000008u;
goto P_0c0875f0;
P_0c0875f0: /* original 4f22, guest PC 0x0c0875f0 */
if(!s->budget--) { s->failed_pc=0x0c0875f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0875f2;
P_0c0875f2: /* original 90c6, guest PC 0x0c0875f2 */
if(!s->budget--) { s->failed_pc=0x0c0875f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087782u,2);
goto P_0c0875f4;
P_0c0875f4: /* original 3f0c, guest PC 0x0c0875f4 */
if(!s->budget--) { s->failed_pc=0x0c0875f4u; return 0; }
r[15]+=r[0];
goto P_0c0875f6;
P_0c0875f6: /* original 2f42, guest PC 0x0c0875f6 */
if(!s->budget--) { s->failed_pc=0x0c0875f6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0875f8;
P_0c0875f8: /* original 64f3, guest PC 0x0c0875f8 */
if(!s->budget--) { s->failed_pc=0x0c0875f8u; return 0; }
r[4]=r[15];
goto P_0c0875fa;
P_0c0875fa: /* original d363, guest PC 0x0c0875fa */
if(!s->budget--) { s->failed_pc=0x0c0875fau; return 0; }
r[3]=read(ram,0x0c087788u,4);
goto P_0c0875fc;
P_0c0875fc: /* original 430b, guest PC 0x0c0875fc */
if(!s->budget--) { s->failed_pc=0x0c0875fcu; return 0; }
target=r[3];
r[16]=code_base|0x0c087600u;
r[4]+=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087600u) { target=s->pc; goto dispatch; }
goto P_0c087600;
P_0c0875fe: /* original 7444, guest PC 0x0c0875fe */
if(!s->budget--) { s->failed_pc=0x0c0875feu; return 0; }
r[4]+=0x00000044u;
goto P_0c087600;
P_0c087600: /* original d362, guest PC 0x0c087600 */
if(!s->budget--) { s->failed_pc=0x0c087600u; return 0; }
r[3]=read(ram,0x0c08778cu,4);
goto P_0c087602;
P_0c087602: /* original 430b, guest PC 0x0c087602 */
if(!s->budget--) { s->failed_pc=0x0c087602u; return 0; }
target=r[3];
r[16]=code_base|0x0c087606u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087606u) { target=s->pc; goto dispatch; }
goto P_0c087606;
P_0c087604: /* original 64f2, guest PC 0x0c087604 */
if(!s->budget--) { s->failed_pc=0x0c087604u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c087606;
P_0c087606: /* original d260, guest PC 0x0c087606 */
if(!s->budget--) { s->failed_pc=0x0c087606u; return 0; }
r[2]=read(ram,0x0c087788u,4);
goto P_0c087608;
P_0c087608: /* original 64f3, guest PC 0x0c087608 */
if(!s->budget--) { s->failed_pc=0x0c087608u; return 0; }
r[4]=r[15];
goto P_0c08760a;
P_0c08760a: /* original 420b, guest PC 0x0c08760a */
if(!s->budget--) { s->failed_pc=0x0c08760au; return 0; }
target=r[2];
r[16]=code_base|0x0c08760eu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08760eu) { target=s->pc; goto dispatch; }
goto P_0c08760e;
P_0c08760c: /* original 7404, guest PC 0x0c08760c */
if(!s->budget--) { s->failed_pc=0x0c08760cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08760e;
P_0c08760e: /* original e074, guest PC 0x0c08760e */
if(!s->budget--) { s->failed_pc=0x0c08760eu; return 0; }
r[0]=0x00000074u;
goto P_0c087610;
P_0c087610: /* original 64f3, guest PC 0x0c087610 */
if(!s->budget--) { s->failed_pc=0x0c087610u; return 0; }
r[4]=r[15];
goto P_0c087612;
P_0c087612: /* original f3f6, guest PC 0x0c087612 */
if(!s->budget--) { s->failed_pc=0x0c087612u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087614;
P_0c087614: /* original e034, guest PC 0x0c087614 */
if(!s->budget--) { s->failed_pc=0x0c087614u; return 0; }
r[0]=0x00000034u;
goto P_0c087616;
P_0c087616: /* original ff37, guest PC 0x0c087616 */
if(!s->budget--) { s->failed_pc=0x0c087616u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087618;
P_0c087618: /* original e078, guest PC 0x0c087618 */
if(!s->budget--) { s->failed_pc=0x0c087618u; return 0; }
r[0]=0x00000078u;
goto P_0c08761a;
P_0c08761a: /* original f3f6, guest PC 0x0c08761a */
if(!s->budget--) { s->failed_pc=0x0c08761au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08761c;
P_0c08761c: /* original e038, guest PC 0x0c08761c */
if(!s->budget--) { s->failed_pc=0x0c08761cu; return 0; }
r[0]=0x00000038u;
goto P_0c08761e;
P_0c08761e: /* original ff37, guest PC 0x0c08761e */
if(!s->budget--) { s->failed_pc=0x0c08761eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087620;
P_0c087620: /* original e07c, guest PC 0x0c087620 */
if(!s->budget--) { s->failed_pc=0x0c087620u; return 0; }
r[0]=0x0000007cu;
goto P_0c087622;
P_0c087622: /* original f3f6, guest PC 0x0c087622 */
if(!s->budget--) { s->failed_pc=0x0c087622u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087624;
P_0c087624: /* original e03c, guest PC 0x0c087624 */
if(!s->budget--) { s->failed_pc=0x0c087624u; return 0; }
r[0]=0x0000003cu;
goto P_0c087626;
P_0c087626: /* original ff37, guest PC 0x0c087626 */
if(!s->budget--) { s->failed_pc=0x0c087626u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087628;
P_0c087628: /* original d359, guest PC 0x0c087628 */
if(!s->budget--) { s->failed_pc=0x0c087628u; return 0; }
r[3]=read(ram,0x0c087790u,4);
goto P_0c08762a;
P_0c08762a: /* original 430b, guest PC 0x0c08762a */
if(!s->budget--) { s->failed_pc=0x0c08762au; return 0; }
target=r[3];
r[16]=code_base|0x0c08762eu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08762eu) { target=s->pc; goto dispatch; }
goto P_0c08762e;
P_0c08762c: /* original 7404, guest PC 0x0c08762c */
if(!s->budget--) { s->failed_pc=0x0c08762cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08762e;
P_0c08762e: /* original 91a9, guest PC 0x0c08762e */
if(!s->budget--) { s->failed_pc=0x0c08762eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087784u,2);
goto P_0c087630;
P_0c087630: /* original 3f1c, guest PC 0x0c087630 */
if(!s->budget--) { s->failed_pc=0x0c087630u; return 0; }
r[15]+=r[1];
goto P_0c087632;
P_0c087632: /* original 4f26, guest PC 0x0c087632 */
if(!s->budget--) { s->failed_pc=0x0c087632u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087634;
P_0c087634: /* original 000b, guest PC 0x0c087634 */
if(!s->budget--) { s->failed_pc=0x0c087634u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087636: /* original 0009, guest PC 0x0c087636 */
if(!s->budget--) { s->failed_pc=0x0c087636u; return 0; }
goto P_0c087638;
P_0c087638: /* original 2fe6, guest PC 0x0c087638 */
if(!s->budget--) { s->failed_pc=0x0c087638u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08763a;
P_0c08763a: /* original 6e43, guest PC 0x0c08763a */
if(!s->budget--) { s->failed_pc=0x0c08763au; return 0; }
r[14]=r[4];
goto P_0c08763c;
P_0c08763c: /* original 4f22, guest PC 0x0c08763c */
if(!s->budget--) { s->failed_pc=0x0c08763cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08763e;
P_0c08763e: /* original d352, guest PC 0x0c08763e */
if(!s->budget--) { s->failed_pc=0x0c08763eu; return 0; }
r[3]=read(ram,0x0c087788u,4);
goto P_0c087640;
P_0c087640: /* original 7fc0, guest PC 0x0c087640 */
if(!s->budget--) { s->failed_pc=0x0c087640u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c087642;
P_0c087642: /* original 430b, guest PC 0x0c087642 */
if(!s->budget--) { s->failed_pc=0x0c087642u; return 0; }
target=r[3];
r[16]=code_base|0x0c087646u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087646u) { target=s->pc; goto dispatch; }
goto P_0c087646;
P_0c087644: /* original 64f3, guest PC 0x0c087644 */
if(!s->budget--) { s->failed_pc=0x0c087644u; return 0; }
r[4]=r[15];
goto P_0c087646;
P_0c087646: /* original f3e8, guest PC 0x0c087646 */
if(!s->budget--) { s->failed_pc=0x0c087646u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c087648;
P_0c087648: /* original e004, guest PC 0x0c087648 */
if(!s->budget--) { s->failed_pc=0x0c087648u; return 0; }
r[0]=0x00000004u;
goto P_0c08764a;
P_0c08764a: /* original ff3a, guest PC 0x0c08764a */
if(!s->budget--) { s->failed_pc=0x0c08764au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08764c;
P_0c08764c: /* original f3e6, guest PC 0x0c08764c */
if(!s->budget--) { s->failed_pc=0x0c08764cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08764e;
P_0c08764e: /* original e004, guest PC 0x0c08764e */
if(!s->budget--) { s->failed_pc=0x0c08764eu; return 0; }
r[0]=0x00000004u;
goto P_0c087650;
P_0c087650: /* original ff37, guest PC 0x0c087650 */
if(!s->budget--) { s->failed_pc=0x0c087650u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087652;
P_0c087652: /* original e008, guest PC 0x0c087652 */
if(!s->budget--) { s->failed_pc=0x0c087652u; return 0; }
r[0]=0x00000008u;
goto P_0c087654;
P_0c087654: /* original f3e6, guest PC 0x0c087654 */
if(!s->budget--) { s->failed_pc=0x0c087654u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087656;
P_0c087656: /* original e008, guest PC 0x0c087656 */
if(!s->budget--) { s->failed_pc=0x0c087656u; return 0; }
r[0]=0x00000008u;
goto P_0c087658;
P_0c087658: /* original ff37, guest PC 0x0c087658 */
if(!s->budget--) { s->failed_pc=0x0c087658u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08765a;
P_0c08765a: /* original e010, guest PC 0x0c08765a */
if(!s->budget--) { s->failed_pc=0x0c08765au; return 0; }
r[0]=0x00000010u;
goto P_0c08765c;
P_0c08765c: /* original f3e6, guest PC 0x0c08765c */
if(!s->budget--) { s->failed_pc=0x0c08765cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08765e;
P_0c08765e: /* original e010, guest PC 0x0c08765e */
if(!s->budget--) { s->failed_pc=0x0c08765eu; return 0; }
r[0]=0x00000010u;
goto P_0c087660;
P_0c087660: /* original ff37, guest PC 0x0c087660 */
if(!s->budget--) { s->failed_pc=0x0c087660u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087662;
P_0c087662: /* original e014, guest PC 0x0c087662 */
if(!s->budget--) { s->failed_pc=0x0c087662u; return 0; }
r[0]=0x00000014u;
goto P_0c087664;
P_0c087664: /* original f3e6, guest PC 0x0c087664 */
if(!s->budget--) { s->failed_pc=0x0c087664u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087666;
P_0c087666: /* original e014, guest PC 0x0c087666 */
if(!s->budget--) { s->failed_pc=0x0c087666u; return 0; }
r[0]=0x00000014u;
goto P_0c087668;
P_0c087668: /* original ff37, guest PC 0x0c087668 */
if(!s->budget--) { s->failed_pc=0x0c087668u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08766a;
P_0c08766a: /* original e018, guest PC 0x0c08766a */
if(!s->budget--) { s->failed_pc=0x0c08766au; return 0; }
r[0]=0x00000018u;
goto P_0c08766c;
P_0c08766c: /* original f3e6, guest PC 0x0c08766c */
if(!s->budget--) { s->failed_pc=0x0c08766cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08766e;
P_0c08766e: /* original e018, guest PC 0x0c08766e */
if(!s->budget--) { s->failed_pc=0x0c08766eu; return 0; }
r[0]=0x00000018u;
goto P_0c087670;
P_0c087670: /* original ff37, guest PC 0x0c087670 */
if(!s->budget--) { s->failed_pc=0x0c087670u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087672;
P_0c087672: /* original e020, guest PC 0x0c087672 */
if(!s->budget--) { s->failed_pc=0x0c087672u; return 0; }
r[0]=0x00000020u;
goto P_0c087674;
P_0c087674: /* original f3e6, guest PC 0x0c087674 */
if(!s->budget--) { s->failed_pc=0x0c087674u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087676;
P_0c087676: /* original e020, guest PC 0x0c087676 */
if(!s->budget--) { s->failed_pc=0x0c087676u; return 0; }
r[0]=0x00000020u;
goto P_0c087678;
P_0c087678: /* original ff37, guest PC 0x0c087678 */
if(!s->budget--) { s->failed_pc=0x0c087678u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08767a;
P_0c08767a: /* original e024, guest PC 0x0c08767a */
if(!s->budget--) { s->failed_pc=0x0c08767au; return 0; }
r[0]=0x00000024u;
goto P_0c08767c;
P_0c08767c: /* original f3e6, guest PC 0x0c08767c */
if(!s->budget--) { s->failed_pc=0x0c08767cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08767e;
P_0c08767e: /* original e024, guest PC 0x0c08767e */
if(!s->budget--) { s->failed_pc=0x0c08767eu; return 0; }
r[0]=0x00000024u;
goto P_0c087680;
P_0c087680: /* original ff37, guest PC 0x0c087680 */
if(!s->budget--) { s->failed_pc=0x0c087680u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087682;
P_0c087682: /* original e028, guest PC 0x0c087682 */
if(!s->budget--) { s->failed_pc=0x0c087682u; return 0; }
r[0]=0x00000028u;
goto P_0c087684;
P_0c087684: /* original f3e6, guest PC 0x0c087684 */
if(!s->budget--) { s->failed_pc=0x0c087684u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087686;
P_0c087686: /* original e028, guest PC 0x0c087686 */
if(!s->budget--) { s->failed_pc=0x0c087686u; return 0; }
r[0]=0x00000028u;
goto P_0c087688;
P_0c087688: /* original ff37, guest PC 0x0c087688 */
if(!s->budget--) { s->failed_pc=0x0c087688u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08768a;
P_0c08768a: /* original d341, guest PC 0x0c08768a */
if(!s->budget--) { s->failed_pc=0x0c08768au; return 0; }
r[3]=read(ram,0x0c087790u,4);
goto P_0c08768c;
P_0c08768c: /* original 430b, guest PC 0x0c08768c */
if(!s->budget--) { s->failed_pc=0x0c08768cu; return 0; }
target=r[3];
r[16]=code_base|0x0c087690u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087690u) { target=s->pc; goto dispatch; }
goto P_0c087690;
P_0c08768e: /* original 64f3, guest PC 0x0c08768e */
if(!s->budget--) { s->failed_pc=0x0c08768eu; return 0; }
r[4]=r[15];
goto P_0c087690;
P_0c087690: /* original 7f40, guest PC 0x0c087690 */
if(!s->budget--) { s->failed_pc=0x0c087690u; return 0; }
r[15]+=0x00000040u;
goto P_0c087692;
P_0c087692: /* original 4f26, guest PC 0x0c087692 */
if(!s->budget--) { s->failed_pc=0x0c087692u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087694;
P_0c087694: /* original 000b, guest PC 0x0c087694 */
if(!s->budget--) { s->failed_pc=0x0c087694u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087696: /* original 6ef6, guest PC 0x0c087696 */
if(!s->budget--) { s->failed_pc=0x0c087696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c087698;
P_0c087698: /* original 2fe6, guest PC 0x0c087698 */
if(!s->budget--) { s->failed_pc=0x0c087698u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08769a;
P_0c08769a: /* original 6e43, guest PC 0x0c08769a */
if(!s->budget--) { s->failed_pc=0x0c08769au; return 0; }
r[14]=r[4];
goto P_0c08769c;
P_0c08769c: /* original 4f22, guest PC 0x0c08769c */
if(!s->budget--) { s->failed_pc=0x0c08769cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08769e;
P_0c08769e: /* original d33a, guest PC 0x0c08769e */
if(!s->budget--) { s->failed_pc=0x0c08769eu; return 0; }
r[3]=read(ram,0x0c087788u,4);
goto P_0c0876a0;
P_0c0876a0: /* original 7fc0, guest PC 0x0c0876a0 */
if(!s->budget--) { s->failed_pc=0x0c0876a0u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c0876a2;
P_0c0876a2: /* original 430b, guest PC 0x0c0876a2 */
if(!s->budget--) { s->failed_pc=0x0c0876a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0876a6u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0876a6u) { target=s->pc; goto dispatch; }
goto P_0c0876a6;
P_0c0876a4: /* original 64f3, guest PC 0x0c0876a4 */
if(!s->budget--) { s->failed_pc=0x0c0876a4u; return 0; }
r[4]=r[15];
goto P_0c0876a6;
P_0c0876a6: /* original f3f8, guest PC 0x0c0876a6 */
if(!s->budget--) { s->failed_pc=0x0c0876a6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0876a8;
P_0c0876a8: /* original e004, guest PC 0x0c0876a8 */
if(!s->budget--) { s->failed_pc=0x0c0876a8u; return 0; }
r[0]=0x00000004u;
goto P_0c0876aa;
P_0c0876aa: /* original fe3a, guest PC 0x0c0876aa */
if(!s->budget--) { s->failed_pc=0x0c0876aau; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0876ac;
P_0c0876ac: /* original f3f6, guest PC 0x0c0876ac */
if(!s->budget--) { s->failed_pc=0x0c0876acu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876ae;
P_0c0876ae: /* original e004, guest PC 0x0c0876ae */
if(!s->budget--) { s->failed_pc=0x0c0876aeu; return 0; }
r[0]=0x00000004u;
goto P_0c0876b0;
P_0c0876b0: /* original fe37, guest PC 0x0c0876b0 */
if(!s->budget--) { s->failed_pc=0x0c0876b0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876b2;
P_0c0876b2: /* original e008, guest PC 0x0c0876b2 */
if(!s->budget--) { s->failed_pc=0x0c0876b2u; return 0; }
r[0]=0x00000008u;
goto P_0c0876b4;
P_0c0876b4: /* original f3f6, guest PC 0x0c0876b4 */
if(!s->budget--) { s->failed_pc=0x0c0876b4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876b6;
P_0c0876b6: /* original e008, guest PC 0x0c0876b6 */
if(!s->budget--) { s->failed_pc=0x0c0876b6u; return 0; }
r[0]=0x00000008u;
goto P_0c0876b8;
P_0c0876b8: /* original fe37, guest PC 0x0c0876b8 */
if(!s->budget--) { s->failed_pc=0x0c0876b8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876ba;
P_0c0876ba: /* original e010, guest PC 0x0c0876ba */
if(!s->budget--) { s->failed_pc=0x0c0876bau; return 0; }
r[0]=0x00000010u;
goto P_0c0876bc;
P_0c0876bc: /* original f3f6, guest PC 0x0c0876bc */
if(!s->budget--) { s->failed_pc=0x0c0876bcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876be;
P_0c0876be: /* original e010, guest PC 0x0c0876be */
if(!s->budget--) { s->failed_pc=0x0c0876beu; return 0; }
r[0]=0x00000010u;
goto P_0c0876c0;
P_0c0876c0: /* original fe37, guest PC 0x0c0876c0 */
if(!s->budget--) { s->failed_pc=0x0c0876c0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876c2;
P_0c0876c2: /* original e014, guest PC 0x0c0876c2 */
if(!s->budget--) { s->failed_pc=0x0c0876c2u; return 0; }
r[0]=0x00000014u;
goto P_0c0876c4;
P_0c0876c4: /* original f3f6, guest PC 0x0c0876c4 */
if(!s->budget--) { s->failed_pc=0x0c0876c4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876c6;
P_0c0876c6: /* original e014, guest PC 0x0c0876c6 */
if(!s->budget--) { s->failed_pc=0x0c0876c6u; return 0; }
r[0]=0x00000014u;
goto P_0c0876c8;
P_0c0876c8: /* original fe37, guest PC 0x0c0876c8 */
if(!s->budget--) { s->failed_pc=0x0c0876c8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876ca;
P_0c0876ca: /* original e018, guest PC 0x0c0876ca */
if(!s->budget--) { s->failed_pc=0x0c0876cau; return 0; }
r[0]=0x00000018u;
goto P_0c0876cc;
P_0c0876cc: /* original f3f6, guest PC 0x0c0876cc */
if(!s->budget--) { s->failed_pc=0x0c0876ccu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876ce;
P_0c0876ce: /* original e018, guest PC 0x0c0876ce */
if(!s->budget--) { s->failed_pc=0x0c0876ceu; return 0; }
r[0]=0x00000018u;
goto P_0c0876d0;
P_0c0876d0: /* original fe37, guest PC 0x0c0876d0 */
if(!s->budget--) { s->failed_pc=0x0c0876d0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876d2;
P_0c0876d2: /* original e020, guest PC 0x0c0876d2 */
if(!s->budget--) { s->failed_pc=0x0c0876d2u; return 0; }
r[0]=0x00000020u;
goto P_0c0876d4;
P_0c0876d4: /* original f3f6, guest PC 0x0c0876d4 */
if(!s->budget--) { s->failed_pc=0x0c0876d4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876d6;
P_0c0876d6: /* original e020, guest PC 0x0c0876d6 */
if(!s->budget--) { s->failed_pc=0x0c0876d6u; return 0; }
r[0]=0x00000020u;
goto P_0c0876d8;
P_0c0876d8: /* original fe37, guest PC 0x0c0876d8 */
if(!s->budget--) { s->failed_pc=0x0c0876d8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876da;
P_0c0876da: /* original e024, guest PC 0x0c0876da */
if(!s->budget--) { s->failed_pc=0x0c0876dau; return 0; }
r[0]=0x00000024u;
goto P_0c0876dc;
P_0c0876dc: /* original f3f6, guest PC 0x0c0876dc */
if(!s->budget--) { s->failed_pc=0x0c0876dcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876de;
P_0c0876de: /* original e024, guest PC 0x0c0876de */
if(!s->budget--) { s->failed_pc=0x0c0876deu; return 0; }
r[0]=0x00000024u;
goto P_0c0876e0;
P_0c0876e0: /* original fe37, guest PC 0x0c0876e0 */
if(!s->budget--) { s->failed_pc=0x0c0876e0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876e2;
P_0c0876e2: /* original e028, guest PC 0x0c0876e2 */
if(!s->budget--) { s->failed_pc=0x0c0876e2u; return 0; }
r[0]=0x00000028u;
goto P_0c0876e4;
P_0c0876e4: /* original f3f6, guest PC 0x0c0876e4 */
if(!s->budget--) { s->failed_pc=0x0c0876e4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876e6;
P_0c0876e6: /* original 7f40, guest PC 0x0c0876e6 */
if(!s->budget--) { s->failed_pc=0x0c0876e6u; return 0; }
r[15]+=0x00000040u;
goto P_0c0876e8;
P_0c0876e8: /* original 4f26, guest PC 0x0c0876e8 */
if(!s->budget--) { s->failed_pc=0x0c0876e8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0876ea;
P_0c0876ea: /* original e028, guest PC 0x0c0876ea */
if(!s->budget--) { s->failed_pc=0x0c0876eau; return 0; }
r[0]=0x00000028u;
goto P_0c0876ec;
P_0c0876ec: /* original fe37, guest PC 0x0c0876ec */
if(!s->budget--) { s->failed_pc=0x0c0876ecu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876ee;
P_0c0876ee: /* original 000b, guest PC 0x0c0876ee */
if(!s->budget--) { s->failed_pc=0x0c0876eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0876f0: /* original 6ef6, guest PC 0x0c0876f0 */
if(!s->budget--) { s->failed_pc=0x0c0876f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0876f2;
P_0c0876f2: /* original 4f22, guest PC 0x0c0876f2 */
if(!s->budget--) { s->failed_pc=0x0c0876f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0876f4;
P_0c0876f4: /* original e018, guest PC 0x0c0876f4 */
if(!s->budget--) { s->failed_pc=0x0c0876f4u; return 0; }
r[0]=0x00000018u;
goto P_0c0876f6;
P_0c0876f6: /* original 7fdc, guest PC 0x0c0876f6 */
if(!s->budget--) { s->failed_pc=0x0c0876f6u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c0876f8;
P_0c0876f8: /* original 1f42, guest PC 0x0c0876f8 */
if(!s->budget--) { s->failed_pc=0x0c0876f8u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0876fa;
P_0c0876fa: /* original 64f3, guest PC 0x0c0876fa */
if(!s->budget--) { s->failed_pc=0x0c0876fau; return 0; }
r[4]=r[15];
goto P_0c0876fc;
P_0c0876fc: /* original 1f51, guest PC 0x0c0876fc */
if(!s->budget--) { s->failed_pc=0x0c0876fcu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0876fe;
P_0c0876fe: /* original 65f3, guest PC 0x0c0876fe */
if(!s->budget--) { s->failed_pc=0x0c0876feu; return 0; }
r[5]=r[15];
goto P_0c087700;
P_0c087700: /* original 2f62, guest PC 0x0c087700 */
if(!s->budget--) { s->failed_pc=0x0c087700u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c087702;
P_0c087702: /* original 750c, guest PC 0x0c087702 */
if(!s->budget--) { s->failed_pc=0x0c087702u; return 0; }
r[5]+=0x0000000cu;
goto P_0c087704;
P_0c087704: /* original ff47, guest PC 0x0c087704 */
if(!s->budget--) { s->failed_pc=0x0c087704u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c087706;
P_0c087706: /* original e01c, guest PC 0x0c087706 */
if(!s->budget--) { s->failed_pc=0x0c087706u; return 0; }
r[0]=0x0000001cu;
goto P_0c087708;
P_0c087708: /* original ff57, guest PC 0x0c087708 */
if(!s->budget--) { s->failed_pc=0x0c087708u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c08770a;
P_0c08770a: /* original e020, guest PC 0x0c08770a */
if(!s->budget--) { s->failed_pc=0x0c08770au; return 0; }
r[0]=0x00000020u;
goto P_0c08770c;
P_0c08770c: /* original ff67, guest PC 0x0c08770c */
if(!s->budget--) { s->failed_pc=0x0c08770cu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08770e;
P_0c08770e: /* original d321, guest PC 0x0c08770e */
if(!s->budget--) { s->failed_pc=0x0c08770eu; return 0; }
r[3]=read(ram,0x0c087794u,4);
goto P_0c087710;
P_0c087710: /* original 430b, guest PC 0x0c087710 */
if(!s->budget--) { s->failed_pc=0x0c087710u; return 0; }
target=r[3];
r[16]=code_base|0x0c087714u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087714u) { target=s->pc; goto dispatch; }
goto P_0c087714;
P_0c087712: /* original 7418, guest PC 0x0c087712 */
if(!s->budget--) { s->failed_pc=0x0c087712u; return 0; }
r[4]+=0x00000018u;
goto P_0c087714;
P_0c087714: /* original e00c, guest PC 0x0c087714 */
if(!s->budget--) { s->failed_pc=0x0c087714u; return 0; }
r[0]=0x0000000cu;
goto P_0c087716;
P_0c087716: /* original 52f2, guest PC 0x0c087716 */
if(!s->budget--) { s->failed_pc=0x0c087716u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c087718;
P_0c087718: /* original f3f6, guest PC 0x0c087718 */
if(!s->budget--) { s->failed_pc=0x0c087718u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08771a;
P_0c08771a: /* original e010, guest PC 0x0c08771a */
if(!s->budget--) { s->failed_pc=0x0c08771au; return 0; }
r[0]=0x00000010u;
goto P_0c08771c;
P_0c08771c: /* original f23a, guest PC 0x0c08771c */
if(!s->budget--) { s->failed_pc=0x0c08771cu; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c08771e;
P_0c08771e: /* original f3f6, guest PC 0x0c08771e */
if(!s->budget--) { s->failed_pc=0x0c08771eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087720;
P_0c087720: /* original e014, guest PC 0x0c087720 */
if(!s->budget--) { s->failed_pc=0x0c087720u; return 0; }
r[0]=0x00000014u;
goto P_0c087722;
P_0c087722: /* original 53f1, guest PC 0x0c087722 */
if(!s->budget--) { s->failed_pc=0x0c087722u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c087724;
P_0c087724: /* original f33a, guest PC 0x0c087724 */
if(!s->budget--) { s->failed_pc=0x0c087724u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087726;
P_0c087726: /* original f3f6, guest PC 0x0c087726 */
if(!s->budget--) { s->failed_pc=0x0c087726u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087728;
P_0c087728: /* original 63f2, guest PC 0x0c087728 */
if(!s->budget--) { s->failed_pc=0x0c087728u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08772a;
P_0c08772a: /* original 7f24, guest PC 0x0c08772a */
if(!s->budget--) { s->failed_pc=0x0c08772au; return 0; }
r[15]+=0x00000024u;
goto P_0c08772c;
P_0c08772c: /* original 4f26, guest PC 0x0c08772c */
if(!s->budget--) { s->failed_pc=0x0c08772cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08772e;
P_0c08772e: /* original f33a, guest PC 0x0c08772e */
if(!s->budget--) { s->failed_pc=0x0c08772eu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087730;
P_0c087730: /* original 000b, guest PC 0x0c087730 */
if(!s->budget--) { s->failed_pc=0x0c087730u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087732: /* original 0009, guest PC 0x0c087732 */
if(!s->budget--) { s->failed_pc=0x0c087732u; return 0; }
goto P_0c087734;
P_0c087734: /* original 4f22, guest PC 0x0c087734 */
if(!s->budget--) { s->failed_pc=0x0c087734u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087736;
P_0c087736: /* original e018, guest PC 0x0c087736 */
if(!s->budget--) { s->failed_pc=0x0c087736u; return 0; }
r[0]=0x00000018u;
goto P_0c087738;
P_0c087738: /* original 7fdc, guest PC 0x0c087738 */
if(!s->budget--) { s->failed_pc=0x0c087738u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c08773a;
P_0c08773a: /* original 1f42, guest PC 0x0c08773a */
if(!s->budget--) { s->failed_pc=0x0c08773au; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c08773c;
P_0c08773c: /* original 64f3, guest PC 0x0c08773c */
if(!s->budget--) { s->failed_pc=0x0c08773cu; return 0; }
r[4]=r[15];
goto P_0c08773e;
P_0c08773e: /* original 1f51, guest PC 0x0c08773e */
if(!s->budget--) { s->failed_pc=0x0c08773eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c087740;
P_0c087740: /* original 65f3, guest PC 0x0c087740 */
if(!s->budget--) { s->failed_pc=0x0c087740u; return 0; }
r[5]=r[15];
goto P_0c087742;
P_0c087742: /* original 750c, guest PC 0x0c087742 */
if(!s->budget--) { s->failed_pc=0x0c087742u; return 0; }
r[5]+=0x0000000cu;
goto P_0c087744;
P_0c087744: /* original 2f62, guest PC 0x0c087744 */
if(!s->budget--) { s->failed_pc=0x0c087744u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c087746;
P_0c087746: /* original 53f2, guest PC 0x0c087746 */
if(!s->budget--) { s->failed_pc=0x0c087746u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c087748;
P_0c087748: /* original f338, guest PC 0x0c087748 */
if(!s->budget--) { s->failed_pc=0x0c087748u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c08774a;
P_0c08774a: /* original ff37, guest PC 0x0c08774a */
if(!s->budget--) { s->failed_pc=0x0c08774au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08774c;
P_0c08774c: /* original e01c, guest PC 0x0c08774c */
if(!s->budget--) { s->failed_pc=0x0c08774cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08774e;
P_0c08774e: /* original 53f1, guest PC 0x0c08774e */
if(!s->budget--) { s->failed_pc=0x0c08774eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c087750;
P_0c087750: /* original f338, guest PC 0x0c087750 */
if(!s->budget--) { s->failed_pc=0x0c087750u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c087752;
P_0c087752: /* original ff37, guest PC 0x0c087752 */
if(!s->budget--) { s->failed_pc=0x0c087752u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087754;
P_0c087754: /* original e020, guest PC 0x0c087754 */
if(!s->budget--) { s->failed_pc=0x0c087754u; return 0; }
r[0]=0x00000020u;
goto P_0c087756;
P_0c087756: /* original 63f2, guest PC 0x0c087756 */
if(!s->budget--) { s->failed_pc=0x0c087756u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c087758;
P_0c087758: /* original f338, guest PC 0x0c087758 */
if(!s->budget--) { s->failed_pc=0x0c087758u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c08775a;
P_0c08775a: /* original ff37, guest PC 0x0c08775a */
if(!s->budget--) { s->failed_pc=0x0c08775au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08775c;
P_0c08775c: /* original d30e, guest PC 0x0c08775c */
if(!s->budget--) { s->failed_pc=0x0c08775cu; return 0; }
r[3]=read(ram,0x0c087798u,4);
goto P_0c08775e;
P_0c08775e: /* original 430b, guest PC 0x0c08775e */
if(!s->budget--) { s->failed_pc=0x0c08775eu; return 0; }
target=r[3];
r[16]=code_base|0x0c087762u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087762u) { target=s->pc; goto dispatch; }
goto P_0c087762;
P_0c087760: /* original 7418, guest PC 0x0c087760 */
if(!s->budget--) { s->failed_pc=0x0c087760u; return 0; }
r[4]+=0x00000018u;
goto P_0c087762;
P_0c087762: /* original e00c, guest PC 0x0c087762 */
if(!s->budget--) { s->failed_pc=0x0c087762u; return 0; }
r[0]=0x0000000cu;
goto P_0c087764;
P_0c087764: /* original 52f2, guest PC 0x0c087764 */
if(!s->budget--) { s->failed_pc=0x0c087764u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c087766;
P_0c087766: /* original f3f6, guest PC 0x0c087766 */
if(!s->budget--) { s->failed_pc=0x0c087766u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087768;
P_0c087768: /* original e010, guest PC 0x0c087768 */
if(!s->budget--) { s->failed_pc=0x0c087768u; return 0; }
r[0]=0x00000010u;
goto P_0c08776a;
P_0c08776a: /* original f23a, guest PC 0x0c08776a */
if(!s->budget--) { s->failed_pc=0x0c08776au; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c08776c;
P_0c08776c: /* original f3f6, guest PC 0x0c08776c */
if(!s->budget--) { s->failed_pc=0x0c08776cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08776e;
P_0c08776e: /* original e014, guest PC 0x0c08776e */
if(!s->budget--) { s->failed_pc=0x0c08776eu; return 0; }
r[0]=0x00000014u;
goto P_0c087770;
P_0c087770: /* original 53f1, guest PC 0x0c087770 */
if(!s->budget--) { s->failed_pc=0x0c087770u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c087772;
P_0c087772: /* original f33a, guest PC 0x0c087772 */
if(!s->budget--) { s->failed_pc=0x0c087772u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087774;
P_0c087774: /* original f3f6, guest PC 0x0c087774 */
if(!s->budget--) { s->failed_pc=0x0c087774u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087776;
P_0c087776: /* original 63f2, guest PC 0x0c087776 */
if(!s->budget--) { s->failed_pc=0x0c087776u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c087778;
P_0c087778: /* original 7f24, guest PC 0x0c087778 */
if(!s->budget--) { s->failed_pc=0x0c087778u; return 0; }
r[15]+=0x00000024u;
goto P_0c08777a;
P_0c08777a: /* original 4f26, guest PC 0x0c08777a */
if(!s->budget--) { s->failed_pc=0x0c08777au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08777c;
P_0c08777c: /* original f33a, guest PC 0x0c08777c */
if(!s->budget--) { s->failed_pc=0x0c08777cu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c08777e;
P_0c08777e: /* original 000b, guest PC 0x0c08777e */
if(!s->budget--) { s->failed_pc=0x0c08777eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087780: /* original 0009, guest PC 0x0c087780 */
if(!s->budget--) { s->failed_pc=0x0c087780u; return 0; }
if(!vf3_matrix_family(0x0c087782u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087782u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
