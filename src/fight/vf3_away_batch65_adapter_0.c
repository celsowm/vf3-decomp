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
int vf3_away_batch65_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0925ecu: goto P_0c0925ec;
case 0x0c0925eeu: goto P_0c0925ee;
case 0x0c0925f0u: goto P_0c0925f0;
case 0x0c0925f2u: goto P_0c0925f2;
case 0x0c0925f4u: goto P_0c0925f4;
case 0x0c0925f6u: goto P_0c0925f6;
case 0x0c0925f8u: goto P_0c0925f8;
case 0x0c0925fau: goto P_0c0925fa;
case 0x0c0925fcu: goto P_0c0925fc;
case 0x0c0925feu: goto P_0c0925fe;
case 0x0c092600u: goto P_0c092600;
case 0x0c092602u: goto P_0c092602;
case 0x0c092604u: goto P_0c092604;
case 0x0c092606u: goto P_0c092606;
case 0x0c092608u: goto P_0c092608;
case 0x0c09260au: goto P_0c09260a;
case 0x0c09260cu: goto P_0c09260c;
case 0x0c09260eu: goto P_0c09260e;
case 0x0c092610u: goto P_0c092610;
case 0x0c092612u: goto P_0c092612;
case 0x0c092614u: goto P_0c092614;
case 0x0c092616u: goto P_0c092616;
case 0x0c092618u: goto P_0c092618;
case 0x0c09261au: goto P_0c09261a;
case 0x0c09261cu: goto P_0c09261c;
case 0x0c09261eu: goto P_0c09261e;
case 0x0c092620u: goto P_0c092620;
case 0x0c092622u: goto P_0c092622;
case 0x0c092624u: goto P_0c092624;
case 0x0c092626u: goto P_0c092626;
case 0x0c092628u: goto P_0c092628;
case 0x0c09262au: goto P_0c09262a;
case 0x0c09262cu: goto P_0c09262c;
case 0x0c09262eu: goto P_0c09262e;
case 0x0c092630u: goto P_0c092630;
case 0x0c092632u: goto P_0c092632;
case 0x0c092634u: goto P_0c092634;
case 0x0c092636u: goto P_0c092636;
case 0x0c092638u: goto P_0c092638;
case 0x0c09263au: goto P_0c09263a;
case 0x0c09263cu: goto P_0c09263c;
case 0x0c09263eu: goto P_0c09263e;
case 0x0c092640u: goto P_0c092640;
case 0x0c092642u: goto P_0c092642;
case 0x0c092644u: goto P_0c092644;
case 0x0c092646u: goto P_0c092646;
case 0x0c092648u: goto P_0c092648;
case 0x0c09264au: goto P_0c09264a;
case 0x0c09264cu: goto P_0c09264c;
case 0x0c09264eu: goto P_0c09264e;
case 0x0c092650u: goto P_0c092650;
case 0x0c092652u: goto P_0c092652;
case 0x0c092654u: goto P_0c092654;
case 0x0c092656u: goto P_0c092656;
case 0x0c092658u: goto P_0c092658;
case 0x0c09265au: goto P_0c09265a;
case 0x0c09265cu: goto P_0c09265c;
case 0x0c09265eu: goto P_0c09265e;
case 0x0c092660u: goto P_0c092660;
case 0x0c092662u: goto P_0c092662;
case 0x0c092664u: goto P_0c092664;
case 0x0c092666u: goto P_0c092666;
case 0x0c092668u: goto P_0c092668;
case 0x0c09266au: goto P_0c09266a;
case 0x0c09266cu: goto P_0c09266c;
case 0x0c09266eu: goto P_0c09266e;
case 0x0c092670u: goto P_0c092670;
case 0x0c092672u: goto P_0c092672;
case 0x0c092674u: goto P_0c092674;
case 0x0c092676u: goto P_0c092676;
case 0x0c092678u: goto P_0c092678;
case 0x0c09267au: goto P_0c09267a;
case 0x0c09267cu: goto P_0c09267c;
case 0x0c09267eu: goto P_0c09267e;
case 0x0c092680u: goto P_0c092680;
case 0x0c092682u: goto P_0c092682;
case 0x0c092684u: goto P_0c092684;
case 0x0c092686u: goto P_0c092686;
case 0x0c092688u: goto P_0c092688;
case 0x0c09268au: goto P_0c09268a;
case 0x0c09268cu: goto P_0c09268c;
case 0x0c09268eu: goto P_0c09268e;
case 0x0c092690u: goto P_0c092690;
case 0x0c092692u: goto P_0c092692;
case 0x0c092694u: goto P_0c092694;
case 0x0c092696u: goto P_0c092696;
case 0x0c092698u: goto P_0c092698;
case 0x0c09269au: goto P_0c09269a;
case 0x0c09269cu: goto P_0c09269c;
case 0x0c09269eu: goto P_0c09269e;
case 0x0c0926a0u: goto P_0c0926a0;
case 0x0c0926a2u: goto P_0c0926a2;
case 0x0c0926a4u: goto P_0c0926a4;
case 0x0c0926a6u: goto P_0c0926a6;
case 0x0c0926a8u: goto P_0c0926a8;
case 0x0c0926aau: goto P_0c0926aa;
case 0x0c0926acu: goto P_0c0926ac;
case 0x0c0926aeu: goto P_0c0926ae;
case 0x0c0926b0u: goto P_0c0926b0;
case 0x0c0926b2u: goto P_0c0926b2;
case 0x0c0926b4u: goto P_0c0926b4;
case 0x0c0926b6u: goto P_0c0926b6;
case 0x0c0926b8u: goto P_0c0926b8;
case 0x0c0926bau: goto P_0c0926ba;
case 0x0c0926bcu: goto P_0c0926bc;
case 0x0c0926beu: goto P_0c0926be;
case 0x0c0926c0u: goto P_0c0926c0;
case 0x0c0926c2u: goto P_0c0926c2;
case 0x0c0926c4u: goto P_0c0926c4;
case 0x0c0926c6u: goto P_0c0926c6;
case 0x0c0926c8u: goto P_0c0926c8;
case 0x0c0926cau: goto P_0c0926ca;
case 0x0c0926ccu: goto P_0c0926cc;
case 0x0c0926ceu: goto P_0c0926ce;
case 0x0c0926d0u: goto P_0c0926d0;
case 0x0c0926d2u: goto P_0c0926d2;
case 0x0c0926d4u: goto P_0c0926d4;
case 0x0c0926d6u: goto P_0c0926d6;
case 0x0c0926d8u: goto P_0c0926d8;
case 0x0c0926dau: goto P_0c0926da;
case 0x0c0926dcu: goto P_0c0926dc;
case 0x0c0926deu: goto P_0c0926de;
case 0x0c0926e0u: goto P_0c0926e0;
case 0x0c0926e2u: goto P_0c0926e2;
case 0x0c0926e4u: goto P_0c0926e4;
case 0x0c0926e6u: goto P_0c0926e6;
case 0x0c0926e8u: goto P_0c0926e8;
case 0x0c0926eau: goto P_0c0926ea;
case 0x0c0926ecu: goto P_0c0926ec;
case 0x0c0926eeu: goto P_0c0926ee;
case 0x0c0926f0u: goto P_0c0926f0;
case 0x0c0926f2u: goto P_0c0926f2;
case 0x0c0926f4u: goto P_0c0926f4;
case 0x0c0926f6u: goto P_0c0926f6;
case 0x0c092720u: goto P_0c092720;
case 0x0c092722u: goto P_0c092722;
case 0x0c092724u: goto P_0c092724;
case 0x0c092726u: goto P_0c092726;
case 0x0c092728u: goto P_0c092728;
case 0x0c09272au: goto P_0c09272a;
case 0x0c09272cu: goto P_0c09272c;
case 0x0c09272eu: goto P_0c09272e;
case 0x0c092730u: goto P_0c092730;
case 0x0c092732u: goto P_0c092732;
case 0x0c092734u: goto P_0c092734;
case 0x0c092736u: goto P_0c092736;
case 0x0c092738u: goto P_0c092738;
case 0x0c09273au: goto P_0c09273a;
case 0x0c09273cu: goto P_0c09273c;
case 0x0c09273eu: goto P_0c09273e;
case 0x0c092740u: goto P_0c092740;
case 0x0c092742u: goto P_0c092742;
case 0x0c092744u: goto P_0c092744;
case 0x0c092746u: goto P_0c092746;
case 0x0c092748u: goto P_0c092748;
case 0x0c09274au: goto P_0c09274a;
case 0x0c09274cu: goto P_0c09274c;
case 0x0c09274eu: goto P_0c09274e;
case 0x0c092750u: goto P_0c092750;
case 0x0c092752u: goto P_0c092752;
case 0x0c092754u: goto P_0c092754;
case 0x0c092756u: goto P_0c092756;
case 0x0c092758u: goto P_0c092758;
case 0x0c09275au: goto P_0c09275a;
case 0x0c09275cu: goto P_0c09275c;
case 0x0c09275eu: goto P_0c09275e;
case 0x0c092760u: goto P_0c092760;
case 0x0c092762u: goto P_0c092762;
case 0x0c092764u: goto P_0c092764;
case 0x0c092766u: goto P_0c092766;
case 0x0c092768u: goto P_0c092768;
case 0x0c09276au: goto P_0c09276a;
case 0x0c09276cu: goto P_0c09276c;
case 0x0c09276eu: goto P_0c09276e;
case 0x0c092770u: goto P_0c092770;
case 0x0c092772u: goto P_0c092772;
case 0x0c092774u: goto P_0c092774;
case 0x0c092776u: goto P_0c092776;
case 0x0c092778u: goto P_0c092778;
case 0x0c09277au: goto P_0c09277a;
case 0x0c09277cu: goto P_0c09277c;
case 0x0c09277eu: goto P_0c09277e;
case 0x0c092780u: goto P_0c092780;
case 0x0c092782u: goto P_0c092782;
case 0x0c092784u: goto P_0c092784;
case 0x0c092786u: goto P_0c092786;
case 0x0c092788u: goto P_0c092788;
case 0x0c09278au: goto P_0c09278a;
case 0x0c09278cu: goto P_0c09278c;
case 0x0c09278eu: goto P_0c09278e;
case 0x0c092790u: goto P_0c092790;
case 0x0c092792u: goto P_0c092792;
case 0x0c092794u: goto P_0c092794;
case 0x0c092796u: goto P_0c092796;
case 0x0c092798u: goto P_0c092798;
case 0x0c09279au: goto P_0c09279a;
case 0x0c09279cu: goto P_0c09279c;
case 0x0c09279eu: goto P_0c09279e;
case 0x0c0927a0u: goto P_0c0927a0;
case 0x0c0927a2u: goto P_0c0927a2;
case 0x0c0927a4u: goto P_0c0927a4;
case 0x0c0927a6u: goto P_0c0927a6;
case 0x0c0927a8u: goto P_0c0927a8;
case 0x0c0927aau: goto P_0c0927aa;
case 0x0c0927acu: goto P_0c0927ac;
case 0x0c0927aeu: goto P_0c0927ae;
case 0x0c0927b0u: goto P_0c0927b0;
case 0x0c0927b2u: goto P_0c0927b2;
case 0x0c0927b4u: goto P_0c0927b4;
case 0x0c0927b6u: goto P_0c0927b6;
case 0x0c0927b8u: goto P_0c0927b8;
case 0x0c0927bau: goto P_0c0927ba;
case 0x0c0927bcu: goto P_0c0927bc;
case 0x0c0927beu: goto P_0c0927be;
case 0x0c0927c0u: goto P_0c0927c0;
case 0x0c0927c2u: goto P_0c0927c2;
case 0x0c0927c4u: goto P_0c0927c4;
case 0x0c0927c6u: goto P_0c0927c6;
case 0x0c0927c8u: goto P_0c0927c8;
case 0x0c0927cau: goto P_0c0927ca;
case 0x0c0927ccu: goto P_0c0927cc;
case 0x0c0927ceu: goto P_0c0927ce;
case 0x0c0927d0u: goto P_0c0927d0;
case 0x0c0927d2u: goto P_0c0927d2;
case 0x0c0927d4u: goto P_0c0927d4;
case 0x0c0927d6u: goto P_0c0927d6;
case 0x0c0927d8u: goto P_0c0927d8;
case 0x0c0927dau: goto P_0c0927da;
case 0x0c0927dcu: goto P_0c0927dc;
case 0x0c0927deu: goto P_0c0927de;
case 0x0c0927e0u: goto P_0c0927e0;
case 0x0c0927e2u: goto P_0c0927e2;
case 0x0c0927e4u: goto P_0c0927e4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0925ec: /* original 2fe6, guest PC 0x0c0925ec */
if(!s->budget--) { s->failed_pc=0x0c0925ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0925ee;
P_0c0925ee: /* original e061, guest PC 0x0c0925ee */
if(!s->budget--) { s->failed_pc=0x0c0925eeu; return 0; }
r[0]=0x00000061u;
goto P_0c0925f0;
P_0c0925f0: /* original 2fd6, guest PC 0x0c0925f0 */
if(!s->budget--) { s->failed_pc=0x0c0925f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0925f2;
P_0c0925f2: /* original e30c, guest PC 0x0c0925f2 */
if(!s->budget--) { s->failed_pc=0x0c0925f2u; return 0; }
r[3]=0x0000000cu;
goto P_0c0925f4;
P_0c0925f4: /* original 2fc6, guest PC 0x0c0925f4 */
if(!s->budget--) { s->failed_pc=0x0c0925f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0925f6;
P_0c0925f6: /* original ffdb, guest PC 0x0c0925f6 */
if(!s->budget--) { s->failed_pc=0x0c0925f6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0925f8;
P_0c0925f8: /* original ffcb, guest PC 0x0c0925f8 */
if(!s->budget--) { s->failed_pc=0x0c0925f8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0925fa;
P_0c0925fa: /* original 044c, guest PC 0x0c0925fa */
if(!s->budget--) { s->failed_pc=0x0c0925fau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0925fc;
P_0c0925fc: /* original 7ffc, guest PC 0x0c0925fc */
if(!s->budget--) { s->failed_pc=0x0c0925fcu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0925fe;
P_0c0925fe: /* original 644c, guest PC 0x0c0925fe */
if(!s->budget--) { s->failed_pc=0x0c0925feu; return 0; }
r[4]=r[4]&255u;
goto P_0c092600;
P_0c092600: /* original 3436, guest PC 0x0c092600 */
if(!s->budget--) { s->failed_pc=0x0c092600u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c092602;
P_0c092602: /* original 8b00, guest PC 0x0c092602 */
if(!s->budget--) { s->failed_pc=0x0c092602u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092606; }
goto P_0c092604;
P_0c092604: /* original 3438, guest PC 0x0c092604 */
if(!s->budget--) { s->failed_pc=0x0c092604u; return 0; }
r[4]-=r[3];
goto P_0c092606;
P_0c092606: /* original 6d43, guest PC 0x0c092606 */
if(!s->budget--) { s->failed_pc=0x0c092606u; return 0; }
r[13]=r[4];
goto P_0c092608;
P_0c092608: /* original d33d, guest PC 0x0c092608 */
if(!s->budget--) { s->failed_pc=0x0c092608u; return 0; }
r[3]=read(ram,0x0c092700u,4);
goto P_0c09260a;
P_0c09260a: /* original 4d08, guest PC 0x0c09260a */
if(!s->budget--) { s->failed_pc=0x0c09260au; return 0; }
r[13]<<=2;
goto P_0c09260c;
P_0c09260c: /* original dc3d, guest PC 0x0c09260c */
if(!s->budget--) { s->failed_pc=0x0c09260cu; return 0; }
r[12]=read(ram,0x0c092704u,4);
goto P_0c09260e;
P_0c09260e: /* original 4d08, guest PC 0x0c09260e */
if(!s->budget--) { s->failed_pc=0x0c09260eu; return 0; }
r[13]<<=2;
goto P_0c092610;
P_0c092610: /* original 3d3c, guest PC 0x0c092610 */
if(!s->budget--) { s->failed_pc=0x0c092610u; return 0; }
r[13]+=r[3];
goto P_0c092612;
P_0c092612: /* original 6ed5, guest PC 0x0c092612 */
if(!s->budget--) { s->failed_pc=0x0c092612u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[14]=tmp;
goto P_0c092614;
P_0c092614: /* original e200, guest PC 0x0c092614 */
if(!s->budget--) { s->failed_pc=0x0c092614u; return 0; }
r[2]=0x00000000u;
goto P_0c092616;
P_0c092616: /* original 3e26, guest PC 0x0c092616 */
if(!s->budget--) { s->failed_pc=0x0c092616u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[2])!=0);
goto P_0c092618;
P_0c092618: /* original 8b48, guest PC 0x0c092618 */
if(!s->budget--) { s->failed_pc=0x0c092618u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0926ac; }
goto P_0c09261a;
P_0c09261a: /* original 67d5, guest PC 0x0c09261a */
if(!s->budget--) { s->failed_pc=0x0c09261au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[7]=tmp;
goto P_0c09261c;
P_0c09261c: /* original 6373, guest PC 0x0c09261c */
if(!s->budget--) { s->failed_pc=0x0c09261cu; return 0; }
r[3]=r[7];
goto P_0c09261e;
P_0c09261e: /* original 4700, guest PC 0x0c09261e */
if(!s->budget--) { s->failed_pc=0x0c09261eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c092620;
P_0c092620: /* original 373c, guest PC 0x0c092620 */
if(!s->budget--) { s->failed_pc=0x0c092620u; return 0; }
r[7]+=r[3];
goto P_0c092622;
P_0c092622: /* original 4708, guest PC 0x0c092622 */
if(!s->budget--) { s->failed_pc=0x0c092622u; return 0; }
r[7]<<=2;
goto P_0c092624;
P_0c092624: /* original 37cc, guest PC 0x0c092624 */
if(!s->budget--) { s->failed_pc=0x0c092624u; return 0; }
r[7]+=r[12];
goto P_0c092626;
P_0c092626: /* original 6471, guest PC 0x0c092626 */
if(!s->budget--) { s->failed_pc=0x0c092626u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[4]=tmp;
goto P_0c092628;
P_0c092628: /* original 8571, guest PC 0x0c092628 */
if(!s->budget--) { s->failed_pc=0x0c092628u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+2,2);
goto P_0c09262a;
P_0c09262a: /* original 6343, guest PC 0x0c09262a */
if(!s->budget--) { s->failed_pc=0x0c09262au; return 0; }
r[3]=r[4];
goto P_0c09262c;
P_0c09262c: /* original 4400, guest PC 0x0c09262c */
if(!s->budget--) { s->failed_pc=0x0c09262cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09262e;
P_0c09262e: /* original 343c, guest PC 0x0c09262e */
if(!s->budget--) { s->failed_pc=0x0c09262eu; return 0; }
r[4]+=r[3];
goto P_0c092630;
P_0c092630: /* original 6303, guest PC 0x0c092630 */
if(!s->budget--) { s->failed_pc=0x0c092630u; return 0; }
r[3]=r[0];
goto P_0c092632;
P_0c092632: /* original 4408, guest PC 0x0c092632 */
if(!s->budget--) { s->failed_pc=0x0c092632u; return 0; }
r[4]<<=2;
goto P_0c092634;
P_0c092634: /* original 4400, guest PC 0x0c092634 */
if(!s->budget--) { s->failed_pc=0x0c092634u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c092636;
P_0c092636: /* original 345c, guest PC 0x0c092636 */
if(!s->budget--) { s->failed_pc=0x0c092636u; return 0; }
r[4]+=r[5];
goto P_0c092638;
P_0c092638: /* original f649, guest PC 0x0c092638 */
if(!s->budget--) { s->failed_pc=0x0c092638u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09263a;
P_0c09263a: /* original 4000, guest PC 0x0c09263a */
if(!s->budget--) { s->failed_pc=0x0c09263au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c09263c;
P_0c09263c: /* original 303c, guest PC 0x0c09263c */
if(!s->budget--) { s->failed_pc=0x0c09263cu; return 0; }
r[0]+=r[3];
goto P_0c09263e;
P_0c09263e: /* original 6363, guest PC 0x0c09263e */
if(!s->budget--) { s->failed_pc=0x0c09263eu; return 0; }
r[3]=r[6];
goto P_0c092640;
P_0c092640: /* original f549, guest PC 0x0c092640 */
if(!s->budget--) { s->failed_pc=0x0c092640u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092642;
P_0c092642: /* original 4008, guest PC 0x0c092642 */
if(!s->budget--) { s->failed_pc=0x0c092642u; return 0; }
r[0]<<=2;
goto P_0c092644;
P_0c092644: /* original 4000, guest PC 0x0c092644 */
if(!s->budget--) { s->failed_pc=0x0c092644u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c092646;
P_0c092646: /* original f449, guest PC 0x0c092646 */
if(!s->budget--) { s->failed_pc=0x0c092646u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092648;
P_0c092648: /* original 7340, guest PC 0x0c092648 */
if(!s->budget--) { s->failed_pc=0x0c092648u; return 0; }
r[3]+=0x00000040u;
goto P_0c09264a;
P_0c09264a: /* original f749, guest PC 0x0c09264a */
if(!s->budget--) { s->failed_pc=0x0c09264au; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09264c;
P_0c09264c: /* original f848, guest PC 0x0c09264c */
if(!s->budget--) { s->failed_pc=0x0c09264cu; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
goto P_0c09264e;
P_0c09264e: /* original 6453, guest PC 0x0c09264e */
if(!s->budget--) { s->failed_pc=0x0c09264eu; return 0; }
r[4]=r[5];
goto P_0c092650;
P_0c092650: /* original 340c, guest PC 0x0c092650 */
if(!s->budget--) { s->failed_pc=0x0c092650u; return 0; }
r[4]+=r[0];
goto P_0c092652;
P_0c092652: /* original fa49, guest PC 0x0c092652 */
if(!s->budget--) { s->failed_pc=0x0c092652u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092654;
P_0c092654: /* original f949, guest PC 0x0c092654 */
if(!s->budget--) { s->failed_pc=0x0c092654u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092656;
P_0c092656: /* original fc48, guest PC 0x0c092656 */
if(!s->budget--) { s->failed_pc=0x0c092656u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
goto P_0c092658;
P_0c092658: /* original 0383, guest PC 0x0c092658 */
if(!s->budget--) { s->failed_pc=0x0c092658u; return 0; }
if((r[3]&0xFC000000u)==0xE0000000u) pref(ram,r[3]);
goto P_0c09265a;
P_0c09265a: /* original f19c, guest PC 0x0c09265a */
if(!s->budget--) { s->failed_pc=0x0c09265au; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c09265c;
P_0c09265c: /* original f151, guest PC 0x0c09265c */
if(!s->budget--) { s->failed_pc=0x0c09265cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'-');
goto P_0c09265e;
P_0c09265e: /* original f0cc, guest PC 0x0c09265e */
if(!s->budget--) { s->failed_pc=0x0c09265eu; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c092660;
P_0c092660: /* original f041, guest PC 0x0c092660 */
if(!s->budget--) { s->failed_pc=0x0c092660u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'-');
goto P_0c092662;
P_0c092662: /* original fdac, guest PC 0x0c092662 */
if(!s->budget--) { s->failed_pc=0x0c092662u; return 0; }
vf3_matrix_move(s,13,10);
goto P_0c092664;
P_0c092664: /* original fd61, guest PC 0x0c092664 */
if(!s->budget--) { s->failed_pc=0x0c092664u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[6],r[18],'-');
goto P_0c092666;
P_0c092666: /* original e004, guest PC 0x0c092666 */
if(!s->budget--) { s->failed_pc=0x0c092666u; return 0; }
r[0]=0x00000004u;
goto P_0c092668;
P_0c092668: /* original 6463, guest PC 0x0c092668 */
if(!s->budget--) { s->failed_pc=0x0c092668u; return 0; }
r[4]=r[6];
goto P_0c09266a;
P_0c09266a: /* original fb76, guest PC 0x0c09266a */
if(!s->budget--) { s->failed_pc=0x0c09266au; return 0; }
vf3_matrix_load(s,ram,11,r[7]+r[0]);
goto P_0c09266c;
P_0c09266c: /* original e008, guest PC 0x0c09266c */
if(!s->budget--) { s->failed_pc=0x0c09266cu; return 0; }
r[0]=0x00000008u;
goto P_0c09266e;
P_0c09266e: /* original f376, guest PC 0x0c09266e */
if(!s->budget--) { s->failed_pc=0x0c09266eu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c092670;
P_0c092670: /* original 7430, guest PC 0x0c092670 */
if(!s->budget--) { s->failed_pc=0x0c092670u; return 0; }
r[4]+=0x00000030u;
goto P_0c092672;
P_0c092672: /* original fdb2, guest PC 0x0c092672 */
if(!s->budget--) { s->failed_pc=0x0c092672u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[11],r[18],'*');
goto P_0c092674;
P_0c092674: /* original f0b2, guest PC 0x0c092674 */
if(!s->budget--) { s->failed_pc=0x0c092674u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c092676;
P_0c092676: /* original ff3a, guest PC 0x0c092676 */
if(!s->budget--) { s->failed_pc=0x0c092676u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c092678;
P_0c092678: /* original f1b2, guest PC 0x0c092678 */
if(!s->budget--) { s->failed_pc=0x0c092678u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'*');
goto P_0c09267a;
P_0c09267a: /* original fb7c, guest PC 0x0c09267a */
if(!s->budget--) { s->failed_pc=0x0c09267au; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c09267c;
P_0c09267c: /* original fb30, guest PC 0x0c09267c */
if(!s->budget--) { s->failed_pc=0x0c09267cu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'+');
goto P_0c09267e;
P_0c09267e: /* original f2bc, guest PC 0x0c09267e */
if(!s->budget--) { s->failed_pc=0x0c09267eu; return 0; }
vf3_matrix_move(s,2,11);
goto P_0c092680;
P_0c092680: /* original f2b2, guest PC 0x0c092680 */
if(!s->budget--) { s->failed_pc=0x0c092680u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[11],r[18],'*');
goto P_0c092682;
P_0c092682: /* original f42a, guest PC 0x0c092682 */
if(!s->budget--) { s->failed_pc=0x0c092682u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092684;
P_0c092684: /* original f3f8, guest PC 0x0c092684 */
if(!s->budget--) { s->failed_pc=0x0c092684u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c092686;
P_0c092686: /* original f23c, guest PC 0x0c092686 */
if(!s->budget--) { s->failed_pc=0x0c092686u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c092688;
P_0c092688: /* original f232, guest PC 0x0c092688 */
if(!s->budget--) { s->failed_pc=0x0c092688u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c09268a;
P_0c09268a: /* original f42b, guest PC 0x0c09268a */
if(!s->budget--) { s->failed_pc=0x0c09268au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09268c;
P_0c09268c: /* original f48b, guest PC 0x0c09268c */
if(!s->budget--) { s->failed_pc=0x0c09268cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c09268e;
P_0c09268e: /* original f47b, guest PC 0x0c09268e */
if(!s->budget--) { s->failed_pc=0x0c09268eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c092690;
P_0c092690: /* original f40b, guest PC 0x0c092690 */
if(!s->budget--) { s->failed_pc=0x0c092690u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092692;
P_0c092692: /* original f41b, guest PC 0x0c092692 */
if(!s->budget--) { s->failed_pc=0x0c092692u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092694;
P_0c092694: /* original f4db, guest PC 0x0c092694 */
if(!s->budget--) { s->failed_pc=0x0c092694u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[4]);
goto P_0c092696;
P_0c092696: /* original f4cb, guest PC 0x0c092696 */
if(!s->budget--) { s->failed_pc=0x0c092696u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[4]);
goto P_0c092698;
P_0c092698: /* original f49b, guest PC 0x0c092698 */
if(!s->budget--) { s->failed_pc=0x0c092698u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c09269a;
P_0c09269a: /* original f4ab, guest PC 0x0c09269a */
if(!s->budget--) { s->failed_pc=0x0c09269au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c09269c;
P_0c09269c: /* original 7eff, guest PC 0x0c09269c */
if(!s->budget--) { s->failed_pc=0x0c09269cu; return 0; }
r[14]+=0xffffffffu;
goto P_0c09269e;
P_0c09269e: /* original f44b, guest PC 0x0c09269e */
if(!s->budget--) { s->failed_pc=0x0c09269eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c0926a0;
P_0c0926a0: /* original e300, guest PC 0x0c0926a0 */
if(!s->budget--) { s->failed_pc=0x0c0926a0u; return 0; }
r[3]=0x00000000u;
goto P_0c0926a2;
P_0c0926a2: /* original f45b, guest PC 0x0c0926a2 */
if(!s->budget--) { s->failed_pc=0x0c0926a2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c0926a4;
P_0c0926a4: /* original 3e36, guest PC 0x0c0926a4 */
if(!s->budget--) { s->failed_pc=0x0c0926a4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[3])!=0);
goto P_0c0926a6;
P_0c0926a6: /* original f46b, guest PC 0x0c0926a6 */
if(!s->budget--) { s->failed_pc=0x0c0926a6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c0926a8;
P_0c0926a8: /* original 8db7, guest PC 0x0c0926a8 */
if(!s->budget--) { s->failed_pc=0x0c0926a8u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000040u;
if(cond) { goto P_0c09261a; }
goto P_0c0926ac;
P_0c0926aa: /* original 7640, guest PC 0x0c0926aa */
if(!s->budget--) { s->failed_pc=0x0c0926aau; return 0; }
r[6]+=0x00000040u;
goto P_0c0926ac;
P_0c0926ac: /* original 7f04, guest PC 0x0c0926ac */
if(!s->budget--) { s->failed_pc=0x0c0926acu; return 0; }
r[15]+=0x00000004u;
goto P_0c0926ae;
P_0c0926ae: /* original fcf9, guest PC 0x0c0926ae */
if(!s->budget--) { s->failed_pc=0x0c0926aeu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0926b0;
P_0c0926b0: /* original fdf9, guest PC 0x0c0926b0 */
if(!s->budget--) { s->failed_pc=0x0c0926b0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0926b2;
P_0c0926b2: /* original 6cf6, guest PC 0x0c0926b2 */
if(!s->budget--) { s->failed_pc=0x0c0926b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0926b4;
P_0c0926b4: /* original 6df6, guest PC 0x0c0926b4 */
if(!s->budget--) { s->failed_pc=0x0c0926b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0926b6;
P_0c0926b6: /* original 000b, guest PC 0x0c0926b6 */
if(!s->budget--) { s->failed_pc=0x0c0926b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0926b8: /* original 6ef6, guest PC 0x0c0926b8 */
if(!s->budget--) { s->failed_pc=0x0c0926b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0926ba;
P_0c0926ba: /* original 2fe6, guest PC 0x0c0926ba */
if(!s->budget--) { s->failed_pc=0x0c0926bau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0926bc;
P_0c0926bc: /* original 6e43, guest PC 0x0c0926bc */
if(!s->budget--) { s->failed_pc=0x0c0926bcu; return 0; }
r[14]=r[4];
goto P_0c0926be;
P_0c0926be: /* original 2fd6, guest PC 0x0c0926be */
if(!s->budget--) { s->failed_pc=0x0c0926beu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0926c0;
P_0c0926c0: /* original 2fc6, guest PC 0x0c0926c0 */
if(!s->budget--) { s->failed_pc=0x0c0926c0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0926c2;
P_0c0926c2: /* original 2fb6, guest PC 0x0c0926c2 */
if(!s->budget--) { s->failed_pc=0x0c0926c2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0926c4;
P_0c0926c4: /* original 2fa6, guest PC 0x0c0926c4 */
if(!s->budget--) { s->failed_pc=0x0c0926c4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0926c6;
P_0c0926c6: /* original 2f96, guest PC 0x0c0926c6 */
if(!s->budget--) { s->failed_pc=0x0c0926c6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0926c8;
P_0c0926c8: /* original 2f86, guest PC 0x0c0926c8 */
if(!s->budget--) { s->failed_pc=0x0c0926c8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0926ca;
P_0c0926ca: /* original d40f, guest PC 0x0c0926ca */
if(!s->budget--) { s->failed_pc=0x0c0926cau; return 0; }
r[4]=read(ram,0x0c092708u,4);
goto P_0c0926cc;
P_0c0926cc: /* original 4f22, guest PC 0x0c0926cc */
if(!s->budget--) { s->failed_pc=0x0c0926ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0926ce;
P_0c0926ce: /* original 6242, guest PC 0x0c0926ce */
if(!s->budget--) { s->failed_pc=0x0c0926ceu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0926d0;
P_0c0926d0: /* original d30e, guest PC 0x0c0926d0 */
if(!s->budget--) { s->failed_pc=0x0c0926d0u; return 0; }
r[3]=read(ram,0x0c09270cu,4);
goto P_0c0926d2;
P_0c0926d2: /* original 7ff4, guest PC 0x0c0926d2 */
if(!s->budget--) { s->failed_pc=0x0c0926d2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0926d4;
P_0c0926d4: /* original 2238, guest PC 0x0c0926d4 */
if(!s->budget--) { s->failed_pc=0x0c0926d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0926d6;
P_0c0926d6: /* original 8903, guest PC 0x0c0926d6 */
if(!s->budget--) { s->failed_pc=0x0c0926d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0926e0; }
goto P_0c0926d8;
P_0c0926d8: /* original 5141, guest PC 0x0c0926d8 */
if(!s->budget--) { s->failed_pc=0x0c0926d8u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c0926da;
P_0c0926da: /* original d20d, guest PC 0x0c0926da */
if(!s->budget--) { s->failed_pc=0x0c0926dau; return 0; }
r[2]=read(ram,0x0c092710u,4);
goto P_0c0926dc;
P_0c0926dc: /* original 2128, guest PC 0x0c0926dc */
if(!s->budget--) { s->failed_pc=0x0c0926dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0926de;
P_0c0926de: /* original 8b78, guest PC 0x0c0926de */
if(!s->budget--) { s->failed_pc=0x0c0926deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0927d2; }
goto P_0c0926e0;
P_0c0926e0: /* original d20d, guest PC 0x0c0926e0 */
if(!s->budget--) { s->failed_pc=0x0c0926e0u; return 0; }
r[2]=read(ram,0x0c092718u,4);
goto P_0c0926e2;
P_0c0926e2: /* original d30c, guest PC 0x0c0926e2 */
if(!s->budget--) { s->failed_pc=0x0c0926e2u; return 0; }
r[3]=read(ram,0x0c092714u,4);
goto P_0c0926e4;
P_0c0926e4: /* original 6022, guest PC 0x0c0926e4 */
if(!s->budget--) { s->failed_pc=0x0c0926e4u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0926e6;
P_0c0926e6: /* original 2038, guest PC 0x0c0926e6 */
if(!s->budget--) { s->failed_pc=0x0c0926e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c0926e8;
P_0c0926e8: /* original 8b73, guest PC 0x0c0926e8 */
if(!s->budget--) { s->failed_pc=0x0c0926e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0927d2; }
goto P_0c0926ea;
P_0c0926ea: /* original d10c, guest PC 0x0c0926ea */
if(!s->budget--) { s->failed_pc=0x0c0926eau; return 0; }
r[1]=read(ram,0x0c09271cu,4);
goto P_0c0926ec;
P_0c0926ec: /* original 6be3, guest PC 0x0c0926ec */
if(!s->budget--) { s->failed_pc=0x0c0926ecu; return 0; }
r[11]=r[14];
goto P_0c0926ee;
P_0c0926ee: /* original e302, guest PC 0x0c0926ee */
if(!s->budget--) { s->failed_pc=0x0c0926eeu; return 0; }
r[3]=0x00000002u;
goto P_0c0926f0;
P_0c0926f0: /* original 7b2c, guest PC 0x0c0926f0 */
if(!s->budget--) { s->failed_pc=0x0c0926f0u; return 0; }
r[11]+=0x0000002cu;
goto P_0c0926f2;
P_0c0926f2: /* original 1f11, guest PC 0x0c0926f2 */
if(!s->budget--) { s->failed_pc=0x0c0926f2u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0926f4;
P_0c0926f4: /* original a06a, guest PC 0x0c0926f4 */
if(!s->budget--) { s->failed_pc=0x0c0926f4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0927cc;
P_0c0926f6: /* original 2f32, guest PC 0x0c0926f6 */
if(!s->budget--) { s->failed_pc=0x0c0926f6u; return 0; }
write(ram,r[15],r[3],4);
if(!vf3_matrix_family(0x0c0926f8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0926f8u; return 0; } return 1;
P_0c092720: /* original 5df1, guest PC 0x0c092720 */
if(!s->budget--) { s->failed_pc=0x0c092720u; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c092722;
P_0c092722: /* original 7d04, guest PC 0x0c092722 */
if(!s->budget--) { s->failed_pc=0x0c092722u; return 0; }
r[13]+=0x00000004u;
goto P_0c092724;
P_0c092724: /* original 1fd1, guest PC 0x0c092724 */
if(!s->budget--) { s->failed_pc=0x0c092724u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c092726;
P_0c092726: /* original 7dfc, guest PC 0x0c092726 */
if(!s->budget--) { s->failed_pc=0x0c092726u; return 0; }
r[13]+=0xfffffffcu;
goto P_0c092728;
P_0c092728: /* original 6dd2, guest PC 0x0c092728 */
if(!s->budget--) { s->failed_pc=0x0c092728u; return 0; }
tmp=read(ram,r[13],4);
r[13]=tmp;
goto P_0c09272a;
P_0c09272a: /* original d350, guest PC 0x0c09272a */
if(!s->budget--) { s->failed_pc=0x0c09272au; return 0; }
r[3]=read(ram,0x0c09286cu,4);
goto P_0c09272c;
P_0c09272c: /* original 65d3, guest PC 0x0c09272c */
if(!s->budget--) { s->failed_pc=0x0c09272cu; return 0; }
r[5]=r[13];
goto P_0c09272e;
P_0c09272e: /* original 430b, guest PC 0x0c09272e */
if(!s->budget--) { s->failed_pc=0x0c09272eu; return 0; }
target=r[3];
r[16]=code_base|0x0c092732u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092732u) { target=s->pc; goto dispatch; }
goto P_0c092732;
P_0c092730: /* original 64e3, guest PC 0x0c092730 */
if(!s->budget--) { s->failed_pc=0x0c092730u; return 0; }
r[4]=r[14];
goto P_0c092732;
P_0c092732: /* original d24f, guest PC 0x0c092732 */
if(!s->budget--) { s->failed_pc=0x0c092732u; return 0; }
r[2]=read(ram,0x0c092870u,4);
goto P_0c092734;
P_0c092734: /* original 65d3, guest PC 0x0c092734 */
if(!s->budget--) { s->failed_pc=0x0c092734u; return 0; }
r[5]=r[13];
goto P_0c092736;
P_0c092736: /* original 420b, guest PC 0x0c092736 */
if(!s->budget--) { s->failed_pc=0x0c092736u; return 0; }
target=r[2];
r[16]=code_base|0x0c09273au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09273au) { target=s->pc; goto dispatch; }
goto P_0c09273a;
P_0c092738: /* original 64e3, guest PC 0x0c092738 */
if(!s->budget--) { s->failed_pc=0x0c092738u; return 0; }
r[4]=r[14];
goto P_0c09273a;
P_0c09273a: /* original 84d4, guest PC 0x0c09273a */
if(!s->budget--) { s->failed_pc=0x0c09273au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c09273c;
P_0c09273c: /* original 9292, guest PC 0x0c09273c */
if(!s->budget--) { s->failed_pc=0x0c09273cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092864u,2);
goto P_0c09273e;
P_0c09273e: /* original 6403, guest PC 0x0c09273e */
if(!s->budget--) { s->failed_pc=0x0c09273eu; return 0; }
r[4]=r[0];
goto P_0c092740;
P_0c092740: /* original 6a4c, guest PC 0x0c092740 */
if(!s->budget--) { s->failed_pc=0x0c092740u; return 0; }
r[10]=r[4]&255u;
goto P_0c092742;
P_0c092742: /* original 63a3, guest PC 0x0c092742 */
if(!s->budget--) { s->failed_pc=0x0c092742u; return 0; }
r[3]=r[10];
goto P_0c092744;
P_0c092744: /* original 4a00, guest PC 0x0c092744 */
if(!s->budget--) { s->failed_pc=0x0c092744u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c092746;
P_0c092746: /* original 3a3c, guest PC 0x0c092746 */
if(!s->budget--) { s->failed_pc=0x0c092746u; return 0; }
r[10]+=r[3];
goto P_0c092748;
P_0c092748: /* original 938d, guest PC 0x0c092748 */
if(!s->budget--) { s->failed_pc=0x0c092748u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092866u,2);
goto P_0c09274a;
P_0c09274a: /* original 684c, guest PC 0x0c09274a */
if(!s->budget--) { s->failed_pc=0x0c09274au; return 0; }
r[8]=r[4]&255u;
goto P_0c09274c;
P_0c09274c: /* original 6c03, guest PC 0x0c09274c */
if(!s->budget--) { s->failed_pc=0x0c09274cu; return 0; }
r[12]=r[0];
goto P_0c09274e;
P_0c09274e: /* original 4818, guest PC 0x0c09274e */
if(!s->budget--) { s->failed_pc=0x0c09274eu; return 0; }
r[8]<<=8;
goto P_0c092750;
P_0c092750: /* original 4a08, guest PC 0x0c092750 */
if(!s->budget--) { s->failed_pc=0x0c092750u; return 0; }
r[10]<<=2;
goto P_0c092752;
P_0c092752: /* original 33ec, guest PC 0x0c092752 */
if(!s->budget--) { s->failed_pc=0x0c092752u; return 0; }
r[3]+=r[14];
goto P_0c092754;
P_0c092754: /* original 4a08, guest PC 0x0c092754 */
if(!s->budget--) { s->failed_pc=0x0c092754u; return 0; }
r[10]<<=2;
goto P_0c092756;
P_0c092756: /* original 694c, guest PC 0x0c092756 */
if(!s->budget--) { s->failed_pc=0x0c092756u; return 0; }
r[9]=r[4]&255u;
goto P_0c092758;
P_0c092758: /* original 4a08, guest PC 0x0c092758 */
if(!s->budget--) { s->failed_pc=0x0c092758u; return 0; }
r[10]<<=2;
goto P_0c09275a;
P_0c09275a: /* original 4a00, guest PC 0x0c09275a */
if(!s->budget--) { s->failed_pc=0x0c09275au; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c09275c;
P_0c09275c: /* original 4800, guest PC 0x0c09275c */
if(!s->budget--) { s->failed_pc=0x0c09275cu; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c09275e;
P_0c09275e: /* original 383c, guest PC 0x0c09275e */
if(!s->budget--) { s->failed_pc=0x0c09275eu; return 0; }
r[8]+=r[3];
goto P_0c092760;
P_0c092760: /* original 6393, guest PC 0x0c092760 */
if(!s->budget--) { s->failed_pc=0x0c092760u; return 0; }
r[3]=r[9];
goto P_0c092762;
P_0c092762: /* original 4900, guest PC 0x0c092762 */
if(!s->budget--) { s->failed_pc=0x0c092762u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c092764;
P_0c092764: /* original 393c, guest PC 0x0c092764 */
if(!s->budget--) { s->failed_pc=0x0c092764u; return 0; }
r[9]+=r[3];
goto P_0c092766;
P_0c092766: /* original 32ec, guest PC 0x0c092766 */
if(!s->budget--) { s->failed_pc=0x0c092766u; return 0; }
r[2]+=r[14];
goto P_0c092768;
P_0c092768: /* original 6aaf, guest PC 0x0c092768 */
if(!s->budget--) { s->failed_pc=0x0c092768u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c09276a;
P_0c09276a: /* original 4918, guest PC 0x0c09276a */
if(!s->budget--) { s->failed_pc=0x0c09276au; return 0; }
r[9]<<=8;
goto P_0c09276c;
P_0c09276c: /* original 3a2c, guest PC 0x0c09276c */
if(!s->budget--) { s->failed_pc=0x0c09276cu; return 0; }
r[10]+=r[2];
goto P_0c09276e;
P_0c09276e: /* original 927b, guest PC 0x0c09276e */
if(!s->budget--) { s->failed_pc=0x0c09276eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092868u,2);
goto P_0c092770;
P_0c092770: /* original 4908, guest PC 0x0c092770 */
if(!s->budget--) { s->failed_pc=0x0c092770u; return 0; }
r[9]<<=2;
goto P_0c092772;
P_0c092772: /* original 4908, guest PC 0x0c092772 */
if(!s->budget--) { s->failed_pc=0x0c092772u; return 0; }
r[9]<<=2;
goto P_0c092774;
P_0c092774: /* original 32ec, guest PC 0x0c092774 */
if(!s->budget--) { s->failed_pc=0x0c092774u; return 0; }
r[2]+=r[14];
goto P_0c092776;
P_0c092776: /* original 699f, guest PC 0x0c092776 */
if(!s->budget--) { s->failed_pc=0x0c092776u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c092778;
P_0c092778: /* original 392c, guest PC 0x0c092778 */
if(!s->budget--) { s->failed_pc=0x0c092778u; return 0; }
r[9]+=r[2];
goto P_0c09277a;
P_0c09277a: /* original 4c08, guest PC 0x0c09277a */
if(!s->budget--) { s->failed_pc=0x0c09277au; return 0; }
r[12]<<=2;
goto P_0c09277c;
P_0c09277c: /* original 6303, guest PC 0x0c09277c */
if(!s->budget--) { s->failed_pc=0x0c09277cu; return 0; }
r[3]=r[0];
goto P_0c09277e;
P_0c09277e: /* original 9274, guest PC 0x0c09277e */
if(!s->budget--) { s->failed_pc=0x0c09277eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09286au,2);
goto P_0c092780;
P_0c092780: /* original 3c3c, guest PC 0x0c092780 */
if(!s->budget--) { s->failed_pc=0x0c092780u; return 0; }
r[12]+=r[3];
goto P_0c092782;
P_0c092782: /* original 4c08, guest PC 0x0c092782 */
if(!s->budget--) { s->failed_pc=0x0c092782u; return 0; }
r[12]<<=2;
goto P_0c092784;
P_0c092784: /* original d33b, guest PC 0x0c092784 */
if(!s->budget--) { s->failed_pc=0x0c092784u; return 0; }
r[3]=read(ram,0x0c092874u,4);
goto P_0c092786;
P_0c092786: /* original 32ec, guest PC 0x0c092786 */
if(!s->budget--) { s->failed_pc=0x0c092786u; return 0; }
r[2]+=r[14];
goto P_0c092788;
P_0c092788: /* original 6cce, guest PC 0x0c092788 */
if(!s->budget--) { s->failed_pc=0x0c092788u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c09278a;
P_0c09278a: /* original 3c2c, guest PC 0x0c09278a */
if(!s->budget--) { s->failed_pc=0x0c09278au; return 0; }
r[12]+=r[2];
goto P_0c09278c;
P_0c09278c: /* original 65c3, guest PC 0x0c09278c */
if(!s->budget--) { s->failed_pc=0x0c09278cu; return 0; }
r[5]=r[12];
goto P_0c09278e;
P_0c09278e: /* original 430b, guest PC 0x0c09278e */
if(!s->budget--) { s->failed_pc=0x0c09278eu; return 0; }
target=r[3];
r[16]=code_base|0x0c092792u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092792u) { target=s->pc; goto dispatch; }
goto P_0c092792;
P_0c092790: /* original 64d3, guest PC 0x0c092790 */
if(!s->budget--) { s->failed_pc=0x0c092790u; return 0; }
r[4]=r[13];
goto P_0c092792;
P_0c092792: /* original 1f02, guest PC 0x0c092792 */
if(!s->budget--) { s->failed_pc=0x0c092792u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c092794;
P_0c092794: /* original 63b1, guest PC 0x0c092794 */
if(!s->budget--) { s->failed_pc=0x0c092794u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[3]=tmp;
goto P_0c092796;
P_0c092796: /* original 2338, guest PC 0x0c092796 */
if(!s->budget--) { s->failed_pc=0x0c092796u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c092798;
P_0c092798: /* original 890a, guest PC 0x0c092798 */
if(!s->budget--) { s->failed_pc=0x0c092798u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0927b0; }
goto P_0c09279a;
P_0c09279a: /* original e100, guest PC 0x0c09279a */
if(!s->budget--) { s->failed_pc=0x0c09279au; return 0; }
r[1]=0x00000000u;
goto P_0c09279c;
P_0c09279c: /* original 6693, guest PC 0x0c09279c */
if(!s->budget--) { s->failed_pc=0x0c09279cu; return 0; }
r[6]=r[9];
goto P_0c09279e;
P_0c09279e: /* original 65d3, guest PC 0x0c09279e */
if(!s->budget--) { s->failed_pc=0x0c09279eu; return 0; }
r[5]=r[13];
goto P_0c0927a0;
P_0c0927a0: /* original 2b11, guest PC 0x0c0927a0 */
if(!s->budget--) { s->failed_pc=0x0c0927a0u; return 0; }
write(ram,r[11],r[1],2);
goto P_0c0927a2;
P_0c0927a2: /* original 2fc6, guest PC 0x0c0927a2 */
if(!s->budget--) { s->failed_pc=0x0c0927a2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927a4;
P_0c0927a4: /* original 67a3, guest PC 0x0c0927a4 */
if(!s->budget--) { s->failed_pc=0x0c0927a4u; return 0; }
r[7]=r[10];
goto P_0c0927a6;
P_0c0927a6: /* original 2f86, guest PC 0x0c0927a6 */
if(!s->budget--) { s->failed_pc=0x0c0927a6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927a8;
P_0c0927a8: /* original d333, guest PC 0x0c0927a8 */
if(!s->budget--) { s->failed_pc=0x0c0927a8u; return 0; }
r[3]=read(ram,0x0c092878u,4);
goto P_0c0927aa;
P_0c0927aa: /* original 430b, guest PC 0x0c0927aa */
if(!s->budget--) { s->failed_pc=0x0c0927aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0927aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0927aeu) { target=s->pc; goto dispatch; }
goto P_0c0927ae;
P_0c0927ac: /* original 64e3, guest PC 0x0c0927ac */
if(!s->budget--) { s->failed_pc=0x0c0927acu; return 0; }
r[4]=r[14];
goto P_0c0927ae;
P_0c0927ae: /* original 7f08, guest PC 0x0c0927ae */
if(!s->budget--) { s->failed_pc=0x0c0927aeu; return 0; }
r[15]+=0x00000008u;
goto P_0c0927b0;
P_0c0927b0: /* original 52f2, guest PC 0x0c0927b0 */
if(!s->budget--) { s->failed_pc=0x0c0927b0u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0927b2;
P_0c0927b2: /* original 6693, guest PC 0x0c0927b2 */
if(!s->budget--) { s->failed_pc=0x0c0927b2u; return 0; }
r[6]=r[9];
goto P_0c0927b4;
P_0c0927b4: /* original 65d3, guest PC 0x0c0927b4 */
if(!s->budget--) { s->failed_pc=0x0c0927b4u; return 0; }
r[5]=r[13];
goto P_0c0927b6;
P_0c0927b6: /* original 67a3, guest PC 0x0c0927b6 */
if(!s->budget--) { s->failed_pc=0x0c0927b6u; return 0; }
r[7]=r[10];
goto P_0c0927b8;
P_0c0927b8: /* original 2f26, guest PC 0x0c0927b8 */
if(!s->budget--) { s->failed_pc=0x0c0927b8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927ba;
P_0c0927ba: /* original 7b02, guest PC 0x0c0927ba */
if(!s->budget--) { s->failed_pc=0x0c0927bau; return 0; }
r[11]+=0x00000002u;
goto P_0c0927bc;
P_0c0927bc: /* original 2fc6, guest PC 0x0c0927bc */
if(!s->budget--) { s->failed_pc=0x0c0927bcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927be;
P_0c0927be: /* original 2f86, guest PC 0x0c0927be */
if(!s->budget--) { s->failed_pc=0x0c0927beu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927c0;
P_0c0927c0: /* original b011, guest PC 0x0c0927c0 */
if(!s->budget--) { s->failed_pc=0x0c0927c0u; return 0; }
target=code_base|0x0c0927e6u; r[16]=code_base|0x0c0927c4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0927c4u) { target=s->pc; goto dispatch; }
goto P_0c0927c4;
P_0c0927c2: /* original 64e3, guest PC 0x0c0927c2 */
if(!s->budget--) { s->failed_pc=0x0c0927c2u; return 0; }
r[4]=r[14];
goto P_0c0927c4;
P_0c0927c4: /* original 7f0c, guest PC 0x0c0927c4 */
if(!s->budget--) { s->failed_pc=0x0c0927c4u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0927c6;
P_0c0927c6: /* original 62f2, guest PC 0x0c0927c6 */
if(!s->budget--) { s->failed_pc=0x0c0927c6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0927c8;
P_0c0927c8: /* original 72ff, guest PC 0x0c0927c8 */
if(!s->budget--) { s->failed_pc=0x0c0927c8u; return 0; }
r[2]+=0xffffffffu;
goto P_0c0927ca;
P_0c0927ca: /* original 2f22, guest PC 0x0c0927ca */
if(!s->budget--) { s->failed_pc=0x0c0927cau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0927cc;
P_0c0927cc: /* original 63f2, guest PC 0x0c0927cc */
if(!s->budget--) { s->failed_pc=0x0c0927ccu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0927ce;
P_0c0927ce: /* original 2338, guest PC 0x0c0927ce */
if(!s->budget--) { s->failed_pc=0x0c0927ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0927d0;
P_0c0927d0: /* original 8ba6, guest PC 0x0c0927d0 */
if(!s->budget--) { s->failed_pc=0x0c0927d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092720; }
goto P_0c0927d2;
P_0c0927d2: /* original 7f0c, guest PC 0x0c0927d2 */
if(!s->budget--) { s->failed_pc=0x0c0927d2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0927d4;
P_0c0927d4: /* original 4f26, guest PC 0x0c0927d4 */
if(!s->budget--) { s->failed_pc=0x0c0927d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0927d6;
P_0c0927d6: /* original 68f6, guest PC 0x0c0927d6 */
if(!s->budget--) { s->failed_pc=0x0c0927d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0927d8;
P_0c0927d8: /* original 69f6, guest PC 0x0c0927d8 */
if(!s->budget--) { s->failed_pc=0x0c0927d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0927da;
P_0c0927da: /* original 6af6, guest PC 0x0c0927da */
if(!s->budget--) { s->failed_pc=0x0c0927dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0927dc;
P_0c0927dc: /* original 6bf6, guest PC 0x0c0927dc */
if(!s->budget--) { s->failed_pc=0x0c0927dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0927de;
P_0c0927de: /* original 6cf6, guest PC 0x0c0927de */
if(!s->budget--) { s->failed_pc=0x0c0927deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0927e0;
P_0c0927e0: /* original 6df6, guest PC 0x0c0927e0 */
if(!s->budget--) { s->failed_pc=0x0c0927e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0927e2;
P_0c0927e2: /* original 000b, guest PC 0x0c0927e2 */
if(!s->budget--) { s->failed_pc=0x0c0927e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0927e4: /* original 6ef6, guest PC 0x0c0927e4 */
if(!s->budget--) { s->failed_pc=0x0c0927e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0927e6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
