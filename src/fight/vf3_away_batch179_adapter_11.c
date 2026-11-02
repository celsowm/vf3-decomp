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
int vf3_away_batch179_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062490u: goto P_0c062490;
case 0x0c062492u: goto P_0c062492;
case 0x0c062494u: goto P_0c062494;
case 0x0c062496u: goto P_0c062496;
case 0x0c062498u: goto P_0c062498;
case 0x0c06249au: goto P_0c06249a;
case 0x0c06249cu: goto P_0c06249c;
case 0x0c06249eu: goto P_0c06249e;
case 0x0c0624a0u: goto P_0c0624a0;
case 0x0c0624a2u: goto P_0c0624a2;
case 0x0c0624a4u: goto P_0c0624a4;
case 0x0c0624a6u: goto P_0c0624a6;
case 0x0c0624a8u: goto P_0c0624a8;
case 0x0c0624aau: goto P_0c0624aa;
case 0x0c0624acu: goto P_0c0624ac;
case 0x0c0624aeu: goto P_0c0624ae;
case 0x0c0624b0u: goto P_0c0624b0;
case 0x0c0624b2u: goto P_0c0624b2;
case 0x0c0624b4u: goto P_0c0624b4;
case 0x0c0624b6u: goto P_0c0624b6;
case 0x0c0624b8u: goto P_0c0624b8;
case 0x0c0624bau: goto P_0c0624ba;
case 0x0c0624bcu: goto P_0c0624bc;
case 0x0c0624beu: goto P_0c0624be;
case 0x0c0624c0u: goto P_0c0624c0;
case 0x0c0624c2u: goto P_0c0624c2;
case 0x0c0624c4u: goto P_0c0624c4;
case 0x0c0624c6u: goto P_0c0624c6;
case 0x0c0624c8u: goto P_0c0624c8;
case 0x0c0624cau: goto P_0c0624ca;
case 0x0c0624ccu: goto P_0c0624cc;
case 0x0c0624ceu: goto P_0c0624ce;
case 0x0c0624d0u: goto P_0c0624d0;
case 0x0c0624d2u: goto P_0c0624d2;
case 0x0c0624d4u: goto P_0c0624d4;
case 0x0c0624d6u: goto P_0c0624d6;
case 0x0c0624d8u: goto P_0c0624d8;
case 0x0c0624dau: goto P_0c0624da;
case 0x0c0624dcu: goto P_0c0624dc;
case 0x0c0624deu: goto P_0c0624de;
case 0x0c0624e0u: goto P_0c0624e0;
case 0x0c0624e2u: goto P_0c0624e2;
case 0x0c0624e4u: goto P_0c0624e4;
case 0x0c0624e6u: goto P_0c0624e6;
case 0x0c0624e8u: goto P_0c0624e8;
case 0x0c0624eau: goto P_0c0624ea;
case 0x0c0624ecu: goto P_0c0624ec;
case 0x0c0624eeu: goto P_0c0624ee;
case 0x0c0624f0u: goto P_0c0624f0;
case 0x0c0624f2u: goto P_0c0624f2;
case 0x0c0624f4u: goto P_0c0624f4;
case 0x0c0624f6u: goto P_0c0624f6;
case 0x0c0624f8u: goto P_0c0624f8;
case 0x0c0624fau: goto P_0c0624fa;
case 0x0c0624fcu: goto P_0c0624fc;
case 0x0c0624feu: goto P_0c0624fe;
case 0x0c062500u: goto P_0c062500;
case 0x0c062502u: goto P_0c062502;
case 0x0c062504u: goto P_0c062504;
case 0x0c062506u: goto P_0c062506;
case 0x0c062508u: goto P_0c062508;
case 0x0c06250au: goto P_0c06250a;
case 0x0c06250cu: goto P_0c06250c;
case 0x0c06250eu: goto P_0c06250e;
case 0x0c062510u: goto P_0c062510;
case 0x0c062512u: goto P_0c062512;
case 0x0c062514u: goto P_0c062514;
case 0x0c062516u: goto P_0c062516;
case 0x0c062518u: goto P_0c062518;
case 0x0c06251au: goto P_0c06251a;
case 0x0c06251cu: goto P_0c06251c;
case 0x0c06251eu: goto P_0c06251e;
case 0x0c062520u: goto P_0c062520;
case 0x0c062522u: goto P_0c062522;
case 0x0c062524u: goto P_0c062524;
case 0x0c062526u: goto P_0c062526;
case 0x0c062528u: goto P_0c062528;
case 0x0c06252au: goto P_0c06252a;
case 0x0c06252cu: goto P_0c06252c;
case 0x0c06252eu: goto P_0c06252e;
case 0x0c062530u: goto P_0c062530;
case 0x0c062532u: goto P_0c062532;
case 0x0c062534u: goto P_0c062534;
case 0x0c062536u: goto P_0c062536;
case 0x0c062538u: goto P_0c062538;
case 0x0c06253au: goto P_0c06253a;
case 0x0c06253cu: goto P_0c06253c;
case 0x0c06253eu: goto P_0c06253e;
case 0x0c062540u: goto P_0c062540;
case 0x0c062542u: goto P_0c062542;
case 0x0c062544u: goto P_0c062544;
case 0x0c062546u: goto P_0c062546;
case 0x0c062548u: goto P_0c062548;
case 0x0c06254au: goto P_0c06254a;
case 0x0c06254cu: goto P_0c06254c;
case 0x0c06254eu: goto P_0c06254e;
case 0x0c062550u: goto P_0c062550;
case 0x0c062552u: goto P_0c062552;
case 0x0c062554u: goto P_0c062554;
case 0x0c062556u: goto P_0c062556;
case 0x0c062558u: goto P_0c062558;
case 0x0c06255au: goto P_0c06255a;
case 0x0c06255cu: goto P_0c06255c;
case 0x0c06255eu: goto P_0c06255e;
case 0x0c062560u: goto P_0c062560;
case 0x0c062562u: goto P_0c062562;
case 0x0c062564u: goto P_0c062564;
case 0x0c062566u: goto P_0c062566;
case 0x0c062568u: goto P_0c062568;
case 0x0c06256au: goto P_0c06256a;
case 0x0c06256cu: goto P_0c06256c;
case 0x0c06256eu: goto P_0c06256e;
case 0x0c062570u: goto P_0c062570;
case 0x0c062572u: goto P_0c062572;
case 0x0c062574u: goto P_0c062574;
case 0x0c062576u: goto P_0c062576;
case 0x0c062578u: goto P_0c062578;
case 0x0c06257au: goto P_0c06257a;
case 0x0c06257cu: goto P_0c06257c;
case 0x0c06257eu: goto P_0c06257e;
case 0x0c062580u: goto P_0c062580;
case 0x0c062582u: goto P_0c062582;
case 0x0c062584u: goto P_0c062584;
case 0x0c062586u: goto P_0c062586;
case 0x0c062588u: goto P_0c062588;
case 0x0c0625a0u: goto P_0c0625a0;
case 0x0c0625a2u: goto P_0c0625a2;
case 0x0c0625a4u: goto P_0c0625a4;
case 0x0c0625a6u: goto P_0c0625a6;
case 0x0c0625a8u: goto P_0c0625a8;
case 0x0c0625aau: goto P_0c0625aa;
case 0x0c0625acu: goto P_0c0625ac;
case 0x0c0625aeu: goto P_0c0625ae;
case 0x0c0625b0u: goto P_0c0625b0;
case 0x0c0625b2u: goto P_0c0625b2;
case 0x0c0625b4u: goto P_0c0625b4;
case 0x0c0625b6u: goto P_0c0625b6;
case 0x0c0625b8u: goto P_0c0625b8;
case 0x0c0625bau: goto P_0c0625ba;
case 0x0c0625bcu: goto P_0c0625bc;
case 0x0c0625beu: goto P_0c0625be;
case 0x0c0625c0u: goto P_0c0625c0;
case 0x0c0625c2u: goto P_0c0625c2;
case 0x0c0625c4u: goto P_0c0625c4;
case 0x0c0625c6u: goto P_0c0625c6;
case 0x0c0625c8u: goto P_0c0625c8;
case 0x0c0625cau: goto P_0c0625ca;
case 0x0c0625ccu: goto P_0c0625cc;
case 0x0c0625ceu: goto P_0c0625ce;
case 0x0c0625d0u: goto P_0c0625d0;
case 0x0c0625d2u: goto P_0c0625d2;
case 0x0c0625d4u: goto P_0c0625d4;
case 0x0c0625d6u: goto P_0c0625d6;
case 0x0c0625d8u: goto P_0c0625d8;
case 0x0c0625dau: goto P_0c0625da;
case 0x0c0625dcu: goto P_0c0625dc;
case 0x0c0625deu: goto P_0c0625de;
case 0x0c0625e0u: goto P_0c0625e0;
case 0x0c0625e2u: goto P_0c0625e2;
case 0x0c0625e4u: goto P_0c0625e4;
case 0x0c0625e6u: goto P_0c0625e6;
case 0x0c0625e8u: goto P_0c0625e8;
case 0x0c0625eau: goto P_0c0625ea;
case 0x0c0625ecu: goto P_0c0625ec;
case 0x0c0625eeu: goto P_0c0625ee;
case 0x0c0625f0u: goto P_0c0625f0;
case 0x0c0625f2u: goto P_0c0625f2;
case 0x0c0625f4u: goto P_0c0625f4;
case 0x0c0625f6u: goto P_0c0625f6;
case 0x0c0625f8u: goto P_0c0625f8;
case 0x0c0625fau: goto P_0c0625fa;
case 0x0c0625fcu: goto P_0c0625fc;
case 0x0c0625feu: goto P_0c0625fe;
case 0x0c062600u: goto P_0c062600;
case 0x0c062602u: goto P_0c062602;
case 0x0c062604u: goto P_0c062604;
case 0x0c062606u: goto P_0c062606;
case 0x0c062608u: goto P_0c062608;
case 0x0c06260au: goto P_0c06260a;
case 0x0c06260cu: goto P_0c06260c;
case 0x0c06260eu: goto P_0c06260e;
case 0x0c062610u: goto P_0c062610;
case 0x0c062612u: goto P_0c062612;
case 0x0c062614u: goto P_0c062614;
case 0x0c062616u: goto P_0c062616;
case 0x0c062618u: goto P_0c062618;
case 0x0c06261au: goto P_0c06261a;
case 0x0c06261cu: goto P_0c06261c;
case 0x0c06261eu: goto P_0c06261e;
case 0x0c062620u: goto P_0c062620;
case 0x0c062622u: goto P_0c062622;
case 0x0c062624u: goto P_0c062624;
case 0x0c062626u: goto P_0c062626;
case 0x0c062628u: goto P_0c062628;
case 0x0c06262au: goto P_0c06262a;
case 0x0c06262cu: goto P_0c06262c;
case 0x0c06262eu: goto P_0c06262e;
case 0x0c062630u: goto P_0c062630;
case 0x0c062632u: goto P_0c062632;
case 0x0c062634u: goto P_0c062634;
case 0x0c062636u: goto P_0c062636;
case 0x0c062638u: goto P_0c062638;
case 0x0c06263au: goto P_0c06263a;
case 0x0c06263cu: goto P_0c06263c;
case 0x0c06263eu: goto P_0c06263e;
case 0x0c062640u: goto P_0c062640;
case 0x0c062642u: goto P_0c062642;
case 0x0c062644u: goto P_0c062644;
case 0x0c062646u: goto P_0c062646;
case 0x0c062648u: goto P_0c062648;
case 0x0c06264au: goto P_0c06264a;
case 0x0c06264cu: goto P_0c06264c;
case 0x0c06264eu: goto P_0c06264e;
case 0x0c062650u: goto P_0c062650;
case 0x0c062652u: goto P_0c062652;
case 0x0c062654u: goto P_0c062654;
case 0x0c062656u: goto P_0c062656;
case 0x0c062658u: goto P_0c062658;
case 0x0c06265au: goto P_0c06265a;
case 0x0c06265cu: goto P_0c06265c;
case 0x0c06265eu: goto P_0c06265e;
case 0x0c062660u: goto P_0c062660;
case 0x0c062662u: goto P_0c062662;
case 0x0c062664u: goto P_0c062664;
case 0x0c062666u: goto P_0c062666;
case 0x0c062668u: goto P_0c062668;
case 0x0c06266au: goto P_0c06266a;
case 0x0c06266cu: goto P_0c06266c;
case 0x0c06266eu: goto P_0c06266e;
case 0x0c062670u: goto P_0c062670;
case 0x0c062672u: goto P_0c062672;
case 0x0c062674u: goto P_0c062674;
case 0x0c062676u: goto P_0c062676;
case 0x0c062678u: goto P_0c062678;
case 0x0c06267au: goto P_0c06267a;
case 0x0c06267cu: goto P_0c06267c;
case 0x0c06267eu: goto P_0c06267e;
case 0x0c062680u: goto P_0c062680;
case 0x0c062682u: goto P_0c062682;
case 0x0c062684u: goto P_0c062684;
case 0x0c062686u: goto P_0c062686;
case 0x0c062688u: goto P_0c062688;
case 0x0c06268au: goto P_0c06268a;
case 0x0c06268cu: goto P_0c06268c;
case 0x0c06268eu: goto P_0c06268e;
case 0x0c062690u: goto P_0c062690;
case 0x0c062692u: goto P_0c062692;
case 0x0c062694u: goto P_0c062694;
case 0x0c062696u: goto P_0c062696;
case 0x0c062698u: goto P_0c062698;
case 0x0c06269au: goto P_0c06269a;
case 0x0c06269cu: goto P_0c06269c;
case 0x0c06269eu: goto P_0c06269e;
case 0x0c0626a0u: goto P_0c0626a0;
case 0x0c0626a2u: goto P_0c0626a2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062490: /* original d53f, guest PC 0x0c062490 */
if(!s->budget--) { s->failed_pc=0x0c062490u; return 0; }
r[5]=read(ram,0x0c062590u,4);
goto P_0c062492;
P_0c062492: /* original e700, guest PC 0x0c062492 */
if(!s->budget--) { s->failed_pc=0x0c062492u; return 0; }
r[7]=0x00000000u;
goto P_0c062494;
P_0c062494: /* original 9079, guest PC 0x0c062494 */
if(!s->budget--) { s->failed_pc=0x0c062494u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06258au,2);
goto P_0c062496;
P_0c062496: /* original 6453, guest PC 0x0c062496 */
if(!s->budget--) { s->failed_pc=0x0c062496u; return 0; }
r[4]=r[5];
goto P_0c062498;
P_0c062498: /* original 6653, guest PC 0x0c062498 */
if(!s->budget--) { s->failed_pc=0x0c062498u; return 0; }
r[6]=r[5];
goto P_0c06249a;
P_0c06249a: /* original e501, guest PC 0x0c06249a */
if(!s->budget--) { s->failed_pc=0x0c06249au; return 0; }
r[5]=0x00000001u;
goto P_0c06249c;
P_0c06249c: /* original 6361, guest PC 0x0c06249c */
if(!s->budget--) { s->failed_pc=0x0c06249cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c06249e;
P_0c06249e: /* original 633d, guest PC 0x0c06249e */
if(!s->budget--) { s->failed_pc=0x0c06249eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0624a0;
P_0c0624a0: /* original 2358, guest PC 0x0c0624a0 */
if(!s->budget--) { s->failed_pc=0x0c0624a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0624a2;
P_0c0624a2: /* original 8b02, guest PC 0x0c0624a2 */
if(!s->budget--) { s->failed_pc=0x0c0624a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0624aa; }
goto P_0c0624a4;
P_0c0624a4: /* original 2451, guest PC 0x0c0624a4 */
if(!s->budget--) { s->failed_pc=0x0c0624a4u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0624a6;
P_0c0624a6: /* original 000b, guest PC 0x0c0624a6 */
if(!s->budget--) { s->failed_pc=0x0c0624a6u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0624a8: /* original 6043, guest PC 0x0c0624a8 */
if(!s->budget--) { s->failed_pc=0x0c0624a8u; return 0; }
r[0]=r[4];
goto P_0c0624aa;
P_0c0624aa: /* original 7701, guest PC 0x0c0624aa */
if(!s->budget--) { s->failed_pc=0x0c0624aau; return 0; }
r[7]+=0x00000001u;
goto P_0c0624ac;
P_0c0624ac: /* original 7418, guest PC 0x0c0624ac */
if(!s->budget--) { s->failed_pc=0x0c0624acu; return 0; }
r[4]+=0x00000018u;
goto P_0c0624ae;
P_0c0624ae: /* original 3703, guest PC 0x0c0624ae */
if(!s->budget--) { s->failed_pc=0x0c0624aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c0624b0;
P_0c0624b0: /* original 8ff4, guest PC 0x0c0624b0 */
if(!s->budget--) { s->failed_pc=0x0c0624b0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000018u;
if(!cond) { goto P_0c06249c; }
goto P_0c0624b4;
P_0c0624b2: /* original 7618, guest PC 0x0c0624b2 */
if(!s->budget--) { s->failed_pc=0x0c0624b2u; return 0; }
r[6]+=0x00000018u;
goto P_0c0624b4;
P_0c0624b4: /* original e000, guest PC 0x0c0624b4 */
if(!s->budget--) { s->failed_pc=0x0c0624b4u; return 0; }
r[0]=0x00000000u;
goto P_0c0624b6;
P_0c0624b6: /* original 000b, guest PC 0x0c0624b6 */
if(!s->budget--) { s->failed_pc=0x0c0624b6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0624b8: /* original 0009, guest PC 0x0c0624b8 */
if(!s->budget--) { s->failed_pc=0x0c0624b8u; return 0; }
goto P_0c0624ba;
P_0c0624ba: /* original e700, guest PC 0x0c0624ba */
if(!s->budget--) { s->failed_pc=0x0c0624bau; return 0; }
r[7]=0x00000000u;
goto P_0c0624bc;
P_0c0624bc: /* original d534, guest PC 0x0c0624bc */
if(!s->budget--) { s->failed_pc=0x0c0624bcu; return 0; }
r[5]=read(ram,0x0c062590u,4);
goto P_0c0624be;
P_0c0624be: /* original 2fd6, guest PC 0x0c0624be */
if(!s->budget--) { s->failed_pc=0x0c0624beu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0624c0;
P_0c0624c0: /* original dd34, guest PC 0x0c0624c0 */
if(!s->budget--) { s->failed_pc=0x0c0624c0u; return 0; }
r[13]=read(ram,0x0c062594u,4);
goto P_0c0624c2;
P_0c0624c2: /* original 6653, guest PC 0x0c0624c2 */
if(!s->budget--) { s->failed_pc=0x0c0624c2u; return 0; }
r[6]=r[5];
goto P_0c0624c4;
P_0c0624c4: /* original 9161, guest PC 0x0c0624c4 */
if(!s->budget--) { s->failed_pc=0x0c0624c4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06258au,2);
goto P_0c0624c6;
P_0c0624c6: /* original 7ffc, guest PC 0x0c0624c6 */
if(!s->budget--) { s->failed_pc=0x0c0624c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0624c8;
P_0c0624c8: /* original 2f52, guest PC 0x0c0624c8 */
if(!s->budget--) { s->failed_pc=0x0c0624c8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0624ca;
P_0c0624ca: /* original 3640, guest PC 0x0c0624ca */
if(!s->budget--) { s->failed_pc=0x0c0624cau; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c0624cc;
P_0c0624cc: /* original 8f03, guest PC 0x0c0624cc */
if(!s->budget--) { s->failed_pc=0x0c0624ccu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c0624d6; }
goto P_0c0624d0;
P_0c0624ce: /* original 7701, guest PC 0x0c0624ce */
if(!s->budget--) { s->failed_pc=0x0c0624ceu; return 0; }
r[7]+=0x00000001u;
goto P_0c0624d0;
P_0c0624d0: /* original 6251, guest PC 0x0c0624d0 */
if(!s->budget--) { s->failed_pc=0x0c0624d0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c0624d2;
P_0c0624d2: /* original 22d9, guest PC 0x0c0624d2 */
if(!s->budget--) { s->failed_pc=0x0c0624d2u; return 0; }
r[2]&=r[13];
goto P_0c0624d4;
P_0c0624d4: /* original 2521, guest PC 0x0c0624d4 */
if(!s->budget--) { s->failed_pc=0x0c0624d4u; return 0; }
write(ram,r[5],r[2],2);
goto P_0c0624d6;
P_0c0624d6: /* original 7518, guest PC 0x0c0624d6 */
if(!s->budget--) { s->failed_pc=0x0c0624d6u; return 0; }
r[5]+=0x00000018u;
goto P_0c0624d8;
P_0c0624d8: /* original 3713, guest PC 0x0c0624d8 */
if(!s->budget--) { s->failed_pc=0x0c0624d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c0624da;
P_0c0624da: /* original 8ff6, guest PC 0x0c0624da */
if(!s->budget--) { s->failed_pc=0x0c0624dau; return 0; }
cond=r[17]&1u;
r[6]+=0x00000018u;
if(!cond) { goto P_0c0624ca; }
goto P_0c0624de;
P_0c0624dc: /* original 7618, guest PC 0x0c0624dc */
if(!s->budget--) { s->failed_pc=0x0c0624dcu; return 0; }
r[6]+=0x00000018u;
goto P_0c0624de;
P_0c0624de: /* original 7f04, guest PC 0x0c0624de */
if(!s->budget--) { s->failed_pc=0x0c0624deu; return 0; }
r[15]+=0x00000004u;
goto P_0c0624e0;
P_0c0624e0: /* original 000b, guest PC 0x0c0624e0 */
if(!s->budget--) { s->failed_pc=0x0c0624e0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c0624e2: /* original 6df6, guest PC 0x0c0624e2 */
if(!s->budget--) { s->failed_pc=0x0c0624e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0624e4;
P_0c0624e4: /* original 6342, guest PC 0x0c0624e4 */
if(!s->budget--) { s->failed_pc=0x0c0624e4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0624e6;
P_0c0624e6: /* original 2338, guest PC 0x0c0624e6 */
if(!s->budget--) { s->failed_pc=0x0c0624e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0624e8;
P_0c0624e8: /* original 8b05, guest PC 0x0c0624e8 */
if(!s->budget--) { s->failed_pc=0x0c0624e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0624f6; }
goto P_0c0624ea;
P_0c0624ea: /* original e700, guest PC 0x0c0624ea */
if(!s->budget--) { s->failed_pc=0x0c0624eau; return 0; }
r[7]=0x00000000u;
goto P_0c0624ec;
P_0c0624ec: /* original 1671, guest PC 0x0c0624ec */
if(!s->budget--) { s->failed_pc=0x0c0624ecu; return 0; }
write(ram,r[6]+4,r[7],4);
goto P_0c0624ee;
P_0c0624ee: /* original 1672, guest PC 0x0c0624ee */
if(!s->budget--) { s->failed_pc=0x0c0624eeu; return 0; }
write(ram,r[6]+8,r[7],4);
goto P_0c0624f0;
P_0c0624f0: /* original 2462, guest PC 0x0c0624f0 */
if(!s->budget--) { s->failed_pc=0x0c0624f0u; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0624f2;
P_0c0624f2: /* original a007, guest PC 0x0c0624f2 */
if(!s->budget--) { s->failed_pc=0x0c0624f2u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c062504;
P_0c0624f4: /* original 2562, guest PC 0x0c0624f4 */
if(!s->budget--) { s->failed_pc=0x0c0624f4u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c0624f6;
P_0c0624f6: /* original 6542, guest PC 0x0c0624f6 */
if(!s->budget--) { s->failed_pc=0x0c0624f6u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0624f8;
P_0c0624f8: /* original 5251, guest PC 0x0c0624f8 */
if(!s->budget--) { s->failed_pc=0x0c0624f8u; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c0624fa;
P_0c0624fa: /* original 1621, guest PC 0x0c0624fa */
if(!s->budget--) { s->failed_pc=0x0c0624fau; return 0; }
write(ram,r[6]+4,r[2],4);
goto P_0c0624fc;
P_0c0624fc: /* original 6342, guest PC 0x0c0624fc */
if(!s->budget--) { s->failed_pc=0x0c0624fcu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0624fe;
P_0c0624fe: /* original 1632, guest PC 0x0c0624fe */
if(!s->budget--) { s->failed_pc=0x0c0624feu; return 0; }
write(ram,r[6]+8,r[3],4);
goto P_0c062500;
P_0c062500: /* original 1561, guest PC 0x0c062500 */
if(!s->budget--) { s->failed_pc=0x0c062500u; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c062502;
P_0c062502: /* original 2462, guest PC 0x0c062502 */
if(!s->budget--) { s->failed_pc=0x0c062502u; return 0; }
write(ram,r[4],r[6],4);
goto P_0c062504;
P_0c062504: /* original 000b, guest PC 0x0c062504 */
if(!s->budget--) { s->failed_pc=0x0c062504u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062506: /* original 0009, guest PC 0x0c062506 */
if(!s->budget--) { s->failed_pc=0x0c062506u; return 0; }
goto P_0c062508;
P_0c062508: /* original 5362, guest PC 0x0c062508 */
if(!s->budget--) { s->failed_pc=0x0c062508u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06250a;
P_0c06250a: /* original 2338, guest PC 0x0c06250a */
if(!s->budget--) { s->failed_pc=0x0c06250au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06250c;
P_0c06250c: /* original 8b03, guest PC 0x0c06250c */
if(!s->budget--) { s->failed_pc=0x0c06250cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062516; }
goto P_0c06250e;
P_0c06250e: /* original 2452, guest PC 0x0c06250e */
if(!s->budget--) { s->failed_pc=0x0c06250eu; return 0; }
write(ram,r[4],r[5],4);
goto P_0c062510;
P_0c062510: /* original 1561, guest PC 0x0c062510 */
if(!s->budget--) { s->failed_pc=0x0c062510u; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c062512;
P_0c062512: /* original a004, guest PC 0x0c062512 */
if(!s->budget--) { s->failed_pc=0x0c062512u; return 0; }
r[3]=0x00000000u;
goto P_0c06251e;
P_0c062514: /* original e300, guest PC 0x0c062514 */
if(!s->budget--) { s->failed_pc=0x0c062514u; return 0; }
r[3]=0x00000000u;
goto P_0c062516;
P_0c062516: /* original 5462, guest PC 0x0c062516 */
if(!s->budget--) { s->failed_pc=0x0c062516u; return 0; }
r[4]=read(ram,r[6]+8,4);
goto P_0c062518;
P_0c062518: /* original 1451, guest PC 0x0c062518 */
if(!s->budget--) { s->failed_pc=0x0c062518u; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c06251a;
P_0c06251a: /* original 1561, guest PC 0x0c06251a */
if(!s->budget--) { s->failed_pc=0x0c06251au; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c06251c;
P_0c06251c: /* original 5362, guest PC 0x0c06251c */
if(!s->budget--) { s->failed_pc=0x0c06251cu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06251e;
P_0c06251e: /* original 1532, guest PC 0x0c06251e */
if(!s->budget--) { s->failed_pc=0x0c06251eu; return 0; }
write(ram,r[5]+8,r[3],4);
goto P_0c062520;
P_0c062520: /* original 000b, guest PC 0x0c062520 */
if(!s->budget--) { s->failed_pc=0x0c062520u; return 0; }
target=r[16];
write(ram,r[6]+8,r[5],4);
s->pc=target; return ram->oob==0;
P_0c062522: /* original 1652, guest PC 0x0c062522 */
if(!s->budget--) { s->failed_pc=0x0c062522u; return 0; }
write(ram,r[6]+8,r[5],4);
goto P_0c062524;
P_0c062524: /* original 7ff8, guest PC 0x0c062524 */
if(!s->budget--) { s->failed_pc=0x0c062524u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c062526;
P_0c062526: /* original 5761, guest PC 0x0c062526 */
if(!s->budget--) { s->failed_pc=0x0c062526u; return 0; }
r[7]=read(ram,r[6]+4,4);
goto P_0c062528;
P_0c062528: /* original 2f72, guest PC 0x0c062528 */
if(!s->budget--) { s->failed_pc=0x0c062528u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c06252a;
P_0c06252a: /* original 2778, guest PC 0x0c06252a */
if(!s->budget--) { s->failed_pc=0x0c06252au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06252c;
P_0c06252c: /* original 5362, guest PC 0x0c06252c */
if(!s->budget--) { s->failed_pc=0x0c06252cu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06252e;
P_0c06252e: /* original 8f03, guest PC 0x0c06252e */
if(!s->budget--) { s->failed_pc=0x0c06252eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c062538; }
goto P_0c062532;
P_0c062530: /* original 1f31, guest PC 0x0c062530 */
if(!s->budget--) { s->failed_pc=0x0c062530u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c062532;
P_0c062532: /* original 5162, guest PC 0x0c062532 */
if(!s->budget--) { s->failed_pc=0x0c062532u; return 0; }
r[1]=read(ram,r[6]+8,4);
goto P_0c062534;
P_0c062534: /* original a003, guest PC 0x0c062534 */
if(!s->budget--) { s->failed_pc=0x0c062534u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c06253e;
P_0c062536: /* original 2412, guest PC 0x0c062536 */
if(!s->budget--) { s->failed_pc=0x0c062536u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c062538;
P_0c062538: /* original 62f2, guest PC 0x0c062538 */
if(!s->budget--) { s->failed_pc=0x0c062538u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06253a;
P_0c06253a: /* original 5362, guest PC 0x0c06253a */
if(!s->budget--) { s->failed_pc=0x0c06253au; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06253c;
P_0c06253c: /* original 1232, guest PC 0x0c06253c */
if(!s->budget--) { s->failed_pc=0x0c06253cu; return 0; }
write(ram,r[2]+8,r[3],4);
goto P_0c06253e;
P_0c06253e: /* original 5262, guest PC 0x0c06253e */
if(!s->budget--) { s->failed_pc=0x0c06253eu; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c062540;
P_0c062540: /* original 2228, guest PC 0x0c062540 */
if(!s->budget--) { s->failed_pc=0x0c062540u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c062542;
P_0c062542: /* original 8b02, guest PC 0x0c062542 */
if(!s->budget--) { s->failed_pc=0x0c062542u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06254a; }
goto P_0c062544;
P_0c062544: /* original 5261, guest PC 0x0c062544 */
if(!s->budget--) { s->failed_pc=0x0c062544u; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c062546;
P_0c062546: /* original a003, guest PC 0x0c062546 */
if(!s->budget--) { s->failed_pc=0x0c062546u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c062550;
P_0c062548: /* original 2522, guest PC 0x0c062548 */
if(!s->budget--) { s->failed_pc=0x0c062548u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c06254a;
P_0c06254a: /* original 51f1, guest PC 0x0c06254a */
if(!s->budget--) { s->failed_pc=0x0c06254au; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06254c;
P_0c06254c: /* original 5361, guest PC 0x0c06254c */
if(!s->budget--) { s->failed_pc=0x0c06254cu; return 0; }
r[3]=read(ram,r[6]+4,4);
goto P_0c06254e;
P_0c06254e: /* original 1131, guest PC 0x0c06254e */
if(!s->budget--) { s->failed_pc=0x0c06254eu; return 0; }
write(ram,r[1]+4,r[3],4);
goto P_0c062550;
P_0c062550: /* original 000b, guest PC 0x0c062550 */
if(!s->budget--) { s->failed_pc=0x0c062550u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c062552: /* original 7f08, guest PC 0x0c062552 */
if(!s->budget--) { s->failed_pc=0x0c062552u; return 0; }
r[15]+=0x00000008u;
goto P_0c062554;
P_0c062554: /* original 2fe6, guest PC 0x0c062554 */
if(!s->budget--) { s->failed_pc=0x0c062554u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062556;
P_0c062556: /* original 2fd6, guest PC 0x0c062556 */
if(!s->budget--) { s->failed_pc=0x0c062556u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062558;
P_0c062558: /* original 2fc6, guest PC 0x0c062558 */
if(!s->budget--) { s->failed_pc=0x0c062558u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06255a;
P_0c06255a: /* original 6d63, guest PC 0x0c06255a */
if(!s->budget--) { s->failed_pc=0x0c06255au; return 0; }
r[13]=r[6];
goto P_0c06255c;
P_0c06255c: /* original 9e17, guest PC 0x0c06255c */
if(!s->budget--) { s->failed_pc=0x0c06255cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06258eu,2);
goto P_0c06255e;
P_0c06255e: /* original 2fb6, guest PC 0x0c06255e */
if(!s->budget--) { s->failed_pc=0x0c06255eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062560;
P_0c062560: /* original 2fa6, guest PC 0x0c062560 */
if(!s->budget--) { s->failed_pc=0x0c062560u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062562;
P_0c062562: /* original 3de6, guest PC 0x0c062562 */
if(!s->budget--) { s->failed_pc=0x0c062562u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[14])!=0);
goto P_0c062564;
P_0c062564: /* original 9012, guest PC 0x0c062564 */
if(!s->budget--) { s->failed_pc=0x0c062564u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06258cu,2);
goto P_0c062566;
P_0c062566: /* original 2f96, guest PC 0x0c062566 */
if(!s->budget--) { s->failed_pc=0x0c062566u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062568;
P_0c062568: /* original 2f86, guest PC 0x0c062568 */
if(!s->budget--) { s->failed_pc=0x0c062568u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06256a;
P_0c06256a: /* original 6943, guest PC 0x0c06256a */
if(!s->budget--) { s->failed_pc=0x0c06256au; return 0; }
r[9]=r[4];
goto P_0c06256c;
P_0c06256c: /* original da0a, guest PC 0x0c06256c */
if(!s->budget--) { s->failed_pc=0x0c06256cu; return 0; }
r[10]=read(ram,0x0c062598u,4);
goto P_0c06256e;
P_0c06256e: /* original 4f22, guest PC 0x0c06256e */
if(!s->budget--) { s->failed_pc=0x0c06256eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c062570;
P_0c062570: /* original 3f0c, guest PC 0x0c062570 */
if(!s->budget--) { s->failed_pc=0x0c062570u; return 0; }
r[15]+=r[0];
goto P_0c062572;
P_0c062572: /* original 8f27, guest PC 0x0c062572 */
if(!s->budget--) { s->failed_pc=0x0c062572u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[5],4);
if(!cond) { goto P_0c0625c4; }
goto P_0c062576;
P_0c062574: /* original 2f52, guest PC 0x0c062574 */
if(!s->budget--) { s->failed_pc=0x0c062574u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062576;
P_0c062576: /* original 68f3, guest PC 0x0c062576 */
if(!s->budget--) { s->failed_pc=0x0c062576u; return 0; }
r[8]=r[15];
goto P_0c062578;
P_0c062578: /* original 7808, guest PC 0x0c062578 */
if(!s->budget--) { s->failed_pc=0x0c062578u; return 0; }
r[8]+=0x00000008u;
goto P_0c06257a;
P_0c06257a: /* original 66e3, guest PC 0x0c06257a */
if(!s->budget--) { s->failed_pc=0x0c06257au; return 0; }
r[6]=r[14];
goto P_0c06257c;
P_0c06257c: /* original 65f2, guest PC 0x0c06257c */
if(!s->budget--) { s->failed_pc=0x0c06257cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06257e;
P_0c06257e: /* original d307, guest PC 0x0c06257e */
if(!s->budget--) { s->failed_pc=0x0c06257eu; return 0; }
r[3]=read(ram,0x0c06259cu,4);
goto P_0c062580;
P_0c062580: /* original 430b, guest PC 0x0c062580 */
if(!s->budget--) { s->failed_pc=0x0c062580u; return 0; }
target=r[3];
r[16]=code_base|0x0c062584u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062584u) { target=s->pc; goto dispatch; }
goto P_0c062584;
P_0c062582: /* original 6483, guest PC 0x0c062582 */
if(!s->budget--) { s->failed_pc=0x0c062582u; return 0; }
r[4]=r[8];
goto P_0c062584;
P_0c062584: /* original 6c83, guest PC 0x0c062584 */
if(!s->budget--) { s->failed_pc=0x0c062584u; return 0; }
r[12]=r[8];
goto P_0c062586;
P_0c062586: /* original a00f, guest PC 0x0c062586 */
if(!s->budget--) { s->failed_pc=0x0c062586u; return 0; }
r[11]=0x00000040u;
goto P_0c0625a8;
P_0c062588: /* original eb40, guest PC 0x0c062588 */
if(!s->budget--) { s->failed_pc=0x0c062588u; return 0; }
r[11]=0x00000040u;
if(!vf3_matrix_family(0x0c06258au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06258au; return 0; } return 1;
P_0c0625a0: /* original 4a0b, guest PC 0x0c0625a0 */
if(!s->budget--) { s->failed_pc=0x0c0625a0u; return 0; }
target=r[10];
r[16]=code_base|0x0c0625a4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625a4u) { target=s->pc; goto dispatch; }
goto P_0c0625a4;
P_0c0625a2: /* original 64c3, guest PC 0x0c0625a2 */
if(!s->budget--) { s->failed_pc=0x0c0625a2u; return 0; }
r[4]=r[12];
goto P_0c0625a4;
P_0c0625a4: /* original 7c20, guest PC 0x0c0625a4 */
if(!s->budget--) { s->failed_pc=0x0c0625a4u; return 0; }
r[12]+=0x00000020u;
goto P_0c0625a6;
P_0c0625a6: /* original 7bff, guest PC 0x0c0625a6 */
if(!s->budget--) { s->failed_pc=0x0c0625a6u; return 0; }
r[11]+=0xffffffffu;
goto P_0c0625a8;
P_0c0625a8: /* original 2bb8, guest PC 0x0c0625a8 */
if(!s->budget--) { s->failed_pc=0x0c0625a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0625aa;
P_0c0625aa: /* original 8bf9, guest PC 0x0c0625aa */
if(!s->budget--) { s->failed_pc=0x0c0625aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0625a0; }
goto P_0c0625ac;
P_0c0625ac: /* original d23e, guest PC 0x0c0625ac */
if(!s->budget--) { s->failed_pc=0x0c0625acu; return 0; }
r[2]=read(ram,0x0c0626a8u,4);
goto P_0c0625ae;
P_0c0625ae: /* original 66e3, guest PC 0x0c0625ae */
if(!s->budget--) { s->failed_pc=0x0c0625aeu; return 0; }
r[6]=r[14];
goto P_0c0625b0;
P_0c0625b0: /* original 6583, guest PC 0x0c0625b0 */
if(!s->budget--) { s->failed_pc=0x0c0625b0u; return 0; }
r[5]=r[8];
goto P_0c0625b2;
P_0c0625b2: /* original 420b, guest PC 0x0c0625b2 */
if(!s->budget--) { s->failed_pc=0x0c0625b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0625b6u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625b6u) { target=s->pc; goto dispatch; }
goto P_0c0625b6;
P_0c0625b4: /* original 6493, guest PC 0x0c0625b4 */
if(!s->budget--) { s->failed_pc=0x0c0625b4u; return 0; }
r[4]=r[9];
goto P_0c0625b6;
P_0c0625b6: /* original 3de8, guest PC 0x0c0625b6 */
if(!s->budget--) { s->failed_pc=0x0c0625b6u; return 0; }
r[13]-=r[14];
goto P_0c0625b8;
P_0c0625b8: /* original 63f2, guest PC 0x0c0625b8 */
if(!s->budget--) { s->failed_pc=0x0c0625b8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0625ba;
P_0c0625ba: /* original 3de6, guest PC 0x0c0625ba */
if(!s->budget--) { s->failed_pc=0x0c0625bau; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[14])!=0);
goto P_0c0625bc;
P_0c0625bc: /* original 33ec, guest PC 0x0c0625bc */
if(!s->budget--) { s->failed_pc=0x0c0625bcu; return 0; }
r[3]+=r[14];
goto P_0c0625be;
P_0c0625be: /* original 2f32, guest PC 0x0c0625be */
if(!s->budget--) { s->failed_pc=0x0c0625beu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0625c0;
P_0c0625c0: /* original 8ddb, guest PC 0x0c0625c0 */
if(!s->budget--) { s->failed_pc=0x0c0625c0u; return 0; }
cond=r[17]&1u;
r[9]+=r[14];
if(cond) { goto P_0c06257a; }
goto P_0c0625c4;
P_0c0625c2: /* original 39ec, guest PC 0x0c0625c2 */
if(!s->budget--) { s->failed_pc=0x0c0625c2u; return 0; }
r[9]+=r[14];
goto P_0c0625c4;
P_0c0625c4: /* original 65f2, guest PC 0x0c0625c4 */
if(!s->budget--) { s->failed_pc=0x0c0625c4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0625c6;
P_0c0625c6: /* original 64f3, guest PC 0x0c0625c6 */
if(!s->budget--) { s->failed_pc=0x0c0625c6u; return 0; }
r[4]=r[15];
goto P_0c0625c8;
P_0c0625c8: /* original d338, guest PC 0x0c0625c8 */
if(!s->budget--) { s->failed_pc=0x0c0625c8u; return 0; }
r[3]=read(ram,0x0c0626acu,4);
goto P_0c0625ca;
P_0c0625ca: /* original 66d3, guest PC 0x0c0625ca */
if(!s->budget--) { s->failed_pc=0x0c0625cau; return 0; }
r[6]=r[13];
goto P_0c0625cc;
P_0c0625cc: /* original 7408, guest PC 0x0c0625cc */
if(!s->budget--) { s->failed_pc=0x0c0625ccu; return 0; }
r[4]+=0x00000008u;
goto P_0c0625ce;
P_0c0625ce: /* original 430b, guest PC 0x0c0625ce */
if(!s->budget--) { s->failed_pc=0x0c0625ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0625d2u;
write(ram,r[15]+4,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625d2u) { target=s->pc; goto dispatch; }
goto P_0c0625d2;
P_0c0625d0: /* original 1f41, guest PC 0x0c0625d0 */
if(!s->budget--) { s->failed_pc=0x0c0625d0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0625d2;
P_0c0625d2: /* original 5ef1, guest PC 0x0c0625d2 */
if(!s->budget--) { s->failed_pc=0x0c0625d2u; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c0625d4;
P_0c0625d4: /* original a004, guest PC 0x0c0625d4 */
if(!s->budget--) { s->failed_pc=0x0c0625d4u; return 0; }
r[12]=0x00000040u;
goto P_0c0625e0;
P_0c0625d6: /* original ec40, guest PC 0x0c0625d6 */
if(!s->budget--) { s->failed_pc=0x0c0625d6u; return 0; }
r[12]=0x00000040u;
goto P_0c0625d8;
P_0c0625d8: /* original 4a0b, guest PC 0x0c0625d8 */
if(!s->budget--) { s->failed_pc=0x0c0625d8u; return 0; }
target=r[10];
r[16]=code_base|0x0c0625dcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625dcu) { target=s->pc; goto dispatch; }
goto P_0c0625dc;
P_0c0625da: /* original 64e3, guest PC 0x0c0625da */
if(!s->budget--) { s->failed_pc=0x0c0625dau; return 0; }
r[4]=r[14];
goto P_0c0625dc;
P_0c0625dc: /* original 7e20, guest PC 0x0c0625dc */
if(!s->budget--) { s->failed_pc=0x0c0625dcu; return 0; }
r[14]+=0x00000020u;
goto P_0c0625de;
P_0c0625de: /* original 7cff, guest PC 0x0c0625de */
if(!s->budget--) { s->failed_pc=0x0c0625deu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0625e0;
P_0c0625e0: /* original 2cc8, guest PC 0x0c0625e0 */
if(!s->budget--) { s->failed_pc=0x0c0625e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0625e2;
P_0c0625e2: /* original 8bf9, guest PC 0x0c0625e2 */
if(!s->budget--) { s->failed_pc=0x0c0625e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0625d8; }
goto P_0c0625e4;
P_0c0625e4: /* original 55f1, guest PC 0x0c0625e4 */
if(!s->budget--) { s->failed_pc=0x0c0625e4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0625e6;
P_0c0625e6: /* original 66d3, guest PC 0x0c0625e6 */
if(!s->budget--) { s->failed_pc=0x0c0625e6u; return 0; }
r[6]=r[13];
goto P_0c0625e8;
P_0c0625e8: /* original d32f, guest PC 0x0c0625e8 */
if(!s->budget--) { s->failed_pc=0x0c0625e8u; return 0; }
r[3]=read(ram,0x0c0626a8u,4);
goto P_0c0625ea;
P_0c0625ea: /* original 430b, guest PC 0x0c0625ea */
if(!s->budget--) { s->failed_pc=0x0c0625eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0625eeu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625eeu) { target=s->pc; goto dispatch; }
goto P_0c0625ee;
P_0c0625ec: /* original 6493, guest PC 0x0c0625ec */
if(!s->budget--) { s->failed_pc=0x0c0625ecu; return 0; }
r[4]=r[9];
goto P_0c0625ee;
P_0c0625ee: /* original 9159, guest PC 0x0c0625ee */
if(!s->budget--) { s->failed_pc=0x0c0625eeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0626a4u,2);
goto P_0c0625f0;
P_0c0625f0: /* original 3f1c, guest PC 0x0c0625f0 */
if(!s->budget--) { s->failed_pc=0x0c0625f0u; return 0; }
r[15]+=r[1];
goto P_0c0625f2;
P_0c0625f2: /* original 4f26, guest PC 0x0c0625f2 */
if(!s->budget--) { s->failed_pc=0x0c0625f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0625f4;
P_0c0625f4: /* original 68f6, guest PC 0x0c0625f4 */
if(!s->budget--) { s->failed_pc=0x0c0625f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0625f6;
P_0c0625f6: /* original 69f6, guest PC 0x0c0625f6 */
if(!s->budget--) { s->failed_pc=0x0c0625f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0625f8;
P_0c0625f8: /* original 6af6, guest PC 0x0c0625f8 */
if(!s->budget--) { s->failed_pc=0x0c0625f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0625fa;
P_0c0625fa: /* original 6bf6, guest PC 0x0c0625fa */
if(!s->budget--) { s->failed_pc=0x0c0625fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0625fc;
P_0c0625fc: /* original 6cf6, guest PC 0x0c0625fc */
if(!s->budget--) { s->failed_pc=0x0c0625fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0625fe;
P_0c0625fe: /* original 6df6, guest PC 0x0c0625fe */
if(!s->budget--) { s->failed_pc=0x0c0625feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062600;
P_0c062600: /* original 000b, guest PC 0x0c062600 */
if(!s->budget--) { s->failed_pc=0x0c062600u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c062602: /* original 6ef6, guest PC 0x0c062602 */
if(!s->budget--) { s->failed_pc=0x0c062602u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c062604;
P_0c062604: /* original 2fe6, guest PC 0x0c062604 */
if(!s->budget--) { s->failed_pc=0x0c062604u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062606;
P_0c062606: /* original 2fd6, guest PC 0x0c062606 */
if(!s->budget--) { s->failed_pc=0x0c062606u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062608;
P_0c062608: /* original 2fc6, guest PC 0x0c062608 */
if(!s->budget--) { s->failed_pc=0x0c062608u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06260a;
P_0c06260a: /* original 6c53, guest PC 0x0c06260a */
if(!s->budget--) { s->failed_pc=0x0c06260au; return 0; }
r[12]=r[5];
goto P_0c06260c;
P_0c06260c: /* original 2fb6, guest PC 0x0c06260c */
if(!s->budget--) { s->failed_pc=0x0c06260cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06260e;
P_0c06260e: /* original 2fa6, guest PC 0x0c06260e */
if(!s->budget--) { s->failed_pc=0x0c06260eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062610;
P_0c062610: /* original 2f96, guest PC 0x0c062610 */
if(!s->budget--) { s->failed_pc=0x0c062610u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062612;
P_0c062612: /* original 6943, guest PC 0x0c062612 */
if(!s->budget--) { s->failed_pc=0x0c062612u; return 0; }
r[9]=r[4];
goto P_0c062614;
P_0c062614: /* original 2f86, guest PC 0x0c062614 */
if(!s->budget--) { s->failed_pc=0x0c062614u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062616;
P_0c062616: /* original 4f22, guest PC 0x0c062616 */
if(!s->budget--) { s->failed_pc=0x0c062616u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c062618;
P_0c062618: /* original 6392, guest PC 0x0c062618 */
if(!s->budget--) { s->failed_pc=0x0c062618u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c06261a;
P_0c06261a: /* original 2338, guest PC 0x0c06261a */
if(!s->budget--) { s->failed_pc=0x0c06261au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06261c;
P_0c06261c: /* original 8d39, guest PC 0x0c06261c */
if(!s->budget--) { s->failed_pc=0x0c06261cu; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(cond) { goto P_0c062692; }
goto P_0c062620;
P_0c06261e: /* original ea00, guest PC 0x0c06261e */
if(!s->budget--) { s->failed_pc=0x0c06261eu; return 0; }
r[10]=0x00000000u;
goto P_0c062620;
P_0c062620: /* original 6492, guest PC 0x0c062620 */
if(!s->budget--) { s->failed_pc=0x0c062620u; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c062622;
P_0c062622: /* original 6e43, guest PC 0x0c062622 */
if(!s->budget--) { s->failed_pc=0x0c062622u; return 0; }
r[14]=r[4];
goto P_0c062624;
P_0c062624: /* original 53e3, guest PC 0x0c062624 */
if(!s->budget--) { s->failed_pc=0x0c062624u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c062626;
P_0c062626: /* original 5243, guest PC 0x0c062626 */
if(!s->budget--) { s->failed_pc=0x0c062626u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c062628;
P_0c062628: /* original 3237, guest PC 0x0c062628 */
if(!s->budget--) { s->failed_pc=0x0c062628u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c06262a;
P_0c06262a: /* original 8b00, guest PC 0x0c06262a */
if(!s->budget--) { s->failed_pc=0x0c06262au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06262e; }
goto P_0c06262c;
P_0c06262c: /* original 6e43, guest PC 0x0c06262c */
if(!s->budget--) { s->failed_pc=0x0c06262cu; return 0; }
r[14]=r[4];
goto P_0c06262e;
P_0c06262e: /* original 5442, guest PC 0x0c06262e */
if(!s->budget--) { s->failed_pc=0x0c06262eu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c062630;
P_0c062630: /* original 2448, guest PC 0x0c062630 */
if(!s->budget--) { s->failed_pc=0x0c062630u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c062632;
P_0c062632: /* original 8ff7, guest PC 0x0c062632 */
if(!s->budget--) { s->failed_pc=0x0c062632u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000001u;
if(!cond) { goto P_0c062624; }
goto P_0c062636;
P_0c062634: /* original 7a01, guest PC 0x0c062634 */
if(!s->budget--) { s->failed_pc=0x0c062634u; return 0; }
r[10]+=0x00000001u;
goto P_0c062636;
P_0c062636: /* original e201, guest PC 0x0c062636 */
if(!s->budget--) { s->failed_pc=0x0c062636u; return 0; }
r[2]=0x00000001u;
goto P_0c062638;
P_0c062638: /* original 3a27, guest PC 0x0c062638 */
if(!s->budget--) { s->failed_pc=0x0c062638u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>(int32_t)r[2])!=0);
goto P_0c06263a;
P_0c06263a: /* original 8b2a, guest PC 0x0c06263a */
if(!s->budget--) { s->failed_pc=0x0c06263au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062692; }
goto P_0c06263c;
P_0c06263c: /* original 61c2, guest PC 0x0c06263c */
if(!s->budget--) { s->failed_pc=0x0c06263cu; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c06263e;
P_0c06263e: /* original 31e0, guest PC 0x0c06263e */
if(!s->budget--) { s->failed_pc=0x0c06263eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[14])!=0);
goto P_0c062640;
P_0c062640: /* original 8907, guest PC 0x0c062640 */
if(!s->budget--) { s->failed_pc=0x0c062640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062652; }
goto P_0c062642;
P_0c062642: /* original 66e3, guest PC 0x0c062642 */
if(!s->budget--) { s->failed_pc=0x0c062642u; return 0; }
r[6]=r[14];
goto P_0c062644;
P_0c062644: /* original 65c3, guest PC 0x0c062644 */
if(!s->budget--) { s->failed_pc=0x0c062644u; return 0; }
r[5]=r[12];
goto P_0c062646;
P_0c062646: /* original bf6d, guest PC 0x0c062646 */
if(!s->budget--) { s->failed_pc=0x0c062646u; return 0; }
target=code_base|0x0c062524u; r[16]=code_base|0x0c06264au;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06264au) { target=s->pc; goto dispatch; }
goto P_0c06264a;
P_0c062648: /* original 6493, guest PC 0x0c062648 */
if(!s->budget--) { s->failed_pc=0x0c062648u; return 0; }
r[4]=r[9];
goto P_0c06264a;
P_0c06264a: /* original 65e3, guest PC 0x0c06264a */
if(!s->budget--) { s->failed_pc=0x0c06264au; return 0; }
r[5]=r[14];
goto P_0c06264c;
P_0c06264c: /* original 66c2, guest PC 0x0c06264c */
if(!s->budget--) { s->failed_pc=0x0c06264cu; return 0; }
tmp=read(ram,r[12],4);
r[6]=tmp;
goto P_0c06264e;
P_0c06264e: /* original bf5b, guest PC 0x0c06264e */
if(!s->budget--) { s->failed_pc=0x0c06264eu; return 0; }
target=code_base|0x0c062508u; r[16]=code_base|0x0c062652u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062652u) { target=s->pc; goto dispatch; }
goto P_0c062652;
P_0c062650: /* original 64c3, guest PC 0x0c062650 */
if(!s->budget--) { s->failed_pc=0x0c062650u; return 0; }
r[4]=r[12];
goto P_0c062652;
P_0c062652: /* original 7afe, guest PC 0x0c062652 */
if(!s->budget--) { s->failed_pc=0x0c062652u; return 0; }
r[10]+=0xfffffffeu;
goto P_0c062654;
P_0c062654: /* original 6ba3, guest PC 0x0c062654 */
if(!s->budget--) { s->failed_pc=0x0c062654u; return 0; }
r[11]=r[10];
goto P_0c062656;
P_0c062656: /* original a01a, guest PC 0x0c062656 */
if(!s->budget--) { s->failed_pc=0x0c062656u; return 0; }
r[8]=0x00000000u;
goto P_0c06268e;
P_0c062658: /* original e800, guest PC 0x0c062658 */
if(!s->budget--) { s->failed_pc=0x0c062658u; return 0; }
r[8]=0x00000000u;
goto P_0c06265a;
P_0c06265a: /* original 4b15, guest PC 0x0c06265a */
if(!s->budget--) { s->failed_pc=0x0c06265au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c06265c;
P_0c06265c: /* original 6e92, guest PC 0x0c06265c */
if(!s->budget--) { s->failed_pc=0x0c06265cu; return 0; }
tmp=read(ram,r[9],4);
r[14]=tmp;
goto P_0c06265e;
P_0c06265e: /* original 6de3, guest PC 0x0c06265e */
if(!s->budget--) { s->failed_pc=0x0c06265eu; return 0; }
r[13]=r[14];
goto P_0c062660;
P_0c062660: /* original 8f09, guest PC 0x0c062660 */
if(!s->budget--) { s->failed_pc=0x0c062660u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c062676; }
goto P_0c062664;
P_0c062662: /* original e400, guest PC 0x0c062662 */
if(!s->budget--) { s->failed_pc=0x0c062662u; return 0; }
r[4]=0x00000000u;
goto P_0c062664;
P_0c062664: /* original 5ee2, guest PC 0x0c062664 */
if(!s->budget--) { s->failed_pc=0x0c062664u; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c062666;
P_0c062666: /* original 52d3, guest PC 0x0c062666 */
if(!s->budget--) { s->failed_pc=0x0c062666u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c062668;
P_0c062668: /* original 53e3, guest PC 0x0c062668 */
if(!s->budget--) { s->failed_pc=0x0c062668u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c06266a;
P_0c06266a: /* original 3327, guest PC 0x0c06266a */
if(!s->budget--) { s->failed_pc=0x0c06266au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c06266c;
P_0c06266c: /* original 8f01, guest PC 0x0c06266c */
if(!s->budget--) { s->failed_pc=0x0c06266cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c062672; }
goto P_0c062670;
P_0c06266e: /* original 7401, guest PC 0x0c06266e */
if(!s->budget--) { s->failed_pc=0x0c06266eu; return 0; }
r[4]+=0x00000001u;
goto P_0c062670;
P_0c062670: /* original 6de3, guest PC 0x0c062670 */
if(!s->budget--) { s->failed_pc=0x0c062670u; return 0; }
r[13]=r[14];
goto P_0c062672;
P_0c062672: /* original 34b3, guest PC 0x0c062672 */
if(!s->budget--) { s->failed_pc=0x0c062672u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[11])!=0);
goto P_0c062674;
P_0c062674: /* original 8bf6, guest PC 0x0c062674 */
if(!s->budget--) { s->failed_pc=0x0c062674u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062664; }
goto P_0c062676;
P_0c062676: /* original 3ed0, guest PC 0x0c062676 */
if(!s->budget--) { s->failed_pc=0x0c062676u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[13])!=0);
goto P_0c062678;
P_0c062678: /* original 8907, guest PC 0x0c062678 */
if(!s->budget--) { s->failed_pc=0x0c062678u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06268a; }
goto P_0c06267a;
P_0c06267a: /* original 66d3, guest PC 0x0c06267a */
if(!s->budget--) { s->failed_pc=0x0c06267au; return 0; }
r[6]=r[13];
goto P_0c06267c;
P_0c06267c: /* original 65c3, guest PC 0x0c06267c */
if(!s->budget--) { s->failed_pc=0x0c06267cu; return 0; }
r[5]=r[12];
goto P_0c06267e;
P_0c06267e: /* original bf51, guest PC 0x0c06267e */
if(!s->budget--) { s->failed_pc=0x0c06267eu; return 0; }
target=code_base|0x0c062524u; r[16]=code_base|0x0c062682u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062682u) { target=s->pc; goto dispatch; }
goto P_0c062682;
P_0c062680: /* original 6493, guest PC 0x0c062680 */
if(!s->budget--) { s->failed_pc=0x0c062680u; return 0; }
r[4]=r[9];
goto P_0c062682;
P_0c062682: /* original 66e3, guest PC 0x0c062682 */
if(!s->budget--) { s->failed_pc=0x0c062682u; return 0; }
r[6]=r[14];
goto P_0c062684;
P_0c062684: /* original 65d3, guest PC 0x0c062684 */
if(!s->budget--) { s->failed_pc=0x0c062684u; return 0; }
r[5]=r[13];
goto P_0c062686;
P_0c062686: /* original bf3f, guest PC 0x0c062686 */
if(!s->budget--) { s->failed_pc=0x0c062686u; return 0; }
target=code_base|0x0c062508u; r[16]=code_base|0x0c06268au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06268au) { target=s->pc; goto dispatch; }
goto P_0c06268a;
P_0c062688: /* original 64c3, guest PC 0x0c062688 */
if(!s->budget--) { s->failed_pc=0x0c062688u; return 0; }
r[4]=r[12];
goto P_0c06268a;
P_0c06268a: /* original 7bff, guest PC 0x0c06268a */
if(!s->budget--) { s->failed_pc=0x0c06268au; return 0; }
r[11]+=0xffffffffu;
goto P_0c06268c;
P_0c06268c: /* original 7801, guest PC 0x0c06268c */
if(!s->budget--) { s->failed_pc=0x0c06268cu; return 0; }
r[8]+=0x00000001u;
goto P_0c06268e;
P_0c06268e: /* original 38a3, guest PC 0x0c06268e */
if(!s->budget--) { s->failed_pc=0x0c06268eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[10])!=0);
goto P_0c062690;
P_0c062690: /* original 8be3, guest PC 0x0c062690 */
if(!s->budget--) { s->failed_pc=0x0c062690u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06265a; }
goto P_0c062692;
P_0c062692: /* original 4f26, guest PC 0x0c062692 */
if(!s->budget--) { s->failed_pc=0x0c062692u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c062694;
P_0c062694: /* original 68f6, guest PC 0x0c062694 */
if(!s->budget--) { s->failed_pc=0x0c062694u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c062696;
P_0c062696: /* original 69f6, guest PC 0x0c062696 */
if(!s->budget--) { s->failed_pc=0x0c062696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c062698;
P_0c062698: /* original 6af6, guest PC 0x0c062698 */
if(!s->budget--) { s->failed_pc=0x0c062698u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06269a;
P_0c06269a: /* original 6bf6, guest PC 0x0c06269a */
if(!s->budget--) { s->failed_pc=0x0c06269au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06269c;
P_0c06269c: /* original 6cf6, guest PC 0x0c06269c */
if(!s->budget--) { s->failed_pc=0x0c06269cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06269e;
P_0c06269e: /* original 6df6, guest PC 0x0c06269e */
if(!s->budget--) { s->failed_pc=0x0c06269eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0626a0;
P_0c0626a0: /* original 000b, guest PC 0x0c0626a0 */
if(!s->budget--) { s->failed_pc=0x0c0626a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0626a2: /* original 6ef6, guest PC 0x0c0626a2 */
if(!s->budget--) { s->failed_pc=0x0c0626a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0626a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0626a4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
