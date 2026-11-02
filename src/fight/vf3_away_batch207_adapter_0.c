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
int vf3_away_batch207_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
case 0x0c069624u: goto P_0c069624;
case 0x0c069626u: goto P_0c069626;
case 0x0c069628u: goto P_0c069628;
case 0x0c06962au: goto P_0c06962a;
case 0x0c06962cu: goto P_0c06962c;
case 0x0c06962eu: goto P_0c06962e;
case 0x0c069630u: goto P_0c069630;
case 0x0c069632u: goto P_0c069632;
case 0x0c069634u: goto P_0c069634;
case 0x0c069636u: goto P_0c069636;
case 0x0c069638u: goto P_0c069638;
case 0x0c06963au: goto P_0c06963a;
case 0x0c06963cu: goto P_0c06963c;
case 0x0c06963eu: goto P_0c06963e;
case 0x0c069640u: goto P_0c069640;
case 0x0c069642u: goto P_0c069642;
case 0x0c069644u: goto P_0c069644;
case 0x0c069646u: goto P_0c069646;
case 0x0c069648u: goto P_0c069648;
case 0x0c06964au: goto P_0c06964a;
case 0x0c06964cu: goto P_0c06964c;
case 0x0c06964eu: goto P_0c06964e;
case 0x0c069650u: goto P_0c069650;
case 0x0c069652u: goto P_0c069652;
case 0x0c069654u: goto P_0c069654;
case 0x0c069656u: goto P_0c069656;
case 0x0c069658u: goto P_0c069658;
case 0x0c06965au: goto P_0c06965a;
case 0x0c06965cu: goto P_0c06965c;
case 0x0c06965eu: goto P_0c06965e;
case 0x0c069660u: goto P_0c069660;
case 0x0c069662u: goto P_0c069662;
case 0x0c069664u: goto P_0c069664;
case 0x0c069666u: goto P_0c069666;
case 0x0c069668u: goto P_0c069668;
case 0x0c06966au: goto P_0c06966a;
case 0x0c06966cu: goto P_0c06966c;
case 0x0c06966eu: goto P_0c06966e;
case 0x0c069670u: goto P_0c069670;
case 0x0c069672u: goto P_0c069672;
case 0x0c069674u: goto P_0c069674;
case 0x0c069676u: goto P_0c069676;
case 0x0c069678u: goto P_0c069678;
case 0x0c06967au: goto P_0c06967a;
case 0x0c06967cu: goto P_0c06967c;
case 0x0c06967eu: goto P_0c06967e;
case 0x0c069680u: goto P_0c069680;
case 0x0c069682u: goto P_0c069682;
case 0x0c069684u: goto P_0c069684;
case 0x0c069686u: goto P_0c069686;
case 0x0c069688u: goto P_0c069688;
case 0x0c06968au: goto P_0c06968a;
case 0x0c06968cu: goto P_0c06968c;
case 0x0c06968eu: goto P_0c06968e;
case 0x0c069690u: goto P_0c069690;
case 0x0c069692u: goto P_0c069692;
case 0x0c069694u: goto P_0c069694;
case 0x0c069696u: goto P_0c069696;
case 0x0c069698u: goto P_0c069698;
case 0x0c06969au: goto P_0c06969a;
case 0x0c06969cu: goto P_0c06969c;
case 0x0c09d5aeu: goto P_0c09d5ae;
case 0x0c09d5b0u: goto P_0c09d5b0;
case 0x0c09d5b2u: goto P_0c09d5b2;
case 0x0c09d5b4u: goto P_0c09d5b4;
case 0x0c09d5b6u: goto P_0c09d5b6;
case 0x0c09d5b8u: goto P_0c09d5b8;
case 0x0c09d5bau: goto P_0c09d5ba;
case 0x0c09d5bcu: goto P_0c09d5bc;
case 0x0c09d5beu: goto P_0c09d5be;
case 0x0c09d5c0u: goto P_0c09d5c0;
case 0x0c09d5c2u: goto P_0c09d5c2;
case 0x0c09d5c4u: goto P_0c09d5c4;
case 0x0c09d5c6u: goto P_0c09d5c6;
case 0x0c09d5c8u: goto P_0c09d5c8;
case 0x0c09d5cau: goto P_0c09d5ca;
case 0x0c09d5ccu: goto P_0c09d5cc;
case 0x0c09d5ceu: goto P_0c09d5ce;
case 0x0c09d5d0u: goto P_0c09d5d0;
case 0x0c09d5d2u: goto P_0c09d5d2;
case 0x0c09d5d4u: goto P_0c09d5d4;
case 0x0c09d5d6u: goto P_0c09d5d6;
case 0x0c09d5d8u: goto P_0c09d5d8;
case 0x0c09d5dau: goto P_0c09d5da;
case 0x0c09d5dcu: goto P_0c09d5dc;
case 0x0c09d5deu: goto P_0c09d5de;
case 0x0c09d5e0u: goto P_0c09d5e0;
case 0x0c09d5e2u: goto P_0c09d5e2;
case 0x0c09d5e4u: goto P_0c09d5e4;
case 0x0c09d5e6u: goto P_0c09d5e6;
case 0x0c09d5e8u: goto P_0c09d5e8;
case 0x0c09d5eau: goto P_0c09d5ea;
case 0x0c09d5ecu: goto P_0c09d5ec;
case 0x0c09d5eeu: goto P_0c09d5ee;
case 0x0c09d5f0u: goto P_0c09d5f0;
case 0x0c09d5f2u: goto P_0c09d5f2;
case 0x0c09d5f4u: goto P_0c09d5f4;
case 0x0c09d5f6u: goto P_0c09d5f6;
case 0x0c09d5f8u: goto P_0c09d5f8;
case 0x0c09d5fau: goto P_0c09d5fa;
case 0x0c09d5fcu: goto P_0c09d5fc;
case 0x0c09d5feu: goto P_0c09d5fe;
case 0x0c09d600u: goto P_0c09d600;
case 0x0c09d602u: goto P_0c09d602;
case 0x0c09d604u: goto P_0c09d604;
case 0x0c09d606u: goto P_0c09d606;
case 0x0c09d608u: goto P_0c09d608;
case 0x0c09d60au: goto P_0c09d60a;
case 0x0c09d60cu: goto P_0c09d60c;
case 0x0c09d60eu: goto P_0c09d60e;
case 0x0c09d610u: goto P_0c09d610;
case 0x0c09d612u: goto P_0c09d612;
case 0x0c09d614u: goto P_0c09d614;
case 0x0c09d616u: goto P_0c09d616;
case 0x0c09d618u: goto P_0c09d618;
case 0x0c09d61au: goto P_0c09d61a;
case 0x0c09d61cu: goto P_0c09d61c;
case 0x0c09d61eu: goto P_0c09d61e;
case 0x0c09d620u: goto P_0c09d620;
case 0x0c09d622u: goto P_0c09d622;
case 0x0c09d624u: goto P_0c09d624;
case 0x0c09d626u: goto P_0c09d626;
case 0x0c09d628u: goto P_0c09d628;
case 0x0c09d62au: goto P_0c09d62a;
case 0x0c09d62cu: goto P_0c09d62c;
case 0x0c09d62eu: goto P_0c09d62e;
case 0x0c09d630u: goto P_0c09d630;
case 0x0c09d632u: goto P_0c09d632;
case 0x0c09d634u: goto P_0c09d634;
case 0x0c09d636u: goto P_0c09d636;
case 0x0c09d638u: goto P_0c09d638;
case 0x0c09d63au: goto P_0c09d63a;
case 0x0c09d63cu: goto P_0c09d63c;
case 0x0c09d63eu: goto P_0c09d63e;
case 0x0c09d640u: goto P_0c09d640;
case 0x0c09d642u: goto P_0c09d642;
case 0x0c09d644u: goto P_0c09d644;
case 0x0c09d646u: goto P_0c09d646;
case 0x0c09d648u: goto P_0c09d648;
case 0x0c09d64au: goto P_0c09d64a;
case 0x0c09d64cu: goto P_0c09d64c;
case 0x0c09d64eu: goto P_0c09d64e;
case 0x0c09d650u: goto P_0c09d650;
case 0x0c09d652u: goto P_0c09d652;
case 0x0c09d654u: goto P_0c09d654;
case 0x0c09d656u: goto P_0c09d656;
case 0x0c09d658u: goto P_0c09d658;
case 0x0c09d65au: goto P_0c09d65a;
case 0x0c09d65cu: goto P_0c09d65c;
case 0x0c09d65eu: goto P_0c09d65e;
case 0x0c09d660u: goto P_0c09d660;
case 0x0c09d662u: goto P_0c09d662;
case 0x0c09efd8u: goto P_0c09efd8;
case 0x0c09efdau: goto P_0c09efda;
case 0x0c09efdcu: goto P_0c09efdc;
case 0x0c09efdeu: goto P_0c09efde;
case 0x0c09efe0u: goto P_0c09efe0;
case 0x0c09efe2u: goto P_0c09efe2;
case 0x0c09efe4u: goto P_0c09efe4;
case 0x0c09f1acu: goto P_0c09f1ac;
case 0x0c09f1aeu: goto P_0c09f1ae;
case 0x0c09f1b0u: goto P_0c09f1b0;
case 0x0c09f1b2u: goto P_0c09f1b2;
case 0x0c09f1b4u: goto P_0c09f1b4;
case 0x0c09f1b6u: goto P_0c09f1b6;
case 0x0c09f1b8u: goto P_0c09f1b8;
case 0x0c09f1bau: goto P_0c09f1ba;
case 0x0c09f1bcu: goto P_0c09f1bc;
case 0x0c09f1beu: goto P_0c09f1be;
case 0x0c09f1c0u: goto P_0c09f1c0;
case 0x0c09f1c2u: goto P_0c09f1c2;
case 0x0c09f1c4u: goto P_0c09f1c4;
case 0x0c09f1c6u: goto P_0c09f1c6;
case 0x0c09f1c8u: goto P_0c09f1c8;
case 0x0c09f1cau: goto P_0c09f1ca;
case 0x0c09f1ccu: goto P_0c09f1cc;
case 0x0c09f1ceu: goto P_0c09f1ce;
case 0x0c09f1d0u: goto P_0c09f1d0;
case 0x0c09f1d2u: goto P_0c09f1d2;
case 0x0c09f1d4u: goto P_0c09f1d4;
case 0x0c09f1d6u: goto P_0c09f1d6;
case 0x0c09f1d8u: goto P_0c09f1d8;
case 0x0c09f1dau: goto P_0c09f1da;
case 0x0c09f1dcu: goto P_0c09f1dc;
case 0x0c09f1deu: goto P_0c09f1de;
case 0x0c09f1e0u: goto P_0c09f1e0;
case 0x0c09f1e2u: goto P_0c09f1e2;
case 0x0c09f1e4u: goto P_0c09f1e4;
case 0x0c09f1e6u: goto P_0c09f1e6;
case 0x0c09f1e8u: goto P_0c09f1e8;
case 0x0c09f1eau: goto P_0c09f1ea;
case 0x0c09f1ecu: goto P_0c09f1ec;
case 0x0c09f1eeu: goto P_0c09f1ee;
case 0x0c09f1f0u: goto P_0c09f1f0;
case 0x0c09f1f2u: goto P_0c09f1f2;
case 0x0c09f1f4u: goto P_0c09f1f4;
case 0x0c09f1f6u: goto P_0c09f1f6;
case 0x0c09f1f8u: goto P_0c09f1f8;
case 0x0c09f1fau: goto P_0c09f1fa;
case 0x0c09f1fcu: goto P_0c09f1fc;
case 0x0c09f1feu: goto P_0c09f1fe;
case 0x0c09f200u: goto P_0c09f200;
case 0x0c09f202u: goto P_0c09f202;
case 0x0c09f204u: goto P_0c09f204;
case 0x0c09f206u: goto P_0c09f206;
case 0x0c09f208u: goto P_0c09f208;
case 0x0c09f20au: goto P_0c09f20a;
case 0x0c09f20cu: goto P_0c09f20c;
case 0x0c09f20eu: goto P_0c09f20e;
case 0x0c09f210u: goto P_0c09f210;
case 0x0c09f212u: goto P_0c09f212;
case 0x0c09f214u: goto P_0c09f214;
case 0x0c09f216u: goto P_0c09f216;
case 0x0c09f218u: goto P_0c09f218;
case 0x0c09f21au: goto P_0c09f21a;
case 0x0c09f21cu: goto P_0c09f21c;
case 0x0c09f21eu: goto P_0c09f21e;
case 0x0c09f220u: goto P_0c09f220;
case 0x0c09f222u: goto P_0c09f222;
case 0x0c09f224u: goto P_0c09f224;
case 0x0c09f226u: goto P_0c09f226;
case 0x0c09f228u: goto P_0c09f228;
case 0x0c09f22au: goto P_0c09f22a;
case 0x0c09f22cu: goto P_0c09f22c;
case 0x0c09f22eu: goto P_0c09f22e;
case 0x0c09f230u: goto P_0c09f230;
case 0x0c09f232u: goto P_0c09f232;
case 0x0c09f234u: goto P_0c09f234;
case 0x0c09f236u: goto P_0c09f236;
case 0x0c09f238u: goto P_0c09f238;
case 0x0c09f23au: goto P_0c09f23a;
case 0x0c09f23cu: goto P_0c09f23c;
case 0x0c09f23eu: goto P_0c09f23e;
case 0x0c09f240u: goto P_0c09f240;
case 0x0c09f242u: goto P_0c09f242;
case 0x0c09f244u: goto P_0c09f244;
case 0x0c09f246u: goto P_0c09f246;
case 0x0c09f248u: goto P_0c09f248;
case 0x0c09f24au: goto P_0c09f24a;
case 0x0c09f24cu: goto P_0c09f24c;
case 0x0c09f24eu: goto P_0c09f24e;
case 0x0c09f250u: goto P_0c09f250;
case 0x0c09f268u: goto P_0c09f268;
case 0x0c09f26au: goto P_0c09f26a;
case 0x0c09f26cu: goto P_0c09f26c;
case 0x0c09f26eu: goto P_0c09f26e;
case 0x0c09f270u: goto P_0c09f270;
case 0x0c09f272u: goto P_0c09f272;
case 0x0c09f274u: goto P_0c09f274;
case 0x0c09f276u: goto P_0c09f276;
case 0x0c09f278u: goto P_0c09f278;
case 0x0c09f27au: goto P_0c09f27a;
case 0x0c09f27cu: goto P_0c09f27c;
case 0x0c09f27eu: goto P_0c09f27e;
case 0x0c09f280u: goto P_0c09f280;
case 0x0c09f282u: goto P_0c09f282;
case 0x0c09f284u: goto P_0c09f284;
case 0x0c09f286u: goto P_0c09f286;
case 0x0c09f288u: goto P_0c09f288;
case 0x0c09f28au: goto P_0c09f28a;
case 0x0c09f28cu: goto P_0c09f28c;
case 0x0c09f28eu: goto P_0c09f28e;
case 0x0c09f290u: goto P_0c09f290;
case 0x0c09f292u: goto P_0c09f292;
case 0x0c09f294u: goto P_0c09f294;
case 0x0c09f296u: goto P_0c09f296;
case 0x0c09f298u: goto P_0c09f298;
case 0x0c09f29au: goto P_0c09f29a;
case 0x0c09f29cu: goto P_0c09f29c;
case 0x0c09f29eu: goto P_0c09f29e;
case 0x0c09f2a0u: goto P_0c09f2a0;
case 0x0c09f2a2u: goto P_0c09f2a2;
case 0x0c09f2a4u: goto P_0c09f2a4;
case 0x0c09f2a6u: goto P_0c09f2a6;
case 0x0c09f2a8u: goto P_0c09f2a8;
case 0x0c09f2aau: goto P_0c09f2aa;
case 0x0c09f2acu: goto P_0c09f2ac;
case 0x0c09f2aeu: goto P_0c09f2ae;
case 0x0c09f2b0u: goto P_0c09f2b0;
case 0x0c09f2b2u: goto P_0c09f2b2;
case 0x0c09f2b4u: goto P_0c09f2b4;
case 0x0c09f2b6u: goto P_0c09f2b6;
case 0x0c09f2b8u: goto P_0c09f2b8;
case 0x0c09f2bau: goto P_0c09f2ba;
case 0x0c09f2bcu: goto P_0c09f2bc;
case 0x0c09f2beu: goto P_0c09f2be;
case 0x0c09f2c0u: goto P_0c09f2c0;
case 0x0c09f2c2u: goto P_0c09f2c2;
case 0x0c09f2c4u: goto P_0c09f2c4;
case 0x0c09f2c6u: goto P_0c09f2c6;
case 0x0c09f2c8u: goto P_0c09f2c8;
case 0x0c09f2cau: goto P_0c09f2ca;
case 0x0c09f2ccu: goto P_0c09f2cc;
case 0x0c09f2ceu: goto P_0c09f2ce;
case 0x0c09f2d0u: goto P_0c09f2d0;
case 0x0c09f2d2u: goto P_0c09f2d2;
case 0x0c09f2d4u: goto P_0c09f2d4;
case 0x0c09f2d6u: goto P_0c09f2d6;
case 0x0c09f2d8u: goto P_0c09f2d8;
case 0x0c09f2dau: goto P_0c09f2da;
case 0x0c09f2dcu: goto P_0c09f2dc;
case 0x0c09f2deu: goto P_0c09f2de;
case 0x0c09f2e0u: goto P_0c09f2e0;
case 0x0c09f2e2u: goto P_0c09f2e2;
case 0x0c09f2e4u: goto P_0c09f2e4;
case 0x0c09f2e6u: goto P_0c09f2e6;
case 0x0c09f2e8u: goto P_0c09f2e8;
case 0x0c09f2eau: goto P_0c09f2ea;
case 0x0c09f2ecu: goto P_0c09f2ec;
case 0x0c09f2eeu: goto P_0c09f2ee;
case 0x0c09f2f0u: goto P_0c09f2f0;
case 0x0c09f2f2u: goto P_0c09f2f2;
case 0x0c09f2f4u: goto P_0c09f2f4;
case 0x0c09f2f6u: goto P_0c09f2f6;
case 0x0c09f2f8u: goto P_0c09f2f8;
case 0x0c09f2fau: goto P_0c09f2fa;
case 0x0c09f2fcu: goto P_0c09f2fc;
case 0x0c09f2feu: goto P_0c09f2fe;
case 0x0c09f300u: goto P_0c09f300;
case 0x0c09f302u: goto P_0c09f302;
case 0x0c09f304u: goto P_0c09f304;
case 0x0c09f306u: goto P_0c09f306;
case 0x0c09f308u: goto P_0c09f308;
case 0x0c09f30au: goto P_0c09f30a;
case 0x0c09f30cu: goto P_0c09f30c;
case 0x0c09f30eu: goto P_0c09f30e;
case 0x0c09f310u: goto P_0c09f310;
case 0x0c09f312u: goto P_0c09f312;
case 0x0c09f314u: goto P_0c09f314;
case 0x0c09f316u: goto P_0c09f316;
case 0x0c09f318u: goto P_0c09f318;
case 0x0c09f31au: goto P_0c09f31a;
case 0x0c09f31cu: goto P_0c09f31c;
case 0x0c09f31eu: goto P_0c09f31e;
case 0x0c09f320u: goto P_0c09f320;
case 0x0c09f322u: goto P_0c09f322;
case 0x0c09f324u: goto P_0c09f324;
case 0x0c09f326u: goto P_0c09f326;
case 0x0c09f328u: goto P_0c09f328;
case 0x0c09f32au: goto P_0c09f32a;
case 0x0c09f32cu: goto P_0c09f32c;
case 0x0c09f32eu: goto P_0c09f32e;
case 0x0c09f330u: goto P_0c09f330;
case 0x0c09f332u: goto P_0c09f332;
case 0x0c09f334u: goto P_0c09f334;
case 0x0c0ab340u: goto P_0c0ab340;
case 0x0c0ab342u: goto P_0c0ab342;
case 0x0c0ab344u: goto P_0c0ab344;
case 0x0c0ab346u: goto P_0c0ab346;
case 0x0c0ab348u: goto P_0c0ab348;
case 0x0c0ab34au: goto P_0c0ab34a;
case 0x0c0ab34cu: goto P_0c0ab34c;
case 0x0c0ab34eu: goto P_0c0ab34e;
case 0x0c0ab350u: goto P_0c0ab350;
case 0x0c0ab352u: goto P_0c0ab352;
case 0x0c0ab354u: goto P_0c0ab354;
case 0x0c0ab356u: goto P_0c0ab356;
case 0x0c0ab358u: goto P_0c0ab358;
case 0x0c0ab35au: goto P_0c0ab35a;
case 0x0c0ab35cu: goto P_0c0ab35c;
case 0x0c0ab35eu: goto P_0c0ab35e;
case 0x0c0ab360u: goto P_0c0ab360;
case 0x0c0ab362u: goto P_0c0ab362;
case 0x0c0ab364u: goto P_0c0ab364;
case 0x0c0ab366u: goto P_0c0ab366;
case 0x0c0ab368u: goto P_0c0ab368;
case 0x0c0ab36au: goto P_0c0ab36a;
case 0x0c0ab36cu: goto P_0c0ab36c;
case 0x0c0ab36eu: goto P_0c0ab36e;
case 0x0c0ab370u: goto P_0c0ab370;
case 0x0c0ab372u: goto P_0c0ab372;
case 0x0c0ab374u: goto P_0c0ab374;
case 0x0c0ab376u: goto P_0c0ab376;
case 0x0c0ab378u: goto P_0c0ab378;
case 0x0c0ab37au: goto P_0c0ab37a;
case 0x0c0ab37cu: goto P_0c0ab37c;
case 0x0c0ab37eu: goto P_0c0ab37e;
case 0x0c0ab380u: goto P_0c0ab380;
case 0x0c0ab382u: goto P_0c0ab382;
case 0x0c0ab384u: goto P_0c0ab384;
case 0x0c0ab386u: goto P_0c0ab386;
case 0x0c0ab388u: goto P_0c0ab388;
case 0x0c0ab38au: goto P_0c0ab38a;
case 0x0c0ab38cu: goto P_0c0ab38c;
case 0x0c0ab38eu: goto P_0c0ab38e;
case 0x0c0ab390u: goto P_0c0ab390;
case 0x0c0ab392u: goto P_0c0ab392;
case 0x0c0ab394u: goto P_0c0ab394;
case 0x0c0ab396u: goto P_0c0ab396;
case 0x0c0ab398u: goto P_0c0ab398;
case 0x0c0ab39au: goto P_0c0ab39a;
case 0x0c0ab39cu: goto P_0c0ab39c;
case 0x0c0ab39eu: goto P_0c0ab39e;
case 0x0c0ab3a0u: goto P_0c0ab3a0;
case 0x0c0ab3a2u: goto P_0c0ab3a2;
case 0x0c0ab3a4u: goto P_0c0ab3a4;
case 0x0c0ab3a6u: goto P_0c0ab3a6;
case 0x0c0ab3a8u: goto P_0c0ab3a8;
case 0x0c0ab3aau: goto P_0c0ab3aa;
case 0x0c0ab3acu: goto P_0c0ab3ac;
case 0x0c0ab3aeu: goto P_0c0ab3ae;
case 0x0c0ab3b0u: goto P_0c0ab3b0;
case 0x0c0ab3b2u: goto P_0c0ab3b2;
case 0x0c0ab3b4u: goto P_0c0ab3b4;
case 0x0c0ab3b6u: goto P_0c0ab3b6;
case 0x0c0ab3b8u: goto P_0c0ab3b8;
case 0x0c0ab3bau: goto P_0c0ab3ba;
case 0x0c0ab3bcu: goto P_0c0ab3bc;
case 0x0c0ab3beu: goto P_0c0ab3be;
case 0x0c0ab3c0u: goto P_0c0ab3c0;
case 0x0c0ab3c2u: goto P_0c0ab3c2;
case 0x0c0ab3c4u: goto P_0c0ab3c4;
case 0x0c0ab3c6u: goto P_0c0ab3c6;
case 0x0c0ab3c8u: goto P_0c0ab3c8;
case 0x0c0ab3cau: goto P_0c0ab3ca;
case 0x0c0ab3ccu: goto P_0c0ab3cc;
case 0x0c0ab3ceu: goto P_0c0ab3ce;
case 0x0c0ab3d0u: goto P_0c0ab3d0;
case 0x0c0ab3d2u: goto P_0c0ab3d2;
case 0x0c0ab3d4u: goto P_0c0ab3d4;
case 0x0c0ab3d6u: goto P_0c0ab3d6;
case 0x0c0ab3d8u: goto P_0c0ab3d8;
case 0x0c0ab3dau: goto P_0c0ab3da;
case 0x0c0ab3dcu: goto P_0c0ab3dc;
case 0x0c0ab3deu: goto P_0c0ab3de;
case 0x0c0ab3e0u: goto P_0c0ab3e0;
case 0x0c0ab3e2u: goto P_0c0ab3e2;
case 0x0c0ab3e4u: goto P_0c0ab3e4;
case 0x0c0ab3e6u: goto P_0c0ab3e6;
case 0x0c0ab3e8u: goto P_0c0ab3e8;
case 0x0c0ab3eau: goto P_0c0ab3ea;
case 0x0c0ab3ecu: goto P_0c0ab3ec;
case 0x0c0ab3eeu: goto P_0c0ab3ee;
case 0x0c0ab3f0u: goto P_0c0ab3f0;
case 0x0c0ab3f2u: goto P_0c0ab3f2;
case 0x0c0ab3f4u: goto P_0c0ab3f4;
case 0x0c0ab3f6u: goto P_0c0ab3f6;
case 0x0c0ab3f8u: goto P_0c0ab3f8;
case 0x0c0ab3fau: goto P_0c0ab3fa;
case 0x0c0ab3fcu: goto P_0c0ab3fc;
case 0x0c0ab3feu: goto P_0c0ab3fe;
case 0x0c0ab400u: goto P_0c0ab400;
case 0x0c0ab402u: goto P_0c0ab402;
case 0x0c0ab404u: goto P_0c0ab404;
case 0x0c0ab406u: goto P_0c0ab406;
case 0x0c0ab408u: goto P_0c0ab408;
case 0x0c0ab40au: goto P_0c0ab40a;
case 0x0c0ab40cu: goto P_0c0ab40c;
case 0x0c0ab40eu: goto P_0c0ab40e;
case 0x0c0ab410u: goto P_0c0ab410;
case 0x0c0ab412u: goto P_0c0ab412;
case 0x0c0ab414u: goto P_0c0ab414;
case 0x0c0ab416u: goto P_0c0ab416;
case 0x0c0ab418u: goto P_0c0ab418;
case 0x0c0ab41au: goto P_0c0ab41a;
case 0x0c0ab41cu: goto P_0c0ab41c;
case 0x0c0ab41eu: goto P_0c0ab41e;
case 0x0c0ab420u: goto P_0c0ab420;
case 0x0c0ab422u: goto P_0c0ab422;
case 0x0c0ab424u: goto P_0c0ab424;
case 0x0c0ab426u: goto P_0c0ab426;
case 0x0c0ab428u: goto P_0c0ab428;
case 0x0c0ab42au: goto P_0c0ab42a;
case 0x0c0ab42cu: goto P_0c0ab42c;
case 0x0c0ab42eu: goto P_0c0ab42e;
case 0x0c0ab430u: goto P_0c0ab430;
case 0x0c0ab432u: goto P_0c0ab432;
case 0x0c0ab434u: goto P_0c0ab434;
case 0x0c0ab436u: goto P_0c0ab436;
case 0x0c0ab438u: goto P_0c0ab438;
case 0x0c0ab43au: goto P_0c0ab43a;
case 0x0c0ab43cu: goto P_0c0ab43c;
case 0x0c0ab43eu: goto P_0c0ab43e;
case 0x0c0ab440u: goto P_0c0ab440;
case 0x0c0ab442u: goto P_0c0ab442;
case 0x0c0ab444u: goto P_0c0ab444;
case 0x0c0ab446u: goto P_0c0ab446;
case 0x0c0ab448u: goto P_0c0ab448;
case 0x0c0ab44au: goto P_0c0ab44a;
case 0x0c0ab44cu: goto P_0c0ab44c;
case 0x0c0ab44eu: goto P_0c0ab44e;
case 0x0c0ab450u: goto P_0c0ab450;
case 0x0c0ab452u: goto P_0c0ab452;
case 0x0c0ab454u: goto P_0c0ab454;
case 0x0c0ab456u: goto P_0c0ab456;
case 0x0c0ab458u: goto P_0c0ab458;
case 0x0c0ab45au: goto P_0c0ab45a;
case 0x0c0ab45cu: goto P_0c0ab45c;
case 0x0c0ab45eu: goto P_0c0ab45e;
case 0x0c0ab460u: goto P_0c0ab460;
case 0x0c0ab462u: goto P_0c0ab462;
case 0x0c0ab464u: goto P_0c0ab464;
case 0x0c0ab466u: goto P_0c0ab466;
case 0x0c0ab468u: goto P_0c0ab468;
case 0x0c0ab46au: goto P_0c0ab46a;
case 0x0c0ab46cu: goto P_0c0ab46c;
case 0x0c0ab46eu: goto P_0c0ab46e;
case 0x0c0ab470u: goto P_0c0ab470;
case 0x0c0ab472u: goto P_0c0ab472;
case 0x0c0ab474u: goto P_0c0ab474;
case 0x0c0ab4b4u: goto P_0c0ab4b4;
case 0x0c0ab4b6u: goto P_0c0ab4b6;
case 0x0c0ab4b8u: goto P_0c0ab4b8;
case 0x0c0ab4bau: goto P_0c0ab4ba;
case 0x0c0ab4bcu: goto P_0c0ab4bc;
case 0x0c0ab4beu: goto P_0c0ab4be;
case 0x0c0ab4c0u: goto P_0c0ab4c0;
case 0x0c0ab4c2u: goto P_0c0ab4c2;
case 0x0c0ab4c4u: goto P_0c0ab4c4;
case 0x0c0ab4c6u: goto P_0c0ab4c6;
case 0x0c0ab4c8u: goto P_0c0ab4c8;
case 0x0c0ab4cau: goto P_0c0ab4ca;
case 0x0c0ab4ccu: goto P_0c0ab4cc;
case 0x0c0ab4ceu: goto P_0c0ab4ce;
case 0x0c0ab4d0u: goto P_0c0ab4d0;
case 0x0c0ab4d2u: goto P_0c0ab4d2;
case 0x0c0ab4d4u: goto P_0c0ab4d4;
case 0x0c0ab4d6u: goto P_0c0ab4d6;
case 0x0c0ab4d8u: goto P_0c0ab4d8;
case 0x0c0ab4dau: goto P_0c0ab4da;
case 0x0c0ab4dcu: goto P_0c0ab4dc;
case 0x0c0ab4deu: goto P_0c0ab4de;
case 0x0c0ab4e0u: goto P_0c0ab4e0;
case 0x0c0ab4e2u: goto P_0c0ab4e2;
case 0x0c0ab4e4u: goto P_0c0ab4e4;
case 0x0c0ab4e6u: goto P_0c0ab4e6;
case 0x0c0ab4e8u: goto P_0c0ab4e8;
case 0x0c0ab4eau: goto P_0c0ab4ea;
case 0x0c0ab4ecu: goto P_0c0ab4ec;
case 0x0c0ab4eeu: goto P_0c0ab4ee;
case 0x0c0ab4f0u: goto P_0c0ab4f0;
case 0x0c0ab4f2u: goto P_0c0ab4f2;
case 0x0c0ab4f4u: goto P_0c0ab4f4;
case 0x0c0ab4f6u: goto P_0c0ab4f6;
case 0x0c0ab4f8u: goto P_0c0ab4f8;
case 0x0c0ab4fau: goto P_0c0ab4fa;
case 0x0c0ab4fcu: goto P_0c0ab4fc;
case 0x0c0ab4feu: goto P_0c0ab4fe;
case 0x0c0ab500u: goto P_0c0ab500;
case 0x0c0ab502u: goto P_0c0ab502;
case 0x0c0ab504u: goto P_0c0ab504;
case 0x0c0ab506u: goto P_0c0ab506;
case 0x0c0ab508u: goto P_0c0ab508;
case 0x0c0ab50au: goto P_0c0ab50a;
case 0x0c0ab50cu: goto P_0c0ab50c;
case 0x0c0ab50eu: goto P_0c0ab50e;
case 0x0c0ab510u: goto P_0c0ab510;
case 0x0c0ab512u: goto P_0c0ab512;
case 0x0c0ab514u: goto P_0c0ab514;
case 0x0c0ab516u: goto P_0c0ab516;
case 0x0c0ab518u: goto P_0c0ab518;
case 0x0c0ab51au: goto P_0c0ab51a;
case 0x0c0ab51cu: goto P_0c0ab51c;
case 0x0c0ab51eu: goto P_0c0ab51e;
case 0x0c0ab520u: goto P_0c0ab520;
case 0x0c0ab522u: goto P_0c0ab522;
case 0x0c0ab524u: goto P_0c0ab524;
case 0x0c0ab526u: goto P_0c0ab526;
case 0x0c0ab528u: goto P_0c0ab528;
case 0x0c0ab52au: goto P_0c0ab52a;
case 0x0c0ab52cu: goto P_0c0ab52c;
case 0x0c0ab52eu: goto P_0c0ab52e;
case 0x0c0ab530u: goto P_0c0ab530;
case 0x0c0ab532u: goto P_0c0ab532;
case 0x0c0ab534u: goto P_0c0ab534;
case 0x0c0ab536u: goto P_0c0ab536;
case 0x0c0ab538u: goto P_0c0ab538;
case 0x0c0ab53au: goto P_0c0ab53a;
case 0x0c0ab53cu: goto P_0c0ab53c;
case 0x0c0ab53eu: goto P_0c0ab53e;
case 0x0c0ab540u: goto P_0c0ab540;
case 0x0c0ab542u: goto P_0c0ab542;
case 0x0c0ab544u: goto P_0c0ab544;
case 0x0c0ab546u: goto P_0c0ab546;
case 0x0c0ab548u: goto P_0c0ab548;
case 0x0c0ab54au: goto P_0c0ab54a;
case 0x0c0ab54cu: goto P_0c0ab54c;
case 0x0c0ab54eu: goto P_0c0ab54e;
case 0x0c0ab550u: goto P_0c0ab550;
case 0x0c0ab552u: goto P_0c0ab552;
case 0x0c0ab554u: goto P_0c0ab554;
case 0x0c0ab556u: goto P_0c0ab556;
case 0x0c0ab558u: goto P_0c0ab558;
case 0x0c0ab55au: goto P_0c0ab55a;
case 0x0c0ab55cu: goto P_0c0ab55c;
case 0x0c0ab55eu: goto P_0c0ab55e;
case 0x0c0ab560u: goto P_0c0ab560;
case 0x0c0ab562u: goto P_0c0ab562;
case 0x0c0ab564u: goto P_0c0ab564;
case 0x0c0ab566u: goto P_0c0ab566;
case 0x0c0ab568u: goto P_0c0ab568;
case 0x0c0ab56au: goto P_0c0ab56a;
case 0x0c0ab56cu: goto P_0c0ab56c;
case 0x0c0ab56eu: goto P_0c0ab56e;
case 0x0c0ab570u: goto P_0c0ab570;
case 0x0c0ab572u: goto P_0c0ab572;
case 0x0c0ab574u: goto P_0c0ab574;
case 0x0c0ab576u: goto P_0c0ab576;
case 0x0c0ab578u: goto P_0c0ab578;
case 0x0c0ab57au: goto P_0c0ab57a;
case 0x0c0ab57cu: goto P_0c0ab57c;
case 0x0c0ab57eu: goto P_0c0ab57e;
case 0x0c0ab580u: goto P_0c0ab580;
case 0x0c0ab582u: goto P_0c0ab582;
case 0x0c0ab584u: goto P_0c0ab584;
case 0x0c0ab586u: goto P_0c0ab586;
case 0x0c0ab588u: goto P_0c0ab588;
case 0x0c0ab58au: goto P_0c0ab58a;
case 0x0c0ab58cu: goto P_0c0ab58c;
case 0x0c0ab58eu: goto P_0c0ab58e;
case 0x0c0ab590u: goto P_0c0ab590;
case 0x0c0ab592u: goto P_0c0ab592;
case 0x0c0ab594u: goto P_0c0ab594;
case 0x0c0ab596u: goto P_0c0ab596;
case 0x0c0ab598u: goto P_0c0ab598;
case 0x0c0ab59au: goto P_0c0ab59a;
case 0x0c0ab59cu: goto P_0c0ab59c;
case 0x0c0ab59eu: goto P_0c0ab59e;
case 0x0c0ab5a0u: goto P_0c0ab5a0;
case 0x0c0ab5a2u: goto P_0c0ab5a2;
case 0x0c0ab5a4u: goto P_0c0ab5a4;
case 0x0c0ab5a6u: goto P_0c0ab5a6;
case 0x0c0ab5a8u: goto P_0c0ab5a8;
case 0x0c0ab5aau: goto P_0c0ab5aa;
case 0x0c0ab5acu: goto P_0c0ab5ac;
case 0x0c0ab5aeu: goto P_0c0ab5ae;
case 0x0c0ab5b0u: goto P_0c0ab5b0;
case 0x0c0ab5b2u: goto P_0c0ab5b2;
case 0x0c0ab5b4u: goto P_0c0ab5b4;
case 0x0c0ab5b6u: goto P_0c0ab5b6;
case 0x0c0ab5b8u: goto P_0c0ab5b8;
case 0x0c0ab5bau: goto P_0c0ab5ba;
case 0x0c0ab5bcu: goto P_0c0ab5bc;
case 0x0c0ab5beu: goto P_0c0ab5be;
case 0x0c0ab5c0u: goto P_0c0ab5c0;
case 0x0c0ab5e4u: goto P_0c0ab5e4;
case 0x0c0ab5e6u: goto P_0c0ab5e6;
case 0x0c0ab5e8u: goto P_0c0ab5e8;
case 0x0c0ab5eau: goto P_0c0ab5ea;
case 0x0c0ab5ecu: goto P_0c0ab5ec;
case 0x0c0ab5eeu: goto P_0c0ab5ee;
case 0x0c0ab5f0u: goto P_0c0ab5f0;
case 0x0c0ab5f2u: goto P_0c0ab5f2;
case 0x0c0ab5f4u: goto P_0c0ab5f4;
case 0x0c0ab5f6u: goto P_0c0ab5f6;
case 0x0c0ab5f8u: goto P_0c0ab5f8;
case 0x0c0ab5fau: goto P_0c0ab5fa;
case 0x0c0ab5fcu: goto P_0c0ab5fc;
case 0x0c0ab5feu: goto P_0c0ab5fe;
case 0x0c0ab600u: goto P_0c0ab600;
case 0x0c0ab602u: goto P_0c0ab602;
case 0x0c0ab604u: goto P_0c0ab604;
case 0x0c0ab606u: goto P_0c0ab606;
case 0x0c0ab608u: goto P_0c0ab608;
case 0x0c0ab60au: goto P_0c0ab60a;
case 0x0c0ab60cu: goto P_0c0ab60c;
case 0x0c0ab60eu: goto P_0c0ab60e;
case 0x0c0ab610u: goto P_0c0ab610;
case 0x0c0ab612u: goto P_0c0ab612;
case 0x0c0ab614u: goto P_0c0ab614;
case 0x0c0ab616u: goto P_0c0ab616;
case 0x0c0ab618u: goto P_0c0ab618;
case 0x0c0ab61au: goto P_0c0ab61a;
case 0x0c0ab61cu: goto P_0c0ab61c;
case 0x0c0ab61eu: goto P_0c0ab61e;
case 0x0c0ab620u: goto P_0c0ab620;
case 0x0c0ab622u: goto P_0c0ab622;
case 0x0c0ab624u: goto P_0c0ab624;
case 0x0c0ab626u: goto P_0c0ab626;
case 0x0c0ab628u: goto P_0c0ab628;
case 0x0c0ab62au: goto P_0c0ab62a;
case 0x0c0ab62cu: goto P_0c0ab62c;
case 0x0c0ab62eu: goto P_0c0ab62e;
case 0x0c0ab630u: goto P_0c0ab630;
case 0x0c0ab632u: goto P_0c0ab632;
case 0x0c0ab634u: goto P_0c0ab634;
case 0x0c0ab636u: goto P_0c0ab636;
case 0x0c0ab638u: goto P_0c0ab638;
case 0x0c0ab63au: goto P_0c0ab63a;
case 0x0c0ab63cu: goto P_0c0ab63c;
case 0x0c0ab63eu: goto P_0c0ab63e;
case 0x0c0ab640u: goto P_0c0ab640;
case 0x0c0ab642u: goto P_0c0ab642;
case 0x0c0ab644u: goto P_0c0ab644;
case 0x0c0ab646u: goto P_0c0ab646;
case 0x0c0ab648u: goto P_0c0ab648;
case 0x0c0ab64au: goto P_0c0ab64a;
case 0x0c0ab64cu: goto P_0c0ab64c;
case 0x0c0ab64eu: goto P_0c0ab64e;
case 0x0c0ab650u: goto P_0c0ab650;
case 0x0c0ab652u: goto P_0c0ab652;
case 0x0c0ab654u: goto P_0c0ab654;
case 0x0c0ab656u: goto P_0c0ab656;
case 0x0c0ab658u: goto P_0c0ab658;
case 0x0c0ab65au: goto P_0c0ab65a;
case 0x0c0ab65cu: goto P_0c0ab65c;
case 0x0c0ab65eu: goto P_0c0ab65e;
case 0x0c0ab660u: goto P_0c0ab660;
case 0x0c0ab662u: goto P_0c0ab662;
case 0x0c0ab664u: goto P_0c0ab664;
case 0x0c0ab666u: goto P_0c0ab666;
case 0x0c0ab668u: goto P_0c0ab668;
case 0x0c0ab66au: goto P_0c0ab66a;
case 0x0c0ab66cu: goto P_0c0ab66c;
case 0x0c0ab66eu: goto P_0c0ab66e;
case 0x0c0ab670u: goto P_0c0ab670;
case 0x0c0ab672u: goto P_0c0ab672;
case 0x0c0ab674u: goto P_0c0ab674;
case 0x0c0ab676u: goto P_0c0ab676;
case 0x0c0ab678u: goto P_0c0ab678;
case 0x0c0ab67au: goto P_0c0ab67a;
case 0x0c0ab67cu: goto P_0c0ab67c;
case 0x0c0ab67eu: goto P_0c0ab67e;
case 0x0c0ab680u: goto P_0c0ab680;
case 0x0c0ab682u: goto P_0c0ab682;
case 0x0c0ab684u: goto P_0c0ab684;
case 0x0c0ab686u: goto P_0c0ab686;
case 0x0c0ab688u: goto P_0c0ab688;
case 0x0c0ab68au: goto P_0c0ab68a;
case 0x0c0ab68cu: goto P_0c0ab68c;
case 0x0c0ab68eu: goto P_0c0ab68e;
case 0x0c0ab690u: goto P_0c0ab690;
case 0x0c0ab692u: goto P_0c0ab692;
case 0x0c0ab694u: goto P_0c0ab694;
case 0x0c0ab696u: goto P_0c0ab696;
case 0x0c0ab698u: goto P_0c0ab698;
case 0x0c0ab69au: goto P_0c0ab69a;
case 0x0c0ab69cu: goto P_0c0ab69c;
case 0x0c0ab69eu: goto P_0c0ab69e;
case 0x0c0ab6a0u: goto P_0c0ab6a0;
case 0x0c0ab6a2u: goto P_0c0ab6a2;
case 0x0c0ab6a4u: goto P_0c0ab6a4;
case 0x0c0ab6a6u: goto P_0c0ab6a6;
case 0x0c0ab6a8u: goto P_0c0ab6a8;
case 0x0c0ab6aau: goto P_0c0ab6aa;
case 0x0c0ab6acu: goto P_0c0ab6ac;
case 0x0c0ab6aeu: goto P_0c0ab6ae;
case 0x0c0ab6b0u: goto P_0c0ab6b0;
case 0x0c0ab6b2u: goto P_0c0ab6b2;
case 0x0c0ab6b4u: goto P_0c0ab6b4;
case 0x0c0ab6b6u: goto P_0c0ab6b6;
case 0x0c0ab6b8u: goto P_0c0ab6b8;
case 0x0c0ab6bau: goto P_0c0ab6ba;
case 0x0c0ab6bcu: goto P_0c0ab6bc;
case 0x0c0ab6beu: goto P_0c0ab6be;
case 0x0c0ab6c0u: goto P_0c0ab6c0;
case 0x0c0ab6c2u: goto P_0c0ab6c2;
case 0x0c0ab6c4u: goto P_0c0ab6c4;
case 0x0c0ab6c6u: goto P_0c0ab6c6;
case 0x0c0ab6c8u: goto P_0c0ab6c8;
case 0x0c0ab6cau: goto P_0c0ab6ca;
case 0x0c0ab6ccu: goto P_0c0ab6cc;
case 0x0c0ab6ceu: goto P_0c0ab6ce;
case 0x0c0ab6d0u: goto P_0c0ab6d0;
case 0x0c0ab6d2u: goto P_0c0ab6d2;
case 0x0c0ab6d4u: goto P_0c0ab6d4;
case 0x0c0ab6d6u: goto P_0c0ab6d6;
case 0x0c0ab6d8u: goto P_0c0ab6d8;
case 0x0c0ab6dau: goto P_0c0ab6da;
case 0x0c0ab6dcu: goto P_0c0ab6dc;
case 0x0c0ab6deu: goto P_0c0ab6de;
case 0x0c0ab6e0u: goto P_0c0ab6e0;
case 0x0c0ab6e2u: goto P_0c0ab6e2;
case 0x0c0ab6e4u: goto P_0c0ab6e4;
case 0x0c0ab6e6u: goto P_0c0ab6e6;
case 0x0c0ab6e8u: goto P_0c0ab6e8;
case 0x0c0ab6eau: goto P_0c0ab6ea;
case 0x0c0ab6ecu: goto P_0c0ab6ec;
case 0x0c0ab6eeu: goto P_0c0ab6ee;
case 0x0c0ab6f0u: goto P_0c0ab6f0;
case 0x0c0ab6f2u: goto P_0c0ab6f2;
case 0x0c0ab71cu: goto P_0c0ab71c;
case 0x0c0ab71eu: goto P_0c0ab71e;
case 0x0c0ab720u: goto P_0c0ab720;
case 0x0c0ab722u: goto P_0c0ab722;
case 0x0c0ab724u: goto P_0c0ab724;
case 0x0c0ab726u: goto P_0c0ab726;
case 0x0c0ab728u: goto P_0c0ab728;
case 0x0c0ab72au: goto P_0c0ab72a;
case 0x0c0ab72cu: goto P_0c0ab72c;
case 0x0c0ab72eu: goto P_0c0ab72e;
case 0x0c0ab730u: goto P_0c0ab730;
case 0x0c0ab732u: goto P_0c0ab732;
case 0x0c0ab734u: goto P_0c0ab734;
case 0x0c0ab736u: goto P_0c0ab736;
case 0x0c0ab738u: goto P_0c0ab738;
case 0x0c0ab73au: goto P_0c0ab73a;
case 0x0c0ab73cu: goto P_0c0ab73c;
case 0x0c0ab73eu: goto P_0c0ab73e;
case 0x0c0ab740u: goto P_0c0ab740;
case 0x0c0ab742u: goto P_0c0ab742;
case 0x0c0ab744u: goto P_0c0ab744;
case 0x0c0ab746u: goto P_0c0ab746;
case 0x0c0ab748u: goto P_0c0ab748;
case 0x0c0ab74au: goto P_0c0ab74a;
case 0x0c0ab74cu: goto P_0c0ab74c;
case 0x0c0ab74eu: goto P_0c0ab74e;
case 0x0c0ab750u: goto P_0c0ab750;
case 0x0c0ab752u: goto P_0c0ab752;
case 0x0c0ab754u: goto P_0c0ab754;
case 0x0c0ab756u: goto P_0c0ab756;
case 0x0c0ab758u: goto P_0c0ab758;
case 0x0c0ab75au: goto P_0c0ab75a;
case 0x0c0ab75cu: goto P_0c0ab75c;
case 0x0c0ab75eu: goto P_0c0ab75e;
case 0x0c0ab760u: goto P_0c0ab760;
case 0x0c0ab762u: goto P_0c0ab762;
case 0x0c0ab764u: goto P_0c0ab764;
case 0x0c0ab766u: goto P_0c0ab766;
case 0x0c0ab768u: goto P_0c0ab768;
case 0x0c0ab76au: goto P_0c0ab76a;
case 0x0c0ab76cu: goto P_0c0ab76c;
case 0x0c0ab76eu: goto P_0c0ab76e;
case 0x0c0ab770u: goto P_0c0ab770;
case 0x0c0ab772u: goto P_0c0ab772;
case 0x0c0ab774u: goto P_0c0ab774;
case 0x0c0ab776u: goto P_0c0ab776;
case 0x0c0ab778u: goto P_0c0ab778;
case 0x0c0ab77au: goto P_0c0ab77a;
case 0x0c0ab77cu: goto P_0c0ab77c;
case 0x0c0ab77eu: goto P_0c0ab77e;
case 0x0c0ab780u: goto P_0c0ab780;
case 0x0c0ab782u: goto P_0c0ab782;
case 0x0c0ab784u: goto P_0c0ab784;
case 0x0c0ab786u: goto P_0c0ab786;
case 0x0c0ab788u: goto P_0c0ab788;
case 0x0c0ab78au: goto P_0c0ab78a;
case 0x0c0ab78cu: goto P_0c0ab78c;
case 0x0c0ab78eu: goto P_0c0ab78e;
case 0x0c0ab790u: goto P_0c0ab790;
case 0x0c0ab792u: goto P_0c0ab792;
case 0x0c0ab794u: goto P_0c0ab794;
case 0x0c0ab796u: goto P_0c0ab796;
case 0x0c0ab798u: goto P_0c0ab798;
case 0x0c0ab79au: goto P_0c0ab79a;
case 0x0c0ab79cu: goto P_0c0ab79c;
case 0x0c0ab79eu: goto P_0c0ab79e;
case 0x0c0ab7a0u: goto P_0c0ab7a0;
case 0x0c0ab7a2u: goto P_0c0ab7a2;
case 0x0c0ab7a4u: goto P_0c0ab7a4;
case 0x0c0ab7a6u: goto P_0c0ab7a6;
case 0x0c0ab7a8u: goto P_0c0ab7a8;
case 0x0c0ab7aau: goto P_0c0ab7aa;
case 0x0c0ab7acu: goto P_0c0ab7ac;
case 0x0c0ab7aeu: goto P_0c0ab7ae;
case 0x0c0ab7b0u: goto P_0c0ab7b0;
case 0x0c0ab7b2u: goto P_0c0ab7b2;
case 0x0c0ab7b4u: goto P_0c0ab7b4;
case 0x0c0ab7b6u: goto P_0c0ab7b6;
case 0x0c0ab7b8u: goto P_0c0ab7b8;
case 0x0c0ab7bau: goto P_0c0ab7ba;
case 0x0c0ab7bcu: goto P_0c0ab7bc;
case 0x0c0ab7beu: goto P_0c0ab7be;
case 0x0c0ab7c0u: goto P_0c0ab7c0;
case 0x0c0ab7c2u: goto P_0c0ab7c2;
case 0x0c0ab7c4u: goto P_0c0ab7c4;
case 0x0c0ab7c6u: goto P_0c0ab7c6;
case 0x0c0ab7c8u: goto P_0c0ab7c8;
case 0x0c0ab7cau: goto P_0c0ab7ca;
case 0x0c0ab7ccu: goto P_0c0ab7cc;
case 0x0c0ab7ceu: goto P_0c0ab7ce;
case 0x0c0ab7d0u: goto P_0c0ab7d0;
case 0x0c0ab7d2u: goto P_0c0ab7d2;
case 0x0c0ab7d4u: goto P_0c0ab7d4;
case 0x0c0ab7d6u: goto P_0c0ab7d6;
case 0x0c0ab7d8u: goto P_0c0ab7d8;
case 0x0c0ab7dau: goto P_0c0ab7da;
case 0x0c0ab7dcu: goto P_0c0ab7dc;
case 0x0c0ab7deu: goto P_0c0ab7de;
case 0x0c0ab7e0u: goto P_0c0ab7e0;
case 0x0c0ab7e2u: goto P_0c0ab7e2;
case 0x0c0ab7e4u: goto P_0c0ab7e4;
case 0x0c0ab7e6u: goto P_0c0ab7e6;
case 0x0c0ab7e8u: goto P_0c0ab7e8;
case 0x0c0ab7eau: goto P_0c0ab7ea;
case 0x0c0ab7ecu: goto P_0c0ab7ec;
case 0x0c0ab7eeu: goto P_0c0ab7ee;
case 0x0c0ab7f0u: goto P_0c0ab7f0;
case 0x0c0ab7f2u: goto P_0c0ab7f2;
case 0x0c0ab7f4u: goto P_0c0ab7f4;
case 0x0c0ab7f6u: goto P_0c0ab7f6;
case 0x0c0ab7f8u: goto P_0c0ab7f8;
case 0x0c0ab7fau: goto P_0c0ab7fa;
case 0x0c0ab7fcu: goto P_0c0ab7fc;
case 0x0c0ab7feu: goto P_0c0ab7fe;
case 0x0c0ab800u: goto P_0c0ab800;
case 0x0c0ab802u: goto P_0c0ab802;
case 0x0c0ab804u: goto P_0c0ab804;
case 0x0c0ab806u: goto P_0c0ab806;
case 0x0c0ab808u: goto P_0c0ab808;
case 0x0c0ab80au: goto P_0c0ab80a;
case 0x0c0ab80cu: goto P_0c0ab80c;
case 0x0c0ab80eu: goto P_0c0ab80e;
case 0x0c0ab810u: goto P_0c0ab810;
case 0x0c0ab812u: goto P_0c0ab812;
case 0x0c0ab814u: goto P_0c0ab814;
case 0x0c0ab816u: goto P_0c0ab816;
case 0x0c0ab818u: goto P_0c0ab818;
case 0x0c0ab81au: goto P_0c0ab81a;
case 0x0c0ab81cu: goto P_0c0ab81c;
case 0x0c0ab81eu: goto P_0c0ab81e;
case 0x0c0ab820u: goto P_0c0ab820;
case 0x0c0ab822u: goto P_0c0ab822;
case 0x0c0ab824u: goto P_0c0ab824;
case 0x0c0ab826u: goto P_0c0ab826;
case 0x0c0ab828u: goto P_0c0ab828;
case 0x0c0ab82au: goto P_0c0ab82a;
case 0x0c0ab82cu: goto P_0c0ab82c;
case 0x0c0ab82eu: goto P_0c0ab82e;
case 0x0c0ab830u: goto P_0c0ab830;
case 0x0c0ab832u: goto P_0c0ab832;
case 0x0c0ab834u: goto P_0c0ab834;
case 0x0c0ab836u: goto P_0c0ab836;
case 0x0c0ab838u: goto P_0c0ab838;
case 0x0c0ab83au: goto P_0c0ab83a;
case 0x0c0ab83cu: goto P_0c0ab83c;
case 0x0c0ab83eu: goto P_0c0ab83e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
if(!vf3_matrix_family(0x0c040f68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040f68u; return 0; } return 1;
P_0c069624: /* original f38d, guest PC 0x0c069624 */
if(!s->budget--) { s->failed_pc=0x0c069624u; return 0; }
fr[3]=0;
goto P_0c069626;
P_0c069626: /* original f534, guest PC 0x0c069626 */
if(!s->budget--) { s->failed_pc=0x0c069626u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c069628;
P_0c069628: /* original 8b03, guest PC 0x0c069628 */
if(!s->budget--) { s->failed_pc=0x0c069628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962a;
P_0c06962a: /* original f434, guest PC 0x0c06962a */
if(!s->budget--) { s->failed_pc=0x0c06962au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06962c;
P_0c06962c: /* original 8b01, guest PC 0x0c06962c */
if(!s->budget--) { s->failed_pc=0x0c06962cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962e;
P_0c06962e: /* original 000b, guest PC 0x0c06962e */
if(!s->budget--) { s->failed_pc=0x0c06962eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c069630: /* original e000, guest PC 0x0c069630 */
if(!s->budget--) { s->failed_pc=0x0c069630u; return 0; }
r[0]=0x00000000u;
goto P_0c069632;
P_0c069632: /* original f38d, guest PC 0x0c069632 */
if(!s->budget--) { s->failed_pc=0x0c069632u; return 0; }
fr[3]=0;
goto P_0c069634;
P_0c069634: /* original f355, guest PC 0x0c069634 */
if(!s->budget--) { s->failed_pc=0x0c069634u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c069636;
P_0c069636: /* original 8f03, guest PC 0x0c069636 */
if(!s->budget--) { s->failed_pc=0x0c069636u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(!cond) { goto P_0c069640; }
goto P_0c06963a;
P_0c069638: /* original f38d, guest PC 0x0c069638 */
if(!s->budget--) { s->failed_pc=0x0c069638u; return 0; }
fr[3]=0;
goto P_0c06963a;
P_0c06963a: /* original f65c, guest PC 0x0c06963a */
if(!s->budget--) { s->failed_pc=0x0c06963au; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c06963c;
P_0c06963c: /* original a001, guest PC 0x0c06963c */
if(!s->budget--) { s->failed_pc=0x0c06963cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069642;
P_0c06963e: /* original f64d, guest PC 0x0c06963e */
if(!s->budget--) { s->failed_pc=0x0c06963eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069640;
P_0c069640: /* original f65c, guest PC 0x0c069640 */
if(!s->budget--) { s->failed_pc=0x0c069640u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c069642;
P_0c069642: /* original f345, guest PC 0x0c069642 */
if(!s->budget--) { s->failed_pc=0x0c069642u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069644;
P_0c069644: /* original 8b02, guest PC 0x0c069644 */
if(!s->budget--) { s->failed_pc=0x0c069644u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06964c; }
goto P_0c069646;
P_0c069646: /* original f74c, guest PC 0x0c069646 */
if(!s->budget--) { s->failed_pc=0x0c069646u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c069648;
P_0c069648: /* original a001, guest PC 0x0c069648 */
if(!s->budget--) { s->failed_pc=0x0c069648u; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964e;
P_0c06964a: /* original f74d, guest PC 0x0c06964a */
if(!s->budget--) { s->failed_pc=0x0c06964au; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964c;
P_0c06964c: /* original f74c, guest PC 0x0c06964c */
if(!s->budget--) { s->failed_pc=0x0c06964cu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06964e;
P_0c06964e: /* original f675, guest PC 0x0c06964e */
if(!s->budget--) { s->failed_pc=0x0c06964eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c069650;
P_0c069650: /* original 8b02, guest PC 0x0c069650 */
if(!s->budget--) { s->failed_pc=0x0c069650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069658; }
goto P_0c069652;
P_0c069652: /* original f87c, guest PC 0x0c069652 */
if(!s->budget--) { s->failed_pc=0x0c069652u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c069654;
P_0c069654: /* original a002, guest PC 0x0c069654 */
if(!s->budget--) { s->failed_pc=0x0c069654u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c06965c;
P_0c069656: /* original f863, guest PC 0x0c069656 */
if(!s->budget--) { s->failed_pc=0x0c069656u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c069658;
P_0c069658: /* original f86c, guest PC 0x0c069658 */
if(!s->budget--) { s->failed_pc=0x0c069658u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06965a;
P_0c06965a: /* original f873, guest PC 0x0c06965a */
if(!s->budget--) { s->failed_pc=0x0c06965au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'/');
goto P_0c06965c;
P_0c06965c: /* original c711, guest PC 0x0c06965c */
if(!s->budget--) { s->failed_pc=0x0c06965cu; return 0; }
r[0]=code_base|0x000696a4u;
goto P_0c06965e;
P_0c06965e: /* original f28c, guest PC 0x0c06965e */
if(!s->budget--) { s->failed_pc=0x0c06965eu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c069660;
P_0c069660: /* original f308, guest PC 0x0c069660 */
if(!s->budget--) { s->failed_pc=0x0c069660u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069662;
P_0c069662: /* original d011, guest PC 0x0c069662 */
if(!s->budget--) { s->failed_pc=0x0c069662u; return 0; }
r[0]=read(ram,0x0c0696a8u,4);
goto P_0c069664;
P_0c069664: /* original f232, guest PC 0x0c069664 */
if(!s->budget--) { s->failed_pc=0x0c069664u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c069666;
P_0c069666: /* original f23d, guest PC 0x0c069666 */
if(!s->budget--) { s->failed_pc=0x0c069666u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c069668;
P_0c069668: /* original 045a, guest PC 0x0c069668 */
if(!s->budget--) { s->failed_pc=0x0c069668u; return 0; }
r[4]=r[53];
goto P_0c06966a;
P_0c06966a: /* original 4400, guest PC 0x0c06966a */
if(!s->budget--) { s->failed_pc=0x0c06966au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06966c;
P_0c06966c: /* original f765, guest PC 0x0c06966c */
if(!s->budget--) { s->failed_pc=0x0c06966cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[6]))!=0);
goto P_0c06966e;
P_0c06966e: /* original 8f03, guest PC 0x0c06966e */
if(!s->budget--) { s->failed_pc=0x0c06966eu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!cond) { goto P_0c069678; }
goto P_0c069672;
P_0c069670: /* original 044d, guest PC 0x0c069670 */
if(!s->budget--) { s->failed_pc=0x0c069670u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c069672;
P_0c069672: /* original 9214, guest PC 0x0c069672 */
if(!s->budget--) { s->failed_pc=0x0c069672u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06969eu,2);
goto P_0c069674;
P_0c069674: /* original 3248, guest PC 0x0c069674 */
if(!s->budget--) { s->failed_pc=0x0c069674u; return 0; }
r[2]-=r[4];
goto P_0c069676;
P_0c069676: /* original 6423, guest PC 0x0c069676 */
if(!s->budget--) { s->failed_pc=0x0c069676u; return 0; }
r[4]=r[2];
goto P_0c069678;
P_0c069678: /* original f38d, guest PC 0x0c069678 */
if(!s->budget--) { s->failed_pc=0x0c069678u; return 0; }
fr[3]=0;
goto P_0c06967a;
P_0c06967a: /* original f355, guest PC 0x0c06967a */
if(!s->budget--) { s->failed_pc=0x0c06967au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c06967c;
P_0c06967c: /* original 8904, guest PC 0x0c06967c */
if(!s->budget--) { s->failed_pc=0x0c06967cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069688; }
goto P_0c06967e;
P_0c06967e: /* original f38d, guest PC 0x0c06967e */
if(!s->budget--) { s->failed_pc=0x0c06967eu; return 0; }
fr[3]=0;
goto P_0c069680;
P_0c069680: /* original f345, guest PC 0x0c069680 */
if(!s->budget--) { s->failed_pc=0x0c069680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069682;
P_0c069682: /* original 8b09, guest PC 0x0c069682 */
if(!s->budget--) { s->failed_pc=0x0c069682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069698; }
goto P_0c069684;
P_0c069684: /* original a008, guest PC 0x0c069684 */
if(!s->budget--) { s->failed_pc=0x0c069684u; return 0; }
r[4]=0u-r[4];
goto P_0c069698;
P_0c069686: /* original 644b, guest PC 0x0c069686 */
if(!s->budget--) { s->failed_pc=0x0c069686u; return 0; }
r[4]=0u-r[4];
goto P_0c069688;
P_0c069688: /* original f345, guest PC 0x0c069688 */
if(!s->budget--) { s->failed_pc=0x0c069688u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06968a;
P_0c06968a: /* original 8903, guest PC 0x0c06968a */
if(!s->budget--) { s->failed_pc=0x0c06968au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069694; }
goto P_0c06968c;
P_0c06968c: /* original d207, guest PC 0x0c06968c */
if(!s->budget--) { s->failed_pc=0x0c06968cu; return 0; }
r[2]=read(ram,0x0c0696acu,4);
goto P_0c06968e;
P_0c06968e: /* original 3248, guest PC 0x0c06968e */
if(!s->budget--) { s->failed_pc=0x0c06968eu; return 0; }
r[2]-=r[4];
goto P_0c069690;
P_0c069690: /* original a002, guest PC 0x0c069690 */
if(!s->budget--) { s->failed_pc=0x0c069690u; return 0; }
r[4]=r[2];
goto P_0c069698;
P_0c069692: /* original 6423, guest PC 0x0c069692 */
if(!s->budget--) { s->failed_pc=0x0c069692u; return 0; }
r[4]=r[2];
goto P_0c069694;
P_0c069694: /* original 9104, guest PC 0x0c069694 */
if(!s->budget--) { s->failed_pc=0x0c069694u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0696a0u,2);
goto P_0c069696;
P_0c069696: /* original 341c, guest PC 0x0c069696 */
if(!s->budget--) { s->failed_pc=0x0c069696u; return 0; }
r[4]+=r[1];
goto P_0c069698;
P_0c069698: /* original 6043, guest PC 0x0c069698 */
if(!s->budget--) { s->failed_pc=0x0c069698u; return 0; }
r[0]=r[4];
goto P_0c06969a;
P_0c06969a: /* original 000b, guest PC 0x0c06969a */
if(!s->budget--) { s->failed_pc=0x0c06969au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06969c: /* original 0009, guest PC 0x0c06969c */
if(!s->budget--) { s->failed_pc=0x0c06969cu; return 0; }
if(!vf3_matrix_family(0x0c06969eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06969eu; return 0; } return 1;
P_0c09d5ae: /* original 6543, guest PC 0x0c09d5ae */
if(!s->budget--) { s->failed_pc=0x0c09d5aeu; return 0; }
r[5]=r[4];
goto P_0c09d5b0;
P_0c09d5b0: /* original e03c, guest PC 0x0c09d5b0 */
if(!s->budget--) { s->failed_pc=0x0c09d5b0u; return 0; }
r[0]=0x0000003cu;
goto P_0c09d5b2;
P_0c09d5b2: /* original 7ffc, guest PC 0x0c09d5b2 */
if(!s->budget--) { s->failed_pc=0x0c09d5b2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09d5b4;
P_0c09d5b4: /* original 2f42, guest PC 0x0c09d5b4 */
if(!s->budget--) { s->failed_pc=0x0c09d5b4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d5b6;
P_0c09d5b6: /* original 055d, guest PC 0x0c09d5b6 */
if(!s->budget--) { s->failed_pc=0x0c09d5b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c09d5b8;
P_0c09d5b8: /* original 655d, guest PC 0x0c09d5b8 */
if(!s->budget--) { s->failed_pc=0x0c09d5b8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09d5ba;
P_0c09d5ba: /* original a000, guest PC 0x0c09d5ba */
if(!s->budget--) { s->failed_pc=0x0c09d5bau; return 0; }
r[15]+=0x00000004u;
goto P_0c09d5be;
P_0c09d5bc: /* original 7f04, guest PC 0x0c09d5bc */
if(!s->budget--) { s->failed_pc=0x0c09d5bcu; return 0; }
r[15]+=0x00000004u;
goto P_0c09d5be;
P_0c09d5be: /* original 75ff, guest PC 0x0c09d5be */
if(!s->budget--) { s->failed_pc=0x0c09d5beu; return 0; }
r[5]+=0xffffffffu;
goto P_0c09d5c0;
P_0c09d5c0: /* original d346, guest PC 0x0c09d5c0 */
if(!s->budget--) { s->failed_pc=0x0c09d5c0u; return 0; }
r[3]=read(ram,0x0c09d6dcu,4);
goto P_0c09d5c2;
P_0c09d5c2: /* original 6253, guest PC 0x0c09d5c2 */
if(!s->budget--) { s->failed_pc=0x0c09d5c2u; return 0; }
r[2]=r[5];
goto P_0c09d5c4;
P_0c09d5c4: /* original 4500, guest PC 0x0c09d5c4 */
if(!s->budget--) { s->failed_pc=0x0c09d5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c09d5c6;
P_0c09d5c6: /* original 6632, guest PC 0x0c09d5c6 */
if(!s->budget--) { s->failed_pc=0x0c09d5c6u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c09d5c8;
P_0c09d5c8: /* original 352c, guest PC 0x0c09d5c8 */
if(!s->budget--) { s->failed_pc=0x0c09d5c8u; return 0; }
r[5]+=r[2];
goto P_0c09d5ca;
P_0c09d5ca: /* original 4508, guest PC 0x0c09d5ca */
if(!s->budget--) { s->failed_pc=0x0c09d5cau; return 0; }
r[5]<<=2;
goto P_0c09d5cc;
P_0c09d5cc: /* original 356c, guest PC 0x0c09d5cc */
if(!s->budget--) { s->failed_pc=0x0c09d5ccu; return 0; }
r[5]+=r[6];
goto P_0c09d5ce;
P_0c09d5ce: /* original 5151, guest PC 0x0c09d5ce */
if(!s->budget--) { s->failed_pc=0x0c09d5ceu; return 0; }
r[1]=read(ram,r[5]+4,4);
goto P_0c09d5d0;
P_0c09d5d0: /* original 7ff8, guest PC 0x0c09d5d0 */
if(!s->budget--) { s->failed_pc=0x0c09d5d0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09d5d2;
P_0c09d5d2: /* original 6752, guest PC 0x0c09d5d2 */
if(!s->budget--) { s->failed_pc=0x0c09d5d2u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c09d5d4;
P_0c09d5d4: /* original 316c, guest PC 0x0c09d5d4 */
if(!s->budget--) { s->failed_pc=0x0c09d5d4u; return 0; }
r[1]+=r[6];
goto P_0c09d5d6;
P_0c09d5d6: /* original 376c, guest PC 0x0c09d5d6 */
if(!s->budget--) { s->failed_pc=0x0c09d5d6u; return 0; }
r[7]+=r[6];
goto P_0c09d5d8;
P_0c09d5d8: /* original 2f12, guest PC 0x0c09d5d8 */
if(!s->budget--) { s->failed_pc=0x0c09d5d8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c09d5da;
P_0c09d5da: /* original 5252, guest PC 0x0c09d5da */
if(!s->budget--) { s->failed_pc=0x0c09d5dau; return 0; }
r[2]=read(ram,r[5]+8,4);
goto P_0c09d5dc;
P_0c09d5dc: /* original e104, guest PC 0x0c09d5dc */
if(!s->budget--) { s->failed_pc=0x0c09d5dcu; return 0; }
r[1]=0x00000004u;
goto P_0c09d5de;
P_0c09d5de: /* original 362c, guest PC 0x0c09d5de */
if(!s->budget--) { s->failed_pc=0x0c09d5deu; return 0; }
r[6]+=r[2];
goto P_0c09d5e0;
P_0c09d5e0: /* original 1f61, guest PC 0x0c09d5e0 */
if(!s->budget--) { s->failed_pc=0x0c09d5e0u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c09d5e2;
P_0c09d5e2: /* original 6673, guest PC 0x0c09d5e2 */
if(!s->budget--) { s->failed_pc=0x0c09d5e2u; return 0; }
r[6]=r[7];
goto P_0c09d5e4;
P_0c09d5e4: /* original 9073, guest PC 0x0c09d5e4 */
if(!s->budget--) { s->failed_pc=0x0c09d5e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6ceu,2);
goto P_0c09d5e6;
P_0c09d5e6: /* original 7602, guest PC 0x0c09d5e6 */
if(!s->budget--) { s->failed_pc=0x0c09d5e6u; return 0; }
r[6]+=0x00000002u;
goto P_0c09d5e8;
P_0c09d5e8: /* original 6571, guest PC 0x0c09d5e8 */
if(!s->budget--) { s->failed_pc=0x0c09d5e8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[5]=tmp;
goto P_0c09d5ea;
P_0c09d5ea: /* original 024c, guest PC 0x0c09d5ea */
if(!s->budget--) { s->failed_pc=0x0c09d5eau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09d5ec;
P_0c09d5ec: /* original 701d, guest PC 0x0c09d5ec */
if(!s->budget--) { s->failed_pc=0x0c09d5ecu; return 0; }
r[0]+=0x0000001du;
goto P_0c09d5ee;
P_0c09d5ee: /* original 655d, guest PC 0x0c09d5ee */
if(!s->budget--) { s->failed_pc=0x0c09d5eeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c09d5f0;
P_0c09d5f0: /* original 0424, guest PC 0x0c09d5f0 */
if(!s->budget--) { s->failed_pc=0x0c09d5f0u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09d5f2;
P_0c09d5f2: /* original e2f4, guest PC 0x0c09d5f2 */
if(!s->budget--) { s->failed_pc=0x0c09d5f2u; return 0; }
r[2]=0xfffffff4u;
goto P_0c09d5f4;
P_0c09d5f4: /* original 452c, guest PC 0x0c09d5f4 */
if(!s->budget--) { s->failed_pc=0x0c09d5f4u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c09d5f6;
P_0c09d5f6: /* original 70e3, guest PC 0x0c09d5f6 */
if(!s->budget--) { s->failed_pc=0x0c09d5f6u; return 0; }
r[0]+=0xffffffe3u;
goto P_0c09d5f8;
P_0c09d5f8: /* original 2519, guest PC 0x0c09d5f8 */
if(!s->budget--) { s->failed_pc=0x0c09d5f8u; return 0; }
r[5]&=r[1];
goto P_0c09d5fa;
P_0c09d5fa: /* original 0454, guest PC 0x0c09d5fa */
if(!s->budget--) { s->failed_pc=0x0c09d5fau; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c09d5fc;
P_0c09d5fc: /* original 9068, guest PC 0x0c09d5fc */
if(!s->budget--) { s->failed_pc=0x0c09d5fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6d0u,2);
goto P_0c09d5fe;
P_0c09d5fe: /* original 044e, guest PC 0x0c09d5fe */
if(!s->budget--) { s->failed_pc=0x0c09d5feu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09d600;
P_0c09d600: /* original 6563, guest PC 0x0c09d600 */
if(!s->budget--) { s->failed_pc=0x0c09d600u; return 0; }
r[5]=r[6];
goto P_0c09d602;
P_0c09d602: /* original 750f, guest PC 0x0c09d602 */
if(!s->budget--) { s->failed_pc=0x0c09d602u; return 0; }
r[5]+=0x0000000fu;
goto P_0c09d604;
P_0c09d604: /* original 53f1, guest PC 0x0c09d604 */
if(!s->budget--) { s->failed_pc=0x0c09d604u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d606;
P_0c09d606: /* original e110, guest PC 0x0c09d606 */
if(!s->budget--) { s->failed_pc=0x0c09d606u; return 0; }
r[1]=0x00000010u;
goto P_0c09d608;
P_0c09d608: /* original 1432, guest PC 0x0c09d608 */
if(!s->budget--) { s->failed_pc=0x0c09d608u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c09d60a;
P_0c09d60a: /* original 62f2, guest PC 0x0c09d60a */
if(!s->budget--) { s->failed_pc=0x0c09d60au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09d60c;
P_0c09d60c: /* original 1421, guest PC 0x0c09d60c */
if(!s->budget--) { s->failed_pc=0x0c09d60cu; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c09d60e;
P_0c09d60e: /* original 6263, guest PC 0x0c09d60e */
if(!s->budget--) { s->failed_pc=0x0c09d60eu; return 0; }
r[2]=r[6];
goto P_0c09d610;
P_0c09d610: /* original e600, guest PC 0x0c09d610 */
if(!s->budget--) { s->failed_pc=0x0c09d610u; return 0; }
r[6]=0x00000000u;
goto P_0c09d612;
P_0c09d612: /* original 2452, guest PC 0x0c09d612 */
if(!s->budget--) { s->failed_pc=0x0c09d612u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c09d614;
P_0c09d614: /* original 6563, guest PC 0x0c09d614 */
if(!s->budget--) { s->failed_pc=0x0c09d614u; return 0; }
r[5]=r[6];
goto P_0c09d616;
P_0c09d616: /* original 6763, guest PC 0x0c09d616 */
if(!s->budget--) { s->failed_pc=0x0c09d616u; return 0; }
r[7]=r[6];
goto P_0c09d618;
P_0c09d618: /* original 6624, guest PC 0x0c09d618 */
if(!s->budget--) { s->failed_pc=0x0c09d618u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[6]=tmp;
goto P_0c09d61a;
P_0c09d61a: /* original 6343, guest PC 0x0c09d61a */
if(!s->budget--) { s->failed_pc=0x0c09d61au; return 0; }
r[3]=r[4];
goto P_0c09d61c;
P_0c09d61c: /* original 730c, guest PC 0x0c09d61c */
if(!s->budget--) { s->failed_pc=0x0c09d61cu; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d61e;
P_0c09d61e: /* original 666c, guest PC 0x0c09d61e */
if(!s->budget--) { s->failed_pc=0x0c09d61eu; return 0; }
r[6]=r[6]&255u;
goto P_0c09d620;
P_0c09d620: /* original 6063, guest PC 0x0c09d620 */
if(!s->budget--) { s->failed_pc=0x0c09d620u; return 0; }
r[0]=r[6];
goto P_0c09d622;
P_0c09d622: /* original 4009, guest PC 0x0c09d622 */
if(!s->budget--) { s->failed_pc=0x0c09d622u; return 0; }
r[0]>>=2;
goto P_0c09d624;
P_0c09d624: /* original 4009, guest PC 0x0c09d624 */
if(!s->budget--) { s->failed_pc=0x0c09d624u; return 0; }
r[0]>>=2;
goto P_0c09d626;
P_0c09d626: /* original 4009, guest PC 0x0c09d626 */
if(!s->budget--) { s->failed_pc=0x0c09d626u; return 0; }
r[0]>>=2;
goto P_0c09d628;
P_0c09d628: /* original c903, guest PC 0x0c09d628 */
if(!s->budget--) { s->failed_pc=0x0c09d628u; return 0; }
r[0]&=3u;
goto P_0c09d62a;
P_0c09d62a: /* original 335c, guest PC 0x0c09d62a */
if(!s->budget--) { s->failed_pc=0x0c09d62au; return 0; }
r[3]+=r[5];
goto P_0c09d62c;
P_0c09d62c: /* original 2300, guest PC 0x0c09d62c */
if(!s->budget--) { s->failed_pc=0x0c09d62cu; return 0; }
write(ram,r[3],r[0],1);
goto P_0c09d62e;
P_0c09d62e: /* original 6063, guest PC 0x0c09d62e */
if(!s->budget--) { s->failed_pc=0x0c09d62eu; return 0; }
r[0]=r[6];
goto P_0c09d630;
P_0c09d630: /* original 4009, guest PC 0x0c09d630 */
if(!s->budget--) { s->failed_pc=0x0c09d630u; return 0; }
r[0]>>=2;
goto P_0c09d632;
P_0c09d632: /* original 6343, guest PC 0x0c09d632 */
if(!s->budget--) { s->failed_pc=0x0c09d632u; return 0; }
r[3]=r[4];
goto P_0c09d634;
P_0c09d634: /* original 4009, guest PC 0x0c09d634 */
if(!s->budget--) { s->failed_pc=0x0c09d634u; return 0; }
r[0]>>=2;
goto P_0c09d636;
P_0c09d636: /* original 730c, guest PC 0x0c09d636 */
if(!s->budget--) { s->failed_pc=0x0c09d636u; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d638;
P_0c09d638: /* original c903, guest PC 0x0c09d638 */
if(!s->budget--) { s->failed_pc=0x0c09d638u; return 0; }
r[0]&=3u;
goto P_0c09d63a;
P_0c09d63a: /* original 335c, guest PC 0x0c09d63a */
if(!s->budget--) { s->failed_pc=0x0c09d63au; return 0; }
r[3]+=r[5];
goto P_0c09d63c;
P_0c09d63c: /* original 8031, guest PC 0x0c09d63c */
if(!s->budget--) { s->failed_pc=0x0c09d63cu; return 0; }
write(ram,r[3]+1,r[0],1);
goto P_0c09d63e;
P_0c09d63e: /* original 6063, guest PC 0x0c09d63e */
if(!s->budget--) { s->failed_pc=0x0c09d63eu; return 0; }
r[0]=r[6];
goto P_0c09d640;
P_0c09d640: /* original 6343, guest PC 0x0c09d640 */
if(!s->budget--) { s->failed_pc=0x0c09d640u; return 0; }
r[3]=r[4];
goto P_0c09d642;
P_0c09d642: /* original 4009, guest PC 0x0c09d642 */
if(!s->budget--) { s->failed_pc=0x0c09d642u; return 0; }
r[0]>>=2;
goto P_0c09d644;
P_0c09d644: /* original 730c, guest PC 0x0c09d644 */
if(!s->budget--) { s->failed_pc=0x0c09d644u; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d646;
P_0c09d646: /* original c903, guest PC 0x0c09d646 */
if(!s->budget--) { s->failed_pc=0x0c09d646u; return 0; }
r[0]&=3u;
goto P_0c09d648;
P_0c09d648: /* original 335c, guest PC 0x0c09d648 */
if(!s->budget--) { s->failed_pc=0x0c09d648u; return 0; }
r[3]+=r[5];
goto P_0c09d64a;
P_0c09d64a: /* original 8032, guest PC 0x0c09d64a */
if(!s->budget--) { s->failed_pc=0x0c09d64au; return 0; }
write(ram,r[3]+2,r[0],1);
goto P_0c09d64c;
P_0c09d64c: /* original 6343, guest PC 0x0c09d64c */
if(!s->budget--) { s->failed_pc=0x0c09d64cu; return 0; }
r[3]=r[4];
goto P_0c09d64e;
P_0c09d64e: /* original e003, guest PC 0x0c09d64e */
if(!s->budget--) { s->failed_pc=0x0c09d64eu; return 0; }
r[0]=0x00000003u;
goto P_0c09d650;
P_0c09d650: /* original 730c, guest PC 0x0c09d650 */
if(!s->budget--) { s->failed_pc=0x0c09d650u; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d652;
P_0c09d652: /* original 2069, guest PC 0x0c09d652 */
if(!s->budget--) { s->failed_pc=0x0c09d652u; return 0; }
r[0]&=r[6];
goto P_0c09d654;
P_0c09d654: /* original 335c, guest PC 0x0c09d654 */
if(!s->budget--) { s->failed_pc=0x0c09d654u; return 0; }
r[3]+=r[5];
goto P_0c09d656;
P_0c09d656: /* original 8033, guest PC 0x0c09d656 */
if(!s->budget--) { s->failed_pc=0x0c09d656u; return 0; }
write(ram,r[3]+3,r[0],1);
goto P_0c09d658;
P_0c09d658: /* original 7701, guest PC 0x0c09d658 */
if(!s->budget--) { s->failed_pc=0x0c09d658u; return 0; }
r[7]+=0x00000001u;
goto P_0c09d65a;
P_0c09d65a: /* original 3712, guest PC 0x0c09d65a */
if(!s->budget--) { s->failed_pc=0x0c09d65au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[1])!=0);
goto P_0c09d65c;
P_0c09d65c: /* original 8fdc, guest PC 0x0c09d65c */
if(!s->budget--) { s->failed_pc=0x0c09d65cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c09d618; }
goto P_0c09d660;
P_0c09d65e: /* original 7504, guest PC 0x0c09d65e */
if(!s->budget--) { s->failed_pc=0x0c09d65eu; return 0; }
r[5]+=0x00000004u;
goto P_0c09d660;
P_0c09d660: /* original 000b, guest PC 0x0c09d660 */
if(!s->budget--) { s->failed_pc=0x0c09d660u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c09d662: /* original 7f08, guest PC 0x0c09d662 */
if(!s->budget--) { s->failed_pc=0x0c09d662u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c09d664u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d664u; return 0; } return 1;
P_0c09efd8: /* original e03e, guest PC 0x0c09efd8 */
if(!s->budget--) { s->failed_pc=0x0c09efd8u; return 0; }
r[0]=0x0000003eu;
goto P_0c09efda;
P_0c09efda: /* original e301, guest PC 0x0c09efda */
if(!s->budget--) { s->failed_pc=0x0c09efdau; return 0; }
r[3]=0x00000001u;
goto P_0c09efdc;
P_0c09efdc: /* original 0435, guest PC 0x0c09efdc */
if(!s->budget--) { s->failed_pc=0x0c09efdcu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efde;
P_0c09efde: /* original e040, guest PC 0x0c09efde */
if(!s->budget--) { s->failed_pc=0x0c09efdeu; return 0; }
r[0]=0x00000040u;
goto P_0c09efe0;
P_0c09efe0: /* original e200, guest PC 0x0c09efe0 */
if(!s->budget--) { s->failed_pc=0x0c09efe0u; return 0; }
r[2]=0x00000000u;
goto P_0c09efe2;
P_0c09efe2: /* original 000b, guest PC 0x0c09efe2 */
if(!s->budget--) { s->failed_pc=0x0c09efe2u; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[2],2);
s->pc=target; return ram->oob==0;
P_0c09efe4: /* original 0425, guest PC 0x0c09efe4 */
if(!s->budget--) { s->failed_pc=0x0c09efe4u; return 0; }
write(ram,r[4]+r[0],r[2],2);
if(!vf3_matrix_family(0x0c09efe6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09efe6u; return 0; } return 1;
P_0c09f1ac: /* original e048, guest PC 0x0c09f1ac */
if(!s->budget--) { s->failed_pc=0x0c09f1acu; return 0; }
r[0]=0x00000048u;
goto P_0c09f1ae;
P_0c09f1ae: /* original 2fe6, guest PC 0x0c09f1ae */
if(!s->budget--) { s->failed_pc=0x0c09f1aeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b0;
P_0c09f1b0: /* original 2fd6, guest PC 0x0c09f1b0 */
if(!s->budget--) { s->failed_pc=0x0c09f1b0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b2;
P_0c09f1b2: /* original e304, guest PC 0x0c09f1b2 */
if(!s->budget--) { s->failed_pc=0x0c09f1b2u; return 0; }
r[3]=0x00000004u;
goto P_0c09f1b4;
P_0c09f1b4: /* original 2fc6, guest PC 0x0c09f1b4 */
if(!s->budget--) { s->failed_pc=0x0c09f1b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b6;
P_0c09f1b6: /* original e520, guest PC 0x0c09f1b6 */
if(!s->budget--) { s->failed_pc=0x0c09f1b6u; return 0; }
r[5]=0x00000020u;
goto P_0c09f1b8;
P_0c09f1b8: /* original 2fb6, guest PC 0x0c09f1b8 */
if(!s->budget--) { s->failed_pc=0x0c09f1b8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1ba;
P_0c09f1ba: /* original e210, guest PC 0x0c09f1ba */
if(!s->budget--) { s->failed_pc=0x0c09f1bau; return 0; }
r[2]=0x00000010u;
goto P_0c09f1bc;
P_0c09f1bc: /* original 2fa6, guest PC 0x0c09f1bc */
if(!s->budget--) { s->failed_pc=0x0c09f1bcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1be;
P_0c09f1be: /* original e700, guest PC 0x0c09f1be */
if(!s->budget--) { s->failed_pc=0x0c09f1beu; return 0; }
r[7]=0x00000000u;
goto P_0c09f1c0;
P_0c09f1c0: /* original 2f96, guest PC 0x0c09f1c0 */
if(!s->budget--) { s->failed_pc=0x0c09f1c0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1c2;
P_0c09f1c2: /* original 2f86, guest PC 0x0c09f1c2 */
if(!s->budget--) { s->failed_pc=0x0c09f1c2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1c4;
P_0c09f1c4: /* original 064e, guest PC 0x0c09f1c4 */
if(!s->budget--) { s->failed_pc=0x0c09f1c4u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c09f1c6;
P_0c09f1c6: /* original 7fec, guest PC 0x0c09f1c6 */
if(!s->budget--) { s->failed_pc=0x0c09f1c6u; return 0; }
r[15]+=0xffffffecu;
goto P_0c09f1c8;
P_0c09f1c8: /* original 2f32, guest PC 0x0c09f1c8 */
if(!s->budget--) { s->failed_pc=0x0c09f1c8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09f1ca;
P_0c09f1ca: /* original 9042, guest PC 0x0c09f1ca */
if(!s->budget--) { s->failed_pc=0x0c09f1cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f252u,2);
goto P_0c09f1cc;
P_0c09f1cc: /* original dc23, guest PC 0x0c09f1cc */
if(!s->budget--) { s->failed_pc=0x0c09f1ccu; return 0; }
r[12]=read(ram,0x0c09f25cu,4);
goto P_0c09f1ce;
P_0c09f1ce: /* original 0e4c, guest PC 0x0c09f1ce */
if(!s->budget--) { s->failed_pc=0x0c09f1ceu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f1d0;
P_0c09f1d0: /* original db21, guest PC 0x0c09f1d0 */
if(!s->budget--) { s->failed_pc=0x0c09f1d0u; return 0; }
r[11]=read(ram,0x0c09f258u,4);
goto P_0c09f1d2;
P_0c09f1d2: /* original 6eec, guest PC 0x0c09f1d2 */
if(!s->budget--) { s->failed_pc=0x0c09f1d2u; return 0; }
r[14]=r[14]&255u;
goto P_0c09f1d4;
P_0c09f1d4: /* original 60e3, guest PC 0x0c09f1d4 */
if(!s->budget--) { s->failed_pc=0x0c09f1d4u; return 0; }
r[0]=r[14];
goto P_0c09f1d6;
P_0c09f1d6: /* original 4001, guest PC 0x0c09f1d6 */
if(!s->budget--) { s->failed_pc=0x0c09f1d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c09f1d8;
P_0c09f1d8: /* original 6303, guest PC 0x0c09f1d8 */
if(!s->budget--) { s->failed_pc=0x0c09f1d8u; return 0; }
r[3]=r[0];
goto P_0c09f1da;
P_0c09f1da: /* original 60e3, guest PC 0x0c09f1da */
if(!s->budget--) { s->failed_pc=0x0c09f1dau; return 0; }
r[0]=r[14];
goto P_0c09f1dc;
P_0c09f1dc: /* original c901, guest PC 0x0c09f1dc */
if(!s->budget--) { s->failed_pc=0x0c09f1dcu; return 0; }
r[0]&=1u;
goto P_0c09f1de;
P_0c09f1de: /* original 4005, guest PC 0x0c09f1de */
if(!s->budget--) { s->failed_pc=0x0c09f1deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c09f1e0;
P_0c09f1e0: /* original 203b, guest PC 0x0c09f1e0 */
if(!s->budget--) { s->failed_pc=0x0c09f1e0u; return 0; }
r[0]|=r[3];
goto P_0c09f1e2;
P_0c09f1e2: /* original 2509, guest PC 0x0c09f1e2 */
if(!s->budget--) { s->failed_pc=0x0c09f1e2u; return 0; }
r[5]&=r[0];
goto P_0c09f1e4;
P_0c09f1e4: /* original 9036, guest PC 0x0c09f1e4 */
if(!s->budget--) { s->failed_pc=0x0c09f1e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f254u,2);
goto P_0c09f1e6;
P_0c09f1e6: /* original 252b, guest PC 0x0c09f1e6 */
if(!s->budget--) { s->failed_pc=0x0c09f1e6u; return 0; }
r[5]|=r[2];
goto P_0c09f1e8;
P_0c09f1e8: /* original 034c, guest PC 0x0c09f1e8 */
if(!s->budget--) { s->failed_pc=0x0c09f1e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f1ea;
P_0c09f1ea: /* original 633c, guest PC 0x0c09f1ea */
if(!s->budget--) { s->failed_pc=0x0c09f1eau; return 0; }
r[3]=r[3]&255u;
goto P_0c09f1ec;
P_0c09f1ec: /* original 6853, guest PC 0x0c09f1ec */
if(!s->budget--) { s->failed_pc=0x0c09f1ecu; return 0; }
r[8]=r[5];
goto P_0c09f1ee;
P_0c09f1ee: /* original 1f31, guest PC 0x0c09f1ee */
if(!s->budget--) { s->failed_pc=0x0c09f1eeu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f1f0;
P_0c09f1f0: /* original 61f2, guest PC 0x0c09f1f0 */
if(!s->budget--) { s->failed_pc=0x0c09f1f0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c09f1f2;
P_0c09f1f2: /* original e902, guest PC 0x0c09f1f2 */
if(!s->budget--) { s->failed_pc=0x0c09f1f2u; return 0; }
r[9]=0x00000002u;
goto P_0c09f1f4;
P_0c09f1f4: /* original 2168, guest PC 0x0c09f1f4 */
if(!s->budget--) { s->failed_pc=0x0c09f1f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[6])==0)!=0);
goto P_0c09f1f6;
P_0c09f1f6: /* original 8f2a, guest PC 0x0c09f1f6 */
if(!s->budget--) { s->failed_pc=0x0c09f1f6u; return 0; }
cond=r[17]&1u;
r[8]|=r[9];
if(!cond) { goto P_0c09f24e; }
goto P_0c09f1fa;
P_0c09f1f8: /* original 289b, guest PC 0x0c09f1f8 */
if(!s->budget--) { s->failed_pc=0x0c09f1f8u; return 0; }
r[8]|=r[9];
goto P_0c09f1fa;
P_0c09f1fa: /* original 53f1, guest PC 0x0c09f1fa */
if(!s->budget--) { s->failed_pc=0x0c09f1fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f1fc;
P_0c09f1fc: /* original 2338, guest PC 0x0c09f1fc */
if(!s->budget--) { s->failed_pc=0x0c09f1fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f1fe;
P_0c09f1fe: /* original 8b26, guest PC 0x0c09f1fe */
if(!s->budget--) { s->failed_pc=0x0c09f1feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f24e; }
goto P_0c09f200;
P_0c09f200: /* original d217, guest PC 0x0c09f200 */
if(!s->budget--) { s->failed_pc=0x0c09f200u; return 0; }
r[2]=read(ram,0x0c09f260u,4);
goto P_0c09f202;
P_0c09f202: /* original 2769, guest PC 0x0c09f202 */
if(!s->budget--) { s->failed_pc=0x0c09f202u; return 0; }
r[7]&=r[6];
goto P_0c09f204;
P_0c09f204: /* original 2b69, guest PC 0x0c09f204 */
if(!s->budget--) { s->failed_pc=0x0c09f204u; return 0; }
r[11]&=r[6];
goto P_0c09f206;
P_0c09f206: /* original 6323, guest PC 0x0c09f206 */
if(!s->budget--) { s->failed_pc=0x0c09f206u; return 0; }
r[3]=r[2];
goto P_0c09f208;
P_0c09f208: /* original 2f22, guest PC 0x0c09f208 */
if(!s->budget--) { s->failed_pc=0x0c09f208u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09f20a;
P_0c09f20a: /* original 9d24, guest PC 0x0c09f20a */
if(!s->budget--) { s->failed_pc=0x0c09f20au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f256u,2);
goto P_0c09f20c;
P_0c09f20c: /* original 2369, guest PC 0x0c09f20c */
if(!s->budget--) { s->failed_pc=0x0c09f20cu; return 0; }
r[3]&=r[6];
goto P_0c09f20e;
P_0c09f20e: /* original da15, guest PC 0x0c09f20e */
if(!s->budget--) { s->failed_pc=0x0c09f20eu; return 0; }
r[10]=read(ram,0x0c09f264u,4);
goto P_0c09f210;
P_0c09f210: /* original 2c69, guest PC 0x0c09f210 */
if(!s->budget--) { s->failed_pc=0x0c09f210u; return 0; }
r[12]&=r[6];
goto P_0c09f212;
P_0c09f212: /* original 2d69, guest PC 0x0c09f212 */
if(!s->budget--) { s->failed_pc=0x0c09f212u; return 0; }
r[13]&=r[6];
goto P_0c09f214;
P_0c09f214: /* original 1f31, guest PC 0x0c09f214 */
if(!s->budget--) { s->failed_pc=0x0c09f214u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f216;
P_0c09f216: /* original 62f2, guest PC 0x0c09f216 */
if(!s->budget--) { s->failed_pc=0x0c09f216u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f218;
P_0c09f218: /* original 26a9, guest PC 0x0c09f218 */
if(!s->budget--) { s->failed_pc=0x0c09f218u; return 0; }
r[6]&=r[10];
goto P_0c09f21a;
P_0c09f21a: /* original 3320, guest PC 0x0c09f21a */
if(!s->budget--) { s->failed_pc=0x0c09f21au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09f21c;
P_0c09f21c: /* original 0029, guest PC 0x0c09f21c */
if(!s->budget--) { s->failed_pc=0x0c09f21cu; return 0; }
r[0]=r[17]&1u;
goto P_0c09f21e;
P_0c09f21e: /* original 36a0, guest PC 0x0c09f21e */
if(!s->budget--) { s->failed_pc=0x0c09f21eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[10])!=0);
goto P_0c09f220;
P_0c09f220: /* original ca01, guest PC 0x0c09f220 */
if(!s->budget--) { s->failed_pc=0x0c09f220u; return 0; }
r[0]^=1u;
goto P_0c09f222;
P_0c09f222: /* original 2f02, guest PC 0x0c09f222 */
if(!s->budget--) { s->failed_pc=0x0c09f222u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09f224;
P_0c09f224: /* original 0029, guest PC 0x0c09f224 */
if(!s->budget--) { s->failed_pc=0x0c09f224u; return 0; }
r[0]=r[17]&1u;
goto P_0c09f226;
P_0c09f226: /* original ca01, guest PC 0x0c09f226 */
if(!s->budget--) { s->failed_pc=0x0c09f226u; return 0; }
r[0]^=1u;
goto P_0c09f228;
P_0c09f228: /* original 1fb2, guest PC 0x0c09f228 */
if(!s->budget--) { s->failed_pc=0x0c09f228u; return 0; }
write(ram,r[15]+8,r[11],4);
goto P_0c09f22a;
P_0c09f22a: /* original 1fc3, guest PC 0x0c09f22a */
if(!s->budget--) { s->failed_pc=0x0c09f22au; return 0; }
write(ram,r[15]+12,r[12],4);
goto P_0c09f22c;
P_0c09f22c: /* original 1f04, guest PC 0x0c09f22c */
if(!s->budget--) { s->failed_pc=0x0c09f22cu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c09f22e;
P_0c09f22e: /* original 1fd1, guest PC 0x0c09f22e */
if(!s->budget--) { s->failed_pc=0x0c09f22eu; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c09f230;
P_0c09f230: /* original 62f2, guest PC 0x0c09f230 */
if(!s->budget--) { s->failed_pc=0x0c09f230u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f232;
P_0c09f232: /* original 2228, guest PC 0x0c09f232 */
if(!s->budget--) { s->failed_pc=0x0c09f232u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f234;
P_0c09f234: /* original 8d08, guest PC 0x0c09f234 */
if(!s->budget--) { s->failed_pc=0x0c09f234u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(cond) { goto P_0c09f248; }
goto P_0c09f238;
P_0c09f236: /* original e601, guest PC 0x0c09f236 */
if(!s->budget--) { s->failed_pc=0x0c09f236u; return 0; }
r[6]=0x00000001u;
goto P_0c09f238;
P_0c09f238: /* original 53f2, guest PC 0x0c09f238 */
if(!s->budget--) { s->failed_pc=0x0c09f238u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f23a;
P_0c09f23a: /* original 2338, guest PC 0x0c09f23a */
if(!s->budget--) { s->failed_pc=0x0c09f23au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f23c;
P_0c09f23c: /* original 8b14, guest PC 0x0c09f23c */
if(!s->budget--) { s->failed_pc=0x0c09f23cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f268; }
goto P_0c09f23e;
P_0c09f23e: /* original 2778, guest PC 0x0c09f23e */
if(!s->budget--) { s->failed_pc=0x0c09f23eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f240;
P_0c09f240: /* original 8b03, guest PC 0x0c09f240 */
if(!s->budget--) { s->failed_pc=0x0c09f240u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f24a; }
goto P_0c09f242;
P_0c09f242: /* original 52f3, guest PC 0x0c09f242 */
if(!s->budget--) { s->failed_pc=0x0c09f242u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c09f244;
P_0c09f244: /* original 2228, guest PC 0x0c09f244 */
if(!s->budget--) { s->failed_pc=0x0c09f244u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f246;
P_0c09f246: /* original 8b15, guest PC 0x0c09f246 */
if(!s->budget--) { s->failed_pc=0x0c09f246u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f274; }
goto P_0c09f248;
P_0c09f248: /* original 6583, guest PC 0x0c09f248 */
if(!s->budget--) { s->failed_pc=0x0c09f248u; return 0; }
r[5]=r[8];
goto P_0c09f24a;
P_0c09f24a: /* original a014, guest PC 0x0c09f24a */
if(!s->budget--) { s->failed_pc=0x0c09f24au; return 0; }
r[5]|=r[6];
goto P_0c09f276;
P_0c09f24c: /* original 256b, guest PC 0x0c09f24c */
if(!s->budget--) { s->failed_pc=0x0c09f24cu; return 0; }
r[5]|=r[6];
goto P_0c09f24e;
P_0c09f24e: /* original a012, guest PC 0x0c09f24e */
if(!s->budget--) { s->failed_pc=0x0c09f24eu; return 0; }
r[5]=r[8];
goto P_0c09f276;
P_0c09f250: /* original 6583, guest PC 0x0c09f250 */
if(!s->budget--) { s->failed_pc=0x0c09f250u; return 0; }
r[5]=r[8];
if(!vf3_matrix_family(0x0c09f252u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f252u; return 0; } return 1;
P_0c09f268: /* original e048, guest PC 0x0c09f268 */
if(!s->budget--) { s->failed_pc=0x0c09f268u; return 0; }
r[0]=0x00000048u;
goto P_0c09f26a;
P_0c09f26a: /* original d335, guest PC 0x0c09f26a */
if(!s->budget--) { s->failed_pc=0x0c09f26au; return 0; }
r[3]=read(ram,0x0c09f340u,4);
goto P_0c09f26c;
P_0c09f26c: /* original 024e, guest PC 0x0c09f26c */
if(!s->budget--) { s->failed_pc=0x0c09f26cu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c09f26e;
P_0c09f26e: /* original 2238, guest PC 0x0c09f26e */
if(!s->budget--) { s->failed_pc=0x0c09f26eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09f270;
P_0c09f270: /* original 8b00, guest PC 0x0c09f270 */
if(!s->budget--) { s->failed_pc=0x0c09f270u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f274; }
goto P_0c09f272;
P_0c09f272: /* original 256b, guest PC 0x0c09f272 */
if(!s->budget--) { s->failed_pc=0x0c09f272u; return 0; }
r[5]|=r[6];
goto P_0c09f274;
P_0c09f274: /* original 259b, guest PC 0x0c09f274 */
if(!s->budget--) { s->failed_pc=0x0c09f274u; return 0; }
r[5]|=r[9];
goto P_0c09f276;
P_0c09f276: /* original 905e, guest PC 0x0c09f276 */
if(!s->budget--) { s->failed_pc=0x0c09f276u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f336u,2);
goto P_0c09f278;
P_0c09f278: /* original e30f, guest PC 0x0c09f278 */
if(!s->budget--) { s->failed_pc=0x0c09f278u; return 0; }
r[3]=0x0000000fu;
goto P_0c09f27a;
P_0c09f27a: /* original e208, guest PC 0x0c09f27a */
if(!s->budget--) { s->failed_pc=0x0c09f27au; return 0; }
r[2]=0x00000008u;
goto P_0c09f27c;
P_0c09f27c: /* original 0d4d, guest PC 0x0c09f27c */
if(!s->budget--) { s->failed_pc=0x0c09f27cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f27e;
P_0c09f27e: /* original e03e, guest PC 0x0c09f27e */
if(!s->budget--) { s->failed_pc=0x0c09f27eu; return 0; }
r[0]=0x0000003eu;
goto P_0c09f280;
P_0c09f280: /* original 064d, guest PC 0x0c09f280 */
if(!s->budget--) { s->failed_pc=0x0c09f280u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f282;
P_0c09f282: /* original 6ddd, guest PC 0x0c09f282 */
if(!s->budget--) { s->failed_pc=0x0c09f282u; return 0; }
r[13]=r[13]&65535u;
goto P_0c09f284;
P_0c09f284: /* original 67d3, guest PC 0x0c09f284 */
if(!s->budget--) { s->failed_pc=0x0c09f284u; return 0; }
r[7]=r[13];
goto P_0c09f286;
P_0c09f286: /* original 666d, guest PC 0x0c09f286 */
if(!s->budget--) { s->failed_pc=0x0c09f286u; return 0; }
r[6]=r[6]&65535u;
goto P_0c09f288;
P_0c09f288: /* original 3768, guest PC 0x0c09f288 */
if(!s->budget--) { s->failed_pc=0x0c09f288u; return 0; }
r[7]-=r[6];
goto P_0c09f28a;
P_0c09f28a: /* original 3732, guest PC 0x0c09f28a */
if(!s->budget--) { s->failed_pc=0x0c09f28au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[3])!=0);
goto P_0c09f28c;
P_0c09f28c: /* original 0029, guest PC 0x0c09f28c */
if(!s->budget--) { s->failed_pc=0x0c09f28cu; return 0; }
r[0]=r[17]&1u;
goto P_0c09f28e;
P_0c09f28e: /* original 3726, guest PC 0x0c09f28e */
if(!s->budget--) { s->failed_pc=0x0c09f28eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[2])!=0);
goto P_0c09f290;
P_0c09f290: /* original 1f02, guest PC 0x0c09f290 */
if(!s->budget--) { s->failed_pc=0x0c09f290u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c09f292;
P_0c09f292: /* original 0029, guest PC 0x0c09f292 */
if(!s->budget--) { s->failed_pc=0x0c09f292u; return 0; }
r[0]=r[17]&1u;
goto P_0c09f294;
P_0c09f294: /* original 1f03, guest PC 0x0c09f294 */
if(!s->budget--) { s->failed_pc=0x0c09f294u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c09f296;
P_0c09f296: /* original 6763, guest PC 0x0c09f296 */
if(!s->budget--) { s->failed_pc=0x0c09f296u; return 0; }
r[7]=r[6];
goto P_0c09f298;
P_0c09f298: /* original 53f1, guest PC 0x0c09f298 */
if(!s->budget--) { s->failed_pc=0x0c09f298u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f29a;
P_0c09f29a: /* original 2338, guest PC 0x0c09f29a */
if(!s->budget--) { s->failed_pc=0x0c09f29au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f29c;
P_0c09f29c: /* original 8f02, guest PC 0x0c09f29c */
if(!s->budget--) { s->failed_pc=0x0c09f29cu; return 0; }
cond=r[17]&1u;
r[7]+=0x0000000eu;
if(!cond) { goto P_0c09f2a4; }
goto P_0c09f2a0;
P_0c09f29e: /* original 770e, guest PC 0x0c09f29e */
if(!s->budget--) { s->failed_pc=0x0c09f29eu; return 0; }
r[7]+=0x0000000eu;
goto P_0c09f2a0;
P_0c09f2a0: /* original 6763, guest PC 0x0c09f2a0 */
if(!s->budget--) { s->failed_pc=0x0c09f2a0u; return 0; }
r[7]=r[6];
goto P_0c09f2a2;
P_0c09f2a2: /* original 7707, guest PC 0x0c09f2a2 */
if(!s->budget--) { s->failed_pc=0x0c09f2a2u; return 0; }
r[7]+=0x00000007u;
goto P_0c09f2a4;
P_0c09f2a4: /* original 6cd3, guest PC 0x0c09f2a4 */
if(!s->budget--) { s->failed_pc=0x0c09f2a4u; return 0; }
r[12]=r[13];
goto P_0c09f2a6;
P_0c09f2a6: /* original 7cf9, guest PC 0x0c09f2a6 */
if(!s->budget--) { s->failed_pc=0x0c09f2a6u; return 0; }
r[12]+=0xfffffff9u;
goto P_0c09f2a8;
P_0c09f2a8: /* original 2fc2, guest PC 0x0c09f2a8 */
if(!s->budget--) { s->failed_pc=0x0c09f2a8u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c09f2aa;
P_0c09f2aa: /* original 53f4, guest PC 0x0c09f2aa */
if(!s->budget--) { s->failed_pc=0x0c09f2aau; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c09f2ac;
P_0c09f2ac: /* original 2338, guest PC 0x0c09f2ac */
if(!s->budget--) { s->failed_pc=0x0c09f2acu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f2ae;
P_0c09f2ae: /* original 8b02, guest PC 0x0c09f2ae */
if(!s->budget--) { s->failed_pc=0x0c09f2aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f2b6; }
goto P_0c09f2b0;
P_0c09f2b0: /* original 6cf2, guest PC 0x0c09f2b0 */
if(!s->budget--) { s->failed_pc=0x0c09f2b0u; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c09f2b2;
P_0c09f2b2: /* original 6763, guest PC 0x0c09f2b2 */
if(!s->budget--) { s->failed_pc=0x0c09f2b2u; return 0; }
r[7]=r[6];
goto P_0c09f2b4;
P_0c09f2b4: /* original 7701, guest PC 0x0c09f2b4 */
if(!s->budget--) { s->failed_pc=0x0c09f2b4u; return 0; }
r[7]+=0x00000001u;
goto P_0c09f2b6;
P_0c09f2b6: /* original 53f2, guest PC 0x0c09f2b6 */
if(!s->budget--) { s->failed_pc=0x0c09f2b6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f2b8;
P_0c09f2b8: /* original 2338, guest PC 0x0c09f2b8 */
if(!s->budget--) { s->failed_pc=0x0c09f2b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f2ba;
P_0c09f2ba: /* original 8b07, guest PC 0x0c09f2ba */
if(!s->budget--) { s->failed_pc=0x0c09f2bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f2cc; }
goto P_0c09f2bc;
P_0c09f2bc: /* original 52f3, guest PC 0x0c09f2bc */
if(!s->budget--) { s->failed_pc=0x0c09f2bcu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c09f2be;
P_0c09f2be: /* original 6c73, guest PC 0x0c09f2be */
if(!s->budget--) { s->failed_pc=0x0c09f2beu; return 0; }
r[12]=r[7];
goto P_0c09f2c0;
P_0c09f2c0: /* original 2228, guest PC 0x0c09f2c0 */
if(!s->budget--) { s->failed_pc=0x0c09f2c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f2c2;
P_0c09f2c2: /* original 8f03, guest PC 0x0c09f2c2 */
if(!s->budget--) { s->failed_pc=0x0c09f2c2u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c09f2cc; }
goto P_0c09f2c6;
P_0c09f2c4: /* original 7c01, guest PC 0x0c09f2c4 */
if(!s->budget--) { s->failed_pc=0x0c09f2c4u; return 0; }
r[12]+=0x00000001u;
goto P_0c09f2c6;
P_0c09f2c6: /* original 6cd3, guest PC 0x0c09f2c6 */
if(!s->budget--) { s->failed_pc=0x0c09f2c6u; return 0; }
r[12]=r[13];
goto P_0c09f2c8;
P_0c09f2c8: /* original 7c01, guest PC 0x0c09f2c8 */
if(!s->budget--) { s->failed_pc=0x0c09f2c8u; return 0; }
r[12]+=0x00000001u;
goto P_0c09f2ca;
P_0c09f2ca: /* original 67d3, guest PC 0x0c09f2ca */
if(!s->budget--) { s->failed_pc=0x0c09f2cau; return 0; }
r[7]=r[13];
goto P_0c09f2cc;
P_0c09f2cc: /* original 9034, guest PC 0x0c09f2cc */
if(!s->budget--) { s->failed_pc=0x0c09f2ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f338u,2);
goto P_0c09f2ce;
P_0c09f2ce: /* original e200, guest PC 0x0c09f2ce */
if(!s->budget--) { s->failed_pc=0x0c09f2ceu; return 0; }
r[2]=0x00000000u;
goto P_0c09f2d0;
P_0c09f2d0: /* original 76ff, guest PC 0x0c09f2d0 */
if(!s->budget--) { s->failed_pc=0x0c09f2d0u; return 0; }
r[6]+=0xffffffffu;
goto P_0c09f2d2;
P_0c09f2d2: /* original 0424, guest PC 0x0c09f2d2 */
if(!s->budget--) { s->failed_pc=0x0c09f2d2u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09f2d4;
P_0c09f2d4: /* original 70f0, guest PC 0x0c09f2d4 */
if(!s->budget--) { s->failed_pc=0x0c09f2d4u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c09f2d6;
P_0c09f2d6: /* original 0475, guest PC 0x0c09f2d6 */
if(!s->budget--) { s->failed_pc=0x0c09f2d6u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c09f2d8;
P_0c09f2d8: /* original 7002, guest PC 0x0c09f2d8 */
if(!s->budget--) { s->failed_pc=0x0c09f2d8u; return 0; }
r[0]+=0x00000002u;
goto P_0c09f2da;
P_0c09f2da: /* original 04c5, guest PC 0x0c09f2da */
if(!s->budget--) { s->failed_pc=0x0c09f2dau; return 0; }
write(ram,r[4]+r[0],r[12],2);
goto P_0c09f2dc;
P_0c09f2dc: /* original 7002, guest PC 0x0c09f2dc */
if(!s->budget--) { s->failed_pc=0x0c09f2dcu; return 0; }
r[0]+=0x00000002u;
goto P_0c09f2de;
P_0c09f2de: /* original 0465, guest PC 0x0c09f2de */
if(!s->budget--) { s->failed_pc=0x0c09f2deu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c09f2e0;
P_0c09f2e0: /* original e04c, guest PC 0x0c09f2e0 */
if(!s->budget--) { s->failed_pc=0x0c09f2e0u; return 0; }
r[0]=0x0000004cu;
goto P_0c09f2e2;
P_0c09f2e2: /* original d318, guest PC 0x0c09f2e2 */
if(!s->budget--) { s->failed_pc=0x0c09f2e2u; return 0; }
r[3]=read(ram,0x0c09f344u,4);
goto P_0c09f2e4;
P_0c09f2e4: /* original 29e9, guest PC 0x0c09f2e4 */
if(!s->budget--) { s->failed_pc=0x0c09f2e4u; return 0; }
r[9]&=r[14];
goto P_0c09f2e6;
P_0c09f2e6: /* original 064e, guest PC 0x0c09f2e6 */
if(!s->budget--) { s->failed_pc=0x0c09f2e6u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c09f2e8;
P_0c09f2e8: /* original 2369, guest PC 0x0c09f2e8 */
if(!s->budget--) { s->failed_pc=0x0c09f2e8u; return 0; }
r[3]&=r[6];
goto P_0c09f2ea;
P_0c09f2ea: /* original 1f31, guest PC 0x0c09f2ea */
if(!s->budget--) { s->failed_pc=0x0c09f2eau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f2ec;
P_0c09f2ec: /* original d716, guest PC 0x0c09f2ec */
if(!s->budget--) { s->failed_pc=0x0c09f2ecu; return 0; }
r[7]=read(ram,0x0c09f348u,4);
goto P_0c09f2ee;
P_0c09f2ee: /* original 2f92, guest PC 0x0c09f2ee */
if(!s->budget--) { s->failed_pc=0x0c09f2eeu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c09f2f0;
P_0c09f2f0: /* original d216, guest PC 0x0c09f2f0 */
if(!s->budget--) { s->failed_pc=0x0c09f2f0u; return 0; }
r[2]=read(ram,0x0c09f34cu,4);
goto P_0c09f2f2;
P_0c09f2f2: /* original 2769, guest PC 0x0c09f2f2 */
if(!s->budget--) { s->failed_pc=0x0c09f2f2u; return 0; }
r[7]&=r[6];
goto P_0c09f2f4;
P_0c09f2f4: /* original 1f31, guest PC 0x0c09f2f4 */
if(!s->budget--) { s->failed_pc=0x0c09f2f4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f2f6;
P_0c09f2f6: /* original 2629, guest PC 0x0c09f2f6 */
if(!s->budget--) { s->failed_pc=0x0c09f2f6u; return 0; }
r[6]&=r[2];
goto P_0c09f2f8;
P_0c09f2f8: /* original 1f64, guest PC 0x0c09f2f8 */
if(!s->budget--) { s->failed_pc=0x0c09f2f8u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c09f2fa;
P_0c09f2fa: /* original 53f1, guest PC 0x0c09f2fa */
if(!s->budget--) { s->failed_pc=0x0c09f2fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f2fc;
P_0c09f2fc: /* original 961d, guest PC 0x0c09f2fc */
if(!s->budget--) { s->failed_pc=0x0c09f2fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33au,2);
goto P_0c09f2fe;
P_0c09f2fe: /* original 2338, guest PC 0x0c09f2fe */
if(!s->budget--) { s->failed_pc=0x0c09f2feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f300;
P_0c09f300: /* original 8900, guest PC 0x0c09f300 */
if(!s->budget--) { s->failed_pc=0x0c09f300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f304; }
goto P_0c09f302;
P_0c09f302: /* original 2569, guest PC 0x0c09f302 */
if(!s->budget--) { s->failed_pc=0x0c09f302u; return 0; }
r[5]&=r[6];
goto P_0c09f304;
P_0c09f304: /* original 2778, guest PC 0x0c09f304 */
if(!s->budget--) { s->failed_pc=0x0c09f304u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f306;
P_0c09f306: /* original 8901, guest PC 0x0c09f306 */
if(!s->budget--) { s->failed_pc=0x0c09f306u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f30c; }
goto P_0c09f308;
P_0c09f308: /* original 9218, guest PC 0x0c09f308 */
if(!s->budget--) { s->failed_pc=0x0c09f308u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33cu,2);
goto P_0c09f30a;
P_0c09f30a: /* original 2529, guest PC 0x0c09f30a */
if(!s->budget--) { s->failed_pc=0x0c09f30au; return 0; }
r[5]&=r[2];
goto P_0c09f30c;
P_0c09f30c: /* original 63f2, guest PC 0x0c09f30c */
if(!s->budget--) { s->failed_pc=0x0c09f30cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09f30e;
P_0c09f30e: /* original 2338, guest PC 0x0c09f30e */
if(!s->budget--) { s->failed_pc=0x0c09f30eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f310;
P_0c09f310: /* original 8b00, guest PC 0x0c09f310 */
if(!s->budget--) { s->failed_pc=0x0c09f310u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f314; }
goto P_0c09f312;
P_0c09f312: /* original 2569, guest PC 0x0c09f312 */
if(!s->budget--) { s->failed_pc=0x0c09f312u; return 0; }
r[5]&=r[6];
goto P_0c09f314;
P_0c09f314: /* original 52f4, guest PC 0x0c09f314 */
if(!s->budget--) { s->failed_pc=0x0c09f314u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c09f316;
P_0c09f316: /* original 2228, guest PC 0x0c09f316 */
if(!s->budget--) { s->failed_pc=0x0c09f316u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f318;
P_0c09f318: /* original 8901, guest PC 0x0c09f318 */
if(!s->budget--) { s->failed_pc=0x0c09f318u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f31e; }
goto P_0c09f31a;
P_0c09f31a: /* original e204, guest PC 0x0c09f31a */
if(!s->budget--) { s->failed_pc=0x0c09f31au; return 0; }
r[2]=0x00000004u;
goto P_0c09f31c;
P_0c09f31c: /* original 252b, guest PC 0x0c09f31c */
if(!s->budget--) { s->failed_pc=0x0c09f31cu; return 0; }
r[5]|=r[2];
goto P_0c09f31e;
P_0c09f31e: /* original 7f14, guest PC 0x0c09f31e */
if(!s->budget--) { s->failed_pc=0x0c09f31eu; return 0; }
r[15]+=0x00000014u;
goto P_0c09f320;
P_0c09f320: /* original 900d, guest PC 0x0c09f320 */
if(!s->budget--) { s->failed_pc=0x0c09f320u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33eu,2);
goto P_0c09f322;
P_0c09f322: /* original 0454, guest PC 0x0c09f322 */
if(!s->budget--) { s->failed_pc=0x0c09f322u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c09f324;
P_0c09f324: /* original 68f6, guest PC 0x0c09f324 */
if(!s->budget--) { s->failed_pc=0x0c09f324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09f326;
P_0c09f326: /* original d30a, guest PC 0x0c09f326 */
if(!s->budget--) { s->failed_pc=0x0c09f326u; return 0; }
r[3]=read(ram,0x0c09f350u,4);
goto P_0c09f328;
P_0c09f328: /* original 69f6, guest PC 0x0c09f328 */
if(!s->budget--) { s->failed_pc=0x0c09f328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09f32a;
P_0c09f32a: /* original 6af6, guest PC 0x0c09f32a */
if(!s->budget--) { s->failed_pc=0x0c09f32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09f32c;
P_0c09f32c: /* original 6bf6, guest PC 0x0c09f32c */
if(!s->budget--) { s->failed_pc=0x0c09f32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09f32e;
P_0c09f32e: /* original 6cf6, guest PC 0x0c09f32e */
if(!s->budget--) { s->failed_pc=0x0c09f32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f330;
P_0c09f330: /* original 6df6, guest PC 0x0c09f330 */
if(!s->budget--) { s->failed_pc=0x0c09f330u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f332;
P_0c09f332: /* original 432b, guest PC 0x0c09f332 */
if(!s->budget--) { s->failed_pc=0x0c09f332u; return 0; }
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
P_0c09f334: /* original 6ef6, guest PC 0x0c09f334 */
if(!s->budget--) { s->failed_pc=0x0c09f334u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f336u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f336u; return 0; } return 1;
P_0c0ab340: /* original 2fe6, guest PC 0x0c0ab340 */
if(!s->budget--) { s->failed_pc=0x0c0ab340u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab342;
P_0c0ab342: /* original 6e43, guest PC 0x0c0ab342 */
if(!s->budget--) { s->failed_pc=0x0c0ab342u; return 0; }
r[14]=r[4];
goto P_0c0ab344;
P_0c0ab344: /* original 2fd6, guest PC 0x0c0ab344 */
if(!s->budget--) { s->failed_pc=0x0c0ab344u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab346;
P_0c0ab346: /* original 6d63, guest PC 0x0c0ab346 */
if(!s->budget--) { s->failed_pc=0x0c0ab346u; return 0; }
r[13]=r[6];
goto P_0c0ab348;
P_0c0ab348: /* original 2fc6, guest PC 0x0c0ab348 */
if(!s->budget--) { s->failed_pc=0x0c0ab348u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab34a;
P_0c0ab34a: /* original e048, guest PC 0x0c0ab34a */
if(!s->budget--) { s->failed_pc=0x0c0ab34au; return 0; }
r[0]=0x00000048u;
goto P_0c0ab34c;
P_0c0ab34c: /* original 2fb6, guest PC 0x0c0ab34c */
if(!s->budget--) { s->failed_pc=0x0c0ab34cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab34e;
P_0c0ab34e: /* original 6b53, guest PC 0x0c0ab34e */
if(!s->budget--) { s->failed_pc=0x0c0ab34eu; return 0; }
r[11]=r[5];
goto P_0c0ab350;
P_0c0ab350: /* original 2fa6, guest PC 0x0c0ab350 */
if(!s->budget--) { s->failed_pc=0x0c0ab350u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab352;
P_0c0ab352: /* original fffb, guest PC 0x0c0ab352 */
if(!s->budget--) { s->failed_pc=0x0c0ab352u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ab354;
P_0c0ab354: /* original ffeb, guest PC 0x0c0ab354 */
if(!s->budget--) { s->failed_pc=0x0c0ab354u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0ab356;
P_0c0ab356: /* original ffdb, guest PC 0x0c0ab356 */
if(!s->budget--) { s->failed_pc=0x0c0ab356u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0ab358;
P_0c0ab358: /* original ffcb, guest PC 0x0c0ab358 */
if(!s->budget--) { s->failed_pc=0x0c0ab358u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0ab35a;
P_0c0ab35a: /* original 4f22, guest PC 0x0c0ab35a */
if(!s->budget--) { s->failed_pc=0x0c0ab35au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ab35c;
P_0c0ab35c: /* original d34a, guest PC 0x0c0ab35c */
if(!s->budget--) { s->failed_pc=0x0c0ab35cu; return 0; }
r[3]=read(ram,0x0c0ab488u,4);
goto P_0c0ab35e;
P_0c0ab35e: /* original 7fd8, guest PC 0x0c0ab35e */
if(!s->budget--) { s->failed_pc=0x0c0ab35eu; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0ab360;
P_0c0ab360: /* original 1f39, guest PC 0x0c0ab360 */
if(!s->budget--) { s->failed_pc=0x0c0ab360u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c0ab362;
P_0c0ab362: /* original d24a, guest PC 0x0c0ab362 */
if(!s->budget--) { s->failed_pc=0x0c0ab362u; return 0; }
r[2]=read(ram,0x0c0ab48cu,4);
goto P_0c0ab364;
P_0c0ab364: /* original 1f27, guest PC 0x0c0ab364 */
if(!s->budget--) { s->failed_pc=0x0c0ab364u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c0ab366;
P_0c0ab366: /* original 63e2, guest PC 0x0c0ab366 */
if(!s->budget--) { s->failed_pc=0x0c0ab366u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0ab368;
P_0c0ab368: /* original 0cee, guest PC 0x0c0ab368 */
if(!s->budget--) { s->failed_pc=0x0c0ab368u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0ab36a;
P_0c0ab36a: /* original 1f36, guest PC 0x0c0ab36a */
if(!s->budget--) { s->failed_pc=0x0c0ab36au; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0ab36c;
P_0c0ab36c: /* original 53d1, guest PC 0x0c0ab36c */
if(!s->budget--) { s->failed_pc=0x0c0ab36cu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ab36e;
P_0c0ab36e: /* original 2338, guest PC 0x0c0ab36e */
if(!s->budget--) { s->failed_pc=0x0c0ab36eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0ab370;
P_0c0ab370: /* original 8d05, guest PC 0x0c0ab370 */
if(!s->budget--) { s->failed_pc=0x0c0ab370u; return 0; }
cond=r[17]&1u;
fr[13]=0x3f800000u;
if(cond) { goto P_0c0ab37e; }
goto P_0c0ab374;
P_0c0ab372: /* original fd9d, guest PC 0x0c0ab372 */
if(!s->budget--) { s->failed_pc=0x0c0ab372u; return 0; }
fr[13]=0x3f800000u;
goto P_0c0ab374;
P_0c0ab374: /* original 50d1, guest PC 0x0c0ab374 */
if(!s->budget--) { s->failed_pc=0x0c0ab374u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0ab376;
P_0c0ab376: /* original 8801, guest PC 0x0c0ab376 */
if(!s->budget--) { s->failed_pc=0x0c0ab376u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ab378;
P_0c0ab378: /* original 8b01, guest PC 0x0c0ab378 */
if(!s->budget--) { s->failed_pc=0x0c0ab378u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab37e; }
goto P_0c0ab37a;
P_0c0ab37a: /* original a1cf, guest PC 0x0c0ab37a */
if(!s->budget--) { s->failed_pc=0x0c0ab37au; return 0; }
goto P_0c0ab71c;
P_0c0ab37c: /* original 0009, guest PC 0x0c0ab37c */
if(!s->budget--) { s->failed_pc=0x0c0ab37cu; return 0; }
goto P_0c0ab37e;
P_0c0ab37e: /* original e03e, guest PC 0x0c0ab37e */
if(!s->budget--) { s->failed_pc=0x0c0ab37eu; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab380;
P_0c0ab380: /* original 03ed, guest PC 0x0c0ab380 */
if(!s->budget--) { s->failed_pc=0x0c0ab380u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab382;
P_0c0ab382: /* original 633d, guest PC 0x0c0ab382 */
if(!s->budget--) { s->failed_pc=0x0c0ab382u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab384;
P_0c0ab384: /* original 1f32, guest PC 0x0c0ab384 */
if(!s->budget--) { s->failed_pc=0x0c0ab384u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab386;
P_0c0ab386: /* original 9076, guest PC 0x0c0ab386 */
if(!s->budget--) { s->failed_pc=0x0c0ab386u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab476u,2);
goto P_0c0ab388;
P_0c0ab388: /* original 02ed, guest PC 0x0c0ab388 */
if(!s->budget--) { s->failed_pc=0x0c0ab388u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab38a;
P_0c0ab38a: /* original 622d, guest PC 0x0c0ab38a */
if(!s->budget--) { s->failed_pc=0x0c0ab38au; return 0; }
r[2]=r[2]&65535u;
goto P_0c0ab38c;
P_0c0ab38c: /* original 1f24, guest PC 0x0c0ab38c */
if(!s->budget--) { s->failed_pc=0x0c0ab38cu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0ab38e;
P_0c0ab38e: /* original 53f2, guest PC 0x0c0ab38e */
if(!s->budget--) { s->failed_pc=0x0c0ab38eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0ab390;
P_0c0ab390: /* original 3322, guest PC 0x0c0ab390 */
if(!s->budget--) { s->failed_pc=0x0c0ab390u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ab392;
P_0c0ab392: /* original 8901, guest PC 0x0c0ab392 */
if(!s->budget--) { s->failed_pc=0x0c0ab392u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab398; }
goto P_0c0ab394;
P_0c0ab394: /* original a248, guest PC 0x0c0ab394 */
if(!s->budget--) { s->failed_pc=0x0c0ab394u; return 0; }
goto P_0c0ab828;
P_0c0ab396: /* original 0009, guest PC 0x0c0ab396 */
if(!s->budget--) { s->failed_pc=0x0c0ab396u; return 0; }
goto P_0c0ab398;
P_0c0ab398: /* original d23d, guest PC 0x0c0ab398 */
if(!s->budget--) { s->failed_pc=0x0c0ab398u; return 0; }
r[2]=read(ram,0x0c0ab490u,4);
goto P_0c0ab39a;
P_0c0ab39a: /* original e048, guest PC 0x0c0ab39a */
if(!s->budget--) { s->failed_pc=0x0c0ab39au; return 0; }
r[0]=0x00000048u;
goto P_0c0ab39c;
P_0c0ab39c: /* original 2c29, guest PC 0x0c0ab39c */
if(!s->budget--) { s->failed_pc=0x0c0ab39cu; return 0; }
r[12]&=r[2];
goto P_0c0ab39e;
P_0c0ab39e: /* original 0ec6, guest PC 0x0c0ab39e */
if(!s->budget--) { s->failed_pc=0x0c0ab39eu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0ab3a0;
P_0c0ab3a0: /* original 63d2, guest PC 0x0c0ab3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a0u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ab3a2;
P_0c0ab3a2: /* original 633d, guest PC 0x0c0ab3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a2u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab3a4;
P_0c0ab3a4: /* original 2338, guest PC 0x0c0ab3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0ab3a6;
P_0c0ab3a6: /* original 8d09, guest PC 0x0c0ab3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a6u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+16,r[3],4);
if(cond) { goto P_0c0ab3bc; }
goto P_0c0ab3aa;
P_0c0ab3a8: /* original 1f34, guest PC 0x0c0ab3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a8u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ab3aa;
P_0c0ab3aa: /* original e03c, guest PC 0x0c0ab3aa */
if(!s->budget--) { s->failed_pc=0x0c0ab3aau; return 0; }
r[0]=0x0000003cu;
goto P_0c0ab3ac;
P_0c0ab3ac: /* original 01ed, guest PC 0x0c0ab3ac */
if(!s->budget--) { s->failed_pc=0x0c0ab3acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab3ae;
P_0c0ab3ae: /* original 611d, guest PC 0x0c0ab3ae */
if(!s->budget--) { s->failed_pc=0x0c0ab3aeu; return 0; }
r[1]=r[1]&65535u;
goto P_0c0ab3b0;
P_0c0ab3b0: /* original 3310, guest PC 0x0c0ab3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0ab3b2;
P_0c0ab3b2: /* original 8903, guest PC 0x0c0ab3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab3bc; }
goto P_0c0ab3b4;
P_0c0ab3b4: /* original d337, guest PC 0x0c0ab3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b4u; return 0; }
r[3]=read(ram,0x0c0ab494u,4);
goto P_0c0ab3b6;
P_0c0ab3b6: /* original 55f4, guest PC 0x0c0ab3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b6u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c0ab3b8;
P_0c0ab3b8: /* original 430b, guest PC 0x0c0ab3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab3bcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab3bcu) { target=s->pc; goto dispatch; }
goto P_0c0ab3bc;
P_0c0ab3ba: /* original 64e3, guest PC 0x0c0ab3ba */
if(!s->budget--) { s->failed_pc=0x0c0ab3bau; return 0; }
r[4]=r[14];
goto P_0c0ab3bc;
P_0c0ab3bc: /* original 905c, guest PC 0x0c0ab3bc */
if(!s->budget--) { s->failed_pc=0x0c0ab3bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab478u,2);
goto P_0c0ab3be;
P_0c0ab3be: /* original 02ec, guest PC 0x0c0ab3be */
if(!s->budget--) { s->failed_pc=0x0c0ab3beu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab3c0;
P_0c0ab3c0: /* original e064, guest PC 0x0c0ab3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c0u; return 0; }
r[0]=0x00000064u;
goto P_0c0ab3c2;
P_0c0ab3c2: /* original 622c, guest PC 0x0c0ab3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c2u; return 0; }
r[2]=r[2]&255u;
goto P_0c0ab3c4;
P_0c0ab3c4: /* original 6323, guest PC 0x0c0ab3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c4u; return 0; }
r[3]=r[2];
goto P_0c0ab3c6;
P_0c0ab3c6: /* original 1f22, guest PC 0x0c0ab3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0ab3c8;
P_0c0ab3c8: /* original 0e35, guest PC 0x0c0ab3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0ab3ca;
P_0c0ab3ca: /* original 52f2, guest PC 0x0c0ab3ca */
if(!s->budget--) { s->failed_pc=0x0c0ab3cau; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0ab3cc;
P_0c0ab3cc: /* original f28d, guest PC 0x0c0ab3cc */
if(!s->budget--) { s->failed_pc=0x0c0ab3ccu; return 0; }
fr[2]=0;
goto P_0c0ab3ce;
P_0c0ab3ce: /* original 425a, guest PC 0x0c0ab3ce */
if(!s->budget--) { s->failed_pc=0x0c0ab3ceu; return 0; }
r[53]=r[2];
goto P_0c0ab3d0;
P_0c0ab3d0: /* original f32d, guest PC 0x0c0ab3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0ab3d2;
P_0c0ab3d2: /* original f235, guest PC 0x0c0ab3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab3d4;
P_0c0ab3d4: /* original 8f03, guest PC 0x0c0ab3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d4u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c0ab3de; }
goto P_0c0ab3d8;
P_0c0ab3d6: /* original f43c, guest PC 0x0c0ab3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d6u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0ab3d8;
P_0c0ab3d8: /* original c72f, guest PC 0x0c0ab3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d8u; return 0; }
r[0]=code_base|0x000ab498u;
goto P_0c0ab3da;
P_0c0ab3da: /* original f308, guest PC 0x0c0ab3da */
if(!s->budget--) { s->failed_pc=0x0c0ab3dau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab3dc;
P_0c0ab3dc: /* original f430, guest PC 0x0c0ab3dc */
if(!s->budget--) { s->failed_pc=0x0c0ab3dcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0ab3de;
P_0c0ab3de: /* original 53f9, guest PC 0x0c0ab3de */
if(!s->budget--) { s->failed_pc=0x0c0ab3deu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0ab3e0;
P_0c0ab3e0: /* original 904b, guest PC 0x0c0ab3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab47au,2);
goto P_0c0ab3e2;
P_0c0ab3e2: /* original f138, guest PC 0x0c0ab3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e2u; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
goto P_0c0ab3e4;
P_0c0ab3e4: /* original f2e6, guest PC 0x0c0ab3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e4u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab3e6;
P_0c0ab3e6: /* original c72d, guest PC 0x0c0ab3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e6u; return 0; }
r[0]=code_base|0x000ab49cu;
goto P_0c0ab3e8;
P_0c0ab3e8: /* original f34c, guest PC 0x0c0ab3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e8u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ab3ea;
P_0c0ab3ea: /* original f3d0, guest PC 0x0c0ab3ea */
if(!s->budget--) { s->failed_pc=0x0c0ab3eau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'+');
goto P_0c0ab3ec;
P_0c0ab3ec: /* original f121, guest PC 0x0c0ab3ec */
if(!s->budget--) { s->failed_pc=0x0c0ab3ecu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
goto P_0c0ab3ee;
P_0c0ab3ee: /* original f208, guest PC 0x0c0ab3ee */
if(!s->budget--) { s->failed_pc=0x0c0ab3eeu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab3f0;
P_0c0ab3f0: /* original 9044, guest PC 0x0c0ab3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab47cu,2);
goto P_0c0ab3f2;
P_0c0ab3f2: /* original f312, guest PC 0x0c0ab3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'*');
goto P_0c0ab3f4;
P_0c0ab3f4: /* original f53c, guest PC 0x0c0ab3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f4u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0ab3f6;
P_0c0ab3f6: /* original f522, guest PC 0x0c0ab3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c0ab3f8;
P_0c0ab3f8: /* original f3e6, guest PC 0x0c0ab3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab3fa;
P_0c0ab3fa: /* original 9040, guest PC 0x0c0ab3fa */
if(!s->budget--) { s->failed_pc=0x0c0ab3fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab47eu,2);
goto P_0c0ab3fc;
P_0c0ab3fc: /* original f1e6, guest PC 0x0c0ab3fc */
if(!s->budget--) { s->failed_pc=0x0c0ab3fcu; return 0; }
vf3_matrix_load(s,ram,1,r[14]+r[0]);
goto P_0c0ab3fe;
P_0c0ab3fe: /* original 903f, guest PC 0x0c0ab3fe */
if(!s->budget--) { s->failed_pc=0x0c0ab3feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab480u,2);
goto P_0c0ab400;
P_0c0ab400: /* original f130, guest PC 0x0c0ab400 */
if(!s->budget--) { s->failed_pc=0x0c0ab400u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0ab402;
P_0c0ab402: /* original f3e6, guest PC 0x0c0ab402 */
if(!s->budget--) { s->failed_pc=0x0c0ab402u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab404;
P_0c0ab404: /* original e028, guest PC 0x0c0ab404 */
if(!s->budget--) { s->failed_pc=0x0c0ab404u; return 0; }
r[0]=0x00000028u;
goto P_0c0ab406;
P_0c0ab406: /* original f131, guest PC 0x0c0ab406 */
if(!s->budget--) { s->failed_pc=0x0c0ab406u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c0ab408;
P_0c0ab408: /* original f143, guest PC 0x0c0ab408 */
if(!s->budget--) { s->failed_pc=0x0c0ab408u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'/');
goto P_0c0ab40a;
P_0c0ab40a: /* original f510, guest PC 0x0c0ab40a */
if(!s->budget--) { s->failed_pc=0x0c0ab40au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'+');
goto P_0c0ab40c;
P_0c0ab40c: /* original fe57, guest PC 0x0c0ab40c */
if(!s->budget--) { s->failed_pc=0x0c0ab40cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ab40e;
P_0c0ab40e: /* original d326, guest PC 0x0c0ab40e */
if(!s->budget--) { s->failed_pc=0x0c0ab40eu; return 0; }
r[3]=read(ram,0x0c0ab4a8u,4);
goto P_0c0ab410;
P_0c0ab410: /* original 62d2, guest PC 0x0c0ab410 */
if(!s->budget--) { s->failed_pc=0x0c0ab410u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab412;
P_0c0ab412: /* original dc24, guest PC 0x0c0ab412 */
if(!s->budget--) { s->failed_pc=0x0c0ab412u; return 0; }
r[12]=read(ram,0x0c0ab4a4u,4);
goto P_0c0ab414;
P_0c0ab414: /* original da22, guest PC 0x0c0ab414 */
if(!s->budget--) { s->failed_pc=0x0c0ab414u; return 0; }
r[10]=read(ram,0x0c0ab4a0u,4);
goto P_0c0ab416;
P_0c0ab416: /* original 2238, guest PC 0x0c0ab416 */
if(!s->budget--) { s->failed_pc=0x0c0ab416u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab418;
P_0c0ab418: /* original 8b51, guest PC 0x0c0ab418 */
if(!s->budget--) { s->failed_pc=0x0c0ab418u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab4be; }
goto P_0c0ab41a;
P_0c0ab41a: /* original 9032, guest PC 0x0c0ab41a */
if(!s->budget--) { s->failed_pc=0x0c0ab41au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab482u,2);
goto P_0c0ab41c;
P_0c0ab41c: /* original f28d, guest PC 0x0c0ab41c */
if(!s->budget--) { s->failed_pc=0x0c0ab41cu; return 0; }
fr[2]=0;
goto P_0c0ab41e;
P_0c0ab41e: /* original ffe6, guest PC 0x0c0ab41e */
if(!s->budget--) { s->failed_pc=0x0c0ab41eu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ab420;
P_0c0ab420: /* original c722, guest PC 0x0c0ab420 */
if(!s->budget--) { s->failed_pc=0x0c0ab420u; return 0; }
r[0]=code_base|0x000ab4acu;
goto P_0c0ab422;
P_0c0ab422: /* original f308, guest PC 0x0c0ab422 */
if(!s->budget--) { s->failed_pc=0x0c0ab422u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab424;
P_0c0ab424: /* original ff24, guest PC 0x0c0ab424 */
if(!s->budget--) { s->failed_pc=0x0c0ab424u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[2]))!=0);
goto P_0c0ab426;
P_0c0ab426: /* original f54c, guest PC 0x0c0ab426 */
if(!s->budget--) { s->failed_pc=0x0c0ab426u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0ab428;
P_0c0ab428: /* original 8d0d, guest PC 0x0c0ab428 */
if(!s->budget--) { s->failed_pc=0x0c0ab428u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
if(cond) { goto P_0c0ab446; }
goto P_0c0ab42c;
P_0c0ab42a: /* original f532, guest PC 0x0c0ab42a */
if(!s->budget--) { s->failed_pc=0x0c0ab42au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0ab42c;
P_0c0ab42c: /* original f38d, guest PC 0x0c0ab42c */
if(!s->budget--) { s->failed_pc=0x0c0ab42cu; return 0; }
fr[3]=0;
goto P_0c0ab42e;
P_0c0ab42e: /* original f3f5, guest PC 0x0c0ab42e */
if(!s->budget--) { s->failed_pc=0x0c0ab42eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0ab430;
P_0c0ab430: /* original 9028, guest PC 0x0c0ab430 */
if(!s->budget--) { s->failed_pc=0x0c0ab430u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab484u,2);
goto P_0c0ab432;
P_0c0ab432: /* original 8d02, guest PC 0x0c0ab432 */
if(!s->budget--) { s->failed_pc=0x0c0ab432u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[14]+r[0]);
if(cond) { goto P_0c0ab43a; }
goto P_0c0ab436;
P_0c0ab434: /* original f6e6, guest PC 0x0c0ab434 */
if(!s->budget--) { s->failed_pc=0x0c0ab434u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab436;
P_0c0ab436: /* original 9026, guest PC 0x0c0ab436 */
if(!s->budget--) { s->failed_pc=0x0c0ab436u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab486u,2);
goto P_0c0ab438;
P_0c0ab438: /* original f6e6, guest PC 0x0c0ab438 */
if(!s->budget--) { s->failed_pc=0x0c0ab438u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab43a;
P_0c0ab43a: /* original c71d, guest PC 0x0c0ab43a */
if(!s->budget--) { s->failed_pc=0x0c0ab43au; return 0; }
r[0]=code_base|0x000ab4b0u;
goto P_0c0ab43c;
P_0c0ab43c: /* original f308, guest PC 0x0c0ab43c */
if(!s->budget--) { s->failed_pc=0x0c0ab43cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab43e;
P_0c0ab43e: /* original f630, guest PC 0x0c0ab43e */
if(!s->budget--) { s->failed_pc=0x0c0ab43eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0ab440;
P_0c0ab440: /* original f565, guest PC 0x0c0ab440 */
if(!s->budget--) { s->failed_pc=0x0c0ab440u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c0ab442;
P_0c0ab442: /* original 8b00, guest PC 0x0c0ab442 */
if(!s->budget--) { s->failed_pc=0x0c0ab442u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab446; }
goto P_0c0ab444;
P_0c0ab444: /* original f56c, guest PC 0x0c0ab444 */
if(!s->budget--) { s->failed_pc=0x0c0ab444u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0ab446;
P_0c0ab446: /* original f543, guest PC 0x0c0ab446 */
if(!s->budget--) { s->failed_pc=0x0c0ab446u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c0ab448;
P_0c0ab448: /* original 85ef, guest PC 0x0c0ab448 */
if(!s->budget--) { s->failed_pc=0x0c0ab448u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0ab44a;
P_0c0ab44a: /* original 640f, guest PC 0x0c0ab44a */
if(!s->budget--) { s->failed_pc=0x0c0ab44au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0ab44c;
P_0c0ab44c: /* original 1f06, guest PC 0x0c0ab44c */
if(!s->budget--) { s->failed_pc=0x0c0ab44cu; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c0ab44e;
P_0c0ab44e: /* original ff52, guest PC 0x0c0ab44e */
if(!s->budget--) { s->failed_pc=0x0c0ab44eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[5],r[18],'*');
goto P_0c0ab450;
P_0c0ab450: /* original 4a0b, guest PC 0x0c0ab450 */
if(!s->budget--) { s->failed_pc=0x0c0ab450u; return 0; }
target=r[10];
r[16]=code_base|0x0c0ab454u;
write(ram,r[15]+28,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab454u) { target=s->pc; goto dispatch; }
goto P_0c0ab454;
P_0c0ab452: /* original 1f47, guest PC 0x0c0ab452 */
if(!s->budget--) { s->failed_pc=0x0c0ab452u; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c0ab454;
P_0c0ab454: /* original e020, guest PC 0x0c0ab454 */
if(!s->budget--) { s->failed_pc=0x0c0ab454u; return 0; }
r[0]=0x00000020u;
goto P_0c0ab456;
P_0c0ab456: /* original ff0a, guest PC 0x0c0ab456 */
if(!s->budget--) { s->failed_pc=0x0c0ab456u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab458;
P_0c0ab458: /* original f2fc, guest PC 0x0c0ab458 */
if(!s->budget--) { s->failed_pc=0x0c0ab458u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0ab45a;
P_0c0ab45a: /* original f30c, guest PC 0x0c0ab45a */
if(!s->budget--) { s->failed_pc=0x0c0ab45au; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0ab45c;
P_0c0ab45c: /* original f232, guest PC 0x0c0ab45c */
if(!s->budget--) { s->failed_pc=0x0c0ab45cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0ab45e;
P_0c0ab45e: /* original f24d, guest PC 0x0c0ab45e */
if(!s->budget--) { s->failed_pc=0x0c0ab45eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c0ab460;
P_0c0ab460: /* original ff27, guest PC 0x0c0ab460 */
if(!s->budget--) { s->failed_pc=0x0c0ab460u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab462;
P_0c0ab462: /* original 4c0b, guest PC 0x0c0ab462 */
if(!s->budget--) { s->failed_pc=0x0c0ab462u; return 0; }
target=r[12];
r[16]=code_base|0x0c0ab466u;
r[4]=read(ram,r[15]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab466u) { target=s->pc; goto dispatch; }
goto P_0c0ab466;
P_0c0ab464: /* original 54f7, guest PC 0x0c0ab464 */
if(!s->budget--) { s->failed_pc=0x0c0ab464u; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c0ab466;
P_0c0ab466: /* original ff02, guest PC 0x0c0ab466 */
if(!s->budget--) { s->failed_pc=0x0c0ab466u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[0],r[18],'*');
goto P_0c0ab468;
P_0c0ab468: /* original e020, guest PC 0x0c0ab468 */
if(!s->budget--) { s->failed_pc=0x0c0ab468u; return 0; }
r[0]=0x00000020u;
goto P_0c0ab46a;
P_0c0ab46a: /* original ff0a, guest PC 0x0c0ab46a */
if(!s->budget--) { s->failed_pc=0x0c0ab46au; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab46c;
P_0c0ab46c: /* original f3f6, guest PC 0x0c0ab46c */
if(!s->budget--) { s->failed_pc=0x0c0ab46cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab46e;
P_0c0ab46e: /* original f4fc, guest PC 0x0c0ab46e */
if(!s->budget--) { s->failed_pc=0x0c0ab46eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ab470;
P_0c0ab470: /* original f44d, guest PC 0x0c0ab470 */
if(!s->budget--) { s->failed_pc=0x0c0ab470u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0ab472;
P_0c0ab472: /* original a01f, guest PC 0x0c0ab472 */
if(!s->budget--) { s->failed_pc=0x0c0ab472u; return 0; }
goto P_0c0ab4b4;
P_0c0ab474: /* original 0009, guest PC 0x0c0ab474 */
if(!s->budget--) { s->failed_pc=0x0c0ab474u; return 0; }
if(!vf3_matrix_family(0x0c0ab476u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab476u; return 0; } return 1;
P_0c0ab4b4: /* original e024, guest PC 0x0c0ab4b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4b4u; return 0; }
r[0]=0x00000024u;
goto P_0c0ab4b6;
P_0c0ab4b6: /* original fe37, guest PC 0x0c0ab4b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4b6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab4b8;
P_0c0ab4b8: /* original e02c, guest PC 0x0c0ab4b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4b8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab4ba;
P_0c0ab4ba: /* original a0fd, guest PC 0x0c0ab4ba */
if(!s->budget--) { s->failed_pc=0x0c0ab4bau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab6b8;
P_0c0ab4bc: /* original fe47, guest PC 0x0c0ab4bc */
if(!s->budget--) { s->failed_pc=0x0c0ab4bcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab4be;
P_0c0ab4be: /* original 9080, guest PC 0x0c0ab4be */
if(!s->budget--) { s->failed_pc=0x0c0ab4beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c2u,2);
goto P_0c0ab4c0;
P_0c0ab4c0: /* original 62b2, guest PC 0x0c0ab4c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c0u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0ab4c2;
P_0c0ab4c2: /* original d342, guest PC 0x0c0ab4c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c2u; return 0; }
r[3]=read(ram,0x0c0ab5ccu,4);
goto P_0c0ab4c4;
P_0c0ab4c4: /* original fee6, guest PC 0x0c0ab4c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c4u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0ab4c6;
P_0c0ab4c6: /* original 7008, guest PC 0x0c0ab4c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c6u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab4c8;
P_0c0ab4c8: /* original 2238, guest PC 0x0c0ab4c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab4ca;
P_0c0ab4ca: /* original 8f07, guest PC 0x0c0ab4ca */
if(!s->budget--) { s->failed_pc=0x0c0ab4cau; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[14]+r[0]);
if(!cond) { goto P_0c0ab4dc; }
goto P_0c0ab4ce;
P_0c0ab4cc: /* original ffe6, guest PC 0x0c0ab4cc */
if(!s->budget--) { s->failed_pc=0x0c0ab4ccu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ab4ce;
P_0c0ab4ce: /* original 9079, guest PC 0x0c0ab4ce */
if(!s->budget--) { s->failed_pc=0x0c0ab4ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c4u,2);
goto P_0c0ab4d0;
P_0c0ab4d0: /* original 00bc, guest PC 0x0c0ab4d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0ab4d2;
P_0c0ab4d2: /* original 600c, guest PC 0x0c0ab4d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab4d4;
P_0c0ab4d4: /* original c840, guest PC 0x0c0ab4d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0ab4d6;
P_0c0ab4d6: /* original 8b01, guest PC 0x0c0ab4d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab4dc; }
goto P_0c0ab4d8;
P_0c0ab4d8: /* original a084, guest PC 0x0c0ab4d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d8u; return 0; }
goto P_0c0ab5e4;
P_0c0ab4da: /* original 0009, guest PC 0x0c0ab4da */
if(!s->budget--) { s->failed_pc=0x0c0ab4dau; return 0; }
goto P_0c0ab4dc;
P_0c0ab4dc: /* original 50f7, guest PC 0x0c0ab4dc */
if(!s->budget--) { s->failed_pc=0x0c0ab4dcu; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0ab4de;
P_0c0ab4de: /* original e11c, guest PC 0x0c0ab4de */
if(!s->budget--) { s->failed_pc=0x0c0ab4deu; return 0; }
r[1]=0x0000001cu;
goto P_0c0ab4e0;
P_0c0ab4e0: /* original 001c, guest PC 0x0c0ab4e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0ab4e2;
P_0c0ab4e2: /* original 600c, guest PC 0x0c0ab4e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab4e4;
P_0c0ab4e4: /* original c90f, guest PC 0x0c0ab4e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e4u; return 0; }
r[0]&=15u;
goto P_0c0ab4e6;
P_0c0ab4e6: /* original 880f, guest PC 0x0c0ab4e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0ab4e8;
P_0c0ab4e8: /* original 8b31, guest PC 0x0c0ab4e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab54e; }
goto P_0c0ab4ea;
P_0c0ab4ea: /* original e06a, guest PC 0x0c0ab4ea */
if(!s->budget--) { s->failed_pc=0x0c0ab4eau; return 0; }
r[0]=0x0000006au;
goto P_0c0ab4ec;
P_0c0ab4ec: /* original 03ed, guest PC 0x0c0ab4ec */
if(!s->budget--) { s->failed_pc=0x0c0ab4ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab4ee;
P_0c0ab4ee: /* original 1f32, guest PC 0x0c0ab4ee */
if(!s->budget--) { s->failed_pc=0x0c0ab4eeu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab4f0;
P_0c0ab4f0: /* original 4a0b, guest PC 0x0c0ab4f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f0u; return 0; }
target=r[10];
r[16]=code_base|0x0c0ab4f4u;
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab4f4u) { target=s->pc; goto dispatch; }
goto P_0c0ab4f4;
P_0c0ab4f2: /* original 643f, guest PC 0x0c0ab4f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c0ab4f4;
P_0c0ab4f4: /* original ff0a, guest PC 0x0c0ab4f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f4u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab4f6;
P_0c0ab4f6: /* original 54f2, guest PC 0x0c0ab4f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab4f8;
P_0c0ab4f8: /* original 4c0b, guest PC 0x0c0ab4f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0ab4fcu;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab4fcu) { target=s->pc; goto dispatch; }
goto P_0c0ab4fc;
P_0c0ab4fa: /* original 644f, guest PC 0x0c0ab4fa */
if(!s->budget--) { s->failed_pc=0x0c0ab4fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ab4fc;
P_0c0ab4fc: /* original e004, guest PC 0x0c0ab4fc */
if(!s->budget--) { s->failed_pc=0x0c0ab4fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0ab4fe;
P_0c0ab4fe: /* original ff07, guest PC 0x0c0ab4fe */
if(!s->budget--) { s->failed_pc=0x0c0ab4feu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ab500;
P_0c0ab500: /* original e050, guest PC 0x0c0ab500 */
if(!s->budget--) { s->failed_pc=0x0c0ab500u; return 0; }
r[0]=0x00000050u;
goto P_0c0ab502;
P_0c0ab502: /* original 02ee, guest PC 0x0c0ab502 */
if(!s->budget--) { s->failed_pc=0x0c0ab502u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab504;
P_0c0ab504: /* original d332, guest PC 0x0c0ab504 */
if(!s->budget--) { s->failed_pc=0x0c0ab504u; return 0; }
r[3]=read(ram,0x0c0ab5d0u,4);
goto P_0c0ab506;
P_0c0ab506: /* original 2238, guest PC 0x0c0ab506 */
if(!s->budget--) { s->failed_pc=0x0c0ab506u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab508;
P_0c0ab508: /* original 8902, guest PC 0x0c0ab508 */
if(!s->budget--) { s->failed_pc=0x0c0ab508u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab510; }
goto P_0c0ab50a;
P_0c0ab50a: /* original 905c, guest PC 0x0c0ab50a */
if(!s->budget--) { s->failed_pc=0x0c0ab50au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c6u,2);
goto P_0c0ab50c;
P_0c0ab50c: /* original a001, guest PC 0x0c0ab50c */
if(!s->budget--) { s->failed_pc=0x0c0ab50cu; return 0; }
goto P_0c0ab512;
P_0c0ab50e: /* original 0009, guest PC 0x0c0ab50e */
if(!s->budget--) { s->failed_pc=0x0c0ab50eu; return 0; }
goto P_0c0ab510;
P_0c0ab510: /* original 905a, guest PC 0x0c0ab510 */
if(!s->budget--) { s->failed_pc=0x0c0ab510u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c8u,2);
goto P_0c0ab512;
P_0c0ab512: /* original f3e6, guest PC 0x0c0ab512 */
if(!s->budget--) { s->failed_pc=0x0c0ab512u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab514;
P_0c0ab514: /* original e00c, guest PC 0x0c0ab514 */
if(!s->budget--) { s->failed_pc=0x0c0ab514u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab516;
P_0c0ab516: /* original ff37, guest PC 0x0c0ab516 */
if(!s->budget--) { s->failed_pc=0x0c0ab516u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab518;
P_0c0ab518: /* original c72e, guest PC 0x0c0ab518 */
if(!s->budget--) { s->failed_pc=0x0c0ab518u; return 0; }
r[0]=code_base|0x000ab5d4u;
goto P_0c0ab51a;
P_0c0ab51a: /* original f308, guest PC 0x0c0ab51a */
if(!s->budget--) { s->failed_pc=0x0c0ab51au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab51c;
P_0c0ab51c: /* original e00c, guest PC 0x0c0ab51c */
if(!s->budget--) { s->failed_pc=0x0c0ab51cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab51e;
P_0c0ab51e: /* original f2f6, guest PC 0x0c0ab51e */
if(!s->budget--) { s->failed_pc=0x0c0ab51eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab520;
P_0c0ab520: /* original e00c, guest PC 0x0c0ab520 */
if(!s->budget--) { s->failed_pc=0x0c0ab520u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab522;
P_0c0ab522: /* original f231, guest PC 0x0c0ab522 */
if(!s->budget--) { s->failed_pc=0x0c0ab522u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0ab524;
P_0c0ab524: /* original ff27, guest PC 0x0c0ab524 */
if(!s->budget--) { s->failed_pc=0x0c0ab524u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab526;
P_0c0ab526: /* original e00c, guest PC 0x0c0ab526 */
if(!s->budget--) { s->failed_pc=0x0c0ab526u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab528;
P_0c0ab528: /* original f1f8, guest PC 0x0c0ab528 */
if(!s->budget--) { s->failed_pc=0x0c0ab528u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c0ab52a;
P_0c0ab52a: /* original f122, guest PC 0x0c0ab52a */
if(!s->budget--) { s->failed_pc=0x0c0ab52au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0ab52c;
P_0c0ab52c: /* original ff1a, guest PC 0x0c0ab52c */
if(!s->budget--) { s->failed_pc=0x0c0ab52cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c0ab52e;
P_0c0ab52e: /* original f2f6, guest PC 0x0c0ab52e */
if(!s->budget--) { s->failed_pc=0x0c0ab52eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab530;
P_0c0ab530: /* original e004, guest PC 0x0c0ab530 */
if(!s->budget--) { s->failed_pc=0x0c0ab530u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab532;
P_0c0ab532: /* original f1f6, guest PC 0x0c0ab532 */
if(!s->budget--) { s->failed_pc=0x0c0ab532u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ab534;
P_0c0ab534: /* original e004, guest PC 0x0c0ab534 */
if(!s->budget--) { s->failed_pc=0x0c0ab534u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab536;
P_0c0ab536: /* original f122, guest PC 0x0c0ab536 */
if(!s->budget--) { s->failed_pc=0x0c0ab536u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0ab538;
P_0c0ab538: /* original ff17, guest PC 0x0c0ab538 */
if(!s->budget--) { s->failed_pc=0x0c0ab538u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0ab53a;
P_0c0ab53a: /* original e014, guest PC 0x0c0ab53a */
if(!s->budget--) { s->failed_pc=0x0c0ab53au; return 0; }
r[0]=0x00000014u;
goto P_0c0ab53c;
P_0c0ab53c: /* original f3f8, guest PC 0x0c0ab53c */
if(!s->budget--) { s->failed_pc=0x0c0ab53cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab53e;
P_0c0ab53e: /* original f0ec, guest PC 0x0c0ab53e */
if(!s->budget--) { s->failed_pc=0x0c0ab53eu; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0ab540;
P_0c0ab540: /* original f031, guest PC 0x0c0ab540 */
if(!s->budget--) { s->failed_pc=0x0c0ab540u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0ab542;
P_0c0ab542: /* original ff07, guest PC 0x0c0ab542 */
if(!s->budget--) { s->failed_pc=0x0c0ab542u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ab544;
P_0c0ab544: /* original e004, guest PC 0x0c0ab544 */
if(!s->budget--) { s->failed_pc=0x0c0ab544u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab546;
P_0c0ab546: /* original f2f6, guest PC 0x0c0ab546 */
if(!s->budget--) { s->failed_pc=0x0c0ab546u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab548;
P_0c0ab548: /* original fcfc, guest PC 0x0c0ab548 */
if(!s->budget--) { s->failed_pc=0x0c0ab548u; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c0ab54a;
P_0c0ab54a: /* original a07c, guest PC 0x0c0ab54a */
if(!s->budget--) { s->failed_pc=0x0c0ab54au; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[2],r[18],'-');
goto P_0c0ab646;
P_0c0ab54c: /* original fc21, guest PC 0x0c0ab54c */
if(!s->budget--) { s->failed_pc=0x0c0ab54cu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[2],r[18],'-');
goto P_0c0ab54e;
P_0c0ab54e: /* original 9038, guest PC 0x0c0ab54e */
if(!s->budget--) { s->failed_pc=0x0c0ab54eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c2u,2);
goto P_0c0ab550;
P_0c0ab550: /* original 63f3, guest PC 0x0c0ab550 */
if(!s->budget--) { s->failed_pc=0x0c0ab550u; return 0; }
r[3]=r[15];
goto P_0c0ab552;
P_0c0ab552: /* original 7310, guest PC 0x0c0ab552 */
if(!s->budget--) { s->failed_pc=0x0c0ab552u; return 0; }
r[3]+=0x00000010u;
goto P_0c0ab554;
P_0c0ab554: /* original f4ec, guest PC 0x0c0ab554 */
if(!s->budget--) { s->failed_pc=0x0c0ab554u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0ab556;
P_0c0ab556: /* original f6b6, guest PC 0x0c0ab556 */
if(!s->budget--) { s->failed_pc=0x0c0ab556u; return 0; }
vf3_matrix_load(s,ram,6,r[11]+r[0]);
goto P_0c0ab558;
P_0c0ab558: /* original 7008, guest PC 0x0c0ab558 */
if(!s->budget--) { s->failed_pc=0x0c0ab558u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab55a;
P_0c0ab55a: /* original f7b6, guest PC 0x0c0ab55a */
if(!s->budget--) { s->failed_pc=0x0c0ab55au; return 0; }
vf3_matrix_load(s,ram,7,r[11]+r[0]);
goto P_0c0ab55c;
P_0c0ab55c: /* original f5fc, guest PC 0x0c0ab55c */
if(!s->budget--) { s->failed_pc=0x0c0ab55cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0ab55e;
P_0c0ab55e: /* original 2f36, guest PC 0x0c0ab55e */
if(!s->budget--) { s->failed_pc=0x0c0ab55eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab560;
P_0c0ab560: /* original 67f3, guest PC 0x0c0ab560 */
if(!s->budget--) { s->failed_pc=0x0c0ab560u; return 0; }
r[7]=r[15];
goto P_0c0ab562;
P_0c0ab562: /* original 66f3, guest PC 0x0c0ab562 */
if(!s->budget--) { s->failed_pc=0x0c0ab562u; return 0; }
r[6]=r[15];
goto P_0c0ab564;
P_0c0ab564: /* original 65f3, guest PC 0x0c0ab564 */
if(!s->budget--) { s->failed_pc=0x0c0ab564u; return 0; }
r[5]=r[15];
goto P_0c0ab566;
P_0c0ab566: /* original d21c, guest PC 0x0c0ab566 */
if(!s->budget--) { s->failed_pc=0x0c0ab566u; return 0; }
r[2]=read(ram,0x0c0ab5d8u,4);
goto P_0c0ab568;
P_0c0ab568: /* original 64f3, guest PC 0x0c0ab568 */
if(!s->budget--) { s->failed_pc=0x0c0ab568u; return 0; }
r[4]=r[15];
goto P_0c0ab56a;
P_0c0ab56a: /* original 7508, guest PC 0x0c0ab56a */
if(!s->budget--) { s->failed_pc=0x0c0ab56au; return 0; }
r[5]+=0x00000008u;
goto P_0c0ab56c;
P_0c0ab56c: /* original 7610, guest PC 0x0c0ab56c */
if(!s->budget--) { s->failed_pc=0x0c0ab56cu; return 0; }
r[6]+=0x00000010u;
goto P_0c0ab56e;
P_0c0ab56e: /* original 770c, guest PC 0x0c0ab56e */
if(!s->budget--) { s->failed_pc=0x0c0ab56eu; return 0; }
r[7]+=0x0000000cu;
goto P_0c0ab570;
P_0c0ab570: /* original 420b, guest PC 0x0c0ab570 */
if(!s->budget--) { s->failed_pc=0x0c0ab570u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ab574u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab574u) { target=s->pc; goto dispatch; }
goto P_0c0ab574;
P_0c0ab572: /* original 7404, guest PC 0x0c0ab572 */
if(!s->budget--) { s->failed_pc=0x0c0ab572u; return 0; }
r[4]+=0x00000004u;
goto P_0c0ab574;
P_0c0ab574: /* original 9025, guest PC 0x0c0ab574 */
if(!s->budget--) { s->failed_pc=0x0c0ab574u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c2u,2);
goto P_0c0ab576;
P_0c0ab576: /* original 7f04, guest PC 0x0c0ab576 */
if(!s->budget--) { s->failed_pc=0x0c0ab576u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ab578;
P_0c0ab578: /* original f5f8, guest PC 0x0c0ab578 */
if(!s->budget--) { s->failed_pc=0x0c0ab578u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c0ab57a;
P_0c0ab57a: /* original fee6, guest PC 0x0c0ab57a */
if(!s->budget--) { s->failed_pc=0x0c0ab57au; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0ab57c;
P_0c0ab57c: /* original 7008, guest PC 0x0c0ab57c */
if(!s->budget--) { s->failed_pc=0x0c0ab57cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab57e;
P_0c0ab57e: /* original ffe6, guest PC 0x0c0ab57e */
if(!s->budget--) { s->failed_pc=0x0c0ab57eu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ab580;
P_0c0ab580: /* original e00c, guest PC 0x0c0ab580 */
if(!s->budget--) { s->failed_pc=0x0c0ab580u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab582;
P_0c0ab582: /* original f5e1, guest PC 0x0c0ab582 */
if(!s->budget--) { s->failed_pc=0x0c0ab582u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c0ab584;
P_0c0ab584: /* original f4f6, guest PC 0x0c0ab584 */
if(!s->budget--) { s->failed_pc=0x0c0ab584u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ab586;
P_0c0ab586: /* original e004, guest PC 0x0c0ab586 */
if(!s->budget--) { s->failed_pc=0x0c0ab586u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab588;
P_0c0ab588: /* original f4f1, guest PC 0x0c0ab588 */
if(!s->budget--) { s->failed_pc=0x0c0ab588u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0ab58a;
P_0c0ab58a: /* original f35c, guest PC 0x0c0ab58a */
if(!s->budget--) { s->failed_pc=0x0c0ab58au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ab58c;
P_0c0ab58c: /* original f352, guest PC 0x0c0ab58c */
if(!s->budget--) { s->failed_pc=0x0c0ab58cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab58e;
P_0c0ab58e: /* original f04c, guest PC 0x0c0ab58e */
if(!s->budget--) { s->failed_pc=0x0c0ab58eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ab590;
P_0c0ab590: /* original f34e, guest PC 0x0c0ab590 */
if(!s->budget--) { s->failed_pc=0x0c0ab590u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0ab592;
P_0c0ab592: /* original ff37, guest PC 0x0c0ab592 */
if(!s->budget--) { s->failed_pc=0x0c0ab592u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab594;
P_0c0ab594: /* original c711, guest PC 0x0c0ab594 */
if(!s->budget--) { s->failed_pc=0x0c0ab594u; return 0; }
r[0]=code_base|0x000ab5dcu;
goto P_0c0ab596;
P_0c0ab596: /* original f208, guest PC 0x0c0ab596 */
if(!s->budget--) { s->failed_pc=0x0c0ab596u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab598;
P_0c0ab598: /* original f235, guest PC 0x0c0ab598 */
if(!s->budget--) { s->failed_pc=0x0c0ab598u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab59a;
P_0c0ab59a: /* original 8b01, guest PC 0x0c0ab59a */
if(!s->budget--) { s->failed_pc=0x0c0ab59au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab5a0; }
goto P_0c0ab59c;
P_0c0ab59c: /* original a001, guest PC 0x0c0ab59c */
if(!s->budget--) { s->failed_pc=0x0c0ab59cu; return 0; }
fr[3]=0;
goto P_0c0ab5a2;
P_0c0ab59e: /* original f38d, guest PC 0x0c0ab59e */
if(!s->budget--) { s->failed_pc=0x0c0ab59eu; return 0; }
fr[3]=0;
goto P_0c0ab5a0;
P_0c0ab5a0: /* original f37d, guest PC 0x0c0ab5a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0ab5a2;
P_0c0ab5a2: /* original e004, guest PC 0x0c0ab5a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a2u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab5a4;
P_0c0ab5a4: /* original f532, guest PC 0x0c0ab5a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0ab5a6;
P_0c0ab5a6: /* original ff37, guest PC 0x0c0ab5a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab5a8;
P_0c0ab5a8: /* original c70d, guest PC 0x0c0ab5a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a8u; return 0; }
r[0]=code_base|0x000ab5e0u;
goto P_0c0ab5aa;
P_0c0ab5aa: /* original f608, guest PC 0x0c0ab5aa */
if(!s->budget--) { s->failed_pc=0x0c0ab5aau; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0ab5ac;
P_0c0ab5ac: /* original f432, guest PC 0x0c0ab5ac */
if(!s->budget--) { s->failed_pc=0x0c0ab5acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0ab5ae;
P_0c0ab5ae: /* original f3f8, guest PC 0x0c0ab5ae */
if(!s->budget--) { s->failed_pc=0x0c0ab5aeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab5b0;
P_0c0ab5b0: /* original e014, guest PC 0x0c0ab5b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b0u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab5b2;
P_0c0ab5b2: /* original f562, guest PC 0x0c0ab5b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0ab5b4;
P_0c0ab5b4: /* original f462, guest PC 0x0c0ab5b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0ab5b6;
P_0c0ab5b6: /* original f351, guest PC 0x0c0ab5b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c0ab5b8;
P_0c0ab5b8: /* original ff37, guest PC 0x0c0ab5b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab5ba;
P_0c0ab5ba: /* original e00c, guest PC 0x0c0ab5ba */
if(!s->budget--) { s->failed_pc=0x0c0ab5bau; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab5bc;
P_0c0ab5bc: /* original fcf6, guest PC 0x0c0ab5bc */
if(!s->budget--) { s->failed_pc=0x0c0ab5bcu; return 0; }
vf3_matrix_load(s,ram,12,r[15]+r[0]);
goto P_0c0ab5be;
P_0c0ab5be: /* original a042, guest PC 0x0c0ab5be */
if(!s->budget--) { s->failed_pc=0x0c0ab5beu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'-');
goto P_0c0ab646;
P_0c0ab5c0: /* original fc41, guest PC 0x0c0ab5c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5c0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'-');
if(!vf3_matrix_family(0x0c0ab5c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab5c2u; return 0; } return 1;
P_0c0ab5e4: /* original 9086, guest PC 0x0c0ab5e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f4u,2);
goto P_0c0ab5e6;
P_0c0ab5e6: /* original f3e6, guest PC 0x0c0ab5e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5e6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab5e8;
P_0c0ab5e8: /* original e014, guest PC 0x0c0ab5e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5e8u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab5ea;
P_0c0ab5ea: /* original ff37, guest PC 0x0c0ab5ea */
if(!s->budget--) { s->failed_pc=0x0c0ab5eau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab5ec;
P_0c0ab5ec: /* original 9083, guest PC 0x0c0ab5ec */
if(!s->budget--) { s->failed_pc=0x0c0ab5ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f6u,2);
goto P_0c0ab5ee;
P_0c0ab5ee: /* original f38d, guest PC 0x0c0ab5ee */
if(!s->budget--) { s->failed_pc=0x0c0ab5eeu; return 0; }
fr[3]=0;
goto P_0c0ab5f0;
P_0c0ab5f0: /* original fce6, guest PC 0x0c0ab5f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f0u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0ab5f2;
P_0c0ab5f2: /* original 70f0, guest PC 0x0c0ab5f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f2u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c0ab5f4;
P_0c0ab5f4: /* original f2e6, guest PC 0x0c0ab5f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f4u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab5f6;
P_0c0ab5f6: /* original f234, guest PC 0x0c0ab5f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])==as_float(fr[3]))!=0);
goto P_0c0ab5f8;
P_0c0ab5f8: /* original 892b, guest PC 0x0c0ab5f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab652; }
goto P_0c0ab5fa;
P_0c0ab5fa: /* original f5cc, guest PC 0x0c0ab5fa */
if(!s->budget--) { s->failed_pc=0x0c0ab5fau; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c0ab5fc;
P_0c0ab5fc: /* original f5f1, guest PC 0x0c0ab5fc */
if(!s->budget--) { s->failed_pc=0x0c0ab5fcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c0ab5fe;
P_0c0ab5fe: /* original e014, guest PC 0x0c0ab5fe */
if(!s->budget--) { s->failed_pc=0x0c0ab5feu; return 0; }
r[0]=0x00000014u;
goto P_0c0ab600;
P_0c0ab600: /* original d33f, guest PC 0x0c0ab600 */
if(!s->budget--) { s->failed_pc=0x0c0ab600u; return 0; }
r[3]=read(ram,0x0c0ab700u,4);
goto P_0c0ab602;
P_0c0ab602: /* original f4f6, guest PC 0x0c0ab602 */
if(!s->budget--) { s->failed_pc=0x0c0ab602u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ab604;
P_0c0ab604: /* original 430b, guest PC 0x0c0ab604 */
if(!s->budget--) { s->failed_pc=0x0c0ab604u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab608u;
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab608u) { target=s->pc; goto dispatch; }
goto P_0c0ab608;
P_0c0ab606: /* original f4e1, guest PC 0x0c0ab606 */
if(!s->budget--) { s->failed_pc=0x0c0ab606u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c0ab608;
P_0c0ab608: /* original 9376, guest PC 0x0c0ab608 */
if(!s->budget--) { s->failed_pc=0x0c0ab608u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f8u,2);
goto P_0c0ab60a;
P_0c0ab60a: /* original 600f, guest PC 0x0c0ab60a */
if(!s->budget--) { s->failed_pc=0x0c0ab60au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0ab60c;
P_0c0ab60c: /* original 6203, guest PC 0x0c0ab60c */
if(!s->budget--) { s->failed_pc=0x0c0ab60cu; return 0; }
r[2]=r[0];
goto P_0c0ab60e;
P_0c0ab60e: /* original 323c, guest PC 0x0c0ab60e */
if(!s->budget--) { s->failed_pc=0x0c0ab60eu; return 0; }
r[2]+=r[3];
goto P_0c0ab610;
P_0c0ab610: /* original 1f22, guest PC 0x0c0ab610 */
if(!s->budget--) { s->failed_pc=0x0c0ab610u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0ab612;
P_0c0ab612: /* original 4a0b, guest PC 0x0c0ab612 */
if(!s->budget--) { s->failed_pc=0x0c0ab612u; return 0; }
target=r[10];
r[16]=code_base|0x0c0ab616u;
r[4]=(uint32_t)(int32_t)(int16_t)r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab616u) { target=s->pc; goto dispatch; }
goto P_0c0ab616;
P_0c0ab614: /* original 642f, guest PC 0x0c0ab614 */
if(!s->budget--) { s->failed_pc=0x0c0ab614u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c0ab616;
P_0c0ab616: /* original ff0a, guest PC 0x0c0ab616 */
if(!s->budget--) { s->failed_pc=0x0c0ab616u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab618;
P_0c0ab618: /* original 54f2, guest PC 0x0c0ab618 */
if(!s->budget--) { s->failed_pc=0x0c0ab618u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab61a;
P_0c0ab61a: /* original 4c0b, guest PC 0x0c0ab61a */
if(!s->budget--) { s->failed_pc=0x0c0ab61au; return 0; }
target=r[12];
r[16]=code_base|0x0c0ab61eu;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab61eu) { target=s->pc; goto dispatch; }
goto P_0c0ab61e;
P_0c0ab61c: /* original 644f, guest PC 0x0c0ab61c */
if(!s->budget--) { s->failed_pc=0x0c0ab61cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ab61e;
P_0c0ab61e: /* original e004, guest PC 0x0c0ab61e */
if(!s->budget--) { s->failed_pc=0x0c0ab61eu; return 0; }
r[0]=0x00000004u;
goto P_0c0ab620;
P_0c0ab620: /* original ff07, guest PC 0x0c0ab620 */
if(!s->budget--) { s->failed_pc=0x0c0ab620u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ab622;
P_0c0ab622: /* original 906a, guest PC 0x0c0ab622 */
if(!s->budget--) { s->failed_pc=0x0c0ab622u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6fau,2);
goto P_0c0ab624;
P_0c0ab624: /* original f3e6, guest PC 0x0c0ab624 */
if(!s->budget--) { s->failed_pc=0x0c0ab624u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab626;
P_0c0ab626: /* original e00c, guest PC 0x0c0ab626 */
if(!s->budget--) { s->failed_pc=0x0c0ab626u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab628;
P_0c0ab628: /* original ff37, guest PC 0x0c0ab628 */
if(!s->budget--) { s->failed_pc=0x0c0ab628u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab62a;
P_0c0ab62a: /* original e014, guest PC 0x0c0ab62a */
if(!s->budget--) { s->failed_pc=0x0c0ab62au; return 0; }
r[0]=0x00000014u;
goto P_0c0ab62c;
P_0c0ab62c: /* original f3f6, guest PC 0x0c0ab62c */
if(!s->budget--) { s->failed_pc=0x0c0ab62cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab62e;
P_0c0ab62e: /* original e00c, guest PC 0x0c0ab62e */
if(!s->budget--) { s->failed_pc=0x0c0ab62eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab630;
P_0c0ab630: /* original f0f6, guest PC 0x0c0ab630 */
if(!s->budget--) { s->failed_pc=0x0c0ab630u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0ab632;
P_0c0ab632: /* original e004, guest PC 0x0c0ab632 */
if(!s->budget--) { s->failed_pc=0x0c0ab632u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab634;
P_0c0ab634: /* original f2f6, guest PC 0x0c0ab634 */
if(!s->budget--) { s->failed_pc=0x0c0ab634u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab636;
P_0c0ab636: /* original e014, guest PC 0x0c0ab636 */
if(!s->budget--) { s->failed_pc=0x0c0ab636u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab638;
P_0c0ab638: /* original f32e, guest PC 0x0c0ab638 */
if(!s->budget--) { s->failed_pc=0x0c0ab638u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0ab63a;
P_0c0ab63a: /* original ff37, guest PC 0x0c0ab63a */
if(!s->budget--) { s->failed_pc=0x0c0ab63au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab63c;
P_0c0ab63c: /* original e00c, guest PC 0x0c0ab63c */
if(!s->budget--) { s->failed_pc=0x0c0ab63cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab63e;
P_0c0ab63e: /* original f1f8, guest PC 0x0c0ab63e */
if(!s->budget--) { s->failed_pc=0x0c0ab63eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c0ab640;
P_0c0ab640: /* original f2f6, guest PC 0x0c0ab640 */
if(!s->budget--) { s->failed_pc=0x0c0ab640u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab642;
P_0c0ab642: /* original f122, guest PC 0x0c0ab642 */
if(!s->budget--) { s->failed_pc=0x0c0ab642u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0ab644;
P_0c0ab644: /* original fc11, guest PC 0x0c0ab644 */
if(!s->budget--) { s->failed_pc=0x0c0ab644u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[1],r[18],'-');
goto P_0c0ab646;
P_0c0ab646: /* original e014, guest PC 0x0c0ab646 */
if(!s->budget--) { s->failed_pc=0x0c0ab646u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab648;
P_0c0ab648: /* original f3f6, guest PC 0x0c0ab648 */
if(!s->budget--) { s->failed_pc=0x0c0ab648u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab64a;
P_0c0ab64a: /* original 9053, guest PC 0x0c0ab64a */
if(!s->budget--) { s->failed_pc=0x0c0ab64au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f4u,2);
goto P_0c0ab64c;
P_0c0ab64c: /* original fe37, guest PC 0x0c0ab64c */
if(!s->budget--) { s->failed_pc=0x0c0ab64cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab64e;
P_0c0ab64e: /* original 7008, guest PC 0x0c0ab64e */
if(!s->budget--) { s->failed_pc=0x0c0ab64eu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab650;
P_0c0ab650: /* original fec7, guest PC 0x0c0ab650 */
if(!s->budget--) { s->failed_pc=0x0c0ab650u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0ab652;
P_0c0ab652: /* original e014, guest PC 0x0c0ab652 */
if(!s->budget--) { s->failed_pc=0x0c0ab652u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab654;
P_0c0ab654: /* original f3f6, guest PC 0x0c0ab654 */
if(!s->budget--) { s->failed_pc=0x0c0ab654u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab656;
P_0c0ab656: /* original e00c, guest PC 0x0c0ab656 */
if(!s->budget--) { s->failed_pc=0x0c0ab656u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab658;
P_0c0ab658: /* original f3e1, guest PC 0x0c0ab658 */
if(!s->budget--) { s->failed_pc=0x0c0ab658u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'-');
goto P_0c0ab65a;
P_0c0ab65a: /* original ff37, guest PC 0x0c0ab65a */
if(!s->budget--) { s->failed_pc=0x0c0ab65au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab65c;
P_0c0ab65c: /* original f332, guest PC 0x0c0ab65c */
if(!s->budget--) { s->failed_pc=0x0c0ab65cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'*');
goto P_0c0ab65e;
P_0c0ab65e: /* original f4cc, guest PC 0x0c0ab65e */
if(!s->budget--) { s->failed_pc=0x0c0ab65eu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c0ab660;
P_0c0ab660: /* original f4f1, guest PC 0x0c0ab660 */
if(!s->budget--) { s->failed_pc=0x0c0ab660u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0ab662;
P_0c0ab662: /* original f04c, guest PC 0x0c0ab662 */
if(!s->budget--) { s->failed_pc=0x0c0ab662u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ab664;
P_0c0ab664: /* original f34e, guest PC 0x0c0ab664 */
if(!s->budget--) { s->failed_pc=0x0c0ab664u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0ab666;
P_0c0ab666: /* original ff3a, guest PC 0x0c0ab666 */
if(!s->budget--) { s->failed_pc=0x0c0ab666u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab668;
P_0c0ab668: /* original 9048, guest PC 0x0c0ab668 */
if(!s->budget--) { s->failed_pc=0x0c0ab668u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6fcu,2);
goto P_0c0ab66a;
P_0c0ab66a: /* original f5e6, guest PC 0x0c0ab66a */
if(!s->budget--) { s->failed_pc=0x0c0ab66au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab66c;
P_0c0ab66c: /* original e004, guest PC 0x0c0ab66c */
if(!s->budget--) { s->failed_pc=0x0c0ab66cu; return 0; }
r[0]=0x00000004u;
goto P_0c0ab66e;
P_0c0ab66e: /* original f35c, guest PC 0x0c0ab66e */
if(!s->budget--) { s->failed_pc=0x0c0ab66eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ab670;
P_0c0ab670: /* original f352, guest PC 0x0c0ab670 */
if(!s->budget--) { s->failed_pc=0x0c0ab670u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab672;
P_0c0ab672: /* original ff37, guest PC 0x0c0ab672 */
if(!s->budget--) { s->failed_pc=0x0c0ab672u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab674;
P_0c0ab674: /* original f2f8, guest PC 0x0c0ab674 */
if(!s->budget--) { s->failed_pc=0x0c0ab674u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0ab676;
P_0c0ab676: /* original f235, guest PC 0x0c0ab676 */
if(!s->budget--) { s->failed_pc=0x0c0ab676u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab678;
P_0c0ab678: /* original 8b1e, guest PC 0x0c0ab678 */
if(!s->budget--) { s->failed_pc=0x0c0ab678u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab6b8; }
goto P_0c0ab67a;
P_0c0ab67a: /* original c722, guest PC 0x0c0ab67a */
if(!s->budget--) { s->failed_pc=0x0c0ab67au; return 0; }
r[0]=code_base|0x000ab704u;
goto P_0c0ab67c;
P_0c0ab67c: /* original f3f8, guest PC 0x0c0ab67c */
if(!s->budget--) { s->failed_pc=0x0c0ab67cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab67e;
P_0c0ab67e: /* original f208, guest PC 0x0c0ab67e */
if(!s->budget--) { s->failed_pc=0x0c0ab67eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab680;
P_0c0ab680: /* original f235, guest PC 0x0c0ab680 */
if(!s->budget--) { s->failed_pc=0x0c0ab680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab682;
P_0c0ab682: /* original 8b01, guest PC 0x0c0ab682 */
if(!s->budget--) { s->failed_pc=0x0c0ab682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab688; }
goto P_0c0ab684;
P_0c0ab684: /* original a001, guest PC 0x0c0ab684 */
if(!s->budget--) { s->failed_pc=0x0c0ab684u; return 0; }
fr[3]=0;
goto P_0c0ab68a;
P_0c0ab686: /* original f38d, guest PC 0x0c0ab686 */
if(!s->budget--) { s->failed_pc=0x0c0ab686u; return 0; }
fr[3]=0;
goto P_0c0ab688;
P_0c0ab688: /* original f37d, guest PC 0x0c0ab688 */
if(!s->budget--) { s->failed_pc=0x0c0ab688u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0ab68a;
P_0c0ab68a: /* original e004, guest PC 0x0c0ab68a */
if(!s->budget--) { s->failed_pc=0x0c0ab68au; return 0; }
r[0]=0x00000004u;
goto P_0c0ab68c;
P_0c0ab68c: /* original ff37, guest PC 0x0c0ab68c */
if(!s->budget--) { s->failed_pc=0x0c0ab68cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab68e;
P_0c0ab68e: /* original c71e, guest PC 0x0c0ab68e */
if(!s->budget--) { s->failed_pc=0x0c0ab68eu; return 0; }
r[0]=code_base|0x000ab708u;
goto P_0c0ab690;
P_0c0ab690: /* original f6f8, guest PC 0x0c0ab690 */
if(!s->budget--) { s->failed_pc=0x0c0ab690u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c0ab692;
P_0c0ab692: /* original f632, guest PC 0x0c0ab692 */
if(!s->budget--) { s->failed_pc=0x0c0ab692u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0ab694;
P_0c0ab694: /* original f26c, guest PC 0x0c0ab694 */
if(!s->budget--) { s->failed_pc=0x0c0ab694u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0ab696;
P_0c0ab696: /* original f6dc, guest PC 0x0c0ab696 */
if(!s->budget--) { s->failed_pc=0x0c0ab696u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0ab698;
P_0c0ab698: /* original f623, guest PC 0x0c0ab698 */
if(!s->budget--) { s->failed_pc=0x0c0ab698u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'/');
goto P_0c0ab69a;
P_0c0ab69a: /* original f208, guest PC 0x0c0ab69a */
if(!s->budget--) { s->failed_pc=0x0c0ab69au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab69c;
P_0c0ab69c: /* original e00c, guest PC 0x0c0ab69c */
if(!s->budget--) { s->failed_pc=0x0c0ab69cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab69e;
P_0c0ab69e: /* original f521, guest PC 0x0c0ab69e */
if(!s->budget--) { s->failed_pc=0x0c0ab69eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0ab6a0;
P_0c0ab6a0: /* original f562, guest PC 0x0c0ab6a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0ab6a2;
P_0c0ab6a2: /* original ff5a, guest PC 0x0c0ab6a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a2u; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c0ab6a4;
P_0c0ab6a4: /* original f1f6, guest PC 0x0c0ab6a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a4u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ab6a6;
P_0c0ab6a6: /* original f05c, guest PC 0x0c0ab6a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0ab6a8;
P_0c0ab6a8: /* original ff4e, guest PC 0x0c0ab6a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a8u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[4],fr[15],r[18]);
goto P_0c0ab6aa;
P_0c0ab6aa: /* original fe1e, guest PC 0x0c0ab6aa */
if(!s->budget--) { s->failed_pc=0x0c0ab6aau; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[1],fr[14],r[18]);
goto P_0c0ab6ac;
P_0c0ab6ac: /* original 9022, guest PC 0x0c0ab6ac */
if(!s->budget--) { s->failed_pc=0x0c0ab6acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f4u,2);
goto P_0c0ab6ae;
P_0c0ab6ae: /* original f4fc, guest PC 0x0c0ab6ae */
if(!s->budget--) { s->failed_pc=0x0c0ab6aeu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ab6b0;
P_0c0ab6b0: /* original f5ec, guest PC 0x0c0ab6b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b0u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0ab6b2;
P_0c0ab6b2: /* original fe57, guest PC 0x0c0ab6b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b2u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ab6b4;
P_0c0ab6b4: /* original 7008, guest PC 0x0c0ab6b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b4u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab6b6;
P_0c0ab6b6: /* original fe47, guest PC 0x0c0ab6b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab6b8;
P_0c0ab6b8: /* original d314, guest PC 0x0c0ab6b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b8u; return 0; }
r[3]=read(ram,0x0c0ab70cu,4);
goto P_0c0ab6ba;
P_0c0ab6ba: /* original 66e3, guest PC 0x0c0ab6ba */
if(!s->budget--) { s->failed_pc=0x0c0ab6bau; return 0; }
r[6]=r[14];
goto P_0c0ab6bc;
P_0c0ab6bc: /* original 65e3, guest PC 0x0c0ab6bc */
if(!s->budget--) { s->failed_pc=0x0c0ab6bcu; return 0; }
r[5]=r[14];
goto P_0c0ab6be;
P_0c0ab6be: /* original 7648, guest PC 0x0c0ab6be */
if(!s->budget--) { s->failed_pc=0x0c0ab6beu; return 0; }
r[6]+=0x00000048u;
goto P_0c0ab6c0;
P_0c0ab6c0: /* original 430b, guest PC 0x0c0ab6c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab6c4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab6c4u) { target=s->pc; goto dispatch; }
goto P_0c0ab6c4;
P_0c0ab6c2: /* original 64e3, guest PC 0x0c0ab6c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c2u; return 0; }
r[4]=r[14];
goto P_0c0ab6c4;
P_0c0ab6c4: /* original 52d1, guest PC 0x0c0ab6c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c4u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab6c6;
P_0c0ab6c6: /* original e062, guest PC 0x0c0ab6c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c6u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab6c8;
P_0c0ab6c8: /* original 7201, guest PC 0x0c0ab6c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c8u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab6ca;
P_0c0ab6ca: /* original 6323, guest PC 0x0c0ab6ca */
if(!s->budget--) { s->failed_pc=0x0c0ab6cau; return 0; }
r[3]=r[2];
goto P_0c0ab6cc;
P_0c0ab6cc: /* original 1d21, guest PC 0x0c0ab6cc */
if(!s->budget--) { s->failed_pc=0x0c0ab6ccu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab6ce;
P_0c0ab6ce: /* original 0e34, guest PC 0x0c0ab6ce */
if(!s->budget--) { s->failed_pc=0x0c0ab6ceu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab6d0;
P_0c0ab6d0: /* original e377, guest PC 0x0c0ab6d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d0u; return 0; }
r[3]=0x00000077u;
goto P_0c0ab6d2;
P_0c0ab6d2: /* original 52ee, guest PC 0x0c0ab6d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d2u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c0ab6d4;
P_0c0ab6d4: /* original 1f24, guest PC 0x0c0ab6d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d4u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0ab6d6;
P_0c0ab6d6: /* original 1f32, guest PC 0x0c0ab6d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab6d8;
P_0c0ab6d8: /* original 52f4, guest PC 0x0c0ab6d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d8u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0ab6da;
P_0c0ab6da: /* original d30d, guest PC 0x0c0ab6da */
if(!s->budget--) { s->failed_pc=0x0c0ab6dau; return 0; }
r[3]=read(ram,0x0c0ab710u,4);
goto P_0c0ab6dc;
P_0c0ab6dc: /* original 2238, guest PC 0x0c0ab6dc */
if(!s->budget--) { s->failed_pc=0x0c0ab6dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab6de;
P_0c0ab6de: /* original 8901, guest PC 0x0c0ab6de */
if(!s->budget--) { s->failed_pc=0x0c0ab6deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab6e4; }
goto P_0c0ab6e0;
P_0c0ab6e0: /* original e174, guest PC 0x0c0ab6e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e0u; return 0; }
r[1]=0x00000074u;
goto P_0c0ab6e2;
P_0c0ab6e2: /* original 1f12, guest PC 0x0c0ab6e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e2u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0ab6e4;
P_0c0ab6e4: /* original d30b, guest PC 0x0c0ab6e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e4u; return 0; }
r[3]=read(ram,0x0c0ab714u,4);
goto P_0c0ab6e6;
P_0c0ab6e6: /* original 430b, guest PC 0x0c0ab6e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab6eau;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab6eau) { target=s->pc; goto dispatch; }
goto P_0c0ab6ea;
P_0c0ab6e8: /* original 54f2, guest PC 0x0c0ab6e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e8u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab6ea;
P_0c0ab6ea: /* original d30b, guest PC 0x0c0ab6ea */
if(!s->budget--) { s->failed_pc=0x0c0ab6eau; return 0; }
r[3]=read(ram,0x0c0ab718u,4);
goto P_0c0ab6ec;
P_0c0ab6ec: /* original 430b, guest PC 0x0c0ab6ec */
if(!s->budget--) { s->failed_pc=0x0c0ab6ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab6f0u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab6f0u) { target=s->pc; goto dispatch; }
goto P_0c0ab6f0;
P_0c0ab6ee: /* original 54f2, guest PC 0x0c0ab6ee */
if(!s->budget--) { s->failed_pc=0x0c0ab6eeu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab6f0;
P_0c0ab6f0: /* original a09a, guest PC 0x0c0ab6f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6f0u; return 0; }
goto P_0c0ab828;
P_0c0ab6f2: /* original 0009, guest PC 0x0c0ab6f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6f2u; return 0; }
if(!vf3_matrix_family(0x0c0ab6f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab6f4u; return 0; } return 1;
P_0c0ab71c: /* original 62d2, guest PC 0x0c0ab71c */
if(!s->budget--) { s->failed_pc=0x0c0ab71cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab71e;
P_0c0ab71e: /* original d34c, guest PC 0x0c0ab71e */
if(!s->budget--) { s->failed_pc=0x0c0ab71eu; return 0; }
r[3]=read(ram,0x0c0ab850u,4);
goto P_0c0ab720;
P_0c0ab720: /* original 2238, guest PC 0x0c0ab720 */
if(!s->budget--) { s->failed_pc=0x0c0ab720u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab722;
P_0c0ab722: /* original 8916, guest PC 0x0c0ab722 */
if(!s->budget--) { s->failed_pc=0x0c0ab722u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab752; }
goto P_0c0ab724;
P_0c0ab724: /* original e064, guest PC 0x0c0ab724 */
if(!s->budget--) { s->failed_pc=0x0c0ab724u; return 0; }
r[0]=0x00000064u;
goto P_0c0ab726;
P_0c0ab726: /* original 01ed, guest PC 0x0c0ab726 */
if(!s->budget--) { s->failed_pc=0x0c0ab726u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab728;
P_0c0ab728: /* original 611d, guest PC 0x0c0ab728 */
if(!s->budget--) { s->failed_pc=0x0c0ab728u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0ab72a;
P_0c0ab72a: /* original 1f12, guest PC 0x0c0ab72a */
if(!s->budget--) { s->failed_pc=0x0c0ab72au; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0ab72c;
P_0c0ab72c: /* original 9088, guest PC 0x0c0ab72c */
if(!s->budget--) { s->failed_pc=0x0c0ab72cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab840u,2);
goto P_0c0ab72e;
P_0c0ab72e: /* original 03ed, guest PC 0x0c0ab72e */
if(!s->budget--) { s->failed_pc=0x0c0ab72eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab730;
P_0c0ab730: /* original 1f34, guest PC 0x0c0ab730 */
if(!s->budget--) { s->failed_pc=0x0c0ab730u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ab732;
P_0c0ab732: /* original 52f2, guest PC 0x0c0ab732 */
if(!s->budget--) { s->failed_pc=0x0c0ab732u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0ab734;
P_0c0ab734: /* original 3236, guest PC 0x0c0ab734 */
if(!s->budget--) { s->failed_pc=0x0c0ab734u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c0ab736;
P_0c0ab736: /* original 890c, guest PC 0x0c0ab736 */
if(!s->budget--) { s->failed_pc=0x0c0ab736u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab752; }
goto P_0c0ab738;
P_0c0ab738: /* original 63d2, guest PC 0x0c0ab738 */
if(!s->budget--) { s->failed_pc=0x0c0ab738u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ab73a;
P_0c0ab73a: /* original 633d, guest PC 0x0c0ab73a */
if(!s->budget--) { s->failed_pc=0x0c0ab73au; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab73c;
P_0c0ab73c: /* original 6533, guest PC 0x0c0ab73c */
if(!s->budget--) { s->failed_pc=0x0c0ab73cu; return 0; }
r[5]=r[3];
goto P_0c0ab73e;
P_0c0ab73e: /* original 1f34, guest PC 0x0c0ab73e */
if(!s->budget--) { s->failed_pc=0x0c0ab73eu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ab740;
P_0c0ab740: /* original d244, guest PC 0x0c0ab740 */
if(!s->budget--) { s->failed_pc=0x0c0ab740u; return 0; }
r[2]=read(ram,0x0c0ab854u,4);
goto P_0c0ab742;
P_0c0ab742: /* original 420b, guest PC 0x0c0ab742 */
if(!s->budget--) { s->failed_pc=0x0c0ab742u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ab746u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab746u) { target=s->pc; goto dispatch; }
goto P_0c0ab746;
P_0c0ab744: /* original 64e3, guest PC 0x0c0ab744 */
if(!s->budget--) { s->failed_pc=0x0c0ab744u; return 0; }
r[4]=r[14];
goto P_0c0ab746;
P_0c0ab746: /* original 62d2, guest PC 0x0c0ab746 */
if(!s->budget--) { s->failed_pc=0x0c0ab746u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab748;
P_0c0ab748: /* original d343, guest PC 0x0c0ab748 */
if(!s->budget--) { s->failed_pc=0x0c0ab748u; return 0; }
r[3]=read(ram,0x0c0ab858u,4);
goto P_0c0ab74a;
P_0c0ab74a: /* original 2239, guest PC 0x0c0ab74a */
if(!s->budget--) { s->failed_pc=0x0c0ab74au; return 0; }
r[2]&=r[3];
goto P_0c0ab74c;
P_0c0ab74c: /* original 6123, guest PC 0x0c0ab74c */
if(!s->budget--) { s->failed_pc=0x0c0ab74cu; return 0; }
r[1]=r[2];
goto P_0c0ab74e;
P_0c0ab74e: /* original 2d22, guest PC 0x0c0ab74e */
if(!s->budget--) { s->failed_pc=0x0c0ab74eu; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ab750;
P_0c0ab750: /* original 1e2e, guest PC 0x0c0ab750 */
if(!s->budget--) { s->failed_pc=0x0c0ab750u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c0ab752;
P_0c0ab752: /* original 62d2, guest PC 0x0c0ab752 */
if(!s->budget--) { s->failed_pc=0x0c0ab752u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab754;
P_0c0ab754: /* original d341, guest PC 0x0c0ab754 */
if(!s->budget--) { s->failed_pc=0x0c0ab754u; return 0; }
r[3]=read(ram,0x0c0ab85cu,4);
goto P_0c0ab756;
P_0c0ab756: /* original 2238, guest PC 0x0c0ab756 */
if(!s->budget--) { s->failed_pc=0x0c0ab756u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab758;
P_0c0ab758: /* original 893d, guest PC 0x0c0ab758 */
if(!s->budget--) { s->failed_pc=0x0c0ab758u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab7d6; }
goto P_0c0ab75a;
P_0c0ab75a: /* original e064, guest PC 0x0c0ab75a */
if(!s->budget--) { s->failed_pc=0x0c0ab75au; return 0; }
r[0]=0x00000064u;
goto P_0c0ab75c;
P_0c0ab75c: /* original 04ed, guest PC 0x0c0ab75c */
if(!s->budget--) { s->failed_pc=0x0c0ab75cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab75e;
P_0c0ab75e: /* original e30a, guest PC 0x0c0ab75e */
if(!s->budget--) { s->failed_pc=0x0c0ab75eu; return 0; }
r[3]=0x0000000au;
goto P_0c0ab760;
P_0c0ab760: /* original 644d, guest PC 0x0c0ab760 */
if(!s->budget--) { s->failed_pc=0x0c0ab760u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ab762;
P_0c0ab762: /* original 3437, guest PC 0x0c0ab762 */
if(!s->budget--) { s->failed_pc=0x0c0ab762u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0ab764;
P_0c0ab764: /* original 8b02, guest PC 0x0c0ab764 */
if(!s->budget--) { s->failed_pc=0x0c0ab764u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab76c; }
goto P_0c0ab766;
P_0c0ab766: /* original 956c, guest PC 0x0c0ab766 */
if(!s->budget--) { s->failed_pc=0x0c0ab766u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab842u,2);
goto P_0c0ab768;
P_0c0ab768: /* original a009, guest PC 0x0c0ab768 */
if(!s->budget--) { s->failed_pc=0x0c0ab768u; return 0; }
r[5]+=r[14];
goto P_0c0ab77e;
P_0c0ab76a: /* original 35ec, guest PC 0x0c0ab76a */
if(!s->budget--) { s->failed_pc=0x0c0ab76au; return 0; }
r[5]+=r[14];
goto P_0c0ab76c;
P_0c0ab76c: /* original 906b, guest PC 0x0c0ab76c */
if(!s->budget--) { s->failed_pc=0x0c0ab76cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab846u,2);
goto P_0c0ab76e;
P_0c0ab76e: /* original 9569, guest PC 0x0c0ab76e */
if(!s->budget--) { s->failed_pc=0x0c0ab76eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab844u,2);
goto P_0c0ab770;
P_0c0ab770: /* original 03ec, guest PC 0x0c0ab770 */
if(!s->budget--) { s->failed_pc=0x0c0ab770u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab772;
P_0c0ab772: /* original 35ec, guest PC 0x0c0ab772 */
if(!s->budget--) { s->failed_pc=0x0c0ab772u; return 0; }
r[5]+=r[14];
goto P_0c0ab774;
P_0c0ab774: /* original 633c, guest PC 0x0c0ab774 */
if(!s->budget--) { s->failed_pc=0x0c0ab774u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ab776;
P_0c0ab776: /* original 4308, guest PC 0x0c0ab776 */
if(!s->budget--) { s->failed_pc=0x0c0ab776u; return 0; }
r[3]<<=2;
goto P_0c0ab778;
P_0c0ab778: /* original 4308, guest PC 0x0c0ab778 */
if(!s->budget--) { s->failed_pc=0x0c0ab778u; return 0; }
r[3]<<=2;
goto P_0c0ab77a;
P_0c0ab77a: /* original 4308, guest PC 0x0c0ab77a */
if(!s->budget--) { s->failed_pc=0x0c0ab77au; return 0; }
r[3]<<=2;
goto P_0c0ab77c;
P_0c0ab77c: /* original 353c, guest PC 0x0c0ab77c */
if(!s->budget--) { s->failed_pc=0x0c0ab77cu; return 0; }
r[5]+=r[3];
goto P_0c0ab77e;
P_0c0ab77e: /* original e030, guest PC 0x0c0ab77e */
if(!s->budget--) { s->failed_pc=0x0c0ab77eu; return 0; }
r[0]=0x00000030u;
goto P_0c0ab780;
P_0c0ab780: /* original f656, guest PC 0x0c0ab780 */
if(!s->budget--) { s->failed_pc=0x0c0ab780u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0ab782;
P_0c0ab782: /* original e038, guest PC 0x0c0ab782 */
if(!s->budget--) { s->failed_pc=0x0c0ab782u; return 0; }
r[0]=0x00000038u;
goto P_0c0ab784;
P_0c0ab784: /* original f856, guest PC 0x0c0ab784 */
if(!s->budget--) { s->failed_pc=0x0c0ab784u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c0ab786;
P_0c0ab786: /* original 2448, guest PC 0x0c0ab786 */
if(!s->budget--) { s->failed_pc=0x0c0ab786u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ab788;
P_0c0ab788: /* original 905e, guest PC 0x0c0ab788 */
if(!s->budget--) { s->failed_pc=0x0c0ab788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab848u,2);
goto P_0c0ab78a;
P_0c0ab78a: /* original f7e6, guest PC 0x0c0ab78a */
if(!s->budget--) { s->failed_pc=0x0c0ab78au; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0ab78c;
P_0c0ab78c: /* original 7008, guest PC 0x0c0ab78c */
if(!s->budget--) { s->failed_pc=0x0c0ab78cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab78e;
P_0c0ab78e: /* original 8d22, guest PC 0x0c0ab78e */
if(!s->budget--) { s->failed_pc=0x0c0ab78eu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,9,r[14]+r[0]);
if(cond) { goto P_0c0ab7d6; }
goto P_0c0ab792;
P_0c0ab790: /* original f9e6, guest PC 0x0c0ab790 */
if(!s->budget--) { s->failed_pc=0x0c0ab790u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0ab792;
P_0c0ab792: /* original 445a, guest PC 0x0c0ab792 */
if(!s->budget--) { s->failed_pc=0x0c0ab792u; return 0; }
r[53]=r[4];
goto P_0c0ab794;
P_0c0ab794: /* original e010, guest PC 0x0c0ab794 */
if(!s->budget--) { s->failed_pc=0x0c0ab794u; return 0; }
r[0]=0x00000010u;
goto P_0c0ab796;
P_0c0ab796: /* original f2e6, guest PC 0x0c0ab796 */
if(!s->budget--) { s->failed_pc=0x0c0ab796u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab798;
P_0c0ab798: /* original e00c, guest PC 0x0c0ab798 */
if(!s->budget--) { s->failed_pc=0x0c0ab798u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab79a;
P_0c0ab79a: /* original f981, guest PC 0x0c0ab79a */
if(!s->budget--) { s->failed_pc=0x0c0ab79au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[8],r[18],'-');
goto P_0c0ab79c;
P_0c0ab79c: /* original f32d, guest PC 0x0c0ab79c */
if(!s->budget--) { s->failed_pc=0x0c0ab79cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0ab79e;
P_0c0ab79e: /* original ff27, guest PC 0x0c0ab79e */
if(!s->budget--) { s->failed_pc=0x0c0ab79eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab7a0;
P_0c0ab7a0: /* original f4dc, guest PC 0x0c0ab7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a0u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0ab7a2;
P_0c0ab7a2: /* original e018, guest PC 0x0c0ab7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a2u; return 0; }
r[0]=0x00000018u;
goto P_0c0ab7a4;
P_0c0ab7a4: /* original f5e6, guest PC 0x0c0ab7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a4u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab7a6;
P_0c0ab7a6: /* original e004, guest PC 0x0c0ab7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab7a8;
P_0c0ab7a8: /* original f761, guest PC 0x0c0ab7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'-');
goto P_0c0ab7aa;
P_0c0ab7aa: /* original f433, guest PC 0x0c0ab7aa */
if(!s->budget--) { s->failed_pc=0x0c0ab7aau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0ab7ac;
P_0c0ab7ac: /* original ff7a, guest PC 0x0c0ab7ac */
if(!s->budget--) { s->failed_pc=0x0c0ab7acu; return 0; }
vf3_matrix_store(s,ram,7,r[15]);
goto P_0c0ab7ae;
P_0c0ab7ae: /* original ff97, guest PC 0x0c0ab7ae */
if(!s->budget--) { s->failed_pc=0x0c0ab7aeu; return 0; }
vf3_matrix_store(s,ram,9,r[15]+r[0]);
goto P_0c0ab7b0;
P_0c0ab7b0: /* original e004, guest PC 0x0c0ab7b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b0u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab7b2;
P_0c0ab7b2: /* original f3f8, guest PC 0x0c0ab7b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab7b4;
P_0c0ab7b4: /* original f342, guest PC 0x0c0ab7b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0ab7b6;
P_0c0ab7b6: /* original ff3a, guest PC 0x0c0ab7b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab7b8;
P_0c0ab7b8: /* original f2f6, guest PC 0x0c0ab7b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab7ba;
P_0c0ab7ba: /* original e004, guest PC 0x0c0ab7ba */
if(!s->budget--) { s->failed_pc=0x0c0ab7bau; return 0; }
r[0]=0x00000004u;
goto P_0c0ab7bc;
P_0c0ab7bc: /* original f242, guest PC 0x0c0ab7bc */
if(!s->budget--) { s->failed_pc=0x0c0ab7bcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0ab7be;
P_0c0ab7be: /* original ff27, guest PC 0x0c0ab7be */
if(!s->budget--) { s->failed_pc=0x0c0ab7beu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab7c0;
P_0c0ab7c0: /* original e00c, guest PC 0x0c0ab7c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab7c2;
P_0c0ab7c2: /* original f1f6, guest PC 0x0c0ab7c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c2u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ab7c4;
P_0c0ab7c4: /* original f520, guest PC 0x0c0ab7c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'+');
goto P_0c0ab7c6;
P_0c0ab7c6: /* original e00c, guest PC 0x0c0ab7c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab7c8;
P_0c0ab7c8: /* original f130, guest PC 0x0c0ab7c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0ab7ca;
P_0c0ab7ca: /* original ff17, guest PC 0x0c0ab7ca */
if(!s->budget--) { s->failed_pc=0x0c0ab7cau; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0ab7cc;
P_0c0ab7cc: /* original e010, guest PC 0x0c0ab7cc */
if(!s->budget--) { s->failed_pc=0x0c0ab7ccu; return 0; }
r[0]=0x00000010u;
goto P_0c0ab7ce;
P_0c0ab7ce: /* original f31c, guest PC 0x0c0ab7ce */
if(!s->budget--) { s->failed_pc=0x0c0ab7ceu; return 0; }
vf3_matrix_move(s,3,1);
goto P_0c0ab7d0;
P_0c0ab7d0: /* original fe37, guest PC 0x0c0ab7d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab7d2;
P_0c0ab7d2: /* original e018, guest PC 0x0c0ab7d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d2u; return 0; }
r[0]=0x00000018u;
goto P_0c0ab7d4;
P_0c0ab7d4: /* original fe57, guest PC 0x0c0ab7d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d4u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ab7d6;
P_0c0ab7d6: /* original 52f6, guest PC 0x0c0ab7d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d6u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0ab7d8;
P_0c0ab7d8: /* original d321, guest PC 0x0c0ab7d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d8u; return 0; }
r[3]=read(ram,0x0c0ab860u,4);
goto P_0c0ab7da;
P_0c0ab7da: /* original 2238, guest PC 0x0c0ab7da */
if(!s->budget--) { s->failed_pc=0x0c0ab7dau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab7dc;
P_0c0ab7dc: /* original 8b24, guest PC 0x0c0ab7dc */
if(!s->budget--) { s->failed_pc=0x0c0ab7dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab828; }
goto P_0c0ab7de;
P_0c0ab7de: /* original 51ee, guest PC 0x0c0ab7de */
if(!s->budget--) { s->failed_pc=0x0c0ab7deu; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c0ab7e0;
P_0c0ab7e0: /* original d320, guest PC 0x0c0ab7e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e0u; return 0; }
r[3]=read(ram,0x0c0ab864u,4);
goto P_0c0ab7e2;
P_0c0ab7e2: /* original 2138, guest PC 0x0c0ab7e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0ab7e4;
P_0c0ab7e4: /* original 8b02, guest PC 0x0c0ab7e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab7ec; }
goto P_0c0ab7e6;
P_0c0ab7e6: /* original 65e3, guest PC 0x0c0ab7e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e6u; return 0; }
r[5]=r[14];
goto P_0c0ab7e8;
P_0c0ab7e8: /* original a002, guest PC 0x0c0ab7e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e8u; return 0; }
r[4]=0x00000001u;
goto P_0c0ab7f0;
P_0c0ab7ea: /* original e401, guest PC 0x0c0ab7ea */
if(!s->budget--) { s->failed_pc=0x0c0ab7eau; return 0; }
r[4]=0x00000001u;
goto P_0c0ab7ec;
P_0c0ab7ec: /* original e402, guest PC 0x0c0ab7ec */
if(!s->budget--) { s->failed_pc=0x0c0ab7ecu; return 0; }
r[4]=0x00000002u;
goto P_0c0ab7ee;
P_0c0ab7ee: /* original 65e3, guest PC 0x0c0ab7ee */
if(!s->budget--) { s->failed_pc=0x0c0ab7eeu; return 0; }
r[5]=r[14];
goto P_0c0ab7f0;
P_0c0ab7f0: /* original d31d, guest PC 0x0c0ab7f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f0u; return 0; }
r[3]=read(ram,0x0c0ab868u,4);
goto P_0c0ab7f2;
P_0c0ab7f2: /* original 430b, guest PC 0x0c0ab7f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab7f6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab7f6u) { target=s->pc; goto dispatch; }
goto P_0c0ab7f6;
P_0c0ab7f4: /* original 0009, guest PC 0x0c0ab7f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f4u; return 0; }
goto P_0c0ab7f6;
P_0c0ab7f6: /* original e024, guest PC 0x0c0ab7f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f6u; return 0; }
r[0]=0x00000024u;
goto P_0c0ab7f8;
P_0c0ab7f8: /* original f48d, guest PC 0x0c0ab7f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f8u; return 0; }
fr[4]=0;
goto P_0c0ab7fa;
P_0c0ab7fa: /* original fe47, guest PC 0x0c0ab7fa */
if(!s->budget--) { s->failed_pc=0x0c0ab7fau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab7fc;
P_0c0ab7fc: /* original e028, guest PC 0x0c0ab7fc */
if(!s->budget--) { s->failed_pc=0x0c0ab7fcu; return 0; }
r[0]=0x00000028u;
goto P_0c0ab7fe;
P_0c0ab7fe: /* original fe47, guest PC 0x0c0ab7fe */
if(!s->budget--) { s->failed_pc=0x0c0ab7feu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab800;
P_0c0ab800: /* original e02c, guest PC 0x0c0ab800 */
if(!s->budget--) { s->failed_pc=0x0c0ab800u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab802;
P_0c0ab802: /* original fe47, guest PC 0x0c0ab802 */
if(!s->budget--) { s->failed_pc=0x0c0ab802u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab804;
P_0c0ab804: /* original e300, guest PC 0x0c0ab804 */
if(!s->budget--) { s->failed_pc=0x0c0ab804u; return 0; }
r[3]=0x00000000u;
goto P_0c0ab806;
P_0c0ab806: /* original 9020, guest PC 0x0c0ab806 */
if(!s->budget--) { s->failed_pc=0x0c0ab806u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab84au,2);
goto P_0c0ab808;
P_0c0ab808: /* original fe47, guest PC 0x0c0ab808 */
if(!s->budget--) { s->failed_pc=0x0c0ab808u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab80a;
P_0c0ab80a: /* original 7004, guest PC 0x0c0ab80a */
if(!s->budget--) { s->failed_pc=0x0c0ab80au; return 0; }
r[0]+=0x00000004u;
goto P_0c0ab80c;
P_0c0ab80c: /* original fe47, guest PC 0x0c0ab80c */
if(!s->budget--) { s->failed_pc=0x0c0ab80cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab80e;
P_0c0ab80e: /* original 7004, guest PC 0x0c0ab80e */
if(!s->budget--) { s->failed_pc=0x0c0ab80eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0ab810;
P_0c0ab810: /* original fe47, guest PC 0x0c0ab810 */
if(!s->budget--) { s->failed_pc=0x0c0ab810u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab812;
P_0c0ab812: /* original e03e, guest PC 0x0c0ab812 */
if(!s->budget--) { s->failed_pc=0x0c0ab812u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab814;
P_0c0ab814: /* original 1e3e, guest PC 0x0c0ab814 */
if(!s->budget--) { s->failed_pc=0x0c0ab814u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0ab816;
P_0c0ab816: /* original 02ed, guest PC 0x0c0ab816 */
if(!s->budget--) { s->failed_pc=0x0c0ab816u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab818;
P_0c0ab818: /* original 9018, guest PC 0x0c0ab818 */
if(!s->budget--) { s->failed_pc=0x0c0ab818u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab84cu,2);
goto P_0c0ab81a;
P_0c0ab81a: /* original 03ed, guest PC 0x0c0ab81a */
if(!s->budget--) { s->failed_pc=0x0c0ab81au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab81c;
P_0c0ab81c: /* original 3232, guest PC 0x0c0ab81c */
if(!s->budget--) { s->failed_pc=0x0c0ab81cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0ab81e;
P_0c0ab81e: /* original 8903, guest PC 0x0c0ab81e */
if(!s->budget--) { s->failed_pc=0x0c0ab81eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab828; }
goto P_0c0ab820;
P_0c0ab820: /* original d212, guest PC 0x0c0ab820 */
if(!s->budget--) { s->failed_pc=0x0c0ab820u; return 0; }
r[2]=read(ram,0x0c0ab86cu,4);
goto P_0c0ab822;
P_0c0ab822: /* original e048, guest PC 0x0c0ab822 */
if(!s->budget--) { s->failed_pc=0x0c0ab822u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab824;
P_0c0ab824: /* original 2c2b, guest PC 0x0c0ab824 */
if(!s->budget--) { s->failed_pc=0x0c0ab824u; return 0; }
r[12]|=r[2];
goto P_0c0ab826;
P_0c0ab826: /* original 0ec6, guest PC 0x0c0ab826 */
if(!s->budget--) { s->failed_pc=0x0c0ab826u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0ab828;
P_0c0ab828: /* original 7f28, guest PC 0x0c0ab828 */
if(!s->budget--) { s->failed_pc=0x0c0ab828u; return 0; }
r[15]+=0x00000028u;
goto P_0c0ab82a;
P_0c0ab82a: /* original 4f26, guest PC 0x0c0ab82a */
if(!s->budget--) { s->failed_pc=0x0c0ab82au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ab82c;
P_0c0ab82c: /* original fcf9, guest PC 0x0c0ab82c */
if(!s->budget--) { s->failed_pc=0x0c0ab82cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab82e;
P_0c0ab82e: /* original fdf9, guest PC 0x0c0ab82e */
if(!s->budget--) { s->failed_pc=0x0c0ab82eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab830;
P_0c0ab830: /* original fef9, guest PC 0x0c0ab830 */
if(!s->budget--) { s->failed_pc=0x0c0ab830u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab832;
P_0c0ab832: /* original fff9, guest PC 0x0c0ab832 */
if(!s->budget--) { s->failed_pc=0x0c0ab832u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab834;
P_0c0ab834: /* original 6af6, guest PC 0x0c0ab834 */
if(!s->budget--) { s->failed_pc=0x0c0ab834u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ab836;
P_0c0ab836: /* original 6bf6, guest PC 0x0c0ab836 */
if(!s->budget--) { s->failed_pc=0x0c0ab836u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ab838;
P_0c0ab838: /* original 6cf6, guest PC 0x0c0ab838 */
if(!s->budget--) { s->failed_pc=0x0c0ab838u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ab83a;
P_0c0ab83a: /* original 6df6, guest PC 0x0c0ab83a */
if(!s->budget--) { s->failed_pc=0x0c0ab83au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ab83c;
P_0c0ab83c: /* original 000b, guest PC 0x0c0ab83c */
if(!s->budget--) { s->failed_pc=0x0c0ab83cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ab83e: /* original 6ef6, guest PC 0x0c0ab83e */
if(!s->budget--) { s->failed_pc=0x0c0ab83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ab840u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab840u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
