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
int vf3_away_batch42_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07ad58u: goto P_0c07ad58;
case 0x0c07ad5au: goto P_0c07ad5a;
case 0x0c07ad5cu: goto P_0c07ad5c;
case 0x0c07ad5eu: goto P_0c07ad5e;
case 0x0c07ad60u: goto P_0c07ad60;
case 0x0c07ad62u: goto P_0c07ad62;
case 0x0c07ad64u: goto P_0c07ad64;
case 0x0c07ad66u: goto P_0c07ad66;
case 0x0c07ad68u: goto P_0c07ad68;
case 0x0c07ad6au: goto P_0c07ad6a;
case 0x0c07ad6cu: goto P_0c07ad6c;
case 0x0c07ad6eu: goto P_0c07ad6e;
case 0x0c07ad70u: goto P_0c07ad70;
case 0x0c07ad72u: goto P_0c07ad72;
case 0x0c07ad74u: goto P_0c07ad74;
case 0x0c07ad76u: goto P_0c07ad76;
case 0x0c07ad78u: goto P_0c07ad78;
case 0x0c07ad7au: goto P_0c07ad7a;
case 0x0c07ad7cu: goto P_0c07ad7c;
case 0x0c07ad7eu: goto P_0c07ad7e;
case 0x0c07ad80u: goto P_0c07ad80;
case 0x0c07ad82u: goto P_0c07ad82;
case 0x0c07ad84u: goto P_0c07ad84;
case 0x0c07ad86u: goto P_0c07ad86;
case 0x0c07ad88u: goto P_0c07ad88;
case 0x0c07ad8au: goto P_0c07ad8a;
case 0x0c07ad8cu: goto P_0c07ad8c;
case 0x0c07ad8eu: goto P_0c07ad8e;
case 0x0c07ad90u: goto P_0c07ad90;
case 0x0c07ad92u: goto P_0c07ad92;
case 0x0c07ad94u: goto P_0c07ad94;
case 0x0c07b5b0u: goto P_0c07b5b0;
case 0x0c07b5b2u: goto P_0c07b5b2;
case 0x0c07b5b4u: goto P_0c07b5b4;
case 0x0c07b5b6u: goto P_0c07b5b6;
case 0x0c07b5b8u: goto P_0c07b5b8;
case 0x0c07b5bau: goto P_0c07b5ba;
case 0x0c07b5bcu: goto P_0c07b5bc;
case 0x0c07b5beu: goto P_0c07b5be;
case 0x0c07b5c0u: goto P_0c07b5c0;
case 0x0c07b5c2u: goto P_0c07b5c2;
case 0x0c07b5c4u: goto P_0c07b5c4;
case 0x0c07b5c6u: goto P_0c07b5c6;
case 0x0c07b5c8u: goto P_0c07b5c8;
case 0x0c07b5cau: goto P_0c07b5ca;
case 0x0c07b5ccu: goto P_0c07b5cc;
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
case 0x0c09d42cu: goto P_0c09d42c;
case 0x0c09d42eu: goto P_0c09d42e;
case 0x0c09d430u: goto P_0c09d430;
case 0x0c09d432u: goto P_0c09d432;
case 0x0c09d434u: goto P_0c09d434;
case 0x0c09d436u: goto P_0c09d436;
case 0x0c09d438u: goto P_0c09d438;
case 0x0c09d43au: goto P_0c09d43a;
case 0x0c09d43cu: goto P_0c09d43c;
case 0x0c09d43eu: goto P_0c09d43e;
case 0x0c09d440u: goto P_0c09d440;
case 0x0c09d442u: goto P_0c09d442;
case 0x0c09d444u: goto P_0c09d444;
case 0x0c09d446u: goto P_0c09d446;
case 0x0c09d448u: goto P_0c09d448;
case 0x0c09d44au: goto P_0c09d44a;
case 0x0c09d44cu: goto P_0c09d44c;
case 0x0c09d44eu: goto P_0c09d44e;
case 0x0c09d450u: goto P_0c09d450;
case 0x0c09d452u: goto P_0c09d452;
case 0x0c09d454u: goto P_0c09d454;
case 0x0c09d456u: goto P_0c09d456;
case 0x0c09d458u: goto P_0c09d458;
case 0x0c09d45au: goto P_0c09d45a;
case 0x0c09d45cu: goto P_0c09d45c;
case 0x0c09d45eu: goto P_0c09d45e;
case 0x0c09d460u: goto P_0c09d460;
case 0x0c09d462u: goto P_0c09d462;
case 0x0c09d464u: goto P_0c09d464;
case 0x0c09d466u: goto P_0c09d466;
case 0x0c09d468u: goto P_0c09d468;
case 0x0c09d46au: goto P_0c09d46a;
case 0x0c09d46cu: goto P_0c09d46c;
case 0x0c09d46eu: goto P_0c09d46e;
case 0x0c09d470u: goto P_0c09d470;
case 0x0c09d472u: goto P_0c09d472;
case 0x0c09d474u: goto P_0c09d474;
case 0x0c09d476u: goto P_0c09d476;
case 0x0c09d478u: goto P_0c09d478;
case 0x0c09d47au: goto P_0c09d47a;
case 0x0c09d47cu: goto P_0c09d47c;
case 0x0c09d47eu: goto P_0c09d47e;
case 0x0c09d480u: goto P_0c09d480;
case 0x0c09d482u: goto P_0c09d482;
case 0x0c09d484u: goto P_0c09d484;
case 0x0c09d486u: goto P_0c09d486;
case 0x0c09d488u: goto P_0c09d488;
case 0x0c09d48au: goto P_0c09d48a;
case 0x0c09d48cu: goto P_0c09d48c;
case 0x0c09d48eu: goto P_0c09d48e;
case 0x0c09d490u: goto P_0c09d490;
case 0x0c09d492u: goto P_0c09d492;
case 0x0c09d494u: goto P_0c09d494;
case 0x0c09d496u: goto P_0c09d496;
case 0x0c09d498u: goto P_0c09d498;
case 0x0c09d49au: goto P_0c09d49a;
case 0x0c09d49cu: goto P_0c09d49c;
case 0x0c09d49eu: goto P_0c09d49e;
case 0x0c09d4a0u: goto P_0c09d4a0;
case 0x0c09d4a2u: goto P_0c09d4a2;
case 0x0c09d4a4u: goto P_0c09d4a4;
case 0x0c09d4a6u: goto P_0c09d4a6;
case 0x0c09d4a8u: goto P_0c09d4a8;
case 0x0c09d4aau: goto P_0c09d4aa;
case 0x0c09d4acu: goto P_0c09d4ac;
case 0x0c09d4aeu: goto P_0c09d4ae;
case 0x0c09d4b0u: goto P_0c09d4b0;
case 0x0c09d4b2u: goto P_0c09d4b2;
case 0x0c09d4b4u: goto P_0c09d4b4;
case 0x0c09d4b6u: goto P_0c09d4b6;
case 0x0c09d4b8u: goto P_0c09d4b8;
case 0x0c09d4bau: goto P_0c09d4ba;
case 0x0c09d4bcu: goto P_0c09d4bc;
case 0x0c09d4beu: goto P_0c09d4be;
case 0x0c09d4c0u: goto P_0c09d4c0;
case 0x0c09d4c2u: goto P_0c09d4c2;
case 0x0c09d4c4u: goto P_0c09d4c4;
case 0x0c09d4c6u: goto P_0c09d4c6;
case 0x0c09d4c8u: goto P_0c09d4c8;
case 0x0c09d4cau: goto P_0c09d4ca;
case 0x0c09d4ccu: goto P_0c09d4cc;
case 0x0c09d4ceu: goto P_0c09d4ce;
case 0x0c09d4d0u: goto P_0c09d4d0;
case 0x0c09d4d2u: goto P_0c09d4d2;
case 0x0c09d4d4u: goto P_0c09d4d4;
case 0x0c09d4d6u: goto P_0c09d4d6;
case 0x0c09d4d8u: goto P_0c09d4d8;
case 0x0c09d4dau: goto P_0c09d4da;
case 0x0c09d4dcu: goto P_0c09d4dc;
case 0x0c09d4deu: goto P_0c09d4de;
case 0x0c09d4e0u: goto P_0c09d4e0;
case 0x0c09d4e2u: goto P_0c09d4e2;
case 0x0c09d4e4u: goto P_0c09d4e4;
case 0x0c09d4e6u: goto P_0c09d4e6;
case 0x0c09d4e8u: goto P_0c09d4e8;
case 0x0c09d4eau: goto P_0c09d4ea;
case 0x0c09d4ecu: goto P_0c09d4ec;
case 0x0c09d4eeu: goto P_0c09d4ee;
case 0x0c09d4f0u: goto P_0c09d4f0;
case 0x0c09d4f2u: goto P_0c09d4f2;
case 0x0c09d4f4u: goto P_0c09d4f4;
case 0x0c09d4f6u: goto P_0c09d4f6;
case 0x0c09d4f8u: goto P_0c09d4f8;
case 0x0c09d4fau: goto P_0c09d4fa;
case 0x0c09d4fcu: goto P_0c09d4fc;
case 0x0c09d4feu: goto P_0c09d4fe;
case 0x0c09d500u: goto P_0c09d500;
case 0x0c09d502u: goto P_0c09d502;
case 0x0c09d504u: goto P_0c09d504;
case 0x0c09d506u: goto P_0c09d506;
case 0x0c09d508u: goto P_0c09d508;
case 0x0c09d50au: goto P_0c09d50a;
case 0x0c09d50cu: goto P_0c09d50c;
case 0x0c09d50eu: goto P_0c09d50e;
case 0x0c09d510u: goto P_0c09d510;
case 0x0c09d512u: goto P_0c09d512;
case 0x0c09d514u: goto P_0c09d514;
case 0x0c09d516u: goto P_0c09d516;
case 0x0c09d518u: goto P_0c09d518;
case 0x0c09d51au: goto P_0c09d51a;
case 0x0c09d51cu: goto P_0c09d51c;
case 0x0c09d51eu: goto P_0c09d51e;
case 0x0c09d520u: goto P_0c09d520;
case 0x0c09d522u: goto P_0c09d522;
case 0x0c09d524u: goto P_0c09d524;
case 0x0c09d526u: goto P_0c09d526;
case 0x0c09d528u: goto P_0c09d528;
case 0x0c09d52au: goto P_0c09d52a;
case 0x0c09d52cu: goto P_0c09d52c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07ad58: /* original 2fe6, guest PC 0x0c07ad58 */
if(!s->budget--) { s->failed_pc=0x0c07ad58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad5a;
P_0c07ad5a: /* original ee38, guest PC 0x0c07ad5a */
if(!s->budget--) { s->failed_pc=0x0c07ad5au; return 0; }
r[14]=0x00000038u;
goto P_0c07ad5c;
P_0c07ad5c: /* original 2fd6, guest PC 0x0c07ad5c */
if(!s->budget--) { s->failed_pc=0x0c07ad5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad5e;
P_0c07ad5e: /* original ed00, guest PC 0x0c07ad5e */
if(!s->budget--) { s->failed_pc=0x0c07ad5eu; return 0; }
r[13]=0x00000000u;
goto P_0c07ad60;
P_0c07ad60: /* original 2fc6, guest PC 0x0c07ad60 */
if(!s->budget--) { s->failed_pc=0x0c07ad60u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad62;
P_0c07ad62: /* original 2fb6, guest PC 0x0c07ad62 */
if(!s->budget--) { s->failed_pc=0x0c07ad62u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad64;
P_0c07ad64: /* original eb44, guest PC 0x0c07ad64 */
if(!s->budget--) { s->failed_pc=0x0c07ad64u; return 0; }
r[11]=0x00000044u;
goto P_0c07ad66;
P_0c07ad66: /* original 2fa6, guest PC 0x0c07ad66 */
if(!s->budget--) { s->failed_pc=0x0c07ad66u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad68;
P_0c07ad68: /* original 4f22, guest PC 0x0c07ad68 */
if(!s->budget--) { s->failed_pc=0x0c07ad68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ad6a;
P_0c07ad6a: /* original dc2d, guest PC 0x0c07ad6a */
if(!s->budget--) { s->failed_pc=0x0c07ad6au; return 0; }
r[12]=read(ram,0x0c07ae20u,4);
goto P_0c07ad6c;
P_0c07ad6c: /* original da29, guest PC 0x0c07ad6c */
if(!s->budget--) { s->failed_pc=0x0c07ad6cu; return 0; }
r[10]=read(ram,0x0c07ae14u,4);
goto P_0c07ad6e;
P_0c07ad6e: /* original 64e3, guest PC 0x0c07ad6e */
if(!s->budget--) { s->failed_pc=0x0c07ad6eu; return 0; }
r[4]=r[14];
goto P_0c07ad70;
P_0c07ad70: /* original 4400, guest PC 0x0c07ad70 */
if(!s->budget--) { s->failed_pc=0x0c07ad70u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07ad72;
P_0c07ad72: /* original 34ac, guest PC 0x0c07ad72 */
if(!s->budget--) { s->failed_pc=0x0c07ad72u; return 0; }
r[4]+=r[10];
goto P_0c07ad74;
P_0c07ad74: /* original 6341, guest PC 0x0c07ad74 */
if(!s->budget--) { s->failed_pc=0x0c07ad74u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07ad76;
P_0c07ad76: /* original 633d, guest PC 0x0c07ad76 */
if(!s->budget--) { s->failed_pc=0x0c07ad76u; return 0; }
r[3]=r[3]&65535u;
goto P_0c07ad78;
P_0c07ad78: /* original 33c0, guest PC 0x0c07ad78 */
if(!s->budget--) { s->failed_pc=0x0c07ad78u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[12])!=0);
goto P_0c07ad7a;
P_0c07ad7a: /* original 8b00, guest PC 0x0c07ad7a */
if(!s->budget--) { s->failed_pc=0x0c07ad7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ad7e; }
goto P_0c07ad7c;
P_0c07ad7c: /* original 24d1, guest PC 0x0c07ad7c */
if(!s->budget--) { s->failed_pc=0x0c07ad7cu; return 0; }
write(ram,r[4],r[13],2);
goto P_0c07ad7e;
P_0c07ad7e: /* original b437, guest PC 0x0c07ad7e */
if(!s->budget--) { s->failed_pc=0x0c07ad7eu; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ad82u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ad82u) { target=s->pc; goto dispatch; }
goto P_0c07ad82;
P_0c07ad80: /* original 64e3, guest PC 0x0c07ad80 */
if(!s->budget--) { s->failed_pc=0x0c07ad80u; return 0; }
r[4]=r[14];
goto P_0c07ad82;
P_0c07ad82: /* original 7e01, guest PC 0x0c07ad82 */
if(!s->budget--) { s->failed_pc=0x0c07ad82u; return 0; }
r[14]+=0x00000001u;
goto P_0c07ad84;
P_0c07ad84: /* original 3eb7, guest PC 0x0c07ad84 */
if(!s->budget--) { s->failed_pc=0x0c07ad84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[11])!=0);
goto P_0c07ad86;
P_0c07ad86: /* original 8bf2, guest PC 0x0c07ad86 */
if(!s->budget--) { s->failed_pc=0x0c07ad86u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ad6e; }
goto P_0c07ad88;
P_0c07ad88: /* original 4f26, guest PC 0x0c07ad88 */
if(!s->budget--) { s->failed_pc=0x0c07ad88u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ad8a;
P_0c07ad8a: /* original 6af6, guest PC 0x0c07ad8a */
if(!s->budget--) { s->failed_pc=0x0c07ad8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07ad8c;
P_0c07ad8c: /* original 6bf6, guest PC 0x0c07ad8c */
if(!s->budget--) { s->failed_pc=0x0c07ad8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07ad8e;
P_0c07ad8e: /* original 6cf6, guest PC 0x0c07ad8e */
if(!s->budget--) { s->failed_pc=0x0c07ad8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ad90;
P_0c07ad90: /* original 6df6, guest PC 0x0c07ad90 */
if(!s->budget--) { s->failed_pc=0x0c07ad90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ad92;
P_0c07ad92: /* original 000b, guest PC 0x0c07ad92 */
if(!s->budget--) { s->failed_pc=0x0c07ad92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ad94: /* original 6ef6, guest PC 0x0c07ad94 */
if(!s->budget--) { s->failed_pc=0x0c07ad94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ad96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ad96u; return 0; } return 1;
P_0c07b5b0: /* original 920d, guest PC 0x0c07b5b0 */
if(!s->budget--) { s->failed_pc=0x0c07b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b5b2;
P_0c07b5b2: /* original 634d, guest PC 0x0c07b5b2 */
if(!s->budget--) { s->failed_pc=0x0c07b5b2u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5b4;
P_0c07b5b4: /* original 2328, guest PC 0x0c07b5b4 */
if(!s->budget--) { s->failed_pc=0x0c07b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c07b5b6;
P_0c07b5b6: /* original 8908, guest PC 0x0c07b5b6 */
if(!s->budget--) { s->failed_pc=0x0c07b5b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b5ca; }
goto P_0c07b5b8;
P_0c07b5b8: /* original 900a, guest PC 0x0c07b5b8 */
if(!s->budget--) { s->failed_pc=0x0c07b5b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b5ba;
P_0c07b5ba: /* original 2409, guest PC 0x0c07b5ba */
if(!s->budget--) { s->failed_pc=0x0c07b5bau; return 0; }
r[4]&=r[0];
goto P_0c07b5bc;
P_0c07b5bc: /* original d005, guest PC 0x0c07b5bc */
if(!s->budget--) { s->failed_pc=0x0c07b5bcu; return 0; }
r[0]=read(ram,0x0c07b5d4u,4);
goto P_0c07b5be;
P_0c07b5be: /* original 634d, guest PC 0x0c07b5be */
if(!s->budget--) { s->failed_pc=0x0c07b5beu; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5c0;
P_0c07b5c0: /* original 6133, guest PC 0x0c07b5c0 */
if(!s->budget--) { s->failed_pc=0x0c07b5c0u; return 0; }
r[1]=r[3];
goto P_0c07b5c2;
P_0c07b5c2: /* original 4108, guest PC 0x0c07b5c2 */
if(!s->budget--) { s->failed_pc=0x0c07b5c2u; return 0; }
r[1]<<=2;
goto P_0c07b5c4;
P_0c07b5c4: /* original 4300, guest PC 0x0c07b5c4 */
if(!s->budget--) { s->failed_pc=0x0c07b5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07b5c6;
P_0c07b5c6: /* original 331c, guest PC 0x0c07b5c6 */
if(!s->budget--) { s->failed_pc=0x0c07b5c6u; return 0; }
r[3]+=r[1];
goto P_0c07b5c8;
P_0c07b5c8: /* original 043d, guest PC 0x0c07b5c8 */
if(!s->budget--) { s->failed_pc=0x0c07b5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07b5ca;
P_0c07b5ca: /* original 000b, guest PC 0x0c07b5ca */
if(!s->budget--) { s->failed_pc=0x0c07b5cau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c07b5cc: /* original 6043, guest PC 0x0c07b5cc */
if(!s->budget--) { s->failed_pc=0x0c07b5ccu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c07b5ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5ceu; return 0; } return 1;
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
P_0c09d42c: /* original 4f22, guest PC 0x0c09d42c */
if(!s->budget--) { s->failed_pc=0x0c09d42cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d42e;
P_0c09d42e: /* original e004, guest PC 0x0c09d42e */
if(!s->budget--) { s->failed_pc=0x0c09d42eu; return 0; }
r[0]=0x00000004u;
goto P_0c09d430;
P_0c09d430: /* original 7ff0, guest PC 0x0c09d430 */
if(!s->budget--) { s->failed_pc=0x0c09d430u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d432;
P_0c09d432: /* original 2f42, guest PC 0x0c09d432 */
if(!s->budget--) { s->failed_pc=0x0c09d432u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d434;
P_0c09d434: /* original 64f3, guest PC 0x0c09d434 */
if(!s->budget--) { s->failed_pc=0x0c09d434u; return 0; }
r[4]=r[15];
goto P_0c09d436;
P_0c09d436: /* original ff47, guest PC 0x0c09d436 */
if(!s->budget--) { s->failed_pc=0x0c09d436u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d438;
P_0c09d438: /* original e008, guest PC 0x0c09d438 */
if(!s->budget--) { s->failed_pc=0x0c09d438u; return 0; }
r[0]=0x00000008u;
goto P_0c09d43a;
P_0c09d43a: /* original f38d, guest PC 0x0c09d43a */
if(!s->budget--) { s->failed_pc=0x0c09d43au; return 0; }
fr[3]=0;
goto P_0c09d43c;
P_0c09d43c: /* original ff37, guest PC 0x0c09d43c */
if(!s->budget--) { s->failed_pc=0x0c09d43cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09d43e;
P_0c09d43e: /* original e00c, guest PC 0x0c09d43e */
if(!s->budget--) { s->failed_pc=0x0c09d43eu; return 0; }
r[0]=0x0000000cu;
goto P_0c09d440;
P_0c09d440: /* original ff57, guest PC 0x0c09d440 */
if(!s->budget--) { s->failed_pc=0x0c09d440u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c09d442;
P_0c09d442: /* original d34e, guest PC 0x0c09d442 */
if(!s->budget--) { s->failed_pc=0x0c09d442u; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d444;
P_0c09d444: /* original 65f2, guest PC 0x0c09d444 */
if(!s->budget--) { s->failed_pc=0x0c09d444u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d446;
P_0c09d446: /* original 430b, guest PC 0x0c09d446 */
if(!s->budget--) { s->failed_pc=0x0c09d446u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d44au;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d44au) { target=s->pc; goto dispatch; }
goto P_0c09d44a;
P_0c09d448: /* original 7404, guest PC 0x0c09d448 */
if(!s->budget--) { s->failed_pc=0x0c09d448u; return 0; }
r[4]+=0x00000004u;
goto P_0c09d44a;
P_0c09d44a: /* original 7f10, guest PC 0x0c09d44a */
if(!s->budget--) { s->failed_pc=0x0c09d44au; return 0; }
r[15]+=0x00000010u;
goto P_0c09d44c;
P_0c09d44c: /* original 4f26, guest PC 0x0c09d44c */
if(!s->budget--) { s->failed_pc=0x0c09d44cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d44e;
P_0c09d44e: /* original 000b, guest PC 0x0c09d44e */
if(!s->budget--) { s->failed_pc=0x0c09d44eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d450: /* original 0009, guest PC 0x0c09d450 */
if(!s->budget--) { s->failed_pc=0x0c09d450u; return 0; }
goto P_0c09d452;
P_0c09d452: /* original 4f22, guest PC 0x0c09d452 */
if(!s->budget--) { s->failed_pc=0x0c09d452u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d454;
P_0c09d454: /* original 6053, guest PC 0x0c09d454 */
if(!s->budget--) { s->failed_pc=0x0c09d454u; return 0; }
r[0]=r[5];
goto P_0c09d456;
P_0c09d456: /* original 7ff4, guest PC 0x0c09d456 */
if(!s->budget--) { s->failed_pc=0x0c09d456u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d458;
P_0c09d458: /* original 2f41, guest PC 0x0c09d458 */
if(!s->budget--) { s->failed_pc=0x0c09d458u; return 0; }
write(ram,r[15],r[4],2);
goto P_0c09d45a;
P_0c09d45a: /* original 81f2, guest PC 0x0c09d45a */
if(!s->budget--) { s->failed_pc=0x0c09d45au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d45c;
P_0c09d45c: /* original 6063, guest PC 0x0c09d45c */
if(!s->budget--) { s->failed_pc=0x0c09d45cu; return 0; }
r[0]=r[6];
goto P_0c09d45e;
P_0c09d45e: /* original 81f4, guest PC 0x0c09d45e */
if(!s->budget--) { s->failed_pc=0x0c09d45eu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d460;
P_0c09d460: /* original 85f4, guest PC 0x0c09d460 */
if(!s->budget--) { s->failed_pc=0x0c09d460u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d462;
P_0c09d462: /* original d347, guest PC 0x0c09d462 */
if(!s->budget--) { s->failed_pc=0x0c09d462u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d464;
P_0c09d464: /* original 6403, guest PC 0x0c09d464 */
if(!s->budget--) { s->failed_pc=0x0c09d464u; return 0; }
r[4]=r[0];
goto P_0c09d466;
P_0c09d466: /* original 430b, guest PC 0x0c09d466 */
if(!s->budget--) { s->failed_pc=0x0c09d466u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d46au;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d46au) { target=s->pc; goto dispatch; }
goto P_0c09d46a;
P_0c09d468: /* original 644d, guest PC 0x0c09d468 */
if(!s->budget--) { s->failed_pc=0x0c09d468u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d46a;
P_0c09d46a: /* original 85f2, guest PC 0x0c09d46a */
if(!s->budget--) { s->failed_pc=0x0c09d46au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d46c;
P_0c09d46c: /* original d345, guest PC 0x0c09d46c */
if(!s->budget--) { s->failed_pc=0x0c09d46cu; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d46e;
P_0c09d46e: /* original 6403, guest PC 0x0c09d46e */
if(!s->budget--) { s->failed_pc=0x0c09d46eu; return 0; }
r[4]=r[0];
goto P_0c09d470;
P_0c09d470: /* original 430b, guest PC 0x0c09d470 */
if(!s->budget--) { s->failed_pc=0x0c09d470u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d474u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d474u) { target=s->pc; goto dispatch; }
goto P_0c09d474;
P_0c09d472: /* original 644d, guest PC 0x0c09d472 */
if(!s->budget--) { s->failed_pc=0x0c09d472u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d474;
P_0c09d474: /* original 64f1, guest PC 0x0c09d474 */
if(!s->budget--) { s->failed_pc=0x0c09d474u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d476;
P_0c09d476: /* original 7f0c, guest PC 0x0c09d476 */
if(!s->budget--) { s->failed_pc=0x0c09d476u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d478;
P_0c09d478: /* original d343, guest PC 0x0c09d478 */
if(!s->budget--) { s->failed_pc=0x0c09d478u; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d47a;
P_0c09d47a: /* original 644d, guest PC 0x0c09d47a */
if(!s->budget--) { s->failed_pc=0x0c09d47au; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d47c;
P_0c09d47c: /* original 432b, guest PC 0x0c09d47c */
if(!s->budget--) { s->failed_pc=0x0c09d47cu; return 0; }
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
P_0c09d47e: /* original 4f26, guest PC 0x0c09d47e */
if(!s->budget--) { s->failed_pc=0x0c09d47eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d480;
P_0c09d480: /* original 4f22, guest PC 0x0c09d480 */
if(!s->budget--) { s->failed_pc=0x0c09d480u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d482;
P_0c09d482: /* original 6041, guest PC 0x0c09d482 */
if(!s->budget--) { s->failed_pc=0x0c09d482u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c09d484;
P_0c09d484: /* original 7ff4, guest PC 0x0c09d484 */
if(!s->budget--) { s->failed_pc=0x0c09d484u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d486;
P_0c09d486: /* original 81f4, guest PC 0x0c09d486 */
if(!s->budget--) { s->failed_pc=0x0c09d486u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d488;
P_0c09d488: /* original 8541, guest PC 0x0c09d488 */
if(!s->budget--) { s->failed_pc=0x0c09d488u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c09d48a;
P_0c09d48a: /* original 81f2, guest PC 0x0c09d48a */
if(!s->budget--) { s->failed_pc=0x0c09d48au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d48c;
P_0c09d48c: /* original 8542, guest PC 0x0c09d48c */
if(!s->budget--) { s->failed_pc=0x0c09d48cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c09d48e;
P_0c09d48e: /* original 2f01, guest PC 0x0c09d48e */
if(!s->budget--) { s->failed_pc=0x0c09d48eu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c09d490;
P_0c09d490: /* original 85f4, guest PC 0x0c09d490 */
if(!s->budget--) { s->failed_pc=0x0c09d490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d492;
P_0c09d492: /* original d33b, guest PC 0x0c09d492 */
if(!s->budget--) { s->failed_pc=0x0c09d492u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d494;
P_0c09d494: /* original 6403, guest PC 0x0c09d494 */
if(!s->budget--) { s->failed_pc=0x0c09d494u; return 0; }
r[4]=r[0];
goto P_0c09d496;
P_0c09d496: /* original 430b, guest PC 0x0c09d496 */
if(!s->budget--) { s->failed_pc=0x0c09d496u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d49au;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d49au) { target=s->pc; goto dispatch; }
goto P_0c09d49a;
P_0c09d498: /* original 644d, guest PC 0x0c09d498 */
if(!s->budget--) { s->failed_pc=0x0c09d498u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d49a;
P_0c09d49a: /* original 85f2, guest PC 0x0c09d49a */
if(!s->budget--) { s->failed_pc=0x0c09d49au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d49c;
P_0c09d49c: /* original d339, guest PC 0x0c09d49c */
if(!s->budget--) { s->failed_pc=0x0c09d49cu; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d49e;
P_0c09d49e: /* original 6403, guest PC 0x0c09d49e */
if(!s->budget--) { s->failed_pc=0x0c09d49eu; return 0; }
r[4]=r[0];
goto P_0c09d4a0;
P_0c09d4a0: /* original 430b, guest PC 0x0c09d4a0 */
if(!s->budget--) { s->failed_pc=0x0c09d4a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d4a4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d4a4u) { target=s->pc; goto dispatch; }
goto P_0c09d4a4;
P_0c09d4a2: /* original 644d, guest PC 0x0c09d4a2 */
if(!s->budget--) { s->failed_pc=0x0c09d4a2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4a4;
P_0c09d4a4: /* original 64f1, guest PC 0x0c09d4a4 */
if(!s->budget--) { s->failed_pc=0x0c09d4a4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d4a6;
P_0c09d4a6: /* original 7f0c, guest PC 0x0c09d4a6 */
if(!s->budget--) { s->failed_pc=0x0c09d4a6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d4a8;
P_0c09d4a8: /* original d337, guest PC 0x0c09d4a8 */
if(!s->budget--) { s->failed_pc=0x0c09d4a8u; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d4aa;
P_0c09d4aa: /* original 644d, guest PC 0x0c09d4aa */
if(!s->budget--) { s->failed_pc=0x0c09d4aau; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4ac;
P_0c09d4ac: /* original 432b, guest PC 0x0c09d4ac */
if(!s->budget--) { s->failed_pc=0x0c09d4acu; return 0; }
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
P_0c09d4ae: /* original 4f26, guest PC 0x0c09d4ae */
if(!s->budget--) { s->failed_pc=0x0c09d4aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d4b0;
P_0c09d4b0: /* original 4f22, guest PC 0x0c09d4b0 */
if(!s->budget--) { s->failed_pc=0x0c09d4b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d4b2;
P_0c09d4b2: /* original 7ff0, guest PC 0x0c09d4b2 */
if(!s->budget--) { s->failed_pc=0x0c09d4b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d4b4;
P_0c09d4b4: /* original 2f51, guest PC 0x0c09d4b4 */
if(!s->budget--) { s->failed_pc=0x0c09d4b4u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c09d4b6;
P_0c09d4b6: /* original 6041, guest PC 0x0c09d4b6 */
if(!s->budget--) { s->failed_pc=0x0c09d4b6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c09d4b8;
P_0c09d4b8: /* original 81f4, guest PC 0x0c09d4b8 */
if(!s->budget--) { s->failed_pc=0x0c09d4b8u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d4ba;
P_0c09d4ba: /* original 8541, guest PC 0x0c09d4ba */
if(!s->budget--) { s->failed_pc=0x0c09d4bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c09d4bc;
P_0c09d4bc: /* original 81f2, guest PC 0x0c09d4bc */
if(!s->budget--) { s->failed_pc=0x0c09d4bcu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d4be;
P_0c09d4be: /* original 8542, guest PC 0x0c09d4be */
if(!s->budget--) { s->failed_pc=0x0c09d4beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c09d4c0;
P_0c09d4c0: /* original 81f6, guest PC 0x0c09d4c0 */
if(!s->budget--) { s->failed_pc=0x0c09d4c0u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c09d4c2;
P_0c09d4c2: /* original 85f4, guest PC 0x0c09d4c2 */
if(!s->budget--) { s->failed_pc=0x0c09d4c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d4c4;
P_0c09d4c4: /* original d32e, guest PC 0x0c09d4c4 */
if(!s->budget--) { s->failed_pc=0x0c09d4c4u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d4c6;
P_0c09d4c6: /* original 6403, guest PC 0x0c09d4c6 */
if(!s->budget--) { s->failed_pc=0x0c09d4c6u; return 0; }
r[4]=r[0];
goto P_0c09d4c8;
P_0c09d4c8: /* original 430b, guest PC 0x0c09d4c8 */
if(!s->budget--) { s->failed_pc=0x0c09d4c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d4ccu;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d4ccu) { target=s->pc; goto dispatch; }
goto P_0c09d4cc;
P_0c09d4ca: /* original 644d, guest PC 0x0c09d4ca */
if(!s->budget--) { s->failed_pc=0x0c09d4cau; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4cc;
P_0c09d4cc: /* original 85f2, guest PC 0x0c09d4cc */
if(!s->budget--) { s->failed_pc=0x0c09d4ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d4ce;
P_0c09d4ce: /* original 64f1, guest PC 0x0c09d4ce */
if(!s->budget--) { s->failed_pc=0x0c09d4ceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d4d0;
P_0c09d4d0: /* original d32c, guest PC 0x0c09d4d0 */
if(!s->budget--) { s->failed_pc=0x0c09d4d0u; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d4d2;
P_0c09d4d2: /* original 600d, guest PC 0x0c09d4d2 */
if(!s->budget--) { s->failed_pc=0x0c09d4d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c09d4d4;
P_0c09d4d4: /* original 430b, guest PC 0x0c09d4d4 */
if(!s->budget--) { s->failed_pc=0x0c09d4d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d4d8u;
r[4]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d4d8u) { target=s->pc; goto dispatch; }
goto P_0c09d4d8;
P_0c09d4d6: /* original 340c, guest PC 0x0c09d4d6 */
if(!s->budget--) { s->failed_pc=0x0c09d4d6u; return 0; }
r[4]+=r[0];
goto P_0c09d4d8;
P_0c09d4d8: /* original 85f6, guest PC 0x0c09d4d8 */
if(!s->budget--) { s->failed_pc=0x0c09d4d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c09d4da;
P_0c09d4da: /* original 7f10, guest PC 0x0c09d4da */
if(!s->budget--) { s->failed_pc=0x0c09d4dau; return 0; }
r[15]+=0x00000010u;
goto P_0c09d4dc;
P_0c09d4dc: /* original d32a, guest PC 0x0c09d4dc */
if(!s->budget--) { s->failed_pc=0x0c09d4dcu; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d4de;
P_0c09d4de: /* original 6403, guest PC 0x0c09d4de */
if(!s->budget--) { s->failed_pc=0x0c09d4deu; return 0; }
r[4]=r[0];
goto P_0c09d4e0;
P_0c09d4e0: /* original 644d, guest PC 0x0c09d4e0 */
if(!s->budget--) { s->failed_pc=0x0c09d4e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4e2;
P_0c09d4e2: /* original 432b, guest PC 0x0c09d4e2 */
if(!s->budget--) { s->failed_pc=0x0c09d4e2u; return 0; }
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
P_0c09d4e4: /* original 4f26, guest PC 0x0c09d4e4 */
if(!s->budget--) { s->failed_pc=0x0c09d4e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d4e6;
P_0c09d4e6: /* original 2fe6, guest PC 0x0c09d4e6 */
if(!s->budget--) { s->failed_pc=0x0c09d4e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d4e8;
P_0c09d4e8: /* original e030, guest PC 0x0c09d4e8 */
if(!s->budget--) { s->failed_pc=0x0c09d4e8u; return 0; }
r[0]=0x00000030u;
goto P_0c09d4ea;
P_0c09d4ea: /* original 2fd6, guest PC 0x0c09d4ea */
if(!s->budget--) { s->failed_pc=0x0c09d4eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d4ec;
P_0c09d4ec: /* original 6e43, guest PC 0x0c09d4ec */
if(!s->budget--) { s->failed_pc=0x0c09d4ecu; return 0; }
r[14]=r[4];
goto P_0c09d4ee;
P_0c09d4ee: /* original 4f22, guest PC 0x0c09d4ee */
if(!s->budget--) { s->failed_pc=0x0c09d4eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d4f0;
P_0c09d4f0: /* original f3e6, guest PC 0x0c09d4f0 */
if(!s->budget--) { s->failed_pc=0x0c09d4f0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d4f2;
P_0c09d4f2: /* original e034, guest PC 0x0c09d4f2 */
if(!s->budget--) { s->failed_pc=0x0c09d4f2u; return 0; }
r[0]=0x00000034u;
goto P_0c09d4f4;
P_0c09d4f4: /* original 7ff4, guest PC 0x0c09d4f4 */
if(!s->budget--) { s->failed_pc=0x0c09d4f4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d4f6;
P_0c09d4f6: /* original 6df3, guest PC 0x0c09d4f6 */
if(!s->budget--) { s->failed_pc=0x0c09d4f6u; return 0; }
r[13]=r[15];
goto P_0c09d4f8;
P_0c09d4f8: /* original fd3a, guest PC 0x0c09d4f8 */
if(!s->budget--) { s->failed_pc=0x0c09d4f8u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c09d4fa;
P_0c09d4fa: /* original f3e6, guest PC 0x0c09d4fa */
if(!s->budget--) { s->failed_pc=0x0c09d4fau; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d4fc;
P_0c09d4fc: /* original e004, guest PC 0x0c09d4fc */
if(!s->budget--) { s->failed_pc=0x0c09d4fcu; return 0; }
r[0]=0x00000004u;
goto P_0c09d4fe;
P_0c09d4fe: /* original fd37, guest PC 0x0c09d4fe */
if(!s->budget--) { s->failed_pc=0x0c09d4feu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09d500;
P_0c09d500: /* original e038, guest PC 0x0c09d500 */
if(!s->budget--) { s->failed_pc=0x0c09d500u; return 0; }
r[0]=0x00000038u;
goto P_0c09d502;
P_0c09d502: /* original f3e6, guest PC 0x0c09d502 */
if(!s->budget--) { s->failed_pc=0x0c09d502u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d504;
P_0c09d504: /* original e008, guest PC 0x0c09d504 */
if(!s->budget--) { s->failed_pc=0x0c09d504u; return 0; }
r[0]=0x00000008u;
goto P_0c09d506;
P_0c09d506: /* original fd37, guest PC 0x0c09d506 */
if(!s->budget--) { s->failed_pc=0x0c09d506u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09d508;
P_0c09d508: /* original d320, guest PC 0x0c09d508 */
if(!s->budget--) { s->failed_pc=0x0c09d508u; return 0; }
r[3]=read(ram,0x0c09d58cu,4);
goto P_0c09d50a;
P_0c09d50a: /* original 430b, guest PC 0x0c09d50a */
if(!s->budget--) { s->failed_pc=0x0c09d50au; return 0; }
target=r[3];
r[16]=code_base|0x0c09d50eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d50eu) { target=s->pc; goto dispatch; }
goto P_0c09d50e;
P_0c09d50c: /* original 64e3, guest PC 0x0c09d50c */
if(!s->budget--) { s->failed_pc=0x0c09d50cu; return 0; }
r[4]=r[14];
goto P_0c09d50e;
P_0c09d50e: /* original f3d8, guest PC 0x0c09d50e */
if(!s->budget--) { s->failed_pc=0x0c09d50eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c09d510;
P_0c09d510: /* original e030, guest PC 0x0c09d510 */
if(!s->budget--) { s->failed_pc=0x0c09d510u; return 0; }
r[0]=0x00000030u;
goto P_0c09d512;
P_0c09d512: /* original 7f0c, guest PC 0x0c09d512 */
if(!s->budget--) { s->failed_pc=0x0c09d512u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d514;
P_0c09d514: /* original fe37, guest PC 0x0c09d514 */
if(!s->budget--) { s->failed_pc=0x0c09d514u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d516;
P_0c09d516: /* original e004, guest PC 0x0c09d516 */
if(!s->budget--) { s->failed_pc=0x0c09d516u; return 0; }
r[0]=0x00000004u;
goto P_0c09d518;
P_0c09d518: /* original f3d6, guest PC 0x0c09d518 */
if(!s->budget--) { s->failed_pc=0x0c09d518u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09d51a;
P_0c09d51a: /* original e034, guest PC 0x0c09d51a */
if(!s->budget--) { s->failed_pc=0x0c09d51au; return 0; }
r[0]=0x00000034u;
goto P_0c09d51c;
P_0c09d51c: /* original 4f26, guest PC 0x0c09d51c */
if(!s->budget--) { s->failed_pc=0x0c09d51cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d51e;
P_0c09d51e: /* original fe37, guest PC 0x0c09d51e */
if(!s->budget--) { s->failed_pc=0x0c09d51eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d520;
P_0c09d520: /* original e008, guest PC 0x0c09d520 */
if(!s->budget--) { s->failed_pc=0x0c09d520u; return 0; }
r[0]=0x00000008u;
goto P_0c09d522;
P_0c09d522: /* original f3d6, guest PC 0x0c09d522 */
if(!s->budget--) { s->failed_pc=0x0c09d522u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09d524;
P_0c09d524: /* original e038, guest PC 0x0c09d524 */
if(!s->budget--) { s->failed_pc=0x0c09d524u; return 0; }
r[0]=0x00000038u;
goto P_0c09d526;
P_0c09d526: /* original fe37, guest PC 0x0c09d526 */
if(!s->budget--) { s->failed_pc=0x0c09d526u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d528;
P_0c09d528: /* original 6df6, guest PC 0x0c09d528 */
if(!s->budget--) { s->failed_pc=0x0c09d528u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d52a;
P_0c09d52a: /* original 000b, guest PC 0x0c09d52a */
if(!s->budget--) { s->failed_pc=0x0c09d52au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d52c: /* original 6ef6, guest PC 0x0c09d52c */
if(!s->budget--) { s->failed_pc=0x0c09d52cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09d52eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
