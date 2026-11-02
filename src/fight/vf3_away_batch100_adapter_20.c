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
int vf3_away_batch100_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b5f0u: goto P_0c07b5f0;
case 0x0c07b5f2u: goto P_0c07b5f2;
case 0x0c07b5f4u: goto P_0c07b5f4;
case 0x0c07b5f6u: goto P_0c07b5f6;
case 0x0c07b5f8u: goto P_0c07b5f8;
case 0x0c07b5fau: goto P_0c07b5fa;
case 0x0c07b5fcu: goto P_0c07b5fc;
case 0x0c07b5feu: goto P_0c07b5fe;
case 0x0c07b600u: goto P_0c07b600;
case 0x0c07b602u: goto P_0c07b602;
case 0x0c07b604u: goto P_0c07b604;
case 0x0c07b606u: goto P_0c07b606;
case 0x0c07b608u: goto P_0c07b608;
case 0x0c07b60au: goto P_0c07b60a;
case 0x0c07b60cu: goto P_0c07b60c;
case 0x0c07b60eu: goto P_0c07b60e;
case 0x0c07b610u: goto P_0c07b610;
case 0x0c07b612u: goto P_0c07b612;
case 0x0c07b614u: goto P_0c07b614;
case 0x0c07b616u: goto P_0c07b616;
case 0x0c07b618u: goto P_0c07b618;
case 0x0c07b61au: goto P_0c07b61a;
case 0x0c07b61cu: goto P_0c07b61c;
case 0x0c07b61eu: goto P_0c07b61e;
case 0x0c07b620u: goto P_0c07b620;
case 0x0c07b622u: goto P_0c07b622;
case 0x0c07b624u: goto P_0c07b624;
case 0x0c07b626u: goto P_0c07b626;
case 0x0c07b628u: goto P_0c07b628;
case 0x0c07b62au: goto P_0c07b62a;
case 0x0c07b62cu: goto P_0c07b62c;
case 0x0c07b62eu: goto P_0c07b62e;
case 0x0c07b630u: goto P_0c07b630;
case 0x0c07b632u: goto P_0c07b632;
case 0x0c07b634u: goto P_0c07b634;
case 0x0c07b636u: goto P_0c07b636;
case 0x0c07b638u: goto P_0c07b638;
case 0x0c07b63au: goto P_0c07b63a;
case 0x0c07b63cu: goto P_0c07b63c;
case 0x0c07b63eu: goto P_0c07b63e;
case 0x0c07b640u: goto P_0c07b640;
case 0x0c07b642u: goto P_0c07b642;
case 0x0c07b644u: goto P_0c07b644;
case 0x0c07b646u: goto P_0c07b646;
case 0x0c07b648u: goto P_0c07b648;
case 0x0c07b64au: goto P_0c07b64a;
case 0x0c07b64cu: goto P_0c07b64c;
case 0x0c07b64eu: goto P_0c07b64e;
case 0x0c07b650u: goto P_0c07b650;
case 0x0c07b652u: goto P_0c07b652;
case 0x0c07b654u: goto P_0c07b654;
case 0x0c07b656u: goto P_0c07b656;
case 0x0c07b658u: goto P_0c07b658;
case 0x0c07b65au: goto P_0c07b65a;
case 0x0c07b65cu: goto P_0c07b65c;
case 0x0c07b65eu: goto P_0c07b65e;
case 0x0c07b660u: goto P_0c07b660;
case 0x0c07b662u: goto P_0c07b662;
case 0x0c07b664u: goto P_0c07b664;
case 0x0c07b666u: goto P_0c07b666;
case 0x0c07b668u: goto P_0c07b668;
case 0x0c07b66au: goto P_0c07b66a;
case 0x0c07b66cu: goto P_0c07b66c;
case 0x0c08b430u: goto P_0c08b430;
case 0x0c08b432u: goto P_0c08b432;
case 0x0c08b434u: goto P_0c08b434;
case 0x0c08b436u: goto P_0c08b436;
case 0x0c08b438u: goto P_0c08b438;
case 0x0c08b43au: goto P_0c08b43a;
case 0x0c08b43cu: goto P_0c08b43c;
case 0x0c08b43eu: goto P_0c08b43e;
case 0x0c08b440u: goto P_0c08b440;
case 0x0c08b442u: goto P_0c08b442;
case 0x0c08b444u: goto P_0c08b444;
case 0x0c08b446u: goto P_0c08b446;
case 0x0c08b448u: goto P_0c08b448;
case 0x0c08b44au: goto P_0c08b44a;
case 0x0c08b44cu: goto P_0c08b44c;
case 0x0c08b44eu: goto P_0c08b44e;
case 0x0c08b450u: goto P_0c08b450;
case 0x0c08b452u: goto P_0c08b452;
case 0x0c08b454u: goto P_0c08b454;
case 0x0c08b456u: goto P_0c08b456;
case 0x0c08b458u: goto P_0c08b458;
case 0x0c08b45au: goto P_0c08b45a;
case 0x0c08b45cu: goto P_0c08b45c;
case 0x0c08b45eu: goto P_0c08b45e;
case 0x0c08b460u: goto P_0c08b460;
case 0x0c08b462u: goto P_0c08b462;
case 0x0c08b464u: goto P_0c08b464;
case 0x0c08b466u: goto P_0c08b466;
case 0x0c08b468u: goto P_0c08b468;
case 0x0c08b46au: goto P_0c08b46a;
case 0x0c08b46cu: goto P_0c08b46c;
case 0x0c08b46eu: goto P_0c08b46e;
case 0x0c08b470u: goto P_0c08b470;
case 0x0c08b472u: goto P_0c08b472;
case 0x0c08b474u: goto P_0c08b474;
case 0x0c08b476u: goto P_0c08b476;
case 0x0c08b478u: goto P_0c08b478;
case 0x0c08b47au: goto P_0c08b47a;
case 0x0c08b47cu: goto P_0c08b47c;
case 0x0c08b47eu: goto P_0c08b47e;
case 0x0c08b480u: goto P_0c08b480;
case 0x0c08b482u: goto P_0c08b482;
case 0x0c08b484u: goto P_0c08b484;
case 0x0c08b486u: goto P_0c08b486;
case 0x0c08b488u: goto P_0c08b488;
case 0x0c08b48au: goto P_0c08b48a;
case 0x0c08b48cu: goto P_0c08b48c;
case 0x0c08b48eu: goto P_0c08b48e;
case 0x0c08b490u: goto P_0c08b490;
case 0x0c08b492u: goto P_0c08b492;
case 0x0c08b494u: goto P_0c08b494;
case 0x0c08b496u: goto P_0c08b496;
case 0x0c08b498u: goto P_0c08b498;
case 0x0c08b49au: goto P_0c08b49a;
case 0x0c08b49cu: goto P_0c08b49c;
case 0x0c08b49eu: goto P_0c08b49e;
case 0x0c08b4a0u: goto P_0c08b4a0;
case 0x0c08b4a2u: goto P_0c08b4a2;
case 0x0c08b4a4u: goto P_0c08b4a4;
case 0x0c08b4a6u: goto P_0c08b4a6;
case 0x0c08b4a8u: goto P_0c08b4a8;
case 0x0c08b4aau: goto P_0c08b4aa;
case 0x0c08b4acu: goto P_0c08b4ac;
case 0x0c08b4aeu: goto P_0c08b4ae;
case 0x0c08b4b0u: goto P_0c08b4b0;
case 0x0c08b4b2u: goto P_0c08b4b2;
case 0x0c08b4b4u: goto P_0c08b4b4;
case 0x0c08b4b6u: goto P_0c08b4b6;
case 0x0c08b4b8u: goto P_0c08b4b8;
case 0x0c08b4bau: goto P_0c08b4ba;
case 0x0c08b4bcu: goto P_0c08b4bc;
case 0x0c08b4beu: goto P_0c08b4be;
case 0x0c08b4c0u: goto P_0c08b4c0;
case 0x0c08b4c2u: goto P_0c08b4c2;
case 0x0c08b4c4u: goto P_0c08b4c4;
case 0x0c08b4c6u: goto P_0c08b4c6;
case 0x0c08b4c8u: goto P_0c08b4c8;
case 0x0c08b4cau: goto P_0c08b4ca;
case 0x0c08b4ccu: goto P_0c08b4cc;
case 0x0c08b4ceu: goto P_0c08b4ce;
case 0x0c08b4d0u: goto P_0c08b4d0;
case 0x0c08b4d2u: goto P_0c08b4d2;
case 0x0c08b4d4u: goto P_0c08b4d4;
case 0x0c08b4d6u: goto P_0c08b4d6;
case 0x0c08b4d8u: goto P_0c08b4d8;
case 0x0c08b4dau: goto P_0c08b4da;
case 0x0c08b4dcu: goto P_0c08b4dc;
case 0x0c08b4deu: goto P_0c08b4de;
case 0x0c08b4e0u: goto P_0c08b4e0;
case 0x0c08b4e2u: goto P_0c08b4e2;
case 0x0c08b4e4u: goto P_0c08b4e4;
case 0x0c08b4e6u: goto P_0c08b4e6;
case 0x0c08b4e8u: goto P_0c08b4e8;
case 0x0c08b4eau: goto P_0c08b4ea;
case 0x0c08b4ecu: goto P_0c08b4ec;
case 0x0c08b4eeu: goto P_0c08b4ee;
case 0x0c08b4f0u: goto P_0c08b4f0;
case 0x0c08b4f2u: goto P_0c08b4f2;
case 0x0c08b4f4u: goto P_0c08b4f4;
case 0x0c08b4f6u: goto P_0c08b4f6;
case 0x0c08b4f8u: goto P_0c08b4f8;
case 0x0c08b544u: goto P_0c08b544;
case 0x0c08b546u: goto P_0c08b546;
case 0x0c08b548u: goto P_0c08b548;
case 0x0c08b54au: goto P_0c08b54a;
case 0x0c08b54cu: goto P_0c08b54c;
case 0x0c08b54eu: goto P_0c08b54e;
case 0x0c08b550u: goto P_0c08b550;
case 0x0c08b552u: goto P_0c08b552;
case 0x0c08b554u: goto P_0c08b554;
case 0x0c08b556u: goto P_0c08b556;
case 0x0c08b558u: goto P_0c08b558;
case 0x0c08b55au: goto P_0c08b55a;
case 0x0c08b55cu: goto P_0c08b55c;
case 0x0c08b55eu: goto P_0c08b55e;
case 0x0c08b560u: goto P_0c08b560;
case 0x0c08b562u: goto P_0c08b562;
case 0x0c08b564u: goto P_0c08b564;
case 0x0c08b566u: goto P_0c08b566;
case 0x0c08b568u: goto P_0c08b568;
case 0x0c08b56au: goto P_0c08b56a;
case 0x0c08b56cu: goto P_0c08b56c;
case 0x0c08b56eu: goto P_0c08b56e;
case 0x0c08b570u: goto P_0c08b570;
case 0x0c08b572u: goto P_0c08b572;
case 0x0c08b574u: goto P_0c08b574;
case 0x0c08b576u: goto P_0c08b576;
case 0x0c08b578u: goto P_0c08b578;
case 0x0c08b57au: goto P_0c08b57a;
case 0x0c08b57cu: goto P_0c08b57c;
case 0x0c0955b0u: goto P_0c0955b0;
case 0x0c0955b2u: goto P_0c0955b2;
case 0x0c0955b4u: goto P_0c0955b4;
case 0x0c0955b6u: goto P_0c0955b6;
case 0x0c0955b8u: goto P_0c0955b8;
case 0x0c0955bau: goto P_0c0955ba;
case 0x0c0955bcu: goto P_0c0955bc;
case 0x0c0955beu: goto P_0c0955be;
case 0x0c0955c0u: goto P_0c0955c0;
case 0x0c0955c2u: goto P_0c0955c2;
case 0x0c0955c4u: goto P_0c0955c4;
case 0x0c0955c6u: goto P_0c0955c6;
case 0x0c0955c8u: goto P_0c0955c8;
case 0x0c0955cau: goto P_0c0955ca;
case 0x0c0955ccu: goto P_0c0955cc;
case 0x0c0955ceu: goto P_0c0955ce;
case 0x0c0955d0u: goto P_0c0955d0;
case 0x0c0955d2u: goto P_0c0955d2;
case 0x0c0955d4u: goto P_0c0955d4;
case 0x0c0955d6u: goto P_0c0955d6;
case 0x0c0955d8u: goto P_0c0955d8;
case 0x0c0955dau: goto P_0c0955da;
case 0x0c0955dcu: goto P_0c0955dc;
case 0x0c0955deu: goto P_0c0955de;
case 0x0c0955e0u: goto P_0c0955e0;
case 0x0c0955e2u: goto P_0c0955e2;
case 0x0c0955e4u: goto P_0c0955e4;
case 0x0c0955e6u: goto P_0c0955e6;
case 0x0c0955e8u: goto P_0c0955e8;
case 0x0c0955eau: goto P_0c0955ea;
case 0x0c0955ecu: goto P_0c0955ec;
case 0x0c0955eeu: goto P_0c0955ee;
case 0x0c0955f0u: goto P_0c0955f0;
case 0x0c0955f2u: goto P_0c0955f2;
case 0x0c0955f4u: goto P_0c0955f4;
case 0x0c0955f6u: goto P_0c0955f6;
case 0x0c0955f8u: goto P_0c0955f8;
case 0x0c0955fau: goto P_0c0955fa;
case 0x0c0955fcu: goto P_0c0955fc;
case 0x0c0955feu: goto P_0c0955fe;
case 0x0c095600u: goto P_0c095600;
case 0x0c095602u: goto P_0c095602;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c096864u: goto P_0c096864;
case 0x0c096866u: goto P_0c096866;
case 0x0c096868u: goto P_0c096868;
case 0x0c09686au: goto P_0c09686a;
case 0x0c09686cu: goto P_0c09686c;
case 0x0c09686eu: goto P_0c09686e;
case 0x0c096870u: goto P_0c096870;
case 0x0c096872u: goto P_0c096872;
case 0x0c096874u: goto P_0c096874;
case 0x0c096876u: goto P_0c096876;
case 0x0c096878u: goto P_0c096878;
case 0x0c09687au: goto P_0c09687a;
case 0x0c09687cu: goto P_0c09687c;
case 0x0c09687eu: goto P_0c09687e;
case 0x0c096880u: goto P_0c096880;
case 0x0c096882u: goto P_0c096882;
case 0x0c096884u: goto P_0c096884;
case 0x0c096886u: goto P_0c096886;
case 0x0c096888u: goto P_0c096888;
case 0x0c09688au: goto P_0c09688a;
case 0x0c09688cu: goto P_0c09688c;
case 0x0c09688eu: goto P_0c09688e;
case 0x0c096890u: goto P_0c096890;
case 0x0c096892u: goto P_0c096892;
case 0x0c096894u: goto P_0c096894;
case 0x0c096896u: goto P_0c096896;
case 0x0c096898u: goto P_0c096898;
case 0x0c09689au: goto P_0c09689a;
case 0x0c09689cu: goto P_0c09689c;
case 0x0c09689eu: goto P_0c09689e;
case 0x0c0968a0u: goto P_0c0968a0;
case 0x0c0968a2u: goto P_0c0968a2;
case 0x0c0968a4u: goto P_0c0968a4;
case 0x0c0968a6u: goto P_0c0968a6;
case 0x0c0968a8u: goto P_0c0968a8;
case 0x0c0968aau: goto P_0c0968aa;
case 0x0c0968acu: goto P_0c0968ac;
case 0x0c0968aeu: goto P_0c0968ae;
case 0x0c0a13a4u: goto P_0c0a13a4;
case 0x0c0a13a6u: goto P_0c0a13a6;
case 0x0c0a13a8u: goto P_0c0a13a8;
case 0x0c0a13aau: goto P_0c0a13aa;
case 0x0c0a13acu: goto P_0c0a13ac;
case 0x0c0a13aeu: goto P_0c0a13ae;
case 0x0c0a13b0u: goto P_0c0a13b0;
case 0x0c0a13b2u: goto P_0c0a13b2;
case 0x0c0a13b4u: goto P_0c0a13b4;
case 0x0c0a13b6u: goto P_0c0a13b6;
case 0x0c0a13b8u: goto P_0c0a13b8;
case 0x0c0a13bau: goto P_0c0a13ba;
case 0x0c0a13bcu: goto P_0c0a13bc;
case 0x0c0a13beu: goto P_0c0a13be;
case 0x0c0a13c0u: goto P_0c0a13c0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b5f0: /* original 2fe6, guest PC 0x0c07b5f0 */
if(!s->budget--) { s->failed_pc=0x0c07b5f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f2;
P_0c07b5f2: /* original 2fd6, guest PC 0x0c07b5f2 */
if(!s->budget--) { s->failed_pc=0x0c07b5f2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f4;
P_0c07b5f4: /* original 6d43, guest PC 0x0c07b5f4 */
if(!s->budget--) { s->failed_pc=0x0c07b5f4u; return 0; }
r[13]=r[4];
goto P_0c07b5f6;
P_0c07b5f6: /* original 2fc6, guest PC 0x0c07b5f6 */
if(!s->budget--) { s->failed_pc=0x0c07b5f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f8;
P_0c07b5f8: /* original 4f22, guest PC 0x0c07b5f8 */
if(!s->budget--) { s->failed_pc=0x0c07b5f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b5fa;
P_0c07b5fa: /* original d22a, guest PC 0x0c07b5fa */
if(!s->budget--) { s->failed_pc=0x0c07b5fau; return 0; }
r[2]=read(ram,0x0c07b6a4u,4);
goto P_0c07b5fc;
P_0c07b5fc: /* original d32a, guest PC 0x0c07b5fc */
if(!s->budget--) { s->failed_pc=0x0c07b5fcu; return 0; }
r[3]=read(ram,0x0c07b6a8u,4);
goto P_0c07b5fe;
P_0c07b5fe: /* original 7fe0, guest PC 0x0c07b5fe */
if(!s->budget--) { s->failed_pc=0x0c07b5feu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07b600;
P_0c07b600: /* original 61f3, guest PC 0x0c07b600 */
if(!s->budget--) { s->failed_pc=0x0c07b600u; return 0; }
r[1]=r[15];
goto P_0c07b602;
P_0c07b602: /* original 430b, guest PC 0x0c07b602 */
if(!s->budget--) { s->failed_pc=0x0c07b602u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b606u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b606u) { target=s->pc; goto dispatch; }
goto P_0c07b606;
P_0c07b604: /* original e020, guest PC 0x0c07b604 */
if(!s->budget--) { s->failed_pc=0x0c07b604u; return 0; }
r[0]=0x00000020u;
goto P_0c07b606;
P_0c07b606: /* original 9149, guest PC 0x0c07b606 */
if(!s->budget--) { s->failed_pc=0x0c07b606u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69cu,2);
goto P_0c07b608;
P_0c07b608: /* original 6edd, guest PC 0x0c07b608 */
if(!s->budget--) { s->failed_pc=0x0c07b608u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b60a;
P_0c07b60a: /* original 21e8, guest PC 0x0c07b60a */
if(!s->budget--) { s->failed_pc=0x0c07b60au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c07b60c;
P_0c07b60c: /* original 8b29, guest PC 0x0c07b60c */
if(!s->budget--) { s->failed_pc=0x0c07b60cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b60e;
P_0c07b60e: /* original d227, guest PC 0x0c07b60e */
if(!s->budget--) { s->failed_pc=0x0c07b60eu; return 0; }
r[2]=read(ram,0x0c07b6acu,4);
goto P_0c07b610;
P_0c07b610: /* original 22e8, guest PC 0x0c07b610 */
if(!s->budget--) { s->failed_pc=0x0c07b610u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c07b612;
P_0c07b612: /* original 8b26, guest PC 0x0c07b612 */
if(!s->budget--) { s->failed_pc=0x0c07b612u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b614;
P_0c07b614: /* original 60e3, guest PC 0x0c07b614 */
if(!s->budget--) { s->failed_pc=0x0c07b614u; return 0; }
r[0]=r[14];
goto P_0c07b616;
P_0c07b616: /* original dc26, guest PC 0x0c07b616 */
if(!s->budget--) { s->failed_pc=0x0c07b616u; return 0; }
r[12]=read(ram,0x0c07b6b0u,4);
goto P_0c07b618;
P_0c07b618: /* original 8807, guest PC 0x0c07b618 */
if(!s->budget--) { s->failed_pc=0x0c07b618u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c07b61a;
P_0c07b61a: /* original 8b02, guest PC 0x0c07b61a */
if(!s->budget--) { s->failed_pc=0x0c07b61au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b622; }
goto P_0c07b61c;
P_0c07b61c: /* original 953f, guest PC 0x0c07b61c */
if(!s->budget--) { s->failed_pc=0x0c07b61cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b61e;
P_0c07b61e: /* original 4c0b, guest PC 0x0c07b61e */
if(!s->budget--) { s->failed_pc=0x0c07b61eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07b622u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b622u) { target=s->pc; goto dispatch; }
goto P_0c07b622;
P_0c07b620: /* original e401, guest PC 0x0c07b620 */
if(!s->budget--) { s->failed_pc=0x0c07b620u; return 0; }
r[4]=0x00000001u;
goto P_0c07b622;
P_0c07b622: /* original 60e3, guest PC 0x0c07b622 */
if(!s->budget--) { s->failed_pc=0x0c07b622u; return 0; }
r[0]=r[14];
goto P_0c07b624;
P_0c07b624: /* original 8805, guest PC 0x0c07b624 */
if(!s->budget--) { s->failed_pc=0x0c07b624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07b626;
P_0c07b626: /* original 8b02, guest PC 0x0c07b626 */
if(!s->budget--) { s->failed_pc=0x0c07b626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b62e; }
goto P_0c07b628;
P_0c07b628: /* original 953a, guest PC 0x0c07b628 */
if(!s->budget--) { s->failed_pc=0x0c07b628u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b6a0u,2);
goto P_0c07b62a;
P_0c07b62a: /* original 4c0b, guest PC 0x0c07b62a */
if(!s->budget--) { s->failed_pc=0x0c07b62au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b62eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b62eu) { target=s->pc; goto dispatch; }
goto P_0c07b62e;
P_0c07b62c: /* original e401, guest PC 0x0c07b62c */
if(!s->budget--) { s->failed_pc=0x0c07b62cu; return 0; }
r[4]=0x00000001u;
goto P_0c07b62e;
P_0c07b62e: /* original d021, guest PC 0x0c07b62e */
if(!s->budget--) { s->failed_pc=0x0c07b62eu; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b630;
P_0c07b630: /* original 64dd, guest PC 0x0c07b630 */
if(!s->budget--) { s->failed_pc=0x0c07b630u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b632;
P_0c07b632: /* original 4400, guest PC 0x0c07b632 */
if(!s->budget--) { s->failed_pc=0x0c07b632u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b634;
P_0c07b634: /* original 044d, guest PC 0x0c07b634 */
if(!s->budget--) { s->failed_pc=0x0c07b634u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07b636;
P_0c07b636: /* original 644d, guest PC 0x0c07b636 */
if(!s->budget--) { s->failed_pc=0x0c07b636u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b638;
P_0c07b638: /* original 2448, guest PC 0x0c07b638 */
if(!s->budget--) { s->failed_pc=0x0c07b638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b63a;
P_0c07b63a: /* original 8912, guest PC 0x0c07b63a */
if(!s->budget--) { s->failed_pc=0x0c07b63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b63c;
P_0c07b63c: /* original d21e, guest PC 0x0c07b63c */
if(!s->budget--) { s->failed_pc=0x0c07b63cu; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b63e;
P_0c07b63e: /* original 3420, guest PC 0x0c07b63e */
if(!s->budget--) { s->failed_pc=0x0c07b63eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07b640;
P_0c07b640: /* original 890f, guest PC 0x0c07b640 */
if(!s->budget--) { s->failed_pc=0x0c07b640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b642;
P_0c07b642: /* original d21e, guest PC 0x0c07b642 */
if(!s->budget--) { s->failed_pc=0x0c07b642u; return 0; }
r[2]=read(ram,0x0c07b6bcu,4);
goto P_0c07b644;
P_0c07b644: /* original 420b, guest PC 0x0c07b644 */
if(!s->budget--) { s->failed_pc=0x0c07b644u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b648u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b648u) { target=s->pc; goto dispatch; }
goto P_0c07b648;
P_0c07b646: /* original 0009, guest PC 0x0c07b646 */
if(!s->budget--) { s->failed_pc=0x0c07b646u; return 0; }
goto P_0c07b648;
P_0c07b648: /* original d31d, guest PC 0x0c07b648 */
if(!s->budget--) { s->failed_pc=0x0c07b648u; return 0; }
r[3]=read(ram,0x0c07b6c0u,4);
goto P_0c07b64a;
P_0c07b64a: /* original 430b, guest PC 0x0c07b64a */
if(!s->budget--) { s->failed_pc=0x0c07b64au; return 0; }
target=r[3];
r[16]=code_base|0x0c07b64eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b64eu) { target=s->pc; goto dispatch; }
goto P_0c07b64e;
P_0c07b64c: /* original 64f3, guest PC 0x0c07b64c */
if(!s->budget--) { s->failed_pc=0x0c07b64cu; return 0; }
r[4]=r[15];
goto P_0c07b64e;
P_0c07b64e: /* original 2008, guest PC 0x0c07b64e */
if(!s->budget--) { s->failed_pc=0x0c07b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b650;
P_0c07b650: /* original 8902, guest PC 0x0c07b650 */
if(!s->budget--) { s->failed_pc=0x0c07b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b658; }
goto P_0c07b652;
P_0c07b652: /* original 9524, guest PC 0x0c07b652 */
if(!s->budget--) { s->failed_pc=0x0c07b652u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b654;
P_0c07b654: /* original 4c0b, guest PC 0x0c07b654 */
if(!s->budget--) { s->failed_pc=0x0c07b654u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b658u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b658u) { target=s->pc; goto dispatch; }
goto P_0c07b658;
P_0c07b656: /* original e401, guest PC 0x0c07b656 */
if(!s->budget--) { s->failed_pc=0x0c07b656u; return 0; }
r[4]=0x00000001u;
goto P_0c07b658;
P_0c07b658: /* original d016, guest PC 0x0c07b658 */
if(!s->budget--) { s->failed_pc=0x0c07b658u; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b65a;
P_0c07b65a: /* original 6ddd, guest PC 0x0c07b65a */
if(!s->budget--) { s->failed_pc=0x0c07b65au; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b65c;
P_0c07b65c: /* original e300, guest PC 0x0c07b65c */
if(!s->budget--) { s->failed_pc=0x0c07b65cu; return 0; }
r[3]=0x00000000u;
goto P_0c07b65e;
P_0c07b65e: /* original 4d00, guest PC 0x0c07b65e */
if(!s->budget--) { s->failed_pc=0x0c07b65eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b660;
P_0c07b660: /* original 0d35, guest PC 0x0c07b660 */
if(!s->budget--) { s->failed_pc=0x0c07b660u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b662;
P_0c07b662: /* original 7f20, guest PC 0x0c07b662 */
if(!s->budget--) { s->failed_pc=0x0c07b662u; return 0; }
r[15]+=0x00000020u;
goto P_0c07b664;
P_0c07b664: /* original 4f26, guest PC 0x0c07b664 */
if(!s->budget--) { s->failed_pc=0x0c07b664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b666;
P_0c07b666: /* original 6cf6, guest PC 0x0c07b666 */
if(!s->budget--) { s->failed_pc=0x0c07b666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b668;
P_0c07b668: /* original 6df6, guest PC 0x0c07b668 */
if(!s->budget--) { s->failed_pc=0x0c07b668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b66a;
P_0c07b66a: /* original 000b, guest PC 0x0c07b66a */
if(!s->budget--) { s->failed_pc=0x0c07b66au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b66c: /* original 6ef6, guest PC 0x0c07b66c */
if(!s->budget--) { s->failed_pc=0x0c07b66cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b66eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b66eu; return 0; } return 1;
P_0c08b430: /* original 2fe6, guest PC 0x0c08b430 */
if(!s->budget--) { s->failed_pc=0x0c08b430u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b432;
P_0c08b432: /* original 6e73, guest PC 0x0c08b432 */
if(!s->budget--) { s->failed_pc=0x0c08b432u; return 0; }
r[14]=r[7];
goto P_0c08b434;
P_0c08b434: /* original 2fd6, guest PC 0x0c08b434 */
if(!s->budget--) { s->failed_pc=0x0c08b434u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b436;
P_0c08b436: /* original 2fc6, guest PC 0x0c08b436 */
if(!s->budget--) { s->failed_pc=0x0c08b436u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b438;
P_0c08b438: /* original 6c53, guest PC 0x0c08b438 */
if(!s->budget--) { s->failed_pc=0x0c08b438u; return 0; }
r[12]=r[5];
goto P_0c08b43a;
P_0c08b43a: /* original 2fb6, guest PC 0x0c08b43a */
if(!s->budget--) { s->failed_pc=0x0c08b43au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b43c;
P_0c08b43c: /* original 2fa6, guest PC 0x0c08b43c */
if(!s->budget--) { s->failed_pc=0x0c08b43cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b43e;
P_0c08b43e: /* original 2f96, guest PC 0x0c08b43e */
if(!s->budget--) { s->failed_pc=0x0c08b43eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b440;
P_0c08b440: /* original 6943, guest PC 0x0c08b440 */
if(!s->budget--) { s->failed_pc=0x0c08b440u; return 0; }
r[9]=r[4];
goto P_0c08b442;
P_0c08b442: /* original 2f86, guest PC 0x0c08b442 */
if(!s->budget--) { s->failed_pc=0x0c08b442u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b444;
P_0c08b444: /* original 7964, guest PC 0x0c08b444 */
if(!s->budget--) { s->failed_pc=0x0c08b444u; return 0; }
r[9]+=0x00000064u;
goto P_0c08b446;
P_0c08b446: /* original fffb, guest PC 0x0c08b446 */
if(!s->budget--) { s->failed_pc=0x0c08b446u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08b448;
P_0c08b448: /* original 4f22, guest PC 0x0c08b448 */
if(!s->budget--) { s->failed_pc=0x0c08b448u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b44a;
P_0c08b44a: /* original 4f12, guest PC 0x0c08b44a */
if(!s->budget--) { s->failed_pc=0x0c08b44au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c08b44c;
P_0c08b44c: /* original 7ff8, guest PC 0x0c08b44c */
if(!s->budget--) { s->failed_pc=0x0c08b44cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08b44e;
P_0c08b44e: /* original 1f61, guest PC 0x0c08b44e */
if(!s->budget--) { s->failed_pc=0x0c08b44eu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c08b450;
P_0c08b450: /* original 2f72, guest PC 0x0c08b450 */
if(!s->budget--) { s->failed_pc=0x0c08b450u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c08b452;
P_0c08b452: /* original d22d, guest PC 0x0c08b452 */
if(!s->budget--) { s->failed_pc=0x0c08b452u; return 0; }
r[2]=read(ram,0x0c08b508u,4);
goto P_0c08b454;
P_0c08b454: /* original 9353, guest PC 0x0c08b454 */
if(!s->budget--) { s->failed_pc=0x0c08b454u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4feu,2);
goto P_0c08b456;
P_0c08b456: /* original 6822, guest PC 0x0c08b456 */
if(!s->budget--) { s->failed_pc=0x0c08b456u; return 0; }
tmp=read(ram,r[2],4);
r[8]=tmp;
goto P_0c08b458;
P_0c08b458: /* original 9d50, guest PC 0x0c08b458 */
if(!s->budget--) { s->failed_pc=0x0c08b458u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4fcu,2);
goto P_0c08b45a;
P_0c08b45a: /* original 2838, guest PC 0x0c08b45a */
if(!s->budget--) { s->failed_pc=0x0c08b45au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c08b45c;
P_0c08b45c: /* original 3d4c, guest PC 0x0c08b45c */
if(!s->budget--) { s->failed_pc=0x0c08b45cu; return 0; }
r[13]+=r[4];
goto P_0c08b45e;
P_0c08b45e: /* original 8d05, guest PC 0x0c08b45e */
if(!s->budget--) { s->failed_pc=0x0c08b45eu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
if(cond) { goto P_0c08b46c; }
goto P_0c08b462;
P_0c08b460: /* original 6ee0, guest PC 0x0c08b460 */
if(!s->budget--) { s->failed_pc=0x0c08b460u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b462;
P_0c08b462: /* original 60c3, guest PC 0x0c08b462 */
if(!s->budget--) { s->failed_pc=0x0c08b462u; return 0; }
r[0]=r[12];
goto P_0c08b464;
P_0c08b464: /* original 8810, guest PC 0x0c08b464 */
if(!s->budget--) { s->failed_pc=0x0c08b464u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b466;
P_0c08b466: /* original 8b01, guest PC 0x0c08b466 */
if(!s->budget--) { s->failed_pc=0x0c08b466u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b46c; }
goto P_0c08b468;
P_0c08b468: /* original a001, guest PC 0x0c08b468 */
if(!s->budget--) { s->failed_pc=0x0c08b468u; return 0; }
r[8]=0x00000001u;
goto P_0c08b46e;
P_0c08b46a: /* original e801, guest PC 0x0c08b46a */
if(!s->budget--) { s->failed_pc=0x0c08b46au; return 0; }
r[8]=0x00000001u;
goto P_0c08b46c;
P_0c08b46c: /* original e800, guest PC 0x0c08b46c */
if(!s->budget--) { s->failed_pc=0x0c08b46cu; return 0; }
r[8]=0x00000000u;
goto P_0c08b46e;
P_0c08b46e: /* original da27, guest PC 0x0c08b46e */
if(!s->budget--) { s->failed_pc=0x0c08b46eu; return 0; }
r[10]=read(ram,0x0c08b50cu,4);
goto P_0c08b470;
P_0c08b470: /* original c727, guest PC 0x0c08b470 */
if(!s->budget--) { s->failed_pc=0x0c08b470u; return 0; }
r[0]=code_base|0x0008b510u;
goto P_0c08b472;
P_0c08b472: /* original a024, guest PC 0x0c08b472 */
if(!s->budget--) { s->failed_pc=0x0c08b472u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b4be;
P_0c08b474: /* original ff08, guest PC 0x0c08b474 */
if(!s->budget--) { s->failed_pc=0x0c08b474u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b476;
P_0c08b476: /* original 2888, guest PC 0x0c08b476 */
if(!s->budget--) { s->failed_pc=0x0c08b476u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c08b478;
P_0c08b478: /* original 8905, guest PC 0x0c08b478 */
if(!s->budget--) { s->failed_pc=0x0c08b478u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b486; }
goto P_0c08b47a;
P_0c08b47a: /* original d326, guest PC 0x0c08b47a */
if(!s->budget--) { s->failed_pc=0x0c08b47au; return 0; }
r[3]=read(ram,0x0c08b514u,4);
goto P_0c08b47c;
P_0c08b47c: /* original 430b, guest PC 0x0c08b47c */
if(!s->budget--) { s->failed_pc=0x0c08b47cu; return 0; }
target=r[3];
r[16]=code_base|0x0c08b480u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b480u) { target=s->pc; goto dispatch; }
goto P_0c08b480;
P_0c08b47e: /* original 0009, guest PC 0x0c08b47e */
if(!s->budget--) { s->failed_pc=0x0c08b47eu; return 0; }
goto P_0c08b480;
P_0c08b480: /* original f40c, guest PC 0x0c08b480 */
if(!s->budget--) { s->failed_pc=0x0c08b480u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08b482;
P_0c08b482: /* original f4f5, guest PC 0x0c08b482 */
if(!s->budget--) { s->failed_pc=0x0c08b482u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c08b484;
P_0c08b484: /* original 891e, guest PC 0x0c08b484 */
if(!s->budget--) { s->failed_pc=0x0c08b484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4c4; }
goto P_0c08b486;
P_0c08b486: /* original 60ee, guest PC 0x0c08b486 */
if(!s->budget--) { s->failed_pc=0x0c08b486u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b488;
P_0c08b488: /* original 7eff, guest PC 0x0c08b488 */
if(!s->budget--) { s->failed_pc=0x0c08b488u; return 0; }
r[14]+=0xffffffffu;
goto P_0c08b48a;
P_0c08b48a: /* original 6eee, guest PC 0x0c08b48a */
if(!s->budget--) { s->failed_pc=0x0c08b48au; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b48c;
P_0c08b48c: /* original e31c, guest PC 0x0c08b48c */
if(!s->budget--) { s->failed_pc=0x0c08b48cu; return 0; }
r[3]=0x0000001cu;
goto P_0c08b48e;
P_0c08b48e: /* original 2e3f, guest PC 0x0c08b48e */
if(!s->budget--) { s->failed_pc=0x0c08b48eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c08b490;
P_0c08b490: /* original 4008, guest PC 0x0c08b490 */
if(!s->budget--) { s->failed_pc=0x0c08b490u; return 0; }
r[0]<<=2;
goto P_0c08b492;
P_0c08b492: /* original 09d6, guest PC 0x0c08b492 */
if(!s->budget--) { s->failed_pc=0x0c08b492u; return 0; }
write(ram,r[9]+r[0],r[13],4);
goto P_0c08b494;
P_0c08b494: /* original 52f1, guest PC 0x0c08b494 */
if(!s->budget--) { s->failed_pc=0x0c08b494u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08b496;
P_0c08b496: /* original 0e1a, guest PC 0x0c08b496 */
if(!s->budget--) { s->failed_pc=0x0c08b496u; return 0; }
r[14]=r[19];
goto P_0c08b498;
P_0c08b498: /* original 6eef, guest PC 0x0c08b498 */
if(!s->budget--) { s->failed_pc=0x0c08b498u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c08b49a;
P_0c08b49a: /* original 3eac, guest PC 0x0c08b49a */
if(!s->budget--) { s->failed_pc=0x0c08b49au; return 0; }
r[14]+=r[10];
goto P_0c08b49c;
P_0c08b49c: /* original 85ec, guest PC 0x0c08b49c */
if(!s->budget--) { s->failed_pc=0x0c08b49cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c08b49e;
P_0c08b49e: /* original 6403, guest PC 0x0c08b49e */
if(!s->budget--) { s->failed_pc=0x0c08b49eu; return 0; }
r[4]=r[0];
goto P_0c08b4a0;
P_0c08b4a0: /* original 2428, guest PC 0x0c08b4a0 */
if(!s->budget--) { s->failed_pc=0x0c08b4a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08b4a2;
P_0c08b4a2: /* original 8b02, guest PC 0x0c08b4a2 */
if(!s->budget--) { s->failed_pc=0x0c08b4a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4aa; }
goto P_0c08b4a4;
P_0c08b4a4: /* original 60c3, guest PC 0x0c08b4a4 */
if(!s->budget--) { s->failed_pc=0x0c08b4a4u; return 0; }
r[0]=r[12];
goto P_0c08b4a6;
P_0c08b4a6: /* original 8810, guest PC 0x0c08b4a6 */
if(!s->budget--) { s->failed_pc=0x0c08b4a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b4a8;
P_0c08b4a8: /* original 8903, guest PC 0x0c08b4a8 */
if(!s->budget--) { s->failed_pc=0x0c08b4a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4b2; }
goto P_0c08b4aa;
P_0c08b4aa: /* original 60c3, guest PC 0x0c08b4aa */
if(!s->budget--) { s->failed_pc=0x0c08b4aau; return 0; }
r[0]=r[12];
goto P_0c08b4ac;
P_0c08b4ac: /* original 0bee, guest PC 0x0c08b4ac */
if(!s->budget--) { s->failed_pc=0x0c08b4acu; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c08b4ae;
P_0c08b4ae: /* original 4b0b, guest PC 0x0c08b4ae */
if(!s->budget--) { s->failed_pc=0x0c08b4aeu; return 0; }
target=r[11];
r[16]=code_base|0x0c08b4b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b4b2u) { target=s->pc; goto dispatch; }
goto P_0c08b4b2;
P_0c08b4b0: /* original 64d3, guest PC 0x0c08b4b0 */
if(!s->budget--) { s->failed_pc=0x0c08b4b0u; return 0; }
r[4]=r[13];
goto P_0c08b4b2;
P_0c08b4b2: /* original 52e5, guest PC 0x0c08b4b2 */
if(!s->budget--) { s->failed_pc=0x0c08b4b2u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c08b4b4;
P_0c08b4b4: /* original 6ef2, guest PC 0x0c08b4b4 */
if(!s->budget--) { s->failed_pc=0x0c08b4b4u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c08b4b6;
P_0c08b4b6: /* original 3d2c, guest PC 0x0c08b4b6 */
if(!s->budget--) { s->failed_pc=0x0c08b4b6u; return 0; }
r[13]+=r[2];
goto P_0c08b4b8;
P_0c08b4b8: /* original 7e01, guest PC 0x0c08b4b8 */
if(!s->budget--) { s->failed_pc=0x0c08b4b8u; return 0; }
r[14]+=0x00000001u;
goto P_0c08b4ba;
P_0c08b4ba: /* original 2fe2, guest PC 0x0c08b4ba */
if(!s->budget--) { s->failed_pc=0x0c08b4bau; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b4bc;
P_0c08b4bc: /* original 6ee0, guest PC 0x0c08b4bc */
if(!s->budget--) { s->failed_pc=0x0c08b4bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b4be;
P_0c08b4be: /* original 63ee, guest PC 0x0c08b4be */
if(!s->budget--) { s->failed_pc=0x0c08b4beu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b4c0;
P_0c08b4c0: /* original 2338, guest PC 0x0c08b4c0 */
if(!s->budget--) { s->failed_pc=0x0c08b4c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08b4c2;
P_0c08b4c2: /* original 8bd8, guest PC 0x0c08b4c2 */
if(!s->budget--) { s->failed_pc=0x0c08b4c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b476; }
goto P_0c08b4c4;
P_0c08b4c4: /* original 7f08, guest PC 0x0c08b4c4 */
if(!s->budget--) { s->failed_pc=0x0c08b4c4u; return 0; }
r[15]+=0x00000008u;
goto P_0c08b4c6;
P_0c08b4c6: /* original 60d3, guest PC 0x0c08b4c6 */
if(!s->budget--) { s->failed_pc=0x0c08b4c6u; return 0; }
r[0]=r[13];
goto P_0c08b4c8;
P_0c08b4c8: /* original 4f16, guest PC 0x0c08b4c8 */
if(!s->budget--) { s->failed_pc=0x0c08b4c8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4ca;
P_0c08b4ca: /* original 4f26, guest PC 0x0c08b4ca */
if(!s->budget--) { s->failed_pc=0x0c08b4cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4cc;
P_0c08b4cc: /* original fff9, guest PC 0x0c08b4cc */
if(!s->budget--) { s->failed_pc=0x0c08b4ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b4ce;
P_0c08b4ce: /* original 68f6, guest PC 0x0c08b4ce */
if(!s->budget--) { s->failed_pc=0x0c08b4ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b4d0;
P_0c08b4d0: /* original 69f6, guest PC 0x0c08b4d0 */
if(!s->budget--) { s->failed_pc=0x0c08b4d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b4d2;
P_0c08b4d2: /* original 6af6, guest PC 0x0c08b4d2 */
if(!s->budget--) { s->failed_pc=0x0c08b4d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b4d4;
P_0c08b4d4: /* original 6bf6, guest PC 0x0c08b4d4 */
if(!s->budget--) { s->failed_pc=0x0c08b4d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b4d6;
P_0c08b4d6: /* original 6cf6, guest PC 0x0c08b4d6 */
if(!s->budget--) { s->failed_pc=0x0c08b4d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b4d8;
P_0c08b4d8: /* original 6df6, guest PC 0x0c08b4d8 */
if(!s->budget--) { s->failed_pc=0x0c08b4d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b4da;
P_0c08b4da: /* original 000b, guest PC 0x0c08b4da */
if(!s->budget--) { s->failed_pc=0x0c08b4dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b4dc: /* original 6ef6, guest PC 0x0c08b4dc */
if(!s->budget--) { s->failed_pc=0x0c08b4dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b4de;
P_0c08b4de: /* original d50e, guest PC 0x0c08b4de */
if(!s->budget--) { s->failed_pc=0x0c08b4deu; return 0; }
r[5]=read(ram,0x0c08b518u,4);
goto P_0c08b4e0;
P_0c08b4e0: /* original a007, guest PC 0x0c08b4e0 */
if(!s->budget--) { s->failed_pc=0x0c08b4e0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4f2;
P_0c08b4e2: /* original 664e, guest PC 0x0c08b4e2 */
if(!s->budget--) { s->failed_pc=0x0c08b4e2u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4e4;
P_0c08b4e4: /* original 7501, guest PC 0x0c08b4e4 */
if(!s->budget--) { s->failed_pc=0x0c08b4e4u; return 0; }
r[5]+=0x00000001u;
goto P_0c08b4e6;
P_0c08b4e6: /* original 6450, guest PC 0x0c08b4e6 */
if(!s->budget--) { s->failed_pc=0x0c08b4e6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[4]=tmp;
goto P_0c08b4e8;
P_0c08b4e8: /* original 644e, guest PC 0x0c08b4e8 */
if(!s->budget--) { s->failed_pc=0x0c08b4e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4ea;
P_0c08b4ea: /* original 2448, guest PC 0x0c08b4ea */
if(!s->budget--) { s->failed_pc=0x0c08b4eau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08b4ec;
P_0c08b4ec: /* original 8bfa, guest PC 0x0c08b4ec */
if(!s->budget--) { s->failed_pc=0x0c08b4ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4e4; }
goto P_0c08b4ee;
P_0c08b4ee: /* original 76ff, guest PC 0x0c08b4ee */
if(!s->budget--) { s->failed_pc=0x0c08b4eeu; return 0; }
r[6]+=0xffffffffu;
goto P_0c08b4f0;
P_0c08b4f0: /* original 7501, guest PC 0x0c08b4f0 */
if(!s->budget--) { s->failed_pc=0x0c08b4f0u; return 0; }
r[5]+=0x00000001u;
goto P_0c08b4f2;
P_0c08b4f2: /* original 4615, guest PC 0x0c08b4f2 */
if(!s->budget--) { s->failed_pc=0x0c08b4f2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c08b4f4;
P_0c08b4f4: /* original 89f7, guest PC 0x0c08b4f4 */
if(!s->budget--) { s->failed_pc=0x0c08b4f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4e6; }
goto P_0c08b4f6;
P_0c08b4f6: /* original 000b, guest PC 0x0c08b4f6 */
if(!s->budget--) { s->failed_pc=0x0c08b4f6u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c08b4f8: /* original 6053, guest PC 0x0c08b4f8 */
if(!s->budget--) { s->failed_pc=0x0c08b4f8u; return 0; }
r[0]=r[5];
if(!vf3_matrix_family(0x0c08b4fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08b4fau; return 0; } return 1;
P_0c08b544: /* original 2fe6, guest PC 0x0c08b544 */
if(!s->budget--) { s->failed_pc=0x0c08b544u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b546;
P_0c08b546: /* original e41e, guest PC 0x0c08b546 */
if(!s->budget--) { s->failed_pc=0x0c08b546u; return 0; }
r[4]=0x0000001eu;
goto P_0c08b548;
P_0c08b548: /* original d33b, guest PC 0x0c08b548 */
if(!s->budget--) { s->failed_pc=0x0c08b548u; return 0; }
r[3]=read(ram,0x0c08b638u,4);
goto P_0c08b54a;
P_0c08b54a: /* original e500, guest PC 0x0c08b54a */
if(!s->budget--) { s->failed_pc=0x0c08b54au; return 0; }
r[5]=0x00000000u;
goto P_0c08b54c;
P_0c08b54c: /* original 4f22, guest PC 0x0c08b54c */
if(!s->budget--) { s->failed_pc=0x0c08b54cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b54e;
P_0c08b54e: /* original 6e32, guest PC 0x0c08b54e */
if(!s->budget--) { s->failed_pc=0x0c08b54eu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c08b550;
P_0c08b550: /* original 66e3, guest PC 0x0c08b550 */
if(!s->budget--) { s->failed_pc=0x0c08b550u; return 0; }
r[6]=r[14];
goto P_0c08b552;
P_0c08b552: /* original 7664, guest PC 0x0c08b552 */
if(!s->budget--) { s->failed_pc=0x0c08b552u; return 0; }
r[6]+=0x00000064u;
goto P_0c08b554;
P_0c08b554: /* original 4410, guest PC 0x0c08b554 */
if(!s->budget--) { s->failed_pc=0x0c08b554u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c08b556;
P_0c08b556: /* original 2652, guest PC 0x0c08b556 */
if(!s->budget--) { s->failed_pc=0x0c08b556u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c08b558;
P_0c08b558: /* original 8ffc, guest PC 0x0c08b558 */
if(!s->budget--) { s->failed_pc=0x0c08b558u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c08b554; }
goto P_0c08b55c;
P_0c08b55a: /* original 7604, guest PC 0x0c08b55a */
if(!s->budget--) { s->failed_pc=0x0c08b55au; return 0; }
r[6]+=0x00000004u;
goto P_0c08b55c;
P_0c08b55c: /* original d337, guest PC 0x0c08b55c */
if(!s->budget--) { s->failed_pc=0x0c08b55cu; return 0; }
r[3]=read(ram,0x0c08b63cu,4);
goto P_0c08b55e;
P_0c08b55e: /* original e010, guest PC 0x0c08b55e */
if(!s->budget--) { s->failed_pc=0x0c08b55eu; return 0; }
r[0]=0x00000010u;
goto P_0c08b560;
P_0c08b560: /* original 6230, guest PC 0x0c08b560 */
if(!s->budget--) { s->failed_pc=0x0c08b560u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c08b562;
P_0c08b562: /* original 0e24, guest PC 0x0c08b562 */
if(!s->budget--) { s->failed_pc=0x0c08b562u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08b564;
P_0c08b564: /* original bfbb, guest PC 0x0c08b564 */
if(!s->budget--) { s->failed_pc=0x0c08b564u; return 0; }
target=code_base|0x0c08b4deu; r[16]=code_base|0x0c08b568u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b568u) { target=s->pc; goto dispatch; }
goto P_0c08b568;
P_0c08b566: /* original 04ec, guest PC 0x0c08b566 */
if(!s->budget--) { s->failed_pc=0x0c08b566u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08b568;
P_0c08b568: /* original e504, guest PC 0x0c08b568 */
if(!s->budget--) { s->failed_pc=0x0c08b568u; return 0; }
r[5]=0x00000004u;
goto P_0c08b56a;
P_0c08b56a: /* original 6703, guest PC 0x0c08b56a */
if(!s->budget--) { s->failed_pc=0x0c08b56au; return 0; }
r[7]=r[0];
goto P_0c08b56c;
P_0c08b56c: /* original e600, guest PC 0x0c08b56c */
if(!s->budget--) { s->failed_pc=0x0c08b56cu; return 0; }
r[6]=0x00000000u;
goto P_0c08b56e;
P_0c08b56e: /* original bf5f, guest PC 0x0c08b56e */
if(!s->budget--) { s->failed_pc=0x0c08b56eu; return 0; }
target=code_base|0x0c08b430u; r[16]=code_base|0x0c08b572u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b572u) { target=s->pc; goto dispatch; }
goto P_0c08b572;
P_0c08b570: /* original 64e3, guest PC 0x0c08b570 */
if(!s->budget--) { s->failed_pc=0x0c08b570u; return 0; }
r[4]=r[14];
goto P_0c08b572;
P_0c08b572: /* original 6403, guest PC 0x0c08b572 */
if(!s->budget--) { s->failed_pc=0x0c08b572u; return 0; }
r[4]=r[0];
goto P_0c08b574;
P_0c08b574: /* original 9058, guest PC 0x0c08b574 */
if(!s->budget--) { s->failed_pc=0x0c08b574u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b628u,2);
goto P_0c08b576;
P_0c08b576: /* original 4f26, guest PC 0x0c08b576 */
if(!s->budget--) { s->failed_pc=0x0c08b576u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b578;
P_0c08b578: /* original 0e46, guest PC 0x0c08b578 */
if(!s->budget--) { s->failed_pc=0x0c08b578u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c08b57a;
P_0c08b57a: /* original 000b, guest PC 0x0c08b57a */
if(!s->budget--) { s->failed_pc=0x0c08b57au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b57c: /* original 6ef6, guest PC 0x0c08b57c */
if(!s->budget--) { s->failed_pc=0x0c08b57cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08b57eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08b57eu; return 0; } return 1;
P_0c0955b0: /* original 4f22, guest PC 0x0c0955b0 */
if(!s->budget--) { s->failed_pc=0x0c0955b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0955b2;
P_0c0955b2: /* original 7ff0, guest PC 0x0c0955b2 */
if(!s->budget--) { s->failed_pc=0x0c0955b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0955b4;
P_0c0955b4: /* original 1f42, guest PC 0x0c0955b4 */
if(!s->budget--) { s->failed_pc=0x0c0955b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0955b6;
P_0c0955b6: /* original 1f51, guest PC 0x0c0955b6 */
if(!s->budget--) { s->failed_pc=0x0c0955b6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0955b8;
P_0c0955b8: /* original 2f62, guest PC 0x0c0955b8 */
if(!s->budget--) { s->failed_pc=0x0c0955b8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0955ba;
P_0c0955ba: /* original 1f73, guest PC 0x0c0955ba */
if(!s->budget--) { s->failed_pc=0x0c0955bau; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c0955bc;
P_0c0955bc: /* original d34e, guest PC 0x0c0955bc */
if(!s->budget--) { s->failed_pc=0x0c0955bcu; return 0; }
r[3]=read(ram,0x0c0956f8u,4);
goto P_0c0955be;
P_0c0955be: /* original 430b, guest PC 0x0c0955be */
if(!s->budget--) { s->failed_pc=0x0c0955beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0955c2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c2u) { target=s->pc; goto dispatch; }
goto P_0c0955c2;
P_0c0955c0: /* original e400, guest PC 0x0c0955c0 */
if(!s->budget--) { s->failed_pc=0x0c0955c0u; return 0; }
r[4]=0x00000000u;
goto P_0c0955c2;
P_0c0955c2: /* original d24e, guest PC 0x0c0955c2 */
if(!s->budget--) { s->failed_pc=0x0c0955c2u; return 0; }
r[2]=read(ram,0x0c0956fcu,4);
goto P_0c0955c4;
P_0c0955c4: /* original 420b, guest PC 0x0c0955c4 */
if(!s->budget--) { s->failed_pc=0x0c0955c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0955c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c8u) { target=s->pc; goto dispatch; }
goto P_0c0955c8;
P_0c0955c6: /* original 0009, guest PC 0x0c0955c6 */
if(!s->budget--) { s->failed_pc=0x0c0955c6u; return 0; }
goto P_0c0955c8;
P_0c0955c8: /* original d34d, guest PC 0x0c0955c8 */
if(!s->budget--) { s->failed_pc=0x0c0955c8u; return 0; }
r[3]=read(ram,0x0c095700u,4);
goto P_0c0955ca;
P_0c0955ca: /* original 430b, guest PC 0x0c0955ca */
if(!s->budget--) { s->failed_pc=0x0c0955cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0955ceu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955ceu) { target=s->pc; goto dispatch; }
goto P_0c0955ce;
P_0c0955cc: /* original 54f6, guest PC 0x0c0955cc */
if(!s->budget--) { s->failed_pc=0x0c0955ccu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0955ce;
P_0c0955ce: /* original d34d, guest PC 0x0c0955ce */
if(!s->budget--) { s->failed_pc=0x0c0955ceu; return 0; }
r[3]=read(ram,0x0c095704u,4);
goto P_0c0955d0;
P_0c0955d0: /* original 430b, guest PC 0x0c0955d0 */
if(!s->budget--) { s->failed_pc=0x0c0955d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955d4u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955d4u) { target=s->pc; goto dispatch; }
goto P_0c0955d4;
P_0c0955d2: /* original 54f5, guest PC 0x0c0955d2 */
if(!s->budget--) { s->failed_pc=0x0c0955d2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0955d4;
P_0c0955d4: /* original d34c, guest PC 0x0c0955d4 */
if(!s->budget--) { s->failed_pc=0x0c0955d4u; return 0; }
r[3]=read(ram,0x0c095708u,4);
goto P_0c0955d6;
P_0c0955d6: /* original 430b, guest PC 0x0c0955d6 */
if(!s->budget--) { s->failed_pc=0x0c0955d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955dau;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955dau) { target=s->pc; goto dispatch; }
goto P_0c0955da;
P_0c0955d8: /* original 54f3, guest PC 0x0c0955d8 */
if(!s->budget--) { s->failed_pc=0x0c0955d8u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0955da;
P_0c0955da: /* original d24c, guest PC 0x0c0955da */
if(!s->budget--) { s->failed_pc=0x0c0955dau; return 0; }
r[2]=read(ram,0x0c09570cu,4);
goto P_0c0955dc;
P_0c0955dc: /* original 420b, guest PC 0x0c0955dc */
if(!s->budget--) { s->failed_pc=0x0c0955dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0955e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955e0u) { target=s->pc; goto dispatch; }
goto P_0c0955e0;
P_0c0955de: /* original e400, guest PC 0x0c0955de */
if(!s->budget--) { s->failed_pc=0x0c0955deu; return 0; }
r[4]=0x00000000u;
goto P_0c0955e0;
P_0c0955e0: /* original 6403, guest PC 0x0c0955e0 */
if(!s->budget--) { s->failed_pc=0x0c0955e0u; return 0; }
r[4]=r[0];
goto P_0c0955e2;
P_0c0955e2: /* original e020, guest PC 0x0c0955e2 */
if(!s->budget--) { s->failed_pc=0x0c0955e2u; return 0; }
r[0]=0x00000020u;
goto P_0c0955e4;
P_0c0955e4: /* original f346, guest PC 0x0c0955e4 */
if(!s->budget--) { s->failed_pc=0x0c0955e4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955e6;
P_0c0955e6: /* original e024, guest PC 0x0c0955e6 */
if(!s->budget--) { s->failed_pc=0x0c0955e6u; return 0; }
r[0]=0x00000024u;
goto P_0c0955e8;
P_0c0955e8: /* original 53f2, guest PC 0x0c0955e8 */
if(!s->budget--) { s->failed_pc=0x0c0955e8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0955ea;
P_0c0955ea: /* original f33a, guest PC 0x0c0955ea */
if(!s->budget--) { s->failed_pc=0x0c0955eau; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955ec;
P_0c0955ec: /* original f346, guest PC 0x0c0955ec */
if(!s->budget--) { s->failed_pc=0x0c0955ecu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955ee;
P_0c0955ee: /* original e028, guest PC 0x0c0955ee */
if(!s->budget--) { s->failed_pc=0x0c0955eeu; return 0; }
r[0]=0x00000028u;
goto P_0c0955f0;
P_0c0955f0: /* original 53f1, guest PC 0x0c0955f0 */
if(!s->budget--) { s->failed_pc=0x0c0955f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0955f2;
P_0c0955f2: /* original f33a, guest PC 0x0c0955f2 */
if(!s->budget--) { s->failed_pc=0x0c0955f2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955f4;
P_0c0955f4: /* original f346, guest PC 0x0c0955f4 */
if(!s->budget--) { s->failed_pc=0x0c0955f4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955f6;
P_0c0955f6: /* original e401, guest PC 0x0c0955f6 */
if(!s->budget--) { s->failed_pc=0x0c0955f6u; return 0; }
r[4]=0x00000001u;
goto P_0c0955f8;
P_0c0955f8: /* original 63f2, guest PC 0x0c0955f8 */
if(!s->budget--) { s->failed_pc=0x0c0955f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0955fa;
P_0c0955fa: /* original 7f10, guest PC 0x0c0955fa */
if(!s->budget--) { s->failed_pc=0x0c0955fau; return 0; }
r[15]+=0x00000010u;
goto P_0c0955fc;
P_0c0955fc: /* original f33a, guest PC 0x0c0955fc */
if(!s->budget--) { s->failed_pc=0x0c0955fcu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955fe;
P_0c0955fe: /* original d344, guest PC 0x0c0955fe */
if(!s->budget--) { s->failed_pc=0x0c0955feu; return 0; }
r[3]=read(ram,0x0c095710u,4);
goto P_0c095600;
P_0c095600: /* original 432b, guest PC 0x0c095600 */
if(!s->budget--) { s->failed_pc=0x0c095600u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c095602: /* original 4f26, guest PC 0x0c095602 */
if(!s->budget--) { s->failed_pc=0x0c095602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c095604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095604u; return 0; } return 1;
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c096864: /* original 2fe6, guest PC 0x0c096864 */
if(!s->budget--) { s->failed_pc=0x0c096864u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096866;
P_0c096866: /* original 4f22, guest PC 0x0c096866 */
if(!s->budget--) { s->failed_pc=0x0c096866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096868;
P_0c096868: /* original 7ff8, guest PC 0x0c096868 */
if(!s->budget--) { s->failed_pc=0x0c096868u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09686a;
P_0c09686a: /* original 2f42, guest PC 0x0c09686a */
if(!s->budget--) { s->failed_pc=0x0c09686au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09686c;
P_0c09686c: /* original d311, guest PC 0x0c09686c */
if(!s->budget--) { s->failed_pc=0x0c09686cu; return 0; }
r[3]=read(ram,0x0c0968b4u,4);
goto P_0c09686e;
P_0c09686e: /* original 430b, guest PC 0x0c09686e */
if(!s->budget--) { s->failed_pc=0x0c09686eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096872u;
write(ram,r[15]+4,r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096872u) { target=s->pc; goto dispatch; }
goto P_0c096872;
P_0c096870: /* original 1f51, guest PC 0x0c096870 */
if(!s->budget--) { s->failed_pc=0x0c096870u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c096872;
P_0c096872: /* original 6e03, guest PC 0x0c096872 */
if(!s->budget--) { s->failed_pc=0x0c096872u; return 0; }
r[14]=r[0];
goto P_0c096874;
P_0c096874: /* original 2ee8, guest PC 0x0c096874 */
if(!s->budget--) { s->failed_pc=0x0c096874u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c096876;
P_0c096876: /* original 8905, guest PC 0x0c096876 */
if(!s->budget--) { s->failed_pc=0x0c096876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096884; }
goto P_0c096878;
P_0c096878: /* original d30f, guest PC 0x0c096878 */
if(!s->budget--) { s->failed_pc=0x0c096878u; return 0; }
r[3]=read(ram,0x0c0968b8u,4);
goto P_0c09687a;
P_0c09687a: /* original 430b, guest PC 0x0c09687a */
if(!s->budget--) { s->failed_pc=0x0c09687au; return 0; }
target=r[3];
r[16]=code_base|0x0c09687eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09687eu) { target=s->pc; goto dispatch; }
goto P_0c09687e;
P_0c09687c: /* original 64e3, guest PC 0x0c09687c */
if(!s->budget--) { s->failed_pc=0x0c09687cu; return 0; }
r[4]=r[14];
goto P_0c09687e;
P_0c09687e: /* original d20f, guest PC 0x0c09687e */
if(!s->budget--) { s->failed_pc=0x0c09687eu; return 0; }
r[2]=read(ram,0x0c0968bcu,4);
goto P_0c096880;
P_0c096880: /* original 420b, guest PC 0x0c096880 */
if(!s->budget--) { s->failed_pc=0x0c096880u; return 0; }
target=r[2];
r[16]=code_base|0x0c096884u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096884u) { target=s->pc; goto dispatch; }
goto P_0c096884;
P_0c096882: /* original 64e3, guest PC 0x0c096882 */
if(!s->budget--) { s->failed_pc=0x0c096882u; return 0; }
r[4]=r[14];
goto P_0c096884;
P_0c096884: /* original 0002, guest PC 0x0c096884 */
if(!s->budget--) { s->failed_pc=0x0c096884u; return 0; }
r[0]=r[17];
goto P_0c096886;
P_0c096886: /* original 9313, guest PC 0x0c096886 */
if(!s->budget--) { s->failed_pc=0x0c096886u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c096888;
P_0c096888: /* original 2039, guest PC 0x0c096888 */
if(!s->budget--) { s->failed_pc=0x0c096888u; return 0; }
r[0]&=r[3];
goto P_0c09688a;
P_0c09688a: /* original cbe0, guest PC 0x0c09688a */
if(!s->budget--) { s->failed_pc=0x0c09688au; return 0; }
r[0]|=224u;
goto P_0c09688c;
P_0c09688c: /* original 400e, guest PC 0x0c09688c */
if(!s->budget--) { s->failed_pc=0x0c09688cu; return 0; }
r[17]=r[0];
goto P_0c09688e;
P_0c09688e: /* original d20c, guest PC 0x0c09688e */
if(!s->budget--) { s->failed_pc=0x0c09688eu; return 0; }
r[2]=read(ram,0x0c0968c0u,4);
goto P_0c096890;
P_0c096890: /* original 420b, guest PC 0x0c096890 */
if(!s->budget--) { s->failed_pc=0x0c096890u; return 0; }
target=r[2];
r[16]=code_base|0x0c096894u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096894u) { target=s->pc; goto dispatch; }
goto P_0c096894;
P_0c096892: /* original 0009, guest PC 0x0c096892 */
if(!s->budget--) { s->failed_pc=0x0c096892u; return 0; }
goto P_0c096894;
P_0c096894: /* original d10b, guest PC 0x0c096894 */
if(!s->budget--) { s->failed_pc=0x0c096894u; return 0; }
r[1]=read(ram,0x0c0968c4u,4);
goto P_0c096896;
P_0c096896: /* original 410b, guest PC 0x0c096896 */
if(!s->budget--) { s->failed_pc=0x0c096896u; return 0; }
target=r[1];
r[16]=code_base|0x0c09689au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09689au) { target=s->pc; goto dispatch; }
goto P_0c09689a;
P_0c096898: /* original 0009, guest PC 0x0c096898 */
if(!s->budget--) { s->failed_pc=0x0c096898u; return 0; }
goto P_0c09689a;
P_0c09689a: /* original 0002, guest PC 0x0c09689a */
if(!s->budget--) { s->failed_pc=0x0c09689au; return 0; }
r[0]=r[17];
goto P_0c09689c;
P_0c09689c: /* original 9208, guest PC 0x0c09689c */
if(!s->budget--) { s->failed_pc=0x0c09689cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c09689e;
P_0c09689e: /* original 2029, guest PC 0x0c09689e */
if(!s->budget--) { s->failed_pc=0x0c09689eu; return 0; }
r[0]&=r[2];
goto P_0c0968a0;
P_0c0968a0: /* original 400e, guest PC 0x0c0968a0 */
if(!s->budget--) { s->failed_pc=0x0c0968a0u; return 0; }
r[17]=r[0];
goto P_0c0968a2;
P_0c0968a2: /* original 64f2, guest PC 0x0c0968a2 */
if(!s->budget--) { s->failed_pc=0x0c0968a2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0968a4;
P_0c0968a4: /* original 55f1, guest PC 0x0c0968a4 */
if(!s->budget--) { s->failed_pc=0x0c0968a4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0968a6;
P_0c0968a6: /* original 7f08, guest PC 0x0c0968a6 */
if(!s->budget--) { s->failed_pc=0x0c0968a6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0968a8;
P_0c0968a8: /* original 4f26, guest PC 0x0c0968a8 */
if(!s->budget--) { s->failed_pc=0x0c0968a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0968aa;
P_0c0968aa: /* original d307, guest PC 0x0c0968aa */
if(!s->budget--) { s->failed_pc=0x0c0968aau; return 0; }
r[3]=read(ram,0x0c0968c8u,4);
goto P_0c0968ac;
P_0c0968ac: /* original 432b, guest PC 0x0c0968ac */
if(!s->budget--) { s->failed_pc=0x0c0968acu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0968ae: /* original 6ef6, guest PC 0x0c0968ae */
if(!s->budget--) { s->failed_pc=0x0c0968aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0968b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0968b0u; return 0; } return 1;
P_0c0a13a4: /* original d224, guest PC 0x0c0a13a4 */
if(!s->budget--) { s->failed_pc=0x0c0a13a4u; return 0; }
r[2]=read(ram,0x0c0a1438u,4);
goto P_0c0a13a6;
P_0c0a13a6: /* original 6322, guest PC 0x0c0a13a6 */
if(!s->budget--) { s->failed_pc=0x0c0a13a6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0a13a8;
P_0c0a13a8: /* original 435a, guest PC 0x0c0a13a8 */
if(!s->budget--) { s->failed_pc=0x0c0a13a8u; return 0; }
r[53]=r[3];
goto P_0c0a13aa;
P_0c0a13aa: /* original 4311, guest PC 0x0c0a13aa */
if(!s->budget--) { s->failed_pc=0x0c0a13aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0a13ac;
P_0c0a13ac: /* original 8d04, guest PC 0x0c0a13ac */
if(!s->budget--) { s->failed_pc=0x0c0a13acu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0a13b8; }
goto P_0c0a13b0;
P_0c0a13ae: /* original f32d, guest PC 0x0c0a13ae */
if(!s->budget--) { s->failed_pc=0x0c0a13aeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a13b0;
P_0c0a13b0: /* original d222, guest PC 0x0c0a13b0 */
if(!s->budget--) { s->failed_pc=0x0c0a13b0u; return 0; }
r[2]=read(ram,0x0c0a143cu,4);
goto P_0c0a13b2;
P_0c0a13b2: /* original 425a, guest PC 0x0c0a13b2 */
if(!s->budget--) { s->failed_pc=0x0c0a13b2u; return 0; }
r[53]=r[2];
goto P_0c0a13b4;
P_0c0a13b4: /* original f20d, guest PC 0x0c0a13b4 */
if(!s->budget--) { s->failed_pc=0x0c0a13b4u; return 0; }
fr[2]=r[53];
goto P_0c0a13b6;
P_0c0a13b6: /* original f320, guest PC 0x0c0a13b6 */
if(!s->budget--) { s->failed_pc=0x0c0a13b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0a13b8;
P_0c0a13b8: /* original c721, guest PC 0x0c0a13b8 */
if(!s->budget--) { s->failed_pc=0x0c0a13b8u; return 0; }
r[0]=code_base|0x000a1440u;
goto P_0c0a13ba;
P_0c0a13ba: /* original f03c, guest PC 0x0c0a13ba */
if(!s->budget--) { s->failed_pc=0x0c0a13bau; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0a13bc;
P_0c0a13bc: /* original f208, guest PC 0x0c0a13bc */
if(!s->budget--) { s->failed_pc=0x0c0a13bcu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0a13be;
P_0c0a13be: /* original 000b, guest PC 0x0c0a13be */
if(!s->budget--) { s->failed_pc=0x0c0a13beu; return 0; }
target=r[16];
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'/');
s->pc=target; return ram->oob==0;
P_0c0a13c0: /* original f023, guest PC 0x0c0a13c0 */
if(!s->budget--) { s->failed_pc=0x0c0a13c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'/');
if(!vf3_matrix_family(0x0c0a13c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a13c2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
