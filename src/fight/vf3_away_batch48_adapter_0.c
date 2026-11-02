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
int vf3_away_batch48_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0423b0u: goto P_0c0423b0;
case 0x0c0423b2u: goto P_0c0423b2;
case 0x0c0423b4u: goto P_0c0423b4;
case 0x0c0423b6u: goto P_0c0423b6;
case 0x0c0423b8u: goto P_0c0423b8;
case 0x0c0423bau: goto P_0c0423ba;
case 0x0c0423bcu: goto P_0c0423bc;
case 0x0c0423beu: goto P_0c0423be;
case 0x0c0423c0u: goto P_0c0423c0;
case 0x0c0423c2u: goto P_0c0423c2;
case 0x0c0423c4u: goto P_0c0423c4;
case 0x0c0423c6u: goto P_0c0423c6;
case 0x0c0423c8u: goto P_0c0423c8;
case 0x0c0423cau: goto P_0c0423ca;
case 0x0c0423ccu: goto P_0c0423cc;
case 0x0c0423ceu: goto P_0c0423ce;
case 0x0c0423d0u: goto P_0c0423d0;
case 0x0c0423d2u: goto P_0c0423d2;
case 0x0c0423d4u: goto P_0c0423d4;
case 0x0c0423d6u: goto P_0c0423d6;
case 0x0c0423d8u: goto P_0c0423d8;
case 0x0c0423dau: goto P_0c0423da;
case 0x0c0423dcu: goto P_0c0423dc;
case 0x0c0423deu: goto P_0c0423de;
case 0x0c0423e0u: goto P_0c0423e0;
case 0x0c0423e2u: goto P_0c0423e2;
case 0x0c0423e4u: goto P_0c0423e4;
case 0x0c0423e6u: goto P_0c0423e6;
case 0x0c0423e8u: goto P_0c0423e8;
case 0x0c0423eau: goto P_0c0423ea;
case 0x0c0423ecu: goto P_0c0423ec;
case 0x0c0423eeu: goto P_0c0423ee;
case 0x0c0423f0u: goto P_0c0423f0;
case 0x0c0423f2u: goto P_0c0423f2;
case 0x0c0423f4u: goto P_0c0423f4;
case 0x0c0423f6u: goto P_0c0423f6;
case 0x0c0423f8u: goto P_0c0423f8;
case 0x0c0423fau: goto P_0c0423fa;
case 0x0c0423fcu: goto P_0c0423fc;
case 0x0c0423feu: goto P_0c0423fe;
case 0x0c042400u: goto P_0c042400;
case 0x0c042402u: goto P_0c042402;
case 0x0c042404u: goto P_0c042404;
case 0x0c042406u: goto P_0c042406;
case 0x0c042408u: goto P_0c042408;
case 0x0c04240au: goto P_0c04240a;
case 0x0c04240cu: goto P_0c04240c;
case 0x0c04240eu: goto P_0c04240e;
case 0x0c042410u: goto P_0c042410;
case 0x0c042412u: goto P_0c042412;
case 0x0c042414u: goto P_0c042414;
case 0x0c042416u: goto P_0c042416;
case 0x0c042418u: goto P_0c042418;
case 0x0c04241au: goto P_0c04241a;
case 0x0c04241cu: goto P_0c04241c;
case 0x0c04241eu: goto P_0c04241e;
case 0x0c042420u: goto P_0c042420;
case 0x0c042422u: goto P_0c042422;
case 0x0c042424u: goto P_0c042424;
case 0x0c042426u: goto P_0c042426;
case 0x0c042428u: goto P_0c042428;
case 0x0c04242au: goto P_0c04242a;
case 0x0c04242cu: goto P_0c04242c;
case 0x0c04242eu: goto P_0c04242e;
case 0x0c042430u: goto P_0c042430;
case 0x0c042432u: goto P_0c042432;
case 0x0c042434u: goto P_0c042434;
case 0x0c042436u: goto P_0c042436;
case 0x0c042438u: goto P_0c042438;
case 0x0c04243au: goto P_0c04243a;
case 0x0c04243cu: goto P_0c04243c;
case 0x0c04243eu: goto P_0c04243e;
case 0x0c042440u: goto P_0c042440;
case 0x0c042442u: goto P_0c042442;
case 0x0c042444u: goto P_0c042444;
case 0x0c042446u: goto P_0c042446;
case 0x0c042448u: goto P_0c042448;
case 0x0c04244au: goto P_0c04244a;
case 0x0c04244cu: goto P_0c04244c;
case 0x0c04244eu: goto P_0c04244e;
case 0x0c042450u: goto P_0c042450;
case 0x0c042460u: goto P_0c042460;
case 0x0c042462u: goto P_0c042462;
case 0x0c042464u: goto P_0c042464;
case 0x0c042466u: goto P_0c042466;
case 0x0c042468u: goto P_0c042468;
case 0x0c04246au: goto P_0c04246a;
case 0x0c04246cu: goto P_0c04246c;
case 0x0c04246eu: goto P_0c04246e;
case 0x0c042490u: goto P_0c042490;
case 0x0c042492u: goto P_0c042492;
case 0x0c042494u: goto P_0c042494;
case 0x0c042496u: goto P_0c042496;
case 0x0c042498u: goto P_0c042498;
case 0x0c04249au: goto P_0c04249a;
case 0x0c04249cu: goto P_0c04249c;
case 0x0c04249eu: goto P_0c04249e;
case 0x0c0424a0u: goto P_0c0424a0;
case 0x0c0424a2u: goto P_0c0424a2;
case 0x0c0424a4u: goto P_0c0424a4;
case 0x0c0424a6u: goto P_0c0424a6;
case 0x0c0424a8u: goto P_0c0424a8;
case 0x0c0424aau: goto P_0c0424aa;
case 0x0c0424acu: goto P_0c0424ac;
case 0x0c0424aeu: goto P_0c0424ae;
case 0x0c0424b0u: goto P_0c0424b0;
case 0x0c0424b2u: goto P_0c0424b2;
case 0x0c0424b4u: goto P_0c0424b4;
case 0x0c0424b6u: goto P_0c0424b6;
case 0x0c0425f0u: goto P_0c0425f0;
case 0x0c0425f2u: goto P_0c0425f2;
case 0x0c0425f4u: goto P_0c0425f4;
case 0x0c0425f6u: goto P_0c0425f6;
case 0x0c0425f8u: goto P_0c0425f8;
case 0x0c0425fau: goto P_0c0425fa;
case 0x0c0425fcu: goto P_0c0425fc;
case 0x0c042660u: goto P_0c042660;
case 0x0c042662u: goto P_0c042662;
case 0x0c042664u: goto P_0c042664;
case 0x0c042666u: goto P_0c042666;
case 0x0c042668u: goto P_0c042668;
case 0x0c04266au: goto P_0c04266a;
case 0x0c04266cu: goto P_0c04266c;
case 0x0c04266eu: goto P_0c04266e;
case 0x0c042670u: goto P_0c042670;
case 0x0c042672u: goto P_0c042672;
case 0x0c042674u: goto P_0c042674;
case 0x0c042676u: goto P_0c042676;
case 0x0c042678u: goto P_0c042678;
case 0x0c04267au: goto P_0c04267a;
case 0x0c04267cu: goto P_0c04267c;
case 0x0c04267eu: goto P_0c04267e;
case 0x0c042680u: goto P_0c042680;
case 0x0c042682u: goto P_0c042682;
case 0x0c042684u: goto P_0c042684;
case 0x0c042686u: goto P_0c042686;
case 0x0c042688u: goto P_0c042688;
case 0x0c04268au: goto P_0c04268a;
case 0x0c04268cu: goto P_0c04268c;
case 0x0c04268eu: goto P_0c04268e;
case 0x0c042690u: goto P_0c042690;
case 0x0c042692u: goto P_0c042692;
case 0x0c042694u: goto P_0c042694;
case 0x0c042696u: goto P_0c042696;
case 0x0c042698u: goto P_0c042698;
case 0x0c04269au: goto P_0c04269a;
case 0x0c04269cu: goto P_0c04269c;
case 0x0c04269eu: goto P_0c04269e;
case 0x0c0426a0u: goto P_0c0426a0;
case 0x0c0426a2u: goto P_0c0426a2;
case 0x0c0426a4u: goto P_0c0426a4;
case 0x0c0426a6u: goto P_0c0426a6;
case 0x0c0426a8u: goto P_0c0426a8;
case 0x0c0426aau: goto P_0c0426aa;
case 0x0c0426acu: goto P_0c0426ac;
case 0x0c0426aeu: goto P_0c0426ae;
case 0x0c0426b0u: goto P_0c0426b0;
case 0x0c0426b2u: goto P_0c0426b2;
case 0x0c0426b4u: goto P_0c0426b4;
case 0x0c0426b6u: goto P_0c0426b6;
case 0x0c0426b8u: goto P_0c0426b8;
case 0x0c0426bau: goto P_0c0426ba;
case 0x0c0426c0u: goto P_0c0426c0;
case 0x0c0426c2u: goto P_0c0426c2;
case 0x0c0426c4u: goto P_0c0426c4;
case 0x0c0426c6u: goto P_0c0426c6;
case 0x0c0426d0u: goto P_0c0426d0;
case 0x0c0426d2u: goto P_0c0426d2;
case 0x0c0426d4u: goto P_0c0426d4;
case 0x0c0426d6u: goto P_0c0426d6;
case 0x0c0426d8u: goto P_0c0426d8;
case 0x0c0426dau: goto P_0c0426da;
case 0x0c0426dcu: goto P_0c0426dc;
case 0x0c0426deu: goto P_0c0426de;
case 0x0c0426e0u: goto P_0c0426e0;
case 0x0c0426e2u: goto P_0c0426e2;
case 0x0c0426e4u: goto P_0c0426e4;
case 0x0c0426e6u: goto P_0c0426e6;
case 0x0c0426e8u: goto P_0c0426e8;
case 0x0c0426eau: goto P_0c0426ea;
case 0x0c0426ecu: goto P_0c0426ec;
case 0x0c0426eeu: goto P_0c0426ee;
case 0x0c0426f0u: goto P_0c0426f0;
case 0x0c0426f2u: goto P_0c0426f2;
case 0x0c0426f4u: goto P_0c0426f4;
case 0x0c0426f6u: goto P_0c0426f6;
case 0x0c0426f8u: goto P_0c0426f8;
case 0x0c0426fau: goto P_0c0426fa;
case 0x0c0426fcu: goto P_0c0426fc;
case 0x0c0426feu: goto P_0c0426fe;
case 0x0c042700u: goto P_0c042700;
case 0x0c042702u: goto P_0c042702;
case 0x0c042704u: goto P_0c042704;
case 0x0c042706u: goto P_0c042706;
case 0x0c042708u: goto P_0c042708;
case 0x0c04270au: goto P_0c04270a;
case 0x0c04270cu: goto P_0c04270c;
case 0x0c04270eu: goto P_0c04270e;
case 0x0c042710u: goto P_0c042710;
case 0x0c042740u: goto P_0c042740;
case 0x0c042742u: goto P_0c042742;
case 0x0c042744u: goto P_0c042744;
case 0x0c042746u: goto P_0c042746;
case 0x0c042748u: goto P_0c042748;
case 0x0c04274au: goto P_0c04274a;
case 0x0c04274cu: goto P_0c04274c;
case 0x0c04274eu: goto P_0c04274e;
case 0x0c042750u: goto P_0c042750;
case 0x0c042752u: goto P_0c042752;
case 0x0c042754u: goto P_0c042754;
case 0x0c042756u: goto P_0c042756;
case 0x0c042758u: goto P_0c042758;
case 0x0c04275au: goto P_0c04275a;
case 0x0c04275cu: goto P_0c04275c;
case 0x0c04275eu: goto P_0c04275e;
case 0x0c042760u: goto P_0c042760;
case 0x0c042762u: goto P_0c042762;
case 0x0c042764u: goto P_0c042764;
case 0x0c042766u: goto P_0c042766;
case 0x0c042768u: goto P_0c042768;
case 0x0c04276au: goto P_0c04276a;
case 0x0c04276cu: goto P_0c04276c;
case 0x0c04276eu: goto P_0c04276e;
case 0x0c042770u: goto P_0c042770;
case 0x0c042772u: goto P_0c042772;
case 0x0c042774u: goto P_0c042774;
case 0x0c042776u: goto P_0c042776;
case 0x0c042778u: goto P_0c042778;
case 0x0c04277au: goto P_0c04277a;
case 0x0c04277cu: goto P_0c04277c;
case 0x0c04277eu: goto P_0c04277e;
case 0x0c042780u: goto P_0c042780;
case 0x0c042782u: goto P_0c042782;
case 0x0c042784u: goto P_0c042784;
case 0x0c042786u: goto P_0c042786;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0423b0: /* original 2fe6, guest PC 0x0c0423b0 */
if(!s->budget--) { s->failed_pc=0x0c0423b0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b2;
P_0c0423b2: /* original 2fd6, guest PC 0x0c0423b2 */
if(!s->budget--) { s->failed_pc=0x0c0423b2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b4;
P_0c0423b4: /* original 2fc6, guest PC 0x0c0423b4 */
if(!s->budget--) { s->failed_pc=0x0c0423b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b6;
P_0c0423b6: /* original 2fb6, guest PC 0x0c0423b6 */
if(!s->budget--) { s->failed_pc=0x0c0423b6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b8;
P_0c0423b8: /* original 2fa6, guest PC 0x0c0423b8 */
if(!s->budget--) { s->failed_pc=0x0c0423b8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423ba;
P_0c0423ba: /* original 2f96, guest PC 0x0c0423ba */
if(!s->budget--) { s->failed_pc=0x0c0423bau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423bc;
P_0c0423bc: /* original 2f86, guest PC 0x0c0423bc */
if(!s->budget--) { s->failed_pc=0x0c0423bcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423be;
P_0c0423be: /* original d12c, guest PC 0x0c0423be */
if(!s->budget--) { s->failed_pc=0x0c0423beu; return 0; }
r[1]=read(ram,0x0c042470u,4);
goto P_0c0423c0;
P_0c0423c0: /* original 7ff4, guest PC 0x0c0423c0 */
if(!s->budget--) { s->failed_pc=0x0c0423c0u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0423c2;
P_0c0423c2: /* original 6e12, guest PC 0x0c0423c2 */
if(!s->budget--) { s->failed_pc=0x0c0423c2u; return 0; }
tmp=read(ram,r[1],4);
r[14]=tmp;
goto P_0c0423c4;
P_0c0423c4: /* original 2ee8, guest PC 0x0c0423c4 */
if(!s->budget--) { s->failed_pc=0x0c0423c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0423c6;
P_0c0423c6: /* original 893b, guest PC 0x0c0423c6 */
if(!s->budget--) { s->failed_pc=0x0c0423c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042440; }
goto P_0c0423c8;
P_0c0423c8: /* original 6df3, guest PC 0x0c0423c8 */
if(!s->budget--) { s->failed_pc=0x0c0423c8u; return 0; }
r[13]=r[15];
goto P_0c0423ca;
P_0c0423ca: /* original dc2c, guest PC 0x0c0423ca */
if(!s->budget--) { s->failed_pc=0x0c0423cau; return 0; }
r[12]=read(ram,0x0c04247cu,4);
goto P_0c0423cc;
P_0c0423cc: /* original 7d04, guest PC 0x0c0423cc */
if(!s->budget--) { s->failed_pc=0x0c0423ccu; return 0; }
r[13]+=0x00000004u;
goto P_0c0423ce;
P_0c0423ce: /* original 2d41, guest PC 0x0c0423ce */
if(!s->budget--) { s->failed_pc=0x0c0423ceu; return 0; }
write(ram,r[13],r[4],2);
goto P_0c0423d0;
P_0c0423d0: /* original 2c41, guest PC 0x0c0423d0 */
if(!s->budget--) { s->failed_pc=0x0c0423d0u; return 0; }
write(ram,r[12],r[4],2);
goto P_0c0423d2;
P_0c0423d2: /* original 6053, guest PC 0x0c0423d2 */
if(!s->budget--) { s->failed_pc=0x0c0423d2u; return 0; }
r[0]=r[5];
goto P_0c0423d4;
P_0c0423d4: /* original 0009, guest PC 0x0c0423d4 */
if(!s->budget--) { s->failed_pc=0x0c0423d4u; return 0; }
goto P_0c0423d6;
P_0c0423d6: /* original 81d1, guest PC 0x0c0423d6 */
if(!s->budget--) { s->failed_pc=0x0c0423d6u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c0423d8;
P_0c0423d8: /* original 81c1, guest PC 0x0c0423d8 */
if(!s->budget--) { s->failed_pc=0x0c0423d8u; return 0; }
write(ram,r[12]+2,r[0],2);
goto P_0c0423da;
P_0c0423da: /* original 6063, guest PC 0x0c0423da */
if(!s->budget--) { s->failed_pc=0x0c0423dau; return 0; }
r[0]=r[6];
goto P_0c0423dc;
P_0c0423dc: /* original 0009, guest PC 0x0c0423dc */
if(!s->budget--) { s->failed_pc=0x0c0423dcu; return 0; }
goto P_0c0423de;
P_0c0423de: /* original 81d2, guest PC 0x0c0423de */
if(!s->budget--) { s->failed_pc=0x0c0423deu; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c0423e0;
P_0c0423e0: /* original 81c2, guest PC 0x0c0423e0 */
if(!s->budget--) { s->failed_pc=0x0c0423e0u; return 0; }
write(ram,r[12]+4,r[0],2);
goto P_0c0423e2;
P_0c0423e2: /* original 6073, guest PC 0x0c0423e2 */
if(!s->budget--) { s->failed_pc=0x0c0423e2u; return 0; }
r[0]=r[7];
goto P_0c0423e4;
P_0c0423e4: /* original 0009, guest PC 0x0c0423e4 */
if(!s->budget--) { s->failed_pc=0x0c0423e4u; return 0; }
goto P_0c0423e6;
P_0c0423e6: /* original e500, guest PC 0x0c0423e6 */
if(!s->budget--) { s->failed_pc=0x0c0423e6u; return 0; }
r[5]=0x00000000u;
goto P_0c0423e8;
P_0c0423e8: /* original 81d3, guest PC 0x0c0423e8 */
if(!s->budget--) { s->failed_pc=0x0c0423e8u; return 0; }
write(ram,r[13]+6,r[0],2);
goto P_0c0423ea;
P_0c0423ea: /* original e404, guest PC 0x0c0423ea */
if(!s->budget--) { s->failed_pc=0x0c0423eau; return 0; }
r[4]=0x00000004u;
goto P_0c0423ec;
P_0c0423ec: /* original 6853, guest PC 0x0c0423ec */
if(!s->budget--) { s->failed_pc=0x0c0423ecu; return 0; }
r[8]=r[5];
goto P_0c0423ee;
P_0c0423ee: /* original 81c3, guest PC 0x0c0423ee */
if(!s->budget--) { s->failed_pc=0x0c0423eeu; return 0; }
write(ram,r[12]+6,r[0],2);
goto P_0c0423f0;
P_0c0423f0: /* original 6383, guest PC 0x0c0423f0 */
if(!s->budget--) { s->failed_pc=0x0c0423f0u; return 0; }
r[3]=r[8];
goto P_0c0423f2;
P_0c0423f2: /* original 4300, guest PC 0x0c0423f2 */
if(!s->budget--) { s->failed_pc=0x0c0423f2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0423f4;
P_0c0423f4: /* original 33dc, guest PC 0x0c0423f4 */
if(!s->budget--) { s->failed_pc=0x0c0423f4u; return 0; }
r[3]+=r[13];
goto P_0c0423f6;
P_0c0423f6: /* original 6c53, guest PC 0x0c0423f6 */
if(!s->budget--) { s->failed_pc=0x0c0423f6u; return 0; }
r[12]=r[5];
goto P_0c0423f8;
P_0c0423f8: /* original 2f32, guest PC 0x0c0423f8 */
if(!s->budget--) { s->failed_pc=0x0c0423f8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0423fa;
P_0c0423fa: /* original 69c3, guest PC 0x0c0423fa */
if(!s->budget--) { s->failed_pc=0x0c0423fau; return 0; }
r[9]=r[12];
goto P_0c0423fc;
P_0c0423fc: /* original 4900, guest PC 0x0c0423fc */
if(!s->budget--) { s->failed_pc=0x0c0423fcu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0423fe;
P_0c0423fe: /* original 39dc, guest PC 0x0c0423fe */
if(!s->budget--) { s->failed_pc=0x0c0423feu; return 0; }
r[9]+=r[13];
goto P_0c042400;
P_0c042400: /* original 6653, guest PC 0x0c042400 */
if(!s->budget--) { s->failed_pc=0x0c042400u; return 0; }
r[6]=r[5];
goto P_0c042402;
P_0c042402: /* original 6b63, guest PC 0x0c042402 */
if(!s->budget--) { s->failed_pc=0x0c042402u; return 0; }
r[11]=r[6];
goto P_0c042404;
P_0c042404: /* original 4b00, guest PC 0x0c042404 */
if(!s->budget--) { s->failed_pc=0x0c042404u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c042406;
P_0c042406: /* original ea00, guest PC 0x0c042406 */
if(!s->budget--) { s->failed_pc=0x0c042406u; return 0; }
r[10]=0x00000000u;
goto P_0c042408;
P_0c042408: /* original 6753, guest PC 0x0c042408 */
if(!s->budget--) { s->failed_pc=0x0c042408u; return 0; }
r[7]=r[5];
goto P_0c04240a;
P_0c04240a: /* original 3bdc, guest PC 0x0c04240a */
if(!s->budget--) { s->failed_pc=0x0c04240au; return 0; }
r[11]+=r[13];
goto P_0c04240c;
P_0c04240c: /* original 3adc, guest PC 0x0c04240c */
if(!s->budget--) { s->failed_pc=0x0c04240cu; return 0; }
r[10]+=r[13];
goto P_0c04240e;
P_0c04240e: /* original 62a5, guest PC 0x0c04240e */
if(!s->budget--) { s->failed_pc=0x0c04240eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[10]+=2;
r[2]=tmp;
goto P_0c042410;
P_0c042410: /* original 7701, guest PC 0x0c042410 */
if(!s->budget--) { s->failed_pc=0x0c042410u; return 0; }
r[7]+=0x00000001u;
goto P_0c042412;
P_0c042412: /* original 3743, guest PC 0x0c042412 */
if(!s->budget--) { s->failed_pc=0x0c042412u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[4])!=0);
goto P_0c042414;
P_0c042414: /* original 2e21, guest PC 0x0c042414 */
if(!s->budget--) { s->failed_pc=0x0c042414u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c042416;
P_0c042416: /* original 7e02, guest PC 0x0c042416 */
if(!s->budget--) { s->failed_pc=0x0c042416u; return 0; }
r[14]+=0x00000002u;
goto P_0c042418;
P_0c042418: /* original 62b1, guest PC 0x0c042418 */
if(!s->budget--) { s->failed_pc=0x0c042418u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[2]=tmp;
goto P_0c04241a;
P_0c04241a: /* original 2e21, guest PC 0x0c04241a */
if(!s->budget--) { s->failed_pc=0x0c04241au; return 0; }
write(ram,r[14],r[2],2);
goto P_0c04241c;
P_0c04241c: /* original 7e02, guest PC 0x0c04241c */
if(!s->budget--) { s->failed_pc=0x0c04241cu; return 0; }
r[14]+=0x00000002u;
goto P_0c04241e;
P_0c04241e: /* original 6291, guest PC 0x0c04241e */
if(!s->budget--) { s->failed_pc=0x0c04241eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[9],2);
r[2]=tmp;
goto P_0c042420;
P_0c042420: /* original 2e21, guest PC 0x0c042420 */
if(!s->budget--) { s->failed_pc=0x0c042420u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c042422;
P_0c042422: /* original 7e02, guest PC 0x0c042422 */
if(!s->budget--) { s->failed_pc=0x0c042422u; return 0; }
r[14]+=0x00000002u;
goto P_0c042424;
P_0c042424: /* original 62f2, guest PC 0x0c042424 */
if(!s->budget--) { s->failed_pc=0x0c042424u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c042426;
P_0c042426: /* original 6121, guest PC 0x0c042426 */
if(!s->budget--) { s->failed_pc=0x0c042426u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c042428;
P_0c042428: /* original 2e11, guest PC 0x0c042428 */
if(!s->budget--) { s->failed_pc=0x0c042428u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c04242a;
P_0c04242a: /* original 8ff0, guest PC 0x0c04242a */
if(!s->budget--) { s->failed_pc=0x0c04242au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000002u;
if(!cond) { goto P_0c04240e; }
goto P_0c04242e;
P_0c04242c: /* original 7e02, guest PC 0x0c04242c */
if(!s->budget--) { s->failed_pc=0x0c04242cu; return 0; }
r[14]+=0x00000002u;
goto P_0c04242e;
P_0c04242e: /* original 7601, guest PC 0x0c04242e */
if(!s->budget--) { s->failed_pc=0x0c04242eu; return 0; }
r[6]+=0x00000001u;
goto P_0c042430;
P_0c042430: /* original 3643, guest PC 0x0c042430 */
if(!s->budget--) { s->failed_pc=0x0c042430u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c042432;
P_0c042432: /* original 8be6, guest PC 0x0c042432 */
if(!s->budget--) { s->failed_pc=0x0c042432u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042402; }
goto P_0c042434;
P_0c042434: /* original 7c01, guest PC 0x0c042434 */
if(!s->budget--) { s->failed_pc=0x0c042434u; return 0; }
r[12]+=0x00000001u;
goto P_0c042436;
P_0c042436: /* original 3c43, guest PC 0x0c042436 */
if(!s->budget--) { s->failed_pc=0x0c042436u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[4])!=0);
goto P_0c042438;
P_0c042438: /* original 8bdf, guest PC 0x0c042438 */
if(!s->budget--) { s->failed_pc=0x0c042438u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0423fa; }
goto P_0c04243a;
P_0c04243a: /* original 7801, guest PC 0x0c04243a */
if(!s->budget--) { s->failed_pc=0x0c04243au; return 0; }
r[8]+=0x00000001u;
goto P_0c04243c;
P_0c04243c: /* original 3843, guest PC 0x0c04243c */
if(!s->budget--) { s->failed_pc=0x0c04243cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[4])!=0);
goto P_0c04243e;
P_0c04243e: /* original 8bd7, guest PC 0x0c04243e */
if(!s->budget--) { s->failed_pc=0x0c04243eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0423f0; }
goto P_0c042440;
P_0c042440: /* original 7f0c, guest PC 0x0c042440 */
if(!s->budget--) { s->failed_pc=0x0c042440u; return 0; }
r[15]+=0x0000000cu;
goto P_0c042442;
P_0c042442: /* original 68f6, guest PC 0x0c042442 */
if(!s->budget--) { s->failed_pc=0x0c042442u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c042444;
P_0c042444: /* original 69f6, guest PC 0x0c042444 */
if(!s->budget--) { s->failed_pc=0x0c042444u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c042446;
P_0c042446: /* original 6af6, guest PC 0x0c042446 */
if(!s->budget--) { s->failed_pc=0x0c042446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c042448;
P_0c042448: /* original 6bf6, guest PC 0x0c042448 */
if(!s->budget--) { s->failed_pc=0x0c042448u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04244a;
P_0c04244a: /* original 6cf6, guest PC 0x0c04244a */
if(!s->budget--) { s->failed_pc=0x0c04244au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04244c;
P_0c04244c: /* original 6df6, guest PC 0x0c04244c */
if(!s->budget--) { s->failed_pc=0x0c04244cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04244e;
P_0c04244e: /* original 000b, guest PC 0x0c04244e */
if(!s->budget--) { s->failed_pc=0x0c04244eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042450: /* original 6ef6, guest PC 0x0c042450 */
if(!s->budget--) { s->failed_pc=0x0c042450u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c042452u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042452u; return 0; } return 1;
P_0c042460: /* original d207, guest PC 0x0c042460 */
if(!s->budget--) { s->failed_pc=0x0c042460u; return 0; }
r[2]=read(ram,0x0c042480u,4);
goto P_0c042462;
P_0c042462: /* original e303, guest PC 0x0c042462 */
if(!s->budget--) { s->failed_pc=0x0c042462u; return 0; }
r[3]=0x00000003u;
goto P_0c042464;
P_0c042464: /* original 2439, guest PC 0x0c042464 */
if(!s->budget--) { s->failed_pc=0x0c042464u; return 0; }
r[4]&=r[3];
goto P_0c042466;
P_0c042466: /* original 2539, guest PC 0x0c042466 */
if(!s->budget--) { s->failed_pc=0x0c042466u; return 0; }
r[5]&=r[3];
goto P_0c042468;
P_0c042468: /* original 2240, guest PC 0x0c042468 */
if(!s->budget--) { s->failed_pc=0x0c042468u; return 0; }
write(ram,r[2],r[4],1);
goto P_0c04246a;
P_0c04246a: /* original d106, guest PC 0x0c04246a */
if(!s->budget--) { s->failed_pc=0x0c04246au; return 0; }
r[1]=read(ram,0x0c042484u,4);
goto P_0c04246c;
P_0c04246c: /* original 000b, guest PC 0x0c04246c */
if(!s->budget--) { s->failed_pc=0x0c04246cu; return 0; }
target=r[16];
write(ram,r[1],r[5],1);
s->pc=target; return ram->oob==0;
P_0c04246e: /* original 2150, guest PC 0x0c04246e */
if(!s->budget--) { s->failed_pc=0x0c04246eu; return 0; }
write(ram,r[1],r[5],1);
if(!vf3_matrix_family(0x0c042470u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042470u; return 0; } return 1;
P_0c042490: /* original d30a, guest PC 0x0c042490 */
if(!s->budget--) { s->failed_pc=0x0c042490u; return 0; }
r[3]=read(ram,0x0c0424bcu,4);
goto P_0c042492;
P_0c042492: /* original d20b, guest PC 0x0c042492 */
if(!s->budget--) { s->failed_pc=0x0c042492u; return 0; }
r[2]=read(ram,0x0c0424c0u,4);
goto P_0c042494;
P_0c042494: /* original 6530, guest PC 0x0c042494 */
if(!s->budget--) { s->failed_pc=0x0c042494u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c042496;
P_0c042496: /* original d10b, guest PC 0x0c042496 */
if(!s->budget--) { s->failed_pc=0x0c042496u; return 0; }
r[1]=read(ram,0x0c0424c4u,4);
goto P_0c042498;
P_0c042498: /* original 4f12, guest PC 0x0c042498 */
if(!s->budget--) { s->failed_pc=0x0c042498u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04249a;
P_0c04249a: /* original 0527, guest PC 0x0c04249a */
if(!s->budget--) { s->failed_pc=0x0c04249au; return 0; }
r[19]=r[5]*r[2];
goto P_0c04249c;
P_0c04249c: /* original 6412, guest PC 0x0c04249c */
if(!s->budget--) { s->failed_pc=0x0c04249cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c04249e;
P_0c04249e: /* original 2448, guest PC 0x0c04249e */
if(!s->budget--) { s->failed_pc=0x0c04249eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0424a0;
P_0c0424a0: /* original 8d08, guest PC 0x0c0424a0 */
if(!s->budget--) { s->failed_pc=0x0c0424a0u; return 0; }
cond=r[17]&1u;
r[5]=r[19];
if(cond) { goto P_0c0424b4; }
goto P_0c0424a4;
P_0c0424a2: /* original 051a, guest PC 0x0c0424a2 */
if(!s->budget--) { s->failed_pc=0x0c0424a2u; return 0; }
r[5]=r[19];
goto P_0c0424a4;
P_0c0424a4: /* original 9608, guest PC 0x0c0424a4 */
if(!s->budget--) { s->failed_pc=0x0c0424a4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0424b8u,2);
goto P_0c0424a6;
P_0c0424a6: /* original 364c, guest PC 0x0c0424a6 */
if(!s->budget--) { s->failed_pc=0x0c0424a6u; return 0; }
r[6]+=r[4];
goto P_0c0424a8;
P_0c0424a8: /* original d407, guest PC 0x0c0424a8 */
if(!s->budget--) { s->failed_pc=0x0c0424a8u; return 0; }
r[4]=read(ram,0x0c0424c8u,4);
goto P_0c0424aa;
P_0c0424aa: /* original 74ff, guest PC 0x0c0424aa */
if(!s->budget--) { s->failed_pc=0x0c0424aau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0424ac;
P_0c0424ac: /* original 2652, guest PC 0x0c0424ac */
if(!s->budget--) { s->failed_pc=0x0c0424acu; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0424ae;
P_0c0424ae: /* original 4411, guest PC 0x0c0424ae */
if(!s->budget--) { s->failed_pc=0x0c0424aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0424b0;
P_0c0424b0: /* original 8dfb, guest PC 0x0c0424b0 */
if(!s->budget--) { s->failed_pc=0x0c0424b0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(cond) { goto P_0c0424aa; }
goto P_0c0424b4;
P_0c0424b2: /* original 7604, guest PC 0x0c0424b2 */
if(!s->budget--) { s->failed_pc=0x0c0424b2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0424b4;
P_0c0424b4: /* original 000b, guest PC 0x0c0424b4 */
if(!s->budget--) { s->failed_pc=0x0c0424b4u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0424b6: /* original 4f16, guest PC 0x0c0424b6 */
if(!s->budget--) { s->failed_pc=0x0c0424b6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0424b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0424b8u; return 0; } return 1;
P_0c0425f0: /* original d316, guest PC 0x0c0425f0 */
if(!s->budget--) { s->failed_pc=0x0c0425f0u; return 0; }
r[3]=read(ram,0x0c04264cu,4);
goto P_0c0425f2;
P_0c0425f2: /* original 2342, guest PC 0x0c0425f2 */
if(!s->budget--) { s->failed_pc=0x0c0425f2u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0425f4;
P_0c0425f4: /* original d216, guest PC 0x0c0425f4 */
if(!s->budget--) { s->failed_pc=0x0c0425f4u; return 0; }
r[2]=read(ram,0x0c042650u,4);
goto P_0c0425f6;
P_0c0425f6: /* original 2242, guest PC 0x0c0425f6 */
if(!s->budget--) { s->failed_pc=0x0c0425f6u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0425f8;
P_0c0425f8: /* original d116, guest PC 0x0c0425f8 */
if(!s->budget--) { s->failed_pc=0x0c0425f8u; return 0; }
r[1]=read(ram,0x0c042654u,4);
goto P_0c0425fa;
P_0c0425fa: /* original 000b, guest PC 0x0c0425fa */
if(!s->budget--) { s->failed_pc=0x0c0425fau; return 0; }
target=r[16];
write(ram,r[1],r[5],4);
s->pc=target; return ram->oob==0;
P_0c0425fc: /* original 2152, guest PC 0x0c0425fc */
if(!s->budget--) { s->failed_pc=0x0c0425fcu; return 0; }
write(ram,r[1],r[5],4);
if(!vf3_matrix_family(0x0c0425feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0425feu; return 0; } return 1;
P_0c042660: /* original 2fe6, guest PC 0x0c042660 */
if(!s->budget--) { s->failed_pc=0x0c042660u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042662;
P_0c042662: /* original 6e43, guest PC 0x0c042662 */
if(!s->budget--) { s->failed_pc=0x0c042662u; return 0; }
r[14]=r[4];
goto P_0c042664;
P_0c042664: /* original 2fd6, guest PC 0x0c042664 */
if(!s->budget--) { s->failed_pc=0x0c042664u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042666;
P_0c042666: /* original e418, guest PC 0x0c042666 */
if(!s->budget--) { s->failed_pc=0x0c042666u; return 0; }
r[4]=0x00000018u;
goto P_0c042668;
P_0c042668: /* original 2fc6, guest PC 0x0c042668 */
if(!s->budget--) { s->failed_pc=0x0c042668u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04266a;
P_0c04266a: /* original 2fb6, guest PC 0x0c04266a */
if(!s->budget--) { s->failed_pc=0x0c04266au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04266c;
P_0c04266c: /* original 2fa6, guest PC 0x0c04266c */
if(!s->budget--) { s->failed_pc=0x0c04266cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04266e;
P_0c04266e: /* original 2f96, guest PC 0x0c04266e */
if(!s->budget--) { s->failed_pc=0x0c04266eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042670;
P_0c042670: /* original 2f86, guest PC 0x0c042670 */
if(!s->budget--) { s->failed_pc=0x0c042670u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042672;
P_0c042672: /* original 4f22, guest PC 0x0c042672 */
if(!s->budget--) { s->failed_pc=0x0c042672u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042674;
P_0c042674: /* original 7fa4, guest PC 0x0c042674 */
if(!s->budget--) { s->failed_pc=0x0c042674u; return 0; }
r[15]+=0xffffffa4u;
goto P_0c042676;
P_0c042676: /* original 6df3, guest PC 0x0c042676 */
if(!s->budget--) { s->failed_pc=0x0c042676u; return 0; }
r[13]=r[15];
goto P_0c042678;
P_0c042678: /* original 7d58, guest PC 0x0c042678 */
if(!s->budget--) { s->failed_pc=0x0c042678u; return 0; }
r[13]+=0x00000058u;
goto P_0c04267a;
P_0c04267a: /* original 6043, guest PC 0x0c04267a */
if(!s->budget--) { s->failed_pc=0x0c04267au; return 0; }
r[0]=r[4];
goto P_0c04267c;
P_0c04267c: /* original 0009, guest PC 0x0c04267c */
if(!s->budget--) { s->failed_pc=0x0c04267cu; return 0; }
goto P_0c04267e;
P_0c04267e: /* original 80d1, guest PC 0x0c04267e */
if(!s->budget--) { s->failed_pc=0x0c04267eu; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c042680;
P_0c042680: /* original 9347, guest PC 0x0c042680 */
if(!s->budget--) { s->failed_pc=0x0c042680u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042712u,2);
goto P_0c042682;
P_0c042682: /* original 3e33, guest PC 0x0c042682 */
if(!s->budget--) { s->failed_pc=0x0c042682u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c042684;
P_0c042684: /* original 8d02, guest PC 0x0c042684 */
if(!s->budget--) { s->failed_pc=0x0c042684u; return 0; }
cond=r[17]&1u;
write(ram,r[13],r[0],1);
if(cond) { goto P_0c04268c; }
goto P_0c042688;
P_0c042686: /* original 2d00, guest PC 0x0c042686 */
if(!s->budget--) { s->failed_pc=0x0c042686u; return 0; }
write(ram,r[13],r[0],1);
goto P_0c042688;
P_0c042688: /* original e10c, guest PC 0x0c042688 */
if(!s->budget--) { s->failed_pc=0x0c042688u; return 0; }
r[1]=0x0000000cu;
goto P_0c04268a;
P_0c04268a: /* original 2d10, guest PC 0x0c04268a */
if(!s->budget--) { s->failed_pc=0x0c04268au; return 0; }
write(ram,r[13],r[1],1);
goto P_0c04268c;
P_0c04268c: /* original d222, guest PC 0x0c04268c */
if(!s->budget--) { s->failed_pc=0x0c04268cu; return 0; }
r[2]=read(ram,0x0c042718u,4);
goto P_0c04268e;
P_0c04268e: /* original 6320, guest PC 0x0c04268e */
if(!s->budget--) { s->failed_pc=0x0c04268eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c042690;
P_0c042690: /* original 1f32, guest PC 0x0c042690 */
if(!s->budget--) { s->failed_pc=0x0c042690u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c042692;
P_0c042692: /* original d323, guest PC 0x0c042692 */
if(!s->budget--) { s->failed_pc=0x0c042692u; return 0; }
r[3]=read(ram,0x0c042720u,4);
goto P_0c042694;
P_0c042694: /* original d121, guest PC 0x0c042694 */
if(!s->budget--) { s->failed_pc=0x0c042694u; return 0; }
r[1]=read(ram,0x0c04271cu,4);
goto P_0c042696;
P_0c042696: /* original 6030, guest PC 0x0c042696 */
if(!s->budget--) { s->failed_pc=0x0c042696u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c042698;
P_0c042698: /* original 8801, guest PC 0x0c042698 */
if(!s->budget--) { s->failed_pc=0x0c042698u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04269a;
P_0c04269a: /* original 8f01, guest PC 0x0c04269a */
if(!s->budget--) { s->failed_pc=0x0c04269au; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[8]=tmp;
if(!cond) { goto P_0c0426a0; }
goto P_0c04269e;
P_0c04269c: /* original 6810, guest PC 0x0c04269c */
if(!s->budget--) { s->failed_pc=0x0c04269cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[8]=tmp;
goto P_0c04269e;
P_0c04269e: /* original e8ff, guest PC 0x0c04269e */
if(!s->budget--) { s->failed_pc=0x0c04269eu; return 0; }
r[8]=0xffffffffu;
goto P_0c0426a0;
P_0c0426a0: /* original b21e, guest PC 0x0c0426a0 */
if(!s->budget--) { s->failed_pc=0x0c0426a0u; return 0; }
target=code_base|0x0c042ae0u; r[16]=code_base|0x0c0426a4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0426a4u) { target=s->pc; goto dispatch; }
goto P_0c0426a4;
P_0c0426a2: /* original 64e3, guest PC 0x0c0426a2 */
if(!s->budget--) { s->failed_pc=0x0c0426a2u; return 0; }
r[4]=r[14];
goto P_0c0426a4;
P_0c0426a4: /* original d21f, guest PC 0x0c0426a4 */
if(!s->budget--) { s->failed_pc=0x0c0426a4u; return 0; }
r[2]=read(ram,0x0c042724u,4);
goto P_0c0426a6;
P_0c0426a6: /* original d320, guest PC 0x0c0426a6 */
if(!s->budget--) { s->failed_pc=0x0c0426a6u; return 0; }
r[3]=read(ram,0x0c042728u,4);
goto P_0c0426a8;
P_0c0426a8: /* original 6c22, guest PC 0x0c0426a8 */
if(!s->budget--) { s->failed_pc=0x0c0426a8u; return 0; }
tmp=read(ram,r[2],4);
r[12]=tmp;
goto P_0c0426aa;
P_0c0426aa: /* original 430b, guest PC 0x0c0426aa */
if(!s->budget--) { s->failed_pc=0x0c0426aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0426aeu;
r[12]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0426aeu) { target=s->pc; goto dispatch; }
goto P_0c0426ae;
P_0c0426ac: /* original 3c0c, guest PC 0x0c0426ac */
if(!s->budget--) { s->failed_pc=0x0c0426acu; return 0; }
r[12]+=r[0];
goto P_0c0426ae;
P_0c0426ae: /* original 2008, guest PC 0x0c0426ae */
if(!s->budget--) { s->failed_pc=0x0c0426aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0426b0;
P_0c0426b0: /* original 8b5a, guest PC 0x0c0426b0 */
if(!s->budget--) { s->failed_pc=0x0c0426b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042768; }
goto P_0c0426b2;
P_0c0426b2: /* original 932e, guest PC 0x0c0426b2 */
if(!s->budget--) { s->failed_pc=0x0c0426b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042712u,2);
goto P_0c0426b4;
P_0c0426b4: /* original 3e33, guest PC 0x0c0426b4 */
if(!s->budget--) { s->failed_pc=0x0c0426b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0426b6;
P_0c0426b6: /* original 8903, guest PC 0x0c0426b6 */
if(!s->budget--) { s->failed_pc=0x0c0426b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0426c0; }
goto P_0c0426b8;
P_0c0426b8: /* original a003, guest PC 0x0c0426b8 */
if(!s->budget--) { s->failed_pc=0x0c0426b8u; return 0; }
r[4]=0x00000024u;
goto P_0c0426c2;
P_0c0426ba: /* original e424, guest PC 0x0c0426ba */
if(!s->budget--) { s->failed_pc=0x0c0426bau; return 0; }
r[4]=0x00000024u;
if(!vf3_matrix_family(0x0c0426bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0426bcu; return 0; } return 1;
P_0c0426c0: /* original e448, guest PC 0x0c0426c0 */
if(!s->budget--) { s->failed_pc=0x0c0426c0u; return 0; }
r[4]=0x00000048u;
goto P_0c0426c2;
P_0c0426c2: /* original 65f3, guest PC 0x0c0426c2 */
if(!s->budget--) { s->failed_pc=0x0c0426c2u; return 0; }
r[5]=r[15];
goto P_0c0426c4;
P_0c0426c4: /* original a007, guest PC 0x0c0426c4 */
if(!s->budget--) { s->failed_pc=0x0c0426c4u; return 0; }
r[5]+=0x00000010u;
goto P_0c0426d6;
P_0c0426c6: /* original 7510, guest PC 0x0c0426c6 */
if(!s->budget--) { s->failed_pc=0x0c0426c6u; return 0; }
r[5]+=0x00000010u;
if(!vf3_matrix_family(0x0c0426c8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0426c8u; return 0; } return 1;
P_0c0426d0: /* original 63c4, guest PC 0x0c0426d0 */
if(!s->budget--) { s->failed_pc=0x0c0426d0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c0426d2;
P_0c0426d2: /* original 2530, guest PC 0x0c0426d2 */
if(!s->budget--) { s->failed_pc=0x0c0426d2u; return 0; }
write(ram,r[5],r[3],1);
goto P_0c0426d4;
P_0c0426d4: /* original 7501, guest PC 0x0c0426d4 */
if(!s->budget--) { s->failed_pc=0x0c0426d4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0426d6;
P_0c0426d6: /* original 4415, guest PC 0x0c0426d6 */
if(!s->budget--) { s->failed_pc=0x0c0426d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0426d8;
P_0c0426d8: /* original 8dfa, guest PC 0x0c0426d8 */
if(!s->budget--) { s->failed_pc=0x0c0426d8u; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c0426d0; }
goto P_0c0426dc;
P_0c0426da: /* original 74ff, guest PC 0x0c0426da */
if(!s->budget--) { s->failed_pc=0x0c0426dau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0426dc;
P_0c0426dc: /* original d213, guest PC 0x0c0426dc */
if(!s->budget--) { s->failed_pc=0x0c0426dcu; return 0; }
r[2]=read(ram,0x0c04272cu,4);
goto P_0c0426de;
P_0c0426de: /* original 420b, guest PC 0x0c0426de */
if(!s->budget--) { s->failed_pc=0x0c0426deu; return 0; }
target=r[2];
r[16]=code_base|0x0c0426e2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0426e2u) { target=s->pc; goto dispatch; }
goto P_0c0426e2;
P_0c0426e0: /* original 0009, guest PC 0x0c0426e0 */
if(!s->budget--) { s->failed_pc=0x0c0426e0u; return 0; }
goto P_0c0426e2;
P_0c0426e2: /* original 63f3, guest PC 0x0c0426e2 */
if(!s->budget--) { s->failed_pc=0x0c0426e2u; return 0; }
r[3]=r[15];
goto P_0c0426e4;
P_0c0426e4: /* original 7310, guest PC 0x0c0426e4 */
if(!s->budget--) { s->failed_pc=0x0c0426e4u; return 0; }
r[3]+=0x00000010u;
goto P_0c0426e6;
P_0c0426e6: /* original 1f33, guest PC 0x0c0426e6 */
if(!s->budget--) { s->failed_pc=0x0c0426e6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0426e8;
P_0c0426e8: /* original e900, guest PC 0x0c0426e8 */
if(!s->budget--) { s->failed_pc=0x0c0426e8u; return 0; }
r[9]=0x00000000u;
goto P_0c0426ea;
P_0c0426ea: /* original d111, guest PC 0x0c0426ea */
if(!s->budget--) { s->failed_pc=0x0c0426eau; return 0; }
r[1]=read(ram,0x0c042730u,4);
goto P_0c0426ec;
P_0c0426ec: /* original 6c93, guest PC 0x0c0426ec */
if(!s->budget--) { s->failed_pc=0x0c0426ecu; return 0; }
r[12]=r[9];
goto P_0c0426ee;
P_0c0426ee: /* original 6e93, guest PC 0x0c0426ee */
if(!s->budget--) { s->failed_pc=0x0c0426eeu; return 0; }
r[14]=r[9];
goto P_0c0426f0;
P_0c0426f0: /* original 6212, guest PC 0x0c0426f0 */
if(!s->budget--) { s->failed_pc=0x0c0426f0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0426f2;
P_0c0426f2: /* original 2f22, guest PC 0x0c0426f2 */
if(!s->budget--) { s->failed_pc=0x0c0426f2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0426f4;
P_0c0426f4: /* original d20f, guest PC 0x0c0426f4 */
if(!s->budget--) { s->failed_pc=0x0c0426f4u; return 0; }
r[2]=read(ram,0x0c042734u,4);
goto P_0c0426f6;
P_0c0426f6: /* original 6322, guest PC 0x0c0426f6 */
if(!s->budget--) { s->failed_pc=0x0c0426f6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0426f8;
P_0c0426f8: /* original 1f31, guest PC 0x0c0426f8 */
if(!s->budget--) { s->failed_pc=0x0c0426f8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0426fa;
P_0c0426fa: /* original 5bf3, guest PC 0x0c0426fa */
if(!s->budget--) { s->failed_pc=0x0c0426fau; return 0; }
r[11]=read(ram,r[15]+12,4);
goto P_0c0426fc;
P_0c0426fc: /* original ea08, guest PC 0x0c0426fc */
if(!s->budget--) { s->failed_pc=0x0c0426fcu; return 0; }
r[10]=0x00000008u;
goto P_0c0426fe;
P_0c0426fe: /* original 7b01, guest PC 0x0c0426fe */
if(!s->budget--) { s->failed_pc=0x0c0426feu; return 0; }
r[11]+=0x00000001u;
goto P_0c042700;
P_0c042700: /* original 1fb3, guest PC 0x0c042700 */
if(!s->budget--) { s->failed_pc=0x0c042700u; return 0; }
write(ram,r[15]+12,r[11],4);
goto P_0c042702;
P_0c042702: /* original 7bff, guest PC 0x0c042702 */
if(!s->budget--) { s->failed_pc=0x0c042702u; return 0; }
r[11]+=0xffffffffu;
goto P_0c042704;
P_0c042704: /* original 6bb0, guest PC 0x0c042704 */
if(!s->budget--) { s->failed_pc=0x0c042704u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]=tmp;
goto P_0c042706;
P_0c042706: /* original 9605, guest PC 0x0c042706 */
if(!s->budget--) { s->failed_pc=0x0c042706u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042714u,2);
goto P_0c042708;
P_0c042708: /* original 60bc, guest PC 0x0c042708 */
if(!s->budget--) { s->failed_pc=0x0c042708u; return 0; }
r[0]=r[11]&255u;
goto P_0c04270a;
P_0c04270a: /* original 2608, guest PC 0x0c04270a */
if(!s->budget--) { s->failed_pc=0x0c04270au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[0])==0)!=0);
goto P_0c04270c;
P_0c04270c: /* original 8918, guest PC 0x0c04270c */
if(!s->budget--) { s->failed_pc=0x0c04270cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042740; }
goto P_0c04270e;
P_0c04270e: /* original a018, guest PC 0x0c04270e */
if(!s->budget--) { s->failed_pc=0x0c04270eu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c042742;
P_0c042710: /* original 56f2, guest PC 0x0c042710 */
if(!s->budget--) { s->failed_pc=0x0c042710u; return 0; }
r[6]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(0x0c042712u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042712u; return 0; } return 1;
P_0c042740: /* original 6683, guest PC 0x0c042740 */
if(!s->budget--) { s->failed_pc=0x0c042740u; return 0; }
r[6]=r[8];
goto P_0c042742;
P_0c042742: /* original 55f1, guest PC 0x0c042742 */
if(!s->budget--) { s->failed_pc=0x0c042742u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c042744;
P_0c042744: /* original 64f2, guest PC 0x0c042744 */
if(!s->budget--) { s->failed_pc=0x0c042744u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c042746;
P_0c042746: /* original 35cc, guest PC 0x0c042746 */
if(!s->budget--) { s->failed_pc=0x0c042746u; return 0; }
r[5]+=r[12];
goto P_0c042748;
P_0c042748: /* original b132, guest PC 0x0c042748 */
if(!s->budget--) { s->failed_pc=0x0c042748u; return 0; }
target=code_base|0x0c0429b0u; r[16]=code_base|0x0c04274cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04274cu) { target=s->pc; goto dispatch; }
goto P_0c04274c;
P_0c04274a: /* original 34ec, guest PC 0x0c04274a */
if(!s->budget--) { s->failed_pc=0x0c04274au; return 0; }
r[4]+=r[14];
goto P_0c04274c;
P_0c04274c: /* original 62d0, guest PC 0x0c04274c */
if(!s->budget--) { s->failed_pc=0x0c04274cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[2]=tmp;
goto P_0c04274e;
P_0c04274e: /* original 7e01, guest PC 0x0c04274e */
if(!s->budget--) { s->failed_pc=0x0c04274eu; return 0; }
r[14]+=0x00000001u;
goto P_0c042750;
P_0c042750: /* original 4b00, guest PC 0x0c042750 */
if(!s->budget--) { s->failed_pc=0x0c042750u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c042752;
P_0c042752: /* original 622c, guest PC 0x0c042752 */
if(!s->budget--) { s->failed_pc=0x0c042752u; return 0; }
r[2]=r[2]&255u;
goto P_0c042754;
P_0c042754: /* original 3e23, guest PC 0x0c042754 */
if(!s->budget--) { s->failed_pc=0x0c042754u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c042756;
P_0c042756: /* original 8b01, guest PC 0x0c042756 */
if(!s->budget--) { s->failed_pc=0x0c042756u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04275c; }
goto P_0c042758;
P_0c042758: /* original 7c01, guest PC 0x0c042758 */
if(!s->budget--) { s->failed_pc=0x0c042758u; return 0; }
r[12]+=0x00000001u;
goto P_0c04275a;
P_0c04275a: /* original 6e93, guest PC 0x0c04275a */
if(!s->budget--) { s->failed_pc=0x0c04275au; return 0; }
r[14]=r[9];
goto P_0c04275c;
P_0c04275c: /* original 4a10, guest PC 0x0c04275c */
if(!s->budget--) { s->failed_pc=0x0c04275cu; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c04275e;
P_0c04275e: /* original 8bd2, guest PC 0x0c04275e */
if(!s->budget--) { s->failed_pc=0x0c04275eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042706; }
goto P_0c042760;
P_0c042760: /* original 84d1, guest PC 0x0c042760 */
if(!s->budget--) { s->failed_pc=0x0c042760u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+1,1);
goto P_0c042762;
P_0c042762: /* original 600c, guest PC 0x0c042762 */
if(!s->budget--) { s->failed_pc=0x0c042762u; return 0; }
r[0]=r[0]&255u;
goto P_0c042764;
P_0c042764: /* original 3c03, guest PC 0x0c042764 */
if(!s->budget--) { s->failed_pc=0x0c042764u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c042766;
P_0c042766: /* original 8bc8, guest PC 0x0c042766 */
if(!s->budget--) { s->failed_pc=0x0c042766u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0426fa; }
goto P_0c042768;
P_0c042768: /* original 7f5c, guest PC 0x0c042768 */
if(!s->budget--) { s->failed_pc=0x0c042768u; return 0; }
r[15]+=0x0000005cu;
goto P_0c04276a;
P_0c04276a: /* original d230, guest PC 0x0c04276a */
if(!s->budget--) { s->failed_pc=0x0c04276au; return 0; }
r[2]=read(ram,0x0c04282cu,4);
goto P_0c04276c;
P_0c04276c: /* original 4f26, guest PC 0x0c04276c */
if(!s->budget--) { s->failed_pc=0x0c04276cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04276e;
P_0c04276e: /* original 63d0, guest PC 0x0c04276e */
if(!s->budget--) { s->failed_pc=0x0c04276eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[3]=tmp;
goto P_0c042770;
P_0c042770: /* original 6122, guest PC 0x0c042770 */
if(!s->budget--) { s->failed_pc=0x0c042770u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c042772;
P_0c042772: /* original 633c, guest PC 0x0c042772 */
if(!s->budget--) { s->failed_pc=0x0c042772u; return 0; }
r[3]=r[3]&255u;
goto P_0c042774;
P_0c042774: /* original 313c, guest PC 0x0c042774 */
if(!s->budget--) { s->failed_pc=0x0c042774u; return 0; }
r[1]+=r[3];
goto P_0c042776;
P_0c042776: /* original 2212, guest PC 0x0c042776 */
if(!s->budget--) { s->failed_pc=0x0c042776u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c042778;
P_0c042778: /* original 68f6, guest PC 0x0c042778 */
if(!s->budget--) { s->failed_pc=0x0c042778u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04277a;
P_0c04277a: /* original 69f6, guest PC 0x0c04277a */
if(!s->budget--) { s->failed_pc=0x0c04277au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04277c;
P_0c04277c: /* original 6af6, guest PC 0x0c04277c */
if(!s->budget--) { s->failed_pc=0x0c04277cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04277e;
P_0c04277e: /* original 6bf6, guest PC 0x0c04277e */
if(!s->budget--) { s->failed_pc=0x0c04277eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c042780;
P_0c042780: /* original 6cf6, guest PC 0x0c042780 */
if(!s->budget--) { s->failed_pc=0x0c042780u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c042782;
P_0c042782: /* original 6df6, guest PC 0x0c042782 */
if(!s->budget--) { s->failed_pc=0x0c042782u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c042784;
P_0c042784: /* original 000b, guest PC 0x0c042784 */
if(!s->budget--) { s->failed_pc=0x0c042784u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042786: /* original 6ef6, guest PC 0x0c042786 */
if(!s->budget--) { s->failed_pc=0x0c042786u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c042788u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042788u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
