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
int vf3_away_batch184_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09af6cu: goto P_0c09af6c;
case 0x0c09af6eu: goto P_0c09af6e;
case 0x0c09af70u: goto P_0c09af70;
case 0x0c09af72u: goto P_0c09af72;
case 0x0c09af74u: goto P_0c09af74;
case 0x0c09af76u: goto P_0c09af76;
case 0x0c09af78u: goto P_0c09af78;
case 0x0c09af7au: goto P_0c09af7a;
case 0x0c09af7cu: goto P_0c09af7c;
case 0x0c09af7eu: goto P_0c09af7e;
case 0x0c09af80u: goto P_0c09af80;
case 0x0c09af82u: goto P_0c09af82;
case 0x0c09af84u: goto P_0c09af84;
case 0x0c09af86u: goto P_0c09af86;
case 0x0c09af88u: goto P_0c09af88;
case 0x0c09af8au: goto P_0c09af8a;
case 0x0c09af8cu: goto P_0c09af8c;
case 0x0c09af8eu: goto P_0c09af8e;
case 0x0c09af90u: goto P_0c09af90;
case 0x0c09af92u: goto P_0c09af92;
case 0x0c09af94u: goto P_0c09af94;
case 0x0c09af96u: goto P_0c09af96;
case 0x0c09af98u: goto P_0c09af98;
case 0x0c09af9au: goto P_0c09af9a;
case 0x0c09af9cu: goto P_0c09af9c;
case 0x0c09af9eu: goto P_0c09af9e;
case 0x0c09afa0u: goto P_0c09afa0;
case 0x0c09afa2u: goto P_0c09afa2;
case 0x0c09afa4u: goto P_0c09afa4;
case 0x0c09afa6u: goto P_0c09afa6;
case 0x0c09afa8u: goto P_0c09afa8;
case 0x0c09afaau: goto P_0c09afaa;
case 0x0c09afacu: goto P_0c09afac;
case 0x0c09afaeu: goto P_0c09afae;
case 0x0c09afb0u: goto P_0c09afb0;
case 0x0c09afb2u: goto P_0c09afb2;
case 0x0c09afb4u: goto P_0c09afb4;
case 0x0c09afb6u: goto P_0c09afb6;
case 0x0c09afb8u: goto P_0c09afb8;
case 0x0c09afbau: goto P_0c09afba;
case 0x0c09afbcu: goto P_0c09afbc;
case 0x0c09afbeu: goto P_0c09afbe;
case 0x0c09cfacu: goto P_0c09cfac;
case 0x0c09cfaeu: goto P_0c09cfae;
case 0x0c09cfb0u: goto P_0c09cfb0;
case 0x0c09cfb2u: goto P_0c09cfb2;
case 0x0c09cfb4u: goto P_0c09cfb4;
case 0x0c09cfb6u: goto P_0c09cfb6;
case 0x0c09cfb8u: goto P_0c09cfb8;
case 0x0c09cfbau: goto P_0c09cfba;
case 0x0c09cfbcu: goto P_0c09cfbc;
case 0x0c09cfbeu: goto P_0c09cfbe;
case 0x0c09cfc0u: goto P_0c09cfc0;
case 0x0c09cfc2u: goto P_0c09cfc2;
case 0x0c09cfc4u: goto P_0c09cfc4;
case 0x0c09cfc6u: goto P_0c09cfc6;
case 0x0c09cfc8u: goto P_0c09cfc8;
case 0x0c09cfcau: goto P_0c09cfca;
case 0x0c09cfccu: goto P_0c09cfcc;
case 0x0c09cfceu: goto P_0c09cfce;
case 0x0c09cfd0u: goto P_0c09cfd0;
case 0x0c09cfd2u: goto P_0c09cfd2;
case 0x0c09cfd4u: goto P_0c09cfd4;
case 0x0c09cfd6u: goto P_0c09cfd6;
case 0x0c09cfd8u: goto P_0c09cfd8;
case 0x0c09cfdau: goto P_0c09cfda;
case 0x0c09cfdcu: goto P_0c09cfdc;
case 0x0c09cfdeu: goto P_0c09cfde;
case 0x0c09cfe0u: goto P_0c09cfe0;
case 0x0c09cfe2u: goto P_0c09cfe2;
case 0x0c09cfe4u: goto P_0c09cfe4;
case 0x0c09cfe6u: goto P_0c09cfe6;
case 0x0c09cfe8u: goto P_0c09cfe8;
case 0x0c09cfeau: goto P_0c09cfea;
case 0x0c09cfecu: goto P_0c09cfec;
case 0x0c09cfeeu: goto P_0c09cfee;
case 0x0c09cff0u: goto P_0c09cff0;
case 0x0c09cff2u: goto P_0c09cff2;
case 0x0c09cff4u: goto P_0c09cff4;
case 0x0c09cff6u: goto P_0c09cff6;
case 0x0c09cff8u: goto P_0c09cff8;
case 0x0c09cffau: goto P_0c09cffa;
case 0x0c09cffcu: goto P_0c09cffc;
case 0x0c09cffeu: goto P_0c09cffe;
case 0x0c09d000u: goto P_0c09d000;
case 0x0c09d002u: goto P_0c09d002;
case 0x0c09d004u: goto P_0c09d004;
case 0x0c09d006u: goto P_0c09d006;
case 0x0c09d008u: goto P_0c09d008;
case 0x0c09d00au: goto P_0c09d00a;
case 0x0c09d00cu: goto P_0c09d00c;
case 0x0c09d00eu: goto P_0c09d00e;
case 0x0c09d010u: goto P_0c09d010;
case 0x0c09d012u: goto P_0c09d012;
case 0x0c09d014u: goto P_0c09d014;
case 0x0c09d016u: goto P_0c09d016;
case 0x0c09d018u: goto P_0c09d018;
case 0x0c09d01au: goto P_0c09d01a;
case 0x0c09d01cu: goto P_0c09d01c;
case 0x0c09d01eu: goto P_0c09d01e;
case 0x0c09d020u: goto P_0c09d020;
case 0x0c09d022u: goto P_0c09d022;
case 0x0c09d024u: goto P_0c09d024;
case 0x0c09d026u: goto P_0c09d026;
case 0x0c09d028u: goto P_0c09d028;
case 0x0c09d02au: goto P_0c09d02a;
case 0x0c09d02cu: goto P_0c09d02c;
case 0x0c09d02eu: goto P_0c09d02e;
case 0x0c09d030u: goto P_0c09d030;
case 0x0c09d032u: goto P_0c09d032;
case 0x0c09d034u: goto P_0c09d034;
case 0x0c09d036u: goto P_0c09d036;
case 0x0c09d038u: goto P_0c09d038;
case 0x0c09d03au: goto P_0c09d03a;
case 0x0c09d03cu: goto P_0c09d03c;
case 0x0c09d03eu: goto P_0c09d03e;
case 0x0c09d040u: goto P_0c09d040;
case 0x0c09d042u: goto P_0c09d042;
case 0x0c09d044u: goto P_0c09d044;
case 0x0c09d046u: goto P_0c09d046;
case 0x0c09d048u: goto P_0c09d048;
case 0x0c09d04au: goto P_0c09d04a;
case 0x0c09d04cu: goto P_0c09d04c;
case 0x0c09d04eu: goto P_0c09d04e;
case 0x0c09d050u: goto P_0c09d050;
case 0x0c09d052u: goto P_0c09d052;
case 0x0c09d054u: goto P_0c09d054;
case 0x0c09d056u: goto P_0c09d056;
case 0x0c09d058u: goto P_0c09d058;
case 0x0c09d05au: goto P_0c09d05a;
case 0x0c09d05cu: goto P_0c09d05c;
case 0x0c09d05eu: goto P_0c09d05e;
case 0x0c09d060u: goto P_0c09d060;
case 0x0c09d062u: goto P_0c09d062;
case 0x0c09d064u: goto P_0c09d064;
case 0x0c09d066u: goto P_0c09d066;
case 0x0c09d068u: goto P_0c09d068;
case 0x0c09d06au: goto P_0c09d06a;
case 0x0c09d06cu: goto P_0c09d06c;
case 0x0c09d06eu: goto P_0c09d06e;
case 0x0c09d070u: goto P_0c09d070;
case 0x0c09d072u: goto P_0c09d072;
case 0x0c09d074u: goto P_0c09d074;
case 0x0c09d076u: goto P_0c09d076;
case 0x0c09d078u: goto P_0c09d078;
case 0x0c09d07au: goto P_0c09d07a;
case 0x0c09d07cu: goto P_0c09d07c;
case 0x0c09d138u: goto P_0c09d138;
case 0x0c09d13au: goto P_0c09d13a;
case 0x0c09d13cu: goto P_0c09d13c;
case 0x0c09d13eu: goto P_0c09d13e;
case 0x0c09d140u: goto P_0c09d140;
case 0x0c09d142u: goto P_0c09d142;
case 0x0c09d144u: goto P_0c09d144;
case 0x0c09d146u: goto P_0c09d146;
case 0x0c09d148u: goto P_0c09d148;
case 0x0c09d14au: goto P_0c09d14a;
case 0x0c09d14cu: goto P_0c09d14c;
case 0x0c09d14eu: goto P_0c09d14e;
case 0x0c09d150u: goto P_0c09d150;
case 0x0c09d152u: goto P_0c09d152;
case 0x0c09d154u: goto P_0c09d154;
case 0x0c09d156u: goto P_0c09d156;
case 0x0c09d158u: goto P_0c09d158;
case 0x0c09d15au: goto P_0c09d15a;
case 0x0c09d15cu: goto P_0c09d15c;
case 0x0c09d15eu: goto P_0c09d15e;
case 0x0c09d160u: goto P_0c09d160;
case 0x0c09d162u: goto P_0c09d162;
case 0x0c09d164u: goto P_0c09d164;
case 0x0c09d166u: goto P_0c09d166;
case 0x0c09d168u: goto P_0c09d168;
case 0x0c09d16au: goto P_0c09d16a;
case 0x0c09d16cu: goto P_0c09d16c;
case 0x0c09d16eu: goto P_0c09d16e;
case 0x0c09d170u: goto P_0c09d170;
case 0x0c09d172u: goto P_0c09d172;
case 0x0c09d174u: goto P_0c09d174;
case 0x0c09d176u: goto P_0c09d176;
case 0x0c09d178u: goto P_0c09d178;
case 0x0c09d17au: goto P_0c09d17a;
case 0x0c09d17cu: goto P_0c09d17c;
case 0x0c09d17eu: goto P_0c09d17e;
case 0x0c09d180u: goto P_0c09d180;
case 0x0c09d182u: goto P_0c09d182;
case 0x0c09d184u: goto P_0c09d184;
case 0x0c09d186u: goto P_0c09d186;
case 0x0c09d188u: goto P_0c09d188;
case 0x0c09d18au: goto P_0c09d18a;
case 0x0c09d18cu: goto P_0c09d18c;
case 0x0c09d18eu: goto P_0c09d18e;
case 0x0c09d190u: goto P_0c09d190;
case 0x0c09d192u: goto P_0c09d192;
case 0x0c09d194u: goto P_0c09d194;
case 0x0c09d196u: goto P_0c09d196;
case 0x0c09d198u: goto P_0c09d198;
case 0x0c09d19au: goto P_0c09d19a;
case 0x0c09d19cu: goto P_0c09d19c;
case 0x0c09d19eu: goto P_0c09d19e;
case 0x0c09d1a0u: goto P_0c09d1a0;
case 0x0c09d1a2u: goto P_0c09d1a2;
case 0x0c09d1a4u: goto P_0c09d1a4;
case 0x0c09d1a6u: goto P_0c09d1a6;
case 0x0c09d1a8u: goto P_0c09d1a8;
case 0x0c09d1aau: goto P_0c09d1aa;
case 0x0c09d1acu: goto P_0c09d1ac;
case 0x0c09d1aeu: goto P_0c09d1ae;
case 0x0c09d1b0u: goto P_0c09d1b0;
case 0x0c09d1b2u: goto P_0c09d1b2;
case 0x0c09d1b4u: goto P_0c09d1b4;
case 0x0c09d1fcu: goto P_0c09d1fc;
case 0x0c09d1feu: goto P_0c09d1fe;
case 0x0c09d200u: goto P_0c09d200;
case 0x0c09d202u: goto P_0c09d202;
case 0x0c09d204u: goto P_0c09d204;
case 0x0c09d206u: goto P_0c09d206;
case 0x0c09d208u: goto P_0c09d208;
case 0x0c09d20au: goto P_0c09d20a;
case 0x0c09d20cu: goto P_0c09d20c;
case 0x0c09d20eu: goto P_0c09d20e;
case 0x0c09d210u: goto P_0c09d210;
case 0x0c09d212u: goto P_0c09d212;
case 0x0c09d214u: goto P_0c09d214;
case 0x0c09d216u: goto P_0c09d216;
case 0x0c09d218u: goto P_0c09d218;
case 0x0c09d21au: goto P_0c09d21a;
case 0x0c09d21cu: goto P_0c09d21c;
case 0x0c09d21eu: goto P_0c09d21e;
case 0x0c09d220u: goto P_0c09d220;
case 0x0c09d222u: goto P_0c09d222;
case 0x0c09d224u: goto P_0c09d224;
case 0x0c09d226u: goto P_0c09d226;
case 0x0c09d228u: goto P_0c09d228;
case 0x0c09d22au: goto P_0c09d22a;
case 0x0c09d22cu: goto P_0c09d22c;
case 0x0c09d22eu: goto P_0c09d22e;
case 0x0c09d230u: goto P_0c09d230;
case 0x0c09d232u: goto P_0c09d232;
case 0x0c09d234u: goto P_0c09d234;
case 0x0c09d236u: goto P_0c09d236;
case 0x0c09d238u: goto P_0c09d238;
case 0x0c09d23au: goto P_0c09d23a;
case 0x0c09d23cu: goto P_0c09d23c;
case 0x0c09d23eu: goto P_0c09d23e;
case 0x0c09d240u: goto P_0c09d240;
case 0x0c09d242u: goto P_0c09d242;
case 0x0c09d244u: goto P_0c09d244;
case 0x0c09d246u: goto P_0c09d246;
case 0x0c09d248u: goto P_0c09d248;
case 0x0c09d24au: goto P_0c09d24a;
case 0x0c09d24cu: goto P_0c09d24c;
case 0x0c09d24eu: goto P_0c09d24e;
case 0x0c09d250u: goto P_0c09d250;
case 0x0c09d252u: goto P_0c09d252;
case 0x0c09d254u: goto P_0c09d254;
case 0x0c09d256u: goto P_0c09d256;
case 0x0c09d258u: goto P_0c09d258;
case 0x0c09d25au: goto P_0c09d25a;
case 0x0c09d25cu: goto P_0c09d25c;
case 0x0c09d25eu: goto P_0c09d25e;
case 0x0c09d260u: goto P_0c09d260;
case 0x0c09d262u: goto P_0c09d262;
case 0x0c09d264u: goto P_0c09d264;
case 0x0c09d266u: goto P_0c09d266;
case 0x0c09d268u: goto P_0c09d268;
case 0x0c09d26au: goto P_0c09d26a;
case 0x0c09d26cu: goto P_0c09d26c;
case 0x0c09d26eu: goto P_0c09d26e;
case 0x0c09d270u: goto P_0c09d270;
case 0x0c09d272u: goto P_0c09d272;
case 0x0c09d274u: goto P_0c09d274;
case 0x0c09d276u: goto P_0c09d276;
case 0x0c09d278u: goto P_0c09d278;
case 0x0c09d27au: goto P_0c09d27a;
case 0x0c09d27cu: goto P_0c09d27c;
case 0x0c09d27eu: goto P_0c09d27e;
case 0x0c09d280u: goto P_0c09d280;
case 0x0c09d282u: goto P_0c09d282;
case 0x0c09d284u: goto P_0c09d284;
case 0x0c09d286u: goto P_0c09d286;
case 0x0c09d288u: goto P_0c09d288;
case 0x0c09d28au: goto P_0c09d28a;
case 0x0c09d28cu: goto P_0c09d28c;
case 0x0c09d28eu: goto P_0c09d28e;
case 0x0c09d290u: goto P_0c09d290;
case 0x0c09d292u: goto P_0c09d292;
case 0x0c09d294u: goto P_0c09d294;
case 0x0c09d296u: goto P_0c09d296;
case 0x0c09d298u: goto P_0c09d298;
case 0x0c09d29au: goto P_0c09d29a;
case 0x0c09d29cu: goto P_0c09d29c;
case 0x0c09d29eu: goto P_0c09d29e;
case 0x0c09d2a0u: goto P_0c09d2a0;
case 0x0c09d2a2u: goto P_0c09d2a2;
case 0x0c09d2a4u: goto P_0c09d2a4;
case 0x0c09d2a6u: goto P_0c09d2a6;
case 0x0c09d2a8u: goto P_0c09d2a8;
case 0x0c09d2aau: goto P_0c09d2aa;
case 0x0c09d2acu: goto P_0c09d2ac;
case 0x0c09d2aeu: goto P_0c09d2ae;
case 0x0c09d2b0u: goto P_0c09d2b0;
case 0x0c09d2b2u: goto P_0c09d2b2;
case 0x0c09d2b4u: goto P_0c09d2b4;
case 0x0c09d2b6u: goto P_0c09d2b6;
case 0x0c09d2b8u: goto P_0c09d2b8;
case 0x0c09d2bau: goto P_0c09d2ba;
case 0x0c09d2bcu: goto P_0c09d2bc;
case 0x0c09d2beu: goto P_0c09d2be;
case 0x0c09d2c0u: goto P_0c09d2c0;
case 0x0c09d2c2u: goto P_0c09d2c2;
case 0x0c09d2c4u: goto P_0c09d2c4;
case 0x0c09d2c6u: goto P_0c09d2c6;
case 0x0c09d2c8u: goto P_0c09d2c8;
case 0x0c09d2cau: goto P_0c09d2ca;
case 0x0c09d2ccu: goto P_0c09d2cc;
case 0x0c09d2ceu: goto P_0c09d2ce;
case 0x0c09d2d0u: goto P_0c09d2d0;
case 0x0c09d2d2u: goto P_0c09d2d2;
case 0x0c09d2d4u: goto P_0c09d2d4;
case 0x0c09d2d6u: goto P_0c09d2d6;
case 0x0c09d2d8u: goto P_0c09d2d8;
case 0x0c09d2dau: goto P_0c09d2da;
case 0x0c09d2dcu: goto P_0c09d2dc;
case 0x0c09d2deu: goto P_0c09d2de;
case 0x0c09d2e0u: goto P_0c09d2e0;
case 0x0c09d2e2u: goto P_0c09d2e2;
case 0x0c09d2e4u: goto P_0c09d2e4;
case 0x0c09d2e6u: goto P_0c09d2e6;
case 0x0c09d2e8u: goto P_0c09d2e8;
case 0x0c09d2eau: goto P_0c09d2ea;
case 0x0c09d2ecu: goto P_0c09d2ec;
case 0x0c09d2eeu: goto P_0c09d2ee;
case 0x0c09d2f0u: goto P_0c09d2f0;
case 0x0c09d2f2u: goto P_0c09d2f2;
case 0x0c09d2f4u: goto P_0c09d2f4;
case 0x0c09d2f6u: goto P_0c09d2f6;
case 0x0c09d2f8u: goto P_0c09d2f8;
case 0x0c09d2fau: goto P_0c09d2fa;
case 0x0c09d2fcu: goto P_0c09d2fc;
case 0x0c09d2feu: goto P_0c09d2fe;
case 0x0c09d300u: goto P_0c09d300;
case 0x0c09d302u: goto P_0c09d302;
case 0x0c09d304u: goto P_0c09d304;
case 0x0c09d306u: goto P_0c09d306;
case 0x0c09d308u: goto P_0c09d308;
case 0x0c09d30au: goto P_0c09d30a;
case 0x0c09d30cu: goto P_0c09d30c;
case 0x0c09d30eu: goto P_0c09d30e;
case 0x0c09d310u: goto P_0c09d310;
case 0x0c09d312u: goto P_0c09d312;
case 0x0c09d314u: goto P_0c09d314;
case 0x0c09d32cu: goto P_0c09d32c;
case 0x0c09d32eu: goto P_0c09d32e;
case 0x0c09d330u: goto P_0c09d330;
case 0x0c09d332u: goto P_0c09d332;
case 0x0c09d334u: goto P_0c09d334;
case 0x0c09d336u: goto P_0c09d336;
case 0x0c09d338u: goto P_0c09d338;
case 0x0c09d33au: goto P_0c09d33a;
case 0x0c09d33cu: goto P_0c09d33c;
case 0x0c09d33eu: goto P_0c09d33e;
case 0x0c09d340u: goto P_0c09d340;
case 0x0c09d342u: goto P_0c09d342;
case 0x0c09d344u: goto P_0c09d344;
case 0x0c09d346u: goto P_0c09d346;
case 0x0c09d348u: goto P_0c09d348;
case 0x0c09d34au: goto P_0c09d34a;
case 0x0c09d34cu: goto P_0c09d34c;
case 0x0c09d34eu: goto P_0c09d34e;
case 0x0c09d350u: goto P_0c09d350;
case 0x0c09d352u: goto P_0c09d352;
case 0x0c09d354u: goto P_0c09d354;
case 0x0c09d356u: goto P_0c09d356;
case 0x0c09d358u: goto P_0c09d358;
case 0x0c09d35au: goto P_0c09d35a;
case 0x0c09d35cu: goto P_0c09d35c;
case 0x0c09d35eu: goto P_0c09d35e;
case 0x0c09d360u: goto P_0c09d360;
case 0x0c09d362u: goto P_0c09d362;
case 0x0c09d364u: goto P_0c09d364;
case 0x0c09d366u: goto P_0c09d366;
case 0x0c09d368u: goto P_0c09d368;
case 0x0c09d36au: goto P_0c09d36a;
case 0x0c09d36cu: goto P_0c09d36c;
case 0x0c09d36eu: goto P_0c09d36e;
case 0x0c09d370u: goto P_0c09d370;
case 0x0c09d372u: goto P_0c09d372;
case 0x0c09d374u: goto P_0c09d374;
case 0x0c09d376u: goto P_0c09d376;
case 0x0c09d378u: goto P_0c09d378;
case 0x0c09d37au: goto P_0c09d37a;
case 0x0c09d37cu: goto P_0c09d37c;
case 0x0c09d37eu: goto P_0c09d37e;
case 0x0c09d380u: goto P_0c09d380;
case 0x0c09d382u: goto P_0c09d382;
case 0x0c09d384u: goto P_0c09d384;
case 0x0c09d386u: goto P_0c09d386;
case 0x0c09d388u: goto P_0c09d388;
case 0x0c09d38au: goto P_0c09d38a;
case 0x0c09d38cu: goto P_0c09d38c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09af6c: /* original 2fe6, guest PC 0x0c09af6c */
if(!s->budget--) { s->failed_pc=0x0c09af6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af6e;
P_0c09af6e: /* original 2fd6, guest PC 0x0c09af6e */
if(!s->budget--) { s->failed_pc=0x0c09af6eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af70;
P_0c09af70: /* original 2fc6, guest PC 0x0c09af70 */
if(!s->budget--) { s->failed_pc=0x0c09af70u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af72;
P_0c09af72: /* original 4f22, guest PC 0x0c09af72 */
if(!s->budget--) { s->failed_pc=0x0c09af72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09af74;
P_0c09af74: /* original d32c, guest PC 0x0c09af74 */
if(!s->budget--) { s->failed_pc=0x0c09af74u; return 0; }
r[3]=read(ram,0x0c09b028u,4);
goto P_0c09af76;
P_0c09af76: /* original 7ffc, guest PC 0x0c09af76 */
if(!s->budget--) { s->failed_pc=0x0c09af76u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09af78;
P_0c09af78: /* original 2f32, guest PC 0x0c09af78 */
if(!s->budget--) { s->failed_pc=0x0c09af78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09af7a;
P_0c09af7a: /* original dc2c, guest PC 0x0c09af7a */
if(!s->budget--) { s->failed_pc=0x0c09af7au; return 0; }
r[12]=read(ram,0x0c09b02cu,4);
goto P_0c09af7c;
P_0c09af7c: /* original dd2c, guest PC 0x0c09af7c */
if(!s->budget--) { s->failed_pc=0x0c09af7cu; return 0; }
r[13]=read(ram,0x0c09b030u,4);
goto P_0c09af7e;
P_0c09af7e: /* original 4d0b, guest PC 0x0c09af7e */
if(!s->budget--) { s->failed_pc=0x0c09af7eu; return 0; }
target=r[13];
r[16]=code_base|0x0c09af82u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09af82u) { target=s->pc; goto dispatch; }
goto P_0c09af82;
P_0c09af80: /* original e400, guest PC 0x0c09af80 */
if(!s->budget--) { s->failed_pc=0x0c09af80u; return 0; }
r[4]=0x00000000u;
goto P_0c09af82;
P_0c09af82: /* original 6403, guest PC 0x0c09af82 */
if(!s->budget--) { s->failed_pc=0x0c09af82u; return 0; }
r[4]=r[0];
goto P_0c09af84;
P_0c09af84: /* original 5e42, guest PC 0x0c09af84 */
if(!s->budget--) { s->failed_pc=0x0c09af84u; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09af86;
P_0c09af86: /* original 53c2, guest PC 0x0c09af86 */
if(!s->budget--) { s->failed_pc=0x0c09af86u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c09af88;
P_0c09af88: /* original d42a, guest PC 0x0c09af88 */
if(!s->budget--) { s->failed_pc=0x0c09af88u; return 0; }
r[4]=read(ram,0x0c09b034u,4);
goto P_0c09af8a;
P_0c09af8a: /* original 2349, guest PC 0x0c09af8a */
if(!s->budget--) { s->failed_pc=0x0c09af8au; return 0; }
r[3]&=r[4];
goto P_0c09af8c;
P_0c09af8c: /* original 3340, guest PC 0x0c09af8c */
if(!s->budget--) { s->failed_pc=0x0c09af8cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c09af8e;
P_0c09af8e: /* original 8b05, guest PC 0x0c09af8e */
if(!s->budget--) { s->failed_pc=0x0c09af8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09af9c; }
goto P_0c09af90;
P_0c09af90: /* original 4d0b, guest PC 0x0c09af90 */
if(!s->budget--) { s->failed_pc=0x0c09af90u; return 0; }
target=r[13];
r[16]=code_base|0x0c09af94u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09af94u) { target=s->pc; goto dispatch; }
goto P_0c09af94;
P_0c09af92: /* original e401, guest PC 0x0c09af92 */
if(!s->budget--) { s->failed_pc=0x0c09af92u; return 0; }
r[4]=0x00000001u;
goto P_0c09af94;
P_0c09af94: /* original 6403, guest PC 0x0c09af94 */
if(!s->budget--) { s->failed_pc=0x0c09af94u; return 0; }
r[4]=r[0];
goto P_0c09af96;
P_0c09af96: /* original 5342, guest PC 0x0c09af96 */
if(!s->budget--) { s->failed_pc=0x0c09af96u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09af98;
P_0c09af98: /* original a008, guest PC 0x0c09af98 */
if(!s->budget--) { s->failed_pc=0x0c09af98u; return 0; }
r[14]|=r[3];
goto P_0c09afac;
P_0c09af9a: /* original 2e3b, guest PC 0x0c09af9a */
if(!s->budget--) { s->failed_pc=0x0c09af9au; return 0; }
r[14]|=r[3];
goto P_0c09af9c;
P_0c09af9c: /* original 52c2, guest PC 0x0c09af9c */
if(!s->budget--) { s->failed_pc=0x0c09af9cu; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09af9e;
P_0c09af9e: /* original d326, guest PC 0x0c09af9e */
if(!s->budget--) { s->failed_pc=0x0c09af9eu; return 0; }
r[3]=read(ram,0x0c09b038u,4);
goto P_0c09afa0;
P_0c09afa0: /* original 2238, guest PC 0x0c09afa0 */
if(!s->budget--) { s->failed_pc=0x0c09afa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09afa2;
P_0c09afa2: /* original 8903, guest PC 0x0c09afa2 */
if(!s->budget--) { s->failed_pc=0x0c09afa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09afac; }
goto P_0c09afa4;
P_0c09afa4: /* original 4d0b, guest PC 0x0c09afa4 */
if(!s->budget--) { s->failed_pc=0x0c09afa4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09afa8u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09afa8u) { target=s->pc; goto dispatch; }
goto P_0c09afa8;
P_0c09afa6: /* original e401, guest PC 0x0c09afa6 */
if(!s->budget--) { s->failed_pc=0x0c09afa6u; return 0; }
r[4]=0x00000001u;
goto P_0c09afa8;
P_0c09afa8: /* original 6403, guest PC 0x0c09afa8 */
if(!s->budget--) { s->failed_pc=0x0c09afa8u; return 0; }
r[4]=r[0];
goto P_0c09afaa;
P_0c09afaa: /* original 5e42, guest PC 0x0c09afaa */
if(!s->budget--) { s->failed_pc=0x0c09afaau; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09afac;
P_0c09afac: /* original 63f2, guest PC 0x0c09afac */
if(!s->budget--) { s->failed_pc=0x0c09afacu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09afae;
P_0c09afae: /* original 7f04, guest PC 0x0c09afae */
if(!s->budget--) { s->failed_pc=0x0c09afaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c09afb0;
P_0c09afb0: /* original 4f26, guest PC 0x0c09afb0 */
if(!s->budget--) { s->failed_pc=0x0c09afb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09afb2;
P_0c09afb2: /* original 9038, guest PC 0x0c09afb2 */
if(!s->budget--) { s->failed_pc=0x0c09afb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b026u,2);
goto P_0c09afb4;
P_0c09afb4: /* original 03e6, guest PC 0x0c09afb4 */
if(!s->budget--) { s->failed_pc=0x0c09afb4u; return 0; }
write(ram,r[3]+r[0],r[14],4);
goto P_0c09afb6;
P_0c09afb6: /* original 60e3, guest PC 0x0c09afb6 */
if(!s->budget--) { s->failed_pc=0x0c09afb6u; return 0; }
r[0]=r[14];
goto P_0c09afb8;
P_0c09afb8: /* original 6cf6, guest PC 0x0c09afb8 */
if(!s->budget--) { s->failed_pc=0x0c09afb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09afba;
P_0c09afba: /* original 6df6, guest PC 0x0c09afba */
if(!s->budget--) { s->failed_pc=0x0c09afbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09afbc;
P_0c09afbc: /* original 000b, guest PC 0x0c09afbc */
if(!s->budget--) { s->failed_pc=0x0c09afbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09afbe: /* original 6ef6, guest PC 0x0c09afbe */
if(!s->budget--) { s->failed_pc=0x0c09afbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09afc0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09afc0u; return 0; } return 1;
P_0c09cfac: /* original 2fe6, guest PC 0x0c09cfac */
if(!s->budget--) { s->failed_pc=0x0c09cfacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfae;
P_0c09cfae: /* original 2fd6, guest PC 0x0c09cfae */
if(!s->budget--) { s->failed_pc=0x0c09cfaeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfb0;
P_0c09cfb0: /* original 2fc6, guest PC 0x0c09cfb0 */
if(!s->budget--) { s->failed_pc=0x0c09cfb0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfb2;
P_0c09cfb2: /* original 2fb6, guest PC 0x0c09cfb2 */
if(!s->budget--) { s->failed_pc=0x0c09cfb2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfb4;
P_0c09cfb4: /* original 2fa6, guest PC 0x0c09cfb4 */
if(!s->budget--) { s->failed_pc=0x0c09cfb4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfb6;
P_0c09cfb6: /* original 4f22, guest PC 0x0c09cfb6 */
if(!s->budget--) { s->failed_pc=0x0c09cfb6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09cfb8;
P_0c09cfb8: /* original d335, guest PC 0x0c09cfb8 */
if(!s->budget--) { s->failed_pc=0x0c09cfb8u; return 0; }
r[3]=read(ram,0x0c09d090u,4);
goto P_0c09cfba;
P_0c09cfba: /* original de34, guest PC 0x0c09cfba */
if(!s->budget--) { s->failed_pc=0x0c09cfbau; return 0; }
r[14]=read(ram,0x0c09d08cu,4);
goto P_0c09cfbc;
P_0c09cfbc: /* original 430b, guest PC 0x0c09cfbc */
if(!s->budget--) { s->failed_pc=0x0c09cfbcu; return 0; }
target=r[3];
r[16]=code_base|0x0c09cfc0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cfc0u) { target=s->pc; goto dispatch; }
goto P_0c09cfc0;
P_0c09cfbe: /* original 0009, guest PC 0x0c09cfbe */
if(!s->budget--) { s->failed_pc=0x0c09cfbeu; return 0; }
goto P_0c09cfc0;
P_0c09cfc0: /* original 6d03, guest PC 0x0c09cfc0 */
if(!s->budget--) { s->failed_pc=0x0c09cfc0u; return 0; }
r[13]=r[0];
goto P_0c09cfc2;
P_0c09cfc2: /* original e07d, guest PC 0x0c09cfc2 */
if(!s->budget--) { s->failed_pc=0x0c09cfc2u; return 0; }
r[0]=0x0000007du;
goto P_0c09cfc4;
P_0c09cfc4: /* original e310, guest PC 0x0c09cfc4 */
if(!s->budget--) { s->failed_pc=0x0c09cfc4u; return 0; }
r[3]=0x00000010u;
goto P_0c09cfc6;
P_0c09cfc6: /* original eb00, guest PC 0x0c09cfc6 */
if(!s->budget--) { s->failed_pc=0x0c09cfc6u; return 0; }
r[11]=0x00000000u;
goto P_0c09cfc8;
P_0c09cfc8: /* original e240, guest PC 0x0c09cfc8 */
if(!s->budget--) { s->failed_pc=0x0c09cfc8u; return 0; }
r[2]=0x00000040u;
goto P_0c09cfca;
P_0c09cfca: /* original 23d8, guest PC 0x0c09cfca */
if(!s->budget--) { s->failed_pc=0x0c09cfcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cfcc;
P_0c09cfcc: /* original 1e23, guest PC 0x0c09cfcc */
if(!s->budget--) { s->failed_pc=0x0c09cfccu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09cfce;
P_0c09cfce: /* original 1eb6, guest PC 0x0c09cfce */
if(!s->budget--) { s->failed_pc=0x0c09cfceu; return 0; }
write(ram,r[14]+24,r[11],4);
goto P_0c09cfd0;
P_0c09cfd0: /* original 0eb4, guest PC 0x0c09cfd0 */
if(!s->budget--) { s->failed_pc=0x0c09cfd0u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09cfd2;
P_0c09cfd2: /* original 9a54, guest PC 0x0c09cfd2 */
if(!s->budget--) { s->failed_pc=0x0c09cfd2u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d07eu,2);
goto P_0c09cfd4;
P_0c09cfd4: /* original dc2f, guest PC 0x0c09cfd4 */
if(!s->budget--) { s->failed_pc=0x0c09cfd4u; return 0; }
r[12]=read(ram,0x0c09d094u,4);
goto P_0c09cfd6;
P_0c09cfd6: /* original 8d0b, guest PC 0x0c09cfd6 */
if(!s->budget--) { s->failed_pc=0x0c09cfd6u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[11],4);
if(cond) { goto P_0c09cff0; }
goto P_0c09cfda;
P_0c09cfd8: /* original 1eb5, guest PC 0x0c09cfd8 */
if(!s->budget--) { s->failed_pc=0x0c09cfd8u; return 0; }
write(ram,r[14]+20,r[11],4);
goto P_0c09cfda;
P_0c09cfda: /* original 4c0b, guest PC 0x0c09cfda */
if(!s->budget--) { s->failed_pc=0x0c09cfdau; return 0; }
target=r[12];
r[16]=code_base|0x0c09cfdeu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cfdeu) { target=s->pc; goto dispatch; }
goto P_0c09cfde;
P_0c09cfdc: /* original 64a3, guest PC 0x0c09cfdc */
if(!s->budget--) { s->failed_pc=0x0c09cfdcu; return 0; }
r[4]=r[10];
goto P_0c09cfde;
P_0c09cfde: /* original 904f, guest PC 0x0c09cfde */
if(!s->budget--) { s->failed_pc=0x0c09cfdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d080u,2);
goto P_0c09cfe0;
P_0c09cfe0: /* original 03ee, guest PC 0x0c09cfe0 */
if(!s->budget--) { s->failed_pc=0x0c09cfe0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cfe2;
P_0c09cfe2: /* original 73ff, guest PC 0x0c09cfe2 */
if(!s->budget--) { s->failed_pc=0x0c09cfe2u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cfe4;
P_0c09cfe4: /* original 0e36, guest PC 0x0c09cfe4 */
if(!s->budget--) { s->failed_pc=0x0c09cfe4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cfe6;
P_0c09cfe6: /* original 02ee, guest PC 0x0c09cfe6 */
if(!s->budget--) { s->failed_pc=0x0c09cfe6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cfe8;
P_0c09cfe8: /* original 4211, guest PC 0x0c09cfe8 */
if(!s->budget--) { s->failed_pc=0x0c09cfe8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cfea;
P_0c09cfea: /* original 8901, guest PC 0x0c09cfea */
if(!s->budget--) { s->failed_pc=0x0c09cfeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cff0; }
goto P_0c09cfec;
P_0c09cfec: /* original e103, guest PC 0x0c09cfec */
if(!s->budget--) { s->failed_pc=0x0c09cfecu; return 0; }
r[1]=0x00000003u;
goto P_0c09cfee;
P_0c09cfee: /* original 0e16, guest PC 0x0c09cfee */
if(!s->budget--) { s->failed_pc=0x0c09cfeeu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09cff0;
P_0c09cff0: /* original e320, guest PC 0x0c09cff0 */
if(!s->budget--) { s->failed_pc=0x0c09cff0u; return 0; }
r[3]=0x00000020u;
goto P_0c09cff2;
P_0c09cff2: /* original 23d8, guest PC 0x0c09cff2 */
if(!s->budget--) { s->failed_pc=0x0c09cff2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cff4;
P_0c09cff4: /* original 890a, guest PC 0x0c09cff4 */
if(!s->budget--) { s->failed_pc=0x0c09cff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d00c; }
goto P_0c09cff6;
P_0c09cff6: /* original 4c0b, guest PC 0x0c09cff6 */
if(!s->budget--) { s->failed_pc=0x0c09cff6u; return 0; }
target=r[12];
r[16]=code_base|0x0c09cffau;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cffau) { target=s->pc; goto dispatch; }
goto P_0c09cffa;
P_0c09cff8: /* original 64a3, guest PC 0x0c09cff8 */
if(!s->budget--) { s->failed_pc=0x0c09cff8u; return 0; }
r[4]=r[10];
goto P_0c09cffa;
P_0c09cffa: /* original 9041, guest PC 0x0c09cffa */
if(!s->budget--) { s->failed_pc=0x0c09cffau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d080u,2);
goto P_0c09cffc;
P_0c09cffc: /* original e203, guest PC 0x0c09cffc */
if(!s->budget--) { s->failed_pc=0x0c09cffcu; return 0; }
r[2]=0x00000003u;
goto P_0c09cffe;
P_0c09cffe: /* original 03ee, guest PC 0x0c09cffe */
if(!s->budget--) { s->failed_pc=0x0c09cffeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09d000;
P_0c09d000: /* original 7301, guest PC 0x0c09d000 */
if(!s->budget--) { s->failed_pc=0x0c09d000u; return 0; }
r[3]+=0x00000001u;
goto P_0c09d002;
P_0c09d002: /* original 0e36, guest PC 0x0c09d002 */
if(!s->budget--) { s->failed_pc=0x0c09d002u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09d004;
P_0c09d004: /* original 01ee, guest PC 0x0c09d004 */
if(!s->budget--) { s->failed_pc=0x0c09d004u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09d006;
P_0c09d006: /* original 3123, guest PC 0x0c09d006 */
if(!s->budget--) { s->failed_pc=0x0c09d006u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c09d008;
P_0c09d008: /* original 8b00, guest PC 0x0c09d008 */
if(!s->budget--) { s->failed_pc=0x0c09d008u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d00c; }
goto P_0c09d00a;
P_0c09d00a: /* original 0eb6, guest PC 0x0c09d00a */
if(!s->budget--) { s->failed_pc=0x0c09d00au; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09d00c;
P_0c09d00c: /* original e340, guest PC 0x0c09d00c */
if(!s->budget--) { s->failed_pc=0x0c09d00cu; return 0; }
r[3]=0x00000040u;
goto P_0c09d00e;
P_0c09d00e: /* original 23d8, guest PC 0x0c09d00e */
if(!s->budget--) { s->failed_pc=0x0c09d00eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09d010;
P_0c09d010: /* original 8909, guest PC 0x0c09d010 */
if(!s->budget--) { s->failed_pc=0x0c09d010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d026; }
goto P_0c09d012;
P_0c09d012: /* original 4c0b, guest PC 0x0c09d012 */
if(!s->budget--) { s->failed_pc=0x0c09d012u; return 0; }
target=r[12];
r[16]=code_base|0x0c09d016u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d016u) { target=s->pc; goto dispatch; }
goto P_0c09d016;
P_0c09d014: /* original 64a3, guest PC 0x0c09d014 */
if(!s->budget--) { s->failed_pc=0x0c09d014u; return 0; }
r[4]=r[10];
goto P_0c09d016;
P_0c09d016: /* original 9034, guest PC 0x0c09d016 */
if(!s->budget--) { s->failed_pc=0x0c09d016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d082u,2);
goto P_0c09d018;
P_0c09d018: /* original 03ee, guest PC 0x0c09d018 */
if(!s->budget--) { s->failed_pc=0x0c09d018u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09d01a;
P_0c09d01a: /* original 73ff, guest PC 0x0c09d01a */
if(!s->budget--) { s->failed_pc=0x0c09d01au; return 0; }
r[3]+=0xffffffffu;
goto P_0c09d01c;
P_0c09d01c: /* original 0e36, guest PC 0x0c09d01c */
if(!s->budget--) { s->failed_pc=0x0c09d01cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09d01e;
P_0c09d01e: /* original 02ee, guest PC 0x0c09d01e */
if(!s->budget--) { s->failed_pc=0x0c09d01eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09d020;
P_0c09d020: /* original 4211, guest PC 0x0c09d020 */
if(!s->budget--) { s->failed_pc=0x0c09d020u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09d022;
P_0c09d022: /* original 8900, guest PC 0x0c09d022 */
if(!s->budget--) { s->failed_pc=0x0c09d022u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d026; }
goto P_0c09d024;
P_0c09d024: /* original 0eb6, guest PC 0x0c09d024 */
if(!s->budget--) { s->failed_pc=0x0c09d024u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09d026;
P_0c09d026: /* original 932d, guest PC 0x0c09d026 */
if(!s->budget--) { s->failed_pc=0x0c09d026u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d084u,2);
goto P_0c09d028;
P_0c09d028: /* original 23d8, guest PC 0x0c09d028 */
if(!s->budget--) { s->failed_pc=0x0c09d028u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09d02a;
P_0c09d02a: /* original 890a, guest PC 0x0c09d02a */
if(!s->budget--) { s->failed_pc=0x0c09d02au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d042; }
goto P_0c09d02c;
P_0c09d02c: /* original 4c0b, guest PC 0x0c09d02c */
if(!s->budget--) { s->failed_pc=0x0c09d02cu; return 0; }
target=r[12];
r[16]=code_base|0x0c09d030u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d030u) { target=s->pc; goto dispatch; }
goto P_0c09d030;
P_0c09d02e: /* original 64a3, guest PC 0x0c09d02e */
if(!s->budget--) { s->failed_pc=0x0c09d02eu; return 0; }
r[4]=r[10];
goto P_0c09d030;
P_0c09d030: /* original 9027, guest PC 0x0c09d030 */
if(!s->budget--) { s->failed_pc=0x0c09d030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d082u,2);
goto P_0c09d032;
P_0c09d032: /* original e401, guest PC 0x0c09d032 */
if(!s->budget--) { s->failed_pc=0x0c09d032u; return 0; }
r[4]=0x00000001u;
goto P_0c09d034;
P_0c09d034: /* original 03ee, guest PC 0x0c09d034 */
if(!s->budget--) { s->failed_pc=0x0c09d034u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09d036;
P_0c09d036: /* original 7301, guest PC 0x0c09d036 */
if(!s->budget--) { s->failed_pc=0x0c09d036u; return 0; }
r[3]+=0x00000001u;
goto P_0c09d038;
P_0c09d038: /* original 0e36, guest PC 0x0c09d038 */
if(!s->budget--) { s->failed_pc=0x0c09d038u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09d03a;
P_0c09d03a: /* original 02ee, guest PC 0x0c09d03a */
if(!s->budget--) { s->failed_pc=0x0c09d03au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09d03c;
P_0c09d03c: /* original 3243, guest PC 0x0c09d03c */
if(!s->budget--) { s->failed_pc=0x0c09d03cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c09d03e;
P_0c09d03e: /* original 8b00, guest PC 0x0c09d03e */
if(!s->budget--) { s->failed_pc=0x0c09d03eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d042; }
goto P_0c09d040;
P_0c09d040: /* original 0e46, guest PC 0x0c09d040 */
if(!s->budget--) { s->failed_pc=0x0c09d040u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09d042;
P_0c09d042: /* original e304, guest PC 0x0c09d042 */
if(!s->budget--) { s->failed_pc=0x0c09d042u; return 0; }
r[3]=0x00000004u;
goto P_0c09d044;
P_0c09d044: /* original 23d8, guest PC 0x0c09d044 */
if(!s->budget--) { s->failed_pc=0x0c09d044u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09d046;
P_0c09d046: /* original 8902, guest PC 0x0c09d046 */
if(!s->budget--) { s->failed_pc=0x0c09d046u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d04e; }
goto P_0c09d048;
P_0c09d048: /* original 941d, guest PC 0x0c09d048 */
if(!s->budget--) { s->failed_pc=0x0c09d048u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d086u,2);
goto P_0c09d04a;
P_0c09d04a: /* original 4c0b, guest PC 0x0c09d04a */
if(!s->budget--) { s->failed_pc=0x0c09d04au; return 0; }
target=r[12];
r[16]=code_base|0x0c09d04eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d04eu) { target=s->pc; goto dispatch; }
goto P_0c09d04e;
P_0c09d04c: /* original 0009, guest PC 0x0c09d04c */
if(!s->budget--) { s->failed_pc=0x0c09d04cu; return 0; }
goto P_0c09d04e;
P_0c09d04e: /* original e30a, guest PC 0x0c09d04e */
if(!s->budget--) { s->failed_pc=0x0c09d04eu; return 0; }
r[3]=0x0000000au;
goto P_0c09d050;
P_0c09d050: /* original 23d8, guest PC 0x0c09d050 */
if(!s->budget--) { s->failed_pc=0x0c09d050u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09d052;
P_0c09d052: /* original 890d, guest PC 0x0c09d052 */
if(!s->budget--) { s->failed_pc=0x0c09d052u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d070; }
goto P_0c09d054;
P_0c09d054: /* original e108, guest PC 0x0c09d054 */
if(!s->budget--) { s->failed_pc=0x0c09d054u; return 0; }
r[1]=0x00000008u;
goto P_0c09d056;
P_0c09d056: /* original 2d18, guest PC 0x0c09d056 */
if(!s->budget--) { s->failed_pc=0x0c09d056u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[1])==0)!=0);
goto P_0c09d058;
P_0c09d058: /* original 8902, guest PC 0x0c09d058 */
if(!s->budget--) { s->failed_pc=0x0c09d058u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d060; }
goto P_0c09d05a;
P_0c09d05a: /* original 9414, guest PC 0x0c09d05a */
if(!s->budget--) { s->failed_pc=0x0c09d05au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d086u,2);
goto P_0c09d05c;
P_0c09d05c: /* original a001, guest PC 0x0c09d05c */
if(!s->budget--) { s->failed_pc=0x0c09d05cu; return 0; }
goto P_0c09d062;
P_0c09d05e: /* original 0009, guest PC 0x0c09d05e */
if(!s->budget--) { s->failed_pc=0x0c09d05eu; return 0; }
goto P_0c09d060;
P_0c09d060: /* original 9412, guest PC 0x0c09d060 */
if(!s->budget--) { s->failed_pc=0x0c09d060u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d088u,2);
goto P_0c09d062;
P_0c09d062: /* original 4c0b, guest PC 0x0c09d062 */
if(!s->budget--) { s->failed_pc=0x0c09d062u; return 0; }
target=r[12];
r[16]=code_base|0x0c09d066u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d066u) { target=s->pc; goto dispatch; }
goto P_0c09d066;
P_0c09d064: /* original 0009, guest PC 0x0c09d064 */
if(!s->budget--) { s->failed_pc=0x0c09d064u; return 0; }
goto P_0c09d066;
P_0c09d066: /* original e005, guest PC 0x0c09d066 */
if(!s->budget--) { s->failed_pc=0x0c09d066u; return 0; }
r[0]=0x00000005u;
goto P_0c09d068;
P_0c09d068: /* original 80eb, guest PC 0x0c09d068 */
if(!s->budget--) { s->failed_pc=0x0c09d068u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09d06a;
P_0c09d06a: /* original e010, guest PC 0x0c09d06a */
if(!s->budget--) { s->failed_pc=0x0c09d06au; return 0; }
r[0]=0x00000010u;
goto P_0c09d06c;
P_0c09d06c: /* original e374, guest PC 0x0c09d06c */
if(!s->budget--) { s->failed_pc=0x0c09d06cu; return 0; }
r[3]=0x00000074u;
goto P_0c09d06e;
P_0c09d06e: /* original 0e34, guest PC 0x0c09d06e */
if(!s->budget--) { s->failed_pc=0x0c09d06eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09d070;
P_0c09d070: /* original 4f26, guest PC 0x0c09d070 */
if(!s->budget--) { s->failed_pc=0x0c09d070u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d072;
P_0c09d072: /* original 6af6, guest PC 0x0c09d072 */
if(!s->budget--) { s->failed_pc=0x0c09d072u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09d074;
P_0c09d074: /* original 6bf6, guest PC 0x0c09d074 */
if(!s->budget--) { s->failed_pc=0x0c09d074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09d076;
P_0c09d076: /* original 6cf6, guest PC 0x0c09d076 */
if(!s->budget--) { s->failed_pc=0x0c09d076u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09d078;
P_0c09d078: /* original 6df6, guest PC 0x0c09d078 */
if(!s->budget--) { s->failed_pc=0x0c09d078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d07a;
P_0c09d07a: /* original 000b, guest PC 0x0c09d07a */
if(!s->budget--) { s->failed_pc=0x0c09d07au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d07c: /* original 6ef6, guest PC 0x0c09d07c */
if(!s->budget--) { s->failed_pc=0x0c09d07cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09d07eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d07eu; return 0; } return 1;
P_0c09d138: /* original 2fe6, guest PC 0x0c09d138 */
if(!s->budget--) { s->failed_pc=0x0c09d138u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d13a;
P_0c09d13a: /* original e029, guest PC 0x0c09d13a */
if(!s->budget--) { s->failed_pc=0x0c09d13au; return 0; }
r[0]=0x00000029u;
goto P_0c09d13c;
P_0c09d13c: /* original 2fd6, guest PC 0x0c09d13c */
if(!s->budget--) { s->failed_pc=0x0c09d13cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d13e;
P_0c09d13e: /* original 2fc6, guest PC 0x0c09d13e */
if(!s->budget--) { s->failed_pc=0x0c09d13eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d140;
P_0c09d140: /* original 2fb6, guest PC 0x0c09d140 */
if(!s->budget--) { s->failed_pc=0x0c09d140u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d142;
P_0c09d142: /* original 2fa6, guest PC 0x0c09d142 */
if(!s->budget--) { s->failed_pc=0x0c09d142u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d144;
P_0c09d144: /* original 2f96, guest PC 0x0c09d144 */
if(!s->budget--) { s->failed_pc=0x0c09d144u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d146;
P_0c09d146: /* original d626, guest PC 0x0c09d146 */
if(!s->budget--) { s->failed_pc=0x0c09d146u; return 0; }
r[6]=read(ram,0x0c09d1e0u,4);
goto P_0c09d148;
P_0c09d148: /* original 4f12, guest PC 0x0c09d148 */
if(!s->budget--) { s->failed_pc=0x0c09d148u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c09d14a;
P_0c09d14a: /* original 006c, guest PC 0x0c09d14a */
if(!s->budget--) { s->failed_pc=0x0c09d14au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c09d14c;
P_0c09d14c: /* original d426, guest PC 0x0c09d14c */
if(!s->budget--) { s->failed_pc=0x0c09d14cu; return 0; }
r[4]=read(ram,0x0c09d1e8u,4);
goto P_0c09d14e;
P_0c09d14e: /* original 600c, guest PC 0x0c09d14e */
if(!s->budget--) { s->failed_pc=0x0c09d14eu; return 0; }
r[0]=r[0]&255u;
goto P_0c09d150;
P_0c09d150: /* original 8803, guest PC 0x0c09d150 */
if(!s->budget--) { s->failed_pc=0x0c09d150u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09d152;
P_0c09d152: /* original 7ff8, guest PC 0x0c09d152 */
if(!s->budget--) { s->failed_pc=0x0c09d152u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09d154;
P_0c09d154: /* original 8901, guest PC 0x0c09d154 */
if(!s->budget--) { s->failed_pc=0x0c09d154u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d15a; }
goto P_0c09d156;
P_0c09d156: /* original a111, guest PC 0x0c09d156 */
if(!s->budget--) { s->failed_pc=0x0c09d156u; return 0; }
goto P_0c09d37c;
P_0c09d158: /* original 0009, guest PC 0x0c09d158 */
if(!s->budget--) { s->failed_pc=0x0c09d158u; return 0; }
goto P_0c09d15a;
P_0c09d15a: /* original e019, guest PC 0x0c09d15a */
if(!s->budget--) { s->failed_pc=0x0c09d15au; return 0; }
r[0]=0x00000019u;
goto P_0c09d15c;
P_0c09d15c: /* original 006c, guest PC 0x0c09d15c */
if(!s->budget--) { s->failed_pc=0x0c09d15cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c09d15e;
P_0c09d15e: /* original 600c, guest PC 0x0c09d15e */
if(!s->budget--) { s->failed_pc=0x0c09d15eu; return 0; }
r[0]=r[0]&255u;
goto P_0c09d160;
P_0c09d160: /* original 8802, guest PC 0x0c09d160 */
if(!s->budget--) { s->failed_pc=0x0c09d160u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09d162;
P_0c09d162: /* original 8b01, guest PC 0x0c09d162 */
if(!s->budget--) { s->failed_pc=0x0c09d162u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d168; }
goto P_0c09d164;
P_0c09d164: /* original a10a, guest PC 0x0c09d164 */
if(!s->budget--) { s->failed_pc=0x0c09d164u; return 0; }
goto P_0c09d37c;
P_0c09d166: /* original 0009, guest PC 0x0c09d166 */
if(!s->budget--) { s->failed_pc=0x0c09d166u; return 0; }
goto P_0c09d168;
P_0c09d168: /* original 9029, guest PC 0x0c09d168 */
if(!s->budget--) { s->failed_pc=0x0c09d168u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d1beu,2);
goto P_0c09d16a;
P_0c09d16a: /* original d520, guest PC 0x0c09d16a */
if(!s->budget--) { s->failed_pc=0x0c09d16au; return 0; }
r[5]=read(ram,0x0c09d1ecu,4);
goto P_0c09d16c;
P_0c09d16c: /* original 026e, guest PC 0x0c09d16c */
if(!s->budget--) { s->failed_pc=0x0c09d16cu; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c09d16e;
P_0c09d16e: /* original 5354, guest PC 0x0c09d16e */
if(!s->budget--) { s->failed_pc=0x0c09d16eu; return 0; }
r[3]=read(ram,r[5]+16,4);
goto P_0c09d170;
P_0c09d170: /* original 3230, guest PC 0x0c09d170 */
if(!s->budget--) { s->failed_pc=0x0c09d170u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c09d172;
P_0c09d172: /* original 8b01, guest PC 0x0c09d172 */
if(!s->budget--) { s->failed_pc=0x0c09d172u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d178; }
goto P_0c09d174;
P_0c09d174: /* original a001, guest PC 0x0c09d174 */
if(!s->budget--) { s->failed_pc=0x0c09d174u; return 0; }
r[13]=0x00000000u;
goto P_0c09d17a;
P_0c09d176: /* original ed00, guest PC 0x0c09d176 */
if(!s->budget--) { s->failed_pc=0x0c09d176u; return 0; }
r[13]=0x00000000u;
goto P_0c09d178;
P_0c09d178: /* original ed01, guest PC 0x0c09d178 */
if(!s->budget--) { s->failed_pc=0x0c09d178u; return 0; }
r[13]=0x00000001u;
goto P_0c09d17a;
P_0c09d17a: /* original 2dd8, guest PC 0x0c09d17a */
if(!s->budget--) { s->failed_pc=0x0c09d17au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c09d17c;
P_0c09d17c: /* original 8f03, guest PC 0x0c09d17c */
if(!s->budget--) { s->failed_pc=0x0c09d17cu; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c09d186; }
goto P_0c09d180;
P_0c09d17e: /* original e061, guest PC 0x0c09d17e */
if(!s->budget--) { s->failed_pc=0x0c09d17eu; return 0; }
r[0]=0x00000061u;
goto P_0c09d180;
P_0c09d180: /* original 5754, guest PC 0x0c09d180 */
if(!s->budget--) { s->failed_pc=0x0c09d180u; return 0; }
r[7]=read(ram,r[5]+16,4);
goto P_0c09d182;
P_0c09d182: /* original a002, guest PC 0x0c09d182 */
if(!s->budget--) { s->failed_pc=0x0c09d182u; return 0; }
r[14]=read(ram,r[5]+20,4);
goto P_0c09d18a;
P_0c09d184: /* original 5e55, guest PC 0x0c09d184 */
if(!s->budget--) { s->failed_pc=0x0c09d184u; return 0; }
r[14]=read(ram,r[5]+20,4);
goto P_0c09d186;
P_0c09d186: /* original 5e54, guest PC 0x0c09d186 */
if(!s->budget--) { s->failed_pc=0x0c09d186u; return 0; }
r[14]=read(ram,r[5]+16,4);
goto P_0c09d188;
P_0c09d188: /* original 5755, guest PC 0x0c09d188 */
if(!s->budget--) { s->failed_pc=0x0c09d188u; return 0; }
r[7]=read(ram,r[5]+20,4);
goto P_0c09d18a;
P_0c09d18a: /* original 0cec, guest PC 0x0c09d18a */
if(!s->budget--) { s->failed_pc=0x0c09d18au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09d18c;
P_0c09d18c: /* original 077c, guest PC 0x0c09d18c */
if(!s->budget--) { s->failed_pc=0x0c09d18cu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c09d18e;
P_0c09d18e: /* original 6ccc, guest PC 0x0c09d18e */
if(!s->budget--) { s->failed_pc=0x0c09d18eu; return 0; }
r[12]=r[12]&255u;
goto P_0c09d190;
P_0c09d190: /* original d917, guest PC 0x0c09d190 */
if(!s->budget--) { s->failed_pc=0x0c09d190u; return 0; }
r[9]=read(ram,0x0c09d1f0u,4);
goto P_0c09d192;
P_0c09d192: /* original 6ec3, guest PC 0x0c09d192 */
if(!s->budget--) { s->failed_pc=0x0c09d192u; return 0; }
r[14]=r[12];
goto P_0c09d194;
P_0c09d194: /* original 677c, guest PC 0x0c09d194 */
if(!s->budget--) { s->failed_pc=0x0c09d194u; return 0; }
r[7]=r[7]&255u;
goto P_0c09d196;
P_0c09d196: /* original 2972, guest PC 0x0c09d196 */
if(!s->budget--) { s->failed_pc=0x0c09d196u; return 0; }
write(ram,r[9],r[7],4);
goto P_0c09d198;
P_0c09d198: /* original 4e08, guest PC 0x0c09d198 */
if(!s->budget--) { s->failed_pc=0x0c09d198u; return 0; }
r[14]<<=2;
goto P_0c09d19a;
P_0c09d19a: /* original d316, guest PC 0x0c09d19a */
if(!s->budget--) { s->failed_pc=0x0c09d19au; return 0; }
r[3]=read(ram,0x0c09d1f4u,4);
goto P_0c09d19c;
P_0c09d19c: /* original 6573, guest PC 0x0c09d19c */
if(!s->budget--) { s->failed_pc=0x0c09d19cu; return 0; }
r[5]=r[7];
goto P_0c09d19e;
P_0c09d19e: /* original db16, guest PC 0x0c09d19e */
if(!s->budget--) { s->failed_pc=0x0c09d19eu; return 0; }
r[11]=read(ram,0x0c09d1f8u,4);
goto P_0c09d1a0;
P_0c09d1a0: /* original 6132, guest PC 0x0c09d1a0 */
if(!s->budget--) { s->failed_pc=0x0c09d1a0u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09d1a2;
P_0c09d1a2: /* original 9a0d, guest PC 0x0c09d1a2 */
if(!s->budget--) { s->failed_pc=0x0c09d1a2u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d1c0u,2);
goto P_0c09d1a4;
P_0c09d1a4: /* original 6013, guest PC 0x0c09d1a4 */
if(!s->budget--) { s->failed_pc=0x0c09d1a4u; return 0; }
r[0]=r[1];
goto P_0c09d1a6;
P_0c09d1a6: /* original 88ff, guest PC 0x0c09d1a6 */
if(!s->budget--) { s->failed_pc=0x0c09d1a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c09d1a8;
P_0c09d1a8: /* original 8f28, guest PC 0x0c09d1a8 */
if(!s->budget--) { s->failed_pc=0x0c09d1a8u; return 0; }
cond=r[17]&1u;
r[5]<<=2;
if(!cond) { goto P_0c09d1fc; }
goto P_0c09d1ac;
P_0c09d1aa: /* original 4508, guest PC 0x0c09d1aa */
if(!s->budget--) { s->failed_pc=0x0c09d1aau; return 0; }
r[5]<<=2;
goto P_0c09d1ac;
P_0c09d1ac: /* original 6092, guest PC 0x0c09d1ac */
if(!s->budget--) { s->failed_pc=0x0c09d1acu; return 0; }
tmp=read(ram,r[9],4);
r[0]=tmp;
goto P_0c09d1ae;
P_0c09d1ae: /* original e201, guest PC 0x0c09d1ae */
if(!s->budget--) { s->failed_pc=0x0c09d1aeu; return 0; }
r[2]=0x00000001u;
goto P_0c09d1b0;
P_0c09d1b0: /* original 4008, guest PC 0x0c09d1b0 */
if(!s->budget--) { s->failed_pc=0x0c09d1b0u; return 0; }
r[0]<<=2;
goto P_0c09d1b2;
P_0c09d1b2: /* original a03f, guest PC 0x0c09d1b2 */
if(!s->budget--) { s->failed_pc=0x0c09d1b2u; return 0; }
write(ram,r[11]+r[0],r[2],4);
goto P_0c09d234;
P_0c09d1b4: /* original 0b26, guest PC 0x0c09d1b4 */
if(!s->budget--) { s->failed_pc=0x0c09d1b4u; return 0; }
write(ram,r[11]+r[0],r[2],4);
if(!vf3_matrix_family(0x0c09d1b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d1b6u; return 0; } return 1;
P_0c09d1fc: /* original 31d0, guest PC 0x0c09d1fc */
if(!s->budget--) { s->failed_pc=0x0c09d1fcu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[13])!=0);
goto P_0c09d1fe;
P_0c09d1fe: /* original 8b0a, guest PC 0x0c09d1fe */
if(!s->budget--) { s->failed_pc=0x0c09d1feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d216; }
goto P_0c09d200;
P_0c09d200: /* original 6092, guest PC 0x0c09d200 */
if(!s->budget--) { s->failed_pc=0x0c09d200u; return 0; }
tmp=read(ram,r[9],4);
r[0]=tmp;
goto P_0c09d202;
P_0c09d202: /* original 4008, guest PC 0x0c09d202 */
if(!s->budget--) { s->failed_pc=0x0c09d202u; return 0; }
r[0]<<=2;
goto P_0c09d204;
P_0c09d204: /* original 02be, guest PC 0x0c09d204 */
if(!s->budget--) { s->failed_pc=0x0c09d204u; return 0; }
r[2]=read(ram,r[11]+r[0],4);
goto P_0c09d206;
P_0c09d206: /* original 32a3, guest PC 0x0c09d206 */
if(!s->budget--) { s->failed_pc=0x0c09d206u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[10])!=0);
goto P_0c09d208;
P_0c09d208: /* original 8914, guest PC 0x0c09d208 */
if(!s->budget--) { s->failed_pc=0x0c09d208u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d234; }
goto P_0c09d20a;
P_0c09d20a: /* original 6092, guest PC 0x0c09d20a */
if(!s->budget--) { s->failed_pc=0x0c09d20au; return 0; }
tmp=read(ram,r[9],4);
r[0]=tmp;
goto P_0c09d20c;
P_0c09d20c: /* original 4008, guest PC 0x0c09d20c */
if(!s->budget--) { s->failed_pc=0x0c09d20cu; return 0; }
r[0]<<=2;
goto P_0c09d20e;
P_0c09d20e: /* original 02be, guest PC 0x0c09d20e */
if(!s->budget--) { s->failed_pc=0x0c09d20eu; return 0; }
r[2]=read(ram,r[11]+r[0],4);
goto P_0c09d210;
P_0c09d210: /* original 7201, guest PC 0x0c09d210 */
if(!s->budget--) { s->failed_pc=0x0c09d210u; return 0; }
r[2]+=0x00000001u;
goto P_0c09d212;
P_0c09d212: /* original a00f, guest PC 0x0c09d212 */
if(!s->budget--) { s->failed_pc=0x0c09d212u; return 0; }
write(ram,r[11]+r[0],r[2],4);
goto P_0c09d234;
P_0c09d214: /* original 0b26, guest PC 0x0c09d214 */
if(!s->budget--) { s->failed_pc=0x0c09d214u; return 0; }
write(ram,r[11]+r[0],r[2],4);
goto P_0c09d216;
P_0c09d216: /* original 60e3, guest PC 0x0c09d216 */
if(!s->budget--) { s->failed_pc=0x0c09d216u; return 0; }
r[0]=r[14];
goto P_0c09d218;
P_0c09d218: /* original 0bbe, guest PC 0x0c09d218 */
if(!s->budget--) { s->failed_pc=0x0c09d218u; return 0; }
r[11]=read(ram,r[11]+r[0],4);
goto P_0c09d21a;
P_0c09d21a: /* original d041, guest PC 0x0c09d21a */
if(!s->budget--) { s->failed_pc=0x0c09d21au; return 0; }
r[0]=read(ram,0x0c09d320u,4);
goto P_0c09d21c;
P_0c09d21c: /* original 2f02, guest PC 0x0c09d21c */
if(!s->budget--) { s->failed_pc=0x0c09d21cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09d21e;
P_0c09d21e: /* original 02ee, guest PC 0x0c09d21e */
if(!s->budget--) { s->failed_pc=0x0c09d21eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09d220;
P_0c09d220: /* original 32b3, guest PC 0x0c09d220 */
if(!s->budget--) { s->failed_pc=0x0c09d220u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[11])!=0);
goto P_0c09d222;
P_0c09d222: /* original 8d02, guest PC 0x0c09d222 */
if(!s->budget--) { s->failed_pc=0x0c09d222u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[2],4);
if(cond) { goto P_0c09d22a; }
goto P_0c09d226;
P_0c09d224: /* original 1f21, guest PC 0x0c09d224 */
if(!s->budget--) { s->failed_pc=0x0c09d224u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c09d226;
P_0c09d226: /* original 60f2, guest PC 0x0c09d226 */
if(!s->budget--) { s->failed_pc=0x0c09d226u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09d228;
P_0c09d228: /* original 0eb6, guest PC 0x0c09d228 */
if(!s->budget--) { s->failed_pc=0x0c09d228u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09d22a;
P_0c09d22a: /* original d03e, guest PC 0x0c09d22a */
if(!s->budget--) { s->failed_pc=0x0c09d22au; return 0; }
r[0]=read(ram,0x0c09d324u,4);
goto P_0c09d22c;
P_0c09d22c: /* original e300, guest PC 0x0c09d22c */
if(!s->budget--) { s->failed_pc=0x0c09d22cu; return 0; }
r[3]=0x00000000u;
goto P_0c09d22e;
P_0c09d22e: /* original 0e36, guest PC 0x0c09d22e */
if(!s->budget--) { s->failed_pc=0x0c09d22eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09d230;
P_0c09d230: /* original e301, guest PC 0x0c09d230 */
if(!s->budget--) { s->failed_pc=0x0c09d230u; return 0; }
r[3]=0x00000001u;
goto P_0c09d232;
P_0c09d232: /* original 0536, guest PC 0x0c09d232 */
if(!s->budget--) { s->failed_pc=0x0c09d232u; return 0; }
write(ram,r[5]+r[0],r[3],4);
goto P_0c09d234;
P_0c09d234: /* original e20d, guest PC 0x0c09d234 */
if(!s->budget--) { s->failed_pc=0x0c09d234u; return 0; }
r[2]=0x0000000du;
goto P_0c09d236;
P_0c09d236: /* original 0727, guest PC 0x0c09d236 */
if(!s->budget--) { s->failed_pc=0x0c09d236u; return 0; }
r[19]=r[7]*r[2];
goto P_0c09d238;
P_0c09d238: /* original e30d, guest PC 0x0c09d238 */
if(!s->budget--) { s->failed_pc=0x0c09d238u; return 0; }
r[3]=0x0000000du;
goto P_0c09d23a;
P_0c09d23a: /* original c73b, guest PC 0x0c09d23a */
if(!s->budget--) { s->failed_pc=0x0c09d23au; return 0; }
r[0]=code_base|0x0009d328u;
goto P_0c09d23c;
P_0c09d23c: /* original 021a, guest PC 0x0c09d23c */
if(!s->budget--) { s->failed_pc=0x0c09d23cu; return 0; }
r[2]=r[19];
goto P_0c09d23e;
P_0c09d23e: /* original 0c37, guest PC 0x0c09d23e */
if(!s->budget--) { s->failed_pc=0x0c09d23eu; return 0; }
r[19]=r[12]*r[3];
goto P_0c09d240;
P_0c09d240: /* original 32cc, guest PC 0x0c09d240 */
if(!s->budget--) { s->failed_pc=0x0c09d240u; return 0; }
r[2]+=r[12];
goto P_0c09d242;
P_0c09d242: /* original 1f21, guest PC 0x0c09d242 */
if(!s->budget--) { s->failed_pc=0x0c09d242u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c09d244;
P_0c09d244: /* original 0c1a, guest PC 0x0c09d244 */
if(!s->budget--) { s->failed_pc=0x0c09d244u; return 0; }
r[12]=r[19];
goto P_0c09d246;
P_0c09d246: /* original 3c7c, guest PC 0x0c09d246 */
if(!s->budget--) { s->failed_pc=0x0c09d246u; return 0; }
r[12]+=r[7];
goto P_0c09d248;
P_0c09d248: /* original 6723, guest PC 0x0c09d248 */
if(!s->budget--) { s->failed_pc=0x0c09d248u; return 0; }
r[7]=r[2];
goto P_0c09d24a;
P_0c09d24a: /* original 4708, guest PC 0x0c09d24a */
if(!s->budget--) { s->failed_pc=0x0c09d24au; return 0; }
r[7]<<=2;
goto P_0c09d24c;
P_0c09d24c: /* original 2fc2, guest PC 0x0c09d24c */
if(!s->budget--) { s->failed_pc=0x0c09d24cu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c09d24e;
P_0c09d24e: /* original 9262, guest PC 0x0c09d24e */
if(!s->budget--) { s->failed_pc=0x0c09d24eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d316u,2);
goto P_0c09d250;
P_0c09d250: /* original f408, guest PC 0x0c09d250 */
if(!s->budget--) { s->failed_pc=0x0c09d250u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09d252;
P_0c09d252: /* original 324c, guest PC 0x0c09d252 */
if(!s->budget--) { s->failed_pc=0x0c09d252u; return 0; }
r[2]+=r[4];
goto P_0c09d254;
P_0c09d254: /* original 327c, guest PC 0x0c09d254 */
if(!s->budget--) { s->failed_pc=0x0c09d254u; return 0; }
r[2]+=r[7];
goto P_0c09d256;
P_0c09d256: /* original f328, guest PC 0x0c09d256 */
if(!s->budget--) { s->failed_pc=0x0c09d256u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c09d258;
P_0c09d258: /* original f435, guest PC 0x0c09d258 */
if(!s->budget--) { s->failed_pc=0x0c09d258u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c09d25a;
P_0c09d25a: /* original 8f06, guest PC 0x0c09d25a */
if(!s->budget--) { s->failed_pc=0x0c09d25au; return 0; }
cond=r[17]&1u;
fr[5]=0x3f800000u;
if(!cond) { goto P_0c09d26a; }
goto P_0c09d25e;
P_0c09d25c: /* original f59d, guest PC 0x0c09d25c */
if(!s->budget--) { s->failed_pc=0x0c09d25cu; return 0; }
fr[5]=0x3f800000u;
goto P_0c09d25e;
P_0c09d25e: /* original 915a, guest PC 0x0c09d25e */
if(!s->budget--) { s->failed_pc=0x0c09d25eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d316u,2);
goto P_0c09d260;
P_0c09d260: /* original 314c, guest PC 0x0c09d260 */
if(!s->budget--) { s->failed_pc=0x0c09d260u; return 0; }
r[1]+=r[4];
goto P_0c09d262;
P_0c09d262: /* original 317c, guest PC 0x0c09d262 */
if(!s->budget--) { s->failed_pc=0x0c09d262u; return 0; }
r[1]+=r[7];
goto P_0c09d264;
P_0c09d264: /* original f318, guest PC 0x0c09d264 */
if(!s->budget--) { s->failed_pc=0x0c09d264u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c09d266;
P_0c09d266: /* original f350, guest PC 0x0c09d266 */
if(!s->budget--) { s->failed_pc=0x0c09d266u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c09d268;
P_0c09d268: /* original f13a, guest PC 0x0c09d268 */
if(!s->budget--) { s->failed_pc=0x0c09d268u; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c09d26a;
P_0c09d26a: /* original 9354, guest PC 0x0c09d26a */
if(!s->budget--) { s->failed_pc=0x0c09d26au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d316u,2);
goto P_0c09d26c;
P_0c09d26c: /* original 6cf2, guest PC 0x0c09d26c */
if(!s->budget--) { s->failed_pc=0x0c09d26cu; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c09d26e;
P_0c09d26e: /* original 334c, guest PC 0x0c09d26e */
if(!s->budget--) { s->failed_pc=0x0c09d26eu; return 0; }
r[3]+=r[4];
goto P_0c09d270;
P_0c09d270: /* original 4c08, guest PC 0x0c09d270 */
if(!s->budget--) { s->failed_pc=0x0c09d270u; return 0; }
r[12]<<=2;
goto P_0c09d272;
P_0c09d272: /* original 33cc, guest PC 0x0c09d272 */
if(!s->budget--) { s->failed_pc=0x0c09d272u; return 0; }
r[3]+=r[12];
goto P_0c09d274;
P_0c09d274: /* original f338, guest PC 0x0c09d274 */
if(!s->budget--) { s->failed_pc=0x0c09d274u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c09d276;
P_0c09d276: /* original f435, guest PC 0x0c09d276 */
if(!s->budget--) { s->failed_pc=0x0c09d276u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c09d278;
P_0c09d278: /* original 8b05, guest PC 0x0c09d278 */
if(!s->budget--) { s->failed_pc=0x0c09d278u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d286; }
goto P_0c09d27a;
P_0c09d27a: /* original 924c, guest PC 0x0c09d27a */
if(!s->budget--) { s->failed_pc=0x0c09d27au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d316u,2);
goto P_0c09d27c;
P_0c09d27c: /* original 324c, guest PC 0x0c09d27c */
if(!s->budget--) { s->failed_pc=0x0c09d27cu; return 0; }
r[2]+=r[4];
goto P_0c09d27e;
P_0c09d27e: /* original 3c2c, guest PC 0x0c09d27e */
if(!s->budget--) { s->failed_pc=0x0c09d27eu; return 0; }
r[12]+=r[2];
goto P_0c09d280;
P_0c09d280: /* original f3c8, guest PC 0x0c09d280 */
if(!s->budget--) { s->failed_pc=0x0c09d280u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c09d282;
P_0c09d282: /* original f350, guest PC 0x0c09d282 */
if(!s->budget--) { s->failed_pc=0x0c09d282u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c09d284;
P_0c09d284: /* original fc3a, guest PC 0x0c09d284 */
if(!s->budget--) { s->failed_pc=0x0c09d284u; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c09d286;
P_0c09d286: /* original 9347, guest PC 0x0c09d286 */
if(!s->budget--) { s->failed_pc=0x0c09d286u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d318u,2);
goto P_0c09d288;
P_0c09d288: /* original 334c, guest PC 0x0c09d288 */
if(!s->budget--) { s->failed_pc=0x0c09d288u; return 0; }
r[3]+=r[4];
goto P_0c09d28a;
P_0c09d28a: /* original 337c, guest PC 0x0c09d28a */
if(!s->budget--) { s->failed_pc=0x0c09d28au; return 0; }
r[3]+=r[7];
goto P_0c09d28c;
P_0c09d28c: /* original f338, guest PC 0x0c09d28c */
if(!s->budget--) { s->failed_pc=0x0c09d28cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c09d28e;
P_0c09d28e: /* original f435, guest PC 0x0c09d28e */
if(!s->budget--) { s->failed_pc=0x0c09d28eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c09d290;
P_0c09d290: /* original 8b05, guest PC 0x0c09d290 */
if(!s->budget--) { s->failed_pc=0x0c09d290u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d29e; }
goto P_0c09d292;
P_0c09d292: /* original 9241, guest PC 0x0c09d292 */
if(!s->budget--) { s->failed_pc=0x0c09d292u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d318u,2);
goto P_0c09d294;
P_0c09d294: /* original 324c, guest PC 0x0c09d294 */
if(!s->budget--) { s->failed_pc=0x0c09d294u; return 0; }
r[2]+=r[4];
goto P_0c09d296;
P_0c09d296: /* original 372c, guest PC 0x0c09d296 */
if(!s->budget--) { s->failed_pc=0x0c09d296u; return 0; }
r[7]+=r[2];
goto P_0c09d298;
P_0c09d298: /* original f378, guest PC 0x0c09d298 */
if(!s->budget--) { s->failed_pc=0x0c09d298u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c09d29a;
P_0c09d29a: /* original f350, guest PC 0x0c09d29a */
if(!s->budget--) { s->failed_pc=0x0c09d29au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c09d29c;
P_0c09d29c: /* original f73a, guest PC 0x0c09d29c */
if(!s->budget--) { s->failed_pc=0x0c09d29cu; return 0; }
vf3_matrix_store(s,ram,3,r[7]);
goto P_0c09d29e;
P_0c09d29e: /* original 933c, guest PC 0x0c09d29e */
if(!s->budget--) { s->failed_pc=0x0c09d29eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d31au,2);
goto P_0c09d2a0;
P_0c09d2a0: /* original 334c, guest PC 0x0c09d2a0 */
if(!s->budget--) { s->failed_pc=0x0c09d2a0u; return 0; }
r[3]+=r[4];
goto P_0c09d2a2;
P_0c09d2a2: /* original 335c, guest PC 0x0c09d2a2 */
if(!s->budget--) { s->failed_pc=0x0c09d2a2u; return 0; }
r[3]+=r[5];
goto P_0c09d2a4;
P_0c09d2a4: /* original f338, guest PC 0x0c09d2a4 */
if(!s->budget--) { s->failed_pc=0x0c09d2a4u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c09d2a6;
P_0c09d2a6: /* original f435, guest PC 0x0c09d2a6 */
if(!s->budget--) { s->failed_pc=0x0c09d2a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c09d2a8;
P_0c09d2a8: /* original 8b05, guest PC 0x0c09d2a8 */
if(!s->budget--) { s->failed_pc=0x0c09d2a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d2b6; }
goto P_0c09d2aa;
P_0c09d2aa: /* original 9236, guest PC 0x0c09d2aa */
if(!s->budget--) { s->failed_pc=0x0c09d2aau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d31au,2);
goto P_0c09d2ac;
P_0c09d2ac: /* original 324c, guest PC 0x0c09d2ac */
if(!s->budget--) { s->failed_pc=0x0c09d2acu; return 0; }
r[2]+=r[4];
goto P_0c09d2ae;
P_0c09d2ae: /* original 325c, guest PC 0x0c09d2ae */
if(!s->budget--) { s->failed_pc=0x0c09d2aeu; return 0; }
r[2]+=r[5];
goto P_0c09d2b0;
P_0c09d2b0: /* original f328, guest PC 0x0c09d2b0 */
if(!s->budget--) { s->failed_pc=0x0c09d2b0u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c09d2b2;
P_0c09d2b2: /* original f350, guest PC 0x0c09d2b2 */
if(!s->budget--) { s->failed_pc=0x0c09d2b2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c09d2b4;
P_0c09d2b4: /* original f23a, guest PC 0x0c09d2b4 */
if(!s->budget--) { s->failed_pc=0x0c09d2b4u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c09d2b6;
P_0c09d2b6: /* original 9330, guest PC 0x0c09d2b6 */
if(!s->budget--) { s->failed_pc=0x0c09d2b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d31au,2);
goto P_0c09d2b8;
P_0c09d2b8: /* original 334c, guest PC 0x0c09d2b8 */
if(!s->budget--) { s->failed_pc=0x0c09d2b8u; return 0; }
r[3]+=r[4];
goto P_0c09d2ba;
P_0c09d2ba: /* original 33ec, guest PC 0x0c09d2ba */
if(!s->budget--) { s->failed_pc=0x0c09d2bau; return 0; }
r[3]+=r[14];
goto P_0c09d2bc;
P_0c09d2bc: /* original f338, guest PC 0x0c09d2bc */
if(!s->budget--) { s->failed_pc=0x0c09d2bcu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c09d2be;
P_0c09d2be: /* original f435, guest PC 0x0c09d2be */
if(!s->budget--) { s->failed_pc=0x0c09d2beu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c09d2c0;
P_0c09d2c0: /* original 8b05, guest PC 0x0c09d2c0 */
if(!s->budget--) { s->failed_pc=0x0c09d2c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d2ce; }
goto P_0c09d2c2;
P_0c09d2c2: /* original 922a, guest PC 0x0c09d2c2 */
if(!s->budget--) { s->failed_pc=0x0c09d2c2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d31au,2);
goto P_0c09d2c4;
P_0c09d2c4: /* original 324c, guest PC 0x0c09d2c4 */
if(!s->budget--) { s->failed_pc=0x0c09d2c4u; return 0; }
r[2]+=r[4];
goto P_0c09d2c6;
P_0c09d2c6: /* original 32ec, guest PC 0x0c09d2c6 */
if(!s->budget--) { s->failed_pc=0x0c09d2c6u; return 0; }
r[2]+=r[14];
goto P_0c09d2c8;
P_0c09d2c8: /* original f328, guest PC 0x0c09d2c8 */
if(!s->budget--) { s->failed_pc=0x0c09d2c8u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c09d2ca;
P_0c09d2ca: /* original f350, guest PC 0x0c09d2ca */
if(!s->budget--) { s->failed_pc=0x0c09d2cau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c09d2cc;
P_0c09d2cc: /* original f23a, guest PC 0x0c09d2cc */
if(!s->budget--) { s->failed_pc=0x0c09d2ccu; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c09d2ce;
P_0c09d2ce: /* original 9325, guest PC 0x0c09d2ce */
if(!s->budget--) { s->failed_pc=0x0c09d2ceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d31cu,2);
goto P_0c09d2d0;
P_0c09d2d0: /* original 334c, guest PC 0x0c09d2d0 */
if(!s->budget--) { s->failed_pc=0x0c09d2d0u; return 0; }
r[3]+=r[4];
goto P_0c09d2d2;
P_0c09d2d2: /* original 335c, guest PC 0x0c09d2d2 */
if(!s->budget--) { s->failed_pc=0x0c09d2d2u; return 0; }
r[3]+=r[5];
goto P_0c09d2d4;
P_0c09d2d4: /* original f338, guest PC 0x0c09d2d4 */
if(!s->budget--) { s->failed_pc=0x0c09d2d4u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c09d2d6;
P_0c09d2d6: /* original f435, guest PC 0x0c09d2d6 */
if(!s->budget--) { s->failed_pc=0x0c09d2d6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c09d2d8;
P_0c09d2d8: /* original 8b05, guest PC 0x0c09d2d8 */
if(!s->budget--) { s->failed_pc=0x0c09d2d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d2e6; }
goto P_0c09d2da;
P_0c09d2da: /* original 921f, guest PC 0x0c09d2da */
if(!s->budget--) { s->failed_pc=0x0c09d2dau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d31cu,2);
goto P_0c09d2dc;
P_0c09d2dc: /* original 324c, guest PC 0x0c09d2dc */
if(!s->budget--) { s->failed_pc=0x0c09d2dcu; return 0; }
r[2]+=r[4];
goto P_0c09d2de;
P_0c09d2de: /* original 325c, guest PC 0x0c09d2de */
if(!s->budget--) { s->failed_pc=0x0c09d2deu; return 0; }
r[2]+=r[5];
goto P_0c09d2e0;
P_0c09d2e0: /* original f328, guest PC 0x0c09d2e0 */
if(!s->budget--) { s->failed_pc=0x0c09d2e0u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c09d2e2;
P_0c09d2e2: /* original f350, guest PC 0x0c09d2e2 */
if(!s->budget--) { s->failed_pc=0x0c09d2e2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c09d2e4;
P_0c09d2e4: /* original f23a, guest PC 0x0c09d2e4 */
if(!s->budget--) { s->failed_pc=0x0c09d2e4u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c09d2e6;
P_0c09d2e6: /* original 931a, guest PC 0x0c09d2e6 */
if(!s->budget--) { s->failed_pc=0x0c09d2e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d31eu,2);
goto P_0c09d2e8;
P_0c09d2e8: /* original 334c, guest PC 0x0c09d2e8 */
if(!s->budget--) { s->failed_pc=0x0c09d2e8u; return 0; }
r[3]+=r[4];
goto P_0c09d2ea;
P_0c09d2ea: /* original 335c, guest PC 0x0c09d2ea */
if(!s->budget--) { s->failed_pc=0x0c09d2eau; return 0; }
r[3]+=r[5];
goto P_0c09d2ec;
P_0c09d2ec: /* original f338, guest PC 0x0c09d2ec */
if(!s->budget--) { s->failed_pc=0x0c09d2ecu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c09d2ee;
P_0c09d2ee: /* original f435, guest PC 0x0c09d2ee */
if(!s->budget--) { s->failed_pc=0x0c09d2eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c09d2f0;
P_0c09d2f0: /* original 8f07, guest PC 0x0c09d2f0 */
if(!s->budget--) { s->failed_pc=0x0c09d2f0u; return 0; }
cond=r[17]&1u;
r[0]=0x00000018u;
if(!cond) { goto P_0c09d302; }
goto P_0c09d2f4;
P_0c09d2f2: /* original e018, guest PC 0x0c09d2f2 */
if(!s->budget--) { s->failed_pc=0x0c09d2f2u; return 0; }
r[0]=0x00000018u;
goto P_0c09d2f4;
P_0c09d2f4: /* original 9213, guest PC 0x0c09d2f4 */
if(!s->budget--) { s->failed_pc=0x0c09d2f4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d31eu,2);
goto P_0c09d2f6;
P_0c09d2f6: /* original f29d, guest PC 0x0c09d2f6 */
if(!s->budget--) { s->failed_pc=0x0c09d2f6u; return 0; }
fr[2]=0x3f800000u;
goto P_0c09d2f8;
P_0c09d2f8: /* original 324c, guest PC 0x0c09d2f8 */
if(!s->budget--) { s->failed_pc=0x0c09d2f8u; return 0; }
r[2]+=r[4];
goto P_0c09d2fa;
P_0c09d2fa: /* original 32ec, guest PC 0x0c09d2fa */
if(!s->budget--) { s->failed_pc=0x0c09d2fau; return 0; }
r[2]+=r[14];
goto P_0c09d2fc;
P_0c09d2fc: /* original f328, guest PC 0x0c09d2fc */
if(!s->budget--) { s->failed_pc=0x0c09d2fcu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c09d2fe;
P_0c09d2fe: /* original f320, guest PC 0x0c09d2fe */
if(!s->budget--) { s->failed_pc=0x0c09d2feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c09d300;
P_0c09d300: /* original f23a, guest PC 0x0c09d300 */
if(!s->budget--) { s->failed_pc=0x0c09d300u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c09d302;
P_0c09d302: /* original 006c, guest PC 0x0c09d302 */
if(!s->budget--) { s->failed_pc=0x0c09d302u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c09d304;
P_0c09d304: /* original 600c, guest PC 0x0c09d304 */
if(!s->budget--) { s->failed_pc=0x0c09d304u; return 0; }
r[0]=r[0]&255u;
goto P_0c09d306;
P_0c09d306: /* original 8800, guest PC 0x0c09d306 */
if(!s->budget--) { s->failed_pc=0x0c09d306u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09d308;
P_0c09d308: /* original 8910, guest PC 0x0c09d308 */
if(!s->budget--) { s->failed_pc=0x0c09d308u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d32c; }
goto P_0c09d30a;
P_0c09d30a: /* original 8801, guest PC 0x0c09d30a */
if(!s->budget--) { s->failed_pc=0x0c09d30au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09d30c;
P_0c09d30c: /* original 891b, guest PC 0x0c09d30c */
if(!s->budget--) { s->failed_pc=0x0c09d30cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d346; }
goto P_0c09d30e;
P_0c09d30e: /* original 8802, guest PC 0x0c09d30e */
if(!s->budget--) { s->failed_pc=0x0c09d30eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09d310;
P_0c09d310: /* original 8926, guest PC 0x0c09d310 */
if(!s->budget--) { s->failed_pc=0x0c09d310u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d360; }
goto P_0c09d312;
P_0c09d312: /* original a031, guest PC 0x0c09d312 */
if(!s->budget--) { s->failed_pc=0x0c09d312u; return 0; }
goto P_0c09d378;
P_0c09d314: /* original 0009, guest PC 0x0c09d314 */
if(!s->budget--) { s->failed_pc=0x0c09d314u; return 0; }
if(!vf3_matrix_family(0x0c09d316u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d316u; return 0; } return 1;
P_0c09d32c: /* original 935b, guest PC 0x0c09d32c */
if(!s->budget--) { s->failed_pc=0x0c09d32cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d3e6u,2);
goto P_0c09d32e;
P_0c09d32e: /* original 334c, guest PC 0x0c09d32e */
if(!s->budget--) { s->failed_pc=0x0c09d32eu; return 0; }
r[3]+=r[4];
goto P_0c09d330;
P_0c09d330: /* original 335c, guest PC 0x0c09d330 */
if(!s->budget--) { s->failed_pc=0x0c09d330u; return 0; }
r[3]+=r[5];
goto P_0c09d332;
P_0c09d332: /* original 6232, guest PC 0x0c09d332 */
if(!s->budget--) { s->failed_pc=0x0c09d332u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09d334;
P_0c09d334: /* original 32a2, guest PC 0x0c09d334 */
if(!s->budget--) { s->failed_pc=0x0c09d334u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[10])!=0);
goto P_0c09d336;
P_0c09d336: /* original 891f, guest PC 0x0c09d336 */
if(!s->budget--) { s->failed_pc=0x0c09d336u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d378; }
goto P_0c09d338;
P_0c09d338: /* original 9155, guest PC 0x0c09d338 */
if(!s->budget--) { s->failed_pc=0x0c09d338u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d3e6u,2);
goto P_0c09d33a;
P_0c09d33a: /* original 314c, guest PC 0x0c09d33a */
if(!s->budget--) { s->failed_pc=0x0c09d33au; return 0; }
r[1]+=r[4];
goto P_0c09d33c;
P_0c09d33c: /* original 351c, guest PC 0x0c09d33c */
if(!s->budget--) { s->failed_pc=0x0c09d33cu; return 0; }
r[5]+=r[1];
goto P_0c09d33e;
P_0c09d33e: /* original 6352, guest PC 0x0c09d33e */
if(!s->budget--) { s->failed_pc=0x0c09d33eu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c09d340;
P_0c09d340: /* original 7301, guest PC 0x0c09d340 */
if(!s->budget--) { s->failed_pc=0x0c09d340u; return 0; }
r[3]+=0x00000001u;
goto P_0c09d342;
P_0c09d342: /* original a019, guest PC 0x0c09d342 */
if(!s->budget--) { s->failed_pc=0x0c09d342u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c09d378;
P_0c09d344: /* original 2532, guest PC 0x0c09d344 */
if(!s->budget--) { s->failed_pc=0x0c09d344u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c09d346;
P_0c09d346: /* original 914f, guest PC 0x0c09d346 */
if(!s->budget--) { s->failed_pc=0x0c09d346u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d3e8u,2);
goto P_0c09d348;
P_0c09d348: /* original 314c, guest PC 0x0c09d348 */
if(!s->budget--) { s->failed_pc=0x0c09d348u; return 0; }
r[1]+=r[4];
goto P_0c09d34a;
P_0c09d34a: /* original 315c, guest PC 0x0c09d34a */
if(!s->budget--) { s->failed_pc=0x0c09d34au; return 0; }
r[1]+=r[5];
goto P_0c09d34c;
P_0c09d34c: /* original 6312, guest PC 0x0c09d34c */
if(!s->budget--) { s->failed_pc=0x0c09d34cu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c09d34e;
P_0c09d34e: /* original 33a2, guest PC 0x0c09d34e */
if(!s->budget--) { s->failed_pc=0x0c09d34eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[10])!=0);
goto P_0c09d350;
P_0c09d350: /* original 8912, guest PC 0x0c09d350 */
if(!s->budget--) { s->failed_pc=0x0c09d350u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d378; }
goto P_0c09d352;
P_0c09d352: /* original 9149, guest PC 0x0c09d352 */
if(!s->budget--) { s->failed_pc=0x0c09d352u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d3e8u,2);
goto P_0c09d354;
P_0c09d354: /* original 314c, guest PC 0x0c09d354 */
if(!s->budget--) { s->failed_pc=0x0c09d354u; return 0; }
r[1]+=r[4];
goto P_0c09d356;
P_0c09d356: /* original 351c, guest PC 0x0c09d356 */
if(!s->budget--) { s->failed_pc=0x0c09d356u; return 0; }
r[5]+=r[1];
goto P_0c09d358;
P_0c09d358: /* original 6352, guest PC 0x0c09d358 */
if(!s->budget--) { s->failed_pc=0x0c09d358u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c09d35a;
P_0c09d35a: /* original 7301, guest PC 0x0c09d35a */
if(!s->budget--) { s->failed_pc=0x0c09d35au; return 0; }
r[3]+=0x00000001u;
goto P_0c09d35c;
P_0c09d35c: /* original a00c, guest PC 0x0c09d35c */
if(!s->budget--) { s->failed_pc=0x0c09d35cu; return 0; }
write(ram,r[5],r[3],4);
goto P_0c09d378;
P_0c09d35e: /* original 2532, guest PC 0x0c09d35e */
if(!s->budget--) { s->failed_pc=0x0c09d35eu; return 0; }
write(ram,r[5],r[3],4);
goto P_0c09d360;
P_0c09d360: /* original 9143, guest PC 0x0c09d360 */
if(!s->budget--) { s->failed_pc=0x0c09d360u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d3eau,2);
goto P_0c09d362;
P_0c09d362: /* original 314c, guest PC 0x0c09d362 */
if(!s->budget--) { s->failed_pc=0x0c09d362u; return 0; }
r[1]+=r[4];
goto P_0c09d364;
P_0c09d364: /* original 315c, guest PC 0x0c09d364 */
if(!s->budget--) { s->failed_pc=0x0c09d364u; return 0; }
r[1]+=r[5];
goto P_0c09d366;
P_0c09d366: /* original 6312, guest PC 0x0c09d366 */
if(!s->budget--) { s->failed_pc=0x0c09d366u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c09d368;
P_0c09d368: /* original 33a2, guest PC 0x0c09d368 */
if(!s->budget--) { s->failed_pc=0x0c09d368u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[10])!=0);
goto P_0c09d36a;
P_0c09d36a: /* original 8905, guest PC 0x0c09d36a */
if(!s->budget--) { s->failed_pc=0x0c09d36au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d378; }
goto P_0c09d36c;
P_0c09d36c: /* original 913d, guest PC 0x0c09d36c */
if(!s->budget--) { s->failed_pc=0x0c09d36cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d3eau,2);
goto P_0c09d36e;
P_0c09d36e: /* original 314c, guest PC 0x0c09d36e */
if(!s->budget--) { s->failed_pc=0x0c09d36eu; return 0; }
r[1]+=r[4];
goto P_0c09d370;
P_0c09d370: /* original 351c, guest PC 0x0c09d370 */
if(!s->budget--) { s->failed_pc=0x0c09d370u; return 0; }
r[5]+=r[1];
goto P_0c09d372;
P_0c09d372: /* original 6352, guest PC 0x0c09d372 */
if(!s->budget--) { s->failed_pc=0x0c09d372u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c09d374;
P_0c09d374: /* original 7301, guest PC 0x0c09d374 */
if(!s->budget--) { s->failed_pc=0x0c09d374u; return 0; }
r[3]+=0x00000001u;
goto P_0c09d376;
P_0c09d376: /* original 2532, guest PC 0x0c09d376 */
if(!s->budget--) { s->failed_pc=0x0c09d376u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c09d378;
P_0c09d378: /* original d21d, guest PC 0x0c09d378 */
if(!s->budget--) { s->failed_pc=0x0c09d378u; return 0; }
r[2]=read(ram,0x0c09d3f0u,4);
goto P_0c09d37a;
P_0c09d37a: /* original 22d2, guest PC 0x0c09d37a */
if(!s->budget--) { s->failed_pc=0x0c09d37au; return 0; }
write(ram,r[2],r[13],4);
goto P_0c09d37c;
P_0c09d37c: /* original 7f08, guest PC 0x0c09d37c */
if(!s->budget--) { s->failed_pc=0x0c09d37cu; return 0; }
r[15]+=0x00000008u;
goto P_0c09d37e;
P_0c09d37e: /* original 4f16, guest PC 0x0c09d37e */
if(!s->budget--) { s->failed_pc=0x0c09d37eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d380;
P_0c09d380: /* original 69f6, guest PC 0x0c09d380 */
if(!s->budget--) { s->failed_pc=0x0c09d380u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09d382;
P_0c09d382: /* original 6af6, guest PC 0x0c09d382 */
if(!s->budget--) { s->failed_pc=0x0c09d382u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09d384;
P_0c09d384: /* original 6bf6, guest PC 0x0c09d384 */
if(!s->budget--) { s->failed_pc=0x0c09d384u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09d386;
P_0c09d386: /* original 6cf6, guest PC 0x0c09d386 */
if(!s->budget--) { s->failed_pc=0x0c09d386u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09d388;
P_0c09d388: /* original 6df6, guest PC 0x0c09d388 */
if(!s->budget--) { s->failed_pc=0x0c09d388u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d38a;
P_0c09d38a: /* original 000b, guest PC 0x0c09d38a */
if(!s->budget--) { s->failed_pc=0x0c09d38au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d38c: /* original 6ef6, guest PC 0x0c09d38c */
if(!s->budget--) { s->failed_pc=0x0c09d38cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09d38eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d38eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
