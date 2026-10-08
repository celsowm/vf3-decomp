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
int vf3_percentage_family_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07abf8u: goto P_0c07abf8;
case 0x0c07abfau: goto P_0c07abfa;
case 0x0c07abfcu: goto P_0c07abfc;
case 0x0c07abfeu: goto P_0c07abfe;
case 0x0c07ac00u: goto P_0c07ac00;
case 0x0c07ac02u: goto P_0c07ac02;
case 0x0c07ac04u: goto P_0c07ac04;
case 0x0c07ac06u: goto P_0c07ac06;
case 0x0c07ac08u: goto P_0c07ac08;
case 0x0c07ac0au: goto P_0c07ac0a;
case 0x0c07ac0cu: goto P_0c07ac0c;
case 0x0c07ac0eu: goto P_0c07ac0e;
case 0x0c07ac10u: goto P_0c07ac10;
case 0x0c07ac12u: goto P_0c07ac12;
case 0x0c07ac14u: goto P_0c07ac14;
case 0x0c07ac16u: goto P_0c07ac16;
case 0x0c07ac18u: goto P_0c07ac18;
case 0x0c07ac1au: goto P_0c07ac1a;
case 0x0c07ac1cu: goto P_0c07ac1c;
case 0x0c07ac1eu: goto P_0c07ac1e;
case 0x0c07ac20u: goto P_0c07ac20;
case 0x0c07ac22u: goto P_0c07ac22;
case 0x0c07ac24u: goto P_0c07ac24;
case 0x0c07ac26u: goto P_0c07ac26;
case 0x0c09befcu: goto P_0c09befc;
case 0x0c09befeu: goto P_0c09befe;
case 0x0c09bf00u: goto P_0c09bf00;
case 0x0c09bf02u: goto P_0c09bf02;
case 0x0c09bf04u: goto P_0c09bf04;
case 0x0c09bf06u: goto P_0c09bf06;
case 0x0c09bf08u: goto P_0c09bf08;
case 0x0c09bf0au: goto P_0c09bf0a;
case 0x0c09bf0cu: goto P_0c09bf0c;
case 0x0c09bf0eu: goto P_0c09bf0e;
case 0x0c09bf10u: goto P_0c09bf10;
case 0x0c09bf12u: goto P_0c09bf12;
case 0x0c09bf14u: goto P_0c09bf14;
case 0x0c09bf16u: goto P_0c09bf16;
case 0x0c09bf18u: goto P_0c09bf18;
case 0x0c09bf1au: goto P_0c09bf1a;
case 0x0c09bf1cu: goto P_0c09bf1c;
case 0x0c09bf1eu: goto P_0c09bf1e;
case 0x0c09bf20u: goto P_0c09bf20;
case 0x0c09bf22u: goto P_0c09bf22;
case 0x0c09bf24u: goto P_0c09bf24;
case 0x0c09bf26u: goto P_0c09bf26;
case 0x0c09bf28u: goto P_0c09bf28;
case 0x0c09bf2au: goto P_0c09bf2a;
case 0x0c09bf2cu: goto P_0c09bf2c;
case 0x0c09bf2eu: goto P_0c09bf2e;
case 0x0c09bf30u: goto P_0c09bf30;
case 0x0c09bf32u: goto P_0c09bf32;
case 0x0c09bf34u: goto P_0c09bf34;
case 0x0c09bf36u: goto P_0c09bf36;
case 0x0c09bf38u: goto P_0c09bf38;
case 0x0c09bf3au: goto P_0c09bf3a;
case 0x0c09bf3cu: goto P_0c09bf3c;
case 0x0c09bf3eu: goto P_0c09bf3e;
case 0x0c09bf40u: goto P_0c09bf40;
case 0x0c09bf42u: goto P_0c09bf42;
case 0x0c09bf44u: goto P_0c09bf44;
case 0x0c09bf46u: goto P_0c09bf46;
case 0x0c09bf48u: goto P_0c09bf48;
case 0x0c09bf4au: goto P_0c09bf4a;
case 0x0c09bf4cu: goto P_0c09bf4c;
case 0x0c09bf4eu: goto P_0c09bf4e;
case 0x0c09bf50u: goto P_0c09bf50;
case 0x0c09bf52u: goto P_0c09bf52;
case 0x0c09bf54u: goto P_0c09bf54;
case 0x0c09bf56u: goto P_0c09bf56;
case 0x0c09bf58u: goto P_0c09bf58;
case 0x0c09bf5au: goto P_0c09bf5a;
case 0x0c09bf5cu: goto P_0c09bf5c;
case 0x0c09bf5eu: goto P_0c09bf5e;
case 0x0c09bf60u: goto P_0c09bf60;
case 0x0c09bf62u: goto P_0c09bf62;
case 0x0c09bf64u: goto P_0c09bf64;
case 0x0c09bf66u: goto P_0c09bf66;
case 0x0c09bf68u: goto P_0c09bf68;
case 0x0c09bf6au: goto P_0c09bf6a;
case 0x0c09bf6cu: goto P_0c09bf6c;
case 0x0c09bf6eu: goto P_0c09bf6e;
case 0x0c09bf70u: goto P_0c09bf70;
case 0x0c09bf72u: goto P_0c09bf72;
case 0x0c09bf74u: goto P_0c09bf74;
case 0x0c09bf76u: goto P_0c09bf76;
case 0x0c09bf78u: goto P_0c09bf78;
case 0x0c09bf7au: goto P_0c09bf7a;
case 0x0c09bf7cu: goto P_0c09bf7c;
case 0x0c09bf7eu: goto P_0c09bf7e;
case 0x0c09bf80u: goto P_0c09bf80;
case 0x0c09bf82u: goto P_0c09bf82;
case 0x0c09bf84u: goto P_0c09bf84;
case 0x0c09bf86u: goto P_0c09bf86;
case 0x0c09bf88u: goto P_0c09bf88;
case 0x0c09bf8au: goto P_0c09bf8a;
case 0x0c09bf8cu: goto P_0c09bf8c;
case 0x0c09bf8eu: goto P_0c09bf8e;
case 0x0c09bf90u: goto P_0c09bf90;
case 0x0c09bf92u: goto P_0c09bf92;
case 0x0c09c044u: goto P_0c09c044;
case 0x0c09c046u: goto P_0c09c046;
case 0x0c09c048u: goto P_0c09c048;
case 0x0c09c04au: goto P_0c09c04a;
case 0x0c09c04cu: goto P_0c09c04c;
case 0x0c09c04eu: goto P_0c09c04e;
case 0x0c09c050u: goto P_0c09c050;
case 0x0c09c052u: goto P_0c09c052;
case 0x0c09c054u: goto P_0c09c054;
case 0x0c09c056u: goto P_0c09c056;
case 0x0c09c058u: goto P_0c09c058;
case 0x0c09c05au: goto P_0c09c05a;
case 0x0c09c05cu: goto P_0c09c05c;
case 0x0c09c05eu: goto P_0c09c05e;
case 0x0c09c060u: goto P_0c09c060;
case 0x0c09c062u: goto P_0c09c062;
case 0x0c09c064u: goto P_0c09c064;
case 0x0c09c066u: goto P_0c09c066;
case 0x0c09c068u: goto P_0c09c068;
case 0x0c09c06au: goto P_0c09c06a;
case 0x0c09c06cu: goto P_0c09c06c;
case 0x0c09c06eu: goto P_0c09c06e;
case 0x0c09c070u: goto P_0c09c070;
case 0x0c09c072u: goto P_0c09c072;
case 0x0c09c074u: goto P_0c09c074;
case 0x0c09c076u: goto P_0c09c076;
case 0x0c09c078u: goto P_0c09c078;
case 0x0c09c07au: goto P_0c09c07a;
case 0x0c09c07cu: goto P_0c09c07c;
case 0x0c09c07eu: goto P_0c09c07e;
case 0x0c09c080u: goto P_0c09c080;
case 0x0c09c082u: goto P_0c09c082;
case 0x0c09c084u: goto P_0c09c084;
case 0x0c09c086u: goto P_0c09c086;
case 0x0c09c088u: goto P_0c09c088;
case 0x0c09c08au: goto P_0c09c08a;
case 0x0c09c08cu: goto P_0c09c08c;
case 0x0c09c08eu: goto P_0c09c08e;
case 0x0c09c090u: goto P_0c09c090;
case 0x0c09c092u: goto P_0c09c092;
case 0x0c09c094u: goto P_0c09c094;
case 0x0c09c096u: goto P_0c09c096;
case 0x0c09c098u: goto P_0c09c098;
case 0x0c09c09au: goto P_0c09c09a;
case 0x0c09c09cu: goto P_0c09c09c;
case 0x0c09c09eu: goto P_0c09c09e;
case 0x0c09c0a0u: goto P_0c09c0a0;
case 0x0c09c0a2u: goto P_0c09c0a2;
case 0x0c09c0a4u: goto P_0c09c0a4;
case 0x0c09c0a6u: goto P_0c09c0a6;
case 0x0c09c0a8u: goto P_0c09c0a8;
case 0x0c09c0aau: goto P_0c09c0aa;
case 0x0c09c0acu: goto P_0c09c0ac;
case 0x0c09c0aeu: goto P_0c09c0ae;
case 0x0c09c0b0u: goto P_0c09c0b0;
case 0x0c09c0b2u: goto P_0c09c0b2;
case 0x0c09c0b4u: goto P_0c09c0b4;
case 0x0c09c0e4u: goto P_0c09c0e4;
case 0x0c09c0e6u: goto P_0c09c0e6;
case 0x0c09c0e8u: goto P_0c09c0e8;
case 0x0c09c0eau: goto P_0c09c0ea;
case 0x0c09c0ecu: goto P_0c09c0ec;
case 0x0c09c0eeu: goto P_0c09c0ee;
case 0x0c09c0f0u: goto P_0c09c0f0;
case 0x0c09c0f2u: goto P_0c09c0f2;
case 0x0c09c0f4u: goto P_0c09c0f4;
case 0x0c09c0f6u: goto P_0c09c0f6;
case 0x0c09c0f8u: goto P_0c09c0f8;
case 0x0c09c0fau: goto P_0c09c0fa;
case 0x0c09c0fcu: goto P_0c09c0fc;
case 0x0c09c0feu: goto P_0c09c0fe;
case 0x0c09c100u: goto P_0c09c100;
case 0x0c09c102u: goto P_0c09c102;
case 0x0c09c104u: goto P_0c09c104;
case 0x0c09c106u: goto P_0c09c106;
case 0x0c09c108u: goto P_0c09c108;
case 0x0c09c10au: goto P_0c09c10a;
case 0x0c09c10cu: goto P_0c09c10c;
case 0x0c09c10eu: goto P_0c09c10e;
case 0x0c09c110u: goto P_0c09c110;
case 0x0c09c112u: goto P_0c09c112;
case 0x0c09c114u: goto P_0c09c114;
case 0x0c09c116u: goto P_0c09c116;
case 0x0c09c118u: goto P_0c09c118;
case 0x0c09c11au: goto P_0c09c11a;
case 0x0c09c11cu: goto P_0c09c11c;
case 0x0c09c11eu: goto P_0c09c11e;
case 0x0c09c120u: goto P_0c09c120;
case 0x0c09c122u: goto P_0c09c122;
case 0x0c09c124u: goto P_0c09c124;
case 0x0c09c126u: goto P_0c09c126;
case 0x0c09c128u: goto P_0c09c128;
case 0x0c09c12au: goto P_0c09c12a;
case 0x0c09c12cu: goto P_0c09c12c;
case 0x0c09c12eu: goto P_0c09c12e;
case 0x0c09c130u: goto P_0c09c130;
case 0x0c09c132u: goto P_0c09c132;
case 0x0c09c134u: goto P_0c09c134;
case 0x0c09c136u: goto P_0c09c136;
case 0x0c09c138u: goto P_0c09c138;
case 0x0c09c13au: goto P_0c09c13a;
case 0x0c09c13cu: goto P_0c09c13c;
case 0x0c09c13eu: goto P_0c09c13e;
case 0x0c09c140u: goto P_0c09c140;
case 0x0c09c142u: goto P_0c09c142;
case 0x0c09c144u: goto P_0c09c144;
case 0x0c09c146u: goto P_0c09c146;
case 0x0c09c148u: goto P_0c09c148;
case 0x0c09c14au: goto P_0c09c14a;
case 0x0c09c14cu: goto P_0c09c14c;
case 0x0c09c14eu: goto P_0c09c14e;
case 0x0c09c150u: goto P_0c09c150;
case 0x0c09c152u: goto P_0c09c152;
case 0x0c09c154u: goto P_0c09c154;
case 0x0c09c156u: goto P_0c09c156;
case 0x0c09c158u: goto P_0c09c158;
case 0x0c09c15au: goto P_0c09c15a;
case 0x0c09c15cu: goto P_0c09c15c;
case 0x0c09c15eu: goto P_0c09c15e;
case 0x0c09c160u: goto P_0c09c160;
case 0x0c09c162u: goto P_0c09c162;
case 0x0c09c164u: goto P_0c09c164;
case 0x0c09c166u: goto P_0c09c166;
case 0x0c09c168u: goto P_0c09c168;
case 0x0c09c16au: goto P_0c09c16a;
case 0x0c09c16cu: goto P_0c09c16c;
case 0x0c09c16eu: goto P_0c09c16e;
case 0x0c09c170u: goto P_0c09c170;
case 0x0c09c172u: goto P_0c09c172;
case 0x0c09c174u: goto P_0c09c174;
case 0x0c09c176u: goto P_0c09c176;
case 0x0c09c178u: goto P_0c09c178;
case 0x0c09c17au: goto P_0c09c17a;
case 0x0c09c17cu: goto P_0c09c17c;
case 0x0c09c17eu: goto P_0c09c17e;
case 0x0c09c180u: goto P_0c09c180;
case 0x0c09c182u: goto P_0c09c182;
case 0x0c09c184u: goto P_0c09c184;
case 0x0c09c186u: goto P_0c09c186;
case 0x0c09c188u: goto P_0c09c188;
case 0x0c09c18au: goto P_0c09c18a;
case 0x0c09c18cu: goto P_0c09c18c;
case 0x0c09c18eu: goto P_0c09c18e;
case 0x0c09c190u: goto P_0c09c190;
case 0x0c09c192u: goto P_0c09c192;
case 0x0c09c194u: goto P_0c09c194;
case 0x0c09c196u: goto P_0c09c196;
case 0x0c09c198u: goto P_0c09c198;
case 0x0c09c19au: goto P_0c09c19a;
case 0x0c09c19cu: goto P_0c09c19c;
case 0x0c09c19eu: goto P_0c09c19e;
case 0x0c09c1a0u: goto P_0c09c1a0;
case 0x0c09c1a2u: goto P_0c09c1a2;
case 0x0c09c1a4u: goto P_0c09c1a4;
case 0x0c09c1a6u: goto P_0c09c1a6;
case 0x0c09c1a8u: goto P_0c09c1a8;
case 0x0c09c1aau: goto P_0c09c1aa;
case 0x0c09c1acu: goto P_0c09c1ac;
case 0x0c09c1aeu: goto P_0c09c1ae;
case 0x0c09c1b0u: goto P_0c09c1b0;
case 0x0c09c1b2u: goto P_0c09c1b2;
case 0x0c09c1b4u: goto P_0c09c1b4;
case 0x0c09c1b6u: goto P_0c09c1b6;
case 0x0c09c1b8u: goto P_0c09c1b8;
case 0x0c09c1bau: goto P_0c09c1ba;
case 0x0c09c1bcu: goto P_0c09c1bc;
case 0x0c09c1beu: goto P_0c09c1be;
case 0x0c09c1c0u: goto P_0c09c1c0;
case 0x0c09c1c2u: goto P_0c09c1c2;
case 0x0c09c1c4u: goto P_0c09c1c4;
case 0x0c09c1c6u: goto P_0c09c1c6;
case 0x0c09c1c8u: goto P_0c09c1c8;
case 0x0c09c1cau: goto P_0c09c1ca;
case 0x0c09c1ccu: goto P_0c09c1cc;
case 0x0c09c1ceu: goto P_0c09c1ce;
case 0x0c09c1d0u: goto P_0c09c1d0;
case 0x0c09c1d2u: goto P_0c09c1d2;
case 0x0c09c1d4u: goto P_0c09c1d4;
case 0x0c09c1d6u: goto P_0c09c1d6;
case 0x0c09c1d8u: goto P_0c09c1d8;
case 0x0c09c1dau: goto P_0c09c1da;
case 0x0c09c1dcu: goto P_0c09c1dc;
case 0x0c09c1deu: goto P_0c09c1de;
case 0x0c09c1e0u: goto P_0c09c1e0;
case 0x0c09c1e2u: goto P_0c09c1e2;
case 0x0c09c1e4u: goto P_0c09c1e4;
case 0x0c09c1e6u: goto P_0c09c1e6;
case 0x0c09c1e8u: goto P_0c09c1e8;
case 0x0c09c1eau: goto P_0c09c1ea;
case 0x0c09c1ecu: goto P_0c09c1ec;
case 0x0c09c1eeu: goto P_0c09c1ee;
case 0x0c09c1f0u: goto P_0c09c1f0;
case 0x0c09c1f2u: goto P_0c09c1f2;
case 0x0c09c1f4u: goto P_0c09c1f4;
case 0x0c09c1f6u: goto P_0c09c1f6;
case 0x0c09c1f8u: goto P_0c09c1f8;
case 0x0c09c1fau: goto P_0c09c1fa;
case 0x0c09c1fcu: goto P_0c09c1fc;
case 0x0c09c1feu: goto P_0c09c1fe;
case 0x0c09c200u: goto P_0c09c200;
case 0x0c09c202u: goto P_0c09c202;
case 0x0c09c204u: goto P_0c09c204;
case 0x0c09c206u: goto P_0c09c206;
case 0x0c09c208u: goto P_0c09c208;
case 0x0c09c20au: goto P_0c09c20a;
case 0x0c09c224u: goto P_0c09c224;
case 0x0c09c226u: goto P_0c09c226;
case 0x0c09c228u: goto P_0c09c228;
case 0x0c09c22au: goto P_0c09c22a;
case 0x0c09c22cu: goto P_0c09c22c;
case 0x0c09c22eu: goto P_0c09c22e;
case 0x0c09c230u: goto P_0c09c230;
case 0x0c09c232u: goto P_0c09c232;
case 0x0c09c234u: goto P_0c09c234;
case 0x0c09c236u: goto P_0c09c236;
case 0x0c09c238u: goto P_0c09c238;
case 0x0c09c23au: goto P_0c09c23a;
case 0x0c09c23cu: goto P_0c09c23c;
case 0x0c09c23eu: goto P_0c09c23e;
case 0x0c09c240u: goto P_0c09c240;
case 0x0c09c242u: goto P_0c09c242;
case 0x0c09c244u: goto P_0c09c244;
case 0x0c09c246u: goto P_0c09c246;
case 0x0c09c248u: goto P_0c09c248;
case 0x0c09c24au: goto P_0c09c24a;
case 0x0c09c24cu: goto P_0c09c24c;
case 0x0c09c24eu: goto P_0c09c24e;
case 0x0c09c250u: goto P_0c09c250;
case 0x0c09c252u: goto P_0c09c252;
case 0x0c09c254u: goto P_0c09c254;
case 0x0c09c256u: goto P_0c09c256;
case 0x0c09c258u: goto P_0c09c258;
case 0x0c09c25au: goto P_0c09c25a;
case 0x0c09c25cu: goto P_0c09c25c;
case 0x0c09c25eu: goto P_0c09c25e;
case 0x0c09c260u: goto P_0c09c260;
case 0x0c09c262u: goto P_0c09c262;
case 0x0c09c264u: goto P_0c09c264;
case 0x0c09c266u: goto P_0c09c266;
case 0x0c09c268u: goto P_0c09c268;
case 0x0c09c26au: goto P_0c09c26a;
case 0x0c09c26cu: goto P_0c09c26c;
case 0x0c09c26eu: goto P_0c09c26e;
case 0x0c09c270u: goto P_0c09c270;
case 0x0c09c272u: goto P_0c09c272;
case 0x0c09c274u: goto P_0c09c274;
case 0x0c09c276u: goto P_0c09c276;
case 0x0c09c278u: goto P_0c09c278;
case 0x0c09c27au: goto P_0c09c27a;
case 0x0c09c27cu: goto P_0c09c27c;
case 0x0c09c27eu: goto P_0c09c27e;
case 0x0c09c280u: goto P_0c09c280;
case 0x0c09c282u: goto P_0c09c282;
case 0x0c09c284u: goto P_0c09c284;
case 0x0c09c286u: goto P_0c09c286;
case 0x0c09c288u: goto P_0c09c288;
case 0x0c09c28au: goto P_0c09c28a;
case 0x0c09c28cu: goto P_0c09c28c;
case 0x0c09c28eu: goto P_0c09c28e;
case 0x0c09c290u: goto P_0c09c290;
case 0x0c09c292u: goto P_0c09c292;
case 0x0c09c294u: goto P_0c09c294;
case 0x0c09c296u: goto P_0c09c296;
case 0x0c09c298u: goto P_0c09c298;
case 0x0c09c29au: goto P_0c09c29a;
case 0x0c09c29cu: goto P_0c09c29c;
case 0x0c09c29eu: goto P_0c09c29e;
case 0x0c09c2a0u: goto P_0c09c2a0;
case 0x0c09c2a2u: goto P_0c09c2a2;
case 0x0c09c2a4u: goto P_0c09c2a4;
case 0x0c09c2a6u: goto P_0c09c2a6;
case 0x0c09c2a8u: goto P_0c09c2a8;
case 0x0c09c2aau: goto P_0c09c2aa;
case 0x0c09c2acu: goto P_0c09c2ac;
case 0x0c09c2aeu: goto P_0c09c2ae;
case 0x0c09c2b0u: goto P_0c09c2b0;
case 0x0c09c2b2u: goto P_0c09c2b2;
case 0x0c09c2b4u: goto P_0c09c2b4;
case 0x0c09c2b6u: goto P_0c09c2b6;
case 0x0c09c2b8u: goto P_0c09c2b8;
case 0x0c09c2bau: goto P_0c09c2ba;
case 0x0c09c2bcu: goto P_0c09c2bc;
case 0x0c09c2beu: goto P_0c09c2be;
case 0x0c09c2c0u: goto P_0c09c2c0;
case 0x0c09c2c2u: goto P_0c09c2c2;
case 0x0c09c2c4u: goto P_0c09c2c4;
case 0x0c09c2c6u: goto P_0c09c2c6;
case 0x0c09c2c8u: goto P_0c09c2c8;
case 0x0c09c2cau: goto P_0c09c2ca;
case 0x0c09c2ccu: goto P_0c09c2cc;
case 0x0c09c2ceu: goto P_0c09c2ce;
case 0x0c09c2d0u: goto P_0c09c2d0;
case 0x0c09c2d2u: goto P_0c09c2d2;
case 0x0c09c2d4u: goto P_0c09c2d4;
case 0x0c09c2d6u: goto P_0c09c2d6;
case 0x0c09c2d8u: goto P_0c09c2d8;
case 0x0c09c2dau: goto P_0c09c2da;
case 0x0c09c2dcu: goto P_0c09c2dc;
case 0x0c09c2deu: goto P_0c09c2de;
case 0x0c09c2e0u: goto P_0c09c2e0;
case 0x0c09c2e2u: goto P_0c09c2e2;
case 0x0c09c2e4u: goto P_0c09c2e4;
case 0x0c09c2e6u: goto P_0c09c2e6;
case 0x0c09c2e8u: goto P_0c09c2e8;
case 0x0c09c304u: goto P_0c09c304;
case 0x0c09c306u: goto P_0c09c306;
case 0x0c09c308u: goto P_0c09c308;
case 0x0c09c30au: goto P_0c09c30a;
case 0x0c09c30cu: goto P_0c09c30c;
case 0x0c09c30eu: goto P_0c09c30e;
case 0x0c09c310u: goto P_0c09c310;
case 0x0c09c312u: goto P_0c09c312;
case 0x0c09c314u: goto P_0c09c314;
case 0x0c09c316u: goto P_0c09c316;
case 0x0c09c318u: goto P_0c09c318;
case 0x0c09c31au: goto P_0c09c31a;
case 0x0c09c31cu: goto P_0c09c31c;
case 0x0c09c31eu: goto P_0c09c31e;
case 0x0c09c320u: goto P_0c09c320;
case 0x0c09c322u: goto P_0c09c322;
case 0x0c09c324u: goto P_0c09c324;
case 0x0c09c326u: goto P_0c09c326;
case 0x0c09c328u: goto P_0c09c328;
case 0x0c09c32au: goto P_0c09c32a;
case 0x0c09c32cu: goto P_0c09c32c;
case 0x0c09c32eu: goto P_0c09c32e;
case 0x0c09c330u: goto P_0c09c330;
case 0x0c09c332u: goto P_0c09c332;
case 0x0c09c334u: goto P_0c09c334;
case 0x0c09c336u: goto P_0c09c336;
case 0x0c09c338u: goto P_0c09c338;
case 0x0c09c33au: goto P_0c09c33a;
case 0x0c09c33cu: goto P_0c09c33c;
case 0x0c09c33eu: goto P_0c09c33e;
case 0x0c09c340u: goto P_0c09c340;
case 0x0c09c342u: goto P_0c09c342;
case 0x0c09c344u: goto P_0c09c344;
case 0x0c09c346u: goto P_0c09c346;
case 0x0c09c348u: goto P_0c09c348;
case 0x0c09c34au: goto P_0c09c34a;
case 0x0c09c34cu: goto P_0c09c34c;
case 0x0c09c34eu: goto P_0c09c34e;
case 0x0c09c350u: goto P_0c09c350;
case 0x0c09c352u: goto P_0c09c352;
case 0x0c09c354u: goto P_0c09c354;
case 0x0c09c356u: goto P_0c09c356;
case 0x0c09c358u: goto P_0c09c358;
case 0x0c09c35au: goto P_0c09c35a;
case 0x0c09c35cu: goto P_0c09c35c;
case 0x0c09c35eu: goto P_0c09c35e;
case 0x0c09c360u: goto P_0c09c360;
case 0x0c09c362u: goto P_0c09c362;
case 0x0c09c364u: goto P_0c09c364;
case 0x0c09c366u: goto P_0c09c366;
case 0x0c09c368u: goto P_0c09c368;
case 0x0c09c36au: goto P_0c09c36a;
case 0x0c09c36cu: goto P_0c09c36c;
case 0x0c09c36eu: goto P_0c09c36e;
case 0x0c09c370u: goto P_0c09c370;
case 0x0c09c372u: goto P_0c09c372;
case 0x0c09c374u: goto P_0c09c374;
case 0x0c09c376u: goto P_0c09c376;
case 0x0c09c378u: goto P_0c09c378;
case 0x0c09c37au: goto P_0c09c37a;
case 0x0c09c37cu: goto P_0c09c37c;
case 0x0c09c37eu: goto P_0c09c37e;
case 0x0c09c380u: goto P_0c09c380;
case 0x0c09c382u: goto P_0c09c382;
case 0x0c09c384u: goto P_0c09c384;
case 0x0c09c386u: goto P_0c09c386;
case 0x0c09c388u: goto P_0c09c388;
case 0x0c09c38au: goto P_0c09c38a;
case 0x0c09c38cu: goto P_0c09c38c;
case 0x0c09c38eu: goto P_0c09c38e;
case 0x0c09c390u: goto P_0c09c390;
case 0x0c09c392u: goto P_0c09c392;
case 0x0c09c394u: goto P_0c09c394;
case 0x0c09c396u: goto P_0c09c396;
case 0x0c09c398u: goto P_0c09c398;
case 0x0c09c39au: goto P_0c09c39a;
case 0x0c09c39cu: goto P_0c09c39c;
case 0x0c09c39eu: goto P_0c09c39e;
case 0x0c09c3a0u: goto P_0c09c3a0;
case 0x0c09c3a2u: goto P_0c09c3a2;
case 0x0c09c3a4u: goto P_0c09c3a4;
case 0x0c09c3a6u: goto P_0c09c3a6;
case 0x0c09c3a8u: goto P_0c09c3a8;
case 0x0c09c3aau: goto P_0c09c3aa;
case 0x0c09c3acu: goto P_0c09c3ac;
case 0x0c09c3aeu: goto P_0c09c3ae;
case 0x0c09c3b0u: goto P_0c09c3b0;
case 0x0c09c3b2u: goto P_0c09c3b2;
case 0x0c09c3b4u: goto P_0c09c3b4;
case 0x0c09c3b6u: goto P_0c09c3b6;
case 0x0c09c3b8u: goto P_0c09c3b8;
case 0x0c09c3bau: goto P_0c09c3ba;
case 0x0c09c3bcu: goto P_0c09c3bc;
case 0x0c09c3beu: goto P_0c09c3be;
case 0x0c09c3c0u: goto P_0c09c3c0;
case 0x0c09c3c2u: goto P_0c09c3c2;
case 0x0c09c3c4u: goto P_0c09c3c4;
case 0x0c09c3c6u: goto P_0c09c3c6;
case 0x0c09c3c8u: goto P_0c09c3c8;
case 0x0c09c3cau: goto P_0c09c3ca;
case 0x0c09c3ccu: goto P_0c09c3cc;
case 0x0c09c3ceu: goto P_0c09c3ce;
case 0x0c09c3d0u: goto P_0c09c3d0;
case 0x0c09c3d2u: goto P_0c09c3d2;
case 0x0c09c3d4u: goto P_0c09c3d4;
case 0x0c09c3d6u: goto P_0c09c3d6;
case 0x0c09c3d8u: goto P_0c09c3d8;
case 0x0c09c3dau: goto P_0c09c3da;
case 0x0c09c3dcu: goto P_0c09c3dc;
case 0x0c09c3deu: goto P_0c09c3de;
case 0x0c09c3e0u: goto P_0c09c3e0;
case 0x0c09c3e2u: goto P_0c09c3e2;
case 0x0c09c3e4u: goto P_0c09c3e4;
case 0x0c09c3e6u: goto P_0c09c3e6;
case 0x0c09c3e8u: goto P_0c09c3e8;
case 0x0c09c3eau: goto P_0c09c3ea;
case 0x0c09c3ecu: goto P_0c09c3ec;
case 0x0c09c3eeu: goto P_0c09c3ee;
case 0x0c09c3f0u: goto P_0c09c3f0;
case 0x0c09c3f2u: goto P_0c09c3f2;
case 0x0c09c3f4u: goto P_0c09c3f4;
case 0x0c09c3f6u: goto P_0c09c3f6;
case 0x0c09c3f8u: goto P_0c09c3f8;
case 0x0c09c3fau: goto P_0c09c3fa;
case 0x0c09c3fcu: goto P_0c09c3fc;
case 0x0c09c3feu: goto P_0c09c3fe;
case 0x0c09c400u: goto P_0c09c400;
case 0x0c09c402u: goto P_0c09c402;
case 0x0c09c404u: goto P_0c09c404;
case 0x0c09c406u: goto P_0c09c406;
case 0x0c09c408u: goto P_0c09c408;
case 0x0c09c40au: goto P_0c09c40a;
case 0x0c09c40cu: goto P_0c09c40c;
case 0x0c09c40eu: goto P_0c09c40e;
case 0x0c09c410u: goto P_0c09c410;
case 0x0c09c412u: goto P_0c09c412;
case 0x0c09c414u: goto P_0c09c414;
case 0x0c09c416u: goto P_0c09c416;
case 0x0c09c418u: goto P_0c09c418;
case 0x0c09c41au: goto P_0c09c41a;
case 0x0c09c41cu: goto P_0c09c41c;
case 0x0c09c41eu: goto P_0c09c41e;
case 0x0c09c420u: goto P_0c09c420;
case 0x0c09c422u: goto P_0c09c422;
case 0x0c09c424u: goto P_0c09c424;
case 0x0c09c426u: goto P_0c09c426;
case 0x0c09c428u: goto P_0c09c428;
case 0x0c09c42au: goto P_0c09c42a;
case 0x0c09c42cu: goto P_0c09c42c;
case 0x0c09c42eu: goto P_0c09c42e;
case 0x0c09c430u: goto P_0c09c430;
case 0x0c09c432u: goto P_0c09c432;
case 0x0c09c434u: goto P_0c09c434;
case 0x0c09c436u: goto P_0c09c436;
case 0x0c09c438u: goto P_0c09c438;
case 0x0c09c43au: goto P_0c09c43a;
case 0x0c09c43cu: goto P_0c09c43c;
case 0x0c09c43eu: goto P_0c09c43e;
case 0x0c09c440u: goto P_0c09c440;
case 0x0c09c442u: goto P_0c09c442;
case 0x0c09c444u: goto P_0c09c444;
case 0x0c09c446u: goto P_0c09c446;
case 0x0c09c448u: goto P_0c09c448;
case 0x0c09c458u: goto P_0c09c458;
case 0x0c09c45au: goto P_0c09c45a;
case 0x0c09c45cu: goto P_0c09c45c;
case 0x0c09c45eu: goto P_0c09c45e;
case 0x0c09c460u: goto P_0c09c460;
case 0x0c09c462u: goto P_0c09c462;
case 0x0c09c464u: goto P_0c09c464;
case 0x0c09c466u: goto P_0c09c466;
case 0x0c09c468u: goto P_0c09c468;
case 0x0c09c46au: goto P_0c09c46a;
case 0x0c09c46cu: goto P_0c09c46c;
case 0x0c09c46eu: goto P_0c09c46e;
case 0x0c09c470u: goto P_0c09c470;
case 0x0c09c472u: goto P_0c09c472;
case 0x0c09c474u: goto P_0c09c474;
case 0x0c09c476u: goto P_0c09c476;
case 0x0c09c478u: goto P_0c09c478;
case 0x0c09c47au: goto P_0c09c47a;
case 0x0c09c47cu: goto P_0c09c47c;
case 0x0c09c47eu: goto P_0c09c47e;
case 0x0c09c480u: goto P_0c09c480;
case 0x0c09c482u: goto P_0c09c482;
case 0x0c09c484u: goto P_0c09c484;
case 0x0c09c486u: goto P_0c09c486;
case 0x0c09c488u: goto P_0c09c488;
case 0x0c09c48au: goto P_0c09c48a;
case 0x0c09c48cu: goto P_0c09c48c;
case 0x0c09c48eu: goto P_0c09c48e;
case 0x0c09c490u: goto P_0c09c490;
case 0x0c09c492u: goto P_0c09c492;
case 0x0c09c494u: goto P_0c09c494;
case 0x0c09c496u: goto P_0c09c496;
case 0x0c09c498u: goto P_0c09c498;
case 0x0c09c49au: goto P_0c09c49a;
case 0x0c09c49cu: goto P_0c09c49c;
case 0x0c09c49eu: goto P_0c09c49e;
case 0x0c09c4a0u: goto P_0c09c4a0;
case 0x0c09c4a2u: goto P_0c09c4a2;
case 0x0c09c4a4u: goto P_0c09c4a4;
case 0x0c09c4a6u: goto P_0c09c4a6;
case 0x0c09c4a8u: goto P_0c09c4a8;
case 0x0c09c4aau: goto P_0c09c4aa;
case 0x0c09c4acu: goto P_0c09c4ac;
case 0x0c09c4aeu: goto P_0c09c4ae;
case 0x0c09c4b0u: goto P_0c09c4b0;
case 0x0c09c4b2u: goto P_0c09c4b2;
case 0x0c09c4b4u: goto P_0c09c4b4;
case 0x0c09c4b6u: goto P_0c09c4b6;
case 0x0c09c4b8u: goto P_0c09c4b8;
case 0x0c09c4bau: goto P_0c09c4ba;
case 0x0c09c4bcu: goto P_0c09c4bc;
case 0x0c09c4beu: goto P_0c09c4be;
case 0x0c09c4c0u: goto P_0c09c4c0;
case 0x0c09c4c2u: goto P_0c09c4c2;
case 0x0c09c4c4u: goto P_0c09c4c4;
case 0x0c09c4c6u: goto P_0c09c4c6;
case 0x0c09c4c8u: goto P_0c09c4c8;
case 0x0c09c4cau: goto P_0c09c4ca;
case 0x0c09c4ccu: goto P_0c09c4cc;
case 0x0c09c4ceu: goto P_0c09c4ce;
case 0x0c09c4d0u: goto P_0c09c4d0;
case 0x0c09c4d2u: goto P_0c09c4d2;
case 0x0c09c4d4u: goto P_0c09c4d4;
case 0x0c09c4d6u: goto P_0c09c4d6;
case 0x0c09c4d8u: goto P_0c09c4d8;
case 0x0c09c4dau: goto P_0c09c4da;
case 0x0c09c4dcu: goto P_0c09c4dc;
case 0x0c09c4deu: goto P_0c09c4de;
case 0x0c09c4e0u: goto P_0c09c4e0;
case 0x0c09c4e2u: goto P_0c09c4e2;
case 0x0c09c4e4u: goto P_0c09c4e4;
case 0x0c09c4e6u: goto P_0c09c4e6;
case 0x0c09c4e8u: goto P_0c09c4e8;
case 0x0c09c4eau: goto P_0c09c4ea;
case 0x0c09c4ecu: goto P_0c09c4ec;
case 0x0c09c4eeu: goto P_0c09c4ee;
case 0x0c09c4f0u: goto P_0c09c4f0;
case 0x0c09c4f2u: goto P_0c09c4f2;
case 0x0c09c4f4u: goto P_0c09c4f4;
case 0x0c09c4f6u: goto P_0c09c4f6;
case 0x0c09c4f8u: goto P_0c09c4f8;
case 0x0c09c4fau: goto P_0c09c4fa;
case 0x0c09c4fcu: goto P_0c09c4fc;
case 0x0c09c4feu: goto P_0c09c4fe;
case 0x0c09c500u: goto P_0c09c500;
case 0x0c09c502u: goto P_0c09c502;
case 0x0c09c504u: goto P_0c09c504;
case 0x0c09c506u: goto P_0c09c506;
case 0x0c09c508u: goto P_0c09c508;
case 0x0c09c50au: goto P_0c09c50a;
case 0x0c09c50cu: goto P_0c09c50c;
case 0x0c09c50eu: goto P_0c09c50e;
case 0x0c09c510u: goto P_0c09c510;
case 0x0c09c512u: goto P_0c09c512;
case 0x0c09c514u: goto P_0c09c514;
case 0x0c09c516u: goto P_0c09c516;
case 0x0c09c518u: goto P_0c09c518;
case 0x0c09c51au: goto P_0c09c51a;
case 0x0c09c51cu: goto P_0c09c51c;
case 0x0c09c51eu: goto P_0c09c51e;
case 0x0c09c520u: goto P_0c09c520;
case 0x0c09c522u: goto P_0c09c522;
case 0x0c09c524u: goto P_0c09c524;
case 0x0c09c526u: goto P_0c09c526;
case 0x0c09c528u: goto P_0c09c528;
case 0x0c09c52au: goto P_0c09c52a;
case 0x0c09c52cu: goto P_0c09c52c;
case 0x0c09c52eu: goto P_0c09c52e;
case 0x0c09c530u: goto P_0c09c530;
case 0x0c09c532u: goto P_0c09c532;
case 0x0c09c534u: goto P_0c09c534;
case 0x0c09c536u: goto P_0c09c536;
case 0x0c09c538u: goto P_0c09c538;
case 0x0c09c53au: goto P_0c09c53a;
case 0x0c09c53cu: goto P_0c09c53c;
case 0x0c09c53eu: goto P_0c09c53e;
case 0x0c09c540u: goto P_0c09c540;
case 0x0c09c542u: goto P_0c09c542;
case 0x0c09c544u: goto P_0c09c544;
case 0x0c09c546u: goto P_0c09c546;
case 0x0c09c548u: goto P_0c09c548;
case 0x0c09c54au: goto P_0c09c54a;
case 0x0c09c54cu: goto P_0c09c54c;
case 0x0c09c54eu: goto P_0c09c54e;
case 0x0c09c550u: goto P_0c09c550;
case 0x0c09c552u: goto P_0c09c552;
case 0x0c09c554u: goto P_0c09c554;
case 0x0c09c556u: goto P_0c09c556;
case 0x0c09c558u: goto P_0c09c558;
case 0x0c09c55au: goto P_0c09c55a;
case 0x0c09c568u: goto P_0c09c568;
case 0x0c09c56au: goto P_0c09c56a;
case 0x0c09c56cu: goto P_0c09c56c;
case 0x0c09c56eu: goto P_0c09c56e;
case 0x0c09c570u: goto P_0c09c570;
case 0x0c09c572u: goto P_0c09c572;
case 0x0c09c574u: goto P_0c09c574;
case 0x0c09c576u: goto P_0c09c576;
case 0x0c09c578u: goto P_0c09c578;
case 0x0c09c57au: goto P_0c09c57a;
case 0x0c09c57cu: goto P_0c09c57c;
case 0x0c09c57eu: goto P_0c09c57e;
case 0x0c09c580u: goto P_0c09c580;
case 0x0c09c582u: goto P_0c09c582;
case 0x0c09c584u: goto P_0c09c584;
case 0x0c09c586u: goto P_0c09c586;
case 0x0c09c588u: goto P_0c09c588;
case 0x0c09c58au: goto P_0c09c58a;
case 0x0c09c58cu: goto P_0c09c58c;
case 0x0c09c58eu: goto P_0c09c58e;
case 0x0c09c590u: goto P_0c09c590;
case 0x0c09c592u: goto P_0c09c592;
case 0x0c09c594u: goto P_0c09c594;
case 0x0c09c596u: goto P_0c09c596;
case 0x0c09c598u: goto P_0c09c598;
case 0x0c09c59au: goto P_0c09c59a;
case 0x0c09c59cu: goto P_0c09c59c;
case 0x0c09c59eu: goto P_0c09c59e;
case 0x0c09c5a0u: goto P_0c09c5a0;
case 0x0c09c5a2u: goto P_0c09c5a2;
case 0x0c09c5a4u: goto P_0c09c5a4;
case 0x0c09c5a6u: goto P_0c09c5a6;
case 0x0c09c5a8u: goto P_0c09c5a8;
case 0x0c09c5aau: goto P_0c09c5aa;
case 0x0c09c5acu: goto P_0c09c5ac;
case 0x0c09c5aeu: goto P_0c09c5ae;
case 0x0c09c5b0u: goto P_0c09c5b0;
case 0x0c09c5b2u: goto P_0c09c5b2;
case 0x0c09c5b4u: goto P_0c09c5b4;
case 0x0c09c5b6u: goto P_0c09c5b6;
case 0x0c09c5b8u: goto P_0c09c5b8;
case 0x0c09c5bau: goto P_0c09c5ba;
case 0x0c09c5bcu: goto P_0c09c5bc;
case 0x0c09c5beu: goto P_0c09c5be;
case 0x0c09c5c0u: goto P_0c09c5c0;
case 0x0c09c5c2u: goto P_0c09c5c2;
case 0x0c09c5c4u: goto P_0c09c5c4;
case 0x0c09c5c6u: goto P_0c09c5c6;
case 0x0c09c5c8u: goto P_0c09c5c8;
case 0x0c09c5cau: goto P_0c09c5ca;
case 0x0c09c5ccu: goto P_0c09c5cc;
case 0x0c09c5ceu: goto P_0c09c5ce;
case 0x0c09c5d0u: goto P_0c09c5d0;
case 0x0c09c5d2u: goto P_0c09c5d2;
case 0x0c09c5d4u: goto P_0c09c5d4;
case 0x0c09c5d6u: goto P_0c09c5d6;
case 0x0c09c5d8u: goto P_0c09c5d8;
case 0x0c09c5dau: goto P_0c09c5da;
case 0x0c09c5dcu: goto P_0c09c5dc;
case 0x0c09c5deu: goto P_0c09c5de;
case 0x0c09c5e0u: goto P_0c09c5e0;
case 0x0c09c5e2u: goto P_0c09c5e2;
case 0x0c09c5e4u: goto P_0c09c5e4;
case 0x0c09c5e6u: goto P_0c09c5e6;
case 0x0c09c5e8u: goto P_0c09c5e8;
case 0x0c09c5eau: goto P_0c09c5ea;
case 0x0c09c5ecu: goto P_0c09c5ec;
case 0x0c09c5eeu: goto P_0c09c5ee;
case 0x0c09c5f0u: goto P_0c09c5f0;
case 0x0c09c5f2u: goto P_0c09c5f2;
case 0x0c09c5f4u: goto P_0c09c5f4;
case 0x0c09c5f6u: goto P_0c09c5f6;
case 0x0c09c5f8u: goto P_0c09c5f8;
case 0x0c09c5fau: goto P_0c09c5fa;
case 0x0c09c5fcu: goto P_0c09c5fc;
case 0x0c09c5feu: goto P_0c09c5fe;
case 0x0c09c600u: goto P_0c09c600;
case 0x0c09c602u: goto P_0c09c602;
case 0x0c09c604u: goto P_0c09c604;
case 0x0c09c606u: goto P_0c09c606;
case 0x0c09c608u: goto P_0c09c608;
case 0x0c09c60au: goto P_0c09c60a;
case 0x0c09c60cu: goto P_0c09c60c;
case 0x0c09c60eu: goto P_0c09c60e;
case 0x0c09c610u: goto P_0c09c610;
case 0x0c09c612u: goto P_0c09c612;
case 0x0c09c614u: goto P_0c09c614;
case 0x0c09c616u: goto P_0c09c616;
case 0x0c09c618u: goto P_0c09c618;
case 0x0c09c61au: goto P_0c09c61a;
case 0x0c09c61cu: goto P_0c09c61c;
case 0x0c09c61eu: goto P_0c09c61e;
case 0x0c09c620u: goto P_0c09c620;
case 0x0c09c622u: goto P_0c09c622;
case 0x0c09c624u: goto P_0c09c624;
case 0x0c09c626u: goto P_0c09c626;
case 0x0c09c628u: goto P_0c09c628;
case 0x0c09c62au: goto P_0c09c62a;
case 0x0c09c62cu: goto P_0c09c62c;
case 0x0c09c62eu: goto P_0c09c62e;
case 0x0c09c630u: goto P_0c09c630;
case 0x0c09c632u: goto P_0c09c632;
case 0x0c09c634u: goto P_0c09c634;
case 0x0c09c636u: goto P_0c09c636;
case 0x0c09c638u: goto P_0c09c638;
case 0x0c09c63au: goto P_0c09c63a;
case 0x0c09c63cu: goto P_0c09c63c;
case 0x0c09c63eu: goto P_0c09c63e;
case 0x0c09c640u: goto P_0c09c640;
case 0x0c09c642u: goto P_0c09c642;
case 0x0c09c644u: goto P_0c09c644;
case 0x0c09c646u: goto P_0c09c646;
case 0x0c09c648u: goto P_0c09c648;
case 0x0c09c64au: goto P_0c09c64a;
case 0x0c09c64cu: goto P_0c09c64c;
case 0x0c09c64eu: goto P_0c09c64e;
case 0x0c09c650u: goto P_0c09c650;
case 0x0c09c652u: goto P_0c09c652;
case 0x0c09c654u: goto P_0c09c654;
case 0x0c09c656u: goto P_0c09c656;
case 0x0c09c658u: goto P_0c09c658;
case 0x0c09c65au: goto P_0c09c65a;
case 0x0c09c65cu: goto P_0c09c65c;
case 0x0c09c65eu: goto P_0c09c65e;
case 0x0c09c660u: goto P_0c09c660;
case 0x0c09c662u: goto P_0c09c662;
case 0x0c09c664u: goto P_0c09c664;
case 0x0c09c666u: goto P_0c09c666;
case 0x0c09c668u: goto P_0c09c668;
case 0x0c09c66au: goto P_0c09c66a;
case 0x0c09c66cu: goto P_0c09c66c;
case 0x0c09c66eu: goto P_0c09c66e;
case 0x0c09c67cu: goto P_0c09c67c;
case 0x0c09c67eu: goto P_0c09c67e;
case 0x0c09c680u: goto P_0c09c680;
case 0x0c09c682u: goto P_0c09c682;
case 0x0c09c684u: goto P_0c09c684;
case 0x0c09c686u: goto P_0c09c686;
case 0x0c09c688u: goto P_0c09c688;
case 0x0c09c68au: goto P_0c09c68a;
case 0x0c09c68cu: goto P_0c09c68c;
case 0x0c09c68eu: goto P_0c09c68e;
case 0x0c09c690u: goto P_0c09c690;
case 0x0c09c692u: goto P_0c09c692;
case 0x0c09c694u: goto P_0c09c694;
case 0x0c09c696u: goto P_0c09c696;
case 0x0c09c698u: goto P_0c09c698;
case 0x0c09c69au: goto P_0c09c69a;
case 0x0c09c69cu: goto P_0c09c69c;
case 0x0c09c69eu: goto P_0c09c69e;
case 0x0c09c6a0u: goto P_0c09c6a0;
case 0x0c09c6a2u: goto P_0c09c6a2;
case 0x0c09c6a4u: goto P_0c09c6a4;
case 0x0c09c6a6u: goto P_0c09c6a6;
case 0x0c09c6a8u: goto P_0c09c6a8;
case 0x0c09c6aau: goto P_0c09c6aa;
case 0x0c09c6acu: goto P_0c09c6ac;
case 0x0c09c6aeu: goto P_0c09c6ae;
case 0x0c09c6b0u: goto P_0c09c6b0;
case 0x0c09c6b2u: goto P_0c09c6b2;
case 0x0c09c6b4u: goto P_0c09c6b4;
case 0x0c09c6b6u: goto P_0c09c6b6;
case 0x0c09c6b8u: goto P_0c09c6b8;
case 0x0c09c6bau: goto P_0c09c6ba;
case 0x0c09c6bcu: goto P_0c09c6bc;
case 0x0c09c6beu: goto P_0c09c6be;
case 0x0c09c6c0u: goto P_0c09c6c0;
case 0x0c09c6c2u: goto P_0c09c6c2;
case 0x0c09c6c4u: goto P_0c09c6c4;
case 0x0c09c6c6u: goto P_0c09c6c6;
case 0x0c09c6c8u: goto P_0c09c6c8;
case 0x0c09c6cau: goto P_0c09c6ca;
case 0x0c09c6ccu: goto P_0c09c6cc;
case 0x0c09c6ceu: goto P_0c09c6ce;
case 0x0c09c6d0u: goto P_0c09c6d0;
case 0x0c09c6d2u: goto P_0c09c6d2;
case 0x0c09c6d4u: goto P_0c09c6d4;
case 0x0c09c6d6u: goto P_0c09c6d6;
case 0x0c09c6d8u: goto P_0c09c6d8;
case 0x0c09c6dau: goto P_0c09c6da;
case 0x0c09c6dcu: goto P_0c09c6dc;
case 0x0c09c6deu: goto P_0c09c6de;
case 0x0c09c6e0u: goto P_0c09c6e0;
case 0x0c09c6e2u: goto P_0c09c6e2;
case 0x0c09c6e4u: goto P_0c09c6e4;
case 0x0c09c6e6u: goto P_0c09c6e6;
case 0x0c09c6e8u: goto P_0c09c6e8;
case 0x0c09c6eau: goto P_0c09c6ea;
case 0x0c09c6ecu: goto P_0c09c6ec;
case 0x0c09c6eeu: goto P_0c09c6ee;
case 0x0c09c6f0u: goto P_0c09c6f0;
case 0x0c09c6f2u: goto P_0c09c6f2;
case 0x0c09c6f4u: goto P_0c09c6f4;
case 0x0c09c6f6u: goto P_0c09c6f6;
case 0x0c09c6f8u: goto P_0c09c6f8;
case 0x0c09c6fau: goto P_0c09c6fa;
case 0x0c09c6fcu: goto P_0c09c6fc;
case 0x0c09c6feu: goto P_0c09c6fe;
case 0x0c09c700u: goto P_0c09c700;
case 0x0c09c702u: goto P_0c09c702;
case 0x0c09c704u: goto P_0c09c704;
case 0x0c09c706u: goto P_0c09c706;
case 0x0c09c708u: goto P_0c09c708;
case 0x0c09c70au: goto P_0c09c70a;
case 0x0c09c70cu: goto P_0c09c70c;
case 0x0c09c70eu: goto P_0c09c70e;
case 0x0c09c710u: goto P_0c09c710;
case 0x0c09c712u: goto P_0c09c712;
case 0x0c09c714u: goto P_0c09c714;
case 0x0c09c716u: goto P_0c09c716;
case 0x0c09c718u: goto P_0c09c718;
case 0x0c09c71au: goto P_0c09c71a;
case 0x0c09c71cu: goto P_0c09c71c;
case 0x0c09c71eu: goto P_0c09c71e;
case 0x0c09c720u: goto P_0c09c720;
case 0x0c09c722u: goto P_0c09c722;
case 0x0c09c724u: goto P_0c09c724;
case 0x0c09c726u: goto P_0c09c726;
case 0x0c09c728u: goto P_0c09c728;
case 0x0c09c72au: goto P_0c09c72a;
case 0x0c09c72cu: goto P_0c09c72c;
case 0x0c09c72eu: goto P_0c09c72e;
case 0x0c09c730u: goto P_0c09c730;
case 0x0c09c732u: goto P_0c09c732;
case 0x0c09c734u: goto P_0c09c734;
case 0x0c09c736u: goto P_0c09c736;
case 0x0c09c738u: goto P_0c09c738;
case 0x0c09c73au: goto P_0c09c73a;
case 0x0c09c73cu: goto P_0c09c73c;
case 0x0c09c73eu: goto P_0c09c73e;
case 0x0c09c740u: goto P_0c09c740;
case 0x0c09c742u: goto P_0c09c742;
case 0x0c09c744u: goto P_0c09c744;
case 0x0c09c746u: goto P_0c09c746;
case 0x0c09c748u: goto P_0c09c748;
case 0x0c09c74au: goto P_0c09c74a;
case 0x0c09c74cu: goto P_0c09c74c;
case 0x0c09c74eu: goto P_0c09c74e;
case 0x0c09c750u: goto P_0c09c750;
case 0x0c09c752u: goto P_0c09c752;
case 0x0c09c75cu: goto P_0c09c75c;
case 0x0c09c75eu: goto P_0c09c75e;
case 0x0c09c760u: goto P_0c09c760;
case 0x0c09c762u: goto P_0c09c762;
case 0x0c09c764u: goto P_0c09c764;
case 0x0c09c766u: goto P_0c09c766;
case 0x0c09c768u: goto P_0c09c768;
case 0x0c09c76au: goto P_0c09c76a;
case 0x0c09c76cu: goto P_0c09c76c;
case 0x0c09c76eu: goto P_0c09c76e;
case 0x0c09c770u: goto P_0c09c770;
case 0x0c09c772u: goto P_0c09c772;
case 0x0c09c774u: goto P_0c09c774;
case 0x0c09c776u: goto P_0c09c776;
case 0x0c09c778u: goto P_0c09c778;
case 0x0c09c77au: goto P_0c09c77a;
case 0x0c09c77cu: goto P_0c09c77c;
case 0x0c09c77eu: goto P_0c09c77e;
case 0x0c09c780u: goto P_0c09c780;
case 0x0c09c782u: goto P_0c09c782;
case 0x0c09c784u: goto P_0c09c784;
case 0x0c09c786u: goto P_0c09c786;
case 0x0c09c788u: goto P_0c09c788;
case 0x0c09c78au: goto P_0c09c78a;
case 0x0c09c78cu: goto P_0c09c78c;
case 0x0c09c78eu: goto P_0c09c78e;
case 0x0c09c790u: goto P_0c09c790;
case 0x0c09c792u: goto P_0c09c792;
case 0x0c09c794u: goto P_0c09c794;
case 0x0c09c796u: goto P_0c09c796;
case 0x0c09c798u: goto P_0c09c798;
case 0x0c09c79au: goto P_0c09c79a;
case 0x0c09c79cu: goto P_0c09c79c;
case 0x0c09c79eu: goto P_0c09c79e;
case 0x0c09c7a0u: goto P_0c09c7a0;
case 0x0c09c7a2u: goto P_0c09c7a2;
case 0x0c09c7a4u: goto P_0c09c7a4;
case 0x0c09c7a6u: goto P_0c09c7a6;
case 0x0c09c7a8u: goto P_0c09c7a8;
case 0x0c09c7aau: goto P_0c09c7aa;
case 0x0c09c7acu: goto P_0c09c7ac;
case 0x0c09c7aeu: goto P_0c09c7ae;
case 0x0c09c7b0u: goto P_0c09c7b0;
case 0x0c09c7b2u: goto P_0c09c7b2;
case 0x0c09c7b4u: goto P_0c09c7b4;
case 0x0c09c7b6u: goto P_0c09c7b6;
case 0x0c09c7b8u: goto P_0c09c7b8;
case 0x0c09c7bau: goto P_0c09c7ba;
case 0x0c09c7bcu: goto P_0c09c7bc;
case 0x0c09c7beu: goto P_0c09c7be;
case 0x0c09c7c0u: goto P_0c09c7c0;
case 0x0c09c7c2u: goto P_0c09c7c2;
case 0x0c09c7c4u: goto P_0c09c7c4;
case 0x0c09c7c6u: goto P_0c09c7c6;
case 0x0c09c7c8u: goto P_0c09c7c8;
case 0x0c09c7cau: goto P_0c09c7ca;
case 0x0c09c7ccu: goto P_0c09c7cc;
case 0x0c09c7ceu: goto P_0c09c7ce;
case 0x0c09c7d0u: goto P_0c09c7d0;
case 0x0c09c7d2u: goto P_0c09c7d2;
case 0x0c09c7d4u: goto P_0c09c7d4;
case 0x0c09c7d6u: goto P_0c09c7d6;
case 0x0c09c7d8u: goto P_0c09c7d8;
case 0x0c09c7dau: goto P_0c09c7da;
case 0x0c09c7dcu: goto P_0c09c7dc;
case 0x0c09c7deu: goto P_0c09c7de;
case 0x0c09c7e0u: goto P_0c09c7e0;
case 0x0c09c7e2u: goto P_0c09c7e2;
case 0x0c09c7e4u: goto P_0c09c7e4;
case 0x0c09c7e6u: goto P_0c09c7e6;
case 0x0c09c7e8u: goto P_0c09c7e8;
case 0x0c09c7eau: goto P_0c09c7ea;
case 0x0c09c7ecu: goto P_0c09c7ec;
case 0x0c09c7eeu: goto P_0c09c7ee;
case 0x0c09c7f0u: goto P_0c09c7f0;
case 0x0c09c7f2u: goto P_0c09c7f2;
case 0x0c09c7f4u: goto P_0c09c7f4;
case 0x0c09c7f6u: goto P_0c09c7f6;
case 0x0c09c7f8u: goto P_0c09c7f8;
case 0x0c09c7fau: goto P_0c09c7fa;
case 0x0c09c7fcu: goto P_0c09c7fc;
case 0x0c09c7feu: goto P_0c09c7fe;
case 0x0c09c800u: goto P_0c09c800;
case 0x0c09c802u: goto P_0c09c802;
case 0x0c09c804u: goto P_0c09c804;
case 0x0c09c806u: goto P_0c09c806;
case 0x0c09c808u: goto P_0c09c808;
case 0x0c09c80au: goto P_0c09c80a;
case 0x0c09c80cu: goto P_0c09c80c;
case 0x0c09c80eu: goto P_0c09c80e;
case 0x0c09c810u: goto P_0c09c810;
case 0x0c09c812u: goto P_0c09c812;
case 0x0c09c814u: goto P_0c09c814;
case 0x0c09c816u: goto P_0c09c816;
case 0x0c09c818u: goto P_0c09c818;
case 0x0c09c81au: goto P_0c09c81a;
case 0x0c09c81cu: goto P_0c09c81c;
case 0x0c09c81eu: goto P_0c09c81e;
case 0x0c09c820u: goto P_0c09c820;
case 0x0c09c822u: goto P_0c09c822;
case 0x0c09c824u: goto P_0c09c824;
case 0x0c09c826u: goto P_0c09c826;
case 0x0c09c828u: goto P_0c09c828;
case 0x0c09c82au: goto P_0c09c82a;
case 0x0c09c82cu: goto P_0c09c82c;
case 0x0c09c82eu: goto P_0c09c82e;
case 0x0c09c830u: goto P_0c09c830;
case 0x0c09c832u: goto P_0c09c832;
case 0x0c09c834u: goto P_0c09c834;
case 0x0c09c836u: goto P_0c09c836;
case 0x0c09c838u: goto P_0c09c838;
case 0x0c09c83au: goto P_0c09c83a;
case 0x0c09c83cu: goto P_0c09c83c;
case 0x0c09c83eu: goto P_0c09c83e;
case 0x0c09c840u: goto P_0c09c840;
case 0x0c09c842u: goto P_0c09c842;
case 0x0c09c844u: goto P_0c09c844;
case 0x0c09c846u: goto P_0c09c846;
case 0x0c09c848u: goto P_0c09c848;
case 0x0c09c84au: goto P_0c09c84a;
case 0x0c09c84cu: goto P_0c09c84c;
case 0x0c09c84eu: goto P_0c09c84e;
case 0x0c09c850u: goto P_0c09c850;
case 0x0c09c852u: goto P_0c09c852;
case 0x0c09c854u: goto P_0c09c854;
case 0x0c09c856u: goto P_0c09c856;
case 0x0c09c858u: goto P_0c09c858;
case 0x0c09c85au: goto P_0c09c85a;
case 0x0c09c85cu: goto P_0c09c85c;
case 0x0c09c85eu: goto P_0c09c85e;
case 0x0c09c860u: goto P_0c09c860;
case 0x0c09c862u: goto P_0c09c862;
case 0x0c09c864u: goto P_0c09c864;
case 0x0c09c866u: goto P_0c09c866;
case 0x0c09c868u: goto P_0c09c868;
case 0x0c09c86au: goto P_0c09c86a;
case 0x0c09c86cu: goto P_0c09c86c;
case 0x0c09c86eu: goto P_0c09c86e;
case 0x0c09c870u: goto P_0c09c870;
case 0x0c09c872u: goto P_0c09c872;
case 0x0c09c874u: goto P_0c09c874;
case 0x0c09c876u: goto P_0c09c876;
case 0x0c09c878u: goto P_0c09c878;
case 0x0c09c87au: goto P_0c09c87a;
case 0x0c09c87cu: goto P_0c09c87c;
case 0x0c09c87eu: goto P_0c09c87e;
case 0x0c09c880u: goto P_0c09c880;
case 0x0c09c882u: goto P_0c09c882;
case 0x0c09c884u: goto P_0c09c884;
case 0x0c09c886u: goto P_0c09c886;
case 0x0c09c888u: goto P_0c09c888;
case 0x0c09c88au: goto P_0c09c88a;
case 0x0c09c88cu: goto P_0c09c88c;
case 0x0c09c88eu: goto P_0c09c88e;
case 0x0c09c890u: goto P_0c09c890;
case 0x0c09c892u: goto P_0c09c892;
case 0x0c09c894u: goto P_0c09c894;
case 0x0c09c896u: goto P_0c09c896;
case 0x0c09c898u: goto P_0c09c898;
case 0x0c09c89au: goto P_0c09c89a;
case 0x0c09c89cu: goto P_0c09c89c;
case 0x0c09c89eu: goto P_0c09c89e;
case 0x0c09c8a0u: goto P_0c09c8a0;
case 0x0c09c8a2u: goto P_0c09c8a2;
case 0x0c09c8a4u: goto P_0c09c8a4;
case 0x0c09c8a6u: goto P_0c09c8a6;
case 0x0c09c8a8u: goto P_0c09c8a8;
case 0x0c09c8aau: goto P_0c09c8aa;
case 0x0c09c8acu: goto P_0c09c8ac;
case 0x0c09c8b6u: goto P_0c09c8b6;
case 0x0c09c8b8u: goto P_0c09c8b8;
case 0x0c09c8bau: goto P_0c09c8ba;
case 0x0c09c8bcu: goto P_0c09c8bc;
case 0x0c09c8beu: goto P_0c09c8be;
case 0x0c09c8c0u: goto P_0c09c8c0;
case 0x0c09c8c2u: goto P_0c09c8c2;
case 0x0c09c8c4u: goto P_0c09c8c4;
case 0x0c09c8c6u: goto P_0c09c8c6;
case 0x0c09c8c8u: goto P_0c09c8c8;
case 0x0c09c8cau: goto P_0c09c8ca;
case 0x0c09c8ccu: goto P_0c09c8cc;
case 0x0c09c8ceu: goto P_0c09c8ce;
case 0x0c09c8d0u: goto P_0c09c8d0;
case 0x0c09c8d2u: goto P_0c09c8d2;
case 0x0c09c8d4u: goto P_0c09c8d4;
case 0x0c09c8d6u: goto P_0c09c8d6;
case 0x0c09c8d8u: goto P_0c09c8d8;
case 0x0c09c8dau: goto P_0c09c8da;
case 0x0c09c8dcu: goto P_0c09c8dc;
case 0x0c09c8deu: goto P_0c09c8de;
case 0x0c09c8e0u: goto P_0c09c8e0;
case 0x0c09c8e2u: goto P_0c09c8e2;
case 0x0c09c8e4u: goto P_0c09c8e4;
case 0x0c09c8e6u: goto P_0c09c8e6;
case 0x0c09c8e8u: goto P_0c09c8e8;
case 0x0c09c8eau: goto P_0c09c8ea;
case 0x0c09c8ecu: goto P_0c09c8ec;
case 0x0c09c8eeu: goto P_0c09c8ee;
case 0x0c09c8f0u: goto P_0c09c8f0;
case 0x0c09c8f2u: goto P_0c09c8f2;
case 0x0c09c8f4u: goto P_0c09c8f4;
case 0x0c09c8f6u: goto P_0c09c8f6;
case 0x0c09c8f8u: goto P_0c09c8f8;
case 0x0c09c8fau: goto P_0c09c8fa;
case 0x0c09c8fcu: goto P_0c09c8fc;
case 0x0c09c8feu: goto P_0c09c8fe;
case 0x0c09c900u: goto P_0c09c900;
case 0x0c09c902u: goto P_0c09c902;
case 0x0c09c904u: goto P_0c09c904;
case 0x0c09c906u: goto P_0c09c906;
case 0x0c09c908u: goto P_0c09c908;
case 0x0c09c90au: goto P_0c09c90a;
case 0x0c09c90cu: goto P_0c09c90c;
case 0x0c09c90eu: goto P_0c09c90e;
case 0x0c09c910u: goto P_0c09c910;
case 0x0c09c912u: goto P_0c09c912;
case 0x0c09c914u: goto P_0c09c914;
case 0x0c09c916u: goto P_0c09c916;
case 0x0c09c918u: goto P_0c09c918;
case 0x0c09c91au: goto P_0c09c91a;
case 0x0c09c91cu: goto P_0c09c91c;
case 0x0c09c91eu: goto P_0c09c91e;
case 0x0c09c920u: goto P_0c09c920;
case 0x0c09c922u: goto P_0c09c922;
case 0x0c09c924u: goto P_0c09c924;
case 0x0c09c926u: goto P_0c09c926;
case 0x0c09c928u: goto P_0c09c928;
case 0x0c09c92au: goto P_0c09c92a;
case 0x0c09c92cu: goto P_0c09c92c;
case 0x0c09c92eu: goto P_0c09c92e;
case 0x0c09c930u: goto P_0c09c930;
case 0x0c09c932u: goto P_0c09c932;
case 0x0c09c934u: goto P_0c09c934;
case 0x0c09c936u: goto P_0c09c936;
case 0x0c09c938u: goto P_0c09c938;
case 0x0c09c93au: goto P_0c09c93a;
case 0x0c09c93cu: goto P_0c09c93c;
case 0x0c09c942u: goto P_0c09c942;
case 0x0c09c944u: goto P_0c09c944;
case 0x0c09c946u: goto P_0c09c946;
case 0x0c09c948u: goto P_0c09c948;
case 0x0c09c94au: goto P_0c09c94a;
case 0x0c09c94cu: goto P_0c09c94c;
case 0x0c09c94eu: goto P_0c09c94e;
case 0x0c09c950u: goto P_0c09c950;
case 0x0c09c952u: goto P_0c09c952;
case 0x0c09c954u: goto P_0c09c954;
case 0x0c09c956u: goto P_0c09c956;
case 0x0c09c958u: goto P_0c09c958;
case 0x0c09c95au: goto P_0c09c95a;
case 0x0c09c95cu: goto P_0c09c95c;
case 0x0c09c95eu: goto P_0c09c95e;
case 0x0c09c960u: goto P_0c09c960;
case 0x0c09c962u: goto P_0c09c962;
case 0x0c09c964u: goto P_0c09c964;
case 0x0c09c966u: goto P_0c09c966;
case 0x0c09c968u: goto P_0c09c968;
case 0x0c09c96au: goto P_0c09c96a;
case 0x0c09c96cu: goto P_0c09c96c;
case 0x0c09c96eu: goto P_0c09c96e;
case 0x0c09c970u: goto P_0c09c970;
case 0x0c09c972u: goto P_0c09c972;
case 0x0c09c974u: goto P_0c09c974;
case 0x0c09c976u: goto P_0c09c976;
case 0x0c09c978u: goto P_0c09c978;
case 0x0c09c97au: goto P_0c09c97a;
case 0x0c09c97cu: goto P_0c09c97c;
case 0x0c09c97eu: goto P_0c09c97e;
case 0x0c09c980u: goto P_0c09c980;
case 0x0c09c982u: goto P_0c09c982;
case 0x0c09c984u: goto P_0c09c984;
case 0x0c09c986u: goto P_0c09c986;
case 0x0c09c988u: goto P_0c09c988;
case 0x0c09c98au: goto P_0c09c98a;
case 0x0c09c98cu: goto P_0c09c98c;
case 0x0c09c98eu: goto P_0c09c98e;
case 0x0c09c990u: goto P_0c09c990;
case 0x0c09c992u: goto P_0c09c992;
case 0x0c09c994u: goto P_0c09c994;
case 0x0c09c996u: goto P_0c09c996;
case 0x0c09c998u: goto P_0c09c998;
case 0x0c09c99au: goto P_0c09c99a;
case 0x0c09c99cu: goto P_0c09c99c;
case 0x0c09c99eu: goto P_0c09c99e;
case 0x0c09c9a0u: goto P_0c09c9a0;
case 0x0c09c9a2u: goto P_0c09c9a2;
case 0x0c09c9a4u: goto P_0c09c9a4;
case 0x0c09c9a6u: goto P_0c09c9a6;
case 0x0c09c9a8u: goto P_0c09c9a8;
case 0x0c09c9aau: goto P_0c09c9aa;
case 0x0c09c9acu: goto P_0c09c9ac;
case 0x0c09c9aeu: goto P_0c09c9ae;
case 0x0c09c9b0u: goto P_0c09c9b0;
case 0x0c09c9b2u: goto P_0c09c9b2;
case 0x0c09c9b4u: goto P_0c09c9b4;
case 0x0c09c9b6u: goto P_0c09c9b6;
case 0x0c09c9b8u: goto P_0c09c9b8;
case 0x0c09c9bau: goto P_0c09c9ba;
case 0x0c09c9bcu: goto P_0c09c9bc;
case 0x0c09c9beu: goto P_0c09c9be;
case 0x0c09c9c0u: goto P_0c09c9c0;
case 0x0c09c9c2u: goto P_0c09c9c2;
case 0x0c09c9c4u: goto P_0c09c9c4;
case 0x0c09c9c6u: goto P_0c09c9c6;
case 0x0c09c9c8u: goto P_0c09c9c8;
case 0x0c09c9cau: goto P_0c09c9ca;
case 0x0c09c9ccu: goto P_0c09c9cc;
case 0x0c09c9ceu: goto P_0c09c9ce;
case 0x0c09c9d0u: goto P_0c09c9d0;
case 0x0c09c9d2u: goto P_0c09c9d2;
case 0x0c09c9d4u: goto P_0c09c9d4;
case 0x0c09c9d6u: goto P_0c09c9d6;
case 0x0c09c9d8u: goto P_0c09c9d8;
case 0x0c09c9dau: goto P_0c09c9da;
case 0x0c09c9dcu: goto P_0c09c9dc;
case 0x0c09c9deu: goto P_0c09c9de;
case 0x0c09c9e0u: goto P_0c09c9e0;
case 0x0c09c9e2u: goto P_0c09c9e2;
case 0x0c09c9e4u: goto P_0c09c9e4;
case 0x0c09c9e6u: goto P_0c09c9e6;
case 0x0c09c9e8u: goto P_0c09c9e8;
case 0x0c09c9eau: goto P_0c09c9ea;
case 0x0c09c9ecu: goto P_0c09c9ec;
case 0x0c09c9eeu: goto P_0c09c9ee;
case 0x0c09c9f0u: goto P_0c09c9f0;
case 0x0c09c9f2u: goto P_0c09c9f2;
case 0x0c09c9f4u: goto P_0c09c9f4;
case 0x0c09c9f6u: goto P_0c09c9f6;
case 0x0c09c9f8u: goto P_0c09c9f8;
case 0x0c09c9fau: goto P_0c09c9fa;
case 0x0c09c9fcu: goto P_0c09c9fc;
case 0x0c09c9feu: goto P_0c09c9fe;
case 0x0c09ca00u: goto P_0c09ca00;
case 0x0c09ca02u: goto P_0c09ca02;
case 0x0c09ca04u: goto P_0c09ca04;
case 0x0c09ca06u: goto P_0c09ca06;
case 0x0c09ca08u: goto P_0c09ca08;
case 0x0c09ca0au: goto P_0c09ca0a;
case 0x0c09ca0cu: goto P_0c09ca0c;
case 0x0c09ca0eu: goto P_0c09ca0e;
case 0x0c09ca10u: goto P_0c09ca10;
case 0x0c09ca12u: goto P_0c09ca12;
case 0x0c09ca14u: goto P_0c09ca14;
case 0x0c09ca16u: goto P_0c09ca16;
case 0x0c09ca18u: goto P_0c09ca18;
case 0x0c09ca1au: goto P_0c09ca1a;
case 0x0c09ca1cu: goto P_0c09ca1c;
case 0x0c09ca1eu: goto P_0c09ca1e;
case 0x0c09ca20u: goto P_0c09ca20;
case 0x0c09ca22u: goto P_0c09ca22;
case 0x0c09ca24u: goto P_0c09ca24;
case 0x0c09ca26u: goto P_0c09ca26;
case 0x0c09ca28u: goto P_0c09ca28;
case 0x0c09ca2au: goto P_0c09ca2a;
case 0x0c09ca2cu: goto P_0c09ca2c;
case 0x0c09ca2eu: goto P_0c09ca2e;
case 0x0c09ca30u: goto P_0c09ca30;
case 0x0c09ca32u: goto P_0c09ca32;
case 0x0c09ca34u: goto P_0c09ca34;
case 0x0c09ca36u: goto P_0c09ca36;
case 0x0c09ca38u: goto P_0c09ca38;
case 0x0c09ca3au: goto P_0c09ca3a;
case 0x0c09ca3cu: goto P_0c09ca3c;
case 0x0c09ca46u: goto P_0c09ca46;
case 0x0c09ca48u: goto P_0c09ca48;
case 0x0c09ca4au: goto P_0c09ca4a;
case 0x0c09ca4cu: goto P_0c09ca4c;
case 0x0c09ca4eu: goto P_0c09ca4e;
case 0x0c09ca50u: goto P_0c09ca50;
case 0x0c09ca52u: goto P_0c09ca52;
case 0x0c09ca54u: goto P_0c09ca54;
case 0x0c09ca56u: goto P_0c09ca56;
case 0x0c09ca58u: goto P_0c09ca58;
case 0x0c09ca5au: goto P_0c09ca5a;
case 0x0c09ca5cu: goto P_0c09ca5c;
case 0x0c09ca5eu: goto P_0c09ca5e;
case 0x0c09ca60u: goto P_0c09ca60;
case 0x0c09ca62u: goto P_0c09ca62;
case 0x0c09ca64u: goto P_0c09ca64;
case 0x0c09ca66u: goto P_0c09ca66;
case 0x0c09ca68u: goto P_0c09ca68;
case 0x0c09ca6au: goto P_0c09ca6a;
case 0x0c09ca6cu: goto P_0c09ca6c;
case 0x0c09ca6eu: goto P_0c09ca6e;
case 0x0c09ca70u: goto P_0c09ca70;
case 0x0c09ca72u: goto P_0c09ca72;
case 0x0c09ca74u: goto P_0c09ca74;
case 0x0c09ca76u: goto P_0c09ca76;
case 0x0c09ca78u: goto P_0c09ca78;
case 0x0c09ca7au: goto P_0c09ca7a;
case 0x0c09ca7cu: goto P_0c09ca7c;
case 0x0c09ca7eu: goto P_0c09ca7e;
case 0x0c09ca80u: goto P_0c09ca80;
case 0x0c09ca82u: goto P_0c09ca82;
case 0x0c09ca84u: goto P_0c09ca84;
case 0x0c09ca86u: goto P_0c09ca86;
case 0x0c09ca88u: goto P_0c09ca88;
case 0x0c09ca8au: goto P_0c09ca8a;
case 0x0c0abcb8u: goto P_0c0abcb8;
case 0x0c0abcbau: goto P_0c0abcba;
case 0x0c0abcbcu: goto P_0c0abcbc;
case 0x0c0abcbeu: goto P_0c0abcbe;
case 0x0c0abcc0u: goto P_0c0abcc0;
case 0x0c0abcc2u: goto P_0c0abcc2;
case 0x0c0abcc4u: goto P_0c0abcc4;
case 0x0c0abcc6u: goto P_0c0abcc6;
case 0x0c0abcc8u: goto P_0c0abcc8;
case 0x0c0abccau: goto P_0c0abcca;
case 0x0c0abcccu: goto P_0c0abccc;
case 0x0c0abcceu: goto P_0c0abcce;
case 0x0c0abcd0u: goto P_0c0abcd0;
case 0x0c0abcd2u: goto P_0c0abcd2;
case 0x0c0abcd4u: goto P_0c0abcd4;
case 0x0c0abcd6u: goto P_0c0abcd6;
case 0x0c0abcd8u: goto P_0c0abcd8;
case 0x0c0abcdau: goto P_0c0abcda;
case 0x0c0abdc4u: goto P_0c0abdc4;
case 0x0c0abdc6u: goto P_0c0abdc6;
case 0x0c0abdc8u: goto P_0c0abdc8;
case 0x0c0abdcau: goto P_0c0abdca;
case 0x0c0abdccu: goto P_0c0abdcc;
case 0x0c0abdceu: goto P_0c0abdce;
case 0x0c0abdd0u: goto P_0c0abdd0;
case 0x0c0abdd2u: goto P_0c0abdd2;
case 0x0c0abdd4u: goto P_0c0abdd4;
case 0x0c0abdd6u: goto P_0c0abdd6;
case 0x0c0abdd8u: goto P_0c0abdd8;
case 0x0c0abddau: goto P_0c0abdda;
case 0x0c0abddcu: goto P_0c0abddc;
case 0x0c0abddeu: goto P_0c0abdde;
case 0x0c0abde0u: goto P_0c0abde0;
case 0x0c0abde2u: goto P_0c0abde2;
case 0x0c0abde4u: goto P_0c0abde4;
case 0x0c0abde6u: goto P_0c0abde6;
case 0x0c0abde8u: goto P_0c0abde8;
case 0x0c0abdeau: goto P_0c0abdea;
case 0x0c0abdecu: goto P_0c0abdec;
case 0x0c0abdeeu: goto P_0c0abdee;
case 0x0c0abdf0u: goto P_0c0abdf0;
case 0x0c0abdf2u: goto P_0c0abdf2;
case 0x0c0abdf4u: goto P_0c0abdf4;
case 0x0c0abdf6u: goto P_0c0abdf6;
case 0x0c0abdf8u: goto P_0c0abdf8;
case 0x0c0abdfau: goto P_0c0abdfa;
case 0x0c0abe20u: goto P_0c0abe20;
case 0x0c0abe22u: goto P_0c0abe22;
case 0x0c0abe24u: goto P_0c0abe24;
case 0x0c0abe26u: goto P_0c0abe26;
case 0x0c0abe28u: goto P_0c0abe28;
case 0x0c0abe2au: goto P_0c0abe2a;
case 0x0c0abe2cu: goto P_0c0abe2c;
case 0x0c0abe2eu: goto P_0c0abe2e;
case 0x0c0abe30u: goto P_0c0abe30;
case 0x0c0abe32u: goto P_0c0abe32;
case 0x0c0abe34u: goto P_0c0abe34;
case 0x0c0abe36u: goto P_0c0abe36;
case 0x0c0abe38u: goto P_0c0abe38;
case 0x0c0abe3au: goto P_0c0abe3a;
case 0x0c0abe3cu: goto P_0c0abe3c;
case 0x0c0abe3eu: goto P_0c0abe3e;
case 0x0c0abe40u: goto P_0c0abe40;
case 0x0c0abe42u: goto P_0c0abe42;
case 0x0c0abe44u: goto P_0c0abe44;
case 0x0c0abe46u: goto P_0c0abe46;
case 0x0c0abe48u: goto P_0c0abe48;
case 0x0c0abe4au: goto P_0c0abe4a;
case 0x0c0abe4cu: goto P_0c0abe4c;
case 0x0c0abe4eu: goto P_0c0abe4e;
case 0x0c0c2f4eu: goto P_0c0c2f4e;
case 0x0c0c2f50u: goto P_0c0c2f50;
case 0x0c0c2f52u: goto P_0c0c2f52;
case 0x0c0c2f54u: goto P_0c0c2f54;
case 0x0c0c2f56u: goto P_0c0c2f56;
case 0x0c0c2f58u: goto P_0c0c2f58;
case 0x0c0c2f5au: goto P_0c0c2f5a;
case 0x0c0c2f5cu: goto P_0c0c2f5c;
case 0x0c0c2f5eu: goto P_0c0c2f5e;
case 0x0c0c2f60u: goto P_0c0c2f60;
case 0x0c0c2f62u: goto P_0c0c2f62;
case 0x0c0c2f64u: goto P_0c0c2f64;
case 0x0c0c2f66u: goto P_0c0c2f66;
case 0x0c0c2f68u: goto P_0c0c2f68;
case 0x0c0c2f6au: goto P_0c0c2f6a;
case 0x0c0c2f6cu: goto P_0c0c2f6c;
case 0x0c0c2f6eu: goto P_0c0c2f6e;
case 0x0c0c2f70u: goto P_0c0c2f70;
case 0x0c0c2f72u: goto P_0c0c2f72;
case 0x0c0c2f74u: goto P_0c0c2f74;
case 0x0c0c2f76u: goto P_0c0c2f76;
case 0x0c0c2f78u: goto P_0c0c2f78;
case 0x0c0c2f7au: goto P_0c0c2f7a;
case 0x0c0c2f7cu: goto P_0c0c2f7c;
case 0x0c0c2f7eu: goto P_0c0c2f7e;
case 0x0c0c2f80u: goto P_0c0c2f80;
case 0x0c0c2f82u: goto P_0c0c2f82;
case 0x0c0c2f84u: goto P_0c0c2f84;
case 0x0c0c2f86u: goto P_0c0c2f86;
case 0x0c0c2f88u: goto P_0c0c2f88;
case 0x0c0c2f8au: goto P_0c0c2f8a;
case 0x0c0c2f8cu: goto P_0c0c2f8c;
case 0x0c0c2f8eu: goto P_0c0c2f8e;
case 0x0c0c2f90u: goto P_0c0c2f90;
case 0x0c0c2f92u: goto P_0c0c2f92;
case 0x0c0c2f94u: goto P_0c0c2f94;
case 0x0c0c2f96u: goto P_0c0c2f96;
case 0x0c0c2f98u: goto P_0c0c2f98;
case 0x0c0c2f9au: goto P_0c0c2f9a;
case 0x0c0c2f9cu: goto P_0c0c2f9c;
case 0x0c0c2f9eu: goto P_0c0c2f9e;
case 0x0c0c2fa0u: goto P_0c0c2fa0;
case 0x0c0c2fa2u: goto P_0c0c2fa2;
case 0x0c0c2fa4u: goto P_0c0c2fa4;
case 0x0c0c2fa6u: goto P_0c0c2fa6;
case 0x0c0c2fa8u: goto P_0c0c2fa8;
case 0x0c0c2faau: goto P_0c0c2faa;
case 0x0c0c2facu: goto P_0c0c2fac;
case 0x0c0c2faeu: goto P_0c0c2fae;
case 0x0c0c2fb0u: goto P_0c0c2fb0;
case 0x0c0c2fb2u: goto P_0c0c2fb2;
case 0x0c0c2fb4u: goto P_0c0c2fb4;
case 0x0c0c2fb6u: goto P_0c0c2fb6;
case 0x0c0c2fb8u: goto P_0c0c2fb8;
case 0x0c0c2fbau: goto P_0c0c2fba;
case 0x0c0c2fbcu: goto P_0c0c2fbc;
case 0x0c0c2fbeu: goto P_0c0c2fbe;
case 0x0c0c2fc0u: goto P_0c0c2fc0;
case 0x0c0c2fc2u: goto P_0c0c2fc2;
case 0x0c0c2fc4u: goto P_0c0c2fc4;
case 0x0c0c2fc6u: goto P_0c0c2fc6;
case 0x0c0c2fc8u: goto P_0c0c2fc8;
case 0x0c0c2fcau: goto P_0c0c2fca;
case 0x0c0c2fccu: goto P_0c0c2fcc;
case 0x0c0c2fceu: goto P_0c0c2fce;
case 0x0c0c2fd0u: goto P_0c0c2fd0;
case 0x0c0c2fd2u: goto P_0c0c2fd2;
case 0x0c0c2fd4u: goto P_0c0c2fd4;
case 0x0c0c2fd6u: goto P_0c0c2fd6;
case 0x0c0c2fd8u: goto P_0c0c2fd8;
case 0x0c0c2fdau: goto P_0c0c2fda;
case 0x0c0c2fdcu: goto P_0c0c2fdc;
case 0x0c0c2fdeu: goto P_0c0c2fde;
case 0x0c0c2fe0u: goto P_0c0c2fe0;
case 0x0c0c2fe2u: goto P_0c0c2fe2;
case 0x0c0c2fe4u: goto P_0c0c2fe4;
case 0x0c0c2fe6u: goto P_0c0c2fe6;
case 0x0c0c2fe8u: goto P_0c0c2fe8;
case 0x0c0c2feau: goto P_0c0c2fea;
case 0x0c0c2fecu: goto P_0c0c2fec;
case 0x0c0c2feeu: goto P_0c0c2fee;
case 0x0c0c2ff0u: goto P_0c0c2ff0;
case 0x0c0c2ff2u: goto P_0c0c2ff2;
case 0x0c0c2ff4u: goto P_0c0c2ff4;
case 0x0c0c2ff6u: goto P_0c0c2ff6;
case 0x0c0c2ff8u: goto P_0c0c2ff8;
case 0x0c0c2ffau: goto P_0c0c2ffa;
case 0x0c0c2ffcu: goto P_0c0c2ffc;
case 0x0c0c2ffeu: goto P_0c0c2ffe;
case 0x0c0c3000u: goto P_0c0c3000;
case 0x0c0c3002u: goto P_0c0c3002;
case 0x0c0c3004u: goto P_0c0c3004;
case 0x0c0c3006u: goto P_0c0c3006;
case 0x0c0c3008u: goto P_0c0c3008;
case 0x0c0c300au: goto P_0c0c300a;
case 0x0c0c300cu: goto P_0c0c300c;
case 0x0c0c300eu: goto P_0c0c300e;
case 0x0c0c3010u: goto P_0c0c3010;
case 0x0c0c3012u: goto P_0c0c3012;
case 0x0c0c3014u: goto P_0c0c3014;
case 0x0c0c3016u: goto P_0c0c3016;
case 0x0c0c3018u: goto P_0c0c3018;
case 0x0c0c301au: goto P_0c0c301a;
case 0x0c0c301cu: goto P_0c0c301c;
case 0x0c0c301eu: goto P_0c0c301e;
case 0x0c0c3020u: goto P_0c0c3020;
case 0x0c0c3022u: goto P_0c0c3022;
case 0x0c0c3024u: goto P_0c0c3024;
case 0x0c0c3026u: goto P_0c0c3026;
case 0x0c0c3028u: goto P_0c0c3028;
case 0x0c0c302au: goto P_0c0c302a;
case 0x0c0c304cu: goto P_0c0c304c;
case 0x0c0c304eu: goto P_0c0c304e;
case 0x0c0c3050u: goto P_0c0c3050;
case 0x0c0c3052u: goto P_0c0c3052;
case 0x0c0c3054u: goto P_0c0c3054;
case 0x0c0c3056u: goto P_0c0c3056;
case 0x0c0c3058u: goto P_0c0c3058;
case 0x0c0c305au: goto P_0c0c305a;
case 0x0c0c305cu: goto P_0c0c305c;
case 0x0c0c305eu: goto P_0c0c305e;
case 0x0c0c3060u: goto P_0c0c3060;
case 0x0c0c3062u: goto P_0c0c3062;
case 0x0c0c3064u: goto P_0c0c3064;
case 0x0c0c3066u: goto P_0c0c3066;
case 0x0c0c3068u: goto P_0c0c3068;
case 0x0c0c306au: goto P_0c0c306a;
case 0x0c0c306cu: goto P_0c0c306c;
case 0x0c0c306eu: goto P_0c0c306e;
case 0x0c0c3070u: goto P_0c0c3070;
case 0x0c0c3072u: goto P_0c0c3072;
case 0x0c0c3074u: goto P_0c0c3074;
case 0x0c0c3076u: goto P_0c0c3076;
case 0x0c0c3078u: goto P_0c0c3078;
case 0x0c0c307au: goto P_0c0c307a;
case 0x0c0c307cu: goto P_0c0c307c;
case 0x0c0c307eu: goto P_0c0c307e;
case 0x0c0c3080u: goto P_0c0c3080;
case 0x0c0c3082u: goto P_0c0c3082;
case 0x0c0c3084u: goto P_0c0c3084;
case 0x0c0c3086u: goto P_0c0c3086;
case 0x0c0c3088u: goto P_0c0c3088;
case 0x0c0c308au: goto P_0c0c308a;
case 0x0c0c308cu: goto P_0c0c308c;
case 0x0c0c308eu: goto P_0c0c308e;
case 0x0c0c3090u: goto P_0c0c3090;
case 0x0c0c3092u: goto P_0c0c3092;
case 0x0c0c3094u: goto P_0c0c3094;
case 0x0c0c3096u: goto P_0c0c3096;
case 0x0c0c3098u: goto P_0c0c3098;
case 0x0c0c309au: goto P_0c0c309a;
case 0x0c0c309cu: goto P_0c0c309c;
case 0x0c0c309eu: goto P_0c0c309e;
case 0x0c0c30a0u: goto P_0c0c30a0;
case 0x0c0c30a2u: goto P_0c0c30a2;
case 0x0c0c30a4u: goto P_0c0c30a4;
case 0x0c0c30a6u: goto P_0c0c30a6;
case 0x0c0c30a8u: goto P_0c0c30a8;
case 0x0c0c30aau: goto P_0c0c30aa;
case 0x0c0c30acu: goto P_0c0c30ac;
case 0x0c0c30aeu: goto P_0c0c30ae;
case 0x0c0c30b0u: goto P_0c0c30b0;
case 0x0c0c30b2u: goto P_0c0c30b2;
case 0x0c0c30b4u: goto P_0c0c30b4;
case 0x0c0c30b6u: goto P_0c0c30b6;
case 0x0c0c30b8u: goto P_0c0c30b8;
case 0x0c0c30bau: goto P_0c0c30ba;
case 0x0c0c30bcu: goto P_0c0c30bc;
case 0x0c0c30beu: goto P_0c0c30be;
case 0x0c0c30c0u: goto P_0c0c30c0;
case 0x0c0c30c2u: goto P_0c0c30c2;
case 0x0c0c30c4u: goto P_0c0c30c4;
case 0x0c0c30c6u: goto P_0c0c30c6;
case 0x0c0c30c8u: goto P_0c0c30c8;
case 0x0c0c30cau: goto P_0c0c30ca;
case 0x0c0c30ccu: goto P_0c0c30cc;
case 0x0c0c30ceu: goto P_0c0c30ce;
case 0x0c0c30d0u: goto P_0c0c30d0;
case 0x0c0c30d2u: goto P_0c0c30d2;
case 0x0c0c30d4u: goto P_0c0c30d4;
case 0x0c0c30d6u: goto P_0c0c30d6;
case 0x0c0c30d8u: goto P_0c0c30d8;
case 0x0c0c30dau: goto P_0c0c30da;
case 0x0c0c30e8u: goto P_0c0c30e8;
case 0x0c0c30eau: goto P_0c0c30ea;
case 0x0c0c30ecu: goto P_0c0c30ec;
case 0x0c0c30eeu: goto P_0c0c30ee;
case 0x0c0c30f0u: goto P_0c0c30f0;
case 0x0c0c30f2u: goto P_0c0c30f2;
case 0x0c0c30f4u: goto P_0c0c30f4;
case 0x0c0c30f6u: goto P_0c0c30f6;
case 0x0c0c30f8u: goto P_0c0c30f8;
case 0x0c0c30fau: goto P_0c0c30fa;
case 0x0c0c30fcu: goto P_0c0c30fc;
case 0x0c0c30feu: goto P_0c0c30fe;
case 0x0c0c3100u: goto P_0c0c3100;
case 0x0c0c3102u: goto P_0c0c3102;
case 0x0c0c3104u: goto P_0c0c3104;
case 0x0c0c3106u: goto P_0c0c3106;
case 0x0c0c3108u: goto P_0c0c3108;
case 0x0c0c310au: goto P_0c0c310a;
case 0x0c0c310cu: goto P_0c0c310c;
case 0x0c0c310eu: goto P_0c0c310e;
case 0x0c0c3110u: goto P_0c0c3110;
case 0x0c0c3112u: goto P_0c0c3112;
case 0x0c0c3114u: goto P_0c0c3114;
case 0x0c0c3116u: goto P_0c0c3116;
case 0x0c0c3118u: goto P_0c0c3118;
case 0x0c0c311au: goto P_0c0c311a;
case 0x0c0c311cu: goto P_0c0c311c;
case 0x0c0c311eu: goto P_0c0c311e;
case 0x0c0c3120u: goto P_0c0c3120;
case 0x0c0c3122u: goto P_0c0c3122;
case 0x0c0c3124u: goto P_0c0c3124;
case 0x0c0c3126u: goto P_0c0c3126;
case 0x0c0c3128u: goto P_0c0c3128;
case 0x0c0c312au: goto P_0c0c312a;
case 0x0c0c312cu: goto P_0c0c312c;
case 0x0c0c312eu: goto P_0c0c312e;
case 0x0c0c3130u: goto P_0c0c3130;
case 0x0c0c3132u: goto P_0c0c3132;
case 0x0c0c3134u: goto P_0c0c3134;
case 0x0c0c3136u: goto P_0c0c3136;
case 0x0c0c3138u: goto P_0c0c3138;
case 0x0c0c313au: goto P_0c0c313a;
case 0x0c0c313cu: goto P_0c0c313c;
case 0x0c0c313eu: goto P_0c0c313e;
case 0x0c0c3140u: goto P_0c0c3140;
case 0x0c0c3142u: goto P_0c0c3142;
case 0x0c0c3144u: goto P_0c0c3144;
case 0x0c0c3146u: goto P_0c0c3146;
case 0x0c0c3148u: goto P_0c0c3148;
case 0x0c0c314au: goto P_0c0c314a;
case 0x0c0c314cu: goto P_0c0c314c;
case 0x0c0c314eu: goto P_0c0c314e;
case 0x0c0c3150u: goto P_0c0c3150;
case 0x0c0c3152u: goto P_0c0c3152;
case 0x0c0c3154u: goto P_0c0c3154;
case 0x0c0c3156u: goto P_0c0c3156;
case 0x0c0c3158u: goto P_0c0c3158;
case 0x0c0c315au: goto P_0c0c315a;
case 0x0c0c315cu: goto P_0c0c315c;
case 0x0c0c315eu: goto P_0c0c315e;
case 0x0c0c3160u: goto P_0c0c3160;
case 0x0c0c3162u: goto P_0c0c3162;
case 0x0c0c3164u: goto P_0c0c3164;
case 0x0c0c3166u: goto P_0c0c3166;
case 0x0c0c3168u: goto P_0c0c3168;
case 0x0c0c316au: goto P_0c0c316a;
case 0x0c0c316cu: goto P_0c0c316c;
case 0x0c0c316eu: goto P_0c0c316e;
case 0x0c0c3170u: goto P_0c0c3170;
case 0x0c0c3172u: goto P_0c0c3172;
case 0x0c0c3174u: goto P_0c0c3174;
case 0x0c0c3176u: goto P_0c0c3176;
case 0x0c0c3178u: goto P_0c0c3178;
case 0x0c0c317au: goto P_0c0c317a;
case 0x0c0c317cu: goto P_0c0c317c;
case 0x0c0c317eu: goto P_0c0c317e;
case 0x0c0c3180u: goto P_0c0c3180;
case 0x0c0c3182u: goto P_0c0c3182;
case 0x0c0c3184u: goto P_0c0c3184;
case 0x0c0c3186u: goto P_0c0c3186;
case 0x0c0c3188u: goto P_0c0c3188;
case 0x0c0c318au: goto P_0c0c318a;
case 0x0c0c318cu: goto P_0c0c318c;
case 0x0c0c318eu: goto P_0c0c318e;
case 0x0c0c3190u: goto P_0c0c3190;
case 0x0c0c3192u: goto P_0c0c3192;
case 0x0c0c3194u: goto P_0c0c3194;
case 0x0c0c3196u: goto P_0c0c3196;
case 0x0c0c3198u: goto P_0c0c3198;
case 0x0c0c319au: goto P_0c0c319a;
case 0x0c0c319cu: goto P_0c0c319c;
case 0x0c0c319eu: goto P_0c0c319e;
case 0x0c0c31a0u: goto P_0c0c31a0;
case 0x0c0c31a2u: goto P_0c0c31a2;
case 0x0c0c31a4u: goto P_0c0c31a4;
case 0x0c0c31a6u: goto P_0c0c31a6;
case 0x0c0c31a8u: goto P_0c0c31a8;
case 0x0c0c31aau: goto P_0c0c31aa;
case 0x0c0c31acu: goto P_0c0c31ac;
case 0x0c0c31aeu: goto P_0c0c31ae;
case 0x0c0c31b0u: goto P_0c0c31b0;
case 0x0c0c31b2u: goto P_0c0c31b2;
case 0x0c0c31b4u: goto P_0c0c31b4;
case 0x0c0c31b6u: goto P_0c0c31b6;
case 0x0c0c31b8u: goto P_0c0c31b8;
case 0x0c0c31bau: goto P_0c0c31ba;
case 0x0c0c31bcu: goto P_0c0c31bc;
case 0x0c0c31beu: goto P_0c0c31be;
case 0x0c0c31c0u: goto P_0c0c31c0;
case 0x0c0c31c2u: goto P_0c0c31c2;
case 0x0c0c31c4u: goto P_0c0c31c4;
case 0x0c0c31c6u: goto P_0c0c31c6;
case 0x0c0c31c8u: goto P_0c0c31c8;
case 0x0c0c31cau: goto P_0c0c31ca;
case 0x0c0c31ccu: goto P_0c0c31cc;
case 0x0c0c31ceu: goto P_0c0c31ce;
case 0x0c0c31d0u: goto P_0c0c31d0;
case 0x0c0c31d2u: goto P_0c0c31d2;
case 0x0c0c31d4u: goto P_0c0c31d4;
case 0x0c0c31d6u: goto P_0c0c31d6;
case 0x0c0c31d8u: goto P_0c0c31d8;
case 0x0c0c31dau: goto P_0c0c31da;
case 0x0c0c31dcu: goto P_0c0c31dc;
case 0x0c0c31deu: goto P_0c0c31de;
case 0x0c0c31e0u: goto P_0c0c31e0;
case 0x0c0c31e2u: goto P_0c0c31e2;
case 0x0c0c31e4u: goto P_0c0c31e4;
case 0x0c0c31e6u: goto P_0c0c31e6;
case 0x0c0c31e8u: goto P_0c0c31e8;
case 0x0c0c31eau: goto P_0c0c31ea;
case 0x0c0c31ecu: goto P_0c0c31ec;
case 0x0c0c31eeu: goto P_0c0c31ee;
case 0x0c0c31f0u: goto P_0c0c31f0;
case 0x0c0c31f2u: goto P_0c0c31f2;
case 0x0c0c31f4u: goto P_0c0c31f4;
case 0x0c0c3210u: goto P_0c0c3210;
case 0x0c0c3212u: goto P_0c0c3212;
case 0x0c0c3214u: goto P_0c0c3214;
case 0x0c0c3216u: goto P_0c0c3216;
case 0x0c0c3218u: goto P_0c0c3218;
case 0x0c0c321au: goto P_0c0c321a;
case 0x0c0c321cu: goto P_0c0c321c;
case 0x0c0c321eu: goto P_0c0c321e;
case 0x0c0c3220u: goto P_0c0c3220;
case 0x0c0c3222u: goto P_0c0c3222;
case 0x0c0c3224u: goto P_0c0c3224;
case 0x0c0c3226u: goto P_0c0c3226;
case 0x0c0c3228u: goto P_0c0c3228;
case 0x0c0c322au: goto P_0c0c322a;
case 0x0c0c322cu: goto P_0c0c322c;
case 0x0c0c322eu: goto P_0c0c322e;
case 0x0c0c3230u: goto P_0c0c3230;
case 0x0c0c3232u: goto P_0c0c3232;
case 0x0c0c3234u: goto P_0c0c3234;
case 0x0c0c3236u: goto P_0c0c3236;
case 0x0c0c3238u: goto P_0c0c3238;
case 0x0c0c323au: goto P_0c0c323a;
case 0x0c0c323cu: goto P_0c0c323c;
case 0x0c0c323eu: goto P_0c0c323e;
case 0x0c0c3240u: goto P_0c0c3240;
case 0x0c0c3242u: goto P_0c0c3242;
case 0x0c0c3244u: goto P_0c0c3244;
case 0x0c0c3246u: goto P_0c0c3246;
case 0x0c0c3248u: goto P_0c0c3248;
case 0x0c0c324au: goto P_0c0c324a;
case 0x0c0c324cu: goto P_0c0c324c;
case 0x0c0c324eu: goto P_0c0c324e;
case 0x0c0c3250u: goto P_0c0c3250;
case 0x0c0c3252u: goto P_0c0c3252;
case 0x0c0c3254u: goto P_0c0c3254;
case 0x0c0c3256u: goto P_0c0c3256;
case 0x0c0c3258u: goto P_0c0c3258;
case 0x0c0c325au: goto P_0c0c325a;
case 0x0c0c325cu: goto P_0c0c325c;
case 0x0c0c325eu: goto P_0c0c325e;
case 0x0c0c3260u: goto P_0c0c3260;
case 0x0c0c3262u: goto P_0c0c3262;
case 0x0c0c3264u: goto P_0c0c3264;
case 0x0c0c3266u: goto P_0c0c3266;
case 0x0c0c3268u: goto P_0c0c3268;
case 0x0c0c326au: goto P_0c0c326a;
case 0x0c0c326cu: goto P_0c0c326c;
case 0x0c0c326eu: goto P_0c0c326e;
case 0x0c0c3270u: goto P_0c0c3270;
case 0x0c0c3272u: goto P_0c0c3272;
case 0x0c0c3274u: goto P_0c0c3274;
case 0x0c0c3276u: goto P_0c0c3276;
case 0x0c0c3278u: goto P_0c0c3278;
case 0x0c0c327au: goto P_0c0c327a;
case 0x0c0c327cu: goto P_0c0c327c;
case 0x0c0c327eu: goto P_0c0c327e;
case 0x0c0c3280u: goto P_0c0c3280;
case 0x0c0c3282u: goto P_0c0c3282;
case 0x0c0c3284u: goto P_0c0c3284;
case 0x0c0c3286u: goto P_0c0c3286;
case 0x0c0c3288u: goto P_0c0c3288;
case 0x0c0c328au: goto P_0c0c328a;
case 0x0c0c328cu: goto P_0c0c328c;
case 0x0c0c328eu: goto P_0c0c328e;
case 0x0c0c3290u: goto P_0c0c3290;
case 0x0c0c3292u: goto P_0c0c3292;
case 0x0c0c3294u: goto P_0c0c3294;
case 0x0c0c3296u: goto P_0c0c3296;
case 0x0c0c3298u: goto P_0c0c3298;
case 0x0c0c329au: goto P_0c0c329a;
case 0x0c0c329cu: goto P_0c0c329c;
case 0x0c0c329eu: goto P_0c0c329e;
case 0x0c0c32a0u: goto P_0c0c32a0;
case 0x0c0c32a2u: goto P_0c0c32a2;
case 0x0c0c32a4u: goto P_0c0c32a4;
case 0x0c0c32a6u: goto P_0c0c32a6;
case 0x0c0c32a8u: goto P_0c0c32a8;
case 0x0c0c32aau: goto P_0c0c32aa;
case 0x0c0c32acu: goto P_0c0c32ac;
case 0x0c0c32aeu: goto P_0c0c32ae;
case 0x0c0c32b0u: goto P_0c0c32b0;
case 0x0c0c32b2u: goto P_0c0c32b2;
case 0x0c0c32b4u: goto P_0c0c32b4;
case 0x0c0c32b6u: goto P_0c0c32b6;
case 0x0c0c32b8u: goto P_0c0c32b8;
case 0x0c0c32bau: goto P_0c0c32ba;
case 0x0c0c32bcu: goto P_0c0c32bc;
case 0x0c0c32beu: goto P_0c0c32be;
case 0x0c0c32c0u: goto P_0c0c32c0;
case 0x0c0c32c2u: goto P_0c0c32c2;
case 0x0c0c32c4u: goto P_0c0c32c4;
case 0x0c0c32c6u: goto P_0c0c32c6;
case 0x0c0c32c8u: goto P_0c0c32c8;
case 0x0c0c32cau: goto P_0c0c32ca;
case 0x0c0c32ccu: goto P_0c0c32cc;
case 0x0c0c32ceu: goto P_0c0c32ce;
case 0x0c0c32d0u: goto P_0c0c32d0;
case 0x0c0c32d2u: goto P_0c0c32d2;
case 0x0c0c32d4u: goto P_0c0c32d4;
case 0x0c0c32d6u: goto P_0c0c32d6;
case 0x0c0c32d8u: goto P_0c0c32d8;
case 0x0c0c32dau: goto P_0c0c32da;
case 0x0c0c32dcu: goto P_0c0c32dc;
case 0x0c0c32deu: goto P_0c0c32de;
case 0x0c0c32e0u: goto P_0c0c32e0;
case 0x0c0c32e2u: goto P_0c0c32e2;
case 0x0c0c32e4u: goto P_0c0c32e4;
case 0x0c0c32e6u: goto P_0c0c32e6;
case 0x0c0c32e8u: goto P_0c0c32e8;
case 0x0c0c32eau: goto P_0c0c32ea;
case 0x0c0c32ecu: goto P_0c0c32ec;
case 0x0c0c32eeu: goto P_0c0c32ee;
case 0x0c0c32f0u: goto P_0c0c32f0;
case 0x0c0c32f2u: goto P_0c0c32f2;
case 0x0c0c32f4u: goto P_0c0c32f4;
case 0x0c0c32f6u: goto P_0c0c32f6;
case 0x0c0c32f8u: goto P_0c0c32f8;
case 0x0c0c32fau: goto P_0c0c32fa;
case 0x0c0c32fcu: goto P_0c0c32fc;
case 0x0c0c32feu: goto P_0c0c32fe;
case 0x0c0c3300u: goto P_0c0c3300;
case 0x0c0c3302u: goto P_0c0c3302;
case 0x0c0c3304u: goto P_0c0c3304;
case 0x0c0c3306u: goto P_0c0c3306;
case 0x0c0c3308u: goto P_0c0c3308;
case 0x0c0c330au: goto P_0c0c330a;
case 0x0c0c330cu: goto P_0c0c330c;
case 0x0c0c330eu: goto P_0c0c330e;
case 0x0c0c3310u: goto P_0c0c3310;
case 0x0c0c3312u: goto P_0c0c3312;
case 0x0c0c3314u: goto P_0c0c3314;
case 0x0c0c3316u: goto P_0c0c3316;
case 0x0c0c3318u: goto P_0c0c3318;
case 0x0c0c331au: goto P_0c0c331a;
case 0x0c0c3348u: goto P_0c0c3348;
case 0x0c0c334au: goto P_0c0c334a;
case 0x0c0c334cu: goto P_0c0c334c;
case 0x0c0c334eu: goto P_0c0c334e;
case 0x0c0c3350u: goto P_0c0c3350;
case 0x0c0c3352u: goto P_0c0c3352;
case 0x0c0c3354u: goto P_0c0c3354;
case 0x0c0c3356u: goto P_0c0c3356;
case 0x0c0c3358u: goto P_0c0c3358;
case 0x0c0c335au: goto P_0c0c335a;
case 0x0c0c335cu: goto P_0c0c335c;
case 0x0c0c335eu: goto P_0c0c335e;
case 0x0c0c3360u: goto P_0c0c3360;
case 0x0c0c3362u: goto P_0c0c3362;
case 0x0c0c3364u: goto P_0c0c3364;
case 0x0c0c3366u: goto P_0c0c3366;
case 0x0c0c3368u: goto P_0c0c3368;
case 0x0c0c336au: goto P_0c0c336a;
case 0x0c0c336cu: goto P_0c0c336c;
case 0x0c0c336eu: goto P_0c0c336e;
case 0x0c0c3370u: goto P_0c0c3370;
case 0x0c0c3372u: goto P_0c0c3372;
case 0x0c0c3374u: goto P_0c0c3374;
case 0x0c0c3376u: goto P_0c0c3376;
case 0x0c0c3378u: goto P_0c0c3378;
case 0x0c0c337au: goto P_0c0c337a;
case 0x0c0c337cu: goto P_0c0c337c;
case 0x0c0c337eu: goto P_0c0c337e;
case 0x0c0c3380u: goto P_0c0c3380;
case 0x0c0c3382u: goto P_0c0c3382;
case 0x0c0c3384u: goto P_0c0c3384;
case 0x0c0c3386u: goto P_0c0c3386;
case 0x0c0c3388u: goto P_0c0c3388;
case 0x0c0c338au: goto P_0c0c338a;
case 0x0c0c338cu: goto P_0c0c338c;
case 0x0c0c338eu: goto P_0c0c338e;
case 0x0c0c3390u: goto P_0c0c3390;
case 0x0c0c3392u: goto P_0c0c3392;
case 0x0c0c3394u: goto P_0c0c3394;
case 0x0c0c3396u: goto P_0c0c3396;
case 0x0c0c3398u: goto P_0c0c3398;
case 0x0c0c339au: goto P_0c0c339a;
case 0x0c0c339cu: goto P_0c0c339c;
case 0x0c0c339eu: goto P_0c0c339e;
case 0x0c0c33a0u: goto P_0c0c33a0;
case 0x0c0c33a2u: goto P_0c0c33a2;
case 0x0c0c33a4u: goto P_0c0c33a4;
case 0x0c0c33a6u: goto P_0c0c33a6;
case 0x0c0c33a8u: goto P_0c0c33a8;
case 0x0c0c33aau: goto P_0c0c33aa;
case 0x0c0c33acu: goto P_0c0c33ac;
case 0x0c0c33aeu: goto P_0c0c33ae;
case 0x0c0c33b0u: goto P_0c0c33b0;
case 0x0c0c33b2u: goto P_0c0c33b2;
case 0x0c0c33b4u: goto P_0c0c33b4;
case 0x0c0c33b6u: goto P_0c0c33b6;
case 0x0c0c33b8u: goto P_0c0c33b8;
case 0x0c0c33bau: goto P_0c0c33ba;
case 0x0c0c33bcu: goto P_0c0c33bc;
case 0x0c0c33beu: goto P_0c0c33be;
case 0x0c0c33c0u: goto P_0c0c33c0;
case 0x0c0c33c2u: goto P_0c0c33c2;
case 0x0c0c33c4u: goto P_0c0c33c4;
case 0x0c0c33c6u: goto P_0c0c33c6;
case 0x0c0c33c8u: goto P_0c0c33c8;
case 0x0c0c33cau: goto P_0c0c33ca;
case 0x0c0c33ccu: goto P_0c0c33cc;
case 0x0c0c33ceu: goto P_0c0c33ce;
case 0x0c0c33d0u: goto P_0c0c33d0;
case 0x0c0c33d2u: goto P_0c0c33d2;
case 0x0c0c33d4u: goto P_0c0c33d4;
case 0x0c0c33d6u: goto P_0c0c33d6;
case 0x0c0c33d8u: goto P_0c0c33d8;
case 0x0c0c33dau: goto P_0c0c33da;
case 0x0c0c33dcu: goto P_0c0c33dc;
case 0x0c0c33deu: goto P_0c0c33de;
case 0x0c0c33e0u: goto P_0c0c33e0;
case 0x0c0c33e2u: goto P_0c0c33e2;
case 0x0c0c33e4u: goto P_0c0c33e4;
case 0x0c0c33e6u: goto P_0c0c33e6;
case 0x0c0c33e8u: goto P_0c0c33e8;
case 0x0c0c33eau: goto P_0c0c33ea;
case 0x0c0c33ecu: goto P_0c0c33ec;
case 0x0c0c33eeu: goto P_0c0c33ee;
case 0x0c0c33f0u: goto P_0c0c33f0;
case 0x0c0c33f2u: goto P_0c0c33f2;
case 0x0c0c33f4u: goto P_0c0c33f4;
case 0x0c0c33f6u: goto P_0c0c33f6;
case 0x0c0c33f8u: goto P_0c0c33f8;
case 0x0c0c33fau: goto P_0c0c33fa;
case 0x0c0c33fcu: goto P_0c0c33fc;
case 0x0c0c33feu: goto P_0c0c33fe;
case 0x0c0c3400u: goto P_0c0c3400;
case 0x0c0c3402u: goto P_0c0c3402;
case 0x0c0c3404u: goto P_0c0c3404;
case 0x0c0c3406u: goto P_0c0c3406;
case 0x0c0c3408u: goto P_0c0c3408;
case 0x0c0c340au: goto P_0c0c340a;
case 0x0c0c340cu: goto P_0c0c340c;
case 0x0c0c340eu: goto P_0c0c340e;
case 0x0c0c3410u: goto P_0c0c3410;
case 0x0c0c3412u: goto P_0c0c3412;
case 0x0c0c3414u: goto P_0c0c3414;
case 0x0c0c3420u: goto P_0c0c3420;
case 0x0c0c3422u: goto P_0c0c3422;
case 0x0c0c3424u: goto P_0c0c3424;
case 0x0c0c3426u: goto P_0c0c3426;
case 0x0c0c3428u: goto P_0c0c3428;
case 0x0c0c342au: goto P_0c0c342a;
case 0x0c0c342cu: goto P_0c0c342c;
case 0x0c0c342eu: goto P_0c0c342e;
case 0x0c0c3430u: goto P_0c0c3430;
case 0x0c0c3432u: goto P_0c0c3432;
case 0x0c0c3434u: goto P_0c0c3434;
case 0x0c0c3436u: goto P_0c0c3436;
case 0x0c0c3438u: goto P_0c0c3438;
case 0x0c0c343au: goto P_0c0c343a;
case 0x0c0c343cu: goto P_0c0c343c;
case 0x0c0c343eu: goto P_0c0c343e;
case 0x0c0c3440u: goto P_0c0c3440;
case 0x0c0c3442u: goto P_0c0c3442;
case 0x0c0c3444u: goto P_0c0c3444;
case 0x0c0c3446u: goto P_0c0c3446;
case 0x0c0c3448u: goto P_0c0c3448;
case 0x0c0c344au: goto P_0c0c344a;
case 0x0c0c344cu: goto P_0c0c344c;
case 0x0c0c344eu: goto P_0c0c344e;
case 0x0c0c3450u: goto P_0c0c3450;
case 0x0c0c3452u: goto P_0c0c3452;
case 0x0c0c3454u: goto P_0c0c3454;
case 0x0c0c3456u: goto P_0c0c3456;
case 0x0c0c3458u: goto P_0c0c3458;
case 0x0c0c345au: goto P_0c0c345a;
case 0x0c0c345cu: goto P_0c0c345c;
case 0x0c0c345eu: goto P_0c0c345e;
case 0x0c0c3460u: goto P_0c0c3460;
case 0x0c0c3462u: goto P_0c0c3462;
case 0x0c0c3464u: goto P_0c0c3464;
case 0x0c0c3466u: goto P_0c0c3466;
case 0x0c0c3468u: goto P_0c0c3468;
case 0x0c0c346au: goto P_0c0c346a;
case 0x0c0c346cu: goto P_0c0c346c;
case 0x0c0c346eu: goto P_0c0c346e;
case 0x0c0c3470u: goto P_0c0c3470;
case 0x0c0c3472u: goto P_0c0c3472;
case 0x0c0c3474u: goto P_0c0c3474;
case 0x0c0c3476u: goto P_0c0c3476;
case 0x0c0c3478u: goto P_0c0c3478;
case 0x0c0c347au: goto P_0c0c347a;
case 0x0c0c347cu: goto P_0c0c347c;
case 0x0c0c347eu: goto P_0c0c347e;
case 0x0c0c3480u: goto P_0c0c3480;
case 0x0c0c3482u: goto P_0c0c3482;
case 0x0c0c3484u: goto P_0c0c3484;
case 0x0c0c3486u: goto P_0c0c3486;
case 0x0c0c3488u: goto P_0c0c3488;
case 0x0c0c348au: goto P_0c0c348a;
case 0x0c0c348cu: goto P_0c0c348c;
case 0x0c0c348eu: goto P_0c0c348e;
case 0x0c0c3490u: goto P_0c0c3490;
case 0x0c0c3492u: goto P_0c0c3492;
case 0x0c0c3494u: goto P_0c0c3494;
case 0x0c0c3496u: goto P_0c0c3496;
case 0x0c0c3498u: goto P_0c0c3498;
case 0x0c0c349au: goto P_0c0c349a;
case 0x0c0c349cu: goto P_0c0c349c;
case 0x0c0c349eu: goto P_0c0c349e;
case 0x0c0c34a0u: goto P_0c0c34a0;
case 0x0c0c34a2u: goto P_0c0c34a2;
case 0x0c0c34a4u: goto P_0c0c34a4;
case 0x0c0c34a6u: goto P_0c0c34a6;
case 0x0c0c34a8u: goto P_0c0c34a8;
case 0x0c0c34aau: goto P_0c0c34aa;
case 0x0c0c34acu: goto P_0c0c34ac;
case 0x0c0c34aeu: goto P_0c0c34ae;
case 0x0c0c34b0u: goto P_0c0c34b0;
case 0x0c0c34b2u: goto P_0c0c34b2;
case 0x0c0c34b4u: goto P_0c0c34b4;
case 0x0c0c34b6u: goto P_0c0c34b6;
case 0x0c0c34b8u: goto P_0c0c34b8;
case 0x0c0c34bau: goto P_0c0c34ba;
case 0x0c0c34bcu: goto P_0c0c34bc;
case 0x0c0c34beu: goto P_0c0c34be;
case 0x0c0c34c0u: goto P_0c0c34c0;
case 0x0c0c34c2u: goto P_0c0c34c2;
case 0x0c0c34c4u: goto P_0c0c34c4;
case 0x0c0c34c6u: goto P_0c0c34c6;
case 0x0c0c34c8u: goto P_0c0c34c8;
case 0x0c0c34cau: goto P_0c0c34ca;
case 0x0c0c34ccu: goto P_0c0c34cc;
case 0x0c0c34ceu: goto P_0c0c34ce;
case 0x0c0c34d0u: goto P_0c0c34d0;
case 0x0c0c34d2u: goto P_0c0c34d2;
case 0x0c0c34d4u: goto P_0c0c34d4;
case 0x0c0c34d6u: goto P_0c0c34d6;
case 0x0c0c34d8u: goto P_0c0c34d8;
case 0x0c0c34dau: goto P_0c0c34da;
case 0x0c0c34dcu: goto P_0c0c34dc;
case 0x0c0c34deu: goto P_0c0c34de;
case 0x0c0c34e0u: goto P_0c0c34e0;
case 0x0c0c34e2u: goto P_0c0c34e2;
case 0x0c0c34e4u: goto P_0c0c34e4;
case 0x0c0c34e6u: goto P_0c0c34e6;
case 0x0c0c34e8u: goto P_0c0c34e8;
case 0x0c0c34eau: goto P_0c0c34ea;
case 0x0c0c34ecu: goto P_0c0c34ec;
case 0x0c0c34eeu: goto P_0c0c34ee;
case 0x0c0c34f0u: goto P_0c0c34f0;
case 0x0c0c34f2u: goto P_0c0c34f2;
case 0x0c0c34f4u: goto P_0c0c34f4;
case 0x0c0c34f6u: goto P_0c0c34f6;
case 0x0c0c34f8u: goto P_0c0c34f8;
case 0x0c0c34fau: goto P_0c0c34fa;
case 0x0c0c34fcu: goto P_0c0c34fc;
case 0x0c0c34feu: goto P_0c0c34fe;
case 0x0c0c3500u: goto P_0c0c3500;
case 0x0c0c3502u: goto P_0c0c3502;
case 0x0c0c3504u: goto P_0c0c3504;
case 0x0c0c3506u: goto P_0c0c3506;
case 0x0c0c3508u: goto P_0c0c3508;
case 0x0c0c350au: goto P_0c0c350a;
case 0x0c0c350cu: goto P_0c0c350c;
case 0x0c0c350eu: goto P_0c0c350e;
case 0x0c0c3510u: goto P_0c0c3510;
case 0x0c0c3512u: goto P_0c0c3512;
case 0x0c0c3514u: goto P_0c0c3514;
case 0x0c0c3528u: goto P_0c0c3528;
case 0x0c0c352au: goto P_0c0c352a;
case 0x0c0c352cu: goto P_0c0c352c;
case 0x0c0c352eu: goto P_0c0c352e;
case 0x0c0c3530u: goto P_0c0c3530;
case 0x0c0c3532u: goto P_0c0c3532;
case 0x0c0c3534u: goto P_0c0c3534;
case 0x0c0c3536u: goto P_0c0c3536;
case 0x0c0c3538u: goto P_0c0c3538;
case 0x0c0c353au: goto P_0c0c353a;
case 0x0c0c353cu: goto P_0c0c353c;
case 0x0c0c353eu: goto P_0c0c353e;
case 0x0c0c3540u: goto P_0c0c3540;
case 0x0c0c3542u: goto P_0c0c3542;
case 0x0c0c3544u: goto P_0c0c3544;
case 0x0c0c3546u: goto P_0c0c3546;
case 0x0c0c3548u: goto P_0c0c3548;
case 0x0c0c354au: goto P_0c0c354a;
case 0x0c0c354cu: goto P_0c0c354c;
case 0x0c0c354eu: goto P_0c0c354e;
case 0x0c0c3550u: goto P_0c0c3550;
case 0x0c0c3552u: goto P_0c0c3552;
case 0x0c0c3554u: goto P_0c0c3554;
case 0x0c0c3556u: goto P_0c0c3556;
case 0x0c0c3558u: goto P_0c0c3558;
case 0x0c0c355au: goto P_0c0c355a;
case 0x0c0c355cu: goto P_0c0c355c;
case 0x0c0c355eu: goto P_0c0c355e;
case 0x0c0c3560u: goto P_0c0c3560;
case 0x0c0c3562u: goto P_0c0c3562;
case 0x0c0c3564u: goto P_0c0c3564;
case 0x0c0c3566u: goto P_0c0c3566;
case 0x0c0c3568u: goto P_0c0c3568;
case 0x0c0c356au: goto P_0c0c356a;
case 0x0c0c356cu: goto P_0c0c356c;
case 0x0c0c356eu: goto P_0c0c356e;
case 0x0c0c3570u: goto P_0c0c3570;
case 0x0c0c3572u: goto P_0c0c3572;
case 0x0c0c3574u: goto P_0c0c3574;
case 0x0c0c3576u: goto P_0c0c3576;
case 0x0c0c3578u: goto P_0c0c3578;
case 0x0c0c357au: goto P_0c0c357a;
case 0x0c0c357cu: goto P_0c0c357c;
case 0x0c0c357eu: goto P_0c0c357e;
case 0x0c0c3580u: goto P_0c0c3580;
case 0x0c0c3582u: goto P_0c0c3582;
case 0x0c0c3584u: goto P_0c0c3584;
case 0x0c0c3586u: goto P_0c0c3586;
case 0x0c0c3588u: goto P_0c0c3588;
case 0x0c0c358au: goto P_0c0c358a;
case 0x0c0c358cu: goto P_0c0c358c;
case 0x0c0c358eu: goto P_0c0c358e;
case 0x0c0c3590u: goto P_0c0c3590;
case 0x0c0c3592u: goto P_0c0c3592;
case 0x0c0c3594u: goto P_0c0c3594;
case 0x0c0c3596u: goto P_0c0c3596;
case 0x0c0c3598u: goto P_0c0c3598;
case 0x0c0c359au: goto P_0c0c359a;
case 0x0c0c359cu: goto P_0c0c359c;
case 0x0c0c359eu: goto P_0c0c359e;
case 0x0c0c35a0u: goto P_0c0c35a0;
case 0x0c0c35a2u: goto P_0c0c35a2;
case 0x0c0c35a4u: goto P_0c0c35a4;
case 0x0c0c35a6u: goto P_0c0c35a6;
case 0x0c0c35a8u: goto P_0c0c35a8;
case 0x0c0c35aau: goto P_0c0c35aa;
case 0x0c0c35acu: goto P_0c0c35ac;
case 0x0c0c35aeu: goto P_0c0c35ae;
case 0x0c0c35b0u: goto P_0c0c35b0;
case 0x0c0c35b2u: goto P_0c0c35b2;
case 0x0c0c35b4u: goto P_0c0c35b4;
case 0x0c0c35b6u: goto P_0c0c35b6;
case 0x0c0c35b8u: goto P_0c0c35b8;
case 0x0c0c35bau: goto P_0c0c35ba;
case 0x0c0c35bcu: goto P_0c0c35bc;
case 0x0c0c35beu: goto P_0c0c35be;
case 0x0c0c35c0u: goto P_0c0c35c0;
case 0x0c0c35c2u: goto P_0c0c35c2;
case 0x0c0c35c4u: goto P_0c0c35c4;
case 0x0c0c35c6u: goto P_0c0c35c6;
case 0x0c0c35c8u: goto P_0c0c35c8;
case 0x0c0c35cau: goto P_0c0c35ca;
case 0x0c0c35ccu: goto P_0c0c35cc;
case 0x0c0c35ceu: goto P_0c0c35ce;
case 0x0c0c35d0u: goto P_0c0c35d0;
case 0x0c0c35d2u: goto P_0c0c35d2;
case 0x0c0c35d4u: goto P_0c0c35d4;
case 0x0c0c35d6u: goto P_0c0c35d6;
case 0x0c0c35d8u: goto P_0c0c35d8;
case 0x0c0c35dau: goto P_0c0c35da;
case 0x0c0c35dcu: goto P_0c0c35dc;
case 0x0c0c35deu: goto P_0c0c35de;
case 0x0c0c35e0u: goto P_0c0c35e0;
case 0x0c0c35e2u: goto P_0c0c35e2;
case 0x0c0c35e4u: goto P_0c0c35e4;
case 0x0c0c35e6u: goto P_0c0c35e6;
case 0x0c0c35e8u: goto P_0c0c35e8;
case 0x0c0c35eau: goto P_0c0c35ea;
case 0x0c0c35ecu: goto P_0c0c35ec;
case 0x0c0c35eeu: goto P_0c0c35ee;
case 0x0c0c35f0u: goto P_0c0c35f0;
case 0x0c0c35f2u: goto P_0c0c35f2;
case 0x0c0c35f4u: goto P_0c0c35f4;
case 0x0c0c35f6u: goto P_0c0c35f6;
case 0x0c0c35f8u: goto P_0c0c35f8;
case 0x0c0c35fau: goto P_0c0c35fa;
case 0x0c0c3610u: goto P_0c0c3610;
case 0x0c0c3612u: goto P_0c0c3612;
case 0x0c0c3614u: goto P_0c0c3614;
case 0x0c0c3616u: goto P_0c0c3616;
case 0x0c0c3618u: goto P_0c0c3618;
case 0x0c0c361au: goto P_0c0c361a;
case 0x0c0c361cu: goto P_0c0c361c;
case 0x0c0c361eu: goto P_0c0c361e;
case 0x0c0c3620u: goto P_0c0c3620;
case 0x0c0c3622u: goto P_0c0c3622;
case 0x0c0c3624u: goto P_0c0c3624;
case 0x0c0c3626u: goto P_0c0c3626;
case 0x0c0c3628u: goto P_0c0c3628;
case 0x0c0c362au: goto P_0c0c362a;
case 0x0c0c362cu: goto P_0c0c362c;
case 0x0c0c362eu: goto P_0c0c362e;
case 0x0c0c3630u: goto P_0c0c3630;
case 0x0c0c3632u: goto P_0c0c3632;
case 0x0c0c3634u: goto P_0c0c3634;
case 0x0c0c3636u: goto P_0c0c3636;
case 0x0c0c3638u: goto P_0c0c3638;
case 0x0c0c363au: goto P_0c0c363a;
case 0x0c0c363cu: goto P_0c0c363c;
case 0x0c0c363eu: goto P_0c0c363e;
case 0x0c0c3640u: goto P_0c0c3640;
case 0x0c0c3642u: goto P_0c0c3642;
case 0x0c0c3644u: goto P_0c0c3644;
case 0x0c0c3646u: goto P_0c0c3646;
case 0x0c0c3648u: goto P_0c0c3648;
case 0x0c0c364au: goto P_0c0c364a;
case 0x0c0c364cu: goto P_0c0c364c;
case 0x0c0c364eu: goto P_0c0c364e;
case 0x0c0c3650u: goto P_0c0c3650;
case 0x0c0c3652u: goto P_0c0c3652;
case 0x0c0c3654u: goto P_0c0c3654;
case 0x0c0c3656u: goto P_0c0c3656;
case 0x0c0c3658u: goto P_0c0c3658;
case 0x0c0c365au: goto P_0c0c365a;
case 0x0c0c365cu: goto P_0c0c365c;
case 0x0c0c365eu: goto P_0c0c365e;
case 0x0c0c3660u: goto P_0c0c3660;
case 0x0c0c3662u: goto P_0c0c3662;
case 0x0c0c3664u: goto P_0c0c3664;
case 0x0c0c3666u: goto P_0c0c3666;
case 0x0c0c3668u: goto P_0c0c3668;
case 0x0c0c366au: goto P_0c0c366a;
case 0x0c0c366cu: goto P_0c0c366c;
case 0x0c0c366eu: goto P_0c0c366e;
case 0x0c0c3670u: goto P_0c0c3670;
case 0x0c0c3672u: goto P_0c0c3672;
case 0x0c0c3674u: goto P_0c0c3674;
case 0x0c0c3676u: goto P_0c0c3676;
case 0x0c0c3678u: goto P_0c0c3678;
case 0x0c0c367au: goto P_0c0c367a;
case 0x0c0c367cu: goto P_0c0c367c;
case 0x0c0c367eu: goto P_0c0c367e;
case 0x0c0c3680u: goto P_0c0c3680;
case 0x0c0c3682u: goto P_0c0c3682;
case 0x0c0c3684u: goto P_0c0c3684;
case 0x0c0c3686u: goto P_0c0c3686;
case 0x0c0c3688u: goto P_0c0c3688;
case 0x0c0c368au: goto P_0c0c368a;
case 0x0c0c368cu: goto P_0c0c368c;
case 0x0c0c368eu: goto P_0c0c368e;
case 0x0c0c3690u: goto P_0c0c3690;
case 0x0c0c3692u: goto P_0c0c3692;
case 0x0c0c3694u: goto P_0c0c3694;
case 0x0c0c3696u: goto P_0c0c3696;
case 0x0c0c3698u: goto P_0c0c3698;
case 0x0c0c369au: goto P_0c0c369a;
case 0x0c0c369cu: goto P_0c0c369c;
case 0x0c0c369eu: goto P_0c0c369e;
case 0x0c0c36a0u: goto P_0c0c36a0;
case 0x0c0c36a2u: goto P_0c0c36a2;
case 0x0c0c36a4u: goto P_0c0c36a4;
case 0x0c0c36a6u: goto P_0c0c36a6;
case 0x0c0c36a8u: goto P_0c0c36a8;
case 0x0c0c36aau: goto P_0c0c36aa;
case 0x0c0c36acu: goto P_0c0c36ac;
case 0x0c0c36aeu: goto P_0c0c36ae;
case 0x0c0c36b0u: goto P_0c0c36b0;
case 0x0c0c36b2u: goto P_0c0c36b2;
case 0x0c0c36b4u: goto P_0c0c36b4;
case 0x0c0c36b6u: goto P_0c0c36b6;
case 0x0c0c36b8u: goto P_0c0c36b8;
case 0x0c0c36bau: goto P_0c0c36ba;
case 0x0c0c36bcu: goto P_0c0c36bc;
case 0x0c0c36beu: goto P_0c0c36be;
case 0x0c0c36c0u: goto P_0c0c36c0;
case 0x0c0c36c2u: goto P_0c0c36c2;
case 0x0c0c36c4u: goto P_0c0c36c4;
case 0x0c0c36c6u: goto P_0c0c36c6;
case 0x0c0c36c8u: goto P_0c0c36c8;
case 0x0c0c36cau: goto P_0c0c36ca;
case 0x0c0c36ccu: goto P_0c0c36cc;
case 0x0c0c36ceu: goto P_0c0c36ce;
case 0x0c0c36d0u: goto P_0c0c36d0;
case 0x0c0c36d2u: goto P_0c0c36d2;
case 0x0c0c36d4u: goto P_0c0c36d4;
case 0x0c0c36d6u: goto P_0c0c36d6;
case 0x0c0c36d8u: goto P_0c0c36d8;
case 0x0c0c36dau: goto P_0c0c36da;
case 0x0c0c36dcu: goto P_0c0c36dc;
case 0x0c0c36deu: goto P_0c0c36de;
case 0x0c0c36e0u: goto P_0c0c36e0;
case 0x0c0c36e2u: goto P_0c0c36e2;
case 0x0c0c36e4u: goto P_0c0c36e4;
case 0x0c0c36e6u: goto P_0c0c36e6;
case 0x0c0c36e8u: goto P_0c0c36e8;
case 0x0c0c36eau: goto P_0c0c36ea;
case 0x0c0c36ecu: goto P_0c0c36ec;
case 0x0c0c36eeu: goto P_0c0c36ee;
case 0x0c0c36f0u: goto P_0c0c36f0;
case 0x0c0c36f2u: goto P_0c0c36f2;
case 0x0c0c36f4u: goto P_0c0c36f4;
case 0x0c0c36f6u: goto P_0c0c36f6;
case 0x0c0c36f8u: goto P_0c0c36f8;
case 0x0c0c36fau: goto P_0c0c36fa;
case 0x0c0c36fcu: goto P_0c0c36fc;
case 0x0c0c3714u: goto P_0c0c3714;
case 0x0c0c3716u: goto P_0c0c3716;
case 0x0c0c3718u: goto P_0c0c3718;
case 0x0c0c371au: goto P_0c0c371a;
case 0x0c0c371cu: goto P_0c0c371c;
case 0x0c0c371eu: goto P_0c0c371e;
case 0x0c0c3720u: goto P_0c0c3720;
case 0x0c0c3722u: goto P_0c0c3722;
case 0x0c0c3724u: goto P_0c0c3724;
case 0x0c0c3726u: goto P_0c0c3726;
case 0x0c0c3728u: goto P_0c0c3728;
case 0x0c0c372au: goto P_0c0c372a;
case 0x0c0c372cu: goto P_0c0c372c;
case 0x0c0c372eu: goto P_0c0c372e;
case 0x0c0c3730u: goto P_0c0c3730;
case 0x0c0c3732u: goto P_0c0c3732;
case 0x0c0c3734u: goto P_0c0c3734;
case 0x0c0c3736u: goto P_0c0c3736;
case 0x0c0c3738u: goto P_0c0c3738;
case 0x0c0c373au: goto P_0c0c373a;
case 0x0c0c373cu: goto P_0c0c373c;
case 0x0c0c373eu: goto P_0c0c373e;
case 0x0c0c3740u: goto P_0c0c3740;
case 0x0c0c3742u: goto P_0c0c3742;
case 0x0c0c3744u: goto P_0c0c3744;
case 0x0c0c3746u: goto P_0c0c3746;
case 0x0c0c3748u: goto P_0c0c3748;
case 0x0c0c374au: goto P_0c0c374a;
case 0x0c0c374cu: goto P_0c0c374c;
case 0x0c0c374eu: goto P_0c0c374e;
case 0x0c0c3750u: goto P_0c0c3750;
case 0x0c0c3752u: goto P_0c0c3752;
case 0x0c0c3754u: goto P_0c0c3754;
case 0x0c0c3756u: goto P_0c0c3756;
case 0x0c0c3758u: goto P_0c0c3758;
case 0x0c0c375au: goto P_0c0c375a;
case 0x0c0c375cu: goto P_0c0c375c;
case 0x0c0c375eu: goto P_0c0c375e;
case 0x0c0c3760u: goto P_0c0c3760;
case 0x0c0c3762u: goto P_0c0c3762;
case 0x0c0c3764u: goto P_0c0c3764;
case 0x0c0c3766u: goto P_0c0c3766;
case 0x0c0c3768u: goto P_0c0c3768;
case 0x0c0c376au: goto P_0c0c376a;
case 0x0c0c376cu: goto P_0c0c376c;
case 0x0c0c376eu: goto P_0c0c376e;
case 0x0c0c3770u: goto P_0c0c3770;
case 0x0c0c3772u: goto P_0c0c3772;
case 0x0c0c3774u: goto P_0c0c3774;
case 0x0c0c3776u: goto P_0c0c3776;
case 0x0c0c3778u: goto P_0c0c3778;
case 0x0c0c377au: goto P_0c0c377a;
case 0x0c0c377cu: goto P_0c0c377c;
case 0x0c0c377eu: goto P_0c0c377e;
case 0x0c0c3780u: goto P_0c0c3780;
case 0x0c0c3782u: goto P_0c0c3782;
case 0x0c0c3784u: goto P_0c0c3784;
case 0x0c0c3786u: goto P_0c0c3786;
case 0x0c0c3788u: goto P_0c0c3788;
case 0x0c0c378au: goto P_0c0c378a;
case 0x0c0c378cu: goto P_0c0c378c;
case 0x0c0c378eu: goto P_0c0c378e;
case 0x0c0c3790u: goto P_0c0c3790;
case 0x0c0c3792u: goto P_0c0c3792;
case 0x0c0c3794u: goto P_0c0c3794;
case 0x0c0c3796u: goto P_0c0c3796;
case 0x0c0c3798u: goto P_0c0c3798;
case 0x0c0c379au: goto P_0c0c379a;
case 0x0c0c379cu: goto P_0c0c379c;
case 0x0c0c379eu: goto P_0c0c379e;
case 0x0c0c37a0u: goto P_0c0c37a0;
case 0x0c0c37a2u: goto P_0c0c37a2;
case 0x0c0c37a4u: goto P_0c0c37a4;
case 0x0c0c37a6u: goto P_0c0c37a6;
case 0x0c0c37a8u: goto P_0c0c37a8;
case 0x0c0c37aau: goto P_0c0c37aa;
case 0x0c0c37acu: goto P_0c0c37ac;
case 0x0c0c37aeu: goto P_0c0c37ae;
case 0x0c0c37b0u: goto P_0c0c37b0;
case 0x0c0c37b2u: goto P_0c0c37b2;
case 0x0c0c37b4u: goto P_0c0c37b4;
case 0x0c0c37b6u: goto P_0c0c37b6;
case 0x0c0c37b8u: goto P_0c0c37b8;
case 0x0c0c37bau: goto P_0c0c37ba;
case 0x0c0c37bcu: goto P_0c0c37bc;
case 0x0c0c37beu: goto P_0c0c37be;
case 0x0c0c37c0u: goto P_0c0c37c0;
case 0x0c0c37c2u: goto P_0c0c37c2;
case 0x0c0c37c4u: goto P_0c0c37c4;
case 0x0c0c37c6u: goto P_0c0c37c6;
case 0x0c0c37c8u: goto P_0c0c37c8;
case 0x0c0c37cau: goto P_0c0c37ca;
case 0x0c0c37ccu: goto P_0c0c37cc;
case 0x0c0c37ceu: goto P_0c0c37ce;
case 0x0c0c37d0u: goto P_0c0c37d0;
case 0x0c0c37d2u: goto P_0c0c37d2;
case 0x0c0c37d4u: goto P_0c0c37d4;
case 0x0c0c37d6u: goto P_0c0c37d6;
case 0x0c0c37d8u: goto P_0c0c37d8;
case 0x0c0c37dau: goto P_0c0c37da;
case 0x0c0c37dcu: goto P_0c0c37dc;
case 0x0c0c37deu: goto P_0c0c37de;
case 0x0c0c37e0u: goto P_0c0c37e0;
case 0x0c0c37e2u: goto P_0c0c37e2;
case 0x0c0c37e4u: goto P_0c0c37e4;
case 0x0c0c37e6u: goto P_0c0c37e6;
case 0x0c0c37e8u: goto P_0c0c37e8;
case 0x0c0c37eau: goto P_0c0c37ea;
case 0x0c0c37ecu: goto P_0c0c37ec;
case 0x0c0c37eeu: goto P_0c0c37ee;
case 0x0c0c37f0u: goto P_0c0c37f0;
case 0x0c0c37f2u: goto P_0c0c37f2;
case 0x0c0c37f4u: goto P_0c0c37f4;
case 0x0c0c37f6u: goto P_0c0c37f6;
case 0x0c0c37f8u: goto P_0c0c37f8;
case 0x0c0c37fau: goto P_0c0c37fa;
case 0x0c0c37fcu: goto P_0c0c37fc;
case 0x0c0c37feu: goto P_0c0c37fe;
case 0x0c0c3800u: goto P_0c0c3800;
case 0x0c0c3802u: goto P_0c0c3802;
case 0x0c0c3804u: goto P_0c0c3804;
case 0x0c0c3806u: goto P_0c0c3806;
case 0x0c0c3808u: goto P_0c0c3808;
case 0x0c0c380au: goto P_0c0c380a;
case 0x0c0c380cu: goto P_0c0c380c;
case 0x0c0c380eu: goto P_0c0c380e;
case 0x0c0c3810u: goto P_0c0c3810;
case 0x0c0c3812u: goto P_0c0c3812;
case 0x0c0c3814u: goto P_0c0c3814;
case 0x0c0c3816u: goto P_0c0c3816;
case 0x0c0c3818u: goto P_0c0c3818;
case 0x0c0c381au: goto P_0c0c381a;
case 0x0c0c381cu: goto P_0c0c381c;
case 0x0c0c381eu: goto P_0c0c381e;
case 0x0c0c3820u: goto P_0c0c3820;
case 0x0c0c3822u: goto P_0c0c3822;
case 0x0c0c3824u: goto P_0c0c3824;
case 0x0c0c3826u: goto P_0c0c3826;
case 0x0c0c3838u: goto P_0c0c3838;
case 0x0c0c383au: goto P_0c0c383a;
case 0x0c0c383cu: goto P_0c0c383c;
case 0x0c0c383eu: goto P_0c0c383e;
case 0x0c0c3840u: goto P_0c0c3840;
case 0x0c0c3842u: goto P_0c0c3842;
case 0x0c0c3844u: goto P_0c0c3844;
case 0x0c0c3846u: goto P_0c0c3846;
case 0x0c0c3848u: goto P_0c0c3848;
case 0x0c0c384au: goto P_0c0c384a;
case 0x0c0c384cu: goto P_0c0c384c;
case 0x0c0c384eu: goto P_0c0c384e;
case 0x0c0c3850u: goto P_0c0c3850;
case 0x0c0c3852u: goto P_0c0c3852;
case 0x0c0c3854u: goto P_0c0c3854;
case 0x0c0c3856u: goto P_0c0c3856;
case 0x0c0c3858u: goto P_0c0c3858;
case 0x0c0c385au: goto P_0c0c385a;
case 0x0c0c385cu: goto P_0c0c385c;
case 0x0c0c385eu: goto P_0c0c385e;
case 0x0c0c3860u: goto P_0c0c3860;
case 0x0c0c3862u: goto P_0c0c3862;
case 0x0c0c3864u: goto P_0c0c3864;
case 0x0c0c3866u: goto P_0c0c3866;
case 0x0c0c3868u: goto P_0c0c3868;
case 0x0c0c386au: goto P_0c0c386a;
case 0x0c0c386cu: goto P_0c0c386c;
case 0x0c0c386eu: goto P_0c0c386e;
case 0x0c0c3870u: goto P_0c0c3870;
case 0x0c0c3872u: goto P_0c0c3872;
case 0x0c0c3874u: goto P_0c0c3874;
case 0x0c0c3876u: goto P_0c0c3876;
case 0x0c0c3878u: goto P_0c0c3878;
case 0x0c0c387au: goto P_0c0c387a;
case 0x0c0c387cu: goto P_0c0c387c;
case 0x0c0c387eu: goto P_0c0c387e;
case 0x0c0c3880u: goto P_0c0c3880;
case 0x0c0c3882u: goto P_0c0c3882;
case 0x0c0c3884u: goto P_0c0c3884;
case 0x0c0c3886u: goto P_0c0c3886;
case 0x0c0c3888u: goto P_0c0c3888;
case 0x0c0c388au: goto P_0c0c388a;
case 0x0c0c388cu: goto P_0c0c388c;
case 0x0c0c388eu: goto P_0c0c388e;
case 0x0c0c3890u: goto P_0c0c3890;
case 0x0c0c3892u: goto P_0c0c3892;
case 0x0c0c3894u: goto P_0c0c3894;
case 0x0c0c3896u: goto P_0c0c3896;
case 0x0c0c3898u: goto P_0c0c3898;
case 0x0c0c389au: goto P_0c0c389a;
case 0x0c0c389cu: goto P_0c0c389c;
case 0x0c0c389eu: goto P_0c0c389e;
case 0x0c0c38a0u: goto P_0c0c38a0;
case 0x0c0c38a2u: goto P_0c0c38a2;
case 0x0c0c38a4u: goto P_0c0c38a4;
case 0x0c0c38a6u: goto P_0c0c38a6;
case 0x0c0c38a8u: goto P_0c0c38a8;
case 0x0c0c38aau: goto P_0c0c38aa;
case 0x0c0c38acu: goto P_0c0c38ac;
case 0x0c0c38aeu: goto P_0c0c38ae;
case 0x0c0c38b0u: goto P_0c0c38b0;
case 0x0c0c38b2u: goto P_0c0c38b2;
case 0x0c0c38b4u: goto P_0c0c38b4;
case 0x0c0c38b6u: goto P_0c0c38b6;
case 0x0c0c38b8u: goto P_0c0c38b8;
case 0x0c0c38bau: goto P_0c0c38ba;
case 0x0c0c38bcu: goto P_0c0c38bc;
case 0x0c0c38beu: goto P_0c0c38be;
case 0x0c0c38c0u: goto P_0c0c38c0;
case 0x0c0c38c2u: goto P_0c0c38c2;
case 0x0c0c38c4u: goto P_0c0c38c4;
case 0x0c0c4b7eu: goto P_0c0c4b7e;
case 0x0c0c4b80u: goto P_0c0c4b80;
case 0x0c0c4b82u: goto P_0c0c4b82;
case 0x0c0c4b84u: goto P_0c0c4b84;
case 0x0c0c4b86u: goto P_0c0c4b86;
case 0x0c0c4b88u: goto P_0c0c4b88;
case 0x0c0c4b8au: goto P_0c0c4b8a;
case 0x0c0c4b8cu: goto P_0c0c4b8c;
case 0x0c0c4b8eu: goto P_0c0c4b8e;
case 0x0c0c4c60u: goto P_0c0c4c60;
case 0x0c0c4c62u: goto P_0c0c4c62;
case 0x0c0c4c64u: goto P_0c0c4c64;
case 0x0c0c4c66u: goto P_0c0c4c66;
case 0x0c0c4c68u: goto P_0c0c4c68;
case 0x0c0c4c6au: goto P_0c0c4c6a;
case 0x0c0c4c6cu: goto P_0c0c4c6c;
case 0x0c0c4c6eu: goto P_0c0c4c6e;
case 0x0c0c4c70u: goto P_0c0c4c70;
case 0x0c0c4c72u: goto P_0c0c4c72;
case 0x0c0c4c74u: goto P_0c0c4c74;
case 0x0c0c4c76u: goto P_0c0c4c76;
case 0x0c0c4c78u: goto P_0c0c4c78;
case 0x0c0c4c7au: goto P_0c0c4c7a;
case 0x0c0c4c7cu: goto P_0c0c4c7c;
case 0x0c0c4c7eu: goto P_0c0c4c7e;
case 0x0c0c4c80u: goto P_0c0c4c80;
case 0x0c0c4c82u: goto P_0c0c4c82;
case 0x0c0c4c84u: goto P_0c0c4c84;
case 0x0c0c4c86u: goto P_0c0c4c86;
case 0x0c0c4c88u: goto P_0c0c4c88;
case 0x0c0c4c8au: goto P_0c0c4c8a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07abf8: /* original 4f22, guest PC 0x0c07abf8 */
if(!s->budget--) { s->failed_pc=0x0c07abf8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07abfa;
P_0c07abfa: /* original dc3c, guest PC 0x0c07abfa */
if(!s->budget--) { s->failed_pc=0x0c07abfau; return 0; }
r[12]=read(ram,0x0c07acecu,4);
goto P_0c07abfc;
P_0c07abfc: /* original da3a, guest PC 0x0c07abfc */
if(!s->budget--) { s->failed_pc=0x0c07abfcu; return 0; }
r[10]=read(ram,0x0c07ace8u,4);
goto P_0c07abfe;
P_0c07abfe: /* original 64ed, guest PC 0x0c07abfe */
if(!s->budget--) { s->failed_pc=0x0c07abfeu; return 0; }
r[4]=r[14]&65535u;
goto P_0c07ac00;
P_0c07ac00: /* original 4400, guest PC 0x0c07ac00 */
if(!s->budget--) { s->failed_pc=0x0c07ac00u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07ac02;
P_0c07ac02: /* original 34ac, guest PC 0x0c07ac02 */
if(!s->budget--) { s->failed_pc=0x0c07ac02u; return 0; }
r[4]+=r[10];
goto P_0c07ac04;
P_0c07ac04: /* original 6341, guest PC 0x0c07ac04 */
if(!s->budget--) { s->failed_pc=0x0c07ac04u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07ac06;
P_0c07ac06: /* original 633d, guest PC 0x0c07ac06 */
if(!s->budget--) { s->failed_pc=0x0c07ac06u; return 0; }
r[3]=r[3]&65535u;
goto P_0c07ac08;
P_0c07ac08: /* original 33c0, guest PC 0x0c07ac08 */
if(!s->budget--) { s->failed_pc=0x0c07ac08u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[12])!=0);
goto P_0c07ac0a;
P_0c07ac0a: /* original 8b00, guest PC 0x0c07ac0a */
if(!s->budget--) { s->failed_pc=0x0c07ac0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ac0e; }
goto P_0c07ac0c;
P_0c07ac0c: /* original 24d1, guest PC 0x0c07ac0c */
if(!s->budget--) { s->failed_pc=0x0c07ac0cu; return 0; }
write(ram,r[4],r[13],2);
goto P_0c07ac0e;
P_0c07ac0e: /* original b4ef, guest PC 0x0c07ac0e */
if(!s->budget--) { s->failed_pc=0x0c07ac0eu; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ac12u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ac12u) { target=s->pc; goto dispatch; }
goto P_0c07ac12;
P_0c07ac10: /* original 64e3, guest PC 0x0c07ac10 */
if(!s->budget--) { s->failed_pc=0x0c07ac10u; return 0; }
r[4]=r[14];
goto P_0c07ac12;
P_0c07ac12: /* original 7e01, guest PC 0x0c07ac12 */
if(!s->budget--) { s->failed_pc=0x0c07ac12u; return 0; }
r[14]+=0x00000001u;
goto P_0c07ac14;
P_0c07ac14: /* original 62ed, guest PC 0x0c07ac14 */
if(!s->budget--) { s->failed_pc=0x0c07ac14u; return 0; }
r[2]=r[14]&65535u;
goto P_0c07ac16;
P_0c07ac16: /* original 32b7, guest PC 0x0c07ac16 */
if(!s->budget--) { s->failed_pc=0x0c07ac16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[11])!=0);
goto P_0c07ac18;
P_0c07ac18: /* original 8bf1, guest PC 0x0c07ac18 */
if(!s->budget--) { s->failed_pc=0x0c07ac18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07abfe; }
goto P_0c07ac1a;
P_0c07ac1a: /* original 4f26, guest PC 0x0c07ac1a */
if(!s->budget--) { s->failed_pc=0x0c07ac1au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ac1c;
P_0c07ac1c: /* original 6af6, guest PC 0x0c07ac1c */
if(!s->budget--) { s->failed_pc=0x0c07ac1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07ac1e;
P_0c07ac1e: /* original 6bf6, guest PC 0x0c07ac1e */
if(!s->budget--) { s->failed_pc=0x0c07ac1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07ac20;
P_0c07ac20: /* original 6cf6, guest PC 0x0c07ac20 */
if(!s->budget--) { s->failed_pc=0x0c07ac20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ac22;
P_0c07ac22: /* original 6df6, guest PC 0x0c07ac22 */
if(!s->budget--) { s->failed_pc=0x0c07ac22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ac24;
P_0c07ac24: /* original 000b, guest PC 0x0c07ac24 */
if(!s->budget--) { s->failed_pc=0x0c07ac24u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ac26: /* original 6ef6, guest PC 0x0c07ac26 */
if(!s->budget--) { s->failed_pc=0x0c07ac26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ac28u,s,ram);
P_0c09befc: /* original 6242, guest PC 0x0c09befc */
if(!s->budget--) { s->failed_pc=0x0c09befcu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09befe;
P_0c09befe: /* original 5341, guest PC 0x0c09befe */
if(!s->budget--) { s->failed_pc=0x0c09befeu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09bf00;
P_0c09bf00: /* original 5142, guest PC 0x0c09bf00 */
if(!s->budget--) { s->failed_pc=0x0c09bf00u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c09bf02;
P_0c09bf02: /* original 2239, guest PC 0x0c09bf02 */
if(!s->budget--) { s->failed_pc=0x0c09bf02u; return 0; }
r[2]&=r[3];
goto P_0c09bf04;
P_0c09bf04: /* original 2219, guest PC 0x0c09bf04 */
if(!s->budget--) { s->failed_pc=0x0c09bf04u; return 0; }
r[2]&=r[1];
goto P_0c09bf06;
P_0c09bf06: /* original 2258, guest PC 0x0c09bf06 */
if(!s->budget--) { s->failed_pc=0x0c09bf06u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf08;
P_0c09bf08: /* original 8902, guest PC 0x0c09bf08 */
if(!s->budget--) { s->failed_pc=0x0c09bf08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf10; }
goto P_0c09bf0a;
P_0c09bf0a: /* original 9044, guest PC 0x0c09bf0a */
if(!s->budget--) { s->failed_pc=0x0c09bf0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf96u,2);
goto P_0c09bf0c;
P_0c09bf0c: /* original 000b, guest PC 0x0c09bf0c */
if(!s->budget--) { s->failed_pc=0x0c09bf0cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf0e: /* original 0009, guest PC 0x0c09bf0e */
if(!s->budget--) { s->failed_pc=0x0c09bf0eu; return 0; }
goto P_0c09bf10;
P_0c09bf10: /* original 6242, guest PC 0x0c09bf10 */
if(!s->budget--) { s->failed_pc=0x0c09bf10u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf12;
P_0c09bf12: /* original 5342, guest PC 0x0c09bf12 */
if(!s->budget--) { s->failed_pc=0x0c09bf12u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09bf14;
P_0c09bf14: /* original 2239, guest PC 0x0c09bf14 */
if(!s->budget--) { s->failed_pc=0x0c09bf14u; return 0; }
r[2]&=r[3];
goto P_0c09bf16;
P_0c09bf16: /* original 2258, guest PC 0x0c09bf16 */
if(!s->budget--) { s->failed_pc=0x0c09bf16u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf18;
P_0c09bf18: /* original 8901, guest PC 0x0c09bf18 */
if(!s->budget--) { s->failed_pc=0x0c09bf18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf1e; }
goto P_0c09bf1a;
P_0c09bf1a: /* original 000b, guest PC 0x0c09bf1a */
if(!s->budget--) { s->failed_pc=0x0c09bf1au; return 0; }
target=r[16];
r[0]=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c09bf1c: /* original e020, guest PC 0x0c09bf1c */
if(!s->budget--) { s->failed_pc=0x0c09bf1cu; return 0; }
r[0]=0x00000020u;
goto P_0c09bf1e;
P_0c09bf1e: /* original 6242, guest PC 0x0c09bf1e */
if(!s->budget--) { s->failed_pc=0x0c09bf1eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf20;
P_0c09bf20: /* original 5343, guest PC 0x0c09bf20 */
if(!s->budget--) { s->failed_pc=0x0c09bf20u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c09bf22;
P_0c09bf22: /* original 2239, guest PC 0x0c09bf22 */
if(!s->budget--) { s->failed_pc=0x0c09bf22u; return 0; }
r[2]&=r[3];
goto P_0c09bf24;
P_0c09bf24: /* original 2258, guest PC 0x0c09bf24 */
if(!s->budget--) { s->failed_pc=0x0c09bf24u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf26;
P_0c09bf26: /* original 8901, guest PC 0x0c09bf26 */
if(!s->budget--) { s->failed_pc=0x0c09bf26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf2c; }
goto P_0c09bf28;
P_0c09bf28: /* original 000b, guest PC 0x0c09bf28 */
if(!s->budget--) { s->failed_pc=0x0c09bf28u; return 0; }
target=r[16];
r[0]=0x00000040u;
s->pc=target; return ram->oob==0;
P_0c09bf2a: /* original e040, guest PC 0x0c09bf2a */
if(!s->budget--) { s->failed_pc=0x0c09bf2au; return 0; }
r[0]=0x00000040u;
goto P_0c09bf2c;
P_0c09bf2c: /* original 5241, guest PC 0x0c09bf2c */
if(!s->budget--) { s->failed_pc=0x0c09bf2cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c09bf2e;
P_0c09bf2e: /* original 5342, guest PC 0x0c09bf2e */
if(!s->budget--) { s->failed_pc=0x0c09bf2eu; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09bf30;
P_0c09bf30: /* original 2239, guest PC 0x0c09bf30 */
if(!s->budget--) { s->failed_pc=0x0c09bf30u; return 0; }
r[2]&=r[3];
goto P_0c09bf32;
P_0c09bf32: /* original 2258, guest PC 0x0c09bf32 */
if(!s->budget--) { s->failed_pc=0x0c09bf32u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf34;
P_0c09bf34: /* original 8902, guest PC 0x0c09bf34 */
if(!s->budget--) { s->failed_pc=0x0c09bf34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf3c; }
goto P_0c09bf36;
P_0c09bf36: /* original 902f, guest PC 0x0c09bf36 */
if(!s->budget--) { s->failed_pc=0x0c09bf36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf98u,2);
goto P_0c09bf38;
P_0c09bf38: /* original 000b, guest PC 0x0c09bf38 */
if(!s->budget--) { s->failed_pc=0x0c09bf38u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf3a: /* original 0009, guest PC 0x0c09bf3a */
if(!s->budget--) { s->failed_pc=0x0c09bf3au; return 0; }
goto P_0c09bf3c;
P_0c09bf3c: /* original 5241, guest PC 0x0c09bf3c */
if(!s->budget--) { s->failed_pc=0x0c09bf3cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c09bf3e;
P_0c09bf3e: /* original 5343, guest PC 0x0c09bf3e */
if(!s->budget--) { s->failed_pc=0x0c09bf3eu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c09bf40;
P_0c09bf40: /* original 2239, guest PC 0x0c09bf40 */
if(!s->budget--) { s->failed_pc=0x0c09bf40u; return 0; }
r[2]&=r[3];
goto P_0c09bf42;
P_0c09bf42: /* original 2258, guest PC 0x0c09bf42 */
if(!s->budget--) { s->failed_pc=0x0c09bf42u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf44;
P_0c09bf44: /* original 8902, guest PC 0x0c09bf44 */
if(!s->budget--) { s->failed_pc=0x0c09bf44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf4c; }
goto P_0c09bf46;
P_0c09bf46: /* original 9028, guest PC 0x0c09bf46 */
if(!s->budget--) { s->failed_pc=0x0c09bf46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf9au,2);
goto P_0c09bf48;
P_0c09bf48: /* original 000b, guest PC 0x0c09bf48 */
if(!s->budget--) { s->failed_pc=0x0c09bf48u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf4a: /* original 0009, guest PC 0x0c09bf4a */
if(!s->budget--) { s->failed_pc=0x0c09bf4au; return 0; }
goto P_0c09bf4c;
P_0c09bf4c: /* original 6242, guest PC 0x0c09bf4c */
if(!s->budget--) { s->failed_pc=0x0c09bf4cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf4e;
P_0c09bf4e: /* original 5341, guest PC 0x0c09bf4e */
if(!s->budget--) { s->failed_pc=0x0c09bf4eu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09bf50;
P_0c09bf50: /* original 2239, guest PC 0x0c09bf50 */
if(!s->budget--) { s->failed_pc=0x0c09bf50u; return 0; }
r[2]&=r[3];
goto P_0c09bf52;
P_0c09bf52: /* original 2258, guest PC 0x0c09bf52 */
if(!s->budget--) { s->failed_pc=0x0c09bf52u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf54;
P_0c09bf54: /* original 8902, guest PC 0x0c09bf54 */
if(!s->budget--) { s->failed_pc=0x0c09bf54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf5c; }
goto P_0c09bf56;
P_0c09bf56: /* original 9021, guest PC 0x0c09bf56 */
if(!s->budget--) { s->failed_pc=0x0c09bf56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf9cu,2);
goto P_0c09bf58;
P_0c09bf58: /* original 000b, guest PC 0x0c09bf58 */
if(!s->budget--) { s->failed_pc=0x0c09bf58u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf5a: /* original 0009, guest PC 0x0c09bf5a */
if(!s->budget--) { s->failed_pc=0x0c09bf5au; return 0; }
goto P_0c09bf5c;
P_0c09bf5c: /* original 6242, guest PC 0x0c09bf5c */
if(!s->budget--) { s->failed_pc=0x0c09bf5cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf5e;
P_0c09bf5e: /* original 2258, guest PC 0x0c09bf5e */
if(!s->budget--) { s->failed_pc=0x0c09bf5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf60;
P_0c09bf60: /* original 8901, guest PC 0x0c09bf60 */
if(!s->budget--) { s->failed_pc=0x0c09bf60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf66; }
goto P_0c09bf62;
P_0c09bf62: /* original 000b, guest PC 0x0c09bf62 */
if(!s->budget--) { s->failed_pc=0x0c09bf62u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c09bf64: /* original e001, guest PC 0x0c09bf64 */
if(!s->budget--) { s->failed_pc=0x0c09bf64u; return 0; }
r[0]=0x00000001u;
goto P_0c09bf66;
P_0c09bf66: /* original 5241, guest PC 0x0c09bf66 */
if(!s->budget--) { s->failed_pc=0x0c09bf66u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c09bf68;
P_0c09bf68: /* original 2258, guest PC 0x0c09bf68 */
if(!s->budget--) { s->failed_pc=0x0c09bf68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf6a;
P_0c09bf6a: /* original 8901, guest PC 0x0c09bf6a */
if(!s->budget--) { s->failed_pc=0x0c09bf6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf70; }
goto P_0c09bf6c;
P_0c09bf6c: /* original 000b, guest PC 0x0c09bf6c */
if(!s->budget--) { s->failed_pc=0x0c09bf6cu; return 0; }
target=r[16];
r[0]=0x00000002u;
s->pc=target; return ram->oob==0;
P_0c09bf6e: /* original e002, guest PC 0x0c09bf6e */
if(!s->budget--) { s->failed_pc=0x0c09bf6eu; return 0; }
r[0]=0x00000002u;
goto P_0c09bf70;
P_0c09bf70: /* original 5242, guest PC 0x0c09bf70 */
if(!s->budget--) { s->failed_pc=0x0c09bf70u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09bf72;
P_0c09bf72: /* original 2258, guest PC 0x0c09bf72 */
if(!s->budget--) { s->failed_pc=0x0c09bf72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf74;
P_0c09bf74: /* original 8901, guest PC 0x0c09bf74 */
if(!s->budget--) { s->failed_pc=0x0c09bf74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf7a; }
goto P_0c09bf76;
P_0c09bf76: /* original 000b, guest PC 0x0c09bf76 */
if(!s->budget--) { s->failed_pc=0x0c09bf76u; return 0; }
target=r[16];
r[0]=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c09bf78: /* original e004, guest PC 0x0c09bf78 */
if(!s->budget--) { s->failed_pc=0x0c09bf78u; return 0; }
r[0]=0x00000004u;
goto P_0c09bf7a;
P_0c09bf7a: /* original 5243, guest PC 0x0c09bf7a */
if(!s->budget--) { s->failed_pc=0x0c09bf7au; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c09bf7c;
P_0c09bf7c: /* original 2258, guest PC 0x0c09bf7c */
if(!s->budget--) { s->failed_pc=0x0c09bf7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf7e;
P_0c09bf7e: /* original 8901, guest PC 0x0c09bf7e */
if(!s->budget--) { s->failed_pc=0x0c09bf7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf84; }
goto P_0c09bf80;
P_0c09bf80: /* original 000b, guest PC 0x0c09bf80 */
if(!s->budget--) { s->failed_pc=0x0c09bf80u; return 0; }
target=r[16];
r[0]=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c09bf82: /* original e008, guest PC 0x0c09bf82 */
if(!s->budget--) { s->failed_pc=0x0c09bf82u; return 0; }
r[0]=0x00000008u;
goto P_0c09bf84;
P_0c09bf84: /* original 5244, guest PC 0x0c09bf84 */
if(!s->budget--) { s->failed_pc=0x0c09bf84u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c09bf86;
P_0c09bf86: /* original 2528, guest PC 0x0c09bf86 */
if(!s->budget--) { s->failed_pc=0x0c09bf86u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c09bf88;
P_0c09bf88: /* original 8901, guest PC 0x0c09bf88 */
if(!s->budget--) { s->failed_pc=0x0c09bf88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf8e; }
goto P_0c09bf8a;
P_0c09bf8a: /* original 000b, guest PC 0x0c09bf8a */
if(!s->budget--) { s->failed_pc=0x0c09bf8au; return 0; }
target=r[16];
r[0]=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c09bf8c: /* original e010, guest PC 0x0c09bf8c */
if(!s->budget--) { s->failed_pc=0x0c09bf8cu; return 0; }
r[0]=0x00000010u;
goto P_0c09bf8e;
P_0c09bf8e: /* original e000, guest PC 0x0c09bf8e */
if(!s->budget--) { s->failed_pc=0x0c09bf8eu; return 0; }
r[0]=0x00000000u;
goto P_0c09bf90;
P_0c09bf90: /* original 000b, guest PC 0x0c09bf90 */
if(!s->budget--) { s->failed_pc=0x0c09bf90u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf92: /* original 0009, guest PC 0x0c09bf92 */
if(!s->budget--) { s->failed_pc=0x0c09bf92u; return 0; }
return vf3_matrix_family(0x0c09bf94u,s,ram);
P_0c09c044: /* original 4f22, guest PC 0x0c09c044 */
if(!s->budget--) { s->failed_pc=0x0c09c044u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09c046;
P_0c09c046: /* original d323, guest PC 0x0c09c046 */
if(!s->budget--) { s->failed_pc=0x0c09c046u; return 0; }
r[3]=read(ram,0x0c09c0d4u,4);
goto P_0c09c048;
P_0c09c048: /* original de1f, guest PC 0x0c09c048 */
if(!s->budget--) { s->failed_pc=0x0c09c048u; return 0; }
r[14]=read(ram,0x0c09c0c8u,4);
goto P_0c09c04a;
P_0c09c04a: /* original 430b, guest PC 0x0c09c04a */
if(!s->budget--) { s->failed_pc=0x0c09c04au; return 0; }
target=r[3];
r[16]=0x0c09c04eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c04eu) { target=s->pc; goto dispatch; }
goto P_0c09c04e;
P_0c09c04c: /* original e400, guest PC 0x0c09c04c */
if(!s->budget--) { s->failed_pc=0x0c09c04cu; return 0; }
r[4]=0x00000000u;
goto P_0c09c04e;
P_0c09c04e: /* original e300, guest PC 0x0c09c04e */
if(!s->budget--) { s->failed_pc=0x0c09c04eu; return 0; }
r[3]=0x00000000u;
goto P_0c09c050;
P_0c09c050: /* original 6a33, guest PC 0x0c09c050 */
if(!s->budget--) { s->failed_pc=0x0c09c050u; return 0; }
r[10]=r[3];
goto P_0c09c052;
P_0c09c052: /* original e07d, guest PC 0x0c09c052 */
if(!s->budget--) { s->failed_pc=0x0c09c052u; return 0; }
r[0]=0x0000007du;
goto P_0c09c054;
P_0c09c054: /* original e240, guest PC 0x0c09c054 */
if(!s->budget--) { s->failed_pc=0x0c09c054u; return 0; }
r[2]=0x00000040u;
goto P_0c09c056;
P_0c09c056: /* original 1e23, guest PC 0x0c09c056 */
if(!s->budget--) { s->failed_pc=0x0c09c056u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09c058;
P_0c09c058: /* original 62a3, guest PC 0x0c09c058 */
if(!s->budget--) { s->failed_pc=0x0c09c058u; return 0; }
r[2]=r[10];
goto P_0c09c05a;
P_0c09c05a: /* original 6b23, guest PC 0x0c09c05a */
if(!s->budget--) { s->failed_pc=0x0c09c05au; return 0; }
r[11]=r[2];
goto P_0c09c05c;
P_0c09c05c: /* original 1e36, guest PC 0x0c09c05c */
if(!s->budget--) { s->failed_pc=0x0c09c05cu; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c09c05e;
P_0c09c05e: /* original 0ea4, guest PC 0x0c09c05e */
if(!s->budget--) { s->failed_pc=0x0c09c05eu; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c09c060;
P_0c09c060: /* original 1ea5, guest PC 0x0c09c060 */
if(!s->budget--) { s->failed_pc=0x0c09c060u; return 0; }
write(ram,r[14]+20,r[10],4);
goto P_0c09c062;
P_0c09c062: /* original 902c, guest PC 0x0c09c062 */
if(!s->budget--) { s->failed_pc=0x0c09c062u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0beu,2);
goto P_0c09c064;
P_0c09c064: /* original 0ea6, guest PC 0x0c09c064 */
if(!s->budget--) { s->failed_pc=0x0c09c064u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09c066;
P_0c09c066: /* original 70fc, guest PC 0x0c09c066 */
if(!s->budget--) { s->failed_pc=0x0c09c066u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09c068;
P_0c09c068: /* original 0e26, guest PC 0x0c09c068 */
if(!s->budget--) { s->failed_pc=0x0c09c068u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09c06a;
P_0c09c06a: /* original d818, guest PC 0x0c09c06a */
if(!s->budget--) { s->failed_pc=0x0c09c06au; return 0; }
r[8]=read(ram,0x0c09c0ccu,4);
goto P_0c09c06c;
P_0c09c06c: /* original d918, guest PC 0x0c09c06c */
if(!s->budget--) { s->failed_pc=0x0c09c06cu; return 0; }
r[9]=read(ram,0x0c09c0d0u,4);
goto P_0c09c06e;
P_0c09c06e: /* original 9327, guest PC 0x0c09c06e */
if(!s->budget--) { s->failed_pc=0x0c09c06eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0c0u,2);
goto P_0c09c070;
P_0c09c070: /* original 6cb3, guest PC 0x0c09c070 */
if(!s->budget--) { s->failed_pc=0x0c09c070u; return 0; }
r[12]=r[11];
goto P_0c09c072;
P_0c09c072: /* original 9226, guest PC 0x0c09c072 */
if(!s->budget--) { s->failed_pc=0x0c09c072u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0c2u,2);
goto P_0c09c074;
P_0c09c074: /* original 4c08, guest PC 0x0c09c074 */
if(!s->budget--) { s->failed_pc=0x0c09c074u; return 0; }
r[12]<<=2;
goto P_0c09c076;
P_0c09c076: /* original 33ec, guest PC 0x0c09c076 */
if(!s->budget--) { s->failed_pc=0x0c09c076u; return 0; }
r[3]+=r[14];
goto P_0c09c078;
P_0c09c078: /* original 6db3, guest PC 0x0c09c078 */
if(!s->budget--) { s->failed_pc=0x0c09c078u; return 0; }
r[13]=r[11];
goto P_0c09c07a;
P_0c09c07a: /* original 33cc, guest PC 0x0c09c07a */
if(!s->budget--) { s->failed_pc=0x0c09c07au; return 0; }
r[3]+=r[12];
goto P_0c09c07c;
P_0c09c07c: /* original 9122, guest PC 0x0c09c07c */
if(!s->budget--) { s->failed_pc=0x0c09c07cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0c4u,2);
goto P_0c09c07e;
P_0c09c07e: /* original 32ec, guest PC 0x0c09c07e */
if(!s->budget--) { s->failed_pc=0x0c09c07eu; return 0; }
r[2]+=r[14];
goto P_0c09c080;
P_0c09c080: /* original 4d08, guest PC 0x0c09c080 */
if(!s->budget--) { s->failed_pc=0x0c09c080u; return 0; }
r[13]<<=2;
goto P_0c09c082;
P_0c09c082: /* original 4d00, guest PC 0x0c09c082 */
if(!s->budget--) { s->failed_pc=0x0c09c082u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c09c084;
P_0c09c084: /* original 32cc, guest PC 0x0c09c084 */
if(!s->budget--) { s->failed_pc=0x0c09c084u; return 0; }
r[2]+=r[12];
goto P_0c09c086;
P_0c09c086: /* original 31ec, guest PC 0x0c09c086 */
if(!s->budget--) { s->failed_pc=0x0c09c086u; return 0; }
r[1]+=r[14];
goto P_0c09c088;
P_0c09c088: /* original 31cc, guest PC 0x0c09c088 */
if(!s->budget--) { s->failed_pc=0x0c09c088u; return 0; }
r[1]+=r[12];
goto P_0c09c08a;
P_0c09c08a: /* original 21a2, guest PC 0x0c09c08a */
if(!s->budget--) { s->failed_pc=0x0c09c08au; return 0; }
write(ram,r[1],r[10],4);
goto P_0c09c08c;
P_0c09c08c: /* original 22a2, guest PC 0x0c09c08c */
if(!s->budget--) { s->failed_pc=0x0c09c08cu; return 0; }
write(ram,r[2],r[10],4);
goto P_0c09c08e;
P_0c09c08e: /* original 23a2, guest PC 0x0c09c08e */
if(!s->budget--) { s->failed_pc=0x0c09c08eu; return 0; }
write(ram,r[3],r[10],4);
goto P_0c09c090;
P_0c09c090: /* original 63b3, guest PC 0x0c09c090 */
if(!s->budget--) { s->failed_pc=0x0c09c090u; return 0; }
r[3]=r[11];
goto P_0c09c092;
P_0c09c092: /* original 3d3c, guest PC 0x0c09c092 */
if(!s->budget--) { s->failed_pc=0x0c09c092u; return 0; }
r[13]+=r[3];
goto P_0c09c094;
P_0c09c094: /* original d210, guest PC 0x0c09c094 */
if(!s->budget--) { s->failed_pc=0x0c09c094u; return 0; }
r[2]=read(ram,0x0c09c0d8u,4);
goto P_0c09c096;
P_0c09c096: /* original 4d08, guest PC 0x0c09c096 */
if(!s->budget--) { s->failed_pc=0x0c09c096u; return 0; }
r[13]<<=2;
goto P_0c09c098;
P_0c09c098: /* original d310, guest PC 0x0c09c098 */
if(!s->budget--) { s->failed_pc=0x0c09c098u; return 0; }
r[3]=read(ram,0x0c09c0dcu,4);
goto P_0c09c09a;
P_0c09c09a: /* original 6dde, guest PC 0x0c09c09a */
if(!s->budget--) { s->failed_pc=0x0c09c09au; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)r[13];
goto P_0c09c09c;
P_0c09c09c: /* original 3d2c, guest PC 0x0c09c09c */
if(!s->budget--) { s->failed_pc=0x0c09c09cu; return 0; }
r[13]+=r[2];
goto P_0c09c09e;
P_0c09c09e: /* original 430b, guest PC 0x0c09c09e */
if(!s->budget--) { s->failed_pc=0x0c09c09eu; return 0; }
target=r[3];
r[16]=0x0c09c0a2u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c0a2u) { target=s->pc; goto dispatch; }
goto P_0c09c0a2;
P_0c09c0a0: /* original 64b3, guest PC 0x0c09c0a0 */
if(!s->budget--) { s->failed_pc=0x0c09c0a0u; return 0; }
r[4]=r[11];
goto P_0c09c0a2;
P_0c09c0a2: /* original 6403, guest PC 0x0c09c0a2 */
if(!s->budget--) { s->failed_pc=0x0c09c0a2u; return 0; }
r[4]=r[0];
goto P_0c09c0a4;
P_0c09c0a4: /* original 6342, guest PC 0x0c09c0a4 */
if(!s->budget--) { s->failed_pc=0x0c09c0a4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09c0a6;
P_0c09c0a6: /* original d20e, guest PC 0x0c09c0a6 */
if(!s->budget--) { s->failed_pc=0x0c09c0a6u; return 0; }
r[2]=read(ram,0x0c09c0e0u,4);
goto P_0c09c0a8;
P_0c09c0a8: /* original 3320, guest PC 0x0c09c0a8 */
if(!s->budget--) { s->failed_pc=0x0c09c0a8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09c0aa;
P_0c09c0aa: /* original 8b1b, guest PC 0x0c09c0aa */
if(!s->budget--) { s->failed_pc=0x0c09c0aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c0e4; }
goto P_0c09c0ac;
P_0c09c0ac: /* original 900b, guest PC 0x0c09c0ac */
if(!s->budget--) { s->failed_pc=0x0c09c0acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0c6u,2);
goto P_0c09c0ae;
P_0c09c0ae: /* original 30ec, guest PC 0x0c09c0ae */
if(!s->budget--) { s->failed_pc=0x0c09c0aeu; return 0; }
r[0]+=r[14];
goto P_0c09c0b0;
P_0c09c0b0: /* original 30cc, guest PC 0x0c09c0b0 */
if(!s->budget--) { s->failed_pc=0x0c09c0b0u; return 0; }
r[0]+=r[12];
goto P_0c09c0b2;
P_0c09c0b2: /* original a027, guest PC 0x0c09c0b2 */
if(!s->budget--) { s->failed_pc=0x0c09c0b2u; return 0; }
write(ram,r[0],r[10],4);
goto P_0c09c104;
P_0c09c0b4: /* original 20a2, guest PC 0x0c09c0b4 */
if(!s->budget--) { s->failed_pc=0x0c09c0b4u; return 0; }
write(ram,r[0],r[10],4);
return vf3_matrix_family(0x0c09c0b6u,s,ram);
P_0c09c0e4: /* original 6342, guest PC 0x0c09c0e4 */
if(!s->budget--) { s->failed_pc=0x0c09c0e4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09c0e6;
P_0c09c0e6: /* original 9191, guest PC 0x0c09c0e6 */
if(!s->budget--) { s->failed_pc=0x0c09c0e6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c20cu,2);
goto P_0c09c0e8;
P_0c09c0e8: /* original 3310, guest PC 0x0c09c0e8 */
if(!s->budget--) { s->failed_pc=0x0c09c0e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c09c0ea;
P_0c09c0ea: /* original 8b06, guest PC 0x0c09c0ea */
if(!s->budget--) { s->failed_pc=0x0c09c0eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c0fa; }
goto P_0c09c0ec;
P_0c09c0ec: /* original 938f, guest PC 0x0c09c0ec */
if(!s->budget--) { s->failed_pc=0x0c09c0ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c20eu,2);
goto P_0c09c0ee;
P_0c09c0ee: /* original e001, guest PC 0x0c09c0ee */
if(!s->budget--) { s->failed_pc=0x0c09c0eeu; return 0; }
r[0]=0x00000001u;
goto P_0c09c0f0;
P_0c09c0f0: /* original 33ec, guest PC 0x0c09c0f0 */
if(!s->budget--) { s->failed_pc=0x0c09c0f0u; return 0; }
r[3]+=r[14];
goto P_0c09c0f2;
P_0c09c0f2: /* original 33cc, guest PC 0x0c09c0f2 */
if(!s->budget--) { s->failed_pc=0x0c09c0f2u; return 0; }
r[3]+=r[12];
goto P_0c09c0f4;
P_0c09c0f4: /* original 2302, guest PC 0x0c09c0f4 */
if(!s->budget--) { s->failed_pc=0x0c09c0f4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c0f6;
P_0c09c0f6: /* original a005, guest PC 0x0c09c0f6 */
if(!s->budget--) { s->failed_pc=0x0c09c0f6u; return 0; }
goto P_0c09c104;
P_0c09c0f8: /* original 0009, guest PC 0x0c09c0f8 */
if(!s->budget--) { s->failed_pc=0x0c09c0f8u; return 0; }
goto P_0c09c0fa;
P_0c09c0fa: /* original 9388, guest PC 0x0c09c0fa */
if(!s->budget--) { s->failed_pc=0x0c09c0fau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c20eu,2);
goto P_0c09c0fc;
P_0c09c0fc: /* original e0ff, guest PC 0x0c09c0fc */
if(!s->budget--) { s->failed_pc=0x0c09c0fcu; return 0; }
r[0]=0xffffffffu;
goto P_0c09c0fe;
P_0c09c0fe: /* original 33ec, guest PC 0x0c09c0fe */
if(!s->budget--) { s->failed_pc=0x0c09c0feu; return 0; }
r[3]+=r[14];
goto P_0c09c100;
P_0c09c100: /* original 33cc, guest PC 0x0c09c100 */
if(!s->budget--) { s->failed_pc=0x0c09c100u; return 0; }
r[3]+=r[12];
goto P_0c09c102;
P_0c09c102: /* original 2302, guest PC 0x0c09c102 */
if(!s->budget--) { s->failed_pc=0x0c09c102u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c104;
P_0c09c104: /* original 6cb3, guest PC 0x0c09c104 */
if(!s->budget--) { s->failed_pc=0x0c09c104u; return 0; }
r[12]=r[11];
goto P_0c09c106;
P_0c09c106: /* original 9383, guest PC 0x0c09c106 */
if(!s->budget--) { s->failed_pc=0x0c09c106u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c108;
P_0c09c108: /* original 4c08, guest PC 0x0c09c108 */
if(!s->budget--) { s->failed_pc=0x0c09c108u; return 0; }
r[12]<<=2;
goto P_0c09c10a;
P_0c09c10a: /* original 4c08, guest PC 0x0c09c10a */
if(!s->budget--) { s->failed_pc=0x0c09c10au; return 0; }
r[12]<<=2;
goto P_0c09c10c;
P_0c09c10c: /* original 33ec, guest PC 0x0c09c10c */
if(!s->budget--) { s->failed_pc=0x0c09c10cu; return 0; }
r[3]+=r[14];
goto P_0c09c10e;
P_0c09c10e: /* original 4c08, guest PC 0x0c09c10e */
if(!s->budget--) { s->failed_pc=0x0c09c10eu; return 0; }
r[12]<<=2;
goto P_0c09c110;
P_0c09c110: /* original e104, guest PC 0x0c09c110 */
if(!s->budget--) { s->failed_pc=0x0c09c110u; return 0; }
r[1]=0x00000004u;
goto P_0c09c112;
P_0c09c112: /* original 33cc, guest PC 0x0c09c112 */
if(!s->budget--) { s->failed_pc=0x0c09c112u; return 0; }
r[3]+=r[12];
goto P_0c09c114;
P_0c09c114: /* original 313c, guest PC 0x0c09c114 */
if(!s->budget--) { s->failed_pc=0x0c09c114u; return 0; }
r[1]+=r[3];
goto P_0c09c116;
P_0c09c116: /* original e504, guest PC 0x0c09c116 */
if(!s->budget--) { s->failed_pc=0x0c09c116u; return 0; }
r[5]=0x00000004u;
goto P_0c09c118;
P_0c09c118: /* original 2f16, guest PC 0x0c09c118 */
if(!s->budget--) { s->failed_pc=0x0c09c118u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c11a;
P_0c09c11a: /* original beef, guest PC 0x0c09c11a */
if(!s->budget--) { s->failed_pc=0x0c09c11au; return 0; }
target=0x0c09befcu; r[16]=0x0c09c11eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c11eu) { target=s->pc; goto dispatch; }
goto P_0c09c11e;
P_0c09c11c: /* original 64d3, guest PC 0x0c09c11c */
if(!s->budget--) { s->failed_pc=0x0c09c11cu; return 0; }
r[4]=r[13];
goto P_0c09c11e;
P_0c09c11e: /* original e108, guest PC 0x0c09c11e */
if(!s->budget--) { s->failed_pc=0x0c09c11eu; return 0; }
r[1]=0x00000008u;
goto P_0c09c120;
P_0c09c120: /* original 62f6, guest PC 0x0c09c120 */
if(!s->budget--) { s->failed_pc=0x0c09c120u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c122;
P_0c09c122: /* original e502, guest PC 0x0c09c122 */
if(!s->budget--) { s->failed_pc=0x0c09c122u; return 0; }
r[5]=0x00000002u;
goto P_0c09c124;
P_0c09c124: /* original 2202, guest PC 0x0c09c124 */
if(!s->budget--) { s->failed_pc=0x0c09c124u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c126;
P_0c09c126: /* original 9373, guest PC 0x0c09c126 */
if(!s->budget--) { s->failed_pc=0x0c09c126u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c128;
P_0c09c128: /* original 33ec, guest PC 0x0c09c128 */
if(!s->budget--) { s->failed_pc=0x0c09c128u; return 0; }
r[3]+=r[14];
goto P_0c09c12a;
P_0c09c12a: /* original 33cc, guest PC 0x0c09c12a */
if(!s->budget--) { s->failed_pc=0x0c09c12au; return 0; }
r[3]+=r[12];
goto P_0c09c12c;
P_0c09c12c: /* original 313c, guest PC 0x0c09c12c */
if(!s->budget--) { s->failed_pc=0x0c09c12cu; return 0; }
r[1]+=r[3];
goto P_0c09c12e;
P_0c09c12e: /* original 2f16, guest PC 0x0c09c12e */
if(!s->budget--) { s->failed_pc=0x0c09c12eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c130;
P_0c09c130: /* original bee4, guest PC 0x0c09c130 */
if(!s->budget--) { s->failed_pc=0x0c09c130u; return 0; }
target=0x0c09befcu; r[16]=0x0c09c134u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c134u) { target=s->pc; goto dispatch; }
goto P_0c09c134;
P_0c09c132: /* original 64d3, guest PC 0x0c09c132 */
if(!s->budget--) { s->failed_pc=0x0c09c132u; return 0; }
r[4]=r[13];
goto P_0c09c134;
P_0c09c134: /* original e10c, guest PC 0x0c09c134 */
if(!s->budget--) { s->failed_pc=0x0c09c134u; return 0; }
r[1]=0x0000000cu;
goto P_0c09c136;
P_0c09c136: /* original 62f6, guest PC 0x0c09c136 */
if(!s->budget--) { s->failed_pc=0x0c09c136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c138;
P_0c09c138: /* original e501, guest PC 0x0c09c138 */
if(!s->budget--) { s->failed_pc=0x0c09c138u; return 0; }
r[5]=0x00000001u;
goto P_0c09c13a;
P_0c09c13a: /* original 2202, guest PC 0x0c09c13a */
if(!s->budget--) { s->failed_pc=0x0c09c13au; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c13c;
P_0c09c13c: /* original 9368, guest PC 0x0c09c13c */
if(!s->budget--) { s->failed_pc=0x0c09c13cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c13e;
P_0c09c13e: /* original 33ec, guest PC 0x0c09c13e */
if(!s->budget--) { s->failed_pc=0x0c09c13eu; return 0; }
r[3]+=r[14];
goto P_0c09c140;
P_0c09c140: /* original 33cc, guest PC 0x0c09c140 */
if(!s->budget--) { s->failed_pc=0x0c09c140u; return 0; }
r[3]+=r[12];
goto P_0c09c142;
P_0c09c142: /* original 313c, guest PC 0x0c09c142 */
if(!s->budget--) { s->failed_pc=0x0c09c142u; return 0; }
r[1]+=r[3];
goto P_0c09c144;
P_0c09c144: /* original 2f16, guest PC 0x0c09c144 */
if(!s->budget--) { s->failed_pc=0x0c09c144u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c146;
P_0c09c146: /* original bed9, guest PC 0x0c09c146 */
if(!s->budget--) { s->failed_pc=0x0c09c146u; return 0; }
target=0x0c09befcu; r[16]=0x0c09c14au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c14au) { target=s->pc; goto dispatch; }
goto P_0c09c14a;
P_0c09c148: /* original 64d3, guest PC 0x0c09c148 */
if(!s->budget--) { s->failed_pc=0x0c09c148u; return 0; }
r[4]=r[13];
goto P_0c09c14a;
P_0c09c14a: /* original e110, guest PC 0x0c09c14a */
if(!s->budget--) { s->failed_pc=0x0c09c14au; return 0; }
r[1]=0x00000010u;
goto P_0c09c14c;
P_0c09c14c: /* original 62f6, guest PC 0x0c09c14c */
if(!s->budget--) { s->failed_pc=0x0c09c14cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c14e;
P_0c09c14e: /* original 2202, guest PC 0x0c09c14e */
if(!s->budget--) { s->failed_pc=0x0c09c14eu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c150;
P_0c09c150: /* original 935e, guest PC 0x0c09c150 */
if(!s->budget--) { s->failed_pc=0x0c09c150u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c152;
P_0c09c152: /* original 33ec, guest PC 0x0c09c152 */
if(!s->budget--) { s->failed_pc=0x0c09c152u; return 0; }
r[3]+=r[14];
goto P_0c09c154;
P_0c09c154: /* original 33cc, guest PC 0x0c09c154 */
if(!s->budget--) { s->failed_pc=0x0c09c154u; return 0; }
r[3]+=r[12];
goto P_0c09c156;
P_0c09c156: /* original 313c, guest PC 0x0c09c156 */
if(!s->budget--) { s->failed_pc=0x0c09c156u; return 0; }
r[1]+=r[3];
goto P_0c09c158;
P_0c09c158: /* original 2f16, guest PC 0x0c09c158 */
if(!s->budget--) { s->failed_pc=0x0c09c158u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c15a;
P_0c09c15a: /* original 955a, guest PC 0x0c09c15a */
if(!s->budget--) { s->failed_pc=0x0c09c15au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c212u,2);
goto P_0c09c15c;
P_0c09c15c: /* original bece, guest PC 0x0c09c15c */
if(!s->budget--) { s->failed_pc=0x0c09c15cu; return 0; }
target=0x0c09befcu; r[16]=0x0c09c160u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c160u) { target=s->pc; goto dispatch; }
goto P_0c09c160;
P_0c09c15e: /* original 64d3, guest PC 0x0c09c15e */
if(!s->budget--) { s->failed_pc=0x0c09c15eu; return 0; }
r[4]=r[13];
goto P_0c09c160;
P_0c09c160: /* original e114, guest PC 0x0c09c160 */
if(!s->budget--) { s->failed_pc=0x0c09c160u; return 0; }
r[1]=0x00000014u;
goto P_0c09c162;
P_0c09c162: /* original 62f6, guest PC 0x0c09c162 */
if(!s->budget--) { s->failed_pc=0x0c09c162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c164;
P_0c09c164: /* original 2202, guest PC 0x0c09c164 */
if(!s->budget--) { s->failed_pc=0x0c09c164u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c166;
P_0c09c166: /* original 9353, guest PC 0x0c09c166 */
if(!s->budget--) { s->failed_pc=0x0c09c166u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c168;
P_0c09c168: /* original 33ec, guest PC 0x0c09c168 */
if(!s->budget--) { s->failed_pc=0x0c09c168u; return 0; }
r[3]+=r[14];
goto P_0c09c16a;
P_0c09c16a: /* original 33cc, guest PC 0x0c09c16a */
if(!s->budget--) { s->failed_pc=0x0c09c16au; return 0; }
r[3]+=r[12];
goto P_0c09c16c;
P_0c09c16c: /* original 313c, guest PC 0x0c09c16c */
if(!s->budget--) { s->failed_pc=0x0c09c16cu; return 0; }
r[1]+=r[3];
goto P_0c09c16e;
P_0c09c16e: /* original 2f16, guest PC 0x0c09c16e */
if(!s->budget--) { s->failed_pc=0x0c09c16eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c170;
P_0c09c170: /* original 9550, guest PC 0x0c09c170 */
if(!s->budget--) { s->failed_pc=0x0c09c170u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c214u,2);
goto P_0c09c172;
P_0c09c172: /* original bec3, guest PC 0x0c09c172 */
if(!s->budget--) { s->failed_pc=0x0c09c172u; return 0; }
target=0x0c09befcu; r[16]=0x0c09c176u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c176u) { target=s->pc; goto dispatch; }
goto P_0c09c176;
P_0c09c174: /* original 64d3, guest PC 0x0c09c174 */
if(!s->budget--) { s->failed_pc=0x0c09c174u; return 0; }
r[4]=r[13];
goto P_0c09c176;
P_0c09c176: /* original e118, guest PC 0x0c09c176 */
if(!s->budget--) { s->failed_pc=0x0c09c176u; return 0; }
r[1]=0x00000018u;
goto P_0c09c178;
P_0c09c178: /* original 62f6, guest PC 0x0c09c178 */
if(!s->budget--) { s->failed_pc=0x0c09c178u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c17a;
P_0c09c17a: /* original 2202, guest PC 0x0c09c17a */
if(!s->budget--) { s->failed_pc=0x0c09c17au; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c17c;
P_0c09c17c: /* original 9348, guest PC 0x0c09c17c */
if(!s->budget--) { s->failed_pc=0x0c09c17cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c17e;
P_0c09c17e: /* original 33ec, guest PC 0x0c09c17e */
if(!s->budget--) { s->failed_pc=0x0c09c17eu; return 0; }
r[3]+=r[14];
goto P_0c09c180;
P_0c09c180: /* original 33cc, guest PC 0x0c09c180 */
if(!s->budget--) { s->failed_pc=0x0c09c180u; return 0; }
r[3]+=r[12];
goto P_0c09c182;
P_0c09c182: /* original 313c, guest PC 0x0c09c182 */
if(!s->budget--) { s->failed_pc=0x0c09c182u; return 0; }
r[1]+=r[3];
goto P_0c09c184;
P_0c09c184: /* original 2f16, guest PC 0x0c09c184 */
if(!s->budget--) { s->failed_pc=0x0c09c184u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c186;
P_0c09c186: /* original 9546, guest PC 0x0c09c186 */
if(!s->budget--) { s->failed_pc=0x0c09c186u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c216u,2);
goto P_0c09c188;
P_0c09c188: /* original beb8, guest PC 0x0c09c188 */
if(!s->budget--) { s->failed_pc=0x0c09c188u; return 0; }
target=0x0c09befcu; r[16]=0x0c09c18cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c18cu) { target=s->pc; goto dispatch; }
goto P_0c09c18c;
P_0c09c18a: /* original 64d3, guest PC 0x0c09c18a */
if(!s->budget--) { s->failed_pc=0x0c09c18au; return 0; }
r[4]=r[13];
goto P_0c09c18c;
P_0c09c18c: /* original e11c, guest PC 0x0c09c18c */
if(!s->budget--) { s->failed_pc=0x0c09c18cu; return 0; }
r[1]=0x0000001cu;
goto P_0c09c18e;
P_0c09c18e: /* original 62f6, guest PC 0x0c09c18e */
if(!s->budget--) { s->failed_pc=0x0c09c18eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c190;
P_0c09c190: /* original 6583, guest PC 0x0c09c190 */
if(!s->budget--) { s->failed_pc=0x0c09c190u; return 0; }
r[5]=r[8];
goto P_0c09c192;
P_0c09c192: /* original 2202, guest PC 0x0c09c192 */
if(!s->budget--) { s->failed_pc=0x0c09c192u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c194;
P_0c09c194: /* original 933c, guest PC 0x0c09c194 */
if(!s->budget--) { s->failed_pc=0x0c09c194u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c196;
P_0c09c196: /* original 33ec, guest PC 0x0c09c196 */
if(!s->budget--) { s->failed_pc=0x0c09c196u; return 0; }
r[3]+=r[14];
goto P_0c09c198;
P_0c09c198: /* original 33cc, guest PC 0x0c09c198 */
if(!s->budget--) { s->failed_pc=0x0c09c198u; return 0; }
r[3]+=r[12];
goto P_0c09c19a;
P_0c09c19a: /* original 313c, guest PC 0x0c09c19a */
if(!s->budget--) { s->failed_pc=0x0c09c19au; return 0; }
r[1]+=r[3];
goto P_0c09c19c;
P_0c09c19c: /* original 2f16, guest PC 0x0c09c19c */
if(!s->budget--) { s->failed_pc=0x0c09c19cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c19e;
P_0c09c19e: /* original bead, guest PC 0x0c09c19e */
if(!s->budget--) { s->failed_pc=0x0c09c19eu; return 0; }
target=0x0c09befcu; r[16]=0x0c09c1a2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c1a2u) { target=s->pc; goto dispatch; }
goto P_0c09c1a2;
P_0c09c1a0: /* original 64d3, guest PC 0x0c09c1a0 */
if(!s->budget--) { s->failed_pc=0x0c09c1a0u; return 0; }
r[4]=r[13];
goto P_0c09c1a2;
P_0c09c1a2: /* original 62f6, guest PC 0x0c09c1a2 */
if(!s->budget--) { s->failed_pc=0x0c09c1a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c1a4;
P_0c09c1a4: /* original 6593, guest PC 0x0c09c1a4 */
if(!s->budget--) { s->failed_pc=0x0c09c1a4u; return 0; }
r[5]=r[9];
goto P_0c09c1a6;
P_0c09c1a6: /* original 2202, guest PC 0x0c09c1a6 */
if(!s->budget--) { s->failed_pc=0x0c09c1a6u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c1a8;
P_0c09c1a8: /* original 9332, guest PC 0x0c09c1a8 */
if(!s->budget--) { s->failed_pc=0x0c09c1a8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c1aa;
P_0c09c1aa: /* original 33ec, guest PC 0x0c09c1aa */
if(!s->budget--) { s->failed_pc=0x0c09c1aau; return 0; }
r[3]+=r[14];
goto P_0c09c1ac;
P_0c09c1ac: /* original 3c3c, guest PC 0x0c09c1ac */
if(!s->budget--) { s->failed_pc=0x0c09c1acu; return 0; }
r[12]+=r[3];
goto P_0c09c1ae;
P_0c09c1ae: /* original bea5, guest PC 0x0c09c1ae */
if(!s->budget--) { s->failed_pc=0x0c09c1aeu; return 0; }
target=0x0c09befcu; r[16]=0x0c09c1b2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c1b2u) { target=s->pc; goto dispatch; }
goto P_0c09c1b2;
P_0c09c1b0: /* original 64d3, guest PC 0x0c09c1b0 */
if(!s->budget--) { s->failed_pc=0x0c09c1b0u; return 0; }
r[4]=r[13];
goto P_0c09c1b2;
P_0c09c1b2: /* original e302, guest PC 0x0c09c1b2 */
if(!s->budget--) { s->failed_pc=0x0c09c1b2u; return 0; }
r[3]=0x00000002u;
goto P_0c09c1b4;
P_0c09c1b4: /* original 7b01, guest PC 0x0c09c1b4 */
if(!s->budget--) { s->failed_pc=0x0c09c1b4u; return 0; }
r[11]+=0x00000001u;
goto P_0c09c1b6;
P_0c09c1b6: /* original 3b33, guest PC 0x0c09c1b6 */
if(!s->budget--) { s->failed_pc=0x0c09c1b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c09c1b8;
P_0c09c1b8: /* original 8d02, guest PC 0x0c09c1b8 */
if(!s->budget--) { s->failed_pc=0x0c09c1b8u; return 0; }
cond=r[17]&1u;
write(ram,r[12]+32,r[0],4);
if(cond) { goto P_0c09c1c0; }
goto P_0c09c1bc;
P_0c09c1ba: /* original 1c08, guest PC 0x0c09c1ba */
if(!s->budget--) { s->failed_pc=0x0c09c1bau; return 0; }
write(ram,r[12]+32,r[0],4);
goto P_0c09c1bc;
P_0c09c1bc: /* original af57, guest PC 0x0c09c1bc */
if(!s->budget--) { s->failed_pc=0x0c09c1bcu; return 0; }
goto P_0c09c06e;
P_0c09c1be: /* original 0009, guest PC 0x0c09c1be */
if(!s->budget--) { s->failed_pc=0x0c09c1beu; return 0; }
goto P_0c09c1c0;
P_0c09c1c0: /* original 4f26, guest PC 0x0c09c1c0 */
if(!s->budget--) { s->failed_pc=0x0c09c1c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09c1c2;
P_0c09c1c2: /* original 84eb, guest PC 0x0c09c1c2 */
if(!s->budget--) { s->failed_pc=0x0c09c1c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09c1c4;
P_0c09c1c4: /* original e377, guest PC 0x0c09c1c4 */
if(!s->budget--) { s->failed_pc=0x0c09c1c4u; return 0; }
r[3]=0x00000077u;
goto P_0c09c1c6;
P_0c09c1c6: /* original 7001, guest PC 0x0c09c1c6 */
if(!s->budget--) { s->failed_pc=0x0c09c1c6u; return 0; }
r[0]+=0x00000001u;
goto P_0c09c1c8;
P_0c09c1c8: /* original 80eb, guest PC 0x0c09c1c8 */
if(!s->budget--) { s->failed_pc=0x0c09c1c8u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09c1ca;
P_0c09c1ca: /* original e010, guest PC 0x0c09c1ca */
if(!s->budget--) { s->failed_pc=0x0c09c1cau; return 0; }
r[0]=0x00000010u;
goto P_0c09c1cc;
P_0c09c1cc: /* original 0e34, guest PC 0x0c09c1cc */
if(!s->budget--) { s->failed_pc=0x0c09c1ccu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09c1ce;
P_0c09c1ce: /* original 68f6, guest PC 0x0c09c1ce */
if(!s->budget--) { s->failed_pc=0x0c09c1ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09c1d0;
P_0c09c1d0: /* original 69f6, guest PC 0x0c09c1d0 */
if(!s->budget--) { s->failed_pc=0x0c09c1d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09c1d2;
P_0c09c1d2: /* original 6af6, guest PC 0x0c09c1d2 */
if(!s->budget--) { s->failed_pc=0x0c09c1d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09c1d4;
P_0c09c1d4: /* original 6bf6, guest PC 0x0c09c1d4 */
if(!s->budget--) { s->failed_pc=0x0c09c1d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09c1d6;
P_0c09c1d6: /* original 6cf6, guest PC 0x0c09c1d6 */
if(!s->budget--) { s->failed_pc=0x0c09c1d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09c1d8;
P_0c09c1d8: /* original 6df6, guest PC 0x0c09c1d8 */
if(!s->budget--) { s->failed_pc=0x0c09c1d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09c1da;
P_0c09c1da: /* original a000, guest PC 0x0c09c1da */
if(!s->budget--) { s->failed_pc=0x0c09c1dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09c1de;
P_0c09c1dc: /* original 6ef6, guest PC 0x0c09c1dc */
if(!s->budget--) { s->failed_pc=0x0c09c1dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09c1de;
P_0c09c1de: /* original 2fe6, guest PC 0x0c09c1de */
if(!s->budget--) { s->failed_pc=0x0c09c1deu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1e0;
P_0c09c1e0: /* original e07d, guest PC 0x0c09c1e0 */
if(!s->budget--) { s->failed_pc=0x0c09c1e0u; return 0; }
r[0]=0x0000007du;
goto P_0c09c1e2;
P_0c09c1e2: /* original 2fd6, guest PC 0x0c09c1e2 */
if(!s->budget--) { s->failed_pc=0x0c09c1e2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1e4;
P_0c09c1e4: /* original e340, guest PC 0x0c09c1e4 */
if(!s->budget--) { s->failed_pc=0x0c09c1e4u; return 0; }
r[3]=0x00000040u;
goto P_0c09c1e6;
P_0c09c1e6: /* original 2fc6, guest PC 0x0c09c1e6 */
if(!s->budget--) { s->failed_pc=0x0c09c1e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1e8;
P_0c09c1e8: /* original ec01, guest PC 0x0c09c1e8 */
if(!s->budget--) { s->failed_pc=0x0c09c1e8u; return 0; }
r[12]=0x00000001u;
goto P_0c09c1ea;
P_0c09c1ea: /* original 2fb6, guest PC 0x0c09c1ea */
if(!s->budget--) { s->failed_pc=0x0c09c1eau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1ec;
P_0c09c1ec: /* original 2fa6, guest PC 0x0c09c1ec */
if(!s->budget--) { s->failed_pc=0x0c09c1ecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1ee;
P_0c09c1ee: /* original 2f96, guest PC 0x0c09c1ee */
if(!s->budget--) { s->failed_pc=0x0c09c1eeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1f0;
P_0c09c1f0: /* original e900, guest PC 0x0c09c1f0 */
if(!s->budget--) { s->failed_pc=0x0c09c1f0u; return 0; }
r[9]=0x00000000u;
goto P_0c09c1f2;
P_0c09c1f2: /* original 2f86, guest PC 0x0c09c1f2 */
if(!s->budget--) { s->failed_pc=0x0c09c1f2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1f4;
P_0c09c1f4: /* original 4f22, guest PC 0x0c09c1f4 */
if(!s->budget--) { s->failed_pc=0x0c09c1f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09c1f6;
P_0c09c1f6: /* original dd0a, guest PC 0x0c09c1f6 */
if(!s->budget--) { s->failed_pc=0x0c09c1f6u; return 0; }
r[13]=read(ram,0x0c09c220u,4);
goto P_0c09c1f8;
P_0c09c1f8: /* original 9b0e, guest PC 0x0c09c1f8 */
if(!s->budget--) { s->failed_pc=0x0c09c1f8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c218u,2);
goto P_0c09c1fa;
P_0c09c1fa: /* original 980a, guest PC 0x0c09c1fa */
if(!s->budget--) { s->failed_pc=0x0c09c1fau; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c212u,2);
goto P_0c09c1fc;
P_0c09c1fc: /* original 7ff4, guest PC 0x0c09c1fc */
if(!s->budget--) { s->failed_pc=0x0c09c1fcu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09c1fe;
P_0c09c1fe: /* original da07, guest PC 0x0c09c1fe */
if(!s->budget--) { s->failed_pc=0x0c09c1feu; return 0; }
r[10]=read(ram,0x0c09c21cu,4);
goto P_0c09c200;
P_0c09c200: /* original 1d33, guest PC 0x0c09c200 */
if(!s->budget--) { s->failed_pc=0x0c09c200u; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c09c202;
P_0c09c202: /* original 1d96, guest PC 0x0c09c202 */
if(!s->budget--) { s->failed_pc=0x0c09c202u; return 0; }
write(ram,r[13]+24,r[9],4);
goto P_0c09c204;
P_0c09c204: /* original 0d94, guest PC 0x0c09c204 */
if(!s->budget--) { s->failed_pc=0x0c09c204u; return 0; }
write(ram,r[13]+r[0],r[9],1);
goto P_0c09c206;
P_0c09c206: /* original 1d95, guest PC 0x0c09c206 */
if(!s->budget--) { s->failed_pc=0x0c09c206u; return 0; }
write(ram,r[13]+20,r[9],4);
goto P_0c09c208;
P_0c09c208: /* original a3f6, guest PC 0x0c09c208 */
if(!s->budget--) { s->failed_pc=0x0c09c208u; return 0; }
r[14]=r[9];
goto P_0c09c9f8;
P_0c09c20a: /* original 6e93, guest PC 0x0c09c20a */
if(!s->budget--) { s->failed_pc=0x0c09c20au; return 0; }
r[14]=r[9];
return vf3_matrix_family(0x0c09c20cu,s,ram);
P_0c09c224: /* original d232, guest PC 0x0c09c224 */
if(!s->budget--) { s->failed_pc=0x0c09c224u; return 0; }
r[2]=read(ram,0x0c09c2f0u,4);
goto P_0c09c226;
P_0c09c226: /* original 420b, guest PC 0x0c09c226 */
if(!s->budget--) { s->failed_pc=0x0c09c226u; return 0; }
target=r[2];
r[16]=0x0c09c22au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c22au) { target=s->pc; goto dispatch; }
goto P_0c09c22a;
P_0c09c228: /* original 64e3, guest PC 0x0c09c228 */
if(!s->budget--) { s->failed_pc=0x0c09c228u; return 0; }
r[4]=r[14];
goto P_0c09c22a;
P_0c09c22a: /* original 63e3, guest PC 0x0c09c22a */
if(!s->budget--) { s->failed_pc=0x0c09c22au; return 0; }
r[3]=r[14];
goto P_0c09c22c;
P_0c09c22c: /* original 4308, guest PC 0x0c09c22c */
if(!s->budget--) { s->failed_pc=0x0c09c22cu; return 0; }
r[3]<<=2;
goto P_0c09c22e;
P_0c09c22e: /* original 4300, guest PC 0x0c09c22e */
if(!s->budget--) { s->failed_pc=0x0c09c22eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c09c230;
P_0c09c230: /* original 62e3, guest PC 0x0c09c230 */
if(!s->budget--) { s->failed_pc=0x0c09c230u; return 0; }
r[2]=r[14];
goto P_0c09c232;
P_0c09c232: /* original 332c, guest PC 0x0c09c232 */
if(!s->budget--) { s->failed_pc=0x0c09c232u; return 0; }
r[3]+=r[2];
goto P_0c09c234;
P_0c09c234: /* original 1f02, guest PC 0x0c09c234 */
if(!s->budget--) { s->failed_pc=0x0c09c234u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c09c236;
P_0c09c236: /* original d12f, guest PC 0x0c09c236 */
if(!s->budget--) { s->failed_pc=0x0c09c236u; return 0; }
r[1]=read(ram,0x0c09c2f4u,4);
goto P_0c09c238;
P_0c09c238: /* original 4308, guest PC 0x0c09c238 */
if(!s->budget--) { s->failed_pc=0x0c09c238u; return 0; }
r[3]<<=2;
goto P_0c09c23a;
P_0c09c23a: /* original 633e, guest PC 0x0c09c23a */
if(!s->budget--) { s->failed_pc=0x0c09c23au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c09c23c;
P_0c09c23c: /* original 331c, guest PC 0x0c09c23c */
if(!s->budget--) { s->failed_pc=0x0c09c23cu; return 0; }
r[3]+=r[1];
goto P_0c09c23e;
P_0c09c23e: /* original 1f31, guest PC 0x0c09c23e */
if(!s->budget--) { s->failed_pc=0x0c09c23eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09c240;
P_0c09c240: /* original d22d, guest PC 0x0c09c240 */
if(!s->budget--) { s->failed_pc=0x0c09c240u; return 0; }
r[2]=read(ram,0x0c09c2f8u,4);
goto P_0c09c242;
P_0c09c242: /* original 420b, guest PC 0x0c09c242 */
if(!s->budget--) { s->failed_pc=0x0c09c242u; return 0; }
target=r[2];
r[16]=0x0c09c246u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c246u) { target=s->pc; goto dispatch; }
goto P_0c09c246;
P_0c09c244: /* original 64e3, guest PC 0x0c09c244 */
if(!s->budget--) { s->failed_pc=0x0c09c244u; return 0; }
r[4]=r[14];
goto P_0c09c246;
P_0c09c246: /* original d42d, guest PC 0x0c09c246 */
if(!s->budget--) { s->failed_pc=0x0c09c246u; return 0; }
r[4]=read(ram,0x0c09c2fcu,4);
goto P_0c09c248;
P_0c09c248: /* original 3040, guest PC 0x0c09c248 */
if(!s->budget--) { s->failed_pc=0x0c09c248u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[4])!=0);
goto P_0c09c24a;
P_0c09c24a: /* original 8f0a, guest PC 0x0c09c24a */
if(!s->budget--) { s->failed_pc=0x0c09c24au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(!cond) { goto P_0c09c262; }
goto P_0c09c24e;
P_0c09c24c: /* original 2f02, guest PC 0x0c09c24c */
if(!s->budget--) { s->failed_pc=0x0c09c24cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09c24e;
P_0c09c24e: /* original 924c, guest PC 0x0c09c24e */
if(!s->budget--) { s->failed_pc=0x0c09c24eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c250;
P_0c09c250: /* original 63e3, guest PC 0x0c09c250 */
if(!s->budget--) { s->failed_pc=0x0c09c250u; return 0; }
r[3]=r[14];
goto P_0c09c252;
P_0c09c252: /* original 4308, guest PC 0x0c09c252 */
if(!s->budget--) { s->failed_pc=0x0c09c252u; return 0; }
r[3]<<=2;
goto P_0c09c254;
P_0c09c254: /* original 32dc, guest PC 0x0c09c254 */
if(!s->budget--) { s->failed_pc=0x0c09c254u; return 0; }
r[2]+=r[13];
goto P_0c09c256;
P_0c09c256: /* original 332c, guest PC 0x0c09c256 */
if(!s->budget--) { s->failed_pc=0x0c09c256u; return 0; }
r[3]+=r[2];
goto P_0c09c258;
P_0c09c258: /* original 6032, guest PC 0x0c09c258 */
if(!s->budget--) { s->failed_pc=0x0c09c258u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c25a;
P_0c09c25a: /* original cb04, guest PC 0x0c09c25a */
if(!s->budget--) { s->failed_pc=0x0c09c25au; return 0; }
r[0]|=4u;
goto P_0c09c25c;
P_0c09c25c: /* original 2302, guest PC 0x0c09c25c */
if(!s->budget--) { s->failed_pc=0x0c09c25cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c25e;
P_0c09c25e: /* original a3ca, guest PC 0x0c09c25e */
if(!s->budget--) { s->failed_pc=0x0c09c25eu; return 0; }
goto P_0c09c9f6;
P_0c09c260: /* original 0009, guest PC 0x0c09c260 */
if(!s->budget--) { s->failed_pc=0x0c09c260u; return 0; }
goto P_0c09c262;
P_0c09c262: /* original 9242, guest PC 0x0c09c262 */
if(!s->budget--) { s->failed_pc=0x0c09c262u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c264;
P_0c09c264: /* original 63e3, guest PC 0x0c09c264 */
if(!s->budget--) { s->failed_pc=0x0c09c264u; return 0; }
r[3]=r[14];
goto P_0c09c266;
P_0c09c266: /* original 4308, guest PC 0x0c09c266 */
if(!s->budget--) { s->failed_pc=0x0c09c266u; return 0; }
r[3]<<=2;
goto P_0c09c268;
P_0c09c268: /* original 32dc, guest PC 0x0c09c268 */
if(!s->budget--) { s->failed_pc=0x0c09c268u; return 0; }
r[2]+=r[13];
goto P_0c09c26a;
P_0c09c26a: /* original 332c, guest PC 0x0c09c26a */
if(!s->budget--) { s->failed_pc=0x0c09c26au; return 0; }
r[3]+=r[2];
goto P_0c09c26c;
P_0c09c26c: /* original 6132, guest PC 0x0c09c26c */
if(!s->budget--) { s->failed_pc=0x0c09c26cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c26e;
P_0c09c26e: /* original e4fb, guest PC 0x0c09c26e */
if(!s->budget--) { s->failed_pc=0x0c09c26eu; return 0; }
r[4]=0xfffffffbu;
goto P_0c09c270;
P_0c09c270: /* original 2149, guest PC 0x0c09c270 */
if(!s->budget--) { s->failed_pc=0x0c09c270u; return 0; }
r[1]&=r[4];
goto P_0c09c272;
P_0c09c272: /* original 2312, guest PC 0x0c09c272 */
if(!s->budget--) { s->failed_pc=0x0c09c272u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c274;
P_0c09c274: /* original 63e3, guest PC 0x0c09c274 */
if(!s->budget--) { s->failed_pc=0x0c09c274u; return 0; }
r[3]=r[14];
goto P_0c09c276;
P_0c09c276: /* original 9238, guest PC 0x0c09c276 */
if(!s->budget--) { s->failed_pc=0x0c09c276u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c278;
P_0c09c278: /* original 4308, guest PC 0x0c09c278 */
if(!s->budget--) { s->failed_pc=0x0c09c278u; return 0; }
r[3]<<=2;
goto P_0c09c27a;
P_0c09c27a: /* original 32dc, guest PC 0x0c09c27a */
if(!s->budget--) { s->failed_pc=0x0c09c27au; return 0; }
r[2]+=r[13];
goto P_0c09c27c;
P_0c09c27c: /* original 332c, guest PC 0x0c09c27c */
if(!s->budget--) { s->failed_pc=0x0c09c27cu; return 0; }
r[3]+=r[2];
goto P_0c09c27e;
P_0c09c27e: /* original 6132, guest PC 0x0c09c27e */
if(!s->budget--) { s->failed_pc=0x0c09c27eu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c280;
P_0c09c280: /* original 21c8, guest PC 0x0c09c280 */
if(!s->budget--) { s->failed_pc=0x0c09c280u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c09c282;
P_0c09c282: /* original 8901, guest PC 0x0c09c282 */
if(!s->budget--) { s->failed_pc=0x0c09c282u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c288; }
goto P_0c09c284;
P_0c09c284: /* original a3b7, guest PC 0x0c09c284 */
if(!s->budget--) { s->failed_pc=0x0c09c284u; return 0; }
goto P_0c09c9f6;
P_0c09c286: /* original 0009, guest PC 0x0c09c286 */
if(!s->budget--) { s->failed_pc=0x0c09c286u; return 0; }
goto P_0c09c288;
P_0c09c288: /* original 9330, guest PC 0x0c09c288 */
if(!s->budget--) { s->failed_pc=0x0c09c288u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2ecu,2);
goto P_0c09c28a;
P_0c09c28a: /* original 60e3, guest PC 0x0c09c28a */
if(!s->budget--) { s->failed_pc=0x0c09c28au; return 0; }
r[0]=r[14];
goto P_0c09c28c;
P_0c09c28c: /* original 4008, guest PC 0x0c09c28c */
if(!s->budget--) { s->failed_pc=0x0c09c28cu; return 0; }
r[0]<<=2;
goto P_0c09c28e;
P_0c09c28e: /* original 33dc, guest PC 0x0c09c28e */
if(!s->budget--) { s->failed_pc=0x0c09c28eu; return 0; }
r[3]+=r[13];
goto P_0c09c290;
P_0c09c290: /* original 003e, guest PC 0x0c09c290 */
if(!s->budget--) { s->failed_pc=0x0c09c290u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c292;
P_0c09c292: /* original 8809, guest PC 0x0c09c292 */
if(!s->budget--) { s->failed_pc=0x0c09c292u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c09c294;
P_0c09c294: /* original 8901, guest PC 0x0c09c294 */
if(!s->budget--) { s->failed_pc=0x0c09c294u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c29a; }
goto P_0c09c296;
P_0c09c296: /* original a0b9, guest PC 0x0c09c296 */
if(!s->budget--) { s->failed_pc=0x0c09c296u; return 0; }
goto P_0c09c40c;
P_0c09c298: /* original 0009, guest PC 0x0c09c298 */
if(!s->budget--) { s->failed_pc=0x0c09c298u; return 0; }
goto P_0c09c29a;
P_0c09c29a: /* original 63f2, guest PC 0x0c09c29a */
if(!s->budget--) { s->failed_pc=0x0c09c29au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09c29c;
P_0c09c29c: /* original e40c, guest PC 0x0c09c29c */
if(!s->budget--) { s->failed_pc=0x0c09c29cu; return 0; }
r[4]=0x0000000cu;
goto P_0c09c29e;
P_0c09c29e: /* original 2348, guest PC 0x0c09c29e */
if(!s->budget--) { s->failed_pc=0x0c09c29eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c09c2a0;
P_0c09c2a0: /* original 8b01, guest PC 0x0c09c2a0 */
if(!s->budget--) { s->failed_pc=0x0c09c2a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c2a6; }
goto P_0c09c2a2;
P_0c09c2a2: /* original a0b3, guest PC 0x0c09c2a2 */
if(!s->budget--) { s->failed_pc=0x0c09c2a2u; return 0; }
goto P_0c09c40c;
P_0c09c2a4: /* original 0009, guest PC 0x0c09c2a4 */
if(!s->budget--) { s->failed_pc=0x0c09c2a4u; return 0; }
goto P_0c09c2a6;
P_0c09c2a6: /* original 60f2, guest PC 0x0c09c2a6 */
if(!s->budget--) { s->failed_pc=0x0c09c2a6u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09c2a8;
P_0c09c2a8: /* original c808, guest PC 0x0c09c2a8 */
if(!s->budget--) { s->failed_pc=0x0c09c2a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09c2aa;
P_0c09c2aa: /* original 8907, guest PC 0x0c09c2aa */
if(!s->budget--) { s->failed_pc=0x0c09c2aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c2bc; }
goto P_0c09c2ac;
P_0c09c2ac: /* original 921d, guest PC 0x0c09c2ac */
if(!s->budget--) { s->failed_pc=0x0c09c2acu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c2ae;
P_0c09c2ae: /* original 63e3, guest PC 0x0c09c2ae */
if(!s->budget--) { s->failed_pc=0x0c09c2aeu; return 0; }
r[3]=r[14];
goto P_0c09c2b0;
P_0c09c2b0: /* original 4308, guest PC 0x0c09c2b0 */
if(!s->budget--) { s->failed_pc=0x0c09c2b0u; return 0; }
r[3]<<=2;
goto P_0c09c2b2;
P_0c09c2b2: /* original 32dc, guest PC 0x0c09c2b2 */
if(!s->budget--) { s->failed_pc=0x0c09c2b2u; return 0; }
r[2]+=r[13];
goto P_0c09c2b4;
P_0c09c2b4: /* original 332c, guest PC 0x0c09c2b4 */
if(!s->budget--) { s->failed_pc=0x0c09c2b4u; return 0; }
r[3]+=r[2];
goto P_0c09c2b6;
P_0c09c2b6: /* original 6032, guest PC 0x0c09c2b6 */
if(!s->budget--) { s->failed_pc=0x0c09c2b6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c2b8;
P_0c09c2b8: /* original cb08, guest PC 0x0c09c2b8 */
if(!s->budget--) { s->failed_pc=0x0c09c2b8u; return 0; }
r[0]|=8u;
goto P_0c09c2ba;
P_0c09c2ba: /* original 2302, guest PC 0x0c09c2ba */
if(!s->budget--) { s->failed_pc=0x0c09c2bau; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c2bc;
P_0c09c2bc: /* original 9215, guest PC 0x0c09c2bc */
if(!s->budget--) { s->failed_pc=0x0c09c2bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c2be;
P_0c09c2be: /* original 63e3, guest PC 0x0c09c2be */
if(!s->budget--) { s->failed_pc=0x0c09c2beu; return 0; }
r[3]=r[14];
goto P_0c09c2c0;
P_0c09c2c0: /* original 4308, guest PC 0x0c09c2c0 */
if(!s->budget--) { s->failed_pc=0x0c09c2c0u; return 0; }
r[3]<<=2;
goto P_0c09c2c2;
P_0c09c2c2: /* original 32dc, guest PC 0x0c09c2c2 */
if(!s->budget--) { s->failed_pc=0x0c09c2c2u; return 0; }
r[2]+=r[13];
goto P_0c09c2c4;
P_0c09c2c4: /* original 332c, guest PC 0x0c09c2c4 */
if(!s->budget--) { s->failed_pc=0x0c09c2c4u; return 0; }
r[3]+=r[2];
goto P_0c09c2c6;
P_0c09c2c6: /* original 6132, guest PC 0x0c09c2c6 */
if(!s->budget--) { s->failed_pc=0x0c09c2c6u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c2c8;
P_0c09c2c8: /* original 21c8, guest PC 0x0c09c2c8 */
if(!s->budget--) { s->failed_pc=0x0c09c2c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c09c2ca;
P_0c09c2ca: /* original 8901, guest PC 0x0c09c2ca */
if(!s->budget--) { s->failed_pc=0x0c09c2cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c2d0; }
goto P_0c09c2cc;
P_0c09c2cc: /* original a096, guest PC 0x0c09c2cc */
if(!s->budget--) { s->failed_pc=0x0c09c2ccu; return 0; }
goto P_0c09c3fc;
P_0c09c2ce: /* original 0009, guest PC 0x0c09c2ce */
if(!s->budget--) { s->failed_pc=0x0c09c2ceu; return 0; }
goto P_0c09c2d0;
P_0c09c2d0: /* original 930d, guest PC 0x0c09c2d0 */
if(!s->budget--) { s->failed_pc=0x0c09c2d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eeu,2);
goto P_0c09c2d2;
P_0c09c2d2: /* original 62e3, guest PC 0x0c09c2d2 */
if(!s->budget--) { s->failed_pc=0x0c09c2d2u; return 0; }
r[2]=r[14];
goto P_0c09c2d4;
P_0c09c2d4: /* original 4208, guest PC 0x0c09c2d4 */
if(!s->budget--) { s->failed_pc=0x0c09c2d4u; return 0; }
r[2]<<=2;
goto P_0c09c2d6;
P_0c09c2d6: /* original 33dc, guest PC 0x0c09c2d6 */
if(!s->budget--) { s->failed_pc=0x0c09c2d6u; return 0; }
r[3]+=r[13];
goto P_0c09c2d8;
P_0c09c2d8: /* original 323c, guest PC 0x0c09c2d8 */
if(!s->budget--) { s->failed_pc=0x0c09c2d8u; return 0; }
r[2]+=r[3];
goto P_0c09c2da;
P_0c09c2da: /* original 6122, guest PC 0x0c09c2da */
if(!s->budget--) { s->failed_pc=0x0c09c2dau; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c2dc;
P_0c09c2dc: /* original 2118, guest PC 0x0c09c2dc */
if(!s->budget--) { s->failed_pc=0x0c09c2dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c2de;
P_0c09c2de: /* original 8b11, guest PC 0x0c09c2de */
if(!s->budget--) { s->failed_pc=0x0c09c2deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c304; }
goto P_0c09c2e0;
P_0c09c2e0: /* original d307, guest PC 0x0c09c2e0 */
if(!s->budget--) { s->failed_pc=0x0c09c2e0u; return 0; }
r[3]=read(ram,0x0c09c300u,4);
goto P_0c09c2e2;
P_0c09c2e2: /* original 430b, guest PC 0x0c09c2e2 */
if(!s->budget--) { s->failed_pc=0x0c09c2e2u; return 0; }
target=r[3];
r[16]=0x0c09c2e6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c2e6u) { target=s->pc; goto dispatch; }
goto P_0c09c2e6;
P_0c09c2e4: /* original 64e3, guest PC 0x0c09c2e4 */
if(!s->budget--) { s->failed_pc=0x0c09c2e4u; return 0; }
r[4]=r[14];
goto P_0c09c2e6;
P_0c09c2e6: /* original a086, guest PC 0x0c09c2e6 */
if(!s->budget--) { s->failed_pc=0x0c09c2e6u; return 0; }
goto P_0c09c3f6;
P_0c09c2e8: /* original 0009, guest PC 0x0c09c2e8 */
if(!s->budget--) { s->failed_pc=0x0c09c2e8u; return 0; }
return vf3_matrix_family(0x0c09c2eau,s,ram);
P_0c09c304: /* original 53f1, guest PC 0x0c09c304 */
if(!s->budget--) { s->failed_pc=0x0c09c304u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c306;
P_0c09c306: /* original e501, guest PC 0x0c09c306 */
if(!s->budget--) { s->failed_pc=0x0c09c306u; return 0; }
r[5]=0x00000001u;
goto P_0c09c308;
P_0c09c308: /* original 2f36, guest PC 0x0c09c308 */
if(!s->budget--) { s->failed_pc=0x0c09c308u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c30a;
P_0c09c30a: /* original be4d, guest PC 0x0c09c30a */
if(!s->budget--) { s->failed_pc=0x0c09c30au; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c30eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c30eu) { target=s->pc; goto dispatch; }
goto P_0c09c30e;
P_0c09c30c: /* original 64e3, guest PC 0x0c09c30c */
if(!s->budget--) { s->failed_pc=0x0c09c30cu; return 0; }
r[4]=r[14];
goto P_0c09c30e;
P_0c09c30e: /* original e520, guest PC 0x0c09c30e */
if(!s->budget--) { s->failed_pc=0x0c09c30eu; return 0; }
r[5]=0x00000020u;
goto P_0c09c310;
P_0c09c310: /* original 2f06, guest PC 0x0c09c310 */
if(!s->budget--) { s->failed_pc=0x0c09c310u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c312;
P_0c09c312: /* original be49, guest PC 0x0c09c312 */
if(!s->budget--) { s->failed_pc=0x0c09c312u; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c316u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c316u) { target=s->pc; goto dispatch; }
goto P_0c09c316;
P_0c09c314: /* original 64e3, guest PC 0x0c09c314 */
if(!s->budget--) { s->failed_pc=0x0c09c314u; return 0; }
r[4]=r[14];
goto P_0c09c316;
P_0c09c316: /* original 63f6, guest PC 0x0c09c316 */
if(!s->budget--) { s->failed_pc=0x0c09c316u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c318;
P_0c09c318: /* original e540, guest PC 0x0c09c318 */
if(!s->budget--) { s->failed_pc=0x0c09c318u; return 0; }
r[5]=0x00000040u;
goto P_0c09c31a;
P_0c09c31a: /* original 203b, guest PC 0x0c09c31a */
if(!s->budget--) { s->failed_pc=0x0c09c31au; return 0; }
r[0]|=r[3];
goto P_0c09c31c;
P_0c09c31c: /* original 2f06, guest PC 0x0c09c31c */
if(!s->budget--) { s->failed_pc=0x0c09c31cu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c31e;
P_0c09c31e: /* original be43, guest PC 0x0c09c31e */
if(!s->budget--) { s->failed_pc=0x0c09c31eu; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c322u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c322u) { target=s->pc; goto dispatch; }
goto P_0c09c322;
P_0c09c320: /* original 64e3, guest PC 0x0c09c320 */
if(!s->budget--) { s->failed_pc=0x0c09c320u; return 0; }
r[4]=r[14];
goto P_0c09c322;
P_0c09c322: /* original 63f6, guest PC 0x0c09c322 */
if(!s->budget--) { s->failed_pc=0x0c09c322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c324;
P_0c09c324: /* original 203b, guest PC 0x0c09c324 */
if(!s->budget--) { s->failed_pc=0x0c09c324u; return 0; }
r[0]|=r[3];
goto P_0c09c326;
P_0c09c326: /* original 2f06, guest PC 0x0c09c326 */
if(!s->budget--) { s->failed_pc=0x0c09c326u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c328;
P_0c09c328: /* original 958f, guest PC 0x0c09c328 */
if(!s->budget--) { s->failed_pc=0x0c09c328u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44au,2);
goto P_0c09c32a;
P_0c09c32a: /* original be3d, guest PC 0x0c09c32a */
if(!s->budget--) { s->failed_pc=0x0c09c32au; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c32eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c32eu) { target=s->pc; goto dispatch; }
goto P_0c09c32e;
P_0c09c32c: /* original 64e3, guest PC 0x0c09c32c */
if(!s->budget--) { s->failed_pc=0x0c09c32cu; return 0; }
r[4]=r[14];
goto P_0c09c32e;
P_0c09c32e: /* original 63f6, guest PC 0x0c09c32e */
if(!s->budget--) { s->failed_pc=0x0c09c32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c330;
P_0c09c330: /* original 203b, guest PC 0x0c09c330 */
if(!s->budget--) { s->failed_pc=0x0c09c330u; return 0; }
r[0]|=r[3];
goto P_0c09c332;
P_0c09c332: /* original 2f06, guest PC 0x0c09c332 */
if(!s->budget--) { s->failed_pc=0x0c09c332u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c334;
P_0c09c334: /* original 958a, guest PC 0x0c09c334 */
if(!s->budget--) { s->failed_pc=0x0c09c334u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44cu,2);
goto P_0c09c336;
P_0c09c336: /* original be37, guest PC 0x0c09c336 */
if(!s->budget--) { s->failed_pc=0x0c09c336u; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c33au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c33au) { target=s->pc; goto dispatch; }
goto P_0c09c33a;
P_0c09c338: /* original 64e3, guest PC 0x0c09c338 */
if(!s->budget--) { s->failed_pc=0x0c09c338u; return 0; }
r[4]=r[14];
goto P_0c09c33a;
P_0c09c33a: /* original 63f6, guest PC 0x0c09c33a */
if(!s->budget--) { s->failed_pc=0x0c09c33au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c33c;
P_0c09c33c: /* original e502, guest PC 0x0c09c33c */
if(!s->budget--) { s->failed_pc=0x0c09c33cu; return 0; }
r[5]=0x00000002u;
goto P_0c09c33e;
P_0c09c33e: /* original 62f6, guest PC 0x0c09c33e */
if(!s->budget--) { s->failed_pc=0x0c09c33eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c340;
P_0c09c340: /* original 203b, guest PC 0x0c09c340 */
if(!s->budget--) { s->failed_pc=0x0c09c340u; return 0; }
r[0]|=r[3];
goto P_0c09c342;
P_0c09c342: /* original 2202, guest PC 0x0c09c342 */
if(!s->budget--) { s->failed_pc=0x0c09c342u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c344;
P_0c09c344: /* original e204, guest PC 0x0c09c344 */
if(!s->budget--) { s->failed_pc=0x0c09c344u; return 0; }
r[2]=0x00000004u;
goto P_0c09c346;
P_0c09c346: /* original 53f1, guest PC 0x0c09c346 */
if(!s->budget--) { s->failed_pc=0x0c09c346u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c348;
P_0c09c348: /* original 323c, guest PC 0x0c09c348 */
if(!s->budget--) { s->failed_pc=0x0c09c348u; return 0; }
r[2]+=r[3];
goto P_0c09c34a;
P_0c09c34a: /* original 2f26, guest PC 0x0c09c34a */
if(!s->budget--) { s->failed_pc=0x0c09c34au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c34c;
P_0c09c34c: /* original be2c, guest PC 0x0c09c34c */
if(!s->budget--) { s->failed_pc=0x0c09c34cu; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c350u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c350u) { target=s->pc; goto dispatch; }
goto P_0c09c350;
P_0c09c34e: /* original 64e3, guest PC 0x0c09c34e */
if(!s->budget--) { s->failed_pc=0x0c09c34eu; return 0; }
r[4]=r[14];
goto P_0c09c350;
P_0c09c350: /* original 2f06, guest PC 0x0c09c350 */
if(!s->budget--) { s->failed_pc=0x0c09c350u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c352;
P_0c09c352: /* original 957c, guest PC 0x0c09c352 */
if(!s->budget--) { s->failed_pc=0x0c09c352u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44eu,2);
goto P_0c09c354;
P_0c09c354: /* original be28, guest PC 0x0c09c354 */
if(!s->budget--) { s->failed_pc=0x0c09c354u; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c358u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c358u) { target=s->pc; goto dispatch; }
goto P_0c09c358;
P_0c09c356: /* original 64e3, guest PC 0x0c09c356 */
if(!s->budget--) { s->failed_pc=0x0c09c356u; return 0; }
r[4]=r[14];
goto P_0c09c358;
P_0c09c358: /* original 63f6, guest PC 0x0c09c358 */
if(!s->budget--) { s->failed_pc=0x0c09c358u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c35a;
P_0c09c35a: /* original 6583, guest PC 0x0c09c35a */
if(!s->budget--) { s->failed_pc=0x0c09c35au; return 0; }
r[5]=r[8];
goto P_0c09c35c;
P_0c09c35c: /* original 203b, guest PC 0x0c09c35c */
if(!s->budget--) { s->failed_pc=0x0c09c35cu; return 0; }
r[0]|=r[3];
goto P_0c09c35e;
P_0c09c35e: /* original 2f06, guest PC 0x0c09c35e */
if(!s->budget--) { s->failed_pc=0x0c09c35eu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c360;
P_0c09c360: /* original be22, guest PC 0x0c09c360 */
if(!s->budget--) { s->failed_pc=0x0c09c360u; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c364u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c364u) { target=s->pc; goto dispatch; }
goto P_0c09c364;
P_0c09c362: /* original 64e3, guest PC 0x0c09c362 */
if(!s->budget--) { s->failed_pc=0x0c09c362u; return 0; }
r[4]=r[14];
goto P_0c09c364;
P_0c09c364: /* original 63f6, guest PC 0x0c09c364 */
if(!s->budget--) { s->failed_pc=0x0c09c364u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c366;
P_0c09c366: /* original 203b, guest PC 0x0c09c366 */
if(!s->budget--) { s->failed_pc=0x0c09c366u; return 0; }
r[0]|=r[3];
goto P_0c09c368;
P_0c09c368: /* original 2f06, guest PC 0x0c09c368 */
if(!s->budget--) { s->failed_pc=0x0c09c368u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c36a;
P_0c09c36a: /* original 956e, guest PC 0x0c09c36a */
if(!s->budget--) { s->failed_pc=0x0c09c36au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44au,2);
goto P_0c09c36c;
P_0c09c36c: /* original be1c, guest PC 0x0c09c36c */
if(!s->budget--) { s->failed_pc=0x0c09c36cu; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c370u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c370u) { target=s->pc; goto dispatch; }
goto P_0c09c370;
P_0c09c36e: /* original 64e3, guest PC 0x0c09c36e */
if(!s->budget--) { s->failed_pc=0x0c09c36eu; return 0; }
r[4]=r[14];
goto P_0c09c370;
P_0c09c370: /* original 63f6, guest PC 0x0c09c370 */
if(!s->budget--) { s->failed_pc=0x0c09c370u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c372;
P_0c09c372: /* original 203b, guest PC 0x0c09c372 */
if(!s->budget--) { s->failed_pc=0x0c09c372u; return 0; }
r[0]|=r[3];
goto P_0c09c374;
P_0c09c374: /* original 2f06, guest PC 0x0c09c374 */
if(!s->budget--) { s->failed_pc=0x0c09c374u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c376;
P_0c09c376: /* original 9569, guest PC 0x0c09c376 */
if(!s->budget--) { s->failed_pc=0x0c09c376u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44cu,2);
goto P_0c09c378;
P_0c09c378: /* original be16, guest PC 0x0c09c378 */
if(!s->budget--) { s->failed_pc=0x0c09c378u; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c37cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c37cu) { target=s->pc; goto dispatch; }
goto P_0c09c37c;
P_0c09c37a: /* original 64e3, guest PC 0x0c09c37a */
if(!s->budget--) { s->failed_pc=0x0c09c37au; return 0; }
r[4]=r[14];
goto P_0c09c37c;
P_0c09c37c: /* original 63f6, guest PC 0x0c09c37c */
if(!s->budget--) { s->failed_pc=0x0c09c37cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c37e;
P_0c09c37e: /* original e208, guest PC 0x0c09c37e */
if(!s->budget--) { s->failed_pc=0x0c09c37eu; return 0; }
r[2]=0x00000008u;
goto P_0c09c380;
P_0c09c380: /* original e504, guest PC 0x0c09c380 */
if(!s->budget--) { s->failed_pc=0x0c09c380u; return 0; }
r[5]=0x00000004u;
goto P_0c09c382;
P_0c09c382: /* original 61f6, guest PC 0x0c09c382 */
if(!s->budget--) { s->failed_pc=0x0c09c382u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c09c384;
P_0c09c384: /* original 203b, guest PC 0x0c09c384 */
if(!s->budget--) { s->failed_pc=0x0c09c384u; return 0; }
r[0]|=r[3];
goto P_0c09c386;
P_0c09c386: /* original 2102, guest PC 0x0c09c386 */
if(!s->budget--) { s->failed_pc=0x0c09c386u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c09c388;
P_0c09c388: /* original 53f1, guest PC 0x0c09c388 */
if(!s->budget--) { s->failed_pc=0x0c09c388u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c38a;
P_0c09c38a: /* original 323c, guest PC 0x0c09c38a */
if(!s->budget--) { s->failed_pc=0x0c09c38au; return 0; }
r[2]+=r[3];
goto P_0c09c38c;
P_0c09c38c: /* original 2f26, guest PC 0x0c09c38c */
if(!s->budget--) { s->failed_pc=0x0c09c38cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c38e;
P_0c09c38e: /* original be0b, guest PC 0x0c09c38e */
if(!s->budget--) { s->failed_pc=0x0c09c38eu; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c392u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c392u) { target=s->pc; goto dispatch; }
goto P_0c09c392;
P_0c09c390: /* original 64e3, guest PC 0x0c09c390 */
if(!s->budget--) { s->failed_pc=0x0c09c390u; return 0; }
r[4]=r[14];
goto P_0c09c392;
P_0c09c392: /* original e520, guest PC 0x0c09c392 */
if(!s->budget--) { s->failed_pc=0x0c09c392u; return 0; }
r[5]=0x00000020u;
goto P_0c09c394;
P_0c09c394: /* original 2f06, guest PC 0x0c09c394 */
if(!s->budget--) { s->failed_pc=0x0c09c394u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c396;
P_0c09c396: /* original be07, guest PC 0x0c09c396 */
if(!s->budget--) { s->failed_pc=0x0c09c396u; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c39au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c39au) { target=s->pc; goto dispatch; }
goto P_0c09c39a;
P_0c09c398: /* original 64e3, guest PC 0x0c09c398 */
if(!s->budget--) { s->failed_pc=0x0c09c398u; return 0; }
r[4]=r[14];
goto P_0c09c39a;
P_0c09c39a: /* original 63f6, guest PC 0x0c09c39a */
if(!s->budget--) { s->failed_pc=0x0c09c39au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c39c;
P_0c09c39c: /* original 203b, guest PC 0x0c09c39c */
if(!s->budget--) { s->failed_pc=0x0c09c39cu; return 0; }
r[0]|=r[3];
goto P_0c09c39e;
P_0c09c39e: /* original 2f06, guest PC 0x0c09c39e */
if(!s->budget--) { s->failed_pc=0x0c09c39eu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3a0;
P_0c09c3a0: /* original 9555, guest PC 0x0c09c3a0 */
if(!s->budget--) { s->failed_pc=0x0c09c3a0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44eu,2);
goto P_0c09c3a2;
P_0c09c3a2: /* original be01, guest PC 0x0c09c3a2 */
if(!s->budget--) { s->failed_pc=0x0c09c3a2u; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c3a6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c3a6u) { target=s->pc; goto dispatch; }
goto P_0c09c3a6;
P_0c09c3a4: /* original 64e3, guest PC 0x0c09c3a4 */
if(!s->budget--) { s->failed_pc=0x0c09c3a4u; return 0; }
r[4]=r[14];
goto P_0c09c3a6;
P_0c09c3a6: /* original 63f6, guest PC 0x0c09c3a6 */
if(!s->budget--) { s->failed_pc=0x0c09c3a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c3a8;
P_0c09c3a8: /* original 203b, guest PC 0x0c09c3a8 */
if(!s->budget--) { s->failed_pc=0x0c09c3a8u; return 0; }
r[0]|=r[3];
goto P_0c09c3aa;
P_0c09c3aa: /* original 2f06, guest PC 0x0c09c3aa */
if(!s->budget--) { s->failed_pc=0x0c09c3aau; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3ac;
P_0c09c3ac: /* original 954e, guest PC 0x0c09c3ac */
if(!s->budget--) { s->failed_pc=0x0c09c3acu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44cu,2);
goto P_0c09c3ae;
P_0c09c3ae: /* original bdfb, guest PC 0x0c09c3ae */
if(!s->budget--) { s->failed_pc=0x0c09c3aeu; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c3b2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c3b2u) { target=s->pc; goto dispatch; }
goto P_0c09c3b2;
P_0c09c3b0: /* original 64e3, guest PC 0x0c09c3b0 */
if(!s->budget--) { s->failed_pc=0x0c09c3b0u; return 0; }
r[4]=r[14];
goto P_0c09c3b2;
P_0c09c3b2: /* original 63f6, guest PC 0x0c09c3b2 */
if(!s->budget--) { s->failed_pc=0x0c09c3b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c3b4;
P_0c09c3b4: /* original e20c, guest PC 0x0c09c3b4 */
if(!s->budget--) { s->failed_pc=0x0c09c3b4u; return 0; }
r[2]=0x0000000cu;
goto P_0c09c3b6;
P_0c09c3b6: /* original e508, guest PC 0x0c09c3b6 */
if(!s->budget--) { s->failed_pc=0x0c09c3b6u; return 0; }
r[5]=0x00000008u;
goto P_0c09c3b8;
P_0c09c3b8: /* original 61f6, guest PC 0x0c09c3b8 */
if(!s->budget--) { s->failed_pc=0x0c09c3b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c09c3ba;
P_0c09c3ba: /* original 203b, guest PC 0x0c09c3ba */
if(!s->budget--) { s->failed_pc=0x0c09c3bau; return 0; }
r[0]|=r[3];
goto P_0c09c3bc;
P_0c09c3bc: /* original 2102, guest PC 0x0c09c3bc */
if(!s->budget--) { s->failed_pc=0x0c09c3bcu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c09c3be;
P_0c09c3be: /* original 53f1, guest PC 0x0c09c3be */
if(!s->budget--) { s->failed_pc=0x0c09c3beu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c3c0;
P_0c09c3c0: /* original 323c, guest PC 0x0c09c3c0 */
if(!s->budget--) { s->failed_pc=0x0c09c3c0u; return 0; }
r[2]+=r[3];
goto P_0c09c3c2;
P_0c09c3c2: /* original 2f26, guest PC 0x0c09c3c2 */
if(!s->budget--) { s->failed_pc=0x0c09c3c2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3c4;
P_0c09c3c4: /* original bdf0, guest PC 0x0c09c3c4 */
if(!s->budget--) { s->failed_pc=0x0c09c3c4u; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c3c8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c3c8u) { target=s->pc; goto dispatch; }
goto P_0c09c3c8;
P_0c09c3c6: /* original 64e3, guest PC 0x0c09c3c6 */
if(!s->budget--) { s->failed_pc=0x0c09c3c6u; return 0; }
r[4]=r[14];
goto P_0c09c3c8;
P_0c09c3c8: /* original e540, guest PC 0x0c09c3c8 */
if(!s->budget--) { s->failed_pc=0x0c09c3c8u; return 0; }
r[5]=0x00000040u;
goto P_0c09c3ca;
P_0c09c3ca: /* original 2f06, guest PC 0x0c09c3ca */
if(!s->budget--) { s->failed_pc=0x0c09c3cau; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3cc;
P_0c09c3cc: /* original bdec, guest PC 0x0c09c3cc */
if(!s->budget--) { s->failed_pc=0x0c09c3ccu; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c3d0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c3d0u) { target=s->pc; goto dispatch; }
goto P_0c09c3d0;
P_0c09c3ce: /* original 64e3, guest PC 0x0c09c3ce */
if(!s->budget--) { s->failed_pc=0x0c09c3ceu; return 0; }
r[4]=r[14];
goto P_0c09c3d0;
P_0c09c3d0: /* original 63f6, guest PC 0x0c09c3d0 */
if(!s->budget--) { s->failed_pc=0x0c09c3d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c3d2;
P_0c09c3d2: /* original 6583, guest PC 0x0c09c3d2 */
if(!s->budget--) { s->failed_pc=0x0c09c3d2u; return 0; }
r[5]=r[8];
goto P_0c09c3d4;
P_0c09c3d4: /* original 203b, guest PC 0x0c09c3d4 */
if(!s->budget--) { s->failed_pc=0x0c09c3d4u; return 0; }
r[0]|=r[3];
goto P_0c09c3d6;
P_0c09c3d6: /* original 2f06, guest PC 0x0c09c3d6 */
if(!s->budget--) { s->failed_pc=0x0c09c3d6u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3d8;
P_0c09c3d8: /* original bde6, guest PC 0x0c09c3d8 */
if(!s->budget--) { s->failed_pc=0x0c09c3d8u; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c3dcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c3dcu) { target=s->pc; goto dispatch; }
goto P_0c09c3dc;
P_0c09c3da: /* original 64e3, guest PC 0x0c09c3da */
if(!s->budget--) { s->failed_pc=0x0c09c3dau; return 0; }
r[4]=r[14];
goto P_0c09c3dc;
P_0c09c3dc: /* original 63f6, guest PC 0x0c09c3dc */
if(!s->budget--) { s->failed_pc=0x0c09c3dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c3de;
P_0c09c3de: /* original e210, guest PC 0x0c09c3de */
if(!s->budget--) { s->failed_pc=0x0c09c3deu; return 0; }
r[2]=0x00000010u;
goto P_0c09c3e0;
P_0c09c3e0: /* original e510, guest PC 0x0c09c3e0 */
if(!s->budget--) { s->failed_pc=0x0c09c3e0u; return 0; }
r[5]=0x00000010u;
goto P_0c09c3e2;
P_0c09c3e2: /* original 61f6, guest PC 0x0c09c3e2 */
if(!s->budget--) { s->failed_pc=0x0c09c3e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c09c3e4;
P_0c09c3e4: /* original 203b, guest PC 0x0c09c3e4 */
if(!s->budget--) { s->failed_pc=0x0c09c3e4u; return 0; }
r[0]|=r[3];
goto P_0c09c3e6;
P_0c09c3e6: /* original 2102, guest PC 0x0c09c3e6 */
if(!s->budget--) { s->failed_pc=0x0c09c3e6u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c09c3e8;
P_0c09c3e8: /* original 53f1, guest PC 0x0c09c3e8 */
if(!s->budget--) { s->failed_pc=0x0c09c3e8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c3ea;
P_0c09c3ea: /* original 323c, guest PC 0x0c09c3ea */
if(!s->budget--) { s->failed_pc=0x0c09c3eau; return 0; }
r[2]+=r[3];
goto P_0c09c3ec;
P_0c09c3ec: /* original 2f26, guest PC 0x0c09c3ec */
if(!s->budget--) { s->failed_pc=0x0c09c3ecu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3ee;
P_0c09c3ee: /* original bddb, guest PC 0x0c09c3ee */
if(!s->budget--) { s->failed_pc=0x0c09c3eeu; return 0; }
target=0x0c09bfa8u; r[16]=0x0c09c3f2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c3f2u) { target=s->pc; goto dispatch; }
goto P_0c09c3f2;
P_0c09c3f0: /* original 64e3, guest PC 0x0c09c3f0 */
if(!s->budget--) { s->failed_pc=0x0c09c3f0u; return 0; }
r[4]=r[14];
goto P_0c09c3f2;
P_0c09c3f2: /* original 61f6, guest PC 0x0c09c3f2 */
if(!s->budget--) { s->failed_pc=0x0c09c3f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c09c3f4;
P_0c09c3f4: /* original 2102, guest PC 0x0c09c3f4 */
if(!s->budget--) { s->failed_pc=0x0c09c3f4u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c09c3f6;
P_0c09c3f6: /* original 942b, guest PC 0x0c09c3f6 */
if(!s->budget--) { s->failed_pc=0x0c09c3f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c450u,2);
goto P_0c09c3f8;
P_0c09c3f8: /* original 4a0b, guest PC 0x0c09c3f8 */
if(!s->budget--) { s->failed_pc=0x0c09c3f8u; return 0; }
target=r[10];
r[16]=0x0c09c3fcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c3fcu) { target=s->pc; goto dispatch; }
goto P_0c09c3fc;
P_0c09c3fa: /* original 0009, guest PC 0x0c09c3fa */
if(!s->budget--) { s->failed_pc=0x0c09c3fau; return 0; }
goto P_0c09c3fc;
P_0c09c3fc: /* original 9229, guest PC 0x0c09c3fc */
if(!s->budget--) { s->failed_pc=0x0c09c3fcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c452u,2);
goto P_0c09c3fe;
P_0c09c3fe: /* original 63e3, guest PC 0x0c09c3fe */
if(!s->budget--) { s->failed_pc=0x0c09c3feu; return 0; }
r[3]=r[14];
goto P_0c09c400;
P_0c09c400: /* original 4308, guest PC 0x0c09c400 */
if(!s->budget--) { s->failed_pc=0x0c09c400u; return 0; }
r[3]<<=2;
goto P_0c09c402;
P_0c09c402: /* original 32dc, guest PC 0x0c09c402 */
if(!s->budget--) { s->failed_pc=0x0c09c402u; return 0; }
r[2]+=r[13];
goto P_0c09c404;
P_0c09c404: /* original 332c, guest PC 0x0c09c404 */
if(!s->budget--) { s->failed_pc=0x0c09c404u; return 0; }
r[3]+=r[2];
goto P_0c09c406;
P_0c09c406: /* original 6132, guest PC 0x0c09c406 */
if(!s->budget--) { s->failed_pc=0x0c09c406u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c408;
P_0c09c408: /* original 21cb, guest PC 0x0c09c408 */
if(!s->budget--) { s->failed_pc=0x0c09c408u; return 0; }
r[1]|=r[12];
goto P_0c09c40a;
P_0c09c40a: /* original 2312, guest PC 0x0c09c40a */
if(!s->budget--) { s->failed_pc=0x0c09c40au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c40c;
P_0c09c40c: /* original 63f2, guest PC 0x0c09c40c */
if(!s->budget--) { s->failed_pc=0x0c09c40cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09c40e;
P_0c09c40e: /* original e410, guest PC 0x0c09c40e */
if(!s->budget--) { s->failed_pc=0x0c09c40eu; return 0; }
r[4]=0x00000010u;
goto P_0c09c410;
P_0c09c410: /* original 2348, guest PC 0x0c09c410 */
if(!s->budget--) { s->failed_pc=0x0c09c410u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c09c412;
P_0c09c412: /* original 8b01, guest PC 0x0c09c412 */
if(!s->budget--) { s->failed_pc=0x0c09c412u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c418; }
goto P_0c09c414;
P_0c09c414: /* original a07d, guest PC 0x0c09c414 */
if(!s->budget--) { s->failed_pc=0x0c09c414u; return 0; }
goto P_0c09c512;
P_0c09c416: /* original 0009, guest PC 0x0c09c416 */
if(!s->budget--) { s->failed_pc=0x0c09c416u; return 0; }
goto P_0c09c418;
P_0c09c418: /* original 4a0b, guest PC 0x0c09c418 */
if(!s->budget--) { s->failed_pc=0x0c09c418u; return 0; }
target=r[10];
r[16]=0x0c09c41cu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c41cu) { target=s->pc; goto dispatch; }
goto P_0c09c41c;
P_0c09c41a: /* original 64b3, guest PC 0x0c09c41a */
if(!s->budget--) { s->failed_pc=0x0c09c41au; return 0; }
r[4]=r[11];
goto P_0c09c41c;
P_0c09c41c: /* original 921a, guest PC 0x0c09c41c */
if(!s->budget--) { s->failed_pc=0x0c09c41cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c454u,2);
goto P_0c09c41e;
P_0c09c41e: /* original 63e3, guest PC 0x0c09c41e */
if(!s->budget--) { s->failed_pc=0x0c09c41eu; return 0; }
r[3]=r[14];
goto P_0c09c420;
P_0c09c420: /* original 4308, guest PC 0x0c09c420 */
if(!s->budget--) { s->failed_pc=0x0c09c420u; return 0; }
r[3]<<=2;
goto P_0c09c422;
P_0c09c422: /* original 32dc, guest PC 0x0c09c422 */
if(!s->budget--) { s->failed_pc=0x0c09c422u; return 0; }
r[2]+=r[13];
goto P_0c09c424;
P_0c09c424: /* original 332c, guest PC 0x0c09c424 */
if(!s->budget--) { s->failed_pc=0x0c09c424u; return 0; }
r[3]+=r[2];
goto P_0c09c426;
P_0c09c426: /* original 6132, guest PC 0x0c09c426 */
if(!s->budget--) { s->failed_pc=0x0c09c426u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c428;
P_0c09c428: /* original 2118, guest PC 0x0c09c428 */
if(!s->budget--) { s->failed_pc=0x0c09c428u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c42a;
P_0c09c42a: /* original 8b15, guest PC 0x0c09c42a */
if(!s->budget--) { s->failed_pc=0x0c09c42au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c458; }
goto P_0c09c42c;
P_0c09c42c: /* original 9313, guest PC 0x0c09c42c */
if(!s->budget--) { s->failed_pc=0x0c09c42cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c456u,2);
goto P_0c09c42e;
P_0c09c42e: /* original 61e3, guest PC 0x0c09c42e */
if(!s->budget--) { s->failed_pc=0x0c09c42eu; return 0; }
r[1]=r[14];
goto P_0c09c430;
P_0c09c430: /* original 4108, guest PC 0x0c09c430 */
if(!s->budget--) { s->failed_pc=0x0c09c430u; return 0; }
r[1]<<=2;
goto P_0c09c432;
P_0c09c432: /* original 33dc, guest PC 0x0c09c432 */
if(!s->budget--) { s->failed_pc=0x0c09c432u; return 0; }
r[3]+=r[13];
goto P_0c09c434;
P_0c09c434: /* original 313c, guest PC 0x0c09c434 */
if(!s->budget--) { s->failed_pc=0x0c09c434u; return 0; }
r[1]+=r[3];
goto P_0c09c436;
P_0c09c436: /* original 6212, guest PC 0x0c09c436 */
if(!s->budget--) { s->failed_pc=0x0c09c436u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09c438;
P_0c09c438: /* original 4215, guest PC 0x0c09c438 */
if(!s->budget--) { s->failed_pc=0x0c09c438u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c09c43a;
P_0c09c43a: /* original 8b63, guest PC 0x0c09c43a */
if(!s->budget--) { s->failed_pc=0x0c09c43au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c504; }
goto P_0c09c43c;
P_0c09c43c: /* original 930b, guest PC 0x0c09c43c */
if(!s->budget--) { s->failed_pc=0x0c09c43cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c456u,2);
goto P_0c09c43e;
P_0c09c43e: /* original 61e3, guest PC 0x0c09c43e */
if(!s->budget--) { s->failed_pc=0x0c09c43eu; return 0; }
r[1]=r[14];
goto P_0c09c440;
P_0c09c440: /* original 4108, guest PC 0x0c09c440 */
if(!s->budget--) { s->failed_pc=0x0c09c440u; return 0; }
r[1]<<=2;
goto P_0c09c442;
P_0c09c442: /* original 33dc, guest PC 0x0c09c442 */
if(!s->budget--) { s->failed_pc=0x0c09c442u; return 0; }
r[3]+=r[13];
goto P_0c09c444;
P_0c09c444: /* original 313c, guest PC 0x0c09c444 */
if(!s->budget--) { s->failed_pc=0x0c09c444u; return 0; }
r[1]+=r[3];
goto P_0c09c446;
P_0c09c446: /* original a064, guest PC 0x0c09c446 */
if(!s->budget--) { s->failed_pc=0x0c09c446u; return 0; }
write(ram,r[1],r[9],4);
goto P_0c09c512;
P_0c09c448: /* original 2192, guest PC 0x0c09c448 */
if(!s->budget--) { s->failed_pc=0x0c09c448u; return 0; }
write(ram,r[1],r[9],4);
return vf3_matrix_family(0x0c09c44au,s,ram);
P_0c09c458: /* original 9280, guest PC 0x0c09c458 */
if(!s->budget--) { s->failed_pc=0x0c09c458u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c45a;
P_0c09c45a: /* original 63e3, guest PC 0x0c09c45a */
if(!s->budget--) { s->failed_pc=0x0c09c45au; return 0; }
r[3]=r[14];
goto P_0c09c45c;
P_0c09c45c: /* original 4308, guest PC 0x0c09c45c */
if(!s->budget--) { s->failed_pc=0x0c09c45cu; return 0; }
r[3]<<=2;
goto P_0c09c45e;
P_0c09c45e: /* original 32dc, guest PC 0x0c09c45e */
if(!s->budget--) { s->failed_pc=0x0c09c45eu; return 0; }
r[2]+=r[13];
goto P_0c09c460;
P_0c09c460: /* original 332c, guest PC 0x0c09c460 */
if(!s->budget--) { s->failed_pc=0x0c09c460u; return 0; }
r[3]+=r[2];
goto P_0c09c462;
P_0c09c462: /* original 6132, guest PC 0x0c09c462 */
if(!s->budget--) { s->failed_pc=0x0c09c462u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c464;
P_0c09c464: /* original 71ff, guest PC 0x0c09c464 */
if(!s->budget--) { s->failed_pc=0x0c09c464u; return 0; }
r[1]+=0xffffffffu;
goto P_0c09c466;
P_0c09c466: /* original 2312, guest PC 0x0c09c466 */
if(!s->budget--) { s->failed_pc=0x0c09c466u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c468;
P_0c09c468: /* original 53f2, guest PC 0x0c09c468 */
if(!s->budget--) { s->failed_pc=0x0c09c468u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09c46a;
P_0c09c46a: /* original d23e, guest PC 0x0c09c46a */
if(!s->budget--) { s->failed_pc=0x0c09c46au; return 0; }
r[2]=read(ram,0x0c09c564u,4);
goto P_0c09c46c;
P_0c09c46c: /* original 6132, guest PC 0x0c09c46c */
if(!s->budget--) { s->failed_pc=0x0c09c46cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c46e;
P_0c09c46e: /* original 3120, guest PC 0x0c09c46e */
if(!s->budget--) { s->failed_pc=0x0c09c46eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c09c470;
P_0c09c470: /* original 8b1d, guest PC 0x0c09c470 */
if(!s->budget--) { s->failed_pc=0x0c09c470u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4ae; }
goto P_0c09c472;
P_0c09c472: /* original 9373, guest PC 0x0c09c472 */
if(!s->budget--) { s->failed_pc=0x0c09c472u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c474;
P_0c09c474: /* original 60e3, guest PC 0x0c09c474 */
if(!s->budget--) { s->failed_pc=0x0c09c474u; return 0; }
r[0]=r[14];
goto P_0c09c476;
P_0c09c476: /* original 4008, guest PC 0x0c09c476 */
if(!s->budget--) { s->failed_pc=0x0c09c476u; return 0; }
r[0]<<=2;
goto P_0c09c478;
P_0c09c478: /* original 33dc, guest PC 0x0c09c478 */
if(!s->budget--) { s->failed_pc=0x0c09c478u; return 0; }
r[3]+=r[13];
goto P_0c09c47a;
P_0c09c47a: /* original 003e, guest PC 0x0c09c47a */
if(!s->budget--) { s->failed_pc=0x0c09c47au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c47c;
P_0c09c47c: /* original 8806, guest PC 0x0c09c47c */
if(!s->budget--) { s->failed_pc=0x0c09c47cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c09c47e;
P_0c09c47e: /* original 8b07, guest PC 0x0c09c47e */
if(!s->budget--) { s->failed_pc=0x0c09c47eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c490; }
goto P_0c09c480;
P_0c09c480: /* original 916c, guest PC 0x0c09c480 */
if(!s->budget--) { s->failed_pc=0x0c09c480u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c482;
P_0c09c482: /* original 63e3, guest PC 0x0c09c482 */
if(!s->budget--) { s->failed_pc=0x0c09c482u; return 0; }
r[3]=r[14];
goto P_0c09c484;
P_0c09c484: /* original 4308, guest PC 0x0c09c484 */
if(!s->budget--) { s->failed_pc=0x0c09c484u; return 0; }
r[3]<<=2;
goto P_0c09c486;
P_0c09c486: /* original 31dc, guest PC 0x0c09c486 */
if(!s->budget--) { s->failed_pc=0x0c09c486u; return 0; }
r[1]+=r[13];
goto P_0c09c488;
P_0c09c488: /* original 331c, guest PC 0x0c09c488 */
if(!s->budget--) { s->failed_pc=0x0c09c488u; return 0; }
r[3]+=r[1];
goto P_0c09c48a;
P_0c09c48a: /* original 6032, guest PC 0x0c09c48a */
if(!s->budget--) { s->failed_pc=0x0c09c48au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c48c;
P_0c09c48c: /* original 70ff, guest PC 0x0c09c48c */
if(!s->budget--) { s->failed_pc=0x0c09c48cu; return 0; }
r[0]+=0xffffffffu;
goto P_0c09c48e;
P_0c09c48e: /* original 2302, guest PC 0x0c09c48e */
if(!s->budget--) { s->failed_pc=0x0c09c48eu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c490;
P_0c09c490: /* original 9364, guest PC 0x0c09c490 */
if(!s->budget--) { s->failed_pc=0x0c09c490u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c492;
P_0c09c492: /* original 60e3, guest PC 0x0c09c492 */
if(!s->budget--) { s->failed_pc=0x0c09c492u; return 0; }
r[0]=r[14];
goto P_0c09c494;
P_0c09c494: /* original 4008, guest PC 0x0c09c494 */
if(!s->budget--) { s->failed_pc=0x0c09c494u; return 0; }
r[0]<<=2;
goto P_0c09c496;
P_0c09c496: /* original 33dc, guest PC 0x0c09c496 */
if(!s->budget--) { s->failed_pc=0x0c09c496u; return 0; }
r[3]+=r[13];
goto P_0c09c498;
P_0c09c498: /* original 003e, guest PC 0x0c09c498 */
if(!s->budget--) { s->failed_pc=0x0c09c498u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c49a;
P_0c09c49a: /* original 8803, guest PC 0x0c09c49a */
if(!s->budget--) { s->failed_pc=0x0c09c49au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09c49c;
P_0c09c49c: /* original 8b07, guest PC 0x0c09c49c */
if(!s->budget--) { s->failed_pc=0x0c09c49cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4ae; }
goto P_0c09c49e;
P_0c09c49e: /* original 925d, guest PC 0x0c09c49e */
if(!s->budget--) { s->failed_pc=0x0c09c49eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4a0;
P_0c09c4a0: /* original 63e3, guest PC 0x0c09c4a0 */
if(!s->budget--) { s->failed_pc=0x0c09c4a0u; return 0; }
r[3]=r[14];
goto P_0c09c4a2;
P_0c09c4a2: /* original 4308, guest PC 0x0c09c4a2 */
if(!s->budget--) { s->failed_pc=0x0c09c4a2u; return 0; }
r[3]<<=2;
goto P_0c09c4a4;
P_0c09c4a4: /* original 32dc, guest PC 0x0c09c4a4 */
if(!s->budget--) { s->failed_pc=0x0c09c4a4u; return 0; }
r[2]+=r[13];
goto P_0c09c4a6;
P_0c09c4a6: /* original 332c, guest PC 0x0c09c4a6 */
if(!s->budget--) { s->failed_pc=0x0c09c4a6u; return 0; }
r[3]+=r[2];
goto P_0c09c4a8;
P_0c09c4a8: /* original 6132, guest PC 0x0c09c4a8 */
if(!s->budget--) { s->failed_pc=0x0c09c4a8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c4aa;
P_0c09c4aa: /* original 71ff, guest PC 0x0c09c4aa */
if(!s->budget--) { s->failed_pc=0x0c09c4aau; return 0; }
r[1]+=0xffffffffu;
goto P_0c09c4ac;
P_0c09c4ac: /* original 2312, guest PC 0x0c09c4ac */
if(!s->budget--) { s->failed_pc=0x0c09c4acu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c4ae;
P_0c09c4ae: /* original 53f2, guest PC 0x0c09c4ae */
if(!s->budget--) { s->failed_pc=0x0c09c4aeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09c4b0;
P_0c09c4b0: /* original 9255, guest PC 0x0c09c4b0 */
if(!s->budget--) { s->failed_pc=0x0c09c4b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55eu,2);
goto P_0c09c4b2;
P_0c09c4b2: /* original 6132, guest PC 0x0c09c4b2 */
if(!s->budget--) { s->failed_pc=0x0c09c4b2u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c4b4;
P_0c09c4b4: /* original 3120, guest PC 0x0c09c4b4 */
if(!s->budget--) { s->failed_pc=0x0c09c4b4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c09c4b6;
P_0c09c4b6: /* original 8b1d, guest PC 0x0c09c4b6 */
if(!s->budget--) { s->failed_pc=0x0c09c4b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4f4; }
goto P_0c09c4b8;
P_0c09c4b8: /* original 9350, guest PC 0x0c09c4b8 */
if(!s->budget--) { s->failed_pc=0x0c09c4b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4ba;
P_0c09c4ba: /* original 60e3, guest PC 0x0c09c4ba */
if(!s->budget--) { s->failed_pc=0x0c09c4bau; return 0; }
r[0]=r[14];
goto P_0c09c4bc;
P_0c09c4bc: /* original 4008, guest PC 0x0c09c4bc */
if(!s->budget--) { s->failed_pc=0x0c09c4bcu; return 0; }
r[0]<<=2;
goto P_0c09c4be;
P_0c09c4be: /* original 33dc, guest PC 0x0c09c4be */
if(!s->budget--) { s->failed_pc=0x0c09c4beu; return 0; }
r[3]+=r[13];
goto P_0c09c4c0;
P_0c09c4c0: /* original 003e, guest PC 0x0c09c4c0 */
if(!s->budget--) { s->failed_pc=0x0c09c4c0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c4c2;
P_0c09c4c2: /* original 8808, guest PC 0x0c09c4c2 */
if(!s->budget--) { s->failed_pc=0x0c09c4c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09c4c4;
P_0c09c4c4: /* original 8b07, guest PC 0x0c09c4c4 */
if(!s->budget--) { s->failed_pc=0x0c09c4c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4d6; }
goto P_0c09c4c6;
P_0c09c4c6: /* original 9149, guest PC 0x0c09c4c6 */
if(!s->budget--) { s->failed_pc=0x0c09c4c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4c8;
P_0c09c4c8: /* original 63e3, guest PC 0x0c09c4c8 */
if(!s->budget--) { s->failed_pc=0x0c09c4c8u; return 0; }
r[3]=r[14];
goto P_0c09c4ca;
P_0c09c4ca: /* original 4308, guest PC 0x0c09c4ca */
if(!s->budget--) { s->failed_pc=0x0c09c4cau; return 0; }
r[3]<<=2;
goto P_0c09c4cc;
P_0c09c4cc: /* original 31dc, guest PC 0x0c09c4cc */
if(!s->budget--) { s->failed_pc=0x0c09c4ccu; return 0; }
r[1]+=r[13];
goto P_0c09c4ce;
P_0c09c4ce: /* original 331c, guest PC 0x0c09c4ce */
if(!s->budget--) { s->failed_pc=0x0c09c4ceu; return 0; }
r[3]+=r[1];
goto P_0c09c4d0;
P_0c09c4d0: /* original 6032, guest PC 0x0c09c4d0 */
if(!s->budget--) { s->failed_pc=0x0c09c4d0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c4d2;
P_0c09c4d2: /* original 70ff, guest PC 0x0c09c4d2 */
if(!s->budget--) { s->failed_pc=0x0c09c4d2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c09c4d4;
P_0c09c4d4: /* original 2302, guest PC 0x0c09c4d4 */
if(!s->budget--) { s->failed_pc=0x0c09c4d4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c4d6;
P_0c09c4d6: /* original 9341, guest PC 0x0c09c4d6 */
if(!s->budget--) { s->failed_pc=0x0c09c4d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4d8;
P_0c09c4d8: /* original 60e3, guest PC 0x0c09c4d8 */
if(!s->budget--) { s->failed_pc=0x0c09c4d8u; return 0; }
r[0]=r[14];
goto P_0c09c4da;
P_0c09c4da: /* original 4008, guest PC 0x0c09c4da */
if(!s->budget--) { s->failed_pc=0x0c09c4dau; return 0; }
r[0]<<=2;
goto P_0c09c4dc;
P_0c09c4dc: /* original 33dc, guest PC 0x0c09c4dc */
if(!s->budget--) { s->failed_pc=0x0c09c4dcu; return 0; }
r[3]+=r[13];
goto P_0c09c4de;
P_0c09c4de: /* original 003e, guest PC 0x0c09c4de */
if(!s->budget--) { s->failed_pc=0x0c09c4deu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c4e0;
P_0c09c4e0: /* original 8807, guest PC 0x0c09c4e0 */
if(!s->budget--) { s->failed_pc=0x0c09c4e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c09c4e2;
P_0c09c4e2: /* original 8b07, guest PC 0x0c09c4e2 */
if(!s->budget--) { s->failed_pc=0x0c09c4e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4f4; }
goto P_0c09c4e4;
P_0c09c4e4: /* original 923a, guest PC 0x0c09c4e4 */
if(!s->budget--) { s->failed_pc=0x0c09c4e4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4e6;
P_0c09c4e6: /* original 63e3, guest PC 0x0c09c4e6 */
if(!s->budget--) { s->failed_pc=0x0c09c4e6u; return 0; }
r[3]=r[14];
goto P_0c09c4e8;
P_0c09c4e8: /* original 4308, guest PC 0x0c09c4e8 */
if(!s->budget--) { s->failed_pc=0x0c09c4e8u; return 0; }
r[3]<<=2;
goto P_0c09c4ea;
P_0c09c4ea: /* original 32dc, guest PC 0x0c09c4ea */
if(!s->budget--) { s->failed_pc=0x0c09c4eau; return 0; }
r[2]+=r[13];
goto P_0c09c4ec;
P_0c09c4ec: /* original 332c, guest PC 0x0c09c4ec */
if(!s->budget--) { s->failed_pc=0x0c09c4ecu; return 0; }
r[3]+=r[2];
goto P_0c09c4ee;
P_0c09c4ee: /* original 6132, guest PC 0x0c09c4ee */
if(!s->budget--) { s->failed_pc=0x0c09c4eeu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c4f0;
P_0c09c4f0: /* original 71ff, guest PC 0x0c09c4f0 */
if(!s->budget--) { s->failed_pc=0x0c09c4f0u; return 0; }
r[1]+=0xffffffffu;
goto P_0c09c4f2;
P_0c09c4f2: /* original 2312, guest PC 0x0c09c4f2 */
if(!s->budget--) { s->failed_pc=0x0c09c4f2u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c4f4;
P_0c09c4f4: /* original 9232, guest PC 0x0c09c4f4 */
if(!s->budget--) { s->failed_pc=0x0c09c4f4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4f6;
P_0c09c4f6: /* original 63e3, guest PC 0x0c09c4f6 */
if(!s->budget--) { s->failed_pc=0x0c09c4f6u; return 0; }
r[3]=r[14];
goto P_0c09c4f8;
P_0c09c4f8: /* original 4308, guest PC 0x0c09c4f8 */
if(!s->budget--) { s->failed_pc=0x0c09c4f8u; return 0; }
r[3]<<=2;
goto P_0c09c4fa;
P_0c09c4fa: /* original 32dc, guest PC 0x0c09c4fa */
if(!s->budget--) { s->failed_pc=0x0c09c4fau; return 0; }
r[2]+=r[13];
goto P_0c09c4fc;
P_0c09c4fc: /* original 332c, guest PC 0x0c09c4fc */
if(!s->budget--) { s->failed_pc=0x0c09c4fcu; return 0; }
r[3]+=r[2];
goto P_0c09c4fe;
P_0c09c4fe: /* original 6132, guest PC 0x0c09c4fe */
if(!s->budget--) { s->failed_pc=0x0c09c4feu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c500;
P_0c09c500: /* original 4111, guest PC 0x0c09c500 */
if(!s->budget--) { s->failed_pc=0x0c09c500u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=0)!=0);
goto P_0c09c502;
P_0c09c502: /* original 8906, guest PC 0x0c09c502 */
if(!s->budget--) { s->failed_pc=0x0c09c502u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c512; }
goto P_0c09c504;
P_0c09c504: /* original 932a, guest PC 0x0c09c504 */
if(!s->budget--) { s->failed_pc=0x0c09c504u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c506;
P_0c09c506: /* original 62e3, guest PC 0x0c09c506 */
if(!s->budget--) { s->failed_pc=0x0c09c506u; return 0; }
r[2]=r[14];
goto P_0c09c508;
P_0c09c508: /* original 4208, guest PC 0x0c09c508 */
if(!s->budget--) { s->failed_pc=0x0c09c508u; return 0; }
r[2]<<=2;
goto P_0c09c50a;
P_0c09c50a: /* original 33dc, guest PC 0x0c09c50a */
if(!s->budget--) { s->failed_pc=0x0c09c50au; return 0; }
r[3]+=r[13];
goto P_0c09c50c;
P_0c09c50c: /* original e109, guest PC 0x0c09c50c */
if(!s->budget--) { s->failed_pc=0x0c09c50cu; return 0; }
r[1]=0x00000009u;
goto P_0c09c50e;
P_0c09c50e: /* original 323c, guest PC 0x0c09c50e */
if(!s->budget--) { s->failed_pc=0x0c09c50eu; return 0; }
r[2]+=r[3];
goto P_0c09c510;
P_0c09c510: /* original 2212, guest PC 0x0c09c510 */
if(!s->budget--) { s->failed_pc=0x0c09c510u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c09c512;
P_0c09c512: /* original 60f2, guest PC 0x0c09c512 */
if(!s->budget--) { s->failed_pc=0x0c09c512u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09c514;
P_0c09c514: /* original c820, guest PC 0x0c09c514 */
if(!s->budget--) { s->failed_pc=0x0c09c514u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c09c516;
P_0c09c516: /* original 8b01, guest PC 0x0c09c516 */
if(!s->budget--) { s->failed_pc=0x0c09c516u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c51c; }
goto P_0c09c518;
P_0c09c518: /* original a083, guest PC 0x0c09c518 */
if(!s->budget--) { s->failed_pc=0x0c09c518u; return 0; }
goto P_0c09c622;
P_0c09c51a: /* original 0009, guest PC 0x0c09c51a */
if(!s->budget--) { s->failed_pc=0x0c09c51au; return 0; }
goto P_0c09c51c;
P_0c09c51c: /* original 4a0b, guest PC 0x0c09c51c */
if(!s->budget--) { s->failed_pc=0x0c09c51cu; return 0; }
target=r[10];
r[16]=0x0c09c520u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c520u) { target=s->pc; goto dispatch; }
goto P_0c09c520;
P_0c09c51e: /* original 64b3, guest PC 0x0c09c51e */
if(!s->budget--) { s->failed_pc=0x0c09c51eu; return 0; }
r[4]=r[11];
goto P_0c09c520;
P_0c09c520: /* original 931e, guest PC 0x0c09c520 */
if(!s->budget--) { s->failed_pc=0x0c09c520u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c560u,2);
goto P_0c09c522;
P_0c09c522: /* original 62e3, guest PC 0x0c09c522 */
if(!s->budget--) { s->failed_pc=0x0c09c522u; return 0; }
r[2]=r[14];
goto P_0c09c524;
P_0c09c524: /* original 4208, guest PC 0x0c09c524 */
if(!s->budget--) { s->failed_pc=0x0c09c524u; return 0; }
r[2]<<=2;
goto P_0c09c526;
P_0c09c526: /* original 33dc, guest PC 0x0c09c526 */
if(!s->budget--) { s->failed_pc=0x0c09c526u; return 0; }
r[3]+=r[13];
goto P_0c09c528;
P_0c09c528: /* original 323c, guest PC 0x0c09c528 */
if(!s->budget--) { s->failed_pc=0x0c09c528u; return 0; }
r[2]+=r[3];
goto P_0c09c52a;
P_0c09c52a: /* original 6122, guest PC 0x0c09c52a */
if(!s->budget--) { s->failed_pc=0x0c09c52au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c52c;
P_0c09c52c: /* original 2118, guest PC 0x0c09c52c */
if(!s->budget--) { s->failed_pc=0x0c09c52cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c52e;
P_0c09c52e: /* original 8b1b, guest PC 0x0c09c52e */
if(!s->budget--) { s->failed_pc=0x0c09c52eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c568; }
goto P_0c09c530;
P_0c09c530: /* original 9314, guest PC 0x0c09c530 */
if(!s->budget--) { s->failed_pc=0x0c09c530u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c532;
P_0c09c532: /* original 64e3, guest PC 0x0c09c532 */
if(!s->budget--) { s->failed_pc=0x0c09c532u; return 0; }
r[4]=r[14];
goto P_0c09c534;
P_0c09c534: /* original 4408, guest PC 0x0c09c534 */
if(!s->budget--) { s->failed_pc=0x0c09c534u; return 0; }
r[4]<<=2;
goto P_0c09c536;
P_0c09c536: /* original 33dc, guest PC 0x0c09c536 */
if(!s->budget--) { s->failed_pc=0x0c09c536u; return 0; }
r[3]+=r[13];
goto P_0c09c538;
P_0c09c538: /* original 334c, guest PC 0x0c09c538 */
if(!s->budget--) { s->failed_pc=0x0c09c538u; return 0; }
r[3]+=r[4];
goto P_0c09c53a;
P_0c09c53a: /* original 6232, guest PC 0x0c09c53a */
if(!s->budget--) { s->failed_pc=0x0c09c53au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c53c;
P_0c09c53c: /* original 7201, guest PC 0x0c09c53c */
if(!s->budget--) { s->failed_pc=0x0c09c53cu; return 0; }
r[2]+=0x00000001u;
goto P_0c09c53e;
P_0c09c53e: /* original 2322, guest PC 0x0c09c53e */
if(!s->budget--) { s->failed_pc=0x0c09c53eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c540;
P_0c09c540: /* original e209, guest PC 0x0c09c540 */
if(!s->budget--) { s->failed_pc=0x0c09c540u; return 0; }
r[2]=0x00000009u;
goto P_0c09c542;
P_0c09c542: /* original 930b, guest PC 0x0c09c542 */
if(!s->budget--) { s->failed_pc=0x0c09c542u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c544;
P_0c09c544: /* original 33dc, guest PC 0x0c09c544 */
if(!s->budget--) { s->failed_pc=0x0c09c544u; return 0; }
r[3]+=r[13];
goto P_0c09c546;
P_0c09c546: /* original 343c, guest PC 0x0c09c546 */
if(!s->budget--) { s->failed_pc=0x0c09c546u; return 0; }
r[4]+=r[3];
goto P_0c09c548;
P_0c09c548: /* original 6142, guest PC 0x0c09c548 */
if(!s->budget--) { s->failed_pc=0x0c09c548u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c09c54a;
P_0c09c54a: /* original 3123, guest PC 0x0c09c54a */
if(!s->budget--) { s->failed_pc=0x0c09c54au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c09c54c;
P_0c09c54c: /* original 8963, guest PC 0x0c09c54c */
if(!s->budget--) { s->failed_pc=0x0c09c54cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c616; }
goto P_0c09c54e;
P_0c09c54e: /* original 9305, guest PC 0x0c09c54e */
if(!s->budget--) { s->failed_pc=0x0c09c54eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c550;
P_0c09c550: /* original 60e3, guest PC 0x0c09c550 */
if(!s->budget--) { s->failed_pc=0x0c09c550u; return 0; }
r[0]=r[14];
goto P_0c09c552;
P_0c09c552: /* original 4008, guest PC 0x0c09c552 */
if(!s->budget--) { s->failed_pc=0x0c09c552u; return 0; }
r[0]<<=2;
goto P_0c09c554;
P_0c09c554: /* original 33dc, guest PC 0x0c09c554 */
if(!s->budget--) { s->failed_pc=0x0c09c554u; return 0; }
r[3]+=r[13];
goto P_0c09c556;
P_0c09c556: /* original 303c, guest PC 0x0c09c556 */
if(!s->budget--) { s->failed_pc=0x0c09c556u; return 0; }
r[0]+=r[3];
goto P_0c09c558;
P_0c09c558: /* original a063, guest PC 0x0c09c558 */
if(!s->budget--) { s->failed_pc=0x0c09c558u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c09c622;
P_0c09c55a: /* original 2022, guest PC 0x0c09c55a */
if(!s->budget--) { s->failed_pc=0x0c09c55au; return 0; }
write(ram,r[0],r[2],4);
return vf3_matrix_family(0x0c09c55cu,s,ram);
P_0c09c568: /* original 9282, guest PC 0x0c09c568 */
if(!s->budget--) { s->failed_pc=0x0c09c568u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c56a;
P_0c09c56a: /* original 63e3, guest PC 0x0c09c56a */
if(!s->budget--) { s->failed_pc=0x0c09c56au; return 0; }
r[3]=r[14];
goto P_0c09c56c;
P_0c09c56c: /* original 4308, guest PC 0x0c09c56c */
if(!s->budget--) { s->failed_pc=0x0c09c56cu; return 0; }
r[3]<<=2;
goto P_0c09c56e;
P_0c09c56e: /* original 32dc, guest PC 0x0c09c56e */
if(!s->budget--) { s->failed_pc=0x0c09c56eu; return 0; }
r[2]+=r[13];
goto P_0c09c570;
P_0c09c570: /* original 332c, guest PC 0x0c09c570 */
if(!s->budget--) { s->failed_pc=0x0c09c570u; return 0; }
r[3]+=r[2];
goto P_0c09c572;
P_0c09c572: /* original 6132, guest PC 0x0c09c572 */
if(!s->budget--) { s->failed_pc=0x0c09c572u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c574;
P_0c09c574: /* original 7101, guest PC 0x0c09c574 */
if(!s->budget--) { s->failed_pc=0x0c09c574u; return 0; }
r[1]+=0x00000001u;
goto P_0c09c576;
P_0c09c576: /* original 2312, guest PC 0x0c09c576 */
if(!s->budget--) { s->failed_pc=0x0c09c576u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c578;
P_0c09c578: /* original 53f2, guest PC 0x0c09c578 */
if(!s->budget--) { s->failed_pc=0x0c09c578u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09c57a;
P_0c09c57a: /* original d23f, guest PC 0x0c09c57a */
if(!s->budget--) { s->failed_pc=0x0c09c57au; return 0; }
r[2]=read(ram,0x0c09c678u,4);
goto P_0c09c57c;
P_0c09c57c: /* original 6132, guest PC 0x0c09c57c */
if(!s->budget--) { s->failed_pc=0x0c09c57cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c57e;
P_0c09c57e: /* original 3120, guest PC 0x0c09c57e */
if(!s->budget--) { s->failed_pc=0x0c09c57eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c09c580;
P_0c09c580: /* original 8b1d, guest PC 0x0c09c580 */
if(!s->budget--) { s->failed_pc=0x0c09c580u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c5be; }
goto P_0c09c582;
P_0c09c582: /* original 9375, guest PC 0x0c09c582 */
if(!s->budget--) { s->failed_pc=0x0c09c582u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c584;
P_0c09c584: /* original 60e3, guest PC 0x0c09c584 */
if(!s->budget--) { s->failed_pc=0x0c09c584u; return 0; }
r[0]=r[14];
goto P_0c09c586;
P_0c09c586: /* original 4008, guest PC 0x0c09c586 */
if(!s->budget--) { s->failed_pc=0x0c09c586u; return 0; }
r[0]<<=2;
goto P_0c09c588;
P_0c09c588: /* original 33dc, guest PC 0x0c09c588 */
if(!s->budget--) { s->failed_pc=0x0c09c588u; return 0; }
r[3]+=r[13];
goto P_0c09c58a;
P_0c09c58a: /* original 003e, guest PC 0x0c09c58a */
if(!s->budget--) { s->failed_pc=0x0c09c58au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c58c;
P_0c09c58c: /* original 8803, guest PC 0x0c09c58c */
if(!s->budget--) { s->failed_pc=0x0c09c58cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09c58e;
P_0c09c58e: /* original 8b07, guest PC 0x0c09c58e */
if(!s->budget--) { s->failed_pc=0x0c09c58eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c5a0; }
goto P_0c09c590;
P_0c09c590: /* original 916e, guest PC 0x0c09c590 */
if(!s->budget--) { s->failed_pc=0x0c09c590u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c592;
P_0c09c592: /* original 63e3, guest PC 0x0c09c592 */
if(!s->budget--) { s->failed_pc=0x0c09c592u; return 0; }
r[3]=r[14];
goto P_0c09c594;
P_0c09c594: /* original 4308, guest PC 0x0c09c594 */
if(!s->budget--) { s->failed_pc=0x0c09c594u; return 0; }
r[3]<<=2;
goto P_0c09c596;
P_0c09c596: /* original 31dc, guest PC 0x0c09c596 */
if(!s->budget--) { s->failed_pc=0x0c09c596u; return 0; }
r[1]+=r[13];
goto P_0c09c598;
P_0c09c598: /* original 331c, guest PC 0x0c09c598 */
if(!s->budget--) { s->failed_pc=0x0c09c598u; return 0; }
r[3]+=r[1];
goto P_0c09c59a;
P_0c09c59a: /* original 6032, guest PC 0x0c09c59a */
if(!s->budget--) { s->failed_pc=0x0c09c59au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c59c;
P_0c09c59c: /* original 7001, guest PC 0x0c09c59c */
if(!s->budget--) { s->failed_pc=0x0c09c59cu; return 0; }
r[0]+=0x00000001u;
goto P_0c09c59e;
P_0c09c59e: /* original 2302, guest PC 0x0c09c59e */
if(!s->budget--) { s->failed_pc=0x0c09c59eu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c5a0;
P_0c09c5a0: /* original 9366, guest PC 0x0c09c5a0 */
if(!s->budget--) { s->failed_pc=0x0c09c5a0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5a2;
P_0c09c5a2: /* original 60e3, guest PC 0x0c09c5a2 */
if(!s->budget--) { s->failed_pc=0x0c09c5a2u; return 0; }
r[0]=r[14];
goto P_0c09c5a4;
P_0c09c5a4: /* original 4008, guest PC 0x0c09c5a4 */
if(!s->budget--) { s->failed_pc=0x0c09c5a4u; return 0; }
r[0]<<=2;
goto P_0c09c5a6;
P_0c09c5a6: /* original 33dc, guest PC 0x0c09c5a6 */
if(!s->budget--) { s->failed_pc=0x0c09c5a6u; return 0; }
r[3]+=r[13];
goto P_0c09c5a8;
P_0c09c5a8: /* original 003e, guest PC 0x0c09c5a8 */
if(!s->budget--) { s->failed_pc=0x0c09c5a8u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c5aa;
P_0c09c5aa: /* original 8806, guest PC 0x0c09c5aa */
if(!s->budget--) { s->failed_pc=0x0c09c5aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c09c5ac;
P_0c09c5ac: /* original 8b07, guest PC 0x0c09c5ac */
if(!s->budget--) { s->failed_pc=0x0c09c5acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c5be; }
goto P_0c09c5ae;
P_0c09c5ae: /* original 925f, guest PC 0x0c09c5ae */
if(!s->budget--) { s->failed_pc=0x0c09c5aeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5b0;
P_0c09c5b0: /* original 63e3, guest PC 0x0c09c5b0 */
if(!s->budget--) { s->failed_pc=0x0c09c5b0u; return 0; }
r[3]=r[14];
goto P_0c09c5b2;
P_0c09c5b2: /* original 4308, guest PC 0x0c09c5b2 */
if(!s->budget--) { s->failed_pc=0x0c09c5b2u; return 0; }
r[3]<<=2;
goto P_0c09c5b4;
P_0c09c5b4: /* original 32dc, guest PC 0x0c09c5b4 */
if(!s->budget--) { s->failed_pc=0x0c09c5b4u; return 0; }
r[2]+=r[13];
goto P_0c09c5b6;
P_0c09c5b6: /* original 332c, guest PC 0x0c09c5b6 */
if(!s->budget--) { s->failed_pc=0x0c09c5b6u; return 0; }
r[3]+=r[2];
goto P_0c09c5b8;
P_0c09c5b8: /* original 6132, guest PC 0x0c09c5b8 */
if(!s->budget--) { s->failed_pc=0x0c09c5b8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c5ba;
P_0c09c5ba: /* original 7101, guest PC 0x0c09c5ba */
if(!s->budget--) { s->failed_pc=0x0c09c5bau; return 0; }
r[1]+=0x00000001u;
goto P_0c09c5bc;
P_0c09c5bc: /* original 2312, guest PC 0x0c09c5bc */
if(!s->budget--) { s->failed_pc=0x0c09c5bcu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c5be;
P_0c09c5be: /* original 53f2, guest PC 0x0c09c5be */
if(!s->budget--) { s->failed_pc=0x0c09c5beu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09c5c0;
P_0c09c5c0: /* original 9257, guest PC 0x0c09c5c0 */
if(!s->budget--) { s->failed_pc=0x0c09c5c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c672u,2);
goto P_0c09c5c2;
P_0c09c5c2: /* original 6132, guest PC 0x0c09c5c2 */
if(!s->budget--) { s->failed_pc=0x0c09c5c2u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c5c4;
P_0c09c5c4: /* original 3120, guest PC 0x0c09c5c4 */
if(!s->budget--) { s->failed_pc=0x0c09c5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c09c5c6;
P_0c09c5c6: /* original 8b1d, guest PC 0x0c09c5c6 */
if(!s->budget--) { s->failed_pc=0x0c09c5c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c604; }
goto P_0c09c5c8;
P_0c09c5c8: /* original 9352, guest PC 0x0c09c5c8 */
if(!s->budget--) { s->failed_pc=0x0c09c5c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5ca;
P_0c09c5ca: /* original 60e3, guest PC 0x0c09c5ca */
if(!s->budget--) { s->failed_pc=0x0c09c5cau; return 0; }
r[0]=r[14];
goto P_0c09c5cc;
P_0c09c5cc: /* original 4008, guest PC 0x0c09c5cc */
if(!s->budget--) { s->failed_pc=0x0c09c5ccu; return 0; }
r[0]<<=2;
goto P_0c09c5ce;
P_0c09c5ce: /* original 33dc, guest PC 0x0c09c5ce */
if(!s->budget--) { s->failed_pc=0x0c09c5ceu; return 0; }
r[3]+=r[13];
goto P_0c09c5d0;
P_0c09c5d0: /* original 003e, guest PC 0x0c09c5d0 */
if(!s->budget--) { s->failed_pc=0x0c09c5d0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c5d2;
P_0c09c5d2: /* original 8807, guest PC 0x0c09c5d2 */
if(!s->budget--) { s->failed_pc=0x0c09c5d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c09c5d4;
P_0c09c5d4: /* original 8b07, guest PC 0x0c09c5d4 */
if(!s->budget--) { s->failed_pc=0x0c09c5d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c5e6; }
goto P_0c09c5d6;
P_0c09c5d6: /* original 914b, guest PC 0x0c09c5d6 */
if(!s->budget--) { s->failed_pc=0x0c09c5d6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5d8;
P_0c09c5d8: /* original 63e3, guest PC 0x0c09c5d8 */
if(!s->budget--) { s->failed_pc=0x0c09c5d8u; return 0; }
r[3]=r[14];
goto P_0c09c5da;
P_0c09c5da: /* original 4308, guest PC 0x0c09c5da */
if(!s->budget--) { s->failed_pc=0x0c09c5dau; return 0; }
r[3]<<=2;
goto P_0c09c5dc;
P_0c09c5dc: /* original 31dc, guest PC 0x0c09c5dc */
if(!s->budget--) { s->failed_pc=0x0c09c5dcu; return 0; }
r[1]+=r[13];
goto P_0c09c5de;
P_0c09c5de: /* original 331c, guest PC 0x0c09c5de */
if(!s->budget--) { s->failed_pc=0x0c09c5deu; return 0; }
r[3]+=r[1];
goto P_0c09c5e0;
P_0c09c5e0: /* original 6032, guest PC 0x0c09c5e0 */
if(!s->budget--) { s->failed_pc=0x0c09c5e0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c5e2;
P_0c09c5e2: /* original 7001, guest PC 0x0c09c5e2 */
if(!s->budget--) { s->failed_pc=0x0c09c5e2u; return 0; }
r[0]+=0x00000001u;
goto P_0c09c5e4;
P_0c09c5e4: /* original 2302, guest PC 0x0c09c5e4 */
if(!s->budget--) { s->failed_pc=0x0c09c5e4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c5e6;
P_0c09c5e6: /* original 9343, guest PC 0x0c09c5e6 */
if(!s->budget--) { s->failed_pc=0x0c09c5e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5e8;
P_0c09c5e8: /* original 60e3, guest PC 0x0c09c5e8 */
if(!s->budget--) { s->failed_pc=0x0c09c5e8u; return 0; }
r[0]=r[14];
goto P_0c09c5ea;
P_0c09c5ea: /* original 4008, guest PC 0x0c09c5ea */
if(!s->budget--) { s->failed_pc=0x0c09c5eau; return 0; }
r[0]<<=2;
goto P_0c09c5ec;
P_0c09c5ec: /* original 33dc, guest PC 0x0c09c5ec */
if(!s->budget--) { s->failed_pc=0x0c09c5ecu; return 0; }
r[3]+=r[13];
goto P_0c09c5ee;
P_0c09c5ee: /* original 003e, guest PC 0x0c09c5ee */
if(!s->budget--) { s->failed_pc=0x0c09c5eeu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c5f0;
P_0c09c5f0: /* original 8808, guest PC 0x0c09c5f0 */
if(!s->budget--) { s->failed_pc=0x0c09c5f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09c5f2;
P_0c09c5f2: /* original 8b07, guest PC 0x0c09c5f2 */
if(!s->budget--) { s->failed_pc=0x0c09c5f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c604; }
goto P_0c09c5f4;
P_0c09c5f4: /* original 923c, guest PC 0x0c09c5f4 */
if(!s->budget--) { s->failed_pc=0x0c09c5f4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5f6;
P_0c09c5f6: /* original 63e3, guest PC 0x0c09c5f6 */
if(!s->budget--) { s->failed_pc=0x0c09c5f6u; return 0; }
r[3]=r[14];
goto P_0c09c5f8;
P_0c09c5f8: /* original 4308, guest PC 0x0c09c5f8 */
if(!s->budget--) { s->failed_pc=0x0c09c5f8u; return 0; }
r[3]<<=2;
goto P_0c09c5fa;
P_0c09c5fa: /* original 32dc, guest PC 0x0c09c5fa */
if(!s->budget--) { s->failed_pc=0x0c09c5fau; return 0; }
r[2]+=r[13];
goto P_0c09c5fc;
P_0c09c5fc: /* original 332c, guest PC 0x0c09c5fc */
if(!s->budget--) { s->failed_pc=0x0c09c5fcu; return 0; }
r[3]+=r[2];
goto P_0c09c5fe;
P_0c09c5fe: /* original 6132, guest PC 0x0c09c5fe */
if(!s->budget--) { s->failed_pc=0x0c09c5feu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c600;
P_0c09c600: /* original 7101, guest PC 0x0c09c600 */
if(!s->budget--) { s->failed_pc=0x0c09c600u; return 0; }
r[1]+=0x00000001u;
goto P_0c09c602;
P_0c09c602: /* original 2312, guest PC 0x0c09c602 */
if(!s->budget--) { s->failed_pc=0x0c09c602u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c604;
P_0c09c604: /* original 9234, guest PC 0x0c09c604 */
if(!s->budget--) { s->failed_pc=0x0c09c604u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c606;
P_0c09c606: /* original 63e3, guest PC 0x0c09c606 */
if(!s->budget--) { s->failed_pc=0x0c09c606u; return 0; }
r[3]=r[14];
goto P_0c09c608;
P_0c09c608: /* original 4308, guest PC 0x0c09c608 */
if(!s->budget--) { s->failed_pc=0x0c09c608u; return 0; }
r[3]<<=2;
goto P_0c09c60a;
P_0c09c60a: /* original 32dc, guest PC 0x0c09c60a */
if(!s->budget--) { s->failed_pc=0x0c09c60au; return 0; }
r[2]+=r[13];
goto P_0c09c60c;
P_0c09c60c: /* original 332c, guest PC 0x0c09c60c */
if(!s->budget--) { s->failed_pc=0x0c09c60cu; return 0; }
r[3]+=r[2];
goto P_0c09c60e;
P_0c09c60e: /* original 6032, guest PC 0x0c09c60e */
if(!s->budget--) { s->failed_pc=0x0c09c60eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c610;
P_0c09c610: /* original e109, guest PC 0x0c09c610 */
if(!s->budget--) { s->failed_pc=0x0c09c610u; return 0; }
r[1]=0x00000009u;
goto P_0c09c612;
P_0c09c612: /* original 3017, guest PC 0x0c09c612 */
if(!s->budget--) { s->failed_pc=0x0c09c612u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[1])!=0);
goto P_0c09c614;
P_0c09c614: /* original 8b05, guest PC 0x0c09c614 */
if(!s->budget--) { s->failed_pc=0x0c09c614u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c622; }
goto P_0c09c616;
P_0c09c616: /* original 932b, guest PC 0x0c09c616 */
if(!s->budget--) { s->failed_pc=0x0c09c616u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c618;
P_0c09c618: /* original 62e3, guest PC 0x0c09c618 */
if(!s->budget--) { s->failed_pc=0x0c09c618u; return 0; }
r[2]=r[14];
goto P_0c09c61a;
P_0c09c61a: /* original 4208, guest PC 0x0c09c61a */
if(!s->budget--) { s->failed_pc=0x0c09c61au; return 0; }
r[2]<<=2;
goto P_0c09c61c;
P_0c09c61c: /* original 33dc, guest PC 0x0c09c61c */
if(!s->budget--) { s->failed_pc=0x0c09c61cu; return 0; }
r[3]+=r[13];
goto P_0c09c61e;
P_0c09c61e: /* original 323c, guest PC 0x0c09c61e */
if(!s->budget--) { s->failed_pc=0x0c09c61eu; return 0; }
r[2]+=r[3];
goto P_0c09c620;
P_0c09c620: /* original 2292, guest PC 0x0c09c620 */
if(!s->budget--) { s->failed_pc=0x0c09c620u; return 0; }
write(ram,r[2],r[9],4);
goto P_0c09c622;
P_0c09c622: /* original 60f2, guest PC 0x0c09c622 */
if(!s->budget--) { s->failed_pc=0x0c09c622u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09c624;
P_0c09c624: /* original c840, guest PC 0x0c09c624 */
if(!s->budget--) { s->failed_pc=0x0c09c624u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c09c626;
P_0c09c626: /* original 8b01, guest PC 0x0c09c626 */
if(!s->budget--) { s->failed_pc=0x0c09c626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c62c; }
goto P_0c09c628;
P_0c09c628: /* original a0f2, guest PC 0x0c09c628 */
if(!s->budget--) { s->failed_pc=0x0c09c628u; return 0; }
goto P_0c09c810;
P_0c09c62a: /* original 0009, guest PC 0x0c09c62a */
if(!s->budget--) { s->failed_pc=0x0c09c62au; return 0; }
goto P_0c09c62c;
P_0c09c62c: /* original 9320, guest PC 0x0c09c62c */
if(!s->budget--) { s->failed_pc=0x0c09c62cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c62e;
P_0c09c62e: /* original 62e3, guest PC 0x0c09c62e */
if(!s->budget--) { s->failed_pc=0x0c09c62eu; return 0; }
r[2]=r[14];
goto P_0c09c630;
P_0c09c630: /* original 4208, guest PC 0x0c09c630 */
if(!s->budget--) { s->failed_pc=0x0c09c630u; return 0; }
r[2]<<=2;
goto P_0c09c632;
P_0c09c632: /* original 33dc, guest PC 0x0c09c632 */
if(!s->budget--) { s->failed_pc=0x0c09c632u; return 0; }
r[3]+=r[13];
goto P_0c09c634;
P_0c09c634: /* original 323c, guest PC 0x0c09c634 */
if(!s->budget--) { s->failed_pc=0x0c09c634u; return 0; }
r[2]+=r[3];
goto P_0c09c636;
P_0c09c636: /* original 6122, guest PC 0x0c09c636 */
if(!s->budget--) { s->failed_pc=0x0c09c636u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c638;
P_0c09c638: /* original 2118, guest PC 0x0c09c638 */
if(!s->budget--) { s->failed_pc=0x0c09c638u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c63a;
P_0c09c63a: /* original 8b1f, guest PC 0x0c09c63a */
if(!s->budget--) { s->failed_pc=0x0c09c63au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c67c; }
goto P_0c09c63c;
P_0c09c63c: /* original 4a0b, guest PC 0x0c09c63c */
if(!s->budget--) { s->failed_pc=0x0c09c63cu; return 0; }
target=r[10];
r[16]=0x0c09c640u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c640u) { target=s->pc; goto dispatch; }
goto P_0c09c640;
P_0c09c63e: /* original 64b3, guest PC 0x0c09c63e */
if(!s->budget--) { s->failed_pc=0x0c09c63eu; return 0; }
r[4]=r[11];
goto P_0c09c640;
P_0c09c640: /* original 9219, guest PC 0x0c09c640 */
if(!s->budget--) { s->failed_pc=0x0c09c640u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c676u,2);
goto P_0c09c642;
P_0c09c642: /* original 64e3, guest PC 0x0c09c642 */
if(!s->budget--) { s->failed_pc=0x0c09c642u; return 0; }
r[4]=r[14];
goto P_0c09c644;
P_0c09c644: /* original 4408, guest PC 0x0c09c644 */
if(!s->budget--) { s->failed_pc=0x0c09c644u; return 0; }
r[4]<<=2;
goto P_0c09c646;
P_0c09c646: /* original 9315, guest PC 0x0c09c646 */
if(!s->budget--) { s->failed_pc=0x0c09c646u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c674u,2);
goto P_0c09c648;
P_0c09c648: /* original 32dc, guest PC 0x0c09c648 */
if(!s->budget--) { s->failed_pc=0x0c09c648u; return 0; }
r[2]+=r[13];
goto P_0c09c64a;
P_0c09c64a: /* original 324c, guest PC 0x0c09c64a */
if(!s->budget--) { s->failed_pc=0x0c09c64au; return 0; }
r[2]+=r[4];
goto P_0c09c64c;
P_0c09c64c: /* original 33dc, guest PC 0x0c09c64c */
if(!s->budget--) { s->failed_pc=0x0c09c64cu; return 0; }
r[3]+=r[13];
goto P_0c09c64e;
P_0c09c64e: /* original 6122, guest PC 0x0c09c64e */
if(!s->budget--) { s->failed_pc=0x0c09c64eu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c650;
P_0c09c650: /* original 334c, guest PC 0x0c09c650 */
if(!s->budget--) { s->failed_pc=0x0c09c650u; return 0; }
r[3]+=r[4];
goto P_0c09c652;
P_0c09c652: /* original 2312, guest PC 0x0c09c652 */
if(!s->budget--) { s->failed_pc=0x0c09c652u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c654;
P_0c09c654: /* original 930f, guest PC 0x0c09c654 */
if(!s->budget--) { s->failed_pc=0x0c09c654u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c676u,2);
goto P_0c09c656;
P_0c09c656: /* original 33dc, guest PC 0x0c09c656 */
if(!s->budget--) { s->failed_pc=0x0c09c656u; return 0; }
r[3]+=r[13];
goto P_0c09c658;
P_0c09c658: /* original 334c, guest PC 0x0c09c658 */
if(!s->budget--) { s->failed_pc=0x0c09c658u; return 0; }
r[3]+=r[4];
goto P_0c09c65a;
P_0c09c65a: /* original 6232, guest PC 0x0c09c65a */
if(!s->budget--) { s->failed_pc=0x0c09c65au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c65c;
P_0c09c65c: /* original 72ff, guest PC 0x0c09c65c */
if(!s->budget--) { s->failed_pc=0x0c09c65cu; return 0; }
r[2]+=0xffffffffu;
goto P_0c09c65e;
P_0c09c65e: /* original 2322, guest PC 0x0c09c65e */
if(!s->budget--) { s->failed_pc=0x0c09c65eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c660;
P_0c09c660: /* original 9309, guest PC 0x0c09c660 */
if(!s->budget--) { s->failed_pc=0x0c09c660u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c676u,2);
goto P_0c09c662;
P_0c09c662: /* original 33dc, guest PC 0x0c09c662 */
if(!s->budget--) { s->failed_pc=0x0c09c662u; return 0; }
r[3]+=r[13];
goto P_0c09c664;
P_0c09c664: /* original 343c, guest PC 0x0c09c664 */
if(!s->budget--) { s->failed_pc=0x0c09c664u; return 0; }
r[4]+=r[3];
goto P_0c09c666;
P_0c09c666: /* original 6242, guest PC 0x0c09c666 */
if(!s->budget--) { s->failed_pc=0x0c09c666u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09c668;
P_0c09c668: /* original 4211, guest PC 0x0c09c668 */
if(!s->budget--) { s->failed_pc=0x0c09c668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09c66a;
P_0c09c66a: /* original 8b28, guest PC 0x0c09c66a */
if(!s->budget--) { s->failed_pc=0x0c09c66au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c6be; }
goto P_0c09c66c;
P_0c09c66c: /* original a0d0, guest PC 0x0c09c66c */
if(!s->budget--) { s->failed_pc=0x0c09c66cu; return 0; }
goto P_0c09c810;
P_0c09c66e: /* original 0009, guest PC 0x0c09c66e */
if(!s->budget--) { s->failed_pc=0x0c09c66eu; return 0; }
return vf3_matrix_family(0x0c09c670u,s,ram);
P_0c09c67c: /* original 936a, guest PC 0x0c09c67c */
if(!s->budget--) { s->failed_pc=0x0c09c67cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c67e;
P_0c09c67e: /* original 60e3, guest PC 0x0c09c67e */
if(!s->budget--) { s->failed_pc=0x0c09c67eu; return 0; }
r[0]=r[14];
goto P_0c09c680;
P_0c09c680: /* original 4008, guest PC 0x0c09c680 */
if(!s->budget--) { s->failed_pc=0x0c09c680u; return 0; }
r[0]<<=2;
goto P_0c09c682;
P_0c09c682: /* original 33dc, guest PC 0x0c09c682 */
if(!s->budget--) { s->failed_pc=0x0c09c682u; return 0; }
r[3]+=r[13];
goto P_0c09c684;
P_0c09c684: /* original 003e, guest PC 0x0c09c684 */
if(!s->budget--) { s->failed_pc=0x0c09c684u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c686;
P_0c09c686: /* original 8809, guest PC 0x0c09c686 */
if(!s->budget--) { s->failed_pc=0x0c09c686u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c09c688;
P_0c09c688: /* original 8b20, guest PC 0x0c09c688 */
if(!s->budget--) { s->failed_pc=0x0c09c688u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c6cc; }
goto P_0c09c68a;
P_0c09c68a: /* original 4a0b, guest PC 0x0c09c68a */
if(!s->budget--) { s->failed_pc=0x0c09c68au; return 0; }
target=r[10];
r[16]=0x0c09c68eu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c68eu) { target=s->pc; goto dispatch; }
goto P_0c09c68e;
P_0c09c68c: /* original 64b3, guest PC 0x0c09c68c */
if(!s->budget--) { s->failed_pc=0x0c09c68cu; return 0; }
r[4]=r[11];
goto P_0c09c68e;
P_0c09c68e: /* original 9263, guest PC 0x0c09c68e */
if(!s->budget--) { s->failed_pc=0x0c09c68eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c758u,2);
goto P_0c09c690;
P_0c09c690: /* original 64e3, guest PC 0x0c09c690 */
if(!s->budget--) { s->failed_pc=0x0c09c690u; return 0; }
r[4]=r[14];
goto P_0c09c692;
P_0c09c692: /* original 4408, guest PC 0x0c09c692 */
if(!s->budget--) { s->failed_pc=0x0c09c692u; return 0; }
r[4]<<=2;
goto P_0c09c694;
P_0c09c694: /* original 935f, guest PC 0x0c09c694 */
if(!s->budget--) { s->failed_pc=0x0c09c694u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c756u,2);
goto P_0c09c696;
P_0c09c696: /* original 32dc, guest PC 0x0c09c696 */
if(!s->budget--) { s->failed_pc=0x0c09c696u; return 0; }
r[2]+=r[13];
goto P_0c09c698;
P_0c09c698: /* original 324c, guest PC 0x0c09c698 */
if(!s->budget--) { s->failed_pc=0x0c09c698u; return 0; }
r[2]+=r[4];
goto P_0c09c69a;
P_0c09c69a: /* original 33dc, guest PC 0x0c09c69a */
if(!s->budget--) { s->failed_pc=0x0c09c69au; return 0; }
r[3]+=r[13];
goto P_0c09c69c;
P_0c09c69c: /* original 6122, guest PC 0x0c09c69c */
if(!s->budget--) { s->failed_pc=0x0c09c69cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c69e;
P_0c09c69e: /* original 334c, guest PC 0x0c09c69e */
if(!s->budget--) { s->failed_pc=0x0c09c69eu; return 0; }
r[3]+=r[4];
goto P_0c09c6a0;
P_0c09c6a0: /* original 2312, guest PC 0x0c09c6a0 */
if(!s->budget--) { s->failed_pc=0x0c09c6a0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c6a2;
P_0c09c6a2: /* original 9359, guest PC 0x0c09c6a2 */
if(!s->budget--) { s->failed_pc=0x0c09c6a2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c758u,2);
goto P_0c09c6a4;
P_0c09c6a4: /* original 33dc, guest PC 0x0c09c6a4 */
if(!s->budget--) { s->failed_pc=0x0c09c6a4u; return 0; }
r[3]+=r[13];
goto P_0c09c6a6;
P_0c09c6a6: /* original 334c, guest PC 0x0c09c6a6 */
if(!s->budget--) { s->failed_pc=0x0c09c6a6u; return 0; }
r[3]+=r[4];
goto P_0c09c6a8;
P_0c09c6a8: /* original 6232, guest PC 0x0c09c6a8 */
if(!s->budget--) { s->failed_pc=0x0c09c6a8u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c6aa;
P_0c09c6aa: /* original 72ff, guest PC 0x0c09c6aa */
if(!s->budget--) { s->failed_pc=0x0c09c6aau; return 0; }
r[2]+=0xffffffffu;
goto P_0c09c6ac;
P_0c09c6ac: /* original 2322, guest PC 0x0c09c6ac */
if(!s->budget--) { s->failed_pc=0x0c09c6acu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c6ae;
P_0c09c6ae: /* original 9353, guest PC 0x0c09c6ae */
if(!s->budget--) { s->failed_pc=0x0c09c6aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c758u,2);
goto P_0c09c6b0;
P_0c09c6b0: /* original 33dc, guest PC 0x0c09c6b0 */
if(!s->budget--) { s->failed_pc=0x0c09c6b0u; return 0; }
r[3]+=r[13];
goto P_0c09c6b2;
P_0c09c6b2: /* original 343c, guest PC 0x0c09c6b2 */
if(!s->budget--) { s->failed_pc=0x0c09c6b2u; return 0; }
r[4]+=r[3];
goto P_0c09c6b4;
P_0c09c6b4: /* original 6242, guest PC 0x0c09c6b4 */
if(!s->budget--) { s->failed_pc=0x0c09c6b4u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09c6b6;
P_0c09c6b6: /* original 4211, guest PC 0x0c09c6b6 */
if(!s->budget--) { s->failed_pc=0x0c09c6b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09c6b8;
P_0c09c6b8: /* original 8b01, guest PC 0x0c09c6b8 */
if(!s->budget--) { s->failed_pc=0x0c09c6b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c6be; }
goto P_0c09c6ba;
P_0c09c6ba: /* original a0a9, guest PC 0x0c09c6ba */
if(!s->budget--) { s->failed_pc=0x0c09c6bau; return 0; }
goto P_0c09c810;
P_0c09c6bc: /* original 0009, guest PC 0x0c09c6bc */
if(!s->budget--) { s->failed_pc=0x0c09c6bcu; return 0; }
goto P_0c09c6be;
P_0c09c6be: /* original 934b, guest PC 0x0c09c6be */
if(!s->budget--) { s->failed_pc=0x0c09c6beu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c758u,2);
goto P_0c09c6c0;
P_0c09c6c0: /* original 61e3, guest PC 0x0c09c6c0 */
if(!s->budget--) { s->failed_pc=0x0c09c6c0u; return 0; }
r[1]=r[14];
goto P_0c09c6c2;
P_0c09c6c2: /* original 4108, guest PC 0x0c09c6c2 */
if(!s->budget--) { s->failed_pc=0x0c09c6c2u; return 0; }
r[1]<<=2;
goto P_0c09c6c4;
P_0c09c6c4: /* original 33dc, guest PC 0x0c09c6c4 */
if(!s->budget--) { s->failed_pc=0x0c09c6c4u; return 0; }
r[3]+=r[13];
goto P_0c09c6c6;
P_0c09c6c6: /* original 313c, guest PC 0x0c09c6c6 */
if(!s->budget--) { s->failed_pc=0x0c09c6c6u; return 0; }
r[1]+=r[3];
goto P_0c09c6c8;
P_0c09c6c8: /* original a0a2, guest PC 0x0c09c6c8 */
if(!s->budget--) { s->failed_pc=0x0c09c6c8u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c09c810;
P_0c09c6ca: /* original 21c2, guest PC 0x0c09c6ca */
if(!s->budget--) { s->failed_pc=0x0c09c6cau; return 0; }
write(ram,r[1],r[12],4);
goto P_0c09c6cc;
P_0c09c6cc: /* original 4a0b, guest PC 0x0c09c6cc */
if(!s->budget--) { s->failed_pc=0x0c09c6ccu; return 0; }
target=r[10];
r[16]=0x0c09c6d0u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c6d0u) { target=s->pc; goto dispatch; }
goto P_0c09c6d0;
P_0c09c6ce: /* original 64b3, guest PC 0x0c09c6ce */
if(!s->budget--) { s->failed_pc=0x0c09c6ceu; return 0; }
r[4]=r[11];
goto P_0c09c6d0;
P_0c09c6d0: /* original 60e3, guest PC 0x0c09c6d0 */
if(!s->budget--) { s->failed_pc=0x0c09c6d0u; return 0; }
r[0]=r[14];
goto P_0c09c6d2;
P_0c09c6d2: /* original 9342, guest PC 0x0c09c6d2 */
if(!s->budget--) { s->failed_pc=0x0c09c6d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c75au,2);
goto P_0c09c6d4;
P_0c09c6d4: /* original 4008, guest PC 0x0c09c6d4 */
if(!s->budget--) { s->failed_pc=0x0c09c6d4u; return 0; }
r[0]<<=2;
goto P_0c09c6d6;
P_0c09c6d6: /* original 62e3, guest PC 0x0c09c6d6 */
if(!s->budget--) { s->failed_pc=0x0c09c6d6u; return 0; }
r[2]=r[14];
goto P_0c09c6d8;
P_0c09c6d8: /* original 4008, guest PC 0x0c09c6d8 */
if(!s->budget--) { s->failed_pc=0x0c09c6d8u; return 0; }
r[0]<<=2;
goto P_0c09c6da;
P_0c09c6da: /* original 33dc, guest PC 0x0c09c6da */
if(!s->budget--) { s->failed_pc=0x0c09c6dau; return 0; }
r[3]+=r[13];
goto P_0c09c6dc;
P_0c09c6dc: /* original 4008, guest PC 0x0c09c6dc */
if(!s->budget--) { s->failed_pc=0x0c09c6dcu; return 0; }
r[0]<<=2;
goto P_0c09c6de;
P_0c09c6de: /* original 303c, guest PC 0x0c09c6de */
if(!s->budget--) { s->failed_pc=0x0c09c6deu; return 0; }
r[0]+=r[3];
goto P_0c09c6e0;
P_0c09c6e0: /* original 9338, guest PC 0x0c09c6e0 */
if(!s->budget--) { s->failed_pc=0x0c09c6e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c6e2;
P_0c09c6e2: /* original 4208, guest PC 0x0c09c6e2 */
if(!s->budget--) { s->failed_pc=0x0c09c6e2u; return 0; }
r[2]<<=2;
goto P_0c09c6e4;
P_0c09c6e4: /* original 33dc, guest PC 0x0c09c6e4 */
if(!s->budget--) { s->failed_pc=0x0c09c6e4u; return 0; }
r[3]+=r[13];
goto P_0c09c6e6;
P_0c09c6e6: /* original 323c, guest PC 0x0c09c6e6 */
if(!s->budget--) { s->failed_pc=0x0c09c6e6u; return 0; }
r[2]+=r[3];
goto P_0c09c6e8;
P_0c09c6e8: /* original 6122, guest PC 0x0c09c6e8 */
if(!s->budget--) { s->failed_pc=0x0c09c6e8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c6ea;
P_0c09c6ea: /* original 4108, guest PC 0x0c09c6ea */
if(!s->budget--) { s->failed_pc=0x0c09c6eau; return 0; }
r[1]<<=2;
goto P_0c09c6ec;
P_0c09c6ec: /* original 031e, guest PC 0x0c09c6ec */
if(!s->budget--) { s->failed_pc=0x0c09c6ecu; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c6ee;
P_0c09c6ee: /* original 2338, guest PC 0x0c09c6ee */
if(!s->budget--) { s->failed_pc=0x0c09c6eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09c6f0;
P_0c09c6f0: /* original 8b0f, guest PC 0x0c09c6f0 */
if(!s->budget--) { s->failed_pc=0x0c09c6f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c712; }
goto P_0c09c6f2;
P_0c09c6f2: /* original 60e3, guest PC 0x0c09c6f2 */
if(!s->budget--) { s->failed_pc=0x0c09c6f2u; return 0; }
r[0]=r[14];
goto P_0c09c6f4;
P_0c09c6f4: /* original 9331, guest PC 0x0c09c6f4 */
if(!s->budget--) { s->failed_pc=0x0c09c6f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c75au,2);
goto P_0c09c6f6;
P_0c09c6f6: /* original 4008, guest PC 0x0c09c6f6 */
if(!s->budget--) { s->failed_pc=0x0c09c6f6u; return 0; }
r[0]<<=2;
goto P_0c09c6f8;
P_0c09c6f8: /* original 62e3, guest PC 0x0c09c6f8 */
if(!s->budget--) { s->failed_pc=0x0c09c6f8u; return 0; }
r[2]=r[14];
goto P_0c09c6fa;
P_0c09c6fa: /* original 4008, guest PC 0x0c09c6fa */
if(!s->budget--) { s->failed_pc=0x0c09c6fau; return 0; }
r[0]<<=2;
goto P_0c09c6fc;
P_0c09c6fc: /* original 33dc, guest PC 0x0c09c6fc */
if(!s->budget--) { s->failed_pc=0x0c09c6fcu; return 0; }
r[3]+=r[13];
goto P_0c09c6fe;
P_0c09c6fe: /* original 4008, guest PC 0x0c09c6fe */
if(!s->budget--) { s->failed_pc=0x0c09c6feu; return 0; }
r[0]<<=2;
goto P_0c09c700;
P_0c09c700: /* original 303c, guest PC 0x0c09c700 */
if(!s->budget--) { s->failed_pc=0x0c09c700u; return 0; }
r[0]+=r[3];
goto P_0c09c702;
P_0c09c702: /* original 9327, guest PC 0x0c09c702 */
if(!s->budget--) { s->failed_pc=0x0c09c702u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c704;
P_0c09c704: /* original 4208, guest PC 0x0c09c704 */
if(!s->budget--) { s->failed_pc=0x0c09c704u; return 0; }
r[2]<<=2;
goto P_0c09c706;
P_0c09c706: /* original 33dc, guest PC 0x0c09c706 */
if(!s->budget--) { s->failed_pc=0x0c09c706u; return 0; }
r[3]+=r[13];
goto P_0c09c708;
P_0c09c708: /* original 323c, guest PC 0x0c09c708 */
if(!s->budget--) { s->failed_pc=0x0c09c708u; return 0; }
r[2]+=r[3];
goto P_0c09c70a;
P_0c09c70a: /* original 6122, guest PC 0x0c09c70a */
if(!s->budget--) { s->failed_pc=0x0c09c70au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c70c;
P_0c09c70c: /* original 4108, guest PC 0x0c09c70c */
if(!s->budget--) { s->failed_pc=0x0c09c70cu; return 0; }
r[1]<<=2;
goto P_0c09c70e;
P_0c09c70e: /* original a037, guest PC 0x0c09c70e */
if(!s->budget--) { s->failed_pc=0x0c09c70eu; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c09c780;
P_0c09c710: /* original 01c6, guest PC 0x0c09c710 */
if(!s->budget--) { s->failed_pc=0x0c09c710u; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c09c712;
P_0c09c712: /* original 60e3, guest PC 0x0c09c712 */
if(!s->budget--) { s->failed_pc=0x0c09c712u; return 0; }
r[0]=r[14];
goto P_0c09c714;
P_0c09c714: /* original 9321, guest PC 0x0c09c714 */
if(!s->budget--) { s->failed_pc=0x0c09c714u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c75au,2);
goto P_0c09c716;
P_0c09c716: /* original 4008, guest PC 0x0c09c716 */
if(!s->budget--) { s->failed_pc=0x0c09c716u; return 0; }
r[0]<<=2;
goto P_0c09c718;
P_0c09c718: /* original 62e3, guest PC 0x0c09c718 */
if(!s->budget--) { s->failed_pc=0x0c09c718u; return 0; }
r[2]=r[14];
goto P_0c09c71a;
P_0c09c71a: /* original 4008, guest PC 0x0c09c71a */
if(!s->budget--) { s->failed_pc=0x0c09c71au; return 0; }
r[0]<<=2;
goto P_0c09c71c;
P_0c09c71c: /* original 33dc, guest PC 0x0c09c71c */
if(!s->budget--) { s->failed_pc=0x0c09c71cu; return 0; }
r[3]+=r[13];
goto P_0c09c71e;
P_0c09c71e: /* original 4008, guest PC 0x0c09c71e */
if(!s->budget--) { s->failed_pc=0x0c09c71eu; return 0; }
r[0]<<=2;
goto P_0c09c720;
P_0c09c720: /* original 303c, guest PC 0x0c09c720 */
if(!s->budget--) { s->failed_pc=0x0c09c720u; return 0; }
r[0]+=r[3];
goto P_0c09c722;
P_0c09c722: /* original 9317, guest PC 0x0c09c722 */
if(!s->budget--) { s->failed_pc=0x0c09c722u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c724;
P_0c09c724: /* original 4208, guest PC 0x0c09c724 */
if(!s->budget--) { s->failed_pc=0x0c09c724u; return 0; }
r[2]<<=2;
goto P_0c09c726;
P_0c09c726: /* original 33dc, guest PC 0x0c09c726 */
if(!s->budget--) { s->failed_pc=0x0c09c726u; return 0; }
r[3]+=r[13];
goto P_0c09c728;
P_0c09c728: /* original 323c, guest PC 0x0c09c728 */
if(!s->budget--) { s->failed_pc=0x0c09c728u; return 0; }
r[2]+=r[3];
goto P_0c09c72a;
P_0c09c72a: /* original 6122, guest PC 0x0c09c72a */
if(!s->budget--) { s->failed_pc=0x0c09c72au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c72c;
P_0c09c72c: /* original 4108, guest PC 0x0c09c72c */
if(!s->budget--) { s->failed_pc=0x0c09c72cu; return 0; }
r[1]<<=2;
goto P_0c09c72e;
P_0c09c72e: /* original 031e, guest PC 0x0c09c72e */
if(!s->budget--) { s->failed_pc=0x0c09c72eu; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c730;
P_0c09c730: /* original 3380, guest PC 0x0c09c730 */
if(!s->budget--) { s->failed_pc=0x0c09c730u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[8])!=0);
goto P_0c09c732;
P_0c09c732: /* original 8b13, guest PC 0x0c09c732 */
if(!s->budget--) { s->failed_pc=0x0c09c732u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c75c; }
goto P_0c09c734;
P_0c09c734: /* original 60e3, guest PC 0x0c09c734 */
if(!s->budget--) { s->failed_pc=0x0c09c734u; return 0; }
r[0]=r[14];
goto P_0c09c736;
P_0c09c736: /* original 9310, guest PC 0x0c09c736 */
if(!s->budget--) { s->failed_pc=0x0c09c736u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c75au,2);
goto P_0c09c738;
P_0c09c738: /* original 4008, guest PC 0x0c09c738 */
if(!s->budget--) { s->failed_pc=0x0c09c738u; return 0; }
r[0]<<=2;
goto P_0c09c73a;
P_0c09c73a: /* original 62e3, guest PC 0x0c09c73a */
if(!s->budget--) { s->failed_pc=0x0c09c73au; return 0; }
r[2]=r[14];
goto P_0c09c73c;
P_0c09c73c: /* original 4008, guest PC 0x0c09c73c */
if(!s->budget--) { s->failed_pc=0x0c09c73cu; return 0; }
r[0]<<=2;
goto P_0c09c73e;
P_0c09c73e: /* original 33dc, guest PC 0x0c09c73e */
if(!s->budget--) { s->failed_pc=0x0c09c73eu; return 0; }
r[3]+=r[13];
goto P_0c09c740;
P_0c09c740: /* original 4008, guest PC 0x0c09c740 */
if(!s->budget--) { s->failed_pc=0x0c09c740u; return 0; }
r[0]<<=2;
goto P_0c09c742;
P_0c09c742: /* original 303c, guest PC 0x0c09c742 */
if(!s->budget--) { s->failed_pc=0x0c09c742u; return 0; }
r[0]+=r[3];
goto P_0c09c744;
P_0c09c744: /* original 9306, guest PC 0x0c09c744 */
if(!s->budget--) { s->failed_pc=0x0c09c744u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c746;
P_0c09c746: /* original 4208, guest PC 0x0c09c746 */
if(!s->budget--) { s->failed_pc=0x0c09c746u; return 0; }
r[2]<<=2;
goto P_0c09c748;
P_0c09c748: /* original 33dc, guest PC 0x0c09c748 */
if(!s->budget--) { s->failed_pc=0x0c09c748u; return 0; }
r[3]+=r[13];
goto P_0c09c74a;
P_0c09c74a: /* original 323c, guest PC 0x0c09c74a */
if(!s->budget--) { s->failed_pc=0x0c09c74au; return 0; }
r[2]+=r[3];
goto P_0c09c74c;
P_0c09c74c: /* original 6122, guest PC 0x0c09c74c */
if(!s->budget--) { s->failed_pc=0x0c09c74cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c74e;
P_0c09c74e: /* original 4108, guest PC 0x0c09c74e */
if(!s->budget--) { s->failed_pc=0x0c09c74eu; return 0; }
r[1]<<=2;
goto P_0c09c750;
P_0c09c750: /* original a016, guest PC 0x0c09c750 */
if(!s->budget--) { s->failed_pc=0x0c09c750u; return 0; }
write(ram,r[1]+r[0],r[9],4);
goto P_0c09c780;
P_0c09c752: /* original 0196, guest PC 0x0c09c752 */
if(!s->budget--) { s->failed_pc=0x0c09c752u; return 0; }
write(ram,r[1]+r[0],r[9],4);
return vf3_matrix_family(0x0c09c754u,s,ram);
P_0c09c75c: /* original 64e3, guest PC 0x0c09c75c */
if(!s->budget--) { s->failed_pc=0x0c09c75cu; return 0; }
r[4]=r[14];
goto P_0c09c75e;
P_0c09c75e: /* original 93a6, guest PC 0x0c09c75e */
if(!s->budget--) { s->failed_pc=0x0c09c75eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c760;
P_0c09c760: /* original 4408, guest PC 0x0c09c760 */
if(!s->budget--) { s->failed_pc=0x0c09c760u; return 0; }
r[4]<<=2;
goto P_0c09c762;
P_0c09c762: /* original 62e3, guest PC 0x0c09c762 */
if(!s->budget--) { s->failed_pc=0x0c09c762u; return 0; }
r[2]=r[14];
goto P_0c09c764;
P_0c09c764: /* original 4408, guest PC 0x0c09c764 */
if(!s->budget--) { s->failed_pc=0x0c09c764u; return 0; }
r[4]<<=2;
goto P_0c09c766;
P_0c09c766: /* original 33dc, guest PC 0x0c09c766 */
if(!s->budget--) { s->failed_pc=0x0c09c766u; return 0; }
r[3]+=r[13];
goto P_0c09c768;
P_0c09c768: /* original 4408, guest PC 0x0c09c768 */
if(!s->budget--) { s->failed_pc=0x0c09c768u; return 0; }
r[4]<<=2;
goto P_0c09c76a;
P_0c09c76a: /* original 343c, guest PC 0x0c09c76a */
if(!s->budget--) { s->failed_pc=0x0c09c76au; return 0; }
r[4]+=r[3];
goto P_0c09c76c;
P_0c09c76c: /* original 93a0, guest PC 0x0c09c76c */
if(!s->budget--) { s->failed_pc=0x0c09c76cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c76e;
P_0c09c76e: /* original 4208, guest PC 0x0c09c76e */
if(!s->budget--) { s->failed_pc=0x0c09c76eu; return 0; }
r[2]<<=2;
goto P_0c09c770;
P_0c09c770: /* original 33dc, guest PC 0x0c09c770 */
if(!s->budget--) { s->failed_pc=0x0c09c770u; return 0; }
r[3]+=r[13];
goto P_0c09c772;
P_0c09c772: /* original 323c, guest PC 0x0c09c772 */
if(!s->budget--) { s->failed_pc=0x0c09c772u; return 0; }
r[2]+=r[3];
goto P_0c09c774;
P_0c09c774: /* original 6122, guest PC 0x0c09c774 */
if(!s->budget--) { s->failed_pc=0x0c09c774u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c776;
P_0c09c776: /* original 4108, guest PC 0x0c09c776 */
if(!s->budget--) { s->failed_pc=0x0c09c776u; return 0; }
r[1]<<=2;
goto P_0c09c778;
P_0c09c778: /* original 341c, guest PC 0x0c09c778 */
if(!s->budget--) { s->failed_pc=0x0c09c778u; return 0; }
r[4]+=r[1];
goto P_0c09c77a;
P_0c09c77a: /* original 6342, guest PC 0x0c09c77a */
if(!s->budget--) { s->failed_pc=0x0c09c77au; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09c77c;
P_0c09c77c: /* original 4300, guest PC 0x0c09c77c */
if(!s->budget--) { s->failed_pc=0x0c09c77cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c09c77e;
P_0c09c77e: /* original 2432, guest PC 0x0c09c77e */
if(!s->budget--) { s->failed_pc=0x0c09c77eu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c09c780;
P_0c09c780: /* original 9396, guest PC 0x0c09c780 */
if(!s->budget--) { s->failed_pc=0x0c09c780u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c782;
P_0c09c782: /* original 60e3, guest PC 0x0c09c782 */
if(!s->budget--) { s->failed_pc=0x0c09c782u; return 0; }
r[0]=r[14];
goto P_0c09c784;
P_0c09c784: /* original 4008, guest PC 0x0c09c784 */
if(!s->budget--) { s->failed_pc=0x0c09c784u; return 0; }
r[0]<<=2;
goto P_0c09c786;
P_0c09c786: /* original 33dc, guest PC 0x0c09c786 */
if(!s->budget--) { s->failed_pc=0x0c09c786u; return 0; }
r[3]+=r[13];
goto P_0c09c788;
P_0c09c788: /* original 003e, guest PC 0x0c09c788 */
if(!s->budget--) { s->failed_pc=0x0c09c788u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c78a;
P_0c09c78a: /* original 8801, guest PC 0x0c09c78a */
if(!s->budget--) { s->failed_pc=0x0c09c78au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09c78c;
P_0c09c78c: /* original 8b40, guest PC 0x0c09c78c */
if(!s->budget--) { s->failed_pc=0x0c09c78cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c810; }
goto P_0c09c78e;
P_0c09c78e: /* original 60e3, guest PC 0x0c09c78e */
if(!s->budget--) { s->failed_pc=0x0c09c78eu; return 0; }
r[0]=r[14];
goto P_0c09c790;
P_0c09c790: /* original 938d, guest PC 0x0c09c790 */
if(!s->budget--) { s->failed_pc=0x0c09c790u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c792;
P_0c09c792: /* original 4008, guest PC 0x0c09c792 */
if(!s->budget--) { s->failed_pc=0x0c09c792u; return 0; }
r[0]<<=2;
goto P_0c09c794;
P_0c09c794: /* original 62e3, guest PC 0x0c09c794 */
if(!s->budget--) { s->failed_pc=0x0c09c794u; return 0; }
r[2]=r[14];
goto P_0c09c796;
P_0c09c796: /* original 4008, guest PC 0x0c09c796 */
if(!s->budget--) { s->failed_pc=0x0c09c796u; return 0; }
r[0]<<=2;
goto P_0c09c798;
P_0c09c798: /* original 33dc, guest PC 0x0c09c798 */
if(!s->budget--) { s->failed_pc=0x0c09c798u; return 0; }
r[3]+=r[13];
goto P_0c09c79a;
P_0c09c79a: /* original 4008, guest PC 0x0c09c79a */
if(!s->budget--) { s->failed_pc=0x0c09c79au; return 0; }
r[0]<<=2;
goto P_0c09c79c;
P_0c09c79c: /* original 303c, guest PC 0x0c09c79c */
if(!s->budget--) { s->failed_pc=0x0c09c79cu; return 0; }
r[0]+=r[3];
goto P_0c09c79e;
P_0c09c79e: /* original 9387, guest PC 0x0c09c79e */
if(!s->budget--) { s->failed_pc=0x0c09c79eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c7a0;
P_0c09c7a0: /* original 4208, guest PC 0x0c09c7a0 */
if(!s->budget--) { s->failed_pc=0x0c09c7a0u; return 0; }
r[2]<<=2;
goto P_0c09c7a2;
P_0c09c7a2: /* original 33dc, guest PC 0x0c09c7a2 */
if(!s->budget--) { s->failed_pc=0x0c09c7a2u; return 0; }
r[3]+=r[13];
goto P_0c09c7a4;
P_0c09c7a4: /* original 323c, guest PC 0x0c09c7a4 */
if(!s->budget--) { s->failed_pc=0x0c09c7a4u; return 0; }
r[2]+=r[3];
goto P_0c09c7a6;
P_0c09c7a6: /* original 6122, guest PC 0x0c09c7a6 */
if(!s->budget--) { s->failed_pc=0x0c09c7a6u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c7a8;
P_0c09c7a8: /* original 4108, guest PC 0x0c09c7a8 */
if(!s->budget--) { s->failed_pc=0x0c09c7a8u; return 0; }
r[1]<<=2;
goto P_0c09c7aa;
P_0c09c7aa: /* original 001e, guest PC 0x0c09c7aa */
if(!s->budget--) { s->failed_pc=0x0c09c7aau; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c09c7ac;
P_0c09c7ac: /* original 8810, guest PC 0x0c09c7ac */
if(!s->budget--) { s->failed_pc=0x0c09c7acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c09c7ae;
P_0c09c7ae: /* original 8b0f, guest PC 0x0c09c7ae */
if(!s->budget--) { s->failed_pc=0x0c09c7aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c7d0; }
goto P_0c09c7b0;
P_0c09c7b0: /* original 60e3, guest PC 0x0c09c7b0 */
if(!s->budget--) { s->failed_pc=0x0c09c7b0u; return 0; }
r[0]=r[14];
goto P_0c09c7b2;
P_0c09c7b2: /* original 937c, guest PC 0x0c09c7b2 */
if(!s->budget--) { s->failed_pc=0x0c09c7b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c7b4;
P_0c09c7b4: /* original 4008, guest PC 0x0c09c7b4 */
if(!s->budget--) { s->failed_pc=0x0c09c7b4u; return 0; }
r[0]<<=2;
goto P_0c09c7b6;
P_0c09c7b6: /* original 62e3, guest PC 0x0c09c7b6 */
if(!s->budget--) { s->failed_pc=0x0c09c7b6u; return 0; }
r[2]=r[14];
goto P_0c09c7b8;
P_0c09c7b8: /* original 4008, guest PC 0x0c09c7b8 */
if(!s->budget--) { s->failed_pc=0x0c09c7b8u; return 0; }
r[0]<<=2;
goto P_0c09c7ba;
P_0c09c7ba: /* original 33dc, guest PC 0x0c09c7ba */
if(!s->budget--) { s->failed_pc=0x0c09c7bau; return 0; }
r[3]+=r[13];
goto P_0c09c7bc;
P_0c09c7bc: /* original 4008, guest PC 0x0c09c7bc */
if(!s->budget--) { s->failed_pc=0x0c09c7bcu; return 0; }
r[0]<<=2;
goto P_0c09c7be;
P_0c09c7be: /* original 303c, guest PC 0x0c09c7be */
if(!s->budget--) { s->failed_pc=0x0c09c7beu; return 0; }
r[0]+=r[3];
goto P_0c09c7c0;
P_0c09c7c0: /* original 9376, guest PC 0x0c09c7c0 */
if(!s->budget--) { s->failed_pc=0x0c09c7c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c7c2;
P_0c09c7c2: /* original 4208, guest PC 0x0c09c7c2 */
if(!s->budget--) { s->failed_pc=0x0c09c7c2u; return 0; }
r[2]<<=2;
goto P_0c09c7c4;
P_0c09c7c4: /* original 33dc, guest PC 0x0c09c7c4 */
if(!s->budget--) { s->failed_pc=0x0c09c7c4u; return 0; }
r[3]+=r[13];
goto P_0c09c7c6;
P_0c09c7c6: /* original 323c, guest PC 0x0c09c7c6 */
if(!s->budget--) { s->failed_pc=0x0c09c7c6u; return 0; }
r[2]+=r[3];
goto P_0c09c7c8;
P_0c09c7c8: /* original 6122, guest PC 0x0c09c7c8 */
if(!s->budget--) { s->failed_pc=0x0c09c7c8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c7ca;
P_0c09c7ca: /* original e320, guest PC 0x0c09c7ca */
if(!s->budget--) { s->failed_pc=0x0c09c7cau; return 0; }
r[3]=0x00000020u;
goto P_0c09c7cc;
P_0c09c7cc: /* original 4108, guest PC 0x0c09c7cc */
if(!s->budget--) { s->failed_pc=0x0c09c7ccu; return 0; }
r[1]<<=2;
goto P_0c09c7ce;
P_0c09c7ce: /* original 0136, guest PC 0x0c09c7ce */
if(!s->budget--) { s->failed_pc=0x0c09c7ceu; return 0; }
write(ram,r[1]+r[0],r[3],4);
goto P_0c09c7d0;
P_0c09c7d0: /* original 60e3, guest PC 0x0c09c7d0 */
if(!s->budget--) { s->failed_pc=0x0c09c7d0u; return 0; }
r[0]=r[14];
goto P_0c09c7d2;
P_0c09c7d2: /* original 936c, guest PC 0x0c09c7d2 */
if(!s->budget--) { s->failed_pc=0x0c09c7d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c7d4;
P_0c09c7d4: /* original 4008, guest PC 0x0c09c7d4 */
if(!s->budget--) { s->failed_pc=0x0c09c7d4u; return 0; }
r[0]<<=2;
goto P_0c09c7d6;
P_0c09c7d6: /* original 62e3, guest PC 0x0c09c7d6 */
if(!s->budget--) { s->failed_pc=0x0c09c7d6u; return 0; }
r[2]=r[14];
goto P_0c09c7d8;
P_0c09c7d8: /* original 4008, guest PC 0x0c09c7d8 */
if(!s->budget--) { s->failed_pc=0x0c09c7d8u; return 0; }
r[0]<<=2;
goto P_0c09c7da;
P_0c09c7da: /* original 33dc, guest PC 0x0c09c7da */
if(!s->budget--) { s->failed_pc=0x0c09c7dau; return 0; }
r[3]+=r[13];
goto P_0c09c7dc;
P_0c09c7dc: /* original 4008, guest PC 0x0c09c7dc */
if(!s->budget--) { s->failed_pc=0x0c09c7dcu; return 0; }
r[0]<<=2;
goto P_0c09c7de;
P_0c09c7de: /* original 303c, guest PC 0x0c09c7de */
if(!s->budget--) { s->failed_pc=0x0c09c7deu; return 0; }
r[0]+=r[3];
goto P_0c09c7e0;
P_0c09c7e0: /* original 9366, guest PC 0x0c09c7e0 */
if(!s->budget--) { s->failed_pc=0x0c09c7e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c7e2;
P_0c09c7e2: /* original 4208, guest PC 0x0c09c7e2 */
if(!s->budget--) { s->failed_pc=0x0c09c7e2u; return 0; }
r[2]<<=2;
goto P_0c09c7e4;
P_0c09c7e4: /* original 33dc, guest PC 0x0c09c7e4 */
if(!s->budget--) { s->failed_pc=0x0c09c7e4u; return 0; }
r[3]+=r[13];
goto P_0c09c7e6;
P_0c09c7e6: /* original 323c, guest PC 0x0c09c7e6 */
if(!s->budget--) { s->failed_pc=0x0c09c7e6u; return 0; }
r[2]+=r[3];
goto P_0c09c7e8;
P_0c09c7e8: /* original 6122, guest PC 0x0c09c7e8 */
if(!s->budget--) { s->failed_pc=0x0c09c7e8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c7ea;
P_0c09c7ea: /* original 4108, guest PC 0x0c09c7ea */
if(!s->budget--) { s->failed_pc=0x0c09c7eau; return 0; }
r[1]<<=2;
goto P_0c09c7ec;
P_0c09c7ec: /* original 031e, guest PC 0x0c09c7ec */
if(!s->budget--) { s->failed_pc=0x0c09c7ecu; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c7ee;
P_0c09c7ee: /* original 2338, guest PC 0x0c09c7ee */
if(!s->budget--) { s->failed_pc=0x0c09c7eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09c7f0;
P_0c09c7f0: /* original 8b0e, guest PC 0x0c09c7f0 */
if(!s->budget--) { s->failed_pc=0x0c09c7f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c810; }
goto P_0c09c7f2;
P_0c09c7f2: /* original 60e3, guest PC 0x0c09c7f2 */
if(!s->budget--) { s->failed_pc=0x0c09c7f2u; return 0; }
r[0]=r[14];
goto P_0c09c7f4;
P_0c09c7f4: /* original 935b, guest PC 0x0c09c7f4 */
if(!s->budget--) { s->failed_pc=0x0c09c7f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c7f6;
P_0c09c7f6: /* original 4008, guest PC 0x0c09c7f6 */
if(!s->budget--) { s->failed_pc=0x0c09c7f6u; return 0; }
r[0]<<=2;
goto P_0c09c7f8;
P_0c09c7f8: /* original 62e3, guest PC 0x0c09c7f8 */
if(!s->budget--) { s->failed_pc=0x0c09c7f8u; return 0; }
r[2]=r[14];
goto P_0c09c7fa;
P_0c09c7fa: /* original 4008, guest PC 0x0c09c7fa */
if(!s->budget--) { s->failed_pc=0x0c09c7fau; return 0; }
r[0]<<=2;
goto P_0c09c7fc;
P_0c09c7fc: /* original 33dc, guest PC 0x0c09c7fc */
if(!s->budget--) { s->failed_pc=0x0c09c7fcu; return 0; }
r[3]+=r[13];
goto P_0c09c7fe;
P_0c09c7fe: /* original 4008, guest PC 0x0c09c7fe */
if(!s->budget--) { s->failed_pc=0x0c09c7feu; return 0; }
r[0]<<=2;
goto P_0c09c800;
P_0c09c800: /* original 303c, guest PC 0x0c09c800 */
if(!s->budget--) { s->failed_pc=0x0c09c800u; return 0; }
r[0]+=r[3];
goto P_0c09c802;
P_0c09c802: /* original 9355, guest PC 0x0c09c802 */
if(!s->budget--) { s->failed_pc=0x0c09c802u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c804;
P_0c09c804: /* original 4208, guest PC 0x0c09c804 */
if(!s->budget--) { s->failed_pc=0x0c09c804u; return 0; }
r[2]<<=2;
goto P_0c09c806;
P_0c09c806: /* original 33dc, guest PC 0x0c09c806 */
if(!s->budget--) { s->failed_pc=0x0c09c806u; return 0; }
r[3]+=r[13];
goto P_0c09c808;
P_0c09c808: /* original 323c, guest PC 0x0c09c808 */
if(!s->budget--) { s->failed_pc=0x0c09c808u; return 0; }
r[2]+=r[3];
goto P_0c09c80a;
P_0c09c80a: /* original 6122, guest PC 0x0c09c80a */
if(!s->budget--) { s->failed_pc=0x0c09c80au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c80c;
P_0c09c80c: /* original 4108, guest PC 0x0c09c80c */
if(!s->budget--) { s->failed_pc=0x0c09c80cu; return 0; }
r[1]<<=2;
goto P_0c09c80e;
P_0c09c80e: /* original 01c6, guest PC 0x0c09c80e */
if(!s->budget--) { s->failed_pc=0x0c09c80eu; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c09c810;
P_0c09c810: /* original 60f2, guest PC 0x0c09c810 */
if(!s->budget--) { s->failed_pc=0x0c09c810u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09c812;
P_0c09c812: /* original c880, guest PC 0x0c09c812 */
if(!s->budget--) { s->failed_pc=0x0c09c812u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c09c814;
P_0c09c814: /* original 8b01, guest PC 0x0c09c814 */
if(!s->budget--) { s->failed_pc=0x0c09c814u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c81a; }
goto P_0c09c816;
P_0c09c816: /* original a0ee, guest PC 0x0c09c816 */
if(!s->budget--) { s->failed_pc=0x0c09c816u; return 0; }
goto P_0c09c9f6;
P_0c09c818: /* original 0009, guest PC 0x0c09c818 */
if(!s->budget--) { s->failed_pc=0x0c09c818u; return 0; }
goto P_0c09c81a;
P_0c09c81a: /* original 9349, guest PC 0x0c09c81a */
if(!s->budget--) { s->failed_pc=0x0c09c81au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c81c;
P_0c09c81c: /* original 62e3, guest PC 0x0c09c81c */
if(!s->budget--) { s->failed_pc=0x0c09c81cu; return 0; }
r[2]=r[14];
goto P_0c09c81e;
P_0c09c81e: /* original 4208, guest PC 0x0c09c81e */
if(!s->budget--) { s->failed_pc=0x0c09c81eu; return 0; }
r[2]<<=2;
goto P_0c09c820;
P_0c09c820: /* original 33dc, guest PC 0x0c09c820 */
if(!s->budget--) { s->failed_pc=0x0c09c820u; return 0; }
r[3]+=r[13];
goto P_0c09c822;
P_0c09c822: /* original 323c, guest PC 0x0c09c822 */
if(!s->budget--) { s->failed_pc=0x0c09c822u; return 0; }
r[2]+=r[3];
goto P_0c09c824;
P_0c09c824: /* original 6122, guest PC 0x0c09c824 */
if(!s->budget--) { s->failed_pc=0x0c09c824u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c826;
P_0c09c826: /* original 2118, guest PC 0x0c09c826 */
if(!s->budget--) { s->failed_pc=0x0c09c826u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c828;
P_0c09c828: /* original 8b19, guest PC 0x0c09c828 */
if(!s->budget--) { s->failed_pc=0x0c09c828u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c85e; }
goto P_0c09c82a;
P_0c09c82a: /* original 4a0b, guest PC 0x0c09c82a */
if(!s->budget--) { s->failed_pc=0x0c09c82au; return 0; }
target=r[10];
r[16]=0x0c09c82eu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c82eu) { target=s->pc; goto dispatch; }
goto P_0c09c82e;
P_0c09c82c: /* original 64b3, guest PC 0x0c09c82c */
if(!s->budget--) { s->failed_pc=0x0c09c82cu; return 0; }
r[4]=r[11];
goto P_0c09c82e;
P_0c09c82e: /* original 9241, guest PC 0x0c09c82e */
if(!s->budget--) { s->failed_pc=0x0c09c82eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c830;
P_0c09c830: /* original 64e3, guest PC 0x0c09c830 */
if(!s->budget--) { s->failed_pc=0x0c09c830u; return 0; }
r[4]=r[14];
goto P_0c09c832;
P_0c09c832: /* original 4408, guest PC 0x0c09c832 */
if(!s->budget--) { s->failed_pc=0x0c09c832u; return 0; }
r[4]<<=2;
goto P_0c09c834;
P_0c09c834: /* original 933d, guest PC 0x0c09c834 */
if(!s->budget--) { s->failed_pc=0x0c09c834u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b2u,2);
goto P_0c09c836;
P_0c09c836: /* original 32dc, guest PC 0x0c09c836 */
if(!s->budget--) { s->failed_pc=0x0c09c836u; return 0; }
r[2]+=r[13];
goto P_0c09c838;
P_0c09c838: /* original 324c, guest PC 0x0c09c838 */
if(!s->budget--) { s->failed_pc=0x0c09c838u; return 0; }
r[2]+=r[4];
goto P_0c09c83a;
P_0c09c83a: /* original 33dc, guest PC 0x0c09c83a */
if(!s->budget--) { s->failed_pc=0x0c09c83au; return 0; }
r[3]+=r[13];
goto P_0c09c83c;
P_0c09c83c: /* original 6122, guest PC 0x0c09c83c */
if(!s->budget--) { s->failed_pc=0x0c09c83cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c83e;
P_0c09c83e: /* original 334c, guest PC 0x0c09c83e */
if(!s->budget--) { s->failed_pc=0x0c09c83eu; return 0; }
r[3]+=r[4];
goto P_0c09c840;
P_0c09c840: /* original 2312, guest PC 0x0c09c840 */
if(!s->budget--) { s->failed_pc=0x0c09c840u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c842;
P_0c09c842: /* original 9337, guest PC 0x0c09c842 */
if(!s->budget--) { s->failed_pc=0x0c09c842u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c844;
P_0c09c844: /* original 33dc, guest PC 0x0c09c844 */
if(!s->budget--) { s->failed_pc=0x0c09c844u; return 0; }
r[3]+=r[13];
goto P_0c09c846;
P_0c09c846: /* original 334c, guest PC 0x0c09c846 */
if(!s->budget--) { s->failed_pc=0x0c09c846u; return 0; }
r[3]+=r[4];
goto P_0c09c848;
P_0c09c848: /* original 6232, guest PC 0x0c09c848 */
if(!s->budget--) { s->failed_pc=0x0c09c848u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c84a;
P_0c09c84a: /* original 7201, guest PC 0x0c09c84a */
if(!s->budget--) { s->failed_pc=0x0c09c84au; return 0; }
r[2]+=0x00000001u;
goto P_0c09c84c;
P_0c09c84c: /* original 2322, guest PC 0x0c09c84c */
if(!s->budget--) { s->failed_pc=0x0c09c84cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c84e;
P_0c09c84e: /* original 9331, guest PC 0x0c09c84e */
if(!s->budget--) { s->failed_pc=0x0c09c84eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c850;
P_0c09c850: /* original 33dc, guest PC 0x0c09c850 */
if(!s->budget--) { s->failed_pc=0x0c09c850u; return 0; }
r[3]+=r[13];
goto P_0c09c852;
P_0c09c852: /* original 343c, guest PC 0x0c09c852 */
if(!s->budget--) { s->failed_pc=0x0c09c852u; return 0; }
r[4]+=r[3];
goto P_0c09c854;
P_0c09c854: /* original 6242, guest PC 0x0c09c854 */
if(!s->budget--) { s->failed_pc=0x0c09c854u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09c856;
P_0c09c856: /* original 32c7, guest PC 0x0c09c856 */
if(!s->budget--) { s->failed_pc=0x0c09c856u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[12])!=0);
goto P_0c09c858;
P_0c09c858: /* original 8922, guest PC 0x0c09c858 */
if(!s->budget--) { s->failed_pc=0x0c09c858u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c8a0; }
goto P_0c09c85a;
P_0c09c85a: /* original a0cc, guest PC 0x0c09c85a */
if(!s->budget--) { s->failed_pc=0x0c09c85au; return 0; }
goto P_0c09c9f6;
P_0c09c85c: /* original 0009, guest PC 0x0c09c85c */
if(!s->budget--) { s->failed_pc=0x0c09c85cu; return 0; }
goto P_0c09c85e;
P_0c09c85e: /* original 9327, guest PC 0x0c09c85e */
if(!s->budget--) { s->failed_pc=0x0c09c85eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c860;
P_0c09c860: /* original 60e3, guest PC 0x0c09c860 */
if(!s->budget--) { s->failed_pc=0x0c09c860u; return 0; }
r[0]=r[14];
goto P_0c09c862;
P_0c09c862: /* original 4008, guest PC 0x0c09c862 */
if(!s->budget--) { s->failed_pc=0x0c09c862u; return 0; }
r[0]<<=2;
goto P_0c09c864;
P_0c09c864: /* original 33dc, guest PC 0x0c09c864 */
if(!s->budget--) { s->failed_pc=0x0c09c864u; return 0; }
r[3]+=r[13];
goto P_0c09c866;
P_0c09c866: /* original 003e, guest PC 0x0c09c866 */
if(!s->budget--) { s->failed_pc=0x0c09c866u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c868;
P_0c09c868: /* original 8809, guest PC 0x0c09c868 */
if(!s->budget--) { s->failed_pc=0x0c09c868u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c09c86a;
P_0c09c86a: /* original 8b24, guest PC 0x0c09c86a */
if(!s->budget--) { s->failed_pc=0x0c09c86au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c8b6; }
goto P_0c09c86c;
P_0c09c86c: /* original 4a0b, guest PC 0x0c09c86c */
if(!s->budget--) { s->failed_pc=0x0c09c86cu; return 0; }
target=r[10];
r[16]=0x0c09c870u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c870u) { target=s->pc; goto dispatch; }
goto P_0c09c870;
P_0c09c86e: /* original 64b3, guest PC 0x0c09c86e */
if(!s->budget--) { s->failed_pc=0x0c09c86eu; return 0; }
r[4]=r[11];
goto P_0c09c870;
P_0c09c870: /* original 9220, guest PC 0x0c09c870 */
if(!s->budget--) { s->failed_pc=0x0c09c870u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c872;
P_0c09c872: /* original 64e3, guest PC 0x0c09c872 */
if(!s->budget--) { s->failed_pc=0x0c09c872u; return 0; }
r[4]=r[14];
goto P_0c09c874;
P_0c09c874: /* original 4408, guest PC 0x0c09c874 */
if(!s->budget--) { s->failed_pc=0x0c09c874u; return 0; }
r[4]<<=2;
goto P_0c09c876;
P_0c09c876: /* original 931c, guest PC 0x0c09c876 */
if(!s->budget--) { s->failed_pc=0x0c09c876u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b2u,2);
goto P_0c09c878;
P_0c09c878: /* original 32dc, guest PC 0x0c09c878 */
if(!s->budget--) { s->failed_pc=0x0c09c878u; return 0; }
r[2]+=r[13];
goto P_0c09c87a;
P_0c09c87a: /* original 324c, guest PC 0x0c09c87a */
if(!s->budget--) { s->failed_pc=0x0c09c87au; return 0; }
r[2]+=r[4];
goto P_0c09c87c;
P_0c09c87c: /* original 33dc, guest PC 0x0c09c87c */
if(!s->budget--) { s->failed_pc=0x0c09c87cu; return 0; }
r[3]+=r[13];
goto P_0c09c87e;
P_0c09c87e: /* original 6122, guest PC 0x0c09c87e */
if(!s->budget--) { s->failed_pc=0x0c09c87eu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c880;
P_0c09c880: /* original 334c, guest PC 0x0c09c880 */
if(!s->budget--) { s->failed_pc=0x0c09c880u; return 0; }
r[3]+=r[4];
goto P_0c09c882;
P_0c09c882: /* original 2312, guest PC 0x0c09c882 */
if(!s->budget--) { s->failed_pc=0x0c09c882u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c884;
P_0c09c884: /* original 9316, guest PC 0x0c09c884 */
if(!s->budget--) { s->failed_pc=0x0c09c884u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c886;
P_0c09c886: /* original 33dc, guest PC 0x0c09c886 */
if(!s->budget--) { s->failed_pc=0x0c09c886u; return 0; }
r[3]+=r[13];
goto P_0c09c888;
P_0c09c888: /* original 334c, guest PC 0x0c09c888 */
if(!s->budget--) { s->failed_pc=0x0c09c888u; return 0; }
r[3]+=r[4];
goto P_0c09c88a;
P_0c09c88a: /* original 6232, guest PC 0x0c09c88a */
if(!s->budget--) { s->failed_pc=0x0c09c88au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c88c;
P_0c09c88c: /* original 7201, guest PC 0x0c09c88c */
if(!s->budget--) { s->failed_pc=0x0c09c88cu; return 0; }
r[2]+=0x00000001u;
goto P_0c09c88e;
P_0c09c88e: /* original 2322, guest PC 0x0c09c88e */
if(!s->budget--) { s->failed_pc=0x0c09c88eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c890;
P_0c09c890: /* original 9310, guest PC 0x0c09c890 */
if(!s->budget--) { s->failed_pc=0x0c09c890u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c892;
P_0c09c892: /* original 33dc, guest PC 0x0c09c892 */
if(!s->budget--) { s->failed_pc=0x0c09c892u; return 0; }
r[3]+=r[13];
goto P_0c09c894;
P_0c09c894: /* original 343c, guest PC 0x0c09c894 */
if(!s->budget--) { s->failed_pc=0x0c09c894u; return 0; }
r[4]+=r[3];
goto P_0c09c896;
P_0c09c896: /* original 6242, guest PC 0x0c09c896 */
if(!s->budget--) { s->failed_pc=0x0c09c896u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09c898;
P_0c09c898: /* original 32c7, guest PC 0x0c09c898 */
if(!s->budget--) { s->failed_pc=0x0c09c898u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[12])!=0);
goto P_0c09c89a;
P_0c09c89a: /* original 8901, guest PC 0x0c09c89a */
if(!s->budget--) { s->failed_pc=0x0c09c89au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c8a0; }
goto P_0c09c89c;
P_0c09c89c: /* original a0ab, guest PC 0x0c09c89c */
if(!s->budget--) { s->failed_pc=0x0c09c89cu; return 0; }
goto P_0c09c9f6;
P_0c09c89e: /* original 0009, guest PC 0x0c09c89e */
if(!s->budget--) { s->failed_pc=0x0c09c89eu; return 0; }
goto P_0c09c8a0;
P_0c09c8a0: /* original 9308, guest PC 0x0c09c8a0 */
if(!s->budget--) { s->failed_pc=0x0c09c8a0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c8a2;
P_0c09c8a2: /* original 61e3, guest PC 0x0c09c8a2 */
if(!s->budget--) { s->failed_pc=0x0c09c8a2u; return 0; }
r[1]=r[14];
goto P_0c09c8a4;
P_0c09c8a4: /* original 4108, guest PC 0x0c09c8a4 */
if(!s->budget--) { s->failed_pc=0x0c09c8a4u; return 0; }
r[1]<<=2;
goto P_0c09c8a6;
P_0c09c8a6: /* original 33dc, guest PC 0x0c09c8a6 */
if(!s->budget--) { s->failed_pc=0x0c09c8a6u; return 0; }
r[3]+=r[13];
goto P_0c09c8a8;
P_0c09c8a8: /* original 313c, guest PC 0x0c09c8a8 */
if(!s->budget--) { s->failed_pc=0x0c09c8a8u; return 0; }
r[1]+=r[3];
goto P_0c09c8aa;
P_0c09c8aa: /* original a0a4, guest PC 0x0c09c8aa */
if(!s->budget--) { s->failed_pc=0x0c09c8aau; return 0; }
write(ram,r[1],r[9],4);
goto P_0c09c9f6;
P_0c09c8ac: /* original 2192, guest PC 0x0c09c8ac */
if(!s->budget--) { s->failed_pc=0x0c09c8acu; return 0; }
write(ram,r[1],r[9],4);
return vf3_matrix_family(0x0c09c8aeu,s,ram);
P_0c09c8b6: /* original 4a0b, guest PC 0x0c09c8b6 */
if(!s->budget--) { s->failed_pc=0x0c09c8b6u; return 0; }
target=r[10];
r[16]=0x0c09c8bau;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09c8bau) { target=s->pc; goto dispatch; }
goto P_0c09c8ba;
P_0c09c8b8: /* original 64b3, guest PC 0x0c09c8b8 */
if(!s->budget--) { s->failed_pc=0x0c09c8b8u; return 0; }
r[4]=r[11];
goto P_0c09c8ba;
P_0c09c8ba: /* original 60e3, guest PC 0x0c09c8ba */
if(!s->budget--) { s->failed_pc=0x0c09c8bau; return 0; }
r[0]=r[14];
goto P_0c09c8bc;
P_0c09c8bc: /* original 933f, guest PC 0x0c09c8bc */
if(!s->budget--) { s->failed_pc=0x0c09c8bcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c93eu,2);
goto P_0c09c8be;
P_0c09c8be: /* original 4008, guest PC 0x0c09c8be */
if(!s->budget--) { s->failed_pc=0x0c09c8beu; return 0; }
r[0]<<=2;
goto P_0c09c8c0;
P_0c09c8c0: /* original 62e3, guest PC 0x0c09c8c0 */
if(!s->budget--) { s->failed_pc=0x0c09c8c0u; return 0; }
r[2]=r[14];
goto P_0c09c8c2;
P_0c09c8c2: /* original 4008, guest PC 0x0c09c8c2 */
if(!s->budget--) { s->failed_pc=0x0c09c8c2u; return 0; }
r[0]<<=2;
goto P_0c09c8c4;
P_0c09c8c4: /* original 33dc, guest PC 0x0c09c8c4 */
if(!s->budget--) { s->failed_pc=0x0c09c8c4u; return 0; }
r[3]+=r[13];
goto P_0c09c8c6;
P_0c09c8c6: /* original 4008, guest PC 0x0c09c8c6 */
if(!s->budget--) { s->failed_pc=0x0c09c8c6u; return 0; }
r[0]<<=2;
goto P_0c09c8c8;
P_0c09c8c8: /* original 303c, guest PC 0x0c09c8c8 */
if(!s->budget--) { s->failed_pc=0x0c09c8c8u; return 0; }
r[0]+=r[3];
goto P_0c09c8ca;
P_0c09c8ca: /* original 9339, guest PC 0x0c09c8ca */
if(!s->budget--) { s->failed_pc=0x0c09c8cau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c940u,2);
goto P_0c09c8cc;
P_0c09c8cc: /* original 4208, guest PC 0x0c09c8cc */
if(!s->budget--) { s->failed_pc=0x0c09c8ccu; return 0; }
r[2]<<=2;
goto P_0c09c8ce;
P_0c09c8ce: /* original 33dc, guest PC 0x0c09c8ce */
if(!s->budget--) { s->failed_pc=0x0c09c8ceu; return 0; }
r[3]+=r[13];
goto P_0c09c8d0;
P_0c09c8d0: /* original 323c, guest PC 0x0c09c8d0 */
if(!s->budget--) { s->failed_pc=0x0c09c8d0u; return 0; }
r[2]+=r[3];
goto P_0c09c8d2;
P_0c09c8d2: /* original 6122, guest PC 0x0c09c8d2 */
if(!s->budget--) { s->failed_pc=0x0c09c8d2u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c8d4;
P_0c09c8d4: /* original 4108, guest PC 0x0c09c8d4 */
if(!s->budget--) { s->failed_pc=0x0c09c8d4u; return 0; }
r[1]<<=2;
goto P_0c09c8d6;
P_0c09c8d6: /* original 031e, guest PC 0x0c09c8d6 */
if(!s->budget--) { s->failed_pc=0x0c09c8d6u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c8d8;
P_0c09c8d8: /* original 2338, guest PC 0x0c09c8d8 */
if(!s->budget--) { s->failed_pc=0x0c09c8d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09c8da;
P_0c09c8da: /* original 8b0f, guest PC 0x0c09c8da */
if(!s->budget--) { s->failed_pc=0x0c09c8dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c8fc; }
goto P_0c09c8dc;
P_0c09c8dc: /* original 60e3, guest PC 0x0c09c8dc */
if(!s->budget--) { s->failed_pc=0x0c09c8dcu; return 0; }
r[0]=r[14];
goto P_0c09c8de;
P_0c09c8de: /* original 932e, guest PC 0x0c09c8de */
if(!s->budget--) { s->failed_pc=0x0c09c8deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c93eu,2);
goto P_0c09c8e0;
P_0c09c8e0: /* original 4008, guest PC 0x0c09c8e0 */
if(!s->budget--) { s->failed_pc=0x0c09c8e0u; return 0; }
r[0]<<=2;
goto P_0c09c8e2;
P_0c09c8e2: /* original 62e3, guest PC 0x0c09c8e2 */
if(!s->budget--) { s->failed_pc=0x0c09c8e2u; return 0; }
r[2]=r[14];
goto P_0c09c8e4;
P_0c09c8e4: /* original 4008, guest PC 0x0c09c8e4 */
if(!s->budget--) { s->failed_pc=0x0c09c8e4u; return 0; }
r[0]<<=2;
goto P_0c09c8e6;
P_0c09c8e6: /* original 33dc, guest PC 0x0c09c8e6 */
if(!s->budget--) { s->failed_pc=0x0c09c8e6u; return 0; }
r[3]+=r[13];
goto P_0c09c8e8;
P_0c09c8e8: /* original 4008, guest PC 0x0c09c8e8 */
if(!s->budget--) { s->failed_pc=0x0c09c8e8u; return 0; }
r[0]<<=2;
goto P_0c09c8ea;
P_0c09c8ea: /* original 303c, guest PC 0x0c09c8ea */
if(!s->budget--) { s->failed_pc=0x0c09c8eau; return 0; }
r[0]+=r[3];
goto P_0c09c8ec;
P_0c09c8ec: /* original 9328, guest PC 0x0c09c8ec */
if(!s->budget--) { s->failed_pc=0x0c09c8ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c940u,2);
goto P_0c09c8ee;
P_0c09c8ee: /* original 4208, guest PC 0x0c09c8ee */
if(!s->budget--) { s->failed_pc=0x0c09c8eeu; return 0; }
r[2]<<=2;
goto P_0c09c8f0;
P_0c09c8f0: /* original 33dc, guest PC 0x0c09c8f0 */
if(!s->budget--) { s->failed_pc=0x0c09c8f0u; return 0; }
r[3]+=r[13];
goto P_0c09c8f2;
P_0c09c8f2: /* original 323c, guest PC 0x0c09c8f2 */
if(!s->budget--) { s->failed_pc=0x0c09c8f2u; return 0; }
r[2]+=r[3];
goto P_0c09c8f4;
P_0c09c8f4: /* original 6122, guest PC 0x0c09c8f4 */
if(!s->budget--) { s->failed_pc=0x0c09c8f4u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c8f6;
P_0c09c8f6: /* original 4108, guest PC 0x0c09c8f6 */
if(!s->budget--) { s->failed_pc=0x0c09c8f6u; return 0; }
r[1]<<=2;
goto P_0c09c8f8;
P_0c09c8f8: /* original a035, guest PC 0x0c09c8f8 */
if(!s->budget--) { s->failed_pc=0x0c09c8f8u; return 0; }
write(ram,r[1]+r[0],r[8],4);
goto P_0c09c966;
P_0c09c8fa: /* original 0186, guest PC 0x0c09c8fa */
if(!s->budget--) { s->failed_pc=0x0c09c8fau; return 0; }
write(ram,r[1]+r[0],r[8],4);
goto P_0c09c8fc;
P_0c09c8fc: /* original 60e3, guest PC 0x0c09c8fc */
if(!s->budget--) { s->failed_pc=0x0c09c8fcu; return 0; }
r[0]=r[14];
goto P_0c09c8fe;
P_0c09c8fe: /* original 931e, guest PC 0x0c09c8fe */
if(!s->budget--) { s->failed_pc=0x0c09c8feu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c93eu,2);
goto P_0c09c900;
P_0c09c900: /* original 4008, guest PC 0x0c09c900 */
if(!s->budget--) { s->failed_pc=0x0c09c900u; return 0; }
r[0]<<=2;
goto P_0c09c902;
P_0c09c902: /* original 62e3, guest PC 0x0c09c902 */
if(!s->budget--) { s->failed_pc=0x0c09c902u; return 0; }
r[2]=r[14];
goto P_0c09c904;
P_0c09c904: /* original 4008, guest PC 0x0c09c904 */
if(!s->budget--) { s->failed_pc=0x0c09c904u; return 0; }
r[0]<<=2;
goto P_0c09c906;
P_0c09c906: /* original 33dc, guest PC 0x0c09c906 */
if(!s->budget--) { s->failed_pc=0x0c09c906u; return 0; }
r[3]+=r[13];
goto P_0c09c908;
P_0c09c908: /* original 4008, guest PC 0x0c09c908 */
if(!s->budget--) { s->failed_pc=0x0c09c908u; return 0; }
r[0]<<=2;
goto P_0c09c90a;
P_0c09c90a: /* original 303c, guest PC 0x0c09c90a */
if(!s->budget--) { s->failed_pc=0x0c09c90au; return 0; }
r[0]+=r[3];
goto P_0c09c90c;
P_0c09c90c: /* original 9318, guest PC 0x0c09c90c */
if(!s->budget--) { s->failed_pc=0x0c09c90cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c940u,2);
goto P_0c09c90e;
P_0c09c90e: /* original 4208, guest PC 0x0c09c90e */
if(!s->budget--) { s->failed_pc=0x0c09c90eu; return 0; }
r[2]<<=2;
goto P_0c09c910;
P_0c09c910: /* original 33dc, guest PC 0x0c09c910 */
if(!s->budget--) { s->failed_pc=0x0c09c910u; return 0; }
r[3]+=r[13];
goto P_0c09c912;
P_0c09c912: /* original 323c, guest PC 0x0c09c912 */
if(!s->budget--) { s->failed_pc=0x0c09c912u; return 0; }
r[2]+=r[3];
goto P_0c09c914;
P_0c09c914: /* original 6122, guest PC 0x0c09c914 */
if(!s->budget--) { s->failed_pc=0x0c09c914u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c916;
P_0c09c916: /* original 4108, guest PC 0x0c09c916 */
if(!s->budget--) { s->failed_pc=0x0c09c916u; return 0; }
r[1]<<=2;
goto P_0c09c918;
P_0c09c918: /* original 001e, guest PC 0x0c09c918 */
if(!s->budget--) { s->failed_pc=0x0c09c918u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c09c91a;
P_0c09c91a: /* original 8801, guest PC 0x0c09c91a */
if(!s->budget--) { s->failed_pc=0x0c09c91au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09c91c;
P_0c09c91c: /* original 8b11, guest PC 0x0c09c91c */
if(!s->budget--) { s->failed_pc=0x0c09c91cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c942; }
goto P_0c09c91e;
P_0c09c91e: /* original 60e3, guest PC 0x0c09c91e */
if(!s->budget--) { s->failed_pc=0x0c09c91eu; return 0; }
r[0]=r[14];
goto P_0c09c920;
P_0c09c920: /* original 930d, guest PC 0x0c09c920 */
if(!s->budget--) { s->failed_pc=0x0c09c920u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c93eu,2);
goto P_0c09c922;
P_0c09c922: /* original 4008, guest PC 0x0c09c922 */
if(!s->budget--) { s->failed_pc=0x0c09c922u; return 0; }
r[0]<<=2;
goto P_0c09c924;
P_0c09c924: /* original 62e3, guest PC 0x0c09c924 */
if(!s->budget--) { s->failed_pc=0x0c09c924u; return 0; }
r[2]=r[14];
goto P_0c09c926;
P_0c09c926: /* original 4008, guest PC 0x0c09c926 */
if(!s->budget--) { s->failed_pc=0x0c09c926u; return 0; }
r[0]<<=2;
goto P_0c09c928;
P_0c09c928: /* original 33dc, guest PC 0x0c09c928 */
if(!s->budget--) { s->failed_pc=0x0c09c928u; return 0; }
r[3]+=r[13];
goto P_0c09c92a;
P_0c09c92a: /* original 4008, guest PC 0x0c09c92a */
if(!s->budget--) { s->failed_pc=0x0c09c92au; return 0; }
r[0]<<=2;
goto P_0c09c92c;
P_0c09c92c: /* original 303c, guest PC 0x0c09c92c */
if(!s->budget--) { s->failed_pc=0x0c09c92cu; return 0; }
r[0]+=r[3];
goto P_0c09c92e;
P_0c09c92e: /* original 9307, guest PC 0x0c09c92e */
if(!s->budget--) { s->failed_pc=0x0c09c92eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c940u,2);
goto P_0c09c930;
P_0c09c930: /* original 4208, guest PC 0x0c09c930 */
if(!s->budget--) { s->failed_pc=0x0c09c930u; return 0; }
r[2]<<=2;
goto P_0c09c932;
P_0c09c932: /* original 33dc, guest PC 0x0c09c932 */
if(!s->budget--) { s->failed_pc=0x0c09c932u; return 0; }
r[3]+=r[13];
goto P_0c09c934;
P_0c09c934: /* original 323c, guest PC 0x0c09c934 */
if(!s->budget--) { s->failed_pc=0x0c09c934u; return 0; }
r[2]+=r[3];
goto P_0c09c936;
P_0c09c936: /* original 6122, guest PC 0x0c09c936 */
if(!s->budget--) { s->failed_pc=0x0c09c936u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c938;
P_0c09c938: /* original 4108, guest PC 0x0c09c938 */
if(!s->budget--) { s->failed_pc=0x0c09c938u; return 0; }
r[1]<<=2;
goto P_0c09c93a;
P_0c09c93a: /* original a014, guest PC 0x0c09c93a */
if(!s->budget--) { s->failed_pc=0x0c09c93au; return 0; }
write(ram,r[1]+r[0],r[9],4);
goto P_0c09c966;
P_0c09c93c: /* original 0196, guest PC 0x0c09c93c */
if(!s->budget--) { s->failed_pc=0x0c09c93cu; return 0; }
write(ram,r[1]+r[0],r[9],4);
return vf3_matrix_family(0x0c09c93eu,s,ram);
P_0c09c942: /* original 64e3, guest PC 0x0c09c942 */
if(!s->budget--) { s->failed_pc=0x0c09c942u; return 0; }
r[4]=r[14];
goto P_0c09c944;
P_0c09c944: /* original 937b, guest PC 0x0c09c944 */
if(!s->budget--) { s->failed_pc=0x0c09c944u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c946;
P_0c09c946: /* original 4408, guest PC 0x0c09c946 */
if(!s->budget--) { s->failed_pc=0x0c09c946u; return 0; }
r[4]<<=2;
goto P_0c09c948;
P_0c09c948: /* original 62e3, guest PC 0x0c09c948 */
if(!s->budget--) { s->failed_pc=0x0c09c948u; return 0; }
r[2]=r[14];
goto P_0c09c94a;
P_0c09c94a: /* original 4408, guest PC 0x0c09c94a */
if(!s->budget--) { s->failed_pc=0x0c09c94au; return 0; }
r[4]<<=2;
goto P_0c09c94c;
P_0c09c94c: /* original 33dc, guest PC 0x0c09c94c */
if(!s->budget--) { s->failed_pc=0x0c09c94cu; return 0; }
r[3]+=r[13];
goto P_0c09c94e;
P_0c09c94e: /* original 4408, guest PC 0x0c09c94e */
if(!s->budget--) { s->failed_pc=0x0c09c94eu; return 0; }
r[4]<<=2;
goto P_0c09c950;
P_0c09c950: /* original 343c, guest PC 0x0c09c950 */
if(!s->budget--) { s->failed_pc=0x0c09c950u; return 0; }
r[4]+=r[3];
goto P_0c09c952;
P_0c09c952: /* original 9375, guest PC 0x0c09c952 */
if(!s->budget--) { s->failed_pc=0x0c09c952u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c954;
P_0c09c954: /* original 4208, guest PC 0x0c09c954 */
if(!s->budget--) { s->failed_pc=0x0c09c954u; return 0; }
r[2]<<=2;
goto P_0c09c956;
P_0c09c956: /* original 33dc, guest PC 0x0c09c956 */
if(!s->budget--) { s->failed_pc=0x0c09c956u; return 0; }
r[3]+=r[13];
goto P_0c09c958;
P_0c09c958: /* original 323c, guest PC 0x0c09c958 */
if(!s->budget--) { s->failed_pc=0x0c09c958u; return 0; }
r[2]+=r[3];
goto P_0c09c95a;
P_0c09c95a: /* original 6122, guest PC 0x0c09c95a */
if(!s->budget--) { s->failed_pc=0x0c09c95au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c95c;
P_0c09c95c: /* original 4108, guest PC 0x0c09c95c */
if(!s->budget--) { s->failed_pc=0x0c09c95cu; return 0; }
r[1]<<=2;
goto P_0c09c95e;
P_0c09c95e: /* original 341c, guest PC 0x0c09c95e */
if(!s->budget--) { s->failed_pc=0x0c09c95eu; return 0; }
r[4]+=r[1];
goto P_0c09c960;
P_0c09c960: /* original 6342, guest PC 0x0c09c960 */
if(!s->budget--) { s->failed_pc=0x0c09c960u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09c962;
P_0c09c962: /* original 4321, guest PC 0x0c09c962 */
if(!s->budget--) { s->failed_pc=0x0c09c962u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c09c964;
P_0c09c964: /* original 2432, guest PC 0x0c09c964 */
if(!s->budget--) { s->failed_pc=0x0c09c964u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c09c966;
P_0c09c966: /* original 936b, guest PC 0x0c09c966 */
if(!s->budget--) { s->failed_pc=0x0c09c966u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c968;
P_0c09c968: /* original 60e3, guest PC 0x0c09c968 */
if(!s->budget--) { s->failed_pc=0x0c09c968u; return 0; }
r[0]=r[14];
goto P_0c09c96a;
P_0c09c96a: /* original 4008, guest PC 0x0c09c96a */
if(!s->budget--) { s->failed_pc=0x0c09c96au; return 0; }
r[0]<<=2;
goto P_0c09c96c;
P_0c09c96c: /* original 33dc, guest PC 0x0c09c96c */
if(!s->budget--) { s->failed_pc=0x0c09c96cu; return 0; }
r[3]+=r[13];
goto P_0c09c96e;
P_0c09c96e: /* original 003e, guest PC 0x0c09c96e */
if(!s->budget--) { s->failed_pc=0x0c09c96eu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c970;
P_0c09c970: /* original 8801, guest PC 0x0c09c970 */
if(!s->budget--) { s->failed_pc=0x0c09c970u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09c972;
P_0c09c972: /* original 8b40, guest PC 0x0c09c972 */
if(!s->budget--) { s->failed_pc=0x0c09c972u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c9f6; }
goto P_0c09c974;
P_0c09c974: /* original 60e3, guest PC 0x0c09c974 */
if(!s->budget--) { s->failed_pc=0x0c09c974u; return 0; }
r[0]=r[14];
goto P_0c09c976;
P_0c09c976: /* original 9362, guest PC 0x0c09c976 */
if(!s->budget--) { s->failed_pc=0x0c09c976u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c978;
P_0c09c978: /* original 4008, guest PC 0x0c09c978 */
if(!s->budget--) { s->failed_pc=0x0c09c978u; return 0; }
r[0]<<=2;
goto P_0c09c97a;
P_0c09c97a: /* original 62e3, guest PC 0x0c09c97a */
if(!s->budget--) { s->failed_pc=0x0c09c97au; return 0; }
r[2]=r[14];
goto P_0c09c97c;
P_0c09c97c: /* original 4008, guest PC 0x0c09c97c */
if(!s->budget--) { s->failed_pc=0x0c09c97cu; return 0; }
r[0]<<=2;
goto P_0c09c97e;
P_0c09c97e: /* original 33dc, guest PC 0x0c09c97e */
if(!s->budget--) { s->failed_pc=0x0c09c97eu; return 0; }
r[3]+=r[13];
goto P_0c09c980;
P_0c09c980: /* original 4008, guest PC 0x0c09c980 */
if(!s->budget--) { s->failed_pc=0x0c09c980u; return 0; }
r[0]<<=2;
goto P_0c09c982;
P_0c09c982: /* original 303c, guest PC 0x0c09c982 */
if(!s->budget--) { s->failed_pc=0x0c09c982u; return 0; }
r[0]+=r[3];
goto P_0c09c984;
P_0c09c984: /* original 935c, guest PC 0x0c09c984 */
if(!s->budget--) { s->failed_pc=0x0c09c984u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c986;
P_0c09c986: /* original 4208, guest PC 0x0c09c986 */
if(!s->budget--) { s->failed_pc=0x0c09c986u; return 0; }
r[2]<<=2;
goto P_0c09c988;
P_0c09c988: /* original 33dc, guest PC 0x0c09c988 */
if(!s->budget--) { s->failed_pc=0x0c09c988u; return 0; }
r[3]+=r[13];
goto P_0c09c98a;
P_0c09c98a: /* original 323c, guest PC 0x0c09c98a */
if(!s->budget--) { s->failed_pc=0x0c09c98au; return 0; }
r[2]+=r[3];
goto P_0c09c98c;
P_0c09c98c: /* original 6122, guest PC 0x0c09c98c */
if(!s->budget--) { s->failed_pc=0x0c09c98cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c98e;
P_0c09c98e: /* original 4108, guest PC 0x0c09c98e */
if(!s->budget--) { s->failed_pc=0x0c09c98eu; return 0; }
r[1]<<=2;
goto P_0c09c990;
P_0c09c990: /* original 001e, guest PC 0x0c09c990 */
if(!s->budget--) { s->failed_pc=0x0c09c990u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c09c992;
P_0c09c992: /* original 8810, guest PC 0x0c09c992 */
if(!s->budget--) { s->failed_pc=0x0c09c992u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c09c994;
P_0c09c994: /* original 8b0f, guest PC 0x0c09c994 */
if(!s->budget--) { s->failed_pc=0x0c09c994u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c9b6; }
goto P_0c09c996;
P_0c09c996: /* original 60e3, guest PC 0x0c09c996 */
if(!s->budget--) { s->failed_pc=0x0c09c996u; return 0; }
r[0]=r[14];
goto P_0c09c998;
P_0c09c998: /* original 9351, guest PC 0x0c09c998 */
if(!s->budget--) { s->failed_pc=0x0c09c998u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c99a;
P_0c09c99a: /* original 4008, guest PC 0x0c09c99a */
if(!s->budget--) { s->failed_pc=0x0c09c99au; return 0; }
r[0]<<=2;
goto P_0c09c99c;
P_0c09c99c: /* original 62e3, guest PC 0x0c09c99c */
if(!s->budget--) { s->failed_pc=0x0c09c99cu; return 0; }
r[2]=r[14];
goto P_0c09c99e;
P_0c09c99e: /* original 4008, guest PC 0x0c09c99e */
if(!s->budget--) { s->failed_pc=0x0c09c99eu; return 0; }
r[0]<<=2;
goto P_0c09c9a0;
P_0c09c9a0: /* original 33dc, guest PC 0x0c09c9a0 */
if(!s->budget--) { s->failed_pc=0x0c09c9a0u; return 0; }
r[3]+=r[13];
goto P_0c09c9a2;
P_0c09c9a2: /* original 4008, guest PC 0x0c09c9a2 */
if(!s->budget--) { s->failed_pc=0x0c09c9a2u; return 0; }
r[0]<<=2;
goto P_0c09c9a4;
P_0c09c9a4: /* original 303c, guest PC 0x0c09c9a4 */
if(!s->budget--) { s->failed_pc=0x0c09c9a4u; return 0; }
r[0]+=r[3];
goto P_0c09c9a6;
P_0c09c9a6: /* original 934b, guest PC 0x0c09c9a6 */
if(!s->budget--) { s->failed_pc=0x0c09c9a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c9a8;
P_0c09c9a8: /* original 4208, guest PC 0x0c09c9a8 */
if(!s->budget--) { s->failed_pc=0x0c09c9a8u; return 0; }
r[2]<<=2;
goto P_0c09c9aa;
P_0c09c9aa: /* original 33dc, guest PC 0x0c09c9aa */
if(!s->budget--) { s->failed_pc=0x0c09c9aau; return 0; }
r[3]+=r[13];
goto P_0c09c9ac;
P_0c09c9ac: /* original 323c, guest PC 0x0c09c9ac */
if(!s->budget--) { s->failed_pc=0x0c09c9acu; return 0; }
r[2]+=r[3];
goto P_0c09c9ae;
P_0c09c9ae: /* original 6122, guest PC 0x0c09c9ae */
if(!s->budget--) { s->failed_pc=0x0c09c9aeu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c9b0;
P_0c09c9b0: /* original e308, guest PC 0x0c09c9b0 */
if(!s->budget--) { s->failed_pc=0x0c09c9b0u; return 0; }
r[3]=0x00000008u;
goto P_0c09c9b2;
P_0c09c9b2: /* original 4108, guest PC 0x0c09c9b2 */
if(!s->budget--) { s->failed_pc=0x0c09c9b2u; return 0; }
r[1]<<=2;
goto P_0c09c9b4;
P_0c09c9b4: /* original 0136, guest PC 0x0c09c9b4 */
if(!s->budget--) { s->failed_pc=0x0c09c9b4u; return 0; }
write(ram,r[1]+r[0],r[3],4);
goto P_0c09c9b6;
P_0c09c9b6: /* original 60e3, guest PC 0x0c09c9b6 */
if(!s->budget--) { s->failed_pc=0x0c09c9b6u; return 0; }
r[0]=r[14];
goto P_0c09c9b8;
P_0c09c9b8: /* original 9341, guest PC 0x0c09c9b8 */
if(!s->budget--) { s->failed_pc=0x0c09c9b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c9ba;
P_0c09c9ba: /* original 4008, guest PC 0x0c09c9ba */
if(!s->budget--) { s->failed_pc=0x0c09c9bau; return 0; }
r[0]<<=2;
goto P_0c09c9bc;
P_0c09c9bc: /* original 62e3, guest PC 0x0c09c9bc */
if(!s->budget--) { s->failed_pc=0x0c09c9bcu; return 0; }
r[2]=r[14];
goto P_0c09c9be;
P_0c09c9be: /* original 4008, guest PC 0x0c09c9be */
if(!s->budget--) { s->failed_pc=0x0c09c9beu; return 0; }
r[0]<<=2;
goto P_0c09c9c0;
P_0c09c9c0: /* original 33dc, guest PC 0x0c09c9c0 */
if(!s->budget--) { s->failed_pc=0x0c09c9c0u; return 0; }
r[3]+=r[13];
goto P_0c09c9c2;
P_0c09c9c2: /* original 4008, guest PC 0x0c09c9c2 */
if(!s->budget--) { s->failed_pc=0x0c09c9c2u; return 0; }
r[0]<<=2;
goto P_0c09c9c4;
P_0c09c9c4: /* original 303c, guest PC 0x0c09c9c4 */
if(!s->budget--) { s->failed_pc=0x0c09c9c4u; return 0; }
r[0]+=r[3];
goto P_0c09c9c6;
P_0c09c9c6: /* original 933b, guest PC 0x0c09c9c6 */
if(!s->budget--) { s->failed_pc=0x0c09c9c6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c9c8;
P_0c09c9c8: /* original 4208, guest PC 0x0c09c9c8 */
if(!s->budget--) { s->failed_pc=0x0c09c9c8u; return 0; }
r[2]<<=2;
goto P_0c09c9ca;
P_0c09c9ca: /* original 33dc, guest PC 0x0c09c9ca */
if(!s->budget--) { s->failed_pc=0x0c09c9cau; return 0; }
r[3]+=r[13];
goto P_0c09c9cc;
P_0c09c9cc: /* original 323c, guest PC 0x0c09c9cc */
if(!s->budget--) { s->failed_pc=0x0c09c9ccu; return 0; }
r[2]+=r[3];
goto P_0c09c9ce;
P_0c09c9ce: /* original 6122, guest PC 0x0c09c9ce */
if(!s->budget--) { s->failed_pc=0x0c09c9ceu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c9d0;
P_0c09c9d0: /* original 4108, guest PC 0x0c09c9d0 */
if(!s->budget--) { s->failed_pc=0x0c09c9d0u; return 0; }
r[1]<<=2;
goto P_0c09c9d2;
P_0c09c9d2: /* original 031e, guest PC 0x0c09c9d2 */
if(!s->budget--) { s->failed_pc=0x0c09c9d2u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c9d4;
P_0c09c9d4: /* original 2338, guest PC 0x0c09c9d4 */
if(!s->budget--) { s->failed_pc=0x0c09c9d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09c9d6;
P_0c09c9d6: /* original 8b0e, guest PC 0x0c09c9d6 */
if(!s->budget--) { s->failed_pc=0x0c09c9d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c9f6; }
goto P_0c09c9d8;
P_0c09c9d8: /* original 60e3, guest PC 0x0c09c9d8 */
if(!s->budget--) { s->failed_pc=0x0c09c9d8u; return 0; }
r[0]=r[14];
goto P_0c09c9da;
P_0c09c9da: /* original 9330, guest PC 0x0c09c9da */
if(!s->budget--) { s->failed_pc=0x0c09c9dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c9dc;
P_0c09c9dc: /* original 4008, guest PC 0x0c09c9dc */
if(!s->budget--) { s->failed_pc=0x0c09c9dcu; return 0; }
r[0]<<=2;
goto P_0c09c9de;
P_0c09c9de: /* original 62e3, guest PC 0x0c09c9de */
if(!s->budget--) { s->failed_pc=0x0c09c9deu; return 0; }
r[2]=r[14];
goto P_0c09c9e0;
P_0c09c9e0: /* original 4008, guest PC 0x0c09c9e0 */
if(!s->budget--) { s->failed_pc=0x0c09c9e0u; return 0; }
r[0]<<=2;
goto P_0c09c9e2;
P_0c09c9e2: /* original 33dc, guest PC 0x0c09c9e2 */
if(!s->budget--) { s->failed_pc=0x0c09c9e2u; return 0; }
r[3]+=r[13];
goto P_0c09c9e4;
P_0c09c9e4: /* original 4008, guest PC 0x0c09c9e4 */
if(!s->budget--) { s->failed_pc=0x0c09c9e4u; return 0; }
r[0]<<=2;
goto P_0c09c9e6;
P_0c09c9e6: /* original 303c, guest PC 0x0c09c9e6 */
if(!s->budget--) { s->failed_pc=0x0c09c9e6u; return 0; }
r[0]+=r[3];
goto P_0c09c9e8;
P_0c09c9e8: /* original 932a, guest PC 0x0c09c9e8 */
if(!s->budget--) { s->failed_pc=0x0c09c9e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c9ea;
P_0c09c9ea: /* original 4208, guest PC 0x0c09c9ea */
if(!s->budget--) { s->failed_pc=0x0c09c9eau; return 0; }
r[2]<<=2;
goto P_0c09c9ec;
P_0c09c9ec: /* original 33dc, guest PC 0x0c09c9ec */
if(!s->budget--) { s->failed_pc=0x0c09c9ecu; return 0; }
r[3]+=r[13];
goto P_0c09c9ee;
P_0c09c9ee: /* original 323c, guest PC 0x0c09c9ee */
if(!s->budget--) { s->failed_pc=0x0c09c9eeu; return 0; }
r[2]+=r[3];
goto P_0c09c9f0;
P_0c09c9f0: /* original 6122, guest PC 0x0c09c9f0 */
if(!s->budget--) { s->failed_pc=0x0c09c9f0u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c9f2;
P_0c09c9f2: /* original 4108, guest PC 0x0c09c9f2 */
if(!s->budget--) { s->failed_pc=0x0c09c9f2u; return 0; }
r[1]<<=2;
goto P_0c09c9f4;
P_0c09c9f4: /* original 0186, guest PC 0x0c09c9f4 */
if(!s->budget--) { s->failed_pc=0x0c09c9f4u; return 0; }
write(ram,r[1]+r[0],r[8],4);
goto P_0c09c9f6;
P_0c09c9f6: /* original 7e01, guest PC 0x0c09c9f6 */
if(!s->budget--) { s->failed_pc=0x0c09c9f6u; return 0; }
r[14]+=0x00000001u;
goto P_0c09c9f8;
P_0c09c9f8: /* original e402, guest PC 0x0c09c9f8 */
if(!s->budget--) { s->failed_pc=0x0c09c9f8u; return 0; }
r[4]=0x00000002u;
goto P_0c09c9fa;
P_0c09c9fa: /* original 3e43, guest PC 0x0c09c9fa */
if(!s->budget--) { s->failed_pc=0x0c09c9fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[4])!=0);
goto P_0c09c9fc;
P_0c09c9fc: /* original 8901, guest PC 0x0c09c9fc */
if(!s->budget--) { s->failed_pc=0x0c09c9fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca02; }
goto P_0c09c9fe;
P_0c09c9fe: /* original ac11, guest PC 0x0c09c9fe */
if(!s->budget--) { s->failed_pc=0x0c09c9feu; return 0; }
goto P_0c09c224;
P_0c09ca00: /* original 0009, guest PC 0x0c09ca00 */
if(!s->budget--) { s->failed_pc=0x0c09ca00u; return 0; }
goto P_0c09ca02;
P_0c09ca02: /* original 901e, guest PC 0x0c09ca02 */
if(!s->budget--) { s->failed_pc=0x0c09ca02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca42u,2);
goto P_0c09ca04;
P_0c09ca04: /* original 00de, guest PC 0x0c09ca04 */
if(!s->budget--) { s->failed_pc=0x0c09ca04u; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca06;
P_0c09ca06: /* original c804, guest PC 0x0c09ca06 */
if(!s->budget--) { s->failed_pc=0x0c09ca06u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09ca08;
P_0c09ca08: /* original 890c, guest PC 0x0c09ca08 */
if(!s->budget--) { s->failed_pc=0x0c09ca08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca24; }
goto P_0c09ca0a;
P_0c09ca0a: /* original 901b, guest PC 0x0c09ca0a */
if(!s->budget--) { s->failed_pc=0x0c09ca0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca44u,2);
goto P_0c09ca0c;
P_0c09ca0c: /* original 00de, guest PC 0x0c09ca0c */
if(!s->budget--) { s->failed_pc=0x0c09ca0cu; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca0e;
P_0c09ca0e: /* original c804, guest PC 0x0c09ca0e */
if(!s->budget--) { s->failed_pc=0x0c09ca0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09ca10;
P_0c09ca10: /* original 8b2d, guest PC 0x0c09ca10 */
if(!s->budget--) { s->failed_pc=0x0c09ca10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ca6e; }
goto P_0c09ca12;
P_0c09ca12: /* original 9017, guest PC 0x0c09ca12 */
if(!s->budget--) { s->failed_pc=0x0c09ca12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca44u,2);
goto P_0c09ca14;
P_0c09ca14: /* original 03de, guest PC 0x0c09ca14 */
if(!s->budget--) { s->failed_pc=0x0c09ca14u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c09ca16;
P_0c09ca16: /* original 23c8, guest PC 0x0c09ca16 */
if(!s->budget--) { s->failed_pc=0x0c09ca16u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09ca18;
P_0c09ca18: /* original 892e, guest PC 0x0c09ca18 */
if(!s->budget--) { s->failed_pc=0x0c09ca18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca78; }
goto P_0c09ca1a;
P_0c09ca1a: /* original 00de, guest PC 0x0c09ca1a */
if(!s->budget--) { s->failed_pc=0x0c09ca1au; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca1c;
P_0c09ca1c: /* original c808, guest PC 0x0c09ca1c */
if(!s->budget--) { s->failed_pc=0x0c09ca1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09ca1e;
P_0c09ca1e: /* original 8b22, guest PC 0x0c09ca1e */
if(!s->budget--) { s->failed_pc=0x0c09ca1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ca66; }
goto P_0c09ca20;
P_0c09ca20: /* original a025, guest PC 0x0c09ca20 */
if(!s->budget--) { s->failed_pc=0x0c09ca20u; return 0; }
goto P_0c09ca6e;
P_0c09ca22: /* original 0009, guest PC 0x0c09ca22 */
if(!s->budget--) { s->failed_pc=0x0c09ca22u; return 0; }
goto P_0c09ca24;
P_0c09ca24: /* original 900e, guest PC 0x0c09ca24 */
if(!s->budget--) { s->failed_pc=0x0c09ca24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca44u,2);
goto P_0c09ca26;
P_0c09ca26: /* original 00de, guest PC 0x0c09ca26 */
if(!s->budget--) { s->failed_pc=0x0c09ca26u; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca28;
P_0c09ca28: /* original c804, guest PC 0x0c09ca28 */
if(!s->budget--) { s->failed_pc=0x0c09ca28u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09ca2a;
P_0c09ca2a: /* original 890c, guest PC 0x0c09ca2a */
if(!s->budget--) { s->failed_pc=0x0c09ca2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca46; }
goto P_0c09ca2c;
P_0c09ca2c: /* original 9009, guest PC 0x0c09ca2c */
if(!s->budget--) { s->failed_pc=0x0c09ca2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca42u,2);
goto P_0c09ca2e;
P_0c09ca2e: /* original 02de, guest PC 0x0c09ca2e */
if(!s->budget--) { s->failed_pc=0x0c09ca2eu; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c09ca30;
P_0c09ca30: /* original 22c8, guest PC 0x0c09ca30 */
if(!s->budget--) { s->failed_pc=0x0c09ca30u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c09ca32;
P_0c09ca32: /* original 8921, guest PC 0x0c09ca32 */
if(!s->budget--) { s->failed_pc=0x0c09ca32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca78; }
goto P_0c09ca34;
P_0c09ca34: /* original 00de, guest PC 0x0c09ca34 */
if(!s->budget--) { s->failed_pc=0x0c09ca34u; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca36;
P_0c09ca36: /* original c808, guest PC 0x0c09ca36 */
if(!s->budget--) { s->failed_pc=0x0c09ca36u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09ca38;
P_0c09ca38: /* original 8919, guest PC 0x0c09ca38 */
if(!s->budget--) { s->failed_pc=0x0c09ca38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca6e; }
goto P_0c09ca3a;
P_0c09ca3a: /* original a014, guest PC 0x0c09ca3a */
if(!s->budget--) { s->failed_pc=0x0c09ca3au; return 0; }
goto P_0c09ca66;
P_0c09ca3c: /* original 0009, guest PC 0x0c09ca3c */
if(!s->budget--) { s->failed_pc=0x0c09ca3cu; return 0; }
return vf3_matrix_family(0x0c09ca3eu,s,ram);
P_0c09ca46: /* original 9478, guest PC 0x0c09ca46 */
if(!s->budget--) { s->failed_pc=0x0c09ca46u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb3au,2);
goto P_0c09ca48;
P_0c09ca48: /* original 34dc, guest PC 0x0c09ca48 */
if(!s->budget--) { s->failed_pc=0x0c09ca48u; return 0; }
r[4]+=r[13];
goto P_0c09ca4a;
P_0c09ca4a: /* original 6042, guest PC 0x0c09ca4a */
if(!s->budget--) { s->failed_pc=0x0c09ca4au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09ca4c;
P_0c09ca4c: /* original 5341, guest PC 0x0c09ca4c */
if(!s->budget--) { s->failed_pc=0x0c09ca4cu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09ca4e;
P_0c09ca4e: /* original 2039, guest PC 0x0c09ca4e */
if(!s->budget--) { s->failed_pc=0x0c09ca4eu; return 0; }
r[0]&=r[3];
goto P_0c09ca50;
P_0c09ca50: /* original 20c9, guest PC 0x0c09ca50 */
if(!s->budget--) { s->failed_pc=0x0c09ca50u; return 0; }
r[0]&=r[12];
goto P_0c09ca52;
P_0c09ca52: /* original 8801, guest PC 0x0c09ca52 */
if(!s->budget--) { s->failed_pc=0x0c09ca52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09ca54;
P_0c09ca54: /* original 8b10, guest PC 0x0c09ca54 */
if(!s->budget--) { s->failed_pc=0x0c09ca54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ca78; }
goto P_0c09ca56;
P_0c09ca56: /* original 9470, guest PC 0x0c09ca56 */
if(!s->budget--) { s->failed_pc=0x0c09ca56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb3au,2);
goto P_0c09ca58;
P_0c09ca58: /* original 34dc, guest PC 0x0c09ca58 */
if(!s->budget--) { s->failed_pc=0x0c09ca58u; return 0; }
r[4]+=r[13];
goto P_0c09ca5a;
P_0c09ca5a: /* original 6042, guest PC 0x0c09ca5a */
if(!s->budget--) { s->failed_pc=0x0c09ca5au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09ca5c;
P_0c09ca5c: /* original 5341, guest PC 0x0c09ca5c */
if(!s->budget--) { s->failed_pc=0x0c09ca5cu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09ca5e;
P_0c09ca5e: /* original 203b, guest PC 0x0c09ca5e */
if(!s->budget--) { s->failed_pc=0x0c09ca5eu; return 0; }
r[0]|=r[3];
goto P_0c09ca60;
P_0c09ca60: /* original c908, guest PC 0x0c09ca60 */
if(!s->budget--) { s->failed_pc=0x0c09ca60u; return 0; }
r[0]&=8u;
goto P_0c09ca62;
P_0c09ca62: /* original 8808, guest PC 0x0c09ca62 */
if(!s->budget--) { s->failed_pc=0x0c09ca62u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09ca64;
P_0c09ca64: /* original 8b03, guest PC 0x0c09ca64 */
if(!s->budget--) { s->failed_pc=0x0c09ca64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ca6e; }
goto P_0c09ca66;
P_0c09ca66: /* original 60c3, guest PC 0x0c09ca66 */
if(!s->budget--) { s->failed_pc=0x0c09ca66u; return 0; }
r[0]=r[12];
goto P_0c09ca68;
P_0c09ca68: /* original 80db, guest PC 0x0c09ca68 */
if(!s->budget--) { s->failed_pc=0x0c09ca68u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09ca6a;
P_0c09ca6a: /* original a003, guest PC 0x0c09ca6a */
if(!s->budget--) { s->failed_pc=0x0c09ca6au; return 0; }
r[3]=0x00000072u;
goto P_0c09ca74;
P_0c09ca6c: /* original e372, guest PC 0x0c09ca6c */
if(!s->budget--) { s->failed_pc=0x0c09ca6cu; return 0; }
r[3]=0x00000072u;
goto P_0c09ca6e;
P_0c09ca6e: /* original e009, guest PC 0x0c09ca6e */
if(!s->budget--) { s->failed_pc=0x0c09ca6eu; return 0; }
r[0]=0x00000009u;
goto P_0c09ca70;
P_0c09ca70: /* original e376, guest PC 0x0c09ca70 */
if(!s->budget--) { s->failed_pc=0x0c09ca70u; return 0; }
r[3]=0x00000076u;
goto P_0c09ca72;
P_0c09ca72: /* original 80db, guest PC 0x0c09ca72 */
if(!s->budget--) { s->failed_pc=0x0c09ca72u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09ca74;
P_0c09ca74: /* original e010, guest PC 0x0c09ca74 */
if(!s->budget--) { s->failed_pc=0x0c09ca74u; return 0; }
r[0]=0x00000010u;
goto P_0c09ca76;
P_0c09ca76: /* original 0d34, guest PC 0x0c09ca76 */
if(!s->budget--) { s->failed_pc=0x0c09ca76u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c09ca78;
P_0c09ca78: /* original 7f0c, guest PC 0x0c09ca78 */
if(!s->budget--) { s->failed_pc=0x0c09ca78u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09ca7a;
P_0c09ca7a: /* original 4f26, guest PC 0x0c09ca7a */
if(!s->budget--) { s->failed_pc=0x0c09ca7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ca7c;
P_0c09ca7c: /* original 68f6, guest PC 0x0c09ca7c */
if(!s->budget--) { s->failed_pc=0x0c09ca7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09ca7e;
P_0c09ca7e: /* original 69f6, guest PC 0x0c09ca7e */
if(!s->budget--) { s->failed_pc=0x0c09ca7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09ca80;
P_0c09ca80: /* original 6af6, guest PC 0x0c09ca80 */
if(!s->budget--) { s->failed_pc=0x0c09ca80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09ca82;
P_0c09ca82: /* original 6bf6, guest PC 0x0c09ca82 */
if(!s->budget--) { s->failed_pc=0x0c09ca82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ca84;
P_0c09ca84: /* original 6cf6, guest PC 0x0c09ca84 */
if(!s->budget--) { s->failed_pc=0x0c09ca84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ca86;
P_0c09ca86: /* original 6df6, guest PC 0x0c09ca86 */
if(!s->budget--) { s->failed_pc=0x0c09ca86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ca88;
P_0c09ca88: /* original 000b, guest PC 0x0c09ca88 */
if(!s->budget--) { s->failed_pc=0x0c09ca88u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09ca8a: /* original 6ef6, guest PC 0x0c09ca8a */
if(!s->budget--) { s->failed_pc=0x0c09ca8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09ca8cu,s,ram);
P_0c0abcb8: /* original 4f22, guest PC 0x0c0abcb8 */
if(!s->budget--) { s->failed_pc=0x0c0abcb8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abcba;
P_0c0abcba: /* original 05ed, guest PC 0x0c0abcba */
if(!s->budget--) { s->failed_pc=0x0c0abcbau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abcbc;
P_0c0abcbc: /* original 644d, guest PC 0x0c0abcbc */
if(!s->budget--) { s->failed_pc=0x0c0abcbcu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0abcbe;
P_0c0abcbe: /* original 655d, guest PC 0x0c0abcbe */
if(!s->budget--) { s->failed_pc=0x0c0abcbeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0abcc0;
P_0c0abcc0: /* original 3453, guest PC 0x0c0abcc0 */
if(!s->budget--) { s->failed_pc=0x0c0abcc0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0abcc2;
P_0c0abcc2: /* original 8903, guest PC 0x0c0abcc2 */
if(!s->budget--) { s->failed_pc=0x0c0abcc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abccc; }
goto P_0c0abcc4;
P_0c0abcc4: /* original e03e, guest PC 0x0c0abcc4 */
if(!s->budget--) { s->failed_pc=0x0c0abcc4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abcc6;
P_0c0abcc6: /* original 7401, guest PC 0x0c0abcc6 */
if(!s->budget--) { s->failed_pc=0x0c0abcc6u; return 0; }
r[4]+=0x00000001u;
goto P_0c0abcc8;
P_0c0abcc8: /* original a002, guest PC 0x0c0abcc8 */
if(!s->budget--) { s->failed_pc=0x0c0abcc8u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0abcd0;
P_0c0abcca: /* original 0e45, guest PC 0x0c0abcca */
if(!s->budget--) { s->failed_pc=0x0c0abccau; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0abccc;
P_0c0abccc: /* original e03e, guest PC 0x0c0abccc */
if(!s->budget--) { s->failed_pc=0x0c0abcccu; return 0; }
r[0]=0x0000003eu;
goto P_0c0abcce;
P_0c0abcce: /* original 0e55, guest PC 0x0c0abcce */
if(!s->budget--) { s->failed_pc=0x0c0abcceu; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0abcd0;
P_0c0abcd0: /* original b02c, guest PC 0x0c0abcd0 */
if(!s->budget--) { s->failed_pc=0x0c0abcd0u; return 0; }
target=0x0c0abd2cu; r[16]=0x0c0abcd4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abcd4u) { target=s->pc; goto dispatch; }
goto P_0c0abcd4;
P_0c0abcd2: /* original 64e3, guest PC 0x0c0abcd2 */
if(!s->budget--) { s->failed_pc=0x0c0abcd2u; return 0; }
r[4]=r[14];
goto P_0c0abcd4;
P_0c0abcd4: /* original 4f26, guest PC 0x0c0abcd4 */
if(!s->budget--) { s->failed_pc=0x0c0abcd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abcd6;
P_0c0abcd6: /* original 64e3, guest PC 0x0c0abcd6 */
if(!s->budget--) { s->failed_pc=0x0c0abcd6u; return 0; }
r[4]=r[14];
goto P_0c0abcd8;
P_0c0abcd8: /* original a074, guest PC 0x0c0abcd8 */
if(!s->budget--) { s->failed_pc=0x0c0abcd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abdc4;
P_0c0abcda: /* original 6ef6, guest PC 0x0c0abcda */
if(!s->budget--) { s->failed_pc=0x0c0abcdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0abcdcu,s,ram);
P_0c0abdc4: /* original 901b, guest PC 0x0c0abdc4 */
if(!s->budget--) { s->failed_pc=0x0c0abdc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abdfeu,2);
goto P_0c0abdc6;
P_0c0abdc6: /* original d510, guest PC 0x0c0abdc6 */
if(!s->budget--) { s->failed_pc=0x0c0abdc6u; return 0; }
r[5]=read(ram,0x0c0abe08u,4);
goto P_0c0abdc8;
P_0c0abdc8: /* original f546, guest PC 0x0c0abdc8 */
if(!s->budget--) { s->failed_pc=0x0c0abdc8u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0abdca;
P_0c0abdca: /* original 70fc, guest PC 0x0c0abdca */
if(!s->budget--) { s->failed_pc=0x0c0abdcau; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0abdcc;
P_0c0abdcc: /* original f446, guest PC 0x0c0abdcc */
if(!s->budget--) { s->failed_pc=0x0c0abdccu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0abdce;
P_0c0abdce: /* original e01c, guest PC 0x0c0abdce */
if(!s->budget--) { s->failed_pc=0x0c0abdceu; return 0; }
r[0]=0x0000001cu;
goto P_0c0abdd0;
P_0c0abdd0: /* original 005c, guest PC 0x0c0abdd0 */
if(!s->budget--) { s->failed_pc=0x0c0abdd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0abdd2;
P_0c0abdd2: /* original e50f, guest PC 0x0c0abdd2 */
if(!s->budget--) { s->failed_pc=0x0c0abdd2u; return 0; }
r[5]=0x0000000fu;
goto P_0c0abdd4;
P_0c0abdd4: /* original 600c, guest PC 0x0c0abdd4 */
if(!s->budget--) { s->failed_pc=0x0c0abdd4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0abdd6;
P_0c0abdd6: /* original 2509, guest PC 0x0c0abdd6 */
if(!s->budget--) { s->failed_pc=0x0c0abdd6u; return 0; }
r[5]&=r[0];
goto P_0c0abdd8;
P_0c0abdd8: /* original c70e, guest PC 0x0c0abdd8 */
if(!s->budget--) { s->failed_pc=0x0c0abdd8u; return 0; }
r[0]=0x0c0abe14u;
goto P_0c0abdda;
P_0c0abdda: /* original f608, guest PC 0x0c0abdda */
if(!s->budget--) { s->failed_pc=0x0c0abddau; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0abddc;
P_0c0abddc: /* original 6053, guest PC 0x0c0abddc */
if(!s->budget--) { s->failed_pc=0x0c0abddcu; return 0; }
r[0]=r[5];
goto P_0c0abdde;
P_0c0abdde: /* original 8807, guest PC 0x0c0abdde */
if(!s->budget--) { s->failed_pc=0x0c0abddeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0abde0;
P_0c0abde0: /* original 891e, guest PC 0x0c0abde0 */
if(!s->budget--) { s->failed_pc=0x0c0abde0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe20; }
goto P_0c0abde2;
P_0c0abde2: /* original 6053, guest PC 0x0c0abde2 */
if(!s->budget--) { s->failed_pc=0x0c0abde2u; return 0; }
r[0]=r[5];
goto P_0c0abde4;
P_0c0abde4: /* original 8805, guest PC 0x0c0abde4 */
if(!s->budget--) { s->failed_pc=0x0c0abde4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0abde6;
P_0c0abde6: /* original 8b31, guest PC 0x0c0abde6 */
if(!s->budget--) { s->failed_pc=0x0c0abde6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abe4c; }
goto P_0c0abde8;
P_0c0abde8: /* original c70b, guest PC 0x0c0abde8 */
if(!s->budget--) { s->failed_pc=0x0c0abde8u; return 0; }
r[0]=0x0c0abe18u;
goto P_0c0abdea;
P_0c0abdea: /* original f308, guest PC 0x0c0abdea */
if(!s->budget--) { s->failed_pc=0x0c0abdeau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abdec;
P_0c0abdec: /* original f435, guest PC 0x0c0abdec */
if(!s->budget--) { s->failed_pc=0x0c0abdecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0abdee;
P_0c0abdee: /* original 892d, guest PC 0x0c0abdee */
if(!s->budget--) { s->failed_pc=0x0c0abdeeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe4c; }
goto P_0c0abdf0;
P_0c0abdf0: /* original c70a, guest PC 0x0c0abdf0 */
if(!s->budget--) { s->failed_pc=0x0c0abdf0u; return 0; }
r[0]=0x0c0abe1cu;
goto P_0c0abdf2;
P_0c0abdf2: /* original f308, guest PC 0x0c0abdf2 */
if(!s->budget--) { s->failed_pc=0x0c0abdf2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abdf4;
P_0c0abdf4: /* original f345, guest PC 0x0c0abdf4 */
if(!s->budget--) { s->failed_pc=0x0c0abdf4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0abdf6;
P_0c0abdf6: /* original 8929, guest PC 0x0c0abdf6 */
if(!s->budget--) { s->failed_pc=0x0c0abdf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe4c; }
goto P_0c0abdf8;
P_0c0abdf8: /* original a026, guest PC 0x0c0abdf8 */
if(!s->budget--) { s->failed_pc=0x0c0abdf8u; return 0; }
goto P_0c0abe48;
P_0c0abdfa: /* original 0009, guest PC 0x0c0abdfa */
if(!s->budget--) { s->failed_pc=0x0c0abdfau; return 0; }
return vf3_matrix_family(0x0c0abdfcu,s,ram);
P_0c0abe20: /* original c740, guest PC 0x0c0abe20 */
if(!s->budget--) { s->failed_pc=0x0c0abe20u; return 0; }
r[0]=0x0c0abf24u;
goto P_0c0abe22;
P_0c0abe22: /* original f308, guest PC 0x0c0abe22 */
if(!s->budget--) { s->failed_pc=0x0c0abe22u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe24;
P_0c0abe24: /* original f355, guest PC 0x0c0abe24 */
if(!s->budget--) { s->failed_pc=0x0c0abe24u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0abe26;
P_0c0abe26: /* original 8911, guest PC 0x0c0abe26 */
if(!s->budget--) { s->failed_pc=0x0c0abe26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe4c; }
goto P_0c0abe28;
P_0c0abe28: /* original c73f, guest PC 0x0c0abe28 */
if(!s->budget--) { s->failed_pc=0x0c0abe28u; return 0; }
r[0]=0x0c0abf28u;
goto P_0c0abe2a;
P_0c0abe2a: /* original f308, guest PC 0x0c0abe2a */
if(!s->budget--) { s->failed_pc=0x0c0abe2au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe2c;
P_0c0abe2c: /* original f435, guest PC 0x0c0abe2c */
if(!s->budget--) { s->failed_pc=0x0c0abe2cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0abe2e;
P_0c0abe2e: /* original 8906, guest PC 0x0c0abe2e */
if(!s->budget--) { s->failed_pc=0x0c0abe2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe3e; }
goto P_0c0abe30;
P_0c0abe30: /* original c73e, guest PC 0x0c0abe30 */
if(!s->budget--) { s->failed_pc=0x0c0abe30u; return 0; }
r[0]=0x0c0abf2cu;
goto P_0c0abe32;
P_0c0abe32: /* original f308, guest PC 0x0c0abe32 */
if(!s->budget--) { s->failed_pc=0x0c0abe32u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe34;
P_0c0abe34: /* original f345, guest PC 0x0c0abe34 */
if(!s->budget--) { s->failed_pc=0x0c0abe34u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0abe36;
P_0c0abe36: /* original 8907, guest PC 0x0c0abe36 */
if(!s->budget--) { s->failed_pc=0x0c0abe36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe48; }
goto P_0c0abe38;
P_0c0abe38: /* original f38d, guest PC 0x0c0abe38 */
if(!s->budget--) { s->failed_pc=0x0c0abe38u; return 0; }
fr[3]=0;
goto P_0c0abe3a;
P_0c0abe3a: /* original f435, guest PC 0x0c0abe3a */
if(!s->budget--) { s->failed_pc=0x0c0abe3au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0abe3c;
P_0c0abe3c: /* original 8904, guest PC 0x0c0abe3c */
if(!s->budget--) { s->failed_pc=0x0c0abe3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe48; }
goto P_0c0abe3e;
P_0c0abe3e: /* original c73c, guest PC 0x0c0abe3e */
if(!s->budget--) { s->failed_pc=0x0c0abe3eu; return 0; }
r[0]=0x0c0abf30u;
goto P_0c0abe40;
P_0c0abe40: /* original f308, guest PC 0x0c0abe40 */
if(!s->budget--) { s->failed_pc=0x0c0abe40u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe42;
P_0c0abe42: /* original e024, guest PC 0x0c0abe42 */
if(!s->budget--) { s->failed_pc=0x0c0abe42u; return 0; }
r[0]=0x00000024u;
goto P_0c0abe44;
P_0c0abe44: /* original 000b, guest PC 0x0c0abe44 */
if(!s->budget--) { s->failed_pc=0x0c0abe44u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,3,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0abe46: /* original f437, guest PC 0x0c0abe46 */
if(!s->budget--) { s->failed_pc=0x0c0abe46u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0abe48;
P_0c0abe48: /* original e024, guest PC 0x0c0abe48 */
if(!s->budget--) { s->failed_pc=0x0c0abe48u; return 0; }
r[0]=0x00000024u;
goto P_0c0abe4a;
P_0c0abe4a: /* original f467, guest PC 0x0c0abe4a */
if(!s->budget--) { s->failed_pc=0x0c0abe4au; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0abe4c;
P_0c0abe4c: /* original 000b, guest PC 0x0c0abe4c */
if(!s->budget--) { s->failed_pc=0x0c0abe4cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0abe4e: /* original 0009, guest PC 0x0c0abe4e */
if(!s->budget--) { s->failed_pc=0x0c0abe4eu; return 0; }
return vf3_matrix_family(0x0c0abe50u,s,ram);
P_0c0c2f4e: /* original 4f22, guest PC 0x0c0c2f4e */
if(!s->budget--) { s->failed_pc=0x0c0c2f4eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2f50;
P_0c0c2f50: /* original dc39, guest PC 0x0c0c2f50 */
if(!s->budget--) { s->failed_pc=0x0c0c2f50u; return 0; }
r[12]=read(ram,0x0c0c3038u,4);
goto P_0c0c2f52;
P_0c0c2f52: /* original 7ff8, guest PC 0x0c0c2f52 */
if(!s->budget--) { s->failed_pc=0x0c0c2f52u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c2f54;
P_0c0c2f54: /* original 1f41, guest PC 0x0c0c2f54 */
if(!s->budget--) { s->failed_pc=0x0c0c2f54u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c2f56;
P_0c0c2f56: /* original da3a, guest PC 0x0c0c2f56 */
if(!s->budget--) { s->failed_pc=0x0c0c2f56u; return 0; }
r[10]=read(ram,0x0c0c3040u,4);
goto P_0c0c2f58;
P_0c0c2f58: /* original 9368, guest PC 0x0c0c2f58 */
if(!s->budget--) { s->failed_pc=0x0c0c2f58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c302cu,2);
goto P_0c0c2f5a;
P_0c0c2f5a: /* original 62a2, guest PC 0x0c0c2f5a */
if(!s->budget--) { s->failed_pc=0x0c0c2f5au; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0c2f5c;
P_0c0c2f5c: /* original d839, guest PC 0x0c0c2f5c */
if(!s->budget--) { s->failed_pc=0x0c0c2f5cu; return 0; }
r[8]=read(ram,0x0c0c3044u,4);
goto P_0c0c2f5e;
P_0c0c2f5e: /* original d937, guest PC 0x0c0c2f5e */
if(!s->budget--) { s->failed_pc=0x0c0c2f5eu; return 0; }
r[9]=read(ram,0x0c0c303cu,4);
goto P_0c0c2f60;
P_0c0c2f60: /* original 2238, guest PC 0x0c0c2f60 */
if(!s->budget--) { s->failed_pc=0x0c0c2f60u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c2f62;
P_0c0c2f62: /* original 8d02, guest PC 0x0c0c2f62 */
if(!s->budget--) { s->failed_pc=0x0c0c2f62u; return 0; }
cond=r[17]&1u;
r[13]=r[4];
if(cond) { goto P_0c0c2f6a; }
goto P_0c0c2f66;
P_0c0c2f64: /* original 6d43, guest PC 0x0c0c2f64 */
if(!s->budget--) { s->failed_pc=0x0c0c2f64u; return 0; }
r[13]=r[4];
goto P_0c0c2f66;
P_0c0c2f66: /* original a13c, guest PC 0x0c0c2f66 */
if(!s->budget--) { s->failed_pc=0x0c0c2f66u; return 0; }
goto P_0c0c31e2;
P_0c0c2f68: /* original 0009, guest PC 0x0c0c2f68 */
if(!s->budget--) { s->failed_pc=0x0c0c2f68u; return 0; }
goto P_0c0c2f6a;
P_0c0c2f6a: /* original b4ef, guest PC 0x0c0c2f6a */
if(!s->budget--) { s->failed_pc=0x0c0c2f6au; return 0; }
target=0x0c0c394cu; r[16]=0x0c0c2f6eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2f6eu) { target=s->pc; goto dispatch; }
goto P_0c0c2f6e;
P_0c0c2f6c: /* original 0009, guest PC 0x0c0c2f6c */
if(!s->budget--) { s->failed_pc=0x0c0c2f6cu; return 0; }
goto P_0c0c2f6e;
P_0c0c2f6e: /* original 905e, guest PC 0x0c0c2f6e */
if(!s->budget--) { s->failed_pc=0x0c0c2f6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c302eu,2);
goto P_0c0c2f70;
P_0c0c2f70: /* original 01ac, guest PC 0x0c0c2f70 */
if(!s->budget--) { s->failed_pc=0x0c0c2f70u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0c2f72;
P_0c0c2f72: /* original 2118, guest PC 0x0c0c2f72 */
if(!s->budget--) { s->failed_pc=0x0c0c2f72u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c2f74;
P_0c0c2f74: /* original 8910, guest PC 0x0c0c2f74 */
if(!s->budget--) { s->failed_pc=0x0c0c2f74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2f98; }
goto P_0c0c2f76;
P_0c0c2f76: /* original 55c4, guest PC 0x0c0c2f76 */
if(!s->budget--) { s->failed_pc=0x0c0c2f76u; return 0; }
r[5]=read(ram,r[12]+16,4);
goto P_0c0c2f78;
P_0c0c2f78: /* original e060, guest PC 0x0c0c2f78 */
if(!s->budget--) { s->failed_pc=0x0c0c2f78u; return 0; }
r[0]=0x00000060u;
goto P_0c0c2f7a;
P_0c0c2f7a: /* original 035c, guest PC 0x0c0c2f7a */
if(!s->budget--) { s->failed_pc=0x0c0c2f7au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c2f7c;
P_0c0c2f7c: /* original 633c, guest PC 0x0c0c2f7c */
if(!s->budget--) { s->failed_pc=0x0c0c2f7cu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c2f7e;
P_0c0c2f7e: /* original 33b3, guest PC 0x0c0c2f7e */
if(!s->budget--) { s->failed_pc=0x0c0c2f7eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[11])!=0);
goto P_0c0c2f80;
P_0c0c2f80: /* original 8f03, guest PC 0x0c0c2f80 */
if(!s->budget--) { s->failed_pc=0x0c0c2f80u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[12]+20,4);
if(!cond) { goto P_0c0c2f8a; }
goto P_0c0c2f84;
P_0c0c2f82: /* original 54c5, guest PC 0x0c0c2f82 */
if(!s->budget--) { s->failed_pc=0x0c0c2f82u; return 0; }
r[4]=read(ram,r[12]+20,4);
goto P_0c0c2f84;
P_0c0c2f84: /* original 025c, guest PC 0x0c0c2f84 */
if(!s->budget--) { s->failed_pc=0x0c0c2f84u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c2f86;
P_0c0c2f86: /* original 72f3, guest PC 0x0c0c2f86 */
if(!s->budget--) { s->failed_pc=0x0c0c2f86u; return 0; }
r[2]+=0xfffffff3u;
goto P_0c0c2f88;
P_0c0c2f88: /* original 0524, guest PC 0x0c0c2f88 */
if(!s->budget--) { s->failed_pc=0x0c0c2f88u; return 0; }
write(ram,r[5]+r[0],r[2],1);
goto P_0c0c2f8a;
P_0c0c2f8a: /* original 034c, guest PC 0x0c0c2f8a */
if(!s->budget--) { s->failed_pc=0x0c0c2f8au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c2f8c;
P_0c0c2f8c: /* original 633c, guest PC 0x0c0c2f8c */
if(!s->budget--) { s->failed_pc=0x0c0c2f8cu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c2f8e;
P_0c0c2f8e: /* original 33b7, guest PC 0x0c0c2f8e */
if(!s->budget--) { s->failed_pc=0x0c0c2f8eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[11])!=0);
goto P_0c0c2f90;
P_0c0c2f90: /* original 8902, guest PC 0x0c0c2f90 */
if(!s->budget--) { s->failed_pc=0x0c0c2f90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2f98; }
goto P_0c0c2f92;
P_0c0c2f92: /* original 024c, guest PC 0x0c0c2f92 */
if(!s->budget--) { s->failed_pc=0x0c0c2f92u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c2f94;
P_0c0c2f94: /* original 720d, guest PC 0x0c0c2f94 */
if(!s->budget--) { s->failed_pc=0x0c0c2f94u; return 0; }
r[2]+=0x0000000du;
goto P_0c0c2f96;
P_0c0c2f96: /* original 0424, guest PC 0x0c0c2f96 */
if(!s->budget--) { s->failed_pc=0x0c0c2f96u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0c2f98;
P_0c0c2f98: /* original e607, guest PC 0x0c0c2f98 */
if(!s->budget--) { s->failed_pc=0x0c0c2f98u; return 0; }
r[6]=0x00000007u;
goto P_0c0c2f9a;
P_0c0c2f9a: /* original 18e1, guest PC 0x0c0c2f9a */
if(!s->budget--) { s->failed_pc=0x0c0c2f9au; return 0; }
write(ram,r[8]+4,r[14],4);
goto P_0c0c2f9c;
P_0c0c2f9c: /* original 18e2, guest PC 0x0c0c2f9c */
if(!s->budget--) { s->failed_pc=0x0c0c2f9cu; return 0; }
write(ram,r[8]+8,r[14],4);
goto P_0c0c2f9e;
P_0c0c2f9e: /* original 54ca, guest PC 0x0c0c2f9e */
if(!s->budget--) { s->failed_pc=0x0c0c2f9eu; return 0; }
r[4]=read(ram,r[12]+40,4);
goto P_0c0c2fa0;
P_0c0c2fa0: /* original 6742, guest PC 0x0c0c2fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c2fa0u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c0c2fa2;
P_0c0c2fa2: /* original 2768, guest PC 0x0c0c2fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c2fa2u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[6])==0)!=0);
goto P_0c0c2fa4;
P_0c0c2fa4: /* original 8d01, guest PC 0x0c0c2fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c2fa4u; return 0; }
cond=r[17]&1u;
r[5]=r[14];
if(cond) { goto P_0c0c2faa; }
goto P_0c0c2fa8;
P_0c0c2fa6: /* original 65e3, guest PC 0x0c0c2fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c2fa6u; return 0; }
r[5]=r[14];
goto P_0c0c2fa8;
P_0c0c2fa8: /* original e501, guest PC 0x0c0c2fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c2fa8u; return 0; }
r[5]=0x00000001u;
goto P_0c0c2faa;
P_0c0c2faa: /* original e06c, guest PC 0x0c0c2faa */
if(!s->budget--) { s->failed_pc=0x0c0c2faau; return 0; }
r[0]=0x0000006cu;
goto P_0c0c2fac;
P_0c0c2fac: /* original 04e6, guest PC 0x0c0c2fac */
if(!s->budget--) { s->failed_pc=0x0c0c2facu; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0c2fae;
P_0c0c2fae: /* original 54cb, guest PC 0x0c0c2fae */
if(!s->budget--) { s->failed_pc=0x0c0c2faeu; return 0; }
r[4]=read(ram,r[12]+44,4);
goto P_0c0c2fb0;
P_0c0c2fb0: /* original 6742, guest PC 0x0c0c2fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c2fb0u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c0c2fb2;
P_0c0c2fb2: /* original 2768, guest PC 0x0c0c2fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c2fb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[6])==0)!=0);
goto P_0c0c2fb4;
P_0c0c2fb4: /* original 8d02, guest PC 0x0c0c2fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c2fb4u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[14],4);
if(cond) { goto P_0c0c2fbc; }
goto P_0c0c2fb8;
P_0c0c2fb6: /* original 04e6, guest PC 0x0c0c2fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c2fb6u; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0c2fb8;
P_0c0c2fb8: /* original e202, guest PC 0x0c0c2fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c2fb8u; return 0; }
r[2]=0x00000002u;
goto P_0c0c2fba;
P_0c0c2fba: /* original 252b, guest PC 0x0c0c2fba */
if(!s->budget--) { s->failed_pc=0x0c0c2fbau; return 0; }
r[5]|=r[2];
goto P_0c0c2fbc;
P_0c0c2fbc: /* original 707c, guest PC 0x0c0c2fbc */
if(!s->budget--) { s->failed_pc=0x0c0c2fbcu; return 0; }
r[0]+=0x0000007cu;
goto P_0c0c2fbe;
P_0c0c2fbe: /* original 0a54, guest PC 0x0c0c2fbe */
if(!s->budget--) { s->failed_pc=0x0c0c2fbeu; return 0; }
write(ram,r[10]+r[0],r[5],1);
goto P_0c0c2fc0;
P_0c0c2fc0: /* original 70b0, guest PC 0x0c0c2fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c2fc0u; return 0; }
r[0]+=0xffffffb0u;
goto P_0c0c2fc2;
P_0c0c2fc2: /* original 04ae, guest PC 0x0c0c2fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c2fc2u; return 0; }
r[4]=read(ram,r[10]+r[0],4);
goto P_0c0c2fc4;
P_0c0c2fc4: /* original 6053, guest PC 0x0c0c2fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c2fc4u; return 0; }
r[0]=r[5];
goto P_0c0c2fc6;
P_0c0c2fc6: /* original 8803, guest PC 0x0c0c2fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c2fc6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c2fc8;
P_0c0c2fc8: /* original 8901, guest PC 0x0c0c2fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c2fc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2fce; }
goto P_0c0c2fca;
P_0c0c2fca: /* original a04d, guest PC 0x0c0c2fca */
if(!s->budget--) { s->failed_pc=0x0c0c2fcau; return 0; }
r[4]=r[14];
goto P_0c0c3068;
P_0c0c2fcc: /* original 64e3, guest PC 0x0c0c2fcc */
if(!s->budget--) { s->failed_pc=0x0c0c2fccu; return 0; }
r[4]=r[14];
goto P_0c0c2fce;
P_0c0c2fce: /* original 5092, guest PC 0x0c0c2fce */
if(!s->budget--) { s->failed_pc=0x0c0c2fceu; return 0; }
r[0]=read(ram,r[9]+8,4);
goto P_0c0c2fd0;
P_0c0c2fd0: /* original c804, guest PC 0x0c0c2fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c2fd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0c2fd2;
P_0c0c2fd2: /* original 891f, guest PC 0x0c0c2fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c2fd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3014; }
goto P_0c0c2fd4;
P_0c0c2fd4: /* original 902c, guest PC 0x0c0c2fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c2fd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3030u,2);
goto P_0c0c2fd6;
P_0c0c2fd6: /* original 009c, guest PC 0x0c0c2fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c2fd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0c2fd8;
P_0c0c2fd8: /* original 8801, guest PC 0x0c0c2fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c2fd8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c2fda;
P_0c0c2fda: /* original 8b02, guest PC 0x0c0c2fda */
if(!s->budget--) { s->failed_pc=0x0c0c2fdau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2fe2; }
goto P_0c0c2fdc;
P_0c0c2fdc: /* original 9529, guest PC 0x0c0c2fdc */
if(!s->budget--) { s->failed_pc=0x0c0c2fdcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3032u,2);
goto P_0c0c2fde;
P_0c0c2fde: /* original a001, guest PC 0x0c0c2fde */
if(!s->budget--) { s->failed_pc=0x0c0c2fdeu; return 0; }
goto P_0c0c2fe4;
P_0c0c2fe0: /* original 0009, guest PC 0x0c0c2fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c2fe0u; return 0; }
goto P_0c0c2fe2;
P_0c0c2fe2: /* original 9527, guest PC 0x0c0c2fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c2fe2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3034u,2);
goto P_0c0c2fe4;
P_0c0c2fe4: /* original 9027, guest PC 0x0c0c2fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c2fe4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3036u,2);
goto P_0c0c2fe6;
P_0c0c2fe6: /* original 359c, guest PC 0x0c0c2fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c2fe6u; return 0; }
r[5]+=r[9];
goto P_0c0c2fe8;
P_0c0c2fe8: /* original 68e3, guest PC 0x0c0c2fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c2fe8u; return 0; }
r[8]=r[14];
goto P_0c0c2fea;
P_0c0c2fea: /* original 079c, guest PC 0x0c0c2fea */
if(!s->budget--) { s->failed_pc=0x0c0c2feau; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0c2fec;
P_0c0c2fec: /* original 77ff, guest PC 0x0c0c2fec */
if(!s->budget--) { s->failed_pc=0x0c0c2fecu; return 0; }
r[7]+=0xffffffffu;
goto P_0c0c2fee;
P_0c0c2fee: /* original 6673, guest PC 0x0c0c2fee */
if(!s->budget--) { s->failed_pc=0x0c0c2feeu; return 0; }
r[6]=r[7];
goto P_0c0c2ff0;
P_0c0c2ff0: /* original 4711, guest PC 0x0c0c2ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ff0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c0c2ff2;
P_0c0c2ff2: /* original 8f0d, guest PC 0x0c0c2ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ff2u; return 0; }
cond=r[17]&1u;
r[6]+=r[5];
if(!cond) { goto P_0c0c3010; }
goto P_0c0c2ff6;
P_0c0c2ff4: /* original 365c, guest PC 0x0c0c2ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ff4u; return 0; }
r[6]+=r[5];
goto P_0c0c2ff6;
P_0c0c2ff6: /* original 6560, guest PC 0x0c0c2ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ff6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[5]=tmp;
goto P_0c0c2ff8;
P_0c0c2ff8: /* original 655c, guest PC 0x0c0c2ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ff8u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c2ffa;
P_0c0c2ffa: /* original 35b2, guest PC 0x0c0c2ffa */
if(!s->budget--) { s->failed_pc=0x0c0c2ffau; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[11])!=0);
goto P_0c0c2ffc;
P_0c0c2ffc: /* original 8b00, guest PC 0x0c0c2ffc */
if(!s->budget--) { s->failed_pc=0x0c0c2ffcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3000; }
goto P_0c0c2ffe;
P_0c0c2ffe: /* original 75f3, guest PC 0x0c0c2ffe */
if(!s->budget--) { s->failed_pc=0x0c0c2ffeu; return 0; }
r[5]+=0xfffffff3u;
goto P_0c0c3000;
P_0c0c3000: /* original 635b, guest PC 0x0c0c3000 */
if(!s->budget--) { s->failed_pc=0x0c0c3000u; return 0; }
r[3]=0u-r[5];
goto P_0c0c3002;
P_0c0c3002: /* original d511, guest PC 0x0c0c3002 */
if(!s->budget--) { s->failed_pc=0x0c0c3002u; return 0; }
r[5]=read(ram,0x0c0c3048u,4);
goto P_0c0c3004;
P_0c0c3004: /* original 77ff, guest PC 0x0c0c3004 */
if(!s->budget--) { s->failed_pc=0x0c0c3004u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0c3006;
P_0c0c3006: /* original 453d, guest PC 0x0c0c3006 */
if(!s->budget--) { s->failed_pc=0x0c0c3006u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0c3008;
P_0c0c3008: /* original 4711, guest PC 0x0c0c3008 */
if(!s->budget--) { s->failed_pc=0x0c0c3008u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c0c300a;
P_0c0c300a: /* original 285b, guest PC 0x0c0c300a */
if(!s->budget--) { s->failed_pc=0x0c0c300au; return 0; }
r[8]|=r[5];
goto P_0c0c300c;
P_0c0c300c: /* original 8df3, guest PC 0x0c0c300c */
if(!s->budget--) { s->failed_pc=0x0c0c300cu; return 0; }
cond=r[17]&1u;
r[6]+=0xffffffffu;
if(cond) { goto P_0c0c2ff6; }
goto P_0c0c3010;
P_0c0c300e: /* original 76ff, guest PC 0x0c0c300e */
if(!s->budget--) { s->failed_pc=0x0c0c300eu; return 0; }
r[6]+=0xffffffffu;
goto P_0c0c3010;
P_0c0c3010: /* original a02a, guest PC 0x0c0c3010 */
if(!s->budget--) { s->failed_pc=0x0c0c3010u; return 0; }
r[4]&=r[8];
goto P_0c0c3068;
P_0c0c3012: /* original 2489, guest PC 0x0c0c3012 */
if(!s->budget--) { s->failed_pc=0x0c0c3012u; return 0; }
r[4]&=r[8];
goto P_0c0c3014;
P_0c0c3014: /* original 900c, guest PC 0x0c0c3014 */
if(!s->budget--) { s->failed_pc=0x0c0c3014u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3030u,2);
goto P_0c0c3016;
P_0c0c3016: /* original 009c, guest PC 0x0c0c3016 */
if(!s->budget--) { s->failed_pc=0x0c0c3016u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0c3018;
P_0c0c3018: /* original 8801, guest PC 0x0c0c3018 */
if(!s->budget--) { s->failed_pc=0x0c0c3018u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c301a;
P_0c0c301a: /* original 8b17, guest PC 0x0c0c301a */
if(!s->budget--) { s->failed_pc=0x0c0c301au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c304c; }
goto P_0c0c301c;
P_0c0c301c: /* original 55c4, guest PC 0x0c0c301c */
if(!s->budget--) { s->failed_pc=0x0c0c301cu; return 0; }
r[5]=read(ram,r[12]+16,4);
goto P_0c0c301e;
P_0c0c301e: /* original e060, guest PC 0x0c0c301e */
if(!s->budget--) { s->failed_pc=0x0c0c301eu; return 0; }
r[0]=0x00000060u;
goto P_0c0c3020;
P_0c0c3020: /* original 025c, guest PC 0x0c0c3020 */
if(!s->budget--) { s->failed_pc=0x0c0c3020u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c3022;
P_0c0c3022: /* original 622c, guest PC 0x0c0c3022 */
if(!s->budget--) { s->failed_pc=0x0c0c3022u; return 0; }
r[2]=r[2]&255u;
goto P_0c0c3024;
P_0c0c3024: /* original 32b3, guest PC 0x0c0c3024 */
if(!s->budget--) { s->failed_pc=0x0c0c3024u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[11])!=0);
goto P_0c0c3026;
P_0c0c3026: /* original 8b17, guest PC 0x0c0c3026 */
if(!s->budget--) { s->failed_pc=0x0c0c3026u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3058; }
goto P_0c0c3028;
P_0c0c3028: /* original a017, guest PC 0x0c0c3028 */
if(!s->budget--) { s->failed_pc=0x0c0c3028u; return 0; }
goto P_0c0c305a;
P_0c0c302a: /* original 0009, guest PC 0x0c0c302a */
if(!s->budget--) { s->failed_pc=0x0c0c302au; return 0; }
return vf3_matrix_family(0x0c0c302cu,s,ram);
P_0c0c304c: /* original 55c5, guest PC 0x0c0c304c */
if(!s->budget--) { s->failed_pc=0x0c0c304cu; return 0; }
r[5]=read(ram,r[12]+20,4);
goto P_0c0c304e;
P_0c0c304e: /* original e060, guest PC 0x0c0c304e */
if(!s->budget--) { s->failed_pc=0x0c0c304eu; return 0; }
r[0]=0x00000060u;
goto P_0c0c3050;
P_0c0c3050: /* original 025c, guest PC 0x0c0c3050 */
if(!s->budget--) { s->failed_pc=0x0c0c3050u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c3052;
P_0c0c3052: /* original 622c, guest PC 0x0c0c3052 */
if(!s->budget--) { s->failed_pc=0x0c0c3052u; return 0; }
r[2]=r[2]&255u;
goto P_0c0c3054;
P_0c0c3054: /* original 32b3, guest PC 0x0c0c3054 */
if(!s->budget--) { s->failed_pc=0x0c0c3054u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[11])!=0);
goto P_0c0c3056;
P_0c0c3056: /* original 8b00, guest PC 0x0c0c3056 */
if(!s->budget--) { s->failed_pc=0x0c0c3056u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c305a; }
goto P_0c0c3058;
P_0c0c3058: /* original 64e3, guest PC 0x0c0c3058 */
if(!s->budget--) { s->failed_pc=0x0c0c3058u; return 0; }
r[4]=r[14];
goto P_0c0c305a;
P_0c0c305a: /* original e061, guest PC 0x0c0c305a */
if(!s->budget--) { s->failed_pc=0x0c0c305au; return 0; }
r[0]=0x00000061u;
goto P_0c0c305c;
P_0c0c305c: /* original 055c, guest PC 0x0c0c305c */
if(!s->budget--) { s->failed_pc=0x0c0c305cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c305e;
P_0c0c305e: /* original 655c, guest PC 0x0c0c305e */
if(!s->budget--) { s->failed_pc=0x0c0c305eu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c3060;
P_0c0c3060: /* original 635b, guest PC 0x0c0c3060 */
if(!s->budget--) { s->failed_pc=0x0c0c3060u; return 0; }
r[3]=0u-r[5];
goto P_0c0c3062;
P_0c0c3062: /* original d520, guest PC 0x0c0c3062 */
if(!s->budget--) { s->failed_pc=0x0c0c3062u; return 0; }
r[5]=read(ram,0x0c0c30e4u,4);
goto P_0c0c3064;
P_0c0c3064: /* original 453d, guest PC 0x0c0c3064 */
if(!s->budget--) { s->failed_pc=0x0c0c3064u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0c3066;
P_0c0c3066: /* original 2459, guest PC 0x0c0c3066 */
if(!s->budget--) { s->failed_pc=0x0c0c3066u; return 0; }
r[4]&=r[5];
goto P_0c0c3068;
P_0c0c3068: /* original 9038, guest PC 0x0c0c3068 */
if(!s->budget--) { s->failed_pc=0x0c0c3068u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c30dcu,2);
goto P_0c0c306a;
P_0c0c306a: /* original e314, guest PC 0x0c0c306a */
if(!s->budget--) { s->failed_pc=0x0c0c306au; return 0; }
r[3]=0x00000014u;
goto P_0c0c306c;
P_0c0c306c: /* original 0a46, guest PC 0x0c0c306c */
if(!s->budget--) { s->failed_pc=0x0c0c306cu; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c306e;
P_0c0c306e: /* original 9036, guest PC 0x0c0c306e */
if(!s->budget--) { s->failed_pc=0x0c0c306eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c30deu,2);
goto P_0c0c3070;
P_0c0c3070: /* original 54c8, guest PC 0x0c0c3070 */
if(!s->budget--) { s->failed_pc=0x0c0c3070u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c0c3072;
P_0c0c3072: /* original 0434, guest PC 0x0c0c3072 */
if(!s->budget--) { s->failed_pc=0x0c0c3072u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c3074;
P_0c0c3074: /* original f48d, guest PC 0x0c0c3074 */
if(!s->budget--) { s->failed_pc=0x0c0c3074u; return 0; }
fr[4]=0;
goto P_0c0c3076;
P_0c0c3076: /* original f43d, guest PC 0x0c0c3076 */
if(!s->budget--) { s->failed_pc=0x0c0c3076u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c3078;
P_0c0c3078: /* original 9032, guest PC 0x0c0c3078 */
if(!s->budget--) { s->failed_pc=0x0c0c3078u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c30e0u,2);
goto P_0c0c307a;
P_0c0c307a: /* original f447, guest PC 0x0c0c307a */
if(!s->budget--) { s->failed_pc=0x0c0c307au; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0c307c;
P_0c0c307c: /* original 70f0, guest PC 0x0c0c307c */
if(!s->budget--) { s->failed_pc=0x0c0c307cu; return 0; }
r[0]+=0xfffffff0u;
goto P_0c0c307e;
P_0c0c307e: /* original f447, guest PC 0x0c0c307e */
if(!s->budget--) { s->failed_pc=0x0c0c307eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0c3080;
P_0c0c3080: /* original 7016, guest PC 0x0c0c3080 */
if(!s->budget--) { s->failed_pc=0x0c0c3080u; return 0; }
r[0]+=0x00000016u;
goto P_0c0c3082;
P_0c0c3082: /* original 035a, guest PC 0x0c0c3082 */
if(!s->budget--) { s->failed_pc=0x0c0c3082u; return 0; }
r[3]=r[53];
goto P_0c0c3084;
P_0c0c3084: /* original f43d, guest PC 0x0c0c3084 */
if(!s->budget--) { s->failed_pc=0x0c0c3084u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c3086;
P_0c0c3086: /* original 0434, guest PC 0x0c0c3086 */
if(!s->budget--) { s->failed_pc=0x0c0c3086u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c3088;
P_0c0c3088: /* original 70ff, guest PC 0x0c0c3088 */
if(!s->budget--) { s->failed_pc=0x0c0c3088u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c308a;
P_0c0c308a: /* original 0434, guest PC 0x0c0c308a */
if(!s->budget--) { s->failed_pc=0x0c0c308au; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c308c;
P_0c0c308c: /* original 70ff, guest PC 0x0c0c308c */
if(!s->budget--) { s->failed_pc=0x0c0c308cu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c308e;
P_0c0c308e: /* original 0434, guest PC 0x0c0c308e */
if(!s->budget--) { s->failed_pc=0x0c0c308eu; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c3090;
P_0c0c3090: /* original 9027, guest PC 0x0c0c3090 */
if(!s->budget--) { s->failed_pc=0x0c0c3090u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c30e2u,2);
goto P_0c0c3092;
P_0c0c3092: /* original f447, guest PC 0x0c0c3092 */
if(!s->budget--) { s->failed_pc=0x0c0c3092u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0c3094;
P_0c0c3094: /* original 70f8, guest PC 0x0c0c3094 */
if(!s->budget--) { s->failed_pc=0x0c0c3094u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c3096;
P_0c0c3096: /* original f447, guest PC 0x0c0c3096 */
if(!s->budget--) { s->failed_pc=0x0c0c3096u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0c3098;
P_0c0c3098: /* original 70fb, guest PC 0x0c0c3098 */
if(!s->budget--) { s->failed_pc=0x0c0c3098u; return 0; }
r[0]+=0xfffffffbu;
goto P_0c0c309a;
P_0c0c309a: /* original 035a, guest PC 0x0c0c309a */
if(!s->budget--) { s->failed_pc=0x0c0c309au; return 0; }
r[3]=r[53];
goto P_0c0c309c;
P_0c0c309c: /* original 0434, guest PC 0x0c0c309c */
if(!s->budget--) { s->failed_pc=0x0c0c309cu; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c309e;
P_0c0c309e: /* original 70ff, guest PC 0x0c0c309e */
if(!s->budget--) { s->failed_pc=0x0c0c309eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c30a0;
P_0c0c30a0: /* original 0434, guest PC 0x0c0c30a0 */
if(!s->budget--) { s->failed_pc=0x0c0c30a0u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c30a2;
P_0c0c30a2: /* original 70ff, guest PC 0x0c0c30a2 */
if(!s->budget--) { s->failed_pc=0x0c0c30a2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c30a4;
P_0c0c30a4: /* original 0434, guest PC 0x0c0c30a4 */
if(!s->budget--) { s->failed_pc=0x0c0c30a4u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c30a6;
P_0c0c30a6: /* original 54ca, guest PC 0x0c0c30a6 */
if(!s->budget--) { s->failed_pc=0x0c0c30a6u; return 0; }
r[4]=read(ram,r[12]+40,4);
goto P_0c0c30a8;
P_0c0c30a8: /* original e036, guest PC 0x0c0c30a8 */
if(!s->budget--) { s->failed_pc=0x0c0c30a8u; return 0; }
r[0]=0x00000036u;
goto P_0c0c30aa;
P_0c0c30aa: /* original e301, guest PC 0x0c0c30aa */
if(!s->budget--) { s->failed_pc=0x0c0c30aau; return 0; }
r[3]=0x00000001u;
goto P_0c0c30ac;
P_0c0c30ac: /* original 0434, guest PC 0x0c0c30ac */
if(!s->budget--) { s->failed_pc=0x0c0c30acu; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c30ae;
P_0c0c30ae: /* original e5ff, guest PC 0x0c0c30ae */
if(!s->budget--) { s->failed_pc=0x0c0c30aeu; return 0; }
r[5]=0xffffffffu;
goto P_0c0c30b0;
P_0c0c30b0: /* original e040, guest PC 0x0c0c30b0 */
if(!s->budget--) { s->failed_pc=0x0c0c30b0u; return 0; }
r[0]=0x00000040u;
goto P_0c0c30b2;
P_0c0c30b2: /* original e202, guest PC 0x0c0c30b2 */
if(!s->budget--) { s->failed_pc=0x0c0c30b2u; return 0; }
r[2]=0x00000002u;
goto P_0c0c30b4;
P_0c0c30b4: /* original 142f, guest PC 0x0c0c30b4 */
if(!s->budget--) { s->failed_pc=0x0c0c30b4u; return 0; }
write(ram,r[4]+60,r[2],4);
goto P_0c0c30b6;
P_0c0c30b6: /* original e205, guest PC 0x0c0c30b6 */
if(!s->budget--) { s->failed_pc=0x0c0c30b6u; return 0; }
r[2]=0x00000005u;
goto P_0c0c30b8;
P_0c0c30b8: /* original 0456, guest PC 0x0c0c30b8 */
if(!s->budget--) { s->failed_pc=0x0c0c30b8u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c30ba;
P_0c0c30ba: /* original e036, guest PC 0x0c0c30ba */
if(!s->budget--) { s->failed_pc=0x0c0c30bau; return 0; }
r[0]=0x00000036u;
goto P_0c0c30bc;
P_0c0c30bc: /* original 54cb, guest PC 0x0c0c30bc */
if(!s->budget--) { s->failed_pc=0x0c0c30bcu; return 0; }
r[4]=read(ram,r[12]+44,4);
goto P_0c0c30be;
P_0c0c30be: /* original 0434, guest PC 0x0c0c30be */
if(!s->budget--) { s->failed_pc=0x0c0c30beu; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c30c0;
P_0c0c30c0: /* original e040, guest PC 0x0c0c30c0 */
if(!s->budget--) { s->failed_pc=0x0c0c30c0u; return 0; }
r[0]=0x00000040u;
goto P_0c0c30c2;
P_0c0c30c2: /* original 142f, guest PC 0x0c0c30c2 */
if(!s->budget--) { s->failed_pc=0x0c0c30c2u; return 0; }
write(ram,r[4]+60,r[2],4);
goto P_0c0c30c4;
P_0c0c30c4: /* original 0456, guest PC 0x0c0c30c4 */
if(!s->budget--) { s->failed_pc=0x0c0c30c4u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c30c6;
P_0c0c30c6: /* original e03a, guest PC 0x0c0c30c6 */
if(!s->budget--) { s->failed_pc=0x0c0c30c6u; return 0; }
r[0]=0x0000003au;
goto P_0c0c30c8;
P_0c0c30c8: /* original 0d34, guest PC 0x0c0c30c8 */
if(!s->budget--) { s->failed_pc=0x0c0c30c8u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c30ca;
P_0c0c30ca: /* original 84d4, guest PC 0x0c0c30ca */
if(!s->budget--) { s->failed_pc=0x0c0c30cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c0c30cc;
P_0c0c30cc: /* original 2008, guest PC 0x0c0c30cc */
if(!s->budget--) { s->failed_pc=0x0c0c30ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c30ce;
P_0c0c30ce: /* original 8b0b, guest PC 0x0c0c30ce */
if(!s->budget--) { s->failed_pc=0x0c0c30ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c30e8; }
goto P_0c0c30d0;
P_0c0c30d0: /* original e038, guest PC 0x0c0c30d0 */
if(!s->budget--) { s->failed_pc=0x0c0c30d0u; return 0; }
r[0]=0x00000038u;
goto P_0c0c30d2;
P_0c0c30d2: /* original 0de4, guest PC 0x0c0c30d2 */
if(!s->budget--) { s->failed_pc=0x0c0c30d2u; return 0; }
write(ram,r[13]+r[0],r[14],1);
goto P_0c0c30d4;
P_0c0c30d4: /* original 5acb, guest PC 0x0c0c30d4 */
if(!s->budget--) { s->failed_pc=0x0c0c30d4u; return 0; }
r[10]=read(ram,r[12]+44,4);
goto P_0c0c30d6;
P_0c0c30d6: /* original 58c4, guest PC 0x0c0c30d6 */
if(!s->budget--) { s->failed_pc=0x0c0c30d6u; return 0; }
r[8]=read(ram,r[12]+16,4);
goto P_0c0c30d8;
P_0c0c30d8: /* original a009, guest PC 0x0c0c30d8 */
if(!s->budget--) { s->failed_pc=0x0c0c30d8u; return 0; }
r[3]=read(ram,r[12]+20,4);
goto P_0c0c30ee;
P_0c0c30da: /* original 53c5, guest PC 0x0c0c30da */
if(!s->budget--) { s->failed_pc=0x0c0c30dau; return 0; }
r[3]=read(ram,r[12]+20,4);
return vf3_matrix_family(0x0c0c30dcu,s,ram);
P_0c0c30e8: /* original 53c4, guest PC 0x0c0c30e8 */
if(!s->budget--) { s->failed_pc=0x0c0c30e8u; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c0c30ea;
P_0c0c30ea: /* original 58c5, guest PC 0x0c0c30ea */
if(!s->budget--) { s->failed_pc=0x0c0c30eau; return 0; }
r[8]=read(ram,r[12]+20,4);
goto P_0c0c30ec;
P_0c0c30ec: /* original 5aca, guest PC 0x0c0c30ec */
if(!s->budget--) { s->failed_pc=0x0c0c30ecu; return 0; }
r[10]=read(ram,r[12]+40,4);
goto P_0c0c30ee;
P_0c0c30ee: /* original 2f32, guest PC 0x0c0c30ee */
if(!s->budget--) { s->failed_pc=0x0c0c30eeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c30f0;
P_0c0c30f0: /* original 6633, guest PC 0x0c0c30f0 */
if(!s->budget--) { s->failed_pc=0x0c0c30f0u; return 0; }
r[6]=r[3];
goto P_0c0c30f2;
P_0c0c30f2: /* original 5092, guest PC 0x0c0c30f2 */
if(!s->budget--) { s->failed_pc=0x0c0c30f2u; return 0; }
r[0]=read(ram,r[9]+8,4);
goto P_0c0c30f4;
P_0c0c30f4: /* original c804, guest PC 0x0c0c30f4 */
if(!s->budget--) { s->failed_pc=0x0c0c30f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0c30f6;
P_0c0c30f6: /* original 8934, guest PC 0x0c0c30f6 */
if(!s->budget--) { s->failed_pc=0x0c0c30f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3162; }
goto P_0c0c30f8;
P_0c0c30f8: /* original e068, guest PC 0x0c0c30f8 */
if(!s->budget--) { s->failed_pc=0x0c0c30f8u; return 0; }
r[0]=0x00000068u;
goto P_0c0c30fa;
P_0c0c30fa: /* original 04dc, guest PC 0x0c0c30fa */
if(!s->budget--) { s->failed_pc=0x0c0c30fau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c30fc;
P_0c0c30fc: /* original 644c, guest PC 0x0c0c30fc */
if(!s->budget--) { s->failed_pc=0x0c0c30fcu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c30fe;
P_0c0c30fe: /* original 34b2, guest PC 0x0c0c30fe */
if(!s->budget--) { s->failed_pc=0x0c0c30feu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[11])!=0);
goto P_0c0c3100;
P_0c0c3100: /* original 8f02, guest PC 0x0c0c3100 */
if(!s->budget--) { s->failed_pc=0x0c0c3100u; return 0; }
cond=r[17]&1u;
r[5]=r[4];
if(!cond) { goto P_0c0c3108; }
goto P_0c0c3104;
P_0c0c3102: /* original 6543, guest PC 0x0c0c3102 */
if(!s->budget--) { s->failed_pc=0x0c0c3102u; return 0; }
r[5]=r[4];
goto P_0c0c3104;
P_0c0c3104: /* original 6543, guest PC 0x0c0c3104 */
if(!s->budget--) { s->failed_pc=0x0c0c3104u; return 0; }
r[5]=r[4];
goto P_0c0c3106;
P_0c0c3106: /* original 75f3, guest PC 0x0c0c3106 */
if(!s->budget--) { s->failed_pc=0x0c0c3106u; return 0; }
r[5]+=0xfffffff3u;
goto P_0c0c3108;
P_0c0c3108: /* original e061, guest PC 0x0c0c3108 */
if(!s->budget--) { s->failed_pc=0x0c0c3108u; return 0; }
r[0]=0x00000061u;
goto P_0c0c310a;
P_0c0c310a: /* original 0854, guest PC 0x0c0c310a */
if(!s->budget--) { s->failed_pc=0x0c0c310au; return 0; }
write(ram,r[8]+r[0],r[5],1);
goto P_0c0c310c;
P_0c0c310c: /* original e032, guest PC 0x0c0c310c */
if(!s->budget--) { s->failed_pc=0x0c0c310cu; return 0; }
r[0]=0x00000032u;
goto P_0c0c310e;
P_0c0c310e: /* original 0d44, guest PC 0x0c0c310e */
if(!s->budget--) { s->failed_pc=0x0c0c310eu; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0c3110;
P_0c0c3110: /* original e060, guest PC 0x0c0c3110 */
if(!s->budget--) { s->failed_pc=0x0c0c3110u; return 0; }
r[0]=0x00000060u;
goto P_0c0c3112;
P_0c0c3112: /* original 0844, guest PC 0x0c0c3112 */
if(!s->budget--) { s->failed_pc=0x0c0c3112u; return 0; }
write(ram,r[8]+r[0],r[4],1);
goto P_0c0c3114;
P_0c0c3114: /* original 6453, guest PC 0x0c0c3114 */
if(!s->budget--) { s->failed_pc=0x0c0c3114u; return 0; }
r[4]=r[5];
goto P_0c0c3116;
P_0c0c3116: /* original d739, guest PC 0x0c0c3116 */
if(!s->budget--) { s->failed_pc=0x0c0c3116u; return 0; }
r[7]=read(ram,0x0c0c31fcu,4);
goto P_0c0c3118;
P_0c0c3118: /* original 4400, guest PC 0x0c0c3118 */
if(!s->budget--) { s->failed_pc=0x0c0c3118u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c311a;
P_0c0c311a: /* original e035, guest PC 0x0c0c311a */
if(!s->budget--) { s->failed_pc=0x0c0c311au; return 0; }
r[0]=0x00000035u;
goto P_0c0c311c;
P_0c0c311c: /* original 347c, guest PC 0x0c0c311c */
if(!s->budget--) { s->failed_pc=0x0c0c311cu; return 0; }
r[4]+=r[7];
goto P_0c0c311e;
P_0c0c311e: /* original 6340, guest PC 0x0c0c311e */
if(!s->budget--) { s->failed_pc=0x0c0c311eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c0c3120;
P_0c0c3120: /* original e134, guest PC 0x0c0c3120 */
if(!s->budget--) { s->failed_pc=0x0c0c3120u; return 0; }
r[1]=0x00000034u;
goto P_0c0c3122;
P_0c0c3122: /* original 31dc, guest PC 0x0c0c3122 */
if(!s->budget--) { s->failed_pc=0x0c0c3122u; return 0; }
r[1]+=r[13];
goto P_0c0c3124;
P_0c0c3124: /* original 0d34, guest PC 0x0c0c3124 */
if(!s->budget--) { s->failed_pc=0x0c0c3124u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c3126;
P_0c0c3126: /* original e308, guest PC 0x0c0c3126 */
if(!s->budget--) { s->failed_pc=0x0c0c3126u; return 0; }
r[3]=0x00000008u;
goto P_0c0c3128;
P_0c0c3128: /* original 8441, guest PC 0x0c0c3128 */
if(!s->budget--) { s->failed_pc=0x0c0c3128u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0c312a;
P_0c0c312a: /* original 2100, guest PC 0x0c0c312a */
if(!s->budget--) { s->failed_pc=0x0c0c312au; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0c312c;
P_0c0c312c: /* original 64a2, guest PC 0x0c0c312c */
if(!s->budget--) { s->failed_pc=0x0c0c312cu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c312e;
P_0c0c312e: /* original 2438, guest PC 0x0c0c312e */
if(!s->budget--) { s->failed_pc=0x0c0c312eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c3130;
P_0c0c3130: /* original 8917, guest PC 0x0c0c3130 */
if(!s->budget--) { s->failed_pc=0x0c0c3130u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3162; }
goto P_0c0c3132;
P_0c0c3132: /* original e068, guest PC 0x0c0c3132 */
if(!s->budget--) { s->failed_pc=0x0c0c3132u; return 0; }
r[0]=0x00000068u;
goto P_0c0c3134;
P_0c0c3134: /* original 04ac, guest PC 0x0c0c3134 */
if(!s->budget--) { s->failed_pc=0x0c0c3134u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0c3136;
P_0c0c3136: /* original 644c, guest PC 0x0c0c3136 */
if(!s->budget--) { s->failed_pc=0x0c0c3136u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c3138;
P_0c0c3138: /* original 34b2, guest PC 0x0c0c3138 */
if(!s->budget--) { s->failed_pc=0x0c0c3138u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[11])!=0);
goto P_0c0c313a;
P_0c0c313a: /* original 8f02, guest PC 0x0c0c313a */
if(!s->budget--) { s->failed_pc=0x0c0c313au; return 0; }
cond=r[17]&1u;
r[5]=r[4];
if(!cond) { goto P_0c0c3142; }
goto P_0c0c313e;
P_0c0c313c: /* original 6543, guest PC 0x0c0c313c */
if(!s->budget--) { s->failed_pc=0x0c0c313cu; return 0; }
r[5]=r[4];
goto P_0c0c313e;
P_0c0c313e: /* original 6543, guest PC 0x0c0c313e */
if(!s->budget--) { s->failed_pc=0x0c0c313eu; return 0; }
r[5]=r[4];
goto P_0c0c3140;
P_0c0c3140: /* original 75f3, guest PC 0x0c0c3140 */
if(!s->budget--) { s->failed_pc=0x0c0c3140u; return 0; }
r[5]+=0xfffffff3u;
goto P_0c0c3142;
P_0c0c3142: /* original e061, guest PC 0x0c0c3142 */
if(!s->budget--) { s->failed_pc=0x0c0c3142u; return 0; }
r[0]=0x00000061u;
goto P_0c0c3144;
P_0c0c3144: /* original 0654, guest PC 0x0c0c3144 */
if(!s->budget--) { s->failed_pc=0x0c0c3144u; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c0c3146;
P_0c0c3146: /* original e032, guest PC 0x0c0c3146 */
if(!s->budget--) { s->failed_pc=0x0c0c3146u; return 0; }
r[0]=0x00000032u;
goto P_0c0c3148;
P_0c0c3148: /* original 0a44, guest PC 0x0c0c3148 */
if(!s->budget--) { s->failed_pc=0x0c0c3148u; return 0; }
write(ram,r[10]+r[0],r[4],1);
goto P_0c0c314a;
P_0c0c314a: /* original e060, guest PC 0x0c0c314a */
if(!s->budget--) { s->failed_pc=0x0c0c314au; return 0; }
r[0]=0x00000060u;
goto P_0c0c314c;
P_0c0c314c: /* original 0644, guest PC 0x0c0c314c */
if(!s->budget--) { s->failed_pc=0x0c0c314cu; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c314e;
P_0c0c314e: /* original 6453, guest PC 0x0c0c314e */
if(!s->budget--) { s->failed_pc=0x0c0c314eu; return 0; }
r[4]=r[5];
goto P_0c0c3150;
P_0c0c3150: /* original 4400, guest PC 0x0c0c3150 */
if(!s->budget--) { s->failed_pc=0x0c0c3150u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c3152;
P_0c0c3152: /* original 347c, guest PC 0x0c0c3152 */
if(!s->budget--) { s->failed_pc=0x0c0c3152u; return 0; }
r[4]+=r[7];
goto P_0c0c3154;
P_0c0c3154: /* original 6340, guest PC 0x0c0c3154 */
if(!s->budget--) { s->failed_pc=0x0c0c3154u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c0c3156;
P_0c0c3156: /* original e035, guest PC 0x0c0c3156 */
if(!s->budget--) { s->failed_pc=0x0c0c3156u; return 0; }
r[0]=0x00000035u;
goto P_0c0c3158;
P_0c0c3158: /* original e134, guest PC 0x0c0c3158 */
if(!s->budget--) { s->failed_pc=0x0c0c3158u; return 0; }
r[1]=0x00000034u;
goto P_0c0c315a;
P_0c0c315a: /* original 0a34, guest PC 0x0c0c315a */
if(!s->budget--) { s->failed_pc=0x0c0c315au; return 0; }
write(ram,r[10]+r[0],r[3],1);
goto P_0c0c315c;
P_0c0c315c: /* original 31ac, guest PC 0x0c0c315c */
if(!s->budget--) { s->failed_pc=0x0c0c315cu; return 0; }
r[1]+=r[10];
goto P_0c0c315e;
P_0c0c315e: /* original 8441, guest PC 0x0c0c315e */
if(!s->budget--) { s->failed_pc=0x0c0c315eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0c3160;
P_0c0c3160: /* original 2100, guest PC 0x0c0c3160 */
if(!s->budget--) { s->failed_pc=0x0c0c3160u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0c3162;
P_0c0c3162: /* original e032, guest PC 0x0c0c3162 */
if(!s->budget--) { s->failed_pc=0x0c0c3162u; return 0; }
r[0]=0x00000032u;
goto P_0c0c3164;
P_0c0c3164: /* original 04dc, guest PC 0x0c0c3164 */
if(!s->budget--) { s->failed_pc=0x0c0c3164u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c3166;
P_0c0c3166: /* original e060, guest PC 0x0c0c3166 */
if(!s->budget--) { s->failed_pc=0x0c0c3166u; return 0; }
r[0]=0x00000060u;
goto P_0c0c3168;
P_0c0c3168: /* original 644c, guest PC 0x0c0c3168 */
if(!s->budget--) { s->failed_pc=0x0c0c3168u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c316a;
P_0c0c316a: /* original 0844, guest PC 0x0c0c316a */
if(!s->budget--) { s->failed_pc=0x0c0c316au; return 0; }
write(ram,r[8]+r[0],r[4],1);
goto P_0c0c316c;
P_0c0c316c: /* original e032, guest PC 0x0c0c316c */
if(!s->budget--) { s->failed_pc=0x0c0c316cu; return 0; }
r[0]=0x00000032u;
goto P_0c0c316e;
P_0c0c316e: /* original 9442, guest PC 0x0c0c316e */
if(!s->budget--) { s->failed_pc=0x0c0c316eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c31f6u,2);
goto P_0c0c3170;
P_0c0c3170: /* original 0d44, guest PC 0x0c0c3170 */
if(!s->budget--) { s->failed_pc=0x0c0c3170u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0c3172;
P_0c0c3172: /* original 9041, guest PC 0x0c0c3172 */
if(!s->budget--) { s->failed_pc=0x0c0c3172u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c31f8u,2);
goto P_0c0c3174;
P_0c0c3174: /* original 0844, guest PC 0x0c0c3174 */
if(!s->budget--) { s->failed_pc=0x0c0c3174u; return 0; }
write(ram,r[8]+r[0],r[4],1);
goto P_0c0c3176;
P_0c0c3176: /* original 0644, guest PC 0x0c0c3176 */
if(!s->budget--) { s->failed_pc=0x0c0c3176u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c3178;
P_0c0c3178: /* original d321, guest PC 0x0c0c3178 */
if(!s->budget--) { s->failed_pc=0x0c0c3178u; return 0; }
r[3]=read(ram,0x0c0c3200u,4);
goto P_0c0c317a;
P_0c0c317a: /* original d222, guest PC 0x0c0c317a */
if(!s->budget--) { s->failed_pc=0x0c0c317au; return 0; }
r[2]=read(ram,0x0c0c3204u,4);
goto P_0c0c317c;
P_0c0c317c: /* original 420b, guest PC 0x0c0c317c */
if(!s->budget--) { s->failed_pc=0x0c0c317cu; return 0; }
target=r[2];
r[16]=0x0c0c3180u;
write(ram,r[13]+12,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3180u) { target=s->pc; goto dispatch; }
goto P_0c0c3180;
P_0c0c317e: /* original 1d33, guest PC 0x0c0c317e */
if(!s->budget--) { s->failed_pc=0x0c0c317eu; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c0c3180;
P_0c0c3180: /* original d121, guest PC 0x0c0c3180 */
if(!s->budget--) { s->failed_pc=0x0c0c3180u; return 0; }
r[1]=read(ram,0x0c0c3208u,4);
goto P_0c0c3182;
P_0c0c3182: /* original 410b, guest PC 0x0c0c3182 */
if(!s->budget--) { s->failed_pc=0x0c0c3182u; return 0; }
target=r[1];
r[16]=0x0c0c3186u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3186u) { target=s->pc; goto dispatch; }
goto P_0c0c3186;
P_0c0c3184: /* original 0009, guest PC 0x0c0c3184 */
if(!s->budget--) { s->failed_pc=0x0c0c3184u; return 0; }
goto P_0c0c3186;
P_0c0c3186: /* original 54cb, guest PC 0x0c0c3186 */
if(!s->budget--) { s->failed_pc=0x0c0c3186u; return 0; }
r[4]=read(ram,r[12]+44,4);
goto P_0c0c3188;
P_0c0c3188: /* original e064, guest PC 0x0c0c3188 */
if(!s->budget--) { s->failed_pc=0x0c0c3188u; return 0; }
r[0]=0x00000064u;
goto P_0c0c318a;
P_0c0c318a: /* original 55ca, guest PC 0x0c0c318a */
if(!s->budget--) { s->failed_pc=0x0c0c318au; return 0; }
r[5]=read(ram,r[12]+40,4);
goto P_0c0c318c;
P_0c0c318c: /* original 05e4, guest PC 0x0c0c318c */
if(!s->budget--) { s->failed_pc=0x0c0c318cu; return 0; }
write(ram,r[5]+r[0],r[14],1);
goto P_0c0c318e;
P_0c0c318e: /* original 04e4, guest PC 0x0c0c318e */
if(!s->budget--) { s->failed_pc=0x0c0c318eu; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0c3190;
P_0c0c3190: /* original e04c, guest PC 0x0c0c3190 */
if(!s->budget--) { s->failed_pc=0x0c0c3190u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c3192;
P_0c0c3192: /* original 0de5, guest PC 0x0c0c3192 */
if(!s->budget--) { s->failed_pc=0x0c0c3192u; return 0; }
write(ram,r[13]+r[0],r[14],2);
goto P_0c0c3194;
P_0c0c3194: /* original e044, guest PC 0x0c0c3194 */
if(!s->budget--) { s->failed_pc=0x0c0c3194u; return 0; }
r[0]=0x00000044u;
goto P_0c0c3196;
P_0c0c3196: /* original 0de5, guest PC 0x0c0c3196 */
if(!s->budget--) { s->failed_pc=0x0c0c3196u; return 0; }
write(ram,r[13]+r[0],r[14],2);
goto P_0c0c3198;
P_0c0c3198: /* original e04e, guest PC 0x0c0c3198 */
if(!s->budget--) { s->failed_pc=0x0c0c3198u; return 0; }
r[0]=0x0000004eu;
goto P_0c0c319a;
P_0c0c319a: /* original 942e, guest PC 0x0c0c319a */
if(!s->budget--) { s->failed_pc=0x0c0c319au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c31fau,2);
goto P_0c0c319c;
P_0c0c319c: /* original 0d45, guest PC 0x0c0c319c */
if(!s->budget--) { s->failed_pc=0x0c0c319cu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c0c319e;
P_0c0c319e: /* original e04c, guest PC 0x0c0c319e */
if(!s->budget--) { s->failed_pc=0x0c0c319eu; return 0; }
r[0]=0x0000004cu;
goto P_0c0c31a0;
P_0c0c31a0: /* original 0ae5, guest PC 0x0c0c31a0 */
if(!s->budget--) { s->failed_pc=0x0c0c31a0u; return 0; }
write(ram,r[10]+r[0],r[14],2);
goto P_0c0c31a2;
P_0c0c31a2: /* original e044, guest PC 0x0c0c31a2 */
if(!s->budget--) { s->failed_pc=0x0c0c31a2u; return 0; }
r[0]=0x00000044u;
goto P_0c0c31a4;
P_0c0c31a4: /* original 0ae5, guest PC 0x0c0c31a4 */
if(!s->budget--) { s->failed_pc=0x0c0c31a4u; return 0; }
write(ram,r[10]+r[0],r[14],2);
goto P_0c0c31a6;
P_0c0c31a6: /* original b3ec, guest PC 0x0c0c31a6 */
if(!s->budget--) { s->failed_pc=0x0c0c31a6u; return 0; }
target=0x0c0c3982u; r[16]=0x0c0c31aau;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c31aau) { target=s->pc; goto dispatch; }
goto P_0c0c31aa;
P_0c0c31a8: /* original 64f2, guest PC 0x0c0c31a8 */
if(!s->budget--) { s->failed_pc=0x0c0c31a8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c31aa;
P_0c0c31aa: /* original d318, guest PC 0x0c0c31aa */
if(!s->budget--) { s->failed_pc=0x0c0c31aau; return 0; }
r[3]=read(ram,0x0c0c320cu,4);
goto P_0c0c31ac;
P_0c0c31ac: /* original 430b, guest PC 0x0c0c31ac */
if(!s->budget--) { s->failed_pc=0x0c0c31acu; return 0; }
target=r[3];
r[16]=0x0c0c31b0u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c31b0u) { target=s->pc; goto dispatch; }
goto P_0c0c31b0;
P_0c0c31ae: /* original 64f2, guest PC 0x0c0c31ae */
if(!s->budget--) { s->failed_pc=0x0c0c31aeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c31b0;
P_0c0c31b0: /* original b3e7, guest PC 0x0c0c31b0 */
if(!s->budget--) { s->failed_pc=0x0c0c31b0u; return 0; }
target=0x0c0c3982u; r[16]=0x0c0c31b4u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c31b4u) { target=s->pc; goto dispatch; }
goto P_0c0c31b4;
P_0c0c31b2: /* original 6483, guest PC 0x0c0c31b2 */
if(!s->budget--) { s->failed_pc=0x0c0c31b2u; return 0; }
r[4]=r[8];
goto P_0c0c31b4;
P_0c0c31b4: /* original d315, guest PC 0x0c0c31b4 */
if(!s->budget--) { s->failed_pc=0x0c0c31b4u; return 0; }
r[3]=read(ram,0x0c0c320cu,4);
goto P_0c0c31b6;
P_0c0c31b6: /* original 430b, guest PC 0x0c0c31b6 */
if(!s->budget--) { s->failed_pc=0x0c0c31b6u; return 0; }
target=r[3];
r[16]=0x0c0c31bau;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c31bau) { target=s->pc; goto dispatch; }
goto P_0c0c31ba;
P_0c0c31b8: /* original 6483, guest PC 0x0c0c31b8 */
if(!s->budget--) { s->failed_pc=0x0c0c31b8u; return 0; }
r[4]=r[8];
goto P_0c0c31ba;
P_0c0c31ba: /* original e051, guest PC 0x0c0c31ba */
if(!s->budget--) { s->failed_pc=0x0c0c31bau; return 0; }
r[0]=0x00000051u;
goto P_0c0c31bc;
P_0c0c31bc: /* original 0de4, guest PC 0x0c0c31bc */
if(!s->budget--) { s->failed_pc=0x0c0c31bcu; return 0; }
write(ram,r[13]+r[0],r[14],1);
goto P_0c0c31be;
P_0c0c31be: /* original e054, guest PC 0x0c0c31be */
if(!s->budget--) { s->failed_pc=0x0c0c31beu; return 0; }
r[0]=0x00000054u;
goto P_0c0c31c0;
P_0c0c31c0: /* original 0de4, guest PC 0x0c0c31c0 */
if(!s->budget--) { s->failed_pc=0x0c0c31c0u; return 0; }
write(ram,r[13]+r[0],r[14],1);
goto P_0c0c31c2;
P_0c0c31c2: /* original e057, guest PC 0x0c0c31c2 */
if(!s->budget--) { s->failed_pc=0x0c0c31c2u; return 0; }
r[0]=0x00000057u;
goto P_0c0c31c4;
P_0c0c31c4: /* original 0de4, guest PC 0x0c0c31c4 */
if(!s->budget--) { s->failed_pc=0x0c0c31c4u; return 0; }
write(ram,r[13]+r[0],r[14],1);
goto P_0c0c31c6;
P_0c0c31c6: /* original e314, guest PC 0x0c0c31c6 */
if(!s->budget--) { s->failed_pc=0x0c0c31c6u; return 0; }
r[3]=0x00000014u;
goto P_0c0c31c8;
P_0c0c31c8: /* original e050, guest PC 0x0c0c31c8 */
if(!s->budget--) { s->failed_pc=0x0c0c31c8u; return 0; }
r[0]=0x00000050u;
goto P_0c0c31ca;
P_0c0c31ca: /* original 0d34, guest PC 0x0c0c31ca */
if(!s->budget--) { s->failed_pc=0x0c0c31cau; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c31cc;
P_0c0c31cc: /* original 54f1, guest PC 0x0c0c31cc */
if(!s->budget--) { s->failed_pc=0x0c0c31ccu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c31ce;
P_0c0c31ce: /* original 7f08, guest PC 0x0c0c31ce */
if(!s->budget--) { s->failed_pc=0x0c0c31ceu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c31d0;
P_0c0c31d0: /* original 4f26, guest PC 0x0c0c31d0 */
if(!s->budget--) { s->failed_pc=0x0c0c31d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c31d2;
P_0c0c31d2: /* original 68f6, guest PC 0x0c0c31d2 */
if(!s->budget--) { s->failed_pc=0x0c0c31d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c31d4;
P_0c0c31d4: /* original 69f6, guest PC 0x0c0c31d4 */
if(!s->budget--) { s->failed_pc=0x0c0c31d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c31d6;
P_0c0c31d6: /* original 6af6, guest PC 0x0c0c31d6 */
if(!s->budget--) { s->failed_pc=0x0c0c31d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c31d8;
P_0c0c31d8: /* original 6bf6, guest PC 0x0c0c31d8 */
if(!s->budget--) { s->failed_pc=0x0c0c31d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c31da;
P_0c0c31da: /* original 6cf6, guest PC 0x0c0c31da */
if(!s->budget--) { s->failed_pc=0x0c0c31dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c31dc;
P_0c0c31dc: /* original 6df6, guest PC 0x0c0c31dc */
if(!s->budget--) { s->failed_pc=0x0c0c31dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c31de;
P_0c0c31de: /* original a017, guest PC 0x0c0c31de */
if(!s->budget--) { s->failed_pc=0x0c0c31deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c3210;
P_0c0c31e0: /* original 6ef6, guest PC 0x0c0c31e0 */
if(!s->budget--) { s->failed_pc=0x0c0c31e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c31e2;
P_0c0c31e2: /* original 7f08, guest PC 0x0c0c31e2 */
if(!s->budget--) { s->failed_pc=0x0c0c31e2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c31e4;
P_0c0c31e4: /* original 4f26, guest PC 0x0c0c31e4 */
if(!s->budget--) { s->failed_pc=0x0c0c31e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c31e6;
P_0c0c31e6: /* original 68f6, guest PC 0x0c0c31e6 */
if(!s->budget--) { s->failed_pc=0x0c0c31e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c31e8;
P_0c0c31e8: /* original 69f6, guest PC 0x0c0c31e8 */
if(!s->budget--) { s->failed_pc=0x0c0c31e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c31ea;
P_0c0c31ea: /* original 6af6, guest PC 0x0c0c31ea */
if(!s->budget--) { s->failed_pc=0x0c0c31eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c31ec;
P_0c0c31ec: /* original 6bf6, guest PC 0x0c0c31ec */
if(!s->budget--) { s->failed_pc=0x0c0c31ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c31ee;
P_0c0c31ee: /* original 6cf6, guest PC 0x0c0c31ee */
if(!s->budget--) { s->failed_pc=0x0c0c31eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c31f0;
P_0c0c31f0: /* original 6df6, guest PC 0x0c0c31f0 */
if(!s->budget--) { s->failed_pc=0x0c0c31f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c31f2;
P_0c0c31f2: /* original 000b, guest PC 0x0c0c31f2 */
if(!s->budget--) { s->failed_pc=0x0c0c31f2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c31f4: /* original 6ef6, guest PC 0x0c0c31f4 */
if(!s->budget--) { s->failed_pc=0x0c0c31f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c31f6u,s,ram);
P_0c0c3210: /* original 2fe6, guest PC 0x0c0c3210 */
if(!s->budget--) { s->failed_pc=0x0c0c3210u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3212;
P_0c0c3212: /* original 2fd6, guest PC 0x0c0c3212 */
if(!s->budget--) { s->failed_pc=0x0c0c3212u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3214;
P_0c0c3214: /* original 2fc6, guest PC 0x0c0c3214 */
if(!s->budget--) { s->failed_pc=0x0c0c3214u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3216;
P_0c0c3216: /* original 2fb6, guest PC 0x0c0c3216 */
if(!s->budget--) { s->failed_pc=0x0c0c3216u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3218;
P_0c0c3218: /* original 2fa6, guest PC 0x0c0c3218 */
if(!s->budget--) { s->failed_pc=0x0c0c3218u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c321a;
P_0c0c321a: /* original 2f96, guest PC 0x0c0c321a */
if(!s->budget--) { s->failed_pc=0x0c0c321au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c321c;
P_0c0c321c: /* original 2f86, guest PC 0x0c0c321c */
if(!s->budget--) { s->failed_pc=0x0c0c321cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c321e;
P_0c0c321e: /* original 4f22, guest PC 0x0c0c321e */
if(!s->budget--) { s->failed_pc=0x0c0c321eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c3220;
P_0c0c3220: /* original d343, guest PC 0x0c0c3220 */
if(!s->budget--) { s->failed_pc=0x0c0c3220u; return 0; }
r[3]=read(ram,0x0c0c3330u,4);
goto P_0c0c3222;
P_0c0c3222: /* original da42, guest PC 0x0c0c3222 */
if(!s->budget--) { s->failed_pc=0x0c0c3222u; return 0; }
r[10]=read(ram,0x0c0c332cu,4);
goto P_0c0c3224;
P_0c0c3224: /* original 7fd8, guest PC 0x0c0c3224 */
if(!s->budget--) { s->failed_pc=0x0c0c3224u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0c3226;
P_0c0c3226: /* original dd40, guest PC 0x0c0c3226 */
if(!s->budget--) { s->failed_pc=0x0c0c3226u; return 0; }
r[13]=read(ram,0x0c0c3328u,4);
goto P_0c0c3228;
P_0c0c3228: /* original 1f37, guest PC 0x0c0c3228 */
if(!s->budget--) { s->failed_pc=0x0c0c3228u; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c0c322a;
P_0c0c322a: /* original 9377, guest PC 0x0c0c322a */
if(!s->budget--) { s->failed_pc=0x0c0c322au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c331cu,2);
goto P_0c0c322c;
P_0c0c322c: /* original 62a2, guest PC 0x0c0c322c */
if(!s->budget--) { s->failed_pc=0x0c0c322cu; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0c322e;
P_0c0c322e: /* original d941, guest PC 0x0c0c322e */
if(!s->budget--) { s->failed_pc=0x0c0c322eu; return 0; }
r[9]=read(ram,0x0c0c3334u,4);
goto P_0c0c3230;
P_0c0c3230: /* original 2238, guest PC 0x0c0c3230 */
if(!s->budget--) { s->failed_pc=0x0c0c3230u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c3232;
P_0c0c3232: /* original 8d02, guest PC 0x0c0c3232 */
if(!s->budget--) { s->failed_pc=0x0c0c3232u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c0c323a; }
goto P_0c0c3236;
P_0c0c3234: /* original 6e43, guest PC 0x0c0c3234 */
if(!s->budget--) { s->failed_pc=0x0c0c3234u; return 0; }
r[14]=r[4];
goto P_0c0c3236;
P_0c0c3236: /* original a33c, guest PC 0x0c0c3236 */
if(!s->budget--) { s->failed_pc=0x0c0c3236u; return 0; }
goto P_0c0c38b2;
P_0c0c3238: /* original 0009, guest PC 0x0c0c3238 */
if(!s->budget--) { s->failed_pc=0x0c0c3238u; return 0; }
goto P_0c0c323a;
P_0c0c323a: /* original d040, guest PC 0x0c0c323a */
if(!s->budget--) { s->failed_pc=0x0c0c323au; return 0; }
r[0]=read(ram,0x0c0c333cu,4);
goto P_0c0c323c;
P_0c0c323c: /* original d33e, guest PC 0x0c0c323c */
if(!s->budget--) { s->failed_pc=0x0c0c323cu; return 0; }
r[3]=read(ram,0x0c0c3338u,4);
goto P_0c0c323e;
P_0c0c323e: /* original 6102, guest PC 0x0c0c323e */
if(!s->budget--) { s->failed_pc=0x0c0c323eu; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0c3240;
P_0c0c3240: /* original 2138, guest PC 0x0c0c3240 */
if(!s->budget--) { s->failed_pc=0x0c0c3240u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c3242;
P_0c0c3242: /* original 8901, guest PC 0x0c0c3242 */
if(!s->budget--) { s->failed_pc=0x0c0c3242u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3248; }
goto P_0c0c3244;
P_0c0c3244: /* original a335, guest PC 0x0c0c3244 */
if(!s->budget--) { s->failed_pc=0x0c0c3244u; return 0; }
goto P_0c0c38b2;
P_0c0c3246: /* original 0009, guest PC 0x0c0c3246 */
if(!s->budget--) { s->failed_pc=0x0c0c3246u; return 0; }
goto P_0c0c3248;
P_0c0c3248: /* original 60e2, guest PC 0x0c0c3248 */
if(!s->budget--) { s->failed_pc=0x0c0c3248u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c324a;
P_0c0c324a: /* original c80a, guest PC 0x0c0c324a */
if(!s->budget--) { s->failed_pc=0x0c0c324au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&10u)==0)!=0);
goto P_0c0c324c;
P_0c0c324c: /* original 8901, guest PC 0x0c0c324c */
if(!s->budget--) { s->failed_pc=0x0c0c324cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3252; }
goto P_0c0c324e;
P_0c0c324e: /* original a330, guest PC 0x0c0c324e */
if(!s->budget--) { s->failed_pc=0x0c0c324eu; return 0; }
goto P_0c0c38b2;
P_0c0c3250: /* original 0009, guest PC 0x0c0c3250 */
if(!s->budget--) { s->failed_pc=0x0c0c3250u; return 0; }
goto P_0c0c3252;
P_0c0c3252: /* original b37b, guest PC 0x0c0c3252 */
if(!s->budget--) { s->failed_pc=0x0c0c3252u; return 0; }
target=0x0c0c394cu; r[16]=0x0c0c3256u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3256u) { target=s->pc; goto dispatch; }
goto P_0c0c3256;
P_0c0c3254: /* original 0009, guest PC 0x0c0c3254 */
if(!s->budget--) { s->failed_pc=0x0c0c3254u; return 0; }
goto P_0c0c3256;
P_0c0c3256: /* original e031, guest PC 0x0c0c3256 */
if(!s->budget--) { s->failed_pc=0x0c0c3256u; return 0; }
r[0]=0x00000031u;
goto P_0c0c3258;
P_0c0c3258: /* original 02ec, guest PC 0x0c0c3258 */
if(!s->budget--) { s->failed_pc=0x0c0c3258u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c325a;
P_0c0c325a: /* original e034, guest PC 0x0c0c325a */
if(!s->budget--) { s->failed_pc=0x0c0c325au; return 0; }
r[0]=0x00000034u;
goto P_0c0c325c;
P_0c0c325c: /* original 622c, guest PC 0x0c0c325c */
if(!s->budget--) { s->failed_pc=0x0c0c325cu; return 0; }
r[2]=r[2]&255u;
goto P_0c0c325e;
P_0c0c325e: /* original 1f24, guest PC 0x0c0c325e */
if(!s->budget--) { s->failed_pc=0x0c0c325eu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0c3260;
P_0c0c3260: /* original 03ec, guest PC 0x0c0c3260 */
if(!s->budget--) { s->failed_pc=0x0c0c3260u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3262;
P_0c0c3262: /* original e035, guest PC 0x0c0c3262 */
if(!s->budget--) { s->failed_pc=0x0c0c3262u; return 0; }
r[0]=0x00000035u;
goto P_0c0c3264;
P_0c0c3264: /* original 633c, guest PC 0x0c0c3264 */
if(!s->budget--) { s->failed_pc=0x0c0c3264u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c3266;
P_0c0c3266: /* original 2f32, guest PC 0x0c0c3266 */
if(!s->budget--) { s->failed_pc=0x0c0c3266u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3268;
P_0c0c3268: /* original d435, guest PC 0x0c0c3268 */
if(!s->budget--) { s->failed_pc=0x0c0c3268u; return 0; }
r[4]=read(ram,0x0c0c3340u,4);
goto P_0c0c326a;
P_0c0c326a: /* original 0cec, guest PC 0x0c0c326a */
if(!s->budget--) { s->failed_pc=0x0c0c326au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c326c;
P_0c0c326c: /* original 5345, guest PC 0x0c0c326c */
if(!s->budget--) { s->failed_pc=0x0c0c326cu; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c0c326e;
P_0c0c326e: /* original 5b44, guest PC 0x0c0c326e */
if(!s->budget--) { s->failed_pc=0x0c0c326eu; return 0; }
r[11]=read(ram,r[4]+16,4);
goto P_0c0c3270;
P_0c0c3270: /* original 1f35, guest PC 0x0c0c3270 */
if(!s->budget--) { s->failed_pc=0x0c0c3270u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0c3272;
P_0c0c3272: /* original 84e4, guest PC 0x0c0c3272 */
if(!s->budget--) { s->failed_pc=0x0c0c3272u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3274;
P_0c0c3274: /* original 2008, guest PC 0x0c0c3274 */
if(!s->budget--) { s->failed_pc=0x0c0c3274u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c3276;
P_0c0c3276: /* original 8d03, guest PC 0x0c0c3276 */
if(!s->budget--) { s->failed_pc=0x0c0c3276u; return 0; }
cond=r[17]&1u;
r[12]=r[12]&255u;
if(cond) { goto P_0c0c3280; }
goto P_0c0c327a;
P_0c0c3278: /* original 6ccc, guest PC 0x0c0c3278 */
if(!s->budget--) { s->failed_pc=0x0c0c3278u; return 0; }
r[12]=r[12]&255u;
goto P_0c0c327a;
P_0c0c327a: /* original 64b3, guest PC 0x0c0c327a */
if(!s->budget--) { s->failed_pc=0x0c0c327au; return 0; }
r[4]=r[11];
goto P_0c0c327c;
P_0c0c327c: /* original 5bf5, guest PC 0x0c0c327c */
if(!s->budget--) { s->failed_pc=0x0c0c327cu; return 0; }
r[11]=read(ram,r[15]+20,4);
goto P_0c0c327e;
P_0c0c327e: /* original 1f45, guest PC 0x0c0c327e */
if(!s->budget--) { s->failed_pc=0x0c0c327eu; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c0c3280;
P_0c0c3280: /* original e07d, guest PC 0x0c0c3280 */
if(!s->budget--) { s->failed_pc=0x0c0c3280u; return 0; }
r[0]=0x0000007du;
goto P_0c0c3282;
P_0c0c3282: /* original 05ac, guest PC 0x0c0c3282 */
if(!s->budget--) { s->failed_pc=0x0c0c3282u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0c3284;
P_0c0c3284: /* original 904b, guest PC 0x0c0c3284 */
if(!s->budget--) { s->failed_pc=0x0c0c3284u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c331eu,2);
goto P_0c0c3286;
P_0c0c3286: /* original 655c, guest PC 0x0c0c3286 */
if(!s->budget--) { s->failed_pc=0x0c0c3286u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c3288;
P_0c0c3288: /* original 04ae, guest PC 0x0c0c3288 */
if(!s->budget--) { s->failed_pc=0x0c0c3288u; return 0; }
r[4]=read(ram,r[10]+r[0],4);
goto P_0c0c328a;
P_0c0c328a: /* original 6053, guest PC 0x0c0c328a */
if(!s->budget--) { s->failed_pc=0x0c0c328au; return 0; }
r[0]=r[5];
goto P_0c0c328c;
P_0c0c328c: /* original 8801, guest PC 0x0c0c328c */
if(!s->budget--) { s->failed_pc=0x0c0c328cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c328e;
P_0c0c328e: /* original 8905, guest PC 0x0c0c328e */
if(!s->budget--) { s->failed_pc=0x0c0c328eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c329c; }
goto P_0c0c3290;
P_0c0c3290: /* original 8802, guest PC 0x0c0c3290 */
if(!s->budget--) { s->failed_pc=0x0c0c3290u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c3292;
P_0c0c3292: /* original 8908, guest PC 0x0c0c3292 */
if(!s->budget--) { s->failed_pc=0x0c0c3292u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c32a6; }
goto P_0c0c3294;
P_0c0c3294: /* original 8803, guest PC 0x0c0c3294 */
if(!s->budget--) { s->failed_pc=0x0c0c3294u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c3296;
P_0c0c3296: /* original 8929, guest PC 0x0c0c3296 */
if(!s->budget--) { s->failed_pc=0x0c0c3296u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c32ec; }
goto P_0c0c3298;
P_0c0c3298: /* original a028, guest PC 0x0c0c3298 */
if(!s->budget--) { s->failed_pc=0x0c0c3298u; return 0; }
goto P_0c0c32ec;
P_0c0c329a: /* original 0009, guest PC 0x0c0c329a */
if(!s->budget--) { s->failed_pc=0x0c0c329au; return 0; }
goto P_0c0c329c;
P_0c0c329c: /* original e210, guest PC 0x0c0c329c */
if(!s->budget--) { s->failed_pc=0x0c0c329cu; return 0; }
r[2]=0x00000010u;
goto P_0c0c329e;
P_0c0c329e: /* original 2428, guest PC 0x0c0c329e */
if(!s->budget--) { s->failed_pc=0x0c0c329eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0c32a0;
P_0c0c32a0: /* original 8b04, guest PC 0x0c0c32a0 */
if(!s->budget--) { s->failed_pc=0x0c0c32a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c32ac; }
goto P_0c0c32a2;
P_0c0c32a2: /* original a023, guest PC 0x0c0c32a2 */
if(!s->budget--) { s->failed_pc=0x0c0c32a2u; return 0; }
goto P_0c0c32ec;
P_0c0c32a4: /* original 0009, guest PC 0x0c0c32a4 */
if(!s->budget--) { s->failed_pc=0x0c0c32a4u; return 0; }
goto P_0c0c32a6;
P_0c0c32a6: /* original e120, guest PC 0x0c0c32a6 */
if(!s->budget--) { s->failed_pc=0x0c0c32a6u; return 0; }
r[1]=0x00000020u;
goto P_0c0c32a8;
P_0c0c32a8: /* original 2418, guest PC 0x0c0c32a8 */
if(!s->budget--) { s->failed_pc=0x0c0c32a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0c32aa;
P_0c0c32aa: /* original 891f, guest PC 0x0c0c32aa */
if(!s->budget--) { s->failed_pc=0x0c0c32aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c32ec; }
goto P_0c0c32ac;
P_0c0c32ac: /* original 9038, guest PC 0x0c0c32ac */
if(!s->budget--) { s->failed_pc=0x0c0c32acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3320u,2);
goto P_0c0c32ae;
P_0c0c32ae: /* original 03dc, guest PC 0x0c0c32ae */
if(!s->budget--) { s->failed_pc=0x0c0c32aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c32b0;
P_0c0c32b0: /* original 7001, guest PC 0x0c0c32b0 */
if(!s->budget--) { s->failed_pc=0x0c0c32b0u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c32b2;
P_0c0c32b2: /* original 0d34, guest PC 0x0c0c32b2 */
if(!s->budget--) { s->failed_pc=0x0c0c32b2u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c32b4;
P_0c0c32b4: /* original 70fe, guest PC 0x0c0c32b4 */
if(!s->budget--) { s->failed_pc=0x0c0c32b4u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0c32b6;
P_0c0c32b6: /* original 02dc, guest PC 0x0c0c32b6 */
if(!s->budget--) { s->failed_pc=0x0c0c32b6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c32b8;
P_0c0c32b8: /* original 7001, guest PC 0x0c0c32b8 */
if(!s->budget--) { s->failed_pc=0x0c0c32b8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c32ba;
P_0c0c32ba: /* original 0d24, guest PC 0x0c0c32ba */
if(!s->budget--) { s->failed_pc=0x0c0c32bau; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0c32bc;
P_0c0c32bc: /* original 70fe, guest PC 0x0c0c32bc */
if(!s->budget--) { s->failed_pc=0x0c0c32bcu; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0c32be;
P_0c0c32be: /* original 03dc, guest PC 0x0c0c32be */
if(!s->budget--) { s->failed_pc=0x0c0c32beu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c32c0;
P_0c0c32c0: /* original 7001, guest PC 0x0c0c32c0 */
if(!s->budget--) { s->failed_pc=0x0c0c32c0u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c32c2;
P_0c0c32c2: /* original 0d34, guest PC 0x0c0c32c2 */
if(!s->budget--) { s->failed_pc=0x0c0c32c2u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c32c4;
P_0c0c32c4: /* original 70fe, guest PC 0x0c0c32c4 */
if(!s->budget--) { s->failed_pc=0x0c0c32c4u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0c32c6;
P_0c0c32c6: /* original 02dc, guest PC 0x0c0c32c6 */
if(!s->budget--) { s->failed_pc=0x0c0c32c6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c32c8;
P_0c0c32c8: /* original 7001, guest PC 0x0c0c32c8 */
if(!s->budget--) { s->failed_pc=0x0c0c32c8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c32ca;
P_0c0c32ca: /* original 0d24, guest PC 0x0c0c32ca */
if(!s->budget--) { s->failed_pc=0x0c0c32cau; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0c32cc;
P_0c0c32cc: /* original 70fe, guest PC 0x0c0c32cc */
if(!s->budget--) { s->failed_pc=0x0c0c32ccu; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0c32ce;
P_0c0c32ce: /* original 03dc, guest PC 0x0c0c32ce */
if(!s->budget--) { s->failed_pc=0x0c0c32ceu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c32d0;
P_0c0c32d0: /* original 7001, guest PC 0x0c0c32d0 */
if(!s->budget--) { s->failed_pc=0x0c0c32d0u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c32d2;
P_0c0c32d2: /* original 0d34, guest PC 0x0c0c32d2 */
if(!s->budget--) { s->failed_pc=0x0c0c32d2u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c32d4;
P_0c0c32d4: /* original 70fe, guest PC 0x0c0c32d4 */
if(!s->budget--) { s->failed_pc=0x0c0c32d4u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0c32d6;
P_0c0c32d6: /* original 02dc, guest PC 0x0c0c32d6 */
if(!s->budget--) { s->failed_pc=0x0c0c32d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c32d8;
P_0c0c32d8: /* original 7001, guest PC 0x0c0c32d8 */
if(!s->budget--) { s->failed_pc=0x0c0c32d8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c32da;
P_0c0c32da: /* original 0d24, guest PC 0x0c0c32da */
if(!s->budget--) { s->failed_pc=0x0c0c32dau; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0c32dc;
P_0c0c32dc: /* original 70fe, guest PC 0x0c0c32dc */
if(!s->budget--) { s->failed_pc=0x0c0c32dcu; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0c32de;
P_0c0c32de: /* original 03dc, guest PC 0x0c0c32de */
if(!s->budget--) { s->failed_pc=0x0c0c32deu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c32e0;
P_0c0c32e0: /* original 7001, guest PC 0x0c0c32e0 */
if(!s->budget--) { s->failed_pc=0x0c0c32e0u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c32e2;
P_0c0c32e2: /* original 0d34, guest PC 0x0c0c32e2 */
if(!s->budget--) { s->failed_pc=0x0c0c32e2u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c32e4;
P_0c0c32e4: /* original e061, guest PC 0x0c0c32e4 */
if(!s->budget--) { s->failed_pc=0x0c0c32e4u; return 0; }
r[0]=0x00000061u;
goto P_0c0c32e6;
P_0c0c32e6: /* original 02bc, guest PC 0x0c0c32e6 */
if(!s->budget--) { s->failed_pc=0x0c0c32e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c32e8;
P_0c0c32e8: /* original 901b, guest PC 0x0c0c32e8 */
if(!s->budget--) { s->failed_pc=0x0c0c32e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3322u,2);
goto P_0c0c32ea;
P_0c0c32ea: /* original 0d24, guest PC 0x0c0c32ea */
if(!s->budget--) { s->failed_pc=0x0c0c32eau; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0c32ec;
P_0c0c32ec: /* original d315, guest PC 0x0c0c32ec */
if(!s->budget--) { s->failed_pc=0x0c0c32ecu; return 0; }
r[3]=read(ram,0x0c0c3344u,4);
goto P_0c0c32ee;
P_0c0c32ee: /* original 430b, guest PC 0x0c0c32ee */
if(!s->budget--) { s->failed_pc=0x0c0c32eeu; return 0; }
target=r[3];
r[16]=0x0c0c32f2u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c32f2u) { target=s->pc; goto dispatch; }
goto P_0c0c32f2;
P_0c0c32f0: /* original 64b3, guest PC 0x0c0c32f0 */
if(!s->budget--) { s->failed_pc=0x0c0c32f0u; return 0; }
r[4]=r[11];
goto P_0c0c32f2;
P_0c0c32f2: /* original 9217, guest PC 0x0c0c32f2 */
if(!s->budget--) { s->failed_pc=0x0c0c32f2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3324u,2);
goto P_0c0c32f4;
P_0c0c32f4: /* original 54db, guest PC 0x0c0c32f4 */
if(!s->budget--) { s->failed_pc=0x0c0c32f4u; return 0; }
r[4]=read(ram,r[13]+44,4);
goto P_0c0c32f6;
P_0c0c32f6: /* original 3427, guest PC 0x0c0c32f6 */
if(!s->budget--) { s->failed_pc=0x0c0c32f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c0c32f8;
P_0c0c32f8: /* original 8d5a, guest PC 0x0c0c32f8 */
if(!s->budget--) { s->failed_pc=0x0c0c32f8u; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(cond) { goto P_0c0c33b0; }
goto P_0c0c32fc;
P_0c0c32fa: /* original e800, guest PC 0x0c0c32fa */
if(!s->budget--) { s->failed_pc=0x0c0c32fau; return 0; }
r[8]=0x00000000u;
goto P_0c0c32fc;
P_0c0c32fc: /* original 50f4, guest PC 0x0c0c32fc */
if(!s->budget--) { s->failed_pc=0x0c0c32fcu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c32fe;
P_0c0c32fe: /* original c820, guest PC 0x0c0c32fe */
if(!s->budget--) { s->failed_pc=0x0c0c32feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0c3300;
P_0c0c3300: /* original 8924, guest PC 0x0c0c3300 */
if(!s->budget--) { s->failed_pc=0x0c0c3300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c334c; }
goto P_0c0c3302;
P_0c0c3302: /* original 63f2, guest PC 0x0c0c3302 */
if(!s->budget--) { s->failed_pc=0x0c0c3302u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c3304;
P_0c0c3304: /* original e06c, guest PC 0x0c0c3304 */
if(!s->budget--) { s->failed_pc=0x0c0c3304u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c3306;
P_0c0c3306: /* original e101, guest PC 0x0c0c3306 */
if(!s->budget--) { s->failed_pc=0x0c0c3306u; return 0; }
r[1]=0x00000001u;
goto P_0c0c3308;
P_0c0c3308: /* original 73ff, guest PC 0x0c0c3308 */
if(!s->budget--) { s->failed_pc=0x0c0c3308u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0c330a;
P_0c0c330a: /* original 2319, guest PC 0x0c0c330a */
if(!s->budget--) { s->failed_pc=0x0c0c330au; return 0; }
r[3]&=r[1];
goto P_0c0c330c;
P_0c0c330c: /* original 2f32, guest PC 0x0c0c330c */
if(!s->budget--) { s->failed_pc=0x0c0c330cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c330e;
P_0c0c330e: /* original 00ee, guest PC 0x0c0c330e */
if(!s->budget--) { s->failed_pc=0x0c0c330eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c3310;
P_0c0c3310: /* original 8801, guest PC 0x0c0c3310 */
if(!s->budget--) { s->failed_pc=0x0c0c3310u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c3312;
P_0c0c3312: /* original 8b19, guest PC 0x0c0c3312 */
if(!s->budget--) { s->failed_pc=0x0c0c3312u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3348; }
goto P_0c0c3314;
P_0c0c3314: /* original e06c, guest PC 0x0c0c3314 */
if(!s->budget--) { s->failed_pc=0x0c0c3314u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c3316;
P_0c0c3316: /* original e102, guest PC 0x0c0c3316 */
if(!s->budget--) { s->failed_pc=0x0c0c3316u; return 0; }
r[1]=0x00000002u;
goto P_0c0c3318;
P_0c0c3318: /* original a018, guest PC 0x0c0c3318 */
if(!s->budget--) { s->failed_pc=0x0c0c3318u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0c334c;
P_0c0c331a: /* original 0e16, guest PC 0x0c0c331a */
if(!s->budget--) { s->failed_pc=0x0c0c331au; return 0; }
write(ram,r[14]+r[0],r[1],4);
return vf3_matrix_family(0x0c0c331cu,s,ram);
P_0c0c3348: /* original e06c, guest PC 0x0c0c3348 */
if(!s->budget--) { s->failed_pc=0x0c0c3348u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c334a;
P_0c0c334a: /* original 0e86, guest PC 0x0c0c334a */
if(!s->budget--) { s->failed_pc=0x0c0c334au; return 0; }
write(ram,r[14]+r[0],r[8],4);
goto P_0c0c334c;
P_0c0c334c: /* original 50f4, guest PC 0x0c0c334c */
if(!s->budget--) { s->failed_pc=0x0c0c334cu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c334e;
P_0c0c334e: /* original c810, guest PC 0x0c0c334e */
if(!s->budget--) { s->failed_pc=0x0c0c334eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0c3350;
P_0c0c3350: /* original 8906, guest PC 0x0c0c3350 */
if(!s->budget--) { s->failed_pc=0x0c0c3350u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3360; }
goto P_0c0c3352;
P_0c0c3352: /* original 62f2, guest PC 0x0c0c3352 */
if(!s->budget--) { s->failed_pc=0x0c0c3352u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c3354;
P_0c0c3354: /* original e301, guest PC 0x0c0c3354 */
if(!s->budget--) { s->failed_pc=0x0c0c3354u; return 0; }
r[3]=0x00000001u;
goto P_0c0c3356;
P_0c0c3356: /* original e06c, guest PC 0x0c0c3356 */
if(!s->budget--) { s->failed_pc=0x0c0c3356u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c3358;
P_0c0c3358: /* original 7201, guest PC 0x0c0c3358 */
if(!s->budget--) { s->failed_pc=0x0c0c3358u; return 0; }
r[2]+=0x00000001u;
goto P_0c0c335a;
P_0c0c335a: /* original 2239, guest PC 0x0c0c335a */
if(!s->budget--) { s->failed_pc=0x0c0c335au; return 0; }
r[2]&=r[3];
goto P_0c0c335c;
P_0c0c335c: /* original 2f22, guest PC 0x0c0c335c */
if(!s->budget--) { s->failed_pc=0x0c0c335cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c335e;
P_0c0c335e: /* original 0e36, guest PC 0x0c0c335e */
if(!s->budget--) { s->failed_pc=0x0c0c335eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c3360;
P_0c0c3360: /* original 50f4, guest PC 0x0c0c3360 */
if(!s->budget--) { s->failed_pc=0x0c0c3360u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c3362;
P_0c0c3362: /* original c840, guest PC 0x0c0c3362 */
if(!s->budget--) { s->failed_pc=0x0c0c3362u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0c3364;
P_0c0c3364: /* original 890e, guest PC 0x0c0c3364 */
if(!s->budget--) { s->failed_pc=0x0c0c3364u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3384; }
goto P_0c0c3366;
P_0c0c3366: /* original e205, guest PC 0x0c0c3366 */
if(!s->budget--) { s->failed_pc=0x0c0c3366u; return 0; }
r[2]=0x00000005u;
goto P_0c0c3368;
P_0c0c3368: /* original 7c01, guest PC 0x0c0c3368 */
if(!s->budget--) { s->failed_pc=0x0c0c3368u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c336a;
P_0c0c336a: /* original 3c27, guest PC 0x0c0c336a */
if(!s->budget--) { s->failed_pc=0x0c0c336au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[2])!=0);
goto P_0c0c336c;
P_0c0c336c: /* original 8f01, guest PC 0x0c0c336c */
if(!s->budget--) { s->failed_pc=0x0c0c336cu; return 0; }
cond=r[17]&1u;
r[0]=0x0000006cu;
if(!cond) { goto P_0c0c3372; }
goto P_0c0c3370;
P_0c0c336e: /* original e06c, guest PC 0x0c0c336e */
if(!s->budget--) { s->failed_pc=0x0c0c336eu; return 0; }
r[0]=0x0000006cu;
goto P_0c0c3370;
P_0c0c3370: /* original 6c83, guest PC 0x0c0c3370 */
if(!s->budget--) { s->failed_pc=0x0c0c3370u; return 0; }
r[12]=r[8];
goto P_0c0c3372;
P_0c0c3372: /* original 00ee, guest PC 0x0c0c3372 */
if(!s->budget--) { s->failed_pc=0x0c0c3372u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c3374;
P_0c0c3374: /* original 8802, guest PC 0x0c0c3374 */
if(!s->budget--) { s->failed_pc=0x0c0c3374u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c3376;
P_0c0c3376: /* original 8b03, guest PC 0x0c0c3376 */
if(!s->budget--) { s->failed_pc=0x0c0c3376u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3380; }
goto P_0c0c3378;
P_0c0c3378: /* original e06c, guest PC 0x0c0c3378 */
if(!s->budget--) { s->failed_pc=0x0c0c3378u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c337a;
P_0c0c337a: /* original e203, guest PC 0x0c0c337a */
if(!s->budget--) { s->failed_pc=0x0c0c337au; return 0; }
r[2]=0x00000003u;
goto P_0c0c337c;
P_0c0c337c: /* original a002, guest PC 0x0c0c337c */
if(!s->budget--) { s->failed_pc=0x0c0c337cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c3384;
P_0c0c337e: /* original 0e26, guest PC 0x0c0c337e */
if(!s->budget--) { s->failed_pc=0x0c0c337eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c3380;
P_0c0c3380: /* original e06c, guest PC 0x0c0c3380 */
if(!s->budget--) { s->failed_pc=0x0c0c3380u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c3382;
P_0c0c3382: /* original 0e86, guest PC 0x0c0c3382 */
if(!s->budget--) { s->failed_pc=0x0c0c3382u; return 0; }
write(ram,r[14]+r[0],r[8],4);
goto P_0c0c3384;
P_0c0c3384: /* original 50f4, guest PC 0x0c0c3384 */
if(!s->budget--) { s->failed_pc=0x0c0c3384u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c3386;
P_0c0c3386: /* original c880, guest PC 0x0c0c3386 */
if(!s->budget--) { s->failed_pc=0x0c0c3386u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0c3388;
P_0c0c3388: /* original 890d, guest PC 0x0c0c3388 */
if(!s->budget--) { s->failed_pc=0x0c0c3388u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c33a6; }
goto P_0c0c338a;
P_0c0c338a: /* original 7cff, guest PC 0x0c0c338a */
if(!s->budget--) { s->failed_pc=0x0c0c338au; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c338c;
P_0c0c338c: /* original 4c11, guest PC 0x0c0c338c */
if(!s->budget--) { s->failed_pc=0x0c0c338cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c0c338e;
P_0c0c338e: /* original 8d01, guest PC 0x0c0c338e */
if(!s->budget--) { s->failed_pc=0x0c0c338eu; return 0; }
cond=r[17]&1u;
r[0]=0x0000006cu;
if(cond) { goto P_0c0c3394; }
goto P_0c0c3392;
P_0c0c3390: /* original e06c, guest PC 0x0c0c3390 */
if(!s->budget--) { s->failed_pc=0x0c0c3390u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c3392;
P_0c0c3392: /* original ec05, guest PC 0x0c0c3392 */
if(!s->budget--) { s->failed_pc=0x0c0c3392u; return 0; }
r[12]=0x00000005u;
goto P_0c0c3394;
P_0c0c3394: /* original 00ee, guest PC 0x0c0c3394 */
if(!s->budget--) { s->failed_pc=0x0c0c3394u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c3396;
P_0c0c3396: /* original 8803, guest PC 0x0c0c3396 */
if(!s->budget--) { s->failed_pc=0x0c0c3396u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c3398;
P_0c0c3398: /* original 8b03, guest PC 0x0c0c3398 */
if(!s->budget--) { s->failed_pc=0x0c0c3398u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c33a2; }
goto P_0c0c339a;
P_0c0c339a: /* original e06c, guest PC 0x0c0c339a */
if(!s->budget--) { s->failed_pc=0x0c0c339au; return 0; }
r[0]=0x0000006cu;
goto P_0c0c339c;
P_0c0c339c: /* original e204, guest PC 0x0c0c339c */
if(!s->budget--) { s->failed_pc=0x0c0c339cu; return 0; }
r[2]=0x00000004u;
goto P_0c0c339e;
P_0c0c339e: /* original a002, guest PC 0x0c0c339e */
if(!s->budget--) { s->failed_pc=0x0c0c339eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c33a6;
P_0c0c33a0: /* original 0e26, guest PC 0x0c0c33a0 */
if(!s->budget--) { s->failed_pc=0x0c0c33a0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c33a2;
P_0c0c33a2: /* original e06c, guest PC 0x0c0c33a2 */
if(!s->budget--) { s->failed_pc=0x0c0c33a2u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c33a4;
P_0c0c33a4: /* original 0e86, guest PC 0x0c0c33a4 */
if(!s->budget--) { s->failed_pc=0x0c0c33a4u; return 0; }
write(ram,r[14]+r[0],r[8],4);
goto P_0c0c33a6;
P_0c0c33a6: /* original 63f2, guest PC 0x0c0c33a6 */
if(!s->budget--) { s->failed_pc=0x0c0c33a6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c33a8;
P_0c0c33a8: /* original e034, guest PC 0x0c0c33a8 */
if(!s->budget--) { s->failed_pc=0x0c0c33a8u; return 0; }
r[0]=0x00000034u;
goto P_0c0c33aa;
P_0c0c33aa: /* original 0e34, guest PC 0x0c0c33aa */
if(!s->budget--) { s->failed_pc=0x0c0c33aau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c33ac;
P_0c0c33ac: /* original e035, guest PC 0x0c0c33ac */
if(!s->budget--) { s->failed_pc=0x0c0c33acu; return 0; }
r[0]=0x00000035u;
goto P_0c0c33ae;
P_0c0c33ae: /* original 0ec4, guest PC 0x0c0c33ae */
if(!s->budget--) { s->failed_pc=0x0c0c33aeu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c33b0;
P_0c0c33b0: /* original 63f2, guest PC 0x0c0c33b0 */
if(!s->budget--) { s->failed_pc=0x0c0c33b0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c33b2;
P_0c0c33b2: /* original d019, guest PC 0x0c0c33b2 */
if(!s->budget--) { s->failed_pc=0x0c0c33b2u; return 0; }
r[0]=read(ram,0x0c0c3418u,4);
goto P_0c0c33b4;
P_0c0c33b4: /* original 6233, guest PC 0x0c0c33b4 */
if(!s->budget--) { s->failed_pc=0x0c0c33b4u; return 0; }
r[2]=r[3];
goto P_0c0c33b6;
P_0c0c33b6: /* original 4308, guest PC 0x0c0c33b6 */
if(!s->budget--) { s->failed_pc=0x0c0c33b6u; return 0; }
r[3]<<=2;
goto P_0c0c33b8;
P_0c0c33b8: /* original 4300, guest PC 0x0c0c33b8 */
if(!s->budget--) { s->failed_pc=0x0c0c33b8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c33ba;
P_0c0c33ba: /* original 3328, guest PC 0x0c0c33ba */
if(!s->budget--) { s->failed_pc=0x0c0c33bau; return 0; }
r[3]-=r[2];
goto P_0c0c33bc;
P_0c0c33bc: /* original 33cc, guest PC 0x0c0c33bc */
if(!s->budget--) { s->failed_pc=0x0c0c33bcu; return 0; }
r[3]+=r[12];
goto P_0c0c33be;
P_0c0c33be: /* original 0c3c, guest PC 0x0c0c33be */
if(!s->budget--) { s->failed_pc=0x0c0c33beu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0c33c0;
P_0c0c33c0: /* original 84e4, guest PC 0x0c0c33c0 */
if(!s->budget--) { s->failed_pc=0x0c0c33c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c33c2;
P_0c0c33c2: /* original 2008, guest PC 0x0c0c33c2 */
if(!s->budget--) { s->failed_pc=0x0c0c33c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c33c4;
P_0c0c33c4: /* original 8b01, guest PC 0x0c0c33c4 */
if(!s->budget--) { s->failed_pc=0x0c0c33c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c33ca; }
goto P_0c0c33c6;
P_0c0c33c6: /* original a001, guest PC 0x0c0c33c6 */
if(!s->budget--) { s->failed_pc=0x0c0c33c6u; return 0; }
r[4]=0x00000000u;
goto P_0c0c33cc;
P_0c0c33c8: /* original e400, guest PC 0x0c0c33c8 */
if(!s->budget--) { s->failed_pc=0x0c0c33c8u; return 0; }
r[4]=0x00000000u;
goto P_0c0c33ca;
P_0c0c33ca: /* original e401, guest PC 0x0c0c33ca */
if(!s->budget--) { s->failed_pc=0x0c0c33cau; return 0; }
r[4]=0x00000001u;
goto P_0c0c33cc;
P_0c0c33cc: /* original d213, guest PC 0x0c0c33cc */
if(!s->budget--) { s->failed_pc=0x0c0c33ccu; return 0; }
r[2]=read(ram,0x0c0c341cu,4);
goto P_0c0c33ce;
P_0c0c33ce: /* original 420b, guest PC 0x0c0c33ce */
if(!s->budget--) { s->failed_pc=0x0c0c33ceu; return 0; }
target=r[2];
r[16]=0x0c0c33d2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c33d2u) { target=s->pc; goto dispatch; }
goto P_0c0c33d2;
P_0c0c33d0: /* original 0009, guest PC 0x0c0c33d0 */
if(!s->budget--) { s->failed_pc=0x0c0c33d0u; return 0; }
goto P_0c0c33d2;
P_0c0c33d2: /* original 6403, guest PC 0x0c0c33d2 */
if(!s->budget--) { s->failed_pc=0x0c0c33d2u; return 0; }
r[4]=r[0];
goto P_0c0c33d4;
P_0c0c33d4: /* original e06c, guest PC 0x0c0c33d4 */
if(!s->budget--) { s->failed_pc=0x0c0c33d4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c33d6;
P_0c0c33d6: /* original 00ee, guest PC 0x0c0c33d6 */
if(!s->budget--) { s->failed_pc=0x0c0c33d6u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c33d8;
P_0c0c33d8: /* original 8804, guest PC 0x0c0c33d8 */
if(!s->budget--) { s->failed_pc=0x0c0c33d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c33da;
P_0c0c33da: /* original 8b05, guest PC 0x0c0c33da */
if(!s->budget--) { s->failed_pc=0x0c0c33dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c33e8; }
goto P_0c0c33dc;
P_0c0c33dc: /* original 5042, guest PC 0x0c0c33dc */
if(!s->budget--) { s->failed_pc=0x0c0c33dcu; return 0; }
r[0]=read(ram,r[4]+8,4);
goto P_0c0c33de;
P_0c0c33de: /* original c808, guest PC 0x0c0c33de */
if(!s->budget--) { s->failed_pc=0x0c0c33deu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0c33e0;
P_0c0c33e0: /* original 8902, guest PC 0x0c0c33e0 */
if(!s->budget--) { s->failed_pc=0x0c0c33e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c33e8; }
goto P_0c0c33e2;
P_0c0c33e2: /* original e06c, guest PC 0x0c0c33e2 */
if(!s->budget--) { s->failed_pc=0x0c0c33e2u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c33e4;
P_0c0c33e4: /* original e305, guest PC 0x0c0c33e4 */
if(!s->budget--) { s->failed_pc=0x0c0c33e4u; return 0; }
r[3]=0x00000005u;
goto P_0c0c33e6;
P_0c0c33e6: /* original 0e36, guest PC 0x0c0c33e6 */
if(!s->budget--) { s->failed_pc=0x0c0c33e6u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c33e8;
P_0c0c33e8: /* original e061, guest PC 0x0c0c33e8 */
if(!s->budget--) { s->failed_pc=0x0c0c33e8u; return 0; }
r[0]=0x00000061u;
goto P_0c0c33ea;
P_0c0c33ea: /* original 0bc4, guest PC 0x0c0c33ea */
if(!s->budget--) { s->failed_pc=0x0c0c33eau; return 0; }
write(ram,r[11]+r[0],r[12],1);
goto P_0c0c33ec;
P_0c0c33ec: /* original 84e4, guest PC 0x0c0c33ec */
if(!s->budget--) { s->failed_pc=0x0c0c33ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c33ee;
P_0c0c33ee: /* original 2008, guest PC 0x0c0c33ee */
if(!s->budget--) { s->failed_pc=0x0c0c33eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c33f0;
P_0c0c33f0: /* original 8900, guest PC 0x0c0c33f0 */
if(!s->budget--) { s->failed_pc=0x0c0c33f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c33f4; }
goto P_0c0c33f2;
P_0c0c33f2: /* original 7c0d, guest PC 0x0c0c33f2 */
if(!s->budget--) { s->failed_pc=0x0c0c33f2u; return 0; }
r[12]+=0x0000000du;
goto P_0c0c33f4;
P_0c0c33f4: /* original 900f, guest PC 0x0c0c33f4 */
if(!s->budget--) { s->failed_pc=0x0c0c33f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3416u,2);
goto P_0c0c33f6;
P_0c0c33f6: /* original 04ac, guest PC 0x0c0c33f6 */
if(!s->budget--) { s->failed_pc=0x0c0c33f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0c33f8;
P_0c0c33f8: /* original 604c, guest PC 0x0c0c33f8 */
if(!s->budget--) { s->failed_pc=0x0c0c33f8u; return 0; }
r[0]=r[4]&255u;
goto P_0c0c33fa;
P_0c0c33fa: /* original 8803, guest PC 0x0c0c33fa */
if(!s->budget--) { s->failed_pc=0x0c0c33fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c33fc;
P_0c0c33fc: /* original 8f17, guest PC 0x0c0c33fc */
if(!s->budget--) { s->failed_pc=0x0c0c33fcu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c342e; }
goto P_0c0c3400;
P_0c0c33fe: /* original 6403, guest PC 0x0c0c33fe */
if(!s->budget--) { s->failed_pc=0x0c0c33feu; return 0; }
r[4]=r[0];
goto P_0c0c3400;
P_0c0c3400: /* original 84e4, guest PC 0x0c0c3400 */
if(!s->budget--) { s->failed_pc=0x0c0c3400u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3402;
P_0c0c3402: /* original 2008, guest PC 0x0c0c3402 */
if(!s->budget--) { s->failed_pc=0x0c0c3402u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c3404;
P_0c0c3404: /* original 8b0c, guest PC 0x0c0c3404 */
if(!s->budget--) { s->failed_pc=0x0c0c3404u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3420; }
goto P_0c0c3406;
P_0c0c3406: /* original 52f5, guest PC 0x0c0c3406 */
if(!s->budget--) { s->failed_pc=0x0c0c3406u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0c3408;
P_0c0c3408: /* original e060, guest PC 0x0c0c3408 */
if(!s->budget--) { s->failed_pc=0x0c0c3408u; return 0; }
r[0]=0x00000060u;
goto P_0c0c340a;
P_0c0c340a: /* original 032c, guest PC 0x0c0c340a */
if(!s->budget--) { s->failed_pc=0x0c0c340au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0c340c;
P_0c0c340c: /* original 633c, guest PC 0x0c0c340c */
if(!s->budget--) { s->failed_pc=0x0c0c340cu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c340e;
P_0c0c340e: /* original 33c0, guest PC 0x0c0c340e */
if(!s->budget--) { s->failed_pc=0x0c0c340eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[12])!=0);
goto P_0c0c3410;
P_0c0c3410: /* original 8b0d, guest PC 0x0c0c3410 */
if(!s->budget--) { s->failed_pc=0x0c0c3410u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c342e; }
goto P_0c0c3412;
P_0c0c3412: /* original a00c, guest PC 0x0c0c3412 */
if(!s->budget--) { s->failed_pc=0x0c0c3412u; return 0; }
r[12]+=0x0000000du;
goto P_0c0c342e;
P_0c0c3414: /* original 7c0d, guest PC 0x0c0c3414 */
if(!s->budget--) { s->failed_pc=0x0c0c3414u; return 0; }
r[12]+=0x0000000du;
return vf3_matrix_family(0x0c0c3416u,s,ram);
P_0c0c3420: /* original 53f5, guest PC 0x0c0c3420 */
if(!s->budget--) { s->failed_pc=0x0c0c3420u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0c3422;
P_0c0c3422: /* original e060, guest PC 0x0c0c3422 */
if(!s->budget--) { s->failed_pc=0x0c0c3422u; return 0; }
r[0]=0x00000060u;
goto P_0c0c3424;
P_0c0c3424: /* original 023c, guest PC 0x0c0c3424 */
if(!s->budget--) { s->failed_pc=0x0c0c3424u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0c3426;
P_0c0c3426: /* original 622c, guest PC 0x0c0c3426 */
if(!s->budget--) { s->failed_pc=0x0c0c3426u; return 0; }
r[2]=r[2]&255u;
goto P_0c0c3428;
P_0c0c3428: /* original 32c0, guest PC 0x0c0c3428 */
if(!s->budget--) { s->failed_pc=0x0c0c3428u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[12])!=0);
goto P_0c0c342a;
P_0c0c342a: /* original 8b00, guest PC 0x0c0c342a */
if(!s->budget--) { s->failed_pc=0x0c0c342au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c342e; }
goto P_0c0c342c;
P_0c0c342c: /* original 7cf3, guest PC 0x0c0c342c */
if(!s->budget--) { s->failed_pc=0x0c0c342cu; return 0; }
r[12]+=0xfffffff3u;
goto P_0c0c342e;
P_0c0c342e: /* original 54d2, guest PC 0x0c0c342e */
if(!s->budget--) { s->failed_pc=0x0c0c342eu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0c3430;
P_0c0c3430: /* original e204, guest PC 0x0c0c3430 */
if(!s->budget--) { s->failed_pc=0x0c0c3430u; return 0; }
r[2]=0x00000004u;
goto P_0c0c3432;
P_0c0c3432: /* original 2428, guest PC 0x0c0c3432 */
if(!s->budget--) { s->failed_pc=0x0c0c3432u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0c3434;
P_0c0c3434: /* original 891a, guest PC 0x0c0c3434 */
if(!s->budget--) { s->failed_pc=0x0c0c3434u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c346c; }
goto P_0c0c3436;
P_0c0c3436: /* original 84e4, guest PC 0x0c0c3436 */
if(!s->budget--) { s->failed_pc=0x0c0c3436u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3438;
P_0c0c3438: /* original d438, guest PC 0x0c0c3438 */
if(!s->budget--) { s->failed_pc=0x0c0c3438u; return 0; }
r[4]=read(ram,0x0c0c351cu,4);
goto P_0c0c343a;
P_0c0c343a: /* original 6603, guest PC 0x0c0c343a */
if(!s->budget--) { s->failed_pc=0x0c0c343au; return 0; }
r[6]=r[0];
goto P_0c0c343c;
P_0c0c343c: /* original e061, guest PC 0x0c0c343c */
if(!s->budget--) { s->failed_pc=0x0c0c343cu; return 0; }
r[0]=0x00000061u;
goto P_0c0c343e;
P_0c0c343e: /* original 07bc, guest PC 0x0c0c343e */
if(!s->budget--) { s->failed_pc=0x0c0c343eu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c3440;
P_0c0c3440: /* original 7037, guest PC 0x0c0c3440 */
if(!s->budget--) { s->failed_pc=0x0c0c3440u; return 0; }
r[0]+=0x00000037u;
goto P_0c0c3442;
P_0c0c3442: /* original 666c, guest PC 0x0c0c3442 */
if(!s->budget--) { s->failed_pc=0x0c0c3442u; return 0; }
r[6]=r[6]&255u;
goto P_0c0c3444;
P_0c0c3444: /* original 05ae, guest PC 0x0c0c3444 */
if(!s->budget--) { s->failed_pc=0x0c0c3444u; return 0; }
r[5]=read(ram,r[10]+r[0],4);
goto P_0c0c3446;
P_0c0c3446: /* original 677c, guest PC 0x0c0c3446 */
if(!s->budget--) { s->failed_pc=0x0c0c3446u; return 0; }
r[7]=r[7]&255u;
goto P_0c0c3448;
P_0c0c3448: /* original 677b, guest PC 0x0c0c3448 */
if(!s->budget--) { s->failed_pc=0x0c0c3448u; return 0; }
r[7]=0u-r[7];
goto P_0c0c344a;
P_0c0c344a: /* original 2668, guest PC 0x0c0c344a */
if(!s->budget--) { s->failed_pc=0x0c0c344au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c344c;
P_0c0c344c: /* original 447d, guest PC 0x0c0c344c */
if(!s->budget--) { s->failed_pc=0x0c0c344cu; return 0; }
r[4]=(r[7]&0x80000000u)?((r[7]&31u)?r[4]>>((-r[7])&31u):0):r[4]<<(r[7]&31u);
goto P_0c0c344e;
P_0c0c344e: /* original 8f07, guest PC 0x0c0c344e */
if(!s->budget--) { s->failed_pc=0x0c0c344eu; return 0; }
cond=r[17]&1u;
r[4]&=r[5];
if(!cond) { goto P_0c0c3460; }
goto P_0c0c3452;
P_0c0c3450: /* original 2459, guest PC 0x0c0c3450 */
if(!s->budget--) { s->failed_pc=0x0c0c3450u; return 0; }
r[4]&=r[5];
goto P_0c0c3452;
P_0c0c3452: /* original 2448, guest PC 0x0c0c3452 */
if(!s->budget--) { s->failed_pc=0x0c0c3452u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3454;
P_0c0c3454: /* original 890a, guest PC 0x0c0c3454 */
if(!s->budget--) { s->failed_pc=0x0c0c3454u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c346c; }
goto P_0c0c3456;
P_0c0c3456: /* original e30d, guest PC 0x0c0c3456 */
if(!s->budget--) { s->failed_pc=0x0c0c3456u; return 0; }
r[3]=0x0000000du;
goto P_0c0c3458;
P_0c0c3458: /* original 3c32, guest PC 0x0c0c3458 */
if(!s->budget--) { s->failed_pc=0x0c0c3458u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[3])!=0);
goto P_0c0c345a;
P_0c0c345a: /* original 8907, guest PC 0x0c0c345a */
if(!s->budget--) { s->failed_pc=0x0c0c345au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c346c; }
goto P_0c0c345c;
P_0c0c345c: /* original a006, guest PC 0x0c0c345c */
if(!s->budget--) { s->failed_pc=0x0c0c345cu; return 0; }
r[12]+=0x0000000du;
goto P_0c0c346c;
P_0c0c345e: /* original 7c0d, guest PC 0x0c0c345e */
if(!s->budget--) { s->failed_pc=0x0c0c345eu; return 0; }
r[12]+=0x0000000du;
goto P_0c0c3460;
P_0c0c3460: /* original 2448, guest PC 0x0c0c3460 */
if(!s->budget--) { s->failed_pc=0x0c0c3460u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3462;
P_0c0c3462: /* original 8903, guest PC 0x0c0c3462 */
if(!s->budget--) { s->failed_pc=0x0c0c3462u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c346c; }
goto P_0c0c3464;
P_0c0c3464: /* original e30d, guest PC 0x0c0c3464 */
if(!s->budget--) { s->failed_pc=0x0c0c3464u; return 0; }
r[3]=0x0000000du;
goto P_0c0c3466;
P_0c0c3466: /* original 3c32, guest PC 0x0c0c3466 */
if(!s->budget--) { s->failed_pc=0x0c0c3466u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[3])!=0);
goto P_0c0c3468;
P_0c0c3468: /* original 8b00, guest PC 0x0c0c3468 */
if(!s->budget--) { s->failed_pc=0x0c0c3468u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c346c; }
goto P_0c0c346a;
P_0c0c346a: /* original 7cf3, guest PC 0x0c0c346a */
if(!s->budget--) { s->failed_pc=0x0c0c346au; return 0; }
r[12]+=0xfffffff3u;
goto P_0c0c346c;
P_0c0c346c: /* original e032, guest PC 0x0c0c346c */
if(!s->budget--) { s->failed_pc=0x0c0c346cu; return 0; }
r[0]=0x00000032u;
goto P_0c0c346e;
P_0c0c346e: /* original 04ec, guest PC 0x0c0c346e */
if(!s->budget--) { s->failed_pc=0x0c0c346eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3470;
P_0c0c3470: /* original 644c, guest PC 0x0c0c3470 */
if(!s->budget--) { s->failed_pc=0x0c0c3470u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c3472;
P_0c0c3472: /* original 3c40, guest PC 0x0c0c3472 */
if(!s->budget--) { s->failed_pc=0x0c0c3472u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[4])!=0);
goto P_0c0c3474;
P_0c0c3474: /* original 8b03, guest PC 0x0c0c3474 */
if(!s->budget--) { s->failed_pc=0x0c0c3474u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c347e; }
goto P_0c0c3476;
P_0c0c3476: /* original e06c, guest PC 0x0c0c3476 */
if(!s->budget--) { s->failed_pc=0x0c0c3476u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c3478;
P_0c0c3478: /* original 00ee, guest PC 0x0c0c3478 */
if(!s->budget--) { s->failed_pc=0x0c0c3478u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c347a;
P_0c0c347a: /* original 8805, guest PC 0x0c0c347a */
if(!s->budget--) { s->failed_pc=0x0c0c347au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c347c;
P_0c0c347c: /* original 8b2f, guest PC 0x0c0c347c */
if(!s->budget--) { s->failed_pc=0x0c0c347cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c34de; }
goto P_0c0c347e;
P_0c0c347e: /* original e033, guest PC 0x0c0c347e */
if(!s->budget--) { s->failed_pc=0x0c0c347eu; return 0; }
r[0]=0x00000033u;
goto P_0c0c3480;
P_0c0c3480: /* original 0e44, guest PC 0x0c0c3480 */
if(!s->budget--) { s->failed_pc=0x0c0c3480u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c3482;
P_0c0c3482: /* original e038, guest PC 0x0c0c3482 */
if(!s->budget--) { s->failed_pc=0x0c0c3482u; return 0; }
r[0]=0x00000038u;
goto P_0c0c3484;
P_0c0c3484: /* original 02ec, guest PC 0x0c0c3484 */
if(!s->budget--) { s->failed_pc=0x0c0c3484u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3486;
P_0c0c3486: /* original e301, guest PC 0x0c0c3486 */
if(!s->budget--) { s->failed_pc=0x0c0c3486u; return 0; }
r[3]=0x00000001u;
goto P_0c0c3488;
P_0c0c3488: /* original 223b, guest PC 0x0c0c3488 */
if(!s->budget--) { s->failed_pc=0x0c0c3488u; return 0; }
r[2]|=r[3];
goto P_0c0c348a;
P_0c0c348a: /* original 0e24, guest PC 0x0c0c348a */
if(!s->budget--) { s->failed_pc=0x0c0c348au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c348c;
P_0c0c348c: /* original e04c, guest PC 0x0c0c348c */
if(!s->budget--) { s->failed_pc=0x0c0c348cu; return 0; }
r[0]=0x0000004cu;
goto P_0c0c348e;
P_0c0c348e: /* original 0e85, guest PC 0x0c0c348e */
if(!s->budget--) { s->failed_pc=0x0c0c348eu; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0c3490;
P_0c0c3490: /* original e04a, guest PC 0x0c0c3490 */
if(!s->budget--) { s->failed_pc=0x0c0c3490u; return 0; }
r[0]=0x0000004au;
goto P_0c0c3492;
P_0c0c3492: /* original 0e85, guest PC 0x0c0c3492 */
if(!s->budget--) { s->failed_pc=0x0c0c3492u; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0c3494;
P_0c0c3494: /* original e044, guest PC 0x0c0c3494 */
if(!s->budget--) { s->failed_pc=0x0c0c3494u; return 0; }
r[0]=0x00000044u;
goto P_0c0c3496;
P_0c0c3496: /* original 0e85, guest PC 0x0c0c3496 */
if(!s->budget--) { s->failed_pc=0x0c0c3496u; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0c3498;
P_0c0c3498: /* original e046, guest PC 0x0c0c3498 */
if(!s->budget--) { s->failed_pc=0x0c0c3498u; return 0; }
r[0]=0x00000046u;
goto P_0c0c349a;
P_0c0c349a: /* original 0e85, guest PC 0x0c0c349a */
if(!s->budget--) { s->failed_pc=0x0c0c349au; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0c349c;
P_0c0c349c: /* original e048, guest PC 0x0c0c349c */
if(!s->budget--) { s->failed_pc=0x0c0c349cu; return 0; }
r[0]=0x00000048u;
goto P_0c0c349e;
P_0c0c349e: /* original 0e85, guest PC 0x0c0c349e */
if(!s->budget--) { s->failed_pc=0x0c0c349eu; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0c34a0;
P_0c0c34a0: /* original e04e, guest PC 0x0c0c34a0 */
if(!s->budget--) { s->failed_pc=0x0c0c34a0u; return 0; }
r[0]=0x0000004eu;
goto P_0c0c34a2;
P_0c0c34a2: /* original 9238, guest PC 0x0c0c34a2 */
if(!s->budget--) { s->failed_pc=0x0c0c34a2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3516u,2);
goto P_0c0c34a4;
P_0c0c34a4: /* original 0e25, guest PC 0x0c0c34a4 */
if(!s->budget--) { s->failed_pc=0x0c0c34a4u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0c34a6;
P_0c0c34a6: /* original e03a, guest PC 0x0c0c34a6 */
if(!s->budget--) { s->failed_pc=0x0c0c34a6u; return 0; }
r[0]=0x0000003au;
goto P_0c0c34a8;
P_0c0c34a8: /* original 0e34, guest PC 0x0c0c34a8 */
if(!s->budget--) { s->failed_pc=0x0c0c34a8u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c34aa;
P_0c0c34aa: /* original e036, guest PC 0x0c0c34aa */
if(!s->budget--) { s->failed_pc=0x0c0c34aau; return 0; }
r[0]=0x00000036u;
goto P_0c0c34ac;
P_0c0c34ac: /* original 02ec, guest PC 0x0c0c34ac */
if(!s->budget--) { s->failed_pc=0x0c0c34acu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c34ae;
P_0c0c34ae: /* original 2228, guest PC 0x0c0c34ae */
if(!s->budget--) { s->failed_pc=0x0c0c34aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c34b0;
P_0c0c34b0: /* original b25c, guest PC 0x0c0c34b0 */
if(!s->budget--) { s->failed_pc=0x0c0c34b0u; return 0; }
target=0x0c0c396cu; r[16]=0x0c0c34b4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c34b4u) { target=s->pc; goto dispatch; }
goto P_0c0c34b4;
P_0c0c34b2: /* original 64c3, guest PC 0x0c0c34b2 */
if(!s->budget--) { s->failed_pc=0x0c0c34b2u; return 0; }
r[4]=r[12];
goto P_0c0c34b4;
P_0c0c34b4: /* original 6c03, guest PC 0x0c0c34b4 */
if(!s->budget--) { s->failed_pc=0x0c0c34b4u; return 0; }
r[12]=r[0];
goto P_0c0c34b6;
P_0c0c34b6: /* original e032, guest PC 0x0c0c34b6 */
if(!s->budget--) { s->failed_pc=0x0c0c34b6u; return 0; }
r[0]=0x00000032u;
goto P_0c0c34b8;
P_0c0c34b8: /* original 0ec4, guest PC 0x0c0c34b8 */
if(!s->budget--) { s->failed_pc=0x0c0c34b8u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c34ba;
P_0c0c34ba: /* original e060, guest PC 0x0c0c34ba */
if(!s->budget--) { s->failed_pc=0x0c0c34bau; return 0; }
r[0]=0x00000060u;
goto P_0c0c34bc;
P_0c0c34bc: /* original 0bc4, guest PC 0x0c0c34bc */
if(!s->budget--) { s->failed_pc=0x0c0c34bcu; return 0; }
write(ram,r[11]+r[0],r[12],1);
goto P_0c0c34be;
P_0c0c34be: /* original e06c, guest PC 0x0c0c34be */
if(!s->budget--) { s->failed_pc=0x0c0c34beu; return 0; }
r[0]=0x0000006cu;
goto P_0c0c34c0;
P_0c0c34c0: /* original 00ee, guest PC 0x0c0c34c0 */
if(!s->budget--) { s->failed_pc=0x0c0c34c0u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c34c2;
P_0c0c34c2: /* original 8805, guest PC 0x0c0c34c2 */
if(!s->budget--) { s->failed_pc=0x0c0c34c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c34c4;
P_0c0c34c4: /* original 8b02, guest PC 0x0c0c34c4 */
if(!s->budget--) { s->failed_pc=0x0c0c34c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c34cc; }
goto P_0c0c34c6;
P_0c0c34c6: /* original e06c, guest PC 0x0c0c34c6 */
if(!s->budget--) { s->failed_pc=0x0c0c34c6u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c34c8;
P_0c0c34c8: /* original e206, guest PC 0x0c0c34c8 */
if(!s->budget--) { s->failed_pc=0x0c0c34c8u; return 0; }
r[2]=0x00000006u;
goto P_0c0c34ca;
P_0c0c34ca: /* original 0e26, guest PC 0x0c0c34ca */
if(!s->budget--) { s->failed_pc=0x0c0c34cau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c34cc;
P_0c0c34cc: /* original e036, guest PC 0x0c0c34cc */
if(!s->budget--) { s->failed_pc=0x0c0c34ccu; return 0; }
r[0]=0x00000036u;
goto P_0c0c34ce;
P_0c0c34ce: /* original e301, guest PC 0x0c0c34ce */
if(!s->budget--) { s->failed_pc=0x0c0c34ceu; return 0; }
r[3]=0x00000001u;
goto P_0c0c34d0;
P_0c0c34d0: /* original 0e34, guest PC 0x0c0c34d0 */
if(!s->budget--) { s->failed_pc=0x0c0c34d0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c34d2;
P_0c0c34d2: /* original 1e8f, guest PC 0x0c0c34d2 */
if(!s->budget--) { s->failed_pc=0x0c0c34d2u; return 0; }
write(ram,r[14]+60,r[8],4);
goto P_0c0c34d4;
P_0c0c34d4: /* original b255, guest PC 0x0c0c34d4 */
if(!s->budget--) { s->failed_pc=0x0c0c34d4u; return 0; }
target=0x0c0c3982u; r[16]=0x0c0c34d8u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c34d8u) { target=s->pc; goto dispatch; }
goto P_0c0c34d8;
P_0c0c34d6: /* original 64b3, guest PC 0x0c0c34d6 */
if(!s->budget--) { s->failed_pc=0x0c0c34d6u; return 0; }
r[4]=r[11];
goto P_0c0c34d8;
P_0c0c34d8: /* original d211, guest PC 0x0c0c34d8 */
if(!s->budget--) { s->failed_pc=0x0c0c34d8u; return 0; }
r[2]=read(ram,0x0c0c3520u,4);
goto P_0c0c34da;
P_0c0c34da: /* original 420b, guest PC 0x0c0c34da */
if(!s->budget--) { s->failed_pc=0x0c0c34dau; return 0; }
target=r[2];
r[16]=0x0c0c34deu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c34deu) { target=s->pc; goto dispatch; }
goto P_0c0c34de;
P_0c0c34dc: /* original 64b3, guest PC 0x0c0c34dc */
if(!s->budget--) { s->failed_pc=0x0c0c34dcu; return 0; }
r[4]=r[11];
goto P_0c0c34de;
P_0c0c34de: /* original 931b, guest PC 0x0c0c34de */
if(!s->budget--) { s->failed_pc=0x0c0c34deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3518u,2);
goto P_0c0c34e0;
P_0c0c34e0: /* original 54db, guest PC 0x0c0c34e0 */
if(!s->budget--) { s->failed_pc=0x0c0c34e0u; return 0; }
r[4]=read(ram,r[13]+44,4);
goto P_0c0c34e2;
P_0c0c34e2: /* original 3437, guest PC 0x0c0c34e2 */
if(!s->budget--) { s->failed_pc=0x0c0c34e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0c34e4;
P_0c0c34e4: /* original 8b01, guest PC 0x0c0c34e4 */
if(!s->budget--) { s->failed_pc=0x0c0c34e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c34ea; }
goto P_0c0c34e6;
P_0c0c34e6: /* original a1e4, guest PC 0x0c0c34e6 */
if(!s->budget--) { s->failed_pc=0x0c0c34e6u; return 0; }
goto P_0c0c38b2;
P_0c0c34e8: /* original 0009, guest PC 0x0c0c34e8 */
if(!s->budget--) { s->failed_pc=0x0c0c34e8u; return 0; }
goto P_0c0c34ea;
P_0c0c34ea: /* original 50f4, guest PC 0x0c0c34ea */
if(!s->budget--) { s->failed_pc=0x0c0c34eau; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c34ec;
P_0c0c34ec: /* original c80f, guest PC 0x0c0c34ec */
if(!s->budget--) { s->failed_pc=0x0c0c34ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&15u)==0)!=0);
goto P_0c0c34ee;
P_0c0c34ee: /* original 8920, guest PC 0x0c0c34ee */
if(!s->budget--) { s->failed_pc=0x0c0c34eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3532; }
goto P_0c0c34f0;
P_0c0c34f0: /* original e06c, guest PC 0x0c0c34f0 */
if(!s->budget--) { s->failed_pc=0x0c0c34f0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c34f2;
P_0c0c34f2: /* original 00ee, guest PC 0x0c0c34f2 */
if(!s->budget--) { s->failed_pc=0x0c0c34f2u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c34f4;
P_0c0c34f4: /* original 8806, guest PC 0x0c0c34f4 */
if(!s->budget--) { s->failed_pc=0x0c0c34f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c34f6;
P_0c0c34f6: /* original 8b3b, guest PC 0x0c0c34f6 */
if(!s->budget--) { s->failed_pc=0x0c0c34f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3570; }
goto P_0c0c34f8;
P_0c0c34f8: /* original 900f, guest PC 0x0c0c34f8 */
if(!s->budget--) { s->failed_pc=0x0c0c34f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c351au,2);
goto P_0c0c34fa;
P_0c0c34fa: /* original d30a, guest PC 0x0c0c34fa */
if(!s->budget--) { s->failed_pc=0x0c0c34fau; return 0; }
r[3]=read(ram,0x0c0c3524u,4);
goto P_0c0c34fc;
P_0c0c34fc: /* original 04ae, guest PC 0x0c0c34fc */
if(!s->budget--) { s->failed_pc=0x0c0c34fcu; return 0; }
r[4]=read(ram,r[10]+r[0],4);
goto P_0c0c34fe;
P_0c0c34fe: /* original 2438, guest PC 0x0c0c34fe */
if(!s->budget--) { s->failed_pc=0x0c0c34feu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c3500;
P_0c0c3500: /* original 8d03, guest PC 0x0c0c3500 */
if(!s->budget--) { s->failed_pc=0x0c0c3500u; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
if(cond) { goto P_0c0c350a; }
goto P_0c0c3504;
P_0c0c3502: /* original 84e4, guest PC 0x0c0c3502 */
if(!s->budget--) { s->failed_pc=0x0c0c3502u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3504;
P_0c0c3504: /* original e416, guest PC 0x0c0c3504 */
if(!s->budget--) { s->failed_pc=0x0c0c3504u; return 0; }
r[4]=0x00000016u;
goto P_0c0c3506;
P_0c0c3506: /* original a002, guest PC 0x0c0c3506 */
if(!s->budget--) { s->failed_pc=0x0c0c3506u; return 0; }
r[5]=0x00000009u;
goto P_0c0c350e;
P_0c0c3508: /* original e509, guest PC 0x0c0c3508 */
if(!s->budget--) { s->failed_pc=0x0c0c3508u; return 0; }
r[5]=0x00000009u;
goto P_0c0c350a;
P_0c0c350a: /* original e516, guest PC 0x0c0c350a */
if(!s->budget--) { s->failed_pc=0x0c0c350au; return 0; }
r[5]=0x00000016u;
goto P_0c0c350c;
P_0c0c350c: /* original e409, guest PC 0x0c0c350c */
if(!s->budget--) { s->failed_pc=0x0c0c350cu; return 0; }
r[4]=0x00000009u;
goto P_0c0c350e;
P_0c0c350e: /* original 2008, guest PC 0x0c0c350e */
if(!s->budget--) { s->failed_pc=0x0c0c350eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c3510;
P_0c0c3510: /* original 8b0a, guest PC 0x0c0c3510 */
if(!s->budget--) { s->failed_pc=0x0c0c3510u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3528; }
goto P_0c0c3512;
P_0c0c3512: /* original a00a, guest PC 0x0c0c3512 */
if(!s->budget--) { s->failed_pc=0x0c0c3512u; return 0; }
r[12]=r[4];
goto P_0c0c352a;
P_0c0c3514: /* original 6c43, guest PC 0x0c0c3514 */
if(!s->budget--) { s->failed_pc=0x0c0c3514u; return 0; }
r[12]=r[4];
return vf3_matrix_family(0x0c0c3516u,s,ram);
P_0c0c3528: /* original 6c53, guest PC 0x0c0c3528 */
if(!s->budget--) { s->failed_pc=0x0c0c3528u; return 0; }
r[12]=r[5];
goto P_0c0c352a;
P_0c0c352a: /* original e061, guest PC 0x0c0c352a */
if(!s->budget--) { s->failed_pc=0x0c0c352au; return 0; }
r[0]=0x00000061u;
goto P_0c0c352c;
P_0c0c352c: /* original e309, guest PC 0x0c0c352c */
if(!s->budget--) { s->failed_pc=0x0c0c352cu; return 0; }
r[3]=0x00000009u;
goto P_0c0c352e;
P_0c0c352e: /* original a01f, guest PC 0x0c0c352e */
if(!s->budget--) { s->failed_pc=0x0c0c352eu; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c0c3570;
P_0c0c3530: /* original 0b34, guest PC 0x0c0c3530 */
if(!s->budget--) { s->failed_pc=0x0c0c3530u; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c0c3532;
P_0c0c3532: /* original 52db, guest PC 0x0c0c3532 */
if(!s->budget--) { s->failed_pc=0x0c0c3532u; return 0; }
r[2]=read(ram,r[13]+44,4);
goto P_0c0c3534;
P_0c0c3534: /* original e13f, guest PC 0x0c0c3534 */
if(!s->budget--) { s->failed_pc=0x0c0c3534u; return 0; }
r[1]=0x0000003fu;
goto P_0c0c3536;
P_0c0c3536: /* original 3217, guest PC 0x0c0c3536 */
if(!s->budget--) { s->failed_pc=0x0c0c3536u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[1])!=0);
goto P_0c0c3538;
P_0c0c3538: /* original 8b01, guest PC 0x0c0c3538 */
if(!s->budget--) { s->failed_pc=0x0c0c3538u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c353e; }
goto P_0c0c353a;
P_0c0c353a: /* original a1ba, guest PC 0x0c0c353a */
if(!s->budget--) { s->failed_pc=0x0c0c353au; return 0; }
goto P_0c0c38b2;
P_0c0c353c: /* original 0009, guest PC 0x0c0c353c */
if(!s->budget--) { s->failed_pc=0x0c0c353cu; return 0; }
goto P_0c0c353e;
P_0c0c353e: /* original e06c, guest PC 0x0c0c353e */
if(!s->budget--) { s->failed_pc=0x0c0c353eu; return 0; }
r[0]=0x0000006cu;
goto P_0c0c3540;
P_0c0c3540: /* original 00ee, guest PC 0x0c0c3540 */
if(!s->budget--) { s->failed_pc=0x0c0c3540u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c3542;
P_0c0c3542: /* original 8806, guest PC 0x0c0c3542 */
if(!s->budget--) { s->failed_pc=0x0c0c3542u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c3544;
P_0c0c3544: /* original 8b12, guest PC 0x0c0c3544 */
if(!s->budget--) { s->failed_pc=0x0c0c3544u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c356c; }
goto P_0c0c3546;
P_0c0c3546: /* original 9059, guest PC 0x0c0c3546 */
if(!s->budget--) { s->failed_pc=0x0c0c3546u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c35fcu,2);
goto P_0c0c3548;
P_0c0c3548: /* original d32f, guest PC 0x0c0c3548 */
if(!s->budget--) { s->failed_pc=0x0c0c3548u; return 0; }
r[3]=read(ram,0x0c0c3608u,4);
goto P_0c0c354a;
P_0c0c354a: /* original 04ae, guest PC 0x0c0c354a */
if(!s->budget--) { s->failed_pc=0x0c0c354au; return 0; }
r[4]=read(ram,r[10]+r[0],4);
goto P_0c0c354c;
P_0c0c354c: /* original 2438, guest PC 0x0c0c354c */
if(!s->budget--) { s->failed_pc=0x0c0c354cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c354e;
P_0c0c354e: /* original 8d03, guest PC 0x0c0c354e */
if(!s->budget--) { s->failed_pc=0x0c0c354eu; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
if(cond) { goto P_0c0c3558; }
goto P_0c0c3552;
P_0c0c3550: /* original 84e4, guest PC 0x0c0c3550 */
if(!s->budget--) { s->failed_pc=0x0c0c3550u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3552;
P_0c0c3552: /* original e516, guest PC 0x0c0c3552 */
if(!s->budget--) { s->failed_pc=0x0c0c3552u; return 0; }
r[5]=0x00000016u;
goto P_0c0c3554;
P_0c0c3554: /* original a002, guest PC 0x0c0c3554 */
if(!s->budget--) { s->failed_pc=0x0c0c3554u; return 0; }
r[4]=0x00000009u;
goto P_0c0c355c;
P_0c0c3556: /* original e409, guest PC 0x0c0c3556 */
if(!s->budget--) { s->failed_pc=0x0c0c3556u; return 0; }
r[4]=0x00000009u;
goto P_0c0c3558;
P_0c0c3558: /* original e416, guest PC 0x0c0c3558 */
if(!s->budget--) { s->failed_pc=0x0c0c3558u; return 0; }
r[4]=0x00000016u;
goto P_0c0c355a;
P_0c0c355a: /* original e509, guest PC 0x0c0c355a */
if(!s->budget--) { s->failed_pc=0x0c0c355au; return 0; }
r[5]=0x00000009u;
goto P_0c0c355c;
P_0c0c355c: /* original 2008, guest PC 0x0c0c355c */
if(!s->budget--) { s->failed_pc=0x0c0c355cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c355e;
P_0c0c355e: /* original 8b01, guest PC 0x0c0c355e */
if(!s->budget--) { s->failed_pc=0x0c0c355eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3564; }
goto P_0c0c3560;
P_0c0c3560: /* original a001, guest PC 0x0c0c3560 */
if(!s->budget--) { s->failed_pc=0x0c0c3560u; return 0; }
r[12]=r[5];
goto P_0c0c3566;
P_0c0c3562: /* original 6c53, guest PC 0x0c0c3562 */
if(!s->budget--) { s->failed_pc=0x0c0c3562u; return 0; }
r[12]=r[5];
goto P_0c0c3564;
P_0c0c3564: /* original 6c43, guest PC 0x0c0c3564 */
if(!s->budget--) { s->failed_pc=0x0c0c3564u; return 0; }
r[12]=r[4];
goto P_0c0c3566;
P_0c0c3566: /* original e061, guest PC 0x0c0c3566 */
if(!s->budget--) { s->failed_pc=0x0c0c3566u; return 0; }
r[0]=0x00000061u;
goto P_0c0c3568;
P_0c0c3568: /* original e309, guest PC 0x0c0c3568 */
if(!s->budget--) { s->failed_pc=0x0c0c3568u; return 0; }
r[3]=0x00000009u;
goto P_0c0c356a;
P_0c0c356a: /* original 0b34, guest PC 0x0c0c356a */
if(!s->budget--) { s->failed_pc=0x0c0c356au; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c0c356c;
P_0c0c356c: /* original a002, guest PC 0x0c0c356c */
if(!s->budget--) { s->failed_pc=0x0c0c356cu; return 0; }
r[7]=r[8];
goto P_0c0c3574;
P_0c0c356e: /* original 6783, guest PC 0x0c0c356e */
if(!s->budget--) { s->failed_pc=0x0c0c356eu; return 0; }
r[7]=r[8];
goto P_0c0c3570;
P_0c0c3570: /* original 9045, guest PC 0x0c0c3570 */
if(!s->budget--) { s->failed_pc=0x0c0c3570u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c35feu,2);
goto P_0c0c3572;
P_0c0c3572: /* original 07ae, guest PC 0x0c0c3572 */
if(!s->budget--) { s->failed_pc=0x0c0c3572u; return 0; }
r[7]=read(ram,r[10]+r[0],4);
goto P_0c0c3574;
P_0c0c3574: /* original 9042, guest PC 0x0c0c3574 */
if(!s->budget--) { s->failed_pc=0x0c0c3574u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c35fcu,2);
goto P_0c0c3576;
P_0c0c3576: /* original 03ae, guest PC 0x0c0c3576 */
if(!s->budget--) { s->failed_pc=0x0c0c3576u; return 0; }
r[3]=read(ram,r[10]+r[0],4);
goto P_0c0c3578;
P_0c0c3578: /* original e061, guest PC 0x0c0c3578 */
if(!s->budget--) { s->failed_pc=0x0c0c3578u; return 0; }
r[0]=0x00000061u;
goto P_0c0c357a;
P_0c0c357a: /* original 1f32, guest PC 0x0c0c357a */
if(!s->budget--) { s->failed_pc=0x0c0c357au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c357c;
P_0c0c357c: /* original 02bc, guest PC 0x0c0c357c */
if(!s->budget--) { s->failed_pc=0x0c0c357cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c357e;
P_0c0c357e: /* original 622c, guest PC 0x0c0c357e */
if(!s->budget--) { s->failed_pc=0x0c0c357eu; return 0; }
r[2]=r[2]&255u;
goto P_0c0c3580;
P_0c0c3580: /* original 1f23, guest PC 0x0c0c3580 */
if(!s->budget--) { s->failed_pc=0x0c0c3580u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c3582;
P_0c0c3582: /* original 84e4, guest PC 0x0c0c3582 */
if(!s->budget--) { s->failed_pc=0x0c0c3582u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3584;
P_0c0c3584: /* original 2008, guest PC 0x0c0c3584 */
if(!s->budget--) { s->failed_pc=0x0c0c3584u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c3586;
P_0c0c3586: /* original 8901, guest PC 0x0c0c3586 */
if(!s->budget--) { s->failed_pc=0x0c0c3586u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c358c; }
goto P_0c0c3588;
P_0c0c3588: /* original a001, guest PC 0x0c0c3588 */
if(!s->budget--) { s->failed_pc=0x0c0c3588u; return 0; }
r[5]=0x00000020u;
goto P_0c0c358e;
P_0c0c358a: /* original e520, guest PC 0x0c0c358a */
if(!s->budget--) { s->failed_pc=0x0c0c358au; return 0; }
r[5]=0x00000020u;
goto P_0c0c358c;
P_0c0c358c: /* original e510, guest PC 0x0c0c358c */
if(!s->budget--) { s->failed_pc=0x0c0c358cu; return 0; }
r[5]=0x00000010u;
goto P_0c0c358e;
P_0c0c358e: /* original 2fc2, guest PC 0x0c0c358e */
if(!s->budget--) { s->failed_pc=0x0c0c358eu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0c3590;
P_0c0c3590: /* original 84e4, guest PC 0x0c0c3590 */
if(!s->budget--) { s->failed_pc=0x0c0c3590u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3592;
P_0c0c3592: /* original 2008, guest PC 0x0c0c3592 */
if(!s->budget--) { s->failed_pc=0x0c0c3592u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c3594;
P_0c0c3594: /* original 8b0b, guest PC 0x0c0c3594 */
if(!s->budget--) { s->failed_pc=0x0c0c3594u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c35ae; }
goto P_0c0c3596;
P_0c0c3596: /* original 9233, guest PC 0x0c0c3596 */
if(!s->budget--) { s->failed_pc=0x0c0c3596u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3600u,2);
goto P_0c0c3598;
P_0c0c3598: /* original 32dc, guest PC 0x0c0c3598 */
if(!s->budget--) { s->failed_pc=0x0c0c3598u; return 0; }
r[2]+=r[13];
goto P_0c0c359a;
P_0c0c359a: /* original 1f29, guest PC 0x0c0c359a */
if(!s->budget--) { s->failed_pc=0x0c0c359au; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c0c359c;
P_0c0c359c: /* original 9331, guest PC 0x0c0c359c */
if(!s->budget--) { s->failed_pc=0x0c0c359cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3602u,2);
goto P_0c0c359e;
P_0c0c359e: /* original 6490, guest PC 0x0c0c359e */
if(!s->budget--) { s->failed_pc=0x0c0c359eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[9],1);
r[4]=tmp;
goto P_0c0c35a0;
P_0c0c35a0: /* original 33dc, guest PC 0x0c0c35a0 */
if(!s->budget--) { s->failed_pc=0x0c0c35a0u; return 0; }
r[3]+=r[13];
goto P_0c0c35a2;
P_0c0c35a2: /* original 1f38, guest PC 0x0c0c35a2 */
if(!s->budget--) { s->failed_pc=0x0c0c35a2u; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c0c35a4;
P_0c0c35a4: /* original 644c, guest PC 0x0c0c35a4 */
if(!s->budget--) { s->failed_pc=0x0c0c35a4u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c35a6;
P_0c0c35a6: /* original 8491, guest PC 0x0c0c35a6 */
if(!s->budget--) { s->failed_pc=0x0c0c35a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+1,1);
goto P_0c0c35a8;
P_0c0c35a8: /* original 660c, guest PC 0x0c0c35a8 */
if(!s->budget--) { s->failed_pc=0x0c0c35a8u; return 0; }
r[6]=r[0]&255u;
goto P_0c0c35aa;
P_0c0c35aa: /* original a00b, guest PC 0x0c0c35aa */
if(!s->budget--) { s->failed_pc=0x0c0c35aau; return 0; }
r[3]=0x0000000du;
goto P_0c0c35c4;
P_0c0c35ac: /* original e30d, guest PC 0x0c0c35ac */
if(!s->budget--) { s->failed_pc=0x0c0c35acu; return 0; }
r[3]=0x0000000du;
goto P_0c0c35ae;
P_0c0c35ae: /* original 9128, guest PC 0x0c0c35ae */
if(!s->budget--) { s->failed_pc=0x0c0c35aeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3602u,2);
goto P_0c0c35b0;
P_0c0c35b0: /* original 31dc, guest PC 0x0c0c35b0 */
if(!s->budget--) { s->failed_pc=0x0c0c35b0u; return 0; }
r[1]+=r[13];
goto P_0c0c35b2;
P_0c0c35b2: /* original 1f19, guest PC 0x0c0c35b2 */
if(!s->budget--) { s->failed_pc=0x0c0c35b2u; return 0; }
write(ram,r[15]+36,r[1],4);
goto P_0c0c35b4;
P_0c0c35b4: /* original 9324, guest PC 0x0c0c35b4 */
if(!s->budget--) { s->failed_pc=0x0c0c35b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3600u,2);
goto P_0c0c35b6;
P_0c0c35b6: /* original 8491, guest PC 0x0c0c35b6 */
if(!s->budget--) { s->failed_pc=0x0c0c35b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+1,1);
goto P_0c0c35b8;
P_0c0c35b8: /* original 33dc, guest PC 0x0c0c35b8 */
if(!s->budget--) { s->failed_pc=0x0c0c35b8u; return 0; }
r[3]+=r[13];
goto P_0c0c35ba;
P_0c0c35ba: /* original 1f38, guest PC 0x0c0c35ba */
if(!s->budget--) { s->failed_pc=0x0c0c35bau; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c0c35bc;
P_0c0c35bc: /* original e3f3, guest PC 0x0c0c35bc */
if(!s->budget--) { s->failed_pc=0x0c0c35bcu; return 0; }
r[3]=0xfffffff3u;
goto P_0c0c35be;
P_0c0c35be: /* original 6690, guest PC 0x0c0c35be */
if(!s->budget--) { s->failed_pc=0x0c0c35beu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[9],1);
r[6]=tmp;
goto P_0c0c35c0;
P_0c0c35c0: /* original 640c, guest PC 0x0c0c35c0 */
if(!s->budget--) { s->failed_pc=0x0c0c35c0u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c35c2;
P_0c0c35c2: /* original 666c, guest PC 0x0c0c35c2 */
if(!s->budget--) { s->failed_pc=0x0c0c35c2u; return 0; }
r[6]=r[6]&255u;
goto P_0c0c35c4;
P_0c0c35c4: /* original 2758, guest PC 0x0c0c35c4 */
if(!s->budget--) { s->failed_pc=0x0c0c35c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[5])==0)!=0);
goto P_0c0c35c6;
P_0c0c35c6: /* original 1f36, guest PC 0x0c0c35c6 */
if(!s->budget--) { s->failed_pc=0x0c0c35c6u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0c35c8;
P_0c0c35c8: /* original 895d, guest PC 0x0c0c35c8 */
if(!s->budget--) { s->failed_pc=0x0c0c35c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3686; }
goto P_0c0c35ca;
P_0c0c35ca: /* original 53f3, guest PC 0x0c0c35ca */
if(!s->budget--) { s->failed_pc=0x0c0c35cau; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c35cc;
P_0c0c35cc: /* original d50f, guest PC 0x0c0c35cc */
if(!s->budget--) { s->failed_pc=0x0c0c35ccu; return 0; }
r[5]=read(ram,0x0c0c360cu,4);
goto P_0c0c35ce;
P_0c0c35ce: /* original 52f2, guest PC 0x0c0c35ce */
if(!s->budget--) { s->failed_pc=0x0c0c35ceu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c35d0;
P_0c0c35d0: /* original 633b, guest PC 0x0c0c35d0 */
if(!s->budget--) { s->failed_pc=0x0c0c35d0u; return 0; }
r[3]=0u-r[3];
goto P_0c0c35d2;
P_0c0c35d2: /* original 453d, guest PC 0x0c0c35d2 */
if(!s->budget--) { s->failed_pc=0x0c0c35d2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0c35d4;
P_0c0c35d4: /* original 2258, guest PC 0x0c0c35d4 */
if(!s->budget--) { s->failed_pc=0x0c0c35d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c35d6;
P_0c0c35d6: /* original 8b56, guest PC 0x0c0c35d6 */
if(!s->budget--) { s->failed_pc=0x0c0c35d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3686; }
goto P_0c0c35d8;
P_0c0c35d8: /* original 57d2, guest PC 0x0c0c35d8 */
if(!s->budget--) { s->failed_pc=0x0c0c35d8u; return 0; }
r[7]=read(ram,r[13]+8,4);
goto P_0c0c35da;
P_0c0c35da: /* original e304, guest PC 0x0c0c35da */
if(!s->budget--) { s->failed_pc=0x0c0c35dau; return 0; }
r[3]=0x00000004u;
goto P_0c0c35dc;
P_0c0c35dc: /* original 2738, guest PC 0x0c0c35dc */
if(!s->budget--) { s->failed_pc=0x0c0c35dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c0c35de;
P_0c0c35de: /* original 8b17, guest PC 0x0c0c35de */
if(!s->budget--) { s->failed_pc=0x0c0c35deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3610; }
goto P_0c0c35e0;
P_0c0c35e0: /* original 9010, guest PC 0x0c0c35e0 */
if(!s->budget--) { s->failed_pc=0x0c0c35e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3604u,2);
goto P_0c0c35e2;
P_0c0c35e2: /* original 00ac, guest PC 0x0c0c35e2 */
if(!s->budget--) { s->failed_pc=0x0c0c35e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0c35e4;
P_0c0c35e4: /* original 600c, guest PC 0x0c0c35e4 */
if(!s->budget--) { s->failed_pc=0x0c0c35e4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c35e6;
P_0c0c35e6: /* original 8803, guest PC 0x0c0c35e6 */
if(!s->budget--) { s->failed_pc=0x0c0c35e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c35e8;
P_0c0c35e8: /* original 8b36, guest PC 0x0c0c35e8 */
if(!s->budget--) { s->failed_pc=0x0c0c35e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3658; }
goto P_0c0c35ea;
P_0c0c35ea: /* original 54f5, guest PC 0x0c0c35ea */
if(!s->budget--) { s->failed_pc=0x0c0c35eau; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0c35ec;
P_0c0c35ec: /* original e061, guest PC 0x0c0c35ec */
if(!s->budget--) { s->failed_pc=0x0c0c35ecu; return 0; }
r[0]=0x00000061u;
goto P_0c0c35ee;
P_0c0c35ee: /* original 53f3, guest PC 0x0c0c35ee */
if(!s->budget--) { s->failed_pc=0x0c0c35eeu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c35f0;
P_0c0c35f0: /* original 044c, guest PC 0x0c0c35f0 */
if(!s->budget--) { s->failed_pc=0x0c0c35f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c35f2;
P_0c0c35f2: /* original 644c, guest PC 0x0c0c35f2 */
if(!s->budget--) { s->failed_pc=0x0c0c35f2u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c35f4;
P_0c0c35f4: /* original 3340, guest PC 0x0c0c35f4 */
if(!s->budget--) { s->failed_pc=0x0c0c35f4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c0c35f6;
P_0c0c35f6: /* original 8946, guest PC 0x0c0c35f6 */
if(!s->budget--) { s->failed_pc=0x0c0c35f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3686; }
goto P_0c0c35f8;
P_0c0c35f8: /* original a02e, guest PC 0x0c0c35f8 */
if(!s->budget--) { s->failed_pc=0x0c0c35f8u; return 0; }
goto P_0c0c3658;
P_0c0c35fa: /* original 0009, guest PC 0x0c0c35fa */
if(!s->budget--) { s->failed_pc=0x0c0c35fau; return 0; }
return vf3_matrix_family(0x0c0c35fcu,s,ram);
P_0c0c3610: /* original 9075, guest PC 0x0c0c3610 */
if(!s->budget--) { s->failed_pc=0x0c0c3610u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c36feu,2);
goto P_0c0c3612;
P_0c0c3612: /* original 00ac, guest PC 0x0c0c3612 */
if(!s->budget--) { s->failed_pc=0x0c0c3612u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0c3614;
P_0c0c3614: /* original 600c, guest PC 0x0c0c3614 */
if(!s->budget--) { s->failed_pc=0x0c0c3614u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c3616;
P_0c0c3616: /* original 8803, guest PC 0x0c0c3616 */
if(!s->budget--) { s->failed_pc=0x0c0c3616u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c3618;
P_0c0c3618: /* original 8b13, guest PC 0x0c0c3618 */
if(!s->budget--) { s->failed_pc=0x0c0c3618u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3642; }
goto P_0c0c361a;
P_0c0c361a: /* original 2668, guest PC 0x0c0c361a */
if(!s->budget--) { s->failed_pc=0x0c0c361au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c361c;
P_0c0c361c: /* original 8d11, guest PC 0x0c0c361c */
if(!s->budget--) { s->failed_pc=0x0c0c361cu; return 0; }
cond=r[17]&1u;
r[7]=r[8];
if(cond) { goto P_0c0c3642; }
goto P_0c0c3620;
P_0c0c361e: /* original 6783, guest PC 0x0c0c361e */
if(!s->budget--) { s->failed_pc=0x0c0c361eu; return 0; }
r[7]=r[8];
goto P_0c0c3620;
P_0c0c3620: /* original 50f8, guest PC 0x0c0c3620 */
if(!s->budget--) { s->failed_pc=0x0c0c3620u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c0c3622;
P_0c0c3622: /* original e10d, guest PC 0x0c0c3622 */
if(!s->budget--) { s->failed_pc=0x0c0c3622u; return 0; }
r[1]=0x0000000du;
goto P_0c0c3624;
P_0c0c3624: /* original 037c, guest PC 0x0c0c3624 */
if(!s->budget--) { s->failed_pc=0x0c0c3624u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0c3626;
P_0c0c3626: /* original 633c, guest PC 0x0c0c3626 */
if(!s->budget--) { s->failed_pc=0x0c0c3626u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c3628;
P_0c0c3628: /* original 3312, guest PC 0x0c0c3628 */
if(!s->budget--) { s->failed_pc=0x0c0c3628u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[1])!=0);
goto P_0c0c362a;
P_0c0c362a: /* original 1f31, guest PC 0x0c0c362a */
if(!s->budget--) { s->failed_pc=0x0c0c362au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c362c;
P_0c0c362c: /* original 8b02, guest PC 0x0c0c362c */
if(!s->budget--) { s->failed_pc=0x0c0c362cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3634; }
goto P_0c0c362e;
P_0c0c362e: /* original 50f1, guest PC 0x0c0c362e */
if(!s->budget--) { s->failed_pc=0x0c0c362eu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0c3630;
P_0c0c3630: /* original 70f3, guest PC 0x0c0c3630 */
if(!s->budget--) { s->failed_pc=0x0c0c3630u; return 0; }
r[0]+=0xfffffff3u;
goto P_0c0c3632;
P_0c0c3632: /* original 1f01, guest PC 0x0c0c3632 */
if(!s->budget--) { s->failed_pc=0x0c0c3632u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0c3634;
P_0c0c3634: /* original 51f1, guest PC 0x0c0c3634 */
if(!s->budget--) { s->failed_pc=0x0c0c3634u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0c3636;
P_0c0c3636: /* original 53f3, guest PC 0x0c0c3636 */
if(!s->budget--) { s->failed_pc=0x0c0c3636u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c3638;
P_0c0c3638: /* original 3130, guest PC 0x0c0c3638 */
if(!s->budget--) { s->failed_pc=0x0c0c3638u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0c363a;
P_0c0c363a: /* original 8919, guest PC 0x0c0c363a */
if(!s->budget--) { s->failed_pc=0x0c0c363au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3670; }
goto P_0c0c363c;
P_0c0c363c: /* original 7701, guest PC 0x0c0c363c */
if(!s->budget--) { s->failed_pc=0x0c0c363cu; return 0; }
r[7]+=0x00000001u;
goto P_0c0c363e;
P_0c0c363e: /* original 3766, guest PC 0x0c0c363e */
if(!s->budget--) { s->failed_pc=0x0c0c363eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[6])!=0);
goto P_0c0c3640;
P_0c0c3640: /* original 8bee, guest PC 0x0c0c3640 */
if(!s->budget--) { s->failed_pc=0x0c0c3640u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3620; }
goto P_0c0c3642;
P_0c0c3642: /* original 6683, guest PC 0x0c0c3642 */
if(!s->budget--) { s->failed_pc=0x0c0c3642u; return 0; }
r[6]=r[8];
goto P_0c0c3644;
P_0c0c3644: /* original 2448, guest PC 0x0c0c3644 */
if(!s->budget--) { s->failed_pc=0x0c0c3644u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3646;
P_0c0c3646: /* original 8907, guest PC 0x0c0c3646 */
if(!s->budget--) { s->failed_pc=0x0c0c3646u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3658; }
goto P_0c0c3648;
P_0c0c3648: /* original 50f9, guest PC 0x0c0c3648 */
if(!s->budget--) { s->failed_pc=0x0c0c3648u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c0c364a;
P_0c0c364a: /* original 076c, guest PC 0x0c0c364a */
if(!s->budget--) { s->failed_pc=0x0c0c364au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c364c;
P_0c0c364c: /* original 677c, guest PC 0x0c0c364c */
if(!s->budget--) { s->failed_pc=0x0c0c364cu; return 0; }
r[7]=r[7]&255u;
goto P_0c0c364e;
P_0c0c364e: /* original 37c0, guest PC 0x0c0c364e */
if(!s->budget--) { s->failed_pc=0x0c0c364eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[12])!=0);
goto P_0c0c3650;
P_0c0c3650: /* original 890e, guest PC 0x0c0c3650 */
if(!s->budget--) { s->failed_pc=0x0c0c3650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3670; }
goto P_0c0c3652;
P_0c0c3652: /* original 7601, guest PC 0x0c0c3652 */
if(!s->budget--) { s->failed_pc=0x0c0c3652u; return 0; }
r[6]+=0x00000001u;
goto P_0c0c3654;
P_0c0c3654: /* original aff6, guest PC 0x0c0c3654 */
if(!s->budget--) { s->failed_pc=0x0c0c3654u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c3644;
P_0c0c3656: /* original 74ff, guest PC 0x0c0c3656 */
if(!s->budget--) { s->failed_pc=0x0c0c3656u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c3658;
P_0c0c3658: /* original 52f2, guest PC 0x0c0c3658 */
if(!s->budget--) { s->failed_pc=0x0c0c3658u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c365a;
P_0c0c365a: /* original e036, guest PC 0x0c0c365a */
if(!s->budget--) { s->failed_pc=0x0c0c365au; return 0; }
r[0]=0x00000036u;
goto P_0c0c365c;
P_0c0c365c: /* original 252b, guest PC 0x0c0c365c */
if(!s->budget--) { s->failed_pc=0x0c0c365cu; return 0; }
r[5]|=r[2];
goto P_0c0c365e;
P_0c0c365e: /* original e201, guest PC 0x0c0c365e */
if(!s->budget--) { s->failed_pc=0x0c0c365eu; return 0; }
r[2]=0x00000001u;
goto P_0c0c3660;
P_0c0c3660: /* original 1f52, guest PC 0x0c0c3660 */
if(!s->budget--) { s->failed_pc=0x0c0c3660u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0c3662;
P_0c0c3662: /* original 53f6, guest PC 0x0c0c3662 */
if(!s->budget--) { s->failed_pc=0x0c0c3662u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c3664;
P_0c0c3664: /* original 33cc, guest PC 0x0c0c3664 */
if(!s->budget--) { s->failed_pc=0x0c0c3664u; return 0; }
r[3]+=r[12];
goto P_0c0c3666;
P_0c0c3666: /* original 2f32, guest PC 0x0c0c3666 */
if(!s->budget--) { s->failed_pc=0x0c0c3666u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3668;
P_0c0c3668: /* original 6323, guest PC 0x0c0c3668 */
if(!s->budget--) { s->failed_pc=0x0c0c3668u; return 0; }
r[3]=r[2];
goto P_0c0c366a;
P_0c0c366a: /* original 0e24, guest PC 0x0c0c366a */
if(!s->budget--) { s->failed_pc=0x0c0c366au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c366c;
P_0c0c366c: /* original e03a, guest PC 0x0c0c366c */
if(!s->budget--) { s->failed_pc=0x0c0c366cu; return 0; }
r[0]=0x0000003au;
goto P_0c0c366e;
P_0c0c366e: /* original 0e34, guest PC 0x0c0c366e */
if(!s->budget--) { s->failed_pc=0x0c0c366eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c3670;
P_0c0c3670: /* original b17c, guest PC 0x0c0c3670 */
if(!s->budget--) { s->failed_pc=0x0c0c3670u; return 0; }
target=0x0c0c396cu; r[16]=0x0c0c3674u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3674u) { target=s->pc; goto dispatch; }
goto P_0c0c3674;
P_0c0c3672: /* original 64f2, guest PC 0x0c0c3672 */
if(!s->budget--) { s->failed_pc=0x0c0c3672u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c3674;
P_0c0c3674: /* original 6303, guest PC 0x0c0c3674 */
if(!s->budget--) { s->failed_pc=0x0c0c3674u; return 0; }
r[3]=r[0];
goto P_0c0c3676;
P_0c0c3676: /* original 2f02, guest PC 0x0c0c3676 */
if(!s->budget--) { s->failed_pc=0x0c0c3676u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c3678;
P_0c0c3678: /* original e060, guest PC 0x0c0c3678 */
if(!s->budget--) { s->failed_pc=0x0c0c3678u; return 0; }
r[0]=0x00000060u;
goto P_0c0c367a;
P_0c0c367a: /* original 0b34, guest PC 0x0c0c367a */
if(!s->budget--) { s->failed_pc=0x0c0c367au; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c0c367c;
P_0c0c367c: /* original e032, guest PC 0x0c0c367c */
if(!s->budget--) { s->failed_pc=0x0c0c367cu; return 0; }
r[0]=0x00000032u;
goto P_0c0c367e;
P_0c0c367e: /* original 0e34, guest PC 0x0c0c367e */
if(!s->budget--) { s->failed_pc=0x0c0c367eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c3680;
P_0c0c3680: /* original 903e, guest PC 0x0c0c3680 */
if(!s->budget--) { s->failed_pc=0x0c0c3680u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3700u,2);
goto P_0c0c3682;
P_0c0c3682: /* original 52f2, guest PC 0x0c0c3682 */
if(!s->budget--) { s->failed_pc=0x0c0c3682u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c3684;
P_0c0c3684: /* original 0a26, guest PC 0x0c0c3684 */
if(!s->budget--) { s->failed_pc=0x0c0c3684u; return 0; }
write(ram,r[10]+r[0],r[2],4);
goto P_0c0c3686;
P_0c0c3686: /* original 913c, guest PC 0x0c0c3686 */
if(!s->budget--) { s->failed_pc=0x0c0c3686u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3702u,2);
goto P_0c0c3688;
P_0c0c3688: /* original 53f3, guest PC 0x0c0c3688 */
if(!s->budget--) { s->failed_pc=0x0c0c3688u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c368a;
P_0c0c368a: /* original 31dc, guest PC 0x0c0c368a */
if(!s->budget--) { s->failed_pc=0x0c0c368au; return 0; }
r[1]+=r[13];
goto P_0c0c368c;
P_0c0c368c: /* original 313c, guest PC 0x0c0c368c */
if(!s->budget--) { s->failed_pc=0x0c0c368cu; return 0; }
r[1]+=r[3];
goto P_0c0c368e;
P_0c0c368e: /* original 6210, guest PC 0x0c0c368e */
if(!s->budget--) { s->failed_pc=0x0c0c368eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c0c3690;
P_0c0c3690: /* original 7201, guest PC 0x0c0c3690 */
if(!s->budget--) { s->failed_pc=0x0c0c3690u; return 0; }
r[2]+=0x00000001u;
goto P_0c0c3692;
P_0c0c3692: /* original 2120, guest PC 0x0c0c3692 */
if(!s->budget--) { s->failed_pc=0x0c0c3692u; return 0; }
write(ram,r[1],r[2],1);
goto P_0c0c3694;
P_0c0c3694: /* original 50d2, guest PC 0x0c0c3694 */
if(!s->budget--) { s->failed_pc=0x0c0c3694u; return 0; }
r[0]=read(ram,r[13]+8,4);
goto P_0c0c3696;
P_0c0c3696: /* original c804, guest PC 0x0c0c3696 */
if(!s->budget--) { s->failed_pc=0x0c0c3696u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0c3698;
P_0c0c3698: /* original 8b01, guest PC 0x0c0c3698 */
if(!s->budget--) { s->failed_pc=0x0c0c3698u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c369e; }
goto P_0c0c369a;
P_0c0c369a: /* original a0e5, guest PC 0x0c0c369a */
if(!s->budget--) { s->failed_pc=0x0c0c369au; return 0; }
goto P_0c0c3868;
P_0c0c369c: /* original 0009, guest PC 0x0c0c369c */
if(!s->budget--) { s->failed_pc=0x0c0c369cu; return 0; }
goto P_0c0c369e;
P_0c0c369e: /* original 9031, guest PC 0x0c0c369e */
if(!s->budget--) { s->failed_pc=0x0c0c369eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3704u,2);
goto P_0c0c36a0;
P_0c0c36a0: /* original 03dc, guest PC 0x0c0c36a0 */
if(!s->budget--) { s->failed_pc=0x0c0c36a0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c36a2;
P_0c0c36a2: /* original 1f36, guest PC 0x0c0c36a2 */
if(!s->budget--) { s->failed_pc=0x0c0c36a2u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0c36a4;
P_0c0c36a4: /* original 84e4, guest PC 0x0c0c36a4 */
if(!s->budget--) { s->failed_pc=0x0c0c36a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c36a6;
P_0c0c36a6: /* original 2008, guest PC 0x0c0c36a6 */
if(!s->budget--) { s->failed_pc=0x0c0c36a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c36a8;
P_0c0c36a8: /* original 8905, guest PC 0x0c0c36a8 */
if(!s->budget--) { s->failed_pc=0x0c0c36a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c36b6; }
goto P_0c0c36aa;
P_0c0c36aa: /* original 6293, guest PC 0x0c0c36aa */
if(!s->budget--) { s->failed_pc=0x0c0c36aau; return 0; }
r[2]=r[9];
goto P_0c0c36ac;
P_0c0c36ac: /* original 7201, guest PC 0x0c0c36ac */
if(!s->budget--) { s->failed_pc=0x0c0c36acu; return 0; }
r[2]+=0x00000001u;
goto P_0c0c36ae;
P_0c0c36ae: /* original 1f22, guest PC 0x0c0c36ae */
if(!s->budget--) { s->failed_pc=0x0c0c36aeu; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0c36b0;
P_0c0c36b0: /* original 9329, guest PC 0x0c0c36b0 */
if(!s->budget--) { s->failed_pc=0x0c0c36b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3706u,2);
goto P_0c0c36b2;
P_0c0c36b2: /* original a002, guest PC 0x0c0c36b2 */
if(!s->budget--) { s->failed_pc=0x0c0c36b2u; return 0; }
goto P_0c0c36ba;
P_0c0c36b4: /* original 0009, guest PC 0x0c0c36b4 */
if(!s->budget--) { s->failed_pc=0x0c0c36b4u; return 0; }
goto P_0c0c36b6;
P_0c0c36b6: /* original 1f92, guest PC 0x0c0c36b6 */
if(!s->budget--) { s->failed_pc=0x0c0c36b6u; return 0; }
write(ram,r[15]+8,r[9],4);
goto P_0c0c36b8;
P_0c0c36b8: /* original 9326, guest PC 0x0c0c36b8 */
if(!s->budget--) { s->failed_pc=0x0c0c36b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3708u,2);
goto P_0c0c36ba;
P_0c0c36ba: /* original 33dc, guest PC 0x0c0c36ba */
if(!s->budget--) { s->failed_pc=0x0c0c36bau; return 0; }
r[3]+=r[13];
goto P_0c0c36bc;
P_0c0c36bc: /* original 1f33, guest PC 0x0c0c36bc */
if(!s->budget--) { s->failed_pc=0x0c0c36bcu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0c36be;
P_0c0c36be: /* original d313, guest PC 0x0c0c36be */
if(!s->budget--) { s->failed_pc=0x0c0c36beu; return 0; }
r[3]=read(ram,0x0c0c370cu,4);
goto P_0c0c36c0;
P_0c0c36c0: /* original 54f7, guest PC 0x0c0c36c0 */
if(!s->budget--) { s->failed_pc=0x0c0c36c0u; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c0c36c2;
P_0c0c36c2: /* original 430b, guest PC 0x0c0c36c2 */
if(!s->budget--) { s->failed_pc=0x0c0c36c2u; return 0; }
target=r[3];
r[16]=0x0c0c36c6u;
r[4]+=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c36c6u) { target=s->pc; goto dispatch; }
goto P_0c0c36c6;
P_0c0c36c4: /* original 7416, guest PC 0x0c0c36c4 */
if(!s->budget--) { s->failed_pc=0x0c0c36c4u; return 0; }
r[4]+=0x00000016u;
goto P_0c0c36c6;
P_0c0c36c6: /* original 640c, guest PC 0x0c0c36c6 */
if(!s->budget--) { s->failed_pc=0x0c0c36c6u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c36c8;
P_0c0c36c8: /* original 2448, guest PC 0x0c0c36c8 */
if(!s->budget--) { s->failed_pc=0x0c0c36c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c36ca;
P_0c0c36ca: /* original 8928, guest PC 0x0c0c36ca */
if(!s->budget--) { s->failed_pc=0x0c0c36cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c371e; }
goto P_0c0c36cc;
P_0c0c36cc: /* original 84e4, guest PC 0x0c0c36cc */
if(!s->budget--) { s->failed_pc=0x0c0c36ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c36ce;
P_0c0c36ce: /* original 2008, guest PC 0x0c0c36ce */
if(!s->budget--) { s->failed_pc=0x0c0c36ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c36d0;
P_0c0c36d0: /* original 8902, guest PC 0x0c0c36d0 */
if(!s->budget--) { s->failed_pc=0x0c0c36d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c36d8; }
goto P_0c0c36d2;
P_0c0c36d2: /* original 6693, guest PC 0x0c0c36d2 */
if(!s->budget--) { s->failed_pc=0x0c0c36d2u; return 0; }
r[6]=r[9];
goto P_0c0c36d4;
P_0c0c36d4: /* original a002, guest PC 0x0c0c36d4 */
if(!s->budget--) { s->failed_pc=0x0c0c36d4u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c36dc;
P_0c0c36d6: /* original 7608, guest PC 0x0c0c36d6 */
if(!s->budget--) { s->failed_pc=0x0c0c36d6u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c36d8;
P_0c0c36d8: /* original 6693, guest PC 0x0c0c36d8 */
if(!s->budget--) { s->failed_pc=0x0c0c36d8u; return 0; }
r[6]=r[9];
goto P_0c0c36da;
P_0c0c36da: /* original 7604, guest PC 0x0c0c36da */
if(!s->budget--) { s->failed_pc=0x0c0c36dau; return 0; }
r[6]+=0x00000004u;
goto P_0c0c36dc;
P_0c0c36dc: /* original 64f2, guest PC 0x0c0c36dc */
if(!s->budget--) { s->failed_pc=0x0c0c36dcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c36de;
P_0c0c36de: /* original e30d, guest PC 0x0c0c36de */
if(!s->budget--) { s->failed_pc=0x0c0c36deu; return 0; }
r[3]=0x0000000du;
goto P_0c0c36e0;
P_0c0c36e0: /* original 3432, guest PC 0x0c0c36e0 */
if(!s->budget--) { s->failed_pc=0x0c0c36e0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c0c36e2;
P_0c0c36e2: /* original 8f01, guest PC 0x0c0c36e2 */
if(!s->budget--) { s->failed_pc=0x0c0c36e2u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[6],4);
r[5]=tmp;
if(!cond) { goto P_0c0c36e8; }
goto P_0c0c36e6;
P_0c0c36e4: /* original 6562, guest PC 0x0c0c36e4 */
if(!s->budget--) { s->failed_pc=0x0c0c36e4u; return 0; }
tmp=read(ram,r[6],4);
r[5]=tmp;
goto P_0c0c36e6;
P_0c0c36e6: /* original 3438, guest PC 0x0c0c36e6 */
if(!s->budget--) { s->failed_pc=0x0c0c36e6u; return 0; }
r[4]-=r[3];
goto P_0c0c36e8;
P_0c0c36e8: /* original d209, guest PC 0x0c0c36e8 */
if(!s->budget--) { s->failed_pc=0x0c0c36e8u; return 0; }
r[2]=read(ram,0x0c0c3710u,4);
goto P_0c0c36ea;
P_0c0c36ea: /* original 634b, guest PC 0x0c0c36ea */
if(!s->budget--) { s->failed_pc=0x0c0c36eau; return 0; }
r[3]=0u-r[4];
goto P_0c0c36ec;
P_0c0c36ec: /* original 423d, guest PC 0x0c0c36ec */
if(!s->budget--) { s->failed_pc=0x0c0c36ecu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c0c36ee;
P_0c0c36ee: /* original 2258, guest PC 0x0c0c36ee */
if(!s->budget--) { s->failed_pc=0x0c0c36eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c36f0;
P_0c0c36f0: /* original 8910, guest PC 0x0c0c36f0 */
if(!s->budget--) { s->failed_pc=0x0c0c36f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3714; }
goto P_0c0c36f2;
P_0c0c36f2: /* original 54db, guest PC 0x0c0c36f2 */
if(!s->budget--) { s->failed_pc=0x0c0c36f2u; return 0; }
r[4]=read(ram,r[13]+44,4);
goto P_0c0c36f4;
P_0c0c36f4: /* original e33f, guest PC 0x0c0c36f4 */
if(!s->budget--) { s->failed_pc=0x0c0c36f4u; return 0; }
r[3]=0x0000003fu;
goto P_0c0c36f6;
P_0c0c36f6: /* original 3437, guest PC 0x0c0c36f6 */
if(!s->budget--) { s->failed_pc=0x0c0c36f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0c36f8;
P_0c0c36f8: /* original 8b43, guest PC 0x0c0c36f8 */
if(!s->budget--) { s->failed_pc=0x0c0c36f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3782; }
goto P_0c0c36fa;
P_0c0c36fa: /* original a0da, guest PC 0x0c0c36fa */
if(!s->budget--) { s->failed_pc=0x0c0c36fau; return 0; }
goto P_0c0c38b2;
P_0c0c36fc: /* original 0009, guest PC 0x0c0c36fc */
if(!s->budget--) { s->failed_pc=0x0c0c36fcu; return 0; }
return vf3_matrix_family(0x0c0c36feu,s,ram);
P_0c0c3714: /* original d146, guest PC 0x0c0c3714 */
if(!s->budget--) { s->failed_pc=0x0c0c3714u; return 0; }
r[1]=read(ram,0x0c0c3830u,4);
goto P_0c0c3716;
P_0c0c3716: /* original 644b, guest PC 0x0c0c3716 */
if(!s->budget--) { s->failed_pc=0x0c0c3716u; return 0; }
r[4]=0u-r[4];
goto P_0c0c3718;
P_0c0c3718: /* original 414d, guest PC 0x0c0c3718 */
if(!s->budget--) { s->failed_pc=0x0c0c3718u; return 0; }
r[1]=(r[4]&0x80000000u)?((r[4]&31u)?r[1]>>((-r[4])&31u):0):r[1]<<(r[4]&31u);
goto P_0c0c371a;
P_0c0c371a: /* original 251b, guest PC 0x0c0c371a */
if(!s->budget--) { s->failed_pc=0x0c0c371au; return 0; }
r[5]|=r[1];
goto P_0c0c371c;
P_0c0c371c: /* original 2652, guest PC 0x0c0c371c */
if(!s->budget--) { s->failed_pc=0x0c0c371cu; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0c371e;
P_0c0c371e: /* original 53f2, guest PC 0x0c0c371e */
if(!s->budget--) { s->failed_pc=0x0c0c371eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c3720;
P_0c0c3720: /* original e160, guest PC 0x0c0c3720 */
if(!s->budget--) { s->failed_pc=0x0c0c3720u; return 0; }
r[1]=0x00000060u;
goto P_0c0c3722;
P_0c0c3722: /* original 31bc, guest PC 0x0c0c3722 */
if(!s->budget--) { s->failed_pc=0x0c0c3722u; return 0; }
r[1]+=r[11];
goto P_0c0c3724;
P_0c0c3724: /* original 6230, guest PC 0x0c0c3724 */
if(!s->budget--) { s->failed_pc=0x0c0c3724u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0c3726;
P_0c0c3726: /* original 622c, guest PC 0x0c0c3726 */
if(!s->budget--) { s->failed_pc=0x0c0c3726u; return 0; }
r[2]=r[2]&255u;
goto P_0c0c3728;
P_0c0c3728: /* original 1f21, guest PC 0x0c0c3728 */
if(!s->budget--) { s->failed_pc=0x0c0c3728u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0c372a;
P_0c0c372a: /* original 50f3, guest PC 0x0c0c372a */
if(!s->budget--) { s->failed_pc=0x0c0c372au; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0c372c;
P_0c0c372c: /* original 63f2, guest PC 0x0c0c372c */
if(!s->budget--) { s->failed_pc=0x0c0c372cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c372e;
P_0c0c372e: /* original 2130, guest PC 0x0c0c372e */
if(!s->budget--) { s->failed_pc=0x0c0c372eu; return 0; }
write(ram,r[1],r[3],1);
goto P_0c0c3730;
P_0c0c3730: /* original e132, guest PC 0x0c0c3730 */
if(!s->budget--) { s->failed_pc=0x0c0c3730u; return 0; }
r[1]=0x00000032u;
goto P_0c0c3732;
P_0c0c3732: /* original 31ec, guest PC 0x0c0c3732 */
if(!s->budget--) { s->failed_pc=0x0c0c3732u; return 0; }
r[1]+=r[14];
goto P_0c0c3734;
P_0c0c3734: /* original 2130, guest PC 0x0c0c3734 */
if(!s->budget--) { s->failed_pc=0x0c0c3734u; return 0; }
write(ram,r[1],r[3],1);
goto P_0c0c3736;
P_0c0c3736: /* original 0234, guest PC 0x0c0c3736 */
if(!s->budget--) { s->failed_pc=0x0c0c3736u; return 0; }
write(ram,r[2]+r[0],r[3],1);
goto P_0c0c3738;
P_0c0c3738: /* original e06c, guest PC 0x0c0c3738 */
if(!s->budget--) { s->failed_pc=0x0c0c3738u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c373a;
P_0c0c373a: /* original 00ee, guest PC 0x0c0c373a */
if(!s->budget--) { s->failed_pc=0x0c0c373au; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c373c;
P_0c0c373c: /* original 8806, guest PC 0x0c0c373c */
if(!s->budget--) { s->failed_pc=0x0c0c373cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c373e;
P_0c0c373e: /* original 8902, guest PC 0x0c0c373e */
if(!s->budget--) { s->failed_pc=0x0c0c373eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3746; }
goto P_0c0c3740;
P_0c0c3740: /* original 65b3, guest PC 0x0c0c3740 */
if(!s->budget--) { s->failed_pc=0x0c0c3740u; return 0; }
r[5]=r[11];
goto P_0c0c3742;
P_0c0c3742: /* original b0c0, guest PC 0x0c0c3742 */
if(!s->budget--) { s->failed_pc=0x0c0c3742u; return 0; }
target=0x0c0c38c6u; r[16]=0x0c0c3746u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3746u) { target=s->pc; goto dispatch; }
goto P_0c0c3746;
P_0c0c3744: /* original 64e3, guest PC 0x0c0c3744 */
if(!s->budget--) { s->failed_pc=0x0c0c3744u; return 0; }
r[4]=r[14];
goto P_0c0c3746;
P_0c0c3746: /* original 53f1, guest PC 0x0c0c3746 */
if(!s->budget--) { s->failed_pc=0x0c0c3746u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c3748;
P_0c0c3748: /* original 7301, guest PC 0x0c0c3748 */
if(!s->budget--) { s->failed_pc=0x0c0c3748u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c374a;
P_0c0c374a: /* original 1f31, guest PC 0x0c0c374a */
if(!s->budget--) { s->failed_pc=0x0c0c374au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c374c;
P_0c0c374c: /* original 52f6, guest PC 0x0c0c374c */
if(!s->budget--) { s->failed_pc=0x0c0c374cu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0c374e;
P_0c0c374e: /* original 3322, guest PC 0x0c0c374e */
if(!s->budget--) { s->failed_pc=0x0c0c374eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0c3750;
P_0c0c3750: /* original 8972, guest PC 0x0c0c3750 */
if(!s->budget--) { s->failed_pc=0x0c0c3750u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3838; }
goto P_0c0c3752;
P_0c0c3752: /* original 52f1, guest PC 0x0c0c3752 */
if(!s->budget--) { s->failed_pc=0x0c0c3752u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c3754;
P_0c0c3754: /* original 53f2, guest PC 0x0c0c3754 */
if(!s->budget--) { s->failed_pc=0x0c0c3754u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c3756;
P_0c0c3756: /* original 2320, guest PC 0x0c0c3756 */
if(!s->budget--) { s->failed_pc=0x0c0c3756u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0c3758;
P_0c0c3758: /* original e33f, guest PC 0x0c0c3758 */
if(!s->budget--) { s->failed_pc=0x0c0c3758u; return 0; }
r[3]=0x0000003fu;
goto P_0c0c375a;
P_0c0c375a: /* original 54db, guest PC 0x0c0c375a */
if(!s->budget--) { s->failed_pc=0x0c0c375au; return 0; }
r[4]=read(ram,r[13]+44,4);
goto P_0c0c375c;
P_0c0c375c: /* original 3437, guest PC 0x0c0c375c */
if(!s->budget--) { s->failed_pc=0x0c0c375cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0c375e;
P_0c0c375e: /* original 896e, guest PC 0x0c0c375e */
if(!s->budget--) { s->failed_pc=0x0c0c375eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c383e; }
goto P_0c0c3760;
P_0c0c3760: /* original 9062, guest PC 0x0c0c3760 */
if(!s->budget--) { s->failed_pc=0x0c0c3760u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3828u,2);
goto P_0c0c3762;
P_0c0c3762: /* original 02dc, guest PC 0x0c0c3762 */
if(!s->budget--) { s->failed_pc=0x0c0c3762u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c3764;
P_0c0c3764: /* original 1f26, guest PC 0x0c0c3764 */
if(!s->budget--) { s->failed_pc=0x0c0c3764u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0c3766;
P_0c0c3766: /* original 84e4, guest PC 0x0c0c3766 */
if(!s->budget--) { s->failed_pc=0x0c0c3766u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3768;
P_0c0c3768: /* original 2008, guest PC 0x0c0c3768 */
if(!s->budget--) { s->failed_pc=0x0c0c3768u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c376a;
P_0c0c376a: /* original 8906, guest PC 0x0c0c376a */
if(!s->budget--) { s->failed_pc=0x0c0c376au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c377a; }
goto P_0c0c376c;
P_0c0c376c: /* original 6393, guest PC 0x0c0c376c */
if(!s->budget--) { s->failed_pc=0x0c0c376cu; return 0; }
r[3]=r[9];
goto P_0c0c376e;
P_0c0c376e: /* original 7301, guest PC 0x0c0c376e */
if(!s->budget--) { s->failed_pc=0x0c0c376eu; return 0; }
r[3]+=0x00000001u;
goto P_0c0c3770;
P_0c0c3770: /* original 1f32, guest PC 0x0c0c3770 */
if(!s->budget--) { s->failed_pc=0x0c0c3770u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c3772;
P_0c0c3772: /* original 925a, guest PC 0x0c0c3772 */
if(!s->budget--) { s->failed_pc=0x0c0c3772u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c382au,2);
goto P_0c0c3774;
P_0c0c3774: /* original 32dc, guest PC 0x0c0c3774 */
if(!s->budget--) { s->failed_pc=0x0c0c3774u; return 0; }
r[2]+=r[13];
goto P_0c0c3776;
P_0c0c3776: /* original a004, guest PC 0x0c0c3776 */
if(!s->budget--) { s->failed_pc=0x0c0c3776u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c3782;
P_0c0c3778: /* original 1f23, guest PC 0x0c0c3778 */
if(!s->budget--) { s->failed_pc=0x0c0c3778u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c377a;
P_0c0c377a: /* original 1f92, guest PC 0x0c0c377a */
if(!s->budget--) { s->failed_pc=0x0c0c377au; return 0; }
write(ram,r[15]+8,r[9],4);
goto P_0c0c377c;
P_0c0c377c: /* original 9356, guest PC 0x0c0c377c */
if(!s->budget--) { s->failed_pc=0x0c0c377cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c382cu,2);
goto P_0c0c377e;
P_0c0c377e: /* original 33dc, guest PC 0x0c0c377e */
if(!s->budget--) { s->failed_pc=0x0c0c377eu; return 0; }
r[3]+=r[13];
goto P_0c0c3780;
P_0c0c3780: /* original 1f33, guest PC 0x0c0c3780 */
if(!s->budget--) { s->failed_pc=0x0c0c3780u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0c3782;
P_0c0c3782: /* original d32c, guest PC 0x0c0c3782 */
if(!s->budget--) { s->failed_pc=0x0c0c3782u; return 0; }
r[3]=read(ram,0x0c0c3834u,4);
goto P_0c0c3784;
P_0c0c3784: /* original 54f7, guest PC 0x0c0c3784 */
if(!s->budget--) { s->failed_pc=0x0c0c3784u; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c0c3786;
P_0c0c3786: /* original 430b, guest PC 0x0c0c3786 */
if(!s->budget--) { s->failed_pc=0x0c0c3786u; return 0; }
target=r[3];
r[16]=0x0c0c378au;
r[4]+=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c378au) { target=s->pc; goto dispatch; }
goto P_0c0c378a;
P_0c0c3788: /* original 7416, guest PC 0x0c0c3788 */
if(!s->budget--) { s->failed_pc=0x0c0c3788u; return 0; }
r[4]+=0x00000016u;
goto P_0c0c378a;
P_0c0c378a: /* original 640c, guest PC 0x0c0c378a */
if(!s->budget--) { s->failed_pc=0x0c0c378au; return 0; }
r[4]=r[0]&255u;
goto P_0c0c378c;
P_0c0c378c: /* original 2448, guest PC 0x0c0c378c */
if(!s->budget--) { s->failed_pc=0x0c0c378cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c378e;
P_0c0c378e: /* original 892c, guest PC 0x0c0c378e */
if(!s->budget--) { s->failed_pc=0x0c0c378eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c37ea; }
goto P_0c0c3790;
P_0c0c3790: /* original 84e4, guest PC 0x0c0c3790 */
if(!s->budget--) { s->failed_pc=0x0c0c3790u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3792;
P_0c0c3792: /* original 2008, guest PC 0x0c0c3792 */
if(!s->budget--) { s->failed_pc=0x0c0c3792u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c3794;
P_0c0c3794: /* original 8902, guest PC 0x0c0c3794 */
if(!s->budget--) { s->failed_pc=0x0c0c3794u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c379c; }
goto P_0c0c3796;
P_0c0c3796: /* original 6493, guest PC 0x0c0c3796 */
if(!s->budget--) { s->failed_pc=0x0c0c3796u; return 0; }
r[4]=r[9];
goto P_0c0c3798;
P_0c0c3798: /* original a002, guest PC 0x0c0c3798 */
if(!s->budget--) { s->failed_pc=0x0c0c3798u; return 0; }
r[4]+=0x00000008u;
goto P_0c0c37a0;
P_0c0c379a: /* original 7408, guest PC 0x0c0c379a */
if(!s->budget--) { s->failed_pc=0x0c0c379au; return 0; }
r[4]+=0x00000008u;
goto P_0c0c379c;
P_0c0c379c: /* original 6493, guest PC 0x0c0c379c */
if(!s->budget--) { s->failed_pc=0x0c0c379cu; return 0; }
r[4]=r[9];
goto P_0c0c379e;
P_0c0c379e: /* original 7404, guest PC 0x0c0c379e */
if(!s->budget--) { s->failed_pc=0x0c0c379eu; return 0; }
r[4]+=0x00000004u;
goto P_0c0c37a0;
P_0c0c37a0: /* original 66f2, guest PC 0x0c0c37a0 */
if(!s->budget--) { s->failed_pc=0x0c0c37a0u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0c37a2;
P_0c0c37a2: /* original e30d, guest PC 0x0c0c37a2 */
if(!s->budget--) { s->failed_pc=0x0c0c37a2u; return 0; }
r[3]=0x0000000du;
goto P_0c0c37a4;
P_0c0c37a4: /* original 3632, guest PC 0x0c0c37a4 */
if(!s->budget--) { s->failed_pc=0x0c0c37a4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[3])!=0);
goto P_0c0c37a6;
P_0c0c37a6: /* original 8f01, guest PC 0x0c0c37a6 */
if(!s->budget--) { s->failed_pc=0x0c0c37a6u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[4],4);
r[5]=tmp;
if(!cond) { goto P_0c0c37ac; }
goto P_0c0c37aa;
P_0c0c37a8: /* original 6542, guest PC 0x0c0c37a8 */
if(!s->budget--) { s->failed_pc=0x0c0c37a8u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0c37aa;
P_0c0c37aa: /* original 3638, guest PC 0x0c0c37aa */
if(!s->budget--) { s->failed_pc=0x0c0c37aau; return 0; }
r[6]-=r[3];
goto P_0c0c37ac;
P_0c0c37ac: /* original d720, guest PC 0x0c0c37ac */
if(!s->budget--) { s->failed_pc=0x0c0c37acu; return 0; }
r[7]=read(ram,0x0c0c3830u,4);
goto P_0c0c37ae;
P_0c0c37ae: /* original 666b, guest PC 0x0c0c37ae */
if(!s->budget--) { s->failed_pc=0x0c0c37aeu; return 0; }
r[6]=0u-r[6];
goto P_0c0c37b0;
P_0c0c37b0: /* original 476d, guest PC 0x0c0c37b0 */
if(!s->budget--) { s->failed_pc=0x0c0c37b0u; return 0; }
r[7]=(r[6]&0x80000000u)?((r[6]&31u)?r[7]>>((-r[6])&31u):0):r[7]<<(r[6]&31u);
goto P_0c0c37b2;
P_0c0c37b2: /* original 6373, guest PC 0x0c0c37b2 */
if(!s->budget--) { s->failed_pc=0x0c0c37b2u; return 0; }
r[3]=r[7];
goto P_0c0c37b4;
P_0c0c37b4: /* original 2358, guest PC 0x0c0c37b4 */
if(!s->budget--) { s->failed_pc=0x0c0c37b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c37b6;
P_0c0c37b6: /* original 8916, guest PC 0x0c0c37b6 */
if(!s->budget--) { s->failed_pc=0x0c0c37b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c37e6; }
goto P_0c0c37b8;
P_0c0c37b8: /* original e034, guest PC 0x0c0c37b8 */
if(!s->budget--) { s->failed_pc=0x0c0c37b8u; return 0; }
r[0]=0x00000034u;
goto P_0c0c37ba;
P_0c0c37ba: /* original 01ec, guest PC 0x0c0c37ba */
if(!s->budget--) { s->failed_pc=0x0c0c37bau; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c37bc;
P_0c0c37bc: /* original e035, guest PC 0x0c0c37bc */
if(!s->budget--) { s->failed_pc=0x0c0c37bcu; return 0; }
r[0]=0x00000035u;
goto P_0c0c37be;
P_0c0c37be: /* original e305, guest PC 0x0c0c37be */
if(!s->budget--) { s->failed_pc=0x0c0c37beu; return 0; }
r[3]=0x00000005u;
goto P_0c0c37c0;
P_0c0c37c0: /* original 611c, guest PC 0x0c0c37c0 */
if(!s->budget--) { s->failed_pc=0x0c0c37c0u; return 0; }
r[1]=r[1]&255u;
goto P_0c0c37c2;
P_0c0c37c2: /* original 2f12, guest PC 0x0c0c37c2 */
if(!s->budget--) { s->failed_pc=0x0c0c37c2u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c37c4;
P_0c0c37c4: /* original 0cec, guest PC 0x0c0c37c4 */
if(!s->budget--) { s->failed_pc=0x0c0c37c4u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c37c6;
P_0c0c37c6: /* original 6ccc, guest PC 0x0c0c37c6 */
if(!s->budget--) { s->failed_pc=0x0c0c37c6u; return 0; }
r[12]=r[12]&255u;
goto P_0c0c37c8;
P_0c0c37c8: /* original 7c01, guest PC 0x0c0c37c8 */
if(!s->budget--) { s->failed_pc=0x0c0c37c8u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c37ca;
P_0c0c37ca: /* original 3c37, guest PC 0x0c0c37ca */
if(!s->budget--) { s->failed_pc=0x0c0c37cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[3])!=0);
goto P_0c0c37cc;
P_0c0c37cc: /* original 8b05, guest PC 0x0c0c37cc */
if(!s->budget--) { s->failed_pc=0x0c0c37ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c37da; }
goto P_0c0c37ce;
P_0c0c37ce: /* original 61f2, guest PC 0x0c0c37ce */
if(!s->budget--) { s->failed_pc=0x0c0c37ceu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0c37d0;
P_0c0c37d0: /* original e201, guest PC 0x0c0c37d0 */
if(!s->budget--) { s->failed_pc=0x0c0c37d0u; return 0; }
r[2]=0x00000001u;
goto P_0c0c37d2;
P_0c0c37d2: /* original 6c83, guest PC 0x0c0c37d2 */
if(!s->budget--) { s->failed_pc=0x0c0c37d2u; return 0; }
r[12]=r[8];
goto P_0c0c37d4;
P_0c0c37d4: /* original 7101, guest PC 0x0c0c37d4 */
if(!s->budget--) { s->failed_pc=0x0c0c37d4u; return 0; }
r[1]+=0x00000001u;
goto P_0c0c37d6;
P_0c0c37d6: /* original 2129, guest PC 0x0c0c37d6 */
if(!s->budget--) { s->failed_pc=0x0c0c37d6u; return 0; }
r[1]&=r[2];
goto P_0c0c37d8;
P_0c0c37d8: /* original 2f12, guest PC 0x0c0c37d8 */
if(!s->budget--) { s->failed_pc=0x0c0c37d8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c37da;
P_0c0c37da: /* original 63f2, guest PC 0x0c0c37da */
if(!s->budget--) { s->failed_pc=0x0c0c37dau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c37dc;
P_0c0c37dc: /* original e034, guest PC 0x0c0c37dc */
if(!s->budget--) { s->failed_pc=0x0c0c37dcu; return 0; }
r[0]=0x00000034u;
goto P_0c0c37de;
P_0c0c37de: /* original 0e34, guest PC 0x0c0c37de */
if(!s->budget--) { s->failed_pc=0x0c0c37deu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c37e0;
P_0c0c37e0: /* original e035, guest PC 0x0c0c37e0 */
if(!s->budget--) { s->failed_pc=0x0c0c37e0u; return 0; }
r[0]=0x00000035u;
goto P_0c0c37e2;
P_0c0c37e2: /* original ade5, guest PC 0x0c0c37e2 */
if(!s->budget--) { s->failed_pc=0x0c0c37e2u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c33b0;
P_0c0c37e4: /* original 0ec4, guest PC 0x0c0c37e4 */
if(!s->budget--) { s->failed_pc=0x0c0c37e4u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c37e6;
P_0c0c37e6: /* original 257b, guest PC 0x0c0c37e6 */
if(!s->budget--) { s->failed_pc=0x0c0c37e6u; return 0; }
r[5]|=r[7];
goto P_0c0c37e8;
P_0c0c37e8: /* original 2452, guest PC 0x0c0c37e8 */
if(!s->budget--) { s->failed_pc=0x0c0c37e8u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0c37ea;
P_0c0c37ea: /* original 52f2, guest PC 0x0c0c37ea */
if(!s->budget--) { s->failed_pc=0x0c0c37eau; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c37ec;
P_0c0c37ec: /* original e160, guest PC 0x0c0c37ec */
if(!s->budget--) { s->failed_pc=0x0c0c37ecu; return 0; }
r[1]=0x00000060u;
goto P_0c0c37ee;
P_0c0c37ee: /* original 31bc, guest PC 0x0c0c37ee */
if(!s->budget--) { s->failed_pc=0x0c0c37eeu; return 0; }
r[1]+=r[11];
goto P_0c0c37f0;
P_0c0c37f0: /* original 6320, guest PC 0x0c0c37f0 */
if(!s->budget--) { s->failed_pc=0x0c0c37f0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0c37f2;
P_0c0c37f2: /* original 633c, guest PC 0x0c0c37f2 */
if(!s->budget--) { s->failed_pc=0x0c0c37f2u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c37f4;
P_0c0c37f4: /* original 1f31, guest PC 0x0c0c37f4 */
if(!s->budget--) { s->failed_pc=0x0c0c37f4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c37f6;
P_0c0c37f6: /* original 50f3, guest PC 0x0c0c37f6 */
if(!s->budget--) { s->failed_pc=0x0c0c37f6u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0c37f8;
P_0c0c37f8: /* original 62f2, guest PC 0x0c0c37f8 */
if(!s->budget--) { s->failed_pc=0x0c0c37f8u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c37fa;
P_0c0c37fa: /* original 2120, guest PC 0x0c0c37fa */
if(!s->budget--) { s->failed_pc=0x0c0c37fau; return 0; }
write(ram,r[1],r[2],1);
goto P_0c0c37fc;
P_0c0c37fc: /* original e132, guest PC 0x0c0c37fc */
if(!s->budget--) { s->failed_pc=0x0c0c37fcu; return 0; }
r[1]=0x00000032u;
goto P_0c0c37fe;
P_0c0c37fe: /* original 31ec, guest PC 0x0c0c37fe */
if(!s->budget--) { s->failed_pc=0x0c0c37feu; return 0; }
r[1]+=r[14];
goto P_0c0c3800;
P_0c0c3800: /* original 2120, guest PC 0x0c0c3800 */
if(!s->budget--) { s->failed_pc=0x0c0c3800u; return 0; }
write(ram,r[1],r[2],1);
goto P_0c0c3802;
P_0c0c3802: /* original 0324, guest PC 0x0c0c3802 */
if(!s->budget--) { s->failed_pc=0x0c0c3802u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c0c3804;
P_0c0c3804: /* original e06c, guest PC 0x0c0c3804 */
if(!s->budget--) { s->failed_pc=0x0c0c3804u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c3806;
P_0c0c3806: /* original 00ee, guest PC 0x0c0c3806 */
if(!s->budget--) { s->failed_pc=0x0c0c3806u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c3808;
P_0c0c3808: /* original 8806, guest PC 0x0c0c3808 */
if(!s->budget--) { s->failed_pc=0x0c0c3808u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c380a;
P_0c0c380a: /* original 8902, guest PC 0x0c0c380a */
if(!s->budget--) { s->failed_pc=0x0c0c380au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3812; }
goto P_0c0c380c;
P_0c0c380c: /* original 65b3, guest PC 0x0c0c380c */
if(!s->budget--) { s->failed_pc=0x0c0c380cu; return 0; }
r[5]=r[11];
goto P_0c0c380e;
P_0c0c380e: /* original b05a, guest PC 0x0c0c380e */
if(!s->budget--) { s->failed_pc=0x0c0c380eu; return 0; }
target=0x0c0c38c6u; r[16]=0x0c0c3812u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3812u) { target=s->pc; goto dispatch; }
goto P_0c0c3812;
P_0c0c3810: /* original 64e3, guest PC 0x0c0c3810 */
if(!s->budget--) { s->failed_pc=0x0c0c3810u; return 0; }
r[4]=r[14];
goto P_0c0c3812;
P_0c0c3812: /* original 53f1, guest PC 0x0c0c3812 */
if(!s->budget--) { s->failed_pc=0x0c0c3812u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c3814;
P_0c0c3814: /* original 7301, guest PC 0x0c0c3814 */
if(!s->budget--) { s->failed_pc=0x0c0c3814u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c3816;
P_0c0c3816: /* original 1f31, guest PC 0x0c0c3816 */
if(!s->budget--) { s->failed_pc=0x0c0c3816u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c3818;
P_0c0c3818: /* original 52f6, guest PC 0x0c0c3818 */
if(!s->budget--) { s->failed_pc=0x0c0c3818u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0c381a;
P_0c0c381a: /* original 3322, guest PC 0x0c0c381a */
if(!s->budget--) { s->failed_pc=0x0c0c381au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0c381c;
P_0c0c381c: /* original 890c, guest PC 0x0c0c381c */
if(!s->budget--) { s->failed_pc=0x0c0c381cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3838; }
goto P_0c0c381e;
P_0c0c381e: /* original 52f1, guest PC 0x0c0c381e */
if(!s->budget--) { s->failed_pc=0x0c0c381eu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c3820;
P_0c0c3820: /* original 53f2, guest PC 0x0c0c3820 */
if(!s->budget--) { s->failed_pc=0x0c0c3820u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c3822;
P_0c0c3822: /* original 2320, guest PC 0x0c0c3822 */
if(!s->budget--) { s->failed_pc=0x0c0c3822u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0c3824;
P_0c0c3824: /* original aea4, guest PC 0x0c0c3824 */
if(!s->budget--) { s->failed_pc=0x0c0c3824u; return 0; }
goto P_0c0c3570;
P_0c0c3826: /* original 0009, guest PC 0x0c0c3826 */
if(!s->budget--) { s->failed_pc=0x0c0c3826u; return 0; }
return vf3_matrix_family(0x0c0c3828u,s,ram);
P_0c0c3838: /* original 60e2, guest PC 0x0c0c3838 */
if(!s->budget--) { s->failed_pc=0x0c0c3838u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c383a;
P_0c0c383a: /* original cb08, guest PC 0x0c0c383a */
if(!s->budget--) { s->failed_pc=0x0c0c383au; return 0; }
r[0]|=8u;
goto P_0c0c383c;
P_0c0c383c: /* original 2e02, guest PC 0x0c0c383c */
if(!s->budget--) { s->failed_pc=0x0c0c383cu; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0c383e;
P_0c0c383e: /* original b085, guest PC 0x0c0c383e */
if(!s->budget--) { s->failed_pc=0x0c0c383eu; return 0; }
target=0x0c0c394cu; r[16]=0x0c0c3842u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3842u) { target=s->pc; goto dispatch; }
goto P_0c0c3842;
P_0c0c3840: /* original 0009, guest PC 0x0c0c3840 */
if(!s->budget--) { s->failed_pc=0x0c0c3840u; return 0; }
goto P_0c0c3842;
P_0c0c3842: /* original 84e4, guest PC 0x0c0c3842 */
if(!s->budget--) { s->failed_pc=0x0c0c3842u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3844;
P_0c0c3844: /* original 9470, guest PC 0x0c0c3844 */
if(!s->budget--) { s->failed_pc=0x0c0c3844u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3928u,2);
goto P_0c0c3846;
P_0c0c3846: /* original 600c, guest PC 0x0c0c3846 */
if(!s->budget--) { s->failed_pc=0x0c0c3846u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c3848;
P_0c0c3848: /* original 6303, guest PC 0x0c0c3848 */
if(!s->budget--) { s->failed_pc=0x0c0c3848u; return 0; }
r[3]=r[0];
goto P_0c0c384a;
P_0c0c384a: /* original 4008, guest PC 0x0c0c384a */
if(!s->budget--) { s->failed_pc=0x0c0c384au; return 0; }
r[0]<<=2;
goto P_0c0c384c;
P_0c0c384c: /* original 34dc, guest PC 0x0c0c384c */
if(!s->budget--) { s->failed_pc=0x0c0c384cu; return 0; }
r[4]+=r[13];
goto P_0c0c384e;
P_0c0c384e: /* original 303c, guest PC 0x0c0c384e */
if(!s->budget--) { s->failed_pc=0x0c0c384eu; return 0; }
r[0]+=r[3];
goto P_0c0c3850;
P_0c0c3850: /* original 044c, guest PC 0x0c0c3850 */
if(!s->budget--) { s->failed_pc=0x0c0c3850u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c3852;
P_0c0c3852: /* original e068, guest PC 0x0c0c3852 */
if(!s->budget--) { s->failed_pc=0x0c0c3852u; return 0; }
r[0]=0x00000068u;
goto P_0c0c3854;
P_0c0c3854: /* original 0e44, guest PC 0x0c0c3854 */
if(!s->budget--) { s->failed_pc=0x0c0c3854u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c3856;
P_0c0c3856: /* original b094, guest PC 0x0c0c3856 */
if(!s->budget--) { s->failed_pc=0x0c0c3856u; return 0; }
target=0x0c0c3982u; r[16]=0x0c0c385au;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c385au) { target=s->pc; goto dispatch; }
goto P_0c0c385a;
P_0c0c3858: /* original 64b3, guest PC 0x0c0c3858 */
if(!s->budget--) { s->failed_pc=0x0c0c3858u; return 0; }
r[4]=r[11];
goto P_0c0c385a;
P_0c0c385a: /* original d235, guest PC 0x0c0c385a */
if(!s->budget--) { s->failed_pc=0x0c0c385au; return 0; }
r[2]=read(ram,0x0c0c3930u,4);
goto P_0c0c385c;
P_0c0c385c: /* original 420b, guest PC 0x0c0c385c */
if(!s->budget--) { s->failed_pc=0x0c0c385cu; return 0; }
target=r[2];
r[16]=0x0c0c3860u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3860u) { target=s->pc; goto dispatch; }
goto P_0c0c3860;
P_0c0c385e: /* original 64b3, guest PC 0x0c0c385e */
if(!s->budget--) { s->failed_pc=0x0c0c385eu; return 0; }
r[4]=r[11];
goto P_0c0c3860;
P_0c0c3860: /* original 63f2, guest PC 0x0c0c3860 */
if(!s->budget--) { s->failed_pc=0x0c0c3860u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c3862;
P_0c0c3862: /* original e033, guest PC 0x0c0c3862 */
if(!s->budget--) { s->failed_pc=0x0c0c3862u; return 0; }
r[0]=0x00000033u;
goto P_0c0c3864;
P_0c0c3864: /* original a025, guest PC 0x0c0c3864 */
if(!s->budget--) { s->failed_pc=0x0c0c3864u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c38b2;
P_0c0c3866: /* original 0e34, guest PC 0x0c0c3866 */
if(!s->budget--) { s->failed_pc=0x0c0c3866u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c3868;
P_0c0c3868: /* original 60c3, guest PC 0x0c0c3868 */
if(!s->budget--) { s->failed_pc=0x0c0c3868u; return 0; }
r[0]=r[12];
goto P_0c0c386a;
P_0c0c386a: /* original 8809, guest PC 0x0c0c386a */
if(!s->budget--) { s->failed_pc=0x0c0c386au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c386c;
P_0c0c386c: /* original 8902, guest PC 0x0c0c386c */
if(!s->budget--) { s->failed_pc=0x0c0c386cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3874; }
goto P_0c0c386e;
P_0c0c386e: /* original 60c3, guest PC 0x0c0c386e */
if(!s->budget--) { s->failed_pc=0x0c0c386eu; return 0; }
r[0]=r[12];
goto P_0c0c3870;
P_0c0c3870: /* original 8816, guest PC 0x0c0c3870 */
if(!s->budget--) { s->failed_pc=0x0c0c3870u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c0c3872;
P_0c0c3872: /* original 8b11, guest PC 0x0c0c3872 */
if(!s->budget--) { s->failed_pc=0x0c0c3872u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3898; }
goto P_0c0c3874;
P_0c0c3874: /* original 9059, guest PC 0x0c0c3874 */
if(!s->budget--) { s->failed_pc=0x0c0c3874u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c392au,2);
goto P_0c0c3876;
P_0c0c3876: /* original d32f, guest PC 0x0c0c3876 */
if(!s->budget--) { s->failed_pc=0x0c0c3876u; return 0; }
r[3]=read(ram,0x0c0c3934u,4);
goto P_0c0c3878;
P_0c0c3878: /* original 04ae, guest PC 0x0c0c3878 */
if(!s->budget--) { s->failed_pc=0x0c0c3878u; return 0; }
r[4]=read(ram,r[10]+r[0],4);
goto P_0c0c387a;
P_0c0c387a: /* original 2438, guest PC 0x0c0c387a */
if(!s->budget--) { s->failed_pc=0x0c0c387au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c387c;
P_0c0c387c: /* original 8d03, guest PC 0x0c0c387c */
if(!s->budget--) { s->failed_pc=0x0c0c387cu; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
if(cond) { goto P_0c0c3886; }
goto P_0c0c3880;
P_0c0c387e: /* original 84e4, guest PC 0x0c0c387e */
if(!s->budget--) { s->failed_pc=0x0c0c387eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3880;
P_0c0c3880: /* original e416, guest PC 0x0c0c3880 */
if(!s->budget--) { s->failed_pc=0x0c0c3880u; return 0; }
r[4]=0x00000016u;
goto P_0c0c3882;
P_0c0c3882: /* original a002, guest PC 0x0c0c3882 */
if(!s->budget--) { s->failed_pc=0x0c0c3882u; return 0; }
r[5]=0x00000009u;
goto P_0c0c388a;
P_0c0c3884: /* original e509, guest PC 0x0c0c3884 */
if(!s->budget--) { s->failed_pc=0x0c0c3884u; return 0; }
r[5]=0x00000009u;
goto P_0c0c3886;
P_0c0c3886: /* original e516, guest PC 0x0c0c3886 */
if(!s->budget--) { s->failed_pc=0x0c0c3886u; return 0; }
r[5]=0x00000016u;
goto P_0c0c3888;
P_0c0c3888: /* original e409, guest PC 0x0c0c3888 */
if(!s->budget--) { s->failed_pc=0x0c0c3888u; return 0; }
r[4]=0x00000009u;
goto P_0c0c388a;
P_0c0c388a: /* original 2008, guest PC 0x0c0c388a */
if(!s->budget--) { s->failed_pc=0x0c0c388au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c388c;
P_0c0c388c: /* original 8f02, guest PC 0x0c0c388c */
if(!s->budget--) { s->failed_pc=0x0c0c388cu; return 0; }
cond=r[17]&1u;
r[0]=0x00000032u;
if(!cond) { goto P_0c0c3894; }
goto P_0c0c3890;
P_0c0c388e: /* original e032, guest PC 0x0c0c388e */
if(!s->budget--) { s->failed_pc=0x0c0c388eu; return 0; }
r[0]=0x00000032u;
goto P_0c0c3890;
P_0c0c3890: /* original a001, guest PC 0x0c0c3890 */
if(!s->budget--) { s->failed_pc=0x0c0c3890u; return 0; }
r[6]=r[4];
goto P_0c0c3896;
P_0c0c3892: /* original 6643, guest PC 0x0c0c3892 */
if(!s->budget--) { s->failed_pc=0x0c0c3892u; return 0; }
r[6]=r[4];
goto P_0c0c3894;
P_0c0c3894: /* original 6653, guest PC 0x0c0c3894 */
if(!s->budget--) { s->failed_pc=0x0c0c3894u; return 0; }
r[6]=r[5];
goto P_0c0c3896;
P_0c0c3896: /* original 0e64, guest PC 0x0c0c3896 */
if(!s->budget--) { s->failed_pc=0x0c0c3896u; return 0; }
write(ram,r[14]+r[0],r[6],1);
goto P_0c0c3898;
P_0c0c3898: /* original b073, guest PC 0x0c0c3898 */
if(!s->budget--) { s->failed_pc=0x0c0c3898u; return 0; }
target=0x0c0c3982u; r[16]=0x0c0c389cu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c389cu) { target=s->pc; goto dispatch; }
goto P_0c0c389c;
P_0c0c389a: /* original 64b3, guest PC 0x0c0c389a */
if(!s->budget--) { s->failed_pc=0x0c0c389au; return 0; }
r[4]=r[11];
goto P_0c0c389c;
P_0c0c389c: /* original d224, guest PC 0x0c0c389c */
if(!s->budget--) { s->failed_pc=0x0c0c389cu; return 0; }
r[2]=read(ram,0x0c0c3930u,4);
goto P_0c0c389e;
P_0c0c389e: /* original 420b, guest PC 0x0c0c389e */
if(!s->budget--) { s->failed_pc=0x0c0c389eu; return 0; }
target=r[2];
r[16]=0x0c0c38a2u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c38a2u) { target=s->pc; goto dispatch; }
goto P_0c0c38a2;
P_0c0c38a0: /* original 64b3, guest PC 0x0c0c38a0 */
if(!s->budget--) { s->failed_pc=0x0c0c38a0u; return 0; }
r[4]=r[11];
goto P_0c0c38a2;
P_0c0c38a2: /* original 60e2, guest PC 0x0c0c38a2 */
if(!s->budget--) { s->failed_pc=0x0c0c38a2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c38a4;
P_0c0c38a4: /* original cb08, guest PC 0x0c0c38a4 */
if(!s->budget--) { s->failed_pc=0x0c0c38a4u; return 0; }
r[0]|=8u;
goto P_0c0c38a6;
P_0c0c38a6: /* original 2e02, guest PC 0x0c0c38a6 */
if(!s->budget--) { s->failed_pc=0x0c0c38a6u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0c38a8;
P_0c0c38a8: /* original e033, guest PC 0x0c0c38a8 */
if(!s->budget--) { s->failed_pc=0x0c0c38a8u; return 0; }
r[0]=0x00000033u;
goto P_0c0c38aa;
P_0c0c38aa: /* original d223, guest PC 0x0c0c38aa */
if(!s->budget--) { s->failed_pc=0x0c0c38aau; return 0; }
r[2]=read(ram,0x0c0c3938u,4);
goto P_0c0c38ac;
P_0c0c38ac: /* original 63f2, guest PC 0x0c0c38ac */
if(!s->budget--) { s->failed_pc=0x0c0c38acu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c38ae;
P_0c0c38ae: /* original 420b, guest PC 0x0c0c38ae */
if(!s->budget--) { s->failed_pc=0x0c0c38aeu; return 0; }
target=r[2];
r[16]=0x0c0c38b2u;
write(ram,r[14]+r[0],r[3],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c38b2u) { target=s->pc; goto dispatch; }
goto P_0c0c38b2;
P_0c0c38b0: /* original 0e34, guest PC 0x0c0c38b0 */
if(!s->budget--) { s->failed_pc=0x0c0c38b0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c38b2;
P_0c0c38b2: /* original 7f28, guest PC 0x0c0c38b2 */
if(!s->budget--) { s->failed_pc=0x0c0c38b2u; return 0; }
r[15]+=0x00000028u;
goto P_0c0c38b4;
P_0c0c38b4: /* original 4f26, guest PC 0x0c0c38b4 */
if(!s->budget--) { s->failed_pc=0x0c0c38b4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c38b6;
P_0c0c38b6: /* original 68f6, guest PC 0x0c0c38b6 */
if(!s->budget--) { s->failed_pc=0x0c0c38b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c38b8;
P_0c0c38b8: /* original 69f6, guest PC 0x0c0c38b8 */
if(!s->budget--) { s->failed_pc=0x0c0c38b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c38ba;
P_0c0c38ba: /* original 6af6, guest PC 0x0c0c38ba */
if(!s->budget--) { s->failed_pc=0x0c0c38bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c38bc;
P_0c0c38bc: /* original 6bf6, guest PC 0x0c0c38bc */
if(!s->budget--) { s->failed_pc=0x0c0c38bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c38be;
P_0c0c38be: /* original 6cf6, guest PC 0x0c0c38be */
if(!s->budget--) { s->failed_pc=0x0c0c38beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c38c0;
P_0c0c38c0: /* original 6df6, guest PC 0x0c0c38c0 */
if(!s->budget--) { s->failed_pc=0x0c0c38c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c38c2;
P_0c0c38c2: /* original 000b, guest PC 0x0c0c38c2 */
if(!s->budget--) { s->failed_pc=0x0c0c38c2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c38c4: /* original 6ef6, guest PC 0x0c0c38c4 */
if(!s->budget--) { s->failed_pc=0x0c0c38c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c38c6u,s,ram);
P_0c0c4b7e: /* original d422, guest PC 0x0c0c4b7e */
if(!s->budget--) { s->failed_pc=0x0c0c4b7eu; return 0; }
r[4]=read(ram,0x0c0c4c08u,4);
goto P_0c0c4b80;
P_0c0c4b80: /* original 5042, guest PC 0x0c0c4b80 */
if(!s->budget--) { s->failed_pc=0x0c0c4b80u; return 0; }
r[0]=read(ram,r[4]+8,4);
goto P_0c0c4b82;
P_0c0c4b82: /* original c804, guest PC 0x0c0c4b82 */
if(!s->budget--) { s->failed_pc=0x0c0c4b82u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0c4b84;
P_0c0c4b84: /* original 8d01, guest PC 0x0c0c4b84 */
if(!s->budget--) { s->failed_pc=0x0c0c4b84u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(cond) { goto P_0c0c4b8a; }
goto P_0c0c4b88;
P_0c0c4b86: /* original e500, guest PC 0x0c0c4b86 */
if(!s->budget--) { s->failed_pc=0x0c0c4b86u; return 0; }
r[5]=0x00000000u;
goto P_0c0c4b88;
P_0c0c4b88: /* original e5ff, guest PC 0x0c0c4b88 */
if(!s->budget--) { s->failed_pc=0x0c0c4b88u; return 0; }
r[5]=0xffffffffu;
goto P_0c0c4b8a;
P_0c0c4b8a: /* original 9030, guest PC 0x0c0c4b8a */
if(!s->budget--) { s->failed_pc=0x0c0c4b8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4beeu,2);
goto P_0c0c4b8c;
P_0c0c4b8c: /* original 000b, guest PC 0x0c0c4b8c */
if(!s->budget--) { s->failed_pc=0x0c0c4b8cu; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[5],4);
s->pc=target; return ram->oob==0;
P_0c0c4b8e: /* original 0456, guest PC 0x0c0c4b8e */
if(!s->budget--) { s->failed_pc=0x0c0c4b8eu; return 0; }
write(ram,r[4]+r[0],r[5],4);
return vf3_matrix_family(0x0c0c4b90u,s,ram);
P_0c0c4c60: /* original 904f, guest PC 0x0c0c4c60 */
if(!s->budget--) { s->failed_pc=0x0c0c4c60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4d02u,2);
goto P_0c0c4c62;
P_0c0c4c62: /* original e563, guest PC 0x0c0c4c62 */
if(!s->budget--) { s->failed_pc=0x0c0c4c62u; return 0; }
r[5]=0x00000063u;
goto P_0c0c4c64;
P_0c0c4c64: /* original d429, guest PC 0x0c0c4c64 */
if(!s->budget--) { s->failed_pc=0x0c0c4c64u; return 0; }
r[4]=read(ram,0x0c0c4d0cu,4);
goto P_0c0c4c66;
P_0c0c4c66: /* original e302, guest PC 0x0c0c4c66 */
if(!s->budget--) { s->failed_pc=0x0c0c4c66u; return 0; }
r[3]=0x00000002u;
goto P_0c0c4c68;
P_0c0c4c68: /* original 0454, guest PC 0x0c0c4c68 */
if(!s->budget--) { s->failed_pc=0x0c0c4c68u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4c6a;
P_0c0c4c6a: /* original 7001, guest PC 0x0c0c4c6a */
if(!s->budget--) { s->failed_pc=0x0c0c4c6au; return 0; }
r[0]+=0x00000001u;
goto P_0c0c4c6c;
P_0c0c4c6c: /* original 0454, guest PC 0x0c0c4c6c */
if(!s->budget--) { s->failed_pc=0x0c0c4c6cu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4c6e;
P_0c0c4c6e: /* original 7001, guest PC 0x0c0c4c6e */
if(!s->budget--) { s->failed_pc=0x0c0c4c6eu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c4c70;
P_0c0c4c70: /* original 0454, guest PC 0x0c0c4c70 */
if(!s->budget--) { s->failed_pc=0x0c0c4c70u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4c72;
P_0c0c4c72: /* original 7001, guest PC 0x0c0c4c72 */
if(!s->budget--) { s->failed_pc=0x0c0c4c72u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c4c74;
P_0c0c4c74: /* original 0454, guest PC 0x0c0c4c74 */
if(!s->budget--) { s->failed_pc=0x0c0c4c74u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4c76;
P_0c0c4c76: /* original 7001, guest PC 0x0c0c4c76 */
if(!s->budget--) { s->failed_pc=0x0c0c4c76u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c4c78;
P_0c0c4c78: /* original 0454, guest PC 0x0c0c4c78 */
if(!s->budget--) { s->failed_pc=0x0c0c4c78u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4c7a;
P_0c0c4c7a: /* original 7001, guest PC 0x0c0c4c7a */
if(!s->budget--) { s->failed_pc=0x0c0c4c7au; return 0; }
r[0]+=0x00000001u;
goto P_0c0c4c7c;
P_0c0c4c7c: /* original 0454, guest PC 0x0c0c4c7c */
if(!s->budget--) { s->failed_pc=0x0c0c4c7cu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4c7e;
P_0c0c4c7e: /* original 7001, guest PC 0x0c0c4c7e */
if(!s->budget--) { s->failed_pc=0x0c0c4c7eu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c4c80;
P_0c0c4c80: /* original 0454, guest PC 0x0c0c4c80 */
if(!s->budget--) { s->failed_pc=0x0c0c4c80u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4c82;
P_0c0c4c82: /* original 7001, guest PC 0x0c0c4c82 */
if(!s->budget--) { s->failed_pc=0x0c0c4c82u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c4c84;
P_0c0c4c84: /* original 0454, guest PC 0x0c0c4c84 */
if(!s->budget--) { s->failed_pc=0x0c0c4c84u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4c86;
P_0c0c4c86: /* original 70d4, guest PC 0x0c0c4c86 */
if(!s->budget--) { s->failed_pc=0x0c0c4c86u; return 0; }
r[0]+=0xffffffd4u;
goto P_0c0c4c88;
P_0c0c4c88: /* original 000b, guest PC 0x0c0c4c88 */
if(!s->budget--) { s->failed_pc=0x0c0c4c88u; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[3],1);
s->pc=target; return ram->oob==0;
P_0c0c4c8a: /* original 0434, guest PC 0x0c0c4c8a */
if(!s->budget--) { s->failed_pc=0x0c0c4c8au; return 0; }
write(ram,r[4]+r[0],r[3],1);
return vf3_matrix_family(0x0c0c4c8cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c07abf8u,0x0c07abfau,0x0c07abfcu,0x0c07abfeu,0x0c07ac00u,0x0c07ac02u,0x0c07ac04u,0x0c07ac06u,0x0c07ac08u,0x0c07ac0au,0x0c07ac0cu,0x0c07ac0eu,0x0c07ac10u,0x0c07ac12u,0x0c07ac14u,0x0c07ac16u,
0x0c07ac18u,0x0c07ac1au,0x0c07ac1cu,0x0c07ac1eu,0x0c07ac20u,0x0c07ac22u,0x0c07ac24u,0x0c07ac26u,0x0c09befcu,0x0c09befeu,0x0c09bf00u,0x0c09bf02u,0x0c09bf04u,0x0c09bf06u,0x0c09bf08u,0x0c09bf0au,
0x0c09bf0cu,0x0c09bf0eu,0x0c09bf10u,0x0c09bf12u,0x0c09bf14u,0x0c09bf16u,0x0c09bf18u,0x0c09bf1au,0x0c09bf1cu,0x0c09bf1eu,0x0c09bf20u,0x0c09bf22u,0x0c09bf24u,0x0c09bf26u,0x0c09bf28u,0x0c09bf2au,
0x0c09bf2cu,0x0c09bf2eu,0x0c09bf30u,0x0c09bf32u,0x0c09bf34u,0x0c09bf36u,0x0c09bf38u,0x0c09bf3au,0x0c09bf3cu,0x0c09bf3eu,0x0c09bf40u,0x0c09bf42u,0x0c09bf44u,0x0c09bf46u,0x0c09bf48u,0x0c09bf4au,
0x0c09bf4cu,0x0c09bf4eu,0x0c09bf50u,0x0c09bf52u,0x0c09bf54u,0x0c09bf56u,0x0c09bf58u,0x0c09bf5au,0x0c09bf5cu,0x0c09bf5eu,0x0c09bf60u,0x0c09bf62u,0x0c09bf64u,0x0c09bf66u,0x0c09bf68u,0x0c09bf6au,
0x0c09bf6cu,0x0c09bf6eu,0x0c09bf70u,0x0c09bf72u,0x0c09bf74u,0x0c09bf76u,0x0c09bf78u,0x0c09bf7au,0x0c09bf7cu,0x0c09bf7eu,0x0c09bf80u,0x0c09bf82u,0x0c09bf84u,0x0c09bf86u,0x0c09bf88u,0x0c09bf8au,
0x0c09bf8cu,0x0c09bf8eu,0x0c09bf90u,0x0c09bf92u,0x0c09c044u,0x0c09c046u,0x0c09c048u,0x0c09c04au,0x0c09c04cu,0x0c09c04eu,0x0c09c050u,0x0c09c052u,0x0c09c054u,0x0c09c056u,0x0c09c058u,0x0c09c05au,
0x0c09c05cu,0x0c09c05eu,0x0c09c060u,0x0c09c062u,0x0c09c064u,0x0c09c066u,0x0c09c068u,0x0c09c06au,0x0c09c06cu,0x0c09c06eu,0x0c09c070u,0x0c09c072u,0x0c09c074u,0x0c09c076u,0x0c09c078u,0x0c09c07au,
0x0c09c07cu,0x0c09c07eu,0x0c09c080u,0x0c09c082u,0x0c09c084u,0x0c09c086u,0x0c09c088u,0x0c09c08au,0x0c09c08cu,0x0c09c08eu,0x0c09c090u,0x0c09c092u,0x0c09c094u,0x0c09c096u,0x0c09c098u,0x0c09c09au,
0x0c09c09cu,0x0c09c09eu,0x0c09c0a0u,0x0c09c0a2u,0x0c09c0a4u,0x0c09c0a6u,0x0c09c0a8u,0x0c09c0aau,0x0c09c0acu,0x0c09c0aeu,0x0c09c0b0u,0x0c09c0b2u,0x0c09c0b4u,0x0c09c0e4u,0x0c09c0e6u,0x0c09c0e8u,
0x0c09c0eau,0x0c09c0ecu,0x0c09c0eeu,0x0c09c0f0u,0x0c09c0f2u,0x0c09c0f4u,0x0c09c0f6u,0x0c09c0f8u,0x0c09c0fau,0x0c09c0fcu,0x0c09c0feu,0x0c09c100u,0x0c09c102u,0x0c09c104u,0x0c09c106u,0x0c09c108u,
0x0c09c10au,0x0c09c10cu,0x0c09c10eu,0x0c09c110u,0x0c09c112u,0x0c09c114u,0x0c09c116u,0x0c09c118u,0x0c09c11au,0x0c09c11cu,0x0c09c11eu,0x0c09c120u,0x0c09c122u,0x0c09c124u,0x0c09c126u,0x0c09c128u,
0x0c09c12au,0x0c09c12cu,0x0c09c12eu,0x0c09c130u,0x0c09c132u,0x0c09c134u,0x0c09c136u,0x0c09c138u,0x0c09c13au,0x0c09c13cu,0x0c09c13eu,0x0c09c140u,0x0c09c142u,0x0c09c144u,0x0c09c146u,0x0c09c148u,
0x0c09c14au,0x0c09c14cu,0x0c09c14eu,0x0c09c150u,0x0c09c152u,0x0c09c154u,0x0c09c156u,0x0c09c158u,0x0c09c15au,0x0c09c15cu,0x0c09c15eu,0x0c09c160u,0x0c09c162u,0x0c09c164u,0x0c09c166u,0x0c09c168u,
0x0c09c16au,0x0c09c16cu,0x0c09c16eu,0x0c09c170u,0x0c09c172u,0x0c09c174u,0x0c09c176u,0x0c09c178u,0x0c09c17au,0x0c09c17cu,0x0c09c17eu,0x0c09c180u,0x0c09c182u,0x0c09c184u,0x0c09c186u,0x0c09c188u,
0x0c09c18au,0x0c09c18cu,0x0c09c18eu,0x0c09c190u,0x0c09c192u,0x0c09c194u,0x0c09c196u,0x0c09c198u,0x0c09c19au,0x0c09c19cu,0x0c09c19eu,0x0c09c1a0u,0x0c09c1a2u,0x0c09c1a4u,0x0c09c1a6u,0x0c09c1a8u,
0x0c09c1aau,0x0c09c1acu,0x0c09c1aeu,0x0c09c1b0u,0x0c09c1b2u,0x0c09c1b4u,0x0c09c1b6u,0x0c09c1b8u,0x0c09c1bau,0x0c09c1bcu,0x0c09c1beu,0x0c09c1c0u,0x0c09c1c2u,0x0c09c1c4u,0x0c09c1c6u,0x0c09c1c8u,
0x0c09c1cau,0x0c09c1ccu,0x0c09c1ceu,0x0c09c1d0u,0x0c09c1d2u,0x0c09c1d4u,0x0c09c1d6u,0x0c09c1d8u,0x0c09c1dau,0x0c09c1dcu,0x0c09c1deu,0x0c09c1e0u,0x0c09c1e2u,0x0c09c1e4u,0x0c09c1e6u,0x0c09c1e8u,
0x0c09c1eau,0x0c09c1ecu,0x0c09c1eeu,0x0c09c1f0u,0x0c09c1f2u,0x0c09c1f4u,0x0c09c1f6u,0x0c09c1f8u,0x0c09c1fau,0x0c09c1fcu,0x0c09c1feu,0x0c09c200u,0x0c09c202u,0x0c09c204u,0x0c09c206u,0x0c09c208u,
0x0c09c20au,0x0c09c224u,0x0c09c226u,0x0c09c228u,0x0c09c22au,0x0c09c22cu,0x0c09c22eu,0x0c09c230u,0x0c09c232u,0x0c09c234u,0x0c09c236u,0x0c09c238u,0x0c09c23au,0x0c09c23cu,0x0c09c23eu,0x0c09c240u,
0x0c09c242u,0x0c09c244u,0x0c09c246u,0x0c09c248u,0x0c09c24au,0x0c09c24cu,0x0c09c24eu,0x0c09c250u,0x0c09c252u,0x0c09c254u,0x0c09c256u,0x0c09c258u,0x0c09c25au,0x0c09c25cu,0x0c09c25eu,0x0c09c260u,
0x0c09c262u,0x0c09c264u,0x0c09c266u,0x0c09c268u,0x0c09c26au,0x0c09c26cu,0x0c09c26eu,0x0c09c270u,0x0c09c272u,0x0c09c274u,0x0c09c276u,0x0c09c278u,0x0c09c27au,0x0c09c27cu,0x0c09c27eu,0x0c09c280u,
0x0c09c282u,0x0c09c284u,0x0c09c286u,0x0c09c288u,0x0c09c28au,0x0c09c28cu,0x0c09c28eu,0x0c09c290u,0x0c09c292u,0x0c09c294u,0x0c09c296u,0x0c09c298u,0x0c09c29au,0x0c09c29cu,0x0c09c29eu,0x0c09c2a0u,
0x0c09c2a2u,0x0c09c2a4u,0x0c09c2a6u,0x0c09c2a8u,0x0c09c2aau,0x0c09c2acu,0x0c09c2aeu,0x0c09c2b0u,0x0c09c2b2u,0x0c09c2b4u,0x0c09c2b6u,0x0c09c2b8u,0x0c09c2bau,0x0c09c2bcu,0x0c09c2beu,0x0c09c2c0u,
0x0c09c2c2u,0x0c09c2c4u,0x0c09c2c6u,0x0c09c2c8u,0x0c09c2cau,0x0c09c2ccu,0x0c09c2ceu,0x0c09c2d0u,0x0c09c2d2u,0x0c09c2d4u,0x0c09c2d6u,0x0c09c2d8u,0x0c09c2dau,0x0c09c2dcu,0x0c09c2deu,0x0c09c2e0u,
0x0c09c2e2u,0x0c09c2e4u,0x0c09c2e6u,0x0c09c2e8u,0x0c09c304u,0x0c09c306u,0x0c09c308u,0x0c09c30au,0x0c09c30cu,0x0c09c30eu,0x0c09c310u,0x0c09c312u,0x0c09c314u,0x0c09c316u,0x0c09c318u,0x0c09c31au,
0x0c09c31cu,0x0c09c31eu,0x0c09c320u,0x0c09c322u,0x0c09c324u,0x0c09c326u,0x0c09c328u,0x0c09c32au,0x0c09c32cu,0x0c09c32eu,0x0c09c330u,0x0c09c332u,0x0c09c334u,0x0c09c336u,0x0c09c338u,0x0c09c33au,
0x0c09c33cu,0x0c09c33eu,0x0c09c340u,0x0c09c342u,0x0c09c344u,0x0c09c346u,0x0c09c348u,0x0c09c34au,0x0c09c34cu,0x0c09c34eu,0x0c09c350u,0x0c09c352u,0x0c09c354u,0x0c09c356u,0x0c09c358u,0x0c09c35au,
0x0c09c35cu,0x0c09c35eu,0x0c09c360u,0x0c09c362u,0x0c09c364u,0x0c09c366u,0x0c09c368u,0x0c09c36au,0x0c09c36cu,0x0c09c36eu,0x0c09c370u,0x0c09c372u,0x0c09c374u,0x0c09c376u,0x0c09c378u,0x0c09c37au,
0x0c09c37cu,0x0c09c37eu,0x0c09c380u,0x0c09c382u,0x0c09c384u,0x0c09c386u,0x0c09c388u,0x0c09c38au,0x0c09c38cu,0x0c09c38eu,0x0c09c390u,0x0c09c392u,0x0c09c394u,0x0c09c396u,0x0c09c398u,0x0c09c39au,
0x0c09c39cu,0x0c09c39eu,0x0c09c3a0u,0x0c09c3a2u,0x0c09c3a4u,0x0c09c3a6u,0x0c09c3a8u,0x0c09c3aau,0x0c09c3acu,0x0c09c3aeu,0x0c09c3b0u,0x0c09c3b2u,0x0c09c3b4u,0x0c09c3b6u,0x0c09c3b8u,0x0c09c3bau,
0x0c09c3bcu,0x0c09c3beu,0x0c09c3c0u,0x0c09c3c2u,0x0c09c3c4u,0x0c09c3c6u,0x0c09c3c8u,0x0c09c3cau,0x0c09c3ccu,0x0c09c3ceu,0x0c09c3d0u,0x0c09c3d2u,0x0c09c3d4u,0x0c09c3d6u,0x0c09c3d8u,0x0c09c3dau,
0x0c09c3dcu,0x0c09c3deu,0x0c09c3e0u,0x0c09c3e2u,0x0c09c3e4u,0x0c09c3e6u,0x0c09c3e8u,0x0c09c3eau,0x0c09c3ecu,0x0c09c3eeu,0x0c09c3f0u,0x0c09c3f2u,0x0c09c3f4u,0x0c09c3f6u,0x0c09c3f8u,0x0c09c3fau,
0x0c09c3fcu,0x0c09c3feu,0x0c09c400u,0x0c09c402u,0x0c09c404u,0x0c09c406u,0x0c09c408u,0x0c09c40au,0x0c09c40cu,0x0c09c40eu,0x0c09c410u,0x0c09c412u,0x0c09c414u,0x0c09c416u,0x0c09c418u,0x0c09c41au,
0x0c09c41cu,0x0c09c41eu,0x0c09c420u,0x0c09c422u,0x0c09c424u,0x0c09c426u,0x0c09c428u,0x0c09c42au,0x0c09c42cu,0x0c09c42eu,0x0c09c430u,0x0c09c432u,0x0c09c434u,0x0c09c436u,0x0c09c438u,0x0c09c43au,
0x0c09c43cu,0x0c09c43eu,0x0c09c440u,0x0c09c442u,0x0c09c444u,0x0c09c446u,0x0c09c448u,0x0c09c458u,0x0c09c45au,0x0c09c45cu,0x0c09c45eu,0x0c09c460u,0x0c09c462u,0x0c09c464u,0x0c09c466u,0x0c09c468u,
0x0c09c46au,0x0c09c46cu,0x0c09c46eu,0x0c09c470u,0x0c09c472u,0x0c09c474u,0x0c09c476u,0x0c09c478u,0x0c09c47au,0x0c09c47cu,0x0c09c47eu,0x0c09c480u,0x0c09c482u,0x0c09c484u,0x0c09c486u,0x0c09c488u,
0x0c09c48au,0x0c09c48cu,0x0c09c48eu,0x0c09c490u,0x0c09c492u,0x0c09c494u,0x0c09c496u,0x0c09c498u,0x0c09c49au,0x0c09c49cu,0x0c09c49eu,0x0c09c4a0u,0x0c09c4a2u,0x0c09c4a4u,0x0c09c4a6u,0x0c09c4a8u,
0x0c09c4aau,0x0c09c4acu,0x0c09c4aeu,0x0c09c4b0u,0x0c09c4b2u,0x0c09c4b4u,0x0c09c4b6u,0x0c09c4b8u,0x0c09c4bau,0x0c09c4bcu,0x0c09c4beu,0x0c09c4c0u,0x0c09c4c2u,0x0c09c4c4u,0x0c09c4c6u,0x0c09c4c8u,
0x0c09c4cau,0x0c09c4ccu,0x0c09c4ceu,0x0c09c4d0u,0x0c09c4d2u,0x0c09c4d4u,0x0c09c4d6u,0x0c09c4d8u,0x0c09c4dau,0x0c09c4dcu,0x0c09c4deu,0x0c09c4e0u,0x0c09c4e2u,0x0c09c4e4u,0x0c09c4e6u,0x0c09c4e8u,
0x0c09c4eau,0x0c09c4ecu,0x0c09c4eeu,0x0c09c4f0u,0x0c09c4f2u,0x0c09c4f4u,0x0c09c4f6u,0x0c09c4f8u,0x0c09c4fau,0x0c09c4fcu,0x0c09c4feu,0x0c09c500u,0x0c09c502u,0x0c09c504u,0x0c09c506u,0x0c09c508u,
0x0c09c50au,0x0c09c50cu,0x0c09c50eu,0x0c09c510u,0x0c09c512u,0x0c09c514u,0x0c09c516u,0x0c09c518u,0x0c09c51au,0x0c09c51cu,0x0c09c51eu,0x0c09c520u,0x0c09c522u,0x0c09c524u,0x0c09c526u,0x0c09c528u,
0x0c09c52au,0x0c09c52cu,0x0c09c52eu,0x0c09c530u,0x0c09c532u,0x0c09c534u,0x0c09c536u,0x0c09c538u,0x0c09c53au,0x0c09c53cu,0x0c09c53eu,0x0c09c540u,0x0c09c542u,0x0c09c544u,0x0c09c546u,0x0c09c548u,
0x0c09c54au,0x0c09c54cu,0x0c09c54eu,0x0c09c550u,0x0c09c552u,0x0c09c554u,0x0c09c556u,0x0c09c558u,0x0c09c55au,0x0c09c568u,0x0c09c56au,0x0c09c56cu,0x0c09c56eu,0x0c09c570u,0x0c09c572u,0x0c09c574u,
0x0c09c576u,0x0c09c578u,0x0c09c57au,0x0c09c57cu,0x0c09c57eu,0x0c09c580u,0x0c09c582u,0x0c09c584u,0x0c09c586u,0x0c09c588u,0x0c09c58au,0x0c09c58cu,0x0c09c58eu,0x0c09c590u,0x0c09c592u,0x0c09c594u,
0x0c09c596u,0x0c09c598u,0x0c09c59au,0x0c09c59cu,0x0c09c59eu,0x0c09c5a0u,0x0c09c5a2u,0x0c09c5a4u,0x0c09c5a6u,0x0c09c5a8u,0x0c09c5aau,0x0c09c5acu,0x0c09c5aeu,0x0c09c5b0u,0x0c09c5b2u,0x0c09c5b4u,
0x0c09c5b6u,0x0c09c5b8u,0x0c09c5bau,0x0c09c5bcu,0x0c09c5beu,0x0c09c5c0u,0x0c09c5c2u,0x0c09c5c4u,0x0c09c5c6u,0x0c09c5c8u,0x0c09c5cau,0x0c09c5ccu,0x0c09c5ceu,0x0c09c5d0u,0x0c09c5d2u,0x0c09c5d4u,
0x0c09c5d6u,0x0c09c5d8u,0x0c09c5dau,0x0c09c5dcu,0x0c09c5deu,0x0c09c5e0u,0x0c09c5e2u,0x0c09c5e4u,0x0c09c5e6u,0x0c09c5e8u,0x0c09c5eau,0x0c09c5ecu,0x0c09c5eeu,0x0c09c5f0u,0x0c09c5f2u,0x0c09c5f4u,
0x0c09c5f6u,0x0c09c5f8u,0x0c09c5fau,0x0c09c5fcu,0x0c09c5feu,0x0c09c600u,0x0c09c602u,0x0c09c604u,0x0c09c606u,0x0c09c608u,0x0c09c60au,0x0c09c60cu,0x0c09c60eu,0x0c09c610u,0x0c09c612u,0x0c09c614u,
0x0c09c616u,0x0c09c618u,0x0c09c61au,0x0c09c61cu,0x0c09c61eu,0x0c09c620u,0x0c09c622u,0x0c09c624u,0x0c09c626u,0x0c09c628u,0x0c09c62au,0x0c09c62cu,0x0c09c62eu,0x0c09c630u,0x0c09c632u,0x0c09c634u,
0x0c09c636u,0x0c09c638u,0x0c09c63au,0x0c09c63cu,0x0c09c63eu,0x0c09c640u,0x0c09c642u,0x0c09c644u,0x0c09c646u,0x0c09c648u,0x0c09c64au,0x0c09c64cu,0x0c09c64eu,0x0c09c650u,0x0c09c652u,0x0c09c654u,
0x0c09c656u,0x0c09c658u,0x0c09c65au,0x0c09c65cu,0x0c09c65eu,0x0c09c660u,0x0c09c662u,0x0c09c664u,0x0c09c666u,0x0c09c668u,0x0c09c66au,0x0c09c66cu,0x0c09c66eu,0x0c09c67cu,0x0c09c67eu,0x0c09c680u,
0x0c09c682u,0x0c09c684u,0x0c09c686u,0x0c09c688u,0x0c09c68au,0x0c09c68cu,0x0c09c68eu,0x0c09c690u,0x0c09c692u,0x0c09c694u,0x0c09c696u,0x0c09c698u,0x0c09c69au,0x0c09c69cu,0x0c09c69eu,0x0c09c6a0u,
0x0c09c6a2u,0x0c09c6a4u,0x0c09c6a6u,0x0c09c6a8u,0x0c09c6aau,0x0c09c6acu,0x0c09c6aeu,0x0c09c6b0u,0x0c09c6b2u,0x0c09c6b4u,0x0c09c6b6u,0x0c09c6b8u,0x0c09c6bau,0x0c09c6bcu,0x0c09c6beu,0x0c09c6c0u,
0x0c09c6c2u,0x0c09c6c4u,0x0c09c6c6u,0x0c09c6c8u,0x0c09c6cau,0x0c09c6ccu,0x0c09c6ceu,0x0c09c6d0u,0x0c09c6d2u,0x0c09c6d4u,0x0c09c6d6u,0x0c09c6d8u,0x0c09c6dau,0x0c09c6dcu,0x0c09c6deu,0x0c09c6e0u,
0x0c09c6e2u,0x0c09c6e4u,0x0c09c6e6u,0x0c09c6e8u,0x0c09c6eau,0x0c09c6ecu,0x0c09c6eeu,0x0c09c6f0u,0x0c09c6f2u,0x0c09c6f4u,0x0c09c6f6u,0x0c09c6f8u,0x0c09c6fau,0x0c09c6fcu,0x0c09c6feu,0x0c09c700u,
0x0c09c702u,0x0c09c704u,0x0c09c706u,0x0c09c708u,0x0c09c70au,0x0c09c70cu,0x0c09c70eu,0x0c09c710u,0x0c09c712u,0x0c09c714u,0x0c09c716u,0x0c09c718u,0x0c09c71au,0x0c09c71cu,0x0c09c71eu,0x0c09c720u,
0x0c09c722u,0x0c09c724u,0x0c09c726u,0x0c09c728u,0x0c09c72au,0x0c09c72cu,0x0c09c72eu,0x0c09c730u,0x0c09c732u,0x0c09c734u,0x0c09c736u,0x0c09c738u,0x0c09c73au,0x0c09c73cu,0x0c09c73eu,0x0c09c740u,
0x0c09c742u,0x0c09c744u,0x0c09c746u,0x0c09c748u,0x0c09c74au,0x0c09c74cu,0x0c09c74eu,0x0c09c750u,0x0c09c752u,0x0c09c75cu,0x0c09c75eu,0x0c09c760u,0x0c09c762u,0x0c09c764u,0x0c09c766u,0x0c09c768u,
0x0c09c76au,0x0c09c76cu,0x0c09c76eu,0x0c09c770u,0x0c09c772u,0x0c09c774u,0x0c09c776u,0x0c09c778u,0x0c09c77au,0x0c09c77cu,0x0c09c77eu,0x0c09c780u,0x0c09c782u,0x0c09c784u,0x0c09c786u,0x0c09c788u,
0x0c09c78au,0x0c09c78cu,0x0c09c78eu,0x0c09c790u,0x0c09c792u,0x0c09c794u,0x0c09c796u,0x0c09c798u,0x0c09c79au,0x0c09c79cu,0x0c09c79eu,0x0c09c7a0u,0x0c09c7a2u,0x0c09c7a4u,0x0c09c7a6u,0x0c09c7a8u,
0x0c09c7aau,0x0c09c7acu,0x0c09c7aeu,0x0c09c7b0u,0x0c09c7b2u,0x0c09c7b4u,0x0c09c7b6u,0x0c09c7b8u,0x0c09c7bau,0x0c09c7bcu,0x0c09c7beu,0x0c09c7c0u,0x0c09c7c2u,0x0c09c7c4u,0x0c09c7c6u,0x0c09c7c8u,
0x0c09c7cau,0x0c09c7ccu,0x0c09c7ceu,0x0c09c7d0u,0x0c09c7d2u,0x0c09c7d4u,0x0c09c7d6u,0x0c09c7d8u,0x0c09c7dau,0x0c09c7dcu,0x0c09c7deu,0x0c09c7e0u,0x0c09c7e2u,0x0c09c7e4u,0x0c09c7e6u,0x0c09c7e8u,
0x0c09c7eau,0x0c09c7ecu,0x0c09c7eeu,0x0c09c7f0u,0x0c09c7f2u,0x0c09c7f4u,0x0c09c7f6u,0x0c09c7f8u,0x0c09c7fau,0x0c09c7fcu,0x0c09c7feu,0x0c09c800u,0x0c09c802u,0x0c09c804u,0x0c09c806u,0x0c09c808u,
0x0c09c80au,0x0c09c80cu,0x0c09c80eu,0x0c09c810u,0x0c09c812u,0x0c09c814u,0x0c09c816u,0x0c09c818u,0x0c09c81au,0x0c09c81cu,0x0c09c81eu,0x0c09c820u,0x0c09c822u,0x0c09c824u,0x0c09c826u,0x0c09c828u,
0x0c09c82au,0x0c09c82cu,0x0c09c82eu,0x0c09c830u,0x0c09c832u,0x0c09c834u,0x0c09c836u,0x0c09c838u,0x0c09c83au,0x0c09c83cu,0x0c09c83eu,0x0c09c840u,0x0c09c842u,0x0c09c844u,0x0c09c846u,0x0c09c848u,
0x0c09c84au,0x0c09c84cu,0x0c09c84eu,0x0c09c850u,0x0c09c852u,0x0c09c854u,0x0c09c856u,0x0c09c858u,0x0c09c85au,0x0c09c85cu,0x0c09c85eu,0x0c09c860u,0x0c09c862u,0x0c09c864u,0x0c09c866u,0x0c09c868u,
0x0c09c86au,0x0c09c86cu,0x0c09c86eu,0x0c09c870u,0x0c09c872u,0x0c09c874u,0x0c09c876u,0x0c09c878u,0x0c09c87au,0x0c09c87cu,0x0c09c87eu,0x0c09c880u,0x0c09c882u,0x0c09c884u,0x0c09c886u,0x0c09c888u,
0x0c09c88au,0x0c09c88cu,0x0c09c88eu,0x0c09c890u,0x0c09c892u,0x0c09c894u,0x0c09c896u,0x0c09c898u,0x0c09c89au,0x0c09c89cu,0x0c09c89eu,0x0c09c8a0u,0x0c09c8a2u,0x0c09c8a4u,0x0c09c8a6u,0x0c09c8a8u,
0x0c09c8aau,0x0c09c8acu,0x0c09c8b6u,0x0c09c8b8u,0x0c09c8bau,0x0c09c8bcu,0x0c09c8beu,0x0c09c8c0u,0x0c09c8c2u,0x0c09c8c4u,0x0c09c8c6u,0x0c09c8c8u,0x0c09c8cau,0x0c09c8ccu,0x0c09c8ceu,0x0c09c8d0u,
0x0c09c8d2u,0x0c09c8d4u,0x0c09c8d6u,0x0c09c8d8u,0x0c09c8dau,0x0c09c8dcu,0x0c09c8deu,0x0c09c8e0u,0x0c09c8e2u,0x0c09c8e4u,0x0c09c8e6u,0x0c09c8e8u,0x0c09c8eau,0x0c09c8ecu,0x0c09c8eeu,0x0c09c8f0u,
0x0c09c8f2u,0x0c09c8f4u,0x0c09c8f6u,0x0c09c8f8u,0x0c09c8fau,0x0c09c8fcu,0x0c09c8feu,0x0c09c900u,0x0c09c902u,0x0c09c904u,0x0c09c906u,0x0c09c908u,0x0c09c90au,0x0c09c90cu,0x0c09c90eu,0x0c09c910u,
0x0c09c912u,0x0c09c914u,0x0c09c916u,0x0c09c918u,0x0c09c91au,0x0c09c91cu,0x0c09c91eu,0x0c09c920u,0x0c09c922u,0x0c09c924u,0x0c09c926u,0x0c09c928u,0x0c09c92au,0x0c09c92cu,0x0c09c92eu,0x0c09c930u,
0x0c09c932u,0x0c09c934u,0x0c09c936u,0x0c09c938u,0x0c09c93au,0x0c09c93cu,0x0c09c942u,0x0c09c944u,0x0c09c946u,0x0c09c948u,0x0c09c94au,0x0c09c94cu,0x0c09c94eu,0x0c09c950u,0x0c09c952u,0x0c09c954u,
0x0c09c956u,0x0c09c958u,0x0c09c95au,0x0c09c95cu,0x0c09c95eu,0x0c09c960u,0x0c09c962u,0x0c09c964u,0x0c09c966u,0x0c09c968u,0x0c09c96au,0x0c09c96cu,0x0c09c96eu,0x0c09c970u,0x0c09c972u,0x0c09c974u,
0x0c09c976u,0x0c09c978u,0x0c09c97au,0x0c09c97cu,0x0c09c97eu,0x0c09c980u,0x0c09c982u,0x0c09c984u,0x0c09c986u,0x0c09c988u,0x0c09c98au,0x0c09c98cu,0x0c09c98eu,0x0c09c990u,0x0c09c992u,0x0c09c994u,
0x0c09c996u,0x0c09c998u,0x0c09c99au,0x0c09c99cu,0x0c09c99eu,0x0c09c9a0u,0x0c09c9a2u,0x0c09c9a4u,0x0c09c9a6u,0x0c09c9a8u,0x0c09c9aau,0x0c09c9acu,0x0c09c9aeu,0x0c09c9b0u,0x0c09c9b2u,0x0c09c9b4u,
0x0c09c9b6u,0x0c09c9b8u,0x0c09c9bau,0x0c09c9bcu,0x0c09c9beu,0x0c09c9c0u,0x0c09c9c2u,0x0c09c9c4u,0x0c09c9c6u,0x0c09c9c8u,0x0c09c9cau,0x0c09c9ccu,0x0c09c9ceu,0x0c09c9d0u,0x0c09c9d2u,0x0c09c9d4u,
0x0c09c9d6u,0x0c09c9d8u,0x0c09c9dau,0x0c09c9dcu,0x0c09c9deu,0x0c09c9e0u,0x0c09c9e2u,0x0c09c9e4u,0x0c09c9e6u,0x0c09c9e8u,0x0c09c9eau,0x0c09c9ecu,0x0c09c9eeu,0x0c09c9f0u,0x0c09c9f2u,0x0c09c9f4u,
0x0c09c9f6u,0x0c09c9f8u,0x0c09c9fau,0x0c09c9fcu,0x0c09c9feu,0x0c09ca00u,0x0c09ca02u,0x0c09ca04u,0x0c09ca06u,0x0c09ca08u,0x0c09ca0au,0x0c09ca0cu,0x0c09ca0eu,0x0c09ca10u,0x0c09ca12u,0x0c09ca14u,
0x0c09ca16u,0x0c09ca18u,0x0c09ca1au,0x0c09ca1cu,0x0c09ca1eu,0x0c09ca20u,0x0c09ca22u,0x0c09ca24u,0x0c09ca26u,0x0c09ca28u,0x0c09ca2au,0x0c09ca2cu,0x0c09ca2eu,0x0c09ca30u,0x0c09ca32u,0x0c09ca34u,
0x0c09ca36u,0x0c09ca38u,0x0c09ca3au,0x0c09ca3cu,0x0c09ca46u,0x0c09ca48u,0x0c09ca4au,0x0c09ca4cu,0x0c09ca4eu,0x0c09ca50u,0x0c09ca52u,0x0c09ca54u,0x0c09ca56u,0x0c09ca58u,0x0c09ca5au,0x0c09ca5cu,
0x0c09ca5eu,0x0c09ca60u,0x0c09ca62u,0x0c09ca64u,0x0c09ca66u,0x0c09ca68u,0x0c09ca6au,0x0c09ca6cu,0x0c09ca6eu,0x0c09ca70u,0x0c09ca72u,0x0c09ca74u,0x0c09ca76u,0x0c09ca78u,0x0c09ca7au,0x0c09ca7cu,
0x0c09ca7eu,0x0c09ca80u,0x0c09ca82u,0x0c09ca84u,0x0c09ca86u,0x0c09ca88u,0x0c09ca8au,0x0c0abcb8u,0x0c0abcbau,0x0c0abcbcu,0x0c0abcbeu,0x0c0abcc0u,0x0c0abcc2u,0x0c0abcc4u,0x0c0abcc6u,0x0c0abcc8u,
0x0c0abccau,0x0c0abcccu,0x0c0abcceu,0x0c0abcd0u,0x0c0abcd2u,0x0c0abcd4u,0x0c0abcd6u,0x0c0abcd8u,0x0c0abcdau,0x0c0abdc4u,0x0c0abdc6u,0x0c0abdc8u,0x0c0abdcau,0x0c0abdccu,0x0c0abdceu,0x0c0abdd0u,
0x0c0abdd2u,0x0c0abdd4u,0x0c0abdd6u,0x0c0abdd8u,0x0c0abddau,0x0c0abddcu,0x0c0abddeu,0x0c0abde0u,0x0c0abde2u,0x0c0abde4u,0x0c0abde6u,0x0c0abde8u,0x0c0abdeau,0x0c0abdecu,0x0c0abdeeu,0x0c0abdf0u,
0x0c0abdf2u,0x0c0abdf4u,0x0c0abdf6u,0x0c0abdf8u,0x0c0abdfau,0x0c0abe20u,0x0c0abe22u,0x0c0abe24u,0x0c0abe26u,0x0c0abe28u,0x0c0abe2au,0x0c0abe2cu,0x0c0abe2eu,0x0c0abe30u,0x0c0abe32u,0x0c0abe34u,
0x0c0abe36u,0x0c0abe38u,0x0c0abe3au,0x0c0abe3cu,0x0c0abe3eu,0x0c0abe40u,0x0c0abe42u,0x0c0abe44u,0x0c0abe46u,0x0c0abe48u,0x0c0abe4au,0x0c0abe4cu,0x0c0abe4eu,0x0c0c2f4eu,0x0c0c2f50u,0x0c0c2f52u,
0x0c0c2f54u,0x0c0c2f56u,0x0c0c2f58u,0x0c0c2f5au,0x0c0c2f5cu,0x0c0c2f5eu,0x0c0c2f60u,0x0c0c2f62u,0x0c0c2f64u,0x0c0c2f66u,0x0c0c2f68u,0x0c0c2f6au,0x0c0c2f6cu,0x0c0c2f6eu,0x0c0c2f70u,0x0c0c2f72u,
0x0c0c2f74u,0x0c0c2f76u,0x0c0c2f78u,0x0c0c2f7au,0x0c0c2f7cu,0x0c0c2f7eu,0x0c0c2f80u,0x0c0c2f82u,0x0c0c2f84u,0x0c0c2f86u,0x0c0c2f88u,0x0c0c2f8au,0x0c0c2f8cu,0x0c0c2f8eu,0x0c0c2f90u,0x0c0c2f92u,
0x0c0c2f94u,0x0c0c2f96u,0x0c0c2f98u,0x0c0c2f9au,0x0c0c2f9cu,0x0c0c2f9eu,0x0c0c2fa0u,0x0c0c2fa2u,0x0c0c2fa4u,0x0c0c2fa6u,0x0c0c2fa8u,0x0c0c2faau,0x0c0c2facu,0x0c0c2faeu,0x0c0c2fb0u,0x0c0c2fb2u,
0x0c0c2fb4u,0x0c0c2fb6u,0x0c0c2fb8u,0x0c0c2fbau,0x0c0c2fbcu,0x0c0c2fbeu,0x0c0c2fc0u,0x0c0c2fc2u,0x0c0c2fc4u,0x0c0c2fc6u,0x0c0c2fc8u,0x0c0c2fcau,0x0c0c2fccu,0x0c0c2fceu,0x0c0c2fd0u,0x0c0c2fd2u,
0x0c0c2fd4u,0x0c0c2fd6u,0x0c0c2fd8u,0x0c0c2fdau,0x0c0c2fdcu,0x0c0c2fdeu,0x0c0c2fe0u,0x0c0c2fe2u,0x0c0c2fe4u,0x0c0c2fe6u,0x0c0c2fe8u,0x0c0c2feau,0x0c0c2fecu,0x0c0c2feeu,0x0c0c2ff0u,0x0c0c2ff2u,
0x0c0c2ff4u,0x0c0c2ff6u,0x0c0c2ff8u,0x0c0c2ffau,0x0c0c2ffcu,0x0c0c2ffeu,0x0c0c3000u,0x0c0c3002u,0x0c0c3004u,0x0c0c3006u,0x0c0c3008u,0x0c0c300au,0x0c0c300cu,0x0c0c300eu,0x0c0c3010u,0x0c0c3012u,
0x0c0c3014u,0x0c0c3016u,0x0c0c3018u,0x0c0c301au,0x0c0c301cu,0x0c0c301eu,0x0c0c3020u,0x0c0c3022u,0x0c0c3024u,0x0c0c3026u,0x0c0c3028u,0x0c0c302au,0x0c0c304cu,0x0c0c304eu,0x0c0c3050u,0x0c0c3052u,
0x0c0c3054u,0x0c0c3056u,0x0c0c3058u,0x0c0c305au,0x0c0c305cu,0x0c0c305eu,0x0c0c3060u,0x0c0c3062u,0x0c0c3064u,0x0c0c3066u,0x0c0c3068u,0x0c0c306au,0x0c0c306cu,0x0c0c306eu,0x0c0c3070u,0x0c0c3072u,
0x0c0c3074u,0x0c0c3076u,0x0c0c3078u,0x0c0c307au,0x0c0c307cu,0x0c0c307eu,0x0c0c3080u,0x0c0c3082u,0x0c0c3084u,0x0c0c3086u,0x0c0c3088u,0x0c0c308au,0x0c0c308cu,0x0c0c308eu,0x0c0c3090u,0x0c0c3092u,
0x0c0c3094u,0x0c0c3096u,0x0c0c3098u,0x0c0c309au,0x0c0c309cu,0x0c0c309eu,0x0c0c30a0u,0x0c0c30a2u,0x0c0c30a4u,0x0c0c30a6u,0x0c0c30a8u,0x0c0c30aau,0x0c0c30acu,0x0c0c30aeu,0x0c0c30b0u,0x0c0c30b2u,
0x0c0c30b4u,0x0c0c30b6u,0x0c0c30b8u,0x0c0c30bau,0x0c0c30bcu,0x0c0c30beu,0x0c0c30c0u,0x0c0c30c2u,0x0c0c30c4u,0x0c0c30c6u,0x0c0c30c8u,0x0c0c30cau,0x0c0c30ccu,0x0c0c30ceu,0x0c0c30d0u,0x0c0c30d2u,
0x0c0c30d4u,0x0c0c30d6u,0x0c0c30d8u,0x0c0c30dau,0x0c0c30e8u,0x0c0c30eau,0x0c0c30ecu,0x0c0c30eeu,0x0c0c30f0u,0x0c0c30f2u,0x0c0c30f4u,0x0c0c30f6u,0x0c0c30f8u,0x0c0c30fau,0x0c0c30fcu,0x0c0c30feu,
0x0c0c3100u,0x0c0c3102u,0x0c0c3104u,0x0c0c3106u,0x0c0c3108u,0x0c0c310au,0x0c0c310cu,0x0c0c310eu,0x0c0c3110u,0x0c0c3112u,0x0c0c3114u,0x0c0c3116u,0x0c0c3118u,0x0c0c311au,0x0c0c311cu,0x0c0c311eu,
0x0c0c3120u,0x0c0c3122u,0x0c0c3124u,0x0c0c3126u,0x0c0c3128u,0x0c0c312au,0x0c0c312cu,0x0c0c312eu,0x0c0c3130u,0x0c0c3132u,0x0c0c3134u,0x0c0c3136u,0x0c0c3138u,0x0c0c313au,0x0c0c313cu,0x0c0c313eu,
0x0c0c3140u,0x0c0c3142u,0x0c0c3144u,0x0c0c3146u,0x0c0c3148u,0x0c0c314au,0x0c0c314cu,0x0c0c314eu,0x0c0c3150u,0x0c0c3152u,0x0c0c3154u,0x0c0c3156u,0x0c0c3158u,0x0c0c315au,0x0c0c315cu,0x0c0c315eu,
0x0c0c3160u,0x0c0c3162u,0x0c0c3164u,0x0c0c3166u,0x0c0c3168u,0x0c0c316au,0x0c0c316cu,0x0c0c316eu,0x0c0c3170u,0x0c0c3172u,0x0c0c3174u,0x0c0c3176u,0x0c0c3178u,0x0c0c317au,0x0c0c317cu,0x0c0c317eu,
0x0c0c3180u,0x0c0c3182u,0x0c0c3184u,0x0c0c3186u,0x0c0c3188u,0x0c0c318au,0x0c0c318cu,0x0c0c318eu,0x0c0c3190u,0x0c0c3192u,0x0c0c3194u,0x0c0c3196u,0x0c0c3198u,0x0c0c319au,0x0c0c319cu,0x0c0c319eu,
0x0c0c31a0u,0x0c0c31a2u,0x0c0c31a4u,0x0c0c31a6u,0x0c0c31a8u,0x0c0c31aau,0x0c0c31acu,0x0c0c31aeu,0x0c0c31b0u,0x0c0c31b2u,0x0c0c31b4u,0x0c0c31b6u,0x0c0c31b8u,0x0c0c31bau,0x0c0c31bcu,0x0c0c31beu,
0x0c0c31c0u,0x0c0c31c2u,0x0c0c31c4u,0x0c0c31c6u,0x0c0c31c8u,0x0c0c31cau,0x0c0c31ccu,0x0c0c31ceu,0x0c0c31d0u,0x0c0c31d2u,0x0c0c31d4u,0x0c0c31d6u,0x0c0c31d8u,0x0c0c31dau,0x0c0c31dcu,0x0c0c31deu,
0x0c0c31e0u,0x0c0c31e2u,0x0c0c31e4u,0x0c0c31e6u,0x0c0c31e8u,0x0c0c31eau,0x0c0c31ecu,0x0c0c31eeu,0x0c0c31f0u,0x0c0c31f2u,0x0c0c31f4u,0x0c0c3210u,0x0c0c3212u,0x0c0c3214u,0x0c0c3216u,0x0c0c3218u,
0x0c0c321au,0x0c0c321cu,0x0c0c321eu,0x0c0c3220u,0x0c0c3222u,0x0c0c3224u,0x0c0c3226u,0x0c0c3228u,0x0c0c322au,0x0c0c322cu,0x0c0c322eu,0x0c0c3230u,0x0c0c3232u,0x0c0c3234u,0x0c0c3236u,0x0c0c3238u,
0x0c0c323au,0x0c0c323cu,0x0c0c323eu,0x0c0c3240u,0x0c0c3242u,0x0c0c3244u,0x0c0c3246u,0x0c0c3248u,0x0c0c324au,0x0c0c324cu,0x0c0c324eu,0x0c0c3250u,0x0c0c3252u,0x0c0c3254u,0x0c0c3256u,0x0c0c3258u,
0x0c0c325au,0x0c0c325cu,0x0c0c325eu,0x0c0c3260u,0x0c0c3262u,0x0c0c3264u,0x0c0c3266u,0x0c0c3268u,0x0c0c326au,0x0c0c326cu,0x0c0c326eu,0x0c0c3270u,0x0c0c3272u,0x0c0c3274u,0x0c0c3276u,0x0c0c3278u,
0x0c0c327au,0x0c0c327cu,0x0c0c327eu,0x0c0c3280u,0x0c0c3282u,0x0c0c3284u,0x0c0c3286u,0x0c0c3288u,0x0c0c328au,0x0c0c328cu,0x0c0c328eu,0x0c0c3290u,0x0c0c3292u,0x0c0c3294u,0x0c0c3296u,0x0c0c3298u,
0x0c0c329au,0x0c0c329cu,0x0c0c329eu,0x0c0c32a0u,0x0c0c32a2u,0x0c0c32a4u,0x0c0c32a6u,0x0c0c32a8u,0x0c0c32aau,0x0c0c32acu,0x0c0c32aeu,0x0c0c32b0u,0x0c0c32b2u,0x0c0c32b4u,0x0c0c32b6u,0x0c0c32b8u,
0x0c0c32bau,0x0c0c32bcu,0x0c0c32beu,0x0c0c32c0u,0x0c0c32c2u,0x0c0c32c4u,0x0c0c32c6u,0x0c0c32c8u,0x0c0c32cau,0x0c0c32ccu,0x0c0c32ceu,0x0c0c32d0u,0x0c0c32d2u,0x0c0c32d4u,0x0c0c32d6u,0x0c0c32d8u,
0x0c0c32dau,0x0c0c32dcu,0x0c0c32deu,0x0c0c32e0u,0x0c0c32e2u,0x0c0c32e4u,0x0c0c32e6u,0x0c0c32e8u,0x0c0c32eau,0x0c0c32ecu,0x0c0c32eeu,0x0c0c32f0u,0x0c0c32f2u,0x0c0c32f4u,0x0c0c32f6u,0x0c0c32f8u,
0x0c0c32fau,0x0c0c32fcu,0x0c0c32feu,0x0c0c3300u,0x0c0c3302u,0x0c0c3304u,0x0c0c3306u,0x0c0c3308u,0x0c0c330au,0x0c0c330cu,0x0c0c330eu,0x0c0c3310u,0x0c0c3312u,0x0c0c3314u,0x0c0c3316u,0x0c0c3318u,
0x0c0c331au,0x0c0c3348u,0x0c0c334au,0x0c0c334cu,0x0c0c334eu,0x0c0c3350u,0x0c0c3352u,0x0c0c3354u,0x0c0c3356u,0x0c0c3358u,0x0c0c335au,0x0c0c335cu,0x0c0c335eu,0x0c0c3360u,0x0c0c3362u,0x0c0c3364u,
0x0c0c3366u,0x0c0c3368u,0x0c0c336au,0x0c0c336cu,0x0c0c336eu,0x0c0c3370u,0x0c0c3372u,0x0c0c3374u,0x0c0c3376u,0x0c0c3378u,0x0c0c337au,0x0c0c337cu,0x0c0c337eu,0x0c0c3380u,0x0c0c3382u,0x0c0c3384u,
0x0c0c3386u,0x0c0c3388u,0x0c0c338au,0x0c0c338cu,0x0c0c338eu,0x0c0c3390u,0x0c0c3392u,0x0c0c3394u,0x0c0c3396u,0x0c0c3398u,0x0c0c339au,0x0c0c339cu,0x0c0c339eu,0x0c0c33a0u,0x0c0c33a2u,0x0c0c33a4u,
0x0c0c33a6u,0x0c0c33a8u,0x0c0c33aau,0x0c0c33acu,0x0c0c33aeu,0x0c0c33b0u,0x0c0c33b2u,0x0c0c33b4u,0x0c0c33b6u,0x0c0c33b8u,0x0c0c33bau,0x0c0c33bcu,0x0c0c33beu,0x0c0c33c0u,0x0c0c33c2u,0x0c0c33c4u,
0x0c0c33c6u,0x0c0c33c8u,0x0c0c33cau,0x0c0c33ccu,0x0c0c33ceu,0x0c0c33d0u,0x0c0c33d2u,0x0c0c33d4u,0x0c0c33d6u,0x0c0c33d8u,0x0c0c33dau,0x0c0c33dcu,0x0c0c33deu,0x0c0c33e0u,0x0c0c33e2u,0x0c0c33e4u,
0x0c0c33e6u,0x0c0c33e8u,0x0c0c33eau,0x0c0c33ecu,0x0c0c33eeu,0x0c0c33f0u,0x0c0c33f2u,0x0c0c33f4u,0x0c0c33f6u,0x0c0c33f8u,0x0c0c33fau,0x0c0c33fcu,0x0c0c33feu,0x0c0c3400u,0x0c0c3402u,0x0c0c3404u,
0x0c0c3406u,0x0c0c3408u,0x0c0c340au,0x0c0c340cu,0x0c0c340eu,0x0c0c3410u,0x0c0c3412u,0x0c0c3414u,0x0c0c3420u,0x0c0c3422u,0x0c0c3424u,0x0c0c3426u,0x0c0c3428u,0x0c0c342au,0x0c0c342cu,0x0c0c342eu,
0x0c0c3430u,0x0c0c3432u,0x0c0c3434u,0x0c0c3436u,0x0c0c3438u,0x0c0c343au,0x0c0c343cu,0x0c0c343eu,0x0c0c3440u,0x0c0c3442u,0x0c0c3444u,0x0c0c3446u,0x0c0c3448u,0x0c0c344au,0x0c0c344cu,0x0c0c344eu,
0x0c0c3450u,0x0c0c3452u,0x0c0c3454u,0x0c0c3456u,0x0c0c3458u,0x0c0c345au,0x0c0c345cu,0x0c0c345eu,0x0c0c3460u,0x0c0c3462u,0x0c0c3464u,0x0c0c3466u,0x0c0c3468u,0x0c0c346au,0x0c0c346cu,0x0c0c346eu,
0x0c0c3470u,0x0c0c3472u,0x0c0c3474u,0x0c0c3476u,0x0c0c3478u,0x0c0c347au,0x0c0c347cu,0x0c0c347eu,0x0c0c3480u,0x0c0c3482u,0x0c0c3484u,0x0c0c3486u,0x0c0c3488u,0x0c0c348au,0x0c0c348cu,0x0c0c348eu,
0x0c0c3490u,0x0c0c3492u,0x0c0c3494u,0x0c0c3496u,0x0c0c3498u,0x0c0c349au,0x0c0c349cu,0x0c0c349eu,0x0c0c34a0u,0x0c0c34a2u,0x0c0c34a4u,0x0c0c34a6u,0x0c0c34a8u,0x0c0c34aau,0x0c0c34acu,0x0c0c34aeu,
0x0c0c34b0u,0x0c0c34b2u,0x0c0c34b4u,0x0c0c34b6u,0x0c0c34b8u,0x0c0c34bau,0x0c0c34bcu,0x0c0c34beu,0x0c0c34c0u,0x0c0c34c2u,0x0c0c34c4u,0x0c0c34c6u,0x0c0c34c8u,0x0c0c34cau,0x0c0c34ccu,0x0c0c34ceu,
0x0c0c34d0u,0x0c0c34d2u,0x0c0c34d4u,0x0c0c34d6u,0x0c0c34d8u,0x0c0c34dau,0x0c0c34dcu,0x0c0c34deu,0x0c0c34e0u,0x0c0c34e2u,0x0c0c34e4u,0x0c0c34e6u,0x0c0c34e8u,0x0c0c34eau,0x0c0c34ecu,0x0c0c34eeu,
0x0c0c34f0u,0x0c0c34f2u,0x0c0c34f4u,0x0c0c34f6u,0x0c0c34f8u,0x0c0c34fau,0x0c0c34fcu,0x0c0c34feu,0x0c0c3500u,0x0c0c3502u,0x0c0c3504u,0x0c0c3506u,0x0c0c3508u,0x0c0c350au,0x0c0c350cu,0x0c0c350eu,
0x0c0c3510u,0x0c0c3512u,0x0c0c3514u,0x0c0c3528u,0x0c0c352au,0x0c0c352cu,0x0c0c352eu,0x0c0c3530u,0x0c0c3532u,0x0c0c3534u,0x0c0c3536u,0x0c0c3538u,0x0c0c353au,0x0c0c353cu,0x0c0c353eu,0x0c0c3540u,
0x0c0c3542u,0x0c0c3544u,0x0c0c3546u,0x0c0c3548u,0x0c0c354au,0x0c0c354cu,0x0c0c354eu,0x0c0c3550u,0x0c0c3552u,0x0c0c3554u,0x0c0c3556u,0x0c0c3558u,0x0c0c355au,0x0c0c355cu,0x0c0c355eu,0x0c0c3560u,
0x0c0c3562u,0x0c0c3564u,0x0c0c3566u,0x0c0c3568u,0x0c0c356au,0x0c0c356cu,0x0c0c356eu,0x0c0c3570u,0x0c0c3572u,0x0c0c3574u,0x0c0c3576u,0x0c0c3578u,0x0c0c357au,0x0c0c357cu,0x0c0c357eu,0x0c0c3580u,
0x0c0c3582u,0x0c0c3584u,0x0c0c3586u,0x0c0c3588u,0x0c0c358au,0x0c0c358cu,0x0c0c358eu,0x0c0c3590u,0x0c0c3592u,0x0c0c3594u,0x0c0c3596u,0x0c0c3598u,0x0c0c359au,0x0c0c359cu,0x0c0c359eu,0x0c0c35a0u,
0x0c0c35a2u,0x0c0c35a4u,0x0c0c35a6u,0x0c0c35a8u,0x0c0c35aau,0x0c0c35acu,0x0c0c35aeu,0x0c0c35b0u,0x0c0c35b2u,0x0c0c35b4u,0x0c0c35b6u,0x0c0c35b8u,0x0c0c35bau,0x0c0c35bcu,0x0c0c35beu,0x0c0c35c0u,
0x0c0c35c2u,0x0c0c35c4u,0x0c0c35c6u,0x0c0c35c8u,0x0c0c35cau,0x0c0c35ccu,0x0c0c35ceu,0x0c0c35d0u,0x0c0c35d2u,0x0c0c35d4u,0x0c0c35d6u,0x0c0c35d8u,0x0c0c35dau,0x0c0c35dcu,0x0c0c35deu,0x0c0c35e0u,
0x0c0c35e2u,0x0c0c35e4u,0x0c0c35e6u,0x0c0c35e8u,0x0c0c35eau,0x0c0c35ecu,0x0c0c35eeu,0x0c0c35f0u,0x0c0c35f2u,0x0c0c35f4u,0x0c0c35f6u,0x0c0c35f8u,0x0c0c35fau,0x0c0c3610u,0x0c0c3612u,0x0c0c3614u,
0x0c0c3616u,0x0c0c3618u,0x0c0c361au,0x0c0c361cu,0x0c0c361eu,0x0c0c3620u,0x0c0c3622u,0x0c0c3624u,0x0c0c3626u,0x0c0c3628u,0x0c0c362au,0x0c0c362cu,0x0c0c362eu,0x0c0c3630u,0x0c0c3632u,0x0c0c3634u,
0x0c0c3636u,0x0c0c3638u,0x0c0c363au,0x0c0c363cu,0x0c0c363eu,0x0c0c3640u,0x0c0c3642u,0x0c0c3644u,0x0c0c3646u,0x0c0c3648u,0x0c0c364au,0x0c0c364cu,0x0c0c364eu,0x0c0c3650u,0x0c0c3652u,0x0c0c3654u,
0x0c0c3656u,0x0c0c3658u,0x0c0c365au,0x0c0c365cu,0x0c0c365eu,0x0c0c3660u,0x0c0c3662u,0x0c0c3664u,0x0c0c3666u,0x0c0c3668u,0x0c0c366au,0x0c0c366cu,0x0c0c366eu,0x0c0c3670u,0x0c0c3672u,0x0c0c3674u,
0x0c0c3676u,0x0c0c3678u,0x0c0c367au,0x0c0c367cu,0x0c0c367eu,0x0c0c3680u,0x0c0c3682u,0x0c0c3684u,0x0c0c3686u,0x0c0c3688u,0x0c0c368au,0x0c0c368cu,0x0c0c368eu,0x0c0c3690u,0x0c0c3692u,0x0c0c3694u,
0x0c0c3696u,0x0c0c3698u,0x0c0c369au,0x0c0c369cu,0x0c0c369eu,0x0c0c36a0u,0x0c0c36a2u,0x0c0c36a4u,0x0c0c36a6u,0x0c0c36a8u,0x0c0c36aau,0x0c0c36acu,0x0c0c36aeu,0x0c0c36b0u,0x0c0c36b2u,0x0c0c36b4u,
0x0c0c36b6u,0x0c0c36b8u,0x0c0c36bau,0x0c0c36bcu,0x0c0c36beu,0x0c0c36c0u,0x0c0c36c2u,0x0c0c36c4u,0x0c0c36c6u,0x0c0c36c8u,0x0c0c36cau,0x0c0c36ccu,0x0c0c36ceu,0x0c0c36d0u,0x0c0c36d2u,0x0c0c36d4u,
0x0c0c36d6u,0x0c0c36d8u,0x0c0c36dau,0x0c0c36dcu,0x0c0c36deu,0x0c0c36e0u,0x0c0c36e2u,0x0c0c36e4u,0x0c0c36e6u,0x0c0c36e8u,0x0c0c36eau,0x0c0c36ecu,0x0c0c36eeu,0x0c0c36f0u,0x0c0c36f2u,0x0c0c36f4u,
0x0c0c36f6u,0x0c0c36f8u,0x0c0c36fau,0x0c0c36fcu,0x0c0c3714u,0x0c0c3716u,0x0c0c3718u,0x0c0c371au,0x0c0c371cu,0x0c0c371eu,0x0c0c3720u,0x0c0c3722u,0x0c0c3724u,0x0c0c3726u,0x0c0c3728u,0x0c0c372au,
0x0c0c372cu,0x0c0c372eu,0x0c0c3730u,0x0c0c3732u,0x0c0c3734u,0x0c0c3736u,0x0c0c3738u,0x0c0c373au,0x0c0c373cu,0x0c0c373eu,0x0c0c3740u,0x0c0c3742u,0x0c0c3744u,0x0c0c3746u,0x0c0c3748u,0x0c0c374au,
0x0c0c374cu,0x0c0c374eu,0x0c0c3750u,0x0c0c3752u,0x0c0c3754u,0x0c0c3756u,0x0c0c3758u,0x0c0c375au,0x0c0c375cu,0x0c0c375eu,0x0c0c3760u,0x0c0c3762u,0x0c0c3764u,0x0c0c3766u,0x0c0c3768u,0x0c0c376au,
0x0c0c376cu,0x0c0c376eu,0x0c0c3770u,0x0c0c3772u,0x0c0c3774u,0x0c0c3776u,0x0c0c3778u,0x0c0c377au,0x0c0c377cu,0x0c0c377eu,0x0c0c3780u,0x0c0c3782u,0x0c0c3784u,0x0c0c3786u,0x0c0c3788u,0x0c0c378au,
0x0c0c378cu,0x0c0c378eu,0x0c0c3790u,0x0c0c3792u,0x0c0c3794u,0x0c0c3796u,0x0c0c3798u,0x0c0c379au,0x0c0c379cu,0x0c0c379eu,0x0c0c37a0u,0x0c0c37a2u,0x0c0c37a4u,0x0c0c37a6u,0x0c0c37a8u,0x0c0c37aau,
0x0c0c37acu,0x0c0c37aeu,0x0c0c37b0u,0x0c0c37b2u,0x0c0c37b4u,0x0c0c37b6u,0x0c0c37b8u,0x0c0c37bau,0x0c0c37bcu,0x0c0c37beu,0x0c0c37c0u,0x0c0c37c2u,0x0c0c37c4u,0x0c0c37c6u,0x0c0c37c8u,0x0c0c37cau,
0x0c0c37ccu,0x0c0c37ceu,0x0c0c37d0u,0x0c0c37d2u,0x0c0c37d4u,0x0c0c37d6u,0x0c0c37d8u,0x0c0c37dau,0x0c0c37dcu,0x0c0c37deu,0x0c0c37e0u,0x0c0c37e2u,0x0c0c37e4u,0x0c0c37e6u,0x0c0c37e8u,0x0c0c37eau,
0x0c0c37ecu,0x0c0c37eeu,0x0c0c37f0u,0x0c0c37f2u,0x0c0c37f4u,0x0c0c37f6u,0x0c0c37f8u,0x0c0c37fau,0x0c0c37fcu,0x0c0c37feu,0x0c0c3800u,0x0c0c3802u,0x0c0c3804u,0x0c0c3806u,0x0c0c3808u,0x0c0c380au,
0x0c0c380cu,0x0c0c380eu,0x0c0c3810u,0x0c0c3812u,0x0c0c3814u,0x0c0c3816u,0x0c0c3818u,0x0c0c381au,0x0c0c381cu,0x0c0c381eu,0x0c0c3820u,0x0c0c3822u,0x0c0c3824u,0x0c0c3826u,0x0c0c3838u,0x0c0c383au,
0x0c0c383cu,0x0c0c383eu,0x0c0c3840u,0x0c0c3842u,0x0c0c3844u,0x0c0c3846u,0x0c0c3848u,0x0c0c384au,0x0c0c384cu,0x0c0c384eu,0x0c0c3850u,0x0c0c3852u,0x0c0c3854u,0x0c0c3856u,0x0c0c3858u,0x0c0c385au,
0x0c0c385cu,0x0c0c385eu,0x0c0c3860u,0x0c0c3862u,0x0c0c3864u,0x0c0c3866u,0x0c0c3868u,0x0c0c386au,0x0c0c386cu,0x0c0c386eu,0x0c0c3870u,0x0c0c3872u,0x0c0c3874u,0x0c0c3876u,0x0c0c3878u,0x0c0c387au,
0x0c0c387cu,0x0c0c387eu,0x0c0c3880u,0x0c0c3882u,0x0c0c3884u,0x0c0c3886u,0x0c0c3888u,0x0c0c388au,0x0c0c388cu,0x0c0c388eu,0x0c0c3890u,0x0c0c3892u,0x0c0c3894u,0x0c0c3896u,0x0c0c3898u,0x0c0c389au,
0x0c0c389cu,0x0c0c389eu,0x0c0c38a0u,0x0c0c38a2u,0x0c0c38a4u,0x0c0c38a6u,0x0c0c38a8u,0x0c0c38aau,0x0c0c38acu,0x0c0c38aeu,0x0c0c38b0u,0x0c0c38b2u,0x0c0c38b4u,0x0c0c38b6u,0x0c0c38b8u,0x0c0c38bau,
0x0c0c38bcu,0x0c0c38beu,0x0c0c38c0u,0x0c0c38c2u,0x0c0c38c4u,0x0c0c4b7eu,0x0c0c4b80u,0x0c0c4b82u,0x0c0c4b84u,0x0c0c4b86u,0x0c0c4b88u,0x0c0c4b8au,0x0c0c4b8cu,0x0c0c4b8eu,0x0c0c4c60u,0x0c0c4c62u,
0x0c0c4c64u,0x0c0c4c66u,0x0c0c4c68u,0x0c0c4c6au,0x0c0c4c6cu,0x0c0c4c6eu,0x0c0c4c70u,0x0c0c4c72u,0x0c0c4c74u,0x0c0c4c76u,0x0c0c4c78u,0x0c0c4c7au,0x0c0c4c7cu,0x0c0c4c7eu,0x0c0c4c80u,0x0c0c4c82u,
0x0c0c4c84u,0x0c0c4c86u,0x0c0c4c88u,0x0c0c4c8au,
};
int vf3_percentage_family_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
