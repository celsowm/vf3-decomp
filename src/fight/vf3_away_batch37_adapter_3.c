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
int vf3_away_batch37_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06c07eu: goto P_0c06c07e;
case 0x0c06c080u: goto P_0c06c080;
case 0x0c06c082u: goto P_0c06c082;
case 0x0c06c084u: goto P_0c06c084;
case 0x0c06c086u: goto P_0c06c086;
case 0x0c06c088u: goto P_0c06c088;
case 0x0c06c08au: goto P_0c06c08a;
case 0x0c06c08cu: goto P_0c06c08c;
case 0x0c06c08eu: goto P_0c06c08e;
case 0x0c06c090u: goto P_0c06c090;
case 0x0c06c092u: goto P_0c06c092;
case 0x0c06c094u: goto P_0c06c094;
case 0x0c06c096u: goto P_0c06c096;
case 0x0c06c098u: goto P_0c06c098;
case 0x0c06c09au: goto P_0c06c09a;
case 0x0c06c09cu: goto P_0c06c09c;
case 0x0c06c09eu: goto P_0c06c09e;
case 0x0c06c0a0u: goto P_0c06c0a0;
case 0x0c06c0a2u: goto P_0c06c0a2;
case 0x0c06c0a4u: goto P_0c06c0a4;
case 0x0c06c0a6u: goto P_0c06c0a6;
case 0x0c06c0ccu: goto P_0c06c0cc;
case 0x0c06c0ceu: goto P_0c06c0ce;
case 0x0c06c0d0u: goto P_0c06c0d0;
case 0x0c06c0d2u: goto P_0c06c0d2;
case 0x0c06c0d4u: goto P_0c06c0d4;
case 0x0c06c0d6u: goto P_0c06c0d6;
case 0x0c06c0d8u: goto P_0c06c0d8;
case 0x0c06c0dau: goto P_0c06c0da;
case 0x0c06c0dcu: goto P_0c06c0dc;
case 0x0c06c0deu: goto P_0c06c0de;
case 0x0c06c0e0u: goto P_0c06c0e0;
case 0x0c06c0e2u: goto P_0c06c0e2;
case 0x0c06c0e4u: goto P_0c06c0e4;
case 0x0c06c0e6u: goto P_0c06c0e6;
case 0x0c06c0e8u: goto P_0c06c0e8;
case 0x0c06c0eau: goto P_0c06c0ea;
case 0x0c06c0ecu: goto P_0c06c0ec;
case 0x0c06c0eeu: goto P_0c06c0ee;
case 0x0c06c0f0u: goto P_0c06c0f0;
case 0x0c06c0f2u: goto P_0c06c0f2;
case 0x0c06c0f4u: goto P_0c06c0f4;
case 0x0c06c0f6u: goto P_0c06c0f6;
case 0x0c06c0f8u: goto P_0c06c0f8;
case 0x0c06c0fau: goto P_0c06c0fa;
case 0x0c06c0fcu: goto P_0c06c0fc;
case 0x0c06c0feu: goto P_0c06c0fe;
case 0x0c06c100u: goto P_0c06c100;
case 0x0c06c102u: goto P_0c06c102;
case 0x0c06c104u: goto P_0c06c104;
case 0x0c06c106u: goto P_0c06c106;
case 0x0c06c108u: goto P_0c06c108;
case 0x0c06c10au: goto P_0c06c10a;
case 0x0c06c10cu: goto P_0c06c10c;
case 0x0c06c10eu: goto P_0c06c10e;
case 0x0c06c110u: goto P_0c06c110;
case 0x0c06c112u: goto P_0c06c112;
case 0x0c06c114u: goto P_0c06c114;
case 0x0c06c116u: goto P_0c06c116;
case 0x0c06c118u: goto P_0c06c118;
case 0x0c06c11au: goto P_0c06c11a;
case 0x0c06c11cu: goto P_0c06c11c;
case 0x0c06c11eu: goto P_0c06c11e;
case 0x0c06c120u: goto P_0c06c120;
case 0x0c06c122u: goto P_0c06c122;
case 0x0c06c124u: goto P_0c06c124;
case 0x0c06c126u: goto P_0c06c126;
case 0x0c06c128u: goto P_0c06c128;
case 0x0c06c12au: goto P_0c06c12a;
case 0x0c06c12cu: goto P_0c06c12c;
case 0x0c06c12eu: goto P_0c06c12e;
case 0x0c06c130u: goto P_0c06c130;
case 0x0c06c132u: goto P_0c06c132;
case 0x0c06c134u: goto P_0c06c134;
case 0x0c06c136u: goto P_0c06c136;
case 0x0c06c138u: goto P_0c06c138;
case 0x0c06c13au: goto P_0c06c13a;
case 0x0c06c13cu: goto P_0c06c13c;
case 0x0c06c13eu: goto P_0c06c13e;
case 0x0c06c140u: goto P_0c06c140;
case 0x0c06c142u: goto P_0c06c142;
case 0x0c06c144u: goto P_0c06c144;
case 0x0c06c146u: goto P_0c06c146;
case 0x0c06c148u: goto P_0c06c148;
case 0x0c06c14au: goto P_0c06c14a;
case 0x0c06c14cu: goto P_0c06c14c;
case 0x0c06c14eu: goto P_0c06c14e;
case 0x0c06c150u: goto P_0c06c150;
case 0x0c06c152u: goto P_0c06c152;
case 0x0c06c154u: goto P_0c06c154;
case 0x0c06c156u: goto P_0c06c156;
case 0x0c06c158u: goto P_0c06c158;
case 0x0c06c15au: goto P_0c06c15a;
case 0x0c06c15cu: goto P_0c06c15c;
case 0x0c06c15eu: goto P_0c06c15e;
case 0x0c06c160u: goto P_0c06c160;
case 0x0c06c162u: goto P_0c06c162;
case 0x0c06c164u: goto P_0c06c164;
case 0x0c06c166u: goto P_0c06c166;
case 0x0c06c168u: goto P_0c06c168;
case 0x0c06c16au: goto P_0c06c16a;
case 0x0c06c16cu: goto P_0c06c16c;
case 0x0c06c16eu: goto P_0c06c16e;
case 0x0c06c170u: goto P_0c06c170;
case 0x0c06c172u: goto P_0c06c172;
case 0x0c06c174u: goto P_0c06c174;
case 0x0c06c176u: goto P_0c06c176;
case 0x0c06c178u: goto P_0c06c178;
case 0x0c06c17au: goto P_0c06c17a;
case 0x0c06c17cu: goto P_0c06c17c;
case 0x0c06c17eu: goto P_0c06c17e;
case 0x0c06c180u: goto P_0c06c180;
case 0x0c06c182u: goto P_0c06c182;
case 0x0c06c184u: goto P_0c06c184;
case 0x0c06c186u: goto P_0c06c186;
case 0x0c06c188u: goto P_0c06c188;
case 0x0c06c18au: goto P_0c06c18a;
case 0x0c06c18cu: goto P_0c06c18c;
case 0x0c06c18eu: goto P_0c06c18e;
case 0x0c06c190u: goto P_0c06c190;
case 0x0c06c192u: goto P_0c06c192;
case 0x0c06c194u: goto P_0c06c194;
case 0x0c06c196u: goto P_0c06c196;
case 0x0c06c198u: goto P_0c06c198;
case 0x0c06c19au: goto P_0c06c19a;
case 0x0c06c19cu: goto P_0c06c19c;
case 0x0c06c19eu: goto P_0c06c19e;
case 0x0c06c1a0u: goto P_0c06c1a0;
case 0x0c06c1a2u: goto P_0c06c1a2;
case 0x0c06c1a4u: goto P_0c06c1a4;
case 0x0c06c1a6u: goto P_0c06c1a6;
case 0x0c06c1a8u: goto P_0c06c1a8;
case 0x0c06c1aau: goto P_0c06c1aa;
case 0x0c06c1acu: goto P_0c06c1ac;
case 0x0c06c1aeu: goto P_0c06c1ae;
case 0x0c06c1b0u: goto P_0c06c1b0;
case 0x0c06c1b2u: goto P_0c06c1b2;
case 0x0c06c1b4u: goto P_0c06c1b4;
case 0x0c06c1b6u: goto P_0c06c1b6;
case 0x0c06c1b8u: goto P_0c06c1b8;
case 0x0c06c1bau: goto P_0c06c1ba;
case 0x0c06c1bcu: goto P_0c06c1bc;
case 0x0c06c1beu: goto P_0c06c1be;
case 0x0c06c1c0u: goto P_0c06c1c0;
case 0x0c06c1c2u: goto P_0c06c1c2;
case 0x0c06c1c4u: goto P_0c06c1c4;
case 0x0c06c1c6u: goto P_0c06c1c6;
case 0x0c06c1c8u: goto P_0c06c1c8;
case 0x0c06c1cau: goto P_0c06c1ca;
case 0x0c06c1ccu: goto P_0c06c1cc;
case 0x0c06c1ceu: goto P_0c06c1ce;
case 0x0c06c1d0u: goto P_0c06c1d0;
case 0x0c06c1d2u: goto P_0c06c1d2;
case 0x0c06c1d4u: goto P_0c06c1d4;
case 0x0c06c1d6u: goto P_0c06c1d6;
case 0x0c06c1d8u: goto P_0c06c1d8;
case 0x0c06c1dau: goto P_0c06c1da;
case 0x0c06c1dcu: goto P_0c06c1dc;
case 0x0c06c1deu: goto P_0c06c1de;
case 0x0c06c1e0u: goto P_0c06c1e0;
case 0x0c06c1e2u: goto P_0c06c1e2;
case 0x0c06c1e4u: goto P_0c06c1e4;
case 0x0c06c208u: goto P_0c06c208;
case 0x0c06c20au: goto P_0c06c20a;
case 0x0c06c20cu: goto P_0c06c20c;
case 0x0c06c20eu: goto P_0c06c20e;
case 0x0c06c210u: goto P_0c06c210;
case 0x0c06c212u: goto P_0c06c212;
case 0x0c06c214u: goto P_0c06c214;
case 0x0c06c216u: goto P_0c06c216;
case 0x0c06c218u: goto P_0c06c218;
case 0x0c06c21au: goto P_0c06c21a;
case 0x0c06c21cu: goto P_0c06c21c;
case 0x0c06c21eu: goto P_0c06c21e;
case 0x0c06c220u: goto P_0c06c220;
case 0x0c06c222u: goto P_0c06c222;
case 0x0c06c224u: goto P_0c06c224;
case 0x0c06c226u: goto P_0c06c226;
case 0x0c06c228u: goto P_0c06c228;
case 0x0c06c22au: goto P_0c06c22a;
case 0x0c06c22cu: goto P_0c06c22c;
case 0x0c06c22eu: goto P_0c06c22e;
case 0x0c06c230u: goto P_0c06c230;
case 0x0c06c232u: goto P_0c06c232;
case 0x0c06c234u: goto P_0c06c234;
case 0x0c06c236u: goto P_0c06c236;
case 0x0c06c238u: goto P_0c06c238;
case 0x0c06c23au: goto P_0c06c23a;
case 0x0c06c23cu: goto P_0c06c23c;
case 0x0c06c23eu: goto P_0c06c23e;
case 0x0c06c240u: goto P_0c06c240;
case 0x0c06c242u: goto P_0c06c242;
case 0x0c06c244u: goto P_0c06c244;
case 0x0c06c246u: goto P_0c06c246;
case 0x0c06c248u: goto P_0c06c248;
case 0x0c06c24au: goto P_0c06c24a;
case 0x0c06c24cu: goto P_0c06c24c;
case 0x0c06c24eu: goto P_0c06c24e;
case 0x0c06c250u: goto P_0c06c250;
case 0x0c06c252u: goto P_0c06c252;
case 0x0c06c254u: goto P_0c06c254;
case 0x0c06c256u: goto P_0c06c256;
case 0x0c06c258u: goto P_0c06c258;
case 0x0c06c25au: goto P_0c06c25a;
case 0x0c06c25cu: goto P_0c06c25c;
case 0x0c06c25eu: goto P_0c06c25e;
case 0x0c06c260u: goto P_0c06c260;
case 0x0c06c262u: goto P_0c06c262;
case 0x0c06c264u: goto P_0c06c264;
case 0x0c06c266u: goto P_0c06c266;
case 0x0c06c268u: goto P_0c06c268;
case 0x0c06c26au: goto P_0c06c26a;
case 0x0c06c26cu: goto P_0c06c26c;
case 0x0c06c26eu: goto P_0c06c26e;
case 0x0c06c270u: goto P_0c06c270;
case 0x0c06c272u: goto P_0c06c272;
case 0x0c06c274u: goto P_0c06c274;
case 0x0c06c276u: goto P_0c06c276;
case 0x0c06c278u: goto P_0c06c278;
case 0x0c06c27au: goto P_0c06c27a;
case 0x0c06c27cu: goto P_0c06c27c;
case 0x0c06c27eu: goto P_0c06c27e;
case 0x0c06c280u: goto P_0c06c280;
case 0x0c06c282u: goto P_0c06c282;
case 0x0c06c284u: goto P_0c06c284;
case 0x0c06c286u: goto P_0c06c286;
case 0x0c06c288u: goto P_0c06c288;
case 0x0c06c28au: goto P_0c06c28a;
case 0x0c06c28cu: goto P_0c06c28c;
case 0x0c06c28eu: goto P_0c06c28e;
case 0x0c06c290u: goto P_0c06c290;
case 0x0c06c292u: goto P_0c06c292;
case 0x0c06c294u: goto P_0c06c294;
case 0x0c06c296u: goto P_0c06c296;
case 0x0c06c298u: goto P_0c06c298;
case 0x0c06c29au: goto P_0c06c29a;
case 0x0c06c29cu: goto P_0c06c29c;
case 0x0c06c29eu: goto P_0c06c29e;
case 0x0c06c2a0u: goto P_0c06c2a0;
case 0x0c06c2a2u: goto P_0c06c2a2;
case 0x0c06c2a4u: goto P_0c06c2a4;
case 0x0c06c2a6u: goto P_0c06c2a6;
case 0x0c06c2a8u: goto P_0c06c2a8;
case 0x0c06c2aau: goto P_0c06c2aa;
case 0x0c06c2acu: goto P_0c06c2ac;
case 0x0c06c2aeu: goto P_0c06c2ae;
case 0x0c06c2b0u: goto P_0c06c2b0;
case 0x0c06c2b2u: goto P_0c06c2b2;
case 0x0c06c2b4u: goto P_0c06c2b4;
case 0x0c06c2b6u: goto P_0c06c2b6;
case 0x0c06c2b8u: goto P_0c06c2b8;
case 0x0c06c2bau: goto P_0c06c2ba;
case 0x0c06c2bcu: goto P_0c06c2bc;
case 0x0c06c2beu: goto P_0c06c2be;
case 0x0c06c2c0u: goto P_0c06c2c0;
case 0x0c06c2c2u: goto P_0c06c2c2;
case 0x0c06c2c4u: goto P_0c06c2c4;
case 0x0c06c2c6u: goto P_0c06c2c6;
case 0x0c06c2c8u: goto P_0c06c2c8;
case 0x0c06c2cau: goto P_0c06c2ca;
case 0x0c06c2ccu: goto P_0c06c2cc;
case 0x0c06c2ceu: goto P_0c06c2ce;
case 0x0c06c2d0u: goto P_0c06c2d0;
case 0x0c06c2d2u: goto P_0c06c2d2;
case 0x0c06c2d4u: goto P_0c06c2d4;
case 0x0c06c2d6u: goto P_0c06c2d6;
case 0x0c06c2d8u: goto P_0c06c2d8;
case 0x0c06c2dau: goto P_0c06c2da;
case 0x0c06c2dcu: goto P_0c06c2dc;
case 0x0c06c2deu: goto P_0c06c2de;
case 0x0c06c2e0u: goto P_0c06c2e0;
case 0x0c06c2e2u: goto P_0c06c2e2;
case 0x0c06c2e4u: goto P_0c06c2e4;
case 0x0c06c2e6u: goto P_0c06c2e6;
case 0x0c06c2e8u: goto P_0c06c2e8;
case 0x0c06c2eau: goto P_0c06c2ea;
case 0x0c06c2ecu: goto P_0c06c2ec;
case 0x0c06c2eeu: goto P_0c06c2ee;
case 0x0c06c2f0u: goto P_0c06c2f0;
case 0x0c06c2f2u: goto P_0c06c2f2;
case 0x0c06c2f4u: goto P_0c06c2f4;
case 0x0c06c2f6u: goto P_0c06c2f6;
case 0x0c06c2f8u: goto P_0c06c2f8;
case 0x0c06c2fau: goto P_0c06c2fa;
case 0x0c06c2fcu: goto P_0c06c2fc;
case 0x0c06c2feu: goto P_0c06c2fe;
case 0x0c06c300u: goto P_0c06c300;
case 0x0c06c302u: goto P_0c06c302;
case 0x0c06c304u: goto P_0c06c304;
case 0x0c06c306u: goto P_0c06c306;
case 0x0c06c308u: goto P_0c06c308;
case 0x0c06c30au: goto P_0c06c30a;
case 0x0c06c30cu: goto P_0c06c30c;
case 0x0c06c30eu: goto P_0c06c30e;
case 0x0c06c310u: goto P_0c06c310;
case 0x0c06c312u: goto P_0c06c312;
case 0x0c06c314u: goto P_0c06c314;
case 0x0c06c316u: goto P_0c06c316;
case 0x0c06c318u: goto P_0c06c318;
case 0x0c06c31au: goto P_0c06c31a;
case 0x0c06c31cu: goto P_0c06c31c;
case 0x0c06c31eu: goto P_0c06c31e;
case 0x0c06c320u: goto P_0c06c320;
case 0x0c06c322u: goto P_0c06c322;
case 0x0c06c324u: goto P_0c06c324;
case 0x0c06c326u: goto P_0c06c326;
case 0x0c06c328u: goto P_0c06c328;
case 0x0c06c32au: goto P_0c06c32a;
case 0x0c06c32cu: goto P_0c06c32c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06c07e: /* original 9016, guest PC 0x0c06c07e */
if(!s->budget--) { s->failed_pc=0x0c06c07eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c0aeu,2);
goto P_0c06c080;
P_0c06c080: /* original d711, guest PC 0x0c06c080 */
if(!s->budget--) { s->failed_pc=0x0c06c080u; return 0; }
r[7]=read(ram,0x0c06c0c8u,4);
goto P_0c06c082;
P_0c06c082: /* original 007c, guest PC 0x0c06c082 */
if(!s->budget--) { s->failed_pc=0x0c06c082u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c06c084;
P_0c06c084: /* original 8801, guest PC 0x0c06c084 */
if(!s->budget--) { s->failed_pc=0x0c06c084u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c086;
P_0c06c086: /* original 8d0c, guest PC 0x0c06c086 */
if(!s->budget--) { s->failed_pc=0x0c06c086u; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c06c0a2; }
goto P_0c06c08a;
P_0c06c088: /* original 6603, guest PC 0x0c06c088 */
if(!s->budget--) { s->failed_pc=0x0c06c088u; return 0; }
r[6]=r[0];
goto P_0c06c08a;
P_0c06c08a: /* original 2448, guest PC 0x0c06c08a */
if(!s->budget--) { s->failed_pc=0x0c06c08au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06c08c;
P_0c06c08c: /* original 8b03, guest PC 0x0c06c08c */
if(!s->budget--) { s->failed_pc=0x0c06c08cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c096; }
goto P_0c06c08e;
P_0c06c08e: /* original 2558, guest PC 0x0c06c08e */
if(!s->budget--) { s->failed_pc=0x0c06c08eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c090;
P_0c06c090: /* original 8b01, guest PC 0x0c06c090 */
if(!s->budget--) { s->failed_pc=0x0c06c090u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c096; }
goto P_0c06c092;
P_0c06c092: /* original 000b, guest PC 0x0c06c092 */
if(!s->budget--) { s->failed_pc=0x0c06c092u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c06c094: /* original e001, guest PC 0x0c06c094 */
if(!s->budget--) { s->failed_pc=0x0c06c094u; return 0; }
r[0]=0x00000001u;
goto P_0c06c096;
P_0c06c096: /* original 900b, guest PC 0x0c06c096 */
if(!s->budget--) { s->failed_pc=0x0c06c096u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c0b0u,2);
goto P_0c06c098;
P_0c06c098: /* original 057c, guest PC 0x0c06c098 */
if(!s->budget--) { s->failed_pc=0x0c06c098u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c06c09a;
P_0c06c09a: /* original 3452, guest PC 0x0c06c09a */
if(!s->budget--) { s->failed_pc=0x0c06c09au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[5])!=0);
goto P_0c06c09c;
P_0c06c09c: /* original 8901, guest PC 0x0c06c09c */
if(!s->budget--) { s->failed_pc=0x0c06c09cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c0a2; }
goto P_0c06c09e;
P_0c06c09e: /* original 000b, guest PC 0x0c06c09e */
if(!s->budget--) { s->failed_pc=0x0c06c09eu; return 0; }
target=r[16];
r[0]=0x00000002u;
s->pc=target; return ram->oob==0;
P_0c06c0a0: /* original e002, guest PC 0x0c06c0a0 */
if(!s->budget--) { s->failed_pc=0x0c06c0a0u; return 0; }
r[0]=0x00000002u;
goto P_0c06c0a2;
P_0c06c0a2: /* original e003, guest PC 0x0c06c0a2 */
if(!s->budget--) { s->failed_pc=0x0c06c0a2u; return 0; }
r[0]=0x00000003u;
goto P_0c06c0a4;
P_0c06c0a4: /* original 000b, guest PC 0x0c06c0a4 */
if(!s->budget--) { s->failed_pc=0x0c06c0a4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c0a6: /* original 0009, guest PC 0x0c06c0a6 */
if(!s->budget--) { s->failed_pc=0x0c06c0a6u; return 0; }
if(!vf3_matrix_family(0x0c06c0a8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c0a8u; return 0; } return 1;
P_0c06c0cc: /* original 2fe6, guest PC 0x0c06c0cc */
if(!s->budget--) { s->failed_pc=0x0c06c0ccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c0ce;
P_0c06c0ce: /* original 2fd6, guest PC 0x0c06c0ce */
if(!s->budget--) { s->failed_pc=0x0c06c0ceu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c0d0;
P_0c06c0d0: /* original 2fc6, guest PC 0x0c06c0d0 */
if(!s->budget--) { s->failed_pc=0x0c06c0d0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c0d2;
P_0c06c0d2: /* original 2fb6, guest PC 0x0c06c0d2 */
if(!s->budget--) { s->failed_pc=0x0c06c0d2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c0d4;
P_0c06c0d4: /* original 2fa6, guest PC 0x0c06c0d4 */
if(!s->budget--) { s->failed_pc=0x0c06c0d4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c0d6;
P_0c06c0d6: /* original de48, guest PC 0x0c06c0d6 */
if(!s->budget--) { s->failed_pc=0x0c06c0d6u; return 0; }
r[14]=read(ram,0x0c06c1f8u,4);
goto P_0c06c0d8;
P_0c06c0d8: /* original 9085, guest PC 0x0c06c0d8 */
if(!s->budget--) { s->failed_pc=0x0c06c0d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1e6u,2);
goto P_0c06c0da;
P_0c06c0da: /* original 4f22, guest PC 0x0c06c0da */
if(!s->budget--) { s->failed_pc=0x0c06c0dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c0dc;
P_0c06c0dc: /* original 04ec, guest PC 0x0c06c0dc */
if(!s->budget--) { s->failed_pc=0x0c06c0dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c0de;
P_0c06c0de: /* original 7001, guest PC 0x0c06c0de */
if(!s->budget--) { s->failed_pc=0x0c06c0deu; return 0; }
r[0]+=0x00000001u;
goto P_0c06c0e0;
P_0c06c0e0: /* original dd44, guest PC 0x0c06c0e0 */
if(!s->budget--) { s->failed_pc=0x0c06c0e0u; return 0; }
r[13]=read(ram,0x0c06c1f4u,4);
goto P_0c06c0e2;
P_0c06c0e2: /* original 7ffc, guest PC 0x0c06c0e2 */
if(!s->budget--) { s->failed_pc=0x0c06c0e2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c0e4;
P_0c06c0e4: /* original bfcb, guest PC 0x0c06c0e4 */
if(!s->budget--) { s->failed_pc=0x0c06c0e4u; return 0; }
target=code_base|0x0c06c07eu; r[16]=code_base|0x0c06c0e8u;
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c0e8u) { target=s->pc; goto dispatch; }
goto P_0c06c0e8;
P_0c06c0e6: /* original 05ec, guest PC 0x0c06c0e6 */
if(!s->budget--) { s->failed_pc=0x0c06c0e6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c0e8;
P_0c06c0e8: /* original e320, guest PC 0x0c06c0e8 */
if(!s->budget--) { s->failed_pc=0x0c06c0e8u; return 0; }
r[3]=0x00000020u;
goto P_0c06c0ea;
P_0c06c0ea: /* original 2f02, guest PC 0x0c06c0ea */
if(!s->budget--) { s->failed_pc=0x0c06c0eau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06c0ec;
P_0c06c0ec: /* original 957c, guest PC 0x0c06c0ec */
if(!s->budget--) { s->failed_pc=0x0c06c0ecu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1e8u,2);
goto P_0c06c0ee;
P_0c06c0ee: /* original e613, guest PC 0x0c06c0ee */
if(!s->budget--) { s->failed_pc=0x0c06c0eeu; return 0; }
r[6]=0x00000013u;
goto P_0c06c0f0;
P_0c06c0f0: /* original 2f36, guest PC 0x0c06c0f0 */
if(!s->budget--) { s->failed_pc=0x0c06c0f0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c0f2;
P_0c06c0f2: /* original e702, guest PC 0x0c06c0f2 */
if(!s->budget--) { s->failed_pc=0x0c06c0f2u; return 0; }
r[7]=0x00000002u;
goto P_0c06c0f4;
P_0c06c0f4: /* original d241, guest PC 0x0c06c0f4 */
if(!s->budget--) { s->failed_pc=0x0c06c0f4u; return 0; }
r[2]=read(ram,0x0c06c1fcu,4);
goto P_0c06c0f6;
P_0c06c0f6: /* original 420b, guest PC 0x0c06c0f6 */
if(!s->budget--) { s->failed_pc=0x0c06c0f6u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c0fau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c0fau) { target=s->pc; goto dispatch; }
goto P_0c06c0fa;
P_0c06c0f8: /* original 64d3, guest PC 0x0c06c0f8 */
if(!s->budget--) { s->failed_pc=0x0c06c0f8u; return 0; }
r[4]=r[13];
goto P_0c06c0fa;
P_0c06c0fa: /* original 55f1, guest PC 0x0c06c0fa */
if(!s->budget--) { s->failed_pc=0x0c06c0fau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06c0fc;
P_0c06c0fc: /* original e300, guest PC 0x0c06c0fc */
if(!s->budget--) { s->failed_pc=0x0c06c0fcu; return 0; }
r[3]=0x00000000u;
goto P_0c06c0fe;
P_0c06c0fe: /* original d040, guest PC 0x0c06c0fe */
if(!s->budget--) { s->failed_pc=0x0c06c0feu; return 0; }
r[0]=read(ram,0x0c06c200u,4);
goto P_0c06c100;
P_0c06c100: /* original 6733, guest PC 0x0c06c100 */
if(!s->budget--) { s->failed_pc=0x0c06c100u; return 0; }
r[7]=r[3];
goto P_0c06c102;
P_0c06c102: /* original 4508, guest PC 0x0c06c102 */
if(!s->budget--) { s->failed_pc=0x0c06c102u; return 0; }
r[5]<<=2;
goto P_0c06c104;
P_0c06c104: /* original 9470, guest PC 0x0c06c104 */
if(!s->budget--) { s->failed_pc=0x0c06c104u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1e8u,2);
goto P_0c06c106;
P_0c06c106: /* original 055e, guest PC 0x0c06c106 */
if(!s->budget--) { s->failed_pc=0x0c06c106u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c06c108;
P_0c06c108: /* original 2f36, guest PC 0x0c06c108 */
if(!s->budget--) { s->failed_pc=0x0c06c108u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c10a;
P_0c06c10a: /* original d23e, guest PC 0x0c06c10a */
if(!s->budget--) { s->failed_pc=0x0c06c10au; return 0; }
r[2]=read(ram,0x0c06c204u,4);
goto P_0c06c10c;
P_0c06c10c: /* original 420b, guest PC 0x0c06c10c */
if(!s->budget--) { s->failed_pc=0x0c06c10cu; return 0; }
target=r[2];
r[16]=code_base|0x0c06c110u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c110u) { target=s->pc; goto dispatch; }
goto P_0c06c110;
P_0c06c10e: /* original 66d3, guest PC 0x0c06c10e */
if(!s->budget--) { s->failed_pc=0x0c06c10eu; return 0; }
r[6]=r[13];
goto P_0c06c110;
P_0c06c110: /* original e61e, guest PC 0x0c06c110 */
if(!s->budget--) { s->failed_pc=0x0c06c110u; return 0; }
r[6]=0x0000001eu;
goto P_0c06c112;
P_0c06c112: /* original e527, guest PC 0x0c06c112 */
if(!s->budget--) { s->failed_pc=0x0c06c112u; return 0; }
r[5]=0x00000027u;
goto P_0c06c114;
P_0c06c114: /* original 7f08, guest PC 0x0c06c114 */
if(!s->budget--) { s->failed_pc=0x0c06c114u; return 0; }
r[15]+=0x00000008u;
goto P_0c06c116;
P_0c06c116: /* original e703, guest PC 0x0c06c116 */
if(!s->budget--) { s->failed_pc=0x0c06c116u; return 0; }
r[7]=0x00000003u;
goto P_0c06c118;
P_0c06c118: /* original b15a, guest PC 0x0c06c118 */
if(!s->budget--) { s->failed_pc=0x0c06c118u; return 0; }
target=code_base|0x0c06c3d0u; r[16]=code_base|0x0c06c11cu;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c11cu) { target=s->pc; goto dispatch; }
goto P_0c06c11c;
P_0c06c11a: /* original e402, guest PC 0x0c06c11a */
if(!s->budget--) { s->failed_pc=0x0c06c11au; return 0; }
r[4]=0x00000002u;
goto P_0c06c11c;
P_0c06c11c: /* original 9063, guest PC 0x0c06c11c */
if(!s->budget--) { s->failed_pc=0x0c06c11cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1e6u,2);
goto P_0c06c11e;
P_0c06c11e: /* original e62b, guest PC 0x0c06c11e */
if(!s->budget--) { s->failed_pc=0x0c06c11eu; return 0; }
r[6]=0x0000002bu;
goto P_0c06c120;
P_0c06c120: /* original e700, guest PC 0x0c06c120 */
if(!s->budget--) { s->failed_pc=0x0c06c120u; return 0; }
r[7]=0x00000000u;
goto P_0c06c122;
P_0c06c122: /* original 04ec, guest PC 0x0c06c122 */
if(!s->budget--) { s->failed_pc=0x0c06c122u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c124;
P_0c06c124: /* original b070, guest PC 0x0c06c124 */
if(!s->budget--) { s->failed_pc=0x0c06c124u; return 0; }
target=code_base|0x0c06c208u; r[16]=code_base|0x0c06c128u;
r[5]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c128u) { target=s->pc; goto dispatch; }
goto P_0c06c128;
P_0c06c126: /* original 6563, guest PC 0x0c06c126 */
if(!s->budget--) { s->failed_pc=0x0c06c126u; return 0; }
r[5]=r[6];
goto P_0c06c128;
P_0c06c128: /* original 905f, guest PC 0x0c06c128 */
if(!s->budget--) { s->failed_pc=0x0c06c128u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1eau,2);
goto P_0c06c12a;
P_0c06c12a: /* original e62b, guest PC 0x0c06c12a */
if(!s->budget--) { s->failed_pc=0x0c06c12au; return 0; }
r[6]=0x0000002bu;
goto P_0c06c12c;
P_0c06c12c: /* original e701, guest PC 0x0c06c12c */
if(!s->budget--) { s->failed_pc=0x0c06c12cu; return 0; }
r[7]=0x00000001u;
goto P_0c06c12e;
P_0c06c12e: /* original 04ec, guest PC 0x0c06c12e */
if(!s->budget--) { s->failed_pc=0x0c06c12eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c130;
P_0c06c130: /* original b06a, guest PC 0x0c06c130 */
if(!s->budget--) { s->failed_pc=0x0c06c130u; return 0; }
target=code_base|0x0c06c208u; r[16]=code_base|0x0c06c134u;
r[5]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c134u) { target=s->pc; goto dispatch; }
goto P_0c06c134;
P_0c06c132: /* original e502, guest PC 0x0c06c132 */
if(!s->budget--) { s->failed_pc=0x0c06c132u; return 0; }
r[5]=0x00000002u;
goto P_0c06c134;
P_0c06c134: /* original 905a, guest PC 0x0c06c134 */
if(!s->budget--) { s->failed_pc=0x0c06c134u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1ecu,2);
goto P_0c06c136;
P_0c06c136: /* original e52d, guest PC 0x0c06c136 */
if(!s->budget--) { s->failed_pc=0x0c06c136u; return 0; }
r[5]=0x0000002du;
goto P_0c06c138;
P_0c06c138: /* original 06ec, guest PC 0x0c06c138 */
if(!s->budget--) { s->failed_pc=0x0c06c138u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c13a;
P_0c06c13a: /* original b172, guest PC 0x0c06c13a */
if(!s->budget--) { s->failed_pc=0x0c06c13au; return 0; }
target=code_base|0x0c06c422u; r[16]=code_base|0x0c06c13eu;
r[4]=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c13eu) { target=s->pc; goto dispatch; }
goto P_0c06c13e;
P_0c06c13c: /* original e415, guest PC 0x0c06c13c */
if(!s->budget--) { s->failed_pc=0x0c06c13cu; return 0; }
r[4]=0x00000015u;
goto P_0c06c13e;
P_0c06c13e: /* original 9056, guest PC 0x0c06c13e */
if(!s->budget--) { s->failed_pc=0x0c06c13eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1eeu,2);
goto P_0c06c140;
P_0c06c140: /* original e52d, guest PC 0x0c06c140 */
if(!s->budget--) { s->failed_pc=0x0c06c140u; return 0; }
r[5]=0x0000002du;
goto P_0c06c142;
P_0c06c142: /* original 06ec, guest PC 0x0c06c142 */
if(!s->budget--) { s->failed_pc=0x0c06c142u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c144;
P_0c06c144: /* original b16d, guest PC 0x0c06c144 */
if(!s->budget--) { s->failed_pc=0x0c06c144u; return 0; }
target=code_base|0x0c06c422u; r[16]=code_base|0x0c06c148u;
r[4]=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c148u) { target=s->pc; goto dispatch; }
goto P_0c06c148;
P_0c06c146: /* original e421, guest PC 0x0c06c146 */
if(!s->budget--) { s->failed_pc=0x0c06c146u; return 0; }
r[4]=0x00000021u;
goto P_0c06c148;
P_0c06c148: /* original 904f, guest PC 0x0c06c148 */
if(!s->budget--) { s->failed_pc=0x0c06c148u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1eau,2);
goto P_0c06c14a;
P_0c06c14a: /* original 04ec, guest PC 0x0c06c14a */
if(!s->budget--) { s->failed_pc=0x0c06c14au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c14c;
P_0c06c14c: /* original 7001, guest PC 0x0c06c14c */
if(!s->budget--) { s->failed_pc=0x0c06c14cu; return 0; }
r[0]+=0x00000001u;
goto P_0c06c14e;
P_0c06c14e: /* original bf96, guest PC 0x0c06c14e */
if(!s->budget--) { s->failed_pc=0x0c06c14eu; return 0; }
target=code_base|0x0c06c07eu; r[16]=code_base|0x0c06c152u;
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c152u) { target=s->pc; goto dispatch; }
goto P_0c06c152;
P_0c06c150: /* original 05ec, guest PC 0x0c06c150 */
if(!s->budget--) { s->failed_pc=0x0c06c150u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c152;
P_0c06c152: /* original 8801, guest PC 0x0c06c152 */
if(!s->budget--) { s->failed_pc=0x0c06c152u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c154;
P_0c06c154: /* original 6a03, guest PC 0x0c06c154 */
if(!s->budget--) { s->failed_pc=0x0c06c154u; return 0; }
r[10]=r[0];
goto P_0c06c156;
P_0c06c156: /* original 8d06, guest PC 0x0c06c156 */
if(!s->budget--) { s->failed_pc=0x0c06c156u; return 0; }
cond=r[17]&1u;
r[4]=0x00000027u;
if(cond) { goto P_0c06c166; }
goto P_0c06c15a;
P_0c06c158: /* original e427, guest PC 0x0c06c158 */
if(!s->budget--) { s->failed_pc=0x0c06c158u; return 0; }
r[4]=0x00000027u;
goto P_0c06c15a;
P_0c06c15a: /* original 60a3, guest PC 0x0c06c15a */
if(!s->budget--) { s->failed_pc=0x0c06c15au; return 0; }
r[0]=r[10];
goto P_0c06c15c;
P_0c06c15c: /* original 8803, guest PC 0x0c06c15c */
if(!s->budget--) { s->failed_pc=0x0c06c15cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c15e;
P_0c06c15e: /* original 8d0e, guest PC 0x0c06c15e */
if(!s->budget--) { s->failed_pc=0x0c06c15eu; return 0; }
cond=r[17]&1u;
r[5]=0x0000002au;
if(cond) { goto P_0c06c17e; }
goto P_0c06c162;
P_0c06c160: /* original e52a, guest PC 0x0c06c160 */
if(!s->budget--) { s->failed_pc=0x0c06c160u; return 0; }
r[5]=0x0000002au;
goto P_0c06c162;
P_0c06c162: /* original a00c, guest PC 0x0c06c162 */
if(!s->budget--) { s->failed_pc=0x0c06c162u; return 0; }
goto P_0c06c17e;
P_0c06c164: /* original 0009, guest PC 0x0c06c164 */
if(!s->budget--) { s->failed_pc=0x0c06c164u; return 0; }
goto P_0c06c166;
P_0c06c166: /* original e220, guest PC 0x0c06c166 */
if(!s->budget--) { s->failed_pc=0x0c06c166u; return 0; }
r[2]=0x00000020u;
goto P_0c06c168;
P_0c06c168: /* original 9542, guest PC 0x0c06c168 */
if(!s->budget--) { s->failed_pc=0x0c06c168u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1f0u,2);
goto P_0c06c16a;
P_0c06c16a: /* original e613, guest PC 0x0c06c16a */
if(!s->budget--) { s->failed_pc=0x0c06c16au; return 0; }
r[6]=0x00000013u;
goto P_0c06c16c;
P_0c06c16c: /* original 6c43, guest PC 0x0c06c16c */
if(!s->budget--) { s->failed_pc=0x0c06c16cu; return 0; }
r[12]=r[4];
goto P_0c06c16e;
P_0c06c16e: /* original eb2e, guest PC 0x0c06c16e */
if(!s->budget--) { s->failed_pc=0x0c06c16eu; return 0; }
r[11]=0x0000002eu;
goto P_0c06c170;
P_0c06c170: /* original 2f26, guest PC 0x0c06c170 */
if(!s->budget--) { s->failed_pc=0x0c06c170u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c172;
P_0c06c172: /* original d322, guest PC 0x0c06c172 */
if(!s->budget--) { s->failed_pc=0x0c06c172u; return 0; }
r[3]=read(ram,0x0c06c1fcu,4);
goto P_0c06c174;
P_0c06c174: /* original e702, guest PC 0x0c06c174 */
if(!s->budget--) { s->failed_pc=0x0c06c174u; return 0; }
r[7]=0x00000002u;
goto P_0c06c176;
P_0c06c176: /* original 430b, guest PC 0x0c06c176 */
if(!s->budget--) { s->failed_pc=0x0c06c176u; return 0; }
target=r[3];
r[16]=code_base|0x0c06c17au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c17au) { target=s->pc; goto dispatch; }
goto P_0c06c17a;
P_0c06c178: /* original 64d3, guest PC 0x0c06c178 */
if(!s->budget--) { s->failed_pc=0x0c06c178u; return 0; }
r[4]=r[13];
goto P_0c06c17a;
P_0c06c17a: /* original a002, guest PC 0x0c06c17a */
if(!s->budget--) { s->failed_pc=0x0c06c17au; return 0; }
r[15]+=0x00000004u;
goto P_0c06c182;
P_0c06c17c: /* original 7f04, guest PC 0x0c06c17c */
if(!s->budget--) { s->failed_pc=0x0c06c17cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c17e;
P_0c06c17e: /* original 6c43, guest PC 0x0c06c17e */
if(!s->budget--) { s->failed_pc=0x0c06c17eu; return 0; }
r[12]=r[4];
goto P_0c06c180;
P_0c06c180: /* original 6b53, guest PC 0x0c06c180 */
if(!s->budget--) { s->failed_pc=0x0c06c180u; return 0; }
r[11]=r[5];
goto P_0c06c182;
P_0c06c182: /* original 64b3, guest PC 0x0c06c182 */
if(!s->budget--) { s->failed_pc=0x0c06c182u; return 0; }
r[4]=r[11];
goto P_0c06c184;
P_0c06c184: /* original e307, guest PC 0x0c06c184 */
if(!s->budget--) { s->failed_pc=0x0c06c184u; return 0; }
r[3]=0x00000007u;
goto P_0c06c186;
P_0c06c186: /* original 62c3, guest PC 0x0c06c186 */
if(!s->budget--) { s->failed_pc=0x0c06c186u; return 0; }
r[2]=r[12];
goto P_0c06c188;
P_0c06c188: /* original 65a3, guest PC 0x0c06c188 */
if(!s->budget--) { s->failed_pc=0x0c06c188u; return 0; }
r[5]=r[10];
goto P_0c06c18a;
P_0c06c18a: /* original 423d, guest PC 0x0c06c18a */
if(!s->budget--) { s->failed_pc=0x0c06c18au; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c06c18c;
P_0c06c18c: /* original d01c, guest PC 0x0c06c18c */
if(!s->budget--) { s->failed_pc=0x0c06c18cu; return 0; }
r[0]=read(ram,0x0c06c200u,4);
goto P_0c06c18e;
P_0c06c18e: /* original 4400, guest PC 0x0c06c18e */
if(!s->budget--) { s->failed_pc=0x0c06c18eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c190;
P_0c06c190: /* original 242b, guest PC 0x0c06c190 */
if(!s->budget--) { s->failed_pc=0x0c06c190u; return 0; }
r[4]|=r[2];
goto P_0c06c192;
P_0c06c192: /* original 4508, guest PC 0x0c06c192 */
if(!s->budget--) { s->failed_pc=0x0c06c192u; return 0; }
r[5]<<=2;
goto P_0c06c194;
P_0c06c194: /* original e100, guest PC 0x0c06c194 */
if(!s->budget--) { s->failed_pc=0x0c06c194u; return 0; }
r[1]=0x00000000u;
goto P_0c06c196;
P_0c06c196: /* original 055e, guest PC 0x0c06c196 */
if(!s->budget--) { s->failed_pc=0x0c06c196u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c06c198;
P_0c06c198: /* original 6713, guest PC 0x0c06c198 */
if(!s->budget--) { s->failed_pc=0x0c06c198u; return 0; }
r[7]=r[1];
goto P_0c06c19a;
P_0c06c19a: /* original 2f16, guest PC 0x0c06c19a */
if(!s->budget--) { s->failed_pc=0x0c06c19au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c19c;
P_0c06c19c: /* original d219, guest PC 0x0c06c19c */
if(!s->budget--) { s->failed_pc=0x0c06c19cu; return 0; }
r[2]=read(ram,0x0c06c204u,4);
goto P_0c06c19e;
P_0c06c19e: /* original 420b, guest PC 0x0c06c19e */
if(!s->budget--) { s->failed_pc=0x0c06c19eu; return 0; }
target=r[2];
r[16]=code_base|0x0c06c1a2u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c1a2u) { target=s->pc; goto dispatch; }
goto P_0c06c1a2;
P_0c06c1a0: /* original 66d3, guest PC 0x0c06c1a0 */
if(!s->budget--) { s->failed_pc=0x0c06c1a0u; return 0; }
r[6]=r[13];
goto P_0c06c1a2;
P_0c06c1a2: /* original 65c3, guest PC 0x0c06c1a2 */
if(!s->budget--) { s->failed_pc=0x0c06c1a2u; return 0; }
r[5]=r[12];
goto P_0c06c1a4;
P_0c06c1a4: /* original e61e, guest PC 0x0c06c1a4 */
if(!s->budget--) { s->failed_pc=0x0c06c1a4u; return 0; }
r[6]=0x0000001eu;
goto P_0c06c1a6;
P_0c06c1a6: /* original e703, guest PC 0x0c06c1a6 */
if(!s->budget--) { s->failed_pc=0x0c06c1a6u; return 0; }
r[7]=0x00000003u;
goto P_0c06c1a8;
P_0c06c1a8: /* original b112, guest PC 0x0c06c1a8 */
if(!s->budget--) { s->failed_pc=0x0c06c1a8u; return 0; }
target=code_base|0x0c06c3d0u; r[16]=code_base|0x0c06c1acu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c1acu) { target=s->pc; goto dispatch; }
goto P_0c06c1ac;
P_0c06c1aa: /* original 64b3, guest PC 0x0c06c1aa */
if(!s->budget--) { s->failed_pc=0x0c06c1aau; return 0; }
r[4]=r[11];
goto P_0c06c1ac;
P_0c06c1ac: /* original 901b, guest PC 0x0c06c1ac */
if(!s->budget--) { s->failed_pc=0x0c06c1acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1e6u,2);
goto P_0c06c1ae;
P_0c06c1ae: /* original e62b, guest PC 0x0c06c1ae */
if(!s->budget--) { s->failed_pc=0x0c06c1aeu; return 0; }
r[6]=0x0000002bu;
goto P_0c06c1b0;
P_0c06c1b0: /* original e700, guest PC 0x0c06c1b0 */
if(!s->budget--) { s->failed_pc=0x0c06c1b0u; return 0; }
r[7]=0x00000000u;
goto P_0c06c1b2;
P_0c06c1b2: /* original 04ec, guest PC 0x0c06c1b2 */
if(!s->budget--) { s->failed_pc=0x0c06c1b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c1b4;
P_0c06c1b4: /* original b028, guest PC 0x0c06c1b4 */
if(!s->budget--) { s->failed_pc=0x0c06c1b4u; return 0; }
target=code_base|0x0c06c208u; r[16]=code_base|0x0c06c1b8u;
r[5]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c1b8u) { target=s->pc; goto dispatch; }
goto P_0c06c1b8;
P_0c06c1b6: /* original 6563, guest PC 0x0c06c1b6 */
if(!s->budget--) { s->failed_pc=0x0c06c1b6u; return 0; }
r[5]=r[6];
goto P_0c06c1b8;
P_0c06c1b8: /* original 9017, guest PC 0x0c06c1b8 */
if(!s->budget--) { s->failed_pc=0x0c06c1b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1eau,2);
goto P_0c06c1ba;
P_0c06c1ba: /* original e62b, guest PC 0x0c06c1ba */
if(!s->budget--) { s->failed_pc=0x0c06c1bau; return 0; }
r[6]=0x0000002bu;
goto P_0c06c1bc;
P_0c06c1bc: /* original e701, guest PC 0x0c06c1bc */
if(!s->budget--) { s->failed_pc=0x0c06c1bcu; return 0; }
r[7]=0x00000001u;
goto P_0c06c1be;
P_0c06c1be: /* original 04ec, guest PC 0x0c06c1be */
if(!s->budget--) { s->failed_pc=0x0c06c1beu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c1c0;
P_0c06c1c0: /* original b022, guest PC 0x0c06c1c0 */
if(!s->budget--) { s->failed_pc=0x0c06c1c0u; return 0; }
target=code_base|0x0c06c208u; r[16]=code_base|0x0c06c1c4u;
r[5]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c1c4u) { target=s->pc; goto dispatch; }
goto P_0c06c1c4;
P_0c06c1c2: /* original e502, guest PC 0x0c06c1c2 */
if(!s->budget--) { s->failed_pc=0x0c06c1c2u; return 0; }
r[5]=0x00000002u;
goto P_0c06c1c4;
P_0c06c1c4: /* original 9012, guest PC 0x0c06c1c4 */
if(!s->budget--) { s->failed_pc=0x0c06c1c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1ecu,2);
goto P_0c06c1c6;
P_0c06c1c6: /* original e52d, guest PC 0x0c06c1c6 */
if(!s->budget--) { s->failed_pc=0x0c06c1c6u; return 0; }
r[5]=0x0000002du;
goto P_0c06c1c8;
P_0c06c1c8: /* original 06ec, guest PC 0x0c06c1c8 */
if(!s->budget--) { s->failed_pc=0x0c06c1c8u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c1ca;
P_0c06c1ca: /* original b12a, guest PC 0x0c06c1ca */
if(!s->budget--) { s->failed_pc=0x0c06c1cau; return 0; }
target=code_base|0x0c06c422u; r[16]=code_base|0x0c06c1ceu;
r[4]=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c1ceu) { target=s->pc; goto dispatch; }
goto P_0c06c1ce;
P_0c06c1cc: /* original e415, guest PC 0x0c06c1cc */
if(!s->budget--) { s->failed_pc=0x0c06c1ccu; return 0; }
r[4]=0x00000015u;
goto P_0c06c1ce;
P_0c06c1ce: /* original 7f08, guest PC 0x0c06c1ce */
if(!s->budget--) { s->failed_pc=0x0c06c1ceu; return 0; }
r[15]+=0x00000008u;
goto P_0c06c1d0;
P_0c06c1d0: /* original 900d, guest PC 0x0c06c1d0 */
if(!s->budget--) { s->failed_pc=0x0c06c1d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c1eeu,2);
goto P_0c06c1d2;
P_0c06c1d2: /* original 4f26, guest PC 0x0c06c1d2 */
if(!s->budget--) { s->failed_pc=0x0c06c1d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c1d4;
P_0c06c1d4: /* original 06ec, guest PC 0x0c06c1d4 */
if(!s->budget--) { s->failed_pc=0x0c06c1d4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c1d6;
P_0c06c1d6: /* original e52d, guest PC 0x0c06c1d6 */
if(!s->budget--) { s->failed_pc=0x0c06c1d6u; return 0; }
r[5]=0x0000002du;
goto P_0c06c1d8;
P_0c06c1d8: /* original e421, guest PC 0x0c06c1d8 */
if(!s->budget--) { s->failed_pc=0x0c06c1d8u; return 0; }
r[4]=0x00000021u;
goto P_0c06c1da;
P_0c06c1da: /* original 6af6, guest PC 0x0c06c1da */
if(!s->budget--) { s->failed_pc=0x0c06c1dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06c1dc;
P_0c06c1dc: /* original 6bf6, guest PC 0x0c06c1dc */
if(!s->budget--) { s->failed_pc=0x0c06c1dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c1de;
P_0c06c1de: /* original 6cf6, guest PC 0x0c06c1de */
if(!s->budget--) { s->failed_pc=0x0c06c1deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c1e0;
P_0c06c1e0: /* original 6df6, guest PC 0x0c06c1e0 */
if(!s->budget--) { s->failed_pc=0x0c06c1e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c1e2;
P_0c06c1e2: /* original a11e, guest PC 0x0c06c1e2 */
if(!s->budget--) { s->failed_pc=0x0c06c1e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c422u,s,ram);
P_0c06c1e4: /* original 6ef6, guest PC 0x0c06c1e4 */
if(!s->budget--) { s->failed_pc=0x0c06c1e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06c1e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c1e6u; return 0; } return 1;
P_0c06c208: /* original 2fe6, guest PC 0x0c06c208 */
if(!s->budget--) { s->failed_pc=0x0c06c208u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c20a;
P_0c06c20a: /* original 6e53, guest PC 0x0c06c20a */
if(!s->budget--) { s->failed_pc=0x0c06c20au; return 0; }
r[14]=r[5];
goto P_0c06c20c;
P_0c06c20c: /* original 2fd6, guest PC 0x0c06c20c */
if(!s->budget--) { s->failed_pc=0x0c06c20cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c20e;
P_0c06c20e: /* original 2fc6, guest PC 0x0c06c20e */
if(!s->budget--) { s->failed_pc=0x0c06c20eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c210;
P_0c06c210: /* original 2fb6, guest PC 0x0c06c210 */
if(!s->budget--) { s->failed_pc=0x0c06c210u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c212;
P_0c06c212: /* original 6b43, guest PC 0x0c06c212 */
if(!s->budget--) { s->failed_pc=0x0c06c212u; return 0; }
r[11]=r[4];
goto P_0c06c214;
P_0c06c214: /* original 2fa6, guest PC 0x0c06c214 */
if(!s->budget--) { s->failed_pc=0x0c06c214u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c216;
P_0c06c216: /* original 2f96, guest PC 0x0c06c216 */
if(!s->budget--) { s->failed_pc=0x0c06c216u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c218;
P_0c06c218: /* original 2f86, guest PC 0x0c06c218 */
if(!s->budget--) { s->failed_pc=0x0c06c218u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c21a;
P_0c06c21a: /* original d847, guest PC 0x0c06c21a */
if(!s->budget--) { s->failed_pc=0x0c06c21au; return 0; }
r[8]=read(ram,0x0c06c338u,4);
goto P_0c06c21c;
P_0c06c21c: /* original 9087, guest PC 0x0c06c21c */
if(!s->budget--) { s->failed_pc=0x0c06c21cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c32eu,2);
goto P_0c06c21e;
P_0c06c21e: /* original 4f22, guest PC 0x0c06c21e */
if(!s->budget--) { s->failed_pc=0x0c06c21eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c220;
P_0c06c220: /* original 008c, guest PC 0x0c06c220 */
if(!s->budget--) { s->failed_pc=0x0c06c220u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c06c222;
P_0c06c222: /* original dd44, guest PC 0x0c06c222 */
if(!s->budget--) { s->failed_pc=0x0c06c222u; return 0; }
r[13]=read(ram,0x0c06c334u,4);
goto P_0c06c224;
P_0c06c224: /* original 8801, guest PC 0x0c06c224 */
if(!s->budget--) { s->failed_pc=0x0c06c224u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c226;
P_0c06c226: /* original 7ff8, guest PC 0x0c06c226 */
if(!s->budget--) { s->failed_pc=0x0c06c226u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c228;
P_0c06c228: /* original 8d6e, guest PC 0x0c06c228 */
if(!s->budget--) { s->failed_pc=0x0c06c228u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06c308; }
goto P_0c06c22c;
P_0c06c22a: /* original 6403, guest PC 0x0c06c22a */
if(!s->budget--) { s->failed_pc=0x0c06c22au; return 0; }
r[4]=r[0];
goto P_0c06c22c;
P_0c06c22c: /* original 2778, guest PC 0x0c06c22c */
if(!s->budget--) { s->failed_pc=0x0c06c22cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06c22e;
P_0c06c22e: /* original 8906, guest PC 0x0c06c22e */
if(!s->budget--) { s->failed_pc=0x0c06c22eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c23e; }
goto P_0c06c230;
P_0c06c230: /* original 907e, guest PC 0x0c06c230 */
if(!s->budget--) { s->failed_pc=0x0c06c230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c330u,2);
goto P_0c06c232;
P_0c06c232: /* original 7e01, guest PC 0x0c06c232 */
if(!s->budget--) { s->failed_pc=0x0c06c232u; return 0; }
r[14]+=0x00000001u;
goto P_0c06c234;
P_0c06c234: /* original 008c, guest PC 0x0c06c234 */
if(!s->budget--) { s->failed_pc=0x0c06c234u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c06c236;
P_0c06c236: /* original 8801, guest PC 0x0c06c236 */
if(!s->budget--) { s->failed_pc=0x0c06c236u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c238;
P_0c06c238: /* original 8f01, guest PC 0x0c06c238 */
if(!s->budget--) { s->failed_pc=0x0c06c238u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06c23e; }
goto P_0c06c23c;
P_0c06c23a: /* original 6403, guest PC 0x0c06c23a */
if(!s->budget--) { s->failed_pc=0x0c06c23au; return 0; }
r[4]=r[0];
goto P_0c06c23c;
P_0c06c23c: /* original 7e05, guest PC 0x0c06c23c */
if(!s->budget--) { s->failed_pc=0x0c06c23cu; return 0; }
r[14]+=0x00000005u;
goto P_0c06c23e;
P_0c06c23e: /* original 6963, guest PC 0x0c06c23e */
if(!s->budget--) { s->failed_pc=0x0c06c23eu; return 0; }
r[9]=r[6];
goto P_0c06c240;
P_0c06c240: /* original d43e, guest PC 0x0c06c240 */
if(!s->budget--) { s->failed_pc=0x0c06c240u; return 0; }
r[4]=read(ram,0x0c06c33cu,4);
goto P_0c06c242;
P_0c06c242: /* original e201, guest PC 0x0c06c242 */
if(!s->budget--) { s->failed_pc=0x0c06c242u; return 0; }
r[2]=0x00000001u;
goto P_0c06c244;
P_0c06c244: /* original 6ae3, guest PC 0x0c06c244 */
if(!s->budget--) { s->failed_pc=0x0c06c244u; return 0; }
r[10]=r[14];
goto P_0c06c246;
P_0c06c246: /* original e307, guest PC 0x0c06c246 */
if(!s->budget--) { s->failed_pc=0x0c06c246u; return 0; }
r[3]=0x00000007u;
goto P_0c06c248;
P_0c06c248: /* original 493d, guest PC 0x0c06c248 */
if(!s->budget--) { s->failed_pc=0x0c06c248u; return 0; }
r[9]=(r[3]&0x80000000u)?((r[3]&31u)?r[9]>>((-r[3])&31u):0):r[9]<<(r[3]&31u);
goto P_0c06c24a;
P_0c06c24a: /* original 4a00, guest PC 0x0c06c24a */
if(!s->budget--) { s->failed_pc=0x0c06c24au; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c06c24c;
P_0c06c24c: /* original 3b26, guest PC 0x0c06c24c */
if(!s->budget--) { s->failed_pc=0x0c06c24cu; return 0; }
r[17]=(r[17]&~1u)|((r[11]>r[2])!=0);
goto P_0c06c24e;
P_0c06c24e: /* original 8d02, guest PC 0x0c06c24e */
if(!s->budget--) { s->failed_pc=0x0c06c24eu; return 0; }
cond=r[17]&1u;
r[10]|=r[9];
if(cond) { goto P_0c06c256; }
goto P_0c06c252;
P_0c06c250: /* original 2a9b, guest PC 0x0c06c250 */
if(!s->budget--) { s->failed_pc=0x0c06c250u; return 0; }
r[10]|=r[9];
goto P_0c06c252;
P_0c06c252: /* original a002, guest PC 0x0c06c252 */
if(!s->budget--) { s->failed_pc=0x0c06c252u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c06c25a;
P_0c06c254: /* original 5c44, guest PC 0x0c06c254 */
if(!s->budget--) { s->failed_pc=0x0c06c254u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c06c256;
P_0c06c256: /* original 5c45, guest PC 0x0c06c256 */
if(!s->budget--) { s->failed_pc=0x0c06c256u; return 0; }
r[12]=read(ram,r[4]+20,4);
goto P_0c06c258;
P_0c06c258: /* original 7e01, guest PC 0x0c06c258 */
if(!s->budget--) { s->failed_pc=0x0c06c258u; return 0; }
r[14]+=0x00000001u;
goto P_0c06c25a;
P_0c06c25a: /* original e320, guest PC 0x0c06c25a */
if(!s->budget--) { s->failed_pc=0x0c06c25au; return 0; }
r[3]=0x00000020u;
goto P_0c06c25c;
P_0c06c25c: /* original 65a3, guest PC 0x0c06c25c */
if(!s->budget--) { s->failed_pc=0x0c06c25cu; return 0; }
r[5]=r[10];
goto P_0c06c25e;
P_0c06c25e: /* original e610, guest PC 0x0c06c25e */
if(!s->budget--) { s->failed_pc=0x0c06c25eu; return 0; }
r[6]=0x00000010u;
goto P_0c06c260;
P_0c06c260: /* original 2f36, guest PC 0x0c06c260 */
if(!s->budget--) { s->failed_pc=0x0c06c260u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c262;
P_0c06c262: /* original d237, guest PC 0x0c06c262 */
if(!s->budget--) { s->failed_pc=0x0c06c262u; return 0; }
r[2]=read(ram,0x0c06c340u,4);
goto P_0c06c264;
P_0c06c264: /* original e703, guest PC 0x0c06c264 */
if(!s->budget--) { s->failed_pc=0x0c06c264u; return 0; }
r[7]=0x00000003u;
goto P_0c06c266;
P_0c06c266: /* original 420b, guest PC 0x0c06c266 */
if(!s->budget--) { s->failed_pc=0x0c06c266u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c26au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c26au) { target=s->pc; goto dispatch; }
goto P_0c06c26a;
P_0c06c268: /* original 64d3, guest PC 0x0c06c268 */
if(!s->budget--) { s->failed_pc=0x0c06c268u; return 0; }
r[4]=r[13];
goto P_0c06c26a;
P_0c06c26a: /* original e300, guest PC 0x0c06c26a */
if(!s->budget--) { s->failed_pc=0x0c06c26au; return 0; }
r[3]=0x00000000u;
goto P_0c06c26c;
P_0c06c26c: /* original 65c3, guest PC 0x0c06c26c */
if(!s->budget--) { s->failed_pc=0x0c06c26cu; return 0; }
r[5]=r[12];
goto P_0c06c26e;
P_0c06c26e: /* original 66d3, guest PC 0x0c06c26e */
if(!s->budget--) { s->failed_pc=0x0c06c26eu; return 0; }
r[6]=r[13];
goto P_0c06c270;
P_0c06c270: /* original 2f36, guest PC 0x0c06c270 */
if(!s->budget--) { s->failed_pc=0x0c06c270u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c272;
P_0c06c272: /* original d234, guest PC 0x0c06c272 */
if(!s->budget--) { s->failed_pc=0x0c06c272u; return 0; }
r[2]=read(ram,0x0c06c344u,4);
goto P_0c06c274;
P_0c06c274: /* original 6733, guest PC 0x0c06c274 */
if(!s->budget--) { s->failed_pc=0x0c06c274u; return 0; }
r[7]=r[3];
goto P_0c06c276;
P_0c06c276: /* original 420b, guest PC 0x0c06c276 */
if(!s->budget--) { s->failed_pc=0x0c06c276u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c27au;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c27au) { target=s->pc; goto dispatch; }
goto P_0c06c27a;
P_0c06c278: /* original 64a3, guest PC 0x0c06c278 */
if(!s->budget--) { s->failed_pc=0x0c06c278u; return 0; }
r[4]=r[10];
goto P_0c06c27a;
P_0c06c27a: /* original d333, guest PC 0x0c06c27a */
if(!s->budget--) { s->failed_pc=0x0c06c27au; return 0; }
r[3]=read(ram,0x0c06c348u,4);
goto P_0c06c27c;
P_0c06c27c: /* original e00a, guest PC 0x0c06c27c */
if(!s->budget--) { s->failed_pc=0x0c06c27cu; return 0; }
r[0]=0x0000000au;
goto P_0c06c27e;
P_0c06c27e: /* original 7f08, guest PC 0x0c06c27e */
if(!s->budget--) { s->failed_pc=0x0c06c27eu; return 0; }
r[15]+=0x00000008u;
goto P_0c06c280;
P_0c06c280: /* original 7e08, guest PC 0x0c06c280 */
if(!s->budget--) { s->failed_pc=0x0c06c280u; return 0; }
r[14]+=0x00000008u;
goto P_0c06c282;
P_0c06c282: /* original 430b, guest PC 0x0c06c282 */
if(!s->budget--) { s->failed_pc=0x0c06c282u; return 0; }
target=r[3];
r[16]=code_base|0x0c06c286u;
r[1]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c286u) { target=s->pc; goto dispatch; }
goto P_0c06c286;
P_0c06c284: /* original 61b3, guest PC 0x0c06c284 */
if(!s->budget--) { s->failed_pc=0x0c06c284u; return 0; }
r[1]=r[11];
goto P_0c06c286;
P_0c06c286: /* original 6403, guest PC 0x0c06c286 */
if(!s->budget--) { s->failed_pc=0x0c06c286u; return 0; }
r[4]=r[0];
goto P_0c06c288;
P_0c06c288: /* original 4408, guest PC 0x0c06c288 */
if(!s->budget--) { s->failed_pc=0x0c06c288u; return 0; }
r[4]<<=2;
goto P_0c06c28a;
P_0c06c28a: /* original 6303, guest PC 0x0c06c28a */
if(!s->budget--) { s->failed_pc=0x0c06c28au; return 0; }
r[3]=r[0];
goto P_0c06c28c;
P_0c06c28c: /* original 343c, guest PC 0x0c06c28c */
if(!s->budget--) { s->failed_pc=0x0c06c28cu; return 0; }
r[4]+=r[3];
goto P_0c06c28e;
P_0c06c28e: /* original 62b3, guest PC 0x0c06c28e */
if(!s->budget--) { s->failed_pc=0x0c06c28eu; return 0; }
r[2]=r[11];
goto P_0c06c290;
P_0c06c290: /* original 4400, guest PC 0x0c06c290 */
if(!s->budget--) { s->failed_pc=0x0c06c290u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c292;
P_0c06c292: /* original 63e3, guest PC 0x0c06c292 */
if(!s->budget--) { s->failed_pc=0x0c06c292u; return 0; }
r[3]=r[14];
goto P_0c06c294;
P_0c06c294: /* original 6603, guest PC 0x0c06c294 */
if(!s->budget--) { s->failed_pc=0x0c06c294u; return 0; }
r[6]=r[0];
goto P_0c06c296;
P_0c06c296: /* original 3248, guest PC 0x0c06c296 */
if(!s->budget--) { s->failed_pc=0x0c06c296u; return 0; }
r[2]-=r[4];
goto P_0c06c298;
P_0c06c298: /* original 2668, guest PC 0x0c06c298 */
if(!s->budget--) { s->failed_pc=0x0c06c298u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06c29a;
P_0c06c29a: /* original 1f21, guest PC 0x0c06c29a */
if(!s->budget--) { s->failed_pc=0x0c06c29au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06c29c;
P_0c06c29c: /* original da2b, guest PC 0x0c06c29c */
if(!s->budget--) { s->failed_pc=0x0c06c29cu; return 0; }
r[10]=read(ram,0x0c06c34cu,4);
goto P_0c06c29e;
P_0c06c29e: /* original 7302, guest PC 0x0c06c29e */
if(!s->budget--) { s->failed_pc=0x0c06c29eu; return 0; }
r[3]+=0x00000002u;
goto P_0c06c2a0;
P_0c06c2a0: /* original 9c47, guest PC 0x0c06c2a0 */
if(!s->budget--) { s->failed_pc=0x0c06c2a0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c332u,2);
goto P_0c06c2a2;
P_0c06c2a2: /* original 8d0d, guest PC 0x0c06c2a2 */
if(!s->budget--) { s->failed_pc=0x0c06c2a2u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c06c2c0; }
goto P_0c06c2a6;
P_0c06c2a4: /* original 2f32, guest PC 0x0c06c2a4 */
if(!s->budget--) { s->failed_pc=0x0c06c2a4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c2a6;
P_0c06c2a6: /* original 4e00, guest PC 0x0c06c2a6 */
if(!s->budget--) { s->failed_pc=0x0c06c2a6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c06c2a8;
P_0c06c2a8: /* original 67c3, guest PC 0x0c06c2a8 */
if(!s->budget--) { s->failed_pc=0x0c06c2a8u; return 0; }
r[7]=r[12];
goto P_0c06c2aa;
P_0c06c2aa: /* original 65e3, guest PC 0x0c06c2aa */
if(!s->budget--) { s->failed_pc=0x0c06c2aau; return 0; }
r[5]=r[14];
goto P_0c06c2ac;
P_0c06c2ac: /* original 259b, guest PC 0x0c06c2ac */
if(!s->budget--) { s->failed_pc=0x0c06c2acu; return 0; }
r[5]|=r[9];
goto P_0c06c2ae;
P_0c06c2ae: /* original 4a0b, guest PC 0x0c06c2ae */
if(!s->budget--) { s->failed_pc=0x0c06c2aeu; return 0; }
target=r[10];
r[16]=code_base|0x0c06c2b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c2b2u) { target=s->pc; goto dispatch; }
goto P_0c06c2b2;
P_0c06c2b0: /* original 64d3, guest PC 0x0c06c2b0 */
if(!s->budget--) { s->failed_pc=0x0c06c2b0u; return 0; }
r[4]=r[13];
goto P_0c06c2b2;
P_0c06c2b2: /* original 6ef2, guest PC 0x0c06c2b2 */
if(!s->budget--) { s->failed_pc=0x0c06c2b2u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c06c2b4;
P_0c06c2b4: /* original 67c3, guest PC 0x0c06c2b4 */
if(!s->budget--) { s->failed_pc=0x0c06c2b4u; return 0; }
r[7]=r[12];
goto P_0c06c2b6;
P_0c06c2b6: /* original 65e3, guest PC 0x0c06c2b6 */
if(!s->budget--) { s->failed_pc=0x0c06c2b6u; return 0; }
r[5]=r[14];
goto P_0c06c2b8;
P_0c06c2b8: /* original 4500, guest PC 0x0c06c2b8 */
if(!s->budget--) { s->failed_pc=0x0c06c2b8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06c2ba;
P_0c06c2ba: /* original 259b, guest PC 0x0c06c2ba */
if(!s->budget--) { s->failed_pc=0x0c06c2bau; return 0; }
r[5]|=r[9];
goto P_0c06c2bc;
P_0c06c2bc: /* original a006, guest PC 0x0c06c2bc */
if(!s->budget--) { s->failed_pc=0x0c06c2bcu; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c06c2cc;
P_0c06c2be: /* original 56f1, guest PC 0x0c06c2be */
if(!s->budget--) { s->failed_pc=0x0c06c2beu; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c06c2c0;
P_0c06c2c0: /* original 6533, guest PC 0x0c06c2c0 */
if(!s->budget--) { s->failed_pc=0x0c06c2c0u; return 0; }
r[5]=r[3];
goto P_0c06c2c2;
P_0c06c2c2: /* original 4500, guest PC 0x0c06c2c2 */
if(!s->budget--) { s->failed_pc=0x0c06c2c2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06c2c4;
P_0c06c2c4: /* original 67c3, guest PC 0x0c06c2c4 */
if(!s->budget--) { s->failed_pc=0x0c06c2c4u; return 0; }
r[7]=r[12];
goto P_0c06c2c6;
P_0c06c2c6: /* original 66b3, guest PC 0x0c06c2c6 */
if(!s->budget--) { s->failed_pc=0x0c06c2c6u; return 0; }
r[6]=r[11];
goto P_0c06c2c8;
P_0c06c2c8: /* original 6e33, guest PC 0x0c06c2c8 */
if(!s->budget--) { s->failed_pc=0x0c06c2c8u; return 0; }
r[14]=r[3];
goto P_0c06c2ca;
P_0c06c2ca: /* original 259b, guest PC 0x0c06c2ca */
if(!s->budget--) { s->failed_pc=0x0c06c2cau; return 0; }
r[5]|=r[9];
goto P_0c06c2cc;
P_0c06c2cc: /* original 4a0b, guest PC 0x0c06c2cc */
if(!s->budget--) { s->failed_pc=0x0c06c2ccu; return 0; }
target=r[10];
r[16]=code_base|0x0c06c2d0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c2d0u) { target=s->pc; goto dispatch; }
goto P_0c06c2d0;
P_0c06c2ce: /* original 64d3, guest PC 0x0c06c2ce */
if(!s->budget--) { s->failed_pc=0x0c06c2ceu; return 0; }
r[4]=r[13];
goto P_0c06c2d0;
P_0c06c2d0: /* original 902e, guest PC 0x0c06c2d0 */
if(!s->budget--) { s->failed_pc=0x0c06c2d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c330u,2);
goto P_0c06c2d2;
P_0c06c2d2: /* original 008c, guest PC 0x0c06c2d2 */
if(!s->budget--) { s->failed_pc=0x0c06c2d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c06c2d4;
P_0c06c2d4: /* original 8801, guest PC 0x0c06c2d4 */
if(!s->budget--) { s->failed_pc=0x0c06c2d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c2d6;
P_0c06c2d6: /* original 8d20, guest PC 0x0c06c2d6 */
if(!s->budget--) { s->failed_pc=0x0c06c2d6u; return 0; }
cond=r[17]&1u;
r[11]=r[0];
if(cond) { goto P_0c06c31a; }
goto P_0c06c2da;
P_0c06c2d8: /* original 6b03, guest PC 0x0c06c2d8 */
if(!s->budget--) { s->failed_pc=0x0c06c2d8u; return 0; }
r[11]=r[0];
goto P_0c06c2da;
P_0c06c2da: /* original 7e02, guest PC 0x0c06c2da */
if(!s->budget--) { s->failed_pc=0x0c06c2dau; return 0; }
r[14]+=0x00000002u;
goto P_0c06c2dc;
P_0c06c2dc: /* original d51c, guest PC 0x0c06c2dc */
if(!s->budget--) { s->failed_pc=0x0c06c2dcu; return 0; }
r[5]=read(ram,0x0c06c350u,4);
goto P_0c06c2de;
P_0c06c2de: /* original 64e3, guest PC 0x0c06c2de */
if(!s->budget--) { s->failed_pc=0x0c06c2deu; return 0; }
r[4]=r[14];
goto P_0c06c2e0;
P_0c06c2e0: /* original e300, guest PC 0x0c06c2e0 */
if(!s->budget--) { s->failed_pc=0x0c06c2e0u; return 0; }
r[3]=0x00000000u;
goto P_0c06c2e2;
P_0c06c2e2: /* original 4400, guest PC 0x0c06c2e2 */
if(!s->budget--) { s->failed_pc=0x0c06c2e2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c2e4;
P_0c06c2e4: /* original 6552, guest PC 0x0c06c2e4 */
if(!s->budget--) { s->failed_pc=0x0c06c2e4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c06c2e6;
P_0c06c2e6: /* original 6733, guest PC 0x0c06c2e6 */
if(!s->budget--) { s->failed_pc=0x0c06c2e6u; return 0; }
r[7]=r[3];
goto P_0c06c2e8;
P_0c06c2e8: /* original 249b, guest PC 0x0c06c2e8 */
if(!s->budget--) { s->failed_pc=0x0c06c2e8u; return 0; }
r[4]|=r[9];
goto P_0c06c2ea;
P_0c06c2ea: /* original 2f36, guest PC 0x0c06c2ea */
if(!s->budget--) { s->failed_pc=0x0c06c2eau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c2ec;
P_0c06c2ec: /* original d215, guest PC 0x0c06c2ec */
if(!s->budget--) { s->failed_pc=0x0c06c2ecu; return 0; }
r[2]=read(ram,0x0c06c344u,4);
goto P_0c06c2ee;
P_0c06c2ee: /* original 420b, guest PC 0x0c06c2ee */
if(!s->budget--) { s->failed_pc=0x0c06c2eeu; return 0; }
target=r[2];
r[16]=code_base|0x0c06c2f2u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c2f2u) { target=s->pc; goto dispatch; }
goto P_0c06c2f2;
P_0c06c2f0: /* original 66d3, guest PC 0x0c06c2f0 */
if(!s->budget--) { s->failed_pc=0x0c06c2f0u; return 0; }
r[6]=r[13];
goto P_0c06c2f2;
P_0c06c2f2: /* original 7e02, guest PC 0x0c06c2f2 */
if(!s->budget--) { s->failed_pc=0x0c06c2f2u; return 0; }
r[14]+=0x00000002u;
goto P_0c06c2f4;
P_0c06c2f4: /* original 67c3, guest PC 0x0c06c2f4 */
if(!s->budget--) { s->failed_pc=0x0c06c2f4u; return 0; }
r[7]=r[12];
goto P_0c06c2f6;
P_0c06c2f6: /* original 4e00, guest PC 0x0c06c2f6 */
if(!s->budget--) { s->failed_pc=0x0c06c2f6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c06c2f8;
P_0c06c2f8: /* original 66b3, guest PC 0x0c06c2f8 */
if(!s->budget--) { s->failed_pc=0x0c06c2f8u; return 0; }
r[6]=r[11];
goto P_0c06c2fa;
P_0c06c2fa: /* original 65e3, guest PC 0x0c06c2fa */
if(!s->budget--) { s->failed_pc=0x0c06c2fau; return 0; }
r[5]=r[14];
goto P_0c06c2fc;
P_0c06c2fc: /* original 7f04, guest PC 0x0c06c2fc */
if(!s->budget--) { s->failed_pc=0x0c06c2fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c2fe;
P_0c06c2fe: /* original 259b, guest PC 0x0c06c2fe */
if(!s->budget--) { s->failed_pc=0x0c06c2feu; return 0; }
r[5]|=r[9];
goto P_0c06c300;
P_0c06c300: /* original 4a0b, guest PC 0x0c06c300 */
if(!s->budget--) { s->failed_pc=0x0c06c300u; return 0; }
target=r[10];
r[16]=code_base|0x0c06c304u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c304u) { target=s->pc; goto dispatch; }
goto P_0c06c304;
P_0c06c302: /* original 64d3, guest PC 0x0c06c302 */
if(!s->budget--) { s->failed_pc=0x0c06c302u; return 0; }
r[4]=r[13];
goto P_0c06c304;
P_0c06c304: /* original a009, guest PC 0x0c06c304 */
if(!s->budget--) { s->failed_pc=0x0c06c304u; return 0; }
goto P_0c06c31a;
P_0c06c306: /* original 0009, guest PC 0x0c06c306 */
if(!s->budget--) { s->failed_pc=0x0c06c306u; return 0; }
goto P_0c06c308;
P_0c06c308: /* original d412, guest PC 0x0c06c308 */
if(!s->budget--) { s->failed_pc=0x0c06c308u; return 0; }
r[4]=read(ram,0x0c06c354u,4);
goto P_0c06c30a;
P_0c06c30a: /* original 2778, guest PC 0x0c06c30a */
if(!s->budget--) { s->failed_pc=0x0c06c30au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06c30c;
P_0c06c30c: /* original d312, guest PC 0x0c06c30c */
if(!s->budget--) { s->failed_pc=0x0c06c30cu; return 0; }
r[3]=read(ram,0x0c06c358u,4);
goto P_0c06c30e;
P_0c06c30e: /* original 6242, guest PC 0x0c06c30e */
if(!s->budget--) { s->failed_pc=0x0c06c30eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c06c310;
P_0c06c310: /* original 2238, guest PC 0x0c06c310 */
if(!s->budget--) { s->failed_pc=0x0c06c310u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06c312;
P_0c06c312: /* original 8902, guest PC 0x0c06c312 */
if(!s->budget--) { s->failed_pc=0x0c06c312u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c31a; }
goto P_0c06c314;
P_0c06c314: /* original 5141, guest PC 0x0c06c314 */
if(!s->budget--) { s->failed_pc=0x0c06c314u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c06c316;
P_0c06c316: /* original d211, guest PC 0x0c06c316 */
if(!s->budget--) { s->failed_pc=0x0c06c316u; return 0; }
r[2]=read(ram,0x0c06c35cu,4);
goto P_0c06c318;
P_0c06c318: /* original 2128, guest PC 0x0c06c318 */
if(!s->budget--) { s->failed_pc=0x0c06c318u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c06c31a;
P_0c06c31a: /* original 7f08, guest PC 0x0c06c31a */
if(!s->budget--) { s->failed_pc=0x0c06c31au; return 0; }
r[15]+=0x00000008u;
goto P_0c06c31c;
P_0c06c31c: /* original 4f26, guest PC 0x0c06c31c */
if(!s->budget--) { s->failed_pc=0x0c06c31cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c31e;
P_0c06c31e: /* original 68f6, guest PC 0x0c06c31e */
if(!s->budget--) { s->failed_pc=0x0c06c31eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06c320;
P_0c06c320: /* original 69f6, guest PC 0x0c06c320 */
if(!s->budget--) { s->failed_pc=0x0c06c320u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06c322;
P_0c06c322: /* original 6af6, guest PC 0x0c06c322 */
if(!s->budget--) { s->failed_pc=0x0c06c322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06c324;
P_0c06c324: /* original 6bf6, guest PC 0x0c06c324 */
if(!s->budget--) { s->failed_pc=0x0c06c324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c326;
P_0c06c326: /* original 6cf6, guest PC 0x0c06c326 */
if(!s->budget--) { s->failed_pc=0x0c06c326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c328;
P_0c06c328: /* original 6df6, guest PC 0x0c06c328 */
if(!s->budget--) { s->failed_pc=0x0c06c328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c32a;
P_0c06c32a: /* original 000b, guest PC 0x0c06c32a */
if(!s->budget--) { s->failed_pc=0x0c06c32au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c32c: /* original 6ef6, guest PC 0x0c06c32c */
if(!s->budget--) { s->failed_pc=0x0c06c32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06c32eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c32eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
