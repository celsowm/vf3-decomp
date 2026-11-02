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
int vf3_away_batch2_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0365eau: goto P_0c0365ea;
case 0x0c0365ecu: goto P_0c0365ec;
case 0x0c0365eeu: goto P_0c0365ee;
case 0x0c0365f0u: goto P_0c0365f0;
case 0x0c0365f2u: goto P_0c0365f2;
case 0x0c0365f4u: goto P_0c0365f4;
case 0x0c0365f6u: goto P_0c0365f6;
case 0x0c0365f8u: goto P_0c0365f8;
case 0x0c0365fau: goto P_0c0365fa;
case 0x0c0365fcu: goto P_0c0365fc;
case 0x0c0365feu: goto P_0c0365fe;
case 0x0c036600u: goto P_0c036600;
case 0x0c0370f0u: goto P_0c0370f0;
case 0x0c0370f2u: goto P_0c0370f2;
case 0x0c0370f4u: goto P_0c0370f4;
case 0x0c0370f6u: goto P_0c0370f6;
case 0x0c0370f8u: goto P_0c0370f8;
case 0x0c0370fau: goto P_0c0370fa;
case 0x0c0370fcu: goto P_0c0370fc;
case 0x0c0370feu: goto P_0c0370fe;
case 0x0c037100u: goto P_0c037100;
case 0x0c037102u: goto P_0c037102;
case 0x0c037104u: goto P_0c037104;
case 0x0c037106u: goto P_0c037106;
case 0x0c037108u: goto P_0c037108;
case 0x0c03710au: goto P_0c03710a;
case 0x0c03710cu: goto P_0c03710c;
case 0x0c03710eu: goto P_0c03710e;
case 0x0c037110u: goto P_0c037110;
case 0x0c037112u: goto P_0c037112;
case 0x0c037114u: goto P_0c037114;
case 0x0c037116u: goto P_0c037116;
case 0x0c037118u: goto P_0c037118;
case 0x0c03711au: goto P_0c03711a;
case 0x0c03711cu: goto P_0c03711c;
case 0x0c03711eu: goto P_0c03711e;
case 0x0c037120u: goto P_0c037120;
case 0x0c037122u: goto P_0c037122;
case 0x0c037124u: goto P_0c037124;
case 0x0c037126u: goto P_0c037126;
case 0x0c037128u: goto P_0c037128;
case 0x0c03712au: goto P_0c03712a;
case 0x0c03712cu: goto P_0c03712c;
case 0x0c03712eu: goto P_0c03712e;
case 0x0c037130u: goto P_0c037130;
case 0x0c037132u: goto P_0c037132;
case 0x0c037134u: goto P_0c037134;
case 0x0c037136u: goto P_0c037136;
case 0x0c037138u: goto P_0c037138;
case 0x0c03713au: goto P_0c03713a;
case 0x0c03713cu: goto P_0c03713c;
case 0x0c03713eu: goto P_0c03713e;
case 0x0c037140u: goto P_0c037140;
case 0x0c037142u: goto P_0c037142;
case 0x0c037144u: goto P_0c037144;
case 0x0c037146u: goto P_0c037146;
case 0x0c037148u: goto P_0c037148;
case 0x0c03714au: goto P_0c03714a;
case 0x0c03714cu: goto P_0c03714c;
case 0x0c03714eu: goto P_0c03714e;
case 0x0c037150u: goto P_0c037150;
case 0x0c037152u: goto P_0c037152;
case 0x0c037154u: goto P_0c037154;
case 0x0c037156u: goto P_0c037156;
case 0x0c037158u: goto P_0c037158;
case 0x0c03715au: goto P_0c03715a;
case 0x0c03715cu: goto P_0c03715c;
case 0x0c03715eu: goto P_0c03715e;
case 0x0c037160u: goto P_0c037160;
case 0x0c037162u: goto P_0c037162;
case 0x0c037164u: goto P_0c037164;
case 0x0c037166u: goto P_0c037166;
case 0x0c037168u: goto P_0c037168;
case 0x0c03716au: goto P_0c03716a;
case 0x0c03716cu: goto P_0c03716c;
case 0x0c03716eu: goto P_0c03716e;
case 0x0c037170u: goto P_0c037170;
case 0x0c037172u: goto P_0c037172;
case 0x0c037174u: goto P_0c037174;
case 0x0c037176u: goto P_0c037176;
case 0x0c037178u: goto P_0c037178;
case 0x0c03717au: goto P_0c03717a;
case 0x0c03717cu: goto P_0c03717c;
case 0x0c03717eu: goto P_0c03717e;
case 0x0c037180u: goto P_0c037180;
case 0x0c037182u: goto P_0c037182;
case 0x0c037184u: goto P_0c037184;
case 0x0c037186u: goto P_0c037186;
case 0x0c037188u: goto P_0c037188;
case 0x0c03718au: goto P_0c03718a;
case 0x0c03718cu: goto P_0c03718c;
case 0x0c03718eu: goto P_0c03718e;
case 0x0c037316u: goto P_0c037316;
case 0x0c037318u: goto P_0c037318;
case 0x0c03731au: goto P_0c03731a;
case 0x0c03731cu: goto P_0c03731c;
case 0x0c03731eu: goto P_0c03731e;
case 0x0c037320u: goto P_0c037320;
case 0x0c037322u: goto P_0c037322;
case 0x0c037324u: goto P_0c037324;
case 0x0c037326u: goto P_0c037326;
case 0x0c037328u: goto P_0c037328;
case 0x0c03732au: goto P_0c03732a;
case 0x0c03732cu: goto P_0c03732c;
case 0x0c03732eu: goto P_0c03732e;
case 0x0c037330u: goto P_0c037330;
case 0x0c037332u: goto P_0c037332;
case 0x0c037334u: goto P_0c037334;
case 0x0c037336u: goto P_0c037336;
case 0x0c037338u: goto P_0c037338;
case 0x0c03733au: goto P_0c03733a;
case 0x0c03733cu: goto P_0c03733c;
case 0x0c03733eu: goto P_0c03733e;
case 0x0c037340u: goto P_0c037340;
case 0x0c037342u: goto P_0c037342;
case 0x0c037344u: goto P_0c037344;
case 0x0c037346u: goto P_0c037346;
case 0x0c037348u: goto P_0c037348;
case 0x0c03734au: goto P_0c03734a;
case 0x0c03734cu: goto P_0c03734c;
case 0x0c03734eu: goto P_0c03734e;
case 0x0c037350u: goto P_0c037350;
case 0x0c0376e0u: goto P_0c0376e0;
case 0x0c0376e2u: goto P_0c0376e2;
case 0x0c0376e4u: goto P_0c0376e4;
case 0x0c0376e6u: goto P_0c0376e6;
case 0x0c0376e8u: goto P_0c0376e8;
case 0x0c0376eau: goto P_0c0376ea;
case 0x0c0376ecu: goto P_0c0376ec;
case 0x0c0376eeu: goto P_0c0376ee;
case 0x0c0376f0u: goto P_0c0376f0;
case 0x0c0376f2u: goto P_0c0376f2;
case 0x0c0376f4u: goto P_0c0376f4;
case 0x0c0376f6u: goto P_0c0376f6;
case 0x0c0376f8u: goto P_0c0376f8;
case 0x0c0376fau: goto P_0c0376fa;
case 0x0c0376fcu: goto P_0c0376fc;
case 0x0c0376feu: goto P_0c0376fe;
case 0x0c037700u: goto P_0c037700;
case 0x0c037702u: goto P_0c037702;
case 0x0c037704u: goto P_0c037704;
case 0x0c037706u: goto P_0c037706;
case 0x0c037708u: goto P_0c037708;
case 0x0c03770au: goto P_0c03770a;
case 0x0c03770cu: goto P_0c03770c;
case 0x0c03770eu: goto P_0c03770e;
case 0x0c037710u: goto P_0c037710;
case 0x0c037712u: goto P_0c037712;
case 0x0c037714u: goto P_0c037714;
case 0x0c037716u: goto P_0c037716;
case 0x0c037718u: goto P_0c037718;
case 0x0c03771au: goto P_0c03771a;
case 0x0c03771cu: goto P_0c03771c;
case 0x0c03771eu: goto P_0c03771e;
case 0x0c037720u: goto P_0c037720;
case 0x0c037722u: goto P_0c037722;
case 0x0c037724u: goto P_0c037724;
case 0x0c037726u: goto P_0c037726;
case 0x0c037728u: goto P_0c037728;
case 0x0c03772au: goto P_0c03772a;
case 0x0c03772cu: goto P_0c03772c;
case 0x0c03772eu: goto P_0c03772e;
case 0x0c037730u: goto P_0c037730;
case 0x0c037732u: goto P_0c037732;
case 0x0c037734u: goto P_0c037734;
case 0x0c037736u: goto P_0c037736;
case 0x0c037738u: goto P_0c037738;
case 0x0c03773au: goto P_0c03773a;
case 0x0c03773cu: goto P_0c03773c;
case 0x0c03773eu: goto P_0c03773e;
case 0x0c037740u: goto P_0c037740;
case 0x0c037742u: goto P_0c037742;
case 0x0c037744u: goto P_0c037744;
case 0x0c037746u: goto P_0c037746;
case 0x0c037748u: goto P_0c037748;
case 0x0c03774au: goto P_0c03774a;
case 0x0c03774cu: goto P_0c03774c;
case 0x0c03774eu: goto P_0c03774e;
case 0x0c037750u: goto P_0c037750;
case 0x0c037752u: goto P_0c037752;
case 0x0c037754u: goto P_0c037754;
case 0x0c037756u: goto P_0c037756;
case 0x0c037758u: goto P_0c037758;
case 0x0c03775au: goto P_0c03775a;
case 0x0c03775cu: goto P_0c03775c;
case 0x0c03775eu: goto P_0c03775e;
case 0x0c037760u: goto P_0c037760;
case 0x0c037762u: goto P_0c037762;
case 0x0c037764u: goto P_0c037764;
case 0x0c037766u: goto P_0c037766;
case 0x0c037768u: goto P_0c037768;
case 0x0c03776au: goto P_0c03776a;
case 0x0c03776cu: goto P_0c03776c;
case 0x0c03776eu: goto P_0c03776e;
case 0x0c037770u: goto P_0c037770;
case 0x0c037772u: goto P_0c037772;
case 0x0c037774u: goto P_0c037774;
case 0x0c037776u: goto P_0c037776;
case 0x0c037778u: goto P_0c037778;
case 0x0c03777au: goto P_0c03777a;
case 0x0c03777cu: goto P_0c03777c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0365ea: /* original e278, guest PC 0x0c0365ea */
if(!s->budget--) { s->failed_pc=0x0c0365eau; return 0; }
r[2]=0x00000078u;
goto P_0c0365ec;
P_0c0365ec: /* original d315, guest PC 0x0c0365ec */
if(!s->budget--) { s->failed_pc=0x0c0365ecu; return 0; }
r[3]=read(ram,0x0c036644u,4);
goto P_0c0365ee;
P_0c0365ee: /* original 4f12, guest PC 0x0c0365ee */
if(!s->budget--) { s->failed_pc=0x0c0365eeu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0365f0;
P_0c0365f0: /* original 242f, guest PC 0x0c0365f0 */
if(!s->budget--) { s->failed_pc=0x0c0365f0u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[2]);
goto P_0c0365f2;
P_0c0365f2: /* original 911f, guest PC 0x0c0365f2 */
if(!s->budget--) { s->failed_pc=0x0c0365f2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036634u,2);
goto P_0c0365f4;
P_0c0365f4: /* original 6032, guest PC 0x0c0365f4 */
if(!s->budget--) { s->failed_pc=0x0c0365f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0365f6;
P_0c0365f6: /* original 041a, guest PC 0x0c0365f6 */
if(!s->budget--) { s->failed_pc=0x0c0365f6u; return 0; }
r[4]=r[19];
goto P_0c0365f8;
P_0c0365f8: /* original 301c, guest PC 0x0c0365f8 */
if(!s->budget--) { s->failed_pc=0x0c0365f8u; return 0; }
r[0]+=r[1];
goto P_0c0365fa;
P_0c0365fa: /* original 644f, guest PC 0x0c0365fa */
if(!s->budget--) { s->failed_pc=0x0c0365fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0365fc;
P_0c0365fc: /* original 304c, guest PC 0x0c0365fc */
if(!s->budget--) { s->failed_pc=0x0c0365fcu; return 0; }
r[0]+=r[4];
goto P_0c0365fe;
P_0c0365fe: /* original 000b, guest PC 0x0c0365fe */
if(!s->budget--) { s->failed_pc=0x0c0365feu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c036600: /* original 4f16, guest PC 0x0c036600 */
if(!s->budget--) { s->failed_pc=0x0c036600u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c036602u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036602u; return 0; } return 1;
P_0c0370f0: /* original 2fe6, guest PC 0x0c0370f0 */
if(!s->budget--) { s->failed_pc=0x0c0370f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0370f2;
P_0c0370f2: /* original ee4c, guest PC 0x0c0370f2 */
if(!s->budget--) { s->failed_pc=0x0c0370f2u; return 0; }
r[14]=0x0000004cu;
goto P_0c0370f4;
P_0c0370f4: /* original 2fd6, guest PC 0x0c0370f4 */
if(!s->budget--) { s->failed_pc=0x0c0370f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0370f6;
P_0c0370f6: /* original 6053, guest PC 0x0c0370f6 */
if(!s->budget--) { s->failed_pc=0x0c0370f6u; return 0; }
r[0]=r[5];
goto P_0c0370f8;
P_0c0370f8: /* original 2fc6, guest PC 0x0c0370f8 */
if(!s->budget--) { s->failed_pc=0x0c0370f8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0370fa;
P_0c0370fa: /* original 8801, guest PC 0x0c0370fa */
if(!s->budget--) { s->failed_pc=0x0c0370fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0370fc;
P_0c0370fc: /* original 4f22, guest PC 0x0c0370fc */
if(!s->budget--) { s->failed_pc=0x0c0370fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0370fe;
P_0c0370fe: /* original 6c63, guest PC 0x0c0370fe */
if(!s->budget--) { s->failed_pc=0x0c0370feu; return 0; }
r[12]=r[6];
goto P_0c037100;
P_0c037100: /* original 4f12, guest PC 0x0c037100 */
if(!s->budget--) { s->failed_pc=0x0c037100u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c037102;
P_0c037102: /* original 24ef, guest PC 0x0c037102 */
if(!s->budget--) { s->failed_pc=0x0c037102u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c037104;
P_0c037104: /* original 7ffc, guest PC 0x0c037104 */
if(!s->budget--) { s->failed_pc=0x0c037104u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c037106;
P_0c037106: /* original 2f52, guest PC 0x0c037106 */
if(!s->budget--) { s->failed_pc=0x0c037106u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c037108;
P_0c037108: /* original 0e1a, guest PC 0x0c037108 */
if(!s->budget--) { s->failed_pc=0x0c037108u; return 0; }
r[14]=r[19];
goto P_0c03710a;
P_0c03710a: /* original d33d, guest PC 0x0c03710a */
if(!s->budget--) { s->failed_pc=0x0c03710au; return 0; }
r[3]=read(ram,0x0c037200u,4);
goto P_0c03710c;
P_0c03710c: /* original 6eef, guest PC 0x0c03710c */
if(!s->budget--) { s->failed_pc=0x0c03710cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c03710e;
P_0c03710e: /* original 3e3c, guest PC 0x0c03710e */
if(!s->budget--) { s->failed_pc=0x0c03710eu; return 0; }
r[14]+=r[3];
goto P_0c037110;
P_0c037110: /* original 8d04, guest PC 0x0c037110 */
if(!s->budget--) { s->failed_pc=0x0c037110u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c03711c; }
goto P_0c037114;
P_0c037112: /* original ed00, guest PC 0x0c037112 */
if(!s->budget--) { s->failed_pc=0x0c037112u; return 0; }
r[13]=0x00000000u;
goto P_0c037114;
P_0c037114: /* original 8802, guest PC 0x0c037114 */
if(!s->budget--) { s->failed_pc=0x0c037114u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c037116;
P_0c037116: /* original 8913, guest PC 0x0c037116 */
if(!s->budget--) { s->failed_pc=0x0c037116u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c037140; }
goto P_0c037118;
P_0c037118: /* original a020, guest PC 0x0c037118 */
if(!s->budget--) { s->failed_pc=0x0c037118u; return 0; }
goto P_0c03715c;
P_0c03711a: /* original 0009, guest PC 0x0c03711a */
if(!s->budget--) { s->failed_pc=0x0c03711au; return 0; }
goto P_0c03711c;
P_0c03711c: /* original 2cc8, guest PC 0x0c03711c */
if(!s->budget--) { s->failed_pc=0x0c03711cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c03711e;
P_0c03711e: /* original 8b0b, guest PC 0x0c03711e */
if(!s->budget--) { s->failed_pc=0x0c03711eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037138; }
goto P_0c037120;
P_0c037120: /* original e101, guest PC 0x0c037120 */
if(!s->budget--) { s->failed_pc=0x0c037120u; return 0; }
r[1]=0x00000001u;
goto P_0c037122;
P_0c037122: /* original 65e3, guest PC 0x0c037122 */
if(!s->budget--) { s->failed_pc=0x0c037122u; return 0; }
r[5]=r[14];
goto P_0c037124;
P_0c037124: /* original 2e11, guest PC 0x0c037124 */
if(!s->budget--) { s->failed_pc=0x0c037124u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c037126;
P_0c037126: /* original d237, guest PC 0x0c037126 */
if(!s->budget--) { s->failed_pc=0x0c037126u; return 0; }
r[2]=read(ram,0x0c037204u,4);
goto P_0c037128;
P_0c037128: /* original 420b, guest PC 0x0c037128 */
if(!s->budget--) { s->failed_pc=0x0c037128u; return 0; }
target=r[2];
r[16]=code_base|0x0c03712cu;
r[5]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03712cu) { target=s->pc; goto dispatch; }
goto P_0c03712c;
P_0c03712a: /* original 7514, guest PC 0x0c03712a */
if(!s->budget--) { s->failed_pc=0x0c03712au; return 0; }
r[5]+=0x00000014u;
goto P_0c03712c;
P_0c03712c: /* original 6403, guest PC 0x0c03712c */
if(!s->budget--) { s->failed_pc=0x0c03712cu; return 0; }
r[4]=r[0];
goto P_0c03712e;
P_0c03712e: /* original 2448, guest PC 0x0c03712e */
if(!s->budget--) { s->failed_pc=0x0c03712eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c037130;
P_0c037130: /* original 8b01, guest PC 0x0c037130 */
if(!s->budget--) { s->failed_pc=0x0c037130u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037136; }
goto P_0c037132;
P_0c037132: /* original e001, guest PC 0x0c037132 */
if(!s->budget--) { s->failed_pc=0x0c037132u; return 0; }
r[0]=0x00000001u;
goto P_0c037134;
P_0c037134: /* original 81e1, guest PC 0x0c037134 */
if(!s->budget--) { s->failed_pc=0x0c037134u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c037136;
P_0c037136: /* original 1ed1, guest PC 0x0c037136 */
if(!s->budget--) { s->failed_pc=0x0c037136u; return 0; }
write(ram,r[14]+4,r[13],4);
goto P_0c037138;
P_0c037138: /* original b326, guest PC 0x0c037138 */
if(!s->budget--) { s->failed_pc=0x0c037138u; return 0; }
target=code_base|0x0c037788u; r[16]=code_base|0x0c03713cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03713cu) { target=s->pc; goto dispatch; }
goto P_0c03713c;
P_0c03713a: /* original 0009, guest PC 0x0c03713a */
if(!s->budget--) { s->failed_pc=0x0c03713au; return 0; }
goto P_0c03713c;
P_0c03713c: /* original a013, guest PC 0x0c03713c */
if(!s->budget--) { s->failed_pc=0x0c03713cu; return 0; }
goto P_0c037166;
P_0c03713e: /* original 0009, guest PC 0x0c03713e */
if(!s->budget--) { s->failed_pc=0x0c03713eu; return 0; }
goto P_0c037140;
P_0c037140: /* original 60d3, guest PC 0x0c037140 */
if(!s->budget--) { s->failed_pc=0x0c037140u; return 0; }
r[0]=r[13];
goto P_0c037142;
P_0c037142: /* original e638, guest PC 0x0c037142 */
if(!s->budget--) { s->failed_pc=0x0c037142u; return 0; }
r[6]=0x00000038u;
goto P_0c037144;
P_0c037144: /* original e500, guest PC 0x0c037144 */
if(!s->budget--) { s->failed_pc=0x0c037144u; return 0; }
r[5]=0x00000000u;
goto P_0c037146;
P_0c037146: /* original 64e3, guest PC 0x0c037146 */
if(!s->budget--) { s->failed_pc=0x0c037146u; return 0; }
r[4]=r[14];
goto P_0c037148;
P_0c037148: /* original 2ed1, guest PC 0x0c037148 */
if(!s->budget--) { s->failed_pc=0x0c037148u; return 0; }
write(ram,r[14],r[13],2);
goto P_0c03714a;
P_0c03714a: /* original 81e1, guest PC 0x0c03714a */
if(!s->budget--) { s->failed_pc=0x0c03714au; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c03714c;
P_0c03714c: /* original 1e02, guest PC 0x0c03714c */
if(!s->budget--) { s->failed_pc=0x0c03714cu; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c03714e;
P_0c03714e: /* original 1e03, guest PC 0x0c03714e */
if(!s->budget--) { s->failed_pc=0x0c03714eu; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c037150;
P_0c037150: /* original 1e04, guest PC 0x0c037150 */
if(!s->budget--) { s->failed_pc=0x0c037150u; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c037152;
P_0c037152: /* original d22d, guest PC 0x0c037152 */
if(!s->budget--) { s->failed_pc=0x0c037152u; return 0; }
r[2]=read(ram,0x0c037208u,4);
goto P_0c037154;
P_0c037154: /* original 420b, guest PC 0x0c037154 */
if(!s->budget--) { s->failed_pc=0x0c037154u; return 0; }
target=r[2];
r[16]=code_base|0x0c037158u;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c037158u) { target=s->pc; goto dispatch; }
goto P_0c037158;
P_0c037156: /* original 7414, guest PC 0x0c037156 */
if(!s->budget--) { s->failed_pc=0x0c037156u; return 0; }
r[4]+=0x00000014u;
goto P_0c037158;
P_0c037158: /* original a005, guest PC 0x0c037158 */
if(!s->budget--) { s->failed_pc=0x0c037158u; return 0; }
goto P_0c037166;
P_0c03715a: /* original 0009, guest PC 0x0c03715a */
if(!s->budget--) { s->failed_pc=0x0c03715au; return 0; }
goto P_0c03715c;
P_0c03715c: /* original 65e3, guest PC 0x0c03715c */
if(!s->budget--) { s->failed_pc=0x0c03715cu; return 0; }
r[5]=r[14];
goto P_0c03715e;
P_0c03715e: /* original 1ec1, guest PC 0x0c03715e */
if(!s->budget--) { s->failed_pc=0x0c03715eu; return 0; }
write(ram,r[14]+4,r[12],4);
goto P_0c037160;
P_0c037160: /* original d228, guest PC 0x0c037160 */
if(!s->budget--) { s->failed_pc=0x0c037160u; return 0; }
r[2]=read(ram,0x0c037204u,4);
goto P_0c037162;
P_0c037162: /* original 420b, guest PC 0x0c037162 */
if(!s->budget--) { s->failed_pc=0x0c037162u; return 0; }
target=r[2];
r[16]=code_base|0x0c037166u;
r[5]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c037166u) { target=s->pc; goto dispatch; }
goto P_0c037166;
P_0c037164: /* original 7514, guest PC 0x0c037164 */
if(!s->budget--) { s->failed_pc=0x0c037164u; return 0; }
r[5]+=0x00000014u;
goto P_0c037166;
P_0c037166: /* original 1ed4, guest PC 0x0c037166 */
if(!s->budget--) { s->failed_pc=0x0c037166u; return 0; }
write(ram,r[14]+16,r[13],4);
goto P_0c037168;
P_0c037168: /* original d428, guest PC 0x0c037168 */
if(!s->budget--) { s->failed_pc=0x0c037168u; return 0; }
r[4]=read(ram,0x0c03720cu,4);
goto P_0c03716a;
P_0c03716a: /* original 6342, guest PC 0x0c03716a */
if(!s->budget--) { s->failed_pc=0x0c03716au; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03716c;
P_0c03716c: /* original 2338, guest PC 0x0c03716c */
if(!s->budget--) { s->failed_pc=0x0c03716cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03716e;
P_0c03716e: /* original 8907, guest PC 0x0c03716e */
if(!s->budget--) { s->failed_pc=0x0c03716eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c037180; }
goto P_0c037170;
P_0c037170: /* original 60f2, guest PC 0x0c037170 */
if(!s->budget--) { s->failed_pc=0x0c037170u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c037172;
P_0c037172: /* original 880b, guest PC 0x0c037172 */
if(!s->budget--) { s->failed_pc=0x0c037172u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c037174;
P_0c037174: /* original 8b04, guest PC 0x0c037174 */
if(!s->budget--) { s->failed_pc=0x0c037174u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037180; }
goto P_0c037176;
P_0c037176: /* original 2cc8, guest PC 0x0c037176 */
if(!s->budget--) { s->failed_pc=0x0c037176u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c037178;
P_0c037178: /* original 8f02, guest PC 0x0c037178 */
if(!s->budget--) { s->failed_pc=0x0c037178u; return 0; }
cond=r[17]&1u;
write(ram,r[4],r[13],4);
if(!cond) { goto P_0c037180; }
goto P_0c03717c;
P_0c03717a: /* original 24d2, guest PC 0x0c03717a */
if(!s->budget--) { s->failed_pc=0x0c03717au; return 0; }
write(ram,r[4],r[13],4);
goto P_0c03717c;
P_0c03717c: /* original b0cb, guest PC 0x0c03717c */
if(!s->budget--) { s->failed_pc=0x0c03717cu; return 0; }
target=code_base|0x0c037316u; r[16]=code_base|0x0c037180u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c037180u) { target=s->pc; goto dispatch; }
goto P_0c037180;
P_0c03717e: /* original 0009, guest PC 0x0c03717e */
if(!s->budget--) { s->failed_pc=0x0c03717eu; return 0; }
goto P_0c037180;
P_0c037180: /* original 7f04, guest PC 0x0c037180 */
if(!s->budget--) { s->failed_pc=0x0c037180u; return 0; }
r[15]+=0x00000004u;
goto P_0c037182;
P_0c037182: /* original 4f16, guest PC 0x0c037182 */
if(!s->budget--) { s->failed_pc=0x0c037182u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c037184;
P_0c037184: /* original e000, guest PC 0x0c037184 */
if(!s->budget--) { s->failed_pc=0x0c037184u; return 0; }
r[0]=0x00000000u;
goto P_0c037186;
P_0c037186: /* original 4f26, guest PC 0x0c037186 */
if(!s->budget--) { s->failed_pc=0x0c037186u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037188;
P_0c037188: /* original 6cf6, guest PC 0x0c037188 */
if(!s->budget--) { s->failed_pc=0x0c037188u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03718a;
P_0c03718a: /* original 6df6, guest PC 0x0c03718a */
if(!s->budget--) { s->failed_pc=0x0c03718au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03718c;
P_0c03718c: /* original 000b, guest PC 0x0c03718c */
if(!s->budget--) { s->failed_pc=0x0c03718cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03718e: /* original 6ef6, guest PC 0x0c03718e */
if(!s->budget--) { s->failed_pc=0x0c03718eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c037190u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c037190u; return 0; } return 1;
P_0c037316: /* original 4f22, guest PC 0x0c037316 */
if(!s->budget--) { s->failed_pc=0x0c037316u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c037318;
P_0c037318: /* original d321, guest PC 0x0c037318 */
if(!s->budget--) { s->failed_pc=0x0c037318u; return 0; }
r[3]=read(ram,0x0c0373a0u,4);
goto P_0c03731a;
P_0c03731a: /* original d519, guest PC 0x0c03731a */
if(!s->budget--) { s->failed_pc=0x0c03731au; return 0; }
r[5]=read(ram,0x0c037380u,4);
goto P_0c03731c;
P_0c03731c: /* original 7f9c, guest PC 0x0c03731c */
if(!s->budget--) { s->failed_pc=0x0c03731cu; return 0; }
r[15]+=0xffffff9cu;
goto P_0c03731e;
P_0c03731e: /* original 64f3, guest PC 0x0c03731e */
if(!s->budget--) { s->failed_pc=0x0c03731eu; return 0; }
r[4]=r[15];
goto P_0c037320;
P_0c037320: /* original 430b, guest PC 0x0c037320 */
if(!s->budget--) { s->failed_pc=0x0c037320u; return 0; }
target=r[3];
r[16]=code_base|0x0c037324u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c037324u) { target=s->pc; goto dispatch; }
goto P_0c037324;
P_0c037322: /* original 7404, guest PC 0x0c037322 */
if(!s->budget--) { s->failed_pc=0x0c037322u; return 0; }
r[4]+=0x00000004u;
goto P_0c037324;
P_0c037324: /* original 6403, guest PC 0x0c037324 */
if(!s->budget--) { s->failed_pc=0x0c037324u; return 0; }
r[4]=r[0];
goto P_0c037326;
P_0c037326: /* original 2448, guest PC 0x0c037326 */
if(!s->budget--) { s->failed_pc=0x0c037326u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c037328;
P_0c037328: /* original 8903, guest PC 0x0c037328 */
if(!s->budget--) { s->failed_pc=0x0c037328u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c037332; }
goto P_0c03732a;
P_0c03732a: /* original 7f64, guest PC 0x0c03732a */
if(!s->budget--) { s->failed_pc=0x0c03732au; return 0; }
r[15]+=0x00000064u;
goto P_0c03732c;
P_0c03732c: /* original 4f26, guest PC 0x0c03732c */
if(!s->budget--) { s->failed_pc=0x0c03732cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03732e;
P_0c03732e: /* original 000b, guest PC 0x0c03732e */
if(!s->budget--) { s->failed_pc=0x0c03732eu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c037330: /* original 6043, guest PC 0x0c037330 */
if(!s->budget--) { s->failed_pc=0x0c037330u; return 0; }
r[0]=r[4];
goto P_0c037332;
P_0c037332: /* original d313, guest PC 0x0c037332 */
if(!s->budget--) { s->failed_pc=0x0c037332u; return 0; }
r[3]=read(ram,0x0c037380u,4);
goto P_0c037334;
P_0c037334: /* original 2f32, guest PC 0x0c037334 */
if(!s->budget--) { s->failed_pc=0x0c037334u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c037336;
P_0c037336: /* original 930d, guest PC 0x0c037336 */
if(!s->budget--) { s->failed_pc=0x0c037336u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c037354u,2);
goto P_0c037338;
P_0c037338: /* original 65f2, guest PC 0x0c037338 */
if(!s->budget--) { s->failed_pc=0x0c037338u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03733a;
P_0c03733a: /* original d218, guest PC 0x0c03733a */
if(!s->budget--) { s->failed_pc=0x0c03733au; return 0; }
r[2]=read(ram,0x0c03739cu,4);
goto P_0c03733c;
P_0c03733c: /* original 353c, guest PC 0x0c03733c */
if(!s->budget--) { s->failed_pc=0x0c03733cu; return 0; }
r[5]+=r[3];
goto P_0c03733e;
P_0c03733e: /* original d30d, guest PC 0x0c03733e */
if(!s->budget--) { s->failed_pc=0x0c03733eu; return 0; }
r[3]=read(ram,0x0c037374u,4);
goto P_0c037340;
P_0c037340: /* original d115, guest PC 0x0c037340 */
if(!s->budget--) { s->failed_pc=0x0c037340u; return 0; }
r[1]=read(ram,0x0c037398u,4);
goto P_0c037342;
P_0c037342: /* original 6622, guest PC 0x0c037342 */
if(!s->budget--) { s->failed_pc=0x0c037342u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c037344;
P_0c037344: /* original 430b, guest PC 0x0c037344 */
if(!s->budget--) { s->failed_pc=0x0c037344u; return 0; }
target=r[3];
r[16]=code_base|0x0c037348u;
tmp=read(ram,r[1],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c037348u) { target=s->pc; goto dispatch; }
goto P_0c037348;
P_0c037346: /* original 6412, guest PC 0x0c037346 */
if(!s->budget--) { s->failed_pc=0x0c037346u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c037348;
P_0c037348: /* original e000, guest PC 0x0c037348 */
if(!s->budget--) { s->failed_pc=0x0c037348u; return 0; }
r[0]=0x00000000u;
goto P_0c03734a;
P_0c03734a: /* original 7f64, guest PC 0x0c03734a */
if(!s->budget--) { s->failed_pc=0x0c03734au; return 0; }
r[15]+=0x00000064u;
goto P_0c03734c;
P_0c03734c: /* original 4f26, guest PC 0x0c03734c */
if(!s->budget--) { s->failed_pc=0x0c03734cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03734e;
P_0c03734e: /* original 000b, guest PC 0x0c03734e */
if(!s->budget--) { s->failed_pc=0x0c03734eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c037350: /* original 0009, guest PC 0x0c037350 */
if(!s->budget--) { s->failed_pc=0x0c037350u; return 0; }
if(!vf3_matrix_family(0x0c037352u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c037352u; return 0; } return 1;
P_0c0376e0: /* original 4f22, guest PC 0x0c0376e0 */
if(!s->budget--) { s->failed_pc=0x0c0376e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0376e2;
P_0c0376e2: /* original 7ff8, guest PC 0x0c0376e2 */
if(!s->budget--) { s->failed_pc=0x0c0376e2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0376e4;
P_0c0376e4: /* original 2f42, guest PC 0x0c0376e4 */
if(!s->budget--) { s->failed_pc=0x0c0376e4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0376e6;
P_0c0376e6: /* original 1f51, guest PC 0x0c0376e6 */
if(!s->budget--) { s->failed_pc=0x0c0376e6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0376e8;
P_0c0376e8: /* original b01f, guest PC 0x0c0376e8 */
if(!s->budget--) { s->failed_pc=0x0c0376e8u; return 0; }
target=code_base|0x0c03772au; r[16]=code_base|0x0c0376ecu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0376ecu) { target=s->pc; goto dispatch; }
goto P_0c0376ec;
P_0c0376ea: /* original 64f2, guest PC 0x0c0376ea */
if(!s->budget--) { s->failed_pc=0x0c0376eau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0376ec;
P_0c0376ec: /* original 2008, guest PC 0x0c0376ec */
if(!s->budget--) { s->failed_pc=0x0c0376ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0376ee;
P_0c0376ee: /* original 8b03, guest PC 0x0c0376ee */
if(!s->budget--) { s->failed_pc=0x0c0376eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0376f8; }
goto P_0c0376f0;
P_0c0376f0: /* original 7f08, guest PC 0x0c0376f0 */
if(!s->budget--) { s->failed_pc=0x0c0376f0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0376f2;
P_0c0376f2: /* original 4f26, guest PC 0x0c0376f2 */
if(!s->budget--) { s->failed_pc=0x0c0376f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0376f4;
P_0c0376f4: /* original 000b, guest PC 0x0c0376f4 */
if(!s->budget--) { s->failed_pc=0x0c0376f4u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c0376f6: /* original e0ff, guest PC 0x0c0376f6 */
if(!s->budget--) { s->failed_pc=0x0c0376f6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0376f8;
P_0c0376f8: /* original e330, guest PC 0x0c0376f8 */
if(!s->budget--) { s->failed_pc=0x0c0376f8u; return 0; }
r[3]=0x00000030u;
goto P_0c0376fa;
P_0c0376fa: /* original 2f36, guest PC 0x0c0376fa */
if(!s->budget--) { s->failed_pc=0x0c0376fau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0376fc;
P_0c0376fc: /* original e100, guest PC 0x0c0376fc */
if(!s->budget--) { s->failed_pc=0x0c0376fcu; return 0; }
r[1]=0x00000000u;
goto P_0c0376fe;
P_0c0376fe: /* original 52f2, guest PC 0x0c0376fe */
if(!s->budget--) { s->failed_pc=0x0c0376feu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c037700;
P_0c037700: /* original e504, guest PC 0x0c037700 */
if(!s->budget--) { s->failed_pc=0x0c037700u; return 0; }
r[5]=0x00000004u;
goto P_0c037702;
P_0c037702: /* original 6613, guest PC 0x0c037702 */
if(!s->budget--) { s->failed_pc=0x0c037702u; return 0; }
r[6]=r[1];
goto P_0c037704;
P_0c037704: /* original 6713, guest PC 0x0c037704 */
if(!s->budget--) { s->failed_pc=0x0c037704u; return 0; }
r[7]=r[1];
goto P_0c037706;
P_0c037706: /* original 2f26, guest PC 0x0c037706 */
if(!s->budget--) { s->failed_pc=0x0c037706u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c037708;
P_0c037708: /* original 2f16, guest PC 0x0c037708 */
if(!s->budget--) { s->failed_pc=0x0c037708u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03770a;
P_0c03770a: /* original d223, guest PC 0x0c03770a */
if(!s->budget--) { s->failed_pc=0x0c03770au; return 0; }
r[2]=read(ram,0x0c037798u,4);
goto P_0c03770c;
P_0c03770c: /* original 420b, guest PC 0x0c03770c */
if(!s->budget--) { s->failed_pc=0x0c03770cu; return 0; }
target=r[2];
r[16]=code_base|0x0c037710u;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c037710u) { target=s->pc; goto dispatch; }
goto P_0c037710;
P_0c03770e: /* original 54f3, guest PC 0x0c03770e */
if(!s->budget--) { s->failed_pc=0x0c03770eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c037710;
P_0c037710: /* original 6403, guest PC 0x0c037710 */
if(!s->budget--) { s->failed_pc=0x0c037710u; return 0; }
r[4]=r[0];
goto P_0c037712;
P_0c037712: /* original 4411, guest PC 0x0c037712 */
if(!s->budget--) { s->failed_pc=0x0c037712u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c037714;
P_0c037714: /* original 8d04, guest PC 0x0c037714 */
if(!s->budget--) { s->failed_pc=0x0c037714u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c037720; }
goto P_0c037718;
P_0c037716: /* original 7f0c, guest PC 0x0c037716 */
if(!s->budget--) { s->failed_pc=0x0c037716u; return 0; }
r[15]+=0x0000000cu;
goto P_0c037718;
P_0c037718: /* original 7f08, guest PC 0x0c037718 */
if(!s->budget--) { s->failed_pc=0x0c037718u; return 0; }
r[15]+=0x00000008u;
goto P_0c03771a;
P_0c03771a: /* original 4f26, guest PC 0x0c03771a */
if(!s->budget--) { s->failed_pc=0x0c03771au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03771c;
P_0c03771c: /* original 000b, guest PC 0x0c03771c */
if(!s->budget--) { s->failed_pc=0x0c03771cu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c03771e: /* original 6043, guest PC 0x0c03771e */
if(!s->budget--) { s->failed_pc=0x0c03771eu; return 0; }
r[0]=r[4];
goto P_0c037720;
P_0c037720: /* original e000, guest PC 0x0c037720 */
if(!s->budget--) { s->failed_pc=0x0c037720u; return 0; }
r[0]=0x00000000u;
goto P_0c037722;
P_0c037722: /* original 7f08, guest PC 0x0c037722 */
if(!s->budget--) { s->failed_pc=0x0c037722u; return 0; }
r[15]+=0x00000008u;
goto P_0c037724;
P_0c037724: /* original 4f26, guest PC 0x0c037724 */
if(!s->budget--) { s->failed_pc=0x0c037724u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037726;
P_0c037726: /* original 000b, guest PC 0x0c037726 */
if(!s->budget--) { s->failed_pc=0x0c037726u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c037728: /* original 0009, guest PC 0x0c037728 */
if(!s->budget--) { s->failed_pc=0x0c037728u; return 0; }
goto P_0c03772a;
P_0c03772a: /* original 2fe6, guest PC 0x0c03772a */
if(!s->budget--) { s->failed_pc=0x0c03772au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03772c;
P_0c03772c: /* original 4f22, guest PC 0x0c03772c */
if(!s->budget--) { s->failed_pc=0x0c03772cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03772e;
P_0c03772e: /* original d31b, guest PC 0x0c03772e */
if(!s->budget--) { s->failed_pc=0x0c03772eu; return 0; }
r[3]=read(ram,0x0c03779cu,4);
goto P_0c037730;
P_0c037730: /* original 7ff4, guest PC 0x0c037730 */
if(!s->budget--) { s->failed_pc=0x0c037730u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c037732;
P_0c037732: /* original 430b, guest PC 0x0c037732 */
if(!s->budget--) { s->failed_pc=0x0c037732u; return 0; }
target=r[3];
r[16]=code_base|0x0c037736u;
write(ram,r[15],r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c037736u) { target=s->pc; goto dispatch; }
goto P_0c037736;
P_0c037734: /* original 2f42, guest PC 0x0c037734 */
if(!s->budget--) { s->failed_pc=0x0c037734u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c037736;
P_0c037736: /* original d21a, guest PC 0x0c037736 */
if(!s->budget--) { s->failed_pc=0x0c037736u; return 0; }
r[2]=read(ram,0x0c0377a0u,4);
goto P_0c037738;
P_0c037738: /* original 64f3, guest PC 0x0c037738 */
if(!s->budget--) { s->failed_pc=0x0c037738u; return 0; }
r[4]=r[15];
goto P_0c03773a;
P_0c03773a: /* original 6e03, guest PC 0x0c03773a */
if(!s->budget--) { s->failed_pc=0x0c03773au; return 0; }
r[14]=r[0];
goto P_0c03773c;
P_0c03773c: /* original 6503, guest PC 0x0c03773c */
if(!s->budget--) { s->failed_pc=0x0c03773cu; return 0; }
r[5]=r[0];
goto P_0c03773e;
P_0c03773e: /* original 420b, guest PC 0x0c03773e */
if(!s->budget--) { s->failed_pc=0x0c03773eu; return 0; }
target=r[2];
r[16]=code_base|0x0c037742u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c037742u) { target=s->pc; goto dispatch; }
goto P_0c037742;
P_0c037740: /* original 7404, guest PC 0x0c037740 */
if(!s->budget--) { s->failed_pc=0x0c037740u; return 0; }
r[4]+=0x00000004u;
goto P_0c037742;
P_0c037742: /* original 6403, guest PC 0x0c037742 */
if(!s->budget--) { s->failed_pc=0x0c037742u; return 0; }
r[4]=r[0];
goto P_0c037744;
P_0c037744: /* original 4411, guest PC 0x0c037744 */
if(!s->budget--) { s->failed_pc=0x0c037744u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c037746;
P_0c037746: /* original 8b15, guest PC 0x0c037746 */
if(!s->budget--) { s->failed_pc=0x0c037746u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037774; }
goto P_0c037748;
P_0c037748: /* original 60e2, guest PC 0x0c037748 */
if(!s->budget--) { s->failed_pc=0x0c037748u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03774a;
P_0c03774a: /* original 880e, guest PC 0x0c03774a */
if(!s->budget--) { s->failed_pc=0x0c03774au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c03774c;
P_0c03774c: /* original 8b12, guest PC 0x0c03774c */
if(!s->budget--) { s->failed_pc=0x0c03774cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037774; }
goto P_0c03774e;
P_0c03774e: /* original 85f2, guest PC 0x0c03774e */
if(!s->budget--) { s->failed_pc=0x0c03774eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c037750;
P_0c037750: /* original 600d, guest PC 0x0c037750 */
if(!s->budget--) { s->failed_pc=0x0c037750u; return 0; }
r[0]=r[0]&65535u;
goto P_0c037752;
P_0c037752: /* original 8801, guest PC 0x0c037752 */
if(!s->budget--) { s->failed_pc=0x0c037752u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c037754;
P_0c037754: /* original 8b0e, guest PC 0x0c037754 */
if(!s->budget--) { s->failed_pc=0x0c037754u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037774; }
goto P_0c037756;
P_0c037756: /* original 85f3, guest PC 0x0c037756 */
if(!s->budget--) { s->failed_pc=0x0c037756u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+6,2);
goto P_0c037758;
P_0c037758: /* original 9319, guest PC 0x0c037758 */
if(!s->budget--) { s->failed_pc=0x0c037758u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03778eu,2);
goto P_0c03775a;
P_0c03775a: /* original 600d, guest PC 0x0c03775a */
if(!s->budget--) { s->failed_pc=0x0c03775au; return 0; }
r[0]=r[0]&65535u;
goto P_0c03775c;
P_0c03775c: /* original 3030, guest PC 0x0c03775c */
if(!s->budget--) { s->failed_pc=0x0c03775cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c03775e;
P_0c03775e: /* original 8b09, guest PC 0x0c03775e */
if(!s->budget--) { s->failed_pc=0x0c03775eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037774; }
goto P_0c037760;
P_0c037760: /* original 85f4, guest PC 0x0c037760 */
if(!s->budget--) { s->failed_pc=0x0c037760u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c037762;
P_0c037762: /* original 600d, guest PC 0x0c037762 */
if(!s->budget--) { s->failed_pc=0x0c037762u; return 0; }
r[0]=r[0]&65535u;
goto P_0c037764;
P_0c037764: /* original 8801, guest PC 0x0c037764 */
if(!s->budget--) { s->failed_pc=0x0c037764u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c037766;
P_0c037766: /* original 8b05, guest PC 0x0c037766 */
if(!s->budget--) { s->failed_pc=0x0c037766u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037774; }
goto P_0c037768;
P_0c037768: /* original 84fa, guest PC 0x0c037768 */
if(!s->budget--) { s->failed_pc=0x0c037768u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+10,1);
goto P_0c03776a;
P_0c03776a: /* original 2008, guest PC 0x0c03776a */
if(!s->budget--) { s->failed_pc=0x0c03776au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03776c;
P_0c03776c: /* original 8b02, guest PC 0x0c03776c */
if(!s->budget--) { s->failed_pc=0x0c03776cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037774; }
goto P_0c03776e;
P_0c03776e: /* original 84fb, guest PC 0x0c03776e */
if(!s->budget--) { s->failed_pc=0x0c03776eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+11,1);
goto P_0c037770;
P_0c037770: /* original 2008, guest PC 0x0c037770 */
if(!s->budget--) { s->failed_pc=0x0c037770u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c037772;
P_0c037772: /* original 8904, guest PC 0x0c037772 */
if(!s->budget--) { s->failed_pc=0x0c037772u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c03777eu,s,ram); }
goto P_0c037774;
P_0c037774: /* original 7f0c, guest PC 0x0c037774 */
if(!s->budget--) { s->failed_pc=0x0c037774u; return 0; }
r[15]+=0x0000000cu;
goto P_0c037776;
P_0c037776: /* original 4f26, guest PC 0x0c037776 */
if(!s->budget--) { s->failed_pc=0x0c037776u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037778;
P_0c037778: /* original e000, guest PC 0x0c037778 */
if(!s->budget--) { s->failed_pc=0x0c037778u; return 0; }
r[0]=0x00000000u;
goto P_0c03777a;
P_0c03777a: /* original 000b, guest PC 0x0c03777a */
if(!s->budget--) { s->failed_pc=0x0c03777au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03777c: /* original 6ef6, guest PC 0x0c03777c */
if(!s->budget--) { s->failed_pc=0x0c03777cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03777eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
