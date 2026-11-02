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
int vf3_away_batch27_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0351d8u: goto P_0c0351d8;
case 0x0c0351dau: goto P_0c0351da;
case 0x0c0351dcu: goto P_0c0351dc;
case 0x0c0351deu: goto P_0c0351de;
case 0x0c0351e0u: goto P_0c0351e0;
case 0x0c0351e2u: goto P_0c0351e2;
case 0x0c0351e4u: goto P_0c0351e4;
case 0x0c0351e6u: goto P_0c0351e6;
case 0x0c0351e8u: goto P_0c0351e8;
case 0x0c0351eau: goto P_0c0351ea;
case 0x0c0351ecu: goto P_0c0351ec;
case 0x0c0351eeu: goto P_0c0351ee;
case 0x0c0351f0u: goto P_0c0351f0;
case 0x0c0351f2u: goto P_0c0351f2;
case 0x0c0351f4u: goto P_0c0351f4;
case 0x0c0351f6u: goto P_0c0351f6;
case 0x0c0351f8u: goto P_0c0351f8;
case 0x0c0351fau: goto P_0c0351fa;
case 0x0c0351fcu: goto P_0c0351fc;
case 0x0c0351feu: goto P_0c0351fe;
case 0x0c035200u: goto P_0c035200;
case 0x0c035202u: goto P_0c035202;
case 0x0c035204u: goto P_0c035204;
case 0x0c035206u: goto P_0c035206;
case 0x0c035208u: goto P_0c035208;
case 0x0c03520au: goto P_0c03520a;
case 0x0c03520cu: goto P_0c03520c;
case 0x0c03520eu: goto P_0c03520e;
case 0x0c035210u: goto P_0c035210;
case 0x0c035212u: goto P_0c035212;
case 0x0c035214u: goto P_0c035214;
case 0x0c035216u: goto P_0c035216;
case 0x0c035218u: goto P_0c035218;
case 0x0c03521au: goto P_0c03521a;
case 0x0c03521cu: goto P_0c03521c;
case 0x0c03521eu: goto P_0c03521e;
case 0x0c035220u: goto P_0c035220;
case 0x0c035222u: goto P_0c035222;
case 0x0c035224u: goto P_0c035224;
case 0x0c035226u: goto P_0c035226;
case 0x0c035228u: goto P_0c035228;
case 0x0c03522au: goto P_0c03522a;
case 0x0c03522cu: goto P_0c03522c;
case 0x0c03522eu: goto P_0c03522e;
case 0x0c035230u: goto P_0c035230;
case 0x0c035232u: goto P_0c035232;
case 0x0c035234u: goto P_0c035234;
case 0x0c035236u: goto P_0c035236;
case 0x0c03550cu: goto P_0c03550c;
case 0x0c03550eu: goto P_0c03550e;
case 0x0c035510u: goto P_0c035510;
case 0x0c035512u: goto P_0c035512;
case 0x0c035514u: goto P_0c035514;
case 0x0c035516u: goto P_0c035516;
case 0x0c035518u: goto P_0c035518;
case 0x0c03551au: goto P_0c03551a;
case 0x0c03551cu: goto P_0c03551c;
case 0x0c03551eu: goto P_0c03551e;
case 0x0c035520u: goto P_0c035520;
case 0x0c035522u: goto P_0c035522;
case 0x0c035524u: goto P_0c035524;
case 0x0c035526u: goto P_0c035526;
case 0x0c035528u: goto P_0c035528;
case 0x0c03552au: goto P_0c03552a;
case 0x0c03552cu: goto P_0c03552c;
case 0x0c03552eu: goto P_0c03552e;
case 0x0c035530u: goto P_0c035530;
case 0x0c035532u: goto P_0c035532;
case 0x0c035534u: goto P_0c035534;
case 0x0c035536u: goto P_0c035536;
case 0x0c035538u: goto P_0c035538;
case 0x0c03553au: goto P_0c03553a;
case 0x0c03553cu: goto P_0c03553c;
case 0x0c03553eu: goto P_0c03553e;
case 0x0c035540u: goto P_0c035540;
case 0x0c035542u: goto P_0c035542;
case 0x0c035544u: goto P_0c035544;
case 0x0c035546u: goto P_0c035546;
case 0x0c035548u: goto P_0c035548;
case 0x0c03554au: goto P_0c03554a;
case 0x0c03554cu: goto P_0c03554c;
case 0x0c03554eu: goto P_0c03554e;
case 0x0c035550u: goto P_0c035550;
case 0x0c035552u: goto P_0c035552;
case 0x0c035554u: goto P_0c035554;
case 0x0c035556u: goto P_0c035556;
case 0x0c035558u: goto P_0c035558;
case 0x0c03555au: goto P_0c03555a;
case 0x0c03555cu: goto P_0c03555c;
case 0x0c03555eu: goto P_0c03555e;
case 0x0c035560u: goto P_0c035560;
case 0x0c035562u: goto P_0c035562;
case 0x0c035564u: goto P_0c035564;
case 0x0c035566u: goto P_0c035566;
case 0x0c035568u: goto P_0c035568;
case 0x0c03556au: goto P_0c03556a;
case 0x0c03556cu: goto P_0c03556c;
case 0x0c03556eu: goto P_0c03556e;
case 0x0c035570u: goto P_0c035570;
case 0x0c035572u: goto P_0c035572;
case 0x0c035574u: goto P_0c035574;
case 0x0c035576u: goto P_0c035576;
case 0x0c035578u: goto P_0c035578;
case 0x0c03557au: goto P_0c03557a;
case 0x0c03557cu: goto P_0c03557c;
case 0x0c03557eu: goto P_0c03557e;
case 0x0c035580u: goto P_0c035580;
case 0x0c035582u: goto P_0c035582;
case 0x0c035584u: goto P_0c035584;
case 0x0c035586u: goto P_0c035586;
case 0x0c035588u: goto P_0c035588;
case 0x0c03558au: goto P_0c03558a;
case 0x0c03558cu: goto P_0c03558c;
case 0x0c0357bcu: goto P_0c0357bc;
case 0x0c0357beu: goto P_0c0357be;
case 0x0c0357c0u: goto P_0c0357c0;
case 0x0c0357c2u: goto P_0c0357c2;
case 0x0c0357c4u: goto P_0c0357c4;
case 0x0c0357c6u: goto P_0c0357c6;
case 0x0c0357c8u: goto P_0c0357c8;
case 0x0c0357cau: goto P_0c0357ca;
case 0x0c0357ccu: goto P_0c0357cc;
case 0x0c0357ceu: goto P_0c0357ce;
case 0x0c0357d0u: goto P_0c0357d0;
case 0x0c0357d2u: goto P_0c0357d2;
case 0x0c0357d4u: goto P_0c0357d4;
case 0x0c0357d6u: goto P_0c0357d6;
case 0x0c0357d8u: goto P_0c0357d8;
case 0x0c0357dau: goto P_0c0357da;
case 0x0c0357dcu: goto P_0c0357dc;
case 0x0c0357deu: goto P_0c0357de;
case 0x0c0357e0u: goto P_0c0357e0;
case 0x0c0357e2u: goto P_0c0357e2;
case 0x0c0357e4u: goto P_0c0357e4;
case 0x0c0357e6u: goto P_0c0357e6;
case 0x0c0357e8u: goto P_0c0357e8;
case 0x0c0357eau: goto P_0c0357ea;
case 0x0c0357ecu: goto P_0c0357ec;
case 0x0c0357eeu: goto P_0c0357ee;
case 0x0c0357f0u: goto P_0c0357f0;
case 0x0c0357f2u: goto P_0c0357f2;
case 0x0c0357f4u: goto P_0c0357f4;
case 0x0c0357f6u: goto P_0c0357f6;
case 0x0c0357f8u: goto P_0c0357f8;
case 0x0c0357fau: goto P_0c0357fa;
case 0x0c0357fcu: goto P_0c0357fc;
case 0x0c0357feu: goto P_0c0357fe;
case 0x0c035800u: goto P_0c035800;
case 0x0c035802u: goto P_0c035802;
case 0x0c035804u: goto P_0c035804;
case 0x0c035806u: goto P_0c035806;
case 0x0c035808u: goto P_0c035808;
case 0x0c03580au: goto P_0c03580a;
case 0x0c03580cu: goto P_0c03580c;
case 0x0c03580eu: goto P_0c03580e;
case 0x0c035810u: goto P_0c035810;
case 0x0c035812u: goto P_0c035812;
case 0x0c035814u: goto P_0c035814;
case 0x0c035816u: goto P_0c035816;
case 0x0c035818u: goto P_0c035818;
case 0x0c03581au: goto P_0c03581a;
case 0x0c03581cu: goto P_0c03581c;
case 0x0c03581eu: goto P_0c03581e;
case 0x0c035820u: goto P_0c035820;
case 0x0c035822u: goto P_0c035822;
case 0x0c035824u: goto P_0c035824;
case 0x0c035826u: goto P_0c035826;
case 0x0c035828u: goto P_0c035828;
case 0x0c03582au: goto P_0c03582a;
case 0x0c03582cu: goto P_0c03582c;
case 0x0c03582eu: goto P_0c03582e;
case 0x0c035830u: goto P_0c035830;
case 0x0c035832u: goto P_0c035832;
case 0x0c035834u: goto P_0c035834;
case 0x0c035836u: goto P_0c035836;
case 0x0c035838u: goto P_0c035838;
case 0x0c03583au: goto P_0c03583a;
case 0x0c03583cu: goto P_0c03583c;
case 0x0c03583eu: goto P_0c03583e;
case 0x0c035840u: goto P_0c035840;
case 0x0c035842u: goto P_0c035842;
case 0x0c035844u: goto P_0c035844;
case 0x0c035846u: goto P_0c035846;
case 0x0c035848u: goto P_0c035848;
case 0x0c03584au: goto P_0c03584a;
case 0x0c03584cu: goto P_0c03584c;
case 0x0c03584eu: goto P_0c03584e;
case 0x0c035850u: goto P_0c035850;
case 0x0c035852u: goto P_0c035852;
case 0x0c035854u: goto P_0c035854;
case 0x0c035856u: goto P_0c035856;
case 0x0c035858u: goto P_0c035858;
case 0x0c03585au: goto P_0c03585a;
case 0x0c03585cu: goto P_0c03585c;
case 0x0c03585eu: goto P_0c03585e;
case 0x0c035860u: goto P_0c035860;
case 0x0c035862u: goto P_0c035862;
case 0x0c035864u: goto P_0c035864;
case 0x0c035866u: goto P_0c035866;
case 0x0c035868u: goto P_0c035868;
case 0x0c03586au: goto P_0c03586a;
case 0x0c03586cu: goto P_0c03586c;
case 0x0c03586eu: goto P_0c03586e;
case 0x0c035870u: goto P_0c035870;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0351d8: /* original 2fe6, guest PC 0x0c0351d8 */
if(!s->budget--) { s->failed_pc=0x0c0351d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0351da;
P_0c0351da: /* original 2fd6, guest PC 0x0c0351da */
if(!s->budget--) { s->failed_pc=0x0c0351dau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0351dc;
P_0c0351dc: /* original 2fc6, guest PC 0x0c0351dc */
if(!s->budget--) { s->failed_pc=0x0c0351dcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0351de;
P_0c0351de: /* original 2fb6, guest PC 0x0c0351de */
if(!s->budget--) { s->failed_pc=0x0c0351deu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0351e0;
P_0c0351e0: /* original 6b53, guest PC 0x0c0351e0 */
if(!s->budget--) { s->failed_pc=0x0c0351e0u; return 0; }
r[11]=r[5];
goto P_0c0351e2;
P_0c0351e2: /* original 4f22, guest PC 0x0c0351e2 */
if(!s->budget--) { s->failed_pc=0x0c0351e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0351e4;
P_0c0351e4: /* original 4b18, guest PC 0x0c0351e4 */
if(!s->budget--) { s->failed_pc=0x0c0351e4u; return 0; }
r[11]<<=8;
goto P_0c0351e6;
P_0c0351e6: /* original 4b08, guest PC 0x0c0351e6 */
if(!s->budget--) { s->failed_pc=0x0c0351e6u; return 0; }
r[11]<<=2;
goto P_0c0351e8;
P_0c0351e8: /* original 7ffc, guest PC 0x0c0351e8 */
if(!s->budget--) { s->failed_pc=0x0c0351e8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0351ea;
P_0c0351ea: /* original 2f42, guest PC 0x0c0351ea */
if(!s->budget--) { s->failed_pc=0x0c0351eau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0351ec;
P_0c0351ec: /* original e400, guest PC 0x0c0351ec */
if(!s->budget--) { s->failed_pc=0x0c0351ecu; return 0; }
r[4]=0x00000000u;
goto P_0c0351ee;
P_0c0351ee: /* original d3a7, guest PC 0x0c0351ee */
if(!s->budget--) { s->failed_pc=0x0c0351eeu; return 0; }
r[3]=read(ram,0x0c03548cu,4);
goto P_0c0351f0;
P_0c0351f0: /* original 4b00, guest PC 0x0c0351f0 */
if(!s->budget--) { s->failed_pc=0x0c0351f0u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c0351f2;
P_0c0351f2: /* original dca7, guest PC 0x0c0351f2 */
if(!s->budget--) { s->failed_pc=0x0c0351f2u; return 0; }
r[12]=read(ram,0x0c035490u,4);
goto P_0c0351f4;
P_0c0351f4: /* original 6632, guest PC 0x0c0351f4 */
if(!s->budget--) { s->failed_pc=0x0c0351f4u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0351f6;
P_0c0351f6: /* original dda7, guest PC 0x0c0351f6 */
if(!s->budget--) { s->failed_pc=0x0c0351f6u; return 0; }
r[13]=read(ram,0x0c035494u,4);
goto P_0c0351f8;
P_0c0351f8: /* original 6262, guest PC 0x0c0351f8 */
if(!s->budget--) { s->failed_pc=0x0c0351f8u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0351fa;
P_0c0351fa: /* original 4215, guest PC 0x0c0351fa */
if(!s->budget--) { s->failed_pc=0x0c0351fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0351fc;
P_0c0351fc: /* original 8f12, guest PC 0x0c0351fc */
if(!s->budget--) { s->failed_pc=0x0c0351fcu; return 0; }
cond=r[17]&1u;
r[14]=read(ram,r[6]+48,4);
if(!cond) { goto P_0c035224; }
goto P_0c035200;
P_0c0351fe: /* original 5e6c, guest PC 0x0c0351fe */
if(!s->budget--) { s->failed_pc=0x0c0351feu; return 0; }
r[14]=read(ram,r[6]+48,4);
goto P_0c035200;
P_0c035200: /* original e048, guest PC 0x0c035200 */
if(!s->budget--) { s->failed_pc=0x0c035200u; return 0; }
r[0]=0x00000048u;
goto P_0c035202;
P_0c035202: /* original 03ed, guest PC 0x0c035202 */
if(!s->budget--) { s->failed_pc=0x0c035202u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035204;
P_0c035204: /* original 2338, guest PC 0x0c035204 */
if(!s->budget--) { s->failed_pc=0x0c035204u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c035206;
P_0c035206: /* original 8b08, guest PC 0x0c035206 */
if(!s->budget--) { s->failed_pc=0x0c035206u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03521a; }
goto P_0c035208;
P_0c035208: /* original 66f2, guest PC 0x0c035208 */
if(!s->budget--) { s->failed_pc=0x0c035208u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c03520a;
P_0c03520a: /* original e500, guest PC 0x0c03520a */
if(!s->budget--) { s->failed_pc=0x0c03520au; return 0; }
r[5]=0x00000000u;
goto P_0c03520c;
P_0c03520c: /* original 67b3, guest PC 0x0c03520c */
if(!s->budget--) { s->failed_pc=0x0c03520cu; return 0; }
r[7]=r[11];
goto P_0c03520e;
P_0c03520e: /* original 4c0b, guest PC 0x0c03520e */
if(!s->budget--) { s->failed_pc=0x0c03520eu; return 0; }
target=r[12];
r[16]=code_base|0x0c035212u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035212u) { target=s->pc; goto dispatch; }
goto P_0c035212;
P_0c035210: /* original 64e3, guest PC 0x0c035210 */
if(!s->budget--) { s->failed_pc=0x0c035210u; return 0; }
r[4]=r[14];
goto P_0c035212;
P_0c035212: /* original 4d0b, guest PC 0x0c035212 */
if(!s->budget--) { s->failed_pc=0x0c035212u; return 0; }
target=r[13];
r[16]=code_base|0x0c035216u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035216u) { target=s->pc; goto dispatch; }
goto P_0c035216;
P_0c035214: /* original e400, guest PC 0x0c035214 */
if(!s->budget--) { s->failed_pc=0x0c035214u; return 0; }
r[4]=0x00000000u;
goto P_0c035216;
P_0c035216: /* original a008, guest PC 0x0c035216 */
if(!s->budget--) { s->failed_pc=0x0c035216u; return 0; }
r[0]=r[14];
goto P_0c03522a;
P_0c035218: /* original 60e3, guest PC 0x0c035218 */
if(!s->budget--) { s->failed_pc=0x0c035218u; return 0; }
r[0]=r[14];
goto P_0c03521a;
P_0c03521a: /* original 6362, guest PC 0x0c03521a */
if(!s->budget--) { s->failed_pc=0x0c03521au; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c03521c;
P_0c03521c: /* original 7401, guest PC 0x0c03521c */
if(!s->budget--) { s->failed_pc=0x0c03521cu; return 0; }
r[4]+=0x00000001u;
goto P_0c03521e;
P_0c03521e: /* original 3433, guest PC 0x0c03521e */
if(!s->budget--) { s->failed_pc=0x0c03521eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c035220;
P_0c035220: /* original 8fee, guest PC 0x0c035220 */
if(!s->budget--) { s->failed_pc=0x0c035220u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000050u;
if(!cond) { goto P_0c035200; }
goto P_0c035224;
P_0c035222: /* original 7e50, guest PC 0x0c035222 */
if(!s->budget--) { s->failed_pc=0x0c035222u; return 0; }
r[14]+=0x00000050u;
goto P_0c035224;
P_0c035224: /* original 4d0b, guest PC 0x0c035224 */
if(!s->budget--) { s->failed_pc=0x0c035224u; return 0; }
target=r[13];
r[16]=code_base|0x0c035228u;
r[4]=0xfffffff7u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035228u) { target=s->pc; goto dispatch; }
goto P_0c035228;
P_0c035226: /* original e4f7, guest PC 0x0c035226 */
if(!s->budget--) { s->failed_pc=0x0c035226u; return 0; }
r[4]=0xfffffff7u;
goto P_0c035228;
P_0c035228: /* original e000, guest PC 0x0c035228 */
if(!s->budget--) { s->failed_pc=0x0c035228u; return 0; }
r[0]=0x00000000u;
goto P_0c03522a;
P_0c03522a: /* original 7f04, guest PC 0x0c03522a */
if(!s->budget--) { s->failed_pc=0x0c03522au; return 0; }
r[15]+=0x00000004u;
goto P_0c03522c;
P_0c03522c: /* original 4f26, guest PC 0x0c03522c */
if(!s->budget--) { s->failed_pc=0x0c03522cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03522e;
P_0c03522e: /* original 6bf6, guest PC 0x0c03522e */
if(!s->budget--) { s->failed_pc=0x0c03522eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035230;
P_0c035230: /* original 6cf6, guest PC 0x0c035230 */
if(!s->budget--) { s->failed_pc=0x0c035230u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035232;
P_0c035232: /* original 6df6, guest PC 0x0c035232 */
if(!s->budget--) { s->failed_pc=0x0c035232u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c035234;
P_0c035234: /* original 000b, guest PC 0x0c035234 */
if(!s->budget--) { s->failed_pc=0x0c035234u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035236: /* original 6ef6, guest PC 0x0c035236 */
if(!s->budget--) { s->failed_pc=0x0c035236u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035238u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035238u; return 0; } return 1;
P_0c03550c: /* original 2fe6, guest PC 0x0c03550c */
if(!s->budget--) { s->failed_pc=0x0c03550cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03550e;
P_0c03550e: /* original 6e43, guest PC 0x0c03550e */
if(!s->budget--) { s->failed_pc=0x0c03550eu; return 0; }
r[14]=r[4];
goto P_0c035510;
P_0c035510: /* original 2fd6, guest PC 0x0c035510 */
if(!s->budget--) { s->failed_pc=0x0c035510u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035512;
P_0c035512: /* original 2fc6, guest PC 0x0c035512 */
if(!s->budget--) { s->failed_pc=0x0c035512u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035514;
P_0c035514: /* original 2fb6, guest PC 0x0c035514 */
if(!s->budget--) { s->failed_pc=0x0c035514u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035516;
P_0c035516: /* original 2fa6, guest PC 0x0c035516 */
if(!s->budget--) { s->failed_pc=0x0c035516u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035518;
P_0c035518: /* original 4f22, guest PC 0x0c035518 */
if(!s->budget--) { s->failed_pc=0x0c035518u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03551a;
P_0c03551a: /* original d333, guest PC 0x0c03551a */
if(!s->budget--) { s->failed_pc=0x0c03551au; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c03551c;
P_0c03551c: /* original 6d32, guest PC 0x0c03551c */
if(!s->budget--) { s->failed_pc=0x0c03551cu; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c03551e;
P_0c03551e: /* original 9c61, guest PC 0x0c03551e */
if(!s->budget--) { s->failed_pc=0x0c03551eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0355e4u,2);
goto P_0c035520;
P_0c035520: /* original da32, guest PC 0x0c035520 */
if(!s->budget--) { s->failed_pc=0x0c035520u; return 0; }
r[10]=read(ram,0x0c0355ecu,4);
goto P_0c035522;
P_0c035522: /* original 5be6, guest PC 0x0c035522 */
if(!s->budget--) { s->failed_pc=0x0c035522u; return 0; }
r[11]=read(ram,r[14]+24,4);
goto P_0c035524;
P_0c035524: /* original 60e2, guest PC 0x0c035524 */
if(!s->budget--) { s->failed_pc=0x0c035524u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c035526;
P_0c035526: /* original 5009, guest PC 0x0c035526 */
if(!s->budget--) { s->failed_pc=0x0c035526u; return 0; }
r[0]=read(ram,r[0]+36,4);
goto P_0c035528;
P_0c035528: /* original 8802, guest PC 0x0c035528 */
if(!s->budget--) { s->failed_pc=0x0c035528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03552a;
P_0c03552a: /* original 8901, guest PC 0x0c03552a */
if(!s->budget--) { s->failed_pc=0x0c03552au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035530; }
goto P_0c03552c;
P_0c03552c: /* original 4a0b, guest PC 0x0c03552c */
if(!s->budget--) { s->failed_pc=0x0c03552cu; return 0; }
target=r[10];
r[16]=code_base|0x0c035530u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035530u) { target=s->pc; goto dispatch; }
goto P_0c035530;
P_0c03552e: /* original 0009, guest PC 0x0c03552e */
if(!s->budget--) { s->failed_pc=0x0c03552eu; return 0; }
goto P_0c035530;
P_0c035530: /* original b276, guest PC 0x0c035530 */
if(!s->budget--) { s->failed_pc=0x0c035530u; return 0; }
target=code_base|0x0c035a20u; r[16]=code_base|0x0c035534u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035534u) { target=s->pc; goto dispatch; }
goto P_0c035534;
P_0c035532: /* original 64e3, guest PC 0x0c035532 */
if(!s->budget--) { s->failed_pc=0x0c035532u; return 0; }
r[4]=r[14];
goto P_0c035534;
P_0c035534: /* original 8800, guest PC 0x0c035534 */
if(!s->budget--) { s->failed_pc=0x0c035534u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c035536;
P_0c035536: /* original 8d0e, guest PC 0x0c035536 */
if(!s->budget--) { s->failed_pc=0x0c035536u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c035556; }
goto P_0c03553a;
P_0c035538: /* original 6403, guest PC 0x0c035538 */
if(!s->budget--) { s->failed_pc=0x0c035538u; return 0; }
r[4]=r[0];
goto P_0c03553a;
P_0c03553a: /* original 8801, guest PC 0x0c03553a */
if(!s->budget--) { s->failed_pc=0x0c03553au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c03553c;
P_0c03553c: /* original 890d, guest PC 0x0c03553c */
if(!s->budget--) { s->failed_pc=0x0c03553cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555a; }
goto P_0c03553e;
P_0c03553e: /* original 8802, guest PC 0x0c03553e */
if(!s->budget--) { s->failed_pc=0x0c03553eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c035540;
P_0c035540: /* original 890d, guest PC 0x0c035540 */
if(!s->budget--) { s->failed_pc=0x0c035540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035542;
P_0c035542: /* original 8803, guest PC 0x0c035542 */
if(!s->budget--) { s->failed_pc=0x0c035542u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c035544;
P_0c035544: /* original 890b, guest PC 0x0c035544 */
if(!s->budget--) { s->failed_pc=0x0c035544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035546;
P_0c035546: /* original 8804, guest PC 0x0c035546 */
if(!s->budget--) { s->failed_pc=0x0c035546u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c035548;
P_0c035548: /* original 8909, guest PC 0x0c035548 */
if(!s->budget--) { s->failed_pc=0x0c035548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c03554a;
P_0c03554a: /* original 8805, guest PC 0x0c03554a */
if(!s->budget--) { s->failed_pc=0x0c03554au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03554c;
P_0c03554c: /* original 890d, guest PC 0x0c03554c */
if(!s->budget--) { s->failed_pc=0x0c03554cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c03554e;
P_0c03554e: /* original 8806, guest PC 0x0c03554e */
if(!s->budget--) { s->failed_pc=0x0c03554eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c035550;
P_0c035550: /* original 890b, guest PC 0x0c035550 */
if(!s->budget--) { s->failed_pc=0x0c035550u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c035552;
P_0c035552: /* original a00d, guest PC 0x0c035552 */
if(!s->budget--) { s->failed_pc=0x0c035552u; return 0; }
goto P_0c035570;
P_0c035554: /* original 0009, guest PC 0x0c035554 */
if(!s->budget--) { s->failed_pc=0x0c035554u; return 0; }
goto P_0c035556;
P_0c035556: /* original a013, guest PC 0x0c035556 */
if(!s->budget--) { s->failed_pc=0x0c035556u; return 0; }
r[0]=0xffffffe0u;
goto P_0c035580;
P_0c035558: /* original e0e0, guest PC 0x0c035558 */
if(!s->budget--) { s->failed_pc=0x0c035558u; return 0; }
r[0]=0xffffffe0u;
goto P_0c03555a;
P_0c03555a: /* original a011, guest PC 0x0c03555a */
if(!s->budget--) { s->failed_pc=0x0c03555au; return 0; }
r[0]=0x00000000u;
goto P_0c035580;
P_0c03555c: /* original e000, guest PC 0x0c03555c */
if(!s->budget--) { s->failed_pc=0x0c03555cu; return 0; }
r[0]=0x00000000u;
goto P_0c03555e;
P_0c03555e: /* original 53e6, guest PC 0x0c03555e */
if(!s->budget--) { s->failed_pc=0x0c03555eu; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c035560;
P_0c035560: /* original 3b30, guest PC 0x0c035560 */
if(!s->budget--) { s->failed_pc=0x0c035560u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c035562;
P_0c035562: /* original 8907, guest PC 0x0c035562 */
if(!s->budget--) { s->failed_pc=0x0c035562u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035574; }
goto P_0c035564;
P_0c035564: /* original d120, guest PC 0x0c035564 */
if(!s->budget--) { s->failed_pc=0x0c035564u; return 0; }
r[1]=read(ram,0x0c0355e8u,4);
goto P_0c035566;
P_0c035566: /* original a005, guest PC 0x0c035566 */
if(!s->budget--) { s->failed_pc=0x0c035566u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c035574;
P_0c035568: /* original 6d12, guest PC 0x0c035568 */
if(!s->budget--) { s->failed_pc=0x0c035568u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c03556a;
P_0c03556a: /* original e04e, guest PC 0x0c03556a */
if(!s->budget--) { s->failed_pc=0x0c03556au; return 0; }
r[0]=0x0000004eu;
goto P_0c03556c;
P_0c03556c: /* original a008, guest PC 0x0c03556c */
if(!s->budget--) { s->failed_pc=0x0c03556cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035580;
P_0c03556e: /* original 00ed, guest PC 0x0c03556e */
if(!s->budget--) { s->failed_pc=0x0c03556eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035570;
P_0c035570: /* original a006, guest PC 0x0c035570 */
if(!s->budget--) { s->failed_pc=0x0c035570u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035580;
P_0c035572: /* original e0e7, guest PC 0x0c035572 */
if(!s->budget--) { s->failed_pc=0x0c035572u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035574;
P_0c035574: /* original d31c, guest PC 0x0c035574 */
if(!s->budget--) { s->failed_pc=0x0c035574u; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c035576;
P_0c035576: /* original 6432, guest PC 0x0c035576 */
if(!s->budget--) { s->failed_pc=0x0c035576u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c035578;
P_0c035578: /* original 34d8, guest PC 0x0c035578 */
if(!s->budget--) { s->failed_pc=0x0c035578u; return 0; }
r[4]-=r[13];
goto P_0c03557a;
P_0c03557a: /* original 34c6, guest PC 0x0c03557a */
if(!s->budget--) { s->failed_pc=0x0c03557au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[12])!=0);
goto P_0c03557c;
P_0c03557c: /* original 8bd2, guest PC 0x0c03557c */
if(!s->budget--) { s->failed_pc=0x0c03557cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035524; }
goto P_0c03557e;
P_0c03557e: /* original e0eb, guest PC 0x0c03557e */
if(!s->budget--) { s->failed_pc=0x0c03557eu; return 0; }
r[0]=0xffffffebu;
goto P_0c035580;
P_0c035580: /* original 4f26, guest PC 0x0c035580 */
if(!s->budget--) { s->failed_pc=0x0c035580u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035582;
P_0c035582: /* original 6af6, guest PC 0x0c035582 */
if(!s->budget--) { s->failed_pc=0x0c035582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c035584;
P_0c035584: /* original 6bf6, guest PC 0x0c035584 */
if(!s->budget--) { s->failed_pc=0x0c035584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035586;
P_0c035586: /* original 6cf6, guest PC 0x0c035586 */
if(!s->budget--) { s->failed_pc=0x0c035586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035588;
P_0c035588: /* original 6df6, guest PC 0x0c035588 */
if(!s->budget--) { s->failed_pc=0x0c035588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03558a;
P_0c03558a: /* original 000b, guest PC 0x0c03558a */
if(!s->budget--) { s->failed_pc=0x0c03558au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03558c: /* original 6ef6, guest PC 0x0c03558c */
if(!s->budget--) { s->failed_pc=0x0c03558cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03558eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03558eu; return 0; } return 1;
P_0c0357bc: /* original 2fe6, guest PC 0x0c0357bc */
if(!s->budget--) { s->failed_pc=0x0c0357bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0357be;
P_0c0357be: /* original 6e43, guest PC 0x0c0357be */
if(!s->budget--) { s->failed_pc=0x0c0357beu; return 0; }
r[14]=r[4];
goto P_0c0357c0;
P_0c0357c0: /* original 2fd6, guest PC 0x0c0357c0 */
if(!s->budget--) { s->failed_pc=0x0c0357c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0357c2;
P_0c0357c2: /* original 2ee8, guest PC 0x0c0357c2 */
if(!s->budget--) { s->failed_pc=0x0c0357c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0357c4;
P_0c0357c4: /* original 2fc6, guest PC 0x0c0357c4 */
if(!s->budget--) { s->failed_pc=0x0c0357c4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0357c6;
P_0c0357c6: /* original 2fb6, guest PC 0x0c0357c6 */
if(!s->budget--) { s->failed_pc=0x0c0357c6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0357c8;
P_0c0357c8: /* original 2fa6, guest PC 0x0c0357c8 */
if(!s->budget--) { s->failed_pc=0x0c0357c8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0357ca;
P_0c0357ca: /* original 4f22, guest PC 0x0c0357ca */
if(!s->budget--) { s->failed_pc=0x0c0357cau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0357cc;
P_0c0357cc: /* original 8d04, guest PC 0x0c0357cc */
if(!s->budget--) { s->failed_pc=0x0c0357ccu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c0357d8; }
goto P_0c0357d0;
P_0c0357ce: /* original 6d53, guest PC 0x0c0357ce */
if(!s->budget--) { s->failed_pc=0x0c0357ceu; return 0; }
r[13]=r[5];
goto P_0c0357d0;
P_0c0357d0: /* original e048, guest PC 0x0c0357d0 */
if(!s->budget--) { s->failed_pc=0x0c0357d0u; return 0; }
r[0]=0x00000048u;
goto P_0c0357d2;
P_0c0357d2: /* original 02ed, guest PC 0x0c0357d2 */
if(!s->budget--) { s->failed_pc=0x0c0357d2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0357d4;
P_0c0357d4: /* original 2228, guest PC 0x0c0357d4 */
if(!s->budget--) { s->failed_pc=0x0c0357d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0357d6;
P_0c0357d6: /* original 8b01, guest PC 0x0c0357d6 */
if(!s->budget--) { s->failed_pc=0x0c0357d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0357dc; }
goto P_0c0357d8;
P_0c0357d8: /* original a044, guest PC 0x0c0357d8 */
if(!s->budget--) { s->failed_pc=0x0c0357d8u; return 0; }
r[0]=0xfffffff6u;
goto P_0c035864;
P_0c0357da: /* original e0f6, guest PC 0x0c0357da */
if(!s->budget--) { s->failed_pc=0x0c0357dau; return 0; }
r[0]=0xfffffff6u;
goto P_0c0357dc;
P_0c0357dc: /* original 62e2, guest PC 0x0c0357dc */
if(!s->budget--) { s->failed_pc=0x0c0357dcu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0357de;
P_0c0357de: /* original 532a, guest PC 0x0c0357de */
if(!s->budget--) { s->failed_pc=0x0c0357deu; return 0; }
r[3]=read(ram,r[2]+40,4);
goto P_0c0357e0;
P_0c0357e0: /* original 2338, guest PC 0x0c0357e0 */
if(!s->budget--) { s->failed_pc=0x0c0357e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0357e2;
P_0c0357e2: /* original 8901, guest PC 0x0c0357e2 */
if(!s->budget--) { s->failed_pc=0x0c0357e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0357e8; }
goto P_0c0357e4;
P_0c0357e4: /* original a03e, guest PC 0x0c0357e4 */
if(!s->budget--) { s->failed_pc=0x0c0357e4u; return 0; }
r[0]=0x00000000u;
goto P_0c035864;
P_0c0357e6: /* original e000, guest PC 0x0c0357e6 */
if(!s->budget--) { s->failed_pc=0x0c0357e6u; return 0; }
r[0]=0x00000000u;
goto P_0c0357e8;
P_0c0357e8: /* original e31f, guest PC 0x0c0357e8 */
if(!s->budget--) { s->failed_pc=0x0c0357e8u; return 0; }
r[3]=0x0000001fu;
goto P_0c0357ea;
P_0c0357ea: /* original 2368, guest PC 0x0c0357ea */
if(!s->budget--) { s->failed_pc=0x0c0357eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0357ec;
P_0c0357ec: /* original 8901, guest PC 0x0c0357ec */
if(!s->budget--) { s->failed_pc=0x0c0357ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0357f2; }
goto P_0c0357ee;
P_0c0357ee: /* original a039, guest PC 0x0c0357ee */
if(!s->budget--) { s->failed_pc=0x0c0357eeu; return 0; }
r[0]=0xfffffff2u;
goto P_0c035864;
P_0c0357f0: /* original e0f2, guest PC 0x0c0357f0 */
if(!s->budget--) { s->failed_pc=0x0c0357f0u; return 0; }
r[0]=0xfffffff2u;
goto P_0c0357f2;
P_0c0357f2: /* original 5ae5, guest PC 0x0c0357f2 */
if(!s->budget--) { s->failed_pc=0x0c0357f2u; return 0; }
r[10]=read(ram,r[14]+20,4);
goto P_0c0357f4;
P_0c0357f4: /* original eb01, guest PC 0x0c0357f4 */
if(!s->budget--) { s->failed_pc=0x0c0357f4u; return 0; }
r[11]=0x00000001u;
goto P_0c0357f6;
P_0c0357f6: /* original 54e2, guest PC 0x0c0357f6 */
if(!s->budget--) { s->failed_pc=0x0c0357f6u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c0357f8;
P_0c0357f8: /* original 53e4, guest PC 0x0c0357f8 */
if(!s->budget--) { s->failed_pc=0x0c0357f8u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0357fa;
P_0c0357fa: /* original 3a4c, guest PC 0x0c0357fa */
if(!s->budget--) { s->failed_pc=0x0c0357fau; return 0; }
r[10]+=r[4];
goto P_0c0357fc;
P_0c0357fc: /* original 343c, guest PC 0x0c0357fc */
if(!s->budget--) { s->failed_pc=0x0c0357fcu; return 0; }
r[4]+=r[3];
goto P_0c0357fe;
P_0c0357fe: /* original 3a43, guest PC 0x0c0357fe */
if(!s->budget--) { s->failed_pc=0x0c0357feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[4])!=0);
goto P_0c035800;
P_0c035800: /* original 8f02, guest PC 0x0c035800 */
if(!s->budget--) { s->failed_pc=0x0c035800u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c035808; }
goto P_0c035804;
P_0c035802: /* original ec00, guest PC 0x0c035802 */
if(!s->budget--) { s->failed_pc=0x0c035802u; return 0; }
r[12]=0x00000000u;
goto P_0c035804;
P_0c035804: /* original a02b, guest PC 0x0c035804 */
if(!s->budget--) { s->failed_pc=0x0c035804u; return 0; }
write(ram,r[14]+24,r[12],4);
goto P_0c03585e;
P_0c035806: /* original 1ec6, guest PC 0x0c035806 */
if(!s->budget--) { s->failed_pc=0x0c035806u; return 0; }
write(ram,r[14]+24,r[12],4);
goto P_0c035808;
P_0c035808: /* original 63d3, guest PC 0x0c035808 */
if(!s->budget--) { s->failed_pc=0x0c035808u; return 0; }
r[3]=r[13];
goto P_0c03580a;
P_0c03580a: /* original 33ac, guest PC 0x0c03580a */
if(!s->budget--) { s->failed_pc=0x0c03580au; return 0; }
r[3]+=r[10];
goto P_0c03580c;
P_0c03580c: /* original 3347, guest PC 0x0c03580c */
if(!s->budget--) { s->failed_pc=0x0c03580cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[4])!=0);
goto P_0c03580e;
P_0c03580e: /* original 8b01, guest PC 0x0c03580e */
if(!s->budget--) { s->failed_pc=0x0c03580eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035814; }
goto P_0c035810;
P_0c035810: /* original 6d43, guest PC 0x0c035810 */
if(!s->budget--) { s->failed_pc=0x0c035810u; return 0; }
r[13]=r[4];
goto P_0c035812;
P_0c035812: /* original 3da8, guest PC 0x0c035812 */
if(!s->budget--) { s->failed_pc=0x0c035812u; return 0; }
r[13]-=r[10];
goto P_0c035814;
P_0c035814: /* original 2dd8, guest PC 0x0c035814 */
if(!s->budget--) { s->failed_pc=0x0c035814u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c035816;
P_0c035816: /* original 8b03, guest PC 0x0c035816 */
if(!s->budget--) { s->failed_pc=0x0c035816u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035820; }
goto P_0c035818;
P_0c035818: /* original e04c, guest PC 0x0c035818 */
if(!s->budget--) { s->failed_pc=0x0c035818u; return 0; }
r[0]=0x0000004cu;
goto P_0c03581a;
P_0c03581a: /* original 1ec6, guest PC 0x0c03581a */
if(!s->budget--) { s->failed_pc=0x0c03581au; return 0; }
write(ram,r[14]+24,r[12],4);
goto P_0c03581c;
P_0c03581c: /* original a01b, guest PC 0x0c03581c */
if(!s->budget--) { s->failed_pc=0x0c03581cu; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c035856;
P_0c03581e: /* original 0eb5, guest PC 0x0c03581e */
if(!s->budget--) { s->failed_pc=0x0c03581eu; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c035820;
P_0c035820: /* original 63e2, guest PC 0x0c035820 */
if(!s->budget--) { s->failed_pc=0x0c035820u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035822;
P_0c035822: /* original 13b9, guest PC 0x0c035822 */
if(!s->budget--) { s->failed_pc=0x0c035822u; return 0; }
write(ram,r[3]+36,r[11],4);
goto P_0c035824;
P_0c035824: /* original 62e2, guest PC 0x0c035824 */
if(!s->budget--) { s->failed_pc=0x0c035824u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c035826;
P_0c035826: /* original e04a, guest PC 0x0c035826 */
if(!s->budget--) { s->failed_pc=0x0c035826u; return 0; }
r[0]=0x0000004au;
goto P_0c035828;
P_0c035828: /* original 07ed, guest PC 0x0c035828 */
if(!s->budget--) { s->failed_pc=0x0c035828u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c03582a;
P_0c03582a: /* original 65d3, guest PC 0x0c03582a */
if(!s->budget--) { s->failed_pc=0x0c03582au; return 0; }
r[5]=r[13];
goto P_0c03582c;
P_0c03582c: /* original 5325, guest PC 0x0c03582c */
if(!s->budget--) { s->failed_pc=0x0c03582cu; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c03582e;
P_0c03582e: /* original 5131, guest PC 0x0c03582e */
if(!s->budget--) { s->failed_pc=0x0c03582eu; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c035830;
P_0c035830: /* original 410b, guest PC 0x0c035830 */
if(!s->budget--) { s->failed_pc=0x0c035830u; return 0; }
target=r[1];
r[16]=code_base|0x0c035834u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035834u) { target=s->pc; goto dispatch; }
goto P_0c035834;
P_0c035832: /* original 64a3, guest PC 0x0c035832 */
if(!s->budget--) { s->failed_pc=0x0c035832u; return 0; }
r[4]=r[10];
goto P_0c035834;
P_0c035834: /* original 6403, guest PC 0x0c035834 */
if(!s->budget--) { s->failed_pc=0x0c035834u; return 0; }
r[4]=r[0];
goto P_0c035836;
P_0c035836: /* original 2448, guest PC 0x0c035836 */
if(!s->budget--) { s->failed_pc=0x0c035836u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c035838;
P_0c035838: /* original 890f, guest PC 0x0c035838 */
if(!s->budget--) { s->failed_pc=0x0c035838u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03585a; }
goto P_0c03583a;
P_0c03583a: /* original 62e2, guest PC 0x0c03583a */
if(!s->budget--) { s->failed_pc=0x0c03583au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03583c;
P_0c03583c: /* original 12ea, guest PC 0x0c03583c */
if(!s->budget--) { s->failed_pc=0x0c03583cu; return 0; }
write(ram,r[2]+40,r[14],4);
goto P_0c03583e;
P_0c03583e: /* original e302, guest PC 0x0c03583e */
if(!s->budget--) { s->failed_pc=0x0c03583eu; return 0; }
r[3]=0x00000002u;
goto P_0c035840;
P_0c035840: /* original 1e4f, guest PC 0x0c035840 */
if(!s->budget--) { s->failed_pc=0x0c035840u; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c035842;
P_0c035842: /* original e04c, guest PC 0x0c035842 */
if(!s->budget--) { s->failed_pc=0x0c035842u; return 0; }
r[0]=0x0000004cu;
goto P_0c035844;
P_0c035844: /* original 1ed7, guest PC 0x0c035844 */
if(!s->budget--) { s->failed_pc=0x0c035844u; return 0; }
write(ram,r[14]+28,r[13],4);
goto P_0c035846;
P_0c035846: /* original 0e35, guest PC 0x0c035846 */
if(!s->budget--) { s->failed_pc=0x0c035846u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c035848;
P_0c035848: /* original e046, guest PC 0x0c035848 */
if(!s->budget--) { s->failed_pc=0x0c035848u; return 0; }
r[0]=0x00000046u;
goto P_0c03584a;
P_0c03584a: /* original 0eb5, guest PC 0x0c03584a */
if(!s->budget--) { s->failed_pc=0x0c03584au; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c03584c;
P_0c03584c: /* original e044, guest PC 0x0c03584c */
if(!s->budget--) { s->failed_pc=0x0c03584cu; return 0; }
r[0]=0x00000044u;
goto P_0c03584e;
P_0c03584e: /* original 0eb5, guest PC 0x0c03584e */
if(!s->budget--) { s->failed_pc=0x0c03584eu; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c035850;
P_0c035850: /* original 1ec6, guest PC 0x0c035850 */
if(!s->budget--) { s->failed_pc=0x0c035850u; return 0; }
write(ram,r[14]+24,r[12],4);
goto P_0c035852;
P_0c035852: /* original 63e2, guest PC 0x0c035852 */
if(!s->budget--) { s->failed_pc=0x0c035852u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035854;
P_0c035854: /* original 13c9, guest PC 0x0c035854 */
if(!s->budget--) { s->failed_pc=0x0c035854u; return 0; }
write(ram,r[3]+36,r[12],4);
goto P_0c035856;
P_0c035856: /* original a005, guest PC 0x0c035856 */
if(!s->budget--) { s->failed_pc=0x0c035856u; return 0; }
r[0]=r[13];
goto P_0c035864;
P_0c035858: /* original 60d3, guest PC 0x0c035858 */
if(!s->budget--) { s->failed_pc=0x0c035858u; return 0; }
r[0]=r[13];
goto P_0c03585a;
P_0c03585a: /* original 62e2, guest PC 0x0c03585a */
if(!s->budget--) { s->failed_pc=0x0c03585au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03585c;
P_0c03585c: /* original 12c9, guest PC 0x0c03585c */
if(!s->budget--) { s->failed_pc=0x0c03585cu; return 0; }
write(ram,r[2]+36,r[12],4);
goto P_0c03585e;
P_0c03585e: /* original e04c, guest PC 0x0c03585e */
if(!s->budget--) { s->failed_pc=0x0c03585eu; return 0; }
r[0]=0x0000004cu;
goto P_0c035860;
P_0c035860: /* original 0eb5, guest PC 0x0c035860 */
if(!s->budget--) { s->failed_pc=0x0c035860u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c035862;
P_0c035862: /* original 60c3, guest PC 0x0c035862 */
if(!s->budget--) { s->failed_pc=0x0c035862u; return 0; }
r[0]=r[12];
goto P_0c035864;
P_0c035864: /* original 4f26, guest PC 0x0c035864 */
if(!s->budget--) { s->failed_pc=0x0c035864u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035866;
P_0c035866: /* original 6af6, guest PC 0x0c035866 */
if(!s->budget--) { s->failed_pc=0x0c035866u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c035868;
P_0c035868: /* original 6bf6, guest PC 0x0c035868 */
if(!s->budget--) { s->failed_pc=0x0c035868u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03586a;
P_0c03586a: /* original 6cf6, guest PC 0x0c03586a */
if(!s->budget--) { s->failed_pc=0x0c03586au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03586c;
P_0c03586c: /* original 6df6, guest PC 0x0c03586c */
if(!s->budget--) { s->failed_pc=0x0c03586cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03586e;
P_0c03586e: /* original 000b, guest PC 0x0c03586e */
if(!s->budget--) { s->failed_pc=0x0c03586eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035870: /* original 6ef6, guest PC 0x0c035870 */
if(!s->budget--) { s->failed_pc=0x0c035870u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035872u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035872u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
