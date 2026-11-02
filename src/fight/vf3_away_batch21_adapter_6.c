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
int vf3_away_batch21_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09ee18u: goto P_0c09ee18;
case 0x0c09ee1au: goto P_0c09ee1a;
case 0x0c09ee1cu: goto P_0c09ee1c;
case 0x0c09ee1eu: goto P_0c09ee1e;
case 0x0c09ee20u: goto P_0c09ee20;
case 0x0c09ee22u: goto P_0c09ee22;
case 0x0c09ee24u: goto P_0c09ee24;
case 0x0c09ee26u: goto P_0c09ee26;
case 0x0c09ee28u: goto P_0c09ee28;
case 0x0c09ee2au: goto P_0c09ee2a;
case 0x0c09ee2cu: goto P_0c09ee2c;
case 0x0c09ee2eu: goto P_0c09ee2e;
case 0x0c09ee30u: goto P_0c09ee30;
case 0x0c09ee32u: goto P_0c09ee32;
case 0x0c09ee34u: goto P_0c09ee34;
case 0x0c09ee36u: goto P_0c09ee36;
case 0x0c09ee38u: goto P_0c09ee38;
case 0x0c09ee3au: goto P_0c09ee3a;
case 0x0c09ee3cu: goto P_0c09ee3c;
case 0x0c09ee3eu: goto P_0c09ee3e;
case 0x0c09ee40u: goto P_0c09ee40;
case 0x0c09ee42u: goto P_0c09ee42;
case 0x0c09ee44u: goto P_0c09ee44;
case 0x0c09ee46u: goto P_0c09ee46;
case 0x0c09ee48u: goto P_0c09ee48;
case 0x0c09ee4au: goto P_0c09ee4a;
case 0x0c09ee4cu: goto P_0c09ee4c;
case 0x0c09ee4eu: goto P_0c09ee4e;
case 0x0c09ee50u: goto P_0c09ee50;
case 0x0c09ee52u: goto P_0c09ee52;
case 0x0c09ee54u: goto P_0c09ee54;
case 0x0c09ee56u: goto P_0c09ee56;
case 0x0c09ee58u: goto P_0c09ee58;
case 0x0c09ee5au: goto P_0c09ee5a;
case 0x0c09ee5cu: goto P_0c09ee5c;
case 0x0c09ee5eu: goto P_0c09ee5e;
case 0x0c09ee60u: goto P_0c09ee60;
case 0x0c09ee62u: goto P_0c09ee62;
case 0x0c09ee64u: goto P_0c09ee64;
case 0x0c09ee66u: goto P_0c09ee66;
case 0x0c09ee68u: goto P_0c09ee68;
case 0x0c09ee6au: goto P_0c09ee6a;
case 0x0c09ee6cu: goto P_0c09ee6c;
case 0x0c09ee6eu: goto P_0c09ee6e;
case 0x0c09ee70u: goto P_0c09ee70;
case 0x0c09ee72u: goto P_0c09ee72;
case 0x0c09ee74u: goto P_0c09ee74;
case 0x0c09ee76u: goto P_0c09ee76;
case 0x0c09ee78u: goto P_0c09ee78;
case 0x0c09ee7au: goto P_0c09ee7a;
case 0x0c09ee7cu: goto P_0c09ee7c;
case 0x0c09ee7eu: goto P_0c09ee7e;
case 0x0c09ee80u: goto P_0c09ee80;
case 0x0c09ee82u: goto P_0c09ee82;
case 0x0c09ee84u: goto P_0c09ee84;
case 0x0c09ee86u: goto P_0c09ee86;
case 0x0c09ee88u: goto P_0c09ee88;
case 0x0c09ee8au: goto P_0c09ee8a;
case 0x0c09ee8cu: goto P_0c09ee8c;
case 0x0c09ee8eu: goto P_0c09ee8e;
case 0x0c09ee90u: goto P_0c09ee90;
case 0x0c09ee92u: goto P_0c09ee92;
case 0x0c09ee94u: goto P_0c09ee94;
case 0x0c09ee96u: goto P_0c09ee96;
case 0x0c09ee98u: goto P_0c09ee98;
case 0x0c09ee9au: goto P_0c09ee9a;
case 0x0c09ee9cu: goto P_0c09ee9c;
case 0x0c09ee9eu: goto P_0c09ee9e;
case 0x0c09eea0u: goto P_0c09eea0;
case 0x0c09eea2u: goto P_0c09eea2;
case 0x0c09eea4u: goto P_0c09eea4;
case 0x0c09eea6u: goto P_0c09eea6;
case 0x0c09eea8u: goto P_0c09eea8;
case 0x0c09eeaau: goto P_0c09eeaa;
case 0x0c09eeacu: goto P_0c09eeac;
case 0x0c09eeaeu: goto P_0c09eeae;
case 0x0c09eeb0u: goto P_0c09eeb0;
case 0x0c09eeb2u: goto P_0c09eeb2;
case 0x0c09eeb4u: goto P_0c09eeb4;
case 0x0c09eeb6u: goto P_0c09eeb6;
case 0x0c09eeb8u: goto P_0c09eeb8;
case 0x0c09eebau: goto P_0c09eeba;
case 0x0c09eebcu: goto P_0c09eebc;
case 0x0c09eebeu: goto P_0c09eebe;
case 0x0c09eec0u: goto P_0c09eec0;
case 0x0c09eec2u: goto P_0c09eec2;
case 0x0c09eec4u: goto P_0c09eec4;
case 0x0c09eec6u: goto P_0c09eec6;
case 0x0c09eec8u: goto P_0c09eec8;
case 0x0c09eecau: goto P_0c09eeca;
case 0x0c09eeccu: goto P_0c09eecc;
case 0x0c09eeceu: goto P_0c09eece;
case 0x0c09eed0u: goto P_0c09eed0;
case 0x0c09eed2u: goto P_0c09eed2;
case 0x0c09eed4u: goto P_0c09eed4;
case 0x0c09eed6u: goto P_0c09eed6;
case 0x0c09eed8u: goto P_0c09eed8;
case 0x0c09eedau: goto P_0c09eeda;
case 0x0c09eedcu: goto P_0c09eedc;
case 0x0c09eedeu: goto P_0c09eede;
case 0x0c09eee0u: goto P_0c09eee0;
case 0x0c09eee2u: goto P_0c09eee2;
case 0x0c09eee4u: goto P_0c09eee4;
case 0x0c09eee6u: goto P_0c09eee6;
case 0x0c09eee8u: goto P_0c09eee8;
case 0x0c09eeeau: goto P_0c09eeea;
case 0x0c09eeecu: goto P_0c09eeec;
case 0x0c09eeeeu: goto P_0c09eeee;
case 0x0c09eef0u: goto P_0c09eef0;
case 0x0c09eef2u: goto P_0c09eef2;
case 0x0c09eef4u: goto P_0c09eef4;
case 0x0c09eef6u: goto P_0c09eef6;
case 0x0c09eef8u: goto P_0c09eef8;
case 0x0c09eefau: goto P_0c09eefa;
case 0x0c09eefcu: goto P_0c09eefc;
case 0x0c09eefeu: goto P_0c09eefe;
case 0x0c09ef00u: goto P_0c09ef00;
case 0x0c09ef02u: goto P_0c09ef02;
case 0x0c09ef04u: goto P_0c09ef04;
case 0x0c09ef06u: goto P_0c09ef06;
case 0x0c09ef08u: goto P_0c09ef08;
case 0x0c09ef0au: goto P_0c09ef0a;
case 0x0c09ef0cu: goto P_0c09ef0c;
case 0x0c09ef0eu: goto P_0c09ef0e;
case 0x0c09ef10u: goto P_0c09ef10;
case 0x0c09ef12u: goto P_0c09ef12;
case 0x0c09ef14u: goto P_0c09ef14;
case 0x0c09ef16u: goto P_0c09ef16;
case 0x0c09ef18u: goto P_0c09ef18;
case 0x0c09ef1au: goto P_0c09ef1a;
case 0x0c09ef1cu: goto P_0c09ef1c;
case 0x0c09ef1eu: goto P_0c09ef1e;
case 0x0c09ef20u: goto P_0c09ef20;
case 0x0c09ef22u: goto P_0c09ef22;
case 0x0c09ef24u: goto P_0c09ef24;
case 0x0c09ef26u: goto P_0c09ef26;
case 0x0c09ef28u: goto P_0c09ef28;
case 0x0c09ef78u: goto P_0c09ef78;
case 0x0c09ef7au: goto P_0c09ef7a;
case 0x0c09ef7cu: goto P_0c09ef7c;
case 0x0c09ef7eu: goto P_0c09ef7e;
case 0x0c09ef80u: goto P_0c09ef80;
case 0x0c09ef82u: goto P_0c09ef82;
case 0x0c09ef84u: goto P_0c09ef84;
case 0x0c09ef86u: goto P_0c09ef86;
case 0x0c09ef88u: goto P_0c09ef88;
case 0x0c09ef8au: goto P_0c09ef8a;
case 0x0c09ef8cu: goto P_0c09ef8c;
case 0x0c09ef8eu: goto P_0c09ef8e;
case 0x0c09ef90u: goto P_0c09ef90;
case 0x0c09ef92u: goto P_0c09ef92;
case 0x0c09ef94u: goto P_0c09ef94;
case 0x0c09ef96u: goto P_0c09ef96;
case 0x0c09ef98u: goto P_0c09ef98;
case 0x0c09ef9au: goto P_0c09ef9a;
case 0x0c09ef9cu: goto P_0c09ef9c;
case 0x0c09ef9eu: goto P_0c09ef9e;
case 0x0c09efa0u: goto P_0c09efa0;
case 0x0c09efa2u: goto P_0c09efa2;
case 0x0c09efa4u: goto P_0c09efa4;
case 0x0c09efa6u: goto P_0c09efa6;
case 0x0c09efa8u: goto P_0c09efa8;
case 0x0c09efaau: goto P_0c09efaa;
case 0x0c09efacu: goto P_0c09efac;
case 0x0c09efaeu: goto P_0c09efae;
case 0x0c09efb0u: goto P_0c09efb0;
case 0x0c09efb2u: goto P_0c09efb2;
case 0x0c09efb4u: goto P_0c09efb4;
case 0x0c09efb6u: goto P_0c09efb6;
case 0x0c09efb8u: goto P_0c09efb8;
case 0x0c09efbau: goto P_0c09efba;
case 0x0c09efbcu: goto P_0c09efbc;
case 0x0c09efbeu: goto P_0c09efbe;
case 0x0c09efc0u: goto P_0c09efc0;
case 0x0c09efc2u: goto P_0c09efc2;
case 0x0c09efc4u: goto P_0c09efc4;
case 0x0c09efc6u: goto P_0c09efc6;
case 0x0c09efc8u: goto P_0c09efc8;
case 0x0c09efcau: goto P_0c09efca;
case 0x0c09efccu: goto P_0c09efcc;
case 0x0c09efceu: goto P_0c09efce;
case 0x0c09efd0u: goto P_0c09efd0;
case 0x0c09efd2u: goto P_0c09efd2;
case 0x0c09efd4u: goto P_0c09efd4;
case 0x0c09efd6u: goto P_0c09efd6;
case 0x0c09efd8u: goto P_0c09efd8;
case 0x0c09efdau: goto P_0c09efda;
case 0x0c09efdcu: goto P_0c09efdc;
case 0x0c09efdeu: goto P_0c09efde;
case 0x0c09efe0u: goto P_0c09efe0;
case 0x0c09efe2u: goto P_0c09efe2;
case 0x0c09efe4u: goto P_0c09efe4;
case 0x0c09f01au: goto P_0c09f01a;
case 0x0c09f01cu: goto P_0c09f01c;
case 0x0c09f01eu: goto P_0c09f01e;
case 0x0c09f020u: goto P_0c09f020;
case 0x0c09f022u: goto P_0c09f022;
case 0x0c09f024u: goto P_0c09f024;
case 0x0c09f026u: goto P_0c09f026;
case 0x0c09f028u: goto P_0c09f028;
case 0x0c09f02au: goto P_0c09f02a;
case 0x0c09f02cu: goto P_0c09f02c;
case 0x0c09f02eu: goto P_0c09f02e;
case 0x0c09f030u: goto P_0c09f030;
case 0x0c09f032u: goto P_0c09f032;
case 0x0c09f034u: goto P_0c09f034;
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
case 0x0c09f432u: goto P_0c09f432;
case 0x0c09f434u: goto P_0c09f434;
case 0x0c09f436u: goto P_0c09f436;
case 0x0c09f438u: goto P_0c09f438;
case 0x0c09f43au: goto P_0c09f43a;
case 0x0c09f43cu: goto P_0c09f43c;
case 0x0c09f43eu: goto P_0c09f43e;
case 0x0c09f440u: goto P_0c09f440;
case 0x0c09f442u: goto P_0c09f442;
case 0x0c09f444u: goto P_0c09f444;
case 0x0c09f446u: goto P_0c09f446;
case 0x0c09f448u: goto P_0c09f448;
case 0x0c09f44au: goto P_0c09f44a;
case 0x0c09f44cu: goto P_0c09f44c;
case 0x0c09f44eu: goto P_0c09f44e;
case 0x0c09f450u: goto P_0c09f450;
case 0x0c09f452u: goto P_0c09f452;
case 0x0c09f454u: goto P_0c09f454;
case 0x0c09f456u: goto P_0c09f456;
case 0x0c09f458u: goto P_0c09f458;
case 0x0c09f45au: goto P_0c09f45a;
case 0x0c09f45cu: goto P_0c09f45c;
case 0x0c09f45eu: goto P_0c09f45e;
case 0x0c09f460u: goto P_0c09f460;
case 0x0c09f462u: goto P_0c09f462;
case 0x0c09f464u: goto P_0c09f464;
case 0x0c09f466u: goto P_0c09f466;
case 0x0c09f468u: goto P_0c09f468;
case 0x0c09f46au: goto P_0c09f46a;
case 0x0c09f46cu: goto P_0c09f46c;
case 0x0c09f46eu: goto P_0c09f46e;
case 0x0c09f470u: goto P_0c09f470;
case 0x0c09f472u: goto P_0c09f472;
case 0x0c09f474u: goto P_0c09f474;
case 0x0c09f476u: goto P_0c09f476;
case 0x0c09f478u: goto P_0c09f478;
case 0x0c09f47au: goto P_0c09f47a;
case 0x0c09f47cu: goto P_0c09f47c;
case 0x0c09f47eu: goto P_0c09f47e;
case 0x0c09f480u: goto P_0c09f480;
case 0x0c09f482u: goto P_0c09f482;
case 0x0c09f484u: goto P_0c09f484;
case 0x0c09f486u: goto P_0c09f486;
case 0x0c09f488u: goto P_0c09f488;
case 0x0c09f48au: goto P_0c09f48a;
case 0x0c09f48cu: goto P_0c09f48c;
case 0x0c09f48eu: goto P_0c09f48e;
case 0x0c09f490u: goto P_0c09f490;
case 0x0c09f492u: goto P_0c09f492;
case 0x0c09f494u: goto P_0c09f494;
case 0x0c09f496u: goto P_0c09f496;
case 0x0c09f498u: goto P_0c09f498;
case 0x0c09f49au: goto P_0c09f49a;
case 0x0c09f49cu: goto P_0c09f49c;
case 0x0c09f49eu: goto P_0c09f49e;
case 0x0c09f4a0u: goto P_0c09f4a0;
case 0x0c09f4a2u: goto P_0c09f4a2;
case 0x0c09f4a4u: goto P_0c09f4a4;
case 0x0c09f4a6u: goto P_0c09f4a6;
case 0x0c09f4a8u: goto P_0c09f4a8;
case 0x0c09f4aau: goto P_0c09f4aa;
case 0x0c09f4acu: goto P_0c09f4ac;
case 0x0c09f4aeu: goto P_0c09f4ae;
case 0x0c09f4b0u: goto P_0c09f4b0;
case 0x0c09f4b2u: goto P_0c09f4b2;
case 0x0c09f4b4u: goto P_0c09f4b4;
case 0x0c09f4b6u: goto P_0c09f4b6;
case 0x0c09f4b8u: goto P_0c09f4b8;
case 0x0c09f4bau: goto P_0c09f4ba;
case 0x0c09f4bcu: goto P_0c09f4bc;
case 0x0c09f4beu: goto P_0c09f4be;
case 0x0c09f4c0u: goto P_0c09f4c0;
case 0x0c09f4c2u: goto P_0c09f4c2;
case 0x0c09f4c4u: goto P_0c09f4c4;
case 0x0c09f4c6u: goto P_0c09f4c6;
case 0x0c09f4c8u: goto P_0c09f4c8;
case 0x0c09f4cau: goto P_0c09f4ca;
case 0x0c09f4ccu: goto P_0c09f4cc;
case 0x0c09f4ceu: goto P_0c09f4ce;
case 0x0c09f4d0u: goto P_0c09f4d0;
case 0x0c09f4d2u: goto P_0c09f4d2;
case 0x0c09f4d4u: goto P_0c09f4d4;
case 0x0c09f4d6u: goto P_0c09f4d6;
case 0x0c09f4d8u: goto P_0c09f4d8;
case 0x0c09f4dau: goto P_0c09f4da;
case 0x0c09f4dcu: goto P_0c09f4dc;
case 0x0c09f4deu: goto P_0c09f4de;
case 0x0c09f4e0u: goto P_0c09f4e0;
case 0x0c09f4e2u: goto P_0c09f4e2;
case 0x0c09f4e4u: goto P_0c09f4e4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09ee18: /* original 2fe6, guest PC 0x0c09ee18 */
if(!s->budget--) { s->failed_pc=0x0c09ee18u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ee1a;
P_0c09ee1a: /* original 6e43, guest PC 0x0c09ee1a */
if(!s->budget--) { s->failed_pc=0x0c09ee1au; return 0; }
r[14]=r[4];
goto P_0c09ee1c;
P_0c09ee1c: /* original 2fd6, guest PC 0x0c09ee1c */
if(!s->budget--) { s->failed_pc=0x0c09ee1cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ee1e;
P_0c09ee1e: /* original e210, guest PC 0x0c09ee1e */
if(!s->budget--) { s->failed_pc=0x0c09ee1eu; return 0; }
r[2]=0x00000010u;
goto P_0c09ee20;
P_0c09ee20: /* original 2fc6, guest PC 0x0c09ee20 */
if(!s->budget--) { s->failed_pc=0x0c09ee20u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ee22;
P_0c09ee22: /* original 6c53, guest PC 0x0c09ee22 */
if(!s->budget--) { s->failed_pc=0x0c09ee22u; return 0; }
r[12]=r[5];
goto P_0c09ee24;
P_0c09ee24: /* original 2fb6, guest PC 0x0c09ee24 */
if(!s->budget--) { s->failed_pc=0x0c09ee24u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ee26;
P_0c09ee26: /* original 4f22, guest PC 0x0c09ee26 */
if(!s->budget--) { s->failed_pc=0x0c09ee26u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09ee28;
P_0c09ee28: /* original 9380, guest PC 0x0c09ee28 */
if(!s->budget--) { s->failed_pc=0x0c09ee28u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee2a;
P_0c09ee2a: /* original 33ec, guest PC 0x0c09ee2a */
if(!s->budget--) { s->failed_pc=0x0c09ee2au; return 0; }
r[3]+=r[14];
goto P_0c09ee2c;
P_0c09ee2c: /* original 7ff0, guest PC 0x0c09ee2c */
if(!s->budget--) { s->failed_pc=0x0c09ee2cu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09ee2e;
P_0c09ee2e: /* original 2f32, guest PC 0x0c09ee2e */
if(!s->budget--) { s->failed_pc=0x0c09ee2eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09ee30;
P_0c09ee30: /* original 907d, guest PC 0x0c09ee30 */
if(!s->budget--) { s->failed_pc=0x0c09ee30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee32;
P_0c09ee32: /* original 937b, guest PC 0x0c09ee32 */
if(!s->budget--) { s->failed_pc=0x0c09ee32u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee34;
P_0c09ee34: /* original 0bec, guest PC 0x0c09ee34 */
if(!s->budget--) { s->failed_pc=0x0c09ee34u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ee36;
P_0c09ee36: /* original 33ec, guest PC 0x0c09ee36 */
if(!s->budget--) { s->failed_pc=0x0c09ee36u; return 0; }
r[3]+=r[14];
goto P_0c09ee38;
P_0c09ee38: /* original 6bbc, guest PC 0x0c09ee38 */
if(!s->budget--) { s->failed_pc=0x0c09ee38u; return 0; }
r[11]=r[11]&255u;
goto P_0c09ee3a;
P_0c09ee3a: /* original 6db3, guest PC 0x0c09ee3a */
if(!s->budget--) { s->failed_pc=0x0c09ee3au; return 0; }
r[13]=r[11];
goto P_0c09ee3c;
P_0c09ee3c: /* original 22d8, guest PC 0x0c09ee3c */
if(!s->budget--) { s->failed_pc=0x0c09ee3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09ee3e;
P_0c09ee3e: /* original 8f02, guest PC 0x0c09ee3e */
if(!s->budget--) { s->failed_pc=0x0c09ee3eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c09ee46; }
goto P_0c09ee42;
P_0c09ee40: /* original 2f32, guest PC 0x0c09ee40 */
if(!s->budget--) { s->failed_pc=0x0c09ee40u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09ee42;
P_0c09ee42: /* original a099, guest PC 0x0c09ee42 */
if(!s->budget--) { s->failed_pc=0x0c09ee42u; return 0; }
goto P_0c09ef78;
P_0c09ee44: /* original 0009, guest PC 0x0c09ee44 */
if(!s->budget--) { s->failed_pc=0x0c09ee44u; return 0; }
goto P_0c09ee46;
P_0c09ee46: /* original 9373, guest PC 0x0c09ee46 */
if(!s->budget--) { s->failed_pc=0x0c09ee46u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef30u,2);
goto P_0c09ee48;
P_0c09ee48: /* original 9071, guest PC 0x0c09ee48 */
if(!s->budget--) { s->failed_pc=0x0c09ee48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee4a;
P_0c09ee4a: /* original 2b39, guest PC 0x0c09ee4a */
if(!s->budget--) { s->failed_pc=0x0c09ee4au; return 0; }
r[11]&=r[3];
goto P_0c09ee4c;
P_0c09ee4c: /* original 0eb4, guest PC 0x0c09ee4c */
if(!s->budget--) { s->failed_pc=0x0c09ee4cu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09ee4e;
P_0c09ee4e: /* original 956d, guest PC 0x0c09ee4e */
if(!s->budget--) { s->failed_pc=0x0c09ee4eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee50;
P_0c09ee50: /* original d23b, guest PC 0x0c09ee50 */
if(!s->budget--) { s->failed_pc=0x0c09ee50u; return 0; }
r[2]=read(ram,0x0c09ef40u,4);
goto P_0c09ee52;
P_0c09ee52: /* original 35ec, guest PC 0x0c09ee52 */
if(!s->budget--) { s->failed_pc=0x0c09ee52u; return 0; }
r[5]+=r[14];
goto P_0c09ee54;
P_0c09ee54: /* original 420b, guest PC 0x0c09ee54 */
if(!s->budget--) { s->failed_pc=0x0c09ee54u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ee58u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ee58u) { target=s->pc; goto dispatch; }
goto P_0c09ee58;
P_0c09ee56: /* original 64e3, guest PC 0x0c09ee56 */
if(!s->budget--) { s->failed_pc=0x0c09ee56u; return 0; }
r[4]=r[14];
goto P_0c09ee58;
P_0c09ee58: /* original d33a, guest PC 0x0c09ee58 */
if(!s->budget--) { s->failed_pc=0x0c09ee58u; return 0; }
r[3]=read(ram,0x0c09ef44u,4);
goto P_0c09ee5a;
P_0c09ee5a: /* original 65f3, guest PC 0x0c09ee5a */
if(!s->budget--) { s->failed_pc=0x0c09ee5au; return 0; }
r[5]=r[15];
goto P_0c09ee5c;
P_0c09ee5c: /* original 66c3, guest PC 0x0c09ee5c */
if(!s->budget--) { s->failed_pc=0x0c09ee5cu; return 0; }
r[6]=r[12];
goto P_0c09ee5e;
P_0c09ee5e: /* original 430b, guest PC 0x0c09ee5e */
if(!s->budget--) { s->failed_pc=0x0c09ee5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09ee62u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ee62u) { target=s->pc; goto dispatch; }
goto P_0c09ee62;
P_0c09ee60: /* original 64e3, guest PC 0x0c09ee60 */
if(!s->budget--) { s->failed_pc=0x0c09ee60u; return 0; }
r[4]=r[14];
goto P_0c09ee62;
P_0c09ee62: /* original d239, guest PC 0x0c09ee62 */
if(!s->budget--) { s->failed_pc=0x0c09ee62u; return 0; }
r[2]=read(ram,0x0c09ef48u,4);
goto P_0c09ee64;
P_0c09ee64: /* original 420b, guest PC 0x0c09ee64 */
if(!s->budget--) { s->failed_pc=0x0c09ee64u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ee68u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ee68u) { target=s->pc; goto dispatch; }
goto P_0c09ee68;
P_0c09ee66: /* original 64e3, guest PC 0x0c09ee66 */
if(!s->budget--) { s->failed_pc=0x0c09ee66u; return 0; }
r[4]=r[14];
goto P_0c09ee68;
P_0c09ee68: /* original 62e2, guest PC 0x0c09ee68 */
if(!s->budget--) { s->failed_pc=0x0c09ee68u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09ee6a;
P_0c09ee6a: /* original d338, guest PC 0x0c09ee6a */
if(!s->budget--) { s->failed_pc=0x0c09ee6au; return 0; }
r[3]=read(ram,0x0c09ef4cu,4);
goto P_0c09ee6c;
P_0c09ee6c: /* original 2238, guest PC 0x0c09ee6c */
if(!s->budget--) { s->failed_pc=0x0c09ee6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09ee6e;
P_0c09ee6e: /* original 8909, guest PC 0x0c09ee6e */
if(!s->budget--) { s->failed_pc=0x0c09ee6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ee84; }
goto P_0c09ee70;
P_0c09ee70: /* original 905d, guest PC 0x0c09ee70 */
if(!s->budget--) { s->failed_pc=0x0c09ee70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee72;
P_0c09ee72: /* original 6db3, guest PC 0x0c09ee72 */
if(!s->budget--) { s->failed_pc=0x0c09ee72u; return 0; }
r[13]=r[11];
goto P_0c09ee74;
P_0c09ee74: /* original 935d, guest PC 0x0c09ee74 */
if(!s->budget--) { s->failed_pc=0x0c09ee74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef32u,2);
goto P_0c09ee76;
P_0c09ee76: /* original 02ec, guest PC 0x0c09ee76 */
if(!s->budget--) { s->failed_pc=0x0c09ee76u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ee78;
P_0c09ee78: /* original 223b, guest PC 0x0c09ee78 */
if(!s->budget--) { s->failed_pc=0x0c09ee78u; return 0; }
r[2]|=r[3];
goto P_0c09ee7a;
P_0c09ee7a: /* original 0e24, guest PC 0x0c09ee7a */
if(!s->budget--) { s->failed_pc=0x0c09ee7au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09ee7c;
P_0c09ee7c: /* original 9456, guest PC 0x0c09ee7c */
if(!s->budget--) { s->failed_pc=0x0c09ee7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee7e;
P_0c09ee7e: /* original d134, guest PC 0x0c09ee7e */
if(!s->budget--) { s->failed_pc=0x0c09ee7eu; return 0; }
r[1]=read(ram,0x0c09ef50u,4);
goto P_0c09ee80;
P_0c09ee80: /* original 410b, guest PC 0x0c09ee80 */
if(!s->budget--) { s->failed_pc=0x0c09ee80u; return 0; }
target=r[1];
r[16]=code_base|0x0c09ee84u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ee84u) { target=s->pc; goto dispatch; }
goto P_0c09ee84;
P_0c09ee82: /* original 34ec, guest PC 0x0c09ee82 */
if(!s->budget--) { s->failed_pc=0x0c09ee82u; return 0; }
r[4]+=r[14];
goto P_0c09ee84;
P_0c09ee84: /* original 9053, guest PC 0x0c09ee84 */
if(!s->budget--) { s->failed_pc=0x0c09ee84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee86;
P_0c09ee86: /* original 00ec, guest PC 0x0c09ee86 */
if(!s->budget--) { s->failed_pc=0x0c09ee86u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ee88;
P_0c09ee88: /* original 600c, guest PC 0x0c09ee88 */
if(!s->budget--) { s->failed_pc=0x0c09ee88u; return 0; }
r[0]=r[0]&255u;
goto P_0c09ee8a;
P_0c09ee8a: /* original c820, guest PC 0x0c09ee8a */
if(!s->budget--) { s->failed_pc=0x0c09ee8au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c09ee8c;
P_0c09ee8c: /* original 891f, guest PC 0x0c09ee8c */
if(!s->budget--) { s->failed_pc=0x0c09ee8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09eece; }
goto P_0c09ee8e;
P_0c09ee8e: /* original 9051, guest PC 0x0c09ee8e */
if(!s->budget--) { s->failed_pc=0x0c09ee8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef34u,2);
goto P_0c09ee90;
P_0c09ee90: /* original 04ed, guest PC 0x0c09ee90 */
if(!s->budget--) { s->failed_pc=0x0c09ee90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ee92;
P_0c09ee92: /* original e008, guest PC 0x0c09ee92 */
if(!s->budget--) { s->failed_pc=0x0c09ee92u; return 0; }
r[0]=0x00000008u;
goto P_0c09ee94;
P_0c09ee94: /* original 6b4b, guest PC 0x0c09ee94 */
if(!s->budget--) { s->failed_pc=0x0c09ee94u; return 0; }
r[11]=0u-r[4];
goto P_0c09ee96;
P_0c09ee96: /* original 4b5a, guest PC 0x0c09ee96 */
if(!s->budget--) { s->failed_pc=0x0c09ee96u; return 0; }
r[53]=r[11];
goto P_0c09ee98;
P_0c09ee98: /* original 64bf, guest PC 0x0c09ee98 */
if(!s->budget--) { s->failed_pc=0x0c09ee98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c09ee9a;
P_0c09ee9a: /* original f32d, guest PC 0x0c09ee9a */
if(!s->budget--) { s->failed_pc=0x0c09ee9au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09ee9c;
P_0c09ee9c: /* original ff37, guest PC 0x0c09ee9c */
if(!s->budget--) { s->failed_pc=0x0c09ee9cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ee9e;
P_0c09ee9e: /* original d32d, guest PC 0x0c09ee9e */
if(!s->budget--) { s->failed_pc=0x0c09ee9eu; return 0; }
r[3]=read(ram,0x0c09ef54u,4);
goto P_0c09eea0;
P_0c09eea0: /* original 430b, guest PC 0x0c09eea0 */
if(!s->budget--) { s->failed_pc=0x0c09eea0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09eea4u;
write(ram,r[15]+4,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eea4u) { target=s->pc; goto dispatch; }
goto P_0c09eea4;
P_0c09eea2: /* original 1f41, guest PC 0x0c09eea2 */
if(!s->budget--) { s->failed_pc=0x0c09eea2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c09eea4;
P_0c09eea4: /* original e00c, guest PC 0x0c09eea4 */
if(!s->budget--) { s->failed_pc=0x0c09eea4u; return 0; }
r[0]=0x0000000cu;
goto P_0c09eea6;
P_0c09eea6: /* original ff07, guest PC 0x0c09eea6 */
if(!s->budget--) { s->failed_pc=0x0c09eea6u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c09eea8;
P_0c09eea8: /* original d32b, guest PC 0x0c09eea8 */
if(!s->budget--) { s->failed_pc=0x0c09eea8u; return 0; }
r[3]=read(ram,0x0c09ef58u,4);
goto P_0c09eeaa;
P_0c09eeaa: /* original 430b, guest PC 0x0c09eeaa */
if(!s->budget--) { s->failed_pc=0x0c09eeaau; return 0; }
target=r[3];
r[16]=code_base|0x0c09eeaeu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eeaeu) { target=s->pc; goto dispatch; }
goto P_0c09eeae;
P_0c09eeac: /* original 54f1, guest PC 0x0c09eeac */
if(!s->budget--) { s->failed_pc=0x0c09eeacu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c09eeae;
P_0c09eeae: /* original e00c, guest PC 0x0c09eeae */
if(!s->budget--) { s->failed_pc=0x0c09eeaeu; return 0; }
r[0]=0x0000000cu;
goto P_0c09eeb0;
P_0c09eeb0: /* original f39d, guest PC 0x0c09eeb0 */
if(!s->budget--) { s->failed_pc=0x0c09eeb0u; return 0; }
fr[3]=0x3f800000u;
goto P_0c09eeb2;
P_0c09eeb2: /* original f2f6, guest PC 0x0c09eeb2 */
if(!s->budget--) { s->failed_pc=0x0c09eeb2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09eeb4;
P_0c09eeb4: /* original e008, guest PC 0x0c09eeb4 */
if(!s->budget--) { s->failed_pc=0x0c09eeb4u; return 0; }
r[0]=0x00000008u;
goto P_0c09eeb6;
P_0c09eeb6: /* original f6f6, guest PC 0x0c09eeb6 */
if(!s->budget--) { s->failed_pc=0x0c09eeb6u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09eeb8;
P_0c09eeb8: /* original f232, guest PC 0x0c09eeb8 */
if(!s->budget--) { s->failed_pc=0x0c09eeb8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c09eeba;
P_0c09eeba: /* original d328, guest PC 0x0c09eeba */
if(!s->budget--) { s->failed_pc=0x0c09eebau; return 0; }
r[3]=read(ram,0x0c09ef5cu,4);
goto P_0c09eebc;
P_0c09eebc: /* original 943b, guest PC 0x0c09eebc */
if(!s->budget--) { s->failed_pc=0x0c09eebcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09eebe;
P_0c09eebe: /* original f50c, guest PC 0x0c09eebe */
if(!s->budget--) { s->failed_pc=0x0c09eebeu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c09eec0;
P_0c09eec0: /* original f42c, guest PC 0x0c09eec0 */
if(!s->budget--) { s->failed_pc=0x0c09eec0u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c09eec2;
P_0c09eec2: /* original f44d, guest PC 0x0c09eec2 */
if(!s->budget--) { s->failed_pc=0x0c09eec2u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09eec4;
P_0c09eec4: /* original 430b, guest PC 0x0c09eec4 */
if(!s->budget--) { s->failed_pc=0x0c09eec4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09eec8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eec8u) { target=s->pc; goto dispatch; }
goto P_0c09eec8;
P_0c09eec6: /* original 34ec, guest PC 0x0c09eec6 */
if(!s->budget--) { s->failed_pc=0x0c09eec6u; return 0; }
r[4]+=r[14];
goto P_0c09eec8;
P_0c09eec8: /* original d225, guest PC 0x0c09eec8 */
if(!s->budget--) { s->failed_pc=0x0c09eec8u; return 0; }
r[2]=read(ram,0x0c09ef60u,4);
goto P_0c09eeca;
P_0c09eeca: /* original 420b, guest PC 0x0c09eeca */
if(!s->budget--) { s->failed_pc=0x0c09eecau; return 0; }
target=r[2];
r[16]=code_base|0x0c09eeceu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eeceu) { target=s->pc; goto dispatch; }
goto P_0c09eece;
P_0c09eecc: /* original 64e3, guest PC 0x0c09eecc */
if(!s->budget--) { s->failed_pc=0x0c09eeccu; return 0; }
r[4]=r[14];
goto P_0c09eece;
P_0c09eece: /* original e048, guest PC 0x0c09eece */
if(!s->budget--) { s->failed_pc=0x0c09eeceu; return 0; }
r[0]=0x00000048u;
goto P_0c09eed0;
P_0c09eed0: /* original 9332, guest PC 0x0c09eed0 */
if(!s->budget--) { s->failed_pc=0x0c09eed0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef38u,2);
goto P_0c09eed2;
P_0c09eed2: /* original 02ee, guest PC 0x0c09eed2 */
if(!s->budget--) { s->failed_pc=0x0c09eed2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09eed4;
P_0c09eed4: /* original 2238, guest PC 0x0c09eed4 */
if(!s->budget--) { s->failed_pc=0x0c09eed4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09eed6;
P_0c09eed6: /* original 8908, guest PC 0x0c09eed6 */
if(!s->budget--) { s->failed_pc=0x0c09eed6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09eeea; }
goto P_0c09eed8;
P_0c09eed8: /* original c722, guest PC 0x0c09eed8 */
if(!s->budget--) { s->failed_pc=0x0c09eed8u; return 0; }
r[0]=code_base|0x0009ef64u;
goto P_0c09eeda;
P_0c09eeda: /* original 942c, guest PC 0x0c09eeda */
if(!s->budget--) { s->failed_pc=0x0c09eedau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09eedc;
P_0c09eedc: /* original f508, guest PC 0x0c09eedc */
if(!s->budget--) { s->failed_pc=0x0c09eedcu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09eede;
P_0c09eede: /* original c722, guest PC 0x0c09eede */
if(!s->budget--) { s->failed_pc=0x0c09eedeu; return 0; }
r[0]=code_base|0x0009ef68u;
goto P_0c09eee0;
P_0c09eee0: /* original d31e, guest PC 0x0c09eee0 */
if(!s->budget--) { s->failed_pc=0x0c09eee0u; return 0; }
r[3]=read(ram,0x0c09ef5cu,4);
goto P_0c09eee2;
P_0c09eee2: /* original f608, guest PC 0x0c09eee2 */
if(!s->budget--) { s->failed_pc=0x0c09eee2u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c09eee4;
P_0c09eee4: /* original f48d, guest PC 0x0c09eee4 */
if(!s->budget--) { s->failed_pc=0x0c09eee4u; return 0; }
fr[4]=0;
goto P_0c09eee6;
P_0c09eee6: /* original 430b, guest PC 0x0c09eee6 */
if(!s->budget--) { s->failed_pc=0x0c09eee6u; return 0; }
target=r[3];
r[16]=code_base|0x0c09eeeau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eeeau) { target=s->pc; goto dispatch; }
goto P_0c09eeea;
P_0c09eee8: /* original 34ec, guest PC 0x0c09eee8 */
if(!s->budget--) { s->failed_pc=0x0c09eee8u; return 0; }
r[4]+=r[14];
goto P_0c09eeea;
P_0c09eeea: /* original 9026, guest PC 0x0c09eeea */
if(!s->budget--) { s->failed_pc=0x0c09eeeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef3au,2);
goto P_0c09eeec;
P_0c09eeec: /* original d317, guest PC 0x0c09eeec */
if(!s->budget--) { s->failed_pc=0x0c09eeecu; return 0; }
r[3]=read(ram,0x0c09ef4cu,4);
goto P_0c09eeee;
P_0c09eeee: /* original 02ee, guest PC 0x0c09eeee */
if(!s->budget--) { s->failed_pc=0x0c09eeeeu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09eef0;
P_0c09eef0: /* original 2238, guest PC 0x0c09eef0 */
if(!s->budget--) { s->failed_pc=0x0c09eef0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09eef2;
P_0c09eef2: /* original 8908, guest PC 0x0c09eef2 */
if(!s->budget--) { s->failed_pc=0x0c09eef2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ef06; }
goto P_0c09eef4;
P_0c09eef4: /* original 9022, guest PC 0x0c09eef4 */
if(!s->budget--) { s->failed_pc=0x0c09eef4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef3cu,2);
goto P_0c09eef6;
P_0c09eef6: /* original e340, guest PC 0x0c09eef6 */
if(!s->budget--) { s->failed_pc=0x0c09eef6u; return 0; }
r[3]=0x00000040u;
goto P_0c09eef8;
P_0c09eef8: /* original 01ed, guest PC 0x0c09eef8 */
if(!s->budget--) { s->failed_pc=0x0c09eef8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09eefa;
P_0c09eefa: /* original 901b, guest PC 0x0c09eefa */
if(!s->budget--) { s->failed_pc=0x0c09eefau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef34u,2);
goto P_0c09eefc;
P_0c09eefc: /* original 0e15, guest PC 0x0c09eefc */
if(!s->budget--) { s->failed_pc=0x0c09eefcu; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c09eefe;
P_0c09eefe: /* original 70df, guest PC 0x0c09eefe */
if(!s->budget--) { s->failed_pc=0x0c09eefeu; return 0; }
r[0]+=0xffffffdfu;
goto P_0c09ef00;
P_0c09ef00: /* original 02ec, guest PC 0x0c09ef00 */
if(!s->budget--) { s->failed_pc=0x0c09ef00u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ef02;
P_0c09ef02: /* original 223b, guest PC 0x0c09ef02 */
if(!s->budget--) { s->failed_pc=0x0c09ef02u; return 0; }
r[2]|=r[3];
goto P_0c09ef04;
P_0c09ef04: /* original 0e24, guest PC 0x0c09ef04 */
if(!s->budget--) { s->failed_pc=0x0c09ef04u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09ef06;
P_0c09ef06: /* original 9516, guest PC 0x0c09ef06 */
if(!s->budget--) { s->failed_pc=0x0c09ef06u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09ef08;
P_0c09ef08: /* original 9410, guest PC 0x0c09ef08 */
if(!s->budget--) { s->failed_pc=0x0c09ef08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ef0a;
P_0c09ef0a: /* original d318, guest PC 0x0c09ef0a */
if(!s->budget--) { s->failed_pc=0x0c09ef0au; return 0; }
r[3]=read(ram,0x0c09ef6cu,4);
goto P_0c09ef0c;
P_0c09ef0c: /* original 35ec, guest PC 0x0c09ef0c */
if(!s->budget--) { s->failed_pc=0x0c09ef0cu; return 0; }
r[5]+=r[14];
goto P_0c09ef0e;
P_0c09ef0e: /* original 430b, guest PC 0x0c09ef0e */
if(!s->budget--) { s->failed_pc=0x0c09ef0eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09ef12u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef12u) { target=s->pc; goto dispatch; }
goto P_0c09ef12;
P_0c09ef10: /* original 34ec, guest PC 0x0c09ef10 */
if(!s->budget--) { s->failed_pc=0x0c09ef10u; return 0; }
r[4]+=r[14];
goto P_0c09ef12;
P_0c09ef12: /* original 950b, guest PC 0x0c09ef12 */
if(!s->budget--) { s->failed_pc=0x0c09ef12u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ef14;
P_0c09ef14: /* original 960f, guest PC 0x0c09ef14 */
if(!s->budget--) { s->failed_pc=0x0c09ef14u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09ef16;
P_0c09ef16: /* original d216, guest PC 0x0c09ef16 */
if(!s->budget--) { s->failed_pc=0x0c09ef16u; return 0; }
r[2]=read(ram,0x0c09ef70u,4);
goto P_0c09ef18;
P_0c09ef18: /* original 35ec, guest PC 0x0c09ef18 */
if(!s->budget--) { s->failed_pc=0x0c09ef18u; return 0; }
r[5]+=r[14];
goto P_0c09ef1a;
P_0c09ef1a: /* original 36ec, guest PC 0x0c09ef1a */
if(!s->budget--) { s->failed_pc=0x0c09ef1au; return 0; }
r[6]+=r[14];
goto P_0c09ef1c;
P_0c09ef1c: /* original 420b, guest PC 0x0c09ef1c */
if(!s->budget--) { s->failed_pc=0x0c09ef1cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09ef20u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef20u) { target=s->pc; goto dispatch; }
goto P_0c09ef20;
P_0c09ef1e: /* original 64e3, guest PC 0x0c09ef1e */
if(!s->budget--) { s->failed_pc=0x0c09ef1eu; return 0; }
r[4]=r[14];
goto P_0c09ef20;
P_0c09ef20: /* original d314, guest PC 0x0c09ef20 */
if(!s->budget--) { s->failed_pc=0x0c09ef20u; return 0; }
r[3]=read(ram,0x0c09ef74u,4);
goto P_0c09ef22;
P_0c09ef22: /* original 430b, guest PC 0x0c09ef22 */
if(!s->budget--) { s->failed_pc=0x0c09ef22u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ef26u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef26u) { target=s->pc; goto dispatch; }
goto P_0c09ef26;
P_0c09ef24: /* original 64e3, guest PC 0x0c09ef24 */
if(!s->budget--) { s->failed_pc=0x0c09ef24u; return 0; }
r[4]=r[14];
goto P_0c09ef26;
P_0c09ef26: /* original a03a, guest PC 0x0c09ef26 */
if(!s->budget--) { s->failed_pc=0x0c09ef26u; return 0; }
goto P_0c09ef9e;
P_0c09ef28: /* original 0009, guest PC 0x0c09ef28 */
if(!s->budget--) { s->failed_pc=0x0c09ef28u; return 0; }
if(!vf3_matrix_family(0x0c09ef2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ef2au; return 0; } return 1;
P_0c09ef78: /* original 9066, guest PC 0x0c09ef78 */
if(!s->budget--) { s->failed_pc=0x0c09ef78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f048u,2);
goto P_0c09ef7a;
P_0c09ef7a: /* original 65f3, guest PC 0x0c09ef7a */
if(!s->budget--) { s->failed_pc=0x0c09ef7au; return 0; }
r[5]=r[15];
goto P_0c09ef7c;
P_0c09ef7c: /* original 66c3, guest PC 0x0c09ef7c */
if(!s->budget--) { s->failed_pc=0x0c09ef7cu; return 0; }
r[6]=r[12];
goto P_0c09ef7e;
P_0c09ef7e: /* original 03ed, guest PC 0x0c09ef7e */
if(!s->budget--) { s->failed_pc=0x0c09ef7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ef80;
P_0c09ef80: /* original 9063, guest PC 0x0c09ef80 */
if(!s->budget--) { s->failed_pc=0x0c09ef80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f04au,2);
goto P_0c09ef82;
P_0c09ef82: /* original 0e35, guest PC 0x0c09ef82 */
if(!s->budget--) { s->failed_pc=0x0c09ef82u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c09ef84;
P_0c09ef84: /* original d334, guest PC 0x0c09ef84 */
if(!s->budget--) { s->failed_pc=0x0c09ef84u; return 0; }
r[3]=read(ram,0x0c09f058u,4);
goto P_0c09ef86;
P_0c09ef86: /* original 430b, guest PC 0x0c09ef86 */
if(!s->budget--) { s->failed_pc=0x0c09ef86u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ef8au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef8au) { target=s->pc; goto dispatch; }
goto P_0c09ef8a;
P_0c09ef88: /* original 64e3, guest PC 0x0c09ef88 */
if(!s->budget--) { s->failed_pc=0x0c09ef88u; return 0; }
r[4]=r[14];
goto P_0c09ef8a;
P_0c09ef8a: /* original d234, guest PC 0x0c09ef8a */
if(!s->budget--) { s->failed_pc=0x0c09ef8au; return 0; }
r[2]=read(ram,0x0c09f05cu,4);
goto P_0c09ef8c;
P_0c09ef8c: /* original 420b, guest PC 0x0c09ef8c */
if(!s->budget--) { s->failed_pc=0x0c09ef8cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09ef90u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef90u) { target=s->pc; goto dispatch; }
goto P_0c09ef90;
P_0c09ef8e: /* original 64e3, guest PC 0x0c09ef8e */
if(!s->budget--) { s->failed_pc=0x0c09ef8eu; return 0; }
r[4]=r[14];
goto P_0c09ef90;
P_0c09ef90: /* original 935c, guest PC 0x0c09ef90 */
if(!s->budget--) { s->failed_pc=0x0c09ef90u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f04cu,2);
goto P_0c09ef92;
P_0c09ef92: /* original 23d8, guest PC 0x0c09ef92 */
if(!s->budget--) { s->failed_pc=0x0c09ef92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09ef94;
P_0c09ef94: /* original 8903, guest PC 0x0c09ef94 */
if(!s->budget--) { s->failed_pc=0x0c09ef94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ef9e; }
goto P_0c09ef96;
P_0c09ef96: /* original d332, guest PC 0x0c09ef96 */
if(!s->budget--) { s->failed_pc=0x0c09ef96u; return 0; }
r[3]=read(ram,0x0c09f060u,4);
goto P_0c09ef98;
P_0c09ef98: /* original 9459, guest PC 0x0c09ef98 */
if(!s->budget--) { s->failed_pc=0x0c09ef98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f04eu,2);
goto P_0c09ef9a;
P_0c09ef9a: /* original 430b, guest PC 0x0c09ef9a */
if(!s->budget--) { s->failed_pc=0x0c09ef9au; return 0; }
target=r[3];
r[16]=code_base|0x0c09ef9eu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef9eu) { target=s->pc; goto dispatch; }
goto P_0c09ef9e;
P_0c09ef9c: /* original 34ec, guest PC 0x0c09ef9c */
if(!s->budget--) { s->failed_pc=0x0c09ef9cu; return 0; }
r[4]+=r[14];
goto P_0c09ef9e;
P_0c09ef9e: /* original e201, guest PC 0x0c09ef9e */
if(!s->budget--) { s->failed_pc=0x0c09ef9eu; return 0; }
r[2]=0x00000001u;
goto P_0c09efa0;
P_0c09efa0: /* original 22d8, guest PC 0x0c09efa0 */
if(!s->budget--) { s->failed_pc=0x0c09efa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09efa2;
P_0c09efa2: /* original 8902, guest PC 0x0c09efa2 */
if(!s->budget--) { s->failed_pc=0x0c09efa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09efaa; }
goto P_0c09efa4;
P_0c09efa4: /* original d22f, guest PC 0x0c09efa4 */
if(!s->budget--) { s->failed_pc=0x0c09efa4u; return 0; }
r[2]=read(ram,0x0c09f064u,4);
goto P_0c09efa6;
P_0c09efa6: /* original 420b, guest PC 0x0c09efa6 */
if(!s->budget--) { s->failed_pc=0x0c09efa6u; return 0; }
target=r[2];
r[16]=code_base|0x0c09efaau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09efaau) { target=s->pc; goto dispatch; }
goto P_0c09efaa;
P_0c09efa8: /* original 64e3, guest PC 0x0c09efa8 */
if(!s->budget--) { s->failed_pc=0x0c09efa8u; return 0; }
r[4]=r[14];
goto P_0c09efaa;
P_0c09efaa: /* original e302, guest PC 0x0c09efaa */
if(!s->budget--) { s->failed_pc=0x0c09efaau; return 0; }
r[3]=0x00000002u;
goto P_0c09efac;
P_0c09efac: /* original 23d8, guest PC 0x0c09efac */
if(!s->budget--) { s->failed_pc=0x0c09efacu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09efae;
P_0c09efae: /* original 8904, guest PC 0x0c09efae */
if(!s->budget--) { s->failed_pc=0x0c09efaeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09efba; }
goto P_0c09efb0;
P_0c09efb0: /* original d32d, guest PC 0x0c09efb0 */
if(!s->budget--) { s->failed_pc=0x0c09efb0u; return 0; }
r[3]=read(ram,0x0c09f068u,4);
goto P_0c09efb2;
P_0c09efb2: /* original 65c3, guest PC 0x0c09efb2 */
if(!s->budget--) { s->failed_pc=0x0c09efb2u; return 0; }
r[5]=r[12];
goto P_0c09efb4;
P_0c09efb4: /* original 66d3, guest PC 0x0c09efb4 */
if(!s->budget--) { s->failed_pc=0x0c09efb4u; return 0; }
r[6]=r[13];
goto P_0c09efb6;
P_0c09efb6: /* original 430b, guest PC 0x0c09efb6 */
if(!s->budget--) { s->failed_pc=0x0c09efb6u; return 0; }
target=r[3];
r[16]=code_base|0x0c09efbau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09efbau) { target=s->pc; goto dispatch; }
goto P_0c09efba;
P_0c09efb8: /* original 64e3, guest PC 0x0c09efb8 */
if(!s->budget--) { s->failed_pc=0x0c09efb8u; return 0; }
r[4]=r[14];
goto P_0c09efba;
P_0c09efba: /* original d22c, guest PC 0x0c09efba */
if(!s->budget--) { s->failed_pc=0x0c09efbau; return 0; }
r[2]=read(ram,0x0c09f06cu,4);
goto P_0c09efbc;
P_0c09efbc: /* original 420b, guest PC 0x0c09efbc */
if(!s->budget--) { s->failed_pc=0x0c09efbcu; return 0; }
target=r[2];
r[16]=code_base|0x0c09efc0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09efc0u) { target=s->pc; goto dispatch; }
goto P_0c09efc0;
P_0c09efbe: /* original 64e3, guest PC 0x0c09efbe */
if(!s->budget--) { s->failed_pc=0x0c09efbeu; return 0; }
r[4]=r[14];
goto P_0c09efc0;
P_0c09efc0: /* original 7f10, guest PC 0x0c09efc0 */
if(!s->budget--) { s->failed_pc=0x0c09efc0u; return 0; }
r[15]+=0x00000010u;
goto P_0c09efc2;
P_0c09efc2: /* original 4f26, guest PC 0x0c09efc2 */
if(!s->budget--) { s->failed_pc=0x0c09efc2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09efc4;
P_0c09efc4: /* original 6bf6, guest PC 0x0c09efc4 */
if(!s->budget--) { s->failed_pc=0x0c09efc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09efc6;
P_0c09efc6: /* original 6cf6, guest PC 0x0c09efc6 */
if(!s->budget--) { s->failed_pc=0x0c09efc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09efc8;
P_0c09efc8: /* original 6df6, guest PC 0x0c09efc8 */
if(!s->budget--) { s->failed_pc=0x0c09efc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09efca;
P_0c09efca: /* original 000b, guest PC 0x0c09efca */
if(!s->budget--) { s->failed_pc=0x0c09efcau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09efcc: /* original 6ef6, guest PC 0x0c09efcc */
if(!s->budget--) { s->failed_pc=0x0c09efccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09efce;
P_0c09efce: /* original 933f, guest PC 0x0c09efce */
if(!s->budget--) { s->failed_pc=0x0c09efceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f050u,2);
goto P_0c09efd0;
P_0c09efd0: /* original e042, guest PC 0x0c09efd0 */
if(!s->budget--) { s->failed_pc=0x0c09efd0u; return 0; }
r[0]=0x00000042u;
goto P_0c09efd2;
P_0c09efd2: /* original 0435, guest PC 0x0c09efd2 */
if(!s->budget--) { s->failed_pc=0x0c09efd2u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efd4;
P_0c09efd4: /* original a000, guest PC 0x0c09efd4 */
if(!s->budget--) { s->failed_pc=0x0c09efd4u; return 0; }
goto P_0c09efd8;
P_0c09efd6: /* original 0009, guest PC 0x0c09efd6 */
if(!s->budget--) { s->failed_pc=0x0c09efd6u; return 0; }
goto P_0c09efd8;
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
P_0c09f01a: /* original 901c, guest PC 0x0c09f01a */
if(!s->budget--) { s->failed_pc=0x0c09f01au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f056u,2);
goto P_0c09f01c;
P_0c09f01c: /* original e310, guest PC 0x0c09f01c */
if(!s->budget--) { s->failed_pc=0x0c09f01cu; return 0; }
r[3]=0x00000010u;
goto P_0c09f01e;
P_0c09f01e: /* original e101, guest PC 0x0c09f01e */
if(!s->budget--) { s->failed_pc=0x0c09f01eu; return 0; }
r[1]=0x00000001u;
goto P_0c09f020;
P_0c09f020: /* original 024c, guest PC 0x0c09f020 */
if(!s->budget--) { s->failed_pc=0x0c09f020u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f022;
P_0c09f022: /* original 223b, guest PC 0x0c09f022 */
if(!s->budget--) { s->failed_pc=0x0c09f022u; return 0; }
r[2]|=r[3];
goto P_0c09f024;
P_0c09f024: /* original 0424, guest PC 0x0c09f024 */
if(!s->budget--) { s->failed_pc=0x0c09f024u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09f026;
P_0c09f026: /* original e03e, guest PC 0x0c09f026 */
if(!s->budget--) { s->failed_pc=0x0c09f026u; return 0; }
r[0]=0x0000003eu;
goto P_0c09f028;
P_0c09f028: /* original 0415, guest PC 0x0c09f028 */
if(!s->budget--) { s->failed_pc=0x0c09f028u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c09f02a;
P_0c09f02a: /* original e040, guest PC 0x0c09f02a */
if(!s->budget--) { s->failed_pc=0x0c09f02au; return 0; }
r[0]=0x00000040u;
goto P_0c09f02c;
P_0c09f02c: /* original e200, guest PC 0x0c09f02c */
if(!s->budget--) { s->failed_pc=0x0c09f02cu; return 0; }
r[2]=0x00000000u;
goto P_0c09f02e;
P_0c09f02e: /* original 0425, guest PC 0x0c09f02e */
if(!s->budget--) { s->failed_pc=0x0c09f02eu; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c09f030;
P_0c09f030: /* original 950e, guest PC 0x0c09f030 */
if(!s->budget--) { s->failed_pc=0x0c09f030u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f050u,2);
goto P_0c09f032;
P_0c09f032: /* original aef1, guest PC 0x0c09f032 */
if(!s->budget--) { s->failed_pc=0x0c09f032u; return 0; }
goto P_0c09ee18;
P_0c09f034: /* original 0009, guest PC 0x0c09f034 */
if(!s->budget--) { s->failed_pc=0x0c09f034u; return 0; }
if(!vf3_matrix_family(0x0c09f036u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f036u; return 0; } return 1;
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
P_0c09f432: /* original 2fe6, guest PC 0x0c09f432 */
if(!s->budget--) { s->failed_pc=0x0c09f432u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f434;
P_0c09f434: /* original c72d, guest PC 0x0c09f434 */
if(!s->budget--) { s->failed_pc=0x0c09f434u; return 0; }
r[0]=code_base|0x0009f4ecu;
goto P_0c09f436;
P_0c09f436: /* original fffb, guest PC 0x0c09f436 */
if(!s->budget--) { s->failed_pc=0x0c09f436u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09f438;
P_0c09f438: /* original 6e43, guest PC 0x0c09f438 */
if(!s->budget--) { s->failed_pc=0x0c09f438u; return 0; }
r[14]=r[4];
goto P_0c09f43a;
P_0c09f43a: /* original ffeb, guest PC 0x0c09f43a */
if(!s->budget--) { s->failed_pc=0x0c09f43au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c09f43c;
P_0c09f43c: /* original ffdb, guest PC 0x0c09f43c */
if(!s->budget--) { s->failed_pc=0x0c09f43cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09f43e;
P_0c09f43e: /* original ffcb, guest PC 0x0c09f43e */
if(!s->budget--) { s->failed_pc=0x0c09f43eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c09f440;
P_0c09f440: /* original 4f22, guest PC 0x0c09f440 */
if(!s->budget--) { s->failed_pc=0x0c09f440u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f442;
P_0c09f442: /* original f308, guest PC 0x0c09f442 */
if(!s->budget--) { s->failed_pc=0x0c09f442u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09f444;
P_0c09f444: /* original c72a, guest PC 0x0c09f444 */
if(!s->budget--) { s->failed_pc=0x0c09f444u; return 0; }
r[0]=code_base|0x0009f4f0u;
goto P_0c09f446;
P_0c09f446: /* original 944e, guest PC 0x0c09f446 */
if(!s->budget--) { s->failed_pc=0x0c09f446u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f4e6u,2);
goto P_0c09f448;
P_0c09f448: /* original 7ff4, guest PC 0x0c09f448 */
if(!s->budget--) { s->failed_pc=0x0c09f448u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09f44a;
P_0c09f44a: /* original ff3a, guest PC 0x0c09f44a */
if(!s->budget--) { s->failed_pc=0x0c09f44au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09f44c;
P_0c09f44c: /* original 34ec, guest PC 0x0c09f44c */
if(!s->budget--) { s->failed_pc=0x0c09f44cu; return 0; }
r[4]+=r[14];
goto P_0c09f44e;
P_0c09f44e: /* original ff08, guest PC 0x0c09f44e */
if(!s->budget--) { s->failed_pc=0x0c09f44eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09f450;
P_0c09f450: /* original c728, guest PC 0x0c09f450 */
if(!s->budget--) { s->failed_pc=0x0c09f450u; return 0; }
r[0]=code_base|0x0009f4f4u;
goto P_0c09f452;
P_0c09f452: /* original f308, guest PC 0x0c09f452 */
if(!s->budget--) { s->failed_pc=0x0c09f452u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09f454;
P_0c09f454: /* original e004, guest PC 0x0c09f454 */
if(!s->budget--) { s->failed_pc=0x0c09f454u; return 0; }
r[0]=0x00000004u;
goto P_0c09f456;
P_0c09f456: /* original ff37, guest PC 0x0c09f456 */
if(!s->budget--) { s->failed_pc=0x0c09f456u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f458;
P_0c09f458: /* original c727, guest PC 0x0c09f458 */
if(!s->budget--) { s->failed_pc=0x0c09f458u; return 0; }
r[0]=code_base|0x0009f4f8u;
goto P_0c09f45a;
P_0c09f45a: /* original fc08, guest PC 0x0c09f45a */
if(!s->budget--) { s->failed_pc=0x0c09f45au; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c09f45c;
P_0c09f45c: /* original c727, guest PC 0x0c09f45c */
if(!s->budget--) { s->failed_pc=0x0c09f45cu; return 0; }
r[0]=code_base|0x0009f4fcu;
goto P_0c09f45e;
P_0c09f45e: /* original fe08, guest PC 0x0c09f45e */
if(!s->budget--) { s->failed_pc=0x0c09f45eu; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c09f460;
P_0c09f460: /* original f5f8, guest PC 0x0c09f460 */
if(!s->budget--) { s->failed_pc=0x0c09f460u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f462;
P_0c09f462: /* original fd8d, guest PC 0x0c09f462 */
if(!s->budget--) { s->failed_pc=0x0c09f462u; return 0; }
fr[13]=0;
goto P_0c09f464;
P_0c09f464: /* original f7cc, guest PC 0x0c09f464 */
if(!s->budget--) { s->failed_pc=0x0c09f464u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f466;
P_0c09f466: /* original f63c, guest PC 0x0c09f466 */
if(!s->budget--) { s->failed_pc=0x0c09f466u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c09f468;
P_0c09f468: /* original f9ec, guest PC 0x0c09f468 */
if(!s->budget--) { s->failed_pc=0x0c09f468u; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f46a;
P_0c09f46a: /* original f8dc, guest PC 0x0c09f46a */
if(!s->budget--) { s->failed_pc=0x0c09f46au; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f46c;
P_0c09f46c: /* original b0c4, guest PC 0x0c09f46c */
if(!s->budget--) { s->failed_pc=0x0c09f46cu; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f470u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f470u) { target=s->pc; goto dispatch; }
goto P_0c09f470;
P_0c09f46e: /* original f4fc, guest PC 0x0c09f46e */
if(!s->budget--) { s->failed_pc=0x0c09f46eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f470;
P_0c09f470: /* original 6403, guest PC 0x0c09f470 */
if(!s->budget--) { s->failed_pc=0x0c09f470u; return 0; }
r[4]=r[0];
goto P_0c09f472;
P_0c09f472: /* original e004, guest PC 0x0c09f472 */
if(!s->budget--) { s->failed_pc=0x0c09f472u; return 0; }
r[0]=0x00000004u;
goto P_0c09f474;
P_0c09f474: /* original f6f6, guest PC 0x0c09f474 */
if(!s->budget--) { s->failed_pc=0x0c09f474u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f476;
P_0c09f476: /* original f5f8, guest PC 0x0c09f476 */
if(!s->budget--) { s->failed_pc=0x0c09f476u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f478;
P_0c09f478: /* original f9ec, guest PC 0x0c09f478 */
if(!s->budget--) { s->failed_pc=0x0c09f478u; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f47a;
P_0c09f47a: /* original f8dc, guest PC 0x0c09f47a */
if(!s->budget--) { s->failed_pc=0x0c09f47au; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f47c;
P_0c09f47c: /* original f7cc, guest PC 0x0c09f47c */
if(!s->budget--) { s->failed_pc=0x0c09f47cu; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f47e;
P_0c09f47e: /* original b0bb, guest PC 0x0c09f47e */
if(!s->budget--) { s->failed_pc=0x0c09f47eu; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f482u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f482u) { target=s->pc; goto dispatch; }
goto P_0c09f482;
P_0c09f480: /* original f4fc, guest PC 0x0c09f480 */
if(!s->budget--) { s->failed_pc=0x0c09f480u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f482;
P_0c09f482: /* original 6403, guest PC 0x0c09f482 */
if(!s->budget--) { s->failed_pc=0x0c09f482u; return 0; }
r[4]=r[0];
goto P_0c09f484;
P_0c09f484: /* original e004, guest PC 0x0c09f484 */
if(!s->budget--) { s->failed_pc=0x0c09f484u; return 0; }
r[0]=0x00000004u;
goto P_0c09f486;
P_0c09f486: /* original f6f6, guest PC 0x0c09f486 */
if(!s->budget--) { s->failed_pc=0x0c09f486u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f488;
P_0c09f488: /* original 7454, guest PC 0x0c09f488 */
if(!s->budget--) { s->failed_pc=0x0c09f488u; return 0; }
r[4]+=0x00000054u;
goto P_0c09f48a;
P_0c09f48a: /* original f5f8, guest PC 0x0c09f48a */
if(!s->budget--) { s->failed_pc=0x0c09f48au; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f48c;
P_0c09f48c: /* original f7cc, guest PC 0x0c09f48c */
if(!s->budget--) { s->failed_pc=0x0c09f48cu; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f48e;
P_0c09f48e: /* original f9ec, guest PC 0x0c09f48e */
if(!s->budget--) { s->failed_pc=0x0c09f48eu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f490;
P_0c09f490: /* original f8dc, guest PC 0x0c09f490 */
if(!s->budget--) { s->failed_pc=0x0c09f490u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f492;
P_0c09f492: /* original b0b1, guest PC 0x0c09f492 */
if(!s->budget--) { s->failed_pc=0x0c09f492u; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f496u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f496u) { target=s->pc; goto dispatch; }
goto P_0c09f496;
P_0c09f494: /* original f4fc, guest PC 0x0c09f494 */
if(!s->budget--) { s->failed_pc=0x0c09f494u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f496;
P_0c09f496: /* original 6403, guest PC 0x0c09f496 */
if(!s->budget--) { s->failed_pc=0x0c09f496u; return 0; }
r[4]=r[0];
goto P_0c09f498;
P_0c09f498: /* original e004, guest PC 0x0c09f498 */
if(!s->budget--) { s->failed_pc=0x0c09f498u; return 0; }
r[0]=0x00000004u;
goto P_0c09f49a;
P_0c09f49a: /* original f6f6, guest PC 0x0c09f49a */
if(!s->budget--) { s->failed_pc=0x0c09f49au; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f49c;
P_0c09f49c: /* original f5f8, guest PC 0x0c09f49c */
if(!s->budget--) { s->failed_pc=0x0c09f49cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f49e;
P_0c09f49e: /* original f9ec, guest PC 0x0c09f49e */
if(!s->budget--) { s->failed_pc=0x0c09f49eu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f4a0;
P_0c09f4a0: /* original f8dc, guest PC 0x0c09f4a0 */
if(!s->budget--) { s->failed_pc=0x0c09f4a0u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f4a2;
P_0c09f4a2: /* original f7cc, guest PC 0x0c09f4a2 */
if(!s->budget--) { s->failed_pc=0x0c09f4a2u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f4a4;
P_0c09f4a4: /* original b0a8, guest PC 0x0c09f4a4 */
if(!s->budget--) { s->failed_pc=0x0c09f4a4u; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f4a8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4a8u) { target=s->pc; goto dispatch; }
goto P_0c09f4a8;
P_0c09f4a6: /* original f4fc, guest PC 0x0c09f4a6 */
if(!s->budget--) { s->failed_pc=0x0c09f4a6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f4a8;
P_0c09f4a8: /* original 921e, guest PC 0x0c09f4a8 */
if(!s->budget--) { s->failed_pc=0x0c09f4a8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f4e8u,2);
goto P_0c09f4aa;
P_0c09f4aa: /* original 6503, guest PC 0x0c09f4aa */
if(!s->budget--) { s->failed_pc=0x0c09f4aau; return 0; }
r[5]=r[0];
goto P_0c09f4ac;
P_0c09f4ac: /* original 32ec, guest PC 0x0c09f4ac */
if(!s->budget--) { s->failed_pc=0x0c09f4acu; return 0; }
r[2]+=r[14];
goto P_0c09f4ae;
P_0c09f4ae: /* original 6623, guest PC 0x0c09f4ae */
if(!s->budget--) { s->failed_pc=0x0c09f4aeu; return 0; }
r[6]=r[2];
goto P_0c09f4b0;
P_0c09f4b0: /* original 1f22, guest PC 0x0c09f4b0 */
if(!s->budget--) { s->failed_pc=0x0c09f4b0u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09f4b2;
P_0c09f4b2: /* original b025, guest PC 0x0c09f4b2 */
if(!s->budget--) { s->failed_pc=0x0c09f4b2u; return 0; }
target=code_base|0x0c09f500u; r[16]=code_base|0x0c09f4b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4b6u) { target=s->pc; goto dispatch; }
goto P_0c09f4b6;
P_0c09f4b4: /* original 64e3, guest PC 0x0c09f4b4 */
if(!s->budget--) { s->failed_pc=0x0c09f4b4u; return 0; }
r[4]=r[14];
goto P_0c09f4b6;
P_0c09f4b6: /* original 6403, guest PC 0x0c09f4b6 */
if(!s->budget--) { s->failed_pc=0x0c09f4b6u; return 0; }
r[4]=r[0];
goto P_0c09f4b8;
P_0c09f4b8: /* original e004, guest PC 0x0c09f4b8 */
if(!s->budget--) { s->failed_pc=0x0c09f4b8u; return 0; }
r[0]=0x00000004u;
goto P_0c09f4ba;
P_0c09f4ba: /* original f6f6, guest PC 0x0c09f4ba */
if(!s->budget--) { s->failed_pc=0x0c09f4bau; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f4bc;
P_0c09f4bc: /* original f5f8, guest PC 0x0c09f4bc */
if(!s->budget--) { s->failed_pc=0x0c09f4bcu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f4be;
P_0c09f4be: /* original f9ec, guest PC 0x0c09f4be */
if(!s->budget--) { s->failed_pc=0x0c09f4beu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f4c0;
P_0c09f4c0: /* original f8dc, guest PC 0x0c09f4c0 */
if(!s->budget--) { s->failed_pc=0x0c09f4c0u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f4c2;
P_0c09f4c2: /* original f7cc, guest PC 0x0c09f4c2 */
if(!s->budget--) { s->failed_pc=0x0c09f4c2u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f4c4;
P_0c09f4c4: /* original b098, guest PC 0x0c09f4c4 */
if(!s->budget--) { s->failed_pc=0x0c09f4c4u; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f4c8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4c8u) { target=s->pc; goto dispatch; }
goto P_0c09f4c8;
P_0c09f4c6: /* original f4fc, guest PC 0x0c09f4c6 */
if(!s->budget--) { s->failed_pc=0x0c09f4c6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f4c8;
P_0c09f4c8: /* original 920f, guest PC 0x0c09f4c8 */
if(!s->budget--) { s->failed_pc=0x0c09f4c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f4eau,2);
goto P_0c09f4ca;
P_0c09f4ca: /* original 6503, guest PC 0x0c09f4ca */
if(!s->budget--) { s->failed_pc=0x0c09f4cau; return 0; }
r[5]=r[0];
goto P_0c09f4cc;
P_0c09f4cc: /* original 32ec, guest PC 0x0c09f4cc */
if(!s->budget--) { s->failed_pc=0x0c09f4ccu; return 0; }
r[2]+=r[14];
goto P_0c09f4ce;
P_0c09f4ce: /* original 6623, guest PC 0x0c09f4ce */
if(!s->budget--) { s->failed_pc=0x0c09f4ceu; return 0; }
r[6]=r[2];
goto P_0c09f4d0;
P_0c09f4d0: /* original 1f22, guest PC 0x0c09f4d0 */
if(!s->budget--) { s->failed_pc=0x0c09f4d0u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09f4d2;
P_0c09f4d2: /* original b015, guest PC 0x0c09f4d2 */
if(!s->budget--) { s->failed_pc=0x0c09f4d2u; return 0; }
target=code_base|0x0c09f500u; r[16]=code_base|0x0c09f4d6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4d6u) { target=s->pc; goto dispatch; }
goto P_0c09f4d6;
P_0c09f4d4: /* original 64e3, guest PC 0x0c09f4d4 */
if(!s->budget--) { s->failed_pc=0x0c09f4d4u; return 0; }
r[4]=r[14];
goto P_0c09f4d6;
P_0c09f4d6: /* original 7f0c, guest PC 0x0c09f4d6 */
if(!s->budget--) { s->failed_pc=0x0c09f4d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09f4d8;
P_0c09f4d8: /* original 4f26, guest PC 0x0c09f4d8 */
if(!s->budget--) { s->failed_pc=0x0c09f4d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09f4da;
P_0c09f4da: /* original fcf9, guest PC 0x0c09f4da */
if(!s->budget--) { s->failed_pc=0x0c09f4dau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4dc;
P_0c09f4dc: /* original fdf9, guest PC 0x0c09f4dc */
if(!s->budget--) { s->failed_pc=0x0c09f4dcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4de;
P_0c09f4de: /* original fef9, guest PC 0x0c09f4de */
if(!s->budget--) { s->failed_pc=0x0c09f4deu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4e0;
P_0c09f4e0: /* original fff9, guest PC 0x0c09f4e0 */
if(!s->budget--) { s->failed_pc=0x0c09f4e0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4e2;
P_0c09f4e2: /* original 000b, guest PC 0x0c09f4e2 */
if(!s->budget--) { s->failed_pc=0x0c09f4e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f4e4: /* original 6ef6, guest PC 0x0c09f4e4 */
if(!s->budget--) { s->failed_pc=0x0c09f4e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f4e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f4e6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
