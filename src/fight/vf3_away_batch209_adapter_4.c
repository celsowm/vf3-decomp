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
int vf3_away_batch209_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0abfa2u: goto P_0c0abfa2;
case 0x0c0abfa4u: goto P_0c0abfa4;
case 0x0c0abfa6u: goto P_0c0abfa6;
case 0x0c0abfa8u: goto P_0c0abfa8;
case 0x0c0abfaau: goto P_0c0abfaa;
case 0x0c0abfacu: goto P_0c0abfac;
case 0x0c0abfaeu: goto P_0c0abfae;
case 0x0c0abfb0u: goto P_0c0abfb0;
case 0x0c0abfb2u: goto P_0c0abfb2;
case 0x0c0abfb4u: goto P_0c0abfb4;
case 0x0c0abfb6u: goto P_0c0abfb6;
case 0x0c0abfb8u: goto P_0c0abfb8;
case 0x0c0abfbau: goto P_0c0abfba;
case 0x0c0abfbcu: goto P_0c0abfbc;
case 0x0c0abfbeu: goto P_0c0abfbe;
case 0x0c0abfc0u: goto P_0c0abfc0;
case 0x0c0abfc2u: goto P_0c0abfc2;
case 0x0c0abfc4u: goto P_0c0abfc4;
case 0x0c0abfc6u: goto P_0c0abfc6;
case 0x0c0abfc8u: goto P_0c0abfc8;
case 0x0c0abfcau: goto P_0c0abfca;
case 0x0c0abfccu: goto P_0c0abfcc;
case 0x0c0abfceu: goto P_0c0abfce;
case 0x0c0abfd0u: goto P_0c0abfd0;
case 0x0c0abfd2u: goto P_0c0abfd2;
case 0x0c0abfd4u: goto P_0c0abfd4;
case 0x0c0abfd6u: goto P_0c0abfd6;
case 0x0c0abfd8u: goto P_0c0abfd8;
case 0x0c0abfdau: goto P_0c0abfda;
case 0x0c0abfdcu: goto P_0c0abfdc;
case 0x0c0abfdeu: goto P_0c0abfde;
case 0x0c0abfe0u: goto P_0c0abfe0;
case 0x0c0abfe2u: goto P_0c0abfe2;
case 0x0c0abfe4u: goto P_0c0abfe4;
case 0x0c0abfe6u: goto P_0c0abfe6;
case 0x0c0abfe8u: goto P_0c0abfe8;
case 0x0c0abfeau: goto P_0c0abfea;
case 0x0c0abfecu: goto P_0c0abfec;
case 0x0c0abfeeu: goto P_0c0abfee;
case 0x0c0abff0u: goto P_0c0abff0;
case 0x0c0abff2u: goto P_0c0abff2;
case 0x0c0abff4u: goto P_0c0abff4;
case 0x0c0abff6u: goto P_0c0abff6;
case 0x0c0abff8u: goto P_0c0abff8;
case 0x0c0abffau: goto P_0c0abffa;
case 0x0c0abffcu: goto P_0c0abffc;
case 0x0c0abffeu: goto P_0c0abffe;
case 0x0c0ac000u: goto P_0c0ac000;
case 0x0c0ac002u: goto P_0c0ac002;
case 0x0c0ac004u: goto P_0c0ac004;
case 0x0c0ac006u: goto P_0c0ac006;
case 0x0c0ac008u: goto P_0c0ac008;
case 0x0c0ac00au: goto P_0c0ac00a;
case 0x0c0ac00cu: goto P_0c0ac00c;
case 0x0c0ac00eu: goto P_0c0ac00e;
case 0x0c0ac010u: goto P_0c0ac010;
case 0x0c0ac012u: goto P_0c0ac012;
case 0x0c0ac014u: goto P_0c0ac014;
case 0x0c0ac016u: goto P_0c0ac016;
case 0x0c0ac018u: goto P_0c0ac018;
case 0x0c0ac01au: goto P_0c0ac01a;
case 0x0c0ac01cu: goto P_0c0ac01c;
case 0x0c0ac01eu: goto P_0c0ac01e;
case 0x0c0ac020u: goto P_0c0ac020;
case 0x0c0ac022u: goto P_0c0ac022;
case 0x0c0ac024u: goto P_0c0ac024;
case 0x0c0ac026u: goto P_0c0ac026;
case 0x0c0ac028u: goto P_0c0ac028;
case 0x0c0ac02au: goto P_0c0ac02a;
case 0x0c0ac02cu: goto P_0c0ac02c;
case 0x0c0ac02eu: goto P_0c0ac02e;
case 0x0c0ac030u: goto P_0c0ac030;
case 0x0c0ac032u: goto P_0c0ac032;
case 0x0c0ac034u: goto P_0c0ac034;
case 0x0c0ac036u: goto P_0c0ac036;
case 0x0c0ac038u: goto P_0c0ac038;
case 0x0c0ac03au: goto P_0c0ac03a;
case 0x0c0ac03cu: goto P_0c0ac03c;
case 0x0c0ac03eu: goto P_0c0ac03e;
case 0x0c0ac040u: goto P_0c0ac040;
case 0x0c0ac042u: goto P_0c0ac042;
case 0x0c0ac044u: goto P_0c0ac044;
case 0x0c0ac046u: goto P_0c0ac046;
case 0x0c0ac048u: goto P_0c0ac048;
case 0x0c0ac04au: goto P_0c0ac04a;
case 0x0c0ac04cu: goto P_0c0ac04c;
case 0x0c0ac04eu: goto P_0c0ac04e;
case 0x0c0ac050u: goto P_0c0ac050;
case 0x0c0ac052u: goto P_0c0ac052;
case 0x0c0ac054u: goto P_0c0ac054;
case 0x0c0ac0dau: goto P_0c0ac0da;
case 0x0c0ac0dcu: goto P_0c0ac0dc;
case 0x0c0ac0deu: goto P_0c0ac0de;
case 0x0c0ac0e0u: goto P_0c0ac0e0;
case 0x0c0ac0e2u: goto P_0c0ac0e2;
case 0x0c0ac0e4u: goto P_0c0ac0e4;
case 0x0c0ac0e6u: goto P_0c0ac0e6;
case 0x0c0ac0e8u: goto P_0c0ac0e8;
case 0x0c0ac0eau: goto P_0c0ac0ea;
case 0x0c0ac0ecu: goto P_0c0ac0ec;
case 0x0c0ac0eeu: goto P_0c0ac0ee;
case 0x0c0ac0f0u: goto P_0c0ac0f0;
case 0x0c0ac0f2u: goto P_0c0ac0f2;
case 0x0c0ac0f4u: goto P_0c0ac0f4;
case 0x0c0ac0f6u: goto P_0c0ac0f6;
case 0x0c0ac0f8u: goto P_0c0ac0f8;
case 0x0c0ac0fau: goto P_0c0ac0fa;
case 0x0c0ac0fcu: goto P_0c0ac0fc;
case 0x0c0ac0feu: goto P_0c0ac0fe;
case 0x0c0ac100u: goto P_0c0ac100;
case 0x0c0ac102u: goto P_0c0ac102;
case 0x0c0ac140u: goto P_0c0ac140;
case 0x0c0ac142u: goto P_0c0ac142;
case 0x0c0ac144u: goto P_0c0ac144;
case 0x0c0ac146u: goto P_0c0ac146;
case 0x0c0ac148u: goto P_0c0ac148;
case 0x0c0ac14au: goto P_0c0ac14a;
case 0x0c0ac14cu: goto P_0c0ac14c;
case 0x0c0ac14eu: goto P_0c0ac14e;
case 0x0c0ac150u: goto P_0c0ac150;
case 0x0c0ac152u: goto P_0c0ac152;
case 0x0c0ac154u: goto P_0c0ac154;
case 0x0c0ac156u: goto P_0c0ac156;
case 0x0c0ac158u: goto P_0c0ac158;
case 0x0c0ac15au: goto P_0c0ac15a;
case 0x0c0ac15cu: goto P_0c0ac15c;
case 0x0c0ac15eu: goto P_0c0ac15e;
case 0x0c0ac160u: goto P_0c0ac160;
case 0x0c0ac162u: goto P_0c0ac162;
case 0x0c0ac1ceu: goto P_0c0ac1ce;
case 0x0c0ac1d0u: goto P_0c0ac1d0;
case 0x0c0ac1d2u: goto P_0c0ac1d2;
case 0x0c0ac1d4u: goto P_0c0ac1d4;
case 0x0c0ac1d6u: goto P_0c0ac1d6;
case 0x0c0ac1d8u: goto P_0c0ac1d8;
case 0x0c0ac1dau: goto P_0c0ac1da;
case 0x0c0ac1dcu: goto P_0c0ac1dc;
case 0x0c0ac1deu: goto P_0c0ac1de;
case 0x0c0ac1e0u: goto P_0c0ac1e0;
case 0x0c0ac1e2u: goto P_0c0ac1e2;
case 0x0c0ac1e4u: goto P_0c0ac1e4;
case 0x0c0ac1e6u: goto P_0c0ac1e6;
case 0x0c0ac1e8u: goto P_0c0ac1e8;
case 0x0c0ac1eau: goto P_0c0ac1ea;
case 0x0c0ac1ecu: goto P_0c0ac1ec;
case 0x0c0ac1eeu: goto P_0c0ac1ee;
case 0x0c0ac1f0u: goto P_0c0ac1f0;
case 0x0c0ac1f2u: goto P_0c0ac1f2;
case 0x0c0ac1f4u: goto P_0c0ac1f4;
case 0x0c0ac1f6u: goto P_0c0ac1f6;
case 0x0c0ac1f8u: goto P_0c0ac1f8;
case 0x0c0ac1fau: goto P_0c0ac1fa;
case 0x0c0ac1fcu: goto P_0c0ac1fc;
case 0x0c0ac1feu: goto P_0c0ac1fe;
case 0x0c0ac200u: goto P_0c0ac200;
case 0x0c0ac202u: goto P_0c0ac202;
case 0x0c0ac204u: goto P_0c0ac204;
case 0x0c0ac206u: goto P_0c0ac206;
case 0x0c0ac208u: goto P_0c0ac208;
case 0x0c0ac20au: goto P_0c0ac20a;
case 0x0c0ac20cu: goto P_0c0ac20c;
case 0x0c0ac20eu: goto P_0c0ac20e;
case 0x0c0ac210u: goto P_0c0ac210;
case 0x0c0ac212u: goto P_0c0ac212;
case 0x0c0ac214u: goto P_0c0ac214;
case 0x0c0ac216u: goto P_0c0ac216;
case 0x0c0ac218u: goto P_0c0ac218;
case 0x0c0ac21au: goto P_0c0ac21a;
case 0x0c0ac21cu: goto P_0c0ac21c;
case 0x0c0ac21eu: goto P_0c0ac21e;
case 0x0c0ac220u: goto P_0c0ac220;
case 0x0c0ac222u: goto P_0c0ac222;
case 0x0c0ac224u: goto P_0c0ac224;
case 0x0c0ac226u: goto P_0c0ac226;
case 0x0c0ac228u: goto P_0c0ac228;
case 0x0c0ac22au: goto P_0c0ac22a;
case 0x0c0ac22cu: goto P_0c0ac22c;
case 0x0c0ac22eu: goto P_0c0ac22e;
case 0x0c0ac230u: goto P_0c0ac230;
case 0x0c0ac232u: goto P_0c0ac232;
case 0x0c0ac234u: goto P_0c0ac234;
case 0x0c0ac236u: goto P_0c0ac236;
case 0x0c0ac238u: goto P_0c0ac238;
case 0x0c0ac23au: goto P_0c0ac23a;
case 0x0c0ac23cu: goto P_0c0ac23c;
case 0x0c0ac23eu: goto P_0c0ac23e;
case 0x0c0ac240u: goto P_0c0ac240;
case 0x0c0ac242u: goto P_0c0ac242;
case 0x0c0ac244u: goto P_0c0ac244;
case 0x0c0ac246u: goto P_0c0ac246;
case 0x0c0ac248u: goto P_0c0ac248;
case 0x0c0ac24au: goto P_0c0ac24a;
case 0x0c0ac24cu: goto P_0c0ac24c;
case 0x0c0ac24eu: goto P_0c0ac24e;
case 0x0c0ac250u: goto P_0c0ac250;
case 0x0c0ac252u: goto P_0c0ac252;
case 0x0c0ac254u: goto P_0c0ac254;
case 0x0c0ac256u: goto P_0c0ac256;
case 0x0c0ac258u: goto P_0c0ac258;
case 0x0c0ac25au: goto P_0c0ac25a;
case 0x0c0ac25cu: goto P_0c0ac25c;
case 0x0c0ac25eu: goto P_0c0ac25e;
case 0x0c0ac260u: goto P_0c0ac260;
case 0x0c0ac262u: goto P_0c0ac262;
case 0x0c0ac264u: goto P_0c0ac264;
case 0x0c0ac266u: goto P_0c0ac266;
case 0x0c0ac268u: goto P_0c0ac268;
case 0x0c0ac26au: goto P_0c0ac26a;
case 0x0c0ac26cu: goto P_0c0ac26c;
case 0x0c0ac26eu: goto P_0c0ac26e;
case 0x0c0ac270u: goto P_0c0ac270;
case 0x0c0ac272u: goto P_0c0ac272;
case 0x0c0ac274u: goto P_0c0ac274;
case 0x0c0ac276u: goto P_0c0ac276;
case 0x0c0ac278u: goto P_0c0ac278;
case 0x0c0ac27au: goto P_0c0ac27a;
case 0x0c0ac27cu: goto P_0c0ac27c;
case 0x0c0ac27eu: goto P_0c0ac27e;
case 0x0c0ac280u: goto P_0c0ac280;
case 0x0c0ac282u: goto P_0c0ac282;
case 0x0c0ac284u: goto P_0c0ac284;
case 0x0c0ac286u: goto P_0c0ac286;
case 0x0c0ac288u: goto P_0c0ac288;
case 0x0c0ac28au: goto P_0c0ac28a;
case 0x0c0ac28cu: goto P_0c0ac28c;
case 0x0c0ac2b8u: goto P_0c0ac2b8;
case 0x0c0ac2bau: goto P_0c0ac2ba;
case 0x0c0ac2bcu: goto P_0c0ac2bc;
case 0x0c0ac2beu: goto P_0c0ac2be;
case 0x0c0ac2c0u: goto P_0c0ac2c0;
case 0x0c0ac2c2u: goto P_0c0ac2c2;
case 0x0c0ac2c4u: goto P_0c0ac2c4;
case 0x0c0ac2c6u: goto P_0c0ac2c6;
case 0x0c0ac2c8u: goto P_0c0ac2c8;
case 0x0c0ac2cau: goto P_0c0ac2ca;
case 0x0c0ac2ccu: goto P_0c0ac2cc;
case 0x0c0ac2ceu: goto P_0c0ac2ce;
case 0x0c0ac2d0u: goto P_0c0ac2d0;
case 0x0c0ac2d2u: goto P_0c0ac2d2;
case 0x0c0ac2d4u: goto P_0c0ac2d4;
case 0x0c0ac2d6u: goto P_0c0ac2d6;
case 0x0c0ac2d8u: goto P_0c0ac2d8;
case 0x0c0ac2dau: goto P_0c0ac2da;
case 0x0c0ac2dcu: goto P_0c0ac2dc;
case 0x0c0ac2deu: goto P_0c0ac2de;
case 0x0c0ac2e0u: goto P_0c0ac2e0;
case 0x0c0ac2e2u: goto P_0c0ac2e2;
case 0x0c0ac2e4u: goto P_0c0ac2e4;
case 0x0c0ac2e6u: goto P_0c0ac2e6;
case 0x0c0ac2e8u: goto P_0c0ac2e8;
case 0x0c0ac2eau: goto P_0c0ac2ea;
case 0x0c0ac2ecu: goto P_0c0ac2ec;
case 0x0c0ac2eeu: goto P_0c0ac2ee;
case 0x0c0ac2f0u: goto P_0c0ac2f0;
case 0x0c0ac2f2u: goto P_0c0ac2f2;
case 0x0c0ac2f4u: goto P_0c0ac2f4;
case 0x0c0ac2f6u: goto P_0c0ac2f6;
case 0x0c0ac2f8u: goto P_0c0ac2f8;
case 0x0c0ac2fau: goto P_0c0ac2fa;
case 0x0c0ac2fcu: goto P_0c0ac2fc;
case 0x0c0ac2feu: goto P_0c0ac2fe;
case 0x0c0ac300u: goto P_0c0ac300;
case 0x0c0ac302u: goto P_0c0ac302;
case 0x0c0ac304u: goto P_0c0ac304;
case 0x0c0ac306u: goto P_0c0ac306;
case 0x0c0ac308u: goto P_0c0ac308;
case 0x0c0ac30au: goto P_0c0ac30a;
case 0x0c0ac30cu: goto P_0c0ac30c;
case 0x0c0ac30eu: goto P_0c0ac30e;
case 0x0c0ac310u: goto P_0c0ac310;
case 0x0c0ac312u: goto P_0c0ac312;
case 0x0c0ac314u: goto P_0c0ac314;
case 0x0c0ac316u: goto P_0c0ac316;
case 0x0c0ac318u: goto P_0c0ac318;
case 0x0c0ac31au: goto P_0c0ac31a;
case 0x0c0ac31cu: goto P_0c0ac31c;
case 0x0c0ac31eu: goto P_0c0ac31e;
case 0x0c0ac320u: goto P_0c0ac320;
case 0x0c0ac322u: goto P_0c0ac322;
case 0x0c0ac324u: goto P_0c0ac324;
case 0x0c0ac326u: goto P_0c0ac326;
case 0x0c0ac328u: goto P_0c0ac328;
case 0x0c0ac32au: goto P_0c0ac32a;
case 0x0c0ac32cu: goto P_0c0ac32c;
case 0x0c0ac32eu: goto P_0c0ac32e;
case 0x0c0ac330u: goto P_0c0ac330;
case 0x0c0ac332u: goto P_0c0ac332;
case 0x0c0ac334u: goto P_0c0ac334;
case 0x0c0ac336u: goto P_0c0ac336;
case 0x0c0ac338u: goto P_0c0ac338;
case 0x0c0ac33au: goto P_0c0ac33a;
case 0x0c0ac33cu: goto P_0c0ac33c;
case 0x0c0ac33eu: goto P_0c0ac33e;
case 0x0c0ac354u: goto P_0c0ac354;
case 0x0c0ac356u: goto P_0c0ac356;
case 0x0c0ac358u: goto P_0c0ac358;
case 0x0c0ac35au: goto P_0c0ac35a;
case 0x0c0ac35cu: goto P_0c0ac35c;
case 0x0c0ac35eu: goto P_0c0ac35e;
case 0x0c0ac360u: goto P_0c0ac360;
case 0x0c0ac362u: goto P_0c0ac362;
case 0x0c0ac364u: goto P_0c0ac364;
case 0x0c0ac366u: goto P_0c0ac366;
case 0x0c0ac368u: goto P_0c0ac368;
case 0x0c0ac36au: goto P_0c0ac36a;
case 0x0c0ac36cu: goto P_0c0ac36c;
case 0x0c0ac36eu: goto P_0c0ac36e;
case 0x0c0ac370u: goto P_0c0ac370;
case 0x0c0ac372u: goto P_0c0ac372;
case 0x0c0ac374u: goto P_0c0ac374;
case 0x0c0ac376u: goto P_0c0ac376;
case 0x0c0ac378u: goto P_0c0ac378;
case 0x0c0ac37au: goto P_0c0ac37a;
case 0x0c0ac37cu: goto P_0c0ac37c;
case 0x0c0ac37eu: goto P_0c0ac37e;
case 0x0c0ac380u: goto P_0c0ac380;
case 0x0c0ac382u: goto P_0c0ac382;
case 0x0c0ac384u: goto P_0c0ac384;
case 0x0c0ac386u: goto P_0c0ac386;
case 0x0c0ac388u: goto P_0c0ac388;
case 0x0c0ac38au: goto P_0c0ac38a;
case 0x0c0ac38cu: goto P_0c0ac38c;
case 0x0c0ac38eu: goto P_0c0ac38e;
case 0x0c0ac390u: goto P_0c0ac390;
case 0x0c0ac392u: goto P_0c0ac392;
case 0x0c0ac394u: goto P_0c0ac394;
case 0x0c0ac396u: goto P_0c0ac396;
case 0x0c0ac398u: goto P_0c0ac398;
case 0x0c0ac39au: goto P_0c0ac39a;
case 0x0c0ac39cu: goto P_0c0ac39c;
case 0x0c0ac39eu: goto P_0c0ac39e;
case 0x0c0ac3a0u: goto P_0c0ac3a0;
case 0x0c0ac3a2u: goto P_0c0ac3a2;
case 0x0c0ac3a4u: goto P_0c0ac3a4;
case 0x0c0ac3a6u: goto P_0c0ac3a6;
case 0x0c0ac3a8u: goto P_0c0ac3a8;
case 0x0c0ac3aau: goto P_0c0ac3aa;
case 0x0c0ac3acu: goto P_0c0ac3ac;
case 0x0c0ac3aeu: goto P_0c0ac3ae;
case 0x0c0ac3b0u: goto P_0c0ac3b0;
case 0x0c0ac3b2u: goto P_0c0ac3b2;
case 0x0c0ac3b4u: goto P_0c0ac3b4;
case 0x0c0ac3b6u: goto P_0c0ac3b6;
case 0x0c0ac3b8u: goto P_0c0ac3b8;
case 0x0c0ac3bau: goto P_0c0ac3ba;
case 0x0c0ac3bcu: goto P_0c0ac3bc;
case 0x0c0ac3beu: goto P_0c0ac3be;
case 0x0c0ac3c0u: goto P_0c0ac3c0;
case 0x0c0ac3c2u: goto P_0c0ac3c2;
case 0x0c0ac3c4u: goto P_0c0ac3c4;
case 0x0c0ac3c6u: goto P_0c0ac3c6;
case 0x0c0ac3c8u: goto P_0c0ac3c8;
case 0x0c0ac3cau: goto P_0c0ac3ca;
case 0x0c0ac3ccu: goto P_0c0ac3cc;
case 0x0c0ac3ceu: goto P_0c0ac3ce;
case 0x0c0ac3d0u: goto P_0c0ac3d0;
case 0x0c0ac3d2u: goto P_0c0ac3d2;
case 0x0c0ac3d4u: goto P_0c0ac3d4;
case 0x0c0ac3d6u: goto P_0c0ac3d6;
case 0x0c0ac3d8u: goto P_0c0ac3d8;
case 0x0c0ac3dau: goto P_0c0ac3da;
case 0x0c0ac3dcu: goto P_0c0ac3dc;
case 0x0c0ac3deu: goto P_0c0ac3de;
case 0x0c0ac3e0u: goto P_0c0ac3e0;
case 0x0c0ac3e2u: goto P_0c0ac3e2;
case 0x0c0ac3e4u: goto P_0c0ac3e4;
case 0x0c0ac3e6u: goto P_0c0ac3e6;
case 0x0c0ac3e8u: goto P_0c0ac3e8;
case 0x0c0ac3eau: goto P_0c0ac3ea;
case 0x0c0ac3ecu: goto P_0c0ac3ec;
case 0x0c0ac3eeu: goto P_0c0ac3ee;
case 0x0c0ac3f0u: goto P_0c0ac3f0;
case 0x0c0ac3f2u: goto P_0c0ac3f2;
case 0x0c0ac3f4u: goto P_0c0ac3f4;
case 0x0c0ac3f6u: goto P_0c0ac3f6;
case 0x0c0ac3f8u: goto P_0c0ac3f8;
case 0x0c0ac3fau: goto P_0c0ac3fa;
case 0x0c0ac3fcu: goto P_0c0ac3fc;
case 0x0c0ac3feu: goto P_0c0ac3fe;
case 0x0c0ac400u: goto P_0c0ac400;
case 0x0c0ac402u: goto P_0c0ac402;
case 0x0c0ac404u: goto P_0c0ac404;
case 0x0c0ac406u: goto P_0c0ac406;
case 0x0c0ac408u: goto P_0c0ac408;
case 0x0c0ac40au: goto P_0c0ac40a;
case 0x0c0ac40cu: goto P_0c0ac40c;
case 0x0c0ac40eu: goto P_0c0ac40e;
case 0x0c0ac410u: goto P_0c0ac410;
case 0x0c0ac412u: goto P_0c0ac412;
case 0x0c0ac414u: goto P_0c0ac414;
case 0x0c0ac416u: goto P_0c0ac416;
case 0x0c0ac418u: goto P_0c0ac418;
case 0x0c0ac41au: goto P_0c0ac41a;
case 0x0c0ac41cu: goto P_0c0ac41c;
case 0x0c0ac41eu: goto P_0c0ac41e;
case 0x0c0ac420u: goto P_0c0ac420;
case 0x0c0ac422u: goto P_0c0ac422;
case 0x0c0ac424u: goto P_0c0ac424;
case 0x0c0ac426u: goto P_0c0ac426;
case 0x0c0ac428u: goto P_0c0ac428;
case 0x0c0ac42au: goto P_0c0ac42a;
case 0x0c0ac42cu: goto P_0c0ac42c;
case 0x0c0ac42eu: goto P_0c0ac42e;
case 0x0c0ac430u: goto P_0c0ac430;
case 0x0c0ac432u: goto P_0c0ac432;
case 0x0c0ac434u: goto P_0c0ac434;
case 0x0c0ac436u: goto P_0c0ac436;
case 0x0c0ac438u: goto P_0c0ac438;
case 0x0c0ac43au: goto P_0c0ac43a;
case 0x0c0ac43cu: goto P_0c0ac43c;
case 0x0c0ac43eu: goto P_0c0ac43e;
case 0x0c0ac440u: goto P_0c0ac440;
case 0x0c0ac442u: goto P_0c0ac442;
case 0x0c0ac444u: goto P_0c0ac444;
case 0x0c0ac446u: goto P_0c0ac446;
case 0x0c0ac448u: goto P_0c0ac448;
case 0x0c0ac44au: goto P_0c0ac44a;
case 0x0c0ac44cu: goto P_0c0ac44c;
case 0x0c0ac44eu: goto P_0c0ac44e;
case 0x0c0ac450u: goto P_0c0ac450;
case 0x0c0ac452u: goto P_0c0ac452;
case 0x0c0ac454u: goto P_0c0ac454;
case 0x0c0ac456u: goto P_0c0ac456;
case 0x0c0ac458u: goto P_0c0ac458;
case 0x0c0ac45au: goto P_0c0ac45a;
case 0x0c0ac45cu: goto P_0c0ac45c;
case 0x0c0ac45eu: goto P_0c0ac45e;
case 0x0c0ac460u: goto P_0c0ac460;
case 0x0c0ac462u: goto P_0c0ac462;
case 0x0c0ac464u: goto P_0c0ac464;
case 0x0c0ac466u: goto P_0c0ac466;
case 0x0c0ac468u: goto P_0c0ac468;
case 0x0c0ac46au: goto P_0c0ac46a;
case 0x0c0ac46cu: goto P_0c0ac46c;
case 0x0c0ac46eu: goto P_0c0ac46e;
case 0x0c0ac470u: goto P_0c0ac470;
case 0x0c0ac472u: goto P_0c0ac472;
case 0x0c0ac474u: goto P_0c0ac474;
case 0x0c0ac476u: goto P_0c0ac476;
case 0x0c0ac478u: goto P_0c0ac478;
case 0x0c0ac47au: goto P_0c0ac47a;
case 0x0c0ac47cu: goto P_0c0ac47c;
case 0x0c0ac47eu: goto P_0c0ac47e;
case 0x0c0ac480u: goto P_0c0ac480;
case 0x0c0ac482u: goto P_0c0ac482;
case 0x0c0ac484u: goto P_0c0ac484;
case 0x0c0ac486u: goto P_0c0ac486;
case 0x0c0ac488u: goto P_0c0ac488;
case 0x0c0ac48au: goto P_0c0ac48a;
case 0x0c0ac48cu: goto P_0c0ac48c;
case 0x0c0ac48eu: goto P_0c0ac48e;
case 0x0c0ac490u: goto P_0c0ac490;
case 0x0c0ac4c0u: goto P_0c0ac4c0;
case 0x0c0ac4c2u: goto P_0c0ac4c2;
case 0x0c0ac4c4u: goto P_0c0ac4c4;
case 0x0c0ac4c6u: goto P_0c0ac4c6;
case 0x0c0ac4c8u: goto P_0c0ac4c8;
case 0x0c0ac4cau: goto P_0c0ac4ca;
case 0x0c0ac4ccu: goto P_0c0ac4cc;
case 0x0c0ac4ceu: goto P_0c0ac4ce;
case 0x0c0ac4d0u: goto P_0c0ac4d0;
case 0x0c0ac4d2u: goto P_0c0ac4d2;
case 0x0c0ac4d4u: goto P_0c0ac4d4;
case 0x0c0ac4d6u: goto P_0c0ac4d6;
case 0x0c0ac4d8u: goto P_0c0ac4d8;
case 0x0c0ac4dau: goto P_0c0ac4da;
case 0x0c0ac4dcu: goto P_0c0ac4dc;
case 0x0c0ac4deu: goto P_0c0ac4de;
case 0x0c0ac4e0u: goto P_0c0ac4e0;
case 0x0c0ac4e2u: goto P_0c0ac4e2;
case 0x0c0ac4e4u: goto P_0c0ac4e4;
case 0x0c0ac4e6u: goto P_0c0ac4e6;
case 0x0c0ac4e8u: goto P_0c0ac4e8;
case 0x0c0ac4eau: goto P_0c0ac4ea;
case 0x0c0ac4ecu: goto P_0c0ac4ec;
case 0x0c0ac4eeu: goto P_0c0ac4ee;
case 0x0c0ac4f0u: goto P_0c0ac4f0;
case 0x0c0ac4f2u: goto P_0c0ac4f2;
case 0x0c0ac4f4u: goto P_0c0ac4f4;
case 0x0c0ac4f6u: goto P_0c0ac4f6;
case 0x0c0ac4f8u: goto P_0c0ac4f8;
case 0x0c0ac4fau: goto P_0c0ac4fa;
case 0x0c0ac4fcu: goto P_0c0ac4fc;
case 0x0c0ac4feu: goto P_0c0ac4fe;
case 0x0c0ac500u: goto P_0c0ac500;
case 0x0c0ac502u: goto P_0c0ac502;
case 0x0c0ac504u: goto P_0c0ac504;
case 0x0c0ac506u: goto P_0c0ac506;
case 0x0c0ac508u: goto P_0c0ac508;
case 0x0c0ac50au: goto P_0c0ac50a;
case 0x0c0ac50cu: goto P_0c0ac50c;
case 0x0c0ac50eu: goto P_0c0ac50e;
case 0x0c0ac510u: goto P_0c0ac510;
case 0x0c0ac512u: goto P_0c0ac512;
case 0x0c0ac514u: goto P_0c0ac514;
case 0x0c0ac516u: goto P_0c0ac516;
case 0x0c0ac518u: goto P_0c0ac518;
case 0x0c0ac51au: goto P_0c0ac51a;
case 0x0c0ac51cu: goto P_0c0ac51c;
case 0x0c0ac51eu: goto P_0c0ac51e;
case 0x0c0ac520u: goto P_0c0ac520;
case 0x0c0ac522u: goto P_0c0ac522;
case 0x0c0ac524u: goto P_0c0ac524;
case 0x0c0ac526u: goto P_0c0ac526;
case 0x0c0ac528u: goto P_0c0ac528;
case 0x0c0ac52au: goto P_0c0ac52a;
case 0x0c0ac52cu: goto P_0c0ac52c;
case 0x0c0ac52eu: goto P_0c0ac52e;
case 0x0c0ac530u: goto P_0c0ac530;
case 0x0c0ac532u: goto P_0c0ac532;
case 0x0c0ac534u: goto P_0c0ac534;
case 0x0c0ac536u: goto P_0c0ac536;
case 0x0c0ac538u: goto P_0c0ac538;
case 0x0c0ac53au: goto P_0c0ac53a;
case 0x0c0ac53cu: goto P_0c0ac53c;
case 0x0c0ac53eu: goto P_0c0ac53e;
case 0x0c0ac540u: goto P_0c0ac540;
case 0x0c0ac542u: goto P_0c0ac542;
case 0x0c0ac544u: goto P_0c0ac544;
case 0x0c0ac546u: goto P_0c0ac546;
case 0x0c0ac548u: goto P_0c0ac548;
case 0x0c0ac54au: goto P_0c0ac54a;
case 0x0c0ac54cu: goto P_0c0ac54c;
case 0x0c0ac54eu: goto P_0c0ac54e;
case 0x0c0ac550u: goto P_0c0ac550;
case 0x0c0ac552u: goto P_0c0ac552;
case 0x0c0ac554u: goto P_0c0ac554;
case 0x0c0ac556u: goto P_0c0ac556;
case 0x0c0ac558u: goto P_0c0ac558;
case 0x0c0ac55au: goto P_0c0ac55a;
case 0x0c0ac55cu: goto P_0c0ac55c;
case 0x0c0ac55eu: goto P_0c0ac55e;
case 0x0c0ac560u: goto P_0c0ac560;
case 0x0c0ac562u: goto P_0c0ac562;
case 0x0c0ac564u: goto P_0c0ac564;
case 0x0c0ac566u: goto P_0c0ac566;
case 0x0c0ac568u: goto P_0c0ac568;
case 0x0c0ac56au: goto P_0c0ac56a;
case 0x0c0ac56cu: goto P_0c0ac56c;
case 0x0c0ac56eu: goto P_0c0ac56e;
case 0x0c0ac570u: goto P_0c0ac570;
case 0x0c0ac572u: goto P_0c0ac572;
case 0x0c0ac574u: goto P_0c0ac574;
case 0x0c0ac576u: goto P_0c0ac576;
case 0x0c0ac578u: goto P_0c0ac578;
case 0x0c0ac57au: goto P_0c0ac57a;
case 0x0c0ac57cu: goto P_0c0ac57c;
case 0x0c0ac57eu: goto P_0c0ac57e;
case 0x0c0ac580u: goto P_0c0ac580;
case 0x0c0ac582u: goto P_0c0ac582;
case 0x0c0ac584u: goto P_0c0ac584;
case 0x0c0ac586u: goto P_0c0ac586;
case 0x0c0ac588u: goto P_0c0ac588;
case 0x0c0ac58au: goto P_0c0ac58a;
case 0x0c0ac58cu: goto P_0c0ac58c;
case 0x0c0ac58eu: goto P_0c0ac58e;
case 0x0c0ac590u: goto P_0c0ac590;
case 0x0c0ac592u: goto P_0c0ac592;
case 0x0c0ac594u: goto P_0c0ac594;
case 0x0c0ac596u: goto P_0c0ac596;
case 0x0c0ac598u: goto P_0c0ac598;
case 0x0c0ac59au: goto P_0c0ac59a;
case 0x0c0ac59cu: goto P_0c0ac59c;
case 0x0c0ac59eu: goto P_0c0ac59e;
case 0x0c0ac5a0u: goto P_0c0ac5a0;
case 0x0c0ac5a2u: goto P_0c0ac5a2;
case 0x0c0ac5a4u: goto P_0c0ac5a4;
case 0x0c0ac5a6u: goto P_0c0ac5a6;
case 0x0c0ac5a8u: goto P_0c0ac5a8;
case 0x0c0ac5aau: goto P_0c0ac5aa;
case 0x0c0ac5acu: goto P_0c0ac5ac;
case 0x0c0ac5aeu: goto P_0c0ac5ae;
case 0x0c0ac5c4u: goto P_0c0ac5c4;
case 0x0c0ac5c6u: goto P_0c0ac5c6;
case 0x0c0ac5c8u: goto P_0c0ac5c8;
case 0x0c0ac5cau: goto P_0c0ac5ca;
case 0x0c0ac5ccu: goto P_0c0ac5cc;
case 0x0c0ac5ceu: goto P_0c0ac5ce;
case 0x0c0ac5d0u: goto P_0c0ac5d0;
case 0x0c0ac5d2u: goto P_0c0ac5d2;
case 0x0c0ac5d4u: goto P_0c0ac5d4;
case 0x0c0ac5d6u: goto P_0c0ac5d6;
case 0x0c0ac5d8u: goto P_0c0ac5d8;
case 0x0c0ac5dau: goto P_0c0ac5da;
case 0x0c0ac5dcu: goto P_0c0ac5dc;
case 0x0c0ac5deu: goto P_0c0ac5de;
case 0x0c0ac5e0u: goto P_0c0ac5e0;
case 0x0c0ac5e2u: goto P_0c0ac5e2;
case 0x0c0ac5e4u: goto P_0c0ac5e4;
case 0x0c0ac5e6u: goto P_0c0ac5e6;
case 0x0c0ac5e8u: goto P_0c0ac5e8;
case 0x0c0ac5eau: goto P_0c0ac5ea;
case 0x0c0ac5ecu: goto P_0c0ac5ec;
case 0x0c0ac5eeu: goto P_0c0ac5ee;
case 0x0c0ac5f0u: goto P_0c0ac5f0;
case 0x0c0ac5f2u: goto P_0c0ac5f2;
case 0x0c0ac5f4u: goto P_0c0ac5f4;
case 0x0c0ac5f6u: goto P_0c0ac5f6;
case 0x0c0ac5f8u: goto P_0c0ac5f8;
case 0x0c0ac5fau: goto P_0c0ac5fa;
case 0x0c0ac5fcu: goto P_0c0ac5fc;
case 0x0c0ac5feu: goto P_0c0ac5fe;
case 0x0c0ac600u: goto P_0c0ac600;
case 0x0c0ac602u: goto P_0c0ac602;
case 0x0c0ac604u: goto P_0c0ac604;
case 0x0c0ac606u: goto P_0c0ac606;
case 0x0c0ac608u: goto P_0c0ac608;
case 0x0c0ac60au: goto P_0c0ac60a;
case 0x0c0ac60cu: goto P_0c0ac60c;
case 0x0c0ac60eu: goto P_0c0ac60e;
case 0x0c0ac610u: goto P_0c0ac610;
case 0x0c0ac612u: goto P_0c0ac612;
case 0x0c0ac614u: goto P_0c0ac614;
case 0x0c0ac616u: goto P_0c0ac616;
case 0x0c0ac618u: goto P_0c0ac618;
case 0x0c0ac61au: goto P_0c0ac61a;
case 0x0c0ac61cu: goto P_0c0ac61c;
case 0x0c0ac61eu: goto P_0c0ac61e;
case 0x0c0ac620u: goto P_0c0ac620;
case 0x0c0ac622u: goto P_0c0ac622;
case 0x0c0ac624u: goto P_0c0ac624;
case 0x0c0ac626u: goto P_0c0ac626;
case 0x0c0ac628u: goto P_0c0ac628;
case 0x0c0ac62au: goto P_0c0ac62a;
case 0x0c0ac62cu: goto P_0c0ac62c;
case 0x0c0ac62eu: goto P_0c0ac62e;
case 0x0c0ac630u: goto P_0c0ac630;
case 0x0c0ac632u: goto P_0c0ac632;
case 0x0c0ac634u: goto P_0c0ac634;
case 0x0c0ac636u: goto P_0c0ac636;
case 0x0c0ac638u: goto P_0c0ac638;
case 0x0c0ac63au: goto P_0c0ac63a;
case 0x0c0ac63cu: goto P_0c0ac63c;
case 0x0c0ac63eu: goto P_0c0ac63e;
case 0x0c0ac640u: goto P_0c0ac640;
case 0x0c0ac642u: goto P_0c0ac642;
case 0x0c0ac644u: goto P_0c0ac644;
case 0x0c0ac646u: goto P_0c0ac646;
case 0x0c0ac648u: goto P_0c0ac648;
case 0x0c0ac64au: goto P_0c0ac64a;
case 0x0c0ac64cu: goto P_0c0ac64c;
case 0x0c0ac64eu: goto P_0c0ac64e;
case 0x0c0ac650u: goto P_0c0ac650;
case 0x0c0ac652u: goto P_0c0ac652;
case 0x0c0ac654u: goto P_0c0ac654;
case 0x0c0ac656u: goto P_0c0ac656;
case 0x0c0ac658u: goto P_0c0ac658;
case 0x0c0ac65au: goto P_0c0ac65a;
case 0x0c0ac65cu: goto P_0c0ac65c;
case 0x0c0ac65eu: goto P_0c0ac65e;
case 0x0c0ac660u: goto P_0c0ac660;
case 0x0c0ac662u: goto P_0c0ac662;
case 0x0c0ac664u: goto P_0c0ac664;
case 0x0c0ac666u: goto P_0c0ac666;
case 0x0c0ac668u: goto P_0c0ac668;
case 0x0c0ac66au: goto P_0c0ac66a;
case 0x0c0ac66cu: goto P_0c0ac66c;
case 0x0c0ac66eu: goto P_0c0ac66e;
case 0x0c0ac670u: goto P_0c0ac670;
case 0x0c0ac672u: goto P_0c0ac672;
case 0x0c0ac674u: goto P_0c0ac674;
case 0x0c0ac676u: goto P_0c0ac676;
case 0x0c0ac678u: goto P_0c0ac678;
case 0x0c0ac67au: goto P_0c0ac67a;
case 0x0c0ac67cu: goto P_0c0ac67c;
case 0x0c0ac67eu: goto P_0c0ac67e;
case 0x0c0ac680u: goto P_0c0ac680;
case 0x0c0ac682u: goto P_0c0ac682;
case 0x0c0ac684u: goto P_0c0ac684;
case 0x0c0ac686u: goto P_0c0ac686;
case 0x0c0ac688u: goto P_0c0ac688;
case 0x0c0ac68au: goto P_0c0ac68a;
case 0x0c0ac68cu: goto P_0c0ac68c;
case 0x0c0ac68eu: goto P_0c0ac68e;
case 0x0c0ac690u: goto P_0c0ac690;
case 0x0c0ac692u: goto P_0c0ac692;
case 0x0c0ac694u: goto P_0c0ac694;
case 0x0c0ac696u: goto P_0c0ac696;
case 0x0c0ac698u: goto P_0c0ac698;
case 0x0c0ac69au: goto P_0c0ac69a;
case 0x0c0ac69cu: goto P_0c0ac69c;
case 0x0c0ac69eu: goto P_0c0ac69e;
case 0x0c0ac6a0u: goto P_0c0ac6a0;
case 0x0c0ac6a2u: goto P_0c0ac6a2;
case 0x0c0ac6a4u: goto P_0c0ac6a4;
case 0x0c0ac6a6u: goto P_0c0ac6a6;
case 0x0c0ac6a8u: goto P_0c0ac6a8;
case 0x0c0ac6aau: goto P_0c0ac6aa;
case 0x0c0ac6acu: goto P_0c0ac6ac;
case 0x0c0ac6aeu: goto P_0c0ac6ae;
case 0x0c0ac6b0u: goto P_0c0ac6b0;
case 0x0c0ac6b2u: goto P_0c0ac6b2;
case 0x0c0ac6b4u: goto P_0c0ac6b4;
case 0x0c0ac6b6u: goto P_0c0ac6b6;
case 0x0c0ac6b8u: goto P_0c0ac6b8;
case 0x0c0ac6bau: goto P_0c0ac6ba;
case 0x0c0ac6dcu: goto P_0c0ac6dc;
case 0x0c0ac6deu: goto P_0c0ac6de;
case 0x0c0ac6e0u: goto P_0c0ac6e0;
case 0x0c0ac6e2u: goto P_0c0ac6e2;
case 0x0c0ac6e4u: goto P_0c0ac6e4;
case 0x0c0ac6e6u: goto P_0c0ac6e6;
case 0x0c0ac6e8u: goto P_0c0ac6e8;
case 0x0c0ac6eau: goto P_0c0ac6ea;
case 0x0c0ac6ecu: goto P_0c0ac6ec;
case 0x0c0ac6eeu: goto P_0c0ac6ee;
case 0x0c0ac6f0u: goto P_0c0ac6f0;
case 0x0c0ac6f2u: goto P_0c0ac6f2;
case 0x0c0ac6f4u: goto P_0c0ac6f4;
case 0x0c0ac6f6u: goto P_0c0ac6f6;
case 0x0c0ac6f8u: goto P_0c0ac6f8;
case 0x0c0ac6fau: goto P_0c0ac6fa;
case 0x0c0ac6fcu: goto P_0c0ac6fc;
case 0x0c0ac6feu: goto P_0c0ac6fe;
case 0x0c0ac700u: goto P_0c0ac700;
case 0x0c0ac702u: goto P_0c0ac702;
case 0x0c0ac704u: goto P_0c0ac704;
case 0x0c0ac706u: goto P_0c0ac706;
case 0x0c0ac708u: goto P_0c0ac708;
case 0x0c0ac70au: goto P_0c0ac70a;
case 0x0c0ac70cu: goto P_0c0ac70c;
case 0x0c0ac70eu: goto P_0c0ac70e;
case 0x0c0ac710u: goto P_0c0ac710;
case 0x0c0ac712u: goto P_0c0ac712;
case 0x0c0ac714u: goto P_0c0ac714;
case 0x0c0ac716u: goto P_0c0ac716;
case 0x0c0ac718u: goto P_0c0ac718;
case 0x0c0ac71au: goto P_0c0ac71a;
case 0x0c0ac71cu: goto P_0c0ac71c;
case 0x0c0ac71eu: goto P_0c0ac71e;
case 0x0c0ac720u: goto P_0c0ac720;
case 0x0c0ac722u: goto P_0c0ac722;
case 0x0c0ac724u: goto P_0c0ac724;
case 0x0c0ac726u: goto P_0c0ac726;
case 0x0c0ac728u: goto P_0c0ac728;
case 0x0c0ac72au: goto P_0c0ac72a;
case 0x0c0ac72cu: goto P_0c0ac72c;
case 0x0c0ac72eu: goto P_0c0ac72e;
case 0x0c0ac730u: goto P_0c0ac730;
case 0x0c0ac732u: goto P_0c0ac732;
case 0x0c0ac734u: goto P_0c0ac734;
case 0x0c0ac736u: goto P_0c0ac736;
case 0x0c0ac738u: goto P_0c0ac738;
case 0x0c0ac73au: goto P_0c0ac73a;
case 0x0c0ac73cu: goto P_0c0ac73c;
case 0x0c0ac73eu: goto P_0c0ac73e;
case 0x0c0ac740u: goto P_0c0ac740;
case 0x0c0ac742u: goto P_0c0ac742;
case 0x0c0ac744u: goto P_0c0ac744;
case 0x0c0ac746u: goto P_0c0ac746;
case 0x0c0ac748u: goto P_0c0ac748;
case 0x0c0ac74au: goto P_0c0ac74a;
case 0x0c0ac74cu: goto P_0c0ac74c;
case 0x0c0ac74eu: goto P_0c0ac74e;
case 0x0c0ac750u: goto P_0c0ac750;
case 0x0c0ac752u: goto P_0c0ac752;
case 0x0c0ac754u: goto P_0c0ac754;
case 0x0c0ac756u: goto P_0c0ac756;
case 0x0c0ac758u: goto P_0c0ac758;
case 0x0c0ac75au: goto P_0c0ac75a;
case 0x0c0ac75cu: goto P_0c0ac75c;
case 0x0c0ac75eu: goto P_0c0ac75e;
case 0x0c0ac760u: goto P_0c0ac760;
case 0x0c0ac762u: goto P_0c0ac762;
case 0x0c0ac764u: goto P_0c0ac764;
case 0x0c0ac766u: goto P_0c0ac766;
case 0x0c0ac768u: goto P_0c0ac768;
case 0x0c0ac76au: goto P_0c0ac76a;
case 0x0c0ac76cu: goto P_0c0ac76c;
case 0x0c0ac76eu: goto P_0c0ac76e;
case 0x0c0ac770u: goto P_0c0ac770;
case 0x0c0ac772u: goto P_0c0ac772;
case 0x0c0ac774u: goto P_0c0ac774;
case 0x0c0ac776u: goto P_0c0ac776;
case 0x0c0ac778u: goto P_0c0ac778;
case 0x0c0ac77au: goto P_0c0ac77a;
case 0x0c0ac77cu: goto P_0c0ac77c;
case 0x0c0ac77eu: goto P_0c0ac77e;
case 0x0c0ac780u: goto P_0c0ac780;
case 0x0c0ac782u: goto P_0c0ac782;
case 0x0c0ac784u: goto P_0c0ac784;
case 0x0c0ac786u: goto P_0c0ac786;
case 0x0c0ac794u: goto P_0c0ac794;
case 0x0c0ac796u: goto P_0c0ac796;
case 0x0c0ac798u: goto P_0c0ac798;
case 0x0c0ac79au: goto P_0c0ac79a;
case 0x0c0ac79cu: goto P_0c0ac79c;
case 0x0c0ac79eu: goto P_0c0ac79e;
case 0x0c0ac7a0u: goto P_0c0ac7a0;
case 0x0c0ac7a2u: goto P_0c0ac7a2;
case 0x0c0ac7a4u: goto P_0c0ac7a4;
case 0x0c0ac7a6u: goto P_0c0ac7a6;
case 0x0c0ac7a8u: goto P_0c0ac7a8;
case 0x0c0ac7aau: goto P_0c0ac7aa;
case 0x0c0ac7acu: goto P_0c0ac7ac;
case 0x0c0ac7aeu: goto P_0c0ac7ae;
case 0x0c0ac7b0u: goto P_0c0ac7b0;
case 0x0c0ac7b2u: goto P_0c0ac7b2;
case 0x0c0ac7b4u: goto P_0c0ac7b4;
case 0x0c0ac7b6u: goto P_0c0ac7b6;
case 0x0c0ac7b8u: goto P_0c0ac7b8;
case 0x0c0ac7bau: goto P_0c0ac7ba;
case 0x0c0ac7bcu: goto P_0c0ac7bc;
case 0x0c0ac7beu: goto P_0c0ac7be;
case 0x0c0ac7c0u: goto P_0c0ac7c0;
case 0x0c0ac7c2u: goto P_0c0ac7c2;
case 0x0c0ac7c4u: goto P_0c0ac7c4;
case 0x0c0ac7c6u: goto P_0c0ac7c6;
case 0x0c0ac7c8u: goto P_0c0ac7c8;
case 0x0c0ac7cau: goto P_0c0ac7ca;
case 0x0c0ac7ccu: goto P_0c0ac7cc;
case 0x0c0ac7ceu: goto P_0c0ac7ce;
case 0x0c0ac7d0u: goto P_0c0ac7d0;
case 0x0c0ac7d2u: goto P_0c0ac7d2;
case 0x0c0ac7d4u: goto P_0c0ac7d4;
case 0x0c0ac7d6u: goto P_0c0ac7d6;
case 0x0c0ac7d8u: goto P_0c0ac7d8;
case 0x0c0ac7dau: goto P_0c0ac7da;
case 0x0c0ac7dcu: goto P_0c0ac7dc;
case 0x0c0ac7deu: goto P_0c0ac7de;
case 0x0c0ac7e0u: goto P_0c0ac7e0;
case 0x0c0ac7e2u: goto P_0c0ac7e2;
case 0x0c0ac7e4u: goto P_0c0ac7e4;
case 0x0c0ac7e6u: goto P_0c0ac7e6;
case 0x0c0ac7e8u: goto P_0c0ac7e8;
case 0x0c0ac7eau: goto P_0c0ac7ea;
case 0x0c0ac7ecu: goto P_0c0ac7ec;
case 0x0c0ac7eeu: goto P_0c0ac7ee;
case 0x0c0ac7f0u: goto P_0c0ac7f0;
case 0x0c0ac7f2u: goto P_0c0ac7f2;
case 0x0c0ac7f4u: goto P_0c0ac7f4;
case 0x0c0ac7f6u: goto P_0c0ac7f6;
case 0x0c0ac7f8u: goto P_0c0ac7f8;
case 0x0c0ac7fau: goto P_0c0ac7fa;
case 0x0c0ac7fcu: goto P_0c0ac7fc;
case 0x0c0ac7feu: goto P_0c0ac7fe;
case 0x0c0ac800u: goto P_0c0ac800;
case 0x0c0ac802u: goto P_0c0ac802;
case 0x0c0ac804u: goto P_0c0ac804;
case 0x0c0ac806u: goto P_0c0ac806;
case 0x0c0ac808u: goto P_0c0ac808;
case 0x0c0ac80au: goto P_0c0ac80a;
case 0x0c0ac80cu: goto P_0c0ac80c;
case 0x0c0ac80eu: goto P_0c0ac80e;
case 0x0c0ac810u: goto P_0c0ac810;
case 0x0c0ac812u: goto P_0c0ac812;
case 0x0c0ac814u: goto P_0c0ac814;
case 0x0c0ac816u: goto P_0c0ac816;
case 0x0c0ac818u: goto P_0c0ac818;
case 0x0c0ac81au: goto P_0c0ac81a;
case 0x0c0ac81cu: goto P_0c0ac81c;
case 0x0c0ac81eu: goto P_0c0ac81e;
case 0x0c0ac820u: goto P_0c0ac820;
case 0x0c0ac822u: goto P_0c0ac822;
case 0x0c0ac824u: goto P_0c0ac824;
case 0x0c0ac826u: goto P_0c0ac826;
case 0x0c0ac828u: goto P_0c0ac828;
case 0x0c0ac82au: goto P_0c0ac82a;
case 0x0c0ac82cu: goto P_0c0ac82c;
case 0x0c0ac82eu: goto P_0c0ac82e;
case 0x0c0ac830u: goto P_0c0ac830;
case 0x0c0ac832u: goto P_0c0ac832;
case 0x0c0ac834u: goto P_0c0ac834;
case 0x0c0ac836u: goto P_0c0ac836;
case 0x0c0ac838u: goto P_0c0ac838;
case 0x0c0ac83au: goto P_0c0ac83a;
case 0x0c0ac83cu: goto P_0c0ac83c;
case 0x0c0ac83eu: goto P_0c0ac83e;
case 0x0c0ac840u: goto P_0c0ac840;
case 0x0c0ac842u: goto P_0c0ac842;
case 0x0c0ac844u: goto P_0c0ac844;
case 0x0c0ac850u: goto P_0c0ac850;
case 0x0c0ac852u: goto P_0c0ac852;
case 0x0c0ac854u: goto P_0c0ac854;
case 0x0c0ac856u: goto P_0c0ac856;
case 0x0c0ac858u: goto P_0c0ac858;
case 0x0c0ac85au: goto P_0c0ac85a;
case 0x0c0ac85cu: goto P_0c0ac85c;
case 0x0c0ac85eu: goto P_0c0ac85e;
case 0x0c0ac860u: goto P_0c0ac860;
case 0x0c0ac862u: goto P_0c0ac862;
case 0x0c0ac864u: goto P_0c0ac864;
case 0x0c0ac866u: goto P_0c0ac866;
case 0x0c0ac868u: goto P_0c0ac868;
case 0x0c0ac86au: goto P_0c0ac86a;
case 0x0c0ac86cu: goto P_0c0ac86c;
case 0x0c0ac86eu: goto P_0c0ac86e;
case 0x0c0ac870u: goto P_0c0ac870;
case 0x0c0ac872u: goto P_0c0ac872;
case 0x0c0ac874u: goto P_0c0ac874;
case 0x0c0ac876u: goto P_0c0ac876;
case 0x0c0ac878u: goto P_0c0ac878;
case 0x0c0ac87au: goto P_0c0ac87a;
case 0x0c0ac87cu: goto P_0c0ac87c;
case 0x0c0ac87eu: goto P_0c0ac87e;
case 0x0c0ac880u: goto P_0c0ac880;
case 0x0c0ac882u: goto P_0c0ac882;
case 0x0c0ac884u: goto P_0c0ac884;
case 0x0c0ac886u: goto P_0c0ac886;
case 0x0c0ac888u: goto P_0c0ac888;
case 0x0c0ac88au: goto P_0c0ac88a;
case 0x0c0ac88cu: goto P_0c0ac88c;
case 0x0c0ac88eu: goto P_0c0ac88e;
case 0x0c0ac890u: goto P_0c0ac890;
case 0x0c0ac892u: goto P_0c0ac892;
case 0x0c0ac894u: goto P_0c0ac894;
case 0x0c0ac896u: goto P_0c0ac896;
case 0x0c0ac898u: goto P_0c0ac898;
case 0x0c0ac89au: goto P_0c0ac89a;
case 0x0c0ac89cu: goto P_0c0ac89c;
case 0x0c0ac89eu: goto P_0c0ac89e;
case 0x0c0ac8a0u: goto P_0c0ac8a0;
case 0x0c0ac8a2u: goto P_0c0ac8a2;
case 0x0c0ac8a4u: goto P_0c0ac8a4;
case 0x0c0ac8a6u: goto P_0c0ac8a6;
case 0x0c0ac8a8u: goto P_0c0ac8a8;
case 0x0c0ac8aau: goto P_0c0ac8aa;
case 0x0c0ac8acu: goto P_0c0ac8ac;
case 0x0c0ac8aeu: goto P_0c0ac8ae;
case 0x0c0ac8b0u: goto P_0c0ac8b0;
case 0x0c0ac8b2u: goto P_0c0ac8b2;
case 0x0c0ac8b4u: goto P_0c0ac8b4;
case 0x0c0ac8b6u: goto P_0c0ac8b6;
case 0x0c0ac8b8u: goto P_0c0ac8b8;
case 0x0c0ac8bau: goto P_0c0ac8ba;
case 0x0c0ac8bcu: goto P_0c0ac8bc;
case 0x0c0ac8beu: goto P_0c0ac8be;
case 0x0c0ac8c0u: goto P_0c0ac8c0;
case 0x0c0ac8c2u: goto P_0c0ac8c2;
case 0x0c0ac8c4u: goto P_0c0ac8c4;
case 0x0c0ac8c6u: goto P_0c0ac8c6;
case 0x0c0ac8c8u: goto P_0c0ac8c8;
case 0x0c0ac8cau: goto P_0c0ac8ca;
case 0x0c0ac8ccu: goto P_0c0ac8cc;
case 0x0c0ac8ceu: goto P_0c0ac8ce;
case 0x0c0ac8d0u: goto P_0c0ac8d0;
case 0x0c0ac8d2u: goto P_0c0ac8d2;
case 0x0c0ac8d4u: goto P_0c0ac8d4;
case 0x0c0ac8d6u: goto P_0c0ac8d6;
case 0x0c0ac8d8u: goto P_0c0ac8d8;
case 0x0c0ac8dau: goto P_0c0ac8da;
case 0x0c0ac8dcu: goto P_0c0ac8dc;
case 0x0c0ac8deu: goto P_0c0ac8de;
case 0x0c0ac8e0u: goto P_0c0ac8e0;
case 0x0c0ac8e2u: goto P_0c0ac8e2;
case 0x0c0ac8e4u: goto P_0c0ac8e4;
case 0x0c0ac8e6u: goto P_0c0ac8e6;
case 0x0c0ac8e8u: goto P_0c0ac8e8;
case 0x0c0ac8eau: goto P_0c0ac8ea;
case 0x0c0ac8ecu: goto P_0c0ac8ec;
case 0x0c0ac8eeu: goto P_0c0ac8ee;
case 0x0c0ac8f0u: goto P_0c0ac8f0;
case 0x0c0ac8f2u: goto P_0c0ac8f2;
case 0x0c0ac8f4u: goto P_0c0ac8f4;
case 0x0c0ac8f6u: goto P_0c0ac8f6;
case 0x0c0ac8f8u: goto P_0c0ac8f8;
case 0x0c0ac8fau: goto P_0c0ac8fa;
case 0x0c0ac8fcu: goto P_0c0ac8fc;
case 0x0c0ac8feu: goto P_0c0ac8fe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0abfa2: /* original 2fe6, guest PC 0x0c0abfa2 */
if(!s->budget--) { s->failed_pc=0x0c0abfa2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abfa4;
P_0c0abfa4: /* original 6e43, guest PC 0x0c0abfa4 */
if(!s->budget--) { s->failed_pc=0x0c0abfa4u; return 0; }
r[14]=r[4];
goto P_0c0abfa6;
P_0c0abfa6: /* original fffb, guest PC 0x0c0abfa6 */
if(!s->budget--) { s->failed_pc=0x0c0abfa6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0abfa8;
P_0c0abfa8: /* original ffeb, guest PC 0x0c0abfa8 */
if(!s->budget--) { s->failed_pc=0x0c0abfa8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0abfaa;
P_0c0abfaa: /* original ffdb, guest PC 0x0c0abfaa */
if(!s->budget--) { s->failed_pc=0x0c0abfaau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0abfac;
P_0c0abfac: /* original ffcb, guest PC 0x0c0abfac */
if(!s->budget--) { s->failed_pc=0x0c0abfacu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0abfae;
P_0c0abfae: /* original 4f22, guest PC 0x0c0abfae */
if(!s->budget--) { s->failed_pc=0x0c0abfaeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abfb0;
P_0c0abfb0: /* original 7fe8, guest PC 0x0c0abfb0 */
if(!s->budget--) { s->failed_pc=0x0c0abfb0u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0abfb2;
P_0c0abfb2: /* original 1f55, guest PC 0x0c0abfb2 */
if(!s->budget--) { s->failed_pc=0x0c0abfb2u; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c0abfb4;
P_0c0abfb4: /* original 65f3, guest PC 0x0c0abfb4 */
if(!s->budget--) { s->failed_pc=0x0c0abfb4u; return 0; }
r[5]=r[15];
goto P_0c0abfb6;
P_0c0abfb6: /* original 9052, guest PC 0x0c0abfb6 */
if(!s->budget--) { s->failed_pc=0x0c0abfb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac05eu,2);
goto P_0c0abfb8;
P_0c0abfb8: /* original 66f3, guest PC 0x0c0abfb8 */
if(!s->budget--) { s->failed_pc=0x0c0abfb8u; return 0; }
r[6]=r[15];
goto P_0c0abfba;
P_0c0abfba: /* original d32b, guest PC 0x0c0abfba */
if(!s->budget--) { s->failed_pc=0x0c0abfbau; return 0; }
r[3]=read(ram,0x0c0ac068u,4);
goto P_0c0abfbc;
P_0c0abfbc: /* original 67f3, guest PC 0x0c0abfbc */
if(!s->budget--) { s->failed_pc=0x0c0abfbcu; return 0; }
r[7]=r[15];
goto P_0c0abfbe;
P_0c0abfbe: /* original 04ee, guest PC 0x0c0abfbe */
if(!s->budget--) { s->failed_pc=0x0c0abfbeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0abfc0;
P_0c0abfc0: /* original e008, guest PC 0x0c0abfc0 */
if(!s->budget--) { s->failed_pc=0x0c0abfc0u; return 0; }
r[0]=0x00000008u;
goto P_0c0abfc2;
P_0c0abfc2: /* original 7610, guest PC 0x0c0abfc2 */
if(!s->budget--) { s->failed_pc=0x0c0abfc2u; return 0; }
r[6]+=0x00000010u;
goto P_0c0abfc4;
P_0c0abfc4: /* original 7418, guest PC 0x0c0abfc4 */
if(!s->budget--) { s->failed_pc=0x0c0abfc4u; return 0; }
r[4]+=0x00000018u;
goto P_0c0abfc6;
P_0c0abfc6: /* original fe46, guest PC 0x0c0abfc6 */
if(!s->budget--) { s->failed_pc=0x0c0abfc6u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c0abfc8;
P_0c0abfc8: /* original 7704, guest PC 0x0c0abfc8 */
if(!s->budget--) { s->failed_pc=0x0c0abfc8u; return 0; }
r[7]+=0x00000004u;
goto P_0c0abfca;
P_0c0abfca: /* original ff48, guest PC 0x0c0abfca */
if(!s->budget--) { s->failed_pc=0x0c0abfcau; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
goto P_0c0abfcc;
P_0c0abfcc: /* original 64f3, guest PC 0x0c0abfcc */
if(!s->budget--) { s->failed_pc=0x0c0abfccu; return 0; }
r[4]=r[15];
goto P_0c0abfce;
P_0c0abfce: /* original f5ec, guest PC 0x0c0abfce */
if(!s->budget--) { s->failed_pc=0x0c0abfceu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0abfd0;
P_0c0abfd0: /* original 7508, guest PC 0x0c0abfd0 */
if(!s->budget--) { s->failed_pc=0x0c0abfd0u; return 0; }
r[5]+=0x00000008u;
goto P_0c0abfd2;
P_0c0abfd2: /* original f54d, guest PC 0x0c0abfd2 */
if(!s->budget--) { s->failed_pc=0x0c0abfd2u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0abfd4;
P_0c0abfd4: /* original 430b, guest PC 0x0c0abfd4 */
if(!s->budget--) { s->failed_pc=0x0c0abfd4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0abfd8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abfd8u) { target=s->pc; goto dispatch; }
goto P_0c0abfd8;
P_0c0abfd6: /* original f4fc, guest PC 0x0c0abfd6 */
if(!s->budget--) { s->failed_pc=0x0c0abfd6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0abfd8;
P_0c0abfd8: /* original 52f1, guest PC 0x0c0abfd8 */
if(!s->budget--) { s->failed_pc=0x0c0abfd8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0abfda;
P_0c0abfda: /* original d324, guest PC 0x0c0abfda */
if(!s->budget--) { s->failed_pc=0x0c0abfdau; return 0; }
r[3]=read(ram,0x0c0ac06cu,4);
goto P_0c0abfdc;
P_0c0abfdc: /* original 223a, guest PC 0x0c0abfdc */
if(!s->budget--) { s->failed_pc=0x0c0abfdcu; return 0; }
r[2]^=r[3];
goto P_0c0abfde;
P_0c0abfde: /* original 1f21, guest PC 0x0c0abfde */
if(!s->budget--) { s->failed_pc=0x0c0abfdeu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0abfe0;
P_0c0abfe0: /* original 903e, guest PC 0x0c0abfe0 */
if(!s->budget--) { s->failed_pc=0x0c0abfe0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac060u,2);
goto P_0c0abfe2;
P_0c0abfe2: /* original f3e6, guest PC 0x0c0abfe2 */
if(!s->budget--) { s->failed_pc=0x0c0abfe2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abfe4;
P_0c0abfe4: /* original e00c, guest PC 0x0c0abfe4 */
if(!s->budget--) { s->failed_pc=0x0c0abfe4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0abfe6;
P_0c0abfe6: /* original ff37, guest PC 0x0c0abfe6 */
if(!s->budget--) { s->failed_pc=0x0c0abfe6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0abfe8;
P_0c0abfe8: /* original e008, guest PC 0x0c0abfe8 */
if(!s->budget--) { s->failed_pc=0x0c0abfe8u; return 0; }
r[0]=0x00000008u;
goto P_0c0abfea;
P_0c0abfea: /* original fcf6, guest PC 0x0c0abfea */
if(!s->budget--) { s->failed_pc=0x0c0abfeau; return 0; }
vf3_matrix_load(s,ram,12,r[15]+r[0]);
goto P_0c0abfec;
P_0c0abfec: /* original 54f1, guest PC 0x0c0abfec */
if(!s->budget--) { s->failed_pc=0x0c0abfecu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0abfee;
P_0c0abfee: /* original d220, guest PC 0x0c0abfee */
if(!s->budget--) { s->failed_pc=0x0c0abfeeu; return 0; }
r[2]=read(ram,0x0c0ac070u,4);
goto P_0c0abff0;
P_0c0abff0: /* original fdf8, guest PC 0x0c0abff0 */
if(!s->budget--) { s->failed_pc=0x0c0abff0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
goto P_0c0abff2;
P_0c0abff2: /* original fc4d, guest PC 0x0c0abff2 */
if(!s->budget--) { s->failed_pc=0x0c0abff2u; return 0; }
fr[12]^=0x80000000u;
goto P_0c0abff4;
P_0c0abff4: /* original 420b, guest PC 0x0c0abff4 */
if(!s->budget--) { s->failed_pc=0x0c0abff4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0abff8u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abff8u) { target=s->pc; goto dispatch; }
goto P_0c0abff8;
P_0c0abff6: /* original 644f, guest PC 0x0c0abff6 */
if(!s->budget--) { s->failed_pc=0x0c0abff6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0abff8;
P_0c0abff8: /* original ff0a, guest PC 0x0c0abff8 */
if(!s->budget--) { s->failed_pc=0x0c0abff8u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0abffa;
P_0c0abffa: /* original d31e, guest PC 0x0c0abffa */
if(!s->budget--) { s->failed_pc=0x0c0abffau; return 0; }
r[3]=read(ram,0x0c0ac074u,4);
goto P_0c0abffc;
P_0c0abffc: /* original 54f1, guest PC 0x0c0abffc */
if(!s->budget--) { s->failed_pc=0x0c0abffcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0abffe;
P_0c0abffe: /* original 430b, guest PC 0x0c0abffe */
if(!s->budget--) { s->failed_pc=0x0c0abffeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ac002u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac002u) { target=s->pc; goto dispatch; }
goto P_0c0ac002;
P_0c0ac000: /* original 644f, guest PC 0x0c0ac000 */
if(!s->budget--) { s->failed_pc=0x0c0ac000u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ac002;
P_0c0ac002: /* original e00c, guest PC 0x0c0ac002 */
if(!s->budget--) { s->failed_pc=0x0c0ac002u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ac004;
P_0c0ac004: /* original f3f8, guest PC 0x0c0ac004 */
if(!s->budget--) { s->failed_pc=0x0c0ac004u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ac006;
P_0c0ac006: /* original f2f6, guest PC 0x0c0ac006 */
if(!s->budget--) { s->failed_pc=0x0c0ac006u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ac008;
P_0c0ac008: /* original e00c, guest PC 0x0c0ac008 */
if(!s->budget--) { s->failed_pc=0x0c0ac008u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ac00a;
P_0c0ac00a: /* original f40c, guest PC 0x0c0ac00a */
if(!s->budget--) { s->failed_pc=0x0c0ac00au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0ac00c;
P_0c0ac00c: /* original f232, guest PC 0x0c0ac00c */
if(!s->budget--) { s->failed_pc=0x0c0ac00cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0ac00e;
P_0c0ac00e: /* original fd20, guest PC 0x0c0ac00e */
if(!s->budget--) { s->failed_pc=0x0c0ac00eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[2],r[18],'+');
goto P_0c0ac010;
P_0c0ac010: /* original ff2a, guest PC 0x0c0ac010 */
if(!s->budget--) { s->failed_pc=0x0c0ac010u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0ac012;
P_0c0ac012: /* original f34c, guest PC 0x0c0ac012 */
if(!s->budget--) { s->failed_pc=0x0c0ac012u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ac014;
P_0c0ac014: /* original f4f6, guest PC 0x0c0ac014 */
if(!s->budget--) { s->failed_pc=0x0c0ac014u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ac016;
P_0c0ac016: /* original e010, guest PC 0x0c0ac016 */
if(!s->budget--) { s->failed_pc=0x0c0ac016u; return 0; }
r[0]=0x00000010u;
goto P_0c0ac018;
P_0c0ac018: /* original f2e6, guest PC 0x0c0ac018 */
if(!s->budget--) { s->failed_pc=0x0c0ac018u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ac01a;
P_0c0ac01a: /* original e018, guest PC 0x0c0ac01a */
if(!s->budget--) { s->failed_pc=0x0c0ac01au; return 0; }
r[0]=0x00000018u;
goto P_0c0ac01c;
P_0c0ac01c: /* original f432, guest PC 0x0c0ac01c */
if(!s->budget--) { s->failed_pc=0x0c0ac01cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0ac01e;
P_0c0ac01e: /* original f3fc, guest PC 0x0c0ac01e */
if(!s->budget--) { s->failed_pc=0x0c0ac01eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0ac020;
P_0c0ac020: /* original ffdc, guest PC 0x0c0ac020 */
if(!s->budget--) { s->failed_pc=0x0c0ac020u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0ac022;
P_0c0ac022: /* original ff31, guest PC 0x0c0ac022 */
if(!s->budget--) { s->failed_pc=0x0c0ac022u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c0ac024;
P_0c0ac024: /* original f3ec, guest PC 0x0c0ac024 */
if(!s->budget--) { s->failed_pc=0x0c0ac024u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0ac026;
P_0c0ac026: /* original fc40, guest PC 0x0c0ac026 */
if(!s->budget--) { s->failed_pc=0x0c0ac026u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'+');
goto P_0c0ac028;
P_0c0ac028: /* original fecc, guest PC 0x0c0ac028 */
if(!s->budget--) { s->failed_pc=0x0c0ac028u; return 0; }
vf3_matrix_move(s,14,12);
goto P_0c0ac02a;
P_0c0ac02a: /* original fe31, guest PC 0x0c0ac02a */
if(!s->budget--) { s->failed_pc=0x0c0ac02au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0ac02c;
P_0c0ac02c: /* original ff2a, guest PC 0x0c0ac02c */
if(!s->budget--) { s->failed_pc=0x0c0ac02cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0ac02e;
P_0c0ac02e: /* original f32c, guest PC 0x0c0ac02e */
if(!s->budget--) { s->failed_pc=0x0c0ac02eu; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0ac030;
P_0c0ac030: /* original f3f0, guest PC 0x0c0ac030 */
if(!s->budget--) { s->failed_pc=0x0c0ac030u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'+');
goto P_0c0ac032;
P_0c0ac032: /* original f4e6, guest PC 0x0c0ac032 */
if(!s->budget--) { s->failed_pc=0x0c0ac032u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0ac034;
P_0c0ac034: /* original e010, guest PC 0x0c0ac034 */
if(!s->budget--) { s->failed_pc=0x0c0ac034u; return 0; }
r[0]=0x00000010u;
goto P_0c0ac036;
P_0c0ac036: /* original f4e0, guest PC 0x0c0ac036 */
if(!s->budget--) { s->failed_pc=0x0c0ac036u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'+');
goto P_0c0ac038;
P_0c0ac038: /* original ff3a, guest PC 0x0c0ac038 */
if(!s->budget--) { s->failed_pc=0x0c0ac038u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ac03a;
P_0c0ac03a: /* original fe37, guest PC 0x0c0ac03a */
if(!s->budget--) { s->failed_pc=0x0c0ac03au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac03c;
P_0c0ac03c: /* original e018, guest PC 0x0c0ac03c */
if(!s->budget--) { s->failed_pc=0x0c0ac03cu; return 0; }
r[0]=0x00000018u;
goto P_0c0ac03e;
P_0c0ac03e: /* original fe47, guest PC 0x0c0ac03e */
if(!s->budget--) { s->failed_pc=0x0c0ac03eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ac040;
P_0c0ac040: /* original 55f5, guest PC 0x0c0ac040 */
if(!s->budget--) { s->failed_pc=0x0c0ac040u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0ac042;
P_0c0ac042: /* original b04a, guest PC 0x0c0ac042 */
if(!s->budget--) { s->failed_pc=0x0c0ac042u; return 0; }
target=code_base|0x0c0ac0dau; r[16]=code_base|0x0c0ac046u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac046u) { target=s->pc; goto dispatch; }
goto P_0c0ac046;
P_0c0ac044: /* original 64e3, guest PC 0x0c0ac044 */
if(!s->budget--) { s->failed_pc=0x0c0ac044u; return 0; }
r[4]=r[14];
goto P_0c0ac046;
P_0c0ac046: /* original 7f18, guest PC 0x0c0ac046 */
if(!s->budget--) { s->failed_pc=0x0c0ac046u; return 0; }
r[15]+=0x00000018u;
goto P_0c0ac048;
P_0c0ac048: /* original 4f26, guest PC 0x0c0ac048 */
if(!s->budget--) { s->failed_pc=0x0c0ac048u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac04a;
P_0c0ac04a: /* original fcf9, guest PC 0x0c0ac04a */
if(!s->budget--) { s->failed_pc=0x0c0ac04au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac04c;
P_0c0ac04c: /* original fdf9, guest PC 0x0c0ac04c */
if(!s->budget--) { s->failed_pc=0x0c0ac04cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac04e;
P_0c0ac04e: /* original fef9, guest PC 0x0c0ac04e */
if(!s->budget--) { s->failed_pc=0x0c0ac04eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac050;
P_0c0ac050: /* original fff9, guest PC 0x0c0ac050 */
if(!s->budget--) { s->failed_pc=0x0c0ac050u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac052;
P_0c0ac052: /* original 000b, guest PC 0x0c0ac052 */
if(!s->budget--) { s->failed_pc=0x0c0ac052u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac054: /* original 6ef6, guest PC 0x0c0ac054 */
if(!s->budget--) { s->failed_pc=0x0c0ac054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ac056u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac056u; return 0; } return 1;
P_0c0ac0da: /* original 6242, guest PC 0x0c0ac0da */
if(!s->budget--) { s->failed_pc=0x0c0ac0dau; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0ac0dc;
P_0c0ac0dc: /* original d327, guest PC 0x0c0ac0dc */
if(!s->budget--) { s->failed_pc=0x0c0ac0dcu; return 0; }
r[3]=read(ram,0x0c0ac17cu,4);
goto P_0c0ac0de;
P_0c0ac0de: /* original 2238, guest PC 0x0c0ac0de */
if(!s->budget--) { s->failed_pc=0x0c0ac0deu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac0e0;
P_0c0ac0e0: /* original 8b0e, guest PC 0x0c0ac0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac100; }
goto P_0c0ac0e2;
P_0c0ac0e2: /* original 9044, guest PC 0x0c0ac0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16eu,2);
goto P_0c0ac0e4;
P_0c0ac0e4: /* original e13e, guest PC 0x0c0ac0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e4u; return 0; }
r[1]=0x0000003eu;
goto P_0c0ac0e6;
P_0c0ac0e6: /* original 314c, guest PC 0x0c0ac0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e6u; return 0; }
r[1]+=r[4];
goto P_0c0ac0e8;
P_0c0ac0e8: /* original 004d, guest PC 0x0c0ac0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ac0ea;
P_0c0ac0ea: /* original 2101, guest PC 0x0c0ac0ea */
if(!s->budget--) { s->failed_pc=0x0c0ac0eau; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0ac0ec;
P_0c0ac0ec: /* original 903c, guest PC 0x0c0ac0ec */
if(!s->budget--) { s->failed_pc=0x0c0ac0ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac168u,2);
goto P_0c0ac0ee;
P_0c0ac0ee: /* original d624, guest PC 0x0c0ac0ee */
if(!s->budget--) { s->failed_pc=0x0c0ac0eeu; return 0; }
r[6]=read(ram,0x0c0ac180u,4);
goto P_0c0ac0f0;
P_0c0ac0f0: /* original 034e, guest PC 0x0c0ac0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f0u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0ac0f2;
P_0c0ac0f2: /* original 2638, guest PC 0x0c0ac0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0ac0f4;
P_0c0ac0f4: /* original 8902, guest PC 0x0c0ac0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac0fc; }
goto P_0c0ac0f6;
P_0c0ac0f6: /* original 903b, guest PC 0x0c0ac0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac170u,2);
goto P_0c0ac0f8;
P_0c0ac0f8: /* original e101, guest PC 0x0c0ac0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f8u; return 0; }
r[1]=0x00000001u;
goto P_0c0ac0fa;
P_0c0ac0fa: /* original 0414, guest PC 0x0c0ac0fa */
if(!s->budget--) { s->failed_pc=0x0c0ac0fau; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0ac0fc;
P_0c0ac0fc: /* original a020, guest PC 0x0c0ac0fc */
if(!s->budget--) { s->failed_pc=0x0c0ac0fcu; return 0; }
goto P_0c0ac140;
P_0c0ac0fe: /* original 0009, guest PC 0x0c0ac0fe */
if(!s->budget--) { s->failed_pc=0x0c0ac0feu; return 0; }
goto P_0c0ac100;
P_0c0ac100: /* original 000b, guest PC 0x0c0ac100 */
if(!s->budget--) { s->failed_pc=0x0c0ac100u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ac102: /* original 0009, guest PC 0x0c0ac102 */
if(!s->budget--) { s->failed_pc=0x0c0ac102u; return 0; }
if(!vf3_matrix_family(0x0c0ac104u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac104u; return 0; } return 1;
P_0c0ac140: /* original 2fe6, guest PC 0x0c0ac140 */
if(!s->budget--) { s->failed_pc=0x0c0ac140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac142;
P_0c0ac142: /* original 6e43, guest PC 0x0c0ac142 */
if(!s->budget--) { s->failed_pc=0x0c0ac142u; return 0; }
r[14]=r[4];
goto P_0c0ac144;
P_0c0ac144: /* original 4f22, guest PC 0x0c0ac144 */
if(!s->budget--) { s->failed_pc=0x0c0ac144u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac146;
P_0c0ac146: /* original 7ffc, guest PC 0x0c0ac146 */
if(!s->budget--) { s->failed_pc=0x0c0ac146u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ac148;
P_0c0ac148: /* original 2f52, guest PC 0x0c0ac148 */
if(!s->budget--) { s->failed_pc=0x0c0ac148u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ac14a;
P_0c0ac14a: /* original 65e3, guest PC 0x0c0ac14a */
if(!s->budget--) { s->failed_pc=0x0c0ac14au; return 0; }
r[5]=r[14];
goto P_0c0ac14c;
P_0c0ac14c: /* original d30d, guest PC 0x0c0ac14c */
if(!s->budget--) { s->failed_pc=0x0c0ac14cu; return 0; }
r[3]=read(ram,0x0c0ac184u,4);
goto P_0c0ac14e;
P_0c0ac14e: /* original 430b, guest PC 0x0c0ac14e */
if(!s->budget--) { s->failed_pc=0x0c0ac14eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ac152u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac152u) { target=s->pc; goto dispatch; }
goto P_0c0ac152;
P_0c0ac150: /* original e400, guest PC 0x0c0ac150 */
if(!s->budget--) { s->failed_pc=0x0c0ac150u; return 0; }
r[4]=0x00000000u;
goto P_0c0ac152;
P_0c0ac152: /* original d20d, guest PC 0x0c0ac152 */
if(!s->budget--) { s->failed_pc=0x0c0ac152u; return 0; }
r[2]=read(ram,0x0c0ac188u,4);
goto P_0c0ac154;
P_0c0ac154: /* original 420b, guest PC 0x0c0ac154 */
if(!s->budget--) { s->failed_pc=0x0c0ac154u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ac158u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac158u) { target=s->pc; goto dispatch; }
goto P_0c0ac158;
P_0c0ac156: /* original 64e3, guest PC 0x0c0ac156 */
if(!s->budget--) { s->failed_pc=0x0c0ac156u; return 0; }
r[4]=r[14];
goto P_0c0ac158;
P_0c0ac158: /* original 65f2, guest PC 0x0c0ac158 */
if(!s->budget--) { s->failed_pc=0x0c0ac158u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ac15a;
P_0c0ac15a: /* original 7f04, guest PC 0x0c0ac15a */
if(!s->budget--) { s->failed_pc=0x0c0ac15au; return 0; }
r[15]+=0x00000004u;
goto P_0c0ac15c;
P_0c0ac15c: /* original 4f26, guest PC 0x0c0ac15c */
if(!s->budget--) { s->failed_pc=0x0c0ac15cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac15e;
P_0c0ac15e: /* original 64e3, guest PC 0x0c0ac15e */
if(!s->budget--) { s->failed_pc=0x0c0ac15eu; return 0; }
r[4]=r[14];
goto P_0c0ac160;
P_0c0ac160: /* original a035, guest PC 0x0c0ac160 */
if(!s->budget--) { s->failed_pc=0x0c0ac160u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac1ce;
P_0c0ac162: /* original 6ef6, guest PC 0x0c0ac162 */
if(!s->budget--) { s->failed_pc=0x0c0ac162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ac164u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac164u; return 0; } return 1;
P_0c0ac1ce: /* original e304, guest PC 0x0c0ac1ce */
if(!s->budget--) { s->failed_pc=0x0c0ac1ceu; return 0; }
r[3]=0x00000004u;
goto P_0c0ac1d0;
P_0c0ac1d0: /* original e062, guest PC 0x0c0ac1d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d0u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac1d2;
P_0c0ac1d2: /* original 6233, guest PC 0x0c0ac1d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d2u; return 0; }
r[2]=r[3];
goto P_0c0ac1d4;
P_0c0ac1d4: /* original 1531, guest PC 0x0c0ac1d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d4u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c0ac1d6;
P_0c0ac1d6: /* original a000, guest PC 0x0c0ac1d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d6u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ac1da;
P_0c0ac1d8: /* original 0424, guest PC 0x0c0ac1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d8u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ac1da;
P_0c0ac1da: /* original 2fe6, guest PC 0x0c0ac1da */
if(!s->budget--) { s->failed_pc=0x0c0ac1dau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac1dc;
P_0c0ac1dc: /* original e03e, guest PC 0x0c0ac1dc */
if(!s->budget--) { s->failed_pc=0x0c0ac1dcu; return 0; }
r[0]=0x0000003eu;
goto P_0c0ac1de;
P_0c0ac1de: /* original 6e43, guest PC 0x0c0ac1de */
if(!s->budget--) { s->failed_pc=0x0c0ac1deu; return 0; }
r[14]=r[4];
goto P_0c0ac1e0;
P_0c0ac1e0: /* original 03ed, guest PC 0x0c0ac1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac1e2;
P_0c0ac1e2: /* original 9055, guest PC 0x0c0ac1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac290u,2);
goto P_0c0ac1e4;
P_0c0ac1e4: /* original 4f22, guest PC 0x0c0ac1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac1e6;
P_0c0ac1e6: /* original 02ed, guest PC 0x0c0ac1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac1e8;
P_0c0ac1e8: /* original 3322, guest PC 0x0c0ac1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ac1ea;
P_0c0ac1ea: /* original 8b1b, guest PC 0x0c0ac1ea */
if(!s->budget--) { s->failed_pc=0x0c0ac1eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac224; }
goto P_0c0ac1ec;
P_0c0ac1ec: /* original e048, guest PC 0x0c0ac1ec */
if(!s->budget--) { s->failed_pc=0x0c0ac1ecu; return 0; }
r[0]=0x00000048u;
goto P_0c0ac1ee;
P_0c0ac1ee: /* original d32c, guest PC 0x0c0ac1ee */
if(!s->budget--) { s->failed_pc=0x0c0ac1eeu; return 0; }
r[3]=read(ram,0x0c0ac2a0u,4);
goto P_0c0ac1f0;
P_0c0ac1f0: /* original 02ee, guest PC 0x0c0ac1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac1f2;
P_0c0ac1f2: /* original 2238, guest PC 0x0c0ac1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac1f4;
P_0c0ac1f4: /* original 8908, guest PC 0x0c0ac1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac208; }
goto P_0c0ac1f6;
P_0c0ac1f6: /* original 61e2, guest PC 0x0c0ac1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ac1f8;
P_0c0ac1f8: /* original e000, guest PC 0x0c0ac1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f8u; return 0; }
r[0]=0x00000000u;
goto P_0c0ac1fa;
P_0c0ac1fa: /* original d22a, guest PC 0x0c0ac1fa */
if(!s->budget--) { s->failed_pc=0x0c0ac1fau; return 0; }
r[2]=read(ram,0x0c0ac2a4u,4);
goto P_0c0ac1fc;
P_0c0ac1fc: /* original 4f26, guest PC 0x0c0ac1fc */
if(!s->budget--) { s->failed_pc=0x0c0ac1fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac1fe;
P_0c0ac1fe: /* original 2129, guest PC 0x0c0ac1fe */
if(!s->budget--) { s->failed_pc=0x0c0ac1feu; return 0; }
r[1]&=r[2];
goto P_0c0ac200;
P_0c0ac200: /* original 2e12, guest PC 0x0c0ac200 */
if(!s->budget--) { s->failed_pc=0x0c0ac200u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ac202;
P_0c0ac202: /* original 1e0e, guest PC 0x0c0ac202 */
if(!s->budget--) { s->failed_pc=0x0c0ac202u; return 0; }
write(ram,r[14]+56,r[0],4);
goto P_0c0ac204;
P_0c0ac204: /* original 000b, guest PC 0x0c0ac204 */
if(!s->budget--) { s->failed_pc=0x0c0ac204u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac206: /* original 6ef6, guest PC 0x0c0ac206 */
if(!s->budget--) { s->failed_pc=0x0c0ac206u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac208;
P_0c0ac208: /* original 61e2, guest PC 0x0c0ac208 */
if(!s->budget--) { s->failed_pc=0x0c0ac208u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ac20a;
P_0c0ac20a: /* original d224, guest PC 0x0c0ac20a */
if(!s->budget--) { s->failed_pc=0x0c0ac20au; return 0; }
r[2]=read(ram,0x0c0ac29cu,4);
goto P_0c0ac20c;
P_0c0ac20c: /* original 2128, guest PC 0x0c0ac20c */
if(!s->budget--) { s->failed_pc=0x0c0ac20cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ac20e;
P_0c0ac20e: /* original 8907, guest PC 0x0c0ac20e */
if(!s->budget--) { s->failed_pc=0x0c0ac20eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac220; }
goto P_0c0ac210;
P_0c0ac210: /* original d125, guest PC 0x0c0ac210 */
if(!s->budget--) { s->failed_pc=0x0c0ac210u; return 0; }
r[1]=read(ram,0x0c0ac2a8u,4);
goto P_0c0ac212;
P_0c0ac212: /* original 410b, guest PC 0x0c0ac212 */
if(!s->budget--) { s->failed_pc=0x0c0ac212u; return 0; }
target=r[1];
r[16]=code_base|0x0c0ac216u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac216u) { target=s->pc; goto dispatch; }
goto P_0c0ac216;
P_0c0ac214: /* original 64e3, guest PC 0x0c0ac214 */
if(!s->budget--) { s->failed_pc=0x0c0ac214u; return 0; }
r[4]=r[14];
goto P_0c0ac216;
P_0c0ac216: /* original 4f26, guest PC 0x0c0ac216 */
if(!s->budget--) { s->failed_pc=0x0c0ac216u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac218;
P_0c0ac218: /* original d324, guest PC 0x0c0ac218 */
if(!s->budget--) { s->failed_pc=0x0c0ac218u; return 0; }
r[3]=read(ram,0x0c0ac2acu,4);
goto P_0c0ac21a;
P_0c0ac21a: /* original 1e3d, guest PC 0x0c0ac21a */
if(!s->budget--) { s->failed_pc=0x0c0ac21au; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0ac21c;
P_0c0ac21c: /* original 000b, guest PC 0x0c0ac21c */
if(!s->budget--) { s->failed_pc=0x0c0ac21cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac21e: /* original 6ef6, guest PC 0x0c0ac21e */
if(!s->budget--) { s->failed_pc=0x0c0ac21eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac220;
P_0c0ac220: /* original d123, guest PC 0x0c0ac220 */
if(!s->budget--) { s->failed_pc=0x0c0ac220u; return 0; }
r[1]=read(ram,0x0c0ac2b0u,4);
goto P_0c0ac222;
P_0c0ac222: /* original 1e1d, guest PC 0x0c0ac222 */
if(!s->budget--) { s->failed_pc=0x0c0ac222u; return 0; }
write(ram,r[14]+52,r[1],4);
goto P_0c0ac224;
P_0c0ac224: /* original 4f26, guest PC 0x0c0ac224 */
if(!s->budget--) { s->failed_pc=0x0c0ac224u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac226;
P_0c0ac226: /* original 000b, guest PC 0x0c0ac226 */
if(!s->budget--) { s->failed_pc=0x0c0ac226u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac228: /* original 6ef6, guest PC 0x0c0ac228 */
if(!s->budget--) { s->failed_pc=0x0c0ac228u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac22a;
P_0c0ac22a: /* original 2fe6, guest PC 0x0c0ac22a */
if(!s->budget--) { s->failed_pc=0x0c0ac22au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac22c;
P_0c0ac22c: /* original e058, guest PC 0x0c0ac22c */
if(!s->budget--) { s->failed_pc=0x0c0ac22cu; return 0; }
r[0]=0x00000058u;
goto P_0c0ac22e;
P_0c0ac22e: /* original 2fd6, guest PC 0x0c0ac22e */
if(!s->budget--) { s->failed_pc=0x0c0ac22eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac230;
P_0c0ac230: /* original 6e43, guest PC 0x0c0ac230 */
if(!s->budget--) { s->failed_pc=0x0c0ac230u; return 0; }
r[14]=r[4];
goto P_0c0ac232;
P_0c0ac232: /* original 2fc6, guest PC 0x0c0ac232 */
if(!s->budget--) { s->failed_pc=0x0c0ac232u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac234;
P_0c0ac234: /* original 6d63, guest PC 0x0c0ac234 */
if(!s->budget--) { s->failed_pc=0x0c0ac234u; return 0; }
r[13]=r[6];
goto P_0c0ac236;
P_0c0ac236: /* original 2fb6, guest PC 0x0c0ac236 */
if(!s->budget--) { s->failed_pc=0x0c0ac236u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac238;
P_0c0ac238: /* original e500, guest PC 0x0c0ac238 */
if(!s->budget--) { s->failed_pc=0x0c0ac238u; return 0; }
r[5]=0x00000000u;
goto P_0c0ac23a;
P_0c0ac23a: /* original 2fa6, guest PC 0x0c0ac23a */
if(!s->budget--) { s->failed_pc=0x0c0ac23au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac23c;
P_0c0ac23c: /* original 2f96, guest PC 0x0c0ac23c */
if(!s->budget--) { s->failed_pc=0x0c0ac23cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac23e;
P_0c0ac23e: /* original 2f86, guest PC 0x0c0ac23e */
if(!s->budget--) { s->failed_pc=0x0c0ac23eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac240;
P_0c0ac240: /* original fffb, guest PC 0x0c0ac240 */
if(!s->budget--) { s->failed_pc=0x0c0ac240u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ac242;
P_0c0ac242: /* original ffeb, guest PC 0x0c0ac242 */
if(!s->budget--) { s->failed_pc=0x0c0ac242u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0ac244;
P_0c0ac244: /* original ffdb, guest PC 0x0c0ac244 */
if(!s->budget--) { s->failed_pc=0x0c0ac244u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0ac246;
P_0c0ac246: /* original ffcb, guest PC 0x0c0ac246 */
if(!s->budget--) { s->failed_pc=0x0c0ac246u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0ac248;
P_0c0ac248: /* original 0cee, guest PC 0x0c0ac248 */
if(!s->budget--) { s->failed_pc=0x0c0ac248u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0ac24a;
P_0c0ac24a: /* original e050, guest PC 0x0c0ac24a */
if(!s->budget--) { s->failed_pc=0x0c0ac24au; return 0; }
r[0]=0x00000050u;
goto P_0c0ac24c;
P_0c0ac24c: /* original 0aee, guest PC 0x0c0ac24c */
if(!s->budget--) { s->failed_pc=0x0c0ac24cu; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c0ac24e;
P_0c0ac24e: /* original e048, guest PC 0x0c0ac24e */
if(!s->budget--) { s->failed_pc=0x0c0ac24eu; return 0; }
r[0]=0x00000048u;
goto P_0c0ac250;
P_0c0ac250: /* original 08ee, guest PC 0x0c0ac250 */
if(!s->budget--) { s->failed_pc=0x0c0ac250u; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c0ac252;
P_0c0ac252: /* original 4f22, guest PC 0x0c0ac252 */
if(!s->budget--) { s->failed_pc=0x0c0ac252u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac254;
P_0c0ac254: /* original 50d1, guest PC 0x0c0ac254 */
if(!s->budget--) { s->failed_pc=0x0c0ac254u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0ac256;
P_0c0ac256: /* original d917, guest PC 0x0c0ac256 */
if(!s->budget--) { s->failed_pc=0x0c0ac256u; return 0; }
r[9]=read(ram,0x0c0ac2b4u,4);
goto P_0c0ac258;
P_0c0ac258: /* original 9b1b, guest PC 0x0c0ac258 */
if(!s->budget--) { s->failed_pc=0x0c0ac258u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac292u,2);
goto P_0c0ac25a;
P_0c0ac25a: /* original 8800, guest PC 0x0c0ac25a */
if(!s->budget--) { s->failed_pc=0x0c0ac25au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0ac25c;
P_0c0ac25c: /* original 7fec, guest PC 0x0c0ac25c */
if(!s->budget--) { s->failed_pc=0x0c0ac25cu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0ac25e;
P_0c0ac25e: /* original 8d2b, guest PC 0x0c0ac25e */
if(!s->budget--) { s->failed_pc=0x0c0ac25eu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[4]=tmp;
if(cond) { goto P_0c0ac2b8; }
goto P_0c0ac262;
P_0c0ac260: /* original 64e2, guest PC 0x0c0ac260 */
if(!s->budget--) { s->failed_pc=0x0c0ac260u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0ac262;
P_0c0ac262: /* original 8801, guest PC 0x0c0ac262 */
if(!s->budget--) { s->failed_pc=0x0c0ac262u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ac264;
P_0c0ac264: /* original 8935, guest PC 0x0c0ac264 */
if(!s->budget--) { s->failed_pc=0x0c0ac264u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac2d2; }
goto P_0c0ac266;
P_0c0ac266: /* original 8802, guest PC 0x0c0ac266 */
if(!s->budget--) { s->failed_pc=0x0c0ac266u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0ac268;
P_0c0ac268: /* original 8957, guest PC 0x0c0ac268 */
if(!s->budget--) { s->failed_pc=0x0c0ac268u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac31a; }
goto P_0c0ac26a;
P_0c0ac26a: /* original 8803, guest PC 0x0c0ac26a */
if(!s->budget--) { s->failed_pc=0x0c0ac26au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0ac26c;
P_0c0ac26c: /* original 8b01, guest PC 0x0c0ac26c */
if(!s->budget--) { s->failed_pc=0x0c0ac26cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac272; }
goto P_0c0ac26e;
P_0c0ac26e: /* original a088, guest PC 0x0c0ac26e */
if(!s->budget--) { s->failed_pc=0x0c0ac26eu; return 0; }
goto P_0c0ac382;
P_0c0ac270: /* original 0009, guest PC 0x0c0ac270 */
if(!s->budget--) { s->failed_pc=0x0c0ac270u; return 0; }
goto P_0c0ac272;
P_0c0ac272: /* original 8804, guest PC 0x0c0ac272 */
if(!s->budget--) { s->failed_pc=0x0c0ac272u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0ac274;
P_0c0ac274: /* original 8b01, guest PC 0x0c0ac274 */
if(!s->budget--) { s->failed_pc=0x0c0ac274u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac27a; }
goto P_0c0ac276;
P_0c0ac276: /* original a2a8, guest PC 0x0c0ac276 */
if(!s->budget--) { s->failed_pc=0x0c0ac276u; return 0; }
goto P_0c0ac7ca;
P_0c0ac278: /* original 0009, guest PC 0x0c0ac278 */
if(!s->budget--) { s->failed_pc=0x0c0ac278u; return 0; }
goto P_0c0ac27a;
P_0c0ac27a: /* original 8805, guest PC 0x0c0ac27a */
if(!s->budget--) { s->failed_pc=0x0c0ac27au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0ac27c;
P_0c0ac27c: /* original 8b01, guest PC 0x0c0ac27c */
if(!s->budget--) { s->failed_pc=0x0c0ac27cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac282; }
goto P_0c0ac27e;
P_0c0ac27e: /* original a2b0, guest PC 0x0c0ac27e */
if(!s->budget--) { s->failed_pc=0x0c0ac27eu; return 0; }
goto P_0c0ac7e2;
P_0c0ac280: /* original 0009, guest PC 0x0c0ac280 */
if(!s->budget--) { s->failed_pc=0x0c0ac280u; return 0; }
goto P_0c0ac282;
P_0c0ac282: /* original 8806, guest PC 0x0c0ac282 */
if(!s->budget--) { s->failed_pc=0x0c0ac282u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0ac284;
P_0c0ac284: /* original 8b01, guest PC 0x0c0ac284 */
if(!s->budget--) { s->failed_pc=0x0c0ac284u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac28a; }
goto P_0c0ac286;
P_0c0ac286: /* original a2f5, guest PC 0x0c0ac286 */
if(!s->budget--) { s->failed_pc=0x0c0ac286u; return 0; }
goto P_0c0ac874;
P_0c0ac288: /* original 0009, guest PC 0x0c0ac288 */
if(!s->budget--) { s->failed_pc=0x0c0ac288u; return 0; }
goto P_0c0ac28a;
P_0c0ac28a: /* original a328, guest PC 0x0c0ac28a */
if(!s->budget--) { s->failed_pc=0x0c0ac28au; return 0; }
goto P_0c0ac8de;
P_0c0ac28c: /* original 0009, guest PC 0x0c0ac28c */
if(!s->budget--) { s->failed_pc=0x0c0ac28cu; return 0; }
if(!vf3_matrix_family(0x0c0ac28eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac28eu; return 0; } return 1;
P_0c0ac2b8: /* original 9042, guest PC 0x0c0ac2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac2b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac340u,2);
goto P_0c0ac2ba;
P_0c0ac2ba: /* original e200, guest PC 0x0c0ac2ba */
if(!s->budget--) { s->failed_pc=0x0c0ac2bau; return 0; }
r[2]=0x00000000u;
goto P_0c0ac2bc;
P_0c0ac2bc: /* original 0e26, guest PC 0x0c0ac2bc */
if(!s->budget--) { s->failed_pc=0x0c0ac2bcu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ac2be;
P_0c0ac2be: /* original e048, guest PC 0x0c0ac2be */
if(!s->budget--) { s->failed_pc=0x0c0ac2beu; return 0; }
r[0]=0x00000048u;
goto P_0c0ac2c0;
P_0c0ac2c0: /* original d320, guest PC 0x0c0ac2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac2c0u; return 0; }
r[3]=read(ram,0x0c0ac344u,4);
goto P_0c0ac2c2;
P_0c0ac2c2: /* original 283b, guest PC 0x0c0ac2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac2c2u; return 0; }
r[8]|=r[3];
goto P_0c0ac2c4;
P_0c0ac2c4: /* original 0e86, guest PC 0x0c0ac2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac2c4u; return 0; }
write(ram,r[14]+r[0],r[8],4);
goto P_0c0ac2c6;
P_0c0ac2c6: /* original e062, guest PC 0x0c0ac2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac2c6u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac2c8;
P_0c0ac2c8: /* original 52d1, guest PC 0x0c0ac2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac2c8u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ac2ca;
P_0c0ac2ca: /* original 7201, guest PC 0x0c0ac2ca */
if(!s->budget--) { s->failed_pc=0x0c0ac2cau; return 0; }
r[2]+=0x00000001u;
goto P_0c0ac2cc;
P_0c0ac2cc: /* original 6123, guest PC 0x0c0ac2cc */
if(!s->budget--) { s->failed_pc=0x0c0ac2ccu; return 0; }
r[1]=r[2];
goto P_0c0ac2ce;
P_0c0ac2ce: /* original 1d21, guest PC 0x0c0ac2ce */
if(!s->budget--) { s->failed_pc=0x0c0ac2ceu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ac2d0;
P_0c0ac2d0: /* original 0e14, guest PC 0x0c0ac2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac2d0u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0ac2d2;
P_0c0ac2d2: /* original 9336, guest PC 0x0c0ac2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac2d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac342u,2);
goto P_0c0ac2d4;
P_0c0ac2d4: /* original 2348, guest PC 0x0c0ac2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac2d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ac2d6;
P_0c0ac2d6: /* original 8b01, guest PC 0x0c0ac2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac2d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac2dc; }
goto P_0c0ac2d8;
P_0c0ac2d8: /* original a2ef, guest PC 0x0c0ac2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac2d8u; return 0; }
goto P_0c0ac8ba;
P_0c0ac2da: /* original 0009, guest PC 0x0c0ac2da */
if(!s->budget--) { s->failed_pc=0x0c0ac2dau; return 0; }
goto P_0c0ac2dc;
P_0c0ac2dc: /* original d21a, guest PC 0x0c0ac2dc */
if(!s->budget--) { s->failed_pc=0x0c0ac2dcu; return 0; }
r[2]=read(ram,0x0c0ac348u,4);
goto P_0c0ac2de;
P_0c0ac2de: /* original 2248, guest PC 0x0c0ac2de */
if(!s->budget--) { s->failed_pc=0x0c0ac2deu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0ac2e0;
P_0c0ac2e0: /* original 8901, guest PC 0x0c0ac2e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac2e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac2e6; }
goto P_0c0ac2e2;
P_0c0ac2e2: /* original a2f0, guest PC 0x0c0ac2e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac2e2u; return 0; }
goto P_0c0ac8c6;
P_0c0ac2e4: /* original 0009, guest PC 0x0c0ac2e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac2e4u; return 0; }
goto P_0c0ac2e6;
P_0c0ac2e6: /* original e046, guest PC 0x0c0ac2e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac2e6u; return 0; }
r[0]=0x00000046u;
goto P_0c0ac2e8;
P_0c0ac2e8: /* original 03ed, guest PC 0x0c0ac2e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac2e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac2ea;
P_0c0ac2ea: /* original 633d, guest PC 0x0c0ac2ea */
if(!s->budget--) { s->failed_pc=0x0c0ac2eau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ac2ec;
P_0c0ac2ec: /* original 4315, guest PC 0x0c0ac2ec */
if(!s->budget--) { s->failed_pc=0x0c0ac2ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0ac2ee;
P_0c0ac2ee: /* original 8901, guest PC 0x0c0ac2ee */
if(!s->budget--) { s->failed_pc=0x0c0ac2eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac2f4; }
goto P_0c0ac2f0;
P_0c0ac2f0: /* original a2e9, guest PC 0x0c0ac2f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac2f0u; return 0; }
goto P_0c0ac8c6;
P_0c0ac2f2: /* original 0009, guest PC 0x0c0ac2f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac2f2u; return 0; }
goto P_0c0ac2f4;
P_0c0ac2f4: /* original d315, guest PC 0x0c0ac2f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac2f4u; return 0; }
r[3]=read(ram,0x0c0ac34cu,4);
goto P_0c0ac2f6;
P_0c0ac2f6: /* original 2388, guest PC 0x0c0ac2f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac2f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0ac2f8;
P_0c0ac2f8: /* original 8902, guest PC 0x0c0ac2f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac2f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac300; }
goto P_0c0ac2fa;
P_0c0ac2fa: /* original 65c3, guest PC 0x0c0ac2fa */
if(!s->budget--) { s->failed_pc=0x0c0ac2fau; return 0; }
r[5]=r[12];
goto P_0c0ac2fc;
P_0c0ac2fc: /* original a002, guest PC 0x0c0ac2fc */
if(!s->budget--) { s->failed_pc=0x0c0ac2fcu; return 0; }
r[5]+=0x00000054u;
goto P_0c0ac304;
P_0c0ac2fe: /* original 7554, guest PC 0x0c0ac2fe */
if(!s->budget--) { s->failed_pc=0x0c0ac2feu; return 0; }
r[5]+=0x00000054u;
goto P_0c0ac300;
P_0c0ac300: /* original 65c3, guest PC 0x0c0ac300 */
if(!s->budget--) { s->failed_pc=0x0c0ac300u; return 0; }
r[5]=r[12];
goto P_0c0ac302;
P_0c0ac302: /* original 7552, guest PC 0x0c0ac302 */
if(!s->budget--) { s->failed_pc=0x0c0ac302u; return 0; }
r[5]+=0x00000052u;
goto P_0c0ac304;
P_0c0ac304: /* original e068, guest PC 0x0c0ac304 */
if(!s->budget--) { s->failed_pc=0x0c0ac304u; return 0; }
r[0]=0x00000068u;
goto P_0c0ac306;
P_0c0ac306: /* original 6551, guest PC 0x0c0ac306 */
if(!s->budget--) { s->failed_pc=0x0c0ac306u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac308;
P_0c0ac308: /* original e300, guest PC 0x0c0ac308 */
if(!s->budget--) { s->failed_pc=0x0c0ac308u; return 0; }
r[3]=0x00000000u;
goto P_0c0ac30a;
P_0c0ac30a: /* original 0e35, guest PC 0x0c0ac30a */
if(!s->budget--) { s->failed_pc=0x0c0ac30au; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0ac30c;
P_0c0ac30c: /* original e062, guest PC 0x0c0ac30c */
if(!s->budget--) { s->failed_pc=0x0c0ac30cu; return 0; }
r[0]=0x00000062u;
goto P_0c0ac30e;
P_0c0ac30e: /* original 52d1, guest PC 0x0c0ac30e */
if(!s->budget--) { s->failed_pc=0x0c0ac30eu; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ac310;
P_0c0ac310: /* original 655d, guest PC 0x0c0ac310 */
if(!s->budget--) { s->failed_pc=0x0c0ac310u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac312;
P_0c0ac312: /* original 7201, guest PC 0x0c0ac312 */
if(!s->budget--) { s->failed_pc=0x0c0ac312u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ac314;
P_0c0ac314: /* original 6323, guest PC 0x0c0ac314 */
if(!s->budget--) { s->failed_pc=0x0c0ac314u; return 0; }
r[3]=r[2];
goto P_0c0ac316;
P_0c0ac316: /* original 1d21, guest PC 0x0c0ac316 */
if(!s->budget--) { s->failed_pc=0x0c0ac316u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ac318;
P_0c0ac318: /* original 0e34, guest PC 0x0c0ac318 */
if(!s->budget--) { s->failed_pc=0x0c0ac318u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ac31a;
P_0c0ac31a: /* original e066, guest PC 0x0c0ac31a */
if(!s->budget--) { s->failed_pc=0x0c0ac31au; return 0; }
r[0]=0x00000066u;
goto P_0c0ac31c;
P_0c0ac31c: /* original 06ed, guest PC 0x0c0ac31c */
if(!s->budget--) { s->failed_pc=0x0c0ac31cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac31e;
P_0c0ac31e: /* original 4615, guest PC 0x0c0ac31e */
if(!s->budget--) { s->failed_pc=0x0c0ac31eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0ac320;
P_0c0ac320: /* original 8b18, guest PC 0x0c0ac320 */
if(!s->budget--) { s->failed_pc=0x0c0ac320u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac354; }
goto P_0c0ac322;
P_0c0ac322: /* original e068, guest PC 0x0c0ac322 */
if(!s->budget--) { s->failed_pc=0x0c0ac322u; return 0; }
r[0]=0x00000068u;
goto P_0c0ac324;
P_0c0ac324: /* original 07ed, guest PC 0x0c0ac324 */
if(!s->budget--) { s->failed_pc=0x0c0ac324u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac326;
P_0c0ac326: /* original 4708, guest PC 0x0c0ac326 */
if(!s->budget--) { s->failed_pc=0x0c0ac326u; return 0; }
r[7]<<=2;
goto P_0c0ac328;
P_0c0ac328: /* original 3763, guest PC 0x0c0ac328 */
if(!s->budget--) { s->failed_pc=0x0c0ac328u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[6])!=0);
goto P_0c0ac32a;
P_0c0ac32a: /* original 8913, guest PC 0x0c0ac32a */
if(!s->budget--) { s->failed_pc=0x0c0ac32au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac354; }
goto P_0c0ac32c;
P_0c0ac32c: /* original 76ff, guest PC 0x0c0ac32c */
if(!s->budget--) { s->failed_pc=0x0c0ac32cu; return 0; }
r[6]+=0xffffffffu;
goto P_0c0ac32e;
P_0c0ac32e: /* original 4615, guest PC 0x0c0ac32e */
if(!s->budget--) { s->failed_pc=0x0c0ac32eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0ac330;
P_0c0ac330: /* original 8d04, guest PC 0x0c0ac330 */
if(!s->budget--) { s->failed_pc=0x0c0ac330u; return 0; }
cond=r[17]&1u;
r[0]=0x00000066u;
if(cond) { goto P_0c0ac33c; }
goto P_0c0ac334;
P_0c0ac332: /* original e066, guest PC 0x0c0ac332 */
if(!s->budget--) { s->failed_pc=0x0c0ac332u; return 0; }
r[0]=0x00000066u;
goto P_0c0ac334;
P_0c0ac334: /* original d306, guest PC 0x0c0ac334 */
if(!s->budget--) { s->failed_pc=0x0c0ac334u; return 0; }
r[3]=read(ram,0x0c0ac350u,4);
goto P_0c0ac336;
P_0c0ac336: /* original e600, guest PC 0x0c0ac336 */
if(!s->budget--) { s->failed_pc=0x0c0ac336u; return 0; }
r[6]=0x00000000u;
goto P_0c0ac338;
P_0c0ac338: /* original 2439, guest PC 0x0c0ac338 */
if(!s->budget--) { s->failed_pc=0x0c0ac338u; return 0; }
r[4]&=r[3];
goto P_0c0ac33a;
P_0c0ac33a: /* original 2e42, guest PC 0x0c0ac33a */
if(!s->budget--) { s->failed_pc=0x0c0ac33au; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0ac33c;
P_0c0ac33c: /* original a2bd, guest PC 0x0c0ac33c */
if(!s->budget--) { s->failed_pc=0x0c0ac33cu; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c0ac8ba;
P_0c0ac33e: /* original 0e65, guest PC 0x0c0ac33e */
if(!s->budget--) { s->failed_pc=0x0c0ac33eu; return 0; }
write(ram,r[14]+r[0],r[6],2);
if(!vf3_matrix_family(0x0c0ac340u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac340u; return 0; } return 1;
P_0c0ac354: /* original e066, guest PC 0x0c0ac354 */
if(!s->budget--) { s->failed_pc=0x0c0ac354u; return 0; }
r[0]=0x00000066u;
goto P_0c0ac356;
P_0c0ac356: /* original e200, guest PC 0x0c0ac356 */
if(!s->budget--) { s->failed_pc=0x0c0ac356u; return 0; }
r[2]=0x00000000u;
goto P_0c0ac358;
P_0c0ac358: /* original 0e25, guest PC 0x0c0ac358 */
if(!s->budget--) { s->failed_pc=0x0c0ac358u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0ac35a;
P_0c0ac35a: /* original e044, guest PC 0x0c0ac35a */
if(!s->budget--) { s->failed_pc=0x0c0ac35au; return 0; }
r[0]=0x00000044u;
goto P_0c0ac35c;
P_0c0ac35c: /* original 6323, guest PC 0x0c0ac35c */
if(!s->budget--) { s->failed_pc=0x0c0ac35cu; return 0; }
r[3]=r[2];
goto P_0c0ac35e;
P_0c0ac35e: /* original 0e35, guest PC 0x0c0ac35e */
if(!s->budget--) { s->failed_pc=0x0c0ac35eu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0ac360;
P_0c0ac360: /* original 9097, guest PC 0x0c0ac360 */
if(!s->budget--) { s->failed_pc=0x0c0ac360u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac492u,2);
goto P_0c0ac362;
P_0c0ac362: /* original 0e34, guest PC 0x0c0ac362 */
if(!s->budget--) { s->failed_pc=0x0c0ac362u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ac364;
P_0c0ac364: /* original 9096, guest PC 0x0c0ac364 */
if(!s->budget--) { s->failed_pc=0x0c0ac364u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac494u,2);
goto P_0c0ac366;
P_0c0ac366: /* original 0e34, guest PC 0x0c0ac366 */
if(!s->budget--) { s->failed_pc=0x0c0ac366u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ac368;
P_0c0ac368: /* original 703f, guest PC 0x0c0ac368 */
if(!s->budget--) { s->failed_pc=0x0c0ac368u; return 0; }
r[0]+=0x0000003fu;
goto P_0c0ac36a;
P_0c0ac36a: /* original 0e34, guest PC 0x0c0ac36a */
if(!s->budget--) { s->failed_pc=0x0c0ac36au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ac36c;
P_0c0ac36c: /* original 9093, guest PC 0x0c0ac36c */
if(!s->budget--) { s->failed_pc=0x0c0ac36cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac496u,2);
goto P_0c0ac36e;
P_0c0ac36e: /* original 0e34, guest PC 0x0c0ac36e */
if(!s->budget--) { s->failed_pc=0x0c0ac36eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ac370;
P_0c0ac370: /* original e062, guest PC 0x0c0ac370 */
if(!s->budget--) { s->failed_pc=0x0c0ac370u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac372;
P_0c0ac372: /* original d24c, guest PC 0x0c0ac372 */
if(!s->budget--) { s->failed_pc=0x0c0ac372u; return 0; }
r[2]=read(ram,0x0c0ac4a4u,4);
goto P_0c0ac374;
P_0c0ac374: /* original 2429, guest PC 0x0c0ac374 */
if(!s->budget--) { s->failed_pc=0x0c0ac374u; return 0; }
r[4]&=r[2];
goto P_0c0ac376;
P_0c0ac376: /* original 2e42, guest PC 0x0c0ac376 */
if(!s->budget--) { s->failed_pc=0x0c0ac376u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0ac378;
P_0c0ac378: /* original 53d1, guest PC 0x0c0ac378 */
if(!s->budget--) { s->failed_pc=0x0c0ac378u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ac37a;
P_0c0ac37a: /* original 7301, guest PC 0x0c0ac37a */
if(!s->budget--) { s->failed_pc=0x0c0ac37au; return 0; }
r[3]+=0x00000001u;
goto P_0c0ac37c;
P_0c0ac37c: /* original 6133, guest PC 0x0c0ac37c */
if(!s->budget--) { s->failed_pc=0x0c0ac37cu; return 0; }
r[1]=r[3];
goto P_0c0ac37e;
P_0c0ac37e: /* original 1d31, guest PC 0x0c0ac37e */
if(!s->budget--) { s->failed_pc=0x0c0ac37eu; return 0; }
write(ram,r[13]+4,r[3],4);
goto P_0c0ac380;
P_0c0ac380: /* original 0e14, guest PC 0x0c0ac380 */
if(!s->budget--) { s->failed_pc=0x0c0ac380u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0ac382;
P_0c0ac382: /* original 64d2, guest PC 0x0c0ac382 */
if(!s->budget--) { s->failed_pc=0x0c0ac382u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0ac384;
P_0c0ac384: /* original d348, guest PC 0x0c0ac384 */
if(!s->budget--) { s->failed_pc=0x0c0ac384u; return 0; }
r[3]=read(ram,0x0c0ac4a8u,4);
goto P_0c0ac386;
P_0c0ac386: /* original 2439, guest PC 0x0c0ac386 */
if(!s->budget--) { s->failed_pc=0x0c0ac386u; return 0; }
r[4]&=r[3];
goto P_0c0ac388;
P_0c0ac388: /* original 2448, guest PC 0x0c0ac388 */
if(!s->budget--) { s->failed_pc=0x0c0ac388u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ac38a;
P_0c0ac38a: /* original 8b06, guest PC 0x0c0ac38a */
if(!s->budget--) { s->failed_pc=0x0c0ac38au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac39a; }
goto P_0c0ac38c;
P_0c0ac38c: /* original e044, guest PC 0x0c0ac38c */
if(!s->budget--) { s->failed_pc=0x0c0ac38cu; return 0; }
r[0]=0x00000044u;
goto P_0c0ac38e;
P_0c0ac38e: /* original 02ed, guest PC 0x0c0ac38e */
if(!s->budget--) { s->failed_pc=0x0c0ac38eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac390;
P_0c0ac390: /* original e328, guest PC 0x0c0ac390 */
if(!s->budget--) { s->failed_pc=0x0c0ac390u; return 0; }
r[3]=0x00000028u;
goto P_0c0ac392;
P_0c0ac392: /* original 3233, guest PC 0x0c0ac392 */
if(!s->budget--) { s->failed_pc=0x0c0ac392u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0ac394;
P_0c0ac394: /* original 8901, guest PC 0x0c0ac394 */
if(!s->budget--) { s->failed_pc=0x0c0ac394u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac39a; }
goto P_0c0ac396;
P_0c0ac396: /* original a290, guest PC 0x0c0ac396 */
if(!s->budget--) { s->failed_pc=0x0c0ac396u; return 0; }
goto P_0c0ac8ba;
P_0c0ac398: /* original 0009, guest PC 0x0c0ac398 */
if(!s->budget--) { s->failed_pc=0x0c0ac398u; return 0; }
goto P_0c0ac39a;
P_0c0ac39a: /* original 62e2, guest PC 0x0c0ac39a */
if(!s->budget--) { s->failed_pc=0x0c0ac39au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ac39c;
P_0c0ac39c: /* original d343, guest PC 0x0c0ac39c */
if(!s->budget--) { s->failed_pc=0x0c0ac39cu; return 0; }
r[3]=read(ram,0x0c0ac4acu,4);
goto P_0c0ac39e;
P_0c0ac39e: /* original 2239, guest PC 0x0c0ac39e */
if(!s->budget--) { s->failed_pc=0x0c0ac39eu; return 0; }
r[2]&=r[3];
goto P_0c0ac3a0;
P_0c0ac3a0: /* original 2e22, guest PC 0x0c0ac3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac3a0u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ac3a2;
P_0c0ac3a2: /* original 60d2, guest PC 0x0c0ac3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac3a2u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0ac3a4;
P_0c0ac3a4: /* original c808, guest PC 0x0c0ac3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac3a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0ac3a6;
P_0c0ac3a6: /* original 8901, guest PC 0x0c0ac3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac3a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac3ac; }
goto P_0c0ac3a8;
P_0c0ac3a8: /* original a14f, guest PC 0x0c0ac3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac3a8u; return 0; }
goto P_0c0ac64a;
P_0c0ac3aa: /* original 0009, guest PC 0x0c0ac3aa */
if(!s->budget--) { s->failed_pc=0x0c0ac3aau; return 0; }
goto P_0c0ac3ac;
P_0c0ac3ac: /* original c740, guest PC 0x0c0ac3ac */
if(!s->budget--) { s->failed_pc=0x0c0ac3acu; return 0; }
r[0]=code_base|0x000ac4b0u;
goto P_0c0ac3ae;
P_0c0ac3ae: /* original f408, guest PC 0x0c0ac3ae */
if(!s->budget--) { s->failed_pc=0x0c0ac3aeu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ac3b0;
P_0c0ac3b0: /* original 60d2, guest PC 0x0c0ac3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac3b0u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0ac3b2;
P_0c0ac3b2: /* original c810, guest PC 0x0c0ac3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac3b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0ac3b4;
P_0c0ac3b4: /* original 8901, guest PC 0x0c0ac3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac3b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac3ba; }
goto P_0c0ac3b6;
P_0c0ac3b6: /* original a16a, guest PC 0x0c0ac3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac3b6u; return 0; }
goto P_0c0ac68e;
P_0c0ac3b8: /* original 0009, guest PC 0x0c0ac3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac3b8u; return 0; }
goto P_0c0ac3ba;
P_0c0ac3ba: /* original 60d2, guest PC 0x0c0ac3ba */
if(!s->budget--) { s->failed_pc=0x0c0ac3bau; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0ac3bc;
P_0c0ac3bc: /* original c820, guest PC 0x0c0ac3bc */
if(!s->budget--) { s->failed_pc=0x0c0ac3bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0ac3be;
P_0c0ac3be: /* original 8901, guest PC 0x0c0ac3be */
if(!s->budget--) { s->failed_pc=0x0c0ac3beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac3c4; }
goto P_0c0ac3c0;
P_0c0ac3c0: /* original a1a2, guest PC 0x0c0ac3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac3c0u; return 0; }
goto P_0c0ac708;
P_0c0ac3c2: /* original 0009, guest PC 0x0c0ac3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac3c2u; return 0; }
goto P_0c0ac3c4;
P_0c0ac3c4: /* original 9068, guest PC 0x0c0ac3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac3c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac498u,2);
goto P_0c0ac3c6;
P_0c0ac3c6: /* original 65f3, guest PC 0x0c0ac3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac3c6u; return 0; }
r[5]=r[15];
goto P_0c0ac3c8;
P_0c0ac3c8: /* original 7504, guest PC 0x0c0ac3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac3c8u; return 0; }
r[5]+=0x00000004u;
goto P_0c0ac3ca;
P_0c0ac3ca: /* original 66f3, guest PC 0x0c0ac3ca */
if(!s->budget--) { s->failed_pc=0x0c0ac3cau; return 0; }
r[6]=r[15];
goto P_0c0ac3cc;
P_0c0ac3cc: /* original fee6, guest PC 0x0c0ac3cc */
if(!s->budget--) { s->failed_pc=0x0c0ac3ccu; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0ac3ce;
P_0c0ac3ce: /* original 7008, guest PC 0x0c0ac3ce */
if(!s->budget--) { s->failed_pc=0x0c0ac3ceu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ac3d0;
P_0c0ac3d0: /* original ffe6, guest PC 0x0c0ac3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac3d0u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ac3d2;
P_0c0ac3d2: /* original 9062, guest PC 0x0c0ac3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac3d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac49au,2);
goto P_0c0ac3d4;
P_0c0ac3d4: /* original fce6, guest PC 0x0c0ac3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac3d4u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0ac3d6;
P_0c0ac3d6: /* original 7008, guest PC 0x0c0ac3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac3d6u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ac3d8;
P_0c0ac3d8: /* original f3e6, guest PC 0x0c0ac3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac3d8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac3da;
P_0c0ac3da: /* original e00c, guest PC 0x0c0ac3da */
if(!s->budget--) { s->failed_pc=0x0c0ac3dau; return 0; }
r[0]=0x0000000cu;
goto P_0c0ac3dc;
P_0c0ac3dc: /* original ff37, guest PC 0x0c0ac3dc */
if(!s->budget--) { s->failed_pc=0x0c0ac3dcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ac3de;
P_0c0ac3de: /* original 905d, guest PC 0x0c0ac3de */
if(!s->budget--) { s->failed_pc=0x0c0ac3deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac49cu,2);
goto P_0c0ac3e0;
P_0c0ac3e0: /* original f3e6, guest PC 0x0c0ac3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac3e0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac3e2;
P_0c0ac3e2: /* original e008, guest PC 0x0c0ac3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac3e2u; return 0; }
r[0]=0x00000008u;
goto P_0c0ac3e4;
P_0c0ac3e4: /* original ff37, guest PC 0x0c0ac3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac3e4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ac3e6;
P_0c0ac3e6: /* original 905a, guest PC 0x0c0ac3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac3e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac49eu,2);
goto P_0c0ac3e8;
P_0c0ac3e8: /* original fde6, guest PC 0x0c0ac3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac3e8u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0ac3ea;
P_0c0ac3ea: /* original c732, guest PC 0x0c0ac3ea */
if(!s->budget--) { s->failed_pc=0x0c0ac3eau; return 0; }
r[0]=code_base|0x000ac4b4u;
goto P_0c0ac3ec;
P_0c0ac3ec: /* original f308, guest PC 0x0c0ac3ec */
if(!s->budget--) { s->failed_pc=0x0c0ac3ecu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ac3ee;
P_0c0ac3ee: /* original e004, guest PC 0x0c0ac3ee */
if(!s->budget--) { s->failed_pc=0x0c0ac3eeu; return 0; }
r[0]=0x00000004u;
goto P_0c0ac3f0;
P_0c0ac3f0: /* original ff37, guest PC 0x0c0ac3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac3f0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ac3f2;
P_0c0ac3f2: /* original f38d, guest PC 0x0c0ac3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac3f2u; return 0; }
fr[3]=0;
goto P_0c0ac3f4;
P_0c0ac3f4: /* original ff3a, guest PC 0x0c0ac3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac3f4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ac3f6;
P_0c0ac3f6: /* original 9053, guest PC 0x0c0ac3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac3f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac4a0u,2);
goto P_0c0ac3f8;
P_0c0ac3f8: /* original 03ed, guest PC 0x0c0ac3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac3f8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac3fa;
P_0c0ac3fa: /* original 633d, guest PC 0x0c0ac3fa */
if(!s->budget--) { s->failed_pc=0x0c0ac3fau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ac3fc;
P_0c0ac3fc: /* original 1f34, guest PC 0x0c0ac3fc */
if(!s->budget--) { s->failed_pc=0x0c0ac3fcu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ac3fe;
P_0c0ac3fe: /* original d22e, guest PC 0x0c0ac3fe */
if(!s->budget--) { s->failed_pc=0x0c0ac3feu; return 0; }
r[2]=read(ram,0x0c0ac4b8u,4);
goto P_0c0ac400;
P_0c0ac400: /* original 420b, guest PC 0x0c0ac400 */
if(!s->budget--) { s->failed_pc=0x0c0ac400u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ac404u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac404u) { target=s->pc; goto dispatch; }
goto P_0c0ac404;
P_0c0ac402: /* original 6433, guest PC 0x0c0ac402 */
if(!s->budget--) { s->failed_pc=0x0c0ac402u; return 0; }
r[4]=r[3];
goto P_0c0ac404;
P_0c0ac404: /* original e004, guest PC 0x0c0ac404 */
if(!s->budget--) { s->failed_pc=0x0c0ac404u; return 0; }
r[0]=0x00000004u;
goto P_0c0ac406;
P_0c0ac406: /* original f5f8, guest PC 0x0c0ac406 */
if(!s->budget--) { s->failed_pc=0x0c0ac406u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c0ac408;
P_0c0ac408: /* original f4f6, guest PC 0x0c0ac408 */
if(!s->budget--) { s->failed_pc=0x0c0ac408u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ac40a;
P_0c0ac40a: /* original e00c, guest PC 0x0c0ac40a */
if(!s->budget--) { s->failed_pc=0x0c0ac40au; return 0; }
r[0]=0x0000000cu;
goto P_0c0ac40c;
P_0c0ac40c: /* original f3f6, guest PC 0x0c0ac40c */
if(!s->budget--) { s->failed_pc=0x0c0ac40cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ac40e;
P_0c0ac40e: /* original f4c0, guest PC 0x0c0ac40e */
if(!s->budget--) { s->failed_pc=0x0c0ac40eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'+');
goto P_0c0ac410;
P_0c0ac410: /* original b663, guest PC 0x0c0ac410 */
if(!s->budget--) { s->failed_pc=0x0c0ac410u; return 0; }
target=code_base|0x0c0ad0dau; r[16]=code_base|0x0c0ac414u;
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac414u) { target=s->pc; goto dispatch; }
goto P_0c0ac414;
P_0c0ac412: /* original f530, guest PC 0x0c0ac412 */
if(!s->budget--) { s->failed_pc=0x0c0ac412u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0ac414;
P_0c0ac414: /* original f38d, guest PC 0x0c0ac414 */
if(!s->budget--) { s->failed_pc=0x0c0ac414u; return 0; }
fr[3]=0;
goto P_0c0ac416;
P_0c0ac416: /* original f035, guest PC 0x0c0ac416 */
if(!s->budget--) { s->failed_pc=0x0c0ac416u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0ac418;
P_0c0ac418: /* original 891a, guest PC 0x0c0ac418 */
if(!s->budget--) { s->failed_pc=0x0c0ac418u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac450; }
goto P_0c0ac41a;
P_0c0ac41a: /* original e008, guest PC 0x0c0ac41a */
if(!s->budget--) { s->failed_pc=0x0c0ac41au; return 0; }
r[0]=0x00000008u;
goto P_0c0ac41c;
P_0c0ac41c: /* original f5f8, guest PC 0x0c0ac41c */
if(!s->budget--) { s->failed_pc=0x0c0ac41cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c0ac41e;
P_0c0ac41e: /* original f3f6, guest PC 0x0c0ac41e */
if(!s->budget--) { s->failed_pc=0x0c0ac41eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ac420;
P_0c0ac420: /* original e004, guest PC 0x0c0ac420 */
if(!s->budget--) { s->failed_pc=0x0c0ac420u; return 0; }
r[0]=0x00000004u;
goto P_0c0ac422;
P_0c0ac422: /* original f4f6, guest PC 0x0c0ac422 */
if(!s->budget--) { s->failed_pc=0x0c0ac422u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ac424;
P_0c0ac424: /* original f430, guest PC 0x0c0ac424 */
if(!s->budget--) { s->failed_pc=0x0c0ac424u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0ac426;
P_0c0ac426: /* original b658, guest PC 0x0c0ac426 */
if(!s->budget--) { s->failed_pc=0x0c0ac426u; return 0; }
target=code_base|0x0c0ad0dau; r[16]=code_base|0x0c0ac42au;
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'+');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac42au) { target=s->pc; goto dispatch; }
goto P_0c0ac42a;
P_0c0ac428: /* original f5d0, guest PC 0x0c0ac428 */
if(!s->budget--) { s->failed_pc=0x0c0ac428u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'+');
goto P_0c0ac42a;
P_0c0ac42a: /* original f38d, guest PC 0x0c0ac42a */
if(!s->budget--) { s->failed_pc=0x0c0ac42au; return 0; }
fr[3]=0;
goto P_0c0ac42c;
P_0c0ac42c: /* original f035, guest PC 0x0c0ac42c */
if(!s->budget--) { s->failed_pc=0x0c0ac42cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0ac42e;
P_0c0ac42e: /* original 890f, guest PC 0x0c0ac42e */
if(!s->budget--) { s->failed_pc=0x0c0ac42eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac450; }
goto P_0c0ac430;
P_0c0ac430: /* original e004, guest PC 0x0c0ac430 */
if(!s->budget--) { s->failed_pc=0x0c0ac430u; return 0; }
r[0]=0x00000004u;
goto P_0c0ac432;
P_0c0ac432: /* original f4f8, guest PC 0x0c0ac432 */
if(!s->budget--) { s->failed_pc=0x0c0ac432u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0ac434;
P_0c0ac434: /* original f5f6, guest PC 0x0c0ac434 */
if(!s->budget--) { s->failed_pc=0x0c0ac434u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0ac436;
P_0c0ac436: /* original c721, guest PC 0x0c0ac436 */
if(!s->budget--) { s->failed_pc=0x0c0ac436u; return 0; }
r[0]=code_base|0x000ac4bcu;
goto P_0c0ac438;
P_0c0ac438: /* original f4f0, guest PC 0x0c0ac438 */
if(!s->budget--) { s->failed_pc=0x0c0ac438u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c0ac43a;
P_0c0ac43a: /* original f208, guest PC 0x0c0ac43a */
if(!s->budget--) { s->failed_pc=0x0c0ac43au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ac43c;
P_0c0ac43c: /* original f5e0, guest PC 0x0c0ac43c */
if(!s->budget--) { s->failed_pc=0x0c0ac43cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'+');
goto P_0c0ac43e;
P_0c0ac43e: /* original f04c, guest PC 0x0c0ac43e */
if(!s->budget--) { s->failed_pc=0x0c0ac43eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ac440;
P_0c0ac440: /* original f35c, guest PC 0x0c0ac440 */
if(!s->budget--) { s->failed_pc=0x0c0ac440u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ac442;
P_0c0ac442: /* original f532, guest PC 0x0c0ac442 */
if(!s->budget--) { s->failed_pc=0x0c0ac442u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0ac444;
P_0c0ac444: /* original f54e, guest PC 0x0c0ac444 */
if(!s->budget--) { s->failed_pc=0x0c0ac444u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[4],fr[5],r[18]);
goto P_0c0ac446;
P_0c0ac446: /* original f45c, guest PC 0x0c0ac446 */
if(!s->budget--) { s->failed_pc=0x0c0ac446u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0ac448;
P_0c0ac448: /* original f245, guest PC 0x0c0ac448 */
if(!s->budget--) { s->failed_pc=0x0c0ac448u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0ac44a;
P_0c0ac44a: /* original 8901, guest PC 0x0c0ac44a */
if(!s->budget--) { s->failed_pc=0x0c0ac44au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac450; }
goto P_0c0ac44c;
P_0c0ac44c: /* original f34c, guest PC 0x0c0ac44c */
if(!s->budget--) { s->failed_pc=0x0c0ac44cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ac44e;
P_0c0ac44e: /* original f37d, guest PC 0x0c0ac44e */
if(!s->budget--) { s->failed_pc=0x0c0ac44eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0ac450;
P_0c0ac450: /* original e004, guest PC 0x0c0ac450 */
if(!s->budget--) { s->failed_pc=0x0c0ac450u; return 0; }
r[0]=0x00000004u;
goto P_0c0ac452;
P_0c0ac452: /* original f3f6, guest PC 0x0c0ac452 */
if(!s->budget--) { s->failed_pc=0x0c0ac452u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ac454;
P_0c0ac454: /* original e004, guest PC 0x0c0ac454 */
if(!s->budget--) { s->failed_pc=0x0c0ac454u; return 0; }
r[0]=0x00000004u;
goto P_0c0ac456;
P_0c0ac456: /* original f34d, guest PC 0x0c0ac456 */
if(!s->budget--) { s->failed_pc=0x0c0ac456u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0ac458;
P_0c0ac458: /* original ff37, guest PC 0x0c0ac458 */
if(!s->budget--) { s->failed_pc=0x0c0ac458u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ac45a;
P_0c0ac45a: /* original e00c, guest PC 0x0c0ac45a */
if(!s->budget--) { s->failed_pc=0x0c0ac45au; return 0; }
r[0]=0x0000000cu;
goto P_0c0ac45c;
P_0c0ac45c: /* original f2f8, guest PC 0x0c0ac45c */
if(!s->budget--) { s->failed_pc=0x0c0ac45cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0ac45e;
P_0c0ac45e: /* original f24d, guest PC 0x0c0ac45e */
if(!s->budget--) { s->failed_pc=0x0c0ac45eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c0ac460;
P_0c0ac460: /* original ff2a, guest PC 0x0c0ac460 */
if(!s->budget--) { s->failed_pc=0x0c0ac460u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0ac462;
P_0c0ac462: /* original f43c, guest PC 0x0c0ac462 */
if(!s->budget--) { s->failed_pc=0x0c0ac462u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0ac464;
P_0c0ac464: /* original f4c0, guest PC 0x0c0ac464 */
if(!s->budget--) { s->failed_pc=0x0c0ac464u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'+');
goto P_0c0ac466;
P_0c0ac466: /* original f1f6, guest PC 0x0c0ac466 */
if(!s->budget--) { s->failed_pc=0x0c0ac466u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ac468;
P_0c0ac468: /* original f52c, guest PC 0x0c0ac468 */
if(!s->budget--) { s->failed_pc=0x0c0ac468u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0ac46a;
P_0c0ac46a: /* original b636, guest PC 0x0c0ac46a */
if(!s->budget--) { s->failed_pc=0x0c0ac46au; return 0; }
target=code_base|0x0c0ad0dau; r[16]=code_base|0x0c0ac46eu;
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'+');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac46eu) { target=s->pc; goto dispatch; }
goto P_0c0ac46e;
P_0c0ac46c: /* original f510, guest PC 0x0c0ac46c */
if(!s->budget--) { s->failed_pc=0x0c0ac46cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'+');
goto P_0c0ac46e;
P_0c0ac46e: /* original f38d, guest PC 0x0c0ac46e */
if(!s->budget--) { s->failed_pc=0x0c0ac46eu; return 0; }
fr[3]=0;
goto P_0c0ac470;
P_0c0ac470: /* original f035, guest PC 0x0c0ac470 */
if(!s->budget--) { s->failed_pc=0x0c0ac470u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0ac472;
P_0c0ac472: /* original 8933, guest PC 0x0c0ac472 */
if(!s->budget--) { s->failed_pc=0x0c0ac472u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac4dc; }
goto P_0c0ac474;
P_0c0ac474: /* original e008, guest PC 0x0c0ac474 */
if(!s->budget--) { s->failed_pc=0x0c0ac474u; return 0; }
r[0]=0x00000008u;
goto P_0c0ac476;
P_0c0ac476: /* original f5f8, guest PC 0x0c0ac476 */
if(!s->budget--) { s->failed_pc=0x0c0ac476u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c0ac478;
P_0c0ac478: /* original f3f6, guest PC 0x0c0ac478 */
if(!s->budget--) { s->failed_pc=0x0c0ac478u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ac47a;
P_0c0ac47a: /* original e004, guest PC 0x0c0ac47a */
if(!s->budget--) { s->failed_pc=0x0c0ac47au; return 0; }
r[0]=0x00000004u;
goto P_0c0ac47c;
P_0c0ac47c: /* original f4f6, guest PC 0x0c0ac47c */
if(!s->budget--) { s->failed_pc=0x0c0ac47cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ac47e;
P_0c0ac47e: /* original f430, guest PC 0x0c0ac47e */
if(!s->budget--) { s->failed_pc=0x0c0ac47eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0ac480;
P_0c0ac480: /* original b62b, guest PC 0x0c0ac480 */
if(!s->budget--) { s->failed_pc=0x0c0ac480u; return 0; }
target=code_base|0x0c0ad0dau; r[16]=code_base|0x0c0ac484u;
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'+');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac484u) { target=s->pc; goto dispatch; }
goto P_0c0ac484;
P_0c0ac482: /* original f5d0, guest PC 0x0c0ac482 */
if(!s->budget--) { s->failed_pc=0x0c0ac482u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'+');
goto P_0c0ac484;
P_0c0ac484: /* original f38d, guest PC 0x0c0ac484 */
if(!s->budget--) { s->failed_pc=0x0c0ac484u; return 0; }
fr[3]=0;
goto P_0c0ac486;
P_0c0ac486: /* original f035, guest PC 0x0c0ac486 */
if(!s->budget--) { s->failed_pc=0x0c0ac486u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0ac488;
P_0c0ac488: /* original 8928, guest PC 0x0c0ac488 */
if(!s->budget--) { s->failed_pc=0x0c0ac488u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac4dc; }
goto P_0c0ac48a;
P_0c0ac48a: /* original e004, guest PC 0x0c0ac48a */
if(!s->budget--) { s->failed_pc=0x0c0ac48au; return 0; }
r[0]=0x00000004u;
goto P_0c0ac48c;
P_0c0ac48c: /* original f5f6, guest PC 0x0c0ac48c */
if(!s->budget--) { s->failed_pc=0x0c0ac48cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0ac48e;
P_0c0ac48e: /* original a017, guest PC 0x0c0ac48e */
if(!s->budget--) { s->failed_pc=0x0c0ac48eu; return 0; }
goto P_0c0ac4c0;
P_0c0ac490: /* original 0009, guest PC 0x0c0ac490 */
if(!s->budget--) { s->failed_pc=0x0c0ac490u; return 0; }
if(!vf3_matrix_family(0x0c0ac492u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac492u; return 0; } return 1;
P_0c0ac4c0: /* original f5e0, guest PC 0x0c0ac4c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac4c0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'+');
goto P_0c0ac4c2;
P_0c0ac4c2: /* original f4f8, guest PC 0x0c0ac4c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac4c2u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0ac4c4;
P_0c0ac4c4: /* original c73b, guest PC 0x0c0ac4c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac4c4u; return 0; }
r[0]=code_base|0x000ac5b4u;
goto P_0c0ac4c6;
P_0c0ac4c6: /* original f4f0, guest PC 0x0c0ac4c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac4c6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c0ac4c8;
P_0c0ac4c8: /* original f208, guest PC 0x0c0ac4c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac4c8u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ac4ca;
P_0c0ac4ca: /* original f35c, guest PC 0x0c0ac4ca */
if(!s->budget--) { s->failed_pc=0x0c0ac4cau; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ac4cc;
P_0c0ac4cc: /* original f532, guest PC 0x0c0ac4cc */
if(!s->budget--) { s->failed_pc=0x0c0ac4ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0ac4ce;
P_0c0ac4ce: /* original f04c, guest PC 0x0c0ac4ce */
if(!s->budget--) { s->failed_pc=0x0c0ac4ceu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ac4d0;
P_0c0ac4d0: /* original f54e, guest PC 0x0c0ac4d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac4d0u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[4],fr[5],r[18]);
goto P_0c0ac4d2;
P_0c0ac4d2: /* original f45c, guest PC 0x0c0ac4d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac4d2u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0ac4d4;
P_0c0ac4d4: /* original f245, guest PC 0x0c0ac4d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac4d4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0ac4d6;
P_0c0ac4d6: /* original 8901, guest PC 0x0c0ac4d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac4d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac4dc; }
goto P_0c0ac4d8;
P_0c0ac4d8: /* original f34c, guest PC 0x0c0ac4d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac4d8u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ac4da;
P_0c0ac4da: /* original f37d, guest PC 0x0c0ac4da */
if(!s->budget--) { s->failed_pc=0x0c0ac4dau; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0ac4dc;
P_0c0ac4dc: /* original 60d2, guest PC 0x0c0ac4dc */
if(!s->budget--) { s->failed_pc=0x0c0ac4dcu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0ac4de;
P_0c0ac4de: /* original c840, guest PC 0x0c0ac4de */
if(!s->budget--) { s->failed_pc=0x0c0ac4deu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0ac4e0;
P_0c0ac4e0: /* original 890c, guest PC 0x0c0ac4e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac4e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac4fc; }
goto P_0c0ac4e2;
P_0c0ac4e2: /* original 60d2, guest PC 0x0c0ac4e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac4e2u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0ac4e4;
P_0c0ac4e4: /* original c880, guest PC 0x0c0ac4e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac4e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0ac4e6;
P_0c0ac4e6: /* original 8b36, guest PC 0x0c0ac4e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac4e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac556; }
goto P_0c0ac4e8;
P_0c0ac4e8: /* original 62d2, guest PC 0x0c0ac4e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac4e8u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac4ea;
P_0c0ac4ea: /* original 9361, guest PC 0x0c0ac4ea */
if(!s->budget--) { s->failed_pc=0x0c0ac4eau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac5b0u,2);
goto P_0c0ac4ec;
P_0c0ac4ec: /* original 2238, guest PC 0x0c0ac4ec */
if(!s->budget--) { s->failed_pc=0x0c0ac4ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac4ee;
P_0c0ac4ee: /* original 8b0e, guest PC 0x0c0ac4ee */
if(!s->budget--) { s->failed_pc=0x0c0ac4eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac50e; }
goto P_0c0ac4f0;
P_0c0ac4f0: /* original 61e2, guest PC 0x0c0ac4f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac4f0u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ac4f2;
P_0c0ac4f2: /* original d331, guest PC 0x0c0ac4f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac4f2u; return 0; }
r[3]=read(ram,0x0c0ac5b8u,4);
goto P_0c0ac4f4;
P_0c0ac4f4: /* original 2138, guest PC 0x0c0ac4f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac4f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0ac4f6;
P_0c0ac4f6: /* original 8b0a, guest PC 0x0c0ac4f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac4f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac50e; }
goto P_0c0ac4f8;
P_0c0ac4f8: /* original a02d, guest PC 0x0c0ac4f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac4f8u; return 0; }
goto P_0c0ac556;
P_0c0ac4fa: /* original 0009, guest PC 0x0c0ac4fa */
if(!s->budget--) { s->failed_pc=0x0c0ac4fau; return 0; }
goto P_0c0ac4fc;
P_0c0ac4fc: /* original c804, guest PC 0x0c0ac4fc */
if(!s->budget--) { s->failed_pc=0x0c0ac4fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0ac4fe;
P_0c0ac4fe: /* original 8b61, guest PC 0x0c0ac4fe */
if(!s->budget--) { s->failed_pc=0x0c0ac4feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac5c4; }
goto P_0c0ac500;
P_0c0ac500: /* original 60d2, guest PC 0x0c0ac500 */
if(!s->budget--) { s->failed_pc=0x0c0ac500u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0ac502;
P_0c0ac502: /* original c802, guest PC 0x0c0ac502 */
if(!s->budget--) { s->failed_pc=0x0c0ac502u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0ac504;
P_0c0ac504: /* original 8901, guest PC 0x0c0ac504 */
if(!s->budget--) { s->failed_pc=0x0c0ac504u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac50a; }
goto P_0c0ac506;
P_0c0ac506: /* original a07f, guest PC 0x0c0ac506 */
if(!s->budget--) { s->failed_pc=0x0c0ac506u; return 0; }
goto P_0c0ac608;
P_0c0ac508: /* original 0009, guest PC 0x0c0ac508 */
if(!s->budget--) { s->failed_pc=0x0c0ac508u; return 0; }
goto P_0c0ac50a;
P_0c0ac50a: /* original a128, guest PC 0x0c0ac50a */
if(!s->budget--) { s->failed_pc=0x0c0ac50au; return 0; }
goto P_0c0ac75e;
P_0c0ac50c: /* original 0009, guest PC 0x0c0ac50c */
if(!s->budget--) { s->failed_pc=0x0c0ac50cu; return 0; }
goto P_0c0ac50e;
P_0c0ac50e: /* original d22b, guest PC 0x0c0ac50e */
if(!s->budget--) { s->failed_pc=0x0c0ac50eu; return 0; }
r[2]=read(ram,0x0c0ac5bcu,4);
goto P_0c0ac510;
P_0c0ac510: /* original 2288, guest PC 0x0c0ac510 */
if(!s->budget--) { s->failed_pc=0x0c0ac510u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c0ac512;
P_0c0ac512: /* original 8b0e, guest PC 0x0c0ac512 */
if(!s->budget--) { s->failed_pc=0x0c0ac512u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac532; }
goto P_0c0ac514;
P_0c0ac514: /* original 65c3, guest PC 0x0c0ac514 */
if(!s->budget--) { s->failed_pc=0x0c0ac514u; return 0; }
r[5]=r[12];
goto P_0c0ac516;
P_0c0ac516: /* original 7566, guest PC 0x0c0ac516 */
if(!s->budget--) { s->failed_pc=0x0c0ac516u; return 0; }
r[5]+=0x00000066u;
goto P_0c0ac518;
P_0c0ac518: /* original 6551, guest PC 0x0c0ac518 */
if(!s->budget--) { s->failed_pc=0x0c0ac518u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac51a;
P_0c0ac51a: /* original 2a98, guest PC 0x0c0ac51a */
if(!s->budget--) { s->failed_pc=0x0c0ac51au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac51c;
P_0c0ac51c: /* original 8f02, guest PC 0x0c0ac51c */
if(!s->budget--) { s->failed_pc=0x0c0ac51cu; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac524; }
goto P_0c0ac520;
P_0c0ac51e: /* original 655d, guest PC 0x0c0ac51e */
if(!s->budget--) { s->failed_pc=0x0c0ac51eu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac520;
P_0c0ac520: /* original a149, guest PC 0x0c0ac520 */
if(!s->budget--) { s->failed_pc=0x0c0ac520u; return 0; }
goto P_0c0ac7b6;
P_0c0ac522: /* original 0009, guest PC 0x0c0ac522 */
if(!s->budget--) { s->failed_pc=0x0c0ac522u; return 0; }
goto P_0c0ac524;
P_0c0ac524: /* original 63d2, guest PC 0x0c0ac524 */
if(!s->budget--) { s->failed_pc=0x0c0ac524u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac526;
P_0c0ac526: /* original 65c3, guest PC 0x0c0ac526 */
if(!s->budget--) { s->failed_pc=0x0c0ac526u; return 0; }
r[5]=r[12];
goto P_0c0ac528;
P_0c0ac528: /* original 7568, guest PC 0x0c0ac528 */
if(!s->budget--) { s->failed_pc=0x0c0ac528u; return 0; }
r[5]+=0x00000068u;
goto P_0c0ac52a;
P_0c0ac52a: /* original 23bb, guest PC 0x0c0ac52a */
if(!s->budget--) { s->failed_pc=0x0c0ac52au; return 0; }
r[3]|=r[11];
goto P_0c0ac52c;
P_0c0ac52c: /* original 2d32, guest PC 0x0c0ac52c */
if(!s->budget--) { s->failed_pc=0x0c0ac52cu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac52e;
P_0c0ac52e: /* original a141, guest PC 0x0c0ac52e */
if(!s->budget--) { s->failed_pc=0x0c0ac52eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac7b4;
P_0c0ac530: /* original 6551, guest PC 0x0c0ac530 */
if(!s->budget--) { s->failed_pc=0x0c0ac530u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac532;
P_0c0ac532: /* original 65c3, guest PC 0x0c0ac532 */
if(!s->budget--) { s->failed_pc=0x0c0ac532u; return 0; }
r[5]=r[12];
goto P_0c0ac534;
P_0c0ac534: /* original 62d2, guest PC 0x0c0ac534 */
if(!s->budget--) { s->failed_pc=0x0c0ac534u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac536;
P_0c0ac536: /* original 933c, guest PC 0x0c0ac536 */
if(!s->budget--) { s->failed_pc=0x0c0ac536u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac5b2u,2);
goto P_0c0ac538;
P_0c0ac538: /* original 756a, guest PC 0x0c0ac538 */
if(!s->budget--) { s->failed_pc=0x0c0ac538u; return 0; }
r[5]+=0x0000006au;
goto P_0c0ac53a;
P_0c0ac53a: /* original 2a98, guest PC 0x0c0ac53a */
if(!s->budget--) { s->failed_pc=0x0c0ac53au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac53c;
P_0c0ac53c: /* original 223b, guest PC 0x0c0ac53c */
if(!s->budget--) { s->failed_pc=0x0c0ac53cu; return 0; }
r[2]|=r[3];
goto P_0c0ac53e;
P_0c0ac53e: /* original 2d22, guest PC 0x0c0ac53e */
if(!s->budget--) { s->failed_pc=0x0c0ac53eu; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ac540;
P_0c0ac540: /* original 6551, guest PC 0x0c0ac540 */
if(!s->budget--) { s->failed_pc=0x0c0ac540u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac542;
P_0c0ac542: /* original 8f02, guest PC 0x0c0ac542 */
if(!s->budget--) { s->failed_pc=0x0c0ac542u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac54a; }
goto P_0c0ac546;
P_0c0ac544: /* original 655d, guest PC 0x0c0ac544 */
if(!s->budget--) { s->failed_pc=0x0c0ac544u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac546;
P_0c0ac546: /* original a136, guest PC 0x0c0ac546 */
if(!s->budget--) { s->failed_pc=0x0c0ac546u; return 0; }
goto P_0c0ac7b6;
P_0c0ac548: /* original 0009, guest PC 0x0c0ac548 */
if(!s->budget--) { s->failed_pc=0x0c0ac548u; return 0; }
goto P_0c0ac54a;
P_0c0ac54a: /* original 63d2, guest PC 0x0c0ac54a */
if(!s->budget--) { s->failed_pc=0x0c0ac54au; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac54c;
P_0c0ac54c: /* original 65c3, guest PC 0x0c0ac54c */
if(!s->budget--) { s->failed_pc=0x0c0ac54cu; return 0; }
r[5]=r[12];
goto P_0c0ac54e;
P_0c0ac54e: /* original 23bb, guest PC 0x0c0ac54e */
if(!s->budget--) { s->failed_pc=0x0c0ac54eu; return 0; }
r[3]|=r[11];
goto P_0c0ac550;
P_0c0ac550: /* original 2d32, guest PC 0x0c0ac550 */
if(!s->budget--) { s->failed_pc=0x0c0ac550u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac552;
P_0c0ac552: /* original afec, guest PC 0x0c0ac552 */
if(!s->budget--) { s->failed_pc=0x0c0ac552u; return 0; }
r[5]+=0x0000006cu;
goto P_0c0ac52e;
P_0c0ac554: /* original 756c, guest PC 0x0c0ac554 */
if(!s->budget--) { s->failed_pc=0x0c0ac554u; return 0; }
r[5]+=0x0000006cu;
goto P_0c0ac556;
P_0c0ac556: /* original d219, guest PC 0x0c0ac556 */
if(!s->budget--) { s->failed_pc=0x0c0ac556u; return 0; }
r[2]=read(ram,0x0c0ac5bcu,4);
goto P_0c0ac558;
P_0c0ac558: /* original 2288, guest PC 0x0c0ac558 */
if(!s->budget--) { s->failed_pc=0x0c0ac558u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c0ac55a;
P_0c0ac55a: /* original 8b0d, guest PC 0x0c0ac55a */
if(!s->budget--) { s->failed_pc=0x0c0ac55au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac578; }
goto P_0c0ac55c;
P_0c0ac55c: /* original 65c3, guest PC 0x0c0ac55c */
if(!s->budget--) { s->failed_pc=0x0c0ac55cu; return 0; }
r[5]=r[12];
goto P_0c0ac55e;
P_0c0ac55e: /* original 755e, guest PC 0x0c0ac55e */
if(!s->budget--) { s->failed_pc=0x0c0ac55eu; return 0; }
r[5]+=0x0000005eu;
goto P_0c0ac560;
P_0c0ac560: /* original 6551, guest PC 0x0c0ac560 */
if(!s->budget--) { s->failed_pc=0x0c0ac560u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac562;
P_0c0ac562: /* original 2a98, guest PC 0x0c0ac562 */
if(!s->budget--) { s->failed_pc=0x0c0ac562u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac564;
P_0c0ac564: /* original 8f02, guest PC 0x0c0ac564 */
if(!s->budget--) { s->failed_pc=0x0c0ac564u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac56c; }
goto P_0c0ac568;
P_0c0ac566: /* original 655d, guest PC 0x0c0ac566 */
if(!s->budget--) { s->failed_pc=0x0c0ac566u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac568;
P_0c0ac568: /* original a125, guest PC 0x0c0ac568 */
if(!s->budget--) { s->failed_pc=0x0c0ac568u; return 0; }
goto P_0c0ac7b6;
P_0c0ac56a: /* original 0009, guest PC 0x0c0ac56a */
if(!s->budget--) { s->failed_pc=0x0c0ac56au; return 0; }
goto P_0c0ac56c;
P_0c0ac56c: /* original 63d2, guest PC 0x0c0ac56c */
if(!s->budget--) { s->failed_pc=0x0c0ac56cu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac56e;
P_0c0ac56e: /* original 65c3, guest PC 0x0c0ac56e */
if(!s->budget--) { s->failed_pc=0x0c0ac56eu; return 0; }
r[5]=r[12];
goto P_0c0ac570;
P_0c0ac570: /* original 23bb, guest PC 0x0c0ac570 */
if(!s->budget--) { s->failed_pc=0x0c0ac570u; return 0; }
r[3]|=r[11];
goto P_0c0ac572;
P_0c0ac572: /* original 2d32, guest PC 0x0c0ac572 */
if(!s->budget--) { s->failed_pc=0x0c0ac572u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac574;
P_0c0ac574: /* original afdb, guest PC 0x0c0ac574 */
if(!s->budget--) { s->failed_pc=0x0c0ac574u; return 0; }
r[5]+=0x00000060u;
goto P_0c0ac52e;
P_0c0ac576: /* original 7560, guest PC 0x0c0ac576 */
if(!s->budget--) { s->failed_pc=0x0c0ac576u; return 0; }
r[5]+=0x00000060u;
goto P_0c0ac578;
P_0c0ac578: /* original 65c3, guest PC 0x0c0ac578 */
if(!s->budget--) { s->failed_pc=0x0c0ac578u; return 0; }
r[5]=r[12];
goto P_0c0ac57a;
P_0c0ac57a: /* original 62d2, guest PC 0x0c0ac57a */
if(!s->budget--) { s->failed_pc=0x0c0ac57au; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac57c;
P_0c0ac57c: /* original 9319, guest PC 0x0c0ac57c */
if(!s->budget--) { s->failed_pc=0x0c0ac57cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac5b2u,2);
goto P_0c0ac57e;
P_0c0ac57e: /* original 7562, guest PC 0x0c0ac57e */
if(!s->budget--) { s->failed_pc=0x0c0ac57eu; return 0; }
r[5]+=0x00000062u;
goto P_0c0ac580;
P_0c0ac580: /* original 2a98, guest PC 0x0c0ac580 */
if(!s->budget--) { s->failed_pc=0x0c0ac580u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac582;
P_0c0ac582: /* original 223b, guest PC 0x0c0ac582 */
if(!s->budget--) { s->failed_pc=0x0c0ac582u; return 0; }
r[2]|=r[3];
goto P_0c0ac584;
P_0c0ac584: /* original 2d22, guest PC 0x0c0ac584 */
if(!s->budget--) { s->failed_pc=0x0c0ac584u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ac586;
P_0c0ac586: /* original 6551, guest PC 0x0c0ac586 */
if(!s->budget--) { s->failed_pc=0x0c0ac586u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac588;
P_0c0ac588: /* original 8f02, guest PC 0x0c0ac588 */
if(!s->budget--) { s->failed_pc=0x0c0ac588u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac590; }
goto P_0c0ac58c;
P_0c0ac58a: /* original 655d, guest PC 0x0c0ac58a */
if(!s->budget--) { s->failed_pc=0x0c0ac58au; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac58c;
P_0c0ac58c: /* original a113, guest PC 0x0c0ac58c */
if(!s->budget--) { s->failed_pc=0x0c0ac58cu; return 0; }
goto P_0c0ac7b6;
P_0c0ac58e: /* original 0009, guest PC 0x0c0ac58e */
if(!s->budget--) { s->failed_pc=0x0c0ac58eu; return 0; }
goto P_0c0ac590;
P_0c0ac590: /* original 65c3, guest PC 0x0c0ac590 */
if(!s->budget--) { s->failed_pc=0x0c0ac590u; return 0; }
r[5]=r[12];
goto P_0c0ac592;
P_0c0ac592: /* original 63d2, guest PC 0x0c0ac592 */
if(!s->budget--) { s->failed_pc=0x0c0ac592u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac594;
P_0c0ac594: /* original 7565, guest PC 0x0c0ac594 */
if(!s->budget--) { s->failed_pc=0x0c0ac594u; return 0; }
r[5]+=0x00000065u;
goto P_0c0ac596;
P_0c0ac596: /* original 62c3, guest PC 0x0c0ac596 */
if(!s->budget--) { s->failed_pc=0x0c0ac596u; return 0; }
r[2]=r[12];
goto P_0c0ac598;
P_0c0ac598: /* original 23bb, guest PC 0x0c0ac598 */
if(!s->budget--) { s->failed_pc=0x0c0ac598u; return 0; }
r[3]|=r[11];
goto P_0c0ac59a;
P_0c0ac59a: /* original 7264, guest PC 0x0c0ac59a */
if(!s->budget--) { s->failed_pc=0x0c0ac59au; return 0; }
r[2]+=0x00000064u;
goto P_0c0ac59c;
P_0c0ac59c: /* original 2d32, guest PC 0x0c0ac59c */
if(!s->budget--) { s->failed_pc=0x0c0ac59cu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac59e;
P_0c0ac59e: /* original 6550, guest PC 0x0c0ac59e */
if(!s->budget--) { s->failed_pc=0x0c0ac59eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c0ac5a0;
P_0c0ac5a0: /* original 6120, guest PC 0x0c0ac5a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac5a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0ac5a2;
P_0c0ac5a2: /* original d307, guest PC 0x0c0ac5a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac5a2u; return 0; }
r[3]=read(ram,0x0c0ac5c0u,4);
goto P_0c0ac5a4;
P_0c0ac5a4: /* original 655c, guest PC 0x0c0ac5a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac5a4u; return 0; }
r[5]=r[5]&255u;
goto P_0c0ac5a6;
P_0c0ac5a6: /* original 4518, guest PC 0x0c0ac5a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac5a6u; return 0; }
r[5]<<=8;
goto P_0c0ac5a8;
P_0c0ac5a8: /* original 611c, guest PC 0x0c0ac5a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac5a8u; return 0; }
r[1]=r[1]&255u;
goto P_0c0ac5aa;
P_0c0ac5aa: /* original 2539, guest PC 0x0c0ac5aa */
if(!s->budget--) { s->failed_pc=0x0c0ac5aau; return 0; }
r[5]&=r[3];
goto P_0c0ac5ac;
P_0c0ac5ac: /* original a103, guest PC 0x0c0ac5ac */
if(!s->budget--) { s->failed_pc=0x0c0ac5acu; return 0; }
r[5]|=r[1];
goto P_0c0ac7b6;
P_0c0ac5ae: /* original 251b, guest PC 0x0c0ac5ae */
if(!s->budget--) { s->failed_pc=0x0c0ac5aeu; return 0; }
r[5]|=r[1];
if(!vf3_matrix_family(0x0c0ac5b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac5b0u; return 0; } return 1;
P_0c0ac5c4: /* original d344, guest PC 0x0c0ac5c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac5c4u; return 0; }
r[3]=read(ram,0x0c0ac6d8u,4);
goto P_0c0ac5c6;
P_0c0ac5c6: /* original 2388, guest PC 0x0c0ac5c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac5c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0ac5c8;
P_0c0ac5c8: /* original 8b0d, guest PC 0x0c0ac5c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac5c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac5e6; }
goto P_0c0ac5ca;
P_0c0ac5ca: /* original 9077, guest PC 0x0c0ac5ca */
if(!s->budget--) { s->failed_pc=0x0c0ac5cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6bcu,2);
goto P_0c0ac5cc;
P_0c0ac5cc: /* original 2a98, guest PC 0x0c0ac5cc */
if(!s->budget--) { s->failed_pc=0x0c0ac5ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac5ce;
P_0c0ac5ce: /* original 05cd, guest PC 0x0c0ac5ce */
if(!s->budget--) { s->failed_pc=0x0c0ac5ceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac5d0;
P_0c0ac5d0: /* original 8f02, guest PC 0x0c0ac5d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac5d0u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac5d8; }
goto P_0c0ac5d4;
P_0c0ac5d2: /* original 655d, guest PC 0x0c0ac5d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac5d2u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac5d4;
P_0c0ac5d4: /* original a0ef, guest PC 0x0c0ac5d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac5d4u; return 0; }
goto P_0c0ac7b6;
P_0c0ac5d6: /* original 0009, guest PC 0x0c0ac5d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac5d6u; return 0; }
goto P_0c0ac5d8;
P_0c0ac5d8: /* original 63d2, guest PC 0x0c0ac5d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac5d8u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac5da;
P_0c0ac5da: /* original 23bb, guest PC 0x0c0ac5da */
if(!s->budget--) { s->failed_pc=0x0c0ac5dau; return 0; }
r[3]|=r[11];
goto P_0c0ac5dc;
P_0c0ac5dc: /* original 2d32, guest PC 0x0c0ac5dc */
if(!s->budget--) { s->failed_pc=0x0c0ac5dcu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac5de;
P_0c0ac5de: /* original 906e, guest PC 0x0c0ac5de */
if(!s->budget--) { s->failed_pc=0x0c0ac5deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6beu,2);
goto P_0c0ac5e0;
P_0c0ac5e0: /* original 05cd, guest PC 0x0c0ac5e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac5e0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac5e2;
P_0c0ac5e2: /* original a0e8, guest PC 0x0c0ac5e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac5e2u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac7b6;
P_0c0ac5e4: /* original 655d, guest PC 0x0c0ac5e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac5e4u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac5e6;
P_0c0ac5e6: /* original 62d2, guest PC 0x0c0ac5e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac5e6u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac5e8;
P_0c0ac5e8: /* original 2a98, guest PC 0x0c0ac5e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac5e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac5ea;
P_0c0ac5ea: /* original 9369, guest PC 0x0c0ac5ea */
if(!s->budget--) { s->failed_pc=0x0c0ac5eau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6c0u,2);
goto P_0c0ac5ec;
P_0c0ac5ec: /* original 223b, guest PC 0x0c0ac5ec */
if(!s->budget--) { s->failed_pc=0x0c0ac5ecu; return 0; }
r[2]|=r[3];
goto P_0c0ac5ee;
P_0c0ac5ee: /* original 2d22, guest PC 0x0c0ac5ee */
if(!s->budget--) { s->failed_pc=0x0c0ac5eeu; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ac5f0;
P_0c0ac5f0: /* original 9067, guest PC 0x0c0ac5f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac5f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6c2u,2);
goto P_0c0ac5f2;
P_0c0ac5f2: /* original 05cd, guest PC 0x0c0ac5f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac5f2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac5f4;
P_0c0ac5f4: /* original 8f02, guest PC 0x0c0ac5f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac5f4u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac5fc; }
goto P_0c0ac5f8;
P_0c0ac5f6: /* original 655d, guest PC 0x0c0ac5f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac5f6u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac5f8;
P_0c0ac5f8: /* original a0dd, guest PC 0x0c0ac5f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac5f8u; return 0; }
goto P_0c0ac7b6;
P_0c0ac5fa: /* original 0009, guest PC 0x0c0ac5fa */
if(!s->budget--) { s->failed_pc=0x0c0ac5fau; return 0; }
goto P_0c0ac5fc;
P_0c0ac5fc: /* original 63d2, guest PC 0x0c0ac5fc */
if(!s->budget--) { s->failed_pc=0x0c0ac5fcu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac5fe;
P_0c0ac5fe: /* original 23bb, guest PC 0x0c0ac5fe */
if(!s->budget--) { s->failed_pc=0x0c0ac5feu; return 0; }
r[3]|=r[11];
goto P_0c0ac600;
P_0c0ac600: /* original 2d32, guest PC 0x0c0ac600 */
if(!s->budget--) { s->failed_pc=0x0c0ac600u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac602;
P_0c0ac602: /* original 905f, guest PC 0x0c0ac602 */
if(!s->budget--) { s->failed_pc=0x0c0ac602u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6c4u,2);
goto P_0c0ac604;
P_0c0ac604: /* original a01f, guest PC 0x0c0ac604 */
if(!s->budget--) { s->failed_pc=0x0c0ac604u; return 0; }
goto P_0c0ac646;
P_0c0ac606: /* original 0009, guest PC 0x0c0ac606 */
if(!s->budget--) { s->failed_pc=0x0c0ac606u; return 0; }
goto P_0c0ac608;
P_0c0ac608: /* original d333, guest PC 0x0c0ac608 */
if(!s->budget--) { s->failed_pc=0x0c0ac608u; return 0; }
r[3]=read(ram,0x0c0ac6d8u,4);
goto P_0c0ac60a;
P_0c0ac60a: /* original 2388, guest PC 0x0c0ac60a */
if(!s->budget--) { s->failed_pc=0x0c0ac60au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0ac60c;
P_0c0ac60c: /* original 8b0c, guest PC 0x0c0ac60c */
if(!s->budget--) { s->failed_pc=0x0c0ac60cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac628; }
goto P_0c0ac60e;
P_0c0ac60e: /* original 905a, guest PC 0x0c0ac60e */
if(!s->budget--) { s->failed_pc=0x0c0ac60eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6c6u,2);
goto P_0c0ac610;
P_0c0ac610: /* original 2a98, guest PC 0x0c0ac610 */
if(!s->budget--) { s->failed_pc=0x0c0ac610u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac612;
P_0c0ac612: /* original 05cd, guest PC 0x0c0ac612 */
if(!s->budget--) { s->failed_pc=0x0c0ac612u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac614;
P_0c0ac614: /* original 8f02, guest PC 0x0c0ac614 */
if(!s->budget--) { s->failed_pc=0x0c0ac614u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac61c; }
goto P_0c0ac618;
P_0c0ac616: /* original 655d, guest PC 0x0c0ac616 */
if(!s->budget--) { s->failed_pc=0x0c0ac616u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac618;
P_0c0ac618: /* original a0cd, guest PC 0x0c0ac618 */
if(!s->budget--) { s->failed_pc=0x0c0ac618u; return 0; }
goto P_0c0ac7b6;
P_0c0ac61a: /* original 0009, guest PC 0x0c0ac61a */
if(!s->budget--) { s->failed_pc=0x0c0ac61au; return 0; }
goto P_0c0ac61c;
P_0c0ac61c: /* original 63d2, guest PC 0x0c0ac61c */
if(!s->budget--) { s->failed_pc=0x0c0ac61cu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac61e;
P_0c0ac61e: /* original 23bb, guest PC 0x0c0ac61e */
if(!s->budget--) { s->failed_pc=0x0c0ac61eu; return 0; }
r[3]|=r[11];
goto P_0c0ac620;
P_0c0ac620: /* original 2d32, guest PC 0x0c0ac620 */
if(!s->budget--) { s->failed_pc=0x0c0ac620u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac622;
P_0c0ac622: /* original 9051, guest PC 0x0c0ac622 */
if(!s->budget--) { s->failed_pc=0x0c0ac622u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6c8u,2);
goto P_0c0ac624;
P_0c0ac624: /* original a0c6, guest PC 0x0c0ac624 */
if(!s->budget--) { s->failed_pc=0x0c0ac624u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac7b4;
P_0c0ac626: /* original 05cd, guest PC 0x0c0ac626 */
if(!s->budget--) { s->failed_pc=0x0c0ac626u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac628;
P_0c0ac628: /* original 62d2, guest PC 0x0c0ac628 */
if(!s->budget--) { s->failed_pc=0x0c0ac628u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac62a;
P_0c0ac62a: /* original 2a98, guest PC 0x0c0ac62a */
if(!s->budget--) { s->failed_pc=0x0c0ac62au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac62c;
P_0c0ac62c: /* original 9348, guest PC 0x0c0ac62c */
if(!s->budget--) { s->failed_pc=0x0c0ac62cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6c0u,2);
goto P_0c0ac62e;
P_0c0ac62e: /* original 223b, guest PC 0x0c0ac62e */
if(!s->budget--) { s->failed_pc=0x0c0ac62eu; return 0; }
r[2]|=r[3];
goto P_0c0ac630;
P_0c0ac630: /* original 2d22, guest PC 0x0c0ac630 */
if(!s->budget--) { s->failed_pc=0x0c0ac630u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ac632;
P_0c0ac632: /* original 904a, guest PC 0x0c0ac632 */
if(!s->budget--) { s->failed_pc=0x0c0ac632u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6cau,2);
goto P_0c0ac634;
P_0c0ac634: /* original 05cd, guest PC 0x0c0ac634 */
if(!s->budget--) { s->failed_pc=0x0c0ac634u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac636;
P_0c0ac636: /* original 8f02, guest PC 0x0c0ac636 */
if(!s->budget--) { s->failed_pc=0x0c0ac636u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac63e; }
goto P_0c0ac63a;
P_0c0ac638: /* original 655d, guest PC 0x0c0ac638 */
if(!s->budget--) { s->failed_pc=0x0c0ac638u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac63a;
P_0c0ac63a: /* original a0bc, guest PC 0x0c0ac63a */
if(!s->budget--) { s->failed_pc=0x0c0ac63au; return 0; }
goto P_0c0ac7b6;
P_0c0ac63c: /* original 0009, guest PC 0x0c0ac63c */
if(!s->budget--) { s->failed_pc=0x0c0ac63cu; return 0; }
goto P_0c0ac63e;
P_0c0ac63e: /* original 63d2, guest PC 0x0c0ac63e */
if(!s->budget--) { s->failed_pc=0x0c0ac63eu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac640;
P_0c0ac640: /* original 23bb, guest PC 0x0c0ac640 */
if(!s->budget--) { s->failed_pc=0x0c0ac640u; return 0; }
r[3]|=r[11];
goto P_0c0ac642;
P_0c0ac642: /* original 2d32, guest PC 0x0c0ac642 */
if(!s->budget--) { s->failed_pc=0x0c0ac642u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac644;
P_0c0ac644: /* original 9042, guest PC 0x0c0ac644 */
if(!s->budget--) { s->failed_pc=0x0c0ac644u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6ccu,2);
goto P_0c0ac646;
P_0c0ac646: /* original a0b5, guest PC 0x0c0ac646 */
if(!s->budget--) { s->failed_pc=0x0c0ac646u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac7b4;
P_0c0ac648: /* original 05cd, guest PC 0x0c0ac648 */
if(!s->budget--) { s->failed_pc=0x0c0ac648u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac64a;
P_0c0ac64a: /* original d323, guest PC 0x0c0ac64a */
if(!s->budget--) { s->failed_pc=0x0c0ac64au; return 0; }
r[3]=read(ram,0x0c0ac6d8u,4);
goto P_0c0ac64c;
P_0c0ac64c: /* original 2388, guest PC 0x0c0ac64c */
if(!s->budget--) { s->failed_pc=0x0c0ac64cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0ac64e;
P_0c0ac64e: /* original 8b0d, guest PC 0x0c0ac64e */
if(!s->budget--) { s->failed_pc=0x0c0ac64eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac66c; }
goto P_0c0ac650;
P_0c0ac650: /* original 65c3, guest PC 0x0c0ac650 */
if(!s->budget--) { s->failed_pc=0x0c0ac650u; return 0; }
r[5]=r[12];
goto P_0c0ac652;
P_0c0ac652: /* original 757e, guest PC 0x0c0ac652 */
if(!s->budget--) { s->failed_pc=0x0c0ac652u; return 0; }
r[5]+=0x0000007eu;
goto P_0c0ac654;
P_0c0ac654: /* original 6551, guest PC 0x0c0ac654 */
if(!s->budget--) { s->failed_pc=0x0c0ac654u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac656;
P_0c0ac656: /* original 2a98, guest PC 0x0c0ac656 */
if(!s->budget--) { s->failed_pc=0x0c0ac656u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac658;
P_0c0ac658: /* original 8f02, guest PC 0x0c0ac658 */
if(!s->budget--) { s->failed_pc=0x0c0ac658u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac660; }
goto P_0c0ac65c;
P_0c0ac65a: /* original 655d, guest PC 0x0c0ac65a */
if(!s->budget--) { s->failed_pc=0x0c0ac65au; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac65c;
P_0c0ac65c: /* original a0ab, guest PC 0x0c0ac65c */
if(!s->budget--) { s->failed_pc=0x0c0ac65cu; return 0; }
goto P_0c0ac7b6;
P_0c0ac65e: /* original 0009, guest PC 0x0c0ac65e */
if(!s->budget--) { s->failed_pc=0x0c0ac65eu; return 0; }
goto P_0c0ac660;
P_0c0ac660: /* original 63d2, guest PC 0x0c0ac660 */
if(!s->budget--) { s->failed_pc=0x0c0ac660u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac662;
P_0c0ac662: /* original 23bb, guest PC 0x0c0ac662 */
if(!s->budget--) { s->failed_pc=0x0c0ac662u; return 0; }
r[3]|=r[11];
goto P_0c0ac664;
P_0c0ac664: /* original 2d32, guest PC 0x0c0ac664 */
if(!s->budget--) { s->failed_pc=0x0c0ac664u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac666;
P_0c0ac666: /* original 9032, guest PC 0x0c0ac666 */
if(!s->budget--) { s->failed_pc=0x0c0ac666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6ceu,2);
goto P_0c0ac668;
P_0c0ac668: /* original afed, guest PC 0x0c0ac668 */
if(!s->budget--) { s->failed_pc=0x0c0ac668u; return 0; }
goto P_0c0ac646;
P_0c0ac66a: /* original 0009, guest PC 0x0c0ac66a */
if(!s->budget--) { s->failed_pc=0x0c0ac66au; return 0; }
goto P_0c0ac66c;
P_0c0ac66c: /* original 62d2, guest PC 0x0c0ac66c */
if(!s->budget--) { s->failed_pc=0x0c0ac66cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac66e;
P_0c0ac66e: /* original 2a98, guest PC 0x0c0ac66e */
if(!s->budget--) { s->failed_pc=0x0c0ac66eu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac670;
P_0c0ac670: /* original 9326, guest PC 0x0c0ac670 */
if(!s->budget--) { s->failed_pc=0x0c0ac670u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6c0u,2);
goto P_0c0ac672;
P_0c0ac672: /* original 223b, guest PC 0x0c0ac672 */
if(!s->budget--) { s->failed_pc=0x0c0ac672u; return 0; }
r[2]|=r[3];
goto P_0c0ac674;
P_0c0ac674: /* original 2d22, guest PC 0x0c0ac674 */
if(!s->budget--) { s->failed_pc=0x0c0ac674u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ac676;
P_0c0ac676: /* original 902b, guest PC 0x0c0ac676 */
if(!s->budget--) { s->failed_pc=0x0c0ac676u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6d0u,2);
goto P_0c0ac678;
P_0c0ac678: /* original 05cd, guest PC 0x0c0ac678 */
if(!s->budget--) { s->failed_pc=0x0c0ac678u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ac67a;
P_0c0ac67a: /* original 8f02, guest PC 0x0c0ac67a */
if(!s->budget--) { s->failed_pc=0x0c0ac67au; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac682; }
goto P_0c0ac67e;
P_0c0ac67c: /* original 655d, guest PC 0x0c0ac67c */
if(!s->budget--) { s->failed_pc=0x0c0ac67cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac67e;
P_0c0ac67e: /* original a09a, guest PC 0x0c0ac67e */
if(!s->budget--) { s->failed_pc=0x0c0ac67eu; return 0; }
goto P_0c0ac7b6;
P_0c0ac680: /* original 0009, guest PC 0x0c0ac680 */
if(!s->budget--) { s->failed_pc=0x0c0ac680u; return 0; }
goto P_0c0ac682;
P_0c0ac682: /* original 63d2, guest PC 0x0c0ac682 */
if(!s->budget--) { s->failed_pc=0x0c0ac682u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac684;
P_0c0ac684: /* original 23bb, guest PC 0x0c0ac684 */
if(!s->budget--) { s->failed_pc=0x0c0ac684u; return 0; }
r[3]|=r[11];
goto P_0c0ac686;
P_0c0ac686: /* original 2d32, guest PC 0x0c0ac686 */
if(!s->budget--) { s->failed_pc=0x0c0ac686u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac688;
P_0c0ac688: /* original 9023, guest PC 0x0c0ac688 */
if(!s->budget--) { s->failed_pc=0x0c0ac688u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6d2u,2);
goto P_0c0ac68a;
P_0c0ac68a: /* original afdc, guest PC 0x0c0ac68a */
if(!s->budget--) { s->failed_pc=0x0c0ac68au; return 0; }
goto P_0c0ac646;
P_0c0ac68c: /* original 0009, guest PC 0x0c0ac68c */
if(!s->budget--) { s->failed_pc=0x0c0ac68cu; return 0; }
goto P_0c0ac68e;
P_0c0ac68e: /* original 9021, guest PC 0x0c0ac68e */
if(!s->budget--) { s->failed_pc=0x0c0ac68eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac6d4u,2);
goto P_0c0ac690;
P_0c0ac690: /* original f3e6, guest PC 0x0c0ac690 */
if(!s->budget--) { s->failed_pc=0x0c0ac690u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac692;
P_0c0ac692: /* original f435, guest PC 0x0c0ac692 */
if(!s->budget--) { s->failed_pc=0x0c0ac692u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0ac694;
P_0c0ac694: /* original 8963, guest PC 0x0c0ac694 */
if(!s->budget--) { s->failed_pc=0x0c0ac694u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac75e; }
goto P_0c0ac696;
P_0c0ac696: /* original d310, guest PC 0x0c0ac696 */
if(!s->budget--) { s->failed_pc=0x0c0ac696u; return 0; }
r[3]=read(ram,0x0c0ac6d8u,4);
goto P_0c0ac698;
P_0c0ac698: /* original 2388, guest PC 0x0c0ac698 */
if(!s->budget--) { s->failed_pc=0x0c0ac698u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0ac69a;
P_0c0ac69a: /* original 8b4a, guest PC 0x0c0ac69a */
if(!s->budget--) { s->failed_pc=0x0c0ac69au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac732; }
goto P_0c0ac69c;
P_0c0ac69c: /* original 65c3, guest PC 0x0c0ac69c */
if(!s->budget--) { s->failed_pc=0x0c0ac69cu; return 0; }
r[5]=r[12];
goto P_0c0ac69e;
P_0c0ac69e: /* original 756e, guest PC 0x0c0ac69e */
if(!s->budget--) { s->failed_pc=0x0c0ac69eu; return 0; }
r[5]+=0x0000006eu;
goto P_0c0ac6a0;
P_0c0ac6a0: /* original 6551, guest PC 0x0c0ac6a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac6a0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac6a2;
P_0c0ac6a2: /* original 2a98, guest PC 0x0c0ac6a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac6a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac6a4;
P_0c0ac6a4: /* original 8f02, guest PC 0x0c0ac6a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac6a4u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0ac6ac; }
goto P_0c0ac6a8;
P_0c0ac6a6: /* original 655d, guest PC 0x0c0ac6a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac6a6u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac6a8;
P_0c0ac6a8: /* original a085, guest PC 0x0c0ac6a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac6a8u; return 0; }
goto P_0c0ac7b6;
P_0c0ac6aa: /* original 0009, guest PC 0x0c0ac6aa */
if(!s->budget--) { s->failed_pc=0x0c0ac6aau; return 0; }
goto P_0c0ac6ac;
P_0c0ac6ac: /* original 65c3, guest PC 0x0c0ac6ac */
if(!s->budget--) { s->failed_pc=0x0c0ac6acu; return 0; }
r[5]=r[12];
goto P_0c0ac6ae;
P_0c0ac6ae: /* original 63d2, guest PC 0x0c0ac6ae */
if(!s->budget--) { s->failed_pc=0x0c0ac6aeu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac6b0;
P_0c0ac6b0: /* original 7570, guest PC 0x0c0ac6b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac6b0u; return 0; }
r[5]+=0x00000070u;
goto P_0c0ac6b2;
P_0c0ac6b2: /* original 23bb, guest PC 0x0c0ac6b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac6b2u; return 0; }
r[3]|=r[11];
goto P_0c0ac6b4;
P_0c0ac6b4: /* original 2d32, guest PC 0x0c0ac6b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac6b4u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac6b6;
P_0c0ac6b6: /* original 6551, guest PC 0x0c0ac6b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac6b6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac6b8;
P_0c0ac6b8: /* original a07d, guest PC 0x0c0ac6b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac6b8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac7b6;
P_0c0ac6ba: /* original 655d, guest PC 0x0c0ac6ba */
if(!s->budget--) { s->failed_pc=0x0c0ac6bau; return 0; }
r[5]=r[5]&65535u;
if(!vf3_matrix_family(0x0c0ac6bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac6bcu; return 0; } return 1;
P_0c0ac6dc: /* original 62d2, guest PC 0x0c0ac6dc */
if(!s->budget--) { s->failed_pc=0x0c0ac6dcu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac6de;
P_0c0ac6de: /* original e3df, guest PC 0x0c0ac6de */
if(!s->budget--) { s->failed_pc=0x0c0ac6deu; return 0; }
r[3]=0xffffffdfu;
goto P_0c0ac6e0;
P_0c0ac6e0: /* original 65c3, guest PC 0x0c0ac6e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac6e0u; return 0; }
r[5]=r[12];
goto P_0c0ac6e2;
P_0c0ac6e2: /* original 7574, guest PC 0x0c0ac6e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac6e2u; return 0; }
r[5]+=0x00000074u;
goto P_0c0ac6e4;
P_0c0ac6e4: /* original 2239, guest PC 0x0c0ac6e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac6e4u; return 0; }
r[2]&=r[3];
goto P_0c0ac6e6;
P_0c0ac6e6: /* original 2d22, guest PC 0x0c0ac6e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac6e6u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ac6e8;
P_0c0ac6e8: /* original 2a98, guest PC 0x0c0ac6e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac6e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac6ea;
P_0c0ac6ea: /* original 61d2, guest PC 0x0c0ac6ea */
if(!s->budget--) { s->failed_pc=0x0c0ac6eau; return 0; }
tmp=read(ram,r[13],4);
r[1]=tmp;
goto P_0c0ac6ec;
P_0c0ac6ec: /* original 924c, guest PC 0x0c0ac6ec */
if(!s->budget--) { s->failed_pc=0x0c0ac6ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac788u,2);
goto P_0c0ac6ee;
P_0c0ac6ee: /* original 212b, guest PC 0x0c0ac6ee */
if(!s->budget--) { s->failed_pc=0x0c0ac6eeu; return 0; }
r[1]|=r[2];
goto P_0c0ac6f0;
P_0c0ac6f0: /* original 2d12, guest PC 0x0c0ac6f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac6f0u; return 0; }
write(ram,r[13],r[1],4);
goto P_0c0ac6f2;
P_0c0ac6f2: /* original 6551, guest PC 0x0c0ac6f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac6f2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac6f4;
P_0c0ac6f4: /* original 8d5f, guest PC 0x0c0ac6f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac6f4u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0ac7b6; }
goto P_0c0ac6f8;
P_0c0ac6f6: /* original 655d, guest PC 0x0c0ac6f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac6f6u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac6f8;
P_0c0ac6f8: /* original 65c3, guest PC 0x0c0ac6f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac6f8u; return 0; }
r[5]=r[12];
goto P_0c0ac6fa;
P_0c0ac6fa: /* original 63d2, guest PC 0x0c0ac6fa */
if(!s->budget--) { s->failed_pc=0x0c0ac6fau; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac6fc;
P_0c0ac6fc: /* original 7572, guest PC 0x0c0ac6fc */
if(!s->budget--) { s->failed_pc=0x0c0ac6fcu; return 0; }
r[5]+=0x00000072u;
goto P_0c0ac6fe;
P_0c0ac6fe: /* original 23bb, guest PC 0x0c0ac6fe */
if(!s->budget--) { s->failed_pc=0x0c0ac6feu; return 0; }
r[3]|=r[11];
goto P_0c0ac700;
P_0c0ac700: /* original 2d32, guest PC 0x0c0ac700 */
if(!s->budget--) { s->failed_pc=0x0c0ac700u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac702;
P_0c0ac702: /* original 6551, guest PC 0x0c0ac702 */
if(!s->budget--) { s->failed_pc=0x0c0ac702u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac704;
P_0c0ac704: /* original a057, guest PC 0x0c0ac704 */
if(!s->budget--) { s->failed_pc=0x0c0ac704u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac7b6;
P_0c0ac706: /* original 655d, guest PC 0x0c0ac706 */
if(!s->budget--) { s->failed_pc=0x0c0ac706u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac708;
P_0c0ac708: /* original 903f, guest PC 0x0c0ac708 */
if(!s->budget--) { s->failed_pc=0x0c0ac708u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac78au,2);
goto P_0c0ac70a;
P_0c0ac70a: /* original f3e6, guest PC 0x0c0ac70a */
if(!s->budget--) { s->failed_pc=0x0c0ac70au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac70c;
P_0c0ac70c: /* original f435, guest PC 0x0c0ac70c */
if(!s->budget--) { s->failed_pc=0x0c0ac70cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0ac70e;
P_0c0ac70e: /* original 8926, guest PC 0x0c0ac70e */
if(!s->budget--) { s->failed_pc=0x0c0ac70eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac75e; }
goto P_0c0ac710;
P_0c0ac710: /* original d31f, guest PC 0x0c0ac710 */
if(!s->budget--) { s->failed_pc=0x0c0ac710u; return 0; }
r[3]=read(ram,0x0c0ac790u,4);
goto P_0c0ac712;
P_0c0ac712: /* original 2388, guest PC 0x0c0ac712 */
if(!s->budget--) { s->failed_pc=0x0c0ac712u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0ac714;
P_0c0ac714: /* original 8be2, guest PC 0x0c0ac714 */
if(!s->budget--) { s->failed_pc=0x0c0ac714u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac6dc; }
goto P_0c0ac716;
P_0c0ac716: /* original 65c3, guest PC 0x0c0ac716 */
if(!s->budget--) { s->failed_pc=0x0c0ac716u; return 0; }
r[5]=r[12];
goto P_0c0ac718;
P_0c0ac718: /* original 7576, guest PC 0x0c0ac718 */
if(!s->budget--) { s->failed_pc=0x0c0ac718u; return 0; }
r[5]+=0x00000076u;
goto P_0c0ac71a;
P_0c0ac71a: /* original 6551, guest PC 0x0c0ac71a */
if(!s->budget--) { s->failed_pc=0x0c0ac71au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac71c;
P_0c0ac71c: /* original 2a98, guest PC 0x0c0ac71c */
if(!s->budget--) { s->failed_pc=0x0c0ac71cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac71e;
P_0c0ac71e: /* original 8d4a, guest PC 0x0c0ac71e */
if(!s->budget--) { s->failed_pc=0x0c0ac71eu; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0ac7b6; }
goto P_0c0ac722;
P_0c0ac720: /* original 655d, guest PC 0x0c0ac720 */
if(!s->budget--) { s->failed_pc=0x0c0ac720u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac722;
P_0c0ac722: /* original 65c3, guest PC 0x0c0ac722 */
if(!s->budget--) { s->failed_pc=0x0c0ac722u; return 0; }
r[5]=r[12];
goto P_0c0ac724;
P_0c0ac724: /* original 63d2, guest PC 0x0c0ac724 */
if(!s->budget--) { s->failed_pc=0x0c0ac724u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac726;
P_0c0ac726: /* original 7578, guest PC 0x0c0ac726 */
if(!s->budget--) { s->failed_pc=0x0c0ac726u; return 0; }
r[5]+=0x00000078u;
goto P_0c0ac728;
P_0c0ac728: /* original 23bb, guest PC 0x0c0ac728 */
if(!s->budget--) { s->failed_pc=0x0c0ac728u; return 0; }
r[3]|=r[11];
goto P_0c0ac72a;
P_0c0ac72a: /* original 2d32, guest PC 0x0c0ac72a */
if(!s->budget--) { s->failed_pc=0x0c0ac72au; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac72c;
P_0c0ac72c: /* original 6551, guest PC 0x0c0ac72c */
if(!s->budget--) { s->failed_pc=0x0c0ac72cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac72e;
P_0c0ac72e: /* original a042, guest PC 0x0c0ac72e */
if(!s->budget--) { s->failed_pc=0x0c0ac72eu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac7b6;
P_0c0ac730: /* original 655d, guest PC 0x0c0ac730 */
if(!s->budget--) { s->failed_pc=0x0c0ac730u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac732;
P_0c0ac732: /* original 62d2, guest PC 0x0c0ac732 */
if(!s->budget--) { s->failed_pc=0x0c0ac732u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac734;
P_0c0ac734: /* original e3ef, guest PC 0x0c0ac734 */
if(!s->budget--) { s->failed_pc=0x0c0ac734u; return 0; }
r[3]=0xffffffefu;
goto P_0c0ac736;
P_0c0ac736: /* original 65c3, guest PC 0x0c0ac736 */
if(!s->budget--) { s->failed_pc=0x0c0ac736u; return 0; }
r[5]=r[12];
goto P_0c0ac738;
P_0c0ac738: /* original 757c, guest PC 0x0c0ac738 */
if(!s->budget--) { s->failed_pc=0x0c0ac738u; return 0; }
r[5]+=0x0000007cu;
goto P_0c0ac73a;
P_0c0ac73a: /* original 2239, guest PC 0x0c0ac73a */
if(!s->budget--) { s->failed_pc=0x0c0ac73au; return 0; }
r[2]&=r[3];
goto P_0c0ac73c;
P_0c0ac73c: /* original 2d22, guest PC 0x0c0ac73c */
if(!s->budget--) { s->failed_pc=0x0c0ac73cu; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ac73e;
P_0c0ac73e: /* original 2a98, guest PC 0x0c0ac73e */
if(!s->budget--) { s->failed_pc=0x0c0ac73eu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac740;
P_0c0ac740: /* original 61d2, guest PC 0x0c0ac740 */
if(!s->budget--) { s->failed_pc=0x0c0ac740u; return 0; }
tmp=read(ram,r[13],4);
r[1]=tmp;
goto P_0c0ac742;
P_0c0ac742: /* original 9223, guest PC 0x0c0ac742 */
if(!s->budget--) { s->failed_pc=0x0c0ac742u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac78cu,2);
goto P_0c0ac744;
P_0c0ac744: /* original 212b, guest PC 0x0c0ac744 */
if(!s->budget--) { s->failed_pc=0x0c0ac744u; return 0; }
r[1]|=r[2];
goto P_0c0ac746;
P_0c0ac746: /* original 2d12, guest PC 0x0c0ac746 */
if(!s->budget--) { s->failed_pc=0x0c0ac746u; return 0; }
write(ram,r[13],r[1],4);
goto P_0c0ac748;
P_0c0ac748: /* original 6551, guest PC 0x0c0ac748 */
if(!s->budget--) { s->failed_pc=0x0c0ac748u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac74a;
P_0c0ac74a: /* original 8d34, guest PC 0x0c0ac74a */
if(!s->budget--) { s->failed_pc=0x0c0ac74au; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0ac7b6; }
goto P_0c0ac74e;
P_0c0ac74c: /* original 655d, guest PC 0x0c0ac74c */
if(!s->budget--) { s->failed_pc=0x0c0ac74cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac74e;
P_0c0ac74e: /* original 65c3, guest PC 0x0c0ac74e */
if(!s->budget--) { s->failed_pc=0x0c0ac74eu; return 0; }
r[5]=r[12];
goto P_0c0ac750;
P_0c0ac750: /* original 63d2, guest PC 0x0c0ac750 */
if(!s->budget--) { s->failed_pc=0x0c0ac750u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac752;
P_0c0ac752: /* original 757a, guest PC 0x0c0ac752 */
if(!s->budget--) { s->failed_pc=0x0c0ac752u; return 0; }
r[5]+=0x0000007au;
goto P_0c0ac754;
P_0c0ac754: /* original 23bb, guest PC 0x0c0ac754 */
if(!s->budget--) { s->failed_pc=0x0c0ac754u; return 0; }
r[3]|=r[11];
goto P_0c0ac756;
P_0c0ac756: /* original 2d32, guest PC 0x0c0ac756 */
if(!s->budget--) { s->failed_pc=0x0c0ac756u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac758;
P_0c0ac758: /* original 6551, guest PC 0x0c0ac758 */
if(!s->budget--) { s->failed_pc=0x0c0ac758u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac75a;
P_0c0ac75a: /* original a02c, guest PC 0x0c0ac75a */
if(!s->budget--) { s->failed_pc=0x0c0ac75au; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac7b6;
P_0c0ac75c: /* original 655d, guest PC 0x0c0ac75c */
if(!s->budget--) { s->failed_pc=0x0c0ac75cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac75e;
P_0c0ac75e: /* original 62d2, guest PC 0x0c0ac75e */
if(!s->budget--) { s->failed_pc=0x0c0ac75eu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac760;
P_0c0ac760: /* original 9315, guest PC 0x0c0ac760 */
if(!s->budget--) { s->failed_pc=0x0c0ac760u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac78eu,2);
goto P_0c0ac762;
P_0c0ac762: /* original 2239, guest PC 0x0c0ac762 */
if(!s->budget--) { s->failed_pc=0x0c0ac762u; return 0; }
r[2]&=r[3];
goto P_0c0ac764;
P_0c0ac764: /* original 2d22, guest PC 0x0c0ac764 */
if(!s->budget--) { s->failed_pc=0x0c0ac764u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ac766;
P_0c0ac766: /* original d10a, guest PC 0x0c0ac766 */
if(!s->budget--) { s->failed_pc=0x0c0ac766u; return 0; }
r[1]=read(ram,0x0c0ac790u,4);
goto P_0c0ac768;
P_0c0ac768: /* original 2188, guest PC 0x0c0ac768 */
if(!s->budget--) { s->failed_pc=0x0c0ac768u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[8])==0)!=0);
goto P_0c0ac76a;
P_0c0ac76a: /* original 8b13, guest PC 0x0c0ac76a */
if(!s->budget--) { s->failed_pc=0x0c0ac76au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac794; }
goto P_0c0ac76c;
P_0c0ac76c: /* original 65c3, guest PC 0x0c0ac76c */
if(!s->budget--) { s->failed_pc=0x0c0ac76cu; return 0; }
r[5]=r[12];
goto P_0c0ac76e;
P_0c0ac76e: /* original 7556, guest PC 0x0c0ac76e */
if(!s->budget--) { s->failed_pc=0x0c0ac76eu; return 0; }
r[5]+=0x00000056u;
goto P_0c0ac770;
P_0c0ac770: /* original 6551, guest PC 0x0c0ac770 */
if(!s->budget--) { s->failed_pc=0x0c0ac770u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac772;
P_0c0ac772: /* original 2a98, guest PC 0x0c0ac772 */
if(!s->budget--) { s->failed_pc=0x0c0ac772u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac774;
P_0c0ac774: /* original 8d1f, guest PC 0x0c0ac774 */
if(!s->budget--) { s->failed_pc=0x0c0ac774u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0ac7b6; }
goto P_0c0ac778;
P_0c0ac776: /* original 655d, guest PC 0x0c0ac776 */
if(!s->budget--) { s->failed_pc=0x0c0ac776u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac778;
P_0c0ac778: /* original 65c3, guest PC 0x0c0ac778 */
if(!s->budget--) { s->failed_pc=0x0c0ac778u; return 0; }
r[5]=r[12];
goto P_0c0ac77a;
P_0c0ac77a: /* original 63d2, guest PC 0x0c0ac77a */
if(!s->budget--) { s->failed_pc=0x0c0ac77au; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac77c;
P_0c0ac77c: /* original 7558, guest PC 0x0c0ac77c */
if(!s->budget--) { s->failed_pc=0x0c0ac77cu; return 0; }
r[5]+=0x00000058u;
goto P_0c0ac77e;
P_0c0ac77e: /* original 23bb, guest PC 0x0c0ac77e */
if(!s->budget--) { s->failed_pc=0x0c0ac77eu; return 0; }
r[3]|=r[11];
goto P_0c0ac780;
P_0c0ac780: /* original 2d32, guest PC 0x0c0ac780 */
if(!s->budget--) { s->failed_pc=0x0c0ac780u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac782;
P_0c0ac782: /* original 6551, guest PC 0x0c0ac782 */
if(!s->budget--) { s->failed_pc=0x0c0ac782u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac784;
P_0c0ac784: /* original a017, guest PC 0x0c0ac784 */
if(!s->budget--) { s->failed_pc=0x0c0ac784u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac7b6;
P_0c0ac786: /* original 655d, guest PC 0x0c0ac786 */
if(!s->budget--) { s->failed_pc=0x0c0ac786u; return 0; }
r[5]=r[5]&65535u;
if(!vf3_matrix_family(0x0c0ac788u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac788u; return 0; } return 1;
P_0c0ac794: /* original 65c3, guest PC 0x0c0ac794 */
if(!s->budget--) { s->failed_pc=0x0c0ac794u; return 0; }
r[5]=r[12];
goto P_0c0ac796;
P_0c0ac796: /* original 62d2, guest PC 0x0c0ac796 */
if(!s->budget--) { s->failed_pc=0x0c0ac796u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ac798;
P_0c0ac798: /* original 9355, guest PC 0x0c0ac798 */
if(!s->budget--) { s->failed_pc=0x0c0ac798u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac846u,2);
goto P_0c0ac79a;
P_0c0ac79a: /* original 755a, guest PC 0x0c0ac79a */
if(!s->budget--) { s->failed_pc=0x0c0ac79au; return 0; }
r[5]+=0x0000005au;
goto P_0c0ac79c;
P_0c0ac79c: /* original 2a98, guest PC 0x0c0ac79c */
if(!s->budget--) { s->failed_pc=0x0c0ac79cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[9])==0)!=0);
goto P_0c0ac79e;
P_0c0ac79e: /* original 223b, guest PC 0x0c0ac79e */
if(!s->budget--) { s->failed_pc=0x0c0ac79eu; return 0; }
r[2]|=r[3];
goto P_0c0ac7a0;
P_0c0ac7a0: /* original 2d22, guest PC 0x0c0ac7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac7a0u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ac7a2;
P_0c0ac7a2: /* original 6551, guest PC 0x0c0ac7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac7a2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac7a4;
P_0c0ac7a4: /* original 8d07, guest PC 0x0c0ac7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac7a4u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0ac7b6; }
goto P_0c0ac7a8;
P_0c0ac7a6: /* original 655d, guest PC 0x0c0ac7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac7a6u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac7a8;
P_0c0ac7a8: /* original 65c3, guest PC 0x0c0ac7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac7a8u; return 0; }
r[5]=r[12];
goto P_0c0ac7aa;
P_0c0ac7aa: /* original 63d2, guest PC 0x0c0ac7aa */
if(!s->budget--) { s->failed_pc=0x0c0ac7aau; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac7ac;
P_0c0ac7ac: /* original 755c, guest PC 0x0c0ac7ac */
if(!s->budget--) { s->failed_pc=0x0c0ac7acu; return 0; }
r[5]+=0x0000005cu;
goto P_0c0ac7ae;
P_0c0ac7ae: /* original 23bb, guest PC 0x0c0ac7ae */
if(!s->budget--) { s->failed_pc=0x0c0ac7aeu; return 0; }
r[3]|=r[11];
goto P_0c0ac7b0;
P_0c0ac7b0: /* original 2d32, guest PC 0x0c0ac7b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac7b0u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c0ac7b2;
P_0c0ac7b2: /* original 6551, guest PC 0x0c0ac7b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac7b2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac7b4;
P_0c0ac7b4: /* original 655d, guest PC 0x0c0ac7b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac7b4u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac7b6;
P_0c0ac7b6: /* original 63d2, guest PC 0x0c0ac7b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac7b6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ac7b8;
P_0c0ac7b8: /* original 1e3e, guest PC 0x0c0ac7b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac7b8u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0ac7ba;
P_0c0ac7ba: /* original b4dd, guest PC 0x0c0ac7ba */
if(!s->budget--) { s->failed_pc=0x0c0ac7bau; return 0; }
target=code_base|0x0c0ad178u; r[16]=code_base|0x0c0ac7beu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac7beu) { target=s->pc; goto dispatch; }
goto P_0c0ac7be;
P_0c0ac7bc: /* original 64e3, guest PC 0x0c0ac7bc */
if(!s->budget--) { s->failed_pc=0x0c0ac7bcu; return 0; }
r[4]=r[14];
goto P_0c0ac7be;
P_0c0ac7be: /* original 53d1, guest PC 0x0c0ac7be */
if(!s->budget--) { s->failed_pc=0x0c0ac7beu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ac7c0;
P_0c0ac7c0: /* original e062, guest PC 0x0c0ac7c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac7c0u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac7c2;
P_0c0ac7c2: /* original 7301, guest PC 0x0c0ac7c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac7c2u; return 0; }
r[3]+=0x00000001u;
goto P_0c0ac7c4;
P_0c0ac7c4: /* original 6233, guest PC 0x0c0ac7c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac7c4u; return 0; }
r[2]=r[3];
goto P_0c0ac7c6;
P_0c0ac7c6: /* original 1d31, guest PC 0x0c0ac7c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac7c6u; return 0; }
write(ram,r[13]+4,r[3],4);
goto P_0c0ac7c8;
P_0c0ac7c8: /* original 0e24, guest PC 0x0c0ac7c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac7c8u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ac7ca;
P_0c0ac7ca: /* original e04c, guest PC 0x0c0ac7ca */
if(!s->budget--) { s->failed_pc=0x0c0ac7cau; return 0; }
r[0]=0x0000004cu;
goto P_0c0ac7cc;
P_0c0ac7cc: /* original 00ee, guest PC 0x0c0ac7cc */
if(!s->budget--) { s->failed_pc=0x0c0ac7ccu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0ac7ce;
P_0c0ac7ce: /* original c808, guest PC 0x0c0ac7ce */
if(!s->budget--) { s->failed_pc=0x0c0ac7ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0ac7d0;
P_0c0ac7d0: /* original 8b01, guest PC 0x0c0ac7d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac7d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac7d6; }
goto P_0c0ac7d2;
P_0c0ac7d2: /* original a087, guest PC 0x0c0ac7d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac7d2u; return 0; }
goto P_0c0ac8e4;
P_0c0ac7d4: /* original 0009, guest PC 0x0c0ac7d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac7d4u; return 0; }
goto P_0c0ac7d6;
P_0c0ac7d6: /* original 52d1, guest PC 0x0c0ac7d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac7d6u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ac7d8;
P_0c0ac7d8: /* original e062, guest PC 0x0c0ac7d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac7d8u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac7da;
P_0c0ac7da: /* original 7201, guest PC 0x0c0ac7da */
if(!s->budget--) { s->failed_pc=0x0c0ac7dau; return 0; }
r[2]+=0x00000001u;
goto P_0c0ac7dc;
P_0c0ac7dc: /* original 6323, guest PC 0x0c0ac7dc */
if(!s->budget--) { s->failed_pc=0x0c0ac7dcu; return 0; }
r[3]=r[2];
goto P_0c0ac7de;
P_0c0ac7de: /* original 1d21, guest PC 0x0c0ac7de */
if(!s->budget--) { s->failed_pc=0x0c0ac7deu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ac7e0;
P_0c0ac7e0: /* original 0e34, guest PC 0x0c0ac7e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac7e0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ac7e2;
P_0c0ac7e2: /* original d21a, guest PC 0x0c0ac7e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac7e2u; return 0; }
r[2]=read(ram,0x0c0ac84cu,4);
goto P_0c0ac7e4;
P_0c0ac7e4: /* original 2288, guest PC 0x0c0ac7e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac7e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c0ac7e6;
P_0c0ac7e6: /* original 8b3f, guest PC 0x0c0ac7e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac7e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac868; }
goto P_0c0ac7e8;
P_0c0ac7e8: /* original 902e, guest PC 0x0c0ac7e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac7e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac848u,2);
goto P_0c0ac7ea;
P_0c0ac7ea: /* original e40f, guest PC 0x0c0ac7ea */
if(!s->budget--) { s->failed_pc=0x0c0ac7eau; return 0; }
r[4]=0x0000000fu;
goto P_0c0ac7ec;
P_0c0ac7ec: /* original 00ec, guest PC 0x0c0ac7ec */
if(!s->budget--) { s->failed_pc=0x0c0ac7ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ac7ee;
P_0c0ac7ee: /* original 600c, guest PC 0x0c0ac7ee */
if(!s->budget--) { s->failed_pc=0x0c0ac7eeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ac7f0;
P_0c0ac7f0: /* original 2409, guest PC 0x0c0ac7f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac7f0u; return 0; }
r[4]&=r[0];
goto P_0c0ac7f2;
P_0c0ac7f2: /* original 6043, guest PC 0x0c0ac7f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac7f2u; return 0; }
r[0]=r[4];
goto P_0c0ac7f4;
P_0c0ac7f4: /* original 8804, guest PC 0x0c0ac7f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac7f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0ac7f6;
P_0c0ac7f6: /* original 8937, guest PC 0x0c0ac7f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac7f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac868; }
goto P_0c0ac7f8;
P_0c0ac7f8: /* original 50ee, guest PC 0x0c0ac7f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac7f8u; return 0; }
r[0]=read(ram,r[14]+56,4);
goto P_0c0ac7fa;
P_0c0ac7fa: /* original c808, guest PC 0x0c0ac7fa */
if(!s->budget--) { s->failed_pc=0x0c0ac7fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0ac7fc;
P_0c0ac7fc: /* original 8b34, guest PC 0x0c0ac7fc */
if(!s->budget--) { s->failed_pc=0x0c0ac7fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac868; }
goto P_0c0ac7fe;
P_0c0ac7fe: /* original 50ee, guest PC 0x0c0ac7fe */
if(!s->budget--) { s->failed_pc=0x0c0ac7feu; return 0; }
r[0]=read(ram,r[14]+56,4);
goto P_0c0ac800;
P_0c0ac800: /* original c802, guest PC 0x0c0ac800 */
if(!s->budget--) { s->failed_pc=0x0c0ac800u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0ac802;
P_0c0ac802: /* original 8f04, guest PC 0x0c0ac802 */
if(!s->budget--) { s->failed_pc=0x0c0ac802u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c0ac80e; }
goto P_0c0ac806;
P_0c0ac804: /* original e400, guest PC 0x0c0ac804 */
if(!s->budget--) { s->failed_pc=0x0c0ac804u; return 0; }
r[4]=0x00000000u;
goto P_0c0ac806;
P_0c0ac806: /* original 50ee, guest PC 0x0c0ac806 */
if(!s->budget--) { s->failed_pc=0x0c0ac806u; return 0; }
r[0]=read(ram,r[14]+56,4);
goto P_0c0ac808;
P_0c0ac808: /* original c804, guest PC 0x0c0ac808 */
if(!s->budget--) { s->failed_pc=0x0c0ac808u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0ac80a;
P_0c0ac80a: /* original 896b, guest PC 0x0c0ac80a */
if(!s->budget--) { s->failed_pc=0x0c0ac80au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac8e4; }
goto P_0c0ac80c;
P_0c0ac80c: /* original e428, guest PC 0x0c0ac80c */
if(!s->budget--) { s->failed_pc=0x0c0ac80cu; return 0; }
r[4]=0x00000028u;
goto P_0c0ac80e;
P_0c0ac80e: /* original 52ee, guest PC 0x0c0ac80e */
if(!s->budget--) { s->failed_pc=0x0c0ac80eu; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c0ac810;
P_0c0ac810: /* original 9319, guest PC 0x0c0ac810 */
if(!s->budget--) { s->failed_pc=0x0c0ac810u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac846u,2);
goto P_0c0ac812;
P_0c0ac812: /* original 2238, guest PC 0x0c0ac812 */
if(!s->budget--) { s->failed_pc=0x0c0ac812u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac814;
P_0c0ac814: /* original 8d01, guest PC 0x0c0ac814 */
if(!s->budget--) { s->failed_pc=0x0c0ac814u; return 0; }
cond=r[17]&1u;
r[3]=read(ram,r[14]+56,4);
if(cond) { goto P_0c0ac81a; }
goto P_0c0ac818;
P_0c0ac816: /* original 53ee, guest PC 0x0c0ac816 */
if(!s->budget--) { s->failed_pc=0x0c0ac816u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c0ac818;
P_0c0ac818: /* original 7404, guest PC 0x0c0ac818 */
if(!s->budget--) { s->failed_pc=0x0c0ac818u; return 0; }
r[4]+=0x00000004u;
goto P_0c0ac81a;
P_0c0ac81a: /* original 23b8, guest PC 0x0c0ac81a */
if(!s->budget--) { s->failed_pc=0x0c0ac81au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0ac81c;
P_0c0ac81c: /* original 8d01, guest PC 0x0c0ac81c */
if(!s->budget--) { s->failed_pc=0x0c0ac81cu; return 0; }
cond=r[17]&1u;
r[0]=read(ram,r[14]+56,4);
if(cond) { goto P_0c0ac822; }
goto P_0c0ac820;
P_0c0ac81e: /* original 50ee, guest PC 0x0c0ac81e */
if(!s->budget--) { s->failed_pc=0x0c0ac81eu; return 0; }
r[0]=read(ram,r[14]+56,4);
goto P_0c0ac820;
P_0c0ac820: /* original 7402, guest PC 0x0c0ac820 */
if(!s->budget--) { s->failed_pc=0x0c0ac820u; return 0; }
r[4]+=0x00000002u;
goto P_0c0ac822;
P_0c0ac822: /* original c840, guest PC 0x0c0ac822 */
if(!s->budget--) { s->failed_pc=0x0c0ac822u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0ac824;
P_0c0ac824: /* original 890a, guest PC 0x0c0ac824 */
if(!s->budget--) { s->failed_pc=0x0c0ac824u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac83c; }
goto P_0c0ac826;
P_0c0ac826: /* original 50ee, guest PC 0x0c0ac826 */
if(!s->budget--) { s->failed_pc=0x0c0ac826u; return 0; }
r[0]=read(ram,r[14]+56,4);
goto P_0c0ac828;
P_0c0ac828: /* original c880, guest PC 0x0c0ac828 */
if(!s->budget--) { s->failed_pc=0x0c0ac828u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0ac82a;
P_0c0ac82a: /* original 8901, guest PC 0x0c0ac82a */
if(!s->budget--) { s->failed_pc=0x0c0ac82au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac830; }
goto P_0c0ac82c;
P_0c0ac82c: /* original a013, guest PC 0x0c0ac82c */
if(!s->budget--) { s->failed_pc=0x0c0ac82cu; return 0; }
r[4]+=0x00000008u;
goto P_0c0ac856;
P_0c0ac82e: /* original 7408, guest PC 0x0c0ac82e */
if(!s->budget--) { s->failed_pc=0x0c0ac82eu; return 0; }
r[4]+=0x00000008u;
goto P_0c0ac830;
P_0c0ac830: /* original 52ee, guest PC 0x0c0ac830 */
if(!s->budget--) { s->failed_pc=0x0c0ac830u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c0ac832;
P_0c0ac832: /* original 930a, guest PC 0x0c0ac832 */
if(!s->budget--) { s->failed_pc=0x0c0ac832u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac84au,2);
goto P_0c0ac834;
P_0c0ac834: /* original 2238, guest PC 0x0c0ac834 */
if(!s->budget--) { s->failed_pc=0x0c0ac834u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac836;
P_0c0ac836: /* original 8901, guest PC 0x0c0ac836 */
if(!s->budget--) { s->failed_pc=0x0c0ac836u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac83c; }
goto P_0c0ac838;
P_0c0ac838: /* original a00d, guest PC 0x0c0ac838 */
if(!s->budget--) { s->failed_pc=0x0c0ac838u; return 0; }
r[4]+=0x00000010u;
goto P_0c0ac856;
P_0c0ac83a: /* original 7410, guest PC 0x0c0ac83a */
if(!s->budget--) { s->failed_pc=0x0c0ac83au; return 0; }
r[4]+=0x00000010u;
goto P_0c0ac83c;
P_0c0ac83c: /* original 50ee, guest PC 0x0c0ac83c */
if(!s->budget--) { s->failed_pc=0x0c0ac83cu; return 0; }
r[0]=read(ram,r[14]+56,4);
goto P_0c0ac83e;
P_0c0ac83e: /* original c810, guest PC 0x0c0ac83e */
if(!s->budget--) { s->failed_pc=0x0c0ac83eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0ac840;
P_0c0ac840: /* original 8906, guest PC 0x0c0ac840 */
if(!s->budget--) { s->failed_pc=0x0c0ac840u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac850; }
goto P_0c0ac842;
P_0c0ac842: /* original a008, guest PC 0x0c0ac842 */
if(!s->budget--) { s->failed_pc=0x0c0ac842u; return 0; }
r[4]+=0x00000018u;
goto P_0c0ac856;
P_0c0ac844: /* original 7418, guest PC 0x0c0ac844 */
if(!s->budget--) { s->failed_pc=0x0c0ac844u; return 0; }
r[4]+=0x00000018u;
if(!vf3_matrix_family(0x0c0ac846u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac846u; return 0; } return 1;
P_0c0ac850: /* original c820, guest PC 0x0c0ac850 */
if(!s->budget--) { s->failed_pc=0x0c0ac850u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0ac852;
P_0c0ac852: /* original 8900, guest PC 0x0c0ac852 */
if(!s->budget--) { s->failed_pc=0x0c0ac852u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac856; }
goto P_0c0ac854;
P_0c0ac854: /* original 7420, guest PC 0x0c0ac854 */
if(!s->budget--) { s->failed_pc=0x0c0ac854u; return 0; }
r[4]+=0x00000020u;
goto P_0c0ac856;
P_0c0ac856: /* original d33d, guest PC 0x0c0ac856 */
if(!s->budget--) { s->failed_pc=0x0c0ac856u; return 0; }
r[3]=read(ram,0x0c0ac94cu,4);
goto P_0c0ac858;
P_0c0ac858: /* original 65c3, guest PC 0x0c0ac858 */
if(!s->budget--) { s->failed_pc=0x0c0ac858u; return 0; }
r[5]=r[12];
goto P_0c0ac85a;
P_0c0ac85a: /* original 343c, guest PC 0x0c0ac85a */
if(!s->budget--) { s->failed_pc=0x0c0ac85au; return 0; }
r[4]+=r[3];
goto P_0c0ac85c;
P_0c0ac85c: /* original 6441, guest PC 0x0c0ac85c */
if(!s->budget--) { s->failed_pc=0x0c0ac85cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c0ac85e;
P_0c0ac85e: /* original 354c, guest PC 0x0c0ac85e */
if(!s->budget--) { s->failed_pc=0x0c0ac85eu; return 0; }
r[5]+=r[4];
goto P_0c0ac860;
P_0c0ac860: /* original 6551, guest PC 0x0c0ac860 */
if(!s->budget--) { s->failed_pc=0x0c0ac860u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac862;
P_0c0ac862: /* original 655d, guest PC 0x0c0ac862 */
if(!s->budget--) { s->failed_pc=0x0c0ac862u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac864;
P_0c0ac864: /* original b488, guest PC 0x0c0ac864 */
if(!s->budget--) { s->failed_pc=0x0c0ac864u; return 0; }
target=code_base|0x0c0ad178u; r[16]=code_base|0x0c0ac868u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac868u) { target=s->pc; goto dispatch; }
goto P_0c0ac868;
P_0c0ac866: /* original 64e3, guest PC 0x0c0ac866 */
if(!s->budget--) { s->failed_pc=0x0c0ac866u; return 0; }
r[4]=r[14];
goto P_0c0ac868;
P_0c0ac868: /* original 53d1, guest PC 0x0c0ac868 */
if(!s->budget--) { s->failed_pc=0x0c0ac868u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ac86a;
P_0c0ac86a: /* original e062, guest PC 0x0c0ac86a */
if(!s->budget--) { s->failed_pc=0x0c0ac86au; return 0; }
r[0]=0x00000062u;
goto P_0c0ac86c;
P_0c0ac86c: /* original 7301, guest PC 0x0c0ac86c */
if(!s->budget--) { s->failed_pc=0x0c0ac86cu; return 0; }
r[3]+=0x00000001u;
goto P_0c0ac86e;
P_0c0ac86e: /* original 6233, guest PC 0x0c0ac86e */
if(!s->budget--) { s->failed_pc=0x0c0ac86eu; return 0; }
r[2]=r[3];
goto P_0c0ac870;
P_0c0ac870: /* original 1d31, guest PC 0x0c0ac870 */
if(!s->budget--) { s->failed_pc=0x0c0ac870u; return 0; }
write(ram,r[13]+4,r[3],4);
goto P_0c0ac872;
P_0c0ac872: /* original 0e24, guest PC 0x0c0ac872 */
if(!s->budget--) { s->failed_pc=0x0c0ac872u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ac874;
P_0c0ac874: /* original e04c, guest PC 0x0c0ac874 */
if(!s->budget--) { s->failed_pc=0x0c0ac874u; return 0; }
r[0]=0x0000004cu;
goto P_0c0ac876;
P_0c0ac876: /* original 00ee, guest PC 0x0c0ac876 */
if(!s->budget--) { s->failed_pc=0x0c0ac876u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0ac878;
P_0c0ac878: /* original c808, guest PC 0x0c0ac878 */
if(!s->budget--) { s->failed_pc=0x0c0ac878u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0ac87a;
P_0c0ac87a: /* original 8917, guest PC 0x0c0ac87a */
if(!s->budget--) { s->failed_pc=0x0c0ac87au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac8ac; }
goto P_0c0ac87c;
P_0c0ac87c: /* original e048, guest PC 0x0c0ac87c */
if(!s->budget--) { s->failed_pc=0x0c0ac87cu; return 0; }
r[0]=0x00000048u;
goto P_0c0ac87e;
P_0c0ac87e: /* original 04ee, guest PC 0x0c0ac87e */
if(!s->budget--) { s->failed_pc=0x0c0ac87eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ac880;
P_0c0ac880: /* original e50f, guest PC 0x0c0ac880 */
if(!s->budget--) { s->failed_pc=0x0c0ac880u; return 0; }
r[5]=0x0000000fu;
goto P_0c0ac882;
P_0c0ac882: /* original 9062, guest PC 0x0c0ac882 */
if(!s->budget--) { s->failed_pc=0x0c0ac882u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac94au,2);
goto P_0c0ac884;
P_0c0ac884: /* original 00ec, guest PC 0x0c0ac884 */
if(!s->budget--) { s->failed_pc=0x0c0ac884u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ac886;
P_0c0ac886: /* original 600c, guest PC 0x0c0ac886 */
if(!s->budget--) { s->failed_pc=0x0c0ac886u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ac888;
P_0c0ac888: /* original 2509, guest PC 0x0c0ac888 */
if(!s->budget--) { s->failed_pc=0x0c0ac888u; return 0; }
r[5]&=r[0];
goto P_0c0ac88a;
P_0c0ac88a: /* original 6053, guest PC 0x0c0ac88a */
if(!s->budget--) { s->failed_pc=0x0c0ac88au; return 0; }
r[0]=r[5];
goto P_0c0ac88c;
P_0c0ac88c: /* original 8804, guest PC 0x0c0ac88c */
if(!s->budget--) { s->failed_pc=0x0c0ac88cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0ac88e;
P_0c0ac88e: /* original 8b01, guest PC 0x0c0ac88e */
if(!s->budget--) { s->failed_pc=0x0c0ac88eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac894; }
goto P_0c0ac890;
P_0c0ac890: /* original d32f, guest PC 0x0c0ac890 */
if(!s->budget--) { s->failed_pc=0x0c0ac890u; return 0; }
r[3]=read(ram,0x0c0ac950u,4);
goto P_0c0ac892;
P_0c0ac892: /* original 243b, guest PC 0x0c0ac892 */
if(!s->budget--) { s->failed_pc=0x0c0ac892u; return 0; }
r[4]|=r[3];
goto P_0c0ac894;
P_0c0ac894: /* original 9059, guest PC 0x0c0ac894 */
if(!s->budget--) { s->failed_pc=0x0c0ac894u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac94au,2);
goto P_0c0ac896;
P_0c0ac896: /* original 00ec, guest PC 0x0c0ac896 */
if(!s->budget--) { s->failed_pc=0x0c0ac896u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ac898;
P_0c0ac898: /* original 600c, guest PC 0x0c0ac898 */
if(!s->budget--) { s->failed_pc=0x0c0ac898u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ac89a;
P_0c0ac89a: /* original c810, guest PC 0x0c0ac89a */
if(!s->budget--) { s->failed_pc=0x0c0ac89au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0ac89c;
P_0c0ac89c: /* original 8d03, guest PC 0x0c0ac89c */
if(!s->budget--) { s->failed_pc=0x0c0ac89cu; return 0; }
cond=r[17]&1u;
r[0]=0x00000048u;
if(cond) { goto P_0c0ac8a6; }
goto P_0c0ac8a0;
P_0c0ac89e: /* original e048, guest PC 0x0c0ac89e */
if(!s->budget--) { s->failed_pc=0x0c0ac89eu; return 0; }
r[0]=0x00000048u;
goto P_0c0ac8a0;
P_0c0ac8a0: /* original d22c, guest PC 0x0c0ac8a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac8a0u; return 0; }
r[2]=read(ram,0x0c0ac954u,4);
goto P_0c0ac8a2;
P_0c0ac8a2: /* original a002, guest PC 0x0c0ac8a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac8a2u; return 0; }
r[4]|=r[2];
goto P_0c0ac8aa;
P_0c0ac8a4: /* original 242b, guest PC 0x0c0ac8a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac8a4u; return 0; }
r[4]|=r[2];
goto P_0c0ac8a6;
P_0c0ac8a6: /* original d12c, guest PC 0x0c0ac8a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac8a6u; return 0; }
r[1]=read(ram,0x0c0ac958u,4);
goto P_0c0ac8a8;
P_0c0ac8a8: /* original 2419, guest PC 0x0c0ac8a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac8a8u; return 0; }
r[4]&=r[1];
goto P_0c0ac8aa;
P_0c0ac8aa: /* original 0e46, guest PC 0x0c0ac8aa */
if(!s->budget--) { s->failed_pc=0x0c0ac8aau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0ac8ac;
P_0c0ac8ac: /* original d32b, guest PC 0x0c0ac8ac */
if(!s->budget--) { s->failed_pc=0x0c0ac8acu; return 0; }
r[3]=read(ram,0x0c0ac95cu,4);
goto P_0c0ac8ae;
P_0c0ac8ae: /* original 2838, guest PC 0x0c0ac8ae */
if(!s->budget--) { s->failed_pc=0x0c0ac8aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c0ac8b0;
P_0c0ac8b0: /* original 8918, guest PC 0x0c0ac8b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac8b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac8e4; }
goto P_0c0ac8b2;
P_0c0ac8b2: /* original e100, guest PC 0x0c0ac8b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac8b2u; return 0; }
r[1]=0x00000000u;
goto P_0c0ac8b4;
P_0c0ac8b4: /* original 1e1e, guest PC 0x0c0ac8b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac8b4u; return 0; }
write(ram,r[14]+56,r[1],4);
goto P_0c0ac8b6;
P_0c0ac8b6: /* original a015, guest PC 0x0c0ac8b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac8b6u; return 0; }
goto P_0c0ac8e4;
P_0c0ac8b8: /* original 0009, guest PC 0x0c0ac8b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac8b8u; return 0; }
goto P_0c0ac8ba;
P_0c0ac8ba: /* original 2558, guest PC 0x0c0ac8ba */
if(!s->budget--) { s->failed_pc=0x0c0ac8bau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ac8bc;
P_0c0ac8bc: /* original 8912, guest PC 0x0c0ac8bc */
if(!s->budget--) { s->failed_pc=0x0c0ac8bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac8e4; }
goto P_0c0ac8be;
P_0c0ac8be: /* original b45b, guest PC 0x0c0ac8be */
if(!s->budget--) { s->failed_pc=0x0c0ac8beu; return 0; }
target=code_base|0x0c0ad178u; r[16]=code_base|0x0c0ac8c2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac8c2u) { target=s->pc; goto dispatch; }
goto P_0c0ac8c2;
P_0c0ac8c0: /* original 64e3, guest PC 0x0c0ac8c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac8c0u; return 0; }
r[4]=r[14];
goto P_0c0ac8c2;
P_0c0ac8c2: /* original a00f, guest PC 0x0c0ac8c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac8c2u; return 0; }
goto P_0c0ac8e4;
P_0c0ac8c4: /* original 0009, guest PC 0x0c0ac8c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac8c4u; return 0; }
goto P_0c0ac8c6;
P_0c0ac8c6: /* original d326, guest PC 0x0c0ac8c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac8c6u; return 0; }
r[3]=read(ram,0x0c0ac960u,4);
goto P_0c0ac8c8;
P_0c0ac8c8: /* original 2838, guest PC 0x0c0ac8c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac8c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c0ac8ca;
P_0c0ac8ca: /* original 8902, guest PC 0x0c0ac8ca */
if(!s->budget--) { s->failed_pc=0x0c0ac8cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac8d2; }
goto P_0c0ac8cc;
P_0c0ac8cc: /* original 65c3, guest PC 0x0c0ac8cc */
if(!s->budget--) { s->failed_pc=0x0c0ac8ccu; return 0; }
r[5]=r[12];
goto P_0c0ac8ce;
P_0c0ac8ce: /* original a002, guest PC 0x0c0ac8ce */
if(!s->budget--) { s->failed_pc=0x0c0ac8ceu; return 0; }
r[5]+=0x00000054u;
goto P_0c0ac8d6;
P_0c0ac8d0: /* original 7554, guest PC 0x0c0ac8d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac8d0u; return 0; }
r[5]+=0x00000054u;
goto P_0c0ac8d2;
P_0c0ac8d2: /* original 65c3, guest PC 0x0c0ac8d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac8d2u; return 0; }
r[5]=r[12];
goto P_0c0ac8d4;
P_0c0ac8d4: /* original 7552, guest PC 0x0c0ac8d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac8d4u; return 0; }
r[5]+=0x00000052u;
goto P_0c0ac8d6;
P_0c0ac8d6: /* original 6551, guest PC 0x0c0ac8d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac8d6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0ac8d8;
P_0c0ac8d8: /* original 655d, guest PC 0x0c0ac8d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac8d8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac8da;
P_0c0ac8da: /* original b44d, guest PC 0x0c0ac8da */
if(!s->budget--) { s->failed_pc=0x0c0ac8dau; return 0; }
target=code_base|0x0c0ad178u; r[16]=code_base|0x0c0ac8deu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac8deu) { target=s->pc; goto dispatch; }
goto P_0c0ac8de;
P_0c0ac8dc: /* original 64e3, guest PC 0x0c0ac8dc */
if(!s->budget--) { s->failed_pc=0x0c0ac8dcu; return 0; }
r[4]=r[14];
goto P_0c0ac8de;
P_0c0ac8de: /* original e062, guest PC 0x0c0ac8de */
if(!s->budget--) { s->failed_pc=0x0c0ac8deu; return 0; }
r[0]=0x00000062u;
goto P_0c0ac8e0;
P_0c0ac8e0: /* original e207, guest PC 0x0c0ac8e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac8e0u; return 0; }
r[2]=0x00000007u;
goto P_0c0ac8e2;
P_0c0ac8e2: /* original 0e24, guest PC 0x0c0ac8e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac8e2u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ac8e4;
P_0c0ac8e4: /* original 7f14, guest PC 0x0c0ac8e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac8e4u; return 0; }
r[15]+=0x00000014u;
goto P_0c0ac8e6;
P_0c0ac8e6: /* original 4f26, guest PC 0x0c0ac8e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac8e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac8e8;
P_0c0ac8e8: /* original fcf9, guest PC 0x0c0ac8e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac8e8u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac8ea;
P_0c0ac8ea: /* original fdf9, guest PC 0x0c0ac8ea */
if(!s->budget--) { s->failed_pc=0x0c0ac8eau; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac8ec;
P_0c0ac8ec: /* original fef9, guest PC 0x0c0ac8ec */
if(!s->budget--) { s->failed_pc=0x0c0ac8ecu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac8ee;
P_0c0ac8ee: /* original fff9, guest PC 0x0c0ac8ee */
if(!s->budget--) { s->failed_pc=0x0c0ac8eeu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac8f0;
P_0c0ac8f0: /* original 68f6, guest PC 0x0c0ac8f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac8f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0ac8f2;
P_0c0ac8f2: /* original 69f6, guest PC 0x0c0ac8f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac8f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ac8f4;
P_0c0ac8f4: /* original 6af6, guest PC 0x0c0ac8f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac8f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ac8f6;
P_0c0ac8f6: /* original 6bf6, guest PC 0x0c0ac8f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac8f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ac8f8;
P_0c0ac8f8: /* original 6cf6, guest PC 0x0c0ac8f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac8f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ac8fa;
P_0c0ac8fa: /* original 6df6, guest PC 0x0c0ac8fa */
if(!s->budget--) { s->failed_pc=0x0c0ac8fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ac8fc;
P_0c0ac8fc: /* original 000b, guest PC 0x0c0ac8fc */
if(!s->budget--) { s->failed_pc=0x0c0ac8fcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac8fe: /* original 6ef6, guest PC 0x0c0ac8fe */
if(!s->budget--) { s->failed_pc=0x0c0ac8feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ac900u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac900u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
