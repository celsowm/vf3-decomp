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
int vf3_away_batch41_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c055be0u: goto P_0c055be0;
case 0x0c055be2u: goto P_0c055be2;
case 0x0c055be4u: goto P_0c055be4;
case 0x0c055be6u: goto P_0c055be6;
case 0x0c055be8u: goto P_0c055be8;
case 0x0c055beau: goto P_0c055bea;
case 0x0c055becu: goto P_0c055bec;
case 0x0c055beeu: goto P_0c055bee;
case 0x0c055bf0u: goto P_0c055bf0;
case 0x0c055bf2u: goto P_0c055bf2;
case 0x0c055bf4u: goto P_0c055bf4;
case 0x0c055bf6u: goto P_0c055bf6;
case 0x0c055bf8u: goto P_0c055bf8;
case 0x0c055bfau: goto P_0c055bfa;
case 0x0c055bfcu: goto P_0c055bfc;
case 0x0c055bfeu: goto P_0c055bfe;
case 0x0c055c00u: goto P_0c055c00;
case 0x0c055c02u: goto P_0c055c02;
case 0x0c055c04u: goto P_0c055c04;
case 0x0c055c06u: goto P_0c055c06;
case 0x0c055c08u: goto P_0c055c08;
case 0x0c055c0au: goto P_0c055c0a;
case 0x0c055c0cu: goto P_0c055c0c;
case 0x0c055c0eu: goto P_0c055c0e;
case 0x0c055c10u: goto P_0c055c10;
case 0x0c055c12u: goto P_0c055c12;
case 0x0c055c14u: goto P_0c055c14;
case 0x0c055c16u: goto P_0c055c16;
case 0x0c055c18u: goto P_0c055c18;
case 0x0c055c1au: goto P_0c055c1a;
case 0x0c055c1cu: goto P_0c055c1c;
case 0x0c055c1eu: goto P_0c055c1e;
case 0x0c055c20u: goto P_0c055c20;
case 0x0c055c22u: goto P_0c055c22;
case 0x0c055c24u: goto P_0c055c24;
case 0x0c055c26u: goto P_0c055c26;
case 0x0c055c28u: goto P_0c055c28;
case 0x0c055c2au: goto P_0c055c2a;
case 0x0c055c2cu: goto P_0c055c2c;
case 0x0c055c2eu: goto P_0c055c2e;
case 0x0c055c30u: goto P_0c055c30;
case 0x0c055c32u: goto P_0c055c32;
case 0x0c055c34u: goto P_0c055c34;
case 0x0c055c36u: goto P_0c055c36;
case 0x0c055c38u: goto P_0c055c38;
case 0x0c055c3au: goto P_0c055c3a;
case 0x0c055c3cu: goto P_0c055c3c;
case 0x0c055c3eu: goto P_0c055c3e;
case 0x0c055c40u: goto P_0c055c40;
case 0x0c055c42u: goto P_0c055c42;
case 0x0c055c44u: goto P_0c055c44;
case 0x0c055c46u: goto P_0c055c46;
case 0x0c055c48u: goto P_0c055c48;
case 0x0c055c4au: goto P_0c055c4a;
case 0x0c055c4cu: goto P_0c055c4c;
case 0x0c055c4eu: goto P_0c055c4e;
case 0x0c055c50u: goto P_0c055c50;
case 0x0c055c52u: goto P_0c055c52;
case 0x0c055c54u: goto P_0c055c54;
case 0x0c055c56u: goto P_0c055c56;
case 0x0c055c58u: goto P_0c055c58;
case 0x0c055c5au: goto P_0c055c5a;
case 0x0c055c5cu: goto P_0c055c5c;
case 0x0c072076u: goto P_0c072076;
case 0x0c072078u: goto P_0c072078;
case 0x0c07207au: goto P_0c07207a;
case 0x0c07207cu: goto P_0c07207c;
case 0x0c07207eu: goto P_0c07207e;
case 0x0c072080u: goto P_0c072080;
case 0x0c072082u: goto P_0c072082;
case 0x0c072084u: goto P_0c072084;
case 0x0c072086u: goto P_0c072086;
case 0x0c072088u: goto P_0c072088;
case 0x0c07208au: goto P_0c07208a;
case 0x0c07208cu: goto P_0c07208c;
case 0x0c07208eu: goto P_0c07208e;
case 0x0c072090u: goto P_0c072090;
case 0x0c072092u: goto P_0c072092;
case 0x0c072094u: goto P_0c072094;
case 0x0c072096u: goto P_0c072096;
case 0x0c072098u: goto P_0c072098;
case 0x0c07209au: goto P_0c07209a;
case 0x0c07209cu: goto P_0c07209c;
case 0x0c07209eu: goto P_0c07209e;
case 0x0c0720a0u: goto P_0c0720a0;
case 0x0c0720a2u: goto P_0c0720a2;
case 0x0c0720a4u: goto P_0c0720a4;
case 0x0c0720a6u: goto P_0c0720a6;
case 0x0c0720a8u: goto P_0c0720a8;
case 0x0c0720aau: goto P_0c0720aa;
case 0x0c0720acu: goto P_0c0720ac;
case 0x0c0720aeu: goto P_0c0720ae;
case 0x0c0720b0u: goto P_0c0720b0;
case 0x0c0720b2u: goto P_0c0720b2;
case 0x0c0720b4u: goto P_0c0720b4;
case 0x0c0720b6u: goto P_0c0720b6;
case 0x0c0720b8u: goto P_0c0720b8;
case 0x0c0720bau: goto P_0c0720ba;
case 0x0c0720bcu: goto P_0c0720bc;
case 0x0c0720beu: goto P_0c0720be;
case 0x0c0720c0u: goto P_0c0720c0;
case 0x0c0720c2u: goto P_0c0720c2;
case 0x0c0720c4u: goto P_0c0720c4;
case 0x0c0720c6u: goto P_0c0720c6;
case 0x0c0720c8u: goto P_0c0720c8;
case 0x0c0720cau: goto P_0c0720ca;
case 0x0c0720ccu: goto P_0c0720cc;
case 0x0c0720ceu: goto P_0c0720ce;
case 0x0c0720d0u: goto P_0c0720d0;
case 0x0c0720d2u: goto P_0c0720d2;
case 0x0c0720d4u: goto P_0c0720d4;
case 0x0c0720d6u: goto P_0c0720d6;
case 0x0c0720d8u: goto P_0c0720d8;
case 0x0c0720dau: goto P_0c0720da;
case 0x0c0720dcu: goto P_0c0720dc;
case 0x0c0720deu: goto P_0c0720de;
case 0x0c0720e0u: goto P_0c0720e0;
case 0x0c0720e2u: goto P_0c0720e2;
case 0x0c0720e4u: goto P_0c0720e4;
case 0x0c0720e6u: goto P_0c0720e6;
case 0x0c0720e8u: goto P_0c0720e8;
case 0x0c0720eau: goto P_0c0720ea;
case 0x0c0720ecu: goto P_0c0720ec;
case 0x0c0720eeu: goto P_0c0720ee;
case 0x0c0720f0u: goto P_0c0720f0;
case 0x0c0720f2u: goto P_0c0720f2;
case 0x0c0720f4u: goto P_0c0720f4;
case 0x0c0720f6u: goto P_0c0720f6;
case 0x0c072108u: goto P_0c072108;
case 0x0c07210au: goto P_0c07210a;
case 0x0c07210cu: goto P_0c07210c;
case 0x0c07210eu: goto P_0c07210e;
case 0x0c072110u: goto P_0c072110;
case 0x0c072112u: goto P_0c072112;
case 0x0c072114u: goto P_0c072114;
case 0x0c072116u: goto P_0c072116;
case 0x0c072118u: goto P_0c072118;
case 0x0c07211au: goto P_0c07211a;
case 0x0c07211cu: goto P_0c07211c;
case 0x0c07211eu: goto P_0c07211e;
case 0x0c072120u: goto P_0c072120;
case 0x0c072122u: goto P_0c072122;
case 0x0c072124u: goto P_0c072124;
case 0x0c072126u: goto P_0c072126;
case 0x0c072128u: goto P_0c072128;
case 0x0c07212au: goto P_0c07212a;
case 0x0c07212cu: goto P_0c07212c;
case 0x0c07212eu: goto P_0c07212e;
case 0x0c072130u: goto P_0c072130;
case 0x0c072132u: goto P_0c072132;
case 0x0c072134u: goto P_0c072134;
case 0x0c072136u: goto P_0c072136;
case 0x0c072138u: goto P_0c072138;
case 0x0c07213au: goto P_0c07213a;
case 0x0c07213cu: goto P_0c07213c;
case 0x0c07213eu: goto P_0c07213e;
case 0x0c072140u: goto P_0c072140;
case 0x0c072142u: goto P_0c072142;
case 0x0c072144u: goto P_0c072144;
case 0x0c072146u: goto P_0c072146;
case 0x0c072148u: goto P_0c072148;
case 0x0c07214au: goto P_0c07214a;
case 0x0c07214cu: goto P_0c07214c;
case 0x0c07214eu: goto P_0c07214e;
case 0x0c072150u: goto P_0c072150;
case 0x0c072152u: goto P_0c072152;
case 0x0c072154u: goto P_0c072154;
case 0x0c072156u: goto P_0c072156;
case 0x0c072158u: goto P_0c072158;
case 0x0c07215au: goto P_0c07215a;
case 0x0c07215cu: goto P_0c07215c;
case 0x0c07215eu: goto P_0c07215e;
case 0x0c072160u: goto P_0c072160;
case 0x0c072162u: goto P_0c072162;
case 0x0c072164u: goto P_0c072164;
case 0x0c072166u: goto P_0c072166;
case 0x0c072168u: goto P_0c072168;
case 0x0c07216au: goto P_0c07216a;
case 0x0c07216cu: goto P_0c07216c;
case 0x0c07216eu: goto P_0c07216e;
case 0x0c072170u: goto P_0c072170;
case 0x0c072172u: goto P_0c072172;
case 0x0c072174u: goto P_0c072174;
case 0x0c072176u: goto P_0c072176;
case 0x0c072178u: goto P_0c072178;
case 0x0c07217au: goto P_0c07217a;
case 0x0c07217cu: goto P_0c07217c;
case 0x0c07217eu: goto P_0c07217e;
case 0x0c072180u: goto P_0c072180;
case 0x0c072182u: goto P_0c072182;
case 0x0c072184u: goto P_0c072184;
case 0x0c072186u: goto P_0c072186;
case 0x0c072188u: goto P_0c072188;
case 0x0c07218au: goto P_0c07218a;
case 0x0c07218cu: goto P_0c07218c;
case 0x0c07218eu: goto P_0c07218e;
case 0x0c072190u: goto P_0c072190;
case 0x0c072192u: goto P_0c072192;
case 0x0c072194u: goto P_0c072194;
case 0x0c072196u: goto P_0c072196;
case 0x0c072198u: goto P_0c072198;
case 0x0c07219au: goto P_0c07219a;
case 0x0c07219cu: goto P_0c07219c;
case 0x0c07219eu: goto P_0c07219e;
case 0x0c0721a0u: goto P_0c0721a0;
case 0x0c0721a2u: goto P_0c0721a2;
case 0x0c0721a4u: goto P_0c0721a4;
case 0x0c0721a6u: goto P_0c0721a6;
case 0x0c0721a8u: goto P_0c0721a8;
case 0x0c0721aau: goto P_0c0721aa;
case 0x0c0721acu: goto P_0c0721ac;
case 0x0c0721aeu: goto P_0c0721ae;
case 0x0c0721b0u: goto P_0c0721b0;
case 0x0c0721b2u: goto P_0c0721b2;
case 0x0c0721b4u: goto P_0c0721b4;
case 0x0c0721b6u: goto P_0c0721b6;
case 0x0c0721b8u: goto P_0c0721b8;
case 0x0c0721bau: goto P_0c0721ba;
case 0x0c0721bcu: goto P_0c0721bc;
case 0x0c0721beu: goto P_0c0721be;
case 0x0c0721c0u: goto P_0c0721c0;
case 0x0c0721c2u: goto P_0c0721c2;
case 0x0c0721c4u: goto P_0c0721c4;
case 0x0c0721c6u: goto P_0c0721c6;
case 0x0c0721c8u: goto P_0c0721c8;
case 0x0c0721cau: goto P_0c0721ca;
case 0x0c0721ccu: goto P_0c0721cc;
case 0x0c0721ceu: goto P_0c0721ce;
case 0x0c0721d0u: goto P_0c0721d0;
case 0x0c0721d2u: goto P_0c0721d2;
case 0x0c0721d4u: goto P_0c0721d4;
case 0x0c0721d6u: goto P_0c0721d6;
case 0x0c0721d8u: goto P_0c0721d8;
case 0x0c0721dau: goto P_0c0721da;
case 0x0c0721dcu: goto P_0c0721dc;
case 0x0c0721deu: goto P_0c0721de;
case 0x0c0721e0u: goto P_0c0721e0;
case 0x0c0721e2u: goto P_0c0721e2;
case 0x0c0721e4u: goto P_0c0721e4;
case 0x0c0721e6u: goto P_0c0721e6;
case 0x0c0721e8u: goto P_0c0721e8;
case 0x0c0721eau: goto P_0c0721ea;
case 0x0c0721ecu: goto P_0c0721ec;
case 0x0c0721eeu: goto P_0c0721ee;
case 0x0c0721f0u: goto P_0c0721f0;
case 0x0c0721f2u: goto P_0c0721f2;
case 0x0c0721f4u: goto P_0c0721f4;
case 0x0c0721f6u: goto P_0c0721f6;
case 0x0c0721f8u: goto P_0c0721f8;
case 0x0c0721fau: goto P_0c0721fa;
case 0x0c0721fcu: goto P_0c0721fc;
case 0x0c0721feu: goto P_0c0721fe;
case 0x0c072200u: goto P_0c072200;
case 0x0c072202u: goto P_0c072202;
case 0x0c072204u: goto P_0c072204;
case 0x0c072206u: goto P_0c072206;
case 0x0c072208u: goto P_0c072208;
case 0x0c07220au: goto P_0c07220a;
case 0x0c07220cu: goto P_0c07220c;
case 0x0c07220eu: goto P_0c07220e;
case 0x0c072210u: goto P_0c072210;
case 0x0c072212u: goto P_0c072212;
case 0x0c072214u: goto P_0c072214;
case 0x0c072216u: goto P_0c072216;
case 0x0c072218u: goto P_0c072218;
case 0x0c07221au: goto P_0c07221a;
case 0x0c07221cu: goto P_0c07221c;
case 0x0c07221eu: goto P_0c07221e;
case 0x0c072220u: goto P_0c072220;
case 0x0c072222u: goto P_0c072222;
case 0x0c072224u: goto P_0c072224;
case 0x0c072226u: goto P_0c072226;
case 0x0c072228u: goto P_0c072228;
case 0x0c07222au: goto P_0c07222a;
case 0x0c07222cu: goto P_0c07222c;
case 0x0c07222eu: goto P_0c07222e;
case 0x0c072230u: goto P_0c072230;
case 0x0c072232u: goto P_0c072232;
case 0x0c072234u: goto P_0c072234;
case 0x0c072236u: goto P_0c072236;
case 0x0c072238u: goto P_0c072238;
case 0x0c07223au: goto P_0c07223a;
case 0x0c07223cu: goto P_0c07223c;
case 0x0c07223eu: goto P_0c07223e;
case 0x0c072240u: goto P_0c072240;
case 0x0c072242u: goto P_0c072242;
case 0x0c072244u: goto P_0c072244;
case 0x0c072246u: goto P_0c072246;
case 0x0c072248u: goto P_0c072248;
case 0x0c07224au: goto P_0c07224a;
case 0x0c07224cu: goto P_0c07224c;
case 0x0c07224eu: goto P_0c07224e;
case 0x0c072250u: goto P_0c072250;
case 0x0c072252u: goto P_0c072252;
case 0x0c072254u: goto P_0c072254;
case 0x0c072256u: goto P_0c072256;
case 0x0c072258u: goto P_0c072258;
case 0x0c07225au: goto P_0c07225a;
case 0x0c07225cu: goto P_0c07225c;
case 0x0c07225eu: goto P_0c07225e;
case 0x0c072260u: goto P_0c072260;
case 0x0c072262u: goto P_0c072262;
case 0x0c072264u: goto P_0c072264;
case 0x0c072266u: goto P_0c072266;
case 0x0c072268u: goto P_0c072268;
case 0x0c07226au: goto P_0c07226a;
case 0x0c07226cu: goto P_0c07226c;
case 0x0c07226eu: goto P_0c07226e;
case 0x0c072270u: goto P_0c072270;
case 0x0c072272u: goto P_0c072272;
case 0x0c072274u: goto P_0c072274;
case 0x0c072276u: goto P_0c072276;
case 0x0c072278u: goto P_0c072278;
case 0x0c07227au: goto P_0c07227a;
case 0x0c07227cu: goto P_0c07227c;
case 0x0c07227eu: goto P_0c07227e;
case 0x0c072284u: goto P_0c072284;
case 0x0c072286u: goto P_0c072286;
case 0x0c072288u: goto P_0c072288;
case 0x0c07228au: goto P_0c07228a;
case 0x0c07228cu: goto P_0c07228c;
case 0x0c07228eu: goto P_0c07228e;
case 0x0c072290u: goto P_0c072290;
case 0x0c072292u: goto P_0c072292;
case 0x0c072294u: goto P_0c072294;
case 0x0c072296u: goto P_0c072296;
case 0x0c072298u: goto P_0c072298;
case 0x0c07229au: goto P_0c07229a;
case 0x0c07229cu: goto P_0c07229c;
case 0x0c07229eu: goto P_0c07229e;
case 0x0c0722a0u: goto P_0c0722a0;
case 0x0c0722a2u: goto P_0c0722a2;
case 0x0c0722a4u: goto P_0c0722a4;
case 0x0c0722a6u: goto P_0c0722a6;
case 0x0c0722a8u: goto P_0c0722a8;
case 0x0c0722aau: goto P_0c0722aa;
case 0x0c0722acu: goto P_0c0722ac;
case 0x0c0722aeu: goto P_0c0722ae;
case 0x0c0722b0u: goto P_0c0722b0;
case 0x0c0722b2u: goto P_0c0722b2;
case 0x0c0722b4u: goto P_0c0722b4;
case 0x0c0722b6u: goto P_0c0722b6;
case 0x0c0722b8u: goto P_0c0722b8;
case 0x0c0722bau: goto P_0c0722ba;
case 0x0c0722bcu: goto P_0c0722bc;
case 0x0c0722beu: goto P_0c0722be;
case 0x0c0722c0u: goto P_0c0722c0;
case 0x0c0722c2u: goto P_0c0722c2;
case 0x0c0722c4u: goto P_0c0722c4;
case 0x0c0722c6u: goto P_0c0722c6;
case 0x0c0722c8u: goto P_0c0722c8;
case 0x0c0722cau: goto P_0c0722ca;
case 0x0c0722ccu: goto P_0c0722cc;
case 0x0c0722ceu: goto P_0c0722ce;
case 0x0c0722d0u: goto P_0c0722d0;
case 0x0c0722d2u: goto P_0c0722d2;
case 0x0c0722d4u: goto P_0c0722d4;
case 0x0c0722d6u: goto P_0c0722d6;
case 0x0c0722d8u: goto P_0c0722d8;
case 0x0c0722dau: goto P_0c0722da;
case 0x0c0722dcu: goto P_0c0722dc;
case 0x0c0722deu: goto P_0c0722de;
case 0x0c0722e0u: goto P_0c0722e0;
case 0x0c0722e2u: goto P_0c0722e2;
case 0x0c0722e4u: goto P_0c0722e4;
case 0x0c0722e6u: goto P_0c0722e6;
case 0x0c0722e8u: goto P_0c0722e8;
case 0x0c0722eau: goto P_0c0722ea;
case 0x0c0722ecu: goto P_0c0722ec;
case 0x0c0722eeu: goto P_0c0722ee;
case 0x0c0722f0u: goto P_0c0722f0;
case 0x0c0722f2u: goto P_0c0722f2;
case 0x0c0722f4u: goto P_0c0722f4;
case 0x0c0722f6u: goto P_0c0722f6;
case 0x0c0722f8u: goto P_0c0722f8;
case 0x0c0722fau: goto P_0c0722fa;
case 0x0c0722fcu: goto P_0c0722fc;
case 0x0c0722feu: goto P_0c0722fe;
case 0x0c072300u: goto P_0c072300;
case 0x0c072302u: goto P_0c072302;
case 0x0c072304u: goto P_0c072304;
case 0x0c072306u: goto P_0c072306;
case 0x0c072308u: goto P_0c072308;
case 0x0c07230au: goto P_0c07230a;
case 0x0c07230cu: goto P_0c07230c;
case 0x0c07230eu: goto P_0c07230e;
case 0x0c072310u: goto P_0c072310;
case 0x0c072312u: goto P_0c072312;
case 0x0c072314u: goto P_0c072314;
case 0x0c072316u: goto P_0c072316;
case 0x0c072318u: goto P_0c072318;
case 0x0c07231au: goto P_0c07231a;
case 0x0c07231cu: goto P_0c07231c;
case 0x0c07231eu: goto P_0c07231e;
case 0x0c072320u: goto P_0c072320;
case 0x0c072322u: goto P_0c072322;
case 0x0c072324u: goto P_0c072324;
case 0x0c072326u: goto P_0c072326;
case 0x0c072328u: goto P_0c072328;
case 0x0c07232au: goto P_0c07232a;
case 0x0c07232cu: goto P_0c07232c;
case 0x0c07232eu: goto P_0c07232e;
case 0x0c072330u: goto P_0c072330;
case 0x0c072332u: goto P_0c072332;
case 0x0c072334u: goto P_0c072334;
case 0x0c072b40u: goto P_0c072b40;
case 0x0c072b42u: goto P_0c072b42;
case 0x0c072b44u: goto P_0c072b44;
case 0x0c072b46u: goto P_0c072b46;
case 0x0c072b48u: goto P_0c072b48;
case 0x0c072b4au: goto P_0c072b4a;
case 0x0c072b4cu: goto P_0c072b4c;
case 0x0c072b4eu: goto P_0c072b4e;
case 0x0c072b50u: goto P_0c072b50;
case 0x0c072b52u: goto P_0c072b52;
case 0x0c072b54u: goto P_0c072b54;
case 0x0c072b56u: goto P_0c072b56;
case 0x0c072b58u: goto P_0c072b58;
case 0x0c072b5au: goto P_0c072b5a;
case 0x0c072b5cu: goto P_0c072b5c;
case 0x0c072b5eu: goto P_0c072b5e;
case 0x0c072b60u: goto P_0c072b60;
case 0x0c072b62u: goto P_0c072b62;
case 0x0c072b64u: goto P_0c072b64;
case 0x0c072b66u: goto P_0c072b66;
case 0x0c072b68u: goto P_0c072b68;
case 0x0c072b6au: goto P_0c072b6a;
case 0x0c072b6cu: goto P_0c072b6c;
case 0x0c072b6eu: goto P_0c072b6e;
case 0x0c072b70u: goto P_0c072b70;
case 0x0c072b72u: goto P_0c072b72;
case 0x0c072b74u: goto P_0c072b74;
case 0x0c072b76u: goto P_0c072b76;
case 0x0c072b78u: goto P_0c072b78;
case 0x0c072b7au: goto P_0c072b7a;
case 0x0c072b7cu: goto P_0c072b7c;
case 0x0c072b7eu: goto P_0c072b7e;
case 0x0c072b80u: goto P_0c072b80;
case 0x0c072b82u: goto P_0c072b82;
case 0x0c072b84u: goto P_0c072b84;
case 0x0c072b86u: goto P_0c072b86;
case 0x0c072b88u: goto P_0c072b88;
case 0x0c072b8au: goto P_0c072b8a;
case 0x0c072b8cu: goto P_0c072b8c;
case 0x0c072b8eu: goto P_0c072b8e;
case 0x0c072b90u: goto P_0c072b90;
case 0x0c072b92u: goto P_0c072b92;
case 0x0c072b94u: goto P_0c072b94;
case 0x0c072b96u: goto P_0c072b96;
case 0x0c072b98u: goto P_0c072b98;
case 0x0c072b9au: goto P_0c072b9a;
case 0x0c072b9cu: goto P_0c072b9c;
case 0x0c072b9eu: goto P_0c072b9e;
case 0x0c072ba0u: goto P_0c072ba0;
case 0x0c072ba2u: goto P_0c072ba2;
case 0x0c072ba4u: goto P_0c072ba4;
case 0x0c072ba6u: goto P_0c072ba6;
case 0x0c072ba8u: goto P_0c072ba8;
case 0x0c072baau: goto P_0c072baa;
case 0x0c072bacu: goto P_0c072bac;
case 0x0c072baeu: goto P_0c072bae;
case 0x0c072bb0u: goto P_0c072bb0;
case 0x0c072bb2u: goto P_0c072bb2;
case 0x0c072bb4u: goto P_0c072bb4;
case 0x0c072bb6u: goto P_0c072bb6;
case 0x0c072bb8u: goto P_0c072bb8;
case 0x0c072bbau: goto P_0c072bba;
case 0x0c072bd0u: goto P_0c072bd0;
case 0x0c072bd2u: goto P_0c072bd2;
case 0x0c072bd4u: goto P_0c072bd4;
case 0x0c072bd6u: goto P_0c072bd6;
case 0x0c072bd8u: goto P_0c072bd8;
case 0x0c072bdau: goto P_0c072bda;
case 0x0c072bdcu: goto P_0c072bdc;
case 0x0c072bdeu: goto P_0c072bde;
case 0x0c072be0u: goto P_0c072be0;
case 0x0c072be2u: goto P_0c072be2;
case 0x0c072be4u: goto P_0c072be4;
case 0x0c072be6u: goto P_0c072be6;
case 0x0c072be8u: goto P_0c072be8;
case 0x0c072beau: goto P_0c072bea;
case 0x0c072becu: goto P_0c072bec;
case 0x0c072beeu: goto P_0c072bee;
case 0x0c072bf0u: goto P_0c072bf0;
case 0x0c072bf2u: goto P_0c072bf2;
case 0x0c072bf4u: goto P_0c072bf4;
case 0x0c072bf6u: goto P_0c072bf6;
case 0x0c072bf8u: goto P_0c072bf8;
case 0x0c072bfau: goto P_0c072bfa;
case 0x0c072bfcu: goto P_0c072bfc;
case 0x0c072bfeu: goto P_0c072bfe;
case 0x0c072c00u: goto P_0c072c00;
case 0x0c072c02u: goto P_0c072c02;
case 0x0c072c04u: goto P_0c072c04;
case 0x0c072c06u: goto P_0c072c06;
case 0x0c072c08u: goto P_0c072c08;
case 0x0c072c0au: goto P_0c072c0a;
case 0x0c072c0cu: goto P_0c072c0c;
case 0x0c072c0eu: goto P_0c072c0e;
case 0x0c072c10u: goto P_0c072c10;
case 0x0c072c12u: goto P_0c072c12;
case 0x0c072c14u: goto P_0c072c14;
case 0x0c072c16u: goto P_0c072c16;
case 0x0c072c18u: goto P_0c072c18;
case 0x0c072c1au: goto P_0c072c1a;
case 0x0c072c1cu: goto P_0c072c1c;
case 0x0c072c1eu: goto P_0c072c1e;
case 0x0c072c20u: goto P_0c072c20;
case 0x0c072c22u: goto P_0c072c22;
case 0x0c072c24u: goto P_0c072c24;
case 0x0c072c26u: goto P_0c072c26;
case 0x0c072c28u: goto P_0c072c28;
case 0x0c072c2au: goto P_0c072c2a;
case 0x0c072c2cu: goto P_0c072c2c;
case 0x0c072c2eu: goto P_0c072c2e;
case 0x0c072c30u: goto P_0c072c30;
case 0x0c072c32u: goto P_0c072c32;
case 0x0c072c34u: goto P_0c072c34;
case 0x0c072c36u: goto P_0c072c36;
case 0x0c072c38u: goto P_0c072c38;
case 0x0c072c3au: goto P_0c072c3a;
case 0x0c072c3cu: goto P_0c072c3c;
case 0x0c072c3eu: goto P_0c072c3e;
case 0x0c072c40u: goto P_0c072c40;
case 0x0c072c42u: goto P_0c072c42;
case 0x0c072c44u: goto P_0c072c44;
case 0x0c072c46u: goto P_0c072c46;
case 0x0c072c48u: goto P_0c072c48;
case 0x0c072c4au: goto P_0c072c4a;
case 0x0c072c4cu: goto P_0c072c4c;
case 0x0c072c4eu: goto P_0c072c4e;
case 0x0c072c6cu: goto P_0c072c6c;
case 0x0c072c6eu: goto P_0c072c6e;
case 0x0c072c70u: goto P_0c072c70;
case 0x0c072c72u: goto P_0c072c72;
case 0x0c072c74u: goto P_0c072c74;
case 0x0c072c76u: goto P_0c072c76;
case 0x0c072c78u: goto P_0c072c78;
case 0x0c072c7au: goto P_0c072c7a;
case 0x0c072c7cu: goto P_0c072c7c;
case 0x0c072c7eu: goto P_0c072c7e;
case 0x0c072c80u: goto P_0c072c80;
case 0x0c072c82u: goto P_0c072c82;
case 0x0c072c84u: goto P_0c072c84;
case 0x0c072c86u: goto P_0c072c86;
case 0x0c072c88u: goto P_0c072c88;
case 0x0c072c8au: goto P_0c072c8a;
case 0x0c072c8cu: goto P_0c072c8c;
case 0x0c072c8eu: goto P_0c072c8e;
case 0x0c072c90u: goto P_0c072c90;
case 0x0c072c92u: goto P_0c072c92;
case 0x0c072c94u: goto P_0c072c94;
case 0x0c072c96u: goto P_0c072c96;
case 0x0c072c98u: goto P_0c072c98;
case 0x0c072c9au: goto P_0c072c9a;
case 0x0c072c9cu: goto P_0c072c9c;
case 0x0c072c9eu: goto P_0c072c9e;
case 0x0c072ca0u: goto P_0c072ca0;
case 0x0c072ca2u: goto P_0c072ca2;
case 0x0c072ca4u: goto P_0c072ca4;
case 0x0c072ca6u: goto P_0c072ca6;
case 0x0c072ca8u: goto P_0c072ca8;
case 0x0c072caau: goto P_0c072caa;
case 0x0c072cacu: goto P_0c072cac;
case 0x0c072caeu: goto P_0c072cae;
case 0x0c072cb0u: goto P_0c072cb0;
case 0x0c072cb2u: goto P_0c072cb2;
case 0x0c072cb4u: goto P_0c072cb4;
case 0x0c072cb6u: goto P_0c072cb6;
case 0x0c072cb8u: goto P_0c072cb8;
case 0x0c072cbau: goto P_0c072cba;
case 0x0c072cbcu: goto P_0c072cbc;
case 0x0c072cbeu: goto P_0c072cbe;
case 0x0c072cc0u: goto P_0c072cc0;
case 0x0c072cc2u: goto P_0c072cc2;
case 0x0c072cc4u: goto P_0c072cc4;
case 0x0c072cc6u: goto P_0c072cc6;
case 0x0c072cc8u: goto P_0c072cc8;
case 0x0c072ccau: goto P_0c072cca;
case 0x0c072cccu: goto P_0c072ccc;
case 0x0c072cceu: goto P_0c072cce;
case 0x0c072cd0u: goto P_0c072cd0;
case 0x0c072cd2u: goto P_0c072cd2;
case 0x0c072cd4u: goto P_0c072cd4;
case 0x0c072cd6u: goto P_0c072cd6;
case 0x0c072cd8u: goto P_0c072cd8;
case 0x0c072cdau: goto P_0c072cda;
case 0x0c072cdcu: goto P_0c072cdc;
case 0x0c072cdeu: goto P_0c072cde;
case 0x0c072ce0u: goto P_0c072ce0;
case 0x0c072ce2u: goto P_0c072ce2;
case 0x0c072ce4u: goto P_0c072ce4;
case 0x0c072ce6u: goto P_0c072ce6;
case 0x0c072ce8u: goto P_0c072ce8;
case 0x0c072ceau: goto P_0c072cea;
case 0x0c072cecu: goto P_0c072cec;
case 0x0c072ceeu: goto P_0c072cee;
case 0x0c072cf0u: goto P_0c072cf0;
case 0x0c072cf2u: goto P_0c072cf2;
case 0x0c072cf4u: goto P_0c072cf4;
case 0x0c072cf6u: goto P_0c072cf6;
case 0x0c072cf8u: goto P_0c072cf8;
case 0x0c072cfau: goto P_0c072cfa;
default: return vf3_matrix_family(target,s,ram);
}
P_0c055be0: /* original d01f, guest PC 0x0c055be0 */
if(!s->budget--) { s->failed_pc=0x0c055be0u; return 0; }
r[0]=read(ram,0x0c055c60u,4);
goto P_0c055be2;
P_0c055be2: /* original e100, guest PC 0x0c055be2 */
if(!s->budget--) { s->failed_pc=0x0c055be2u; return 0; }
r[1]=0x00000000u;
goto P_0c055be4;
P_0c055be4: /* original 2012, guest PC 0x0c055be4 */
if(!s->budget--) { s->failed_pc=0x0c055be4u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c055be6;
P_0c055be6: /* original fffb, guest PC 0x0c055be6 */
if(!s->budget--) { s->failed_pc=0x0c055be6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c055be8;
P_0c055be8: /* original ffeb, guest PC 0x0c055be8 */
if(!s->budget--) { s->failed_pc=0x0c055be8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c055bea;
P_0c055bea: /* original ffdb, guest PC 0x0c055bea */
if(!s->budget--) { s->failed_pc=0x0c055beau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c055bec;
P_0c055bec: /* original ffcb, guest PC 0x0c055bec */
if(!s->budget--) { s->failed_pc=0x0c055becu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c055bee;
P_0c055bee: /* original 2fe6, guest PC 0x0c055bee */
if(!s->budget--) { s->failed_pc=0x0c055beeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf0;
P_0c055bf0: /* original 2fd6, guest PC 0x0c055bf0 */
if(!s->budget--) { s->failed_pc=0x0c055bf0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf2;
P_0c055bf2: /* original 2fc6, guest PC 0x0c055bf2 */
if(!s->budget--) { s->failed_pc=0x0c055bf2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf4;
P_0c055bf4: /* original 2fb6, guest PC 0x0c055bf4 */
if(!s->budget--) { s->failed_pc=0x0c055bf4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf6;
P_0c055bf6: /* original 2fa6, guest PC 0x0c055bf6 */
if(!s->budget--) { s->failed_pc=0x0c055bf6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf8;
P_0c055bf8: /* original 2f96, guest PC 0x0c055bf8 */
if(!s->budget--) { s->failed_pc=0x0c055bf8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bfa;
P_0c055bfa: /* original 2f86, guest PC 0x0c055bfa */
if(!s->budget--) { s->failed_pc=0x0c055bfau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bfc;
P_0c055bfc: /* original 4f22, guest PC 0x0c055bfc */
if(!s->budget--) { s->failed_pc=0x0c055bfcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055bfe;
P_0c055bfe: /* original 6e43, guest PC 0x0c055bfe */
if(!s->budget--) { s->failed_pc=0x0c055bfeu; return 0; }
r[14]=r[4];
goto P_0c055c00;
P_0c055c00: /* original d348, guest PC 0x0c055c00 */
if(!s->budget--) { s->failed_pc=0x0c055c00u; return 0; }
r[3]=read(ram,0x0c055d24u,4);
goto P_0c055c02;
P_0c055c02: /* original 430b, guest PC 0x0c055c02 */
if(!s->budget--) { s->failed_pc=0x0c055c02u; return 0; }
target=r[3];
r[16]=code_base|0x0c055c06u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c06u) { target=s->pc; goto dispatch; }
goto P_0c055c06;
P_0c055c04: /* original e400, guest PC 0x0c055c04 */
if(!s->budget--) { s->failed_pc=0x0c055c04u; return 0; }
r[4]=0x00000000u;
goto P_0c055c06;
P_0c055c06: /* original c605, guest PC 0x0c055c06 */
if(!s->budget--) { s->failed_pc=0x0c055c06u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+20,4);
goto P_0c055c08;
P_0c055c08: /* original 400b, guest PC 0x0c055c08 */
if(!s->budget--) { s->failed_pc=0x0c055c08u; return 0; }
target=r[0];
r[16]=code_base|0x0c055c0cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c0cu) { target=s->pc; goto dispatch; }
goto P_0c055c0c;
P_0c055c0a: /* original 0009, guest PC 0x0c055c0a */
if(!s->budget--) { s->failed_pc=0x0c055c0au; return 0; }
goto P_0c055c0c;
P_0c055c0c: /* original d347, guest PC 0x0c055c0c */
if(!s->budget--) { s->failed_pc=0x0c055c0cu; return 0; }
r[3]=read(ram,0x0c055d2cu,4);
goto P_0c055c0e;
P_0c055c0e: /* original c749, guest PC 0x0c055c0e */
if(!s->budget--) { s->failed_pc=0x0c055c0eu; return 0; }
r[0]=code_base|0x00055d34u;
goto P_0c055c10;
P_0c055c10: /* original 6106, guest PC 0x0c055c10 */
if(!s->budget--) { s->failed_pc=0x0c055c10u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055c12;
P_0c055c12: /* original f418, guest PC 0x0c055c12 */
if(!s->budget--) { s->failed_pc=0x0c055c12u; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
goto P_0c055c14;
P_0c055c14: /* original 6106, guest PC 0x0c055c14 */
if(!s->budget--) { s->failed_pc=0x0c055c14u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055c16;
P_0c055c16: /* original 430b, guest PC 0x0c055c16 */
if(!s->budget--) { s->failed_pc=0x0c055c16u; return 0; }
target=r[3];
r[16]=code_base|0x0c055c1au;
vf3_matrix_load(s,ram,5,r[1]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c1au) { target=s->pc; goto dispatch; }
goto P_0c055c1a;
P_0c055c18: /* original f518, guest PC 0x0c055c18 */
if(!s->budget--) { s->failed_pc=0x0c055c18u; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
goto P_0c055c1a;
P_0c055c1a: /* original 54e1, guest PC 0x0c055c1a */
if(!s->budget--) { s->failed_pc=0x0c055c1au; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c055c1c;
P_0c055c1c: /* original c60b, guest PC 0x0c055c1c */
if(!s->budget--) { s->failed_pc=0x0c055c1cu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+44,4);
goto P_0c055c1e;
P_0c055c1e: /* original 6503, guest PC 0x0c055c1e */
if(!s->budget--) { s->failed_pc=0x0c055c1eu; return 0; }
r[5]=r[0];
goto P_0c055c20;
P_0c055c20: /* original c604, guest PC 0x0c055c20 */
if(!s->budget--) { s->failed_pc=0x0c055c20u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+16,4);
goto P_0c055c22;
P_0c055c22: /* original 67e3, guest PC 0x0c055c22 */
if(!s->budget--) { s->failed_pc=0x0c055c22u; return 0; }
r[7]=r[14];
goto P_0c055c24;
P_0c055c24: /* original 400b, guest PC 0x0c055c24 */
if(!s->budget--) { s->failed_pc=0x0c055c24u; return 0; }
target=r[0];
r[16]=code_base|0x0c055c28u;
r[6]=read(ram,r[14]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c28u) { target=s->pc; goto dispatch; }
goto P_0c055c28;
P_0c055c26: /* original 56e2, guest PC 0x0c055c26 */
if(!s->budget--) { s->failed_pc=0x0c055c26u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c055c28;
P_0c055c28: /* original d33f, guest PC 0x0c055c28 */
if(!s->budget--) { s->failed_pc=0x0c055c28u; return 0; }
r[3]=read(ram,0x0c055d28u,4);
goto P_0c055c2a;
P_0c055c2a: /* original 430b, guest PC 0x0c055c2a */
if(!s->budget--) { s->failed_pc=0x0c055c2au; return 0; }
target=r[3];
r[16]=code_base|0x0c055c2eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c2eu) { target=s->pc; goto dispatch; }
goto P_0c055c2e;
P_0c055c2c: /* original e401, guest PC 0x0c055c2c */
if(!s->budget--) { s->failed_pc=0x0c055c2cu; return 0; }
r[4]=0x00000001u;
goto P_0c055c2e;
P_0c055c2e: /* original 64e3, guest PC 0x0c055c2e */
if(!s->budget--) { s->failed_pc=0x0c055c2eu; return 0; }
r[4]=r[14];
goto P_0c055c30;
P_0c055c30: /* original e001, guest PC 0x0c055c30 */
if(!s->budget--) { s->failed_pc=0x0c055c30u; return 0; }
r[0]=0x00000001u;
goto P_0c055c32;
P_0c055c32: /* original d10c, guest PC 0x0c055c32 */
if(!s->budget--) { s->failed_pc=0x0c055c32u; return 0; }
r[1]=read(ram,0x0c055c64u,4);
goto P_0c055c34;
P_0c055c34: /* original 410b, guest PC 0x0c055c34 */
if(!s->budget--) { s->failed_pc=0x0c055c34u; return 0; }
target=r[1];
r[16]=code_base|0x0c055c38u;
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+68,r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c38u) { target=s->pc; goto dispatch; }
goto P_0c055c38;
P_0c055c36: /* original c211, guest PC 0x0c055c36 */
if(!s->budget--) { s->failed_pc=0x0c055c36u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+68,r[0],4);
goto P_0c055c38;
P_0c055c38: /* original c60c, guest PC 0x0c055c38 */
if(!s->budget--) { s->failed_pc=0x0c055c38u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+48,4);
goto P_0c055c3a;
P_0c055c3a: /* original c20b, guest PC 0x0c055c3a */
if(!s->budget--) { s->failed_pc=0x0c055c3au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+44,r[0],4);
goto P_0c055c3c;
P_0c055c3c: /* original c60f, guest PC 0x0c055c3c */
if(!s->budget--) { s->failed_pc=0x0c055c3cu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+60,4);
goto P_0c055c3e;
P_0c055c3e: /* original c20e, guest PC 0x0c055c3e */
if(!s->budget--) { s->failed_pc=0x0c055c3eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+56,r[0],4);
goto P_0c055c40;
P_0c055c40: /* original e000, guest PC 0x0c055c40 */
if(!s->budget--) { s->failed_pc=0x0c055c40u; return 0; }
r[0]=0x00000000u;
goto P_0c055c42;
P_0c055c42: /* original c211, guest PC 0x0c055c42 */
if(!s->budget--) { s->failed_pc=0x0c055c42u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+68,r[0],4);
goto P_0c055c44;
P_0c055c44: /* original 4f26, guest PC 0x0c055c44 */
if(!s->budget--) { s->failed_pc=0x0c055c44u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055c46;
P_0c055c46: /* original 68f6, guest PC 0x0c055c46 */
if(!s->budget--) { s->failed_pc=0x0c055c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c055c48;
P_0c055c48: /* original 69f6, guest PC 0x0c055c48 */
if(!s->budget--) { s->failed_pc=0x0c055c48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c055c4a;
P_0c055c4a: /* original 6af6, guest PC 0x0c055c4a */
if(!s->budget--) { s->failed_pc=0x0c055c4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c055c4c;
P_0c055c4c: /* original 6bf6, guest PC 0x0c055c4c */
if(!s->budget--) { s->failed_pc=0x0c055c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c055c4e;
P_0c055c4e: /* original 6cf6, guest PC 0x0c055c4e */
if(!s->budget--) { s->failed_pc=0x0c055c4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c055c50;
P_0c055c50: /* original 6df6, guest PC 0x0c055c50 */
if(!s->budget--) { s->failed_pc=0x0c055c50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055c52;
P_0c055c52: /* original 6ef6, guest PC 0x0c055c52 */
if(!s->budget--) { s->failed_pc=0x0c055c52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055c54;
P_0c055c54: /* original fcf9, guest PC 0x0c055c54 */
if(!s->budget--) { s->failed_pc=0x0c055c54u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055c56;
P_0c055c56: /* original fdf9, guest PC 0x0c055c56 */
if(!s->budget--) { s->failed_pc=0x0c055c56u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055c58;
P_0c055c58: /* original fef9, guest PC 0x0c055c58 */
if(!s->budget--) { s->failed_pc=0x0c055c58u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055c5a;
P_0c055c5a: /* original 000b, guest PC 0x0c055c5a */
if(!s->budget--) { s->failed_pc=0x0c055c5au; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c055c5c: /* original fff9, guest PC 0x0c055c5c */
if(!s->budget--) { s->failed_pc=0x0c055c5cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c055c5eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055c5eu; return 0; } return 1;
P_0c072076: /* original 2fe6, guest PC 0x0c072076 */
if(!s->budget--) { s->failed_pc=0x0c072076u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072078;
P_0c072078: /* original 6643, guest PC 0x0c072078 */
if(!s->budget--) { s->failed_pc=0x0c072078u; return 0; }
r[6]=r[4];
goto P_0c07207a;
P_0c07207a: /* original 2fd6, guest PC 0x0c07207a */
if(!s->budget--) { s->failed_pc=0x0c07207au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07207c;
P_0c07207c: /* original e058, guest PC 0x0c07207c */
if(!s->budget--) { s->failed_pc=0x0c07207cu; return 0; }
r[0]=0x00000058u;
goto P_0c07207e;
P_0c07207e: /* original 2fc6, guest PC 0x0c07207e */
if(!s->budget--) { s->failed_pc=0x0c07207eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072080;
P_0c072080: /* original 2fb6, guest PC 0x0c072080 */
if(!s->budget--) { s->failed_pc=0x0c072080u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072082;
P_0c072082: /* original 2fa6, guest PC 0x0c072082 */
if(!s->budget--) { s->failed_pc=0x0c072082u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072084;
P_0c072084: /* original 2f96, guest PC 0x0c072084 */
if(!s->budget--) { s->failed_pc=0x0c072084u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072086;
P_0c072086: /* original 2f86, guest PC 0x0c072086 */
if(!s->budget--) { s->failed_pc=0x0c072086u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072088;
P_0c072088: /* original fffb, guest PC 0x0c072088 */
if(!s->budget--) { s->failed_pc=0x0c072088u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07208a;
P_0c07208a: /* original 7fa0, guest PC 0x0c07208a */
if(!s->budget--) { s->failed_pc=0x0c07208au; return 0; }
r[15]+=0xffffffa0u;
goto P_0c07208c;
P_0c07208c: /* original 1f43, guest PC 0x0c07208c */
if(!s->budget--) { s->failed_pc=0x0c07208cu; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c07208e;
P_0c07208e: /* original 056e, guest PC 0x0c07208e */
if(!s->budget--) { s->failed_pc=0x0c07208eu; return 0; }
r[5]=read(ram,r[6]+r[0],4);
goto P_0c072090;
P_0c072090: /* original e05c, guest PC 0x0c072090 */
if(!s->budget--) { s->failed_pc=0x0c072090u; return 0; }
r[0]=0x0000005cu;
goto P_0c072092;
P_0c072092: /* original 036e, guest PC 0x0c072092 */
if(!s->budget--) { s->failed_pc=0x0c072092u; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c072094;
P_0c072094: /* original 1f32, guest PC 0x0c072094 */
if(!s->budget--) { s->failed_pc=0x0c072094u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c072096;
P_0c072096: /* original 902f, guest PC 0x0c072096 */
if(!s->budget--) { s->failed_pc=0x0c072096u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0720f8u,2);
goto P_0c072098;
P_0c072098: /* original 932f, guest PC 0x0c072098 */
if(!s->budget--) { s->failed_pc=0x0c072098u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0720fau,2);
goto P_0c07209a;
P_0c07209a: /* original 046e, guest PC 0x0c07209a */
if(!s->budget--) { s->failed_pc=0x0c07209au; return 0; }
r[4]=read(ram,r[6]+r[0],4);
goto P_0c07209c;
P_0c07209c: /* original 3430, guest PC 0x0c07209c */
if(!s->budget--) { s->failed_pc=0x0c07209cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c07209e;
P_0c07209e: /* original 8902, guest PC 0x0c07209e */
if(!s->budget--) { s->failed_pc=0x0c07209eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0720a6; }
goto P_0c0720a0;
P_0c0720a0: /* original 912c, guest PC 0x0c0720a0 */
if(!s->budget--) { s->failed_pc=0x0c0720a0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0720fcu,2);
goto P_0c0720a2;
P_0c0720a2: /* original 3410, guest PC 0x0c0720a2 */
if(!s->budget--) { s->failed_pc=0x0c0720a2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c0720a4;
P_0c0720a4: /* original 8b02, guest PC 0x0c0720a4 */
if(!s->budget--) { s->failed_pc=0x0c0720a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0720ac; }
goto P_0c0720a6;
P_0c0720a6: /* original c716, guest PC 0x0c0720a6 */
if(!s->budget--) { s->failed_pc=0x0c0720a6u; return 0; }
r[0]=code_base|0x00072100u;
goto P_0c0720a8;
P_0c0720a8: /* original a001, guest PC 0x0c0720a8 */
if(!s->budget--) { s->failed_pc=0x0c0720a8u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0720ae;
P_0c0720aa: /* original ff08, guest PC 0x0c0720aa */
if(!s->budget--) { s->failed_pc=0x0c0720aau; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0720ac;
P_0c0720ac: /* original ff9d, guest PC 0x0c0720ac */
if(!s->budget--) { s->failed_pc=0x0c0720acu; return 0; }
fr[15]=0x3f800000u;
goto P_0c0720ae;
P_0c0720ae: /* original 54f3, guest PC 0x0c0720ae */
if(!s->budget--) { s->failed_pc=0x0c0720aeu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0720b0;
P_0c0720b0: /* original 6953, guest PC 0x0c0720b0 */
if(!s->budget--) { s->failed_pc=0x0c0720b0u; return 0; }
r[9]=r[5];
goto P_0c0720b2;
P_0c0720b2: /* original 4900, guest PC 0x0c0720b2 */
if(!s->budget--) { s->failed_pc=0x0c0720b2u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0720b4;
P_0c0720b4: /* original 6353, guest PC 0x0c0720b4 */
if(!s->budget--) { s->failed_pc=0x0c0720b4u; return 0; }
r[3]=r[5];
goto P_0c0720b6;
P_0c0720b6: /* original 5441, guest PC 0x0c0720b6 */
if(!s->budget--) { s->failed_pc=0x0c0720b6u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0720b8;
P_0c0720b8: /* original 393c, guest PC 0x0c0720b8 */
if(!s->budget--) { s->failed_pc=0x0c0720b8u; return 0; }
r[9]+=r[3];
goto P_0c0720ba;
P_0c0720ba: /* original 4908, guest PC 0x0c0720ba */
if(!s->budget--) { s->failed_pc=0x0c0720bau; return 0; }
r[9]<<=2;
goto P_0c0720bc;
P_0c0720bc: /* original 6df3, guest PC 0x0c0720bc */
if(!s->budget--) { s->failed_pc=0x0c0720bcu; return 0; }
r[13]=r[15];
goto P_0c0720be;
P_0c0720be: /* original 6b43, guest PC 0x0c0720be */
if(!s->budget--) { s->failed_pc=0x0c0720beu; return 0; }
r[11]=r[4];
goto P_0c0720c0;
P_0c0720c0: /* original 7b18, guest PC 0x0c0720c0 */
if(!s->budget--) { s->failed_pc=0x0c0720c0u; return 0; }
r[11]+=0x00000018u;
goto P_0c0720c2;
P_0c0720c2: /* original 75ff, guest PC 0x0c0720c2 */
if(!s->budget--) { s->failed_pc=0x0c0720c2u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0720c4;
P_0c0720c4: /* original 6af3, guest PC 0x0c0720c4 */
if(!s->budget--) { s->failed_pc=0x0c0720c4u; return 0; }
r[10]=r[15];
goto P_0c0720c6;
P_0c0720c6: /* original 4900, guest PC 0x0c0720c6 */
if(!s->budget--) { s->failed_pc=0x0c0720c6u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0720c8;
P_0c0720c8: /* original 6253, guest PC 0x0c0720c8 */
if(!s->budget--) { s->failed_pc=0x0c0720c8u; return 0; }
r[2]=r[5];
goto P_0c0720ca;
P_0c0720ca: /* original e301, guest PC 0x0c0720ca */
if(!s->budget--) { s->failed_pc=0x0c0720cau; return 0; }
r[3]=0x00000001u;
goto P_0c0720cc;
P_0c0720cc: /* original 6eb3, guest PC 0x0c0720cc */
if(!s->budget--) { s->failed_pc=0x0c0720ccu; return 0; }
r[14]=r[11];
goto P_0c0720ce;
P_0c0720ce: /* original 394c, guest PC 0x0c0720ce */
if(!s->budget--) { s->failed_pc=0x0c0720ceu; return 0; }
r[9]+=r[4];
goto P_0c0720d0;
P_0c0720d0: /* original 6cf3, guest PC 0x0c0720d0 */
if(!s->budget--) { s->failed_pc=0x0c0720d0u; return 0; }
r[12]=r[15];
goto P_0c0720d2;
P_0c0720d2: /* original 7a3c, guest PC 0x0c0720d2 */
if(!s->budget--) { s->failed_pc=0x0c0720d2u; return 0; }
r[10]+=0x0000003cu;
goto P_0c0720d4;
P_0c0720d4: /* original 3237, guest PC 0x0c0720d4 */
if(!s->budget--) { s->failed_pc=0x0c0720d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0720d6;
P_0c0720d6: /* original 6843, guest PC 0x0c0720d6 */
if(!s->budget--) { s->failed_pc=0x0c0720d6u; return 0; }
r[8]=r[4];
goto P_0c0720d8;
P_0c0720d8: /* original 2f42, guest PC 0x0c0720d8 */
if(!s->budget--) { s->failed_pc=0x0c0720d8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0720da;
P_0c0720da: /* original 7b18, guest PC 0x0c0720da */
if(!s->budget--) { s->failed_pc=0x0c0720dau; return 0; }
r[11]+=0x00000018u;
goto P_0c0720dc;
P_0c0720dc: /* original 1f55, guest PC 0x0c0720dc */
if(!s->budget--) { s->failed_pc=0x0c0720dcu; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c0720de;
P_0c0720de: /* original 7918, guest PC 0x0c0720de */
if(!s->budget--) { s->failed_pc=0x0c0720deu; return 0; }
r[9]+=0x00000018u;
goto P_0c0720e0;
P_0c0720e0: /* original 1f51, guest PC 0x0c0720e0 */
if(!s->budget--) { s->failed_pc=0x0c0720e0u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0720e2;
P_0c0720e2: /* original 7d30, guest PC 0x0c0720e2 */
if(!s->budget--) { s->failed_pc=0x0c0720e2u; return 0; }
r[13]+=0x00000030u;
goto P_0c0720e4;
P_0c0720e4: /* original 8d03, guest PC 0x0c0720e4 */
if(!s->budget--) { s->failed_pc=0x0c0720e4u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000048u;
if(cond) { goto P_0c0720ee; }
goto P_0c0720e8;
P_0c0720e6: /* original 7c48, guest PC 0x0c0720e6 */
if(!s->budget--) { s->failed_pc=0x0c0720e6u; return 0; }
r[12]+=0x00000048u;
goto P_0c0720e8;
P_0c0720e8: /* original d106, guest PC 0x0c0720e8 */
if(!s->budget--) { s->failed_pc=0x0c0720e8u; return 0; }
r[1]=read(ram,0x0c072104u,4);
goto P_0c0720ea;
P_0c0720ea: /* original 412b, guest PC 0x0c0720ea */
if(!s->budget--) { s->failed_pc=0x0c0720eau; return 0; }
target=r[1];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c072276u: goto P_0c072276;
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
P_0c0720ec: /* original 0009, guest PC 0x0c0720ec */
if(!s->budget--) { s->failed_pc=0x0c0720ecu; return 0; }
goto P_0c0720ee;
P_0c0720ee: /* original 65f2, guest PC 0x0c0720ee */
if(!s->budget--) { s->failed_pc=0x0c0720eeu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0720f0;
P_0c0720f0: /* original 64d3, guest PC 0x0c0720f0 */
if(!s->budget--) { s->failed_pc=0x0c0720f0u; return 0; }
r[4]=r[13];
goto P_0c0720f2;
P_0c0720f2: /* original 66e3, guest PC 0x0c0720f2 */
if(!s->budget--) { s->failed_pc=0x0c0720f2u; return 0; }
r[6]=r[14];
goto P_0c0720f4;
P_0c0720f4: /* original a008, guest PC 0x0c0720f4 */
if(!s->budget--) { s->failed_pc=0x0c0720f4u; return 0; }
goto P_0c072108;
P_0c0720f6: /* original 0009, guest PC 0x0c0720f6 */
if(!s->budget--) { s->failed_pc=0x0c0720f6u; return 0; }
if(!vf3_matrix_family(0x0c0720f8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0720f8u; return 0; } return 1;
P_0c072108: /* original f059, guest PC 0x0c072108 */
if(!s->budget--) { s->failed_pc=0x0c072108u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07210a;
P_0c07210a: /* original f369, guest PC 0x0c07210a */
if(!s->budget--) { s->failed_pc=0x0c07210au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07210c;
P_0c07210c: /* original f159, guest PC 0x0c07210c */
if(!s->budget--) { s->failed_pc=0x0c07210cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07210e;
P_0c07210e: /* original f469, guest PC 0x0c07210e */
if(!s->budget--) { s->failed_pc=0x0c07210eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072110;
P_0c072110: /* original f031, guest PC 0x0c072110 */
if(!s->budget--) { s->failed_pc=0x0c072110u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072112;
P_0c072112: /* original f258, guest PC 0x0c072112 */
if(!s->budget--) { s->failed_pc=0x0c072112u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072114;
P_0c072114: /* original f568, guest PC 0x0c072114 */
if(!s->budget--) { s->failed_pc=0x0c072114u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072116;
P_0c072116: /* original f141, guest PC 0x0c072116 */
if(!s->budget--) { s->failed_pc=0x0c072116u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072118;
P_0c072118: /* original f251, guest PC 0x0c072118 */
if(!s->budget--) { s->failed_pc=0x0c072118u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07211a;
P_0c07211a: /* original 7408, guest PC 0x0c07211a */
if(!s->budget--) { s->failed_pc=0x0c07211au; return 0; }
r[4]+=0x00000008u;
goto P_0c07211c;
P_0c07211c: /* original f42a, guest PC 0x0c07211c */
if(!s->budget--) { s->failed_pc=0x0c07211cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07211e;
P_0c07211e: /* original f41b, guest PC 0x0c07211e */
if(!s->budget--) { s->failed_pc=0x0c07211eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072120;
P_0c072120: /* original f40b, guest PC 0x0c072120 */
if(!s->budget--) { s->failed_pc=0x0c072120u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072122;
P_0c072122: /* original 0009, guest PC 0x0c072122 */
if(!s->budget--) { s->failed_pc=0x0c072122u; return 0; }
goto P_0c072124;
P_0c072124: /* original 64a3, guest PC 0x0c072124 */
if(!s->budget--) { s->failed_pc=0x0c072124u; return 0; }
r[4]=r[10];
goto P_0c072126;
P_0c072126: /* original 65b3, guest PC 0x0c072126 */
if(!s->budget--) { s->failed_pc=0x0c072126u; return 0; }
r[5]=r[11];
goto P_0c072128;
P_0c072128: /* original 66e3, guest PC 0x0c072128 */
if(!s->budget--) { s->failed_pc=0x0c072128u; return 0; }
r[6]=r[14];
goto P_0c07212a;
P_0c07212a: /* original f059, guest PC 0x0c07212a */
if(!s->budget--) { s->failed_pc=0x0c07212au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07212c;
P_0c07212c: /* original f369, guest PC 0x0c07212c */
if(!s->budget--) { s->failed_pc=0x0c07212cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07212e;
P_0c07212e: /* original f159, guest PC 0x0c07212e */
if(!s->budget--) { s->failed_pc=0x0c07212eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072130;
P_0c072130: /* original f469, guest PC 0x0c072130 */
if(!s->budget--) { s->failed_pc=0x0c072130u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072132;
P_0c072132: /* original f031, guest PC 0x0c072132 */
if(!s->budget--) { s->failed_pc=0x0c072132u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072134;
P_0c072134: /* original f258, guest PC 0x0c072134 */
if(!s->budget--) { s->failed_pc=0x0c072134u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072136;
P_0c072136: /* original f568, guest PC 0x0c072136 */
if(!s->budget--) { s->failed_pc=0x0c072136u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072138;
P_0c072138: /* original f141, guest PC 0x0c072138 */
if(!s->budget--) { s->failed_pc=0x0c072138u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c07213a;
P_0c07213a: /* original f251, guest PC 0x0c07213a */
if(!s->budget--) { s->failed_pc=0x0c07213au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07213c;
P_0c07213c: /* original 7408, guest PC 0x0c07213c */
if(!s->budget--) { s->failed_pc=0x0c07213cu; return 0; }
r[4]+=0x00000008u;
goto P_0c07213e;
P_0c07213e: /* original f42a, guest PC 0x0c07213e */
if(!s->budget--) { s->failed_pc=0x0c07213eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072140;
P_0c072140: /* original f41b, guest PC 0x0c072140 */
if(!s->budget--) { s->failed_pc=0x0c072140u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072142;
P_0c072142: /* original f40b, guest PC 0x0c072142 */
if(!s->budget--) { s->failed_pc=0x0c072142u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072144;
P_0c072144: /* original 64c3, guest PC 0x0c072144 */
if(!s->budget--) { s->failed_pc=0x0c072144u; return 0; }
r[4]=r[12];
goto P_0c072146;
P_0c072146: /* original 6593, guest PC 0x0c072146 */
if(!s->budget--) { s->failed_pc=0x0c072146u; return 0; }
r[5]=r[9];
goto P_0c072148;
P_0c072148: /* original 66e3, guest PC 0x0c072148 */
if(!s->budget--) { s->failed_pc=0x0c072148u; return 0; }
r[6]=r[14];
goto P_0c07214a;
P_0c07214a: /* original f059, guest PC 0x0c07214a */
if(!s->budget--) { s->failed_pc=0x0c07214au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07214c;
P_0c07214c: /* original f369, guest PC 0x0c07214c */
if(!s->budget--) { s->failed_pc=0x0c07214cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07214e;
P_0c07214e: /* original f159, guest PC 0x0c07214e */
if(!s->budget--) { s->failed_pc=0x0c07214eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072150;
P_0c072150: /* original f469, guest PC 0x0c072150 */
if(!s->budget--) { s->failed_pc=0x0c072150u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072152;
P_0c072152: /* original f031, guest PC 0x0c072152 */
if(!s->budget--) { s->failed_pc=0x0c072152u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072154;
P_0c072154: /* original f258, guest PC 0x0c072154 */
if(!s->budget--) { s->failed_pc=0x0c072154u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072156;
P_0c072156: /* original f568, guest PC 0x0c072156 */
if(!s->budget--) { s->failed_pc=0x0c072156u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072158;
P_0c072158: /* original f141, guest PC 0x0c072158 */
if(!s->budget--) { s->failed_pc=0x0c072158u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c07215a;
P_0c07215a: /* original f251, guest PC 0x0c07215a */
if(!s->budget--) { s->failed_pc=0x0c07215au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07215c;
P_0c07215c: /* original 7408, guest PC 0x0c07215c */
if(!s->budget--) { s->failed_pc=0x0c07215cu; return 0; }
r[4]+=0x00000008u;
goto P_0c07215e;
P_0c07215e: /* original f42a, guest PC 0x0c07215e */
if(!s->budget--) { s->failed_pc=0x0c07215eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072160;
P_0c072160: /* original f41b, guest PC 0x0c072160 */
if(!s->budget--) { s->failed_pc=0x0c072160u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072162;
P_0c072162: /* original f40b, guest PC 0x0c072162 */
if(!s->budget--) { s->failed_pc=0x0c072162u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072164;
P_0c072164: /* original 66f3, guest PC 0x0c072164 */
if(!s->budget--) { s->failed_pc=0x0c072164u; return 0; }
r[6]=r[15];
goto P_0c072166;
P_0c072166: /* original 64c3, guest PC 0x0c072166 */
if(!s->budget--) { s->failed_pc=0x0c072166u; return 0; }
r[4]=r[12];
goto P_0c072168;
P_0c072168: /* original 65d3, guest PC 0x0c072168 */
if(!s->budget--) { s->failed_pc=0x0c072168u; return 0; }
r[5]=r[13];
goto P_0c07216a;
P_0c07216a: /* original 7624, guest PC 0x0c07216a */
if(!s->budget--) { s->failed_pc=0x0c07216au; return 0; }
r[6]+=0x00000024u;
goto P_0c07216c;
P_0c07216c: /* original f049, guest PC 0x0c07216c */
if(!s->budget--) { s->failed_pc=0x0c07216cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07216e;
P_0c07216e: /* original f549, guest PC 0x0c07216e */
if(!s->budget--) { s->failed_pc=0x0c07216eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072170;
P_0c072170: /* original f648, guest PC 0x0c072170 */
if(!s->budget--) { s->failed_pc=0x0c072170u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c072172;
P_0c072172: /* original f859, guest PC 0x0c072172 */
if(!s->budget--) { s->failed_pc=0x0c072172u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072174;
P_0c072174: /* original f959, guest PC 0x0c072174 */
if(!s->budget--) { s->failed_pc=0x0c072174u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072176;
P_0c072176: /* original fa58, guest PC 0x0c072176 */
if(!s->budget--) { s->failed_pc=0x0c072176u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072178;
P_0c072178: /* original 760c, guest PC 0x0c072178 */
if(!s->budget--) { s->failed_pc=0x0c072178u; return 0; }
r[6]+=0x0000000cu;
goto P_0c07217a;
P_0c07217a: /* original f35c, guest PC 0x0c07217a */
if(!s->budget--) { s->failed_pc=0x0c07217au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c07217c;
P_0c07217c: /* original f382, guest PC 0x0c07217c */
if(!s->budget--) { s->failed_pc=0x0c07217cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07217e;
P_0c07217e: /* original f20c, guest PC 0x0c07217e */
if(!s->budget--) { s->failed_pc=0x0c07217eu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c072180;
P_0c072180: /* original f2a2, guest PC 0x0c072180 */
if(!s->budget--) { s->failed_pc=0x0c072180u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c072182;
P_0c072182: /* original f16c, guest PC 0x0c072182 */
if(!s->budget--) { s->failed_pc=0x0c072182u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072184;
P_0c072184: /* original f192, guest PC 0x0c072184 */
if(!s->budget--) { s->failed_pc=0x0c072184u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072186;
P_0c072186: /* original f34d, guest PC 0x0c072186 */
if(!s->budget--) { s->failed_pc=0x0c072186u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072188;
P_0c072188: /* original f39e, guest PC 0x0c072188 */
if(!s->budget--) { s->failed_pc=0x0c072188u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c07218a;
P_0c07218a: /* original f24d, guest PC 0x0c07218a */
if(!s->budget--) { s->failed_pc=0x0c07218au; return 0; }
fr[2]^=0x80000000u;
goto P_0c07218c;
P_0c07218c: /* original f06c, guest PC 0x0c07218c */
if(!s->budget--) { s->failed_pc=0x0c07218cu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07218e;
P_0c07218e: /* original f28e, guest PC 0x0c07218e */
if(!s->budget--) { s->failed_pc=0x0c07218eu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c072190;
P_0c072190: /* original f14d, guest PC 0x0c072190 */
if(!s->budget--) { s->failed_pc=0x0c072190u; return 0; }
fr[1]^=0x80000000u;
goto P_0c072192;
P_0c072192: /* original f63b, guest PC 0x0c072192 */
if(!s->budget--) { s->failed_pc=0x0c072192u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072194;
P_0c072194: /* original f05c, guest PC 0x0c072194 */
if(!s->budget--) { s->failed_pc=0x0c072194u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072196;
P_0c072196: /* original f1ae, guest PC 0x0c072196 */
if(!s->budget--) { s->failed_pc=0x0c072196u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072198;
P_0c072198: /* original f62b, guest PC 0x0c072198 */
if(!s->budget--) { s->failed_pc=0x0c072198u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c07219a;
P_0c07219a: /* original f61b, guest PC 0x0c07219a */
if(!s->budget--) { s->failed_pc=0x0c07219au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c07219c;
P_0c07219c: /* original 66f3, guest PC 0x0c07219c */
if(!s->budget--) { s->failed_pc=0x0c07219cu; return 0; }
r[6]=r[15];
goto P_0c07219e;
P_0c07219e: /* original 64a3, guest PC 0x0c07219e */
if(!s->budget--) { s->failed_pc=0x0c07219eu; return 0; }
r[4]=r[10];
goto P_0c0721a0;
P_0c0721a0: /* original 65c3, guest PC 0x0c0721a0 */
if(!s->budget--) { s->failed_pc=0x0c0721a0u; return 0; }
r[5]=r[12];
goto P_0c0721a2;
P_0c0721a2: /* original 7618, guest PC 0x0c0721a2 */
if(!s->budget--) { s->failed_pc=0x0c0721a2u; return 0; }
r[6]+=0x00000018u;
goto P_0c0721a4;
P_0c0721a4: /* original f049, guest PC 0x0c0721a4 */
if(!s->budget--) { s->failed_pc=0x0c0721a4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721a6;
P_0c0721a6: /* original f549, guest PC 0x0c0721a6 */
if(!s->budget--) { s->failed_pc=0x0c0721a6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721a8;
P_0c0721a8: /* original f648, guest PC 0x0c0721a8 */
if(!s->budget--) { s->failed_pc=0x0c0721a8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0721aa;
P_0c0721aa: /* original f859, guest PC 0x0c0721aa */
if(!s->budget--) { s->failed_pc=0x0c0721aau; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0721ac;
P_0c0721ac: /* original f959, guest PC 0x0c0721ac */
if(!s->budget--) { s->failed_pc=0x0c0721acu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0721ae;
P_0c0721ae: /* original fa58, guest PC 0x0c0721ae */
if(!s->budget--) { s->failed_pc=0x0c0721aeu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0721b0;
P_0c0721b0: /* original 760c, guest PC 0x0c0721b0 */
if(!s->budget--) { s->failed_pc=0x0c0721b0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0721b2;
P_0c0721b2: /* original f35c, guest PC 0x0c0721b2 */
if(!s->budget--) { s->failed_pc=0x0c0721b2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0721b4;
P_0c0721b4: /* original f382, guest PC 0x0c0721b4 */
if(!s->budget--) { s->failed_pc=0x0c0721b4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0721b6;
P_0c0721b6: /* original f20c, guest PC 0x0c0721b6 */
if(!s->budget--) { s->failed_pc=0x0c0721b6u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0721b8;
P_0c0721b8: /* original f2a2, guest PC 0x0c0721b8 */
if(!s->budget--) { s->failed_pc=0x0c0721b8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0721ba;
P_0c0721ba: /* original f16c, guest PC 0x0c0721ba */
if(!s->budget--) { s->failed_pc=0x0c0721bau; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0721bc;
P_0c0721bc: /* original f192, guest PC 0x0c0721bc */
if(!s->budget--) { s->failed_pc=0x0c0721bcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0721be;
P_0c0721be: /* original f34d, guest PC 0x0c0721be */
if(!s->budget--) { s->failed_pc=0x0c0721beu; return 0; }
fr[3]^=0x80000000u;
goto P_0c0721c0;
P_0c0721c0: /* original f39e, guest PC 0x0c0721c0 */
if(!s->budget--) { s->failed_pc=0x0c0721c0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0721c2;
P_0c0721c2: /* original f24d, guest PC 0x0c0721c2 */
if(!s->budget--) { s->failed_pc=0x0c0721c2u; return 0; }
fr[2]^=0x80000000u;
goto P_0c0721c4;
P_0c0721c4: /* original f06c, guest PC 0x0c0721c4 */
if(!s->budget--) { s->failed_pc=0x0c0721c4u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0721c6;
P_0c0721c6: /* original f28e, guest PC 0x0c0721c6 */
if(!s->budget--) { s->failed_pc=0x0c0721c6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0721c8;
P_0c0721c8: /* original f14d, guest PC 0x0c0721c8 */
if(!s->budget--) { s->failed_pc=0x0c0721c8u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0721ca;
P_0c0721ca: /* original f63b, guest PC 0x0c0721ca */
if(!s->budget--) { s->failed_pc=0x0c0721cau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0721cc;
P_0c0721cc: /* original f05c, guest PC 0x0c0721cc */
if(!s->budget--) { s->failed_pc=0x0c0721ccu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0721ce;
P_0c0721ce: /* original f1ae, guest PC 0x0c0721ce */
if(!s->budget--) { s->failed_pc=0x0c0721ceu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0721d0;
P_0c0721d0: /* original f62b, guest PC 0x0c0721d0 */
if(!s->budget--) { s->failed_pc=0x0c0721d0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0721d2;
P_0c0721d2: /* original f61b, guest PC 0x0c0721d2 */
if(!s->budget--) { s->failed_pc=0x0c0721d2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0721d4;
P_0c0721d4: /* original 64f3, guest PC 0x0c0721d4 */
if(!s->budget--) { s->failed_pc=0x0c0721d4u; return 0; }
r[4]=r[15];
goto P_0c0721d6;
P_0c0721d6: /* original 7424, guest PC 0x0c0721d6 */
if(!s->budget--) { s->failed_pc=0x0c0721d6u; return 0; }
r[4]+=0x00000024u;
goto P_0c0721d8;
P_0c0721d8: /* original f049, guest PC 0x0c0721d8 */
if(!s->budget--) { s->failed_pc=0x0c0721d8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721da;
P_0c0721da: /* original f149, guest PC 0x0c0721da */
if(!s->budget--) { s->failed_pc=0x0c0721dau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721dc;
P_0c0721dc: /* original f249, guest PC 0x0c0721dc */
if(!s->budget--) { s->failed_pc=0x0c0721dcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721de;
P_0c0721de: /* original f38d, guest PC 0x0c0721de */
if(!s->budget--) { s->failed_pc=0x0c0721deu; return 0; }
fr[3]=0;
goto P_0c0721e0;
P_0c0721e0: /* original f0ed, guest PC 0x0c0721e0 */
if(!s->budget--) { s->failed_pc=0x0c0721e0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0721e2;
P_0c0721e2: /* original f37d, guest PC 0x0c0721e2 */
if(!s->budget--) { s->failed_pc=0x0c0721e2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0721e4;
P_0c0721e4: /* original f232, guest PC 0x0c0721e4 */
if(!s->budget--) { s->failed_pc=0x0c0721e4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0721e6;
P_0c0721e6: /* original f132, guest PC 0x0c0721e6 */
if(!s->budget--) { s->failed_pc=0x0c0721e6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0721e8;
P_0c0721e8: /* original f032, guest PC 0x0c0721e8 */
if(!s->budget--) { s->failed_pc=0x0c0721e8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0721ea;
P_0c0721ea: /* original f42b, guest PC 0x0c0721ea */
if(!s->budget--) { s->failed_pc=0x0c0721eau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0721ec;
P_0c0721ec: /* original f41b, guest PC 0x0c0721ec */
if(!s->budget--) { s->failed_pc=0x0c0721ecu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0721ee;
P_0c0721ee: /* original f40b, guest PC 0x0c0721ee */
if(!s->budget--) { s->failed_pc=0x0c0721eeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0721f0;
P_0c0721f0: /* original 64f3, guest PC 0x0c0721f0 */
if(!s->budget--) { s->failed_pc=0x0c0721f0u; return 0; }
r[4]=r[15];
goto P_0c0721f2;
P_0c0721f2: /* original 7418, guest PC 0x0c0721f2 */
if(!s->budget--) { s->failed_pc=0x0c0721f2u; return 0; }
r[4]+=0x00000018u;
goto P_0c0721f4;
P_0c0721f4: /* original f049, guest PC 0x0c0721f4 */
if(!s->budget--) { s->failed_pc=0x0c0721f4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721f6;
P_0c0721f6: /* original f149, guest PC 0x0c0721f6 */
if(!s->budget--) { s->failed_pc=0x0c0721f6u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721f8;
P_0c0721f8: /* original f249, guest PC 0x0c0721f8 */
if(!s->budget--) { s->failed_pc=0x0c0721f8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0721fa;
P_0c0721fa: /* original f38d, guest PC 0x0c0721fa */
if(!s->budget--) { s->failed_pc=0x0c0721fau; return 0; }
fr[3]=0;
goto P_0c0721fc;
P_0c0721fc: /* original f0ed, guest PC 0x0c0721fc */
if(!s->budget--) { s->failed_pc=0x0c0721fcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0721fe;
P_0c0721fe: /* original f37d, guest PC 0x0c0721fe */
if(!s->budget--) { s->failed_pc=0x0c0721feu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072200;
P_0c072200: /* original f232, guest PC 0x0c072200 */
if(!s->budget--) { s->failed_pc=0x0c072200u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072202;
P_0c072202: /* original f132, guest PC 0x0c072202 */
if(!s->budget--) { s->failed_pc=0x0c072202u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072204;
P_0c072204: /* original f032, guest PC 0x0c072204 */
if(!s->budget--) { s->failed_pc=0x0c072204u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072206;
P_0c072206: /* original f42b, guest PC 0x0c072206 */
if(!s->budget--) { s->failed_pc=0x0c072206u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072208;
P_0c072208: /* original f41b, guest PC 0x0c072208 */
if(!s->budget--) { s->failed_pc=0x0c072208u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07220a;
P_0c07220a: /* original f40b, guest PC 0x0c07220a */
if(!s->budget--) { s->failed_pc=0x0c07220au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07220c;
P_0c07220c: /* original 65f3, guest PC 0x0c07220c */
if(!s->budget--) { s->failed_pc=0x0c07220cu; return 0; }
r[5]=r[15];
goto P_0c07220e;
P_0c07220e: /* original 64e3, guest PC 0x0c07220e */
if(!s->budget--) { s->failed_pc=0x0c07220eu; return 0; }
r[4]=r[14];
goto P_0c072210;
P_0c072210: /* original 66f3, guest PC 0x0c072210 */
if(!s->budget--) { s->failed_pc=0x0c072210u; return 0; }
r[6]=r[15];
goto P_0c072212;
P_0c072212: /* original 740c, guest PC 0x0c072212 */
if(!s->budget--) { s->failed_pc=0x0c072212u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072214;
P_0c072214: /* original 7618, guest PC 0x0c072214 */
if(!s->budget--) { s->failed_pc=0x0c072214u; return 0; }
r[6]+=0x00000018u;
goto P_0c072216;
P_0c072216: /* original 7524, guest PC 0x0c072216 */
if(!s->budget--) { s->failed_pc=0x0c072216u; return 0; }
r[5]+=0x00000024u;
goto P_0c072218;
P_0c072218: /* original f059, guest PC 0x0c072218 */
if(!s->budget--) { s->failed_pc=0x0c072218u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07221a;
P_0c07221a: /* original f369, guest PC 0x0c07221a */
if(!s->budget--) { s->failed_pc=0x0c07221au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07221c;
P_0c07221c: /* original f159, guest PC 0x0c07221c */
if(!s->budget--) { s->failed_pc=0x0c07221cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07221e;
P_0c07221e: /* original f469, guest PC 0x0c07221e */
if(!s->budget--) { s->failed_pc=0x0c07221eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072220;
P_0c072220: /* original f259, guest PC 0x0c072220 */
if(!s->budget--) { s->failed_pc=0x0c072220u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072222;
P_0c072222: /* original f569, guest PC 0x0c072222 */
if(!s->budget--) { s->failed_pc=0x0c072222u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072224;
P_0c072224: /* original 740c, guest PC 0x0c072224 */
if(!s->budget--) { s->failed_pc=0x0c072224u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072226;
P_0c072226: /* original f030, guest PC 0x0c072226 */
if(!s->budget--) { s->failed_pc=0x0c072226u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c072228;
P_0c072228: /* original f250, guest PC 0x0c072228 */
if(!s->budget--) { s->failed_pc=0x0c072228u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07222a;
P_0c07222a: /* original f140, guest PC 0x0c07222a */
if(!s->budget--) { s->failed_pc=0x0c07222au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c07222c;
P_0c07222c: /* original f42b, guest PC 0x0c07222c */
if(!s->budget--) { s->failed_pc=0x0c07222cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07222e;
P_0c07222e: /* original f41b, guest PC 0x0c07222e */
if(!s->budget--) { s->failed_pc=0x0c07222eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072230;
P_0c072230: /* original f40b, guest PC 0x0c072230 */
if(!s->budget--) { s->failed_pc=0x0c072230u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072232;
P_0c072232: /* original 0009, guest PC 0x0c072232 */
if(!s->budget--) { s->failed_pc=0x0c072232u; return 0; }
goto P_0c072234;
P_0c072234: /* original 64e3, guest PC 0x0c072234 */
if(!s->budget--) { s->failed_pc=0x0c072234u; return 0; }
r[4]=r[14];
goto P_0c072236;
P_0c072236: /* original 65e3, guest PC 0x0c072236 */
if(!s->budget--) { s->failed_pc=0x0c072236u; return 0; }
r[5]=r[14];
goto P_0c072238;
P_0c072238: /* original 740c, guest PC 0x0c072238 */
if(!s->budget--) { s->failed_pc=0x0c072238u; return 0; }
r[4]+=0x0000000cu;
goto P_0c07223a;
P_0c07223a: /* original f4fc, guest PC 0x0c07223a */
if(!s->budget--) { s->failed_pc=0x0c07223au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c07223c;
P_0c07223c: /* original 750c, guest PC 0x0c07223c */
if(!s->budget--) { s->failed_pc=0x0c07223cu; return 0; }
r[5]+=0x0000000cu;
goto P_0c07223e;
P_0c07223e: /* original f059, guest PC 0x0c07223e */
if(!s->budget--) { s->failed_pc=0x0c07223eu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072240;
P_0c072240: /* original f159, guest PC 0x0c072240 */
if(!s->budget--) { s->failed_pc=0x0c072240u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072242;
P_0c072242: /* original f259, guest PC 0x0c072242 */
if(!s->budget--) { s->failed_pc=0x0c072242u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072244;
P_0c072244: /* original f38d, guest PC 0x0c072244 */
if(!s->budget--) { s->failed_pc=0x0c072244u; return 0; }
fr[3]=0;
goto P_0c072246;
P_0c072246: /* original f0ed, guest PC 0x0c072246 */
if(!s->budget--) { s->failed_pc=0x0c072246u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072248;
P_0c072248: /* original f37d, guest PC 0x0c072248 */
if(!s->budget--) { s->failed_pc=0x0c072248u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07224a;
P_0c07224a: /* original f342, guest PC 0x0c07224a */
if(!s->budget--) { s->failed_pc=0x0c07224au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07224c;
P_0c07224c: /* original 740c, guest PC 0x0c07224c */
if(!s->budget--) { s->failed_pc=0x0c07224cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c07224e;
P_0c07224e: /* original f232, guest PC 0x0c07224e */
if(!s->budget--) { s->failed_pc=0x0c07224eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072250;
P_0c072250: /* original f132, guest PC 0x0c072250 */
if(!s->budget--) { s->failed_pc=0x0c072250u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072252;
P_0c072252: /* original f032, guest PC 0x0c072252 */
if(!s->budget--) { s->failed_pc=0x0c072252u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072254;
P_0c072254: /* original f42b, guest PC 0x0c072254 */
if(!s->budget--) { s->failed_pc=0x0c072254u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072256;
P_0c072256: /* original f41b, guest PC 0x0c072256 */
if(!s->budget--) { s->failed_pc=0x0c072256u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072258;
P_0c072258: /* original f40b, guest PC 0x0c072258 */
if(!s->budget--) { s->failed_pc=0x0c072258u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07225a;
P_0c07225a: /* original 0009, guest PC 0x0c07225a */
if(!s->budget--) { s->failed_pc=0x0c07225au; return 0; }
goto P_0c07225c;
P_0c07225c: /* original 2fe2, guest PC 0x0c07225c */
if(!s->budget--) { s->failed_pc=0x0c07225cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c07225e;
P_0c07225e: /* original e201, guest PC 0x0c07225e */
if(!s->budget--) { s->failed_pc=0x0c07225eu; return 0; }
r[2]=0x00000001u;
goto P_0c072260;
P_0c072260: /* original 53f1, guest PC 0x0c072260 */
if(!s->budget--) { s->failed_pc=0x0c072260u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c072262;
P_0c072262: /* original 6eb3, guest PC 0x0c072262 */
if(!s->budget--) { s->failed_pc=0x0c072262u; return 0; }
r[14]=r[11];
goto P_0c072264;
P_0c072264: /* original 7b18, guest PC 0x0c072264 */
if(!s->budget--) { s->failed_pc=0x0c072264u; return 0; }
r[11]+=0x00000018u;
goto P_0c072266;
P_0c072266: /* original 73ff, guest PC 0x0c072266 */
if(!s->budget--) { s->failed_pc=0x0c072266u; return 0; }
r[3]+=0xffffffffu;
goto P_0c072268;
P_0c072268: /* original 3327, guest PC 0x0c072268 */
if(!s->budget--) { s->failed_pc=0x0c072268u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c07226a;
P_0c07226a: /* original 7918, guest PC 0x0c07226a */
if(!s->budget--) { s->failed_pc=0x0c07226au; return 0; }
r[9]+=0x00000018u;
goto P_0c07226c;
P_0c07226c: /* original 8f03, guest PC 0x0c07226c */
if(!s->budget--) { s->failed_pc=0x0c07226cu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c072276; }
goto P_0c072270;
P_0c07226e: /* original 1f31, guest PC 0x0c07226e */
if(!s->budget--) { s->failed_pc=0x0c07226eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c072270;
P_0c072270: /* original d103, guest PC 0x0c072270 */
if(!s->budget--) { s->failed_pc=0x0c072270u; return 0; }
r[1]=read(ram,0x0c072280u,4);
goto P_0c072272;
P_0c072272: /* original 412b, guest PC 0x0c072272 */
if(!s->budget--) { s->failed_pc=0x0c072272u; return 0; }
target=r[1];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0720eeu: goto P_0c0720ee;
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
P_0c072274: /* original 0009, guest PC 0x0c072274 */
if(!s->budget--) { s->failed_pc=0x0c072274u; return 0; }
goto P_0c072276;
P_0c072276: /* original 65f2, guest PC 0x0c072276 */
if(!s->budget--) { s->failed_pc=0x0c072276u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c072278;
P_0c072278: /* original 64d3, guest PC 0x0c072278 */
if(!s->budget--) { s->failed_pc=0x0c072278u; return 0; }
r[4]=r[13];
goto P_0c07227a;
P_0c07227a: /* original 66e3, guest PC 0x0c07227a */
if(!s->budget--) { s->failed_pc=0x0c07227au; return 0; }
r[6]=r[14];
goto P_0c07227c;
P_0c07227c: /* original a002, guest PC 0x0c07227c */
if(!s->budget--) { s->failed_pc=0x0c07227cu; return 0; }
goto P_0c072284;
P_0c07227e: /* original 0009, guest PC 0x0c07227e */
if(!s->budget--) { s->failed_pc=0x0c07227eu; return 0; }
if(!vf3_matrix_family(0x0c072280u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c072280u; return 0; } return 1;
P_0c072284: /* original f059, guest PC 0x0c072284 */
if(!s->budget--) { s->failed_pc=0x0c072284u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072286;
P_0c072286: /* original f369, guest PC 0x0c072286 */
if(!s->budget--) { s->failed_pc=0x0c072286u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c072288;
P_0c072288: /* original f159, guest PC 0x0c072288 */
if(!s->budget--) { s->failed_pc=0x0c072288u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07228a;
P_0c07228a: /* original f469, guest PC 0x0c07228a */
if(!s->budget--) { s->failed_pc=0x0c07228au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07228c;
P_0c07228c: /* original f031, guest PC 0x0c07228c */
if(!s->budget--) { s->failed_pc=0x0c07228cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07228e;
P_0c07228e: /* original f258, guest PC 0x0c07228e */
if(!s->budget--) { s->failed_pc=0x0c07228eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072290;
P_0c072290: /* original f568, guest PC 0x0c072290 */
if(!s->budget--) { s->failed_pc=0x0c072290u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072292;
P_0c072292: /* original f141, guest PC 0x0c072292 */
if(!s->budget--) { s->failed_pc=0x0c072292u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072294;
P_0c072294: /* original f251, guest PC 0x0c072294 */
if(!s->budget--) { s->failed_pc=0x0c072294u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072296;
P_0c072296: /* original 7408, guest PC 0x0c072296 */
if(!s->budget--) { s->failed_pc=0x0c072296u; return 0; }
r[4]+=0x00000008u;
goto P_0c072298;
P_0c072298: /* original f42a, guest PC 0x0c072298 */
if(!s->budget--) { s->failed_pc=0x0c072298u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07229a;
P_0c07229a: /* original f41b, guest PC 0x0c07229a */
if(!s->budget--) { s->failed_pc=0x0c07229au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07229c;
P_0c07229c: /* original f40b, guest PC 0x0c07229c */
if(!s->budget--) { s->failed_pc=0x0c07229cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07229e;
P_0c07229e: /* original 0009, guest PC 0x0c07229e */
if(!s->budget--) { s->failed_pc=0x0c07229eu; return 0; }
goto P_0c0722a0;
P_0c0722a0: /* original 64a3, guest PC 0x0c0722a0 */
if(!s->budget--) { s->failed_pc=0x0c0722a0u; return 0; }
r[4]=r[10];
goto P_0c0722a2;
P_0c0722a2: /* original 6593, guest PC 0x0c0722a2 */
if(!s->budget--) { s->failed_pc=0x0c0722a2u; return 0; }
r[5]=r[9];
goto P_0c0722a4;
P_0c0722a4: /* original 66e3, guest PC 0x0c0722a4 */
if(!s->budget--) { s->failed_pc=0x0c0722a4u; return 0; }
r[6]=r[14];
goto P_0c0722a6;
P_0c0722a6: /* original f059, guest PC 0x0c0722a6 */
if(!s->budget--) { s->failed_pc=0x0c0722a6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0722a8;
P_0c0722a8: /* original f369, guest PC 0x0c0722a8 */
if(!s->budget--) { s->failed_pc=0x0c0722a8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0722aa;
P_0c0722aa: /* original f159, guest PC 0x0c0722aa */
if(!s->budget--) { s->failed_pc=0x0c0722aau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0722ac;
P_0c0722ac: /* original f469, guest PC 0x0c0722ac */
if(!s->budget--) { s->failed_pc=0x0c0722acu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0722ae;
P_0c0722ae: /* original f031, guest PC 0x0c0722ae */
if(!s->budget--) { s->failed_pc=0x0c0722aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0722b0;
P_0c0722b0: /* original f258, guest PC 0x0c0722b0 */
if(!s->budget--) { s->failed_pc=0x0c0722b0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0722b2;
P_0c0722b2: /* original f568, guest PC 0x0c0722b2 */
if(!s->budget--) { s->failed_pc=0x0c0722b2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0722b4;
P_0c0722b4: /* original f141, guest PC 0x0c0722b4 */
if(!s->budget--) { s->failed_pc=0x0c0722b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0722b6;
P_0c0722b6: /* original f251, guest PC 0x0c0722b6 */
if(!s->budget--) { s->failed_pc=0x0c0722b6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0722b8;
P_0c0722b8: /* original 7408, guest PC 0x0c0722b8 */
if(!s->budget--) { s->failed_pc=0x0c0722b8u; return 0; }
r[4]+=0x00000008u;
goto P_0c0722ba;
P_0c0722ba: /* original f42a, guest PC 0x0c0722ba */
if(!s->budget--) { s->failed_pc=0x0c0722bau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0722bc;
P_0c0722bc: /* original f41b, guest PC 0x0c0722bc */
if(!s->budget--) { s->failed_pc=0x0c0722bcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0722be;
P_0c0722be: /* original f40b, guest PC 0x0c0722be */
if(!s->budget--) { s->failed_pc=0x0c0722beu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0722c0;
P_0c0722c0: /* original 66e3, guest PC 0x0c0722c0 */
if(!s->budget--) { s->failed_pc=0x0c0722c0u; return 0; }
r[6]=r[14];
goto P_0c0722c2;
P_0c0722c2: /* original 64a3, guest PC 0x0c0722c2 */
if(!s->budget--) { s->failed_pc=0x0c0722c2u; return 0; }
r[4]=r[10];
goto P_0c0722c4;
P_0c0722c4: /* original 65d3, guest PC 0x0c0722c4 */
if(!s->budget--) { s->failed_pc=0x0c0722c4u; return 0; }
r[5]=r[13];
goto P_0c0722c6;
P_0c0722c6: /* original 760c, guest PC 0x0c0722c6 */
if(!s->budget--) { s->failed_pc=0x0c0722c6u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0722c8;
P_0c0722c8: /* original f049, guest PC 0x0c0722c8 */
if(!s->budget--) { s->failed_pc=0x0c0722c8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0722ca;
P_0c0722ca: /* original f549, guest PC 0x0c0722ca */
if(!s->budget--) { s->failed_pc=0x0c0722cau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0722cc;
P_0c0722cc: /* original f648, guest PC 0x0c0722cc */
if(!s->budget--) { s->failed_pc=0x0c0722ccu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0722ce;
P_0c0722ce: /* original f859, guest PC 0x0c0722ce */
if(!s->budget--) { s->failed_pc=0x0c0722ceu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0722d0;
P_0c0722d0: /* original f959, guest PC 0x0c0722d0 */
if(!s->budget--) { s->failed_pc=0x0c0722d0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0722d2;
P_0c0722d2: /* original fa58, guest PC 0x0c0722d2 */
if(!s->budget--) { s->failed_pc=0x0c0722d2u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0722d4;
P_0c0722d4: /* original 760c, guest PC 0x0c0722d4 */
if(!s->budget--) { s->failed_pc=0x0c0722d4u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0722d6;
P_0c0722d6: /* original f35c, guest PC 0x0c0722d6 */
if(!s->budget--) { s->failed_pc=0x0c0722d6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0722d8;
P_0c0722d8: /* original f382, guest PC 0x0c0722d8 */
if(!s->budget--) { s->failed_pc=0x0c0722d8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0722da;
P_0c0722da: /* original f20c, guest PC 0x0c0722da */
if(!s->budget--) { s->failed_pc=0x0c0722dau; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0722dc;
P_0c0722dc: /* original f2a2, guest PC 0x0c0722dc */
if(!s->budget--) { s->failed_pc=0x0c0722dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0722de;
P_0c0722de: /* original f16c, guest PC 0x0c0722de */
if(!s->budget--) { s->failed_pc=0x0c0722deu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0722e0;
P_0c0722e0: /* original f192, guest PC 0x0c0722e0 */
if(!s->budget--) { s->failed_pc=0x0c0722e0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0722e2;
P_0c0722e2: /* original f34d, guest PC 0x0c0722e2 */
if(!s->budget--) { s->failed_pc=0x0c0722e2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0722e4;
P_0c0722e4: /* original f39e, guest PC 0x0c0722e4 */
if(!s->budget--) { s->failed_pc=0x0c0722e4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0722e6;
P_0c0722e6: /* original f24d, guest PC 0x0c0722e6 */
if(!s->budget--) { s->failed_pc=0x0c0722e6u; return 0; }
fr[2]^=0x80000000u;
goto P_0c0722e8;
P_0c0722e8: /* original f06c, guest PC 0x0c0722e8 */
if(!s->budget--) { s->failed_pc=0x0c0722e8u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0722ea;
P_0c0722ea: /* original f28e, guest PC 0x0c0722ea */
if(!s->budget--) { s->failed_pc=0x0c0722eau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0722ec;
P_0c0722ec: /* original f14d, guest PC 0x0c0722ec */
if(!s->budget--) { s->failed_pc=0x0c0722ecu; return 0; }
fr[1]^=0x80000000u;
goto P_0c0722ee;
P_0c0722ee: /* original f63b, guest PC 0x0c0722ee */
if(!s->budget--) { s->failed_pc=0x0c0722eeu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0722f0;
P_0c0722f0: /* original f05c, guest PC 0x0c0722f0 */
if(!s->budget--) { s->failed_pc=0x0c0722f0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0722f2;
P_0c0722f2: /* original f1ae, guest PC 0x0c0722f2 */
if(!s->budget--) { s->failed_pc=0x0c0722f2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0722f4;
P_0c0722f4: /* original f62b, guest PC 0x0c0722f4 */
if(!s->budget--) { s->failed_pc=0x0c0722f4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0722f6;
P_0c0722f6: /* original f61b, guest PC 0x0c0722f6 */
if(!s->budget--) { s->failed_pc=0x0c0722f6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0722f8;
P_0c0722f8: /* original 64e3, guest PC 0x0c0722f8 */
if(!s->budget--) { s->failed_pc=0x0c0722f8u; return 0; }
r[4]=r[14];
goto P_0c0722fa;
P_0c0722fa: /* original 65e3, guest PC 0x0c0722fa */
if(!s->budget--) { s->failed_pc=0x0c0722fau; return 0; }
r[5]=r[14];
goto P_0c0722fc;
P_0c0722fc: /* original 740c, guest PC 0x0c0722fc */
if(!s->budget--) { s->failed_pc=0x0c0722fcu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0722fe;
P_0c0722fe: /* original f4fc, guest PC 0x0c0722fe */
if(!s->budget--) { s->failed_pc=0x0c0722feu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072300;
P_0c072300: /* original 750c, guest PC 0x0c072300 */
if(!s->budget--) { s->failed_pc=0x0c072300u; return 0; }
r[5]+=0x0000000cu;
goto P_0c072302;
P_0c072302: /* original f059, guest PC 0x0c072302 */
if(!s->budget--) { s->failed_pc=0x0c072302u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072304;
P_0c072304: /* original f159, guest PC 0x0c072304 */
if(!s->budget--) { s->failed_pc=0x0c072304u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072306;
P_0c072306: /* original f259, guest PC 0x0c072306 */
if(!s->budget--) { s->failed_pc=0x0c072306u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072308;
P_0c072308: /* original f38d, guest PC 0x0c072308 */
if(!s->budget--) { s->failed_pc=0x0c072308u; return 0; }
fr[3]=0;
goto P_0c07230a;
P_0c07230a: /* original f0ed, guest PC 0x0c07230a */
if(!s->budget--) { s->failed_pc=0x0c07230au; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07230c;
P_0c07230c: /* original f37d, guest PC 0x0c07230c */
if(!s->budget--) { s->failed_pc=0x0c07230cu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07230e;
P_0c07230e: /* original f342, guest PC 0x0c07230e */
if(!s->budget--) { s->failed_pc=0x0c07230eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c072310;
P_0c072310: /* original 740c, guest PC 0x0c072310 */
if(!s->budget--) { s->failed_pc=0x0c072310u; return 0; }
r[4]+=0x0000000cu;
goto P_0c072312;
P_0c072312: /* original f232, guest PC 0x0c072312 */
if(!s->budget--) { s->failed_pc=0x0c072312u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c072314;
P_0c072314: /* original f132, guest PC 0x0c072314 */
if(!s->budget--) { s->failed_pc=0x0c072314u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c072316;
P_0c072316: /* original f032, guest PC 0x0c072316 */
if(!s->budget--) { s->failed_pc=0x0c072316u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c072318;
P_0c072318: /* original f42b, guest PC 0x0c072318 */
if(!s->budget--) { s->failed_pc=0x0c072318u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07231a;
P_0c07231a: /* original f41b, guest PC 0x0c07231a */
if(!s->budget--) { s->failed_pc=0x0c07231au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07231c;
P_0c07231c: /* original f40b, guest PC 0x0c07231c */
if(!s->budget--) { s->failed_pc=0x0c07231cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07231e;
P_0c07231e: /* original 0009, guest PC 0x0c07231e */
if(!s->budget--) { s->failed_pc=0x0c07231eu; return 0; }
goto P_0c072320;
P_0c072320: /* original 53f2, guest PC 0x0c072320 */
if(!s->budget--) { s->failed_pc=0x0c072320u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c072322;
P_0c072322: /* original 62f3, guest PC 0x0c072322 */
if(!s->budget--) { s->failed_pc=0x0c072322u; return 0; }
r[2]=r[15];
goto P_0c072324;
P_0c072324: /* original 6eb3, guest PC 0x0c072324 */
if(!s->budget--) { s->failed_pc=0x0c072324u; return 0; }
r[14]=r[11];
goto P_0c072326;
P_0c072326: /* original 7254, guest PC 0x0c072326 */
if(!s->budget--) { s->failed_pc=0x0c072326u; return 0; }
r[2]+=0x00000054u;
goto P_0c072328;
P_0c072328: /* original 73ff, guest PC 0x0c072328 */
if(!s->budget--) { s->failed_pc=0x0c072328u; return 0; }
r[3]+=0xffffffffu;
goto P_0c07232a;
P_0c07232a: /* original 7b18, guest PC 0x0c07232a */
if(!s->budget--) { s->failed_pc=0x0c07232au; return 0; }
r[11]+=0x00000018u;
goto P_0c07232c;
P_0c07232c: /* original 1f34, guest PC 0x0c07232c */
if(!s->budget--) { s->failed_pc=0x0c07232cu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07232e;
P_0c07232e: /* original d104, guest PC 0x0c07232e */
if(!s->budget--) { s->failed_pc=0x0c07232eu; return 0; }
r[1]=read(ram,0x0c072340u,4);
goto P_0c072330;
P_0c072330: /* original 7918, guest PC 0x0c072330 */
if(!s->budget--) { s->failed_pc=0x0c072330u; return 0; }
r[9]+=0x00000018u;
goto P_0c072332;
P_0c072332: /* original 412b, guest PC 0x0c072332 */
if(!s->budget--) { s->failed_pc=0x0c072332u; return 0; }
target=r[1];
write(ram,r[15]+8,r[2],4);
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
P_0c072334: /* original 1f22, guest PC 0x0c072334 */
if(!s->budget--) { s->failed_pc=0x0c072334u; return 0; }
write(ram,r[15]+8,r[2],4);
if(!vf3_matrix_family(0x0c072336u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c072336u; return 0; } return 1;
P_0c072b40: /* original 2fe6, guest PC 0x0c072b40 */
if(!s->budget--) { s->failed_pc=0x0c072b40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b42;
P_0c072b42: /* original 2fd6, guest PC 0x0c072b42 */
if(!s->budget--) { s->failed_pc=0x0c072b42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b44;
P_0c072b44: /* original 2fc6, guest PC 0x0c072b44 */
if(!s->budget--) { s->failed_pc=0x0c072b44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b46;
P_0c072b46: /* original 2fb6, guest PC 0x0c072b46 */
if(!s->budget--) { s->failed_pc=0x0c072b46u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b48;
P_0c072b48: /* original 2fa6, guest PC 0x0c072b48 */
if(!s->budget--) { s->failed_pc=0x0c072b48u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b4a;
P_0c072b4a: /* original 2f96, guest PC 0x0c072b4a */
if(!s->budget--) { s->failed_pc=0x0c072b4au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b4c;
P_0c072b4c: /* original 2f86, guest PC 0x0c072b4c */
if(!s->budget--) { s->failed_pc=0x0c072b4cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072b4e;
P_0c072b4e: /* original fffb, guest PC 0x0c072b4e */
if(!s->budget--) { s->failed_pc=0x0c072b4eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c072b50;
P_0c072b50: /* original 4f22, guest PC 0x0c072b50 */
if(!s->budget--) { s->failed_pc=0x0c072b50u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c072b52;
P_0c072b52: /* original 4f12, guest PC 0x0c072b52 */
if(!s->budget--) { s->failed_pc=0x0c072b52u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c072b54;
P_0c072b54: /* original 7ff0, guest PC 0x0c072b54 */
if(!s->budget--) { s->failed_pc=0x0c072b54u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c072b56;
P_0c072b56: /* original 2f42, guest PC 0x0c072b56 */
if(!s->budget--) { s->failed_pc=0x0c072b56u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c072b58;
P_0c072b58: /* original dd1a, guest PC 0x0c072b58 */
if(!s->budget--) { s->failed_pc=0x0c072b58u; return 0; }
r[13]=read(ram,0x0c072bc4u,4);
goto P_0c072b5a;
P_0c072b5a: /* original de19, guest PC 0x0c072b5a */
if(!s->budget--) { s->failed_pc=0x0c072b5au; return 0; }
r[14]=read(ram,0x0c072bc0u,4);
goto P_0c072b5c;
P_0c072b5c: /* original 53d8, guest PC 0x0c072b5c */
if(!s->budget--) { s->failed_pc=0x0c072b5cu; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c072b5e;
P_0c072b5e: /* original d21a, guest PC 0x0c072b5e */
if(!s->budget--) { s->failed_pc=0x0c072b5eu; return 0; }
r[2]=read(ram,0x0c072bc8u,4);
goto P_0c072b60;
P_0c072b60: /* original 420b, guest PC 0x0c072b60 */
if(!s->budget--) { s->failed_pc=0x0c072b60u; return 0; }
target=r[2];
r[16]=code_base|0x0c072b64u;
write(ram,r[15]+12,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072b64u) { target=s->pc; goto dispatch; }
goto P_0c072b64;
P_0c072b62: /* original 1f33, guest PC 0x0c072b62 */
if(!s->budget--) { s->failed_pc=0x0c072b62u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c072b64;
P_0c072b64: /* original 2008, guest PC 0x0c072b64 */
if(!s->budget--) { s->failed_pc=0x0c072b64u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c072b66;
P_0c072b66: /* original 8b01, guest PC 0x0c072b66 */
if(!s->budget--) { s->failed_pc=0x0c072b66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072b6c; }
goto P_0c072b68;
P_0c072b68: /* original a0bc, guest PC 0x0c072b68 */
if(!s->budget--) { s->failed_pc=0x0c072b68u; return 0; }
goto P_0c072ce4;
P_0c072b6a: /* original 0009, guest PC 0x0c072b6a */
if(!s->budget--) { s->failed_pc=0x0c072b6au; return 0; }
goto P_0c072b6c;
P_0c072b6c: /* original 62f2, guest PC 0x0c072b6c */
if(!s->budget--) { s->failed_pc=0x0c072b6cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c072b6e;
P_0c072b6e: /* original 8424, guest PC 0x0c072b6e */
if(!s->budget--) { s->failed_pc=0x0c072b6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+4,1);
goto P_0c072b70;
P_0c072b70: /* original 2008, guest PC 0x0c072b70 */
if(!s->budget--) { s->failed_pc=0x0c072b70u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c072b72;
P_0c072b72: /* original 8b01, guest PC 0x0c072b72 */
if(!s->budget--) { s->failed_pc=0x0c072b72u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072b78; }
goto P_0c072b74;
P_0c072b74: /* original a001, guest PC 0x0c072b74 */
if(!s->budget--) { s->failed_pc=0x0c072b74u; return 0; }
r[0]=0x00000048u;
goto P_0c072b7a;
P_0c072b76: /* original e048, guest PC 0x0c072b76 */
if(!s->budget--) { s->failed_pc=0x0c072b76u; return 0; }
r[0]=0x00000048u;
goto P_0c072b78;
P_0c072b78: /* original e05c, guest PC 0x0c072b78 */
if(!s->budget--) { s->failed_pc=0x0c072b78u; return 0; }
r[0]=0x0000005cu;
goto P_0c072b7a;
P_0c072b7a: /* original 0ade, guest PC 0x0c072b7a */
if(!s->budget--) { s->failed_pc=0x0c072b7au; return 0; }
r[10]=read(ram,r[13]+r[0],4);
goto P_0c072b7c;
P_0c072b7c: /* original d313, guest PC 0x0c072b7c */
if(!s->budget--) { s->failed_pc=0x0c072b7cu; return 0; }
r[3]=read(ram,0x0c072bccu,4);
goto P_0c072b7e;
P_0c072b7e: /* original 64a2, guest PC 0x0c072b7e */
if(!s->budget--) { s->failed_pc=0x0c072b7eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c072b80;
P_0c072b80: /* original 2348, guest PC 0x0c072b80 */
if(!s->budget--) { s->failed_pc=0x0c072b80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c072b82;
P_0c072b82: /* original 8b01, guest PC 0x0c072b82 */
if(!s->budget--) { s->failed_pc=0x0c072b82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072b88; }
goto P_0c072b84;
P_0c072b84: /* original a0ae, guest PC 0x0c072b84 */
if(!s->budget--) { s->failed_pc=0x0c072b84u; return 0; }
goto P_0c072ce4;
P_0c072b86: /* original 0009, guest PC 0x0c072b86 */
if(!s->budget--) { s->failed_pc=0x0c072b86u; return 0; }
goto P_0c072b88;
P_0c072b88: /* original e101, guest PC 0x0c072b88 */
if(!s->budget--) { s->failed_pc=0x0c072b88u; return 0; }
r[1]=0x00000001u;
goto P_0c072b8a;
P_0c072b8a: /* original 2148, guest PC 0x0c072b8a */
if(!s->budget--) { s->failed_pc=0x0c072b8au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c072b8c;
P_0c072b8c: /* original 8b01, guest PC 0x0c072b8c */
if(!s->budget--) { s->failed_pc=0x0c072b8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072b92; }
goto P_0c072b8e;
P_0c072b8e: /* original a0a9, guest PC 0x0c072b8e */
if(!s->budget--) { s->failed_pc=0x0c072b8eu; return 0; }
goto P_0c072ce4;
P_0c072b90: /* original 0009, guest PC 0x0c072b90 */
if(!s->budget--) { s->failed_pc=0x0c072b90u; return 0; }
goto P_0c072b92;
P_0c072b92: /* original 64f2, guest PC 0x0c072b92 */
if(!s->budget--) { s->failed_pc=0x0c072b92u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c072b94;
P_0c072b94: /* original e060, guest PC 0x0c072b94 */
if(!s->budget--) { s->failed_pc=0x0c072b94u; return 0; }
r[0]=0x00000060u;
goto P_0c072b96;
P_0c072b96: /* original 044c, guest PC 0x0c072b96 */
if(!s->budget--) { s->failed_pc=0x0c072b96u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c072b98;
P_0c072b98: /* original 644c, guest PC 0x0c072b98 */
if(!s->budget--) { s->failed_pc=0x0c072b98u; return 0; }
r[4]=r[4]&255u;
goto P_0c072b9a;
P_0c072b9a: /* original 6043, guest PC 0x0c072b9a */
if(!s->budget--) { s->failed_pc=0x0c072b9au; return 0; }
r[0]=r[4];
goto P_0c072b9c;
P_0c072b9c: /* original 880b, guest PC 0x0c072b9c */
if(!s->budget--) { s->failed_pc=0x0c072b9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c072b9e;
P_0c072b9e: /* original 8b05, guest PC 0x0c072b9e */
if(!s->budget--) { s->failed_pc=0x0c072b9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072bac; }
goto P_0c072ba0;
P_0c072ba0: /* original 900c, guest PC 0x0c072ba0 */
if(!s->budget--) { s->failed_pc=0x0c072ba0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072bbcu,2);
goto P_0c072ba2;
P_0c072ba2: /* original 02ec, guest PC 0x0c072ba2 */
if(!s->budget--) { s->failed_pc=0x0c072ba2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c072ba4;
P_0c072ba4: /* original 2228, guest PC 0x0c072ba4 */
if(!s->budget--) { s->failed_pc=0x0c072ba4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c072ba6;
P_0c072ba6: /* original 891b, guest PC 0x0c072ba6 */
if(!s->budget--) { s->failed_pc=0x0c072ba6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072be0; }
goto P_0c072ba8;
P_0c072ba8: /* original a01a, guest PC 0x0c072ba8 */
if(!s->budget--) { s->failed_pc=0x0c072ba8u; return 0; }
r[4]=0x0000001au;
goto P_0c072be0;
P_0c072baa: /* original e41a, guest PC 0x0c072baa */
if(!s->budget--) { s->failed_pc=0x0c072baau; return 0; }
r[4]=0x0000001au;
goto P_0c072bac;
P_0c072bac: /* original 8818, guest PC 0x0c072bac */
if(!s->budget--) { s->failed_pc=0x0c072bacu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c072bae;
P_0c072bae: /* original 8b0f, guest PC 0x0c072bae */
if(!s->budget--) { s->failed_pc=0x0c072baeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072bd0; }
goto P_0c072bb0;
P_0c072bb0: /* original 9004, guest PC 0x0c072bb0 */
if(!s->budget--) { s->failed_pc=0x0c072bb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072bbcu,2);
goto P_0c072bb2;
P_0c072bb2: /* original 02ec, guest PC 0x0c072bb2 */
if(!s->budget--) { s->failed_pc=0x0c072bb2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c072bb4;
P_0c072bb4: /* original 2228, guest PC 0x0c072bb4 */
if(!s->budget--) { s->failed_pc=0x0c072bb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c072bb6;
P_0c072bb6: /* original 8913, guest PC 0x0c072bb6 */
if(!s->budget--) { s->failed_pc=0x0c072bb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072be0; }
goto P_0c072bb8;
P_0c072bb8: /* original a012, guest PC 0x0c072bb8 */
if(!s->budget--) { s->failed_pc=0x0c072bb8u; return 0; }
r[4]=0x0000001bu;
goto P_0c072be0;
P_0c072bba: /* original e41b, guest PC 0x0c072bba */
if(!s->budget--) { s->failed_pc=0x0c072bbau; return 0; }
r[4]=0x0000001bu;
if(!vf3_matrix_family(0x0c072bbcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c072bbcu; return 0; } return 1;
P_0c072bd0: /* original 6043, guest PC 0x0c072bd0 */
if(!s->budget--) { s->failed_pc=0x0c072bd0u; return 0; }
r[0]=r[4];
goto P_0c072bd2;
P_0c072bd2: /* original 880c, guest PC 0x0c072bd2 */
if(!s->budget--) { s->failed_pc=0x0c072bd2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c072bd4;
P_0c072bd4: /* original 8b04, guest PC 0x0c072bd4 */
if(!s->budget--) { s->failed_pc=0x0c072bd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072be0; }
goto P_0c072bd6;
P_0c072bd6: /* original 903b, guest PC 0x0c072bd6 */
if(!s->budget--) { s->failed_pc=0x0c072bd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c50u,2);
goto P_0c072bd8;
P_0c072bd8: /* original 02ec, guest PC 0x0c072bd8 */
if(!s->budget--) { s->failed_pc=0x0c072bd8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c072bda;
P_0c072bda: /* original 2228, guest PC 0x0c072bda */
if(!s->budget--) { s->failed_pc=0x0c072bdau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c072bdc;
P_0c072bdc: /* original 8900, guest PC 0x0c072bdc */
if(!s->budget--) { s->failed_pc=0x0c072bdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072be0; }
goto P_0c072bde;
P_0c072bde: /* original e41c, guest PC 0x0c072bde */
if(!s->budget--) { s->failed_pc=0x0c072bdeu; return 0; }
r[4]=0x0000001cu;
goto P_0c072be0;
P_0c072be0: /* original d21e, guest PC 0x0c072be0 */
if(!s->budget--) { s->failed_pc=0x0c072be0u; return 0; }
r[2]=read(ram,0x0c072c5cu,4);
goto P_0c072be2;
P_0c072be2: /* original 4408, guest PC 0x0c072be2 */
if(!s->budget--) { s->failed_pc=0x0c072be2u; return 0; }
r[4]<<=2;
goto P_0c072be4;
P_0c072be4: /* original 4400, guest PC 0x0c072be4 */
if(!s->budget--) { s->failed_pc=0x0c072be4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c072be6;
P_0c072be6: /* original 342c, guest PC 0x0c072be6 */
if(!s->budget--) { s->failed_pc=0x0c072be6u; return 0; }
r[4]+=r[2];
goto P_0c072be8;
P_0c072be8: /* original 6442, guest PC 0x0c072be8 */
if(!s->budget--) { s->failed_pc=0x0c072be8u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c072bea;
P_0c072bea: /* original 2448, guest PC 0x0c072bea */
if(!s->budget--) { s->failed_pc=0x0c072beau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c072bec;
P_0c072bec: /* original 897a, guest PC 0x0c072bec */
if(!s->budget--) { s->failed_pc=0x0c072becu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072ce4; }
goto P_0c072bee;
P_0c072bee: /* original d21c, guest PC 0x0c072bee */
if(!s->budget--) { s->failed_pc=0x0c072beeu; return 0; }
r[2]=read(ram,0x0c072c60u,4);
goto P_0c072bf0;
P_0c072bf0: /* original 420b, guest PC 0x0c072bf0 */
if(!s->budget--) { s->failed_pc=0x0c072bf0u; return 0; }
target=r[2];
r[16]=code_base|0x0c072bf4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072bf4u) { target=s->pc; goto dispatch; }
goto P_0c072bf4;
P_0c072bf2: /* original e400, guest PC 0x0c072bf2 */
if(!s->budget--) { s->failed_pc=0x0c072bf2u; return 0; }
r[4]=0x00000000u;
goto P_0c072bf4;
P_0c072bf4: /* original a065, guest PC 0x0c072bf4 */
if(!s->budget--) { s->failed_pc=0x0c072bf4u; return 0; }
r[11]=0x00000000u;
goto P_0c072cc2;
P_0c072bf6: /* original eb00, guest PC 0x0c072bf6 */
if(!s->budget--) { s->failed_pc=0x0c072bf6u; return 0; }
r[11]=0x00000000u;
goto P_0c072bf8;
P_0c072bf8: /* original 9e2b, guest PC 0x0c072bf8 */
if(!s->budget--) { s->failed_pc=0x0c072bf8u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c52u,2);
goto P_0c072bfa;
P_0c072bfa: /* original 63a3, guest PC 0x0c072bfa */
if(!s->budget--) { s->failed_pc=0x0c072bfau; return 0; }
r[3]=r[10];
goto P_0c072bfc;
P_0c072bfc: /* original 902a, guest PC 0x0c072bfc */
if(!s->budget--) { s->failed_pc=0x0c072bfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c54u,2);
goto P_0c072bfe;
P_0c072bfe: /* original 7314, guest PC 0x0c072bfe */
if(!s->budget--) { s->failed_pc=0x0c072bfeu; return 0; }
r[3]+=0x00000014u;
goto P_0c072c00;
P_0c072c00: /* original 2bef, guest PC 0x0c072c00 */
if(!s->budget--) { s->failed_pc=0x0c072c00u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[14]);
goto P_0c072c02;
P_0c072c02: /* original d418, guest PC 0x0c072c02 */
if(!s->budget--) { s->failed_pc=0x0c072c02u; return 0; }
r[4]=read(ram,0x0c072c64u,4);
goto P_0c072c04;
P_0c072c04: /* original e160, guest PC 0x0c072c04 */
if(!s->budget--) { s->failed_pc=0x0c072c04u; return 0; }
r[1]=0x00000060u;
goto P_0c072c06;
P_0c072c06: /* original 0e1a, guest PC 0x0c072c06 */
if(!s->budget--) { s->failed_pc=0x0c072c06u; return 0; }
r[14]=r[19];
goto P_0c072c08;
P_0c072c08: /* original 6eef, guest PC 0x0c072c08 */
if(!s->budget--) { s->failed_pc=0x0c072c08u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c072c0a;
P_0c072c0a: /* original 3e3c, guest PC 0x0c072c0a */
if(!s->budget--) { s->failed_pc=0x0c072c0au; return 0; }
r[14]+=r[3];
goto P_0c072c0c;
P_0c072c0c: /* original 00ee, guest PC 0x0c072c0c */
if(!s->budget--) { s->failed_pc=0x0c072c0cu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c072c0e;
P_0c072c0e: /* original 4008, guest PC 0x0c072c0e */
if(!s->budget--) { s->failed_pc=0x0c072c0eu; return 0; }
r[0]<<=2;
goto P_0c072c10;
P_0c072c10: /* original 0c4e, guest PC 0x0c072c10 */
if(!s->budget--) { s->failed_pc=0x0c072c10u; return 0; }
r[12]=read(ram,r[4]+r[0],4);
goto P_0c072c12;
P_0c072c12: /* original 60f2, guest PC 0x0c072c12 */
if(!s->budget--) { s->failed_pc=0x0c072c12u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c072c14;
P_0c072c14: /* original 001c, guest PC 0x0c072c14 */
if(!s->budget--) { s->failed_pc=0x0c072c14u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c072c16;
P_0c072c16: /* original 600c, guest PC 0x0c072c16 */
if(!s->budget--) { s->failed_pc=0x0c072c16u; return 0; }
r[0]=r[0]&255u;
goto P_0c072c18;
P_0c072c18: /* original 8808, guest PC 0x0c072c18 */
if(!s->budget--) { s->failed_pc=0x0c072c18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c072c1a;
P_0c072c1a: /* original 8b27, guest PC 0x0c072c1a */
if(!s->budget--) { s->failed_pc=0x0c072c1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072c6c; }
goto P_0c072c1c;
P_0c072c1c: /* original 901b, guest PC 0x0c072c1c */
if(!s->budget--) { s->failed_pc=0x0c072c1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c56u,2);
goto P_0c072c1e;
P_0c072c1e: /* original 54f3, guest PC 0x0c072c1e */
if(!s->budget--) { s->failed_pc=0x0c072c1eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c072c20;
P_0c072c20: /* original 044e, guest PC 0x0c072c20 */
if(!s->budget--) { s->failed_pc=0x0c072c20u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c072c22;
P_0c072c22: /* original 6043, guest PC 0x0c072c22 */
if(!s->budget--) { s->failed_pc=0x0c072c22u; return 0; }
r[0]=r[4];
goto P_0c072c24;
P_0c072c24: /* original 8804, guest PC 0x0c072c24 */
if(!s->budget--) { s->failed_pc=0x0c072c24u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c072c26;
P_0c072c26: /* original 8902, guest PC 0x0c072c26 */
if(!s->budget--) { s->failed_pc=0x0c072c26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072c2e; }
goto P_0c072c28;
P_0c072c28: /* original 6043, guest PC 0x0c072c28 */
if(!s->budget--) { s->failed_pc=0x0c072c28u; return 0; }
r[0]=r[4];
goto P_0c072c2a;
P_0c072c2a: /* original 8814, guest PC 0x0c072c2a */
if(!s->budget--) { s->failed_pc=0x0c072c2au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c072c2c;
P_0c072c2c: /* original 8b06, guest PC 0x0c072c2c */
if(!s->budget--) { s->failed_pc=0x0c072c2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072c3c; }
goto P_0c072c2e;
P_0c072c2e: /* original d20e, guest PC 0x0c072c2e */
if(!s->budget--) { s->failed_pc=0x0c072c2eu; return 0; }
r[2]=read(ram,0x0c072c68u,4);
goto P_0c072c30;
P_0c072c30: /* original 6320, guest PC 0x0c072c30 */
if(!s->budget--) { s->failed_pc=0x0c072c30u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c072c32;
P_0c072c32: /* original 2338, guest PC 0x0c072c32 */
if(!s->budget--) { s->failed_pc=0x0c072c32u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c072c34;
P_0c072c34: /* original 8902, guest PC 0x0c072c34 */
if(!s->budget--) { s->failed_pc=0x0c072c34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072c3c; }
goto P_0c072c36;
P_0c072c36: /* original 900f, guest PC 0x0c072c36 */
if(!s->budget--) { s->failed_pc=0x0c072c36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c58u,2);
goto P_0c072c38;
P_0c072c38: /* original e414, guest PC 0x0c072c38 */
if(!s->budget--) { s->failed_pc=0x0c072c38u; return 0; }
r[4]=0x00000014u;
goto P_0c072c3a;
P_0c072c3a: /* original 0e46, guest PC 0x0c072c3a */
if(!s->budget--) { s->failed_pc=0x0c072c3au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c072c3c;
P_0c072c3c: /* original 900c, guest PC 0x0c072c3c */
if(!s->budget--) { s->failed_pc=0x0c072c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c072c58u,2);
goto P_0c072c3e;
P_0c072c3e: /* original 03ee, guest PC 0x0c072c3e */
if(!s->budget--) { s->failed_pc=0x0c072c3eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c072c40;
P_0c072c40: /* original 4315, guest PC 0x0c072c40 */
if(!s->budget--) { s->failed_pc=0x0c072c40u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c072c42;
P_0c072c42: /* original 8b13, guest PC 0x0c072c42 */
if(!s->budget--) { s->failed_pc=0x0c072c42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072c6c; }
goto P_0c072c44;
P_0c072c44: /* original 2bb8, guest PC 0x0c072c44 */
if(!s->budget--) { s->failed_pc=0x0c072c44u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c072c46;
P_0c072c46: /* original 8b11, guest PC 0x0c072c46 */
if(!s->budget--) { s->failed_pc=0x0c072c46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072c6c; }
goto P_0c072c48;
P_0c072c48: /* original 03ee, guest PC 0x0c072c48 */
if(!s->budget--) { s->failed_pc=0x0c072c48u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c072c4a;
P_0c072c4a: /* original 73ff, guest PC 0x0c072c4a */
if(!s->budget--) { s->failed_pc=0x0c072c4au; return 0; }
r[3]+=0xffffffffu;
goto P_0c072c4c;
P_0c072c4c: /* original a038, guest PC 0x0c072c4c */
if(!s->budget--) { s->failed_pc=0x0c072c4cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c072cc0;
P_0c072c4e: /* original 0e36, guest PC 0x0c072c4e */
if(!s->budget--) { s->failed_pc=0x0c072c4eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
if(!vf3_matrix_family(0x0c072c50u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c072c50u; return 0; } return 1;
P_0c072c6c: /* original 2cc8, guest PC 0x0c072c6c */
if(!s->budget--) { s->failed_pc=0x0c072c6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c072c6e;
P_0c072c6e: /* original 8927, guest PC 0x0c072c6e */
if(!s->budget--) { s->failed_pc=0x0c072c6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072cc0; }
goto P_0c072c70;
P_0c072c70: /* original 58c1, guest PC 0x0c072c70 */
if(!s->budget--) { s->failed_pc=0x0c072c70u; return 0; }
r[8]=read(ram,r[12]+4,4);
goto P_0c072c72;
P_0c072c72: /* original 64e2, guest PC 0x0c072c72 */
if(!s->budget--) { s->failed_pc=0x0c072c72u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c072c74;
P_0c072c74: /* original 5381, guest PC 0x0c072c74 */
if(!s->budget--) { s->failed_pc=0x0c072c74u; return 0; }
r[3]=read(ram,r[8]+4,4);
goto P_0c072c76;
P_0c072c76: /* original 5dcb, guest PC 0x0c072c76 */
if(!s->budget--) { s->failed_pc=0x0c072c76u; return 0; }
r[13]=read(ram,r[12]+44,4);
goto P_0c072c78;
P_0c072c78: /* original 2448, guest PC 0x0c072c78 */
if(!s->budget--) { s->failed_pc=0x0c072c78u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c072c7a;
P_0c072c7a: /* original 8d02, guest PC 0x0c072c7a */
if(!s->budget--) { s->failed_pc=0x0c072c7au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(cond) { goto P_0c072c82; }
goto P_0c072c7e;
P_0c072c7c: /* original 1f31, guest PC 0x0c072c7c */
if(!s->budget--) { s->failed_pc=0x0c072c7cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c072c7e;
P_0c072c7e: /* original 51e1, guest PC 0x0c072c7e */
if(!s->budget--) { s->failed_pc=0x0c072c7eu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c072c80;
P_0c072c80: /* original 1811, guest PC 0x0c072c80 */
if(!s->budget--) { s->failed_pc=0x0c072c80u; return 0; }
write(ram,r[8]+4,r[1],4);
goto P_0c072c82;
P_0c072c82: /* original 2dd8, guest PC 0x0c072c82 */
if(!s->budget--) { s->failed_pc=0x0c072c82u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c072c84;
P_0c072c84: /* original 8906, guest PC 0x0c072c84 */
if(!s->budget--) { s->failed_pc=0x0c072c84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072c94; }
goto P_0c072c86;
P_0c072c86: /* original 59d1, guest PC 0x0c072c86 */
if(!s->budget--) { s->failed_pc=0x0c072c86u; return 0; }
r[9]=read(ram,r[13]+4,4);
goto P_0c072c88;
P_0c072c88: /* original 2448, guest PC 0x0c072c88 */
if(!s->budget--) { s->failed_pc=0x0c072c88u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c072c8a;
P_0c072c8a: /* original 5291, guest PC 0x0c072c8a */
if(!s->budget--) { s->failed_pc=0x0c072c8au; return 0; }
r[2]=read(ram,r[9]+4,4);
goto P_0c072c8c;
P_0c072c8c: /* original 8d02, guest PC 0x0c072c8c */
if(!s->budget--) { s->failed_pc=0x0c072c8cu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(cond) { goto P_0c072c94; }
goto P_0c072c90;
P_0c072c8e: /* original 1f22, guest PC 0x0c072c8e */
if(!s->budget--) { s->failed_pc=0x0c072c8eu; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c072c90;
P_0c072c90: /* original 51e2, guest PC 0x0c072c90 */
if(!s->budget--) { s->failed_pc=0x0c072c90u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c072c92;
P_0c072c92: /* original 1911, guest PC 0x0c072c92 */
if(!s->budget--) { s->failed_pc=0x0c072c92u; return 0; }
write(ram,r[9]+4,r[1],4);
goto P_0c072c94;
P_0c072c94: /* original d319, guest PC 0x0c072c94 */
if(!s->budget--) { s->failed_pc=0x0c072c94u; return 0; }
r[3]=read(ram,0x0c072cfcu,4);
goto P_0c072c96;
P_0c072c96: /* original 430b, guest PC 0x0c072c96 */
if(!s->budget--) { s->failed_pc=0x0c072c96u; return 0; }
target=r[3];
r[16]=code_base|0x0c072c9au;
r[4]=read(ram,r[14]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072c9au) { target=s->pc; goto dispatch; }
goto P_0c072c9a;
P_0c072c98: /* original 54e3, guest PC 0x0c072c98 */
if(!s->budget--) { s->failed_pc=0x0c072c98u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c072c9a;
P_0c072c9a: /* original ff9d, guest PC 0x0c072c9a */
if(!s->budget--) { s->failed_pc=0x0c072c9au; return 0; }
fr[15]=0x3f800000u;
goto P_0c072c9c;
P_0c072c9c: /* original de18, guest PC 0x0c072c9c */
if(!s->budget--) { s->failed_pc=0x0c072c9cu; return 0; }
r[14]=read(ram,0x0c072d00u,4);
goto P_0c072c9e;
P_0c072c9e: /* original f4fc, guest PC 0x0c072c9e */
if(!s->budget--) { s->failed_pc=0x0c072c9eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072ca0;
P_0c072ca0: /* original 4e0b, guest PC 0x0c072ca0 */
if(!s->budget--) { s->failed_pc=0x0c072ca0u; return 0; }
target=r[14];
r[16]=code_base|0x0c072ca4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072ca4u) { target=s->pc; goto dispatch; }
goto P_0c072ca4;
P_0c072ca2: /* original 64c3, guest PC 0x0c072ca2 */
if(!s->budget--) { s->failed_pc=0x0c072ca2u; return 0; }
r[4]=r[12];
goto P_0c072ca4;
P_0c072ca4: /* original 2dd8, guest PC 0x0c072ca4 */
if(!s->budget--) { s->failed_pc=0x0c072ca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c072ca6;
P_0c072ca6: /* original 8902, guest PC 0x0c072ca6 */
if(!s->budget--) { s->failed_pc=0x0c072ca6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072cae; }
goto P_0c072ca8;
P_0c072ca8: /* original f4fc, guest PC 0x0c072ca8 */
if(!s->budget--) { s->failed_pc=0x0c072ca8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c072caa;
P_0c072caa: /* original 4e0b, guest PC 0x0c072caa */
if(!s->budget--) { s->failed_pc=0x0c072caau; return 0; }
target=r[14];
r[16]=code_base|0x0c072caeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072caeu) { target=s->pc; goto dispatch; }
goto P_0c072cae;
P_0c072cac: /* original 64d3, guest PC 0x0c072cac */
if(!s->budget--) { s->failed_pc=0x0c072cacu; return 0; }
r[4]=r[13];
goto P_0c072cae;
P_0c072cae: /* original de15, guest PC 0x0c072cae */
if(!s->budget--) { s->failed_pc=0x0c072caeu; return 0; }
r[14]=read(ram,0x0c072d04u,4);
goto P_0c072cb0;
P_0c072cb0: /* original 4e0b, guest PC 0x0c072cb0 */
if(!s->budget--) { s->failed_pc=0x0c072cb0u; return 0; }
target=r[14];
r[16]=code_base|0x0c072cb4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072cb4u) { target=s->pc; goto dispatch; }
goto P_0c072cb4;
P_0c072cb2: /* original 0009, guest PC 0x0c072cb2 */
if(!s->budget--) { s->failed_pc=0x0c072cb2u; return 0; }
goto P_0c072cb4;
P_0c072cb4: /* original 53f1, guest PC 0x0c072cb4 */
if(!s->budget--) { s->failed_pc=0x0c072cb4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c072cb6;
P_0c072cb6: /* original 2dd8, guest PC 0x0c072cb6 */
if(!s->budget--) { s->failed_pc=0x0c072cb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c072cb8;
P_0c072cb8: /* original 8d02, guest PC 0x0c072cb8 */
if(!s->budget--) { s->failed_pc=0x0c072cb8u; return 0; }
cond=r[17]&1u;
write(ram,r[8]+4,r[3],4);
if(cond) { goto P_0c072cc0; }
goto P_0c072cbc;
P_0c072cba: /* original 1831, guest PC 0x0c072cba */
if(!s->budget--) { s->failed_pc=0x0c072cbau; return 0; }
write(ram,r[8]+4,r[3],4);
goto P_0c072cbc;
P_0c072cbc: /* original 51f2, guest PC 0x0c072cbc */
if(!s->budget--) { s->failed_pc=0x0c072cbcu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c072cbe;
P_0c072cbe: /* original 1911, guest PC 0x0c072cbe */
if(!s->budget--) { s->failed_pc=0x0c072cbeu; return 0; }
write(ram,r[9]+4,r[1],4);
goto P_0c072cc0;
P_0c072cc0: /* original 7b01, guest PC 0x0c072cc0 */
if(!s->budget--) { s->failed_pc=0x0c072cc0u; return 0; }
r[11]+=0x00000001u;
goto P_0c072cc2;
P_0c072cc2: /* original 53a4, guest PC 0x0c072cc2 */
if(!s->budget--) { s->failed_pc=0x0c072cc2u; return 0; }
r[3]=read(ram,r[10]+16,4);
goto P_0c072cc4;
P_0c072cc4: /* original 3b32, guest PC 0x0c072cc4 */
if(!s->budget--) { s->failed_pc=0x0c072cc4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[3])!=0);
goto P_0c072cc6;
P_0c072cc6: /* original 8b97, guest PC 0x0c072cc6 */
if(!s->budget--) { s->failed_pc=0x0c072cc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072bf8; }
goto P_0c072cc8;
P_0c072cc8: /* original 7f10, guest PC 0x0c072cc8 */
if(!s->budget--) { s->failed_pc=0x0c072cc8u; return 0; }
r[15]+=0x00000010u;
goto P_0c072cca;
P_0c072cca: /* original d30f, guest PC 0x0c072cca */
if(!s->budget--) { s->failed_pc=0x0c072ccau; return 0; }
r[3]=read(ram,0x0c072d08u,4);
goto P_0c072ccc;
P_0c072ccc: /* original 4f16, guest PC 0x0c072ccc */
if(!s->budget--) { s->failed_pc=0x0c072cccu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c072cce;
P_0c072cce: /* original e401, guest PC 0x0c072cce */
if(!s->budget--) { s->failed_pc=0x0c072cceu; return 0; }
r[4]=0x00000001u;
goto P_0c072cd0;
P_0c072cd0: /* original 4f26, guest PC 0x0c072cd0 */
if(!s->budget--) { s->failed_pc=0x0c072cd0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c072cd2;
P_0c072cd2: /* original fff9, guest PC 0x0c072cd2 */
if(!s->budget--) { s->failed_pc=0x0c072cd2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c072cd4;
P_0c072cd4: /* original 68f6, guest PC 0x0c072cd4 */
if(!s->budget--) { s->failed_pc=0x0c072cd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c072cd6;
P_0c072cd6: /* original 69f6, guest PC 0x0c072cd6 */
if(!s->budget--) { s->failed_pc=0x0c072cd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c072cd8;
P_0c072cd8: /* original 6af6, guest PC 0x0c072cd8 */
if(!s->budget--) { s->failed_pc=0x0c072cd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c072cda;
P_0c072cda: /* original 6bf6, guest PC 0x0c072cda */
if(!s->budget--) { s->failed_pc=0x0c072cdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c072cdc;
P_0c072cdc: /* original 6cf6, guest PC 0x0c072cdc */
if(!s->budget--) { s->failed_pc=0x0c072cdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c072cde;
P_0c072cde: /* original 6df6, guest PC 0x0c072cde */
if(!s->budget--) { s->failed_pc=0x0c072cdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072ce0;
P_0c072ce0: /* original 432b, guest PC 0x0c072ce0 */
if(!s->budget--) { s->failed_pc=0x0c072ce0u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c072ce2: /* original 6ef6, guest PC 0x0c072ce2 */
if(!s->budget--) { s->failed_pc=0x0c072ce2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c072ce4;
P_0c072ce4: /* original 7f10, guest PC 0x0c072ce4 */
if(!s->budget--) { s->failed_pc=0x0c072ce4u; return 0; }
r[15]+=0x00000010u;
goto P_0c072ce6;
P_0c072ce6: /* original 4f16, guest PC 0x0c072ce6 */
if(!s->budget--) { s->failed_pc=0x0c072ce6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c072ce8;
P_0c072ce8: /* original 4f26, guest PC 0x0c072ce8 */
if(!s->budget--) { s->failed_pc=0x0c072ce8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c072cea;
P_0c072cea: /* original fff9, guest PC 0x0c072cea */
if(!s->budget--) { s->failed_pc=0x0c072ceau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c072cec;
P_0c072cec: /* original 68f6, guest PC 0x0c072cec */
if(!s->budget--) { s->failed_pc=0x0c072cecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c072cee;
P_0c072cee: /* original 69f6, guest PC 0x0c072cee */
if(!s->budget--) { s->failed_pc=0x0c072ceeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c072cf0;
P_0c072cf0: /* original 6af6, guest PC 0x0c072cf0 */
if(!s->budget--) { s->failed_pc=0x0c072cf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c072cf2;
P_0c072cf2: /* original 6bf6, guest PC 0x0c072cf2 */
if(!s->budget--) { s->failed_pc=0x0c072cf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c072cf4;
P_0c072cf4: /* original 6cf6, guest PC 0x0c072cf4 */
if(!s->budget--) { s->failed_pc=0x0c072cf4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c072cf6;
P_0c072cf6: /* original 6df6, guest PC 0x0c072cf6 */
if(!s->budget--) { s->failed_pc=0x0c072cf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072cf8;
P_0c072cf8: /* original 000b, guest PC 0x0c072cf8 */
if(!s->budget--) { s->failed_pc=0x0c072cf8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c072cfa: /* original 6ef6, guest PC 0x0c072cfa */
if(!s->budget--) { s->failed_pc=0x0c072cfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c072cfcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c072cfcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
