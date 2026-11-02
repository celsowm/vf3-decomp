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
int vf3_away_batch9_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06aff8u: goto P_0c06aff8;
case 0x0c06affau: goto P_0c06affa;
case 0x0c06affcu: goto P_0c06affc;
case 0x0c06affeu: goto P_0c06affe;
case 0x0c06b000u: goto P_0c06b000;
case 0x0c06b002u: goto P_0c06b002;
case 0x0c06b004u: goto P_0c06b004;
case 0x0c06b006u: goto P_0c06b006;
case 0x0c06b008u: goto P_0c06b008;
case 0x0c06b00au: goto P_0c06b00a;
case 0x0c06b00cu: goto P_0c06b00c;
case 0x0c06b00eu: goto P_0c06b00e;
case 0x0c06b010u: goto P_0c06b010;
case 0x0c06b012u: goto P_0c06b012;
case 0x0c06b014u: goto P_0c06b014;
case 0x0c06b016u: goto P_0c06b016;
case 0x0c06b018u: goto P_0c06b018;
case 0x0c06b01au: goto P_0c06b01a;
case 0x0c06b01cu: goto P_0c06b01c;
case 0x0c06b01eu: goto P_0c06b01e;
case 0x0c06b020u: goto P_0c06b020;
case 0x0c06b022u: goto P_0c06b022;
case 0x0c06b024u: goto P_0c06b024;
case 0x0c06b026u: goto P_0c06b026;
case 0x0c06b028u: goto P_0c06b028;
case 0x0c06b02au: goto P_0c06b02a;
case 0x0c06b02cu: goto P_0c06b02c;
case 0x0c06b02eu: goto P_0c06b02e;
case 0x0c06b030u: goto P_0c06b030;
case 0x0c06b032u: goto P_0c06b032;
case 0x0c06b034u: goto P_0c06b034;
case 0x0c06b036u: goto P_0c06b036;
case 0x0c06b038u: goto P_0c06b038;
case 0x0c06b03au: goto P_0c06b03a;
case 0x0c06b03cu: goto P_0c06b03c;
case 0x0c06b03eu: goto P_0c06b03e;
case 0x0c06b040u: goto P_0c06b040;
case 0x0c06b042u: goto P_0c06b042;
case 0x0c06b044u: goto P_0c06b044;
case 0x0c06b046u: goto P_0c06b046;
case 0x0c06b048u: goto P_0c06b048;
case 0x0c06b04au: goto P_0c06b04a;
case 0x0c06b04cu: goto P_0c06b04c;
case 0x0c06b04eu: goto P_0c06b04e;
case 0x0c06b050u: goto P_0c06b050;
case 0x0c06b052u: goto P_0c06b052;
case 0x0c06b054u: goto P_0c06b054;
case 0x0c06b056u: goto P_0c06b056;
case 0x0c06b058u: goto P_0c06b058;
case 0x0c06b05au: goto P_0c06b05a;
case 0x0c06b05cu: goto P_0c06b05c;
case 0x0c06b05eu: goto P_0c06b05e;
case 0x0c06b060u: goto P_0c06b060;
case 0x0c06b062u: goto P_0c06b062;
case 0x0c06b064u: goto P_0c06b064;
case 0x0c06b066u: goto P_0c06b066;
case 0x0c06b068u: goto P_0c06b068;
case 0x0c06b06au: goto P_0c06b06a;
case 0x0c06b06cu: goto P_0c06b06c;
case 0x0c06b06eu: goto P_0c06b06e;
case 0x0c06b070u: goto P_0c06b070;
case 0x0c06b072u: goto P_0c06b072;
case 0x0c06b074u: goto P_0c06b074;
case 0x0c06b076u: goto P_0c06b076;
case 0x0c06b078u: goto P_0c06b078;
case 0x0c06b07au: goto P_0c06b07a;
case 0x0c06b07cu: goto P_0c06b07c;
case 0x0c06b07eu: goto P_0c06b07e;
case 0x0c06b080u: goto P_0c06b080;
case 0x0c06b082u: goto P_0c06b082;
case 0x0c06b084u: goto P_0c06b084;
case 0x0c06b086u: goto P_0c06b086;
case 0x0c06b088u: goto P_0c06b088;
case 0x0c06b08au: goto P_0c06b08a;
case 0x0c06b08cu: goto P_0c06b08c;
case 0x0c06b08eu: goto P_0c06b08e;
case 0x0c06b090u: goto P_0c06b090;
case 0x0c06b092u: goto P_0c06b092;
case 0x0c06b094u: goto P_0c06b094;
case 0x0c06b096u: goto P_0c06b096;
case 0x0c06b098u: goto P_0c06b098;
case 0x0c06b09au: goto P_0c06b09a;
case 0x0c06b09cu: goto P_0c06b09c;
case 0x0c06b09eu: goto P_0c06b09e;
case 0x0c06b0a0u: goto P_0c06b0a0;
case 0x0c06b0a2u: goto P_0c06b0a2;
case 0x0c06b0a4u: goto P_0c06b0a4;
case 0x0c06b0a6u: goto P_0c06b0a6;
case 0x0c06b0a8u: goto P_0c06b0a8;
case 0x0c06b0aau: goto P_0c06b0aa;
case 0x0c06b0acu: goto P_0c06b0ac;
case 0x0c06b0aeu: goto P_0c06b0ae;
case 0x0c06b0b0u: goto P_0c06b0b0;
case 0x0c06b0b2u: goto P_0c06b0b2;
case 0x0c06b0b4u: goto P_0c06b0b4;
case 0x0c06b0b6u: goto P_0c06b0b6;
case 0x0c06b0b8u: goto P_0c06b0b8;
case 0x0c06b0bau: goto P_0c06b0ba;
case 0x0c06b0bcu: goto P_0c06b0bc;
case 0x0c06b0beu: goto P_0c06b0be;
case 0x0c06b0c0u: goto P_0c06b0c0;
case 0x0c06b0c2u: goto P_0c06b0c2;
case 0x0c06b0c4u: goto P_0c06b0c4;
case 0x0c06b0c6u: goto P_0c06b0c6;
case 0x0c06b0c8u: goto P_0c06b0c8;
case 0x0c06b0cau: goto P_0c06b0ca;
case 0x0c06b0ccu: goto P_0c06b0cc;
case 0x0c06b0ceu: goto P_0c06b0ce;
case 0x0c06b0d0u: goto P_0c06b0d0;
case 0x0c06b0d2u: goto P_0c06b0d2;
case 0x0c06b0d4u: goto P_0c06b0d4;
case 0x0c06b0d6u: goto P_0c06b0d6;
case 0x0c06b0d8u: goto P_0c06b0d8;
case 0x0c06b0dau: goto P_0c06b0da;
case 0x0c06b0dcu: goto P_0c06b0dc;
case 0x0c06b0deu: goto P_0c06b0de;
case 0x0c06b0e0u: goto P_0c06b0e0;
case 0x0c06b0e2u: goto P_0c06b0e2;
case 0x0c06b0e4u: goto P_0c06b0e4;
case 0x0c06b0e6u: goto P_0c06b0e6;
case 0x0c06b0e8u: goto P_0c06b0e8;
case 0x0c06b0eau: goto P_0c06b0ea;
case 0x0c06b0ecu: goto P_0c06b0ec;
case 0x0c06b0eeu: goto P_0c06b0ee;
case 0x0c06b0f0u: goto P_0c06b0f0;
case 0x0c06b0f2u: goto P_0c06b0f2;
case 0x0c06b0f4u: goto P_0c06b0f4;
case 0x0c06b0f6u: goto P_0c06b0f6;
case 0x0c06b0f8u: goto P_0c06b0f8;
case 0x0c06b0fau: goto P_0c06b0fa;
case 0x0c06b0fcu: goto P_0c06b0fc;
case 0x0c06b0feu: goto P_0c06b0fe;
case 0x0c06b100u: goto P_0c06b100;
case 0x0c06b102u: goto P_0c06b102;
case 0x0c06b104u: goto P_0c06b104;
case 0x0c06b106u: goto P_0c06b106;
case 0x0c06b108u: goto P_0c06b108;
case 0x0c06b10au: goto P_0c06b10a;
case 0x0c06b10cu: goto P_0c06b10c;
case 0x0c06b10eu: goto P_0c06b10e;
case 0x0c06b110u: goto P_0c06b110;
case 0x0c06b112u: goto P_0c06b112;
case 0x0c06b150u: goto P_0c06b150;
case 0x0c06b152u: goto P_0c06b152;
case 0x0c06b154u: goto P_0c06b154;
case 0x0c06b156u: goto P_0c06b156;
case 0x0c06b158u: goto P_0c06b158;
case 0x0c06b15au: goto P_0c06b15a;
case 0x0c06b15cu: goto P_0c06b15c;
case 0x0c06b15eu: goto P_0c06b15e;
case 0x0c06b160u: goto P_0c06b160;
case 0x0c06b162u: goto P_0c06b162;
case 0x0c06b164u: goto P_0c06b164;
case 0x0c06b166u: goto P_0c06b166;
case 0x0c06b168u: goto P_0c06b168;
case 0x0c06b16au: goto P_0c06b16a;
case 0x0c06b16cu: goto P_0c06b16c;
case 0x0c06b16eu: goto P_0c06b16e;
case 0x0c06b170u: goto P_0c06b170;
case 0x0c06b172u: goto P_0c06b172;
case 0x0c06b174u: goto P_0c06b174;
case 0x0c06b176u: goto P_0c06b176;
case 0x0c06b178u: goto P_0c06b178;
case 0x0c06b17au: goto P_0c06b17a;
case 0x0c06b17cu: goto P_0c06b17c;
case 0x0c06b17eu: goto P_0c06b17e;
case 0x0c06b180u: goto P_0c06b180;
case 0x0c06b182u: goto P_0c06b182;
case 0x0c06b184u: goto P_0c06b184;
case 0x0c06b186u: goto P_0c06b186;
case 0x0c06b188u: goto P_0c06b188;
case 0x0c06b18au: goto P_0c06b18a;
case 0x0c06b18cu: goto P_0c06b18c;
case 0x0c06b18eu: goto P_0c06b18e;
case 0x0c06b190u: goto P_0c06b190;
case 0x0c06b192u: goto P_0c06b192;
case 0x0c06b194u: goto P_0c06b194;
case 0x0c06b196u: goto P_0c06b196;
case 0x0c06b198u: goto P_0c06b198;
case 0x0c06b19au: goto P_0c06b19a;
case 0x0c06b19cu: goto P_0c06b19c;
case 0x0c06b19eu: goto P_0c06b19e;
case 0x0c06b1a0u: goto P_0c06b1a0;
case 0x0c06b1a2u: goto P_0c06b1a2;
case 0x0c06b1a4u: goto P_0c06b1a4;
case 0x0c06b1a6u: goto P_0c06b1a6;
case 0x0c06b1a8u: goto P_0c06b1a8;
case 0x0c06b1aau: goto P_0c06b1aa;
case 0x0c06b1acu: goto P_0c06b1ac;
case 0x0c06b1aeu: goto P_0c06b1ae;
case 0x0c06b1b0u: goto P_0c06b1b0;
case 0x0c06b1b2u: goto P_0c06b1b2;
case 0x0c06b1b4u: goto P_0c06b1b4;
case 0x0c06b1b6u: goto P_0c06b1b6;
case 0x0c06b1b8u: goto P_0c06b1b8;
case 0x0c06b1bau: goto P_0c06b1ba;
case 0x0c06b1bcu: goto P_0c06b1bc;
case 0x0c06b1beu: goto P_0c06b1be;
case 0x0c06b1c0u: goto P_0c06b1c0;
case 0x0c06b1c2u: goto P_0c06b1c2;
case 0x0c06b1c4u: goto P_0c06b1c4;
case 0x0c06b1c6u: goto P_0c06b1c6;
case 0x0c06b1c8u: goto P_0c06b1c8;
case 0x0c06b1cau: goto P_0c06b1ca;
case 0x0c06b1ccu: goto P_0c06b1cc;
case 0x0c06b1ceu: goto P_0c06b1ce;
case 0x0c06b1d0u: goto P_0c06b1d0;
case 0x0c06b1d2u: goto P_0c06b1d2;
case 0x0c06b1d4u: goto P_0c06b1d4;
case 0x0c06b1d6u: goto P_0c06b1d6;
case 0x0c06b1d8u: goto P_0c06b1d8;
case 0x0c06b1dau: goto P_0c06b1da;
case 0x0c06b1dcu: goto P_0c06b1dc;
case 0x0c06b1deu: goto P_0c06b1de;
case 0x0c06b1e0u: goto P_0c06b1e0;
case 0x0c06b1e2u: goto P_0c06b1e2;
case 0x0c06b1e4u: goto P_0c06b1e4;
case 0x0c06b1e6u: goto P_0c06b1e6;
case 0x0c06b1e8u: goto P_0c06b1e8;
case 0x0c06b1eau: goto P_0c06b1ea;
case 0x0c06b1ecu: goto P_0c06b1ec;
case 0x0c06b1eeu: goto P_0c06b1ee;
case 0x0c06b1f0u: goto P_0c06b1f0;
case 0x0c06b1f2u: goto P_0c06b1f2;
case 0x0c06b1f4u: goto P_0c06b1f4;
case 0x0c06b1f6u: goto P_0c06b1f6;
case 0x0c06b1f8u: goto P_0c06b1f8;
case 0x0c06b1fau: goto P_0c06b1fa;
case 0x0c06b1fcu: goto P_0c06b1fc;
case 0x0c06b1feu: goto P_0c06b1fe;
case 0x0c06b200u: goto P_0c06b200;
case 0x0c06b202u: goto P_0c06b202;
case 0x0c06b204u: goto P_0c06b204;
case 0x0c06b206u: goto P_0c06b206;
case 0x0c06b208u: goto P_0c06b208;
case 0x0c06b20au: goto P_0c06b20a;
case 0x0c06b20cu: goto P_0c06b20c;
case 0x0c06b20eu: goto P_0c06b20e;
case 0x0c06b210u: goto P_0c06b210;
case 0x0c06b212u: goto P_0c06b212;
case 0x0c06b214u: goto P_0c06b214;
case 0x0c06b216u: goto P_0c06b216;
case 0x0c06b218u: goto P_0c06b218;
case 0x0c06b21au: goto P_0c06b21a;
case 0x0c06b21cu: goto P_0c06b21c;
case 0x0c06b21eu: goto P_0c06b21e;
case 0x0c06b220u: goto P_0c06b220;
case 0x0c06b222u: goto P_0c06b222;
case 0x0c06b224u: goto P_0c06b224;
case 0x0c06b226u: goto P_0c06b226;
case 0x0c06b228u: goto P_0c06b228;
case 0x0c06b22au: goto P_0c06b22a;
case 0x0c06b22cu: goto P_0c06b22c;
case 0x0c06b22eu: goto P_0c06b22e;
case 0x0c06b230u: goto P_0c06b230;
case 0x0c06b232u: goto P_0c06b232;
case 0x0c06b234u: goto P_0c06b234;
case 0x0c06b236u: goto P_0c06b236;
case 0x0c06b238u: goto P_0c06b238;
case 0x0c06b23au: goto P_0c06b23a;
case 0x0c06b23cu: goto P_0c06b23c;
case 0x0c06b23eu: goto P_0c06b23e;
case 0x0c06b240u: goto P_0c06b240;
case 0x0c06b242u: goto P_0c06b242;
case 0x0c06b244u: goto P_0c06b244;
case 0x0c06b246u: goto P_0c06b246;
case 0x0c06b248u: goto P_0c06b248;
case 0x0c06b24au: goto P_0c06b24a;
case 0x0c06b24cu: goto P_0c06b24c;
case 0x0c06b24eu: goto P_0c06b24e;
case 0x0c06b250u: goto P_0c06b250;
case 0x0c06b252u: goto P_0c06b252;
case 0x0c06b254u: goto P_0c06b254;
case 0x0c06b256u: goto P_0c06b256;
case 0x0c06b258u: goto P_0c06b258;
case 0x0c06b25au: goto P_0c06b25a;
case 0x0c06b25cu: goto P_0c06b25c;
case 0x0c06b25eu: goto P_0c06b25e;
case 0x0c06b260u: goto P_0c06b260;
case 0x0c06b262u: goto P_0c06b262;
case 0x0c06b264u: goto P_0c06b264;
case 0x0c06b266u: goto P_0c06b266;
case 0x0c06b268u: goto P_0c06b268;
case 0x0c06b26au: goto P_0c06b26a;
case 0x0c06b26cu: goto P_0c06b26c;
case 0x0c06b26eu: goto P_0c06b26e;
case 0x0c06b270u: goto P_0c06b270;
case 0x0c06b272u: goto P_0c06b272;
case 0x0c06b274u: goto P_0c06b274;
case 0x0c06b276u: goto P_0c06b276;
case 0x0c06b278u: goto P_0c06b278;
case 0x0c06b27au: goto P_0c06b27a;
case 0x0c06b27cu: goto P_0c06b27c;
case 0x0c06b27eu: goto P_0c06b27e;
case 0x0c06b280u: goto P_0c06b280;
case 0x0c06b282u: goto P_0c06b282;
case 0x0c06b284u: goto P_0c06b284;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06aff8: /* original 2fe6, guest PC 0x0c06aff8 */
if(!s->budget--) { s->failed_pc=0x0c06aff8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06affa;
P_0c06affa: /* original 2fd6, guest PC 0x0c06affa */
if(!s->budget--) { s->failed_pc=0x0c06affau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06affc;
P_0c06affc: /* original 2fc6, guest PC 0x0c06affc */
if(!s->budget--) { s->failed_pc=0x0c06affcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06affe;
P_0c06affe: /* original 2fb6, guest PC 0x0c06affe */
if(!s->budget--) { s->failed_pc=0x0c06affeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b000;
P_0c06b000: /* original 2fa6, guest PC 0x0c06b000 */
if(!s->budget--) { s->failed_pc=0x0c06b000u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b002;
P_0c06b002: /* original 2f96, guest PC 0x0c06b002 */
if(!s->budget--) { s->failed_pc=0x0c06b002u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b004;
P_0c06b004: /* original 2f86, guest PC 0x0c06b004 */
if(!s->budget--) { s->failed_pc=0x0c06b004u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b006;
P_0c06b006: /* original fffb, guest PC 0x0c06b006 */
if(!s->budget--) { s->failed_pc=0x0c06b006u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b008;
P_0c06b008: /* original 4f22, guest PC 0x0c06b008 */
if(!s->budget--) { s->failed_pc=0x0c06b008u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06b00a;
P_0c06b00a: /* original d445, guest PC 0x0c06b00a */
if(!s->budget--) { s->failed_pc=0x0c06b00au; return 0; }
r[4]=read(ram,0x0c06b120u,4);
goto P_0c06b00c;
P_0c06b00c: /* original 9382, guest PC 0x0c06b00c */
if(!s->budget--) { s->failed_pc=0x0c06b00cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b114u,2);
goto P_0c06b00e;
P_0c06b00e: /* original 4f12, guest PC 0x0c06b00e */
if(!s->budget--) { s->failed_pc=0x0c06b00eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06b010;
P_0c06b010: /* original 334c, guest PC 0x0c06b010 */
if(!s->budget--) { s->failed_pc=0x0c06b010u; return 0; }
r[3]+=r[4];
goto P_0c06b012;
P_0c06b012: /* original 7ff8, guest PC 0x0c06b012 */
if(!s->budget--) { s->failed_pc=0x0c06b012u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06b014;
P_0c06b014: /* original 2f32, guest PC 0x0c06b014 */
if(!s->budget--) { s->failed_pc=0x0c06b014u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06b016;
P_0c06b016: /* original de43, guest PC 0x0c06b016 */
if(!s->budget--) { s->failed_pc=0x0c06b016u; return 0; }
r[14]=read(ram,0x0c06b124u,4);
goto P_0c06b018;
P_0c06b018: /* original d543, guest PC 0x0c06b018 */
if(!s->budget--) { s->failed_pc=0x0c06b018u; return 0; }
r[5]=read(ram,0x0c06b128u,4);
goto P_0c06b01a;
P_0c06b01a: /* original 947c, guest PC 0x0c06b01a */
if(!s->budget--) { s->failed_pc=0x0c06b01au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b116u,2);
goto P_0c06b01c;
P_0c06b01c: /* original 4e0b, guest PC 0x0c06b01c */
if(!s->budget--) { s->failed_pc=0x0c06b01cu; return 0; }
target=r[14];
r[16]=code_base|0x0c06b020u;
r[6]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b020u) { target=s->pc; goto dispatch; }
goto P_0c06b020;
P_0c06b01e: /* original e603, guest PC 0x0c06b01e */
if(!s->budget--) { s->failed_pc=0x0c06b01eu; return 0; }
r[6]=0x00000003u;
goto P_0c06b020;
P_0c06b020: /* original 9a7a, guest PC 0x0c06b020 */
if(!s->budget--) { s->failed_pc=0x0c06b020u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b118u,2);
goto P_0c06b022;
P_0c06b022: /* original ec0e, guest PC 0x0c06b022 */
if(!s->budget--) { s->failed_pc=0x0c06b022u; return 0; }
r[12]=0x0000000eu;
goto P_0c06b024;
P_0c06b024: /* original 9d79, guest PC 0x0c06b024 */
if(!s->budget--) { s->failed_pc=0x0c06b024u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b11au,2);
goto P_0c06b026;
P_0c06b026: /* original eb28, guest PC 0x0c06b026 */
if(!s->budget--) { s->failed_pc=0x0c06b026u; return 0; }
r[11]=0x00000028u;
goto P_0c06b028;
P_0c06b028: /* original d940, guest PC 0x0c06b028 */
if(!s->budget--) { s->failed_pc=0x0c06b028u; return 0; }
r[9]=read(ram,0x0c06b12cu,4);
goto P_0c06b02a;
P_0c06b02a: /* original e603, guest PC 0x0c06b02a */
if(!s->budget--) { s->failed_pc=0x0c06b02au; return 0; }
r[6]=0x00000003u;
goto P_0c06b02c;
P_0c06b02c: /* original 64d3, guest PC 0x0c06b02c */
if(!s->budget--) { s->failed_pc=0x0c06b02cu; return 0; }
r[4]=r[13];
goto P_0c06b02e;
P_0c06b02e: /* original 4e0b, guest PC 0x0c06b02e */
if(!s->budget--) { s->failed_pc=0x0c06b02eu; return 0; }
target=r[14];
r[16]=code_base|0x0c06b032u;
r[5]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b032u) { target=s->pc; goto dispatch; }
goto P_0c06b032;
P_0c06b030: /* original 6593, guest PC 0x0c06b030 */
if(!s->budget--) { s->failed_pc=0x0c06b030u; return 0; }
r[5]=r[9];
goto P_0c06b032;
P_0c06b032: /* original 7c02, guest PC 0x0c06b032 */
if(!s->budget--) { s->failed_pc=0x0c06b032u; return 0; }
r[12]+=0x00000002u;
goto P_0c06b034;
P_0c06b034: /* original 3cb3, guest PC 0x0c06b034 */
if(!s->budget--) { s->failed_pc=0x0c06b034u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[11])!=0);
goto P_0c06b036;
P_0c06b036: /* original 8ff8, guest PC 0x0c06b036 */
if(!s->budget--) { s->failed_pc=0x0c06b036u; return 0; }
cond=r[17]&1u;
r[13]+=r[10];
if(!cond) { goto P_0c06b02a; }
goto P_0c06b03a;
P_0c06b038: /* original 3dac, guest PC 0x0c06b038 */
if(!s->budget--) { s->failed_pc=0x0c06b038u; return 0; }
r[13]+=r[10];
goto P_0c06b03a;
P_0c06b03a: /* original eb00, guest PC 0x0c06b03a */
if(!s->budget--) { s->failed_pc=0x0c06b03au; return 0; }
r[11]=0x00000000u;
goto P_0c06b03c;
P_0c06b03c: /* original ec0d, guest PC 0x0c06b03c */
if(!s->budget--) { s->failed_pc=0x0c06b03cu; return 0; }
r[12]=0x0000000du;
goto P_0c06b03e;
P_0c06b03e: /* original 0bc7, guest PC 0x0c06b03e */
if(!s->budget--) { s->failed_pc=0x0c06b03eu; return 0; }
r[19]=r[11]*r[12];
goto P_0c06b040;
P_0c06b040: /* original 68b3, guest PC 0x0c06b040 */
if(!s->budget--) { s->failed_pc=0x0c06b040u; return 0; }
r[8]=r[11];
goto P_0c06b042;
P_0c06b042: /* original ed00, guest PC 0x0c06b042 */
if(!s->budget--) { s->failed_pc=0x0c06b042u; return 0; }
r[13]=0x00000000u;
goto P_0c06b044;
P_0c06b044: /* original 4800, guest PC 0x0c06b044 */
if(!s->budget--) { s->failed_pc=0x0c06b044u; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c06b046;
P_0c06b046: /* original 021a, guest PC 0x0c06b046 */
if(!s->budget--) { s->failed_pc=0x0c06b046u; return 0; }
r[2]=r[19];
goto P_0c06b048;
P_0c06b048: /* original 1f21, guest PC 0x0c06b048 */
if(!s->budget--) { s->failed_pc=0x0c06b048u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06b04a;
P_0c06b04a: /* original 6ad3, guest PC 0x0c06b04a */
if(!s->budget--) { s->failed_pc=0x0c06b04au; return 0; }
r[10]=r[13];
goto P_0c06b04c;
P_0c06b04c: /* original 4a08, guest PC 0x0c06b04c */
if(!s->budget--) { s->failed_pc=0x0c06b04cu; return 0; }
r[10]<<=2;
goto P_0c06b04e;
P_0c06b04e: /* original 6583, guest PC 0x0c06b04e */
if(!s->budget--) { s->failed_pc=0x0c06b04eu; return 0; }
r[5]=r[8];
goto P_0c06b050;
P_0c06b050: /* original 64a3, guest PC 0x0c06b050 */
if(!s->budget--) { s->failed_pc=0x0c06b050u; return 0; }
r[4]=r[10];
goto P_0c06b052;
P_0c06b052: /* original e307, guest PC 0x0c06b052 */
if(!s->budget--) { s->failed_pc=0x0c06b052u; return 0; }
r[3]=0x00000007u;
goto P_0c06b054;
P_0c06b054: /* original 750f, guest PC 0x0c06b054 */
if(!s->budget--) { s->failed_pc=0x0c06b054u; return 0; }
r[5]+=0x0000000fu;
goto P_0c06b056;
P_0c06b056: /* original 7409, guest PC 0x0c06b056 */
if(!s->budget--) { s->failed_pc=0x0c06b056u; return 0; }
r[4]+=0x00000009u;
goto P_0c06b058;
P_0c06b058: /* original 453c, guest PC 0x0c06b058 */
if(!s->budget--) { s->failed_pc=0x0c06b058u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c06b05a;
P_0c06b05a: /* original 4400, guest PC 0x0c06b05a */
if(!s->budget--) { s->failed_pc=0x0c06b05au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06b05c;
P_0c06b05c: /* original 245b, guest PC 0x0c06b05c */
if(!s->budget--) { s->failed_pc=0x0c06b05cu; return 0; }
r[4]|=r[5];
goto P_0c06b05e;
P_0c06b05e: /* original d534, guest PC 0x0c06b05e */
if(!s->budget--) { s->failed_pc=0x0c06b05eu; return 0; }
r[5]=read(ram,0x0c06b130u,4);
goto P_0c06b060;
P_0c06b060: /* original 4e0b, guest PC 0x0c06b060 */
if(!s->budget--) { s->failed_pc=0x0c06b060u; return 0; }
target=r[14];
r[16]=code_base|0x0c06b064u;
r[6]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b064u) { target=s->pc; goto dispatch; }
goto P_0c06b064;
P_0c06b062: /* original e603, guest PC 0x0c06b062 */
if(!s->budget--) { s->failed_pc=0x0c06b062u; return 0; }
r[6]=0x00000003u;
goto P_0c06b064;
P_0c06b064: /* original 3db0, guest PC 0x0c06b064 */
if(!s->budget--) { s->failed_pc=0x0c06b064u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[11])!=0);
goto P_0c06b066;
P_0c06b066: /* original 8f13, guest PC 0x0c06b066 */
if(!s->budget--) { s->failed_pc=0x0c06b066u; return 0; }
cond=r[17]&1u;
r[9]=r[0];
if(!cond) { goto P_0c06b090; }
goto P_0c06b06a;
P_0c06b068: /* original 6903, guest PC 0x0c06b068 */
if(!s->budget--) { s->failed_pc=0x0c06b068u; return 0; }
r[9]=r[0];
goto P_0c06b06a;
P_0c06b06a: /* original d532, guest PC 0x0c06b06a */
if(!s->budget--) { s->failed_pc=0x0c06b06au; return 0; }
r[5]=read(ram,0x0c06b134u,4);
goto P_0c06b06c;
P_0c06b06c: /* original e602, guest PC 0x0c06b06c */
if(!s->budget--) { s->failed_pc=0x0c06b06cu; return 0; }
r[6]=0x00000002u;
goto P_0c06b06e;
P_0c06b06e: /* original 4e0b, guest PC 0x0c06b06e */
if(!s->budget--) { s->failed_pc=0x0c06b06eu; return 0; }
target=r[14];
r[16]=code_base|0x0c06b072u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b072u) { target=s->pc; goto dispatch; }
goto P_0c06b072;
P_0c06b070: /* original 6493, guest PC 0x0c06b070 */
if(!s->budget--) { s->failed_pc=0x0c06b070u; return 0; }
r[4]=r[9];
goto P_0c06b072;
P_0c06b072: /* original 6483, guest PC 0x0c06b072 */
if(!s->budget--) { s->failed_pc=0x0c06b072u; return 0; }
r[4]=r[8];
goto P_0c06b074;
P_0c06b074: /* original 65a3, guest PC 0x0c06b074 */
if(!s->budget--) { s->failed_pc=0x0c06b074u; return 0; }
r[5]=r[10];
goto P_0c06b076;
P_0c06b076: /* original e307, guest PC 0x0c06b076 */
if(!s->budget--) { s->failed_pc=0x0c06b076u; return 0; }
r[3]=0x00000007u;
goto P_0c06b078;
P_0c06b078: /* original 740e, guest PC 0x0c06b078 */
if(!s->budget--) { s->failed_pc=0x0c06b078u; return 0; }
r[4]+=0x0000000eu;
goto P_0c06b07a;
P_0c06b07a: /* original 7508, guest PC 0x0c06b07a */
if(!s->budget--) { s->failed_pc=0x0c06b07au; return 0; }
r[5]+=0x00000008u;
goto P_0c06b07c;
P_0c06b07c: /* original 443c, guest PC 0x0c06b07c */
if(!s->budget--) { s->failed_pc=0x0c06b07cu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c06b07e;
P_0c06b07e: /* original 4500, guest PC 0x0c06b07e */
if(!s->budget--) { s->failed_pc=0x0c06b07eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06b080;
P_0c06b080: /* original 245b, guest PC 0x0c06b080 */
if(!s->budget--) { s->failed_pc=0x0c06b080u; return 0; }
r[4]|=r[5];
goto P_0c06b082;
P_0c06b082: /* original d52d, guest PC 0x0c06b082 */
if(!s->budget--) { s->failed_pc=0x0c06b082u; return 0; }
r[5]=read(ram,0x0c06b138u,4);
goto P_0c06b084;
P_0c06b084: /* original 2dd8, guest PC 0x0c06b084 */
if(!s->budget--) { s->failed_pc=0x0c06b084u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c06b086;
P_0c06b086: /* original 8f01, guest PC 0x0c06b086 */
if(!s->budget--) { s->failed_pc=0x0c06b086u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(!cond) { goto P_0c06b08c; }
goto P_0c06b08a;
P_0c06b088: /* original e601, guest PC 0x0c06b088 */
if(!s->budget--) { s->failed_pc=0x0c06b088u; return 0; }
r[6]=0x00000001u;
goto P_0c06b08a;
P_0c06b08a: /* original d52c, guest PC 0x0c06b08a */
if(!s->budget--) { s->failed_pc=0x0c06b08au; return 0; }
r[5]=read(ram,0x0c06b13cu,4);
goto P_0c06b08c;
P_0c06b08c: /* original a02a, guest PC 0x0c06b08c */
if(!s->budget--) { s->failed_pc=0x0c06b08cu; return 0; }
goto P_0c06b0e4;
P_0c06b08e: /* original 0009, guest PC 0x0c06b08e */
if(!s->budget--) { s->failed_pc=0x0c06b08eu; return 0; }
goto P_0c06b090;
P_0c06b090: /* original 52f1, guest PC 0x0c06b090 */
if(!s->budget--) { s->failed_pc=0x0c06b090u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06b092;
P_0c06b092: /* original 6ad3, guest PC 0x0c06b092 */
if(!s->budget--) { s->failed_pc=0x0c06b092u; return 0; }
r[10]=r[13];
goto P_0c06b094;
P_0c06b094: /* original d32a, guest PC 0x0c06b094 */
if(!s->budget--) { s->failed_pc=0x0c06b094u; return 0; }
r[3]=read(ram,0x0c06b140u,4);
goto P_0c06b096;
P_0c06b096: /* original 3a2c, guest PC 0x0c06b096 */
if(!s->budget--) { s->failed_pc=0x0c06b096u; return 0; }
r[10]+=r[2];
goto P_0c06b098;
P_0c06b098: /* original 60f2, guest PC 0x0c06b098 */
if(!s->budget--) { s->failed_pc=0x0c06b098u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c06b09a;
P_0c06b09a: /* original 64a3, guest PC 0x0c06b09a */
if(!s->budget--) { s->failed_pc=0x0c06b09au; return 0; }
r[4]=r[10];
goto P_0c06b09c;
P_0c06b09c: /* original 4408, guest PC 0x0c06b09c */
if(!s->budget--) { s->failed_pc=0x0c06b09cu; return 0; }
r[4]<<=2;
goto P_0c06b09e;
P_0c06b09e: /* original 430b, guest PC 0x0c06b09e */
if(!s->budget--) { s->failed_pc=0x0c06b09eu; return 0; }
target=r[3];
r[16]=code_base|0x0c06b0a2u;
r[4]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b0a2u) { target=s->pc; goto dispatch; }
goto P_0c06b0a2;
P_0c06b0a0: /* original 340c, guest PC 0x0c06b0a0 */
if(!s->budget--) { s->failed_pc=0x0c06b0a0u; return 0; }
r[4]+=r[0];
goto P_0c06b0a2;
P_0c06b0a2: /* original 0dc7, guest PC 0x0c06b0a2 */
if(!s->budget--) { s->failed_pc=0x0c06b0a2u; return 0; }
r[19]=r[13]*r[12];
goto P_0c06b0a4;
P_0c06b0a4: /* original 6ab3, guest PC 0x0c06b0a4 */
if(!s->budget--) { s->failed_pc=0x0c06b0a4u; return 0; }
r[10]=r[11];
goto P_0c06b0a6;
P_0c06b0a6: /* original d326, guest PC 0x0c06b0a6 */
if(!s->budget--) { s->failed_pc=0x0c06b0a6u; return 0; }
r[3]=read(ram,0x0c06b140u,4);
goto P_0c06b0a8;
P_0c06b0a8: /* original 60f2, guest PC 0x0c06b0a8 */
if(!s->budget--) { s->failed_pc=0x0c06b0a8u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c06b0aa;
P_0c06b0aa: /* original ff0c, guest PC 0x0c06b0aa */
if(!s->budget--) { s->failed_pc=0x0c06b0aau; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c06b0ac;
P_0c06b0ac: /* original 041a, guest PC 0x0c06b0ac */
if(!s->budget--) { s->failed_pc=0x0c06b0acu; return 0; }
r[4]=r[19];
goto P_0c06b0ae;
P_0c06b0ae: /* original 3a4c, guest PC 0x0c06b0ae */
if(!s->budget--) { s->failed_pc=0x0c06b0aeu; return 0; }
r[10]+=r[4];
goto P_0c06b0b0;
P_0c06b0b0: /* original 64a3, guest PC 0x0c06b0b0 */
if(!s->budget--) { s->failed_pc=0x0c06b0b0u; return 0; }
r[4]=r[10];
goto P_0c06b0b2;
P_0c06b0b2: /* original 4408, guest PC 0x0c06b0b2 */
if(!s->budget--) { s->failed_pc=0x0c06b0b2u; return 0; }
r[4]<<=2;
goto P_0c06b0b4;
P_0c06b0b4: /* original 430b, guest PC 0x0c06b0b4 */
if(!s->budget--) { s->failed_pc=0x0c06b0b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c06b0b8u;
r[4]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b0b8u) { target=s->pc; goto dispatch; }
goto P_0c06b0b8;
P_0c06b0b6: /* original 340c, guest PC 0x0c06b0b6 */
if(!s->budget--) { s->failed_pc=0x0c06b0b6u; return 0; }
r[4]+=r[0];
goto P_0c06b0b8;
P_0c06b0b8: /* original f40c, guest PC 0x0c06b0b8 */
if(!s->budget--) { s->failed_pc=0x0c06b0b8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06b0ba;
P_0c06b0ba: /* original ff44, guest PC 0x0c06b0ba */
if(!s->budget--) { s->failed_pc=0x0c06b0bau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[4]))!=0);
goto P_0c06b0bc;
P_0c06b0bc: /* original 8b08, guest PC 0x0c06b0bc */
if(!s->budget--) { s->failed_pc=0x0c06b0bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b0d0; }
goto P_0c06b0be;
P_0c06b0be: /* original f38d, guest PC 0x0c06b0be */
if(!s->budget--) { s->failed_pc=0x0c06b0beu; return 0; }
fr[3]=0;
goto P_0c06b0c0;
P_0c06b0c0: /* original f3f4, guest PC 0x0c06b0c0 */
if(!s->budget--) { s->failed_pc=0x0c06b0c0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[15]))!=0);
goto P_0c06b0c2;
P_0c06b0c2: /* original 8b05, guest PC 0x0c06b0c2 */
if(!s->budget--) { s->failed_pc=0x0c06b0c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b0d0; }
goto P_0c06b0c4;
P_0c06b0c4: /* original d51f, guest PC 0x0c06b0c4 */
if(!s->budget--) { s->failed_pc=0x0c06b0c4u; return 0; }
r[5]=read(ram,0x0c06b144u,4);
goto P_0c06b0c6;
P_0c06b0c6: /* original e601, guest PC 0x0c06b0c6 */
if(!s->budget--) { s->failed_pc=0x0c06b0c6u; return 0; }
r[6]=0x00000001u;
goto P_0c06b0c8;
P_0c06b0c8: /* original 4e0b, guest PC 0x0c06b0c8 */
if(!s->budget--) { s->failed_pc=0x0c06b0c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06b0ccu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b0ccu) { target=s->pc; goto dispatch; }
goto P_0c06b0cc;
P_0c06b0ca: /* original 6493, guest PC 0x0c06b0ca */
if(!s->budget--) { s->failed_pc=0x0c06b0cau; return 0; }
r[4]=r[9];
goto P_0c06b0cc;
P_0c06b0cc: /* original a007, guest PC 0x0c06b0cc */
if(!s->budget--) { s->failed_pc=0x0c06b0ccu; return 0; }
goto P_0c06b0de;
P_0c06b0ce: /* original 0009, guest PC 0x0c06b0ce */
if(!s->budget--) { s->failed_pc=0x0c06b0ceu; return 0; }
goto P_0c06b0d0;
P_0c06b0d0: /* original fffb, guest PC 0x0c06b0d0 */
if(!s->budget--) { s->failed_pc=0x0c06b0d0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b0d2;
P_0c06b0d2: /* original d31d, guest PC 0x0c06b0d2 */
if(!s->budget--) { s->failed_pc=0x0c06b0d2u; return 0; }
r[3]=read(ram,0x0c06b148u,4);
goto P_0c06b0d4;
P_0c06b0d4: /* original 2f36, guest PC 0x0c06b0d4 */
if(!s->budget--) { s->failed_pc=0x0c06b0d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b0d6;
P_0c06b0d6: /* original d21d, guest PC 0x0c06b0d6 */
if(!s->budget--) { s->failed_pc=0x0c06b0d6u; return 0; }
r[2]=read(ram,0x0c06b14cu,4);
goto P_0c06b0d8;
P_0c06b0d8: /* original 420b, guest PC 0x0c06b0d8 */
if(!s->budget--) { s->failed_pc=0x0c06b0d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c06b0dcu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b0dcu) { target=s->pc; goto dispatch; }
goto P_0c06b0dc;
P_0c06b0da: /* original 6493, guest PC 0x0c06b0da */
if(!s->budget--) { s->failed_pc=0x0c06b0dau; return 0; }
r[4]=r[9];
goto P_0c06b0dc;
P_0c06b0dc: /* original 7f08, guest PC 0x0c06b0dc */
if(!s->budget--) { s->failed_pc=0x0c06b0dcu; return 0; }
r[15]+=0x00000008u;
goto P_0c06b0de;
P_0c06b0de: /* original d514, guest PC 0x0c06b0de */
if(!s->budget--) { s->failed_pc=0x0c06b0deu; return 0; }
r[5]=read(ram,0x0c06b130u,4);
goto P_0c06b0e0;
P_0c06b0e0: /* original e601, guest PC 0x0c06b0e0 */
if(!s->budget--) { s->failed_pc=0x0c06b0e0u; return 0; }
r[6]=0x00000001u;
goto P_0c06b0e2;
P_0c06b0e2: /* original 6403, guest PC 0x0c06b0e2 */
if(!s->budget--) { s->failed_pc=0x0c06b0e2u; return 0; }
r[4]=r[0];
goto P_0c06b0e4;
P_0c06b0e4: /* original 4e0b, guest PC 0x0c06b0e4 */
if(!s->budget--) { s->failed_pc=0x0c06b0e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c06b0e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b0e8u) { target=s->pc; goto dispatch; }
goto P_0c06b0e8;
P_0c06b0e6: /* original 0009, guest PC 0x0c06b0e6 */
if(!s->budget--) { s->failed_pc=0x0c06b0e6u; return 0; }
goto P_0c06b0e8;
P_0c06b0e8: /* original 7d01, guest PC 0x0c06b0e8 */
if(!s->budget--) { s->failed_pc=0x0c06b0e8u; return 0; }
r[13]+=0x00000001u;
goto P_0c06b0ea;
P_0c06b0ea: /* original 3dc3, guest PC 0x0c06b0ea */
if(!s->budget--) { s->failed_pc=0x0c06b0eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[12])!=0);
goto P_0c06b0ec;
P_0c06b0ec: /* original 8bad, guest PC 0x0c06b0ec */
if(!s->budget--) { s->failed_pc=0x0c06b0ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b04a; }
goto P_0c06b0ee;
P_0c06b0ee: /* original 7b01, guest PC 0x0c06b0ee */
if(!s->budget--) { s->failed_pc=0x0c06b0eeu; return 0; }
r[11]+=0x00000001u;
goto P_0c06b0f0;
P_0c06b0f0: /* original 3bc3, guest PC 0x0c06b0f0 */
if(!s->budget--) { s->failed_pc=0x0c06b0f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[12])!=0);
goto P_0c06b0f2;
P_0c06b0f2: /* original 8ba4, guest PC 0x0c06b0f2 */
if(!s->budget--) { s->failed_pc=0x0c06b0f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b03e; }
goto P_0c06b0f4;
P_0c06b0f4: /* original d50e, guest PC 0x0c06b0f4 */
if(!s->budget--) { s->failed_pc=0x0c06b0f4u; return 0; }
r[5]=read(ram,0x0c06b130u,4);
goto P_0c06b0f6;
P_0c06b0f6: /* original 9411, guest PC 0x0c06b0f6 */
if(!s->budget--) { s->failed_pc=0x0c06b0f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b11cu,2);
goto P_0c06b0f8;
P_0c06b0f8: /* original 4e0b, guest PC 0x0c06b0f8 */
if(!s->budget--) { s->failed_pc=0x0c06b0f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06b0fcu;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b0fcu) { target=s->pc; goto dispatch; }
goto P_0c06b0fc;
P_0c06b0fa: /* original e601, guest PC 0x0c06b0fa */
if(!s->budget--) { s->failed_pc=0x0c06b0fau; return 0; }
r[6]=0x00000001u;
goto P_0c06b0fc;
P_0c06b0fc: /* original 7f08, guest PC 0x0c06b0fc */
if(!s->budget--) { s->failed_pc=0x0c06b0fcu; return 0; }
r[15]+=0x00000008u;
goto P_0c06b0fe;
P_0c06b0fe: /* original 4f16, guest PC 0x0c06b0fe */
if(!s->budget--) { s->failed_pc=0x0c06b0feu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06b100;
P_0c06b100: /* original 4f26, guest PC 0x0c06b100 */
if(!s->budget--) { s->failed_pc=0x0c06b100u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06b102;
P_0c06b102: /* original fff9, guest PC 0x0c06b102 */
if(!s->budget--) { s->failed_pc=0x0c06b102u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b104;
P_0c06b104: /* original 68f6, guest PC 0x0c06b104 */
if(!s->budget--) { s->failed_pc=0x0c06b104u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06b106;
P_0c06b106: /* original 69f6, guest PC 0x0c06b106 */
if(!s->budget--) { s->failed_pc=0x0c06b106u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06b108;
P_0c06b108: /* original 6af6, guest PC 0x0c06b108 */
if(!s->budget--) { s->failed_pc=0x0c06b108u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06b10a;
P_0c06b10a: /* original 6bf6, guest PC 0x0c06b10a */
if(!s->budget--) { s->failed_pc=0x0c06b10au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06b10c;
P_0c06b10c: /* original 6cf6, guest PC 0x0c06b10c */
if(!s->budget--) { s->failed_pc=0x0c06b10cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06b10e;
P_0c06b10e: /* original 6df6, guest PC 0x0c06b10e */
if(!s->budget--) { s->failed_pc=0x0c06b10eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06b110;
P_0c06b110: /* original 000b, guest PC 0x0c06b110 */
if(!s->budget--) { s->failed_pc=0x0c06b110u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06b112: /* original 6ef6, guest PC 0x0c06b112 */
if(!s->budget--) { s->failed_pc=0x0c06b112u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06b114u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06b114u; return 0; } return 1;
P_0c06b150: /* original 2fe6, guest PC 0x0c06b150 */
if(!s->budget--) { s->failed_pc=0x0c06b150u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b152;
P_0c06b152: /* original 2fd6, guest PC 0x0c06b152 */
if(!s->budget--) { s->failed_pc=0x0c06b152u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b154;
P_0c06b154: /* original 2fc6, guest PC 0x0c06b154 */
if(!s->budget--) { s->failed_pc=0x0c06b154u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b156;
P_0c06b156: /* original 2fb6, guest PC 0x0c06b156 */
if(!s->budget--) { s->failed_pc=0x0c06b156u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b158;
P_0c06b158: /* original 2fa6, guest PC 0x0c06b158 */
if(!s->budget--) { s->failed_pc=0x0c06b158u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b15a;
P_0c06b15a: /* original 2f96, guest PC 0x0c06b15a */
if(!s->budget--) { s->failed_pc=0x0c06b15au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b15c;
P_0c06b15c: /* original 2f86, guest PC 0x0c06b15c */
if(!s->budget--) { s->failed_pc=0x0c06b15cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b15e;
P_0c06b15e: /* original fffb, guest PC 0x0c06b15e */
if(!s->budget--) { s->failed_pc=0x0c06b15eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b160;
P_0c06b160: /* original ffeb, guest PC 0x0c06b160 */
if(!s->budget--) { s->failed_pc=0x0c06b160u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06b162;
P_0c06b162: /* original ffdb, guest PC 0x0c06b162 */
if(!s->budget--) { s->failed_pc=0x0c06b162u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06b164;
P_0c06b164: /* original d44d, guest PC 0x0c06b164 */
if(!s->budget--) { s->failed_pc=0x0c06b164u; return 0; }
r[4]=read(ram,0x0c06b29cu,4);
goto P_0c06b166;
P_0c06b166: /* original 9e8e, guest PC 0x0c06b166 */
if(!s->budget--) { s->failed_pc=0x0c06b166u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b286u,2);
goto P_0c06b168;
P_0c06b168: /* original 4f22, guest PC 0x0c06b168 */
if(!s->budget--) { s->failed_pc=0x0c06b168u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06b16a;
P_0c06b16a: /* original 3e4c, guest PC 0x0c06b16a */
if(!s->budget--) { s->failed_pc=0x0c06b16au; return 0; }
r[14]+=r[4];
goto P_0c06b16c;
P_0c06b16c: /* original 948c, guest PC 0x0c06b16c */
if(!s->budget--) { s->failed_pc=0x0c06b16cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b288u,2);
goto P_0c06b16e;
P_0c06b16e: /* original d34d, guest PC 0x0c06b16e */
if(!s->budget--) { s->failed_pc=0x0c06b16eu; return 0; }
r[3]=read(ram,0x0c06b2a4u,4);
goto P_0c06b170;
P_0c06b170: /* original d54b, guest PC 0x0c06b170 */
if(!s->budget--) { s->failed_pc=0x0c06b170u; return 0; }
r[5]=read(ram,0x0c06b2a0u,4);
goto P_0c06b172;
P_0c06b172: /* original 7fec, guest PC 0x0c06b172 */
if(!s->budget--) { s->failed_pc=0x0c06b172u; return 0; }
r[15]+=0xffffffecu;
goto P_0c06b174;
P_0c06b174: /* original 430b, guest PC 0x0c06b174 */
if(!s->budget--) { s->failed_pc=0x0c06b174u; return 0; }
target=r[3];
r[16]=code_base|0x0c06b178u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b178u) { target=s->pc; goto dispatch; }
goto P_0c06b178;
P_0c06b176: /* original e601, guest PC 0x0c06b176 */
if(!s->budget--) { s->failed_pc=0x0c06b176u; return 0; }
r[6]=0x00000001u;
goto P_0c06b178;
P_0c06b178: /* original d24a, guest PC 0x0c06b178 */
if(!s->budget--) { s->failed_pc=0x0c06b178u; return 0; }
r[2]=read(ram,0x0c06b2a4u,4);
goto P_0c06b17a;
P_0c06b17a: /* original 9486, guest PC 0x0c06b17a */
if(!s->budget--) { s->failed_pc=0x0c06b17au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b28au,2);
goto P_0c06b17c;
P_0c06b17c: /* original d54a, guest PC 0x0c06b17c */
if(!s->budget--) { s->failed_pc=0x0c06b17cu; return 0; }
r[5]=read(ram,0x0c06b2a8u,4);
goto P_0c06b17e;
P_0c06b17e: /* original 420b, guest PC 0x0c06b17e */
if(!s->budget--) { s->failed_pc=0x0c06b17eu; return 0; }
target=r[2];
r[16]=code_base|0x0c06b182u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b182u) { target=s->pc; goto dispatch; }
goto P_0c06b182;
P_0c06b180: /* original e601, guest PC 0x0c06b180 */
if(!s->budget--) { s->failed_pc=0x0c06b180u; return 0; }
r[6]=0x00000001u;
goto P_0c06b182;
P_0c06b182: /* original e201, guest PC 0x0c06b182 */
if(!s->budget--) { s->failed_pc=0x0c06b182u; return 0; }
r[2]=0x00000001u;
goto P_0c06b184;
P_0c06b184: /* original e400, guest PC 0x0c06b184 */
if(!s->budget--) { s->failed_pc=0x0c06b184u; return 0; }
r[4]=0x00000000u;
goto P_0c06b186;
P_0c06b186: /* original 1f42, guest PC 0x0c06b186 */
if(!s->budget--) { s->failed_pc=0x0c06b186u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c06b188;
P_0c06b188: /* original 6843, guest PC 0x0c06b188 */
if(!s->budget--) { s->failed_pc=0x0c06b188u; return 0; }
r[8]=r[4];
goto P_0c06b18a;
P_0c06b18a: /* original 937f, guest PC 0x0c06b18a */
if(!s->budget--) { s->failed_pc=0x0c06b18au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b28cu,2);
goto P_0c06b18c;
P_0c06b18c: /* original 33ec, guest PC 0x0c06b18c */
if(!s->budget--) { s->failed_pc=0x0c06b18cu; return 0; }
r[3]+=r[14];
goto P_0c06b18e;
P_0c06b18e: /* original 1f34, guest PC 0x0c06b18e */
if(!s->budget--) { s->failed_pc=0x0c06b18eu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c06b190;
P_0c06b190: /* original dc48, guest PC 0x0c06b190 */
if(!s->budget--) { s->failed_pc=0x0c06b190u; return 0; }
r[12]=read(ram,0x0c06b2b4u,4);
goto P_0c06b192;
P_0c06b192: /* original db47, guest PC 0x0c06b192 */
if(!s->budget--) { s->failed_pc=0x0c06b192u; return 0; }
r[11]=read(ram,0x0c06b2b0u,4);
goto P_0c06b194;
P_0c06b194: /* original da45, guest PC 0x0c06b194 */
if(!s->budget--) { s->failed_pc=0x0c06b194u; return 0; }
r[10]=read(ram,0x0c06b2acu,4);
goto P_0c06b196;
P_0c06b196: /* original 1f23, guest PC 0x0c06b196 */
if(!s->budget--) { s->failed_pc=0x0c06b196u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c06b198;
P_0c06b198: /* original 6483, guest PC 0x0c06b198 */
if(!s->budget--) { s->failed_pc=0x0c06b198u; return 0; }
r[4]=r[8];
goto P_0c06b19a;
P_0c06b19a: /* original 740f, guest PC 0x0c06b19a */
if(!s->budget--) { s->failed_pc=0x0c06b19au; return 0; }
r[4]+=0x0000000fu;
goto P_0c06b19c;
P_0c06b19c: /* original 55f3, guest PC 0x0c06b19c */
if(!s->budget--) { s->failed_pc=0x0c06b19cu; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c06b19e;
P_0c06b19e: /* original 6943, guest PC 0x0c06b19e */
if(!s->budget--) { s->failed_pc=0x0c06b19eu; return 0; }
r[9]=r[4];
goto P_0c06b1a0;
P_0c06b1a0: /* original e307, guest PC 0x0c06b1a0 */
if(!s->budget--) { s->failed_pc=0x0c06b1a0u; return 0; }
r[3]=0x00000007u;
goto P_0c06b1a2;
P_0c06b1a2: /* original 2f56, guest PC 0x0c06b1a2 */
if(!s->budget--) { s->failed_pc=0x0c06b1a2u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b1a4;
P_0c06b1a4: /* original 493c, guest PC 0x0c06b1a4 */
if(!s->budget--) { s->failed_pc=0x0c06b1a4u; return 0; }
r[9]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[9]>>((-r[3])&31u)):((int32_t)r[9]<0?0xffffffffu:0)):r[9]<<(r[3]&31u);
goto P_0c06b1a6;
P_0c06b1a6: /* original d244, guest PC 0x0c06b1a6 */
if(!s->budget--) { s->failed_pc=0x0c06b1a6u; return 0; }
r[2]=read(ram,0x0c06b2b8u,4);
goto P_0c06b1a8;
P_0c06b1a8: /* original ed04, guest PC 0x0c06b1a8 */
if(!s->budget--) { s->failed_pc=0x0c06b1a8u; return 0; }
r[13]=0x00000004u;
goto P_0c06b1aa;
P_0c06b1aa: /* original 2d9b, guest PC 0x0c06b1aa */
if(!s->budget--) { s->failed_pc=0x0c06b1aau; return 0; }
r[13]|=r[9];
goto P_0c06b1ac;
P_0c06b1ac: /* original 2f26, guest PC 0x0c06b1ac */
if(!s->budget--) { s->failed_pc=0x0c06b1acu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b1ae;
P_0c06b1ae: /* original 4b0b, guest PC 0x0c06b1ae */
if(!s->budget--) { s->failed_pc=0x0c06b1aeu; return 0; }
target=r[11];
r[16]=code_base|0x0c06b1b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b1b2u) { target=s->pc; goto dispatch; }
goto P_0c06b1b2;
P_0c06b1b0: /* original 64d3, guest PC 0x0c06b1b0 */
if(!s->budget--) { s->failed_pc=0x0c06b1b0u; return 0; }
r[4]=r[13];
goto P_0c06b1b2;
P_0c06b1b2: /* original d342, guest PC 0x0c06b1b2 */
if(!s->budget--) { s->failed_pc=0x0c06b1b2u; return 0; }
r[3]=read(ram,0x0c06b2bcu,4);
goto P_0c06b1b4;
P_0c06b1b4: /* original 7f08, guest PC 0x0c06b1b4 */
if(!s->budget--) { s->failed_pc=0x0c06b1b4u; return 0; }
r[15]+=0x00000008u;
goto P_0c06b1b6;
P_0c06b1b6: /* original 430b, guest PC 0x0c06b1b6 */
if(!s->budget--) { s->failed_pc=0x0c06b1b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c06b1bau;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b1bau) { target=s->pc; goto dispatch; }
goto P_0c06b1ba;
P_0c06b1b8: /* original 54f4, guest PC 0x0c06b1b8 */
if(!s->budget--) { s->failed_pc=0x0c06b1b8u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c06b1ba;
P_0c06b1ba: /* original 600c, guest PC 0x0c06b1ba */
if(!s->budget--) { s->failed_pc=0x0c06b1bau; return 0; }
r[0]=r[0]&255u;
goto P_0c06b1bc;
P_0c06b1bc: /* original 1f01, guest PC 0x0c06b1bc */
if(!s->budget--) { s->failed_pc=0x0c06b1bcu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06b1be;
P_0c06b1be: /* original e30e, guest PC 0x0c06b1be */
if(!s->budget--) { s->failed_pc=0x0c06b1beu; return 0; }
r[3]=0x0000000eu;
goto P_0c06b1c0;
P_0c06b1c0: /* original 239b, guest PC 0x0c06b1c0 */
if(!s->budget--) { s->failed_pc=0x0c06b1c0u; return 0; }
r[3]|=r[9];
goto P_0c06b1c2;
P_0c06b1c2: /* original 2f32, guest PC 0x0c06b1c2 */
if(!s->budget--) { s->failed_pc=0x0c06b1c2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06b1c4;
P_0c06b1c4: /* original e601, guest PC 0x0c06b1c4 */
if(!s->budget--) { s->failed_pc=0x0c06b1c4u; return 0; }
r[6]=0x00000001u;
goto P_0c06b1c6;
P_0c06b1c6: /* original 5df1, guest PC 0x0c06b1c6 */
if(!s->budget--) { s->failed_pc=0x0c06b1c6u; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c06b1c8;
P_0c06b1c8: /* original d03d, guest PC 0x0c06b1c8 */
if(!s->budget--) { s->failed_pc=0x0c06b1c8u; return 0; }
r[0]=read(ram,0x0c06b2c0u,4);
goto P_0c06b1ca;
P_0c06b1ca: /* original 4d08, guest PC 0x0c06b1ca */
if(!s->budget--) { s->failed_pc=0x0c06b1cau; return 0; }
r[13]<<=2;
goto P_0c06b1cc;
P_0c06b1cc: /* original d235, guest PC 0x0c06b1cc */
if(!s->budget--) { s->failed_pc=0x0c06b1ccu; return 0; }
r[2]=read(ram,0x0c06b2a4u,4);
goto P_0c06b1ce;
P_0c06b1ce: /* original 05de, guest PC 0x0c06b1ce */
if(!s->budget--) { s->failed_pc=0x0c06b1ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c06b1d0;
P_0c06b1d0: /* original 420b, guest PC 0x0c06b1d0 */
if(!s->budget--) { s->failed_pc=0x0c06b1d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c06b1d4u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b1d4u) { target=s->pc; goto dispatch; }
goto P_0c06b1d4;
P_0c06b1d2: /* original 6433, guest PC 0x0c06b1d2 */
if(!s->budget--) { s->failed_pc=0x0c06b1d2u; return 0; }
r[4]=r[3];
goto P_0c06b1d4;
P_0c06b1d4: /* original 945b, guest PC 0x0c06b1d4 */
if(!s->budget--) { s->failed_pc=0x0c06b1d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b28eu,2);
goto P_0c06b1d6;
P_0c06b1d6: /* original 34ec, guest PC 0x0c06b1d6 */
if(!s->budget--) { s->failed_pc=0x0c06b1d6u; return 0; }
r[4]+=r[14];
goto P_0c06b1d8;
P_0c06b1d8: /* original 4c0b, guest PC 0x0c06b1d8 */
if(!s->budget--) { s->failed_pc=0x0c06b1d8u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b1dcu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b1dcu) { target=s->pc; goto dispatch; }
goto P_0c06b1dc;
P_0c06b1da: /* original 34dc, guest PC 0x0c06b1da */
if(!s->budget--) { s->failed_pc=0x0c06b1dau; return 0; }
r[4]+=r[13];
goto P_0c06b1dc;
P_0c06b1dc: /* original 9458, guest PC 0x0c06b1dc */
if(!s->budget--) { s->failed_pc=0x0c06b1dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b290u,2);
goto P_0c06b1de;
P_0c06b1de: /* original fd0c, guest PC 0x0c06b1de */
if(!s->budget--) { s->failed_pc=0x0c06b1deu; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c06b1e0;
P_0c06b1e0: /* original 34ec, guest PC 0x0c06b1e0 */
if(!s->budget--) { s->failed_pc=0x0c06b1e0u; return 0; }
r[4]+=r[14];
goto P_0c06b1e2;
P_0c06b1e2: /* original 4c0b, guest PC 0x0c06b1e2 */
if(!s->budget--) { s->failed_pc=0x0c06b1e2u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b1e6u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b1e6u) { target=s->pc; goto dispatch; }
goto P_0c06b1e6;
P_0c06b1e4: /* original 34dc, guest PC 0x0c06b1e4 */
if(!s->budget--) { s->failed_pc=0x0c06b1e4u; return 0; }
r[4]+=r[13];
goto P_0c06b1e6;
P_0c06b1e6: /* original 9454, guest PC 0x0c06b1e6 */
if(!s->budget--) { s->failed_pc=0x0c06b1e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b292u,2);
goto P_0c06b1e8;
P_0c06b1e8: /* original ff0c, guest PC 0x0c06b1e8 */
if(!s->budget--) { s->failed_pc=0x0c06b1e8u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c06b1ea;
P_0c06b1ea: /* original 34ec, guest PC 0x0c06b1ea */
if(!s->budget--) { s->failed_pc=0x0c06b1eau; return 0; }
r[4]+=r[14];
goto P_0c06b1ec;
P_0c06b1ec: /* original 4c0b, guest PC 0x0c06b1ec */
if(!s->budget--) { s->failed_pc=0x0c06b1ecu; return 0; }
target=r[12];
r[16]=code_base|0x0c06b1f0u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b1f0u) { target=s->pc; goto dispatch; }
goto P_0c06b1f0;
P_0c06b1ee: /* original 34dc, guest PC 0x0c06b1ee */
if(!s->budget--) { s->failed_pc=0x0c06b1eeu; return 0; }
r[4]+=r[13];
goto P_0c06b1f0;
P_0c06b1f0: /* original 9450, guest PC 0x0c06b1f0 */
if(!s->budget--) { s->failed_pc=0x0c06b1f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b294u,2);
goto P_0c06b1f2;
P_0c06b1f2: /* original fe0c, guest PC 0x0c06b1f2 */
if(!s->budget--) { s->failed_pc=0x0c06b1f2u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c06b1f4;
P_0c06b1f4: /* original 34ec, guest PC 0x0c06b1f4 */
if(!s->budget--) { s->failed_pc=0x0c06b1f4u; return 0; }
r[4]+=r[14];
goto P_0c06b1f6;
P_0c06b1f6: /* original 4a0b, guest PC 0x0c06b1f6 */
if(!s->budget--) { s->failed_pc=0x0c06b1f6u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b1fau;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b1fau) { target=s->pc; goto dispatch; }
goto P_0c06b1fa;
P_0c06b1f8: /* original 34dc, guest PC 0x0c06b1f8 */
if(!s->budget--) { s->failed_pc=0x0c06b1f8u; return 0; }
r[4]+=r[13];
goto P_0c06b1fa;
P_0c06b1fa: /* original 2f02, guest PC 0x0c06b1fa */
if(!s->budget--) { s->failed_pc=0x0c06b1fau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06b1fc;
P_0c06b1fc: /* original 944b, guest PC 0x0c06b1fc */
if(!s->budget--) { s->failed_pc=0x0c06b1fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b296u,2);
goto P_0c06b1fe;
P_0c06b1fe: /* original 34ec, guest PC 0x0c06b1fe */
if(!s->budget--) { s->failed_pc=0x0c06b1feu; return 0; }
r[4]+=r[14];
goto P_0c06b200;
P_0c06b200: /* original 4a0b, guest PC 0x0c06b200 */
if(!s->budget--) { s->failed_pc=0x0c06b200u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b204u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b204u) { target=s->pc; goto dispatch; }
goto P_0c06b204;
P_0c06b202: /* original 34dc, guest PC 0x0c06b202 */
if(!s->budget--) { s->failed_pc=0x0c06b202u; return 0; }
r[4]+=r[13];
goto P_0c06b204;
P_0c06b204: /* original 1f01, guest PC 0x0c06b204 */
if(!s->budget--) { s->failed_pc=0x0c06b204u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06b206;
P_0c06b206: /* original 9447, guest PC 0x0c06b206 */
if(!s->budget--) { s->failed_pc=0x0c06b206u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b298u,2);
goto P_0c06b208;
P_0c06b208: /* original 34ec, guest PC 0x0c06b208 */
if(!s->budget--) { s->failed_pc=0x0c06b208u; return 0; }
r[4]+=r[14];
goto P_0c06b20a;
P_0c06b20a: /* original 4a0b, guest PC 0x0c06b20a */
if(!s->budget--) { s->failed_pc=0x0c06b20au; return 0; }
target=r[10];
r[16]=code_base|0x0c06b20eu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b20eu) { target=s->pc; goto dispatch; }
goto P_0c06b20e;
P_0c06b20c: /* original 34dc, guest PC 0x0c06b20c */
if(!s->budget--) { s->failed_pc=0x0c06b20cu; return 0; }
r[4]+=r[13];
goto P_0c06b20e;
P_0c06b20e: /* original f38d, guest PC 0x0c06b20e */
if(!s->budget--) { s->failed_pc=0x0c06b20eu; return 0; }
fr[3]=0;
goto P_0c06b210;
P_0c06b210: /* original f3f4, guest PC 0x0c06b210 */
if(!s->budget--) { s->failed_pc=0x0c06b210u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[15]))!=0);
goto P_0c06b212;
P_0c06b212: /* original 6703, guest PC 0x0c06b212 */
if(!s->budget--) { s->failed_pc=0x0c06b212u; return 0; }
r[7]=r[0];
goto P_0c06b214;
P_0c06b214: /* original e081, guest PC 0x0c06b214 */
if(!s->budget--) { s->failed_pc=0x0c06b214u; return 0; }
r[0]=0xffffff81u;
goto P_0c06b216;
P_0c06b216: /* original 2099, guest PC 0x0c06b216 */
if(!s->budget--) { s->failed_pc=0x0c06b216u; return 0; }
r[0]&=r[9];
goto P_0c06b218;
P_0c06b218: /* original ed1e, guest PC 0x0c06b218 */
if(!s->budget--) { s->failed_pc=0x0c06b218u; return 0; }
r[13]=0x0000001eu;
goto P_0c06b21a;
P_0c06b21a: /* original 8d0e, guest PC 0x0c06b21a */
if(!s->budget--) { s->failed_pc=0x0c06b21au; return 0; }
cond=r[17]&1u;
r[13]|=r[0];
if(cond) { goto P_0c06b23a; }
goto P_0c06b21e;
P_0c06b21c: /* original 2d0b, guest PC 0x0c06b21c */
if(!s->budget--) { s->failed_pc=0x0c06b21cu; return 0; }
r[13]|=r[0];
goto P_0c06b21e;
P_0c06b21e: /* original 2f76, guest PC 0x0c06b21e */
if(!s->budget--) { s->failed_pc=0x0c06b21eu; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b220;
P_0c06b220: /* original 52f2, guest PC 0x0c06b220 */
if(!s->budget--) { s->failed_pc=0x0c06b220u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06b222;
P_0c06b222: /* original 2f26, guest PC 0x0c06b222 */
if(!s->budget--) { s->failed_pc=0x0c06b222u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b224;
P_0c06b224: /* original 53f2, guest PC 0x0c06b224 */
if(!s->budget--) { s->failed_pc=0x0c06b224u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06b226;
P_0c06b226: /* original 2f36, guest PC 0x0c06b226 */
if(!s->budget--) { s->failed_pc=0x0c06b226u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b228;
P_0c06b228: /* original ffeb, guest PC 0x0c06b228 */
if(!s->budget--) { s->failed_pc=0x0c06b228u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06b22a;
P_0c06b22a: /* original fffb, guest PC 0x0c06b22a */
if(!s->budget--) { s->failed_pc=0x0c06b22au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b22c;
P_0c06b22c: /* original ffdb, guest PC 0x0c06b22c */
if(!s->budget--) { s->failed_pc=0x0c06b22cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06b22e;
P_0c06b22e: /* original d325, guest PC 0x0c06b22e */
if(!s->budget--) { s->failed_pc=0x0c06b22eu; return 0; }
r[3]=read(ram,0x0c06b2c4u,4);
goto P_0c06b230;
P_0c06b230: /* original 2f36, guest PC 0x0c06b230 */
if(!s->budget--) { s->failed_pc=0x0c06b230u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b232;
P_0c06b232: /* original 4b0b, guest PC 0x0c06b232 */
if(!s->budget--) { s->failed_pc=0x0c06b232u; return 0; }
target=r[11];
r[16]=code_base|0x0c06b236u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b236u) { target=s->pc; goto dispatch; }
goto P_0c06b236;
P_0c06b234: /* original 64d3, guest PC 0x0c06b234 */
if(!s->budget--) { s->failed_pc=0x0c06b234u; return 0; }
r[4]=r[13];
goto P_0c06b236;
P_0c06b236: /* original a00c, guest PC 0x0c06b236 */
if(!s->budget--) { s->failed_pc=0x0c06b236u; return 0; }
r[15]+=0x0000001cu;
goto P_0c06b252;
P_0c06b238: /* original 7f1c, guest PC 0x0c06b238 */
if(!s->budget--) { s->failed_pc=0x0c06b238u; return 0; }
r[15]+=0x0000001cu;
goto P_0c06b23a;
P_0c06b23a: /* original 2f76, guest PC 0x0c06b23a */
if(!s->budget--) { s->failed_pc=0x0c06b23au; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b23c;
P_0c06b23c: /* original 53f2, guest PC 0x0c06b23c */
if(!s->budget--) { s->failed_pc=0x0c06b23cu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06b23e;
P_0c06b23e: /* original 2f36, guest PC 0x0c06b23e */
if(!s->budget--) { s->failed_pc=0x0c06b23eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b240;
P_0c06b240: /* original 52f2, guest PC 0x0c06b240 */
if(!s->budget--) { s->failed_pc=0x0c06b240u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06b242;
P_0c06b242: /* original 2f26, guest PC 0x0c06b242 */
if(!s->budget--) { s->failed_pc=0x0c06b242u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b244;
P_0c06b244: /* original ffeb, guest PC 0x0c06b244 */
if(!s->budget--) { s->failed_pc=0x0c06b244u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06b246;
P_0c06b246: /* original fffb, guest PC 0x0c06b246 */
if(!s->budget--) { s->failed_pc=0x0c06b246u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b248;
P_0c06b248: /* original d31f, guest PC 0x0c06b248 */
if(!s->budget--) { s->failed_pc=0x0c06b248u; return 0; }
r[3]=read(ram,0x0c06b2c8u,4);
goto P_0c06b24a;
P_0c06b24a: /* original 2f36, guest PC 0x0c06b24a */
if(!s->budget--) { s->failed_pc=0x0c06b24au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b24c;
P_0c06b24c: /* original 4b0b, guest PC 0x0c06b24c */
if(!s->budget--) { s->failed_pc=0x0c06b24cu; return 0; }
target=r[11];
r[16]=code_base|0x0c06b250u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b250u) { target=s->pc; goto dispatch; }
goto P_0c06b250;
P_0c06b24e: /* original 64d3, guest PC 0x0c06b24e */
if(!s->budget--) { s->failed_pc=0x0c06b24eu; return 0; }
r[4]=r[13];
goto P_0c06b250;
P_0c06b250: /* original 7f18, guest PC 0x0c06b250 */
if(!s->budget--) { s->failed_pc=0x0c06b250u; return 0; }
r[15]+=0x00000018u;
goto P_0c06b252;
P_0c06b252: /* original 52f2, guest PC 0x0c06b252 */
if(!s->budget--) { s->failed_pc=0x0c06b252u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06b254;
P_0c06b254: /* original 7201, guest PC 0x0c06b254 */
if(!s->budget--) { s->failed_pc=0x0c06b254u; return 0; }
r[2]+=0x00000001u;
goto P_0c06b256;
P_0c06b256: /* original 1f22, guest PC 0x0c06b256 */
if(!s->budget--) { s->failed_pc=0x0c06b256u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c06b258;
P_0c06b258: /* original 53f4, guest PC 0x0c06b258 */
if(!s->budget--) { s->failed_pc=0x0c06b258u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c06b25a;
P_0c06b25a: /* original 7301, guest PC 0x0c06b25a */
if(!s->budget--) { s->failed_pc=0x0c06b25au; return 0; }
r[3]+=0x00000001u;
goto P_0c06b25c;
P_0c06b25c: /* original 1f34, guest PC 0x0c06b25c */
if(!s->budget--) { s->failed_pc=0x0c06b25cu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c06b25e;
P_0c06b25e: /* original e30d, guest PC 0x0c06b25e */
if(!s->budget--) { s->failed_pc=0x0c06b25eu; return 0; }
r[3]=0x0000000du;
goto P_0c06b260;
P_0c06b260: /* original 51f3, guest PC 0x0c06b260 */
if(!s->budget--) { s->failed_pc=0x0c06b260u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c06b262;
P_0c06b262: /* original 3233, guest PC 0x0c06b262 */
if(!s->budget--) { s->failed_pc=0x0c06b262u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c06b264;
P_0c06b264: /* original 7101, guest PC 0x0c06b264 */
if(!s->budget--) { s->failed_pc=0x0c06b264u; return 0; }
r[1]+=0x00000001u;
goto P_0c06b266;
P_0c06b266: /* original 1f13, guest PC 0x0c06b266 */
if(!s->budget--) { s->failed_pc=0x0c06b266u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c06b268;
P_0c06b268: /* original 8f96, guest PC 0x0c06b268 */
if(!s->budget--) { s->failed_pc=0x0c06b268u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000002u;
if(!cond) { goto P_0c06b198; }
goto P_0c06b26c;
P_0c06b26a: /* original 7802, guest PC 0x0c06b26a */
if(!s->budget--) { s->failed_pc=0x0c06b26au; return 0; }
r[8]+=0x00000002u;
goto P_0c06b26c;
P_0c06b26c: /* original 7f14, guest PC 0x0c06b26c */
if(!s->budget--) { s->failed_pc=0x0c06b26cu; return 0; }
r[15]+=0x00000014u;
goto P_0c06b26e;
P_0c06b26e: /* original 4f26, guest PC 0x0c06b26e */
if(!s->budget--) { s->failed_pc=0x0c06b26eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06b270;
P_0c06b270: /* original fdf9, guest PC 0x0c06b270 */
if(!s->budget--) { s->failed_pc=0x0c06b270u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b272;
P_0c06b272: /* original fef9, guest PC 0x0c06b272 */
if(!s->budget--) { s->failed_pc=0x0c06b272u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b274;
P_0c06b274: /* original fff9, guest PC 0x0c06b274 */
if(!s->budget--) { s->failed_pc=0x0c06b274u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b276;
P_0c06b276: /* original 68f6, guest PC 0x0c06b276 */
if(!s->budget--) { s->failed_pc=0x0c06b276u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06b278;
P_0c06b278: /* original 69f6, guest PC 0x0c06b278 */
if(!s->budget--) { s->failed_pc=0x0c06b278u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06b27a;
P_0c06b27a: /* original 6af6, guest PC 0x0c06b27a */
if(!s->budget--) { s->failed_pc=0x0c06b27au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06b27c;
P_0c06b27c: /* original 6bf6, guest PC 0x0c06b27c */
if(!s->budget--) { s->failed_pc=0x0c06b27cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06b27e;
P_0c06b27e: /* original 6cf6, guest PC 0x0c06b27e */
if(!s->budget--) { s->failed_pc=0x0c06b27eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06b280;
P_0c06b280: /* original 6df6, guest PC 0x0c06b280 */
if(!s->budget--) { s->failed_pc=0x0c06b280u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06b282;
P_0c06b282: /* original 000b, guest PC 0x0c06b282 */
if(!s->budget--) { s->failed_pc=0x0c06b282u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06b284: /* original 6ef6, guest PC 0x0c06b284 */
if(!s->budget--) { s->failed_pc=0x0c06b284u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06b286u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06b286u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
