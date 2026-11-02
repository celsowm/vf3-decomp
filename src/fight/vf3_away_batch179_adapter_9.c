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
int vf3_away_batch179_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06149eu: goto P_0c06149e;
case 0x0c0614a0u: goto P_0c0614a0;
case 0x0c0614a2u: goto P_0c0614a2;
case 0x0c0614a4u: goto P_0c0614a4;
case 0x0c0614a6u: goto P_0c0614a6;
case 0x0c0614a8u: goto P_0c0614a8;
case 0x0c0614aau: goto P_0c0614aa;
case 0x0c0614acu: goto P_0c0614ac;
case 0x0c0614aeu: goto P_0c0614ae;
case 0x0c0614b0u: goto P_0c0614b0;
case 0x0c0614b2u: goto P_0c0614b2;
case 0x0c0614b4u: goto P_0c0614b4;
case 0x0c0614b6u: goto P_0c0614b6;
case 0x0c0614b8u: goto P_0c0614b8;
case 0x0c0614bau: goto P_0c0614ba;
case 0x0c0614bcu: goto P_0c0614bc;
case 0x0c0614beu: goto P_0c0614be;
case 0x0c0614c0u: goto P_0c0614c0;
case 0x0c0614c2u: goto P_0c0614c2;
case 0x0c0614c4u: goto P_0c0614c4;
case 0x0c0614c6u: goto P_0c0614c6;
case 0x0c0614c8u: goto P_0c0614c8;
case 0x0c0614cau: goto P_0c0614ca;
case 0x0c0614ccu: goto P_0c0614cc;
case 0x0c0614ceu: goto P_0c0614ce;
case 0x0c0614d0u: goto P_0c0614d0;
case 0x0c0614d2u: goto P_0c0614d2;
case 0x0c0614d4u: goto P_0c0614d4;
case 0x0c0614d6u: goto P_0c0614d6;
case 0x0c0614d8u: goto P_0c0614d8;
case 0x0c0614dau: goto P_0c0614da;
case 0x0c0614dcu: goto P_0c0614dc;
case 0x0c0614deu: goto P_0c0614de;
case 0x0c0614e0u: goto P_0c0614e0;
case 0x0c0614e2u: goto P_0c0614e2;
case 0x0c0614e4u: goto P_0c0614e4;
case 0x0c0614e6u: goto P_0c0614e6;
case 0x0c0614e8u: goto P_0c0614e8;
case 0x0c0614eau: goto P_0c0614ea;
case 0x0c0614ecu: goto P_0c0614ec;
case 0x0c0614eeu: goto P_0c0614ee;
case 0x0c0614f0u: goto P_0c0614f0;
case 0x0c0614f2u: goto P_0c0614f2;
case 0x0c0614f4u: goto P_0c0614f4;
case 0x0c0614f6u: goto P_0c0614f6;
case 0x0c0614f8u: goto P_0c0614f8;
case 0x0c0614fau: goto P_0c0614fa;
case 0x0c0614fcu: goto P_0c0614fc;
case 0x0c0614feu: goto P_0c0614fe;
case 0x0c061500u: goto P_0c061500;
case 0x0c061502u: goto P_0c061502;
case 0x0c061504u: goto P_0c061504;
case 0x0c061506u: goto P_0c061506;
case 0x0c061508u: goto P_0c061508;
case 0x0c06150au: goto P_0c06150a;
case 0x0c06150cu: goto P_0c06150c;
case 0x0c06150eu: goto P_0c06150e;
case 0x0c061510u: goto P_0c061510;
case 0x0c061512u: goto P_0c061512;
case 0x0c061514u: goto P_0c061514;
case 0x0c061516u: goto P_0c061516;
case 0x0c061518u: goto P_0c061518;
case 0x0c06151au: goto P_0c06151a;
case 0x0c06151cu: goto P_0c06151c;
case 0x0c06151eu: goto P_0c06151e;
case 0x0c061520u: goto P_0c061520;
case 0x0c061522u: goto P_0c061522;
case 0x0c061524u: goto P_0c061524;
case 0x0c061526u: goto P_0c061526;
case 0x0c061528u: goto P_0c061528;
case 0x0c06152au: goto P_0c06152a;
case 0x0c06152cu: goto P_0c06152c;
case 0x0c06152eu: goto P_0c06152e;
case 0x0c061530u: goto P_0c061530;
case 0x0c061532u: goto P_0c061532;
case 0x0c061534u: goto P_0c061534;
case 0x0c061536u: goto P_0c061536;
case 0x0c061538u: goto P_0c061538;
case 0x0c06153au: goto P_0c06153a;
case 0x0c06153cu: goto P_0c06153c;
case 0x0c06153eu: goto P_0c06153e;
case 0x0c061540u: goto P_0c061540;
case 0x0c061542u: goto P_0c061542;
case 0x0c061544u: goto P_0c061544;
case 0x0c061546u: goto P_0c061546;
case 0x0c061548u: goto P_0c061548;
case 0x0c06154au: goto P_0c06154a;
case 0x0c06154cu: goto P_0c06154c;
case 0x0c06154eu: goto P_0c06154e;
case 0x0c061550u: goto P_0c061550;
case 0x0c061552u: goto P_0c061552;
case 0x0c061554u: goto P_0c061554;
case 0x0c061556u: goto P_0c061556;
case 0x0c061558u: goto P_0c061558;
case 0x0c06155au: goto P_0c06155a;
case 0x0c06155cu: goto P_0c06155c;
case 0x0c06155eu: goto P_0c06155e;
case 0x0c061560u: goto P_0c061560;
case 0x0c061562u: goto P_0c061562;
case 0x0c061564u: goto P_0c061564;
case 0x0c061566u: goto P_0c061566;
case 0x0c061568u: goto P_0c061568;
case 0x0c06156au: goto P_0c06156a;
case 0x0c06156cu: goto P_0c06156c;
case 0x0c06156eu: goto P_0c06156e;
case 0x0c061570u: goto P_0c061570;
case 0x0c061572u: goto P_0c061572;
case 0x0c061574u: goto P_0c061574;
case 0x0c061576u: goto P_0c061576;
case 0x0c061578u: goto P_0c061578;
case 0x0c06157au: goto P_0c06157a;
case 0x0c06157cu: goto P_0c06157c;
case 0x0c06157eu: goto P_0c06157e;
case 0x0c061580u: goto P_0c061580;
case 0x0c061582u: goto P_0c061582;
case 0x0c061584u: goto P_0c061584;
case 0x0c061586u: goto P_0c061586;
case 0x0c061588u: goto P_0c061588;
case 0x0c06158au: goto P_0c06158a;
case 0x0c06158cu: goto P_0c06158c;
case 0x0c06158eu: goto P_0c06158e;
case 0x0c061590u: goto P_0c061590;
case 0x0c061592u: goto P_0c061592;
case 0x0c061594u: goto P_0c061594;
case 0x0c061910u: goto P_0c061910;
case 0x0c061912u: goto P_0c061912;
case 0x0c061914u: goto P_0c061914;
case 0x0c061916u: goto P_0c061916;
case 0x0c061918u: goto P_0c061918;
case 0x0c06191au: goto P_0c06191a;
case 0x0c06191cu: goto P_0c06191c;
case 0x0c06191eu: goto P_0c06191e;
case 0x0c061920u: goto P_0c061920;
case 0x0c061922u: goto P_0c061922;
case 0x0c061924u: goto P_0c061924;
case 0x0c061926u: goto P_0c061926;
case 0x0c061928u: goto P_0c061928;
case 0x0c06192au: goto P_0c06192a;
case 0x0c06192cu: goto P_0c06192c;
case 0x0c06192eu: goto P_0c06192e;
case 0x0c061930u: goto P_0c061930;
case 0x0c061932u: goto P_0c061932;
case 0x0c061934u: goto P_0c061934;
case 0x0c061936u: goto P_0c061936;
case 0x0c061938u: goto P_0c061938;
case 0x0c06193au: goto P_0c06193a;
case 0x0c06193cu: goto P_0c06193c;
case 0x0c06193eu: goto P_0c06193e;
case 0x0c061940u: goto P_0c061940;
case 0x0c061942u: goto P_0c061942;
case 0x0c061944u: goto P_0c061944;
case 0x0c061946u: goto P_0c061946;
case 0x0c061948u: goto P_0c061948;
case 0x0c06194au: goto P_0c06194a;
case 0x0c06194cu: goto P_0c06194c;
case 0x0c06194eu: goto P_0c06194e;
case 0x0c061950u: goto P_0c061950;
case 0x0c061952u: goto P_0c061952;
case 0x0c061954u: goto P_0c061954;
case 0x0c061956u: goto P_0c061956;
case 0x0c061958u: goto P_0c061958;
case 0x0c06195au: goto P_0c06195a;
case 0x0c06195cu: goto P_0c06195c;
case 0x0c06195eu: goto P_0c06195e;
case 0x0c061960u: goto P_0c061960;
case 0x0c061962u: goto P_0c061962;
case 0x0c061964u: goto P_0c061964;
case 0x0c061966u: goto P_0c061966;
case 0x0c061968u: goto P_0c061968;
case 0x0c06196au: goto P_0c06196a;
case 0x0c06196cu: goto P_0c06196c;
case 0x0c06196eu: goto P_0c06196e;
case 0x0c061970u: goto P_0c061970;
case 0x0c061972u: goto P_0c061972;
case 0x0c061974u: goto P_0c061974;
case 0x0c061976u: goto P_0c061976;
case 0x0c061978u: goto P_0c061978;
case 0x0c06197au: goto P_0c06197a;
case 0x0c06197cu: goto P_0c06197c;
case 0x0c06197eu: goto P_0c06197e;
case 0x0c061980u: goto P_0c061980;
case 0x0c061982u: goto P_0c061982;
case 0x0c061984u: goto P_0c061984;
case 0x0c061986u: goto P_0c061986;
case 0x0c061988u: goto P_0c061988;
case 0x0c06198au: goto P_0c06198a;
case 0x0c06198cu: goto P_0c06198c;
case 0x0c06198eu: goto P_0c06198e;
case 0x0c061990u: goto P_0c061990;
case 0x0c061992u: goto P_0c061992;
case 0x0c061994u: goto P_0c061994;
case 0x0c061996u: goto P_0c061996;
case 0x0c061998u: goto P_0c061998;
case 0x0c06199au: goto P_0c06199a;
case 0x0c06199cu: goto P_0c06199c;
case 0x0c06199eu: goto P_0c06199e;
case 0x0c0619a0u: goto P_0c0619a0;
case 0x0c0619a2u: goto P_0c0619a2;
case 0x0c0619a4u: goto P_0c0619a4;
case 0x0c0619a6u: goto P_0c0619a6;
case 0x0c0619a8u: goto P_0c0619a8;
case 0x0c0619aau: goto P_0c0619aa;
case 0x0c0619acu: goto P_0c0619ac;
case 0x0c0619aeu: goto P_0c0619ae;
case 0x0c0619b0u: goto P_0c0619b0;
case 0x0c0619b2u: goto P_0c0619b2;
case 0x0c0619b4u: goto P_0c0619b4;
case 0x0c0619b6u: goto P_0c0619b6;
case 0x0c0619b8u: goto P_0c0619b8;
case 0x0c0619bau: goto P_0c0619ba;
case 0x0c0619bcu: goto P_0c0619bc;
case 0x0c0619beu: goto P_0c0619be;
case 0x0c0619c0u: goto P_0c0619c0;
case 0x0c0619c2u: goto P_0c0619c2;
case 0x0c0619c4u: goto P_0c0619c4;
case 0x0c0619c6u: goto P_0c0619c6;
case 0x0c0619c8u: goto P_0c0619c8;
case 0x0c0619cau: goto P_0c0619ca;
case 0x0c0619ccu: goto P_0c0619cc;
case 0x0c0619ceu: goto P_0c0619ce;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06149e: /* original 6543, guest PC 0x0c06149e */
if(!s->budget--) { s->failed_pc=0x0c06149eu; return 0; }
r[5]=r[4];
goto P_0c0614a0;
P_0c0614a0: /* original d352, guest PC 0x0c0614a0 */
if(!s->budget--) { s->failed_pc=0x0c0614a0u; return 0; }
r[3]=read(ram,0x0c0615ecu,4);
goto P_0c0614a2;
P_0c0614a2: /* original 2fe6, guest PC 0x0c0614a2 */
if(!s->budget--) { s->failed_pc=0x0c0614a2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614a4;
P_0c0614a4: /* original 2fd6, guest PC 0x0c0614a4 */
if(!s->budget--) { s->failed_pc=0x0c0614a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614a6;
P_0c0614a6: /* original 2fc6, guest PC 0x0c0614a6 */
if(!s->budget--) { s->failed_pc=0x0c0614a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614a8;
P_0c0614a8: /* original 2fb6, guest PC 0x0c0614a8 */
if(!s->budget--) { s->failed_pc=0x0c0614a8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614aa;
P_0c0614aa: /* original 6b43, guest PC 0x0c0614aa */
if(!s->budget--) { s->failed_pc=0x0c0614aau; return 0; }
r[11]=r[4];
goto P_0c0614ac;
P_0c0614ac: /* original 4f22, guest PC 0x0c0614ac */
if(!s->budget--) { s->failed_pc=0x0c0614acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0614ae;
P_0c0614ae: /* original 7fe4, guest PC 0x0c0614ae */
if(!s->budget--) { s->failed_pc=0x0c0614aeu; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0614b0;
P_0c0614b0: /* original 64f3, guest PC 0x0c0614b0 */
if(!s->budget--) { s->failed_pc=0x0c0614b0u; return 0; }
r[4]=r[15];
goto P_0c0614b2;
P_0c0614b2: /* original 430b, guest PC 0x0c0614b2 */
if(!s->budget--) { s->failed_pc=0x0c0614b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0614b6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0614b6u) { target=s->pc; goto dispatch; }
goto P_0c0614b6;
P_0c0614b4: /* original 7408, guest PC 0x0c0614b4 */
if(!s->budget--) { s->failed_pc=0x0c0614b4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0614b6;
P_0c0614b6: /* original d24e, guest PC 0x0c0614b6 */
if(!s->budget--) { s->failed_pc=0x0c0614b6u; return 0; }
r[2]=read(ram,0x0c0615f0u,4);
goto P_0c0614b8;
P_0c0614b8: /* original 6422, guest PC 0x0c0614b8 */
if(!s->budget--) { s->failed_pc=0x0c0614b8u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0614ba;
P_0c0614ba: /* original 2448, guest PC 0x0c0614ba */
if(!s->budget--) { s->failed_pc=0x0c0614bau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0614bc;
P_0c0614bc: /* original 8d1e, guest PC 0x0c0614bc */
if(!s->budget--) { s->failed_pc=0x0c0614bcu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(cond) { goto P_0c0614fc; }
goto P_0c0614c0;
P_0c0614be: /* original ee00, guest PC 0x0c0614be */
if(!s->budget--) { s->failed_pc=0x0c0614beu; return 0; }
r[14]=0x00000000u;
goto P_0c0614c0;
P_0c0614c0: /* original d74c, guest PC 0x0c0614c0 */
if(!s->budget--) { s->failed_pc=0x0c0614c0u; return 0; }
r[7]=read(ram,0x0c0615f4u,4);
goto P_0c0614c2;
P_0c0614c2: /* original 6241, guest PC 0x0c0614c2 */
if(!s->budget--) { s->failed_pc=0x0c0614c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c0614c4;
P_0c0614c4: /* original 53f2, guest PC 0x0c0614c4 */
if(!s->budget--) { s->failed_pc=0x0c0614c4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0614c6;
P_0c0614c6: /* original 622d, guest PC 0x0c0614c6 */
if(!s->budget--) { s->failed_pc=0x0c0614c6u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0614c8;
P_0c0614c8: /* original 2279, guest PC 0x0c0614c8 */
if(!s->budget--) { s->failed_pc=0x0c0614c8u; return 0; }
r[2]&=r[7];
goto P_0c0614ca;
P_0c0614ca: /* original 3230, guest PC 0x0c0614ca */
if(!s->budget--) { s->failed_pc=0x0c0614cau; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0614cc;
P_0c0614cc: /* original 8b11, guest PC 0x0c0614cc */
if(!s->budget--) { s->failed_pc=0x0c0614ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614f2; }
goto P_0c0614ce;
P_0c0614ce: /* original e500, guest PC 0x0c0614ce */
if(!s->budget--) { s->failed_pc=0x0c0614ceu; return 0; }
r[5]=0x00000000u;
goto P_0c0614d0;
P_0c0614d0: /* original a00d, guest PC 0x0c0614d0 */
if(!s->budget--) { s->failed_pc=0x0c0614d0u; return 0; }
r[6]=read(ram,r[15]+24,4);
goto P_0c0614ee;
P_0c0614d2: /* original 56f6, guest PC 0x0c0614d2 */
if(!s->budget--) { s->failed_pc=0x0c0614d2u; return 0; }
r[6]=read(ram,r[15]+24,4);
goto P_0c0614d4;
P_0c0614d4: /* original 6253, guest PC 0x0c0614d4 */
if(!s->budget--) { s->failed_pc=0x0c0614d4u; return 0; }
r[2]=r[5];
goto P_0c0614d6;
P_0c0614d6: /* original 4208, guest PC 0x0c0614d6 */
if(!s->budget--) { s->failed_pc=0x0c0614d6u; return 0; }
r[2]<<=2;
goto P_0c0614d8;
P_0c0614d8: /* original 6343, guest PC 0x0c0614d8 */
if(!s->budget--) { s->failed_pc=0x0c0614d8u; return 0; }
r[3]=r[4];
goto P_0c0614da;
P_0c0614da: /* original 730c, guest PC 0x0c0614da */
if(!s->budget--) { s->failed_pc=0x0c0614dau; return 0; }
r[3]+=0x0000000cu;
goto P_0c0614dc;
P_0c0614dc: /* original 323c, guest PC 0x0c0614dc */
if(!s->budget--) { s->failed_pc=0x0c0614dcu; return 0; }
r[2]+=r[3];
goto P_0c0614de;
P_0c0614de: /* original 6122, guest PC 0x0c0614de */
if(!s->budget--) { s->failed_pc=0x0c0614deu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0614e0;
P_0c0614e0: /* original 2118, guest PC 0x0c0614e0 */
if(!s->budget--) { s->failed_pc=0x0c0614e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0614e2;
P_0c0614e2: /* original 8b03, guest PC 0x0c0614e2 */
if(!s->budget--) { s->failed_pc=0x0c0614e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614ec; }
goto P_0c0614e4;
P_0c0614e4: /* original 6e43, guest PC 0x0c0614e4 */
if(!s->budget--) { s->failed_pc=0x0c0614e4u; return 0; }
r[14]=r[4];
goto P_0c0614e6;
P_0c0614e6: /* original 6d53, guest PC 0x0c0614e6 */
if(!s->budget--) { s->failed_pc=0x0c0614e6u; return 0; }
r[13]=r[5];
goto P_0c0614e8;
P_0c0614e8: /* original 6563, guest PC 0x0c0614e8 */
if(!s->budget--) { s->failed_pc=0x0c0614e8u; return 0; }
r[5]=r[6];
goto P_0c0614ea;
P_0c0614ea: /* original e400, guest PC 0x0c0614ea */
if(!s->budget--) { s->failed_pc=0x0c0614eau; return 0; }
r[4]=0x00000000u;
goto P_0c0614ec;
P_0c0614ec: /* original 7501, guest PC 0x0c0614ec */
if(!s->budget--) { s->failed_pc=0x0c0614ecu; return 0; }
r[5]+=0x00000001u;
goto P_0c0614ee;
P_0c0614ee: /* original 3562, guest PC 0x0c0614ee */
if(!s->budget--) { s->failed_pc=0x0c0614eeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c0614f0;
P_0c0614f0: /* original 8bf0, guest PC 0x0c0614f0 */
if(!s->budget--) { s->failed_pc=0x0c0614f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614d4; }
goto P_0c0614f2;
P_0c0614f2: /* original 2ee8, guest PC 0x0c0614f2 */
if(!s->budget--) { s->failed_pc=0x0c0614f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0614f4;
P_0c0614f4: /* original 8b00, guest PC 0x0c0614f4 */
if(!s->budget--) { s->failed_pc=0x0c0614f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614f8; }
goto P_0c0614f6;
P_0c0614f6: /* original 5441, guest PC 0x0c0614f6 */
if(!s->budget--) { s->failed_pc=0x0c0614f6u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0614f8;
P_0c0614f8: /* original 2448, guest PC 0x0c0614f8 */
if(!s->budget--) { s->failed_pc=0x0c0614f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0614fa;
P_0c0614fa: /* original 8be2, guest PC 0x0c0614fa */
if(!s->budget--) { s->failed_pc=0x0c0614fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614c2; }
goto P_0c0614fc;
P_0c0614fc: /* original 2ee8, guest PC 0x0c0614fc */
if(!s->budget--) { s->failed_pc=0x0c0614fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0614fe;
P_0c0614fe: /* original 8b32, guest PC 0x0c0614fe */
if(!s->budget--) { s->failed_pc=0x0c0614feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061566; }
goto P_0c061500;
P_0c061500: /* original d33d, guest PC 0x0c061500 */
if(!s->budget--) { s->failed_pc=0x0c061500u; return 0; }
r[3]=read(ram,0x0c0615f8u,4);
goto P_0c061502;
P_0c061502: /* original 430b, guest PC 0x0c061502 */
if(!s->budget--) { s->failed_pc=0x0c061502u; return 0; }
target=r[3];
r[16]=code_base|0x0c061506u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061506u) { target=s->pc; goto dispatch; }
goto P_0c061506;
P_0c061504: /* original 0009, guest PC 0x0c061504 */
if(!s->budget--) { s->failed_pc=0x0c061504u; return 0; }
goto P_0c061506;
P_0c061506: /* original 6e03, guest PC 0x0c061506 */
if(!s->budget--) { s->failed_pc=0x0c061506u; return 0; }
r[14]=r[0];
goto P_0c061508;
P_0c061508: /* original 2ee8, guest PC 0x0c061508 */
if(!s->budget--) { s->failed_pc=0x0c061508u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06150a;
P_0c06150a: /* original 892a, guest PC 0x0c06150a */
if(!s->budget--) { s->failed_pc=0x0c06150au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061562; }
goto P_0c06150c;
P_0c06150c: /* original a001, guest PC 0x0c06150c */
if(!s->budget--) { s->failed_pc=0x0c06150cu; return 0; }
r[4]=0x00000010u;
goto P_0c061512;
P_0c06150e: /* original e410, guest PC 0x0c06150e */
if(!s->budget--) { s->failed_pc=0x0c06150eu; return 0; }
r[4]=0x00000010u;
goto P_0c061510;
P_0c061510: /* original 74ff, guest PC 0x0c061510 */
if(!s->budget--) { s->failed_pc=0x0c061510u; return 0; }
r[4]+=0xffffffffu;
goto P_0c061512;
P_0c061512: /* original 2448, guest PC 0x0c061512 */
if(!s->budget--) { s->failed_pc=0x0c061512u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061514;
P_0c061514: /* original 8bfc, guest PC 0x0c061514 */
if(!s->budget--) { s->failed_pc=0x0c061514u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061510; }
goto P_0c061516;
P_0c061516: /* original ed00, guest PC 0x0c061516 */
if(!s->budget--) { s->failed_pc=0x0c061516u; return 0; }
r[13]=0x00000000u;
goto P_0c061518;
P_0c061518: /* original d435, guest PC 0x0c061518 */
if(!s->budget--) { s->failed_pc=0x0c061518u; return 0; }
r[4]=read(ram,0x0c0615f0u,4);
goto P_0c06151a;
P_0c06151a: /* original d238, guest PC 0x0c06151a */
if(!s->budget--) { s->failed_pc=0x0c06151au; return 0; }
r[2]=read(ram,0x0c0615fcu,4);
goto P_0c06151c;
P_0c06151c: /* original 420b, guest PC 0x0c06151c */
if(!s->budget--) { s->failed_pc=0x0c06151cu; return 0; }
target=r[2];
r[16]=code_base|0x0c061520u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061520u) { target=s->pc; goto dispatch; }
goto P_0c061520;
P_0c06151e: /* original 65e3, guest PC 0x0c06151e */
if(!s->budget--) { s->failed_pc=0x0c06151eu; return 0; }
r[5]=r[14];
goto P_0c061520;
P_0c061520: /* original 53f2, guest PC 0x0c061520 */
if(!s->budget--) { s->failed_pc=0x0c061520u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c061522;
P_0c061522: /* original 62e1, guest PC 0x0c061522 */
if(!s->budget--) { s->failed_pc=0x0c061522u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c061524;
P_0c061524: /* original 223b, guest PC 0x0c061524 */
if(!s->budget--) { s->failed_pc=0x0c061524u; return 0; }
r[2]|=r[3];
goto P_0c061526;
P_0c061526: /* original 2e21, guest PC 0x0c061526 */
if(!s->budget--) { s->failed_pc=0x0c061526u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c061528;
P_0c061528: /* original 5cf5, guest PC 0x0c061528 */
if(!s->budget--) { s->failed_pc=0x0c061528u; return 0; }
r[12]=read(ram,r[15]+20,4);
goto P_0c06152a;
P_0c06152a: /* original d335, guest PC 0x0c06152a */
if(!s->budget--) { s->failed_pc=0x0c06152au; return 0; }
r[3]=read(ram,0x0c061600u,4);
goto P_0c06152c;
P_0c06152c: /* original 6032, guest PC 0x0c06152c */
if(!s->budget--) { s->failed_pc=0x0c06152cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06152e;
P_0c06152e: /* original c804, guest PC 0x0c06152e */
if(!s->budget--) { s->failed_pc=0x0c06152eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c061530;
P_0c061530: /* original 890d, guest PC 0x0c061530 */
if(!s->budget--) { s->failed_pc=0x0c061530u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06154e; }
goto P_0c061532;
P_0c061532: /* original 65f3, guest PC 0x0c061532 */
if(!s->budget--) { s->failed_pc=0x0c061532u; return 0; }
r[5]=r[15];
goto P_0c061534;
P_0c061534: /* original 7504, guest PC 0x0c061534 */
if(!s->budget--) { s->failed_pc=0x0c061534u; return 0; }
r[5]+=0x00000004u;
goto P_0c061536;
P_0c061536: /* original b1eb, guest PC 0x0c061536 */
if(!s->budget--) { s->failed_pc=0x0c061536u; return 0; }
target=code_base|0x0c061910u; r[16]=code_base|0x0c06153au;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06153au) { target=s->pc; goto dispatch; }
goto P_0c06153a;
P_0c061538: /* original 64f3, guest PC 0x0c061538 */
if(!s->budget--) { s->failed_pc=0x0c061538u; return 0; }
r[4]=r[15];
goto P_0c06153a;
P_0c06153a: /* original 53f1, guest PC 0x0c06153a */
if(!s->budget--) { s->failed_pc=0x0c06153au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06153c;
P_0c06153c: /* original 62f2, guest PC 0x0c06153c */
if(!s->budget--) { s->failed_pc=0x0c06153cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06153e;
P_0c06153e: /* original 3233, guest PC 0x0c06153e */
if(!s->budget--) { s->failed_pc=0x0c06153eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c061540;
P_0c061540: /* original 8b05, guest PC 0x0c061540 */
if(!s->budget--) { s->failed_pc=0x0c061540u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06154e; }
goto P_0c061542;
P_0c061542: /* original 66e3, guest PC 0x0c061542 */
if(!s->budget--) { s->failed_pc=0x0c061542u; return 0; }
r[6]=r[14];
goto P_0c061544;
P_0c061544: /* original 65c3, guest PC 0x0c061544 */
if(!s->budget--) { s->failed_pc=0x0c061544u; return 0; }
r[5]=r[12];
goto P_0c061546;
P_0c061546: /* original b5cd, guest PC 0x0c061546 */
if(!s->budget--) { s->failed_pc=0x0c061546u; return 0; }
target=code_base|0x0c0620e4u; r[16]=code_base|0x0c06154au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06154au) { target=s->pc; goto dispatch; }
goto P_0c06154a;
P_0c061548: /* original e400, guest PC 0x0c061548 */
if(!s->budget--) { s->failed_pc=0x0c061548u; return 0; }
r[4]=0x00000000u;
goto P_0c06154a;
P_0c06154a: /* original a005, guest PC 0x0c06154a */
if(!s->budget--) { s->failed_pc=0x0c06154au; return 0; }
r[4]=r[0];
goto P_0c061558;
P_0c06154c: /* original 6403, guest PC 0x0c06154c */
if(!s->budget--) { s->failed_pc=0x0c06154cu; return 0; }
r[4]=r[0];
goto P_0c06154e;
P_0c06154e: /* original 66e3, guest PC 0x0c06154e */
if(!s->budget--) { s->failed_pc=0x0c06154eu; return 0; }
r[6]=r[14];
goto P_0c061550;
P_0c061550: /* original 65c3, guest PC 0x0c061550 */
if(!s->budget--) { s->failed_pc=0x0c061550u; return 0; }
r[5]=r[12];
goto P_0c061552;
P_0c061552: /* original b5c7, guest PC 0x0c061552 */
if(!s->budget--) { s->failed_pc=0x0c061552u; return 0; }
target=code_base|0x0c0620e4u; r[16]=code_base|0x0c061556u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061556u) { target=s->pc; goto dispatch; }
goto P_0c061556;
P_0c061554: /* original e401, guest PC 0x0c061554 */
if(!s->budget--) { s->failed_pc=0x0c061554u; return 0; }
r[4]=0x00000001u;
goto P_0c061556;
P_0c061556: /* original 6403, guest PC 0x0c061556 */
if(!s->budget--) { s->failed_pc=0x0c061556u; return 0; }
r[4]=r[0];
goto P_0c061558;
P_0c061558: /* original 2448, guest PC 0x0c061558 */
if(!s->budget--) { s->failed_pc=0x0c061558u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06155a;
P_0c06155a: /* original 8904, guest PC 0x0c06155a */
if(!s->budget--) { s->failed_pc=0x0c06155au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061566; }
goto P_0c06155c;
P_0c06155c: /* original d229, guest PC 0x0c06155c */
if(!s->budget--) { s->failed_pc=0x0c06155cu; return 0; }
r[2]=read(ram,0x0c061604u,4);
goto P_0c06155e;
P_0c06155e: /* original 420b, guest PC 0x0c06155e */
if(!s->budget--) { s->failed_pc=0x0c06155eu; return 0; }
target=r[2];
r[16]=code_base|0x0c061562u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061562u) { target=s->pc; goto dispatch; }
goto P_0c061562;
P_0c061560: /* original 64e3, guest PC 0x0c061560 */
if(!s->budget--) { s->failed_pc=0x0c061560u; return 0; }
r[4]=r[14];
goto P_0c061562;
P_0c061562: /* original a011, guest PC 0x0c061562 */
if(!s->budget--) { s->failed_pc=0x0c061562u; return 0; }
r[0]=0x00000003u;
goto P_0c061588;
P_0c061564: /* original e003, guest PC 0x0c061564 */
if(!s->budget--) { s->failed_pc=0x0c061564u; return 0; }
r[0]=0x00000003u;
goto P_0c061566;
P_0c061566: /* original 53f3, guest PC 0x0c061566 */
if(!s->budget--) { s->failed_pc=0x0c061566u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c061568;
P_0c061568: /* original 52e2, guest PC 0x0c061568 */
if(!s->budget--) { s->failed_pc=0x0c061568u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c06156a;
P_0c06156a: /* original 4309, guest PC 0x0c06156a */
if(!s->budget--) { s->failed_pc=0x0c06156au; return 0; }
r[3]>>=2;
goto P_0c06156c;
P_0c06156c: /* original 0d37, guest PC 0x0c06156c */
if(!s->budget--) { s->failed_pc=0x0c06156cu; return 0; }
r[19]=r[13]*r[3];
goto P_0c06156e;
P_0c06156e: /* original 4d08, guest PC 0x0c06156e */
if(!s->budget--) { s->failed_pc=0x0c06156eu; return 0; }
r[13]<<=2;
goto P_0c061570;
P_0c061570: /* original 031a, guest PC 0x0c061570 */
if(!s->budget--) { s->failed_pc=0x0c061570u; return 0; }
r[3]=r[19];
goto P_0c061572;
P_0c061572: /* original 4308, guest PC 0x0c061572 */
if(!s->budget--) { s->failed_pc=0x0c061572u; return 0; }
r[3]<<=2;
goto P_0c061574;
P_0c061574: /* original 332c, guest PC 0x0c061574 */
if(!s->budget--) { s->failed_pc=0x0c061574u; return 0; }
r[3]+=r[2];
goto P_0c061576;
P_0c061576: /* original 1b37, guest PC 0x0c061576 */
if(!s->budget--) { s->failed_pc=0x0c061576u; return 0; }
write(ram,r[11]+28,r[3],4);
goto P_0c061578;
P_0c061578: /* original 63e3, guest PC 0x0c061578 */
if(!s->budget--) { s->failed_pc=0x0c061578u; return 0; }
r[3]=r[14];
goto P_0c06157a;
P_0c06157a: /* original 730c, guest PC 0x0c06157a */
if(!s->budget--) { s->failed_pc=0x0c06157au; return 0; }
r[3]+=0x0000000cu;
goto P_0c06157c;
P_0c06157c: /* original 3d3c, guest PC 0x0c06157c */
if(!s->budget--) { s->failed_pc=0x0c06157cu; return 0; }
r[13]+=r[3];
goto P_0c06157e;
P_0c06157e: /* original 2db2, guest PC 0x0c06157e */
if(!s->budget--) { s->failed_pc=0x0c06157eu; return 0; }
write(ram,r[13],r[11],4);
goto P_0c061580;
P_0c061580: /* original 60e1, guest PC 0x0c061580 */
if(!s->budget--) { s->failed_pc=0x0c061580u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c061582;
P_0c061582: /* original cb02, guest PC 0x0c061582 */
if(!s->budget--) { s->failed_pc=0x0c061582u; return 0; }
r[0]|=2u;
goto P_0c061584;
P_0c061584: /* original 2e01, guest PC 0x0c061584 */
if(!s->budget--) { s->failed_pc=0x0c061584u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c061586;
P_0c061586: /* original e000, guest PC 0x0c061586 */
if(!s->budget--) { s->failed_pc=0x0c061586u; return 0; }
r[0]=0x00000000u;
goto P_0c061588;
P_0c061588: /* original 7f1c, guest PC 0x0c061588 */
if(!s->budget--) { s->failed_pc=0x0c061588u; return 0; }
r[15]+=0x0000001cu;
goto P_0c06158a;
P_0c06158a: /* original 4f26, guest PC 0x0c06158a */
if(!s->budget--) { s->failed_pc=0x0c06158au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06158c;
P_0c06158c: /* original 6bf6, guest PC 0x0c06158c */
if(!s->budget--) { s->failed_pc=0x0c06158cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06158e;
P_0c06158e: /* original 6cf6, guest PC 0x0c06158e */
if(!s->budget--) { s->failed_pc=0x0c06158eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c061590;
P_0c061590: /* original 6df6, guest PC 0x0c061590 */
if(!s->budget--) { s->failed_pc=0x0c061590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061592;
P_0c061592: /* original 000b, guest PC 0x0c061592 */
if(!s->budget--) { s->failed_pc=0x0c061592u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061594: /* original 6ef6, guest PC 0x0c061594 */
if(!s->budget--) { s->failed_pc=0x0c061594u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c061596u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061596u; return 0; } return 1;
P_0c061910: /* original 2fe6, guest PC 0x0c061910 */
if(!s->budget--) { s->failed_pc=0x0c061910u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061912;
P_0c061912: /* original ee00, guest PC 0x0c061912 */
if(!s->budget--) { s->failed_pc=0x0c061912u; return 0; }
r[14]=0x00000000u;
goto P_0c061914;
P_0c061914: /* original 2fd6, guest PC 0x0c061914 */
if(!s->budget--) { s->failed_pc=0x0c061914u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061916;
P_0c061916: /* original 2fc6, guest PC 0x0c061916 */
if(!s->budget--) { s->failed_pc=0x0c061916u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061918;
P_0c061918: /* original dc3c, guest PC 0x0c061918 */
if(!s->budget--) { s->failed_pc=0x0c061918u; return 0; }
r[12]=read(ram,0x0c061a0cu,4);
goto P_0c06191a;
P_0c06191a: /* original 7ffc, guest PC 0x0c06191a */
if(!s->budget--) { s->failed_pc=0x0c06191au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06191c;
P_0c06191c: /* original 56c2, guest PC 0x0c06191c */
if(!s->budget--) { s->failed_pc=0x0c06191cu; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c06191e;
P_0c06191e: /* original 2668, guest PC 0x0c06191e */
if(!s->budget--) { s->failed_pc=0x0c06191eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061920;
P_0c061920: /* original 8d07, guest PC 0x0c061920 */
if(!s->budget--) { s->failed_pc=0x0c061920u; return 0; }
cond=r[17]&1u;
r[7]=r[14];
if(cond) { goto P_0c061932; }
goto P_0c061924;
P_0c061922: /* original 67e3, guest PC 0x0c061922 */
if(!s->budget--) { s->failed_pc=0x0c061922u; return 0; }
r[7]=r[14];
goto P_0c061924;
P_0c061924: /* original 5264, guest PC 0x0c061924 */
if(!s->budget--) { s->failed_pc=0x0c061924u; return 0; }
r[2]=read(ram,r[6]+16,4);
goto P_0c061926;
P_0c061926: /* original 3277, guest PC 0x0c061926 */
if(!s->budget--) { s->failed_pc=0x0c061926u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[7])!=0);
goto P_0c061928;
P_0c061928: /* original 8b00, guest PC 0x0c061928 */
if(!s->budget--) { s->failed_pc=0x0c061928u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06192c; }
goto P_0c06192a;
P_0c06192a: /* original 5764, guest PC 0x0c06192a */
if(!s->budget--) { s->failed_pc=0x0c06192au; return 0; }
r[7]=read(ram,r[6]+16,4);
goto P_0c06192c;
P_0c06192c: /* original 5662, guest PC 0x0c06192c */
if(!s->budget--) { s->failed_pc=0x0c06192cu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c06192e;
P_0c06192e: /* original 2668, guest PC 0x0c06192e */
if(!s->budget--) { s->failed_pc=0x0c06192eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061930;
P_0c061930: /* original 8bf8, guest PC 0x0c061930 */
if(!s->budget--) { s->failed_pc=0x0c061930u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061924; }
goto P_0c061932;
P_0c061932: /* original 66c2, guest PC 0x0c061932 */
if(!s->budget--) { s->failed_pc=0x0c061932u; return 0; }
tmp=read(ram,r[12],4);
r[6]=tmp;
goto P_0c061934;
P_0c061934: /* original 2668, guest PC 0x0c061934 */
if(!s->budget--) { s->failed_pc=0x0c061934u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061936;
P_0c061936: /* original 8d0b, guest PC 0x0c061936 */
if(!s->budget--) { s->failed_pc=0x0c061936u; return 0; }
cond=r[17]&1u;
r[13]=0x00000004u;
if(cond) { goto P_0c061950; }
goto P_0c06193a;
P_0c061938: /* original ed04, guest PC 0x0c061938 */
if(!s->budget--) { s->failed_pc=0x0c061938u; return 0; }
r[13]=0x00000004u;
goto P_0c06193a;
P_0c06193a: /* original 6261, guest PC 0x0c06193a */
if(!s->budget--) { s->failed_pc=0x0c06193au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[2]=tmp;
goto P_0c06193c;
P_0c06193c: /* original 622d, guest PC 0x0c06193c */
if(!s->budget--) { s->failed_pc=0x0c06193cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c06193e;
P_0c06193e: /* original 22d8, guest PC 0x0c06193e */
if(!s->budget--) { s->failed_pc=0x0c06193eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c061940;
P_0c061940: /* original 8b03, guest PC 0x0c061940 */
if(!s->budget--) { s->failed_pc=0x0c061940u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06194a; }
goto P_0c061942;
P_0c061942: /* original 5164, guest PC 0x0c061942 */
if(!s->budget--) { s->failed_pc=0x0c061942u; return 0; }
r[1]=read(ram,r[6]+16,4);
goto P_0c061944;
P_0c061944: /* original 3177, guest PC 0x0c061944 */
if(!s->budget--) { s->failed_pc=0x0c061944u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[7])!=0);
goto P_0c061946;
P_0c061946: /* original 8b00, guest PC 0x0c061946 */
if(!s->budget--) { s->failed_pc=0x0c061946u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06194a; }
goto P_0c061948;
P_0c061948: /* original 5764, guest PC 0x0c061948 */
if(!s->budget--) { s->failed_pc=0x0c061948u; return 0; }
r[7]=read(ram,r[6]+16,4);
goto P_0c06194a;
P_0c06194a: /* original 5662, guest PC 0x0c06194a */
if(!s->budget--) { s->failed_pc=0x0c06194au; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c06194c;
P_0c06194c: /* original 2668, guest PC 0x0c06194c */
if(!s->budget--) { s->failed_pc=0x0c06194cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06194e;
P_0c06194e: /* original 8bf4, guest PC 0x0c06194e */
if(!s->budget--) { s->failed_pc=0x0c06194eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06193a; }
goto P_0c061950;
P_0c061950: /* original 66c3, guest PC 0x0c061950 */
if(!s->budget--) { s->failed_pc=0x0c061950u; return 0; }
r[6]=r[12];
goto P_0c061952;
P_0c061952: /* original 7614, guest PC 0x0c061952 */
if(!s->budget--) { s->failed_pc=0x0c061952u; return 0; }
r[6]+=0x00000014u;
goto P_0c061954;
P_0c061954: /* original 2f62, guest PC 0x0c061954 */
if(!s->budget--) { s->failed_pc=0x0c061954u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c061956;
P_0c061956: /* original 5662, guest PC 0x0c061956 */
if(!s->budget--) { s->failed_pc=0x0c061956u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c061958;
P_0c061958: /* original 2668, guest PC 0x0c061958 */
if(!s->budget--) { s->failed_pc=0x0c061958u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06195a;
P_0c06195a: /* original 8906, guest PC 0x0c06195a */
if(!s->budget--) { s->failed_pc=0x0c06195au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06196a; }
goto P_0c06195c;
P_0c06195c: /* original 5264, guest PC 0x0c06195c */
if(!s->budget--) { s->failed_pc=0x0c06195cu; return 0; }
r[2]=read(ram,r[6]+16,4);
goto P_0c06195e;
P_0c06195e: /* original 32e7, guest PC 0x0c06195e */
if(!s->budget--) { s->failed_pc=0x0c06195eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[14])!=0);
goto P_0c061960;
P_0c061960: /* original 8b00, guest PC 0x0c061960 */
if(!s->budget--) { s->failed_pc=0x0c061960u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061964; }
goto P_0c061962;
P_0c061962: /* original 5e64, guest PC 0x0c061962 */
if(!s->budget--) { s->failed_pc=0x0c061962u; return 0; }
r[14]=read(ram,r[6]+16,4);
goto P_0c061964;
P_0c061964: /* original 5662, guest PC 0x0c061964 */
if(!s->budget--) { s->failed_pc=0x0c061964u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c061966;
P_0c061966: /* original 2668, guest PC 0x0c061966 */
if(!s->budget--) { s->failed_pc=0x0c061966u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061968;
P_0c061968: /* original 8bf8, guest PC 0x0c061968 */
if(!s->budget--) { s->failed_pc=0x0c061968u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06195c; }
goto P_0c06196a;
P_0c06196a: /* original 66f2, guest PC 0x0c06196a */
if(!s->budget--) { s->failed_pc=0x0c06196au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c06196c;
P_0c06196c: /* original 6662, guest PC 0x0c06196c */
if(!s->budget--) { s->failed_pc=0x0c06196cu; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c06196e;
P_0c06196e: /* original 2668, guest PC 0x0c06196e */
if(!s->budget--) { s->failed_pc=0x0c06196eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061970;
P_0c061970: /* original 890a, guest PC 0x0c061970 */
if(!s->budget--) { s->failed_pc=0x0c061970u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061988; }
goto P_0c061972;
P_0c061972: /* original 6261, guest PC 0x0c061972 */
if(!s->budget--) { s->failed_pc=0x0c061972u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[2]=tmp;
goto P_0c061974;
P_0c061974: /* original 622d, guest PC 0x0c061974 */
if(!s->budget--) { s->failed_pc=0x0c061974u; return 0; }
r[2]=r[2]&65535u;
goto P_0c061976;
P_0c061976: /* original 22d8, guest PC 0x0c061976 */
if(!s->budget--) { s->failed_pc=0x0c061976u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c061978;
P_0c061978: /* original 8b03, guest PC 0x0c061978 */
if(!s->budget--) { s->failed_pc=0x0c061978u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061982; }
goto P_0c06197a;
P_0c06197a: /* original 5164, guest PC 0x0c06197a */
if(!s->budget--) { s->failed_pc=0x0c06197au; return 0; }
r[1]=read(ram,r[6]+16,4);
goto P_0c06197c;
P_0c06197c: /* original 31e7, guest PC 0x0c06197c */
if(!s->budget--) { s->failed_pc=0x0c06197cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[14])!=0);
goto P_0c06197e;
P_0c06197e: /* original 8b00, guest PC 0x0c06197e */
if(!s->budget--) { s->failed_pc=0x0c06197eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061982; }
goto P_0c061980;
P_0c061980: /* original 5e64, guest PC 0x0c061980 */
if(!s->budget--) { s->failed_pc=0x0c061980u; return 0; }
r[14]=read(ram,r[6]+16,4);
goto P_0c061982;
P_0c061982: /* original 5662, guest PC 0x0c061982 */
if(!s->budget--) { s->failed_pc=0x0c061982u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c061984;
P_0c061984: /* original 2668, guest PC 0x0c061984 */
if(!s->budget--) { s->failed_pc=0x0c061984u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061986;
P_0c061986: /* original 8bf4, guest PC 0x0c061986 */
if(!s->budget--) { s->failed_pc=0x0c061986u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061972; }
goto P_0c061988;
P_0c061988: /* original 2472, guest PC 0x0c061988 */
if(!s->budget--) { s->failed_pc=0x0c061988u; return 0; }
write(ram,r[4],r[7],4);
goto P_0c06198a;
P_0c06198a: /* original e000, guest PC 0x0c06198a */
if(!s->budget--) { s->failed_pc=0x0c06198au; return 0; }
r[0]=0x00000000u;
goto P_0c06198c;
P_0c06198c: /* original 25e2, guest PC 0x0c06198c */
if(!s->budget--) { s->failed_pc=0x0c06198cu; return 0; }
write(ram,r[5],r[14],4);
goto P_0c06198e;
P_0c06198e: /* original 7f04, guest PC 0x0c06198e */
if(!s->budget--) { s->failed_pc=0x0c06198eu; return 0; }
r[15]+=0x00000004u;
goto P_0c061990;
P_0c061990: /* original 6cf6, guest PC 0x0c061990 */
if(!s->budget--) { s->failed_pc=0x0c061990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c061992;
P_0c061992: /* original 6df6, guest PC 0x0c061992 */
if(!s->budget--) { s->failed_pc=0x0c061992u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061994;
P_0c061994: /* original 000b, guest PC 0x0c061994 */
if(!s->budget--) { s->failed_pc=0x0c061994u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061996: /* original 6ef6, guest PC 0x0c061996 */
if(!s->budget--) { s->failed_pc=0x0c061996u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c061998;
P_0c061998: /* original 2fe6, guest PC 0x0c061998 */
if(!s->budget--) { s->failed_pc=0x0c061998u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06199a;
P_0c06199a: /* original 2fd6, guest PC 0x0c06199a */
if(!s->budget--) { s->failed_pc=0x0c06199au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06199c;
P_0c06199c: /* original 4f22, guest PC 0x0c06199c */
if(!s->budget--) { s->failed_pc=0x0c06199cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06199e;
P_0c06199e: /* original de1b, guest PC 0x0c06199e */
if(!s->budget--) { s->failed_pc=0x0c06199eu; return 0; }
r[14]=read(ram,0x0c061a0cu,4);
goto P_0c0619a0;
P_0c0619a0: /* original 65e3, guest PC 0x0c0619a0 */
if(!s->budget--) { s->failed_pc=0x0c0619a0u; return 0; }
r[5]=r[14];
goto P_0c0619a2;
P_0c0619a2: /* original 7504, guest PC 0x0c0619a2 */
if(!s->budget--) { s->failed_pc=0x0c0619a2u; return 0; }
r[5]+=0x00000004u;
goto P_0c0619a4;
P_0c0619a4: /* original b62e, guest PC 0x0c0619a4 */
if(!s->budget--) { s->failed_pc=0x0c0619a4u; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619a8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619a8u) { target=s->pc; goto dispatch; }
goto P_0c0619a8;
P_0c0619a6: /* original 64e3, guest PC 0x0c0619a6 */
if(!s->budget--) { s->failed_pc=0x0c0619a6u; return 0; }
r[4]=r[14];
goto P_0c0619a8;
P_0c0619a8: /* original dd19, guest PC 0x0c0619a8 */
if(!s->budget--) { s->failed_pc=0x0c0619a8u; return 0; }
r[13]=read(ram,0x0c061a10u,4);
goto P_0c0619aa;
P_0c0619aa: /* original 65d3, guest PC 0x0c0619aa */
if(!s->budget--) { s->failed_pc=0x0c0619aau; return 0; }
r[5]=r[13];
goto P_0c0619ac;
P_0c0619ac: /* original 7504, guest PC 0x0c0619ac */
if(!s->budget--) { s->failed_pc=0x0c0619acu; return 0; }
r[5]+=0x00000004u;
goto P_0c0619ae;
P_0c0619ae: /* original b629, guest PC 0x0c0619ae */
if(!s->budget--) { s->failed_pc=0x0c0619aeu; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619b2u) { target=s->pc; goto dispatch; }
goto P_0c0619b2;
P_0c0619b0: /* original 64d3, guest PC 0x0c0619b0 */
if(!s->budget--) { s->failed_pc=0x0c0619b0u; return 0; }
r[4]=r[13];
goto P_0c0619b2;
P_0c0619b2: /* original 65e3, guest PC 0x0c0619b2 */
if(!s->budget--) { s->failed_pc=0x0c0619b2u; return 0; }
r[5]=r[14];
goto P_0c0619b4;
P_0c0619b4: /* original 750c, guest PC 0x0c0619b4 */
if(!s->budget--) { s->failed_pc=0x0c0619b4u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619b6;
P_0c0619b6: /* original 64e3, guest PC 0x0c0619b6 */
if(!s->budget--) { s->failed_pc=0x0c0619b6u; return 0; }
r[4]=r[14];
goto P_0c0619b8;
P_0c0619b8: /* original b624, guest PC 0x0c0619b8 */
if(!s->budget--) { s->failed_pc=0x0c0619b8u; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619bcu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619bcu) { target=s->pc; goto dispatch; }
goto P_0c0619bc;
P_0c0619ba: /* original 7408, guest PC 0x0c0619ba */
if(!s->budget--) { s->failed_pc=0x0c0619bau; return 0; }
r[4]+=0x00000008u;
goto P_0c0619bc;
P_0c0619bc: /* original 65d3, guest PC 0x0c0619bc */
if(!s->budget--) { s->failed_pc=0x0c0619bcu; return 0; }
r[5]=r[13];
goto P_0c0619be;
P_0c0619be: /* original 750c, guest PC 0x0c0619be */
if(!s->budget--) { s->failed_pc=0x0c0619beu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619c0;
P_0c0619c0: /* original 64d3, guest PC 0x0c0619c0 */
if(!s->budget--) { s->failed_pc=0x0c0619c0u; return 0; }
r[4]=r[13];
goto P_0c0619c2;
P_0c0619c2: /* original b61f, guest PC 0x0c0619c2 */
if(!s->budget--) { s->failed_pc=0x0c0619c2u; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619c6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619c6u) { target=s->pc; goto dispatch; }
goto P_0c0619c6;
P_0c0619c4: /* original 7408, guest PC 0x0c0619c4 */
if(!s->budget--) { s->failed_pc=0x0c0619c4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0619c6;
P_0c0619c6: /* original e000, guest PC 0x0c0619c6 */
if(!s->budget--) { s->failed_pc=0x0c0619c6u; return 0; }
r[0]=0x00000000u;
goto P_0c0619c8;
P_0c0619c8: /* original 4f26, guest PC 0x0c0619c8 */
if(!s->budget--) { s->failed_pc=0x0c0619c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0619ca;
P_0c0619ca: /* original 6df6, guest PC 0x0c0619ca */
if(!s->budget--) { s->failed_pc=0x0c0619cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0619cc;
P_0c0619cc: /* original 000b, guest PC 0x0c0619cc */
if(!s->budget--) { s->failed_pc=0x0c0619ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0619ce: /* original 6ef6, guest PC 0x0c0619ce */
if(!s->budget--) { s->failed_pc=0x0c0619ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0619d0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
