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
int vf3_away_batch141_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ad01cu: goto P_0c0ad01c;
case 0x0c0ad01eu: goto P_0c0ad01e;
case 0x0c0ad020u: goto P_0c0ad020;
case 0x0c0ad022u: goto P_0c0ad022;
case 0x0c0ad024u: goto P_0c0ad024;
case 0x0c0ad026u: goto P_0c0ad026;
case 0x0c0ad028u: goto P_0c0ad028;
case 0x0c0ad02au: goto P_0c0ad02a;
case 0x0c0ad02cu: goto P_0c0ad02c;
case 0x0c0ad02eu: goto P_0c0ad02e;
case 0x0c0ad030u: goto P_0c0ad030;
case 0x0c0ad032u: goto P_0c0ad032;
case 0x0c0ad034u: goto P_0c0ad034;
case 0x0c0ad036u: goto P_0c0ad036;
case 0x0c0ad038u: goto P_0c0ad038;
case 0x0c0ad03au: goto P_0c0ad03a;
case 0x0c0ad03cu: goto P_0c0ad03c;
case 0x0c0ad03eu: goto P_0c0ad03e;
case 0x0c0ad040u: goto P_0c0ad040;
case 0x0c0ad042u: goto P_0c0ad042;
case 0x0c0ad044u: goto P_0c0ad044;
case 0x0c0ad046u: goto P_0c0ad046;
case 0x0c0ad048u: goto P_0c0ad048;
case 0x0c0ad04au: goto P_0c0ad04a;
case 0x0c0ad04cu: goto P_0c0ad04c;
case 0x0c0ad04eu: goto P_0c0ad04e;
case 0x0c0ad050u: goto P_0c0ad050;
case 0x0c0ad052u: goto P_0c0ad052;
case 0x0c0ad054u: goto P_0c0ad054;
case 0x0c0ad056u: goto P_0c0ad056;
case 0x0c0ad058u: goto P_0c0ad058;
case 0x0c0ad05au: goto P_0c0ad05a;
case 0x0c0ad05cu: goto P_0c0ad05c;
case 0x0c0ad05eu: goto P_0c0ad05e;
case 0x0c0ad060u: goto P_0c0ad060;
case 0x0c0ad062u: goto P_0c0ad062;
case 0x0c0ad064u: goto P_0c0ad064;
case 0x0c0ad066u: goto P_0c0ad066;
case 0x0c0ad068u: goto P_0c0ad068;
case 0x0c0ad06au: goto P_0c0ad06a;
case 0x0c0ad06cu: goto P_0c0ad06c;
case 0x0c0ad06eu: goto P_0c0ad06e;
case 0x0c0ad070u: goto P_0c0ad070;
case 0x0c0ad072u: goto P_0c0ad072;
case 0x0c0ad074u: goto P_0c0ad074;
case 0x0c0ad076u: goto P_0c0ad076;
case 0x0c0ad078u: goto P_0c0ad078;
case 0x0c0ad07au: goto P_0c0ad07a;
case 0x0c0ad07cu: goto P_0c0ad07c;
case 0x0c0ad07eu: goto P_0c0ad07e;
case 0x0c0ad080u: goto P_0c0ad080;
case 0x0c0ad082u: goto P_0c0ad082;
case 0x0c0ad084u: goto P_0c0ad084;
case 0x0c0ad086u: goto P_0c0ad086;
case 0x0c0ad088u: goto P_0c0ad088;
case 0x0c0ad08au: goto P_0c0ad08a;
case 0x0c0ad08cu: goto P_0c0ad08c;
case 0x0c0ad08eu: goto P_0c0ad08e;
case 0x0c0ad090u: goto P_0c0ad090;
case 0x0c0ad092u: goto P_0c0ad092;
case 0x0c0ad094u: goto P_0c0ad094;
case 0x0c0ad096u: goto P_0c0ad096;
case 0x0c0ad098u: goto P_0c0ad098;
case 0x0c0ad09au: goto P_0c0ad09a;
case 0x0c0ad09cu: goto P_0c0ad09c;
case 0x0c0ad09eu: goto P_0c0ad09e;
case 0x0c0ad0a0u: goto P_0c0ad0a0;
case 0x0c0ad0a2u: goto P_0c0ad0a2;
case 0x0c0ad0a4u: goto P_0c0ad0a4;
case 0x0c0ad0a6u: goto P_0c0ad0a6;
case 0x0c0ad0a8u: goto P_0c0ad0a8;
case 0x0c0ad0aau: goto P_0c0ad0aa;
case 0x0c0ad0acu: goto P_0c0ad0ac;
case 0x0c0ad0aeu: goto P_0c0ad0ae;
case 0x0c0ad0b0u: goto P_0c0ad0b0;
case 0x0c0ad0b2u: goto P_0c0ad0b2;
case 0x0c0ad0b4u: goto P_0c0ad0b4;
case 0x0c0ad0b6u: goto P_0c0ad0b6;
case 0x0c0ad0b8u: goto P_0c0ad0b8;
case 0x0c0ad0bau: goto P_0c0ad0ba;
case 0x0c0ad0bcu: goto P_0c0ad0bc;
case 0x0c0ad0beu: goto P_0c0ad0be;
case 0x0c0ad0c0u: goto P_0c0ad0c0;
case 0x0c0ad0c2u: goto P_0c0ad0c2;
case 0x0c0ad0c4u: goto P_0c0ad0c4;
case 0x0c0ad0c6u: goto P_0c0ad0c6;
case 0x0c0ad0c8u: goto P_0c0ad0c8;
case 0x0c0ad0cau: goto P_0c0ad0ca;
case 0x0c0ad0ccu: goto P_0c0ad0cc;
case 0x0c0ad0ceu: goto P_0c0ad0ce;
case 0x0c0ad0d0u: goto P_0c0ad0d0;
case 0x0c0ad0d2u: goto P_0c0ad0d2;
case 0x0c0ad0d4u: goto P_0c0ad0d4;
case 0x0c0ad0d6u: goto P_0c0ad0d6;
case 0x0c0ad0d8u: goto P_0c0ad0d8;
case 0x0c0ad106u: goto P_0c0ad106;
case 0x0c0ad108u: goto P_0c0ad108;
case 0x0c0ad10au: goto P_0c0ad10a;
case 0x0c0ad10cu: goto P_0c0ad10c;
case 0x0c0ad10eu: goto P_0c0ad10e;
case 0x0c0ad110u: goto P_0c0ad110;
case 0x0c0ad178u: goto P_0c0ad178;
case 0x0c0ad17au: goto P_0c0ad17a;
case 0x0c0ad17cu: goto P_0c0ad17c;
case 0x0c0ad17eu: goto P_0c0ad17e;
case 0x0c0ad180u: goto P_0c0ad180;
case 0x0c0ad182u: goto P_0c0ad182;
case 0x0c0ad184u: goto P_0c0ad184;
case 0x0c0ad186u: goto P_0c0ad186;
case 0x0c0ad188u: goto P_0c0ad188;
case 0x0c0ad18au: goto P_0c0ad18a;
case 0x0c0ad18cu: goto P_0c0ad18c;
case 0x0c0ad18eu: goto P_0c0ad18e;
case 0x0c0ad190u: goto P_0c0ad190;
case 0x0c0ad192u: goto P_0c0ad192;
case 0x0c0ad194u: goto P_0c0ad194;
case 0x0c0ad196u: goto P_0c0ad196;
case 0x0c0ad198u: goto P_0c0ad198;
case 0x0c0ad19au: goto P_0c0ad19a;
case 0x0c0ad19cu: goto P_0c0ad19c;
case 0x0c0ad19eu: goto P_0c0ad19e;
case 0x0c0ad1a0u: goto P_0c0ad1a0;
case 0x0c0ad1a2u: goto P_0c0ad1a2;
case 0x0c0ad1a4u: goto P_0c0ad1a4;
case 0x0c0ad1a6u: goto P_0c0ad1a6;
case 0x0c0ad1a8u: goto P_0c0ad1a8;
case 0x0c0ad1aau: goto P_0c0ad1aa;
case 0x0c0ad1acu: goto P_0c0ad1ac;
case 0x0c0ad1aeu: goto P_0c0ad1ae;
case 0x0c0ad1b0u: goto P_0c0ad1b0;
case 0x0c0ad1b2u: goto P_0c0ad1b2;
case 0x0c0ad1b4u: goto P_0c0ad1b4;
case 0x0c0ad1b6u: goto P_0c0ad1b6;
case 0x0c0ad1b8u: goto P_0c0ad1b8;
case 0x0c0ad1bau: goto P_0c0ad1ba;
case 0x0c0ad1bcu: goto P_0c0ad1bc;
case 0x0c0ad1beu: goto P_0c0ad1be;
case 0x0c0ad1c0u: goto P_0c0ad1c0;
case 0x0c0ad1c2u: goto P_0c0ad1c2;
case 0x0c0ad1c4u: goto P_0c0ad1c4;
case 0x0c0ad1c6u: goto P_0c0ad1c6;
case 0x0c0ad1c8u: goto P_0c0ad1c8;
case 0x0c0ad1cau: goto P_0c0ad1ca;
case 0x0c0ad1ccu: goto P_0c0ad1cc;
case 0x0c0ad1ceu: goto P_0c0ad1ce;
case 0x0c0ad1d0u: goto P_0c0ad1d0;
case 0x0c0ad1d2u: goto P_0c0ad1d2;
case 0x0c0ad1d4u: goto P_0c0ad1d4;
case 0x0c0ad1d6u: goto P_0c0ad1d6;
case 0x0c0ad1d8u: goto P_0c0ad1d8;
case 0x0c0ad1dau: goto P_0c0ad1da;
case 0x0c0ad1dcu: goto P_0c0ad1dc;
case 0x0c0ad1deu: goto P_0c0ad1de;
case 0x0c0ad1e0u: goto P_0c0ad1e0;
case 0x0c0ad1e2u: goto P_0c0ad1e2;
case 0x0c0ad1e4u: goto P_0c0ad1e4;
case 0x0c0ad1e6u: goto P_0c0ad1e6;
case 0x0c0ad1e8u: goto P_0c0ad1e8;
case 0x0c0ad1eau: goto P_0c0ad1ea;
case 0x0c0ad1ecu: goto P_0c0ad1ec;
case 0x0c0ad1eeu: goto P_0c0ad1ee;
case 0x0c0ad1f0u: goto P_0c0ad1f0;
case 0x0c0ad1f2u: goto P_0c0ad1f2;
case 0x0c0ad1f4u: goto P_0c0ad1f4;
case 0x0c0ad1f6u: goto P_0c0ad1f6;
case 0x0c0ad1f8u: goto P_0c0ad1f8;
case 0x0c0ad1fau: goto P_0c0ad1fa;
case 0x0c0ad1fcu: goto P_0c0ad1fc;
case 0x0c0ad1feu: goto P_0c0ad1fe;
case 0x0c0ad200u: goto P_0c0ad200;
case 0x0c0ad202u: goto P_0c0ad202;
case 0x0c0ad204u: goto P_0c0ad204;
case 0x0c0ad206u: goto P_0c0ad206;
case 0x0c0ad208u: goto P_0c0ad208;
case 0x0c0ad20au: goto P_0c0ad20a;
case 0x0c0ad20cu: goto P_0c0ad20c;
case 0x0c0ad20eu: goto P_0c0ad20e;
case 0x0c0ad210u: goto P_0c0ad210;
case 0x0c0ad212u: goto P_0c0ad212;
case 0x0c0ad214u: goto P_0c0ad214;
case 0x0c0ad216u: goto P_0c0ad216;
case 0x0c0ad218u: goto P_0c0ad218;
case 0x0c0ad21au: goto P_0c0ad21a;
case 0x0c0ad21cu: goto P_0c0ad21c;
case 0x0c0ad21eu: goto P_0c0ad21e;
case 0x0c0ad220u: goto P_0c0ad220;
case 0x0c0ad222u: goto P_0c0ad222;
case 0x0c0ad224u: goto P_0c0ad224;
case 0x0c0ad226u: goto P_0c0ad226;
case 0x0c0ad228u: goto P_0c0ad228;
case 0x0c0ad22au: goto P_0c0ad22a;
case 0x0c0ad22cu: goto P_0c0ad22c;
case 0x0c0ad22eu: goto P_0c0ad22e;
case 0x0c0ad230u: goto P_0c0ad230;
case 0x0c0ad232u: goto P_0c0ad232;
case 0x0c0ad234u: goto P_0c0ad234;
case 0x0c0ad236u: goto P_0c0ad236;
case 0x0c0ad238u: goto P_0c0ad238;
case 0x0c0ad26cu: goto P_0c0ad26c;
case 0x0c0ad26eu: goto P_0c0ad26e;
case 0x0c0ad270u: goto P_0c0ad270;
case 0x0c0ad272u: goto P_0c0ad272;
case 0x0c0ad274u: goto P_0c0ad274;
case 0x0c0ad276u: goto P_0c0ad276;
case 0x0c0ad278u: goto P_0c0ad278;
case 0x0c0ad27au: goto P_0c0ad27a;
case 0x0c0ad27cu: goto P_0c0ad27c;
case 0x0c0ad27eu: goto P_0c0ad27e;
case 0x0c0ad280u: goto P_0c0ad280;
case 0x0c0ad282u: goto P_0c0ad282;
case 0x0c0ad284u: goto P_0c0ad284;
case 0x0c0ad286u: goto P_0c0ad286;
case 0x0c0ad288u: goto P_0c0ad288;
case 0x0c0ad28au: goto P_0c0ad28a;
case 0x0c0ad28cu: goto P_0c0ad28c;
case 0x0c0ad28eu: goto P_0c0ad28e;
case 0x0c0ad290u: goto P_0c0ad290;
case 0x0c0ad292u: goto P_0c0ad292;
case 0x0c0ad294u: goto P_0c0ad294;
case 0x0c0ad296u: goto P_0c0ad296;
case 0x0c0ad298u: goto P_0c0ad298;
case 0x0c0ad29au: goto P_0c0ad29a;
case 0x0c0ad29cu: goto P_0c0ad29c;
case 0x0c0ad29eu: goto P_0c0ad29e;
case 0x0c0ad2a0u: goto P_0c0ad2a0;
case 0x0c0ad2a2u: goto P_0c0ad2a2;
case 0x0c0ad2a4u: goto P_0c0ad2a4;
case 0x0c0ad2a6u: goto P_0c0ad2a6;
case 0x0c0ad2a8u: goto P_0c0ad2a8;
case 0x0c0ad2aau: goto P_0c0ad2aa;
case 0x0c0ad2acu: goto P_0c0ad2ac;
case 0x0c0ad2aeu: goto P_0c0ad2ae;
case 0x0c0ad2b0u: goto P_0c0ad2b0;
case 0x0c0ad2b2u: goto P_0c0ad2b2;
case 0x0c0ad2b4u: goto P_0c0ad2b4;
case 0x0c0ad2b6u: goto P_0c0ad2b6;
case 0x0c0ad2b8u: goto P_0c0ad2b8;
case 0x0c0ad2bau: goto P_0c0ad2ba;
case 0x0c0ad2bcu: goto P_0c0ad2bc;
case 0x0c0ad2beu: goto P_0c0ad2be;
case 0x0c0ad2c0u: goto P_0c0ad2c0;
case 0x0c0ad2c2u: goto P_0c0ad2c2;
case 0x0c0ad2c4u: goto P_0c0ad2c4;
case 0x0c0ad2c6u: goto P_0c0ad2c6;
case 0x0c0ad2c8u: goto P_0c0ad2c8;
case 0x0c0ad2cau: goto P_0c0ad2ca;
case 0x0c0ad2ccu: goto P_0c0ad2cc;
case 0x0c0ad2ceu: goto P_0c0ad2ce;
case 0x0c0ad2d0u: goto P_0c0ad2d0;
case 0x0c0ad2d2u: goto P_0c0ad2d2;
case 0x0c0ad2d4u: goto P_0c0ad2d4;
case 0x0c0ad2d6u: goto P_0c0ad2d6;
case 0x0c0ad2d8u: goto P_0c0ad2d8;
case 0x0c0ad2dau: goto P_0c0ad2da;
case 0x0c0ad2dcu: goto P_0c0ad2dc;
case 0x0c0ad2deu: goto P_0c0ad2de;
case 0x0c0ad2e0u: goto P_0c0ad2e0;
case 0x0c0ad2e2u: goto P_0c0ad2e2;
case 0x0c0ad2e4u: goto P_0c0ad2e4;
case 0x0c0ad2e6u: goto P_0c0ad2e6;
case 0x0c0ad2e8u: goto P_0c0ad2e8;
case 0x0c0ad2eau: goto P_0c0ad2ea;
case 0x0c0ad2ecu: goto P_0c0ad2ec;
case 0x0c0ad2eeu: goto P_0c0ad2ee;
case 0x0c0ad2f0u: goto P_0c0ad2f0;
case 0x0c0ad2f2u: goto P_0c0ad2f2;
case 0x0c0ad2f4u: goto P_0c0ad2f4;
case 0x0c0ad2f6u: goto P_0c0ad2f6;
case 0x0c0ad2f8u: goto P_0c0ad2f8;
case 0x0c0ad2fau: goto P_0c0ad2fa;
case 0x0c0ad2fcu: goto P_0c0ad2fc;
case 0x0c0ad2feu: goto P_0c0ad2fe;
case 0x0c0ad300u: goto P_0c0ad300;
case 0x0c0ad302u: goto P_0c0ad302;
case 0x0c0ad304u: goto P_0c0ad304;
case 0x0c0ad306u: goto P_0c0ad306;
case 0x0c0ad308u: goto P_0c0ad308;
case 0x0c0ad30au: goto P_0c0ad30a;
case 0x0c0ad30cu: goto P_0c0ad30c;
case 0x0c0ad30eu: goto P_0c0ad30e;
case 0x0c0ad310u: goto P_0c0ad310;
case 0x0c0ad312u: goto P_0c0ad312;
case 0x0c0ad314u: goto P_0c0ad314;
case 0x0c0ad316u: goto P_0c0ad316;
case 0x0c0ad318u: goto P_0c0ad318;
case 0x0c0ad31au: goto P_0c0ad31a;
case 0x0c0ad31cu: goto P_0c0ad31c;
case 0x0c0ad31eu: goto P_0c0ad31e;
case 0x0c0ad320u: goto P_0c0ad320;
case 0x0c0ad322u: goto P_0c0ad322;
case 0x0c0ad324u: goto P_0c0ad324;
case 0x0c0ad326u: goto P_0c0ad326;
case 0x0c0ad328u: goto P_0c0ad328;
case 0x0c0ad32au: goto P_0c0ad32a;
case 0x0c0ad32cu: goto P_0c0ad32c;
case 0x0c0ad32eu: goto P_0c0ad32e;
case 0x0c0ad330u: goto P_0c0ad330;
case 0x0c0ad332u: goto P_0c0ad332;
case 0x0c0ad334u: goto P_0c0ad334;
case 0x0c0ad336u: goto P_0c0ad336;
case 0x0c0ad338u: goto P_0c0ad338;
case 0x0c0ad33au: goto P_0c0ad33a;
case 0x0c0ad33cu: goto P_0c0ad33c;
case 0x0c0ad33eu: goto P_0c0ad33e;
case 0x0c0ad340u: goto P_0c0ad340;
case 0x0c0ad342u: goto P_0c0ad342;
case 0x0c0ad344u: goto P_0c0ad344;
case 0x0c0ad346u: goto P_0c0ad346;
case 0x0c0ad348u: goto P_0c0ad348;
case 0x0c0ad34au: goto P_0c0ad34a;
case 0x0c0ad34cu: goto P_0c0ad34c;
case 0x0c0ad34eu: goto P_0c0ad34e;
case 0x0c0ad350u: goto P_0c0ad350;
case 0x0c0ad352u: goto P_0c0ad352;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ad01c: /* original 2fe6, guest PC 0x0c0ad01c */
if(!s->budget--) { s->failed_pc=0x0c0ad01cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad01e;
P_0c0ad01e: /* original 6e43, guest PC 0x0c0ad01e */
if(!s->budget--) { s->failed_pc=0x0c0ad01eu; return 0; }
r[14]=r[4];
goto P_0c0ad020;
P_0c0ad020: /* original 2fd6, guest PC 0x0c0ad020 */
if(!s->budget--) { s->failed_pc=0x0c0ad020u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad022;
P_0c0ad022: /* original 2fc6, guest PC 0x0c0ad022 */
if(!s->budget--) { s->failed_pc=0x0c0ad022u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad024;
P_0c0ad024: /* original 6c53, guest PC 0x0c0ad024 */
if(!s->budget--) { s->failed_pc=0x0c0ad024u; return 0; }
r[12]=r[5];
goto P_0c0ad026;
P_0c0ad026: /* original 4f22, guest PC 0x0c0ad026 */
if(!s->budget--) { s->failed_pc=0x0c0ad026u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ad028;
P_0c0ad028: /* original 7ffc, guest PC 0x0c0ad028 */
if(!s->budget--) { s->failed_pc=0x0c0ad028u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad02a;
P_0c0ad02a: /* original 2f62, guest PC 0x0c0ad02a */
if(!s->budget--) { s->failed_pc=0x0c0ad02au; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0ad02c;
P_0c0ad02c: /* original 9080, guest PC 0x0c0ad02c */
if(!s->budget--) { s->failed_pc=0x0c0ad02cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad130u,2);
goto P_0c0ad02e;
P_0c0ad02e: /* original 04ec, guest PC 0x0c0ad02e */
if(!s->budget--) { s->failed_pc=0x0c0ad02eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ad030;
P_0c0ad030: /* original e03e, guest PC 0x0c0ad030 */
if(!s->budget--) { s->failed_pc=0x0c0ad030u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ad032;
P_0c0ad032: /* original 05ed, guest PC 0x0c0ad032 */
if(!s->budget--) { s->failed_pc=0x0c0ad032u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad034;
P_0c0ad034: /* original 644c, guest PC 0x0c0ad034 */
if(!s->budget--) { s->failed_pc=0x0c0ad034u; return 0; }
r[4]=r[4]&255u;
goto P_0c0ad036;
P_0c0ad036: /* original 2448, guest PC 0x0c0ad036 */
if(!s->budget--) { s->failed_pc=0x0c0ad036u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ad038;
P_0c0ad038: /* original 8d22, guest PC 0x0c0ad038 */
if(!s->budget--) { s->failed_pc=0x0c0ad038u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0ad080; }
goto P_0c0ad03c;
P_0c0ad03a: /* original 655d, guest PC 0x0c0ad03a */
if(!s->budget--) { s->failed_pc=0x0c0ad03au; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ad03c;
P_0c0ad03c: /* original 3547, guest PC 0x0c0ad03c */
if(!s->budget--) { s->failed_pc=0x0c0ad03cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[4])!=0);
goto P_0c0ad03e;
P_0c0ad03e: /* original 8b46, guest PC 0x0c0ad03e */
if(!s->budget--) { s->failed_pc=0x0c0ad03eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad0ce; }
goto P_0c0ad040;
P_0c0ad040: /* original e048, guest PC 0x0c0ad040 */
if(!s->budget--) { s->failed_pc=0x0c0ad040u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad042;
P_0c0ad042: /* original d33e, guest PC 0x0c0ad042 */
if(!s->budget--) { s->failed_pc=0x0c0ad042u; return 0; }
r[3]=read(ram,0x0c0ad13cu,4);
goto P_0c0ad044;
P_0c0ad044: /* original 04ee, guest PC 0x0c0ad044 */
if(!s->budget--) { s->failed_pc=0x0c0ad044u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ad046;
P_0c0ad046: /* original d23e, guest PC 0x0c0ad046 */
if(!s->budget--) { s->failed_pc=0x0c0ad046u; return 0; }
r[2]=read(ram,0x0c0ad140u,4);
goto P_0c0ad048;
P_0c0ad048: /* original 243b, guest PC 0x0c0ad048 */
if(!s->budget--) { s->failed_pc=0x0c0ad048u; return 0; }
r[4]|=r[3];
goto P_0c0ad04a;
P_0c0ad04a: /* original 2429, guest PC 0x0c0ad04a */
if(!s->budget--) { s->failed_pc=0x0c0ad04au; return 0; }
r[4]&=r[2];
goto P_0c0ad04c;
P_0c0ad04c: /* original 0e46, guest PC 0x0c0ad04c */
if(!s->budget--) { s->failed_pc=0x0c0ad04cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0ad04e;
P_0c0ad04e: /* original 9070, guest PC 0x0c0ad04e */
if(!s->budget--) { s->failed_pc=0x0c0ad04eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad132u,2);
goto P_0c0ad050;
P_0c0ad050: /* original 9570, guest PC 0x0c0ad050 */
if(!s->budget--) { s->failed_pc=0x0c0ad050u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad134u,2);
goto P_0c0ad052;
P_0c0ad052: /* original 0dec, guest PC 0x0c0ad052 */
if(!s->budget--) { s->failed_pc=0x0c0ad052u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ad054;
P_0c0ad054: /* original e03e, guest PC 0x0c0ad054 */
if(!s->budget--) { s->failed_pc=0x0c0ad054u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ad056;
P_0c0ad056: /* original 04ed, guest PC 0x0c0ad056 */
if(!s->budget--) { s->failed_pc=0x0c0ad056u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad058;
P_0c0ad058: /* original 6ddc, guest PC 0x0c0ad058 */
if(!s->budget--) { s->failed_pc=0x0c0ad058u; return 0; }
r[13]=r[13]&255u;
goto P_0c0ad05a;
P_0c0ad05a: /* original 634d, guest PC 0x0c0ad05a */
if(!s->budget--) { s->failed_pc=0x0c0ad05au; return 0; }
r[3]=r[4]&65535u;
goto P_0c0ad05c;
P_0c0ad05c: /* original 33d8, guest PC 0x0c0ad05c */
if(!s->budget--) { s->failed_pc=0x0c0ad05cu; return 0; }
r[3]-=r[13];
goto P_0c0ad05e;
P_0c0ad05e: /* original 6d33, guest PC 0x0c0ad05e */
if(!s->budget--) { s->failed_pc=0x0c0ad05eu; return 0; }
r[13]=r[3];
goto P_0c0ad060;
P_0c0ad060: /* original b08a, guest PC 0x0c0ad060 */
if(!s->budget--) { s->failed_pc=0x0c0ad060u; return 0; }
target=code_base|0x0c0ad178u; r[16]=code_base|0x0c0ad064u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad064u) { target=s->pc; goto dispatch; }
goto P_0c0ad064;
P_0c0ad062: /* original 64e3, guest PC 0x0c0ad062 */
if(!s->budget--) { s->failed_pc=0x0c0ad062u; return 0; }
r[4]=r[14];
goto P_0c0ad064;
P_0c0ad064: /* original 9067, guest PC 0x0c0ad064 */
if(!s->budget--) { s->failed_pc=0x0c0ad064u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad136u,2);
goto P_0c0ad066;
P_0c0ad066: /* original 65c3, guest PC 0x0c0ad066 */
if(!s->budget--) { s->failed_pc=0x0c0ad066u; return 0; }
r[5]=r[12];
goto P_0c0ad068;
P_0c0ad068: /* original 04ed, guest PC 0x0c0ad068 */
if(!s->budget--) { s->failed_pc=0x0c0ad068u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad06a;
P_0c0ad06a: /* original e03e, guest PC 0x0c0ad06a */
if(!s->budget--) { s->failed_pc=0x0c0ad06au; return 0; }
r[0]=0x0000003eu;
goto P_0c0ad06c;
P_0c0ad06c: /* original 644d, guest PC 0x0c0ad06c */
if(!s->budget--) { s->failed_pc=0x0c0ad06cu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ad06e;
P_0c0ad06e: /* original 34d8, guest PC 0x0c0ad06e */
if(!s->budget--) { s->failed_pc=0x0c0ad06eu; return 0; }
r[4]-=r[13];
goto P_0c0ad070;
P_0c0ad070: /* original 74fe, guest PC 0x0c0ad070 */
if(!s->budget--) { s->failed_pc=0x0c0ad070u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c0ad072;
P_0c0ad072: /* original 0e45, guest PC 0x0c0ad072 */
if(!s->budget--) { s->failed_pc=0x0c0ad072u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0ad074;
P_0c0ad074: /* original 965e, guest PC 0x0c0ad074 */
if(!s->budget--) { s->failed_pc=0x0c0ad074u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad134u,2);
goto P_0c0ad076;
P_0c0ad076: /* original b046, guest PC 0x0c0ad076 */
if(!s->budget--) { s->failed_pc=0x0c0ad076u; return 0; }
target=code_base|0x0c0ad106u; r[16]=code_base|0x0c0ad07au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad07au) { target=s->pc; goto dispatch; }
goto P_0c0ad07a;
P_0c0ad078: /* original 64e3, guest PC 0x0c0ad078 */
if(!s->budget--) { s->failed_pc=0x0c0ad078u; return 0; }
r[4]=r[14];
goto P_0c0ad07a;
P_0c0ad07a: /* original 9059, guest PC 0x0c0ad07a */
if(!s->budget--) { s->failed_pc=0x0c0ad07au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad130u,2);
goto P_0c0ad07c;
P_0c0ad07c: /* original e200, guest PC 0x0c0ad07c */
if(!s->budget--) { s->failed_pc=0x0c0ad07cu; return 0; }
r[2]=0x00000000u;
goto P_0c0ad07e;
P_0c0ad07e: /* original 0e24, guest PC 0x0c0ad07e */
if(!s->budget--) { s->failed_pc=0x0c0ad07eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ad080;
P_0c0ad080: /* original e03e, guest PC 0x0c0ad080 */
if(!s->budget--) { s->failed_pc=0x0c0ad080u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ad082;
P_0c0ad082: /* original 03ed, guest PC 0x0c0ad082 */
if(!s->budget--) { s->failed_pc=0x0c0ad082u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad084;
P_0c0ad084: /* original 9057, guest PC 0x0c0ad084 */
if(!s->budget--) { s->failed_pc=0x0c0ad084u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad136u,2);
goto P_0c0ad086;
P_0c0ad086: /* original 02ed, guest PC 0x0c0ad086 */
if(!s->budget--) { s->failed_pc=0x0c0ad086u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad088;
P_0c0ad088: /* original 3326, guest PC 0x0c0ad088 */
if(!s->budget--) { s->failed_pc=0x0c0ad088u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[2])!=0);
goto P_0c0ad08a;
P_0c0ad08a: /* original 8b20, guest PC 0x0c0ad08a */
if(!s->budget--) { s->failed_pc=0x0c0ad08au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad0ce; }
goto P_0c0ad08c;
P_0c0ad08c: /* original 62e2, guest PC 0x0c0ad08c */
if(!s->budget--) { s->failed_pc=0x0c0ad08cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ad08e;
P_0c0ad08e: /* original e048, guest PC 0x0c0ad08e */
if(!s->budget--) { s->failed_pc=0x0c0ad08eu; return 0; }
r[0]=0x00000048u;
goto P_0c0ad090;
P_0c0ad090: /* original d32c, guest PC 0x0c0ad090 */
if(!s->budget--) { s->failed_pc=0x0c0ad090u; return 0; }
r[3]=read(ram,0x0c0ad144u,4);
goto P_0c0ad092;
P_0c0ad092: /* original 223b, guest PC 0x0c0ad092 */
if(!s->budget--) { s->failed_pc=0x0c0ad092u; return 0; }
r[2]|=r[3];
goto P_0c0ad094;
P_0c0ad094: /* original 2e22, guest PC 0x0c0ad094 */
if(!s->budget--) { s->failed_pc=0x0c0ad094u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ad096;
P_0c0ad096: /* original 01ee, guest PC 0x0c0ad096 */
if(!s->budget--) { s->failed_pc=0x0c0ad096u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0ad098;
P_0c0ad098: /* original d22b, guest PC 0x0c0ad098 */
if(!s->budget--) { s->failed_pc=0x0c0ad098u; return 0; }
r[2]=read(ram,0x0c0ad148u,4);
goto P_0c0ad09a;
P_0c0ad09a: /* original 2128, guest PC 0x0c0ad09a */
if(!s->budget--) { s->failed_pc=0x0c0ad09au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ad09c;
P_0c0ad09c: /* original 8b0b, guest PC 0x0c0ad09c */
if(!s->budget--) { s->failed_pc=0x0c0ad09cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad0b6; }
goto P_0c0ad09e;
P_0c0ad09e: /* original 65c3, guest PC 0x0c0ad09e */
if(!s->budget--) { s->failed_pc=0x0c0ad09eu; return 0; }
r[5]=r[12];
goto P_0c0ad0a0;
P_0c0ad0a0: /* original d32a, guest PC 0x0c0ad0a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad0a0u; return 0; }
r[3]=read(ram,0x0c0ad14cu,4);
goto P_0c0ad0a2;
P_0c0ad0a2: /* original 64e3, guest PC 0x0c0ad0a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad0a2u; return 0; }
r[4]=r[14];
goto P_0c0ad0a4;
P_0c0ad0a4: /* original 1e3c, guest PC 0x0c0ad0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad0a4u; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c0ad0a6;
P_0c0ad0a6: /* original 66f2, guest PC 0x0c0ad0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad0a6u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0ad0a8;
P_0c0ad0a8: /* original 7f04, guest PC 0x0c0ad0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad0a8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ad0aa;
P_0c0ad0aa: /* original 4f26, guest PC 0x0c0ad0aa */
if(!s->budget--) { s->failed_pc=0x0c0ad0aau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad0ac;
P_0c0ad0ac: /* original d328, guest PC 0x0c0ad0ac */
if(!s->budget--) { s->failed_pc=0x0c0ad0acu; return 0; }
r[3]=read(ram,0x0c0ad150u,4);
goto P_0c0ad0ae;
P_0c0ad0ae: /* original 6cf6, guest PC 0x0c0ad0ae */
if(!s->budget--) { s->failed_pc=0x0c0ad0aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad0b0;
P_0c0ad0b0: /* original 6df6, guest PC 0x0c0ad0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad0b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad0b2;
P_0c0ad0b2: /* original 432b, guest PC 0x0c0ad0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad0b2u; return 0; }
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
P_0c0ad0b4: /* original 6ef6, guest PC 0x0c0ad0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad0b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad0b6;
P_0c0ad0b6: /* original 65c3, guest PC 0x0c0ad0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad0b6u; return 0; }
r[5]=r[12];
goto P_0c0ad0b8;
P_0c0ad0b8: /* original d226, guest PC 0x0c0ad0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad0b8u; return 0; }
r[2]=read(ram,0x0c0ad154u,4);
goto P_0c0ad0ba;
P_0c0ad0ba: /* original 64e3, guest PC 0x0c0ad0ba */
if(!s->budget--) { s->failed_pc=0x0c0ad0bau; return 0; }
r[4]=r[14];
goto P_0c0ad0bc;
P_0c0ad0bc: /* original 1e2c, guest PC 0x0c0ad0bc */
if(!s->budget--) { s->failed_pc=0x0c0ad0bcu; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c0ad0be;
P_0c0ad0be: /* original 66f2, guest PC 0x0c0ad0be */
if(!s->budget--) { s->failed_pc=0x0c0ad0beu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0ad0c0;
P_0c0ad0c0: /* original 7f04, guest PC 0x0c0ad0c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad0c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ad0c2;
P_0c0ad0c2: /* original 4f26, guest PC 0x0c0ad0c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad0c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad0c4;
P_0c0ad0c4: /* original d324, guest PC 0x0c0ad0c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad0c4u; return 0; }
r[3]=read(ram,0x0c0ad158u,4);
goto P_0c0ad0c6;
P_0c0ad0c6: /* original 6cf6, guest PC 0x0c0ad0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad0c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad0c8;
P_0c0ad0c8: /* original 6df6, guest PC 0x0c0ad0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad0c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad0ca;
P_0c0ad0ca: /* original 432b, guest PC 0x0c0ad0ca */
if(!s->budget--) { s->failed_pc=0x0c0ad0cau; return 0; }
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
P_0c0ad0cc: /* original 6ef6, guest PC 0x0c0ad0cc */
if(!s->budget--) { s->failed_pc=0x0c0ad0ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad0ce;
P_0c0ad0ce: /* original 7f04, guest PC 0x0c0ad0ce */
if(!s->budget--) { s->failed_pc=0x0c0ad0ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ad0d0;
P_0c0ad0d0: /* original 4f26, guest PC 0x0c0ad0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad0d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad0d2;
P_0c0ad0d2: /* original 6cf6, guest PC 0x0c0ad0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad0d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad0d4;
P_0c0ad0d4: /* original 6df6, guest PC 0x0c0ad0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad0d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad0d6;
P_0c0ad0d6: /* original 000b, guest PC 0x0c0ad0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad0d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ad0d8: /* original 6ef6, guest PC 0x0c0ad0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad0d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ad0dau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad0dau; return 0; } return 1;
P_0c0ad106: /* original 7ffc, guest PC 0x0c0ad106 */
if(!s->budget--) { s->failed_pc=0x0c0ad106u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad108;
P_0c0ad108: /* original 2f62, guest PC 0x0c0ad108 */
if(!s->budget--) { s->failed_pc=0x0c0ad108u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0ad10a;
P_0c0ad10a: /* original e600, guest PC 0x0c0ad10a */
if(!s->budget--) { s->failed_pc=0x0c0ad10au; return 0; }
r[6]=0x00000000u;
goto P_0c0ad10c;
P_0c0ad10c: /* original 65f2, guest PC 0x0c0ad10c */
if(!s->budget--) { s->failed_pc=0x0c0ad10cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ad10e;
P_0c0ad10e: /* original a04c, guest PC 0x0c0ad10e */
if(!s->budget--) { s->failed_pc=0x0c0ad10eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ad1aa;
P_0c0ad110: /* original 7f04, guest PC 0x0c0ad110 */
if(!s->budget--) { s->failed_pc=0x0c0ad110u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ad112u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad112u; return 0; } return 1;
P_0c0ad178: /* original 2fe6, guest PC 0x0c0ad178 */
if(!s->budget--) { s->failed_pc=0x0c0ad178u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad17a;
P_0c0ad17a: /* original 6e43, guest PC 0x0c0ad17a */
if(!s->budget--) { s->failed_pc=0x0c0ad17au; return 0; }
r[14]=r[4];
goto P_0c0ad17c;
P_0c0ad17c: /* original 4f22, guest PC 0x0c0ad17c */
if(!s->budget--) { s->failed_pc=0x0c0ad17cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ad17e;
P_0c0ad17e: /* original 7ffc, guest PC 0x0c0ad17e */
if(!s->budget--) { s->failed_pc=0x0c0ad17eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad180;
P_0c0ad180: /* original 2f52, guest PC 0x0c0ad180 */
if(!s->budget--) { s->failed_pc=0x0c0ad180u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ad182;
P_0c0ad182: /* original 905a, guest PC 0x0c0ad182 */
if(!s->budget--) { s->failed_pc=0x0c0ad182u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad23au,2);
goto P_0c0ad184;
P_0c0ad184: /* original 03ec, guest PC 0x0c0ad184 */
if(!s->budget--) { s->failed_pc=0x0c0ad184u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ad186;
P_0c0ad186: /* original 633c, guest PC 0x0c0ad186 */
if(!s->budget--) { s->failed_pc=0x0c0ad186u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad188;
P_0c0ad188: /* original 4315, guest PC 0x0c0ad188 */
if(!s->budget--) { s->failed_pc=0x0c0ad188u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0ad18a;
P_0c0ad18a: /* original 8b04, guest PC 0x0c0ad18a */
if(!s->budget--) { s->failed_pc=0x0c0ad18au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad196; }
goto P_0c0ad18c;
P_0c0ad18c: /* original d22e, guest PC 0x0c0ad18c */
if(!s->budget--) { s->failed_pc=0x0c0ad18cu; return 0; }
r[2]=read(ram,0x0c0ad248u,4);
goto P_0c0ad18e;
P_0c0ad18e: /* original 420b, guest PC 0x0c0ad18e */
if(!s->budget--) { s->failed_pc=0x0c0ad18eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0ad192u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad192u) { target=s->pc; goto dispatch; }
goto P_0c0ad192;
P_0c0ad190: /* original 64e3, guest PC 0x0c0ad190 */
if(!s->budget--) { s->failed_pc=0x0c0ad190u; return 0; }
r[4]=r[14];
goto P_0c0ad192;
P_0c0ad192: /* original a003, guest PC 0x0c0ad192 */
if(!s->budget--) { s->failed_pc=0x0c0ad192u; return 0; }
goto P_0c0ad19c;
P_0c0ad194: /* original 0009, guest PC 0x0c0ad194 */
if(!s->budget--) { s->failed_pc=0x0c0ad194u; return 0; }
goto P_0c0ad196;
P_0c0ad196: /* original d22d, guest PC 0x0c0ad196 */
if(!s->budget--) { s->failed_pc=0x0c0ad196u; return 0; }
r[2]=read(ram,0x0c0ad24cu,4);
goto P_0c0ad198;
P_0c0ad198: /* original 420b, guest PC 0x0c0ad198 */
if(!s->budget--) { s->failed_pc=0x0c0ad198u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ad19cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad19cu) { target=s->pc; goto dispatch; }
goto P_0c0ad19c;
P_0c0ad19a: /* original 64e3, guest PC 0x0c0ad19a */
if(!s->budget--) { s->failed_pc=0x0c0ad19au; return 0; }
r[4]=r[14];
goto P_0c0ad19c;
P_0c0ad19c: /* original 65f2, guest PC 0x0c0ad19c */
if(!s->budget--) { s->failed_pc=0x0c0ad19cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ad19e;
P_0c0ad19e: /* original 7f04, guest PC 0x0c0ad19e */
if(!s->budget--) { s->failed_pc=0x0c0ad19eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ad1a0;
P_0c0ad1a0: /* original 4f26, guest PC 0x0c0ad1a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad1a2;
P_0c0ad1a2: /* original e600, guest PC 0x0c0ad1a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a2u; return 0; }
r[6]=0x00000000u;
goto P_0c0ad1a4;
P_0c0ad1a4: /* original 64e3, guest PC 0x0c0ad1a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a4u; return 0; }
r[4]=r[14];
goto P_0c0ad1a6;
P_0c0ad1a6: /* original a000, guest PC 0x0c0ad1a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad1aa;
P_0c0ad1a8: /* original 6ef6, guest PC 0x0c0ad1a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad1aa;
P_0c0ad1aa: /* original 2fe6, guest PC 0x0c0ad1aa */
if(!s->budget--) { s->failed_pc=0x0c0ad1aau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1ac;
P_0c0ad1ac: /* original 6e43, guest PC 0x0c0ad1ac */
if(!s->budget--) { s->failed_pc=0x0c0ad1acu; return 0; }
r[14]=r[4];
goto P_0c0ad1ae;
P_0c0ad1ae: /* original 2fd6, guest PC 0x0c0ad1ae */
if(!s->budget--) { s->failed_pc=0x0c0ad1aeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b0;
P_0c0ad1b0: /* original 2fc6, guest PC 0x0c0ad1b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b2;
P_0c0ad1b2: /* original 2fb6, guest PC 0x0c0ad1b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b4;
P_0c0ad1b4: /* original 2fa6, guest PC 0x0c0ad1b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b6;
P_0c0ad1b6: /* original 84e4, guest PC 0x0c0ad1b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0ad1b8;
P_0c0ad1b8: /* original 4f22, guest PC 0x0c0ad1b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ad1ba;
P_0c0ad1ba: /* original d425, guest PC 0x0c0ad1ba */
if(!s->budget--) { s->failed_pc=0x0c0ad1bau; return 0; }
r[4]=read(ram,0x0c0ad250u,4);
goto P_0c0ad1bc;
P_0c0ad1bc: /* original 2008, guest PC 0x0c0ad1bc */
if(!s->budget--) { s->failed_pc=0x0c0ad1bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0ad1be;
P_0c0ad1be: /* original 8f02, guest PC 0x0c0ad1be */
if(!s->budget--) { s->failed_pc=0x0c0ad1beu; return 0; }
cond=r[17]&1u;
r[0]=0x00000048u;
if(!cond) { goto P_0c0ad1c6; }
goto P_0c0ad1c2;
P_0c0ad1c0: /* original e048, guest PC 0x0c0ad1c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c0u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad1c2;
P_0c0ad1c2: /* original a001, guest PC 0x0c0ad1c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c2u; return 0; }
r[12]=read(ram,r[4]+20,4);
goto P_0c0ad1c8;
P_0c0ad1c4: /* original 5c45, guest PC 0x0c0ad1c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c4u; return 0; }
r[12]=read(ram,r[4]+20,4);
goto P_0c0ad1c6;
P_0c0ad1c6: /* original 5c44, guest PC 0x0c0ad1c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c6u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c0ad1c8;
P_0c0ad1c8: /* original 04ee, guest PC 0x0c0ad1c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ad1ca;
P_0c0ad1ca: /* original ed00, guest PC 0x0c0ad1ca */
if(!s->budget--) { s->failed_pc=0x0c0ad1cau; return 0; }
r[13]=0x00000000u;
goto P_0c0ad1cc;
P_0c0ad1cc: /* original 9036, guest PC 0x0c0ad1cc */
if(!s->budget--) { s->failed_pc=0x0c0ad1ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad23cu,2);
goto P_0c0ad1ce;
P_0c0ad1ce: /* original 2558, guest PC 0x0c0ad1ce */
if(!s->budget--) { s->failed_pc=0x0c0ad1ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ad1d0;
P_0c0ad1d0: /* original f38d, guest PC 0x0c0ad1d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d0u; return 0; }
fr[3]=0;
goto P_0c0ad1d2;
P_0c0ad1d2: /* original fe37, guest PC 0x0c0ad1d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ad1d4;
P_0c0ad1d4: /* original 7066, guest PC 0x0c0ad1d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d4u; return 0; }
r[0]+=0x00000066u;
goto P_0c0ad1d6;
P_0c0ad1d6: /* original 0ed4, guest PC 0x0c0ad1d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0ad1d8;
P_0c0ad1d8: /* original 8f08, guest PC 0x0c0ad1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d8u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[7]=tmp;
if(!cond) { goto P_0c0ad1ec; }
goto P_0c0ad1dc;
P_0c0ad1da: /* original 67e2, guest PC 0x0c0ad1da */
if(!s->budget--) { s->failed_pc=0x0c0ad1dau; return 0; }
tmp=read(ram,r[14],4);
r[7]=tmp;
goto P_0c0ad1dc;
P_0c0ad1dc: /* original e048, guest PC 0x0c0ad1dc */
if(!s->budget--) { s->failed_pc=0x0c0ad1dcu; return 0; }
r[0]=0x00000048u;
goto P_0c0ad1de;
P_0c0ad1de: /* original d31d, guest PC 0x0c0ad1de */
if(!s->budget--) { s->failed_pc=0x0c0ad1deu; return 0; }
r[3]=read(ram,0x0c0ad254u,4);
goto P_0c0ad1e0;
P_0c0ad1e0: /* original 02ee, guest PC 0x0c0ad1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ad1e2;
P_0c0ad1e2: /* original 2239, guest PC 0x0c0ad1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e2u; return 0; }
r[2]&=r[3];
goto P_0c0ad1e4;
P_0c0ad1e4: /* original 0e26, guest PC 0x0c0ad1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ad1e6;
P_0c0ad1e6: /* original e03c, guest PC 0x0c0ad1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e6u; return 0; }
r[0]=0x0000003cu;
goto P_0c0ad1e8;
P_0c0ad1e8: /* original a0ad, guest PC 0x0c0ad1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e8u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad346;
P_0c0ad1ea: /* original 0e55, guest PC 0x0c0ad1ea */
if(!s->budget--) { s->failed_pc=0x0c0ad1eau; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad1ec;
P_0c0ad1ec: /* original d31a, guest PC 0x0c0ad1ec */
if(!s->budget--) { s->failed_pc=0x0c0ad1ecu; return 0; }
r[3]=read(ram,0x0c0ad258u,4);
goto P_0c0ad1ee;
P_0c0ad1ee: /* original e2ef, guest PC 0x0c0ad1ee */
if(!s->budget--) { s->failed_pc=0x0c0ad1eeu; return 0; }
r[2]=0xffffffefu;
goto P_0c0ad1f0;
P_0c0ad1f0: /* original 273b, guest PC 0x0c0ad1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f0u; return 0; }
r[7]|=r[3];
goto P_0c0ad1f2;
P_0c0ad1f2: /* original 2729, guest PC 0x0c0ad1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f2u; return 0; }
r[7]&=r[2];
goto P_0c0ad1f4;
P_0c0ad1f4: /* original 2e72, guest PC 0x0c0ad1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f4u; return 0; }
write(ram,r[14],r[7],4);
goto P_0c0ad1f6;
P_0c0ad1f6: /* original 9122, guest PC 0x0c0ad1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad23eu,2);
goto P_0c0ad1f8;
P_0c0ad1f8: /* original 2158, guest PC 0x0c0ad1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c0ad1fa;
P_0c0ad1fa: /* original 8d04, guest PC 0x0c0ad1fa */
if(!s->budget--) { s->failed_pc=0x0c0ad1fau; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(cond) { goto P_0c0ad206; }
goto P_0c0ad1fe;
P_0c0ad1fc: /* original e701, guest PC 0x0c0ad1fc */
if(!s->budget--) { s->failed_pc=0x0c0ad1fcu; return 0; }
r[7]=0x00000001u;
goto P_0c0ad1fe;
P_0c0ad1fe: /* original 901f, guest PC 0x0c0ad1fe */
if(!s->budget--) { s->failed_pc=0x0c0ad1feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad240u,2);
goto P_0c0ad200;
P_0c0ad200: /* original 0e74, guest PC 0x0c0ad200 */
if(!s->budget--) { s->failed_pc=0x0c0ad200u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0ad202;
P_0c0ad202: /* original d316, guest PC 0x0c0ad202 */
if(!s->budget--) { s->failed_pc=0x0c0ad202u; return 0; }
r[3]=read(ram,0x0c0ad25cu,4);
goto P_0c0ad204;
P_0c0ad204: /* original 2439, guest PC 0x0c0ad204 */
if(!s->budget--) { s->failed_pc=0x0c0ad204u; return 0; }
r[4]&=r[3];
goto P_0c0ad206;
P_0c0ad206: /* original 6243, guest PC 0x0c0ad206 */
if(!s->budget--) { s->failed_pc=0x0c0ad206u; return 0; }
r[2]=r[4];
goto P_0c0ad208;
P_0c0ad208: /* original 2278, guest PC 0x0c0ad208 */
if(!s->budget--) { s->failed_pc=0x0c0ad208u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0ad20a;
P_0c0ad20a: /* original 8902, guest PC 0x0c0ad20a */
if(!s->budget--) { s->failed_pc=0x0c0ad20au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad212; }
goto P_0c0ad20c;
P_0c0ad20c: /* original 60e2, guest PC 0x0c0ad20c */
if(!s->budget--) { s->failed_pc=0x0c0ad20cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0ad20e;
P_0c0ad20e: /* original cb04, guest PC 0x0c0ad20e */
if(!s->budget--) { s->failed_pc=0x0c0ad20eu; return 0; }
r[0]|=4u;
goto P_0c0ad210;
P_0c0ad210: /* original 2e02, guest PC 0x0c0ad210 */
if(!s->budget--) { s->failed_pc=0x0c0ad210u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0ad212;
P_0c0ad212: /* original 9216, guest PC 0x0c0ad212 */
if(!s->budget--) { s->failed_pc=0x0c0ad212u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad242u,2);
goto P_0c0ad214;
P_0c0ad214: /* original 2258, guest PC 0x0c0ad214 */
if(!s->budget--) { s->failed_pc=0x0c0ad214u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0ad216;
P_0c0ad216: /* original 8903, guest PC 0x0c0ad216 */
if(!s->budget--) { s->failed_pc=0x0c0ad216u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad220; }
goto P_0c0ad218;
P_0c0ad218: /* original 9012, guest PC 0x0c0ad218 */
if(!s->budget--) { s->failed_pc=0x0c0ad218u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad240u,2);
goto P_0c0ad21a;
P_0c0ad21a: /* original 0e74, guest PC 0x0c0ad21a */
if(!s->budget--) { s->failed_pc=0x0c0ad21au; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0ad21c;
P_0c0ad21c: /* original d310, guest PC 0x0c0ad21c */
if(!s->budget--) { s->failed_pc=0x0c0ad21cu; return 0; }
r[3]=read(ram,0x0c0ad260u,4);
goto P_0c0ad21e;
P_0c0ad21e: /* original 2439, guest PC 0x0c0ad21e */
if(!s->budget--) { s->failed_pc=0x0c0ad21eu; return 0; }
r[4]&=r[3];
goto P_0c0ad220;
P_0c0ad220: /* original d710, guest PC 0x0c0ad220 */
if(!s->budget--) { s->failed_pc=0x0c0ad220u; return 0; }
r[7]=read(ram,0x0c0ad264u,4);
goto P_0c0ad222;
P_0c0ad222: /* original 6243, guest PC 0x0c0ad222 */
if(!s->budget--) { s->failed_pc=0x0c0ad222u; return 0; }
r[2]=r[4];
goto P_0c0ad224;
P_0c0ad224: /* original 2278, guest PC 0x0c0ad224 */
if(!s->budget--) { s->failed_pc=0x0c0ad224u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0ad226;
P_0c0ad226: /* original 8926, guest PC 0x0c0ad226 */
if(!s->budget--) { s->failed_pc=0x0c0ad226u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad276; }
goto P_0c0ad228;
P_0c0ad228: /* original 6063, guest PC 0x0c0ad228 */
if(!s->budget--) { s->failed_pc=0x0c0ad228u; return 0; }
r[0]=r[6];
goto P_0c0ad22a;
P_0c0ad22a: /* original 8801, guest PC 0x0c0ad22a */
if(!s->budget--) { s->failed_pc=0x0c0ad22au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ad22c;
P_0c0ad22c: /* original 8b1e, guest PC 0x0c0ad22c */
if(!s->budget--) { s->failed_pc=0x0c0ad22cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad26c; }
goto P_0c0ad22e;
P_0c0ad22e: /* original d30e, guest PC 0x0c0ad22e */
if(!s->budget--) { s->failed_pc=0x0c0ad22eu; return 0; }
r[3]=read(ram,0x0c0ad268u,4);
goto P_0c0ad230;
P_0c0ad230: /* original 2348, guest PC 0x0c0ad230 */
if(!s->budget--) { s->failed_pc=0x0c0ad230u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ad232;
P_0c0ad232: /* original 891b, guest PC 0x0c0ad232 */
if(!s->budget--) { s->failed_pc=0x0c0ad232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad26c; }
goto P_0c0ad234;
P_0c0ad234: /* original 9006, guest PC 0x0c0ad234 */
if(!s->budget--) { s->failed_pc=0x0c0ad234u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad244u,2);
goto P_0c0ad236;
P_0c0ad236: /* original a01d, guest PC 0x0c0ad236 */
if(!s->budget--) { s->failed_pc=0x0c0ad236u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad274;
P_0c0ad238: /* original 00ed, guest PC 0x0c0ad238 */
if(!s->budget--) { s->failed_pc=0x0c0ad238u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(0x0c0ad23au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad23au; return 0; } return 1;
P_0c0ad26c: /* original 9072, guest PC 0x0c0ad26c */
if(!s->budget--) { s->failed_pc=0x0c0ad26cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad354u,2);
goto P_0c0ad26e;
P_0c0ad26e: /* original 03ed, guest PC 0x0c0ad26e */
if(!s->budget--) { s->failed_pc=0x0c0ad26eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad270;
P_0c0ad270: /* original 85ef, guest PC 0x0c0ad270 */
if(!s->budget--) { s->failed_pc=0x0c0ad270u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0ad272;
P_0c0ad272: /* original 303c, guest PC 0x0c0ad272 */
if(!s->budget--) { s->failed_pc=0x0c0ad272u; return 0; }
r[0]+=r[3];
goto P_0c0ad274;
P_0c0ad274: /* original 81ef, guest PC 0x0c0ad274 */
if(!s->budget--) { s->failed_pc=0x0c0ad274u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ad276;
P_0c0ad276: /* original da3e, guest PC 0x0c0ad276 */
if(!s->budget--) { s->failed_pc=0x0c0ad276u; return 0; }
r[10]=read(ram,0x0c0ad370u,4);
goto P_0c0ad278;
P_0c0ad278: /* original 2a49, guest PC 0x0c0ad278 */
if(!s->budget--) { s->failed_pc=0x0c0ad278u; return 0; }
r[10]&=r[4];
goto P_0c0ad27a;
P_0c0ad27a: /* original 2aa8, guest PC 0x0c0ad27a */
if(!s->budget--) { s->failed_pc=0x0c0ad27au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0ad27c;
P_0c0ad27c: /* original 8907, guest PC 0x0c0ad27c */
if(!s->budget--) { s->failed_pc=0x0c0ad27cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad28e; }
goto P_0c0ad27e;
P_0c0ad27e: /* original 906a, guest PC 0x0c0ad27e */
if(!s->budget--) { s->failed_pc=0x0c0ad27eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad356u,2);
goto P_0c0ad280;
P_0c0ad280: /* original f3e6, guest PC 0x0c0ad280 */
if(!s->budget--) { s->failed_pc=0x0c0ad280u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ad282;
P_0c0ad282: /* original e010, guest PC 0x0c0ad282 */
if(!s->budget--) { s->failed_pc=0x0c0ad282u; return 0; }
r[0]=0x00000010u;
goto P_0c0ad284;
P_0c0ad284: /* original fe37, guest PC 0x0c0ad284 */
if(!s->budget--) { s->failed_pc=0x0c0ad284u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ad286;
P_0c0ad286: /* original 9067, guest PC 0x0c0ad286 */
if(!s->budget--) { s->failed_pc=0x0c0ad286u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad358u,2);
goto P_0c0ad288;
P_0c0ad288: /* original f3e6, guest PC 0x0c0ad288 */
if(!s->budget--) { s->failed_pc=0x0c0ad288u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ad28a;
P_0c0ad28a: /* original e018, guest PC 0x0c0ad28a */
if(!s->budget--) { s->failed_pc=0x0c0ad28au; return 0; }
r[0]=0x00000018u;
goto P_0c0ad28c;
P_0c0ad28c: /* original fe37, guest PC 0x0c0ad28c */
if(!s->budget--) { s->failed_pc=0x0c0ad28cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ad28e;
P_0c0ad28e: /* original 9164, guest PC 0x0c0ad28e */
if(!s->budget--) { s->failed_pc=0x0c0ad28eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35au,2);
goto P_0c0ad290;
P_0c0ad290: /* original e014, guest PC 0x0c0ad290 */
if(!s->budget--) { s->failed_pc=0x0c0ad290u; return 0; }
r[0]=0x00000014u;
goto P_0c0ad292;
P_0c0ad292: /* original f2e6, guest PC 0x0c0ad292 */
if(!s->budget--) { s->failed_pc=0x0c0ad292u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ad294;
P_0c0ad294: /* original 31ec, guest PC 0x0c0ad294 */
if(!s->budget--) { s->failed_pc=0x0c0ad294u; return 0; }
r[1]+=r[14];
goto P_0c0ad296;
P_0c0ad296: /* original 9361, guest PC 0x0c0ad296 */
if(!s->budget--) { s->failed_pc=0x0c0ad296u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35cu,2);
goto P_0c0ad298;
P_0c0ad298: /* original f318, guest PC 0x0c0ad298 */
if(!s->budget--) { s->failed_pc=0x0c0ad298u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0ad29a;
P_0c0ad29a: /* original 2438, guest PC 0x0c0ad29a */
if(!s->budget--) { s->failed_pc=0x0c0ad29au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0ad29c;
P_0c0ad29c: /* original f230, guest PC 0x0c0ad29c */
if(!s->budget--) { s->failed_pc=0x0c0ad29cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0ad29e;
P_0c0ad29e: /* original 8d03, guest PC 0x0c0ad29e */
if(!s->budget--) { s->failed_pc=0x0c0ad29eu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[14]+r[0]);
if(cond) { goto P_0c0ad2a8; }
goto P_0c0ad2a2;
P_0c0ad2a0: /* original fe27, guest PC 0x0c0ad2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a0u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0ad2a2;
P_0c0ad2a2: /* original 61e2, guest PC 0x0c0ad2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a2u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ad2a4;
P_0c0ad2a4: /* original 217a, guest PC 0x0c0ad2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a4u; return 0; }
r[1]^=r[7];
goto P_0c0ad2a6;
P_0c0ad2a6: /* original 2e12, guest PC 0x0c0ad2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a6u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ad2a8;
P_0c0ad2a8: /* original db32, guest PC 0x0c0ad2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a8u; return 0; }
r[11]=read(ram,0x0c0ad374u,4);
goto P_0c0ad2aa;
P_0c0ad2aa: /* original 2b59, guest PC 0x0c0ad2aa */
if(!s->budget--) { s->failed_pc=0x0c0ad2aau; return 0; }
r[11]&=r[5];
goto P_0c0ad2ac;
P_0c0ad2ac: /* original 2bb8, guest PC 0x0c0ad2ac */
if(!s->budget--) { s->failed_pc=0x0c0ad2acu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0ad2ae;
P_0c0ad2ae: /* original 8902, guest PC 0x0c0ad2ae */
if(!s->budget--) { s->failed_pc=0x0c0ad2aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad2b6; }
goto P_0c0ad2b0;
P_0c0ad2b0: /* original 62e2, guest PC 0x0c0ad2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ad2b2;
P_0c0ad2b2: /* original 227a, guest PC 0x0c0ad2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b2u; return 0; }
r[2]^=r[7];
goto P_0c0ad2b4;
P_0c0ad2b4: /* original 2e22, guest PC 0x0c0ad2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b4u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ad2b6;
P_0c0ad2b6: /* original 9352, guest PC 0x0c0ad2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35eu,2);
goto P_0c0ad2b8;
P_0c0ad2b8: /* original e03c, guest PC 0x0c0ad2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b8u; return 0; }
r[0]=0x0000003cu;
goto P_0c0ad2ba;
P_0c0ad2ba: /* original 2539, guest PC 0x0c0ad2ba */
if(!s->budget--) { s->failed_pc=0x0c0ad2bau; return 0; }
r[5]&=r[3];
goto P_0c0ad2bc;
P_0c0ad2bc: /* original 0e55, guest PC 0x0c0ad2bc */
if(!s->budget--) { s->failed_pc=0x0c0ad2bcu; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad2be;
P_0c0ad2be: /* original 65c3, guest PC 0x0c0ad2be */
if(!s->budget--) { s->failed_pc=0x0c0ad2beu; return 0; }
r[5]=r[12];
goto P_0c0ad2c0;
P_0c0ad2c0: /* original 06ed, guest PC 0x0c0ad2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad2c2;
P_0c0ad2c2: /* original 666d, guest PC 0x0c0ad2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c2u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0ad2c4;
P_0c0ad2c4: /* original b064, guest PC 0x0c0ad2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c4u; return 0; }
target=code_base|0x0c0ad390u; r[16]=code_base|0x0c0ad2c8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad2c8u) { target=s->pc; goto dispatch; }
goto P_0c0ad2c8;
P_0c0ad2c6: /* original 64e3, guest PC 0x0c0ad2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c6u; return 0; }
r[4]=r[14];
goto P_0c0ad2c8;
P_0c0ad2c8: /* original d32b, guest PC 0x0c0ad2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c8u; return 0; }
r[3]=read(ram,0x0c0ad378u,4);
goto P_0c0ad2ca;
P_0c0ad2ca: /* original 430b, guest PC 0x0c0ad2ca */
if(!s->budget--) { s->failed_pc=0x0c0ad2cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0ad2ceu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad2ceu) { target=s->pc; goto dispatch; }
goto P_0c0ad2ce;
P_0c0ad2cc: /* original 64e3, guest PC 0x0c0ad2cc */
if(!s->budget--) { s->failed_pc=0x0c0ad2ccu; return 0; }
r[4]=r[14];
goto P_0c0ad2ce;
P_0c0ad2ce: /* original d22b, guest PC 0x0c0ad2ce */
if(!s->budget--) { s->failed_pc=0x0c0ad2ceu; return 0; }
r[2]=read(ram,0x0c0ad37cu,4);
goto P_0c0ad2d0;
P_0c0ad2d0: /* original 420b, guest PC 0x0c0ad2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ad2d4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad2d4u) { target=s->pc; goto dispatch; }
goto P_0c0ad2d4;
P_0c0ad2d2: /* original 64e3, guest PC 0x0c0ad2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d2u; return 0; }
r[4]=r[14];
goto P_0c0ad2d4;
P_0c0ad2d4: /* original 2bb8, guest PC 0x0c0ad2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0ad2d6;
P_0c0ad2d6: /* original e048, guest PC 0x0c0ad2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d6u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad2d8;
P_0c0ad2d8: /* original 8d02, guest PC 0x0c0ad2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d8u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+r[0],4);
if(cond) { goto P_0c0ad2e0; }
goto P_0c0ad2dc;
P_0c0ad2da: /* original 04ee, guest PC 0x0c0ad2da */
if(!s->budget--) { s->failed_pc=0x0c0ad2dau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ad2dc;
P_0c0ad2dc: /* original 923e, guest PC 0x0c0ad2dc */
if(!s->budget--) { s->failed_pc=0x0c0ad2dcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35cu,2);
goto P_0c0ad2de;
P_0c0ad2de: /* original 242a, guest PC 0x0c0ad2de */
if(!s->budget--) { s->failed_pc=0x0c0ad2deu; return 0; }
r[4]^=r[2];
goto P_0c0ad2e0;
P_0c0ad2e0: /* original 2aa8, guest PC 0x0c0ad2e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0ad2e2;
P_0c0ad2e2: /* original 8901, guest PC 0x0c0ad2e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad2e8; }
goto P_0c0ad2e4;
P_0c0ad2e4: /* original d126, guest PC 0x0c0ad2e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e4u; return 0; }
r[1]=read(ram,0x0c0ad380u,4);
goto P_0c0ad2e6;
P_0c0ad2e6: /* original 241b, guest PC 0x0c0ad2e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e6u; return 0; }
r[4]|=r[1];
goto P_0c0ad2e8;
P_0c0ad2e8: /* original d626, guest PC 0x0c0ad2e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e8u; return 0; }
r[6]=read(ram,0x0c0ad384u,4);
goto P_0c0ad2ea;
P_0c0ad2ea: /* original 2649, guest PC 0x0c0ad2ea */
if(!s->budget--) { s->failed_pc=0x0c0ad2eau; return 0; }
r[6]&=r[4];
goto P_0c0ad2ec;
P_0c0ad2ec: /* original 2668, guest PC 0x0c0ad2ec */
if(!s->budget--) { s->failed_pc=0x0c0ad2ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ad2ee;
P_0c0ad2ee: /* original 8905, guest PC 0x0c0ad2ee */
if(!s->budget--) { s->failed_pc=0x0c0ad2eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad2fc; }
goto P_0c0ad2f0;
P_0c0ad2f0: /* original 9036, guest PC 0x0c0ad2f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad360u,2);
goto P_0c0ad2f2;
P_0c0ad2f2: /* original 02ed, guest PC 0x0c0ad2f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad2f4;
P_0c0ad2f4: /* original 7201, guest PC 0x0c0ad2f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f4u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ad2f6;
P_0c0ad2f6: /* original 0e25, guest PC 0x0c0ad2f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f6u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0ad2f8;
P_0c0ad2f8: /* original 70d6, guest PC 0x0c0ad2f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f8u; return 0; }
r[0]+=0xffffffd6u;
goto P_0c0ad2fa;
P_0c0ad2fa: /* original 0ed6, guest PC 0x0c0ad2fa */
if(!s->budget--) { s->failed_pc=0x0c0ad2fau; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad2fc;
P_0c0ad2fc: /* original 9331, guest PC 0x0c0ad2fc */
if(!s->budget--) { s->failed_pc=0x0c0ad2fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad362u,2);
goto P_0c0ad2fe;
P_0c0ad2fe: /* original 2348, guest PC 0x0c0ad2fe */
if(!s->budget--) { s->failed_pc=0x0c0ad2feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ad300;
P_0c0ad300: /* original 8904, guest PC 0x0c0ad300 */
if(!s->budget--) { s->failed_pc=0x0c0ad300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad30c; }
goto P_0c0ad302;
P_0c0ad302: /* original 902f, guest PC 0x0c0ad302 */
if(!s->budget--) { s->failed_pc=0x0c0ad302u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad364u,2);
goto P_0c0ad304;
P_0c0ad304: /* original 00ed, guest PC 0x0c0ad304 */
if(!s->budget--) { s->failed_pc=0x0c0ad304u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad306;
P_0c0ad306: /* original 81ef, guest PC 0x0c0ad306 */
if(!s->budget--) { s->failed_pc=0x0c0ad306u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ad308;
P_0c0ad308: /* original 902d, guest PC 0x0c0ad308 */
if(!s->budget--) { s->failed_pc=0x0c0ad308u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad366u,2);
goto P_0c0ad30a;
P_0c0ad30a: /* original 0ed6, guest PC 0x0c0ad30a */
if(!s->budget--) { s->failed_pc=0x0c0ad30au; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad30c;
P_0c0ad30c: /* original 902c, guest PC 0x0c0ad30c */
if(!s->budget--) { s->failed_pc=0x0c0ad30cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad368u,2);
goto P_0c0ad30e;
P_0c0ad30e: /* original 05ed, guest PC 0x0c0ad30e */
if(!s->budget--) { s->failed_pc=0x0c0ad30eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad310;
P_0c0ad310: /* original 0ed5, guest PC 0x0c0ad310 */
if(!s->budget--) { s->failed_pc=0x0c0ad310u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0ad312;
P_0c0ad312: /* original 62e2, guest PC 0x0c0ad312 */
if(!s->budget--) { s->failed_pc=0x0c0ad312u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ad314;
P_0c0ad314: /* original d31c, guest PC 0x0c0ad314 */
if(!s->budget--) { s->failed_pc=0x0c0ad314u; return 0; }
r[3]=read(ram,0x0c0ad388u,4);
goto P_0c0ad316;
P_0c0ad316: /* original 2238, guest PC 0x0c0ad316 */
if(!s->budget--) { s->failed_pc=0x0c0ad316u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ad318;
P_0c0ad318: /* original 8b0a, guest PC 0x0c0ad318 */
if(!s->budget--) { s->failed_pc=0x0c0ad318u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad330; }
goto P_0c0ad31a;
P_0c0ad31a: /* original 2668, guest PC 0x0c0ad31a */
if(!s->budget--) { s->failed_pc=0x0c0ad31au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ad31c;
P_0c0ad31c: /* original 8908, guest PC 0x0c0ad31c */
if(!s->budget--) { s->failed_pc=0x0c0ad31cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad330; }
goto P_0c0ad31e;
P_0c0ad31e: /* original 2558, guest PC 0x0c0ad31e */
if(!s->budget--) { s->failed_pc=0x0c0ad31eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ad320;
P_0c0ad320: /* original 8906, guest PC 0x0c0ad320 */
if(!s->budget--) { s->failed_pc=0x0c0ad320u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad330; }
goto P_0c0ad322;
P_0c0ad322: /* original 9022, guest PC 0x0c0ad322 */
if(!s->budget--) { s->failed_pc=0x0c0ad322u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad36au,2);
goto P_0c0ad324;
P_0c0ad324: /* original 0e55, guest PC 0x0c0ad324 */
if(!s->budget--) { s->failed_pc=0x0c0ad324u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad326;
P_0c0ad326: /* original 7008, guest PC 0x0c0ad326 */
if(!s->budget--) { s->failed_pc=0x0c0ad326u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ad328;
P_0c0ad328: /* original 03ee, guest PC 0x0c0ad328 */
if(!s->budget--) { s->failed_pc=0x0c0ad328u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0ad32a;
P_0c0ad32a: /* original 70fc, guest PC 0x0c0ad32a */
if(!s->budget--) { s->failed_pc=0x0c0ad32au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0ad32c;
P_0c0ad32c: /* original a002, guest PC 0x0c0ad32c */
if(!s->budget--) { s->failed_pc=0x0c0ad32cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0ad334;
P_0c0ad32e: /* original 0e36, guest PC 0x0c0ad32e */
if(!s->budget--) { s->failed_pc=0x0c0ad32eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0ad330;
P_0c0ad330: /* original 901b, guest PC 0x0c0ad330 */
if(!s->budget--) { s->failed_pc=0x0c0ad330u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad36au,2);
goto P_0c0ad332;
P_0c0ad332: /* original 0ed5, guest PC 0x0c0ad332 */
if(!s->budget--) { s->failed_pc=0x0c0ad332u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0ad334;
P_0c0ad334: /* original d515, guest PC 0x0c0ad334 */
if(!s->budget--) { s->failed_pc=0x0c0ad334u; return 0; }
r[5]=read(ram,0x0c0ad38cu,4);
goto P_0c0ad336;
P_0c0ad336: /* original 2548, guest PC 0x0c0ad336 */
if(!s->budget--) { s->failed_pc=0x0c0ad336u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[4])==0)!=0);
goto P_0c0ad338;
P_0c0ad338: /* original 8903, guest PC 0x0c0ad338 */
if(!s->budget--) { s->failed_pc=0x0c0ad338u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad342; }
goto P_0c0ad33a;
P_0c0ad33a: /* original 9017, guest PC 0x0c0ad33a */
if(!s->budget--) { s->failed_pc=0x0c0ad33au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad36cu,2);
goto P_0c0ad33c;
P_0c0ad33c: /* original 0ed6, guest PC 0x0c0ad33c */
if(!s->budget--) { s->failed_pc=0x0c0ad33cu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad33e;
P_0c0ad33e: /* original 7004, guest PC 0x0c0ad33e */
if(!s->budget--) { s->failed_pc=0x0c0ad33eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0ad340;
P_0c0ad340: /* original 0ed6, guest PC 0x0c0ad340 */
if(!s->budget--) { s->failed_pc=0x0c0ad340u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad342;
P_0c0ad342: /* original e048, guest PC 0x0c0ad342 */
if(!s->budget--) { s->failed_pc=0x0c0ad342u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad344;
P_0c0ad344: /* original 0e46, guest PC 0x0c0ad344 */
if(!s->budget--) { s->failed_pc=0x0c0ad344u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0ad346;
P_0c0ad346: /* original 4f26, guest PC 0x0c0ad346 */
if(!s->budget--) { s->failed_pc=0x0c0ad346u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad348;
P_0c0ad348: /* original 6af6, guest PC 0x0c0ad348 */
if(!s->budget--) { s->failed_pc=0x0c0ad348u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ad34a;
P_0c0ad34a: /* original 6bf6, guest PC 0x0c0ad34a */
if(!s->budget--) { s->failed_pc=0x0c0ad34au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ad34c;
P_0c0ad34c: /* original 6cf6, guest PC 0x0c0ad34c */
if(!s->budget--) { s->failed_pc=0x0c0ad34cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad34e;
P_0c0ad34e: /* original 6df6, guest PC 0x0c0ad34e */
if(!s->budget--) { s->failed_pc=0x0c0ad34eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad350;
P_0c0ad350: /* original 000b, guest PC 0x0c0ad350 */
if(!s->budget--) { s->failed_pc=0x0c0ad350u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ad352: /* original 6ef6, guest PC 0x0c0ad352 */
if(!s->budget--) { s->failed_pc=0x0c0ad352u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ad354u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad354u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
