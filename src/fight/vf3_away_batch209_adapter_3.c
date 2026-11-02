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
int vf3_away_batch209_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0aa740u: goto P_0c0aa740;
case 0x0c0aa742u: goto P_0c0aa742;
case 0x0c0aa744u: goto P_0c0aa744;
case 0x0c0aa746u: goto P_0c0aa746;
case 0x0c0aa748u: goto P_0c0aa748;
case 0x0c0aa74au: goto P_0c0aa74a;
case 0x0c0aa74cu: goto P_0c0aa74c;
case 0x0c0aa74eu: goto P_0c0aa74e;
case 0x0c0aa750u: goto P_0c0aa750;
case 0x0c0aa752u: goto P_0c0aa752;
case 0x0c0aa754u: goto P_0c0aa754;
case 0x0c0aa756u: goto P_0c0aa756;
case 0x0c0aa758u: goto P_0c0aa758;
case 0x0c0aa75au: goto P_0c0aa75a;
case 0x0c0aa75cu: goto P_0c0aa75c;
case 0x0c0aa75eu: goto P_0c0aa75e;
case 0x0c0aa760u: goto P_0c0aa760;
case 0x0c0aa762u: goto P_0c0aa762;
case 0x0c0aa764u: goto P_0c0aa764;
case 0x0c0aa766u: goto P_0c0aa766;
case 0x0c0aa768u: goto P_0c0aa768;
case 0x0c0aa76au: goto P_0c0aa76a;
case 0x0c0aa76cu: goto P_0c0aa76c;
case 0x0c0aa76eu: goto P_0c0aa76e;
case 0x0c0aa770u: goto P_0c0aa770;
case 0x0c0aa772u: goto P_0c0aa772;
case 0x0c0aa774u: goto P_0c0aa774;
case 0x0c0aa776u: goto P_0c0aa776;
case 0x0c0aa778u: goto P_0c0aa778;
case 0x0c0aa77au: goto P_0c0aa77a;
case 0x0c0aa77cu: goto P_0c0aa77c;
case 0x0c0aa77eu: goto P_0c0aa77e;
case 0x0c0aa780u: goto P_0c0aa780;
case 0x0c0aa782u: goto P_0c0aa782;
case 0x0c0aa784u: goto P_0c0aa784;
case 0x0c0aa786u: goto P_0c0aa786;
case 0x0c0aa788u: goto P_0c0aa788;
case 0x0c0aa78au: goto P_0c0aa78a;
case 0x0c0aa78cu: goto P_0c0aa78c;
case 0x0c0aa78eu: goto P_0c0aa78e;
case 0x0c0aa790u: goto P_0c0aa790;
case 0x0c0aa792u: goto P_0c0aa792;
case 0x0c0aa794u: goto P_0c0aa794;
case 0x0c0aa796u: goto P_0c0aa796;
case 0x0c0aa798u: goto P_0c0aa798;
case 0x0c0aa79au: goto P_0c0aa79a;
case 0x0c0aa79cu: goto P_0c0aa79c;
case 0x0c0aa79eu: goto P_0c0aa79e;
case 0x0c0aa7a0u: goto P_0c0aa7a0;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0aa740: /* original 2fe6, guest PC 0x0c0aa740 */
if(!s->budget--) { s->failed_pc=0x0c0aa740u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa742;
P_0c0aa742: /* original 6e43, guest PC 0x0c0aa742 */
if(!s->budget--) { s->failed_pc=0x0c0aa742u; return 0; }
r[14]=r[4];
goto P_0c0aa744;
P_0c0aa744: /* original 4f22, guest PC 0x0c0aa744 */
if(!s->budget--) { s->failed_pc=0x0c0aa744u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa746;
P_0c0aa746: /* original d338, guest PC 0x0c0aa746 */
if(!s->budget--) { s->failed_pc=0x0c0aa746u; return 0; }
r[3]=read(ram,0x0c0aa828u,4);
goto P_0c0aa748;
P_0c0aa748: /* original 7ff0, guest PC 0x0c0aa748 */
if(!s->budget--) { s->failed_pc=0x0c0aa748u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0aa74a;
P_0c0aa74a: /* original 2f32, guest PC 0x0c0aa74a */
if(!s->budget--) { s->failed_pc=0x0c0aa74au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0aa74c;
P_0c0aa74c: /* original 64f3, guest PC 0x0c0aa74c */
if(!s->budget--) { s->failed_pc=0x0c0aa74cu; return 0; }
r[4]=r[15];
goto P_0c0aa74e;
P_0c0aa74e: /* original 9063, guest PC 0x0c0aa74e */
if(!s->budget--) { s->failed_pc=0x0c0aa74eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa818u,2);
goto P_0c0aa750;
P_0c0aa750: /* original 7404, guest PC 0x0c0aa750 */
if(!s->budget--) { s->failed_pc=0x0c0aa750u; return 0; }
r[4]+=0x00000004u;
goto P_0c0aa752;
P_0c0aa752: /* original d336, guest PC 0x0c0aa752 */
if(!s->budget--) { s->failed_pc=0x0c0aa752u; return 0; }
r[3]=read(ram,0x0c0aa82cu,4);
goto P_0c0aa754;
P_0c0aa754: /* original f5e6, guest PC 0x0c0aa754 */
if(!s->budget--) { s->failed_pc=0x0c0aa754u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0aa756;
P_0c0aa756: /* original 70f8, guest PC 0x0c0aa756 */
if(!s->budget--) { s->failed_pc=0x0c0aa756u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0aa758;
P_0c0aa758: /* original 430b, guest PC 0x0c0aa758 */
if(!s->budget--) { s->failed_pc=0x0c0aa758u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa75cu;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa75cu) { target=s->pc; goto dispatch; }
goto P_0c0aa75c;
P_0c0aa75a: /* original f4e6, guest PC 0x0c0aa75a */
if(!s->budget--) { s->failed_pc=0x0c0aa75au; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0aa75c;
P_0c0aa75c: /* original e004, guest PC 0x0c0aa75c */
if(!s->budget--) { s->failed_pc=0x0c0aa75cu; return 0; }
r[0]=0x00000004u;
goto P_0c0aa75e;
P_0c0aa75e: /* original f5f6, guest PC 0x0c0aa75e */
if(!s->budget--) { s->failed_pc=0x0c0aa75eu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0aa760;
P_0c0aa760: /* original e00c, guest PC 0x0c0aa760 */
if(!s->budget--) { s->failed_pc=0x0c0aa760u; return 0; }
r[0]=0x0000000cu;
goto P_0c0aa762;
P_0c0aa762: /* original f7f6, guest PC 0x0c0aa762 */
if(!s->budget--) { s->failed_pc=0x0c0aa762u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0aa764;
P_0c0aa764: /* original e024, guest PC 0x0c0aa764 */
if(!s->budget--) { s->failed_pc=0x0c0aa764u; return 0; }
r[0]=0x00000024u;
goto P_0c0aa766;
P_0c0aa766: /* original f8e6, guest PC 0x0c0aa766 */
if(!s->budget--) { s->failed_pc=0x0c0aa766u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0aa768;
P_0c0aa768: /* original e02c, guest PC 0x0c0aa768 */
if(!s->budget--) { s->failed_pc=0x0c0aa768u; return 0; }
r[0]=0x0000002cu;
goto P_0c0aa76a;
P_0c0aa76a: /* original f4e6, guest PC 0x0c0aa76a */
if(!s->budget--) { s->failed_pc=0x0c0aa76au; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0aa76c;
P_0c0aa76c: /* original e11c, guest PC 0x0c0aa76c */
if(!s->budget--) { s->failed_pc=0x0c0aa76cu; return 0; }
r[1]=0x0000001cu;
goto P_0c0aa76e;
P_0c0aa76e: /* original 60f2, guest PC 0x0c0aa76e */
if(!s->budget--) { s->failed_pc=0x0c0aa76eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0aa770;
P_0c0aa770: /* original 001c, guest PC 0x0c0aa770 */
if(!s->budget--) { s->failed_pc=0x0c0aa770u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0aa772;
P_0c0aa772: /* original 600c, guest PC 0x0c0aa772 */
if(!s->budget--) { s->failed_pc=0x0c0aa772u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa774;
P_0c0aa774: /* original c90f, guest PC 0x0c0aa774 */
if(!s->budget--) { s->failed_pc=0x0c0aa774u; return 0; }
r[0]&=15u;
goto P_0c0aa776;
P_0c0aa776: /* original 8809, guest PC 0x0c0aa776 */
if(!s->budget--) { s->failed_pc=0x0c0aa776u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0aa778;
P_0c0aa778: /* original 8d03, guest PC 0x0c0aa778 */
if(!s->budget--) { s->failed_pc=0x0c0aa778u; return 0; }
cond=r[17]&1u;
fr[7]^=0x80000000u;
if(cond) { goto P_0c0aa782; }
goto P_0c0aa77c;
P_0c0aa77a: /* original f74d, guest PC 0x0c0aa77a */
if(!s->budget--) { s->failed_pc=0x0c0aa77au; return 0; }
fr[7]^=0x80000000u;
goto P_0c0aa77c;
P_0c0aa77c: /* original c72c, guest PC 0x0c0aa77c */
if(!s->budget--) { s->failed_pc=0x0c0aa77cu; return 0; }
r[0]=code_base|0x000aa830u;
goto P_0c0aa77e;
P_0c0aa77e: /* original a002, guest PC 0x0c0aa77e */
if(!s->budget--) { s->failed_pc=0x0c0aa77eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0aa786;
P_0c0aa780: /* original f608, guest PC 0x0c0aa780 */
if(!s->budget--) { s->failed_pc=0x0c0aa780u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0aa782;
P_0c0aa782: /* original c72c, guest PC 0x0c0aa782 */
if(!s->budget--) { s->failed_pc=0x0c0aa782u; return 0; }
r[0]=code_base|0x000aa834u;
goto P_0c0aa784;
P_0c0aa784: /* original f608, guest PC 0x0c0aa784 */
if(!s->budget--) { s->failed_pc=0x0c0aa784u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0aa786;
P_0c0aa786: /* original f37c, guest PC 0x0c0aa786 */
if(!s->budget--) { s->failed_pc=0x0c0aa786u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0aa788;
P_0c0aa788: /* original f562, guest PC 0x0c0aa788 */
if(!s->budget--) { s->failed_pc=0x0c0aa788u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0aa78a;
P_0c0aa78a: /* original f76c, guest PC 0x0c0aa78a */
if(!s->budget--) { s->failed_pc=0x0c0aa78au; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c0aa78c;
P_0c0aa78c: /* original f732, guest PC 0x0c0aa78c */
if(!s->budget--) { s->failed_pc=0x0c0aa78cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0aa78e;
P_0c0aa78e: /* original 7f10, guest PC 0x0c0aa78e */
if(!s->budget--) { s->failed_pc=0x0c0aa78eu; return 0; }
r[15]+=0x00000010u;
goto P_0c0aa790;
P_0c0aa790: /* original e024, guest PC 0x0c0aa790 */
if(!s->budget--) { s->failed_pc=0x0c0aa790u; return 0; }
r[0]=0x00000024u;
goto P_0c0aa792;
P_0c0aa792: /* original f850, guest PC 0x0c0aa792 */
if(!s->budget--) { s->failed_pc=0x0c0aa792u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'+');
goto P_0c0aa794;
P_0c0aa794: /* original f470, guest PC 0x0c0aa794 */
if(!s->budget--) { s->failed_pc=0x0c0aa794u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c0aa796;
P_0c0aa796: /* original 4f26, guest PC 0x0c0aa796 */
if(!s->budget--) { s->failed_pc=0x0c0aa796u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa798;
P_0c0aa798: /* original fe87, guest PC 0x0c0aa798 */
if(!s->budget--) { s->failed_pc=0x0c0aa798u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c0aa79a;
P_0c0aa79a: /* original e02c, guest PC 0x0c0aa79a */
if(!s->budget--) { s->failed_pc=0x0c0aa79au; return 0; }
r[0]=0x0000002cu;
goto P_0c0aa79c;
P_0c0aa79c: /* original fe47, guest PC 0x0c0aa79c */
if(!s->budget--) { s->failed_pc=0x0c0aa79cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0aa79e;
P_0c0aa79e: /* original 000b, guest PC 0x0c0aa79e */
if(!s->budget--) { s->failed_pc=0x0c0aa79eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aa7a0: /* original 6ef6, guest PC 0x0c0aa7a0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aa7a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa7a2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
