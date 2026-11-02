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
int vf3_away_batch8_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05ddf2u: goto P_0c05ddf2;
case 0x0c05ddf4u: goto P_0c05ddf4;
case 0x0c05ddf6u: goto P_0c05ddf6;
case 0x0c05ddf8u: goto P_0c05ddf8;
case 0x0c05ddfau: goto P_0c05ddfa;
case 0x0c05ddfcu: goto P_0c05ddfc;
case 0x0c05ddfeu: goto P_0c05ddfe;
case 0x0c05de00u: goto P_0c05de00;
case 0x0c05de02u: goto P_0c05de02;
case 0x0c05de04u: goto P_0c05de04;
case 0x0c05de06u: goto P_0c05de06;
case 0x0c05de08u: goto P_0c05de08;
case 0x0c05de0au: goto P_0c05de0a;
case 0x0c05de0cu: goto P_0c05de0c;
case 0x0c05de0eu: goto P_0c05de0e;
case 0x0c05de10u: goto P_0c05de10;
case 0x0c05de12u: goto P_0c05de12;
case 0x0c05de14u: goto P_0c05de14;
case 0x0c05de16u: goto P_0c05de16;
case 0x0c05de18u: goto P_0c05de18;
case 0x0c05de1au: goto P_0c05de1a;
case 0x0c05de1cu: goto P_0c05de1c;
case 0x0c05de1eu: goto P_0c05de1e;
case 0x0c05de20u: goto P_0c05de20;
case 0x0c05de22u: goto P_0c05de22;
case 0x0c05de24u: goto P_0c05de24;
case 0x0c05de26u: goto P_0c05de26;
case 0x0c05de28u: goto P_0c05de28;
case 0x0c05de2au: goto P_0c05de2a;
case 0x0c05de2cu: goto P_0c05de2c;
case 0x0c05de6cu: goto P_0c05de6c;
case 0x0c05de6eu: goto P_0c05de6e;
case 0x0c05de70u: goto P_0c05de70;
case 0x0c05de72u: goto P_0c05de72;
case 0x0c05de74u: goto P_0c05de74;
case 0x0c05de76u: goto P_0c05de76;
case 0x0c05de78u: goto P_0c05de78;
case 0x0c05de7au: goto P_0c05de7a;
case 0x0c05de7cu: goto P_0c05de7c;
case 0x0c05de7eu: goto P_0c05de7e;
case 0x0c05de80u: goto P_0c05de80;
case 0x0c05de82u: goto P_0c05de82;
case 0x0c05de84u: goto P_0c05de84;
case 0x0c05de86u: goto P_0c05de86;
case 0x0c05de88u: goto P_0c05de88;
case 0x0c05de8au: goto P_0c05de8a;
case 0x0c05de8cu: goto P_0c05de8c;
case 0x0c05de8eu: goto P_0c05de8e;
case 0x0c05de90u: goto P_0c05de90;
case 0x0c05de92u: goto P_0c05de92;
case 0x0c05de94u: goto P_0c05de94;
case 0x0c05de96u: goto P_0c05de96;
case 0x0c05de98u: goto P_0c05de98;
case 0x0c05de9au: goto P_0c05de9a;
case 0x0c05de9cu: goto P_0c05de9c;
case 0x0c05de9eu: goto P_0c05de9e;
case 0x0c05dea0u: goto P_0c05dea0;
case 0x0c05dea2u: goto P_0c05dea2;
case 0x0c05dea4u: goto P_0c05dea4;
case 0x0c05dea6u: goto P_0c05dea6;
case 0x0c05dea8u: goto P_0c05dea8;
case 0x0c05deaau: goto P_0c05deaa;
case 0x0c05deacu: goto P_0c05deac;
case 0x0c05deaeu: goto P_0c05deae;
case 0x0c05deb0u: goto P_0c05deb0;
case 0x0c05deb2u: goto P_0c05deb2;
case 0x0c05deb4u: goto P_0c05deb4;
case 0x0c05deb6u: goto P_0c05deb6;
case 0x0c05deb8u: goto P_0c05deb8;
case 0x0c05debau: goto P_0c05deba;
case 0x0c05debcu: goto P_0c05debc;
case 0x0c05debeu: goto P_0c05debe;
case 0x0c05dec0u: goto P_0c05dec0;
case 0x0c05dec2u: goto P_0c05dec2;
case 0x0c05dec4u: goto P_0c05dec4;
case 0x0c05dec6u: goto P_0c05dec6;
case 0x0c05dec8u: goto P_0c05dec8;
case 0x0c05decau: goto P_0c05deca;
case 0x0c05deccu: goto P_0c05decc;
case 0x0c05deceu: goto P_0c05dece;
case 0x0c05ded0u: goto P_0c05ded0;
case 0x0c05ded2u: goto P_0c05ded2;
case 0x0c05ded4u: goto P_0c05ded4;
case 0x0c05ded6u: goto P_0c05ded6;
case 0x0c05ded8u: goto P_0c05ded8;
case 0x0c05dedau: goto P_0c05deda;
case 0x0c05dedcu: goto P_0c05dedc;
case 0x0c05dedeu: goto P_0c05dede;
case 0x0c05dee0u: goto P_0c05dee0;
case 0x0c05dee2u: goto P_0c05dee2;
case 0x0c05dee4u: goto P_0c05dee4;
case 0x0c05dee6u: goto P_0c05dee6;
case 0x0c05dee8u: goto P_0c05dee8;
case 0x0c05deeau: goto P_0c05deea;
case 0x0c05deecu: goto P_0c05deec;
case 0x0c05deeeu: goto P_0c05deee;
case 0x0c05def0u: goto P_0c05def0;
case 0x0c05def2u: goto P_0c05def2;
case 0x0c05def4u: goto P_0c05def4;
case 0x0c05def6u: goto P_0c05def6;
case 0x0c05def8u: goto P_0c05def8;
case 0x0c05defau: goto P_0c05defa;
case 0x0c05defcu: goto P_0c05defc;
case 0x0c05defeu: goto P_0c05defe;
case 0x0c05df00u: goto P_0c05df00;
case 0x0c05df02u: goto P_0c05df02;
case 0x0c05df04u: goto P_0c05df04;
case 0x0c05df06u: goto P_0c05df06;
case 0x0c05df08u: goto P_0c05df08;
case 0x0c05df0au: goto P_0c05df0a;
case 0x0c05df0cu: goto P_0c05df0c;
case 0x0c05df0eu: goto P_0c05df0e;
case 0x0c05df10u: goto P_0c05df10;
case 0x0c05df12u: goto P_0c05df12;
case 0x0c05df14u: goto P_0c05df14;
case 0x0c05df16u: goto P_0c05df16;
case 0x0c05df18u: goto P_0c05df18;
case 0x0c05df1au: goto P_0c05df1a;
case 0x0c05df1cu: goto P_0c05df1c;
case 0x0c05df1eu: goto P_0c05df1e;
case 0x0c05df20u: goto P_0c05df20;
case 0x0c05df22u: goto P_0c05df22;
case 0x0c05df24u: goto P_0c05df24;
case 0x0c05df26u: goto P_0c05df26;
case 0x0c05df28u: goto P_0c05df28;
case 0x0c05df2au: goto P_0c05df2a;
case 0x0c05df2cu: goto P_0c05df2c;
case 0x0c05df2eu: goto P_0c05df2e;
case 0x0c05df30u: goto P_0c05df30;
case 0x0c05df32u: goto P_0c05df32;
case 0x0c05df34u: goto P_0c05df34;
case 0x0c05df36u: goto P_0c05df36;
case 0x0c05df38u: goto P_0c05df38;
case 0x0c05df3au: goto P_0c05df3a;
case 0x0c05df3cu: goto P_0c05df3c;
case 0x0c05df3eu: goto P_0c05df3e;
case 0x0c05df40u: goto P_0c05df40;
case 0x0c05df42u: goto P_0c05df42;
case 0x0c05df44u: goto P_0c05df44;
case 0x0c05e1d2u: goto P_0c05e1d2;
case 0x0c05e1d4u: goto P_0c05e1d4;
case 0x0c05e1d6u: goto P_0c05e1d6;
case 0x0c05e1d8u: goto P_0c05e1d8;
case 0x0c05e1dau: goto P_0c05e1da;
case 0x0c05e1dcu: goto P_0c05e1dc;
case 0x0c05e1deu: goto P_0c05e1de;
case 0x0c05e1e0u: goto P_0c05e1e0;
case 0x0c05e1e2u: goto P_0c05e1e2;
case 0x0c05e1e4u: goto P_0c05e1e4;
case 0x0c05e1e6u: goto P_0c05e1e6;
case 0x0c05e1e8u: goto P_0c05e1e8;
case 0x0c05e1eau: goto P_0c05e1ea;
case 0x0c05e1ecu: goto P_0c05e1ec;
case 0x0c05e1eeu: goto P_0c05e1ee;
case 0x0c05e1f0u: goto P_0c05e1f0;
case 0x0c05e1f2u: goto P_0c05e1f2;
case 0x0c05e1f4u: goto P_0c05e1f4;
case 0x0c05e1f6u: goto P_0c05e1f6;
case 0x0c05e1f8u: goto P_0c05e1f8;
case 0x0c05e1fau: goto P_0c05e1fa;
case 0x0c05e1fcu: goto P_0c05e1fc;
case 0x0c05e1feu: goto P_0c05e1fe;
case 0x0c05e200u: goto P_0c05e200;
case 0x0c05e202u: goto P_0c05e202;
case 0x0c05e204u: goto P_0c05e204;
case 0x0c05e206u: goto P_0c05e206;
case 0x0c05e208u: goto P_0c05e208;
case 0x0c05e20au: goto P_0c05e20a;
case 0x0c05e20cu: goto P_0c05e20c;
case 0x0c05e20eu: goto P_0c05e20e;
case 0x0c05e210u: goto P_0c05e210;
case 0x0c05e212u: goto P_0c05e212;
case 0x0c05e214u: goto P_0c05e214;
case 0x0c05e216u: goto P_0c05e216;
case 0x0c05e218u: goto P_0c05e218;
case 0x0c05e21au: goto P_0c05e21a;
case 0x0c05e21cu: goto P_0c05e21c;
case 0x0c05e21eu: goto P_0c05e21e;
case 0x0c05e220u: goto P_0c05e220;
case 0x0c05e222u: goto P_0c05e222;
case 0x0c05e224u: goto P_0c05e224;
case 0x0c05e226u: goto P_0c05e226;
case 0x0c05e228u: goto P_0c05e228;
case 0x0c05e22au: goto P_0c05e22a;
case 0x0c05e22cu: goto P_0c05e22c;
case 0x0c05e22eu: goto P_0c05e22e;
case 0x0c05e230u: goto P_0c05e230;
case 0x0c05e232u: goto P_0c05e232;
case 0x0c05e234u: goto P_0c05e234;
case 0x0c05e236u: goto P_0c05e236;
case 0x0c05e238u: goto P_0c05e238;
case 0x0c05e23au: goto P_0c05e23a;
case 0x0c05f964u: goto P_0c05f964;
case 0x0c05f966u: goto P_0c05f966;
case 0x0c05f968u: goto P_0c05f968;
case 0x0c05f96au: goto P_0c05f96a;
case 0x0c05f96cu: goto P_0c05f96c;
case 0x0c05f96eu: goto P_0c05f96e;
case 0x0c05f970u: goto P_0c05f970;
case 0x0c05f972u: goto P_0c05f972;
case 0x0c05f974u: goto P_0c05f974;
case 0x0c05f976u: goto P_0c05f976;
case 0x0c05f978u: goto P_0c05f978;
case 0x0c05f97au: goto P_0c05f97a;
case 0x0c05f97cu: goto P_0c05f97c;
case 0x0c05f97eu: goto P_0c05f97e;
case 0x0c05f980u: goto P_0c05f980;
case 0x0c05f982u: goto P_0c05f982;
case 0x0c05f984u: goto P_0c05f984;
case 0x0c05f986u: goto P_0c05f986;
case 0x0c05f988u: goto P_0c05f988;
case 0x0c05f98au: goto P_0c05f98a;
case 0x0c05f98cu: goto P_0c05f98c;
case 0x0c05f98eu: goto P_0c05f98e;
case 0x0c05f990u: goto P_0c05f990;
case 0x0c05f992u: goto P_0c05f992;
case 0x0c05f994u: goto P_0c05f994;
case 0x0c05f996u: goto P_0c05f996;
case 0x0c05f998u: goto P_0c05f998;
case 0x0c05f99au: goto P_0c05f99a;
case 0x0c05f99cu: goto P_0c05f99c;
case 0x0c05f99eu: goto P_0c05f99e;
case 0x0c05f9a0u: goto P_0c05f9a0;
case 0x0c05f9a2u: goto P_0c05f9a2;
case 0x0c05f9a4u: goto P_0c05f9a4;
case 0x0c05f9a6u: goto P_0c05f9a6;
case 0x0c05f9a8u: goto P_0c05f9a8;
case 0x0c05f9aau: goto P_0c05f9aa;
case 0x0c05f9acu: goto P_0c05f9ac;
case 0x0c05f9aeu: goto P_0c05f9ae;
case 0x0c05f9b0u: goto P_0c05f9b0;
case 0x0c05f9b2u: goto P_0c05f9b2;
case 0x0c05f9b4u: goto P_0c05f9b4;
case 0x0c05f9b6u: goto P_0c05f9b6;
case 0x0c05f9b8u: goto P_0c05f9b8;
case 0x0c05f9bau: goto P_0c05f9ba;
case 0x0c05f9bcu: goto P_0c05f9bc;
case 0x0c05f9beu: goto P_0c05f9be;
case 0x0c05f9c0u: goto P_0c05f9c0;
case 0x0c05f9c2u: goto P_0c05f9c2;
case 0x0c05f9c4u: goto P_0c05f9c4;
case 0x0c05f9c6u: goto P_0c05f9c6;
case 0x0c05f9c8u: goto P_0c05f9c8;
case 0x0c05f9cau: goto P_0c05f9ca;
case 0x0c05f9ccu: goto P_0c05f9cc;
case 0x0c05f9ceu: goto P_0c05f9ce;
case 0x0c05f9d0u: goto P_0c05f9d0;
case 0x0c05f9d2u: goto P_0c05f9d2;
case 0x0c05f9d4u: goto P_0c05f9d4;
case 0x0c05f9d6u: goto P_0c05f9d6;
case 0x0c05f9d8u: goto P_0c05f9d8;
case 0x0c05f9dau: goto P_0c05f9da;
case 0x0c05f9dcu: goto P_0c05f9dc;
case 0x0c05f9deu: goto P_0c05f9de;
case 0x0c05f9e0u: goto P_0c05f9e0;
case 0x0c05f9e2u: goto P_0c05f9e2;
case 0x0c05f9e4u: goto P_0c05f9e4;
case 0x0c05f9e6u: goto P_0c05f9e6;
case 0x0c05f9e8u: goto P_0c05f9e8;
case 0x0c05f9eau: goto P_0c05f9ea;
case 0x0c05f9ecu: goto P_0c05f9ec;
case 0x0c05f9eeu: goto P_0c05f9ee;
case 0x0c05f9f0u: goto P_0c05f9f0;
case 0x0c05f9f2u: goto P_0c05f9f2;
case 0x0c05f9f4u: goto P_0c05f9f4;
case 0x0c05f9f6u: goto P_0c05f9f6;
case 0x0c05f9f8u: goto P_0c05f9f8;
case 0x0c05f9fau: goto P_0c05f9fa;
case 0x0c05f9fcu: goto P_0c05f9fc;
case 0x0c05f9feu: goto P_0c05f9fe;
case 0x0c05fa00u: goto P_0c05fa00;
case 0x0c05fa02u: goto P_0c05fa02;
case 0x0c05fa04u: goto P_0c05fa04;
case 0x0c05fa06u: goto P_0c05fa06;
case 0x0c05fa08u: goto P_0c05fa08;
case 0x0c05fa0au: goto P_0c05fa0a;
case 0x0c05fa0cu: goto P_0c05fa0c;
case 0x0c05fa0eu: goto P_0c05fa0e;
case 0x0c05fa10u: goto P_0c05fa10;
case 0x0c05fa12u: goto P_0c05fa12;
case 0x0c05fa14u: goto P_0c05fa14;
case 0x0c05fa16u: goto P_0c05fa16;
case 0x0c05fa18u: goto P_0c05fa18;
case 0x0c05fa1au: goto P_0c05fa1a;
case 0x0c05fa1cu: goto P_0c05fa1c;
case 0x0c05fa1eu: goto P_0c05fa1e;
case 0x0c05fa20u: goto P_0c05fa20;
case 0x0c05fa22u: goto P_0c05fa22;
case 0x0c05fa24u: goto P_0c05fa24;
case 0x0c05fa26u: goto P_0c05fa26;
case 0x0c05fa28u: goto P_0c05fa28;
case 0x0c05fa2au: goto P_0c05fa2a;
case 0x0c05fa2cu: goto P_0c05fa2c;
case 0x0c05fa2eu: goto P_0c05fa2e;
case 0x0c05fa30u: goto P_0c05fa30;
case 0x0c05fa32u: goto P_0c05fa32;
case 0x0c05fa34u: goto P_0c05fa34;
case 0x0c05fa36u: goto P_0c05fa36;
case 0x0c05fa38u: goto P_0c05fa38;
case 0x0c05fa3au: goto P_0c05fa3a;
case 0x0c05fa3cu: goto P_0c05fa3c;
case 0x0c05fa3eu: goto P_0c05fa3e;
case 0x0c05fa40u: goto P_0c05fa40;
case 0x0c05fa42u: goto P_0c05fa42;
case 0x0c05fa44u: goto P_0c05fa44;
case 0x0c05fa46u: goto P_0c05fa46;
case 0x0c05fa48u: goto P_0c05fa48;
case 0x0c05fa4au: goto P_0c05fa4a;
case 0x0c05fa4cu: goto P_0c05fa4c;
case 0x0c05fa4eu: goto P_0c05fa4e;
case 0x0c05fa50u: goto P_0c05fa50;
case 0x0c05fa52u: goto P_0c05fa52;
case 0x0c05fa54u: goto P_0c05fa54;
case 0x0c05fa56u: goto P_0c05fa56;
case 0x0c05fa58u: goto P_0c05fa58;
case 0x0c05fa5au: goto P_0c05fa5a;
case 0x0c05fa5cu: goto P_0c05fa5c;
case 0x0c05fa5eu: goto P_0c05fa5e;
case 0x0c05fa60u: goto P_0c05fa60;
case 0x0c05fa62u: goto P_0c05fa62;
case 0x0c05fa64u: goto P_0c05fa64;
case 0x0c05fa66u: goto P_0c05fa66;
case 0x0c05fa68u: goto P_0c05fa68;
case 0x0c05fa6au: goto P_0c05fa6a;
case 0x0c05fa6cu: goto P_0c05fa6c;
case 0x0c05fa6eu: goto P_0c05fa6e;
case 0x0c05fa70u: goto P_0c05fa70;
case 0x0c05fa72u: goto P_0c05fa72;
case 0x0c05fa74u: goto P_0c05fa74;
case 0x0c05fa76u: goto P_0c05fa76;
case 0x0c05fa78u: goto P_0c05fa78;
case 0x0c05fa7au: goto P_0c05fa7a;
case 0x0c05fa7cu: goto P_0c05fa7c;
case 0x0c05fa7eu: goto P_0c05fa7e;
case 0x0c05fa80u: goto P_0c05fa80;
case 0x0c05fa82u: goto P_0c05fa82;
case 0x0c05fa84u: goto P_0c05fa84;
case 0x0c05fa86u: goto P_0c05fa86;
case 0x0c05fa88u: goto P_0c05fa88;
case 0x0c05fa8au: goto P_0c05fa8a;
case 0x0c05fa8cu: goto P_0c05fa8c;
case 0x0c05fa8eu: goto P_0c05fa8e;
case 0x0c05fa90u: goto P_0c05fa90;
case 0x0c05fa92u: goto P_0c05fa92;
case 0x0c05fa94u: goto P_0c05fa94;
case 0x0c05fb30u: goto P_0c05fb30;
case 0x0c05fb32u: goto P_0c05fb32;
case 0x0c05fb34u: goto P_0c05fb34;
case 0x0c05fb36u: goto P_0c05fb36;
case 0x0c05fb38u: goto P_0c05fb38;
case 0x0c05fb3au: goto P_0c05fb3a;
case 0x0c05fb3cu: goto P_0c05fb3c;
case 0x0c05fb3eu: goto P_0c05fb3e;
case 0x0c05fb40u: goto P_0c05fb40;
case 0x0c05fb42u: goto P_0c05fb42;
case 0x0c05fb44u: goto P_0c05fb44;
case 0x0c05fb46u: goto P_0c05fb46;
case 0x0c05fb48u: goto P_0c05fb48;
case 0x0c05fb4au: goto P_0c05fb4a;
case 0x0c05fb4cu: goto P_0c05fb4c;
case 0x0c05fb4eu: goto P_0c05fb4e;
case 0x0c05fb50u: goto P_0c05fb50;
case 0x0c05fb52u: goto P_0c05fb52;
case 0x0c05fb54u: goto P_0c05fb54;
case 0x0c05fb56u: goto P_0c05fb56;
case 0x0c05fb58u: goto P_0c05fb58;
case 0x0c05fb5au: goto P_0c05fb5a;
case 0x0c05fb5cu: goto P_0c05fb5c;
case 0x0c05fb5eu: goto P_0c05fb5e;
case 0x0c05fb60u: goto P_0c05fb60;
case 0x0c05fb62u: goto P_0c05fb62;
case 0x0c05fb64u: goto P_0c05fb64;
case 0x0c05fb66u: goto P_0c05fb66;
case 0x0c05fb68u: goto P_0c05fb68;
case 0x0c05fb6au: goto P_0c05fb6a;
case 0x0c05fb6cu: goto P_0c05fb6c;
case 0x0c05fb6eu: goto P_0c05fb6e;
case 0x0c05fb70u: goto P_0c05fb70;
case 0x0c05fb72u: goto P_0c05fb72;
case 0x0c05fb74u: goto P_0c05fb74;
case 0x0c05fb76u: goto P_0c05fb76;
case 0x0c05fb78u: goto P_0c05fb78;
case 0x0c05fb7au: goto P_0c05fb7a;
case 0x0c05fb7cu: goto P_0c05fb7c;
case 0x0c05fb7eu: goto P_0c05fb7e;
case 0x0c05fb80u: goto P_0c05fb80;
case 0x0c05fb82u: goto P_0c05fb82;
case 0x0c05fb84u: goto P_0c05fb84;
case 0x0c05fb86u: goto P_0c05fb86;
case 0x0c05fb88u: goto P_0c05fb88;
case 0x0c05fb8au: goto P_0c05fb8a;
case 0x0c05fb8cu: goto P_0c05fb8c;
case 0x0c05fb8eu: goto P_0c05fb8e;
case 0x0c05fb90u: goto P_0c05fb90;
case 0x0c05fb92u: goto P_0c05fb92;
case 0x0c05fb94u: goto P_0c05fb94;
case 0x0c05fb96u: goto P_0c05fb96;
case 0x0c05fb98u: goto P_0c05fb98;
case 0x0c05fb9au: goto P_0c05fb9a;
case 0x0c05fb9cu: goto P_0c05fb9c;
case 0x0c05fb9eu: goto P_0c05fb9e;
case 0x0c05fba0u: goto P_0c05fba0;
case 0x0c05fba2u: goto P_0c05fba2;
case 0x0c05fba4u: goto P_0c05fba4;
case 0x0c05fba6u: goto P_0c05fba6;
case 0x0c05fba8u: goto P_0c05fba8;
case 0x0c05fbaau: goto P_0c05fbaa;
case 0x0c05fbacu: goto P_0c05fbac;
case 0x0c05fbaeu: goto P_0c05fbae;
case 0x0c05fbb0u: goto P_0c05fbb0;
case 0x0c05fbb2u: goto P_0c05fbb2;
case 0x0c05fbb4u: goto P_0c05fbb4;
case 0x0c05fbb6u: goto P_0c05fbb6;
case 0x0c05fbb8u: goto P_0c05fbb8;
case 0x0c05fbbau: goto P_0c05fbba;
case 0x0c05fbbcu: goto P_0c05fbbc;
case 0x0c05fbbeu: goto P_0c05fbbe;
case 0x0c05fbc0u: goto P_0c05fbc0;
case 0x0c05fbc2u: goto P_0c05fbc2;
case 0x0c05fbc4u: goto P_0c05fbc4;
case 0x0c05fbc6u: goto P_0c05fbc6;
case 0x0c05fbc8u: goto P_0c05fbc8;
case 0x0c05fbcau: goto P_0c05fbca;
case 0x0c05fbccu: goto P_0c05fbcc;
case 0x0c05fbceu: goto P_0c05fbce;
case 0x0c05fbd0u: goto P_0c05fbd0;
case 0x0c05fbd2u: goto P_0c05fbd2;
case 0x0c05fbd4u: goto P_0c05fbd4;
case 0x0c05fbd6u: goto P_0c05fbd6;
case 0x0c05fbd8u: goto P_0c05fbd8;
case 0x0c05fbdau: goto P_0c05fbda;
case 0x0c05fbdcu: goto P_0c05fbdc;
case 0x0c05fbdeu: goto P_0c05fbde;
case 0x0c05fbe0u: goto P_0c05fbe0;
case 0x0c05fbe2u: goto P_0c05fbe2;
case 0x0c05fbe4u: goto P_0c05fbe4;
case 0x0c05fbe6u: goto P_0c05fbe6;
case 0x0c05fbe8u: goto P_0c05fbe8;
case 0x0c05fbeau: goto P_0c05fbea;
case 0x0c05fbecu: goto P_0c05fbec;
case 0x0c05fbeeu: goto P_0c05fbee;
case 0x0c05fbf0u: goto P_0c05fbf0;
case 0x0c05fbf2u: goto P_0c05fbf2;
case 0x0c05fbf4u: goto P_0c05fbf4;
case 0x0c05fbf6u: goto P_0c05fbf6;
case 0x0c05fbf8u: goto P_0c05fbf8;
case 0x0c05fbfau: goto P_0c05fbfa;
case 0x0c05fbfcu: goto P_0c05fbfc;
case 0x0c05fbfeu: goto P_0c05fbfe;
case 0x0c05fc00u: goto P_0c05fc00;
case 0x0c05fc02u: goto P_0c05fc02;
case 0x0c05fc04u: goto P_0c05fc04;
case 0x0c05fc06u: goto P_0c05fc06;
case 0x0c05fc08u: goto P_0c05fc08;
case 0x0c05fc0au: goto P_0c05fc0a;
case 0x0c05fc0cu: goto P_0c05fc0c;
case 0x0c05fc0eu: goto P_0c05fc0e;
case 0x0c05fc10u: goto P_0c05fc10;
case 0x0c05fc12u: goto P_0c05fc12;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05ddf2: /* original 2fe6, guest PC 0x0c05ddf2 */
if(!s->budget--) { s->failed_pc=0x0c05ddf2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ddf4;
P_0c05ddf4: /* original 2fd6, guest PC 0x0c05ddf4 */
if(!s->budget--) { s->failed_pc=0x0c05ddf4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ddf6;
P_0c05ddf6: /* original 2fc6, guest PC 0x0c05ddf6 */
if(!s->budget--) { s->failed_pc=0x0c05ddf6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ddf8;
P_0c05ddf8: /* original 2fb6, guest PC 0x0c05ddf8 */
if(!s->budget--) { s->failed_pc=0x0c05ddf8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ddfa;
P_0c05ddfa: /* original 2fa6, guest PC 0x0c05ddfa */
if(!s->budget--) { s->failed_pc=0x0c05ddfau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ddfc;
P_0c05ddfc: /* original 2f96, guest PC 0x0c05ddfc */
if(!s->budget--) { s->failed_pc=0x0c05ddfcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ddfe;
P_0c05ddfe: /* original 4f22, guest PC 0x0c05ddfe */
if(!s->budget--) { s->failed_pc=0x0c05ddfeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05de00;
P_0c05de00: /* original d217, guest PC 0x0c05de00 */
if(!s->budget--) { s->failed_pc=0x0c05de00u; return 0; }
r[2]=read(ram,0x0c05de60u,4);
goto P_0c05de02;
P_0c05de02: /* original 7fe0, guest PC 0x0c05de02 */
if(!s->budget--) { s->failed_pc=0x0c05de02u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c05de04;
P_0c05de04: /* original d317, guest PC 0x0c05de04 */
if(!s->budget--) { s->failed_pc=0x0c05de04u; return 0; }
r[3]=read(ram,0x0c05de64u,4);
goto P_0c05de06;
P_0c05de06: /* original 61f3, guest PC 0x0c05de06 */
if(!s->budget--) { s->failed_pc=0x0c05de06u; return 0; }
r[1]=r[15];
goto P_0c05de08;
P_0c05de08: /* original 2f42, guest PC 0x0c05de08 */
if(!s->budget--) { s->failed_pc=0x0c05de08u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05de0a;
P_0c05de0a: /* original 7108, guest PC 0x0c05de0a */
if(!s->budget--) { s->failed_pc=0x0c05de0au; return 0; }
r[1]+=0x00000008u;
goto P_0c05de0c;
P_0c05de0c: /* original 1f51, guest PC 0x0c05de0c */
if(!s->budget--) { s->failed_pc=0x0c05de0cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c05de0e;
P_0c05de0e: /* original 430b, guest PC 0x0c05de0e */
if(!s->budget--) { s->failed_pc=0x0c05de0eu; return 0; }
target=r[3];
r[16]=code_base|0x0c05de12u;
r[0]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05de12u) { target=s->pc; goto dispatch; }
goto P_0c05de12;
P_0c05de10: /* original e018, guest PC 0x0c05de10 */
if(!s->budget--) { s->failed_pc=0x0c05de10u; return 0; }
r[0]=0x00000018u;
goto P_0c05de12;
P_0c05de12: /* original d115, guest PC 0x0c05de12 */
if(!s->budget--) { s->failed_pc=0x0c05de12u; return 0; }
r[1]=read(ram,0x0c05de68u,4);
goto P_0c05de14;
P_0c05de14: /* original 410b, guest PC 0x0c05de14 */
if(!s->budget--) { s->failed_pc=0x0c05de14u; return 0; }
target=r[1];
r[16]=code_base|0x0c05de18u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05de18u) { target=s->pc; goto dispatch; }
goto P_0c05de18;
P_0c05de16: /* original 0009, guest PC 0x0c05de16 */
if(!s->budget--) { s->failed_pc=0x0c05de16u; return 0; }
goto P_0c05de18;
P_0c05de18: /* original 52f1, guest PC 0x0c05de18 */
if(!s->budget--) { s->failed_pc=0x0c05de18u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c05de1a;
P_0c05de1a: /* original 2228, guest PC 0x0c05de1a */
if(!s->budget--) { s->failed_pc=0x0c05de1au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05de1c;
P_0c05de1c: /* original 8901, guest PC 0x0c05de1c */
if(!s->budget--) { s->failed_pc=0x0c05de1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05de22; }
goto P_0c05de1e;
P_0c05de1e: /* original a001, guest PC 0x0c05de1e */
if(!s->budget--) { s->failed_pc=0x0c05de1eu; return 0; }
r[11]=0x00000001u;
goto P_0c05de24;
P_0c05de20: /* original eb01, guest PC 0x0c05de20 */
if(!s->budget--) { s->failed_pc=0x0c05de20u; return 0; }
r[11]=0x00000001u;
goto P_0c05de22;
P_0c05de22: /* original eb00, guest PC 0x0c05de22 */
if(!s->budget--) { s->failed_pc=0x0c05de22u; return 0; }
r[11]=0x00000000u;
goto P_0c05de24;
P_0c05de24: /* original 62f2, guest PC 0x0c05de24 */
if(!s->budget--) { s->failed_pc=0x0c05de24u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05de26;
P_0c05de26: /* original 2228, guest PC 0x0c05de26 */
if(!s->budget--) { s->failed_pc=0x0c05de26u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05de28;
P_0c05de28: /* original 8920, guest PC 0x0c05de28 */
if(!s->budget--) { s->failed_pc=0x0c05de28u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05de6c; }
goto P_0c05de2a;
P_0c05de2a: /* original a020, guest PC 0x0c05de2a */
if(!s->budget--) { s->failed_pc=0x0c05de2au; return 0; }
r[12]=0x00000001u;
goto P_0c05de6e;
P_0c05de2c: /* original ec01, guest PC 0x0c05de2c */
if(!s->budget--) { s->failed_pc=0x0c05de2cu; return 0; }
r[12]=0x00000001u;
if(!vf3_matrix_family(0x0c05de2eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05de2eu; return 0; } return 1;
P_0c05de6c: /* original ec00, guest PC 0x0c05de6c */
if(!s->budget--) { s->failed_pc=0x0c05de6cu; return 0; }
r[12]=0x00000000u;
goto P_0c05de6e;
P_0c05de6e: /* original d238, guest PC 0x0c05de6e */
if(!s->budget--) { s->failed_pc=0x0c05de6eu; return 0; }
r[2]=read(ram,0x0c05df50u,4);
goto P_0c05de70;
P_0c05de70: /* original 22c2, guest PC 0x0c05de70 */
if(!s->budget--) { s->failed_pc=0x0c05de70u; return 0; }
write(ram,r[2],r[12],4);
goto P_0c05de72;
P_0c05de72: /* original d338, guest PC 0x0c05de72 */
if(!s->budget--) { s->failed_pc=0x0c05de72u; return 0; }
r[3]=read(ram,0x0c05df54u,4);
goto P_0c05de74;
P_0c05de74: /* original 23b2, guest PC 0x0c05de74 */
if(!s->budget--) { s->failed_pc=0x0c05de74u; return 0; }
write(ram,r[3],r[11],4);
goto P_0c05de76;
P_0c05de76: /* original d138, guest PC 0x0c05de76 */
if(!s->budget--) { s->failed_pc=0x0c05de76u; return 0; }
r[1]=read(ram,0x0c05df58u,4);
goto P_0c05de78;
P_0c05de78: /* original 6012, guest PC 0x0c05de78 */
if(!s->budget--) { s->failed_pc=0x0c05de78u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05de7a;
P_0c05de7a: /* original 8801, guest PC 0x0c05de7a */
if(!s->budget--) { s->failed_pc=0x0c05de7au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05de7c;
P_0c05de7c: /* original 8f04, guest PC 0x0c05de7c */
if(!s->budget--) { s->failed_pc=0x0c05de7cu; return 0; }
cond=r[17]&1u;
r[9]=0x00000001u;
if(!cond) { goto P_0c05de88; }
goto P_0c05de80;
P_0c05de7e: /* original e901, guest PC 0x0c05de7e */
if(!s->budget--) { s->failed_pc=0x0c05de7eu; return 0; }
r[9]=0x00000001u;
goto P_0c05de80;
P_0c05de80: /* original 9d61, guest PC 0x0c05de80 */
if(!s->budget--) { s->failed_pc=0x0c05de80u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05df46u,2);
goto P_0c05de82;
P_0c05de82: /* original 9e61, guest PC 0x0c05de82 */
if(!s->budget--) { s->failed_pc=0x0c05de82u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05df48u,2);
goto P_0c05de84;
P_0c05de84: /* original a01e, guest PC 0x0c05de84 */
if(!s->budget--) { s->failed_pc=0x0c05de84u; return 0; }
r[10]=0x00000000u;
goto P_0c05dec4;
P_0c05de86: /* original ea00, guest PC 0x0c05de86 */
if(!s->budget--) { s->failed_pc=0x0c05de86u; return 0; }
r[10]=0x00000000u;
goto P_0c05de88;
P_0c05de88: /* original d233, guest PC 0x0c05de88 */
if(!s->budget--) { s->failed_pc=0x0c05de88u; return 0; }
r[2]=read(ram,0x0c05df58u,4);
goto P_0c05de8a;
P_0c05de8a: /* original 6022, guest PC 0x0c05de8a */
if(!s->budget--) { s->failed_pc=0x0c05de8au; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05de8c;
P_0c05de8c: /* original 2099, guest PC 0x0c05de8c */
if(!s->budget--) { s->failed_pc=0x0c05de8cu; return 0; }
r[0]&=r[9];
goto P_0c05de8e;
P_0c05de8e: /* original 8801, guest PC 0x0c05de8e */
if(!s->budget--) { s->failed_pc=0x0c05de8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05de90;
P_0c05de90: /* original 8907, guest PC 0x0c05de90 */
if(!s->budget--) { s->failed_pc=0x0c05de90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dea2; }
goto P_0c05de92;
P_0c05de92: /* original d331, guest PC 0x0c05de92 */
if(!s->budget--) { s->failed_pc=0x0c05de92u; return 0; }
r[3]=read(ram,0x0c05df58u,4);
goto P_0c05de94;
P_0c05de94: /* original 6032, guest PC 0x0c05de94 */
if(!s->budget--) { s->failed_pc=0x0c05de94u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05de96;
P_0c05de96: /* original c82c, guest PC 0x0c05de96 */
if(!s->budget--) { s->failed_pc=0x0c05de96u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c05de98;
P_0c05de98: /* original 8903, guest PC 0x0c05de98 */
if(!s->budget--) { s->failed_pc=0x0c05de98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dea2; }
goto P_0c05de9a;
P_0c05de9a: /* original 2998, guest PC 0x0c05de9a */
if(!s->budget--) { s->failed_pc=0x0c05de9au; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c05de9c;
P_0c05de9c: /* original 8901, guest PC 0x0c05de9c */
if(!s->budget--) { s->failed_pc=0x0c05de9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dea2; }
goto P_0c05de9e;
P_0c05de9e: /* original a001, guest PC 0x0c05de9e */
if(!s->budget--) { s->failed_pc=0x0c05de9eu; return 0; }
r[10]=0x00000001u;
goto P_0c05dea4;
P_0c05dea0: /* original ea01, guest PC 0x0c05dea0 */
if(!s->budget--) { s->failed_pc=0x0c05dea0u; return 0; }
r[10]=0x00000001u;
goto P_0c05dea2;
P_0c05dea2: /* original ea00, guest PC 0x0c05dea2 */
if(!s->budget--) { s->failed_pc=0x0c05dea2u; return 0; }
r[10]=0x00000000u;
goto P_0c05dea4;
P_0c05dea4: /* original d22c, guest PC 0x0c05dea4 */
if(!s->budget--) { s->failed_pc=0x0c05dea4u; return 0; }
r[2]=read(ram,0x0c05df58u,4);
goto P_0c05dea6;
P_0c05dea6: /* original 6022, guest PC 0x0c05dea6 */
if(!s->budget--) { s->failed_pc=0x0c05dea6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05dea8;
P_0c05dea8: /* original c810, guest PC 0x0c05dea8 */
if(!s->budget--) { s->failed_pc=0x0c05dea8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c05deaa;
P_0c05deaa: /* original 8902, guest PC 0x0c05deaa */
if(!s->budget--) { s->failed_pc=0x0c05deaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05deb2; }
goto P_0c05deac;
P_0c05deac: /* original 9d4b, guest PC 0x0c05deac */
if(!s->budget--) { s->failed_pc=0x0c05deacu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05df46u,2);
goto P_0c05deae;
P_0c05deae: /* original a001, guest PC 0x0c05deae */
if(!s->budget--) { s->failed_pc=0x0c05deaeu; return 0; }
goto P_0c05deb4;
P_0c05deb0: /* original 0009, guest PC 0x0c05deb0 */
if(!s->budget--) { s->failed_pc=0x0c05deb0u; return 0; }
goto P_0c05deb2;
P_0c05deb2: /* original 9d4a, guest PC 0x0c05deb2 */
if(!s->budget--) { s->failed_pc=0x0c05deb2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05df4au,2);
goto P_0c05deb4;
P_0c05deb4: /* original d328, guest PC 0x0c05deb4 */
if(!s->budget--) { s->failed_pc=0x0c05deb4u; return 0; }
r[3]=read(ram,0x0c05df58u,4);
goto P_0c05deb6;
P_0c05deb6: /* original 6032, guest PC 0x0c05deb6 */
if(!s->budget--) { s->failed_pc=0x0c05deb6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05deb8;
P_0c05deb8: /* original c820, guest PC 0x0c05deb8 */
if(!s->budget--) { s->failed_pc=0x0c05deb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05deba;
P_0c05deba: /* original 8902, guest PC 0x0c05deba */
if(!s->budget--) { s->failed_pc=0x0c05debau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dec2; }
goto P_0c05debc;
P_0c05debc: /* original 9e44, guest PC 0x0c05debc */
if(!s->budget--) { s->failed_pc=0x0c05debcu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05df48u,2);
goto P_0c05debe;
P_0c05debe: /* original a001, guest PC 0x0c05debe */
if(!s->budget--) { s->failed_pc=0x0c05debeu; return 0; }
goto P_0c05dec4;
P_0c05dec0: /* original 0009, guest PC 0x0c05dec0 */
if(!s->budget--) { s->failed_pc=0x0c05dec0u; return 0; }
goto P_0c05dec2;
P_0c05dec2: /* original 9e43, guest PC 0x0c05dec2 */
if(!s->budget--) { s->failed_pc=0x0c05dec2u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05df4cu,2);
goto P_0c05dec4;
P_0c05dec4: /* original be6a, guest PC 0x0c05dec4 */
if(!s->budget--) { s->failed_pc=0x0c05dec4u; return 0; }
target=code_base|0x0c05db9cu; r[16]=code_base|0x0c05dec8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dec8u) { target=s->pc; goto dispatch; }
goto P_0c05dec8;
P_0c05dec6: /* original 0009, guest PC 0x0c05dec6 */
if(!s->budget--) { s->failed_pc=0x0c05dec6u; return 0; }
goto P_0c05dec8;
P_0c05dec8: /* original 2fb6, guest PC 0x0c05dec8 */
if(!s->budget--) { s->failed_pc=0x0c05dec8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05deca;
P_0c05deca: /* original 67a3, guest PC 0x0c05deca */
if(!s->budget--) { s->failed_pc=0x0c05decau; return 0; }
r[7]=r[10];
goto P_0c05decc;
P_0c05decc: /* original d223, guest PC 0x0c05decc */
if(!s->budget--) { s->failed_pc=0x0c05deccu; return 0; }
r[2]=read(ram,0x0c05df5cu,4);
goto P_0c05dece;
P_0c05dece: /* original 2fc6, guest PC 0x0c05dece */
if(!s->budget--) { s->failed_pc=0x0c05deceu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ded0;
P_0c05ded0: /* original 6622, guest PC 0x0c05ded0 */
if(!s->budget--) { s->failed_pc=0x0c05ded0u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c05ded2;
P_0c05ded2: /* original 65e3, guest PC 0x0c05ded2 */
if(!s->budget--) { s->failed_pc=0x0c05ded2u; return 0; }
r[5]=r[14];
goto P_0c05ded4;
P_0c05ded4: /* original d322, guest PC 0x0c05ded4 */
if(!s->budget--) { s->failed_pc=0x0c05ded4u; return 0; }
r[3]=read(ram,0x0c05df60u,4);
goto P_0c05ded6;
P_0c05ded6: /* original 430b, guest PC 0x0c05ded6 */
if(!s->budget--) { s->failed_pc=0x0c05ded6u; return 0; }
target=r[3];
r[16]=code_base|0x0c05dedau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dedau) { target=s->pc; goto dispatch; }
goto P_0c05deda;
P_0c05ded8: /* original 64d3, guest PC 0x0c05ded8 */
if(!s->budget--) { s->failed_pc=0x0c05ded8u; return 0; }
r[4]=r[13];
goto P_0c05deda;
P_0c05deda: /* original be31, guest PC 0x0c05deda */
if(!s->budget--) { s->failed_pc=0x0c05dedau; return 0; }
target=code_base|0x0c05db40u; r[16]=code_base|0x0c05dedeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dedeu) { target=s->pc; goto dispatch; }
goto P_0c05dede;
P_0c05dedc: /* original 0009, guest PC 0x0c05dedc */
if(!s->budget--) { s->failed_pc=0x0c05dedcu; return 0; }
goto P_0c05dede;
P_0c05dede: /* original e3fe, guest PC 0x0c05dede */
if(!s->budget--) { s->failed_pc=0x0c05dedeu; return 0; }
r[3]=0xfffffffeu;
goto P_0c05dee0;
P_0c05dee0: /* original d221, guest PC 0x0c05dee0 */
if(!s->budget--) { s->failed_pc=0x0c05dee0u; return 0; }
r[2]=read(ram,0x0c05df68u,4);
goto P_0c05dee2;
P_0c05dee2: /* original de20, guest PC 0x0c05dee2 */
if(!s->budget--) { s->failed_pc=0x0c05dee2u; return 0; }
r[14]=read(ram,0x0c05df64u,4);
goto P_0c05dee4;
P_0c05dee4: /* original 6522, guest PC 0x0c05dee4 */
if(!s->budget--) { s->failed_pc=0x0c05dee4u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05dee6;
P_0c05dee6: /* original 2539, guest PC 0x0c05dee6 */
if(!s->budget--) { s->failed_pc=0x0c05dee6u; return 0; }
r[5]&=r[3];
goto P_0c05dee8;
P_0c05dee8: /* original 4e0b, guest PC 0x0c05dee8 */
if(!s->budget--) { s->failed_pc=0x0c05dee8u; return 0; }
target=r[14];
r[16]=code_base|0x0c05deecu;
r[4]=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05deecu) { target=s->pc; goto dispatch; }
goto P_0c05deec;
P_0c05deea: /* original e444, guest PC 0x0c05deea */
if(!s->budget--) { s->failed_pc=0x0c05deeau; return 0; }
r[4]=0x00000044u;
goto P_0c05deec;
P_0c05deec: /* original d31f, guest PC 0x0c05deec */
if(!s->budget--) { s->failed_pc=0x0c05deecu; return 0; }
r[3]=read(ram,0x0c05df6cu,4);
goto P_0c05deee;
P_0c05deee: /* original 942e, guest PC 0x0c05deee */
if(!s->budget--) { s->failed_pc=0x0c05deeeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05df4eu,2);
goto P_0c05def0;
P_0c05def0: /* original 4e0b, guest PC 0x0c05def0 */
if(!s->budget--) { s->failed_pc=0x0c05def0u; return 0; }
target=r[14];
r[16]=code_base|0x0c05def4u;
tmp=read(ram,r[3],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05def4u) { target=s->pc; goto dispatch; }
goto P_0c05def4;
P_0c05def2: /* original 6532, guest PC 0x0c05def2 */
if(!s->budget--) { s->failed_pc=0x0c05def2u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05def4;
P_0c05def4: /* original d21c, guest PC 0x0c05def4 */
if(!s->budget--) { s->failed_pc=0x0c05def4u; return 0; }
r[2]=read(ram,0x0c05df68u,4);
goto P_0c05def6;
P_0c05def6: /* original 6522, guest PC 0x0c05def6 */
if(!s->budget--) { s->failed_pc=0x0c05def6u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05def8;
P_0c05def8: /* original 4e0b, guest PC 0x0c05def8 */
if(!s->budget--) { s->failed_pc=0x0c05def8u; return 0; }
target=r[14];
r[16]=code_base|0x0c05defcu;
r[4]=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05defcu) { target=s->pc; goto dispatch; }
goto P_0c05defc;
P_0c05defa: /* original e444, guest PC 0x0c05defa */
if(!s->budget--) { s->failed_pc=0x0c05defau; return 0; }
r[4]=0x00000044u;
goto P_0c05defc;
P_0c05defc: /* original d31c, guest PC 0x0c05defc */
if(!s->budget--) { s->failed_pc=0x0c05defcu; return 0; }
r[3]=read(ram,0x0c05df70u,4);
goto P_0c05defe;
P_0c05defe: /* original 430b, guest PC 0x0c05defe */
if(!s->budget--) { s->failed_pc=0x0c05defeu; return 0; }
target=r[3];
r[16]=code_base|0x0c05df02u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05df02u) { target=s->pc; goto dispatch; }
goto P_0c05df02;
P_0c05df00: /* original 0009, guest PC 0x0c05df00 */
if(!s->budget--) { s->failed_pc=0x0c05df00u; return 0; }
goto P_0c05df02;
P_0c05df02: /* original e200, guest PC 0x0c05df02 */
if(!s->budget--) { s->failed_pc=0x0c05df02u; return 0; }
r[2]=0x00000000u;
goto P_0c05df04;
P_0c05df04: /* original d11b, guest PC 0x0c05df04 */
if(!s->budget--) { s->failed_pc=0x0c05df04u; return 0; }
r[1]=read(ram,0x0c05df74u,4);
goto P_0c05df06;
P_0c05df06: /* original 2f26, guest PC 0x0c05df06 */
if(!s->budget--) { s->failed_pc=0x0c05df06u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05df08;
P_0c05df08: /* original 6312, guest PC 0x0c05df08 */
if(!s->budget--) { s->failed_pc=0x0c05df08u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c05df0a;
P_0c05df0a: /* original 2f36, guest PC 0x0c05df0a */
if(!s->budget--) { s->failed_pc=0x0c05df0au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05df0c;
P_0c05df0c: /* original d71a, guest PC 0x0c05df0c */
if(!s->budget--) { s->failed_pc=0x0c05df0cu; return 0; }
r[7]=read(ram,0x0c05df78u,4);
goto P_0c05df0e;
P_0c05df0e: /* original 5773, guest PC 0x0c05df0e */
if(!s->budget--) { s->failed_pc=0x0c05df0eu; return 0; }
r[7]=read(ram,r[7]+12,4);
goto P_0c05df10;
P_0c05df10: /* original e3f9, guest PC 0x0c05df10 */
if(!s->budget--) { s->failed_pc=0x0c05df10u; return 0; }
r[3]=0xfffffff9u;
goto P_0c05df12;
P_0c05df12: /* original 473d, guest PC 0x0c05df12 */
if(!s->budget--) { s->failed_pc=0x0c05df12u; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?r[7]>>((-r[3])&31u):0):r[7]<<(r[3]&31u);
goto P_0c05df14;
P_0c05df14: /* original d618, guest PC 0x0c05df14 */
if(!s->budget--) { s->failed_pc=0x0c05df14u; return 0; }
r[6]=read(ram,0x0c05df78u,4);
goto P_0c05df16;
P_0c05df16: /* original 5662, guest PC 0x0c05df16 */
if(!s->budget--) { s->failed_pc=0x0c05df16u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c05df18;
P_0c05df18: /* original 463d, guest PC 0x0c05df18 */
if(!s->budget--) { s->failed_pc=0x0c05df18u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?r[6]>>((-r[3])&31u):0):r[6]<<(r[3]&31u);
goto P_0c05df1a;
P_0c05df1a: /* original d517, guest PC 0x0c05df1a */
if(!s->budget--) { s->failed_pc=0x0c05df1au; return 0; }
r[5]=read(ram,0x0c05df78u,4);
goto P_0c05df1c;
P_0c05df1c: /* original 5551, guest PC 0x0c05df1c */
if(!s->budget--) { s->failed_pc=0x0c05df1cu; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c05df1e;
P_0c05df1e: /* original 453d, guest PC 0x0c05df1e */
if(!s->budget--) { s->failed_pc=0x0c05df1eu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c05df20;
P_0c05df20: /* original d415, guest PC 0x0c05df20 */
if(!s->budget--) { s->failed_pc=0x0c05df20u; return 0; }
r[4]=read(ram,0x0c05df78u,4);
goto P_0c05df22;
P_0c05df22: /* original 6442, guest PC 0x0c05df22 */
if(!s->budget--) { s->failed_pc=0x0c05df22u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05df24;
P_0c05df24: /* original 443d, guest PC 0x0c05df24 */
if(!s->budget--) { s->failed_pc=0x0c05df24u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c05df26;
P_0c05df26: /* original d315, guest PC 0x0c05df26 */
if(!s->budget--) { s->failed_pc=0x0c05df26u; return 0; }
r[3]=read(ram,0x0c05df7cu,4);
goto P_0c05df28;
P_0c05df28: /* original 430b, guest PC 0x0c05df28 */
if(!s->budget--) { s->failed_pc=0x0c05df28u; return 0; }
target=r[3];
r[16]=code_base|0x0c05df2cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05df2cu) { target=s->pc; goto dispatch; }
goto P_0c05df2c;
P_0c05df2a: /* original 0009, guest PC 0x0c05df2a */
if(!s->budget--) { s->failed_pc=0x0c05df2au; return 0; }
goto P_0c05df2c;
P_0c05df2c: /* original d214, guest PC 0x0c05df2c */
if(!s->budget--) { s->failed_pc=0x0c05df2cu; return 0; }
r[2]=read(ram,0x0c05df80u,4);
goto P_0c05df2e;
P_0c05df2e: /* original be35, guest PC 0x0c05df2e */
if(!s->budget--) { s->failed_pc=0x0c05df2eu; return 0; }
target=code_base|0x0c05db9cu; r[16]=code_base|0x0c05df32u;
write(ram,r[2],r[9],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05df32u) { target=s->pc; goto dispatch; }
goto P_0c05df32;
P_0c05df30: /* original 2292, guest PC 0x0c05df30 */
if(!s->budget--) { s->failed_pc=0x0c05df30u; return 0; }
write(ram,r[2],r[9],4);
goto P_0c05df32;
P_0c05df32: /* original e000, guest PC 0x0c05df32 */
if(!s->budget--) { s->failed_pc=0x0c05df32u; return 0; }
r[0]=0x00000000u;
goto P_0c05df34;
P_0c05df34: /* original 7f30, guest PC 0x0c05df34 */
if(!s->budget--) { s->failed_pc=0x0c05df34u; return 0; }
r[15]+=0x00000030u;
goto P_0c05df36;
P_0c05df36: /* original 4f26, guest PC 0x0c05df36 */
if(!s->budget--) { s->failed_pc=0x0c05df36u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05df38;
P_0c05df38: /* original 69f6, guest PC 0x0c05df38 */
if(!s->budget--) { s->failed_pc=0x0c05df38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05df3a;
P_0c05df3a: /* original 6af6, guest PC 0x0c05df3a */
if(!s->budget--) { s->failed_pc=0x0c05df3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05df3c;
P_0c05df3c: /* original 6bf6, guest PC 0x0c05df3c */
if(!s->budget--) { s->failed_pc=0x0c05df3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05df3e;
P_0c05df3e: /* original 6cf6, guest PC 0x0c05df3e */
if(!s->budget--) { s->failed_pc=0x0c05df3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05df40;
P_0c05df40: /* original 6df6, guest PC 0x0c05df40 */
if(!s->budget--) { s->failed_pc=0x0c05df40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05df42;
P_0c05df42: /* original 000b, guest PC 0x0c05df42 */
if(!s->budget--) { s->failed_pc=0x0c05df42u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05df44: /* original 6ef6, guest PC 0x0c05df44 */
if(!s->budget--) { s->failed_pc=0x0c05df44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05df46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05df46u; return 0; } return 1;
P_0c05e1d2: /* original 2fe6, guest PC 0x0c05e1d2 */
if(!s->budget--) { s->failed_pc=0x0c05e1d2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e1d4;
P_0c05e1d4: /* original 2fd6, guest PC 0x0c05e1d4 */
if(!s->budget--) { s->failed_pc=0x0c05e1d4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e1d6;
P_0c05e1d6: /* original 2fc6, guest PC 0x0c05e1d6 */
if(!s->budget--) { s->failed_pc=0x0c05e1d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e1d8;
P_0c05e1d8: /* original 2fb6, guest PC 0x0c05e1d8 */
if(!s->budget--) { s->failed_pc=0x0c05e1d8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e1da;
P_0c05e1da: /* original 2fa6, guest PC 0x0c05e1da */
if(!s->budget--) { s->failed_pc=0x0c05e1dau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e1dc;
P_0c05e1dc: /* original 2f96, guest PC 0x0c05e1dc */
if(!s->budget--) { s->failed_pc=0x0c05e1dcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e1de;
P_0c05e1de: /* original 6a43, guest PC 0x0c05e1de */
if(!s->budget--) { s->failed_pc=0x0c05e1deu; return 0; }
r[10]=r[4];
goto P_0c05e1e0;
P_0c05e1e0: /* original 9e4d, guest PC 0x0c05e1e0 */
if(!s->budget--) { s->failed_pc=0x0c05e1e0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e27eu,2);
goto P_0c05e1e2;
P_0c05e1e2: /* original fffb, guest PC 0x0c05e1e2 */
if(!s->budget--) { s->failed_pc=0x0c05e1e2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c05e1e4;
P_0c05e1e4: /* original c72f, guest PC 0x0c05e1e4 */
if(!s->budget--) { s->failed_pc=0x0c05e1e4u; return 0; }
r[0]=code_base|0x0005e2a4u;
goto P_0c05e1e6;
P_0c05e1e6: /* original 6ce3, guest PC 0x0c05e1e6 */
if(!s->budget--) { s->failed_pc=0x0c05e1e6u; return 0; }
r[12]=r[14];
goto P_0c05e1e8;
P_0c05e1e8: /* original d92c, guest PC 0x0c05e1e8 */
if(!s->budget--) { s->failed_pc=0x0c05e1e8u; return 0; }
r[9]=read(ram,0x0c05e29cu,4);
goto P_0c05e1ea;
P_0c05e1ea: /* original 7c7f, guest PC 0x0c05e1ea */
if(!s->budget--) { s->failed_pc=0x0c05e1eau; return 0; }
r[12]+=0x0000007fu;
goto P_0c05e1ec;
P_0c05e1ec: /* original 9b49, guest PC 0x0c05e1ec */
if(!s->budget--) { s->failed_pc=0x0c05e1ecu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e282u,2);
goto P_0c05e1ee;
P_0c05e1ee: /* original 4f22, guest PC 0x0c05e1ee */
if(!s->budget--) { s->failed_pc=0x0c05e1eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e1f0;
P_0c05e1f0: /* original ff08, guest PC 0x0c05e1f0 */
if(!s->budget--) { s->failed_pc=0x0c05e1f0u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c05e1f2;
P_0c05e1f2: /* original 9045, guest PC 0x0c05e1f2 */
if(!s->budget--) { s->failed_pc=0x0c05e1f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e280u,2);
goto P_0c05e1f4;
P_0c05e1f4: /* original f3a6, guest PC 0x0c05e1f4 */
if(!s->budget--) { s->failed_pc=0x0c05e1f4u; return 0; }
vf3_matrix_load(s,ram,3,r[10]+r[0]);
goto P_0c05e1f6;
P_0c05e1f6: /* original f23c, guest PC 0x0c05e1f6 */
if(!s->budget--) { s->failed_pc=0x0c05e1f6u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c05e1f8;
P_0c05e1f8: /* original f2f2, guest PC 0x0c05e1f8 */
if(!s->budget--) { s->failed_pc=0x0c05e1f8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'*');
goto P_0c05e1fa;
P_0c05e1fa: /* original f23d, guest PC 0x0c05e1fa */
if(!s->budget--) { s->failed_pc=0x0c05e1fau; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c05e1fc;
P_0c05e1fc: /* original 0d5a, guest PC 0x0c05e1fc */
if(!s->budget--) { s->failed_pc=0x0c05e1fcu; return 0; }
r[13]=r[53];
goto P_0c05e1fe;
P_0c05e1fe: /* original 2dc9, guest PC 0x0c05e1fe */
if(!s->budget--) { s->failed_pc=0x0c05e1feu; return 0; }
r[13]&=r[12];
goto P_0c05e200;
P_0c05e200: /* original 7eff, guest PC 0x0c05e200 */
if(!s->budget--) { s->failed_pc=0x0c05e200u; return 0; }
r[14]+=0xffffffffu;
goto P_0c05e202;
P_0c05e202: /* original 64d3, guest PC 0x0c05e202 */
if(!s->budget--) { s->failed_pc=0x0c05e202u; return 0; }
r[4]=r[13];
goto P_0c05e204;
P_0c05e204: /* original 60e3, guest PC 0x0c05e204 */
if(!s->budget--) { s->failed_pc=0x0c05e204u; return 0; }
r[0]=r[14];
goto P_0c05e206;
P_0c05e206: /* original 0009, guest PC 0x0c05e206 */
if(!s->budget--) { s->failed_pc=0x0c05e206u; return 0; }
goto P_0c05e208;
P_0c05e208: /* original 4008, guest PC 0x0c05e208 */
if(!s->budget--) { s->failed_pc=0x0c05e208u; return 0; }
r[0]<<=2;
goto P_0c05e20a;
P_0c05e20a: /* original f2a6, guest PC 0x0c05e20a */
if(!s->budget--) { s->failed_pc=0x0c05e20au; return 0; }
vf3_matrix_load(s,ram,2,r[10]+r[0]);
goto P_0c05e20c;
P_0c05e20c: /* original f2f2, guest PC 0x0c05e20c */
if(!s->budget--) { s->failed_pc=0x0c05e20cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'*');
goto P_0c05e20e;
P_0c05e20e: /* original f23d, guest PC 0x0c05e20e */
if(!s->budget--) { s->failed_pc=0x0c05e20eu; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c05e210;
P_0c05e210: /* original 0d5a, guest PC 0x0c05e210 */
if(!s->budget--) { s->failed_pc=0x0c05e210u; return 0; }
r[13]=r[53];
goto P_0c05e212;
P_0c05e212: /* original 2dc9, guest PC 0x0c05e212 */
if(!s->budget--) { s->failed_pc=0x0c05e212u; return 0; }
r[13]&=r[12];
goto P_0c05e214;
P_0c05e214: /* original 65d3, guest PC 0x0c05e214 */
if(!s->budget--) { s->failed_pc=0x0c05e214u; return 0; }
r[5]=r[13];
goto P_0c05e216;
P_0c05e216: /* original 4518, guest PC 0x0c05e216 */
if(!s->budget--) { s->failed_pc=0x0c05e216u; return 0; }
r[5]<<=8;
goto P_0c05e218;
P_0c05e218: /* original 254b, guest PC 0x0c05e218 */
if(!s->budget--) { s->failed_pc=0x0c05e218u; return 0; }
r[5]|=r[4];
goto P_0c05e21a;
P_0c05e21a: /* original 655d, guest PC 0x0c05e21a */
if(!s->budget--) { s->failed_pc=0x0c05e21au; return 0; }
r[5]=r[5]&65535u;
goto P_0c05e21c;
P_0c05e21c: /* original 64e3, guest PC 0x0c05e21c */
if(!s->budget--) { s->failed_pc=0x0c05e21cu; return 0; }
r[4]=r[14];
goto P_0c05e21e;
P_0c05e21e: /* original 4408, guest PC 0x0c05e21e */
if(!s->budget--) { s->failed_pc=0x0c05e21eu; return 0; }
r[4]<<=2;
goto P_0c05e220;
P_0c05e220: /* original 490b, guest PC 0x0c05e220 */
if(!s->budget--) { s->failed_pc=0x0c05e220u; return 0; }
target=r[9];
r[16]=code_base|0x0c05e224u;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e224u) { target=s->pc; goto dispatch; }
goto P_0c05e224;
P_0c05e222: /* original 34bc, guest PC 0x0c05e222 */
if(!s->budget--) { s->failed_pc=0x0c05e222u; return 0; }
r[4]+=r[11];
goto P_0c05e224;
P_0c05e224: /* original 2ee8, guest PC 0x0c05e224 */
if(!s->budget--) { s->failed_pc=0x0c05e224u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c05e226;
P_0c05e226: /* original 8beb, guest PC 0x0c05e226 */
if(!s->budget--) { s->failed_pc=0x0c05e226u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e200; }
goto P_0c05e228;
P_0c05e228: /* original 4f26, guest PC 0x0c05e228 */
if(!s->budget--) { s->failed_pc=0x0c05e228u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e22a;
P_0c05e22a: /* original e000, guest PC 0x0c05e22a */
if(!s->budget--) { s->failed_pc=0x0c05e22au; return 0; }
r[0]=0x00000000u;
goto P_0c05e22c;
P_0c05e22c: /* original fff9, guest PC 0x0c05e22c */
if(!s->budget--) { s->failed_pc=0x0c05e22cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c05e22e;
P_0c05e22e: /* original 69f6, guest PC 0x0c05e22e */
if(!s->budget--) { s->failed_pc=0x0c05e22eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05e230;
P_0c05e230: /* original 6af6, guest PC 0x0c05e230 */
if(!s->budget--) { s->failed_pc=0x0c05e230u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05e232;
P_0c05e232: /* original 6bf6, guest PC 0x0c05e232 */
if(!s->budget--) { s->failed_pc=0x0c05e232u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05e234;
P_0c05e234: /* original 6cf6, guest PC 0x0c05e234 */
if(!s->budget--) { s->failed_pc=0x0c05e234u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05e236;
P_0c05e236: /* original 6df6, guest PC 0x0c05e236 */
if(!s->budget--) { s->failed_pc=0x0c05e236u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05e238;
P_0c05e238: /* original 000b, guest PC 0x0c05e238 */
if(!s->budget--) { s->failed_pc=0x0c05e238u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e23a: /* original 6ef6, guest PC 0x0c05e23a */
if(!s->budget--) { s->failed_pc=0x0c05e23au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05e23cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e23cu; return 0; } return 1;
P_0c05f964: /* original 000b, guest PC 0x0c05f964 */
if(!s->budget--) { s->failed_pc=0x0c05f964u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05f966: /* original e000, guest PC 0x0c05f966 */
if(!s->budget--) { s->failed_pc=0x0c05f966u; return 0; }
r[0]=0x00000000u;
goto P_0c05f968;
P_0c05f968: /* original 2fe6, guest PC 0x0c05f968 */
if(!s->budget--) { s->failed_pc=0x0c05f968u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f96a;
P_0c05f96a: /* original 2fd6, guest PC 0x0c05f96a */
if(!s->budget--) { s->failed_pc=0x0c05f96au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f96c;
P_0c05f96c: /* original 2fc6, guest PC 0x0c05f96c */
if(!s->budget--) { s->failed_pc=0x0c05f96cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f96e;
P_0c05f96e: /* original 2fb6, guest PC 0x0c05f96e */
if(!s->budget--) { s->failed_pc=0x0c05f96eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f970;
P_0c05f970: /* original 2fa6, guest PC 0x0c05f970 */
if(!s->budget--) { s->failed_pc=0x0c05f970u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f972;
P_0c05f972: /* original 2f96, guest PC 0x0c05f972 */
if(!s->budget--) { s->failed_pc=0x0c05f972u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f974;
P_0c05f974: /* original 2f86, guest PC 0x0c05f974 */
if(!s->budget--) { s->failed_pc=0x0c05f974u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f976;
P_0c05f976: /* original 4f22, guest PC 0x0c05f976 */
if(!s->budget--) { s->failed_pc=0x0c05f976u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05f978;
P_0c05f978: /* original d248, guest PC 0x0c05f978 */
if(!s->budget--) { s->failed_pc=0x0c05f978u; return 0; }
r[2]=read(ram,0x0c05fa9cu,4);
goto P_0c05f97a;
P_0c05f97a: /* original 7ff4, guest PC 0x0c05f97a */
if(!s->budget--) { s->failed_pc=0x0c05f97au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c05f97c;
P_0c05f97c: /* original 6322, guest PC 0x0c05f97c */
if(!s->budget--) { s->failed_pc=0x0c05f97cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05f97e;
P_0c05f97e: /* original 2338, guest PC 0x0c05f97e */
if(!s->budget--) { s->failed_pc=0x0c05f97eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05f980;
P_0c05f980: /* original 8b07, guest PC 0x0c05f980 */
if(!s->budget--) { s->failed_pc=0x0c05f980u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f992; }
goto P_0c05f982;
P_0c05f982: /* original d347, guest PC 0x0c05f982 */
if(!s->budget--) { s->failed_pc=0x0c05f982u; return 0; }
r[3]=read(ram,0x0c05faa0u,4);
goto P_0c05f984;
P_0c05f984: /* original d145, guest PC 0x0c05f984 */
if(!s->budget--) { s->failed_pc=0x0c05f984u; return 0; }
r[1]=read(ram,0x0c05fa9cu,4);
goto P_0c05f986;
P_0c05f986: /* original 2132, guest PC 0x0c05f986 */
if(!s->budget--) { s->failed_pc=0x0c05f986u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c05f988;
P_0c05f988: /* original 9685, guest PC 0x0c05f988 */
if(!s->budget--) { s->failed_pc=0x0c05f988u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05fa96u,2);
goto P_0c05f98a;
P_0c05f98a: /* original e500, guest PC 0x0c05f98a */
if(!s->budget--) { s->failed_pc=0x0c05f98au; return 0; }
r[5]=0x00000000u;
goto P_0c05f98c;
P_0c05f98c: /* original d345, guest PC 0x0c05f98c */
if(!s->budget--) { s->failed_pc=0x0c05f98cu; return 0; }
r[3]=read(ram,0x0c05faa4u,4);
goto P_0c05f98e;
P_0c05f98e: /* original 430b, guest PC 0x0c05f98e */
if(!s->budget--) { s->failed_pc=0x0c05f98eu; return 0; }
target=r[3];
r[16]=code_base|0x0c05f992u;
tmp=read(ram,r[1],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f992u) { target=s->pc; goto dispatch; }
goto P_0c05f992;
P_0c05f990: /* original 6412, guest PC 0x0c05f990 */
if(!s->budget--) { s->failed_pc=0x0c05f990u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c05f992;
P_0c05f992: /* original e303, guest PC 0x0c05f992 */
if(!s->budget--) { s->failed_pc=0x0c05f992u; return 0; }
r[3]=0x00000003u;
goto P_0c05f994;
P_0c05f994: /* original d142, guest PC 0x0c05f994 */
if(!s->budget--) { s->failed_pc=0x0c05f994u; return 0; }
r[1]=read(ram,0x0c05faa0u,4);
goto P_0c05f996;
P_0c05f996: /* original eb02, guest PC 0x0c05f996 */
if(!s->budget--) { s->failed_pc=0x0c05f996u; return 0; }
r[11]=0x00000002u;
goto P_0c05f998;
P_0c05f998: /* original d443, guest PC 0x0c05f998 */
if(!s->budget--) { s->failed_pc=0x0c05f998u; return 0; }
r[4]=read(ram,0x0c05faa8u,4);
goto P_0c05f99a;
P_0c05f99a: /* original e204, guest PC 0x0c05f99a */
if(!s->budget--) { s->failed_pc=0x0c05f99au; return 0; }
r[2]=0x00000004u;
goto P_0c05f99c;
P_0c05f99c: /* original 2432, guest PC 0x0c05f99c */
if(!s->budget--) { s->failed_pc=0x0c05f99cu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c05f99e;
P_0c05f99e: /* original e801, guest PC 0x0c05f99e */
if(!s->budget--) { s->failed_pc=0x0c05f99eu; return 0; }
r[8]=0x00000001u;
goto P_0c05f9a0;
P_0c05f9a0: /* original 14b1, guest PC 0x0c05f9a0 */
if(!s->budget--) { s->failed_pc=0x0c05f9a0u; return 0; }
write(ram,r[4]+4,r[11],4);
goto P_0c05f9a2;
P_0c05f9a2: /* original 1422, guest PC 0x0c05f9a2 */
if(!s->budget--) { s->failed_pc=0x0c05f9a2u; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c05f9a4;
P_0c05f9a4: /* original 1483, guest PC 0x0c05f9a4 */
if(!s->budget--) { s->failed_pc=0x0c05f9a4u; return 0; }
write(ram,r[4]+12,r[8],4);
goto P_0c05f9a6;
P_0c05f9a6: /* original 6243, guest PC 0x0c05f9a6 */
if(!s->budget--) { s->failed_pc=0x0c05f9a6u; return 0; }
r[2]=r[4];
goto P_0c05f9a8;
P_0c05f9a8: /* original d340, guest PC 0x0c05f9a8 */
if(!s->budget--) { s->failed_pc=0x0c05f9a8u; return 0; }
r[3]=read(ram,0x0c05faacu,4);
goto P_0c05f9aa;
P_0c05f9aa: /* original 1434, guest PC 0x0c05f9aa */
if(!s->budget--) { s->failed_pc=0x0c05f9aau; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c05f9ac;
P_0c05f9ac: /* original 2142, guest PC 0x0c05f9ac */
if(!s->budget--) { s->failed_pc=0x0c05f9acu; return 0; }
write(ram,r[1],r[4],4);
goto P_0c05f9ae;
P_0c05f9ae: /* original ee00, guest PC 0x0c05f9ae */
if(!s->budget--) { s->failed_pc=0x0c05f9aeu; return 0; }
r[14]=0x00000000u;
goto P_0c05f9b0;
P_0c05f9b0: /* original d33f, guest PC 0x0c05f9b0 */
if(!s->budget--) { s->failed_pc=0x0c05f9b0u; return 0; }
r[3]=read(ram,0x0c05fab0u,4);
goto P_0c05f9b2;
P_0c05f9b2: /* original 23e2, guest PC 0x0c05f9b2 */
if(!s->budget--) { s->failed_pc=0x0c05f9b2u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05f9b4;
P_0c05f9b4: /* original d23f, guest PC 0x0c05f9b4 */
if(!s->budget--) { s->failed_pc=0x0c05f9b4u; return 0; }
r[2]=read(ram,0x0c05fab4u,4);
goto P_0c05f9b6;
P_0c05f9b6: /* original 22e2, guest PC 0x0c05f9b6 */
if(!s->budget--) { s->failed_pc=0x0c05f9b6u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05f9b8;
P_0c05f9b8: /* original d13f, guest PC 0x0c05f9b8 */
if(!s->budget--) { s->failed_pc=0x0c05f9b8u; return 0; }
r[1]=read(ram,0x0c05fab8u,4);
goto P_0c05f9ba;
P_0c05f9ba: /* original 21e2, guest PC 0x0c05f9ba */
if(!s->budget--) { s->failed_pc=0x0c05f9bau; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05f9bc;
P_0c05f9bc: /* original 731c, guest PC 0x0c05f9bc */
if(!s->budget--) { s->failed_pc=0x0c05f9bcu; return 0; }
r[3]+=0x0000001cu;
goto P_0c05f9be;
P_0c05f9be: /* original 23e2, guest PC 0x0c05f9be */
if(!s->budget--) { s->failed_pc=0x0c05f9beu; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05f9c0;
P_0c05f9c0: /* original d13e, guest PC 0x0c05f9c0 */
if(!s->budget--) { s->failed_pc=0x0c05f9c0u; return 0; }
r[1]=read(ram,0x0c05fabcu,4);
goto P_0c05f9c2;
P_0c05f9c2: /* original 721c, guest PC 0x0c05f9c2 */
if(!s->budget--) { s->failed_pc=0x0c05f9c2u; return 0; }
r[2]+=0x0000001cu;
goto P_0c05f9c4;
P_0c05f9c4: /* original 410b, guest PC 0x0c05f9c4 */
if(!s->budget--) { s->failed_pc=0x0c05f9c4u; return 0; }
target=r[1];
r[16]=code_base|0x0c05f9c8u;
write(ram,r[2],r[14],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f9c8u) { target=s->pc; goto dispatch; }
goto P_0c05f9c8;
P_0c05f9c6: /* original 22e2, guest PC 0x0c05f9c6 */
if(!s->budget--) { s->failed_pc=0x0c05f9c6u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05f9c8;
P_0c05f9c8: /* original d33d, guest PC 0x0c05f9c8 */
if(!s->budget--) { s->failed_pc=0x0c05f9c8u; return 0; }
r[3]=read(ram,0x0c05fac0u,4);
goto P_0c05f9ca;
P_0c05f9ca: /* original 23e2, guest PC 0x0c05f9ca */
if(!s->budget--) { s->failed_pc=0x0c05f9cau; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05f9cc;
P_0c05f9cc: /* original d23d, guest PC 0x0c05f9cc */
if(!s->budget--) { s->failed_pc=0x0c05f9ccu; return 0; }
r[2]=read(ram,0x0c05fac4u,4);
goto P_0c05f9ce;
P_0c05f9ce: /* original 22e2, guest PC 0x0c05f9ce */
if(!s->budget--) { s->failed_pc=0x0c05f9ceu; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05f9d0;
P_0c05f9d0: /* original dc3d, guest PC 0x0c05f9d0 */
if(!s->budget--) { s->failed_pc=0x0c05f9d0u; return 0; }
r[12]=read(ram,0x0c05fac8u,4);
goto P_0c05f9d2;
P_0c05f9d2: /* original 6683, guest PC 0x0c05f9d2 */
if(!s->budget--) { s->failed_pc=0x0c05f9d2u; return 0; }
r[6]=r[8];
goto P_0c05f9d4;
P_0c05f9d4: /* original d53e, guest PC 0x0c05f9d4 */
if(!s->budget--) { s->failed_pc=0x0c05f9d4u; return 0; }
r[5]=read(ram,0x0c05fad0u,4);
goto P_0c05f9d6;
P_0c05f9d6: /* original dd3d, guest PC 0x0c05f9d6 */
if(!s->budget--) { s->failed_pc=0x0c05f9d6u; return 0; }
r[13]=read(ram,0x0c05faccu,4);
goto P_0c05f9d8;
P_0c05f9d8: /* original 4d0b, guest PC 0x0c05f9d8 */
if(!s->budget--) { s->failed_pc=0x0c05f9d8u; return 0; }
target=r[13];
r[16]=code_base|0x0c05f9dcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f9dcu) { target=s->pc; goto dispatch; }
goto P_0c05f9dc;
P_0c05f9da: /* original 64c3, guest PC 0x0c05f9da */
if(!s->budget--) { s->failed_pc=0x0c05f9dau; return 0; }
r[4]=r[12];
goto P_0c05f9dc;
P_0c05f9dc: /* original d33d, guest PC 0x0c05f9dc */
if(!s->budget--) { s->failed_pc=0x0c05f9dcu; return 0; }
r[3]=read(ram,0x0c05fad4u,4);
goto P_0c05f9de;
P_0c05f9de: /* original 70ff, guest PC 0x0c05f9de */
if(!s->budget--) { s->failed_pc=0x0c05f9deu; return 0; }
r[0]+=0xffffffffu;
goto P_0c05f9e0;
P_0c05f9e0: /* original 2302, guest PC 0x0c05f9e0 */
if(!s->budget--) { s->failed_pc=0x0c05f9e0u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05f9e2;
P_0c05f9e2: /* original 6133, guest PC 0x0c05f9e2 */
if(!s->budget--) { s->failed_pc=0x0c05f9e2u; return 0; }
r[1]=r[3];
goto P_0c05f9e4;
P_0c05f9e4: /* original 6212, guest PC 0x0c05f9e4 */
if(!s->budget--) { s->failed_pc=0x0c05f9e4u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c05f9e6;
P_0c05f9e6: /* original d03c, guest PC 0x0c05f9e6 */
if(!s->budget--) { s->failed_pc=0x0c05f9e6u; return 0; }
r[0]=read(ram,0x0c05fad8u,4);
goto P_0c05f9e8;
P_0c05f9e8: /* original 2022, guest PC 0x0c05f9e8 */
if(!s->budget--) { s->failed_pc=0x0c05f9e8u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c05f9ea;
P_0c05f9ea: /* original d33c, guest PC 0x0c05f9ea */
if(!s->budget--) { s->failed_pc=0x0c05f9eau; return 0; }
r[3]=read(ram,0x0c05fadcu,4);
goto P_0c05f9ec;
P_0c05f9ec: /* original d23c, guest PC 0x0c05f9ec */
if(!s->budget--) { s->failed_pc=0x0c05f9ecu; return 0; }
r[2]=read(ram,0x0c05fae0u,4);
goto P_0c05f9ee;
P_0c05f9ee: /* original 2232, guest PC 0x0c05f9ee */
if(!s->budget--) { s->failed_pc=0x0c05f9eeu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05f9f0;
P_0c05f9f0: /* original d43c, guest PC 0x0c05f9f0 */
if(!s->budget--) { s->failed_pc=0x0c05f9f0u; return 0; }
r[4]=read(ram,0x0c05fae4u,4);
goto P_0c05f9f2;
P_0c05f9f2: /* original d33d, guest PC 0x0c05f9f2 */
if(!s->budget--) { s->failed_pc=0x0c05f9f2u; return 0; }
r[3]=read(ram,0x0c05fae8u,4);
goto P_0c05f9f4;
P_0c05f9f4: /* original 2342, guest PC 0x0c05f9f4 */
if(!s->budget--) { s->failed_pc=0x0c05f9f4u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05f9f6;
P_0c05f9f6: /* original d13d, guest PC 0x0c05f9f6 */
if(!s->budget--) { s->failed_pc=0x0c05f9f6u; return 0; }
r[1]=read(ram,0x0c05faecu,4);
goto P_0c05f9f8;
P_0c05f9f8: /* original 2142, guest PC 0x0c05f9f8 */
if(!s->budget--) { s->failed_pc=0x0c05f9f8u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c05f9fa;
P_0c05f9fa: /* original d23d, guest PC 0x0c05f9fa */
if(!s->budget--) { s->failed_pc=0x0c05f9fau; return 0; }
r[2]=read(ram,0x0c05faf0u,4);
goto P_0c05f9fc;
P_0c05f9fc: /* original 22e2, guest PC 0x0c05f9fc */
if(!s->budget--) { s->failed_pc=0x0c05f9fcu; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05f9fe;
P_0c05f9fe: /* original d33d, guest PC 0x0c05f9fe */
if(!s->budget--) { s->failed_pc=0x0c05f9feu; return 0; }
r[3]=read(ram,0x0c05faf4u,4);
goto P_0c05fa00;
P_0c05fa00: /* original 23e2, guest PC 0x0c05fa00 */
if(!s->budget--) { s->failed_pc=0x0c05fa00u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05fa02;
P_0c05fa02: /* original d13d, guest PC 0x0c05fa02 */
if(!s->budget--) { s->failed_pc=0x0c05fa02u; return 0; }
r[1]=read(ram,0x0c05faf8u,4);
goto P_0c05fa04;
P_0c05fa04: /* original 21e2, guest PC 0x0c05fa04 */
if(!s->budget--) { s->failed_pc=0x0c05fa04u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05fa06;
P_0c05fa06: /* original e203, guest PC 0x0c05fa06 */
if(!s->budget--) { s->failed_pc=0x0c05fa06u; return 0; }
r[2]=0x00000003u;
goto P_0c05fa08;
P_0c05fa08: /* original d03c, guest PC 0x0c05fa08 */
if(!s->budget--) { s->failed_pc=0x0c05fa08u; return 0; }
r[0]=read(ram,0x0c05fafcu,4);
goto P_0c05fa0a;
P_0c05fa0a: /* original 2022, guest PC 0x0c05fa0a */
if(!s->budget--) { s->failed_pc=0x0c05fa0au; return 0; }
write(ram,r[0],r[2],4);
goto P_0c05fa0c;
P_0c05fa0c: /* original d23c, guest PC 0x0c05fa0c */
if(!s->budget--) { s->failed_pc=0x0c05fa0cu; return 0; }
r[2]=read(ram,0x0c05fb00u,4);
goto P_0c05fa0e;
P_0c05fa0e: /* original 6383, guest PC 0x0c05fa0e */
if(!s->budget--) { s->failed_pc=0x0c05fa0eu; return 0; }
r[3]=r[8];
goto P_0c05fa10;
P_0c05fa10: /* original d13c, guest PC 0x0c05fa10 */
if(!s->budget--) { s->failed_pc=0x0c05fa10u; return 0; }
r[1]=read(ram,0x0c05fb04u,4);
goto P_0c05fa12;
P_0c05fa12: /* original 410b, guest PC 0x0c05fa12 */
if(!s->budget--) { s->failed_pc=0x0c05fa12u; return 0; }
target=r[1];
r[16]=code_base|0x0c05fa16u;
write(ram,r[2],r[8],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fa16u) { target=s->pc; goto dispatch; }
goto P_0c05fa16;
P_0c05fa14: /* original 2282, guest PC 0x0c05fa14 */
if(!s->budget--) { s->failed_pc=0x0c05fa14u; return 0; }
write(ram,r[2],r[8],4);
goto P_0c05fa16;
P_0c05fa16: /* original 963f, guest PC 0x0c05fa16 */
if(!s->budget--) { s->failed_pc=0x0c05fa16u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05fa98u,2);
goto P_0c05fa18;
P_0c05fa18: /* original d53b, guest PC 0x0c05fa18 */
if(!s->budget--) { s->failed_pc=0x0c05fa18u; return 0; }
r[5]=read(ram,0x0c05fb08u,4);
goto P_0c05fa1a;
P_0c05fa1a: /* original 4d0b, guest PC 0x0c05fa1a */
if(!s->budget--) { s->failed_pc=0x0c05fa1au; return 0; }
target=r[13];
r[16]=code_base|0x0c05fa1eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fa1eu) { target=s->pc; goto dispatch; }
goto P_0c05fa1e;
P_0c05fa1c: /* original 64c3, guest PC 0x0c05fa1c */
if(!s->budget--) { s->failed_pc=0x0c05fa1cu; return 0; }
r[4]=r[12];
goto P_0c05fa1e;
P_0c05fa1e: /* original 2f02, guest PC 0x0c05fa1e */
if(!s->budget--) { s->failed_pc=0x0c05fa1eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c05fa20;
P_0c05fa20: /* original d63a, guest PC 0x0c05fa20 */
if(!s->budget--) { s->failed_pc=0x0c05fa20u; return 0; }
r[6]=read(ram,0x0c05fb0cu,4);
goto P_0c05fa22;
P_0c05fa22: /* original d53b, guest PC 0x0c05fa22 */
if(!s->budget--) { s->failed_pc=0x0c05fa22u; return 0; }
r[5]=read(ram,0x0c05fb10u,4);
goto P_0c05fa24;
P_0c05fa24: /* original 4d0b, guest PC 0x0c05fa24 */
if(!s->budget--) { s->failed_pc=0x0c05fa24u; return 0; }
target=r[13];
r[16]=code_base|0x0c05fa28u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fa28u) { target=s->pc; goto dispatch; }
goto P_0c05fa28;
P_0c05fa26: /* original 64c3, guest PC 0x0c05fa26 */
if(!s->budget--) { s->failed_pc=0x0c05fa26u; return 0; }
r[4]=r[12];
goto P_0c05fa28;
P_0c05fa28: /* original 1f01, guest PC 0x0c05fa28 */
if(!s->budget--) { s->failed_pc=0x0c05fa28u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c05fa2a;
P_0c05fa2a: /* original d63a, guest PC 0x0c05fa2a */
if(!s->budget--) { s->failed_pc=0x0c05fa2au; return 0; }
r[6]=read(ram,0x0c05fb14u,4);
goto P_0c05fa2c;
P_0c05fa2c: /* original d53a, guest PC 0x0c05fa2c */
if(!s->budget--) { s->failed_pc=0x0c05fa2cu; return 0; }
r[5]=read(ram,0x0c05fb18u,4);
goto P_0c05fa2e;
P_0c05fa2e: /* original 4d0b, guest PC 0x0c05fa2e */
if(!s->budget--) { s->failed_pc=0x0c05fa2eu; return 0; }
target=r[13];
r[16]=code_base|0x0c05fa32u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fa32u) { target=s->pc; goto dispatch; }
goto P_0c05fa32;
P_0c05fa30: /* original 64c3, guest PC 0x0c05fa30 */
if(!s->budget--) { s->failed_pc=0x0c05fa30u; return 0; }
r[4]=r[12];
goto P_0c05fa32;
P_0c05fa32: /* original 1f02, guest PC 0x0c05fa32 */
if(!s->budget--) { s->failed_pc=0x0c05fa32u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c05fa34;
P_0c05fa34: /* original d637, guest PC 0x0c05fa34 */
if(!s->budget--) { s->failed_pc=0x0c05fa34u; return 0; }
r[6]=read(ram,0x0c05fb14u,4);
goto P_0c05fa36;
P_0c05fa36: /* original d539, guest PC 0x0c05fa36 */
if(!s->budget--) { s->failed_pc=0x0c05fa36u; return 0; }
r[5]=read(ram,0x0c05fb1cu,4);
goto P_0c05fa38;
P_0c05fa38: /* original 4d0b, guest PC 0x0c05fa38 */
if(!s->budget--) { s->failed_pc=0x0c05fa38u; return 0; }
target=r[13];
r[16]=code_base|0x0c05fa3cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fa3cu) { target=s->pc; goto dispatch; }
goto P_0c05fa3c;
P_0c05fa3a: /* original 64c3, guest PC 0x0c05fa3a */
if(!s->budget--) { s->failed_pc=0x0c05fa3au; return 0; }
r[4]=r[12];
goto P_0c05fa3c;
P_0c05fa3c: /* original 69f2, guest PC 0x0c05fa3c */
if(!s->budget--) { s->failed_pc=0x0c05fa3cu; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c05fa3e;
P_0c05fa3e: /* original 6503, guest PC 0x0c05fa3e */
if(!s->budget--) { s->failed_pc=0x0c05fa3eu; return 0; }
r[5]=r[0];
goto P_0c05fa40;
P_0c05fa40: /* original 56f1, guest PC 0x0c05fa40 */
if(!s->budget--) { s->failed_pc=0x0c05fa40u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c05fa42;
P_0c05fa42: /* original 4919, guest PC 0x0c05fa42 */
if(!s->budget--) { s->failed_pc=0x0c05fa42u; return 0; }
r[9]>>=8;
goto P_0c05fa44;
P_0c05fa44: /* original 54f2, guest PC 0x0c05fa44 */
if(!s->budget--) { s->failed_pc=0x0c05fa44u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c05fa46;
P_0c05fa46: /* original 4519, guest PC 0x0c05fa46 */
if(!s->budget--) { s->failed_pc=0x0c05fa46u; return 0; }
r[5]>>=8;
goto P_0c05fa48;
P_0c05fa48: /* original d335, guest PC 0x0c05fa48 */
if(!s->budget--) { s->failed_pc=0x0c05fa48u; return 0; }
r[3]=read(ram,0x0c05fb20u,4);
goto P_0c05fa4a;
P_0c05fa4a: /* original 4619, guest PC 0x0c05fa4a */
if(!s->budget--) { s->failed_pc=0x0c05fa4au; return 0; }
r[6]>>=8;
goto P_0c05fa4c;
P_0c05fa4c: /* original 4909, guest PC 0x0c05fa4c */
if(!s->budget--) { s->failed_pc=0x0c05fa4cu; return 0; }
r[9]>>=2;
goto P_0c05fa4e;
P_0c05fa4e: /* original 4901, guest PC 0x0c05fa4e */
if(!s->budget--) { s->failed_pc=0x0c05fa4eu; return 0; }
r[17]=(r[17]&~1u)|((r[9]&1)!=0);
r[9]>>=1;
goto P_0c05fa50;
P_0c05fa50: /* original 4918, guest PC 0x0c05fa50 */
if(!s->budget--) { s->failed_pc=0x0c05fa50u; return 0; }
r[9]<<=8;
goto P_0c05fa52;
P_0c05fa52: /* original 4908, guest PC 0x0c05fa52 */
if(!s->budget--) { s->failed_pc=0x0c05fa52u; return 0; }
r[9]<<=2;
goto P_0c05fa54;
P_0c05fa54: /* original 4900, guest PC 0x0c05fa54 */
if(!s->budget--) { s->failed_pc=0x0c05fa54u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c05fa56;
P_0c05fa56: /* original 4609, guest PC 0x0c05fa56 */
if(!s->budget--) { s->failed_pc=0x0c05fa56u; return 0; }
r[6]>>=2;
goto P_0c05fa58;
P_0c05fa58: /* original 4601, guest PC 0x0c05fa58 */
if(!s->budget--) { s->failed_pc=0x0c05fa58u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c05fa5a;
P_0c05fa5a: /* original 4618, guest PC 0x0c05fa5a */
if(!s->budget--) { s->failed_pc=0x0c05fa5au; return 0; }
r[6]<<=8;
goto P_0c05fa5c;
P_0c05fa5c: /* original 4608, guest PC 0x0c05fa5c */
if(!s->budget--) { s->failed_pc=0x0c05fa5cu; return 0; }
r[6]<<=2;
goto P_0c05fa5e;
P_0c05fa5e: /* original 4600, guest PC 0x0c05fa5e */
if(!s->budget--) { s->failed_pc=0x0c05fa5eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c05fa60;
P_0c05fa60: /* original 4419, guest PC 0x0c05fa60 */
if(!s->budget--) { s->failed_pc=0x0c05fa60u; return 0; }
r[4]>>=8;
goto P_0c05fa62;
P_0c05fa62: /* original 4409, guest PC 0x0c05fa62 */
if(!s->budget--) { s->failed_pc=0x0c05fa62u; return 0; }
r[4]>>=2;
goto P_0c05fa64;
P_0c05fa64: /* original 4401, guest PC 0x0c05fa64 */
if(!s->budget--) { s->failed_pc=0x0c05fa64u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c05fa66;
P_0c05fa66: /* original 4418, guest PC 0x0c05fa66 */
if(!s->budget--) { s->failed_pc=0x0c05fa66u; return 0; }
r[4]<<=8;
goto P_0c05fa68;
P_0c05fa68: /* original 4408, guest PC 0x0c05fa68 */
if(!s->budget--) { s->failed_pc=0x0c05fa68u; return 0; }
r[4]<<=2;
goto P_0c05fa6a;
P_0c05fa6a: /* original 4400, guest PC 0x0c05fa6a */
if(!s->budget--) { s->failed_pc=0x0c05fa6au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c05fa6c;
P_0c05fa6c: /* original 4509, guest PC 0x0c05fa6c */
if(!s->budget--) { s->failed_pc=0x0c05fa6cu; return 0; }
r[5]>>=2;
goto P_0c05fa6e;
P_0c05fa6e: /* original 4501, guest PC 0x0c05fa6e */
if(!s->budget--) { s->failed_pc=0x0c05fa6eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c05fa70;
P_0c05fa70: /* original 4518, guest PC 0x0c05fa70 */
if(!s->budget--) { s->failed_pc=0x0c05fa70u; return 0; }
r[5]<<=8;
goto P_0c05fa72;
P_0c05fa72: /* original 4508, guest PC 0x0c05fa72 */
if(!s->budget--) { s->failed_pc=0x0c05fa72u; return 0; }
r[5]<<=2;
goto P_0c05fa74;
P_0c05fa74: /* original 4500, guest PC 0x0c05fa74 */
if(!s->budget--) { s->failed_pc=0x0c05fa74u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c05fa76;
P_0c05fa76: /* original 2342, guest PC 0x0c05fa76 */
if(!s->budget--) { s->failed_pc=0x0c05fa76u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05fa78;
P_0c05fa78: /* original d22a, guest PC 0x0c05fa78 */
if(!s->budget--) { s->failed_pc=0x0c05fa78u; return 0; }
r[2]=read(ram,0x0c05fb24u,4);
goto P_0c05fa7a;
P_0c05fa7a: /* original 2252, guest PC 0x0c05fa7a */
if(!s->budget--) { s->failed_pc=0x0c05fa7au; return 0; }
write(ram,r[2],r[5],4);
goto P_0c05fa7c;
P_0c05fa7c: /* original da2a, guest PC 0x0c05fa7c */
if(!s->budget--) { s->failed_pc=0x0c05fa7cu; return 0; }
r[10]=read(ram,0x0c05fb28u,4);
goto P_0c05fa7e;
P_0c05fa7e: /* original 369c, guest PC 0x0c05fa7e */
if(!s->budget--) { s->failed_pc=0x0c05fa7eu; return 0; }
r[6]+=r[9];
goto P_0c05fa80;
P_0c05fa80: /* original 2f62, guest PC 0x0c05fa80 */
if(!s->budget--) { s->failed_pc=0x0c05fa80u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05fa82;
P_0c05fa82: /* original 6163, guest PC 0x0c05fa82 */
if(!s->budget--) { s->failed_pc=0x0c05fa82u; return 0; }
r[1]=r[6];
goto P_0c05fa84;
P_0c05fa84: /* original 341c, guest PC 0x0c05fa84 */
if(!s->budget--) { s->failed_pc=0x0c05fa84u; return 0; }
r[4]+=r[1];
goto P_0c05fa86;
P_0c05fa86: /* original 67e3, guest PC 0x0c05fa86 */
if(!s->budget--) { s->failed_pc=0x0c05fa86u; return 0; }
r[7]=r[14];
goto P_0c05fa88;
P_0c05fa88: /* original 1f41, guest PC 0x0c05fa88 */
if(!s->budget--) { s->failed_pc=0x0c05fa88u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c05fa8a;
P_0c05fa8a: /* original 66e3, guest PC 0x0c05fa8a */
if(!s->budget--) { s->failed_pc=0x0c05fa8au; return 0; }
r[6]=r[14];
goto P_0c05fa8c;
P_0c05fa8c: /* original 64e3, guest PC 0x0c05fa8c */
if(!s->budget--) { s->failed_pc=0x0c05fa8cu; return 0; }
r[4]=r[14];
goto P_0c05fa8e;
P_0c05fa8e: /* original 65e3, guest PC 0x0c05fa8e */
if(!s->budget--) { s->failed_pc=0x0c05fa8eu; return 0; }
r[5]=r[14];
goto P_0c05fa90;
P_0c05fa90: /* original d026, guest PC 0x0c05fa90 */
if(!s->budget--) { s->failed_pc=0x0c05fa90u; return 0; }
r[0]=read(ram,0x0c05fb2cu,4);
goto P_0c05fa92;
P_0c05fa92: /* original a04d, guest PC 0x0c05fa92 */
if(!s->budget--) { s->failed_pc=0x0c05fa92u; return 0; }
goto P_0c05fb30;
P_0c05fa94: /* original 0009, guest PC 0x0c05fa94 */
if(!s->budget--) { s->failed_pc=0x0c05fa94u; return 0; }
if(!vf3_matrix_family(0x0c05fa96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fa96u; return 0; } return 1;
P_0c05fb30: /* original 0546, guest PC 0x0c05fb30 */
if(!s->budget--) { s->failed_pc=0x0c05fb30u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c05fb32;
P_0c05fb32: /* original 6303, guest PC 0x0c05fb32 */
if(!s->budget--) { s->failed_pc=0x0c05fb32u; return 0; }
r[3]=r[0];
goto P_0c05fb34;
P_0c05fb34: /* original 335c, guest PC 0x0c05fb34 */
if(!s->budget--) { s->failed_pc=0x0c05fb34u; return 0; }
r[3]+=r[5];
goto P_0c05fb36;
P_0c05fb36: /* original 6243, guest PC 0x0c05fb36 */
if(!s->budget--) { s->failed_pc=0x0c05fb36u; return 0; }
r[2]=r[4];
goto P_0c05fb38;
P_0c05fb38: /* original 329c, guest PC 0x0c05fb38 */
if(!s->budget--) { s->failed_pc=0x0c05fb38u; return 0; }
r[2]+=r[9];
goto P_0c05fb3a;
P_0c05fb3a: /* original 1321, guest PC 0x0c05fb3a */
if(!s->budget--) { s->failed_pc=0x0c05fb3au; return 0; }
write(ram,r[3]+4,r[2],4);
goto P_0c05fb3c;
P_0c05fb3c: /* original 62f2, guest PC 0x0c05fb3c */
if(!s->budget--) { s->failed_pc=0x0c05fb3cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05fb3e;
P_0c05fb3e: /* original 6303, guest PC 0x0c05fb3e */
if(!s->budget--) { s->failed_pc=0x0c05fb3eu; return 0; }
r[3]=r[0];
goto P_0c05fb40;
P_0c05fb40: /* original 335c, guest PC 0x0c05fb40 */
if(!s->budget--) { s->failed_pc=0x0c05fb40u; return 0; }
r[3]+=r[5];
goto P_0c05fb42;
P_0c05fb42: /* original 324c, guest PC 0x0c05fb42 */
if(!s->budget--) { s->failed_pc=0x0c05fb42u; return 0; }
r[2]+=r[4];
goto P_0c05fb44;
P_0c05fb44: /* original 1322, guest PC 0x0c05fb44 */
if(!s->budget--) { s->failed_pc=0x0c05fb44u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c05fb46;
P_0c05fb46: /* original 53f1, guest PC 0x0c05fb46 */
if(!s->budget--) { s->failed_pc=0x0c05fb46u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05fb48;
P_0c05fb48: /* original d061, guest PC 0x0c05fb48 */
if(!s->budget--) { s->failed_pc=0x0c05fb48u; return 0; }
r[0]=read(ram,0x0c05fcd0u,4);
goto P_0c05fb4a;
P_0c05fb4a: /* original 334c, guest PC 0x0c05fb4a */
if(!s->budget--) { s->failed_pc=0x0c05fb4au; return 0; }
r[3]+=r[4];
goto P_0c05fb4c;
P_0c05fb4c: /* original 0536, guest PC 0x0c05fb4c */
if(!s->budget--) { s->failed_pc=0x0c05fb4cu; return 0; }
write(ram,r[5]+r[0],r[3],4);
goto P_0c05fb4e;
P_0c05fb4e: /* original 7014, guest PC 0x0c05fb4e */
if(!s->budget--) { s->failed_pc=0x0c05fb4eu; return 0; }
r[0]+=0x00000014u;
goto P_0c05fb50;
P_0c05fb50: /* original d360, guest PC 0x0c05fb50 */
if(!s->budget--) { s->failed_pc=0x0c05fb50u; return 0; }
r[3]=read(ram,0x0c05fcd4u,4);
goto P_0c05fb52;
P_0c05fb52: /* original 3348, guest PC 0x0c05fb52 */
if(!s->budget--) { s->failed_pc=0x0c05fb52u; return 0; }
r[3]-=r[4];
goto P_0c05fb54;
P_0c05fb54: /* original 0636, guest PC 0x0c05fb54 */
if(!s->budget--) { s->failed_pc=0x0c05fb54u; return 0; }
write(ram,r[6]+r[0],r[3],4);
goto P_0c05fb56;
P_0c05fb56: /* original 7701, guest PC 0x0c05fb56 */
if(!s->budget--) { s->failed_pc=0x0c05fb56u; return 0; }
r[7]+=0x00000001u;
goto P_0c05fb58;
P_0c05fb58: /* original 7604, guest PC 0x0c05fb58 */
if(!s->budget--) { s->failed_pc=0x0c05fb58u; return 0; }
r[6]+=0x00000004u;
goto P_0c05fb5a;
P_0c05fb5a: /* original 34ac, guest PC 0x0c05fb5a */
if(!s->budget--) { s->failed_pc=0x0c05fb5au; return 0; }
r[4]+=r[10];
goto P_0c05fb5c;
P_0c05fb5c: /* original 37b3, guest PC 0x0c05fb5c */
if(!s->budget--) { s->failed_pc=0x0c05fb5cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[11])!=0);
goto P_0c05fb5e;
P_0c05fb5e: /* original 8f97, guest PC 0x0c05fb5e */
if(!s->budget--) { s->failed_pc=0x0c05fb5eu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000010u;
if(!cond) { goto P_0c05fa90; }
goto P_0c05fb62;
P_0c05fb60: /* original 7510, guest PC 0x0c05fb60 */
if(!s->budget--) { s->failed_pc=0x0c05fb60u; return 0; }
r[5]+=0x00000010u;
goto P_0c05fb62;
P_0c05fb62: /* original d35d, guest PC 0x0c05fb62 */
if(!s->budget--) { s->failed_pc=0x0c05fb62u; return 0; }
r[3]=read(ram,0x0c05fcd8u,4);
goto P_0c05fb64;
P_0c05fb64: /* original 23e2, guest PC 0x0c05fb64 */
if(!s->budget--) { s->failed_pc=0x0c05fb64u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05fb66;
P_0c05fb66: /* original d25d, guest PC 0x0c05fb66 */
if(!s->budget--) { s->failed_pc=0x0c05fb66u; return 0; }
r[2]=read(ram,0x0c05fcdcu,4);
goto P_0c05fb68;
P_0c05fb68: /* original 22e2, guest PC 0x0c05fb68 */
if(!s->budget--) { s->failed_pc=0x0c05fb68u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05fb6a;
P_0c05fb6a: /* original d15d, guest PC 0x0c05fb6a */
if(!s->budget--) { s->failed_pc=0x0c05fb6au; return 0; }
r[1]=read(ram,0x0c05fce0u,4);
goto P_0c05fb6c;
P_0c05fb6c: /* original 21e2, guest PC 0x0c05fb6c */
if(!s->budget--) { s->failed_pc=0x0c05fb6cu; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05fb6e;
P_0c05fb6e: /* original e4ff, guest PC 0x0c05fb6e */
if(!s->budget--) { s->failed_pc=0x0c05fb6eu; return 0; }
r[4]=0xffffffffu;
goto P_0c05fb70;
P_0c05fb70: /* original 730c, guest PC 0x0c05fb70 */
if(!s->budget--) { s->failed_pc=0x0c05fb70u; return 0; }
r[3]+=0x0000000cu;
goto P_0c05fb72;
P_0c05fb72: /* original 2342, guest PC 0x0c05fb72 */
if(!s->budget--) { s->failed_pc=0x0c05fb72u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05fb74;
P_0c05fb74: /* original d25b, guest PC 0x0c05fb74 */
if(!s->budget--) { s->failed_pc=0x0c05fb74u; return 0; }
r[2]=read(ram,0x0c05fce4u,4);
goto P_0c05fb76;
P_0c05fb76: /* original 2242, guest PC 0x0c05fb76 */
if(!s->budget--) { s->failed_pc=0x0c05fb76u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c05fb78;
P_0c05fb78: /* original 710c, guest PC 0x0c05fb78 */
if(!s->budget--) { s->failed_pc=0x0c05fb78u; return 0; }
r[1]+=0x0000000cu;
goto P_0c05fb7a;
P_0c05fb7a: /* original 2142, guest PC 0x0c05fb7a */
if(!s->budget--) { s->failed_pc=0x0c05fb7au; return 0; }
write(ram,r[1],r[4],4);
goto P_0c05fb7c;
P_0c05fb7c: /* original 730c, guest PC 0x0c05fb7c */
if(!s->budget--) { s->failed_pc=0x0c05fb7cu; return 0; }
r[3]+=0x0000000cu;
goto P_0c05fb7e;
P_0c05fb7e: /* original 23e2, guest PC 0x0c05fb7e */
if(!s->budget--) { s->failed_pc=0x0c05fb7eu; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05fb80;
P_0c05fb80: /* original 720c, guest PC 0x0c05fb80 */
if(!s->budget--) { s->failed_pc=0x0c05fb80u; return 0; }
r[2]+=0x0000000cu;
goto P_0c05fb82;
P_0c05fb82: /* original 22e2, guest PC 0x0c05fb82 */
if(!s->budget--) { s->failed_pc=0x0c05fb82u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05fb84;
P_0c05fb84: /* original 710c, guest PC 0x0c05fb84 */
if(!s->budget--) { s->failed_pc=0x0c05fb84u; return 0; }
r[1]+=0x0000000cu;
goto P_0c05fb86;
P_0c05fb86: /* original 21e2, guest PC 0x0c05fb86 */
if(!s->budget--) { s->failed_pc=0x0c05fb86u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05fb88;
P_0c05fb88: /* original d357, guest PC 0x0c05fb88 */
if(!s->budget--) { s->failed_pc=0x0c05fb88u; return 0; }
r[3]=read(ram,0x0c05fce8u,4);
goto P_0c05fb8a;
P_0c05fb8a: /* original 23e2, guest PC 0x0c05fb8a */
if(!s->budget--) { s->failed_pc=0x0c05fb8au; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05fb8c;
P_0c05fb8c: /* original d257, guest PC 0x0c05fb8c */
if(!s->budget--) { s->failed_pc=0x0c05fb8cu; return 0; }
r[2]=read(ram,0x0c05fcecu,4);
goto P_0c05fb8e;
P_0c05fb8e: /* original 22e2, guest PC 0x0c05fb8e */
if(!s->budget--) { s->failed_pc=0x0c05fb8eu; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05fb90;
P_0c05fb90: /* original d157, guest PC 0x0c05fb90 */
if(!s->budget--) { s->failed_pc=0x0c05fb90u; return 0; }
r[1]=read(ram,0x0c05fcf0u,4);
goto P_0c05fb92;
P_0c05fb92: /* original d658, guest PC 0x0c05fb92 */
if(!s->budget--) { s->failed_pc=0x0c05fb92u; return 0; }
r[6]=read(ram,0x0c05fcf4u,4);
goto P_0c05fb94;
P_0c05fb94: /* original d558, guest PC 0x0c05fb94 */
if(!s->budget--) { s->failed_pc=0x0c05fb94u; return 0; }
r[5]=read(ram,0x0c05fcf8u,4);
goto P_0c05fb96;
P_0c05fb96: /* original d459, guest PC 0x0c05fb96 */
if(!s->budget--) { s->failed_pc=0x0c05fb96u; return 0; }
r[4]=read(ram,0x0c05fcfcu,4);
goto P_0c05fb98;
P_0c05fb98: /* original 4d0b, guest PC 0x0c05fb98 */
if(!s->budget--) { s->failed_pc=0x0c05fb98u; return 0; }
target=r[13];
r[16]=code_base|0x0c05fb9cu;
write(ram,r[1],r[8],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fb9cu) { target=s->pc; goto dispatch; }
goto P_0c05fb9c;
P_0c05fb9a: /* original 2182, guest PC 0x0c05fb9a */
if(!s->budget--) { s->failed_pc=0x0c05fb9au; return 0; }
write(ram,r[1],r[8],4);
goto P_0c05fb9c;
P_0c05fb9c: /* original d358, guest PC 0x0c05fb9c */
if(!s->budget--) { s->failed_pc=0x0c05fb9cu; return 0; }
r[3]=read(ram,0x0c05fd00u,4);
goto P_0c05fb9e;
P_0c05fb9e: /* original 2302, guest PC 0x0c05fb9e */
if(!s->budget--) { s->failed_pc=0x0c05fb9eu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05fba0;
P_0c05fba0: /* original d558, guest PC 0x0c05fba0 */
if(!s->budget--) { s->failed_pc=0x0c05fba0u; return 0; }
r[5]=read(ram,0x0c05fd04u,4);
goto P_0c05fba2;
P_0c05fba2: /* original d456, guest PC 0x0c05fba2 */
if(!s->budget--) { s->failed_pc=0x0c05fba2u; return 0; }
r[4]=read(ram,0x0c05fcfcu,4);
goto P_0c05fba4;
P_0c05fba4: /* original 4d0b, guest PC 0x0c05fba4 */
if(!s->budget--) { s->failed_pc=0x0c05fba4u; return 0; }
target=r[13];
r[16]=code_base|0x0c05fba8u;
r[6]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fba8u) { target=s->pc; goto dispatch; }
goto P_0c05fba8;
P_0c05fba6: /* original 66a3, guest PC 0x0c05fba6 */
if(!s->budget--) { s->failed_pc=0x0c05fba6u; return 0; }
r[6]=r[10];
goto P_0c05fba8;
P_0c05fba8: /* original d257, guest PC 0x0c05fba8 */
if(!s->budget--) { s->failed_pc=0x0c05fba8u; return 0; }
r[2]=read(ram,0x0c05fd08u,4);
goto P_0c05fbaa;
P_0c05fbaa: /* original 2202, guest PC 0x0c05fbaa */
if(!s->budget--) { s->failed_pc=0x0c05fbaau; return 0; }
write(ram,r[2],r[0],4);
goto P_0c05fbac;
P_0c05fbac: /* original d557, guest PC 0x0c05fbac */
if(!s->budget--) { s->failed_pc=0x0c05fbacu; return 0; }
r[5]=read(ram,0x0c05fd0cu,4);
goto P_0c05fbae;
P_0c05fbae: /* original e600, guest PC 0x0c05fbae */
if(!s->budget--) { s->failed_pc=0x0c05fbaeu; return 0; }
r[6]=0x00000000u;
goto P_0c05fbb0;
P_0c05fbb0: /* original 4d0b, guest PC 0x0c05fbb0 */
if(!s->budget--) { s->failed_pc=0x0c05fbb0u; return 0; }
target=r[13];
r[16]=code_base|0x0c05fbb4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fbb4u) { target=s->pc; goto dispatch; }
goto P_0c05fbb4;
P_0c05fbb2: /* original 64c3, guest PC 0x0c05fbb2 */
if(!s->budget--) { s->failed_pc=0x0c05fbb2u; return 0; }
r[4]=r[12];
goto P_0c05fbb4;
P_0c05fbb4: /* original d356, guest PC 0x0c05fbb4 */
if(!s->budget--) { s->failed_pc=0x0c05fbb4u; return 0; }
r[3]=read(ram,0x0c05fd10u,4);
goto P_0c05fbb6;
P_0c05fbb6: /* original 2302, guest PC 0x0c05fbb6 */
if(!s->budget--) { s->failed_pc=0x0c05fbb6u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05fbb8;
P_0c05fbb8: /* original d556, guest PC 0x0c05fbb8 */
if(!s->budget--) { s->failed_pc=0x0c05fbb8u; return 0; }
r[5]=read(ram,0x0c05fd14u,4);
goto P_0c05fbba;
P_0c05fbba: /* original e60a, guest PC 0x0c05fbba */
if(!s->budget--) { s->failed_pc=0x0c05fbbau; return 0; }
r[6]=0x0000000au;
goto P_0c05fbbc;
P_0c05fbbc: /* original 4d0b, guest PC 0x0c05fbbc */
if(!s->budget--) { s->failed_pc=0x0c05fbbcu; return 0; }
target=r[13];
r[16]=code_base|0x0c05fbc0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fbc0u) { target=s->pc; goto dispatch; }
goto P_0c05fbc0;
P_0c05fbbe: /* original 64c3, guest PC 0x0c05fbbe */
if(!s->budget--) { s->failed_pc=0x0c05fbbeu; return 0; }
r[4]=r[12];
goto P_0c05fbc0;
P_0c05fbc0: /* original d255, guest PC 0x0c05fbc0 */
if(!s->budget--) { s->failed_pc=0x0c05fbc0u; return 0; }
r[2]=read(ram,0x0c05fd18u,4);
goto P_0c05fbc2;
P_0c05fbc2: /* original 2202, guest PC 0x0c05fbc2 */
if(!s->budget--) { s->failed_pc=0x0c05fbc2u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c05fbc4;
P_0c05fbc4: /* original d555, guest PC 0x0c05fbc4 */
if(!s->budget--) { s->failed_pc=0x0c05fbc4u; return 0; }
r[5]=read(ram,0x0c05fd1cu,4);
goto P_0c05fbc6;
P_0c05fbc6: /* original e60a, guest PC 0x0c05fbc6 */
if(!s->budget--) { s->failed_pc=0x0c05fbc6u; return 0; }
r[6]=0x0000000au;
goto P_0c05fbc8;
P_0c05fbc8: /* original 4d0b, guest PC 0x0c05fbc8 */
if(!s->budget--) { s->failed_pc=0x0c05fbc8u; return 0; }
target=r[13];
r[16]=code_base|0x0c05fbccu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fbccu) { target=s->pc; goto dispatch; }
goto P_0c05fbcc;
P_0c05fbca: /* original 64c3, guest PC 0x0c05fbca */
if(!s->budget--) { s->failed_pc=0x0c05fbcau; return 0; }
r[4]=r[12];
goto P_0c05fbcc;
P_0c05fbcc: /* original d354, guest PC 0x0c05fbcc */
if(!s->budget--) { s->failed_pc=0x0c05fbccu; return 0; }
r[3]=read(ram,0x0c05fd20u,4);
goto P_0c05fbce;
P_0c05fbce: /* original 2302, guest PC 0x0c05fbce */
if(!s->budget--) { s->failed_pc=0x0c05fbceu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05fbd0;
P_0c05fbd0: /* original d554, guest PC 0x0c05fbd0 */
if(!s->budget--) { s->failed_pc=0x0c05fbd0u; return 0; }
r[5]=read(ram,0x0c05fd24u,4);
goto P_0c05fbd2;
P_0c05fbd2: /* original e60a, guest PC 0x0c05fbd2 */
if(!s->budget--) { s->failed_pc=0x0c05fbd2u; return 0; }
r[6]=0x0000000au;
goto P_0c05fbd4;
P_0c05fbd4: /* original 4d0b, guest PC 0x0c05fbd4 */
if(!s->budget--) { s->failed_pc=0x0c05fbd4u; return 0; }
target=r[13];
r[16]=code_base|0x0c05fbd8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fbd8u) { target=s->pc; goto dispatch; }
goto P_0c05fbd8;
P_0c05fbd6: /* original 64c3, guest PC 0x0c05fbd6 */
if(!s->budget--) { s->failed_pc=0x0c05fbd6u; return 0; }
r[4]=r[12];
goto P_0c05fbd8;
P_0c05fbd8: /* original d253, guest PC 0x0c05fbd8 */
if(!s->budget--) { s->failed_pc=0x0c05fbd8u; return 0; }
r[2]=read(ram,0x0c05fd28u,4);
goto P_0c05fbda;
P_0c05fbda: /* original 2202, guest PC 0x0c05fbda */
if(!s->budget--) { s->failed_pc=0x0c05fbdau; return 0; }
write(ram,r[2],r[0],4);
goto P_0c05fbdc;
P_0c05fbdc: /* original d353, guest PC 0x0c05fbdc */
if(!s->budget--) { s->failed_pc=0x0c05fbdcu; return 0; }
r[3]=read(ram,0x0c05fd2cu,4);
goto P_0c05fbde;
P_0c05fbde: /* original 23e2, guest PC 0x0c05fbde */
if(!s->budget--) { s->failed_pc=0x0c05fbdeu; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05fbe0;
P_0c05fbe0: /* original d153, guest PC 0x0c05fbe0 */
if(!s->budget--) { s->failed_pc=0x0c05fbe0u; return 0; }
r[1]=read(ram,0x0c05fd30u,4);
goto P_0c05fbe2;
P_0c05fbe2: /* original 2182, guest PC 0x0c05fbe2 */
if(!s->budget--) { s->failed_pc=0x0c05fbe2u; return 0; }
write(ram,r[1],r[8],4);
goto P_0c05fbe4;
P_0c05fbe4: /* original d053, guest PC 0x0c05fbe4 */
if(!s->budget--) { s->failed_pc=0x0c05fbe4u; return 0; }
r[0]=read(ram,0x0c05fd34u,4);
goto P_0c05fbe6;
P_0c05fbe6: /* original e20f, guest PC 0x0c05fbe6 */
if(!s->budget--) { s->failed_pc=0x0c05fbe6u; return 0; }
r[2]=0x0000000fu;
goto P_0c05fbe8;
P_0c05fbe8: /* original 2022, guest PC 0x0c05fbe8 */
if(!s->budget--) { s->failed_pc=0x0c05fbe8u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c05fbea;
P_0c05fbea: /* original 6302, guest PC 0x0c05fbea */
if(!s->budget--) { s->failed_pc=0x0c05fbeau; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05fbec;
P_0c05fbec: /* original 23eb, guest PC 0x0c05fbec */
if(!s->budget--) { s->failed_pc=0x0c05fbecu; return 0; }
r[3]|=r[14];
goto P_0c05fbee;
P_0c05fbee: /* original 2032, guest PC 0x0c05fbee */
if(!s->budget--) { s->failed_pc=0x0c05fbeeu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c05fbf0;
P_0c05fbf0: /* original d251, guest PC 0x0c05fbf0 */
if(!s->budget--) { s->failed_pc=0x0c05fbf0u; return 0; }
r[2]=read(ram,0x0c05fd38u,4);
goto P_0c05fbf2;
P_0c05fbf2: /* original 22e2, guest PC 0x0c05fbf2 */
if(!s->budget--) { s->failed_pc=0x0c05fbf2u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05fbf4;
P_0c05fbf4: /* original d351, guest PC 0x0c05fbf4 */
if(!s->budget--) { s->failed_pc=0x0c05fbf4u; return 0; }
r[3]=read(ram,0x0c05fd3cu,4);
goto P_0c05fbf6;
P_0c05fbf6: /* original beb5, guest PC 0x0c05fbf6 */
if(!s->budget--) { s->failed_pc=0x0c05fbf6u; return 0; }
target=code_base|0x0c05f964u; r[16]=code_base|0x0c05fbfau;
write(ram,r[3],r[14],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fbfau) { target=s->pc; goto dispatch; }
goto P_0c05fbfa;
P_0c05fbf8: /* original 23e2, guest PC 0x0c05fbf8 */
if(!s->budget--) { s->failed_pc=0x0c05fbf8u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05fbfa;
P_0c05fbfa: /* original d351, guest PC 0x0c05fbfa */
if(!s->budget--) { s->failed_pc=0x0c05fbfau; return 0; }
r[3]=read(ram,0x0c05fd40u,4);
goto P_0c05fbfc;
P_0c05fbfc: /* original 430b, guest PC 0x0c05fbfc */
if(!s->budget--) { s->failed_pc=0x0c05fbfcu; return 0; }
target=r[3];
r[16]=code_base|0x0c05fc00u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fc00u) { target=s->pc; goto dispatch; }
goto P_0c05fc00;
P_0c05fbfe: /* original 0009, guest PC 0x0c05fbfe */
if(!s->budget--) { s->failed_pc=0x0c05fbfeu; return 0; }
goto P_0c05fc00;
P_0c05fc00: /* original 7f0c, guest PC 0x0c05fc00 */
if(!s->budget--) { s->failed_pc=0x0c05fc00u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05fc02;
P_0c05fc02: /* original 4f26, guest PC 0x0c05fc02 */
if(!s->budget--) { s->failed_pc=0x0c05fc02u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05fc04;
P_0c05fc04: /* original 68f6, guest PC 0x0c05fc04 */
if(!s->budget--) { s->failed_pc=0x0c05fc04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05fc06;
P_0c05fc06: /* original 69f6, guest PC 0x0c05fc06 */
if(!s->budget--) { s->failed_pc=0x0c05fc06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05fc08;
P_0c05fc08: /* original 6af6, guest PC 0x0c05fc08 */
if(!s->budget--) { s->failed_pc=0x0c05fc08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05fc0a;
P_0c05fc0a: /* original 6bf6, guest PC 0x0c05fc0a */
if(!s->budget--) { s->failed_pc=0x0c05fc0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05fc0c;
P_0c05fc0c: /* original 6cf6, guest PC 0x0c05fc0c */
if(!s->budget--) { s->failed_pc=0x0c05fc0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05fc0e;
P_0c05fc0e: /* original 6df6, guest PC 0x0c05fc0e */
if(!s->budget--) { s->failed_pc=0x0c05fc0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05fc10;
P_0c05fc10: /* original 000b, guest PC 0x0c05fc10 */
if(!s->budget--) { s->failed_pc=0x0c05fc10u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05fc12: /* original 6ef6, guest PC 0x0c05fc12 */
if(!s->budget--) { s->failed_pc=0x0c05fc12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05fc14u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fc14u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
