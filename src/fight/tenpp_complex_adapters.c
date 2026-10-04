/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_tenpp_complex_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c064530u: goto P_0c064530;
case 0x0c064532u: goto P_0c064532;
case 0x0c064534u: goto P_0c064534;
case 0x0c064536u: goto P_0c064536;
case 0x0c064538u: goto P_0c064538;
case 0x0c06453au: goto P_0c06453a;
case 0x0c06453cu: goto P_0c06453c;
case 0x0c06453eu: goto P_0c06453e;
case 0x0c064540u: goto P_0c064540;
case 0x0c064542u: goto P_0c064542;
case 0x0c064544u: goto P_0c064544;
case 0x0c064546u: goto P_0c064546;
case 0x0c064548u: goto P_0c064548;
case 0x0c06454au: goto P_0c06454a;
case 0x0c06454cu: goto P_0c06454c;
case 0x0c06454eu: goto P_0c06454e;
case 0x0c064550u: goto P_0c064550;
case 0x0c064552u: goto P_0c064552;
case 0x0c064554u: goto P_0c064554;
case 0x0c064556u: goto P_0c064556;
case 0x0c064558u: goto P_0c064558;
case 0x0c06455au: goto P_0c06455a;
case 0x0c06455cu: goto P_0c06455c;
case 0x0c06455eu: goto P_0c06455e;
case 0x0c064560u: goto P_0c064560;
case 0x0c064562u: goto P_0c064562;
case 0x0c064564u: goto P_0c064564;
case 0x0c064566u: goto P_0c064566;
case 0x0c064568u: goto P_0c064568;
case 0x0c06456au: goto P_0c06456a;
case 0x0c06456cu: goto P_0c06456c;
case 0x0c06456eu: goto P_0c06456e;
case 0x0c064570u: goto P_0c064570;
case 0x0c064572u: goto P_0c064572;
case 0x0c064574u: goto P_0c064574;
case 0x0c064576u: goto P_0c064576;
case 0x0c064578u: goto P_0c064578;
case 0x0c06457au: goto P_0c06457a;
case 0x0c06457cu: goto P_0c06457c;
case 0x0c06457eu: goto P_0c06457e;
case 0x0c064580u: goto P_0c064580;
case 0x0c064582u: goto P_0c064582;
case 0x0c064584u: goto P_0c064584;
case 0x0c064586u: goto P_0c064586;
case 0x0c064588u: goto P_0c064588;
case 0x0c06458au: goto P_0c06458a;
case 0x0c06458cu: goto P_0c06458c;
case 0x0c06458eu: goto P_0c06458e;
case 0x0c064590u: goto P_0c064590;
case 0x0c064592u: goto P_0c064592;
case 0x0c064772u: goto P_0c064772;
case 0x0c064774u: goto P_0c064774;
case 0x0c064776u: goto P_0c064776;
case 0x0c064778u: goto P_0c064778;
case 0x0c06477au: goto P_0c06477a;
case 0x0c06477cu: goto P_0c06477c;
case 0x0c06477eu: goto P_0c06477e;
case 0x0c064780u: goto P_0c064780;
case 0x0c064782u: goto P_0c064782;
case 0x0c064784u: goto P_0c064784;
case 0x0c064786u: goto P_0c064786;
case 0x0c064788u: goto P_0c064788;
case 0x0c06478au: goto P_0c06478a;
case 0x0c06478cu: goto P_0c06478c;
case 0x0c06478eu: goto P_0c06478e;
case 0x0c064790u: goto P_0c064790;
case 0x0c064792u: goto P_0c064792;
case 0x0c064794u: goto P_0c064794;
case 0x0c064796u: goto P_0c064796;
case 0x0c064798u: goto P_0c064798;
case 0x0c06479au: goto P_0c06479a;
case 0x0c06479cu: goto P_0c06479c;
case 0x0c06479eu: goto P_0c06479e;
case 0x0c0647a0u: goto P_0c0647a0;
case 0x0c0647a2u: goto P_0c0647a2;
case 0x0c0647a4u: goto P_0c0647a4;
case 0x0c0647a6u: goto P_0c0647a6;
case 0x0c0647a8u: goto P_0c0647a8;
case 0x0c0647aau: goto P_0c0647aa;
case 0x0c0647acu: goto P_0c0647ac;
case 0x0c0647aeu: goto P_0c0647ae;
case 0x0c0647b0u: goto P_0c0647b0;
case 0x0c0647b2u: goto P_0c0647b2;
case 0x0c0647b4u: goto P_0c0647b4;
case 0x0c0647b6u: goto P_0c0647b6;
case 0x0c0647b8u: goto P_0c0647b8;
case 0x0c0647bau: goto P_0c0647ba;
case 0x0c0647bcu: goto P_0c0647bc;
case 0x0c0647beu: goto P_0c0647be;
case 0x0c0647c0u: goto P_0c0647c0;
case 0x0c0647c2u: goto P_0c0647c2;
case 0x0c0647c4u: goto P_0c0647c4;
case 0x0c0647c6u: goto P_0c0647c6;
case 0x0c0647c8u: goto P_0c0647c8;
case 0x0c0647cau: goto P_0c0647ca;
case 0x0c0647ccu: goto P_0c0647cc;
case 0x0c0647ceu: goto P_0c0647ce;
case 0x0c0647d0u: goto P_0c0647d0;
case 0x0c0647d2u: goto P_0c0647d2;
case 0x0c0647d4u: goto P_0c0647d4;
case 0x0c0647d6u: goto P_0c0647d6;
case 0x0c0647d8u: goto P_0c0647d8;
case 0x0c0647dau: goto P_0c0647da;
case 0x0c0647dcu: goto P_0c0647dc;
case 0x0c0647deu: goto P_0c0647de;
case 0x0c0647e0u: goto P_0c0647e0;
case 0x0c0647e2u: goto P_0c0647e2;
case 0x0c0647e4u: goto P_0c0647e4;
case 0x0c0647e6u: goto P_0c0647e6;
case 0x0c0647e8u: goto P_0c0647e8;
case 0x0c0647eau: goto P_0c0647ea;
case 0x0c0647ecu: goto P_0c0647ec;
case 0x0c0647eeu: goto P_0c0647ee;
case 0x0c0647f0u: goto P_0c0647f0;
case 0x0c0647f2u: goto P_0c0647f2;
case 0x0c0647f4u: goto P_0c0647f4;
case 0x0c0647f6u: goto P_0c0647f6;
case 0x0c0647f8u: goto P_0c0647f8;
case 0x0c0647fau: goto P_0c0647fa;
case 0x0c0647fcu: goto P_0c0647fc;
case 0x0c0647feu: goto P_0c0647fe;
case 0x0c064800u: goto P_0c064800;
case 0x0c064802u: goto P_0c064802;
case 0x0c064804u: goto P_0c064804;
case 0x0c064806u: goto P_0c064806;
case 0x0c064808u: goto P_0c064808;
case 0x0c06480au: goto P_0c06480a;
case 0x0c06480cu: goto P_0c06480c;
case 0x0c06480eu: goto P_0c06480e;
case 0x0c064810u: goto P_0c064810;
case 0x0c064812u: goto P_0c064812;
case 0x0c064814u: goto P_0c064814;
case 0x0c064816u: goto P_0c064816;
case 0x0c064818u: goto P_0c064818;
case 0x0c06481au: goto P_0c06481a;
case 0x0c06481cu: goto P_0c06481c;
case 0x0c06481eu: goto P_0c06481e;
case 0x0c064820u: goto P_0c064820;
case 0x0c064822u: goto P_0c064822;
case 0x0c064824u: goto P_0c064824;
case 0x0c064826u: goto P_0c064826;
case 0x0c064828u: goto P_0c064828;
case 0x0c06482au: goto P_0c06482a;
case 0x0c06482cu: goto P_0c06482c;
case 0x0c06482eu: goto P_0c06482e;
case 0x0c064830u: goto P_0c064830;
case 0x0c064832u: goto P_0c064832;
case 0x0c064834u: goto P_0c064834;
case 0x0c064836u: goto P_0c064836;
case 0x0c064838u: goto P_0c064838;
case 0x0c06483au: goto P_0c06483a;
case 0x0c06483cu: goto P_0c06483c;
case 0x0c06483eu: goto P_0c06483e;
case 0x0c064840u: goto P_0c064840;
case 0x0c064842u: goto P_0c064842;
case 0x0c064844u: goto P_0c064844;
case 0x0c064846u: goto P_0c064846;
case 0x0c064848u: goto P_0c064848;
case 0x0c06484au: goto P_0c06484a;
case 0x0c06484cu: goto P_0c06484c;
case 0x0c06484eu: goto P_0c06484e;
case 0x0c064850u: goto P_0c064850;
case 0x0c064852u: goto P_0c064852;
case 0x0c064854u: goto P_0c064854;
case 0x0c064856u: goto P_0c064856;
case 0x0c064858u: goto P_0c064858;
case 0x0c06485au: goto P_0c06485a;
case 0x0c06485cu: goto P_0c06485c;
case 0x0c06485eu: goto P_0c06485e;
case 0x0c064860u: goto P_0c064860;
case 0x0c064862u: goto P_0c064862;
case 0x0c064864u: goto P_0c064864;
case 0x0c064866u: goto P_0c064866;
case 0x0c064868u: goto P_0c064868;
case 0x0c06486au: goto P_0c06486a;
case 0x0c06486cu: goto P_0c06486c;
case 0x0c06486eu: goto P_0c06486e;
case 0x0c064870u: goto P_0c064870;
case 0x0c064872u: goto P_0c064872;
case 0x0c064874u: goto P_0c064874;
case 0x0c064876u: goto P_0c064876;
case 0x0c064878u: goto P_0c064878;
case 0x0c06487au: goto P_0c06487a;
case 0x0c06487cu: goto P_0c06487c;
case 0x0c06487eu: goto P_0c06487e;
case 0x0c064880u: goto P_0c064880;
case 0x0c064882u: goto P_0c064882;
case 0x0c064884u: goto P_0c064884;
case 0x0c064886u: goto P_0c064886;
case 0x0c064888u: goto P_0c064888;
case 0x0c06488au: goto P_0c06488a;
case 0x0c06488cu: goto P_0c06488c;
case 0x0c06488eu: goto P_0c06488e;
case 0x0c064890u: goto P_0c064890;
case 0x0c064892u: goto P_0c064892;
case 0x0c064894u: goto P_0c064894;
case 0x0c064896u: goto P_0c064896;
case 0x0c064898u: goto P_0c064898;
case 0x0c06489au: goto P_0c06489a;
case 0x0c06489cu: goto P_0c06489c;
case 0x0c06489eu: goto P_0c06489e;
case 0x0c0648a0u: goto P_0c0648a0;
case 0x0c0648a2u: goto P_0c0648a2;
case 0x0c0648a4u: goto P_0c0648a4;
case 0x0c0648a6u: goto P_0c0648a6;
case 0x0c0648a8u: goto P_0c0648a8;
case 0x0c0648aau: goto P_0c0648aa;
case 0x0c0648acu: goto P_0c0648ac;
case 0x0c0648aeu: goto P_0c0648ae;
case 0x0c0648b0u: goto P_0c0648b0;
case 0x0c0648b2u: goto P_0c0648b2;
case 0x0c0648b4u: goto P_0c0648b4;
case 0x0c0648b6u: goto P_0c0648b6;
case 0x0c0648b8u: goto P_0c0648b8;
case 0x0c0648bau: goto P_0c0648ba;
case 0x0c0648bcu: goto P_0c0648bc;
case 0x0c0648beu: goto P_0c0648be;
case 0x0c0648c0u: goto P_0c0648c0;
case 0x0c0648c2u: goto P_0c0648c2;
case 0x0c0648c4u: goto P_0c0648c4;
case 0x0c0648c6u: goto P_0c0648c6;
case 0x0c0648c8u: goto P_0c0648c8;
case 0x0c0648cau: goto P_0c0648ca;
case 0x0c0648ccu: goto P_0c0648cc;
case 0x0c0648ceu: goto P_0c0648ce;
case 0x0c0648d0u: goto P_0c0648d0;
case 0x0c0648d2u: goto P_0c0648d2;
case 0x0c0648d4u: goto P_0c0648d4;
case 0x0c0648d6u: goto P_0c0648d6;
case 0x0c0648d8u: goto P_0c0648d8;
case 0x0c0648dau: goto P_0c0648da;
case 0x0c0648dcu: goto P_0c0648dc;
case 0x0c0648deu: goto P_0c0648de;
case 0x0c0648e0u: goto P_0c0648e0;
case 0x0c0648e2u: goto P_0c0648e2;
case 0x0c0648e4u: goto P_0c0648e4;
case 0x0c0648e6u: goto P_0c0648e6;
case 0x0c0648e8u: goto P_0c0648e8;
case 0x0c0648eau: goto P_0c0648ea;
case 0x0c0648ecu: goto P_0c0648ec;
case 0x0c0648eeu: goto P_0c0648ee;
case 0x0c0648f0u: goto P_0c0648f0;
case 0x0c0648f2u: goto P_0c0648f2;
case 0x0c0648f4u: goto P_0c0648f4;
case 0x0c0648f6u: goto P_0c0648f6;
case 0x0c0648f8u: goto P_0c0648f8;
case 0x0c0648fau: goto P_0c0648fa;
case 0x0c0648fcu: goto P_0c0648fc;
case 0x0c0648feu: goto P_0c0648fe;
case 0x0c064900u: goto P_0c064900;
case 0x0c064902u: goto P_0c064902;
case 0x0c064904u: goto P_0c064904;
case 0x0c064906u: goto P_0c064906;
case 0x0c064908u: goto P_0c064908;
case 0x0c06490au: goto P_0c06490a;
case 0x0c06490cu: goto P_0c06490c;
case 0x0c06490eu: goto P_0c06490e;
case 0x0c064910u: goto P_0c064910;
case 0x0c064912u: goto P_0c064912;
case 0x0c064914u: goto P_0c064914;
case 0x0c064916u: goto P_0c064916;
case 0x0c064918u: goto P_0c064918;
case 0x0c06491au: goto P_0c06491a;
case 0x0c06491cu: goto P_0c06491c;
case 0x0c06491eu: goto P_0c06491e;
case 0x0c064920u: goto P_0c064920;
case 0x0c064922u: goto P_0c064922;
case 0x0c064924u: goto P_0c064924;
case 0x0c064926u: goto P_0c064926;
case 0x0c064928u: goto P_0c064928;
case 0x0c064ab8u: goto P_0c064ab8;
case 0x0c064abau: goto P_0c064aba;
case 0x0c064abcu: goto P_0c064abc;
case 0x0c064abeu: goto P_0c064abe;
case 0x0c064ac0u: goto P_0c064ac0;
case 0x0c064ac2u: goto P_0c064ac2;
case 0x0c064ac4u: goto P_0c064ac4;
case 0x0c064ac6u: goto P_0c064ac6;
case 0x0c064ac8u: goto P_0c064ac8;
case 0x0c064acau: goto P_0c064aca;
case 0x0c064accu: goto P_0c064acc;
case 0x0c064aceu: goto P_0c064ace;
case 0x0c064ad0u: goto P_0c064ad0;
case 0x0c064ad2u: goto P_0c064ad2;
case 0x0c064ad4u: goto P_0c064ad4;
case 0x0c064ad6u: goto P_0c064ad6;
case 0x0c064ad8u: goto P_0c064ad8;
case 0x0c064adau: goto P_0c064ada;
case 0x0c064adcu: goto P_0c064adc;
case 0x0c064adeu: goto P_0c064ade;
case 0x0c064ae0u: goto P_0c064ae0;
case 0x0c064ae2u: goto P_0c064ae2;
case 0x0c064ae4u: goto P_0c064ae4;
case 0x0c064ae6u: goto P_0c064ae6;
case 0x0c064ae8u: goto P_0c064ae8;
case 0x0c064aeau: goto P_0c064aea;
case 0x0c064aecu: goto P_0c064aec;
case 0x0c064aeeu: goto P_0c064aee;
case 0x0c064af0u: goto P_0c064af0;
case 0x0c064af2u: goto P_0c064af2;
case 0x0c064af4u: goto P_0c064af4;
case 0x0c064af6u: goto P_0c064af6;
case 0x0c064af8u: goto P_0c064af8;
case 0x0c064afau: goto P_0c064afa;
case 0x0c064afcu: goto P_0c064afc;
case 0x0c064afeu: goto P_0c064afe;
case 0x0c064b00u: goto P_0c064b00;
case 0x0c064b02u: goto P_0c064b02;
case 0x0c064b04u: goto P_0c064b04;
case 0x0c064b06u: goto P_0c064b06;
case 0x0c064b08u: goto P_0c064b08;
case 0x0c064b0au: goto P_0c064b0a;
case 0x0c064b0cu: goto P_0c064b0c;
case 0x0c064b0eu: goto P_0c064b0e;
case 0x0c064b10u: goto P_0c064b10;
case 0x0c064b12u: goto P_0c064b12;
case 0x0c064b14u: goto P_0c064b14;
case 0x0c064b16u: goto P_0c064b16;
case 0x0c064b18u: goto P_0c064b18;
case 0x0c064b1au: goto P_0c064b1a;
case 0x0c064b1cu: goto P_0c064b1c;
case 0x0c064b1eu: goto P_0c064b1e;
case 0x0c064b20u: goto P_0c064b20;
case 0x0c064b22u: goto P_0c064b22;
case 0x0c064b24u: goto P_0c064b24;
case 0x0c064b26u: goto P_0c064b26;
case 0x0c064b28u: goto P_0c064b28;
case 0x0c064b2au: goto P_0c064b2a;
case 0x0c064b2cu: goto P_0c064b2c;
case 0x0c064b2eu: goto P_0c064b2e;
case 0x0c064b30u: goto P_0c064b30;
case 0x0c064b32u: goto P_0c064b32;
case 0x0c064b34u: goto P_0c064b34;
case 0x0c064b36u: goto P_0c064b36;
case 0x0c064b38u: goto P_0c064b38;
case 0x0c064b3au: goto P_0c064b3a;
case 0x0c064b3cu: goto P_0c064b3c;
case 0x0c064b3eu: goto P_0c064b3e;
case 0x0c064b40u: goto P_0c064b40;
case 0x0c064b42u: goto P_0c064b42;
case 0x0c064b44u: goto P_0c064b44;
case 0x0c064b46u: goto P_0c064b46;
case 0x0c064b48u: goto P_0c064b48;
case 0x0c064b4au: goto P_0c064b4a;
case 0x0c064b4cu: goto P_0c064b4c;
case 0x0c064b4eu: goto P_0c064b4e;
case 0x0c064b50u: goto P_0c064b50;
case 0x0c064b52u: goto P_0c064b52;
case 0x0c064b54u: goto P_0c064b54;
case 0x0c064b56u: goto P_0c064b56;
case 0x0c064b58u: goto P_0c064b58;
case 0x0c064b5au: goto P_0c064b5a;
case 0x0c064b5cu: goto P_0c064b5c;
case 0x0c064b5eu: goto P_0c064b5e;
case 0x0c064b60u: goto P_0c064b60;
case 0x0c064b62u: goto P_0c064b62;
case 0x0c064b64u: goto P_0c064b64;
case 0x0c064b66u: goto P_0c064b66;
case 0x0c064b68u: goto P_0c064b68;
case 0x0c064b6au: goto P_0c064b6a;
case 0x0c064b6cu: goto P_0c064b6c;
case 0x0c064b6eu: goto P_0c064b6e;
case 0x0c064b70u: goto P_0c064b70;
case 0x0c064b72u: goto P_0c064b72;
case 0x0c064b74u: goto P_0c064b74;
case 0x0c064b76u: goto P_0c064b76;
case 0x0c064b78u: goto P_0c064b78;
case 0x0c064b7au: goto P_0c064b7a;
case 0x0c064b7cu: goto P_0c064b7c;
case 0x0c064b7eu: goto P_0c064b7e;
case 0x0c064b80u: goto P_0c064b80;
case 0x0c064b82u: goto P_0c064b82;
case 0x0c064b84u: goto P_0c064b84;
case 0x0c064b86u: goto P_0c064b86;
case 0x0c064b88u: goto P_0c064b88;
case 0x0c064b8au: goto P_0c064b8a;
case 0x0c064b8cu: goto P_0c064b8c;
case 0x0c064b8eu: goto P_0c064b8e;
case 0x0c064b90u: goto P_0c064b90;
case 0x0c064b92u: goto P_0c064b92;
case 0x0c064b94u: goto P_0c064b94;
case 0x0c064b96u: goto P_0c064b96;
case 0x0c064b98u: goto P_0c064b98;
case 0x0c064b9au: goto P_0c064b9a;
case 0x0c064b9cu: goto P_0c064b9c;
case 0x0c064b9eu: goto P_0c064b9e;
case 0x0c064ba0u: goto P_0c064ba0;
case 0x0c064ba2u: goto P_0c064ba2;
case 0x0c064ba4u: goto P_0c064ba4;
case 0x0c064ba6u: goto P_0c064ba6;
case 0x0c064ba8u: goto P_0c064ba8;
case 0x0c064baau: goto P_0c064baa;
case 0x0c064bacu: goto P_0c064bac;
case 0x0c064baeu: goto P_0c064bae;
case 0x0c064bb0u: goto P_0c064bb0;
case 0x0c064bb2u: goto P_0c064bb2;
case 0x0c064bb4u: goto P_0c064bb4;
case 0x0c064bb6u: goto P_0c064bb6;
case 0x0c064bb8u: goto P_0c064bb8;
case 0x0c064bbau: goto P_0c064bba;
case 0x0c064bbcu: goto P_0c064bbc;
case 0x0c064bbeu: goto P_0c064bbe;
case 0x0c064bc0u: goto P_0c064bc0;
case 0x0c064bc2u: goto P_0c064bc2;
case 0x0c064bc4u: goto P_0c064bc4;
case 0x0c064bc6u: goto P_0c064bc6;
case 0x0c064bc8u: goto P_0c064bc8;
case 0x0c064bcau: goto P_0c064bca;
case 0x0c064bccu: goto P_0c064bcc;
case 0x0c064bceu: goto P_0c064bce;
case 0x0c064bd0u: goto P_0c064bd0;
case 0x0c064bd2u: goto P_0c064bd2;
case 0x0c064bd4u: goto P_0c064bd4;
case 0x0c064bd6u: goto P_0c064bd6;
case 0x0c064bd8u: goto P_0c064bd8;
case 0x0c064bdau: goto P_0c064bda;
case 0x0c064bdcu: goto P_0c064bdc;
case 0x0c064bdeu: goto P_0c064bde;
case 0x0c064be0u: goto P_0c064be0;
case 0x0c064be2u: goto P_0c064be2;
case 0x0c064be4u: goto P_0c064be4;
case 0x0c064be6u: goto P_0c064be6;
case 0x0c064be8u: goto P_0c064be8;
case 0x0c064beau: goto P_0c064bea;
case 0x0c064becu: goto P_0c064bec;
case 0x0c064beeu: goto P_0c064bee;
case 0x0c064bf0u: goto P_0c064bf0;
case 0x0c064bf2u: goto P_0c064bf2;
case 0x0c064bf4u: goto P_0c064bf4;
case 0x0c064bf6u: goto P_0c064bf6;
case 0x0c064bf8u: goto P_0c064bf8;
case 0x0c064bfau: goto P_0c064bfa;
case 0x0c064bfcu: goto P_0c064bfc;
case 0x0c064bfeu: goto P_0c064bfe;
case 0x0c064c00u: goto P_0c064c00;
case 0x0c064c02u: goto P_0c064c02;
case 0x0c064c04u: goto P_0c064c04;
case 0x0c064c06u: goto P_0c064c06;
case 0x0c064c08u: goto P_0c064c08;
case 0x0c064c0au: goto P_0c064c0a;
case 0x0c064c0cu: goto P_0c064c0c;
case 0x0c064c0eu: goto P_0c064c0e;
case 0x0c064c10u: goto P_0c064c10;
case 0x0c064c12u: goto P_0c064c12;
case 0x0c064c14u: goto P_0c064c14;
case 0x0c064c16u: goto P_0c064c16;
case 0x0c064c18u: goto P_0c064c18;
case 0x0c064c1au: goto P_0c064c1a;
case 0x0c064c28u: goto P_0c064c28;
case 0x0c064c2au: goto P_0c064c2a;
case 0x0c064c2cu: goto P_0c064c2c;
case 0x0c064c2eu: goto P_0c064c2e;
case 0x0c064c30u: goto P_0c064c30;
case 0x0c064c32u: goto P_0c064c32;
case 0x0c064c34u: goto P_0c064c34;
case 0x0c064c36u: goto P_0c064c36;
case 0x0c064c38u: goto P_0c064c38;
case 0x0c064c3au: goto P_0c064c3a;
case 0x0c064c3cu: goto P_0c064c3c;
case 0x0c064c3eu: goto P_0c064c3e;
case 0x0c064c40u: goto P_0c064c40;
case 0x0c064c42u: goto P_0c064c42;
case 0x0c064c44u: goto P_0c064c44;
case 0x0c064c46u: goto P_0c064c46;
case 0x0c064c48u: goto P_0c064c48;
case 0x0c064c4au: goto P_0c064c4a;
case 0x0c064c4cu: goto P_0c064c4c;
case 0x0c064c4eu: goto P_0c064c4e;
case 0x0c064c50u: goto P_0c064c50;
case 0x0c064c52u: goto P_0c064c52;
case 0x0c064c54u: goto P_0c064c54;
case 0x0c064c56u: goto P_0c064c56;
case 0x0c064c58u: goto P_0c064c58;
case 0x0c064c5au: goto P_0c064c5a;
case 0x0c064c5cu: goto P_0c064c5c;
case 0x0c064c5eu: goto P_0c064c5e;
case 0x0c064c60u: goto P_0c064c60;
case 0x0c064c62u: goto P_0c064c62;
case 0x0c064c64u: goto P_0c064c64;
case 0x0c064c66u: goto P_0c064c66;
case 0x0c064c68u: goto P_0c064c68;
case 0x0c064c6au: goto P_0c064c6a;
case 0x0c064c6cu: goto P_0c064c6c;
case 0x0c064c6eu: goto P_0c064c6e;
case 0x0c064c70u: goto P_0c064c70;
case 0x0c064c72u: goto P_0c064c72;
case 0x0c064c74u: goto P_0c064c74;
case 0x0c064c76u: goto P_0c064c76;
case 0x0c064c78u: goto P_0c064c78;
case 0x0c064c7au: goto P_0c064c7a;
case 0x0c064c7cu: goto P_0c064c7c;
case 0x0c064c7eu: goto P_0c064c7e;
case 0x0c064c80u: goto P_0c064c80;
case 0x0c064c82u: goto P_0c064c82;
case 0x0c064c84u: goto P_0c064c84;
case 0x0c064c86u: goto P_0c064c86;
case 0x0c064c88u: goto P_0c064c88;
case 0x0c064c8au: goto P_0c064c8a;
case 0x0c064c8cu: goto P_0c064c8c;
case 0x0c064c8eu: goto P_0c064c8e;
case 0x0c064c90u: goto P_0c064c90;
case 0x0c064c92u: goto P_0c064c92;
case 0x0c064c94u: goto P_0c064c94;
case 0x0c064c96u: goto P_0c064c96;
case 0x0c064c98u: goto P_0c064c98;
case 0x0c064c9au: goto P_0c064c9a;
case 0x0c064c9cu: goto P_0c064c9c;
case 0x0c064c9eu: goto P_0c064c9e;
case 0x0c064ca0u: goto P_0c064ca0;
case 0x0c064ca2u: goto P_0c064ca2;
case 0x0c064ca4u: goto P_0c064ca4;
case 0x0c064ca6u: goto P_0c064ca6;
case 0x0c064ca8u: goto P_0c064ca8;
case 0x0c064caau: goto P_0c064caa;
case 0x0c064cacu: goto P_0c064cac;
case 0x0c064caeu: goto P_0c064cae;
case 0x0c064cb0u: goto P_0c064cb0;
case 0x0c064cb2u: goto P_0c064cb2;
case 0x0c064cb4u: goto P_0c064cb4;
case 0x0c064cb6u: goto P_0c064cb6;
case 0x0c064cb8u: goto P_0c064cb8;
case 0x0c064cbau: goto P_0c064cba;
case 0x0c064cbcu: goto P_0c064cbc;
case 0x0c064cbeu: goto P_0c064cbe;
case 0x0c064cc0u: goto P_0c064cc0;
case 0x0c064cc2u: goto P_0c064cc2;
case 0x0c064cc4u: goto P_0c064cc4;
case 0x0c064cc6u: goto P_0c064cc6;
case 0x0c064cc8u: goto P_0c064cc8;
case 0x0c064ccau: goto P_0c064cca;
case 0x0c064cccu: goto P_0c064ccc;
case 0x0c064cceu: goto P_0c064cce;
case 0x0c064cd0u: goto P_0c064cd0;
case 0x0c064cd2u: goto P_0c064cd2;
case 0x0c064cd4u: goto P_0c064cd4;
case 0x0c064cd6u: goto P_0c064cd6;
case 0x0c064cd8u: goto P_0c064cd8;
case 0x0c064cdau: goto P_0c064cda;
case 0x0c064cdcu: goto P_0c064cdc;
case 0x0c064cdeu: goto P_0c064cde;
case 0x0c064ce0u: goto P_0c064ce0;
case 0x0c064ce2u: goto P_0c064ce2;
case 0x0c064ce4u: goto P_0c064ce4;
case 0x0c064ce6u: goto P_0c064ce6;
case 0x0c064ce8u: goto P_0c064ce8;
case 0x0c064ceau: goto P_0c064cea;
case 0x0c064cecu: goto P_0c064cec;
case 0x0c064ceeu: goto P_0c064cee;
case 0x0c064cf0u: goto P_0c064cf0;
case 0x0c064cf2u: goto P_0c064cf2;
case 0x0c064cf4u: goto P_0c064cf4;
case 0x0c064cf6u: goto P_0c064cf6;
case 0x0c064cf8u: goto P_0c064cf8;
case 0x0c064cfau: goto P_0c064cfa;
case 0x0c064cfcu: goto P_0c064cfc;
case 0x0c064cfeu: goto P_0c064cfe;
case 0x0c064d00u: goto P_0c064d00;
case 0x0c064d02u: goto P_0c064d02;
case 0x0c064d04u: goto P_0c064d04;
case 0x0c064d06u: goto P_0c064d06;
case 0x0c064d08u: goto P_0c064d08;
case 0x0c064d0au: goto P_0c064d0a;
case 0x0c064d0cu: goto P_0c064d0c;
case 0x0c064d0eu: goto P_0c064d0e;
case 0x0c064d10u: goto P_0c064d10;
case 0x0c064d12u: goto P_0c064d12;
case 0x0c064d14u: goto P_0c064d14;
case 0x0c064d16u: goto P_0c064d16;
case 0x0c064d18u: goto P_0c064d18;
case 0x0c064d1au: goto P_0c064d1a;
case 0x0c064d1cu: goto P_0c064d1c;
case 0x0c064d1eu: goto P_0c064d1e;
case 0x0c064d20u: goto P_0c064d20;
case 0x0c064d22u: goto P_0c064d22;
case 0x0c064d24u: goto P_0c064d24;
case 0x0c064d26u: goto P_0c064d26;
case 0x0c064d28u: goto P_0c064d28;
case 0x0c064d2au: goto P_0c064d2a;
case 0x0c064d2cu: goto P_0c064d2c;
case 0x0c064d2eu: goto P_0c064d2e;
case 0x0c064d30u: goto P_0c064d30;
case 0x0c064d32u: goto P_0c064d32;
case 0x0c064d34u: goto P_0c064d34;
case 0x0c064d36u: goto P_0c064d36;
case 0x0c064d38u: goto P_0c064d38;
case 0x0c064d3au: goto P_0c064d3a;
case 0x0c064d3cu: goto P_0c064d3c;
case 0x0c064d3eu: goto P_0c064d3e;
case 0x0c064d40u: goto P_0c064d40;
case 0x0c064d42u: goto P_0c064d42;
case 0x0c064d44u: goto P_0c064d44;
case 0x0c064d46u: goto P_0c064d46;
case 0x0c064d48u: goto P_0c064d48;
case 0x0c064d4au: goto P_0c064d4a;
case 0x0c064d4cu: goto P_0c064d4c;
case 0x0c064d4eu: goto P_0c064d4e;
case 0x0c064d50u: goto P_0c064d50;
case 0x0c064d52u: goto P_0c064d52;
case 0x0c064d54u: goto P_0c064d54;
case 0x0c064d56u: goto P_0c064d56;
case 0x0c064d58u: goto P_0c064d58;
case 0x0c064d5au: goto P_0c064d5a;
case 0x0c064d5cu: goto P_0c064d5c;
case 0x0c064d5eu: goto P_0c064d5e;
case 0x0c064d60u: goto P_0c064d60;
case 0x0c064d62u: goto P_0c064d62;
case 0x0c064d64u: goto P_0c064d64;
case 0x0c064d66u: goto P_0c064d66;
case 0x0c064d68u: goto P_0c064d68;
case 0x0c064d6au: goto P_0c064d6a;
case 0x0c064d6cu: goto P_0c064d6c;
case 0x0c064d6eu: goto P_0c064d6e;
case 0x0c064d70u: goto P_0c064d70;
case 0x0c064d72u: goto P_0c064d72;
case 0x0c064d74u: goto P_0c064d74;
case 0x0c064d76u: goto P_0c064d76;
case 0x0c064da0u: goto P_0c064da0;
case 0x0c064da2u: goto P_0c064da2;
case 0x0c064da4u: goto P_0c064da4;
case 0x0c064da6u: goto P_0c064da6;
case 0x0c064da8u: goto P_0c064da8;
case 0x0c064daau: goto P_0c064daa;
case 0x0c064dacu: goto P_0c064dac;
case 0x0c064daeu: goto P_0c064dae;
case 0x0c064db0u: goto P_0c064db0;
case 0x0c064db2u: goto P_0c064db2;
case 0x0c064db4u: goto P_0c064db4;
case 0x0c064db6u: goto P_0c064db6;
case 0x0c064db8u: goto P_0c064db8;
case 0x0c064dbau: goto P_0c064dba;
case 0x0c064dbcu: goto P_0c064dbc;
case 0x0c064dbeu: goto P_0c064dbe;
case 0x0c064dc0u: goto P_0c064dc0;
case 0x0c064dc2u: goto P_0c064dc2;
case 0x0c064dc4u: goto P_0c064dc4;
case 0x0c064dc6u: goto P_0c064dc6;
case 0x0c064dc8u: goto P_0c064dc8;
case 0x0c064dcau: goto P_0c064dca;
case 0x0c064dccu: goto P_0c064dcc;
case 0x0c064dceu: goto P_0c064dce;
case 0x0c064dd0u: goto P_0c064dd0;
case 0x0c064dd2u: goto P_0c064dd2;
case 0x0c064dd4u: goto P_0c064dd4;
case 0x0c064dd6u: goto P_0c064dd6;
case 0x0c064dd8u: goto P_0c064dd8;
case 0x0c064ddau: goto P_0c064dda;
case 0x0c064ddcu: goto P_0c064ddc;
case 0x0c064ddeu: goto P_0c064dde;
case 0x0c064de0u: goto P_0c064de0;
case 0x0c064de2u: goto P_0c064de2;
case 0x0c064de4u: goto P_0c064de4;
case 0x0c064de6u: goto P_0c064de6;
case 0x0c064de8u: goto P_0c064de8;
case 0x0c064deau: goto P_0c064dea;
case 0x0c064decu: goto P_0c064dec;
case 0x0c064deeu: goto P_0c064dee;
case 0x0c064df0u: goto P_0c064df0;
case 0x0c064df2u: goto P_0c064df2;
case 0x0c064df4u: goto P_0c064df4;
case 0x0c064df6u: goto P_0c064df6;
case 0x0c064df8u: goto P_0c064df8;
case 0x0c064dfau: goto P_0c064dfa;
case 0x0c064dfcu: goto P_0c064dfc;
case 0x0c064dfeu: goto P_0c064dfe;
case 0x0c064e00u: goto P_0c064e00;
case 0x0c064e02u: goto P_0c064e02;
case 0x0c064e04u: goto P_0c064e04;
case 0x0c064e06u: goto P_0c064e06;
case 0x0c064e08u: goto P_0c064e08;
case 0x0c064e0au: goto P_0c064e0a;
case 0x0c064e0cu: goto P_0c064e0c;
case 0x0c064e0eu: goto P_0c064e0e;
case 0x0c064e10u: goto P_0c064e10;
case 0x0c064e12u: goto P_0c064e12;
case 0x0c064e14u: goto P_0c064e14;
case 0x0c064e16u: goto P_0c064e16;
case 0x0c064e18u: goto P_0c064e18;
case 0x0c064e1au: goto P_0c064e1a;
case 0x0c064e1cu: goto P_0c064e1c;
case 0x0c064e1eu: goto P_0c064e1e;
case 0x0c064e20u: goto P_0c064e20;
case 0x0c064e22u: goto P_0c064e22;
case 0x0c064e24u: goto P_0c064e24;
case 0x0c064e26u: goto P_0c064e26;
case 0x0c064e28u: goto P_0c064e28;
case 0x0c064e2au: goto P_0c064e2a;
case 0x0c064e2cu: goto P_0c064e2c;
case 0x0c064e2eu: goto P_0c064e2e;
case 0x0c064e30u: goto P_0c064e30;
case 0x0c064e32u: goto P_0c064e32;
case 0x0c064e34u: goto P_0c064e34;
case 0x0c064e36u: goto P_0c064e36;
case 0x0c064e38u: goto P_0c064e38;
case 0x0c064e3au: goto P_0c064e3a;
case 0x0c064e3cu: goto P_0c064e3c;
case 0x0c064e3eu: goto P_0c064e3e;
case 0x0c064e40u: goto P_0c064e40;
case 0x0c064e42u: goto P_0c064e42;
case 0x0c064e44u: goto P_0c064e44;
case 0x0c064e46u: goto P_0c064e46;
case 0x0c064e48u: goto P_0c064e48;
case 0x0c064e4au: goto P_0c064e4a;
case 0x0c064e4cu: goto P_0c064e4c;
case 0x0c064e4eu: goto P_0c064e4e;
case 0x0c064e50u: goto P_0c064e50;
case 0x0c064e52u: goto P_0c064e52;
case 0x0c064e54u: goto P_0c064e54;
case 0x0c064e56u: goto P_0c064e56;
case 0x0c064e58u: goto P_0c064e58;
case 0x0c064e5au: goto P_0c064e5a;
case 0x0c064e5cu: goto P_0c064e5c;
case 0x0c064e5eu: goto P_0c064e5e;
case 0x0c064e60u: goto P_0c064e60;
case 0x0c064e62u: goto P_0c064e62;
case 0x0c064e64u: goto P_0c064e64;
case 0x0c064e66u: goto P_0c064e66;
case 0x0c064e68u: goto P_0c064e68;
case 0x0c064e6au: goto P_0c064e6a;
case 0x0c064e6cu: goto P_0c064e6c;
case 0x0c064e6eu: goto P_0c064e6e;
case 0x0c064e70u: goto P_0c064e70;
case 0x0c064e72u: goto P_0c064e72;
case 0x0c064e74u: goto P_0c064e74;
case 0x0c064e76u: goto P_0c064e76;
case 0x0c064e78u: goto P_0c064e78;
case 0x0c064e7au: goto P_0c064e7a;
case 0x0c064e7cu: goto P_0c064e7c;
case 0x0c064e7eu: goto P_0c064e7e;
case 0x0c064e80u: goto P_0c064e80;
case 0x0c064e82u: goto P_0c064e82;
case 0x0c064e84u: goto P_0c064e84;
case 0x0c064e86u: goto P_0c064e86;
case 0x0c064e88u: goto P_0c064e88;
case 0x0c064e8au: goto P_0c064e8a;
case 0x0c064e8cu: goto P_0c064e8c;
case 0x0c064e8eu: goto P_0c064e8e;
case 0x0c064e90u: goto P_0c064e90;
case 0x0c064e92u: goto P_0c064e92;
case 0x0c064e94u: goto P_0c064e94;
case 0x0c064e96u: goto P_0c064e96;
case 0x0c064e98u: goto P_0c064e98;
case 0x0c064e9au: goto P_0c064e9a;
case 0x0c064e9cu: goto P_0c064e9c;
case 0x0c064e9eu: goto P_0c064e9e;
case 0x0c064ea0u: goto P_0c064ea0;
case 0x0c064ea2u: goto P_0c064ea2;
case 0x0c064ea4u: goto P_0c064ea4;
case 0x0c064ea6u: goto P_0c064ea6;
case 0x0c064ea8u: goto P_0c064ea8;
case 0x0c064eaau: goto P_0c064eaa;
case 0x0c064eacu: goto P_0c064eac;
case 0x0c064eaeu: goto P_0c064eae;
case 0x0c064eb0u: goto P_0c064eb0;
case 0x0c064eb2u: goto P_0c064eb2;
case 0x0c064eb4u: goto P_0c064eb4;
case 0x0c064eb6u: goto P_0c064eb6;
case 0x0c064eb8u: goto P_0c064eb8;
case 0x0c064ebau: goto P_0c064eba;
case 0x0c064ebcu: goto P_0c064ebc;
case 0x0c064ebeu: goto P_0c064ebe;
case 0x0c064ec0u: goto P_0c064ec0;
case 0x0c064ec2u: goto P_0c064ec2;
case 0x0c064ec4u: goto P_0c064ec4;
case 0x0c064ec6u: goto P_0c064ec6;
case 0x0c064ec8u: goto P_0c064ec8;
case 0x0c064ecau: goto P_0c064eca;
case 0x0c064eccu: goto P_0c064ecc;
case 0x0c064eceu: goto P_0c064ece;
case 0x0c064ed0u: goto P_0c064ed0;
case 0x0c064ed2u: goto P_0c064ed2;
case 0x0c064ed4u: goto P_0c064ed4;
case 0x0c064ed6u: goto P_0c064ed6;
case 0x0c064ed8u: goto P_0c064ed8;
case 0x0c064edau: goto P_0c064eda;
case 0x0c064edcu: goto P_0c064edc;
case 0x0c064edeu: goto P_0c064ede;
case 0x0c064ee0u: goto P_0c064ee0;
case 0x0c064ee2u: goto P_0c064ee2;
case 0x0c064ee4u: goto P_0c064ee4;
case 0x0c064ee6u: goto P_0c064ee6;
case 0x0c064ee8u: goto P_0c064ee8;
case 0x0c064eeau: goto P_0c064eea;
case 0x0c064eecu: goto P_0c064eec;
case 0x0c064eeeu: goto P_0c064eee;
case 0x0c064ef0u: goto P_0c064ef0;
case 0x0c064ef2u: goto P_0c064ef2;
case 0x0c064ef4u: goto P_0c064ef4;
case 0x0c064ef6u: goto P_0c064ef6;
case 0x0c064ef8u: goto P_0c064ef8;
case 0x0c064efau: goto P_0c064efa;
case 0x0c064efcu: goto P_0c064efc;
case 0x0c064efeu: goto P_0c064efe;
case 0x0c064f00u: goto P_0c064f00;
case 0x0c064f02u: goto P_0c064f02;
case 0x0c064f04u: goto P_0c064f04;
case 0x0c064f06u: goto P_0c064f06;
case 0x0c064f08u: goto P_0c064f08;
case 0x0c064f0au: goto P_0c064f0a;
case 0x0c064f0cu: goto P_0c064f0c;
case 0x0c064f0eu: goto P_0c064f0e;
case 0x0c064f10u: goto P_0c064f10;
case 0x0c064f12u: goto P_0c064f12;
case 0x0c064f14u: goto P_0c064f14;
case 0x0c064f16u: goto P_0c064f16;
case 0x0c064f18u: goto P_0c064f18;
case 0x0c064f1au: goto P_0c064f1a;
case 0x0c064f1cu: goto P_0c064f1c;
case 0x0c064f1eu: goto P_0c064f1e;
case 0x0c064f20u: goto P_0c064f20;
case 0x0c064f22u: goto P_0c064f22;
case 0x0c064f24u: goto P_0c064f24;
case 0x0c064f26u: goto P_0c064f26;
case 0x0c064f28u: goto P_0c064f28;
case 0x0c064f2au: goto P_0c064f2a;
case 0x0c064f2cu: goto P_0c064f2c;
case 0x0c064f2eu: goto P_0c064f2e;
case 0x0c064f30u: goto P_0c064f30;
case 0x0c064f32u: goto P_0c064f32;
case 0x0c064f34u: goto P_0c064f34;
case 0x0c064f36u: goto P_0c064f36;
case 0x0c064f38u: goto P_0c064f38;
case 0x0c064f3au: goto P_0c064f3a;
case 0x0c064f3cu: goto P_0c064f3c;
case 0x0c064f3eu: goto P_0c064f3e;
case 0x0c064f40u: goto P_0c064f40;
case 0x0c064f42u: goto P_0c064f42;
case 0x0c064f44u: goto P_0c064f44;
case 0x0c064f46u: goto P_0c064f46;
case 0x0c064f48u: goto P_0c064f48;
case 0x0c064f4au: goto P_0c064f4a;
case 0x0c064f4cu: goto P_0c064f4c;
case 0x0c064f4eu: goto P_0c064f4e;
case 0x0c064f50u: goto P_0c064f50;
case 0x0c064f52u: goto P_0c064f52;
case 0x0c064f54u: goto P_0c064f54;
case 0x0c064f56u: goto P_0c064f56;
case 0x0c064f58u: goto P_0c064f58;
case 0x0c064f5au: goto P_0c064f5a;
case 0x0c064f5cu: goto P_0c064f5c;
case 0x0c064f5eu: goto P_0c064f5e;
case 0x0c064f60u: goto P_0c064f60;
case 0x0c064f62u: goto P_0c064f62;
case 0x0c064f64u: goto P_0c064f64;
case 0x0c064f66u: goto P_0c064f66;
case 0x0c064f68u: goto P_0c064f68;
case 0x0c064f6au: goto P_0c064f6a;
case 0x0c064f6cu: goto P_0c064f6c;
case 0x0c064f6eu: goto P_0c064f6e;
case 0x0c064f70u: goto P_0c064f70;
case 0x0c064f72u: goto P_0c064f72;
case 0x0c064f74u: goto P_0c064f74;
case 0x0c064f76u: goto P_0c064f76;
case 0x0c064f78u: goto P_0c064f78;
case 0x0c064f7au: goto P_0c064f7a;
case 0x0c064f7cu: goto P_0c064f7c;
case 0x0c064f7eu: goto P_0c064f7e;
case 0x0c064f80u: goto P_0c064f80;
case 0x0c064f82u: goto P_0c064f82;
case 0x0c064f84u: goto P_0c064f84;
case 0x0c064f86u: goto P_0c064f86;
case 0x0c064f88u: goto P_0c064f88;
case 0x0c064f8au: goto P_0c064f8a;
case 0x0c064f8cu: goto P_0c064f8c;
case 0x0c064f8eu: goto P_0c064f8e;
case 0x0c064f90u: goto P_0c064f90;
case 0x0c064f92u: goto P_0c064f92;
case 0x0c064f94u: goto P_0c064f94;
case 0x0c064f96u: goto P_0c064f96;
case 0x0c064f98u: goto P_0c064f98;
case 0x0c064f9au: goto P_0c064f9a;
case 0x0c064f9cu: goto P_0c064f9c;
case 0x0c064f9eu: goto P_0c064f9e;
case 0x0c064fa0u: goto P_0c064fa0;
case 0x0c064fa2u: goto P_0c064fa2;
case 0x0c064fa4u: goto P_0c064fa4;
case 0x0c064fa6u: goto P_0c064fa6;
case 0x0c064fa8u: goto P_0c064fa8;
case 0x0c064faau: goto P_0c064faa;
case 0x0c064facu: goto P_0c064fac;
case 0x0c064faeu: goto P_0c064fae;
case 0x0c064fb0u: goto P_0c064fb0;
case 0x0c064fb2u: goto P_0c064fb2;
case 0x0c064fb4u: goto P_0c064fb4;
case 0x0c064fb6u: goto P_0c064fb6;
case 0x0c064fb8u: goto P_0c064fb8;
case 0x0c064fbau: goto P_0c064fba;
case 0x0c064fbcu: goto P_0c064fbc;
case 0x0c064fbeu: goto P_0c064fbe;
case 0x0c064fc0u: goto P_0c064fc0;
case 0x0c064fc2u: goto P_0c064fc2;
case 0x0c064fc4u: goto P_0c064fc4;
case 0x0c064fc6u: goto P_0c064fc6;
case 0x0c064fc8u: goto P_0c064fc8;
case 0x0c064fcau: goto P_0c064fca;
case 0x0c064fccu: goto P_0c064fcc;
case 0x0c064fceu: goto P_0c064fce;
case 0x0c064fd0u: goto P_0c064fd0;
case 0x0c064fd2u: goto P_0c064fd2;
case 0x0c064fd4u: goto P_0c064fd4;
case 0x0c064fd6u: goto P_0c064fd6;
case 0x0c064fd8u: goto P_0c064fd8;
case 0x0c064fdau: goto P_0c064fda;
case 0x0c064fdcu: goto P_0c064fdc;
case 0x0c064fdeu: goto P_0c064fde;
case 0x0c064fe0u: goto P_0c064fe0;
case 0x0c064fe2u: goto P_0c064fe2;
case 0x0c064fe4u: goto P_0c064fe4;
case 0x0c064fe6u: goto P_0c064fe6;
case 0x0c064fe8u: goto P_0c064fe8;
case 0x0c064feau: goto P_0c064fea;
case 0x0c064fecu: goto P_0c064fec;
case 0x0c064feeu: goto P_0c064fee;
case 0x0c064ff0u: goto P_0c064ff0;
case 0x0c064ff2u: goto P_0c064ff2;
case 0x0c064ff4u: goto P_0c064ff4;
case 0x0c064ff6u: goto P_0c064ff6;
case 0x0c064ff8u: goto P_0c064ff8;
case 0x0c064ffau: goto P_0c064ffa;
case 0x0c064ffcu: goto P_0c064ffc;
case 0x0c064ffeu: goto P_0c064ffe;
case 0x0c065000u: goto P_0c065000;
case 0x0c065002u: goto P_0c065002;
case 0x0c065004u: goto P_0c065004;
case 0x0c065006u: goto P_0c065006;
case 0x0c065008u: goto P_0c065008;
case 0x0c06500au: goto P_0c06500a;
case 0x0c06500cu: goto P_0c06500c;
case 0x0c06500eu: goto P_0c06500e;
case 0x0c065010u: goto P_0c065010;
case 0x0c065012u: goto P_0c065012;
case 0x0c065014u: goto P_0c065014;
case 0x0c065016u: goto P_0c065016;
case 0x0c065018u: goto P_0c065018;
case 0x0c06501au: goto P_0c06501a;
case 0x0c06501cu: goto P_0c06501c;
case 0x0c06501eu: goto P_0c06501e;
case 0x0c065020u: goto P_0c065020;
case 0x0c065022u: goto P_0c065022;
case 0x0c065024u: goto P_0c065024;
case 0x0c065026u: goto P_0c065026;
case 0x0c065028u: goto P_0c065028;
case 0x0c06502au: goto P_0c06502a;
case 0x0c06502cu: goto P_0c06502c;
case 0x0c06502eu: goto P_0c06502e;
case 0x0c065030u: goto P_0c065030;
case 0x0c065032u: goto P_0c065032;
case 0x0c065034u: goto P_0c065034;
case 0x0c065036u: goto P_0c065036;
case 0x0c065038u: goto P_0c065038;
case 0x0c06503au: goto P_0c06503a;
case 0x0c06503cu: goto P_0c06503c;
case 0x0c06503eu: goto P_0c06503e;
case 0x0c065040u: goto P_0c065040;
case 0x0c065042u: goto P_0c065042;
case 0x0c065044u: goto P_0c065044;
case 0x0c065046u: goto P_0c065046;
case 0x0c065048u: goto P_0c065048;
case 0x0c06504au: goto P_0c06504a;
case 0x0c06504cu: goto P_0c06504c;
case 0x0c06504eu: goto P_0c06504e;
case 0x0c065050u: goto P_0c065050;
case 0x0c065052u: goto P_0c065052;
case 0x0c065054u: goto P_0c065054;
case 0x0c065056u: goto P_0c065056;
case 0x0c065058u: goto P_0c065058;
case 0x0c06505au: goto P_0c06505a;
case 0x0c065088u: goto P_0c065088;
case 0x0c06508au: goto P_0c06508a;
case 0x0c06508cu: goto P_0c06508c;
case 0x0c06508eu: goto P_0c06508e;
case 0x0c065090u: goto P_0c065090;
case 0x0c065092u: goto P_0c065092;
case 0x0c065094u: goto P_0c065094;
case 0x0c065096u: goto P_0c065096;
case 0x0c065098u: goto P_0c065098;
case 0x0c06509au: goto P_0c06509a;
case 0x0c06509cu: goto P_0c06509c;
case 0x0c06509eu: goto P_0c06509e;
case 0x0c0650a0u: goto P_0c0650a0;
case 0x0c0650a2u: goto P_0c0650a2;
case 0x0c0650a4u: goto P_0c0650a4;
case 0x0c0650a6u: goto P_0c0650a6;
case 0x0c0650a8u: goto P_0c0650a8;
case 0x0c0650aau: goto P_0c0650aa;
case 0x0c0650acu: goto P_0c0650ac;
case 0x0c0650aeu: goto P_0c0650ae;
case 0x0c0650b0u: goto P_0c0650b0;
case 0x0c0650b2u: goto P_0c0650b2;
case 0x0c0650b4u: goto P_0c0650b4;
case 0x0c0650b6u: goto P_0c0650b6;
case 0x0c0650b8u: goto P_0c0650b8;
case 0x0c0650bau: goto P_0c0650ba;
case 0x0c0650bcu: goto P_0c0650bc;
case 0x0c0650beu: goto P_0c0650be;
case 0x0c0650c0u: goto P_0c0650c0;
case 0x0c0650c2u: goto P_0c0650c2;
case 0x0c0650c4u: goto P_0c0650c4;
case 0x0c0650c6u: goto P_0c0650c6;
case 0x0c0650c8u: goto P_0c0650c8;
case 0x0c0650cau: goto P_0c0650ca;
case 0x0c0650ccu: goto P_0c0650cc;
case 0x0c0650ceu: goto P_0c0650ce;
case 0x0c0650d0u: goto P_0c0650d0;
case 0x0c0650d2u: goto P_0c0650d2;
case 0x0c0650d4u: goto P_0c0650d4;
case 0x0c0650d6u: goto P_0c0650d6;
case 0x0c0650d8u: goto P_0c0650d8;
case 0x0c0650dau: goto P_0c0650da;
case 0x0c0650dcu: goto P_0c0650dc;
case 0x0c0650deu: goto P_0c0650de;
case 0x0c0650e0u: goto P_0c0650e0;
case 0x0c0650e2u: goto P_0c0650e2;
case 0x0c0650e4u: goto P_0c0650e4;
case 0x0c0650e6u: goto P_0c0650e6;
case 0x0c0650e8u: goto P_0c0650e8;
case 0x0c0650eau: goto P_0c0650ea;
case 0x0c0650ecu: goto P_0c0650ec;
case 0x0c0650eeu: goto P_0c0650ee;
case 0x0c0650f0u: goto P_0c0650f0;
case 0x0c0650f2u: goto P_0c0650f2;
case 0x0c0650f4u: goto P_0c0650f4;
case 0x0c0650f6u: goto P_0c0650f6;
case 0x0c0650f8u: goto P_0c0650f8;
case 0x0c0650fau: goto P_0c0650fa;
case 0x0c0650fcu: goto P_0c0650fc;
case 0x0c0650feu: goto P_0c0650fe;
case 0x0c065100u: goto P_0c065100;
case 0x0c065102u: goto P_0c065102;
case 0x0c065104u: goto P_0c065104;
case 0x0c065106u: goto P_0c065106;
case 0x0c065108u: goto P_0c065108;
case 0x0c06510au: goto P_0c06510a;
case 0x0c06510cu: goto P_0c06510c;
case 0x0c06510eu: goto P_0c06510e;
case 0x0c065110u: goto P_0c065110;
case 0x0c065112u: goto P_0c065112;
case 0x0c065114u: goto P_0c065114;
case 0x0c065116u: goto P_0c065116;
case 0x0c065118u: goto P_0c065118;
case 0x0c06511au: goto P_0c06511a;
case 0x0c06511cu: goto P_0c06511c;
case 0x0c06511eu: goto P_0c06511e;
case 0x0c065120u: goto P_0c065120;
case 0x0c065122u: goto P_0c065122;
case 0x0c065124u: goto P_0c065124;
case 0x0c065126u: goto P_0c065126;
case 0x0c065128u: goto P_0c065128;
case 0x0c06512au: goto P_0c06512a;
case 0x0c06512cu: goto P_0c06512c;
case 0x0c06512eu: goto P_0c06512e;
case 0x0c065130u: goto P_0c065130;
case 0x0c065132u: goto P_0c065132;
case 0x0c065134u: goto P_0c065134;
case 0x0c065136u: goto P_0c065136;
case 0x0c065138u: goto P_0c065138;
case 0x0c06513au: goto P_0c06513a;
case 0x0c06513cu: goto P_0c06513c;
case 0x0c06513eu: goto P_0c06513e;
case 0x0c065140u: goto P_0c065140;
case 0x0c065142u: goto P_0c065142;
case 0x0c065144u: goto P_0c065144;
case 0x0c065146u: goto P_0c065146;
case 0x0c065148u: goto P_0c065148;
case 0x0c06514au: goto P_0c06514a;
case 0x0c06514cu: goto P_0c06514c;
case 0x0c06514eu: goto P_0c06514e;
case 0x0c065150u: goto P_0c065150;
case 0x0c065152u: goto P_0c065152;
case 0x0c065154u: goto P_0c065154;
case 0x0c065156u: goto P_0c065156;
case 0x0c065158u: goto P_0c065158;
case 0x0c06515au: goto P_0c06515a;
case 0x0c06515cu: goto P_0c06515c;
case 0x0c06515eu: goto P_0c06515e;
case 0x0c065160u: goto P_0c065160;
case 0x0c065162u: goto P_0c065162;
case 0x0c065164u: goto P_0c065164;
case 0x0c065166u: goto P_0c065166;
case 0x0c065168u: goto P_0c065168;
case 0x0c06516au: goto P_0c06516a;
case 0x0c06516cu: goto P_0c06516c;
case 0x0c06516eu: goto P_0c06516e;
case 0x0c065170u: goto P_0c065170;
case 0x0c065172u: goto P_0c065172;
case 0x0c065174u: goto P_0c065174;
case 0x0c065176u: goto P_0c065176;
case 0x0c065178u: goto P_0c065178;
case 0x0c06517au: goto P_0c06517a;
case 0x0c06517cu: goto P_0c06517c;
case 0x0c06517eu: goto P_0c06517e;
case 0x0c065180u: goto P_0c065180;
case 0x0c065182u: goto P_0c065182;
case 0x0c065184u: goto P_0c065184;
case 0x0c065186u: goto P_0c065186;
case 0x0c065188u: goto P_0c065188;
case 0x0c06518au: goto P_0c06518a;
case 0x0c06518cu: goto P_0c06518c;
case 0x0c06518eu: goto P_0c06518e;
case 0x0c065190u: goto P_0c065190;
case 0x0c065192u: goto P_0c065192;
case 0x0c065194u: goto P_0c065194;
case 0x0c065196u: goto P_0c065196;
case 0x0c065198u: goto P_0c065198;
case 0x0c06519au: goto P_0c06519a;
case 0x0c06519cu: goto P_0c06519c;
case 0x0c06519eu: goto P_0c06519e;
case 0x0c0651a0u: goto P_0c0651a0;
case 0x0c0651a2u: goto P_0c0651a2;
case 0x0c0651a4u: goto P_0c0651a4;
case 0x0c0651a6u: goto P_0c0651a6;
case 0x0c0651a8u: goto P_0c0651a8;
case 0x0c0651aau: goto P_0c0651aa;
case 0x0c0651acu: goto P_0c0651ac;
case 0x0c0651aeu: goto P_0c0651ae;
case 0x0c0651b0u: goto P_0c0651b0;
case 0x0c0651b2u: goto P_0c0651b2;
case 0x0c0651b4u: goto P_0c0651b4;
case 0x0c0651b6u: goto P_0c0651b6;
case 0x0c0651b8u: goto P_0c0651b8;
case 0x0c0651bau: goto P_0c0651ba;
case 0x0c0651bcu: goto P_0c0651bc;
case 0x0c0651beu: goto P_0c0651be;
case 0x0c0651c0u: goto P_0c0651c0;
case 0x0c0651c2u: goto P_0c0651c2;
case 0x0c0651c4u: goto P_0c0651c4;
case 0x0c0651c6u: goto P_0c0651c6;
case 0x0c0651c8u: goto P_0c0651c8;
case 0x0c0651cau: goto P_0c0651ca;
case 0x0c0651ccu: goto P_0c0651cc;
case 0x0c0651ceu: goto P_0c0651ce;
case 0x0c0651d0u: goto P_0c0651d0;
case 0x0c0651d2u: goto P_0c0651d2;
case 0x0c0651d4u: goto P_0c0651d4;
case 0x0c0651d6u: goto P_0c0651d6;
case 0x0c0651d8u: goto P_0c0651d8;
case 0x0c0651dau: goto P_0c0651da;
case 0x0c0651dcu: goto P_0c0651dc;
case 0x0c0651deu: goto P_0c0651de;
case 0x0c0651e0u: goto P_0c0651e0;
case 0x0c0651e2u: goto P_0c0651e2;
case 0x0c0651e4u: goto P_0c0651e4;
case 0x0c0651e6u: goto P_0c0651e6;
case 0x0c0651e8u: goto P_0c0651e8;
case 0x0c0651eau: goto P_0c0651ea;
case 0x0c0651ecu: goto P_0c0651ec;
case 0x0c0651eeu: goto P_0c0651ee;
case 0x0c0651f0u: goto P_0c0651f0;
case 0x0c0651f2u: goto P_0c0651f2;
case 0x0c0651f4u: goto P_0c0651f4;
case 0x0c0651f6u: goto P_0c0651f6;
case 0x0c0651f8u: goto P_0c0651f8;
case 0x0c0651fau: goto P_0c0651fa;
case 0x0c0651fcu: goto P_0c0651fc;
case 0x0c0651feu: goto P_0c0651fe;
case 0x0c065200u: goto P_0c065200;
case 0x0c065202u: goto P_0c065202;
case 0x0c065204u: goto P_0c065204;
case 0x0c065206u: goto P_0c065206;
case 0x0c065208u: goto P_0c065208;
case 0x0c06520au: goto P_0c06520a;
case 0x0c06520cu: goto P_0c06520c;
case 0x0c06520eu: goto P_0c06520e;
case 0x0c065210u: goto P_0c065210;
case 0x0c065212u: goto P_0c065212;
case 0x0c065214u: goto P_0c065214;
case 0x0c065216u: goto P_0c065216;
case 0x0c065218u: goto P_0c065218;
case 0x0c06521au: goto P_0c06521a;
case 0x0c06521cu: goto P_0c06521c;
case 0x0c06521eu: goto P_0c06521e;
case 0x0c065220u: goto P_0c065220;
case 0x0c065222u: goto P_0c065222;
case 0x0c065224u: goto P_0c065224;
case 0x0c065226u: goto P_0c065226;
case 0x0c065228u: goto P_0c065228;
case 0x0c06522au: goto P_0c06522a;
case 0x0c06522cu: goto P_0c06522c;
case 0x0c06522eu: goto P_0c06522e;
case 0x0c065230u: goto P_0c065230;
case 0x0c065232u: goto P_0c065232;
case 0x0c065234u: goto P_0c065234;
case 0x0c065236u: goto P_0c065236;
case 0x0c065238u: goto P_0c065238;
case 0x0c06523au: goto P_0c06523a;
case 0x0c06523cu: goto P_0c06523c;
case 0x0c06523eu: goto P_0c06523e;
case 0x0c065240u: goto P_0c065240;
case 0x0c065242u: goto P_0c065242;
case 0x0c065244u: goto P_0c065244;
case 0x0c065246u: goto P_0c065246;
case 0x0c065248u: goto P_0c065248;
case 0x0c06524au: goto P_0c06524a;
case 0x0c06524cu: goto P_0c06524c;
case 0x0c06524eu: goto P_0c06524e;
case 0x0c065250u: goto P_0c065250;
case 0x0c065252u: goto P_0c065252;
case 0x0c065254u: goto P_0c065254;
case 0x0c065256u: goto P_0c065256;
case 0x0c065258u: goto P_0c065258;
case 0x0c06525au: goto P_0c06525a;
case 0x0c06525cu: goto P_0c06525c;
case 0x0c06525eu: goto P_0c06525e;
case 0x0c065260u: goto P_0c065260;
case 0x0c065262u: goto P_0c065262;
case 0x0c065264u: goto P_0c065264;
case 0x0c065266u: goto P_0c065266;
case 0x0c065268u: goto P_0c065268;
case 0x0c06526au: goto P_0c06526a;
case 0x0c06526cu: goto P_0c06526c;
case 0x0c06526eu: goto P_0c06526e;
case 0x0c065270u: goto P_0c065270;
case 0x0c065272u: goto P_0c065272;
case 0x0c065274u: goto P_0c065274;
case 0x0c065276u: goto P_0c065276;
case 0x0c065278u: goto P_0c065278;
case 0x0c06527au: goto P_0c06527a;
case 0x0c06527cu: goto P_0c06527c;
case 0x0c06527eu: goto P_0c06527e;
case 0x0c065280u: goto P_0c065280;
case 0x0c065282u: goto P_0c065282;
case 0x0c065284u: goto P_0c065284;
case 0x0c065286u: goto P_0c065286;
case 0x0c065288u: goto P_0c065288;
case 0x0c06528au: goto P_0c06528a;
case 0x0c06528cu: goto P_0c06528c;
case 0x0c06528eu: goto P_0c06528e;
case 0x0c065290u: goto P_0c065290;
case 0x0c065292u: goto P_0c065292;
case 0x0c065294u: goto P_0c065294;
case 0x0c065296u: goto P_0c065296;
case 0x0c065298u: goto P_0c065298;
case 0x0c06529au: goto P_0c06529a;
case 0x0c06529cu: goto P_0c06529c;
case 0x0c06529eu: goto P_0c06529e;
case 0x0c0652a0u: goto P_0c0652a0;
case 0x0c0652a2u: goto P_0c0652a2;
case 0x0c0652a4u: goto P_0c0652a4;
case 0x0c0652a6u: goto P_0c0652a6;
case 0x0c0652a8u: goto P_0c0652a8;
case 0x0c0652aau: goto P_0c0652aa;
case 0x0c0652acu: goto P_0c0652ac;
case 0x0c0652aeu: goto P_0c0652ae;
case 0x0c0652b0u: goto P_0c0652b0;
case 0x0c0652b2u: goto P_0c0652b2;
case 0x0c0652b4u: goto P_0c0652b4;
case 0x0c0652b6u: goto P_0c0652b6;
case 0x0c0652b8u: goto P_0c0652b8;
case 0x0c0652bau: goto P_0c0652ba;
case 0x0c0652bcu: goto P_0c0652bc;
case 0x0c0652beu: goto P_0c0652be;
case 0x0c0652c0u: goto P_0c0652c0;
case 0x0c0652c2u: goto P_0c0652c2;
case 0x0c0652c4u: goto P_0c0652c4;
case 0x0c0652c6u: goto P_0c0652c6;
case 0x0c0652c8u: goto P_0c0652c8;
case 0x0c0652cau: goto P_0c0652ca;
case 0x0c0652ccu: goto P_0c0652cc;
case 0x0c0652ceu: goto P_0c0652ce;
case 0x0c0652d0u: goto P_0c0652d0;
case 0x0c0652d2u: goto P_0c0652d2;
case 0x0c0652d4u: goto P_0c0652d4;
case 0x0c0652d6u: goto P_0c0652d6;
case 0x0c0652d8u: goto P_0c0652d8;
case 0x0c0652dau: goto P_0c0652da;
case 0x0c0652dcu: goto P_0c0652dc;
case 0x0c0652deu: goto P_0c0652de;
case 0x0c0652e0u: goto P_0c0652e0;
case 0x0c0652e2u: goto P_0c0652e2;
case 0x0c0652e4u: goto P_0c0652e4;
case 0x0c0652e6u: goto P_0c0652e6;
case 0x0c0652e8u: goto P_0c0652e8;
case 0x0c0652eau: goto P_0c0652ea;
case 0x0c0652ecu: goto P_0c0652ec;
case 0x0c0652eeu: goto P_0c0652ee;
case 0x0c0652f0u: goto P_0c0652f0;
case 0x0c0652f2u: goto P_0c0652f2;
case 0x0c0652f4u: goto P_0c0652f4;
case 0x0c0652f6u: goto P_0c0652f6;
case 0x0c0652f8u: goto P_0c0652f8;
case 0x0c0652fau: goto P_0c0652fa;
case 0x0c0652fcu: goto P_0c0652fc;
case 0x0c0652feu: goto P_0c0652fe;
case 0x0c065300u: goto P_0c065300;
case 0x0c065302u: goto P_0c065302;
case 0x0c065304u: goto P_0c065304;
case 0x0c065306u: goto P_0c065306;
case 0x0c065308u: goto P_0c065308;
case 0x0c06530au: goto P_0c06530a;
case 0x0c06530cu: goto P_0c06530c;
case 0x0c06530eu: goto P_0c06530e;
case 0x0c065310u: goto P_0c065310;
case 0x0c065312u: goto P_0c065312;
case 0x0c065314u: goto P_0c065314;
case 0x0c065316u: goto P_0c065316;
case 0x0c065318u: goto P_0c065318;
case 0x0c06531au: goto P_0c06531a;
case 0x0c06531cu: goto P_0c06531c;
case 0x0c06531eu: goto P_0c06531e;
case 0x0c065320u: goto P_0c065320;
case 0x0c065322u: goto P_0c065322;
case 0x0c065324u: goto P_0c065324;
case 0x0c065326u: goto P_0c065326;
case 0x0c065328u: goto P_0c065328;
case 0x0c06532au: goto P_0c06532a;
case 0x0c06532cu: goto P_0c06532c;
case 0x0c06532eu: goto P_0c06532e;
case 0x0c06535cu: goto P_0c06535c;
case 0x0c06535eu: goto P_0c06535e;
case 0x0c065360u: goto P_0c065360;
case 0x0c065362u: goto P_0c065362;
case 0x0c065364u: goto P_0c065364;
case 0x0c065366u: goto P_0c065366;
case 0x0c065368u: goto P_0c065368;
case 0x0c06536au: goto P_0c06536a;
case 0x0c06536cu: goto P_0c06536c;
case 0x0c06536eu: goto P_0c06536e;
case 0x0c065370u: goto P_0c065370;
case 0x0c065372u: goto P_0c065372;
case 0x0c065374u: goto P_0c065374;
case 0x0c065376u: goto P_0c065376;
case 0x0c065378u: goto P_0c065378;
case 0x0c06537au: goto P_0c06537a;
case 0x0c06537cu: goto P_0c06537c;
case 0x0c06537eu: goto P_0c06537e;
case 0x0c065380u: goto P_0c065380;
case 0x0c065382u: goto P_0c065382;
case 0x0c065384u: goto P_0c065384;
case 0x0c065386u: goto P_0c065386;
case 0x0c065388u: goto P_0c065388;
case 0x0c06538au: goto P_0c06538a;
case 0x0c06538cu: goto P_0c06538c;
case 0x0c06538eu: goto P_0c06538e;
case 0x0c065390u: goto P_0c065390;
case 0x0c065392u: goto P_0c065392;
case 0x0c065394u: goto P_0c065394;
case 0x0c065396u: goto P_0c065396;
case 0x0c065398u: goto P_0c065398;
case 0x0c06539au: goto P_0c06539a;
case 0x0c06539cu: goto P_0c06539c;
case 0x0c06539eu: goto P_0c06539e;
case 0x0c0653a0u: goto P_0c0653a0;
case 0x0c0653a2u: goto P_0c0653a2;
case 0x0c0653a4u: goto P_0c0653a4;
case 0x0c0653a6u: goto P_0c0653a6;
case 0x0c0653a8u: goto P_0c0653a8;
case 0x0c0653aau: goto P_0c0653aa;
case 0x0c0653acu: goto P_0c0653ac;
case 0x0c0653aeu: goto P_0c0653ae;
case 0x0c0653b0u: goto P_0c0653b0;
case 0x0c0653b2u: goto P_0c0653b2;
case 0x0c0653b4u: goto P_0c0653b4;
case 0x0c0653b6u: goto P_0c0653b6;
case 0x0c0653b8u: goto P_0c0653b8;
case 0x0c0653bau: goto P_0c0653ba;
case 0x0c0653bcu: goto P_0c0653bc;
case 0x0c0653beu: goto P_0c0653be;
case 0x0c0653c0u: goto P_0c0653c0;
case 0x0c0653c2u: goto P_0c0653c2;
case 0x0c0653c4u: goto P_0c0653c4;
case 0x0c0653c6u: goto P_0c0653c6;
case 0x0c0653c8u: goto P_0c0653c8;
case 0x0c0653cau: goto P_0c0653ca;
case 0x0c0653ccu: goto P_0c0653cc;
case 0x0c0653ceu: goto P_0c0653ce;
case 0x0c0653d0u: goto P_0c0653d0;
case 0x0c0653d2u: goto P_0c0653d2;
case 0x0c0653d4u: goto P_0c0653d4;
case 0x0c0653d6u: goto P_0c0653d6;
case 0x0c0653d8u: goto P_0c0653d8;
case 0x0c0653dau: goto P_0c0653da;
case 0x0c0653dcu: goto P_0c0653dc;
case 0x0c0653deu: goto P_0c0653de;
case 0x0c0653e0u: goto P_0c0653e0;
case 0x0c0653e2u: goto P_0c0653e2;
case 0x0c0653e4u: goto P_0c0653e4;
case 0x0c0653e6u: goto P_0c0653e6;
case 0x0c0653e8u: goto P_0c0653e8;
case 0x0c0653eau: goto P_0c0653ea;
case 0x0c0653ecu: goto P_0c0653ec;
case 0x0c0653eeu: goto P_0c0653ee;
case 0x0c0653f0u: goto P_0c0653f0;
case 0x0c0653f2u: goto P_0c0653f2;
case 0x0c0653f4u: goto P_0c0653f4;
case 0x0c0653f6u: goto P_0c0653f6;
case 0x0c0653f8u: goto P_0c0653f8;
case 0x0c0653fau: goto P_0c0653fa;
case 0x0c0653fcu: goto P_0c0653fc;
case 0x0c0653feu: goto P_0c0653fe;
case 0x0c065400u: goto P_0c065400;
case 0x0c065402u: goto P_0c065402;
case 0x0c065404u: goto P_0c065404;
case 0x0c065406u: goto P_0c065406;
case 0x0c065408u: goto P_0c065408;
case 0x0c06540au: goto P_0c06540a;
case 0x0c06540cu: goto P_0c06540c;
case 0x0c06540eu: goto P_0c06540e;
case 0x0c065410u: goto P_0c065410;
case 0x0c065412u: goto P_0c065412;
case 0x0c065414u: goto P_0c065414;
case 0x0c065416u: goto P_0c065416;
case 0x0c065418u: goto P_0c065418;
case 0x0c06541au: goto P_0c06541a;
case 0x0c06541cu: goto P_0c06541c;
case 0x0c06541eu: goto P_0c06541e;
case 0x0c065420u: goto P_0c065420;
case 0x0c065422u: goto P_0c065422;
case 0x0c065424u: goto P_0c065424;
case 0x0c065426u: goto P_0c065426;
case 0x0c065428u: goto P_0c065428;
case 0x0c06542au: goto P_0c06542a;
case 0x0c06542cu: goto P_0c06542c;
case 0x0c06542eu: goto P_0c06542e;
case 0x0c065430u: goto P_0c065430;
case 0x0c065432u: goto P_0c065432;
case 0x0c065434u: goto P_0c065434;
case 0x0c065436u: goto P_0c065436;
case 0x0c065438u: goto P_0c065438;
case 0x0c06543au: goto P_0c06543a;
case 0x0c06543cu: goto P_0c06543c;
case 0x0c06543eu: goto P_0c06543e;
case 0x0c065440u: goto P_0c065440;
case 0x0c065442u: goto P_0c065442;
case 0x0c065444u: goto P_0c065444;
case 0x0c065446u: goto P_0c065446;
case 0x0c065448u: goto P_0c065448;
case 0x0c06544au: goto P_0c06544a;
case 0x0c06544cu: goto P_0c06544c;
case 0x0c06544eu: goto P_0c06544e;
case 0x0c065450u: goto P_0c065450;
case 0x0c065452u: goto P_0c065452;
case 0x0c065454u: goto P_0c065454;
case 0x0c065456u: goto P_0c065456;
case 0x0c065458u: goto P_0c065458;
case 0x0c06545au: goto P_0c06545a;
case 0x0c06545cu: goto P_0c06545c;
case 0x0c06545eu: goto P_0c06545e;
case 0x0c065460u: goto P_0c065460;
case 0x0c065462u: goto P_0c065462;
case 0x0c065464u: goto P_0c065464;
case 0x0c065466u: goto P_0c065466;
case 0x0c065468u: goto P_0c065468;
case 0x0c06546au: goto P_0c06546a;
case 0x0c06546cu: goto P_0c06546c;
case 0x0c06546eu: goto P_0c06546e;
case 0x0c065470u: goto P_0c065470;
case 0x0c065472u: goto P_0c065472;
case 0x0c065474u: goto P_0c065474;
case 0x0c065476u: goto P_0c065476;
case 0x0c065478u: goto P_0c065478;
case 0x0c06547au: goto P_0c06547a;
case 0x0c06547cu: goto P_0c06547c;
case 0x0c06547eu: goto P_0c06547e;
case 0x0c065480u: goto P_0c065480;
case 0x0c065482u: goto P_0c065482;
case 0x0c065484u: goto P_0c065484;
case 0x0c065486u: goto P_0c065486;
case 0x0c065488u: goto P_0c065488;
case 0x0c06548au: goto P_0c06548a;
case 0x0c06548cu: goto P_0c06548c;
case 0x0c06548eu: goto P_0c06548e;
case 0x0c065490u: goto P_0c065490;
case 0x0c065492u: goto P_0c065492;
case 0x0c065494u: goto P_0c065494;
case 0x0c065496u: goto P_0c065496;
case 0x0c065498u: goto P_0c065498;
case 0x0c06549au: goto P_0c06549a;
case 0x0c06549cu: goto P_0c06549c;
case 0x0c06549eu: goto P_0c06549e;
case 0x0c0654a0u: goto P_0c0654a0;
case 0x0c0654a2u: goto P_0c0654a2;
case 0x0c0654a4u: goto P_0c0654a4;
case 0x0c0654a6u: goto P_0c0654a6;
case 0x0c0654a8u: goto P_0c0654a8;
case 0x0c0654aau: goto P_0c0654aa;
case 0x0c0654acu: goto P_0c0654ac;
case 0x0c0654aeu: goto P_0c0654ae;
case 0x0c0654b0u: goto P_0c0654b0;
case 0x0c0654b2u: goto P_0c0654b2;
case 0x0c0654b4u: goto P_0c0654b4;
case 0x0c0654b6u: goto P_0c0654b6;
case 0x0c0654b8u: goto P_0c0654b8;
case 0x0c0654bau: goto P_0c0654ba;
case 0x0c0654bcu: goto P_0c0654bc;
case 0x0c0654beu: goto P_0c0654be;
case 0x0c0654c0u: goto P_0c0654c0;
case 0x0c0654c2u: goto P_0c0654c2;
case 0x0c0654c4u: goto P_0c0654c4;
case 0x0c0654c6u: goto P_0c0654c6;
case 0x0c0654c8u: goto P_0c0654c8;
case 0x0c0654cau: goto P_0c0654ca;
case 0x0c0654ccu: goto P_0c0654cc;
case 0x0c0654ceu: goto P_0c0654ce;
case 0x0c0654d0u: goto P_0c0654d0;
case 0x0c0654d2u: goto P_0c0654d2;
case 0x0c0654d4u: goto P_0c0654d4;
case 0x0c0654d6u: goto P_0c0654d6;
case 0x0c0654d8u: goto P_0c0654d8;
case 0x0c0654dau: goto P_0c0654da;
case 0x0c0654dcu: goto P_0c0654dc;
case 0x0c0654deu: goto P_0c0654de;
case 0x0c0654e0u: goto P_0c0654e0;
case 0x0c0654e2u: goto P_0c0654e2;
case 0x0c0654e4u: goto P_0c0654e4;
case 0x0c0654e6u: goto P_0c0654e6;
case 0x0c0654e8u: goto P_0c0654e8;
case 0x0c0654eau: goto P_0c0654ea;
case 0x0c0654ecu: goto P_0c0654ec;
case 0x0c0654eeu: goto P_0c0654ee;
case 0x0c0654f0u: goto P_0c0654f0;
case 0x0c0654f2u: goto P_0c0654f2;
case 0x0c0654f4u: goto P_0c0654f4;
case 0x0c0654f6u: goto P_0c0654f6;
case 0x0c0654f8u: goto P_0c0654f8;
case 0x0c0654fau: goto P_0c0654fa;
case 0x0c0654fcu: goto P_0c0654fc;
case 0x0c0654feu: goto P_0c0654fe;
case 0x0c065500u: goto P_0c065500;
case 0x0c065502u: goto P_0c065502;
case 0x0c065504u: goto P_0c065504;
case 0x0c065506u: goto P_0c065506;
case 0x0c065508u: goto P_0c065508;
case 0x0c06550au: goto P_0c06550a;
case 0x0c06550cu: goto P_0c06550c;
case 0x0c06550eu: goto P_0c06550e;
case 0x0c065510u: goto P_0c065510;
case 0x0c065512u: goto P_0c065512;
case 0x0c065514u: goto P_0c065514;
case 0x0c065516u: goto P_0c065516;
case 0x0c065518u: goto P_0c065518;
case 0x0c06551au: goto P_0c06551a;
case 0x0c06551cu: goto P_0c06551c;
case 0x0c06551eu: goto P_0c06551e;
case 0x0c065520u: goto P_0c065520;
case 0x0c065522u: goto P_0c065522;
case 0x0c065524u: goto P_0c065524;
case 0x0c065526u: goto P_0c065526;
case 0x0c065528u: goto P_0c065528;
case 0x0c06552au: goto P_0c06552a;
case 0x0c06552cu: goto P_0c06552c;
case 0x0c06552eu: goto P_0c06552e;
case 0x0c065530u: goto P_0c065530;
case 0x0c065532u: goto P_0c065532;
case 0x0c065534u: goto P_0c065534;
case 0x0c065536u: goto P_0c065536;
case 0x0c065538u: goto P_0c065538;
case 0x0c06553au: goto P_0c06553a;
case 0x0c06553cu: goto P_0c06553c;
case 0x0c06553eu: goto P_0c06553e;
case 0x0c065540u: goto P_0c065540;
case 0x0c065542u: goto P_0c065542;
case 0x0c065544u: goto P_0c065544;
case 0x0c065546u: goto P_0c065546;
case 0x0c065548u: goto P_0c065548;
case 0x0c06554au: goto P_0c06554a;
case 0x0c06554cu: goto P_0c06554c;
case 0x0c06554eu: goto P_0c06554e;
case 0x0c065550u: goto P_0c065550;
case 0x0c065552u: goto P_0c065552;
case 0x0c065554u: goto P_0c065554;
case 0x0c065556u: goto P_0c065556;
case 0x0c065558u: goto P_0c065558;
case 0x0c06555au: goto P_0c06555a;
case 0x0c06555cu: goto P_0c06555c;
case 0x0c06555eu: goto P_0c06555e;
case 0x0c065560u: goto P_0c065560;
case 0x0c065562u: goto P_0c065562;
case 0x0c065564u: goto P_0c065564;
case 0x0c065566u: goto P_0c065566;
case 0x0c065568u: goto P_0c065568;
case 0x0c06556au: goto P_0c06556a;
case 0x0c06556cu: goto P_0c06556c;
case 0x0c06556eu: goto P_0c06556e;
case 0x0c065570u: goto P_0c065570;
case 0x0c065572u: goto P_0c065572;
case 0x0c065574u: goto P_0c065574;
case 0x0c065576u: goto P_0c065576;
case 0x0c065578u: goto P_0c065578;
case 0x0c06557au: goto P_0c06557a;
case 0x0c06557cu: goto P_0c06557c;
case 0x0c06557eu: goto P_0c06557e;
case 0x0c065580u: goto P_0c065580;
case 0x0c065582u: goto P_0c065582;
case 0x0c065584u: goto P_0c065584;
case 0x0c065586u: goto P_0c065586;
case 0x0c065588u: goto P_0c065588;
case 0x0c06558au: goto P_0c06558a;
case 0x0c06558cu: goto P_0c06558c;
case 0x0c06558eu: goto P_0c06558e;
case 0x0c065590u: goto P_0c065590;
case 0x0c065592u: goto P_0c065592;
case 0x0c065594u: goto P_0c065594;
case 0x0c065596u: goto P_0c065596;
case 0x0c065598u: goto P_0c065598;
case 0x0c06559au: goto P_0c06559a;
case 0x0c06559cu: goto P_0c06559c;
case 0x0c06559eu: goto P_0c06559e;
case 0x0c0655a0u: goto P_0c0655a0;
case 0x0c0655a2u: goto P_0c0655a2;
case 0x0c0655a4u: goto P_0c0655a4;
case 0x0c0655e0u: goto P_0c0655e0;
case 0x0c0655e2u: goto P_0c0655e2;
case 0x0c0655e4u: goto P_0c0655e4;
case 0x0c0655e6u: goto P_0c0655e6;
case 0x0c0655e8u: goto P_0c0655e8;
case 0x0c0655eau: goto P_0c0655ea;
case 0x0c0655ecu: goto P_0c0655ec;
case 0x0c0655eeu: goto P_0c0655ee;
case 0x0c0655f0u: goto P_0c0655f0;
case 0x0c0655f2u: goto P_0c0655f2;
case 0x0c0655f4u: goto P_0c0655f4;
case 0x0c0655f6u: goto P_0c0655f6;
case 0x0c0655f8u: goto P_0c0655f8;
case 0x0c0655fau: goto P_0c0655fa;
case 0x0c0655fcu: goto P_0c0655fc;
case 0x0c0655feu: goto P_0c0655fe;
case 0x0c065600u: goto P_0c065600;
case 0x0c065602u: goto P_0c065602;
case 0x0c065604u: goto P_0c065604;
case 0x0c065606u: goto P_0c065606;
case 0x0c065608u: goto P_0c065608;
case 0x0c06560au: goto P_0c06560a;
case 0x0c06560cu: goto P_0c06560c;
case 0x0c06560eu: goto P_0c06560e;
case 0x0c065610u: goto P_0c065610;
case 0x0c065612u: goto P_0c065612;
case 0x0c065614u: goto P_0c065614;
case 0x0c065616u: goto P_0c065616;
case 0x0c065618u: goto P_0c065618;
case 0x0c06561au: goto P_0c06561a;
case 0x0c06561cu: goto P_0c06561c;
case 0x0c06561eu: goto P_0c06561e;
case 0x0c065620u: goto P_0c065620;
case 0x0c065622u: goto P_0c065622;
case 0x0c065624u: goto P_0c065624;
case 0x0c065626u: goto P_0c065626;
case 0x0c065628u: goto P_0c065628;
case 0x0c06562au: goto P_0c06562a;
case 0x0c06562cu: goto P_0c06562c;
case 0x0c06562eu: goto P_0c06562e;
case 0x0c065630u: goto P_0c065630;
case 0x0c065632u: goto P_0c065632;
case 0x0c065634u: goto P_0c065634;
case 0x0c065636u: goto P_0c065636;
case 0x0c065638u: goto P_0c065638;
case 0x0c06563au: goto P_0c06563a;
case 0x0c06563cu: goto P_0c06563c;
case 0x0c06563eu: goto P_0c06563e;
case 0x0c065640u: goto P_0c065640;
case 0x0c065642u: goto P_0c065642;
case 0x0c065644u: goto P_0c065644;
case 0x0c065646u: goto P_0c065646;
case 0x0c065648u: goto P_0c065648;
case 0x0c06564au: goto P_0c06564a;
case 0x0c06564cu: goto P_0c06564c;
case 0x0c06564eu: goto P_0c06564e;
case 0x0c065650u: goto P_0c065650;
case 0x0c065652u: goto P_0c065652;
case 0x0c065654u: goto P_0c065654;
case 0x0c065656u: goto P_0c065656;
case 0x0c065658u: goto P_0c065658;
case 0x0c06565au: goto P_0c06565a;
case 0x0c06565cu: goto P_0c06565c;
case 0x0c06565eu: goto P_0c06565e;
case 0x0c065660u: goto P_0c065660;
case 0x0c065662u: goto P_0c065662;
case 0x0c065664u: goto P_0c065664;
case 0x0c065666u: goto P_0c065666;
case 0x0c065668u: goto P_0c065668;
case 0x0c06566au: goto P_0c06566a;
case 0x0c06566cu: goto P_0c06566c;
case 0x0c06566eu: goto P_0c06566e;
case 0x0c065670u: goto P_0c065670;
case 0x0c065672u: goto P_0c065672;
case 0x0c065674u: goto P_0c065674;
case 0x0c065676u: goto P_0c065676;
case 0x0c065678u: goto P_0c065678;
case 0x0c06567au: goto P_0c06567a;
case 0x0c06567cu: goto P_0c06567c;
case 0x0c06567eu: goto P_0c06567e;
case 0x0c065680u: goto P_0c065680;
case 0x0c065682u: goto P_0c065682;
case 0x0c065684u: goto P_0c065684;
case 0x0c065686u: goto P_0c065686;
case 0x0c065688u: goto P_0c065688;
case 0x0c06568au: goto P_0c06568a;
case 0x0c06568cu: goto P_0c06568c;
case 0x0c06568eu: goto P_0c06568e;
case 0x0c065690u: goto P_0c065690;
case 0x0c065692u: goto P_0c065692;
case 0x0c065694u: goto P_0c065694;
case 0x0c065696u: goto P_0c065696;
case 0x0c065698u: goto P_0c065698;
case 0x0c06569au: goto P_0c06569a;
case 0x0c06569cu: goto P_0c06569c;
case 0x0c06569eu: goto P_0c06569e;
case 0x0c0656a0u: goto P_0c0656a0;
case 0x0c0656a2u: goto P_0c0656a2;
case 0x0c0656a4u: goto P_0c0656a4;
case 0x0c0656a6u: goto P_0c0656a6;
case 0x0c0656a8u: goto P_0c0656a8;
case 0x0c0656aau: goto P_0c0656aa;
case 0x0c0656acu: goto P_0c0656ac;
case 0x0c0656aeu: goto P_0c0656ae;
case 0x0c0656b0u: goto P_0c0656b0;
case 0x0c0656b2u: goto P_0c0656b2;
case 0x0c0656b4u: goto P_0c0656b4;
case 0x0c0656b6u: goto P_0c0656b6;
case 0x0c0656b8u: goto P_0c0656b8;
case 0x0c0656bau: goto P_0c0656ba;
case 0x0c0656bcu: goto P_0c0656bc;
case 0x0c0656beu: goto P_0c0656be;
case 0x0c0656c0u: goto P_0c0656c0;
case 0x0c0656c2u: goto P_0c0656c2;
case 0x0c0656c4u: goto P_0c0656c4;
case 0x0c0656c6u: goto P_0c0656c6;
case 0x0c0656c8u: goto P_0c0656c8;
case 0x0c0656cau: goto P_0c0656ca;
case 0x0c0656ccu: goto P_0c0656cc;
case 0x0c0656ceu: goto P_0c0656ce;
case 0x0c0656d0u: goto P_0c0656d0;
case 0x0c0656d2u: goto P_0c0656d2;
case 0x0c0656d4u: goto P_0c0656d4;
case 0x0c0656d6u: goto P_0c0656d6;
case 0x0c0656d8u: goto P_0c0656d8;
case 0x0c0656dau: goto P_0c0656da;
case 0x0c0656dcu: goto P_0c0656dc;
case 0x0c0656deu: goto P_0c0656de;
case 0x0c0656e0u: goto P_0c0656e0;
case 0x0c0656e2u: goto P_0c0656e2;
case 0x0c0656e4u: goto P_0c0656e4;
case 0x0c0656e6u: goto P_0c0656e6;
case 0x0c0656e8u: goto P_0c0656e8;
case 0x0c0656eau: goto P_0c0656ea;
case 0x0c0656ecu: goto P_0c0656ec;
case 0x0c0656eeu: goto P_0c0656ee;
case 0x0c0656f0u: goto P_0c0656f0;
case 0x0c0656f2u: goto P_0c0656f2;
case 0x0c0656f4u: goto P_0c0656f4;
case 0x0c0656f6u: goto P_0c0656f6;
case 0x0c0656f8u: goto P_0c0656f8;
case 0x0c0656fau: goto P_0c0656fa;
case 0x0c0656fcu: goto P_0c0656fc;
case 0x0c0656feu: goto P_0c0656fe;
case 0x0c065700u: goto P_0c065700;
case 0x0c065702u: goto P_0c065702;
case 0x0c065704u: goto P_0c065704;
case 0x0c065706u: goto P_0c065706;
case 0x0c065708u: goto P_0c065708;
case 0x0c06570au: goto P_0c06570a;
case 0x0c06570cu: goto P_0c06570c;
case 0x0c06570eu: goto P_0c06570e;
case 0x0c065710u: goto P_0c065710;
case 0x0c065712u: goto P_0c065712;
case 0x0c065714u: goto P_0c065714;
case 0x0c065716u: goto P_0c065716;
case 0x0c065718u: goto P_0c065718;
case 0x0c06571au: goto P_0c06571a;
case 0x0c06571cu: goto P_0c06571c;
case 0x0c06571eu: goto P_0c06571e;
case 0x0c065720u: goto P_0c065720;
case 0x0c065722u: goto P_0c065722;
case 0x0c065724u: goto P_0c065724;
case 0x0c065726u: goto P_0c065726;
case 0x0c065728u: goto P_0c065728;
case 0x0c06572au: goto P_0c06572a;
case 0x0c06572cu: goto P_0c06572c;
case 0x0c06572eu: goto P_0c06572e;
case 0x0c065730u: goto P_0c065730;
case 0x0c065732u: goto P_0c065732;
case 0x0c065734u: goto P_0c065734;
case 0x0c065736u: goto P_0c065736;
case 0x0c065738u: goto P_0c065738;
case 0x0c06573au: goto P_0c06573a;
case 0x0c06573cu: goto P_0c06573c;
case 0x0c06573eu: goto P_0c06573e;
case 0x0c065740u: goto P_0c065740;
case 0x0c065742u: goto P_0c065742;
case 0x0c065744u: goto P_0c065744;
case 0x0c065746u: goto P_0c065746;
case 0x0c065748u: goto P_0c065748;
case 0x0c06574au: goto P_0c06574a;
case 0x0c06574cu: goto P_0c06574c;
case 0x0c06574eu: goto P_0c06574e;
case 0x0c065750u: goto P_0c065750;
case 0x0c065752u: goto P_0c065752;
case 0x0c065754u: goto P_0c065754;
case 0x0c065756u: goto P_0c065756;
case 0x0c065758u: goto P_0c065758;
case 0x0c06575au: goto P_0c06575a;
case 0x0c06575cu: goto P_0c06575c;
case 0x0c06575eu: goto P_0c06575e;
case 0x0c065760u: goto P_0c065760;
case 0x0c065762u: goto P_0c065762;
case 0x0c065764u: goto P_0c065764;
case 0x0c065766u: goto P_0c065766;
case 0x0c065768u: goto P_0c065768;
case 0x0c06576au: goto P_0c06576a;
case 0x0c06576cu: goto P_0c06576c;
case 0x0c06576eu: goto P_0c06576e;
case 0x0c065770u: goto P_0c065770;
case 0x0c065772u: goto P_0c065772;
case 0x0c065774u: goto P_0c065774;
case 0x0c065776u: goto P_0c065776;
case 0x0c065778u: goto P_0c065778;
case 0x0c06577au: goto P_0c06577a;
case 0x0c06577cu: goto P_0c06577c;
case 0x0c06577eu: goto P_0c06577e;
case 0x0c065780u: goto P_0c065780;
case 0x0c065782u: goto P_0c065782;
case 0x0c065784u: goto P_0c065784;
case 0x0c065786u: goto P_0c065786;
case 0x0c065788u: goto P_0c065788;
case 0x0c06578au: goto P_0c06578a;
case 0x0c06578cu: goto P_0c06578c;
case 0x0c06578eu: goto P_0c06578e;
case 0x0c065790u: goto P_0c065790;
case 0x0c065792u: goto P_0c065792;
case 0x0c065794u: goto P_0c065794;
case 0x0c065796u: goto P_0c065796;
case 0x0c065798u: goto P_0c065798;
case 0x0c06579au: goto P_0c06579a;
case 0x0c06579cu: goto P_0c06579c;
case 0x0c06579eu: goto P_0c06579e;
case 0x0c0657a0u: goto P_0c0657a0;
case 0x0c0657a2u: goto P_0c0657a2;
case 0x0c0657a4u: goto P_0c0657a4;
case 0x0c0657a6u: goto P_0c0657a6;
case 0x0c0657a8u: goto P_0c0657a8;
case 0x0c0657aau: goto P_0c0657aa;
case 0x0c0657acu: goto P_0c0657ac;
case 0x0c0657aeu: goto P_0c0657ae;
case 0x0c0657b0u: goto P_0c0657b0;
case 0x0c0657b2u: goto P_0c0657b2;
case 0x0c0657b4u: goto P_0c0657b4;
case 0x0c0657b6u: goto P_0c0657b6;
case 0x0c0657b8u: goto P_0c0657b8;
case 0x0c0657bau: goto P_0c0657ba;
case 0x0c0657bcu: goto P_0c0657bc;
case 0x0c0657beu: goto P_0c0657be;
case 0x0c0657c0u: goto P_0c0657c0;
case 0x0c0657c2u: goto P_0c0657c2;
case 0x0c0657c4u: goto P_0c0657c4;
case 0x0c0657c6u: goto P_0c0657c6;
case 0x0c0657c8u: goto P_0c0657c8;
case 0x0c0657cau: goto P_0c0657ca;
case 0x0c0657ccu: goto P_0c0657cc;
case 0x0c0657ceu: goto P_0c0657ce;
case 0x0c0657d0u: goto P_0c0657d0;
case 0x0c0657d2u: goto P_0c0657d2;
case 0x0c0657d4u: goto P_0c0657d4;
case 0x0c0657d6u: goto P_0c0657d6;
case 0x0c0657d8u: goto P_0c0657d8;
case 0x0c0657dau: goto P_0c0657da;
case 0x0c0657dcu: goto P_0c0657dc;
case 0x0c0657deu: goto P_0c0657de;
case 0x0c0657e0u: goto P_0c0657e0;
case 0x0c0657e2u: goto P_0c0657e2;
case 0x0c0657e4u: goto P_0c0657e4;
case 0x0c0657e6u: goto P_0c0657e6;
case 0x0c0657e8u: goto P_0c0657e8;
case 0x0c0657eau: goto P_0c0657ea;
case 0x0c0657ecu: goto P_0c0657ec;
case 0x0c0657eeu: goto P_0c0657ee;
case 0x0c0657f0u: goto P_0c0657f0;
case 0x0c0657f2u: goto P_0c0657f2;
case 0x0c0657f4u: goto P_0c0657f4;
case 0x0c065aa0u: goto P_0c065aa0;
case 0x0c065aa2u: goto P_0c065aa2;
case 0x0c065aa4u: goto P_0c065aa4;
case 0x0c065aa6u: goto P_0c065aa6;
case 0x0c065aa8u: goto P_0c065aa8;
case 0x0c065aaau: goto P_0c065aaa;
case 0x0c065aacu: goto P_0c065aac;
case 0x0c065aaeu: goto P_0c065aae;
case 0x0c065ab0u: goto P_0c065ab0;
case 0x0c065ab2u: goto P_0c065ab2;
case 0x0c065ab4u: goto P_0c065ab4;
case 0x0c065ab6u: goto P_0c065ab6;
case 0x0c065ab8u: goto P_0c065ab8;
case 0x0c065abau: goto P_0c065aba;
case 0x0c065abcu: goto P_0c065abc;
case 0x0c065abeu: goto P_0c065abe;
case 0x0c065ac0u: goto P_0c065ac0;
case 0x0c065ac2u: goto P_0c065ac2;
case 0x0c065ac4u: goto P_0c065ac4;
case 0x0c065ac6u: goto P_0c065ac6;
case 0x0c065ac8u: goto P_0c065ac8;
case 0x0c065acau: goto P_0c065aca;
case 0x0c065accu: goto P_0c065acc;
case 0x0c065aceu: goto P_0c065ace;
case 0x0c065ad0u: goto P_0c065ad0;
case 0x0c065ad2u: goto P_0c065ad2;
case 0x0c065ad4u: goto P_0c065ad4;
case 0x0c065ad6u: goto P_0c065ad6;
case 0x0c065ad8u: goto P_0c065ad8;
case 0x0c065adau: goto P_0c065ada;
case 0x0c065adcu: goto P_0c065adc;
case 0x0c065adeu: goto P_0c065ade;
case 0x0c065ae0u: goto P_0c065ae0;
case 0x0c065ae2u: goto P_0c065ae2;
case 0x0c065ae4u: goto P_0c065ae4;
case 0x0c065ae6u: goto P_0c065ae6;
case 0x0c065ae8u: goto P_0c065ae8;
case 0x0c065aeau: goto P_0c065aea;
case 0x0c065aecu: goto P_0c065aec;
case 0x0c065aeeu: goto P_0c065aee;
case 0x0c065af0u: goto P_0c065af0;
case 0x0c065af2u: goto P_0c065af2;
case 0x0c065af4u: goto P_0c065af4;
case 0x0c065af6u: goto P_0c065af6;
case 0x0c065af8u: goto P_0c065af8;
case 0x0c065afau: goto P_0c065afa;
case 0x0c065afcu: goto P_0c065afc;
case 0x0c065afeu: goto P_0c065afe;
case 0x0c065b00u: goto P_0c065b00;
case 0x0c065b02u: goto P_0c065b02;
case 0x0c065b04u: goto P_0c065b04;
case 0x0c065b06u: goto P_0c065b06;
case 0x0c065b08u: goto P_0c065b08;
case 0x0c065b0au: goto P_0c065b0a;
case 0x0c065b0cu: goto P_0c065b0c;
case 0x0c065b0eu: goto P_0c065b0e;
case 0x0c065b10u: goto P_0c065b10;
case 0x0c065b12u: goto P_0c065b12;
case 0x0c065b14u: goto P_0c065b14;
case 0x0c065b16u: goto P_0c065b16;
case 0x0c065b18u: goto P_0c065b18;
case 0x0c065b1au: goto P_0c065b1a;
case 0x0c065b1cu: goto P_0c065b1c;
case 0x0c065b1eu: goto P_0c065b1e;
case 0x0c065b20u: goto P_0c065b20;
case 0x0c065b22u: goto P_0c065b22;
case 0x0c065b24u: goto P_0c065b24;
case 0x0c065b26u: goto P_0c065b26;
case 0x0c065b28u: goto P_0c065b28;
case 0x0c065b2au: goto P_0c065b2a;
case 0x0c065b2cu: goto P_0c065b2c;
case 0x0c065b2eu: goto P_0c065b2e;
case 0x0c065b30u: goto P_0c065b30;
case 0x0c065b32u: goto P_0c065b32;
case 0x0c065b34u: goto P_0c065b34;
case 0x0c065b36u: goto P_0c065b36;
case 0x0c065b38u: goto P_0c065b38;
case 0x0c065b3au: goto P_0c065b3a;
case 0x0c065b3cu: goto P_0c065b3c;
case 0x0c065b3eu: goto P_0c065b3e;
case 0x0c065b40u: goto P_0c065b40;
case 0x0c065b42u: goto P_0c065b42;
case 0x0c065b44u: goto P_0c065b44;
case 0x0c065b46u: goto P_0c065b46;
case 0x0c065b48u: goto P_0c065b48;
case 0x0c065b4au: goto P_0c065b4a;
case 0x0c065b4cu: goto P_0c065b4c;
case 0x0c065b4eu: goto P_0c065b4e;
case 0x0c065b50u: goto P_0c065b50;
case 0x0c065b52u: goto P_0c065b52;
case 0x0c065b54u: goto P_0c065b54;
case 0x0c065b56u: goto P_0c065b56;
case 0x0c065b58u: goto P_0c065b58;
case 0x0c065b5au: goto P_0c065b5a;
case 0x0c065b5cu: goto P_0c065b5c;
case 0x0c065b5eu: goto P_0c065b5e;
case 0x0c065b60u: goto P_0c065b60;
case 0x0c065b62u: goto P_0c065b62;
case 0x0c065b64u: goto P_0c065b64;
case 0x0c065b66u: goto P_0c065b66;
case 0x0c065b68u: goto P_0c065b68;
case 0x0c065b6au: goto P_0c065b6a;
case 0x0c065b6cu: goto P_0c065b6c;
case 0x0c065b6eu: goto P_0c065b6e;
case 0x0c065b70u: goto P_0c065b70;
case 0x0c065b72u: goto P_0c065b72;
case 0x0c065b74u: goto P_0c065b74;
case 0x0c065b76u: goto P_0c065b76;
case 0x0c065b78u: goto P_0c065b78;
case 0x0c065b7au: goto P_0c065b7a;
case 0x0c065b7cu: goto P_0c065b7c;
case 0x0c065b7eu: goto P_0c065b7e;
case 0x0c065b80u: goto P_0c065b80;
case 0x0c065b82u: goto P_0c065b82;
case 0x0c065b84u: goto P_0c065b84;
case 0x0c065b86u: goto P_0c065b86;
case 0x0c065b88u: goto P_0c065b88;
case 0x0c065b8au: goto P_0c065b8a;
case 0x0c065b8cu: goto P_0c065b8c;
case 0x0c065b8eu: goto P_0c065b8e;
case 0x0c065b90u: goto P_0c065b90;
case 0x0c065b92u: goto P_0c065b92;
case 0x0c065b94u: goto P_0c065b94;
case 0x0c065b96u: goto P_0c065b96;
case 0x0c065b98u: goto P_0c065b98;
case 0x0c065b9au: goto P_0c065b9a;
case 0x0c065b9cu: goto P_0c065b9c;
case 0x0c065b9eu: goto P_0c065b9e;
case 0x0c065ba0u: goto P_0c065ba0;
case 0x0c065ba2u: goto P_0c065ba2;
case 0x0c065ba4u: goto P_0c065ba4;
case 0x0c065ba6u: goto P_0c065ba6;
case 0x0c065ba8u: goto P_0c065ba8;
case 0x0c065baau: goto P_0c065baa;
case 0x0c065bacu: goto P_0c065bac;
case 0x0c065baeu: goto P_0c065bae;
case 0x0c065bb0u: goto P_0c065bb0;
case 0x0c065bb2u: goto P_0c065bb2;
case 0x0c065bb4u: goto P_0c065bb4;
case 0x0c065bb6u: goto P_0c065bb6;
case 0x0c065bb8u: goto P_0c065bb8;
case 0x0c065bbau: goto P_0c065bba;
case 0x0c065bbcu: goto P_0c065bbc;
case 0x0c065bbeu: goto P_0c065bbe;
case 0x0c065bc0u: goto P_0c065bc0;
case 0x0c065bc2u: goto P_0c065bc2;
case 0x0c065bc4u: goto P_0c065bc4;
case 0x0c065bc6u: goto P_0c065bc6;
case 0x0c065bc8u: goto P_0c065bc8;
case 0x0c065bcau: goto P_0c065bca;
case 0x0c065bccu: goto P_0c065bcc;
case 0x0c065bceu: goto P_0c065bce;
case 0x0c065bd0u: goto P_0c065bd0;
case 0x0c065bd2u: goto P_0c065bd2;
case 0x0c065bd4u: goto P_0c065bd4;
case 0x0c065bd6u: goto P_0c065bd6;
case 0x0c065bd8u: goto P_0c065bd8;
case 0x0c065bdau: goto P_0c065bda;
case 0x0c065bdcu: goto P_0c065bdc;
case 0x0c065bdeu: goto P_0c065bde;
case 0x0c065be0u: goto P_0c065be0;
case 0x0c065be2u: goto P_0c065be2;
case 0x0c065be4u: goto P_0c065be4;
case 0x0c065be6u: goto P_0c065be6;
case 0x0c065be8u: goto P_0c065be8;
case 0x0c065beau: goto P_0c065bea;
case 0x0c065becu: goto P_0c065bec;
case 0x0c065beeu: goto P_0c065bee;
case 0x0c065bf0u: goto P_0c065bf0;
case 0x0c065bf2u: goto P_0c065bf2;
case 0x0c065bf4u: goto P_0c065bf4;
case 0x0c065bf6u: goto P_0c065bf6;
case 0x0c065bf8u: goto P_0c065bf8;
case 0x0c065bfau: goto P_0c065bfa;
case 0x0c065bfcu: goto P_0c065bfc;
case 0x0c065bfeu: goto P_0c065bfe;
case 0x0c065c00u: goto P_0c065c00;
case 0x0c065c02u: goto P_0c065c02;
case 0x0c065c04u: goto P_0c065c04;
case 0x0c065c06u: goto P_0c065c06;
case 0x0c065c08u: goto P_0c065c08;
case 0x0c065c0au: goto P_0c065c0a;
case 0x0c065c0cu: goto P_0c065c0c;
case 0x0c065c0eu: goto P_0c065c0e;
case 0x0c065c10u: goto P_0c065c10;
case 0x0c065c12u: goto P_0c065c12;
case 0x0c065c4cu: goto P_0c065c4c;
case 0x0c065c4eu: goto P_0c065c4e;
case 0x0c065c50u: goto P_0c065c50;
case 0x0c065c52u: goto P_0c065c52;
case 0x0c065c54u: goto P_0c065c54;
case 0x0c065c56u: goto P_0c065c56;
case 0x0c065c58u: goto P_0c065c58;
case 0x0c065c5au: goto P_0c065c5a;
case 0x0c065c5cu: goto P_0c065c5c;
case 0x0c065c5eu: goto P_0c065c5e;
case 0x0c065c60u: goto P_0c065c60;
case 0x0c065c62u: goto P_0c065c62;
case 0x0c065c64u: goto P_0c065c64;
case 0x0c065c66u: goto P_0c065c66;
case 0x0c065c68u: goto P_0c065c68;
case 0x0c065c6au: goto P_0c065c6a;
case 0x0c065c6cu: goto P_0c065c6c;
case 0x0c065c6eu: goto P_0c065c6e;
case 0x0c065c70u: goto P_0c065c70;
case 0x0c065c72u: goto P_0c065c72;
case 0x0c065c74u: goto P_0c065c74;
case 0x0c065c76u: goto P_0c065c76;
case 0x0c065c78u: goto P_0c065c78;
case 0x0c065c7au: goto P_0c065c7a;
case 0x0c065c7cu: goto P_0c065c7c;
case 0x0c065c7eu: goto P_0c065c7e;
case 0x0c065c80u: goto P_0c065c80;
case 0x0c065c82u: goto P_0c065c82;
case 0x0c065c84u: goto P_0c065c84;
case 0x0c065c86u: goto P_0c065c86;
case 0x0c065c88u: goto P_0c065c88;
case 0x0c065c8au: goto P_0c065c8a;
case 0x0c065c8cu: goto P_0c065c8c;
case 0x0c065c8eu: goto P_0c065c8e;
case 0x0c065c90u: goto P_0c065c90;
case 0x0c065c92u: goto P_0c065c92;
case 0x0c065c94u: goto P_0c065c94;
case 0x0c065c96u: goto P_0c065c96;
case 0x0c065c98u: goto P_0c065c98;
case 0x0c065c9au: goto P_0c065c9a;
case 0x0c065c9cu: goto P_0c065c9c;
case 0x0c065c9eu: goto P_0c065c9e;
case 0x0c065ca0u: goto P_0c065ca0;
case 0x0c065ca2u: goto P_0c065ca2;
case 0x0c065ca4u: goto P_0c065ca4;
case 0x0c065ca6u: goto P_0c065ca6;
case 0x0c065ca8u: goto P_0c065ca8;
case 0x0c065caau: goto P_0c065caa;
case 0x0c065cacu: goto P_0c065cac;
case 0x0c065caeu: goto P_0c065cae;
case 0x0c065cb0u: goto P_0c065cb0;
case 0x0c065cb2u: goto P_0c065cb2;
case 0x0c065cb4u: goto P_0c065cb4;
case 0x0c065cb6u: goto P_0c065cb6;
case 0x0c065cb8u: goto P_0c065cb8;
case 0x0c065cbau: goto P_0c065cba;
case 0x0c065cbcu: goto P_0c065cbc;
case 0x0c065cbeu: goto P_0c065cbe;
case 0x0c065cc0u: goto P_0c065cc0;
case 0x0c065cc2u: goto P_0c065cc2;
case 0x0c065cc4u: goto P_0c065cc4;
case 0x0c065cc6u: goto P_0c065cc6;
case 0x0c065cc8u: goto P_0c065cc8;
case 0x0c065ccau: goto P_0c065cca;
case 0x0c065cccu: goto P_0c065ccc;
case 0x0c065cceu: goto P_0c065cce;
case 0x0c065cd0u: goto P_0c065cd0;
case 0x0c065cd2u: goto P_0c065cd2;
case 0x0c065cd4u: goto P_0c065cd4;
case 0x0c065cd6u: goto P_0c065cd6;
case 0x0c065cd8u: goto P_0c065cd8;
case 0x0c065cdau: goto P_0c065cda;
case 0x0c065cdcu: goto P_0c065cdc;
case 0x0c065cdeu: goto P_0c065cde;
case 0x0c065ce0u: goto P_0c065ce0;
case 0x0c065ce2u: goto P_0c065ce2;
case 0x0c065ce4u: goto P_0c065ce4;
case 0x0c065ce6u: goto P_0c065ce6;
case 0x0c065ce8u: goto P_0c065ce8;
case 0x0c065ceau: goto P_0c065cea;
case 0x0c065cecu: goto P_0c065cec;
case 0x0c065ceeu: goto P_0c065cee;
case 0x0c065cf0u: goto P_0c065cf0;
case 0x0c065cf2u: goto P_0c065cf2;
case 0x0c065cf4u: goto P_0c065cf4;
case 0x0c065cf6u: goto P_0c065cf6;
case 0x0c065cf8u: goto P_0c065cf8;
case 0x0c065cfau: goto P_0c065cfa;
case 0x0c065cfcu: goto P_0c065cfc;
case 0x0c065cfeu: goto P_0c065cfe;
case 0x0c065d00u: goto P_0c065d00;
case 0x0c065d02u: goto P_0c065d02;
case 0x0c065d04u: goto P_0c065d04;
case 0x0c065d06u: goto P_0c065d06;
case 0x0c065d08u: goto P_0c065d08;
case 0x0c065d0au: goto P_0c065d0a;
case 0x0c065d0cu: goto P_0c065d0c;
case 0x0c065d0eu: goto P_0c065d0e;
case 0x0c065d10u: goto P_0c065d10;
case 0x0c065d12u: goto P_0c065d12;
case 0x0c065d14u: goto P_0c065d14;
case 0x0c065d16u: goto P_0c065d16;
case 0x0c065d18u: goto P_0c065d18;
case 0x0c065d1au: goto P_0c065d1a;
case 0x0c065d1cu: goto P_0c065d1c;
case 0x0c065d1eu: goto P_0c065d1e;
case 0x0c065d20u: goto P_0c065d20;
case 0x0c065d22u: goto P_0c065d22;
case 0x0c065d24u: goto P_0c065d24;
case 0x0c065d26u: goto P_0c065d26;
case 0x0c065d28u: goto P_0c065d28;
case 0x0c065d2au: goto P_0c065d2a;
case 0x0c065d2cu: goto P_0c065d2c;
case 0x0c065d2eu: goto P_0c065d2e;
case 0x0c065d30u: goto P_0c065d30;
case 0x0c065d32u: goto P_0c065d32;
case 0x0c065d34u: goto P_0c065d34;
case 0x0c065d36u: goto P_0c065d36;
case 0x0c065d38u: goto P_0c065d38;
case 0x0c065d3au: goto P_0c065d3a;
case 0x0c065d3cu: goto P_0c065d3c;
case 0x0c065d3eu: goto P_0c065d3e;
case 0x0c065d40u: goto P_0c065d40;
case 0x0c065d42u: goto P_0c065d42;
case 0x0c065d44u: goto P_0c065d44;
case 0x0c065d46u: goto P_0c065d46;
case 0x0c065d48u: goto P_0c065d48;
case 0x0c065d4au: goto P_0c065d4a;
case 0x0c065d4cu: goto P_0c065d4c;
case 0x0c065d4eu: goto P_0c065d4e;
case 0x0c065d50u: goto P_0c065d50;
case 0x0c065d52u: goto P_0c065d52;
case 0x0c065d54u: goto P_0c065d54;
case 0x0c065d56u: goto P_0c065d56;
case 0x0c065d58u: goto P_0c065d58;
case 0x0c065d5au: goto P_0c065d5a;
case 0x0c065d5cu: goto P_0c065d5c;
case 0x0c065d5eu: goto P_0c065d5e;
case 0x0c065d60u: goto P_0c065d60;
case 0x0c065d62u: goto P_0c065d62;
case 0x0c065d64u: goto P_0c065d64;
case 0x0c065d66u: goto P_0c065d66;
case 0x0c065d68u: goto P_0c065d68;
case 0x0c065d6au: goto P_0c065d6a;
case 0x0c065d6cu: goto P_0c065d6c;
case 0x0c065d6eu: goto P_0c065d6e;
case 0x0c065d70u: goto P_0c065d70;
case 0x0c065d72u: goto P_0c065d72;
case 0x0c065d74u: goto P_0c065d74;
case 0x0c065d76u: goto P_0c065d76;
case 0x0c065d78u: goto P_0c065d78;
case 0x0c065d7au: goto P_0c065d7a;
case 0x0c065d7cu: goto P_0c065d7c;
case 0x0c065d7eu: goto P_0c065d7e;
case 0x0c065d80u: goto P_0c065d80;
case 0x0c065d82u: goto P_0c065d82;
case 0x0c065d84u: goto P_0c065d84;
case 0x0c065d86u: goto P_0c065d86;
case 0x0c065d88u: goto P_0c065d88;
case 0x0c065d8au: goto P_0c065d8a;
case 0x0c065d8cu: goto P_0c065d8c;
case 0x0c065d8eu: goto P_0c065d8e;
case 0x0c065d90u: goto P_0c065d90;
case 0x0c065d92u: goto P_0c065d92;
case 0x0c065d94u: goto P_0c065d94;
case 0x0c065d96u: goto P_0c065d96;
case 0x0c065d98u: goto P_0c065d98;
case 0x0c065d9au: goto P_0c065d9a;
case 0x0c065d9cu: goto P_0c065d9c;
case 0x0c065d9eu: goto P_0c065d9e;
case 0x0c065da0u: goto P_0c065da0;
case 0x0c065da2u: goto P_0c065da2;
case 0x0c065da4u: goto P_0c065da4;
case 0x0c065da6u: goto P_0c065da6;
case 0x0c065da8u: goto P_0c065da8;
case 0x0c065daau: goto P_0c065daa;
case 0x0c065de4u: goto P_0c065de4;
case 0x0c065de6u: goto P_0c065de6;
case 0x0c065de8u: goto P_0c065de8;
case 0x0c065deau: goto P_0c065dea;
case 0x0c065decu: goto P_0c065dec;
case 0x0c065deeu: goto P_0c065dee;
case 0x0c065df0u: goto P_0c065df0;
case 0x0c065df2u: goto P_0c065df2;
case 0x0c065df4u: goto P_0c065df4;
case 0x0c065df6u: goto P_0c065df6;
case 0x0c065df8u: goto P_0c065df8;
case 0x0c065dfau: goto P_0c065dfa;
case 0x0c065dfcu: goto P_0c065dfc;
case 0x0c065dfeu: goto P_0c065dfe;
case 0x0c065e00u: goto P_0c065e00;
case 0x0c065e02u: goto P_0c065e02;
case 0x0c065e04u: goto P_0c065e04;
case 0x0c065e06u: goto P_0c065e06;
case 0x0c065e08u: goto P_0c065e08;
case 0x0c065e0au: goto P_0c065e0a;
case 0x0c065e0cu: goto P_0c065e0c;
case 0x0c065e0eu: goto P_0c065e0e;
case 0x0c065e10u: goto P_0c065e10;
case 0x0c065e12u: goto P_0c065e12;
case 0x0c065e14u: goto P_0c065e14;
case 0x0c065e16u: goto P_0c065e16;
case 0x0c065e18u: goto P_0c065e18;
case 0x0c065e1au: goto P_0c065e1a;
case 0x0c065e1cu: goto P_0c065e1c;
case 0x0c065e1eu: goto P_0c065e1e;
case 0x0c065e20u: goto P_0c065e20;
case 0x0c065e22u: goto P_0c065e22;
case 0x0c065e24u: goto P_0c065e24;
case 0x0c065e26u: goto P_0c065e26;
case 0x0c065e28u: goto P_0c065e28;
case 0x0c065e2au: goto P_0c065e2a;
case 0x0c065e2cu: goto P_0c065e2c;
case 0x0c065e2eu: goto P_0c065e2e;
case 0x0c065e30u: goto P_0c065e30;
case 0x0c065e32u: goto P_0c065e32;
case 0x0c065e34u: goto P_0c065e34;
case 0x0c065e36u: goto P_0c065e36;
case 0x0c065e38u: goto P_0c065e38;
case 0x0c065e3au: goto P_0c065e3a;
case 0x0c065e3cu: goto P_0c065e3c;
case 0x0c065e3eu: goto P_0c065e3e;
case 0x0c065e40u: goto P_0c065e40;
case 0x0c065e42u: goto P_0c065e42;
case 0x0c065e44u: goto P_0c065e44;
case 0x0c065e46u: goto P_0c065e46;
case 0x0c065e48u: goto P_0c065e48;
case 0x0c065e4au: goto P_0c065e4a;
case 0x0c065e4cu: goto P_0c065e4c;
case 0x0c065e4eu: goto P_0c065e4e;
case 0x0c065e50u: goto P_0c065e50;
case 0x0c065e52u: goto P_0c065e52;
case 0x0c065e54u: goto P_0c065e54;
case 0x0c065e56u: goto P_0c065e56;
case 0x0c065e58u: goto P_0c065e58;
case 0x0c065e5au: goto P_0c065e5a;
case 0x0c065e5cu: goto P_0c065e5c;
case 0x0c065e5eu: goto P_0c065e5e;
case 0x0c065e60u: goto P_0c065e60;
case 0x0c065e62u: goto P_0c065e62;
case 0x0c065e64u: goto P_0c065e64;
case 0x0c065e66u: goto P_0c065e66;
case 0x0c065e68u: goto P_0c065e68;
case 0x0c065e6au: goto P_0c065e6a;
case 0x0c065e6cu: goto P_0c065e6c;
case 0x0c065e6eu: goto P_0c065e6e;
case 0x0c065e70u: goto P_0c065e70;
case 0x0c065e72u: goto P_0c065e72;
case 0x0c065e74u: goto P_0c065e74;
case 0x0c065e76u: goto P_0c065e76;
case 0x0c065e78u: goto P_0c065e78;
case 0x0c065e7au: goto P_0c065e7a;
case 0x0c065e7cu: goto P_0c065e7c;
case 0x0c065e7eu: goto P_0c065e7e;
case 0x0c065e80u: goto P_0c065e80;
case 0x0c065e82u: goto P_0c065e82;
case 0x0c065e84u: goto P_0c065e84;
case 0x0c065e86u: goto P_0c065e86;
case 0x0c065e88u: goto P_0c065e88;
case 0x0c065e8au: goto P_0c065e8a;
case 0x0c065e8cu: goto P_0c065e8c;
case 0x0c065e8eu: goto P_0c065e8e;
case 0x0c065e90u: goto P_0c065e90;
case 0x0c065e92u: goto P_0c065e92;
case 0x0c065e94u: goto P_0c065e94;
case 0x0c065e96u: goto P_0c065e96;
case 0x0c065e98u: goto P_0c065e98;
case 0x0c065e9au: goto P_0c065e9a;
case 0x0c065e9cu: goto P_0c065e9c;
case 0x0c065e9eu: goto P_0c065e9e;
case 0x0c065ea0u: goto P_0c065ea0;
case 0x0c065ea2u: goto P_0c065ea2;
case 0x0c065ea4u: goto P_0c065ea4;
case 0x0c065ea6u: goto P_0c065ea6;
case 0x0c065ea8u: goto P_0c065ea8;
case 0x0c065eaau: goto P_0c065eaa;
case 0x0c065eacu: goto P_0c065eac;
case 0x0c065eaeu: goto P_0c065eae;
case 0x0c065eb0u: goto P_0c065eb0;
case 0x0c065eb2u: goto P_0c065eb2;
case 0x0c065eb4u: goto P_0c065eb4;
case 0x0c065eb6u: goto P_0c065eb6;
case 0x0c065eb8u: goto P_0c065eb8;
case 0x0c065ebau: goto P_0c065eba;
case 0x0c065ebcu: goto P_0c065ebc;
case 0x0c065ebeu: goto P_0c065ebe;
case 0x0c065ec0u: goto P_0c065ec0;
case 0x0c065ec2u: goto P_0c065ec2;
case 0x0c065ec4u: goto P_0c065ec4;
case 0x0c065ec6u: goto P_0c065ec6;
case 0x0c065ec8u: goto P_0c065ec8;
case 0x0c065ecau: goto P_0c065eca;
case 0x0c065eccu: goto P_0c065ecc;
case 0x0c065eceu: goto P_0c065ece;
case 0x0c065ed0u: goto P_0c065ed0;
case 0x0c065ed2u: goto P_0c065ed2;
case 0x0c065ed4u: goto P_0c065ed4;
case 0x0c065ed6u: goto P_0c065ed6;
case 0x0c065ed8u: goto P_0c065ed8;
case 0x0c065edau: goto P_0c065eda;
case 0x0c065edcu: goto P_0c065edc;
case 0x0c065edeu: goto P_0c065ede;
case 0x0c065ee0u: goto P_0c065ee0;
case 0x0c065ee2u: goto P_0c065ee2;
case 0x0c065ee4u: goto P_0c065ee4;
case 0x0c065ee6u: goto P_0c065ee6;
case 0x0c065ee8u: goto P_0c065ee8;
case 0x0c065eeau: goto P_0c065eea;
case 0x0c065eecu: goto P_0c065eec;
case 0x0c065eeeu: goto P_0c065eee;
case 0x0c065ef0u: goto P_0c065ef0;
case 0x0c065ef2u: goto P_0c065ef2;
case 0x0c065ef4u: goto P_0c065ef4;
case 0x0c065ef6u: goto P_0c065ef6;
case 0x0c065ef8u: goto P_0c065ef8;
case 0x0c065efau: goto P_0c065efa;
case 0x0c065efcu: goto P_0c065efc;
case 0x0c065efeu: goto P_0c065efe;
case 0x0c065f00u: goto P_0c065f00;
case 0x0c065f02u: goto P_0c065f02;
case 0x0c065f04u: goto P_0c065f04;
case 0x0c065f06u: goto P_0c065f06;
case 0x0c065f08u: goto P_0c065f08;
case 0x0c065f0au: goto P_0c065f0a;
case 0x0c065f0cu: goto P_0c065f0c;
case 0x0c065f0eu: goto P_0c065f0e;
case 0x0c065f10u: goto P_0c065f10;
case 0x0c065f12u: goto P_0c065f12;
case 0x0c065f14u: goto P_0c065f14;
case 0x0c065f16u: goto P_0c065f16;
case 0x0c065f18u: goto P_0c065f18;
case 0x0c065f1au: goto P_0c065f1a;
case 0x0c065f1cu: goto P_0c065f1c;
case 0x0c065f1eu: goto P_0c065f1e;
case 0x0c065f20u: goto P_0c065f20;
case 0x0c065f22u: goto P_0c065f22;
case 0x0c065f24u: goto P_0c065f24;
case 0x0c065f26u: goto P_0c065f26;
case 0x0c065f28u: goto P_0c065f28;
case 0x0c065f2au: goto P_0c065f2a;
case 0x0c065f2cu: goto P_0c065f2c;
case 0x0c065f2eu: goto P_0c065f2e;
case 0x0c065f30u: goto P_0c065f30;
case 0x0c065f32u: goto P_0c065f32;
case 0x0c065f34u: goto P_0c065f34;
case 0x0c065f36u: goto P_0c065f36;
case 0x0c065f38u: goto P_0c065f38;
case 0x0c065f3au: goto P_0c065f3a;
case 0x0c065f3cu: goto P_0c065f3c;
case 0x0c065f3eu: goto P_0c065f3e;
case 0x0c065f40u: goto P_0c065f40;
case 0x0c065f42u: goto P_0c065f42;
case 0x0c065f44u: goto P_0c065f44;
case 0x0c065f46u: goto P_0c065f46;
case 0x0c065f48u: goto P_0c065f48;
case 0x0c065f4au: goto P_0c065f4a;
case 0x0c065f4cu: goto P_0c065f4c;
case 0x0c065f4eu: goto P_0c065f4e;
case 0x0c065f50u: goto P_0c065f50;
case 0x0c065f52u: goto P_0c065f52;
case 0x0c065f54u: goto P_0c065f54;
case 0x0c065f56u: goto P_0c065f56;
case 0x0c065f58u: goto P_0c065f58;
case 0x0c065f5au: goto P_0c065f5a;
case 0x0c065f5cu: goto P_0c065f5c;
case 0x0c065f5eu: goto P_0c065f5e;
case 0x0c065f60u: goto P_0c065f60;
case 0x0c065f62u: goto P_0c065f62;
case 0x0c065f64u: goto P_0c065f64;
case 0x0c065f66u: goto P_0c065f66;
case 0x0c065f68u: goto P_0c065f68;
case 0x0c065f6au: goto P_0c065f6a;
case 0x0c065f6cu: goto P_0c065f6c;
case 0x0c065f6eu: goto P_0c065f6e;
case 0x0c065f70u: goto P_0c065f70;
case 0x0c065f72u: goto P_0c065f72;
case 0x0c065f74u: goto P_0c065f74;
case 0x0c065f76u: goto P_0c065f76;
case 0x0c065f78u: goto P_0c065f78;
case 0x0c065f7au: goto P_0c065f7a;
case 0x0c065f7cu: goto P_0c065f7c;
case 0x0c065f7eu: goto P_0c065f7e;
case 0x0c065f80u: goto P_0c065f80;
case 0x0c065f82u: goto P_0c065f82;
case 0x0c065f84u: goto P_0c065f84;
case 0x0c065f86u: goto P_0c065f86;
case 0x0c065f88u: goto P_0c065f88;
case 0x0c065f8au: goto P_0c065f8a;
case 0x0c065f8cu: goto P_0c065f8c;
case 0x0c065f8eu: goto P_0c065f8e;
case 0x0c065f90u: goto P_0c065f90;
case 0x0c065f92u: goto P_0c065f92;
case 0x0c065f94u: goto P_0c065f94;
case 0x0c065f96u: goto P_0c065f96;
case 0x0c065f98u: goto P_0c065f98;
case 0x0c065f9au: goto P_0c065f9a;
case 0x0c065f9cu: goto P_0c065f9c;
case 0x0c065f9eu: goto P_0c065f9e;
case 0x0c065fa0u: goto P_0c065fa0;
case 0x0c065fa2u: goto P_0c065fa2;
case 0x0c065fa4u: goto P_0c065fa4;
case 0x0c065fa6u: goto P_0c065fa6;
case 0x0c065fa8u: goto P_0c065fa8;
case 0x0c065faau: goto P_0c065faa;
case 0x0c065facu: goto P_0c065fac;
case 0x0c065faeu: goto P_0c065fae;
case 0x0c065fb0u: goto P_0c065fb0;
case 0x0c065fb2u: goto P_0c065fb2;
case 0x0c065fb4u: goto P_0c065fb4;
case 0x0c065fb6u: goto P_0c065fb6;
case 0x0c065fb8u: goto P_0c065fb8;
case 0x0c065fbau: goto P_0c065fba;
case 0x0c065fbcu: goto P_0c065fbc;
case 0x0c065fbeu: goto P_0c065fbe;
case 0x0c065fc0u: goto P_0c065fc0;
case 0x0c065fc2u: goto P_0c065fc2;
case 0x0c065fc4u: goto P_0c065fc4;
case 0x0c065fc6u: goto P_0c065fc6;
case 0x0c065fc8u: goto P_0c065fc8;
case 0x0c065fcau: goto P_0c065fca;
case 0x0c065fccu: goto P_0c065fcc;
case 0x0c065fceu: goto P_0c065fce;
case 0x0c065fd0u: goto P_0c065fd0;
case 0x0c065fd2u: goto P_0c065fd2;
case 0x0c065fd4u: goto P_0c065fd4;
case 0x0c065fd6u: goto P_0c065fd6;
case 0x0c065fd8u: goto P_0c065fd8;
case 0x0c065fdau: goto P_0c065fda;
case 0x0c065fdcu: goto P_0c065fdc;
case 0x0c065fdeu: goto P_0c065fde;
case 0x0c065fe0u: goto P_0c065fe0;
case 0x0c065fe2u: goto P_0c065fe2;
case 0x0c065fe4u: goto P_0c065fe4;
case 0x0c065fe6u: goto P_0c065fe6;
case 0x0c065fe8u: goto P_0c065fe8;
case 0x0c065feau: goto P_0c065fea;
case 0x0c065fecu: goto P_0c065fec;
case 0x0c065feeu: goto P_0c065fee;
case 0x0c065ff0u: goto P_0c065ff0;
case 0x0c065ff2u: goto P_0c065ff2;
case 0x0c065ff4u: goto P_0c065ff4;
case 0x0c065ff6u: goto P_0c065ff6;
case 0x0c065ff8u: goto P_0c065ff8;
case 0x0c065ffau: goto P_0c065ffa;
case 0x0c065ffcu: goto P_0c065ffc;
case 0x0c065ffeu: goto P_0c065ffe;
case 0x0c066000u: goto P_0c066000;
case 0x0c066002u: goto P_0c066002;
case 0x0c066004u: goto P_0c066004;
case 0x0c066006u: goto P_0c066006;
case 0x0c066008u: goto P_0c066008;
case 0x0c06600au: goto P_0c06600a;
case 0x0c06600cu: goto P_0c06600c;
case 0x0c06604cu: goto P_0c06604c;
case 0x0c06604eu: goto P_0c06604e;
case 0x0c066050u: goto P_0c066050;
case 0x0c066052u: goto P_0c066052;
case 0x0c066054u: goto P_0c066054;
case 0x0c066056u: goto P_0c066056;
case 0x0c066058u: goto P_0c066058;
case 0x0c06605au: goto P_0c06605a;
case 0x0c06605cu: goto P_0c06605c;
case 0x0c06605eu: goto P_0c06605e;
case 0x0c066060u: goto P_0c066060;
case 0x0c066062u: goto P_0c066062;
case 0x0c066064u: goto P_0c066064;
case 0x0c066066u: goto P_0c066066;
case 0x0c066068u: goto P_0c066068;
case 0x0c06606au: goto P_0c06606a;
case 0x0c06606cu: goto P_0c06606c;
case 0x0c06606eu: goto P_0c06606e;
case 0x0c066070u: goto P_0c066070;
case 0x0c066072u: goto P_0c066072;
case 0x0c066074u: goto P_0c066074;
case 0x0c066076u: goto P_0c066076;
case 0x0c066078u: goto P_0c066078;
case 0x0c06607au: goto P_0c06607a;
case 0x0c06607cu: goto P_0c06607c;
case 0x0c06607eu: goto P_0c06607e;
case 0x0c066080u: goto P_0c066080;
case 0x0c066082u: goto P_0c066082;
case 0x0c066084u: goto P_0c066084;
case 0x0c066086u: goto P_0c066086;
case 0x0c066088u: goto P_0c066088;
case 0x0c06608au: goto P_0c06608a;
case 0x0c06608cu: goto P_0c06608c;
case 0x0c06608eu: goto P_0c06608e;
case 0x0c066090u: goto P_0c066090;
case 0x0c066092u: goto P_0c066092;
case 0x0c066094u: goto P_0c066094;
case 0x0c066096u: goto P_0c066096;
case 0x0c066098u: goto P_0c066098;
case 0x0c06609au: goto P_0c06609a;
case 0x0c06609cu: goto P_0c06609c;
case 0x0c06609eu: goto P_0c06609e;
case 0x0c0660a0u: goto P_0c0660a0;
case 0x0c0660a2u: goto P_0c0660a2;
case 0x0c0660a4u: goto P_0c0660a4;
case 0x0c0660a6u: goto P_0c0660a6;
case 0x0c0660a8u: goto P_0c0660a8;
case 0x0c0660aau: goto P_0c0660aa;
case 0x0c0660acu: goto P_0c0660ac;
case 0x0c0660aeu: goto P_0c0660ae;
case 0x0c0660b0u: goto P_0c0660b0;
case 0x0c0660b2u: goto P_0c0660b2;
case 0x0c0660b4u: goto P_0c0660b4;
case 0x0c0660b6u: goto P_0c0660b6;
case 0x0c0660b8u: goto P_0c0660b8;
case 0x0c0660bau: goto P_0c0660ba;
case 0x0c0660bcu: goto P_0c0660bc;
case 0x0c0660beu: goto P_0c0660be;
case 0x0c0660c0u: goto P_0c0660c0;
case 0x0c0660c2u: goto P_0c0660c2;
case 0x0c0660c4u: goto P_0c0660c4;
case 0x0c0660c6u: goto P_0c0660c6;
case 0x0c0660c8u: goto P_0c0660c8;
case 0x0c0660cau: goto P_0c0660ca;
case 0x0c0660ccu: goto P_0c0660cc;
case 0x0c0660ceu: goto P_0c0660ce;
case 0x0c0660d0u: goto P_0c0660d0;
case 0x0c0660d2u: goto P_0c0660d2;
case 0x0c0660d4u: goto P_0c0660d4;
case 0x0c0660d6u: goto P_0c0660d6;
case 0x0c0660d8u: goto P_0c0660d8;
case 0x0c0660dau: goto P_0c0660da;
case 0x0c0660dcu: goto P_0c0660dc;
case 0x0c0660deu: goto P_0c0660de;
case 0x0c0660e0u: goto P_0c0660e0;
case 0x0c0660e2u: goto P_0c0660e2;
case 0x0c0660e4u: goto P_0c0660e4;
case 0x0c0660e6u: goto P_0c0660e6;
case 0x0c0660e8u: goto P_0c0660e8;
case 0x0c0660eau: goto P_0c0660ea;
case 0x0c0660ecu: goto P_0c0660ec;
case 0x0c0660eeu: goto P_0c0660ee;
case 0x0c0660f0u: goto P_0c0660f0;
case 0x0c0660f2u: goto P_0c0660f2;
case 0x0c0660f4u: goto P_0c0660f4;
case 0x0c0660f6u: goto P_0c0660f6;
case 0x0c0660f8u: goto P_0c0660f8;
case 0x0c0660fau: goto P_0c0660fa;
case 0x0c0660fcu: goto P_0c0660fc;
case 0x0c0660feu: goto P_0c0660fe;
case 0x0c066100u: goto P_0c066100;
case 0x0c066102u: goto P_0c066102;
case 0x0c066104u: goto P_0c066104;
case 0x0c066106u: goto P_0c066106;
case 0x0c066108u: goto P_0c066108;
case 0x0c06610au: goto P_0c06610a;
case 0x0c06610cu: goto P_0c06610c;
case 0x0c06610eu: goto P_0c06610e;
case 0x0c066110u: goto P_0c066110;
case 0x0c066112u: goto P_0c066112;
case 0x0c066114u: goto P_0c066114;
case 0x0c066116u: goto P_0c066116;
case 0x0c066118u: goto P_0c066118;
case 0x0c06611au: goto P_0c06611a;
case 0x0c06611cu: goto P_0c06611c;
case 0x0c06611eu: goto P_0c06611e;
case 0x0c066120u: goto P_0c066120;
case 0x0c066122u: goto P_0c066122;
case 0x0c066124u: goto P_0c066124;
case 0x0c066126u: goto P_0c066126;
case 0x0c066128u: goto P_0c066128;
case 0x0c06612au: goto P_0c06612a;
case 0x0c06612cu: goto P_0c06612c;
case 0x0c06612eu: goto P_0c06612e;
case 0x0c066130u: goto P_0c066130;
case 0x0c066132u: goto P_0c066132;
case 0x0c066134u: goto P_0c066134;
case 0x0c066136u: goto P_0c066136;
case 0x0c066138u: goto P_0c066138;
case 0x0c06613au: goto P_0c06613a;
case 0x0c06613cu: goto P_0c06613c;
case 0x0c06613eu: goto P_0c06613e;
case 0x0c066140u: goto P_0c066140;
case 0x0c066142u: goto P_0c066142;
case 0x0c066144u: goto P_0c066144;
case 0x0c066146u: goto P_0c066146;
case 0x0c066148u: goto P_0c066148;
case 0x0c06614au: goto P_0c06614a;
case 0x0c06614cu: goto P_0c06614c;
case 0x0c06614eu: goto P_0c06614e;
case 0x0c066150u: goto P_0c066150;
case 0x0c066152u: goto P_0c066152;
case 0x0c066154u: goto P_0c066154;
case 0x0c066156u: goto P_0c066156;
case 0x0c066158u: goto P_0c066158;
case 0x0c06615au: goto P_0c06615a;
case 0x0c06615cu: goto P_0c06615c;
case 0x0c06615eu: goto P_0c06615e;
case 0x0c066160u: goto P_0c066160;
case 0x0c066162u: goto P_0c066162;
case 0x0c066164u: goto P_0c066164;
case 0x0c066166u: goto P_0c066166;
case 0x0c066168u: goto P_0c066168;
case 0x0c06616au: goto P_0c06616a;
case 0x0c06616cu: goto P_0c06616c;
case 0x0c06616eu: goto P_0c06616e;
case 0x0c066170u: goto P_0c066170;
case 0x0c066172u: goto P_0c066172;
case 0x0c066174u: goto P_0c066174;
case 0x0c066176u: goto P_0c066176;
case 0x0c066178u: goto P_0c066178;
case 0x0c06617au: goto P_0c06617a;
case 0x0c06617cu: goto P_0c06617c;
case 0x0c06617eu: goto P_0c06617e;
case 0x0c066180u: goto P_0c066180;
case 0x0c066182u: goto P_0c066182;
case 0x0c066184u: goto P_0c066184;
case 0x0c066186u: goto P_0c066186;
case 0x0c066188u: goto P_0c066188;
case 0x0c06618au: goto P_0c06618a;
case 0x0c06618cu: goto P_0c06618c;
case 0x0c06618eu: goto P_0c06618e;
case 0x0c066190u: goto P_0c066190;
case 0x0c066192u: goto P_0c066192;
case 0x0c066194u: goto P_0c066194;
case 0x0c066196u: goto P_0c066196;
case 0x0c066198u: goto P_0c066198;
case 0x0c06619au: goto P_0c06619a;
case 0x0c06619cu: goto P_0c06619c;
case 0x0c06619eu: goto P_0c06619e;
case 0x0c0661a0u: goto P_0c0661a0;
case 0x0c0661a2u: goto P_0c0661a2;
case 0x0c0661a4u: goto P_0c0661a4;
case 0x0c0661a6u: goto P_0c0661a6;
case 0x0c0661a8u: goto P_0c0661a8;
case 0x0c0661aau: goto P_0c0661aa;
case 0x0c0661acu: goto P_0c0661ac;
case 0x0c0661aeu: goto P_0c0661ae;
case 0x0c0661b0u: goto P_0c0661b0;
case 0x0c0661b2u: goto P_0c0661b2;
case 0x0c0661b4u: goto P_0c0661b4;
case 0x0c0661b6u: goto P_0c0661b6;
case 0x0c0661b8u: goto P_0c0661b8;
case 0x0c0661bau: goto P_0c0661ba;
case 0x0c0661bcu: goto P_0c0661bc;
case 0x0c0661beu: goto P_0c0661be;
case 0x0c0661c0u: goto P_0c0661c0;
case 0x0c0661c2u: goto P_0c0661c2;
case 0x0c0661c4u: goto P_0c0661c4;
case 0x0c0661c6u: goto P_0c0661c6;
case 0x0c0661c8u: goto P_0c0661c8;
case 0x0c0661cau: goto P_0c0661ca;
case 0x0c0661ccu: goto P_0c0661cc;
case 0x0c0661ceu: goto P_0c0661ce;
case 0x0c0661d0u: goto P_0c0661d0;
case 0x0c0661d2u: goto P_0c0661d2;
case 0x0c0661d4u: goto P_0c0661d4;
case 0x0c0661d6u: goto P_0c0661d6;
case 0x0c0661d8u: goto P_0c0661d8;
case 0x0c0661dau: goto P_0c0661da;
case 0x0c0661dcu: goto P_0c0661dc;
case 0x0c0661deu: goto P_0c0661de;
case 0x0c0661e0u: goto P_0c0661e0;
case 0x0c0661e2u: goto P_0c0661e2;
case 0x0c0661e4u: goto P_0c0661e4;
case 0x0c0661e6u: goto P_0c0661e6;
case 0x0c0661e8u: goto P_0c0661e8;
case 0x0c0661eau: goto P_0c0661ea;
case 0x0c0661ecu: goto P_0c0661ec;
case 0x0c0661eeu: goto P_0c0661ee;
case 0x0c0661f0u: goto P_0c0661f0;
case 0x0c0661f2u: goto P_0c0661f2;
case 0x0c0661f4u: goto P_0c0661f4;
case 0x0c0661f6u: goto P_0c0661f6;
case 0x0c0661f8u: goto P_0c0661f8;
case 0x0c0661fau: goto P_0c0661fa;
case 0x0c0661fcu: goto P_0c0661fc;
case 0x0c0661feu: goto P_0c0661fe;
case 0x0c066200u: goto P_0c066200;
case 0x0c066202u: goto P_0c066202;
case 0x0c066204u: goto P_0c066204;
case 0x0c066206u: goto P_0c066206;
case 0x0c066208u: goto P_0c066208;
case 0x0c06620au: goto P_0c06620a;
case 0x0c06620cu: goto P_0c06620c;
case 0x0c06620eu: goto P_0c06620e;
case 0x0c066210u: goto P_0c066210;
case 0x0c066212u: goto P_0c066212;
case 0x0c066214u: goto P_0c066214;
case 0x0c066216u: goto P_0c066216;
case 0x0c066218u: goto P_0c066218;
case 0x0c06621au: goto P_0c06621a;
case 0x0c06621cu: goto P_0c06621c;
case 0x0c06621eu: goto P_0c06621e;
case 0x0c066220u: goto P_0c066220;
case 0x0c066222u: goto P_0c066222;
case 0x0c066224u: goto P_0c066224;
case 0x0c066226u: goto P_0c066226;
case 0x0c066228u: goto P_0c066228;
case 0x0c06622au: goto P_0c06622a;
case 0x0c06622cu: goto P_0c06622c;
case 0x0c06622eu: goto P_0c06622e;
case 0x0c066230u: goto P_0c066230;
case 0x0c066232u: goto P_0c066232;
case 0x0c066234u: goto P_0c066234;
case 0x0c066236u: goto P_0c066236;
case 0x0c066238u: goto P_0c066238;
case 0x0c06623au: goto P_0c06623a;
case 0x0c06623cu: goto P_0c06623c;
case 0x0c06623eu: goto P_0c06623e;
case 0x0c066240u: goto P_0c066240;
case 0x0c066242u: goto P_0c066242;
case 0x0c066244u: goto P_0c066244;
case 0x0c066246u: goto P_0c066246;
case 0x0c066248u: goto P_0c066248;
case 0x0c06624au: goto P_0c06624a;
case 0x0c06624cu: goto P_0c06624c;
case 0x0c06624eu: goto P_0c06624e;
case 0x0c066250u: goto P_0c066250;
case 0x0c066252u: goto P_0c066252;
case 0x0c066254u: goto P_0c066254;
case 0x0c066256u: goto P_0c066256;
case 0x0c066258u: goto P_0c066258;
case 0x0c06625au: goto P_0c06625a;
case 0x0c06625cu: goto P_0c06625c;
case 0x0c06625eu: goto P_0c06625e;
case 0x0c066260u: goto P_0c066260;
default: return vf3_matrix_family(target,s,ram);
}
P_0c064530: /* original d375, guest PC 0x0c064530 */
if(!s->budget--) { s->failed_pc=0x0c064530u; return 0; }
r[3]=read(ram,0x0c064708u,4);
goto P_0c064532;
P_0c064532: /* original 2438, guest PC 0x0c064532 */
if(!s->budget--) { s->failed_pc=0x0c064532u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c064534;
P_0c064534: /* original 8904, guest PC 0x0c064534 */
if(!s->budget--) { s->failed_pc=0x0c064534u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064540; }
goto P_0c064536;
P_0c064536: /* original 6153, guest PC 0x0c064536 */
if(!s->budget--) { s->failed_pc=0x0c064536u; return 0; }
r[1]=r[5];
goto P_0c064538;
P_0c064538: /* original d075, guest PC 0x0c064538 */
if(!s->budget--) { s->failed_pc=0x0c064538u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c06453a;
P_0c06453a: /* original 7501, guest PC 0x0c06453a */
if(!s->budget--) { s->failed_pc=0x0c06453au; return 0; }
r[5]+=0x00000001u;
goto P_0c06453c;
P_0c06453c: /* original 4108, guest PC 0x0c06453c */
if(!s->budget--) { s->failed_pc=0x0c06453cu; return 0; }
r[1]<<=2;
goto P_0c06453e;
P_0c06453e: /* original 0166, guest PC 0x0c06453e */
if(!s->budget--) { s->failed_pc=0x0c06453eu; return 0; }
write(ram,r[1]+r[0],r[6],4);
goto P_0c064540;
P_0c064540: /* original 000b, guest PC 0x0c064540 */
if(!s->budget--) { s->failed_pc=0x0c064540u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c064542: /* original 6053, guest PC 0x0c064542 */
if(!s->budget--) { s->failed_pc=0x0c064542u; return 0; }
r[0]=r[5];
goto P_0c064544;
P_0c064544: /* original d36f, guest PC 0x0c064544 */
if(!s->budget--) { s->failed_pc=0x0c064544u; return 0; }
r[3]=read(ram,0x0c064704u,4);
goto P_0c064546;
P_0c064546: /* original 2348, guest PC 0x0c064546 */
if(!s->budget--) { s->failed_pc=0x0c064546u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c064548;
P_0c064548: /* original 8914, guest PC 0x0c064548 */
if(!s->budget--) { s->failed_pc=0x0c064548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064574; }
goto P_0c06454a;
P_0c06454a: /* original d170, guest PC 0x0c06454a */
if(!s->budget--) { s->failed_pc=0x0c06454au; return 0; }
r[1]=read(ram,0x0c06470cu,4);
goto P_0c06454c;
P_0c06454c: /* original 2418, guest PC 0x0c06454c */
if(!s->budget--) { s->failed_pc=0x0c06454cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c06454e;
P_0c06454e: /* original 8904, guest PC 0x0c06454e */
if(!s->budget--) { s->failed_pc=0x0c06454eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06455a; }
goto P_0c064550;
P_0c064550: /* original d06f, guest PC 0x0c064550 */
if(!s->budget--) { s->failed_pc=0x0c064550u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064552;
P_0c064552: /* original 6253, guest PC 0x0c064552 */
if(!s->budget--) { s->failed_pc=0x0c064552u; return 0; }
r[2]=r[5];
goto P_0c064554;
P_0c064554: /* original 7501, guest PC 0x0c064554 */
if(!s->budget--) { s->failed_pc=0x0c064554u; return 0; }
r[5]+=0x00000001u;
goto P_0c064556;
P_0c064556: /* original a00c, guest PC 0x0c064556 */
if(!s->budget--) { s->failed_pc=0x0c064556u; return 0; }
r[2]<<=2;
goto P_0c064572;
P_0c064558: /* original 4208, guest PC 0x0c064558 */
if(!s->budget--) { s->failed_pc=0x0c064558u; return 0; }
r[2]<<=2;
goto P_0c06455a;
P_0c06455a: /* original 6253, guest PC 0x0c06455a */
if(!s->budget--) { s->failed_pc=0x0c06455au; return 0; }
r[2]=r[5];
goto P_0c06455c;
P_0c06455c: /* original d36d, guest PC 0x0c06455c */
if(!s->budget--) { s->failed_pc=0x0c06455cu; return 0; }
r[3]=read(ram,0x0c064714u,4);
goto P_0c06455e;
P_0c06455e: /* original 7501, guest PC 0x0c06455e */
if(!s->budget--) { s->failed_pc=0x0c06455eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064560;
P_0c064560: /* original d06b, guest PC 0x0c064560 */
if(!s->budget--) { s->failed_pc=0x0c064560u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064562;
P_0c064562: /* original 4208, guest PC 0x0c064562 */
if(!s->budget--) { s->failed_pc=0x0c064562u; return 0; }
r[2]<<=2;
goto P_0c064564;
P_0c064564: /* original 2369, guest PC 0x0c064564 */
if(!s->budget--) { s->failed_pc=0x0c064564u; return 0; }
r[3]&=r[6];
goto P_0c064566;
P_0c064566: /* original 0236, guest PC 0x0c064566 */
if(!s->budget--) { s->failed_pc=0x0c064566u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064568;
P_0c064568: /* original 6253, guest PC 0x0c064568 */
if(!s->budget--) { s->failed_pc=0x0c064568u; return 0; }
r[2]=r[5];
goto P_0c06456a;
P_0c06456a: /* original 7501, guest PC 0x0c06456a */
if(!s->budget--) { s->failed_pc=0x0c06456au; return 0; }
r[5]+=0x00000001u;
goto P_0c06456c;
P_0c06456c: /* original 4208, guest PC 0x0c06456c */
if(!s->budget--) { s->failed_pc=0x0c06456cu; return 0; }
r[2]<<=2;
goto P_0c06456e;
P_0c06456e: /* original 666d, guest PC 0x0c06456e */
if(!s->budget--) { s->failed_pc=0x0c06456eu; return 0; }
r[6]=r[6]&65535u;
goto P_0c064570;
P_0c064570: /* original 4628, guest PC 0x0c064570 */
if(!s->budget--) { s->failed_pc=0x0c064570u; return 0; }
r[6]<<=16;
goto P_0c064572;
P_0c064572: /* original 0266, guest PC 0x0c064572 */
if(!s->budget--) { s->failed_pc=0x0c064572u; return 0; }
write(ram,r[2]+r[0],r[6],4);
goto P_0c064574;
P_0c064574: /* original 000b, guest PC 0x0c064574 */
if(!s->budget--) { s->failed_pc=0x0c064574u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c064576: /* original 6053, guest PC 0x0c064576 */
if(!s->budget--) { s->failed_pc=0x0c064576u; return 0; }
r[0]=r[5];
goto P_0c064578;
P_0c064578: /* original d362, guest PC 0x0c064578 */
if(!s->budget--) { s->failed_pc=0x0c064578u; return 0; }
r[3]=read(ram,0x0c064704u,4);
goto P_0c06457a;
P_0c06457a: /* original 2438, guest PC 0x0c06457a */
if(!s->budget--) { s->failed_pc=0x0c06457au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06457c;
P_0c06457c: /* original 8908, guest PC 0x0c06457c */
if(!s->budget--) { s->failed_pc=0x0c06457cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064590; }
goto P_0c06457e;
P_0c06457e: /* original 6153, guest PC 0x0c06457e */
if(!s->budget--) { s->failed_pc=0x0c06457eu; return 0; }
r[1]=r[5];
goto P_0c064580;
P_0c064580: /* original d063, guest PC 0x0c064580 */
if(!s->budget--) { s->failed_pc=0x0c064580u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064582;
P_0c064582: /* original 7501, guest PC 0x0c064582 */
if(!s->budget--) { s->failed_pc=0x0c064582u; return 0; }
r[5]+=0x00000001u;
goto P_0c064584;
P_0c064584: /* original 4108, guest PC 0x0c064584 */
if(!s->budget--) { s->failed_pc=0x0c064584u; return 0; }
r[1]<<=2;
goto P_0c064586;
P_0c064586: /* original 0166, guest PC 0x0c064586 */
if(!s->budget--) { s->failed_pc=0x0c064586u; return 0; }
write(ram,r[1]+r[0],r[6],4);
goto P_0c064588;
P_0c064588: /* original 6253, guest PC 0x0c064588 */
if(!s->budget--) { s->failed_pc=0x0c064588u; return 0; }
r[2]=r[5];
goto P_0c06458a;
P_0c06458a: /* original 7501, guest PC 0x0c06458a */
if(!s->budget--) { s->failed_pc=0x0c06458au; return 0; }
r[5]+=0x00000001u;
goto P_0c06458c;
P_0c06458c: /* original 4208, guest PC 0x0c06458c */
if(!s->budget--) { s->failed_pc=0x0c06458cu; return 0; }
r[2]<<=2;
goto P_0c06458e;
P_0c06458e: /* original 0276, guest PC 0x0c06458e */
if(!s->budget--) { s->failed_pc=0x0c06458eu; return 0; }
write(ram,r[2]+r[0],r[7],4);
goto P_0c064590;
P_0c064590: /* original 000b, guest PC 0x0c064590 */
if(!s->budget--) { s->failed_pc=0x0c064590u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c064592: /* original 6053, guest PC 0x0c064592 */
if(!s->budget--) { s->failed_pc=0x0c064592u; return 0; }
r[0]=r[5];
return vf3_matrix_family(0x0c064594u,s,ram);
P_0c064772: /* original 4f22, guest PC 0x0c064772 */
if(!s->budget--) { s->failed_pc=0x0c064772u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064774;
P_0c064774: /* original 7ff0, guest PC 0x0c064774 */
if(!s->budget--) { s->failed_pc=0x0c064774u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c064776;
P_0c064776: /* original 6df3, guest PC 0x0c064776 */
if(!s->budget--) { s->failed_pc=0x0c064776u; return 0; }
r[13]=r[15];
goto P_0c064778;
P_0c064778: /* original 6342, guest PC 0x0c064778 */
if(!s->budget--) { s->failed_pc=0x0c064778u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c06477a;
P_0c06477a: /* original 7d04, guest PC 0x0c06477a */
if(!s->budget--) { s->failed_pc=0x0c06477au; return 0; }
r[13]+=0x00000004u;
goto P_0c06477c;
P_0c06477c: /* original 6ed3, guest PC 0x0c06477c */
if(!s->budget--) { s->failed_pc=0x0c06477cu; return 0; }
r[14]=r[13];
goto P_0c06477e;
P_0c06477e: /* original 66e3, guest PC 0x0c06477e */
if(!s->budget--) { s->failed_pc=0x0c06477eu; return 0; }
r[6]=r[14];
goto P_0c064780;
P_0c064780: /* original 2e32, guest PC 0x0c064780 */
if(!s->budget--) { s->failed_pc=0x0c064780u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c064782;
P_0c064782: /* original 67e3, guest PC 0x0c064782 */
if(!s->budget--) { s->failed_pc=0x0c064782u; return 0; }
r[7]=r[14];
goto P_0c064784;
P_0c064784: /* original 5241, guest PC 0x0c064784 */
if(!s->budget--) { s->failed_pc=0x0c064784u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c064786;
P_0c064786: /* original 7604, guest PC 0x0c064786 */
if(!s->budget--) { s->failed_pc=0x0c064786u; return 0; }
r[6]+=0x00000004u;
goto P_0c064788;
P_0c064788: /* original 2622, guest PC 0x0c064788 */
if(!s->budget--) { s->failed_pc=0x0c064788u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c06478a;
P_0c06478a: /* original 7708, guest PC 0x0c06478a */
if(!s->budget--) { s->failed_pc=0x0c06478au; return 0; }
r[7]+=0x00000008u;
goto P_0c06478c;
P_0c06478c: /* original 5342, guest PC 0x0c06478c */
if(!s->budget--) { s->failed_pc=0x0c06478cu; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c06478e;
P_0c06478e: /* original 2732, guest PC 0x0c06478e */
if(!s->budget--) { s->failed_pc=0x0c06478eu; return 0; }
write(ram,r[7],r[3],4);
goto P_0c064790;
P_0c064790: /* original d2bf, guest PC 0x0c064790 */
if(!s->budget--) { s->failed_pc=0x0c064790u; return 0; }
r[2]=read(ram,0x0c064a90u,4);
goto P_0c064792;
P_0c064792: /* original 6d22, guest PC 0x0c064792 */
if(!s->budget--) { s->failed_pc=0x0c064792u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c064794;
P_0c064794: /* original d1bf, guest PC 0x0c064794 */
if(!s->budget--) { s->failed_pc=0x0c064794u; return 0; }
r[1]=read(ram,0x0c064a94u,4);
goto P_0c064796;
P_0c064796: /* original 6312, guest PC 0x0c064796 */
if(!s->budget--) { s->failed_pc=0x0c064796u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c064798;
P_0c064798: /* original 2f32, guest PC 0x0c064798 */
if(!s->budget--) { s->failed_pc=0x0c064798u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06479a;
P_0c06479a: /* original d3bf, guest PC 0x0c06479a */
if(!s->budget--) { s->failed_pc=0x0c06479au; return 0; }
r[3]=read(ram,0x0c064a98u,4);
goto P_0c06479c;
P_0c06479c: /* original 6432, guest PC 0x0c06479c */
if(!s->budget--) { s->failed_pc=0x0c06479cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c06479e;
P_0c06479e: /* original d0bf, guest PC 0x0c06479e */
if(!s->budget--) { s->failed_pc=0x0c06479eu; return 0; }
r[0]=read(ram,0x0c064a9cu,4);
goto P_0c0647a0;
P_0c0647a0: /* original 6253, guest PC 0x0c0647a0 */
if(!s->budget--) { s->failed_pc=0x0c0647a0u; return 0; }
r[2]=r[5];
goto P_0c0647a2;
P_0c0647a2: /* original 7501, guest PC 0x0c0647a2 */
if(!s->budget--) { s->failed_pc=0x0c0647a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0647a4;
P_0c0647a4: /* original 4208, guest PC 0x0c0647a4 */
if(!s->budget--) { s->failed_pc=0x0c0647a4u; return 0; }
r[2]<<=2;
goto P_0c0647a6;
P_0c0647a6: /* original 02d6, guest PC 0x0c0647a6 */
if(!s->budget--) { s->failed_pc=0x0c0647a6u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c0647a8;
P_0c0647a8: /* original 6153, guest PC 0x0c0647a8 */
if(!s->budget--) { s->failed_pc=0x0c0647a8u; return 0; }
r[1]=r[5];
goto P_0c0647aa;
P_0c0647aa: /* original 7501, guest PC 0x0c0647aa */
if(!s->budget--) { s->failed_pc=0x0c0647aau; return 0; }
r[5]+=0x00000001u;
goto P_0c0647ac;
P_0c0647ac: /* original 62f2, guest PC 0x0c0647ac */
if(!s->budget--) { s->failed_pc=0x0c0647acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0647ae;
P_0c0647ae: /* original 4108, guest PC 0x0c0647ae */
if(!s->budget--) { s->failed_pc=0x0c0647aeu; return 0; }
r[1]<<=2;
goto P_0c0647b0;
P_0c0647b0: /* original 0126, guest PC 0x0c0647b0 */
if(!s->budget--) { s->failed_pc=0x0c0647b0u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c0647b2;
P_0c0647b2: /* original 6153, guest PC 0x0c0647b2 */
if(!s->budget--) { s->failed_pc=0x0c0647b2u; return 0; }
r[1]=r[5];
goto P_0c0647b4;
P_0c0647b4: /* original 7501, guest PC 0x0c0647b4 */
if(!s->budget--) { s->failed_pc=0x0c0647b4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0647b6;
P_0c0647b6: /* original 4108, guest PC 0x0c0647b6 */
if(!s->budget--) { s->failed_pc=0x0c0647b6u; return 0; }
r[1]<<=2;
goto P_0c0647b8;
P_0c0647b8: /* original 0146, guest PC 0x0c0647b8 */
if(!s->budget--) { s->failed_pc=0x0c0647b8u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c0647ba;
P_0c0647ba: /* original 6253, guest PC 0x0c0647ba */
if(!s->budget--) { s->failed_pc=0x0c0647bau; return 0; }
r[2]=r[5];
goto P_0c0647bc;
P_0c0647bc: /* original 61e2, guest PC 0x0c0647bc */
if(!s->budget--) { s->failed_pc=0x0c0647bcu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0647be;
P_0c0647be: /* original 7501, guest PC 0x0c0647be */
if(!s->budget--) { s->failed_pc=0x0c0647beu; return 0; }
r[5]+=0x00000001u;
goto P_0c0647c0;
P_0c0647c0: /* original 5111, guest PC 0x0c0647c0 */
if(!s->budget--) { s->failed_pc=0x0c0647c0u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c0647c2;
P_0c0647c2: /* original 4208, guest PC 0x0c0647c2 */
if(!s->budget--) { s->failed_pc=0x0c0647c2u; return 0; }
r[2]<<=2;
goto P_0c0647c4;
P_0c0647c4: /* original 0216, guest PC 0x0c0647c4 */
if(!s->budget--) { s->failed_pc=0x0c0647c4u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0647c6;
P_0c0647c6: /* original 6253, guest PC 0x0c0647c6 */
if(!s->budget--) { s->failed_pc=0x0c0647c6u; return 0; }
r[2]=r[5];
goto P_0c0647c8;
P_0c0647c8: /* original 61e2, guest PC 0x0c0647c8 */
if(!s->budget--) { s->failed_pc=0x0c0647c8u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0647ca;
P_0c0647ca: /* original 7501, guest PC 0x0c0647ca */
if(!s->budget--) { s->failed_pc=0x0c0647cau; return 0; }
r[5]+=0x00000001u;
goto P_0c0647cc;
P_0c0647cc: /* original 5112, guest PC 0x0c0647cc */
if(!s->budget--) { s->failed_pc=0x0c0647ccu; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c0647ce;
P_0c0647ce: /* original 4208, guest PC 0x0c0647ce */
if(!s->budget--) { s->failed_pc=0x0c0647ceu; return 0; }
r[2]<<=2;
goto P_0c0647d0;
P_0c0647d0: /* original 0216, guest PC 0x0c0647d0 */
if(!s->budget--) { s->failed_pc=0x0c0647d0u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0647d2;
P_0c0647d2: /* original 6253, guest PC 0x0c0647d2 */
if(!s->budget--) { s->failed_pc=0x0c0647d2u; return 0; }
r[2]=r[5];
goto P_0c0647d4;
P_0c0647d4: /* original 61e2, guest PC 0x0c0647d4 */
if(!s->budget--) { s->failed_pc=0x0c0647d4u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0647d6;
P_0c0647d6: /* original 7501, guest PC 0x0c0647d6 */
if(!s->budget--) { s->failed_pc=0x0c0647d6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0647d8;
P_0c0647d8: /* original 5113, guest PC 0x0c0647d8 */
if(!s->budget--) { s->failed_pc=0x0c0647d8u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c0647da;
P_0c0647da: /* original 4208, guest PC 0x0c0647da */
if(!s->budget--) { s->failed_pc=0x0c0647dau; return 0; }
r[2]<<=2;
goto P_0c0647dc;
P_0c0647dc: /* original 0216, guest PC 0x0c0647dc */
if(!s->budget--) { s->failed_pc=0x0c0647dcu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0647de;
P_0c0647de: /* original 6253, guest PC 0x0c0647de */
if(!s->budget--) { s->failed_pc=0x0c0647deu; return 0; }
r[2]=r[5];
goto P_0c0647e0;
P_0c0647e0: /* original c7af, guest PC 0x0c0647e0 */
if(!s->budget--) { s->failed_pc=0x0c0647e0u; return 0; }
r[0]=0x0c064aa0u;
goto P_0c0647e2;
P_0c0647e2: /* original 7501, guest PC 0x0c0647e2 */
if(!s->budget--) { s->failed_pc=0x0c0647e2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0647e4;
P_0c0647e4: /* original f408, guest PC 0x0c0647e4 */
if(!s->budget--) { s->failed_pc=0x0c0647e4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0647e6;
P_0c0647e6: /* original 4208, guest PC 0x0c0647e6 */
if(!s->budget--) { s->failed_pc=0x0c0647e6u; return 0; }
r[2]<<=2;
goto P_0c0647e8;
P_0c0647e8: /* original d0ac, guest PC 0x0c0647e8 */
if(!s->budget--) { s->failed_pc=0x0c0647e8u; return 0; }
r[0]=read(ram,0x0c064a9cu,4);
goto P_0c0647ea;
P_0c0647ea: /* original e110, guest PC 0x0c0647ea */
if(!s->budget--) { s->failed_pc=0x0c0647eau; return 0; }
r[1]=0x00000010u;
goto P_0c0647ec;
P_0c0647ec: /* original 64e2, guest PC 0x0c0647ec */
if(!s->budget--) { s->failed_pc=0x0c0647ecu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0647ee;
P_0c0647ee: /* original e314, guest PC 0x0c0647ee */
if(!s->budget--) { s->failed_pc=0x0c0647eeu; return 0; }
r[3]=0x00000014u;
goto P_0c0647f0;
P_0c0647f0: /* original 314c, guest PC 0x0c0647f0 */
if(!s->budget--) { s->failed_pc=0x0c0647f0u; return 0; }
r[1]+=r[4];
goto P_0c0647f2;
P_0c0647f2: /* original 334c, guest PC 0x0c0647f2 */
if(!s->budget--) { s->failed_pc=0x0c0647f2u; return 0; }
r[3]+=r[4];
goto P_0c0647f4;
P_0c0647f4: /* original f318, guest PC 0x0c0647f4 */
if(!s->budget--) { s->failed_pc=0x0c0647f4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0647f6;
P_0c0647f6: /* original f342, guest PC 0x0c0647f6 */
if(!s->budget--) { s->failed_pc=0x0c0647f6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0647f8;
P_0c0647f8: /* original f33d, guest PC 0x0c0647f8 */
if(!s->budget--) { s->failed_pc=0x0c0647f8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0647fa;
P_0c0647fa: /* original 015a, guest PC 0x0c0647fa */
if(!s->budget--) { s->failed_pc=0x0c0647fau; return 0; }
r[1]=r[53];
goto P_0c0647fc;
P_0c0647fc: /* original f338, guest PC 0x0c0647fc */
if(!s->budget--) { s->failed_pc=0x0c0647fcu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0647fe;
P_0c0647fe: /* original 4128, guest PC 0x0c0647fe */
if(!s->budget--) { s->failed_pc=0x0c0647feu; return 0; }
r[1]<<=16;
goto P_0c064800;
P_0c064800: /* original 4118, guest PC 0x0c064800 */
if(!s->budget--) { s->failed_pc=0x0c064800u; return 0; }
r[1]<<=8;
goto P_0c064802;
P_0c064802: /* original f342, guest PC 0x0c064802 */
if(!s->budget--) { s->failed_pc=0x0c064802u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064804;
P_0c064804: /* original f33d, guest PC 0x0c064804 */
if(!s->budget--) { s->failed_pc=0x0c064804u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064806;
P_0c064806: /* original 035a, guest PC 0x0c064806 */
if(!s->budget--) { s->failed_pc=0x0c064806u; return 0; }
r[3]=r[53];
goto P_0c064808;
P_0c064808: /* original 4328, guest PC 0x0c064808 */
if(!s->budget--) { s->failed_pc=0x0c064808u; return 0; }
r[3]<<=16;
goto P_0c06480a;
P_0c06480a: /* original 213b, guest PC 0x0c06480a */
if(!s->budget--) { s->failed_pc=0x0c06480au; return 0; }
r[1]|=r[3];
goto P_0c06480c;
P_0c06480c: /* original e318, guest PC 0x0c06480c */
if(!s->budget--) { s->failed_pc=0x0c06480cu; return 0; }
r[3]=0x00000018u;
goto P_0c06480e;
P_0c06480e: /* original 334c, guest PC 0x0c06480e */
if(!s->budget--) { s->failed_pc=0x0c06480eu; return 0; }
r[3]+=r[4];
goto P_0c064810;
P_0c064810: /* original f338, guest PC 0x0c064810 */
if(!s->budget--) { s->failed_pc=0x0c064810u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c064812;
P_0c064812: /* original f342, guest PC 0x0c064812 */
if(!s->budget--) { s->failed_pc=0x0c064812u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064814;
P_0c064814: /* original f33d, guest PC 0x0c064814 */
if(!s->budget--) { s->failed_pc=0x0c064814u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064816;
P_0c064816: /* original 035a, guest PC 0x0c064816 */
if(!s->budget--) { s->failed_pc=0x0c064816u; return 0; }
r[3]=r[53];
goto P_0c064818;
P_0c064818: /* original 4318, guest PC 0x0c064818 */
if(!s->budget--) { s->failed_pc=0x0c064818u; return 0; }
r[3]<<=8;
goto P_0c06481a;
P_0c06481a: /* original 213b, guest PC 0x0c06481a */
if(!s->budget--) { s->failed_pc=0x0c06481au; return 0; }
r[1]|=r[3];
goto P_0c06481c;
P_0c06481c: /* original e31c, guest PC 0x0c06481c */
if(!s->budget--) { s->failed_pc=0x0c06481cu; return 0; }
r[3]=0x0000001cu;
goto P_0c06481e;
P_0c06481e: /* original 334c, guest PC 0x0c06481e */
if(!s->budget--) { s->failed_pc=0x0c06481eu; return 0; }
r[3]+=r[4];
goto P_0c064820;
P_0c064820: /* original f338, guest PC 0x0c064820 */
if(!s->budget--) { s->failed_pc=0x0c064820u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c064822;
P_0c064822: /* original f342, guest PC 0x0c064822 */
if(!s->budget--) { s->failed_pc=0x0c064822u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064824;
P_0c064824: /* original f33d, guest PC 0x0c064824 */
if(!s->budget--) { s->failed_pc=0x0c064824u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064826;
P_0c064826: /* original 035a, guest PC 0x0c064826 */
if(!s->budget--) { s->failed_pc=0x0c064826u; return 0; }
r[3]=r[53];
goto P_0c064828;
P_0c064828: /* original 213b, guest PC 0x0c064828 */
if(!s->budget--) { s->failed_pc=0x0c064828u; return 0; }
r[1]|=r[3];
goto P_0c06482a;
P_0c06482a: /* original 0216, guest PC 0x0c06482a */
if(!s->budget--) { s->failed_pc=0x0c06482au; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06482c;
P_0c06482c: /* original 6162, guest PC 0x0c06482c */
if(!s->budget--) { s->failed_pc=0x0c06482cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06482e;
P_0c06482e: /* original 6253, guest PC 0x0c06482e */
if(!s->budget--) { s->failed_pc=0x0c06482eu; return 0; }
r[2]=r[5];
goto P_0c064830;
P_0c064830: /* original 5311, guest PC 0x0c064830 */
if(!s->budget--) { s->failed_pc=0x0c064830u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064832;
P_0c064832: /* original 7501, guest PC 0x0c064832 */
if(!s->budget--) { s->failed_pc=0x0c064832u; return 0; }
r[5]+=0x00000001u;
goto P_0c064834;
P_0c064834: /* original 4208, guest PC 0x0c064834 */
if(!s->budget--) { s->failed_pc=0x0c064834u; return 0; }
r[2]<<=2;
goto P_0c064836;
P_0c064836: /* original 0236, guest PC 0x0c064836 */
if(!s->budget--) { s->failed_pc=0x0c064836u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064838;
P_0c064838: /* original 6162, guest PC 0x0c064838 */
if(!s->budget--) { s->failed_pc=0x0c064838u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06483a;
P_0c06483a: /* original 6253, guest PC 0x0c06483a */
if(!s->budget--) { s->failed_pc=0x0c06483au; return 0; }
r[2]=r[5];
goto P_0c06483c;
P_0c06483c: /* original 5312, guest PC 0x0c06483c */
if(!s->budget--) { s->failed_pc=0x0c06483cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c06483e;
P_0c06483e: /* original 7501, guest PC 0x0c06483e */
if(!s->budget--) { s->failed_pc=0x0c06483eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064840;
P_0c064840: /* original 4208, guest PC 0x0c064840 */
if(!s->budget--) { s->failed_pc=0x0c064840u; return 0; }
r[2]<<=2;
goto P_0c064842;
P_0c064842: /* original 0236, guest PC 0x0c064842 */
if(!s->budget--) { s->failed_pc=0x0c064842u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064844;
P_0c064844: /* original 6162, guest PC 0x0c064844 */
if(!s->budget--) { s->failed_pc=0x0c064844u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064846;
P_0c064846: /* original 6253, guest PC 0x0c064846 */
if(!s->budget--) { s->failed_pc=0x0c064846u; return 0; }
r[2]=r[5];
goto P_0c064848;
P_0c064848: /* original 5313, guest PC 0x0c064848 */
if(!s->budget--) { s->failed_pc=0x0c064848u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c06484a;
P_0c06484a: /* original 7501, guest PC 0x0c06484a */
if(!s->budget--) { s->failed_pc=0x0c06484au; return 0; }
r[5]+=0x00000001u;
goto P_0c06484c;
P_0c06484c: /* original 4208, guest PC 0x0c06484c */
if(!s->budget--) { s->failed_pc=0x0c06484cu; return 0; }
r[2]<<=2;
goto P_0c06484e;
P_0c06484e: /* original 0236, guest PC 0x0c06484e */
if(!s->budget--) { s->failed_pc=0x0c06484eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064850;
P_0c064850: /* original 6462, guest PC 0x0c064850 */
if(!s->budget--) { s->failed_pc=0x0c064850u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c064852;
P_0c064852: /* original e110, guest PC 0x0c064852 */
if(!s->budget--) { s->failed_pc=0x0c064852u; return 0; }
r[1]=0x00000010u;
goto P_0c064854;
P_0c064854: /* original 6253, guest PC 0x0c064854 */
if(!s->budget--) { s->failed_pc=0x0c064854u; return 0; }
r[2]=r[5];
goto P_0c064856;
P_0c064856: /* original 7501, guest PC 0x0c064856 */
if(!s->budget--) { s->failed_pc=0x0c064856u; return 0; }
r[5]+=0x00000001u;
goto P_0c064858;
P_0c064858: /* original 4208, guest PC 0x0c064858 */
if(!s->budget--) { s->failed_pc=0x0c064858u; return 0; }
r[2]<<=2;
goto P_0c06485a;
P_0c06485a: /* original 314c, guest PC 0x0c06485a */
if(!s->budget--) { s->failed_pc=0x0c06485au; return 0; }
r[1]+=r[4];
goto P_0c06485c;
P_0c06485c: /* original f318, guest PC 0x0c06485c */
if(!s->budget--) { s->failed_pc=0x0c06485cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06485e;
P_0c06485e: /* original e114, guest PC 0x0c06485e */
if(!s->budget--) { s->failed_pc=0x0c06485eu; return 0; }
r[1]=0x00000014u;
goto P_0c064860;
P_0c064860: /* original f342, guest PC 0x0c064860 */
if(!s->budget--) { s->failed_pc=0x0c064860u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064862;
P_0c064862: /* original f33d, guest PC 0x0c064862 */
if(!s->budget--) { s->failed_pc=0x0c064862u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064864;
P_0c064864: /* original 035a, guest PC 0x0c064864 */
if(!s->budget--) { s->failed_pc=0x0c064864u; return 0; }
r[3]=r[53];
goto P_0c064866;
P_0c064866: /* original 4328, guest PC 0x0c064866 */
if(!s->budget--) { s->failed_pc=0x0c064866u; return 0; }
r[3]<<=16;
goto P_0c064868;
P_0c064868: /* original 4318, guest PC 0x0c064868 */
if(!s->budget--) { s->failed_pc=0x0c064868u; return 0; }
r[3]<<=8;
goto P_0c06486a;
P_0c06486a: /* original 314c, guest PC 0x0c06486a */
if(!s->budget--) { s->failed_pc=0x0c06486au; return 0; }
r[1]+=r[4];
goto P_0c06486c;
P_0c06486c: /* original f318, guest PC 0x0c06486c */
if(!s->budget--) { s->failed_pc=0x0c06486cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06486e;
P_0c06486e: /* original f342, guest PC 0x0c06486e */
if(!s->budget--) { s->failed_pc=0x0c06486eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064870;
P_0c064870: /* original f33d, guest PC 0x0c064870 */
if(!s->budget--) { s->failed_pc=0x0c064870u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064872;
P_0c064872: /* original 015a, guest PC 0x0c064872 */
if(!s->budget--) { s->failed_pc=0x0c064872u; return 0; }
r[1]=r[53];
goto P_0c064874;
P_0c064874: /* original 4128, guest PC 0x0c064874 */
if(!s->budget--) { s->failed_pc=0x0c064874u; return 0; }
r[1]<<=16;
goto P_0c064876;
P_0c064876: /* original 231b, guest PC 0x0c064876 */
if(!s->budget--) { s->failed_pc=0x0c064876u; return 0; }
r[3]|=r[1];
goto P_0c064878;
P_0c064878: /* original e118, guest PC 0x0c064878 */
if(!s->budget--) { s->failed_pc=0x0c064878u; return 0; }
r[1]=0x00000018u;
goto P_0c06487a;
P_0c06487a: /* original 314c, guest PC 0x0c06487a */
if(!s->budget--) { s->failed_pc=0x0c06487au; return 0; }
r[1]+=r[4];
goto P_0c06487c;
P_0c06487c: /* original f318, guest PC 0x0c06487c */
if(!s->budget--) { s->failed_pc=0x0c06487cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06487e;
P_0c06487e: /* original f342, guest PC 0x0c06487e */
if(!s->budget--) { s->failed_pc=0x0c06487eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064880;
P_0c064880: /* original f33d, guest PC 0x0c064880 */
if(!s->budget--) { s->failed_pc=0x0c064880u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064882;
P_0c064882: /* original 015a, guest PC 0x0c064882 */
if(!s->budget--) { s->failed_pc=0x0c064882u; return 0; }
r[1]=r[53];
goto P_0c064884;
P_0c064884: /* original 4118, guest PC 0x0c064884 */
if(!s->budget--) { s->failed_pc=0x0c064884u; return 0; }
r[1]<<=8;
goto P_0c064886;
P_0c064886: /* original 231b, guest PC 0x0c064886 */
if(!s->budget--) { s->failed_pc=0x0c064886u; return 0; }
r[3]|=r[1];
goto P_0c064888;
P_0c064888: /* original e11c, guest PC 0x0c064888 */
if(!s->budget--) { s->failed_pc=0x0c064888u; return 0; }
r[1]=0x0000001cu;
goto P_0c06488a;
P_0c06488a: /* original 314c, guest PC 0x0c06488a */
if(!s->budget--) { s->failed_pc=0x0c06488au; return 0; }
r[1]+=r[4];
goto P_0c06488c;
P_0c06488c: /* original f318, guest PC 0x0c06488c */
if(!s->budget--) { s->failed_pc=0x0c06488cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06488e;
P_0c06488e: /* original f342, guest PC 0x0c06488e */
if(!s->budget--) { s->failed_pc=0x0c06488eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064890;
P_0c064890: /* original f33d, guest PC 0x0c064890 */
if(!s->budget--) { s->failed_pc=0x0c064890u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064892;
P_0c064892: /* original 015a, guest PC 0x0c064892 */
if(!s->budget--) { s->failed_pc=0x0c064892u; return 0; }
r[1]=r[53];
goto P_0c064894;
P_0c064894: /* original 231b, guest PC 0x0c064894 */
if(!s->budget--) { s->failed_pc=0x0c064894u; return 0; }
r[3]|=r[1];
goto P_0c064896;
P_0c064896: /* original 0236, guest PC 0x0c064896 */
if(!s->budget--) { s->failed_pc=0x0c064896u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064898;
P_0c064898: /* original 6172, guest PC 0x0c064898 */
if(!s->budget--) { s->failed_pc=0x0c064898u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c06489a;
P_0c06489a: /* original 6253, guest PC 0x0c06489a */
if(!s->budget--) { s->failed_pc=0x0c06489au; return 0; }
r[2]=r[5];
goto P_0c06489c;
P_0c06489c: /* original 5311, guest PC 0x0c06489c */
if(!s->budget--) { s->failed_pc=0x0c06489cu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c06489e;
P_0c06489e: /* original 7501, guest PC 0x0c06489e */
if(!s->budget--) { s->failed_pc=0x0c06489eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0648a0;
P_0c0648a0: /* original 4208, guest PC 0x0c0648a0 */
if(!s->budget--) { s->failed_pc=0x0c0648a0u; return 0; }
r[2]<<=2;
goto P_0c0648a2;
P_0c0648a2: /* original 0236, guest PC 0x0c0648a2 */
if(!s->budget--) { s->failed_pc=0x0c0648a2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0648a4;
P_0c0648a4: /* original 6253, guest PC 0x0c0648a4 */
if(!s->budget--) { s->failed_pc=0x0c0648a4u; return 0; }
r[2]=r[5];
goto P_0c0648a6;
P_0c0648a6: /* original 7501, guest PC 0x0c0648a6 */
if(!s->budget--) { s->failed_pc=0x0c0648a6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0648a8;
P_0c0648a8: /* original 4208, guest PC 0x0c0648a8 */
if(!s->budget--) { s->failed_pc=0x0c0648a8u; return 0; }
r[2]<<=2;
goto P_0c0648aa;
P_0c0648aa: /* original 6172, guest PC 0x0c0648aa */
if(!s->budget--) { s->failed_pc=0x0c0648aau; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0648ac;
P_0c0648ac: /* original 5312, guest PC 0x0c0648ac */
if(!s->budget--) { s->failed_pc=0x0c0648acu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0648ae;
P_0c0648ae: /* original 0236, guest PC 0x0c0648ae */
if(!s->budget--) { s->failed_pc=0x0c0648aeu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0648b0;
P_0c0648b0: /* original 6172, guest PC 0x0c0648b0 */
if(!s->budget--) { s->failed_pc=0x0c0648b0u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0648b2;
P_0c0648b2: /* original 6253, guest PC 0x0c0648b2 */
if(!s->budget--) { s->failed_pc=0x0c0648b2u; return 0; }
r[2]=r[5];
goto P_0c0648b4;
P_0c0648b4: /* original 5313, guest PC 0x0c0648b4 */
if(!s->budget--) { s->failed_pc=0x0c0648b4u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0648b6;
P_0c0648b6: /* original 7501, guest PC 0x0c0648b6 */
if(!s->budget--) { s->failed_pc=0x0c0648b6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0648b8;
P_0c0648b8: /* original 4208, guest PC 0x0c0648b8 */
if(!s->budget--) { s->failed_pc=0x0c0648b8u; return 0; }
r[2]<<=2;
goto P_0c0648ba;
P_0c0648ba: /* original 0236, guest PC 0x0c0648ba */
if(!s->budget--) { s->failed_pc=0x0c0648bau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0648bc;
P_0c0648bc: /* original 6472, guest PC 0x0c0648bc */
if(!s->budget--) { s->failed_pc=0x0c0648bcu; return 0; }
tmp=read(ram,r[7],4);
r[4]=tmp;
goto P_0c0648be;
P_0c0648be: /* original e110, guest PC 0x0c0648be */
if(!s->budget--) { s->failed_pc=0x0c0648beu; return 0; }
r[1]=0x00000010u;
goto P_0c0648c0;
P_0c0648c0: /* original 6253, guest PC 0x0c0648c0 */
if(!s->budget--) { s->failed_pc=0x0c0648c0u; return 0; }
r[2]=r[5];
goto P_0c0648c2;
P_0c0648c2: /* original 7501, guest PC 0x0c0648c2 */
if(!s->budget--) { s->failed_pc=0x0c0648c2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0648c4;
P_0c0648c4: /* original 4208, guest PC 0x0c0648c4 */
if(!s->budget--) { s->failed_pc=0x0c0648c4u; return 0; }
r[2]<<=2;
goto P_0c0648c6;
P_0c0648c6: /* original 314c, guest PC 0x0c0648c6 */
if(!s->budget--) { s->failed_pc=0x0c0648c6u; return 0; }
r[1]+=r[4];
goto P_0c0648c8;
P_0c0648c8: /* original f318, guest PC 0x0c0648c8 */
if(!s->budget--) { s->failed_pc=0x0c0648c8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0648ca;
P_0c0648ca: /* original e114, guest PC 0x0c0648ca */
if(!s->budget--) { s->failed_pc=0x0c0648cau; return 0; }
r[1]=0x00000014u;
goto P_0c0648cc;
P_0c0648cc: /* original f342, guest PC 0x0c0648cc */
if(!s->budget--) { s->failed_pc=0x0c0648ccu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0648ce;
P_0c0648ce: /* original 314c, guest PC 0x0c0648ce */
if(!s->budget--) { s->failed_pc=0x0c0648ceu; return 0; }
r[1]+=r[4];
goto P_0c0648d0;
P_0c0648d0: /* original f33d, guest PC 0x0c0648d0 */
if(!s->budget--) { s->failed_pc=0x0c0648d0u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0648d2;
P_0c0648d2: /* original 035a, guest PC 0x0c0648d2 */
if(!s->budget--) { s->failed_pc=0x0c0648d2u; return 0; }
r[3]=r[53];
goto P_0c0648d4;
P_0c0648d4: /* original f318, guest PC 0x0c0648d4 */
if(!s->budget--) { s->failed_pc=0x0c0648d4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0648d6;
P_0c0648d6: /* original 4328, guest PC 0x0c0648d6 */
if(!s->budget--) { s->failed_pc=0x0c0648d6u; return 0; }
r[3]<<=16;
goto P_0c0648d8;
P_0c0648d8: /* original 4318, guest PC 0x0c0648d8 */
if(!s->budget--) { s->failed_pc=0x0c0648d8u; return 0; }
r[3]<<=8;
goto P_0c0648da;
P_0c0648da: /* original f342, guest PC 0x0c0648da */
if(!s->budget--) { s->failed_pc=0x0c0648dau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0648dc;
P_0c0648dc: /* original f33d, guest PC 0x0c0648dc */
if(!s->budget--) { s->failed_pc=0x0c0648dcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0648de;
P_0c0648de: /* original 015a, guest PC 0x0c0648de */
if(!s->budget--) { s->failed_pc=0x0c0648deu; return 0; }
r[1]=r[53];
goto P_0c0648e0;
P_0c0648e0: /* original 4128, guest PC 0x0c0648e0 */
if(!s->budget--) { s->failed_pc=0x0c0648e0u; return 0; }
r[1]<<=16;
goto P_0c0648e2;
P_0c0648e2: /* original 231b, guest PC 0x0c0648e2 */
if(!s->budget--) { s->failed_pc=0x0c0648e2u; return 0; }
r[3]|=r[1];
goto P_0c0648e4;
P_0c0648e4: /* original e118, guest PC 0x0c0648e4 */
if(!s->budget--) { s->failed_pc=0x0c0648e4u; return 0; }
r[1]=0x00000018u;
goto P_0c0648e6;
P_0c0648e6: /* original 314c, guest PC 0x0c0648e6 */
if(!s->budget--) { s->failed_pc=0x0c0648e6u; return 0; }
r[1]+=r[4];
goto P_0c0648e8;
P_0c0648e8: /* original f318, guest PC 0x0c0648e8 */
if(!s->budget--) { s->failed_pc=0x0c0648e8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0648ea;
P_0c0648ea: /* original f342, guest PC 0x0c0648ea */
if(!s->budget--) { s->failed_pc=0x0c0648eau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0648ec;
P_0c0648ec: /* original f33d, guest PC 0x0c0648ec */
if(!s->budget--) { s->failed_pc=0x0c0648ecu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0648ee;
P_0c0648ee: /* original 015a, guest PC 0x0c0648ee */
if(!s->budget--) { s->failed_pc=0x0c0648eeu; return 0; }
r[1]=r[53];
goto P_0c0648f0;
P_0c0648f0: /* original 4118, guest PC 0x0c0648f0 */
if(!s->budget--) { s->failed_pc=0x0c0648f0u; return 0; }
r[1]<<=8;
goto P_0c0648f2;
P_0c0648f2: /* original 231b, guest PC 0x0c0648f2 */
if(!s->budget--) { s->failed_pc=0x0c0648f2u; return 0; }
r[3]|=r[1];
goto P_0c0648f4;
P_0c0648f4: /* original e11c, guest PC 0x0c0648f4 */
if(!s->budget--) { s->failed_pc=0x0c0648f4u; return 0; }
r[1]=0x0000001cu;
goto P_0c0648f6;
P_0c0648f6: /* original 314c, guest PC 0x0c0648f6 */
if(!s->budget--) { s->failed_pc=0x0c0648f6u; return 0; }
r[1]+=r[4];
goto P_0c0648f8;
P_0c0648f8: /* original f318, guest PC 0x0c0648f8 */
if(!s->budget--) { s->failed_pc=0x0c0648f8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0648fa;
P_0c0648fa: /* original f342, guest PC 0x0c0648fa */
if(!s->budget--) { s->failed_pc=0x0c0648fau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0648fc;
P_0c0648fc: /* original f33d, guest PC 0x0c0648fc */
if(!s->budget--) { s->failed_pc=0x0c0648fcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0648fe;
P_0c0648fe: /* original 015a, guest PC 0x0c0648fe */
if(!s->budget--) { s->failed_pc=0x0c0648feu; return 0; }
r[1]=r[53];
goto P_0c064900;
P_0c064900: /* original 231b, guest PC 0x0c064900 */
if(!s->budget--) { s->failed_pc=0x0c064900u; return 0; }
r[3]|=r[1];
goto P_0c064902;
P_0c064902: /* original 0236, guest PC 0x0c064902 */
if(!s->budget--) { s->failed_pc=0x0c064902u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064904;
P_0c064904: /* original d367, guest PC 0x0c064904 */
if(!s->budget--) { s->failed_pc=0x0c064904u; return 0; }
r[3]=read(ram,0x0c064aa4u,4);
goto P_0c064906;
P_0c064906: /* original 4508, guest PC 0x0c064906 */
if(!s->budget--) { s->failed_pc=0x0c064906u; return 0; }
r[5]<<=2;
goto P_0c064908;
P_0c064908: /* original 2352, guest PC 0x0c064908 */
if(!s->budget--) { s->failed_pc=0x0c064908u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c06490a;
P_0c06490a: /* original be02, guest PC 0x0c06490a */
if(!s->budget--) { s->failed_pc=0x0c06490au; return 0; }
target=0x0c064512u; r[16]=0x0c06490eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06490eu) { target=s->pc; goto dispatch; }
goto P_0c06490e;
P_0c06490c: /* original 64d3, guest PC 0x0c06490c */
if(!s->budget--) { s->failed_pc=0x0c06490cu; return 0; }
r[4]=r[13];
goto P_0c06490e;
P_0c06490e: /* original 6403, guest PC 0x0c06490e */
if(!s->budget--) { s->failed_pc=0x0c06490eu; return 0; }
r[4]=r[0];
goto P_0c064910;
P_0c064910: /* original e500, guest PC 0x0c064910 */
if(!s->budget--) { s->failed_pc=0x0c064910u; return 0; }
r[5]=0x00000000u;
goto P_0c064912;
P_0c064912: /* original bde9, guest PC 0x0c064912 */
if(!s->budget--) { s->failed_pc=0x0c064912u; return 0; }
target=0x0c0644e8u; r[16]=0x0c064916u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064916u) { target=s->pc; goto dispatch; }
goto P_0c064916;
P_0c064914: /* original 6653, guest PC 0x0c064914 */
if(!s->budget--) { s->failed_pc=0x0c064914u; return 0; }
r[6]=r[5];
goto P_0c064916;
P_0c064916: /* original 63e2, guest PC 0x0c064916 */
if(!s->budget--) { s->failed_pc=0x0c064916u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c064918;
P_0c064918: /* original d163, guest PC 0x0c064918 */
if(!s->budget--) { s->failed_pc=0x0c064918u; return 0; }
r[1]=read(ram,0x0c064aa8u,4);
goto P_0c06491a;
P_0c06491a: /* original 5233, guest PC 0x0c06491a */
if(!s->budget--) { s->failed_pc=0x0c06491au; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c06491c;
P_0c06491c: /* original 2122, guest PC 0x0c06491c */
if(!s->budget--) { s->failed_pc=0x0c06491cu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c06491e;
P_0c06491e: /* original e000, guest PC 0x0c06491e */
if(!s->budget--) { s->failed_pc=0x0c06491eu; return 0; }
r[0]=0x00000000u;
goto P_0c064920;
P_0c064920: /* original 7f10, guest PC 0x0c064920 */
if(!s->budget--) { s->failed_pc=0x0c064920u; return 0; }
r[15]+=0x00000010u;
goto P_0c064922;
P_0c064922: /* original 4f26, guest PC 0x0c064922 */
if(!s->budget--) { s->failed_pc=0x0c064922u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c064924;
P_0c064924: /* original 6df6, guest PC 0x0c064924 */
if(!s->budget--) { s->failed_pc=0x0c064924u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c064926;
P_0c064926: /* original 000b, guest PC 0x0c064926 */
if(!s->budget--) { s->failed_pc=0x0c064926u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c064928: /* original 6ef6, guest PC 0x0c064928 */
if(!s->budget--) { s->failed_pc=0x0c064928u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06492au,s,ram);
P_0c064ab8: /* original 4f22, guest PC 0x0c064ab8 */
if(!s->budget--) { s->failed_pc=0x0c064ab8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064aba;
P_0c064aba: /* original 7ff0, guest PC 0x0c064aba */
if(!s->budget--) { s->failed_pc=0x0c064abau; return 0; }
r[15]+=0xfffffff0u;
goto P_0c064abc;
P_0c064abc: /* original 6342, guest PC 0x0c064abc */
if(!s->budget--) { s->failed_pc=0x0c064abcu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064abe;
P_0c064abe: /* original 65f3, guest PC 0x0c064abe */
if(!s->budget--) { s->failed_pc=0x0c064abeu; return 0; }
r[5]=r[15];
goto P_0c064ac0;
P_0c064ac0: /* original 7504, guest PC 0x0c064ac0 */
if(!s->budget--) { s->failed_pc=0x0c064ac0u; return 0; }
r[5]+=0x00000004u;
goto P_0c064ac2;
P_0c064ac2: /* original 6d53, guest PC 0x0c064ac2 */
if(!s->budget--) { s->failed_pc=0x0c064ac2u; return 0; }
r[13]=r[5];
goto P_0c064ac4;
P_0c064ac4: /* original 2d32, guest PC 0x0c064ac4 */
if(!s->budget--) { s->failed_pc=0x0c064ac4u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c064ac6;
P_0c064ac6: /* original 6ad3, guest PC 0x0c064ac6 */
if(!s->budget--) { s->failed_pc=0x0c064ac6u; return 0; }
r[10]=r[13];
goto P_0c064ac8;
P_0c064ac8: /* original 5241, guest PC 0x0c064ac8 */
if(!s->budget--) { s->failed_pc=0x0c064ac8u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c064aca;
P_0c064aca: /* original 6bd3, guest PC 0x0c064aca */
if(!s->budget--) { s->failed_pc=0x0c064acau; return 0; }
r[11]=r[13];
goto P_0c064acc;
P_0c064acc: /* original 7a04, guest PC 0x0c064acc */
if(!s->budget--) { s->failed_pc=0x0c064accu; return 0; }
r[10]+=0x00000004u;
goto P_0c064ace;
P_0c064ace: /* original 7b08, guest PC 0x0c064ace */
if(!s->budget--) { s->failed_pc=0x0c064aceu; return 0; }
r[11]+=0x00000008u;
goto P_0c064ad0;
P_0c064ad0: /* original 2a22, guest PC 0x0c064ad0 */
if(!s->budget--) { s->failed_pc=0x0c064ad0u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c064ad2;
P_0c064ad2: /* original 5342, guest PC 0x0c064ad2 */
if(!s->budget--) { s->failed_pc=0x0c064ad2u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c064ad4;
P_0c064ad4: /* original d2a8, guest PC 0x0c064ad4 */
if(!s->budget--) { s->failed_pc=0x0c064ad4u; return 0; }
r[2]=read(ram,0x0c064d78u,4);
goto P_0c064ad6;
P_0c064ad6: /* original 2b32, guest PC 0x0c064ad6 */
if(!s->budget--) { s->failed_pc=0x0c064ad6u; return 0; }
write(ram,r[11],r[3],4);
goto P_0c064ad8;
P_0c064ad8: /* original 6e22, guest PC 0x0c064ad8 */
if(!s->budget--) { s->failed_pc=0x0c064ad8u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c064ada;
P_0c064ada: /* original d3a8, guest PC 0x0c064ada */
if(!s->budget--) { s->failed_pc=0x0c064adau; return 0; }
r[3]=read(ram,0x0c064d7cu,4);
goto P_0c064adc;
P_0c064adc: /* original 6432, guest PC 0x0c064adc */
if(!s->budget--) { s->failed_pc=0x0c064adcu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c064ade;
P_0c064ade: /* original d1a8, guest PC 0x0c064ade */
if(!s->budget--) { s->failed_pc=0x0c064adeu; return 0; }
r[1]=read(ram,0x0c064d80u,4);
goto P_0c064ae0;
P_0c064ae0: /* original 6512, guest PC 0x0c064ae0 */
if(!s->budget--) { s->failed_pc=0x0c064ae0u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c064ae2;
P_0c064ae2: /* original d0a8, guest PC 0x0c064ae2 */
if(!s->budget--) { s->failed_pc=0x0c064ae2u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064ae4;
P_0c064ae4: /* original 62c3, guest PC 0x0c064ae4 */
if(!s->budget--) { s->failed_pc=0x0c064ae4u; return 0; }
r[2]=r[12];
goto P_0c064ae6;
P_0c064ae6: /* original 7c01, guest PC 0x0c064ae6 */
if(!s->budget--) { s->failed_pc=0x0c064ae6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064ae8;
P_0c064ae8: /* original 4208, guest PC 0x0c064ae8 */
if(!s->budget--) { s->failed_pc=0x0c064ae8u; return 0; }
r[2]<<=2;
goto P_0c064aea;
P_0c064aea: /* original 02e6, guest PC 0x0c064aea */
if(!s->budget--) { s->failed_pc=0x0c064aeau; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c064aec;
P_0c064aec: /* original 63c3, guest PC 0x0c064aec */
if(!s->budget--) { s->failed_pc=0x0c064aecu; return 0; }
r[3]=r[12];
goto P_0c064aee;
P_0c064aee: /* original 7c01, guest PC 0x0c064aee */
if(!s->budget--) { s->failed_pc=0x0c064aeeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064af0;
P_0c064af0: /* original 4308, guest PC 0x0c064af0 */
if(!s->budget--) { s->failed_pc=0x0c064af0u; return 0; }
r[3]<<=2;
goto P_0c064af2;
P_0c064af2: /* original 0346, guest PC 0x0c064af2 */
if(!s->budget--) { s->failed_pc=0x0c064af2u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c064af4;
P_0c064af4: /* original 62c3, guest PC 0x0c064af4 */
if(!s->budget--) { s->failed_pc=0x0c064af4u; return 0; }
r[2]=r[12];
goto P_0c064af6;
P_0c064af6: /* original 7c01, guest PC 0x0c064af6 */
if(!s->budget--) { s->failed_pc=0x0c064af6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064af8;
P_0c064af8: /* original 4208, guest PC 0x0c064af8 */
if(!s->budget--) { s->failed_pc=0x0c064af8u; return 0; }
r[2]<<=2;
goto P_0c064afa;
P_0c064afa: /* original 0256, guest PC 0x0c064afa */
if(!s->budget--) { s->failed_pc=0x0c064afau; return 0; }
write(ram,r[2]+r[0],r[5],4);
goto P_0c064afc;
P_0c064afc: /* original 62d2, guest PC 0x0c064afc */
if(!s->budget--) { s->failed_pc=0x0c064afcu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064afe;
P_0c064afe: /* original 63c3, guest PC 0x0c064afe */
if(!s->budget--) { s->failed_pc=0x0c064afeu; return 0; }
r[3]=r[12];
goto P_0c064b00;
P_0c064b00: /* original 5221, guest PC 0x0c064b00 */
if(!s->budget--) { s->failed_pc=0x0c064b00u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c064b02;
P_0c064b02: /* original 7c01, guest PC 0x0c064b02 */
if(!s->budget--) { s->failed_pc=0x0c064b02u; return 0; }
r[12]+=0x00000001u;
goto P_0c064b04;
P_0c064b04: /* original 4308, guest PC 0x0c064b04 */
if(!s->budget--) { s->failed_pc=0x0c064b04u; return 0; }
r[3]<<=2;
goto P_0c064b06;
P_0c064b06: /* original 0326, guest PC 0x0c064b06 */
if(!s->budget--) { s->failed_pc=0x0c064b06u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064b08;
P_0c064b08: /* original 62d2, guest PC 0x0c064b08 */
if(!s->budget--) { s->failed_pc=0x0c064b08u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064b0a;
P_0c064b0a: /* original 63c3, guest PC 0x0c064b0a */
if(!s->budget--) { s->failed_pc=0x0c064b0au; return 0; }
r[3]=r[12];
goto P_0c064b0c;
P_0c064b0c: /* original 5222, guest PC 0x0c064b0c */
if(!s->budget--) { s->failed_pc=0x0c064b0cu; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c064b0e;
P_0c064b0e: /* original 7c01, guest PC 0x0c064b0e */
if(!s->budget--) { s->failed_pc=0x0c064b0eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064b10;
P_0c064b10: /* original 4308, guest PC 0x0c064b10 */
if(!s->budget--) { s->failed_pc=0x0c064b10u; return 0; }
r[3]<<=2;
goto P_0c064b12;
P_0c064b12: /* original 0326, guest PC 0x0c064b12 */
if(!s->budget--) { s->failed_pc=0x0c064b12u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064b14;
P_0c064b14: /* original 62d2, guest PC 0x0c064b14 */
if(!s->budget--) { s->failed_pc=0x0c064b14u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064b16;
P_0c064b16: /* original 63c3, guest PC 0x0c064b16 */
if(!s->budget--) { s->failed_pc=0x0c064b16u; return 0; }
r[3]=r[12];
goto P_0c064b18;
P_0c064b18: /* original 5223, guest PC 0x0c064b18 */
if(!s->budget--) { s->failed_pc=0x0c064b18u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c064b1a;
P_0c064b1a: /* original 7c01, guest PC 0x0c064b1a */
if(!s->budget--) { s->failed_pc=0x0c064b1au; return 0; }
r[12]+=0x00000001u;
goto P_0c064b1c;
P_0c064b1c: /* original 4308, guest PC 0x0c064b1c */
if(!s->budget--) { s->failed_pc=0x0c064b1cu; return 0; }
r[3]<<=2;
goto P_0c064b1e;
P_0c064b1e: /* original 0326, guest PC 0x0c064b1e */
if(!s->budget--) { s->failed_pc=0x0c064b1eu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064b20;
P_0c064b20: /* original 67d2, guest PC 0x0c064b20 */
if(!s->budget--) { s->failed_pc=0x0c064b20u; return 0; }
tmp=read(ram,r[13],4);
r[7]=tmp;
goto P_0c064b22;
P_0c064b22: /* original 2f72, guest PC 0x0c064b22 */
if(!s->budget--) { s->failed_pc=0x0c064b22u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064b24;
P_0c064b24: /* original 5775, guest PC 0x0c064b24 */
if(!s->budget--) { s->failed_pc=0x0c064b24u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064b26;
P_0c064b26: /* original 66f2, guest PC 0x0c064b26 */
if(!s->budget--) { s->failed_pc=0x0c064b26u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064b28;
P_0c064b28: /* original 5664, guest PC 0x0c064b28 */
if(!s->budget--) { s->failed_pc=0x0c064b28u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064b2a;
P_0c064b2a: /* original 65c3, guest PC 0x0c064b2a */
if(!s->budget--) { s->failed_pc=0x0c064b2au; return 0; }
r[5]=r[12];
goto P_0c064b2c;
P_0c064b2c: /* original bd24, guest PC 0x0c064b2c */
if(!s->budget--) { s->failed_pc=0x0c064b2cu; return 0; }
target=0x0c064578u; r[16]=0x0c064b30u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064b30u) { target=s->pc; goto dispatch; }
goto P_0c064b30;
P_0c064b2e: /* original 64e3, guest PC 0x0c064b2e */
if(!s->budget--) { s->failed_pc=0x0c064b2eu; return 0; }
r[4]=r[14];
goto P_0c064b30;
P_0c064b30: /* original 63d2, guest PC 0x0c064b30 */
if(!s->budget--) { s->failed_pc=0x0c064b30u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c064b32;
P_0c064b32: /* original 6c03, guest PC 0x0c064b32 */
if(!s->budget--) { s->failed_pc=0x0c064b32u; return 0; }
r[12]=r[0];
goto P_0c064b34;
P_0c064b34: /* original 5136, guest PC 0x0c064b34 */
if(!s->budget--) { s->failed_pc=0x0c064b34u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064b36;
P_0c064b36: /* original 62c3, guest PC 0x0c064b36 */
if(!s->budget--) { s->failed_pc=0x0c064b36u; return 0; }
r[2]=r[12];
goto P_0c064b38;
P_0c064b38: /* original d092, guest PC 0x0c064b38 */
if(!s->budget--) { s->failed_pc=0x0c064b38u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064b3a;
P_0c064b3a: /* original 7c01, guest PC 0x0c064b3a */
if(!s->budget--) { s->failed_pc=0x0c064b3au; return 0; }
r[12]+=0x00000001u;
goto P_0c064b3c;
P_0c064b3c: /* original 4208, guest PC 0x0c064b3c */
if(!s->budget--) { s->failed_pc=0x0c064b3cu; return 0; }
r[2]<<=2;
goto P_0c064b3e;
P_0c064b3e: /* original 0216, guest PC 0x0c064b3e */
if(!s->budget--) { s->failed_pc=0x0c064b3eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064b40;
P_0c064b40: /* original 66d2, guest PC 0x0c064b40 */
if(!s->budget--) { s->failed_pc=0x0c064b40u; return 0; }
tmp=read(ram,r[13],4);
r[6]=tmp;
goto P_0c064b42;
P_0c064b42: /* original 65c3, guest PC 0x0c064b42 */
if(!s->budget--) { s->failed_pc=0x0c064b42u; return 0; }
r[5]=r[12];
goto P_0c064b44;
P_0c064b44: /* original 5667, guest PC 0x0c064b44 */
if(!s->budget--) { s->failed_pc=0x0c064b44u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064b46;
P_0c064b46: /* original bcf3, guest PC 0x0c064b46 */
if(!s->budget--) { s->failed_pc=0x0c064b46u; return 0; }
target=0x0c064530u; r[16]=0x0c064b4au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064b4au) { target=s->pc; goto dispatch; }
goto P_0c064b4a;
P_0c064b48: /* original 64e3, guest PC 0x0c064b48 */
if(!s->budget--) { s->failed_pc=0x0c064b48u; return 0; }
r[4]=r[14];
goto P_0c064b4a;
P_0c064b4a: /* original 6c03, guest PC 0x0c064b4a */
if(!s->budget--) { s->failed_pc=0x0c064b4au; return 0; }
r[12]=r[0];
goto P_0c064b4c;
P_0c064b4c: /* original 61a2, guest PC 0x0c064b4c */
if(!s->budget--) { s->failed_pc=0x0c064b4cu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064b4e;
P_0c064b4e: /* original 62c3, guest PC 0x0c064b4e */
if(!s->budget--) { s->failed_pc=0x0c064b4eu; return 0; }
r[2]=r[12];
goto P_0c064b50;
P_0c064b50: /* original d08c, guest PC 0x0c064b50 */
if(!s->budget--) { s->failed_pc=0x0c064b50u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064b52;
P_0c064b52: /* original 7c01, guest PC 0x0c064b52 */
if(!s->budget--) { s->failed_pc=0x0c064b52u; return 0; }
r[12]+=0x00000001u;
goto P_0c064b54;
P_0c064b54: /* original 5311, guest PC 0x0c064b54 */
if(!s->budget--) { s->failed_pc=0x0c064b54u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064b56;
P_0c064b56: /* original 4208, guest PC 0x0c064b56 */
if(!s->budget--) { s->failed_pc=0x0c064b56u; return 0; }
r[2]<<=2;
goto P_0c064b58;
P_0c064b58: /* original 0236, guest PC 0x0c064b58 */
if(!s->budget--) { s->failed_pc=0x0c064b58u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064b5a;
P_0c064b5a: /* original 62c3, guest PC 0x0c064b5a */
if(!s->budget--) { s->failed_pc=0x0c064b5au; return 0; }
r[2]=r[12];
goto P_0c064b5c;
P_0c064b5c: /* original 61a2, guest PC 0x0c064b5c */
if(!s->budget--) { s->failed_pc=0x0c064b5cu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064b5e;
P_0c064b5e: /* original 7c01, guest PC 0x0c064b5e */
if(!s->budget--) { s->failed_pc=0x0c064b5eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064b60;
P_0c064b60: /* original 5312, guest PC 0x0c064b60 */
if(!s->budget--) { s->failed_pc=0x0c064b60u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064b62;
P_0c064b62: /* original 4208, guest PC 0x0c064b62 */
if(!s->budget--) { s->failed_pc=0x0c064b62u; return 0; }
r[2]<<=2;
goto P_0c064b64;
P_0c064b64: /* original 0236, guest PC 0x0c064b64 */
if(!s->budget--) { s->failed_pc=0x0c064b64u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064b66;
P_0c064b66: /* original 62c3, guest PC 0x0c064b66 */
if(!s->budget--) { s->failed_pc=0x0c064b66u; return 0; }
r[2]=r[12];
goto P_0c064b68;
P_0c064b68: /* original 61a2, guest PC 0x0c064b68 */
if(!s->budget--) { s->failed_pc=0x0c064b68u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064b6a;
P_0c064b6a: /* original 7c01, guest PC 0x0c064b6a */
if(!s->budget--) { s->failed_pc=0x0c064b6au; return 0; }
r[12]+=0x00000001u;
goto P_0c064b6c;
P_0c064b6c: /* original 5313, guest PC 0x0c064b6c */
if(!s->budget--) { s->failed_pc=0x0c064b6cu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064b6e;
P_0c064b6e: /* original 4208, guest PC 0x0c064b6e */
if(!s->budget--) { s->failed_pc=0x0c064b6eu; return 0; }
r[2]<<=2;
goto P_0c064b70;
P_0c064b70: /* original 0236, guest PC 0x0c064b70 */
if(!s->budget--) { s->failed_pc=0x0c064b70u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064b72;
P_0c064b72: /* original 65c3, guest PC 0x0c064b72 */
if(!s->budget--) { s->failed_pc=0x0c064b72u; return 0; }
r[5]=r[12];
goto P_0c064b74;
P_0c064b74: /* original 67a2, guest PC 0x0c064b74 */
if(!s->budget--) { s->failed_pc=0x0c064b74u; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c064b76;
P_0c064b76: /* original 2f72, guest PC 0x0c064b76 */
if(!s->budget--) { s->failed_pc=0x0c064b76u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064b78;
P_0c064b78: /* original 5775, guest PC 0x0c064b78 */
if(!s->budget--) { s->failed_pc=0x0c064b78u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064b7a;
P_0c064b7a: /* original 66f2, guest PC 0x0c064b7a */
if(!s->budget--) { s->failed_pc=0x0c064b7au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064b7c;
P_0c064b7c: /* original 5664, guest PC 0x0c064b7c */
if(!s->budget--) { s->failed_pc=0x0c064b7cu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064b7e;
P_0c064b7e: /* original bcfb, guest PC 0x0c064b7e */
if(!s->budget--) { s->failed_pc=0x0c064b7eu; return 0; }
target=0x0c064578u; r[16]=0x0c064b82u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064b82u) { target=s->pc; goto dispatch; }
goto P_0c064b82;
P_0c064b80: /* original 64e3, guest PC 0x0c064b80 */
if(!s->budget--) { s->failed_pc=0x0c064b80u; return 0; }
r[4]=r[14];
goto P_0c064b82;
P_0c064b82: /* original 6c03, guest PC 0x0c064b82 */
if(!s->budget--) { s->failed_pc=0x0c064b82u; return 0; }
r[12]=r[0];
goto P_0c064b84;
P_0c064b84: /* original 63a2, guest PC 0x0c064b84 */
if(!s->budget--) { s->failed_pc=0x0c064b84u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c064b86;
P_0c064b86: /* original 62c3, guest PC 0x0c064b86 */
if(!s->budget--) { s->failed_pc=0x0c064b86u; return 0; }
r[2]=r[12];
goto P_0c064b88;
P_0c064b88: /* original d07e, guest PC 0x0c064b88 */
if(!s->budget--) { s->failed_pc=0x0c064b88u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064b8a;
P_0c064b8a: /* original 7c01, guest PC 0x0c064b8a */
if(!s->budget--) { s->failed_pc=0x0c064b8au; return 0; }
r[12]+=0x00000001u;
goto P_0c064b8c;
P_0c064b8c: /* original 5136, guest PC 0x0c064b8c */
if(!s->budget--) { s->failed_pc=0x0c064b8cu; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064b8e;
P_0c064b8e: /* original 4208, guest PC 0x0c064b8e */
if(!s->budget--) { s->failed_pc=0x0c064b8eu; return 0; }
r[2]<<=2;
goto P_0c064b90;
P_0c064b90: /* original 0216, guest PC 0x0c064b90 */
if(!s->budget--) { s->failed_pc=0x0c064b90u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064b92;
P_0c064b92: /* original 65c3, guest PC 0x0c064b92 */
if(!s->budget--) { s->failed_pc=0x0c064b92u; return 0; }
r[5]=r[12];
goto P_0c064b94;
P_0c064b94: /* original 66a2, guest PC 0x0c064b94 */
if(!s->budget--) { s->failed_pc=0x0c064b94u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c064b96;
P_0c064b96: /* original 5667, guest PC 0x0c064b96 */
if(!s->budget--) { s->failed_pc=0x0c064b96u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064b98;
P_0c064b98: /* original bcca, guest PC 0x0c064b98 */
if(!s->budget--) { s->failed_pc=0x0c064b98u; return 0; }
target=0x0c064530u; r[16]=0x0c064b9cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064b9cu) { target=s->pc; goto dispatch; }
goto P_0c064b9c;
P_0c064b9a: /* original 64e3, guest PC 0x0c064b9a */
if(!s->budget--) { s->failed_pc=0x0c064b9au; return 0; }
r[4]=r[14];
goto P_0c064b9c;
P_0c064b9c: /* original 61b2, guest PC 0x0c064b9c */
if(!s->budget--) { s->failed_pc=0x0c064b9cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064b9e;
P_0c064b9e: /* original 6c03, guest PC 0x0c064b9e */
if(!s->budget--) { s->failed_pc=0x0c064b9eu; return 0; }
r[12]=r[0];
goto P_0c064ba0;
P_0c064ba0: /* original 5311, guest PC 0x0c064ba0 */
if(!s->budget--) { s->failed_pc=0x0c064ba0u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064ba2;
P_0c064ba2: /* original 62c3, guest PC 0x0c064ba2 */
if(!s->budget--) { s->failed_pc=0x0c064ba2u; return 0; }
r[2]=r[12];
goto P_0c064ba4;
P_0c064ba4: /* original d077, guest PC 0x0c064ba4 */
if(!s->budget--) { s->failed_pc=0x0c064ba4u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064ba6;
P_0c064ba6: /* original 7c01, guest PC 0x0c064ba6 */
if(!s->budget--) { s->failed_pc=0x0c064ba6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064ba8;
P_0c064ba8: /* original 4208, guest PC 0x0c064ba8 */
if(!s->budget--) { s->failed_pc=0x0c064ba8u; return 0; }
r[2]<<=2;
goto P_0c064baa;
P_0c064baa: /* original 0236, guest PC 0x0c064baa */
if(!s->budget--) { s->failed_pc=0x0c064baau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064bac;
P_0c064bac: /* original 61b2, guest PC 0x0c064bac */
if(!s->budget--) { s->failed_pc=0x0c064bacu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064bae;
P_0c064bae: /* original 62c3, guest PC 0x0c064bae */
if(!s->budget--) { s->failed_pc=0x0c064baeu; return 0; }
r[2]=r[12];
goto P_0c064bb0;
P_0c064bb0: /* original 5312, guest PC 0x0c064bb0 */
if(!s->budget--) { s->failed_pc=0x0c064bb0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064bb2;
P_0c064bb2: /* original 7c01, guest PC 0x0c064bb2 */
if(!s->budget--) { s->failed_pc=0x0c064bb2u; return 0; }
r[12]+=0x00000001u;
goto P_0c064bb4;
P_0c064bb4: /* original 4208, guest PC 0x0c064bb4 */
if(!s->budget--) { s->failed_pc=0x0c064bb4u; return 0; }
r[2]<<=2;
goto P_0c064bb6;
P_0c064bb6: /* original 0236, guest PC 0x0c064bb6 */
if(!s->budget--) { s->failed_pc=0x0c064bb6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064bb8;
P_0c064bb8: /* original 61b2, guest PC 0x0c064bb8 */
if(!s->budget--) { s->failed_pc=0x0c064bb8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064bba;
P_0c064bba: /* original 62c3, guest PC 0x0c064bba */
if(!s->budget--) { s->failed_pc=0x0c064bbau; return 0; }
r[2]=r[12];
goto P_0c064bbc;
P_0c064bbc: /* original 5313, guest PC 0x0c064bbc */
if(!s->budget--) { s->failed_pc=0x0c064bbcu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064bbe;
P_0c064bbe: /* original 7c01, guest PC 0x0c064bbe */
if(!s->budget--) { s->failed_pc=0x0c064bbeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064bc0;
P_0c064bc0: /* original 4208, guest PC 0x0c064bc0 */
if(!s->budget--) { s->failed_pc=0x0c064bc0u; return 0; }
r[2]<<=2;
goto P_0c064bc2;
P_0c064bc2: /* original 0236, guest PC 0x0c064bc2 */
if(!s->budget--) { s->failed_pc=0x0c064bc2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064bc4;
P_0c064bc4: /* original 67b2, guest PC 0x0c064bc4 */
if(!s->budget--) { s->failed_pc=0x0c064bc4u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c064bc6;
P_0c064bc6: /* original 65c3, guest PC 0x0c064bc6 */
if(!s->budget--) { s->failed_pc=0x0c064bc6u; return 0; }
r[5]=r[12];
goto P_0c064bc8;
P_0c064bc8: /* original 2f72, guest PC 0x0c064bc8 */
if(!s->budget--) { s->failed_pc=0x0c064bc8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064bca;
P_0c064bca: /* original 5775, guest PC 0x0c064bca */
if(!s->budget--) { s->failed_pc=0x0c064bcau; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064bcc;
P_0c064bcc: /* original 66f2, guest PC 0x0c064bcc */
if(!s->budget--) { s->failed_pc=0x0c064bccu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064bce;
P_0c064bce: /* original 5664, guest PC 0x0c064bce */
if(!s->budget--) { s->failed_pc=0x0c064bceu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064bd0;
P_0c064bd0: /* original bcd2, guest PC 0x0c064bd0 */
if(!s->budget--) { s->failed_pc=0x0c064bd0u; return 0; }
target=0x0c064578u; r[16]=0x0c064bd4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064bd4u) { target=s->pc; goto dispatch; }
goto P_0c064bd4;
P_0c064bd2: /* original 64e3, guest PC 0x0c064bd2 */
if(!s->budget--) { s->failed_pc=0x0c064bd2u; return 0; }
r[4]=r[14];
goto P_0c064bd4;
P_0c064bd4: /* original 63b2, guest PC 0x0c064bd4 */
if(!s->budget--) { s->failed_pc=0x0c064bd4u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c064bd6;
P_0c064bd6: /* original 6c03, guest PC 0x0c064bd6 */
if(!s->budget--) { s->failed_pc=0x0c064bd6u; return 0; }
r[12]=r[0];
goto P_0c064bd8;
P_0c064bd8: /* original 5136, guest PC 0x0c064bd8 */
if(!s->budget--) { s->failed_pc=0x0c064bd8u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064bda;
P_0c064bda: /* original 62c3, guest PC 0x0c064bda */
if(!s->budget--) { s->failed_pc=0x0c064bdau; return 0; }
r[2]=r[12];
goto P_0c064bdc;
P_0c064bdc: /* original d069, guest PC 0x0c064bdc */
if(!s->budget--) { s->failed_pc=0x0c064bdcu; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064bde;
P_0c064bde: /* original 7c01, guest PC 0x0c064bde */
if(!s->budget--) { s->failed_pc=0x0c064bdeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064be0;
P_0c064be0: /* original 4208, guest PC 0x0c064be0 */
if(!s->budget--) { s->failed_pc=0x0c064be0u; return 0; }
r[2]<<=2;
goto P_0c064be2;
P_0c064be2: /* original 0216, guest PC 0x0c064be2 */
if(!s->budget--) { s->failed_pc=0x0c064be2u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064be4;
P_0c064be4: /* original 66b2, guest PC 0x0c064be4 */
if(!s->budget--) { s->failed_pc=0x0c064be4u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c064be6;
P_0c064be6: /* original 65c3, guest PC 0x0c064be6 */
if(!s->budget--) { s->failed_pc=0x0c064be6u; return 0; }
r[5]=r[12];
goto P_0c064be8;
P_0c064be8: /* original 5667, guest PC 0x0c064be8 */
if(!s->budget--) { s->failed_pc=0x0c064be8u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064bea;
P_0c064bea: /* original bca1, guest PC 0x0c064bea */
if(!s->budget--) { s->failed_pc=0x0c064beau; return 0; }
target=0x0c064530u; r[16]=0x0c064beeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064beeu) { target=s->pc; goto dispatch; }
goto P_0c064bee;
P_0c064bec: /* original 64e3, guest PC 0x0c064bec */
if(!s->budget--) { s->failed_pc=0x0c064becu; return 0; }
r[4]=r[14];
goto P_0c064bee;
P_0c064bee: /* original 6403, guest PC 0x0c064bee */
if(!s->budget--) { s->failed_pc=0x0c064beeu; return 0; }
r[4]=r[0];
goto P_0c064bf0;
P_0c064bf0: /* original d265, guest PC 0x0c064bf0 */
if(!s->budget--) { s->failed_pc=0x0c064bf0u; return 0; }
r[2]=read(ram,0x0c064d88u,4);
goto P_0c064bf2;
P_0c064bf2: /* original 4408, guest PC 0x0c064bf2 */
if(!s->budget--) { s->failed_pc=0x0c064bf2u; return 0; }
r[4]<<=2;
goto P_0c064bf4;
P_0c064bf4: /* original 2242, guest PC 0x0c064bf4 */
if(!s->budget--) { s->failed_pc=0x0c064bf4u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c064bf6;
P_0c064bf6: /* original bc8c, guest PC 0x0c064bf6 */
if(!s->budget--) { s->failed_pc=0x0c064bf6u; return 0; }
target=0x0c064512u; r[16]=0x0c064bfau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064bfau) { target=s->pc; goto dispatch; }
goto P_0c064bfa;
P_0c064bf8: /* original 64e3, guest PC 0x0c064bf8 */
if(!s->budget--) { s->failed_pc=0x0c064bf8u; return 0; }
r[4]=r[14];
goto P_0c064bfa;
P_0c064bfa: /* original 6403, guest PC 0x0c064bfa */
if(!s->budget--) { s->failed_pc=0x0c064bfau; return 0; }
r[4]=r[0];
goto P_0c064bfc;
P_0c064bfc: /* original e500, guest PC 0x0c064bfc */
if(!s->budget--) { s->failed_pc=0x0c064bfcu; return 0; }
r[5]=0x00000000u;
goto P_0c064bfe;
P_0c064bfe: /* original bc73, guest PC 0x0c064bfe */
if(!s->budget--) { s->failed_pc=0x0c064bfeu; return 0; }
target=0x0c0644e8u; r[16]=0x0c064c02u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064c02u) { target=s->pc; goto dispatch; }
goto P_0c064c02;
P_0c064c00: /* original 6653, guest PC 0x0c064c00 */
if(!s->budget--) { s->failed_pc=0x0c064c00u; return 0; }
r[6]=r[5];
goto P_0c064c02;
P_0c064c02: /* original 62d2, guest PC 0x0c064c02 */
if(!s->budget--) { s->failed_pc=0x0c064c02u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064c04;
P_0c064c04: /* original d161, guest PC 0x0c064c04 */
if(!s->budget--) { s->failed_pc=0x0c064c04u; return 0; }
r[1]=read(ram,0x0c064d8cu,4);
goto P_0c064c06;
P_0c064c06: /* original 5323, guest PC 0x0c064c06 */
if(!s->budget--) { s->failed_pc=0x0c064c06u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c064c08;
P_0c064c08: /* original 2132, guest PC 0x0c064c08 */
if(!s->budget--) { s->failed_pc=0x0c064c08u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c064c0a;
P_0c064c0a: /* original e000, guest PC 0x0c064c0a */
if(!s->budget--) { s->failed_pc=0x0c064c0au; return 0; }
r[0]=0x00000000u;
goto P_0c064c0c;
P_0c064c0c: /* original 7f10, guest PC 0x0c064c0c */
if(!s->budget--) { s->failed_pc=0x0c064c0cu; return 0; }
r[15]+=0x00000010u;
goto P_0c064c0e;
P_0c064c0e: /* original 4f26, guest PC 0x0c064c0e */
if(!s->budget--) { s->failed_pc=0x0c064c0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c064c10;
P_0c064c10: /* original 6af6, guest PC 0x0c064c10 */
if(!s->budget--) { s->failed_pc=0x0c064c10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c064c12;
P_0c064c12: /* original 6bf6, guest PC 0x0c064c12 */
if(!s->budget--) { s->failed_pc=0x0c064c12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c064c14;
P_0c064c14: /* original 6cf6, guest PC 0x0c064c14 */
if(!s->budget--) { s->failed_pc=0x0c064c14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c064c16;
P_0c064c16: /* original 6df6, guest PC 0x0c064c16 */
if(!s->budget--) { s->failed_pc=0x0c064c16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c064c18;
P_0c064c18: /* original 000b, guest PC 0x0c064c18 */
if(!s->budget--) { s->failed_pc=0x0c064c18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c064c1a: /* original 6ef6, guest PC 0x0c064c1a */
if(!s->budget--) { s->failed_pc=0x0c064c1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c064c1cu,s,ram);
P_0c064c28: /* original 4f22, guest PC 0x0c064c28 */
if(!s->budget--) { s->failed_pc=0x0c064c28u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064c2a;
P_0c064c2a: /* original 7ff4, guest PC 0x0c064c2a */
if(!s->budget--) { s->failed_pc=0x0c064c2au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c064c2c;
P_0c064c2c: /* original 6342, guest PC 0x0c064c2c */
if(!s->budget--) { s->failed_pc=0x0c064c2cu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064c2e;
P_0c064c2e: /* original 65f3, guest PC 0x0c064c2e */
if(!s->budget--) { s->failed_pc=0x0c064c2eu; return 0; }
r[5]=r[15];
goto P_0c064c30;
P_0c064c30: /* original 6e53, guest PC 0x0c064c30 */
if(!s->budget--) { s->failed_pc=0x0c064c30u; return 0; }
r[14]=r[5];
goto P_0c064c32;
P_0c064c32: /* original 6ae3, guest PC 0x0c064c32 */
if(!s->budget--) { s->failed_pc=0x0c064c32u; return 0; }
r[10]=r[14];
goto P_0c064c34;
P_0c064c34: /* original 2e32, guest PC 0x0c064c34 */
if(!s->budget--) { s->failed_pc=0x0c064c34u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c064c36;
P_0c064c36: /* original 6be3, guest PC 0x0c064c36 */
if(!s->budget--) { s->failed_pc=0x0c064c36u; return 0; }
r[11]=r[14];
goto P_0c064c38;
P_0c064c38: /* original 5241, guest PC 0x0c064c38 */
if(!s->budget--) { s->failed_pc=0x0c064c38u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c064c3a;
P_0c064c3a: /* original 7a04, guest PC 0x0c064c3a */
if(!s->budget--) { s->failed_pc=0x0c064c3au; return 0; }
r[10]+=0x00000004u;
goto P_0c064c3c;
P_0c064c3c: /* original 2a22, guest PC 0x0c064c3c */
if(!s->budget--) { s->failed_pc=0x0c064c3cu; return 0; }
write(ram,r[10],r[2],4);
goto P_0c064c3e;
P_0c064c3e: /* original 7b08, guest PC 0x0c064c3e */
if(!s->budget--) { s->failed_pc=0x0c064c3eu; return 0; }
r[11]+=0x00000008u;
goto P_0c064c40;
P_0c064c40: /* original 5342, guest PC 0x0c064c40 */
if(!s->budget--) { s->failed_pc=0x0c064c40u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c064c42;
P_0c064c42: /* original 2b32, guest PC 0x0c064c42 */
if(!s->budget--) { s->failed_pc=0x0c064c42u; return 0; }
write(ram,r[11],r[3],4);
goto P_0c064c44;
P_0c064c44: /* original d24c, guest PC 0x0c064c44 */
if(!s->budget--) { s->failed_pc=0x0c064c44u; return 0; }
r[2]=read(ram,0x0c064d78u,4);
goto P_0c064c46;
P_0c064c46: /* original 6d22, guest PC 0x0c064c46 */
if(!s->budget--) { s->failed_pc=0x0c064c46u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c064c48;
P_0c064c48: /* original d34c, guest PC 0x0c064c48 */
if(!s->budget--) { s->failed_pc=0x0c064c48u; return 0; }
r[3]=read(ram,0x0c064d7cu,4);
goto P_0c064c4a;
P_0c064c4a: /* original 6432, guest PC 0x0c064c4a */
if(!s->budget--) { s->failed_pc=0x0c064c4au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c064c4c;
P_0c064c4c: /* original d14c, guest PC 0x0c064c4c */
if(!s->budget--) { s->failed_pc=0x0c064c4cu; return 0; }
r[1]=read(ram,0x0c064d80u,4);
goto P_0c064c4e;
P_0c064c4e: /* original 6512, guest PC 0x0c064c4e */
if(!s->budget--) { s->failed_pc=0x0c064c4eu; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c064c50;
P_0c064c50: /* original d04c, guest PC 0x0c064c50 */
if(!s->budget--) { s->failed_pc=0x0c064c50u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064c52;
P_0c064c52: /* original 62c3, guest PC 0x0c064c52 */
if(!s->budget--) { s->failed_pc=0x0c064c52u; return 0; }
r[2]=r[12];
goto P_0c064c54;
P_0c064c54: /* original 7c01, guest PC 0x0c064c54 */
if(!s->budget--) { s->failed_pc=0x0c064c54u; return 0; }
r[12]+=0x00000001u;
goto P_0c064c56;
P_0c064c56: /* original 4208, guest PC 0x0c064c56 */
if(!s->budget--) { s->failed_pc=0x0c064c56u; return 0; }
r[2]<<=2;
goto P_0c064c58;
P_0c064c58: /* original 02d6, guest PC 0x0c064c58 */
if(!s->budget--) { s->failed_pc=0x0c064c58u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c064c5a;
P_0c064c5a: /* original 63c3, guest PC 0x0c064c5a */
if(!s->budget--) { s->failed_pc=0x0c064c5au; return 0; }
r[3]=r[12];
goto P_0c064c5c;
P_0c064c5c: /* original 7c01, guest PC 0x0c064c5c */
if(!s->budget--) { s->failed_pc=0x0c064c5cu; return 0; }
r[12]+=0x00000001u;
goto P_0c064c5e;
P_0c064c5e: /* original 4308, guest PC 0x0c064c5e */
if(!s->budget--) { s->failed_pc=0x0c064c5eu; return 0; }
r[3]<<=2;
goto P_0c064c60;
P_0c064c60: /* original 0346, guest PC 0x0c064c60 */
if(!s->budget--) { s->failed_pc=0x0c064c60u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c064c62;
P_0c064c62: /* original 62c3, guest PC 0x0c064c62 */
if(!s->budget--) { s->failed_pc=0x0c064c62u; return 0; }
r[2]=r[12];
goto P_0c064c64;
P_0c064c64: /* original 7c01, guest PC 0x0c064c64 */
if(!s->budget--) { s->failed_pc=0x0c064c64u; return 0; }
r[12]+=0x00000001u;
goto P_0c064c66;
P_0c064c66: /* original 4208, guest PC 0x0c064c66 */
if(!s->budget--) { s->failed_pc=0x0c064c66u; return 0; }
r[2]<<=2;
goto P_0c064c68;
P_0c064c68: /* original 0256, guest PC 0x0c064c68 */
if(!s->budget--) { s->failed_pc=0x0c064c68u; return 0; }
write(ram,r[2]+r[0],r[5],4);
goto P_0c064c6a;
P_0c064c6a: /* original 63c3, guest PC 0x0c064c6a */
if(!s->budget--) { s->failed_pc=0x0c064c6au; return 0; }
r[3]=r[12];
goto P_0c064c6c;
P_0c064c6c: /* original 62e2, guest PC 0x0c064c6c */
if(!s->budget--) { s->failed_pc=0x0c064c6cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c064c6e;
P_0c064c6e: /* original 7c01, guest PC 0x0c064c6e */
if(!s->budget--) { s->failed_pc=0x0c064c6eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064c70;
P_0c064c70: /* original 5221, guest PC 0x0c064c70 */
if(!s->budget--) { s->failed_pc=0x0c064c70u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c064c72;
P_0c064c72: /* original 4308, guest PC 0x0c064c72 */
if(!s->budget--) { s->failed_pc=0x0c064c72u; return 0; }
r[3]<<=2;
goto P_0c064c74;
P_0c064c74: /* original 0326, guest PC 0x0c064c74 */
if(!s->budget--) { s->failed_pc=0x0c064c74u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064c76;
P_0c064c76: /* original 63c3, guest PC 0x0c064c76 */
if(!s->budget--) { s->failed_pc=0x0c064c76u; return 0; }
r[3]=r[12];
goto P_0c064c78;
P_0c064c78: /* original 62e2, guest PC 0x0c064c78 */
if(!s->budget--) { s->failed_pc=0x0c064c78u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c064c7a;
P_0c064c7a: /* original 7c01, guest PC 0x0c064c7a */
if(!s->budget--) { s->failed_pc=0x0c064c7au; return 0; }
r[12]+=0x00000001u;
goto P_0c064c7c;
P_0c064c7c: /* original 5222, guest PC 0x0c064c7c */
if(!s->budget--) { s->failed_pc=0x0c064c7cu; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c064c7e;
P_0c064c7e: /* original 4308, guest PC 0x0c064c7e */
if(!s->budget--) { s->failed_pc=0x0c064c7eu; return 0; }
r[3]<<=2;
goto P_0c064c80;
P_0c064c80: /* original 0326, guest PC 0x0c064c80 */
if(!s->budget--) { s->failed_pc=0x0c064c80u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064c82;
P_0c064c82: /* original 63c3, guest PC 0x0c064c82 */
if(!s->budget--) { s->failed_pc=0x0c064c82u; return 0; }
r[3]=r[12];
goto P_0c064c84;
P_0c064c84: /* original 62e2, guest PC 0x0c064c84 */
if(!s->budget--) { s->failed_pc=0x0c064c84u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c064c86;
P_0c064c86: /* original 7c01, guest PC 0x0c064c86 */
if(!s->budget--) { s->failed_pc=0x0c064c86u; return 0; }
r[12]+=0x00000001u;
goto P_0c064c88;
P_0c064c88: /* original 5223, guest PC 0x0c064c88 */
if(!s->budget--) { s->failed_pc=0x0c064c88u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c064c8a;
P_0c064c8a: /* original 4308, guest PC 0x0c064c8a */
if(!s->budget--) { s->failed_pc=0x0c064c8au; return 0; }
r[3]<<=2;
goto P_0c064c8c;
P_0c064c8c: /* original 0326, guest PC 0x0c064c8c */
if(!s->budget--) { s->failed_pc=0x0c064c8cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064c8e;
P_0c064c8e: /* original 65c3, guest PC 0x0c064c8e */
if(!s->budget--) { s->failed_pc=0x0c064c8eu; return 0; }
r[5]=r[12];
goto P_0c064c90;
P_0c064c90: /* original 66e2, guest PC 0x0c064c90 */
if(!s->budget--) { s->failed_pc=0x0c064c90u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c064c92;
P_0c064c92: /* original 5664, guest PC 0x0c064c92 */
if(!s->budget--) { s->failed_pc=0x0c064c92u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064c94;
P_0c064c94: /* original bc56, guest PC 0x0c064c94 */
if(!s->budget--) { s->failed_pc=0x0c064c94u; return 0; }
target=0x0c064544u; r[16]=0x0c064c98u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064c98u) { target=s->pc; goto dispatch; }
goto P_0c064c98;
P_0c064c96: /* original 64d3, guest PC 0x0c064c96 */
if(!s->budget--) { s->failed_pc=0x0c064c96u; return 0; }
r[4]=r[13];
goto P_0c064c98;
P_0c064c98: /* original 63e2, guest PC 0x0c064c98 */
if(!s->budget--) { s->failed_pc=0x0c064c98u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c064c9a;
P_0c064c9a: /* original 6c03, guest PC 0x0c064c9a */
if(!s->budget--) { s->failed_pc=0x0c064c9au; return 0; }
r[12]=r[0];
goto P_0c064c9c;
P_0c064c9c: /* original 5136, guest PC 0x0c064c9c */
if(!s->budget--) { s->failed_pc=0x0c064c9cu; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064c9e;
P_0c064c9e: /* original 62c3, guest PC 0x0c064c9e */
if(!s->budget--) { s->failed_pc=0x0c064c9eu; return 0; }
r[2]=r[12];
goto P_0c064ca0;
P_0c064ca0: /* original d038, guest PC 0x0c064ca0 */
if(!s->budget--) { s->failed_pc=0x0c064ca0u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064ca2;
P_0c064ca2: /* original 7c01, guest PC 0x0c064ca2 */
if(!s->budget--) { s->failed_pc=0x0c064ca2u; return 0; }
r[12]+=0x00000001u;
goto P_0c064ca4;
P_0c064ca4: /* original 4208, guest PC 0x0c064ca4 */
if(!s->budget--) { s->failed_pc=0x0c064ca4u; return 0; }
r[2]<<=2;
goto P_0c064ca6;
P_0c064ca6: /* original 0216, guest PC 0x0c064ca6 */
if(!s->budget--) { s->failed_pc=0x0c064ca6u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064ca8;
P_0c064ca8: /* original 66e2, guest PC 0x0c064ca8 */
if(!s->budget--) { s->failed_pc=0x0c064ca8u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c064caa;
P_0c064caa: /* original 65c3, guest PC 0x0c064caa */
if(!s->budget--) { s->failed_pc=0x0c064caau; return 0; }
r[5]=r[12];
goto P_0c064cac;
P_0c064cac: /* original 5667, guest PC 0x0c064cac */
if(!s->budget--) { s->failed_pc=0x0c064cacu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064cae;
P_0c064cae: /* original bc3f, guest PC 0x0c064cae */
if(!s->budget--) { s->failed_pc=0x0c064caeu; return 0; }
target=0x0c064530u; r[16]=0x0c064cb2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064cb2u) { target=s->pc; goto dispatch; }
goto P_0c064cb2;
P_0c064cb0: /* original 64d3, guest PC 0x0c064cb0 */
if(!s->budget--) { s->failed_pc=0x0c064cb0u; return 0; }
r[4]=r[13];
goto P_0c064cb2;
P_0c064cb2: /* original 6c03, guest PC 0x0c064cb2 */
if(!s->budget--) { s->failed_pc=0x0c064cb2u; return 0; }
r[12]=r[0];
goto P_0c064cb4;
P_0c064cb4: /* original 61a2, guest PC 0x0c064cb4 */
if(!s->budget--) { s->failed_pc=0x0c064cb4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064cb6;
P_0c064cb6: /* original 62c3, guest PC 0x0c064cb6 */
if(!s->budget--) { s->failed_pc=0x0c064cb6u; return 0; }
r[2]=r[12];
goto P_0c064cb8;
P_0c064cb8: /* original d032, guest PC 0x0c064cb8 */
if(!s->budget--) { s->failed_pc=0x0c064cb8u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064cba;
P_0c064cba: /* original 7c01, guest PC 0x0c064cba */
if(!s->budget--) { s->failed_pc=0x0c064cbau; return 0; }
r[12]+=0x00000001u;
goto P_0c064cbc;
P_0c064cbc: /* original 5311, guest PC 0x0c064cbc */
if(!s->budget--) { s->failed_pc=0x0c064cbcu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064cbe;
P_0c064cbe: /* original 4208, guest PC 0x0c064cbe */
if(!s->budget--) { s->failed_pc=0x0c064cbeu; return 0; }
r[2]<<=2;
goto P_0c064cc0;
P_0c064cc0: /* original 0236, guest PC 0x0c064cc0 */
if(!s->budget--) { s->failed_pc=0x0c064cc0u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064cc2;
P_0c064cc2: /* original 62c3, guest PC 0x0c064cc2 */
if(!s->budget--) { s->failed_pc=0x0c064cc2u; return 0; }
r[2]=r[12];
goto P_0c064cc4;
P_0c064cc4: /* original 61a2, guest PC 0x0c064cc4 */
if(!s->budget--) { s->failed_pc=0x0c064cc4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064cc6;
P_0c064cc6: /* original 7c01, guest PC 0x0c064cc6 */
if(!s->budget--) { s->failed_pc=0x0c064cc6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064cc8;
P_0c064cc8: /* original 5312, guest PC 0x0c064cc8 */
if(!s->budget--) { s->failed_pc=0x0c064cc8u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064cca;
P_0c064cca: /* original 4208, guest PC 0x0c064cca */
if(!s->budget--) { s->failed_pc=0x0c064ccau; return 0; }
r[2]<<=2;
goto P_0c064ccc;
P_0c064ccc: /* original 0236, guest PC 0x0c064ccc */
if(!s->budget--) { s->failed_pc=0x0c064cccu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064cce;
P_0c064cce: /* original 62c3, guest PC 0x0c064cce */
if(!s->budget--) { s->failed_pc=0x0c064cceu; return 0; }
r[2]=r[12];
goto P_0c064cd0;
P_0c064cd0: /* original 61a2, guest PC 0x0c064cd0 */
if(!s->budget--) { s->failed_pc=0x0c064cd0u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064cd2;
P_0c064cd2: /* original 7c01, guest PC 0x0c064cd2 */
if(!s->budget--) { s->failed_pc=0x0c064cd2u; return 0; }
r[12]+=0x00000001u;
goto P_0c064cd4;
P_0c064cd4: /* original 5313, guest PC 0x0c064cd4 */
if(!s->budget--) { s->failed_pc=0x0c064cd4u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064cd6;
P_0c064cd6: /* original 4208, guest PC 0x0c064cd6 */
if(!s->budget--) { s->failed_pc=0x0c064cd6u; return 0; }
r[2]<<=2;
goto P_0c064cd8;
P_0c064cd8: /* original 0236, guest PC 0x0c064cd8 */
if(!s->budget--) { s->failed_pc=0x0c064cd8u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064cda;
P_0c064cda: /* original 65c3, guest PC 0x0c064cda */
if(!s->budget--) { s->failed_pc=0x0c064cdau; return 0; }
r[5]=r[12];
goto P_0c064cdc;
P_0c064cdc: /* original 66a2, guest PC 0x0c064cdc */
if(!s->budget--) { s->failed_pc=0x0c064cdcu; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c064cde;
P_0c064cde: /* original 5664, guest PC 0x0c064cde */
if(!s->budget--) { s->failed_pc=0x0c064cdeu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064ce0;
P_0c064ce0: /* original bc30, guest PC 0x0c064ce0 */
if(!s->budget--) { s->failed_pc=0x0c064ce0u; return 0; }
target=0x0c064544u; r[16]=0x0c064ce4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064ce4u) { target=s->pc; goto dispatch; }
goto P_0c064ce4;
P_0c064ce2: /* original 64d3, guest PC 0x0c064ce2 */
if(!s->budget--) { s->failed_pc=0x0c064ce2u; return 0; }
r[4]=r[13];
goto P_0c064ce4;
P_0c064ce4: /* original 63a2, guest PC 0x0c064ce4 */
if(!s->budget--) { s->failed_pc=0x0c064ce4u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c064ce6;
P_0c064ce6: /* original 6c03, guest PC 0x0c064ce6 */
if(!s->budget--) { s->failed_pc=0x0c064ce6u; return 0; }
r[12]=r[0];
goto P_0c064ce8;
P_0c064ce8: /* original 5136, guest PC 0x0c064ce8 */
if(!s->budget--) { s->failed_pc=0x0c064ce8u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064cea;
P_0c064cea: /* original 62c3, guest PC 0x0c064cea */
if(!s->budget--) { s->failed_pc=0x0c064ceau; return 0; }
r[2]=r[12];
goto P_0c064cec;
P_0c064cec: /* original d025, guest PC 0x0c064cec */
if(!s->budget--) { s->failed_pc=0x0c064cecu; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064cee;
P_0c064cee: /* original 7c01, guest PC 0x0c064cee */
if(!s->budget--) { s->failed_pc=0x0c064ceeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064cf0;
P_0c064cf0: /* original 4208, guest PC 0x0c064cf0 */
if(!s->budget--) { s->failed_pc=0x0c064cf0u; return 0; }
r[2]<<=2;
goto P_0c064cf2;
P_0c064cf2: /* original 0216, guest PC 0x0c064cf2 */
if(!s->budget--) { s->failed_pc=0x0c064cf2u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064cf4;
P_0c064cf4: /* original 66e2, guest PC 0x0c064cf4 */
if(!s->budget--) { s->failed_pc=0x0c064cf4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c064cf6;
P_0c064cf6: /* original 65c3, guest PC 0x0c064cf6 */
if(!s->budget--) { s->failed_pc=0x0c064cf6u; return 0; }
r[5]=r[12];
goto P_0c064cf8;
P_0c064cf8: /* original 5667, guest PC 0x0c064cf8 */
if(!s->budget--) { s->failed_pc=0x0c064cf8u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064cfa;
P_0c064cfa: /* original bc19, guest PC 0x0c064cfa */
if(!s->budget--) { s->failed_pc=0x0c064cfau; return 0; }
target=0x0c064530u; r[16]=0x0c064cfeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064cfeu) { target=s->pc; goto dispatch; }
goto P_0c064cfe;
P_0c064cfc: /* original 64d3, guest PC 0x0c064cfc */
if(!s->budget--) { s->failed_pc=0x0c064cfcu; return 0; }
r[4]=r[13];
goto P_0c064cfe;
P_0c064cfe: /* original 6c03, guest PC 0x0c064cfe */
if(!s->budget--) { s->failed_pc=0x0c064cfeu; return 0; }
r[12]=r[0];
goto P_0c064d00;
P_0c064d00: /* original 61b2, guest PC 0x0c064d00 */
if(!s->budget--) { s->failed_pc=0x0c064d00u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064d02;
P_0c064d02: /* original 62c3, guest PC 0x0c064d02 */
if(!s->budget--) { s->failed_pc=0x0c064d02u; return 0; }
r[2]=r[12];
goto P_0c064d04;
P_0c064d04: /* original d01f, guest PC 0x0c064d04 */
if(!s->budget--) { s->failed_pc=0x0c064d04u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064d06;
P_0c064d06: /* original 7c01, guest PC 0x0c064d06 */
if(!s->budget--) { s->failed_pc=0x0c064d06u; return 0; }
r[12]+=0x00000001u;
goto P_0c064d08;
P_0c064d08: /* original 5311, guest PC 0x0c064d08 */
if(!s->budget--) { s->failed_pc=0x0c064d08u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064d0a;
P_0c064d0a: /* original 4208, guest PC 0x0c064d0a */
if(!s->budget--) { s->failed_pc=0x0c064d0au; return 0; }
r[2]<<=2;
goto P_0c064d0c;
P_0c064d0c: /* original 0236, guest PC 0x0c064d0c */
if(!s->budget--) { s->failed_pc=0x0c064d0cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064d0e;
P_0c064d0e: /* original 62c3, guest PC 0x0c064d0e */
if(!s->budget--) { s->failed_pc=0x0c064d0eu; return 0; }
r[2]=r[12];
goto P_0c064d10;
P_0c064d10: /* original 61b2, guest PC 0x0c064d10 */
if(!s->budget--) { s->failed_pc=0x0c064d10u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064d12;
P_0c064d12: /* original 7c01, guest PC 0x0c064d12 */
if(!s->budget--) { s->failed_pc=0x0c064d12u; return 0; }
r[12]+=0x00000001u;
goto P_0c064d14;
P_0c064d14: /* original 5312, guest PC 0x0c064d14 */
if(!s->budget--) { s->failed_pc=0x0c064d14u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064d16;
P_0c064d16: /* original 4208, guest PC 0x0c064d16 */
if(!s->budget--) { s->failed_pc=0x0c064d16u; return 0; }
r[2]<<=2;
goto P_0c064d18;
P_0c064d18: /* original 0236, guest PC 0x0c064d18 */
if(!s->budget--) { s->failed_pc=0x0c064d18u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064d1a;
P_0c064d1a: /* original 62c3, guest PC 0x0c064d1a */
if(!s->budget--) { s->failed_pc=0x0c064d1au; return 0; }
r[2]=r[12];
goto P_0c064d1c;
P_0c064d1c: /* original 61b2, guest PC 0x0c064d1c */
if(!s->budget--) { s->failed_pc=0x0c064d1cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064d1e;
P_0c064d1e: /* original 7c01, guest PC 0x0c064d1e */
if(!s->budget--) { s->failed_pc=0x0c064d1eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064d20;
P_0c064d20: /* original 5313, guest PC 0x0c064d20 */
if(!s->budget--) { s->failed_pc=0x0c064d20u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064d22;
P_0c064d22: /* original 4208, guest PC 0x0c064d22 */
if(!s->budget--) { s->failed_pc=0x0c064d22u; return 0; }
r[2]<<=2;
goto P_0c064d24;
P_0c064d24: /* original 0236, guest PC 0x0c064d24 */
if(!s->budget--) { s->failed_pc=0x0c064d24u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064d26;
P_0c064d26: /* original 65c3, guest PC 0x0c064d26 */
if(!s->budget--) { s->failed_pc=0x0c064d26u; return 0; }
r[5]=r[12];
goto P_0c064d28;
P_0c064d28: /* original 66b2, guest PC 0x0c064d28 */
if(!s->budget--) { s->failed_pc=0x0c064d28u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c064d2a;
P_0c064d2a: /* original 5664, guest PC 0x0c064d2a */
if(!s->budget--) { s->failed_pc=0x0c064d2au; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064d2c;
P_0c064d2c: /* original bc0a, guest PC 0x0c064d2c */
if(!s->budget--) { s->failed_pc=0x0c064d2cu; return 0; }
target=0x0c064544u; r[16]=0x0c064d30u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064d30u) { target=s->pc; goto dispatch; }
goto P_0c064d30;
P_0c064d2e: /* original 64d3, guest PC 0x0c064d2e */
if(!s->budget--) { s->failed_pc=0x0c064d2eu; return 0; }
r[4]=r[13];
goto P_0c064d30;
P_0c064d30: /* original 63b2, guest PC 0x0c064d30 */
if(!s->budget--) { s->failed_pc=0x0c064d30u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c064d32;
P_0c064d32: /* original 6c03, guest PC 0x0c064d32 */
if(!s->budget--) { s->failed_pc=0x0c064d32u; return 0; }
r[12]=r[0];
goto P_0c064d34;
P_0c064d34: /* original 5136, guest PC 0x0c064d34 */
if(!s->budget--) { s->failed_pc=0x0c064d34u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064d36;
P_0c064d36: /* original 62c3, guest PC 0x0c064d36 */
if(!s->budget--) { s->failed_pc=0x0c064d36u; return 0; }
r[2]=r[12];
goto P_0c064d38;
P_0c064d38: /* original d012, guest PC 0x0c064d38 */
if(!s->budget--) { s->failed_pc=0x0c064d38u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064d3a;
P_0c064d3a: /* original 7c01, guest PC 0x0c064d3a */
if(!s->budget--) { s->failed_pc=0x0c064d3au; return 0; }
r[12]+=0x00000001u;
goto P_0c064d3c;
P_0c064d3c: /* original 4208, guest PC 0x0c064d3c */
if(!s->budget--) { s->failed_pc=0x0c064d3cu; return 0; }
r[2]<<=2;
goto P_0c064d3e;
P_0c064d3e: /* original 0216, guest PC 0x0c064d3e */
if(!s->budget--) { s->failed_pc=0x0c064d3eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064d40;
P_0c064d40: /* original 66e2, guest PC 0x0c064d40 */
if(!s->budget--) { s->failed_pc=0x0c064d40u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c064d42;
P_0c064d42: /* original 65c3, guest PC 0x0c064d42 */
if(!s->budget--) { s->failed_pc=0x0c064d42u; return 0; }
r[5]=r[12];
goto P_0c064d44;
P_0c064d44: /* original 5667, guest PC 0x0c064d44 */
if(!s->budget--) { s->failed_pc=0x0c064d44u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064d46;
P_0c064d46: /* original bbf3, guest PC 0x0c064d46 */
if(!s->budget--) { s->failed_pc=0x0c064d46u; return 0; }
target=0x0c064530u; r[16]=0x0c064d4au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064d4au) { target=s->pc; goto dispatch; }
goto P_0c064d4a;
P_0c064d48: /* original 64d3, guest PC 0x0c064d48 */
if(!s->budget--) { s->failed_pc=0x0c064d48u; return 0; }
r[4]=r[13];
goto P_0c064d4a;
P_0c064d4a: /* original 6403, guest PC 0x0c064d4a */
if(!s->budget--) { s->failed_pc=0x0c064d4au; return 0; }
r[4]=r[0];
goto P_0c064d4c;
P_0c064d4c: /* original d20e, guest PC 0x0c064d4c */
if(!s->budget--) { s->failed_pc=0x0c064d4cu; return 0; }
r[2]=read(ram,0x0c064d88u,4);
goto P_0c064d4e;
P_0c064d4e: /* original 4408, guest PC 0x0c064d4e */
if(!s->budget--) { s->failed_pc=0x0c064d4eu; return 0; }
r[4]<<=2;
goto P_0c064d50;
P_0c064d50: /* original 2242, guest PC 0x0c064d50 */
if(!s->budget--) { s->failed_pc=0x0c064d50u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c064d52;
P_0c064d52: /* original bbde, guest PC 0x0c064d52 */
if(!s->budget--) { s->failed_pc=0x0c064d52u; return 0; }
target=0x0c064512u; r[16]=0x0c064d56u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064d56u) { target=s->pc; goto dispatch; }
goto P_0c064d56;
P_0c064d54: /* original 64d3, guest PC 0x0c064d54 */
if(!s->budget--) { s->failed_pc=0x0c064d54u; return 0; }
r[4]=r[13];
goto P_0c064d56;
P_0c064d56: /* original 6403, guest PC 0x0c064d56 */
if(!s->budget--) { s->failed_pc=0x0c064d56u; return 0; }
r[4]=r[0];
goto P_0c064d58;
P_0c064d58: /* original e500, guest PC 0x0c064d58 */
if(!s->budget--) { s->failed_pc=0x0c064d58u; return 0; }
r[5]=0x00000000u;
goto P_0c064d5a;
P_0c064d5a: /* original bbc5, guest PC 0x0c064d5a */
if(!s->budget--) { s->failed_pc=0x0c064d5au; return 0; }
target=0x0c0644e8u; r[16]=0x0c064d5eu;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064d5eu) { target=s->pc; goto dispatch; }
goto P_0c064d5e;
P_0c064d5c: /* original 6653, guest PC 0x0c064d5c */
if(!s->budget--) { s->failed_pc=0x0c064d5cu; return 0; }
r[6]=r[5];
goto P_0c064d5e;
P_0c064d5e: /* original 62e2, guest PC 0x0c064d5e */
if(!s->budget--) { s->failed_pc=0x0c064d5eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c064d60;
P_0c064d60: /* original d10a, guest PC 0x0c064d60 */
if(!s->budget--) { s->failed_pc=0x0c064d60u; return 0; }
r[1]=read(ram,0x0c064d8cu,4);
goto P_0c064d62;
P_0c064d62: /* original 5323, guest PC 0x0c064d62 */
if(!s->budget--) { s->failed_pc=0x0c064d62u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c064d64;
P_0c064d64: /* original 2132, guest PC 0x0c064d64 */
if(!s->budget--) { s->failed_pc=0x0c064d64u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c064d66;
P_0c064d66: /* original e000, guest PC 0x0c064d66 */
if(!s->budget--) { s->failed_pc=0x0c064d66u; return 0; }
r[0]=0x00000000u;
goto P_0c064d68;
P_0c064d68: /* original 7f0c, guest PC 0x0c064d68 */
if(!s->budget--) { s->failed_pc=0x0c064d68u; return 0; }
r[15]+=0x0000000cu;
goto P_0c064d6a;
P_0c064d6a: /* original 4f26, guest PC 0x0c064d6a */
if(!s->budget--) { s->failed_pc=0x0c064d6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c064d6c;
P_0c064d6c: /* original 6af6, guest PC 0x0c064d6c */
if(!s->budget--) { s->failed_pc=0x0c064d6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c064d6e;
P_0c064d6e: /* original 6bf6, guest PC 0x0c064d6e */
if(!s->budget--) { s->failed_pc=0x0c064d6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c064d70;
P_0c064d70: /* original 6cf6, guest PC 0x0c064d70 */
if(!s->budget--) { s->failed_pc=0x0c064d70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c064d72;
P_0c064d72: /* original 6df6, guest PC 0x0c064d72 */
if(!s->budget--) { s->failed_pc=0x0c064d72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c064d74;
P_0c064d74: /* original 000b, guest PC 0x0c064d74 */
if(!s->budget--) { s->failed_pc=0x0c064d74u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c064d76: /* original 6ef6, guest PC 0x0c064d76 */
if(!s->budget--) { s->failed_pc=0x0c064d76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c064d78u,s,ram);
P_0c064da0: /* original 4f22, guest PC 0x0c064da0 */
if(!s->budget--) { s->failed_pc=0x0c064da0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064da2;
P_0c064da2: /* original 7ff0, guest PC 0x0c064da2 */
if(!s->budget--) { s->failed_pc=0x0c064da2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c064da4;
P_0c064da4: /* original 6342, guest PC 0x0c064da4 */
if(!s->budget--) { s->failed_pc=0x0c064da4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064da6;
P_0c064da6: /* original 65f3, guest PC 0x0c064da6 */
if(!s->budget--) { s->failed_pc=0x0c064da6u; return 0; }
r[5]=r[15];
goto P_0c064da8;
P_0c064da8: /* original 7504, guest PC 0x0c064da8 */
if(!s->budget--) { s->failed_pc=0x0c064da8u; return 0; }
r[5]+=0x00000004u;
goto P_0c064daa;
P_0c064daa: /* original 6d53, guest PC 0x0c064daa */
if(!s->budget--) { s->failed_pc=0x0c064daau; return 0; }
r[13]=r[5];
goto P_0c064dac;
P_0c064dac: /* original 2d32, guest PC 0x0c064dac */
if(!s->budget--) { s->failed_pc=0x0c064dacu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c064dae;
P_0c064dae: /* original 6bd3, guest PC 0x0c064dae */
if(!s->budget--) { s->failed_pc=0x0c064daeu; return 0; }
r[11]=r[13];
goto P_0c064db0;
P_0c064db0: /* original 5241, guest PC 0x0c064db0 */
if(!s->budget--) { s->failed_pc=0x0c064db0u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c064db2;
P_0c064db2: /* original 6ad3, guest PC 0x0c064db2 */
if(!s->budget--) { s->failed_pc=0x0c064db2u; return 0; }
r[10]=r[13];
goto P_0c064db4;
P_0c064db4: /* original 7b04, guest PC 0x0c064db4 */
if(!s->budget--) { s->failed_pc=0x0c064db4u; return 0; }
r[11]+=0x00000004u;
goto P_0c064db6;
P_0c064db6: /* original 7a08, guest PC 0x0c064db6 */
if(!s->budget--) { s->failed_pc=0x0c064db6u; return 0; }
r[10]+=0x00000008u;
goto P_0c064db8;
P_0c064db8: /* original 2b22, guest PC 0x0c064db8 */
if(!s->budget--) { s->failed_pc=0x0c064db8u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c064dba;
P_0c064dba: /* original 5342, guest PC 0x0c064dba */
if(!s->budget--) { s->failed_pc=0x0c064dbau; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c064dbc;
P_0c064dbc: /* original d2a7, guest PC 0x0c064dbc */
if(!s->budget--) { s->failed_pc=0x0c064dbcu; return 0; }
r[2]=read(ram,0x0c06505cu,4);
goto P_0c064dbe;
P_0c064dbe: /* original 2a32, guest PC 0x0c064dbe */
if(!s->budget--) { s->failed_pc=0x0c064dbeu; return 0; }
write(ram,r[10],r[3],4);
goto P_0c064dc0;
P_0c064dc0: /* original 6e22, guest PC 0x0c064dc0 */
if(!s->budget--) { s->failed_pc=0x0c064dc0u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c064dc2;
P_0c064dc2: /* original d3a7, guest PC 0x0c064dc2 */
if(!s->budget--) { s->failed_pc=0x0c064dc2u; return 0; }
r[3]=read(ram,0x0c065060u,4);
goto P_0c064dc4;
P_0c064dc4: /* original 6532, guest PC 0x0c064dc4 */
if(!s->budget--) { s->failed_pc=0x0c064dc4u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c064dc6;
P_0c064dc6: /* original d1a7, guest PC 0x0c064dc6 */
if(!s->budget--) { s->failed_pc=0x0c064dc6u; return 0; }
r[1]=read(ram,0x0c065064u,4);
goto P_0c064dc8;
P_0c064dc8: /* original 6412, guest PC 0x0c064dc8 */
if(!s->budget--) { s->failed_pc=0x0c064dc8u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c064dca;
P_0c064dca: /* original d0a7, guest PC 0x0c064dca */
if(!s->budget--) { s->failed_pc=0x0c064dcau; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064dcc;
P_0c064dcc: /* original 62c3, guest PC 0x0c064dcc */
if(!s->budget--) { s->failed_pc=0x0c064dccu; return 0; }
r[2]=r[12];
goto P_0c064dce;
P_0c064dce: /* original 7c01, guest PC 0x0c064dce */
if(!s->budget--) { s->failed_pc=0x0c064dceu; return 0; }
r[12]+=0x00000001u;
goto P_0c064dd0;
P_0c064dd0: /* original 4208, guest PC 0x0c064dd0 */
if(!s->budget--) { s->failed_pc=0x0c064dd0u; return 0; }
r[2]<<=2;
goto P_0c064dd2;
P_0c064dd2: /* original 02e6, guest PC 0x0c064dd2 */
if(!s->budget--) { s->failed_pc=0x0c064dd2u; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c064dd4;
P_0c064dd4: /* original 63c3, guest PC 0x0c064dd4 */
if(!s->budget--) { s->failed_pc=0x0c064dd4u; return 0; }
r[3]=r[12];
goto P_0c064dd6;
P_0c064dd6: /* original 7c01, guest PC 0x0c064dd6 */
if(!s->budget--) { s->failed_pc=0x0c064dd6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064dd8;
P_0c064dd8: /* original 4308, guest PC 0x0c064dd8 */
if(!s->budget--) { s->failed_pc=0x0c064dd8u; return 0; }
r[3]<<=2;
goto P_0c064dda;
P_0c064dda: /* original 0356, guest PC 0x0c064dda */
if(!s->budget--) { s->failed_pc=0x0c064ddau; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c064ddc;
P_0c064ddc: /* original 62c3, guest PC 0x0c064ddc */
if(!s->budget--) { s->failed_pc=0x0c064ddcu; return 0; }
r[2]=r[12];
goto P_0c064dde;
P_0c064dde: /* original 7c01, guest PC 0x0c064dde */
if(!s->budget--) { s->failed_pc=0x0c064ddeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064de0;
P_0c064de0: /* original 4208, guest PC 0x0c064de0 */
if(!s->budget--) { s->failed_pc=0x0c064de0u; return 0; }
r[2]<<=2;
goto P_0c064de2;
P_0c064de2: /* original 0246, guest PC 0x0c064de2 */
if(!s->budget--) { s->failed_pc=0x0c064de2u; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c064de4;
P_0c064de4: /* original 62d2, guest PC 0x0c064de4 */
if(!s->budget--) { s->failed_pc=0x0c064de4u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064de6;
P_0c064de6: /* original 63c3, guest PC 0x0c064de6 */
if(!s->budget--) { s->failed_pc=0x0c064de6u; return 0; }
r[3]=r[12];
goto P_0c064de8;
P_0c064de8: /* original 5221, guest PC 0x0c064de8 */
if(!s->budget--) { s->failed_pc=0x0c064de8u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c064dea;
P_0c064dea: /* original 7c01, guest PC 0x0c064dea */
if(!s->budget--) { s->failed_pc=0x0c064deau; return 0; }
r[12]+=0x00000001u;
goto P_0c064dec;
P_0c064dec: /* original 4308, guest PC 0x0c064dec */
if(!s->budget--) { s->failed_pc=0x0c064decu; return 0; }
r[3]<<=2;
goto P_0c064dee;
P_0c064dee: /* original 0326, guest PC 0x0c064dee */
if(!s->budget--) { s->failed_pc=0x0c064deeu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064df0;
P_0c064df0: /* original 62d2, guest PC 0x0c064df0 */
if(!s->budget--) { s->failed_pc=0x0c064df0u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064df2;
P_0c064df2: /* original 63c3, guest PC 0x0c064df2 */
if(!s->budget--) { s->failed_pc=0x0c064df2u; return 0; }
r[3]=r[12];
goto P_0c064df4;
P_0c064df4: /* original 5222, guest PC 0x0c064df4 */
if(!s->budget--) { s->failed_pc=0x0c064df4u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c064df6;
P_0c064df6: /* original 7c01, guest PC 0x0c064df6 */
if(!s->budget--) { s->failed_pc=0x0c064df6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064df8;
P_0c064df8: /* original 4308, guest PC 0x0c064df8 */
if(!s->budget--) { s->failed_pc=0x0c064df8u; return 0; }
r[3]<<=2;
goto P_0c064dfa;
P_0c064dfa: /* original 0326, guest PC 0x0c064dfa */
if(!s->budget--) { s->failed_pc=0x0c064dfau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064dfc;
P_0c064dfc: /* original 62d2, guest PC 0x0c064dfc */
if(!s->budget--) { s->failed_pc=0x0c064dfcu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064dfe;
P_0c064dfe: /* original 63c3, guest PC 0x0c064dfe */
if(!s->budget--) { s->failed_pc=0x0c064dfeu; return 0; }
r[3]=r[12];
goto P_0c064e00;
P_0c064e00: /* original 5223, guest PC 0x0c064e00 */
if(!s->budget--) { s->failed_pc=0x0c064e00u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c064e02;
P_0c064e02: /* original 7c01, guest PC 0x0c064e02 */
if(!s->budget--) { s->failed_pc=0x0c064e02u; return 0; }
r[12]+=0x00000001u;
goto P_0c064e04;
P_0c064e04: /* original 4308, guest PC 0x0c064e04 */
if(!s->budget--) { s->failed_pc=0x0c064e04u; return 0; }
r[3]<<=2;
goto P_0c064e06;
P_0c064e06: /* original 0326, guest PC 0x0c064e06 */
if(!s->budget--) { s->failed_pc=0x0c064e06u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064e08;
P_0c064e08: /* original 67d2, guest PC 0x0c064e08 */
if(!s->budget--) { s->failed_pc=0x0c064e08u; return 0; }
tmp=read(ram,r[13],4);
r[7]=tmp;
goto P_0c064e0a;
P_0c064e0a: /* original 2f72, guest PC 0x0c064e0a */
if(!s->budget--) { s->failed_pc=0x0c064e0au; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064e0c;
P_0c064e0c: /* original 5775, guest PC 0x0c064e0c */
if(!s->budget--) { s->failed_pc=0x0c064e0cu; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064e0e;
P_0c064e0e: /* original 65c3, guest PC 0x0c064e0e */
if(!s->budget--) { s->failed_pc=0x0c064e0eu; return 0; }
r[5]=r[12];
goto P_0c064e10;
P_0c064e10: /* original 66f2, guest PC 0x0c064e10 */
if(!s->budget--) { s->failed_pc=0x0c064e10u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064e12;
P_0c064e12: /* original 5664, guest PC 0x0c064e12 */
if(!s->budget--) { s->failed_pc=0x0c064e12u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064e14;
P_0c064e14: /* original bbb0, guest PC 0x0c064e14 */
if(!s->budget--) { s->failed_pc=0x0c064e14u; return 0; }
target=0x0c064578u; r[16]=0x0c064e18u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064e18u) { target=s->pc; goto dispatch; }
goto P_0c064e18;
P_0c064e16: /* original 64e3, guest PC 0x0c064e16 */
if(!s->budget--) { s->failed_pc=0x0c064e16u; return 0; }
r[4]=r[14];
goto P_0c064e18;
P_0c064e18: /* original 64d2, guest PC 0x0c064e18 */
if(!s->budget--) { s->failed_pc=0x0c064e18u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c064e1a;
P_0c064e1a: /* original e120, guest PC 0x0c064e1a */
if(!s->budget--) { s->failed_pc=0x0c064e1au; return 0; }
r[1]=0x00000020u;
goto P_0c064e1c;
P_0c064e1c: /* original 6903, guest PC 0x0c064e1c */
if(!s->budget--) { s->failed_pc=0x0c064e1cu; return 0; }
r[9]=r[0];
goto P_0c064e1e;
P_0c064e1e: /* original 6393, guest PC 0x0c064e1e */
if(!s->budget--) { s->failed_pc=0x0c064e1eu; return 0; }
r[3]=r[9];
goto P_0c064e20;
P_0c064e20: /* original c792, guest PC 0x0c064e20 */
if(!s->budget--) { s->failed_pc=0x0c064e20u; return 0; }
r[0]=0x0c06506cu;
goto P_0c064e22;
P_0c064e22: /* original 314c, guest PC 0x0c064e22 */
if(!s->budget--) { s->failed_pc=0x0c064e22u; return 0; }
r[1]+=r[4];
goto P_0c064e24;
P_0c064e24: /* original ff08, guest PC 0x0c064e24 */
if(!s->budget--) { s->failed_pc=0x0c064e24u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c064e26;
P_0c064e26: /* original 7901, guest PC 0x0c064e26 */
if(!s->budget--) { s->failed_pc=0x0c064e26u; return 0; }
r[9]+=0x00000001u;
goto P_0c064e28;
P_0c064e28: /* original f318, guest PC 0x0c064e28 */
if(!s->budget--) { s->failed_pc=0x0c064e28u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064e2a;
P_0c064e2a: /* original 4308, guest PC 0x0c064e2a */
if(!s->budget--) { s->failed_pc=0x0c064e2au; return 0; }
r[3]<<=2;
goto P_0c064e2c;
P_0c064e2c: /* original d08e, guest PC 0x0c064e2c */
if(!s->budget--) { s->failed_pc=0x0c064e2cu; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064e2e;
P_0c064e2e: /* original f3f2, guest PC 0x0c064e2e */
if(!s->budget--) { s->failed_pc=0x0c064e2eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e30;
P_0c064e30: /* original f33d, guest PC 0x0c064e30 */
if(!s->budget--) { s->failed_pc=0x0c064e30u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e32;
P_0c064e32: /* original e124, guest PC 0x0c064e32 */
if(!s->budget--) { s->failed_pc=0x0c064e32u; return 0; }
r[1]=0x00000024u;
goto P_0c064e34;
P_0c064e34: /* original 025a, guest PC 0x0c064e34 */
if(!s->budget--) { s->failed_pc=0x0c064e34u; return 0; }
r[2]=r[53];
goto P_0c064e36;
P_0c064e36: /* original 4228, guest PC 0x0c064e36 */
if(!s->budget--) { s->failed_pc=0x0c064e36u; return 0; }
r[2]<<=16;
goto P_0c064e38;
P_0c064e38: /* original 4218, guest PC 0x0c064e38 */
if(!s->budget--) { s->failed_pc=0x0c064e38u; return 0; }
r[2]<<=8;
goto P_0c064e3a;
P_0c064e3a: /* original 314c, guest PC 0x0c064e3a */
if(!s->budget--) { s->failed_pc=0x0c064e3au; return 0; }
r[1]+=r[4];
goto P_0c064e3c;
P_0c064e3c: /* original f318, guest PC 0x0c064e3c */
if(!s->budget--) { s->failed_pc=0x0c064e3cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064e3e;
P_0c064e3e: /* original f3f2, guest PC 0x0c064e3e */
if(!s->budget--) { s->failed_pc=0x0c064e3eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e40;
P_0c064e40: /* original f33d, guest PC 0x0c064e40 */
if(!s->budget--) { s->failed_pc=0x0c064e40u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e42;
P_0c064e42: /* original 015a, guest PC 0x0c064e42 */
if(!s->budget--) { s->failed_pc=0x0c064e42u; return 0; }
r[1]=r[53];
goto P_0c064e44;
P_0c064e44: /* original 4128, guest PC 0x0c064e44 */
if(!s->budget--) { s->failed_pc=0x0c064e44u; return 0; }
r[1]<<=16;
goto P_0c064e46;
P_0c064e46: /* original 221b, guest PC 0x0c064e46 */
if(!s->budget--) { s->failed_pc=0x0c064e46u; return 0; }
r[2]|=r[1];
goto P_0c064e48;
P_0c064e48: /* original e128, guest PC 0x0c064e48 */
if(!s->budget--) { s->failed_pc=0x0c064e48u; return 0; }
r[1]=0x00000028u;
goto P_0c064e4a;
P_0c064e4a: /* original 314c, guest PC 0x0c064e4a */
if(!s->budget--) { s->failed_pc=0x0c064e4au; return 0; }
r[1]+=r[4];
goto P_0c064e4c;
P_0c064e4c: /* original f318, guest PC 0x0c064e4c */
if(!s->budget--) { s->failed_pc=0x0c064e4cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064e4e;
P_0c064e4e: /* original f3f2, guest PC 0x0c064e4e */
if(!s->budget--) { s->failed_pc=0x0c064e4eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e50;
P_0c064e50: /* original f33d, guest PC 0x0c064e50 */
if(!s->budget--) { s->failed_pc=0x0c064e50u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e52;
P_0c064e52: /* original 015a, guest PC 0x0c064e52 */
if(!s->budget--) { s->failed_pc=0x0c064e52u; return 0; }
r[1]=r[53];
goto P_0c064e54;
P_0c064e54: /* original 4118, guest PC 0x0c064e54 */
if(!s->budget--) { s->failed_pc=0x0c064e54u; return 0; }
r[1]<<=8;
goto P_0c064e56;
P_0c064e56: /* original 221b, guest PC 0x0c064e56 */
if(!s->budget--) { s->failed_pc=0x0c064e56u; return 0; }
r[2]|=r[1];
goto P_0c064e58;
P_0c064e58: /* original e12c, guest PC 0x0c064e58 */
if(!s->budget--) { s->failed_pc=0x0c064e58u; return 0; }
r[1]=0x0000002cu;
goto P_0c064e5a;
P_0c064e5a: /* original 314c, guest PC 0x0c064e5a */
if(!s->budget--) { s->failed_pc=0x0c064e5au; return 0; }
r[1]+=r[4];
goto P_0c064e5c;
P_0c064e5c: /* original f318, guest PC 0x0c064e5c */
if(!s->budget--) { s->failed_pc=0x0c064e5cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064e5e;
P_0c064e5e: /* original f3f2, guest PC 0x0c064e5e */
if(!s->budget--) { s->failed_pc=0x0c064e5eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e60;
P_0c064e60: /* original f33d, guest PC 0x0c064e60 */
if(!s->budget--) { s->failed_pc=0x0c064e60u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e62;
P_0c064e62: /* original 015a, guest PC 0x0c064e62 */
if(!s->budget--) { s->failed_pc=0x0c064e62u; return 0; }
r[1]=r[53];
goto P_0c064e64;
P_0c064e64: /* original 221b, guest PC 0x0c064e64 */
if(!s->budget--) { s->failed_pc=0x0c064e64u; return 0; }
r[2]|=r[1];
goto P_0c064e66;
P_0c064e66: /* original 0326, guest PC 0x0c064e66 */
if(!s->budget--) { s->failed_pc=0x0c064e66u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064e68;
P_0c064e68: /* original 6cd2, guest PC 0x0c064e68 */
if(!s->budget--) { s->failed_pc=0x0c064e68u; return 0; }
tmp=read(ram,r[13],4);
r[12]=tmp;
goto P_0c064e6a;
P_0c064e6a: /* original e030, guest PC 0x0c064e6a */
if(!s->budget--) { s->failed_pc=0x0c064e6au; return 0; }
r[0]=0x00000030u;
goto P_0c064e6c;
P_0c064e6c: /* original f3c6, guest PC 0x0c064e6c */
if(!s->budget--) { s->failed_pc=0x0c064e6cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064e6e;
P_0c064e6e: /* original e034, guest PC 0x0c064e6e */
if(!s->budget--) { s->failed_pc=0x0c064e6eu; return 0; }
r[0]=0x00000034u;
goto P_0c064e70;
P_0c064e70: /* original f3f2, guest PC 0x0c064e70 */
if(!s->budget--) { s->failed_pc=0x0c064e70u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e72;
P_0c064e72: /* original f33d, guest PC 0x0c064e72 */
if(!s->budget--) { s->failed_pc=0x0c064e72u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e74;
P_0c064e74: /* original f3c6, guest PC 0x0c064e74 */
if(!s->budget--) { s->failed_pc=0x0c064e74u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064e76;
P_0c064e76: /* original 065a, guest PC 0x0c064e76 */
if(!s->budget--) { s->failed_pc=0x0c064e76u; return 0; }
r[6]=r[53];
goto P_0c064e78;
P_0c064e78: /* original 4628, guest PC 0x0c064e78 */
if(!s->budget--) { s->failed_pc=0x0c064e78u; return 0; }
r[6]<<=16;
goto P_0c064e7a;
P_0c064e7a: /* original 4618, guest PC 0x0c064e7a */
if(!s->budget--) { s->failed_pc=0x0c064e7au; return 0; }
r[6]<<=8;
goto P_0c064e7c;
P_0c064e7c: /* original f3f2, guest PC 0x0c064e7c */
if(!s->budget--) { s->failed_pc=0x0c064e7cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e7e;
P_0c064e7e: /* original e038, guest PC 0x0c064e7e */
if(!s->budget--) { s->failed_pc=0x0c064e7eu; return 0; }
r[0]=0x00000038u;
goto P_0c064e80;
P_0c064e80: /* original f33d, guest PC 0x0c064e80 */
if(!s->budget--) { s->failed_pc=0x0c064e80u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e82;
P_0c064e82: /* original 035a, guest PC 0x0c064e82 */
if(!s->budget--) { s->failed_pc=0x0c064e82u; return 0; }
r[3]=r[53];
goto P_0c064e84;
P_0c064e84: /* original f3c6, guest PC 0x0c064e84 */
if(!s->budget--) { s->failed_pc=0x0c064e84u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064e86;
P_0c064e86: /* original 4328, guest PC 0x0c064e86 */
if(!s->budget--) { s->failed_pc=0x0c064e86u; return 0; }
r[3]<<=16;
goto P_0c064e88;
P_0c064e88: /* original 263b, guest PC 0x0c064e88 */
if(!s->budget--) { s->failed_pc=0x0c064e88u; return 0; }
r[6]|=r[3];
goto P_0c064e8a;
P_0c064e8a: /* original f3f2, guest PC 0x0c064e8a */
if(!s->budget--) { s->failed_pc=0x0c064e8au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e8c;
P_0c064e8c: /* original f33d, guest PC 0x0c064e8c */
if(!s->budget--) { s->failed_pc=0x0c064e8cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e8e;
P_0c064e8e: /* original e03c, guest PC 0x0c064e8e */
if(!s->budget--) { s->failed_pc=0x0c064e8eu; return 0; }
r[0]=0x0000003cu;
goto P_0c064e90;
P_0c064e90: /* original f3c6, guest PC 0x0c064e90 */
if(!s->budget--) { s->failed_pc=0x0c064e90u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064e92;
P_0c064e92: /* original 035a, guest PC 0x0c064e92 */
if(!s->budget--) { s->failed_pc=0x0c064e92u; return 0; }
r[3]=r[53];
goto P_0c064e94;
P_0c064e94: /* original 4318, guest PC 0x0c064e94 */
if(!s->budget--) { s->failed_pc=0x0c064e94u; return 0; }
r[3]<<=8;
goto P_0c064e96;
P_0c064e96: /* original 263b, guest PC 0x0c064e96 */
if(!s->budget--) { s->failed_pc=0x0c064e96u; return 0; }
r[6]|=r[3];
goto P_0c064e98;
P_0c064e98: /* original f3f2, guest PC 0x0c064e98 */
if(!s->budget--) { s->failed_pc=0x0c064e98u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064e9a;
P_0c064e9a: /* original 6593, guest PC 0x0c064e9a */
if(!s->budget--) { s->failed_pc=0x0c064e9au; return 0; }
r[5]=r[9];
goto P_0c064e9c;
P_0c064e9c: /* original f33d, guest PC 0x0c064e9c */
if(!s->budget--) { s->failed_pc=0x0c064e9cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064e9e;
P_0c064e9e: /* original 035a, guest PC 0x0c064e9e */
if(!s->budget--) { s->failed_pc=0x0c064e9eu; return 0; }
r[3]=r[53];
goto P_0c064ea0;
P_0c064ea0: /* original 263b, guest PC 0x0c064ea0 */
if(!s->budget--) { s->failed_pc=0x0c064ea0u; return 0; }
r[6]|=r[3];
goto P_0c064ea2;
P_0c064ea2: /* original bb45, guest PC 0x0c064ea2 */
if(!s->budget--) { s->failed_pc=0x0c064ea2u; return 0; }
target=0x0c064530u; r[16]=0x0c064ea6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064ea6u) { target=s->pc; goto dispatch; }
goto P_0c064ea6;
P_0c064ea4: /* original 64e3, guest PC 0x0c064ea4 */
if(!s->budget--) { s->failed_pc=0x0c064ea4u; return 0; }
r[4]=r[14];
goto P_0c064ea6;
P_0c064ea6: /* original 6c03, guest PC 0x0c064ea6 */
if(!s->budget--) { s->failed_pc=0x0c064ea6u; return 0; }
r[12]=r[0];
goto P_0c064ea8;
P_0c064ea8: /* original 61b2, guest PC 0x0c064ea8 */
if(!s->budget--) { s->failed_pc=0x0c064ea8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064eaa;
P_0c064eaa: /* original 63c3, guest PC 0x0c064eaa */
if(!s->budget--) { s->failed_pc=0x0c064eaau; return 0; }
r[3]=r[12];
goto P_0c064eac;
P_0c064eac: /* original d06e, guest PC 0x0c064eac */
if(!s->budget--) { s->failed_pc=0x0c064eacu; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064eae;
P_0c064eae: /* original 7c01, guest PC 0x0c064eae */
if(!s->budget--) { s->failed_pc=0x0c064eaeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064eb0;
P_0c064eb0: /* original 5211, guest PC 0x0c064eb0 */
if(!s->budget--) { s->failed_pc=0x0c064eb0u; return 0; }
r[2]=read(ram,r[1]+4,4);
goto P_0c064eb2;
P_0c064eb2: /* original 4308, guest PC 0x0c064eb2 */
if(!s->budget--) { s->failed_pc=0x0c064eb2u; return 0; }
r[3]<<=2;
goto P_0c064eb4;
P_0c064eb4: /* original 0326, guest PC 0x0c064eb4 */
if(!s->budget--) { s->failed_pc=0x0c064eb4u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064eb6;
P_0c064eb6: /* original 63c3, guest PC 0x0c064eb6 */
if(!s->budget--) { s->failed_pc=0x0c064eb6u; return 0; }
r[3]=r[12];
goto P_0c064eb8;
P_0c064eb8: /* original 61b2, guest PC 0x0c064eb8 */
if(!s->budget--) { s->failed_pc=0x0c064eb8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064eba;
P_0c064eba: /* original 7c01, guest PC 0x0c064eba */
if(!s->budget--) { s->failed_pc=0x0c064ebau; return 0; }
r[12]+=0x00000001u;
goto P_0c064ebc;
P_0c064ebc: /* original 5212, guest PC 0x0c064ebc */
if(!s->budget--) { s->failed_pc=0x0c064ebcu; return 0; }
r[2]=read(ram,r[1]+8,4);
goto P_0c064ebe;
P_0c064ebe: /* original 4308, guest PC 0x0c064ebe */
if(!s->budget--) { s->failed_pc=0x0c064ebeu; return 0; }
r[3]<<=2;
goto P_0c064ec0;
P_0c064ec0: /* original 0326, guest PC 0x0c064ec0 */
if(!s->budget--) { s->failed_pc=0x0c064ec0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064ec2;
P_0c064ec2: /* original 63c3, guest PC 0x0c064ec2 */
if(!s->budget--) { s->failed_pc=0x0c064ec2u; return 0; }
r[3]=r[12];
goto P_0c064ec4;
P_0c064ec4: /* original 61b2, guest PC 0x0c064ec4 */
if(!s->budget--) { s->failed_pc=0x0c064ec4u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064ec6;
P_0c064ec6: /* original 7c01, guest PC 0x0c064ec6 */
if(!s->budget--) { s->failed_pc=0x0c064ec6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064ec8;
P_0c064ec8: /* original 5213, guest PC 0x0c064ec8 */
if(!s->budget--) { s->failed_pc=0x0c064ec8u; return 0; }
r[2]=read(ram,r[1]+12,4);
goto P_0c064eca;
P_0c064eca: /* original 4308, guest PC 0x0c064eca */
if(!s->budget--) { s->failed_pc=0x0c064ecau; return 0; }
r[3]<<=2;
goto P_0c064ecc;
P_0c064ecc: /* original 0326, guest PC 0x0c064ecc */
if(!s->budget--) { s->failed_pc=0x0c064eccu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064ece;
P_0c064ece: /* original 65c3, guest PC 0x0c064ece */
if(!s->budget--) { s->failed_pc=0x0c064eceu; return 0; }
r[5]=r[12];
goto P_0c064ed0;
P_0c064ed0: /* original 67b2, guest PC 0x0c064ed0 */
if(!s->budget--) { s->failed_pc=0x0c064ed0u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c064ed2;
P_0c064ed2: /* original 2f72, guest PC 0x0c064ed2 */
if(!s->budget--) { s->failed_pc=0x0c064ed2u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064ed4;
P_0c064ed4: /* original 5775, guest PC 0x0c064ed4 */
if(!s->budget--) { s->failed_pc=0x0c064ed4u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064ed6;
P_0c064ed6: /* original 66f2, guest PC 0x0c064ed6 */
if(!s->budget--) { s->failed_pc=0x0c064ed6u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064ed8;
P_0c064ed8: /* original 5664, guest PC 0x0c064ed8 */
if(!s->budget--) { s->failed_pc=0x0c064ed8u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064eda;
P_0c064eda: /* original bb4d, guest PC 0x0c064eda */
if(!s->budget--) { s->failed_pc=0x0c064edau; return 0; }
target=0x0c064578u; r[16]=0x0c064edeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064edeu) { target=s->pc; goto dispatch; }
goto P_0c064ede;
P_0c064edc: /* original 64e3, guest PC 0x0c064edc */
if(!s->budget--) { s->failed_pc=0x0c064edcu; return 0; }
r[4]=r[14];
goto P_0c064ede;
P_0c064ede: /* original 6903, guest PC 0x0c064ede */
if(!s->budget--) { s->failed_pc=0x0c064edeu; return 0; }
r[9]=r[0];
goto P_0c064ee0;
P_0c064ee0: /* original 64b2, guest PC 0x0c064ee0 */
if(!s->budget--) { s->failed_pc=0x0c064ee0u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c064ee2;
P_0c064ee2: /* original e120, guest PC 0x0c064ee2 */
if(!s->budget--) { s->failed_pc=0x0c064ee2u; return 0; }
r[1]=0x00000020u;
goto P_0c064ee4;
P_0c064ee4: /* original d060, guest PC 0x0c064ee4 */
if(!s->budget--) { s->failed_pc=0x0c064ee4u; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064ee6;
P_0c064ee6: /* original 6293, guest PC 0x0c064ee6 */
if(!s->budget--) { s->failed_pc=0x0c064ee6u; return 0; }
r[2]=r[9];
goto P_0c064ee8;
P_0c064ee8: /* original 7901, guest PC 0x0c064ee8 */
if(!s->budget--) { s->failed_pc=0x0c064ee8u; return 0; }
r[9]+=0x00000001u;
goto P_0c064eea;
P_0c064eea: /* original 4208, guest PC 0x0c064eea */
if(!s->budget--) { s->failed_pc=0x0c064eeau; return 0; }
r[2]<<=2;
goto P_0c064eec;
P_0c064eec: /* original 314c, guest PC 0x0c064eec */
if(!s->budget--) { s->failed_pc=0x0c064eecu; return 0; }
r[1]+=r[4];
goto P_0c064eee;
P_0c064eee: /* original f318, guest PC 0x0c064eee */
if(!s->budget--) { s->failed_pc=0x0c064eeeu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064ef0;
P_0c064ef0: /* original f3f2, guest PC 0x0c064ef0 */
if(!s->budget--) { s->failed_pc=0x0c064ef0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064ef2;
P_0c064ef2: /* original e124, guest PC 0x0c064ef2 */
if(!s->budget--) { s->failed_pc=0x0c064ef2u; return 0; }
r[1]=0x00000024u;
goto P_0c064ef4;
P_0c064ef4: /* original f33d, guest PC 0x0c064ef4 */
if(!s->budget--) { s->failed_pc=0x0c064ef4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064ef6;
P_0c064ef6: /* original 314c, guest PC 0x0c064ef6 */
if(!s->budget--) { s->failed_pc=0x0c064ef6u; return 0; }
r[1]+=r[4];
goto P_0c064ef8;
P_0c064ef8: /* original f318, guest PC 0x0c064ef8 */
if(!s->budget--) { s->failed_pc=0x0c064ef8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064efa;
P_0c064efa: /* original 035a, guest PC 0x0c064efa */
if(!s->budget--) { s->failed_pc=0x0c064efau; return 0; }
r[3]=r[53];
goto P_0c064efc;
P_0c064efc: /* original 4328, guest PC 0x0c064efc */
if(!s->budget--) { s->failed_pc=0x0c064efcu; return 0; }
r[3]<<=16;
goto P_0c064efe;
P_0c064efe: /* original 4318, guest PC 0x0c064efe */
if(!s->budget--) { s->failed_pc=0x0c064efeu; return 0; }
r[3]<<=8;
goto P_0c064f00;
P_0c064f00: /* original f3f2, guest PC 0x0c064f00 */
if(!s->budget--) { s->failed_pc=0x0c064f00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f02;
P_0c064f02: /* original f33d, guest PC 0x0c064f02 */
if(!s->budget--) { s->failed_pc=0x0c064f02u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f04;
P_0c064f04: /* original 015a, guest PC 0x0c064f04 */
if(!s->budget--) { s->failed_pc=0x0c064f04u; return 0; }
r[1]=r[53];
goto P_0c064f06;
P_0c064f06: /* original 4128, guest PC 0x0c064f06 */
if(!s->budget--) { s->failed_pc=0x0c064f06u; return 0; }
r[1]<<=16;
goto P_0c064f08;
P_0c064f08: /* original 231b, guest PC 0x0c064f08 */
if(!s->budget--) { s->failed_pc=0x0c064f08u; return 0; }
r[3]|=r[1];
goto P_0c064f0a;
P_0c064f0a: /* original e128, guest PC 0x0c064f0a */
if(!s->budget--) { s->failed_pc=0x0c064f0au; return 0; }
r[1]=0x00000028u;
goto P_0c064f0c;
P_0c064f0c: /* original 314c, guest PC 0x0c064f0c */
if(!s->budget--) { s->failed_pc=0x0c064f0cu; return 0; }
r[1]+=r[4];
goto P_0c064f0e;
P_0c064f0e: /* original f318, guest PC 0x0c064f0e */
if(!s->budget--) { s->failed_pc=0x0c064f0eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064f10;
P_0c064f10: /* original f3f2, guest PC 0x0c064f10 */
if(!s->budget--) { s->failed_pc=0x0c064f10u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f12;
P_0c064f12: /* original f33d, guest PC 0x0c064f12 */
if(!s->budget--) { s->failed_pc=0x0c064f12u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f14;
P_0c064f14: /* original 015a, guest PC 0x0c064f14 */
if(!s->budget--) { s->failed_pc=0x0c064f14u; return 0; }
r[1]=r[53];
goto P_0c064f16;
P_0c064f16: /* original 4118, guest PC 0x0c064f16 */
if(!s->budget--) { s->failed_pc=0x0c064f16u; return 0; }
r[1]<<=8;
goto P_0c064f18;
P_0c064f18: /* original 231b, guest PC 0x0c064f18 */
if(!s->budget--) { s->failed_pc=0x0c064f18u; return 0; }
r[3]|=r[1];
goto P_0c064f1a;
P_0c064f1a: /* original e12c, guest PC 0x0c064f1a */
if(!s->budget--) { s->failed_pc=0x0c064f1au; return 0; }
r[1]=0x0000002cu;
goto P_0c064f1c;
P_0c064f1c: /* original 314c, guest PC 0x0c064f1c */
if(!s->budget--) { s->failed_pc=0x0c064f1cu; return 0; }
r[1]+=r[4];
goto P_0c064f1e;
P_0c064f1e: /* original f318, guest PC 0x0c064f1e */
if(!s->budget--) { s->failed_pc=0x0c064f1eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064f20;
P_0c064f20: /* original f3f2, guest PC 0x0c064f20 */
if(!s->budget--) { s->failed_pc=0x0c064f20u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f22;
P_0c064f22: /* original f33d, guest PC 0x0c064f22 */
if(!s->budget--) { s->failed_pc=0x0c064f22u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f24;
P_0c064f24: /* original 015a, guest PC 0x0c064f24 */
if(!s->budget--) { s->failed_pc=0x0c064f24u; return 0; }
r[1]=r[53];
goto P_0c064f26;
P_0c064f26: /* original 231b, guest PC 0x0c064f26 */
if(!s->budget--) { s->failed_pc=0x0c064f26u; return 0; }
r[3]|=r[1];
goto P_0c064f28;
P_0c064f28: /* original 0236, guest PC 0x0c064f28 */
if(!s->budget--) { s->failed_pc=0x0c064f28u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064f2a;
P_0c064f2a: /* original e030, guest PC 0x0c064f2a */
if(!s->budget--) { s->failed_pc=0x0c064f2au; return 0; }
r[0]=0x00000030u;
goto P_0c064f2c;
P_0c064f2c: /* original 6cb2, guest PC 0x0c064f2c */
if(!s->budget--) { s->failed_pc=0x0c064f2cu; return 0; }
tmp=read(ram,r[11],4);
r[12]=tmp;
goto P_0c064f2e;
P_0c064f2e: /* original f3c6, guest PC 0x0c064f2e */
if(!s->budget--) { s->failed_pc=0x0c064f2eu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064f30;
P_0c064f30: /* original f3f2, guest PC 0x0c064f30 */
if(!s->budget--) { s->failed_pc=0x0c064f30u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f32;
P_0c064f32: /* original e034, guest PC 0x0c064f32 */
if(!s->budget--) { s->failed_pc=0x0c064f32u; return 0; }
r[0]=0x00000034u;
goto P_0c064f34;
P_0c064f34: /* original f33d, guest PC 0x0c064f34 */
if(!s->budget--) { s->failed_pc=0x0c064f34u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f36;
P_0c064f36: /* original 065a, guest PC 0x0c064f36 */
if(!s->budget--) { s->failed_pc=0x0c064f36u; return 0; }
r[6]=r[53];
goto P_0c064f38;
P_0c064f38: /* original f3c6, guest PC 0x0c064f38 */
if(!s->budget--) { s->failed_pc=0x0c064f38u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064f3a;
P_0c064f3a: /* original 4628, guest PC 0x0c064f3a */
if(!s->budget--) { s->failed_pc=0x0c064f3au; return 0; }
r[6]<<=16;
goto P_0c064f3c;
P_0c064f3c: /* original 4618, guest PC 0x0c064f3c */
if(!s->budget--) { s->failed_pc=0x0c064f3cu; return 0; }
r[6]<<=8;
goto P_0c064f3e;
P_0c064f3e: /* original f3f2, guest PC 0x0c064f3e */
if(!s->budget--) { s->failed_pc=0x0c064f3eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f40;
P_0c064f40: /* original f33d, guest PC 0x0c064f40 */
if(!s->budget--) { s->failed_pc=0x0c064f40u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f42;
P_0c064f42: /* original e038, guest PC 0x0c064f42 */
if(!s->budget--) { s->failed_pc=0x0c064f42u; return 0; }
r[0]=0x00000038u;
goto P_0c064f44;
P_0c064f44: /* original f3c6, guest PC 0x0c064f44 */
if(!s->budget--) { s->failed_pc=0x0c064f44u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064f46;
P_0c064f46: /* original 035a, guest PC 0x0c064f46 */
if(!s->budget--) { s->failed_pc=0x0c064f46u; return 0; }
r[3]=r[53];
goto P_0c064f48;
P_0c064f48: /* original 4328, guest PC 0x0c064f48 */
if(!s->budget--) { s->failed_pc=0x0c064f48u; return 0; }
r[3]<<=16;
goto P_0c064f4a;
P_0c064f4a: /* original 263b, guest PC 0x0c064f4a */
if(!s->budget--) { s->failed_pc=0x0c064f4au; return 0; }
r[6]|=r[3];
goto P_0c064f4c;
P_0c064f4c: /* original f3f2, guest PC 0x0c064f4c */
if(!s->budget--) { s->failed_pc=0x0c064f4cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f4e;
P_0c064f4e: /* original e03c, guest PC 0x0c064f4e */
if(!s->budget--) { s->failed_pc=0x0c064f4eu; return 0; }
r[0]=0x0000003cu;
goto P_0c064f50;
P_0c064f50: /* original f33d, guest PC 0x0c064f50 */
if(!s->budget--) { s->failed_pc=0x0c064f50u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f52;
P_0c064f52: /* original 035a, guest PC 0x0c064f52 */
if(!s->budget--) { s->failed_pc=0x0c064f52u; return 0; }
r[3]=r[53];
goto P_0c064f54;
P_0c064f54: /* original f3c6, guest PC 0x0c064f54 */
if(!s->budget--) { s->failed_pc=0x0c064f54u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c064f56;
P_0c064f56: /* original 4318, guest PC 0x0c064f56 */
if(!s->budget--) { s->failed_pc=0x0c064f56u; return 0; }
r[3]<<=8;
goto P_0c064f58;
P_0c064f58: /* original 263b, guest PC 0x0c064f58 */
if(!s->budget--) { s->failed_pc=0x0c064f58u; return 0; }
r[6]|=r[3];
goto P_0c064f5a;
P_0c064f5a: /* original f3f2, guest PC 0x0c064f5a */
if(!s->budget--) { s->failed_pc=0x0c064f5au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064f5c;
P_0c064f5c: /* original f33d, guest PC 0x0c064f5c */
if(!s->budget--) { s->failed_pc=0x0c064f5cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064f5e;
P_0c064f5e: /* original 035a, guest PC 0x0c064f5e */
if(!s->budget--) { s->failed_pc=0x0c064f5eu; return 0; }
r[3]=r[53];
goto P_0c064f60;
P_0c064f60: /* original 263b, guest PC 0x0c064f60 */
if(!s->budget--) { s->failed_pc=0x0c064f60u; return 0; }
r[6]|=r[3];
goto P_0c064f62;
P_0c064f62: /* original 6593, guest PC 0x0c064f62 */
if(!s->budget--) { s->failed_pc=0x0c064f62u; return 0; }
r[5]=r[9];
goto P_0c064f64;
P_0c064f64: /* original bae4, guest PC 0x0c064f64 */
if(!s->budget--) { s->failed_pc=0x0c064f64u; return 0; }
target=0x0c064530u; r[16]=0x0c064f68u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064f68u) { target=s->pc; goto dispatch; }
goto P_0c064f68;
P_0c064f66: /* original 64e3, guest PC 0x0c064f66 */
if(!s->budget--) { s->failed_pc=0x0c064f66u; return 0; }
r[4]=r[14];
goto P_0c064f68;
P_0c064f68: /* original 61a2, guest PC 0x0c064f68 */
if(!s->budget--) { s->failed_pc=0x0c064f68u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064f6a;
P_0c064f6a: /* original 6c03, guest PC 0x0c064f6a */
if(!s->budget--) { s->failed_pc=0x0c064f6au; return 0; }
r[12]=r[0];
goto P_0c064f6c;
P_0c064f6c: /* original 5211, guest PC 0x0c064f6c */
if(!s->budget--) { s->failed_pc=0x0c064f6cu; return 0; }
r[2]=read(ram,r[1]+4,4);
goto P_0c064f6e;
P_0c064f6e: /* original 63c3, guest PC 0x0c064f6e */
if(!s->budget--) { s->failed_pc=0x0c064f6eu; return 0; }
r[3]=r[12];
goto P_0c064f70;
P_0c064f70: /* original d03d, guest PC 0x0c064f70 */
if(!s->budget--) { s->failed_pc=0x0c064f70u; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064f72;
P_0c064f72: /* original 7c01, guest PC 0x0c064f72 */
if(!s->budget--) { s->failed_pc=0x0c064f72u; return 0; }
r[12]+=0x00000001u;
goto P_0c064f74;
P_0c064f74: /* original 4308, guest PC 0x0c064f74 */
if(!s->budget--) { s->failed_pc=0x0c064f74u; return 0; }
r[3]<<=2;
goto P_0c064f76;
P_0c064f76: /* original 0326, guest PC 0x0c064f76 */
if(!s->budget--) { s->failed_pc=0x0c064f76u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064f78;
P_0c064f78: /* original 61a2, guest PC 0x0c064f78 */
if(!s->budget--) { s->failed_pc=0x0c064f78u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064f7a;
P_0c064f7a: /* original 63c3, guest PC 0x0c064f7a */
if(!s->budget--) { s->failed_pc=0x0c064f7au; return 0; }
r[3]=r[12];
goto P_0c064f7c;
P_0c064f7c: /* original 5212, guest PC 0x0c064f7c */
if(!s->budget--) { s->failed_pc=0x0c064f7cu; return 0; }
r[2]=read(ram,r[1]+8,4);
goto P_0c064f7e;
P_0c064f7e: /* original 7c01, guest PC 0x0c064f7e */
if(!s->budget--) { s->failed_pc=0x0c064f7eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064f80;
P_0c064f80: /* original 4308, guest PC 0x0c064f80 */
if(!s->budget--) { s->failed_pc=0x0c064f80u; return 0; }
r[3]<<=2;
goto P_0c064f82;
P_0c064f82: /* original 0326, guest PC 0x0c064f82 */
if(!s->budget--) { s->failed_pc=0x0c064f82u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064f84;
P_0c064f84: /* original 61a2, guest PC 0x0c064f84 */
if(!s->budget--) { s->failed_pc=0x0c064f84u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064f86;
P_0c064f86: /* original 63c3, guest PC 0x0c064f86 */
if(!s->budget--) { s->failed_pc=0x0c064f86u; return 0; }
r[3]=r[12];
goto P_0c064f88;
P_0c064f88: /* original 5213, guest PC 0x0c064f88 */
if(!s->budget--) { s->failed_pc=0x0c064f88u; return 0; }
r[2]=read(ram,r[1]+12,4);
goto P_0c064f8a;
P_0c064f8a: /* original 7c01, guest PC 0x0c064f8a */
if(!s->budget--) { s->failed_pc=0x0c064f8au; return 0; }
r[12]+=0x00000001u;
goto P_0c064f8c;
P_0c064f8c: /* original 4308, guest PC 0x0c064f8c */
if(!s->budget--) { s->failed_pc=0x0c064f8cu; return 0; }
r[3]<<=2;
goto P_0c064f8e;
P_0c064f8e: /* original 0326, guest PC 0x0c064f8e */
if(!s->budget--) { s->failed_pc=0x0c064f8eu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064f90;
P_0c064f90: /* original 67a2, guest PC 0x0c064f90 */
if(!s->budget--) { s->failed_pc=0x0c064f90u; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c064f92;
P_0c064f92: /* original 65c3, guest PC 0x0c064f92 */
if(!s->budget--) { s->failed_pc=0x0c064f92u; return 0; }
r[5]=r[12];
goto P_0c064f94;
P_0c064f94: /* original 2f72, guest PC 0x0c064f94 */
if(!s->budget--) { s->failed_pc=0x0c064f94u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064f96;
P_0c064f96: /* original 5775, guest PC 0x0c064f96 */
if(!s->budget--) { s->failed_pc=0x0c064f96u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064f98;
P_0c064f98: /* original 66f2, guest PC 0x0c064f98 */
if(!s->budget--) { s->failed_pc=0x0c064f98u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064f9a;
P_0c064f9a: /* original 5664, guest PC 0x0c064f9a */
if(!s->budget--) { s->failed_pc=0x0c064f9au; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064f9c;
P_0c064f9c: /* original baec, guest PC 0x0c064f9c */
if(!s->budget--) { s->failed_pc=0x0c064f9cu; return 0; }
target=0x0c064578u; r[16]=0x0c064fa0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064fa0u) { target=s->pc; goto dispatch; }
goto P_0c064fa0;
P_0c064f9e: /* original 64e3, guest PC 0x0c064f9e */
if(!s->budget--) { s->failed_pc=0x0c064f9eu; return 0; }
r[4]=r[14];
goto P_0c064fa0;
P_0c064fa0: /* original 64a2, guest PC 0x0c064fa0 */
if(!s->budget--) { s->failed_pc=0x0c064fa0u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c064fa2;
P_0c064fa2: /* original e120, guest PC 0x0c064fa2 */
if(!s->budget--) { s->failed_pc=0x0c064fa2u; return 0; }
r[1]=0x00000020u;
goto P_0c064fa4;
P_0c064fa4: /* original 6c03, guest PC 0x0c064fa4 */
if(!s->budget--) { s->failed_pc=0x0c064fa4u; return 0; }
r[12]=r[0];
goto P_0c064fa6;
P_0c064fa6: /* original 62c3, guest PC 0x0c064fa6 */
if(!s->budget--) { s->failed_pc=0x0c064fa6u; return 0; }
r[2]=r[12];
goto P_0c064fa8;
P_0c064fa8: /* original d02f, guest PC 0x0c064fa8 */
if(!s->budget--) { s->failed_pc=0x0c064fa8u; return 0; }
r[0]=read(ram,0x0c065068u,4);
goto P_0c064faa;
P_0c064faa: /* original 314c, guest PC 0x0c064faa */
if(!s->budget--) { s->failed_pc=0x0c064faau; return 0; }
r[1]+=r[4];
goto P_0c064fac;
P_0c064fac: /* original f318, guest PC 0x0c064fac */
if(!s->budget--) { s->failed_pc=0x0c064facu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064fae;
P_0c064fae: /* original 7c01, guest PC 0x0c064fae */
if(!s->budget--) { s->failed_pc=0x0c064faeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064fb0;
P_0c064fb0: /* original 4208, guest PC 0x0c064fb0 */
if(!s->budget--) { s->failed_pc=0x0c064fb0u; return 0; }
r[2]<<=2;
goto P_0c064fb2;
P_0c064fb2: /* original f3f2, guest PC 0x0c064fb2 */
if(!s->budget--) { s->failed_pc=0x0c064fb2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064fb4;
P_0c064fb4: /* original f33d, guest PC 0x0c064fb4 */
if(!s->budget--) { s->failed_pc=0x0c064fb4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064fb6;
P_0c064fb6: /* original e124, guest PC 0x0c064fb6 */
if(!s->budget--) { s->failed_pc=0x0c064fb6u; return 0; }
r[1]=0x00000024u;
goto P_0c064fb8;
P_0c064fb8: /* original 035a, guest PC 0x0c064fb8 */
if(!s->budget--) { s->failed_pc=0x0c064fb8u; return 0; }
r[3]=r[53];
goto P_0c064fba;
P_0c064fba: /* original 4328, guest PC 0x0c064fba */
if(!s->budget--) { s->failed_pc=0x0c064fbau; return 0; }
r[3]<<=16;
goto P_0c064fbc;
P_0c064fbc: /* original 4318, guest PC 0x0c064fbc */
if(!s->budget--) { s->failed_pc=0x0c064fbcu; return 0; }
r[3]<<=8;
goto P_0c064fbe;
P_0c064fbe: /* original 314c, guest PC 0x0c064fbe */
if(!s->budget--) { s->failed_pc=0x0c064fbeu; return 0; }
r[1]+=r[4];
goto P_0c064fc0;
P_0c064fc0: /* original f318, guest PC 0x0c064fc0 */
if(!s->budget--) { s->failed_pc=0x0c064fc0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064fc2;
P_0c064fc2: /* original f3f2, guest PC 0x0c064fc2 */
if(!s->budget--) { s->failed_pc=0x0c064fc2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064fc4;
P_0c064fc4: /* original f33d, guest PC 0x0c064fc4 */
if(!s->budget--) { s->failed_pc=0x0c064fc4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064fc6;
P_0c064fc6: /* original 015a, guest PC 0x0c064fc6 */
if(!s->budget--) { s->failed_pc=0x0c064fc6u; return 0; }
r[1]=r[53];
goto P_0c064fc8;
P_0c064fc8: /* original 4128, guest PC 0x0c064fc8 */
if(!s->budget--) { s->failed_pc=0x0c064fc8u; return 0; }
r[1]<<=16;
goto P_0c064fca;
P_0c064fca: /* original 231b, guest PC 0x0c064fca */
if(!s->budget--) { s->failed_pc=0x0c064fcau; return 0; }
r[3]|=r[1];
goto P_0c064fcc;
P_0c064fcc: /* original e128, guest PC 0x0c064fcc */
if(!s->budget--) { s->failed_pc=0x0c064fccu; return 0; }
r[1]=0x00000028u;
goto P_0c064fce;
P_0c064fce: /* original 314c, guest PC 0x0c064fce */
if(!s->budget--) { s->failed_pc=0x0c064fceu; return 0; }
r[1]+=r[4];
goto P_0c064fd0;
P_0c064fd0: /* original f318, guest PC 0x0c064fd0 */
if(!s->budget--) { s->failed_pc=0x0c064fd0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064fd2;
P_0c064fd2: /* original f3f2, guest PC 0x0c064fd2 */
if(!s->budget--) { s->failed_pc=0x0c064fd2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064fd4;
P_0c064fd4: /* original f33d, guest PC 0x0c064fd4 */
if(!s->budget--) { s->failed_pc=0x0c064fd4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064fd6;
P_0c064fd6: /* original 015a, guest PC 0x0c064fd6 */
if(!s->budget--) { s->failed_pc=0x0c064fd6u; return 0; }
r[1]=r[53];
goto P_0c064fd8;
P_0c064fd8: /* original 4118, guest PC 0x0c064fd8 */
if(!s->budget--) { s->failed_pc=0x0c064fd8u; return 0; }
r[1]<<=8;
goto P_0c064fda;
P_0c064fda: /* original 231b, guest PC 0x0c064fda */
if(!s->budget--) { s->failed_pc=0x0c064fdau; return 0; }
r[3]|=r[1];
goto P_0c064fdc;
P_0c064fdc: /* original e12c, guest PC 0x0c064fdc */
if(!s->budget--) { s->failed_pc=0x0c064fdcu; return 0; }
r[1]=0x0000002cu;
goto P_0c064fde;
P_0c064fde: /* original 314c, guest PC 0x0c064fde */
if(!s->budget--) { s->failed_pc=0x0c064fdeu; return 0; }
r[1]+=r[4];
goto P_0c064fe0;
P_0c064fe0: /* original f318, guest PC 0x0c064fe0 */
if(!s->budget--) { s->failed_pc=0x0c064fe0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064fe2;
P_0c064fe2: /* original f3f2, guest PC 0x0c064fe2 */
if(!s->budget--) { s->failed_pc=0x0c064fe2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064fe4;
P_0c064fe4: /* original f33d, guest PC 0x0c064fe4 */
if(!s->budget--) { s->failed_pc=0x0c064fe4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064fe6;
P_0c064fe6: /* original 015a, guest PC 0x0c064fe6 */
if(!s->budget--) { s->failed_pc=0x0c064fe6u; return 0; }
r[1]=r[53];
goto P_0c064fe8;
P_0c064fe8: /* original 231b, guest PC 0x0c064fe8 */
if(!s->budget--) { s->failed_pc=0x0c064fe8u; return 0; }
r[3]|=r[1];
goto P_0c064fea;
P_0c064fea: /* original 0236, guest PC 0x0c064fea */
if(!s->budget--) { s->failed_pc=0x0c064feau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064fec;
P_0c064fec: /* original 6ba2, guest PC 0x0c064fec */
if(!s->budget--) { s->failed_pc=0x0c064fecu; return 0; }
tmp=read(ram,r[10],4);
r[11]=tmp;
goto P_0c064fee;
P_0c064fee: /* original e030, guest PC 0x0c064fee */
if(!s->budget--) { s->failed_pc=0x0c064feeu; return 0; }
r[0]=0x00000030u;
goto P_0c064ff0;
P_0c064ff0: /* original f3b6, guest PC 0x0c064ff0 */
if(!s->budget--) { s->failed_pc=0x0c064ff0u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c064ff2;
P_0c064ff2: /* original e034, guest PC 0x0c064ff2 */
if(!s->budget--) { s->failed_pc=0x0c064ff2u; return 0; }
r[0]=0x00000034u;
goto P_0c064ff4;
P_0c064ff4: /* original f3f2, guest PC 0x0c064ff4 */
if(!s->budget--) { s->failed_pc=0x0c064ff4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c064ff6;
P_0c064ff6: /* original f33d, guest PC 0x0c064ff6 */
if(!s->budget--) { s->failed_pc=0x0c064ff6u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064ff8;
P_0c064ff8: /* original f3b6, guest PC 0x0c064ff8 */
if(!s->budget--) { s->failed_pc=0x0c064ff8u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c064ffa;
P_0c064ffa: /* original 065a, guest PC 0x0c064ffa */
if(!s->budget--) { s->failed_pc=0x0c064ffau; return 0; }
r[6]=r[53];
goto P_0c064ffc;
P_0c064ffc: /* original 4628, guest PC 0x0c064ffc */
if(!s->budget--) { s->failed_pc=0x0c064ffcu; return 0; }
r[6]<<=16;
goto P_0c064ffe;
P_0c064ffe: /* original 4618, guest PC 0x0c064ffe */
if(!s->budget--) { s->failed_pc=0x0c064ffeu; return 0; }
r[6]<<=8;
goto P_0c065000;
P_0c065000: /* original f3f2, guest PC 0x0c065000 */
if(!s->budget--) { s->failed_pc=0x0c065000u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065002;
P_0c065002: /* original e038, guest PC 0x0c065002 */
if(!s->budget--) { s->failed_pc=0x0c065002u; return 0; }
r[0]=0x00000038u;
goto P_0c065004;
P_0c065004: /* original f33d, guest PC 0x0c065004 */
if(!s->budget--) { s->failed_pc=0x0c065004u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065006;
P_0c065006: /* original 035a, guest PC 0x0c065006 */
if(!s->budget--) { s->failed_pc=0x0c065006u; return 0; }
r[3]=r[53];
goto P_0c065008;
P_0c065008: /* original f3b6, guest PC 0x0c065008 */
if(!s->budget--) { s->failed_pc=0x0c065008u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c06500a;
P_0c06500a: /* original 4328, guest PC 0x0c06500a */
if(!s->budget--) { s->failed_pc=0x0c06500au; return 0; }
r[3]<<=16;
goto P_0c06500c;
P_0c06500c: /* original 263b, guest PC 0x0c06500c */
if(!s->budget--) { s->failed_pc=0x0c06500cu; return 0; }
r[6]|=r[3];
goto P_0c06500e;
P_0c06500e: /* original f3f2, guest PC 0x0c06500e */
if(!s->budget--) { s->failed_pc=0x0c06500eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065010;
P_0c065010: /* original f33d, guest PC 0x0c065010 */
if(!s->budget--) { s->failed_pc=0x0c065010u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065012;
P_0c065012: /* original e03c, guest PC 0x0c065012 */
if(!s->budget--) { s->failed_pc=0x0c065012u; return 0; }
r[0]=0x0000003cu;
goto P_0c065014;
P_0c065014: /* original f3b6, guest PC 0x0c065014 */
if(!s->budget--) { s->failed_pc=0x0c065014u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c065016;
P_0c065016: /* original 035a, guest PC 0x0c065016 */
if(!s->budget--) { s->failed_pc=0x0c065016u; return 0; }
r[3]=r[53];
goto P_0c065018;
P_0c065018: /* original 4318, guest PC 0x0c065018 */
if(!s->budget--) { s->failed_pc=0x0c065018u; return 0; }
r[3]<<=8;
goto P_0c06501a;
P_0c06501a: /* original 263b, guest PC 0x0c06501a */
if(!s->budget--) { s->failed_pc=0x0c06501au; return 0; }
r[6]|=r[3];
goto P_0c06501c;
P_0c06501c: /* original f3f2, guest PC 0x0c06501c */
if(!s->budget--) { s->failed_pc=0x0c06501cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06501e;
P_0c06501e: /* original f33d, guest PC 0x0c06501e */
if(!s->budget--) { s->failed_pc=0x0c06501eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065020;
P_0c065020: /* original 035a, guest PC 0x0c065020 */
if(!s->budget--) { s->failed_pc=0x0c065020u; return 0; }
r[3]=r[53];
goto P_0c065022;
P_0c065022: /* original 263b, guest PC 0x0c065022 */
if(!s->budget--) { s->failed_pc=0x0c065022u; return 0; }
r[6]|=r[3];
goto P_0c065024;
P_0c065024: /* original 65c3, guest PC 0x0c065024 */
if(!s->budget--) { s->failed_pc=0x0c065024u; return 0; }
r[5]=r[12];
goto P_0c065026;
P_0c065026: /* original ba83, guest PC 0x0c065026 */
if(!s->budget--) { s->failed_pc=0x0c065026u; return 0; }
target=0x0c064530u; r[16]=0x0c06502au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06502au) { target=s->pc; goto dispatch; }
goto P_0c06502a;
P_0c065028: /* original 64e3, guest PC 0x0c065028 */
if(!s->budget--) { s->failed_pc=0x0c065028u; return 0; }
r[4]=r[14];
goto P_0c06502a;
P_0c06502a: /* original 6403, guest PC 0x0c06502a */
if(!s->budget--) { s->failed_pc=0x0c06502au; return 0; }
r[4]=r[0];
goto P_0c06502c;
P_0c06502c: /* original d310, guest PC 0x0c06502c */
if(!s->budget--) { s->failed_pc=0x0c06502cu; return 0; }
r[3]=read(ram,0x0c065070u,4);
goto P_0c06502e;
P_0c06502e: /* original 4408, guest PC 0x0c06502e */
if(!s->budget--) { s->failed_pc=0x0c06502eu; return 0; }
r[4]<<=2;
goto P_0c065030;
P_0c065030: /* original 2342, guest PC 0x0c065030 */
if(!s->budget--) { s->failed_pc=0x0c065030u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c065032;
P_0c065032: /* original ba6e, guest PC 0x0c065032 */
if(!s->budget--) { s->failed_pc=0x0c065032u; return 0; }
target=0x0c064512u; r[16]=0x0c065036u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065036u) { target=s->pc; goto dispatch; }
goto P_0c065036;
P_0c065034: /* original 64e3, guest PC 0x0c065034 */
if(!s->budget--) { s->failed_pc=0x0c065034u; return 0; }
r[4]=r[14];
goto P_0c065036;
P_0c065036: /* original 6403, guest PC 0x0c065036 */
if(!s->budget--) { s->failed_pc=0x0c065036u; return 0; }
r[4]=r[0];
goto P_0c065038;
P_0c065038: /* original e500, guest PC 0x0c065038 */
if(!s->budget--) { s->failed_pc=0x0c065038u; return 0; }
r[5]=0x00000000u;
goto P_0c06503a;
P_0c06503a: /* original ba55, guest PC 0x0c06503a */
if(!s->budget--) { s->failed_pc=0x0c06503au; return 0; }
target=0x0c0644e8u; r[16]=0x0c06503eu;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06503eu) { target=s->pc; goto dispatch; }
goto P_0c06503e;
P_0c06503c: /* original 6653, guest PC 0x0c06503c */
if(!s->budget--) { s->failed_pc=0x0c06503cu; return 0; }
r[6]=r[5];
goto P_0c06503e;
P_0c06503e: /* original 63d2, guest PC 0x0c06503e */
if(!s->budget--) { s->failed_pc=0x0c06503eu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c065040;
P_0c065040: /* original d10c, guest PC 0x0c065040 */
if(!s->budget--) { s->failed_pc=0x0c065040u; return 0; }
r[1]=read(ram,0x0c065074u,4);
goto P_0c065042;
P_0c065042: /* original 5233, guest PC 0x0c065042 */
if(!s->budget--) { s->failed_pc=0x0c065042u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c065044;
P_0c065044: /* original 2122, guest PC 0x0c065044 */
if(!s->budget--) { s->failed_pc=0x0c065044u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c065046;
P_0c065046: /* original e000, guest PC 0x0c065046 */
if(!s->budget--) { s->failed_pc=0x0c065046u; return 0; }
r[0]=0x00000000u;
goto P_0c065048;
P_0c065048: /* original 7f10, guest PC 0x0c065048 */
if(!s->budget--) { s->failed_pc=0x0c065048u; return 0; }
r[15]+=0x00000010u;
goto P_0c06504a;
P_0c06504a: /* original 4f26, guest PC 0x0c06504a */
if(!s->budget--) { s->failed_pc=0x0c06504au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06504c;
P_0c06504c: /* original fff9, guest PC 0x0c06504c */
if(!s->budget--) { s->failed_pc=0x0c06504cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06504e;
P_0c06504e: /* original 69f6, guest PC 0x0c06504e */
if(!s->budget--) { s->failed_pc=0x0c06504eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c065050;
P_0c065050: /* original 6af6, guest PC 0x0c065050 */
if(!s->budget--) { s->failed_pc=0x0c065050u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c065052;
P_0c065052: /* original 6bf6, guest PC 0x0c065052 */
if(!s->budget--) { s->failed_pc=0x0c065052u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c065054;
P_0c065054: /* original 6cf6, guest PC 0x0c065054 */
if(!s->budget--) { s->failed_pc=0x0c065054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c065056;
P_0c065056: /* original 6df6, guest PC 0x0c065056 */
if(!s->budget--) { s->failed_pc=0x0c065056u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c065058;
P_0c065058: /* original 000b, guest PC 0x0c065058 */
if(!s->budget--) { s->failed_pc=0x0c065058u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06505a: /* original 6ef6, guest PC 0x0c06505a */
if(!s->budget--) { s->failed_pc=0x0c06505au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06505cu,s,ram);
P_0c065088: /* original 4f22, guest PC 0x0c065088 */
if(!s->budget--) { s->failed_pc=0x0c065088u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06508a;
P_0c06508a: /* original 7ff4, guest PC 0x0c06508a */
if(!s->budget--) { s->failed_pc=0x0c06508au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06508c;
P_0c06508c: /* original 6342, guest PC 0x0c06508c */
if(!s->budget--) { s->failed_pc=0x0c06508cu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c06508e;
P_0c06508e: /* original 65f3, guest PC 0x0c06508e */
if(!s->budget--) { s->failed_pc=0x0c06508eu; return 0; }
r[5]=r[15];
goto P_0c065090;
P_0c065090: /* original 6e53, guest PC 0x0c065090 */
if(!s->budget--) { s->failed_pc=0x0c065090u; return 0; }
r[14]=r[5];
goto P_0c065092;
P_0c065092: /* original 6be3, guest PC 0x0c065092 */
if(!s->budget--) { s->failed_pc=0x0c065092u; return 0; }
r[11]=r[14];
goto P_0c065094;
P_0c065094: /* original 2e32, guest PC 0x0c065094 */
if(!s->budget--) { s->failed_pc=0x0c065094u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c065096;
P_0c065096: /* original 6ae3, guest PC 0x0c065096 */
if(!s->budget--) { s->failed_pc=0x0c065096u; return 0; }
r[10]=r[14];
goto P_0c065098;
P_0c065098: /* original 5241, guest PC 0x0c065098 */
if(!s->budget--) { s->failed_pc=0x0c065098u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06509a;
P_0c06509a: /* original 7b04, guest PC 0x0c06509a */
if(!s->budget--) { s->failed_pc=0x0c06509au; return 0; }
r[11]+=0x00000004u;
goto P_0c06509c;
P_0c06509c: /* original 2b22, guest PC 0x0c06509c */
if(!s->budget--) { s->failed_pc=0x0c06509cu; return 0; }
write(ram,r[11],r[2],4);
goto P_0c06509e;
P_0c06509e: /* original 7a08, guest PC 0x0c06509e */
if(!s->budget--) { s->failed_pc=0x0c06509eu; return 0; }
r[10]+=0x00000008u;
goto P_0c0650a0;
P_0c0650a0: /* original 5342, guest PC 0x0c0650a0 */
if(!s->budget--) { s->failed_pc=0x0c0650a0u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0650a2;
P_0c0650a2: /* original 2a32, guest PC 0x0c0650a2 */
if(!s->budget--) { s->failed_pc=0x0c0650a2u; return 0; }
write(ram,r[10],r[3],4);
goto P_0c0650a4;
P_0c0650a4: /* original d2a2, guest PC 0x0c0650a4 */
if(!s->budget--) { s->failed_pc=0x0c0650a4u; return 0; }
r[2]=read(ram,0x0c065330u,4);
goto P_0c0650a6;
P_0c0650a6: /* original 6d22, guest PC 0x0c0650a6 */
if(!s->budget--) { s->failed_pc=0x0c0650a6u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c0650a8;
P_0c0650a8: /* original d3a2, guest PC 0x0c0650a8 */
if(!s->budget--) { s->failed_pc=0x0c0650a8u; return 0; }
r[3]=read(ram,0x0c065334u,4);
goto P_0c0650aa;
P_0c0650aa: /* original 6532, guest PC 0x0c0650aa */
if(!s->budget--) { s->failed_pc=0x0c0650aau; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0650ac;
P_0c0650ac: /* original d1a2, guest PC 0x0c0650ac */
if(!s->budget--) { s->failed_pc=0x0c0650acu; return 0; }
r[1]=read(ram,0x0c065338u,4);
goto P_0c0650ae;
P_0c0650ae: /* original 6412, guest PC 0x0c0650ae */
if(!s->budget--) { s->failed_pc=0x0c0650aeu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c0650b0;
P_0c0650b0: /* original d0a2, guest PC 0x0c0650b0 */
if(!s->budget--) { s->failed_pc=0x0c0650b0u; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c0650b2;
P_0c0650b2: /* original 62c3, guest PC 0x0c0650b2 */
if(!s->budget--) { s->failed_pc=0x0c0650b2u; return 0; }
r[2]=r[12];
goto P_0c0650b4;
P_0c0650b4: /* original 7c01, guest PC 0x0c0650b4 */
if(!s->budget--) { s->failed_pc=0x0c0650b4u; return 0; }
r[12]+=0x00000001u;
goto P_0c0650b6;
P_0c0650b6: /* original 4208, guest PC 0x0c0650b6 */
if(!s->budget--) { s->failed_pc=0x0c0650b6u; return 0; }
r[2]<<=2;
goto P_0c0650b8;
P_0c0650b8: /* original 02d6, guest PC 0x0c0650b8 */
if(!s->budget--) { s->failed_pc=0x0c0650b8u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c0650ba;
P_0c0650ba: /* original 63c3, guest PC 0x0c0650ba */
if(!s->budget--) { s->failed_pc=0x0c0650bau; return 0; }
r[3]=r[12];
goto P_0c0650bc;
P_0c0650bc: /* original 7c01, guest PC 0x0c0650bc */
if(!s->budget--) { s->failed_pc=0x0c0650bcu; return 0; }
r[12]+=0x00000001u;
goto P_0c0650be;
P_0c0650be: /* original 4308, guest PC 0x0c0650be */
if(!s->budget--) { s->failed_pc=0x0c0650beu; return 0; }
r[3]<<=2;
goto P_0c0650c0;
P_0c0650c0: /* original 0356, guest PC 0x0c0650c0 */
if(!s->budget--) { s->failed_pc=0x0c0650c0u; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c0650c2;
P_0c0650c2: /* original 62c3, guest PC 0x0c0650c2 */
if(!s->budget--) { s->failed_pc=0x0c0650c2u; return 0; }
r[2]=r[12];
goto P_0c0650c4;
P_0c0650c4: /* original 7c01, guest PC 0x0c0650c4 */
if(!s->budget--) { s->failed_pc=0x0c0650c4u; return 0; }
r[12]+=0x00000001u;
goto P_0c0650c6;
P_0c0650c6: /* original 4208, guest PC 0x0c0650c6 */
if(!s->budget--) { s->failed_pc=0x0c0650c6u; return 0; }
r[2]<<=2;
goto P_0c0650c8;
P_0c0650c8: /* original 0246, guest PC 0x0c0650c8 */
if(!s->budget--) { s->failed_pc=0x0c0650c8u; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c0650ca;
P_0c0650ca: /* original 63c3, guest PC 0x0c0650ca */
if(!s->budget--) { s->failed_pc=0x0c0650cau; return 0; }
r[3]=r[12];
goto P_0c0650cc;
P_0c0650cc: /* original 62e2, guest PC 0x0c0650cc */
if(!s->budget--) { s->failed_pc=0x0c0650ccu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0650ce;
P_0c0650ce: /* original 7c01, guest PC 0x0c0650ce */
if(!s->budget--) { s->failed_pc=0x0c0650ceu; return 0; }
r[12]+=0x00000001u;
goto P_0c0650d0;
P_0c0650d0: /* original 5221, guest PC 0x0c0650d0 */
if(!s->budget--) { s->failed_pc=0x0c0650d0u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c0650d2;
P_0c0650d2: /* original 4308, guest PC 0x0c0650d2 */
if(!s->budget--) { s->failed_pc=0x0c0650d2u; return 0; }
r[3]<<=2;
goto P_0c0650d4;
P_0c0650d4: /* original 0326, guest PC 0x0c0650d4 */
if(!s->budget--) { s->failed_pc=0x0c0650d4u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0650d6;
P_0c0650d6: /* original 63c3, guest PC 0x0c0650d6 */
if(!s->budget--) { s->failed_pc=0x0c0650d6u; return 0; }
r[3]=r[12];
goto P_0c0650d8;
P_0c0650d8: /* original 62e2, guest PC 0x0c0650d8 */
if(!s->budget--) { s->failed_pc=0x0c0650d8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0650da;
P_0c0650da: /* original 7c01, guest PC 0x0c0650da */
if(!s->budget--) { s->failed_pc=0x0c0650dau; return 0; }
r[12]+=0x00000001u;
goto P_0c0650dc;
P_0c0650dc: /* original 5222, guest PC 0x0c0650dc */
if(!s->budget--) { s->failed_pc=0x0c0650dcu; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c0650de;
P_0c0650de: /* original 4308, guest PC 0x0c0650de */
if(!s->budget--) { s->failed_pc=0x0c0650deu; return 0; }
r[3]<<=2;
goto P_0c0650e0;
P_0c0650e0: /* original 0326, guest PC 0x0c0650e0 */
if(!s->budget--) { s->failed_pc=0x0c0650e0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0650e2;
P_0c0650e2: /* original 63c3, guest PC 0x0c0650e2 */
if(!s->budget--) { s->failed_pc=0x0c0650e2u; return 0; }
r[3]=r[12];
goto P_0c0650e4;
P_0c0650e4: /* original 62e2, guest PC 0x0c0650e4 */
if(!s->budget--) { s->failed_pc=0x0c0650e4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0650e6;
P_0c0650e6: /* original 7c01, guest PC 0x0c0650e6 */
if(!s->budget--) { s->failed_pc=0x0c0650e6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0650e8;
P_0c0650e8: /* original 5223, guest PC 0x0c0650e8 */
if(!s->budget--) { s->failed_pc=0x0c0650e8u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c0650ea;
P_0c0650ea: /* original 4308, guest PC 0x0c0650ea */
if(!s->budget--) { s->failed_pc=0x0c0650eau; return 0; }
r[3]<<=2;
goto P_0c0650ec;
P_0c0650ec: /* original 0326, guest PC 0x0c0650ec */
if(!s->budget--) { s->failed_pc=0x0c0650ecu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0650ee;
P_0c0650ee: /* original 65c3, guest PC 0x0c0650ee */
if(!s->budget--) { s->failed_pc=0x0c0650eeu; return 0; }
r[5]=r[12];
goto P_0c0650f0;
P_0c0650f0: /* original 66e2, guest PC 0x0c0650f0 */
if(!s->budget--) { s->failed_pc=0x0c0650f0u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0650f2;
P_0c0650f2: /* original 5664, guest PC 0x0c0650f2 */
if(!s->budget--) { s->failed_pc=0x0c0650f2u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0650f4;
P_0c0650f4: /* original ba26, guest PC 0x0c0650f4 */
if(!s->budget--) { s->failed_pc=0x0c0650f4u; return 0; }
target=0x0c064544u; r[16]=0x0c0650f8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0650f8u) { target=s->pc; goto dispatch; }
goto P_0c0650f8;
P_0c0650f6: /* original 64d3, guest PC 0x0c0650f6 */
if(!s->budget--) { s->failed_pc=0x0c0650f6u; return 0; }
r[4]=r[13];
goto P_0c0650f8;
P_0c0650f8: /* original 64e2, guest PC 0x0c0650f8 */
if(!s->budget--) { s->failed_pc=0x0c0650f8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0650fa;
P_0c0650fa: /* original e120, guest PC 0x0c0650fa */
if(!s->budget--) { s->failed_pc=0x0c0650fau; return 0; }
r[1]=0x00000020u;
goto P_0c0650fc;
P_0c0650fc: /* original 6903, guest PC 0x0c0650fc */
if(!s->budget--) { s->failed_pc=0x0c0650fcu; return 0; }
r[9]=r[0];
goto P_0c0650fe;
P_0c0650fe: /* original 6393, guest PC 0x0c0650fe */
if(!s->budget--) { s->failed_pc=0x0c0650feu; return 0; }
r[3]=r[9];
goto P_0c065100;
P_0c065100: /* original c78f, guest PC 0x0c065100 */
if(!s->budget--) { s->failed_pc=0x0c065100u; return 0; }
r[0]=0x0c065340u;
goto P_0c065102;
P_0c065102: /* original 314c, guest PC 0x0c065102 */
if(!s->budget--) { s->failed_pc=0x0c065102u; return 0; }
r[1]+=r[4];
goto P_0c065104;
P_0c065104: /* original ff08, guest PC 0x0c065104 */
if(!s->budget--) { s->failed_pc=0x0c065104u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c065106;
P_0c065106: /* original 7901, guest PC 0x0c065106 */
if(!s->budget--) { s->failed_pc=0x0c065106u; return 0; }
r[9]+=0x00000001u;
goto P_0c065108;
P_0c065108: /* original f318, guest PC 0x0c065108 */
if(!s->budget--) { s->failed_pc=0x0c065108u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06510a;
P_0c06510a: /* original 4308, guest PC 0x0c06510a */
if(!s->budget--) { s->failed_pc=0x0c06510au; return 0; }
r[3]<<=2;
goto P_0c06510c;
P_0c06510c: /* original d08b, guest PC 0x0c06510c */
if(!s->budget--) { s->failed_pc=0x0c06510cu; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c06510e;
P_0c06510e: /* original f3f2, guest PC 0x0c06510e */
if(!s->budget--) { s->failed_pc=0x0c06510eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065110;
P_0c065110: /* original f33d, guest PC 0x0c065110 */
if(!s->budget--) { s->failed_pc=0x0c065110u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065112;
P_0c065112: /* original e124, guest PC 0x0c065112 */
if(!s->budget--) { s->failed_pc=0x0c065112u; return 0; }
r[1]=0x00000024u;
goto P_0c065114;
P_0c065114: /* original 025a, guest PC 0x0c065114 */
if(!s->budget--) { s->failed_pc=0x0c065114u; return 0; }
r[2]=r[53];
goto P_0c065116;
P_0c065116: /* original 4228, guest PC 0x0c065116 */
if(!s->budget--) { s->failed_pc=0x0c065116u; return 0; }
r[2]<<=16;
goto P_0c065118;
P_0c065118: /* original 4218, guest PC 0x0c065118 */
if(!s->budget--) { s->failed_pc=0x0c065118u; return 0; }
r[2]<<=8;
goto P_0c06511a;
P_0c06511a: /* original 314c, guest PC 0x0c06511a */
if(!s->budget--) { s->failed_pc=0x0c06511au; return 0; }
r[1]+=r[4];
goto P_0c06511c;
P_0c06511c: /* original f318, guest PC 0x0c06511c */
if(!s->budget--) { s->failed_pc=0x0c06511cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06511e;
P_0c06511e: /* original f3f2, guest PC 0x0c06511e */
if(!s->budget--) { s->failed_pc=0x0c06511eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065120;
P_0c065120: /* original f33d, guest PC 0x0c065120 */
if(!s->budget--) { s->failed_pc=0x0c065120u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065122;
P_0c065122: /* original 015a, guest PC 0x0c065122 */
if(!s->budget--) { s->failed_pc=0x0c065122u; return 0; }
r[1]=r[53];
goto P_0c065124;
P_0c065124: /* original 4128, guest PC 0x0c065124 */
if(!s->budget--) { s->failed_pc=0x0c065124u; return 0; }
r[1]<<=16;
goto P_0c065126;
P_0c065126: /* original 221b, guest PC 0x0c065126 */
if(!s->budget--) { s->failed_pc=0x0c065126u; return 0; }
r[2]|=r[1];
goto P_0c065128;
P_0c065128: /* original e128, guest PC 0x0c065128 */
if(!s->budget--) { s->failed_pc=0x0c065128u; return 0; }
r[1]=0x00000028u;
goto P_0c06512a;
P_0c06512a: /* original 314c, guest PC 0x0c06512a */
if(!s->budget--) { s->failed_pc=0x0c06512au; return 0; }
r[1]+=r[4];
goto P_0c06512c;
P_0c06512c: /* original f318, guest PC 0x0c06512c */
if(!s->budget--) { s->failed_pc=0x0c06512cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06512e;
P_0c06512e: /* original f3f2, guest PC 0x0c06512e */
if(!s->budget--) { s->failed_pc=0x0c06512eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065130;
P_0c065130: /* original f33d, guest PC 0x0c065130 */
if(!s->budget--) { s->failed_pc=0x0c065130u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065132;
P_0c065132: /* original 015a, guest PC 0x0c065132 */
if(!s->budget--) { s->failed_pc=0x0c065132u; return 0; }
r[1]=r[53];
goto P_0c065134;
P_0c065134: /* original 4118, guest PC 0x0c065134 */
if(!s->budget--) { s->failed_pc=0x0c065134u; return 0; }
r[1]<<=8;
goto P_0c065136;
P_0c065136: /* original 221b, guest PC 0x0c065136 */
if(!s->budget--) { s->failed_pc=0x0c065136u; return 0; }
r[2]|=r[1];
goto P_0c065138;
P_0c065138: /* original e12c, guest PC 0x0c065138 */
if(!s->budget--) { s->failed_pc=0x0c065138u; return 0; }
r[1]=0x0000002cu;
goto P_0c06513a;
P_0c06513a: /* original 314c, guest PC 0x0c06513a */
if(!s->budget--) { s->failed_pc=0x0c06513au; return 0; }
r[1]+=r[4];
goto P_0c06513c;
P_0c06513c: /* original f318, guest PC 0x0c06513c */
if(!s->budget--) { s->failed_pc=0x0c06513cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06513e;
P_0c06513e: /* original f3f2, guest PC 0x0c06513e */
if(!s->budget--) { s->failed_pc=0x0c06513eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065140;
P_0c065140: /* original f33d, guest PC 0x0c065140 */
if(!s->budget--) { s->failed_pc=0x0c065140u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065142;
P_0c065142: /* original 015a, guest PC 0x0c065142 */
if(!s->budget--) { s->failed_pc=0x0c065142u; return 0; }
r[1]=r[53];
goto P_0c065144;
P_0c065144: /* original 221b, guest PC 0x0c065144 */
if(!s->budget--) { s->failed_pc=0x0c065144u; return 0; }
r[2]|=r[1];
goto P_0c065146;
P_0c065146: /* original 0326, guest PC 0x0c065146 */
if(!s->budget--) { s->failed_pc=0x0c065146u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065148;
P_0c065148: /* original 6ce2, guest PC 0x0c065148 */
if(!s->budget--) { s->failed_pc=0x0c065148u; return 0; }
tmp=read(ram,r[14],4);
r[12]=tmp;
goto P_0c06514a;
P_0c06514a: /* original e030, guest PC 0x0c06514a */
if(!s->budget--) { s->failed_pc=0x0c06514au; return 0; }
r[0]=0x00000030u;
goto P_0c06514c;
P_0c06514c: /* original f3c6, guest PC 0x0c06514c */
if(!s->budget--) { s->failed_pc=0x0c06514cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06514e;
P_0c06514e: /* original e034, guest PC 0x0c06514e */
if(!s->budget--) { s->failed_pc=0x0c06514eu; return 0; }
r[0]=0x00000034u;
goto P_0c065150;
P_0c065150: /* original f3f2, guest PC 0x0c065150 */
if(!s->budget--) { s->failed_pc=0x0c065150u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065152;
P_0c065152: /* original f33d, guest PC 0x0c065152 */
if(!s->budget--) { s->failed_pc=0x0c065152u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065154;
P_0c065154: /* original f3c6, guest PC 0x0c065154 */
if(!s->budget--) { s->failed_pc=0x0c065154u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065156;
P_0c065156: /* original 065a, guest PC 0x0c065156 */
if(!s->budget--) { s->failed_pc=0x0c065156u; return 0; }
r[6]=r[53];
goto P_0c065158;
P_0c065158: /* original 4628, guest PC 0x0c065158 */
if(!s->budget--) { s->failed_pc=0x0c065158u; return 0; }
r[6]<<=16;
goto P_0c06515a;
P_0c06515a: /* original 4618, guest PC 0x0c06515a */
if(!s->budget--) { s->failed_pc=0x0c06515au; return 0; }
r[6]<<=8;
goto P_0c06515c;
P_0c06515c: /* original f3f2, guest PC 0x0c06515c */
if(!s->budget--) { s->failed_pc=0x0c06515cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06515e;
P_0c06515e: /* original e038, guest PC 0x0c06515e */
if(!s->budget--) { s->failed_pc=0x0c06515eu; return 0; }
r[0]=0x00000038u;
goto P_0c065160;
P_0c065160: /* original f33d, guest PC 0x0c065160 */
if(!s->budget--) { s->failed_pc=0x0c065160u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065162;
P_0c065162: /* original 035a, guest PC 0x0c065162 */
if(!s->budget--) { s->failed_pc=0x0c065162u; return 0; }
r[3]=r[53];
goto P_0c065164;
P_0c065164: /* original f3c6, guest PC 0x0c065164 */
if(!s->budget--) { s->failed_pc=0x0c065164u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065166;
P_0c065166: /* original 4328, guest PC 0x0c065166 */
if(!s->budget--) { s->failed_pc=0x0c065166u; return 0; }
r[3]<<=16;
goto P_0c065168;
P_0c065168: /* original 263b, guest PC 0x0c065168 */
if(!s->budget--) { s->failed_pc=0x0c065168u; return 0; }
r[6]|=r[3];
goto P_0c06516a;
P_0c06516a: /* original f3f2, guest PC 0x0c06516a */
if(!s->budget--) { s->failed_pc=0x0c06516au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06516c;
P_0c06516c: /* original f33d, guest PC 0x0c06516c */
if(!s->budget--) { s->failed_pc=0x0c06516cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06516e;
P_0c06516e: /* original e03c, guest PC 0x0c06516e */
if(!s->budget--) { s->failed_pc=0x0c06516eu; return 0; }
r[0]=0x0000003cu;
goto P_0c065170;
P_0c065170: /* original f3c6, guest PC 0x0c065170 */
if(!s->budget--) { s->failed_pc=0x0c065170u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065172;
P_0c065172: /* original 035a, guest PC 0x0c065172 */
if(!s->budget--) { s->failed_pc=0x0c065172u; return 0; }
r[3]=r[53];
goto P_0c065174;
P_0c065174: /* original 4318, guest PC 0x0c065174 */
if(!s->budget--) { s->failed_pc=0x0c065174u; return 0; }
r[3]<<=8;
goto P_0c065176;
P_0c065176: /* original 263b, guest PC 0x0c065176 */
if(!s->budget--) { s->failed_pc=0x0c065176u; return 0; }
r[6]|=r[3];
goto P_0c065178;
P_0c065178: /* original f3f2, guest PC 0x0c065178 */
if(!s->budget--) { s->failed_pc=0x0c065178u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06517a;
P_0c06517a: /* original 6593, guest PC 0x0c06517a */
if(!s->budget--) { s->failed_pc=0x0c06517au; return 0; }
r[5]=r[9];
goto P_0c06517c;
P_0c06517c: /* original f33d, guest PC 0x0c06517c */
if(!s->budget--) { s->failed_pc=0x0c06517cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06517e;
P_0c06517e: /* original 035a, guest PC 0x0c06517e */
if(!s->budget--) { s->failed_pc=0x0c06517eu; return 0; }
r[3]=r[53];
goto P_0c065180;
P_0c065180: /* original 263b, guest PC 0x0c065180 */
if(!s->budget--) { s->failed_pc=0x0c065180u; return 0; }
r[6]|=r[3];
goto P_0c065182;
P_0c065182: /* original b9d5, guest PC 0x0c065182 */
if(!s->budget--) { s->failed_pc=0x0c065182u; return 0; }
target=0x0c064530u; r[16]=0x0c065186u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065186u) { target=s->pc; goto dispatch; }
goto P_0c065186;
P_0c065184: /* original 64d3, guest PC 0x0c065184 */
if(!s->budget--) { s->failed_pc=0x0c065184u; return 0; }
r[4]=r[13];
goto P_0c065186;
P_0c065186: /* original 6c03, guest PC 0x0c065186 */
if(!s->budget--) { s->failed_pc=0x0c065186u; return 0; }
r[12]=r[0];
goto P_0c065188;
P_0c065188: /* original 61b2, guest PC 0x0c065188 */
if(!s->budget--) { s->failed_pc=0x0c065188u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c06518a;
P_0c06518a: /* original 63c3, guest PC 0x0c06518a */
if(!s->budget--) { s->failed_pc=0x0c06518au; return 0; }
r[3]=r[12];
goto P_0c06518c;
P_0c06518c: /* original d06b, guest PC 0x0c06518c */
if(!s->budget--) { s->failed_pc=0x0c06518cu; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c06518e;
P_0c06518e: /* original 7c01, guest PC 0x0c06518e */
if(!s->budget--) { s->failed_pc=0x0c06518eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065190;
P_0c065190: /* original 5211, guest PC 0x0c065190 */
if(!s->budget--) { s->failed_pc=0x0c065190u; return 0; }
r[2]=read(ram,r[1]+4,4);
goto P_0c065192;
P_0c065192: /* original 4308, guest PC 0x0c065192 */
if(!s->budget--) { s->failed_pc=0x0c065192u; return 0; }
r[3]<<=2;
goto P_0c065194;
P_0c065194: /* original 0326, guest PC 0x0c065194 */
if(!s->budget--) { s->failed_pc=0x0c065194u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065196;
P_0c065196: /* original 63c3, guest PC 0x0c065196 */
if(!s->budget--) { s->failed_pc=0x0c065196u; return 0; }
r[3]=r[12];
goto P_0c065198;
P_0c065198: /* original 61b2, guest PC 0x0c065198 */
if(!s->budget--) { s->failed_pc=0x0c065198u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c06519a;
P_0c06519a: /* original 7c01, guest PC 0x0c06519a */
if(!s->budget--) { s->failed_pc=0x0c06519au; return 0; }
r[12]+=0x00000001u;
goto P_0c06519c;
P_0c06519c: /* original 5212, guest PC 0x0c06519c */
if(!s->budget--) { s->failed_pc=0x0c06519cu; return 0; }
r[2]=read(ram,r[1]+8,4);
goto P_0c06519e;
P_0c06519e: /* original 4308, guest PC 0x0c06519e */
if(!s->budget--) { s->failed_pc=0x0c06519eu; return 0; }
r[3]<<=2;
goto P_0c0651a0;
P_0c0651a0: /* original 0326, guest PC 0x0c0651a0 */
if(!s->budget--) { s->failed_pc=0x0c0651a0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0651a2;
P_0c0651a2: /* original 63c3, guest PC 0x0c0651a2 */
if(!s->budget--) { s->failed_pc=0x0c0651a2u; return 0; }
r[3]=r[12];
goto P_0c0651a4;
P_0c0651a4: /* original 61b2, guest PC 0x0c0651a4 */
if(!s->budget--) { s->failed_pc=0x0c0651a4u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c0651a6;
P_0c0651a6: /* original 7c01, guest PC 0x0c0651a6 */
if(!s->budget--) { s->failed_pc=0x0c0651a6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0651a8;
P_0c0651a8: /* original 5213, guest PC 0x0c0651a8 */
if(!s->budget--) { s->failed_pc=0x0c0651a8u; return 0; }
r[2]=read(ram,r[1]+12,4);
goto P_0c0651aa;
P_0c0651aa: /* original 4308, guest PC 0x0c0651aa */
if(!s->budget--) { s->failed_pc=0x0c0651aau; return 0; }
r[3]<<=2;
goto P_0c0651ac;
P_0c0651ac: /* original 0326, guest PC 0x0c0651ac */
if(!s->budget--) { s->failed_pc=0x0c0651acu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0651ae;
P_0c0651ae: /* original 65c3, guest PC 0x0c0651ae */
if(!s->budget--) { s->failed_pc=0x0c0651aeu; return 0; }
r[5]=r[12];
goto P_0c0651b0;
P_0c0651b0: /* original 66e2, guest PC 0x0c0651b0 */
if(!s->budget--) { s->failed_pc=0x0c0651b0u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0651b2;
P_0c0651b2: /* original 5664, guest PC 0x0c0651b2 */
if(!s->budget--) { s->failed_pc=0x0c0651b2u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0651b4;
P_0c0651b4: /* original b9c6, guest PC 0x0c0651b4 */
if(!s->budget--) { s->failed_pc=0x0c0651b4u; return 0; }
target=0x0c064544u; r[16]=0x0c0651b8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0651b8u) { target=s->pc; goto dispatch; }
goto P_0c0651b8;
P_0c0651b6: /* original 64d3, guest PC 0x0c0651b6 */
if(!s->budget--) { s->failed_pc=0x0c0651b6u; return 0; }
r[4]=r[13];
goto P_0c0651b8;
P_0c0651b8: /* original 64b2, guest PC 0x0c0651b8 */
if(!s->budget--) { s->failed_pc=0x0c0651b8u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0651ba;
P_0c0651ba: /* original e120, guest PC 0x0c0651ba */
if(!s->budget--) { s->failed_pc=0x0c0651bau; return 0; }
r[1]=0x00000020u;
goto P_0c0651bc;
P_0c0651bc: /* original 6903, guest PC 0x0c0651bc */
if(!s->budget--) { s->failed_pc=0x0c0651bcu; return 0; }
r[9]=r[0];
goto P_0c0651be;
P_0c0651be: /* original 6293, guest PC 0x0c0651be */
if(!s->budget--) { s->failed_pc=0x0c0651beu; return 0; }
r[2]=r[9];
goto P_0c0651c0;
P_0c0651c0: /* original d05e, guest PC 0x0c0651c0 */
if(!s->budget--) { s->failed_pc=0x0c0651c0u; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c0651c2;
P_0c0651c2: /* original 314c, guest PC 0x0c0651c2 */
if(!s->budget--) { s->failed_pc=0x0c0651c2u; return 0; }
r[1]+=r[4];
goto P_0c0651c4;
P_0c0651c4: /* original f318, guest PC 0x0c0651c4 */
if(!s->budget--) { s->failed_pc=0x0c0651c4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0651c6;
P_0c0651c6: /* original 7901, guest PC 0x0c0651c6 */
if(!s->budget--) { s->failed_pc=0x0c0651c6u; return 0; }
r[9]+=0x00000001u;
goto P_0c0651c8;
P_0c0651c8: /* original 4208, guest PC 0x0c0651c8 */
if(!s->budget--) { s->failed_pc=0x0c0651c8u; return 0; }
r[2]<<=2;
goto P_0c0651ca;
P_0c0651ca: /* original f3f2, guest PC 0x0c0651ca */
if(!s->budget--) { s->failed_pc=0x0c0651cau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0651cc;
P_0c0651cc: /* original f33d, guest PC 0x0c0651cc */
if(!s->budget--) { s->failed_pc=0x0c0651ccu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0651ce;
P_0c0651ce: /* original e124, guest PC 0x0c0651ce */
if(!s->budget--) { s->failed_pc=0x0c0651ceu; return 0; }
r[1]=0x00000024u;
goto P_0c0651d0;
P_0c0651d0: /* original 035a, guest PC 0x0c0651d0 */
if(!s->budget--) { s->failed_pc=0x0c0651d0u; return 0; }
r[3]=r[53];
goto P_0c0651d2;
P_0c0651d2: /* original 4328, guest PC 0x0c0651d2 */
if(!s->budget--) { s->failed_pc=0x0c0651d2u; return 0; }
r[3]<<=16;
goto P_0c0651d4;
P_0c0651d4: /* original 4318, guest PC 0x0c0651d4 */
if(!s->budget--) { s->failed_pc=0x0c0651d4u; return 0; }
r[3]<<=8;
goto P_0c0651d6;
P_0c0651d6: /* original 314c, guest PC 0x0c0651d6 */
if(!s->budget--) { s->failed_pc=0x0c0651d6u; return 0; }
r[1]+=r[4];
goto P_0c0651d8;
P_0c0651d8: /* original f318, guest PC 0x0c0651d8 */
if(!s->budget--) { s->failed_pc=0x0c0651d8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0651da;
P_0c0651da: /* original f3f2, guest PC 0x0c0651da */
if(!s->budget--) { s->failed_pc=0x0c0651dau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0651dc;
P_0c0651dc: /* original f33d, guest PC 0x0c0651dc */
if(!s->budget--) { s->failed_pc=0x0c0651dcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0651de;
P_0c0651de: /* original 015a, guest PC 0x0c0651de */
if(!s->budget--) { s->failed_pc=0x0c0651deu; return 0; }
r[1]=r[53];
goto P_0c0651e0;
P_0c0651e0: /* original 4128, guest PC 0x0c0651e0 */
if(!s->budget--) { s->failed_pc=0x0c0651e0u; return 0; }
r[1]<<=16;
goto P_0c0651e2;
P_0c0651e2: /* original 231b, guest PC 0x0c0651e2 */
if(!s->budget--) { s->failed_pc=0x0c0651e2u; return 0; }
r[3]|=r[1];
goto P_0c0651e4;
P_0c0651e4: /* original e128, guest PC 0x0c0651e4 */
if(!s->budget--) { s->failed_pc=0x0c0651e4u; return 0; }
r[1]=0x00000028u;
goto P_0c0651e6;
P_0c0651e6: /* original 314c, guest PC 0x0c0651e6 */
if(!s->budget--) { s->failed_pc=0x0c0651e6u; return 0; }
r[1]+=r[4];
goto P_0c0651e8;
P_0c0651e8: /* original f318, guest PC 0x0c0651e8 */
if(!s->budget--) { s->failed_pc=0x0c0651e8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0651ea;
P_0c0651ea: /* original f3f2, guest PC 0x0c0651ea */
if(!s->budget--) { s->failed_pc=0x0c0651eau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0651ec;
P_0c0651ec: /* original f33d, guest PC 0x0c0651ec */
if(!s->budget--) { s->failed_pc=0x0c0651ecu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0651ee;
P_0c0651ee: /* original 015a, guest PC 0x0c0651ee */
if(!s->budget--) { s->failed_pc=0x0c0651eeu; return 0; }
r[1]=r[53];
goto P_0c0651f0;
P_0c0651f0: /* original 4118, guest PC 0x0c0651f0 */
if(!s->budget--) { s->failed_pc=0x0c0651f0u; return 0; }
r[1]<<=8;
goto P_0c0651f2;
P_0c0651f2: /* original 231b, guest PC 0x0c0651f2 */
if(!s->budget--) { s->failed_pc=0x0c0651f2u; return 0; }
r[3]|=r[1];
goto P_0c0651f4;
P_0c0651f4: /* original e12c, guest PC 0x0c0651f4 */
if(!s->budget--) { s->failed_pc=0x0c0651f4u; return 0; }
r[1]=0x0000002cu;
goto P_0c0651f6;
P_0c0651f6: /* original 314c, guest PC 0x0c0651f6 */
if(!s->budget--) { s->failed_pc=0x0c0651f6u; return 0; }
r[1]+=r[4];
goto P_0c0651f8;
P_0c0651f8: /* original f318, guest PC 0x0c0651f8 */
if(!s->budget--) { s->failed_pc=0x0c0651f8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0651fa;
P_0c0651fa: /* original f3f2, guest PC 0x0c0651fa */
if(!s->budget--) { s->failed_pc=0x0c0651fau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0651fc;
P_0c0651fc: /* original f33d, guest PC 0x0c0651fc */
if(!s->budget--) { s->failed_pc=0x0c0651fcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0651fe;
P_0c0651fe: /* original 015a, guest PC 0x0c0651fe */
if(!s->budget--) { s->failed_pc=0x0c0651feu; return 0; }
r[1]=r[53];
goto P_0c065200;
P_0c065200: /* original 231b, guest PC 0x0c065200 */
if(!s->budget--) { s->failed_pc=0x0c065200u; return 0; }
r[3]|=r[1];
goto P_0c065202;
P_0c065202: /* original 0236, guest PC 0x0c065202 */
if(!s->budget--) { s->failed_pc=0x0c065202u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065204;
P_0c065204: /* original 6cb2, guest PC 0x0c065204 */
if(!s->budget--) { s->failed_pc=0x0c065204u; return 0; }
tmp=read(ram,r[11],4);
r[12]=tmp;
goto P_0c065206;
P_0c065206: /* original e030, guest PC 0x0c065206 */
if(!s->budget--) { s->failed_pc=0x0c065206u; return 0; }
r[0]=0x00000030u;
goto P_0c065208;
P_0c065208: /* original f3c6, guest PC 0x0c065208 */
if(!s->budget--) { s->failed_pc=0x0c065208u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06520a;
P_0c06520a: /* original e034, guest PC 0x0c06520a */
if(!s->budget--) { s->failed_pc=0x0c06520au; return 0; }
r[0]=0x00000034u;
goto P_0c06520c;
P_0c06520c: /* original f3f2, guest PC 0x0c06520c */
if(!s->budget--) { s->failed_pc=0x0c06520cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06520e;
P_0c06520e: /* original f33d, guest PC 0x0c06520e */
if(!s->budget--) { s->failed_pc=0x0c06520eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065210;
P_0c065210: /* original f3c6, guest PC 0x0c065210 */
if(!s->budget--) { s->failed_pc=0x0c065210u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065212;
P_0c065212: /* original 065a, guest PC 0x0c065212 */
if(!s->budget--) { s->failed_pc=0x0c065212u; return 0; }
r[6]=r[53];
goto P_0c065214;
P_0c065214: /* original 4628, guest PC 0x0c065214 */
if(!s->budget--) { s->failed_pc=0x0c065214u; return 0; }
r[6]<<=16;
goto P_0c065216;
P_0c065216: /* original 4618, guest PC 0x0c065216 */
if(!s->budget--) { s->failed_pc=0x0c065216u; return 0; }
r[6]<<=8;
goto P_0c065218;
P_0c065218: /* original f3f2, guest PC 0x0c065218 */
if(!s->budget--) { s->failed_pc=0x0c065218u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06521a;
P_0c06521a: /* original e038, guest PC 0x0c06521a */
if(!s->budget--) { s->failed_pc=0x0c06521au; return 0; }
r[0]=0x00000038u;
goto P_0c06521c;
P_0c06521c: /* original f33d, guest PC 0x0c06521c */
if(!s->budget--) { s->failed_pc=0x0c06521cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06521e;
P_0c06521e: /* original 035a, guest PC 0x0c06521e */
if(!s->budget--) { s->failed_pc=0x0c06521eu; return 0; }
r[3]=r[53];
goto P_0c065220;
P_0c065220: /* original f3c6, guest PC 0x0c065220 */
if(!s->budget--) { s->failed_pc=0x0c065220u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065222;
P_0c065222: /* original 4328, guest PC 0x0c065222 */
if(!s->budget--) { s->failed_pc=0x0c065222u; return 0; }
r[3]<<=16;
goto P_0c065224;
P_0c065224: /* original 263b, guest PC 0x0c065224 */
if(!s->budget--) { s->failed_pc=0x0c065224u; return 0; }
r[6]|=r[3];
goto P_0c065226;
P_0c065226: /* original f3f2, guest PC 0x0c065226 */
if(!s->budget--) { s->failed_pc=0x0c065226u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065228;
P_0c065228: /* original f33d, guest PC 0x0c065228 */
if(!s->budget--) { s->failed_pc=0x0c065228u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06522a;
P_0c06522a: /* original e03c, guest PC 0x0c06522a */
if(!s->budget--) { s->failed_pc=0x0c06522au; return 0; }
r[0]=0x0000003cu;
goto P_0c06522c;
P_0c06522c: /* original f3c6, guest PC 0x0c06522c */
if(!s->budget--) { s->failed_pc=0x0c06522cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06522e;
P_0c06522e: /* original 035a, guest PC 0x0c06522e */
if(!s->budget--) { s->failed_pc=0x0c06522eu; return 0; }
r[3]=r[53];
goto P_0c065230;
P_0c065230: /* original 4318, guest PC 0x0c065230 */
if(!s->budget--) { s->failed_pc=0x0c065230u; return 0; }
r[3]<<=8;
goto P_0c065232;
P_0c065232: /* original 263b, guest PC 0x0c065232 */
if(!s->budget--) { s->failed_pc=0x0c065232u; return 0; }
r[6]|=r[3];
goto P_0c065234;
P_0c065234: /* original f3f2, guest PC 0x0c065234 */
if(!s->budget--) { s->failed_pc=0x0c065234u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065236;
P_0c065236: /* original f33d, guest PC 0x0c065236 */
if(!s->budget--) { s->failed_pc=0x0c065236u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065238;
P_0c065238: /* original 035a, guest PC 0x0c065238 */
if(!s->budget--) { s->failed_pc=0x0c065238u; return 0; }
r[3]=r[53];
goto P_0c06523a;
P_0c06523a: /* original 263b, guest PC 0x0c06523a */
if(!s->budget--) { s->failed_pc=0x0c06523au; return 0; }
r[6]|=r[3];
goto P_0c06523c;
P_0c06523c: /* original 6593, guest PC 0x0c06523c */
if(!s->budget--) { s->failed_pc=0x0c06523cu; return 0; }
r[5]=r[9];
goto P_0c06523e;
P_0c06523e: /* original b977, guest PC 0x0c06523e */
if(!s->budget--) { s->failed_pc=0x0c06523eu; return 0; }
target=0x0c064530u; r[16]=0x0c065242u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065242u) { target=s->pc; goto dispatch; }
goto P_0c065242;
P_0c065240: /* original 64d3, guest PC 0x0c065240 */
if(!s->budget--) { s->failed_pc=0x0c065240u; return 0; }
r[4]=r[13];
goto P_0c065242;
P_0c065242: /* original 6c03, guest PC 0x0c065242 */
if(!s->budget--) { s->failed_pc=0x0c065242u; return 0; }
r[12]=r[0];
goto P_0c065244;
P_0c065244: /* original 61a2, guest PC 0x0c065244 */
if(!s->budget--) { s->failed_pc=0x0c065244u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065246;
P_0c065246: /* original 63c3, guest PC 0x0c065246 */
if(!s->budget--) { s->failed_pc=0x0c065246u; return 0; }
r[3]=r[12];
goto P_0c065248;
P_0c065248: /* original d03c, guest PC 0x0c065248 */
if(!s->budget--) { s->failed_pc=0x0c065248u; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c06524a;
P_0c06524a: /* original 7c01, guest PC 0x0c06524a */
if(!s->budget--) { s->failed_pc=0x0c06524au; return 0; }
r[12]+=0x00000001u;
goto P_0c06524c;
P_0c06524c: /* original 5211, guest PC 0x0c06524c */
if(!s->budget--) { s->failed_pc=0x0c06524cu; return 0; }
r[2]=read(ram,r[1]+4,4);
goto P_0c06524e;
P_0c06524e: /* original 4308, guest PC 0x0c06524e */
if(!s->budget--) { s->failed_pc=0x0c06524eu; return 0; }
r[3]<<=2;
goto P_0c065250;
P_0c065250: /* original 0326, guest PC 0x0c065250 */
if(!s->budget--) { s->failed_pc=0x0c065250u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065252;
P_0c065252: /* original 63c3, guest PC 0x0c065252 */
if(!s->budget--) { s->failed_pc=0x0c065252u; return 0; }
r[3]=r[12];
goto P_0c065254;
P_0c065254: /* original 61a2, guest PC 0x0c065254 */
if(!s->budget--) { s->failed_pc=0x0c065254u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065256;
P_0c065256: /* original 7c01, guest PC 0x0c065256 */
if(!s->budget--) { s->failed_pc=0x0c065256u; return 0; }
r[12]+=0x00000001u;
goto P_0c065258;
P_0c065258: /* original 5212, guest PC 0x0c065258 */
if(!s->budget--) { s->failed_pc=0x0c065258u; return 0; }
r[2]=read(ram,r[1]+8,4);
goto P_0c06525a;
P_0c06525a: /* original 4308, guest PC 0x0c06525a */
if(!s->budget--) { s->failed_pc=0x0c06525au; return 0; }
r[3]<<=2;
goto P_0c06525c;
P_0c06525c: /* original 0326, guest PC 0x0c06525c */
if(!s->budget--) { s->failed_pc=0x0c06525cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06525e;
P_0c06525e: /* original 63c3, guest PC 0x0c06525e */
if(!s->budget--) { s->failed_pc=0x0c06525eu; return 0; }
r[3]=r[12];
goto P_0c065260;
P_0c065260: /* original 61a2, guest PC 0x0c065260 */
if(!s->budget--) { s->failed_pc=0x0c065260u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065262;
P_0c065262: /* original 7c01, guest PC 0x0c065262 */
if(!s->budget--) { s->failed_pc=0x0c065262u; return 0; }
r[12]+=0x00000001u;
goto P_0c065264;
P_0c065264: /* original 5213, guest PC 0x0c065264 */
if(!s->budget--) { s->failed_pc=0x0c065264u; return 0; }
r[2]=read(ram,r[1]+12,4);
goto P_0c065266;
P_0c065266: /* original 4308, guest PC 0x0c065266 */
if(!s->budget--) { s->failed_pc=0x0c065266u; return 0; }
r[3]<<=2;
goto P_0c065268;
P_0c065268: /* original 0326, guest PC 0x0c065268 */
if(!s->budget--) { s->failed_pc=0x0c065268u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06526a;
P_0c06526a: /* original 65c3, guest PC 0x0c06526a */
if(!s->budget--) { s->failed_pc=0x0c06526au; return 0; }
r[5]=r[12];
goto P_0c06526c;
P_0c06526c: /* original 66e2, guest PC 0x0c06526c */
if(!s->budget--) { s->failed_pc=0x0c06526cu; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c06526e;
P_0c06526e: /* original 5664, guest PC 0x0c06526e */
if(!s->budget--) { s->failed_pc=0x0c06526eu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065270;
P_0c065270: /* original b968, guest PC 0x0c065270 */
if(!s->budget--) { s->failed_pc=0x0c065270u; return 0; }
target=0x0c064544u; r[16]=0x0c065274u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065274u) { target=s->pc; goto dispatch; }
goto P_0c065274;
P_0c065272: /* original 64d3, guest PC 0x0c065272 */
if(!s->budget--) { s->failed_pc=0x0c065272u; return 0; }
r[4]=r[13];
goto P_0c065274;
P_0c065274: /* original 64a2, guest PC 0x0c065274 */
if(!s->budget--) { s->failed_pc=0x0c065274u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c065276;
P_0c065276: /* original e120, guest PC 0x0c065276 */
if(!s->budget--) { s->failed_pc=0x0c065276u; return 0; }
r[1]=0x00000020u;
goto P_0c065278;
P_0c065278: /* original 6c03, guest PC 0x0c065278 */
if(!s->budget--) { s->failed_pc=0x0c065278u; return 0; }
r[12]=r[0];
goto P_0c06527a;
P_0c06527a: /* original 62c3, guest PC 0x0c06527a */
if(!s->budget--) { s->failed_pc=0x0c06527au; return 0; }
r[2]=r[12];
goto P_0c06527c;
P_0c06527c: /* original d02f, guest PC 0x0c06527c */
if(!s->budget--) { s->failed_pc=0x0c06527cu; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c06527e;
P_0c06527e: /* original 314c, guest PC 0x0c06527e */
if(!s->budget--) { s->failed_pc=0x0c06527eu; return 0; }
r[1]+=r[4];
goto P_0c065280;
P_0c065280: /* original f318, guest PC 0x0c065280 */
if(!s->budget--) { s->failed_pc=0x0c065280u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065282;
P_0c065282: /* original 7c01, guest PC 0x0c065282 */
if(!s->budget--) { s->failed_pc=0x0c065282u; return 0; }
r[12]+=0x00000001u;
goto P_0c065284;
P_0c065284: /* original 4208, guest PC 0x0c065284 */
if(!s->budget--) { s->failed_pc=0x0c065284u; return 0; }
r[2]<<=2;
goto P_0c065286;
P_0c065286: /* original f3f2, guest PC 0x0c065286 */
if(!s->budget--) { s->failed_pc=0x0c065286u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065288;
P_0c065288: /* original f33d, guest PC 0x0c065288 */
if(!s->budget--) { s->failed_pc=0x0c065288u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06528a;
P_0c06528a: /* original e124, guest PC 0x0c06528a */
if(!s->budget--) { s->failed_pc=0x0c06528au; return 0; }
r[1]=0x00000024u;
goto P_0c06528c;
P_0c06528c: /* original 035a, guest PC 0x0c06528c */
if(!s->budget--) { s->failed_pc=0x0c06528cu; return 0; }
r[3]=r[53];
goto P_0c06528e;
P_0c06528e: /* original 4328, guest PC 0x0c06528e */
if(!s->budget--) { s->failed_pc=0x0c06528eu; return 0; }
r[3]<<=16;
goto P_0c065290;
P_0c065290: /* original 4318, guest PC 0x0c065290 */
if(!s->budget--) { s->failed_pc=0x0c065290u; return 0; }
r[3]<<=8;
goto P_0c065292;
P_0c065292: /* original 314c, guest PC 0x0c065292 */
if(!s->budget--) { s->failed_pc=0x0c065292u; return 0; }
r[1]+=r[4];
goto P_0c065294;
P_0c065294: /* original f318, guest PC 0x0c065294 */
if(!s->budget--) { s->failed_pc=0x0c065294u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065296;
P_0c065296: /* original f3f2, guest PC 0x0c065296 */
if(!s->budget--) { s->failed_pc=0x0c065296u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065298;
P_0c065298: /* original f33d, guest PC 0x0c065298 */
if(!s->budget--) { s->failed_pc=0x0c065298u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06529a;
P_0c06529a: /* original 015a, guest PC 0x0c06529a */
if(!s->budget--) { s->failed_pc=0x0c06529au; return 0; }
r[1]=r[53];
goto P_0c06529c;
P_0c06529c: /* original 4128, guest PC 0x0c06529c */
if(!s->budget--) { s->failed_pc=0x0c06529cu; return 0; }
r[1]<<=16;
goto P_0c06529e;
P_0c06529e: /* original 231b, guest PC 0x0c06529e */
if(!s->budget--) { s->failed_pc=0x0c06529eu; return 0; }
r[3]|=r[1];
goto P_0c0652a0;
P_0c0652a0: /* original e128, guest PC 0x0c0652a0 */
if(!s->budget--) { s->failed_pc=0x0c0652a0u; return 0; }
r[1]=0x00000028u;
goto P_0c0652a2;
P_0c0652a2: /* original 314c, guest PC 0x0c0652a2 */
if(!s->budget--) { s->failed_pc=0x0c0652a2u; return 0; }
r[1]+=r[4];
goto P_0c0652a4;
P_0c0652a4: /* original f318, guest PC 0x0c0652a4 */
if(!s->budget--) { s->failed_pc=0x0c0652a4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0652a6;
P_0c0652a6: /* original f3f2, guest PC 0x0c0652a6 */
if(!s->budget--) { s->failed_pc=0x0c0652a6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652a8;
P_0c0652a8: /* original f33d, guest PC 0x0c0652a8 */
if(!s->budget--) { s->failed_pc=0x0c0652a8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652aa;
P_0c0652aa: /* original 015a, guest PC 0x0c0652aa */
if(!s->budget--) { s->failed_pc=0x0c0652aau; return 0; }
r[1]=r[53];
goto P_0c0652ac;
P_0c0652ac: /* original 4118, guest PC 0x0c0652ac */
if(!s->budget--) { s->failed_pc=0x0c0652acu; return 0; }
r[1]<<=8;
goto P_0c0652ae;
P_0c0652ae: /* original 231b, guest PC 0x0c0652ae */
if(!s->budget--) { s->failed_pc=0x0c0652aeu; return 0; }
r[3]|=r[1];
goto P_0c0652b0;
P_0c0652b0: /* original e12c, guest PC 0x0c0652b0 */
if(!s->budget--) { s->failed_pc=0x0c0652b0u; return 0; }
r[1]=0x0000002cu;
goto P_0c0652b2;
P_0c0652b2: /* original 314c, guest PC 0x0c0652b2 */
if(!s->budget--) { s->failed_pc=0x0c0652b2u; return 0; }
r[1]+=r[4];
goto P_0c0652b4;
P_0c0652b4: /* original f318, guest PC 0x0c0652b4 */
if(!s->budget--) { s->failed_pc=0x0c0652b4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0652b6;
P_0c0652b6: /* original f3f2, guest PC 0x0c0652b6 */
if(!s->budget--) { s->failed_pc=0x0c0652b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652b8;
P_0c0652b8: /* original f33d, guest PC 0x0c0652b8 */
if(!s->budget--) { s->failed_pc=0x0c0652b8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652ba;
P_0c0652ba: /* original 015a, guest PC 0x0c0652ba */
if(!s->budget--) { s->failed_pc=0x0c0652bau; return 0; }
r[1]=r[53];
goto P_0c0652bc;
P_0c0652bc: /* original 231b, guest PC 0x0c0652bc */
if(!s->budget--) { s->failed_pc=0x0c0652bcu; return 0; }
r[3]|=r[1];
goto P_0c0652be;
P_0c0652be: /* original 0236, guest PC 0x0c0652be */
if(!s->budget--) { s->failed_pc=0x0c0652beu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0652c0;
P_0c0652c0: /* original 6ba2, guest PC 0x0c0652c0 */
if(!s->budget--) { s->failed_pc=0x0c0652c0u; return 0; }
tmp=read(ram,r[10],4);
r[11]=tmp;
goto P_0c0652c2;
P_0c0652c2: /* original e030, guest PC 0x0c0652c2 */
if(!s->budget--) { s->failed_pc=0x0c0652c2u; return 0; }
r[0]=0x00000030u;
goto P_0c0652c4;
P_0c0652c4: /* original f3b6, guest PC 0x0c0652c4 */
if(!s->budget--) { s->failed_pc=0x0c0652c4u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0652c6;
P_0c0652c6: /* original e034, guest PC 0x0c0652c6 */
if(!s->budget--) { s->failed_pc=0x0c0652c6u; return 0; }
r[0]=0x00000034u;
goto P_0c0652c8;
P_0c0652c8: /* original f3f2, guest PC 0x0c0652c8 */
if(!s->budget--) { s->failed_pc=0x0c0652c8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652ca;
P_0c0652ca: /* original f33d, guest PC 0x0c0652ca */
if(!s->budget--) { s->failed_pc=0x0c0652cau; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652cc;
P_0c0652cc: /* original f3b6, guest PC 0x0c0652cc */
if(!s->budget--) { s->failed_pc=0x0c0652ccu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0652ce;
P_0c0652ce: /* original 065a, guest PC 0x0c0652ce */
if(!s->budget--) { s->failed_pc=0x0c0652ceu; return 0; }
r[6]=r[53];
goto P_0c0652d0;
P_0c0652d0: /* original 4628, guest PC 0x0c0652d0 */
if(!s->budget--) { s->failed_pc=0x0c0652d0u; return 0; }
r[6]<<=16;
goto P_0c0652d2;
P_0c0652d2: /* original 4618, guest PC 0x0c0652d2 */
if(!s->budget--) { s->failed_pc=0x0c0652d2u; return 0; }
r[6]<<=8;
goto P_0c0652d4;
P_0c0652d4: /* original f3f2, guest PC 0x0c0652d4 */
if(!s->budget--) { s->failed_pc=0x0c0652d4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652d6;
P_0c0652d6: /* original e038, guest PC 0x0c0652d6 */
if(!s->budget--) { s->failed_pc=0x0c0652d6u; return 0; }
r[0]=0x00000038u;
goto P_0c0652d8;
P_0c0652d8: /* original f33d, guest PC 0x0c0652d8 */
if(!s->budget--) { s->failed_pc=0x0c0652d8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652da;
P_0c0652da: /* original 035a, guest PC 0x0c0652da */
if(!s->budget--) { s->failed_pc=0x0c0652dau; return 0; }
r[3]=r[53];
goto P_0c0652dc;
P_0c0652dc: /* original f3b6, guest PC 0x0c0652dc */
if(!s->budget--) { s->failed_pc=0x0c0652dcu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0652de;
P_0c0652de: /* original 4328, guest PC 0x0c0652de */
if(!s->budget--) { s->failed_pc=0x0c0652deu; return 0; }
r[3]<<=16;
goto P_0c0652e0;
P_0c0652e0: /* original 263b, guest PC 0x0c0652e0 */
if(!s->budget--) { s->failed_pc=0x0c0652e0u; return 0; }
r[6]|=r[3];
goto P_0c0652e2;
P_0c0652e2: /* original f3f2, guest PC 0x0c0652e2 */
if(!s->budget--) { s->failed_pc=0x0c0652e2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652e4;
P_0c0652e4: /* original f33d, guest PC 0x0c0652e4 */
if(!s->budget--) { s->failed_pc=0x0c0652e4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652e6;
P_0c0652e6: /* original e03c, guest PC 0x0c0652e6 */
if(!s->budget--) { s->failed_pc=0x0c0652e6u; return 0; }
r[0]=0x0000003cu;
goto P_0c0652e8;
P_0c0652e8: /* original f3b6, guest PC 0x0c0652e8 */
if(!s->budget--) { s->failed_pc=0x0c0652e8u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0652ea;
P_0c0652ea: /* original 035a, guest PC 0x0c0652ea */
if(!s->budget--) { s->failed_pc=0x0c0652eau; return 0; }
r[3]=r[53];
goto P_0c0652ec;
P_0c0652ec: /* original 4318, guest PC 0x0c0652ec */
if(!s->budget--) { s->failed_pc=0x0c0652ecu; return 0; }
r[3]<<=8;
goto P_0c0652ee;
P_0c0652ee: /* original 263b, guest PC 0x0c0652ee */
if(!s->budget--) { s->failed_pc=0x0c0652eeu; return 0; }
r[6]|=r[3];
goto P_0c0652f0;
P_0c0652f0: /* original f3f2, guest PC 0x0c0652f0 */
if(!s->budget--) { s->failed_pc=0x0c0652f0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652f2;
P_0c0652f2: /* original f33d, guest PC 0x0c0652f2 */
if(!s->budget--) { s->failed_pc=0x0c0652f2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652f4;
P_0c0652f4: /* original 035a, guest PC 0x0c0652f4 */
if(!s->budget--) { s->failed_pc=0x0c0652f4u; return 0; }
r[3]=r[53];
goto P_0c0652f6;
P_0c0652f6: /* original 263b, guest PC 0x0c0652f6 */
if(!s->budget--) { s->failed_pc=0x0c0652f6u; return 0; }
r[6]|=r[3];
goto P_0c0652f8;
P_0c0652f8: /* original 65c3, guest PC 0x0c0652f8 */
if(!s->budget--) { s->failed_pc=0x0c0652f8u; return 0; }
r[5]=r[12];
goto P_0c0652fa;
P_0c0652fa: /* original b919, guest PC 0x0c0652fa */
if(!s->budget--) { s->failed_pc=0x0c0652fau; return 0; }
target=0x0c064530u; r[16]=0x0c0652feu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0652feu) { target=s->pc; goto dispatch; }
goto P_0c0652fe;
P_0c0652fc: /* original 64d3, guest PC 0x0c0652fc */
if(!s->budget--) { s->failed_pc=0x0c0652fcu; return 0; }
r[4]=r[13];
goto P_0c0652fe;
P_0c0652fe: /* original 6403, guest PC 0x0c0652fe */
if(!s->budget--) { s->failed_pc=0x0c0652feu; return 0; }
r[4]=r[0];
goto P_0c065300;
P_0c065300: /* original d310, guest PC 0x0c065300 */
if(!s->budget--) { s->failed_pc=0x0c065300u; return 0; }
r[3]=read(ram,0x0c065344u,4);
goto P_0c065302;
P_0c065302: /* original 4408, guest PC 0x0c065302 */
if(!s->budget--) { s->failed_pc=0x0c065302u; return 0; }
r[4]<<=2;
goto P_0c065304;
P_0c065304: /* original 2342, guest PC 0x0c065304 */
if(!s->budget--) { s->failed_pc=0x0c065304u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c065306;
P_0c065306: /* original b904, guest PC 0x0c065306 */
if(!s->budget--) { s->failed_pc=0x0c065306u; return 0; }
target=0x0c064512u; r[16]=0x0c06530au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06530au) { target=s->pc; goto dispatch; }
goto P_0c06530a;
P_0c065308: /* original 64d3, guest PC 0x0c065308 */
if(!s->budget--) { s->failed_pc=0x0c065308u; return 0; }
r[4]=r[13];
goto P_0c06530a;
P_0c06530a: /* original 6403, guest PC 0x0c06530a */
if(!s->budget--) { s->failed_pc=0x0c06530au; return 0; }
r[4]=r[0];
goto P_0c06530c;
P_0c06530c: /* original e500, guest PC 0x0c06530c */
if(!s->budget--) { s->failed_pc=0x0c06530cu; return 0; }
r[5]=0x00000000u;
goto P_0c06530e;
P_0c06530e: /* original b8eb, guest PC 0x0c06530e */
if(!s->budget--) { s->failed_pc=0x0c06530eu; return 0; }
target=0x0c0644e8u; r[16]=0x0c065312u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065312u) { target=s->pc; goto dispatch; }
goto P_0c065312;
P_0c065310: /* original 6653, guest PC 0x0c065310 */
if(!s->budget--) { s->failed_pc=0x0c065310u; return 0; }
r[6]=r[5];
goto P_0c065312;
P_0c065312: /* original 63e2, guest PC 0x0c065312 */
if(!s->budget--) { s->failed_pc=0x0c065312u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c065314;
P_0c065314: /* original d10c, guest PC 0x0c065314 */
if(!s->budget--) { s->failed_pc=0x0c065314u; return 0; }
r[1]=read(ram,0x0c065348u,4);
goto P_0c065316;
P_0c065316: /* original 5233, guest PC 0x0c065316 */
if(!s->budget--) { s->failed_pc=0x0c065316u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c065318;
P_0c065318: /* original 2122, guest PC 0x0c065318 */
if(!s->budget--) { s->failed_pc=0x0c065318u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c06531a;
P_0c06531a: /* original e000, guest PC 0x0c06531a */
if(!s->budget--) { s->failed_pc=0x0c06531au; return 0; }
r[0]=0x00000000u;
goto P_0c06531c;
P_0c06531c: /* original 7f0c, guest PC 0x0c06531c */
if(!s->budget--) { s->failed_pc=0x0c06531cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06531e;
P_0c06531e: /* original 4f26, guest PC 0x0c06531e */
if(!s->budget--) { s->failed_pc=0x0c06531eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065320;
P_0c065320: /* original fff9, guest PC 0x0c065320 */
if(!s->budget--) { s->failed_pc=0x0c065320u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c065322;
P_0c065322: /* original 69f6, guest PC 0x0c065322 */
if(!s->budget--) { s->failed_pc=0x0c065322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c065324;
P_0c065324: /* original 6af6, guest PC 0x0c065324 */
if(!s->budget--) { s->failed_pc=0x0c065324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c065326;
P_0c065326: /* original 6bf6, guest PC 0x0c065326 */
if(!s->budget--) { s->failed_pc=0x0c065326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c065328;
P_0c065328: /* original 6cf6, guest PC 0x0c065328 */
if(!s->budget--) { s->failed_pc=0x0c065328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06532a;
P_0c06532a: /* original 6df6, guest PC 0x0c06532a */
if(!s->budget--) { s->failed_pc=0x0c06532au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06532c;
P_0c06532c: /* original 000b, guest PC 0x0c06532c */
if(!s->budget--) { s->failed_pc=0x0c06532cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06532e: /* original 6ef6, guest PC 0x0c06532e */
if(!s->budget--) { s->failed_pc=0x0c06532eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c065330u,s,ram);
P_0c06535c: /* original 4f22, guest PC 0x0c06535c */
if(!s->budget--) { s->failed_pc=0x0c06535cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06535e;
P_0c06535e: /* original 7ff0, guest PC 0x0c06535e */
if(!s->budget--) { s->failed_pc=0x0c06535eu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065360;
P_0c065360: /* original 6342, guest PC 0x0c065360 */
if(!s->budget--) { s->failed_pc=0x0c065360u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065362;
P_0c065362: /* original 65f3, guest PC 0x0c065362 */
if(!s->budget--) { s->failed_pc=0x0c065362u; return 0; }
r[5]=r[15];
goto P_0c065364;
P_0c065364: /* original 7504, guest PC 0x0c065364 */
if(!s->budget--) { s->failed_pc=0x0c065364u; return 0; }
r[5]+=0x00000004u;
goto P_0c065366;
P_0c065366: /* original 6e53, guest PC 0x0c065366 */
if(!s->budget--) { s->failed_pc=0x0c065366u; return 0; }
r[14]=r[5];
goto P_0c065368;
P_0c065368: /* original 2e32, guest PC 0x0c065368 */
if(!s->budget--) { s->failed_pc=0x0c065368u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c06536a;
P_0c06536a: /* original 6be3, guest PC 0x0c06536a */
if(!s->budget--) { s->failed_pc=0x0c06536au; return 0; }
r[11]=r[14];
goto P_0c06536c;
P_0c06536c: /* original 5241, guest PC 0x0c06536c */
if(!s->budget--) { s->failed_pc=0x0c06536cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06536e;
P_0c06536e: /* original 6ae3, guest PC 0x0c06536e */
if(!s->budget--) { s->failed_pc=0x0c06536eu; return 0; }
r[10]=r[14];
goto P_0c065370;
P_0c065370: /* original 7b04, guest PC 0x0c065370 */
if(!s->budget--) { s->failed_pc=0x0c065370u; return 0; }
r[11]+=0x00000004u;
goto P_0c065372;
P_0c065372: /* original 7a08, guest PC 0x0c065372 */
if(!s->budget--) { s->failed_pc=0x0c065372u; return 0; }
r[10]+=0x00000008u;
goto P_0c065374;
P_0c065374: /* original 2b22, guest PC 0x0c065374 */
if(!s->budget--) { s->failed_pc=0x0c065374u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c065376;
P_0c065376: /* original 5342, guest PC 0x0c065376 */
if(!s->budget--) { s->failed_pc=0x0c065376u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065378;
P_0c065378: /* original d28b, guest PC 0x0c065378 */
if(!s->budget--) { s->failed_pc=0x0c065378u; return 0; }
r[2]=read(ram,0x0c0655a8u,4);
goto P_0c06537a;
P_0c06537a: /* original 2a32, guest PC 0x0c06537a */
if(!s->budget--) { s->failed_pc=0x0c06537au; return 0; }
write(ram,r[10],r[3],4);
goto P_0c06537c;
P_0c06537c: /* original 6d22, guest PC 0x0c06537c */
if(!s->budget--) { s->failed_pc=0x0c06537cu; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c06537e;
P_0c06537e: /* original d38b, guest PC 0x0c06537e */
if(!s->budget--) { s->failed_pc=0x0c06537eu; return 0; }
r[3]=read(ram,0x0c0655acu,4);
goto P_0c065380;
P_0c065380: /* original 6532, guest PC 0x0c065380 */
if(!s->budget--) { s->failed_pc=0x0c065380u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c065382;
P_0c065382: /* original d18b, guest PC 0x0c065382 */
if(!s->budget--) { s->failed_pc=0x0c065382u; return 0; }
r[1]=read(ram,0x0c0655b0u,4);
goto P_0c065384;
P_0c065384: /* original 6412, guest PC 0x0c065384 */
if(!s->budget--) { s->failed_pc=0x0c065384u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c065386;
P_0c065386: /* original d08b, guest PC 0x0c065386 */
if(!s->budget--) { s->failed_pc=0x0c065386u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c065388;
P_0c065388: /* original 62c3, guest PC 0x0c065388 */
if(!s->budget--) { s->failed_pc=0x0c065388u; return 0; }
r[2]=r[12];
goto P_0c06538a;
P_0c06538a: /* original 7c01, guest PC 0x0c06538a */
if(!s->budget--) { s->failed_pc=0x0c06538au; return 0; }
r[12]+=0x00000001u;
goto P_0c06538c;
P_0c06538c: /* original 4208, guest PC 0x0c06538c */
if(!s->budget--) { s->failed_pc=0x0c06538cu; return 0; }
r[2]<<=2;
goto P_0c06538e;
P_0c06538e: /* original 02d6, guest PC 0x0c06538e */
if(!s->budget--) { s->failed_pc=0x0c06538eu; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065390;
P_0c065390: /* original 63c3, guest PC 0x0c065390 */
if(!s->budget--) { s->failed_pc=0x0c065390u; return 0; }
r[3]=r[12];
goto P_0c065392;
P_0c065392: /* original 7c01, guest PC 0x0c065392 */
if(!s->budget--) { s->failed_pc=0x0c065392u; return 0; }
r[12]+=0x00000001u;
goto P_0c065394;
P_0c065394: /* original 4308, guest PC 0x0c065394 */
if(!s->budget--) { s->failed_pc=0x0c065394u; return 0; }
r[3]<<=2;
goto P_0c065396;
P_0c065396: /* original 0356, guest PC 0x0c065396 */
if(!s->budget--) { s->failed_pc=0x0c065396u; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c065398;
P_0c065398: /* original 62c3, guest PC 0x0c065398 */
if(!s->budget--) { s->failed_pc=0x0c065398u; return 0; }
r[2]=r[12];
goto P_0c06539a;
P_0c06539a: /* original 7c01, guest PC 0x0c06539a */
if(!s->budget--) { s->failed_pc=0x0c06539au; return 0; }
r[12]+=0x00000001u;
goto P_0c06539c;
P_0c06539c: /* original 4208, guest PC 0x0c06539c */
if(!s->budget--) { s->failed_pc=0x0c06539cu; return 0; }
r[2]<<=2;
goto P_0c06539e;
P_0c06539e: /* original 0246, guest PC 0x0c06539e */
if(!s->budget--) { s->failed_pc=0x0c06539eu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c0653a0;
P_0c0653a0: /* original 62e2, guest PC 0x0c0653a0 */
if(!s->budget--) { s->failed_pc=0x0c0653a0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0653a2;
P_0c0653a2: /* original 63c3, guest PC 0x0c0653a2 */
if(!s->budget--) { s->failed_pc=0x0c0653a2u; return 0; }
r[3]=r[12];
goto P_0c0653a4;
P_0c0653a4: /* original 5221, guest PC 0x0c0653a4 */
if(!s->budget--) { s->failed_pc=0x0c0653a4u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c0653a6;
P_0c0653a6: /* original 7c01, guest PC 0x0c0653a6 */
if(!s->budget--) { s->failed_pc=0x0c0653a6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0653a8;
P_0c0653a8: /* original 4308, guest PC 0x0c0653a8 */
if(!s->budget--) { s->failed_pc=0x0c0653a8u; return 0; }
r[3]<<=2;
goto P_0c0653aa;
P_0c0653aa: /* original 0326, guest PC 0x0c0653aa */
if(!s->budget--) { s->failed_pc=0x0c0653aau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0653ac;
P_0c0653ac: /* original 62e2, guest PC 0x0c0653ac */
if(!s->budget--) { s->failed_pc=0x0c0653acu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0653ae;
P_0c0653ae: /* original 63c3, guest PC 0x0c0653ae */
if(!s->budget--) { s->failed_pc=0x0c0653aeu; return 0; }
r[3]=r[12];
goto P_0c0653b0;
P_0c0653b0: /* original 5222, guest PC 0x0c0653b0 */
if(!s->budget--) { s->failed_pc=0x0c0653b0u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c0653b2;
P_0c0653b2: /* original 7c01, guest PC 0x0c0653b2 */
if(!s->budget--) { s->failed_pc=0x0c0653b2u; return 0; }
r[12]+=0x00000001u;
goto P_0c0653b4;
P_0c0653b4: /* original 4308, guest PC 0x0c0653b4 */
if(!s->budget--) { s->failed_pc=0x0c0653b4u; return 0; }
r[3]<<=2;
goto P_0c0653b6;
P_0c0653b6: /* original 0326, guest PC 0x0c0653b6 */
if(!s->budget--) { s->failed_pc=0x0c0653b6u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0653b8;
P_0c0653b8: /* original 62e2, guest PC 0x0c0653b8 */
if(!s->budget--) { s->failed_pc=0x0c0653b8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0653ba;
P_0c0653ba: /* original 63c3, guest PC 0x0c0653ba */
if(!s->budget--) { s->failed_pc=0x0c0653bau; return 0; }
r[3]=r[12];
goto P_0c0653bc;
P_0c0653bc: /* original 5223, guest PC 0x0c0653bc */
if(!s->budget--) { s->failed_pc=0x0c0653bcu; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c0653be;
P_0c0653be: /* original 7c01, guest PC 0x0c0653be */
if(!s->budget--) { s->failed_pc=0x0c0653beu; return 0; }
r[12]+=0x00000001u;
goto P_0c0653c0;
P_0c0653c0: /* original 4308, guest PC 0x0c0653c0 */
if(!s->budget--) { s->failed_pc=0x0c0653c0u; return 0; }
r[3]<<=2;
goto P_0c0653c2;
P_0c0653c2: /* original 0326, guest PC 0x0c0653c2 */
if(!s->budget--) { s->failed_pc=0x0c0653c2u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0653c4;
P_0c0653c4: /* original 67e2, guest PC 0x0c0653c4 */
if(!s->budget--) { s->failed_pc=0x0c0653c4u; return 0; }
tmp=read(ram,r[14],4);
r[7]=tmp;
goto P_0c0653c6;
P_0c0653c6: /* original 2f72, guest PC 0x0c0653c6 */
if(!s->budget--) { s->failed_pc=0x0c0653c6u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0653c8;
P_0c0653c8: /* original 5775, guest PC 0x0c0653c8 */
if(!s->budget--) { s->failed_pc=0x0c0653c8u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c0653ca;
P_0c0653ca: /* original 65c3, guest PC 0x0c0653ca */
if(!s->budget--) { s->failed_pc=0x0c0653cau; return 0; }
r[5]=r[12];
goto P_0c0653cc;
P_0c0653cc: /* original 66f2, guest PC 0x0c0653cc */
if(!s->budget--) { s->failed_pc=0x0c0653ccu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0653ce;
P_0c0653ce: /* original 5664, guest PC 0x0c0653ce */
if(!s->budget--) { s->failed_pc=0x0c0653ceu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0653d0;
P_0c0653d0: /* original b8d2, guest PC 0x0c0653d0 */
if(!s->budget--) { s->failed_pc=0x0c0653d0u; return 0; }
target=0x0c064578u; r[16]=0x0c0653d4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0653d4u) { target=s->pc; goto dispatch; }
goto P_0c0653d4;
P_0c0653d2: /* original 64d3, guest PC 0x0c0653d2 */
if(!s->budget--) { s->failed_pc=0x0c0653d2u; return 0; }
r[4]=r[13];
goto P_0c0653d4;
P_0c0653d4: /* original 64e2, guest PC 0x0c0653d4 */
if(!s->budget--) { s->failed_pc=0x0c0653d4u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0653d6;
P_0c0653d6: /* original e118, guest PC 0x0c0653d6 */
if(!s->budget--) { s->failed_pc=0x0c0653d6u; return 0; }
r[1]=0x00000018u;
goto P_0c0653d8;
P_0c0653d8: /* original 6903, guest PC 0x0c0653d8 */
if(!s->budget--) { s->failed_pc=0x0c0653d8u; return 0; }
r[9]=r[0];
goto P_0c0653da;
P_0c0653da: /* original 6393, guest PC 0x0c0653da */
if(!s->budget--) { s->failed_pc=0x0c0653dau; return 0; }
r[3]=r[9];
goto P_0c0653dc;
P_0c0653dc: /* original c776, guest PC 0x0c0653dc */
if(!s->budget--) { s->failed_pc=0x0c0653dcu; return 0; }
r[0]=0x0c0655b8u;
goto P_0c0653de;
P_0c0653de: /* original 314c, guest PC 0x0c0653de */
if(!s->budget--) { s->failed_pc=0x0c0653deu; return 0; }
r[1]+=r[4];
goto P_0c0653e0;
P_0c0653e0: /* original ff08, guest PC 0x0c0653e0 */
if(!s->budget--) { s->failed_pc=0x0c0653e0u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0653e2;
P_0c0653e2: /* original 7901, guest PC 0x0c0653e2 */
if(!s->budget--) { s->failed_pc=0x0c0653e2u; return 0; }
r[9]+=0x00000001u;
goto P_0c0653e4;
P_0c0653e4: /* original f318, guest PC 0x0c0653e4 */
if(!s->budget--) { s->failed_pc=0x0c0653e4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0653e6;
P_0c0653e6: /* original 4308, guest PC 0x0c0653e6 */
if(!s->budget--) { s->failed_pc=0x0c0653e6u; return 0; }
r[3]<<=2;
goto P_0c0653e8;
P_0c0653e8: /* original d072, guest PC 0x0c0653e8 */
if(!s->budget--) { s->failed_pc=0x0c0653e8u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c0653ea;
P_0c0653ea: /* original f3f2, guest PC 0x0c0653ea */
if(!s->budget--) { s->failed_pc=0x0c0653eau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0653ec;
P_0c0653ec: /* original f33d, guest PC 0x0c0653ec */
if(!s->budget--) { s->failed_pc=0x0c0653ecu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0653ee;
P_0c0653ee: /* original 045a, guest PC 0x0c0653ee */
if(!s->budget--) { s->failed_pc=0x0c0653eeu; return 0; }
r[4]=r[53];
goto P_0c0653f0;
P_0c0653f0: /* original 6243, guest PC 0x0c0653f0 */
if(!s->budget--) { s->failed_pc=0x0c0653f0u; return 0; }
r[2]=r[4];
goto P_0c0653f2;
P_0c0653f2: /* original 4228, guest PC 0x0c0653f2 */
if(!s->budget--) { s->failed_pc=0x0c0653f2u; return 0; }
r[2]<<=16;
goto P_0c0653f4;
P_0c0653f4: /* original 4218, guest PC 0x0c0653f4 */
if(!s->budget--) { s->failed_pc=0x0c0653f4u; return 0; }
r[2]<<=8;
goto P_0c0653f6;
P_0c0653f6: /* original 6143, guest PC 0x0c0653f6 */
if(!s->budget--) { s->failed_pc=0x0c0653f6u; return 0; }
r[1]=r[4];
goto P_0c0653f8;
P_0c0653f8: /* original 4128, guest PC 0x0c0653f8 */
if(!s->budget--) { s->failed_pc=0x0c0653f8u; return 0; }
r[1]<<=16;
goto P_0c0653fa;
P_0c0653fa: /* original 221b, guest PC 0x0c0653fa */
if(!s->budget--) { s->failed_pc=0x0c0653fau; return 0; }
r[2]|=r[1];
goto P_0c0653fc;
P_0c0653fc: /* original 6143, guest PC 0x0c0653fc */
if(!s->budget--) { s->failed_pc=0x0c0653fcu; return 0; }
r[1]=r[4];
goto P_0c0653fe;
P_0c0653fe: /* original 4118, guest PC 0x0c0653fe */
if(!s->budget--) { s->failed_pc=0x0c0653feu; return 0; }
r[1]<<=8;
goto P_0c065400;
P_0c065400: /* original 221b, guest PC 0x0c065400 */
if(!s->budget--) { s->failed_pc=0x0c065400u; return 0; }
r[2]|=r[1];
goto P_0c065402;
P_0c065402: /* original 224b, guest PC 0x0c065402 */
if(!s->budget--) { s->failed_pc=0x0c065402u; return 0; }
r[2]|=r[4];
goto P_0c065404;
P_0c065404: /* original 0326, guest PC 0x0c065404 */
if(!s->budget--) { s->failed_pc=0x0c065404u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065406;
P_0c065406: /* original e01c, guest PC 0x0c065406 */
if(!s->budget--) { s->failed_pc=0x0c065406u; return 0; }
r[0]=0x0000001cu;
goto P_0c065408;
P_0c065408: /* original 6ce2, guest PC 0x0c065408 */
if(!s->budget--) { s->failed_pc=0x0c065408u; return 0; }
tmp=read(ram,r[14],4);
r[12]=tmp;
goto P_0c06540a;
P_0c06540a: /* original f3c6, guest PC 0x0c06540a */
if(!s->budget--) { s->failed_pc=0x0c06540au; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06540c;
P_0c06540c: /* original f3f2, guest PC 0x0c06540c */
if(!s->budget--) { s->failed_pc=0x0c06540cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06540e;
P_0c06540e: /* original f33d, guest PC 0x0c06540e */
if(!s->budget--) { s->failed_pc=0x0c06540eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065410;
P_0c065410: /* original 0c5a, guest PC 0x0c065410 */
if(!s->budget--) { s->failed_pc=0x0c065410u; return 0; }
r[12]=r[53];
goto P_0c065412;
P_0c065412: /* original 66c3, guest PC 0x0c065412 */
if(!s->budget--) { s->failed_pc=0x0c065412u; return 0; }
r[6]=r[12];
goto P_0c065414;
P_0c065414: /* original 4628, guest PC 0x0c065414 */
if(!s->budget--) { s->failed_pc=0x0c065414u; return 0; }
r[6]<<=16;
goto P_0c065416;
P_0c065416: /* original 4618, guest PC 0x0c065416 */
if(!s->budget--) { s->failed_pc=0x0c065416u; return 0; }
r[6]<<=8;
goto P_0c065418;
P_0c065418: /* original 63c3, guest PC 0x0c065418 */
if(!s->budget--) { s->failed_pc=0x0c065418u; return 0; }
r[3]=r[12];
goto P_0c06541a;
P_0c06541a: /* original 4328, guest PC 0x0c06541a */
if(!s->budget--) { s->failed_pc=0x0c06541au; return 0; }
r[3]<<=16;
goto P_0c06541c;
P_0c06541c: /* original 263b, guest PC 0x0c06541c */
if(!s->budget--) { s->failed_pc=0x0c06541cu; return 0; }
r[6]|=r[3];
goto P_0c06541e;
P_0c06541e: /* original 62c3, guest PC 0x0c06541e */
if(!s->budget--) { s->failed_pc=0x0c06541eu; return 0; }
r[2]=r[12];
goto P_0c065420;
P_0c065420: /* original 4218, guest PC 0x0c065420 */
if(!s->budget--) { s->failed_pc=0x0c065420u; return 0; }
r[2]<<=8;
goto P_0c065422;
P_0c065422: /* original 262b, guest PC 0x0c065422 */
if(!s->budget--) { s->failed_pc=0x0c065422u; return 0; }
r[6]|=r[2];
goto P_0c065424;
P_0c065424: /* original 26cb, guest PC 0x0c065424 */
if(!s->budget--) { s->failed_pc=0x0c065424u; return 0; }
r[6]|=r[12];
goto P_0c065426;
P_0c065426: /* original 6593, guest PC 0x0c065426 */
if(!s->budget--) { s->failed_pc=0x0c065426u; return 0; }
r[5]=r[9];
goto P_0c065428;
P_0c065428: /* original b882, guest PC 0x0c065428 */
if(!s->budget--) { s->failed_pc=0x0c065428u; return 0; }
target=0x0c064530u; r[16]=0x0c06542cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06542cu) { target=s->pc; goto dispatch; }
goto P_0c06542c;
P_0c06542a: /* original 64d3, guest PC 0x0c06542a */
if(!s->budget--) { s->failed_pc=0x0c06542au; return 0; }
r[4]=r[13];
goto P_0c06542c;
P_0c06542c: /* original 64e2, guest PC 0x0c06542c */
if(!s->budget--) { s->failed_pc=0x0c06542cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c06542e;
P_0c06542e: /* original e11c, guest PC 0x0c06542e */
if(!s->budget--) { s->failed_pc=0x0c06542eu; return 0; }
r[1]=0x0000001cu;
goto P_0c065430;
P_0c065430: /* original 6c03, guest PC 0x0c065430 */
if(!s->budget--) { s->failed_pc=0x0c065430u; return 0; }
r[12]=r[0];
goto P_0c065432;
P_0c065432: /* original 62c3, guest PC 0x0c065432 */
if(!s->budget--) { s->failed_pc=0x0c065432u; return 0; }
r[2]=r[12];
goto P_0c065434;
P_0c065434: /* original d05f, guest PC 0x0c065434 */
if(!s->budget--) { s->failed_pc=0x0c065434u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c065436;
P_0c065436: /* original 314c, guest PC 0x0c065436 */
if(!s->budget--) { s->failed_pc=0x0c065436u; return 0; }
r[1]+=r[4];
goto P_0c065438;
P_0c065438: /* original f318, guest PC 0x0c065438 */
if(!s->budget--) { s->failed_pc=0x0c065438u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06543a;
P_0c06543a: /* original 7c01, guest PC 0x0c06543a */
if(!s->budget--) { s->failed_pc=0x0c06543au; return 0; }
r[12]+=0x00000001u;
goto P_0c06543c;
P_0c06543c: /* original 4208, guest PC 0x0c06543c */
if(!s->budget--) { s->failed_pc=0x0c06543cu; return 0; }
r[2]<<=2;
goto P_0c06543e;
P_0c06543e: /* original f3f2, guest PC 0x0c06543e */
if(!s->budget--) { s->failed_pc=0x0c06543eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065440;
P_0c065440: /* original f33d, guest PC 0x0c065440 */
if(!s->budget--) { s->failed_pc=0x0c065440u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065442;
P_0c065442: /* original 045a, guest PC 0x0c065442 */
if(!s->budget--) { s->failed_pc=0x0c065442u; return 0; }
r[4]=r[53];
goto P_0c065444;
P_0c065444: /* original 6343, guest PC 0x0c065444 */
if(!s->budget--) { s->failed_pc=0x0c065444u; return 0; }
r[3]=r[4];
goto P_0c065446;
P_0c065446: /* original 4328, guest PC 0x0c065446 */
if(!s->budget--) { s->failed_pc=0x0c065446u; return 0; }
r[3]<<=16;
goto P_0c065448;
P_0c065448: /* original 4318, guest PC 0x0c065448 */
if(!s->budget--) { s->failed_pc=0x0c065448u; return 0; }
r[3]<<=8;
goto P_0c06544a;
P_0c06544a: /* original 6143, guest PC 0x0c06544a */
if(!s->budget--) { s->failed_pc=0x0c06544au; return 0; }
r[1]=r[4];
goto P_0c06544c;
P_0c06544c: /* original 4128, guest PC 0x0c06544c */
if(!s->budget--) { s->failed_pc=0x0c06544cu; return 0; }
r[1]<<=16;
goto P_0c06544e;
P_0c06544e: /* original 231b, guest PC 0x0c06544e */
if(!s->budget--) { s->failed_pc=0x0c06544eu; return 0; }
r[3]|=r[1];
goto P_0c065450;
P_0c065450: /* original 6143, guest PC 0x0c065450 */
if(!s->budget--) { s->failed_pc=0x0c065450u; return 0; }
r[1]=r[4];
goto P_0c065452;
P_0c065452: /* original 4118, guest PC 0x0c065452 */
if(!s->budget--) { s->failed_pc=0x0c065452u; return 0; }
r[1]<<=8;
goto P_0c065454;
P_0c065454: /* original 231b, guest PC 0x0c065454 */
if(!s->budget--) { s->failed_pc=0x0c065454u; return 0; }
r[3]|=r[1];
goto P_0c065456;
P_0c065456: /* original 234b, guest PC 0x0c065456 */
if(!s->budget--) { s->failed_pc=0x0c065456u; return 0; }
r[3]|=r[4];
goto P_0c065458;
P_0c065458: /* original 0236, guest PC 0x0c065458 */
if(!s->budget--) { s->failed_pc=0x0c065458u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06545a;
P_0c06545a: /* original 62c3, guest PC 0x0c06545a */
if(!s->budget--) { s->failed_pc=0x0c06545au; return 0; }
r[2]=r[12];
goto P_0c06545c;
P_0c06545c: /* original 61b2, guest PC 0x0c06545c */
if(!s->budget--) { s->failed_pc=0x0c06545cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c06545e;
P_0c06545e: /* original 7c01, guest PC 0x0c06545e */
if(!s->budget--) { s->failed_pc=0x0c06545eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065460;
P_0c065460: /* original 5311, guest PC 0x0c065460 */
if(!s->budget--) { s->failed_pc=0x0c065460u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065462;
P_0c065462: /* original 4208, guest PC 0x0c065462 */
if(!s->budget--) { s->failed_pc=0x0c065462u; return 0; }
r[2]<<=2;
goto P_0c065464;
P_0c065464: /* original 0236, guest PC 0x0c065464 */
if(!s->budget--) { s->failed_pc=0x0c065464u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065466;
P_0c065466: /* original 62c3, guest PC 0x0c065466 */
if(!s->budget--) { s->failed_pc=0x0c065466u; return 0; }
r[2]=r[12];
goto P_0c065468;
P_0c065468: /* original 7c01, guest PC 0x0c065468 */
if(!s->budget--) { s->failed_pc=0x0c065468u; return 0; }
r[12]+=0x00000001u;
goto P_0c06546a;
P_0c06546a: /* original 4208, guest PC 0x0c06546a */
if(!s->budget--) { s->failed_pc=0x0c06546au; return 0; }
r[2]<<=2;
goto P_0c06546c;
P_0c06546c: /* original 61b2, guest PC 0x0c06546c */
if(!s->budget--) { s->failed_pc=0x0c06546cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c06546e;
P_0c06546e: /* original 5312, guest PC 0x0c06546e */
if(!s->budget--) { s->failed_pc=0x0c06546eu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065470;
P_0c065470: /* original 0236, guest PC 0x0c065470 */
if(!s->budget--) { s->failed_pc=0x0c065470u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065472;
P_0c065472: /* original 62c3, guest PC 0x0c065472 */
if(!s->budget--) { s->failed_pc=0x0c065472u; return 0; }
r[2]=r[12];
goto P_0c065474;
P_0c065474: /* original 61b2, guest PC 0x0c065474 */
if(!s->budget--) { s->failed_pc=0x0c065474u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065476;
P_0c065476: /* original 7c01, guest PC 0x0c065476 */
if(!s->budget--) { s->failed_pc=0x0c065476u; return 0; }
r[12]+=0x00000001u;
goto P_0c065478;
P_0c065478: /* original 5313, guest PC 0x0c065478 */
if(!s->budget--) { s->failed_pc=0x0c065478u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c06547a;
P_0c06547a: /* original 4208, guest PC 0x0c06547a */
if(!s->budget--) { s->failed_pc=0x0c06547au; return 0; }
r[2]<<=2;
goto P_0c06547c;
P_0c06547c: /* original 0236, guest PC 0x0c06547c */
if(!s->budget--) { s->failed_pc=0x0c06547cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06547e;
P_0c06547e: /* original 65c3, guest PC 0x0c06547e */
if(!s->budget--) { s->failed_pc=0x0c06547eu; return 0; }
r[5]=r[12];
goto P_0c065480;
P_0c065480: /* original 67b2, guest PC 0x0c065480 */
if(!s->budget--) { s->failed_pc=0x0c065480u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c065482;
P_0c065482: /* original 2f72, guest PC 0x0c065482 */
if(!s->budget--) { s->failed_pc=0x0c065482u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065484;
P_0c065484: /* original 5775, guest PC 0x0c065484 */
if(!s->budget--) { s->failed_pc=0x0c065484u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065486;
P_0c065486: /* original 66f2, guest PC 0x0c065486 */
if(!s->budget--) { s->failed_pc=0x0c065486u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065488;
P_0c065488: /* original 5664, guest PC 0x0c065488 */
if(!s->budget--) { s->failed_pc=0x0c065488u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c06548a;
P_0c06548a: /* original b875, guest PC 0x0c06548a */
if(!s->budget--) { s->failed_pc=0x0c06548au; return 0; }
target=0x0c064578u; r[16]=0x0c06548eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06548eu) { target=s->pc; goto dispatch; }
goto P_0c06548e;
P_0c06548c: /* original 64d3, guest PC 0x0c06548c */
if(!s->budget--) { s->failed_pc=0x0c06548cu; return 0; }
r[4]=r[13];
goto P_0c06548e;
P_0c06548e: /* original 6c03, guest PC 0x0c06548e */
if(!s->budget--) { s->failed_pc=0x0c06548eu; return 0; }
r[12]=r[0];
goto P_0c065490;
P_0c065490: /* original 64b2, guest PC 0x0c065490 */
if(!s->budget--) { s->failed_pc=0x0c065490u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c065492;
P_0c065492: /* original e118, guest PC 0x0c065492 */
if(!s->budget--) { s->failed_pc=0x0c065492u; return 0; }
r[1]=0x00000018u;
goto P_0c065494;
P_0c065494: /* original d047, guest PC 0x0c065494 */
if(!s->budget--) { s->failed_pc=0x0c065494u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c065496;
P_0c065496: /* original 62c3, guest PC 0x0c065496 */
if(!s->budget--) { s->failed_pc=0x0c065496u; return 0; }
r[2]=r[12];
goto P_0c065498;
P_0c065498: /* original 7c01, guest PC 0x0c065498 */
if(!s->budget--) { s->failed_pc=0x0c065498u; return 0; }
r[12]+=0x00000001u;
goto P_0c06549a;
P_0c06549a: /* original 4208, guest PC 0x0c06549a */
if(!s->budget--) { s->failed_pc=0x0c06549au; return 0; }
r[2]<<=2;
goto P_0c06549c;
P_0c06549c: /* original 314c, guest PC 0x0c06549c */
if(!s->budget--) { s->failed_pc=0x0c06549cu; return 0; }
r[1]+=r[4];
goto P_0c06549e;
P_0c06549e: /* original f318, guest PC 0x0c06549e */
if(!s->budget--) { s->failed_pc=0x0c06549eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0654a0;
P_0c0654a0: /* original f3f2, guest PC 0x0c0654a0 */
if(!s->budget--) { s->failed_pc=0x0c0654a0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0654a2;
P_0c0654a2: /* original f33d, guest PC 0x0c0654a2 */
if(!s->budget--) { s->failed_pc=0x0c0654a2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0654a4;
P_0c0654a4: /* original 045a, guest PC 0x0c0654a4 */
if(!s->budget--) { s->failed_pc=0x0c0654a4u; return 0; }
r[4]=r[53];
goto P_0c0654a6;
P_0c0654a6: /* original 6343, guest PC 0x0c0654a6 */
if(!s->budget--) { s->failed_pc=0x0c0654a6u; return 0; }
r[3]=r[4];
goto P_0c0654a8;
P_0c0654a8: /* original 4328, guest PC 0x0c0654a8 */
if(!s->budget--) { s->failed_pc=0x0c0654a8u; return 0; }
r[3]<<=16;
goto P_0c0654aa;
P_0c0654aa: /* original 4318, guest PC 0x0c0654aa */
if(!s->budget--) { s->failed_pc=0x0c0654aau; return 0; }
r[3]<<=8;
goto P_0c0654ac;
P_0c0654ac: /* original 6143, guest PC 0x0c0654ac */
if(!s->budget--) { s->failed_pc=0x0c0654acu; return 0; }
r[1]=r[4];
goto P_0c0654ae;
P_0c0654ae: /* original 4128, guest PC 0x0c0654ae */
if(!s->budget--) { s->failed_pc=0x0c0654aeu; return 0; }
r[1]<<=16;
goto P_0c0654b0;
P_0c0654b0: /* original 231b, guest PC 0x0c0654b0 */
if(!s->budget--) { s->failed_pc=0x0c0654b0u; return 0; }
r[3]|=r[1];
goto P_0c0654b2;
P_0c0654b2: /* original 6143, guest PC 0x0c0654b2 */
if(!s->budget--) { s->failed_pc=0x0c0654b2u; return 0; }
r[1]=r[4];
goto P_0c0654b4;
P_0c0654b4: /* original 4118, guest PC 0x0c0654b4 */
if(!s->budget--) { s->failed_pc=0x0c0654b4u; return 0; }
r[1]<<=8;
goto P_0c0654b6;
P_0c0654b6: /* original 231b, guest PC 0x0c0654b6 */
if(!s->budget--) { s->failed_pc=0x0c0654b6u; return 0; }
r[3]|=r[1];
goto P_0c0654b8;
P_0c0654b8: /* original 234b, guest PC 0x0c0654b8 */
if(!s->budget--) { s->failed_pc=0x0c0654b8u; return 0; }
r[3]|=r[4];
goto P_0c0654ba;
P_0c0654ba: /* original 0236, guest PC 0x0c0654ba */
if(!s->budget--) { s->failed_pc=0x0c0654bau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0654bc;
P_0c0654bc: /* original 69b2, guest PC 0x0c0654bc */
if(!s->budget--) { s->failed_pc=0x0c0654bcu; return 0; }
tmp=read(ram,r[11],4);
r[9]=tmp;
goto P_0c0654be;
P_0c0654be: /* original e01c, guest PC 0x0c0654be */
if(!s->budget--) { s->failed_pc=0x0c0654beu; return 0; }
r[0]=0x0000001cu;
goto P_0c0654c0;
P_0c0654c0: /* original f396, guest PC 0x0c0654c0 */
if(!s->budget--) { s->failed_pc=0x0c0654c0u; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c0654c2;
P_0c0654c2: /* original f3f2, guest PC 0x0c0654c2 */
if(!s->budget--) { s->failed_pc=0x0c0654c2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0654c4;
P_0c0654c4: /* original f33d, guest PC 0x0c0654c4 */
if(!s->budget--) { s->failed_pc=0x0c0654c4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0654c6;
P_0c0654c6: /* original 095a, guest PC 0x0c0654c6 */
if(!s->budget--) { s->failed_pc=0x0c0654c6u; return 0; }
r[9]=r[53];
goto P_0c0654c8;
P_0c0654c8: /* original 6693, guest PC 0x0c0654c8 */
if(!s->budget--) { s->failed_pc=0x0c0654c8u; return 0; }
r[6]=r[9];
goto P_0c0654ca;
P_0c0654ca: /* original 4628, guest PC 0x0c0654ca */
if(!s->budget--) { s->failed_pc=0x0c0654cau; return 0; }
r[6]<<=16;
goto P_0c0654cc;
P_0c0654cc: /* original 4618, guest PC 0x0c0654cc */
if(!s->budget--) { s->failed_pc=0x0c0654ccu; return 0; }
r[6]<<=8;
goto P_0c0654ce;
P_0c0654ce: /* original 6393, guest PC 0x0c0654ce */
if(!s->budget--) { s->failed_pc=0x0c0654ceu; return 0; }
r[3]=r[9];
goto P_0c0654d0;
P_0c0654d0: /* original 4328, guest PC 0x0c0654d0 */
if(!s->budget--) { s->failed_pc=0x0c0654d0u; return 0; }
r[3]<<=16;
goto P_0c0654d2;
P_0c0654d2: /* original 263b, guest PC 0x0c0654d2 */
if(!s->budget--) { s->failed_pc=0x0c0654d2u; return 0; }
r[6]|=r[3];
goto P_0c0654d4;
P_0c0654d4: /* original 6293, guest PC 0x0c0654d4 */
if(!s->budget--) { s->failed_pc=0x0c0654d4u; return 0; }
r[2]=r[9];
goto P_0c0654d6;
P_0c0654d6: /* original 4218, guest PC 0x0c0654d6 */
if(!s->budget--) { s->failed_pc=0x0c0654d6u; return 0; }
r[2]<<=8;
goto P_0c0654d8;
P_0c0654d8: /* original 262b, guest PC 0x0c0654d8 */
if(!s->budget--) { s->failed_pc=0x0c0654d8u; return 0; }
r[6]|=r[2];
goto P_0c0654da;
P_0c0654da: /* original 269b, guest PC 0x0c0654da */
if(!s->budget--) { s->failed_pc=0x0c0654dau; return 0; }
r[6]|=r[9];
goto P_0c0654dc;
P_0c0654dc: /* original 65c3, guest PC 0x0c0654dc */
if(!s->budget--) { s->failed_pc=0x0c0654dcu; return 0; }
r[5]=r[12];
goto P_0c0654de;
P_0c0654de: /* original b827, guest PC 0x0c0654de */
if(!s->budget--) { s->failed_pc=0x0c0654deu; return 0; }
target=0x0c064530u; r[16]=0x0c0654e2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0654e2u) { target=s->pc; goto dispatch; }
goto P_0c0654e2;
P_0c0654e0: /* original 64d3, guest PC 0x0c0654e0 */
if(!s->budget--) { s->failed_pc=0x0c0654e0u; return 0; }
r[4]=r[13];
goto P_0c0654e2;
P_0c0654e2: /* original 6c03, guest PC 0x0c0654e2 */
if(!s->budget--) { s->failed_pc=0x0c0654e2u; return 0; }
r[12]=r[0];
goto P_0c0654e4;
P_0c0654e4: /* original 61a2, guest PC 0x0c0654e4 */
if(!s->budget--) { s->failed_pc=0x0c0654e4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0654e6;
P_0c0654e6: /* original 62c3, guest PC 0x0c0654e6 */
if(!s->budget--) { s->failed_pc=0x0c0654e6u; return 0; }
r[2]=r[12];
goto P_0c0654e8;
P_0c0654e8: /* original d032, guest PC 0x0c0654e8 */
if(!s->budget--) { s->failed_pc=0x0c0654e8u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c0654ea;
P_0c0654ea: /* original 7c01, guest PC 0x0c0654ea */
if(!s->budget--) { s->failed_pc=0x0c0654eau; return 0; }
r[12]+=0x00000001u;
goto P_0c0654ec;
P_0c0654ec: /* original 5311, guest PC 0x0c0654ec */
if(!s->budget--) { s->failed_pc=0x0c0654ecu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0654ee;
P_0c0654ee: /* original 4208, guest PC 0x0c0654ee */
if(!s->budget--) { s->failed_pc=0x0c0654eeu; return 0; }
r[2]<<=2;
goto P_0c0654f0;
P_0c0654f0: /* original 0236, guest PC 0x0c0654f0 */
if(!s->budget--) { s->failed_pc=0x0c0654f0u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0654f2;
P_0c0654f2: /* original 62c3, guest PC 0x0c0654f2 */
if(!s->budget--) { s->failed_pc=0x0c0654f2u; return 0; }
r[2]=r[12];
goto P_0c0654f4;
P_0c0654f4: /* original 61a2, guest PC 0x0c0654f4 */
if(!s->budget--) { s->failed_pc=0x0c0654f4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0654f6;
P_0c0654f6: /* original 7c01, guest PC 0x0c0654f6 */
if(!s->budget--) { s->failed_pc=0x0c0654f6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0654f8;
P_0c0654f8: /* original 5312, guest PC 0x0c0654f8 */
if(!s->budget--) { s->failed_pc=0x0c0654f8u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0654fa;
P_0c0654fa: /* original 4208, guest PC 0x0c0654fa */
if(!s->budget--) { s->failed_pc=0x0c0654fau; return 0; }
r[2]<<=2;
goto P_0c0654fc;
P_0c0654fc: /* original 0236, guest PC 0x0c0654fc */
if(!s->budget--) { s->failed_pc=0x0c0654fcu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0654fe;
P_0c0654fe: /* original 62c3, guest PC 0x0c0654fe */
if(!s->budget--) { s->failed_pc=0x0c0654feu; return 0; }
r[2]=r[12];
goto P_0c065500;
P_0c065500: /* original 61a2, guest PC 0x0c065500 */
if(!s->budget--) { s->failed_pc=0x0c065500u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065502;
P_0c065502: /* original 7c01, guest PC 0x0c065502 */
if(!s->budget--) { s->failed_pc=0x0c065502u; return 0; }
r[12]+=0x00000001u;
goto P_0c065504;
P_0c065504: /* original 5313, guest PC 0x0c065504 */
if(!s->budget--) { s->failed_pc=0x0c065504u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065506;
P_0c065506: /* original 4208, guest PC 0x0c065506 */
if(!s->budget--) { s->failed_pc=0x0c065506u; return 0; }
r[2]<<=2;
goto P_0c065508;
P_0c065508: /* original 0236, guest PC 0x0c065508 */
if(!s->budget--) { s->failed_pc=0x0c065508u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06550a;
P_0c06550a: /* original 65c3, guest PC 0x0c06550a */
if(!s->budget--) { s->failed_pc=0x0c06550au; return 0; }
r[5]=r[12];
goto P_0c06550c;
P_0c06550c: /* original 67a2, guest PC 0x0c06550c */
if(!s->budget--) { s->failed_pc=0x0c06550cu; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c06550e;
P_0c06550e: /* original 2f72, guest PC 0x0c06550e */
if(!s->budget--) { s->failed_pc=0x0c06550eu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065510;
P_0c065510: /* original 5775, guest PC 0x0c065510 */
if(!s->budget--) { s->failed_pc=0x0c065510u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065512;
P_0c065512: /* original 66f2, guest PC 0x0c065512 */
if(!s->budget--) { s->failed_pc=0x0c065512u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065514;
P_0c065514: /* original 5664, guest PC 0x0c065514 */
if(!s->budget--) { s->failed_pc=0x0c065514u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065516;
P_0c065516: /* original b82f, guest PC 0x0c065516 */
if(!s->budget--) { s->failed_pc=0x0c065516u; return 0; }
target=0x0c064578u; r[16]=0x0c06551au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06551au) { target=s->pc; goto dispatch; }
goto P_0c06551a;
P_0c065518: /* original 64d3, guest PC 0x0c065518 */
if(!s->budget--) { s->failed_pc=0x0c065518u; return 0; }
r[4]=r[13];
goto P_0c06551a;
P_0c06551a: /* original 6c03, guest PC 0x0c06551a */
if(!s->budget--) { s->failed_pc=0x0c06551au; return 0; }
r[12]=r[0];
goto P_0c06551c;
P_0c06551c: /* original 64a2, guest PC 0x0c06551c */
if(!s->budget--) { s->failed_pc=0x0c06551cu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c06551e;
P_0c06551e: /* original e118, guest PC 0x0c06551e */
if(!s->budget--) { s->failed_pc=0x0c06551eu; return 0; }
r[1]=0x00000018u;
goto P_0c065520;
P_0c065520: /* original d024, guest PC 0x0c065520 */
if(!s->budget--) { s->failed_pc=0x0c065520u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c065522;
P_0c065522: /* original 62c3, guest PC 0x0c065522 */
if(!s->budget--) { s->failed_pc=0x0c065522u; return 0; }
r[2]=r[12];
goto P_0c065524;
P_0c065524: /* original 7c01, guest PC 0x0c065524 */
if(!s->budget--) { s->failed_pc=0x0c065524u; return 0; }
r[12]+=0x00000001u;
goto P_0c065526;
P_0c065526: /* original 4208, guest PC 0x0c065526 */
if(!s->budget--) { s->failed_pc=0x0c065526u; return 0; }
r[2]<<=2;
goto P_0c065528;
P_0c065528: /* original 314c, guest PC 0x0c065528 */
if(!s->budget--) { s->failed_pc=0x0c065528u; return 0; }
r[1]+=r[4];
goto P_0c06552a;
P_0c06552a: /* original f318, guest PC 0x0c06552a */
if(!s->budget--) { s->failed_pc=0x0c06552au; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06552c;
P_0c06552c: /* original f3f2, guest PC 0x0c06552c */
if(!s->budget--) { s->failed_pc=0x0c06552cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06552e;
P_0c06552e: /* original f33d, guest PC 0x0c06552e */
if(!s->budget--) { s->failed_pc=0x0c06552eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065530;
P_0c065530: /* original 045a, guest PC 0x0c065530 */
if(!s->budget--) { s->failed_pc=0x0c065530u; return 0; }
r[4]=r[53];
goto P_0c065532;
P_0c065532: /* original 6343, guest PC 0x0c065532 */
if(!s->budget--) { s->failed_pc=0x0c065532u; return 0; }
r[3]=r[4];
goto P_0c065534;
P_0c065534: /* original 4328, guest PC 0x0c065534 */
if(!s->budget--) { s->failed_pc=0x0c065534u; return 0; }
r[3]<<=16;
goto P_0c065536;
P_0c065536: /* original 4318, guest PC 0x0c065536 */
if(!s->budget--) { s->failed_pc=0x0c065536u; return 0; }
r[3]<<=8;
goto P_0c065538;
P_0c065538: /* original 6143, guest PC 0x0c065538 */
if(!s->budget--) { s->failed_pc=0x0c065538u; return 0; }
r[1]=r[4];
goto P_0c06553a;
P_0c06553a: /* original 4128, guest PC 0x0c06553a */
if(!s->budget--) { s->failed_pc=0x0c06553au; return 0; }
r[1]<<=16;
goto P_0c06553c;
P_0c06553c: /* original 231b, guest PC 0x0c06553c */
if(!s->budget--) { s->failed_pc=0x0c06553cu; return 0; }
r[3]|=r[1];
goto P_0c06553e;
P_0c06553e: /* original 6143, guest PC 0x0c06553e */
if(!s->budget--) { s->failed_pc=0x0c06553eu; return 0; }
r[1]=r[4];
goto P_0c065540;
P_0c065540: /* original 4118, guest PC 0x0c065540 */
if(!s->budget--) { s->failed_pc=0x0c065540u; return 0; }
r[1]<<=8;
goto P_0c065542;
P_0c065542: /* original 231b, guest PC 0x0c065542 */
if(!s->budget--) { s->failed_pc=0x0c065542u; return 0; }
r[3]|=r[1];
goto P_0c065544;
P_0c065544: /* original 234b, guest PC 0x0c065544 */
if(!s->budget--) { s->failed_pc=0x0c065544u; return 0; }
r[3]|=r[4];
goto P_0c065546;
P_0c065546: /* original 0236, guest PC 0x0c065546 */
if(!s->budget--) { s->failed_pc=0x0c065546u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065548;
P_0c065548: /* original 6ba2, guest PC 0x0c065548 */
if(!s->budget--) { s->failed_pc=0x0c065548u; return 0; }
tmp=read(ram,r[10],4);
r[11]=tmp;
goto P_0c06554a;
P_0c06554a: /* original e01c, guest PC 0x0c06554a */
if(!s->budget--) { s->failed_pc=0x0c06554au; return 0; }
r[0]=0x0000001cu;
goto P_0c06554c;
P_0c06554c: /* original f3b6, guest PC 0x0c06554c */
if(!s->budget--) { s->failed_pc=0x0c06554cu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c06554e;
P_0c06554e: /* original f3f2, guest PC 0x0c06554e */
if(!s->budget--) { s->failed_pc=0x0c06554eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065550;
P_0c065550: /* original f33d, guest PC 0x0c065550 */
if(!s->budget--) { s->failed_pc=0x0c065550u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065552;
P_0c065552: /* original 0b5a, guest PC 0x0c065552 */
if(!s->budget--) { s->failed_pc=0x0c065552u; return 0; }
r[11]=r[53];
goto P_0c065554;
P_0c065554: /* original 66b3, guest PC 0x0c065554 */
if(!s->budget--) { s->failed_pc=0x0c065554u; return 0; }
r[6]=r[11];
goto P_0c065556;
P_0c065556: /* original 4628, guest PC 0x0c065556 */
if(!s->budget--) { s->failed_pc=0x0c065556u; return 0; }
r[6]<<=16;
goto P_0c065558;
P_0c065558: /* original 4618, guest PC 0x0c065558 */
if(!s->budget--) { s->failed_pc=0x0c065558u; return 0; }
r[6]<<=8;
goto P_0c06555a;
P_0c06555a: /* original 63b3, guest PC 0x0c06555a */
if(!s->budget--) { s->failed_pc=0x0c06555au; return 0; }
r[3]=r[11];
goto P_0c06555c;
P_0c06555c: /* original 4328, guest PC 0x0c06555c */
if(!s->budget--) { s->failed_pc=0x0c06555cu; return 0; }
r[3]<<=16;
goto P_0c06555e;
P_0c06555e: /* original 263b, guest PC 0x0c06555e */
if(!s->budget--) { s->failed_pc=0x0c06555eu; return 0; }
r[6]|=r[3];
goto P_0c065560;
P_0c065560: /* original d316, guest PC 0x0c065560 */
if(!s->budget--) { s->failed_pc=0x0c065560u; return 0; }
r[3]=read(ram,0x0c0655bcu,4);
goto P_0c065562;
P_0c065562: /* original 62b3, guest PC 0x0c065562 */
if(!s->budget--) { s->failed_pc=0x0c065562u; return 0; }
r[2]=r[11];
goto P_0c065564;
P_0c065564: /* original 4218, guest PC 0x0c065564 */
if(!s->budget--) { s->failed_pc=0x0c065564u; return 0; }
r[2]<<=8;
goto P_0c065566;
P_0c065566: /* original 262b, guest PC 0x0c065566 */
if(!s->budget--) { s->failed_pc=0x0c065566u; return 0; }
r[6]|=r[2];
goto P_0c065568;
P_0c065568: /* original 26bb, guest PC 0x0c065568 */
if(!s->budget--) { s->failed_pc=0x0c065568u; return 0; }
r[6]|=r[11];
goto P_0c06556a;
P_0c06556a: /* original 65c3, guest PC 0x0c06556a */
if(!s->budget--) { s->failed_pc=0x0c06556au; return 0; }
r[5]=r[12];
goto P_0c06556c;
P_0c06556c: /* original 430b, guest PC 0x0c06556c */
if(!s->budget--) { s->failed_pc=0x0c06556cu; return 0; }
target=r[3];
r[16]=0x0c065570u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065570u) { target=s->pc; goto dispatch; }
goto P_0c065570;
P_0c06556e: /* original 64d3, guest PC 0x0c06556e */
if(!s->budget--) { s->failed_pc=0x0c06556eu; return 0; }
r[4]=r[13];
goto P_0c065570;
P_0c065570: /* original d213, guest PC 0x0c065570 */
if(!s->budget--) { s->failed_pc=0x0c065570u; return 0; }
r[2]=read(ram,0x0c0655c0u,4);
goto P_0c065572;
P_0c065572: /* original 6403, guest PC 0x0c065572 */
if(!s->budget--) { s->failed_pc=0x0c065572u; return 0; }
r[4]=r[0];
goto P_0c065574;
P_0c065574: /* original 4408, guest PC 0x0c065574 */
if(!s->budget--) { s->failed_pc=0x0c065574u; return 0; }
r[4]<<=2;
goto P_0c065576;
P_0c065576: /* original 2242, guest PC 0x0c065576 */
if(!s->budget--) { s->failed_pc=0x0c065576u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c065578;
P_0c065578: /* original d312, guest PC 0x0c065578 */
if(!s->budget--) { s->failed_pc=0x0c065578u; return 0; }
r[3]=read(ram,0x0c0655c4u,4);
goto P_0c06557a;
P_0c06557a: /* original 430b, guest PC 0x0c06557a */
if(!s->budget--) { s->failed_pc=0x0c06557au; return 0; }
target=r[3];
r[16]=0x0c06557eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06557eu) { target=s->pc; goto dispatch; }
goto P_0c06557e;
P_0c06557c: /* original 64d3, guest PC 0x0c06557c */
if(!s->budget--) { s->failed_pc=0x0c06557cu; return 0; }
r[4]=r[13];
goto P_0c06557e;
P_0c06557e: /* original 6403, guest PC 0x0c06557e */
if(!s->budget--) { s->failed_pc=0x0c06557eu; return 0; }
r[4]=r[0];
goto P_0c065580;
P_0c065580: /* original d211, guest PC 0x0c065580 */
if(!s->budget--) { s->failed_pc=0x0c065580u; return 0; }
r[2]=read(ram,0x0c0655c8u,4);
goto P_0c065582;
P_0c065582: /* original e500, guest PC 0x0c065582 */
if(!s->budget--) { s->failed_pc=0x0c065582u; return 0; }
r[5]=0x00000000u;
goto P_0c065584;
P_0c065584: /* original 420b, guest PC 0x0c065584 */
if(!s->budget--) { s->failed_pc=0x0c065584u; return 0; }
target=r[2];
r[16]=0x0c065588u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065588u) { target=s->pc; goto dispatch; }
goto P_0c065588;
P_0c065586: /* original 6653, guest PC 0x0c065586 */
if(!s->budget--) { s->failed_pc=0x0c065586u; return 0; }
r[6]=r[5];
goto P_0c065588;
P_0c065588: /* original 62e2, guest PC 0x0c065588 */
if(!s->budget--) { s->failed_pc=0x0c065588u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c06558a;
P_0c06558a: /* original 5323, guest PC 0x0c06558a */
if(!s->budget--) { s->failed_pc=0x0c06558au; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c06558c;
P_0c06558c: /* original d10f, guest PC 0x0c06558c */
if(!s->budget--) { s->failed_pc=0x0c06558cu; return 0; }
r[1]=read(ram,0x0c0655ccu,4);
goto P_0c06558e;
P_0c06558e: /* original 2132, guest PC 0x0c06558e */
if(!s->budget--) { s->failed_pc=0x0c06558eu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c065590;
P_0c065590: /* original e000, guest PC 0x0c065590 */
if(!s->budget--) { s->failed_pc=0x0c065590u; return 0; }
r[0]=0x00000000u;
goto P_0c065592;
P_0c065592: /* original 7f10, guest PC 0x0c065592 */
if(!s->budget--) { s->failed_pc=0x0c065592u; return 0; }
r[15]+=0x00000010u;
goto P_0c065594;
P_0c065594: /* original 4f26, guest PC 0x0c065594 */
if(!s->budget--) { s->failed_pc=0x0c065594u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065596;
P_0c065596: /* original fff9, guest PC 0x0c065596 */
if(!s->budget--) { s->failed_pc=0x0c065596u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c065598;
P_0c065598: /* original 69f6, guest PC 0x0c065598 */
if(!s->budget--) { s->failed_pc=0x0c065598u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06559a;
P_0c06559a: /* original 6af6, guest PC 0x0c06559a */
if(!s->budget--) { s->failed_pc=0x0c06559au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06559c;
P_0c06559c: /* original 6bf6, guest PC 0x0c06559c */
if(!s->budget--) { s->failed_pc=0x0c06559cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06559e;
P_0c06559e: /* original 6cf6, guest PC 0x0c06559e */
if(!s->budget--) { s->failed_pc=0x0c06559eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0655a0;
P_0c0655a0: /* original 6df6, guest PC 0x0c0655a0 */
if(!s->budget--) { s->failed_pc=0x0c0655a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0655a2;
P_0c0655a2: /* original 000b, guest PC 0x0c0655a2 */
if(!s->budget--) { s->failed_pc=0x0c0655a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0655a4: /* original 6ef6, guest PC 0x0c0655a4 */
if(!s->budget--) { s->failed_pc=0x0c0655a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0655a6u,s,ram);
P_0c0655e0: /* original 4f22, guest PC 0x0c0655e0 */
if(!s->budget--) { s->failed_pc=0x0c0655e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0655e2;
P_0c0655e2: /* original 7ff4, guest PC 0x0c0655e2 */
if(!s->budget--) { s->failed_pc=0x0c0655e2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0655e4;
P_0c0655e4: /* original 6342, guest PC 0x0c0655e4 */
if(!s->budget--) { s->failed_pc=0x0c0655e4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0655e6;
P_0c0655e6: /* original 65f3, guest PC 0x0c0655e6 */
if(!s->budget--) { s->failed_pc=0x0c0655e6u; return 0; }
r[5]=r[15];
goto P_0c0655e8;
P_0c0655e8: /* original 6e53, guest PC 0x0c0655e8 */
if(!s->budget--) { s->failed_pc=0x0c0655e8u; return 0; }
r[14]=r[5];
goto P_0c0655ea;
P_0c0655ea: /* original 6be3, guest PC 0x0c0655ea */
if(!s->budget--) { s->failed_pc=0x0c0655eau; return 0; }
r[11]=r[14];
goto P_0c0655ec;
P_0c0655ec: /* original 2e32, guest PC 0x0c0655ec */
if(!s->budget--) { s->failed_pc=0x0c0655ecu; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0655ee;
P_0c0655ee: /* original 6ae3, guest PC 0x0c0655ee */
if(!s->budget--) { s->failed_pc=0x0c0655eeu; return 0; }
r[10]=r[14];
goto P_0c0655f0;
P_0c0655f0: /* original 5241, guest PC 0x0c0655f0 */
if(!s->budget--) { s->failed_pc=0x0c0655f0u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0655f2;
P_0c0655f2: /* original 7b04, guest PC 0x0c0655f2 */
if(!s->budget--) { s->failed_pc=0x0c0655f2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0655f4;
P_0c0655f4: /* original 2b22, guest PC 0x0c0655f4 */
if(!s->budget--) { s->failed_pc=0x0c0655f4u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c0655f6;
P_0c0655f6: /* original 7a08, guest PC 0x0c0655f6 */
if(!s->budget--) { s->failed_pc=0x0c0655f6u; return 0; }
r[10]+=0x00000008u;
goto P_0c0655f8;
P_0c0655f8: /* original 5342, guest PC 0x0c0655f8 */
if(!s->budget--) { s->failed_pc=0x0c0655f8u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0655fa;
P_0c0655fa: /* original 2a32, guest PC 0x0c0655fa */
if(!s->budget--) { s->failed_pc=0x0c0655fau; return 0; }
write(ram,r[10],r[3],4);
goto P_0c0655fc;
P_0c0655fc: /* original d2c0, guest PC 0x0c0655fc */
if(!s->budget--) { s->failed_pc=0x0c0655fcu; return 0; }
r[2]=read(ram,0x0c065900u,4);
goto P_0c0655fe;
P_0c0655fe: /* original 6d22, guest PC 0x0c0655fe */
if(!s->budget--) { s->failed_pc=0x0c0655feu; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c065600;
P_0c065600: /* original d3c0, guest PC 0x0c065600 */
if(!s->budget--) { s->failed_pc=0x0c065600u; return 0; }
r[3]=read(ram,0x0c065904u,4);
goto P_0c065602;
P_0c065602: /* original 6532, guest PC 0x0c065602 */
if(!s->budget--) { s->failed_pc=0x0c065602u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c065604;
P_0c065604: /* original d1c0, guest PC 0x0c065604 */
if(!s->budget--) { s->failed_pc=0x0c065604u; return 0; }
r[1]=read(ram,0x0c065908u,4);
goto P_0c065606;
P_0c065606: /* original 6412, guest PC 0x0c065606 */
if(!s->budget--) { s->failed_pc=0x0c065606u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c065608;
P_0c065608: /* original d0c0, guest PC 0x0c065608 */
if(!s->budget--) { s->failed_pc=0x0c065608u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c06560a;
P_0c06560a: /* original 62c3, guest PC 0x0c06560a */
if(!s->budget--) { s->failed_pc=0x0c06560au; return 0; }
r[2]=r[12];
goto P_0c06560c;
P_0c06560c: /* original 7c01, guest PC 0x0c06560c */
if(!s->budget--) { s->failed_pc=0x0c06560cu; return 0; }
r[12]+=0x00000001u;
goto P_0c06560e;
P_0c06560e: /* original 4208, guest PC 0x0c06560e */
if(!s->budget--) { s->failed_pc=0x0c06560eu; return 0; }
r[2]<<=2;
goto P_0c065610;
P_0c065610: /* original 02d6, guest PC 0x0c065610 */
if(!s->budget--) { s->failed_pc=0x0c065610u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065612;
P_0c065612: /* original 63c3, guest PC 0x0c065612 */
if(!s->budget--) { s->failed_pc=0x0c065612u; return 0; }
r[3]=r[12];
goto P_0c065614;
P_0c065614: /* original 7c01, guest PC 0x0c065614 */
if(!s->budget--) { s->failed_pc=0x0c065614u; return 0; }
r[12]+=0x00000001u;
goto P_0c065616;
P_0c065616: /* original 4308, guest PC 0x0c065616 */
if(!s->budget--) { s->failed_pc=0x0c065616u; return 0; }
r[3]<<=2;
goto P_0c065618;
P_0c065618: /* original 0356, guest PC 0x0c065618 */
if(!s->budget--) { s->failed_pc=0x0c065618u; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c06561a;
P_0c06561a: /* original 62c3, guest PC 0x0c06561a */
if(!s->budget--) { s->failed_pc=0x0c06561au; return 0; }
r[2]=r[12];
goto P_0c06561c;
P_0c06561c: /* original 7c01, guest PC 0x0c06561c */
if(!s->budget--) { s->failed_pc=0x0c06561cu; return 0; }
r[12]+=0x00000001u;
goto P_0c06561e;
P_0c06561e: /* original 4208, guest PC 0x0c06561e */
if(!s->budget--) { s->failed_pc=0x0c06561eu; return 0; }
r[2]<<=2;
goto P_0c065620;
P_0c065620: /* original 0246, guest PC 0x0c065620 */
if(!s->budget--) { s->failed_pc=0x0c065620u; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c065622;
P_0c065622: /* original 63c3, guest PC 0x0c065622 */
if(!s->budget--) { s->failed_pc=0x0c065622u; return 0; }
r[3]=r[12];
goto P_0c065624;
P_0c065624: /* original 62e2, guest PC 0x0c065624 */
if(!s->budget--) { s->failed_pc=0x0c065624u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065626;
P_0c065626: /* original 7c01, guest PC 0x0c065626 */
if(!s->budget--) { s->failed_pc=0x0c065626u; return 0; }
r[12]+=0x00000001u;
goto P_0c065628;
P_0c065628: /* original 5221, guest PC 0x0c065628 */
if(!s->budget--) { s->failed_pc=0x0c065628u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c06562a;
P_0c06562a: /* original 4308, guest PC 0x0c06562a */
if(!s->budget--) { s->failed_pc=0x0c06562au; return 0; }
r[3]<<=2;
goto P_0c06562c;
P_0c06562c: /* original 0326, guest PC 0x0c06562c */
if(!s->budget--) { s->failed_pc=0x0c06562cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06562e;
P_0c06562e: /* original 63c3, guest PC 0x0c06562e */
if(!s->budget--) { s->failed_pc=0x0c06562eu; return 0; }
r[3]=r[12];
goto P_0c065630;
P_0c065630: /* original 62e2, guest PC 0x0c065630 */
if(!s->budget--) { s->failed_pc=0x0c065630u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065632;
P_0c065632: /* original 7c01, guest PC 0x0c065632 */
if(!s->budget--) { s->failed_pc=0x0c065632u; return 0; }
r[12]+=0x00000001u;
goto P_0c065634;
P_0c065634: /* original 5222, guest PC 0x0c065634 */
if(!s->budget--) { s->failed_pc=0x0c065634u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c065636;
P_0c065636: /* original 4308, guest PC 0x0c065636 */
if(!s->budget--) { s->failed_pc=0x0c065636u; return 0; }
r[3]<<=2;
goto P_0c065638;
P_0c065638: /* original 0326, guest PC 0x0c065638 */
if(!s->budget--) { s->failed_pc=0x0c065638u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06563a;
P_0c06563a: /* original 63c3, guest PC 0x0c06563a */
if(!s->budget--) { s->failed_pc=0x0c06563au; return 0; }
r[3]=r[12];
goto P_0c06563c;
P_0c06563c: /* original 62e2, guest PC 0x0c06563c */
if(!s->budget--) { s->failed_pc=0x0c06563cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c06563e;
P_0c06563e: /* original 7c01, guest PC 0x0c06563e */
if(!s->budget--) { s->failed_pc=0x0c06563eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065640;
P_0c065640: /* original 5223, guest PC 0x0c065640 */
if(!s->budget--) { s->failed_pc=0x0c065640u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c065642;
P_0c065642: /* original 4308, guest PC 0x0c065642 */
if(!s->budget--) { s->failed_pc=0x0c065642u; return 0; }
r[3]<<=2;
goto P_0c065644;
P_0c065644: /* original 0326, guest PC 0x0c065644 */
if(!s->budget--) { s->failed_pc=0x0c065644u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065646;
P_0c065646: /* original 65c3, guest PC 0x0c065646 */
if(!s->budget--) { s->failed_pc=0x0c065646u; return 0; }
r[5]=r[12];
goto P_0c065648;
P_0c065648: /* original d3b1, guest PC 0x0c065648 */
if(!s->budget--) { s->failed_pc=0x0c065648u; return 0; }
r[3]=read(ram,0x0c065910u,4);
goto P_0c06564a;
P_0c06564a: /* original 66e2, guest PC 0x0c06564a */
if(!s->budget--) { s->failed_pc=0x0c06564au; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c06564c;
P_0c06564c: /* original 5664, guest PC 0x0c06564c */
if(!s->budget--) { s->failed_pc=0x0c06564cu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c06564e;
P_0c06564e: /* original 430b, guest PC 0x0c06564e */
if(!s->budget--) { s->failed_pc=0x0c06564eu; return 0; }
target=r[3];
r[16]=0x0c065652u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065652u) { target=s->pc; goto dispatch; }
goto P_0c065652;
P_0c065650: /* original 64d3, guest PC 0x0c065650 */
if(!s->budget--) { s->failed_pc=0x0c065650u; return 0; }
r[4]=r[13];
goto P_0c065652;
P_0c065652: /* original 6903, guest PC 0x0c065652 */
if(!s->budget--) { s->failed_pc=0x0c065652u; return 0; }
r[9]=r[0];
goto P_0c065654;
P_0c065654: /* original 64e2, guest PC 0x0c065654 */
if(!s->budget--) { s->failed_pc=0x0c065654u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c065656;
P_0c065656: /* original e118, guest PC 0x0c065656 */
if(!s->budget--) { s->failed_pc=0x0c065656u; return 0; }
r[1]=0x00000018u;
goto P_0c065658;
P_0c065658: /* original c7ae, guest PC 0x0c065658 */
if(!s->budget--) { s->failed_pc=0x0c065658u; return 0; }
r[0]=0x0c065914u;
goto P_0c06565a;
P_0c06565a: /* original 6393, guest PC 0x0c06565a */
if(!s->budget--) { s->failed_pc=0x0c06565au; return 0; }
r[3]=r[9];
goto P_0c06565c;
P_0c06565c: /* original ff08, guest PC 0x0c06565c */
if(!s->budget--) { s->failed_pc=0x0c06565cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06565e;
P_0c06565e: /* original 314c, guest PC 0x0c06565e */
if(!s->budget--) { s->failed_pc=0x0c06565eu; return 0; }
r[1]+=r[4];
goto P_0c065660;
P_0c065660: /* original d0aa, guest PC 0x0c065660 */
if(!s->budget--) { s->failed_pc=0x0c065660u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c065662;
P_0c065662: /* original 7901, guest PC 0x0c065662 */
if(!s->budget--) { s->failed_pc=0x0c065662u; return 0; }
r[9]+=0x00000001u;
goto P_0c065664;
P_0c065664: /* original f318, guest PC 0x0c065664 */
if(!s->budget--) { s->failed_pc=0x0c065664u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065666;
P_0c065666: /* original 4308, guest PC 0x0c065666 */
if(!s->budget--) { s->failed_pc=0x0c065666u; return 0; }
r[3]<<=2;
goto P_0c065668;
P_0c065668: /* original f3f2, guest PC 0x0c065668 */
if(!s->budget--) { s->failed_pc=0x0c065668u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06566a;
P_0c06566a: /* original f33d, guest PC 0x0c06566a */
if(!s->budget--) { s->failed_pc=0x0c06566au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06566c;
P_0c06566c: /* original 045a, guest PC 0x0c06566c */
if(!s->budget--) { s->failed_pc=0x0c06566cu; return 0; }
r[4]=r[53];
goto P_0c06566e;
P_0c06566e: /* original 6243, guest PC 0x0c06566e */
if(!s->budget--) { s->failed_pc=0x0c06566eu; return 0; }
r[2]=r[4];
goto P_0c065670;
P_0c065670: /* original 4228, guest PC 0x0c065670 */
if(!s->budget--) { s->failed_pc=0x0c065670u; return 0; }
r[2]<<=16;
goto P_0c065672;
P_0c065672: /* original 4218, guest PC 0x0c065672 */
if(!s->budget--) { s->failed_pc=0x0c065672u; return 0; }
r[2]<<=8;
goto P_0c065674;
P_0c065674: /* original 6143, guest PC 0x0c065674 */
if(!s->budget--) { s->failed_pc=0x0c065674u; return 0; }
r[1]=r[4];
goto P_0c065676;
P_0c065676: /* original 4128, guest PC 0x0c065676 */
if(!s->budget--) { s->failed_pc=0x0c065676u; return 0; }
r[1]<<=16;
goto P_0c065678;
P_0c065678: /* original 221b, guest PC 0x0c065678 */
if(!s->budget--) { s->failed_pc=0x0c065678u; return 0; }
r[2]|=r[1];
goto P_0c06567a;
P_0c06567a: /* original 6143, guest PC 0x0c06567a */
if(!s->budget--) { s->failed_pc=0x0c06567au; return 0; }
r[1]=r[4];
goto P_0c06567c;
P_0c06567c: /* original 4118, guest PC 0x0c06567c */
if(!s->budget--) { s->failed_pc=0x0c06567cu; return 0; }
r[1]<<=8;
goto P_0c06567e;
P_0c06567e: /* original 221b, guest PC 0x0c06567e */
if(!s->budget--) { s->failed_pc=0x0c06567eu; return 0; }
r[2]|=r[1];
goto P_0c065680;
P_0c065680: /* original 224b, guest PC 0x0c065680 */
if(!s->budget--) { s->failed_pc=0x0c065680u; return 0; }
r[2]|=r[4];
goto P_0c065682;
P_0c065682: /* original 0326, guest PC 0x0c065682 */
if(!s->budget--) { s->failed_pc=0x0c065682u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065684;
P_0c065684: /* original 6ce2, guest PC 0x0c065684 */
if(!s->budget--) { s->failed_pc=0x0c065684u; return 0; }
tmp=read(ram,r[14],4);
r[12]=tmp;
goto P_0c065686;
P_0c065686: /* original e01c, guest PC 0x0c065686 */
if(!s->budget--) { s->failed_pc=0x0c065686u; return 0; }
r[0]=0x0000001cu;
goto P_0c065688;
P_0c065688: /* original f3c6, guest PC 0x0c065688 */
if(!s->budget--) { s->failed_pc=0x0c065688u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06568a;
P_0c06568a: /* original f3f2, guest PC 0x0c06568a */
if(!s->budget--) { s->failed_pc=0x0c06568au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06568c;
P_0c06568c: /* original f33d, guest PC 0x0c06568c */
if(!s->budget--) { s->failed_pc=0x0c06568cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06568e;
P_0c06568e: /* original 0c5a, guest PC 0x0c06568e */
if(!s->budget--) { s->failed_pc=0x0c06568eu; return 0; }
r[12]=r[53];
goto P_0c065690;
P_0c065690: /* original 66c3, guest PC 0x0c065690 */
if(!s->budget--) { s->failed_pc=0x0c065690u; return 0; }
r[6]=r[12];
goto P_0c065692;
P_0c065692: /* original 4628, guest PC 0x0c065692 */
if(!s->budget--) { s->failed_pc=0x0c065692u; return 0; }
r[6]<<=16;
goto P_0c065694;
P_0c065694: /* original 4618, guest PC 0x0c065694 */
if(!s->budget--) { s->failed_pc=0x0c065694u; return 0; }
r[6]<<=8;
goto P_0c065696;
P_0c065696: /* original 63c3, guest PC 0x0c065696 */
if(!s->budget--) { s->failed_pc=0x0c065696u; return 0; }
r[3]=r[12];
goto P_0c065698;
P_0c065698: /* original 4328, guest PC 0x0c065698 */
if(!s->budget--) { s->failed_pc=0x0c065698u; return 0; }
r[3]<<=16;
goto P_0c06569a;
P_0c06569a: /* original 263b, guest PC 0x0c06569a */
if(!s->budget--) { s->failed_pc=0x0c06569au; return 0; }
r[6]|=r[3];
goto P_0c06569c;
P_0c06569c: /* original d39e, guest PC 0x0c06569c */
if(!s->budget--) { s->failed_pc=0x0c06569cu; return 0; }
r[3]=read(ram,0x0c065918u,4);
goto P_0c06569e;
P_0c06569e: /* original 62c3, guest PC 0x0c06569e */
if(!s->budget--) { s->failed_pc=0x0c06569eu; return 0; }
r[2]=r[12];
goto P_0c0656a0;
P_0c0656a0: /* original 4218, guest PC 0x0c0656a0 */
if(!s->budget--) { s->failed_pc=0x0c0656a0u; return 0; }
r[2]<<=8;
goto P_0c0656a2;
P_0c0656a2: /* original 262b, guest PC 0x0c0656a2 */
if(!s->budget--) { s->failed_pc=0x0c0656a2u; return 0; }
r[6]|=r[2];
goto P_0c0656a4;
P_0c0656a4: /* original 26cb, guest PC 0x0c0656a4 */
if(!s->budget--) { s->failed_pc=0x0c0656a4u; return 0; }
r[6]|=r[12];
goto P_0c0656a6;
P_0c0656a6: /* original 6593, guest PC 0x0c0656a6 */
if(!s->budget--) { s->failed_pc=0x0c0656a6u; return 0; }
r[5]=r[9];
goto P_0c0656a8;
P_0c0656a8: /* original 430b, guest PC 0x0c0656a8 */
if(!s->budget--) { s->failed_pc=0x0c0656a8u; return 0; }
target=r[3];
r[16]=0x0c0656acu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0656acu) { target=s->pc; goto dispatch; }
goto P_0c0656ac;
P_0c0656aa: /* original 64d3, guest PC 0x0c0656aa */
if(!s->budget--) { s->failed_pc=0x0c0656aau; return 0; }
r[4]=r[13];
goto P_0c0656ac;
P_0c0656ac: /* original 61b2, guest PC 0x0c0656ac */
if(!s->budget--) { s->failed_pc=0x0c0656acu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c0656ae;
P_0c0656ae: /* original 6c03, guest PC 0x0c0656ae */
if(!s->budget--) { s->failed_pc=0x0c0656aeu; return 0; }
r[12]=r[0];
goto P_0c0656b0;
P_0c0656b0: /* original 5311, guest PC 0x0c0656b0 */
if(!s->budget--) { s->failed_pc=0x0c0656b0u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0656b2;
P_0c0656b2: /* original 62c3, guest PC 0x0c0656b2 */
if(!s->budget--) { s->failed_pc=0x0c0656b2u; return 0; }
r[2]=r[12];
goto P_0c0656b4;
P_0c0656b4: /* original d095, guest PC 0x0c0656b4 */
if(!s->budget--) { s->failed_pc=0x0c0656b4u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c0656b6;
P_0c0656b6: /* original 7c01, guest PC 0x0c0656b6 */
if(!s->budget--) { s->failed_pc=0x0c0656b6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0656b8;
P_0c0656b8: /* original 4208, guest PC 0x0c0656b8 */
if(!s->budget--) { s->failed_pc=0x0c0656b8u; return 0; }
r[2]<<=2;
goto P_0c0656ba;
P_0c0656ba: /* original 0236, guest PC 0x0c0656ba */
if(!s->budget--) { s->failed_pc=0x0c0656bau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0656bc;
P_0c0656bc: /* original 61b2, guest PC 0x0c0656bc */
if(!s->budget--) { s->failed_pc=0x0c0656bcu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c0656be;
P_0c0656be: /* original 62c3, guest PC 0x0c0656be */
if(!s->budget--) { s->failed_pc=0x0c0656beu; return 0; }
r[2]=r[12];
goto P_0c0656c0;
P_0c0656c0: /* original 5312, guest PC 0x0c0656c0 */
if(!s->budget--) { s->failed_pc=0x0c0656c0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0656c2;
P_0c0656c2: /* original 7c01, guest PC 0x0c0656c2 */
if(!s->budget--) { s->failed_pc=0x0c0656c2u; return 0; }
r[12]+=0x00000001u;
goto P_0c0656c4;
P_0c0656c4: /* original 4208, guest PC 0x0c0656c4 */
if(!s->budget--) { s->failed_pc=0x0c0656c4u; return 0; }
r[2]<<=2;
goto P_0c0656c6;
P_0c0656c6: /* original 0236, guest PC 0x0c0656c6 */
if(!s->budget--) { s->failed_pc=0x0c0656c6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0656c8;
P_0c0656c8: /* original 61b2, guest PC 0x0c0656c8 */
if(!s->budget--) { s->failed_pc=0x0c0656c8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c0656ca;
P_0c0656ca: /* original 62c3, guest PC 0x0c0656ca */
if(!s->budget--) { s->failed_pc=0x0c0656cau; return 0; }
r[2]=r[12];
goto P_0c0656cc;
P_0c0656cc: /* original 5313, guest PC 0x0c0656cc */
if(!s->budget--) { s->failed_pc=0x0c0656ccu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0656ce;
P_0c0656ce: /* original 7c01, guest PC 0x0c0656ce */
if(!s->budget--) { s->failed_pc=0x0c0656ceu; return 0; }
r[12]+=0x00000001u;
goto P_0c0656d0;
P_0c0656d0: /* original 4208, guest PC 0x0c0656d0 */
if(!s->budget--) { s->failed_pc=0x0c0656d0u; return 0; }
r[2]<<=2;
goto P_0c0656d2;
P_0c0656d2: /* original 0236, guest PC 0x0c0656d2 */
if(!s->budget--) { s->failed_pc=0x0c0656d2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0656d4;
P_0c0656d4: /* original 66e2, guest PC 0x0c0656d4 */
if(!s->budget--) { s->failed_pc=0x0c0656d4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0656d6;
P_0c0656d6: /* original 65c3, guest PC 0x0c0656d6 */
if(!s->budget--) { s->failed_pc=0x0c0656d6u; return 0; }
r[5]=r[12];
goto P_0c0656d8;
P_0c0656d8: /* original d38d, guest PC 0x0c0656d8 */
if(!s->budget--) { s->failed_pc=0x0c0656d8u; return 0; }
r[3]=read(ram,0x0c065910u,4);
goto P_0c0656da;
P_0c0656da: /* original 5664, guest PC 0x0c0656da */
if(!s->budget--) { s->failed_pc=0x0c0656dau; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0656dc;
P_0c0656dc: /* original 430b, guest PC 0x0c0656dc */
if(!s->budget--) { s->failed_pc=0x0c0656dcu; return 0; }
target=r[3];
r[16]=0x0c0656e0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0656e0u) { target=s->pc; goto dispatch; }
goto P_0c0656e0;
P_0c0656de: /* original 64d3, guest PC 0x0c0656de */
if(!s->budget--) { s->failed_pc=0x0c0656deu; return 0; }
r[4]=r[13];
goto P_0c0656e0;
P_0c0656e0: /* original 64b2, guest PC 0x0c0656e0 */
if(!s->budget--) { s->failed_pc=0x0c0656e0u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0656e2;
P_0c0656e2: /* original e118, guest PC 0x0c0656e2 */
if(!s->budget--) { s->failed_pc=0x0c0656e2u; return 0; }
r[1]=0x00000018u;
goto P_0c0656e4;
P_0c0656e4: /* original 6903, guest PC 0x0c0656e4 */
if(!s->budget--) { s->failed_pc=0x0c0656e4u; return 0; }
r[9]=r[0];
goto P_0c0656e6;
P_0c0656e6: /* original 6293, guest PC 0x0c0656e6 */
if(!s->budget--) { s->failed_pc=0x0c0656e6u; return 0; }
r[2]=r[9];
goto P_0c0656e8;
P_0c0656e8: /* original d088, guest PC 0x0c0656e8 */
if(!s->budget--) { s->failed_pc=0x0c0656e8u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c0656ea;
P_0c0656ea: /* original 314c, guest PC 0x0c0656ea */
if(!s->budget--) { s->failed_pc=0x0c0656eau; return 0; }
r[1]+=r[4];
goto P_0c0656ec;
P_0c0656ec: /* original f318, guest PC 0x0c0656ec */
if(!s->budget--) { s->failed_pc=0x0c0656ecu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0656ee;
P_0c0656ee: /* original 7901, guest PC 0x0c0656ee */
if(!s->budget--) { s->failed_pc=0x0c0656eeu; return 0; }
r[9]+=0x00000001u;
goto P_0c0656f0;
P_0c0656f0: /* original 4208, guest PC 0x0c0656f0 */
if(!s->budget--) { s->failed_pc=0x0c0656f0u; return 0; }
r[2]<<=2;
goto P_0c0656f2;
P_0c0656f2: /* original f3f2, guest PC 0x0c0656f2 */
if(!s->budget--) { s->failed_pc=0x0c0656f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0656f4;
P_0c0656f4: /* original f33d, guest PC 0x0c0656f4 */
if(!s->budget--) { s->failed_pc=0x0c0656f4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0656f6;
P_0c0656f6: /* original 045a, guest PC 0x0c0656f6 */
if(!s->budget--) { s->failed_pc=0x0c0656f6u; return 0; }
r[4]=r[53];
goto P_0c0656f8;
P_0c0656f8: /* original 6343, guest PC 0x0c0656f8 */
if(!s->budget--) { s->failed_pc=0x0c0656f8u; return 0; }
r[3]=r[4];
goto P_0c0656fa;
P_0c0656fa: /* original 4328, guest PC 0x0c0656fa */
if(!s->budget--) { s->failed_pc=0x0c0656fau; return 0; }
r[3]<<=16;
goto P_0c0656fc;
P_0c0656fc: /* original 4318, guest PC 0x0c0656fc */
if(!s->budget--) { s->failed_pc=0x0c0656fcu; return 0; }
r[3]<<=8;
goto P_0c0656fe;
P_0c0656fe: /* original 6143, guest PC 0x0c0656fe */
if(!s->budget--) { s->failed_pc=0x0c0656feu; return 0; }
r[1]=r[4];
goto P_0c065700;
P_0c065700: /* original 4128, guest PC 0x0c065700 */
if(!s->budget--) { s->failed_pc=0x0c065700u; return 0; }
r[1]<<=16;
goto P_0c065702;
P_0c065702: /* original 231b, guest PC 0x0c065702 */
if(!s->budget--) { s->failed_pc=0x0c065702u; return 0; }
r[3]|=r[1];
goto P_0c065704;
P_0c065704: /* original 6143, guest PC 0x0c065704 */
if(!s->budget--) { s->failed_pc=0x0c065704u; return 0; }
r[1]=r[4];
goto P_0c065706;
P_0c065706: /* original 4118, guest PC 0x0c065706 */
if(!s->budget--) { s->failed_pc=0x0c065706u; return 0; }
r[1]<<=8;
goto P_0c065708;
P_0c065708: /* original 231b, guest PC 0x0c065708 */
if(!s->budget--) { s->failed_pc=0x0c065708u; return 0; }
r[3]|=r[1];
goto P_0c06570a;
P_0c06570a: /* original 234b, guest PC 0x0c06570a */
if(!s->budget--) { s->failed_pc=0x0c06570au; return 0; }
r[3]|=r[4];
goto P_0c06570c;
P_0c06570c: /* original 0236, guest PC 0x0c06570c */
if(!s->budget--) { s->failed_pc=0x0c06570cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06570e;
P_0c06570e: /* original e01c, guest PC 0x0c06570e */
if(!s->budget--) { s->failed_pc=0x0c06570eu; return 0; }
r[0]=0x0000001cu;
goto P_0c065710;
P_0c065710: /* original 6cb2, guest PC 0x0c065710 */
if(!s->budget--) { s->failed_pc=0x0c065710u; return 0; }
tmp=read(ram,r[11],4);
r[12]=tmp;
goto P_0c065712;
P_0c065712: /* original f3c6, guest PC 0x0c065712 */
if(!s->budget--) { s->failed_pc=0x0c065712u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065714;
P_0c065714: /* original f3f2, guest PC 0x0c065714 */
if(!s->budget--) { s->failed_pc=0x0c065714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065716;
P_0c065716: /* original f33d, guest PC 0x0c065716 */
if(!s->budget--) { s->failed_pc=0x0c065716u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065718;
P_0c065718: /* original 0c5a, guest PC 0x0c065718 */
if(!s->budget--) { s->failed_pc=0x0c065718u; return 0; }
r[12]=r[53];
goto P_0c06571a;
P_0c06571a: /* original 66c3, guest PC 0x0c06571a */
if(!s->budget--) { s->failed_pc=0x0c06571au; return 0; }
r[6]=r[12];
goto P_0c06571c;
P_0c06571c: /* original 4628, guest PC 0x0c06571c */
if(!s->budget--) { s->failed_pc=0x0c06571cu; return 0; }
r[6]<<=16;
goto P_0c06571e;
P_0c06571e: /* original 4618, guest PC 0x0c06571e */
if(!s->budget--) { s->failed_pc=0x0c06571eu; return 0; }
r[6]<<=8;
goto P_0c065720;
P_0c065720: /* original 63c3, guest PC 0x0c065720 */
if(!s->budget--) { s->failed_pc=0x0c065720u; return 0; }
r[3]=r[12];
goto P_0c065722;
P_0c065722: /* original 4328, guest PC 0x0c065722 */
if(!s->budget--) { s->failed_pc=0x0c065722u; return 0; }
r[3]<<=16;
goto P_0c065724;
P_0c065724: /* original 263b, guest PC 0x0c065724 */
if(!s->budget--) { s->failed_pc=0x0c065724u; return 0; }
r[6]|=r[3];
goto P_0c065726;
P_0c065726: /* original 62c3, guest PC 0x0c065726 */
if(!s->budget--) { s->failed_pc=0x0c065726u; return 0; }
r[2]=r[12];
goto P_0c065728;
P_0c065728: /* original d37b, guest PC 0x0c065728 */
if(!s->budget--) { s->failed_pc=0x0c065728u; return 0; }
r[3]=read(ram,0x0c065918u,4);
goto P_0c06572a;
P_0c06572a: /* original 6593, guest PC 0x0c06572a */
if(!s->budget--) { s->failed_pc=0x0c06572au; return 0; }
r[5]=r[9];
goto P_0c06572c;
P_0c06572c: /* original 4218, guest PC 0x0c06572c */
if(!s->budget--) { s->failed_pc=0x0c06572cu; return 0; }
r[2]<<=8;
goto P_0c06572e;
P_0c06572e: /* original 262b, guest PC 0x0c06572e */
if(!s->budget--) { s->failed_pc=0x0c06572eu; return 0; }
r[6]|=r[2];
goto P_0c065730;
P_0c065730: /* original 26cb, guest PC 0x0c065730 */
if(!s->budget--) { s->failed_pc=0x0c065730u; return 0; }
r[6]|=r[12];
goto P_0c065732;
P_0c065732: /* original 430b, guest PC 0x0c065732 */
if(!s->budget--) { s->failed_pc=0x0c065732u; return 0; }
target=r[3];
r[16]=0x0c065736u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065736u) { target=s->pc; goto dispatch; }
goto P_0c065736;
P_0c065734: /* original 64d3, guest PC 0x0c065734 */
if(!s->budget--) { s->failed_pc=0x0c065734u; return 0; }
r[4]=r[13];
goto P_0c065736;
P_0c065736: /* original 6c03, guest PC 0x0c065736 */
if(!s->budget--) { s->failed_pc=0x0c065736u; return 0; }
r[12]=r[0];
goto P_0c065738;
P_0c065738: /* original 61a2, guest PC 0x0c065738 */
if(!s->budget--) { s->failed_pc=0x0c065738u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c06573a;
P_0c06573a: /* original 62c3, guest PC 0x0c06573a */
if(!s->budget--) { s->failed_pc=0x0c06573au; return 0; }
r[2]=r[12];
goto P_0c06573c;
P_0c06573c: /* original d073, guest PC 0x0c06573c */
if(!s->budget--) { s->failed_pc=0x0c06573cu; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c06573e;
P_0c06573e: /* original 7c01, guest PC 0x0c06573e */
if(!s->budget--) { s->failed_pc=0x0c06573eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065740;
P_0c065740: /* original 5311, guest PC 0x0c065740 */
if(!s->budget--) { s->failed_pc=0x0c065740u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065742;
P_0c065742: /* original 4208, guest PC 0x0c065742 */
if(!s->budget--) { s->failed_pc=0x0c065742u; return 0; }
r[2]<<=2;
goto P_0c065744;
P_0c065744: /* original 0236, guest PC 0x0c065744 */
if(!s->budget--) { s->failed_pc=0x0c065744u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065746;
P_0c065746: /* original 62c3, guest PC 0x0c065746 */
if(!s->budget--) { s->failed_pc=0x0c065746u; return 0; }
r[2]=r[12];
goto P_0c065748;
P_0c065748: /* original 61a2, guest PC 0x0c065748 */
if(!s->budget--) { s->failed_pc=0x0c065748u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c06574a;
P_0c06574a: /* original 7c01, guest PC 0x0c06574a */
if(!s->budget--) { s->failed_pc=0x0c06574au; return 0; }
r[12]+=0x00000001u;
goto P_0c06574c;
P_0c06574c: /* original 5312, guest PC 0x0c06574c */
if(!s->budget--) { s->failed_pc=0x0c06574cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c06574e;
P_0c06574e: /* original 4208, guest PC 0x0c06574e */
if(!s->budget--) { s->failed_pc=0x0c06574eu; return 0; }
r[2]<<=2;
goto P_0c065750;
P_0c065750: /* original 0236, guest PC 0x0c065750 */
if(!s->budget--) { s->failed_pc=0x0c065750u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065752;
P_0c065752: /* original 62c3, guest PC 0x0c065752 */
if(!s->budget--) { s->failed_pc=0x0c065752u; return 0; }
r[2]=r[12];
goto P_0c065754;
P_0c065754: /* original 61a2, guest PC 0x0c065754 */
if(!s->budget--) { s->failed_pc=0x0c065754u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065756;
P_0c065756: /* original 7c01, guest PC 0x0c065756 */
if(!s->budget--) { s->failed_pc=0x0c065756u; return 0; }
r[12]+=0x00000001u;
goto P_0c065758;
P_0c065758: /* original 5313, guest PC 0x0c065758 */
if(!s->budget--) { s->failed_pc=0x0c065758u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c06575a;
P_0c06575a: /* original 4208, guest PC 0x0c06575a */
if(!s->budget--) { s->failed_pc=0x0c06575au; return 0; }
r[2]<<=2;
goto P_0c06575c;
P_0c06575c: /* original 0236, guest PC 0x0c06575c */
if(!s->budget--) { s->failed_pc=0x0c06575cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06575e;
P_0c06575e: /* original 65c3, guest PC 0x0c06575e */
if(!s->budget--) { s->failed_pc=0x0c06575eu; return 0; }
r[5]=r[12];
goto P_0c065760;
P_0c065760: /* original d36b, guest PC 0x0c065760 */
if(!s->budget--) { s->failed_pc=0x0c065760u; return 0; }
r[3]=read(ram,0x0c065910u,4);
goto P_0c065762;
P_0c065762: /* original 66e2, guest PC 0x0c065762 */
if(!s->budget--) { s->failed_pc=0x0c065762u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c065764;
P_0c065764: /* original 5664, guest PC 0x0c065764 */
if(!s->budget--) { s->failed_pc=0x0c065764u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065766;
P_0c065766: /* original 430b, guest PC 0x0c065766 */
if(!s->budget--) { s->failed_pc=0x0c065766u; return 0; }
target=r[3];
r[16]=0x0c06576au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06576au) { target=s->pc; goto dispatch; }
goto P_0c06576a;
P_0c065768: /* original 64d3, guest PC 0x0c065768 */
if(!s->budget--) { s->failed_pc=0x0c065768u; return 0; }
r[4]=r[13];
goto P_0c06576a;
P_0c06576a: /* original 6b03, guest PC 0x0c06576a */
if(!s->budget--) { s->failed_pc=0x0c06576au; return 0; }
r[11]=r[0];
goto P_0c06576c;
P_0c06576c: /* original 64a2, guest PC 0x0c06576c */
if(!s->budget--) { s->failed_pc=0x0c06576cu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c06576e;
P_0c06576e: /* original e118, guest PC 0x0c06576e */
if(!s->budget--) { s->failed_pc=0x0c06576eu; return 0; }
r[1]=0x00000018u;
goto P_0c065770;
P_0c065770: /* original d066, guest PC 0x0c065770 */
if(!s->budget--) { s->failed_pc=0x0c065770u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c065772;
P_0c065772: /* original 62b3, guest PC 0x0c065772 */
if(!s->budget--) { s->failed_pc=0x0c065772u; return 0; }
r[2]=r[11];
goto P_0c065774;
P_0c065774: /* original 7b01, guest PC 0x0c065774 */
if(!s->budget--) { s->failed_pc=0x0c065774u; return 0; }
r[11]+=0x00000001u;
goto P_0c065776;
P_0c065776: /* original 4208, guest PC 0x0c065776 */
if(!s->budget--) { s->failed_pc=0x0c065776u; return 0; }
r[2]<<=2;
goto P_0c065778;
P_0c065778: /* original 314c, guest PC 0x0c065778 */
if(!s->budget--) { s->failed_pc=0x0c065778u; return 0; }
r[1]+=r[4];
goto P_0c06577a;
P_0c06577a: /* original f318, guest PC 0x0c06577a */
if(!s->budget--) { s->failed_pc=0x0c06577au; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06577c;
P_0c06577c: /* original f3f2, guest PC 0x0c06577c */
if(!s->budget--) { s->failed_pc=0x0c06577cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06577e;
P_0c06577e: /* original f33d, guest PC 0x0c06577e */
if(!s->budget--) { s->failed_pc=0x0c06577eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065780;
P_0c065780: /* original 045a, guest PC 0x0c065780 */
if(!s->budget--) { s->failed_pc=0x0c065780u; return 0; }
r[4]=r[53];
goto P_0c065782;
P_0c065782: /* original 6343, guest PC 0x0c065782 */
if(!s->budget--) { s->failed_pc=0x0c065782u; return 0; }
r[3]=r[4];
goto P_0c065784;
P_0c065784: /* original 4328, guest PC 0x0c065784 */
if(!s->budget--) { s->failed_pc=0x0c065784u; return 0; }
r[3]<<=16;
goto P_0c065786;
P_0c065786: /* original 4318, guest PC 0x0c065786 */
if(!s->budget--) { s->failed_pc=0x0c065786u; return 0; }
r[3]<<=8;
goto P_0c065788;
P_0c065788: /* original 6143, guest PC 0x0c065788 */
if(!s->budget--) { s->failed_pc=0x0c065788u; return 0; }
r[1]=r[4];
goto P_0c06578a;
P_0c06578a: /* original 4128, guest PC 0x0c06578a */
if(!s->budget--) { s->failed_pc=0x0c06578au; return 0; }
r[1]<<=16;
goto P_0c06578c;
P_0c06578c: /* original 231b, guest PC 0x0c06578c */
if(!s->budget--) { s->failed_pc=0x0c06578cu; return 0; }
r[3]|=r[1];
goto P_0c06578e;
P_0c06578e: /* original 6143, guest PC 0x0c06578e */
if(!s->budget--) { s->failed_pc=0x0c06578eu; return 0; }
r[1]=r[4];
goto P_0c065790;
P_0c065790: /* original 4118, guest PC 0x0c065790 */
if(!s->budget--) { s->failed_pc=0x0c065790u; return 0; }
r[1]<<=8;
goto P_0c065792;
P_0c065792: /* original 231b, guest PC 0x0c065792 */
if(!s->budget--) { s->failed_pc=0x0c065792u; return 0; }
r[3]|=r[1];
goto P_0c065794;
P_0c065794: /* original 234b, guest PC 0x0c065794 */
if(!s->budget--) { s->failed_pc=0x0c065794u; return 0; }
r[3]|=r[4];
goto P_0c065796;
P_0c065796: /* original 0236, guest PC 0x0c065796 */
if(!s->budget--) { s->failed_pc=0x0c065796u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065798;
P_0c065798: /* original 6ca2, guest PC 0x0c065798 */
if(!s->budget--) { s->failed_pc=0x0c065798u; return 0; }
tmp=read(ram,r[10],4);
r[12]=tmp;
goto P_0c06579a;
P_0c06579a: /* original e01c, guest PC 0x0c06579a */
if(!s->budget--) { s->failed_pc=0x0c06579au; return 0; }
r[0]=0x0000001cu;
goto P_0c06579c;
P_0c06579c: /* original f3c6, guest PC 0x0c06579c */
if(!s->budget--) { s->failed_pc=0x0c06579cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06579e;
P_0c06579e: /* original f3f2, guest PC 0x0c06579e */
if(!s->budget--) { s->failed_pc=0x0c06579eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0657a0;
P_0c0657a0: /* original f33d, guest PC 0x0c0657a0 */
if(!s->budget--) { s->failed_pc=0x0c0657a0u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0657a2;
P_0c0657a2: /* original 0c5a, guest PC 0x0c0657a2 */
if(!s->budget--) { s->failed_pc=0x0c0657a2u; return 0; }
r[12]=r[53];
goto P_0c0657a4;
P_0c0657a4: /* original 66c3, guest PC 0x0c0657a4 */
if(!s->budget--) { s->failed_pc=0x0c0657a4u; return 0; }
r[6]=r[12];
goto P_0c0657a6;
P_0c0657a6: /* original 4628, guest PC 0x0c0657a6 */
if(!s->budget--) { s->failed_pc=0x0c0657a6u; return 0; }
r[6]<<=16;
goto P_0c0657a8;
P_0c0657a8: /* original 4618, guest PC 0x0c0657a8 */
if(!s->budget--) { s->failed_pc=0x0c0657a8u; return 0; }
r[6]<<=8;
goto P_0c0657aa;
P_0c0657aa: /* original 63c3, guest PC 0x0c0657aa */
if(!s->budget--) { s->failed_pc=0x0c0657aau; return 0; }
r[3]=r[12];
goto P_0c0657ac;
P_0c0657ac: /* original 4328, guest PC 0x0c0657ac */
if(!s->budget--) { s->failed_pc=0x0c0657acu; return 0; }
r[3]<<=16;
goto P_0c0657ae;
P_0c0657ae: /* original 263b, guest PC 0x0c0657ae */
if(!s->budget--) { s->failed_pc=0x0c0657aeu; return 0; }
r[6]|=r[3];
goto P_0c0657b0;
P_0c0657b0: /* original d359, guest PC 0x0c0657b0 */
if(!s->budget--) { s->failed_pc=0x0c0657b0u; return 0; }
r[3]=read(ram,0x0c065918u,4);
goto P_0c0657b2;
P_0c0657b2: /* original 62c3, guest PC 0x0c0657b2 */
if(!s->budget--) { s->failed_pc=0x0c0657b2u; return 0; }
r[2]=r[12];
goto P_0c0657b4;
P_0c0657b4: /* original 4218, guest PC 0x0c0657b4 */
if(!s->budget--) { s->failed_pc=0x0c0657b4u; return 0; }
r[2]<<=8;
goto P_0c0657b6;
P_0c0657b6: /* original 262b, guest PC 0x0c0657b6 */
if(!s->budget--) { s->failed_pc=0x0c0657b6u; return 0; }
r[6]|=r[2];
goto P_0c0657b8;
P_0c0657b8: /* original 26cb, guest PC 0x0c0657b8 */
if(!s->budget--) { s->failed_pc=0x0c0657b8u; return 0; }
r[6]|=r[12];
goto P_0c0657ba;
P_0c0657ba: /* original 65b3, guest PC 0x0c0657ba */
if(!s->budget--) { s->failed_pc=0x0c0657bau; return 0; }
r[5]=r[11];
goto P_0c0657bc;
P_0c0657bc: /* original 430b, guest PC 0x0c0657bc */
if(!s->budget--) { s->failed_pc=0x0c0657bcu; return 0; }
target=r[3];
r[16]=0x0c0657c0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0657c0u) { target=s->pc; goto dispatch; }
goto P_0c0657c0;
P_0c0657be: /* original 64d3, guest PC 0x0c0657be */
if(!s->budget--) { s->failed_pc=0x0c0657beu; return 0; }
r[4]=r[13];
goto P_0c0657c0;
P_0c0657c0: /* original d256, guest PC 0x0c0657c0 */
if(!s->budget--) { s->failed_pc=0x0c0657c0u; return 0; }
r[2]=read(ram,0x0c06591cu,4);
goto P_0c0657c2;
P_0c0657c2: /* original 6403, guest PC 0x0c0657c2 */
if(!s->budget--) { s->failed_pc=0x0c0657c2u; return 0; }
r[4]=r[0];
goto P_0c0657c4;
P_0c0657c4: /* original 4408, guest PC 0x0c0657c4 */
if(!s->budget--) { s->failed_pc=0x0c0657c4u; return 0; }
r[4]<<=2;
goto P_0c0657c6;
P_0c0657c6: /* original 2242, guest PC 0x0c0657c6 */
if(!s->budget--) { s->failed_pc=0x0c0657c6u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0657c8;
P_0c0657c8: /* original d355, guest PC 0x0c0657c8 */
if(!s->budget--) { s->failed_pc=0x0c0657c8u; return 0; }
r[3]=read(ram,0x0c065920u,4);
goto P_0c0657ca;
P_0c0657ca: /* original 430b, guest PC 0x0c0657ca */
if(!s->budget--) { s->failed_pc=0x0c0657cau; return 0; }
target=r[3];
r[16]=0x0c0657ceu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0657ceu) { target=s->pc; goto dispatch; }
goto P_0c0657ce;
P_0c0657cc: /* original 64d3, guest PC 0x0c0657cc */
if(!s->budget--) { s->failed_pc=0x0c0657ccu; return 0; }
r[4]=r[13];
goto P_0c0657ce;
P_0c0657ce: /* original 6403, guest PC 0x0c0657ce */
if(!s->budget--) { s->failed_pc=0x0c0657ceu; return 0; }
r[4]=r[0];
goto P_0c0657d0;
P_0c0657d0: /* original d254, guest PC 0x0c0657d0 */
if(!s->budget--) { s->failed_pc=0x0c0657d0u; return 0; }
r[2]=read(ram,0x0c065924u,4);
goto P_0c0657d2;
P_0c0657d2: /* original e500, guest PC 0x0c0657d2 */
if(!s->budget--) { s->failed_pc=0x0c0657d2u; return 0; }
r[5]=0x00000000u;
goto P_0c0657d4;
P_0c0657d4: /* original 420b, guest PC 0x0c0657d4 */
if(!s->budget--) { s->failed_pc=0x0c0657d4u; return 0; }
target=r[2];
r[16]=0x0c0657d8u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0657d8u) { target=s->pc; goto dispatch; }
goto P_0c0657d8;
P_0c0657d6: /* original 6653, guest PC 0x0c0657d6 */
if(!s->budget--) { s->failed_pc=0x0c0657d6u; return 0; }
r[6]=r[5];
goto P_0c0657d8;
P_0c0657d8: /* original 62e2, guest PC 0x0c0657d8 */
if(!s->budget--) { s->failed_pc=0x0c0657d8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0657da;
P_0c0657da: /* original 5323, guest PC 0x0c0657da */
if(!s->budget--) { s->failed_pc=0x0c0657dau; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0657dc;
P_0c0657dc: /* original d152, guest PC 0x0c0657dc */
if(!s->budget--) { s->failed_pc=0x0c0657dcu; return 0; }
r[1]=read(ram,0x0c065928u,4);
goto P_0c0657de;
P_0c0657de: /* original 2132, guest PC 0x0c0657de */
if(!s->budget--) { s->failed_pc=0x0c0657deu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0657e0;
P_0c0657e0: /* original e000, guest PC 0x0c0657e0 */
if(!s->budget--) { s->failed_pc=0x0c0657e0u; return 0; }
r[0]=0x00000000u;
goto P_0c0657e2;
P_0c0657e2: /* original 7f0c, guest PC 0x0c0657e2 */
if(!s->budget--) { s->failed_pc=0x0c0657e2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0657e4;
P_0c0657e4: /* original 4f26, guest PC 0x0c0657e4 */
if(!s->budget--) { s->failed_pc=0x0c0657e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0657e6;
P_0c0657e6: /* original fff9, guest PC 0x0c0657e6 */
if(!s->budget--) { s->failed_pc=0x0c0657e6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0657e8;
P_0c0657e8: /* original 69f6, guest PC 0x0c0657e8 */
if(!s->budget--) { s->failed_pc=0x0c0657e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0657ea;
P_0c0657ea: /* original 6af6, guest PC 0x0c0657ea */
if(!s->budget--) { s->failed_pc=0x0c0657eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0657ec;
P_0c0657ec: /* original 6bf6, guest PC 0x0c0657ec */
if(!s->budget--) { s->failed_pc=0x0c0657ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0657ee;
P_0c0657ee: /* original 6cf6, guest PC 0x0c0657ee */
if(!s->budget--) { s->failed_pc=0x0c0657eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0657f0;
P_0c0657f0: /* original 6df6, guest PC 0x0c0657f0 */
if(!s->budget--) { s->failed_pc=0x0c0657f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0657f2;
P_0c0657f2: /* original 000b, guest PC 0x0c0657f2 */
if(!s->budget--) { s->failed_pc=0x0c0657f2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0657f4: /* original 6ef6, guest PC 0x0c0657f4 */
if(!s->budget--) { s->failed_pc=0x0c0657f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0657f6u,s,ram);
P_0c065aa0: /* original 4f22, guest PC 0x0c065aa0 */
if(!s->budget--) { s->failed_pc=0x0c065aa0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c065aa2;
P_0c065aa2: /* original 7ff0, guest PC 0x0c065aa2 */
if(!s->budget--) { s->failed_pc=0x0c065aa2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065aa4;
P_0c065aa4: /* original 6342, guest PC 0x0c065aa4 */
if(!s->budget--) { s->failed_pc=0x0c065aa4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065aa6;
P_0c065aa6: /* original 65f3, guest PC 0x0c065aa6 */
if(!s->budget--) { s->failed_pc=0x0c065aa6u; return 0; }
r[5]=r[15];
goto P_0c065aa8;
P_0c065aa8: /* original 7504, guest PC 0x0c065aa8 */
if(!s->budget--) { s->failed_pc=0x0c065aa8u; return 0; }
r[5]+=0x00000004u;
goto P_0c065aaa;
P_0c065aaa: /* original 6d53, guest PC 0x0c065aaa */
if(!s->budget--) { s->failed_pc=0x0c065aaau; return 0; }
r[13]=r[5];
goto P_0c065aac;
P_0c065aac: /* original 2d32, guest PC 0x0c065aac */
if(!s->budget--) { s->failed_pc=0x0c065aacu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c065aae;
P_0c065aae: /* original 6ad3, guest PC 0x0c065aae */
if(!s->budget--) { s->failed_pc=0x0c065aaeu; return 0; }
r[10]=r[13];
goto P_0c065ab0;
P_0c065ab0: /* original 5241, guest PC 0x0c065ab0 */
if(!s->budget--) { s->failed_pc=0x0c065ab0u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c065ab2;
P_0c065ab2: /* original 6bd3, guest PC 0x0c065ab2 */
if(!s->budget--) { s->failed_pc=0x0c065ab2u; return 0; }
r[11]=r[13];
goto P_0c065ab4;
P_0c065ab4: /* original 7a04, guest PC 0x0c065ab4 */
if(!s->budget--) { s->failed_pc=0x0c065ab4u; return 0; }
r[10]+=0x00000004u;
goto P_0c065ab6;
P_0c065ab6: /* original 7b08, guest PC 0x0c065ab6 */
if(!s->budget--) { s->failed_pc=0x0c065ab6u; return 0; }
r[11]+=0x00000008u;
goto P_0c065ab8;
P_0c065ab8: /* original 2a22, guest PC 0x0c065ab8 */
if(!s->budget--) { s->failed_pc=0x0c065ab8u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c065aba;
P_0c065aba: /* original 5342, guest PC 0x0c065aba */
if(!s->budget--) { s->failed_pc=0x0c065abau; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065abc;
P_0c065abc: /* original d255, guest PC 0x0c065abc */
if(!s->budget--) { s->failed_pc=0x0c065abcu; return 0; }
r[2]=read(ram,0x0c065c14u,4);
goto P_0c065abe;
P_0c065abe: /* original 2b32, guest PC 0x0c065abe */
if(!s->budget--) { s->failed_pc=0x0c065abeu; return 0; }
write(ram,r[11],r[3],4);
goto P_0c065ac0;
P_0c065ac0: /* original 6e22, guest PC 0x0c065ac0 */
if(!s->budget--) { s->failed_pc=0x0c065ac0u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c065ac2;
P_0c065ac2: /* original d355, guest PC 0x0c065ac2 */
if(!s->budget--) { s->failed_pc=0x0c065ac2u; return 0; }
r[3]=read(ram,0x0c065c18u,4);
goto P_0c065ac4;
P_0c065ac4: /* original 6432, guest PC 0x0c065ac4 */
if(!s->budget--) { s->failed_pc=0x0c065ac4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c065ac6;
P_0c065ac6: /* original d155, guest PC 0x0c065ac6 */
if(!s->budget--) { s->failed_pc=0x0c065ac6u; return 0; }
r[1]=read(ram,0x0c065c1cu,4);
goto P_0c065ac8;
P_0c065ac8: /* original 6512, guest PC 0x0c065ac8 */
if(!s->budget--) { s->failed_pc=0x0c065ac8u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c065aca;
P_0c065aca: /* original d055, guest PC 0x0c065aca */
if(!s->budget--) { s->failed_pc=0x0c065acau; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065acc;
P_0c065acc: /* original 62c3, guest PC 0x0c065acc */
if(!s->budget--) { s->failed_pc=0x0c065accu; return 0; }
r[2]=r[12];
goto P_0c065ace;
P_0c065ace: /* original 7c01, guest PC 0x0c065ace */
if(!s->budget--) { s->failed_pc=0x0c065aceu; return 0; }
r[12]+=0x00000001u;
goto P_0c065ad0;
P_0c065ad0: /* original 4208, guest PC 0x0c065ad0 */
if(!s->budget--) { s->failed_pc=0x0c065ad0u; return 0; }
r[2]<<=2;
goto P_0c065ad2;
P_0c065ad2: /* original 02e6, guest PC 0x0c065ad2 */
if(!s->budget--) { s->failed_pc=0x0c065ad2u; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c065ad4;
P_0c065ad4: /* original 63c3, guest PC 0x0c065ad4 */
if(!s->budget--) { s->failed_pc=0x0c065ad4u; return 0; }
r[3]=r[12];
goto P_0c065ad6;
P_0c065ad6: /* original 7c01, guest PC 0x0c065ad6 */
if(!s->budget--) { s->failed_pc=0x0c065ad6u; return 0; }
r[12]+=0x00000001u;
goto P_0c065ad8;
P_0c065ad8: /* original 4308, guest PC 0x0c065ad8 */
if(!s->budget--) { s->failed_pc=0x0c065ad8u; return 0; }
r[3]<<=2;
goto P_0c065ada;
P_0c065ada: /* original 0346, guest PC 0x0c065ada */
if(!s->budget--) { s->failed_pc=0x0c065adau; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c065adc;
P_0c065adc: /* original 62c3, guest PC 0x0c065adc */
if(!s->budget--) { s->failed_pc=0x0c065adcu; return 0; }
r[2]=r[12];
goto P_0c065ade;
P_0c065ade: /* original 7c01, guest PC 0x0c065ade */
if(!s->budget--) { s->failed_pc=0x0c065adeu; return 0; }
r[12]+=0x00000001u;
goto P_0c065ae0;
P_0c065ae0: /* original 4208, guest PC 0x0c065ae0 */
if(!s->budget--) { s->failed_pc=0x0c065ae0u; return 0; }
r[2]<<=2;
goto P_0c065ae2;
P_0c065ae2: /* original 0256, guest PC 0x0c065ae2 */
if(!s->budget--) { s->failed_pc=0x0c065ae2u; return 0; }
write(ram,r[2]+r[0],r[5],4);
goto P_0c065ae4;
P_0c065ae4: /* original 62d2, guest PC 0x0c065ae4 */
if(!s->budget--) { s->failed_pc=0x0c065ae4u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065ae6;
P_0c065ae6: /* original 63c3, guest PC 0x0c065ae6 */
if(!s->budget--) { s->failed_pc=0x0c065ae6u; return 0; }
r[3]=r[12];
goto P_0c065ae8;
P_0c065ae8: /* original 5221, guest PC 0x0c065ae8 */
if(!s->budget--) { s->failed_pc=0x0c065ae8u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c065aea;
P_0c065aea: /* original 7c01, guest PC 0x0c065aea */
if(!s->budget--) { s->failed_pc=0x0c065aeau; return 0; }
r[12]+=0x00000001u;
goto P_0c065aec;
P_0c065aec: /* original 4308, guest PC 0x0c065aec */
if(!s->budget--) { s->failed_pc=0x0c065aecu; return 0; }
r[3]<<=2;
goto P_0c065aee;
P_0c065aee: /* original 0326, guest PC 0x0c065aee */
if(!s->budget--) { s->failed_pc=0x0c065aeeu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065af0;
P_0c065af0: /* original 62d2, guest PC 0x0c065af0 */
if(!s->budget--) { s->failed_pc=0x0c065af0u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065af2;
P_0c065af2: /* original 63c3, guest PC 0x0c065af2 */
if(!s->budget--) { s->failed_pc=0x0c065af2u; return 0; }
r[3]=r[12];
goto P_0c065af4;
P_0c065af4: /* original 5222, guest PC 0x0c065af4 */
if(!s->budget--) { s->failed_pc=0x0c065af4u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c065af6;
P_0c065af6: /* original 7c01, guest PC 0x0c065af6 */
if(!s->budget--) { s->failed_pc=0x0c065af6u; return 0; }
r[12]+=0x00000001u;
goto P_0c065af8;
P_0c065af8: /* original 4308, guest PC 0x0c065af8 */
if(!s->budget--) { s->failed_pc=0x0c065af8u; return 0; }
r[3]<<=2;
goto P_0c065afa;
P_0c065afa: /* original 0326, guest PC 0x0c065afa */
if(!s->budget--) { s->failed_pc=0x0c065afau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065afc;
P_0c065afc: /* original 62d2, guest PC 0x0c065afc */
if(!s->budget--) { s->failed_pc=0x0c065afcu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065afe;
P_0c065afe: /* original 63c3, guest PC 0x0c065afe */
if(!s->budget--) { s->failed_pc=0x0c065afeu; return 0; }
r[3]=r[12];
goto P_0c065b00;
P_0c065b00: /* original 5223, guest PC 0x0c065b00 */
if(!s->budget--) { s->failed_pc=0x0c065b00u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c065b02;
P_0c065b02: /* original 7c01, guest PC 0x0c065b02 */
if(!s->budget--) { s->failed_pc=0x0c065b02u; return 0; }
r[12]+=0x00000001u;
goto P_0c065b04;
P_0c065b04: /* original 4308, guest PC 0x0c065b04 */
if(!s->budget--) { s->failed_pc=0x0c065b04u; return 0; }
r[3]<<=2;
goto P_0c065b06;
P_0c065b06: /* original 0326, guest PC 0x0c065b06 */
if(!s->budget--) { s->failed_pc=0x0c065b06u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065b08;
P_0c065b08: /* original 67d2, guest PC 0x0c065b08 */
if(!s->budget--) { s->failed_pc=0x0c065b08u; return 0; }
tmp=read(ram,r[13],4);
r[7]=tmp;
goto P_0c065b0a;
P_0c065b0a: /* original 2f72, guest PC 0x0c065b0a */
if(!s->budget--) { s->failed_pc=0x0c065b0au; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065b0c;
P_0c065b0c: /* original 5775, guest PC 0x0c065b0c */
if(!s->budget--) { s->failed_pc=0x0c065b0cu; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065b0e;
P_0c065b0e: /* original 66f2, guest PC 0x0c065b0e */
if(!s->budget--) { s->failed_pc=0x0c065b0eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065b10;
P_0c065b10: /* original 5664, guest PC 0x0c065b10 */
if(!s->budget--) { s->failed_pc=0x0c065b10u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065b12;
P_0c065b12: /* original 65c3, guest PC 0x0c065b12 */
if(!s->budget--) { s->failed_pc=0x0c065b12u; return 0; }
r[5]=r[12];
goto P_0c065b14;
P_0c065b14: /* original d348, guest PC 0x0c065b14 */
if(!s->budget--) { s->failed_pc=0x0c065b14u; return 0; }
r[3]=read(ram,0x0c065c38u,4);
goto P_0c065b16;
P_0c065b16: /* original 430b, guest PC 0x0c065b16 */
if(!s->budget--) { s->failed_pc=0x0c065b16u; return 0; }
target=r[3];
r[16]=0x0c065b1au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065b1au) { target=s->pc; goto dispatch; }
goto P_0c065b1a;
P_0c065b18: /* original 64e3, guest PC 0x0c065b18 */
if(!s->budget--) { s->failed_pc=0x0c065b18u; return 0; }
r[4]=r[14];
goto P_0c065b1a;
P_0c065b1a: /* original 6c03, guest PC 0x0c065b1a */
if(!s->budget--) { s->failed_pc=0x0c065b1au; return 0; }
r[12]=r[0];
goto P_0c065b1c;
P_0c065b1c: /* original 63d2, guest PC 0x0c065b1c */
if(!s->budget--) { s->failed_pc=0x0c065b1cu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c065b1e;
P_0c065b1e: /* original 62c3, guest PC 0x0c065b1e */
if(!s->budget--) { s->failed_pc=0x0c065b1eu; return 0; }
r[2]=r[12];
goto P_0c065b20;
P_0c065b20: /* original d03f, guest PC 0x0c065b20 */
if(!s->budget--) { s->failed_pc=0x0c065b20u; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065b22;
P_0c065b22: /* original 7c01, guest PC 0x0c065b22 */
if(!s->budget--) { s->failed_pc=0x0c065b22u; return 0; }
r[12]+=0x00000001u;
goto P_0c065b24;
P_0c065b24: /* original 5136, guest PC 0x0c065b24 */
if(!s->budget--) { s->failed_pc=0x0c065b24u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065b26;
P_0c065b26: /* original 4208, guest PC 0x0c065b26 */
if(!s->budget--) { s->failed_pc=0x0c065b26u; return 0; }
r[2]<<=2;
goto P_0c065b28;
P_0c065b28: /* original 0216, guest PC 0x0c065b28 */
if(!s->budget--) { s->failed_pc=0x0c065b28u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065b2a;
P_0c065b2a: /* original 65c3, guest PC 0x0c065b2a */
if(!s->budget--) { s->failed_pc=0x0c065b2au; return 0; }
r[5]=r[12];
goto P_0c065b2c;
P_0c065b2c: /* original d343, guest PC 0x0c065b2c */
if(!s->budget--) { s->failed_pc=0x0c065b2cu; return 0; }
r[3]=read(ram,0x0c065c3cu,4);
goto P_0c065b2e;
P_0c065b2e: /* original 66d2, guest PC 0x0c065b2e */
if(!s->budget--) { s->failed_pc=0x0c065b2eu; return 0; }
tmp=read(ram,r[13],4);
r[6]=tmp;
goto P_0c065b30;
P_0c065b30: /* original 5667, guest PC 0x0c065b30 */
if(!s->budget--) { s->failed_pc=0x0c065b30u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065b32;
P_0c065b32: /* original 430b, guest PC 0x0c065b32 */
if(!s->budget--) { s->failed_pc=0x0c065b32u; return 0; }
target=r[3];
r[16]=0x0c065b36u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065b36u) { target=s->pc; goto dispatch; }
goto P_0c065b36;
P_0c065b34: /* original 64e3, guest PC 0x0c065b34 */
if(!s->budget--) { s->failed_pc=0x0c065b34u; return 0; }
r[4]=r[14];
goto P_0c065b36;
P_0c065b36: /* original 6c03, guest PC 0x0c065b36 */
if(!s->budget--) { s->failed_pc=0x0c065b36u; return 0; }
r[12]=r[0];
goto P_0c065b38;
P_0c065b38: /* original 61a2, guest PC 0x0c065b38 */
if(!s->budget--) { s->failed_pc=0x0c065b38u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065b3a;
P_0c065b3a: /* original 62c3, guest PC 0x0c065b3a */
if(!s->budget--) { s->failed_pc=0x0c065b3au; return 0; }
r[2]=r[12];
goto P_0c065b3c;
P_0c065b3c: /* original d038, guest PC 0x0c065b3c */
if(!s->budget--) { s->failed_pc=0x0c065b3cu; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065b3e;
P_0c065b3e: /* original 7c01, guest PC 0x0c065b3e */
if(!s->budget--) { s->failed_pc=0x0c065b3eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065b40;
P_0c065b40: /* original 5311, guest PC 0x0c065b40 */
if(!s->budget--) { s->failed_pc=0x0c065b40u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065b42;
P_0c065b42: /* original 4208, guest PC 0x0c065b42 */
if(!s->budget--) { s->failed_pc=0x0c065b42u; return 0; }
r[2]<<=2;
goto P_0c065b44;
P_0c065b44: /* original 0236, guest PC 0x0c065b44 */
if(!s->budget--) { s->failed_pc=0x0c065b44u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065b46;
P_0c065b46: /* original 62c3, guest PC 0x0c065b46 */
if(!s->budget--) { s->failed_pc=0x0c065b46u; return 0; }
r[2]=r[12];
goto P_0c065b48;
P_0c065b48: /* original 61a2, guest PC 0x0c065b48 */
if(!s->budget--) { s->failed_pc=0x0c065b48u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065b4a;
P_0c065b4a: /* original 7c01, guest PC 0x0c065b4a */
if(!s->budget--) { s->failed_pc=0x0c065b4au; return 0; }
r[12]+=0x00000001u;
goto P_0c065b4c;
P_0c065b4c: /* original 5312, guest PC 0x0c065b4c */
if(!s->budget--) { s->failed_pc=0x0c065b4cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065b4e;
P_0c065b4e: /* original 4208, guest PC 0x0c065b4e */
if(!s->budget--) { s->failed_pc=0x0c065b4eu; return 0; }
r[2]<<=2;
goto P_0c065b50;
P_0c065b50: /* original 0236, guest PC 0x0c065b50 */
if(!s->budget--) { s->failed_pc=0x0c065b50u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065b52;
P_0c065b52: /* original 62c3, guest PC 0x0c065b52 */
if(!s->budget--) { s->failed_pc=0x0c065b52u; return 0; }
r[2]=r[12];
goto P_0c065b54;
P_0c065b54: /* original 61a2, guest PC 0x0c065b54 */
if(!s->budget--) { s->failed_pc=0x0c065b54u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065b56;
P_0c065b56: /* original 7c01, guest PC 0x0c065b56 */
if(!s->budget--) { s->failed_pc=0x0c065b56u; return 0; }
r[12]+=0x00000001u;
goto P_0c065b58;
P_0c065b58: /* original 5313, guest PC 0x0c065b58 */
if(!s->budget--) { s->failed_pc=0x0c065b58u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065b5a;
P_0c065b5a: /* original 4208, guest PC 0x0c065b5a */
if(!s->budget--) { s->failed_pc=0x0c065b5au; return 0; }
r[2]<<=2;
goto P_0c065b5c;
P_0c065b5c: /* original 0236, guest PC 0x0c065b5c */
if(!s->budget--) { s->failed_pc=0x0c065b5cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065b5e;
P_0c065b5e: /* original 65c3, guest PC 0x0c065b5e */
if(!s->budget--) { s->failed_pc=0x0c065b5eu; return 0; }
r[5]=r[12];
goto P_0c065b60;
P_0c065b60: /* original d335, guest PC 0x0c065b60 */
if(!s->budget--) { s->failed_pc=0x0c065b60u; return 0; }
r[3]=read(ram,0x0c065c38u,4);
goto P_0c065b62;
P_0c065b62: /* original 67a2, guest PC 0x0c065b62 */
if(!s->budget--) { s->failed_pc=0x0c065b62u; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c065b64;
P_0c065b64: /* original 2f72, guest PC 0x0c065b64 */
if(!s->budget--) { s->failed_pc=0x0c065b64u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065b66;
P_0c065b66: /* original 5775, guest PC 0x0c065b66 */
if(!s->budget--) { s->failed_pc=0x0c065b66u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065b68;
P_0c065b68: /* original 66f2, guest PC 0x0c065b68 */
if(!s->budget--) { s->failed_pc=0x0c065b68u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065b6a;
P_0c065b6a: /* original 5664, guest PC 0x0c065b6a */
if(!s->budget--) { s->failed_pc=0x0c065b6au; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065b6c;
P_0c065b6c: /* original 430b, guest PC 0x0c065b6c */
if(!s->budget--) { s->failed_pc=0x0c065b6cu; return 0; }
target=r[3];
r[16]=0x0c065b70u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065b70u) { target=s->pc; goto dispatch; }
goto P_0c065b70;
P_0c065b6e: /* original 64e3, guest PC 0x0c065b6e */
if(!s->budget--) { s->failed_pc=0x0c065b6eu; return 0; }
r[4]=r[14];
goto P_0c065b70;
P_0c065b70: /* original 63a2, guest PC 0x0c065b70 */
if(!s->budget--) { s->failed_pc=0x0c065b70u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c065b72;
P_0c065b72: /* original 6c03, guest PC 0x0c065b72 */
if(!s->budget--) { s->failed_pc=0x0c065b72u; return 0; }
r[12]=r[0];
goto P_0c065b74;
P_0c065b74: /* original 5136, guest PC 0x0c065b74 */
if(!s->budget--) { s->failed_pc=0x0c065b74u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065b76;
P_0c065b76: /* original 62c3, guest PC 0x0c065b76 */
if(!s->budget--) { s->failed_pc=0x0c065b76u; return 0; }
r[2]=r[12];
goto P_0c065b78;
P_0c065b78: /* original d029, guest PC 0x0c065b78 */
if(!s->budget--) { s->failed_pc=0x0c065b78u; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065b7a;
P_0c065b7a: /* original 7c01, guest PC 0x0c065b7a */
if(!s->budget--) { s->failed_pc=0x0c065b7au; return 0; }
r[12]+=0x00000001u;
goto P_0c065b7c;
P_0c065b7c: /* original 4208, guest PC 0x0c065b7c */
if(!s->budget--) { s->failed_pc=0x0c065b7cu; return 0; }
r[2]<<=2;
goto P_0c065b7e;
P_0c065b7e: /* original 0216, guest PC 0x0c065b7e */
if(!s->budget--) { s->failed_pc=0x0c065b7eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065b80;
P_0c065b80: /* original 66a2, guest PC 0x0c065b80 */
if(!s->budget--) { s->failed_pc=0x0c065b80u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c065b82;
P_0c065b82: /* original 65c3, guest PC 0x0c065b82 */
if(!s->budget--) { s->failed_pc=0x0c065b82u; return 0; }
r[5]=r[12];
goto P_0c065b84;
P_0c065b84: /* original d32d, guest PC 0x0c065b84 */
if(!s->budget--) { s->failed_pc=0x0c065b84u; return 0; }
r[3]=read(ram,0x0c065c3cu,4);
goto P_0c065b86;
P_0c065b86: /* original 5667, guest PC 0x0c065b86 */
if(!s->budget--) { s->failed_pc=0x0c065b86u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065b88;
P_0c065b88: /* original 430b, guest PC 0x0c065b88 */
if(!s->budget--) { s->failed_pc=0x0c065b88u; return 0; }
target=r[3];
r[16]=0x0c065b8cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065b8cu) { target=s->pc; goto dispatch; }
goto P_0c065b8c;
P_0c065b8a: /* original 64e3, guest PC 0x0c065b8a */
if(!s->budget--) { s->failed_pc=0x0c065b8au; return 0; }
r[4]=r[14];
goto P_0c065b8c;
P_0c065b8c: /* original 61b2, guest PC 0x0c065b8c */
if(!s->budget--) { s->failed_pc=0x0c065b8cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065b8e;
P_0c065b8e: /* original 6c03, guest PC 0x0c065b8e */
if(!s->budget--) { s->failed_pc=0x0c065b8eu; return 0; }
r[12]=r[0];
goto P_0c065b90;
P_0c065b90: /* original 5311, guest PC 0x0c065b90 */
if(!s->budget--) { s->failed_pc=0x0c065b90u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065b92;
P_0c065b92: /* original 62c3, guest PC 0x0c065b92 */
if(!s->budget--) { s->failed_pc=0x0c065b92u; return 0; }
r[2]=r[12];
goto P_0c065b94;
P_0c065b94: /* original d022, guest PC 0x0c065b94 */
if(!s->budget--) { s->failed_pc=0x0c065b94u; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065b96;
P_0c065b96: /* original 7c01, guest PC 0x0c065b96 */
if(!s->budget--) { s->failed_pc=0x0c065b96u; return 0; }
r[12]+=0x00000001u;
goto P_0c065b98;
P_0c065b98: /* original 4208, guest PC 0x0c065b98 */
if(!s->budget--) { s->failed_pc=0x0c065b98u; return 0; }
r[2]<<=2;
goto P_0c065b9a;
P_0c065b9a: /* original 0236, guest PC 0x0c065b9a */
if(!s->budget--) { s->failed_pc=0x0c065b9au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065b9c;
P_0c065b9c: /* original 61b2, guest PC 0x0c065b9c */
if(!s->budget--) { s->failed_pc=0x0c065b9cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065b9e;
P_0c065b9e: /* original 62c3, guest PC 0x0c065b9e */
if(!s->budget--) { s->failed_pc=0x0c065b9eu; return 0; }
r[2]=r[12];
goto P_0c065ba0;
P_0c065ba0: /* original 5312, guest PC 0x0c065ba0 */
if(!s->budget--) { s->failed_pc=0x0c065ba0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065ba2;
P_0c065ba2: /* original 7c01, guest PC 0x0c065ba2 */
if(!s->budget--) { s->failed_pc=0x0c065ba2u; return 0; }
r[12]+=0x00000001u;
goto P_0c065ba4;
P_0c065ba4: /* original 4208, guest PC 0x0c065ba4 */
if(!s->budget--) { s->failed_pc=0x0c065ba4u; return 0; }
r[2]<<=2;
goto P_0c065ba6;
P_0c065ba6: /* original 0236, guest PC 0x0c065ba6 */
if(!s->budget--) { s->failed_pc=0x0c065ba6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065ba8;
P_0c065ba8: /* original 61b2, guest PC 0x0c065ba8 */
if(!s->budget--) { s->failed_pc=0x0c065ba8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065baa;
P_0c065baa: /* original 62c3, guest PC 0x0c065baa */
if(!s->budget--) { s->failed_pc=0x0c065baau; return 0; }
r[2]=r[12];
goto P_0c065bac;
P_0c065bac: /* original 5313, guest PC 0x0c065bac */
if(!s->budget--) { s->failed_pc=0x0c065bacu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065bae;
P_0c065bae: /* original 7c01, guest PC 0x0c065bae */
if(!s->budget--) { s->failed_pc=0x0c065baeu; return 0; }
r[12]+=0x00000001u;
goto P_0c065bb0;
P_0c065bb0: /* original 4208, guest PC 0x0c065bb0 */
if(!s->budget--) { s->failed_pc=0x0c065bb0u; return 0; }
r[2]<<=2;
goto P_0c065bb2;
P_0c065bb2: /* original 0236, guest PC 0x0c065bb2 */
if(!s->budget--) { s->failed_pc=0x0c065bb2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065bb4;
P_0c065bb4: /* original 67b2, guest PC 0x0c065bb4 */
if(!s->budget--) { s->failed_pc=0x0c065bb4u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c065bb6;
P_0c065bb6: /* original 65c3, guest PC 0x0c065bb6 */
if(!s->budget--) { s->failed_pc=0x0c065bb6u; return 0; }
r[5]=r[12];
goto P_0c065bb8;
P_0c065bb8: /* original d31f, guest PC 0x0c065bb8 */
if(!s->budget--) { s->failed_pc=0x0c065bb8u; return 0; }
r[3]=read(ram,0x0c065c38u,4);
goto P_0c065bba;
P_0c065bba: /* original 2f72, guest PC 0x0c065bba */
if(!s->budget--) { s->failed_pc=0x0c065bbau; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065bbc;
P_0c065bbc: /* original 5775, guest PC 0x0c065bbc */
if(!s->budget--) { s->failed_pc=0x0c065bbcu; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065bbe;
P_0c065bbe: /* original 66f2, guest PC 0x0c065bbe */
if(!s->budget--) { s->failed_pc=0x0c065bbeu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065bc0;
P_0c065bc0: /* original 5664, guest PC 0x0c065bc0 */
if(!s->budget--) { s->failed_pc=0x0c065bc0u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065bc2;
P_0c065bc2: /* original 430b, guest PC 0x0c065bc2 */
if(!s->budget--) { s->failed_pc=0x0c065bc2u; return 0; }
target=r[3];
r[16]=0x0c065bc6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065bc6u) { target=s->pc; goto dispatch; }
goto P_0c065bc6;
P_0c065bc4: /* original 64e3, guest PC 0x0c065bc4 */
if(!s->budget--) { s->failed_pc=0x0c065bc4u; return 0; }
r[4]=r[14];
goto P_0c065bc6;
P_0c065bc6: /* original 6c03, guest PC 0x0c065bc6 */
if(!s->budget--) { s->failed_pc=0x0c065bc6u; return 0; }
r[12]=r[0];
goto P_0c065bc8;
P_0c065bc8: /* original 63b2, guest PC 0x0c065bc8 */
if(!s->budget--) { s->failed_pc=0x0c065bc8u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c065bca;
P_0c065bca: /* original 62c3, guest PC 0x0c065bca */
if(!s->budget--) { s->failed_pc=0x0c065bcau; return 0; }
r[2]=r[12];
goto P_0c065bcc;
P_0c065bcc: /* original d014, guest PC 0x0c065bcc */
if(!s->budget--) { s->failed_pc=0x0c065bccu; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065bce;
P_0c065bce: /* original 7c01, guest PC 0x0c065bce */
if(!s->budget--) { s->failed_pc=0x0c065bceu; return 0; }
r[12]+=0x00000001u;
goto P_0c065bd0;
P_0c065bd0: /* original 5136, guest PC 0x0c065bd0 */
if(!s->budget--) { s->failed_pc=0x0c065bd0u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065bd2;
P_0c065bd2: /* original 4208, guest PC 0x0c065bd2 */
if(!s->budget--) { s->failed_pc=0x0c065bd2u; return 0; }
r[2]<<=2;
goto P_0c065bd4;
P_0c065bd4: /* original 0216, guest PC 0x0c065bd4 */
if(!s->budget--) { s->failed_pc=0x0c065bd4u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065bd6;
P_0c065bd6: /* original 65c3, guest PC 0x0c065bd6 */
if(!s->budget--) { s->failed_pc=0x0c065bd6u; return 0; }
r[5]=r[12];
goto P_0c065bd8;
P_0c065bd8: /* original d318, guest PC 0x0c065bd8 */
if(!s->budget--) { s->failed_pc=0x0c065bd8u; return 0; }
r[3]=read(ram,0x0c065c3cu,4);
goto P_0c065bda;
P_0c065bda: /* original 66b2, guest PC 0x0c065bda */
if(!s->budget--) { s->failed_pc=0x0c065bdau; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c065bdc;
P_0c065bdc: /* original 5667, guest PC 0x0c065bdc */
if(!s->budget--) { s->failed_pc=0x0c065bdcu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065bde;
P_0c065bde: /* original 430b, guest PC 0x0c065bde */
if(!s->budget--) { s->failed_pc=0x0c065bdeu; return 0; }
target=r[3];
r[16]=0x0c065be2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065be2u) { target=s->pc; goto dispatch; }
goto P_0c065be2;
P_0c065be0: /* original 64e3, guest PC 0x0c065be0 */
if(!s->budget--) { s->failed_pc=0x0c065be0u; return 0; }
r[4]=r[14];
goto P_0c065be2;
P_0c065be2: /* original 6403, guest PC 0x0c065be2 */
if(!s->budget--) { s->failed_pc=0x0c065be2u; return 0; }
r[4]=r[0];
goto P_0c065be4;
P_0c065be4: /* original d210, guest PC 0x0c065be4 */
if(!s->budget--) { s->failed_pc=0x0c065be4u; return 0; }
r[2]=read(ram,0x0c065c28u,4);
goto P_0c065be6;
P_0c065be6: /* original 4408, guest PC 0x0c065be6 */
if(!s->budget--) { s->failed_pc=0x0c065be6u; return 0; }
r[4]<<=2;
goto P_0c065be8;
P_0c065be8: /* original 2242, guest PC 0x0c065be8 */
if(!s->budget--) { s->failed_pc=0x0c065be8u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c065bea;
P_0c065bea: /* original d310, guest PC 0x0c065bea */
if(!s->budget--) { s->failed_pc=0x0c065beau; return 0; }
r[3]=read(ram,0x0c065c2cu,4);
goto P_0c065bec;
P_0c065bec: /* original 430b, guest PC 0x0c065bec */
if(!s->budget--) { s->failed_pc=0x0c065becu; return 0; }
target=r[3];
r[16]=0x0c065bf0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065bf0u) { target=s->pc; goto dispatch; }
goto P_0c065bf0;
P_0c065bee: /* original 64e3, guest PC 0x0c065bee */
if(!s->budget--) { s->failed_pc=0x0c065beeu; return 0; }
r[4]=r[14];
goto P_0c065bf0;
P_0c065bf0: /* original d20f, guest PC 0x0c065bf0 */
if(!s->budget--) { s->failed_pc=0x0c065bf0u; return 0; }
r[2]=read(ram,0x0c065c30u,4);
goto P_0c065bf2;
P_0c065bf2: /* original 6403, guest PC 0x0c065bf2 */
if(!s->budget--) { s->failed_pc=0x0c065bf2u; return 0; }
r[4]=r[0];
goto P_0c065bf4;
P_0c065bf4: /* original e500, guest PC 0x0c065bf4 */
if(!s->budget--) { s->failed_pc=0x0c065bf4u; return 0; }
r[5]=0x00000000u;
goto P_0c065bf6;
P_0c065bf6: /* original 420b, guest PC 0x0c065bf6 */
if(!s->budget--) { s->failed_pc=0x0c065bf6u; return 0; }
target=r[2];
r[16]=0x0c065bfau;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065bfau) { target=s->pc; goto dispatch; }
goto P_0c065bfa;
P_0c065bf8: /* original 6653, guest PC 0x0c065bf8 */
if(!s->budget--) { s->failed_pc=0x0c065bf8u; return 0; }
r[6]=r[5];
goto P_0c065bfa;
P_0c065bfa: /* original 62d2, guest PC 0x0c065bfa */
if(!s->budget--) { s->failed_pc=0x0c065bfau; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065bfc;
P_0c065bfc: /* original d10d, guest PC 0x0c065bfc */
if(!s->budget--) { s->failed_pc=0x0c065bfcu; return 0; }
r[1]=read(ram,0x0c065c34u,4);
goto P_0c065bfe;
P_0c065bfe: /* original 5323, guest PC 0x0c065bfe */
if(!s->budget--) { s->failed_pc=0x0c065bfeu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c065c00;
P_0c065c00: /* original 2132, guest PC 0x0c065c00 */
if(!s->budget--) { s->failed_pc=0x0c065c00u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c065c02;
P_0c065c02: /* original e000, guest PC 0x0c065c02 */
if(!s->budget--) { s->failed_pc=0x0c065c02u; return 0; }
r[0]=0x00000000u;
goto P_0c065c04;
P_0c065c04: /* original 7f10, guest PC 0x0c065c04 */
if(!s->budget--) { s->failed_pc=0x0c065c04u; return 0; }
r[15]+=0x00000010u;
goto P_0c065c06;
P_0c065c06: /* original 4f26, guest PC 0x0c065c06 */
if(!s->budget--) { s->failed_pc=0x0c065c06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065c08;
P_0c065c08: /* original 6af6, guest PC 0x0c065c08 */
if(!s->budget--) { s->failed_pc=0x0c065c08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c065c0a;
P_0c065c0a: /* original 6bf6, guest PC 0x0c065c0a */
if(!s->budget--) { s->failed_pc=0x0c065c0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c065c0c;
P_0c065c0c: /* original 6cf6, guest PC 0x0c065c0c */
if(!s->budget--) { s->failed_pc=0x0c065c0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c065c0e;
P_0c065c0e: /* original 6df6, guest PC 0x0c065c0e */
if(!s->budget--) { s->failed_pc=0x0c065c0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c065c10;
P_0c065c10: /* original 000b, guest PC 0x0c065c10 */
if(!s->budget--) { s->failed_pc=0x0c065c10u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c065c12: /* original 6ef6, guest PC 0x0c065c12 */
if(!s->budget--) { s->failed_pc=0x0c065c12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c065c14u,s,ram);
P_0c065c4c: /* original 4f22, guest PC 0x0c065c4c */
if(!s->budget--) { s->failed_pc=0x0c065c4cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c065c4e;
P_0c065c4e: /* original 7ff4, guest PC 0x0c065c4e */
if(!s->budget--) { s->failed_pc=0x0c065c4eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c065c50;
P_0c065c50: /* original 6342, guest PC 0x0c065c50 */
if(!s->budget--) { s->failed_pc=0x0c065c50u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065c52;
P_0c065c52: /* original 65f3, guest PC 0x0c065c52 */
if(!s->budget--) { s->failed_pc=0x0c065c52u; return 0; }
r[5]=r[15];
goto P_0c065c54;
P_0c065c54: /* original 6e53, guest PC 0x0c065c54 */
if(!s->budget--) { s->failed_pc=0x0c065c54u; return 0; }
r[14]=r[5];
goto P_0c065c56;
P_0c065c56: /* original 6ae3, guest PC 0x0c065c56 */
if(!s->budget--) { s->failed_pc=0x0c065c56u; return 0; }
r[10]=r[14];
goto P_0c065c58;
P_0c065c58: /* original 2e32, guest PC 0x0c065c58 */
if(!s->budget--) { s->failed_pc=0x0c065c58u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c065c5a;
P_0c065c5a: /* original 6be3, guest PC 0x0c065c5a */
if(!s->budget--) { s->failed_pc=0x0c065c5au; return 0; }
r[11]=r[14];
goto P_0c065c5c;
P_0c065c5c: /* original 5241, guest PC 0x0c065c5c */
if(!s->budget--) { s->failed_pc=0x0c065c5cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c065c5e;
P_0c065c5e: /* original 7a04, guest PC 0x0c065c5e */
if(!s->budget--) { s->failed_pc=0x0c065c5eu; return 0; }
r[10]+=0x00000004u;
goto P_0c065c60;
P_0c065c60: /* original 2a22, guest PC 0x0c065c60 */
if(!s->budget--) { s->failed_pc=0x0c065c60u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c065c62;
P_0c065c62: /* original 7b08, guest PC 0x0c065c62 */
if(!s->budget--) { s->failed_pc=0x0c065c62u; return 0; }
r[11]+=0x00000008u;
goto P_0c065c64;
P_0c065c64: /* original 5342, guest PC 0x0c065c64 */
if(!s->budget--) { s->failed_pc=0x0c065c64u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065c66;
P_0c065c66: /* original 2b32, guest PC 0x0c065c66 */
if(!s->budget--) { s->failed_pc=0x0c065c66u; return 0; }
write(ram,r[11],r[3],4);
goto P_0c065c68;
P_0c065c68: /* original d250, guest PC 0x0c065c68 */
if(!s->budget--) { s->failed_pc=0x0c065c68u; return 0; }
r[2]=read(ram,0x0c065dacu,4);
goto P_0c065c6a;
P_0c065c6a: /* original 6d22, guest PC 0x0c065c6a */
if(!s->budget--) { s->failed_pc=0x0c065c6au; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c065c6c;
P_0c065c6c: /* original d350, guest PC 0x0c065c6c */
if(!s->budget--) { s->failed_pc=0x0c065c6cu; return 0; }
r[3]=read(ram,0x0c065db0u,4);
goto P_0c065c6e;
P_0c065c6e: /* original 6432, guest PC 0x0c065c6e */
if(!s->budget--) { s->failed_pc=0x0c065c6eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c065c70;
P_0c065c70: /* original d150, guest PC 0x0c065c70 */
if(!s->budget--) { s->failed_pc=0x0c065c70u; return 0; }
r[1]=read(ram,0x0c065db4u,4);
goto P_0c065c72;
P_0c065c72: /* original 6512, guest PC 0x0c065c72 */
if(!s->budget--) { s->failed_pc=0x0c065c72u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c065c74;
P_0c065c74: /* original d050, guest PC 0x0c065c74 */
if(!s->budget--) { s->failed_pc=0x0c065c74u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065c76;
P_0c065c76: /* original 62c3, guest PC 0x0c065c76 */
if(!s->budget--) { s->failed_pc=0x0c065c76u; return 0; }
r[2]=r[12];
goto P_0c065c78;
P_0c065c78: /* original 7c01, guest PC 0x0c065c78 */
if(!s->budget--) { s->failed_pc=0x0c065c78u; return 0; }
r[12]+=0x00000001u;
goto P_0c065c7a;
P_0c065c7a: /* original 4208, guest PC 0x0c065c7a */
if(!s->budget--) { s->failed_pc=0x0c065c7au; return 0; }
r[2]<<=2;
goto P_0c065c7c;
P_0c065c7c: /* original 02d6, guest PC 0x0c065c7c */
if(!s->budget--) { s->failed_pc=0x0c065c7cu; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065c7e;
P_0c065c7e: /* original 63c3, guest PC 0x0c065c7e */
if(!s->budget--) { s->failed_pc=0x0c065c7eu; return 0; }
r[3]=r[12];
goto P_0c065c80;
P_0c065c80: /* original 7c01, guest PC 0x0c065c80 */
if(!s->budget--) { s->failed_pc=0x0c065c80u; return 0; }
r[12]+=0x00000001u;
goto P_0c065c82;
P_0c065c82: /* original 4308, guest PC 0x0c065c82 */
if(!s->budget--) { s->failed_pc=0x0c065c82u; return 0; }
r[3]<<=2;
goto P_0c065c84;
P_0c065c84: /* original 0346, guest PC 0x0c065c84 */
if(!s->budget--) { s->failed_pc=0x0c065c84u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c065c86;
P_0c065c86: /* original 62c3, guest PC 0x0c065c86 */
if(!s->budget--) { s->failed_pc=0x0c065c86u; return 0; }
r[2]=r[12];
goto P_0c065c88;
P_0c065c88: /* original 7c01, guest PC 0x0c065c88 */
if(!s->budget--) { s->failed_pc=0x0c065c88u; return 0; }
r[12]+=0x00000001u;
goto P_0c065c8a;
P_0c065c8a: /* original 4208, guest PC 0x0c065c8a */
if(!s->budget--) { s->failed_pc=0x0c065c8au; return 0; }
r[2]<<=2;
goto P_0c065c8c;
P_0c065c8c: /* original 0256, guest PC 0x0c065c8c */
if(!s->budget--) { s->failed_pc=0x0c065c8cu; return 0; }
write(ram,r[2]+r[0],r[5],4);
goto P_0c065c8e;
P_0c065c8e: /* original 63c3, guest PC 0x0c065c8e */
if(!s->budget--) { s->failed_pc=0x0c065c8eu; return 0; }
r[3]=r[12];
goto P_0c065c90;
P_0c065c90: /* original 62e2, guest PC 0x0c065c90 */
if(!s->budget--) { s->failed_pc=0x0c065c90u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065c92;
P_0c065c92: /* original 7c01, guest PC 0x0c065c92 */
if(!s->budget--) { s->failed_pc=0x0c065c92u; return 0; }
r[12]+=0x00000001u;
goto P_0c065c94;
P_0c065c94: /* original 5221, guest PC 0x0c065c94 */
if(!s->budget--) { s->failed_pc=0x0c065c94u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c065c96;
P_0c065c96: /* original 4308, guest PC 0x0c065c96 */
if(!s->budget--) { s->failed_pc=0x0c065c96u; return 0; }
r[3]<<=2;
goto P_0c065c98;
P_0c065c98: /* original 0326, guest PC 0x0c065c98 */
if(!s->budget--) { s->failed_pc=0x0c065c98u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065c9a;
P_0c065c9a: /* original 63c3, guest PC 0x0c065c9a */
if(!s->budget--) { s->failed_pc=0x0c065c9au; return 0; }
r[3]=r[12];
goto P_0c065c9c;
P_0c065c9c: /* original 62e2, guest PC 0x0c065c9c */
if(!s->budget--) { s->failed_pc=0x0c065c9cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065c9e;
P_0c065c9e: /* original 7c01, guest PC 0x0c065c9e */
if(!s->budget--) { s->failed_pc=0x0c065c9eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065ca0;
P_0c065ca0: /* original 5222, guest PC 0x0c065ca0 */
if(!s->budget--) { s->failed_pc=0x0c065ca0u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c065ca2;
P_0c065ca2: /* original 4308, guest PC 0x0c065ca2 */
if(!s->budget--) { s->failed_pc=0x0c065ca2u; return 0; }
r[3]<<=2;
goto P_0c065ca4;
P_0c065ca4: /* original 0326, guest PC 0x0c065ca4 */
if(!s->budget--) { s->failed_pc=0x0c065ca4u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065ca6;
P_0c065ca6: /* original 63c3, guest PC 0x0c065ca6 */
if(!s->budget--) { s->failed_pc=0x0c065ca6u; return 0; }
r[3]=r[12];
goto P_0c065ca8;
P_0c065ca8: /* original 62e2, guest PC 0x0c065ca8 */
if(!s->budget--) { s->failed_pc=0x0c065ca8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065caa;
P_0c065caa: /* original 7c01, guest PC 0x0c065caa */
if(!s->budget--) { s->failed_pc=0x0c065caau; return 0; }
r[12]+=0x00000001u;
goto P_0c065cac;
P_0c065cac: /* original 5223, guest PC 0x0c065cac */
if(!s->budget--) { s->failed_pc=0x0c065cacu; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c065cae;
P_0c065cae: /* original 4308, guest PC 0x0c065cae */
if(!s->budget--) { s->failed_pc=0x0c065caeu; return 0; }
r[3]<<=2;
goto P_0c065cb0;
P_0c065cb0: /* original 0326, guest PC 0x0c065cb0 */
if(!s->budget--) { s->failed_pc=0x0c065cb0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065cb2;
P_0c065cb2: /* original 65c3, guest PC 0x0c065cb2 */
if(!s->budget--) { s->failed_pc=0x0c065cb2u; return 0; }
r[5]=r[12];
goto P_0c065cb4;
P_0c065cb4: /* original d341, guest PC 0x0c065cb4 */
if(!s->budget--) { s->failed_pc=0x0c065cb4u; return 0; }
r[3]=read(ram,0x0c065dbcu,4);
goto P_0c065cb6;
P_0c065cb6: /* original 66e2, guest PC 0x0c065cb6 */
if(!s->budget--) { s->failed_pc=0x0c065cb6u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c065cb8;
P_0c065cb8: /* original 5664, guest PC 0x0c065cb8 */
if(!s->budget--) { s->failed_pc=0x0c065cb8u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065cba;
P_0c065cba: /* original 430b, guest PC 0x0c065cba */
if(!s->budget--) { s->failed_pc=0x0c065cbau; return 0; }
target=r[3];
r[16]=0x0c065cbeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065cbeu) { target=s->pc; goto dispatch; }
goto P_0c065cbe;
P_0c065cbc: /* original 64d3, guest PC 0x0c065cbc */
if(!s->budget--) { s->failed_pc=0x0c065cbcu; return 0; }
r[4]=r[13];
goto P_0c065cbe;
P_0c065cbe: /* original 6c03, guest PC 0x0c065cbe */
if(!s->budget--) { s->failed_pc=0x0c065cbeu; return 0; }
r[12]=r[0];
goto P_0c065cc0;
P_0c065cc0: /* original 63e2, guest PC 0x0c065cc0 */
if(!s->budget--) { s->failed_pc=0x0c065cc0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c065cc2;
P_0c065cc2: /* original 62c3, guest PC 0x0c065cc2 */
if(!s->budget--) { s->failed_pc=0x0c065cc2u; return 0; }
r[2]=r[12];
goto P_0c065cc4;
P_0c065cc4: /* original d03c, guest PC 0x0c065cc4 */
if(!s->budget--) { s->failed_pc=0x0c065cc4u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065cc6;
P_0c065cc6: /* original 7c01, guest PC 0x0c065cc6 */
if(!s->budget--) { s->failed_pc=0x0c065cc6u; return 0; }
r[12]+=0x00000001u;
goto P_0c065cc8;
P_0c065cc8: /* original 5136, guest PC 0x0c065cc8 */
if(!s->budget--) { s->failed_pc=0x0c065cc8u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065cca;
P_0c065cca: /* original 4208, guest PC 0x0c065cca */
if(!s->budget--) { s->failed_pc=0x0c065ccau; return 0; }
r[2]<<=2;
goto P_0c065ccc;
P_0c065ccc: /* original 0216, guest PC 0x0c065ccc */
if(!s->budget--) { s->failed_pc=0x0c065cccu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065cce;
P_0c065cce: /* original 65c3, guest PC 0x0c065cce */
if(!s->budget--) { s->failed_pc=0x0c065cceu; return 0; }
r[5]=r[12];
goto P_0c065cd0;
P_0c065cd0: /* original d33b, guest PC 0x0c065cd0 */
if(!s->budget--) { s->failed_pc=0x0c065cd0u; return 0; }
r[3]=read(ram,0x0c065dc0u,4);
goto P_0c065cd2;
P_0c065cd2: /* original 66e2, guest PC 0x0c065cd2 */
if(!s->budget--) { s->failed_pc=0x0c065cd2u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c065cd4;
P_0c065cd4: /* original 5667, guest PC 0x0c065cd4 */
if(!s->budget--) { s->failed_pc=0x0c065cd4u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065cd6;
P_0c065cd6: /* original 430b, guest PC 0x0c065cd6 */
if(!s->budget--) { s->failed_pc=0x0c065cd6u; return 0; }
target=r[3];
r[16]=0x0c065cdau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065cdau) { target=s->pc; goto dispatch; }
goto P_0c065cda;
P_0c065cd8: /* original 64d3, guest PC 0x0c065cd8 */
if(!s->budget--) { s->failed_pc=0x0c065cd8u; return 0; }
r[4]=r[13];
goto P_0c065cda;
P_0c065cda: /* original 6c03, guest PC 0x0c065cda */
if(!s->budget--) { s->failed_pc=0x0c065cdau; return 0; }
r[12]=r[0];
goto P_0c065cdc;
P_0c065cdc: /* original 61a2, guest PC 0x0c065cdc */
if(!s->budget--) { s->failed_pc=0x0c065cdcu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065cde;
P_0c065cde: /* original 62c3, guest PC 0x0c065cde */
if(!s->budget--) { s->failed_pc=0x0c065cdeu; return 0; }
r[2]=r[12];
goto P_0c065ce0;
P_0c065ce0: /* original d035, guest PC 0x0c065ce0 */
if(!s->budget--) { s->failed_pc=0x0c065ce0u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065ce2;
P_0c065ce2: /* original 7c01, guest PC 0x0c065ce2 */
if(!s->budget--) { s->failed_pc=0x0c065ce2u; return 0; }
r[12]+=0x00000001u;
goto P_0c065ce4;
P_0c065ce4: /* original 5311, guest PC 0x0c065ce4 */
if(!s->budget--) { s->failed_pc=0x0c065ce4u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065ce6;
P_0c065ce6: /* original 4208, guest PC 0x0c065ce6 */
if(!s->budget--) { s->failed_pc=0x0c065ce6u; return 0; }
r[2]<<=2;
goto P_0c065ce8;
P_0c065ce8: /* original 0236, guest PC 0x0c065ce8 */
if(!s->budget--) { s->failed_pc=0x0c065ce8u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065cea;
P_0c065cea: /* original 62c3, guest PC 0x0c065cea */
if(!s->budget--) { s->failed_pc=0x0c065ceau; return 0; }
r[2]=r[12];
goto P_0c065cec;
P_0c065cec: /* original 61a2, guest PC 0x0c065cec */
if(!s->budget--) { s->failed_pc=0x0c065cecu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065cee;
P_0c065cee: /* original 7c01, guest PC 0x0c065cee */
if(!s->budget--) { s->failed_pc=0x0c065ceeu; return 0; }
r[12]+=0x00000001u;
goto P_0c065cf0;
P_0c065cf0: /* original 5312, guest PC 0x0c065cf0 */
if(!s->budget--) { s->failed_pc=0x0c065cf0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065cf2;
P_0c065cf2: /* original 4208, guest PC 0x0c065cf2 */
if(!s->budget--) { s->failed_pc=0x0c065cf2u; return 0; }
r[2]<<=2;
goto P_0c065cf4;
P_0c065cf4: /* original 0236, guest PC 0x0c065cf4 */
if(!s->budget--) { s->failed_pc=0x0c065cf4u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065cf6;
P_0c065cf6: /* original 62c3, guest PC 0x0c065cf6 */
if(!s->budget--) { s->failed_pc=0x0c065cf6u; return 0; }
r[2]=r[12];
goto P_0c065cf8;
P_0c065cf8: /* original 61a2, guest PC 0x0c065cf8 */
if(!s->budget--) { s->failed_pc=0x0c065cf8u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065cfa;
P_0c065cfa: /* original 7c01, guest PC 0x0c065cfa */
if(!s->budget--) { s->failed_pc=0x0c065cfau; return 0; }
r[12]+=0x00000001u;
goto P_0c065cfc;
P_0c065cfc: /* original 5313, guest PC 0x0c065cfc */
if(!s->budget--) { s->failed_pc=0x0c065cfcu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065cfe;
P_0c065cfe: /* original 4208, guest PC 0x0c065cfe */
if(!s->budget--) { s->failed_pc=0x0c065cfeu; return 0; }
r[2]<<=2;
goto P_0c065d00;
P_0c065d00: /* original 0236, guest PC 0x0c065d00 */
if(!s->budget--) { s->failed_pc=0x0c065d00u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065d02;
P_0c065d02: /* original 65c3, guest PC 0x0c065d02 */
if(!s->budget--) { s->failed_pc=0x0c065d02u; return 0; }
r[5]=r[12];
goto P_0c065d04;
P_0c065d04: /* original d32d, guest PC 0x0c065d04 */
if(!s->budget--) { s->failed_pc=0x0c065d04u; return 0; }
r[3]=read(ram,0x0c065dbcu,4);
goto P_0c065d06;
P_0c065d06: /* original 66e2, guest PC 0x0c065d06 */
if(!s->budget--) { s->failed_pc=0x0c065d06u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c065d08;
P_0c065d08: /* original 5664, guest PC 0x0c065d08 */
if(!s->budget--) { s->failed_pc=0x0c065d08u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065d0a;
P_0c065d0a: /* original 430b, guest PC 0x0c065d0a */
if(!s->budget--) { s->failed_pc=0x0c065d0au; return 0; }
target=r[3];
r[16]=0x0c065d0eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065d0eu) { target=s->pc; goto dispatch; }
goto P_0c065d0e;
P_0c065d0c: /* original 64d3, guest PC 0x0c065d0c */
if(!s->budget--) { s->failed_pc=0x0c065d0cu; return 0; }
r[4]=r[13];
goto P_0c065d0e;
P_0c065d0e: /* original 6c03, guest PC 0x0c065d0e */
if(!s->budget--) { s->failed_pc=0x0c065d0eu; return 0; }
r[12]=r[0];
goto P_0c065d10;
P_0c065d10: /* original 63a2, guest PC 0x0c065d10 */
if(!s->budget--) { s->failed_pc=0x0c065d10u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c065d12;
P_0c065d12: /* original 62c3, guest PC 0x0c065d12 */
if(!s->budget--) { s->failed_pc=0x0c065d12u; return 0; }
r[2]=r[12];
goto P_0c065d14;
P_0c065d14: /* original d028, guest PC 0x0c065d14 */
if(!s->budget--) { s->failed_pc=0x0c065d14u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065d16;
P_0c065d16: /* original 7c01, guest PC 0x0c065d16 */
if(!s->budget--) { s->failed_pc=0x0c065d16u; return 0; }
r[12]+=0x00000001u;
goto P_0c065d18;
P_0c065d18: /* original 5136, guest PC 0x0c065d18 */
if(!s->budget--) { s->failed_pc=0x0c065d18u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065d1a;
P_0c065d1a: /* original 4208, guest PC 0x0c065d1a */
if(!s->budget--) { s->failed_pc=0x0c065d1au; return 0; }
r[2]<<=2;
goto P_0c065d1c;
P_0c065d1c: /* original 0216, guest PC 0x0c065d1c */
if(!s->budget--) { s->failed_pc=0x0c065d1cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065d1e;
P_0c065d1e: /* original 65c3, guest PC 0x0c065d1e */
if(!s->budget--) { s->failed_pc=0x0c065d1eu; return 0; }
r[5]=r[12];
goto P_0c065d20;
P_0c065d20: /* original d327, guest PC 0x0c065d20 */
if(!s->budget--) { s->failed_pc=0x0c065d20u; return 0; }
r[3]=read(ram,0x0c065dc0u,4);
goto P_0c065d22;
P_0c065d22: /* original 66a2, guest PC 0x0c065d22 */
if(!s->budget--) { s->failed_pc=0x0c065d22u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c065d24;
P_0c065d24: /* original 5667, guest PC 0x0c065d24 */
if(!s->budget--) { s->failed_pc=0x0c065d24u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065d26;
P_0c065d26: /* original 430b, guest PC 0x0c065d26 */
if(!s->budget--) { s->failed_pc=0x0c065d26u; return 0; }
target=r[3];
r[16]=0x0c065d2au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065d2au) { target=s->pc; goto dispatch; }
goto P_0c065d2a;
P_0c065d28: /* original 64d3, guest PC 0x0c065d28 */
if(!s->budget--) { s->failed_pc=0x0c065d28u; return 0; }
r[4]=r[13];
goto P_0c065d2a;
P_0c065d2a: /* original 6c03, guest PC 0x0c065d2a */
if(!s->budget--) { s->failed_pc=0x0c065d2au; return 0; }
r[12]=r[0];
goto P_0c065d2c;
P_0c065d2c: /* original 61b2, guest PC 0x0c065d2c */
if(!s->budget--) { s->failed_pc=0x0c065d2cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065d2e;
P_0c065d2e: /* original 62c3, guest PC 0x0c065d2e */
if(!s->budget--) { s->failed_pc=0x0c065d2eu; return 0; }
r[2]=r[12];
goto P_0c065d30;
P_0c065d30: /* original d021, guest PC 0x0c065d30 */
if(!s->budget--) { s->failed_pc=0x0c065d30u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065d32;
P_0c065d32: /* original 7c01, guest PC 0x0c065d32 */
if(!s->budget--) { s->failed_pc=0x0c065d32u; return 0; }
r[12]+=0x00000001u;
goto P_0c065d34;
P_0c065d34: /* original 5311, guest PC 0x0c065d34 */
if(!s->budget--) { s->failed_pc=0x0c065d34u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065d36;
P_0c065d36: /* original 4208, guest PC 0x0c065d36 */
if(!s->budget--) { s->failed_pc=0x0c065d36u; return 0; }
r[2]<<=2;
goto P_0c065d38;
P_0c065d38: /* original 0236, guest PC 0x0c065d38 */
if(!s->budget--) { s->failed_pc=0x0c065d38u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065d3a;
P_0c065d3a: /* original 62c3, guest PC 0x0c065d3a */
if(!s->budget--) { s->failed_pc=0x0c065d3au; return 0; }
r[2]=r[12];
goto P_0c065d3c;
P_0c065d3c: /* original 61b2, guest PC 0x0c065d3c */
if(!s->budget--) { s->failed_pc=0x0c065d3cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065d3e;
P_0c065d3e: /* original 7c01, guest PC 0x0c065d3e */
if(!s->budget--) { s->failed_pc=0x0c065d3eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065d40;
P_0c065d40: /* original 5312, guest PC 0x0c065d40 */
if(!s->budget--) { s->failed_pc=0x0c065d40u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065d42;
P_0c065d42: /* original 4208, guest PC 0x0c065d42 */
if(!s->budget--) { s->failed_pc=0x0c065d42u; return 0; }
r[2]<<=2;
goto P_0c065d44;
P_0c065d44: /* original 0236, guest PC 0x0c065d44 */
if(!s->budget--) { s->failed_pc=0x0c065d44u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065d46;
P_0c065d46: /* original 62c3, guest PC 0x0c065d46 */
if(!s->budget--) { s->failed_pc=0x0c065d46u; return 0; }
r[2]=r[12];
goto P_0c065d48;
P_0c065d48: /* original 61b2, guest PC 0x0c065d48 */
if(!s->budget--) { s->failed_pc=0x0c065d48u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065d4a;
P_0c065d4a: /* original 7c01, guest PC 0x0c065d4a */
if(!s->budget--) { s->failed_pc=0x0c065d4au; return 0; }
r[12]+=0x00000001u;
goto P_0c065d4c;
P_0c065d4c: /* original 5313, guest PC 0x0c065d4c */
if(!s->budget--) { s->failed_pc=0x0c065d4cu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065d4e;
P_0c065d4e: /* original 4208, guest PC 0x0c065d4e */
if(!s->budget--) { s->failed_pc=0x0c065d4eu; return 0; }
r[2]<<=2;
goto P_0c065d50;
P_0c065d50: /* original 0236, guest PC 0x0c065d50 */
if(!s->budget--) { s->failed_pc=0x0c065d50u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065d52;
P_0c065d52: /* original 65c3, guest PC 0x0c065d52 */
if(!s->budget--) { s->failed_pc=0x0c065d52u; return 0; }
r[5]=r[12];
goto P_0c065d54;
P_0c065d54: /* original d319, guest PC 0x0c065d54 */
if(!s->budget--) { s->failed_pc=0x0c065d54u; return 0; }
r[3]=read(ram,0x0c065dbcu,4);
goto P_0c065d56;
P_0c065d56: /* original 66b2, guest PC 0x0c065d56 */
if(!s->budget--) { s->failed_pc=0x0c065d56u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c065d58;
P_0c065d58: /* original 5664, guest PC 0x0c065d58 */
if(!s->budget--) { s->failed_pc=0x0c065d58u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065d5a;
P_0c065d5a: /* original 430b, guest PC 0x0c065d5a */
if(!s->budget--) { s->failed_pc=0x0c065d5au; return 0; }
target=r[3];
r[16]=0x0c065d5eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065d5eu) { target=s->pc; goto dispatch; }
goto P_0c065d5e;
P_0c065d5c: /* original 64d3, guest PC 0x0c065d5c */
if(!s->budget--) { s->failed_pc=0x0c065d5cu; return 0; }
r[4]=r[13];
goto P_0c065d5e;
P_0c065d5e: /* original 6c03, guest PC 0x0c065d5e */
if(!s->budget--) { s->failed_pc=0x0c065d5eu; return 0; }
r[12]=r[0];
goto P_0c065d60;
P_0c065d60: /* original 63b2, guest PC 0x0c065d60 */
if(!s->budget--) { s->failed_pc=0x0c065d60u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c065d62;
P_0c065d62: /* original 62c3, guest PC 0x0c065d62 */
if(!s->budget--) { s->failed_pc=0x0c065d62u; return 0; }
r[2]=r[12];
goto P_0c065d64;
P_0c065d64: /* original d014, guest PC 0x0c065d64 */
if(!s->budget--) { s->failed_pc=0x0c065d64u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065d66;
P_0c065d66: /* original 7c01, guest PC 0x0c065d66 */
if(!s->budget--) { s->failed_pc=0x0c065d66u; return 0; }
r[12]+=0x00000001u;
goto P_0c065d68;
P_0c065d68: /* original 5136, guest PC 0x0c065d68 */
if(!s->budget--) { s->failed_pc=0x0c065d68u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065d6a;
P_0c065d6a: /* original 4208, guest PC 0x0c065d6a */
if(!s->budget--) { s->failed_pc=0x0c065d6au; return 0; }
r[2]<<=2;
goto P_0c065d6c;
P_0c065d6c: /* original 0216, guest PC 0x0c065d6c */
if(!s->budget--) { s->failed_pc=0x0c065d6cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065d6e;
P_0c065d6e: /* original 65c3, guest PC 0x0c065d6e */
if(!s->budget--) { s->failed_pc=0x0c065d6eu; return 0; }
r[5]=r[12];
goto P_0c065d70;
P_0c065d70: /* original d313, guest PC 0x0c065d70 */
if(!s->budget--) { s->failed_pc=0x0c065d70u; return 0; }
r[3]=read(ram,0x0c065dc0u,4);
goto P_0c065d72;
P_0c065d72: /* original 66b2, guest PC 0x0c065d72 */
if(!s->budget--) { s->failed_pc=0x0c065d72u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c065d74;
P_0c065d74: /* original 5667, guest PC 0x0c065d74 */
if(!s->budget--) { s->failed_pc=0x0c065d74u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065d76;
P_0c065d76: /* original 430b, guest PC 0x0c065d76 */
if(!s->budget--) { s->failed_pc=0x0c065d76u; return 0; }
target=r[3];
r[16]=0x0c065d7au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065d7au) { target=s->pc; goto dispatch; }
goto P_0c065d7a;
P_0c065d78: /* original 64d3, guest PC 0x0c065d78 */
if(!s->budget--) { s->failed_pc=0x0c065d78u; return 0; }
r[4]=r[13];
goto P_0c065d7a;
P_0c065d7a: /* original 6403, guest PC 0x0c065d7a */
if(!s->budget--) { s->failed_pc=0x0c065d7au; return 0; }
r[4]=r[0];
goto P_0c065d7c;
P_0c065d7c: /* original d211, guest PC 0x0c065d7c */
if(!s->budget--) { s->failed_pc=0x0c065d7cu; return 0; }
r[2]=read(ram,0x0c065dc4u,4);
goto P_0c065d7e;
P_0c065d7e: /* original 4408, guest PC 0x0c065d7e */
if(!s->budget--) { s->failed_pc=0x0c065d7eu; return 0; }
r[4]<<=2;
goto P_0c065d80;
P_0c065d80: /* original 2242, guest PC 0x0c065d80 */
if(!s->budget--) { s->failed_pc=0x0c065d80u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c065d82;
P_0c065d82: /* original d311, guest PC 0x0c065d82 */
if(!s->budget--) { s->failed_pc=0x0c065d82u; return 0; }
r[3]=read(ram,0x0c065dc8u,4);
goto P_0c065d84;
P_0c065d84: /* original 430b, guest PC 0x0c065d84 */
if(!s->budget--) { s->failed_pc=0x0c065d84u; return 0; }
target=r[3];
r[16]=0x0c065d88u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065d88u) { target=s->pc; goto dispatch; }
goto P_0c065d88;
P_0c065d86: /* original 64d3, guest PC 0x0c065d86 */
if(!s->budget--) { s->failed_pc=0x0c065d86u; return 0; }
r[4]=r[13];
goto P_0c065d88;
P_0c065d88: /* original d210, guest PC 0x0c065d88 */
if(!s->budget--) { s->failed_pc=0x0c065d88u; return 0; }
r[2]=read(ram,0x0c065dccu,4);
goto P_0c065d8a;
P_0c065d8a: /* original 6403, guest PC 0x0c065d8a */
if(!s->budget--) { s->failed_pc=0x0c065d8au; return 0; }
r[4]=r[0];
goto P_0c065d8c;
P_0c065d8c: /* original e500, guest PC 0x0c065d8c */
if(!s->budget--) { s->failed_pc=0x0c065d8cu; return 0; }
r[5]=0x00000000u;
goto P_0c065d8e;
P_0c065d8e: /* original 420b, guest PC 0x0c065d8e */
if(!s->budget--) { s->failed_pc=0x0c065d8eu; return 0; }
target=r[2];
r[16]=0x0c065d92u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065d92u) { target=s->pc; goto dispatch; }
goto P_0c065d92;
P_0c065d90: /* original 6653, guest PC 0x0c065d90 */
if(!s->budget--) { s->failed_pc=0x0c065d90u; return 0; }
r[6]=r[5];
goto P_0c065d92;
P_0c065d92: /* original 62e2, guest PC 0x0c065d92 */
if(!s->budget--) { s->failed_pc=0x0c065d92u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065d94;
P_0c065d94: /* original d10e, guest PC 0x0c065d94 */
if(!s->budget--) { s->failed_pc=0x0c065d94u; return 0; }
r[1]=read(ram,0x0c065dd0u,4);
goto P_0c065d96;
P_0c065d96: /* original 5323, guest PC 0x0c065d96 */
if(!s->budget--) { s->failed_pc=0x0c065d96u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c065d98;
P_0c065d98: /* original 2132, guest PC 0x0c065d98 */
if(!s->budget--) { s->failed_pc=0x0c065d98u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c065d9a;
P_0c065d9a: /* original e000, guest PC 0x0c065d9a */
if(!s->budget--) { s->failed_pc=0x0c065d9au; return 0; }
r[0]=0x00000000u;
goto P_0c065d9c;
P_0c065d9c: /* original 7f0c, guest PC 0x0c065d9c */
if(!s->budget--) { s->failed_pc=0x0c065d9cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c065d9e;
P_0c065d9e: /* original 4f26, guest PC 0x0c065d9e */
if(!s->budget--) { s->failed_pc=0x0c065d9eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065da0;
P_0c065da0: /* original 6af6, guest PC 0x0c065da0 */
if(!s->budget--) { s->failed_pc=0x0c065da0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c065da2;
P_0c065da2: /* original 6bf6, guest PC 0x0c065da2 */
if(!s->budget--) { s->failed_pc=0x0c065da2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c065da4;
P_0c065da4: /* original 6cf6, guest PC 0x0c065da4 */
if(!s->budget--) { s->failed_pc=0x0c065da4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c065da6;
P_0c065da6: /* original 6df6, guest PC 0x0c065da6 */
if(!s->budget--) { s->failed_pc=0x0c065da6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c065da8;
P_0c065da8: /* original 000b, guest PC 0x0c065da8 */
if(!s->budget--) { s->failed_pc=0x0c065da8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c065daa: /* original 6ef6, guest PC 0x0c065daa */
if(!s->budget--) { s->failed_pc=0x0c065daau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c065dacu,s,ram);
P_0c065de4: /* original 4f22, guest PC 0x0c065de4 */
if(!s->budget--) { s->failed_pc=0x0c065de4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c065de6;
P_0c065de6: /* original 7ff0, guest PC 0x0c065de6 */
if(!s->budget--) { s->failed_pc=0x0c065de6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065de8;
P_0c065de8: /* original 6342, guest PC 0x0c065de8 */
if(!s->budget--) { s->failed_pc=0x0c065de8u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065dea;
P_0c065dea: /* original 65f3, guest PC 0x0c065dea */
if(!s->budget--) { s->failed_pc=0x0c065deau; return 0; }
r[5]=r[15];
goto P_0c065dec;
P_0c065dec: /* original 7504, guest PC 0x0c065dec */
if(!s->budget--) { s->failed_pc=0x0c065decu; return 0; }
r[5]+=0x00000004u;
goto P_0c065dee;
P_0c065dee: /* original 6d53, guest PC 0x0c065dee */
if(!s->budget--) { s->failed_pc=0x0c065deeu; return 0; }
r[13]=r[5];
goto P_0c065df0;
P_0c065df0: /* original 2d32, guest PC 0x0c065df0 */
if(!s->budget--) { s->failed_pc=0x0c065df0u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c065df2;
P_0c065df2: /* original 6bd3, guest PC 0x0c065df2 */
if(!s->budget--) { s->failed_pc=0x0c065df2u; return 0; }
r[11]=r[13];
goto P_0c065df4;
P_0c065df4: /* original 5241, guest PC 0x0c065df4 */
if(!s->budget--) { s->failed_pc=0x0c065df4u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c065df6;
P_0c065df6: /* original 6ad3, guest PC 0x0c065df6 */
if(!s->budget--) { s->failed_pc=0x0c065df6u; return 0; }
r[10]=r[13];
goto P_0c065df8;
P_0c065df8: /* original 7b04, guest PC 0x0c065df8 */
if(!s->budget--) { s->failed_pc=0x0c065df8u; return 0; }
r[11]+=0x00000004u;
goto P_0c065dfa;
P_0c065dfa: /* original 7a08, guest PC 0x0c065dfa */
if(!s->budget--) { s->failed_pc=0x0c065dfau; return 0; }
r[10]+=0x00000008u;
goto P_0c065dfc;
P_0c065dfc: /* original 2b22, guest PC 0x0c065dfc */
if(!s->budget--) { s->failed_pc=0x0c065dfcu; return 0; }
write(ram,r[11],r[2],4);
goto P_0c065dfe;
P_0c065dfe: /* original 5342, guest PC 0x0c065dfe */
if(!s->budget--) { s->failed_pc=0x0c065dfeu; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065e00;
P_0c065e00: /* original d283, guest PC 0x0c065e00 */
if(!s->budget--) { s->failed_pc=0x0c065e00u; return 0; }
r[2]=read(ram,0x0c066010u,4);
goto P_0c065e02;
P_0c065e02: /* original 2a32, guest PC 0x0c065e02 */
if(!s->budget--) { s->failed_pc=0x0c065e02u; return 0; }
write(ram,r[10],r[3],4);
goto P_0c065e04;
P_0c065e04: /* original 6e22, guest PC 0x0c065e04 */
if(!s->budget--) { s->failed_pc=0x0c065e04u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c065e06;
P_0c065e06: /* original d383, guest PC 0x0c065e06 */
if(!s->budget--) { s->failed_pc=0x0c065e06u; return 0; }
r[3]=read(ram,0x0c066014u,4);
goto P_0c065e08;
P_0c065e08: /* original 6532, guest PC 0x0c065e08 */
if(!s->budget--) { s->failed_pc=0x0c065e08u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c065e0a;
P_0c065e0a: /* original d183, guest PC 0x0c065e0a */
if(!s->budget--) { s->failed_pc=0x0c065e0au; return 0; }
r[1]=read(ram,0x0c066018u,4);
goto P_0c065e0c;
P_0c065e0c: /* original 6412, guest PC 0x0c065e0c */
if(!s->budget--) { s->failed_pc=0x0c065e0cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c065e0e;
P_0c065e0e: /* original d083, guest PC 0x0c065e0e */
if(!s->budget--) { s->failed_pc=0x0c065e0eu; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065e10;
P_0c065e10: /* original 62c3, guest PC 0x0c065e10 */
if(!s->budget--) { s->failed_pc=0x0c065e10u; return 0; }
r[2]=r[12];
goto P_0c065e12;
P_0c065e12: /* original 7c01, guest PC 0x0c065e12 */
if(!s->budget--) { s->failed_pc=0x0c065e12u; return 0; }
r[12]+=0x00000001u;
goto P_0c065e14;
P_0c065e14: /* original 4208, guest PC 0x0c065e14 */
if(!s->budget--) { s->failed_pc=0x0c065e14u; return 0; }
r[2]<<=2;
goto P_0c065e16;
P_0c065e16: /* original 02e6, guest PC 0x0c065e16 */
if(!s->budget--) { s->failed_pc=0x0c065e16u; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c065e18;
P_0c065e18: /* original 63c3, guest PC 0x0c065e18 */
if(!s->budget--) { s->failed_pc=0x0c065e18u; return 0; }
r[3]=r[12];
goto P_0c065e1a;
P_0c065e1a: /* original 7c01, guest PC 0x0c065e1a */
if(!s->budget--) { s->failed_pc=0x0c065e1au; return 0; }
r[12]+=0x00000001u;
goto P_0c065e1c;
P_0c065e1c: /* original 4308, guest PC 0x0c065e1c */
if(!s->budget--) { s->failed_pc=0x0c065e1cu; return 0; }
r[3]<<=2;
goto P_0c065e1e;
P_0c065e1e: /* original 0356, guest PC 0x0c065e1e */
if(!s->budget--) { s->failed_pc=0x0c065e1eu; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c065e20;
P_0c065e20: /* original 62c3, guest PC 0x0c065e20 */
if(!s->budget--) { s->failed_pc=0x0c065e20u; return 0; }
r[2]=r[12];
goto P_0c065e22;
P_0c065e22: /* original 7c01, guest PC 0x0c065e22 */
if(!s->budget--) { s->failed_pc=0x0c065e22u; return 0; }
r[12]+=0x00000001u;
goto P_0c065e24;
P_0c065e24: /* original 4208, guest PC 0x0c065e24 */
if(!s->budget--) { s->failed_pc=0x0c065e24u; return 0; }
r[2]<<=2;
goto P_0c065e26;
P_0c065e26: /* original 0246, guest PC 0x0c065e26 */
if(!s->budget--) { s->failed_pc=0x0c065e26u; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c065e28;
P_0c065e28: /* original 62d2, guest PC 0x0c065e28 */
if(!s->budget--) { s->failed_pc=0x0c065e28u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065e2a;
P_0c065e2a: /* original 63c3, guest PC 0x0c065e2a */
if(!s->budget--) { s->failed_pc=0x0c065e2au; return 0; }
r[3]=r[12];
goto P_0c065e2c;
P_0c065e2c: /* original 5221, guest PC 0x0c065e2c */
if(!s->budget--) { s->failed_pc=0x0c065e2cu; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c065e2e;
P_0c065e2e: /* original 7c01, guest PC 0x0c065e2e */
if(!s->budget--) { s->failed_pc=0x0c065e2eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065e30;
P_0c065e30: /* original 4308, guest PC 0x0c065e30 */
if(!s->budget--) { s->failed_pc=0x0c065e30u; return 0; }
r[3]<<=2;
goto P_0c065e32;
P_0c065e32: /* original 0326, guest PC 0x0c065e32 */
if(!s->budget--) { s->failed_pc=0x0c065e32u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065e34;
P_0c065e34: /* original 62d2, guest PC 0x0c065e34 */
if(!s->budget--) { s->failed_pc=0x0c065e34u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065e36;
P_0c065e36: /* original 63c3, guest PC 0x0c065e36 */
if(!s->budget--) { s->failed_pc=0x0c065e36u; return 0; }
r[3]=r[12];
goto P_0c065e38;
P_0c065e38: /* original 5222, guest PC 0x0c065e38 */
if(!s->budget--) { s->failed_pc=0x0c065e38u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c065e3a;
P_0c065e3a: /* original 7c01, guest PC 0x0c065e3a */
if(!s->budget--) { s->failed_pc=0x0c065e3au; return 0; }
r[12]+=0x00000001u;
goto P_0c065e3c;
P_0c065e3c: /* original 4308, guest PC 0x0c065e3c */
if(!s->budget--) { s->failed_pc=0x0c065e3cu; return 0; }
r[3]<<=2;
goto P_0c065e3e;
P_0c065e3e: /* original 0326, guest PC 0x0c065e3e */
if(!s->budget--) { s->failed_pc=0x0c065e3eu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065e40;
P_0c065e40: /* original 62d2, guest PC 0x0c065e40 */
if(!s->budget--) { s->failed_pc=0x0c065e40u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065e42;
P_0c065e42: /* original 63c3, guest PC 0x0c065e42 */
if(!s->budget--) { s->failed_pc=0x0c065e42u; return 0; }
r[3]=r[12];
goto P_0c065e44;
P_0c065e44: /* original 5223, guest PC 0x0c065e44 */
if(!s->budget--) { s->failed_pc=0x0c065e44u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c065e46;
P_0c065e46: /* original 7c01, guest PC 0x0c065e46 */
if(!s->budget--) { s->failed_pc=0x0c065e46u; return 0; }
r[12]+=0x00000001u;
goto P_0c065e48;
P_0c065e48: /* original 4308, guest PC 0x0c065e48 */
if(!s->budget--) { s->failed_pc=0x0c065e48u; return 0; }
r[3]<<=2;
goto P_0c065e4a;
P_0c065e4a: /* original 0326, guest PC 0x0c065e4a */
if(!s->budget--) { s->failed_pc=0x0c065e4au; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065e4c;
P_0c065e4c: /* original 67d2, guest PC 0x0c065e4c */
if(!s->budget--) { s->failed_pc=0x0c065e4cu; return 0; }
tmp=read(ram,r[13],4);
r[7]=tmp;
goto P_0c065e4e;
P_0c065e4e: /* original 2f72, guest PC 0x0c065e4e */
if(!s->budget--) { s->failed_pc=0x0c065e4eu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065e50;
P_0c065e50: /* original 5775, guest PC 0x0c065e50 */
if(!s->budget--) { s->failed_pc=0x0c065e50u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065e52;
P_0c065e52: /* original 65c3, guest PC 0x0c065e52 */
if(!s->budget--) { s->failed_pc=0x0c065e52u; return 0; }
r[5]=r[12];
goto P_0c065e54;
P_0c065e54: /* original d372, guest PC 0x0c065e54 */
if(!s->budget--) { s->failed_pc=0x0c065e54u; return 0; }
r[3]=read(ram,0x0c066020u,4);
goto P_0c065e56;
P_0c065e56: /* original 66f2, guest PC 0x0c065e56 */
if(!s->budget--) { s->failed_pc=0x0c065e56u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065e58;
P_0c065e58: /* original 5664, guest PC 0x0c065e58 */
if(!s->budget--) { s->failed_pc=0x0c065e58u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065e5a;
P_0c065e5a: /* original 430b, guest PC 0x0c065e5a */
if(!s->budget--) { s->failed_pc=0x0c065e5au; return 0; }
target=r[3];
r[16]=0x0c065e5eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065e5eu) { target=s->pc; goto dispatch; }
goto P_0c065e5e;
P_0c065e5c: /* original 64e3, guest PC 0x0c065e5c */
if(!s->budget--) { s->failed_pc=0x0c065e5cu; return 0; }
r[4]=r[14];
goto P_0c065e5e;
P_0c065e5e: /* original 6903, guest PC 0x0c065e5e */
if(!s->budget--) { s->failed_pc=0x0c065e5eu; return 0; }
r[9]=r[0];
goto P_0c065e60;
P_0c065e60: /* original 64d2, guest PC 0x0c065e60 */
if(!s->budget--) { s->failed_pc=0x0c065e60u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c065e62;
P_0c065e62: /* original e118, guest PC 0x0c065e62 */
if(!s->budget--) { s->failed_pc=0x0c065e62u; return 0; }
r[1]=0x00000018u;
goto P_0c065e64;
P_0c065e64: /* original c76f, guest PC 0x0c065e64 */
if(!s->budget--) { s->failed_pc=0x0c065e64u; return 0; }
r[0]=0x0c066024u;
goto P_0c065e66;
P_0c065e66: /* original 6393, guest PC 0x0c065e66 */
if(!s->budget--) { s->failed_pc=0x0c065e66u; return 0; }
r[3]=r[9];
goto P_0c065e68;
P_0c065e68: /* original ff08, guest PC 0x0c065e68 */
if(!s->budget--) { s->failed_pc=0x0c065e68u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c065e6a;
P_0c065e6a: /* original 314c, guest PC 0x0c065e6a */
if(!s->budget--) { s->failed_pc=0x0c065e6au; return 0; }
r[1]+=r[4];
goto P_0c065e6c;
P_0c065e6c: /* original d06b, guest PC 0x0c065e6c */
if(!s->budget--) { s->failed_pc=0x0c065e6cu; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065e6e;
P_0c065e6e: /* original 7901, guest PC 0x0c065e6e */
if(!s->budget--) { s->failed_pc=0x0c065e6eu; return 0; }
r[9]+=0x00000001u;
goto P_0c065e70;
P_0c065e70: /* original f318, guest PC 0x0c065e70 */
if(!s->budget--) { s->failed_pc=0x0c065e70u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065e72;
P_0c065e72: /* original 4308, guest PC 0x0c065e72 */
if(!s->budget--) { s->failed_pc=0x0c065e72u; return 0; }
r[3]<<=2;
goto P_0c065e74;
P_0c065e74: /* original f3f2, guest PC 0x0c065e74 */
if(!s->budget--) { s->failed_pc=0x0c065e74u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065e76;
P_0c065e76: /* original f33d, guest PC 0x0c065e76 */
if(!s->budget--) { s->failed_pc=0x0c065e76u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065e78;
P_0c065e78: /* original 045a, guest PC 0x0c065e78 */
if(!s->budget--) { s->failed_pc=0x0c065e78u; return 0; }
r[4]=r[53];
goto P_0c065e7a;
P_0c065e7a: /* original 6243, guest PC 0x0c065e7a */
if(!s->budget--) { s->failed_pc=0x0c065e7au; return 0; }
r[2]=r[4];
goto P_0c065e7c;
P_0c065e7c: /* original 4228, guest PC 0x0c065e7c */
if(!s->budget--) { s->failed_pc=0x0c065e7cu; return 0; }
r[2]<<=16;
goto P_0c065e7e;
P_0c065e7e: /* original 4218, guest PC 0x0c065e7e */
if(!s->budget--) { s->failed_pc=0x0c065e7eu; return 0; }
r[2]<<=8;
goto P_0c065e80;
P_0c065e80: /* original 6143, guest PC 0x0c065e80 */
if(!s->budget--) { s->failed_pc=0x0c065e80u; return 0; }
r[1]=r[4];
goto P_0c065e82;
P_0c065e82: /* original 4128, guest PC 0x0c065e82 */
if(!s->budget--) { s->failed_pc=0x0c065e82u; return 0; }
r[1]<<=16;
goto P_0c065e84;
P_0c065e84: /* original 221b, guest PC 0x0c065e84 */
if(!s->budget--) { s->failed_pc=0x0c065e84u; return 0; }
r[2]|=r[1];
goto P_0c065e86;
P_0c065e86: /* original 6143, guest PC 0x0c065e86 */
if(!s->budget--) { s->failed_pc=0x0c065e86u; return 0; }
r[1]=r[4];
goto P_0c065e88;
P_0c065e88: /* original 4118, guest PC 0x0c065e88 */
if(!s->budget--) { s->failed_pc=0x0c065e88u; return 0; }
r[1]<<=8;
goto P_0c065e8a;
P_0c065e8a: /* original 221b, guest PC 0x0c065e8a */
if(!s->budget--) { s->failed_pc=0x0c065e8au; return 0; }
r[2]|=r[1];
goto P_0c065e8c;
P_0c065e8c: /* original 224b, guest PC 0x0c065e8c */
if(!s->budget--) { s->failed_pc=0x0c065e8cu; return 0; }
r[2]|=r[4];
goto P_0c065e8e;
P_0c065e8e: /* original 0326, guest PC 0x0c065e8e */
if(!s->budget--) { s->failed_pc=0x0c065e8eu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065e90;
P_0c065e90: /* original 6cd2, guest PC 0x0c065e90 */
if(!s->budget--) { s->failed_pc=0x0c065e90u; return 0; }
tmp=read(ram,r[13],4);
r[12]=tmp;
goto P_0c065e92;
P_0c065e92: /* original e01c, guest PC 0x0c065e92 */
if(!s->budget--) { s->failed_pc=0x0c065e92u; return 0; }
r[0]=0x0000001cu;
goto P_0c065e94;
P_0c065e94: /* original f3c6, guest PC 0x0c065e94 */
if(!s->budget--) { s->failed_pc=0x0c065e94u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065e96;
P_0c065e96: /* original f3f2, guest PC 0x0c065e96 */
if(!s->budget--) { s->failed_pc=0x0c065e96u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065e98;
P_0c065e98: /* original f33d, guest PC 0x0c065e98 */
if(!s->budget--) { s->failed_pc=0x0c065e98u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065e9a;
P_0c065e9a: /* original 0c5a, guest PC 0x0c065e9a */
if(!s->budget--) { s->failed_pc=0x0c065e9au; return 0; }
r[12]=r[53];
goto P_0c065e9c;
P_0c065e9c: /* original 66c3, guest PC 0x0c065e9c */
if(!s->budget--) { s->failed_pc=0x0c065e9cu; return 0; }
r[6]=r[12];
goto P_0c065e9e;
P_0c065e9e: /* original 4628, guest PC 0x0c065e9e */
if(!s->budget--) { s->failed_pc=0x0c065e9eu; return 0; }
r[6]<<=16;
goto P_0c065ea0;
P_0c065ea0: /* original 4618, guest PC 0x0c065ea0 */
if(!s->budget--) { s->failed_pc=0x0c065ea0u; return 0; }
r[6]<<=8;
goto P_0c065ea2;
P_0c065ea2: /* original 63c3, guest PC 0x0c065ea2 */
if(!s->budget--) { s->failed_pc=0x0c065ea2u; return 0; }
r[3]=r[12];
goto P_0c065ea4;
P_0c065ea4: /* original 4328, guest PC 0x0c065ea4 */
if(!s->budget--) { s->failed_pc=0x0c065ea4u; return 0; }
r[3]<<=16;
goto P_0c065ea6;
P_0c065ea6: /* original 263b, guest PC 0x0c065ea6 */
if(!s->budget--) { s->failed_pc=0x0c065ea6u; return 0; }
r[6]|=r[3];
goto P_0c065ea8;
P_0c065ea8: /* original d35f, guest PC 0x0c065ea8 */
if(!s->budget--) { s->failed_pc=0x0c065ea8u; return 0; }
r[3]=read(ram,0x0c066028u,4);
goto P_0c065eaa;
P_0c065eaa: /* original 62c3, guest PC 0x0c065eaa */
if(!s->budget--) { s->failed_pc=0x0c065eaau; return 0; }
r[2]=r[12];
goto P_0c065eac;
P_0c065eac: /* original 4218, guest PC 0x0c065eac */
if(!s->budget--) { s->failed_pc=0x0c065eacu; return 0; }
r[2]<<=8;
goto P_0c065eae;
P_0c065eae: /* original 262b, guest PC 0x0c065eae */
if(!s->budget--) { s->failed_pc=0x0c065eaeu; return 0; }
r[6]|=r[2];
goto P_0c065eb0;
P_0c065eb0: /* original 26cb, guest PC 0x0c065eb0 */
if(!s->budget--) { s->failed_pc=0x0c065eb0u; return 0; }
r[6]|=r[12];
goto P_0c065eb2;
P_0c065eb2: /* original 6593, guest PC 0x0c065eb2 */
if(!s->budget--) { s->failed_pc=0x0c065eb2u; return 0; }
r[5]=r[9];
goto P_0c065eb4;
P_0c065eb4: /* original 430b, guest PC 0x0c065eb4 */
if(!s->budget--) { s->failed_pc=0x0c065eb4u; return 0; }
target=r[3];
r[16]=0x0c065eb8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065eb8u) { target=s->pc; goto dispatch; }
goto P_0c065eb8;
P_0c065eb6: /* original 64e3, guest PC 0x0c065eb6 */
if(!s->budget--) { s->failed_pc=0x0c065eb6u; return 0; }
r[4]=r[14];
goto P_0c065eb8;
P_0c065eb8: /* original 61b2, guest PC 0x0c065eb8 */
if(!s->budget--) { s->failed_pc=0x0c065eb8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065eba;
P_0c065eba: /* original 6c03, guest PC 0x0c065eba */
if(!s->budget--) { s->failed_pc=0x0c065ebau; return 0; }
r[12]=r[0];
goto P_0c065ebc;
P_0c065ebc: /* original 5311, guest PC 0x0c065ebc */
if(!s->budget--) { s->failed_pc=0x0c065ebcu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065ebe;
P_0c065ebe: /* original 62c3, guest PC 0x0c065ebe */
if(!s->budget--) { s->failed_pc=0x0c065ebeu; return 0; }
r[2]=r[12];
goto P_0c065ec0;
P_0c065ec0: /* original d056, guest PC 0x0c065ec0 */
if(!s->budget--) { s->failed_pc=0x0c065ec0u; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065ec2;
P_0c065ec2: /* original 7c01, guest PC 0x0c065ec2 */
if(!s->budget--) { s->failed_pc=0x0c065ec2u; return 0; }
r[12]+=0x00000001u;
goto P_0c065ec4;
P_0c065ec4: /* original 4208, guest PC 0x0c065ec4 */
if(!s->budget--) { s->failed_pc=0x0c065ec4u; return 0; }
r[2]<<=2;
goto P_0c065ec6;
P_0c065ec6: /* original 0236, guest PC 0x0c065ec6 */
if(!s->budget--) { s->failed_pc=0x0c065ec6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065ec8;
P_0c065ec8: /* original 61b2, guest PC 0x0c065ec8 */
if(!s->budget--) { s->failed_pc=0x0c065ec8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065eca;
P_0c065eca: /* original 62c3, guest PC 0x0c065eca */
if(!s->budget--) { s->failed_pc=0x0c065ecau; return 0; }
r[2]=r[12];
goto P_0c065ecc;
P_0c065ecc: /* original 5312, guest PC 0x0c065ecc */
if(!s->budget--) { s->failed_pc=0x0c065eccu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065ece;
P_0c065ece: /* original 7c01, guest PC 0x0c065ece */
if(!s->budget--) { s->failed_pc=0x0c065eceu; return 0; }
r[12]+=0x00000001u;
goto P_0c065ed0;
P_0c065ed0: /* original 4208, guest PC 0x0c065ed0 */
if(!s->budget--) { s->failed_pc=0x0c065ed0u; return 0; }
r[2]<<=2;
goto P_0c065ed2;
P_0c065ed2: /* original 0236, guest PC 0x0c065ed2 */
if(!s->budget--) { s->failed_pc=0x0c065ed2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065ed4;
P_0c065ed4: /* original 61b2, guest PC 0x0c065ed4 */
if(!s->budget--) { s->failed_pc=0x0c065ed4u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065ed6;
P_0c065ed6: /* original 62c3, guest PC 0x0c065ed6 */
if(!s->budget--) { s->failed_pc=0x0c065ed6u; return 0; }
r[2]=r[12];
goto P_0c065ed8;
P_0c065ed8: /* original 5313, guest PC 0x0c065ed8 */
if(!s->budget--) { s->failed_pc=0x0c065ed8u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065eda;
P_0c065eda: /* original 7c01, guest PC 0x0c065eda */
if(!s->budget--) { s->failed_pc=0x0c065edau; return 0; }
r[12]+=0x00000001u;
goto P_0c065edc;
P_0c065edc: /* original 4208, guest PC 0x0c065edc */
if(!s->budget--) { s->failed_pc=0x0c065edcu; return 0; }
r[2]<<=2;
goto P_0c065ede;
P_0c065ede: /* original 0236, guest PC 0x0c065ede */
if(!s->budget--) { s->failed_pc=0x0c065edeu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065ee0;
P_0c065ee0: /* original 67b2, guest PC 0x0c065ee0 */
if(!s->budget--) { s->failed_pc=0x0c065ee0u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c065ee2;
P_0c065ee2: /* original 65c3, guest PC 0x0c065ee2 */
if(!s->budget--) { s->failed_pc=0x0c065ee2u; return 0; }
r[5]=r[12];
goto P_0c065ee4;
P_0c065ee4: /* original d34e, guest PC 0x0c065ee4 */
if(!s->budget--) { s->failed_pc=0x0c065ee4u; return 0; }
r[3]=read(ram,0x0c066020u,4);
goto P_0c065ee6;
P_0c065ee6: /* original 2f72, guest PC 0x0c065ee6 */
if(!s->budget--) { s->failed_pc=0x0c065ee6u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065ee8;
P_0c065ee8: /* original 5775, guest PC 0x0c065ee8 */
if(!s->budget--) { s->failed_pc=0x0c065ee8u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065eea;
P_0c065eea: /* original 66f2, guest PC 0x0c065eea */
if(!s->budget--) { s->failed_pc=0x0c065eeau; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065eec;
P_0c065eec: /* original 5664, guest PC 0x0c065eec */
if(!s->budget--) { s->failed_pc=0x0c065eecu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065eee;
P_0c065eee: /* original 430b, guest PC 0x0c065eee */
if(!s->budget--) { s->failed_pc=0x0c065eeeu; return 0; }
target=r[3];
r[16]=0x0c065ef2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065ef2u) { target=s->pc; goto dispatch; }
goto P_0c065ef2;
P_0c065ef0: /* original 64e3, guest PC 0x0c065ef0 */
if(!s->budget--) { s->failed_pc=0x0c065ef0u; return 0; }
r[4]=r[14];
goto P_0c065ef2;
P_0c065ef2: /* original 6903, guest PC 0x0c065ef2 */
if(!s->budget--) { s->failed_pc=0x0c065ef2u; return 0; }
r[9]=r[0];
goto P_0c065ef4;
P_0c065ef4: /* original 64b2, guest PC 0x0c065ef4 */
if(!s->budget--) { s->failed_pc=0x0c065ef4u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c065ef6;
P_0c065ef6: /* original e118, guest PC 0x0c065ef6 */
if(!s->budget--) { s->failed_pc=0x0c065ef6u; return 0; }
r[1]=0x00000018u;
goto P_0c065ef8;
P_0c065ef8: /* original d048, guest PC 0x0c065ef8 */
if(!s->budget--) { s->failed_pc=0x0c065ef8u; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065efa;
P_0c065efa: /* original 6293, guest PC 0x0c065efa */
if(!s->budget--) { s->failed_pc=0x0c065efau; return 0; }
r[2]=r[9];
goto P_0c065efc;
P_0c065efc: /* original 7901, guest PC 0x0c065efc */
if(!s->budget--) { s->failed_pc=0x0c065efcu; return 0; }
r[9]+=0x00000001u;
goto P_0c065efe;
P_0c065efe: /* original 4208, guest PC 0x0c065efe */
if(!s->budget--) { s->failed_pc=0x0c065efeu; return 0; }
r[2]<<=2;
goto P_0c065f00;
P_0c065f00: /* original 314c, guest PC 0x0c065f00 */
if(!s->budget--) { s->failed_pc=0x0c065f00u; return 0; }
r[1]+=r[4];
goto P_0c065f02;
P_0c065f02: /* original f318, guest PC 0x0c065f02 */
if(!s->budget--) { s->failed_pc=0x0c065f02u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065f04;
P_0c065f04: /* original f3f2, guest PC 0x0c065f04 */
if(!s->budget--) { s->failed_pc=0x0c065f04u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065f06;
P_0c065f06: /* original f33d, guest PC 0x0c065f06 */
if(!s->budget--) { s->failed_pc=0x0c065f06u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065f08;
P_0c065f08: /* original 045a, guest PC 0x0c065f08 */
if(!s->budget--) { s->failed_pc=0x0c065f08u; return 0; }
r[4]=r[53];
goto P_0c065f0a;
P_0c065f0a: /* original 6343, guest PC 0x0c065f0a */
if(!s->budget--) { s->failed_pc=0x0c065f0au; return 0; }
r[3]=r[4];
goto P_0c065f0c;
P_0c065f0c: /* original 4328, guest PC 0x0c065f0c */
if(!s->budget--) { s->failed_pc=0x0c065f0cu; return 0; }
r[3]<<=16;
goto P_0c065f0e;
P_0c065f0e: /* original 4318, guest PC 0x0c065f0e */
if(!s->budget--) { s->failed_pc=0x0c065f0eu; return 0; }
r[3]<<=8;
goto P_0c065f10;
P_0c065f10: /* original 6143, guest PC 0x0c065f10 */
if(!s->budget--) { s->failed_pc=0x0c065f10u; return 0; }
r[1]=r[4];
goto P_0c065f12;
P_0c065f12: /* original 4128, guest PC 0x0c065f12 */
if(!s->budget--) { s->failed_pc=0x0c065f12u; return 0; }
r[1]<<=16;
goto P_0c065f14;
P_0c065f14: /* original 231b, guest PC 0x0c065f14 */
if(!s->budget--) { s->failed_pc=0x0c065f14u; return 0; }
r[3]|=r[1];
goto P_0c065f16;
P_0c065f16: /* original 6143, guest PC 0x0c065f16 */
if(!s->budget--) { s->failed_pc=0x0c065f16u; return 0; }
r[1]=r[4];
goto P_0c065f18;
P_0c065f18: /* original 4118, guest PC 0x0c065f18 */
if(!s->budget--) { s->failed_pc=0x0c065f18u; return 0; }
r[1]<<=8;
goto P_0c065f1a;
P_0c065f1a: /* original 231b, guest PC 0x0c065f1a */
if(!s->budget--) { s->failed_pc=0x0c065f1au; return 0; }
r[3]|=r[1];
goto P_0c065f1c;
P_0c065f1c: /* original 234b, guest PC 0x0c065f1c */
if(!s->budget--) { s->failed_pc=0x0c065f1cu; return 0; }
r[3]|=r[4];
goto P_0c065f1e;
P_0c065f1e: /* original 0236, guest PC 0x0c065f1e */
if(!s->budget--) { s->failed_pc=0x0c065f1eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065f20;
P_0c065f20: /* original 6cb2, guest PC 0x0c065f20 */
if(!s->budget--) { s->failed_pc=0x0c065f20u; return 0; }
tmp=read(ram,r[11],4);
r[12]=tmp;
goto P_0c065f22;
P_0c065f22: /* original e01c, guest PC 0x0c065f22 */
if(!s->budget--) { s->failed_pc=0x0c065f22u; return 0; }
r[0]=0x0000001cu;
goto P_0c065f24;
P_0c065f24: /* original f3c6, guest PC 0x0c065f24 */
if(!s->budget--) { s->failed_pc=0x0c065f24u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065f26;
P_0c065f26: /* original f3f2, guest PC 0x0c065f26 */
if(!s->budget--) { s->failed_pc=0x0c065f26u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065f28;
P_0c065f28: /* original f33d, guest PC 0x0c065f28 */
if(!s->budget--) { s->failed_pc=0x0c065f28u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065f2a;
P_0c065f2a: /* original 0c5a, guest PC 0x0c065f2a */
if(!s->budget--) { s->failed_pc=0x0c065f2au; return 0; }
r[12]=r[53];
goto P_0c065f2c;
P_0c065f2c: /* original 66c3, guest PC 0x0c065f2c */
if(!s->budget--) { s->failed_pc=0x0c065f2cu; return 0; }
r[6]=r[12];
goto P_0c065f2e;
P_0c065f2e: /* original 4628, guest PC 0x0c065f2e */
if(!s->budget--) { s->failed_pc=0x0c065f2eu; return 0; }
r[6]<<=16;
goto P_0c065f30;
P_0c065f30: /* original 4618, guest PC 0x0c065f30 */
if(!s->budget--) { s->failed_pc=0x0c065f30u; return 0; }
r[6]<<=8;
goto P_0c065f32;
P_0c065f32: /* original 63c3, guest PC 0x0c065f32 */
if(!s->budget--) { s->failed_pc=0x0c065f32u; return 0; }
r[3]=r[12];
goto P_0c065f34;
P_0c065f34: /* original 4328, guest PC 0x0c065f34 */
if(!s->budget--) { s->failed_pc=0x0c065f34u; return 0; }
r[3]<<=16;
goto P_0c065f36;
P_0c065f36: /* original 263b, guest PC 0x0c065f36 */
if(!s->budget--) { s->failed_pc=0x0c065f36u; return 0; }
r[6]|=r[3];
goto P_0c065f38;
P_0c065f38: /* original d33b, guest PC 0x0c065f38 */
if(!s->budget--) { s->failed_pc=0x0c065f38u; return 0; }
r[3]=read(ram,0x0c066028u,4);
goto P_0c065f3a;
P_0c065f3a: /* original 62c3, guest PC 0x0c065f3a */
if(!s->budget--) { s->failed_pc=0x0c065f3au; return 0; }
r[2]=r[12];
goto P_0c065f3c;
P_0c065f3c: /* original 4218, guest PC 0x0c065f3c */
if(!s->budget--) { s->failed_pc=0x0c065f3cu; return 0; }
r[2]<<=8;
goto P_0c065f3e;
P_0c065f3e: /* original 262b, guest PC 0x0c065f3e */
if(!s->budget--) { s->failed_pc=0x0c065f3eu; return 0; }
r[6]|=r[2];
goto P_0c065f40;
P_0c065f40: /* original 26cb, guest PC 0x0c065f40 */
if(!s->budget--) { s->failed_pc=0x0c065f40u; return 0; }
r[6]|=r[12];
goto P_0c065f42;
P_0c065f42: /* original 6593, guest PC 0x0c065f42 */
if(!s->budget--) { s->failed_pc=0x0c065f42u; return 0; }
r[5]=r[9];
goto P_0c065f44;
P_0c065f44: /* original 430b, guest PC 0x0c065f44 */
if(!s->budget--) { s->failed_pc=0x0c065f44u; return 0; }
target=r[3];
r[16]=0x0c065f48u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065f48u) { target=s->pc; goto dispatch; }
goto P_0c065f48;
P_0c065f46: /* original 64e3, guest PC 0x0c065f46 */
if(!s->budget--) { s->failed_pc=0x0c065f46u; return 0; }
r[4]=r[14];
goto P_0c065f48;
P_0c065f48: /* original 61a2, guest PC 0x0c065f48 */
if(!s->budget--) { s->failed_pc=0x0c065f48u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065f4a;
P_0c065f4a: /* original 6c03, guest PC 0x0c065f4a */
if(!s->budget--) { s->failed_pc=0x0c065f4au; return 0; }
r[12]=r[0];
goto P_0c065f4c;
P_0c065f4c: /* original 5311, guest PC 0x0c065f4c */
if(!s->budget--) { s->failed_pc=0x0c065f4cu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065f4e;
P_0c065f4e: /* original 62c3, guest PC 0x0c065f4e */
if(!s->budget--) { s->failed_pc=0x0c065f4eu; return 0; }
r[2]=r[12];
goto P_0c065f50;
P_0c065f50: /* original d032, guest PC 0x0c065f50 */
if(!s->budget--) { s->failed_pc=0x0c065f50u; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065f52;
P_0c065f52: /* original 7c01, guest PC 0x0c065f52 */
if(!s->budget--) { s->failed_pc=0x0c065f52u; return 0; }
r[12]+=0x00000001u;
goto P_0c065f54;
P_0c065f54: /* original 4208, guest PC 0x0c065f54 */
if(!s->budget--) { s->failed_pc=0x0c065f54u; return 0; }
r[2]<<=2;
goto P_0c065f56;
P_0c065f56: /* original 0236, guest PC 0x0c065f56 */
if(!s->budget--) { s->failed_pc=0x0c065f56u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065f58;
P_0c065f58: /* original 61a2, guest PC 0x0c065f58 */
if(!s->budget--) { s->failed_pc=0x0c065f58u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065f5a;
P_0c065f5a: /* original 62c3, guest PC 0x0c065f5a */
if(!s->budget--) { s->failed_pc=0x0c065f5au; return 0; }
r[2]=r[12];
goto P_0c065f5c;
P_0c065f5c: /* original 5312, guest PC 0x0c065f5c */
if(!s->budget--) { s->failed_pc=0x0c065f5cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065f5e;
P_0c065f5e: /* original 7c01, guest PC 0x0c065f5e */
if(!s->budget--) { s->failed_pc=0x0c065f5eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065f60;
P_0c065f60: /* original 4208, guest PC 0x0c065f60 */
if(!s->budget--) { s->failed_pc=0x0c065f60u; return 0; }
r[2]<<=2;
goto P_0c065f62;
P_0c065f62: /* original 0236, guest PC 0x0c065f62 */
if(!s->budget--) { s->failed_pc=0x0c065f62u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065f64;
P_0c065f64: /* original 61a2, guest PC 0x0c065f64 */
if(!s->budget--) { s->failed_pc=0x0c065f64u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065f66;
P_0c065f66: /* original 62c3, guest PC 0x0c065f66 */
if(!s->budget--) { s->failed_pc=0x0c065f66u; return 0; }
r[2]=r[12];
goto P_0c065f68;
P_0c065f68: /* original 5313, guest PC 0x0c065f68 */
if(!s->budget--) { s->failed_pc=0x0c065f68u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065f6a;
P_0c065f6a: /* original 7c01, guest PC 0x0c065f6a */
if(!s->budget--) { s->failed_pc=0x0c065f6au; return 0; }
r[12]+=0x00000001u;
goto P_0c065f6c;
P_0c065f6c: /* original 4208, guest PC 0x0c065f6c */
if(!s->budget--) { s->failed_pc=0x0c065f6cu; return 0; }
r[2]<<=2;
goto P_0c065f6e;
P_0c065f6e: /* original 0236, guest PC 0x0c065f6e */
if(!s->budget--) { s->failed_pc=0x0c065f6eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065f70;
P_0c065f70: /* original 67a2, guest PC 0x0c065f70 */
if(!s->budget--) { s->failed_pc=0x0c065f70u; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c065f72;
P_0c065f72: /* original 65c3, guest PC 0x0c065f72 */
if(!s->budget--) { s->failed_pc=0x0c065f72u; return 0; }
r[5]=r[12];
goto P_0c065f74;
P_0c065f74: /* original d32a, guest PC 0x0c065f74 */
if(!s->budget--) { s->failed_pc=0x0c065f74u; return 0; }
r[3]=read(ram,0x0c066020u,4);
goto P_0c065f76;
P_0c065f76: /* original 2f72, guest PC 0x0c065f76 */
if(!s->budget--) { s->failed_pc=0x0c065f76u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065f78;
P_0c065f78: /* original 5775, guest PC 0x0c065f78 */
if(!s->budget--) { s->failed_pc=0x0c065f78u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065f7a;
P_0c065f7a: /* original 66f2, guest PC 0x0c065f7a */
if(!s->budget--) { s->failed_pc=0x0c065f7au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065f7c;
P_0c065f7c: /* original 5664, guest PC 0x0c065f7c */
if(!s->budget--) { s->failed_pc=0x0c065f7cu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065f7e;
P_0c065f7e: /* original 430b, guest PC 0x0c065f7e */
if(!s->budget--) { s->failed_pc=0x0c065f7eu; return 0; }
target=r[3];
r[16]=0x0c065f82u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065f82u) { target=s->pc; goto dispatch; }
goto P_0c065f82;
P_0c065f80: /* original 64e3, guest PC 0x0c065f80 */
if(!s->budget--) { s->failed_pc=0x0c065f80u; return 0; }
r[4]=r[14];
goto P_0c065f82;
P_0c065f82: /* original 6b03, guest PC 0x0c065f82 */
if(!s->budget--) { s->failed_pc=0x0c065f82u; return 0; }
r[11]=r[0];
goto P_0c065f84;
P_0c065f84: /* original 64a2, guest PC 0x0c065f84 */
if(!s->budget--) { s->failed_pc=0x0c065f84u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c065f86;
P_0c065f86: /* original e118, guest PC 0x0c065f86 */
if(!s->budget--) { s->failed_pc=0x0c065f86u; return 0; }
r[1]=0x00000018u;
goto P_0c065f88;
P_0c065f88: /* original d024, guest PC 0x0c065f88 */
if(!s->budget--) { s->failed_pc=0x0c065f88u; return 0; }
r[0]=read(ram,0x0c06601cu,4);
goto P_0c065f8a;
P_0c065f8a: /* original 62b3, guest PC 0x0c065f8a */
if(!s->budget--) { s->failed_pc=0x0c065f8au; return 0; }
r[2]=r[11];
goto P_0c065f8c;
P_0c065f8c: /* original 7b01, guest PC 0x0c065f8c */
if(!s->budget--) { s->failed_pc=0x0c065f8cu; return 0; }
r[11]+=0x00000001u;
goto P_0c065f8e;
P_0c065f8e: /* original 4208, guest PC 0x0c065f8e */
if(!s->budget--) { s->failed_pc=0x0c065f8eu; return 0; }
r[2]<<=2;
goto P_0c065f90;
P_0c065f90: /* original 314c, guest PC 0x0c065f90 */
if(!s->budget--) { s->failed_pc=0x0c065f90u; return 0; }
r[1]+=r[4];
goto P_0c065f92;
P_0c065f92: /* original f318, guest PC 0x0c065f92 */
if(!s->budget--) { s->failed_pc=0x0c065f92u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065f94;
P_0c065f94: /* original f3f2, guest PC 0x0c065f94 */
if(!s->budget--) { s->failed_pc=0x0c065f94u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065f96;
P_0c065f96: /* original f33d, guest PC 0x0c065f96 */
if(!s->budget--) { s->failed_pc=0x0c065f96u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065f98;
P_0c065f98: /* original 045a, guest PC 0x0c065f98 */
if(!s->budget--) { s->failed_pc=0x0c065f98u; return 0; }
r[4]=r[53];
goto P_0c065f9a;
P_0c065f9a: /* original 6343, guest PC 0x0c065f9a */
if(!s->budget--) { s->failed_pc=0x0c065f9au; return 0; }
r[3]=r[4];
goto P_0c065f9c;
P_0c065f9c: /* original 4328, guest PC 0x0c065f9c */
if(!s->budget--) { s->failed_pc=0x0c065f9cu; return 0; }
r[3]<<=16;
goto P_0c065f9e;
P_0c065f9e: /* original 4318, guest PC 0x0c065f9e */
if(!s->budget--) { s->failed_pc=0x0c065f9eu; return 0; }
r[3]<<=8;
goto P_0c065fa0;
P_0c065fa0: /* original 6143, guest PC 0x0c065fa0 */
if(!s->budget--) { s->failed_pc=0x0c065fa0u; return 0; }
r[1]=r[4];
goto P_0c065fa2;
P_0c065fa2: /* original 4128, guest PC 0x0c065fa2 */
if(!s->budget--) { s->failed_pc=0x0c065fa2u; return 0; }
r[1]<<=16;
goto P_0c065fa4;
P_0c065fa4: /* original 231b, guest PC 0x0c065fa4 */
if(!s->budget--) { s->failed_pc=0x0c065fa4u; return 0; }
r[3]|=r[1];
goto P_0c065fa6;
P_0c065fa6: /* original 6143, guest PC 0x0c065fa6 */
if(!s->budget--) { s->failed_pc=0x0c065fa6u; return 0; }
r[1]=r[4];
goto P_0c065fa8;
P_0c065fa8: /* original 4118, guest PC 0x0c065fa8 */
if(!s->budget--) { s->failed_pc=0x0c065fa8u; return 0; }
r[1]<<=8;
goto P_0c065faa;
P_0c065faa: /* original 231b, guest PC 0x0c065faa */
if(!s->budget--) { s->failed_pc=0x0c065faau; return 0; }
r[3]|=r[1];
goto P_0c065fac;
P_0c065fac: /* original 234b, guest PC 0x0c065fac */
if(!s->budget--) { s->failed_pc=0x0c065facu; return 0; }
r[3]|=r[4];
goto P_0c065fae;
P_0c065fae: /* original 0236, guest PC 0x0c065fae */
if(!s->budget--) { s->failed_pc=0x0c065faeu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065fb0;
P_0c065fb0: /* original 6ca2, guest PC 0x0c065fb0 */
if(!s->budget--) { s->failed_pc=0x0c065fb0u; return 0; }
tmp=read(ram,r[10],4);
r[12]=tmp;
goto P_0c065fb2;
P_0c065fb2: /* original e01c, guest PC 0x0c065fb2 */
if(!s->budget--) { s->failed_pc=0x0c065fb2u; return 0; }
r[0]=0x0000001cu;
goto P_0c065fb4;
P_0c065fb4: /* original f3c6, guest PC 0x0c065fb4 */
if(!s->budget--) { s->failed_pc=0x0c065fb4u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065fb6;
P_0c065fb6: /* original f3f2, guest PC 0x0c065fb6 */
if(!s->budget--) { s->failed_pc=0x0c065fb6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065fb8;
P_0c065fb8: /* original f33d, guest PC 0x0c065fb8 */
if(!s->budget--) { s->failed_pc=0x0c065fb8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065fba;
P_0c065fba: /* original 0c5a, guest PC 0x0c065fba */
if(!s->budget--) { s->failed_pc=0x0c065fbau; return 0; }
r[12]=r[53];
goto P_0c065fbc;
P_0c065fbc: /* original 66c3, guest PC 0x0c065fbc */
if(!s->budget--) { s->failed_pc=0x0c065fbcu; return 0; }
r[6]=r[12];
goto P_0c065fbe;
P_0c065fbe: /* original 4628, guest PC 0x0c065fbe */
if(!s->budget--) { s->failed_pc=0x0c065fbeu; return 0; }
r[6]<<=16;
goto P_0c065fc0;
P_0c065fc0: /* original 4618, guest PC 0x0c065fc0 */
if(!s->budget--) { s->failed_pc=0x0c065fc0u; return 0; }
r[6]<<=8;
goto P_0c065fc2;
P_0c065fc2: /* original 63c3, guest PC 0x0c065fc2 */
if(!s->budget--) { s->failed_pc=0x0c065fc2u; return 0; }
r[3]=r[12];
goto P_0c065fc4;
P_0c065fc4: /* original 4328, guest PC 0x0c065fc4 */
if(!s->budget--) { s->failed_pc=0x0c065fc4u; return 0; }
r[3]<<=16;
goto P_0c065fc6;
P_0c065fc6: /* original 263b, guest PC 0x0c065fc6 */
if(!s->budget--) { s->failed_pc=0x0c065fc6u; return 0; }
r[6]|=r[3];
goto P_0c065fc8;
P_0c065fc8: /* original d317, guest PC 0x0c065fc8 */
if(!s->budget--) { s->failed_pc=0x0c065fc8u; return 0; }
r[3]=read(ram,0x0c066028u,4);
goto P_0c065fca;
P_0c065fca: /* original 62c3, guest PC 0x0c065fca */
if(!s->budget--) { s->failed_pc=0x0c065fcau; return 0; }
r[2]=r[12];
goto P_0c065fcc;
P_0c065fcc: /* original 4218, guest PC 0x0c065fcc */
if(!s->budget--) { s->failed_pc=0x0c065fccu; return 0; }
r[2]<<=8;
goto P_0c065fce;
P_0c065fce: /* original 262b, guest PC 0x0c065fce */
if(!s->budget--) { s->failed_pc=0x0c065fceu; return 0; }
r[6]|=r[2];
goto P_0c065fd0;
P_0c065fd0: /* original 26cb, guest PC 0x0c065fd0 */
if(!s->budget--) { s->failed_pc=0x0c065fd0u; return 0; }
r[6]|=r[12];
goto P_0c065fd2;
P_0c065fd2: /* original 65b3, guest PC 0x0c065fd2 */
if(!s->budget--) { s->failed_pc=0x0c065fd2u; return 0; }
r[5]=r[11];
goto P_0c065fd4;
P_0c065fd4: /* original 430b, guest PC 0x0c065fd4 */
if(!s->budget--) { s->failed_pc=0x0c065fd4u; return 0; }
target=r[3];
r[16]=0x0c065fd8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065fd8u) { target=s->pc; goto dispatch; }
goto P_0c065fd8;
P_0c065fd6: /* original 64e3, guest PC 0x0c065fd6 */
if(!s->budget--) { s->failed_pc=0x0c065fd6u; return 0; }
r[4]=r[14];
goto P_0c065fd8;
P_0c065fd8: /* original d214, guest PC 0x0c065fd8 */
if(!s->budget--) { s->failed_pc=0x0c065fd8u; return 0; }
r[2]=read(ram,0x0c06602cu,4);
goto P_0c065fda;
P_0c065fda: /* original 6403, guest PC 0x0c065fda */
if(!s->budget--) { s->failed_pc=0x0c065fdau; return 0; }
r[4]=r[0];
goto P_0c065fdc;
P_0c065fdc: /* original 4408, guest PC 0x0c065fdc */
if(!s->budget--) { s->failed_pc=0x0c065fdcu; return 0; }
r[4]<<=2;
goto P_0c065fde;
P_0c065fde: /* original 2242, guest PC 0x0c065fde */
if(!s->budget--) { s->failed_pc=0x0c065fdeu; return 0; }
write(ram,r[2],r[4],4);
goto P_0c065fe0;
P_0c065fe0: /* original d313, guest PC 0x0c065fe0 */
if(!s->budget--) { s->failed_pc=0x0c065fe0u; return 0; }
r[3]=read(ram,0x0c066030u,4);
goto P_0c065fe2;
P_0c065fe2: /* original 430b, guest PC 0x0c065fe2 */
if(!s->budget--) { s->failed_pc=0x0c065fe2u; return 0; }
target=r[3];
r[16]=0x0c065fe6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065fe6u) { target=s->pc; goto dispatch; }
goto P_0c065fe6;
P_0c065fe4: /* original 64e3, guest PC 0x0c065fe4 */
if(!s->budget--) { s->failed_pc=0x0c065fe4u; return 0; }
r[4]=r[14];
goto P_0c065fe6;
P_0c065fe6: /* original 6403, guest PC 0x0c065fe6 */
if(!s->budget--) { s->failed_pc=0x0c065fe6u; return 0; }
r[4]=r[0];
goto P_0c065fe8;
P_0c065fe8: /* original d212, guest PC 0x0c065fe8 */
if(!s->budget--) { s->failed_pc=0x0c065fe8u; return 0; }
r[2]=read(ram,0x0c066034u,4);
goto P_0c065fea;
P_0c065fea: /* original e500, guest PC 0x0c065fea */
if(!s->budget--) { s->failed_pc=0x0c065feau; return 0; }
r[5]=0x00000000u;
goto P_0c065fec;
P_0c065fec: /* original 420b, guest PC 0x0c065fec */
if(!s->budget--) { s->failed_pc=0x0c065fecu; return 0; }
target=r[2];
r[16]=0x0c065ff0u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065ff0u) { target=s->pc; goto dispatch; }
goto P_0c065ff0;
P_0c065fee: /* original 6653, guest PC 0x0c065fee */
if(!s->budget--) { s->failed_pc=0x0c065feeu; return 0; }
r[6]=r[5];
goto P_0c065ff0;
P_0c065ff0: /* original 62d2, guest PC 0x0c065ff0 */
if(!s->budget--) { s->failed_pc=0x0c065ff0u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065ff2;
P_0c065ff2: /* original 5323, guest PC 0x0c065ff2 */
if(!s->budget--) { s->failed_pc=0x0c065ff2u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c065ff4;
P_0c065ff4: /* original d110, guest PC 0x0c065ff4 */
if(!s->budget--) { s->failed_pc=0x0c065ff4u; return 0; }
r[1]=read(ram,0x0c066038u,4);
goto P_0c065ff6;
P_0c065ff6: /* original 2132, guest PC 0x0c065ff6 */
if(!s->budget--) { s->failed_pc=0x0c065ff6u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c065ff8;
P_0c065ff8: /* original e000, guest PC 0x0c065ff8 */
if(!s->budget--) { s->failed_pc=0x0c065ff8u; return 0; }
r[0]=0x00000000u;
goto P_0c065ffa;
P_0c065ffa: /* original 7f10, guest PC 0x0c065ffa */
if(!s->budget--) { s->failed_pc=0x0c065ffau; return 0; }
r[15]+=0x00000010u;
goto P_0c065ffc;
P_0c065ffc: /* original 4f26, guest PC 0x0c065ffc */
if(!s->budget--) { s->failed_pc=0x0c065ffcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065ffe;
P_0c065ffe: /* original fff9, guest PC 0x0c065ffe */
if(!s->budget--) { s->failed_pc=0x0c065ffeu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c066000;
P_0c066000: /* original 69f6, guest PC 0x0c066000 */
if(!s->budget--) { s->failed_pc=0x0c066000u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c066002;
P_0c066002: /* original 6af6, guest PC 0x0c066002 */
if(!s->budget--) { s->failed_pc=0x0c066002u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c066004;
P_0c066004: /* original 6bf6, guest PC 0x0c066004 */
if(!s->budget--) { s->failed_pc=0x0c066004u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c066006;
P_0c066006: /* original 6cf6, guest PC 0x0c066006 */
if(!s->budget--) { s->failed_pc=0x0c066006u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c066008;
P_0c066008: /* original 6df6, guest PC 0x0c066008 */
if(!s->budget--) { s->failed_pc=0x0c066008u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06600a;
P_0c06600a: /* original 000b, guest PC 0x0c06600a */
if(!s->budget--) { s->failed_pc=0x0c06600au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06600c: /* original 6ef6, guest PC 0x0c06600c */
if(!s->budget--) { s->failed_pc=0x0c06600cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06600eu,s,ram);
P_0c06604c: /* original 4f22, guest PC 0x0c06604c */
if(!s->budget--) { s->failed_pc=0x0c06604cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06604e;
P_0c06604e: /* original 7ff4, guest PC 0x0c06604e */
if(!s->budget--) { s->failed_pc=0x0c06604eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c066050;
P_0c066050: /* original 6342, guest PC 0x0c066050 */
if(!s->budget--) { s->failed_pc=0x0c066050u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c066052;
P_0c066052: /* original 65f3, guest PC 0x0c066052 */
if(!s->budget--) { s->failed_pc=0x0c066052u; return 0; }
r[5]=r[15];
goto P_0c066054;
P_0c066054: /* original 6d53, guest PC 0x0c066054 */
if(!s->budget--) { s->failed_pc=0x0c066054u; return 0; }
r[13]=r[5];
goto P_0c066056;
P_0c066056: /* original 6cd3, guest PC 0x0c066056 */
if(!s->budget--) { s->failed_pc=0x0c066056u; return 0; }
r[12]=r[13];
goto P_0c066058;
P_0c066058: /* original 2d32, guest PC 0x0c066058 */
if(!s->budget--) { s->failed_pc=0x0c066058u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c06605a;
P_0c06605a: /* original 6ad3, guest PC 0x0c06605a */
if(!s->budget--) { s->failed_pc=0x0c06605au; return 0; }
r[10]=r[13];
goto P_0c06605c;
P_0c06605c: /* original 5241, guest PC 0x0c06605c */
if(!s->budget--) { s->failed_pc=0x0c06605cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06605e;
P_0c06605e: /* original 7c04, guest PC 0x0c06605e */
if(!s->budget--) { s->failed_pc=0x0c06605eu; return 0; }
r[12]+=0x00000004u;
goto P_0c066060;
P_0c066060: /* original 2c22, guest PC 0x0c066060 */
if(!s->budget--) { s->failed_pc=0x0c066060u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c066062;
P_0c066062: /* original 7a08, guest PC 0x0c066062 */
if(!s->budget--) { s->failed_pc=0x0c066062u; return 0; }
r[10]+=0x00000008u;
goto P_0c066064;
P_0c066064: /* original 5342, guest PC 0x0c066064 */
if(!s->budget--) { s->failed_pc=0x0c066064u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c066066;
P_0c066066: /* original 2a32, guest PC 0x0c066066 */
if(!s->budget--) { s->failed_pc=0x0c066066u; return 0; }
write(ram,r[10],r[3],4);
goto P_0c066068;
P_0c066068: /* original d281, guest PC 0x0c066068 */
if(!s->budget--) { s->failed_pc=0x0c066068u; return 0; }
r[2]=read(ram,0x0c066270u,4);
goto P_0c06606a;
P_0c06606a: /* original 6e22, guest PC 0x0c06606a */
if(!s->budget--) { s->failed_pc=0x0c06606au; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c06606c;
P_0c06606c: /* original d381, guest PC 0x0c06606c */
if(!s->budget--) { s->failed_pc=0x0c06606cu; return 0; }
r[3]=read(ram,0x0c066274u,4);
goto P_0c06606e;
P_0c06606e: /* original 6532, guest PC 0x0c06606e */
if(!s->budget--) { s->failed_pc=0x0c06606eu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c066070;
P_0c066070: /* original d181, guest PC 0x0c066070 */
if(!s->budget--) { s->failed_pc=0x0c066070u; return 0; }
r[1]=read(ram,0x0c066278u,4);
goto P_0c066072;
P_0c066072: /* original 6412, guest PC 0x0c066072 */
if(!s->budget--) { s->failed_pc=0x0c066072u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c066074;
P_0c066074: /* original d081, guest PC 0x0c066074 */
if(!s->budget--) { s->failed_pc=0x0c066074u; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c066076;
P_0c066076: /* original 62b3, guest PC 0x0c066076 */
if(!s->budget--) { s->failed_pc=0x0c066076u; return 0; }
r[2]=r[11];
goto P_0c066078;
P_0c066078: /* original 7b01, guest PC 0x0c066078 */
if(!s->budget--) { s->failed_pc=0x0c066078u; return 0; }
r[11]+=0x00000001u;
goto P_0c06607a;
P_0c06607a: /* original 4208, guest PC 0x0c06607a */
if(!s->budget--) { s->failed_pc=0x0c06607au; return 0; }
r[2]<<=2;
goto P_0c06607c;
P_0c06607c: /* original 02e6, guest PC 0x0c06607c */
if(!s->budget--) { s->failed_pc=0x0c06607cu; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c06607e;
P_0c06607e: /* original 63b3, guest PC 0x0c06607e */
if(!s->budget--) { s->failed_pc=0x0c06607eu; return 0; }
r[3]=r[11];
goto P_0c066080;
P_0c066080: /* original 7b01, guest PC 0x0c066080 */
if(!s->budget--) { s->failed_pc=0x0c066080u; return 0; }
r[11]+=0x00000001u;
goto P_0c066082;
P_0c066082: /* original 4308, guest PC 0x0c066082 */
if(!s->budget--) { s->failed_pc=0x0c066082u; return 0; }
r[3]<<=2;
goto P_0c066084;
P_0c066084: /* original 0356, guest PC 0x0c066084 */
if(!s->budget--) { s->failed_pc=0x0c066084u; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c066086;
P_0c066086: /* original 62b3, guest PC 0x0c066086 */
if(!s->budget--) { s->failed_pc=0x0c066086u; return 0; }
r[2]=r[11];
goto P_0c066088;
P_0c066088: /* original 7b01, guest PC 0x0c066088 */
if(!s->budget--) { s->failed_pc=0x0c066088u; return 0; }
r[11]+=0x00000001u;
goto P_0c06608a;
P_0c06608a: /* original 4208, guest PC 0x0c06608a */
if(!s->budget--) { s->failed_pc=0x0c06608au; return 0; }
r[2]<<=2;
goto P_0c06608c;
P_0c06608c: /* original 0246, guest PC 0x0c06608c */
if(!s->budget--) { s->failed_pc=0x0c06608cu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c06608e;
P_0c06608e: /* original 63b3, guest PC 0x0c06608e */
if(!s->budget--) { s->failed_pc=0x0c06608eu; return 0; }
r[3]=r[11];
goto P_0c066090;
P_0c066090: /* original 62d2, guest PC 0x0c066090 */
if(!s->budget--) { s->failed_pc=0x0c066090u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c066092;
P_0c066092: /* original 7b01, guest PC 0x0c066092 */
if(!s->budget--) { s->failed_pc=0x0c066092u; return 0; }
r[11]+=0x00000001u;
goto P_0c066094;
P_0c066094: /* original 5221, guest PC 0x0c066094 */
if(!s->budget--) { s->failed_pc=0x0c066094u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c066096;
P_0c066096: /* original 4308, guest PC 0x0c066096 */
if(!s->budget--) { s->failed_pc=0x0c066096u; return 0; }
r[3]<<=2;
goto P_0c066098;
P_0c066098: /* original 0326, guest PC 0x0c066098 */
if(!s->budget--) { s->failed_pc=0x0c066098u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06609a;
P_0c06609a: /* original 63b3, guest PC 0x0c06609a */
if(!s->budget--) { s->failed_pc=0x0c06609au; return 0; }
r[3]=r[11];
goto P_0c06609c;
P_0c06609c: /* original 62d2, guest PC 0x0c06609c */
if(!s->budget--) { s->failed_pc=0x0c06609cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c06609e;
P_0c06609e: /* original 7b01, guest PC 0x0c06609e */
if(!s->budget--) { s->failed_pc=0x0c06609eu; return 0; }
r[11]+=0x00000001u;
goto P_0c0660a0;
P_0c0660a0: /* original 5222, guest PC 0x0c0660a0 */
if(!s->budget--) { s->failed_pc=0x0c0660a0u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c0660a2;
P_0c0660a2: /* original 4308, guest PC 0x0c0660a2 */
if(!s->budget--) { s->failed_pc=0x0c0660a2u; return 0; }
r[3]<<=2;
goto P_0c0660a4;
P_0c0660a4: /* original 0326, guest PC 0x0c0660a4 */
if(!s->budget--) { s->failed_pc=0x0c0660a4u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0660a6;
P_0c0660a6: /* original 63b3, guest PC 0x0c0660a6 */
if(!s->budget--) { s->failed_pc=0x0c0660a6u; return 0; }
r[3]=r[11];
goto P_0c0660a8;
P_0c0660a8: /* original 62d2, guest PC 0x0c0660a8 */
if(!s->budget--) { s->failed_pc=0x0c0660a8u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0660aa;
P_0c0660aa: /* original 7b01, guest PC 0x0c0660aa */
if(!s->budget--) { s->failed_pc=0x0c0660aau; return 0; }
r[11]+=0x00000001u;
goto P_0c0660ac;
P_0c0660ac: /* original 5223, guest PC 0x0c0660ac */
if(!s->budget--) { s->failed_pc=0x0c0660acu; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c0660ae;
P_0c0660ae: /* original 4308, guest PC 0x0c0660ae */
if(!s->budget--) { s->failed_pc=0x0c0660aeu; return 0; }
r[3]<<=2;
goto P_0c0660b0;
P_0c0660b0: /* original 0326, guest PC 0x0c0660b0 */
if(!s->budget--) { s->failed_pc=0x0c0660b0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0660b2;
P_0c0660b2: /* original 65b3, guest PC 0x0c0660b2 */
if(!s->budget--) { s->failed_pc=0x0c0660b2u; return 0; }
r[5]=r[11];
goto P_0c0660b4;
P_0c0660b4: /* original d372, guest PC 0x0c0660b4 */
if(!s->budget--) { s->failed_pc=0x0c0660b4u; return 0; }
r[3]=read(ram,0x0c066280u,4);
goto P_0c0660b6;
P_0c0660b6: /* original 66d2, guest PC 0x0c0660b6 */
if(!s->budget--) { s->failed_pc=0x0c0660b6u; return 0; }
tmp=read(ram,r[13],4);
r[6]=tmp;
goto P_0c0660b8;
P_0c0660b8: /* original 5664, guest PC 0x0c0660b8 */
if(!s->budget--) { s->failed_pc=0x0c0660b8u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0660ba;
P_0c0660ba: /* original 430b, guest PC 0x0c0660ba */
if(!s->budget--) { s->failed_pc=0x0c0660bau; return 0; }
target=r[3];
r[16]=0x0c0660beu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0660beu) { target=s->pc; goto dispatch; }
goto P_0c0660be;
P_0c0660bc: /* original 64e3, guest PC 0x0c0660bc */
if(!s->budget--) { s->failed_pc=0x0c0660bcu; return 0; }
r[4]=r[14];
goto P_0c0660be;
P_0c0660be: /* original 6903, guest PC 0x0c0660be */
if(!s->budget--) { s->failed_pc=0x0c0660beu; return 0; }
r[9]=r[0];
goto P_0c0660c0;
P_0c0660c0: /* original 64d2, guest PC 0x0c0660c0 */
if(!s->budget--) { s->failed_pc=0x0c0660c0u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0660c2;
P_0c0660c2: /* original e118, guest PC 0x0c0660c2 */
if(!s->budget--) { s->failed_pc=0x0c0660c2u; return 0; }
r[1]=0x00000018u;
goto P_0c0660c4;
P_0c0660c4: /* original c76f, guest PC 0x0c0660c4 */
if(!s->budget--) { s->failed_pc=0x0c0660c4u; return 0; }
r[0]=0x0c066284u;
goto P_0c0660c6;
P_0c0660c6: /* original 6393, guest PC 0x0c0660c6 */
if(!s->budget--) { s->failed_pc=0x0c0660c6u; return 0; }
r[3]=r[9];
goto P_0c0660c8;
P_0c0660c8: /* original ff08, guest PC 0x0c0660c8 */
if(!s->budget--) { s->failed_pc=0x0c0660c8u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0660ca;
P_0c0660ca: /* original 314c, guest PC 0x0c0660ca */
if(!s->budget--) { s->failed_pc=0x0c0660cau; return 0; }
r[1]+=r[4];
goto P_0c0660cc;
P_0c0660cc: /* original d06b, guest PC 0x0c0660cc */
if(!s->budget--) { s->failed_pc=0x0c0660ccu; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c0660ce;
P_0c0660ce: /* original 7901, guest PC 0x0c0660ce */
if(!s->budget--) { s->failed_pc=0x0c0660ceu; return 0; }
r[9]+=0x00000001u;
goto P_0c0660d0;
P_0c0660d0: /* original f318, guest PC 0x0c0660d0 */
if(!s->budget--) { s->failed_pc=0x0c0660d0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0660d2;
P_0c0660d2: /* original 4308, guest PC 0x0c0660d2 */
if(!s->budget--) { s->failed_pc=0x0c0660d2u; return 0; }
r[3]<<=2;
goto P_0c0660d4;
P_0c0660d4: /* original f3f2, guest PC 0x0c0660d4 */
if(!s->budget--) { s->failed_pc=0x0c0660d4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0660d6;
P_0c0660d6: /* original f33d, guest PC 0x0c0660d6 */
if(!s->budget--) { s->failed_pc=0x0c0660d6u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0660d8;
P_0c0660d8: /* original 045a, guest PC 0x0c0660d8 */
if(!s->budget--) { s->failed_pc=0x0c0660d8u; return 0; }
r[4]=r[53];
goto P_0c0660da;
P_0c0660da: /* original 6243, guest PC 0x0c0660da */
if(!s->budget--) { s->failed_pc=0x0c0660dau; return 0; }
r[2]=r[4];
goto P_0c0660dc;
P_0c0660dc: /* original 4228, guest PC 0x0c0660dc */
if(!s->budget--) { s->failed_pc=0x0c0660dcu; return 0; }
r[2]<<=16;
goto P_0c0660de;
P_0c0660de: /* original 4218, guest PC 0x0c0660de */
if(!s->budget--) { s->failed_pc=0x0c0660deu; return 0; }
r[2]<<=8;
goto P_0c0660e0;
P_0c0660e0: /* original 6143, guest PC 0x0c0660e0 */
if(!s->budget--) { s->failed_pc=0x0c0660e0u; return 0; }
r[1]=r[4];
goto P_0c0660e2;
P_0c0660e2: /* original 4128, guest PC 0x0c0660e2 */
if(!s->budget--) { s->failed_pc=0x0c0660e2u; return 0; }
r[1]<<=16;
goto P_0c0660e4;
P_0c0660e4: /* original 221b, guest PC 0x0c0660e4 */
if(!s->budget--) { s->failed_pc=0x0c0660e4u; return 0; }
r[2]|=r[1];
goto P_0c0660e6;
P_0c0660e6: /* original 6143, guest PC 0x0c0660e6 */
if(!s->budget--) { s->failed_pc=0x0c0660e6u; return 0; }
r[1]=r[4];
goto P_0c0660e8;
P_0c0660e8: /* original 4118, guest PC 0x0c0660e8 */
if(!s->budget--) { s->failed_pc=0x0c0660e8u; return 0; }
r[1]<<=8;
goto P_0c0660ea;
P_0c0660ea: /* original 221b, guest PC 0x0c0660ea */
if(!s->budget--) { s->failed_pc=0x0c0660eau; return 0; }
r[2]|=r[1];
goto P_0c0660ec;
P_0c0660ec: /* original 224b, guest PC 0x0c0660ec */
if(!s->budget--) { s->failed_pc=0x0c0660ecu; return 0; }
r[2]|=r[4];
goto P_0c0660ee;
P_0c0660ee: /* original 0326, guest PC 0x0c0660ee */
if(!s->budget--) { s->failed_pc=0x0c0660eeu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0660f0;
P_0c0660f0: /* original 6bd2, guest PC 0x0c0660f0 */
if(!s->budget--) { s->failed_pc=0x0c0660f0u; return 0; }
tmp=read(ram,r[13],4);
r[11]=tmp;
goto P_0c0660f2;
P_0c0660f2: /* original e01c, guest PC 0x0c0660f2 */
if(!s->budget--) { s->failed_pc=0x0c0660f2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0660f4;
P_0c0660f4: /* original f3b6, guest PC 0x0c0660f4 */
if(!s->budget--) { s->failed_pc=0x0c0660f4u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0660f6;
P_0c0660f6: /* original f3f2, guest PC 0x0c0660f6 */
if(!s->budget--) { s->failed_pc=0x0c0660f6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0660f8;
P_0c0660f8: /* original f33d, guest PC 0x0c0660f8 */
if(!s->budget--) { s->failed_pc=0x0c0660f8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0660fa;
P_0c0660fa: /* original 0b5a, guest PC 0x0c0660fa */
if(!s->budget--) { s->failed_pc=0x0c0660fau; return 0; }
r[11]=r[53];
goto P_0c0660fc;
P_0c0660fc: /* original 66b3, guest PC 0x0c0660fc */
if(!s->budget--) { s->failed_pc=0x0c0660fcu; return 0; }
r[6]=r[11];
goto P_0c0660fe;
P_0c0660fe: /* original 4628, guest PC 0x0c0660fe */
if(!s->budget--) { s->failed_pc=0x0c0660feu; return 0; }
r[6]<<=16;
goto P_0c066100;
P_0c066100: /* original 4618, guest PC 0x0c066100 */
if(!s->budget--) { s->failed_pc=0x0c066100u; return 0; }
r[6]<<=8;
goto P_0c066102;
P_0c066102: /* original 63b3, guest PC 0x0c066102 */
if(!s->budget--) { s->failed_pc=0x0c066102u; return 0; }
r[3]=r[11];
goto P_0c066104;
P_0c066104: /* original 4328, guest PC 0x0c066104 */
if(!s->budget--) { s->failed_pc=0x0c066104u; return 0; }
r[3]<<=16;
goto P_0c066106;
P_0c066106: /* original 263b, guest PC 0x0c066106 */
if(!s->budget--) { s->failed_pc=0x0c066106u; return 0; }
r[6]|=r[3];
goto P_0c066108;
P_0c066108: /* original d35f, guest PC 0x0c066108 */
if(!s->budget--) { s->failed_pc=0x0c066108u; return 0; }
r[3]=read(ram,0x0c066288u,4);
goto P_0c06610a;
P_0c06610a: /* original 62b3, guest PC 0x0c06610a */
if(!s->budget--) { s->failed_pc=0x0c06610au; return 0; }
r[2]=r[11];
goto P_0c06610c;
P_0c06610c: /* original 4218, guest PC 0x0c06610c */
if(!s->budget--) { s->failed_pc=0x0c06610cu; return 0; }
r[2]<<=8;
goto P_0c06610e;
P_0c06610e: /* original 262b, guest PC 0x0c06610e */
if(!s->budget--) { s->failed_pc=0x0c06610eu; return 0; }
r[6]|=r[2];
goto P_0c066110;
P_0c066110: /* original 26bb, guest PC 0x0c066110 */
if(!s->budget--) { s->failed_pc=0x0c066110u; return 0; }
r[6]|=r[11];
goto P_0c066112;
P_0c066112: /* original 6593, guest PC 0x0c066112 */
if(!s->budget--) { s->failed_pc=0x0c066112u; return 0; }
r[5]=r[9];
goto P_0c066114;
P_0c066114: /* original 430b, guest PC 0x0c066114 */
if(!s->budget--) { s->failed_pc=0x0c066114u; return 0; }
target=r[3];
r[16]=0x0c066118u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066118u) { target=s->pc; goto dispatch; }
goto P_0c066118;
P_0c066116: /* original 64e3, guest PC 0x0c066116 */
if(!s->budget--) { s->failed_pc=0x0c066116u; return 0; }
r[4]=r[14];
goto P_0c066118;
P_0c066118: /* original 61c2, guest PC 0x0c066118 */
if(!s->budget--) { s->failed_pc=0x0c066118u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c06611a;
P_0c06611a: /* original 6b03, guest PC 0x0c06611a */
if(!s->budget--) { s->failed_pc=0x0c06611au; return 0; }
r[11]=r[0];
goto P_0c06611c;
P_0c06611c: /* original 5311, guest PC 0x0c06611c */
if(!s->budget--) { s->failed_pc=0x0c06611cu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c06611e;
P_0c06611e: /* original 62b3, guest PC 0x0c06611e */
if(!s->budget--) { s->failed_pc=0x0c06611eu; return 0; }
r[2]=r[11];
goto P_0c066120;
P_0c066120: /* original d056, guest PC 0x0c066120 */
if(!s->budget--) { s->failed_pc=0x0c066120u; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c066122;
P_0c066122: /* original 7b01, guest PC 0x0c066122 */
if(!s->budget--) { s->failed_pc=0x0c066122u; return 0; }
r[11]+=0x00000001u;
goto P_0c066124;
P_0c066124: /* original 4208, guest PC 0x0c066124 */
if(!s->budget--) { s->failed_pc=0x0c066124u; return 0; }
r[2]<<=2;
goto P_0c066126;
P_0c066126: /* original 0236, guest PC 0x0c066126 */
if(!s->budget--) { s->failed_pc=0x0c066126u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c066128;
P_0c066128: /* original 61c2, guest PC 0x0c066128 */
if(!s->budget--) { s->failed_pc=0x0c066128u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c06612a;
P_0c06612a: /* original 62b3, guest PC 0x0c06612a */
if(!s->budget--) { s->failed_pc=0x0c06612au; return 0; }
r[2]=r[11];
goto P_0c06612c;
P_0c06612c: /* original 5312, guest PC 0x0c06612c */
if(!s->budget--) { s->failed_pc=0x0c06612cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c06612e;
P_0c06612e: /* original 7b01, guest PC 0x0c06612e */
if(!s->budget--) { s->failed_pc=0x0c06612eu; return 0; }
r[11]+=0x00000001u;
goto P_0c066130;
P_0c066130: /* original 4208, guest PC 0x0c066130 */
if(!s->budget--) { s->failed_pc=0x0c066130u; return 0; }
r[2]<<=2;
goto P_0c066132;
P_0c066132: /* original 0236, guest PC 0x0c066132 */
if(!s->budget--) { s->failed_pc=0x0c066132u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c066134;
P_0c066134: /* original 61c2, guest PC 0x0c066134 */
if(!s->budget--) { s->failed_pc=0x0c066134u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c066136;
P_0c066136: /* original 62b3, guest PC 0x0c066136 */
if(!s->budget--) { s->failed_pc=0x0c066136u; return 0; }
r[2]=r[11];
goto P_0c066138;
P_0c066138: /* original 5313, guest PC 0x0c066138 */
if(!s->budget--) { s->failed_pc=0x0c066138u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c06613a;
P_0c06613a: /* original 7b01, guest PC 0x0c06613a */
if(!s->budget--) { s->failed_pc=0x0c06613au; return 0; }
r[11]+=0x00000001u;
goto P_0c06613c;
P_0c06613c: /* original 4208, guest PC 0x0c06613c */
if(!s->budget--) { s->failed_pc=0x0c06613cu; return 0; }
r[2]<<=2;
goto P_0c06613e;
P_0c06613e: /* original 0236, guest PC 0x0c06613e */
if(!s->budget--) { s->failed_pc=0x0c06613eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c066140;
P_0c066140: /* original 66c2, guest PC 0x0c066140 */
if(!s->budget--) { s->failed_pc=0x0c066140u; return 0; }
tmp=read(ram,r[12],4);
r[6]=tmp;
goto P_0c066142;
P_0c066142: /* original 65b3, guest PC 0x0c066142 */
if(!s->budget--) { s->failed_pc=0x0c066142u; return 0; }
r[5]=r[11];
goto P_0c066144;
P_0c066144: /* original d34e, guest PC 0x0c066144 */
if(!s->budget--) { s->failed_pc=0x0c066144u; return 0; }
r[3]=read(ram,0x0c066280u,4);
goto P_0c066146;
P_0c066146: /* original 5664, guest PC 0x0c066146 */
if(!s->budget--) { s->failed_pc=0x0c066146u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c066148;
P_0c066148: /* original 430b, guest PC 0x0c066148 */
if(!s->budget--) { s->failed_pc=0x0c066148u; return 0; }
target=r[3];
r[16]=0x0c06614cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06614cu) { target=s->pc; goto dispatch; }
goto P_0c06614c;
P_0c06614a: /* original 64e3, guest PC 0x0c06614a */
if(!s->budget--) { s->failed_pc=0x0c06614au; return 0; }
r[4]=r[14];
goto P_0c06614c;
P_0c06614c: /* original 64c2, guest PC 0x0c06614c */
if(!s->budget--) { s->failed_pc=0x0c06614cu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c06614e;
P_0c06614e: /* original e118, guest PC 0x0c06614e */
if(!s->budget--) { s->failed_pc=0x0c06614eu; return 0; }
r[1]=0x00000018u;
goto P_0c066150;
P_0c066150: /* original 6903, guest PC 0x0c066150 */
if(!s->budget--) { s->failed_pc=0x0c066150u; return 0; }
r[9]=r[0];
goto P_0c066152;
P_0c066152: /* original 6293, guest PC 0x0c066152 */
if(!s->budget--) { s->failed_pc=0x0c066152u; return 0; }
r[2]=r[9];
goto P_0c066154;
P_0c066154: /* original d049, guest PC 0x0c066154 */
if(!s->budget--) { s->failed_pc=0x0c066154u; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c066156;
P_0c066156: /* original 314c, guest PC 0x0c066156 */
if(!s->budget--) { s->failed_pc=0x0c066156u; return 0; }
r[1]+=r[4];
goto P_0c066158;
P_0c066158: /* original f318, guest PC 0x0c066158 */
if(!s->budget--) { s->failed_pc=0x0c066158u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06615a;
P_0c06615a: /* original 7901, guest PC 0x0c06615a */
if(!s->budget--) { s->failed_pc=0x0c06615au; return 0; }
r[9]+=0x00000001u;
goto P_0c06615c;
P_0c06615c: /* original 4208, guest PC 0x0c06615c */
if(!s->budget--) { s->failed_pc=0x0c06615cu; return 0; }
r[2]<<=2;
goto P_0c06615e;
P_0c06615e: /* original f3f2, guest PC 0x0c06615e */
if(!s->budget--) { s->failed_pc=0x0c06615eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c066160;
P_0c066160: /* original f33d, guest PC 0x0c066160 */
if(!s->budget--) { s->failed_pc=0x0c066160u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c066162;
P_0c066162: /* original 045a, guest PC 0x0c066162 */
if(!s->budget--) { s->failed_pc=0x0c066162u; return 0; }
r[4]=r[53];
goto P_0c066164;
P_0c066164: /* original 6343, guest PC 0x0c066164 */
if(!s->budget--) { s->failed_pc=0x0c066164u; return 0; }
r[3]=r[4];
goto P_0c066166;
P_0c066166: /* original 4328, guest PC 0x0c066166 */
if(!s->budget--) { s->failed_pc=0x0c066166u; return 0; }
r[3]<<=16;
goto P_0c066168;
P_0c066168: /* original 4318, guest PC 0x0c066168 */
if(!s->budget--) { s->failed_pc=0x0c066168u; return 0; }
r[3]<<=8;
goto P_0c06616a;
P_0c06616a: /* original 6143, guest PC 0x0c06616a */
if(!s->budget--) { s->failed_pc=0x0c06616au; return 0; }
r[1]=r[4];
goto P_0c06616c;
P_0c06616c: /* original 4128, guest PC 0x0c06616c */
if(!s->budget--) { s->failed_pc=0x0c06616cu; return 0; }
r[1]<<=16;
goto P_0c06616e;
P_0c06616e: /* original 231b, guest PC 0x0c06616e */
if(!s->budget--) { s->failed_pc=0x0c06616eu; return 0; }
r[3]|=r[1];
goto P_0c066170;
P_0c066170: /* original 6143, guest PC 0x0c066170 */
if(!s->budget--) { s->failed_pc=0x0c066170u; return 0; }
r[1]=r[4];
goto P_0c066172;
P_0c066172: /* original 4118, guest PC 0x0c066172 */
if(!s->budget--) { s->failed_pc=0x0c066172u; return 0; }
r[1]<<=8;
goto P_0c066174;
P_0c066174: /* original 231b, guest PC 0x0c066174 */
if(!s->budget--) { s->failed_pc=0x0c066174u; return 0; }
r[3]|=r[1];
goto P_0c066176;
P_0c066176: /* original 234b, guest PC 0x0c066176 */
if(!s->budget--) { s->failed_pc=0x0c066176u; return 0; }
r[3]|=r[4];
goto P_0c066178;
P_0c066178: /* original 0236, guest PC 0x0c066178 */
if(!s->budget--) { s->failed_pc=0x0c066178u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06617a;
P_0c06617a: /* original e01c, guest PC 0x0c06617a */
if(!s->budget--) { s->failed_pc=0x0c06617au; return 0; }
r[0]=0x0000001cu;
goto P_0c06617c;
P_0c06617c: /* original 6bc2, guest PC 0x0c06617c */
if(!s->budget--) { s->failed_pc=0x0c06617cu; return 0; }
tmp=read(ram,r[12],4);
r[11]=tmp;
goto P_0c06617e;
P_0c06617e: /* original f3b6, guest PC 0x0c06617e */
if(!s->budget--) { s->failed_pc=0x0c06617eu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c066180;
P_0c066180: /* original f3f2, guest PC 0x0c066180 */
if(!s->budget--) { s->failed_pc=0x0c066180u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c066182;
P_0c066182: /* original f33d, guest PC 0x0c066182 */
if(!s->budget--) { s->failed_pc=0x0c066182u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c066184;
P_0c066184: /* original 0b5a, guest PC 0x0c066184 */
if(!s->budget--) { s->failed_pc=0x0c066184u; return 0; }
r[11]=r[53];
goto P_0c066186;
P_0c066186: /* original 66b3, guest PC 0x0c066186 */
if(!s->budget--) { s->failed_pc=0x0c066186u; return 0; }
r[6]=r[11];
goto P_0c066188;
P_0c066188: /* original 4628, guest PC 0x0c066188 */
if(!s->budget--) { s->failed_pc=0x0c066188u; return 0; }
r[6]<<=16;
goto P_0c06618a;
P_0c06618a: /* original 4618, guest PC 0x0c06618a */
if(!s->budget--) { s->failed_pc=0x0c06618au; return 0; }
r[6]<<=8;
goto P_0c06618c;
P_0c06618c: /* original 63b3, guest PC 0x0c06618c */
if(!s->budget--) { s->failed_pc=0x0c06618cu; return 0; }
r[3]=r[11];
goto P_0c06618e;
P_0c06618e: /* original 4328, guest PC 0x0c06618e */
if(!s->budget--) { s->failed_pc=0x0c06618eu; return 0; }
r[3]<<=16;
goto P_0c066190;
P_0c066190: /* original 263b, guest PC 0x0c066190 */
if(!s->budget--) { s->failed_pc=0x0c066190u; return 0; }
r[6]|=r[3];
goto P_0c066192;
P_0c066192: /* original 62b3, guest PC 0x0c066192 */
if(!s->budget--) { s->failed_pc=0x0c066192u; return 0; }
r[2]=r[11];
goto P_0c066194;
P_0c066194: /* original d33c, guest PC 0x0c066194 */
if(!s->budget--) { s->failed_pc=0x0c066194u; return 0; }
r[3]=read(ram,0x0c066288u,4);
goto P_0c066196;
P_0c066196: /* original 6593, guest PC 0x0c066196 */
if(!s->budget--) { s->failed_pc=0x0c066196u; return 0; }
r[5]=r[9];
goto P_0c066198;
P_0c066198: /* original 4218, guest PC 0x0c066198 */
if(!s->budget--) { s->failed_pc=0x0c066198u; return 0; }
r[2]<<=8;
goto P_0c06619a;
P_0c06619a: /* original 262b, guest PC 0x0c06619a */
if(!s->budget--) { s->failed_pc=0x0c06619au; return 0; }
r[6]|=r[2];
goto P_0c06619c;
P_0c06619c: /* original 26bb, guest PC 0x0c06619c */
if(!s->budget--) { s->failed_pc=0x0c06619cu; return 0; }
r[6]|=r[11];
goto P_0c06619e;
P_0c06619e: /* original 430b, guest PC 0x0c06619e */
if(!s->budget--) { s->failed_pc=0x0c06619eu; return 0; }
target=r[3];
r[16]=0x0c0661a2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0661a2u) { target=s->pc; goto dispatch; }
goto P_0c0661a2;
P_0c0661a0: /* original 64e3, guest PC 0x0c0661a0 */
if(!s->budget--) { s->failed_pc=0x0c0661a0u; return 0; }
r[4]=r[14];
goto P_0c0661a2;
P_0c0661a2: /* original 6c03, guest PC 0x0c0661a2 */
if(!s->budget--) { s->failed_pc=0x0c0661a2u; return 0; }
r[12]=r[0];
goto P_0c0661a4;
P_0c0661a4: /* original 61a2, guest PC 0x0c0661a4 */
if(!s->budget--) { s->failed_pc=0x0c0661a4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0661a6;
P_0c0661a6: /* original 62c3, guest PC 0x0c0661a6 */
if(!s->budget--) { s->failed_pc=0x0c0661a6u; return 0; }
r[2]=r[12];
goto P_0c0661a8;
P_0c0661a8: /* original d034, guest PC 0x0c0661a8 */
if(!s->budget--) { s->failed_pc=0x0c0661a8u; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c0661aa;
P_0c0661aa: /* original 7c01, guest PC 0x0c0661aa */
if(!s->budget--) { s->failed_pc=0x0c0661aau; return 0; }
r[12]+=0x00000001u;
goto P_0c0661ac;
P_0c0661ac: /* original 5311, guest PC 0x0c0661ac */
if(!s->budget--) { s->failed_pc=0x0c0661acu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0661ae;
P_0c0661ae: /* original 4208, guest PC 0x0c0661ae */
if(!s->budget--) { s->failed_pc=0x0c0661aeu; return 0; }
r[2]<<=2;
goto P_0c0661b0;
P_0c0661b0: /* original 0236, guest PC 0x0c0661b0 */
if(!s->budget--) { s->failed_pc=0x0c0661b0u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0661b2;
P_0c0661b2: /* original 62c3, guest PC 0x0c0661b2 */
if(!s->budget--) { s->failed_pc=0x0c0661b2u; return 0; }
r[2]=r[12];
goto P_0c0661b4;
P_0c0661b4: /* original 61a2, guest PC 0x0c0661b4 */
if(!s->budget--) { s->failed_pc=0x0c0661b4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0661b6;
P_0c0661b6: /* original 7c01, guest PC 0x0c0661b6 */
if(!s->budget--) { s->failed_pc=0x0c0661b6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0661b8;
P_0c0661b8: /* original 5312, guest PC 0x0c0661b8 */
if(!s->budget--) { s->failed_pc=0x0c0661b8u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0661ba;
P_0c0661ba: /* original 4208, guest PC 0x0c0661ba */
if(!s->budget--) { s->failed_pc=0x0c0661bau; return 0; }
r[2]<<=2;
goto P_0c0661bc;
P_0c0661bc: /* original 0236, guest PC 0x0c0661bc */
if(!s->budget--) { s->failed_pc=0x0c0661bcu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0661be;
P_0c0661be: /* original 62c3, guest PC 0x0c0661be */
if(!s->budget--) { s->failed_pc=0x0c0661beu; return 0; }
r[2]=r[12];
goto P_0c0661c0;
P_0c0661c0: /* original 61a2, guest PC 0x0c0661c0 */
if(!s->budget--) { s->failed_pc=0x0c0661c0u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0661c2;
P_0c0661c2: /* original 7c01, guest PC 0x0c0661c2 */
if(!s->budget--) { s->failed_pc=0x0c0661c2u; return 0; }
r[12]+=0x00000001u;
goto P_0c0661c4;
P_0c0661c4: /* original 5313, guest PC 0x0c0661c4 */
if(!s->budget--) { s->failed_pc=0x0c0661c4u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0661c6;
P_0c0661c6: /* original 4208, guest PC 0x0c0661c6 */
if(!s->budget--) { s->failed_pc=0x0c0661c6u; return 0; }
r[2]<<=2;
goto P_0c0661c8;
P_0c0661c8: /* original 0236, guest PC 0x0c0661c8 */
if(!s->budget--) { s->failed_pc=0x0c0661c8u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0661ca;
P_0c0661ca: /* original 65c3, guest PC 0x0c0661ca */
if(!s->budget--) { s->failed_pc=0x0c0661cau; return 0; }
r[5]=r[12];
goto P_0c0661cc;
P_0c0661cc: /* original d32c, guest PC 0x0c0661cc */
if(!s->budget--) { s->failed_pc=0x0c0661ccu; return 0; }
r[3]=read(ram,0x0c066280u,4);
goto P_0c0661ce;
P_0c0661ce: /* original 66a2, guest PC 0x0c0661ce */
if(!s->budget--) { s->failed_pc=0x0c0661ceu; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c0661d0;
P_0c0661d0: /* original 5664, guest PC 0x0c0661d0 */
if(!s->budget--) { s->failed_pc=0x0c0661d0u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0661d2;
P_0c0661d2: /* original 430b, guest PC 0x0c0661d2 */
if(!s->budget--) { s->failed_pc=0x0c0661d2u; return 0; }
target=r[3];
r[16]=0x0c0661d6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0661d6u) { target=s->pc; goto dispatch; }
goto P_0c0661d6;
P_0c0661d4: /* original 64e3, guest PC 0x0c0661d4 */
if(!s->budget--) { s->failed_pc=0x0c0661d4u; return 0; }
r[4]=r[14];
goto P_0c0661d6;
P_0c0661d6: /* original 6b03, guest PC 0x0c0661d6 */
if(!s->budget--) { s->failed_pc=0x0c0661d6u; return 0; }
r[11]=r[0];
goto P_0c0661d8;
P_0c0661d8: /* original 64a2, guest PC 0x0c0661d8 */
if(!s->budget--) { s->failed_pc=0x0c0661d8u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0661da;
P_0c0661da: /* original e118, guest PC 0x0c0661da */
if(!s->budget--) { s->failed_pc=0x0c0661dau; return 0; }
r[1]=0x00000018u;
goto P_0c0661dc;
P_0c0661dc: /* original d027, guest PC 0x0c0661dc */
if(!s->budget--) { s->failed_pc=0x0c0661dcu; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c0661de;
P_0c0661de: /* original 62b3, guest PC 0x0c0661de */
if(!s->budget--) { s->failed_pc=0x0c0661deu; return 0; }
r[2]=r[11];
goto P_0c0661e0;
P_0c0661e0: /* original 7b01, guest PC 0x0c0661e0 */
if(!s->budget--) { s->failed_pc=0x0c0661e0u; return 0; }
r[11]+=0x00000001u;
goto P_0c0661e2;
P_0c0661e2: /* original 4208, guest PC 0x0c0661e2 */
if(!s->budget--) { s->failed_pc=0x0c0661e2u; return 0; }
r[2]<<=2;
goto P_0c0661e4;
P_0c0661e4: /* original 314c, guest PC 0x0c0661e4 */
if(!s->budget--) { s->failed_pc=0x0c0661e4u; return 0; }
r[1]+=r[4];
goto P_0c0661e6;
P_0c0661e6: /* original f318, guest PC 0x0c0661e6 */
if(!s->budget--) { s->failed_pc=0x0c0661e6u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0661e8;
P_0c0661e8: /* original f3f2, guest PC 0x0c0661e8 */
if(!s->budget--) { s->failed_pc=0x0c0661e8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0661ea;
P_0c0661ea: /* original f33d, guest PC 0x0c0661ea */
if(!s->budget--) { s->failed_pc=0x0c0661eau; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0661ec;
P_0c0661ec: /* original 045a, guest PC 0x0c0661ec */
if(!s->budget--) { s->failed_pc=0x0c0661ecu; return 0; }
r[4]=r[53];
goto P_0c0661ee;
P_0c0661ee: /* original 6343, guest PC 0x0c0661ee */
if(!s->budget--) { s->failed_pc=0x0c0661eeu; return 0; }
r[3]=r[4];
goto P_0c0661f0;
P_0c0661f0: /* original 4328, guest PC 0x0c0661f0 */
if(!s->budget--) { s->failed_pc=0x0c0661f0u; return 0; }
r[3]<<=16;
goto P_0c0661f2;
P_0c0661f2: /* original 4318, guest PC 0x0c0661f2 */
if(!s->budget--) { s->failed_pc=0x0c0661f2u; return 0; }
r[3]<<=8;
goto P_0c0661f4;
P_0c0661f4: /* original 6143, guest PC 0x0c0661f4 */
if(!s->budget--) { s->failed_pc=0x0c0661f4u; return 0; }
r[1]=r[4];
goto P_0c0661f6;
P_0c0661f6: /* original 4128, guest PC 0x0c0661f6 */
if(!s->budget--) { s->failed_pc=0x0c0661f6u; return 0; }
r[1]<<=16;
goto P_0c0661f8;
P_0c0661f8: /* original 231b, guest PC 0x0c0661f8 */
if(!s->budget--) { s->failed_pc=0x0c0661f8u; return 0; }
r[3]|=r[1];
goto P_0c0661fa;
P_0c0661fa: /* original 6143, guest PC 0x0c0661fa */
if(!s->budget--) { s->failed_pc=0x0c0661fau; return 0; }
r[1]=r[4];
goto P_0c0661fc;
P_0c0661fc: /* original 4118, guest PC 0x0c0661fc */
if(!s->budget--) { s->failed_pc=0x0c0661fcu; return 0; }
r[1]<<=8;
goto P_0c0661fe;
P_0c0661fe: /* original 231b, guest PC 0x0c0661fe */
if(!s->budget--) { s->failed_pc=0x0c0661feu; return 0; }
r[3]|=r[1];
goto P_0c066200;
P_0c066200: /* original 234b, guest PC 0x0c066200 */
if(!s->budget--) { s->failed_pc=0x0c066200u; return 0; }
r[3]|=r[4];
goto P_0c066202;
P_0c066202: /* original 0236, guest PC 0x0c066202 */
if(!s->budget--) { s->failed_pc=0x0c066202u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c066204;
P_0c066204: /* original 6ca2, guest PC 0x0c066204 */
if(!s->budget--) { s->failed_pc=0x0c066204u; return 0; }
tmp=read(ram,r[10],4);
r[12]=tmp;
goto P_0c066206;
P_0c066206: /* original e01c, guest PC 0x0c066206 */
if(!s->budget--) { s->failed_pc=0x0c066206u; return 0; }
r[0]=0x0000001cu;
goto P_0c066208;
P_0c066208: /* original f3c6, guest PC 0x0c066208 */
if(!s->budget--) { s->failed_pc=0x0c066208u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06620a;
P_0c06620a: /* original f3f2, guest PC 0x0c06620a */
if(!s->budget--) { s->failed_pc=0x0c06620au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06620c;
P_0c06620c: /* original f33d, guest PC 0x0c06620c */
if(!s->budget--) { s->failed_pc=0x0c06620cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06620e;
P_0c06620e: /* original 0c5a, guest PC 0x0c06620e */
if(!s->budget--) { s->failed_pc=0x0c06620eu; return 0; }
r[12]=r[53];
goto P_0c066210;
P_0c066210: /* original 66c3, guest PC 0x0c066210 */
if(!s->budget--) { s->failed_pc=0x0c066210u; return 0; }
r[6]=r[12];
goto P_0c066212;
P_0c066212: /* original 4628, guest PC 0x0c066212 */
if(!s->budget--) { s->failed_pc=0x0c066212u; return 0; }
r[6]<<=16;
goto P_0c066214;
P_0c066214: /* original 4618, guest PC 0x0c066214 */
if(!s->budget--) { s->failed_pc=0x0c066214u; return 0; }
r[6]<<=8;
goto P_0c066216;
P_0c066216: /* original 63c3, guest PC 0x0c066216 */
if(!s->budget--) { s->failed_pc=0x0c066216u; return 0; }
r[3]=r[12];
goto P_0c066218;
P_0c066218: /* original 4328, guest PC 0x0c066218 */
if(!s->budget--) { s->failed_pc=0x0c066218u; return 0; }
r[3]<<=16;
goto P_0c06621a;
P_0c06621a: /* original 263b, guest PC 0x0c06621a */
if(!s->budget--) { s->failed_pc=0x0c06621au; return 0; }
r[6]|=r[3];
goto P_0c06621c;
P_0c06621c: /* original d31a, guest PC 0x0c06621c */
if(!s->budget--) { s->failed_pc=0x0c06621cu; return 0; }
r[3]=read(ram,0x0c066288u,4);
goto P_0c06621e;
P_0c06621e: /* original 62c3, guest PC 0x0c06621e */
if(!s->budget--) { s->failed_pc=0x0c06621eu; return 0; }
r[2]=r[12];
goto P_0c066220;
P_0c066220: /* original 4218, guest PC 0x0c066220 */
if(!s->budget--) { s->failed_pc=0x0c066220u; return 0; }
r[2]<<=8;
goto P_0c066222;
P_0c066222: /* original 262b, guest PC 0x0c066222 */
if(!s->budget--) { s->failed_pc=0x0c066222u; return 0; }
r[6]|=r[2];
goto P_0c066224;
P_0c066224: /* original 26cb, guest PC 0x0c066224 */
if(!s->budget--) { s->failed_pc=0x0c066224u; return 0; }
r[6]|=r[12];
goto P_0c066226;
P_0c066226: /* original 65b3, guest PC 0x0c066226 */
if(!s->budget--) { s->failed_pc=0x0c066226u; return 0; }
r[5]=r[11];
goto P_0c066228;
P_0c066228: /* original 430b, guest PC 0x0c066228 */
if(!s->budget--) { s->failed_pc=0x0c066228u; return 0; }
target=r[3];
r[16]=0x0c06622cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06622cu) { target=s->pc; goto dispatch; }
goto P_0c06622c;
P_0c06622a: /* original 64e3, guest PC 0x0c06622a */
if(!s->budget--) { s->failed_pc=0x0c06622au; return 0; }
r[4]=r[14];
goto P_0c06622c;
P_0c06622c: /* original d217, guest PC 0x0c06622c */
if(!s->budget--) { s->failed_pc=0x0c06622cu; return 0; }
r[2]=read(ram,0x0c06628cu,4);
goto P_0c06622e;
P_0c06622e: /* original 6403, guest PC 0x0c06622e */
if(!s->budget--) { s->failed_pc=0x0c06622eu; return 0; }
r[4]=r[0];
goto P_0c066230;
P_0c066230: /* original 4408, guest PC 0x0c066230 */
if(!s->budget--) { s->failed_pc=0x0c066230u; return 0; }
r[4]<<=2;
goto P_0c066232;
P_0c066232: /* original 2242, guest PC 0x0c066232 */
if(!s->budget--) { s->failed_pc=0x0c066232u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c066234;
P_0c066234: /* original d316, guest PC 0x0c066234 */
if(!s->budget--) { s->failed_pc=0x0c066234u; return 0; }
r[3]=read(ram,0x0c066290u,4);
goto P_0c066236;
P_0c066236: /* original 430b, guest PC 0x0c066236 */
if(!s->budget--) { s->failed_pc=0x0c066236u; return 0; }
target=r[3];
r[16]=0x0c06623au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06623au) { target=s->pc; goto dispatch; }
goto P_0c06623a;
P_0c066238: /* original 64e3, guest PC 0x0c066238 */
if(!s->budget--) { s->failed_pc=0x0c066238u; return 0; }
r[4]=r[14];
goto P_0c06623a;
P_0c06623a: /* original 6403, guest PC 0x0c06623a */
if(!s->budget--) { s->failed_pc=0x0c06623au; return 0; }
r[4]=r[0];
goto P_0c06623c;
P_0c06623c: /* original d215, guest PC 0x0c06623c */
if(!s->budget--) { s->failed_pc=0x0c06623cu; return 0; }
r[2]=read(ram,0x0c066294u,4);
goto P_0c06623e;
P_0c06623e: /* original e500, guest PC 0x0c06623e */
if(!s->budget--) { s->failed_pc=0x0c06623eu; return 0; }
r[5]=0x00000000u;
goto P_0c066240;
P_0c066240: /* original 420b, guest PC 0x0c066240 */
if(!s->budget--) { s->failed_pc=0x0c066240u; return 0; }
target=r[2];
r[16]=0x0c066244u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066244u) { target=s->pc; goto dispatch; }
goto P_0c066244;
P_0c066242: /* original 6653, guest PC 0x0c066242 */
if(!s->budget--) { s->failed_pc=0x0c066242u; return 0; }
r[6]=r[5];
goto P_0c066244;
P_0c066244: /* original 62d2, guest PC 0x0c066244 */
if(!s->budget--) { s->failed_pc=0x0c066244u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c066246;
P_0c066246: /* original 5323, guest PC 0x0c066246 */
if(!s->budget--) { s->failed_pc=0x0c066246u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c066248;
P_0c066248: /* original d113, guest PC 0x0c066248 */
if(!s->budget--) { s->failed_pc=0x0c066248u; return 0; }
r[1]=read(ram,0x0c066298u,4);
goto P_0c06624a;
P_0c06624a: /* original 2132, guest PC 0x0c06624a */
if(!s->budget--) { s->failed_pc=0x0c06624au; return 0; }
write(ram,r[1],r[3],4);
goto P_0c06624c;
P_0c06624c: /* original e000, guest PC 0x0c06624c */
if(!s->budget--) { s->failed_pc=0x0c06624cu; return 0; }
r[0]=0x00000000u;
goto P_0c06624e;
P_0c06624e: /* original 7f0c, guest PC 0x0c06624e */
if(!s->budget--) { s->failed_pc=0x0c06624eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c066250;
P_0c066250: /* original 4f26, guest PC 0x0c066250 */
if(!s->budget--) { s->failed_pc=0x0c066250u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066252;
P_0c066252: /* original fff9, guest PC 0x0c066252 */
if(!s->budget--) { s->failed_pc=0x0c066252u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c066254;
P_0c066254: /* original 69f6, guest PC 0x0c066254 */
if(!s->budget--) { s->failed_pc=0x0c066254u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c066256;
P_0c066256: /* original 6af6, guest PC 0x0c066256 */
if(!s->budget--) { s->failed_pc=0x0c066256u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c066258;
P_0c066258: /* original 6bf6, guest PC 0x0c066258 */
if(!s->budget--) { s->failed_pc=0x0c066258u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06625a;
P_0c06625a: /* original 6cf6, guest PC 0x0c06625a */
if(!s->budget--) { s->failed_pc=0x0c06625au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06625c;
P_0c06625c: /* original 6df6, guest PC 0x0c06625c */
if(!s->budget--) { s->failed_pc=0x0c06625cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06625e;
P_0c06625e: /* original 000b, guest PC 0x0c06625e */
if(!s->budget--) { s->failed_pc=0x0c06625eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c066260: /* original 6ef6, guest PC 0x0c066260 */
if(!s->budget--) { s->failed_pc=0x0c066260u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c066262u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c064530u,0x0c064532u,0x0c064534u,0x0c064536u,0x0c064538u,0x0c06453au,0x0c06453cu,0x0c06453eu,0x0c064540u,0x0c064542u,0x0c064544u,0x0c064546u,0x0c064548u,0x0c06454au,0x0c06454cu,0x0c06454eu,
0x0c064550u,0x0c064552u,0x0c064554u,0x0c064556u,0x0c064558u,0x0c06455au,0x0c06455cu,0x0c06455eu,0x0c064560u,0x0c064562u,0x0c064564u,0x0c064566u,0x0c064568u,0x0c06456au,0x0c06456cu,0x0c06456eu,
0x0c064570u,0x0c064572u,0x0c064574u,0x0c064576u,0x0c064578u,0x0c06457au,0x0c06457cu,0x0c06457eu,0x0c064580u,0x0c064582u,0x0c064584u,0x0c064586u,0x0c064588u,0x0c06458au,0x0c06458cu,0x0c06458eu,
0x0c064590u,0x0c064592u,0x0c064772u,0x0c064774u,0x0c064776u,0x0c064778u,0x0c06477au,0x0c06477cu,0x0c06477eu,0x0c064780u,0x0c064782u,0x0c064784u,0x0c064786u,0x0c064788u,0x0c06478au,0x0c06478cu,
0x0c06478eu,0x0c064790u,0x0c064792u,0x0c064794u,0x0c064796u,0x0c064798u,0x0c06479au,0x0c06479cu,0x0c06479eu,0x0c0647a0u,0x0c0647a2u,0x0c0647a4u,0x0c0647a6u,0x0c0647a8u,0x0c0647aau,0x0c0647acu,
0x0c0647aeu,0x0c0647b0u,0x0c0647b2u,0x0c0647b4u,0x0c0647b6u,0x0c0647b8u,0x0c0647bau,0x0c0647bcu,0x0c0647beu,0x0c0647c0u,0x0c0647c2u,0x0c0647c4u,0x0c0647c6u,0x0c0647c8u,0x0c0647cau,0x0c0647ccu,
0x0c0647ceu,0x0c0647d0u,0x0c0647d2u,0x0c0647d4u,0x0c0647d6u,0x0c0647d8u,0x0c0647dau,0x0c0647dcu,0x0c0647deu,0x0c0647e0u,0x0c0647e2u,0x0c0647e4u,0x0c0647e6u,0x0c0647e8u,0x0c0647eau,0x0c0647ecu,
0x0c0647eeu,0x0c0647f0u,0x0c0647f2u,0x0c0647f4u,0x0c0647f6u,0x0c0647f8u,0x0c0647fau,0x0c0647fcu,0x0c0647feu,0x0c064800u,0x0c064802u,0x0c064804u,0x0c064806u,0x0c064808u,0x0c06480au,0x0c06480cu,
0x0c06480eu,0x0c064810u,0x0c064812u,0x0c064814u,0x0c064816u,0x0c064818u,0x0c06481au,0x0c06481cu,0x0c06481eu,0x0c064820u,0x0c064822u,0x0c064824u,0x0c064826u,0x0c064828u,0x0c06482au,0x0c06482cu,
0x0c06482eu,0x0c064830u,0x0c064832u,0x0c064834u,0x0c064836u,0x0c064838u,0x0c06483au,0x0c06483cu,0x0c06483eu,0x0c064840u,0x0c064842u,0x0c064844u,0x0c064846u,0x0c064848u,0x0c06484au,0x0c06484cu,
0x0c06484eu,0x0c064850u,0x0c064852u,0x0c064854u,0x0c064856u,0x0c064858u,0x0c06485au,0x0c06485cu,0x0c06485eu,0x0c064860u,0x0c064862u,0x0c064864u,0x0c064866u,0x0c064868u,0x0c06486au,0x0c06486cu,
0x0c06486eu,0x0c064870u,0x0c064872u,0x0c064874u,0x0c064876u,0x0c064878u,0x0c06487au,0x0c06487cu,0x0c06487eu,0x0c064880u,0x0c064882u,0x0c064884u,0x0c064886u,0x0c064888u,0x0c06488au,0x0c06488cu,
0x0c06488eu,0x0c064890u,0x0c064892u,0x0c064894u,0x0c064896u,0x0c064898u,0x0c06489au,0x0c06489cu,0x0c06489eu,0x0c0648a0u,0x0c0648a2u,0x0c0648a4u,0x0c0648a6u,0x0c0648a8u,0x0c0648aau,0x0c0648acu,
0x0c0648aeu,0x0c0648b0u,0x0c0648b2u,0x0c0648b4u,0x0c0648b6u,0x0c0648b8u,0x0c0648bau,0x0c0648bcu,0x0c0648beu,0x0c0648c0u,0x0c0648c2u,0x0c0648c4u,0x0c0648c6u,0x0c0648c8u,0x0c0648cau,0x0c0648ccu,
0x0c0648ceu,0x0c0648d0u,0x0c0648d2u,0x0c0648d4u,0x0c0648d6u,0x0c0648d8u,0x0c0648dau,0x0c0648dcu,0x0c0648deu,0x0c0648e0u,0x0c0648e2u,0x0c0648e4u,0x0c0648e6u,0x0c0648e8u,0x0c0648eau,0x0c0648ecu,
0x0c0648eeu,0x0c0648f0u,0x0c0648f2u,0x0c0648f4u,0x0c0648f6u,0x0c0648f8u,0x0c0648fau,0x0c0648fcu,0x0c0648feu,0x0c064900u,0x0c064902u,0x0c064904u,0x0c064906u,0x0c064908u,0x0c06490au,0x0c06490cu,
0x0c06490eu,0x0c064910u,0x0c064912u,0x0c064914u,0x0c064916u,0x0c064918u,0x0c06491au,0x0c06491cu,0x0c06491eu,0x0c064920u,0x0c064922u,0x0c064924u,0x0c064926u,0x0c064928u,0x0c064ab8u,0x0c064abau,
0x0c064abcu,0x0c064abeu,0x0c064ac0u,0x0c064ac2u,0x0c064ac4u,0x0c064ac6u,0x0c064ac8u,0x0c064acau,0x0c064accu,0x0c064aceu,0x0c064ad0u,0x0c064ad2u,0x0c064ad4u,0x0c064ad6u,0x0c064ad8u,0x0c064adau,
0x0c064adcu,0x0c064adeu,0x0c064ae0u,0x0c064ae2u,0x0c064ae4u,0x0c064ae6u,0x0c064ae8u,0x0c064aeau,0x0c064aecu,0x0c064aeeu,0x0c064af0u,0x0c064af2u,0x0c064af4u,0x0c064af6u,0x0c064af8u,0x0c064afau,
0x0c064afcu,0x0c064afeu,0x0c064b00u,0x0c064b02u,0x0c064b04u,0x0c064b06u,0x0c064b08u,0x0c064b0au,0x0c064b0cu,0x0c064b0eu,0x0c064b10u,0x0c064b12u,0x0c064b14u,0x0c064b16u,0x0c064b18u,0x0c064b1au,
0x0c064b1cu,0x0c064b1eu,0x0c064b20u,0x0c064b22u,0x0c064b24u,0x0c064b26u,0x0c064b28u,0x0c064b2au,0x0c064b2cu,0x0c064b2eu,0x0c064b30u,0x0c064b32u,0x0c064b34u,0x0c064b36u,0x0c064b38u,0x0c064b3au,
0x0c064b3cu,0x0c064b3eu,0x0c064b40u,0x0c064b42u,0x0c064b44u,0x0c064b46u,0x0c064b48u,0x0c064b4au,0x0c064b4cu,0x0c064b4eu,0x0c064b50u,0x0c064b52u,0x0c064b54u,0x0c064b56u,0x0c064b58u,0x0c064b5au,
0x0c064b5cu,0x0c064b5eu,0x0c064b60u,0x0c064b62u,0x0c064b64u,0x0c064b66u,0x0c064b68u,0x0c064b6au,0x0c064b6cu,0x0c064b6eu,0x0c064b70u,0x0c064b72u,0x0c064b74u,0x0c064b76u,0x0c064b78u,0x0c064b7au,
0x0c064b7cu,0x0c064b7eu,0x0c064b80u,0x0c064b82u,0x0c064b84u,0x0c064b86u,0x0c064b88u,0x0c064b8au,0x0c064b8cu,0x0c064b8eu,0x0c064b90u,0x0c064b92u,0x0c064b94u,0x0c064b96u,0x0c064b98u,0x0c064b9au,
0x0c064b9cu,0x0c064b9eu,0x0c064ba0u,0x0c064ba2u,0x0c064ba4u,0x0c064ba6u,0x0c064ba8u,0x0c064baau,0x0c064bacu,0x0c064baeu,0x0c064bb0u,0x0c064bb2u,0x0c064bb4u,0x0c064bb6u,0x0c064bb8u,0x0c064bbau,
0x0c064bbcu,0x0c064bbeu,0x0c064bc0u,0x0c064bc2u,0x0c064bc4u,0x0c064bc6u,0x0c064bc8u,0x0c064bcau,0x0c064bccu,0x0c064bceu,0x0c064bd0u,0x0c064bd2u,0x0c064bd4u,0x0c064bd6u,0x0c064bd8u,0x0c064bdau,
0x0c064bdcu,0x0c064bdeu,0x0c064be0u,0x0c064be2u,0x0c064be4u,0x0c064be6u,0x0c064be8u,0x0c064beau,0x0c064becu,0x0c064beeu,0x0c064bf0u,0x0c064bf2u,0x0c064bf4u,0x0c064bf6u,0x0c064bf8u,0x0c064bfau,
0x0c064bfcu,0x0c064bfeu,0x0c064c00u,0x0c064c02u,0x0c064c04u,0x0c064c06u,0x0c064c08u,0x0c064c0au,0x0c064c0cu,0x0c064c0eu,0x0c064c10u,0x0c064c12u,0x0c064c14u,0x0c064c16u,0x0c064c18u,0x0c064c1au,
0x0c064c28u,0x0c064c2au,0x0c064c2cu,0x0c064c2eu,0x0c064c30u,0x0c064c32u,0x0c064c34u,0x0c064c36u,0x0c064c38u,0x0c064c3au,0x0c064c3cu,0x0c064c3eu,0x0c064c40u,0x0c064c42u,0x0c064c44u,0x0c064c46u,
0x0c064c48u,0x0c064c4au,0x0c064c4cu,0x0c064c4eu,0x0c064c50u,0x0c064c52u,0x0c064c54u,0x0c064c56u,0x0c064c58u,0x0c064c5au,0x0c064c5cu,0x0c064c5eu,0x0c064c60u,0x0c064c62u,0x0c064c64u,0x0c064c66u,
0x0c064c68u,0x0c064c6au,0x0c064c6cu,0x0c064c6eu,0x0c064c70u,0x0c064c72u,0x0c064c74u,0x0c064c76u,0x0c064c78u,0x0c064c7au,0x0c064c7cu,0x0c064c7eu,0x0c064c80u,0x0c064c82u,0x0c064c84u,0x0c064c86u,
0x0c064c88u,0x0c064c8au,0x0c064c8cu,0x0c064c8eu,0x0c064c90u,0x0c064c92u,0x0c064c94u,0x0c064c96u,0x0c064c98u,0x0c064c9au,0x0c064c9cu,0x0c064c9eu,0x0c064ca0u,0x0c064ca2u,0x0c064ca4u,0x0c064ca6u,
0x0c064ca8u,0x0c064caau,0x0c064cacu,0x0c064caeu,0x0c064cb0u,0x0c064cb2u,0x0c064cb4u,0x0c064cb6u,0x0c064cb8u,0x0c064cbau,0x0c064cbcu,0x0c064cbeu,0x0c064cc0u,0x0c064cc2u,0x0c064cc4u,0x0c064cc6u,
0x0c064cc8u,0x0c064ccau,0x0c064cccu,0x0c064cceu,0x0c064cd0u,0x0c064cd2u,0x0c064cd4u,0x0c064cd6u,0x0c064cd8u,0x0c064cdau,0x0c064cdcu,0x0c064cdeu,0x0c064ce0u,0x0c064ce2u,0x0c064ce4u,0x0c064ce6u,
0x0c064ce8u,0x0c064ceau,0x0c064cecu,0x0c064ceeu,0x0c064cf0u,0x0c064cf2u,0x0c064cf4u,0x0c064cf6u,0x0c064cf8u,0x0c064cfau,0x0c064cfcu,0x0c064cfeu,0x0c064d00u,0x0c064d02u,0x0c064d04u,0x0c064d06u,
0x0c064d08u,0x0c064d0au,0x0c064d0cu,0x0c064d0eu,0x0c064d10u,0x0c064d12u,0x0c064d14u,0x0c064d16u,0x0c064d18u,0x0c064d1au,0x0c064d1cu,0x0c064d1eu,0x0c064d20u,0x0c064d22u,0x0c064d24u,0x0c064d26u,
0x0c064d28u,0x0c064d2au,0x0c064d2cu,0x0c064d2eu,0x0c064d30u,0x0c064d32u,0x0c064d34u,0x0c064d36u,0x0c064d38u,0x0c064d3au,0x0c064d3cu,0x0c064d3eu,0x0c064d40u,0x0c064d42u,0x0c064d44u,0x0c064d46u,
0x0c064d48u,0x0c064d4au,0x0c064d4cu,0x0c064d4eu,0x0c064d50u,0x0c064d52u,0x0c064d54u,0x0c064d56u,0x0c064d58u,0x0c064d5au,0x0c064d5cu,0x0c064d5eu,0x0c064d60u,0x0c064d62u,0x0c064d64u,0x0c064d66u,
0x0c064d68u,0x0c064d6au,0x0c064d6cu,0x0c064d6eu,0x0c064d70u,0x0c064d72u,0x0c064d74u,0x0c064d76u,0x0c064da0u,0x0c064da2u,0x0c064da4u,0x0c064da6u,0x0c064da8u,0x0c064daau,0x0c064dacu,0x0c064daeu,
0x0c064db0u,0x0c064db2u,0x0c064db4u,0x0c064db6u,0x0c064db8u,0x0c064dbau,0x0c064dbcu,0x0c064dbeu,0x0c064dc0u,0x0c064dc2u,0x0c064dc4u,0x0c064dc6u,0x0c064dc8u,0x0c064dcau,0x0c064dccu,0x0c064dceu,
0x0c064dd0u,0x0c064dd2u,0x0c064dd4u,0x0c064dd6u,0x0c064dd8u,0x0c064ddau,0x0c064ddcu,0x0c064ddeu,0x0c064de0u,0x0c064de2u,0x0c064de4u,0x0c064de6u,0x0c064de8u,0x0c064deau,0x0c064decu,0x0c064deeu,
0x0c064df0u,0x0c064df2u,0x0c064df4u,0x0c064df6u,0x0c064df8u,0x0c064dfau,0x0c064dfcu,0x0c064dfeu,0x0c064e00u,0x0c064e02u,0x0c064e04u,0x0c064e06u,0x0c064e08u,0x0c064e0au,0x0c064e0cu,0x0c064e0eu,
0x0c064e10u,0x0c064e12u,0x0c064e14u,0x0c064e16u,0x0c064e18u,0x0c064e1au,0x0c064e1cu,0x0c064e1eu,0x0c064e20u,0x0c064e22u,0x0c064e24u,0x0c064e26u,0x0c064e28u,0x0c064e2au,0x0c064e2cu,0x0c064e2eu,
0x0c064e30u,0x0c064e32u,0x0c064e34u,0x0c064e36u,0x0c064e38u,0x0c064e3au,0x0c064e3cu,0x0c064e3eu,0x0c064e40u,0x0c064e42u,0x0c064e44u,0x0c064e46u,0x0c064e48u,0x0c064e4au,0x0c064e4cu,0x0c064e4eu,
0x0c064e50u,0x0c064e52u,0x0c064e54u,0x0c064e56u,0x0c064e58u,0x0c064e5au,0x0c064e5cu,0x0c064e5eu,0x0c064e60u,0x0c064e62u,0x0c064e64u,0x0c064e66u,0x0c064e68u,0x0c064e6au,0x0c064e6cu,0x0c064e6eu,
0x0c064e70u,0x0c064e72u,0x0c064e74u,0x0c064e76u,0x0c064e78u,0x0c064e7au,0x0c064e7cu,0x0c064e7eu,0x0c064e80u,0x0c064e82u,0x0c064e84u,0x0c064e86u,0x0c064e88u,0x0c064e8au,0x0c064e8cu,0x0c064e8eu,
0x0c064e90u,0x0c064e92u,0x0c064e94u,0x0c064e96u,0x0c064e98u,0x0c064e9au,0x0c064e9cu,0x0c064e9eu,0x0c064ea0u,0x0c064ea2u,0x0c064ea4u,0x0c064ea6u,0x0c064ea8u,0x0c064eaau,0x0c064eacu,0x0c064eaeu,
0x0c064eb0u,0x0c064eb2u,0x0c064eb4u,0x0c064eb6u,0x0c064eb8u,0x0c064ebau,0x0c064ebcu,0x0c064ebeu,0x0c064ec0u,0x0c064ec2u,0x0c064ec4u,0x0c064ec6u,0x0c064ec8u,0x0c064ecau,0x0c064eccu,0x0c064eceu,
0x0c064ed0u,0x0c064ed2u,0x0c064ed4u,0x0c064ed6u,0x0c064ed8u,0x0c064edau,0x0c064edcu,0x0c064edeu,0x0c064ee0u,0x0c064ee2u,0x0c064ee4u,0x0c064ee6u,0x0c064ee8u,0x0c064eeau,0x0c064eecu,0x0c064eeeu,
0x0c064ef0u,0x0c064ef2u,0x0c064ef4u,0x0c064ef6u,0x0c064ef8u,0x0c064efau,0x0c064efcu,0x0c064efeu,0x0c064f00u,0x0c064f02u,0x0c064f04u,0x0c064f06u,0x0c064f08u,0x0c064f0au,0x0c064f0cu,0x0c064f0eu,
0x0c064f10u,0x0c064f12u,0x0c064f14u,0x0c064f16u,0x0c064f18u,0x0c064f1au,0x0c064f1cu,0x0c064f1eu,0x0c064f20u,0x0c064f22u,0x0c064f24u,0x0c064f26u,0x0c064f28u,0x0c064f2au,0x0c064f2cu,0x0c064f2eu,
0x0c064f30u,0x0c064f32u,0x0c064f34u,0x0c064f36u,0x0c064f38u,0x0c064f3au,0x0c064f3cu,0x0c064f3eu,0x0c064f40u,0x0c064f42u,0x0c064f44u,0x0c064f46u,0x0c064f48u,0x0c064f4au,0x0c064f4cu,0x0c064f4eu,
0x0c064f50u,0x0c064f52u,0x0c064f54u,0x0c064f56u,0x0c064f58u,0x0c064f5au,0x0c064f5cu,0x0c064f5eu,0x0c064f60u,0x0c064f62u,0x0c064f64u,0x0c064f66u,0x0c064f68u,0x0c064f6au,0x0c064f6cu,0x0c064f6eu,
0x0c064f70u,0x0c064f72u,0x0c064f74u,0x0c064f76u,0x0c064f78u,0x0c064f7au,0x0c064f7cu,0x0c064f7eu,0x0c064f80u,0x0c064f82u,0x0c064f84u,0x0c064f86u,0x0c064f88u,0x0c064f8au,0x0c064f8cu,0x0c064f8eu,
0x0c064f90u,0x0c064f92u,0x0c064f94u,0x0c064f96u,0x0c064f98u,0x0c064f9au,0x0c064f9cu,0x0c064f9eu,0x0c064fa0u,0x0c064fa2u,0x0c064fa4u,0x0c064fa6u,0x0c064fa8u,0x0c064faau,0x0c064facu,0x0c064faeu,
0x0c064fb0u,0x0c064fb2u,0x0c064fb4u,0x0c064fb6u,0x0c064fb8u,0x0c064fbau,0x0c064fbcu,0x0c064fbeu,0x0c064fc0u,0x0c064fc2u,0x0c064fc4u,0x0c064fc6u,0x0c064fc8u,0x0c064fcau,0x0c064fccu,0x0c064fceu,
0x0c064fd0u,0x0c064fd2u,0x0c064fd4u,0x0c064fd6u,0x0c064fd8u,0x0c064fdau,0x0c064fdcu,0x0c064fdeu,0x0c064fe0u,0x0c064fe2u,0x0c064fe4u,0x0c064fe6u,0x0c064fe8u,0x0c064feau,0x0c064fecu,0x0c064feeu,
0x0c064ff0u,0x0c064ff2u,0x0c064ff4u,0x0c064ff6u,0x0c064ff8u,0x0c064ffau,0x0c064ffcu,0x0c064ffeu,0x0c065000u,0x0c065002u,0x0c065004u,0x0c065006u,0x0c065008u,0x0c06500au,0x0c06500cu,0x0c06500eu,
0x0c065010u,0x0c065012u,0x0c065014u,0x0c065016u,0x0c065018u,0x0c06501au,0x0c06501cu,0x0c06501eu,0x0c065020u,0x0c065022u,0x0c065024u,0x0c065026u,0x0c065028u,0x0c06502au,0x0c06502cu,0x0c06502eu,
0x0c065030u,0x0c065032u,0x0c065034u,0x0c065036u,0x0c065038u,0x0c06503au,0x0c06503cu,0x0c06503eu,0x0c065040u,0x0c065042u,0x0c065044u,0x0c065046u,0x0c065048u,0x0c06504au,0x0c06504cu,0x0c06504eu,
0x0c065050u,0x0c065052u,0x0c065054u,0x0c065056u,0x0c065058u,0x0c06505au,0x0c065088u,0x0c06508au,0x0c06508cu,0x0c06508eu,0x0c065090u,0x0c065092u,0x0c065094u,0x0c065096u,0x0c065098u,0x0c06509au,
0x0c06509cu,0x0c06509eu,0x0c0650a0u,0x0c0650a2u,0x0c0650a4u,0x0c0650a6u,0x0c0650a8u,0x0c0650aau,0x0c0650acu,0x0c0650aeu,0x0c0650b0u,0x0c0650b2u,0x0c0650b4u,0x0c0650b6u,0x0c0650b8u,0x0c0650bau,
0x0c0650bcu,0x0c0650beu,0x0c0650c0u,0x0c0650c2u,0x0c0650c4u,0x0c0650c6u,0x0c0650c8u,0x0c0650cau,0x0c0650ccu,0x0c0650ceu,0x0c0650d0u,0x0c0650d2u,0x0c0650d4u,0x0c0650d6u,0x0c0650d8u,0x0c0650dau,
0x0c0650dcu,0x0c0650deu,0x0c0650e0u,0x0c0650e2u,0x0c0650e4u,0x0c0650e6u,0x0c0650e8u,0x0c0650eau,0x0c0650ecu,0x0c0650eeu,0x0c0650f0u,0x0c0650f2u,0x0c0650f4u,0x0c0650f6u,0x0c0650f8u,0x0c0650fau,
0x0c0650fcu,0x0c0650feu,0x0c065100u,0x0c065102u,0x0c065104u,0x0c065106u,0x0c065108u,0x0c06510au,0x0c06510cu,0x0c06510eu,0x0c065110u,0x0c065112u,0x0c065114u,0x0c065116u,0x0c065118u,0x0c06511au,
0x0c06511cu,0x0c06511eu,0x0c065120u,0x0c065122u,0x0c065124u,0x0c065126u,0x0c065128u,0x0c06512au,0x0c06512cu,0x0c06512eu,0x0c065130u,0x0c065132u,0x0c065134u,0x0c065136u,0x0c065138u,0x0c06513au,
0x0c06513cu,0x0c06513eu,0x0c065140u,0x0c065142u,0x0c065144u,0x0c065146u,0x0c065148u,0x0c06514au,0x0c06514cu,0x0c06514eu,0x0c065150u,0x0c065152u,0x0c065154u,0x0c065156u,0x0c065158u,0x0c06515au,
0x0c06515cu,0x0c06515eu,0x0c065160u,0x0c065162u,0x0c065164u,0x0c065166u,0x0c065168u,0x0c06516au,0x0c06516cu,0x0c06516eu,0x0c065170u,0x0c065172u,0x0c065174u,0x0c065176u,0x0c065178u,0x0c06517au,
0x0c06517cu,0x0c06517eu,0x0c065180u,0x0c065182u,0x0c065184u,0x0c065186u,0x0c065188u,0x0c06518au,0x0c06518cu,0x0c06518eu,0x0c065190u,0x0c065192u,0x0c065194u,0x0c065196u,0x0c065198u,0x0c06519au,
0x0c06519cu,0x0c06519eu,0x0c0651a0u,0x0c0651a2u,0x0c0651a4u,0x0c0651a6u,0x0c0651a8u,0x0c0651aau,0x0c0651acu,0x0c0651aeu,0x0c0651b0u,0x0c0651b2u,0x0c0651b4u,0x0c0651b6u,0x0c0651b8u,0x0c0651bau,
0x0c0651bcu,0x0c0651beu,0x0c0651c0u,0x0c0651c2u,0x0c0651c4u,0x0c0651c6u,0x0c0651c8u,0x0c0651cau,0x0c0651ccu,0x0c0651ceu,0x0c0651d0u,0x0c0651d2u,0x0c0651d4u,0x0c0651d6u,0x0c0651d8u,0x0c0651dau,
0x0c0651dcu,0x0c0651deu,0x0c0651e0u,0x0c0651e2u,0x0c0651e4u,0x0c0651e6u,0x0c0651e8u,0x0c0651eau,0x0c0651ecu,0x0c0651eeu,0x0c0651f0u,0x0c0651f2u,0x0c0651f4u,0x0c0651f6u,0x0c0651f8u,0x0c0651fau,
0x0c0651fcu,0x0c0651feu,0x0c065200u,0x0c065202u,0x0c065204u,0x0c065206u,0x0c065208u,0x0c06520au,0x0c06520cu,0x0c06520eu,0x0c065210u,0x0c065212u,0x0c065214u,0x0c065216u,0x0c065218u,0x0c06521au,
0x0c06521cu,0x0c06521eu,0x0c065220u,0x0c065222u,0x0c065224u,0x0c065226u,0x0c065228u,0x0c06522au,0x0c06522cu,0x0c06522eu,0x0c065230u,0x0c065232u,0x0c065234u,0x0c065236u,0x0c065238u,0x0c06523au,
0x0c06523cu,0x0c06523eu,0x0c065240u,0x0c065242u,0x0c065244u,0x0c065246u,0x0c065248u,0x0c06524au,0x0c06524cu,0x0c06524eu,0x0c065250u,0x0c065252u,0x0c065254u,0x0c065256u,0x0c065258u,0x0c06525au,
0x0c06525cu,0x0c06525eu,0x0c065260u,0x0c065262u,0x0c065264u,0x0c065266u,0x0c065268u,0x0c06526au,0x0c06526cu,0x0c06526eu,0x0c065270u,0x0c065272u,0x0c065274u,0x0c065276u,0x0c065278u,0x0c06527au,
0x0c06527cu,0x0c06527eu,0x0c065280u,0x0c065282u,0x0c065284u,0x0c065286u,0x0c065288u,0x0c06528au,0x0c06528cu,0x0c06528eu,0x0c065290u,0x0c065292u,0x0c065294u,0x0c065296u,0x0c065298u,0x0c06529au,
0x0c06529cu,0x0c06529eu,0x0c0652a0u,0x0c0652a2u,0x0c0652a4u,0x0c0652a6u,0x0c0652a8u,0x0c0652aau,0x0c0652acu,0x0c0652aeu,0x0c0652b0u,0x0c0652b2u,0x0c0652b4u,0x0c0652b6u,0x0c0652b8u,0x0c0652bau,
0x0c0652bcu,0x0c0652beu,0x0c0652c0u,0x0c0652c2u,0x0c0652c4u,0x0c0652c6u,0x0c0652c8u,0x0c0652cau,0x0c0652ccu,0x0c0652ceu,0x0c0652d0u,0x0c0652d2u,0x0c0652d4u,0x0c0652d6u,0x0c0652d8u,0x0c0652dau,
0x0c0652dcu,0x0c0652deu,0x0c0652e0u,0x0c0652e2u,0x0c0652e4u,0x0c0652e6u,0x0c0652e8u,0x0c0652eau,0x0c0652ecu,0x0c0652eeu,0x0c0652f0u,0x0c0652f2u,0x0c0652f4u,0x0c0652f6u,0x0c0652f8u,0x0c0652fau,
0x0c0652fcu,0x0c0652feu,0x0c065300u,0x0c065302u,0x0c065304u,0x0c065306u,0x0c065308u,0x0c06530au,0x0c06530cu,0x0c06530eu,0x0c065310u,0x0c065312u,0x0c065314u,0x0c065316u,0x0c065318u,0x0c06531au,
0x0c06531cu,0x0c06531eu,0x0c065320u,0x0c065322u,0x0c065324u,0x0c065326u,0x0c065328u,0x0c06532au,0x0c06532cu,0x0c06532eu,0x0c06535cu,0x0c06535eu,0x0c065360u,0x0c065362u,0x0c065364u,0x0c065366u,
0x0c065368u,0x0c06536au,0x0c06536cu,0x0c06536eu,0x0c065370u,0x0c065372u,0x0c065374u,0x0c065376u,0x0c065378u,0x0c06537au,0x0c06537cu,0x0c06537eu,0x0c065380u,0x0c065382u,0x0c065384u,0x0c065386u,
0x0c065388u,0x0c06538au,0x0c06538cu,0x0c06538eu,0x0c065390u,0x0c065392u,0x0c065394u,0x0c065396u,0x0c065398u,0x0c06539au,0x0c06539cu,0x0c06539eu,0x0c0653a0u,0x0c0653a2u,0x0c0653a4u,0x0c0653a6u,
0x0c0653a8u,0x0c0653aau,0x0c0653acu,0x0c0653aeu,0x0c0653b0u,0x0c0653b2u,0x0c0653b4u,0x0c0653b6u,0x0c0653b8u,0x0c0653bau,0x0c0653bcu,0x0c0653beu,0x0c0653c0u,0x0c0653c2u,0x0c0653c4u,0x0c0653c6u,
0x0c0653c8u,0x0c0653cau,0x0c0653ccu,0x0c0653ceu,0x0c0653d0u,0x0c0653d2u,0x0c0653d4u,0x0c0653d6u,0x0c0653d8u,0x0c0653dau,0x0c0653dcu,0x0c0653deu,0x0c0653e0u,0x0c0653e2u,0x0c0653e4u,0x0c0653e6u,
0x0c0653e8u,0x0c0653eau,0x0c0653ecu,0x0c0653eeu,0x0c0653f0u,0x0c0653f2u,0x0c0653f4u,0x0c0653f6u,0x0c0653f8u,0x0c0653fau,0x0c0653fcu,0x0c0653feu,0x0c065400u,0x0c065402u,0x0c065404u,0x0c065406u,
0x0c065408u,0x0c06540au,0x0c06540cu,0x0c06540eu,0x0c065410u,0x0c065412u,0x0c065414u,0x0c065416u,0x0c065418u,0x0c06541au,0x0c06541cu,0x0c06541eu,0x0c065420u,0x0c065422u,0x0c065424u,0x0c065426u,
0x0c065428u,0x0c06542au,0x0c06542cu,0x0c06542eu,0x0c065430u,0x0c065432u,0x0c065434u,0x0c065436u,0x0c065438u,0x0c06543au,0x0c06543cu,0x0c06543eu,0x0c065440u,0x0c065442u,0x0c065444u,0x0c065446u,
0x0c065448u,0x0c06544au,0x0c06544cu,0x0c06544eu,0x0c065450u,0x0c065452u,0x0c065454u,0x0c065456u,0x0c065458u,0x0c06545au,0x0c06545cu,0x0c06545eu,0x0c065460u,0x0c065462u,0x0c065464u,0x0c065466u,
0x0c065468u,0x0c06546au,0x0c06546cu,0x0c06546eu,0x0c065470u,0x0c065472u,0x0c065474u,0x0c065476u,0x0c065478u,0x0c06547au,0x0c06547cu,0x0c06547eu,0x0c065480u,0x0c065482u,0x0c065484u,0x0c065486u,
0x0c065488u,0x0c06548au,0x0c06548cu,0x0c06548eu,0x0c065490u,0x0c065492u,0x0c065494u,0x0c065496u,0x0c065498u,0x0c06549au,0x0c06549cu,0x0c06549eu,0x0c0654a0u,0x0c0654a2u,0x0c0654a4u,0x0c0654a6u,
0x0c0654a8u,0x0c0654aau,0x0c0654acu,0x0c0654aeu,0x0c0654b0u,0x0c0654b2u,0x0c0654b4u,0x0c0654b6u,0x0c0654b8u,0x0c0654bau,0x0c0654bcu,0x0c0654beu,0x0c0654c0u,0x0c0654c2u,0x0c0654c4u,0x0c0654c6u,
0x0c0654c8u,0x0c0654cau,0x0c0654ccu,0x0c0654ceu,0x0c0654d0u,0x0c0654d2u,0x0c0654d4u,0x0c0654d6u,0x0c0654d8u,0x0c0654dau,0x0c0654dcu,0x0c0654deu,0x0c0654e0u,0x0c0654e2u,0x0c0654e4u,0x0c0654e6u,
0x0c0654e8u,0x0c0654eau,0x0c0654ecu,0x0c0654eeu,0x0c0654f0u,0x0c0654f2u,0x0c0654f4u,0x0c0654f6u,0x0c0654f8u,0x0c0654fau,0x0c0654fcu,0x0c0654feu,0x0c065500u,0x0c065502u,0x0c065504u,0x0c065506u,
0x0c065508u,0x0c06550au,0x0c06550cu,0x0c06550eu,0x0c065510u,0x0c065512u,0x0c065514u,0x0c065516u,0x0c065518u,0x0c06551au,0x0c06551cu,0x0c06551eu,0x0c065520u,0x0c065522u,0x0c065524u,0x0c065526u,
0x0c065528u,0x0c06552au,0x0c06552cu,0x0c06552eu,0x0c065530u,0x0c065532u,0x0c065534u,0x0c065536u,0x0c065538u,0x0c06553au,0x0c06553cu,0x0c06553eu,0x0c065540u,0x0c065542u,0x0c065544u,0x0c065546u,
0x0c065548u,0x0c06554au,0x0c06554cu,0x0c06554eu,0x0c065550u,0x0c065552u,0x0c065554u,0x0c065556u,0x0c065558u,0x0c06555au,0x0c06555cu,0x0c06555eu,0x0c065560u,0x0c065562u,0x0c065564u,0x0c065566u,
0x0c065568u,0x0c06556au,0x0c06556cu,0x0c06556eu,0x0c065570u,0x0c065572u,0x0c065574u,0x0c065576u,0x0c065578u,0x0c06557au,0x0c06557cu,0x0c06557eu,0x0c065580u,0x0c065582u,0x0c065584u,0x0c065586u,
0x0c065588u,0x0c06558au,0x0c06558cu,0x0c06558eu,0x0c065590u,0x0c065592u,0x0c065594u,0x0c065596u,0x0c065598u,0x0c06559au,0x0c06559cu,0x0c06559eu,0x0c0655a0u,0x0c0655a2u,0x0c0655a4u,0x0c0655e0u,
0x0c0655e2u,0x0c0655e4u,0x0c0655e6u,0x0c0655e8u,0x0c0655eau,0x0c0655ecu,0x0c0655eeu,0x0c0655f0u,0x0c0655f2u,0x0c0655f4u,0x0c0655f6u,0x0c0655f8u,0x0c0655fau,0x0c0655fcu,0x0c0655feu,0x0c065600u,
0x0c065602u,0x0c065604u,0x0c065606u,0x0c065608u,0x0c06560au,0x0c06560cu,0x0c06560eu,0x0c065610u,0x0c065612u,0x0c065614u,0x0c065616u,0x0c065618u,0x0c06561au,0x0c06561cu,0x0c06561eu,0x0c065620u,
0x0c065622u,0x0c065624u,0x0c065626u,0x0c065628u,0x0c06562au,0x0c06562cu,0x0c06562eu,0x0c065630u,0x0c065632u,0x0c065634u,0x0c065636u,0x0c065638u,0x0c06563au,0x0c06563cu,0x0c06563eu,0x0c065640u,
0x0c065642u,0x0c065644u,0x0c065646u,0x0c065648u,0x0c06564au,0x0c06564cu,0x0c06564eu,0x0c065650u,0x0c065652u,0x0c065654u,0x0c065656u,0x0c065658u,0x0c06565au,0x0c06565cu,0x0c06565eu,0x0c065660u,
0x0c065662u,0x0c065664u,0x0c065666u,0x0c065668u,0x0c06566au,0x0c06566cu,0x0c06566eu,0x0c065670u,0x0c065672u,0x0c065674u,0x0c065676u,0x0c065678u,0x0c06567au,0x0c06567cu,0x0c06567eu,0x0c065680u,
0x0c065682u,0x0c065684u,0x0c065686u,0x0c065688u,0x0c06568au,0x0c06568cu,0x0c06568eu,0x0c065690u,0x0c065692u,0x0c065694u,0x0c065696u,0x0c065698u,0x0c06569au,0x0c06569cu,0x0c06569eu,0x0c0656a0u,
0x0c0656a2u,0x0c0656a4u,0x0c0656a6u,0x0c0656a8u,0x0c0656aau,0x0c0656acu,0x0c0656aeu,0x0c0656b0u,0x0c0656b2u,0x0c0656b4u,0x0c0656b6u,0x0c0656b8u,0x0c0656bau,0x0c0656bcu,0x0c0656beu,0x0c0656c0u,
0x0c0656c2u,0x0c0656c4u,0x0c0656c6u,0x0c0656c8u,0x0c0656cau,0x0c0656ccu,0x0c0656ceu,0x0c0656d0u,0x0c0656d2u,0x0c0656d4u,0x0c0656d6u,0x0c0656d8u,0x0c0656dau,0x0c0656dcu,0x0c0656deu,0x0c0656e0u,
0x0c0656e2u,0x0c0656e4u,0x0c0656e6u,0x0c0656e8u,0x0c0656eau,0x0c0656ecu,0x0c0656eeu,0x0c0656f0u,0x0c0656f2u,0x0c0656f4u,0x0c0656f6u,0x0c0656f8u,0x0c0656fau,0x0c0656fcu,0x0c0656feu,0x0c065700u,
0x0c065702u,0x0c065704u,0x0c065706u,0x0c065708u,0x0c06570au,0x0c06570cu,0x0c06570eu,0x0c065710u,0x0c065712u,0x0c065714u,0x0c065716u,0x0c065718u,0x0c06571au,0x0c06571cu,0x0c06571eu,0x0c065720u,
0x0c065722u,0x0c065724u,0x0c065726u,0x0c065728u,0x0c06572au,0x0c06572cu,0x0c06572eu,0x0c065730u,0x0c065732u,0x0c065734u,0x0c065736u,0x0c065738u,0x0c06573au,0x0c06573cu,0x0c06573eu,0x0c065740u,
0x0c065742u,0x0c065744u,0x0c065746u,0x0c065748u,0x0c06574au,0x0c06574cu,0x0c06574eu,0x0c065750u,0x0c065752u,0x0c065754u,0x0c065756u,0x0c065758u,0x0c06575au,0x0c06575cu,0x0c06575eu,0x0c065760u,
0x0c065762u,0x0c065764u,0x0c065766u,0x0c065768u,0x0c06576au,0x0c06576cu,0x0c06576eu,0x0c065770u,0x0c065772u,0x0c065774u,0x0c065776u,0x0c065778u,0x0c06577au,0x0c06577cu,0x0c06577eu,0x0c065780u,
0x0c065782u,0x0c065784u,0x0c065786u,0x0c065788u,0x0c06578au,0x0c06578cu,0x0c06578eu,0x0c065790u,0x0c065792u,0x0c065794u,0x0c065796u,0x0c065798u,0x0c06579au,0x0c06579cu,0x0c06579eu,0x0c0657a0u,
0x0c0657a2u,0x0c0657a4u,0x0c0657a6u,0x0c0657a8u,0x0c0657aau,0x0c0657acu,0x0c0657aeu,0x0c0657b0u,0x0c0657b2u,0x0c0657b4u,0x0c0657b6u,0x0c0657b8u,0x0c0657bau,0x0c0657bcu,0x0c0657beu,0x0c0657c0u,
0x0c0657c2u,0x0c0657c4u,0x0c0657c6u,0x0c0657c8u,0x0c0657cau,0x0c0657ccu,0x0c0657ceu,0x0c0657d0u,0x0c0657d2u,0x0c0657d4u,0x0c0657d6u,0x0c0657d8u,0x0c0657dau,0x0c0657dcu,0x0c0657deu,0x0c0657e0u,
0x0c0657e2u,0x0c0657e4u,0x0c0657e6u,0x0c0657e8u,0x0c0657eau,0x0c0657ecu,0x0c0657eeu,0x0c0657f0u,0x0c0657f2u,0x0c0657f4u,0x0c065aa0u,0x0c065aa2u,0x0c065aa4u,0x0c065aa6u,0x0c065aa8u,0x0c065aaau,
0x0c065aacu,0x0c065aaeu,0x0c065ab0u,0x0c065ab2u,0x0c065ab4u,0x0c065ab6u,0x0c065ab8u,0x0c065abau,0x0c065abcu,0x0c065abeu,0x0c065ac0u,0x0c065ac2u,0x0c065ac4u,0x0c065ac6u,0x0c065ac8u,0x0c065acau,
0x0c065accu,0x0c065aceu,0x0c065ad0u,0x0c065ad2u,0x0c065ad4u,0x0c065ad6u,0x0c065ad8u,0x0c065adau,0x0c065adcu,0x0c065adeu,0x0c065ae0u,0x0c065ae2u,0x0c065ae4u,0x0c065ae6u,0x0c065ae8u,0x0c065aeau,
0x0c065aecu,0x0c065aeeu,0x0c065af0u,0x0c065af2u,0x0c065af4u,0x0c065af6u,0x0c065af8u,0x0c065afau,0x0c065afcu,0x0c065afeu,0x0c065b00u,0x0c065b02u,0x0c065b04u,0x0c065b06u,0x0c065b08u,0x0c065b0au,
0x0c065b0cu,0x0c065b0eu,0x0c065b10u,0x0c065b12u,0x0c065b14u,0x0c065b16u,0x0c065b18u,0x0c065b1au,0x0c065b1cu,0x0c065b1eu,0x0c065b20u,0x0c065b22u,0x0c065b24u,0x0c065b26u,0x0c065b28u,0x0c065b2au,
0x0c065b2cu,0x0c065b2eu,0x0c065b30u,0x0c065b32u,0x0c065b34u,0x0c065b36u,0x0c065b38u,0x0c065b3au,0x0c065b3cu,0x0c065b3eu,0x0c065b40u,0x0c065b42u,0x0c065b44u,0x0c065b46u,0x0c065b48u,0x0c065b4au,
0x0c065b4cu,0x0c065b4eu,0x0c065b50u,0x0c065b52u,0x0c065b54u,0x0c065b56u,0x0c065b58u,0x0c065b5au,0x0c065b5cu,0x0c065b5eu,0x0c065b60u,0x0c065b62u,0x0c065b64u,0x0c065b66u,0x0c065b68u,0x0c065b6au,
0x0c065b6cu,0x0c065b6eu,0x0c065b70u,0x0c065b72u,0x0c065b74u,0x0c065b76u,0x0c065b78u,0x0c065b7au,0x0c065b7cu,0x0c065b7eu,0x0c065b80u,0x0c065b82u,0x0c065b84u,0x0c065b86u,0x0c065b88u,0x0c065b8au,
0x0c065b8cu,0x0c065b8eu,0x0c065b90u,0x0c065b92u,0x0c065b94u,0x0c065b96u,0x0c065b98u,0x0c065b9au,0x0c065b9cu,0x0c065b9eu,0x0c065ba0u,0x0c065ba2u,0x0c065ba4u,0x0c065ba6u,0x0c065ba8u,0x0c065baau,
0x0c065bacu,0x0c065baeu,0x0c065bb0u,0x0c065bb2u,0x0c065bb4u,0x0c065bb6u,0x0c065bb8u,0x0c065bbau,0x0c065bbcu,0x0c065bbeu,0x0c065bc0u,0x0c065bc2u,0x0c065bc4u,0x0c065bc6u,0x0c065bc8u,0x0c065bcau,
0x0c065bccu,0x0c065bceu,0x0c065bd0u,0x0c065bd2u,0x0c065bd4u,0x0c065bd6u,0x0c065bd8u,0x0c065bdau,0x0c065bdcu,0x0c065bdeu,0x0c065be0u,0x0c065be2u,0x0c065be4u,0x0c065be6u,0x0c065be8u,0x0c065beau,
0x0c065becu,0x0c065beeu,0x0c065bf0u,0x0c065bf2u,0x0c065bf4u,0x0c065bf6u,0x0c065bf8u,0x0c065bfau,0x0c065bfcu,0x0c065bfeu,0x0c065c00u,0x0c065c02u,0x0c065c04u,0x0c065c06u,0x0c065c08u,0x0c065c0au,
0x0c065c0cu,0x0c065c0eu,0x0c065c10u,0x0c065c12u,0x0c065c4cu,0x0c065c4eu,0x0c065c50u,0x0c065c52u,0x0c065c54u,0x0c065c56u,0x0c065c58u,0x0c065c5au,0x0c065c5cu,0x0c065c5eu,0x0c065c60u,0x0c065c62u,
0x0c065c64u,0x0c065c66u,0x0c065c68u,0x0c065c6au,0x0c065c6cu,0x0c065c6eu,0x0c065c70u,0x0c065c72u,0x0c065c74u,0x0c065c76u,0x0c065c78u,0x0c065c7au,0x0c065c7cu,0x0c065c7eu,0x0c065c80u,0x0c065c82u,
0x0c065c84u,0x0c065c86u,0x0c065c88u,0x0c065c8au,0x0c065c8cu,0x0c065c8eu,0x0c065c90u,0x0c065c92u,0x0c065c94u,0x0c065c96u,0x0c065c98u,0x0c065c9au,0x0c065c9cu,0x0c065c9eu,0x0c065ca0u,0x0c065ca2u,
0x0c065ca4u,0x0c065ca6u,0x0c065ca8u,0x0c065caau,0x0c065cacu,0x0c065caeu,0x0c065cb0u,0x0c065cb2u,0x0c065cb4u,0x0c065cb6u,0x0c065cb8u,0x0c065cbau,0x0c065cbcu,0x0c065cbeu,0x0c065cc0u,0x0c065cc2u,
0x0c065cc4u,0x0c065cc6u,0x0c065cc8u,0x0c065ccau,0x0c065cccu,0x0c065cceu,0x0c065cd0u,0x0c065cd2u,0x0c065cd4u,0x0c065cd6u,0x0c065cd8u,0x0c065cdau,0x0c065cdcu,0x0c065cdeu,0x0c065ce0u,0x0c065ce2u,
0x0c065ce4u,0x0c065ce6u,0x0c065ce8u,0x0c065ceau,0x0c065cecu,0x0c065ceeu,0x0c065cf0u,0x0c065cf2u,0x0c065cf4u,0x0c065cf6u,0x0c065cf8u,0x0c065cfau,0x0c065cfcu,0x0c065cfeu,0x0c065d00u,0x0c065d02u,
0x0c065d04u,0x0c065d06u,0x0c065d08u,0x0c065d0au,0x0c065d0cu,0x0c065d0eu,0x0c065d10u,0x0c065d12u,0x0c065d14u,0x0c065d16u,0x0c065d18u,0x0c065d1au,0x0c065d1cu,0x0c065d1eu,0x0c065d20u,0x0c065d22u,
0x0c065d24u,0x0c065d26u,0x0c065d28u,0x0c065d2au,0x0c065d2cu,0x0c065d2eu,0x0c065d30u,0x0c065d32u,0x0c065d34u,0x0c065d36u,0x0c065d38u,0x0c065d3au,0x0c065d3cu,0x0c065d3eu,0x0c065d40u,0x0c065d42u,
0x0c065d44u,0x0c065d46u,0x0c065d48u,0x0c065d4au,0x0c065d4cu,0x0c065d4eu,0x0c065d50u,0x0c065d52u,0x0c065d54u,0x0c065d56u,0x0c065d58u,0x0c065d5au,0x0c065d5cu,0x0c065d5eu,0x0c065d60u,0x0c065d62u,
0x0c065d64u,0x0c065d66u,0x0c065d68u,0x0c065d6au,0x0c065d6cu,0x0c065d6eu,0x0c065d70u,0x0c065d72u,0x0c065d74u,0x0c065d76u,0x0c065d78u,0x0c065d7au,0x0c065d7cu,0x0c065d7eu,0x0c065d80u,0x0c065d82u,
0x0c065d84u,0x0c065d86u,0x0c065d88u,0x0c065d8au,0x0c065d8cu,0x0c065d8eu,0x0c065d90u,0x0c065d92u,0x0c065d94u,0x0c065d96u,0x0c065d98u,0x0c065d9au,0x0c065d9cu,0x0c065d9eu,0x0c065da0u,0x0c065da2u,
0x0c065da4u,0x0c065da6u,0x0c065da8u,0x0c065daau,0x0c065de4u,0x0c065de6u,0x0c065de8u,0x0c065deau,0x0c065decu,0x0c065deeu,0x0c065df0u,0x0c065df2u,0x0c065df4u,0x0c065df6u,0x0c065df8u,0x0c065dfau,
0x0c065dfcu,0x0c065dfeu,0x0c065e00u,0x0c065e02u,0x0c065e04u,0x0c065e06u,0x0c065e08u,0x0c065e0au,0x0c065e0cu,0x0c065e0eu,0x0c065e10u,0x0c065e12u,0x0c065e14u,0x0c065e16u,0x0c065e18u,0x0c065e1au,
0x0c065e1cu,0x0c065e1eu,0x0c065e20u,0x0c065e22u,0x0c065e24u,0x0c065e26u,0x0c065e28u,0x0c065e2au,0x0c065e2cu,0x0c065e2eu,0x0c065e30u,0x0c065e32u,0x0c065e34u,0x0c065e36u,0x0c065e38u,0x0c065e3au,
0x0c065e3cu,0x0c065e3eu,0x0c065e40u,0x0c065e42u,0x0c065e44u,0x0c065e46u,0x0c065e48u,0x0c065e4au,0x0c065e4cu,0x0c065e4eu,0x0c065e50u,0x0c065e52u,0x0c065e54u,0x0c065e56u,0x0c065e58u,0x0c065e5au,
0x0c065e5cu,0x0c065e5eu,0x0c065e60u,0x0c065e62u,0x0c065e64u,0x0c065e66u,0x0c065e68u,0x0c065e6au,0x0c065e6cu,0x0c065e6eu,0x0c065e70u,0x0c065e72u,0x0c065e74u,0x0c065e76u,0x0c065e78u,0x0c065e7au,
0x0c065e7cu,0x0c065e7eu,0x0c065e80u,0x0c065e82u,0x0c065e84u,0x0c065e86u,0x0c065e88u,0x0c065e8au,0x0c065e8cu,0x0c065e8eu,0x0c065e90u,0x0c065e92u,0x0c065e94u,0x0c065e96u,0x0c065e98u,0x0c065e9au,
0x0c065e9cu,0x0c065e9eu,0x0c065ea0u,0x0c065ea2u,0x0c065ea4u,0x0c065ea6u,0x0c065ea8u,0x0c065eaau,0x0c065eacu,0x0c065eaeu,0x0c065eb0u,0x0c065eb2u,0x0c065eb4u,0x0c065eb6u,0x0c065eb8u,0x0c065ebau,
0x0c065ebcu,0x0c065ebeu,0x0c065ec0u,0x0c065ec2u,0x0c065ec4u,0x0c065ec6u,0x0c065ec8u,0x0c065ecau,0x0c065eccu,0x0c065eceu,0x0c065ed0u,0x0c065ed2u,0x0c065ed4u,0x0c065ed6u,0x0c065ed8u,0x0c065edau,
0x0c065edcu,0x0c065edeu,0x0c065ee0u,0x0c065ee2u,0x0c065ee4u,0x0c065ee6u,0x0c065ee8u,0x0c065eeau,0x0c065eecu,0x0c065eeeu,0x0c065ef0u,0x0c065ef2u,0x0c065ef4u,0x0c065ef6u,0x0c065ef8u,0x0c065efau,
0x0c065efcu,0x0c065efeu,0x0c065f00u,0x0c065f02u,0x0c065f04u,0x0c065f06u,0x0c065f08u,0x0c065f0au,0x0c065f0cu,0x0c065f0eu,0x0c065f10u,0x0c065f12u,0x0c065f14u,0x0c065f16u,0x0c065f18u,0x0c065f1au,
0x0c065f1cu,0x0c065f1eu,0x0c065f20u,0x0c065f22u,0x0c065f24u,0x0c065f26u,0x0c065f28u,0x0c065f2au,0x0c065f2cu,0x0c065f2eu,0x0c065f30u,0x0c065f32u,0x0c065f34u,0x0c065f36u,0x0c065f38u,0x0c065f3au,
0x0c065f3cu,0x0c065f3eu,0x0c065f40u,0x0c065f42u,0x0c065f44u,0x0c065f46u,0x0c065f48u,0x0c065f4au,0x0c065f4cu,0x0c065f4eu,0x0c065f50u,0x0c065f52u,0x0c065f54u,0x0c065f56u,0x0c065f58u,0x0c065f5au,
0x0c065f5cu,0x0c065f5eu,0x0c065f60u,0x0c065f62u,0x0c065f64u,0x0c065f66u,0x0c065f68u,0x0c065f6au,0x0c065f6cu,0x0c065f6eu,0x0c065f70u,0x0c065f72u,0x0c065f74u,0x0c065f76u,0x0c065f78u,0x0c065f7au,
0x0c065f7cu,0x0c065f7eu,0x0c065f80u,0x0c065f82u,0x0c065f84u,0x0c065f86u,0x0c065f88u,0x0c065f8au,0x0c065f8cu,0x0c065f8eu,0x0c065f90u,0x0c065f92u,0x0c065f94u,0x0c065f96u,0x0c065f98u,0x0c065f9au,
0x0c065f9cu,0x0c065f9eu,0x0c065fa0u,0x0c065fa2u,0x0c065fa4u,0x0c065fa6u,0x0c065fa8u,0x0c065faau,0x0c065facu,0x0c065faeu,0x0c065fb0u,0x0c065fb2u,0x0c065fb4u,0x0c065fb6u,0x0c065fb8u,0x0c065fbau,
0x0c065fbcu,0x0c065fbeu,0x0c065fc0u,0x0c065fc2u,0x0c065fc4u,0x0c065fc6u,0x0c065fc8u,0x0c065fcau,0x0c065fccu,0x0c065fceu,0x0c065fd0u,0x0c065fd2u,0x0c065fd4u,0x0c065fd6u,0x0c065fd8u,0x0c065fdau,
0x0c065fdcu,0x0c065fdeu,0x0c065fe0u,0x0c065fe2u,0x0c065fe4u,0x0c065fe6u,0x0c065fe8u,0x0c065feau,0x0c065fecu,0x0c065feeu,0x0c065ff0u,0x0c065ff2u,0x0c065ff4u,0x0c065ff6u,0x0c065ff8u,0x0c065ffau,
0x0c065ffcu,0x0c065ffeu,0x0c066000u,0x0c066002u,0x0c066004u,0x0c066006u,0x0c066008u,0x0c06600au,0x0c06600cu,0x0c06604cu,0x0c06604eu,0x0c066050u,0x0c066052u,0x0c066054u,0x0c066056u,0x0c066058u,
0x0c06605au,0x0c06605cu,0x0c06605eu,0x0c066060u,0x0c066062u,0x0c066064u,0x0c066066u,0x0c066068u,0x0c06606au,0x0c06606cu,0x0c06606eu,0x0c066070u,0x0c066072u,0x0c066074u,0x0c066076u,0x0c066078u,
0x0c06607au,0x0c06607cu,0x0c06607eu,0x0c066080u,0x0c066082u,0x0c066084u,0x0c066086u,0x0c066088u,0x0c06608au,0x0c06608cu,0x0c06608eu,0x0c066090u,0x0c066092u,0x0c066094u,0x0c066096u,0x0c066098u,
0x0c06609au,0x0c06609cu,0x0c06609eu,0x0c0660a0u,0x0c0660a2u,0x0c0660a4u,0x0c0660a6u,0x0c0660a8u,0x0c0660aau,0x0c0660acu,0x0c0660aeu,0x0c0660b0u,0x0c0660b2u,0x0c0660b4u,0x0c0660b6u,0x0c0660b8u,
0x0c0660bau,0x0c0660bcu,0x0c0660beu,0x0c0660c0u,0x0c0660c2u,0x0c0660c4u,0x0c0660c6u,0x0c0660c8u,0x0c0660cau,0x0c0660ccu,0x0c0660ceu,0x0c0660d0u,0x0c0660d2u,0x0c0660d4u,0x0c0660d6u,0x0c0660d8u,
0x0c0660dau,0x0c0660dcu,0x0c0660deu,0x0c0660e0u,0x0c0660e2u,0x0c0660e4u,0x0c0660e6u,0x0c0660e8u,0x0c0660eau,0x0c0660ecu,0x0c0660eeu,0x0c0660f0u,0x0c0660f2u,0x0c0660f4u,0x0c0660f6u,0x0c0660f8u,
0x0c0660fau,0x0c0660fcu,0x0c0660feu,0x0c066100u,0x0c066102u,0x0c066104u,0x0c066106u,0x0c066108u,0x0c06610au,0x0c06610cu,0x0c06610eu,0x0c066110u,0x0c066112u,0x0c066114u,0x0c066116u,0x0c066118u,
0x0c06611au,0x0c06611cu,0x0c06611eu,0x0c066120u,0x0c066122u,0x0c066124u,0x0c066126u,0x0c066128u,0x0c06612au,0x0c06612cu,0x0c06612eu,0x0c066130u,0x0c066132u,0x0c066134u,0x0c066136u,0x0c066138u,
0x0c06613au,0x0c06613cu,0x0c06613eu,0x0c066140u,0x0c066142u,0x0c066144u,0x0c066146u,0x0c066148u,0x0c06614au,0x0c06614cu,0x0c06614eu,0x0c066150u,0x0c066152u,0x0c066154u,0x0c066156u,0x0c066158u,
0x0c06615au,0x0c06615cu,0x0c06615eu,0x0c066160u,0x0c066162u,0x0c066164u,0x0c066166u,0x0c066168u,0x0c06616au,0x0c06616cu,0x0c06616eu,0x0c066170u,0x0c066172u,0x0c066174u,0x0c066176u,0x0c066178u,
0x0c06617au,0x0c06617cu,0x0c06617eu,0x0c066180u,0x0c066182u,0x0c066184u,0x0c066186u,0x0c066188u,0x0c06618au,0x0c06618cu,0x0c06618eu,0x0c066190u,0x0c066192u,0x0c066194u,0x0c066196u,0x0c066198u,
0x0c06619au,0x0c06619cu,0x0c06619eu,0x0c0661a0u,0x0c0661a2u,0x0c0661a4u,0x0c0661a6u,0x0c0661a8u,0x0c0661aau,0x0c0661acu,0x0c0661aeu,0x0c0661b0u,0x0c0661b2u,0x0c0661b4u,0x0c0661b6u,0x0c0661b8u,
0x0c0661bau,0x0c0661bcu,0x0c0661beu,0x0c0661c0u,0x0c0661c2u,0x0c0661c4u,0x0c0661c6u,0x0c0661c8u,0x0c0661cau,0x0c0661ccu,0x0c0661ceu,0x0c0661d0u,0x0c0661d2u,0x0c0661d4u,0x0c0661d6u,0x0c0661d8u,
0x0c0661dau,0x0c0661dcu,0x0c0661deu,0x0c0661e0u,0x0c0661e2u,0x0c0661e4u,0x0c0661e6u,0x0c0661e8u,0x0c0661eau,0x0c0661ecu,0x0c0661eeu,0x0c0661f0u,0x0c0661f2u,0x0c0661f4u,0x0c0661f6u,0x0c0661f8u,
0x0c0661fau,0x0c0661fcu,0x0c0661feu,0x0c066200u,0x0c066202u,0x0c066204u,0x0c066206u,0x0c066208u,0x0c06620au,0x0c06620cu,0x0c06620eu,0x0c066210u,0x0c066212u,0x0c066214u,0x0c066216u,0x0c066218u,
0x0c06621au,0x0c06621cu,0x0c06621eu,0x0c066220u,0x0c066222u,0x0c066224u,0x0c066226u,0x0c066228u,0x0c06622au,0x0c06622cu,0x0c06622eu,0x0c066230u,0x0c066232u,0x0c066234u,0x0c066236u,0x0c066238u,
0x0c06623au,0x0c06623cu,0x0c06623eu,0x0c066240u,0x0c066242u,0x0c066244u,0x0c066246u,0x0c066248u,0x0c06624au,0x0c06624cu,0x0c06624eu,0x0c066250u,0x0c066252u,0x0c066254u,0x0c066256u,0x0c066258u,
0x0c06625au,0x0c06625cu,0x0c06625eu,0x0c066260u,
};
int vf3_tenpp_complex_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
