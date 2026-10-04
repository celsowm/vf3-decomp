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
int vf3_tenpp_leaf_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0387f0u: goto P_0c0387f0;
case 0x0c0387f2u: goto P_0c0387f2;
case 0x0c0387f4u: goto P_0c0387f4;
case 0x0c0387f6u: goto P_0c0387f6;
case 0x0c0387f8u: goto P_0c0387f8;
case 0x0c0387fau: goto P_0c0387fa;
case 0x0c0387fcu: goto P_0c0387fc;
case 0x0c0387feu: goto P_0c0387fe;
case 0x0c038800u: goto P_0c038800;
case 0x0c038802u: goto P_0c038802;
case 0x0c038804u: goto P_0c038804;
case 0x0c038806u: goto P_0c038806;
case 0x0c038810u: goto P_0c038810;
case 0x0c038812u: goto P_0c038812;
case 0x0c038814u: goto P_0c038814;
case 0x0c038816u: goto P_0c038816;
case 0x0c038818u: goto P_0c038818;
case 0x0c03881au: goto P_0c03881a;
case 0x0c03881cu: goto P_0c03881c;
case 0x0c03881eu: goto P_0c03881e;
case 0x0c038820u: goto P_0c038820;
case 0x0c038822u: goto P_0c038822;
case 0x0c038824u: goto P_0c038824;
case 0x0c038826u: goto P_0c038826;
case 0x0c03a1bau: goto P_0c03a1ba;
case 0x0c03a1bcu: goto P_0c03a1bc;
case 0x0c03a1beu: goto P_0c03a1be;
case 0x0c03a1c0u: goto P_0c03a1c0;
case 0x0c03a1c2u: goto P_0c03a1c2;
case 0x0c03a1c4u: goto P_0c03a1c4;
case 0x0c03a1c6u: goto P_0c03a1c6;
case 0x0c03a1c8u: goto P_0c03a1c8;
case 0x0c03a1cau: goto P_0c03a1ca;
case 0x0c03a1ccu: goto P_0c03a1cc;
case 0x0c03a1ceu: goto P_0c03a1ce;
case 0x0c03a1d0u: goto P_0c03a1d0;
case 0x0c03a1d2u: goto P_0c03a1d2;
case 0x0c03a1d4u: goto P_0c03a1d4;
case 0x0c03a1d6u: goto P_0c03a1d6;
case 0x0c03a1d8u: goto P_0c03a1d8;
case 0x0c03a250u: goto P_0c03a250;
case 0x0c03a252u: goto P_0c03a252;
case 0x0c03a254u: goto P_0c03a254;
case 0x0c03a256u: goto P_0c03a256;
case 0x0c03a258u: goto P_0c03a258;
case 0x0c03a25au: goto P_0c03a25a;
case 0x0c03a25cu: goto P_0c03a25c;
case 0x0c03a25eu: goto P_0c03a25e;
case 0x0c03a260u: goto P_0c03a260;
case 0x0c03a262u: goto P_0c03a262;
case 0x0c03a264u: goto P_0c03a264;
case 0x0c03a270u: goto P_0c03a270;
case 0x0c03a272u: goto P_0c03a272;
case 0x0c03a274u: goto P_0c03a274;
case 0x0c03a276u: goto P_0c03a276;
case 0x0c03a278u: goto P_0c03a278;
case 0x0c03a27au: goto P_0c03a27a;
case 0x0c03a27cu: goto P_0c03a27c;
case 0x0c03a27eu: goto P_0c03a27e;
case 0x0c03a280u: goto P_0c03a280;
case 0x0c03a282u: goto P_0c03a282;
case 0x0c03a284u: goto P_0c03a284;
case 0x0c03a286u: goto P_0c03a286;
case 0x0c03a288u: goto P_0c03a288;
case 0x0c03a28au: goto P_0c03a28a;
case 0x0c03a28cu: goto P_0c03a28c;
case 0x0c03a28eu: goto P_0c03a28e;
case 0x0c03a290u: goto P_0c03a290;
case 0x0c03a292u: goto P_0c03a292;
case 0x0c03a294u: goto P_0c03a294;
case 0x0c03a296u: goto P_0c03a296;
case 0x0c03a298u: goto P_0c03a298;
case 0x0c03a29au: goto P_0c03a29a;
case 0x0c03a29cu: goto P_0c03a29c;
case 0x0c03a29eu: goto P_0c03a29e;
case 0x0c03a2a0u: goto P_0c03a2a0;
case 0x0c03a2a2u: goto P_0c03a2a2;
case 0x0c03a2a4u: goto P_0c03a2a4;
case 0x0c03a2a6u: goto P_0c03a2a6;
case 0x0c03a2a8u: goto P_0c03a2a8;
case 0x0c03a2aau: goto P_0c03a2aa;
case 0x0c03a2acu: goto P_0c03a2ac;
case 0x0c03a2aeu: goto P_0c03a2ae;
case 0x0c03a2b0u: goto P_0c03a2b0;
case 0x0c03a2b2u: goto P_0c03a2b2;
case 0x0c03a2b4u: goto P_0c03a2b4;
case 0x0c03a2b6u: goto P_0c03a2b6;
case 0x0c03a2b8u: goto P_0c03a2b8;
case 0x0c03a2bau: goto P_0c03a2ba;
case 0x0c03a2bcu: goto P_0c03a2bc;
case 0x0c03a2beu: goto P_0c03a2be;
case 0x0c03a390u: goto P_0c03a390;
case 0x0c03a392u: goto P_0c03a392;
case 0x0c03a394u: goto P_0c03a394;
case 0x0c03a396u: goto P_0c03a396;
case 0x0c03a398u: goto P_0c03a398;
case 0x0c03a39au: goto P_0c03a39a;
case 0x0c03a39cu: goto P_0c03a39c;
case 0x0c03a3a0u: goto P_0c03a3a0;
case 0x0c03a3a2u: goto P_0c03a3a2;
case 0x0c03a3a4u: goto P_0c03a3a4;
case 0x0c03a3a6u: goto P_0c03a3a6;
case 0x0c03a3a8u: goto P_0c03a3a8;
case 0x0c03a3aau: goto P_0c03a3aa;
case 0x0c03a3acu: goto P_0c03a3ac;
case 0x0c03a3aeu: goto P_0c03a3ae;
case 0x0c03a3b0u: goto P_0c03a3b0;
case 0x0c03a3b2u: goto P_0c03a3b2;
case 0x0c03a3b4u: goto P_0c03a3b4;
case 0x0c03a3b6u: goto P_0c03a3b6;
case 0x0c03a3b8u: goto P_0c03a3b8;
case 0x0c03a3bau: goto P_0c03a3ba;
case 0x0c03a3bcu: goto P_0c03a3bc;
case 0x0c03a3beu: goto P_0c03a3be;
case 0x0c03a3c0u: goto P_0c03a3c0;
case 0x0c03a3c2u: goto P_0c03a3c2;
case 0x0c03a3c4u: goto P_0c03a3c4;
case 0x0c03a3c6u: goto P_0c03a3c6;
case 0x0c03a3c8u: goto P_0c03a3c8;
case 0x0c03a3cau: goto P_0c03a3ca;
case 0x0c03a3ccu: goto P_0c03a3cc;
case 0x0c03a3ceu: goto P_0c03a3ce;
case 0x0c03a3d0u: goto P_0c03a3d0;
case 0x0c03a3d2u: goto P_0c03a3d2;
case 0x0c03a400u: goto P_0c03a400;
case 0x0c03a402u: goto P_0c03a402;
case 0x0c03a404u: goto P_0c03a404;
case 0x0c03a406u: goto P_0c03a406;
case 0x0c03a408u: goto P_0c03a408;
case 0x0c03a40au: goto P_0c03a40a;
case 0x0c03a40cu: goto P_0c03a40c;
case 0x0c03a40eu: goto P_0c03a40e;
case 0x0c03a410u: goto P_0c03a410;
case 0x0c03a412u: goto P_0c03a412;
case 0x0c03a420u: goto P_0c03a420;
case 0x0c03a422u: goto P_0c03a422;
case 0x0c03a424u: goto P_0c03a424;
case 0x0c03a426u: goto P_0c03a426;
case 0x0c03a428u: goto P_0c03a428;
case 0x0c03a42au: goto P_0c03a42a;
case 0x0c03a42cu: goto P_0c03a42c;
case 0x0c03a42eu: goto P_0c03a42e;
case 0x0c03a430u: goto P_0c03a430;
case 0x0c03a432u: goto P_0c03a432;
case 0x0c03a434u: goto P_0c03a434;
case 0x0c03a436u: goto P_0c03a436;
case 0x0c03a5c0u: goto P_0c03a5c0;
case 0x0c03a5c2u: goto P_0c03a5c2;
case 0x0c03a5c4u: goto P_0c03a5c4;
case 0x0c03a5c6u: goto P_0c03a5c6;
case 0x0c03a5c8u: goto P_0c03a5c8;
case 0x0c03a5cau: goto P_0c03a5ca;
case 0x0c03a5ccu: goto P_0c03a5cc;
case 0x0c03a5ceu: goto P_0c03a5ce;
case 0x0c03a5d0u: goto P_0c03a5d0;
case 0x0c03a5d2u: goto P_0c03a5d2;
case 0x0c03a5d4u: goto P_0c03a5d4;
case 0x0c03a772u: goto P_0c03a772;
case 0x0c03a774u: goto P_0c03a774;
case 0x0c03a776u: goto P_0c03a776;
case 0x0c03a778u: goto P_0c03a778;
case 0x0c03a77au: goto P_0c03a77a;
case 0x0c03a77cu: goto P_0c03a77c;
case 0x0c03a77eu: goto P_0c03a77e;
case 0x0c03a780u: goto P_0c03a780;
case 0x0c03a782u: goto P_0c03a782;
case 0x0c03a784u: goto P_0c03a784;
case 0x0c03a786u: goto P_0c03a786;
case 0x0c03a788u: goto P_0c03a788;
case 0x0c03a78au: goto P_0c03a78a;
case 0x0c03a78cu: goto P_0c03a78c;
case 0x0c03a78eu: goto P_0c03a78e;
case 0x0c03a790u: goto P_0c03a790;
case 0x0c03a792u: goto P_0c03a792;
case 0x0c03a794u: goto P_0c03a794;
case 0x0c03a796u: goto P_0c03a796;
case 0x0c03a7a0u: goto P_0c03a7a0;
case 0x0c03a7a2u: goto P_0c03a7a2;
case 0x0c03a7a4u: goto P_0c03a7a4;
case 0x0c03a7a6u: goto P_0c03a7a6;
case 0x0c03a7a8u: goto P_0c03a7a8;
case 0x0c03a7aau: goto P_0c03a7aa;
case 0x0c03a7acu: goto P_0c03a7ac;
case 0x0c03a7aeu: goto P_0c03a7ae;
case 0x0c03a7b0u: goto P_0c03a7b0;
case 0x0c03a7b2u: goto P_0c03a7b2;
case 0x0c03a7b4u: goto P_0c03a7b4;
case 0x0c03ac16u: goto P_0c03ac16;
case 0x0c03ac18u: goto P_0c03ac18;
case 0x0c03ac1au: goto P_0c03ac1a;
case 0x0c03ac1cu: goto P_0c03ac1c;
case 0x0c03ac1eu: goto P_0c03ac1e;
case 0x0c03ac20u: goto P_0c03ac20;
case 0x0c03ac22u: goto P_0c03ac22;
case 0x0c03ac24u: goto P_0c03ac24;
case 0x0c03ac26u: goto P_0c03ac26;
case 0x0c03ac28u: goto P_0c03ac28;
case 0x0c03ac2au: goto P_0c03ac2a;
case 0x0c03ac2cu: goto P_0c03ac2c;
case 0x0c03ac2eu: goto P_0c03ac2e;
case 0x0c03ac30u: goto P_0c03ac30;
case 0x0c03b410u: goto P_0c03b410;
case 0x0c03b412u: goto P_0c03b412;
case 0x0c03b414u: goto P_0c03b414;
case 0x0c03b416u: goto P_0c03b416;
case 0x0c03b418u: goto P_0c03b418;
case 0x0c03b41au: goto P_0c03b41a;
case 0x0c03b41cu: goto P_0c03b41c;
case 0x0c03b41eu: goto P_0c03b41e;
case 0x0c03b420u: goto P_0c03b420;
case 0x0c03b422u: goto P_0c03b422;
case 0x0c03b424u: goto P_0c03b424;
case 0x0c03b426u: goto P_0c03b426;
case 0x0c03b874u: goto P_0c03b874;
case 0x0c03b876u: goto P_0c03b876;
case 0x0c03b878u: goto P_0c03b878;
case 0x0c03b87au: goto P_0c03b87a;
case 0x0c03b87cu: goto P_0c03b87c;
case 0x0c03b87eu: goto P_0c03b87e;
case 0x0c03b880u: goto P_0c03b880;
case 0x0c03b882u: goto P_0c03b882;
case 0x0c03b884u: goto P_0c03b884;
case 0x0c03b886u: goto P_0c03b886;
case 0x0c03b888u: goto P_0c03b888;
case 0x0c03b88au: goto P_0c03b88a;
case 0x0c03b88cu: goto P_0c03b88c;
case 0x0c03b88eu: goto P_0c03b88e;
case 0x0c03b890u: goto P_0c03b890;
case 0x0c03b892u: goto P_0c03b892;
case 0x0c03b894u: goto P_0c03b894;
case 0x0c03b896u: goto P_0c03b896;
case 0x0c03b898u: goto P_0c03b898;
case 0x0c03b89au: goto P_0c03b89a;
case 0x0c03b89cu: goto P_0c03b89c;
case 0x0c03b89eu: goto P_0c03b89e;
case 0x0c03b8a0u: goto P_0c03b8a0;
case 0x0c03b8a2u: goto P_0c03b8a2;
case 0x0c03b8a4u: goto P_0c03b8a4;
case 0x0c03b8a6u: goto P_0c03b8a6;
case 0x0c03b8a8u: goto P_0c03b8a8;
case 0x0c03b8aau: goto P_0c03b8aa;
case 0x0c03b8acu: goto P_0c03b8ac;
case 0x0c03b8aeu: goto P_0c03b8ae;
case 0x0c03b8b0u: goto P_0c03b8b0;
case 0x0c03b8b2u: goto P_0c03b8b2;
case 0x0c03b8b4u: goto P_0c03b8b4;
case 0x0c03b8b6u: goto P_0c03b8b6;
case 0x0c03b8b8u: goto P_0c03b8b8;
case 0x0c03c580u: goto P_0c03c580;
case 0x0c03c582u: goto P_0c03c582;
case 0x0c03c584u: goto P_0c03c584;
case 0x0c03c586u: goto P_0c03c586;
case 0x0c03c588u: goto P_0c03c588;
case 0x0c03c58au: goto P_0c03c58a;
case 0x0c03c58cu: goto P_0c03c58c;
case 0x0c03c58eu: goto P_0c03c58e;
case 0x0c03c590u: goto P_0c03c590;
case 0x0c03c592u: goto P_0c03c592;
case 0x0c03c594u: goto P_0c03c594;
case 0x0c03c596u: goto P_0c03c596;
case 0x0c03c598u: goto P_0c03c598;
case 0x0c03dcc4u: goto P_0c03dcc4;
case 0x0c03dcc6u: goto P_0c03dcc6;
case 0x0c03dcc8u: goto P_0c03dcc8;
case 0x0c03dccau: goto P_0c03dcca;
case 0x0c03dcccu: goto P_0c03dccc;
case 0x0c03dcceu: goto P_0c03dcce;
case 0x0c03dcd0u: goto P_0c03dcd0;
case 0x0c03dcd2u: goto P_0c03dcd2;
case 0x0c03dcd4u: goto P_0c03dcd4;
case 0x0c03dcd6u: goto P_0c03dcd6;
case 0x0c03dcd8u: goto P_0c03dcd8;
case 0x0c03dcdau: goto P_0c03dcda;
case 0x0c03dcdcu: goto P_0c03dcdc;
case 0x0c03dcdeu: goto P_0c03dcde;
case 0x0c03dce0u: goto P_0c03dce0;
case 0x0c03dce2u: goto P_0c03dce2;
case 0x0c03dce4u: goto P_0c03dce4;
case 0x0c03dce6u: goto P_0c03dce6;
case 0x0c03dce8u: goto P_0c03dce8;
case 0x0c03dceau: goto P_0c03dcea;
case 0x0c03dcecu: goto P_0c03dcec;
case 0x0c03dceeu: goto P_0c03dcee;
case 0x0c03dcf0u: goto P_0c03dcf0;
case 0x0c03e760u: goto P_0c03e760;
case 0x0c03e762u: goto P_0c03e762;
case 0x0c03e764u: goto P_0c03e764;
case 0x0c03e766u: goto P_0c03e766;
case 0x0c03e768u: goto P_0c03e768;
case 0x0c03e76au: goto P_0c03e76a;
case 0x0c03e76cu: goto P_0c03e76c;
case 0x0c03e76eu: goto P_0c03e76e;
case 0x0c03e770u: goto P_0c03e770;
case 0x0c03e772u: goto P_0c03e772;
case 0x0c03e774u: goto P_0c03e774;
case 0x0c03e776u: goto P_0c03e776;
case 0x0c03e778u: goto P_0c03e778;
case 0x0c03e77au: goto P_0c03e77a;
case 0x0c03e77cu: goto P_0c03e77c;
case 0x0c03e77eu: goto P_0c03e77e;
case 0x0c03e780u: goto P_0c03e780;
case 0x0c03e782u: goto P_0c03e782;
case 0x0c03e784u: goto P_0c03e784;
case 0x0c03e786u: goto P_0c03e786;
case 0x0c03e790u: goto P_0c03e790;
case 0x0c03e792u: goto P_0c03e792;
case 0x0c03e794u: goto P_0c03e794;
case 0x0c03e796u: goto P_0c03e796;
case 0x0c03e798u: goto P_0c03e798;
case 0x0c03e79au: goto P_0c03e79a;
case 0x0c03e79cu: goto P_0c03e79c;
case 0x0c03e79eu: goto P_0c03e79e;
case 0x0c03e7a0u: goto P_0c03e7a0;
case 0x0c03e7a2u: goto P_0c03e7a2;
case 0x0c03e7a4u: goto P_0c03e7a4;
case 0x0c03e7a6u: goto P_0c03e7a6;
case 0x0c03e7a8u: goto P_0c03e7a8;
case 0x0c03e7aau: goto P_0c03e7aa;
case 0x0c03e7acu: goto P_0c03e7ac;
case 0x0c03e7aeu: goto P_0c03e7ae;
case 0x0c03e7b0u: goto P_0c03e7b0;
case 0x0c043064u: goto P_0c043064;
case 0x0c043066u: goto P_0c043066;
case 0x0c043068u: goto P_0c043068;
case 0x0c04306au: goto P_0c04306a;
case 0x0c04306cu: goto P_0c04306c;
case 0x0c04306eu: goto P_0c04306e;
case 0x0c043070u: goto P_0c043070;
case 0x0c043072u: goto P_0c043072;
case 0x0c043074u: goto P_0c043074;
case 0x0c043076u: goto P_0c043076;
case 0x0c043078u: goto P_0c043078;
case 0x0c04307au: goto P_0c04307a;
case 0x0c04307cu: goto P_0c04307c;
case 0x0c04307eu: goto P_0c04307e;
case 0x0c043080u: goto P_0c043080;
case 0x0c043082u: goto P_0c043082;
case 0x0c043084u: goto P_0c043084;
case 0x0c04326cu: goto P_0c04326c;
case 0x0c04326eu: goto P_0c04326e;
case 0x0c043270u: goto P_0c043270;
case 0x0c043272u: goto P_0c043272;
case 0x0c043274u: goto P_0c043274;
case 0x0c043276u: goto P_0c043276;
case 0x0c043278u: goto P_0c043278;
case 0x0c04327au: goto P_0c04327a;
case 0x0c04327cu: goto P_0c04327c;
case 0x0c04327eu: goto P_0c04327e;
case 0x0c043280u: goto P_0c043280;
case 0x0c043282u: goto P_0c043282;
case 0x0c043284u: goto P_0c043284;
case 0x0c0433c6u: goto P_0c0433c6;
case 0x0c0433c8u: goto P_0c0433c8;
case 0x0c0433cau: goto P_0c0433ca;
case 0x0c0433ccu: goto P_0c0433cc;
case 0x0c0433ceu: goto P_0c0433ce;
case 0x0c0433d0u: goto P_0c0433d0;
case 0x0c0433d2u: goto P_0c0433d2;
case 0x0c0433d4u: goto P_0c0433d4;
case 0x0c0433d6u: goto P_0c0433d6;
case 0x0c0433d8u: goto P_0c0433d8;
case 0x0c0433dau: goto P_0c0433da;
case 0x0c0433dcu: goto P_0c0433dc;
case 0x0c0433deu: goto P_0c0433de;
case 0x0c04341eu: goto P_0c04341e;
case 0x0c043420u: goto P_0c043420;
case 0x0c043422u: goto P_0c043422;
case 0x0c043424u: goto P_0c043424;
case 0x0c043426u: goto P_0c043426;
case 0x0c043428u: goto P_0c043428;
case 0x0c04342au: goto P_0c04342a;
case 0x0c04342cu: goto P_0c04342c;
case 0x0c04342eu: goto P_0c04342e;
case 0x0c043430u: goto P_0c043430;
case 0x0c043432u: goto P_0c043432;
case 0x0c043434u: goto P_0c043434;
case 0x0c043436u: goto P_0c043436;
case 0x0c043438u: goto P_0c043438;
case 0x0c04343au: goto P_0c04343a;
case 0x0c043440u: goto P_0c043440;
case 0x0c043442u: goto P_0c043442;
case 0x0c043444u: goto P_0c043444;
case 0x0c043446u: goto P_0c043446;
case 0x0c043448u: goto P_0c043448;
case 0x0c04344au: goto P_0c04344a;
case 0x0c04344cu: goto P_0c04344c;
case 0x0c04344eu: goto P_0c04344e;
case 0x0c043450u: goto P_0c043450;
case 0x0c043452u: goto P_0c043452;
case 0x0c043454u: goto P_0c043454;
case 0x0c043456u: goto P_0c043456;
case 0x0c043458u: goto P_0c043458;
case 0x0c04345au: goto P_0c04345a;
case 0x0c04345cu: goto P_0c04345c;
case 0x0c043472u: goto P_0c043472;
case 0x0c043474u: goto P_0c043474;
case 0x0c043476u: goto P_0c043476;
case 0x0c043478u: goto P_0c043478;
case 0x0c04347au: goto P_0c04347a;
case 0x0c04347cu: goto P_0c04347c;
case 0x0c04347eu: goto P_0c04347e;
case 0x0c043480u: goto P_0c043480;
case 0x0c043482u: goto P_0c043482;
case 0x0c043484u: goto P_0c043484;
case 0x0c043486u: goto P_0c043486;
case 0x0c043488u: goto P_0c043488;
case 0x0c04348au: goto P_0c04348a;
case 0x0c04348eu: goto P_0c04348e;
case 0x0c043490u: goto P_0c043490;
case 0x0c043492u: goto P_0c043492;
case 0x0c043494u: goto P_0c043494;
case 0x0c043496u: goto P_0c043496;
case 0x0c043498u: goto P_0c043498;
case 0x0c04349au: goto P_0c04349a;
case 0x0c04349cu: goto P_0c04349c;
case 0x0c04349eu: goto P_0c04349e;
case 0x0c0434a0u: goto P_0c0434a0;
case 0x0c0434a2u: goto P_0c0434a2;
case 0x0c0434a4u: goto P_0c0434a4;
case 0x0c0434a6u: goto P_0c0434a6;
case 0x0c0434aau: goto P_0c0434aa;
case 0x0c0434acu: goto P_0c0434ac;
case 0x0c0434aeu: goto P_0c0434ae;
case 0x0c0434b0u: goto P_0c0434b0;
case 0x0c0434b2u: goto P_0c0434b2;
case 0x0c0434b4u: goto P_0c0434b4;
case 0x0c0434b6u: goto P_0c0434b6;
case 0x0c0434b8u: goto P_0c0434b8;
case 0x0c0434bau: goto P_0c0434ba;
case 0x0c0434bcu: goto P_0c0434bc;
case 0x0c0434beu: goto P_0c0434be;
case 0x0c0434c0u: goto P_0c0434c0;
case 0x0c0434c2u: goto P_0c0434c2;
case 0x0c0434c4u: goto P_0c0434c4;
case 0x0c0434c6u: goto P_0c0434c6;
case 0x0c04596cu: goto P_0c04596c;
case 0x0c04596eu: goto P_0c04596e;
case 0x0c045970u: goto P_0c045970;
case 0x0c045972u: goto P_0c045972;
case 0x0c045974u: goto P_0c045974;
case 0x0c045976u: goto P_0c045976;
case 0x0c045978u: goto P_0c045978;
case 0x0c04597au: goto P_0c04597a;
case 0x0c04597cu: goto P_0c04597c;
case 0x0c04597eu: goto P_0c04597e;
case 0x0c045980u: goto P_0c045980;
case 0x0c045982u: goto P_0c045982;
case 0x0c045984u: goto P_0c045984;
case 0x0c045986u: goto P_0c045986;
case 0x0c045988u: goto P_0c045988;
case 0x0c04598au: goto P_0c04598a;
case 0x0c04598cu: goto P_0c04598c;
case 0x0c04598eu: goto P_0c04598e;
case 0x0c045990u: goto P_0c045990;
case 0x0c045992u: goto P_0c045992;
case 0x0c045994u: goto P_0c045994;
case 0x0c045996u: goto P_0c045996;
case 0x0c045998u: goto P_0c045998;
case 0x0c04599au: goto P_0c04599a;
case 0x0c04599cu: goto P_0c04599c;
case 0x0c04599eu: goto P_0c04599e;
case 0x0c0459a0u: goto P_0c0459a0;
case 0x0c0459a2u: goto P_0c0459a2;
case 0x0c0459a4u: goto P_0c0459a4;
case 0x0c0459a6u: goto P_0c0459a6;
case 0x0c0459a8u: goto P_0c0459a8;
case 0x0c0459aau: goto P_0c0459aa;
case 0x0c0459acu: goto P_0c0459ac;
case 0x0c0459aeu: goto P_0c0459ae;
case 0x0c0459b0u: goto P_0c0459b0;
case 0x0c0459b2u: goto P_0c0459b2;
case 0x0c0459b4u: goto P_0c0459b4;
case 0x0c0459b6u: goto P_0c0459b6;
case 0x0c0459b8u: goto P_0c0459b8;
case 0x0c046000u: goto P_0c046000;
case 0x0c046002u: goto P_0c046002;
case 0x0c046004u: goto P_0c046004;
case 0x0c046006u: goto P_0c046006;
case 0x0c046008u: goto P_0c046008;
case 0x0c04600au: goto P_0c04600a;
case 0x0c04600cu: goto P_0c04600c;
case 0x0c04600eu: goto P_0c04600e;
case 0x0c046010u: goto P_0c046010;
case 0x0c046012u: goto P_0c046012;
case 0x0c046014u: goto P_0c046014;
case 0x0c046016u: goto P_0c046016;
case 0x0c046034u: goto P_0c046034;
case 0x0c046036u: goto P_0c046036;
case 0x0c046038u: goto P_0c046038;
case 0x0c04603au: goto P_0c04603a;
case 0x0c04603cu: goto P_0c04603c;
case 0x0c04603eu: goto P_0c04603e;
case 0x0c046040u: goto P_0c046040;
case 0x0c046042u: goto P_0c046042;
case 0x0c046044u: goto P_0c046044;
case 0x0c046046u: goto P_0c046046;
case 0x0c046048u: goto P_0c046048;
case 0x0c04604au: goto P_0c04604a;
case 0x0c04604cu: goto P_0c04604c;
case 0x0c04604eu: goto P_0c04604e;
case 0x0c046050u: goto P_0c046050;
case 0x0c046052u: goto P_0c046052;
case 0x0c046054u: goto P_0c046054;
case 0x0c046056u: goto P_0c046056;
case 0x0c046058u: goto P_0c046058;
case 0x0c04605au: goto P_0c04605a;
case 0x0c04605cu: goto P_0c04605c;
case 0x0c0462a2u: goto P_0c0462a2;
case 0x0c0462a4u: goto P_0c0462a4;
case 0x0c0463b2u: goto P_0c0463b2;
case 0x0c0463b4u: goto P_0c0463b4;
case 0x0c0463b6u: goto P_0c0463b6;
case 0x0c0463b8u: goto P_0c0463b8;
case 0x0c0463bau: goto P_0c0463ba;
case 0x0c0463bcu: goto P_0c0463bc;
case 0x0c0463beu: goto P_0c0463be;
case 0x0c0463c0u: goto P_0c0463c0;
case 0x0c0463c2u: goto P_0c0463c2;
case 0x0c0463c4u: goto P_0c0463c4;
case 0x0c0463c6u: goto P_0c0463c6;
case 0x0c0463c8u: goto P_0c0463c8;
case 0x0c0463cau: goto P_0c0463ca;
case 0x0c0463ccu: goto P_0c0463cc;
case 0x0c0463ceu: goto P_0c0463ce;
case 0x0c0463d0u: goto P_0c0463d0;
case 0x0c0463d2u: goto P_0c0463d2;
case 0x0c0463d4u: goto P_0c0463d4;
case 0x0c0463d6u: goto P_0c0463d6;
case 0x0c0463d8u: goto P_0c0463d8;
case 0x0c0463dau: goto P_0c0463da;
case 0x0c0463dcu: goto P_0c0463dc;
case 0x0c0463deu: goto P_0c0463de;
case 0x0c0463e0u: goto P_0c0463e0;
case 0x0c0463e2u: goto P_0c0463e2;
case 0x0c0463e4u: goto P_0c0463e4;
case 0x0c0463e6u: goto P_0c0463e6;
case 0x0c0463e8u: goto P_0c0463e8;
case 0x0c0476f2u: goto P_0c0476f2;
case 0x0c0476f4u: goto P_0c0476f4;
case 0x0c0476f6u: goto P_0c0476f6;
case 0x0c0476f8u: goto P_0c0476f8;
case 0x0c0476fau: goto P_0c0476fa;
case 0x0c0476fcu: goto P_0c0476fc;
case 0x0c0476feu: goto P_0c0476fe;
case 0x0c047700u: goto P_0c047700;
case 0x0c047702u: goto P_0c047702;
case 0x0c047704u: goto P_0c047704;
case 0x0c047706u: goto P_0c047706;
case 0x0c04771eu: goto P_0c04771e;
case 0x0c047720u: goto P_0c047720;
case 0x0c047722u: goto P_0c047722;
case 0x0c047724u: goto P_0c047724;
case 0x0c047726u: goto P_0c047726;
case 0x0c047728u: goto P_0c047728;
case 0x0c04772au: goto P_0c04772a;
case 0x0c04772cu: goto P_0c04772c;
case 0x0c04772eu: goto P_0c04772e;
case 0x0c047730u: goto P_0c047730;
case 0x0c047732u: goto P_0c047732;
case 0x0c047734u: goto P_0c047734;
case 0x0c047736u: goto P_0c047736;
case 0x0c047738u: goto P_0c047738;
case 0x0c04773au: goto P_0c04773a;
case 0x0c04773cu: goto P_0c04773c;
case 0x0c04773eu: goto P_0c04773e;
case 0x0c047740u: goto P_0c047740;
case 0x0c047742u: goto P_0c047742;
case 0x0c047744u: goto P_0c047744;
case 0x0c049306u: goto P_0c049306;
case 0x0c049308u: goto P_0c049308;
case 0x0c04930au: goto P_0c04930a;
case 0x0c04930cu: goto P_0c04930c;
case 0x0c04930eu: goto P_0c04930e;
case 0x0c049310u: goto P_0c049310;
case 0x0c049312u: goto P_0c049312;
case 0x0c049314u: goto P_0c049314;
case 0x0c049316u: goto P_0c049316;
case 0x0c049318u: goto P_0c049318;
case 0x0c04931au: goto P_0c04931a;
case 0x0c04931cu: goto P_0c04931c;
case 0x0c04931eu: goto P_0c04931e;
case 0x0c049320u: goto P_0c049320;
case 0x0c049322u: goto P_0c049322;
case 0x0c049324u: goto P_0c049324;
case 0x0c049326u: goto P_0c049326;
case 0x0c049328u: goto P_0c049328;
case 0x0c04932au: goto P_0c04932a;
case 0x0c04932cu: goto P_0c04932c;
case 0x0c04932eu: goto P_0c04932e;
case 0x0c049330u: goto P_0c049330;
case 0x0c049332u: goto P_0c049332;
case 0x0c049334u: goto P_0c049334;
case 0x0c049336u: goto P_0c049336;
case 0x0c049338u: goto P_0c049338;
case 0x0c04933au: goto P_0c04933a;
case 0x0c04933cu: goto P_0c04933c;
case 0x0c04933eu: goto P_0c04933e;
case 0x0c049340u: goto P_0c049340;
case 0x0c049342u: goto P_0c049342;
case 0x0c049344u: goto P_0c049344;
case 0x0c049346u: goto P_0c049346;
case 0x0c049348u: goto P_0c049348;
case 0x0c04934au: goto P_0c04934a;
case 0x0c04934cu: goto P_0c04934c;
case 0x0c04934eu: goto P_0c04934e;
case 0x0c049350u: goto P_0c049350;
case 0x0c049352u: goto P_0c049352;
case 0x0c049354u: goto P_0c049354;
case 0x0c049356u: goto P_0c049356;
case 0x0c049358u: goto P_0c049358;
case 0x0c04935au: goto P_0c04935a;
case 0x0c04935cu: goto P_0c04935c;
case 0x0c04935eu: goto P_0c04935e;
case 0x0c049360u: goto P_0c049360;
case 0x0c049362u: goto P_0c049362;
case 0x0c049364u: goto P_0c049364;
case 0x0c049366u: goto P_0c049366;
case 0x0c049368u: goto P_0c049368;
case 0x0c04936au: goto P_0c04936a;
case 0x0c04936cu: goto P_0c04936c;
case 0x0c04936eu: goto P_0c04936e;
case 0x0c049370u: goto P_0c049370;
case 0x0c049372u: goto P_0c049372;
case 0x0c049374u: goto P_0c049374;
case 0x0c049376u: goto P_0c049376;
case 0x0c049378u: goto P_0c049378;
case 0x0c04937au: goto P_0c04937a;
case 0x0c04937cu: goto P_0c04937c;
case 0x0c04937eu: goto P_0c04937e;
case 0x0c049380u: goto P_0c049380;
case 0x0c049382u: goto P_0c049382;
case 0x0c049384u: goto P_0c049384;
case 0x0c049386u: goto P_0c049386;
case 0x0c049388u: goto P_0c049388;
case 0x0c04938au: goto P_0c04938a;
case 0x0c04938cu: goto P_0c04938c;
case 0x0c04938eu: goto P_0c04938e;
case 0x0c049390u: goto P_0c049390;
case 0x0c049392u: goto P_0c049392;
case 0x0c049394u: goto P_0c049394;
case 0x0c049396u: goto P_0c049396;
case 0x0c049398u: goto P_0c049398;
case 0x0c04939au: goto P_0c04939a;
case 0x0c04939cu: goto P_0c04939c;
case 0x0c04939eu: goto P_0c04939e;
case 0x0c0493a0u: goto P_0c0493a0;
case 0x0c0493a2u: goto P_0c0493a2;
case 0x0c0493a4u: goto P_0c0493a4;
case 0x0c0493a6u: goto P_0c0493a6;
case 0x0c0493a8u: goto P_0c0493a8;
case 0x0c0493aau: goto P_0c0493aa;
case 0x0c0493acu: goto P_0c0493ac;
case 0x0c0493aeu: goto P_0c0493ae;
case 0x0c0493b0u: goto P_0c0493b0;
case 0x0c0493b2u: goto P_0c0493b2;
case 0x0c0493b4u: goto P_0c0493b4;
case 0x0c0493b6u: goto P_0c0493b6;
case 0x0c0493b8u: goto P_0c0493b8;
case 0x0c0493bau: goto P_0c0493ba;
case 0x0c0493bcu: goto P_0c0493bc;
case 0x0c0493beu: goto P_0c0493be;
case 0x0c0493c0u: goto P_0c0493c0;
case 0x0c0493c2u: goto P_0c0493c2;
case 0x0c0493c4u: goto P_0c0493c4;
case 0x0c0493c6u: goto P_0c0493c6;
case 0x0c0493c8u: goto P_0c0493c8;
case 0x0c0493cau: goto P_0c0493ca;
case 0x0c0493ccu: goto P_0c0493cc;
case 0x0c0493ceu: goto P_0c0493ce;
case 0x0c0493d0u: goto P_0c0493d0;
case 0x0c0493d2u: goto P_0c0493d2;
case 0x0c0493d4u: goto P_0c0493d4;
case 0x0c0493d6u: goto P_0c0493d6;
case 0x0c0493d8u: goto P_0c0493d8;
case 0x0c0493dau: goto P_0c0493da;
case 0x0c0493dcu: goto P_0c0493dc;
case 0x0c0493deu: goto P_0c0493de;
case 0x0c0493e0u: goto P_0c0493e0;
case 0x0c0493e2u: goto P_0c0493e2;
case 0x0c0493e4u: goto P_0c0493e4;
case 0x0c0493e6u: goto P_0c0493e6;
case 0x0c0493e8u: goto P_0c0493e8;
case 0x0c0493eau: goto P_0c0493ea;
case 0x0c0493ecu: goto P_0c0493ec;
case 0x0c0493eeu: goto P_0c0493ee;
case 0x0c0493f0u: goto P_0c0493f0;
case 0x0c0493f2u: goto P_0c0493f2;
case 0x0c0493f4u: goto P_0c0493f4;
case 0x0c0493f6u: goto P_0c0493f6;
case 0x0c0493f8u: goto P_0c0493f8;
case 0x0c049416u: goto P_0c049416;
case 0x0c049418u: goto P_0c049418;
case 0x0c04941au: goto P_0c04941a;
case 0x0c04941cu: goto P_0c04941c;
case 0x0c04941eu: goto P_0c04941e;
case 0x0c049420u: goto P_0c049420;
case 0x0c049422u: goto P_0c049422;
case 0x0c049424u: goto P_0c049424;
case 0x0c049426u: goto P_0c049426;
case 0x0c049428u: goto P_0c049428;
case 0x0c04942au: goto P_0c04942a;
case 0x0c04942cu: goto P_0c04942c;
case 0x0c04c968u: goto P_0c04c968;
case 0x0c04c96au: goto P_0c04c96a;
case 0x0c04c96cu: goto P_0c04c96c;
case 0x0c04c96eu: goto P_0c04c96e;
case 0x0c04c970u: goto P_0c04c970;
case 0x0c04c972u: goto P_0c04c972;
case 0x0c04c974u: goto P_0c04c974;
case 0x0c04c976u: goto P_0c04c976;
case 0x0c04c978u: goto P_0c04c978;
case 0x0c04c97au: goto P_0c04c97a;
case 0x0c04c97cu: goto P_0c04c97c;
case 0x0c04c97eu: goto P_0c04c97e;
case 0x0c04c980u: goto P_0c04c980;
case 0x0c04c982u: goto P_0c04c982;
case 0x0c04c984u: goto P_0c04c984;
case 0x0c04c986u: goto P_0c04c986;
case 0x0c04c988u: goto P_0c04c988;
case 0x0c04c98au: goto P_0c04c98a;
case 0x0c04c98cu: goto P_0c04c98c;
case 0x0c04c98eu: goto P_0c04c98e;
case 0x0c04c990u: goto P_0c04c990;
case 0x0c04c992u: goto P_0c04c992;
case 0x0c04c994u: goto P_0c04c994;
case 0x0c04c996u: goto P_0c04c996;
case 0x0c04c998u: goto P_0c04c998;
case 0x0c04c99au: goto P_0c04c99a;
case 0x0c04c99cu: goto P_0c04c99c;
case 0x0c04c99eu: goto P_0c04c99e;
case 0x0c04c9a0u: goto P_0c04c9a0;
case 0x0c04cb3eu: goto P_0c04cb3e;
case 0x0c04cb40u: goto P_0c04cb40;
case 0x0c04cb42u: goto P_0c04cb42;
case 0x0c04cb44u: goto P_0c04cb44;
case 0x0c04cb46u: goto P_0c04cb46;
case 0x0c04cb48u: goto P_0c04cb48;
case 0x0c04cb4au: goto P_0c04cb4a;
case 0x0c04cb4cu: goto P_0c04cb4c;
case 0x0c04cb4eu: goto P_0c04cb4e;
case 0x0c04cb50u: goto P_0c04cb50;
case 0x0c04cb52u: goto P_0c04cb52;
case 0x0c04cb54u: goto P_0c04cb54;
case 0x0c04cb56u: goto P_0c04cb56;
case 0x0c04cb58u: goto P_0c04cb58;
case 0x0c04cb5au: goto P_0c04cb5a;
case 0x0c04cb5cu: goto P_0c04cb5c;
case 0x0c050128u: goto P_0c050128;
case 0x0c05012au: goto P_0c05012a;
case 0x0c05012cu: goto P_0c05012c;
case 0x0c05012eu: goto P_0c05012e;
case 0x0c050130u: goto P_0c050130;
case 0x0c050132u: goto P_0c050132;
case 0x0c050134u: goto P_0c050134;
case 0x0c050136u: goto P_0c050136;
case 0x0c050138u: goto P_0c050138;
case 0x0c05013au: goto P_0c05013a;
case 0x0c05013cu: goto P_0c05013c;
case 0x0c05013eu: goto P_0c05013e;
case 0x0c050140u: goto P_0c050140;
case 0x0c050142u: goto P_0c050142;
case 0x0c050144u: goto P_0c050144;
case 0x0c050146u: goto P_0c050146;
case 0x0c050148u: goto P_0c050148;
case 0x0c05014au: goto P_0c05014a;
case 0x0c050174u: goto P_0c050174;
case 0x0c050176u: goto P_0c050176;
case 0x0c050178u: goto P_0c050178;
case 0x0c05017au: goto P_0c05017a;
case 0x0c05017cu: goto P_0c05017c;
case 0x0c05017eu: goto P_0c05017e;
case 0x0c050180u: goto P_0c050180;
case 0x0c050182u: goto P_0c050182;
case 0x0c050184u: goto P_0c050184;
case 0x0c050186u: goto P_0c050186;
case 0x0c050188u: goto P_0c050188;
case 0x0c05018au: goto P_0c05018a;
case 0x0c05018cu: goto P_0c05018c;
case 0x0c05018eu: goto P_0c05018e;
case 0x0c050190u: goto P_0c050190;
case 0x0c050192u: goto P_0c050192;
case 0x0c050194u: goto P_0c050194;
case 0x0c050196u: goto P_0c050196;
case 0x0c050198u: goto P_0c050198;
case 0x0c05019au: goto P_0c05019a;
case 0x0c05019cu: goto P_0c05019c;
case 0x0c05019eu: goto P_0c05019e;
case 0x0c0501a0u: goto P_0c0501a0;
case 0x0c0501a2u: goto P_0c0501a2;
case 0x0c0501a4u: goto P_0c0501a4;
case 0x0c0501a6u: goto P_0c0501a6;
case 0x0c0501a8u: goto P_0c0501a8;
case 0x0c0501aau: goto P_0c0501aa;
case 0x0c0501acu: goto P_0c0501ac;
case 0x0c0501aeu: goto P_0c0501ae;
case 0x0c0501b0u: goto P_0c0501b0;
case 0x0c0501b2u: goto P_0c0501b2;
case 0x0c0501b4u: goto P_0c0501b4;
case 0x0c0501b6u: goto P_0c0501b6;
case 0x0c0501b8u: goto P_0c0501b8;
case 0x0c0501bau: goto P_0c0501ba;
case 0x0c0501bcu: goto P_0c0501bc;
case 0x0c0501beu: goto P_0c0501be;
case 0x0c0501c0u: goto P_0c0501c0;
case 0x0c0501c2u: goto P_0c0501c2;
case 0x0c0501c4u: goto P_0c0501c4;
case 0x0c0501c6u: goto P_0c0501c6;
case 0x0c0501c8u: goto P_0c0501c8;
case 0x0c0501cau: goto P_0c0501ca;
case 0x0c0501ccu: goto P_0c0501cc;
case 0x0c0501ceu: goto P_0c0501ce;
case 0x0c0501d0u: goto P_0c0501d0;
case 0x0c0501d2u: goto P_0c0501d2;
case 0x0c0501d4u: goto P_0c0501d4;
case 0x0c0501d6u: goto P_0c0501d6;
case 0x0c0501d8u: goto P_0c0501d8;
case 0x0c0501dau: goto P_0c0501da;
case 0x0c0501dcu: goto P_0c0501dc;
case 0x0c0501deu: goto P_0c0501de;
case 0x0c0501e0u: goto P_0c0501e0;
case 0x0c0501e2u: goto P_0c0501e2;
case 0x0c0501e4u: goto P_0c0501e4;
case 0x0c0501e6u: goto P_0c0501e6;
case 0x0c0501e8u: goto P_0c0501e8;
case 0x0c0501f4u: goto P_0c0501f4;
case 0x0c0501f6u: goto P_0c0501f6;
case 0x0c0501f8u: goto P_0c0501f8;
case 0x0c0501fau: goto P_0c0501fa;
case 0x0c0501fcu: goto P_0c0501fc;
case 0x0c0501feu: goto P_0c0501fe;
case 0x0c050200u: goto P_0c050200;
case 0x0c050202u: goto P_0c050202;
case 0x0c050204u: goto P_0c050204;
case 0x0c050206u: goto P_0c050206;
case 0x0c050208u: goto P_0c050208;
case 0x0c05020au: goto P_0c05020a;
case 0x0c05020cu: goto P_0c05020c;
case 0x0c05020eu: goto P_0c05020e;
case 0x0c050210u: goto P_0c050210;
case 0x0c050212u: goto P_0c050212;
case 0x0c050214u: goto P_0c050214;
case 0x0c050216u: goto P_0c050216;
case 0x0c050218u: goto P_0c050218;
case 0x0c05021au: goto P_0c05021a;
case 0x0c05021cu: goto P_0c05021c;
case 0x0c05021eu: goto P_0c05021e;
case 0x0c050220u: goto P_0c050220;
case 0x0c050222u: goto P_0c050222;
case 0x0c050224u: goto P_0c050224;
case 0x0c050226u: goto P_0c050226;
case 0x0c050228u: goto P_0c050228;
case 0x0c05022au: goto P_0c05022a;
case 0x0c05022cu: goto P_0c05022c;
case 0x0c05022eu: goto P_0c05022e;
case 0x0c050230u: goto P_0c050230;
case 0x0c050232u: goto P_0c050232;
case 0x0c050234u: goto P_0c050234;
case 0x0c050236u: goto P_0c050236;
case 0x0c050238u: goto P_0c050238;
case 0x0c05023au: goto P_0c05023a;
case 0x0c05023cu: goto P_0c05023c;
case 0x0c05023eu: goto P_0c05023e;
case 0x0c050240u: goto P_0c050240;
case 0x0c050242u: goto P_0c050242;
case 0x0c050244u: goto P_0c050244;
case 0x0c050246u: goto P_0c050246;
case 0x0c050248u: goto P_0c050248;
case 0x0c05024au: goto P_0c05024a;
case 0x0c05024cu: goto P_0c05024c;
case 0x0c05024eu: goto P_0c05024e;
case 0x0c051b7eu: goto P_0c051b7e;
case 0x0c051b80u: goto P_0c051b80;
case 0x0c051b82u: goto P_0c051b82;
case 0x0c051b84u: goto P_0c051b84;
case 0x0c051b86u: goto P_0c051b86;
case 0x0c051b88u: goto P_0c051b88;
case 0x0c051b8au: goto P_0c051b8a;
case 0x0c051b8cu: goto P_0c051b8c;
case 0x0c051b8eu: goto P_0c051b8e;
case 0x0c051b90u: goto P_0c051b90;
case 0x0c051b92u: goto P_0c051b92;
case 0x0c051b94u: goto P_0c051b94;
case 0x0c051b96u: goto P_0c051b96;
case 0x0c0521b6u: goto P_0c0521b6;
case 0x0c0521b8u: goto P_0c0521b8;
case 0x0c0521bau: goto P_0c0521ba;
case 0x0c0521bcu: goto P_0c0521bc;
case 0x0c0521beu: goto P_0c0521be;
case 0x0c0521c0u: goto P_0c0521c0;
case 0x0c0521c2u: goto P_0c0521c2;
case 0x0c0521c4u: goto P_0c0521c4;
case 0x0c0521c6u: goto P_0c0521c6;
case 0x0c0521c8u: goto P_0c0521c8;
case 0x0c0521cau: goto P_0c0521ca;
case 0x0c0521ccu: goto P_0c0521cc;
case 0x0c05283au: goto P_0c05283a;
case 0x0c05283cu: goto P_0c05283c;
case 0x0c05283eu: goto P_0c05283e;
case 0x0c052840u: goto P_0c052840;
case 0x0c052842u: goto P_0c052842;
case 0x0c052844u: goto P_0c052844;
case 0x0c052846u: goto P_0c052846;
case 0x0c052848u: goto P_0c052848;
case 0x0c05284au: goto P_0c05284a;
case 0x0c05284cu: goto P_0c05284c;
case 0x0c05284eu: goto P_0c05284e;
case 0x0c052850u: goto P_0c052850;
case 0x0c05344cu: goto P_0c05344c;
case 0x0c05344eu: goto P_0c05344e;
case 0x0c0563acu: goto P_0c0563ac;
case 0x0c0563aeu: goto P_0c0563ae;
case 0x0c0563b0u: goto P_0c0563b0;
case 0x0c0563b2u: goto P_0c0563b2;
case 0x0c0563b4u: goto P_0c0563b4;
case 0x0c0563b6u: goto P_0c0563b6;
case 0x0c0563b8u: goto P_0c0563b8;
case 0x0c0563bau: goto P_0c0563ba;
case 0x0c0563bcu: goto P_0c0563bc;
case 0x0c0563beu: goto P_0c0563be;
case 0x0c0563c0u: goto P_0c0563c0;
case 0x0c0563c2u: goto P_0c0563c2;
case 0x0c0563c4u: goto P_0c0563c4;
case 0x0c0563c6u: goto P_0c0563c6;
case 0x0c0563c8u: goto P_0c0563c8;
case 0x0c0563cau: goto P_0c0563ca;
case 0x0c0563ccu: goto P_0c0563cc;
case 0x0c0563ceu: goto P_0c0563ce;
case 0x0c0563d0u: goto P_0c0563d0;
case 0x0c0563d2u: goto P_0c0563d2;
case 0x0c0563d4u: goto P_0c0563d4;
case 0x0c0563d6u: goto P_0c0563d6;
case 0x0c0563d8u: goto P_0c0563d8;
case 0x0c0563dau: goto P_0c0563da;
case 0x0c0563dcu: goto P_0c0563dc;
case 0x0c0563deu: goto P_0c0563de;
case 0x0c0563e0u: goto P_0c0563e0;
case 0x0c0563e2u: goto P_0c0563e2;
case 0x0c0563e4u: goto P_0c0563e4;
case 0x0c0563e6u: goto P_0c0563e6;
case 0x0c0563e8u: goto P_0c0563e8;
case 0x0c0563eau: goto P_0c0563ea;
case 0x0c0563ecu: goto P_0c0563ec;
case 0x0c0563eeu: goto P_0c0563ee;
case 0x0c0563f0u: goto P_0c0563f0;
case 0x0c0563f2u: goto P_0c0563f2;
case 0x0c0563f4u: goto P_0c0563f4;
case 0x0c0563f6u: goto P_0c0563f6;
case 0x0c0563f8u: goto P_0c0563f8;
case 0x0c0563fau: goto P_0c0563fa;
case 0x0c058500u: goto P_0c058500;
case 0x0c058502u: goto P_0c058502;
case 0x0c058504u: goto P_0c058504;
case 0x0c058506u: goto P_0c058506;
case 0x0c058508u: goto P_0c058508;
case 0x0c05850au: goto P_0c05850a;
case 0x0c05850cu: goto P_0c05850c;
case 0x0c05850eu: goto P_0c05850e;
case 0x0c058510u: goto P_0c058510;
case 0x0c058512u: goto P_0c058512;
case 0x0c058514u: goto P_0c058514;
case 0x0c058516u: goto P_0c058516;
case 0x0c058518u: goto P_0c058518;
case 0x0c05851au: goto P_0c05851a;
case 0x0c05851cu: goto P_0c05851c;
case 0x0c05851eu: goto P_0c05851e;
case 0x0c058520u: goto P_0c058520;
case 0x0c058522u: goto P_0c058522;
case 0x0c058524u: goto P_0c058524;
case 0x0c058526u: goto P_0c058526;
case 0x0c058528u: goto P_0c058528;
case 0x0c05865cu: goto P_0c05865c;
case 0x0c05865eu: goto P_0c05865e;
case 0x0c058660u: goto P_0c058660;
case 0x0c058662u: goto P_0c058662;
case 0x0c058664u: goto P_0c058664;
case 0x0c058666u: goto P_0c058666;
case 0x0c058668u: goto P_0c058668;
case 0x0c05866au: goto P_0c05866a;
case 0x0c05866cu: goto P_0c05866c;
case 0x0c05866eu: goto P_0c05866e;
case 0x0c058670u: goto P_0c058670;
case 0x0c058672u: goto P_0c058672;
case 0x0c058674u: goto P_0c058674;
case 0x0c058676u: goto P_0c058676;
case 0x0c058678u: goto P_0c058678;
case 0x0c05867au: goto P_0c05867a;
case 0x0c05867cu: goto P_0c05867c;
case 0x0c05867eu: goto P_0c05867e;
case 0x0c058680u: goto P_0c058680;
case 0x0c058682u: goto P_0c058682;
case 0x0c058684u: goto P_0c058684;
case 0x0c058686u: goto P_0c058686;
case 0x0c058688u: goto P_0c058688;
case 0x0c05868au: goto P_0c05868a;
case 0x0c05868cu: goto P_0c05868c;
case 0x0c05868eu: goto P_0c05868e;
case 0x0c058690u: goto P_0c058690;
case 0x0c058692u: goto P_0c058692;
case 0x0c058694u: goto P_0c058694;
case 0x0c058696u: goto P_0c058696;
case 0x0c058698u: goto P_0c058698;
case 0x0c05869au: goto P_0c05869a;
case 0x0c05869cu: goto P_0c05869c;
case 0x0c05869eu: goto P_0c05869e;
case 0x0c0586a0u: goto P_0c0586a0;
case 0x0c0586a2u: goto P_0c0586a2;
case 0x0c0586a4u: goto P_0c0586a4;
case 0x0c0586a6u: goto P_0c0586a6;
case 0x0c0586a8u: goto P_0c0586a8;
case 0x0c0586aau: goto P_0c0586aa;
case 0x0c0586acu: goto P_0c0586ac;
case 0x0c0586aeu: goto P_0c0586ae;
case 0x0c0586b0u: goto P_0c0586b0;
case 0x0c0586b2u: goto P_0c0586b2;
case 0x0c0586b4u: goto P_0c0586b4;
case 0x0c0586b6u: goto P_0c0586b6;
case 0x0c0586b8u: goto P_0c0586b8;
case 0x0c0586bau: goto P_0c0586ba;
case 0x0c0586bcu: goto P_0c0586bc;
case 0x0c0586beu: goto P_0c0586be;
case 0x0c0586c0u: goto P_0c0586c0;
case 0x0c0586c2u: goto P_0c0586c2;
case 0x0c0586c4u: goto P_0c0586c4;
case 0x0c0586c6u: goto P_0c0586c6;
case 0x0c0586c8u: goto P_0c0586c8;
case 0x0c0586cau: goto P_0c0586ca;
case 0x0c0586ccu: goto P_0c0586cc;
case 0x0c0586ceu: goto P_0c0586ce;
case 0x0c0586d0u: goto P_0c0586d0;
case 0x0c0586d2u: goto P_0c0586d2;
case 0x0c0586d4u: goto P_0c0586d4;
case 0x0c0586d6u: goto P_0c0586d6;
case 0x0c0586d8u: goto P_0c0586d8;
case 0x0c0586dau: goto P_0c0586da;
case 0x0c0586dcu: goto P_0c0586dc;
case 0x0c0586deu: goto P_0c0586de;
case 0x0c0586e0u: goto P_0c0586e0;
case 0x0c0586e2u: goto P_0c0586e2;
case 0x0c0586e4u: goto P_0c0586e4;
case 0x0c0586e6u: goto P_0c0586e6;
case 0x0c0586e8u: goto P_0c0586e8;
case 0x0c0586eau: goto P_0c0586ea;
case 0x0c0586ecu: goto P_0c0586ec;
case 0x0c0586eeu: goto P_0c0586ee;
case 0x0c0586f0u: goto P_0c0586f0;
case 0x0c0586f2u: goto P_0c0586f2;
case 0x0c0586f4u: goto P_0c0586f4;
case 0x0c0586f6u: goto P_0c0586f6;
case 0x0c0586f8u: goto P_0c0586f8;
case 0x0c0586fau: goto P_0c0586fa;
case 0x0c0586fcu: goto P_0c0586fc;
case 0x0c0586feu: goto P_0c0586fe;
case 0x0c058700u: goto P_0c058700;
case 0x0c058702u: goto P_0c058702;
case 0x0c058704u: goto P_0c058704;
case 0x0c058706u: goto P_0c058706;
case 0x0c058708u: goto P_0c058708;
case 0x0c05870au: goto P_0c05870a;
case 0x0c05870cu: goto P_0c05870c;
case 0x0c05870eu: goto P_0c05870e;
case 0x0c058710u: goto P_0c058710;
case 0x0c058712u: goto P_0c058712;
case 0x0c058714u: goto P_0c058714;
case 0x0c058716u: goto P_0c058716;
case 0x0c058718u: goto P_0c058718;
case 0x0c05871au: goto P_0c05871a;
case 0x0c05871cu: goto P_0c05871c;
case 0x0c05871eu: goto P_0c05871e;
case 0x0c058720u: goto P_0c058720;
case 0x0c058722u: goto P_0c058722;
case 0x0c058724u: goto P_0c058724;
case 0x0c058726u: goto P_0c058726;
case 0x0c058728u: goto P_0c058728;
case 0x0c05872au: goto P_0c05872a;
case 0x0c05872cu: goto P_0c05872c;
case 0x0c05872eu: goto P_0c05872e;
case 0x0c058730u: goto P_0c058730;
case 0x0c058732u: goto P_0c058732;
case 0x0c058734u: goto P_0c058734;
case 0x0c058736u: goto P_0c058736;
case 0x0c058738u: goto P_0c058738;
case 0x0c05873au: goto P_0c05873a;
case 0x0c05873cu: goto P_0c05873c;
case 0x0c05873eu: goto P_0c05873e;
case 0x0c058740u: goto P_0c058740;
case 0x0c058742u: goto P_0c058742;
case 0x0c058744u: goto P_0c058744;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0387f0: /* original 4f22, guest PC 0x0c0387f0 */
if(!s->budget--) { s->failed_pc=0x0c0387f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0387f2;
P_0c0387f2: /* original d317, guest PC 0x0c0387f2 */
if(!s->budget--) { s->failed_pc=0x0c0387f2u; return 0; }
r[3]=read(ram,0x0c038850u,4);
goto P_0c0387f4;
P_0c0387f4: /* original 7ff8, guest PC 0x0c0387f4 */
if(!s->budget--) { s->failed_pc=0x0c0387f4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0387f6;
P_0c0387f6: /* original 65f3, guest PC 0x0c0387f6 */
if(!s->budget--) { s->failed_pc=0x0c0387f6u; return 0; }
r[5]=r[15];
goto P_0c0387f8;
P_0c0387f8: /* original 7504, guest PC 0x0c0387f8 */
if(!s->budget--) { s->failed_pc=0x0c0387f8u; return 0; }
r[5]+=0x00000004u;
goto P_0c0387fa;
P_0c0387fa: /* original 430b, guest PC 0x0c0387fa */
if(!s->budget--) { s->failed_pc=0x0c0387fau; return 0; }
target=r[3];
r[16]=0x0c0387feu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0387feu) { target=s->pc; goto dispatch; }
goto P_0c0387fe;
P_0c0387fc: /* original 64f3, guest PC 0x0c0387fc */
if(!s->budget--) { s->failed_pc=0x0c0387fcu; return 0; }
r[4]=r[15];
goto P_0c0387fe;
P_0c0387fe: /* original 60f2, guest PC 0x0c0387fe */
if(!s->budget--) { s->failed_pc=0x0c0387feu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c038800;
P_0c038800: /* original 7f08, guest PC 0x0c038800 */
if(!s->budget--) { s->failed_pc=0x0c038800u; return 0; }
r[15]+=0x00000008u;
goto P_0c038802;
P_0c038802: /* original 4f26, guest PC 0x0c038802 */
if(!s->budget--) { s->failed_pc=0x0c038802u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038804;
P_0c038804: /* original 000b, guest PC 0x0c038804 */
if(!s->budget--) { s->failed_pc=0x0c038804u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c038806: /* original 0009, guest PC 0x0c038806 */
if(!s->budget--) { s->failed_pc=0x0c038806u; return 0; }
return vf3_matrix_family(0x0c038808u,s,ram);
P_0c038810: /* original 4f22, guest PC 0x0c038810 */
if(!s->budget--) { s->failed_pc=0x0c038810u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038812;
P_0c038812: /* original d30f, guest PC 0x0c038812 */
if(!s->budget--) { s->failed_pc=0x0c038812u; return 0; }
r[3]=read(ram,0x0c038850u,4);
goto P_0c038814;
P_0c038814: /* original 7ff8, guest PC 0x0c038814 */
if(!s->budget--) { s->failed_pc=0x0c038814u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c038816;
P_0c038816: /* original 64f3, guest PC 0x0c038816 */
if(!s->budget--) { s->failed_pc=0x0c038816u; return 0; }
r[4]=r[15];
goto P_0c038818;
P_0c038818: /* original 65f3, guest PC 0x0c038818 */
if(!s->budget--) { s->failed_pc=0x0c038818u; return 0; }
r[5]=r[15];
goto P_0c03881a;
P_0c03881a: /* original 430b, guest PC 0x0c03881a */
if(!s->budget--) { s->failed_pc=0x0c03881au; return 0; }
target=r[3];
r[16]=0x0c03881eu;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03881eu) { target=s->pc; goto dispatch; }
goto P_0c03881e;
P_0c03881c: /* original 7404, guest PC 0x0c03881c */
if(!s->budget--) { s->failed_pc=0x0c03881cu; return 0; }
r[4]+=0x00000004u;
goto P_0c03881e;
P_0c03881e: /* original 60f2, guest PC 0x0c03881e */
if(!s->budget--) { s->failed_pc=0x0c03881eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c038820;
P_0c038820: /* original 7f08, guest PC 0x0c038820 */
if(!s->budget--) { s->failed_pc=0x0c038820u; return 0; }
r[15]+=0x00000008u;
goto P_0c038822;
P_0c038822: /* original 4f26, guest PC 0x0c038822 */
if(!s->budget--) { s->failed_pc=0x0c038822u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038824;
P_0c038824: /* original 000b, guest PC 0x0c038824 */
if(!s->budget--) { s->failed_pc=0x0c038824u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c038826: /* original 0009, guest PC 0x0c038826 */
if(!s->budget--) { s->failed_pc=0x0c038826u; return 0; }
return vf3_matrix_family(0x0c038828u,s,ram);
P_0c03a1ba: /* original 4f22, guest PC 0x0c03a1ba */
if(!s->budget--) { s->failed_pc=0x0c03a1bau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03a1bc;
P_0c03a1bc: /* original f32d, guest PC 0x0c03a1bc */
if(!s->budget--) { s->failed_pc=0x0c03a1bcu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a1be;
P_0c03a1be: /* original f108, guest PC 0x0c03a1be */
if(!s->budget--) { s->failed_pc=0x0c03a1beu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a1c0;
P_0c03a1c0: /* original f322, guest PC 0x0c03a1c0 */
if(!s->budget--) { s->failed_pc=0x0c03a1c0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a1c2;
P_0c03a1c2: /* original f43c, guest PC 0x0c03a1c2 */
if(!s->budget--) { s->failed_pc=0x0c03a1c2u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a1c4;
P_0c03a1c4: /* original b044, guest PC 0x0c03a1c4 */
if(!s->budget--) { s->failed_pc=0x0c03a1c4u; return 0; }
target=0x0c03a250u; r[16]=0x0c03a1c8u;
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03a1c8u) { target=s->pc; goto dispatch; }
goto P_0c03a1c8;
P_0c03a1c6: /* original f413, guest PC 0x0c03a1c6 */
if(!s->budget--) { s->failed_pc=0x0c03a1c6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'/');
goto P_0c03a1c8;
P_0c03a1c8: /* original f40c, guest PC 0x0c03a1c8 */
if(!s->budget--) { s->failed_pc=0x0c03a1c8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03a1ca;
P_0c03a1ca: /* original c71c, guest PC 0x0c03a1ca */
if(!s->budget--) { s->failed_pc=0x0c03a1cau; return 0; }
r[0]=0x0c03a23cu;
goto P_0c03a1cc;
P_0c03a1cc: /* original f09d, guest PC 0x0c03a1cc */
if(!s->budget--) { s->failed_pc=0x0c03a1ccu; return 0; }
fr[0]=0x3f800000u;
goto P_0c03a1ce;
P_0c03a1ce: /* original f043, guest PC 0x0c03a1ce */
if(!s->budget--) { s->failed_pc=0x0c03a1ceu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'/');
goto P_0c03a1d0;
P_0c03a1d0: /* original 4f26, guest PC 0x0c03a1d0 */
if(!s->budget--) { s->failed_pc=0x0c03a1d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03a1d2;
P_0c03a1d2: /* original f308, guest PC 0x0c03a1d2 */
if(!s->budget--) { s->failed_pc=0x0c03a1d2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a1d4;
P_0c03a1d4: /* original f040, guest PC 0x0c03a1d4 */
if(!s->budget--) { s->failed_pc=0x0c03a1d4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'+');
goto P_0c03a1d6;
P_0c03a1d6: /* original 000b, guest PC 0x0c03a1d6 */
if(!s->budget--) { s->failed_pc=0x0c03a1d6u; return 0; }
target=r[16];
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'/');
s->pc=target; return ram->oob==0;
P_0c03a1d8: /* original f033, guest PC 0x0c03a1d8 */
if(!s->budget--) { s->failed_pc=0x0c03a1d8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'/');
return vf3_matrix_family(0x0c03a1dau,s,ram);
P_0c03a250: /* original fffb, guest PC 0x0c03a250 */
if(!s->budget--) { s->failed_pc=0x0c03a250u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03a252;
P_0c03a252: /* original c760, guest PC 0x0c03a252 */
if(!s->budget--) { s->failed_pc=0x0c03a252u; return 0; }
r[0]=0x0c03a3d4u;
goto P_0c03a254;
P_0c03a254: /* original ffeb, guest PC 0x0c03a254 */
if(!s->budget--) { s->failed_pc=0x0c03a254u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03a256;
P_0c03a256: /* original f28d, guest PC 0x0c03a256 */
if(!s->budget--) { s->failed_pc=0x0c03a256u; return 0; }
fr[2]=0;
goto P_0c03a258;
P_0c03a258: /* original ff4c, guest PC 0x0c03a258 */
if(!s->budget--) { s->failed_pc=0x0c03a258u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c03a25a;
P_0c03a25a: /* original f2f5, guest PC 0x0c03a25a */
if(!s->budget--) { s->failed_pc=0x0c03a25au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c03a25c;
P_0c03a25c: /* original 8d08, guest PC 0x0c03a25c */
if(!s->budget--) { s->failed_pc=0x0c03a25cu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c03a270; }
goto P_0c03a260;
P_0c03a25e: /* original f408, guest PC 0x0c03a25e */
if(!s->budget--) { s->failed_pc=0x0c03a25eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c03a260;
P_0c03a260: /* original c75d, guest PC 0x0c03a260 */
if(!s->budget--) { s->failed_pc=0x0c03a260u; return 0; }
r[0]=0x0c03a3d8u;
goto P_0c03a262;
P_0c03a262: /* original a007, guest PC 0x0c03a262 */
if(!s->budget--) { s->failed_pc=0x0c03a262u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a274;
P_0c03a264: /* original f308, guest PC 0x0c03a264 */
if(!s->budget--) { s->failed_pc=0x0c03a264u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
return vf3_matrix_family(0x0c03a266u,s,ram);
P_0c03a270: /* original c75a, guest PC 0x0c03a270 */
if(!s->budget--) { s->failed_pc=0x0c03a270u; return 0; }
r[0]=0x0c03a3dcu;
goto P_0c03a272;
P_0c03a272: /* original f308, guest PC 0x0c03a272 */
if(!s->budget--) { s->failed_pc=0x0c03a272u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a274;
P_0c03a274: /* original f2fc, guest PC 0x0c03a274 */
if(!s->budget--) { s->failed_pc=0x0c03a274u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c03a276;
P_0c03a276: /* original f243, guest PC 0x0c03a276 */
if(!s->budget--) { s->failed_pc=0x0c03a276u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'/');
goto P_0c03a278;
P_0c03a278: /* original c759, guest PC 0x0c03a278 */
if(!s->budget--) { s->failed_pc=0x0c03a278u; return 0; }
r[0]=0x0c03a3e0u;
goto P_0c03a27a;
P_0c03a27a: /* original e50a, guest PC 0x0c03a27a */
if(!s->budget--) { s->failed_pc=0x0c03a27au; return 0; }
r[5]=0x0000000au;
goto P_0c03a27c;
P_0c03a27c: /* original e606, guest PC 0x0c03a27c */
if(!s->budget--) { s->failed_pc=0x0c03a27cu; return 0; }
r[6]=0x00000006u;
goto P_0c03a27e;
P_0c03a27e: /* original f320, guest PC 0x0c03a27e */
if(!s->budget--) { s->failed_pc=0x0c03a27eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c03a280;
P_0c03a280: /* original f33d, guest PC 0x0c03a280 */
if(!s->budget--) { s->failed_pc=0x0c03a280u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a282;
P_0c03a282: /* original f308, guest PC 0x0c03a282 */
if(!s->budget--) { s->failed_pc=0x0c03a282u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a284;
P_0c03a284: /* original 045a, guest PC 0x0c03a284 */
if(!s->budget--) { s->failed_pc=0x0c03a284u; return 0; }
r[4]=r[53];
goto P_0c03a286;
P_0c03a286: /* original 445a, guest PC 0x0c03a286 */
if(!s->budget--) { s->failed_pc=0x0c03a286u; return 0; }
r[53]=r[4];
goto P_0c03a288;
P_0c03a288: /* original f22d, guest PC 0x0c03a288 */
if(!s->budget--) { s->failed_pc=0x0c03a288u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a28a;
P_0c03a28a: /* original f242, guest PC 0x0c03a28a */
if(!s->budget--) { s->failed_pc=0x0c03a28au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c03a28c;
P_0c03a28c: /* original ff21, guest PC 0x0c03a28c */
if(!s->budget--) { s->failed_pc=0x0c03a28cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'-');
goto P_0c03a28e;
P_0c03a28e: /* original f4fc, guest PC 0x0c03a28e */
if(!s->budget--) { s->failed_pc=0x0c03a28eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c03a290;
P_0c03a290: /* original f4f2, guest PC 0x0c03a290 */
if(!s->budget--) { s->failed_pc=0x0c03a290u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03a292;
P_0c03a292: /* original fe4c, guest PC 0x0c03a292 */
if(!s->budget--) { s->failed_pc=0x0c03a292u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c03a294;
P_0c03a294: /* original fe33, guest PC 0x0c03a294 */
if(!s->budget--) { s->failed_pc=0x0c03a294u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'/');
goto P_0c03a296;
P_0c03a296: /* original 455a, guest PC 0x0c03a296 */
if(!s->budget--) { s->failed_pc=0x0c03a296u; return 0; }
r[53]=r[5];
goto P_0c03a298;
P_0c03a298: /* original 75fc, guest PC 0x0c03a298 */
if(!s->budget--) { s->failed_pc=0x0c03a298u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c03a29a;
P_0c03a29a: /* original 3563, guest PC 0x0c03a29a */
if(!s->budget--) { s->failed_pc=0x0c03a29au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c03a29c;
P_0c03a29c: /* original f32d, guest PC 0x0c03a29c */
if(!s->budget--) { s->failed_pc=0x0c03a29cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a29e;
P_0c03a29e: /* original f3e0, guest PC 0x0c03a29e */
if(!s->budget--) { s->failed_pc=0x0c03a29eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c03a2a0;
P_0c03a2a0: /* original fe4c, guest PC 0x0c03a2a0 */
if(!s->budget--) { s->failed_pc=0x0c03a2a0u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c03a2a2;
P_0c03a2a2: /* original 8df8, guest PC 0x0c03a2a2 */
if(!s->budget--) { s->failed_pc=0x0c03a2a2u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'/');
if(cond) { goto P_0c03a296; }
goto P_0c03a2a6;
P_0c03a2a4: /* original fe33, guest PC 0x0c03a2a4 */
if(!s->budget--) { s->failed_pc=0x0c03a2a4u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'/');
goto P_0c03a2a6;
P_0c03a2a6: /* original f3fc, guest PC 0x0c03a2a6 */
if(!s->budget--) { s->failed_pc=0x0c03a2a6u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c03a2a8;
P_0c03a2a8: /* original f3e0, guest PC 0x0c03a2a8 */
if(!s->budget--) { s->failed_pc=0x0c03a2a8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c03a2aa;
P_0c03a2aa: /* original f1ec, guest PC 0x0c03a2aa */
if(!s->budget--) { s->failed_pc=0x0c03a2aau; return 0; }
vf3_matrix_move(s,1,14);
goto P_0c03a2ac;
P_0c03a2ac: /* original f1f1, guest PC 0x0c03a2ac */
if(!s->budget--) { s->failed_pc=0x0c03a2acu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'-');
goto P_0c03a2ae;
P_0c03a2ae: /* original c74d, guest PC 0x0c03a2ae */
if(!s->budget--) { s->failed_pc=0x0c03a2aeu; return 0; }
r[0]=0x0c03a3e4u;
goto P_0c03a2b0;
P_0c03a2b0: /* original fef9, guest PC 0x0c03a2b0 */
if(!s->budget--) { s->failed_pc=0x0c03a2b0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a2b2;
P_0c03a2b2: /* original f208, guest PC 0x0c03a2b2 */
if(!s->budget--) { s->failed_pc=0x0c03a2b2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a2b4;
P_0c03a2b4: /* original f320, guest PC 0x0c03a2b4 */
if(!s->budget--) { s->failed_pc=0x0c03a2b4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c03a2b6;
P_0c03a2b6: /* original f120, guest PC 0x0c03a2b6 */
if(!s->budget--) { s->failed_pc=0x0c03a2b6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c03a2b8;
P_0c03a2b8: /* original f43c, guest PC 0x0c03a2b8 */
if(!s->budget--) { s->failed_pc=0x0c03a2b8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a2ba;
P_0c03a2ba: /* original f413, guest PC 0x0c03a2ba */
if(!s->budget--) { s->failed_pc=0x0c03a2bau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'/');
goto P_0c03a2bc;
P_0c03a2bc: /* original a068, guest PC 0x0c03a2bc */
if(!s->budget--) { s->failed_pc=0x0c03a2bcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a390;
P_0c03a2be: /* original fff9, guest PC 0x0c03a2be */
if(!s->budget--) { s->failed_pc=0x0c03a2beu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c03a2c0u,s,ram);
P_0c03a390: /* original f38d, guest PC 0x0c03a390 */
if(!s->budget--) { s->failed_pc=0x0c03a390u; return 0; }
fr[3]=0;
goto P_0c03a392;
P_0c03a392: /* original f434, guest PC 0x0c03a392 */
if(!s->budget--) { s->failed_pc=0x0c03a392u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c03a394;
P_0c03a394: /* original 7ffc, guest PC 0x0c03a394 */
if(!s->budget--) { s->failed_pc=0x0c03a394u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03a396;
P_0c03a396: /* original 8b03, guest PC 0x0c03a396 */
if(!s->budget--) { s->failed_pc=0x0c03a396u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a3a0; }
goto P_0c03a398;
P_0c03a398: /* original f08d, guest PC 0x0c03a398 */
if(!s->budget--) { s->failed_pc=0x0c03a398u; return 0; }
fr[0]=0;
goto P_0c03a39a;
P_0c03a39a: /* original 000b, guest PC 0x0c03a39a */
if(!s->budget--) { s->failed_pc=0x0c03a39au; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c03a39c: /* original 7f04, guest PC 0x0c03a39c */
if(!s->budget--) { s->failed_pc=0x0c03a39cu; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c03a39eu,s,ram);
P_0c03a3a0: /* original 65f3, guest PC 0x0c03a3a0 */
if(!s->budget--) { s->failed_pc=0x0c03a3a0u; return 0; }
r[5]=r[15];
goto P_0c03a3a2;
P_0c03a3a2: /* original e2e9, guest PC 0x0c03a3a2 */
if(!s->budget--) { s->failed_pc=0x0c03a3a2u; return 0; }
r[2]=0xffffffe9u;
goto P_0c03a3a4;
P_0c03a3a4: /* original e701, guest PC 0x0c03a3a4 */
if(!s->budget--) { s->failed_pc=0x0c03a3a4u; return 0; }
r[7]=0x00000001u;
goto P_0c03a3a6;
P_0c03a3a6: /* original ff4a, guest PC 0x0c03a3a6 */
if(!s->budget--) { s->failed_pc=0x0c03a3a6u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03a3a8;
P_0c03a3a8: /* original 6352, guest PC 0x0c03a3a8 */
if(!s->budget--) { s->failed_pc=0x0c03a3a8u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c03a3aa;
P_0c03a3aa: /* original d611, guest PC 0x0c03a3aa */
if(!s->budget--) { s->failed_pc=0x0c03a3aau; return 0; }
r[6]=read(ram,0x0c03a3f0u,4);
goto P_0c03a3ac;
P_0c03a3ac: /* original 432c, guest PC 0x0c03a3ac */
if(!s->budget--) { s->failed_pc=0x0c03a3acu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c03a3ae;
P_0c03a3ae: /* original 633c, guest PC 0x0c03a3ae */
if(!s->budget--) { s->failed_pc=0x0c03a3aeu; return 0; }
r[3]=r[3]&255u;
goto P_0c03a3b0;
P_0c03a3b0: /* original 343c, guest PC 0x0c03a3b0 */
if(!s->budget--) { s->failed_pc=0x0c03a3b0u; return 0; }
r[4]+=r[3];
goto P_0c03a3b2;
P_0c03a3b2: /* original 3473, guest PC 0x0c03a3b2 */
if(!s->budget--) { s->failed_pc=0x0c03a3b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c03a3b4;
P_0c03a3b4: /* original 8924, guest PC 0x0c03a3b4 */
if(!s->budget--) { s->failed_pc=0x0c03a3b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a400; }
goto P_0c03a3b6;
P_0c03a3b6: /* original 6252, guest PC 0x0c03a3b6 */
if(!s->budget--) { s->failed_pc=0x0c03a3b6u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c03a3b8;
P_0c03a3b8: /* original 3748, guest PC 0x0c03a3b8 */
if(!s->budget--) { s->failed_pc=0x0c03a3b8u; return 0; }
r[7]-=r[4];
goto P_0c03a3ba;
P_0c03a3ba: /* original d30e, guest PC 0x0c03a3ba */
if(!s->budget--) { s->failed_pc=0x0c03a3bau; return 0; }
r[3]=read(ram,0x0c03a3f4u,4);
goto P_0c03a3bc;
P_0c03a3bc: /* original 677b, guest PC 0x0c03a3bc */
if(!s->budget--) { s->failed_pc=0x0c03a3bcu; return 0; }
r[7]=0u-r[7];
goto P_0c03a3be;
P_0c03a3be: /* original d10e, guest PC 0x0c03a3be */
if(!s->budget--) { s->failed_pc=0x0c03a3beu; return 0; }
r[1]=read(ram,0x0c03a3f8u,4);
goto P_0c03a3c0;
P_0c03a3c0: /* original 2239, guest PC 0x0c03a3c0 */
if(!s->budget--) { s->failed_pc=0x0c03a3c0u; return 0; }
r[2]&=r[3];
goto P_0c03a3c2;
P_0c03a3c2: /* original 6052, guest PC 0x0c03a3c2 */
if(!s->budget--) { s->failed_pc=0x0c03a3c2u; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c03a3c4;
P_0c03a3c4: /* original 221b, guest PC 0x0c03a3c4 */
if(!s->budget--) { s->failed_pc=0x0c03a3c4u; return 0; }
r[2]|=r[1];
goto P_0c03a3c6;
P_0c03a3c6: /* original 427c, guest PC 0x0c03a3c6 */
if(!s->budget--) { s->failed_pc=0x0c03a3c6u; return 0; }
r[2]=(r[7]&0x80000000u)?((r[7]&31u)?(uint32_t)((int32_t)r[2]>>((-r[7])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[7]&31u);
goto P_0c03a3c8;
P_0c03a3c8: /* original 2069, guest PC 0x0c03a3c8 */
if(!s->budget--) { s->failed_pc=0x0c03a3c8u; return 0; }
r[0]&=r[6];
goto P_0c03a3ca;
P_0c03a3ca: /* original 6423, guest PC 0x0c03a3ca */
if(!s->budget--) { s->failed_pc=0x0c03a3cau; return 0; }
r[4]=r[2];
goto P_0c03a3cc;
P_0c03a3cc: /* original 6203, guest PC 0x0c03a3cc */
if(!s->budget--) { s->failed_pc=0x0c03a3ccu; return 0; }
r[2]=r[0];
goto P_0c03a3ce;
P_0c03a3ce: /* original 224b, guest PC 0x0c03a3ce */
if(!s->budget--) { s->failed_pc=0x0c03a3ceu; return 0; }
r[2]|=r[4];
goto P_0c03a3d0;
P_0c03a3d0: /* original a02f, guest PC 0x0c03a3d0 */
if(!s->budget--) { s->failed_pc=0x0c03a3d0u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c03a432;
P_0c03a3d2: /* original 2522, guest PC 0x0c03a3d2 */
if(!s->budget--) { s->failed_pc=0x0c03a3d2u; return 0; }
write(ram,r[5],r[2],4);
return vf3_matrix_family(0x0c03a3d4u,s,ram);
P_0c03a400: /* original 936e, guest PC 0x0c03a400 */
if(!s->budget--) { s->failed_pc=0x0c03a400u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a4e0u,2);
goto P_0c03a402;
P_0c03a402: /* original 3437, guest PC 0x0c03a402 */
if(!s->budget--) { s->failed_pc=0x0c03a402u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c03a404;
P_0c03a404: /* original 8b0c, guest PC 0x0c03a404 */
if(!s->budget--) { s->failed_pc=0x0c03a404u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a420; }
goto P_0c03a406;
P_0c03a406: /* original 6152, guest PC 0x0c03a406 */
if(!s->budget--) { s->failed_pc=0x0c03a406u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c03a408;
P_0c03a408: /* original d236, guest PC 0x0c03a408 */
if(!s->budget--) { s->failed_pc=0x0c03a408u; return 0; }
r[2]=read(ram,0x0c03a4e4u,4);
goto P_0c03a40a;
P_0c03a40a: /* original 2169, guest PC 0x0c03a40a */
if(!s->budget--) { s->failed_pc=0x0c03a40au; return 0; }
r[1]&=r[6];
goto P_0c03a40c;
P_0c03a40c: /* original 6013, guest PC 0x0c03a40c */
if(!s->budget--) { s->failed_pc=0x0c03a40cu; return 0; }
r[0]=r[1];
goto P_0c03a40e;
P_0c03a40e: /* original 202b, guest PC 0x0c03a40e */
if(!s->budget--) { s->failed_pc=0x0c03a40eu; return 0; }
r[0]|=r[2];
goto P_0c03a410;
P_0c03a410: /* original a00f, guest PC 0x0c03a410 */
if(!s->budget--) { s->failed_pc=0x0c03a410u; return 0; }
write(ram,r[5],r[0],4);
goto P_0c03a432;
P_0c03a412: /* original 2502, guest PC 0x0c03a412 */
if(!s->budget--) { s->failed_pc=0x0c03a412u; return 0; }
write(ram,r[5],r[0],4);
return vf3_matrix_family(0x0c03a414u,s,ram);
P_0c03a420: /* original 6252, guest PC 0x0c03a420 */
if(!s->budget--) { s->failed_pc=0x0c03a420u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c03a422;
P_0c03a422: /* original d331, guest PC 0x0c03a422 */
if(!s->budget--) { s->failed_pc=0x0c03a422u; return 0; }
r[3]=read(ram,0x0c03a4e8u,4);
goto P_0c03a424;
P_0c03a424: /* original 2239, guest PC 0x0c03a424 */
if(!s->budget--) { s->failed_pc=0x0c03a424u; return 0; }
r[2]&=r[3];
goto P_0c03a426;
P_0c03a426: /* original 2522, guest PC 0x0c03a426 */
if(!s->budget--) { s->failed_pc=0x0c03a426u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c03a428;
P_0c03a428: /* original e217, guest PC 0x0c03a428 */
if(!s->budget--) { s->failed_pc=0x0c03a428u; return 0; }
r[2]=0x00000017u;
goto P_0c03a42a;
P_0c03a42a: /* original 6152, guest PC 0x0c03a42a */
if(!s->budget--) { s->failed_pc=0x0c03a42au; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c03a42c;
P_0c03a42c: /* original 442c, guest PC 0x0c03a42c */
if(!s->budget--) { s->failed_pc=0x0c03a42cu; return 0; }
r[4]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[4]>>((-r[2])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[2]&31u);
goto P_0c03a42e;
P_0c03a42e: /* original 214b, guest PC 0x0c03a42e */
if(!s->budget--) { s->failed_pc=0x0c03a42eu; return 0; }
r[1]|=r[4];
goto P_0c03a430;
P_0c03a430: /* original 2512, guest PC 0x0c03a430 */
if(!s->budget--) { s->failed_pc=0x0c03a430u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c03a432;
P_0c03a432: /* original f0f8, guest PC 0x0c03a432 */
if(!s->budget--) { s->failed_pc=0x0c03a432u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c03a434;
P_0c03a434: /* original 000b, guest PC 0x0c03a434 */
if(!s->budget--) { s->failed_pc=0x0c03a434u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c03a436: /* original 7f04, guest PC 0x0c03a436 */
if(!s->budget--) { s->failed_pc=0x0c03a436u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c03a438u,s,ram);
P_0c03a5c0: /* original 4f22, guest PC 0x0c03a5c0 */
if(!s->budget--) { s->failed_pc=0x0c03a5c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03a5c2;
P_0c03a5c2: /* original bfed, guest PC 0x0c03a5c2 */
if(!s->budget--) { s->failed_pc=0x0c03a5c2u; return 0; }
target=0x0c03a5a0u; r[16]=0x0c03a5c6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03a5c6u) { target=s->pc; goto dispatch; }
goto P_0c03a5c6;
P_0c03a5c4: /* original 0009, guest PC 0x0c03a5c4 */
if(!s->budget--) { s->failed_pc=0x0c03a5c4u; return 0; }
goto P_0c03a5c6;
P_0c03a5c6: /* original 405a, guest PC 0x0c03a5c6 */
if(!s->budget--) { s->failed_pc=0x0c03a5c6u; return 0; }
r[53]=r[0];
goto P_0c03a5c8;
P_0c03a5c8: /* original c70a, guest PC 0x0c03a5c8 */
if(!s->budget--) { s->failed_pc=0x0c03a5c8u; return 0; }
r[0]=0x0c03a5f4u;
goto P_0c03a5ca;
P_0c03a5ca: /* original 4f26, guest PC 0x0c03a5ca */
if(!s->budget--) { s->failed_pc=0x0c03a5cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03a5cc;
P_0c03a5cc: /* original f208, guest PC 0x0c03a5cc */
if(!s->budget--) { s->failed_pc=0x0c03a5ccu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a5ce;
P_0c03a5ce: /* original f32d, guest PC 0x0c03a5ce */
if(!s->budget--) { s->failed_pc=0x0c03a5ceu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a5d0;
P_0c03a5d0: /* original f03c, guest PC 0x0c03a5d0 */
if(!s->budget--) { s->failed_pc=0x0c03a5d0u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c03a5d2;
P_0c03a5d2: /* original 000b, guest PC 0x0c03a5d2 */
if(!s->budget--) { s->failed_pc=0x0c03a5d2u; return 0; }
target=r[16];
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
s->pc=target; return ram->oob==0;
P_0c03a5d4: /* original f022, guest PC 0x0c03a5d4 */
if(!s->budget--) { s->failed_pc=0x0c03a5d4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
return vf3_matrix_family(0x0c03a5d6u,s,ram);
P_0c03a772: /* original 4f22, guest PC 0x0c03a772 */
if(!s->budget--) { s->failed_pc=0x0c03a772u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03a774;
P_0c03a774: /* original f322, guest PC 0x0c03a774 */
if(!s->budget--) { s->failed_pc=0x0c03a774u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a776;
P_0c03a776: /* original f43c, guest PC 0x0c03a776 */
if(!s->budget--) { s->failed_pc=0x0c03a776u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a778;
P_0c03a778: /* original f413, guest PC 0x0c03a778 */
if(!s->budget--) { s->failed_pc=0x0c03a778u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'/');
goto P_0c03a77a;
P_0c03a77a: /* original f34c, guest PC 0x0c03a77a */
if(!s->budget--) { s->failed_pc=0x0c03a77au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a77c;
P_0c03a77c: /* original f35d, guest PC 0x0c03a77c */
if(!s->budget--) { s->failed_pc=0x0c03a77cu; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c03a77e;
P_0c03a77e: /* original f305, guest PC 0x0c03a77e */
if(!s->budget--) { s->failed_pc=0x0c03a77eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[0]))!=0);
goto P_0c03a780;
P_0c03a780: /* original 8b0e, guest PC 0x0c03a780 */
if(!s->budget--) { s->failed_pc=0x0c03a780u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a7a0; }
goto P_0c03a782;
P_0c03a782: /* original bd65, guest PC 0x0c03a782 */
if(!s->budget--) { s->failed_pc=0x0c03a782u; return 0; }
target=0x0c03a250u; r[16]=0x0c03a786u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03a786u) { target=s->pc; goto dispatch; }
goto P_0c03a786;
P_0c03a784: /* original 0009, guest PC 0x0c03a784 */
if(!s->budget--) { s->failed_pc=0x0c03a784u; return 0; }
goto P_0c03a786;
P_0c03a786: /* original f39d, guest PC 0x0c03a786 */
if(!s->budget--) { s->failed_pc=0x0c03a786u; return 0; }
fr[3]=0x3f800000u;
goto P_0c03a788;
P_0c03a788: /* original c764, guest PC 0x0c03a788 */
if(!s->budget--) { s->failed_pc=0x0c03a788u; return 0; }
r[0]=0x0c03a91cu;
goto P_0c03a78a;
P_0c03a78a: /* original f40c, guest PC 0x0c03a78a */
if(!s->budget--) { s->failed_pc=0x0c03a78au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03a78c;
P_0c03a78c: /* original f343, guest PC 0x0c03a78c */
if(!s->budget--) { s->failed_pc=0x0c03a78cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'/');
goto P_0c03a78e;
P_0c03a78e: /* original 4f26, guest PC 0x0c03a78e */
if(!s->budget--) { s->failed_pc=0x0c03a78eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03a790;
P_0c03a790: /* original f031, guest PC 0x0c03a790 */
if(!s->budget--) { s->failed_pc=0x0c03a790u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c03a792;
P_0c03a792: /* original f308, guest PC 0x0c03a792 */
if(!s->budget--) { s->failed_pc=0x0c03a792u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a794;
P_0c03a794: /* original 000b, guest PC 0x0c03a794 */
if(!s->budget--) { s->failed_pc=0x0c03a794u; return 0; }
target=r[16];
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'/');
s->pc=target; return ram->oob==0;
P_0c03a796: /* original f033, guest PC 0x0c03a796 */
if(!s->budget--) { s->failed_pc=0x0c03a796u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'/');
return vf3_matrix_family(0x0c03a798u,s,ram);
P_0c03a7a0: /* original f04c, guest PC 0x0c03a7a0 */
if(!s->budget--) { s->failed_pc=0x0c03a7a0u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a7a2;
P_0c03a7a2: /* original f042, guest PC 0x0c03a7a2 */
if(!s->budget--) { s->failed_pc=0x0c03a7a2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c03a7a4;
P_0c03a7a4: /* original c763, guest PC 0x0c03a7a4 */
if(!s->budget--) { s->failed_pc=0x0c03a7a4u; return 0; }
r[0]=0x0c03a934u;
goto P_0c03a7a6;
P_0c03a7a6: /* original f29d, guest PC 0x0c03a7a6 */
if(!s->budget--) { s->failed_pc=0x0c03a7a6u; return 0; }
fr[2]=0x3f800000u;
goto P_0c03a7a8;
P_0c03a7a8: /* original f308, guest PC 0x0c03a7a8 */
if(!s->budget--) { s->failed_pc=0x0c03a7a8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a7aa;
P_0c03a7aa: /* original f033, guest PC 0x0c03a7aa */
if(!s->budget--) { s->failed_pc=0x0c03a7aau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'/');
goto P_0c03a7ac;
P_0c03a7ac: /* original f020, guest PC 0x0c03a7ac */
if(!s->budget--) { s->failed_pc=0x0c03a7acu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'+');
goto P_0c03a7ae;
P_0c03a7ae: /* original f042, guest PC 0x0c03a7ae */
if(!s->budget--) { s->failed_pc=0x0c03a7aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c03a7b0;
P_0c03a7b0: /* original 4f26, guest PC 0x0c03a7b0 */
if(!s->budget--) { s->failed_pc=0x0c03a7b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03a7b2;
P_0c03a7b2: /* original 000b, guest PC 0x0c03a7b2 */
if(!s->budget--) { s->failed_pc=0x0c03a7b2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a7b4: /* original 0009, guest PC 0x0c03a7b4 */
if(!s->budget--) { s->failed_pc=0x0c03a7b4u; return 0; }
return vf3_matrix_family(0x0c03a7b6u,s,ram);
P_0c03ac16: /* original 4f22, guest PC 0x0c03ac16 */
if(!s->budget--) { s->failed_pc=0x0c03ac16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ac18;
P_0c03ac18: /* original 2e32, guest PC 0x0c03ac18 */
if(!s->budget--) { s->failed_pc=0x0c03ac18u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c03ac1a;
P_0c03ac1a: /* original d298, guest PC 0x0c03ac1a */
if(!s->budget--) { s->failed_pc=0x0c03ac1au; return 0; }
r[2]=read(ram,0x0c03ae7cu,4);
goto P_0c03ac1c;
P_0c03ac1c: /* original 1e21, guest PC 0x0c03ac1c */
if(!s->budget--) { s->failed_pc=0x0c03ac1cu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c03ac1e;
P_0c03ac1e: /* original d398, guest PC 0x0c03ac1e */
if(!s->budget--) { s->failed_pc=0x0c03ac1eu; return 0; }
r[3]=read(ram,0x0c03ae80u,4);
goto P_0c03ac20;
P_0c03ac20: /* original bf9e, guest PC 0x0c03ac20 */
if(!s->budget--) { s->failed_pc=0x0c03ac20u; return 0; }
target=0x0c03ab60u; r[16]=0x0c03ac24u;
write(ram,r[14]+8,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ac24u) { target=s->pc; goto dispatch; }
goto P_0c03ac24;
P_0c03ac22: /* original 1e32, guest PC 0x0c03ac22 */
if(!s->budget--) { s->failed_pc=0x0c03ac22u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c03ac24;
P_0c03ac24: /* original 4f26, guest PC 0x0c03ac24 */
if(!s->budget--) { s->failed_pc=0x0c03ac24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03ac26;
P_0c03ac26: /* original e300, guest PC 0x0c03ac26 */
if(!s->budget--) { s->failed_pc=0x0c03ac26u; return 0; }
r[3]=0x00000000u;
goto P_0c03ac28;
P_0c03ac28: /* original e1ff, guest PC 0x0c03ac28 */
if(!s->budget--) { s->failed_pc=0x0c03ac28u; return 0; }
r[1]=0xffffffffu;
goto P_0c03ac2a;
P_0c03ac2a: /* original 1e14, guest PC 0x0c03ac2a */
if(!s->budget--) { s->failed_pc=0x0c03ac2au; return 0; }
write(ram,r[14]+16,r[1],4);
goto P_0c03ac2c;
P_0c03ac2c: /* original 1e35, guest PC 0x0c03ac2c */
if(!s->budget--) { s->failed_pc=0x0c03ac2cu; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c03ac2e;
P_0c03ac2e: /* original 000b, guest PC 0x0c03ac2e */
if(!s->budget--) { s->failed_pc=0x0c03ac2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03ac30: /* original 6ef6, guest PC 0x0c03ac30 */
if(!s->budget--) { s->failed_pc=0x0c03ac30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03ac32u,s,ram);
P_0c03b410: /* original f449, guest PC 0x0c03b410 */
if(!s->budget--) { s->failed_pc=0x0c03b410u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03b412;
P_0c03b412: /* original f549, guest PC 0x0c03b412 */
if(!s->budget--) { s->failed_pc=0x0c03b412u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03b414;
P_0c03b414: /* original f649, guest PC 0x0c03b414 */
if(!s->budget--) { s->failed_pc=0x0c03b414u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03b416;
P_0c03b416: /* original f79d, guest PC 0x0c03b416 */
if(!s->budget--) { s->failed_pc=0x0c03b416u; return 0; }
fr[7]=0x3f800000u;
goto P_0c03b418;
P_0c03b418: /* original f5fd, guest PC 0x0c03b418 */
if(!s->budget--) { s->failed_pc=0x0c03b418u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03b41a;
P_0c03b41a: /* original 7510, guest PC 0x0c03b41a */
if(!s->budget--) { s->failed_pc=0x0c03b41au; return 0; }
r[5]+=0x00000010u;
goto P_0c03b41c;
P_0c03b41c: /* original f57b, guest PC 0x0c03b41c */
if(!s->budget--) { s->failed_pc=0x0c03b41cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c03b41e;
P_0c03b41e: /* original f56b, guest PC 0x0c03b41e */
if(!s->budget--) { s->failed_pc=0x0c03b41eu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c03b420;
P_0c03b420: /* original f55b, guest PC 0x0c03b420 */
if(!s->budget--) { s->failed_pc=0x0c03b420u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c03b422;
P_0c03b422: /* original f54b, guest PC 0x0c03b422 */
if(!s->budget--) { s->failed_pc=0x0c03b422u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c03b424;
P_0c03b424: /* original 000b, guest PC 0x0c03b424 */
if(!s->budget--) { s->failed_pc=0x0c03b424u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03b426: /* original 0009, guest PC 0x0c03b426 */
if(!s->budget--) { s->failed_pc=0x0c03b426u; return 0; }
return vf3_matrix_family(0x0c03b428u,s,ram);
P_0c03b874: /* original 4f22, guest PC 0x0c03b874 */
if(!s->budget--) { s->failed_pc=0x0c03b874u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b876;
P_0c03b876: /* original 7ff4, guest PC 0x0c03b876 */
if(!s->budget--) { s->failed_pc=0x0c03b876u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c03b878;
P_0c03b878: /* original 2f42, guest PC 0x0c03b878 */
if(!s->budget--) { s->failed_pc=0x0c03b878u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03b87a;
P_0c03b87a: /* original 1f51, guest PC 0x0c03b87a */
if(!s->budget--) { s->failed_pc=0x0c03b87au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c03b87c;
P_0c03b87c: /* original de11, guest PC 0x0c03b87c */
if(!s->budget--) { s->failed_pc=0x0c03b87cu; return 0; }
r[14]=read(ram,0x0c03b8c4u,4);
goto P_0c03b87e;
P_0c03b87e: /* original d512, guest PC 0x0c03b87e */
if(!s->budget--) { s->failed_pc=0x0c03b87eu; return 0; }
r[5]=read(ram,0x0c03b8c8u,4);
goto P_0c03b880;
P_0c03b880: /* original 64e3, guest PC 0x0c03b880 */
if(!s->budget--) { s->failed_pc=0x0c03b880u; return 0; }
r[4]=r[14];
goto P_0c03b882;
P_0c03b882: /* original bfd5, guest PC 0x0c03b882 */
if(!s->budget--) { s->failed_pc=0x0c03b882u; return 0; }
target=0x0c03b830u; r[16]=0x0c03b886u;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b886u) { target=s->pc; goto dispatch; }
goto P_0c03b886;
P_0c03b884: /* original 7418, guest PC 0x0c03b884 */
if(!s->budget--) { s->failed_pc=0x0c03b884u; return 0; }
r[4]+=0x00000018u;
goto P_0c03b886;
P_0c03b886: /* original d511, guest PC 0x0c03b886 */
if(!s->budget--) { s->failed_pc=0x0c03b886u; return 0; }
r[5]=read(ram,0x0c03b8ccu,4);
goto P_0c03b888;
P_0c03b888: /* original 64e3, guest PC 0x0c03b888 */
if(!s->budget--) { s->failed_pc=0x0c03b888u; return 0; }
r[4]=r[14];
goto P_0c03b88a;
P_0c03b88a: /* original e603, guest PC 0x0c03b88a */
if(!s->budget--) { s->failed_pc=0x0c03b88au; return 0; }
r[6]=0x00000003u;
goto P_0c03b88c;
P_0c03b88c: /* original bfd0, guest PC 0x0c03b88c */
if(!s->budget--) { s->failed_pc=0x0c03b88cu; return 0; }
target=0x0c03b830u; r[16]=0x0c03b890u;
r[4]+=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b890u) { target=s->pc; goto dispatch; }
goto P_0c03b890;
P_0c03b88e: /* original 7424, guest PC 0x0c03b88e */
if(!s->budget--) { s->failed_pc=0x0c03b88eu; return 0; }
r[4]+=0x00000024u;
goto P_0c03b890;
P_0c03b890: /* original 56f1, guest PC 0x0c03b890 */
if(!s->budget--) { s->failed_pc=0x0c03b890u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c03b892;
P_0c03b892: /* original 64e3, guest PC 0x0c03b892 */
if(!s->budget--) { s->failed_pc=0x0c03b892u; return 0; }
r[4]=r[14];
goto P_0c03b894;
P_0c03b894: /* original 65f2, guest PC 0x0c03b894 */
if(!s->budget--) { s->failed_pc=0x0c03b894u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03b896;
P_0c03b896: /* original 740c, guest PC 0x0c03b896 */
if(!s->budget--) { s->failed_pc=0x0c03b896u; return 0; }
r[4]+=0x0000000cu;
goto P_0c03b898;
P_0c03b898: /* original 7601, guest PC 0x0c03b898 */
if(!s->budget--) { s->failed_pc=0x0c03b898u; return 0; }
r[6]+=0x00000001u;
goto P_0c03b89a;
P_0c03b89a: /* original bfc9, guest PC 0x0c03b89a */
if(!s->budget--) { s->failed_pc=0x0c03b89au; return 0; }
target=0x0c03b830u; r[16]=0x0c03b89eu;
write(ram,r[15]+8,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b89eu) { target=s->pc; goto dispatch; }
goto P_0c03b89e;
P_0c03b89c: /* original 1f42, guest PC 0x0c03b89c */
if(!s->budget--) { s->failed_pc=0x0c03b89cu; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c03b89e;
P_0c03b89e: /* original d30c, guest PC 0x0c03b89e */
if(!s->budget--) { s->failed_pc=0x0c03b89eu; return 0; }
r[3]=read(ram,0x0c03b8d0u,4);
goto P_0c03b8a0;
P_0c03b8a0: /* original e201, guest PC 0x0c03b8a0 */
if(!s->budget--) { s->failed_pc=0x0c03b8a0u; return 0; }
r[2]=0x00000001u;
goto P_0c03b8a2;
P_0c03b8a2: /* original 6403, guest PC 0x0c03b8a2 */
if(!s->budget--) { s->failed_pc=0x0c03b8a2u; return 0; }
r[4]=r[0];
goto P_0c03b8a4;
P_0c03b8a4: /* original 61e3, guest PC 0x0c03b8a4 */
if(!s->budget--) { s->failed_pc=0x0c03b8a4u; return 0; }
r[1]=r[14];
goto P_0c03b8a6;
P_0c03b8a6: /* original 2320, guest PC 0x0c03b8a6 */
if(!s->budget--) { s->failed_pc=0x0c03b8a6u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c03b8a8;
P_0c03b8a8: /* original d30a, guest PC 0x0c03b8a8 */
if(!s->budget--) { s->failed_pc=0x0c03b8a8u; return 0; }
r[3]=read(ram,0x0c03b8d4u,4);
goto P_0c03b8aa;
P_0c03b8aa: /* original 52f2, guest PC 0x0c03b8aa */
if(!s->budget--) { s->failed_pc=0x0c03b8aau; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c03b8ac;
P_0c03b8ac: /* original 430b, guest PC 0x0c03b8ac */
if(!s->budget--) { s->failed_pc=0x0c03b8acu; return 0; }
target=r[3];
r[16]=0x0c03b8b0u;
r[0]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b8b0u) { target=s->pc; goto dispatch; }
goto P_0c03b8b0;
P_0c03b8ae: /* original e00c, guest PC 0x0c03b8ae */
if(!s->budget--) { s->failed_pc=0x0c03b8aeu; return 0; }
r[0]=0x0000000cu;
goto P_0c03b8b0;
P_0c03b8b0: /* original 7f0c, guest PC 0x0c03b8b0 */
if(!s->budget--) { s->failed_pc=0x0c03b8b0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c03b8b2;
P_0c03b8b2: /* original 6043, guest PC 0x0c03b8b2 */
if(!s->budget--) { s->failed_pc=0x0c03b8b2u; return 0; }
r[0]=r[4];
goto P_0c03b8b4;
P_0c03b8b4: /* original 4f26, guest PC 0x0c03b8b4 */
if(!s->budget--) { s->failed_pc=0x0c03b8b4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b8b6;
P_0c03b8b6: /* original 000b, guest PC 0x0c03b8b6 */
if(!s->budget--) { s->failed_pc=0x0c03b8b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b8b8: /* original 6ef6, guest PC 0x0c03b8b8 */
if(!s->budget--) { s->failed_pc=0x0c03b8b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03b8bau,s,ram);
P_0c03c580: /* original 4f22, guest PC 0x0c03c580 */
if(!s->budget--) { s->failed_pc=0x0c03c580u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03c582;
P_0c03c582: /* original d306, guest PC 0x0c03c582 */
if(!s->budget--) { s->failed_pc=0x0c03c582u; return 0; }
r[3]=read(ram,0x0c03c59cu,4);
goto P_0c03c584;
P_0c03c584: /* original 7ffc, guest PC 0x0c03c584 */
if(!s->budget--) { s->failed_pc=0x0c03c584u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03c586;
P_0c03c586: /* original 430b, guest PC 0x0c03c586 */
if(!s->budget--) { s->failed_pc=0x0c03c586u; return 0; }
target=r[3];
r[16]=0x0c03c58au;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c58au) { target=s->pc; goto dispatch; }
goto P_0c03c58a;
P_0c03c588: /* original e400, guest PC 0x0c03c588 */
if(!s->budget--) { s->failed_pc=0x0c03c588u; return 0; }
r[4]=0x00000000u;
goto P_0c03c58a;
P_0c03c58a: /* original d305, guest PC 0x0c03c58a */
if(!s->budget--) { s->failed_pc=0x0c03c58au; return 0; }
r[3]=read(ram,0x0c03c5a0u,4);
goto P_0c03c58c;
P_0c03c58c: /* original 430b, guest PC 0x0c03c58c */
if(!s->budget--) { s->failed_pc=0x0c03c58cu; return 0; }
target=r[3];
r[16]=0x0c03c590u;
write(ram,r[15],r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c590u) { target=s->pc; goto dispatch; }
goto P_0c03c590;
P_0c03c58e: /* original 2f02, guest PC 0x0c03c58e */
if(!s->budget--) { s->failed_pc=0x0c03c58eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c03c590;
P_0c03c590: /* original 60f2, guest PC 0x0c03c590 */
if(!s->budget--) { s->failed_pc=0x0c03c590u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03c592;
P_0c03c592: /* original 7f04, guest PC 0x0c03c592 */
if(!s->budget--) { s->failed_pc=0x0c03c592u; return 0; }
r[15]+=0x00000004u;
goto P_0c03c594;
P_0c03c594: /* original 4f26, guest PC 0x0c03c594 */
if(!s->budget--) { s->failed_pc=0x0c03c594u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03c596;
P_0c03c596: /* original 000b, guest PC 0x0c03c596 */
if(!s->budget--) { s->failed_pc=0x0c03c596u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c598: /* original 0009, guest PC 0x0c03c598 */
if(!s->budget--) { s->failed_pc=0x0c03c598u; return 0; }
return vf3_matrix_family(0x0c03c59au,s,ram);
P_0c03dcc4: /* original 4f22, guest PC 0x0c03dcc4 */
if(!s->budget--) { s->failed_pc=0x0c03dcc4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03dcc6;
P_0c03dcc6: /* original d315, guest PC 0x0c03dcc6 */
if(!s->budget--) { s->failed_pc=0x0c03dcc6u; return 0; }
r[3]=read(ram,0x0c03dd1cu,4);
goto P_0c03dcc8;
P_0c03dcc8: /* original 7ff0, guest PC 0x0c03dcc8 */
if(!s->budget--) { s->failed_pc=0x0c03dcc8u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03dcca;
P_0c03dcca: /* original 430b, guest PC 0x0c03dcca */
if(!s->budget--) { s->failed_pc=0x0c03dccau; return 0; }
target=r[3];
r[16]=0x0c03dcceu;
r[5]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03dcceu) { target=s->pc; goto dispatch; }
goto P_0c03dcce;
P_0c03dccc: /* original 65f3, guest PC 0x0c03dccc */
if(!s->budget--) { s->failed_pc=0x0c03dcccu; return 0; }
r[5]=r[15];
goto P_0c03dcce;
P_0c03dcce: /* original e00c, guest PC 0x0c03dcce */
if(!s->budget--) { s->failed_pc=0x0c03dcceu; return 0; }
r[0]=0x0000000cu;
goto P_0c03dcd0;
P_0c03dcd0: /* original f49d, guest PC 0x0c03dcd0 */
if(!s->budget--) { s->failed_pc=0x0c03dcd0u; return 0; }
fr[4]=0x3f800000u;
goto P_0c03dcd2;
P_0c03dcd2: /* original f3f6, guest PC 0x0c03dcd2 */
if(!s->budget--) { s->failed_pc=0x0c03dcd2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03dcd4;
P_0c03dcd4: /* original e004, guest PC 0x0c03dcd4 */
if(!s->budget--) { s->failed_pc=0x0c03dcd4u; return 0; }
r[0]=0x00000004u;
goto P_0c03dcd6;
P_0c03dcd6: /* original f433, guest PC 0x0c03dcd6 */
if(!s->budget--) { s->failed_pc=0x0c03dcd6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03dcd8;
P_0c03dcd8: /* original f3f8, guest PC 0x0c03dcd8 */
if(!s->budget--) { s->failed_pc=0x0c03dcd8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c03dcda;
P_0c03dcda: /* original f342, guest PC 0x0c03dcda */
if(!s->budget--) { s->failed_pc=0x0c03dcdau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03dcdc;
P_0c03dcdc: /* original fe3a, guest PC 0x0c03dcdc */
if(!s->budget--) { s->failed_pc=0x0c03dcdcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c03dcde;
P_0c03dcde: /* original f3f6, guest PC 0x0c03dcde */
if(!s->budget--) { s->failed_pc=0x0c03dcdeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03dce0;
P_0c03dce0: /* original 7f10, guest PC 0x0c03dce0 */
if(!s->budget--) { s->failed_pc=0x0c03dce0u; return 0; }
r[15]+=0x00000010u;
goto P_0c03dce2;
P_0c03dce2: /* original e004, guest PC 0x0c03dce2 */
if(!s->budget--) { s->failed_pc=0x0c03dce2u; return 0; }
r[0]=0x00000004u;
goto P_0c03dce4;
P_0c03dce4: /* original f342, guest PC 0x0c03dce4 */
if(!s->budget--) { s->failed_pc=0x0c03dce4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03dce6;
P_0c03dce6: /* original 4f26, guest PC 0x0c03dce6 */
if(!s->budget--) { s->failed_pc=0x0c03dce6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03dce8;
P_0c03dce8: /* original fe37, guest PC 0x0c03dce8 */
if(!s->budget--) { s->failed_pc=0x0c03dce8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03dcea;
P_0c03dcea: /* original e008, guest PC 0x0c03dcea */
if(!s->budget--) { s->failed_pc=0x0c03dceau; return 0; }
r[0]=0x00000008u;
goto P_0c03dcec;
P_0c03dcec: /* original fe47, guest PC 0x0c03dcec */
if(!s->budget--) { s->failed_pc=0x0c03dcecu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c03dcee;
P_0c03dcee: /* original 000b, guest PC 0x0c03dcee */
if(!s->budget--) { s->failed_pc=0x0c03dceeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03dcf0: /* original 6ef6, guest PC 0x0c03dcf0 */
if(!s->budget--) { s->failed_pc=0x0c03dcf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03dcf2u,s,ram);
P_0c03e760: /* original 9393, guest PC 0x0c03e760 */
if(!s->budget--) { s->failed_pc=0x0c03e760u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e88au,2);
goto P_0c03e762;
P_0c03e762: /* original 4f12, guest PC 0x0c03e762 */
if(!s->budget--) { s->failed_pc=0x0c03e762u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e764;
P_0c03e764: /* original 243f, guest PC 0x0c03e764 */
if(!s->budget--) { s->failed_pc=0x0c03e764u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c03e766;
P_0c03e766: /* original d24a, guest PC 0x0c03e766 */
if(!s->budget--) { s->failed_pc=0x0c03e766u; return 0; }
r[2]=read(ram,0x0c03e890u,4);
goto P_0c03e768;
P_0c03e768: /* original 9090, guest PC 0x0c03e768 */
if(!s->budget--) { s->failed_pc=0x0c03e768u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e88cu,2);
goto P_0c03e76a;
P_0c03e76a: /* original 041a, guest PC 0x0c03e76a */
if(!s->budget--) { s->failed_pc=0x0c03e76au; return 0; }
r[4]=r[19];
goto P_0c03e76c;
P_0c03e76c: /* original 644f, guest PC 0x0c03e76c */
if(!s->budget--) { s->failed_pc=0x0c03e76cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c03e76e;
P_0c03e76e: /* original 342c, guest PC 0x0c03e76e */
if(!s->budget--) { s->failed_pc=0x0c03e76eu; return 0; }
r[4]+=r[2];
goto P_0c03e770;
P_0c03e770: /* original f447, guest PC 0x0c03e770 */
if(!s->budget--) { s->failed_pc=0x0c03e770u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03e772;
P_0c03e772: /* original e058, guest PC 0x0c03e772 */
if(!s->budget--) { s->failed_pc=0x0c03e772u; return 0; }
r[0]=0x00000058u;
goto P_0c03e774;
P_0c03e774: /* original f457, guest PC 0x0c03e774 */
if(!s->budget--) { s->failed_pc=0x0c03e774u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c03e776;
P_0c03e776: /* original 7044, guest PC 0x0c03e776 */
if(!s->budget--) { s->failed_pc=0x0c03e776u; return 0; }
r[0]+=0x00000044u;
goto P_0c03e778;
P_0c03e778: /* original f49d, guest PC 0x0c03e778 */
if(!s->budget--) { s->failed_pc=0x0c03e778u; return 0; }
fr[4]=0x3f800000u;
goto P_0c03e77a;
P_0c03e77a: /* original f34c, guest PC 0x0c03e77a */
if(!s->budget--) { s->failed_pc=0x0c03e77au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03e77c;
P_0c03e77c: /* original f351, guest PC 0x0c03e77c */
if(!s->budget--) { s->failed_pc=0x0c03e77cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03e77e;
P_0c03e77e: /* original f24c, guest PC 0x0c03e77e */
if(!s->budget--) { s->failed_pc=0x0c03e77eu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03e780;
P_0c03e780: /* original f233, guest PC 0x0c03e780 */
if(!s->budget--) { s->failed_pc=0x0c03e780u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c03e782;
P_0c03e782: /* original f427, guest PC 0x0c03e782 */
if(!s->budget--) { s->failed_pc=0x0c03e782u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03e784;
P_0c03e784: /* original 000b, guest PC 0x0c03e784 */
if(!s->budget--) { s->failed_pc=0x0c03e784u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c03e786: /* original 4f16, guest PC 0x0c03e786 */
if(!s->budget--) { s->failed_pc=0x0c03e786u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03e788u,s,ram);
P_0c03e790: /* original 4f22, guest PC 0x0c03e790 */
if(!s->budget--) { s->failed_pc=0x0c03e790u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e792;
P_0c03e792: /* original 7ff8, guest PC 0x0c03e792 */
if(!s->budget--) { s->failed_pc=0x0c03e792u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03e794;
P_0c03e794: /* original 1f41, guest PC 0x0c03e794 */
if(!s->budget--) { s->failed_pc=0x0c03e794u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03e796;
P_0c03e796: /* original 2f52, guest PC 0x0c03e796 */
if(!s->budget--) { s->failed_pc=0x0c03e796u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03e798;
P_0c03e798: /* original d33e, guest PC 0x0c03e798 */
if(!s->budget--) { s->failed_pc=0x0c03e798u; return 0; }
r[3]=read(ram,0x0c03e894u,4);
goto P_0c03e79a;
P_0c03e79a: /* original 430b, guest PC 0x0c03e79a */
if(!s->budget--) { s->failed_pc=0x0c03e79au; return 0; }
target=r[3];
r[16]=0x0c03e79eu;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e79eu) { target=s->pc; goto dispatch; }
goto P_0c03e79e;
P_0c03e79c: /* original 6453, guest PC 0x0c03e79c */
if(!s->budget--) { s->failed_pc=0x0c03e79cu; return 0; }
r[4]=r[5];
goto P_0c03e79e;
P_0c03e79e: /* original ff0b, guest PC 0x0c03e79e */
if(!s->budget--) { s->failed_pc=0x0c03e79eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03e7a0;
P_0c03e7a0: /* original d33d, guest PC 0x0c03e7a0 */
if(!s->budget--) { s->failed_pc=0x0c03e7a0u; return 0; }
r[3]=read(ram,0x0c03e898u,4);
goto P_0c03e7a2;
P_0c03e7a2: /* original 430b, guest PC 0x0c03e7a2 */
if(!s->budget--) { s->failed_pc=0x0c03e7a2u; return 0; }
target=r[3];
r[16]=0x0c03e7a6u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e7a6u) { target=s->pc; goto dispatch; }
goto P_0c03e7a6;
P_0c03e7a4: /* original 54f1, guest PC 0x0c03e7a4 */
if(!s->budget--) { s->failed_pc=0x0c03e7a4u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c03e7a6;
P_0c03e7a6: /* original 54f2, guest PC 0x0c03e7a6 */
if(!s->budget--) { s->failed_pc=0x0c03e7a6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c03e7a8;
P_0c03e7a8: /* original f5f9, guest PC 0x0c03e7a8 */
if(!s->budget--) { s->failed_pc=0x0c03e7a8u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03e7aa;
P_0c03e7aa: /* original f40c, guest PC 0x0c03e7aa */
if(!s->budget--) { s->failed_pc=0x0c03e7aau; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03e7ac;
P_0c03e7ac: /* original 7f08, guest PC 0x0c03e7ac */
if(!s->budget--) { s->failed_pc=0x0c03e7acu; return 0; }
r[15]+=0x00000008u;
goto P_0c03e7ae;
P_0c03e7ae: /* original afd7, guest PC 0x0c03e7ae */
if(!s->budget--) { s->failed_pc=0x0c03e7aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e760;
P_0c03e7b0: /* original 4f26, guest PC 0x0c03e7b0 */
if(!s->budget--) { s->failed_pc=0x0c03e7b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03e7b2u,s,ram);
P_0c043064: /* original 4f22, guest PC 0x0c043064 */
if(!s->budget--) { s->failed_pc=0x0c043064u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043066;
P_0c043066: /* original 6363, guest PC 0x0c043066 */
if(!s->budget--) { s->failed_pc=0x0c043066u; return 0; }
r[3]=r[6];
goto P_0c043068;
P_0c043068: /* original d307, guest PC 0x0c043068 */
if(!s->budget--) { s->failed_pc=0x0c043068u; return 0; }
r[3]=read(ram,0x0c043088u,4);
goto P_0c04306a;
P_0c04306a: /* original 7ff4, guest PC 0x0c04306a */
if(!s->budget--) { s->failed_pc=0x0c04306au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c04306c;
P_0c04306c: /* original 2f42, guest PC 0x0c04306c */
if(!s->budget--) { s->failed_pc=0x0c04306cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04306e;
P_0c04306e: /* original 1f51, guest PC 0x0c04306e */
if(!s->budget--) { s->failed_pc=0x0c04306eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c043070;
P_0c043070: /* original 1f62, guest PC 0x0c043070 */
if(!s->budget--) { s->failed_pc=0x0c043070u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c043072;
P_0c043072: /* original e500, guest PC 0x0c043072 */
if(!s->budget--) { s->failed_pc=0x0c043072u; return 0; }
r[5]=0x00000000u;
goto P_0c043074;
P_0c043074: /* original 2f66, guest PC 0x0c043074 */
if(!s->budget--) { s->failed_pc=0x0c043074u; return 0; }
r[15]-=4; write(ram,r[15],r[6],4);
goto P_0c043076;
P_0c043076: /* original 57f2, guest PC 0x0c043076 */
if(!s->budget--) { s->failed_pc=0x0c043076u; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c043078;
P_0c043078: /* original 56f1, guest PC 0x0c043078 */
if(!s->budget--) { s->failed_pc=0x0c043078u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c04307a;
P_0c04307a: /* original 430b, guest PC 0x0c04307a */
if(!s->budget--) { s->failed_pc=0x0c04307au; return 0; }
target=r[3];
r[16]=0x0c04307eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04307eu) { target=s->pc; goto dispatch; }
goto P_0c04307e;
P_0c04307c: /* original e401, guest PC 0x0c04307c */
if(!s->budget--) { s->failed_pc=0x0c04307cu; return 0; }
r[4]=0x00000001u;
goto P_0c04307e;
P_0c04307e: /* original 7f10, guest PC 0x0c04307e */
if(!s->budget--) { s->failed_pc=0x0c04307eu; return 0; }
r[15]+=0x00000010u;
goto P_0c043080;
P_0c043080: /* original 4f26, guest PC 0x0c043080 */
if(!s->budget--) { s->failed_pc=0x0c043080u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043082;
P_0c043082: /* original 000b, guest PC 0x0c043082 */
if(!s->budget--) { s->failed_pc=0x0c043082u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043084: /* original 0009, guest PC 0x0c043084 */
if(!s->budget--) { s->failed_pc=0x0c043084u; return 0; }
return vf3_matrix_family(0x0c043086u,s,ram);
P_0c04326c: /* original 4f22, guest PC 0x0c04326c */
if(!s->budget--) { s->failed_pc=0x0c04326cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04326e;
P_0c04326e: /* original 7ff8, guest PC 0x0c04326e */
if(!s->budget--) { s->failed_pc=0x0c04326eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043270;
P_0c043270: /* original 6ef3, guest PC 0x0c043270 */
if(!s->budget--) { s->failed_pc=0x0c043270u; return 0; }
r[14]=r[15];
goto P_0c043272;
P_0c043272: /* original 2e42, guest PC 0x0c043272 */
if(!s->budget--) { s->failed_pc=0x0c043272u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043274;
P_0c043274: /* original 1e51, guest PC 0x0c043274 */
if(!s->budget--) { s->failed_pc=0x0c043274u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c043276;
P_0c043276: /* original 65e3, guest PC 0x0c043276 */
if(!s->budget--) { s->failed_pc=0x0c043276u; return 0; }
r[5]=r[14];
goto P_0c043278;
P_0c043278: /* original d32e, guest PC 0x0c043278 */
if(!s->budget--) { s->failed_pc=0x0c043278u; return 0; }
r[3]=read(ram,0x0c043334u,4);
goto P_0c04327a;
P_0c04327a: /* original 430b, guest PC 0x0c04327a */
if(!s->budget--) { s->failed_pc=0x0c04327au; return 0; }
target=r[3];
r[16]=0x0c04327eu;
r[4]=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04327eu) { target=s->pc; goto dispatch; }
goto P_0c04327e;
P_0c04327c: /* original e41c, guest PC 0x0c04327c */
if(!s->budget--) { s->failed_pc=0x0c04327cu; return 0; }
r[4]=0x0000001cu;
goto P_0c04327e;
P_0c04327e: /* original 7f08, guest PC 0x0c04327e */
if(!s->budget--) { s->failed_pc=0x0c04327eu; return 0; }
r[15]+=0x00000008u;
goto P_0c043280;
P_0c043280: /* original 4f26, guest PC 0x0c043280 */
if(!s->budget--) { s->failed_pc=0x0c043280u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043282;
P_0c043282: /* original 000b, guest PC 0x0c043282 */
if(!s->budget--) { s->failed_pc=0x0c043282u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043284: /* original 6ef6, guest PC 0x0c043284 */
if(!s->budget--) { s->failed_pc=0x0c043284u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c043286u,s,ram);
P_0c0433c6: /* original 4f22, guest PC 0x0c0433c6 */
if(!s->budget--) { s->failed_pc=0x0c0433c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0433c8;
P_0c0433c8: /* original 7ff8, guest PC 0x0c0433c8 */
if(!s->budget--) { s->failed_pc=0x0c0433c8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0433ca;
P_0c0433ca: /* original 6ef3, guest PC 0x0c0433ca */
if(!s->budget--) { s->failed_pc=0x0c0433cau; return 0; }
r[14]=r[15];
goto P_0c0433cc;
P_0c0433cc: /* original 65e3, guest PC 0x0c0433cc */
if(!s->budget--) { s->failed_pc=0x0c0433ccu; return 0; }
r[5]=r[14];
goto P_0c0433ce;
P_0c0433ce: /* original 2e42, guest PC 0x0c0433ce */
if(!s->budget--) { s->failed_pc=0x0c0433ceu; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0433d0;
P_0c0433d0: /* original 1e31, guest PC 0x0c0433d0 */
if(!s->budget--) { s->failed_pc=0x0c0433d0u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0433d2;
P_0c0433d2: /* original d245, guest PC 0x0c0433d2 */
if(!s->budget--) { s->failed_pc=0x0c0433d2u; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c0433d4;
P_0c0433d4: /* original 420b, guest PC 0x0c0433d4 */
if(!s->budget--) { s->failed_pc=0x0c0433d4u; return 0; }
target=r[2];
r[16]=0x0c0433d8u;
r[4]=0x0000001bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0433d8u) { target=s->pc; goto dispatch; }
goto P_0c0433d8;
P_0c0433d6: /* original e41b, guest PC 0x0c0433d6 */
if(!s->budget--) { s->failed_pc=0x0c0433d6u; return 0; }
r[4]=0x0000001bu;
goto P_0c0433d8;
P_0c0433d8: /* original 7f08, guest PC 0x0c0433d8 */
if(!s->budget--) { s->failed_pc=0x0c0433d8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0433da;
P_0c0433da: /* original 4f26, guest PC 0x0c0433da */
if(!s->budget--) { s->failed_pc=0x0c0433dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0433dc;
P_0c0433dc: /* original 000b, guest PC 0x0c0433dc */
if(!s->budget--) { s->failed_pc=0x0c0433dcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0433de: /* original 6ef6, guest PC 0x0c0433de */
if(!s->budget--) { s->failed_pc=0x0c0433deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0433e0u,s,ram);
P_0c04341e: /* original 4f22, guest PC 0x0c04341e */
if(!s->budget--) { s->failed_pc=0x0c04341eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043420;
P_0c043420: /* original 7ff0, guest PC 0x0c043420 */
if(!s->budget--) { s->failed_pc=0x0c043420u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c043422;
P_0c043422: /* original 6ef3, guest PC 0x0c043422 */
if(!s->budget--) { s->failed_pc=0x0c043422u; return 0; }
r[14]=r[15];
goto P_0c043424;
P_0c043424: /* original 2e42, guest PC 0x0c043424 */
if(!s->budget--) { s->failed_pc=0x0c043424u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043426;
P_0c043426: /* original 1e51, guest PC 0x0c043426 */
if(!s->budget--) { s->failed_pc=0x0c043426u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c043428;
P_0c043428: /* original 65e3, guest PC 0x0c043428 */
if(!s->budget--) { s->failed_pc=0x0c043428u; return 0; }
r[5]=r[14];
goto P_0c04342a;
P_0c04342a: /* original 1e62, guest PC 0x0c04342a */
if(!s->budget--) { s->failed_pc=0x0c04342au; return 0; }
write(ram,r[14]+8,r[6],4);
goto P_0c04342c;
P_0c04342c: /* original 1e33, guest PC 0x0c04342c */
if(!s->budget--) { s->failed_pc=0x0c04342cu; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c04342e;
P_0c04342e: /* original d22e, guest PC 0x0c04342e */
if(!s->budget--) { s->failed_pc=0x0c04342eu; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c043430;
P_0c043430: /* original 420b, guest PC 0x0c043430 */
if(!s->budget--) { s->failed_pc=0x0c043430u; return 0; }
target=r[2];
r[16]=0x0c043434u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043434u) { target=s->pc; goto dispatch; }
goto P_0c043434;
P_0c043432: /* original e414, guest PC 0x0c043432 */
if(!s->budget--) { s->failed_pc=0x0c043432u; return 0; }
r[4]=0x00000014u;
goto P_0c043434;
P_0c043434: /* original 7f10, guest PC 0x0c043434 */
if(!s->budget--) { s->failed_pc=0x0c043434u; return 0; }
r[15]+=0x00000010u;
goto P_0c043436;
P_0c043436: /* original 4f26, guest PC 0x0c043436 */
if(!s->budget--) { s->failed_pc=0x0c043436u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043438;
P_0c043438: /* original 000b, guest PC 0x0c043438 */
if(!s->budget--) { s->failed_pc=0x0c043438u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04343a: /* original 6ef6, guest PC 0x0c04343a */
if(!s->budget--) { s->failed_pc=0x0c04343au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04343cu,s,ram);
P_0c043440: /* original 4f22, guest PC 0x0c043440 */
if(!s->budget--) { s->failed_pc=0x0c043440u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043442;
P_0c043442: /* original 7ff0, guest PC 0x0c043442 */
if(!s->budget--) { s->failed_pc=0x0c043442u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c043444;
P_0c043444: /* original 6ef3, guest PC 0x0c043444 */
if(!s->budget--) { s->failed_pc=0x0c043444u; return 0; }
r[14]=r[15];
goto P_0c043446;
P_0c043446: /* original 2e42, guest PC 0x0c043446 */
if(!s->budget--) { s->failed_pc=0x0c043446u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043448;
P_0c043448: /* original 1e51, guest PC 0x0c043448 */
if(!s->budget--) { s->failed_pc=0x0c043448u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c04344a;
P_0c04344a: /* original 65e3, guest PC 0x0c04344a */
if(!s->budget--) { s->failed_pc=0x0c04344au; return 0; }
r[5]=r[14];
goto P_0c04344c;
P_0c04344c: /* original 1e62, guest PC 0x0c04344c */
if(!s->budget--) { s->failed_pc=0x0c04344cu; return 0; }
write(ram,r[14]+8,r[6],4);
goto P_0c04344e;
P_0c04344e: /* original 1e33, guest PC 0x0c04344e */
if(!s->budget--) { s->failed_pc=0x0c04344eu; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c043450;
P_0c043450: /* original d225, guest PC 0x0c043450 */
if(!s->budget--) { s->failed_pc=0x0c043450u; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c043452;
P_0c043452: /* original 420b, guest PC 0x0c043452 */
if(!s->budget--) { s->failed_pc=0x0c043452u; return 0; }
target=r[2];
r[16]=0x0c043456u;
r[4]=0x00000015u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043456u) { target=s->pc; goto dispatch; }
goto P_0c043456;
P_0c043454: /* original e415, guest PC 0x0c043454 */
if(!s->budget--) { s->failed_pc=0x0c043454u; return 0; }
r[4]=0x00000015u;
goto P_0c043456;
P_0c043456: /* original 7f10, guest PC 0x0c043456 */
if(!s->budget--) { s->failed_pc=0x0c043456u; return 0; }
r[15]+=0x00000010u;
goto P_0c043458;
P_0c043458: /* original 4f26, guest PC 0x0c043458 */
if(!s->budget--) { s->failed_pc=0x0c043458u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04345a;
P_0c04345a: /* original 000b, guest PC 0x0c04345a */
if(!s->budget--) { s->failed_pc=0x0c04345au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04345c: /* original 6ef6, guest PC 0x0c04345c */
if(!s->budget--) { s->failed_pc=0x0c04345cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04345eu,s,ram);
P_0c043472: /* original 4f22, guest PC 0x0c043472 */
if(!s->budget--) { s->failed_pc=0x0c043472u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043474;
P_0c043474: /* original 7ff8, guest PC 0x0c043474 */
if(!s->budget--) { s->failed_pc=0x0c043474u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043476;
P_0c043476: /* original 6ef3, guest PC 0x0c043476 */
if(!s->budget--) { s->failed_pc=0x0c043476u; return 0; }
r[14]=r[15];
goto P_0c043478;
P_0c043478: /* original 65e3, guest PC 0x0c043478 */
if(!s->budget--) { s->failed_pc=0x0c043478u; return 0; }
r[5]=r[14];
goto P_0c04347a;
P_0c04347a: /* original 2e42, guest PC 0x0c04347a */
if(!s->budget--) { s->failed_pc=0x0c04347au; return 0; }
write(ram,r[14],r[4],4);
goto P_0c04347c;
P_0c04347c: /* original 1e31, guest PC 0x0c04347c */
if(!s->budget--) { s->failed_pc=0x0c04347cu; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c04347e;
P_0c04347e: /* original d21a, guest PC 0x0c04347e */
if(!s->budget--) { s->failed_pc=0x0c04347eu; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c043480;
P_0c043480: /* original 420b, guest PC 0x0c043480 */
if(!s->budget--) { s->failed_pc=0x0c043480u; return 0; }
target=r[2];
r[16]=0x0c043484u;
r[4]=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043484u) { target=s->pc; goto dispatch; }
goto P_0c043484;
P_0c043482: /* original e417, guest PC 0x0c043482 */
if(!s->budget--) { s->failed_pc=0x0c043482u; return 0; }
r[4]=0x00000017u;
goto P_0c043484;
P_0c043484: /* original 7f08, guest PC 0x0c043484 */
if(!s->budget--) { s->failed_pc=0x0c043484u; return 0; }
r[15]+=0x00000008u;
goto P_0c043486;
P_0c043486: /* original 4f26, guest PC 0x0c043486 */
if(!s->budget--) { s->failed_pc=0x0c043486u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043488;
P_0c043488: /* original 000b, guest PC 0x0c043488 */
if(!s->budget--) { s->failed_pc=0x0c043488u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04348a: /* original 6ef6, guest PC 0x0c04348a */
if(!s->budget--) { s->failed_pc=0x0c04348au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04348cu,s,ram);
P_0c04348e: /* original 4f22, guest PC 0x0c04348e */
if(!s->budget--) { s->failed_pc=0x0c04348eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043490;
P_0c043490: /* original 7ff8, guest PC 0x0c043490 */
if(!s->budget--) { s->failed_pc=0x0c043490u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043492;
P_0c043492: /* original 6ef3, guest PC 0x0c043492 */
if(!s->budget--) { s->failed_pc=0x0c043492u; return 0; }
r[14]=r[15];
goto P_0c043494;
P_0c043494: /* original 2e42, guest PC 0x0c043494 */
if(!s->budget--) { s->failed_pc=0x0c043494u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043496;
P_0c043496: /* original 1e51, guest PC 0x0c043496 */
if(!s->budget--) { s->failed_pc=0x0c043496u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c043498;
P_0c043498: /* original 65e3, guest PC 0x0c043498 */
if(!s->budget--) { s->failed_pc=0x0c043498u; return 0; }
r[5]=r[14];
goto P_0c04349a;
P_0c04349a: /* original d313, guest PC 0x0c04349a */
if(!s->budget--) { s->failed_pc=0x0c04349au; return 0; }
r[3]=read(ram,0x0c0434e8u,4);
goto P_0c04349c;
P_0c04349c: /* original 430b, guest PC 0x0c04349c */
if(!s->budget--) { s->failed_pc=0x0c04349cu; return 0; }
target=r[3];
r[16]=0x0c0434a0u;
r[4]=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0434a0u) { target=s->pc; goto dispatch; }
goto P_0c0434a0;
P_0c04349e: /* original e413, guest PC 0x0c04349e */
if(!s->budget--) { s->failed_pc=0x0c04349eu; return 0; }
r[4]=0x00000013u;
goto P_0c0434a0;
P_0c0434a0: /* original 7f08, guest PC 0x0c0434a0 */
if(!s->budget--) { s->failed_pc=0x0c0434a0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0434a2;
P_0c0434a2: /* original 4f26, guest PC 0x0c0434a2 */
if(!s->budget--) { s->failed_pc=0x0c0434a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0434a4;
P_0c0434a4: /* original 000b, guest PC 0x0c0434a4 */
if(!s->budget--) { s->failed_pc=0x0c0434a4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0434a6: /* original 6ef6, guest PC 0x0c0434a6 */
if(!s->budget--) { s->failed_pc=0x0c0434a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0434a8u,s,ram);
P_0c0434aa: /* original 4f22, guest PC 0x0c0434aa */
if(!s->budget--) { s->failed_pc=0x0c0434aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0434ac;
P_0c0434ac: /* original 7ff0, guest PC 0x0c0434ac */
if(!s->budget--) { s->failed_pc=0x0c0434acu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0434ae;
P_0c0434ae: /* original 6ef3, guest PC 0x0c0434ae */
if(!s->budget--) { s->failed_pc=0x0c0434aeu; return 0; }
r[14]=r[15];
goto P_0c0434b0;
P_0c0434b0: /* original 2e42, guest PC 0x0c0434b0 */
if(!s->budget--) { s->failed_pc=0x0c0434b0u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0434b2;
P_0c0434b2: /* original 1e51, guest PC 0x0c0434b2 */
if(!s->budget--) { s->failed_pc=0x0c0434b2u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c0434b4;
P_0c0434b4: /* original 65e3, guest PC 0x0c0434b4 */
if(!s->budget--) { s->failed_pc=0x0c0434b4u; return 0; }
r[5]=r[14];
goto P_0c0434b6;
P_0c0434b6: /* original 1e62, guest PC 0x0c0434b6 */
if(!s->budget--) { s->failed_pc=0x0c0434b6u; return 0; }
write(ram,r[14]+8,r[6],4);
goto P_0c0434b8;
P_0c0434b8: /* original 1e73, guest PC 0x0c0434b8 */
if(!s->budget--) { s->failed_pc=0x0c0434b8u; return 0; }
write(ram,r[14]+12,r[7],4);
goto P_0c0434ba;
P_0c0434ba: /* original d30b, guest PC 0x0c0434ba */
if(!s->budget--) { s->failed_pc=0x0c0434bau; return 0; }
r[3]=read(ram,0x0c0434e8u,4);
goto P_0c0434bc;
P_0c0434bc: /* original 430b, guest PC 0x0c0434bc */
if(!s->budget--) { s->failed_pc=0x0c0434bcu; return 0; }
target=r[3];
r[16]=0x0c0434c0u;
r[4]=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0434c0u) { target=s->pc; goto dispatch; }
goto P_0c0434c0;
P_0c0434be: /* original e41d, guest PC 0x0c0434be */
if(!s->budget--) { s->failed_pc=0x0c0434beu; return 0; }
r[4]=0x0000001du;
goto P_0c0434c0;
P_0c0434c0: /* original 7f10, guest PC 0x0c0434c0 */
if(!s->budget--) { s->failed_pc=0x0c0434c0u; return 0; }
r[15]+=0x00000010u;
goto P_0c0434c2;
P_0c0434c2: /* original 4f26, guest PC 0x0c0434c2 */
if(!s->budget--) { s->failed_pc=0x0c0434c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0434c4;
P_0c0434c4: /* original 000b, guest PC 0x0c0434c4 */
if(!s->budget--) { s->failed_pc=0x0c0434c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0434c6: /* original 6ef6, guest PC 0x0c0434c6 */
if(!s->budget--) { s->failed_pc=0x0c0434c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0434c8u,s,ram);
P_0c04596c: /* original 4f22, guest PC 0x0c04596c */
if(!s->budget--) { s->failed_pc=0x0c04596cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04596e;
P_0c04596e: /* original 6e43, guest PC 0x0c04596e */
if(!s->budget--) { s->failed_pc=0x0c04596eu; return 0; }
r[14]=r[4];
goto P_0c045970;
P_0c045970: /* original b2c0, guest PC 0x0c045970 */
if(!s->budget--) { s->failed_pc=0x0c045970u; return 0; }
target=0x0c045ef4u; r[16]=0x0c045974u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045974u) { target=s->pc; goto dispatch; }
goto P_0c045974;
P_0c045972: /* original e500, guest PC 0x0c045972 */
if(!s->budget--) { s->failed_pc=0x0c045972u; return 0; }
r[5]=0x00000000u;
goto P_0c045974;
P_0c045974: /* original 62e3, guest PC 0x0c045974 */
if(!s->budget--) { s->failed_pc=0x0c045974u; return 0; }
r[2]=r[14];
goto P_0c045976;
P_0c045976: /* original e46e, guest PC 0x0c045976 */
if(!s->budget--) { s->failed_pc=0x0c045976u; return 0; }
r[4]=0x0000006eu;
goto P_0c045978;
P_0c045978: /* original e015, guest PC 0x0c045978 */
if(!s->budget--) { s->failed_pc=0x0c045978u; return 0; }
r[0]=0x00000015u;
goto P_0c04597a;
P_0c04597a: /* original 7214, guest PC 0x0c04597a */
if(!s->budget--) { s->failed_pc=0x0c04597au; return 0; }
r[2]+=0x00000014u;
goto P_0c04597c;
P_0c04597c: /* original e328, guest PC 0x0c04597c */
if(!s->budget--) { s->failed_pc=0x0c04597cu; return 0; }
r[3]=0x00000028u;
goto P_0c04597e;
P_0c04597e: /* original 2230, guest PC 0x0c04597e */
if(!s->budget--) { s->failed_pc=0x0c04597eu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c045980;
P_0c045980: /* original e36f, guest PC 0x0c045980 */
if(!s->budget--) { s->failed_pc=0x0c045980u; return 0; }
r[3]=0x0000006fu;
goto P_0c045982;
P_0c045982: /* original 0e44, guest PC 0x0c045982 */
if(!s->budget--) { s->failed_pc=0x0c045982u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c045984;
P_0c045984: /* original e016, guest PC 0x0c045984 */
if(!s->budget--) { s->failed_pc=0x0c045984u; return 0; }
r[0]=0x00000016u;
goto P_0c045986;
P_0c045986: /* original 0e34, guest PC 0x0c045986 */
if(!s->budget--) { s->failed_pc=0x0c045986u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c045988;
P_0c045988: /* original e017, guest PC 0x0c045988 */
if(!s->budget--) { s->failed_pc=0x0c045988u; return 0; }
r[0]=0x00000017u;
goto P_0c04598a;
P_0c04598a: /* original 0e44, guest PC 0x0c04598a */
if(!s->budget--) { s->failed_pc=0x0c04598au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c04598c;
P_0c04598c: /* original e018, guest PC 0x0c04598c */
if(!s->budget--) { s->failed_pc=0x0c04598cu; return 0; }
r[0]=0x00000018u;
goto P_0c04598e;
P_0c04598e: /* original e365, guest PC 0x0c04598e */
if(!s->budget--) { s->failed_pc=0x0c04598eu; return 0; }
r[3]=0x00000065u;
goto P_0c045990;
P_0c045990: /* original 64e3, guest PC 0x0c045990 */
if(!s->budget--) { s->failed_pc=0x0c045990u; return 0; }
r[4]=r[14];
goto P_0c045992;
P_0c045992: /* original 0e34, guest PC 0x0c045992 */
if(!s->budget--) { s->failed_pc=0x0c045992u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c045994;
P_0c045994: /* original e019, guest PC 0x0c045994 */
if(!s->budget--) { s->failed_pc=0x0c045994u; return 0; }
r[0]=0x00000019u;
goto P_0c045996;
P_0c045996: /* original e229, guest PC 0x0c045996 */
if(!s->budget--) { s->failed_pc=0x0c045996u; return 0; }
r[2]=0x00000029u;
goto P_0c045998;
P_0c045998: /* original e61f, guest PC 0x0c045998 */
if(!s->budget--) { s->failed_pc=0x0c045998u; return 0; }
r[6]=0x0000001fu;
goto P_0c04599a;
P_0c04599a: /* original 0e24, guest PC 0x0c04599a */
if(!s->budget--) { s->failed_pc=0x0c04599au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c04599c;
P_0c04599c: /* original 741a, guest PC 0x0c04599c */
if(!s->budget--) { s->failed_pc=0x0c04599cu; return 0; }
r[4]+=0x0000001au;
goto P_0c04599e;
P_0c04599e: /* original e506, guest PC 0x0c04599e */
if(!s->budget--) { s->failed_pc=0x0c04599eu; return 0; }
r[5]=0x00000006u;
goto P_0c0459a0;
P_0c0459a0: /* original e720, guest PC 0x0c0459a0 */
if(!s->budget--) { s->failed_pc=0x0c0459a0u; return 0; }
r[7]=0x00000020u;
goto P_0c0459a2;
P_0c0459a2: /* original 7501, guest PC 0x0c0459a2 */
if(!s->budget--) { s->failed_pc=0x0c0459a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0459a4;
P_0c0459a4: /* original 2470, guest PC 0x0c0459a4 */
if(!s->budget--) { s->failed_pc=0x0c0459a4u; return 0; }
write(ram,r[4],r[7],1);
goto P_0c0459a6;
P_0c0459a6: /* original 3563, guest PC 0x0c0459a6 */
if(!s->budget--) { s->failed_pc=0x0c0459a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0459a8;
P_0c0459a8: /* original 8ffb, guest PC 0x0c0459a8 */
if(!s->budget--) { s->failed_pc=0x0c0459a8u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c0459a2; }
goto P_0c0459ac;
P_0c0459aa: /* original 7401, guest PC 0x0c0459aa */
if(!s->budget--) { s->failed_pc=0x0c0459aau; return 0; }
r[4]+=0x00000001u;
goto P_0c0459ac;
P_0c0459ac: /* original 4f26, guest PC 0x0c0459ac */
if(!s->budget--) { s->failed_pc=0x0c0459acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0459ae;
P_0c0459ae: /* original e033, guest PC 0x0c0459ae */
if(!s->budget--) { s->failed_pc=0x0c0459aeu; return 0; }
r[0]=0x00000033u;
goto P_0c0459b0;
P_0c0459b0: /* original e200, guest PC 0x0c0459b0 */
if(!s->budget--) { s->failed_pc=0x0c0459b0u; return 0; }
r[2]=0x00000000u;
goto P_0c0459b2;
P_0c0459b2: /* original 0e24, guest PC 0x0c0459b2 */
if(!s->budget--) { s->failed_pc=0x0c0459b2u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0459b4;
P_0c0459b4: /* original 6023, guest PC 0x0c0459b4 */
if(!s->budget--) { s->failed_pc=0x0c0459b4u; return 0; }
r[0]=r[2];
goto P_0c0459b6;
P_0c0459b6: /* original 000b, guest PC 0x0c0459b6 */
if(!s->budget--) { s->failed_pc=0x0c0459b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0459b8: /* original 6ef6, guest PC 0x0c0459b8 */
if(!s->budget--) { s->failed_pc=0x0c0459b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0459bau,s,ram);
P_0c046000: /* original 654d, guest PC 0x0c046000 */
if(!s->budget--) { s->failed_pc=0x0c046000u; return 0; }
r[5]=r[4]&65535u;
goto P_0c046002;
P_0c046002: /* original 6743, guest PC 0x0c046002 */
if(!s->budget--) { s->failed_pc=0x0c046002u; return 0; }
r[7]=r[4];
goto P_0c046004;
P_0c046004: /* original 2558, guest PC 0x0c046004 */
if(!s->budget--) { s->failed_pc=0x0c046004u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c046006;
P_0c046006: /* original 8f02, guest PC 0x0c046006 */
if(!s->budget--) { s->failed_pc=0x0c046006u; return 0; }
cond=r[17]&1u;
r[7]>>=16;
if(!cond) { goto P_0c04600e; }
goto P_0c04600a;
P_0c046008: /* original 4729, guest PC 0x0c046008 */
if(!s->budget--) { s->failed_pc=0x0c046008u; return 0; }
r[7]>>=16;
goto P_0c04600a;
P_0c04600a: /* original 000b, guest PC 0x0c04600a */
if(!s->budget--) { s->failed_pc=0x0c04600au; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c04600c: /* original e0ff, guest PC 0x0c04600c */
if(!s->budget--) { s->failed_pc=0x0c04600cu; return 0; }
r[0]=0xffffffffu;
goto P_0c04600e;
P_0c04600e: /* original d303, guest PC 0x0c04600e */
if(!s->budget--) { s->failed_pc=0x0c04600eu; return 0; }
r[3]=read(ram,0x0c04601cu,4);
goto P_0c046010;
P_0c046010: /* original 6673, guest PC 0x0c046010 */
if(!s->budget--) { s->failed_pc=0x0c046010u; return 0; }
r[6]=r[7];
goto P_0c046012;
P_0c046012: /* original 4608, guest PC 0x0c046012 */
if(!s->budget--) { s->failed_pc=0x0c046012u; return 0; }
r[6]<<=2;
goto P_0c046014;
P_0c046014: /* original a013, guest PC 0x0c046014 */
if(!s->budget--) { s->failed_pc=0x0c046014u; return 0; }
r[6]+=r[3];
goto P_0c04603e;
P_0c046016: /* original 363c, guest PC 0x0c046016 */
if(!s->budget--) { s->failed_pc=0x0c046016u; return 0; }
r[6]+=r[3];
return vf3_matrix_family(0x0c046018u,s,ram);
P_0c046034: /* original 5153, guest PC 0x0c046034 */
if(!s->budget--) { s->failed_pc=0x0c046034u; return 0; }
r[1]=read(ram,r[5]+12,4);
goto P_0c046036;
P_0c046036: /* original 3140, guest PC 0x0c046036 */
if(!s->budget--) { s->failed_pc=0x0c046036u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c046038;
P_0c046038: /* original 8904, guest PC 0x0c046038 */
if(!s->budget--) { s->failed_pc=0x0c046038u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046044; }
goto P_0c04603a;
P_0c04603a: /* original 6653, guest PC 0x0c04603a */
if(!s->budget--) { s->failed_pc=0x0c04603au; return 0; }
r[6]=r[5];
goto P_0c04603c;
P_0c04603c: /* original 7604, guest PC 0x0c04603c */
if(!s->budget--) { s->failed_pc=0x0c04603cu; return 0; }
r[6]+=0x00000004u;
goto P_0c04603e;
P_0c04603e: /* original 6562, guest PC 0x0c04603e */
if(!s->budget--) { s->failed_pc=0x0c04603eu; return 0; }
tmp=read(ram,r[6],4);
r[5]=tmp;
goto P_0c046040;
P_0c046040: /* original 2558, guest PC 0x0c046040 */
if(!s->budget--) { s->failed_pc=0x0c046040u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c046042;
P_0c046042: /* original 8bf7, guest PC 0x0c046042 */
if(!s->budget--) { s->failed_pc=0x0c046042u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c046034; }
goto P_0c046044;
P_0c046044: /* original 2558, guest PC 0x0c046044 */
if(!s->budget--) { s->failed_pc=0x0c046044u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c046046;
P_0c046046: /* original 8b01, guest PC 0x0c046046 */
if(!s->budget--) { s->failed_pc=0x0c046046u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04604c; }
goto P_0c046048;
P_0c046048: /* original 000b, guest PC 0x0c046048 */
if(!s->budget--) { s->failed_pc=0x0c046048u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c04604a: /* original e0fe, guest PC 0x0c04604a */
if(!s->budget--) { s->failed_pc=0x0c04604au; return 0; }
r[0]=0xfffffffeu;
goto P_0c04604c;
P_0c04604c: /* original 5351, guest PC 0x0c04604c */
if(!s->budget--) { s->failed_pc=0x0c04604cu; return 0; }
r[3]=read(ram,r[5]+4,4);
goto P_0c04604e;
P_0c04604e: /* original e000, guest PC 0x0c04604e */
if(!s->budget--) { s->failed_pc=0x0c04604eu; return 0; }
r[0]=0x00000000u;
goto P_0c046050;
P_0c046050: /* original 2632, guest PC 0x0c046050 */
if(!s->budget--) { s->failed_pc=0x0c046050u; return 0; }
write(ram,r[6],r[3],4);
goto P_0c046052;
P_0c046052: /* original d41f, guest PC 0x0c046052 */
if(!s->budget--) { s->failed_pc=0x0c046052u; return 0; }
r[4]=read(ram,0x0c0460d0u,4);
goto P_0c046054;
P_0c046054: /* original 6242, guest PC 0x0c046054 */
if(!s->budget--) { s->failed_pc=0x0c046054u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c046056;
P_0c046056: /* original 1521, guest PC 0x0c046056 */
if(!s->budget--) { s->failed_pc=0x0c046056u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c046058;
P_0c046058: /* original 2452, guest PC 0x0c046058 */
if(!s->budget--) { s->failed_pc=0x0c046058u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c04605a;
P_0c04605a: /* original 000b, guest PC 0x0c04605a */
if(!s->budget--) { s->failed_pc=0x0c04605au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04605c: /* original 0009, guest PC 0x0c04605c */
if(!s->budget--) { s->failed_pc=0x0c04605cu; return 0; }
return vf3_matrix_family(0x0c04605eu,s,ram);
P_0c0462a2: /* original aead, guest PC 0x0c0462a2 */
if(!s->budget--) { s->failed_pc=0x0c0462a2u; return 0; }
goto P_0c046000;
P_0c0462a4: /* original 0009, guest PC 0x0c0462a4 */
if(!s->budget--) { s->failed_pc=0x0c0462a4u; return 0; }
return vf3_matrix_family(0x0c0462a6u,s,ram);
P_0c0463b2: /* original 4f22, guest PC 0x0c0463b2 */
if(!s->budget--) { s->failed_pc=0x0c0463b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0463b4;
P_0c0463b4: /* original 4009, guest PC 0x0c0463b4 */
if(!s->budget--) { s->failed_pc=0x0c0463b4u; return 0; }
r[0]>>=2;
goto P_0c0463b6;
P_0c0463b6: /* original 4009, guest PC 0x0c0463b6 */
if(!s->budget--) { s->failed_pc=0x0c0463b6u; return 0; }
r[0]>>=2;
goto P_0c0463b8;
P_0c0463b8: /* original c90f, guest PC 0x0c0463b8 */
if(!s->budget--) { s->failed_pc=0x0c0463b8u; return 0; }
r[0]&=15u;
goto P_0c0463ba;
P_0c0463ba: /* original 7ffc, guest PC 0x0c0463ba */
if(!s->budget--) { s->failed_pc=0x0c0463bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0463bc;
P_0c0463bc: /* original 2f02, guest PC 0x0c0463bc */
if(!s->budget--) { s->failed_pc=0x0c0463bcu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0463be;
P_0c0463be: /* original 0002, guest PC 0x0c0463be */
if(!s->budget--) { s->failed_pc=0x0c0463beu; return 0; }
r[0]=r[17];
goto P_0c0463c0;
P_0c0463c0: /* original 9337, guest PC 0x0c0463c0 */
if(!s->budget--) { s->failed_pc=0x0c0463c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c046432u,2);
goto P_0c0463c2;
P_0c0463c2: /* original 2039, guest PC 0x0c0463c2 */
if(!s->budget--) { s->failed_pc=0x0c0463c2u; return 0; }
r[0]&=r[3];
goto P_0c0463c4;
P_0c0463c4: /* original cbf0, guest PC 0x0c0463c4 */
if(!s->budget--) { s->failed_pc=0x0c0463c4u; return 0; }
r[0]|=240u;
goto P_0c0463c6;
P_0c0463c6: /* original 400e, guest PC 0x0c0463c6 */
if(!s->budget--) { s->failed_pc=0x0c0463c6u; return 0; }
r[17]=r[0];
goto P_0c0463c8;
P_0c0463c8: /* original d328, guest PC 0x0c0463c8 */
if(!s->budget--) { s->failed_pc=0x0c0463c8u; return 0; }
r[3]=read(ram,0x0c04646cu,4);
goto P_0c0463ca;
P_0c0463ca: /* original d226, guest PC 0x0c0463ca */
if(!s->budget--) { s->failed_pc=0x0c0463cau; return 0; }
r[2]=read(ram,0x0c046464u,4);
goto P_0c0463cc;
P_0c0463cc: /* original 430b, guest PC 0x0c0463cc */
if(!s->budget--) { s->failed_pc=0x0c0463ccu; return 0; }
target=r[3];
r[16]=0x0c0463d0u;
tmp=read(ram,r[2],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0463d0u) { target=s->pc; goto dispatch; }
goto P_0c0463d0;
P_0c0463ce: /* original 6422, guest PC 0x0c0463ce */
if(!s->budget--) { s->failed_pc=0x0c0463ceu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0463d0;
P_0c0463d0: /* original 60f2, guest PC 0x0c0463d0 */
if(!s->budget--) { s->failed_pc=0x0c0463d0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0463d2;
P_0c0463d2: /* original 0102, guest PC 0x0c0463d2 */
if(!s->budget--) { s->failed_pc=0x0c0463d2u; return 0; }
r[1]=r[17];
goto P_0c0463d4;
P_0c0463d4: /* original 932d, guest PC 0x0c0463d4 */
if(!s->budget--) { s->failed_pc=0x0c0463d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c046432u,2);
goto P_0c0463d6;
P_0c0463d6: /* original c90f, guest PC 0x0c0463d6 */
if(!s->budget--) { s->failed_pc=0x0c0463d6u; return 0; }
r[0]&=15u;
goto P_0c0463d8;
P_0c0463d8: /* original 4008, guest PC 0x0c0463d8 */
if(!s->budget--) { s->failed_pc=0x0c0463d8u; return 0; }
r[0]<<=2;
goto P_0c0463da;
P_0c0463da: /* original 2139, guest PC 0x0c0463da */
if(!s->budget--) { s->failed_pc=0x0c0463dau; return 0; }
r[1]&=r[3];
goto P_0c0463dc;
P_0c0463dc: /* original 4008, guest PC 0x0c0463dc */
if(!s->budget--) { s->failed_pc=0x0c0463dcu; return 0; }
r[0]<<=2;
goto P_0c0463de;
P_0c0463de: /* original 201b, guest PC 0x0c0463de */
if(!s->budget--) { s->failed_pc=0x0c0463deu; return 0; }
r[0]|=r[1];
goto P_0c0463e0;
P_0c0463e0: /* original 400e, guest PC 0x0c0463e0 */
if(!s->budget--) { s->failed_pc=0x0c0463e0u; return 0; }
r[17]=r[0];
goto P_0c0463e2;
P_0c0463e2: /* original 7f04, guest PC 0x0c0463e2 */
if(!s->budget--) { s->failed_pc=0x0c0463e2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0463e4;
P_0c0463e4: /* original 4f26, guest PC 0x0c0463e4 */
if(!s->budget--) { s->failed_pc=0x0c0463e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0463e6;
P_0c0463e6: /* original 000b, guest PC 0x0c0463e6 */
if(!s->budget--) { s->failed_pc=0x0c0463e6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0463e8: /* original 0009, guest PC 0x0c0463e8 */
if(!s->budget--) { s->failed_pc=0x0c0463e8u; return 0; }
return vf3_matrix_family(0x0c0463eau,s,ram);
P_0c0476f2: /* original f50b, guest PC 0x0c0476f2 */
if(!s->budget--) { s->failed_pc=0x0c0476f2u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[5]);
goto P_0c0476f4;
P_0c0476f4: /* original fef9, guest PC 0x0c0476f4 */
if(!s->budget--) { s->failed_pc=0x0c0476f4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0476f6;
P_0c0476f6: /* original f5d2, guest PC 0x0c0476f6 */
if(!s->budget--) { s->failed_pc=0x0c0476f6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'*');
goto P_0c0476f8;
P_0c0476f8: /* original 751c, guest PC 0x0c0476f8 */
if(!s->budget--) { s->failed_pc=0x0c0476f8u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0476fa;
P_0c0476fa: /* original f4d2, guest PC 0x0c0476fa */
if(!s->budget--) { s->failed_pc=0x0c0476fau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'*');
goto P_0c0476fc;
P_0c0476fc: /* original f5db, guest PC 0x0c0476fc */
if(!s->budget--) { s->failed_pc=0x0c0476fcu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[5]);
goto P_0c0476fe;
P_0c0476fe: /* original fdf9, guest PC 0x0c0476fe */
if(!s->budget--) { s->failed_pc=0x0c0476feu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c047700;
P_0c047700: /* original fcf9, guest PC 0x0c047700 */
if(!s->budget--) { s->failed_pc=0x0c047700u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c047702;
P_0c047702: /* original f55b, guest PC 0x0c047702 */
if(!s->budget--) { s->failed_pc=0x0c047702u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c047704;
P_0c047704: /* original 000b, guest PC 0x0c047704 */
if(!s->budget--) { s->failed_pc=0x0c047704u; return 0; }
target=r[16];
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
s->pc=target; return ram->oob==0;
P_0c047706: /* original f54b, guest PC 0x0c047706 */
if(!s->budget--) { s->failed_pc=0x0c047706u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
return vf3_matrix_family(0x0c047708u,s,ram);
P_0c04771e: /* original f50b, guest PC 0x0c04771e */
if(!s->budget--) { s->failed_pc=0x0c04771eu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[5]);
goto P_0c047720;
P_0c047720: /* original 0583, guest PC 0x0c047720 */
if(!s->budget--) { s->failed_pc=0x0c047720u; return 0; }
goto P_0c047722;
P_0c047722: /* original fe9d, guest PC 0x0c047722 */
if(!s->budget--) { s->failed_pc=0x0c047722u; return 0; }
fr[14]=0x3f800000u;
goto P_0c047724;
P_0c047724: /* original feb3, guest PC 0x0c047724 */
if(!s->budget--) { s->failed_pc=0x0c047724u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'/');
goto P_0c047726;
P_0c047726: /* original f5d2, guest PC 0x0c047726 */
if(!s->budget--) { s->failed_pc=0x0c047726u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'*');
goto P_0c047728;
P_0c047728: /* original 750c, guest PC 0x0c047728 */
if(!s->budget--) { s->failed_pc=0x0c047728u; return 0; }
r[5]+=0x0000000cu;
goto P_0c04772a;
P_0c04772a: /* original f4d2, guest PC 0x0c04772a */
if(!s->budget--) { s->failed_pc=0x0c04772au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'*');
goto P_0c04772c;
P_0c04772c: /* original f5db, guest PC 0x0c04772c */
if(!s->budget--) { s->failed_pc=0x0c04772cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[5]);
goto P_0c04772e;
P_0c04772e: /* original f55b, guest PC 0x0c04772e */
if(!s->budget--) { s->failed_pc=0x0c04772eu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c047730;
P_0c047730: /* original f54b, guest PC 0x0c047730 */
if(!s->budget--) { s->failed_pc=0x0c047730u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c047732;
P_0c047732: /* original f9e2, guest PC 0x0c047732 */
if(!s->budget--) { s->failed_pc=0x0c047732u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[14],r[18],'*');
goto P_0c047734;
P_0c047734: /* original 751c, guest PC 0x0c047734 */
if(!s->budget--) { s->failed_pc=0x0c047734u; return 0; }
r[5]+=0x0000001cu;
goto P_0c047736;
P_0c047736: /* original f8e2, guest PC 0x0c047736 */
if(!s->budget--) { s->failed_pc=0x0c047736u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[14],r[18],'*');
goto P_0c047738;
P_0c047738: /* original f5eb, guest PC 0x0c047738 */
if(!s->budget--) { s->failed_pc=0x0c047738u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[5]);
goto P_0c04773a;
P_0c04773a: /* original f59b, guest PC 0x0c04773a */
if(!s->budget--) { s->failed_pc=0x0c04773au; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[5]);
goto P_0c04773c;
P_0c04773c: /* original f58b, guest PC 0x0c04773c */
if(!s->budget--) { s->failed_pc=0x0c04773cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[5]);
goto P_0c04773e;
P_0c04773e: /* original fef9, guest PC 0x0c04773e */
if(!s->budget--) { s->failed_pc=0x0c04773eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c047740;
P_0c047740: /* original fdf9, guest PC 0x0c047740 */
if(!s->budget--) { s->failed_pc=0x0c047740u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c047742;
P_0c047742: /* original 000b, guest PC 0x0c047742 */
if(!s->budget--) { s->failed_pc=0x0c047742u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c047744: /* original fcf9, guest PC 0x0c047744 */
if(!s->budget--) { s->failed_pc=0x0c047744u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c047746u,s,ram);
P_0c049306: /* original f449, guest PC 0x0c049306 */
if(!s->budget--) { s->failed_pc=0x0c049306u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c049308;
P_0c049308: /* original f549, guest PC 0x0c049308 */
if(!s->budget--) { s->failed_pc=0x0c049308u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04930a;
P_0c04930a: /* original f649, guest PC 0x0c04930a */
if(!s->budget--) { s->failed_pc=0x0c04930au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04930c;
P_0c04930c: /* original f79d, guest PC 0x0c04930c */
if(!s->budget--) { s->failed_pc=0x0c04930cu; return 0; }
fr[7]=0x3f800000u;
goto P_0c04930e;
P_0c04930e: /* original f249, guest PC 0x0c04930e */
if(!s->budget--) { s->failed_pc=0x0c04930eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c049310;
P_0c049310: /* original f049, guest PC 0x0c049310 */
if(!s->budget--) { s->failed_pc=0x0c049310u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c049312;
P_0c049312: /* original f149, guest PC 0x0c049312 */
if(!s->budget--) { s->failed_pc=0x0c049312u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c049314;
P_0c049314: /* original f5fd, guest PC 0x0c049314 */
if(!s->budget--) { s->failed_pc=0x0c049314u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c049316;
P_0c049316: /* original f38d, guest PC 0x0c049316 */
if(!s->budget--) { s->failed_pc=0x0c049316u; return 0; }
fr[3]=0;
goto P_0c049318;
P_0c049318: /* original fa49, guest PC 0x0c049318 */
if(!s->budget--) { s->failed_pc=0x0c049318u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04931a;
P_0c04931a: /* original 60d3, guest PC 0x0c04931a */
if(!s->budget--) { s->failed_pc=0x0c04931au; return 0; }
r[0]=r[13];
goto P_0c04931c;
P_0c04931c: /* original f849, guest PC 0x0c04931c */
if(!s->budget--) { s->failed_pc=0x0c04931cu; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04931e;
P_0c04931e: /* original 4029, guest PC 0x0c04931e */
if(!s->budget--) { s->failed_pc=0x0c04931eu; return 0; }
r[0]>>=16;
goto P_0c049320;
P_0c049320: /* original f949, guest PC 0x0c049320 */
if(!s->budget--) { s->failed_pc=0x0c049320u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c049322;
P_0c049322: /* original f3ed, guest PC 0x0c049322 */
if(!s->budget--) { s->failed_pc=0x0c049322u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c049324;
P_0c049324: /* original f249, guest PC 0x0c049324 */
if(!s->budget--) { s->failed_pc=0x0c049324u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c049326;
P_0c049326: /* original fff1, guest PC 0x0c049326 */
if(!s->budget--) { s->failed_pc=0x0c049326u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[15],r[18],'-');
goto P_0c049328;
P_0c049328: /* original f79d, guest PC 0x0c049328 */
if(!s->budget--) { s->failed_pc=0x0c049328u; return 0; }
fr[7]=0x3f800000u;
goto P_0c04932a;
P_0c04932a: /* original f743, guest PC 0x0c04932a */
if(!s->budget--) { s->failed_pc=0x0c04932au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c04932c;
P_0c04932c: /* original f049, guest PC 0x0c04932c */
if(!s->budget--) { s->failed_pc=0x0c04932cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04932e;
P_0c04932e: /* original 4028, guest PC 0x0c04932e */
if(!s->budget--) { s->failed_pc=0x0c04932eu; return 0; }
r[0]<<=16;
goto P_0c049330;
P_0c049330: /* original fb8d, guest PC 0x0c049330 */
if(!s->budget--) { s->failed_pc=0x0c049330u; return 0; }
fr[11]=0;
goto P_0c049332;
P_0c049332: /* original f3b5, guest PC 0x0c049332 */
if(!s->budget--) { s->failed_pc=0x0c049332u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[11]))!=0);
goto P_0c049334;
P_0c049334: /* original f149, guest PC 0x0c049334 */
if(!s->budget--) { s->failed_pc=0x0c049334u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c049336;
P_0c049336: /* original 7420, guest PC 0x0c049336 */
if(!s->budget--) { s->failed_pc=0x0c049336u; return 0; }
r[4]+=0x00000020u;
goto P_0c049338;
P_0c049338: /* original fbed, guest PC 0x0c049338 */
if(!s->budget--) { s->failed_pc=0x0c049338u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c04933a;
P_0c04933a: /* original 0483, guest PC 0x0c04933a */
if(!s->budget--) { s->failed_pc=0x0c04933au; return 0; }
goto P_0c04933c;
P_0c04933c: /* original 8900, guest PC 0x0c04933c */
if(!s->budget--) { s->failed_pc=0x0c04933cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c049340; }
goto P_0c04933e;
P_0c04933e: /* original f38d, guest PC 0x0c04933e */
if(!s->budget--) { s->failed_pc=0x0c04933eu; return 0; }
fr[3]=0;
goto P_0c049340;
P_0c049340: /* original f83c, guest PC 0x0c049340 */
if(!s->budget--) { s->failed_pc=0x0c049340u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c049342;
P_0c049342: /* original f882, guest PC 0x0c049342 */
if(!s->budget--) { s->failed_pc=0x0c049342u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[8],r[18],'*');
goto P_0c049344;
P_0c049344: /* original f99d, guest PC 0x0c049344 */
if(!s->budget--) { s->failed_pc=0x0c049344u; return 0; }
fr[9]=0x3f800000u;
goto P_0c049346;
P_0c049346: /* original fced, guest PC 0x0c049346 */
if(!s->budget--) { s->failed_pc=0x0c049346u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+12,r[18],fr+15)) goto unsupported;
goto P_0c049348;
P_0c049348: /* original fa8d, guest PC 0x0c049348 */
if(!s->budget--) { s->failed_pc=0x0c049348u; return 0; }
fr[10]=0;
goto P_0c04934a;
P_0c04934a: /* original fab5, guest PC 0x0c04934a */
if(!s->budget--) { s->failed_pc=0x0c04934au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[11]))!=0);
goto P_0c04934c;
P_0c04934c: /* original 62d3, guest PC 0x0c04934c */
if(!s->budget--) { s->failed_pc=0x0c04934cu; return 0; }
r[2]=r[13];
goto P_0c04934e;
P_0c04934e: /* original f981, guest PC 0x0c04934e */
if(!s->budget--) { s->failed_pc=0x0c04934eu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[8],r[18],'-');
goto P_0c049350;
P_0c049350: /* original 622c, guest PC 0x0c049350 */
if(!s->budget--) { s->failed_pc=0x0c049350u; return 0; }
r[2]=r[2]&255u;
goto P_0c049352;
P_0c049352: /* original 8b00, guest PC 0x0c049352 */
if(!s->budget--) { s->failed_pc=0x0c049352u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c049356; }
goto P_0c049354;
P_0c049354: /* original fb4d, guest PC 0x0c049354 */
if(!s->budget--) { s->failed_pc=0x0c049354u; return 0; }
fr[11]^=0x80000000u;
goto P_0c049356;
P_0c049356: /* original 0029, guest PC 0x0c049356 */
if(!s->budget--) { s->failed_pc=0x0c049356u; return 0; }
r[0]=r[17]&1u;
goto P_0c049358;
P_0c049358: /* original faf5, guest PC 0x0c049358 */
if(!s->budget--) { s->failed_pc=0x0c049358u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[15]))!=0);
goto P_0c04935a;
P_0c04935a: /* original 425a, guest PC 0x0c04935a */
if(!s->budget--) { s->failed_pc=0x0c04935au; return 0; }
r[53]=r[2];
goto P_0c04935c;
P_0c04935c: /* original f96d, guest PC 0x0c04935c */
if(!s->budget--) { s->failed_pc=0x0c04935cu; return 0; }
fr[9]=vf3_fpu_sqrt(fr[9],r[18]);
goto P_0c04935e;
P_0c04935e: /* original 8b00, guest PC 0x0c04935e */
if(!s->budget--) { s->failed_pc=0x0c04935eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c049362; }
goto P_0c049360;
P_0c049360: /* original ff4d, guest PC 0x0c049360 */
if(!s->budget--) { s->failed_pc=0x0c049360u; return 0; }
fr[15]^=0x80000000u;
goto P_0c049362;
P_0c049362: /* original 0129, guest PC 0x0c049362 */
if(!s->budget--) { s->failed_pc=0x0c049362u; return 0; }
r[1]=r[17]&1u;
goto P_0c049364;
P_0c049364: /* original ffb5, guest PC 0x0c049364 */
if(!s->budget--) { s->failed_pc=0x0c049364u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[11]))!=0);
goto P_0c049366;
P_0c049366: /* original fafc, guest PC 0x0c049366 */
if(!s->budget--) { s->failed_pc=0x0c049366u; return 0; }
vf3_matrix_move(s,10,15);
goto P_0c049368;
P_0c049368: /* original 4108, guest PC 0x0c049368 */
if(!s->budget--) { s->failed_pc=0x0c049368u; return 0; }
r[1]<<=2;
goto P_0c04936a;
P_0c04936a: /* original 8b02, guest PC 0x0c04936a */
if(!s->budget--) { s->failed_pc=0x0c04936au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c049372; }
goto P_0c04936c;
P_0c04936c: /* original ffbc, guest PC 0x0c04936c */
if(!s->budget--) { s->failed_pc=0x0c04936cu; return 0; }
vf3_matrix_move(s,15,11);
goto P_0c04936e;
P_0c04936e: /* original cb02, guest PC 0x0c04936e */
if(!s->budget--) { s->failed_pc=0x0c04936eu; return 0; }
r[0]|=2u;
goto P_0c049370;
P_0c049370: /* original fbac, guest PC 0x0c049370 */
if(!s->budget--) { s->failed_pc=0x0c049370u; return 0; }
vf3_matrix_move(s,11,10);
goto P_0c049372;
P_0c049372: /* original 210b, guest PC 0x0c049372 */
if(!s->budget--) { s->failed_pc=0x0c049372u; return 0; }
r[1]|=r[0];
goto P_0c049374;
P_0c049374: /* original fa2d, guest PC 0x0c049374 */
if(!s->budget--) { s->failed_pc=0x0c049374u; return 0; }
fr[10]=vf3_fpu_float(r[53],r[18]);
goto P_0c049376;
P_0c049376: /* original 4100, guest PC 0x0c049376 */
if(!s->budget--) { s->failed_pc=0x0c049376u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c049378;
P_0c049378: /* original c735, guest PC 0x0c049378 */
if(!s->budget--) { s->failed_pc=0x0c049378u; return 0; }
r[0]=0x0c049450u;
goto P_0c04937a;
P_0c04937a: /* original 011d, guest PC 0x0c04937a */
if(!s->budget--) { s->failed_pc=0x0c04937au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c04937c;
P_0c04937c: /* original c730, guest PC 0x0c04937c */
if(!s->budget--) { s->failed_pc=0x0c04937cu; return 0; }
r[0]=0x0c049440u;
goto P_0c04937e;
P_0c04937e: /* original f009, guest PC 0x0c04937e */
if(!s->budget--) { s->failed_pc=0x0c04937eu; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c049380;
P_0c049380: /* original ffb3, guest PC 0x0c049380 */
if(!s->budget--) { s->failed_pc=0x0c049380u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[11],r[18],'/');
goto P_0c049382;
P_0c049382: /* original 4101, guest PC 0x0c049382 */
if(!s->budget--) { s->failed_pc=0x0c049382u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c049384;
P_0c049384: /* original fb09, guest PC 0x0c049384 */
if(!s->budget--) { s->failed_pc=0x0c049384u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c049386;
P_0c049386: /* original f3a2, guest PC 0x0c049386 */
if(!s->budget--) { s->failed_pc=0x0c049386u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'*');
goto P_0c049388;
P_0c049388: /* original 6202, guest PC 0x0c049388 */
if(!s->budget--) { s->failed_pc=0x0c049388u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c04938a;
P_0c04938a: /* original 60d3, guest PC 0x0c04938a */
if(!s->budget--) { s->failed_pc=0x0c04938au; return 0; }
r[0]=r[13];
goto P_0c04938c;
P_0c04938c: /* original 4029, guest PC 0x0c04938c */
if(!s->budget--) { s->failed_pc=0x0c04938cu; return 0; }
r[0]>>=16;
goto P_0c04938e;
P_0c04938e: /* original f9a2, guest PC 0x0c04938e */
if(!s->budget--) { s->failed_pc=0x0c04938eu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c049390;
P_0c049390: /* original 4028, guest PC 0x0c049390 */
if(!s->budget--) { s->failed_pc=0x0c049390u; return 0; }
r[0]<<=16;
goto P_0c049392;
P_0c049392: /* original f33d, guest PC 0x0c049392 */
if(!s->budget--) { s->failed_pc=0x0c049392u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c049394;
P_0c049394: /* original 210b, guest PC 0x0c049394 */
if(!s->budget--) { s->failed_pc=0x0c049394u; return 0; }
r[1]|=r[0];
goto P_0c049396;
P_0c049396: /* original 005a, guest PC 0x0c049396 */
if(!s->budget--) { s->failed_pc=0x0c049396u; return 0; }
r[0]=r[53];
goto P_0c049398;
P_0c049398: /* original 7420, guest PC 0x0c049398 */
if(!s->budget--) { s->failed_pc=0x0c049398u; return 0; }
r[4]+=0x00000020u;
goto P_0c04939a;
P_0c04939a: /* original f93d, guest PC 0x0c04939a */
if(!s->budget--) { s->failed_pc=0x0c04939au; return 0; }
r[53]=truncate_float(fr[9]);
goto P_0c04939c;
P_0c04939c: /* original 0483, guest PC 0x0c04939c */
if(!s->budget--) { s->failed_pc=0x0c04939cu; return 0; }
goto P_0c04939e;
P_0c04939e: /* original 4028, guest PC 0x0c04939e */
if(!s->budget--) { s->failed_pc=0x0c04939eu; return 0; }
r[0]<<=16;
goto P_0c0493a0;
P_0c0493a0: /* original 310c, guest PC 0x0c0493a0 */
if(!s->budget--) { s->failed_pc=0x0c0493a0u; return 0; }
r[1]+=r[0];
goto P_0c0493a2;
P_0c0493a2: /* original 005a, guest PC 0x0c0493a2 */
if(!s->budget--) { s->failed_pc=0x0c0493a2u; return 0; }
r[0]=r[53];
goto P_0c0493a4;
P_0c0493a4: /* original 74c0, guest PC 0x0c0493a4 */
if(!s->budget--) { s->failed_pc=0x0c0493a4u; return 0; }
r[4]+=0xffffffc0u;
goto P_0c0493a6;
P_0c0493a6: /* original fbfe, guest PC 0x0c0493a6 */
if(!s->budget--) { s->failed_pc=0x0c0493a6u; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[15],fr[11],r[18]);
goto P_0c0493a8;
P_0c0493a8: /* original 4018, guest PC 0x0c0493a8 */
if(!s->budget--) { s->failed_pc=0x0c0493a8u; return 0; }
r[0]<<=8;
goto P_0c0493aa;
P_0c0493aa: /* original fb3d, guest PC 0x0c0493aa */
if(!s->budget--) { s->failed_pc=0x0c0493aau; return 0; }
r[53]=truncate_float(fr[11]);
goto P_0c0493ac;
P_0c0493ac: /* original ff8d, guest PC 0x0c0493ac */
if(!s->budget--) { s->failed_pc=0x0c0493acu; return 0; }
fr[15]=0;
goto P_0c0493ae;
P_0c0493ae: /* original 310c, guest PC 0x0c0493ae */
if(!s->budget--) { s->failed_pc=0x0c0493aeu; return 0; }
r[1]+=r[0];
goto P_0c0493b0;
P_0c0493b0: /* original 005a, guest PC 0x0c0493b0 */
if(!s->budget--) { s->failed_pc=0x0c0493b0u; return 0; }
r[0]=r[53];
goto P_0c0493b2;
P_0c0493b2: /* original c9ff, guest PC 0x0c0493b2 */
if(!s->budget--) { s->failed_pc=0x0c0493b2u; return 0; }
r[0]&=255u;
goto P_0c0493b4;
P_0c0493b4: /* original 002c, guest PC 0x0c0493b4 */
if(!s->budget--) { s->failed_pc=0x0c0493b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0493b6;
P_0c0493b6: /* original 8b00, guest PC 0x0c0493b6 */
if(!s->budget--) { s->failed_pc=0x0c0493b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0493ba; }
goto P_0c0493b8;
P_0c0493b8: /* original 600b, guest PC 0x0c0493b8 */
if(!s->budget--) { s->failed_pc=0x0c0493b8u; return 0; }
r[0]=0u-r[0];
goto P_0c0493ba;
P_0c0493ba: /* original 301c, guest PC 0x0c0493ba */
if(!s->budget--) { s->failed_pc=0x0c0493bau; return 0; }
r[0]+=r[1];
goto P_0c0493bc;
P_0c0493bc: /* original 2606, guest PC 0x0c0493bc */
if(!s->budget--) { s->failed_pc=0x0c0493bcu; return 0; }
r[6]-=4; write(ram,r[6],r[0],4);
goto P_0c0493be;
P_0c0493be: /* original f3fd, guest PC 0x0c0493be */
if(!s->budget--) { s->failed_pc=0x0c0493beu; return 0; }
r[18]^=0x100000u;
goto P_0c0493c0;
P_0c0493c0: /* original 6146, guest PC 0x0c0493c0 */
if(!s->budget--) { s->failed_pc=0x0c0493c0u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0493c2;
P_0c0493c2: /* original f672, guest PC 0x0c0493c2 */
if(!s->budget--) { s->failed_pc=0x0c0493c2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0493c4;
P_0c0493c4: /* original 6246, guest PC 0x0c0493c4 */
if(!s->budget--) { s->failed_pc=0x0c0493c4u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[2]=tmp;
goto P_0c0493c6;
P_0c0493c6: /* original f572, guest PC 0x0c0493c6 */
if(!s->budget--) { s->failed_pc=0x0c0493c6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0493c8;
P_0c0493c8: /* original 2686, guest PC 0x0c0493c8 */
if(!s->budget--) { s->failed_pc=0x0c0493c8u; return 0; }
r[6]-=4; write(ram,r[6],r[8],4);
goto P_0c0493ca;
P_0c0493ca: /* original 6e03, guest PC 0x0c0493ca */
if(!s->budget--) { s->failed_pc=0x0c0493cau; return 0; }
r[14]=r[0];
goto P_0c0493cc;
P_0c0493cc: /* original 2626, guest PC 0x0c0493cc */
if(!s->budget--) { s->failed_pc=0x0c0493ccu; return 0; }
r[6]-=4; write(ram,r[6],r[2],4);
goto P_0c0493ce;
P_0c0493ce: /* original 6063, guest PC 0x0c0493ce */
if(!s->budget--) { s->failed_pc=0x0c0493ceu; return 0; }
r[0]=r[6];
goto P_0c0493d0;
P_0c0493d0: /* original 2616, guest PC 0x0c0493d0 */
if(!s->budget--) { s->failed_pc=0x0c0493d0u; return 0; }
r[6]-=4; write(ram,r[6],r[1],4);
goto P_0c0493d2;
P_0c0493d2: /* original 4021, guest PC 0x0c0493d2 */
if(!s->budget--) { s->failed_pc=0x0c0493d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c0493d4;
P_0c0493d4: /* original f66b, guest PC 0x0c0493d4 */
if(!s->budget--) { s->failed_pc=0x0c0493d4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c0493d6;
P_0c0493d6: /* original 4310, guest PC 0x0c0493d6 */
if(!s->budget--) { s->failed_pc=0x0c0493d6u; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c0493d8;
P_0c0493d8: /* original f64b, guest PC 0x0c0493d8 */
if(!s->budget--) { s->failed_pc=0x0c0493d8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0493da;
P_0c0493da: /* original 8d05, guest PC 0x0c0493da */
if(!s->budget--) { s->failed_pc=0x0c0493dau; return 0; }
cond=r[17]&1u;
r[18]^=0x100000u;
if(cond) { goto P_0c0493e8; }
goto P_0c0493de;
P_0c0493dc: /* original f3fd, guest PC 0x0c0493dc */
if(!s->budget--) { s->failed_pc=0x0c0493dcu; return 0; }
r[18]^=0x100000u;
goto P_0c0493de;
P_0c0493de: /* original 2662, guest PC 0x0c0493de */
if(!s->budget--) { s->failed_pc=0x0c0493deu; return 0; }
write(ram,r[6],r[6],4);
goto P_0c0493e0;
P_0c0493e0: /* original 7520, guest PC 0x0c0493e0 */
if(!s->budget--) { s->failed_pc=0x0c0493e0u; return 0; }
r[5]+=0x00000020u;
goto P_0c0493e2;
P_0c0493e2: /* original 0683, guest PC 0x0c0493e2 */
if(!s->budget--) { s->failed_pc=0x0c0493e2u; return 0; }
goto P_0c0493e4;
P_0c0493e4: /* original af8f, guest PC 0x0c0493e4 */
if(!s->budget--) { s->failed_pc=0x0c0493e4u; return 0; }
r[6]+=0x00000040u;
goto P_0c049306;
P_0c0493e6: /* original 7640, guest PC 0x0c0493e6 */
if(!s->budget--) { s->failed_pc=0x0c0493e6u; return 0; }
r[6]+=0x00000040u;
goto P_0c0493e8;
P_0c0493e8: /* original 7520, guest PC 0x0c0493e8 */
if(!s->budget--) { s->failed_pc=0x0c0493e8u; return 0; }
r[5]+=0x00000020u;
goto P_0c0493ea;
P_0c0493ea: /* original 2602, guest PC 0x0c0493ea */
if(!s->budget--) { s->failed_pc=0x0c0493eau; return 0; }
write(ram,r[6],r[0],4);
goto P_0c0493ec;
P_0c0493ec: /* original 4910, guest PC 0x0c0493ec */
if(!s->budget--) { s->failed_pc=0x0c0493ecu; return 0; }
--r[9];
r[17]=(r[17]&~1u)|((r[9]==0)!=0);
goto P_0c0493ee;
P_0c0493ee: /* original 0683, guest PC 0x0c0493ee */
if(!s->budget--) { s->failed_pc=0x0c0493eeu; return 0; }
goto P_0c0493f0;
P_0c0493f0: /* original 7640, guest PC 0x0c0493f0 */
if(!s->budget--) { s->failed_pc=0x0c0493f0u; return 0; }
r[6]+=0x00000040u;
goto P_0c0493f2;
P_0c0493f2: /* original 8f88, guest PC 0x0c0493f2 */
if(!s->budget--) { s->failed_pc=0x0c0493f2u; return 0; }
cond=r[17]&1u;
r[3]=0x00000003u;
if(!cond) { goto P_0c049306; }
goto P_0c0493f6;
P_0c0493f4: /* original e303, guest PC 0x0c0493f4 */
if(!s->budget--) { s->failed_pc=0x0c0493f4u; return 0; }
r[3]=0x00000003u;
goto P_0c0493f6;
P_0c0493f6: /* original 000b, guest PC 0x0c0493f6 */
if(!s->budget--) { s->failed_pc=0x0c0493f6u; return 0; }
target=r[16];
r[6]+=0xffffffe0u;
s->pc=target; return ram->oob==0;
P_0c0493f8: /* original 76e0, guest PC 0x0c0493f8 */
if(!s->budget--) { s->failed_pc=0x0c0493f8u; return 0; }
r[6]+=0xffffffe0u;
return vf3_matrix_family(0x0c0493fau,s,ram);
P_0c049416: /* original f60b, guest PC 0x0c049416 */
if(!s->budget--) { s->failed_pc=0x0c049416u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c049418;
P_0c049418: /* original 4021, guest PC 0x0c049418 */
if(!s->budget--) { s->failed_pc=0x0c049418u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c04941a;
P_0c04941a: /* original f66b, guest PC 0x0c04941a */
if(!s->budget--) { s->failed_pc=0x0c04941au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04941c;
P_0c04941c: /* original 4310, guest PC 0x0c04941c */
if(!s->budget--) { s->failed_pc=0x0c04941cu; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c04941e;
P_0c04941e: /* original f64b, guest PC 0x0c04941e */
if(!s->budget--) { s->failed_pc=0x0c04941eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c049420;
P_0c049420: /* original 8de2, guest PC 0x0c049420 */
if(!s->budget--) { s->failed_pc=0x0c049420u; return 0; }
cond=r[17]&1u;
r[18]^=0x100000u;
if(cond) { goto P_0c0493e8; }
goto P_0c049424;
P_0c049422: /* original f3fd, guest PC 0x0c049422 */
if(!s->budget--) { s->failed_pc=0x0c049422u; return 0; }
r[18]^=0x100000u;
goto P_0c049424;
P_0c049424: /* original 2662, guest PC 0x0c049424 */
if(!s->budget--) { s->failed_pc=0x0c049424u; return 0; }
write(ram,r[6],r[6],4);
goto P_0c049426;
P_0c049426: /* original 7520, guest PC 0x0c049426 */
if(!s->budget--) { s->failed_pc=0x0c049426u; return 0; }
r[5]+=0x00000020u;
goto P_0c049428;
P_0c049428: /* original 0683, guest PC 0x0c049428 */
if(!s->budget--) { s->failed_pc=0x0c049428u; return 0; }
goto P_0c04942a;
P_0c04942a: /* original af6c, guest PC 0x0c04942a */
if(!s->budget--) { s->failed_pc=0x0c04942au; return 0; }
r[6]+=0x00000040u;
goto P_0c049306;
P_0c04942c: /* original 7640, guest PC 0x0c04942c */
if(!s->budget--) { s->failed_pc=0x0c04942cu; return 0; }
r[6]+=0x00000040u;
return vf3_matrix_family(0x0c04942eu,s,ram);
P_0c04c968: /* original 4f22, guest PC 0x0c04c968 */
if(!s->budget--) { s->failed_pc=0x0c04c968u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c96a;
P_0c04c96a: /* original e500, guest PC 0x0c04c96a */
if(!s->budget--) { s->failed_pc=0x0c04c96au; return 0; }
r[5]=0x00000000u;
goto P_0c04c96c;
P_0c04c96c: /* original 4f12, guest PC 0x0c04c96c */
if(!s->budget--) { s->failed_pc=0x0c04c96cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04c96e;
P_0c04c96e: /* original 7ffc, guest PC 0x0c04c96e */
if(!s->budget--) { s->failed_pc=0x0c04c96eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04c970;
P_0c04c970: /* original 2f42, guest PC 0x0c04c970 */
if(!s->budget--) { s->failed_pc=0x0c04c970u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04c972;
P_0c04c972: /* original 935a, guest PC 0x0c04c972 */
if(!s->budget--) { s->failed_pc=0x0c04c972u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ca2au,2);
goto P_0c04c974;
P_0c04c974: /* original d22e, guest PC 0x0c04c974 */
if(!s->budget--) { s->failed_pc=0x0c04c974u; return 0; }
r[2]=read(ram,0x0c04ca30u,4);
goto P_0c04c976;
P_0c04c976: /* original 2e3f, guest PC 0x0c04c976 */
if(!s->budget--) { s->failed_pc=0x0c04c976u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04c978;
P_0c04c978: /* original d12e, guest PC 0x0c04c978 */
if(!s->budget--) { s->failed_pc=0x0c04c978u; return 0; }
r[1]=read(ram,0x0c04ca34u,4);
goto P_0c04c97a;
P_0c04c97a: /* original 6633, guest PC 0x0c04c97a */
if(!s->budget--) { s->failed_pc=0x0c04c97au; return 0; }
r[6]=r[3];
goto P_0c04c97c;
P_0c04c97c: /* original 0e1a, guest PC 0x0c04c97c */
if(!s->budget--) { s->failed_pc=0x0c04c97cu; return 0; }
r[14]=r[19];
goto P_0c04c97e;
P_0c04c97e: /* original 6eef, guest PC 0x0c04c97e */
if(!s->budget--) { s->failed_pc=0x0c04c97eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04c980;
P_0c04c980: /* original 3e2c, guest PC 0x0c04c980 */
if(!s->budget--) { s->failed_pc=0x0c04c980u; return 0; }
r[14]+=r[2];
goto P_0c04c982;
P_0c04c982: /* original 410b, guest PC 0x0c04c982 */
if(!s->budget--) { s->failed_pc=0x0c04c982u; return 0; }
target=r[1];
r[16]=0x0c04c986u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04c986u) { target=s->pc; goto dispatch; }
goto P_0c04c986;
P_0c04c984: /* original 64e3, guest PC 0x0c04c984 */
if(!s->budget--) { s->failed_pc=0x0c04c984u; return 0; }
r[4]=r[14];
goto P_0c04c986;
P_0c04c986: /* original 63f2, guest PC 0x0c04c986 */
if(!s->budget--) { s->failed_pc=0x0c04c986u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04c988;
P_0c04c988: /* original e24c, guest PC 0x0c04c988 */
if(!s->budget--) { s->failed_pc=0x0c04c988u; return 0; }
r[2]=0x0000004cu;
goto P_0c04c98a;
P_0c04c98a: /* original 7f04, guest PC 0x0c04c98a */
if(!s->budget--) { s->failed_pc=0x0c04c98au; return 0; }
r[15]+=0x00000004u;
goto P_0c04c98c;
P_0c04c98c: /* original d12a, guest PC 0x0c04c98c */
if(!s->budget--) { s->failed_pc=0x0c04c98cu; return 0; }
r[1]=read(ram,0x0c04ca38u,4);
goto P_0c04c98e;
P_0c04c98e: /* original 232f, guest PC 0x0c04c98e */
if(!s->budget--) { s->failed_pc=0x0c04c98eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[3]*(int32_t)(int16_t)r[2]);
goto P_0c04c990;
P_0c04c990: /* original e000, guest PC 0x0c04c990 */
if(!s->budget--) { s->failed_pc=0x0c04c990u; return 0; }
r[0]=0x00000000u;
goto P_0c04c992;
P_0c04c992: /* original 031a, guest PC 0x0c04c992 */
if(!s->budget--) { s->failed_pc=0x0c04c992u; return 0; }
r[3]=r[19];
goto P_0c04c994;
P_0c04c994: /* original 4f16, guest PC 0x0c04c994 */
if(!s->budget--) { s->failed_pc=0x0c04c994u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c996;
P_0c04c996: /* original 633f, guest PC 0x0c04c996 */
if(!s->budget--) { s->failed_pc=0x0c04c996u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04c998;
P_0c04c998: /* original 4f26, guest PC 0x0c04c998 */
if(!s->budget--) { s->failed_pc=0x0c04c998u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c99a;
P_0c04c99a: /* original 331c, guest PC 0x0c04c99a */
if(!s->budget--) { s->failed_pc=0x0c04c99au; return 0; }
r[3]+=r[1];
goto P_0c04c99c;
P_0c04c99c: /* original 1e37, guest PC 0x0c04c99c */
if(!s->budget--) { s->failed_pc=0x0c04c99cu; return 0; }
write(ram,r[14]+28,r[3],4);
goto P_0c04c99e;
P_0c04c99e: /* original 000b, guest PC 0x0c04c99e */
if(!s->budget--) { s->failed_pc=0x0c04c99eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c9a0: /* original 6ef6, guest PC 0x0c04c9a0 */
if(!s->budget--) { s->failed_pc=0x0c04c9a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04c9a2u,s,ram);
P_0c04cb3e: /* original 4f22, guest PC 0x0c04cb3e */
if(!s->budget--) { s->failed_pc=0x0c04cb3eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04cb40;
P_0c04cb40: /* original d31e, guest PC 0x0c04cb40 */
if(!s->budget--) { s->failed_pc=0x0c04cb40u; return 0; }
r[3]=read(ram,0x0c04cbbcu,4);
goto P_0c04cb42;
P_0c04cb42: /* original bd2d, guest PC 0x0c04cb42 */
if(!s->budget--) { s->failed_pc=0x0c04cb42u; return 0; }
target=0x0c04c5a0u; r[16]=0x0c04cb46u;
r[15]-=4; write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cb46u) { target=s->pc; goto dispatch; }
goto P_0c04cb46;
P_0c04cb44: /* original 2f36, guest PC 0x0c04cb44 */
if(!s->budget--) { s->failed_pc=0x0c04cb44u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c04cb46;
P_0c04cb46: /* original d41e, guest PC 0x0c04cb46 */
if(!s->budget--) { s->failed_pc=0x0c04cb46u; return 0; }
r[4]=read(ram,0x0c04cbc0u,4);
goto P_0c04cb48;
P_0c04cb48: /* original 7f04, guest PC 0x0c04cb48 */
if(!s->budget--) { s->failed_pc=0x0c04cb48u; return 0; }
r[15]+=0x00000004u;
goto P_0c04cb4a;
P_0c04cb4a: /* original d316, guest PC 0x0c04cb4a */
if(!s->budget--) { s->failed_pc=0x0c04cb4au; return 0; }
r[3]=read(ram,0x0c04cba4u,4);
goto P_0c04cb4c;
P_0c04cb4c: /* original 9626, guest PC 0x0c04cb4c */
if(!s->budget--) { s->failed_pc=0x0c04cb4cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cb9cu,2);
goto P_0c04cb4e;
P_0c04cb4e: /* original 430b, guest PC 0x0c04cb4e */
if(!s->budget--) { s->failed_pc=0x0c04cb4eu; return 0; }
target=r[3];
r[16]=0x0c04cb52u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cb52u) { target=s->pc; goto dispatch; }
goto P_0c04cb52;
P_0c04cb50: /* original e500, guest PC 0x0c04cb50 */
if(!s->budget--) { s->failed_pc=0x0c04cb50u; return 0; }
r[5]=0x00000000u;
goto P_0c04cb52;
P_0c04cb52: /* original d21c, guest PC 0x0c04cb52 */
if(!s->budget--) { s->failed_pc=0x0c04cb52u; return 0; }
r[2]=read(ram,0x0c04cbc4u,4);
goto P_0c04cb54;
P_0c04cb54: /* original 420b, guest PC 0x0c04cb54 */
if(!s->budget--) { s->failed_pc=0x0c04cb54u; return 0; }
target=r[2];
r[16]=0x0c04cb58u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cb58u) { target=s->pc; goto dispatch; }
goto P_0c04cb58;
P_0c04cb56: /* original 0009, guest PC 0x0c04cb56 */
if(!s->budget--) { s->failed_pc=0x0c04cb56u; return 0; }
goto P_0c04cb58;
P_0c04cb58: /* original 4f26, guest PC 0x0c04cb58 */
if(!s->budget--) { s->failed_pc=0x0c04cb58u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cb5a;
P_0c04cb5a: /* original 000b, guest PC 0x0c04cb5a */
if(!s->budget--) { s->failed_pc=0x0c04cb5au; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04cb5c: /* original e000, guest PC 0x0c04cb5c */
if(!s->budget--) { s->failed_pc=0x0c04cb5cu; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c04cb5eu,s,ram);
P_0c050128: /* original 4f22, guest PC 0x0c050128 */
if(!s->budget--) { s->failed_pc=0x0c050128u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05012a;
P_0c05012a: /* original d34c, guest PC 0x0c05012a */
if(!s->budget--) { s->failed_pc=0x0c05012au; return 0; }
r[3]=read(ram,0x0c05025cu,4);
goto P_0c05012c;
P_0c05012c: /* original 6143, guest PC 0x0c05012c */
if(!s->budget--) { s->failed_pc=0x0c05012cu; return 0; }
r[1]=r[4];
goto P_0c05012e;
P_0c05012e: /* original e60a, guest PC 0x0c05012e */
if(!s->budget--) { s->failed_pc=0x0c05012eu; return 0; }
r[6]=0x0000000au;
goto P_0c050130;
P_0c050130: /* original 430b, guest PC 0x0c050130 */
if(!s->budget--) { s->failed_pc=0x0c050130u; return 0; }
target=r[3];
r[16]=0x0c050134u;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050134u) { target=s->pc; goto dispatch; }
goto P_0c050134;
P_0c050132: /* original 6063, guest PC 0x0c050132 */
if(!s->budget--) { s->failed_pc=0x0c050132u; return 0; }
r[0]=r[6];
goto P_0c050134;
P_0c050134: /* original d24a, guest PC 0x0c050134 */
if(!s->budget--) { s->failed_pc=0x0c050134u; return 0; }
r[2]=read(ram,0x0c050260u,4);
goto P_0c050136;
P_0c050136: /* original 6143, guest PC 0x0c050136 */
if(!s->budget--) { s->failed_pc=0x0c050136u; return 0; }
r[1]=r[4];
goto P_0c050138;
P_0c050138: /* original 6503, guest PC 0x0c050138 */
if(!s->budget--) { s->failed_pc=0x0c050138u; return 0; }
r[5]=r[0];
goto P_0c05013a;
P_0c05013a: /* original 420b, guest PC 0x0c05013a */
if(!s->budget--) { s->failed_pc=0x0c05013au; return 0; }
target=r[2];
r[16]=0x0c05013eu;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05013eu) { target=s->pc; goto dispatch; }
goto P_0c05013e;
P_0c05013c: /* original 6063, guest PC 0x0c05013c */
if(!s->budget--) { s->failed_pc=0x0c05013cu; return 0; }
r[0]=r[6];
goto P_0c05013e;
P_0c05013e: /* original 6403, guest PC 0x0c05013e */
if(!s->budget--) { s->failed_pc=0x0c05013eu; return 0; }
r[4]=r[0];
goto P_0c050140;
P_0c050140: /* original 6053, guest PC 0x0c050140 */
if(!s->budget--) { s->failed_pc=0x0c050140u; return 0; }
r[0]=r[5];
goto P_0c050142;
P_0c050142: /* original 4f26, guest PC 0x0c050142 */
if(!s->budget--) { s->failed_pc=0x0c050142u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c050144;
P_0c050144: /* original 4008, guest PC 0x0c050144 */
if(!s->budget--) { s->failed_pc=0x0c050144u; return 0; }
r[0]<<=2;
goto P_0c050146;
P_0c050146: /* original 4008, guest PC 0x0c050146 */
if(!s->budget--) { s->failed_pc=0x0c050146u; return 0; }
r[0]<<=2;
goto P_0c050148;
P_0c050148: /* original 000b, guest PC 0x0c050148 */
if(!s->budget--) { s->failed_pc=0x0c050148u; return 0; }
target=r[16];
r[0]+=r[4];
s->pc=target; return ram->oob==0;
P_0c05014a: /* original 304c, guest PC 0x0c05014a */
if(!s->budget--) { s->failed_pc=0x0c05014au; return 0; }
r[0]+=r[4];
return vf3_matrix_family(0x0c05014cu,s,ram);
P_0c050174: /* original 4f22, guest PC 0x0c050174 */
if(!s->budget--) { s->failed_pc=0x0c050174u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c050176;
P_0c050176: /* original d33b, guest PC 0x0c050176 */
if(!s->budget--) { s->failed_pc=0x0c050176u; return 0; }
r[3]=read(ram,0x0c050264u,4);
goto P_0c050178;
P_0c050178: /* original 611d, guest PC 0x0c050178 */
if(!s->budget--) { s->failed_pc=0x0c050178u; return 0; }
r[1]=r[1]&65535u;
goto P_0c05017a;
P_0c05017a: /* original 430b, guest PC 0x0c05017a */
if(!s->budget--) { s->failed_pc=0x0c05017au; return 0; }
target=r[3];
r[16]=0x0c05017eu;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05017eu) { target=s->pc; goto dispatch; }
goto P_0c05017e;
P_0c05017c: /* original 7e01, guest PC 0x0c05017c */
if(!s->budget--) { s->failed_pc=0x0c05017cu; return 0; }
r[14]+=0x00000001u;
goto P_0c05017e;
P_0c05017e: /* original bfd3, guest PC 0x0c05017e */
if(!s->budget--) { s->failed_pc=0x0c05017eu; return 0; }
target=0x0c050128u; r[16]=0x0c050182u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050182u) { target=s->pc; goto dispatch; }
goto P_0c050182;
P_0c050180: /* original 6403, guest PC 0x0c050180 */
if(!s->budget--) { s->failed_pc=0x0c050180u; return 0; }
r[4]=r[0];
goto P_0c050182;
P_0c050182: /* original 2800, guest PC 0x0c050182 */
if(!s->budget--) { s->failed_pc=0x0c050182u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c050184;
P_0c050184: /* original e064, guest PC 0x0c050184 */
if(!s->budget--) { s->failed_pc=0x0c050184u; return 0; }
r[0]=0x00000064u;
goto P_0c050186;
P_0c050186: /* original 61d1, guest PC 0x0c050186 */
if(!s->budget--) { s->failed_pc=0x0c050186u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[1]=tmp;
goto P_0c050188;
P_0c050188: /* original 68e3, guest PC 0x0c050188 */
if(!s->budget--) { s->failed_pc=0x0c050188u; return 0; }
r[8]=r[14];
goto P_0c05018a;
P_0c05018a: /* original d337, guest PC 0x0c05018a */
if(!s->budget--) { s->failed_pc=0x0c05018au; return 0; }
r[3]=read(ram,0x0c050268u,4);
goto P_0c05018c;
P_0c05018c: /* original 611d, guest PC 0x0c05018c */
if(!s->budget--) { s->failed_pc=0x0c05018cu; return 0; }
r[1]=r[1]&65535u;
goto P_0c05018e;
P_0c05018e: /* original 430b, guest PC 0x0c05018e */
if(!s->budget--) { s->failed_pc=0x0c05018eu; return 0; }
target=r[3];
r[16]=0x0c050192u;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050192u) { target=s->pc; goto dispatch; }
goto P_0c050192;
P_0c050190: /* original 7e01, guest PC 0x0c050190 */
if(!s->budget--) { s->failed_pc=0x0c050190u; return 0; }
r[14]+=0x00000001u;
goto P_0c050192;
P_0c050192: /* original bfc9, guest PC 0x0c050192 */
if(!s->budget--) { s->failed_pc=0x0c050192u; return 0; }
target=0x0c050128u; r[16]=0x0c050196u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050196u) { target=s->pc; goto dispatch; }
goto P_0c050196;
P_0c050194: /* original 6403, guest PC 0x0c050194 */
if(!s->budget--) { s->failed_pc=0x0c050194u; return 0; }
r[4]=r[0];
goto P_0c050196;
P_0c050196: /* original 2800, guest PC 0x0c050196 */
if(!s->budget--) { s->failed_pc=0x0c050196u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c050198;
P_0c050198: /* original 68e3, guest PC 0x0c050198 */
if(!s->budget--) { s->failed_pc=0x0c050198u; return 0; }
r[8]=r[14];
goto P_0c05019a;
P_0c05019a: /* original 84d2, guest PC 0x0c05019a */
if(!s->budget--) { s->failed_pc=0x0c05019au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c05019c;
P_0c05019c: /* original 640c, guest PC 0x0c05019c */
if(!s->budget--) { s->failed_pc=0x0c05019cu; return 0; }
r[4]=r[0]&255u;
goto P_0c05019e;
P_0c05019e: /* original bfc3, guest PC 0x0c05019e */
if(!s->budget--) { s->failed_pc=0x0c05019eu; return 0; }
target=0x0c050128u; r[16]=0x0c0501a2u;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501a2u) { target=s->pc; goto dispatch; }
goto P_0c0501a2;
P_0c0501a0: /* original 7e01, guest PC 0x0c0501a0 */
if(!s->budget--) { s->failed_pc=0x0c0501a0u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501a2;
P_0c0501a2: /* original 2800, guest PC 0x0c0501a2 */
if(!s->budget--) { s->failed_pc=0x0c0501a2u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501a4;
P_0c0501a4: /* original 68e3, guest PC 0x0c0501a4 */
if(!s->budget--) { s->failed_pc=0x0c0501a4u; return 0; }
r[8]=r[14];
goto P_0c0501a6;
P_0c0501a6: /* original 84d3, guest PC 0x0c0501a6 */
if(!s->budget--) { s->failed_pc=0x0c0501a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+3,1);
goto P_0c0501a8;
P_0c0501a8: /* original 640c, guest PC 0x0c0501a8 */
if(!s->budget--) { s->failed_pc=0x0c0501a8u; return 0; }
r[4]=r[0]&255u;
goto P_0c0501aa;
P_0c0501aa: /* original bfbd, guest PC 0x0c0501aa */
if(!s->budget--) { s->failed_pc=0x0c0501aau; return 0; }
target=0x0c050128u; r[16]=0x0c0501aeu;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501aeu) { target=s->pc; goto dispatch; }
goto P_0c0501ae;
P_0c0501ac: /* original 7e01, guest PC 0x0c0501ac */
if(!s->budget--) { s->failed_pc=0x0c0501acu; return 0; }
r[14]+=0x00000001u;
goto P_0c0501ae;
P_0c0501ae: /* original 2800, guest PC 0x0c0501ae */
if(!s->budget--) { s->failed_pc=0x0c0501aeu; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501b0;
P_0c0501b0: /* original 68e3, guest PC 0x0c0501b0 */
if(!s->budget--) { s->failed_pc=0x0c0501b0u; return 0; }
r[8]=r[14];
goto P_0c0501b2;
P_0c0501b2: /* original 84d4, guest PC 0x0c0501b2 */
if(!s->budget--) { s->failed_pc=0x0c0501b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c0501b4;
P_0c0501b4: /* original 640c, guest PC 0x0c0501b4 */
if(!s->budget--) { s->failed_pc=0x0c0501b4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0501b6;
P_0c0501b6: /* original bfb7, guest PC 0x0c0501b6 */
if(!s->budget--) { s->failed_pc=0x0c0501b6u; return 0; }
target=0x0c050128u; r[16]=0x0c0501bau;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501bau) { target=s->pc; goto dispatch; }
goto P_0c0501ba;
P_0c0501b8: /* original 7e01, guest PC 0x0c0501b8 */
if(!s->budget--) { s->failed_pc=0x0c0501b8u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501ba;
P_0c0501ba: /* original 2800, guest PC 0x0c0501ba */
if(!s->budget--) { s->failed_pc=0x0c0501bau; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501bc;
P_0c0501bc: /* original 68e3, guest PC 0x0c0501bc */
if(!s->budget--) { s->failed_pc=0x0c0501bcu; return 0; }
r[8]=r[14];
goto P_0c0501be;
P_0c0501be: /* original 84d5, guest PC 0x0c0501be */
if(!s->budget--) { s->failed_pc=0x0c0501beu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+5,1);
goto P_0c0501c0;
P_0c0501c0: /* original 640c, guest PC 0x0c0501c0 */
if(!s->budget--) { s->failed_pc=0x0c0501c0u; return 0; }
r[4]=r[0]&255u;
goto P_0c0501c2;
P_0c0501c2: /* original bfb1, guest PC 0x0c0501c2 */
if(!s->budget--) { s->failed_pc=0x0c0501c2u; return 0; }
target=0x0c050128u; r[16]=0x0c0501c6u;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501c6u) { target=s->pc; goto dispatch; }
goto P_0c0501c6;
P_0c0501c4: /* original 7e01, guest PC 0x0c0501c4 */
if(!s->budget--) { s->failed_pc=0x0c0501c4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501c6;
P_0c0501c6: /* original 2800, guest PC 0x0c0501c6 */
if(!s->budget--) { s->failed_pc=0x0c0501c6u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501c8;
P_0c0501c8: /* original 68e3, guest PC 0x0c0501c8 */
if(!s->budget--) { s->failed_pc=0x0c0501c8u; return 0; }
r[8]=r[14];
goto P_0c0501ca;
P_0c0501ca: /* original 84d6, guest PC 0x0c0501ca */
if(!s->budget--) { s->failed_pc=0x0c0501cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+6,1);
goto P_0c0501cc;
P_0c0501cc: /* original 640c, guest PC 0x0c0501cc */
if(!s->budget--) { s->failed_pc=0x0c0501ccu; return 0; }
r[4]=r[0]&255u;
goto P_0c0501ce;
P_0c0501ce: /* original bfab, guest PC 0x0c0501ce */
if(!s->budget--) { s->failed_pc=0x0c0501ceu; return 0; }
target=0x0c050128u; r[16]=0x0c0501d2u;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501d2u) { target=s->pc; goto dispatch; }
goto P_0c0501d2;
P_0c0501d0: /* original 7e01, guest PC 0x0c0501d0 */
if(!s->budget--) { s->failed_pc=0x0c0501d0u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501d2;
P_0c0501d2: /* original 2800, guest PC 0x0c0501d2 */
if(!s->budget--) { s->failed_pc=0x0c0501d2u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501d4;
P_0c0501d4: /* original 4f26, guest PC 0x0c0501d4 */
if(!s->budget--) { s->failed_pc=0x0c0501d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0501d6;
P_0c0501d6: /* original 84d7, guest PC 0x0c0501d6 */
if(!s->budget--) { s->failed_pc=0x0c0501d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+7,1);
goto P_0c0501d8;
P_0c0501d8: /* original d124, guest PC 0x0c0501d8 */
if(!s->budget--) { s->failed_pc=0x0c0501d8u; return 0; }
r[1]=read(ram,0x0c05026cu,4);
goto P_0c0501da;
P_0c0501da: /* original 600c, guest PC 0x0c0501da */
if(!s->budget--) { s->failed_pc=0x0c0501dau; return 0; }
r[0]=r[0]&255u;
goto P_0c0501dc;
P_0c0501dc: /* original c907, guest PC 0x0c0501dc */
if(!s->budget--) { s->failed_pc=0x0c0501dcu; return 0; }
r[0]&=7u;
goto P_0c0501de;
P_0c0501de: /* original 031c, guest PC 0x0c0501de */
if(!s->budget--) { s->failed_pc=0x0c0501deu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0501e0;
P_0c0501e0: /* original 2e30, guest PC 0x0c0501e0 */
if(!s->budget--) { s->failed_pc=0x0c0501e0u; return 0; }
write(ram,r[14],r[3],1);
goto P_0c0501e2;
P_0c0501e2: /* original 68f6, guest PC 0x0c0501e2 */
if(!s->budget--) { s->failed_pc=0x0c0501e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0501e4;
P_0c0501e4: /* original 6df6, guest PC 0x0c0501e4 */
if(!s->budget--) { s->failed_pc=0x0c0501e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0501e6;
P_0c0501e6: /* original 000b, guest PC 0x0c0501e6 */
if(!s->budget--) { s->failed_pc=0x0c0501e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0501e8: /* original 6ef6, guest PC 0x0c0501e8 */
if(!s->budget--) { s->failed_pc=0x0c0501e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0501eau,s,ram);
P_0c0501f4: /* original 4f22, guest PC 0x0c0501f4 */
if(!s->budget--) { s->failed_pc=0x0c0501f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0501f6;
P_0c0501f6: /* original 64e0, guest PC 0x0c0501f6 */
if(!s->budget--) { s->failed_pc=0x0c0501f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c0501f8;
P_0c0501f8: /* original 4f12, guest PC 0x0c0501f8 */
if(!s->budget--) { s->failed_pc=0x0c0501f8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0501fa;
P_0c0501fa: /* original bfa7, guest PC 0x0c0501fa */
if(!s->budget--) { s->failed_pc=0x0c0501fau; return 0; }
target=0x0c05014cu; r[16]=0x0c0501feu;
r[4]=r[4]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501feu) { target=s->pc; goto dispatch; }
goto P_0c0501fe;
P_0c0501fc: /* original 644c, guest PC 0x0c0501fc */
if(!s->budget--) { s->failed_pc=0x0c0501fcu; return 0; }
r[4]=r[4]&255u;
goto P_0c0501fe;
P_0c0501fe: /* original e264, guest PC 0x0c0501fe */
if(!s->budget--) { s->failed_pc=0x0c0501feu; return 0; }
r[2]=0x00000064u;
goto P_0c050200;
P_0c050200: /* original 202e, guest PC 0x0c050200 */
if(!s->budget--) { s->failed_pc=0x0c050200u; return 0; }
r[19]=(r[0]&65535u)*(r[2]&65535u);
goto P_0c050202;
P_0c050202: /* original 001a, guest PC 0x0c050202 */
if(!s->budget--) { s->failed_pc=0x0c050202u; return 0; }
r[0]=r[19];
goto P_0c050204;
P_0c050204: /* original 6803, guest PC 0x0c050204 */
if(!s->budget--) { s->failed_pc=0x0c050204u; return 0; }
r[8]=r[0];
goto P_0c050206;
P_0c050206: /* original 84e1, guest PC 0x0c050206 */
if(!s->budget--) { s->failed_pc=0x0c050206u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c050208;
P_0c050208: /* original bfa0, guest PC 0x0c050208 */
if(!s->budget--) { s->failed_pc=0x0c050208u; return 0; }
target=0x0c05014cu; r[16]=0x0c05020cu;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05020cu) { target=s->pc; goto dispatch; }
goto P_0c05020c;
P_0c05020a: /* original 640c, guest PC 0x0c05020a */
if(!s->budget--) { s->failed_pc=0x0c05020au; return 0; }
r[4]=r[0]&255u;
goto P_0c05020c;
P_0c05020c: /* original 380c, guest PC 0x0c05020c */
if(!s->budget--) { s->failed_pc=0x0c05020cu; return 0; }
r[8]+=r[0];
goto P_0c05020e;
P_0c05020e: /* original 2d81, guest PC 0x0c05020e */
if(!s->budget--) { s->failed_pc=0x0c05020eu; return 0; }
write(ram,r[13],r[8],2);
goto P_0c050210;
P_0c050210: /* original 84e2, guest PC 0x0c050210 */
if(!s->budget--) { s->failed_pc=0x0c050210u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c050212;
P_0c050212: /* original bf9b, guest PC 0x0c050212 */
if(!s->budget--) { s->failed_pc=0x0c050212u; return 0; }
target=0x0c05014cu; r[16]=0x0c050216u;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050216u) { target=s->pc; goto dispatch; }
goto P_0c050216;
P_0c050214: /* original 640c, guest PC 0x0c050214 */
if(!s->budget--) { s->failed_pc=0x0c050214u; return 0; }
r[4]=r[0]&255u;
goto P_0c050216;
P_0c050216: /* original 80d2, guest PC 0x0c050216 */
if(!s->budget--) { s->failed_pc=0x0c050216u; return 0; }
write(ram,r[13]+2,r[0],1);
goto P_0c050218;
P_0c050218: /* original 84e3, guest PC 0x0c050218 */
if(!s->budget--) { s->failed_pc=0x0c050218u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c05021a;
P_0c05021a: /* original bf97, guest PC 0x0c05021a */
if(!s->budget--) { s->failed_pc=0x0c05021au; return 0; }
target=0x0c05014cu; r[16]=0x0c05021eu;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05021eu) { target=s->pc; goto dispatch; }
goto P_0c05021e;
P_0c05021c: /* original 640c, guest PC 0x0c05021c */
if(!s->budget--) { s->failed_pc=0x0c05021cu; return 0; }
r[4]=r[0]&255u;
goto P_0c05021e;
P_0c05021e: /* original 80d3, guest PC 0x0c05021e */
if(!s->budget--) { s->failed_pc=0x0c05021eu; return 0; }
write(ram,r[13]+3,r[0],1);
goto P_0c050220;
P_0c050220: /* original 84e4, guest PC 0x0c050220 */
if(!s->budget--) { s->failed_pc=0x0c050220u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c050222;
P_0c050222: /* original bf93, guest PC 0x0c050222 */
if(!s->budget--) { s->failed_pc=0x0c050222u; return 0; }
target=0x0c05014cu; r[16]=0x0c050226u;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050226u) { target=s->pc; goto dispatch; }
goto P_0c050226;
P_0c050224: /* original 640c, guest PC 0x0c050224 */
if(!s->budget--) { s->failed_pc=0x0c050224u; return 0; }
r[4]=r[0]&255u;
goto P_0c050226;
P_0c050226: /* original 80d4, guest PC 0x0c050226 */
if(!s->budget--) { s->failed_pc=0x0c050226u; return 0; }
write(ram,r[13]+4,r[0],1);
goto P_0c050228;
P_0c050228: /* original 84e5, guest PC 0x0c050228 */
if(!s->budget--) { s->failed_pc=0x0c050228u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+5,1);
goto P_0c05022a;
P_0c05022a: /* original bf8f, guest PC 0x0c05022a */
if(!s->budget--) { s->failed_pc=0x0c05022au; return 0; }
target=0x0c05014cu; r[16]=0x0c05022eu;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05022eu) { target=s->pc; goto dispatch; }
goto P_0c05022e;
P_0c05022c: /* original 640c, guest PC 0x0c05022c */
if(!s->budget--) { s->failed_pc=0x0c05022cu; return 0; }
r[4]=r[0]&255u;
goto P_0c05022e;
P_0c05022e: /* original 80d5, guest PC 0x0c05022e */
if(!s->budget--) { s->failed_pc=0x0c05022eu; return 0; }
write(ram,r[13]+5,r[0],1);
goto P_0c050230;
P_0c050230: /* original 84e6, guest PC 0x0c050230 */
if(!s->budget--) { s->failed_pc=0x0c050230u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+6,1);
goto P_0c050232;
P_0c050232: /* original bf8b, guest PC 0x0c050232 */
if(!s->budget--) { s->failed_pc=0x0c050232u; return 0; }
target=0x0c05014cu; r[16]=0x0c050236u;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050236u) { target=s->pc; goto dispatch; }
goto P_0c050236;
P_0c050234: /* original 640c, guest PC 0x0c050234 */
if(!s->budget--) { s->failed_pc=0x0c050234u; return 0; }
r[4]=r[0]&255u;
goto P_0c050236;
P_0c050236: /* original 4f16, guest PC 0x0c050236 */
if(!s->budget--) { s->failed_pc=0x0c050236u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c050238;
P_0c050238: /* original 80d6, guest PC 0x0c050238 */
if(!s->budget--) { s->failed_pc=0x0c050238u; return 0; }
write(ram,r[13]+6,r[0],1);
goto P_0c05023a;
P_0c05023a: /* original 84e7, guest PC 0x0c05023a */
if(!s->budget--) { s->failed_pc=0x0c05023au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c05023c;
P_0c05023c: /* original 4f26, guest PC 0x0c05023c */
if(!s->budget--) { s->failed_pc=0x0c05023cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05023e;
P_0c05023e: /* original d10c, guest PC 0x0c05023e */
if(!s->budget--) { s->failed_pc=0x0c05023eu; return 0; }
r[1]=read(ram,0x0c050270u,4);
goto P_0c050240;
P_0c050240: /* original 600c, guest PC 0x0c050240 */
if(!s->budget--) { s->failed_pc=0x0c050240u; return 0; }
r[0]=r[0]&255u;
goto P_0c050242;
P_0c050242: /* original c907, guest PC 0x0c050242 */
if(!s->budget--) { s->failed_pc=0x0c050242u; return 0; }
r[0]&=7u;
goto P_0c050244;
P_0c050244: /* original 001c, guest PC 0x0c050244 */
if(!s->budget--) { s->failed_pc=0x0c050244u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c050246;
P_0c050246: /* original 80d7, guest PC 0x0c050246 */
if(!s->budget--) { s->failed_pc=0x0c050246u; return 0; }
write(ram,r[13]+7,r[0],1);
goto P_0c050248;
P_0c050248: /* original 68f6, guest PC 0x0c050248 */
if(!s->budget--) { s->failed_pc=0x0c050248u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05024a;
P_0c05024a: /* original 6df6, guest PC 0x0c05024a */
if(!s->budget--) { s->failed_pc=0x0c05024au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05024c;
P_0c05024c: /* original 000b, guest PC 0x0c05024c */
if(!s->budget--) { s->failed_pc=0x0c05024cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05024e: /* original 6ef6, guest PC 0x0c05024e */
if(!s->budget--) { s->failed_pc=0x0c05024eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c050250u,s,ram);
P_0c051b7e: /* original fc0b, guest PC 0x0c051b7e */
if(!s->budget--) { s->failed_pc=0x0c051b7eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[12]);
goto P_0c051b80;
P_0c051b80: /* original e000, guest PC 0x0c051b80 */
if(!s->budget--) { s->failed_pc=0x0c051b80u; return 0; }
r[0]=0x00000000u;
goto P_0c051b82;
P_0c051b82: /* original fcbb, guest PC 0x0c051b82 */
if(!s->budget--) { s->failed_pc=0x0c051b82u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,11,r[12]);
goto P_0c051b84;
P_0c051b84: /* original 7cfc, guest PC 0x0c051b84 */
if(!s->budget--) { s->failed_pc=0x0c051b84u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c051b86;
P_0c051b86: /* original 2c06, guest PC 0x0c051b86 */
if(!s->budget--) { s->failed_pc=0x0c051b86u; return 0; }
r[12]-=4; write(ram,r[12],r[0],4);
goto P_0c051b88;
P_0c051b88: /* original fc6b, guest PC 0x0c051b88 */
if(!s->budget--) { s->failed_pc=0x0c051b88u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c051b8a;
P_0c051b8a: /* original fc5b, guest PC 0x0c051b8a */
if(!s->budget--) { s->failed_pc=0x0c051b8au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c051b8c;
P_0c051b8c: /* original fc4b, guest PC 0x0c051b8c */
if(!s->budget--) { s->failed_pc=0x0c051b8cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c051b8e;
P_0c051b8e: /* original 2c46, guest PC 0x0c051b8e */
if(!s->budget--) { s->failed_pc=0x0c051b8eu; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c051b90;
P_0c051b90: /* original 0c83, guest PC 0x0c051b90 */
if(!s->budget--) { s->failed_pc=0x0c051b90u; return 0; }
goto P_0c051b92;
P_0c051b92: /* original 4f26, guest PC 0x0c051b92 */
if(!s->budget--) { s->failed_pc=0x0c051b92u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c051b94;
P_0c051b94: /* original 000b, guest PC 0x0c051b94 */
if(!s->budget--) { s->failed_pc=0x0c051b94u; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c051b96: /* original 7c20, guest PC 0x0c051b96 */
if(!s->budget--) { s->failed_pc=0x0c051b96u; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c051b98u,s,ram);
P_0c0521b6: /* original fc0b, guest PC 0x0c0521b6 */
if(!s->budget--) { s->failed_pc=0x0c0521b6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[12]);
goto P_0c0521b8;
P_0c0521b8: /* original fcbb, guest PC 0x0c0521b8 */
if(!s->budget--) { s->failed_pc=0x0c0521b8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,11,r[12]);
goto P_0c0521ba;
P_0c0521ba: /* original fc9b, guest PC 0x0c0521ba */
if(!s->budget--) { s->failed_pc=0x0c0521bau; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c0521bc;
P_0c0521bc: /* original fc8b, guest PC 0x0c0521bc */
if(!s->budget--) { s->failed_pc=0x0c0521bcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c0521be;
P_0c0521be: /* original fc6b, guest PC 0x0c0521be */
if(!s->budget--) { s->failed_pc=0x0c0521beu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c0521c0;
P_0c0521c0: /* original fc5b, guest PC 0x0c0521c0 */
if(!s->budget--) { s->failed_pc=0x0c0521c0u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c0521c2;
P_0c0521c2: /* original fc4b, guest PC 0x0c0521c2 */
if(!s->budget--) { s->failed_pc=0x0c0521c2u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c0521c4;
P_0c0521c4: /* original 2c46, guest PC 0x0c0521c4 */
if(!s->budget--) { s->failed_pc=0x0c0521c4u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c0521c6;
P_0c0521c6: /* original 0c83, guest PC 0x0c0521c6 */
if(!s->budget--) { s->failed_pc=0x0c0521c6u; return 0; }
goto P_0c0521c8;
P_0c0521c8: /* original 4f26, guest PC 0x0c0521c8 */
if(!s->budget--) { s->failed_pc=0x0c0521c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0521ca;
P_0c0521ca: /* original 000b, guest PC 0x0c0521ca */
if(!s->budget--) { s->failed_pc=0x0c0521cau; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c0521cc: /* original 7c20, guest PC 0x0c0521cc */
if(!s->budget--) { s->failed_pc=0x0c0521ccu; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c0521ceu,s,ram);
P_0c05283a: /* original fc0b, guest PC 0x0c05283a */
if(!s->budget--) { s->failed_pc=0x0c05283au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[12]);
goto P_0c05283c;
P_0c05283c: /* original fcbb, guest PC 0x0c05283c */
if(!s->budget--) { s->failed_pc=0x0c05283cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,11,r[12]);
goto P_0c05283e;
P_0c05283e: /* original 7cfc, guest PC 0x0c05283e */
if(!s->budget--) { s->failed_pc=0x0c05283eu; return 0; }
r[12]+=0xfffffffcu;
goto P_0c052840;
P_0c052840: /* original 2c16, guest PC 0x0c052840 */
if(!s->budget--) { s->failed_pc=0x0c052840u; return 0; }
r[12]-=4; write(ram,r[12],r[1],4);
goto P_0c052842;
P_0c052842: /* original fc6b, guest PC 0x0c052842 */
if(!s->budget--) { s->failed_pc=0x0c052842u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c052844;
P_0c052844: /* original fc5b, guest PC 0x0c052844 */
if(!s->budget--) { s->failed_pc=0x0c052844u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c052846;
P_0c052846: /* original fc4b, guest PC 0x0c052846 */
if(!s->budget--) { s->failed_pc=0x0c052846u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c052848;
P_0c052848: /* original 2c46, guest PC 0x0c052848 */
if(!s->budget--) { s->failed_pc=0x0c052848u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c05284a;
P_0c05284a: /* original 0c83, guest PC 0x0c05284a */
if(!s->budget--) { s->failed_pc=0x0c05284au; return 0; }
goto P_0c05284c;
P_0c05284c: /* original 4f26, guest PC 0x0c05284c */
if(!s->budget--) { s->failed_pc=0x0c05284cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05284e;
P_0c05284e: /* original 000b, guest PC 0x0c05284e */
if(!s->budget--) { s->failed_pc=0x0c05284eu; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c052850: /* original 7c20, guest PC 0x0c052850 */
if(!s->budget--) { s->failed_pc=0x0c052850u; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c052852u,s,ram);
P_0c05344c: /* original 000b, guest PC 0x0c05344c */
if(!s->budget--) { s->failed_pc=0x0c05344cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05344e: /* original 0009, guest PC 0x0c05344e */
if(!s->budget--) { s->failed_pc=0x0c05344eu; return 0; }
return vf3_matrix_family(0x0c053450u,s,ram);
P_0c0563ac: /* original f10b, guest PC 0x0c0563ac */
if(!s->budget--) { s->failed_pc=0x0c0563acu; return 0; }
r[1]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[1]);
goto P_0c0563ae;
P_0c0563ae: /* original 0009, guest PC 0x0c0563ae */
if(!s->budget--) { s->failed_pc=0x0c0563aeu; return 0; }
goto P_0c0563b0;
P_0c0563b0: /* original 0009, guest PC 0x0c0563b0 */
if(!s->budget--) { s->failed_pc=0x0c0563b0u; return 0; }
goto P_0c0563b2;
P_0c0563b2: /* original 0009, guest PC 0x0c0563b2 */
if(!s->budget--) { s->failed_pc=0x0c0563b2u; return 0; }
goto P_0c0563b4;
P_0c0563b4: /* original 0009, guest PC 0x0c0563b4 */
if(!s->budget--) { s->failed_pc=0x0c0563b4u; return 0; }
goto P_0c0563b6;
P_0c0563b6: /* original 0009, guest PC 0x0c0563b6 */
if(!s->budget--) { s->failed_pc=0x0c0563b6u; return 0; }
goto P_0c0563b8;
P_0c0563b8: /* original 0009, guest PC 0x0c0563b8 */
if(!s->budget--) { s->failed_pc=0x0c0563b8u; return 0; }
goto P_0c0563ba;
P_0c0563ba: /* original 0009, guest PC 0x0c0563ba */
if(!s->budget--) { s->failed_pc=0x0c0563bau; return 0; }
goto P_0c0563bc;
P_0c0563bc: /* original 0009, guest PC 0x0c0563bc */
if(!s->budget--) { s->failed_pc=0x0c0563bcu; return 0; }
goto P_0c0563be;
P_0c0563be: /* original 0009, guest PC 0x0c0563be */
if(!s->budget--) { s->failed_pc=0x0c0563beu; return 0; }
goto P_0c0563c0;
P_0c0563c0: /* original d250, guest PC 0x0c0563c0 */
if(!s->budget--) { s->failed_pc=0x0c0563c0u; return 0; }
r[2]=read(ram,0x0c056504u,4);
goto P_0c0563c2;
P_0c0563c2: /* original c751, guest PC 0x0c0563c2 */
if(!s->budget--) { s->failed_pc=0x0c0563c2u; return 0; }
r[0]=0x0c056508u;
goto P_0c0563c4;
P_0c0563c4: /* original 7404, guest PC 0x0c0563c4 */
if(!s->budget--) { s->failed_pc=0x0c0563c4u; return 0; }
r[4]+=0x00000004u;
goto P_0c0563c6;
P_0c0563c6: /* original f708, guest PC 0x0c0563c6 */
if(!s->budget--) { s->failed_pc=0x0c0563c6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0563c8;
P_0c0563c8: /* original d151, guest PC 0x0c0563c8 */
if(!s->budget--) { s->failed_pc=0x0c0563c8u; return 0; }
r[1]=read(ram,0x0c056510u,4);
goto P_0c0563ca;
P_0c0563ca: /* original f429, guest PC 0x0c0563ca */
if(!s->budget--) { s->failed_pc=0x0c0563cau; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0563cc;
P_0c0563cc: /* original f529, guest PC 0x0c0563cc */
if(!s->budget--) { s->failed_pc=0x0c0563ccu; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0563ce;
P_0c0563ce: /* original f628, guest PC 0x0c0563ce */
if(!s->budget--) { s->failed_pc=0x0c0563ceu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c0563d0;
P_0c0563d0: /* original 6545, guest PC 0x0c0563d0 */
if(!s->budget--) { s->failed_pc=0x0c0563d0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]+=2;
r[5]=tmp;
goto P_0c0563d2;
P_0c0563d2: /* original f472, guest PC 0x0c0563d2 */
if(!s->budget--) { s->failed_pc=0x0c0563d2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c0563d4;
P_0c0563d4: /* original 6645, guest PC 0x0c0563d4 */
if(!s->budget--) { s->failed_pc=0x0c0563d4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]+=2;
r[6]=tmp;
goto P_0c0563d6;
P_0c0563d6: /* original f572, guest PC 0x0c0563d6 */
if(!s->budget--) { s->failed_pc=0x0c0563d6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0563d8;
P_0c0563d8: /* original 625c, guest PC 0x0c0563d8 */
if(!s->budget--) { s->failed_pc=0x0c0563d8u; return 0; }
r[2]=r[5]&255u;
goto P_0c0563da;
P_0c0563da: /* original f672, guest PC 0x0c0563da */
if(!s->budget--) { s->failed_pc=0x0c0563dau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0563dc;
P_0c0563dc: /* original 425a, guest PC 0x0c0563dc */
if(!s->budget--) { s->failed_pc=0x0c0563dcu; return 0; }
r[53]=r[2];
goto P_0c0563de;
P_0c0563de: /* original f02d, guest PC 0x0c0563de */
if(!s->budget--) { s->failed_pc=0x0c0563deu; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c0563e0;
P_0c0563e0: /* original 4519, guest PC 0x0c0563e0 */
if(!s->budget--) { s->failed_pc=0x0c0563e0u; return 0; }
r[5]>>=8;
goto P_0c0563e2;
P_0c0563e2: /* original 655c, guest PC 0x0c0563e2 */
if(!s->budget--) { s->failed_pc=0x0c0563e2u; return 0; }
r[5]=r[5]&255u;
goto P_0c0563e4;
P_0c0563e4: /* original f062, guest PC 0x0c0563e4 */
if(!s->budget--) { s->failed_pc=0x0c0563e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[6],r[18],'*');
goto P_0c0563e6;
P_0c0563e6: /* original 455a, guest PC 0x0c0563e6 */
if(!s->budget--) { s->failed_pc=0x0c0563e6u; return 0; }
r[53]=r[5];
goto P_0c0563e8;
P_0c0563e8: /* original f12d, guest PC 0x0c0563e8 */
if(!s->budget--) { s->failed_pc=0x0c0563e8u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c0563ea;
P_0c0563ea: /* original 666c, guest PC 0x0c0563ea */
if(!s->budget--) { s->failed_pc=0x0c0563eau; return 0; }
r[6]=r[6]&255u;
goto P_0c0563ec;
P_0c0563ec: /* original 465a, guest PC 0x0c0563ec */
if(!s->budget--) { s->failed_pc=0x0c0563ecu; return 0; }
r[53]=r[6];
goto P_0c0563ee;
P_0c0563ee: /* original f22d, guest PC 0x0c0563ee */
if(!s->budget--) { s->failed_pc=0x0c0563eeu; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0563f0;
P_0c0563f0: /* original f152, guest PC 0x0c0563f0 */
if(!s->budget--) { s->failed_pc=0x0c0563f0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c0563f2;
P_0c0563f2: /* original f10a, guest PC 0x0c0563f2 */
if(!s->budget--) { s->failed_pc=0x0c0563f2u; return 0; }
vf3_matrix_store(s,ram,0,r[1]);
goto P_0c0563f4;
P_0c0563f4: /* original f242, guest PC 0x0c0563f4 */
if(!s->budget--) { s->failed_pc=0x0c0563f4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0563f6;
P_0c0563f6: /* original f11b, guest PC 0x0c0563f6 */
if(!s->budget--) { s->failed_pc=0x0c0563f6u; return 0; }
r[1]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[1]);
goto P_0c0563f8;
P_0c0563f8: /* original 000b, guest PC 0x0c0563f8 */
if(!s->budget--) { s->failed_pc=0x0c0563f8u; return 0; }
target=r[16];
r[1]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[1]);
s->pc=target; return ram->oob==0;
P_0c0563fa: /* original f12b, guest PC 0x0c0563fa */
if(!s->budget--) { s->failed_pc=0x0c0563fau; return 0; }
r[1]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[1]);
return vf3_matrix_family(0x0c0563fcu,s,ram);
P_0c058500: /* original fefc, guest PC 0x0c058500 */
if(!s->budget--) { s->failed_pc=0x0c058500u; return 0; }
vf3_matrix_move(s,14,15);
goto P_0c058502;
P_0c058502: /* original 6025, guest PC 0x0c058502 */
if(!s->budget--) { s->failed_pc=0x0c058502u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[0]=tmp;
goto P_0c058504;
P_0c058504: /* original 7c0c, guest PC 0x0c058504 */
if(!s->budget--) { s->failed_pc=0x0c058504u; return 0; }
r[12]+=0x0000000cu;
goto P_0c058506;
P_0c058506: /* original f059, guest PC 0x0c058506 */
if(!s->budget--) { s->failed_pc=0x0c058506u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c058508;
P_0c058508: /* original f3fd, guest PC 0x0c058508 */
if(!s->budget--) { s->failed_pc=0x0c058508u; return 0; }
r[18]^=0x100000u;
goto P_0c05850a;
P_0c05850a: /* original 6121, guest PC 0x0c05850a */
if(!s->budget--) { s->failed_pc=0x0c05850au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c05850c;
P_0c05850c: /* original f258, guest PC 0x0c05850c */
if(!s->budget--) { s->failed_pc=0x0c05850cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c05850e;
P_0c05850e: /* original 405a, guest PC 0x0c05850e */
if(!s->budget--) { s->failed_pc=0x0c05850eu; return 0; }
r[53]=r[0];
goto P_0c058510;
P_0c058510: /* original f42d, guest PC 0x0c058510 */
if(!s->budget--) { s->failed_pc=0x0c058510u; return 0; }
fr[4]=vf3_fpu_float(r[53],r[18]);
goto P_0c058512;
P_0c058512: /* original 415a, guest PC 0x0c058512 */
if(!s->budget--) { s->failed_pc=0x0c058512u; return 0; }
r[53]=r[1];
goto P_0c058514;
P_0c058514: /* original f52d, guest PC 0x0c058514 */
if(!s->budget--) { s->failed_pc=0x0c058514u; return 0; }
fr[5]=vf3_fpu_float(r[53],r[18]);
goto P_0c058516;
P_0c058516: /* original fc2a, guest PC 0x0c058516 */
if(!s->budget--) { s->failed_pc=0x0c058516u; return 0; }
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c058518;
P_0c058518: /* original e010, guest PC 0x0c058518 */
if(!s->budget--) { s->failed_pc=0x0c058518u; return 0; }
r[0]=0x00000010u;
goto P_0c05851a;
P_0c05851a: /* original fc1b, guest PC 0x0c05851a */
if(!s->budget--) { s->failed_pc=0x0c05851au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[12]);
goto P_0c05851c;
P_0c05851c: /* original f4f2, guest PC 0x0c05851c */
if(!s->budget--) { s->failed_pc=0x0c05851cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c05851e;
P_0c05851e: /* original fc0b, guest PC 0x0c05851e */
if(!s->budget--) { s->failed_pc=0x0c05851eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[12]);
goto P_0c058520;
P_0c058520: /* original f5f2, guest PC 0x0c058520 */
if(!s->budget--) { s->failed_pc=0x0c058520u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'*');
goto P_0c058522;
P_0c058522: /* original f3fd, guest PC 0x0c058522 */
if(!s->budget--) { s->failed_pc=0x0c058522u; return 0; }
r[18]^=0x100000u;
goto P_0c058524;
P_0c058524: /* original 2cc6, guest PC 0x0c058524 */
if(!s->budget--) { s->failed_pc=0x0c058524u; return 0; }
tmp=r[12]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c058526;
P_0c058526: /* original 000b, guest PC 0x0c058526 */
if(!s->budget--) { s->failed_pc=0x0c058526u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c058528: /* original fc47, guest PC 0x0c058528 */
if(!s->budget--) { s->failed_pc=0x0c058528u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
return vf3_matrix_family(0x0c05852au,s,ram);
P_0c05865c: /* original 7504, guest PC 0x0c05865c */
if(!s->budget--) { s->failed_pc=0x0c05865cu; return 0; }
r[5]+=0x00000004u;
goto P_0c05865e;
P_0c05865e: /* original 6055, guest PC 0x0c05865e */
if(!s->budget--) { s->failed_pc=0x0c05865eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[0]=tmp;
goto P_0c058660;
P_0c058660: /* original 6155, guest PC 0x0c058660 */
if(!s->budget--) { s->failed_pc=0x0c058660u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[1]=tmp;
goto P_0c058662;
P_0c058662: /* original 6255, guest PC 0x0c058662 */
if(!s->budget--) { s->failed_pc=0x0c058662u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[2]=tmp;
goto P_0c058664;
P_0c058664: /* original f38d, guest PC 0x0c058664 */
if(!s->budget--) { s->failed_pc=0x0c058664u; return 0; }
fr[3]=0;
goto P_0c058666;
P_0c058666: /* original 4028, guest PC 0x0c058666 */
if(!s->budget--) { s->failed_pc=0x0c058666u; return 0; }
r[0]<<=16;
goto P_0c058668;
P_0c058668: /* original 405a, guest PC 0x0c058668 */
if(!s->budget--) { s->failed_pc=0x0c058668u; return 0; }
r[53]=r[0];
goto P_0c05866a;
P_0c05866a: /* original 4128, guest PC 0x0c05866a */
if(!s->budget--) { s->failed_pc=0x0c05866au; return 0; }
r[1]<<=16;
goto P_0c05866c;
P_0c05866c: /* original f00d, guest PC 0x0c05866c */
if(!s->budget--) { s->failed_pc=0x0c05866cu; return 0; }
fr[0]=r[53];
goto P_0c05866e;
P_0c05866e: /* original 4228, guest PC 0x0c05866e */
if(!s->budget--) { s->failed_pc=0x0c05866eu; return 0; }
r[2]<<=16;
goto P_0c058670;
P_0c058670: /* original 415a, guest PC 0x0c058670 */
if(!s->budget--) { s->failed_pc=0x0c058670u; return 0; }
r[53]=r[1];
goto P_0c058672;
P_0c058672: /* original f10d, guest PC 0x0c058672 */
if(!s->budget--) { s->failed_pc=0x0c058672u; return 0; }
fr[1]=r[53];
goto P_0c058674;
P_0c058674: /* original 425a, guest PC 0x0c058674 */
if(!s->budget--) { s->failed_pc=0x0c058674u; return 0; }
r[53]=r[2];
goto P_0c058676;
P_0c058676: /* original f20d, guest PC 0x0c058676 */
if(!s->budget--) { s->failed_pc=0x0c058676u; return 0; }
fr[2]=r[53];
goto P_0c058678;
P_0c058678: /* original f1fd, guest PC 0x0c058678 */
if(!s->budget--) { s->failed_pc=0x0c058678u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c05867a;
P_0c05867a: /* original 6055, guest PC 0x0c05867a */
if(!s->budget--) { s->failed_pc=0x0c05867au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[0]=tmp;
goto P_0c05867c;
P_0c05867c: /* original 6155, guest PC 0x0c05867c */
if(!s->budget--) { s->failed_pc=0x0c05867cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[1]=tmp;
goto P_0c05867e;
P_0c05867e: /* original 6255, guest PC 0x0c05867e */
if(!s->budget--) { s->failed_pc=0x0c05867eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[2]=tmp;
goto P_0c058680;
P_0c058680: /* original f78d, guest PC 0x0c058680 */
if(!s->budget--) { s->failed_pc=0x0c058680u; return 0; }
fr[7]=0;
goto P_0c058682;
P_0c058682: /* original 4028, guest PC 0x0c058682 */
if(!s->budget--) { s->failed_pc=0x0c058682u; return 0; }
r[0]<<=16;
goto P_0c058684;
P_0c058684: /* original 405a, guest PC 0x0c058684 */
if(!s->budget--) { s->failed_pc=0x0c058684u; return 0; }
r[53]=r[0];
goto P_0c058686;
P_0c058686: /* original 4128, guest PC 0x0c058686 */
if(!s->budget--) { s->failed_pc=0x0c058686u; return 0; }
r[1]<<=16;
goto P_0c058688;
P_0c058688: /* original f40d, guest PC 0x0c058688 */
if(!s->budget--) { s->failed_pc=0x0c058688u; return 0; }
fr[4]=r[53];
goto P_0c05868a;
P_0c05868a: /* original 4228, guest PC 0x0c05868a */
if(!s->budget--) { s->failed_pc=0x0c05868au; return 0; }
r[2]<<=16;
goto P_0c05868c;
P_0c05868c: /* original 415a, guest PC 0x0c05868c */
if(!s->budget--) { s->failed_pc=0x0c05868cu; return 0; }
r[53]=r[1];
goto P_0c05868e;
P_0c05868e: /* original f50d, guest PC 0x0c05868e */
if(!s->budget--) { s->failed_pc=0x0c05868eu; return 0; }
fr[5]=r[53];
goto P_0c058690;
P_0c058690: /* original 425a, guest PC 0x0c058690 */
if(!s->budget--) { s->failed_pc=0x0c058690u; return 0; }
r[53]=r[2];
goto P_0c058692;
P_0c058692: /* original f60d, guest PC 0x0c058692 */
if(!s->budget--) { s->failed_pc=0x0c058692u; return 0; }
fr[6]=r[53];
goto P_0c058694;
P_0c058694: /* original f5fd, guest PC 0x0c058694 */
if(!s->budget--) { s->failed_pc=0x0c058694u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c058696;
P_0c058696: /* original 6055, guest PC 0x0c058696 */
if(!s->budget--) { s->failed_pc=0x0c058696u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[0]=tmp;
goto P_0c058698;
P_0c058698: /* original 6155, guest PC 0x0c058698 */
if(!s->budget--) { s->failed_pc=0x0c058698u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[1]=tmp;
goto P_0c05869a;
P_0c05869a: /* original 6255, guest PC 0x0c05869a */
if(!s->budget--) { s->failed_pc=0x0c05869au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[2]=tmp;
goto P_0c05869c;
P_0c05869c: /* original fb8d, guest PC 0x0c05869c */
if(!s->budget--) { s->failed_pc=0x0c05869cu; return 0; }
fr[11]=0;
goto P_0c05869e;
P_0c05869e: /* original 4028, guest PC 0x0c05869e */
if(!s->budget--) { s->failed_pc=0x0c05869eu; return 0; }
r[0]<<=16;
goto P_0c0586a0;
P_0c0586a0: /* original 405a, guest PC 0x0c0586a0 */
if(!s->budget--) { s->failed_pc=0x0c0586a0u; return 0; }
r[53]=r[0];
goto P_0c0586a2;
P_0c0586a2: /* original 4128, guest PC 0x0c0586a2 */
if(!s->budget--) { s->failed_pc=0x0c0586a2u; return 0; }
r[1]<<=16;
goto P_0c0586a4;
P_0c0586a4: /* original f80d, guest PC 0x0c0586a4 */
if(!s->budget--) { s->failed_pc=0x0c0586a4u; return 0; }
fr[8]=r[53];
goto P_0c0586a6;
P_0c0586a6: /* original 4228, guest PC 0x0c0586a6 */
if(!s->budget--) { s->failed_pc=0x0c0586a6u; return 0; }
r[2]<<=16;
goto P_0c0586a8;
P_0c0586a8: /* original 415a, guest PC 0x0c0586a8 */
if(!s->budget--) { s->failed_pc=0x0c0586a8u; return 0; }
r[53]=r[1];
goto P_0c0586aa;
P_0c0586aa: /* original f90d, guest PC 0x0c0586aa */
if(!s->budget--) { s->failed_pc=0x0c0586aau; return 0; }
fr[9]=r[53];
goto P_0c0586ac;
P_0c0586ac: /* original 425a, guest PC 0x0c0586ac */
if(!s->budget--) { s->failed_pc=0x0c0586acu; return 0; }
r[53]=r[2];
goto P_0c0586ae;
P_0c0586ae: /* original fa0d, guest PC 0x0c0586ae */
if(!s->budget--) { s->failed_pc=0x0c0586aeu; return 0; }
fr[10]=r[53];
goto P_0c0586b0;
P_0c0586b0: /* original f9fd, guest PC 0x0c0586b0 */
if(!s->budget--) { s->failed_pc=0x0c0586b0u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c0586b2;
P_0c0586b2: /* original fcdc, guest PC 0x0c0586b2 */
if(!s->budget--) { s->failed_pc=0x0c0586b2u; return 0; }
vf3_matrix_move(s,12,13);
goto P_0c0586b4;
P_0c0586b4: /* original fefc, guest PC 0x0c0586b4 */
if(!s->budget--) { s->failed_pc=0x0c0586b4u; return 0; }
vf3_matrix_move(s,14,15);
goto P_0c0586b6;
P_0c0586b6: /* original f3fd, guest PC 0x0c0586b6 */
if(!s->budget--) { s->failed_pc=0x0c0586b6u; return 0; }
r[18]^=0x100000u;
goto P_0c0586b8;
P_0c0586b8: /* original f11d, guest PC 0x0c0586b8 */
if(!s->budget--) { s->failed_pc=0x0c0586b8u; return 0; }
r[53]=fr[1];
goto P_0c0586ba;
P_0c0586ba: /* original f14c, guest PC 0x0c0586ba */
if(!s->budget--) { s->failed_pc=0x0c0586bau; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0586bc;
P_0c0586bc: /* original f40d, guest PC 0x0c0586bc */
if(!s->budget--) { s->failed_pc=0x0c0586bcu; return 0; }
fr[4]=r[53];
goto P_0c0586be;
P_0c0586be: /* original f21d, guest PC 0x0c0586be */
if(!s->budget--) { s->failed_pc=0x0c0586beu; return 0; }
r[53]=fr[2];
goto P_0c0586c0;
P_0c0586c0: /* original f28c, guest PC 0x0c0586c0 */
if(!s->budget--) { s->failed_pc=0x0c0586c0u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c0586c2;
P_0c0586c2: /* original f80d, guest PC 0x0c0586c2 */
if(!s->budget--) { s->failed_pc=0x0c0586c2u; return 0; }
fr[8]=r[53];
goto P_0c0586c4;
P_0c0586c4: /* original f61d, guest PC 0x0c0586c4 */
if(!s->budget--) { s->failed_pc=0x0c0586c4u; return 0; }
r[53]=fr[6];
goto P_0c0586c6;
P_0c0586c6: /* original f69c, guest PC 0x0c0586c6 */
if(!s->budget--) { s->failed_pc=0x0c0586c6u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c0586c8;
P_0c0586c8: /* original f90d, guest PC 0x0c0586c8 */
if(!s->budget--) { s->failed_pc=0x0c0586c8u; return 0; }
fr[9]=r[53];
goto P_0c0586ca;
P_0c0586ca: /* original fbfd, guest PC 0x0c0586ca */
if(!s->budget--) { s->failed_pc=0x0c0586cau; return 0; }
vf3_matrix_swap(s);
goto P_0c0586cc;
P_0c0586cc: /* original ff8d, guest PC 0x0c0586cc */
if(!s->budget--) { s->failed_pc=0x0c0586ccu; return 0; }
fr[15]=0;
goto P_0c0586ce;
P_0c0586ce: /* original fdfd, guest PC 0x0c0586ce */
if(!s->budget--) { s->failed_pc=0x0c0586ceu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c0586d0;
P_0c0586d0: /* original f3fd, guest PC 0x0c0586d0 */
if(!s->budget--) { s->failed_pc=0x0c0586d0u; return 0; }
r[18]^=0x100000u;
goto P_0c0586d2;
P_0c0586d2: /* original fbfd, guest PC 0x0c0586d2 */
if(!s->budget--) { s->failed_pc=0x0c0586d2u; return 0; }
vf3_matrix_swap(s);
goto P_0c0586d4;
P_0c0586d4: /* original f4dc, guest PC 0x0c0586d4 */
if(!s->budget--) { s->failed_pc=0x0c0586d4u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0586d6;
P_0c0586d6: /* original f6fc, guest PC 0x0c0586d6 */
if(!s->budget--) { s->failed_pc=0x0c0586d6u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0586d8;
P_0c0586d8: /* original fdcc, guest PC 0x0c0586d8 */
if(!s->budget--) { s->failed_pc=0x0c0586d8u; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c0586da;
P_0c0586da: /* original ffec, guest PC 0x0c0586da */
if(!s->budget--) { s->failed_pc=0x0c0586dau; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0586dc;
P_0c0586dc: /* original f3fd, guest PC 0x0c0586dc */
if(!s->budget--) { s->failed_pc=0x0c0586dcu; return 0; }
r[18]^=0x100000u;
goto P_0c0586de;
P_0c0586de: /* original f38d, guest PC 0x0c0586de */
if(!s->budget--) { s->failed_pc=0x0c0586deu; return 0; }
fr[3]=0;
goto P_0c0586e0;
P_0c0586e0: /* original f345, guest PC 0x0c0586e0 */
if(!s->budget--) { s->failed_pc=0x0c0586e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0586e2;
P_0c0586e2: /* original f45d, guest PC 0x0c0586e2 */
if(!s->budget--) { s->failed_pc=0x0c0586e2u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c0586e4;
P_0c0586e4: /* original 0529, guest PC 0x0c0586e4 */
if(!s->budget--) { s->failed_pc=0x0c0586e4u; return 0; }
r[5]=r[17]&1u;
goto P_0c0586e6;
P_0c0586e6: /* original f365, guest PC 0x0c0586e6 */
if(!s->budget--) { s->failed_pc=0x0c0586e6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c0586e8;
P_0c0586e8: /* original f65d, guest PC 0x0c0586e8 */
if(!s->budget--) { s->failed_pc=0x0c0586e8u; return 0; }
fr[6]&=0x7fffffffu;
goto P_0c0586ea;
P_0c0586ea: /* original 355e, guest PC 0x0c0586ea */
if(!s->budget--) { s->failed_pc=0x0c0586eau; return 0; }
wide=(uint64_t)r[5]+r[5]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0586ec;
P_0c0586ec: /* original f645, guest PC 0x0c0586ec */
if(!s->budget--) { s->failed_pc=0x0c0586ecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[4]))!=0);
goto P_0c0586ee;
P_0c0586ee: /* original c71a, guest PC 0x0c0586ee */
if(!s->budget--) { s->failed_pc=0x0c0586eeu; return 0; }
r[0]=0x0c058758u;
goto P_0c0586f0;
P_0c0586f0: /* original f61d, guest PC 0x0c0586f0 */
if(!s->budget--) { s->failed_pc=0x0c0586f0u; return 0; }
r[53]=fr[6];
goto P_0c0586f2;
P_0c0586f2: /* original 8b01, guest PC 0x0c0586f2 */
if(!s->budget--) { s->failed_pc=0x0c0586f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0586f8; }
goto P_0c0586f4;
P_0c0586f4: /* original f64c, guest PC 0x0c0586f4 */
if(!s->budget--) { s->failed_pc=0x0c0586f4u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0586f6;
P_0c0586f6: /* original f40d, guest PC 0x0c0586f6 */
if(!s->budget--) { s->failed_pc=0x0c0586f6u; return 0; }
fr[4]=r[53];
goto P_0c0586f8;
P_0c0586f8: /* original 355e, guest PC 0x0c0586f8 */
if(!s->budget--) { s->failed_pc=0x0c0586f8u; return 0; }
wide=(uint64_t)r[5]+r[5]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0586fa;
P_0c0586fa: /* original f643, guest PC 0x0c0586fa */
if(!s->budget--) { s->failed_pc=0x0c0586fau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'/');
goto P_0c0586fc;
P_0c0586fc: /* original 355c, guest PC 0x0c0586fc */
if(!s->budget--) { s->failed_pc=0x0c0586fcu; return 0; }
r[5]+=r[5];
goto P_0c0586fe;
P_0c0586fe: /* original 025d, guest PC 0x0c0586fe */
if(!s->budget--) { s->failed_pc=0x0c0586feu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c058700;
P_0c058700: /* original c711, guest PC 0x0c058700 */
if(!s->budget--) { s->failed_pc=0x0c058700u; return 0; }
r[0]=0x0c058748u;
goto P_0c058702;
P_0c058702: /* original f009, guest PC 0x0c058702 */
if(!s->budget--) { s->failed_pc=0x0c058702u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c058704;
P_0c058704: /* original f409, guest PC 0x0c058704 */
if(!s->budget--) { s->failed_pc=0x0c058704u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c058706;
P_0c058706: /* original f355, guest PC 0x0c058706 */
if(!s->budget--) { s->failed_pc=0x0c058706u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c058708;
P_0c058708: /* original f309, guest PC 0x0c058708 */
if(!s->budget--) { s->failed_pc=0x0c058708u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c05870a;
P_0c05870a: /* original 6102, guest PC 0x0c05870a */
if(!s->budget--) { s->failed_pc=0x0c05870au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05870c;
P_0c05870c: /* original 70fc, guest PC 0x0c05870c */
if(!s->budget--) { s->failed_pc=0x0c05870cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c05870e;
P_0c05870e: /* original 8905, guest PC 0x0c05870e */
if(!s->budget--) { s->failed_pc=0x0c05870eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05871c; }
goto P_0c058710;
P_0c058710: /* original f352, guest PC 0x0c058710 */
if(!s->budget--) { s->failed_pc=0x0c058710u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c058712;
P_0c058712: /* original 4228, guest PC 0x0c058712 */
if(!s->budget--) { s->failed_pc=0x0c058712u; return 0; }
r[2]<<=16;
goto P_0c058714;
P_0c058714: /* original f33d, guest PC 0x0c058714 */
if(!s->budget--) { s->failed_pc=0x0c058714u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c058716;
P_0c058716: /* original 055a, guest PC 0x0c058716 */
if(!s->budget--) { s->failed_pc=0x0c058716u; return 0; }
r[5]=r[53];
goto P_0c058718;
P_0c058718: /* original 355c, guest PC 0x0c058718 */
if(!s->budget--) { s->failed_pc=0x0c058718u; return 0; }
r[5]+=r[5];
goto P_0c05871a;
P_0c05871a: /* original 225d, guest PC 0x0c05871a */
if(!s->budget--) { s->failed_pc=0x0c05871au; return 0; }
r[2]=(r[2]>>16)|(r[5]<<16);
goto P_0c05871c;
P_0c05871c: /* original f46e, guest PC 0x0c05871c */
if(!s->budget--) { s->failed_pc=0x0c05871cu; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[6],fr[4],r[18]);
goto P_0c05871e;
P_0c05871e: /* original f608, guest PC 0x0c05871e */
if(!s->budget--) { s->failed_pc=0x0c05871eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c058720;
P_0c058720: /* original f552, guest PC 0x0c058720 */
if(!s->budget--) { s->failed_pc=0x0c058720u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[5],r[18],'*');
goto P_0c058722;
P_0c058722: /* original 4201, guest PC 0x0c058722 */
if(!s->budget--) { s->failed_pc=0x0c058722u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c058724;
P_0c058724: /* original f43d, guest PC 0x0c058724 */
if(!s->budget--) { s->failed_pc=0x0c058724u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c058726;
P_0c058726: /* original f39d, guest PC 0x0c058726 */
if(!s->budget--) { s->failed_pc=0x0c058726u; return 0; }
fr[3]=0x3f800000u;
goto P_0c058728;
P_0c058728: /* original f351, guest PC 0x0c058728 */
if(!s->budget--) { s->failed_pc=0x0c058728u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c05872a;
P_0c05872a: /* original 005a, guest PC 0x0c05872a */
if(!s->budget--) { s->failed_pc=0x0c05872au; return 0; }
r[0]=r[53];
goto P_0c05872c;
P_0c05872c: /* original f36d, guest PC 0x0c05872c */
if(!s->budget--) { s->failed_pc=0x0c05872cu; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c05872e;
P_0c05872e: /* original 600c, guest PC 0x0c05872e */
if(!s->budget--) { s->failed_pc=0x0c05872eu; return 0; }
r[0]=r[0]&255u;
goto P_0c058730;
P_0c058730: /* original 011c, guest PC 0x0c058730 */
if(!s->budget--) { s->failed_pc=0x0c058730u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c058732;
P_0c058732: /* original f362, guest PC 0x0c058732 */
if(!s->budget--) { s->failed_pc=0x0c058732u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c058734;
P_0c058734: /* original 8b00, guest PC 0x0c058734 */
if(!s->budget--) { s->failed_pc=0x0c058734u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c058738; }
goto P_0c058736;
P_0c058736: /* original 611b, guest PC 0x0c058736 */
if(!s->budget--) { s->failed_pc=0x0c058736u; return 0; }
r[1]=0u-r[1];
goto P_0c058738;
P_0c058738: /* original 321c, guest PC 0x0c058738 */
if(!s->budget--) { s->failed_pc=0x0c058738u; return 0; }
r[2]+=r[1];
goto P_0c05873a;
P_0c05873a: /* original f33d, guest PC 0x0c05873a */
if(!s->budget--) { s->failed_pc=0x0c05873au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05873c;
P_0c05873c: /* original f3fd, guest PC 0x0c05873c */
if(!s->budget--) { s->failed_pc=0x0c05873cu; return 0; }
r[18]^=0x100000u;
goto P_0c05873e;
P_0c05873e: /* original 005a, guest PC 0x0c05873e */
if(!s->budget--) { s->failed_pc=0x0c05873eu; return 0; }
r[0]=r[53];
goto P_0c058740;
P_0c058740: /* original 4018, guest PC 0x0c058740 */
if(!s->budget--) { s->failed_pc=0x0c058740u; return 0; }
r[0]<<=8;
goto P_0c058742;
P_0c058742: /* original 000b, guest PC 0x0c058742 */
if(!s->budget--) { s->failed_pc=0x0c058742u; return 0; }
target=r[16];
r[0]|=r[2];
s->pc=target; return ram->oob==0;
P_0c058744: /* original 202b, guest PC 0x0c058744 */
if(!s->budget--) { s->failed_pc=0x0c058744u; return 0; }
r[0]|=r[2];
return vf3_matrix_family(0x0c058746u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
