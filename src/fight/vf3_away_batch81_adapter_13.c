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
int vf3_away_batch81_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ad578u: goto P_0c0ad578;
case 0x0c0ad57au: goto P_0c0ad57a;
case 0x0c0ad57cu: goto P_0c0ad57c;
case 0x0c0ad57eu: goto P_0c0ad57e;
case 0x0c0ad580u: goto P_0c0ad580;
case 0x0c0ad582u: goto P_0c0ad582;
case 0x0c0ad584u: goto P_0c0ad584;
case 0x0c0ad586u: goto P_0c0ad586;
case 0x0c0ad588u: goto P_0c0ad588;
case 0x0c0ae0a4u: goto P_0c0ae0a4;
case 0x0c0ae0a6u: goto P_0c0ae0a6;
case 0x0c0ae0a8u: goto P_0c0ae0a8;
case 0x0c0ae0aau: goto P_0c0ae0aa;
case 0x0c0ae0acu: goto P_0c0ae0ac;
case 0x0c0ae0aeu: goto P_0c0ae0ae;
case 0x0c0ae0b0u: goto P_0c0ae0b0;
case 0x0c0ae0b2u: goto P_0c0ae0b2;
case 0x0c0ae0b4u: goto P_0c0ae0b4;
case 0x0c0ae0b6u: goto P_0c0ae0b6;
case 0x0c0ae0b8u: goto P_0c0ae0b8;
case 0x0c0ae0bau: goto P_0c0ae0ba;
case 0x0c0ae0bcu: goto P_0c0ae0bc;
case 0x0c0ae0beu: goto P_0c0ae0be;
case 0x0c0ae0c0u: goto P_0c0ae0c0;
case 0x0c0ae0c2u: goto P_0c0ae0c2;
case 0x0c0ae0c4u: goto P_0c0ae0c4;
case 0x0c0ae0c6u: goto P_0c0ae0c6;
case 0x0c0ae0c8u: goto P_0c0ae0c8;
case 0x0c0ae0cau: goto P_0c0ae0ca;
case 0x0c0ae0ccu: goto P_0c0ae0cc;
case 0x0c0ae0ceu: goto P_0c0ae0ce;
case 0x0c0ae0d0u: goto P_0c0ae0d0;
case 0x0c0ae0d2u: goto P_0c0ae0d2;
case 0x0c0ae0d4u: goto P_0c0ae0d4;
case 0x0c0ae0d6u: goto P_0c0ae0d6;
case 0x0c0ae0d8u: goto P_0c0ae0d8;
case 0x0c0ae0dau: goto P_0c0ae0da;
case 0x0c0ae0dcu: goto P_0c0ae0dc;
case 0x0c0ae0deu: goto P_0c0ae0de;
case 0x0c0ae0e0u: goto P_0c0ae0e0;
case 0x0c0ae0e2u: goto P_0c0ae0e2;
case 0x0c0ae0e4u: goto P_0c0ae0e4;
case 0x0c0ae0e6u: goto P_0c0ae0e6;
case 0x0c0ae0e8u: goto P_0c0ae0e8;
case 0x0c0ae0eau: goto P_0c0ae0ea;
case 0x0c0ae0ecu: goto P_0c0ae0ec;
case 0x0c0ae0eeu: goto P_0c0ae0ee;
case 0x0c0ae0f0u: goto P_0c0ae0f0;
case 0x0c0ae0f2u: goto P_0c0ae0f2;
case 0x0c0ae0f4u: goto P_0c0ae0f4;
case 0x0c0ae0f6u: goto P_0c0ae0f6;
case 0x0c0ae0f8u: goto P_0c0ae0f8;
case 0x0c0ae0fau: goto P_0c0ae0fa;
case 0x0c0ae0fcu: goto P_0c0ae0fc;
case 0x0c0ae0feu: goto P_0c0ae0fe;
case 0x0c0ae100u: goto P_0c0ae100;
case 0x0c0ae102u: goto P_0c0ae102;
case 0x0c0ae104u: goto P_0c0ae104;
case 0x0c0ae106u: goto P_0c0ae106;
case 0x0c0ae108u: goto P_0c0ae108;
case 0x0c0ae10au: goto P_0c0ae10a;
case 0x0c0ae10cu: goto P_0c0ae10c;
case 0x0c0ae10eu: goto P_0c0ae10e;
case 0x0c0ae110u: goto P_0c0ae110;
case 0x0c0ae112u: goto P_0c0ae112;
case 0x0c0ae114u: goto P_0c0ae114;
case 0x0c0ae116u: goto P_0c0ae116;
case 0x0c0ae118u: goto P_0c0ae118;
case 0x0c0ae11au: goto P_0c0ae11a;
case 0x0c0ae11cu: goto P_0c0ae11c;
case 0x0c0ae11eu: goto P_0c0ae11e;
case 0x0c0ae120u: goto P_0c0ae120;
case 0x0c0ae122u: goto P_0c0ae122;
case 0x0c0ae124u: goto P_0c0ae124;
case 0x0c0ae126u: goto P_0c0ae126;
case 0x0c0ae128u: goto P_0c0ae128;
case 0x0c0ae12au: goto P_0c0ae12a;
case 0x0c0ae12cu: goto P_0c0ae12c;
case 0x0c0ae12eu: goto P_0c0ae12e;
case 0x0c0ae130u: goto P_0c0ae130;
case 0x0c0ae132u: goto P_0c0ae132;
case 0x0c0ae134u: goto P_0c0ae134;
case 0x0c0ae136u: goto P_0c0ae136;
case 0x0c0ae138u: goto P_0c0ae138;
case 0x0c0ae13au: goto P_0c0ae13a;
case 0x0c0ae13cu: goto P_0c0ae13c;
case 0x0c0ae13eu: goto P_0c0ae13e;
case 0x0c0ae140u: goto P_0c0ae140;
case 0x0c0ae142u: goto P_0c0ae142;
case 0x0c0ae144u: goto P_0c0ae144;
case 0x0c0ae146u: goto P_0c0ae146;
case 0x0c0ae148u: goto P_0c0ae148;
case 0x0c0ae14au: goto P_0c0ae14a;
case 0x0c0ae14cu: goto P_0c0ae14c;
case 0x0c0ae14eu: goto P_0c0ae14e;
case 0x0c0ae150u: goto P_0c0ae150;
case 0x0c0ae152u: goto P_0c0ae152;
case 0x0c0ae154u: goto P_0c0ae154;
case 0x0c0ae156u: goto P_0c0ae156;
case 0x0c0ae158u: goto P_0c0ae158;
case 0x0c0ae15au: goto P_0c0ae15a;
case 0x0c0ae15cu: goto P_0c0ae15c;
case 0x0c0ae15eu: goto P_0c0ae15e;
case 0x0c0ae184u: goto P_0c0ae184;
case 0x0c0ae186u: goto P_0c0ae186;
case 0x0c0ae188u: goto P_0c0ae188;
case 0x0c0ae18au: goto P_0c0ae18a;
case 0x0c0ae18cu: goto P_0c0ae18c;
case 0x0c0ae18eu: goto P_0c0ae18e;
case 0x0c0ae190u: goto P_0c0ae190;
case 0x0c0ae192u: goto P_0c0ae192;
case 0x0c0ae194u: goto P_0c0ae194;
case 0x0c0ae196u: goto P_0c0ae196;
case 0x0c0ae198u: goto P_0c0ae198;
case 0x0c0ae19au: goto P_0c0ae19a;
case 0x0c0ae19cu: goto P_0c0ae19c;
case 0x0c0ae19eu: goto P_0c0ae19e;
case 0x0c0ae1a0u: goto P_0c0ae1a0;
case 0x0c0ae1a2u: goto P_0c0ae1a2;
case 0x0c0ae1a4u: goto P_0c0ae1a4;
case 0x0c0ae1a6u: goto P_0c0ae1a6;
case 0x0c0ae1a8u: goto P_0c0ae1a8;
case 0x0c0ae1aau: goto P_0c0ae1aa;
case 0x0c0ae1acu: goto P_0c0ae1ac;
case 0x0c0ae1aeu: goto P_0c0ae1ae;
case 0x0c0ae1b0u: goto P_0c0ae1b0;
case 0x0c0ae1b2u: goto P_0c0ae1b2;
case 0x0c0ae1b4u: goto P_0c0ae1b4;
case 0x0c0ae1b6u: goto P_0c0ae1b6;
case 0x0c0ae1b8u: goto P_0c0ae1b8;
case 0x0c0ae1bau: goto P_0c0ae1ba;
case 0x0c0ae1bcu: goto P_0c0ae1bc;
case 0x0c0ae1beu: goto P_0c0ae1be;
case 0x0c0ae1c0u: goto P_0c0ae1c0;
case 0x0c0ae1c2u: goto P_0c0ae1c2;
case 0x0c0ae1c4u: goto P_0c0ae1c4;
case 0x0c0ae1c6u: goto P_0c0ae1c6;
case 0x0c0ae1c8u: goto P_0c0ae1c8;
case 0x0c0ae1cau: goto P_0c0ae1ca;
case 0x0c0ae1ccu: goto P_0c0ae1cc;
case 0x0c0ae1ceu: goto P_0c0ae1ce;
case 0x0c0ae1d0u: goto P_0c0ae1d0;
case 0x0c0ae1d2u: goto P_0c0ae1d2;
case 0x0c0ae1d4u: goto P_0c0ae1d4;
case 0x0c0ae1d6u: goto P_0c0ae1d6;
case 0x0c0ae1d8u: goto P_0c0ae1d8;
case 0x0c0ae1dau: goto P_0c0ae1da;
case 0x0c0ae1dcu: goto P_0c0ae1dc;
case 0x0c0ae1deu: goto P_0c0ae1de;
case 0x0c0ae1e0u: goto P_0c0ae1e0;
case 0x0c0ae1e2u: goto P_0c0ae1e2;
case 0x0c0ae1e4u: goto P_0c0ae1e4;
case 0x0c0ae1e6u: goto P_0c0ae1e6;
case 0x0c0ae1e8u: goto P_0c0ae1e8;
case 0x0c0ae1eau: goto P_0c0ae1ea;
case 0x0c0ae1ecu: goto P_0c0ae1ec;
case 0x0c0ae1eeu: goto P_0c0ae1ee;
case 0x0c0ae1f0u: goto P_0c0ae1f0;
case 0x0c0ae1f2u: goto P_0c0ae1f2;
case 0x0c0ae1f4u: goto P_0c0ae1f4;
case 0x0c0ae1f6u: goto P_0c0ae1f6;
case 0x0c0ae1f8u: goto P_0c0ae1f8;
case 0x0c0ae1fau: goto P_0c0ae1fa;
case 0x0c0ae1fcu: goto P_0c0ae1fc;
case 0x0c0ae1feu: goto P_0c0ae1fe;
case 0x0c0ae200u: goto P_0c0ae200;
case 0x0c0ae202u: goto P_0c0ae202;
case 0x0c0ae204u: goto P_0c0ae204;
case 0x0c0ae206u: goto P_0c0ae206;
case 0x0c0ae208u: goto P_0c0ae208;
case 0x0c0ae20au: goto P_0c0ae20a;
case 0x0c0ae20cu: goto P_0c0ae20c;
case 0x0c0ae20eu: goto P_0c0ae20e;
case 0x0c0ae210u: goto P_0c0ae210;
case 0x0c0ae212u: goto P_0c0ae212;
case 0x0c0ae214u: goto P_0c0ae214;
case 0x0c0ae216u: goto P_0c0ae216;
case 0x0c0ae218u: goto P_0c0ae218;
case 0x0c0ae21au: goto P_0c0ae21a;
case 0x0c0ae21cu: goto P_0c0ae21c;
case 0x0c0ae21eu: goto P_0c0ae21e;
case 0x0c0ae220u: goto P_0c0ae220;
case 0x0c0ae222u: goto P_0c0ae222;
case 0x0c0ae224u: goto P_0c0ae224;
case 0x0c0ae226u: goto P_0c0ae226;
case 0x0c0ae228u: goto P_0c0ae228;
case 0x0c0ae22au: goto P_0c0ae22a;
case 0x0c0ae22cu: goto P_0c0ae22c;
case 0x0c0ae22eu: goto P_0c0ae22e;
case 0x0c0ae230u: goto P_0c0ae230;
case 0x0c0ae232u: goto P_0c0ae232;
case 0x0c0ae234u: goto P_0c0ae234;
case 0x0c0ae236u: goto P_0c0ae236;
case 0x0c0ae238u: goto P_0c0ae238;
case 0x0c0ae23au: goto P_0c0ae23a;
case 0x0c0ae23cu: goto P_0c0ae23c;
case 0x0c0ae23eu: goto P_0c0ae23e;
case 0x0c0ae240u: goto P_0c0ae240;
case 0x0c0ae242u: goto P_0c0ae242;
case 0x0c0ae244u: goto P_0c0ae244;
case 0x0c0ae246u: goto P_0c0ae246;
case 0x0c0ae248u: goto P_0c0ae248;
case 0x0c0ae24au: goto P_0c0ae24a;
case 0x0c0ae24cu: goto P_0c0ae24c;
case 0x0c0ae24eu: goto P_0c0ae24e;
case 0x0c0ae250u: goto P_0c0ae250;
case 0x0c0ae252u: goto P_0c0ae252;
case 0x0c0ae254u: goto P_0c0ae254;
case 0x0c0ae256u: goto P_0c0ae256;
case 0x0c0ae258u: goto P_0c0ae258;
case 0x0c0ae25au: goto P_0c0ae25a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ad578: /* original 6360, guest PC 0x0c0ad578 */
if(!s->budget--) { s->failed_pc=0x0c0ad578u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0ad57a;
P_0c0ad57a: /* original 7ffc, guest PC 0x0c0ad57a */
if(!s->budget--) { s->failed_pc=0x0c0ad57au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad57c;
P_0c0ad57c: /* original d007, guest PC 0x0c0ad57c */
if(!s->budget--) { s->failed_pc=0x0c0ad57cu; return 0; }
r[0]=read(ram,0x0c0ad59cu,4);
goto P_0c0ad57e;
P_0c0ad57e: /* original 633c, guest PC 0x0c0ad57e */
if(!s->budget--) { s->failed_pc=0x0c0ad57eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad580;
P_0c0ad580: /* original 4308, guest PC 0x0c0ad580 */
if(!s->budget--) { s->failed_pc=0x0c0ad580u; return 0; }
r[3]<<=2;
goto P_0c0ad582;
P_0c0ad582: /* original 023e, guest PC 0x0c0ad582 */
if(!s->budget--) { s->failed_pc=0x0c0ad582u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0ad584;
P_0c0ad584: /* original 2f22, guest PC 0x0c0ad584 */
if(!s->budget--) { s->failed_pc=0x0c0ad584u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ad586;
P_0c0ad586: /* original 422b, guest PC 0x0c0ad586 */
if(!s->budget--) { s->failed_pc=0x0c0ad586u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ad588: /* original 7f04, guest PC 0x0c0ad588 */
if(!s->budget--) { s->failed_pc=0x0c0ad588u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ad58au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad58au; return 0; } return 1;
P_0c0ae0a4: /* original 925d, guest PC 0x0c0ae0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0a4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae162u,2);
goto P_0c0ae0a6;
P_0c0ae0a6: /* original d333, guest PC 0x0c0ae0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0a6u; return 0; }
r[3]=read(ram,0x0c0ae174u,4);
goto P_0c0ae0a8;
P_0c0ae0a8: /* original 915c, guest PC 0x0c0ae0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0a8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae164u,2);
goto P_0c0ae0aa;
P_0c0ae0aa: /* original 2429, guest PC 0x0c0ae0aa */
if(!s->budget--) { s->failed_pc=0x0c0ae0aau; return 0; }
r[4]&=r[2];
goto P_0c0ae0ac;
P_0c0ae0ac: /* original 6632, guest PC 0x0c0ae0ac */
if(!s->budget--) { s->failed_pc=0x0c0ae0acu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0ae0ae;
P_0c0ae0ae: /* original 3412, guest PC 0x0c0ae0ae */
if(!s->budget--) { s->failed_pc=0x0c0ae0aeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[1])!=0);
goto P_0c0ae0b0;
P_0c0ae0b0: /* original 8919, guest PC 0x0c0ae0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0b2;
P_0c0ae0b2: /* original 6043, guest PC 0x0c0ae0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b2u; return 0; }
r[0]=r[4];
goto P_0c0ae0b4;
P_0c0ae0b4: /* original 70ff, guest PC 0x0c0ae0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b4u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0ae0b6;
P_0c0ae0b6: /* original 4008, guest PC 0x0c0ae0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b6u; return 0; }
r[0]<<=2;
goto P_0c0ae0b8;
P_0c0ae0b8: /* original 036e, guest PC 0x0c0ae0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0b8u; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c0ae0ba;
P_0c0ae0ba: /* original 6433, guest PC 0x0c0ae0ba */
if(!s->budget--) { s->failed_pc=0x0c0ae0bau; return 0; }
r[4]=r[3];
goto P_0c0ae0bc;
P_0c0ae0bc: /* original 346c, guest PC 0x0c0ae0bc */
if(!s->budget--) { s->failed_pc=0x0c0ae0bcu; return 0; }
r[4]+=r[6];
goto P_0c0ae0be;
P_0c0ae0be: /* original 6643, guest PC 0x0c0ae0be */
if(!s->budget--) { s->failed_pc=0x0c0ae0beu; return 0; }
r[6]=r[4];
goto P_0c0ae0c0;
P_0c0ae0c0: /* original 760c, guest PC 0x0c0ae0c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0ae0c2;
P_0c0ae0c2: /* original 6460, guest PC 0x0c0ae0c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[4]=tmp;
goto P_0c0ae0c4;
P_0c0ae0c4: /* original 644c, guest PC 0x0c0ae0c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c4u; return 0; }
r[4]=r[4]&255u;
goto P_0c0ae0c6;
P_0c0ae0c6: /* original 3450, guest PC 0x0c0ae0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0ae0c8;
P_0c0ae0c8: /* original 8b01, guest PC 0x0c0ae0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae0ce; }
goto P_0c0ae0ca;
P_0c0ae0ca: /* original 000b, guest PC 0x0c0ae0ca */
if(!s->budget--) { s->failed_pc=0x0c0ae0cau; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c0ae0cc: /* original 6063, guest PC 0x0c0ae0cc */
if(!s->budget--) { s->failed_pc=0x0c0ae0ccu; return 0; }
r[0]=r[6];
goto P_0c0ae0ce;
P_0c0ae0ce: /* original 2448, guest PC 0x0c0ae0ce */
if(!s->budget--) { s->failed_pc=0x0c0ae0ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ae0d0;
P_0c0ae0d0: /* original 8909, guest PC 0x0c0ae0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0d2;
P_0c0ae0d2: /* original 6043, guest PC 0x0c0ae0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d2u; return 0; }
r[0]=r[4];
goto P_0c0ae0d4;
P_0c0ae0d4: /* original 8808, guest PC 0x0c0ae0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0ae0d6;
P_0c0ae0d6: /* original 8906, guest PC 0x0c0ae0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0d8;
P_0c0ae0d8: /* original e316, guest PC 0x0c0ae0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0d8u; return 0; }
r[3]=0x00000016u;
goto P_0c0ae0da;
P_0c0ae0da: /* original 3436, guest PC 0x0c0ae0da */
if(!s->budget--) { s->failed_pc=0x0c0ae0dau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c0ae0dc;
P_0c0ae0dc: /* original 8903, guest PC 0x0c0ae0dc */
if(!s->budget--) { s->failed_pc=0x0c0ae0dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae0e6; }
goto P_0c0ae0de;
P_0c0ae0de: /* original d026, guest PC 0x0c0ae0de */
if(!s->budget--) { s->failed_pc=0x0c0ae0deu; return 0; }
r[0]=read(ram,0x0c0ae178u,4);
goto P_0c0ae0e0;
P_0c0ae0e0: /* original 034c, guest PC 0x0c0ae0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ae0e2;
P_0c0ae0e2: /* original afee, guest PC 0x0c0ae0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e2u; return 0; }
r[6]+=r[3];
goto P_0c0ae0c2;
P_0c0ae0e4: /* original 363c, guest PC 0x0c0ae0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e4u; return 0; }
r[6]+=r[3];
goto P_0c0ae0e6;
P_0c0ae0e6: /* original e000, guest PC 0x0c0ae0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e6u; return 0; }
r[0]=0x00000000u;
goto P_0c0ae0e8;
P_0c0ae0e8: /* original 000b, guest PC 0x0c0ae0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ae0ea: /* original 0009, guest PC 0x0c0ae0ea */
if(!s->budget--) { s->failed_pc=0x0c0ae0eau; return 0; }
goto P_0c0ae0ec;
P_0c0ae0ec: /* original 2fe6, guest PC 0x0c0ae0ec */
if(!s->budget--) { s->failed_pc=0x0c0ae0ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae0ee;
P_0c0ae0ee: /* original e03e, guest PC 0x0c0ae0ee */
if(!s->budget--) { s->failed_pc=0x0c0ae0eeu; return 0; }
r[0]=0x0000003eu;
goto P_0c0ae0f0;
P_0c0ae0f0: /* original 2fd6, guest PC 0x0c0ae0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae0f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae0f2;
P_0c0ae0f2: /* original 6e43, guest PC 0x0c0ae0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae0f2u; return 0; }
r[14]=r[4];
goto P_0c0ae0f4;
P_0c0ae0f4: /* original 4f22, guest PC 0x0c0ae0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae0f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae0f6;
P_0c0ae0f6: /* original 7fe8, guest PC 0x0c0ae0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae0f6u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0ae0f8;
P_0c0ae0f8: /* original 2f52, guest PC 0x0c0ae0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae0f8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ae0fa;
P_0c0ae0fa: /* original 04ed, guest PC 0x0c0ae0fa */
if(!s->budget--) { s->failed_pc=0x0c0ae0fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae0fc;
P_0c0ae0fc: /* original 9033, guest PC 0x0c0ae0fc */
if(!s->budget--) { s->failed_pc=0x0c0ae0fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae166u,2);
goto P_0c0ae0fe;
P_0c0ae0fe: /* original 644d, guest PC 0x0c0ae0fe */
if(!s->budget--) { s->failed_pc=0x0c0ae0feu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ae100;
P_0c0ae100: /* original 05ed, guest PC 0x0c0ae100 */
if(!s->budget--) { s->failed_pc=0x0c0ae100u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae102;
P_0c0ae102: /* original 655d, guest PC 0x0c0ae102 */
if(!s->budget--) { s->failed_pc=0x0c0ae102u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ae104;
P_0c0ae104: /* original 3456, guest PC 0x0c0ae104 */
if(!s->budget--) { s->failed_pc=0x0c0ae104u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[5])!=0);
goto P_0c0ae106;
P_0c0ae106: /* original 8b3d, guest PC 0x0c0ae106 */
if(!s->budget--) { s->failed_pc=0x0c0ae106u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae184; }
goto P_0c0ae108;
P_0c0ae108: /* original 902e, guest PC 0x0c0ae108 */
if(!s->budget--) { s->failed_pc=0x0c0ae108u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae168u,2);
goto P_0c0ae10a;
P_0c0ae10a: /* original 932e, guest PC 0x0c0ae10a */
if(!s->budget--) { s->failed_pc=0x0c0ae10au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae16au,2);
goto P_0c0ae10c;
P_0c0ae10c: /* original 0ded, guest PC 0x0c0ae10c */
if(!s->budget--) { s->failed_pc=0x0c0ae10cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae10e;
P_0c0ae10e: /* original 6ddd, guest PC 0x0c0ae10e */
if(!s->budget--) { s->failed_pc=0x0c0ae10eu; return 0; }
r[13]=r[13]&65535u;
goto P_0c0ae110;
P_0c0ae110: /* original 3d30, guest PC 0x0c0ae110 */
if(!s->budget--) { s->failed_pc=0x0c0ae110u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0ae112;
P_0c0ae112: /* original 8b14, guest PC 0x0c0ae112 */
if(!s->budget--) { s->failed_pc=0x0c0ae112u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae13e; }
goto P_0c0ae114;
P_0c0ae114: /* original 902a, guest PC 0x0c0ae114 */
if(!s->budget--) { s->failed_pc=0x0c0ae114u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae16cu,2);
goto P_0c0ae116;
P_0c0ae116: /* original e203, guest PC 0x0c0ae116 */
if(!s->budget--) { s->failed_pc=0x0c0ae116u; return 0; }
r[2]=0x00000003u;
goto P_0c0ae118;
P_0c0ae118: /* original 01ee, guest PC 0x0c0ae118 */
if(!s->budget--) { s->failed_pc=0x0c0ae118u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0ae11a;
P_0c0ae11a: /* original 70fc, guest PC 0x0c0ae11a */
if(!s->budget--) { s->failed_pc=0x0c0ae11au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0ae11c;
P_0c0ae11c: /* original 0e16, guest PC 0x0c0ae11c */
if(!s->budget--) { s->failed_pc=0x0c0ae11cu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0ae11e;
P_0c0ae11e: /* original 9026, guest PC 0x0c0ae11e */
if(!s->budget--) { s->failed_pc=0x0c0ae11eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae16eu,2);
goto P_0c0ae120;
P_0c0ae120: /* original 01ec, guest PC 0x0c0ae120 */
if(!s->budget--) { s->failed_pc=0x0c0ae120u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae122;
P_0c0ae122: /* original 2129, guest PC 0x0c0ae122 */
if(!s->budget--) { s->failed_pc=0x0c0ae122u; return 0; }
r[1]&=r[2];
goto P_0c0ae124;
P_0c0ae124: /* original 0e14, guest PC 0x0c0ae124 */
if(!s->budget--) { s->failed_pc=0x0c0ae124u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0ae126;
P_0c0ae126: /* original e000, guest PC 0x0c0ae126 */
if(!s->budget--) { s->failed_pc=0x0c0ae126u; return 0; }
r[0]=0x00000000u;
goto P_0c0ae128;
P_0c0ae128: /* original 9122, guest PC 0x0c0ae128 */
if(!s->budget--) { s->failed_pc=0x0c0ae128u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae170u,2);
goto P_0c0ae12a;
P_0c0ae12a: /* original 31ec, guest PC 0x0c0ae12a */
if(!s->budget--) { s->failed_pc=0x0c0ae12au; return 0; }
r[1]+=r[14];
goto P_0c0ae12c;
P_0c0ae12c: /* original 2100, guest PC 0x0c0ae12c */
if(!s->budget--) { s->failed_pc=0x0c0ae12cu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0ae12e;
P_0c0ae12e: /* original e03e, guest PC 0x0c0ae12e */
if(!s->budget--) { s->failed_pc=0x0c0ae12eu; return 0; }
r[0]=0x0000003eu;
goto P_0c0ae130;
P_0c0ae130: /* original e101, guest PC 0x0c0ae130 */
if(!s->budget--) { s->failed_pc=0x0c0ae130u; return 0; }
r[1]=0x00000001u;
goto P_0c0ae132;
P_0c0ae132: /* original 0e15, guest PC 0x0c0ae132 */
if(!s->budget--) { s->failed_pc=0x0c0ae132u; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c0ae134;
P_0c0ae134: /* original d311, guest PC 0x0c0ae134 */
if(!s->budget--) { s->failed_pc=0x0c0ae134u; return 0; }
r[3]=read(ram,0x0c0ae17cu,4);
goto P_0c0ae136;
P_0c0ae136: /* original 430b, guest PC 0x0c0ae136 */
if(!s->budget--) { s->failed_pc=0x0c0ae136u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae13au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae13au) { target=s->pc; goto dispatch; }
goto P_0c0ae13a;
P_0c0ae138: /* original 64e3, guest PC 0x0c0ae138 */
if(!s->budget--) { s->failed_pc=0x0c0ae138u; return 0; }
r[4]=r[14];
goto P_0c0ae13a;
P_0c0ae13a: /* original a026, guest PC 0x0c0ae13a */
if(!s->budget--) { s->failed_pc=0x0c0ae13au; return 0; }
goto P_0c0ae18a;
P_0c0ae13c: /* original 0009, guest PC 0x0c0ae13c */
if(!s->budget--) { s->failed_pc=0x0c0ae13cu; return 0; }
goto P_0c0ae13e;
P_0c0ae13e: /* original 9118, guest PC 0x0c0ae13e */
if(!s->budget--) { s->failed_pc=0x0c0ae13eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae172u,2);
goto P_0c0ae140;
P_0c0ae140: /* original 3d10, guest PC 0x0c0ae140 */
if(!s->budget--) { s->failed_pc=0x0c0ae140u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0ae142;
P_0c0ae142: /* original 8b04, guest PC 0x0c0ae142 */
if(!s->budget--) { s->failed_pc=0x0c0ae142u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae14e; }
goto P_0c0ae144;
P_0c0ae144: /* original d20e, guest PC 0x0c0ae144 */
if(!s->budget--) { s->failed_pc=0x0c0ae144u; return 0; }
r[2]=read(ram,0x0c0ae180u,4);
goto P_0c0ae146;
P_0c0ae146: /* original 65f2, guest PC 0x0c0ae146 */
if(!s->budget--) { s->failed_pc=0x0c0ae146u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ae148;
P_0c0ae148: /* original 420b, guest PC 0x0c0ae148 */
if(!s->budget--) { s->failed_pc=0x0c0ae148u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ae14cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae14cu) { target=s->pc; goto dispatch; }
goto P_0c0ae14c;
P_0c0ae14a: /* original 64e3, guest PC 0x0c0ae14a */
if(!s->budget--) { s->failed_pc=0x0c0ae14au; return 0; }
r[4]=r[14];
goto P_0c0ae14c;
P_0c0ae14c: /* original 6d03, guest PC 0x0c0ae14c */
if(!s->budget--) { s->failed_pc=0x0c0ae14cu; return 0; }
r[13]=r[0];
goto P_0c0ae14e;
P_0c0ae14e: /* original 2dd8, guest PC 0x0c0ae14e */
if(!s->budget--) { s->failed_pc=0x0c0ae14eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0ae150;
P_0c0ae150: /* original 8b01, guest PC 0x0c0ae150 */
if(!s->budget--) { s->failed_pc=0x0c0ae150u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae156; }
goto P_0c0ae152;
P_0c0ae152: /* original a07e, guest PC 0x0c0ae152 */
if(!s->budget--) { s->failed_pc=0x0c0ae152u; return 0; }
goto P_0c0ae252;
P_0c0ae154: /* original 0009, guest PC 0x0c0ae154 */
if(!s->budget--) { s->failed_pc=0x0c0ae154u; return 0; }
goto P_0c0ae156;
P_0c0ae156: /* original 65d3, guest PC 0x0c0ae156 */
if(!s->budget--) { s->failed_pc=0x0c0ae156u; return 0; }
r[5]=r[13];
goto P_0c0ae158;
P_0c0ae158: /* original b80e, guest PC 0x0c0ae158 */
if(!s->budget--) { s->failed_pc=0x0c0ae158u; return 0; }
target=code_base|0x0c0ad178u; r[16]=code_base|0x0c0ae15cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae15cu) { target=s->pc; goto dispatch; }
goto P_0c0ae15c;
P_0c0ae15a: /* original 64e3, guest PC 0x0c0ae15a */
if(!s->budget--) { s->failed_pc=0x0c0ae15au; return 0; }
r[4]=r[14];
goto P_0c0ae15c;
P_0c0ae15c: /* original a015, guest PC 0x0c0ae15c */
if(!s->budget--) { s->failed_pc=0x0c0ae15cu; return 0; }
goto P_0c0ae18a;
P_0c0ae15e: /* original 0009, guest PC 0x0c0ae15e */
if(!s->budget--) { s->failed_pc=0x0c0ae15eu; return 0; }
if(!vf3_matrix_family(0x0c0ae160u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae160u; return 0; } return 1;
P_0c0ae184: /* original d33a, guest PC 0x0c0ae184 */
if(!s->budget--) { s->failed_pc=0x0c0ae184u; return 0; }
r[3]=read(ram,0x0c0ae270u,4);
goto P_0c0ae186;
P_0c0ae186: /* original 430b, guest PC 0x0c0ae186 */
if(!s->budget--) { s->failed_pc=0x0c0ae186u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae18au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae18au) { target=s->pc; goto dispatch; }
goto P_0c0ae18a;
P_0c0ae188: /* original 64e3, guest PC 0x0c0ae188 */
if(!s->budget--) { s->failed_pc=0x0c0ae188u; return 0; }
r[4]=r[14];
goto P_0c0ae18a;
P_0c0ae18a: /* original e048, guest PC 0x0c0ae18a */
if(!s->budget--) { s->failed_pc=0x0c0ae18au; return 0; }
r[0]=0x00000048u;
goto P_0c0ae18c;
P_0c0ae18c: /* original 04ee, guest PC 0x0c0ae18c */
if(!s->budget--) { s->failed_pc=0x0c0ae18cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ae18e;
P_0c0ae18e: /* original e301, guest PC 0x0c0ae18e */
if(!s->budget--) { s->failed_pc=0x0c0ae18eu; return 0; }
r[3]=0x00000001u;
goto P_0c0ae190;
P_0c0ae190: /* original 9064, guest PC 0x0c0ae190 */
if(!s->budget--) { s->failed_pc=0x0c0ae190u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae25cu,2);
goto P_0c0ae192;
P_0c0ae192: /* original 07ee, guest PC 0x0c0ae192 */
if(!s->budget--) { s->failed_pc=0x0c0ae192u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0ae194;
P_0c0ae194: /* original e03e, guest PC 0x0c0ae194 */
if(!s->budget--) { s->failed_pc=0x0c0ae194u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ae196;
P_0c0ae196: /* original 06ed, guest PC 0x0c0ae196 */
if(!s->budget--) { s->failed_pc=0x0c0ae196u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae198;
P_0c0ae198: /* original e063, guest PC 0x0c0ae198 */
if(!s->budget--) { s->failed_pc=0x0c0ae198u; return 0; }
r[0]=0x00000063u;
goto P_0c0ae19a;
P_0c0ae19a: /* original 05ec, guest PC 0x0c0ae19a */
if(!s->budget--) { s->failed_pc=0x0c0ae19au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae19c;
P_0c0ae19c: /* original 655c, guest PC 0x0c0ae19c */
if(!s->budget--) { s->failed_pc=0x0c0ae19cu; return 0; }
r[5]=r[5]&255u;
goto P_0c0ae19e;
P_0c0ae19e: /* original 3533, guest PC 0x0c0ae19e */
if(!s->budget--) { s->failed_pc=0x0c0ae19eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c0ae1a0;
P_0c0ae1a0: /* original 8f4c, guest PC 0x0c0ae1a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae1a0u; return 0; }
cond=r[17]&1u;
r[6]=r[6]&65535u;
if(!cond) { goto P_0c0ae23c; }
goto P_0c0ae1a4;
P_0c0ae1a2: /* original 666d, guest PC 0x0c0ae1a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae1a2u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0ae1a4;
P_0c0ae1a4: /* original 6053, guest PC 0x0c0ae1a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae1a4u; return 0; }
r[0]=r[5];
goto P_0c0ae1a6;
P_0c0ae1a6: /* original 8801, guest PC 0x0c0ae1a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae1a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ae1a8;
P_0c0ae1a8: /* original 8905, guest PC 0x0c0ae1a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae1a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae1b6; }
goto P_0c0ae1aa;
P_0c0ae1aa: /* original 6053, guest PC 0x0c0ae1aa */
if(!s->budget--) { s->failed_pc=0x0c0ae1aau; return 0; }
r[0]=r[5];
goto P_0c0ae1ac;
P_0c0ae1ac: /* original 8802, guest PC 0x0c0ae1ac */
if(!s->budget--) { s->failed_pc=0x0c0ae1acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0ae1ae;
P_0c0ae1ae: /* original 890a, guest PC 0x0c0ae1ae */
if(!s->budget--) { s->failed_pc=0x0c0ae1aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae1c6; }
goto P_0c0ae1b0;
P_0c0ae1b0: /* original e202, guest PC 0x0c0ae1b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae1b0u; return 0; }
r[2]=0x00000002u;
goto P_0c0ae1b2;
P_0c0ae1b2: /* original 3527, guest PC 0x0c0ae1b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae1b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[2])!=0);
goto P_0c0ae1b4;
P_0c0ae1b4: /* original 8920, guest PC 0x0c0ae1b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae1b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae1f8; }
goto P_0c0ae1b6;
P_0c0ae1b6: /* original 9052, guest PC 0x0c0ae1b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae1b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae25eu,2);
goto P_0c0ae1b8;
P_0c0ae1b8: /* original 03ed, guest PC 0x0c0ae1b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae1b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae1ba;
P_0c0ae1ba: /* original 633d, guest PC 0x0c0ae1ba */
if(!s->budget--) { s->failed_pc=0x0c0ae1bau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ae1bc;
P_0c0ae1bc: /* original 3632, guest PC 0x0c0ae1bc */
if(!s->budget--) { s->failed_pc=0x0c0ae1bcu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[3])!=0);
goto P_0c0ae1be;
P_0c0ae1be: /* original 8b3b, guest PC 0x0c0ae1be */
if(!s->budget--) { s->failed_pc=0x0c0ae1beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae238; }
goto P_0c0ae1c0;
P_0c0ae1c0: /* original d32c, guest PC 0x0c0ae1c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae1c0u; return 0; }
r[3]=read(ram,0x0c0ae274u,4);
goto P_0c0ae1c2;
P_0c0ae1c2: /* original 7501, guest PC 0x0c0ae1c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae1c2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0ae1c4;
P_0c0ae1c4: /* original 2439, guest PC 0x0c0ae1c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae1c4u; return 0; }
r[4]&=r[3];
goto P_0c0ae1c6;
P_0c0ae1c6: /* original 904b, guest PC 0x0c0ae1c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae1c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae260u,2);
goto P_0c0ae1c8;
P_0c0ae1c8: /* original 02ed, guest PC 0x0c0ae1c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae1c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae1ca;
P_0c0ae1ca: /* original 622d, guest PC 0x0c0ae1ca */
if(!s->budget--) { s->failed_pc=0x0c0ae1cau; return 0; }
r[2]=r[2]&65535u;
goto P_0c0ae1cc;
P_0c0ae1cc: /* original 3622, guest PC 0x0c0ae1cc */
if(!s->budget--) { s->failed_pc=0x0c0ae1ccu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[2])!=0);
goto P_0c0ae1ce;
P_0c0ae1ce: /* original 8b33, guest PC 0x0c0ae1ce */
if(!s->budget--) { s->failed_pc=0x0c0ae1ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae238; }
goto P_0c0ae1d0;
P_0c0ae1d0: /* original 9347, guest PC 0x0c0ae1d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae1d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae262u,2);
goto P_0c0ae1d2;
P_0c0ae1d2: /* original e04c, guest PC 0x0c0ae1d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae1d2u; return 0; }
r[0]=0x0000004cu;
goto P_0c0ae1d4;
P_0c0ae1d4: /* original dd28, guest PC 0x0c0ae1d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae1d4u; return 0; }
r[13]=read(ram,0x0c0ae278u,4);
goto P_0c0ae1d6;
P_0c0ae1d6: /* original 2348, guest PC 0x0c0ae1d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae1d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ae1d8;
P_0c0ae1d8: /* original 8d01, guest PC 0x0c0ae1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae1d8u; return 0; }
cond=r[17]&1u;
r[1]=read(ram,r[14]+r[0],4);
if(cond) { goto P_0c0ae1de; }
goto P_0c0ae1dc;
P_0c0ae1da: /* original 01ee, guest PC 0x0c0ae1da */
if(!s->budget--) { s->failed_pc=0x0c0ae1dau; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0ae1dc;
P_0c0ae1dc: /* original dd27, guest PC 0x0c0ae1dc */
if(!s->budget--) { s->failed_pc=0x0c0ae1dcu; return 0; }
r[13]=read(ram,0x0c0ae27cu,4);
goto P_0c0ae1de;
P_0c0ae1de: /* original d328, guest PC 0x0c0ae1de */
if(!s->budget--) { s->failed_pc=0x0c0ae1deu; return 0; }
r[3]=read(ram,0x0c0ae280u,4);
goto P_0c0ae1e0;
P_0c0ae1e0: /* original 6dd7, guest PC 0x0c0ae1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae1e0u; return 0; }
r[13]=~r[13];
goto P_0c0ae1e2;
P_0c0ae1e2: /* original 24d9, guest PC 0x0c0ae1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae1e2u; return 0; }
r[4]&=r[13];
goto P_0c0ae1e4;
P_0c0ae1e4: /* original 2139, guest PC 0x0c0ae1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae1e4u; return 0; }
r[1]&=r[3];
goto P_0c0ae1e6;
P_0c0ae1e6: /* original 0e16, guest PC 0x0c0ae1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae1e6u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0ae1e8;
P_0c0ae1e8: /* original 903c, guest PC 0x0c0ae1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae1e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae264u,2);
goto P_0c0ae1ea;
P_0c0ae1ea: /* original d226, guest PC 0x0c0ae1ea */
if(!s->budget--) { s->failed_pc=0x0c0ae1eau; return 0; }
r[2]=read(ram,0x0c0ae284u,4);
goto P_0c0ae1ec;
P_0c0ae1ec: /* original 0dee, guest PC 0x0c0ae1ec */
if(!s->budget--) { s->failed_pc=0x0c0ae1ecu; return 0; }
r[13]=read(ram,r[14]+r[0],4);
goto P_0c0ae1ee;
P_0c0ae1ee: /* original 2dd8, guest PC 0x0c0ae1ee */
if(!s->budget--) { s->failed_pc=0x0c0ae1eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0ae1f0;
P_0c0ae1f0: /* original 8d01, guest PC 0x0c0ae1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae1f0u; return 0; }
cond=r[17]&1u;
r[4]|=r[2];
if(cond) { goto P_0c0ae1f6; }
goto P_0c0ae1f4;
P_0c0ae1f2: /* original 242b, guest PC 0x0c0ae1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae1f2u; return 0; }
r[4]|=r[2];
goto P_0c0ae1f4;
P_0c0ae1f4: /* original 1edd, guest PC 0x0c0ae1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae1f4u; return 0; }
write(ram,r[14]+52,r[13],4);
goto P_0c0ae1f6;
P_0c0ae1f6: /* original 7501, guest PC 0x0c0ae1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae1f6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0ae1f8;
P_0c0ae1f8: /* original d223, guest PC 0x0c0ae1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae1f8u; return 0; }
r[2]=read(ram,0x0c0ae288u,4);
goto P_0c0ae1fa;
P_0c0ae1fa: /* original 2248, guest PC 0x0c0ae1fa */
if(!s->budget--) { s->failed_pc=0x0c0ae1fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0ae1fc;
P_0c0ae1fc: /* original 890a, guest PC 0x0c0ae1fc */
if(!s->budget--) { s->failed_pc=0x0c0ae1fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae214; }
goto P_0c0ae1fe;
P_0c0ae1fe: /* original d123, guest PC 0x0c0ae1fe */
if(!s->budget--) { s->failed_pc=0x0c0ae1feu; return 0; }
r[1]=read(ram,0x0c0ae28cu,4);
goto P_0c0ae200;
P_0c0ae200: /* original 2148, guest PC 0x0c0ae200 */
if(!s->budget--) { s->failed_pc=0x0c0ae200u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0ae202;
P_0c0ae202: /* original 8907, guest PC 0x0c0ae202 */
if(!s->budget--) { s->failed_pc=0x0c0ae202u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae214; }
goto P_0c0ae204;
P_0c0ae204: /* original 902f, guest PC 0x0c0ae204 */
if(!s->budget--) { s->failed_pc=0x0c0ae204u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae266u,2);
goto P_0c0ae206;
P_0c0ae206: /* original 0ded, guest PC 0x0c0ae206 */
if(!s->budget--) { s->failed_pc=0x0c0ae206u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae208;
P_0c0ae208: /* original 2dd8, guest PC 0x0c0ae208 */
if(!s->budget--) { s->failed_pc=0x0c0ae208u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0ae20a;
P_0c0ae20a: /* original 8903, guest PC 0x0c0ae20a */
if(!s->budget--) { s->failed_pc=0x0c0ae20au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae214; }
goto P_0c0ae20c;
P_0c0ae20c: /* original 36d2, guest PC 0x0c0ae20c */
if(!s->budget--) { s->failed_pc=0x0c0ae20cu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[13])!=0);
goto P_0c0ae20e;
P_0c0ae20e: /* original 8b01, guest PC 0x0c0ae20e */
if(!s->budget--) { s->failed_pc=0x0c0ae20eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae214; }
goto P_0c0ae210;
P_0c0ae210: /* original d31f, guest PC 0x0c0ae210 */
if(!s->budget--) { s->failed_pc=0x0c0ae210u; return 0; }
r[3]=read(ram,0x0c0ae290u,4);
goto P_0c0ae212;
P_0c0ae212: /* original 2439, guest PC 0x0c0ae212 */
if(!s->budget--) { s->failed_pc=0x0c0ae212u; return 0; }
r[4]&=r[3];
goto P_0c0ae214;
P_0c0ae214: /* original 9028, guest PC 0x0c0ae214 */
if(!s->budget--) { s->failed_pc=0x0c0ae214u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae268u,2);
goto P_0c0ae216;
P_0c0ae216: /* original 02ed, guest PC 0x0c0ae216 */
if(!s->budget--) { s->failed_pc=0x0c0ae216u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae218;
P_0c0ae218: /* original 622d, guest PC 0x0c0ae218 */
if(!s->budget--) { s->failed_pc=0x0c0ae218u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0ae21a;
P_0c0ae21a: /* original 3622, guest PC 0x0c0ae21a */
if(!s->budget--) { s->failed_pc=0x0c0ae21au; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[2])!=0);
goto P_0c0ae21c;
P_0c0ae21c: /* original 8b0c, guest PC 0x0c0ae21c */
if(!s->budget--) { s->failed_pc=0x0c0ae21cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae238; }
goto P_0c0ae21e;
P_0c0ae21e: /* original e04c, guest PC 0x0c0ae21e */
if(!s->budget--) { s->failed_pc=0x0c0ae21eu; return 0; }
r[0]=0x0000004cu;
goto P_0c0ae220;
P_0c0ae220: /* original d31d, guest PC 0x0c0ae220 */
if(!s->budget--) { s->failed_pc=0x0c0ae220u; return 0; }
r[3]=read(ram,0x0c0ae298u,4);
goto P_0c0ae222;
P_0c0ae222: /* original 01ee, guest PC 0x0c0ae222 */
if(!s->budget--) { s->failed_pc=0x0c0ae222u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0ae224;
P_0c0ae224: /* original d21b, guest PC 0x0c0ae224 */
if(!s->budget--) { s->failed_pc=0x0c0ae224u; return 0; }
r[2]=read(ram,0x0c0ae294u,4);
goto P_0c0ae226;
P_0c0ae226: /* original 2139, guest PC 0x0c0ae226 */
if(!s->budget--) { s->failed_pc=0x0c0ae226u; return 0; }
r[1]&=r[3];
goto P_0c0ae228;
P_0c0ae228: /* original 0e16, guest PC 0x0c0ae228 */
if(!s->budget--) { s->failed_pc=0x0c0ae228u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0ae22a;
P_0c0ae22a: /* original 2429, guest PC 0x0c0ae22a */
if(!s->budget--) { s->failed_pc=0x0c0ae22au; return 0; }
r[4]&=r[2];
goto P_0c0ae22c;
P_0c0ae22c: /* original 901d, guest PC 0x0c0ae22c */
if(!s->budget--) { s->failed_pc=0x0c0ae22cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae26au,2);
goto P_0c0ae22e;
P_0c0ae22e: /* original 0dee, guest PC 0x0c0ae22e */
if(!s->budget--) { s->failed_pc=0x0c0ae22eu; return 0; }
r[13]=read(ram,r[14]+r[0],4);
goto P_0c0ae230;
P_0c0ae230: /* original 2dd8, guest PC 0x0c0ae230 */
if(!s->budget--) { s->failed_pc=0x0c0ae230u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0ae232;
P_0c0ae232: /* original 8d01, guest PC 0x0c0ae232 */
if(!s->budget--) { s->failed_pc=0x0c0ae232u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(cond) { goto P_0c0ae238; }
goto P_0c0ae236;
P_0c0ae234: /* original 7501, guest PC 0x0c0ae234 */
if(!s->budget--) { s->failed_pc=0x0c0ae234u; return 0; }
r[5]+=0x00000001u;
goto P_0c0ae236;
P_0c0ae236: /* original 1edd, guest PC 0x0c0ae236 */
if(!s->budget--) { s->failed_pc=0x0c0ae236u; return 0; }
write(ram,r[14]+52,r[13],4);
goto P_0c0ae238;
P_0c0ae238: /* original e063, guest PC 0x0c0ae238 */
if(!s->budget--) { s->failed_pc=0x0c0ae238u; return 0; }
r[0]=0x00000063u;
goto P_0c0ae23a;
P_0c0ae23a: /* original 0e54, guest PC 0x0c0ae23a */
if(!s->budget--) { s->failed_pc=0x0c0ae23au; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0ae23c;
P_0c0ae23c: /* original 1f61, guest PC 0x0c0ae23c */
if(!s->budget--) { s->failed_pc=0x0c0ae23cu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0ae23e;
P_0c0ae23e: /* original 66f3, guest PC 0x0c0ae23e */
if(!s->budget--) { s->failed_pc=0x0c0ae23eu; return 0; }
r[6]=r[15];
goto P_0c0ae240;
P_0c0ae240: /* original 9014, guest PC 0x0c0ae240 */
if(!s->budget--) { s->failed_pc=0x0c0ae240u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae26cu,2);
goto P_0c0ae242;
P_0c0ae242: /* original 7604, guest PC 0x0c0ae242 */
if(!s->budget--) { s->failed_pc=0x0c0ae242u; return 0; }
r[6]+=0x00000004u;
goto P_0c0ae244;
P_0c0ae244: /* original 03ee, guest PC 0x0c0ae244 */
if(!s->budget--) { s->failed_pc=0x0c0ae244u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0ae246;
P_0c0ae246: /* original 1f33, guest PC 0x0c0ae246 */
if(!s->budget--) { s->failed_pc=0x0c0ae246u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0ae248;
P_0c0ae248: /* original 1f44, guest PC 0x0c0ae248 */
if(!s->budget--) { s->failed_pc=0x0c0ae248u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c0ae24a;
P_0c0ae24a: /* original 1f75, guest PC 0x0c0ae24a */
if(!s->budget--) { s->failed_pc=0x0c0ae24au; return 0; }
write(ram,r[15]+20,r[7],4);
goto P_0c0ae24c;
P_0c0ae24c: /* original 65f2, guest PC 0x0c0ae24c */
if(!s->budget--) { s->failed_pc=0x0c0ae24cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ae24e;
P_0c0ae24e: /* original b025, guest PC 0x0c0ae24e */
if(!s->budget--) { s->failed_pc=0x0c0ae24eu; return 0; }
target=code_base|0x0c0ae29cu; r[16]=code_base|0x0c0ae252u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae252u) { target=s->pc; goto dispatch; }
goto P_0c0ae252;
P_0c0ae250: /* original 64e3, guest PC 0x0c0ae250 */
if(!s->budget--) { s->failed_pc=0x0c0ae250u; return 0; }
r[4]=r[14];
goto P_0c0ae252;
P_0c0ae252: /* original 7f18, guest PC 0x0c0ae252 */
if(!s->budget--) { s->failed_pc=0x0c0ae252u; return 0; }
r[15]+=0x00000018u;
goto P_0c0ae254;
P_0c0ae254: /* original 4f26, guest PC 0x0c0ae254 */
if(!s->budget--) { s->failed_pc=0x0c0ae254u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae256;
P_0c0ae256: /* original 6df6, guest PC 0x0c0ae256 */
if(!s->budget--) { s->failed_pc=0x0c0ae256u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae258;
P_0c0ae258: /* original 000b, guest PC 0x0c0ae258 */
if(!s->budget--) { s->failed_pc=0x0c0ae258u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ae25a: /* original 6ef6, guest PC 0x0c0ae25a */
if(!s->budget--) { s->failed_pc=0x0c0ae25au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ae25cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae25cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
