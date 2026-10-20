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
int vf3_c90_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03757cu: goto P_0c03757c;
case 0x0c03757eu: goto P_0c03757e;
case 0x0c037580u: goto P_0c037580;
case 0x0c037582u: goto P_0c037582;
case 0x0c037584u: goto P_0c037584;
case 0x0c037586u: goto P_0c037586;
case 0x0c037588u: goto P_0c037588;
case 0x0c03758au: goto P_0c03758a;
case 0x0c03758cu: goto P_0c03758c;
case 0x0c03758eu: goto P_0c03758e;
case 0x0c037590u: goto P_0c037590;
case 0x0c037592u: goto P_0c037592;
case 0x0c037594u: goto P_0c037594;
case 0x0c037596u: goto P_0c037596;
case 0x0c037598u: goto P_0c037598;
case 0x0c03759au: goto P_0c03759a;
case 0x0c03759cu: goto P_0c03759c;
case 0x0c03759eu: goto P_0c03759e;
case 0x0c0375a0u: goto P_0c0375a0;
case 0x0c0375a2u: goto P_0c0375a2;
case 0x0c0375a4u: goto P_0c0375a4;
case 0x0c0375a6u: goto P_0c0375a6;
case 0x0c0375a8u: goto P_0c0375a8;
case 0x0c0375aau: goto P_0c0375aa;
case 0x0c0375acu: goto P_0c0375ac;
case 0x0c0375aeu: goto P_0c0375ae;
case 0x0c0375b0u: goto P_0c0375b0;
case 0x0c0375b2u: goto P_0c0375b2;
case 0x0c0375b4u: goto P_0c0375b4;
case 0x0c0375b6u: goto P_0c0375b6;
case 0x0c0375b8u: goto P_0c0375b8;
case 0x0c0375bau: goto P_0c0375ba;
case 0x0c0375bcu: goto P_0c0375bc;
case 0x0c0375beu: goto P_0c0375be;
case 0x0c0375c0u: goto P_0c0375c0;
case 0x0c0375c2u: goto P_0c0375c2;
case 0x0c0375c4u: goto P_0c0375c4;
case 0x0c0375c6u: goto P_0c0375c6;
case 0x0c0375c8u: goto P_0c0375c8;
case 0x0c0375cau: goto P_0c0375ca;
case 0x0c0375ccu: goto P_0c0375cc;
case 0x0c0375ceu: goto P_0c0375ce;
case 0x0c0375d0u: goto P_0c0375d0;
case 0x0c0375d2u: goto P_0c0375d2;
case 0x0c0375d4u: goto P_0c0375d4;
case 0x0c0375d6u: goto P_0c0375d6;
case 0x0c0375d8u: goto P_0c0375d8;
case 0x0c0375dau: goto P_0c0375da;
case 0x0c0375dcu: goto P_0c0375dc;
case 0x0c0375deu: goto P_0c0375de;
case 0x0c0375e0u: goto P_0c0375e0;
case 0x0c0375e2u: goto P_0c0375e2;
case 0x0c0375e4u: goto P_0c0375e4;
case 0x0c0375e6u: goto P_0c0375e6;
case 0x0c0375e8u: goto P_0c0375e8;
case 0x0c0375eau: goto P_0c0375ea;
case 0x0c0375ecu: goto P_0c0375ec;
case 0x0c0375eeu: goto P_0c0375ee;
case 0x0c0375f0u: goto P_0c0375f0;
case 0x0c0375f2u: goto P_0c0375f2;
case 0x0c0375f4u: goto P_0c0375f4;
case 0x0c0375f6u: goto P_0c0375f6;
case 0x0c0375f8u: goto P_0c0375f8;
case 0x0c0375fau: goto P_0c0375fa;
case 0x0c0375fcu: goto P_0c0375fc;
case 0x0c0375feu: goto P_0c0375fe;
case 0x0c037600u: goto P_0c037600;
case 0x0c037602u: goto P_0c037602;
case 0x0c037604u: goto P_0c037604;
case 0x0c037606u: goto P_0c037606;
case 0x0c037608u: goto P_0c037608;
case 0x0c03760au: goto P_0c03760a;
case 0x0c03760cu: goto P_0c03760c;
case 0x0c03760eu: goto P_0c03760e;
case 0x0c037610u: goto P_0c037610;
case 0x0c037612u: goto P_0c037612;
case 0x0c037614u: goto P_0c037614;
case 0x0c037616u: goto P_0c037616;
case 0x0c037618u: goto P_0c037618;
case 0x0c03761au: goto P_0c03761a;
case 0x0c03761cu: goto P_0c03761c;
case 0x0c03761eu: goto P_0c03761e;
case 0x0c037620u: goto P_0c037620;
case 0x0c037622u: goto P_0c037622;
case 0x0c037624u: goto P_0c037624;
case 0x0c037626u: goto P_0c037626;
case 0x0c037628u: goto P_0c037628;
case 0x0c03762au: goto P_0c03762a;
case 0x0c03762cu: goto P_0c03762c;
case 0x0c03762eu: goto P_0c03762e;
case 0x0c037630u: goto P_0c037630;
case 0x0c037632u: goto P_0c037632;
case 0x0c037634u: goto P_0c037634;
case 0x0c037636u: goto P_0c037636;
case 0x0c037638u: goto P_0c037638;
case 0x0c03763au: goto P_0c03763a;
case 0x0c03763cu: goto P_0c03763c;
case 0x0c03763eu: goto P_0c03763e;
case 0x0c037640u: goto P_0c037640;
case 0x0c037642u: goto P_0c037642;
case 0x0c037644u: goto P_0c037644;
case 0x0c037646u: goto P_0c037646;
case 0x0c037648u: goto P_0c037648;
case 0x0c03764au: goto P_0c03764a;
case 0x0c03764cu: goto P_0c03764c;
case 0x0c03764eu: goto P_0c03764e;
case 0x0c037650u: goto P_0c037650;
case 0x0c037652u: goto P_0c037652;
case 0x0c037654u: goto P_0c037654;
case 0x0c037656u: goto P_0c037656;
case 0x0c037658u: goto P_0c037658;
case 0x0c03765au: goto P_0c03765a;
case 0x0c03765cu: goto P_0c03765c;
case 0x0c03765eu: goto P_0c03765e;
case 0x0c037660u: goto P_0c037660;
case 0x0c037662u: goto P_0c037662;
case 0x0c037664u: goto P_0c037664;
case 0x0c037666u: goto P_0c037666;
case 0x0c037668u: goto P_0c037668;
case 0x0c03766au: goto P_0c03766a;
case 0x0c03766cu: goto P_0c03766c;
case 0x0c03766eu: goto P_0c03766e;
case 0x0c037670u: goto P_0c037670;
case 0x0c037672u: goto P_0c037672;
case 0x0c037674u: goto P_0c037674;
case 0x0c037676u: goto P_0c037676;
case 0x0c037678u: goto P_0c037678;
case 0x0c03767au: goto P_0c03767a;
case 0x0c03767cu: goto P_0c03767c;
case 0x0c03767eu: goto P_0c03767e;
case 0x0c037680u: goto P_0c037680;
case 0x0c037682u: goto P_0c037682;
case 0x0c037684u: goto P_0c037684;
case 0x0c037686u: goto P_0c037686;
case 0x0c037688u: goto P_0c037688;
case 0x0c04d020u: goto P_0c04d020;
case 0x0c04d022u: goto P_0c04d022;
case 0x0c04d024u: goto P_0c04d024;
case 0x0c04d026u: goto P_0c04d026;
case 0x0c04d028u: goto P_0c04d028;
case 0x0c04d02au: goto P_0c04d02a;
case 0x0c04d02cu: goto P_0c04d02c;
case 0x0c04d02eu: goto P_0c04d02e;
case 0x0c04d030u: goto P_0c04d030;
case 0x0c04d032u: goto P_0c04d032;
case 0x0c04d034u: goto P_0c04d034;
case 0x0c04d036u: goto P_0c04d036;
case 0x0c04d038u: goto P_0c04d038;
case 0x0c04d03au: goto P_0c04d03a;
case 0x0c04d03cu: goto P_0c04d03c;
case 0x0c04d03eu: goto P_0c04d03e;
case 0x0c04d040u: goto P_0c04d040;
case 0x0c04d042u: goto P_0c04d042;
case 0x0c04d044u: goto P_0c04d044;
case 0x0c04d046u: goto P_0c04d046;
case 0x0c04d048u: goto P_0c04d048;
case 0x0c04d04au: goto P_0c04d04a;
case 0x0c04d04cu: goto P_0c04d04c;
case 0x0c04d04eu: goto P_0c04d04e;
case 0x0c04d050u: goto P_0c04d050;
case 0x0c04d052u: goto P_0c04d052;
case 0x0c04d054u: goto P_0c04d054;
case 0x0c04d056u: goto P_0c04d056;
case 0x0c04d058u: goto P_0c04d058;
case 0x0c04d05au: goto P_0c04d05a;
case 0x0c04d05cu: goto P_0c04d05c;
case 0x0c04d05eu: goto P_0c04d05e;
case 0x0c04d060u: goto P_0c04d060;
case 0x0c04d062u: goto P_0c04d062;
case 0x0c04d064u: goto P_0c04d064;
case 0x0c04d066u: goto P_0c04d066;
case 0x0c04d068u: goto P_0c04d068;
case 0x0c04d06au: goto P_0c04d06a;
case 0x0c04d06cu: goto P_0c04d06c;
case 0x0c04d06eu: goto P_0c04d06e;
case 0x0c04d070u: goto P_0c04d070;
case 0x0c04d072u: goto P_0c04d072;
case 0x0c04d09cu: goto P_0c04d09c;
case 0x0c04d09eu: goto P_0c04d09e;
case 0x0c04d0a0u: goto P_0c04d0a0;
case 0x0c04d0a2u: goto P_0c04d0a2;
case 0x0c04d0a4u: goto P_0c04d0a4;
case 0x0c04d0a6u: goto P_0c04d0a6;
case 0x0c04d0a8u: goto P_0c04d0a8;
case 0x0c04d0aau: goto P_0c04d0aa;
case 0x0c04d0acu: goto P_0c04d0ac;
case 0x0c04d0aeu: goto P_0c04d0ae;
case 0x0c04d0b0u: goto P_0c04d0b0;
case 0x0c04d0b2u: goto P_0c04d0b2;
case 0x0c04d0b4u: goto P_0c04d0b4;
case 0x0c04d0b6u: goto P_0c04d0b6;
case 0x0c04d0b8u: goto P_0c04d0b8;
case 0x0c04d0bau: goto P_0c04d0ba;
case 0x0c04d0bcu: goto P_0c04d0bc;
case 0x0c04d0beu: goto P_0c04d0be;
case 0x0c04d0c0u: goto P_0c04d0c0;
case 0x0c04d0c2u: goto P_0c04d0c2;
case 0x0c04d0c4u: goto P_0c04d0c4;
case 0x0c04d0c6u: goto P_0c04d0c6;
case 0x0c04d0c8u: goto P_0c04d0c8;
case 0x0c04d0cau: goto P_0c04d0ca;
case 0x0c04d0ccu: goto P_0c04d0cc;
case 0x0c04d0ceu: goto P_0c04d0ce;
case 0x0c04d0d0u: goto P_0c04d0d0;
case 0x0c04d0d2u: goto P_0c04d0d2;
case 0x0c04d0d4u: goto P_0c04d0d4;
case 0x0c04d0d6u: goto P_0c04d0d6;
case 0x0c04d0d8u: goto P_0c04d0d8;
case 0x0c04d0dau: goto P_0c04d0da;
case 0x0c04d0dcu: goto P_0c04d0dc;
case 0x0c04d0deu: goto P_0c04d0de;
case 0x0c04d0e0u: goto P_0c04d0e0;
case 0x0c04d0e2u: goto P_0c04d0e2;
case 0x0c04d0e4u: goto P_0c04d0e4;
case 0x0c04d0e6u: goto P_0c04d0e6;
case 0x0c04d0e8u: goto P_0c04d0e8;
case 0x0c04d0eau: goto P_0c04d0ea;
case 0x0c04d0ecu: goto P_0c04d0ec;
case 0x0c04d0eeu: goto P_0c04d0ee;
case 0x0c04d0f0u: goto P_0c04d0f0;
case 0x0c04d0f2u: goto P_0c04d0f2;
case 0x0c04d0f4u: goto P_0c04d0f4;
case 0x0c04d0f6u: goto P_0c04d0f6;
case 0x0c04d0f8u: goto P_0c04d0f8;
case 0x0c04d0fau: goto P_0c04d0fa;
case 0x0c04d0fcu: goto P_0c04d0fc;
case 0x0c04d0feu: goto P_0c04d0fe;
case 0x0c04d100u: goto P_0c04d100;
case 0x0c04d102u: goto P_0c04d102;
case 0x0c04d104u: goto P_0c04d104;
case 0x0c04d106u: goto P_0c04d106;
case 0x0c04d108u: goto P_0c04d108;
case 0x0c04d10au: goto P_0c04d10a;
case 0x0c04d10cu: goto P_0c04d10c;
case 0x0c04d10eu: goto P_0c04d10e;
case 0x0c04d110u: goto P_0c04d110;
case 0x0c04d112u: goto P_0c04d112;
case 0x0c04d114u: goto P_0c04d114;
case 0x0c04d116u: goto P_0c04d116;
case 0x0c04d118u: goto P_0c04d118;
case 0x0c04d11au: goto P_0c04d11a;
case 0x0c04d11cu: goto P_0c04d11c;
case 0x0c04d11eu: goto P_0c04d11e;
case 0x0c04d120u: goto P_0c04d120;
case 0x0c04d122u: goto P_0c04d122;
case 0x0c04d124u: goto P_0c04d124;
case 0x0c04d126u: goto P_0c04d126;
case 0x0c04d128u: goto P_0c04d128;
case 0x0c04d12au: goto P_0c04d12a;
case 0x0c04d12cu: goto P_0c04d12c;
case 0x0c04d12eu: goto P_0c04d12e;
case 0x0c04d130u: goto P_0c04d130;
case 0x0c04d132u: goto P_0c04d132;
case 0x0c04d134u: goto P_0c04d134;
case 0x0c04d136u: goto P_0c04d136;
case 0x0c04d138u: goto P_0c04d138;
case 0x0c04d13au: goto P_0c04d13a;
case 0x0c04d13cu: goto P_0c04d13c;
case 0x0c04d13eu: goto P_0c04d13e;
case 0x0c04d140u: goto P_0c04d140;
case 0x0c04d142u: goto P_0c04d142;
case 0x0c04d144u: goto P_0c04d144;
case 0x0c04d146u: goto P_0c04d146;
case 0x0c04d148u: goto P_0c04d148;
case 0x0c04d14au: goto P_0c04d14a;
case 0x0c04d14cu: goto P_0c04d14c;
case 0x0c04d14eu: goto P_0c04d14e;
case 0x0c04d150u: goto P_0c04d150;
case 0x0c04d152u: goto P_0c04d152;
case 0x0c04d154u: goto P_0c04d154;
case 0x0c04d156u: goto P_0c04d156;
case 0x0c04d158u: goto P_0c04d158;
case 0x0c04d15au: goto P_0c04d15a;
case 0x0c04d15cu: goto P_0c04d15c;
case 0x0c04d15eu: goto P_0c04d15e;
case 0x0c04d160u: goto P_0c04d160;
case 0x0c04d162u: goto P_0c04d162;
case 0x0c04d164u: goto P_0c04d164;
case 0x0c04d166u: goto P_0c04d166;
case 0x0c04d168u: goto P_0c04d168;
case 0x0c04d16au: goto P_0c04d16a;
case 0x0c04d16cu: goto P_0c04d16c;
case 0x0c04d16eu: goto P_0c04d16e;
case 0x0c04d170u: goto P_0c04d170;
case 0x0c04d172u: goto P_0c04d172;
case 0x0c04d174u: goto P_0c04d174;
case 0x0c04d1a0u: goto P_0c04d1a0;
case 0x0c04d1a2u: goto P_0c04d1a2;
case 0x0c04d1a4u: goto P_0c04d1a4;
case 0x0c04d1a6u: goto P_0c04d1a6;
case 0x0c04d1a8u: goto P_0c04d1a8;
case 0x0c04d1aau: goto P_0c04d1aa;
case 0x0c04d1acu: goto P_0c04d1ac;
case 0x0c04d1aeu: goto P_0c04d1ae;
case 0x0c04d1b0u: goto P_0c04d1b0;
case 0x0c04d1b2u: goto P_0c04d1b2;
case 0x0c04d1b4u: goto P_0c04d1b4;
case 0x0c04d1b6u: goto P_0c04d1b6;
case 0x0c04d1b8u: goto P_0c04d1b8;
case 0x0c04d1bau: goto P_0c04d1ba;
case 0x0c04d1bcu: goto P_0c04d1bc;
case 0x0c04d1beu: goto P_0c04d1be;
case 0x0c04d1c0u: goto P_0c04d1c0;
case 0x0c04d1c2u: goto P_0c04d1c2;
case 0x0c04d1c4u: goto P_0c04d1c4;
case 0x0c04d1c6u: goto P_0c04d1c6;
case 0x0c04d1c8u: goto P_0c04d1c8;
case 0x0c04d1cau: goto P_0c04d1ca;
case 0x0c04d1ccu: goto P_0c04d1cc;
case 0x0c04d1ceu: goto P_0c04d1ce;
case 0x0c04d1d0u: goto P_0c04d1d0;
case 0x0c04d1d2u: goto P_0c04d1d2;
case 0x0c04d1d4u: goto P_0c04d1d4;
case 0x0c04d1d6u: goto P_0c04d1d6;
case 0x0c04d1d8u: goto P_0c04d1d8;
case 0x0c04d1dau: goto P_0c04d1da;
case 0x0c04d1dcu: goto P_0c04d1dc;
case 0x0c04d1deu: goto P_0c04d1de;
case 0x0c04d1e0u: goto P_0c04d1e0;
case 0x0c04d1e2u: goto P_0c04d1e2;
case 0x0c04d1e4u: goto P_0c04d1e4;
case 0x0c04d1e6u: goto P_0c04d1e6;
case 0x0c04d1e8u: goto P_0c04d1e8;
case 0x0c04d1eau: goto P_0c04d1ea;
case 0x0c04d1ecu: goto P_0c04d1ec;
case 0x0c04d1eeu: goto P_0c04d1ee;
case 0x0c04d1f0u: goto P_0c04d1f0;
case 0x0c04d1f2u: goto P_0c04d1f2;
case 0x0c04d1f4u: goto P_0c04d1f4;
case 0x0c04d1f6u: goto P_0c04d1f6;
case 0x0c04d1f8u: goto P_0c04d1f8;
case 0x0c04d1fau: goto P_0c04d1fa;
case 0x0c04d1fcu: goto P_0c04d1fc;
case 0x0c04d1feu: goto P_0c04d1fe;
case 0x0c04d200u: goto P_0c04d200;
case 0x0c04d202u: goto P_0c04d202;
case 0x0c04d204u: goto P_0c04d204;
case 0x0c04d206u: goto P_0c04d206;
case 0x0c04d208u: goto P_0c04d208;
case 0x0c04d20au: goto P_0c04d20a;
case 0x0c04d20cu: goto P_0c04d20c;
case 0x0c04d20eu: goto P_0c04d20e;
case 0x0c04d210u: goto P_0c04d210;
case 0x0c04d212u: goto P_0c04d212;
case 0x0c04d214u: goto P_0c04d214;
case 0x0c04d216u: goto P_0c04d216;
case 0x0c04d218u: goto P_0c04d218;
case 0x0c04d21au: goto P_0c04d21a;
case 0x0c04d21cu: goto P_0c04d21c;
case 0x0c04d21eu: goto P_0c04d21e;
case 0x0c04d220u: goto P_0c04d220;
case 0x0c04d222u: goto P_0c04d222;
case 0x0c04d224u: goto P_0c04d224;
case 0x0c04d226u: goto P_0c04d226;
case 0x0c04d228u: goto P_0c04d228;
case 0x0c04d22au: goto P_0c04d22a;
case 0x0c04d22cu: goto P_0c04d22c;
case 0x0c04d22eu: goto P_0c04d22e;
case 0x0c04d230u: goto P_0c04d230;
case 0x0c04d232u: goto P_0c04d232;
case 0x0c04d234u: goto P_0c04d234;
case 0x0c04d236u: goto P_0c04d236;
case 0x0c04d238u: goto P_0c04d238;
case 0x0c04d23au: goto P_0c04d23a;
case 0x0c04d23cu: goto P_0c04d23c;
case 0x0c04d23eu: goto P_0c04d23e;
case 0x0c04d240u: goto P_0c04d240;
case 0x0c04d242u: goto P_0c04d242;
case 0x0c04d244u: goto P_0c04d244;
case 0x0c04d246u: goto P_0c04d246;
case 0x0c04d248u: goto P_0c04d248;
case 0x0c04d24au: goto P_0c04d24a;
case 0x0c04d24cu: goto P_0c04d24c;
case 0x0c04d24eu: goto P_0c04d24e;
case 0x0c04d250u: goto P_0c04d250;
case 0x0c04d252u: goto P_0c04d252;
case 0x0c04d254u: goto P_0c04d254;
case 0x0c04d256u: goto P_0c04d256;
case 0x0c04d258u: goto P_0c04d258;
case 0x0c04d25au: goto P_0c04d25a;
case 0x0c04d25cu: goto P_0c04d25c;
case 0x0c04d25eu: goto P_0c04d25e;
case 0x0c04d260u: goto P_0c04d260;
case 0x0c04d262u: goto P_0c04d262;
case 0x0c04d264u: goto P_0c04d264;
case 0x0c04d266u: goto P_0c04d266;
case 0x0c04d268u: goto P_0c04d268;
case 0x0c04d26au: goto P_0c04d26a;
case 0x0c04d26cu: goto P_0c04d26c;
case 0x0c04d26eu: goto P_0c04d26e;
case 0x0c04d270u: goto P_0c04d270;
case 0x0c04d272u: goto P_0c04d272;
case 0x0c04d274u: goto P_0c04d274;
case 0x0c04d276u: goto P_0c04d276;
case 0x0c04d278u: goto P_0c04d278;
case 0x0c04d27au: goto P_0c04d27a;
case 0x0c04d27cu: goto P_0c04d27c;
case 0x0c04d27eu: goto P_0c04d27e;
case 0x0c04d280u: goto P_0c04d280;
case 0x0c04d282u: goto P_0c04d282;
case 0x0c04d284u: goto P_0c04d284;
case 0x0c04d286u: goto P_0c04d286;
case 0x0c04d288u: goto P_0c04d288;
case 0x0c04d28au: goto P_0c04d28a;
case 0x0c04d28cu: goto P_0c04d28c;
case 0x0c04d28eu: goto P_0c04d28e;
case 0x0c04d290u: goto P_0c04d290;
case 0x0c04d292u: goto P_0c04d292;
case 0x0c04d294u: goto P_0c04d294;
case 0x0c04d296u: goto P_0c04d296;
case 0x0c04d298u: goto P_0c04d298;
case 0x0c04d29au: goto P_0c04d29a;
case 0x0c04d29cu: goto P_0c04d29c;
case 0x0c04d29eu: goto P_0c04d29e;
case 0x0c04d2a0u: goto P_0c04d2a0;
case 0x0c04d2a2u: goto P_0c04d2a2;
case 0x0c04d2a4u: goto P_0c04d2a4;
case 0x0c04d2a6u: goto P_0c04d2a6;
case 0x0c04d2a8u: goto P_0c04d2a8;
case 0x0c04d2aau: goto P_0c04d2aa;
case 0x0c04d2acu: goto P_0c04d2ac;
case 0x0c04d2aeu: goto P_0c04d2ae;
case 0x0c04d2b0u: goto P_0c04d2b0;
case 0x0c04d2b2u: goto P_0c04d2b2;
case 0x0c04d2b4u: goto P_0c04d2b4;
case 0x0c04d2b6u: goto P_0c04d2b6;
case 0x0c04d2b8u: goto P_0c04d2b8;
case 0x0c04d2bau: goto P_0c04d2ba;
case 0x0c04d2bcu: goto P_0c04d2bc;
case 0x0c04d2beu: goto P_0c04d2be;
case 0x0c04d2c0u: goto P_0c04d2c0;
case 0x0c04d2c2u: goto P_0c04d2c2;
case 0x0c04d2c4u: goto P_0c04d2c4;
case 0x0c04d2c6u: goto P_0c04d2c6;
case 0x0c04d2c8u: goto P_0c04d2c8;
case 0x0c04d2cau: goto P_0c04d2ca;
case 0x0c04d2ccu: goto P_0c04d2cc;
case 0x0c04d2ceu: goto P_0c04d2ce;
case 0x0c04d2d0u: goto P_0c04d2d0;
case 0x0c04d2d2u: goto P_0c04d2d2;
case 0x0c04d2d4u: goto P_0c04d2d4;
case 0x0c04d2d6u: goto P_0c04d2d6;
case 0x0c04d2d8u: goto P_0c04d2d8;
case 0x0c04d2dau: goto P_0c04d2da;
case 0x0c04d2dcu: goto P_0c04d2dc;
case 0x0c04d2deu: goto P_0c04d2de;
case 0x0c04d2e0u: goto P_0c04d2e0;
case 0x0c04d2e2u: goto P_0c04d2e2;
case 0x0c04d2e4u: goto P_0c04d2e4;
case 0x0c04d2e6u: goto P_0c04d2e6;
case 0x0c04d2e8u: goto P_0c04d2e8;
case 0x0c04d2eau: goto P_0c04d2ea;
case 0x0c04d2ecu: goto P_0c04d2ec;
case 0x0c04d2eeu: goto P_0c04d2ee;
case 0x0c04d2f0u: goto P_0c04d2f0;
case 0x0c04d320u: goto P_0c04d320;
case 0x0c04d322u: goto P_0c04d322;
case 0x0c04d324u: goto P_0c04d324;
case 0x0c04d326u: goto P_0c04d326;
case 0x0c04d328u: goto P_0c04d328;
case 0x0c04d32au: goto P_0c04d32a;
case 0x0c04d32cu: goto P_0c04d32c;
case 0x0c04d32eu: goto P_0c04d32e;
case 0x0c04d330u: goto P_0c04d330;
case 0x0c04d332u: goto P_0c04d332;
case 0x0c04d334u: goto P_0c04d334;
case 0x0c04d336u: goto P_0c04d336;
case 0x0c04d338u: goto P_0c04d338;
case 0x0c04d33au: goto P_0c04d33a;
case 0x0c04d33cu: goto P_0c04d33c;
case 0x0c04d33eu: goto P_0c04d33e;
case 0x0c04d340u: goto P_0c04d340;
case 0x0c04d342u: goto P_0c04d342;
case 0x0c04d344u: goto P_0c04d344;
case 0x0c04d346u: goto P_0c04d346;
case 0x0c04d348u: goto P_0c04d348;
case 0x0c04d34au: goto P_0c04d34a;
case 0x0c04d34cu: goto P_0c04d34c;
case 0x0c04d34eu: goto P_0c04d34e;
case 0x0c04d350u: goto P_0c04d350;
case 0x0c04d352u: goto P_0c04d352;
case 0x0c04d354u: goto P_0c04d354;
case 0x0c04d356u: goto P_0c04d356;
case 0x0c04d358u: goto P_0c04d358;
case 0x0c04d35au: goto P_0c04d35a;
case 0x0c04d35cu: goto P_0c04d35c;
case 0x0c04d35eu: goto P_0c04d35e;
case 0x0c04d360u: goto P_0c04d360;
case 0x0c04d362u: goto P_0c04d362;
case 0x0c04d364u: goto P_0c04d364;
case 0x0c04d366u: goto P_0c04d366;
case 0x0c04d368u: goto P_0c04d368;
case 0x0c04d36au: goto P_0c04d36a;
case 0x0c04d36cu: goto P_0c04d36c;
case 0x0c04d36eu: goto P_0c04d36e;
case 0x0c04d370u: goto P_0c04d370;
case 0x0c04d372u: goto P_0c04d372;
case 0x0c04d374u: goto P_0c04d374;
case 0x0c04d376u: goto P_0c04d376;
case 0x0c04d378u: goto P_0c04d378;
case 0x0c04d37au: goto P_0c04d37a;
case 0x0c04d37cu: goto P_0c04d37c;
case 0x0c04d37eu: goto P_0c04d37e;
case 0x0c04d380u: goto P_0c04d380;
case 0x0c04d382u: goto P_0c04d382;
case 0x0c04d384u: goto P_0c04d384;
case 0x0c04d386u: goto P_0c04d386;
case 0x0c04d388u: goto P_0c04d388;
case 0x0c04d38au: goto P_0c04d38a;
case 0x0c04d38cu: goto P_0c04d38c;
case 0x0c04d38eu: goto P_0c04d38e;
case 0x0c04d390u: goto P_0c04d390;
case 0x0c04d392u: goto P_0c04d392;
case 0x0c04d394u: goto P_0c04d394;
case 0x0c04d396u: goto P_0c04d396;
case 0x0c04d398u: goto P_0c04d398;
case 0x0c04d39au: goto P_0c04d39a;
case 0x0c04d39cu: goto P_0c04d39c;
case 0x0c04d39eu: goto P_0c04d39e;
case 0x0c04d3a0u: goto P_0c04d3a0;
case 0x0c04d3a2u: goto P_0c04d3a2;
case 0x0c04d3a4u: goto P_0c04d3a4;
case 0x0c04d3a6u: goto P_0c04d3a6;
case 0x0c04d3a8u: goto P_0c04d3a8;
case 0x0c04d3aau: goto P_0c04d3aa;
case 0x0c04d3acu: goto P_0c04d3ac;
case 0x0c04d3aeu: goto P_0c04d3ae;
case 0x0c04d3b0u: goto P_0c04d3b0;
case 0x0c04d3b2u: goto P_0c04d3b2;
case 0x0c04d3b4u: goto P_0c04d3b4;
case 0x0c04d3b6u: goto P_0c04d3b6;
case 0x0c04d3b8u: goto P_0c04d3b8;
case 0x0c04d3bau: goto P_0c04d3ba;
case 0x0c04d3bcu: goto P_0c04d3bc;
case 0x0c04d3beu: goto P_0c04d3be;
case 0x0c04d3c0u: goto P_0c04d3c0;
case 0x0c04d3c2u: goto P_0c04d3c2;
case 0x0c04d3c4u: goto P_0c04d3c4;
case 0x0c04d3c6u: goto P_0c04d3c6;
case 0x0c04d3c8u: goto P_0c04d3c8;
case 0x0c04d3cau: goto P_0c04d3ca;
case 0x0c04d3ccu: goto P_0c04d3cc;
case 0x0c04d3ceu: goto P_0c04d3ce;
case 0x0c04d3d0u: goto P_0c04d3d0;
case 0x0c04d3d2u: goto P_0c04d3d2;
case 0x0c04d3d4u: goto P_0c04d3d4;
case 0x0c04d3d6u: goto P_0c04d3d6;
case 0x0c04d3d8u: goto P_0c04d3d8;
case 0x0c04d3dau: goto P_0c04d3da;
case 0x0c04d3dcu: goto P_0c04d3dc;
case 0x0c04d3deu: goto P_0c04d3de;
case 0x0c04d3e0u: goto P_0c04d3e0;
case 0x0c04d3e2u: goto P_0c04d3e2;
case 0x0c04d3e4u: goto P_0c04d3e4;
case 0x0c04d3e6u: goto P_0c04d3e6;
case 0x0c04d3e8u: goto P_0c04d3e8;
case 0x0c04d3eau: goto P_0c04d3ea;
case 0x0c04d3ecu: goto P_0c04d3ec;
case 0x0c04d3eeu: goto P_0c04d3ee;
case 0x0c04d3f0u: goto P_0c04d3f0;
case 0x0c04d3f2u: goto P_0c04d3f2;
case 0x0c04d3f4u: goto P_0c04d3f4;
case 0x0c04d3f6u: goto P_0c04d3f6;
case 0x0c04d3f8u: goto P_0c04d3f8;
case 0x0c04d3fau: goto P_0c04d3fa;
case 0x0c04d3fcu: goto P_0c04d3fc;
case 0x0c04d3feu: goto P_0c04d3fe;
case 0x0c04d400u: goto P_0c04d400;
case 0x0c04d402u: goto P_0c04d402;
case 0x0c04d404u: goto P_0c04d404;
case 0x0c04d406u: goto P_0c04d406;
case 0x0c04d408u: goto P_0c04d408;
case 0x0c04d40au: goto P_0c04d40a;
case 0x0c04d40cu: goto P_0c04d40c;
case 0x0c04d40eu: goto P_0c04d40e;
case 0x0c04d410u: goto P_0c04d410;
case 0x0c04d412u: goto P_0c04d412;
case 0x0c04d414u: goto P_0c04d414;
case 0x0c04d416u: goto P_0c04d416;
case 0x0c04e8f8u: goto P_0c04e8f8;
case 0x0c04e8fau: goto P_0c04e8fa;
case 0x0c04e8fcu: goto P_0c04e8fc;
case 0x0c04e8feu: goto P_0c04e8fe;
case 0x0c04e900u: goto P_0c04e900;
case 0x0c04e902u: goto P_0c04e902;
case 0x0c04e904u: goto P_0c04e904;
case 0x0c04e906u: goto P_0c04e906;
case 0x0c04e908u: goto P_0c04e908;
case 0x0c04e90au: goto P_0c04e90a;
case 0x0c04e90cu: goto P_0c04e90c;
case 0x0c04e90eu: goto P_0c04e90e;
case 0x0c04e910u: goto P_0c04e910;
case 0x0c04e912u: goto P_0c04e912;
case 0x0c04e914u: goto P_0c04e914;
case 0x0c04e916u: goto P_0c04e916;
case 0x0c04e918u: goto P_0c04e918;
case 0x0c04e91au: goto P_0c04e91a;
case 0x0c04e91cu: goto P_0c04e91c;
case 0x0c04e91eu: goto P_0c04e91e;
case 0x0c04e920u: goto P_0c04e920;
case 0x0c04e922u: goto P_0c04e922;
case 0x0c04e924u: goto P_0c04e924;
case 0x0c04e926u: goto P_0c04e926;
case 0x0c04e928u: goto P_0c04e928;
case 0x0c04e92au: goto P_0c04e92a;
case 0x0c04e92cu: goto P_0c04e92c;
case 0x0c04e92eu: goto P_0c04e92e;
case 0x0c04e930u: goto P_0c04e930;
case 0x0c04e932u: goto P_0c04e932;
case 0x0c04e934u: goto P_0c04e934;
case 0x0c04e936u: goto P_0c04e936;
case 0x0c04e938u: goto P_0c04e938;
case 0x0c04e93au: goto P_0c04e93a;
case 0x0c04e93cu: goto P_0c04e93c;
case 0x0c04e93eu: goto P_0c04e93e;
case 0x0c04e940u: goto P_0c04e940;
case 0x0c04e942u: goto P_0c04e942;
case 0x0c04e944u: goto P_0c04e944;
case 0x0c04e946u: goto P_0c04e946;
case 0x0c04e948u: goto P_0c04e948;
case 0x0c04e94au: goto P_0c04e94a;
case 0x0c04e94cu: goto P_0c04e94c;
case 0x0c04e94eu: goto P_0c04e94e;
case 0x0c04e950u: goto P_0c04e950;
case 0x0c04e952u: goto P_0c04e952;
case 0x0c04e954u: goto P_0c04e954;
case 0x0c04e956u: goto P_0c04e956;
case 0x0c04e958u: goto P_0c04e958;
case 0x0c04e95au: goto P_0c04e95a;
case 0x0c04e95cu: goto P_0c04e95c;
case 0x0c04e95eu: goto P_0c04e95e;
case 0x0c04e960u: goto P_0c04e960;
case 0x0c04e962u: goto P_0c04e962;
case 0x0c04e964u: goto P_0c04e964;
case 0x0c04e966u: goto P_0c04e966;
case 0x0c04e968u: goto P_0c04e968;
case 0x0c04e96au: goto P_0c04e96a;
case 0x0c04e96cu: goto P_0c04e96c;
case 0x0c04e96eu: goto P_0c04e96e;
case 0x0c04e970u: goto P_0c04e970;
case 0x0c04e972u: goto P_0c04e972;
case 0x0c04e974u: goto P_0c04e974;
case 0x0c04e976u: goto P_0c04e976;
case 0x0c04e978u: goto P_0c04e978;
case 0x0c04e97au: goto P_0c04e97a;
case 0x0c04e97cu: goto P_0c04e97c;
case 0x0c04e97eu: goto P_0c04e97e;
case 0x0c04e980u: goto P_0c04e980;
case 0x0c04e982u: goto P_0c04e982;
case 0x0c04e984u: goto P_0c04e984;
case 0x0c04e986u: goto P_0c04e986;
case 0x0c04e988u: goto P_0c04e988;
case 0x0c04e98au: goto P_0c04e98a;
case 0x0c04e98cu: goto P_0c04e98c;
case 0x0c04e98eu: goto P_0c04e98e;
case 0x0c04e990u: goto P_0c04e990;
case 0x0c04e992u: goto P_0c04e992;
case 0x0c04e994u: goto P_0c04e994;
case 0x0c04e996u: goto P_0c04e996;
case 0x0c04e998u: goto P_0c04e998;
case 0x0c04e99au: goto P_0c04e99a;
case 0x0c04e99cu: goto P_0c04e99c;
case 0x0c04e99eu: goto P_0c04e99e;
case 0x0c04e9ccu: goto P_0c04e9cc;
case 0x0c04e9ceu: goto P_0c04e9ce;
case 0x0c04e9d0u: goto P_0c04e9d0;
case 0x0c04e9d2u: goto P_0c04e9d2;
case 0x0c04e9d4u: goto P_0c04e9d4;
case 0x0c04e9d6u: goto P_0c04e9d6;
case 0x0c04e9d8u: goto P_0c04e9d8;
case 0x0c04e9dau: goto P_0c04e9da;
case 0x0c04e9dcu: goto P_0c04e9dc;
case 0x0c04e9deu: goto P_0c04e9de;
case 0x0c04e9e0u: goto P_0c04e9e0;
case 0x0c04e9e2u: goto P_0c04e9e2;
case 0x0c04e9e4u: goto P_0c04e9e4;
case 0x0c04e9e6u: goto P_0c04e9e6;
case 0x0c04e9e8u: goto P_0c04e9e8;
case 0x0c04e9eau: goto P_0c04e9ea;
case 0x0c04e9ecu: goto P_0c04e9ec;
case 0x0c04e9eeu: goto P_0c04e9ee;
case 0x0c04e9f0u: goto P_0c04e9f0;
case 0x0c04e9f2u: goto P_0c04e9f2;
case 0x0c04e9f4u: goto P_0c04e9f4;
case 0x0c04e9f6u: goto P_0c04e9f6;
case 0x0c04e9f8u: goto P_0c04e9f8;
case 0x0c04e9fau: goto P_0c04e9fa;
case 0x0c04e9fcu: goto P_0c04e9fc;
case 0x0c04e9feu: goto P_0c04e9fe;
case 0x0c04ea00u: goto P_0c04ea00;
case 0x0c04ea02u: goto P_0c04ea02;
case 0x0c04ea04u: goto P_0c04ea04;
case 0x0c04ea06u: goto P_0c04ea06;
case 0x0c04ea08u: goto P_0c04ea08;
case 0x0c04ea0au: goto P_0c04ea0a;
case 0x0c04ea0cu: goto P_0c04ea0c;
case 0x0c04ea0eu: goto P_0c04ea0e;
case 0x0c04ea10u: goto P_0c04ea10;
case 0x0c04ea12u: goto P_0c04ea12;
case 0x0c04ea14u: goto P_0c04ea14;
case 0x0c04ea16u: goto P_0c04ea16;
case 0x0c04ea18u: goto P_0c04ea18;
case 0x0c04ea1au: goto P_0c04ea1a;
case 0x0c04ea1cu: goto P_0c04ea1c;
case 0x0c04ea1eu: goto P_0c04ea1e;
case 0x0c04ea20u: goto P_0c04ea20;
case 0x0c04ea22u: goto P_0c04ea22;
case 0x0c04ea24u: goto P_0c04ea24;
case 0x0c04ea26u: goto P_0c04ea26;
case 0x0c04ea28u: goto P_0c04ea28;
case 0x0c04ea2au: goto P_0c04ea2a;
case 0x0c04ea2cu: goto P_0c04ea2c;
case 0x0c04ea2eu: goto P_0c04ea2e;
case 0x0c04ea30u: goto P_0c04ea30;
case 0x0c04ea32u: goto P_0c04ea32;
case 0x0c04ea34u: goto P_0c04ea34;
case 0x0c04ea36u: goto P_0c04ea36;
case 0x0c04ea38u: goto P_0c04ea38;
case 0x0c04ea3au: goto P_0c04ea3a;
case 0x0c04ea3cu: goto P_0c04ea3c;
case 0x0c04ea3eu: goto P_0c04ea3e;
case 0x0c04ea40u: goto P_0c04ea40;
case 0x0c04ea42u: goto P_0c04ea42;
case 0x0c04f620u: goto P_0c04f620;
case 0x0c04f622u: goto P_0c04f622;
case 0x0c04f624u: goto P_0c04f624;
case 0x0c04f626u: goto P_0c04f626;
case 0x0c04f628u: goto P_0c04f628;
case 0x0c04f62au: goto P_0c04f62a;
case 0x0c04f62cu: goto P_0c04f62c;
case 0x0c04f62eu: goto P_0c04f62e;
case 0x0c04f630u: goto P_0c04f630;
case 0x0c052f36u: goto P_0c052f36;
case 0x0c052f38u: goto P_0c052f38;
case 0x0c052f3au: goto P_0c052f3a;
case 0x0c052f3cu: goto P_0c052f3c;
case 0x0c052f3eu: goto P_0c052f3e;
case 0x0c052f40u: goto P_0c052f40;
case 0x0c052f42u: goto P_0c052f42;
case 0x0c052f44u: goto P_0c052f44;
case 0x0c052f46u: goto P_0c052f46;
case 0x0c052f48u: goto P_0c052f48;
case 0x0c052f4au: goto P_0c052f4a;
case 0x0c052f4cu: goto P_0c052f4c;
case 0x0c052f4eu: goto P_0c052f4e;
case 0x0c052f50u: goto P_0c052f50;
case 0x0c052f52u: goto P_0c052f52;
case 0x0c052f54u: goto P_0c052f54;
case 0x0c052f56u: goto P_0c052f56;
case 0x0c052f58u: goto P_0c052f58;
case 0x0c052f5au: goto P_0c052f5a;
case 0x0c052f5cu: goto P_0c052f5c;
case 0x0c052f5eu: goto P_0c052f5e;
case 0x0c052f60u: goto P_0c052f60;
case 0x0c052f62u: goto P_0c052f62;
case 0x0c052f64u: goto P_0c052f64;
case 0x0c052f66u: goto P_0c052f66;
case 0x0c052f68u: goto P_0c052f68;
case 0x0c052f6au: goto P_0c052f6a;
case 0x0c052f6cu: goto P_0c052f6c;
case 0x0c052f6eu: goto P_0c052f6e;
case 0x0c052f70u: goto P_0c052f70;
case 0x0c052f72u: goto P_0c052f72;
case 0x0c052f74u: goto P_0c052f74;
case 0x0c052f76u: goto P_0c052f76;
case 0x0c052f78u: goto P_0c052f78;
case 0x0c052f7au: goto P_0c052f7a;
case 0x0c052f7cu: goto P_0c052f7c;
case 0x0c052f7eu: goto P_0c052f7e;
case 0x0c052f80u: goto P_0c052f80;
case 0x0c052f82u: goto P_0c052f82;
case 0x0c052f84u: goto P_0c052f84;
case 0x0c052f86u: goto P_0c052f86;
case 0x0c052f88u: goto P_0c052f88;
case 0x0c052f8au: goto P_0c052f8a;
case 0x0c052f8cu: goto P_0c052f8c;
case 0x0c052f8eu: goto P_0c052f8e;
case 0x0c052f90u: goto P_0c052f90;
case 0x0c052f92u: goto P_0c052f92;
case 0x0c052f94u: goto P_0c052f94;
case 0x0c052f96u: goto P_0c052f96;
case 0x0c052f98u: goto P_0c052f98;
case 0x0c052f9au: goto P_0c052f9a;
case 0x0c052f9cu: goto P_0c052f9c;
case 0x0c052f9eu: goto P_0c052f9e;
case 0x0c052fa0u: goto P_0c052fa0;
case 0x0c052fa2u: goto P_0c052fa2;
case 0x0c052fa4u: goto P_0c052fa4;
case 0x0c052fa6u: goto P_0c052fa6;
case 0x0c052fa8u: goto P_0c052fa8;
case 0x0c052faau: goto P_0c052faa;
case 0x0c052facu: goto P_0c052fac;
case 0x0c052faeu: goto P_0c052fae;
case 0x0c052fb0u: goto P_0c052fb0;
case 0x0c052fb2u: goto P_0c052fb2;
case 0x0c052fb4u: goto P_0c052fb4;
case 0x0c052fb6u: goto P_0c052fb6;
case 0x0c052fb8u: goto P_0c052fb8;
case 0x0c052fbau: goto P_0c052fba;
case 0x0c052fbcu: goto P_0c052fbc;
case 0x0c052fbeu: goto P_0c052fbe;
case 0x0c052fc0u: goto P_0c052fc0;
case 0x0c052fc2u: goto P_0c052fc2;
case 0x0c052fc4u: goto P_0c052fc4;
case 0x0c052fc6u: goto P_0c052fc6;
case 0x0c052fc8u: goto P_0c052fc8;
case 0x0c052fcau: goto P_0c052fca;
case 0x0c052fccu: goto P_0c052fcc;
case 0x0c052fceu: goto P_0c052fce;
case 0x0c052fd0u: goto P_0c052fd0;
case 0x0c052fd2u: goto P_0c052fd2;
case 0x0c052fd4u: goto P_0c052fd4;
case 0x0c052fd6u: goto P_0c052fd6;
case 0x0c052fd8u: goto P_0c052fd8;
case 0x0c052fdau: goto P_0c052fda;
case 0x0c052fdcu: goto P_0c052fdc;
case 0x0c052fdeu: goto P_0c052fde;
case 0x0c052fe0u: goto P_0c052fe0;
case 0x0c052fe2u: goto P_0c052fe2;
case 0x0c052fe4u: goto P_0c052fe4;
case 0x0c052fe6u: goto P_0c052fe6;
case 0x0c052fe8u: goto P_0c052fe8;
case 0x0c052feau: goto P_0c052fea;
case 0x0c052fecu: goto P_0c052fec;
case 0x0c052feeu: goto P_0c052fee;
case 0x0c052ff0u: goto P_0c052ff0;
case 0x0c052ff2u: goto P_0c052ff2;
case 0x0c052ff4u: goto P_0c052ff4;
case 0x0c052ff6u: goto P_0c052ff6;
case 0x0c052ff8u: goto P_0c052ff8;
case 0x0c052ffau: goto P_0c052ffa;
case 0x0c052ffcu: goto P_0c052ffc;
case 0x0c052ffeu: goto P_0c052ffe;
case 0x0c053000u: goto P_0c053000;
case 0x0c053002u: goto P_0c053002;
case 0x0c053004u: goto P_0c053004;
case 0x0c053006u: goto P_0c053006;
case 0x0c053008u: goto P_0c053008;
case 0x0c05300au: goto P_0c05300a;
case 0x0c05300cu: goto P_0c05300c;
case 0x0c05300eu: goto P_0c05300e;
case 0x0c053010u: goto P_0c053010;
case 0x0c053012u: goto P_0c053012;
case 0x0c053014u: goto P_0c053014;
case 0x0c053016u: goto P_0c053016;
case 0x0c053018u: goto P_0c053018;
case 0x0c05301au: goto P_0c05301a;
case 0x0c05301cu: goto P_0c05301c;
case 0x0c05301eu: goto P_0c05301e;
case 0x0c053020u: goto P_0c053020;
case 0x0c053022u: goto P_0c053022;
case 0x0c053024u: goto P_0c053024;
case 0x0c053026u: goto P_0c053026;
case 0x0c053028u: goto P_0c053028;
case 0x0c05302au: goto P_0c05302a;
case 0x0c05302cu: goto P_0c05302c;
case 0x0c05302eu: goto P_0c05302e;
case 0x0c053030u: goto P_0c053030;
case 0x0c053032u: goto P_0c053032;
case 0x0c053034u: goto P_0c053034;
case 0x0c053036u: goto P_0c053036;
case 0x0c053038u: goto P_0c053038;
case 0x0c05303au: goto P_0c05303a;
case 0x0c05303cu: goto P_0c05303c;
case 0x0c05303eu: goto P_0c05303e;
case 0x0c053040u: goto P_0c053040;
case 0x0c054348u: goto P_0c054348;
case 0x0c05434au: goto P_0c05434a;
case 0x0c05434cu: goto P_0c05434c;
case 0x0c05434eu: goto P_0c05434e;
case 0x0c054350u: goto P_0c054350;
case 0x0c054352u: goto P_0c054352;
case 0x0c054354u: goto P_0c054354;
case 0x0c054356u: goto P_0c054356;
case 0x0c054358u: goto P_0c054358;
case 0x0c05435au: goto P_0c05435a;
case 0x0c05435cu: goto P_0c05435c;
case 0x0c05435eu: goto P_0c05435e;
case 0x0c054360u: goto P_0c054360;
case 0x0c054362u: goto P_0c054362;
case 0x0c054364u: goto P_0c054364;
case 0x0c054366u: goto P_0c054366;
case 0x0c054368u: goto P_0c054368;
case 0x0c05436au: goto P_0c05436a;
case 0x0c05436cu: goto P_0c05436c;
case 0x0c05436eu: goto P_0c05436e;
case 0x0c054370u: goto P_0c054370;
case 0x0c054372u: goto P_0c054372;
case 0x0c054374u: goto P_0c054374;
case 0x0c054376u: goto P_0c054376;
case 0x0c054378u: goto P_0c054378;
case 0x0c05437au: goto P_0c05437a;
case 0x0c05437cu: goto P_0c05437c;
case 0x0c05437eu: goto P_0c05437e;
case 0x0c054380u: goto P_0c054380;
case 0x0c054382u: goto P_0c054382;
case 0x0c054650u: goto P_0c054650;
case 0x0c054652u: goto P_0c054652;
case 0x0c054654u: goto P_0c054654;
case 0x0c054656u: goto P_0c054656;
case 0x0c054658u: goto P_0c054658;
case 0x0c05465au: goto P_0c05465a;
case 0x0c05465cu: goto P_0c05465c;
case 0x0c05465eu: goto P_0c05465e;
case 0x0c054660u: goto P_0c054660;
case 0x0c054662u: goto P_0c054662;
case 0x0c054664u: goto P_0c054664;
case 0x0c054666u: goto P_0c054666;
case 0x0c054668u: goto P_0c054668;
case 0x0c05466au: goto P_0c05466a;
case 0x0c05466cu: goto P_0c05466c;
case 0x0c05466eu: goto P_0c05466e;
case 0x0c054670u: goto P_0c054670;
case 0x0c054672u: goto P_0c054672;
case 0x0c054674u: goto P_0c054674;
case 0x0c054676u: goto P_0c054676;
case 0x0c054678u: goto P_0c054678;
case 0x0c05467au: goto P_0c05467a;
case 0x0c05467cu: goto P_0c05467c;
case 0x0c05467eu: goto P_0c05467e;
case 0x0c054680u: goto P_0c054680;
case 0x0c054682u: goto P_0c054682;
case 0x0c054684u: goto P_0c054684;
case 0x0c054686u: goto P_0c054686;
case 0x0c054688u: goto P_0c054688;
case 0x0c05468au: goto P_0c05468a;
case 0x0c05468cu: goto P_0c05468c;
case 0x0c05468eu: goto P_0c05468e;
case 0x0c054690u: goto P_0c054690;
case 0x0c054692u: goto P_0c054692;
case 0x0c054694u: goto P_0c054694;
case 0x0c054696u: goto P_0c054696;
case 0x0c054698u: goto P_0c054698;
case 0x0c05469au: goto P_0c05469a;
case 0x0c05469cu: goto P_0c05469c;
case 0x0c05469eu: goto P_0c05469e;
case 0x0c0546a0u: goto P_0c0546a0;
case 0x0c0546a2u: goto P_0c0546a2;
case 0x0c0546a4u: goto P_0c0546a4;
case 0x0c0546a6u: goto P_0c0546a6;
case 0x0c0546a8u: goto P_0c0546a8;
case 0x0c0546aau: goto P_0c0546aa;
case 0x0c0546acu: goto P_0c0546ac;
case 0x0c0546aeu: goto P_0c0546ae;
case 0x0c0546b0u: goto P_0c0546b0;
case 0x0c0546b2u: goto P_0c0546b2;
case 0x0c0546b4u: goto P_0c0546b4;
case 0x0c0546b6u: goto P_0c0546b6;
case 0x0c0546b8u: goto P_0c0546b8;
case 0x0c0546bau: goto P_0c0546ba;
case 0x0c0546bcu: goto P_0c0546bc;
case 0x0c0546beu: goto P_0c0546be;
case 0x0c0546c0u: goto P_0c0546c0;
case 0x0c0546c2u: goto P_0c0546c2;
case 0x0c0546c4u: goto P_0c0546c4;
case 0x0c0546c6u: goto P_0c0546c6;
case 0x0c0546c8u: goto P_0c0546c8;
case 0x0c0546cau: goto P_0c0546ca;
case 0x0c0546ccu: goto P_0c0546cc;
case 0x0c0546ceu: goto P_0c0546ce;
case 0x0c0546d0u: goto P_0c0546d0;
case 0x0c0546d2u: goto P_0c0546d2;
case 0x0c0546d4u: goto P_0c0546d4;
case 0x0c0546d6u: goto P_0c0546d6;
case 0x0c0546d8u: goto P_0c0546d8;
case 0x0c0546dau: goto P_0c0546da;
case 0x0c0546dcu: goto P_0c0546dc;
case 0x0c0546deu: goto P_0c0546de;
case 0x0c0546e0u: goto P_0c0546e0;
case 0x0c0546e2u: goto P_0c0546e2;
case 0x0c0546e4u: goto P_0c0546e4;
case 0x0c0546e6u: goto P_0c0546e6;
case 0x0c0546e8u: goto P_0c0546e8;
case 0x0c054704u: goto P_0c054704;
case 0x0c054706u: goto P_0c054706;
case 0x0c054708u: goto P_0c054708;
case 0x0c05470au: goto P_0c05470a;
case 0x0c05470cu: goto P_0c05470c;
case 0x0c05470eu: goto P_0c05470e;
case 0x0c054710u: goto P_0c054710;
case 0x0c054712u: goto P_0c054712;
case 0x0c054714u: goto P_0c054714;
case 0x0c054716u: goto P_0c054716;
case 0x0c054718u: goto P_0c054718;
case 0x0c05471au: goto P_0c05471a;
case 0x0c05471cu: goto P_0c05471c;
case 0x0c05471eu: goto P_0c05471e;
case 0x0c054720u: goto P_0c054720;
case 0x0c054722u: goto P_0c054722;
case 0x0c054724u: goto P_0c054724;
case 0x0c054726u: goto P_0c054726;
case 0x0c054728u: goto P_0c054728;
case 0x0c05472au: goto P_0c05472a;
case 0x0c05472cu: goto P_0c05472c;
case 0x0c05472eu: goto P_0c05472e;
case 0x0c054730u: goto P_0c054730;
case 0x0c054732u: goto P_0c054732;
case 0x0c054734u: goto P_0c054734;
case 0x0c054736u: goto P_0c054736;
case 0x0c054738u: goto P_0c054738;
case 0x0c05473au: goto P_0c05473a;
case 0x0c05473cu: goto P_0c05473c;
case 0x0c05473eu: goto P_0c05473e;
case 0x0c054740u: goto P_0c054740;
case 0x0c054742u: goto P_0c054742;
case 0x0c054744u: goto P_0c054744;
case 0x0c054746u: goto P_0c054746;
case 0x0c054748u: goto P_0c054748;
case 0x0c05474au: goto P_0c05474a;
case 0x0c05474cu: goto P_0c05474c;
case 0x0c05474eu: goto P_0c05474e;
case 0x0c054750u: goto P_0c054750;
case 0x0c054752u: goto P_0c054752;
case 0x0c054754u: goto P_0c054754;
case 0x0c054756u: goto P_0c054756;
case 0x0c054758u: goto P_0c054758;
case 0x0c05475au: goto P_0c05475a;
case 0x0c05475cu: goto P_0c05475c;
case 0x0c05475eu: goto P_0c05475e;
case 0x0c054760u: goto P_0c054760;
case 0x0c054762u: goto P_0c054762;
case 0x0c054764u: goto P_0c054764;
case 0x0c054766u: goto P_0c054766;
case 0x0c054768u: goto P_0c054768;
case 0x0c05476au: goto P_0c05476a;
case 0x0c05476cu: goto P_0c05476c;
case 0x0c05476eu: goto P_0c05476e;
case 0x0c054770u: goto P_0c054770;
case 0x0c054772u: goto P_0c054772;
case 0x0c054774u: goto P_0c054774;
case 0x0c054776u: goto P_0c054776;
case 0x0c054778u: goto P_0c054778;
case 0x0c05477au: goto P_0c05477a;
case 0x0c05477cu: goto P_0c05477c;
case 0x0c05477eu: goto P_0c05477e;
case 0x0c054780u: goto P_0c054780;
case 0x0c054782u: goto P_0c054782;
case 0x0c054784u: goto P_0c054784;
case 0x0c054786u: goto P_0c054786;
case 0x0c054788u: goto P_0c054788;
case 0x0c05478au: goto P_0c05478a;
case 0x0c05478cu: goto P_0c05478c;
case 0x0c05478eu: goto P_0c05478e;
case 0x0c054790u: goto P_0c054790;
case 0x0c054792u: goto P_0c054792;
case 0x0c054794u: goto P_0c054794;
case 0x0c054796u: goto P_0c054796;
case 0x0c054798u: goto P_0c054798;
case 0x0c05479au: goto P_0c05479a;
case 0x0c05479cu: goto P_0c05479c;
case 0x0c05479eu: goto P_0c05479e;
case 0x0c0547a0u: goto P_0c0547a0;
case 0x0c0547a2u: goto P_0c0547a2;
case 0x0c0547a4u: goto P_0c0547a4;
case 0x0c0547a6u: goto P_0c0547a6;
case 0x0c0547a8u: goto P_0c0547a8;
case 0x0c0547aau: goto P_0c0547aa;
case 0x0c0547acu: goto P_0c0547ac;
case 0x0c0547aeu: goto P_0c0547ae;
case 0x0c0547b0u: goto P_0c0547b0;
case 0x0c0547b2u: goto P_0c0547b2;
case 0x0c0547b4u: goto P_0c0547b4;
case 0x0c0547b6u: goto P_0c0547b6;
case 0x0c0547b8u: goto P_0c0547b8;
case 0x0c0547bau: goto P_0c0547ba;
case 0x0c0547bcu: goto P_0c0547bc;
case 0x0c0547beu: goto P_0c0547be;
case 0x0c0547c0u: goto P_0c0547c0;
case 0x0c0547c2u: goto P_0c0547c2;
case 0x0c0547c4u: goto P_0c0547c4;
case 0x0c0547c6u: goto P_0c0547c6;
case 0x0c0547c8u: goto P_0c0547c8;
case 0x0c0547cau: goto P_0c0547ca;
case 0x0c0547ccu: goto P_0c0547cc;
case 0x0c0547ceu: goto P_0c0547ce;
case 0x0c0547d0u: goto P_0c0547d0;
case 0x0c0547d2u: goto P_0c0547d2;
case 0x0c0547d4u: goto P_0c0547d4;
case 0x0c0547d6u: goto P_0c0547d6;
case 0x0c0547d8u: goto P_0c0547d8;
case 0x0c0547dau: goto P_0c0547da;
case 0x0c0547dcu: goto P_0c0547dc;
case 0x0c0547deu: goto P_0c0547de;
case 0x0c0547e0u: goto P_0c0547e0;
case 0x0c0547e2u: goto P_0c0547e2;
case 0x0c0547e4u: goto P_0c0547e4;
case 0x0c0547e6u: goto P_0c0547e6;
case 0x0c0547e8u: goto P_0c0547e8;
case 0x0c0547eau: goto P_0c0547ea;
case 0x0c0547ecu: goto P_0c0547ec;
case 0x0c0547eeu: goto P_0c0547ee;
case 0x0c0547f0u: goto P_0c0547f0;
case 0x0c0547f2u: goto P_0c0547f2;
case 0x0c0547f4u: goto P_0c0547f4;
case 0x0c0547f6u: goto P_0c0547f6;
case 0x0c0547f8u: goto P_0c0547f8;
case 0x0c0547fau: goto P_0c0547fa;
case 0x0c0547fcu: goto P_0c0547fc;
case 0x0c0547feu: goto P_0c0547fe;
case 0x0c054800u: goto P_0c054800;
case 0x0c054802u: goto P_0c054802;
case 0x0c054804u: goto P_0c054804;
case 0x0c054806u: goto P_0c054806;
case 0x0c058348u: goto P_0c058348;
case 0x0c05834au: goto P_0c05834a;
case 0x0c05834cu: goto P_0c05834c;
case 0x0c05834eu: goto P_0c05834e;
case 0x0c058350u: goto P_0c058350;
case 0x0c058352u: goto P_0c058352;
case 0x0c058354u: goto P_0c058354;
case 0x0c058356u: goto P_0c058356;
case 0x0c058358u: goto P_0c058358;
case 0x0c05835au: goto P_0c05835a;
case 0x0c05835cu: goto P_0c05835c;
case 0x0c05835eu: goto P_0c05835e;
case 0x0c058360u: goto P_0c058360;
case 0x0c058362u: goto P_0c058362;
case 0x0c058364u: goto P_0c058364;
case 0x0c058366u: goto P_0c058366;
case 0x0c058368u: goto P_0c058368;
case 0x0c05836au: goto P_0c05836a;
case 0x0c05836cu: goto P_0c05836c;
case 0x0c05836eu: goto P_0c05836e;
case 0x0c058370u: goto P_0c058370;
case 0x0c058372u: goto P_0c058372;
case 0x0c058374u: goto P_0c058374;
case 0x0c058376u: goto P_0c058376;
case 0x0c058378u: goto P_0c058378;
case 0x0c05837au: goto P_0c05837a;
case 0x0c05837cu: goto P_0c05837c;
case 0x0c05837eu: goto P_0c05837e;
case 0x0c058380u: goto P_0c058380;
case 0x0c058382u: goto P_0c058382;
case 0x0c058384u: goto P_0c058384;
case 0x0c058386u: goto P_0c058386;
case 0x0c058388u: goto P_0c058388;
case 0x0c05838au: goto P_0c05838a;
case 0x0c05838cu: goto P_0c05838c;
case 0x0c05838eu: goto P_0c05838e;
case 0x0c058390u: goto P_0c058390;
case 0x0c058392u: goto P_0c058392;
case 0x0c058394u: goto P_0c058394;
case 0x0c058396u: goto P_0c058396;
case 0x0c058398u: goto P_0c058398;
case 0x0c05839au: goto P_0c05839a;
case 0x0c05839cu: goto P_0c05839c;
case 0x0c05839eu: goto P_0c05839e;
case 0x0c0583a0u: goto P_0c0583a0;
case 0x0c0583a2u: goto P_0c0583a2;
case 0x0c0583a4u: goto P_0c0583a4;
case 0x0c0583a6u: goto P_0c0583a6;
case 0x0c0583a8u: goto P_0c0583a8;
case 0x0c0583aau: goto P_0c0583aa;
case 0x0c0583acu: goto P_0c0583ac;
case 0x0c0583aeu: goto P_0c0583ae;
case 0x0c0583b0u: goto P_0c0583b0;
case 0x0c0583b2u: goto P_0c0583b2;
case 0x0c0583b4u: goto P_0c0583b4;
case 0x0c0583b6u: goto P_0c0583b6;
case 0x0c0583b8u: goto P_0c0583b8;
case 0x0c0583bau: goto P_0c0583ba;
case 0x0c0583bcu: goto P_0c0583bc;
case 0x0c0583beu: goto P_0c0583be;
case 0x0c0583c0u: goto P_0c0583c0;
case 0x0c0583c2u: goto P_0c0583c2;
case 0x0c0583c4u: goto P_0c0583c4;
case 0x0c0583c6u: goto P_0c0583c6;
case 0x0c0583c8u: goto P_0c0583c8;
case 0x0c0583cau: goto P_0c0583ca;
case 0x0c0583ccu: goto P_0c0583cc;
case 0x0c0583ceu: goto P_0c0583ce;
case 0x0c0583d0u: goto P_0c0583d0;
case 0x0c0583d2u: goto P_0c0583d2;
case 0x0c0583d4u: goto P_0c0583d4;
case 0x0c0583d6u: goto P_0c0583d6;
case 0x0c0583d8u: goto P_0c0583d8;
case 0x0c0583dau: goto P_0c0583da;
case 0x0c0583dcu: goto P_0c0583dc;
case 0x0c0583deu: goto P_0c0583de;
case 0x0c0583e0u: goto P_0c0583e0;
case 0x0c0583e2u: goto P_0c0583e2;
case 0x0c0583e4u: goto P_0c0583e4;
case 0x0c0583e6u: goto P_0c0583e6;
case 0x0c0583e8u: goto P_0c0583e8;
case 0x0c0583eau: goto P_0c0583ea;
case 0x0c0583ecu: goto P_0c0583ec;
case 0x0c0583eeu: goto P_0c0583ee;
case 0x0c0583f0u: goto P_0c0583f0;
case 0x0c0583f2u: goto P_0c0583f2;
case 0x0c0583f4u: goto P_0c0583f4;
case 0x0c0583f6u: goto P_0c0583f6;
case 0x0c0583f8u: goto P_0c0583f8;
case 0x0c0583fau: goto P_0c0583fa;
case 0x0c0583fcu: goto P_0c0583fc;
case 0x0c0583feu: goto P_0c0583fe;
case 0x0c058400u: goto P_0c058400;
case 0x0c058402u: goto P_0c058402;
case 0x0c058404u: goto P_0c058404;
case 0x0c058406u: goto P_0c058406;
case 0x0c058408u: goto P_0c058408;
case 0x0c05840au: goto P_0c05840a;
case 0x0c05840cu: goto P_0c05840c;
case 0x0c05840eu: goto P_0c05840e;
case 0x0c058410u: goto P_0c058410;
case 0x0c058412u: goto P_0c058412;
case 0x0c058414u: goto P_0c058414;
case 0x0c058416u: goto P_0c058416;
case 0x0c058418u: goto P_0c058418;
case 0x0c05841au: goto P_0c05841a;
case 0x0c05841cu: goto P_0c05841c;
case 0x0c05841eu: goto P_0c05841e;
case 0x0c058420u: goto P_0c058420;
case 0x0c058422u: goto P_0c058422;
case 0x0c058424u: goto P_0c058424;
case 0x0c058426u: goto P_0c058426;
case 0x0c058428u: goto P_0c058428;
case 0x0c05842au: goto P_0c05842a;
case 0x0c05842cu: goto P_0c05842c;
case 0x0c05842eu: goto P_0c05842e;
case 0x0c058430u: goto P_0c058430;
case 0x0c058432u: goto P_0c058432;
case 0x0c058434u: goto P_0c058434;
case 0x0c058436u: goto P_0c058436;
case 0x0c058438u: goto P_0c058438;
case 0x0c05843au: goto P_0c05843a;
case 0x0c05843cu: goto P_0c05843c;
case 0x0c05843eu: goto P_0c05843e;
case 0x0c058440u: goto P_0c058440;
case 0x0c058442u: goto P_0c058442;
case 0x0c058444u: goto P_0c058444;
case 0x0c058446u: goto P_0c058446;
case 0x0c058448u: goto P_0c058448;
case 0x0c05844au: goto P_0c05844a;
case 0x0c05844cu: goto P_0c05844c;
case 0x0c05844eu: goto P_0c05844e;
case 0x0c058450u: goto P_0c058450;
case 0x0c058452u: goto P_0c058452;
case 0x0c058454u: goto P_0c058454;
case 0x0c058456u: goto P_0c058456;
case 0x0c058458u: goto P_0c058458;
case 0x0c05845au: goto P_0c05845a;
case 0x0c05845cu: goto P_0c05845c;
case 0x0c05845eu: goto P_0c05845e;
case 0x0c058460u: goto P_0c058460;
case 0x0c058462u: goto P_0c058462;
case 0x0c058464u: goto P_0c058464;
case 0x0c058466u: goto P_0c058466;
case 0x0c058468u: goto P_0c058468;
case 0x0c05846au: goto P_0c05846a;
case 0x0c05846cu: goto P_0c05846c;
case 0x0c05846eu: goto P_0c05846e;
case 0x0c058470u: goto P_0c058470;
case 0x0c058472u: goto P_0c058472;
case 0x0c058474u: goto P_0c058474;
case 0x0c058476u: goto P_0c058476;
case 0x0c058478u: goto P_0c058478;
case 0x0c05847au: goto P_0c05847a;
case 0x0c05847cu: goto P_0c05847c;
case 0x0c05847eu: goto P_0c05847e;
case 0x0c058480u: goto P_0c058480;
case 0x0c058482u: goto P_0c058482;
case 0x0c058484u: goto P_0c058484;
case 0x0c058486u: goto P_0c058486;
case 0x0c058488u: goto P_0c058488;
case 0x0c05848au: goto P_0c05848a;
case 0x0c05848cu: goto P_0c05848c;
case 0x0c05848eu: goto P_0c05848e;
case 0x0c058490u: goto P_0c058490;
case 0x0c058492u: goto P_0c058492;
case 0x0c058494u: goto P_0c058494;
case 0x0c058496u: goto P_0c058496;
case 0x0c058498u: goto P_0c058498;
case 0x0c05849au: goto P_0c05849a;
case 0x0c05849cu: goto P_0c05849c;
case 0x0c05849eu: goto P_0c05849e;
case 0x0c0584a0u: goto P_0c0584a0;
case 0x0c0584a2u: goto P_0c0584a2;
case 0x0c0584a4u: goto P_0c0584a4;
case 0x0c0584a6u: goto P_0c0584a6;
case 0x0c0584a8u: goto P_0c0584a8;
case 0x0c0584aau: goto P_0c0584aa;
case 0x0c0584acu: goto P_0c0584ac;
case 0x0c0584aeu: goto P_0c0584ae;
case 0x0c0584b0u: goto P_0c0584b0;
case 0x0c0584b2u: goto P_0c0584b2;
case 0x0c0584b4u: goto P_0c0584b4;
case 0x0c0584b6u: goto P_0c0584b6;
case 0x0c0584b8u: goto P_0c0584b8;
case 0x0c0584bau: goto P_0c0584ba;
case 0x0c0584bcu: goto P_0c0584bc;
case 0x0c0584beu: goto P_0c0584be;
case 0x0c0584c0u: goto P_0c0584c0;
case 0x0c0584c2u: goto P_0c0584c2;
case 0x0c0584c4u: goto P_0c0584c4;
case 0x0c0584c6u: goto P_0c0584c6;
case 0x0c0584c8u: goto P_0c0584c8;
case 0x0c0584cau: goto P_0c0584ca;
case 0x0c0584ccu: goto P_0c0584cc;
case 0x0c0584ceu: goto P_0c0584ce;
case 0x0c0584d0u: goto P_0c0584d0;
case 0x0c0584d2u: goto P_0c0584d2;
case 0x0c0584d4u: goto P_0c0584d4;
case 0x0c0584d6u: goto P_0c0584d6;
case 0x0c0584d8u: goto P_0c0584d8;
case 0x0c0584dau: goto P_0c0584da;
case 0x0c0584dcu: goto P_0c0584dc;
case 0x0c0584deu: goto P_0c0584de;
case 0x0c0584e0u: goto P_0c0584e0;
case 0x0c058540u: goto P_0c058540;
case 0x0c058542u: goto P_0c058542;
case 0x0c058544u: goto P_0c058544;
case 0x0c058546u: goto P_0c058546;
case 0x0c058548u: goto P_0c058548;
case 0x0c05854au: goto P_0c05854a;
case 0x0c05854cu: goto P_0c05854c;
case 0x0c05854eu: goto P_0c05854e;
case 0x0c058550u: goto P_0c058550;
case 0x0c058552u: goto P_0c058552;
case 0x0c058554u: goto P_0c058554;
case 0x0c058556u: goto P_0c058556;
case 0x0c058558u: goto P_0c058558;
case 0x0c05855au: goto P_0c05855a;
case 0x0c05855cu: goto P_0c05855c;
case 0x0c05855eu: goto P_0c05855e;
case 0x0c058560u: goto P_0c058560;
case 0x0c058562u: goto P_0c058562;
case 0x0c058564u: goto P_0c058564;
case 0x0c058566u: goto P_0c058566;
case 0x0c058568u: goto P_0c058568;
case 0x0c05856au: goto P_0c05856a;
case 0x0c05856cu: goto P_0c05856c;
case 0x0c05856eu: goto P_0c05856e;
case 0x0c058570u: goto P_0c058570;
case 0x0c058572u: goto P_0c058572;
case 0x0c058574u: goto P_0c058574;
case 0x0c058576u: goto P_0c058576;
case 0x0c058578u: goto P_0c058578;
case 0x0c05857au: goto P_0c05857a;
case 0x0c05857cu: goto P_0c05857c;
case 0x0c05857eu: goto P_0c05857e;
case 0x0c058580u: goto P_0c058580;
case 0x0c058582u: goto P_0c058582;
case 0x0c058584u: goto P_0c058584;
case 0x0c058586u: goto P_0c058586;
case 0x0c058588u: goto P_0c058588;
case 0x0c05858au: goto P_0c05858a;
case 0x0c05858cu: goto P_0c05858c;
case 0x0c05858eu: goto P_0c05858e;
case 0x0c058590u: goto P_0c058590;
case 0x0c058592u: goto P_0c058592;
case 0x0c058594u: goto P_0c058594;
case 0x0c058596u: goto P_0c058596;
case 0x0c058598u: goto P_0c058598;
case 0x0c05859au: goto P_0c05859a;
case 0x0c05859cu: goto P_0c05859c;
case 0x0c05859eu: goto P_0c05859e;
case 0x0c0585a0u: goto P_0c0585a0;
case 0x0c0585a2u: goto P_0c0585a2;
case 0x0c0585a4u: goto P_0c0585a4;
case 0x0c0585a6u: goto P_0c0585a6;
case 0x0c0585a8u: goto P_0c0585a8;
case 0x0c0585aau: goto P_0c0585aa;
case 0x0c0585acu: goto P_0c0585ac;
case 0x0c0585aeu: goto P_0c0585ae;
case 0x0c0585b0u: goto P_0c0585b0;
case 0x0c0585b2u: goto P_0c0585b2;
case 0x0c0585b4u: goto P_0c0585b4;
case 0x0c0585b6u: goto P_0c0585b6;
case 0x0c0585b8u: goto P_0c0585b8;
case 0x0c0585bau: goto P_0c0585ba;
case 0x0c0585bcu: goto P_0c0585bc;
case 0x0c0585beu: goto P_0c0585be;
case 0x0c0585c0u: goto P_0c0585c0;
case 0x0c0585c2u: goto P_0c0585c2;
case 0x0c0585c4u: goto P_0c0585c4;
case 0x0c0585c6u: goto P_0c0585c6;
case 0x0c0585c8u: goto P_0c0585c8;
case 0x0c0585cau: goto P_0c0585ca;
case 0x0c0585ccu: goto P_0c0585cc;
case 0x0c0585ceu: goto P_0c0585ce;
case 0x0c0585d0u: goto P_0c0585d0;
case 0x0c0585d2u: goto P_0c0585d2;
case 0x0c0585d4u: goto P_0c0585d4;
case 0x0c0585d6u: goto P_0c0585d6;
case 0x0c0585d8u: goto P_0c0585d8;
case 0x0c0585dau: goto P_0c0585da;
case 0x0c0585dcu: goto P_0c0585dc;
case 0x0c0585deu: goto P_0c0585de;
case 0x0c0585e0u: goto P_0c0585e0;
case 0x0c0585e2u: goto P_0c0585e2;
case 0x0c0585e4u: goto P_0c0585e4;
case 0x0c0585e6u: goto P_0c0585e6;
case 0x0c0585e8u: goto P_0c0585e8;
case 0x0c0585eau: goto P_0c0585ea;
case 0x0c0585ecu: goto P_0c0585ec;
case 0x0c0585eeu: goto P_0c0585ee;
case 0x0c0585f0u: goto P_0c0585f0;
case 0x0c0585f2u: goto P_0c0585f2;
case 0x0c0585f4u: goto P_0c0585f4;
case 0x0c0585f6u: goto P_0c0585f6;
case 0x0c0585f8u: goto P_0c0585f8;
case 0x0c0585fau: goto P_0c0585fa;
case 0x0c0585fcu: goto P_0c0585fc;
case 0x0c0585feu: goto P_0c0585fe;
case 0x0c058600u: goto P_0c058600;
case 0x0c058602u: goto P_0c058602;
case 0x0c058604u: goto P_0c058604;
case 0x0c058606u: goto P_0c058606;
case 0x0c058608u: goto P_0c058608;
case 0x0c05860au: goto P_0c05860a;
case 0x0c05860cu: goto P_0c05860c;
case 0x0c05860eu: goto P_0c05860e;
case 0x0c058610u: goto P_0c058610;
case 0x0c058612u: goto P_0c058612;
case 0x0c058614u: goto P_0c058614;
case 0x0c058616u: goto P_0c058616;
case 0x0c058618u: goto P_0c058618;
case 0x0c05861au: goto P_0c05861a;
case 0x0c05861cu: goto P_0c05861c;
case 0x0c05861eu: goto P_0c05861e;
case 0x0c058620u: goto P_0c058620;
case 0x0c058622u: goto P_0c058622;
case 0x0c058624u: goto P_0c058624;
case 0x0c058626u: goto P_0c058626;
case 0x0c058628u: goto P_0c058628;
case 0x0c05862au: goto P_0c05862a;
case 0x0c05862cu: goto P_0c05862c;
case 0x0c05862eu: goto P_0c05862e;
case 0x0c058630u: goto P_0c058630;
case 0x0c058632u: goto P_0c058632;
case 0x0c058634u: goto P_0c058634;
case 0x0c058636u: goto P_0c058636;
case 0x0c058638u: goto P_0c058638;
case 0x0c05863au: goto P_0c05863a;
case 0x0c05863cu: goto P_0c05863c;
case 0x0c05863eu: goto P_0c05863e;
case 0x0c058640u: goto P_0c058640;
case 0x0c058642u: goto P_0c058642;
case 0x0c058644u: goto P_0c058644;
case 0x0c058646u: goto P_0c058646;
case 0x0c058648u: goto P_0c058648;
case 0x0c05864au: goto P_0c05864a;
case 0x0c05864cu: goto P_0c05864c;
case 0x0c05864eu: goto P_0c05864e;
case 0x0c058650u: goto P_0c058650;
case 0x0c058652u: goto P_0c058652;
case 0x0c058654u: goto P_0c058654;
case 0x0c058656u: goto P_0c058656;
case 0x0c058658u: goto P_0c058658;
case 0x0c05865au: goto P_0c05865a;
case 0x0c058768u: goto P_0c058768;
case 0x0c05876au: goto P_0c05876a;
case 0x0c05876cu: goto P_0c05876c;
case 0x0c05876eu: goto P_0c05876e;
case 0x0c058770u: goto P_0c058770;
case 0x0c058772u: goto P_0c058772;
case 0x0c058774u: goto P_0c058774;
case 0x0c058776u: goto P_0c058776;
case 0x0c058778u: goto P_0c058778;
case 0x0c05877eu: goto P_0c05877e;
case 0x0c058780u: goto P_0c058780;
case 0x0c058782u: goto P_0c058782;
case 0x0c058784u: goto P_0c058784;
case 0x0c058786u: goto P_0c058786;
case 0x0c058788u: goto P_0c058788;
case 0x0c05878au: goto P_0c05878a;
case 0x0c05878cu: goto P_0c05878c;
case 0x0c05878eu: goto P_0c05878e;
case 0x0c058790u: goto P_0c058790;
case 0x0c05879au: goto P_0c05879a;
case 0x0c05879cu: goto P_0c05879c;
case 0x0c05879eu: goto P_0c05879e;
case 0x0c0587a0u: goto P_0c0587a0;
case 0x0c0587a2u: goto P_0c0587a2;
case 0x0c0587a4u: goto P_0c0587a4;
case 0x0c0587a6u: goto P_0c0587a6;
case 0x0c0587a8u: goto P_0c0587a8;
case 0x0c0587aau: goto P_0c0587aa;
case 0x0c0587acu: goto P_0c0587ac;
case 0x0c0587aeu: goto P_0c0587ae;
case 0x0c0587b0u: goto P_0c0587b0;
case 0x0c0587b2u: goto P_0c0587b2;
case 0x0c0587b4u: goto P_0c0587b4;
case 0x0c0587b6u: goto P_0c0587b6;
case 0x0c0587b8u: goto P_0c0587b8;
case 0x0c0587bau: goto P_0c0587ba;
case 0x0c0587bcu: goto P_0c0587bc;
case 0x0c0587beu: goto P_0c0587be;
case 0x0c0587c0u: goto P_0c0587c0;
case 0x0c0587c2u: goto P_0c0587c2;
case 0x0c0587c4u: goto P_0c0587c4;
case 0x0c0587c6u: goto P_0c0587c6;
case 0x0c0587c8u: goto P_0c0587c8;
case 0x0c0587cau: goto P_0c0587ca;
case 0x0c0587ccu: goto P_0c0587cc;
case 0x0c0587ceu: goto P_0c0587ce;
case 0x0c0587d0u: goto P_0c0587d0;
case 0x0c0587d2u: goto P_0c0587d2;
case 0x0c0587d4u: goto P_0c0587d4;
case 0x0c0587d6u: goto P_0c0587d6;
case 0x0c0587d8u: goto P_0c0587d8;
case 0x0c0587dau: goto P_0c0587da;
case 0x0c0587dcu: goto P_0c0587dc;
case 0x0c0587deu: goto P_0c0587de;
case 0x0c0587e0u: goto P_0c0587e0;
case 0x0c0587e2u: goto P_0c0587e2;
case 0x0c0587e4u: goto P_0c0587e4;
case 0x0c0587e6u: goto P_0c0587e6;
case 0x0c0587e8u: goto P_0c0587e8;
case 0x0c0587eau: goto P_0c0587ea;
case 0x0c0587ecu: goto P_0c0587ec;
case 0x0c0587eeu: goto P_0c0587ee;
case 0x0c0587f0u: goto P_0c0587f0;
case 0x0c0587f2u: goto P_0c0587f2;
case 0x0c0587f4u: goto P_0c0587f4;
case 0x0c0587f6u: goto P_0c0587f6;
case 0x0c0587f8u: goto P_0c0587f8;
case 0x0c0587fau: goto P_0c0587fa;
case 0x0c0587fcu: goto P_0c0587fc;
case 0x0c0587feu: goto P_0c0587fe;
case 0x0c058800u: goto P_0c058800;
case 0x0c058802u: goto P_0c058802;
case 0x0c058804u: goto P_0c058804;
case 0x0c058806u: goto P_0c058806;
case 0x0c058808u: goto P_0c058808;
case 0x0c05880au: goto P_0c05880a;
case 0x0c05880cu: goto P_0c05880c;
case 0x0c05880eu: goto P_0c05880e;
case 0x0c058810u: goto P_0c058810;
case 0x0c058812u: goto P_0c058812;
case 0x0c058814u: goto P_0c058814;
case 0x0c058816u: goto P_0c058816;
case 0x0c058818u: goto P_0c058818;
case 0x0c05881au: goto P_0c05881a;
case 0x0c05881cu: goto P_0c05881c;
case 0x0c05881eu: goto P_0c05881e;
case 0x0c058820u: goto P_0c058820;
case 0x0c058822u: goto P_0c058822;
case 0x0c058824u: goto P_0c058824;
case 0x0c058826u: goto P_0c058826;
case 0x0c058828u: goto P_0c058828;
case 0x0c05882au: goto P_0c05882a;
case 0x0c05882cu: goto P_0c05882c;
case 0x0c05882eu: goto P_0c05882e;
case 0x0c058830u: goto P_0c058830;
case 0x0c058832u: goto P_0c058832;
case 0x0c058834u: goto P_0c058834;
case 0x0c058836u: goto P_0c058836;
case 0x0c058838u: goto P_0c058838;
case 0x0c05883au: goto P_0c05883a;
case 0x0c05883cu: goto P_0c05883c;
case 0x0c05883eu: goto P_0c05883e;
case 0x0c058840u: goto P_0c058840;
case 0x0c058842u: goto P_0c058842;
case 0x0c058844u: goto P_0c058844;
case 0x0c058846u: goto P_0c058846;
case 0x0c058848u: goto P_0c058848;
case 0x0c05884au: goto P_0c05884a;
case 0x0c05884cu: goto P_0c05884c;
case 0x0c05884eu: goto P_0c05884e;
case 0x0c058850u: goto P_0c058850;
case 0x0c058852u: goto P_0c058852;
case 0x0c058854u: goto P_0c058854;
case 0x0c058856u: goto P_0c058856;
case 0x0c058858u: goto P_0c058858;
case 0x0c05885au: goto P_0c05885a;
case 0x0c05885cu: goto P_0c05885c;
case 0x0c05885eu: goto P_0c05885e;
case 0x0c058860u: goto P_0c058860;
case 0x0c058862u: goto P_0c058862;
case 0x0c058864u: goto P_0c058864;
case 0x0c058866u: goto P_0c058866;
case 0x0c058868u: goto P_0c058868;
case 0x0c0588f0u: goto P_0c0588f0;
case 0x0c0588f2u: goto P_0c0588f2;
case 0x0c0588f4u: goto P_0c0588f4;
case 0x0c0588f6u: goto P_0c0588f6;
case 0x0c0588f8u: goto P_0c0588f8;
case 0x0c0588fau: goto P_0c0588fa;
case 0x0c0588fcu: goto P_0c0588fc;
case 0x0c0588feu: goto P_0c0588fe;
case 0x0c058900u: goto P_0c058900;
case 0x0c058902u: goto P_0c058902;
case 0x0c058904u: goto P_0c058904;
case 0x0c058906u: goto P_0c058906;
case 0x0c058908u: goto P_0c058908;
case 0x0c05890au: goto P_0c05890a;
case 0x0c05890cu: goto P_0c05890c;
case 0x0c05890eu: goto P_0c05890e;
case 0x0c058910u: goto P_0c058910;
case 0x0c058912u: goto P_0c058912;
case 0x0c058914u: goto P_0c058914;
case 0x0c058916u: goto P_0c058916;
case 0x0c058918u: goto P_0c058918;
case 0x0c05891au: goto P_0c05891a;
case 0x0c05891cu: goto P_0c05891c;
case 0x0c05891eu: goto P_0c05891e;
case 0x0c058920u: goto P_0c058920;
case 0x0c058922u: goto P_0c058922;
case 0x0c058924u: goto P_0c058924;
case 0x0c058926u: goto P_0c058926;
case 0x0c058928u: goto P_0c058928;
case 0x0c05892au: goto P_0c05892a;
case 0x0c05892cu: goto P_0c05892c;
case 0x0c05892eu: goto P_0c05892e;
case 0x0c058930u: goto P_0c058930;
case 0x0c058932u: goto P_0c058932;
case 0x0c058934u: goto P_0c058934;
case 0x0c058936u: goto P_0c058936;
case 0x0c058938u: goto P_0c058938;
case 0x0c05893au: goto P_0c05893a;
case 0x0c05893cu: goto P_0c05893c;
case 0x0c05893eu: goto P_0c05893e;
case 0x0c058940u: goto P_0c058940;
case 0x0c058942u: goto P_0c058942;
case 0x0c058944u: goto P_0c058944;
case 0x0c058946u: goto P_0c058946;
case 0x0c058948u: goto P_0c058948;
case 0x0c05894au: goto P_0c05894a;
case 0x0c05894cu: goto P_0c05894c;
case 0x0c05894eu: goto P_0c05894e;
case 0x0c058950u: goto P_0c058950;
case 0x0c058952u: goto P_0c058952;
case 0x0c058954u: goto P_0c058954;
case 0x0c058956u: goto P_0c058956;
case 0x0c058958u: goto P_0c058958;
case 0x0c05895au: goto P_0c05895a;
case 0x0c05895cu: goto P_0c05895c;
case 0x0c05895eu: goto P_0c05895e;
case 0x0c058960u: goto P_0c058960;
case 0x0c058962u: goto P_0c058962;
case 0x0c058964u: goto P_0c058964;
case 0x0c058966u: goto P_0c058966;
case 0x0c058968u: goto P_0c058968;
case 0x0c05896au: goto P_0c05896a;
case 0x0c05896cu: goto P_0c05896c;
case 0x0c05896eu: goto P_0c05896e;
case 0x0c058970u: goto P_0c058970;
case 0x0c058972u: goto P_0c058972;
case 0x0c058974u: goto P_0c058974;
case 0x0c058976u: goto P_0c058976;
case 0x0c058a5cu: goto P_0c058a5c;
case 0x0c058a5eu: goto P_0c058a5e;
case 0x0c058a60u: goto P_0c058a60;
case 0x0c058a62u: goto P_0c058a62;
case 0x0c058a64u: goto P_0c058a64;
case 0x0c058a66u: goto P_0c058a66;
case 0x0c058a68u: goto P_0c058a68;
case 0x0c058a6au: goto P_0c058a6a;
case 0x0c058a6cu: goto P_0c058a6c;
case 0x0c058a6eu: goto P_0c058a6e;
case 0x0c058a70u: goto P_0c058a70;
case 0x0c058a72u: goto P_0c058a72;
case 0x0c058a74u: goto P_0c058a74;
case 0x0c058a76u: goto P_0c058a76;
case 0x0c058a78u: goto P_0c058a78;
case 0x0c058a7au: goto P_0c058a7a;
case 0x0c058a7cu: goto P_0c058a7c;
case 0x0c058a7eu: goto P_0c058a7e;
case 0x0c058a80u: goto P_0c058a80;
case 0x0c058a82u: goto P_0c058a82;
case 0x0c058a84u: goto P_0c058a84;
case 0x0c058a86u: goto P_0c058a86;
case 0x0c058a88u: goto P_0c058a88;
case 0x0c058a8au: goto P_0c058a8a;
case 0x0c058a8cu: goto P_0c058a8c;
case 0x0c058a8eu: goto P_0c058a8e;
case 0x0c058a90u: goto P_0c058a90;
case 0x0c058a92u: goto P_0c058a92;
case 0x0c058a94u: goto P_0c058a94;
case 0x0c058a96u: goto P_0c058a96;
case 0x0c058a98u: goto P_0c058a98;
case 0x0c058a9au: goto P_0c058a9a;
case 0x0c058a9cu: goto P_0c058a9c;
case 0x0c058a9eu: goto P_0c058a9e;
case 0x0c058aa0u: goto P_0c058aa0;
case 0x0c058aa2u: goto P_0c058aa2;
case 0x0c058aa4u: goto P_0c058aa4;
case 0x0c058aa6u: goto P_0c058aa6;
case 0x0c058aa8u: goto P_0c058aa8;
case 0x0c058aaau: goto P_0c058aaa;
case 0x0c058aacu: goto P_0c058aac;
case 0x0c058aaeu: goto P_0c058aae;
case 0x0c058ab0u: goto P_0c058ab0;
case 0x0c058ab2u: goto P_0c058ab2;
case 0x0c058ab4u: goto P_0c058ab4;
case 0x0c058ab6u: goto P_0c058ab6;
case 0x0c058ab8u: goto P_0c058ab8;
case 0x0c058abau: goto P_0c058aba;
case 0x0c058abcu: goto P_0c058abc;
case 0x0c058abeu: goto P_0c058abe;
case 0x0c058ac0u: goto P_0c058ac0;
case 0x0c058ac2u: goto P_0c058ac2;
case 0x0c058ac4u: goto P_0c058ac4;
case 0x0c058ac6u: goto P_0c058ac6;
case 0x0c058ac8u: goto P_0c058ac8;
case 0x0c058acau: goto P_0c058aca;
case 0x0c058accu: goto P_0c058acc;
case 0x0c058aceu: goto P_0c058ace;
case 0x0c058ad0u: goto P_0c058ad0;
case 0x0c058ad2u: goto P_0c058ad2;
case 0x0c058ad4u: goto P_0c058ad4;
case 0x0c058ad6u: goto P_0c058ad6;
case 0x0c058ad8u: goto P_0c058ad8;
case 0x0c058adau: goto P_0c058ada;
case 0x0c058adcu: goto P_0c058adc;
case 0x0c058adeu: goto P_0c058ade;
case 0x0c058ae0u: goto P_0c058ae0;
case 0x0c058ae2u: goto P_0c058ae2;
case 0x0c058ae4u: goto P_0c058ae4;
case 0x0c058ae6u: goto P_0c058ae6;
case 0x0c058ae8u: goto P_0c058ae8;
case 0x0c058aeau: goto P_0c058aea;
case 0x0c058aecu: goto P_0c058aec;
case 0x0c058aeeu: goto P_0c058aee;
case 0x0c058af0u: goto P_0c058af0;
case 0x0c058af2u: goto P_0c058af2;
case 0x0c058af4u: goto P_0c058af4;
case 0x0c058af6u: goto P_0c058af6;
case 0x0c058af8u: goto P_0c058af8;
case 0x0c058afau: goto P_0c058afa;
case 0x0c058afcu: goto P_0c058afc;
case 0x0c058afeu: goto P_0c058afe;
case 0x0c058b00u: goto P_0c058b00;
case 0x0c058b02u: goto P_0c058b02;
case 0x0c058b04u: goto P_0c058b04;
case 0x0c058b06u: goto P_0c058b06;
case 0x0c058b08u: goto P_0c058b08;
case 0x0c058b0au: goto P_0c058b0a;
case 0x0c058b0cu: goto P_0c058b0c;
case 0x0c058b0eu: goto P_0c058b0e;
case 0x0c058b10u: goto P_0c058b10;
case 0x0c058b12u: goto P_0c058b12;
case 0x0c058b14u: goto P_0c058b14;
case 0x0c058b16u: goto P_0c058b16;
case 0x0c058b18u: goto P_0c058b18;
case 0x0c058b1au: goto P_0c058b1a;
case 0x0c058b1cu: goto P_0c058b1c;
case 0x0c058b1eu: goto P_0c058b1e;
case 0x0c058b20u: goto P_0c058b20;
case 0x0c058b22u: goto P_0c058b22;
case 0x0c058b24u: goto P_0c058b24;
case 0x0c058b26u: goto P_0c058b26;
case 0x0c058b28u: goto P_0c058b28;
case 0x0c058b2au: goto P_0c058b2a;
case 0x0c058b2cu: goto P_0c058b2c;
case 0x0c058b2eu: goto P_0c058b2e;
case 0x0c058b30u: goto P_0c058b30;
case 0x0c058b32u: goto P_0c058b32;
case 0x0c058b34u: goto P_0c058b34;
case 0x0c058b36u: goto P_0c058b36;
case 0x0c058b38u: goto P_0c058b38;
case 0x0c058b3au: goto P_0c058b3a;
case 0x0c058b3cu: goto P_0c058b3c;
case 0x0c058b3eu: goto P_0c058b3e;
case 0x0c058b40u: goto P_0c058b40;
case 0x0c058b42u: goto P_0c058b42;
case 0x0c058b44u: goto P_0c058b44;
case 0x0c058b46u: goto P_0c058b46;
case 0x0c058b48u: goto P_0c058b48;
case 0x0c058b4au: goto P_0c058b4a;
case 0x0c058b4cu: goto P_0c058b4c;
case 0x0c058b4eu: goto P_0c058b4e;
case 0x0c058b50u: goto P_0c058b50;
case 0x0c058b52u: goto P_0c058b52;
case 0x0c058b54u: goto P_0c058b54;
case 0x0c058b56u: goto P_0c058b56;
case 0x0c058b58u: goto P_0c058b58;
case 0x0c059aeau: goto P_0c059aea;
case 0x0c059aecu: goto P_0c059aec;
case 0x0c059aeeu: goto P_0c059aee;
case 0x0c059af0u: goto P_0c059af0;
case 0x0c059af2u: goto P_0c059af2;
case 0x0c059af4u: goto P_0c059af4;
case 0x0c059af6u: goto P_0c059af6;
case 0x0c059af8u: goto P_0c059af8;
case 0x0c059afau: goto P_0c059afa;
case 0x0c059afcu: goto P_0c059afc;
case 0x0c059afeu: goto P_0c059afe;
case 0x0c059b00u: goto P_0c059b00;
case 0x0c059b02u: goto P_0c059b02;
case 0x0c059b04u: goto P_0c059b04;
case 0x0c059b06u: goto P_0c059b06;
case 0x0c059b08u: goto P_0c059b08;
case 0x0c059b0au: goto P_0c059b0a;
case 0x0c059b0cu: goto P_0c059b0c;
case 0x0c059b40u: goto P_0c059b40;
case 0x0c059b42u: goto P_0c059b42;
case 0x0c059b44u: goto P_0c059b44;
case 0x0c059b46u: goto P_0c059b46;
case 0x0c059b48u: goto P_0c059b48;
case 0x0c059b4au: goto P_0c059b4a;
case 0x0c059b4cu: goto P_0c059b4c;
case 0x0c059b4eu: goto P_0c059b4e;
case 0x0c059b50u: goto P_0c059b50;
case 0x0c059b52u: goto P_0c059b52;
case 0x0c059b54u: goto P_0c059b54;
case 0x0c059b56u: goto P_0c059b56;
case 0x0c059b58u: goto P_0c059b58;
case 0x0c059b5au: goto P_0c059b5a;
case 0x0c059b5cu: goto P_0c059b5c;
case 0x0c059b5eu: goto P_0c059b5e;
case 0x0c059b60u: goto P_0c059b60;
case 0x0c059b62u: goto P_0c059b62;
case 0x0c059b64u: goto P_0c059b64;
case 0x0c059b66u: goto P_0c059b66;
case 0x0c059b68u: goto P_0c059b68;
case 0x0c059b6au: goto P_0c059b6a;
case 0x0c059b6cu: goto P_0c059b6c;
case 0x0c059b6eu: goto P_0c059b6e;
case 0x0c059b70u: goto P_0c059b70;
case 0x0c059b72u: goto P_0c059b72;
case 0x0c059b74u: goto P_0c059b74;
case 0x0c059b76u: goto P_0c059b76;
case 0x0c059b78u: goto P_0c059b78;
case 0x0c059b7au: goto P_0c059b7a;
case 0x0c059b7cu: goto P_0c059b7c;
case 0x0c059b7eu: goto P_0c059b7e;
case 0x0c059b80u: goto P_0c059b80;
case 0x0c059b82u: goto P_0c059b82;
case 0x0c059b84u: goto P_0c059b84;
case 0x0c059b86u: goto P_0c059b86;
case 0x0c059b88u: goto P_0c059b88;
case 0x0c059b8au: goto P_0c059b8a;
case 0x0c059b8cu: goto P_0c059b8c;
case 0x0c059b8eu: goto P_0c059b8e;
case 0x0c059b90u: goto P_0c059b90;
case 0x0c059b92u: goto P_0c059b92;
case 0x0c059b94u: goto P_0c059b94;
case 0x0c059b96u: goto P_0c059b96;
case 0x0c059b98u: goto P_0c059b98;
case 0x0c059b9au: goto P_0c059b9a;
case 0x0c059b9cu: goto P_0c059b9c;
case 0x0c059b9eu: goto P_0c059b9e;
case 0x0c059ba0u: goto P_0c059ba0;
case 0x0c059ba2u: goto P_0c059ba2;
case 0x0c059ba4u: goto P_0c059ba4;
case 0x0c059ba6u: goto P_0c059ba6;
case 0x0c059ba8u: goto P_0c059ba8;
case 0x0c059baau: goto P_0c059baa;
case 0x0c059bacu: goto P_0c059bac;
case 0x0c059baeu: goto P_0c059bae;
case 0x0c059bb0u: goto P_0c059bb0;
case 0x0c059bb2u: goto P_0c059bb2;
case 0x0c059bb4u: goto P_0c059bb4;
case 0x0c059bb6u: goto P_0c059bb6;
case 0x0c059bb8u: goto P_0c059bb8;
case 0x0c059bbau: goto P_0c059bba;
case 0x0c059bbcu: goto P_0c059bbc;
case 0x0c059bbeu: goto P_0c059bbe;
case 0x0c059bc0u: goto P_0c059bc0;
case 0x0c059bc2u: goto P_0c059bc2;
case 0x0c059bc4u: goto P_0c059bc4;
case 0x0c059bc6u: goto P_0c059bc6;
case 0x0c059bc8u: goto P_0c059bc8;
case 0x0c059bcau: goto P_0c059bca;
case 0x0c059bccu: goto P_0c059bcc;
case 0x0c059bceu: goto P_0c059bce;
case 0x0c059bd0u: goto P_0c059bd0;
case 0x0c059bd2u: goto P_0c059bd2;
case 0x0c059bd4u: goto P_0c059bd4;
case 0x0c059bd6u: goto P_0c059bd6;
case 0x0c059bd8u: goto P_0c059bd8;
case 0x0c059bdau: goto P_0c059bda;
case 0x0c059bdcu: goto P_0c059bdc;
case 0x0c059bdeu: goto P_0c059bde;
case 0x0c059be0u: goto P_0c059be0;
case 0x0c059be2u: goto P_0c059be2;
case 0x0c059be4u: goto P_0c059be4;
case 0x0c059be6u: goto P_0c059be6;
case 0x0c059be8u: goto P_0c059be8;
case 0x0c059beau: goto P_0c059bea;
case 0x0c059becu: goto P_0c059bec;
case 0x0c059beeu: goto P_0c059bee;
case 0x0c059bf0u: goto P_0c059bf0;
case 0x0c059bf2u: goto P_0c059bf2;
case 0x0c059bf4u: goto P_0c059bf4;
case 0x0c059bf6u: goto P_0c059bf6;
case 0x0c059bf8u: goto P_0c059bf8;
case 0x0c059bfau: goto P_0c059bfa;
case 0x0c059bfcu: goto P_0c059bfc;
case 0x0c059bfeu: goto P_0c059bfe;
case 0x0c059c00u: goto P_0c059c00;
case 0x0c059c02u: goto P_0c059c02;
case 0x0c059c04u: goto P_0c059c04;
case 0x0c059c06u: goto P_0c059c06;
case 0x0c059c08u: goto P_0c059c08;
case 0x0c059c0au: goto P_0c059c0a;
case 0x0c059c0cu: goto P_0c059c0c;
case 0x0c059c0eu: goto P_0c059c0e;
case 0x0c059c10u: goto P_0c059c10;
case 0x0c059c12u: goto P_0c059c12;
case 0x0c059c14u: goto P_0c059c14;
case 0x0c059c16u: goto P_0c059c16;
case 0x0c059c18u: goto P_0c059c18;
case 0x0c059c1au: goto P_0c059c1a;
case 0x0c059c1cu: goto P_0c059c1c;
case 0x0c059c1eu: goto P_0c059c1e;
case 0x0c059c88u: goto P_0c059c88;
case 0x0c059c8au: goto P_0c059c8a;
case 0x0c059c8cu: goto P_0c059c8c;
case 0x0c059c8eu: goto P_0c059c8e;
case 0x0c059c90u: goto P_0c059c90;
case 0x0c059c92u: goto P_0c059c92;
case 0x0c059c94u: goto P_0c059c94;
case 0x0c059c96u: goto P_0c059c96;
case 0x0c059c98u: goto P_0c059c98;
case 0x0c059c9au: goto P_0c059c9a;
case 0x0c059c9cu: goto P_0c059c9c;
case 0x0c059c9eu: goto P_0c059c9e;
case 0x0c059ca0u: goto P_0c059ca0;
case 0x0c059ca2u: goto P_0c059ca2;
case 0x0c059ca4u: goto P_0c059ca4;
case 0x0c059ca6u: goto P_0c059ca6;
case 0x0c059ca8u: goto P_0c059ca8;
case 0x0c059caau: goto P_0c059caa;
case 0x0c059cacu: goto P_0c059cac;
case 0x0c059caeu: goto P_0c059cae;
case 0x0c059cb0u: goto P_0c059cb0;
case 0x0c059cb2u: goto P_0c059cb2;
case 0x0c059cb4u: goto P_0c059cb4;
case 0x0c059cb6u: goto P_0c059cb6;
case 0x0c059cb8u: goto P_0c059cb8;
case 0x0c059cbau: goto P_0c059cba;
case 0x0c059cbcu: goto P_0c059cbc;
case 0x0c059cbeu: goto P_0c059cbe;
case 0x0c059cc0u: goto P_0c059cc0;
case 0x0c059cc2u: goto P_0c059cc2;
case 0x0c059cc4u: goto P_0c059cc4;
case 0x0c059cc6u: goto P_0c059cc6;
case 0x0c059cc8u: goto P_0c059cc8;
case 0x0c059ccau: goto P_0c059cca;
case 0x0c059cccu: goto P_0c059ccc;
case 0x0c059cceu: goto P_0c059cce;
case 0x0c059cd0u: goto P_0c059cd0;
case 0x0c059cd2u: goto P_0c059cd2;
case 0x0c059cd4u: goto P_0c059cd4;
case 0x0c059cd6u: goto P_0c059cd6;
case 0x0c059cd8u: goto P_0c059cd8;
case 0x0c059cdau: goto P_0c059cda;
case 0x0c059cdcu: goto P_0c059cdc;
case 0x0c059cdeu: goto P_0c059cde;
case 0x0c059ce0u: goto P_0c059ce0;
case 0x0c059ce2u: goto P_0c059ce2;
case 0x0c059ce4u: goto P_0c059ce4;
case 0x0c059ce6u: goto P_0c059ce6;
case 0x0c059ce8u: goto P_0c059ce8;
case 0x0c059ceau: goto P_0c059cea;
case 0x0c059cecu: goto P_0c059cec;
case 0x0c059ceeu: goto P_0c059cee;
case 0x0c059cf0u: goto P_0c059cf0;
case 0x0c059cf2u: goto P_0c059cf2;
case 0x0c059cf4u: goto P_0c059cf4;
case 0x0c059cf6u: goto P_0c059cf6;
case 0x0c059cf8u: goto P_0c059cf8;
case 0x0c059cfau: goto P_0c059cfa;
case 0x0c059cfcu: goto P_0c059cfc;
case 0x0c059cfeu: goto P_0c059cfe;
case 0x0c059d00u: goto P_0c059d00;
case 0x0c059d02u: goto P_0c059d02;
case 0x0c059d04u: goto P_0c059d04;
case 0x0c059d06u: goto P_0c059d06;
case 0x0c059d08u: goto P_0c059d08;
case 0x0c059d0au: goto P_0c059d0a;
case 0x0c059d0cu: goto P_0c059d0c;
case 0x0c059d0eu: goto P_0c059d0e;
case 0x0c059d10u: goto P_0c059d10;
case 0x0c059d12u: goto P_0c059d12;
case 0x0c059d14u: goto P_0c059d14;
case 0x0c059d16u: goto P_0c059d16;
case 0x0c059d18u: goto P_0c059d18;
case 0x0c059d1au: goto P_0c059d1a;
case 0x0c059d1cu: goto P_0c059d1c;
case 0x0c059d1eu: goto P_0c059d1e;
case 0x0c059d20u: goto P_0c059d20;
case 0x0c059d22u: goto P_0c059d22;
case 0x0c059d24u: goto P_0c059d24;
case 0x0c059d26u: goto P_0c059d26;
case 0x0c059d28u: goto P_0c059d28;
case 0x0c059d2au: goto P_0c059d2a;
case 0x0c059d2cu: goto P_0c059d2c;
case 0x0c059d2eu: goto P_0c059d2e;
case 0x0c059d30u: goto P_0c059d30;
case 0x0c059d32u: goto P_0c059d32;
case 0x0c059d34u: goto P_0c059d34;
case 0x0c059d36u: goto P_0c059d36;
case 0x0c059d38u: goto P_0c059d38;
case 0x0c059d3au: goto P_0c059d3a;
case 0x0c059d3cu: goto P_0c059d3c;
case 0x0c059d3eu: goto P_0c059d3e;
case 0x0c059d40u: goto P_0c059d40;
case 0x0c059d42u: goto P_0c059d42;
case 0x0c059d44u: goto P_0c059d44;
case 0x0c059d46u: goto P_0c059d46;
case 0x0c059d48u: goto P_0c059d48;
case 0x0c059d4au: goto P_0c059d4a;
case 0x0c059d4cu: goto P_0c059d4c;
case 0x0c059d4eu: goto P_0c059d4e;
case 0x0c059d50u: goto P_0c059d50;
case 0x0c059d52u: goto P_0c059d52;
case 0x0c059d54u: goto P_0c059d54;
case 0x0c059d56u: goto P_0c059d56;
case 0x0c059d58u: goto P_0c059d58;
case 0x0c059d5au: goto P_0c059d5a;
case 0x0c059d5cu: goto P_0c059d5c;
case 0x0c059d5eu: goto P_0c059d5e;
case 0x0c059d60u: goto P_0c059d60;
case 0x0c059d62u: goto P_0c059d62;
case 0x0c059d64u: goto P_0c059d64;
case 0x0c059d66u: goto P_0c059d66;
case 0x0c059d68u: goto P_0c059d68;
case 0x0c059d6au: goto P_0c059d6a;
case 0x0c059d6cu: goto P_0c059d6c;
case 0x0c059d6eu: goto P_0c059d6e;
case 0x0c059d70u: goto P_0c059d70;
case 0x0c060fd6u: goto P_0c060fd6;
case 0x0c060fd8u: goto P_0c060fd8;
case 0x0c060fdau: goto P_0c060fda;
case 0x0c060fdcu: goto P_0c060fdc;
case 0x0c060fdeu: goto P_0c060fde;
case 0x0c060fe0u: goto P_0c060fe0;
case 0x0c060fe2u: goto P_0c060fe2;
case 0x0c060fe4u: goto P_0c060fe4;
case 0x0c060fe6u: goto P_0c060fe6;
case 0x0c060fe8u: goto P_0c060fe8;
case 0x0c060feau: goto P_0c060fea;
case 0x0c060fecu: goto P_0c060fec;
case 0x0c060feeu: goto P_0c060fee;
case 0x0c060ff0u: goto P_0c060ff0;
case 0x0c060ff2u: goto P_0c060ff2;
case 0x0c060ff4u: goto P_0c060ff4;
case 0x0c060ff6u: goto P_0c060ff6;
case 0x0c060ff8u: goto P_0c060ff8;
case 0x0c060ffau: goto P_0c060ffa;
case 0x0c060ffcu: goto P_0c060ffc;
case 0x0c060ffeu: goto P_0c060ffe;
case 0x0c061000u: goto P_0c061000;
case 0x0c061002u: goto P_0c061002;
case 0x0c061004u: goto P_0c061004;
case 0x0c061006u: goto P_0c061006;
case 0x0c061008u: goto P_0c061008;
case 0x0c06100au: goto P_0c06100a;
case 0x0c06100cu: goto P_0c06100c;
case 0x0c061054u: goto P_0c061054;
case 0x0c061056u: goto P_0c061056;
case 0x0c061058u: goto P_0c061058;
case 0x0c06105au: goto P_0c06105a;
case 0x0c06105cu: goto P_0c06105c;
case 0x0c06105eu: goto P_0c06105e;
case 0x0c061060u: goto P_0c061060;
case 0x0c061062u: goto P_0c061062;
case 0x0c061064u: goto P_0c061064;
case 0x0c061066u: goto P_0c061066;
case 0x0c061068u: goto P_0c061068;
case 0x0c06106au: goto P_0c06106a;
case 0x0c06106cu: goto P_0c06106c;
case 0x0c06106eu: goto P_0c06106e;
case 0x0c061070u: goto P_0c061070;
case 0x0c061072u: goto P_0c061072;
case 0x0c061074u: goto P_0c061074;
case 0x0c061076u: goto P_0c061076;
case 0x0c061078u: goto P_0c061078;
case 0x0c06107au: goto P_0c06107a;
case 0x0c06107cu: goto P_0c06107c;
case 0x0c06107eu: goto P_0c06107e;
case 0x0c061080u: goto P_0c061080;
case 0x0c061082u: goto P_0c061082;
case 0x0c061084u: goto P_0c061084;
case 0x0c061086u: goto P_0c061086;
case 0x0c061088u: goto P_0c061088;
case 0x0c06108au: goto P_0c06108a;
case 0x0c06108cu: goto P_0c06108c;
case 0x0c06108eu: goto P_0c06108e;
case 0x0c061090u: goto P_0c061090;
case 0x0c061092u: goto P_0c061092;
case 0x0c061094u: goto P_0c061094;
case 0x0c061096u: goto P_0c061096;
case 0x0c061098u: goto P_0c061098;
case 0x0c06109au: goto P_0c06109a;
case 0x0c06109cu: goto P_0c06109c;
case 0x0c06109eu: goto P_0c06109e;
case 0x0c0610a0u: goto P_0c0610a0;
case 0x0c0610a2u: goto P_0c0610a2;
case 0x0c0610a4u: goto P_0c0610a4;
case 0x0c0610a6u: goto P_0c0610a6;
case 0x0c0610a8u: goto P_0c0610a8;
case 0x0c0610aau: goto P_0c0610aa;
case 0x0c0610acu: goto P_0c0610ac;
case 0x0c0610aeu: goto P_0c0610ae;
case 0x0c0610b0u: goto P_0c0610b0;
case 0x0c0610b2u: goto P_0c0610b2;
case 0x0c0610b4u: goto P_0c0610b4;
case 0x0c0610b6u: goto P_0c0610b6;
case 0x0c0610b8u: goto P_0c0610b8;
case 0x0c0610bau: goto P_0c0610ba;
case 0x0c0610bcu: goto P_0c0610bc;
case 0x0c0610beu: goto P_0c0610be;
case 0x0c0610c0u: goto P_0c0610c0;
case 0x0c0610c2u: goto P_0c0610c2;
case 0x0c0610c4u: goto P_0c0610c4;
case 0x0c0610c6u: goto P_0c0610c6;
case 0x0c0610c8u: goto P_0c0610c8;
case 0x0c0610cau: goto P_0c0610ca;
case 0x0c0610ccu: goto P_0c0610cc;
case 0x0c0610ceu: goto P_0c0610ce;
case 0x0c0610d0u: goto P_0c0610d0;
case 0x0c0610d2u: goto P_0c0610d2;
case 0x0c0610d4u: goto P_0c0610d4;
case 0x0c0610d6u: goto P_0c0610d6;
case 0x0c0610d8u: goto P_0c0610d8;
case 0x0c0610dau: goto P_0c0610da;
case 0x0c0610dcu: goto P_0c0610dc;
case 0x0c0610deu: goto P_0c0610de;
case 0x0c0610e0u: goto P_0c0610e0;
case 0x0c0610e2u: goto P_0c0610e2;
case 0x0c0610e4u: goto P_0c0610e4;
case 0x0c0610e6u: goto P_0c0610e6;
case 0x0c0610e8u: goto P_0c0610e8;
case 0x0c0610eau: goto P_0c0610ea;
case 0x0c0610ecu: goto P_0c0610ec;
case 0x0c0610eeu: goto P_0c0610ee;
case 0x0c0610f0u: goto P_0c0610f0;
case 0x0c0610f2u: goto P_0c0610f2;
case 0x0c0610f4u: goto P_0c0610f4;
case 0x0c0610f6u: goto P_0c0610f6;
case 0x0c0610f8u: goto P_0c0610f8;
case 0x0c0610fau: goto P_0c0610fa;
case 0x0c0610fcu: goto P_0c0610fc;
case 0x0c0610feu: goto P_0c0610fe;
case 0x0c061100u: goto P_0c061100;
case 0x0c061102u: goto P_0c061102;
case 0x0c061104u: goto P_0c061104;
case 0x0c061106u: goto P_0c061106;
case 0x0c061108u: goto P_0c061108;
case 0x0c06110au: goto P_0c06110a;
case 0x0c06110cu: goto P_0c06110c;
case 0x0c06110eu: goto P_0c06110e;
case 0x0c061110u: goto P_0c061110;
case 0x0c061112u: goto P_0c061112;
case 0x0c061114u: goto P_0c061114;
case 0x0c061116u: goto P_0c061116;
case 0x0c061118u: goto P_0c061118;
case 0x0c06111au: goto P_0c06111a;
case 0x0c06111cu: goto P_0c06111c;
case 0x0c06111eu: goto P_0c06111e;
case 0x0c061120u: goto P_0c061120;
case 0x0c061122u: goto P_0c061122;
case 0x0c061124u: goto P_0c061124;
case 0x0c061126u: goto P_0c061126;
case 0x0c061128u: goto P_0c061128;
case 0x0c06112au: goto P_0c06112a;
case 0x0c06112cu: goto P_0c06112c;
case 0x0c06112eu: goto P_0c06112e;
case 0x0c061130u: goto P_0c061130;
case 0x0c061132u: goto P_0c061132;
case 0x0c061134u: goto P_0c061134;
case 0x0c061136u: goto P_0c061136;
case 0x0c061138u: goto P_0c061138;
case 0x0c06113au: goto P_0c06113a;
case 0x0c06113cu: goto P_0c06113c;
case 0x0c06113eu: goto P_0c06113e;
case 0x0c061140u: goto P_0c061140;
case 0x0c063446u: goto P_0c063446;
case 0x0c063448u: goto P_0c063448;
case 0x0c06344au: goto P_0c06344a;
case 0x0c06344cu: goto P_0c06344c;
case 0x0c06344eu: goto P_0c06344e;
case 0x0c063450u: goto P_0c063450;
case 0x0c063452u: goto P_0c063452;
case 0x0c063454u: goto P_0c063454;
case 0x0c063456u: goto P_0c063456;
case 0x0c063458u: goto P_0c063458;
case 0x0c06345au: goto P_0c06345a;
case 0x0c06345cu: goto P_0c06345c;
case 0x0c06345eu: goto P_0c06345e;
case 0x0c063460u: goto P_0c063460;
case 0x0c063462u: goto P_0c063462;
case 0x0c063464u: goto P_0c063464;
case 0x0c063466u: goto P_0c063466;
case 0x0c063468u: goto P_0c063468;
case 0x0c06346au: goto P_0c06346a;
case 0x0c06346cu: goto P_0c06346c;
case 0x0c06346eu: goto P_0c06346e;
case 0x0c063470u: goto P_0c063470;
case 0x0c063472u: goto P_0c063472;
case 0x0c063474u: goto P_0c063474;
case 0x0c063476u: goto P_0c063476;
case 0x0c063478u: goto P_0c063478;
case 0x0c06347au: goto P_0c06347a;
case 0x0c06347cu: goto P_0c06347c;
case 0x0c06347eu: goto P_0c06347e;
case 0x0c063480u: goto P_0c063480;
case 0x0c063482u: goto P_0c063482;
case 0x0c063484u: goto P_0c063484;
case 0x0c063486u: goto P_0c063486;
case 0x0c063488u: goto P_0c063488;
case 0x0c06348au: goto P_0c06348a;
case 0x0c06348cu: goto P_0c06348c;
case 0x0c06348eu: goto P_0c06348e;
case 0x0c063490u: goto P_0c063490;
case 0x0c063492u: goto P_0c063492;
case 0x0c063494u: goto P_0c063494;
case 0x0c063496u: goto P_0c063496;
case 0x0c063498u: goto P_0c063498;
case 0x0c06349au: goto P_0c06349a;
case 0x0c06349cu: goto P_0c06349c;
case 0x0c06349eu: goto P_0c06349e;
case 0x0c0634a0u: goto P_0c0634a0;
case 0x0c0634a2u: goto P_0c0634a2;
case 0x0c0634a4u: goto P_0c0634a4;
case 0x0c0634a6u: goto P_0c0634a6;
case 0x0c0634a8u: goto P_0c0634a8;
case 0x0c0634aau: goto P_0c0634aa;
case 0x0c0634acu: goto P_0c0634ac;
case 0x0c0634aeu: goto P_0c0634ae;
case 0x0c0634b0u: goto P_0c0634b0;
case 0x0c0634b2u: goto P_0c0634b2;
case 0x0c0634b4u: goto P_0c0634b4;
case 0x0c0634b6u: goto P_0c0634b6;
case 0x0c0634b8u: goto P_0c0634b8;
case 0x0c0634bau: goto P_0c0634ba;
case 0x0c0634bcu: goto P_0c0634bc;
case 0x0c0634beu: goto P_0c0634be;
case 0x0c0634c0u: goto P_0c0634c0;
case 0x0c0634c2u: goto P_0c0634c2;
case 0x0c0634c4u: goto P_0c0634c4;
case 0x0c0634c6u: goto P_0c0634c6;
case 0x0c0634c8u: goto P_0c0634c8;
case 0x0c0634cau: goto P_0c0634ca;
case 0x0c0634ccu: goto P_0c0634cc;
case 0x0c0634ceu: goto P_0c0634ce;
case 0x0c0634d0u: goto P_0c0634d0;
case 0x0c0634d2u: goto P_0c0634d2;
case 0x0c0634d4u: goto P_0c0634d4;
case 0x0c0634d6u: goto P_0c0634d6;
case 0x0c0634d8u: goto P_0c0634d8;
case 0x0c0634dau: goto P_0c0634da;
case 0x0c0634dcu: goto P_0c0634dc;
case 0x0c0634deu: goto P_0c0634de;
case 0x0c0634e0u: goto P_0c0634e0;
case 0x0c0634e2u: goto P_0c0634e2;
case 0x0c0634e4u: goto P_0c0634e4;
case 0x0c0634e6u: goto P_0c0634e6;
case 0x0c0634e8u: goto P_0c0634e8;
case 0x0c0634eau: goto P_0c0634ea;
case 0x0c0634ecu: goto P_0c0634ec;
case 0x0c06351cu: goto P_0c06351c;
case 0x0c06351eu: goto P_0c06351e;
case 0x0c063520u: goto P_0c063520;
case 0x0c063522u: goto P_0c063522;
case 0x0c063524u: goto P_0c063524;
case 0x0c063526u: goto P_0c063526;
case 0x0c063528u: goto P_0c063528;
case 0x0c06352au: goto P_0c06352a;
case 0x0c06352cu: goto P_0c06352c;
case 0x0c06352eu: goto P_0c06352e;
case 0x0c063530u: goto P_0c063530;
case 0x0c063532u: goto P_0c063532;
case 0x0c063534u: goto P_0c063534;
case 0x0c063536u: goto P_0c063536;
case 0x0c063538u: goto P_0c063538;
case 0x0c06353au: goto P_0c06353a;
case 0x0c06353cu: goto P_0c06353c;
case 0x0c06353eu: goto P_0c06353e;
case 0x0c063540u: goto P_0c063540;
case 0x0c063542u: goto P_0c063542;
case 0x0c063544u: goto P_0c063544;
case 0x0c063546u: goto P_0c063546;
case 0x0c063548u: goto P_0c063548;
case 0x0c06354au: goto P_0c06354a;
case 0x0c06354cu: goto P_0c06354c;
case 0x0c06354eu: goto P_0c06354e;
case 0x0c063550u: goto P_0c063550;
case 0x0c063552u: goto P_0c063552;
case 0x0c063554u: goto P_0c063554;
case 0x0c063556u: goto P_0c063556;
case 0x0c063558u: goto P_0c063558;
case 0x0c06355au: goto P_0c06355a;
case 0x0c06355cu: goto P_0c06355c;
case 0x0c06355eu: goto P_0c06355e;
case 0x0c063560u: goto P_0c063560;
case 0x0c063562u: goto P_0c063562;
case 0x0c063564u: goto P_0c063564;
case 0x0c063566u: goto P_0c063566;
case 0x0c063568u: goto P_0c063568;
case 0x0c06356au: goto P_0c06356a;
case 0x0c06356cu: goto P_0c06356c;
case 0x0c06356eu: goto P_0c06356e;
case 0x0c063570u: goto P_0c063570;
case 0x0c063572u: goto P_0c063572;
case 0x0c063574u: goto P_0c063574;
case 0x0c063576u: goto P_0c063576;
case 0x0c063578u: goto P_0c063578;
case 0x0c06357au: goto P_0c06357a;
case 0x0c06357cu: goto P_0c06357c;
case 0x0c06357eu: goto P_0c06357e;
case 0x0c063580u: goto P_0c063580;
case 0x0c063582u: goto P_0c063582;
case 0x0c063584u: goto P_0c063584;
case 0x0c063586u: goto P_0c063586;
case 0x0c063588u: goto P_0c063588;
case 0x0c06358au: goto P_0c06358a;
case 0x0c06358cu: goto P_0c06358c;
case 0x0c06358eu: goto P_0c06358e;
case 0x0c063590u: goto P_0c063590;
case 0x0c063592u: goto P_0c063592;
case 0x0c063594u: goto P_0c063594;
case 0x0c063596u: goto P_0c063596;
case 0x0c063598u: goto P_0c063598;
case 0x0c06359au: goto P_0c06359a;
case 0x0c06359cu: goto P_0c06359c;
case 0x0c06359eu: goto P_0c06359e;
case 0x0c0635a0u: goto P_0c0635a0;
case 0x0c0635a2u: goto P_0c0635a2;
case 0x0c0635a4u: goto P_0c0635a4;
case 0x0c0635a6u: goto P_0c0635a6;
case 0x0c0635a8u: goto P_0c0635a8;
case 0x0c0635aau: goto P_0c0635aa;
case 0x0c0635acu: goto P_0c0635ac;
case 0x0c0635aeu: goto P_0c0635ae;
case 0x0c0635b0u: goto P_0c0635b0;
case 0x0c0635b2u: goto P_0c0635b2;
case 0x0c0635b4u: goto P_0c0635b4;
case 0x0c0635b6u: goto P_0c0635b6;
case 0x0c0635b8u: goto P_0c0635b8;
case 0x0c0635bau: goto P_0c0635ba;
case 0x0c0635bcu: goto P_0c0635bc;
case 0x0c0635beu: goto P_0c0635be;
case 0x0c0635c0u: goto P_0c0635c0;
case 0x0c0635c2u: goto P_0c0635c2;
case 0x0c0635c4u: goto P_0c0635c4;
case 0x0c0635c6u: goto P_0c0635c6;
case 0x0c0635c8u: goto P_0c0635c8;
case 0x0c0635cau: goto P_0c0635ca;
case 0x0c0635ccu: goto P_0c0635cc;
case 0x0c0635ceu: goto P_0c0635ce;
case 0x0c0635d0u: goto P_0c0635d0;
case 0x0c0635d2u: goto P_0c0635d2;
case 0x0c0635d4u: goto P_0c0635d4;
case 0x0c0635d6u: goto P_0c0635d6;
case 0x0c0635d8u: goto P_0c0635d8;
case 0x0c0635dau: goto P_0c0635da;
case 0x0c0635dcu: goto P_0c0635dc;
case 0x0c0635deu: goto P_0c0635de;
case 0x0c0635e0u: goto P_0c0635e0;
case 0x0c0635e2u: goto P_0c0635e2;
case 0x0c0635e4u: goto P_0c0635e4;
case 0x0c0635e6u: goto P_0c0635e6;
case 0x0c0635e8u: goto P_0c0635e8;
case 0x0c0635eau: goto P_0c0635ea;
case 0x0c0635ecu: goto P_0c0635ec;
case 0x0c0635eeu: goto P_0c0635ee;
case 0x0c0635f0u: goto P_0c0635f0;
case 0x0c0635f2u: goto P_0c0635f2;
case 0x0c0635f4u: goto P_0c0635f4;
case 0x0c0635f6u: goto P_0c0635f6;
case 0x0c0635f8u: goto P_0c0635f8;
case 0x0c0635fau: goto P_0c0635fa;
case 0x0c0635fcu: goto P_0c0635fc;
case 0x0c0635feu: goto P_0c0635fe;
case 0x0c063600u: goto P_0c063600;
case 0x0c063602u: goto P_0c063602;
case 0x0c063604u: goto P_0c063604;
case 0x0c063606u: goto P_0c063606;
case 0x0c063608u: goto P_0c063608;
case 0x0c06360au: goto P_0c06360a;
case 0x0c06360cu: goto P_0c06360c;
case 0x0c06360eu: goto P_0c06360e;
case 0x0c063610u: goto P_0c063610;
case 0x0c063612u: goto P_0c063612;
case 0x0c063614u: goto P_0c063614;
case 0x0c063680u: goto P_0c063680;
case 0x0c063682u: goto P_0c063682;
case 0x0c063684u: goto P_0c063684;
case 0x0c063686u: goto P_0c063686;
case 0x0c063688u: goto P_0c063688;
case 0x0c06368au: goto P_0c06368a;
case 0x0c06368cu: goto P_0c06368c;
case 0x0c06368eu: goto P_0c06368e;
case 0x0c063690u: goto P_0c063690;
case 0x0c063692u: goto P_0c063692;
case 0x0c063694u: goto P_0c063694;
case 0x0c063696u: goto P_0c063696;
case 0x0c063698u: goto P_0c063698;
case 0x0c06369au: goto P_0c06369a;
case 0x0c06369cu: goto P_0c06369c;
case 0x0c06369eu: goto P_0c06369e;
case 0x0c07a856u: goto P_0c07a856;
case 0x0c07a858u: goto P_0c07a858;
case 0x0c07a85au: goto P_0c07a85a;
case 0x0c07a85cu: goto P_0c07a85c;
case 0x0c07a85eu: goto P_0c07a85e;
case 0x0c07a860u: goto P_0c07a860;
case 0x0c07a862u: goto P_0c07a862;
case 0x0c07a864u: goto P_0c07a864;
case 0x0c07a866u: goto P_0c07a866;
case 0x0c07a868u: goto P_0c07a868;
case 0x0c07a86au: goto P_0c07a86a;
case 0x0c07a86cu: goto P_0c07a86c;
case 0x0c07a86eu: goto P_0c07a86e;
case 0x0c07a870u: goto P_0c07a870;
case 0x0c07a872u: goto P_0c07a872;
case 0x0c07a874u: goto P_0c07a874;
case 0x0c07a876u: goto P_0c07a876;
case 0x0c07a878u: goto P_0c07a878;
case 0x0c07a87au: goto P_0c07a87a;
case 0x0c07a87cu: goto P_0c07a87c;
case 0x0c07a87eu: goto P_0c07a87e;
case 0x0c07a880u: goto P_0c07a880;
case 0x0c07a882u: goto P_0c07a882;
case 0x0c07a884u: goto P_0c07a884;
case 0x0c07a886u: goto P_0c07a886;
case 0x0c07a888u: goto P_0c07a888;
case 0x0c07a88au: goto P_0c07a88a;
case 0x0c07a88cu: goto P_0c07a88c;
case 0x0c07a88eu: goto P_0c07a88e;
case 0x0c07a890u: goto P_0c07a890;
case 0x0c07a892u: goto P_0c07a892;
case 0x0c07a894u: goto P_0c07a894;
case 0x0c07a896u: goto P_0c07a896;
case 0x0c07a898u: goto P_0c07a898;
case 0x0c07a89au: goto P_0c07a89a;
case 0x0c07a89cu: goto P_0c07a89c;
case 0x0c07a89eu: goto P_0c07a89e;
case 0x0c07a8a0u: goto P_0c07a8a0;
case 0x0c07a8a2u: goto P_0c07a8a2;
case 0x0c07a8a4u: goto P_0c07a8a4;
case 0x0c07a8a6u: goto P_0c07a8a6;
case 0x0c07a8a8u: goto P_0c07a8a8;
case 0x0c07a8aau: goto P_0c07a8aa;
case 0x0c07a8acu: goto P_0c07a8ac;
case 0x0c07a8aeu: goto P_0c07a8ae;
case 0x0c07a8b0u: goto P_0c07a8b0;
case 0x0c07a8b2u: goto P_0c07a8b2;
case 0x0c07a8b4u: goto P_0c07a8b4;
case 0x0c07a8b6u: goto P_0c07a8b6;
case 0x0c07a8b8u: goto P_0c07a8b8;
case 0x0c07a8bau: goto P_0c07a8ba;
case 0x0c07a8bcu: goto P_0c07a8bc;
case 0x0c07a8beu: goto P_0c07a8be;
case 0x0c07a8c0u: goto P_0c07a8c0;
case 0x0c07a8c2u: goto P_0c07a8c2;
case 0x0c07a8c4u: goto P_0c07a8c4;
case 0x0c07a8c6u: goto P_0c07a8c6;
case 0x0c07a8c8u: goto P_0c07a8c8;
case 0x0c07a8cau: goto P_0c07a8ca;
case 0x0c07a8ccu: goto P_0c07a8cc;
case 0x0c07a8ceu: goto P_0c07a8ce;
case 0x0c07a8d0u: goto P_0c07a8d0;
case 0x0c07a8d2u: goto P_0c07a8d2;
case 0x0c07a8d4u: goto P_0c07a8d4;
case 0x0c07a8d6u: goto P_0c07a8d6;
case 0x0c07a8d8u: goto P_0c07a8d8;
case 0x0c07a8dau: goto P_0c07a8da;
case 0x0c07a8dcu: goto P_0c07a8dc;
case 0x0c07a8deu: goto P_0c07a8de;
case 0x0c07a8e0u: goto P_0c07a8e0;
case 0x0c07a8e2u: goto P_0c07a8e2;
case 0x0c07a8e4u: goto P_0c07a8e4;
case 0x0c07a8e6u: goto P_0c07a8e6;
case 0x0c07a8e8u: goto P_0c07a8e8;
case 0x0c07a8eau: goto P_0c07a8ea;
case 0x0c07a8ecu: goto P_0c07a8ec;
case 0x0c07a8eeu: goto P_0c07a8ee;
case 0x0c07a8f0u: goto P_0c07a8f0;
case 0x0c07a8f2u: goto P_0c07a8f2;
case 0x0c07a8f4u: goto P_0c07a8f4;
case 0x0c07a8f6u: goto P_0c07a8f6;
case 0x0c07a8f8u: goto P_0c07a8f8;
case 0x0c07a8fau: goto P_0c07a8fa;
case 0x0c07a8fcu: goto P_0c07a8fc;
case 0x0c07a8feu: goto P_0c07a8fe;
case 0x0c07a900u: goto P_0c07a900;
case 0x0c07a902u: goto P_0c07a902;
case 0x0c07a904u: goto P_0c07a904;
case 0x0c07a906u: goto P_0c07a906;
case 0x0c07a908u: goto P_0c07a908;
case 0x0c07a90au: goto P_0c07a90a;
case 0x0c07a90cu: goto P_0c07a90c;
case 0x0c07a90eu: goto P_0c07a90e;
case 0x0c07a910u: goto P_0c07a910;
case 0x0c07a912u: goto P_0c07a912;
case 0x0c07a914u: goto P_0c07a914;
case 0x0c07a916u: goto P_0c07a916;
case 0x0c07a918u: goto P_0c07a918;
case 0x0c07a91au: goto P_0c07a91a;
case 0x0c07a91cu: goto P_0c07a91c;
case 0x0c07a91eu: goto P_0c07a91e;
case 0x0c07a920u: goto P_0c07a920;
case 0x0c07a922u: goto P_0c07a922;
case 0x0c07a924u: goto P_0c07a924;
case 0x0c07a926u: goto P_0c07a926;
case 0x0c07a928u: goto P_0c07a928;
case 0x0c07a92au: goto P_0c07a92a;
case 0x0c07a92cu: goto P_0c07a92c;
case 0x0c07a92eu: goto P_0c07a92e;
case 0x0c07a930u: goto P_0c07a930;
case 0x0c07a932u: goto P_0c07a932;
case 0x0c07a934u: goto P_0c07a934;
case 0x0c07a936u: goto P_0c07a936;
case 0x0c07a938u: goto P_0c07a938;
case 0x0c07a93au: goto P_0c07a93a;
case 0x0c07a93cu: goto P_0c07a93c;
case 0x0c07a93eu: goto P_0c07a93e;
case 0x0c07a940u: goto P_0c07a940;
case 0x0c07a942u: goto P_0c07a942;
case 0x0c07a944u: goto P_0c07a944;
case 0x0c07a946u: goto P_0c07a946;
case 0x0c07a948u: goto P_0c07a948;
case 0x0c07a94au: goto P_0c07a94a;
case 0x0c07a94cu: goto P_0c07a94c;
case 0x0c07a94eu: goto P_0c07a94e;
case 0x0c07a950u: goto P_0c07a950;
case 0x0c07a952u: goto P_0c07a952;
case 0x0c07a954u: goto P_0c07a954;
case 0x0c07a956u: goto P_0c07a956;
case 0x0c07a958u: goto P_0c07a958;
case 0x0c07a95au: goto P_0c07a95a;
case 0x0c07a95cu: goto P_0c07a95c;
case 0x0c07a95eu: goto P_0c07a95e;
case 0x0c07a960u: goto P_0c07a960;
case 0x0c07a962u: goto P_0c07a962;
case 0x0c07a964u: goto P_0c07a964;
case 0x0c07a966u: goto P_0c07a966;
case 0x0c07a968u: goto P_0c07a968;
case 0x0c07a96au: goto P_0c07a96a;
case 0x0c07a96cu: goto P_0c07a96c;
case 0x0c07a96eu: goto P_0c07a96e;
case 0x0c07a970u: goto P_0c07a970;
case 0x0c07a972u: goto P_0c07a972;
case 0x0c07a974u: goto P_0c07a974;
case 0x0c07a976u: goto P_0c07a976;
case 0x0c07a978u: goto P_0c07a978;
case 0x0c07a97au: goto P_0c07a97a;
case 0x0c07a97cu: goto P_0c07a97c;
case 0x0c07a97eu: goto P_0c07a97e;
case 0x0c07a980u: goto P_0c07a980;
case 0x0c07a982u: goto P_0c07a982;
case 0x0c07a984u: goto P_0c07a984;
case 0x0c07a986u: goto P_0c07a986;
case 0x0c07a988u: goto P_0c07a988;
case 0x0c07a98au: goto P_0c07a98a;
case 0x0c07a98cu: goto P_0c07a98c;
case 0x0c07a98eu: goto P_0c07a98e;
case 0x0c07a990u: goto P_0c07a990;
case 0x0c07a992u: goto P_0c07a992;
case 0x0c07a994u: goto P_0c07a994;
case 0x0c07a996u: goto P_0c07a996;
case 0x0c07a998u: goto P_0c07a998;
case 0x0c07a99au: goto P_0c07a99a;
case 0x0c07a99cu: goto P_0c07a99c;
case 0x0c07a99eu: goto P_0c07a99e;
case 0x0c07a9a0u: goto P_0c07a9a0;
case 0x0c07a9a2u: goto P_0c07a9a2;
case 0x0c07a9a4u: goto P_0c07a9a4;
case 0x0c07a9a6u: goto P_0c07a9a6;
case 0x0c07a9a8u: goto P_0c07a9a8;
case 0x0c07a9aau: goto P_0c07a9aa;
case 0x0c07a9acu: goto P_0c07a9ac;
case 0x0c07a9aeu: goto P_0c07a9ae;
case 0x0c07a9b0u: goto P_0c07a9b0;
case 0x0c07a9b2u: goto P_0c07a9b2;
case 0x0c07a9f8u: goto P_0c07a9f8;
case 0x0c07a9fau: goto P_0c07a9fa;
case 0x0c07a9fcu: goto P_0c07a9fc;
case 0x0c07a9feu: goto P_0c07a9fe;
case 0x0c07aa00u: goto P_0c07aa00;
case 0x0c07aa02u: goto P_0c07aa02;
case 0x0c07aa04u: goto P_0c07aa04;
case 0x0c07aa06u: goto P_0c07aa06;
case 0x0c07aa08u: goto P_0c07aa08;
case 0x0c07aa0au: goto P_0c07aa0a;
case 0x0c07aa0cu: goto P_0c07aa0c;
case 0x0c07aa0eu: goto P_0c07aa0e;
case 0x0c07aa10u: goto P_0c07aa10;
case 0x0c07aa12u: goto P_0c07aa12;
case 0x0c07aa14u: goto P_0c07aa14;
case 0x0c07aa16u: goto P_0c07aa16;
case 0x0c07aa18u: goto P_0c07aa18;
case 0x0c07aa1au: goto P_0c07aa1a;
case 0x0c07aa1cu: goto P_0c07aa1c;
case 0x0c07aa1eu: goto P_0c07aa1e;
case 0x0c07aa20u: goto P_0c07aa20;
case 0x0c07aa22u: goto P_0c07aa22;
case 0x0c07aa24u: goto P_0c07aa24;
case 0x0c07aa26u: goto P_0c07aa26;
case 0x0c07aa28u: goto P_0c07aa28;
case 0x0c07aa2au: goto P_0c07aa2a;
case 0x0c07aa2cu: goto P_0c07aa2c;
case 0x0c07aa2eu: goto P_0c07aa2e;
case 0x0c099d74u: goto P_0c099d74;
case 0x0c099d76u: goto P_0c099d76;
case 0x0c099d78u: goto P_0c099d78;
case 0x0c099d7au: goto P_0c099d7a;
case 0x0c099d7cu: goto P_0c099d7c;
case 0x0c099d7eu: goto P_0c099d7e;
case 0x0c099d80u: goto P_0c099d80;
case 0x0c099d82u: goto P_0c099d82;
case 0x0c099d84u: goto P_0c099d84;
case 0x0c099d86u: goto P_0c099d86;
case 0x0c099d88u: goto P_0c099d88;
case 0x0c099d8au: goto P_0c099d8a;
case 0x0c099d8cu: goto P_0c099d8c;
case 0x0c099d8eu: goto P_0c099d8e;
case 0x0c099d90u: goto P_0c099d90;
case 0x0c099d92u: goto P_0c099d92;
case 0x0c099d94u: goto P_0c099d94;
case 0x0c099d96u: goto P_0c099d96;
case 0x0c099d98u: goto P_0c099d98;
case 0x0c099d9au: goto P_0c099d9a;
case 0x0c099d9cu: goto P_0c099d9c;
case 0x0c099d9eu: goto P_0c099d9e;
case 0x0c099de0u: goto P_0c099de0;
case 0x0c099de2u: goto P_0c099de2;
case 0x0c099de4u: goto P_0c099de4;
case 0x0c099de6u: goto P_0c099de6;
case 0x0c099de8u: goto P_0c099de8;
case 0x0c099deau: goto P_0c099dea;
case 0x0c099decu: goto P_0c099dec;
case 0x0c099deeu: goto P_0c099dee;
case 0x0c099df0u: goto P_0c099df0;
case 0x0c099df2u: goto P_0c099df2;
case 0x0c099df4u: goto P_0c099df4;
case 0x0c099df6u: goto P_0c099df6;
case 0x0c099df8u: goto P_0c099df8;
case 0x0c099dfau: goto P_0c099dfa;
case 0x0c099dfcu: goto P_0c099dfc;
case 0x0c099dfeu: goto P_0c099dfe;
case 0x0c099e00u: goto P_0c099e00;
case 0x0c099e02u: goto P_0c099e02;
case 0x0c099e04u: goto P_0c099e04;
case 0x0c099e06u: goto P_0c099e06;
case 0x0c099e08u: goto P_0c099e08;
case 0x0c099e0au: goto P_0c099e0a;
case 0x0c099e0cu: goto P_0c099e0c;
case 0x0c099e0eu: goto P_0c099e0e;
case 0x0c099e10u: goto P_0c099e10;
case 0x0c099e12u: goto P_0c099e12;
case 0x0c099e14u: goto P_0c099e14;
case 0x0c099e16u: goto P_0c099e16;
case 0x0c099e18u: goto P_0c099e18;
case 0x0c099e1au: goto P_0c099e1a;
case 0x0c099e1cu: goto P_0c099e1c;
case 0x0c099e1eu: goto P_0c099e1e;
case 0x0c099e20u: goto P_0c099e20;
case 0x0c099e22u: goto P_0c099e22;
case 0x0c099e24u: goto P_0c099e24;
case 0x0c099e26u: goto P_0c099e26;
case 0x0c099e28u: goto P_0c099e28;
case 0x0c099e2au: goto P_0c099e2a;
case 0x0c099e2cu: goto P_0c099e2c;
case 0x0c099e2eu: goto P_0c099e2e;
case 0x0c099e30u: goto P_0c099e30;
case 0x0c099e32u: goto P_0c099e32;
case 0x0c099e34u: goto P_0c099e34;
case 0x0c099e36u: goto P_0c099e36;
case 0x0c099e38u: goto P_0c099e38;
case 0x0c099e3au: goto P_0c099e3a;
case 0x0c099e3cu: goto P_0c099e3c;
case 0x0c099e3eu: goto P_0c099e3e;
case 0x0c099e40u: goto P_0c099e40;
case 0x0c099e42u: goto P_0c099e42;
case 0x0c099e44u: goto P_0c099e44;
case 0x0c099e46u: goto P_0c099e46;
case 0x0c099e48u: goto P_0c099e48;
case 0x0c099e4au: goto P_0c099e4a;
case 0x0c099e4cu: goto P_0c099e4c;
case 0x0c099e4eu: goto P_0c099e4e;
case 0x0c099e50u: goto P_0c099e50;
case 0x0c099e52u: goto P_0c099e52;
case 0x0c099e54u: goto P_0c099e54;
case 0x0c099e56u: goto P_0c099e56;
case 0x0c099e58u: goto P_0c099e58;
case 0x0c099e5au: goto P_0c099e5a;
case 0x0c099e5cu: goto P_0c099e5c;
case 0x0c099e5eu: goto P_0c099e5e;
case 0x0c099e60u: goto P_0c099e60;
case 0x0c099e62u: goto P_0c099e62;
case 0x0c099e64u: goto P_0c099e64;
case 0x0c099e66u: goto P_0c099e66;
case 0x0c099e68u: goto P_0c099e68;
case 0x0c099e6au: goto P_0c099e6a;
case 0x0c099e6cu: goto P_0c099e6c;
case 0x0c099e6eu: goto P_0c099e6e;
case 0x0c099e70u: goto P_0c099e70;
case 0x0c099e72u: goto P_0c099e72;
case 0x0c099e74u: goto P_0c099e74;
case 0x0c099e76u: goto P_0c099e76;
case 0x0c099e78u: goto P_0c099e78;
case 0x0c099e7au: goto P_0c099e7a;
case 0x0c099e7cu: goto P_0c099e7c;
case 0x0c099e7eu: goto P_0c099e7e;
case 0x0c099e80u: goto P_0c099e80;
case 0x0c099e82u: goto P_0c099e82;
case 0x0c099e84u: goto P_0c099e84;
case 0x0c099e86u: goto P_0c099e86;
case 0x0c099e88u: goto P_0c099e88;
case 0x0c099e8au: goto P_0c099e8a;
case 0x0c099e8cu: goto P_0c099e8c;
case 0x0c099e8eu: goto P_0c099e8e;
case 0x0c099e90u: goto P_0c099e90;
case 0x0c099e92u: goto P_0c099e92;
case 0x0c099e94u: goto P_0c099e94;
case 0x0c099e96u: goto P_0c099e96;
case 0x0c099e98u: goto P_0c099e98;
case 0x0c099e9au: goto P_0c099e9a;
case 0x0c099e9cu: goto P_0c099e9c;
case 0x0c099e9eu: goto P_0c099e9e;
case 0x0c099ea0u: goto P_0c099ea0;
case 0x0c099ea2u: goto P_0c099ea2;
case 0x0c099ea4u: goto P_0c099ea4;
case 0x0c099ea6u: goto P_0c099ea6;
case 0x0c099ea8u: goto P_0c099ea8;
case 0x0c099eaau: goto P_0c099eaa;
case 0x0c099eacu: goto P_0c099eac;
case 0x0c099eaeu: goto P_0c099eae;
case 0x0c099eb0u: goto P_0c099eb0;
case 0x0c099eb2u: goto P_0c099eb2;
case 0x0c099eb4u: goto P_0c099eb4;
case 0x0c099eb6u: goto P_0c099eb6;
case 0x0c099eb8u: goto P_0c099eb8;
case 0x0c099ebau: goto P_0c099eba;
case 0x0c099ebcu: goto P_0c099ebc;
case 0x0c099ebeu: goto P_0c099ebe;
case 0x0c099ec0u: goto P_0c099ec0;
case 0x0c099ec2u: goto P_0c099ec2;
case 0x0c099ec4u: goto P_0c099ec4;
case 0x0c099ec6u: goto P_0c099ec6;
case 0x0c099ec8u: goto P_0c099ec8;
case 0x0c099ecau: goto P_0c099eca;
case 0x0c099eccu: goto P_0c099ecc;
case 0x0c099eceu: goto P_0c099ece;
case 0x0c099ed0u: goto P_0c099ed0;
case 0x0c099ed2u: goto P_0c099ed2;
case 0x0c099ed4u: goto P_0c099ed4;
case 0x0c099ed6u: goto P_0c099ed6;
case 0x0c099f00u: goto P_0c099f00;
case 0x0c099f02u: goto P_0c099f02;
case 0x0c099f04u: goto P_0c099f04;
case 0x0c099f06u: goto P_0c099f06;
case 0x0c099f08u: goto P_0c099f08;
case 0x0c099f0au: goto P_0c099f0a;
case 0x0c099f0cu: goto P_0c099f0c;
case 0x0c099f0eu: goto P_0c099f0e;
case 0x0c099f10u: goto P_0c099f10;
case 0x0c099f12u: goto P_0c099f12;
case 0x0c099f14u: goto P_0c099f14;
case 0x0c099f16u: goto P_0c099f16;
case 0x0c099f18u: goto P_0c099f18;
case 0x0c099f1au: goto P_0c099f1a;
case 0x0c099f1cu: goto P_0c099f1c;
case 0x0c099f1eu: goto P_0c099f1e;
case 0x0c099f20u: goto P_0c099f20;
case 0x0c099f22u: goto P_0c099f22;
case 0x0c099f24u: goto P_0c099f24;
case 0x0c099f26u: goto P_0c099f26;
case 0x0c099f28u: goto P_0c099f28;
case 0x0c099f2au: goto P_0c099f2a;
case 0x0c099f2cu: goto P_0c099f2c;
case 0x0c099f2eu: goto P_0c099f2e;
case 0x0c099f30u: goto P_0c099f30;
case 0x0c099f32u: goto P_0c099f32;
case 0x0c099f34u: goto P_0c099f34;
case 0x0c099f36u: goto P_0c099f36;
case 0x0c099f38u: goto P_0c099f38;
case 0x0c099f3au: goto P_0c099f3a;
case 0x0c099f3cu: goto P_0c099f3c;
case 0x0c099f3eu: goto P_0c099f3e;
case 0x0c099f40u: goto P_0c099f40;
case 0x0c099f42u: goto P_0c099f42;
case 0x0c099f44u: goto P_0c099f44;
case 0x0c099f46u: goto P_0c099f46;
case 0x0c099f48u: goto P_0c099f48;
case 0x0c099f4au: goto P_0c099f4a;
case 0x0c099f4cu: goto P_0c099f4c;
case 0x0c099f4eu: goto P_0c099f4e;
case 0x0c099f50u: goto P_0c099f50;
case 0x0c099f52u: goto P_0c099f52;
case 0x0c099f54u: goto P_0c099f54;
case 0x0c099f56u: goto P_0c099f56;
case 0x0c099f58u: goto P_0c099f58;
case 0x0c099f5au: goto P_0c099f5a;
case 0x0c099f5cu: goto P_0c099f5c;
case 0x0c099f5eu: goto P_0c099f5e;
case 0x0c099f60u: goto P_0c099f60;
case 0x0c099f62u: goto P_0c099f62;
case 0x0c099f64u: goto P_0c099f64;
case 0x0c099f66u: goto P_0c099f66;
case 0x0c099f68u: goto P_0c099f68;
case 0x0c099f6au: goto P_0c099f6a;
case 0x0c099f6cu: goto P_0c099f6c;
case 0x0c099f6eu: goto P_0c099f6e;
case 0x0c099f70u: goto P_0c099f70;
case 0x0c099f72u: goto P_0c099f72;
case 0x0c099f74u: goto P_0c099f74;
case 0x0c099f76u: goto P_0c099f76;
case 0x0c099f78u: goto P_0c099f78;
case 0x0c099f7au: goto P_0c099f7a;
case 0x0c099f7cu: goto P_0c099f7c;
case 0x0c099f7eu: goto P_0c099f7e;
case 0x0c099f80u: goto P_0c099f80;
case 0x0c099f82u: goto P_0c099f82;
case 0x0c099f84u: goto P_0c099f84;
case 0x0c099f86u: goto P_0c099f86;
case 0x0c099f88u: goto P_0c099f88;
case 0x0c099f8au: goto P_0c099f8a;
case 0x0c099f8cu: goto P_0c099f8c;
case 0x0c099f8eu: goto P_0c099f8e;
case 0x0c099f90u: goto P_0c099f90;
case 0x0c099f92u: goto P_0c099f92;
case 0x0c099f94u: goto P_0c099f94;
case 0x0c099f96u: goto P_0c099f96;
case 0x0c099f98u: goto P_0c099f98;
case 0x0c099f9au: goto P_0c099f9a;
case 0x0c099f9cu: goto P_0c099f9c;
case 0x0c099f9eu: goto P_0c099f9e;
case 0x0c099fa0u: goto P_0c099fa0;
case 0x0c099fa2u: goto P_0c099fa2;
case 0x0c099fa4u: goto P_0c099fa4;
case 0x0c099fa6u: goto P_0c099fa6;
case 0x0c099fa8u: goto P_0c099fa8;
case 0x0c099faau: goto P_0c099faa;
case 0x0c099facu: goto P_0c099fac;
case 0x0c099faeu: goto P_0c099fae;
case 0x0c099fb0u: goto P_0c099fb0;
case 0x0c099fb2u: goto P_0c099fb2;
case 0x0c099fb4u: goto P_0c099fb4;
case 0x0c099fb6u: goto P_0c099fb6;
case 0x0c099fb8u: goto P_0c099fb8;
case 0x0c099fbau: goto P_0c099fba;
case 0x0c099fbcu: goto P_0c099fbc;
case 0x0c099fbeu: goto P_0c099fbe;
case 0x0c099fc0u: goto P_0c099fc0;
case 0x0c099fc2u: goto P_0c099fc2;
case 0x0c099fc4u: goto P_0c099fc4;
case 0x0c099fc6u: goto P_0c099fc6;
case 0x0c099fc8u: goto P_0c099fc8;
case 0x0c099fcau: goto P_0c099fca;
case 0x0c099fccu: goto P_0c099fcc;
case 0x0c099fceu: goto P_0c099fce;
case 0x0c099fd0u: goto P_0c099fd0;
case 0x0c099fd2u: goto P_0c099fd2;
case 0x0c099fd4u: goto P_0c099fd4;
case 0x0c099fd6u: goto P_0c099fd6;
case 0x0c099fd8u: goto P_0c099fd8;
case 0x0c099fdau: goto P_0c099fda;
case 0x0c099fdcu: goto P_0c099fdc;
case 0x0c099fdeu: goto P_0c099fde;
case 0x0c099fe0u: goto P_0c099fe0;
case 0x0c099fe2u: goto P_0c099fe2;
case 0x0c099fe4u: goto P_0c099fe4;
case 0x0c099fe6u: goto P_0c099fe6;
case 0x0c099fe8u: goto P_0c099fe8;
case 0x0c099feau: goto P_0c099fea;
case 0x0c099fecu: goto P_0c099fec;
case 0x0c099feeu: goto P_0c099fee;
case 0x0c099ff0u: goto P_0c099ff0;
case 0x0c099ff2u: goto P_0c099ff2;
case 0x0c099ff4u: goto P_0c099ff4;
case 0x0c099ff6u: goto P_0c099ff6;
case 0x0c099ff8u: goto P_0c099ff8;
case 0x0c09a01cu: goto P_0c09a01c;
case 0x0c09a01eu: goto P_0c09a01e;
case 0x0c09a020u: goto P_0c09a020;
case 0x0c09a022u: goto P_0c09a022;
case 0x0c09a024u: goto P_0c09a024;
case 0x0c09a026u: goto P_0c09a026;
case 0x0c09a028u: goto P_0c09a028;
case 0x0c09a02au: goto P_0c09a02a;
case 0x0c09a02cu: goto P_0c09a02c;
case 0x0c09a02eu: goto P_0c09a02e;
case 0x0c09a030u: goto P_0c09a030;
case 0x0c09a032u: goto P_0c09a032;
case 0x0c09a034u: goto P_0c09a034;
case 0x0c09a036u: goto P_0c09a036;
case 0x0c09a038u: goto P_0c09a038;
case 0x0c09a03au: goto P_0c09a03a;
case 0x0c09a03cu: goto P_0c09a03c;
case 0x0c09a03eu: goto P_0c09a03e;
case 0x0c09a040u: goto P_0c09a040;
case 0x0c09a042u: goto P_0c09a042;
case 0x0c09a044u: goto P_0c09a044;
case 0x0c09a046u: goto P_0c09a046;
case 0x0c09a048u: goto P_0c09a048;
case 0x0c09a04au: goto P_0c09a04a;
case 0x0c09a04cu: goto P_0c09a04c;
case 0x0c09a04eu: goto P_0c09a04e;
case 0x0c09a050u: goto P_0c09a050;
case 0x0c09a052u: goto P_0c09a052;
case 0x0c09a054u: goto P_0c09a054;
case 0x0c09a056u: goto P_0c09a056;
case 0x0c09a058u: goto P_0c09a058;
case 0x0c09a05au: goto P_0c09a05a;
case 0x0c09a05cu: goto P_0c09a05c;
case 0x0c09a05eu: goto P_0c09a05e;
case 0x0c09a060u: goto P_0c09a060;
case 0x0c09a062u: goto P_0c09a062;
case 0x0c09a064u: goto P_0c09a064;
case 0x0c09a066u: goto P_0c09a066;
case 0x0c09a068u: goto P_0c09a068;
case 0x0c09a06au: goto P_0c09a06a;
case 0x0c09a06cu: goto P_0c09a06c;
case 0x0c09a06eu: goto P_0c09a06e;
case 0x0c09a070u: goto P_0c09a070;
case 0x0c09a072u: goto P_0c09a072;
case 0x0c09a074u: goto P_0c09a074;
case 0x0c09a076u: goto P_0c09a076;
case 0x0c09a078u: goto P_0c09a078;
case 0x0c09a07au: goto P_0c09a07a;
case 0x0c09a07cu: goto P_0c09a07c;
case 0x0c09a07eu: goto P_0c09a07e;
case 0x0c09a080u: goto P_0c09a080;
case 0x0c09a082u: goto P_0c09a082;
case 0x0c09a084u: goto P_0c09a084;
case 0x0c0c76d4u: goto P_0c0c76d4;
case 0x0c0c76d6u: goto P_0c0c76d6;
case 0x0c0c76d8u: goto P_0c0c76d8;
case 0x0c0c76dau: goto P_0c0c76da;
case 0x0c0c76dcu: goto P_0c0c76dc;
case 0x0c0c76deu: goto P_0c0c76de;
case 0x0c0c76e0u: goto P_0c0c76e0;
case 0x0c0c76e2u: goto P_0c0c76e2;
case 0x0c0c76e4u: goto P_0c0c76e4;
case 0x0c0c76e6u: goto P_0c0c76e6;
case 0x0c0c76e8u: goto P_0c0c76e8;
case 0x0c0c76eau: goto P_0c0c76ea;
case 0x0c0c76ecu: goto P_0c0c76ec;
case 0x0c0c76eeu: goto P_0c0c76ee;
case 0x0c0c76f0u: goto P_0c0c76f0;
case 0x0c0c76f2u: goto P_0c0c76f2;
case 0x0c0c76f4u: goto P_0c0c76f4;
case 0x0c0c76f6u: goto P_0c0c76f6;
case 0x0c0c76f8u: goto P_0c0c76f8;
case 0x0c0c76fau: goto P_0c0c76fa;
case 0x0c0c76fcu: goto P_0c0c76fc;
case 0x0c0c76feu: goto P_0c0c76fe;
case 0x0c0c7700u: goto P_0c0c7700;
case 0x0c0c7702u: goto P_0c0c7702;
case 0x0c0c7704u: goto P_0c0c7704;
case 0x0c0c7706u: goto P_0c0c7706;
case 0x0c0c7708u: goto P_0c0c7708;
case 0x0c0c770au: goto P_0c0c770a;
case 0x0c0c770cu: goto P_0c0c770c;
case 0x0c0c770eu: goto P_0c0c770e;
case 0x0c0c7710u: goto P_0c0c7710;
case 0x0c0c7712u: goto P_0c0c7712;
case 0x0c0c7714u: goto P_0c0c7714;
case 0x0c0c7716u: goto P_0c0c7716;
case 0x0c0c7718u: goto P_0c0c7718;
case 0x0c0c771au: goto P_0c0c771a;
case 0x0c0c771cu: goto P_0c0c771c;
case 0x0c0c771eu: goto P_0c0c771e;
case 0x0c0c7720u: goto P_0c0c7720;
case 0x0c0c7722u: goto P_0c0c7722;
case 0x0c0c7724u: goto P_0c0c7724;
case 0x0c0c7726u: goto P_0c0c7726;
case 0x0c0c7728u: goto P_0c0c7728;
case 0x0c0c772au: goto P_0c0c772a;
case 0x0c0c772cu: goto P_0c0c772c;
case 0x0c0c772eu: goto P_0c0c772e;
case 0x0c0c7730u: goto P_0c0c7730;
case 0x0c0c7732u: goto P_0c0c7732;
case 0x0c0c7734u: goto P_0c0c7734;
case 0x0c0c7736u: goto P_0c0c7736;
case 0x0c0c7738u: goto P_0c0c7738;
case 0x0c0c773au: goto P_0c0c773a;
case 0x0c0c773cu: goto P_0c0c773c;
case 0x0c0c773eu: goto P_0c0c773e;
case 0x0c0c7740u: goto P_0c0c7740;
case 0x0c0c7742u: goto P_0c0c7742;
case 0x0c0c7744u: goto P_0c0c7744;
case 0x0c0c7746u: goto P_0c0c7746;
case 0x0c0c7778u: goto P_0c0c7778;
case 0x0c0c777au: goto P_0c0c777a;
case 0x0c0c777cu: goto P_0c0c777c;
case 0x0c0c777eu: goto P_0c0c777e;
case 0x0c0c7780u: goto P_0c0c7780;
case 0x0c0c7782u: goto P_0c0c7782;
case 0x0c0c7784u: goto P_0c0c7784;
case 0x0c0c7786u: goto P_0c0c7786;
case 0x0c0c7788u: goto P_0c0c7788;
case 0x0c0c778au: goto P_0c0c778a;
case 0x0c0c778cu: goto P_0c0c778c;
case 0x0c0c778eu: goto P_0c0c778e;
case 0x0c0c7790u: goto P_0c0c7790;
case 0x0c0c7792u: goto P_0c0c7792;
case 0x0c0c7794u: goto P_0c0c7794;
case 0x0c0c7796u: goto P_0c0c7796;
case 0x0c0c7798u: goto P_0c0c7798;
case 0x0c0c779au: goto P_0c0c779a;
case 0x0c0c779cu: goto P_0c0c779c;
case 0x0c0c779eu: goto P_0c0c779e;
case 0x0c0c77a0u: goto P_0c0c77a0;
case 0x0c0c77a2u: goto P_0c0c77a2;
case 0x0c0c77a4u: goto P_0c0c77a4;
case 0x0c0c77a6u: goto P_0c0c77a6;
case 0x0c0c77a8u: goto P_0c0c77a8;
case 0x0c0c77aau: goto P_0c0c77aa;
case 0x0c0c77acu: goto P_0c0c77ac;
case 0x0c0c77aeu: goto P_0c0c77ae;
case 0x0c0c77b0u: goto P_0c0c77b0;
case 0x0c0c77b2u: goto P_0c0c77b2;
case 0x0c0c77b4u: goto P_0c0c77b4;
case 0x0c0c77b6u: goto P_0c0c77b6;
case 0x0c0c77b8u: goto P_0c0c77b8;
case 0x0c0c77bau: goto P_0c0c77ba;
case 0x0c0c77bcu: goto P_0c0c77bc;
case 0x0c0c77beu: goto P_0c0c77be;
case 0x0c0c77c0u: goto P_0c0c77c0;
case 0x0c0c77c2u: goto P_0c0c77c2;
case 0x0c0c77c4u: goto P_0c0c77c4;
case 0x0c0c77c6u: goto P_0c0c77c6;
case 0x0c0c77c8u: goto P_0c0c77c8;
case 0x0c0c77cau: goto P_0c0c77ca;
case 0x0c0c77ccu: goto P_0c0c77cc;
case 0x0c0c77ceu: goto P_0c0c77ce;
case 0x0c0c77d0u: goto P_0c0c77d0;
case 0x0c0c77d2u: goto P_0c0c77d2;
case 0x0c0c77d4u: goto P_0c0c77d4;
case 0x0c0c77d6u: goto P_0c0c77d6;
case 0x0c0c77d8u: goto P_0c0c77d8;
case 0x0c0c77dau: goto P_0c0c77da;
case 0x0c0c77dcu: goto P_0c0c77dc;
case 0x0c0c77deu: goto P_0c0c77de;
case 0x0c0c77e0u: goto P_0c0c77e0;
case 0x0c0c77e2u: goto P_0c0c77e2;
case 0x0c0c77e4u: goto P_0c0c77e4;
case 0x0c0c77e6u: goto P_0c0c77e6;
case 0x0c0c77e8u: goto P_0c0c77e8;
case 0x0c0c77eau: goto P_0c0c77ea;
case 0x0c0c77ecu: goto P_0c0c77ec;
case 0x0c0c77eeu: goto P_0c0c77ee;
case 0x0c0c77f0u: goto P_0c0c77f0;
case 0x0c0c77f2u: goto P_0c0c77f2;
case 0x0c0c77f4u: goto P_0c0c77f4;
case 0x0c0c77f6u: goto P_0c0c77f6;
case 0x0c0c77f8u: goto P_0c0c77f8;
case 0x0c0c77fau: goto P_0c0c77fa;
case 0x0c0c77fcu: goto P_0c0c77fc;
case 0x0c0c77feu: goto P_0c0c77fe;
case 0x0c0c7800u: goto P_0c0c7800;
case 0x0c0c7802u: goto P_0c0c7802;
case 0x0c0c7804u: goto P_0c0c7804;
case 0x0c0c7806u: goto P_0c0c7806;
case 0x0c0c7808u: goto P_0c0c7808;
case 0x0c0c780au: goto P_0c0c780a;
case 0x0c0c780cu: goto P_0c0c780c;
case 0x0c0c780eu: goto P_0c0c780e;
case 0x0c0c7810u: goto P_0c0c7810;
case 0x0c0c7812u: goto P_0c0c7812;
case 0x0c0c7814u: goto P_0c0c7814;
case 0x0c0c7816u: goto P_0c0c7816;
case 0x0c0c7818u: goto P_0c0c7818;
case 0x0c0c781au: goto P_0c0c781a;
case 0x0c0c781cu: goto P_0c0c781c;
case 0x0c0c781eu: goto P_0c0c781e;
case 0x0c0c7820u: goto P_0c0c7820;
case 0x0c0c7822u: goto P_0c0c7822;
case 0x0c0c7824u: goto P_0c0c7824;
case 0x0c0c7826u: goto P_0c0c7826;
case 0x0c0c7828u: goto P_0c0c7828;
case 0x0c0c782au: goto P_0c0c782a;
case 0x0c0c782cu: goto P_0c0c782c;
case 0x0c0c782eu: goto P_0c0c782e;
case 0x0c0c7830u: goto P_0c0c7830;
case 0x0c0c7832u: goto P_0c0c7832;
case 0x0c0c7834u: goto P_0c0c7834;
case 0x0c0c7836u: goto P_0c0c7836;
case 0x0c0c7838u: goto P_0c0c7838;
case 0x0c0c783au: goto P_0c0c783a;
case 0x0c0c783cu: goto P_0c0c783c;
case 0x0c0c783eu: goto P_0c0c783e;
case 0x0c0c7840u: goto P_0c0c7840;
case 0x0c0c7842u: goto P_0c0c7842;
case 0x0c0c7844u: goto P_0c0c7844;
case 0x0c0c7846u: goto P_0c0c7846;
case 0x0c0c7848u: goto P_0c0c7848;
case 0x0c0c784au: goto P_0c0c784a;
case 0x0c0c784cu: goto P_0c0c784c;
case 0x0c0c784eu: goto P_0c0c784e;
case 0x0c0c7850u: goto P_0c0c7850;
case 0x0c0c7852u: goto P_0c0c7852;
case 0x0c0c7854u: goto P_0c0c7854;
case 0x0c0c7856u: goto P_0c0c7856;
case 0x0c0c7858u: goto P_0c0c7858;
case 0x0c0c785au: goto P_0c0c785a;
case 0x0c0c785cu: goto P_0c0c785c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03757c: /* original 4f22, guest PC 0x0c03757c */
if(!s->budget--) { s->failed_pc=0x0c03757cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03757e;
P_0c03757e: /* original d344, guest PC 0x0c03757e */
if(!s->budget--) { s->failed_pc=0x0c03757eu; return 0; }
r[3]=read(ram,0x0c037690u,4);
goto P_0c037580;
P_0c037580: /* original 6143, guest PC 0x0c037580 */
if(!s->budget--) { s->failed_pc=0x0c037580u; return 0; }
r[1]=r[4];
goto P_0c037582;
P_0c037582: /* original e53c, guest PC 0x0c037582 */
if(!s->budget--) { s->failed_pc=0x0c037582u; return 0; }
r[5]=0x0000003cu;
goto P_0c037584;
P_0c037584: /* original 430b, guest PC 0x0c037584 */
if(!s->budget--) { s->failed_pc=0x0c037584u; return 0; }
target=r[3];
r[16]=code_base|0x0c037588u;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037588u) { target=s->pc; goto dispatch; }
goto P_0c037588;
P_0c037586: /* original 6053, guest PC 0x0c037586 */
if(!s->budget--) { s->failed_pc=0x0c037586u; return 0; }
r[0]=r[5];
goto P_0c037588;
P_0c037588: /* original 80e6, guest PC 0x0c037588 */
if(!s->budget--) { s->failed_pc=0x0c037588u; return 0; }
write(ram,r[14]+6,r[0],1);
goto P_0c03758a;
P_0c03758a: /* original 6053, guest PC 0x0c03758a */
if(!s->budget--) { s->failed_pc=0x0c03758au; return 0; }
r[0]=r[5];
goto P_0c03758c;
P_0c03758c: /* original d241, guest PC 0x0c03758c */
if(!s->budget--) { s->failed_pc=0x0c03758cu; return 0; }
r[2]=read(ram,0x0c037694u,4);
goto P_0c03758e;
P_0c03758e: /* original 420b, guest PC 0x0c03758e */
if(!s->budget--) { s->failed_pc=0x0c03758eu; return 0; }
target=r[2];
r[16]=code_base|0x0c037592u;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037592u) { target=s->pc; goto dispatch; }
goto P_0c037592;
P_0c037590: /* original 6143, guest PC 0x0c037590 */
if(!s->budget--) { s->failed_pc=0x0c037590u; return 0; }
r[1]=r[4];
goto P_0c037592;
P_0c037592: /* original d33f, guest PC 0x0c037592 */
if(!s->budget--) { s->failed_pc=0x0c037592u; return 0; }
r[3]=read(ram,0x0c037690u,4);
goto P_0c037594;
P_0c037594: /* original 6103, guest PC 0x0c037594 */
if(!s->budget--) { s->failed_pc=0x0c037594u; return 0; }
r[1]=r[0];
goto P_0c037596;
P_0c037596: /* original 6403, guest PC 0x0c037596 */
if(!s->budget--) { s->failed_pc=0x0c037596u; return 0; }
r[4]=r[0];
goto P_0c037598;
P_0c037598: /* original 430b, guest PC 0x0c037598 */
if(!s->budget--) { s->failed_pc=0x0c037598u; return 0; }
target=r[3];
r[16]=code_base|0x0c03759cu;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03759cu) { target=s->pc; goto dispatch; }
goto P_0c03759c;
P_0c03759a: /* original 6053, guest PC 0x0c03759a */
if(!s->budget--) { s->failed_pc=0x0c03759au; return 0; }
r[0]=r[5];
goto P_0c03759c;
P_0c03759c: /* original 80e5, guest PC 0x0c03759c */
if(!s->budget--) { s->failed_pc=0x0c03759cu; return 0; }
write(ram,r[14]+5,r[0],1);
goto P_0c03759e;
P_0c03759e: /* original 6053, guest PC 0x0c03759e */
if(!s->budget--) { s->failed_pc=0x0c03759eu; return 0; }
r[0]=r[5];
goto P_0c0375a0;
P_0c0375a0: /* original d23c, guest PC 0x0c0375a0 */
if(!s->budget--) { s->failed_pc=0x0c0375a0u; return 0; }
r[2]=read(ram,0x0c037694u,4);
goto P_0c0375a2;
P_0c0375a2: /* original 420b, guest PC 0x0c0375a2 */
if(!s->budget--) { s->failed_pc=0x0c0375a2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0375a6u;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0375a6u) { target=s->pc; goto dispatch; }
goto P_0c0375a6;
P_0c0375a4: /* original 6143, guest PC 0x0c0375a4 */
if(!s->budget--) { s->failed_pc=0x0c0375a4u; return 0; }
r[1]=r[4];
goto P_0c0375a6;
P_0c0375a6: /* original d33a, guest PC 0x0c0375a6 */
if(!s->budget--) { s->failed_pc=0x0c0375a6u; return 0; }
r[3]=read(ram,0x0c037690u,4);
goto P_0c0375a8;
P_0c0375a8: /* original 6103, guest PC 0x0c0375a8 */
if(!s->budget--) { s->failed_pc=0x0c0375a8u; return 0; }
r[1]=r[0];
goto P_0c0375aa;
P_0c0375aa: /* original 6403, guest PC 0x0c0375aa */
if(!s->budget--) { s->failed_pc=0x0c0375aau; return 0; }
r[4]=r[0];
goto P_0c0375ac;
P_0c0375ac: /* original e518, guest PC 0x0c0375ac */
if(!s->budget--) { s->failed_pc=0x0c0375acu; return 0; }
r[5]=0x00000018u;
goto P_0c0375ae;
P_0c0375ae: /* original 430b, guest PC 0x0c0375ae */
if(!s->budget--) { s->failed_pc=0x0c0375aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0375b2u;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0375b2u) { target=s->pc; goto dispatch; }
goto P_0c0375b2;
P_0c0375b0: /* original 6053, guest PC 0x0c0375b0 */
if(!s->budget--) { s->failed_pc=0x0c0375b0u; return 0; }
r[0]=r[5];
goto P_0c0375b2;
P_0c0375b2: /* original 80e4, guest PC 0x0c0375b2 */
if(!s->budget--) { s->failed_pc=0x0c0375b2u; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0375b4;
P_0c0375b4: /* original 6053, guest PC 0x0c0375b4 */
if(!s->budget--) { s->failed_pc=0x0c0375b4u; return 0; }
r[0]=r[5];
goto P_0c0375b6;
P_0c0375b6: /* original d237, guest PC 0x0c0375b6 */
if(!s->budget--) { s->failed_pc=0x0c0375b6u; return 0; }
r[2]=read(ram,0x0c037694u,4);
goto P_0c0375b8;
P_0c0375b8: /* original 420b, guest PC 0x0c0375b8 */
if(!s->budget--) { s->failed_pc=0x0c0375b8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0375bcu;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0375bcu) { target=s->pc; goto dispatch; }
goto P_0c0375bc;
P_0c0375ba: /* original 6143, guest PC 0x0c0375ba */
if(!s->budget--) { s->failed_pc=0x0c0375bau; return 0; }
r[1]=r[4];
goto P_0c0375bc;
P_0c0375bc: /* original d335, guest PC 0x0c0375bc */
if(!s->budget--) { s->failed_pc=0x0c0375bcu; return 0; }
r[3]=read(ram,0x0c037694u,4);
goto P_0c0375be;
P_0c0375be: /* original 6403, guest PC 0x0c0375be */
if(!s->budget--) { s->failed_pc=0x0c0375beu; return 0; }
r[4]=r[0];
goto P_0c0375c0;
P_0c0375c0: /* original 9763, guest PC 0x0c0375c0 */
if(!s->budget--) { s->failed_pc=0x0c0375c0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03768au,2);
goto P_0c0375c2;
P_0c0375c2: /* original 6103, guest PC 0x0c0375c2 */
if(!s->budget--) { s->failed_pc=0x0c0375c2u; return 0; }
r[1]=r[0];
goto P_0c0375c4;
P_0c0375c4: /* original 430b, guest PC 0x0c0375c4 */
if(!s->budget--) { s->failed_pc=0x0c0375c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0375c8u;
r[0]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0375c8u) { target=s->pc; goto dispatch; }
goto P_0c0375c8;
P_0c0375c6: /* original 6073, guest PC 0x0c0375c6 */
if(!s->budget--) { s->failed_pc=0x0c0375c6u; return 0; }
r[0]=r[7];
goto P_0c0375c8;
P_0c0375c8: /* original d231, guest PC 0x0c0375c8 */
if(!s->budget--) { s->failed_pc=0x0c0375c8u; return 0; }
r[2]=read(ram,0x0c037690u,4);
goto P_0c0375ca;
P_0c0375ca: /* original 6143, guest PC 0x0c0375ca */
if(!s->budget--) { s->failed_pc=0x0c0375cau; return 0; }
r[1]=r[4];
goto P_0c0375cc;
P_0c0375cc: /* original 6603, guest PC 0x0c0375cc */
if(!s->budget--) { s->failed_pc=0x0c0375ccu; return 0; }
r[6]=r[0];
goto P_0c0375ce;
P_0c0375ce: /* original 420b, guest PC 0x0c0375ce */
if(!s->budget--) { s->failed_pc=0x0c0375ceu; return 0; }
target=r[2];
r[16]=code_base|0x0c0375d2u;
r[0]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0375d2u) { target=s->pc; goto dispatch; }
goto P_0c0375d2;
P_0c0375d0: /* original 6073, guest PC 0x0c0375d0 */
if(!s->budget--) { s->failed_pc=0x0c0375d0u; return 0; }
r[0]=r[7];
goto P_0c0375d2;
P_0c0375d2: /* original 6463, guest PC 0x0c0375d2 */
if(!s->budget--) { s->failed_pc=0x0c0375d2u; return 0; }
r[4]=r[6];
goto P_0c0375d4;
P_0c0375d4: /* original 7401, guest PC 0x0c0375d4 */
if(!s->budget--) { s->failed_pc=0x0c0375d4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0375d6;
P_0c0375d6: /* original 4409, guest PC 0x0c0375d6 */
if(!s->budget--) { s->failed_pc=0x0c0375d6u; return 0; }
r[4]>>=2;
goto P_0c0375d8;
P_0c0375d8: /* original 6503, guest PC 0x0c0375d8 */
if(!s->budget--) { s->failed_pc=0x0c0375d8u; return 0; }
r[5]=r[0];
goto P_0c0375da;
P_0c0375da: /* original 3456, guest PC 0x0c0375da */
if(!s->budget--) { s->failed_pc=0x0c0375dau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[5])!=0);
goto P_0c0375dc;
P_0c0375dc: /* original 8904, guest PC 0x0c0375dc */
if(!s->budget--) { s->failed_pc=0x0c0375dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0375e8; }
goto P_0c0375de;
P_0c0375de: /* original 9255, guest PC 0x0c0375de */
if(!s->budget--) { s->failed_pc=0x0c0375deu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03768cu,2);
goto P_0c0375e0;
P_0c0375e0: /* original 3548, guest PC 0x0c0375e0 */
if(!s->budget--) { s->failed_pc=0x0c0375e0u; return 0; }
r[5]-=r[4];
goto P_0c0375e2;
P_0c0375e2: /* original 362c, guest PC 0x0c0375e2 */
if(!s->budget--) { s->failed_pc=0x0c0375e2u; return 0; }
r[6]+=r[2];
goto P_0c0375e4;
P_0c0375e4: /* original a00d, guest PC 0x0c0375e4 */
if(!s->budget--) { s->failed_pc=0x0c0375e4u; return 0; }
write(ram,r[14],r[6],2);
goto P_0c037602;
P_0c0375e6: /* original 2e61, guest PC 0x0c0375e6 */
if(!s->budget--) { s->failed_pc=0x0c0375e6u; return 0; }
write(ram,r[14],r[6],2);
goto P_0c0375e8;
P_0c0375e8: /* original 9251, guest PC 0x0c0375e8 */
if(!s->budget--) { s->failed_pc=0x0c0375e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03768eu,2);
goto P_0c0375ea;
P_0c0375ea: /* original 3748, guest PC 0x0c0375ea */
if(!s->budget--) { s->failed_pc=0x0c0375eau; return 0; }
r[7]-=r[4];
goto P_0c0375ec;
P_0c0375ec: /* original 357c, guest PC 0x0c0375ec */
if(!s->budget--) { s->failed_pc=0x0c0375ecu; return 0; }
r[5]+=r[7];
goto P_0c0375ee;
P_0c0375ee: /* original 362c, guest PC 0x0c0375ee */
if(!s->budget--) { s->failed_pc=0x0c0375eeu; return 0; }
r[6]+=r[2];
goto P_0c0375f0;
P_0c0375f0: /* original 2e61, guest PC 0x0c0375f0 */
if(!s->budget--) { s->failed_pc=0x0c0375f0u; return 0; }
write(ram,r[14],r[6],2);
goto P_0c0375f2;
P_0c0375f2: /* original 61e1, guest PC 0x0c0375f2 */
if(!s->budget--) { s->failed_pc=0x0c0375f2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c0375f4;
P_0c0375f4: /* original d328, guest PC 0x0c0375f4 */
if(!s->budget--) { s->failed_pc=0x0c0375f4u; return 0; }
r[3]=read(ram,0x0c037698u,4);
goto P_0c0375f6;
P_0c0375f6: /* original 611d, guest PC 0x0c0375f6 */
if(!s->budget--) { s->failed_pc=0x0c0375f6u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0375f8;
P_0c0375f8: /* original 430b, guest PC 0x0c0375f8 */
if(!s->budget--) { s->failed_pc=0x0c0375f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0375fcu;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0375fcu) { target=s->pc; goto dispatch; }
goto P_0c0375fc;
P_0c0375fa: /* original e004, guest PC 0x0c0375fa */
if(!s->budget--) { s->failed_pc=0x0c0375fau; return 0; }
r[0]=0x00000004u;
goto P_0c0375fc;
P_0c0375fc: /* original 2008, guest PC 0x0c0375fc */
if(!s->budget--) { s->failed_pc=0x0c0375fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0375fe;
P_0c0375fe: /* original 8b00, guest PC 0x0c0375fe */
if(!s->budget--) { s->failed_pc=0x0c0375feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037602; }
goto P_0c037600;
P_0c037600: /* original 7501, guest PC 0x0c037600 */
if(!s->budget--) { s->failed_pc=0x0c037600u; return 0; }
r[5]+=0x00000001u;
goto P_0c037602;
P_0c037602: /* original 61e1, guest PC 0x0c037602 */
if(!s->budget--) { s->failed_pc=0x0c037602u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c037604;
P_0c037604: /* original e401, guest PC 0x0c037604 */
if(!s->budget--) { s->failed_pc=0x0c037604u; return 0; }
r[4]=0x00000001u;
goto P_0c037606;
P_0c037606: /* original d324, guest PC 0x0c037606 */
if(!s->budget--) { s->failed_pc=0x0c037606u; return 0; }
r[3]=read(ram,0x0c037698u,4);
goto P_0c037608;
P_0c037608: /* original e60c, guest PC 0x0c037608 */
if(!s->budget--) { s->failed_pc=0x0c037608u; return 0; }
r[6]=0x0000000cu;
goto P_0c03760a;
P_0c03760a: /* original d724, guest PC 0x0c03760a */
if(!s->budget--) { s->failed_pc=0x0c03760au; return 0; }
r[7]=read(ram,0x0c03769cu,4);
goto P_0c03760c;
P_0c03760c: /* original 611d, guest PC 0x0c03760c */
if(!s->budget--) { s->failed_pc=0x0c03760cu; return 0; }
r[1]=r[1]&65535u;
goto P_0c03760e;
P_0c03760e: /* original 430b, guest PC 0x0c03760e */
if(!s->budget--) { s->failed_pc=0x0c03760eu; return 0; }
target=r[3];
r[16]=code_base|0x0c037612u;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037612u) { target=s->pc; goto dispatch; }
goto P_0c037612;
P_0c037610: /* original e004, guest PC 0x0c037610 */
if(!s->budget--) { s->failed_pc=0x0c037610u; return 0; }
r[0]=0x00000004u;
goto P_0c037612;
P_0c037612: /* original 2008, guest PC 0x0c037612 */
if(!s->budget--) { s->failed_pc=0x0c037612u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c037614;
P_0c037614: /* original 8b0e, guest PC 0x0c037614 */
if(!s->budget--) { s->failed_pc=0x0c037614u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037634; }
goto P_0c037616;
P_0c037616: /* original 5171, guest PC 0x0c037616 */
if(!s->budget--) { s->failed_pc=0x0c037616u; return 0; }
r[1]=read(ram,r[7]+4,4);
goto P_0c037618;
P_0c037618: /* original 3512, guest PC 0x0c037618 */
if(!s->budget--) { s->failed_pc=0x0c037618u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[1])!=0);
goto P_0c03761a;
P_0c03761a: /* original 8b13, guest PC 0x0c03761a */
if(!s->budget--) { s->failed_pc=0x0c03761au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037644; }
goto P_0c03761c;
P_0c03761c: /* original e402, guest PC 0x0c03761c */
if(!s->budget--) { s->failed_pc=0x0c03761cu; return 0; }
r[4]=0x00000002u;
goto P_0c03761e;
P_0c03761e: /* original 6043, guest PC 0x0c03761e */
if(!s->budget--) { s->failed_pc=0x0c03761eu; return 0; }
r[0]=r[4];
goto P_0c037620;
P_0c037620: /* original 4008, guest PC 0x0c037620 */
if(!s->budget--) { s->failed_pc=0x0c037620u; return 0; }
r[0]<<=2;
goto P_0c037622;
P_0c037622: /* original 037e, guest PC 0x0c037622 */
if(!s->budget--) { s->failed_pc=0x0c037622u; return 0; }
r[3]=read(ram,r[7]+r[0],4);
goto P_0c037624;
P_0c037624: /* original 7301, guest PC 0x0c037624 */
if(!s->budget--) { s->failed_pc=0x0c037624u; return 0; }
r[3]+=0x00000001u;
goto P_0c037626;
P_0c037626: /* original 3532, guest PC 0x0c037626 */
if(!s->budget--) { s->failed_pc=0x0c037626u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[3])!=0);
goto P_0c037628;
P_0c037628: /* original 8b0c, guest PC 0x0c037628 */
if(!s->budget--) { s->failed_pc=0x0c037628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037644; }
goto P_0c03762a;
P_0c03762a: /* original 7401, guest PC 0x0c03762a */
if(!s->budget--) { s->failed_pc=0x0c03762au; return 0; }
r[4]+=0x00000001u;
goto P_0c03762c;
P_0c03762c: /* original 3462, guest PC 0x0c03762c */
if(!s->budget--) { s->failed_pc=0x0c03762cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c03762e;
P_0c03762e: /* original 8bf6, guest PC 0x0c03762e */
if(!s->budget--) { s->failed_pc=0x0c03762eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03761e; }
goto P_0c037630;
P_0c037630: /* original a008, guest PC 0x0c037630 */
if(!s->budget--) { s->failed_pc=0x0c037630u; return 0; }
goto P_0c037644;
P_0c037632: /* original 0009, guest PC 0x0c037632 */
if(!s->budget--) { s->failed_pc=0x0c037632u; return 0; }
goto P_0c037634;
P_0c037634: /* original 6043, guest PC 0x0c037634 */
if(!s->budget--) { s->failed_pc=0x0c037634u; return 0; }
r[0]=r[4];
goto P_0c037636;
P_0c037636: /* original 4008, guest PC 0x0c037636 */
if(!s->budget--) { s->failed_pc=0x0c037636u; return 0; }
r[0]<<=2;
goto P_0c037638;
P_0c037638: /* original 037e, guest PC 0x0c037638 */
if(!s->budget--) { s->failed_pc=0x0c037638u; return 0; }
r[3]=read(ram,r[7]+r[0],4);
goto P_0c03763a;
P_0c03763a: /* original 3532, guest PC 0x0c03763a */
if(!s->budget--) { s->failed_pc=0x0c03763au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[3])!=0);
goto P_0c03763c;
P_0c03763c: /* original 8b02, guest PC 0x0c03763c */
if(!s->budget--) { s->failed_pc=0x0c03763cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037644; }
goto P_0c03763e;
P_0c03763e: /* original 7401, guest PC 0x0c03763e */
if(!s->budget--) { s->failed_pc=0x0c03763eu; return 0; }
r[4]+=0x00000001u;
goto P_0c037640;
P_0c037640: /* original 3462, guest PC 0x0c037640 */
if(!s->budget--) { s->failed_pc=0x0c037640u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c037642;
P_0c037642: /* original 8bf7, guest PC 0x0c037642 */
if(!s->budget--) { s->failed_pc=0x0c037642u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037634; }
goto P_0c037644;
P_0c037644: /* original 6043, guest PC 0x0c037644 */
if(!s->budget--) { s->failed_pc=0x0c037644u; return 0; }
r[0]=r[4];
goto P_0c037646;
P_0c037646: /* original 80e2, guest PC 0x0c037646 */
if(!s->budget--) { s->failed_pc=0x0c037646u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c037648;
P_0c037648: /* original d014, guest PC 0x0c037648 */
if(!s->budget--) { s->failed_pc=0x0c037648u; return 0; }
r[0]=read(ram,0x0c03769cu,4);
goto P_0c03764a;
P_0c03764a: /* original 74ff, guest PC 0x0c03764a */
if(!s->budget--) { s->failed_pc=0x0c03764au; return 0; }
r[4]+=0xffffffffu;
goto P_0c03764c;
P_0c03764c: /* original 4408, guest PC 0x0c03764c */
if(!s->budget--) { s->failed_pc=0x0c03764cu; return 0; }
r[4]<<=2;
goto P_0c03764e;
P_0c03764e: /* original 034e, guest PC 0x0c03764e */
if(!s->budget--) { s->failed_pc=0x0c03764eu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c037650;
P_0c037650: /* original 3538, guest PC 0x0c037650 */
if(!s->budget--) { s->failed_pc=0x0c037650u; return 0; }
r[5]-=r[3];
goto P_0c037652;
P_0c037652: /* original 6053, guest PC 0x0c037652 */
if(!s->budget--) { s->failed_pc=0x0c037652u; return 0; }
r[0]=r[5];
goto P_0c037654;
P_0c037654: /* original 7001, guest PC 0x0c037654 */
if(!s->budget--) { s->failed_pc=0x0c037654u; return 0; }
r[0]+=0x00000001u;
goto P_0c037656;
P_0c037656: /* original 80e3, guest PC 0x0c037656 */
if(!s->budget--) { s->failed_pc=0x0c037656u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c037658;
P_0c037658: /* original 61e1, guest PC 0x0c037658 */
if(!s->budget--) { s->failed_pc=0x0c037658u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c03765a;
P_0c03765a: /* original d30f, guest PC 0x0c03765a */
if(!s->budget--) { s->failed_pc=0x0c03765au; return 0; }
r[3]=read(ram,0x0c037698u,4);
goto P_0c03765c;
P_0c03765c: /* original 611d, guest PC 0x0c03765c */
if(!s->budget--) { s->failed_pc=0x0c03765cu; return 0; }
r[1]=r[1]&65535u;
goto P_0c03765e;
P_0c03765e: /* original 430b, guest PC 0x0c03765e */
if(!s->budget--) { s->failed_pc=0x0c03765eu; return 0; }
target=r[3];
r[16]=code_base|0x0c037662u;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037662u) { target=s->pc; goto dispatch; }
goto P_0c037662;
P_0c037660: /* original e004, guest PC 0x0c037660 */
if(!s->budget--) { s->failed_pc=0x0c037660u; return 0; }
r[0]=0x00000004u;
goto P_0c037662;
P_0c037662: /* original 2008, guest PC 0x0c037662 */
if(!s->budget--) { s->failed_pc=0x0c037662u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c037664;
P_0c037664: /* original 8b07, guest PC 0x0c037664 */
if(!s->budget--) { s->failed_pc=0x0c037664u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037676; }
goto P_0c037666;
P_0c037666: /* original 84e2, guest PC 0x0c037666 */
if(!s->budget--) { s->failed_pc=0x0c037666u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c037668;
P_0c037668: /* original e302, guest PC 0x0c037668 */
if(!s->budget--) { s->failed_pc=0x0c037668u; return 0; }
r[3]=0x00000002u;
goto P_0c03766a;
P_0c03766a: /* original 600c, guest PC 0x0c03766a */
if(!s->budget--) { s->failed_pc=0x0c03766au; return 0; }
r[0]=r[0]&255u;
goto P_0c03766c;
P_0c03766c: /* original 3037, guest PC 0x0c03766c */
if(!s->budget--) { s->failed_pc=0x0c03766cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[3])!=0);
goto P_0c03766e;
P_0c03766e: /* original 8b02, guest PC 0x0c03766e */
if(!s->budget--) { s->failed_pc=0x0c03766eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037676; }
goto P_0c037670;
P_0c037670: /* original 84e3, guest PC 0x0c037670 */
if(!s->budget--) { s->failed_pc=0x0c037670u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c037672;
P_0c037672: /* original 70ff, guest PC 0x0c037672 */
if(!s->budget--) { s->failed_pc=0x0c037672u; return 0; }
r[0]+=0xffffffffu;
goto P_0c037674;
P_0c037674: /* original 80e3, guest PC 0x0c037674 */
if(!s->budget--) { s->failed_pc=0x0c037674u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c037676;
P_0c037676: /* original 84e3, guest PC 0x0c037676 */
if(!s->budget--) { s->failed_pc=0x0c037676u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c037678;
P_0c037678: /* original 6603, guest PC 0x0c037678 */
if(!s->budget--) { s->failed_pc=0x0c037678u; return 0; }
r[6]=r[0];
goto P_0c03767a;
P_0c03767a: /* original 84e2, guest PC 0x0c03767a */
if(!s->budget--) { s->failed_pc=0x0c03767au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c03767c;
P_0c03767c: /* original 6503, guest PC 0x0c03767c */
if(!s->budget--) { s->failed_pc=0x0c03767cu; return 0; }
r[5]=r[0];
goto P_0c03767e;
P_0c03767e: /* original b00f, guest PC 0x0c03767e */
if(!s->budget--) { s->failed_pc=0x0c03767eu; return 0; }
target=0x0c0376a0u; r[16]=code_base|0x0c037682u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037682u) { target=s->pc; goto dispatch; }
goto P_0c037682;
P_0c037680: /* original 64e1, guest PC 0x0c037680 */
if(!s->budget--) { s->failed_pc=0x0c037680u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c037682;
P_0c037682: /* original 4f26, guest PC 0x0c037682 */
if(!s->budget--) { s->failed_pc=0x0c037682u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037684;
P_0c037684: /* original 80e7, guest PC 0x0c037684 */
if(!s->budget--) { s->failed_pc=0x0c037684u; return 0; }
write(ram,r[14]+7,r[0],1);
goto P_0c037686;
P_0c037686: /* original 000b, guest PC 0x0c037686 */
if(!s->budget--) { s->failed_pc=0x0c037686u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c037688: /* original 6ef6, guest PC 0x0c037688 */
if(!s->budget--) { s->failed_pc=0x0c037688u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03768au,s,ram);
P_0c04d020: /* original 4f22, guest PC 0x0c04d020 */
if(!s->budget--) { s->failed_pc=0x0c04d020u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d022;
P_0c04d022: /* original 4f12, guest PC 0x0c04d022 */
if(!s->budget--) { s->failed_pc=0x0c04d022u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d024;
P_0c04d024: /* original 7fe8, guest PC 0x0c04d024 */
if(!s->budget--) { s->failed_pc=0x0c04d024u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c04d026;
P_0c04d026: /* original 1f52, guest PC 0x0c04d026 */
if(!s->budget--) { s->failed_pc=0x0c04d026u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c04d028;
P_0c04d028: /* original 2f62, guest PC 0x0c04d028 */
if(!s->budget--) { s->failed_pc=0x0c04d028u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04d02a;
P_0c04d02a: /* original 1f71, guest PC 0x0c04d02a */
if(!s->budget--) { s->failed_pc=0x0c04d02au; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c04d02c;
P_0c04d02c: /* original 9a26, guest PC 0x0c04d02c */
if(!s->budget--) { s->failed_pc=0x0c04d02cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d07cu,2);
goto P_0c04d02e;
P_0c04d02e: /* original db15, guest PC 0x0c04d02e */
if(!s->budget--) { s->failed_pc=0x0c04d02eu; return 0; }
r[11]=read(ram,0x0c04d084u,4);
goto P_0c04d030;
P_0c04d030: /* original 2daf, guest PC 0x0c04d030 */
if(!s->budget--) { s->failed_pc=0x0c04d030u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[10]);
goto P_0c04d032;
P_0c04d032: /* original 2fd6, guest PC 0x0c04d032 */
if(!s->budget--) { s->failed_pc=0x0c04d032u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d034;
P_0c04d034: /* original d317, guest PC 0x0c04d034 */
if(!s->budget--) { s->failed_pc=0x0c04d034u; return 0; }
r[3]=read(ram,0x0c04d094u,4);
goto P_0c04d036;
P_0c04d036: /* original 0a1a, guest PC 0x0c04d036 */
if(!s->budget--) { s->failed_pc=0x0c04d036u; return 0; }
r[10]=r[19];
goto P_0c04d038;
P_0c04d038: /* original 6aaf, guest PC 0x0c04d038 */
if(!s->budget--) { s->failed_pc=0x0c04d038u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c04d03a;
P_0c04d03a: /* original 6ea3, guest PC 0x0c04d03a */
if(!s->budget--) { s->failed_pc=0x0c04d03au; return 0; }
r[14]=r[10];
goto P_0c04d03c;
P_0c04d03c: /* original 3ebc, guest PC 0x0c04d03c */
if(!s->budget--) { s->failed_pc=0x0c04d03cu; return 0; }
r[14]+=r[11];
goto P_0c04d03e;
P_0c04d03e: /* original baaf, guest PC 0x0c04d03e */
if(!s->budget--) { s->failed_pc=0x0c04d03eu; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d042u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d042u) { target=s->pc; goto dispatch; }
goto P_0c04d042;
P_0c04d040: /* original 2f36, guest PC 0x0c04d040 */
if(!s->budget--) { s->failed_pc=0x0c04d040u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d042;
P_0c04d042: /* original 84e2, guest PC 0x0c04d042 */
if(!s->budget--) { s->failed_pc=0x0c04d042u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04d044;
P_0c04d044: /* original 2008, guest PC 0x0c04d044 */
if(!s->budget--) { s->failed_pc=0x0c04d044u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d046;
P_0c04d046: /* original 8f02, guest PC 0x0c04d046 */
if(!s->budget--) { s->failed_pc=0x0c04d046u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(!cond) { goto P_0c04d04e; }
goto P_0c04d04a;
P_0c04d048: /* original 7f08, guest PC 0x0c04d048 */
if(!s->budget--) { s->failed_pc=0x0c04d048u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d04a;
P_0c04d04a: /* original a173, guest PC 0x0c04d04a */
if(!s->budget--) { s->failed_pc=0x0c04d04au; return 0; }
goto P_0c04d334;
P_0c04d04c: /* original 0009, guest PC 0x0c04d04c */
if(!s->budget--) { s->failed_pc=0x0c04d04cu; return 0; }
goto P_0c04d04e;
P_0c04d04e: /* original 53ff, guest PC 0x0c04d04e */
if(!s->budget--) { s->failed_pc=0x0c04d04eu; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c04d050;
P_0c04d050: /* original e501, guest PC 0x0c04d050 */
if(!s->budget--) { s->failed_pc=0x0c04d050u; return 0; }
r[5]=0x00000001u;
goto P_0c04d052;
P_0c04d052: /* original d411, guest PC 0x0c04d052 */
if(!s->budget--) { s->failed_pc=0x0c04d052u; return 0; }
r[4]=read(ram,0x0c04d098u,4);
goto P_0c04d054;
P_0c04d054: /* original 6ca3, guest PC 0x0c04d054 */
if(!s->budget--) { s->failed_pc=0x0c04d054u; return 0; }
r[12]=r[10];
goto P_0c04d056;
P_0c04d056: /* original 2338, guest PC 0x0c04d056 */
if(!s->budget--) { s->failed_pc=0x0c04d056u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04d058;
P_0c04d058: /* original 8d20, guest PC 0x0c04d058 */
if(!s->budget--) { s->failed_pc=0x0c04d058u; return 0; }
cond=r[17]&1u;
r[12]+=r[11];
if(cond) { goto P_0c04d09c; }
goto P_0c04d05c;
P_0c04d05a: /* original 3cbc, guest PC 0x0c04d05a */
if(!s->budget--) { s->failed_pc=0x0c04d05au; return 0; }
r[12]+=r[11];
goto P_0c04d05c;
P_0c04d05c: /* original 1c5c, guest PC 0x0c04d05c */
if(!s->budget--) { s->failed_pc=0x0c04d05cu; return 0; }
write(ram,r[12]+48,r[5],4);
goto P_0c04d05e;
P_0c04d05e: /* original 53c1, guest PC 0x0c04d05e */
if(!s->budget--) { s->failed_pc=0x0c04d05eu; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c04d060;
P_0c04d060: /* original 6233, guest PC 0x0c04d060 */
if(!s->budget--) { s->failed_pc=0x0c04d060u; return 0; }
r[2]=r[3];
goto P_0c04d062;
P_0c04d062: /* original 4308, guest PC 0x0c04d062 */
if(!s->budget--) { s->failed_pc=0x0c04d062u; return 0; }
r[3]<<=2;
goto P_0c04d064;
P_0c04d064: /* original 332c, guest PC 0x0c04d064 */
if(!s->budget--) { s->failed_pc=0x0c04d064u; return 0; }
r[3]+=r[2];
goto P_0c04d066;
P_0c04d066: /* original 4308, guest PC 0x0c04d066 */
if(!s->budget--) { s->failed_pc=0x0c04d066u; return 0; }
r[3]<<=2;
goto P_0c04d068;
P_0c04d068: /* original 4308, guest PC 0x0c04d068 */
if(!s->budget--) { s->failed_pc=0x0c04d068u; return 0; }
r[3]<<=2;
goto P_0c04d06a;
P_0c04d06a: /* original 633f, guest PC 0x0c04d06a */
if(!s->budget--) { s->failed_pc=0x0c04d06au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04d06c;
P_0c04d06c: /* original 343c, guest PC 0x0c04d06c */
if(!s->budget--) { s->failed_pc=0x0c04d06cu; return 0; }
r[4]+=r[3];
goto P_0c04d06e;
P_0c04d06e: /* original 5343, guest PC 0x0c04d06e */
if(!s->budget--) { s->failed_pc=0x0c04d06eu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c04d070;
P_0c04d070: /* original a022, guest PC 0x0c04d070 */
if(!s->budget--) { s->failed_pc=0x0c04d070u; return 0; }
write(ram,r[12]+52,r[3],4);
goto P_0c04d0b8;
P_0c04d072: /* original 1c3d, guest PC 0x0c04d072 */
if(!s->budget--) { s->failed_pc=0x0c04d072u; return 0; }
write(ram,r[12]+52,r[3],4);
return vf3_matrix_family(0x0c04d074u,s,ram);
P_0c04d09c: /* original 1c5c, guest PC 0x0c04d09c */
if(!s->budget--) { s->failed_pc=0x0c04d09cu; return 0; }
write(ram,r[12]+48,r[5],4);
goto P_0c04d09e;
P_0c04d09e: /* original 51c1, guest PC 0x0c04d09e */
if(!s->budget--) { s->failed_pc=0x0c04d09eu; return 0; }
r[1]=read(ram,r[12]+4,4);
goto P_0c04d0a0;
P_0c04d0a0: /* original d236, guest PC 0x0c04d0a0 */
if(!s->budget--) { s->failed_pc=0x0c04d0a0u; return 0; }
r[2]=read(ram,0x0c04d17cu,4);
goto P_0c04d0a2;
P_0c04d0a2: /* original 6313, guest PC 0x0c04d0a2 */
if(!s->budget--) { s->failed_pc=0x0c04d0a2u; return 0; }
r[3]=r[1];
goto P_0c04d0a4;
P_0c04d0a4: /* original 4108, guest PC 0x0c04d0a4 */
if(!s->budget--) { s->failed_pc=0x0c04d0a4u; return 0; }
r[1]<<=2;
goto P_0c04d0a6;
P_0c04d0a6: /* original 313c, guest PC 0x0c04d0a6 */
if(!s->budget--) { s->failed_pc=0x0c04d0a6u; return 0; }
r[1]+=r[3];
goto P_0c04d0a8;
P_0c04d0a8: /* original 4108, guest PC 0x0c04d0a8 */
if(!s->budget--) { s->failed_pc=0x0c04d0a8u; return 0; }
r[1]<<=2;
goto P_0c04d0aa;
P_0c04d0aa: /* original 4108, guest PC 0x0c04d0aa */
if(!s->budget--) { s->failed_pc=0x0c04d0aau; return 0; }
r[1]<<=2;
goto P_0c04d0ac;
P_0c04d0ac: /* original 611f, guest PC 0x0c04d0ac */
if(!s->budget--) { s->failed_pc=0x0c04d0acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04d0ae;
P_0c04d0ae: /* original 314c, guest PC 0x0c04d0ae */
if(!s->budget--) { s->failed_pc=0x0c04d0aeu; return 0; }
r[1]+=r[4];
goto P_0c04d0b0;
P_0c04d0b0: /* original 5113, guest PC 0x0c04d0b0 */
if(!s->budget--) { s->failed_pc=0x0c04d0b0u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c04d0b2;
P_0c04d0b2: /* original 420b, guest PC 0x0c04d0b2 */
if(!s->budget--) { s->failed_pc=0x0c04d0b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d0b6u;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d0b6u) { target=s->pc; goto dispatch; }
goto P_0c04d0b6;
P_0c04d0b4: /* original e00a, guest PC 0x0c04d0b4 */
if(!s->budget--) { s->failed_pc=0x0c04d0b4u; return 0; }
r[0]=0x0000000au;
goto P_0c04d0b6;
P_0c04d0b6: /* original 1c0d, guest PC 0x0c04d0b6 */
if(!s->budget--) { s->failed_pc=0x0c04d0b6u; return 0; }
write(ram,r[12]+52,r[0],4);
goto P_0c04d0b8;
P_0c04d0b8: /* original d331, guest PC 0x0c04d0b8 */
if(!s->budget--) { s->failed_pc=0x0c04d0b8u; return 0; }
r[3]=read(ram,0x0c04d180u,4);
goto P_0c04d0ba;
P_0c04d0ba: /* original 430b, guest PC 0x0c04d0ba */
if(!s->budget--) { s->failed_pc=0x0c04d0bau; return 0; }
target=r[3];
r[16]=code_base|0x0c04d0beu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d0beu) { target=s->pc; goto dispatch; }
goto P_0c04d0be;
P_0c04d0bc: /* original 64d3, guest PC 0x0c04d0bc */
if(!s->budget--) { s->failed_pc=0x0c04d0bcu; return 0; }
r[4]=r[13];
goto P_0c04d0be;
P_0c04d0be: /* original 2008, guest PC 0x0c04d0be */
if(!s->budget--) { s->failed_pc=0x0c04d0beu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d0c0;
P_0c04d0c0: /* original 8b01, guest PC 0x0c04d0c0 */
if(!s->budget--) { s->failed_pc=0x0c04d0c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d0c6; }
goto P_0c04d0c2;
P_0c04d0c2: /* original a137, guest PC 0x0c04d0c2 */
if(!s->budget--) { s->failed_pc=0x0c04d0c2u; return 0; }
goto P_0c04d334;
P_0c04d0c4: /* original 0009, guest PC 0x0c04d0c4 */
if(!s->budget--) { s->failed_pc=0x0c04d0c4u; return 0; }
goto P_0c04d0c6;
P_0c04d0c6: /* original 3abc, guest PC 0x0c04d0c6 */
if(!s->budget--) { s->failed_pc=0x0c04d0c6u; return 0; }
r[10]+=r[11];
goto P_0c04d0c8;
P_0c04d0c8: /* original 84a8, guest PC 0x0c04d0c8 */
if(!s->budget--) { s->failed_pc=0x0c04d0c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+8,1);
goto P_0c04d0ca;
P_0c04d0ca: /* original 2008, guest PC 0x0c04d0ca */
if(!s->budget--) { s->failed_pc=0x0c04d0cau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d0cc;
P_0c04d0cc: /* original 8b01, guest PC 0x0c04d0cc */
if(!s->budget--) { s->failed_pc=0x0c04d0ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d0d2; }
goto P_0c04d0ce;
P_0c04d0ce: /* original a131, guest PC 0x0c04d0ce */
if(!s->budget--) { s->failed_pc=0x0c04d0ceu; return 0; }
goto P_0c04d334;
P_0c04d0d0: /* original 0009, guest PC 0x0c04d0d0 */
if(!s->budget--) { s->failed_pc=0x0c04d0d0u; return 0; }
goto P_0c04d0d2;
P_0c04d0d2: /* original 69d3, guest PC 0x0c04d0d2 */
if(!s->budget--) { s->failed_pc=0x0c04d0d2u; return 0; }
r[9]=r[13];
goto P_0c04d0d4;
P_0c04d0d4: /* original d32b, guest PC 0x0c04d0d4 */
if(!s->budget--) { s->failed_pc=0x0c04d0d4u; return 0; }
r[3]=read(ram,0x0c04d184u,4);
goto P_0c04d0d6;
P_0c04d0d6: /* original 4918, guest PC 0x0c04d0d6 */
if(!s->budget--) { s->failed_pc=0x0c04d0d6u; return 0; }
r[9]<<=8;
goto P_0c04d0d8;
P_0c04d0d8: /* original da2b, guest PC 0x0c04d0d8 */
if(!s->budget--) { s->failed_pc=0x0c04d0d8u; return 0; }
r[10]=read(ram,0x0c04d188u,4);
goto P_0c04d0da;
P_0c04d0da: /* original 964c, guest PC 0x0c04d0da */
if(!s->budget--) { s->failed_pc=0x0c04d0dau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d176u,2);
goto P_0c04d0dc;
P_0c04d0dc: /* original 4900, guest PC 0x0c04d0dc */
if(!s->budget--) { s->failed_pc=0x0c04d0dcu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c04d0de;
P_0c04d0de: /* original e500, guest PC 0x0c04d0de */
if(!s->budget--) { s->failed_pc=0x0c04d0deu; return 0; }
r[5]=0x00000000u;
goto P_0c04d0e0;
P_0c04d0e0: /* original 393c, guest PC 0x0c04d0e0 */
if(!s->budget--) { s->failed_pc=0x0c04d0e0u; return 0; }
r[9]+=r[3];
goto P_0c04d0e2;
P_0c04d0e2: /* original 4a0b, guest PC 0x0c04d0e2 */
if(!s->budget--) { s->failed_pc=0x0c04d0e2u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d0e6u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d0e6u) { target=s->pc; goto dispatch; }
goto P_0c04d0e6;
P_0c04d0e4: /* original 54e8, guest PC 0x0c04d0e4 */
if(!s->budget--) { s->failed_pc=0x0c04d0e4u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d0e6;
P_0c04d0e6: /* original d229, guest PC 0x0c04d0e6 */
if(!s->budget--) { s->failed_pc=0x0c04d0e6u; return 0; }
r[2]=read(ram,0x0c04d18cu,4);
goto P_0c04d0e8;
P_0c04d0e8: /* original ba5a, guest PC 0x0c04d0e8 */
if(!s->budget--) { s->failed_pc=0x0c04d0e8u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d0ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d0ecu) { target=s->pc; goto dispatch; }
goto P_0c04d0ec;
P_0c04d0ea: /* original 2f26, guest PC 0x0c04d0ea */
if(!s->budget--) { s->failed_pc=0x0c04d0eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d0ec;
P_0c04d0ec: /* original 55e7, guest PC 0x0c04d0ec */
if(!s->budget--) { s->failed_pc=0x0c04d0ecu; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d0ee;
P_0c04d0ee: /* original 7f04, guest PC 0x0c04d0ee */
if(!s->budget--) { s->failed_pc=0x0c04d0eeu; return 0; }
r[15]+=0x00000004u;
goto P_0c04d0f0;
P_0c04d0f0: /* original 56e8, guest PC 0x0c04d0f0 */
if(!s->budget--) { s->failed_pc=0x0c04d0f0u; return 0; }
r[6]=read(ram,r[14]+32,4);
goto P_0c04d0f2;
P_0c04d0f2: /* original 5552, guest PC 0x0c04d0f2 */
if(!s->budget--) { s->failed_pc=0x0c04d0f2u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04d0f4;
P_0c04d0f4: /* original d826, guest PC 0x0c04d0f4 */
if(!s->budget--) { s->failed_pc=0x0c04d0f4u; return 0; }
r[8]=read(ram,0x0c04d190u,4);
goto P_0c04d0f6;
P_0c04d0f6: /* original 480b, guest PC 0x0c04d0f6 */
if(!s->budget--) { s->failed_pc=0x0c04d0f6u; return 0; }
target=r[8];
r[16]=code_base|0x0c04d0fau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d0fau) { target=s->pc; goto dispatch; }
goto P_0c04d0fa;
P_0c04d0f8: /* original 64d3, guest PC 0x0c04d0f8 */
if(!s->budget--) { s->failed_pc=0x0c04d0f8u; return 0; }
r[4]=r[13];
goto P_0c04d0fa;
P_0c04d0fa: /* original 6403, guest PC 0x0c04d0fa */
if(!s->budget--) { s->failed_pc=0x0c04d0fau; return 0; }
r[4]=r[0];
goto P_0c04d0fc;
P_0c04d0fc: /* original 4411, guest PC 0x0c04d0fc */
if(!s->budget--) { s->failed_pc=0x0c04d0fcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04d0fe;
P_0c04d0fe: /* original 8906, guest PC 0x0c04d0fe */
if(!s->budget--) { s->failed_pc=0x0c04d0feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d10e; }
goto P_0c04d100;
P_0c04d100: /* original 923a, guest PC 0x0c04d100 */
if(!s->budget--) { s->failed_pc=0x0c04d100u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d178u,2);
goto P_0c04d102;
P_0c04d102: /* original 3420, guest PC 0x0c04d102 */
if(!s->budget--) { s->failed_pc=0x0c04d102u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c04d104;
P_0c04d104: /* original 8901, guest PC 0x0c04d104 */
if(!s->budget--) { s->failed_pc=0x0c04d104u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d10a; }
goto P_0c04d106;
P_0c04d106: /* original a115, guest PC 0x0c04d106 */
if(!s->budget--) { s->failed_pc=0x0c04d106u; return 0; }
goto P_0c04d334;
P_0c04d108: /* original 0009, guest PC 0x0c04d108 */
if(!s->budget--) { s->failed_pc=0x0c04d108u; return 0; }
goto P_0c04d10a;
P_0c04d10a: /* original a17a, guest PC 0x0c04d10a */
if(!s->budget--) { s->failed_pc=0x0c04d10au; return 0; }
r[0]=0xffffff81u;
goto P_0c04d402;
P_0c04d10c: /* original e081, guest PC 0x0c04d10c */
if(!s->budget--) { s->failed_pc=0x0c04d10cu; return 0; }
r[0]=0xffffff81u;
goto P_0c04d10e;
P_0c04d10e: /* original d321, guest PC 0x0c04d10e */
if(!s->budget--) { s->failed_pc=0x0c04d10eu; return 0; }
r[3]=read(ram,0x0c04d194u,4);
goto P_0c04d110;
P_0c04d110: /* original 55e7, guest PC 0x0c04d110 */
if(!s->budget--) { s->failed_pc=0x0c04d110u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d112;
P_0c04d112: /* original 430b, guest PC 0x0c04d112 */
if(!s->budget--) { s->failed_pc=0x0c04d112u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d116u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d116u) { target=s->pc; goto dispatch; }
goto P_0c04d116;
P_0c04d114: /* original 64d3, guest PC 0x0c04d114 */
if(!s->budget--) { s->failed_pc=0x0c04d114u; return 0; }
r[4]=r[13];
goto P_0c04d116;
P_0c04d116: /* original 4011, guest PC 0x0c04d116 */
if(!s->budget--) { s->failed_pc=0x0c04d116u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d118;
P_0c04d118: /* original 8901, guest PC 0x0c04d118 */
if(!s->budget--) { s->failed_pc=0x0c04d118u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d11e; }
goto P_0c04d11a;
P_0c04d11a: /* original a10b, guest PC 0x0c04d11a */
if(!s->budget--) { s->failed_pc=0x0c04d11au; return 0; }
goto P_0c04d334;
P_0c04d11c: /* original 0009, guest PC 0x0c04d11c */
if(!s->budget--) { s->failed_pc=0x0c04d11cu; return 0; }
goto P_0c04d11e;
P_0c04d11e: /* original d31e, guest PC 0x0c04d11e */
if(!s->budget--) { s->failed_pc=0x0c04d11eu; return 0; }
r[3]=read(ram,0x0c04d198u,4);
goto P_0c04d120;
P_0c04d120: /* original 430b, guest PC 0x0c04d120 */
if(!s->budget--) { s->failed_pc=0x0c04d120u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d124u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d124u) { target=s->pc; goto dispatch; }
goto P_0c04d124;
P_0c04d122: /* original 64e3, guest PC 0x0c04d122 */
if(!s->budget--) { s->failed_pc=0x0c04d122u; return 0; }
r[4]=r[14];
goto P_0c04d124;
P_0c04d124: /* original 4011, guest PC 0x0c04d124 */
if(!s->budget--) { s->failed_pc=0x0c04d124u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d126;
P_0c04d126: /* original 8901, guest PC 0x0c04d126 */
if(!s->budget--) { s->failed_pc=0x0c04d126u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d12c; }
goto P_0c04d128;
P_0c04d128: /* original a16b, guest PC 0x0c04d128 */
if(!s->budget--) { s->failed_pc=0x0c04d128u; return 0; }
r[0]=0xffffff83u;
goto P_0c04d402;
P_0c04d12a: /* original e083, guest PC 0x0c04d12a */
if(!s->budget--) { s->failed_pc=0x0c04d12au; return 0; }
r[0]=0xffffff83u;
goto P_0c04d12c;
P_0c04d12c: /* original 54e7, guest PC 0x0c04d12c */
if(!s->budget--) { s->failed_pc=0x0c04d12cu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c04d12e;
P_0c04d12e: /* original e500, guest PC 0x0c04d12e */
if(!s->budget--) { s->failed_pc=0x0c04d12eu; return 0; }
r[5]=0x00000000u;
goto P_0c04d130;
P_0c04d130: /* original 5347, guest PC 0x0c04d130 */
if(!s->budget--) { s->failed_pc=0x0c04d130u; return 0; }
r[3]=read(ram,r[4]+28,4);
goto P_0c04d132;
P_0c04d132: /* original 143c, guest PC 0x0c04d132 */
if(!s->budget--) { s->failed_pc=0x0c04d132u; return 0; }
write(ram,r[4]+48,r[3],4);
goto P_0c04d134;
P_0c04d134: /* original 961f, guest PC 0x0c04d134 */
if(!s->budget--) { s->failed_pc=0x0c04d134u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d176u,2);
goto P_0c04d136;
P_0c04d136: /* original 4a0b, guest PC 0x0c04d136 */
if(!s->budget--) { s->failed_pc=0x0c04d136u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d13au;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d13au) { target=s->pc; goto dispatch; }
goto P_0c04d13a;
P_0c04d138: /* original 54e8, guest PC 0x0c04d138 */
if(!s->budget--) { s->failed_pc=0x0c04d138u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d13a;
P_0c04d13a: /* original 54e8, guest PC 0x0c04d13a */
if(!s->budget--) { s->failed_pc=0x0c04d13au; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d13c;
P_0c04d13c: /* original e620, guest PC 0x0c04d13c */
if(!s->budget--) { s->failed_pc=0x0c04d13cu; return 0; }
r[6]=0x00000020u;
goto P_0c04d13e;
P_0c04d13e: /* original 6563, guest PC 0x0c04d13e */
if(!s->budget--) { s->failed_pc=0x0c04d13eu; return 0; }
r[5]=r[6];
goto P_0c04d140;
P_0c04d140: /* original 4a0b, guest PC 0x0c04d140 */
if(!s->budget--) { s->failed_pc=0x0c04d140u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d144u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d144u) { target=s->pc; goto dispatch; }
goto P_0c04d144;
P_0c04d142: /* original 7410, guest PC 0x0c04d142 */
if(!s->budget--) { s->failed_pc=0x0c04d142u; return 0; }
r[4]+=0x00000010u;
goto P_0c04d144;
P_0c04d144: /* original 55f2, guest PC 0x0c04d144 */
if(!s->budget--) { s->failed_pc=0x0c04d144u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c04d146;
P_0c04d146: /* original e400, guest PC 0x0c04d146 */
if(!s->budget--) { s->failed_pc=0x0c04d146u; return 0; }
r[4]=0x00000000u;
goto P_0c04d148;
P_0c04d148: /* original a006, guest PC 0x0c04d148 */
if(!s->budget--) { s->failed_pc=0x0c04d148u; return 0; }
r[6]=0x00000020u;
goto P_0c04d158;
P_0c04d14a: /* original e620, guest PC 0x0c04d14a */
if(!s->budget--) { s->failed_pc=0x0c04d14au; return 0; }
r[6]=0x00000020u;
goto P_0c04d14c;
P_0c04d14c: /* original 50e8, guest PC 0x0c04d14c */
if(!s->budget--) { s->failed_pc=0x0c04d14cu; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c04d14e;
P_0c04d14e: /* original 6243, guest PC 0x0c04d14e */
if(!s->budget--) { s->failed_pc=0x0c04d14eu; return 0; }
r[2]=r[4];
goto P_0c04d150;
P_0c04d150: /* original 6354, guest PC 0x0c04d150 */
if(!s->budget--) { s->failed_pc=0x0c04d150u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04d152;
P_0c04d152: /* original 7210, guest PC 0x0c04d152 */
if(!s->budget--) { s->failed_pc=0x0c04d152u; return 0; }
r[2]+=0x00000010u;
goto P_0c04d154;
P_0c04d154: /* original 7401, guest PC 0x0c04d154 */
if(!s->budget--) { s->failed_pc=0x0c04d154u; return 0; }
r[4]+=0x00000001u;
goto P_0c04d156;
P_0c04d156: /* original 0234, guest PC 0x0c04d156 */
if(!s->budget--) { s->failed_pc=0x0c04d156u; return 0; }
write(ram,r[2]+r[0],r[3],1);
goto P_0c04d158;
P_0c04d158: /* original 3463, guest PC 0x0c04d158 */
if(!s->budget--) { s->failed_pc=0x0c04d158u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c04d15a;
P_0c04d15a: /* original 8bf7, guest PC 0x0c04d15a */
if(!s->budget--) { s->failed_pc=0x0c04d15au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d14c; }
goto P_0c04d15c;
P_0c04d15c: /* original d30f, guest PC 0x0c04d15c */
if(!s->budget--) { s->failed_pc=0x0c04d15cu; return 0; }
r[3]=read(ram,0x0c04d19cu,4);
goto P_0c04d15e;
P_0c04d15e: /* original 64f3, guest PC 0x0c04d15e */
if(!s->budget--) { s->failed_pc=0x0c04d15eu; return 0; }
r[4]=r[15];
goto P_0c04d160;
P_0c04d160: /* original 55f1, guest PC 0x0c04d160 */
if(!s->budget--) { s->failed_pc=0x0c04d160u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c04d162;
P_0c04d162: /* original 430b, guest PC 0x0c04d162 */
if(!s->budget--) { s->failed_pc=0x0c04d162u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d166u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d166u) { target=s->pc; goto dispatch; }
goto P_0c04d166;
P_0c04d164: /* original 7410, guest PC 0x0c04d164 */
if(!s->budget--) { s->failed_pc=0x0c04d164u; return 0; }
r[4]+=0x00000010u;
goto P_0c04d166;
P_0c04d166: /* original 54e8, guest PC 0x0c04d166 */
if(!s->budget--) { s->failed_pc=0x0c04d166u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d168;
P_0c04d168: /* original 67f3, guest PC 0x0c04d168 */
if(!s->budget--) { s->failed_pc=0x0c04d168u; return 0; }
r[7]=r[15];
goto P_0c04d16a;
P_0c04d16a: /* original ec00, guest PC 0x0c04d16a */
if(!s->budget--) { s->failed_pc=0x0c04d16au; return 0; }
r[12]=0x00000000u;
goto P_0c04d16c;
P_0c04d16c: /* original 7430, guest PC 0x0c04d16c */
if(!s->budget--) { s->failed_pc=0x0c04d16cu; return 0; }
r[4]+=0x00000030u;
goto P_0c04d16e;
P_0c04d16e: /* original 65c3, guest PC 0x0c04d16e */
if(!s->budget--) { s->failed_pc=0x0c04d16eu; return 0; }
r[5]=r[12];
goto P_0c04d170;
P_0c04d170: /* original 7710, guest PC 0x0c04d170 */
if(!s->budget--) { s->failed_pc=0x0c04d170u; return 0; }
r[7]+=0x00000010u;
goto P_0c04d172;
P_0c04d172: /* original a019, guest PC 0x0c04d172 */
if(!s->budget--) { s->failed_pc=0x0c04d172u; return 0; }
r[6]=0x00000008u;
goto P_0c04d1a8;
P_0c04d174: /* original e608, guest PC 0x0c04d174 */
if(!s->budget--) { s->failed_pc=0x0c04d174u; return 0; }
r[6]=0x00000008u;
return vf3_matrix_family(0x0c04d176u,s,ram);
P_0c04d1a0: /* original 6374, guest PC 0x0c04d1a0 */
if(!s->budget--) { s->failed_pc=0x0c04d1a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04d1a2;
P_0c04d1a2: /* original 7501, guest PC 0x0c04d1a2 */
if(!s->budget--) { s->failed_pc=0x0c04d1a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c04d1a4;
P_0c04d1a4: /* original 2430, guest PC 0x0c04d1a4 */
if(!s->budget--) { s->failed_pc=0x0c04d1a4u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04d1a6;
P_0c04d1a6: /* original 7401, guest PC 0x0c04d1a6 */
if(!s->budget--) { s->failed_pc=0x0c04d1a6u; return 0; }
r[4]+=0x00000001u;
goto P_0c04d1a8;
P_0c04d1a8: /* original 3563, guest PC 0x0c04d1a8 */
if(!s->budget--) { s->failed_pc=0x0c04d1a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04d1aa;
P_0c04d1aa: /* original 8bf9, guest PC 0x0c04d1aa */
if(!s->budget--) { s->failed_pc=0x0c04d1aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d1a0; }
goto P_0c04d1ac;
P_0c04d1ac: /* original 53e7, guest PC 0x0c04d1ac */
if(!s->budget--) { s->failed_pc=0x0c04d1acu; return 0; }
r[3]=read(ram,r[14]+28,4);
goto P_0c04d1ae;
P_0c04d1ae: /* original e542, guest PC 0x0c04d1ae */
if(!s->budget--) { s->failed_pc=0x0c04d1aeu; return 0; }
r[5]=0x00000042u;
goto P_0c04d1b0;
P_0c04d1b0: /* original 1f31, guest PC 0x0c04d1b0 */
if(!s->budget--) { s->failed_pc=0x0c04d1b0u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04d1b2;
P_0c04d1b2: /* original 5233, guest PC 0x0c04d1b2 */
if(!s->budget--) { s->failed_pc=0x0c04d1b2u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04d1b4;
P_0c04d1b4: /* original 1f22, guest PC 0x0c04d1b4 */
if(!s->budget--) { s->failed_pc=0x0c04d1b4u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c04d1b6;
P_0c04d1b6: /* original 53f1, guest PC 0x0c04d1b6 */
if(!s->budget--) { s->failed_pc=0x0c04d1b6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04d1b8;
P_0c04d1b8: /* original 5235, guest PC 0x0c04d1b8 */
if(!s->budget--) { s->failed_pc=0x0c04d1b8u; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c04d1ba;
P_0c04d1ba: /* original 1f23, guest PC 0x0c04d1ba */
if(!s->budget--) { s->failed_pc=0x0c04d1bau; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c04d1bc;
P_0c04d1bc: /* original db4d, guest PC 0x0c04d1bc */
if(!s->budget--) { s->failed_pc=0x0c04d1bcu; return 0; }
r[11]=read(ram,0x0c04d2f4u,4);
goto P_0c04d1be;
P_0c04d1be: /* original 56f1, guest PC 0x0c04d1be */
if(!s->budget--) { s->failed_pc=0x0c04d1beu; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c04d1c0;
P_0c04d1c0: /* original 63b2, guest PC 0x0c04d1c0 */
if(!s->budget--) { s->failed_pc=0x0c04d1c0u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d1c2;
P_0c04d1c2: /* original 5661, guest PC 0x0c04d1c2 */
if(!s->budget--) { s->failed_pc=0x0c04d1c2u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c04d1c4;
P_0c04d1c4: /* original 5234, guest PC 0x0c04d1c4 */
if(!s->budget--) { s->failed_pc=0x0c04d1c4u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d1c6;
P_0c04d1c6: /* original 420b, guest PC 0x0c04d1c6 */
if(!s->budget--) { s->failed_pc=0x0c04d1c6u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d1cau;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d1cau) { target=s->pc; goto dispatch; }
goto P_0c04d1ca;
P_0c04d1c8: /* original 54e8, guest PC 0x0c04d1c8 */
if(!s->budget--) { s->failed_pc=0x0c04d1c8u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d1ca;
P_0c04d1ca: /* original 62f2, guest PC 0x0c04d1ca */
if(!s->budget--) { s->failed_pc=0x0c04d1cau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04d1cc;
P_0c04d1cc: /* original e04e, guest PC 0x0c04d1cc */
if(!s->budget--) { s->failed_pc=0x0c04d1ccu; return 0; }
r[0]=0x0000004eu;
goto P_0c04d1ce;
P_0c04d1ce: /* original 53e8, guest PC 0x0c04d1ce */
if(!s->budget--) { s->failed_pc=0x0c04d1ceu; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c04d1d0;
P_0c04d1d0: /* original e540, guest PC 0x0c04d1d0 */
if(!s->budget--) { s->failed_pc=0x0c04d1d0u; return 0; }
r[5]=0x00000040u;
goto P_0c04d1d2;
P_0c04d1d2: /* original 0324, guest PC 0x0c04d1d2 */
if(!s->budget--) { s->failed_pc=0x0c04d1d2u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c04d1d4;
P_0c04d1d4: /* original e04f, guest PC 0x0c04d1d4 */
if(!s->budget--) { s->failed_pc=0x0c04d1d4u; return 0; }
r[0]=0x0000004fu;
goto P_0c04d1d6;
P_0c04d1d6: /* original 53e8, guest PC 0x0c04d1d6 */
if(!s->budget--) { s->failed_pc=0x0c04d1d6u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c04d1d8;
P_0c04d1d8: /* original 03c4, guest PC 0x0c04d1d8 */
if(!s->budget--) { s->failed_pc=0x0c04d1d8u; return 0; }
write(ram,r[3]+r[0],r[12],1);
goto P_0c04d1da;
P_0c04d1da: /* original 56e7, guest PC 0x0c04d1da */
if(!s->budget--) { s->failed_pc=0x0c04d1dau; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d1dc;
P_0c04d1dc: /* original 63b2, guest PC 0x0c04d1dc */
if(!s->budget--) { s->failed_pc=0x0c04d1dcu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d1de;
P_0c04d1de: /* original 6662, guest PC 0x0c04d1de */
if(!s->budget--) { s->failed_pc=0x0c04d1deu; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c04d1e0;
P_0c04d1e0: /* original 5234, guest PC 0x0c04d1e0 */
if(!s->budget--) { s->failed_pc=0x0c04d1e0u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d1e2;
P_0c04d1e2: /* original 420b, guest PC 0x0c04d1e2 */
if(!s->budget--) { s->failed_pc=0x0c04d1e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d1e6u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d1e6u) { target=s->pc; goto dispatch; }
goto P_0c04d1e6;
P_0c04d1e4: /* original 54e8, guest PC 0x0c04d1e4 */
if(!s->budget--) { s->failed_pc=0x0c04d1e4u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d1e6;
P_0c04d1e6: /* original 63b2, guest PC 0x0c04d1e6 */
if(!s->budget--) { s->failed_pc=0x0c04d1e6u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d1e8;
P_0c04d1e8: /* original e54a, guest PC 0x0c04d1e8 */
if(!s->budget--) { s->failed_pc=0x0c04d1e8u; return 0; }
r[5]=0x0000004au;
goto P_0c04d1ea;
P_0c04d1ea: /* original 56f3, guest PC 0x0c04d1ea */
if(!s->budget--) { s->failed_pc=0x0c04d1eau; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c04d1ec;
P_0c04d1ec: /* original 5234, guest PC 0x0c04d1ec */
if(!s->budget--) { s->failed_pc=0x0c04d1ecu; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d1ee;
P_0c04d1ee: /* original 420b, guest PC 0x0c04d1ee */
if(!s->budget--) { s->failed_pc=0x0c04d1eeu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d1f2u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d1f2u) { target=s->pc; goto dispatch; }
goto P_0c04d1f2;
P_0c04d1f0: /* original 54e8, guest PC 0x0c04d1f0 */
if(!s->budget--) { s->failed_pc=0x0c04d1f0u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d1f2;
P_0c04d1f2: /* original 63b2, guest PC 0x0c04d1f2 */
if(!s->budget--) { s->failed_pc=0x0c04d1f2u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d1f4;
P_0c04d1f4: /* original e546, guest PC 0x0c04d1f4 */
if(!s->budget--) { s->failed_pc=0x0c04d1f4u; return 0; }
r[5]=0x00000046u;
goto P_0c04d1f6;
P_0c04d1f6: /* original 56f2, guest PC 0x0c04d1f6 */
if(!s->budget--) { s->failed_pc=0x0c04d1f6u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c04d1f8;
P_0c04d1f8: /* original 5234, guest PC 0x0c04d1f8 */
if(!s->budget--) { s->failed_pc=0x0c04d1f8u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d1fa;
P_0c04d1fa: /* original 420b, guest PC 0x0c04d1fa */
if(!s->budget--) { s->failed_pc=0x0c04d1fau; return 0; }
target=r[2];
r[16]=code_base|0x0c04d1feu;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d1feu) { target=s->pc; goto dispatch; }
goto P_0c04d1fe;
P_0c04d1fc: /* original 54e8, guest PC 0x0c04d1fc */
if(!s->budget--) { s->failed_pc=0x0c04d1fcu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d1fe;
P_0c04d1fe: /* original 56e7, guest PC 0x0c04d1fe */
if(!s->budget--) { s->failed_pc=0x0c04d1feu; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d200;
P_0c04d200: /* original e54c, guest PC 0x0c04d200 */
if(!s->budget--) { s->failed_pc=0x0c04d200u; return 0; }
r[5]=0x0000004cu;
goto P_0c04d202;
P_0c04d202: /* original 63b2, guest PC 0x0c04d202 */
if(!s->budget--) { s->failed_pc=0x0c04d202u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d204;
P_0c04d204: /* original 5666, guest PC 0x0c04d204 */
if(!s->budget--) { s->failed_pc=0x0c04d204u; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c04d206;
P_0c04d206: /* original 5234, guest PC 0x0c04d206 */
if(!s->budget--) { s->failed_pc=0x0c04d206u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d208;
P_0c04d208: /* original 420b, guest PC 0x0c04d208 */
if(!s->budget--) { s->failed_pc=0x0c04d208u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d20cu;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d20cu) { target=s->pc; goto dispatch; }
goto P_0c04d20c;
P_0c04d20a: /* original 54e8, guest PC 0x0c04d20a */
if(!s->budget--) { s->failed_pc=0x0c04d20au; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d20c;
P_0c04d20c: /* original 56e7, guest PC 0x0c04d20c */
if(!s->budget--) { s->failed_pc=0x0c04d20cu; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d20e;
P_0c04d20e: /* original e548, guest PC 0x0c04d20e */
if(!s->budget--) { s->failed_pc=0x0c04d20eu; return 0; }
r[5]=0x00000048u;
goto P_0c04d210;
P_0c04d210: /* original 63b2, guest PC 0x0c04d210 */
if(!s->budget--) { s->failed_pc=0x0c04d210u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d212;
P_0c04d212: /* original 5664, guest PC 0x0c04d212 */
if(!s->budget--) { s->failed_pc=0x0c04d212u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c04d214;
P_0c04d214: /* original 5234, guest PC 0x0c04d214 */
if(!s->budget--) { s->failed_pc=0x0c04d214u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d216;
P_0c04d216: /* original 420b, guest PC 0x0c04d216 */
if(!s->budget--) { s->failed_pc=0x0c04d216u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d21au;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d21au) { target=s->pc; goto dispatch; }
goto P_0c04d21a;
P_0c04d218: /* original 54e8, guest PC 0x0c04d218 */
if(!s->budget--) { s->failed_pc=0x0c04d218u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d21a;
P_0c04d21a: /* original 56e7, guest PC 0x0c04d21a */
if(!s->budget--) { s->failed_pc=0x0c04d21au; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d21c;
P_0c04d21c: /* original e550, guest PC 0x0c04d21c */
if(!s->budget--) { s->failed_pc=0x0c04d21cu; return 0; }
r[5]=0x00000050u;
goto P_0c04d21e;
P_0c04d21e: /* original 63b2, guest PC 0x0c04d21e */
if(!s->budget--) { s->failed_pc=0x0c04d21eu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d220;
P_0c04d220: /* original 5667, guest PC 0x0c04d220 */
if(!s->budget--) { s->failed_pc=0x0c04d220u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c04d222;
P_0c04d222: /* original 5234, guest PC 0x0c04d222 */
if(!s->budget--) { s->failed_pc=0x0c04d222u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d224;
P_0c04d224: /* original 420b, guest PC 0x0c04d224 */
if(!s->budget--) { s->failed_pc=0x0c04d224u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d228u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d228u) { target=s->pc; goto dispatch; }
goto P_0c04d228;
P_0c04d226: /* original 54e8, guest PC 0x0c04d226 */
if(!s->budget--) { s->failed_pc=0x0c04d226u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d228;
P_0c04d228: /* original 56e7, guest PC 0x0c04d228 */
if(!s->budget--) { s->failed_pc=0x0c04d228u; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d22a;
P_0c04d22a: /* original e552, guest PC 0x0c04d22a */
if(!s->budget--) { s->failed_pc=0x0c04d22au; return 0; }
r[5]=0x00000052u;
goto P_0c04d22c;
P_0c04d22c: /* original 63b2, guest PC 0x0c04d22c */
if(!s->budget--) { s->failed_pc=0x0c04d22cu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d22e;
P_0c04d22e: /* original 5668, guest PC 0x0c04d22e */
if(!s->budget--) { s->failed_pc=0x0c04d22eu; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c04d230;
P_0c04d230: /* original 5234, guest PC 0x0c04d230 */
if(!s->budget--) { s->failed_pc=0x0c04d230u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d232;
P_0c04d232: /* original 420b, guest PC 0x0c04d232 */
if(!s->budget--) { s->failed_pc=0x0c04d232u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d236u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d236u) { target=s->pc; goto dispatch; }
goto P_0c04d236;
P_0c04d234: /* original 54e8, guest PC 0x0c04d234 */
if(!s->budget--) { s->failed_pc=0x0c04d234u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d236;
P_0c04d236: /* original 56e7, guest PC 0x0c04d236 */
if(!s->budget--) { s->failed_pc=0x0c04d236u; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d238;
P_0c04d238: /* original e554, guest PC 0x0c04d238 */
if(!s->budget--) { s->failed_pc=0x0c04d238u; return 0; }
r[5]=0x00000054u;
goto P_0c04d23a;
P_0c04d23a: /* original 63b2, guest PC 0x0c04d23a */
if(!s->budget--) { s->failed_pc=0x0c04d23au; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d23c;
P_0c04d23c: /* original 566d, guest PC 0x0c04d23c */
if(!s->budget--) { s->failed_pc=0x0c04d23cu; return 0; }
r[6]=read(ram,r[6]+52,4);
goto P_0c04d23e;
P_0c04d23e: /* original 5234, guest PC 0x0c04d23e */
if(!s->budget--) { s->failed_pc=0x0c04d23eu; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d240;
P_0c04d240: /* original 420b, guest PC 0x0c04d240 */
if(!s->budget--) { s->failed_pc=0x0c04d240u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d244u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d244u) { target=s->pc; goto dispatch; }
goto P_0c04d244;
P_0c04d242: /* original 54e8, guest PC 0x0c04d242 */
if(!s->budget--) { s->failed_pc=0x0c04d242u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d244;
P_0c04d244: /* original 56e7, guest PC 0x0c04d244 */
if(!s->budget--) { s->failed_pc=0x0c04d244u; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d246;
P_0c04d246: /* original e556, guest PC 0x0c04d246 */
if(!s->budget--) { s->failed_pc=0x0c04d246u; return 0; }
r[5]=0x00000056u;
goto P_0c04d248;
P_0c04d248: /* original 63b2, guest PC 0x0c04d248 */
if(!s->budget--) { s->failed_pc=0x0c04d248u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d24a;
P_0c04d24a: /* original 566e, guest PC 0x0c04d24a */
if(!s->budget--) { s->failed_pc=0x0c04d24au; return 0; }
r[6]=read(ram,r[6]+56,4);
goto P_0c04d24c;
P_0c04d24c: /* original 5234, guest PC 0x0c04d24c */
if(!s->budget--) { s->failed_pc=0x0c04d24cu; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d24e;
P_0c04d24e: /* original 420b, guest PC 0x0c04d24e */
if(!s->budget--) { s->failed_pc=0x0c04d24eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d252u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d252u) { target=s->pc; goto dispatch; }
goto P_0c04d252;
P_0c04d250: /* original 54e8, guest PC 0x0c04d250 */
if(!s->budget--) { s->failed_pc=0x0c04d250u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d252;
P_0c04d252: /* original 56e7, guest PC 0x0c04d252 */
if(!s->budget--) { s->failed_pc=0x0c04d252u; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d254;
P_0c04d254: /* original e544, guest PC 0x0c04d254 */
if(!s->budget--) { s->failed_pc=0x0c04d254u; return 0; }
r[5]=0x00000044u;
goto P_0c04d256;
P_0c04d256: /* original 63b2, guest PC 0x0c04d256 */
if(!s->budget--) { s->failed_pc=0x0c04d256u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d258;
P_0c04d258: /* original 6662, guest PC 0x0c04d258 */
if(!s->budget--) { s->failed_pc=0x0c04d258u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c04d25a;
P_0c04d25a: /* original 5234, guest PC 0x0c04d25a */
if(!s->budget--) { s->failed_pc=0x0c04d25au; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d25c;
P_0c04d25c: /* original 420b, guest PC 0x0c04d25c */
if(!s->budget--) { s->failed_pc=0x0c04d25cu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d260u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d260u) { target=s->pc; goto dispatch; }
goto P_0c04d260;
P_0c04d25e: /* original 54e8, guest PC 0x0c04d25e */
if(!s->budget--) { s->failed_pc=0x0c04d25eu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d260;
P_0c04d260: /* original 53e7, guest PC 0x0c04d260 */
if(!s->budget--) { s->failed_pc=0x0c04d260u; return 0; }
r[3]=read(ram,r[14]+28,4);
goto P_0c04d262;
P_0c04d262: /* original 6232, guest PC 0x0c04d262 */
if(!s->budget--) { s->failed_pc=0x0c04d262u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04d264;
P_0c04d264: /* original 2f26, guest PC 0x0c04d264 */
if(!s->budget--) { s->failed_pc=0x0c04d264u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d266;
P_0c04d266: /* original d124, guest PC 0x0c04d266 */
if(!s->budget--) { s->failed_pc=0x0c04d266u; return 0; }
r[1]=read(ram,0x0c04d2f8u,4);
goto P_0c04d268;
P_0c04d268: /* original b99a, guest PC 0x0c04d268 */
if(!s->budget--) { s->failed_pc=0x0c04d268u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d26cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d26cu) { target=s->pc; goto dispatch; }
goto P_0c04d26c;
P_0c04d26a: /* original 2f16, guest PC 0x0c04d26a */
if(!s->budget--) { s->failed_pc=0x0c04d26au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d26c;
P_0c04d26c: /* original 52e7, guest PC 0x0c04d26c */
if(!s->budget--) { s->failed_pc=0x0c04d26cu; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d26e;
P_0c04d26e: /* original 532b, guest PC 0x0c04d26e */
if(!s->budget--) { s->failed_pc=0x0c04d26eu; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c04d270;
P_0c04d270: /* original 2f36, guest PC 0x0c04d270 */
if(!s->budget--) { s->failed_pc=0x0c04d270u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d272;
P_0c04d272: /* original d122, guest PC 0x0c04d272 */
if(!s->budget--) { s->failed_pc=0x0c04d272u; return 0; }
r[1]=read(ram,0x0c04d2fcu,4);
goto P_0c04d274;
P_0c04d274: /* original b994, guest PC 0x0c04d274 */
if(!s->budget--) { s->failed_pc=0x0c04d274u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d278u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d278u) { target=s->pc; goto dispatch; }
goto P_0c04d278;
P_0c04d276: /* original 2f16, guest PC 0x0c04d276 */
if(!s->budget--) { s->failed_pc=0x0c04d276u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d278;
P_0c04d278: /* original 52e7, guest PC 0x0c04d278 */
if(!s->budget--) { s->failed_pc=0x0c04d278u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d27a;
P_0c04d27a: /* original 5323, guest PC 0x0c04d27a */
if(!s->budget--) { s->failed_pc=0x0c04d27au; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c04d27c;
P_0c04d27c: /* original 2f36, guest PC 0x0c04d27c */
if(!s->budget--) { s->failed_pc=0x0c04d27cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d27e;
P_0c04d27e: /* original d120, guest PC 0x0c04d27e */
if(!s->budget--) { s->failed_pc=0x0c04d27eu; return 0; }
r[1]=read(ram,0x0c04d300u,4);
goto P_0c04d280;
P_0c04d280: /* original b98e, guest PC 0x0c04d280 */
if(!s->budget--) { s->failed_pc=0x0c04d280u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d284u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d284u) { target=s->pc; goto dispatch; }
goto P_0c04d284;
P_0c04d282: /* original 2f16, guest PC 0x0c04d282 */
if(!s->budget--) { s->failed_pc=0x0c04d282u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d284;
P_0c04d284: /* original 52e7, guest PC 0x0c04d284 */
if(!s->budget--) { s->failed_pc=0x0c04d284u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d286;
P_0c04d286: /* original 5324, guest PC 0x0c04d286 */
if(!s->budget--) { s->failed_pc=0x0c04d286u; return 0; }
r[3]=read(ram,r[2]+16,4);
goto P_0c04d288;
P_0c04d288: /* original 2f36, guest PC 0x0c04d288 */
if(!s->budget--) { s->failed_pc=0x0c04d288u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d28a;
P_0c04d28a: /* original d11e, guest PC 0x0c04d28a */
if(!s->budget--) { s->failed_pc=0x0c04d28au; return 0; }
r[1]=read(ram,0x0c04d304u,4);
goto P_0c04d28c;
P_0c04d28c: /* original b988, guest PC 0x0c04d28c */
if(!s->budget--) { s->failed_pc=0x0c04d28cu; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d290u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d290u) { target=s->pc; goto dispatch; }
goto P_0c04d290;
P_0c04d28e: /* original 2f16, guest PC 0x0c04d28e */
if(!s->budget--) { s->failed_pc=0x0c04d28eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d290;
P_0c04d290: /* original 52e7, guest PC 0x0c04d290 */
if(!s->budget--) { s->failed_pc=0x0c04d290u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d292;
P_0c04d292: /* original 5325, guest PC 0x0c04d292 */
if(!s->budget--) { s->failed_pc=0x0c04d292u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c04d294;
P_0c04d294: /* original 2f36, guest PC 0x0c04d294 */
if(!s->budget--) { s->failed_pc=0x0c04d294u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d296;
P_0c04d296: /* original d11c, guest PC 0x0c04d296 */
if(!s->budget--) { s->failed_pc=0x0c04d296u; return 0; }
r[1]=read(ram,0x0c04d308u,4);
goto P_0c04d298;
P_0c04d298: /* original b982, guest PC 0x0c04d298 */
if(!s->budget--) { s->failed_pc=0x0c04d298u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d29cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d29cu) { target=s->pc; goto dispatch; }
goto P_0c04d29c;
P_0c04d29a: /* original 2f16, guest PC 0x0c04d29a */
if(!s->budget--) { s->failed_pc=0x0c04d29au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d29c;
P_0c04d29c: /* original 52e7, guest PC 0x0c04d29c */
if(!s->budget--) { s->failed_pc=0x0c04d29cu; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d29e;
P_0c04d29e: /* original 5326, guest PC 0x0c04d29e */
if(!s->budget--) { s->failed_pc=0x0c04d29eu; return 0; }
r[3]=read(ram,r[2]+24,4);
goto P_0c04d2a0;
P_0c04d2a0: /* original 2f36, guest PC 0x0c04d2a0 */
if(!s->budget--) { s->failed_pc=0x0c04d2a0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2a2;
P_0c04d2a2: /* original d11a, guest PC 0x0c04d2a2 */
if(!s->budget--) { s->failed_pc=0x0c04d2a2u; return 0; }
r[1]=read(ram,0x0c04d30cu,4);
goto P_0c04d2a4;
P_0c04d2a4: /* original b97c, guest PC 0x0c04d2a4 */
if(!s->budget--) { s->failed_pc=0x0c04d2a4u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d2a8u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d2a8u) { target=s->pc; goto dispatch; }
goto P_0c04d2a8;
P_0c04d2a6: /* original 2f16, guest PC 0x0c04d2a6 */
if(!s->budget--) { s->failed_pc=0x0c04d2a6u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2a8;
P_0c04d2a8: /* original 52e7, guest PC 0x0c04d2a8 */
if(!s->budget--) { s->failed_pc=0x0c04d2a8u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d2aa;
P_0c04d2aa: /* original 5321, guest PC 0x0c04d2aa */
if(!s->budget--) { s->failed_pc=0x0c04d2aau; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c04d2ac;
P_0c04d2ac: /* original 2f36, guest PC 0x0c04d2ac */
if(!s->budget--) { s->failed_pc=0x0c04d2acu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2ae;
P_0c04d2ae: /* original d118, guest PC 0x0c04d2ae */
if(!s->budget--) { s->failed_pc=0x0c04d2aeu; return 0; }
r[1]=read(ram,0x0c04d310u,4);
goto P_0c04d2b0;
P_0c04d2b0: /* original b976, guest PC 0x0c04d2b0 */
if(!s->budget--) { s->failed_pc=0x0c04d2b0u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d2b4u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d2b4u) { target=s->pc; goto dispatch; }
goto P_0c04d2b4;
P_0c04d2b2: /* original 2f16, guest PC 0x0c04d2b2 */
if(!s->budget--) { s->failed_pc=0x0c04d2b2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2b4;
P_0c04d2b4: /* original 52fe, guest PC 0x0c04d2b4 */
if(!s->budget--) { s->failed_pc=0x0c04d2b4u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c04d2b6;
P_0c04d2b6: /* original 2f26, guest PC 0x0c04d2b6 */
if(!s->budget--) { s->failed_pc=0x0c04d2b6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2b8;
P_0c04d2b8: /* original d316, guest PC 0x0c04d2b8 */
if(!s->budget--) { s->failed_pc=0x0c04d2b8u; return 0; }
r[3]=read(ram,0x0c04d314u,4);
goto P_0c04d2ba;
P_0c04d2ba: /* original b971, guest PC 0x0c04d2ba */
if(!s->budget--) { s->failed_pc=0x0c04d2bau; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d2beu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d2beu) { target=s->pc; goto dispatch; }
goto P_0c04d2be;
P_0c04d2bc: /* original 2f36, guest PC 0x0c04d2bc */
if(!s->budget--) { s->failed_pc=0x0c04d2bcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2be;
P_0c04d2be: /* original e100, guest PC 0x0c04d2be */
if(!s->budget--) { s->failed_pc=0x0c04d2beu; return 0; }
r[1]=0x00000000u;
goto P_0c04d2c0;
P_0c04d2c0: /* original 2f16, guest PC 0x0c04d2c0 */
if(!s->budget--) { s->failed_pc=0x0c04d2c0u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2c2;
P_0c04d2c2: /* original d315, guest PC 0x0c04d2c2 */
if(!s->budget--) { s->failed_pc=0x0c04d2c2u; return 0; }
r[3]=read(ram,0x0c04d318u,4);
goto P_0c04d2c4;
P_0c04d2c4: /* original b96c, guest PC 0x0c04d2c4 */
if(!s->budget--) { s->failed_pc=0x0c04d2c4u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d2c8u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d2c8u) { target=s->pc; goto dispatch; }
goto P_0c04d2c8;
P_0c04d2c6: /* original 2f36, guest PC 0x0c04d2c6 */
if(!s->budget--) { s->failed_pc=0x0c04d2c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2c8;
P_0c04d2c8: /* original 9613, guest PC 0x0c04d2c8 */
if(!s->budget--) { s->failed_pc=0x0c04d2c8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d2f2u,2);
goto P_0c04d2ca;
P_0c04d2ca: /* original e500, guest PC 0x0c04d2ca */
if(!s->budget--) { s->failed_pc=0x0c04d2cau; return 0; }
r[5]=0x00000000u;
goto P_0c04d2cc;
P_0c04d2cc: /* original 7f48, guest PC 0x0c04d2cc */
if(!s->budget--) { s->failed_pc=0x0c04d2ccu; return 0; }
r[15]+=0x00000048u;
goto P_0c04d2ce;
P_0c04d2ce: /* original 4a0b, guest PC 0x0c04d2ce */
if(!s->budget--) { s->failed_pc=0x0c04d2ceu; return 0; }
target=r[10];
r[16]=code_base|0x0c04d2d2u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d2d2u) { target=s->pc; goto dispatch; }
goto P_0c04d2d2;
P_0c04d2d0: /* original 6493, guest PC 0x0c04d2d0 */
if(!s->budget--) { s->failed_pc=0x0c04d2d0u; return 0; }
r[4]=r[9];
goto P_0c04d2d2;
P_0c04d2d2: /* original a042, guest PC 0x0c04d2d2 */
if(!s->budget--) { s->failed_pc=0x0c04d2d2u; return 0; }
r[11]=0x00000000u;
goto P_0c04d35a;
P_0c04d2d4: /* original eb00, guest PC 0x0c04d2d4 */
if(!s->budget--) { s->failed_pc=0x0c04d2d4u; return 0; }
r[11]=0x00000000u;
goto P_0c04d2d6;
P_0c04d2d6: /* original 2fb6, guest PC 0x0c04d2d6 */
if(!s->budget--) { s->failed_pc=0x0c04d2d6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2d8;
P_0c04d2d8: /* original d210, guest PC 0x0c04d2d8 */
if(!s->budget--) { s->failed_pc=0x0c04d2d8u; return 0; }
r[2]=read(ram,0x0c04d31cu,4);
goto P_0c04d2da;
P_0c04d2da: /* original b961, guest PC 0x0c04d2da */
if(!s->budget--) { s->failed_pc=0x0c04d2dau; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d2deu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d2deu) { target=s->pc; goto dispatch; }
goto P_0c04d2de;
P_0c04d2dc: /* original 2f26, guest PC 0x0c04d2dc */
if(!s->budget--) { s->failed_pc=0x0c04d2dcu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2de;
P_0c04d2de: /* original 7f08, guest PC 0x0c04d2de */
if(!s->budget--) { s->failed_pc=0x0c04d2deu; return 0; }
r[15]+=0x00000008u;
goto P_0c04d2e0;
P_0c04d2e0: /* original 51ff, guest PC 0x0c04d2e0 */
if(!s->budget--) { s->failed_pc=0x0c04d2e0u; return 0; }
r[1]=read(ram,r[15]+60,4);
goto P_0c04d2e2;
P_0c04d2e2: /* original 2118, guest PC 0x0c04d2e2 */
if(!s->budget--) { s->failed_pc=0x0c04d2e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04d2e4;
P_0c04d2e4: /* original 891c, guest PC 0x0c04d2e4 */
if(!s->budget--) { s->failed_pc=0x0c04d2e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d320; }
goto P_0c04d2e6;
P_0c04d2e6: /* original 65b3, guest PC 0x0c04d2e6 */
if(!s->budget--) { s->failed_pc=0x0c04d2e6u; return 0; }
r[5]=r[11];
goto P_0c04d2e8;
P_0c04d2e8: /* original 6693, guest PC 0x0c04d2e8 */
if(!s->budget--) { s->failed_pc=0x0c04d2e8u; return 0; }
r[6]=r[9];
goto P_0c04d2ea;
P_0c04d2ea: /* original 480b, guest PC 0x0c04d2ea */
if(!s->budget--) { s->failed_pc=0x0c04d2eau; return 0; }
target=r[8];
r[16]=code_base|0x0c04d2eeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d2eeu) { target=s->pc; goto dispatch; }
goto P_0c04d2ee;
P_0c04d2ec: /* original 64d3, guest PC 0x0c04d2ec */
if(!s->budget--) { s->failed_pc=0x0c04d2ecu; return 0; }
r[4]=r[13];
goto P_0c04d2ee;
P_0c04d2ee: /* original a018, guest PC 0x0c04d2ee */
if(!s->budget--) { s->failed_pc=0x0c04d2eeu; return 0; }
r[4]=r[0];
goto P_0c04d322;
P_0c04d2f0: /* original 6403, guest PC 0x0c04d2f0 */
if(!s->budget--) { s->failed_pc=0x0c04d2f0u; return 0; }
r[4]=r[0];
return vf3_matrix_family(0x0c04d2f2u,s,ram);
P_0c04d320: /* original 64c3, guest PC 0x0c04d320 */
if(!s->budget--) { s->failed_pc=0x0c04d320u; return 0; }
r[4]=r[12];
goto P_0c04d322;
P_0c04d322: /* original 9179, guest PC 0x0c04d322 */
if(!s->budget--) { s->failed_pc=0x0c04d322u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d418u,2);
goto P_0c04d324;
P_0c04d324: /* original 6043, guest PC 0x0c04d324 */
if(!s->budget--) { s->failed_pc=0x0c04d324u; return 0; }
r[0]=r[4];
goto P_0c04d326;
P_0c04d326: /* original 3010, guest PC 0x0c04d326 */
if(!s->budget--) { s->failed_pc=0x0c04d326u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04d328;
P_0c04d328: /* original 8904, guest PC 0x0c04d328 */
if(!s->budget--) { s->failed_pc=0x0c04d328u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d334; }
goto P_0c04d32a;
P_0c04d32a: /* original 9176, guest PC 0x0c04d32a */
if(!s->budget--) { s->failed_pc=0x0c04d32au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d41au,2);
goto P_0c04d32c;
P_0c04d32c: /* original 3010, guest PC 0x0c04d32c */
if(!s->budget--) { s->failed_pc=0x0c04d32cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04d32e;
P_0c04d32e: /* original 8904, guest PC 0x0c04d32e */
if(!s->budget--) { s->failed_pc=0x0c04d32eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d33a; }
goto P_0c04d330;
P_0c04d330: /* original a009, guest PC 0x0c04d330 */
if(!s->budget--) { s->failed_pc=0x0c04d330u; return 0; }
goto P_0c04d346;
P_0c04d332: /* original 0009, guest PC 0x0c04d332 */
if(!s->budget--) { s->failed_pc=0x0c04d332u; return 0; }
goto P_0c04d334;
P_0c04d334: /* original 9070, guest PC 0x0c04d334 */
if(!s->budget--) { s->failed_pc=0x0c04d334u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d418u,2);
goto P_0c04d336;
P_0c04d336: /* original a064, guest PC 0x0c04d336 */
if(!s->budget--) { s->failed_pc=0x0c04d336u; return 0; }
goto P_0c04d402;
P_0c04d338: /* original 0009, guest PC 0x0c04d338 */
if(!s->budget--) { s->failed_pc=0x0c04d338u; return 0; }
goto P_0c04d33a;
P_0c04d33a: /* original d238, guest PC 0x0c04d33a */
if(!s->budget--) { s->failed_pc=0x0c04d33au; return 0; }
r[2]=read(ram,0x0c04d41cu,4);
goto P_0c04d33c;
P_0c04d33c: /* original b930, guest PC 0x0c04d33c */
if(!s->budget--) { s->failed_pc=0x0c04d33cu; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d340u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d340u) { target=s->pc; goto dispatch; }
goto P_0c04d340;
P_0c04d33e: /* original 2f26, guest PC 0x0c04d33e */
if(!s->budget--) { s->failed_pc=0x0c04d33eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d340;
P_0c04d340: /* original d637, guest PC 0x0c04d340 */
if(!s->budget--) { s->failed_pc=0x0c04d340u; return 0; }
r[6]=read(ram,0x0c04d420u,4);
goto P_0c04d342;
P_0c04d342: /* original a005, guest PC 0x0c04d342 */
if(!s->budget--) { s->failed_pc=0x0c04d342u; return 0; }
r[15]+=0x00000004u;
goto P_0c04d350;
P_0c04d344: /* original 7f04, guest PC 0x0c04d344 */
if(!s->budget--) { s->failed_pc=0x0c04d344u; return 0; }
r[15]+=0x00000004u;
goto P_0c04d346;
P_0c04d346: /* original d237, guest PC 0x0c04d346 */
if(!s->budget--) { s->failed_pc=0x0c04d346u; return 0; }
r[2]=read(ram,0x0c04d424u,4);
goto P_0c04d348;
P_0c04d348: /* original b92a, guest PC 0x0c04d348 */
if(!s->budget--) { s->failed_pc=0x0c04d348u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d34cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d34cu) { target=s->pc; goto dispatch; }
goto P_0c04d34c;
P_0c04d34a: /* original 2f26, guest PC 0x0c04d34a */
if(!s->budget--) { s->failed_pc=0x0c04d34au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d34c;
P_0c04d34c: /* original d636, guest PC 0x0c04d34c */
if(!s->budget--) { s->failed_pc=0x0c04d34cu; return 0; }
r[6]=read(ram,0x0c04d428u,4);
goto P_0c04d34e;
P_0c04d34e: /* original 7f04, guest PC 0x0c04d34e */
if(!s->budget--) { s->failed_pc=0x0c04d34eu; return 0; }
r[15]+=0x00000004u;
goto P_0c04d350;
P_0c04d350: /* original d236, guest PC 0x0c04d350 */
if(!s->budget--) { s->failed_pc=0x0c04d350u; return 0; }
r[2]=read(ram,0x0c04d42cu,4);
goto P_0c04d352;
P_0c04d352: /* original 65b3, guest PC 0x0c04d352 */
if(!s->budget--) { s->failed_pc=0x0c04d352u; return 0; }
r[5]=r[11];
goto P_0c04d354;
P_0c04d354: /* original 420b, guest PC 0x0c04d354 */
if(!s->budget--) { s->failed_pc=0x0c04d354u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d358u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d358u) { target=s->pc; goto dispatch; }
goto P_0c04d358;
P_0c04d356: /* original 64d3, guest PC 0x0c04d356 */
if(!s->budget--) { s->failed_pc=0x0c04d356u; return 0; }
r[4]=r[13];
goto P_0c04d358;
P_0c04d358: /* original 7b01, guest PC 0x0c04d358 */
if(!s->budget--) { s->failed_pc=0x0c04d358u; return 0; }
r[11]+=0x00000001u;
goto P_0c04d35a;
P_0c04d35a: /* original 53e7, guest PC 0x0c04d35a */
if(!s->budget--) { s->failed_pc=0x0c04d35au; return 0; }
r[3]=read(ram,r[14]+28,4);
goto P_0c04d35c;
P_0c04d35c: /* original 6232, guest PC 0x0c04d35c */
if(!s->budget--) { s->failed_pc=0x0c04d35cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04d35e;
P_0c04d35e: /* original 3b23, guest PC 0x0c04d35e */
if(!s->budget--) { s->failed_pc=0x0c04d35eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c04d360;
P_0c04d360: /* original 8bb9, guest PC 0x0c04d360 */
if(!s->budget--) { s->failed_pc=0x0c04d360u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d2d6; }
goto P_0c04d362;
P_0c04d362: /* original 55e7, guest PC 0x0c04d362 */
if(!s->budget--) { s->failed_pc=0x0c04d362u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d364;
P_0c04d364: /* original 5256, guest PC 0x0c04d364 */
if(!s->budget--) { s->failed_pc=0x0c04d364u; return 0; }
r[2]=read(ram,r[5]+24,4);
goto P_0c04d366;
P_0c04d366: /* original 545c, guest PC 0x0c04d366 */
if(!s->budget--) { s->failed_pc=0x0c04d366u; return 0; }
r[4]=read(ram,r[5]+48,4);
goto P_0c04d368;
P_0c04d368: /* original 2f22, guest PC 0x0c04d368 */
if(!s->budget--) { s->failed_pc=0x0c04d368u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04d36a;
P_0c04d36a: /* original 2f46, guest PC 0x0c04d36a */
if(!s->budget--) { s->failed_pc=0x0c04d36au; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d36c;
P_0c04d36c: /* original d330, guest PC 0x0c04d36c */
if(!s->budget--) { s->failed_pc=0x0c04d36cu; return 0; }
r[3]=read(ram,0x0c04d430u,4);
goto P_0c04d36e;
P_0c04d36e: /* original b917, guest PC 0x0c04d36e */
if(!s->budget--) { s->failed_pc=0x0c04d36eu; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04d372u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d372u) { target=s->pc; goto dispatch; }
goto P_0c04d372;
P_0c04d370: /* original 2f36, guest PC 0x0c04d370 */
if(!s->budget--) { s->failed_pc=0x0c04d370u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d372;
P_0c04d372: /* original 7f08, guest PC 0x0c04d372 */
if(!s->budget--) { s->failed_pc=0x0c04d372u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d374;
P_0c04d374: /* original 66f2, guest PC 0x0c04d374 */
if(!s->budget--) { s->failed_pc=0x0c04d374u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04d376;
P_0c04d376: /* original e500, guest PC 0x0c04d376 */
if(!s->budget--) { s->failed_pc=0x0c04d376u; return 0; }
r[5]=0x00000000u;
goto P_0c04d378;
P_0c04d378: /* original 4618, guest PC 0x0c04d378 */
if(!s->budget--) { s->failed_pc=0x0c04d378u; return 0; }
r[6]<<=8;
goto P_0c04d37a;
P_0c04d37a: /* original 4600, guest PC 0x0c04d37a */
if(!s->budget--) { s->failed_pc=0x0c04d37au; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c04d37c;
P_0c04d37c: /* original 4a0b, guest PC 0x0c04d37c */
if(!s->budget--) { s->failed_pc=0x0c04d37cu; return 0; }
target=r[10];
r[16]=code_base|0x0c04d380u;
r[4]=read(ram,r[14]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d380u) { target=s->pc; goto dispatch; }
goto P_0c04d380;
P_0c04d37e: /* original 54ea, guest PC 0x0c04d37e */
if(!s->budget--) { s->failed_pc=0x0c04d37eu; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04d380;
P_0c04d380: /* original d32c, guest PC 0x0c04d380 */
if(!s->budget--) { s->failed_pc=0x0c04d380u; return 0; }
r[3]=read(ram,0x0c04d434u,4);
goto P_0c04d382;
P_0c04d382: /* original 430b, guest PC 0x0c04d382 */
if(!s->budget--) { s->failed_pc=0x0c04d382u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d386u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d386u) { target=s->pc; goto dispatch; }
goto P_0c04d386;
P_0c04d384: /* original 64d3, guest PC 0x0c04d384 */
if(!s->budget--) { s->failed_pc=0x0c04d384u; return 0; }
r[4]=r[13];
goto P_0c04d386;
P_0c04d386: /* original 55e7, guest PC 0x0c04d386 */
if(!s->budget--) { s->failed_pc=0x0c04d386u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d388;
P_0c04d388: /* original db2b, guest PC 0x0c04d388 */
if(!s->budget--) { s->failed_pc=0x0c04d388u; return 0; }
r[11]=read(ram,0x0c04d438u,4);
goto P_0c04d38a;
P_0c04d38a: /* original d328, guest PC 0x0c04d38a */
if(!s->budget--) { s->failed_pc=0x0c04d38au; return 0; }
r[3]=read(ram,0x0c04d42cu,4);
goto P_0c04d38c;
P_0c04d38c: /* original 5552, guest PC 0x0c04d38c */
if(!s->budget--) { s->failed_pc=0x0c04d38cu; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04d38e;
P_0c04d38e: /* original 66b3, guest PC 0x0c04d38e */
if(!s->budget--) { s->failed_pc=0x0c04d38eu; return 0; }
r[6]=r[11];
goto P_0c04d390;
P_0c04d390: /* original 430b, guest PC 0x0c04d390 */
if(!s->budget--) { s->failed_pc=0x0c04d390u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d394u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d394u) { target=s->pc; goto dispatch; }
goto P_0c04d394;
P_0c04d392: /* original 64d3, guest PC 0x0c04d392 */
if(!s->budget--) { s->failed_pc=0x0c04d392u; return 0; }
r[4]=r[13];
goto P_0c04d394;
P_0c04d394: /* original a008, guest PC 0x0c04d394 */
if(!s->budget--) { s->failed_pc=0x0c04d394u; return 0; }
r[9]=0x00000000u;
goto P_0c04d3a8;
P_0c04d396: /* original e900, guest PC 0x0c04d396 */
if(!s->budget--) { s->failed_pc=0x0c04d396u; return 0; }
r[9]=0x00000000u;
goto P_0c04d398;
P_0c04d398: /* original 55e7, guest PC 0x0c04d398 */
if(!s->budget--) { s->failed_pc=0x0c04d398u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d39a;
P_0c04d39a: /* original 66b3, guest PC 0x0c04d39a */
if(!s->budget--) { s->failed_pc=0x0c04d39au; return 0; }
r[6]=r[11];
goto P_0c04d39c;
P_0c04d39c: /* original d323, guest PC 0x0c04d39c */
if(!s->budget--) { s->failed_pc=0x0c04d39cu; return 0; }
r[3]=read(ram,0x0c04d42cu,4);
goto P_0c04d39e;
P_0c04d39e: /* original 5553, guest PC 0x0c04d39e */
if(!s->budget--) { s->failed_pc=0x0c04d39eu; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04d3a0;
P_0c04d3a0: /* original 359c, guest PC 0x0c04d3a0 */
if(!s->budget--) { s->failed_pc=0x0c04d3a0u; return 0; }
r[5]+=r[9];
goto P_0c04d3a2;
P_0c04d3a2: /* original 430b, guest PC 0x0c04d3a2 */
if(!s->budget--) { s->failed_pc=0x0c04d3a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d3a6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d3a6u) { target=s->pc; goto dispatch; }
goto P_0c04d3a6;
P_0c04d3a4: /* original 64d3, guest PC 0x0c04d3a4 */
if(!s->budget--) { s->failed_pc=0x0c04d3a4u; return 0; }
r[4]=r[13];
goto P_0c04d3a6;
P_0c04d3a6: /* original 7901, guest PC 0x0c04d3a6 */
if(!s->budget--) { s->failed_pc=0x0c04d3a6u; return 0; }
r[9]+=0x00000001u;
goto P_0c04d3a8;
P_0c04d3a8: /* original 52e7, guest PC 0x0c04d3a8 */
if(!s->budget--) { s->failed_pc=0x0c04d3a8u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d3aa;
P_0c04d3aa: /* original 5324, guest PC 0x0c04d3aa */
if(!s->budget--) { s->failed_pc=0x0c04d3aau; return 0; }
r[3]=read(ram,r[2]+16,4);
goto P_0c04d3ac;
P_0c04d3ac: /* original 3933, guest PC 0x0c04d3ac */
if(!s->budget--) { s->failed_pc=0x0c04d3acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[3])!=0);
goto P_0c04d3ae;
P_0c04d3ae: /* original 8bf3, guest PC 0x0c04d3ae */
if(!s->budget--) { s->failed_pc=0x0c04d3aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d398; }
goto P_0c04d3b0;
P_0c04d3b0: /* original 55e7, guest PC 0x0c04d3b0 */
if(!s->budget--) { s->failed_pc=0x0c04d3b0u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d3b2;
P_0c04d3b2: /* original 66b3, guest PC 0x0c04d3b2 */
if(!s->budget--) { s->failed_pc=0x0c04d3b2u; return 0; }
r[6]=r[11];
goto P_0c04d3b4;
P_0c04d3b4: /* original d31d, guest PC 0x0c04d3b4 */
if(!s->budget--) { s->failed_pc=0x0c04d3b4u; return 0; }
r[3]=read(ram,0x0c04d42cu,4);
goto P_0c04d3b6;
P_0c04d3b6: /* original 5552, guest PC 0x0c04d3b6 */
if(!s->budget--) { s->failed_pc=0x0c04d3b6u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04d3b8;
P_0c04d3b8: /* original 430b, guest PC 0x0c04d3b8 */
if(!s->budget--) { s->failed_pc=0x0c04d3b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d3bcu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d3bcu) { target=s->pc; goto dispatch; }
goto P_0c04d3bc;
P_0c04d3ba: /* original 64d3, guest PC 0x0c04d3ba */
if(!s->budget--) { s->failed_pc=0x0c04d3bau; return 0; }
r[4]=r[13];
goto P_0c04d3bc;
P_0c04d3bc: /* original a008, guest PC 0x0c04d3bc */
if(!s->budget--) { s->failed_pc=0x0c04d3bcu; return 0; }
r[9]=r[12];
goto P_0c04d3d0;
P_0c04d3be: /* original 69c3, guest PC 0x0c04d3be */
if(!s->budget--) { s->failed_pc=0x0c04d3beu; return 0; }
r[9]=r[12];
goto P_0c04d3c0;
P_0c04d3c0: /* original 55e7, guest PC 0x0c04d3c0 */
if(!s->budget--) { s->failed_pc=0x0c04d3c0u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d3c2;
P_0c04d3c2: /* original 66b3, guest PC 0x0c04d3c2 */
if(!s->budget--) { s->failed_pc=0x0c04d3c2u; return 0; }
r[6]=r[11];
goto P_0c04d3c4;
P_0c04d3c4: /* original d319, guest PC 0x0c04d3c4 */
if(!s->budget--) { s->failed_pc=0x0c04d3c4u; return 0; }
r[3]=read(ram,0x0c04d42cu,4);
goto P_0c04d3c6;
P_0c04d3c6: /* original 5553, guest PC 0x0c04d3c6 */
if(!s->budget--) { s->failed_pc=0x0c04d3c6u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04d3c8;
P_0c04d3c8: /* original 359c, guest PC 0x0c04d3c8 */
if(!s->budget--) { s->failed_pc=0x0c04d3c8u; return 0; }
r[5]+=r[9];
goto P_0c04d3ca;
P_0c04d3ca: /* original 430b, guest PC 0x0c04d3ca */
if(!s->budget--) { s->failed_pc=0x0c04d3cau; return 0; }
target=r[3];
r[16]=code_base|0x0c04d3ceu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d3ceu) { target=s->pc; goto dispatch; }
goto P_0c04d3ce;
P_0c04d3cc: /* original 64d3, guest PC 0x0c04d3cc */
if(!s->budget--) { s->failed_pc=0x0c04d3ccu; return 0; }
r[4]=r[13];
goto P_0c04d3ce;
P_0c04d3ce: /* original 7901, guest PC 0x0c04d3ce */
if(!s->budget--) { s->failed_pc=0x0c04d3ceu; return 0; }
r[9]+=0x00000001u;
goto P_0c04d3d0;
P_0c04d3d0: /* original 52e7, guest PC 0x0c04d3d0 */
if(!s->budget--) { s->failed_pc=0x0c04d3d0u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d3d2;
P_0c04d3d2: /* original 5324, guest PC 0x0c04d3d2 */
if(!s->budget--) { s->failed_pc=0x0c04d3d2u; return 0; }
r[3]=read(ram,r[2]+16,4);
goto P_0c04d3d4;
P_0c04d3d4: /* original 3933, guest PC 0x0c04d3d4 */
if(!s->budget--) { s->failed_pc=0x0c04d3d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[3])!=0);
goto P_0c04d3d6;
P_0c04d3d6: /* original 8bf3, guest PC 0x0c04d3d6 */
if(!s->budget--) { s->failed_pc=0x0c04d3d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d3c0; }
goto P_0c04d3d8;
P_0c04d3d8: /* original d318, guest PC 0x0c04d3d8 */
if(!s->budget--) { s->failed_pc=0x0c04d3d8u; return 0; }
r[3]=read(ram,0x0c04d43cu,4);
goto P_0c04d3da;
P_0c04d3da: /* original 430b, guest PC 0x0c04d3da */
if(!s->budget--) { s->failed_pc=0x0c04d3dau; return 0; }
target=r[3];
r[16]=code_base|0x0c04d3deu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d3deu) { target=s->pc; goto dispatch; }
goto P_0c04d3de;
P_0c04d3dc: /* original 64d3, guest PC 0x0c04d3dc */
if(!s->budget--) { s->failed_pc=0x0c04d3dcu; return 0; }
r[4]=r[13];
goto P_0c04d3de;
P_0c04d3de: /* original e555, guest PC 0x0c04d3de */
if(!s->budget--) { s->failed_pc=0x0c04d3deu; return 0; }
r[5]=0x00000055u;
goto P_0c04d3e0;
P_0c04d3e0: /* original e610, guest PC 0x0c04d3e0 */
if(!s->budget--) { s->failed_pc=0x0c04d3e0u; return 0; }
r[6]=0x00000010u;
goto P_0c04d3e2;
P_0c04d3e2: /* original 4a0b, guest PC 0x0c04d3e2 */
if(!s->budget--) { s->failed_pc=0x0c04d3e2u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d3e6u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d3e6u) { target=s->pc; goto dispatch; }
goto P_0c04d3e6;
P_0c04d3e4: /* original 54e8, guest PC 0x0c04d3e4 */
if(!s->budget--) { s->failed_pc=0x0c04d3e4u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d3e6;
P_0c04d3e6: /* original d216, guest PC 0x0c04d3e6 */
if(!s->budget--) { s->failed_pc=0x0c04d3e6u; return 0; }
r[2]=read(ram,0x0c04d440u,4);
goto P_0c04d3e8;
P_0c04d3e8: /* original 420b, guest PC 0x0c04d3e8 */
if(!s->budget--) { s->failed_pc=0x0c04d3e8u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d3ecu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d3ecu) { target=s->pc; goto dispatch; }
goto P_0c04d3ec;
P_0c04d3ea: /* original 64d3, guest PC 0x0c04d3ea */
if(!s->budget--) { s->failed_pc=0x0c04d3eau; return 0; }
r[4]=r[13];
goto P_0c04d3ec;
P_0c04d3ec: /* original e500, guest PC 0x0c04d3ec */
if(!s->budget--) { s->failed_pc=0x0c04d3ecu; return 0; }
r[5]=0x00000000u;
goto P_0c04d3ee;
P_0c04d3ee: /* original e610, guest PC 0x0c04d3ee */
if(!s->budget--) { s->failed_pc=0x0c04d3eeu; return 0; }
r[6]=0x00000010u;
goto P_0c04d3f0;
P_0c04d3f0: /* original 4a0b, guest PC 0x0c04d3f0 */
if(!s->budget--) { s->failed_pc=0x0c04d3f0u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d3f4u;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d3f4u) { target=s->pc; goto dispatch; }
goto P_0c04d3f4;
P_0c04d3f2: /* original 54e8, guest PC 0x0c04d3f2 */
if(!s->budget--) { s->failed_pc=0x0c04d3f2u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d3f4;
P_0c04d3f4: /* original 60c3, guest PC 0x0c04d3f4 */
if(!s->budget--) { s->failed_pc=0x0c04d3f4u; return 0; }
r[0]=r[12];
goto P_0c04d3f6;
P_0c04d3f6: /* original 80eb, guest PC 0x0c04d3f6 */
if(!s->budget--) { s->failed_pc=0x0c04d3f6u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04d3f8;
P_0c04d3f8: /* original 80ec, guest PC 0x0c04d3f8 */
if(!s->budget--) { s->failed_pc=0x0c04d3f8u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04d3fa;
P_0c04d3fa: /* original 80ea, guest PC 0x0c04d3fa */
if(!s->budget--) { s->failed_pc=0x0c04d3fau; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04d3fc;
P_0c04d3fc: /* original d311, guest PC 0x0c04d3fc */
if(!s->budget--) { s->failed_pc=0x0c04d3fcu; return 0; }
r[3]=read(ram,0x0c04d444u,4);
goto P_0c04d3fe;
P_0c04d3fe: /* original 430b, guest PC 0x0c04d3fe */
if(!s->budget--) { s->failed_pc=0x0c04d3feu; return 0; }
target=r[3];
r[16]=code_base|0x0c04d402u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d402u) { target=s->pc; goto dispatch; }
goto P_0c04d402;
P_0c04d400: /* original 64d3, guest PC 0x0c04d400 */
if(!s->budget--) { s->failed_pc=0x0c04d400u; return 0; }
r[4]=r[13];
goto P_0c04d402;
P_0c04d402: /* original 7f18, guest PC 0x0c04d402 */
if(!s->budget--) { s->failed_pc=0x0c04d402u; return 0; }
r[15]+=0x00000018u;
goto P_0c04d404;
P_0c04d404: /* original 4f16, guest PC 0x0c04d404 */
if(!s->budget--) { s->failed_pc=0x0c04d404u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d406;
P_0c04d406: /* original 4f26, guest PC 0x0c04d406 */
if(!s->budget--) { s->failed_pc=0x0c04d406u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d408;
P_0c04d408: /* original 68f6, guest PC 0x0c04d408 */
if(!s->budget--) { s->failed_pc=0x0c04d408u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04d40a;
P_0c04d40a: /* original 69f6, guest PC 0x0c04d40a */
if(!s->budget--) { s->failed_pc=0x0c04d40au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04d40c;
P_0c04d40c: /* original 6af6, guest PC 0x0c04d40c */
if(!s->budget--) { s->failed_pc=0x0c04d40cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04d40e;
P_0c04d40e: /* original 6bf6, guest PC 0x0c04d40e */
if(!s->budget--) { s->failed_pc=0x0c04d40eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d410;
P_0c04d410: /* original 6cf6, guest PC 0x0c04d410 */
if(!s->budget--) { s->failed_pc=0x0c04d410u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d412;
P_0c04d412: /* original 6df6, guest PC 0x0c04d412 */
if(!s->budget--) { s->failed_pc=0x0c04d412u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d414;
P_0c04d414: /* original 000b, guest PC 0x0c04d414 */
if(!s->budget--) { s->failed_pc=0x0c04d414u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d416: /* original 6ef6, guest PC 0x0c04d416 */
if(!s->budget--) { s->failed_pc=0x0c04d416u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04d418u,s,ram);
P_0c04e8f8: /* original 4f22, guest PC 0x0c04e8f8 */
if(!s->budget--) { s->failed_pc=0x0c04e8f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e8fa;
P_0c04e8fa: /* original 4f12, guest PC 0x0c04e8fa */
if(!s->budget--) { s->failed_pc=0x0c04e8fau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e8fc;
P_0c04e8fc: /* original 7ffc, guest PC 0x0c04e8fc */
if(!s->budget--) { s->failed_pc=0x0c04e8fcu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04e8fe;
P_0c04e8fe: /* original 2f66, guest PC 0x0c04e8fe */
if(!s->budget--) { s->failed_pc=0x0c04e8feu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e900;
P_0c04e900: /* original 2fb6, guest PC 0x0c04e900 */
if(!s->budget--) { s->failed_pc=0x0c04e900u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e902;
P_0c04e902: /* original 2fe6, guest PC 0x0c04e902 */
if(!s->budget--) { s->failed_pc=0x0c04e902u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e904;
P_0c04e904: /* original d328, guest PC 0x0c04e904 */
if(!s->budget--) { s->failed_pc=0x0c04e904u; return 0; }
r[3]=read(ram,0x0c04e9a8u,4);
goto P_0c04e906;
P_0c04e906: /* original d229, guest PC 0x0c04e906 */
if(!s->budget--) { s->failed_pc=0x0c04e906u; return 0; }
r[2]=read(ram,0x0c04e9acu,4);
goto P_0c04e908;
P_0c04e908: /* original 420b, guest PC 0x0c04e908 */
if(!s->budget--) { s->failed_pc=0x0c04e908u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e90cu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e90cu) { target=s->pc; goto dispatch; }
goto P_0c04e90c;
P_0c04e90a: /* original 2f36, guest PC 0x0c04e90a */
if(!s->budget--) { s->failed_pc=0x0c04e90au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e90c;
P_0c04e90c: /* original 4d15, guest PC 0x0c04e90c */
if(!s->budget--) { s->failed_pc=0x0c04e90cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c04e90e;
P_0c04e90e: /* original e900, guest PC 0x0c04e90e */
if(!s->budget--) { s->failed_pc=0x0c04e90eu; return 0; }
r[9]=0x00000000u;
goto P_0c04e910;
P_0c04e910: /* original 7f10, guest PC 0x0c04e910 */
if(!s->budget--) { s->failed_pc=0x0c04e910u; return 0; }
r[15]+=0x00000010u;
goto P_0c04e912;
P_0c04e912: /* original 8f0f, guest PC 0x0c04e912 */
if(!s->budget--) { s->failed_pc=0x0c04e912u; return 0; }
cond=r[17]&1u;
r[12]=r[9];
if(!cond) { goto P_0c04e934; }
goto P_0c04e916;
P_0c04e914: /* original 6c93, guest PC 0x0c04e914 */
if(!s->budget--) { s->failed_pc=0x0c04e914u; return 0; }
r[12]=r[9];
goto P_0c04e916;
P_0c04e916: /* original d826, guest PC 0x0c04e916 */
if(!s->budget--) { s->failed_pc=0x0c04e916u; return 0; }
r[8]=read(ram,0x0c04e9b0u,4);
goto P_0c04e918;
P_0c04e918: /* original 6ac3, guest PC 0x0c04e918 */
if(!s->budget--) { s->failed_pc=0x0c04e918u; return 0; }
r[10]=r[12];
goto P_0c04e91a;
P_0c04e91a: /* original 4a08, guest PC 0x0c04e91a */
if(!s->budget--) { s->failed_pc=0x0c04e91au; return 0; }
r[10]<<=2;
goto P_0c04e91c;
P_0c04e91c: /* original 3abc, guest PC 0x0c04e91c */
if(!s->budget--) { s->failed_pc=0x0c04e91cu; return 0; }
r[10]+=r[11];
goto P_0c04e91e;
P_0c04e91e: /* original 2fa6, guest PC 0x0c04e91e */
if(!s->budget--) { s->failed_pc=0x0c04e91eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e920;
P_0c04e920: /* original 63a2, guest PC 0x0c04e920 */
if(!s->budget--) { s->failed_pc=0x0c04e920u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c04e922;
P_0c04e922: /* original 2f36, guest PC 0x0c04e922 */
if(!s->budget--) { s->failed_pc=0x0c04e922u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e924;
P_0c04e924: /* original 2fc6, guest PC 0x0c04e924 */
if(!s->budget--) { s->failed_pc=0x0c04e924u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e926;
P_0c04e926: /* original d221, guest PC 0x0c04e926 */
if(!s->budget--) { s->failed_pc=0x0c04e926u; return 0; }
r[2]=read(ram,0x0c04e9acu,4);
goto P_0c04e928;
P_0c04e928: /* original 420b, guest PC 0x0c04e928 */
if(!s->budget--) { s->failed_pc=0x0c04e928u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e92cu;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e92cu) { target=s->pc; goto dispatch; }
goto P_0c04e92c;
P_0c04e92a: /* original 2f86, guest PC 0x0c04e92a */
if(!s->budget--) { s->failed_pc=0x0c04e92au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e92c;
P_0c04e92c: /* original 7c01, guest PC 0x0c04e92c */
if(!s->budget--) { s->failed_pc=0x0c04e92cu; return 0; }
r[12]+=0x00000001u;
goto P_0c04e92e;
P_0c04e92e: /* original 3cd3, guest PC 0x0c04e92e */
if(!s->budget--) { s->failed_pc=0x0c04e92eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[13])!=0);
goto P_0c04e930;
P_0c04e930: /* original 8ff2, guest PC 0x0c04e930 */
if(!s->budget--) { s->failed_pc=0x0c04e930u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000010u;
if(!cond) { goto P_0c04e918; }
goto P_0c04e934;
P_0c04e932: /* original 7f10, guest PC 0x0c04e932 */
if(!s->budget--) { s->failed_pc=0x0c04e932u; return 0; }
r[15]+=0x00000010u;
goto P_0c04e934;
P_0c04e934: /* original 9c34, guest PC 0x0c04e934 */
if(!s->budget--) { s->failed_pc=0x0c04e934u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e9a0u,2);
goto P_0c04e936;
P_0c04e936: /* original ea01, guest PC 0x0c04e936 */
if(!s->budget--) { s->failed_pc=0x0c04e936u; return 0; }
r[10]=0x00000001u;
goto P_0c04e938;
P_0c04e938: /* original 2ecf, guest PC 0x0c04e938 */
if(!s->budget--) { s->failed_pc=0x0c04e938u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[12]);
goto P_0c04e93a;
P_0c04e93a: /* original 0c1a, guest PC 0x0c04e93a */
if(!s->budget--) { s->failed_pc=0x0c04e93au; return 0; }
r[12]=r[19];
goto P_0c04e93c;
P_0c04e93c: /* original 6ccf, guest PC 0x0c04e93c */
if(!s->budget--) { s->failed_pc=0x0c04e93cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04e93e;
P_0c04e93e: /* original 2fc2, guest PC 0x0c04e93e */
if(!s->budget--) { s->failed_pc=0x0c04e93eu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c04e940;
P_0c04e940: /* original d31c, guest PC 0x0c04e940 */
if(!s->budget--) { s->failed_pc=0x0c04e940u; return 0; }
r[3]=read(ram,0x0c04e9b4u,4);
goto P_0c04e942;
P_0c04e942: /* original 3c3c, guest PC 0x0c04e942 */
if(!s->budget--) { s->failed_pc=0x0c04e942u; return 0; }
r[12]+=r[3];
goto P_0c04e944;
P_0c04e944: /* original 1cac, guest PC 0x0c04e944 */
if(!s->budget--) { s->failed_pc=0x0c04e944u; return 0; }
write(ram,r[12]+48,r[10],4);
goto P_0c04e946;
P_0c04e946: /* original 52c1, guest PC 0x0c04e946 */
if(!s->budget--) { s->failed_pc=0x0c04e946u; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c04e948;
P_0c04e948: /* original d01b, guest PC 0x0c04e948 */
if(!s->budget--) { s->failed_pc=0x0c04e948u; return 0; }
r[0]=read(ram,0x0c04e9b8u,4);
goto P_0c04e94a;
P_0c04e94a: /* original 6123, guest PC 0x0c04e94a */
if(!s->budget--) { s->failed_pc=0x0c04e94au; return 0; }
r[1]=r[2];
goto P_0c04e94c;
P_0c04e94c: /* original 4208, guest PC 0x0c04e94c */
if(!s->budget--) { s->failed_pc=0x0c04e94cu; return 0; }
r[2]<<=2;
goto P_0c04e94e;
P_0c04e94e: /* original 321c, guest PC 0x0c04e94e */
if(!s->budget--) { s->failed_pc=0x0c04e94eu; return 0; }
r[2]+=r[1];
goto P_0c04e950;
P_0c04e950: /* original 4208, guest PC 0x0c04e950 */
if(!s->budget--) { s->failed_pc=0x0c04e950u; return 0; }
r[2]<<=2;
goto P_0c04e952;
P_0c04e952: /* original 4208, guest PC 0x0c04e952 */
if(!s->budget--) { s->failed_pc=0x0c04e952u; return 0; }
r[2]<<=2;
goto P_0c04e954;
P_0c04e954: /* original 622f, guest PC 0x0c04e954 */
if(!s->budget--) { s->failed_pc=0x0c04e954u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04e956;
P_0c04e956: /* original 002e, guest PC 0x0c04e956 */
if(!s->budget--) { s->failed_pc=0x0c04e956u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c04e958;
P_0c04e958: /* original 1c0d, guest PC 0x0c04e958 */
if(!s->budget--) { s->failed_pc=0x0c04e958u; return 0; }
write(ram,r[12]+52,r[0],4);
goto P_0c04e95a;
P_0c04e95a: /* original 84c2, guest PC 0x0c04e95a */
if(!s->budget--) { s->failed_pc=0x0c04e95au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+2,1);
goto P_0c04e95c;
P_0c04e95c: /* original 2008, guest PC 0x0c04e95c */
if(!s->budget--) { s->failed_pc=0x0c04e95cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e95e;
P_0c04e95e: /* original 8914, guest PC 0x0c04e95e */
if(!s->budget--) { s->failed_pc=0x0c04e95eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e98a; }
goto P_0c04e960;
P_0c04e960: /* original d316, guest PC 0x0c04e960 */
if(!s->budget--) { s->failed_pc=0x0c04e960u; return 0; }
r[3]=read(ram,0x0c04e9bcu,4);
goto P_0c04e962;
P_0c04e962: /* original 430b, guest PC 0x0c04e962 */
if(!s->budget--) { s->failed_pc=0x0c04e962u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e966u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e966u) { target=s->pc; goto dispatch; }
goto P_0c04e966;
P_0c04e964: /* original 64e3, guest PC 0x0c04e964 */
if(!s->budget--) { s->failed_pc=0x0c04e964u; return 0; }
r[4]=r[14];
goto P_0c04e966;
P_0c04e966: /* original 2008, guest PC 0x0c04e966 */
if(!s->budget--) { s->failed_pc=0x0c04e966u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e968;
P_0c04e968: /* original 8b04, guest PC 0x0c04e968 */
if(!s->budget--) { s->failed_pc=0x0c04e968u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e974; }
goto P_0c04e96a;
P_0c04e96a: /* original d315, guest PC 0x0c04e96a */
if(!s->budget--) { s->failed_pc=0x0c04e96au; return 0; }
r[3]=read(ram,0x0c04e9c0u,4);
goto P_0c04e96c;
P_0c04e96c: /* original 430b, guest PC 0x0c04e96c */
if(!s->budget--) { s->failed_pc=0x0c04e96cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e970u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e970u) { target=s->pc; goto dispatch; }
goto P_0c04e970;
P_0c04e96e: /* original 64e3, guest PC 0x0c04e96e */
if(!s->budget--) { s->failed_pc=0x0c04e96eu; return 0; }
r[4]=r[14];
goto P_0c04e970;
P_0c04e970: /* original a00b, guest PC 0x0c04e970 */
if(!s->budget--) { s->failed_pc=0x0c04e970u; return 0; }
goto P_0c04e98a;
P_0c04e972: /* original 0009, guest PC 0x0c04e972 */
if(!s->budget--) { s->failed_pc=0x0c04e972u; return 0; }
goto P_0c04e974;
P_0c04e974: /* original d213, guest PC 0x0c04e974 */
if(!s->budget--) { s->failed_pc=0x0c04e974u; return 0; }
r[2]=read(ram,0x0c04e9c4u,4);
goto P_0c04e976;
P_0c04e976: /* original 420b, guest PC 0x0c04e976 */
if(!s->budget--) { s->failed_pc=0x0c04e976u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e97au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e97au) { target=s->pc; goto dispatch; }
goto P_0c04e97a;
P_0c04e978: /* original 64e3, guest PC 0x0c04e978 */
if(!s->budget--) { s->failed_pc=0x0c04e978u; return 0; }
r[4]=r[14];
goto P_0c04e97a;
P_0c04e97a: /* original 2008, guest PC 0x0c04e97a */
if(!s->budget--) { s->failed_pc=0x0c04e97au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e97c;
P_0c04e97c: /* original 8905, guest PC 0x0c04e97c */
if(!s->budget--) { s->failed_pc=0x0c04e97cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e98a; }
goto P_0c04e97e;
P_0c04e97e: /* original 62f2, guest PC 0x0c04e97e */
if(!s->budget--) { s->failed_pc=0x0c04e97eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04e980;
P_0c04e980: /* original d30c, guest PC 0x0c04e980 */
if(!s->budget--) { s->failed_pc=0x0c04e980u; return 0; }
r[3]=read(ram,0x0c04e9b4u,4);
goto P_0c04e982;
P_0c04e982: /* original 323c, guest PC 0x0c04e982 */
if(!s->budget--) { s->failed_pc=0x0c04e982u; return 0; }
r[2]+=r[3];
goto P_0c04e984;
P_0c04e984: /* original 8428, guest PC 0x0c04e984 */
if(!s->budget--) { s->failed_pc=0x0c04e984u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04e986;
P_0c04e986: /* original 2008, guest PC 0x0c04e986 */
if(!s->budget--) { s->failed_pc=0x0c04e986u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e988;
P_0c04e988: /* original 8b02, guest PC 0x0c04e988 */
if(!s->budget--) { s->failed_pc=0x0c04e988u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e990; }
goto P_0c04e98a;
P_0c04e98a: /* original 900a, guest PC 0x0c04e98a */
if(!s->budget--) { s->failed_pc=0x0c04e98au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e9a2u,2);
goto P_0c04e98c;
P_0c04e98c: /* original a04f, guest PC 0x0c04e98c */
if(!s->budget--) { s->failed_pc=0x0c04e98cu; return 0; }
goto P_0c04ea2e;
P_0c04e98e: /* original 0009, guest PC 0x0c04e98e */
if(!s->budget--) { s->failed_pc=0x0c04e98eu; return 0; }
goto P_0c04e990;
P_0c04e990: /* original d30d, guest PC 0x0c04e990 */
if(!s->budget--) { s->failed_pc=0x0c04e990u; return 0; }
r[3]=read(ram,0x0c04e9c8u,4);
goto P_0c04e992;
P_0c04e992: /* original 430b, guest PC 0x0c04e992 */
if(!s->budget--) { s->failed_pc=0x0c04e992u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e996u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e996u) { target=s->pc; goto dispatch; }
goto P_0c04e996;
P_0c04e994: /* original 64e3, guest PC 0x0c04e994 */
if(!s->budget--) { s->failed_pc=0x0c04e994u; return 0; }
r[4]=r[14];
goto P_0c04e996;
P_0c04e996: /* original 4011, guest PC 0x0c04e996 */
if(!s->budget--) { s->failed_pc=0x0c04e996u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e998;
P_0c04e998: /* original 8918, guest PC 0x0c04e998 */
if(!s->budget--) { s->failed_pc=0x0c04e998u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e9cc; }
goto P_0c04e99a;
P_0c04e99a: /* original 9003, guest PC 0x0c04e99a */
if(!s->budget--) { s->failed_pc=0x0c04e99au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e9a4u,2);
goto P_0c04e99c;
P_0c04e99c: /* original a047, guest PC 0x0c04e99c */
if(!s->budget--) { s->failed_pc=0x0c04e99cu; return 0; }
goto P_0c04ea2e;
P_0c04e99e: /* original 0009, guest PC 0x0c04e99e */
if(!s->budget--) { s->failed_pc=0x0c04e99eu; return 0; }
return vf3_matrix_family(0x0c04e9a0u,s,ram);
P_0c04e9cc: /* original 4d15, guest PC 0x0c04e9cc */
if(!s->budget--) { s->failed_pc=0x0c04e9ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c04e9ce;
P_0c04e9ce: /* original 6893, guest PC 0x0c04e9ce */
if(!s->budget--) { s->failed_pc=0x0c04e9ceu; return 0; }
r[8]=r[9];
goto P_0c04e9d0;
P_0c04e9d0: /* original 8f0a, guest PC 0x0c04e9d0 */
if(!s->budget--) { s->failed_pc=0x0c04e9d0u; return 0; }
cond=r[17]&1u;
r[12]=r[11];
if(!cond) { goto P_0c04e9e8; }
goto P_0c04e9d4;
P_0c04e9d2: /* original 6cb3, guest PC 0x0c04e9d2 */
if(!s->budget--) { s->failed_pc=0x0c04e9d2u; return 0; }
r[12]=r[11];
goto P_0c04e9d4;
P_0c04e9d4: /* original d235, guest PC 0x0c04e9d4 */
if(!s->budget--) { s->failed_pc=0x0c04e9d4u; return 0; }
r[2]=read(ram,0x0c04eaacu,4);
goto P_0c04e9d6;
P_0c04e9d6: /* original 65c2, guest PC 0x0c04e9d6 */
if(!s->budget--) { s->failed_pc=0x0c04e9d6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c04e9d8;
P_0c04e9d8: /* original 420b, guest PC 0x0c04e9d8 */
if(!s->budget--) { s->failed_pc=0x0c04e9d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e9dcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e9dcu) { target=s->pc; goto dispatch; }
goto P_0c04e9dc;
P_0c04e9da: /* original 64e3, guest PC 0x0c04e9da */
if(!s->budget--) { s->failed_pc=0x0c04e9dau; return 0; }
r[4]=r[14];
goto P_0c04e9dc;
P_0c04e9dc: /* original 4011, guest PC 0x0c04e9dc */
if(!s->budget--) { s->failed_pc=0x0c04e9dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e9de;
P_0c04e9de: /* original 8b22, guest PC 0x0c04e9de */
if(!s->budget--) { s->failed_pc=0x0c04e9deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ea26; }
goto P_0c04e9e0;
P_0c04e9e0: /* original 7801, guest PC 0x0c04e9e0 */
if(!s->budget--) { s->failed_pc=0x0c04e9e0u; return 0; }
r[8]+=0x00000001u;
goto P_0c04e9e2;
P_0c04e9e2: /* original 38d3, guest PC 0x0c04e9e2 */
if(!s->budget--) { s->failed_pc=0x0c04e9e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[13])!=0);
goto P_0c04e9e4;
P_0c04e9e4: /* original 8ff6, guest PC 0x0c04e9e4 */
if(!s->budget--) { s->failed_pc=0x0c04e9e4u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c04e9d4; }
goto P_0c04e9e8;
P_0c04e9e6: /* original 7c04, guest PC 0x0c04e9e6 */
if(!s->budget--) { s->failed_pc=0x0c04e9e6u; return 0; }
r[12]+=0x00000004u;
goto P_0c04e9e8;
P_0c04e9e8: /* original 4d15, guest PC 0x0c04e9e8 */
if(!s->budget--) { s->failed_pc=0x0c04e9e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c04e9ea;
P_0c04e9ea: /* original 6893, guest PC 0x0c04e9ea */
if(!s->budget--) { s->failed_pc=0x0c04e9eau; return 0; }
r[8]=r[9];
goto P_0c04e9ec;
P_0c04e9ec: /* original 2f92, guest PC 0x0c04e9ec */
if(!s->budget--) { s->failed_pc=0x0c04e9ecu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c04e9ee;
P_0c04e9ee: /* original 8f0a, guest PC 0x0c04e9ee */
if(!s->budget--) { s->failed_pc=0x0c04e9eeu; return 0; }
cond=r[17]&1u;
r[12]=r[11];
if(!cond) { goto P_0c04ea06; }
goto P_0c04e9f2;
P_0c04e9f0: /* original 6cb3, guest PC 0x0c04e9f0 */
if(!s->budget--) { s->failed_pc=0x0c04e9f0u; return 0; }
r[12]=r[11];
goto P_0c04e9f2;
P_0c04e9f2: /* original 65c2, guest PC 0x0c04e9f2 */
if(!s->budget--) { s->failed_pc=0x0c04e9f2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c04e9f4;
P_0c04e9f4: /* original be8d, guest PC 0x0c04e9f4 */
if(!s->budget--) { s->failed_pc=0x0c04e9f4u; return 0; }
target=0x0c04e712u; r[16]=code_base|0x0c04e9f8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e9f8u) { target=s->pc; goto dispatch; }
goto P_0c04e9f8;
P_0c04e9f6: /* original 64e3, guest PC 0x0c04e9f6 */
if(!s->budget--) { s->failed_pc=0x0c04e9f6u; return 0; }
r[4]=r[14];
goto P_0c04e9f8;
P_0c04e9f8: /* original 4011, guest PC 0x0c04e9f8 */
if(!s->budget--) { s->failed_pc=0x0c04e9f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e9fa;
P_0c04e9fa: /* original 8d01, guest PC 0x0c04e9fa */
if(!s->budget--) { s->failed_pc=0x0c04e9fau; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c04ea00; }
goto P_0c04e9fe;
P_0c04e9fc: /* original 7801, guest PC 0x0c04e9fc */
if(!s->budget--) { s->failed_pc=0x0c04e9fcu; return 0; }
r[8]+=0x00000001u;
goto P_0c04e9fe;
P_0c04e9fe: /* original 2fa2, guest PC 0x0c04e9fe */
if(!s->budget--) { s->failed_pc=0x0c04e9feu; return 0; }
write(ram,r[15],r[10],4);
goto P_0c04ea00;
P_0c04ea00: /* original 38d3, guest PC 0x0c04ea00 */
if(!s->budget--) { s->failed_pc=0x0c04ea00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[13])!=0);
goto P_0c04ea02;
P_0c04ea02: /* original 8ff6, guest PC 0x0c04ea02 */
if(!s->budget--) { s->failed_pc=0x0c04ea02u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c04e9f2; }
goto P_0c04ea06;
P_0c04ea04: /* original 7c04, guest PC 0x0c04ea04 */
if(!s->budget--) { s->failed_pc=0x0c04ea04u; return 0; }
r[12]+=0x00000004u;
goto P_0c04ea06;
P_0c04ea06: /* original b6a2, guest PC 0x0c04ea06 */
if(!s->budget--) { s->failed_pc=0x0c04ea06u; return 0; }
target=0x0c04f74eu; r[16]=code_base|0x0c04ea0au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ea0au) { target=s->pc; goto dispatch; }
goto P_0c04ea0a;
P_0c04ea08: /* original 64e3, guest PC 0x0c04ea08 */
if(!s->budget--) { s->failed_pc=0x0c04ea08u; return 0; }
r[4]=r[14];
goto P_0c04ea0a;
P_0c04ea0a: /* original 4011, guest PC 0x0c04ea0a */
if(!s->budget--) { s->failed_pc=0x0c04ea0au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ea0c;
P_0c04ea0c: /* original 8f06, guest PC 0x0c04ea0c */
if(!s->budget--) { s->failed_pc=0x0c04ea0cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c04ea1c; }
goto P_0c04ea10;
P_0c04ea0e: /* original 6403, guest PC 0x0c04ea0e */
if(!s->budget--) { s->failed_pc=0x0c04ea0eu; return 0; }
r[4]=r[0];
goto P_0c04ea10;
P_0c04ea10: /* original d327, guest PC 0x0c04ea10 */
if(!s->budget--) { s->failed_pc=0x0c04ea10u; return 0; }
r[3]=read(ram,0x0c04eab0u,4);
goto P_0c04ea12;
P_0c04ea12: /* original 430b, guest PC 0x0c04ea12 */
if(!s->budget--) { s->failed_pc=0x0c04ea12u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ea16u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ea16u) { target=s->pc; goto dispatch; }
goto P_0c04ea16;
P_0c04ea14: /* original 64e3, guest PC 0x0c04ea14 */
if(!s->budget--) { s->failed_pc=0x0c04ea14u; return 0; }
r[4]=r[14];
goto P_0c04ea16;
P_0c04ea16: /* original 4011, guest PC 0x0c04ea16 */
if(!s->budget--) { s->failed_pc=0x0c04ea16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ea18;
P_0c04ea18: /* original 8d02, guest PC 0x0c04ea18 */
if(!s->budget--) { s->failed_pc=0x0c04ea18u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04ea20; }
goto P_0c04ea1c;
P_0c04ea1a: /* original 6403, guest PC 0x0c04ea1a */
if(!s->budget--) { s->failed_pc=0x0c04ea1au; return 0; }
r[4]=r[0];
goto P_0c04ea1c;
P_0c04ea1c: /* original a007, guest PC 0x0c04ea1c */
if(!s->budget--) { s->failed_pc=0x0c04ea1cu; return 0; }
r[0]=r[4];
goto P_0c04ea2e;
P_0c04ea1e: /* original 6043, guest PC 0x0c04ea1e */
if(!s->budget--) { s->failed_pc=0x0c04ea1eu; return 0; }
r[0]=r[4];
goto P_0c04ea20;
P_0c04ea20: /* original 63f2, guest PC 0x0c04ea20 */
if(!s->budget--) { s->failed_pc=0x0c04ea20u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04ea22;
P_0c04ea22: /* original 2338, guest PC 0x0c04ea22 */
if(!s->budget--) { s->failed_pc=0x0c04ea22u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04ea24;
P_0c04ea24: /* original 8902, guest PC 0x0c04ea24 */
if(!s->budget--) { s->failed_pc=0x0c04ea24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ea2c; }
goto P_0c04ea26;
P_0c04ea26: /* original 903f, guest PC 0x0c04ea26 */
if(!s->budget--) { s->failed_pc=0x0c04ea26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04eaa8u,2);
goto P_0c04ea28;
P_0c04ea28: /* original a001, guest PC 0x0c04ea28 */
if(!s->budget--) { s->failed_pc=0x0c04ea28u; return 0; }
goto P_0c04ea2e;
P_0c04ea2a: /* original 0009, guest PC 0x0c04ea2a */
if(!s->budget--) { s->failed_pc=0x0c04ea2au; return 0; }
goto P_0c04ea2c;
P_0c04ea2c: /* original e000, guest PC 0x0c04ea2c */
if(!s->budget--) { s->failed_pc=0x0c04ea2cu; return 0; }
r[0]=0x00000000u;
goto P_0c04ea2e;
P_0c04ea2e: /* original 7f04, guest PC 0x0c04ea2e */
if(!s->budget--) { s->failed_pc=0x0c04ea2eu; return 0; }
r[15]+=0x00000004u;
goto P_0c04ea30;
P_0c04ea30: /* original 4f16, guest PC 0x0c04ea30 */
if(!s->budget--) { s->failed_pc=0x0c04ea30u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ea32;
P_0c04ea32: /* original 4f26, guest PC 0x0c04ea32 */
if(!s->budget--) { s->failed_pc=0x0c04ea32u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ea34;
P_0c04ea34: /* original 68f6, guest PC 0x0c04ea34 */
if(!s->budget--) { s->failed_pc=0x0c04ea34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04ea36;
P_0c04ea36: /* original 69f6, guest PC 0x0c04ea36 */
if(!s->budget--) { s->failed_pc=0x0c04ea36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04ea38;
P_0c04ea38: /* original 6af6, guest PC 0x0c04ea38 */
if(!s->budget--) { s->failed_pc=0x0c04ea38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04ea3a;
P_0c04ea3a: /* original 6bf6, guest PC 0x0c04ea3a */
if(!s->budget--) { s->failed_pc=0x0c04ea3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04ea3c;
P_0c04ea3c: /* original 6cf6, guest PC 0x0c04ea3c */
if(!s->budget--) { s->failed_pc=0x0c04ea3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04ea3e;
P_0c04ea3e: /* original 6df6, guest PC 0x0c04ea3e */
if(!s->budget--) { s->failed_pc=0x0c04ea3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04ea40;
P_0c04ea40: /* original 000b, guest PC 0x0c04ea40 */
if(!s->budget--) { s->failed_pc=0x0c04ea40u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04ea42: /* original 6ef6, guest PC 0x0c04ea42 */
if(!s->budget--) { s->failed_pc=0x0c04ea42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04ea44u,s,ram);
P_0c04f620: /* original 2fe6, guest PC 0x0c04f620 */
if(!s->budget--) { s->failed_pc=0x0c04f620u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f622;
P_0c04f622: /* original 6e43, guest PC 0x0c04f622 */
if(!s->budget--) { s->failed_pc=0x0c04f622u; return 0; }
r[14]=r[4];
goto P_0c04f624;
P_0c04f624: /* original 2fd6, guest PC 0x0c04f624 */
if(!s->budget--) { s->failed_pc=0x0c04f624u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f626;
P_0c04f626: /* original 2fc6, guest PC 0x0c04f626 */
if(!s->budget--) { s->failed_pc=0x0c04f626u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f628;
P_0c04f628: /* original 2fb6, guest PC 0x0c04f628 */
if(!s->budget--) { s->failed_pc=0x0c04f628u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f62a;
P_0c04f62a: /* original eb00, guest PC 0x0c04f62a */
if(!s->budget--) { s->failed_pc=0x0c04f62au; return 0; }
r[11]=0x00000000u;
goto P_0c04f62c;
P_0c04f62c: /* original 2fa6, guest PC 0x0c04f62c */
if(!s->budget--) { s->failed_pc=0x0c04f62cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f62e;
P_0c04f62e: /* original 2f96, guest PC 0x0c04f62e */
if(!s->budget--) { s->failed_pc=0x0c04f62eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f630;
P_0c04f630: /* original 2f86, guest PC 0x0c04f630 */
if(!s->budget--) { s->failed_pc=0x0c04f630u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c04f632u,s,ram);
P_0c052f36: /* original 4f22, guest PC 0x0c052f36 */
if(!s->budget--) { s->failed_pc=0x0c052f36u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c052f38;
P_0c052f38: /* original 7fd4, guest PC 0x0c052f38 */
if(!s->budget--) { s->failed_pc=0x0c052f38u; return 0; }
r[15]+=0xffffffd4u;
goto P_0c052f3a;
P_0c052f3a: /* original 69f3, guest PC 0x0c052f3a */
if(!s->budget--) { s->failed_pc=0x0c052f3au; return 0; }
r[9]=r[15];
goto P_0c052f3c;
P_0c052f3c: /* original 1f53, guest PC 0x0c052f3c */
if(!s->budget--) { s->failed_pc=0x0c052f3cu; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c052f3e;
P_0c052f3e: /* original 7924, guest PC 0x0c052f3e */
if(!s->budget--) { s->failed_pc=0x0c052f3eu; return 0; }
r[9]+=0x00000024u;
goto P_0c052f40;
P_0c052f40: /* original 2f62, guest PC 0x0c052f40 */
if(!s->budget--) { s->failed_pc=0x0c052f40u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c052f42;
P_0c052f42: /* original 6543, guest PC 0x0c052f42 */
if(!s->budget--) { s->failed_pc=0x0c052f42u; return 0; }
r[5]=r[4];
goto P_0c052f44;
P_0c052f44: /* original 1f36, guest PC 0x0c052f44 */
if(!s->budget--) { s->failed_pc=0x0c052f44u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c052f46;
P_0c052f46: /* original e608, guest PC 0x0c052f46 */
if(!s->budget--) { s->failed_pc=0x0c052f46u; return 0; }
r[6]=0x00000008u;
goto P_0c052f48;
P_0c052f48: /* original 53f3, guest PC 0x0c052f48 */
if(!s->budget--) { s->failed_pc=0x0c052f48u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c052f4a;
P_0c052f4a: /* original 6bf2, guest PC 0x0c052f4a */
if(!s->budget--) { s->failed_pc=0x0c052f4au; return 0; }
tmp=read(ram,r[15],4);
r[11]=tmp;
goto P_0c052f4c;
P_0c052f4c: /* original 3b3c, guest PC 0x0c052f4c */
if(!s->budget--) { s->failed_pc=0x0c052f4cu; return 0; }
r[11]+=r[3];
goto P_0c052f4e;
P_0c052f4e: /* original 2b20, guest PC 0x0c052f4e */
if(!s->budget--) { s->failed_pc=0x0c052f4eu; return 0; }
write(ram,r[11],r[2],1);
goto P_0c052f50;
P_0c052f50: /* original d33c, guest PC 0x0c052f50 */
if(!s->budget--) { s->failed_pc=0x0c052f50u; return 0; }
r[3]=read(ram,0x0c053044u,4);
goto P_0c052f52;
P_0c052f52: /* original 430b, guest PC 0x0c052f52 */
if(!s->budget--) { s->failed_pc=0x0c052f52u; return 0; }
target=r[3];
r[16]=code_base|0x0c052f56u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052f56u) { target=s->pc; goto dispatch; }
goto P_0c052f56;
P_0c052f54: /* original 6493, guest PC 0x0c052f54 */
if(!s->budget--) { s->failed_pc=0x0c052f54u; return 0; }
r[4]=r[9];
goto P_0c052f56;
P_0c052f56: /* original e808, guest PC 0x0c052f56 */
if(!s->budget--) { s->failed_pc=0x0c052f56u; return 0; }
r[8]=0x00000008u;
goto P_0c052f58;
P_0c052f58: /* original 62f2, guest PC 0x0c052f58 */
if(!s->budget--) { s->failed_pc=0x0c052f58u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c052f5a;
P_0c052f5a: /* original 6cf3, guest PC 0x0c052f5a */
if(!s->budget--) { s->failed_pc=0x0c052f5au; return 0; }
r[12]=r[15];
goto P_0c052f5c;
P_0c052f5c: /* original d33a, guest PC 0x0c052f5c */
if(!s->budget--) { s->failed_pc=0x0c052f5cu; return 0; }
r[3]=read(ram,0x0c053048u,4);
goto P_0c052f5e;
P_0c052f5e: /* original 72ff, guest PC 0x0c052f5e */
if(!s->budget--) { s->failed_pc=0x0c052f5eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c052f60;
P_0c052f60: /* original 1f21, guest PC 0x0c052f60 */
if(!s->budget--) { s->failed_pc=0x0c052f60u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c052f62;
P_0c052f62: /* original 7c1c, guest PC 0x0c052f62 */
if(!s->budget--) { s->failed_pc=0x0c052f62u; return 0; }
r[12]+=0x0000001cu;
goto P_0c052f64;
P_0c052f64: /* original 4208, guest PC 0x0c052f64 */
if(!s->budget--) { s->failed_pc=0x0c052f64u; return 0; }
r[2]<<=2;
goto P_0c052f66;
P_0c052f66: /* original 4200, guest PC 0x0c052f66 */
if(!s->budget--) { s->failed_pc=0x0c052f66u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c052f68;
P_0c052f68: /* original 323c, guest PC 0x0c052f68 */
if(!s->budget--) { s->failed_pc=0x0c052f68u; return 0; }
r[2]+=r[3];
goto P_0c052f6a;
P_0c052f6a: /* original 1f25, guest PC 0x0c052f6a */
if(!s->budget--) { s->failed_pc=0x0c052f6au; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c052f6c;
P_0c052f6c: /* original 53f1, guest PC 0x0c052f6c */
if(!s->budget--) { s->failed_pc=0x0c052f6cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c052f6e;
P_0c052f6e: /* original 7301, guest PC 0x0c052f6e */
if(!s->budget--) { s->failed_pc=0x0c052f6eu; return 0; }
r[3]+=0x00000001u;
goto P_0c052f70;
P_0c052f70: /* original a059, guest PC 0x0c052f70 */
if(!s->budget--) { s->failed_pc=0x0c052f70u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c053026;
P_0c052f72: /* original 1f34, guest PC 0x0c052f72 */
if(!s->budget--) { s->failed_pc=0x0c052f72u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c052f74;
P_0c052f74: /* original 51f4, guest PC 0x0c052f74 */
if(!s->budget--) { s->failed_pc=0x0c052f74u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c052f76;
P_0c052f76: /* original d335, guest PC 0x0c052f76 */
if(!s->budget--) { s->failed_pc=0x0c052f76u; return 0; }
r[3]=read(ram,0x0c05304cu,4);
goto P_0c052f78;
P_0c052f78: /* original 430b, guest PC 0x0c052f78 */
if(!s->budget--) { s->failed_pc=0x0c052f78u; return 0; }
target=r[3];
r[16]=code_base|0x0c052f7cu;
r[0]=0x00000005u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052f7cu) { target=s->pc; goto dispatch; }
goto P_0c052f7c;
P_0c052f7a: /* original e005, guest PC 0x0c052f7a */
if(!s->budget--) { s->failed_pc=0x0c052f7au; return 0; }
r[0]=0x00000005u;
goto P_0c052f7c;
P_0c052f7c: /* original 55f5, guest PC 0x0c052f7c */
if(!s->budget--) { s->failed_pc=0x0c052f7cu; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c052f7e;
P_0c052f7e: /* original 7001, guest PC 0x0c052f7e */
if(!s->budget--) { s->failed_pc=0x0c052f7eu; return 0; }
r[0]+=0x00000001u;
goto P_0c052f80;
P_0c052f80: /* original d330, guest PC 0x0c052f80 */
if(!s->budget--) { s->failed_pc=0x0c052f80u; return 0; }
r[3]=read(ram,0x0c053044u,4);
goto P_0c052f82;
P_0c052f82: /* original 6e83, guest PC 0x0c052f82 */
if(!s->budget--) { s->failed_pc=0x0c052f82u; return 0; }
r[14]=r[8];
goto P_0c052f84;
P_0c052f84: /* original 4000, guest PC 0x0c052f84 */
if(!s->budget--) { s->failed_pc=0x0c052f84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c052f86;
P_0c052f86: /* original 3e08, guest PC 0x0c052f86 */
if(!s->budget--) { s->failed_pc=0x0c052f86u; return 0; }
r[14]-=r[0];
goto P_0c052f88;
P_0c052f88: /* original 6d83, guest PC 0x0c052f88 */
if(!s->budget--) { s->failed_pc=0x0c052f88u; return 0; }
r[13]=r[8];
goto P_0c052f8a;
P_0c052f8a: /* original 3de8, guest PC 0x0c052f8a */
if(!s->budget--) { s->failed_pc=0x0c052f8au; return 0; }
r[13]-=r[14];
goto P_0c052f8c;
P_0c052f8c: /* original 66d3, guest PC 0x0c052f8c */
if(!s->budget--) { s->failed_pc=0x0c052f8cu; return 0; }
r[6]=r[13];
goto P_0c052f8e;
P_0c052f8e: /* original 35ec, guest PC 0x0c052f8e */
if(!s->budget--) { s->failed_pc=0x0c052f8eu; return 0; }
r[5]+=r[14];
goto P_0c052f90;
P_0c052f90: /* original 64e3, guest PC 0x0c052f90 */
if(!s->budget--) { s->failed_pc=0x0c052f90u; return 0; }
r[4]=r[14];
goto P_0c052f92;
P_0c052f92: /* original 430b, guest PC 0x0c052f92 */
if(!s->budget--) { s->failed_pc=0x0c052f92u; return 0; }
target=r[3];
r[16]=code_base|0x0c052f96u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052f96u) { target=s->pc; goto dispatch; }
goto P_0c052f96;
P_0c052f94: /* original 34cc, guest PC 0x0c052f94 */
if(!s->budget--) { s->failed_pc=0x0c052f94u; return 0; }
r[4]+=r[12];
goto P_0c052f96;
P_0c052f96: /* original ea08, guest PC 0x0c052f96 */
if(!s->budget--) { s->failed_pc=0x0c052f96u; return 0; }
r[10]=0x00000008u;
goto P_0c052f98;
P_0c052f98: /* original e200, guest PC 0x0c052f98 */
if(!s->budget--) { s->failed_pc=0x0c052f98u; return 0; }
r[2]=0x00000000u;
goto P_0c052f9a;
P_0c052f9a: /* original 6323, guest PC 0x0c052f9a */
if(!s->budget--) { s->failed_pc=0x0c052f9au; return 0; }
r[3]=r[2];
goto P_0c052f9c;
P_0c052f9c: /* original 1f22, guest PC 0x0c052f9c */
if(!s->budget--) { s->failed_pc=0x0c052f9cu; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c052f9e;
P_0c052f9e: /* original 2f32, guest PC 0x0c052f9e */
if(!s->budget--) { s->failed_pc=0x0c052f9eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c052fa0;
P_0c052fa0: /* original d32b, guest PC 0x0c052fa0 */
if(!s->budget--) { s->failed_pc=0x0c052fa0u; return 0; }
r[3]=read(ram,0x0c053050u,4);
goto P_0c052fa2;
P_0c052fa2: /* original 66d3, guest PC 0x0c052fa2 */
if(!s->budget--) { s->failed_pc=0x0c052fa2u; return 0; }
r[6]=r[13];
goto P_0c052fa4;
P_0c052fa4: /* original 65e3, guest PC 0x0c052fa4 */
if(!s->budget--) { s->failed_pc=0x0c052fa4u; return 0; }
r[5]=r[14];
goto P_0c052fa6;
P_0c052fa6: /* original 35cc, guest PC 0x0c052fa6 */
if(!s->budget--) { s->failed_pc=0x0c052fa6u; return 0; }
r[5]+=r[12];
goto P_0c052fa8;
P_0c052fa8: /* original 64e3, guest PC 0x0c052fa8 */
if(!s->budget--) { s->failed_pc=0x0c052fa8u; return 0; }
r[4]=r[14];
goto P_0c052faa;
P_0c052faa: /* original 430b, guest PC 0x0c052faa */
if(!s->budget--) { s->failed_pc=0x0c052faau; return 0; }
target=r[3];
r[16]=code_base|0x0c052faeu;
r[4]+=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052faeu) { target=s->pc; goto dispatch; }
goto P_0c052fae;
P_0c052fac: /* original 349c, guest PC 0x0c052fac */
if(!s->budget--) { s->failed_pc=0x0c052facu; return 0; }
r[4]+=r[9];
goto P_0c052fae;
P_0c052fae: /* original 4011, guest PC 0x0c052fae */
if(!s->budget--) { s->failed_pc=0x0c052faeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c052fb0;
P_0c052fb0: /* original 8f0c, guest PC 0x0c052fb0 */
if(!s->budget--) { s->failed_pc=0x0c052fb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c052fcc; }
goto P_0c052fb4;
P_0c052fb2: /* original 0009, guest PC 0x0c052fb2 */
if(!s->budget--) { s->failed_pc=0x0c052fb2u; return 0; }
goto P_0c052fb4;
P_0c052fb4: /* original d327, guest PC 0x0c052fb4 */
if(!s->budget--) { s->failed_pc=0x0c052fb4u; return 0; }
r[3]=read(ram,0x0c053054u,4);
goto P_0c052fb6;
P_0c052fb6: /* original 67d3, guest PC 0x0c052fb6 */
if(!s->budget--) { s->failed_pc=0x0c052fb6u; return 0; }
r[7]=r[13];
goto P_0c052fb8;
P_0c052fb8: /* original 66e3, guest PC 0x0c052fb8 */
if(!s->budget--) { s->failed_pc=0x0c052fb8u; return 0; }
r[6]=r[14];
goto P_0c052fba;
P_0c052fba: /* original 36cc, guest PC 0x0c052fba */
if(!s->budget--) { s->failed_pc=0x0c052fbau; return 0; }
r[6]+=r[12];
goto P_0c052fbc;
P_0c052fbc: /* original 65e3, guest PC 0x0c052fbc */
if(!s->budget--) { s->failed_pc=0x0c052fbcu; return 0; }
r[5]=r[14];
goto P_0c052fbe;
P_0c052fbe: /* original 359c, guest PC 0x0c052fbe */
if(!s->budget--) { s->failed_pc=0x0c052fbeu; return 0; }
r[5]+=r[9];
goto P_0c052fc0;
P_0c052fc0: /* original 430b, guest PC 0x0c052fc0 */
if(!s->budget--) { s->failed_pc=0x0c052fc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c052fc4u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052fc4u) { target=s->pc; goto dispatch; }
goto P_0c052fc4;
P_0c052fc2: /* original e400, guest PC 0x0c052fc2 */
if(!s->budget--) { s->failed_pc=0x0c052fc2u; return 0; }
r[4]=0x00000000u;
goto P_0c052fc4;
P_0c052fc4: /* original 1f06, guest PC 0x0c052fc4 */
if(!s->budget--) { s->failed_pc=0x0c052fc4u; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c052fc6;
P_0c052fc6: /* original 53f2, guest PC 0x0c052fc6 */
if(!s->budget--) { s->failed_pc=0x0c052fc6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c052fc8;
P_0c052fc8: /* original 33ac, guest PC 0x0c052fc8 */
if(!s->budget--) { s->failed_pc=0x0c052fc8u; return 0; }
r[3]+=r[10];
goto P_0c052fca;
P_0c052fca: /* original 1f32, guest PC 0x0c052fca */
if(!s->budget--) { s->failed_pc=0x0c052fcau; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c052fcc;
P_0c052fcc: /* original e300, guest PC 0x0c052fcc */
if(!s->budget--) { s->failed_pc=0x0c052fccu; return 0; }
r[3]=0x00000000u;
goto P_0c052fce;
P_0c052fce: /* original 33a7, guest PC 0x0c052fce */
if(!s->budget--) { s->failed_pc=0x0c052fceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[10])!=0);
goto P_0c052fd0;
P_0c052fd0: /* original 3a3e, guest PC 0x0c052fd0 */
if(!s->budget--) { s->failed_pc=0x0c052fd0u; return 0; }
wide=(uint64_t)r[10]+r[3]+(r[17]&1u); r[10]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c052fd2;
P_0c052fd2: /* original 4a21, guest PC 0x0c052fd2 */
if(!s->budget--) { s->failed_pc=0x0c052fd2u; return 0; }
r[17]=(r[17]&~1u)|((r[10]&1)!=0);
r[10]=(uint32_t)((int32_t)r[10]>>1);
goto P_0c052fd4;
P_0c052fd4: /* original 2aa8, guest PC 0x0c052fd4 */
if(!s->budget--) { s->failed_pc=0x0c052fd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c052fd6;
P_0c052fd6: /* original 8d0c, guest PC 0x0c052fd6 */
if(!s->budget--) { s->failed_pc=0x0c052fd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c052ff2; }
goto P_0c052fda;
P_0c052fd8: /* original 0009, guest PC 0x0c052fd8 */
if(!s->budget--) { s->failed_pc=0x0c052fd8u; return 0; }
goto P_0c052fda;
P_0c052fda: /* original e601, guest PC 0x0c052fda */
if(!s->budget--) { s->failed_pc=0x0c052fdau; return 0; }
r[6]=0x00000001u;
goto P_0c052fdc;
P_0c052fdc: /* original d31e, guest PC 0x0c052fdc */
if(!s->budget--) { s->failed_pc=0x0c052fdcu; return 0; }
r[3]=read(ram,0x0c053058u,4);
goto P_0c052fde;
P_0c052fde: /* original 65d3, guest PC 0x0c052fde */
if(!s->budget--) { s->failed_pc=0x0c052fdeu; return 0; }
r[5]=r[13];
goto P_0c052fe0;
P_0c052fe0: /* original 64e3, guest PC 0x0c052fe0 */
if(!s->budget--) { s->failed_pc=0x0c052fe0u; return 0; }
r[4]=r[14];
goto P_0c052fe2;
P_0c052fe2: /* original 430b, guest PC 0x0c052fe2 */
if(!s->budget--) { s->failed_pc=0x0c052fe2u; return 0; }
target=r[3];
r[16]=code_base|0x0c052fe6u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052fe6u) { target=s->pc; goto dispatch; }
goto P_0c052fe6;
P_0c052fe4: /* original 34cc, guest PC 0x0c052fe4 */
if(!s->budget--) { s->failed_pc=0x0c052fe4u; return 0; }
r[4]+=r[12];
goto P_0c052fe6;
P_0c052fe6: /* original e304, guest PC 0x0c052fe6 */
if(!s->budget--) { s->failed_pc=0x0c052fe6u; return 0; }
r[3]=0x00000004u;
goto P_0c052fe8;
P_0c052fe8: /* original 62f2, guest PC 0x0c052fe8 */
if(!s->budget--) { s->failed_pc=0x0c052fe8u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c052fea;
P_0c052fea: /* original 7201, guest PC 0x0c052fea */
if(!s->budget--) { s->failed_pc=0x0c052feau; return 0; }
r[2]+=0x00000001u;
goto P_0c052fec;
P_0c052fec: /* original 3233, guest PC 0x0c052fec */
if(!s->budget--) { s->failed_pc=0x0c052fecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c052fee;
P_0c052fee: /* original 8fd7, guest PC 0x0c052fee */
if(!s->budget--) { s->failed_pc=0x0c052feeu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(!cond) { goto P_0c052fa0; }
goto P_0c052ff2;
P_0c052ff0: /* original 2f22, guest PC 0x0c052ff0 */
if(!s->budget--) { s->failed_pc=0x0c052ff0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c052ff2;
P_0c052ff2: /* original 54f2, guest PC 0x0c052ff2 */
if(!s->budget--) { s->failed_pc=0x0c052ff2u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c052ff4;
P_0c052ff4: /* original 53f6, guest PC 0x0c052ff4 */
if(!s->budget--) { s->failed_pc=0x0c052ff4u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c052ff6;
P_0c052ff6: /* original 2338, guest PC 0x0c052ff6 */
if(!s->budget--) { s->failed_pc=0x0c052ff6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c052ff8;
P_0c052ff8: /* original 8f0b, guest PC 0x0c052ff8 */
if(!s->budget--) { s->failed_pc=0x0c052ff8u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000030u;
if(!cond) { goto P_0c053012; }
goto P_0c052ffc;
P_0c052ffa: /* original 7430, guest PC 0x0c052ffa */
if(!s->budget--) { s->failed_pc=0x0c052ffau; return 0; }
r[4]+=0x00000030u;
goto P_0c052ffc;
P_0c052ffc: /* original a002, guest PC 0x0c052ffc */
if(!s->budget--) { s->failed_pc=0x0c052ffcu; return 0; }
tmp=r[4]; r[11]-=1; write(ram,r[11],tmp,1);
goto P_0c053004;
P_0c052ffe: /* original 2b44, guest PC 0x0c052ffe */
if(!s->budget--) { s->failed_pc=0x0c052ffeu; return 0; }
tmp=r[4]; r[11]-=1; write(ram,r[11],tmp,1);
goto P_0c053000;
P_0c053000: /* original e230, guest PC 0x0c053000 */
if(!s->budget--) { s->failed_pc=0x0c053000u; return 0; }
r[2]=0x00000030u;
goto P_0c053002;
P_0c053002: /* original 2b20, guest PC 0x0c053002 */
if(!s->budget--) { s->failed_pc=0x0c053002u; return 0; }
write(ram,r[11],r[2],1);
goto P_0c053004;
P_0c053004: /* original 53f3, guest PC 0x0c053004 */
if(!s->budget--) { s->failed_pc=0x0c053004u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c053006;
P_0c053006: /* original 7bff, guest PC 0x0c053006 */
if(!s->budget--) { s->failed_pc=0x0c053006u; return 0; }
r[11]+=0xffffffffu;
goto P_0c053008;
P_0c053008: /* original 3b32, guest PC 0x0c053008 */
if(!s->budget--) { s->failed_pc=0x0c053008u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[3])!=0);
goto P_0c05300a;
P_0c05300a: /* original 8df9, guest PC 0x0c05300a */
if(!s->budget--) { s->failed_pc=0x0c05300au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053000; }
goto P_0c05300e;
P_0c05300c: /* original 0009, guest PC 0x0c05300c */
if(!s->budget--) { s->failed_pc=0x0c05300cu; return 0; }
goto P_0c05300e;
P_0c05300e: /* original a00e, guest PC 0x0c05300e */
if(!s->budget--) { s->failed_pc=0x0c05300eu; return 0; }
goto P_0c05302e;
P_0c053010: /* original 0009, guest PC 0x0c053010 */
if(!s->budget--) { s->failed_pc=0x0c053010u; return 0; }
goto P_0c053012;
P_0c053012: /* original 2b44, guest PC 0x0c053012 */
if(!s->budget--) { s->failed_pc=0x0c053012u; return 0; }
tmp=r[4]; r[11]-=1; write(ram,r[11],tmp,1);
goto P_0c053014;
P_0c053014: /* original 53f1, guest PC 0x0c053014 */
if(!s->budget--) { s->failed_pc=0x0c053014u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053016;
P_0c053016: /* original 73ff, guest PC 0x0c053016 */
if(!s->budget--) { s->failed_pc=0x0c053016u; return 0; }
r[3]+=0xffffffffu;
goto P_0c053018;
P_0c053018: /* original 1f31, guest PC 0x0c053018 */
if(!s->budget--) { s->failed_pc=0x0c053018u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c05301a;
P_0c05301a: /* original 52f5, guest PC 0x0c05301a */
if(!s->budget--) { s->failed_pc=0x0c05301au; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c05301c;
P_0c05301c: /* original 72f8, guest PC 0x0c05301c */
if(!s->budget--) { s->failed_pc=0x0c05301cu; return 0; }
r[2]+=0xfffffff8u;
goto P_0c05301e;
P_0c05301e: /* original 1f25, guest PC 0x0c05301e */
if(!s->budget--) { s->failed_pc=0x0c05301eu; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c053020;
P_0c053020: /* original 51f4, guest PC 0x0c053020 */
if(!s->budget--) { s->failed_pc=0x0c053020u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c053022;
P_0c053022: /* original 71ff, guest PC 0x0c053022 */
if(!s->budget--) { s->failed_pc=0x0c053022u; return 0; }
r[1]+=0xffffffffu;
goto P_0c053024;
P_0c053024: /* original 1f14, guest PC 0x0c053024 */
if(!s->budget--) { s->failed_pc=0x0c053024u; return 0; }
write(ram,r[15]+16,r[1],4);
goto P_0c053026;
P_0c053026: /* original 53f1, guest PC 0x0c053026 */
if(!s->budget--) { s->failed_pc=0x0c053026u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053028;
P_0c053028: /* original 4311, guest PC 0x0c053028 */
if(!s->budget--) { s->failed_pc=0x0c053028u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c05302a;
P_0c05302a: /* original 8da3, guest PC 0x0c05302a */
if(!s->budget--) { s->failed_pc=0x0c05302au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c052f74; }
goto P_0c05302e;
P_0c05302c: /* original 0009, guest PC 0x0c05302c */
if(!s->budget--) { s->failed_pc=0x0c05302cu; return 0; }
goto P_0c05302e;
P_0c05302e: /* original 7f2c, guest PC 0x0c05302e */
if(!s->budget--) { s->failed_pc=0x0c05302eu; return 0; }
r[15]+=0x0000002cu;
goto P_0c053030;
P_0c053030: /* original 4f26, guest PC 0x0c053030 */
if(!s->budget--) { s->failed_pc=0x0c053030u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053032;
P_0c053032: /* original 68f6, guest PC 0x0c053032 */
if(!s->budget--) { s->failed_pc=0x0c053032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c053034;
P_0c053034: /* original 69f6, guest PC 0x0c053034 */
if(!s->budget--) { s->failed_pc=0x0c053034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c053036;
P_0c053036: /* original 6af6, guest PC 0x0c053036 */
if(!s->budget--) { s->failed_pc=0x0c053036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c053038;
P_0c053038: /* original 6bf6, guest PC 0x0c053038 */
if(!s->budget--) { s->failed_pc=0x0c053038u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05303a;
P_0c05303a: /* original 6cf6, guest PC 0x0c05303a */
if(!s->budget--) { s->failed_pc=0x0c05303au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05303c;
P_0c05303c: /* original 6df6, guest PC 0x0c05303c */
if(!s->budget--) { s->failed_pc=0x0c05303cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05303e;
P_0c05303e: /* original 000b, guest PC 0x0c05303e */
if(!s->budget--) { s->failed_pc=0x0c05303eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053040: /* original 6ef6, guest PC 0x0c053040 */
if(!s->budget--) { s->failed_pc=0x0c053040u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c053042u,s,ram);
P_0c054348: /* original 2668, guest PC 0x0c054348 */
if(!s->budget--) { s->failed_pc=0x0c054348u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05434a;
P_0c05434a: /* original 8f02, guest PC 0x0c05434a */
if(!s->budget--) { s->failed_pc=0x0c05434au; return 0; }
cond=r[17]&1u;
r[7]=r[5];
if(!cond) { goto P_0c054352; }
goto P_0c05434e;
P_0c05434c: /* original 6753, guest PC 0x0c05434c */
if(!s->budget--) { s->failed_pc=0x0c05434cu; return 0; }
r[7]=r[5];
goto P_0c05434e;
P_0c05434e: /* original 000b, guest PC 0x0c05434e */
if(!s->budget--) { s->failed_pc=0x0c05434eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c054350: /* original e000, guest PC 0x0c054350 */
if(!s->budget--) { s->failed_pc=0x0c054350u; return 0; }
r[0]=0x00000000u;
goto P_0c054352;
P_0c054352: /* original e500, guest PC 0x0c054352 */
if(!s->budget--) { s->failed_pc=0x0c054352u; return 0; }
r[5]=0x00000000u;
goto P_0c054354;
P_0c054354: /* original 6253, guest PC 0x0c054354 */
if(!s->budget--) { s->failed_pc=0x0c054354u; return 0; }
r[2]=r[5];
goto P_0c054356;
P_0c054356: /* original 3262, guest PC 0x0c054356 */
if(!s->budget--) { s->failed_pc=0x0c054356u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[6])!=0);
goto P_0c054358;
P_0c054358: /* original 8d09, guest PC 0x0c054358 */
if(!s->budget--) { s->failed_pc=0x0c054358u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05436e; }
goto P_0c05435c;
P_0c05435a: /* original 0009, guest PC 0x0c05435a */
if(!s->budget--) { s->failed_pc=0x0c05435au; return 0; }
goto P_0c05435c;
P_0c05435c: /* original 6344, guest PC 0x0c05435c */
if(!s->budget--) { s->failed_pc=0x0c05435cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[3]=tmp;
goto P_0c05435e;
P_0c05435e: /* original 6274, guest PC 0x0c05435e */
if(!s->budget--) { s->failed_pc=0x0c05435eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[2]=tmp;
goto P_0c054360;
P_0c054360: /* original 3320, guest PC 0x0c054360 */
if(!s->budget--) { s->failed_pc=0x0c054360u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c054362;
P_0c054362: /* original 8f04, guest PC 0x0c054362 */
if(!s->budget--) { s->failed_pc=0x0c054362u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05436e; }
goto P_0c054366;
P_0c054364: /* original 0009, guest PC 0x0c054364 */
if(!s->budget--) { s->failed_pc=0x0c054364u; return 0; }
goto P_0c054366;
P_0c054366: /* original 7501, guest PC 0x0c054366 */
if(!s->budget--) { s->failed_pc=0x0c054366u; return 0; }
r[5]+=0x00000001u;
goto P_0c054368;
P_0c054368: /* original 3562, guest PC 0x0c054368 */
if(!s->budget--) { s->failed_pc=0x0c054368u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c05436a;
P_0c05436a: /* original 8ff7, guest PC 0x0c05436a */
if(!s->budget--) { s->failed_pc=0x0c05436au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05435c; }
goto P_0c05436e;
P_0c05436c: /* original 0009, guest PC 0x0c05436c */
if(!s->budget--) { s->failed_pc=0x0c05436cu; return 0; }
goto P_0c05436e;
P_0c05436e: /* original 6043, guest PC 0x0c05436e */
if(!s->budget--) { s->failed_pc=0x0c05436eu; return 0; }
r[0]=r[4];
goto P_0c054370;
P_0c054370: /* original 0009, guest PC 0x0c054370 */
if(!s->budget--) { s->failed_pc=0x0c054370u; return 0; }
goto P_0c054372;
P_0c054372: /* original 70ff, guest PC 0x0c054372 */
if(!s->budget--) { s->failed_pc=0x0c054372u; return 0; }
r[0]+=0xffffffffu;
goto P_0c054374;
P_0c054374: /* original 6000, guest PC 0x0c054374 */
if(!s->budget--) { s->failed_pc=0x0c054374u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[0]=tmp;
goto P_0c054376;
P_0c054376: /* original 77ff, guest PC 0x0c054376 */
if(!s->budget--) { s->failed_pc=0x0c054376u; return 0; }
r[7]+=0xffffffffu;
goto P_0c054378;
P_0c054378: /* original 6370, guest PC 0x0c054378 */
if(!s->budget--) { s->failed_pc=0x0c054378u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[3]=tmp;
goto P_0c05437a;
P_0c05437a: /* original 600c, guest PC 0x0c05437a */
if(!s->budget--) { s->failed_pc=0x0c05437au; return 0; }
r[0]=r[0]&255u;
goto P_0c05437c;
P_0c05437c: /* original 633c, guest PC 0x0c05437c */
if(!s->budget--) { s->failed_pc=0x0c05437cu; return 0; }
r[3]=r[3]&255u;
goto P_0c05437e;
P_0c05437e: /* original 3038, guest PC 0x0c05437e */
if(!s->budget--) { s->failed_pc=0x0c05437eu; return 0; }
r[0]-=r[3];
goto P_0c054380;
P_0c054380: /* original 000b, guest PC 0x0c054380 */
if(!s->budget--) { s->failed_pc=0x0c054380u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c054382: /* original 0009, guest PC 0x0c054382 */
if(!s->budget--) { s->failed_pc=0x0c054382u; return 0; }
return vf3_matrix_family(0x0c054384u,s,ram);
P_0c054650: /* original 4f22, guest PC 0x0c054650 */
if(!s->budget--) { s->failed_pc=0x0c054650u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c054652;
P_0c054652: /* original 7fc8, guest PC 0x0c054652 */
if(!s->budget--) { s->failed_pc=0x0c054652u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c054654;
P_0c054654: /* original 1f51, guest PC 0x0c054654 */
if(!s->budget--) { s->failed_pc=0x0c054654u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c054656;
P_0c054656: /* original 6063, guest PC 0x0c054656 */
if(!s->budget--) { s->failed_pc=0x0c054656u; return 0; }
r[0]=r[6];
goto P_0c054658;
P_0c054658: /* original 0009, guest PC 0x0c054658 */
if(!s->budget--) { s->failed_pc=0x0c054658u; return 0; }
goto P_0c05465a;
P_0c05465a: /* original 6ef3, guest PC 0x0c05465a */
if(!s->budget--) { s->failed_pc=0x0c05465au; return 0; }
r[14]=r[15];
goto P_0c05465c;
P_0c05465c: /* original 81f4, guest PC 0x0c05465c */
if(!s->budget--) { s->failed_pc=0x0c05465cu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c05465e;
P_0c05465e: /* original e604, guest PC 0x0c05465e */
if(!s->budget--) { s->failed_pc=0x0c05465eu; return 0; }
r[6]=0x00000004u;
goto P_0c054660;
P_0c054660: /* original dc22, guest PC 0x0c054660 */
if(!s->budget--) { s->failed_pc=0x0c054660u; return 0; }
r[12]=read(ram,0x0c0546ecu,4);
goto P_0c054662;
P_0c054662: /* original e500, guest PC 0x0c054662 */
if(!s->budget--) { s->failed_pc=0x0c054662u; return 0; }
r[5]=0x00000000u;
goto P_0c054664;
P_0c054664: /* original 2f72, guest PC 0x0c054664 */
if(!s->budget--) { s->failed_pc=0x0c054664u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c054666;
P_0c054666: /* original 7e2c, guest PC 0x0c054666 */
if(!s->budget--) { s->failed_pc=0x0c054666u; return 0; }
r[14]+=0x0000002cu;
goto P_0c054668;
P_0c054668: /* original 4c0b, guest PC 0x0c054668 */
if(!s->budget--) { s->failed_pc=0x0c054668u; return 0; }
target=r[12];
r[16]=code_base|0x0c05466cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05466cu) { target=s->pc; goto dispatch; }
goto P_0c05466c;
P_0c05466a: /* original 64e3, guest PC 0x0c05466a */
if(!s->budget--) { s->failed_pc=0x0c05466au; return 0; }
r[4]=r[14];
goto P_0c05466c;
P_0c05466c: /* original d820, guest PC 0x0c05466c */
if(!s->budget--) { s->failed_pc=0x0c05466cu; return 0; }
r[8]=read(ram,0x0c0546f0u,4);
goto P_0c05466e;
P_0c05466e: /* original e608, guest PC 0x0c05466e */
if(!s->budget--) { s->failed_pc=0x0c05466eu; return 0; }
r[6]=0x00000008u;
goto P_0c054670;
P_0c054670: /* original 65f2, guest PC 0x0c054670 */
if(!s->budget--) { s->failed_pc=0x0c054670u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c054672;
P_0c054672: /* original 64e3, guest PC 0x0c054672 */
if(!s->budget--) { s->failed_pc=0x0c054672u; return 0; }
r[4]=r[14];
goto P_0c054674;
P_0c054674: /* original 7404, guest PC 0x0c054674 */
if(!s->budget--) { s->failed_pc=0x0c054674u; return 0; }
r[4]+=0x00000004u;
goto P_0c054676;
P_0c054676: /* original 480b, guest PC 0x0c054676 */
if(!s->budget--) { s->failed_pc=0x0c054676u; return 0; }
target=r[8];
r[16]=code_base|0x0c05467au;
write(ram,r[15]+12,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05467au) { target=s->pc; goto dispatch; }
goto P_0c05467a;
P_0c054678: /* original 1f43, guest PC 0x0c054678 */
if(!s->budget--) { s->failed_pc=0x0c054678u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c05467a;
P_0c05467a: /* original 6bf3, guest PC 0x0c05467a */
if(!s->budget--) { s->failed_pc=0x0c05467au; return 0; }
r[11]=r[15];
goto P_0c05467c;
P_0c05467c: /* original 7b20, guest PC 0x0c05467c */
if(!s->budget--) { s->failed_pc=0x0c05467cu; return 0; }
r[11]+=0x00000020u;
goto P_0c05467e;
P_0c05467e: /* original e604, guest PC 0x0c05467e */
if(!s->budget--) { s->failed_pc=0x0c05467eu; return 0; }
r[6]=0x00000004u;
goto P_0c054680;
P_0c054680: /* original e500, guest PC 0x0c054680 */
if(!s->budget--) { s->failed_pc=0x0c054680u; return 0; }
r[5]=0x00000000u;
goto P_0c054682;
P_0c054682: /* original 4c0b, guest PC 0x0c054682 */
if(!s->budget--) { s->failed_pc=0x0c054682u; return 0; }
target=r[12];
r[16]=code_base|0x0c054686u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c054686u) { target=s->pc; goto dispatch; }
goto P_0c054686;
P_0c054684: /* original 64b3, guest PC 0x0c054684 */
if(!s->budget--) { s->failed_pc=0x0c054684u; return 0; }
r[4]=r[11];
goto P_0c054686;
P_0c054686: /* original e608, guest PC 0x0c054686 */
if(!s->budget--) { s->failed_pc=0x0c054686u; return 0; }
r[6]=0x00000008u;
goto P_0c054688;
P_0c054688: /* original 55f1, guest PC 0x0c054688 */
if(!s->budget--) { s->failed_pc=0x0c054688u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05468a;
P_0c05468a: /* original 64b3, guest PC 0x0c05468a */
if(!s->budget--) { s->failed_pc=0x0c05468au; return 0; }
r[4]=r[11];
goto P_0c05468c;
P_0c05468c: /* original 480b, guest PC 0x0c05468c */
if(!s->budget--) { s->failed_pc=0x0c05468cu; return 0; }
target=r[8];
r[16]=code_base|0x0c054690u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c054690u) { target=s->pc; goto dispatch; }
goto P_0c054690;
P_0c05468e: /* original 7404, guest PC 0x0c05468e */
if(!s->budget--) { s->failed_pc=0x0c05468eu; return 0; }
r[4]+=0x00000004u;
goto P_0c054690;
P_0c054690: /* original 6df3, guest PC 0x0c054690 */
if(!s->budget--) { s->failed_pc=0x0c054690u; return 0; }
r[13]=r[15];
goto P_0c054692;
P_0c054692: /* original 7d10, guest PC 0x0c054692 */
if(!s->budget--) { s->failed_pc=0x0c054692u; return 0; }
r[13]+=0x00000010u;
goto P_0c054694;
P_0c054694: /* original e610, guest PC 0x0c054694 */
if(!s->budget--) { s->failed_pc=0x0c054694u; return 0; }
r[6]=0x00000010u;
goto P_0c054696;
P_0c054696: /* original e500, guest PC 0x0c054696 */
if(!s->budget--) { s->failed_pc=0x0c054696u; return 0; }
r[5]=0x00000000u;
goto P_0c054698;
P_0c054698: /* original 4c0b, guest PC 0x0c054698 */
if(!s->budget--) { s->failed_pc=0x0c054698u; return 0; }
target=r[12];
r[16]=code_base|0x0c05469cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05469cu) { target=s->pc; goto dispatch; }
goto P_0c05469c;
P_0c05469a: /* original 64d3, guest PC 0x0c05469a */
if(!s->budget--) { s->failed_pc=0x0c05469au; return 0; }
r[4]=r[13];
goto P_0c05469c;
P_0c05469c: /* original dc15, guest PC 0x0c05469c */
if(!s->budget--) { s->failed_pc=0x0c05469cu; return 0; }
r[12]=read(ram,0x0c0546f4u,4);
goto P_0c05469e;
P_0c05469e: /* original 63d3, guest PC 0x0c05469e */
if(!s->budget--) { s->failed_pc=0x0c05469eu; return 0; }
r[3]=r[13];
goto P_0c0546a0;
P_0c0546a0: /* original 730b, guest PC 0x0c0546a0 */
if(!s->budget--) { s->failed_pc=0x0c0546a0u; return 0; }
r[3]+=0x0000000bu;
goto P_0c0546a2;
P_0c0546a2: /* original 2f32, guest PC 0x0c0546a2 */
if(!s->budget--) { s->failed_pc=0x0c0546a2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0546a4;
P_0c0546a4: /* original a01b, guest PC 0x0c0546a4 */
if(!s->budget--) { s->failed_pc=0x0c0546a4u; return 0; }
r[9]=0x00000042u;
goto P_0c0546de;
P_0c0546a6: /* original e942, guest PC 0x0c0546a6 */
if(!s->budget--) { s->failed_pc=0x0c0546a6u; return 0; }
r[9]=0x00000042u;
goto P_0c0546a8;
P_0c0546a8: /* original e50c, guest PC 0x0c0546a8 */
if(!s->budget--) { s->failed_pc=0x0c0546a8u; return 0; }
r[5]=0x0000000cu;
goto P_0c0546aa;
P_0c0546aa: /* original 4c0b, guest PC 0x0c0546aa */
if(!s->budget--) { s->failed_pc=0x0c0546aau; return 0; }
target=r[12];
r[16]=code_base|0x0c0546aeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0546aeu) { target=s->pc; goto dispatch; }
goto P_0c0546ae;
P_0c0546ac: /* original 64d3, guest PC 0x0c0546ac */
if(!s->budget--) { s->failed_pc=0x0c0546acu; return 0; }
r[4]=r[13];
goto P_0c0546ae;
P_0c0546ae: /* original e70c, guest PC 0x0c0546ae */
if(!s->budget--) { s->failed_pc=0x0c0546aeu; return 0; }
r[7]=0x0000000cu;
goto P_0c0546b0;
P_0c0546b0: /* original d311, guest PC 0x0c0546b0 */
if(!s->budget--) { s->failed_pc=0x0c0546b0u; return 0; }
r[3]=read(ram,0x0c0546f8u,4);
goto P_0c0546b2;
P_0c0546b2: /* original 66b3, guest PC 0x0c0546b2 */
if(!s->budget--) { s->failed_pc=0x0c0546b2u; return 0; }
r[6]=r[11];
goto P_0c0546b4;
P_0c0546b4: /* original 65e3, guest PC 0x0c0546b4 */
if(!s->budget--) { s->failed_pc=0x0c0546b4u; return 0; }
r[5]=r[14];
goto P_0c0546b6;
P_0c0546b6: /* original 430b, guest PC 0x0c0546b6 */
if(!s->budget--) { s->failed_pc=0x0c0546b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0546bau;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0546bau) { target=s->pc; goto dispatch; }
goto P_0c0546ba;
P_0c0546b8: /* original e400, guest PC 0x0c0546b8 */
if(!s->budget--) { s->failed_pc=0x0c0546b8u; return 0; }
r[4]=0x00000000u;
goto P_0c0546ba;
P_0c0546ba: /* original 4011, guest PC 0x0c0546ba */
if(!s->budget--) { s->failed_pc=0x0c0546bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0546bc;
P_0c0546bc: /* original 8f06, guest PC 0x0c0546bc */
if(!s->budget--) { s->failed_pc=0x0c0546bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0546cc; }
goto P_0c0546c0;
P_0c0546be: /* original 0009, guest PC 0x0c0546be */
if(!s->budget--) { s->failed_pc=0x0c0546beu; return 0; }
goto P_0c0546c0;
P_0c0546c0: /* original 63f2, guest PC 0x0c0546c0 */
if(!s->budget--) { s->failed_pc=0x0c0546c0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0546c2;
P_0c0546c2: /* original 6230, guest PC 0x0c0546c2 */
if(!s->budget--) { s->failed_pc=0x0c0546c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0546c4;
P_0c0546c4: /* original 7201, guest PC 0x0c0546c4 */
if(!s->budget--) { s->failed_pc=0x0c0546c4u; return 0; }
r[2]+=0x00000001u;
goto P_0c0546c6;
P_0c0546c6: /* original 2320, guest PC 0x0c0546c6 */
if(!s->budget--) { s->failed_pc=0x0c0546c6u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0546c8;
P_0c0546c8: /* original a005, guest PC 0x0c0546c8 */
if(!s->budget--) { s->failed_pc=0x0c0546c8u; return 0; }
goto P_0c0546d6;
P_0c0546ca: /* original 0009, guest PC 0x0c0546ca */
if(!s->budget--) { s->failed_pc=0x0c0546cau; return 0; }
goto P_0c0546cc;
P_0c0546cc: /* original d20b, guest PC 0x0c0546cc */
if(!s->budget--) { s->failed_pc=0x0c0546ccu; return 0; }
r[2]=read(ram,0x0c0546fcu,4);
goto P_0c0546ce;
P_0c0546ce: /* original e60c, guest PC 0x0c0546ce */
if(!s->budget--) { s->failed_pc=0x0c0546ceu; return 0; }
r[6]=0x0000000cu;
goto P_0c0546d0;
P_0c0546d0: /* original 65b3, guest PC 0x0c0546d0 */
if(!s->budget--) { s->failed_pc=0x0c0546d0u; return 0; }
r[5]=r[11];
goto P_0c0546d2;
P_0c0546d2: /* original 420b, guest PC 0x0c0546d2 */
if(!s->budget--) { s->failed_pc=0x0c0546d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0546d6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0546d6u) { target=s->pc; goto dispatch; }
goto P_0c0546d6;
P_0c0546d4: /* original 64e3, guest PC 0x0c0546d4 */
if(!s->budget--) { s->failed_pc=0x0c0546d4u; return 0; }
r[4]=r[14];
goto P_0c0546d6;
P_0c0546d6: /* original e50c, guest PC 0x0c0546d6 */
if(!s->budget--) { s->failed_pc=0x0c0546d6u; return 0; }
r[5]=0x0000000cu;
goto P_0c0546d8;
P_0c0546d8: /* original 4c0b, guest PC 0x0c0546d8 */
if(!s->budget--) { s->failed_pc=0x0c0546d8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0546dcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0546dcu) { target=s->pc; goto dispatch; }
goto P_0c0546dc;
P_0c0546da: /* original 64e3, guest PC 0x0c0546da */
if(!s->budget--) { s->failed_pc=0x0c0546dau; return 0; }
r[4]=r[14];
goto P_0c0546dc;
P_0c0546dc: /* original 79ff, guest PC 0x0c0546dc */
if(!s->budget--) { s->failed_pc=0x0c0546dcu; return 0; }
r[9]+=0xffffffffu;
goto P_0c0546de;
P_0c0546de: /* original 2998, guest PC 0x0c0546de */
if(!s->budget--) { s->failed_pc=0x0c0546deu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0546e0;
P_0c0546e0: /* original 8fe2, guest PC 0x0c0546e0 */
if(!s->budget--) { s->failed_pc=0x0c0546e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0546a8; }
goto P_0c0546e4;
P_0c0546e2: /* original 0009, guest PC 0x0c0546e2 */
if(!s->budget--) { s->failed_pc=0x0c0546e2u; return 0; }
goto P_0c0546e4;
P_0c0546e4: /* original d906, guest PC 0x0c0546e4 */
if(!s->budget--) { s->failed_pc=0x0c0546e4u; return 0; }
r[9]=read(ram,0x0c054700u,4);
goto P_0c0546e6;
P_0c0546e6: /* original a011, guest PC 0x0c0546e6 */
if(!s->budget--) { s->failed_pc=0x0c0546e6u; return 0; }
r[11]=0x00000002u;
goto P_0c05470c;
P_0c0546e8: /* original eb02, guest PC 0x0c0546e8 */
if(!s->budget--) { s->failed_pc=0x0c0546e8u; return 0; }
r[11]=0x00000002u;
return vf3_matrix_family(0x0c0546eau,s,ram);
P_0c054704: /* original e510, guest PC 0x0c054704 */
if(!s->budget--) { s->failed_pc=0x0c054704u; return 0; }
r[5]=0x00000010u;
goto P_0c054706;
P_0c054706: /* original 490b, guest PC 0x0c054706 */
if(!s->budget--) { s->failed_pc=0x0c054706u; return 0; }
target=r[9];
r[16]=code_base|0x0c05470au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05470au) { target=s->pc; goto dispatch; }
goto P_0c05470a;
P_0c054708: /* original 64d3, guest PC 0x0c054708 */
if(!s->budget--) { s->failed_pc=0x0c054708u; return 0; }
r[4]=r[13];
goto P_0c05470a;
P_0c05470a: /* original 7bff, guest PC 0x0c05470a */
if(!s->budget--) { s->failed_pc=0x0c05470au; return 0; }
r[11]+=0xffffffffu;
goto P_0c05470c;
P_0c05470c: /* original 2bb8, guest PC 0x0c05470c */
if(!s->budget--) { s->failed_pc=0x0c05470cu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c05470e;
P_0c05470e: /* original 8ff9, guest PC 0x0c05470e */
if(!s->budget--) { s->failed_pc=0x0c05470eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054704; }
goto P_0c054712;
P_0c054710: /* original 0009, guest PC 0x0c054710 */
if(!s->budget--) { s->failed_pc=0x0c054710u; return 0; }
goto P_0c054712;
P_0c054712: /* original 62e0, guest PC 0x0c054712 */
if(!s->budget--) { s->failed_pc=0x0c054712u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[2]=tmp;
goto P_0c054714;
P_0c054714: /* original 2228, guest PC 0x0c054714 */
if(!s->budget--) { s->failed_pc=0x0c054714u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054716;
P_0c054716: /* original 8f2d, guest PC 0x0c054716 */
if(!s->budget--) { s->failed_pc=0x0c054716u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05471a;
P_0c054718: /* original 0009, guest PC 0x0c054718 */
if(!s->budget--) { s->failed_pc=0x0c054718u; return 0; }
goto P_0c05471a;
P_0c05471a: /* original 84e1, guest PC 0x0c05471a */
if(!s->budget--) { s->failed_pc=0x0c05471au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c05471c;
P_0c05471c: /* original 2008, guest PC 0x0c05471c */
if(!s->budget--) { s->failed_pc=0x0c05471cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05471e;
P_0c05471e: /* original 8f29, guest PC 0x0c05471e */
if(!s->budget--) { s->failed_pc=0x0c05471eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054722;
P_0c054720: /* original 0009, guest PC 0x0c054720 */
if(!s->budget--) { s->failed_pc=0x0c054720u; return 0; }
goto P_0c054722;
P_0c054722: /* original 84e2, guest PC 0x0c054722 */
if(!s->budget--) { s->failed_pc=0x0c054722u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c054724;
P_0c054724: /* original 2008, guest PC 0x0c054724 */
if(!s->budget--) { s->failed_pc=0x0c054724u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054726;
P_0c054726: /* original 8f25, guest PC 0x0c054726 */
if(!s->budget--) { s->failed_pc=0x0c054726u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05472a;
P_0c054728: /* original 0009, guest PC 0x0c054728 */
if(!s->budget--) { s->failed_pc=0x0c054728u; return 0; }
goto P_0c05472a;
P_0c05472a: /* original 84e3, guest PC 0x0c05472a */
if(!s->budget--) { s->failed_pc=0x0c05472au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c05472c;
P_0c05472c: /* original 2008, guest PC 0x0c05472c */
if(!s->budget--) { s->failed_pc=0x0c05472cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05472e;
P_0c05472e: /* original 8f21, guest PC 0x0c05472e */
if(!s->budget--) { s->failed_pc=0x0c05472eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054732;
P_0c054730: /* original 0009, guest PC 0x0c054730 */
if(!s->budget--) { s->failed_pc=0x0c054730u; return 0; }
goto P_0c054732;
P_0c054732: /* original 53f3, guest PC 0x0c054732 */
if(!s->budget--) { s->failed_pc=0x0c054732u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c054734;
P_0c054734: /* original 6230, guest PC 0x0c054734 */
if(!s->budget--) { s->failed_pc=0x0c054734u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c054736;
P_0c054736: /* original 2228, guest PC 0x0c054736 */
if(!s->budget--) { s->failed_pc=0x0c054736u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054738;
P_0c054738: /* original 8f1c, guest PC 0x0c054738 */
if(!s->budget--) { s->failed_pc=0x0c054738u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05473c;
P_0c05473a: /* original 0009, guest PC 0x0c05473a */
if(!s->budget--) { s->failed_pc=0x0c05473au; return 0; }
goto P_0c05473c;
P_0c05473c: /* original 84e5, guest PC 0x0c05473c */
if(!s->budget--) { s->failed_pc=0x0c05473cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+5,1);
goto P_0c05473e;
P_0c05473e: /* original 2008, guest PC 0x0c05473e */
if(!s->budget--) { s->failed_pc=0x0c05473eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054740;
P_0c054740: /* original 8f18, guest PC 0x0c054740 */
if(!s->budget--) { s->failed_pc=0x0c054740u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054744;
P_0c054742: /* original 0009, guest PC 0x0c054742 */
if(!s->budget--) { s->failed_pc=0x0c054742u; return 0; }
goto P_0c054744;
P_0c054744: /* original 84e6, guest PC 0x0c054744 */
if(!s->budget--) { s->failed_pc=0x0c054744u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+6,1);
goto P_0c054746;
P_0c054746: /* original 2008, guest PC 0x0c054746 */
if(!s->budget--) { s->failed_pc=0x0c054746u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054748;
P_0c054748: /* original 8f14, guest PC 0x0c054748 */
if(!s->budget--) { s->failed_pc=0x0c054748u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05474c;
P_0c05474a: /* original 0009, guest PC 0x0c05474a */
if(!s->budget--) { s->failed_pc=0x0c05474au; return 0; }
goto P_0c05474c;
P_0c05474c: /* original 84e7, guest PC 0x0c05474c */
if(!s->budget--) { s->failed_pc=0x0c05474cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c05474e;
P_0c05474e: /* original 2008, guest PC 0x0c05474e */
if(!s->budget--) { s->failed_pc=0x0c05474eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054750;
P_0c054750: /* original 8f10, guest PC 0x0c054750 */
if(!s->budget--) { s->failed_pc=0x0c054750u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054754;
P_0c054752: /* original 0009, guest PC 0x0c054752 */
if(!s->budget--) { s->failed_pc=0x0c054752u; return 0; }
goto P_0c054754;
P_0c054754: /* original 84e8, guest PC 0x0c054754 */
if(!s->budget--) { s->failed_pc=0x0c054754u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c054756;
P_0c054756: /* original 2008, guest PC 0x0c054756 */
if(!s->budget--) { s->failed_pc=0x0c054756u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054758;
P_0c054758: /* original 8f0c, guest PC 0x0c054758 */
if(!s->budget--) { s->failed_pc=0x0c054758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05475c;
P_0c05475a: /* original 0009, guest PC 0x0c05475a */
if(!s->budget--) { s->failed_pc=0x0c05475au; return 0; }
goto P_0c05475c;
P_0c05475c: /* original 84e9, guest PC 0x0c05475c */
if(!s->budget--) { s->failed_pc=0x0c05475cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+9,1);
goto P_0c05475e;
P_0c05475e: /* original 2008, guest PC 0x0c05475e */
if(!s->budget--) { s->failed_pc=0x0c05475eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054760;
P_0c054760: /* original 8f08, guest PC 0x0c054760 */
if(!s->budget--) { s->failed_pc=0x0c054760u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054764;
P_0c054762: /* original 0009, guest PC 0x0c054762 */
if(!s->budget--) { s->failed_pc=0x0c054762u; return 0; }
goto P_0c054764;
P_0c054764: /* original 84ea, guest PC 0x0c054764 */
if(!s->budget--) { s->failed_pc=0x0c054764u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+10,1);
goto P_0c054766;
P_0c054766: /* original 2008, guest PC 0x0c054766 */
if(!s->budget--) { s->failed_pc=0x0c054766u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054768;
P_0c054768: /* original 8f04, guest PC 0x0c054768 */
if(!s->budget--) { s->failed_pc=0x0c054768u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05476c;
P_0c05476a: /* original 0009, guest PC 0x0c05476a */
if(!s->budget--) { s->failed_pc=0x0c05476au; return 0; }
goto P_0c05476c;
P_0c05476c: /* original 84eb, guest PC 0x0c05476c */
if(!s->budget--) { s->failed_pc=0x0c05476cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c05476e;
P_0c05476e: /* original 2008, guest PC 0x0c05476e */
if(!s->budget--) { s->failed_pc=0x0c05476eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054770;
P_0c054770: /* original 8d03, guest PC 0x0c054770 */
if(!s->budget--) { s->failed_pc=0x0c054770u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05477a; }
goto P_0c054774;
P_0c054772: /* original 0009, guest PC 0x0c054772 */
if(!s->budget--) { s->failed_pc=0x0c054772u; return 0; }
goto P_0c054774;
P_0c054774: /* original 84dc, guest PC 0x0c054774 */
if(!s->budget--) { s->failed_pc=0x0c054774u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+12,1);
goto P_0c054776;
P_0c054776: /* original cb20, guest PC 0x0c054776 */
if(!s->budget--) { s->failed_pc=0x0c054776u; return 0; }
r[0]|=32u;
goto P_0c054778;
P_0c054778: /* original 80dc, guest PC 0x0c054778 */
if(!s->budget--) { s->failed_pc=0x0c054778u; return 0; }
write(ram,r[13]+12,r[0],1);
goto P_0c05477a;
P_0c05477a: /* original 63a1, guest PC 0x0c05477a */
if(!s->budget--) { s->failed_pc=0x0c05477au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[3]=tmp;
goto P_0c05477c;
P_0c05477c: /* original 85f4, guest PC 0x0c05477c */
if(!s->budget--) { s->failed_pc=0x0c05477cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c05477e;
P_0c05477e: /* original 3038, guest PC 0x0c05477e */
if(!s->budget--) { s->failed_pc=0x0c05477eu; return 0; }
r[0]-=r[3];
goto P_0c054780;
P_0c054780: /* original 2a01, guest PC 0x0c054780 */
if(!s->budget--) { s->failed_pc=0x0c054780u; return 0; }
write(ram,r[10],r[0],2);
goto P_0c054782;
P_0c054782: /* original 84d4, guest PC 0x0c054782 */
if(!s->budget--) { s->failed_pc=0x0c054782u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c054784;
P_0c054784: /* original 2008, guest PC 0x0c054784 */
if(!s->budget--) { s->failed_pc=0x0c054784u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054786;
P_0c054786: /* original 8f21, guest PC 0x0c054786 */
if(!s->budget--) { s->failed_pc=0x0c054786u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c05478a;
P_0c054788: /* original 0009, guest PC 0x0c054788 */
if(!s->budget--) { s->failed_pc=0x0c054788u; return 0; }
goto P_0c05478a;
P_0c05478a: /* original 84d5, guest PC 0x0c05478a */
if(!s->budget--) { s->failed_pc=0x0c05478au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+5,1);
goto P_0c05478c;
P_0c05478c: /* original 2008, guest PC 0x0c05478c */
if(!s->budget--) { s->failed_pc=0x0c05478cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05478e;
P_0c05478e: /* original 8f1d, guest PC 0x0c05478e */
if(!s->budget--) { s->failed_pc=0x0c05478eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c054792;
P_0c054790: /* original 0009, guest PC 0x0c054790 */
if(!s->budget--) { s->failed_pc=0x0c054790u; return 0; }
goto P_0c054792;
P_0c054792: /* original 84d6, guest PC 0x0c054792 */
if(!s->budget--) { s->failed_pc=0x0c054792u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+6,1);
goto P_0c054794;
P_0c054794: /* original 2008, guest PC 0x0c054794 */
if(!s->budget--) { s->failed_pc=0x0c054794u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054796;
P_0c054796: /* original 8f19, guest PC 0x0c054796 */
if(!s->budget--) { s->failed_pc=0x0c054796u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c05479a;
P_0c054798: /* original 0009, guest PC 0x0c054798 */
if(!s->budget--) { s->failed_pc=0x0c054798u; return 0; }
goto P_0c05479a;
P_0c05479a: /* original 84d7, guest PC 0x0c05479a */
if(!s->budget--) { s->failed_pc=0x0c05479au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+7,1);
goto P_0c05479c;
P_0c05479c: /* original 2008, guest PC 0x0c05479c */
if(!s->budget--) { s->failed_pc=0x0c05479cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05479e;
P_0c05479e: /* original 8f15, guest PC 0x0c05479e */
if(!s->budget--) { s->failed_pc=0x0c05479eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547a2;
P_0c0547a0: /* original 0009, guest PC 0x0c0547a0 */
if(!s->budget--) { s->failed_pc=0x0c0547a0u; return 0; }
goto P_0c0547a2;
P_0c0547a2: /* original 84d8, guest PC 0x0c0547a2 */
if(!s->budget--) { s->failed_pc=0x0c0547a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+8,1);
goto P_0c0547a4;
P_0c0547a4: /* original 2008, guest PC 0x0c0547a4 */
if(!s->budget--) { s->failed_pc=0x0c0547a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0547a6;
P_0c0547a6: /* original 8f11, guest PC 0x0c0547a6 */
if(!s->budget--) { s->failed_pc=0x0c0547a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547aa;
P_0c0547a8: /* original 0009, guest PC 0x0c0547a8 */
if(!s->budget--) { s->failed_pc=0x0c0547a8u; return 0; }
goto P_0c0547aa;
P_0c0547aa: /* original 84d9, guest PC 0x0c0547aa */
if(!s->budget--) { s->failed_pc=0x0c0547aau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+9,1);
goto P_0c0547ac;
P_0c0547ac: /* original 2008, guest PC 0x0c0547ac */
if(!s->budget--) { s->failed_pc=0x0c0547acu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0547ae;
P_0c0547ae: /* original 8f0d, guest PC 0x0c0547ae */
if(!s->budget--) { s->failed_pc=0x0c0547aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547b2;
P_0c0547b0: /* original 0009, guest PC 0x0c0547b0 */
if(!s->budget--) { s->failed_pc=0x0c0547b0u; return 0; }
goto P_0c0547b2;
P_0c0547b2: /* original 84da, guest PC 0x0c0547b2 */
if(!s->budget--) { s->failed_pc=0x0c0547b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+10,1);
goto P_0c0547b4;
P_0c0547b4: /* original 2008, guest PC 0x0c0547b4 */
if(!s->budget--) { s->failed_pc=0x0c0547b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0547b6;
P_0c0547b6: /* original 8f09, guest PC 0x0c0547b6 */
if(!s->budget--) { s->failed_pc=0x0c0547b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547ba;
P_0c0547b8: /* original 0009, guest PC 0x0c0547b8 */
if(!s->budget--) { s->failed_pc=0x0c0547b8u; return 0; }
goto P_0c0547ba;
P_0c0547ba: /* original 63f2, guest PC 0x0c0547ba */
if(!s->budget--) { s->failed_pc=0x0c0547bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0547bc;
P_0c0547bc: /* original 6230, guest PC 0x0c0547bc */
if(!s->budget--) { s->failed_pc=0x0c0547bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0547be;
P_0c0547be: /* original 2228, guest PC 0x0c0547be */
if(!s->budget--) { s->failed_pc=0x0c0547beu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0547c0;
P_0c0547c0: /* original 8f04, guest PC 0x0c0547c0 */
if(!s->budget--) { s->failed_pc=0x0c0547c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547c4;
P_0c0547c2: /* original 0009, guest PC 0x0c0547c2 */
if(!s->budget--) { s->failed_pc=0x0c0547c2u; return 0; }
goto P_0c0547c4;
P_0c0547c4: /* original 84dc, guest PC 0x0c0547c4 */
if(!s->budget--) { s->failed_pc=0x0c0547c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+12,1);
goto P_0c0547c6;
P_0c0547c6: /* original 2008, guest PC 0x0c0547c6 */
if(!s->budget--) { s->failed_pc=0x0c0547c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0547c8;
P_0c0547c8: /* original 8d0f, guest PC 0x0c0547c8 */
if(!s->budget--) { s->failed_pc=0x0c0547c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0547ea; }
goto P_0c0547cc;
P_0c0547ca: /* original 0009, guest PC 0x0c0547ca */
if(!s->budget--) { s->failed_pc=0x0c0547cau; return 0; }
goto P_0c0547cc;
P_0c0547cc: /* original 9b1c, guest PC 0x0c0547cc */
if(!s->budget--) { s->failed_pc=0x0c0547ccu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054808u,2);
goto P_0c0547ce;
P_0c0547ce: /* original 6ed3, guest PC 0x0c0547ce */
if(!s->budget--) { s->failed_pc=0x0c0547ceu; return 0; }
r[14]=r[13];
goto P_0c0547d0;
P_0c0547d0: /* original a006, guest PC 0x0c0547d0 */
if(!s->budget--) { s->failed_pc=0x0c0547d0u; return 0; }
r[14]+=0x00000004u;
goto P_0c0547e0;
P_0c0547d2: /* original 7e04, guest PC 0x0c0547d2 */
if(!s->budget--) { s->failed_pc=0x0c0547d2u; return 0; }
r[14]+=0x00000004u;
goto P_0c0547d4;
P_0c0547d4: /* original e509, guest PC 0x0c0547d4 */
if(!s->budget--) { s->failed_pc=0x0c0547d4u; return 0; }
r[5]=0x00000009u;
goto P_0c0547d6;
P_0c0547d6: /* original 4c0b, guest PC 0x0c0547d6 */
if(!s->budget--) { s->failed_pc=0x0c0547d6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0547dau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0547dau) { target=s->pc; goto dispatch; }
goto P_0c0547da;
P_0c0547d8: /* original 64e3, guest PC 0x0c0547d8 */
if(!s->budget--) { s->failed_pc=0x0c0547d8u; return 0; }
r[4]=r[14];
goto P_0c0547da;
P_0c0547da: /* original 62a1, guest PC 0x0c0547da */
if(!s->budget--) { s->failed_pc=0x0c0547dau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[2]=tmp;
goto P_0c0547dc;
P_0c0547dc: /* original 72ff, guest PC 0x0c0547dc */
if(!s->budget--) { s->failed_pc=0x0c0547dcu; return 0; }
r[2]+=0xffffffffu;
goto P_0c0547de;
P_0c0547de: /* original 2a21, guest PC 0x0c0547de */
if(!s->budget--) { s->failed_pc=0x0c0547deu; return 0; }
write(ram,r[10],r[2],2);
goto P_0c0547e0;
P_0c0547e0: /* original 63e0, guest PC 0x0c0547e0 */
if(!s->budget--) { s->failed_pc=0x0c0547e0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c0547e2;
P_0c0547e2: /* original 633c, guest PC 0x0c0547e2 */
if(!s->budget--) { s->failed_pc=0x0c0547e2u; return 0; }
r[3]=r[3]&255u;
goto P_0c0547e4;
P_0c0547e4: /* original 23b8, guest PC 0x0c0547e4 */
if(!s->budget--) { s->failed_pc=0x0c0547e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0547e6;
P_0c0547e6: /* original 8df5, guest PC 0x0c0547e6 */
if(!s->budget--) { s->failed_pc=0x0c0547e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0547d4; }
goto P_0c0547ea;
P_0c0547e8: /* original 0009, guest PC 0x0c0547e8 */
if(!s->budget--) { s->failed_pc=0x0c0547e8u; return 0; }
goto P_0c0547ea;
P_0c0547ea: /* original e609, guest PC 0x0c0547ea */
if(!s->budget--) { s->failed_pc=0x0c0547eau; return 0; }
r[6]=0x00000009u;
goto P_0c0547ec;
P_0c0547ec: /* original 65d3, guest PC 0x0c0547ec */
if(!s->budget--) { s->failed_pc=0x0c0547ecu; return 0; }
r[5]=r[13];
goto P_0c0547ee;
P_0c0547ee: /* original 7504, guest PC 0x0c0547ee */
if(!s->budget--) { s->failed_pc=0x0c0547eeu; return 0; }
r[5]+=0x00000004u;
goto P_0c0547f0;
P_0c0547f0: /* original 480b, guest PC 0x0c0547f0 */
if(!s->budget--) { s->failed_pc=0x0c0547f0u; return 0; }
target=r[8];
r[16]=code_base|0x0c0547f4u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0547f4u) { target=s->pc; goto dispatch; }
goto P_0c0547f4;
P_0c0547f2: /* original 54f1, guest PC 0x0c0547f2 */
if(!s->budget--) { s->failed_pc=0x0c0547f2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0547f4;
P_0c0547f4: /* original 7f38, guest PC 0x0c0547f4 */
if(!s->budget--) { s->failed_pc=0x0c0547f4u; return 0; }
r[15]+=0x00000038u;
goto P_0c0547f6;
P_0c0547f6: /* original 4f26, guest PC 0x0c0547f6 */
if(!s->budget--) { s->failed_pc=0x0c0547f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0547f8;
P_0c0547f8: /* original 68f6, guest PC 0x0c0547f8 */
if(!s->budget--) { s->failed_pc=0x0c0547f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0547fa;
P_0c0547fa: /* original 69f6, guest PC 0x0c0547fa */
if(!s->budget--) { s->failed_pc=0x0c0547fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0547fc;
P_0c0547fc: /* original 6af6, guest PC 0x0c0547fc */
if(!s->budget--) { s->failed_pc=0x0c0547fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0547fe;
P_0c0547fe: /* original 6bf6, guest PC 0x0c0547fe */
if(!s->budget--) { s->failed_pc=0x0c0547feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c054800;
P_0c054800: /* original 6cf6, guest PC 0x0c054800 */
if(!s->budget--) { s->failed_pc=0x0c054800u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c054802;
P_0c054802: /* original 6df6, guest PC 0x0c054802 */
if(!s->budget--) { s->failed_pc=0x0c054802u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c054804;
P_0c054804: /* original 000b, guest PC 0x0c054804 */
if(!s->budget--) { s->failed_pc=0x0c054804u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054806: /* original 6ef6, guest PC 0x0c054806 */
if(!s->budget--) { s->failed_pc=0x0c054806u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c054808u,s,ram);
P_0c058348: /* original 4f22, guest PC 0x0c058348 */
if(!s->budget--) { s->failed_pc=0x0c058348u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05834a;
P_0c05834a: /* original f31d, guest PC 0x0c05834a */
if(!s->budget--) { s->failed_pc=0x0c05834au; return 0; }
r[53]=fr[3];
goto P_0c05834c;
P_0c05834c: /* original 7e04, guest PC 0x0c05834c */
if(!s->budget--) { s->failed_pc=0x0c05834cu; return 0; }
r[14]+=0x00000004u;
goto P_0c05834e;
P_0c05834e: /* original 5222, guest PC 0x0c05834e */
if(!s->budget--) { s->failed_pc=0x0c05834eu; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c058350;
P_0c058350: /* original 6be5, guest PC 0x0c058350 */
if(!s->budget--) { s->failed_pc=0x0c058350u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[11]=tmp;
goto P_0c058352;
P_0c058352: /* original fbfd, guest PC 0x0c058352 */
if(!s->budget--) { s->failed_pc=0x0c058352u; return 0; }
vf3_matrix_swap(s);
goto P_0c058354;
P_0c058354: /* original 72e0, guest PC 0x0c058354 */
if(!s->budget--) { s->failed_pc=0x0c058354u; return 0; }
r[2]+=0xffffffe0u;
goto P_0c058356;
P_0c058356: /* original f829, guest PC 0x0c058356 */
if(!s->budget--) { s->failed_pc=0x0c058356u; return 0; }
vf3_matrix_load(s,ram,8,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058358;
P_0c058358: /* original f929, guest PC 0x0c058358 */
if(!s->budget--) { s->failed_pc=0x0c058358u; return 0; }
vf3_matrix_load(s,ram,9,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c05835a;
P_0c05835a: /* original fa28, guest PC 0x0c05835a */
if(!s->budget--) { s->failed_pc=0x0c05835au; return 0; }
vf3_matrix_load(s,ram,10,r[2]);
goto P_0c05835c;
P_0c05835c: /* original 72d8, guest PC 0x0c05835c */
if(!s->budget--) { s->failed_pc=0x0c05835cu; return 0; }
r[2]+=0xffffffd8u;
goto P_0c05835e;
P_0c05835e: /* original f029, guest PC 0x0c05835e */
if(!s->budget--) { s->failed_pc=0x0c05835eu; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058360;
P_0c058360: /* original f129, guest PC 0x0c058360 */
if(!s->budget--) { s->failed_pc=0x0c058360u; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058362;
P_0c058362: /* original f228, guest PC 0x0c058362 */
if(!s->budget--) { s->failed_pc=0x0c058362u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c058364;
P_0c058364: /* original 7208, guest PC 0x0c058364 */
if(!s->budget--) { s->failed_pc=0x0c058364u; return 0; }
r[2]+=0x00000008u;
goto P_0c058366;
P_0c058366: /* original f429, guest PC 0x0c058366 */
if(!s->budget--) { s->failed_pc=0x0c058366u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058368;
P_0c058368: /* original f529, guest PC 0x0c058368 */
if(!s->budget--) { s->failed_pc=0x0c058368u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c05836a;
P_0c05836a: /* original 7140, guest PC 0x0c05836a */
if(!s->budget--) { s->failed_pc=0x0c05836au; return 0; }
r[1]+=0x00000040u;
goto P_0c05836c;
P_0c05836c: /* original f628, guest PC 0x0c05836c */
if(!s->budget--) { s->failed_pc=0x0c05836cu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c05836e;
P_0c05836e: /* original fc19, guest PC 0x0c05836e */
if(!s->budget--) { s->failed_pc=0x0c05836eu; return 0; }
vf3_matrix_load(s,ram,12,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c058370;
P_0c058370: /* original fd19, guest PC 0x0c058370 */
if(!s->budget--) { s->failed_pc=0x0c058370u; return 0; }
vf3_matrix_load(s,ram,13,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c058372;
P_0c058372: /* original fe18, guest PC 0x0c058372 */
if(!s->budget--) { s->failed_pc=0x0c058372u; return 0; }
vf3_matrix_load(s,ram,14,r[1]);
goto P_0c058374;
P_0c058374: /* original f3fd, guest PC 0x0c058374 */
if(!s->budget--) { s->failed_pc=0x0c058374u; return 0; }
r[18]^=0x100000u;
goto P_0c058376;
P_0c058376: /* original ff0d, guest PC 0x0c058376 */
if(!s->budget--) { s->failed_pc=0x0c058376u; return 0; }
fr[15]=r[53];
goto P_0c058378;
P_0c058378: /* original fbfd, guest PC 0x0c058378 */
if(!s->budget--) { s->failed_pc=0x0c058378u; return 0; }
vf3_matrix_swap(s);
goto P_0c05837a;
P_0c05837a: /* original 67e5, guest PC 0x0c05837a */
if(!s->budget--) { s->failed_pc=0x0c05837au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[7]=tmp;
goto P_0c05837c;
P_0c05837c: /* original 68e1, guest PC 0x0c05837c */
if(!s->budget--) { s->failed_pc=0x0c05837cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[8]=tmp;
goto P_0c05837e;
P_0c05837e: /* original e104, guest PC 0x0c05837e */
if(!s->budget--) { s->failed_pc=0x0c05837eu; return 0; }
r[1]=0x00000004u;
goto P_0c058380;
P_0c058380: /* original 85ec, guest PC 0x0c058380 */
if(!s->budget--) { s->failed_pc=0x0c058380u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c058382;
P_0c058382: /* original e500, guest PC 0x0c058382 */
if(!s->budget--) { s->failed_pc=0x0c058382u; return 0; }
r[5]=0x00000000u;
goto P_0c058384;
P_0c058384: /* original 4711, guest PC 0x0c058384 */
if(!s->budget--) { s->failed_pc=0x0c058384u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c058386;
P_0c058386: /* original 481d, guest PC 0x0c058386 */
if(!s->budget--) { s->failed_pc=0x0c058386u; return 0; }
r[8]=(r[1]&0x80000000u)?((r[1]&31u)?r[8]>>((-r[1])&31u):0):r[8]<<(r[1]&31u);
goto P_0c058388;
P_0c058388: /* original 8900, guest PC 0x0c058388 */
if(!s->budget--) { s->failed_pc=0x0c058388u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05838c; }
goto P_0c05838a;
P_0c05838a: /* original 677b, guest PC 0x0c05838a */
if(!s->budget--) { s->failed_pc=0x0c05838au; return 0; }
r[7]=0u-r[7];
goto P_0c05838c;
P_0c05838c: /* original 0329, guest PC 0x0c05838c */
if(!s->budget--) { s->failed_pc=0x0c05838cu; return 0; }
r[3]=r[17]&1u;
goto P_0c05838e;
P_0c05838e: /* original 401d, guest PC 0x0c05838e */
if(!s->budget--) { s->failed_pc=0x0c05838eu; return 0; }
r[0]=(r[1]&0x80000000u)?((r[1]&31u)?r[0]>>((-r[1])&31u):0):r[0]<<(r[1]&31u);
goto P_0c058390;
P_0c058390: /* original 38dc, guest PC 0x0c058390 */
if(!s->budget--) { s->failed_pc=0x0c058390u; return 0; }
r[8]+=r[13];
goto P_0c058392;
P_0c058392: /* original 6903, guest PC 0x0c058392 */
if(!s->budget--) { s->failed_pc=0x0c058392u; return 0; }
r[9]=r[0];
goto P_0c058394;
P_0c058394: /* original f088, guest PC 0x0c058394 */
if(!s->budget--) { s->failed_pc=0x0c058394u; return 0; }
vf3_matrix_load(s,ram,0,r[8]);
goto P_0c058396;
P_0c058396: /* original 39dc, guest PC 0x0c058396 */
if(!s->budget--) { s->failed_pc=0x0c058396u; return 0; }
r[9]+=r[13];
goto P_0c058398;
P_0c058398: /* original 5282, guest PC 0x0c058398 */
if(!s->budget--) { s->failed_pc=0x0c058398u; return 0; }
r[2]=read(ram,r[8]+8,4);
goto P_0c05839a;
P_0c05839a: /* original f498, guest PC 0x0c05839a */
if(!s->budget--) { s->failed_pc=0x0c05839au; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c05839c;
P_0c05839c: /* original 7e30, guest PC 0x0c05839c */
if(!s->budget--) { s->failed_pc=0x0c05839cu; return 0; }
r[14]+=0x00000030u;
goto P_0c05839e;
P_0c05839e: /* original 5192, guest PC 0x0c05839e */
if(!s->budget--) { s->failed_pc=0x0c05839eu; return 0; }
r[1]=read(ram,r[9]+8,4);
goto P_0c0583a0;
P_0c0583a0: /* original 32a6, guest PC 0x0c0583a0 */
if(!s->budget--) { s->failed_pc=0x0c0583a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[10])!=0);
goto P_0c0583a2;
P_0c0583a2: /* original 77fe, guest PC 0x0c0583a2 */
if(!s->budget--) { s->failed_pc=0x0c0583a2u; return 0; }
r[7]+=0xfffffffeu;
goto P_0c0583a4;
P_0c0583a4: /* original 0429, guest PC 0x0c0583a4 */
if(!s->budget--) { s->failed_pc=0x0c0583a4u; return 0; }
r[4]=r[17]&1u;
goto P_0c0583a6;
P_0c0583a6: /* original 4215, guest PC 0x0c0583a6 */
if(!s->budget--) { s->failed_pc=0x0c0583a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0583a8;
P_0c0583a8: /* original 344e, guest PC 0x0c0583a8 */
if(!s->budget--) { s->failed_pc=0x0c0583a8u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583aa;
P_0c0583aa: /* original 234a, guest PC 0x0c0583aa */
if(!s->budget--) { s->failed_pc=0x0c0583aau; return 0; }
r[3]^=r[4];
goto P_0c0583ac;
P_0c0583ac: /* original 31a6, guest PC 0x0c0583ac */
if(!s->budget--) { s->failed_pc=0x0c0583acu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[10])!=0);
goto P_0c0583ae;
P_0c0583ae: /* original 66e5, guest PC 0x0c0583ae */
if(!s->budget--) { s->failed_pc=0x0c0583aeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
goto P_0c0583b0;
P_0c0583b0: /* original 344e, guest PC 0x0c0583b0 */
if(!s->budget--) { s->failed_pc=0x0c0583b0u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583b2;
P_0c0583b2: /* original 4115, guest PC 0x0c0583b2 */
if(!s->budget--) { s->failed_pc=0x0c0583b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0583b4;
P_0c0583b4: /* original 344e, guest PC 0x0c0583b4 */
if(!s->budget--) { s->failed_pc=0x0c0583b4u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583b6;
P_0c0583b6: /* original 234a, guest PC 0x0c0583b6 */
if(!s->budget--) { s->failed_pc=0x0c0583b6u; return 0; }
r[3]^=r[4];
goto P_0c0583b8;
P_0c0583b8: /* original 4608, guest PC 0x0c0583b8 */
if(!s->budget--) { s->failed_pc=0x0c0583b8u; return 0; }
r[6]<<=2;
goto P_0c0583ba;
P_0c0583ba: /* original 4608, guest PC 0x0c0583ba */
if(!s->budget--) { s->failed_pc=0x0c0583bau; return 0; }
r[6]<<=2;
goto P_0c0583bc;
P_0c0583bc: /* original 36dc, guest PC 0x0c0583bc */
if(!s->budget--) { s->failed_pc=0x0c0583bcu; return 0; }
r[6]+=r[13];
goto P_0c0583be;
P_0c0583be: /* original 5262, guest PC 0x0c0583be */
if(!s->budget--) { s->failed_pc=0x0c0583beu; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c0583c0;
P_0c0583c0: /* original f868, guest PC 0x0c0583c0 */
if(!s->budget--) { s->failed_pc=0x0c0583c0u; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
goto P_0c0583c2;
P_0c0583c2: /* original 32a6, guest PC 0x0c0583c2 */
if(!s->budget--) { s->failed_pc=0x0c0583c2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[10])!=0);
goto P_0c0583c4;
P_0c0583c4: /* original 344e, guest PC 0x0c0583c4 */
if(!s->budget--) { s->failed_pc=0x0c0583c4u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583c6;
P_0c0583c6: /* original 4215, guest PC 0x0c0583c6 */
if(!s->budget--) { s->failed_pc=0x0c0583c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0583c8;
P_0c0583c8: /* original 344e, guest PC 0x0c0583c8 */
if(!s->budget--) { s->failed_pc=0x0c0583c8u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583ca;
P_0c0583ca: /* original 234a, guest PC 0x0c0583ca */
if(!s->budget--) { s->failed_pc=0x0c0583cau; return 0; }
r[3]^=r[4];
goto P_0c0583cc;
P_0c0583cc: /* original 6043, guest PC 0x0c0583cc */
if(!s->budget--) { s->failed_pc=0x0c0583ccu; return 0; }
r[0]=r[4];
goto P_0c0583ce;
P_0c0583ce: /* original c810, guest PC 0x0c0583ce */
if(!s->budget--) { s->failed_pc=0x0c0583ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0583d0;
P_0c0583d0: /* original 0229, guest PC 0x0c0583d0 */
if(!s->budget--) { s->failed_pc=0x0c0583d0u; return 0; }
r[2]=r[17]&1u;
goto P_0c0583d2;
P_0c0583d2: /* original c92a, guest PC 0x0c0583d2 */
if(!s->budget--) { s->failed_pc=0x0c0583d2u; return 0; }
r[0]&=42u;
goto P_0c0583d4;
P_0c0583d4: /* original 882a, guest PC 0x0c0583d4 */
if(!s->budget--) { s->failed_pc=0x0c0583d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002au)!=0);
goto P_0c0583d6;
P_0c0583d6: /* original f64c, guest PC 0x0c0583d6 */
if(!s->budget--) { s->failed_pc=0x0c0583d6u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0583d8;
P_0c0583d8: /* original 8d54, guest PC 0x0c0583d8 */
if(!s->budget--) { s->failed_pc=0x0c0583d8u; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
if(cond) { goto P_0c058484; }
goto P_0c0583dc;
P_0c0583da: /* original f681, guest PC 0x0c0583da */
if(!s->budget--) { s->failed_pc=0x0c0583dau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c0583dc;
P_0c0583dc: /* original f191, guest PC 0x0c0583dc */
if(!s->budget--) { s->failed_pc=0x0c0583dcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'-');
goto P_0c0583de;
P_0c0583de: /* original f791, guest PC 0x0c0583de */
if(!s->budget--) { s->failed_pc=0x0c0583deu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c0583e0;
P_0c0583e0: /* original f081, guest PC 0x0c0583e0 */
if(!s->budget--) { s->failed_pc=0x0c0583e0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c0583e2;
P_0c0583e2: /* original f64d, guest PC 0x0c0583e2 */
if(!s->budget--) { s->failed_pc=0x0c0583e2u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0583e4;
P_0c0583e4: /* original f612, guest PC 0x0c0583e4 */
if(!s->budget--) { s->failed_pc=0x0c0583e4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'*');
goto P_0c0583e6;
P_0c0583e6: /* original e101, guest PC 0x0c0583e6 */
if(!s->budget--) { s->failed_pc=0x0c0583e6u; return 0; }
r[1]=0x00000001u;
goto P_0c0583e8;
P_0c0583e8: /* original f67e, guest PC 0x0c0583e8 */
if(!s->budget--) { s->failed_pc=0x0c0583e8u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[7],fr[6],r[18]);
goto P_0c0583ea;
P_0c0583ea: /* original 2318, guest PC 0x0c0583ea */
if(!s->budget--) { s->failed_pc=0x0c0583eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c0583ec;
P_0c0583ec: /* original f08d, guest PC 0x0c0583ec */
if(!s->budget--) { s->failed_pc=0x0c0583ecu; return 0; }
fr[0]=0;
goto P_0c0583ee;
P_0c0583ee: /* original 8900, guest PC 0x0c0583ee */
if(!s->budget--) { s->failed_pc=0x0c0583eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0583f2; }
goto P_0c0583f0;
P_0c0583f0: /* original f64d, guest PC 0x0c0583f0 */
if(!s->budget--) { s->failed_pc=0x0c0583f0u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0583f2;
P_0c0583f2: /* original f605, guest PC 0x0c0583f2 */
if(!s->budget--) { s->failed_pc=0x0c0583f2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[0]))!=0);
goto P_0c0583f4;
P_0c0583f4: /* original 8d46, guest PC 0x0c0583f4 */
if(!s->budget--) { s->failed_pc=0x0c0583f4u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&42u)==0)!=0);
if(cond) { goto P_0c058484; }
goto P_0c0583f8;
P_0c0583f6: /* original c82a, guest PC 0x0c0583f6 */
if(!s->budget--) { s->failed_pc=0x0c0583f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&42u)==0)!=0);
goto P_0c0583f8;
P_0c0583f8: /* original 232a, guest PC 0x0c0583f8 */
if(!s->budget--) { s->failed_pc=0x0c0583f8u; return 0; }
r[3]^=r[2];
goto P_0c0583fa;
P_0c0583fa: /* original 8b3a, guest PC 0x0c0583fa */
if(!s->budget--) { s->failed_pc=0x0c0583fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c058472; }
goto P_0c0583fc;
P_0c0583fc: /* original 62e3, guest PC 0x0c0583fc */
if(!s->budget--) { s->failed_pc=0x0c0583fcu; return 0; }
r[2]=r[14];
goto P_0c0583fe;
P_0c0583fe: /* original 72d0, guest PC 0x0c0583fe */
if(!s->budget--) { s->failed_pc=0x0c0583feu; return 0; }
r[2]+=0xffffffd0u;
goto P_0c058400;
P_0c058400: /* original b07e, guest PC 0x0c058400 */
if(!s->budget--) { s->failed_pc=0x0c058400u; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058404u;
r[5]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058404u) { target=s->pc; goto dispatch; }
goto P_0c058404;
P_0c058402: /* original 6583, guest PC 0x0c058402 */
if(!s->budget--) { s->failed_pc=0x0c058402u; return 0; }
r[5]=r[8];
goto P_0c058404;
P_0c058404: /* original 0c83, guest PC 0x0c058404 */
if(!s->budget--) { s->failed_pc=0x0c058404u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058406;
P_0c058406: /* original 7c20, guest PC 0x0c058406 */
if(!s->budget--) { s->failed_pc=0x0c058406u; return 0; }
r[12]+=0x00000020u;
goto P_0c058408;
P_0c058408: /* original 62e3, guest PC 0x0c058408 */
if(!s->budget--) { s->failed_pc=0x0c058408u; return 0; }
r[2]=r[14];
goto P_0c05840a;
P_0c05840a: /* original 72e8, guest PC 0x0c05840a */
if(!s->budget--) { s->failed_pc=0x0c05840au; return 0; }
r[2]+=0xffffffe8u;
goto P_0c05840c;
P_0c05840c: /* original b078, guest PC 0x0c05840c */
if(!s->budget--) { s->failed_pc=0x0c05840cu; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058410u;
r[5]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058410u) { target=s->pc; goto dispatch; }
goto P_0c058410;
P_0c05840e: /* original 6593, guest PC 0x0c05840e */
if(!s->budget--) { s->failed_pc=0x0c05840eu; return 0; }
r[5]=r[9];
goto P_0c058410;
P_0c058410: /* original 6893, guest PC 0x0c058410 */
if(!s->budget--) { s->failed_pc=0x0c058410u; return 0; }
r[8]=r[9];
goto P_0c058412;
P_0c058412: /* original b095, guest PC 0x0c058412 */
if(!s->budget--) { s->failed_pc=0x0c058412u; return 0; }
target=0x0c058540u; r[16]=code_base|0x0c058416u;
r[9]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058416u) { target=s->pc; goto dispatch; }
goto P_0c058416;
P_0c058414: /* original 6963, guest PC 0x0c058414 */
if(!s->budget--) { s->failed_pc=0x0c058414u; return 0; }
r[9]=r[6];
goto P_0c058416;
P_0c058416: /* original 4710, guest PC 0x0c058416 */
if(!s->budget--) { s->failed_pc=0x0c058416u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c058418;
P_0c058418: /* original 60e1, guest PC 0x0c058418 */
if(!s->budget--) { s->failed_pc=0x0c058418u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c05841a;
P_0c05841a: /* original 894f, guest PC 0x0c05841a */
if(!s->budget--) { s->failed_pc=0x0c05841au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0584bc; }
goto P_0c05841c;
P_0c05841c: /* original 7e02, guest PC 0x0c05841c */
if(!s->budget--) { s->failed_pc=0x0c05841cu; return 0; }
r[14]+=0x00000002u;
goto P_0c05841e;
P_0c05841e: /* original 4008, guest PC 0x0c05841e */
if(!s->budget--) { s->failed_pc=0x0c05841eu; return 0; }
r[0]<<=2;
goto P_0c058420;
P_0c058420: /* original 4008, guest PC 0x0c058420 */
if(!s->budget--) { s->failed_pc=0x0c058420u; return 0; }
r[0]<<=2;
goto P_0c058422;
P_0c058422: /* original 6603, guest PC 0x0c058422 */
if(!s->budget--) { s->failed_pc=0x0c058422u; return 0; }
r[6]=r[0];
goto P_0c058424;
P_0c058424: /* original f8d6, guest PC 0x0c058424 */
if(!s->budget--) { s->failed_pc=0x0c058424u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c058426;
P_0c058426: /* original 36dc, guest PC 0x0c058426 */
if(!s->budget--) { s->failed_pc=0x0c058426u; return 0; }
r[6]+=r[13];
goto P_0c058428;
P_0c058428: /* original 5262, guest PC 0x0c058428 */
if(!s->budget--) { s->failed_pc=0x0c058428u; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c05842a;
P_0c05842a: /* original f498, guest PC 0x0c05842a */
if(!s->budget--) { s->failed_pc=0x0c05842au; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c05842c;
P_0c05842c: /* original f088, guest PC 0x0c05842c */
if(!s->budget--) { s->failed_pc=0x0c05842cu; return 0; }
vf3_matrix_load(s,ram,0,r[8]);
goto P_0c05842e;
P_0c05842e: /* original 32a6, guest PC 0x0c05842e */
if(!s->budget--) { s->failed_pc=0x0c05842eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[10])!=0);
goto P_0c058430;
P_0c058430: /* original 344e, guest PC 0x0c058430 */
if(!s->budget--) { s->failed_pc=0x0c058430u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c058432;
P_0c058432: /* original f64c, guest PC 0x0c058432 */
if(!s->budget--) { s->failed_pc=0x0c058432u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c058434;
P_0c058434: /* original f681, guest PC 0x0c058434 */
if(!s->budget--) { s->failed_pc=0x0c058434u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c058436;
P_0c058436: /* original 4215, guest PC 0x0c058436 */
if(!s->budget--) { s->failed_pc=0x0c058436u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c058438;
P_0c058438: /* original 344e, guest PC 0x0c058438 */
if(!s->budget--) { s->failed_pc=0x0c058438u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c05843a;
P_0c05843a: /* original 234a, guest PC 0x0c05843a */
if(!s->budget--) { s->failed_pc=0x0c05843au; return 0; }
r[3]^=r[4];
goto P_0c05843c;
P_0c05843c: /* original 6043, guest PC 0x0c05843c */
if(!s->budget--) { s->failed_pc=0x0c05843cu; return 0; }
r[0]=r[4];
goto P_0c05843e;
P_0c05843e: /* original f191, guest PC 0x0c05843e */
if(!s->budget--) { s->failed_pc=0x0c05843eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'-');
goto P_0c058440;
P_0c058440: /* original c810, guest PC 0x0c058440 */
if(!s->budget--) { s->failed_pc=0x0c058440u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c058442;
P_0c058442: /* original f791, guest PC 0x0c058442 */
if(!s->budget--) { s->failed_pc=0x0c058442u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c058444;
P_0c058444: /* original 0229, guest PC 0x0c058444 */
if(!s->budget--) { s->failed_pc=0x0c058444u; return 0; }
r[2]=r[17]&1u;
goto P_0c058446;
P_0c058446: /* original f081, guest PC 0x0c058446 */
if(!s->budget--) { s->failed_pc=0x0c058446u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c058448;
P_0c058448: /* original f64d, guest PC 0x0c058448 */
if(!s->budget--) { s->failed_pc=0x0c058448u; return 0; }
fr[6]^=0x80000000u;
goto P_0c05844a;
P_0c05844a: /* original f612, guest PC 0x0c05844a */
if(!s->budget--) { s->failed_pc=0x0c05844au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'*');
goto P_0c05844c;
P_0c05844c: /* original e101, guest PC 0x0c05844c */
if(!s->budget--) { s->failed_pc=0x0c05844cu; return 0; }
r[1]=0x00000001u;
goto P_0c05844e;
P_0c05844e: /* original f67e, guest PC 0x0c05844e */
if(!s->budget--) { s->failed_pc=0x0c05844eu; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[7],fr[6],r[18]);
goto P_0c058450;
P_0c058450: /* original 2318, guest PC 0x0c058450 */
if(!s->budget--) { s->failed_pc=0x0c058450u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c058452;
P_0c058452: /* original f08d, guest PC 0x0c058452 */
if(!s->budget--) { s->failed_pc=0x0c058452u; return 0; }
fr[0]=0;
goto P_0c058454;
P_0c058454: /* original 8900, guest PC 0x0c058454 */
if(!s->budget--) { s->failed_pc=0x0c058454u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058458; }
goto P_0c058456;
P_0c058456: /* original f64d, guest PC 0x0c058456 */
if(!s->budget--) { s->failed_pc=0x0c058456u; return 0; }
fr[6]^=0x80000000u;
goto P_0c058458;
P_0c058458: /* original f605, guest PC 0x0c058458 */
if(!s->budget--) { s->failed_pc=0x0c058458u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[0]))!=0);
goto P_0c05845a;
P_0c05845a: /* original 232a, guest PC 0x0c05845a */
if(!s->budget--) { s->failed_pc=0x0c05845au; return 0; }
r[3]^=r[2];
goto P_0c05845c;
P_0c05845c: /* original 8d1f, guest PC 0x0c05845c */
if(!s->budget--) { s->failed_pc=0x0c05845cu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
if(cond) { goto P_0c05849e; }
goto P_0c058460;
P_0c05845e: /* original c802, guest PC 0x0c05845e */
if(!s->budget--) { s->failed_pc=0x0c05845eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c058460;
P_0c058460: /* original 8b1b, guest PC 0x0c058460 */
if(!s->budget--) { s->failed_pc=0x0c058460u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05849a; }
goto P_0c058462;
P_0c058462: /* original 6893, guest PC 0x0c058462 */
if(!s->budget--) { s->failed_pc=0x0c058462u; return 0; }
r[8]=r[9];
goto P_0c058464;
P_0c058464: /* original b06c, guest PC 0x0c058464 */
if(!s->budget--) { s->failed_pc=0x0c058464u; return 0; }
target=0x0c058540u; r[16]=code_base|0x0c058468u;
r[9]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058468u) { target=s->pc; goto dispatch; }
goto P_0c058468;
P_0c058466: /* original 6963, guest PC 0x0c058466 */
if(!s->budget--) { s->failed_pc=0x0c058466u; return 0; }
r[9]=r[6];
goto P_0c058468;
P_0c058468: /* original 4710, guest PC 0x0c058468 */
if(!s->budget--) { s->failed_pc=0x0c058468u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c05846a;
P_0c05846a: /* original 60e1, guest PC 0x0c05846a */
if(!s->budget--) { s->failed_pc=0x0c05846au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c05846c;
P_0c05846c: /* original 8bd6, guest PC 0x0c05846c */
if(!s->budget--) { s->failed_pc=0x0c05846cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05841c; }
goto P_0c05846e;
P_0c05846e: /* original a025, guest PC 0x0c05846e */
if(!s->budget--) { s->failed_pc=0x0c05846eu; return 0; }
goto P_0c0584bc;
P_0c058470: /* original 0009, guest PC 0x0c058470 */
if(!s->budget--) { s->failed_pc=0x0c058470u; return 0; }
goto P_0c058472;
P_0c058472: /* original b179, guest PC 0x0c058472 */
if(!s->budget--) { s->failed_pc=0x0c058472u; return 0; }
target=0x0c058768u; r[16]=code_base|0x0c058476u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058476u) { target=s->pc; goto dispatch; }
goto P_0c058476;
P_0c058474: /* original 0009, guest PC 0x0c058474 */
if(!s->budget--) { s->failed_pc=0x0c058474u; return 0; }
goto P_0c058476;
P_0c058476: /* original 60c3, guest PC 0x0c058476 */
if(!s->budget--) { s->failed_pc=0x0c058476u; return 0; }
r[0]=r[12];
goto P_0c058478;
P_0c058478: /* original 4021, guest PC 0x0c058478 */
if(!s->budget--) { s->failed_pc=0x0c058478u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c05847a;
P_0c05847a: /* original e200, guest PC 0x0c05847a */
if(!s->budget--) { s->failed_pc=0x0c05847au; return 0; }
r[2]=0x00000000u;
goto P_0c05847c;
P_0c05847c: /* original 2c02, guest PC 0x0c05847c */
if(!s->budget--) { s->failed_pc=0x0c05847cu; return 0; }
write(ram,r[12],r[0],4);
goto P_0c05847e;
P_0c05847e: /* original e500, guest PC 0x0c05847e */
if(!s->budget--) { s->failed_pc=0x0c05847eu; return 0; }
r[5]=0x00000000u;
goto P_0c058480;
P_0c058480: /* original 0c83, guest PC 0x0c058480 */
if(!s->budget--) { s->failed_pc=0x0c058480u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058482;
P_0c058482: /* original 7c20, guest PC 0x0c058482 */
if(!s->budget--) { s->failed_pc=0x0c058482u; return 0; }
r[12]+=0x00000020u;
goto P_0c058484;
P_0c058484: /* original 232a, guest PC 0x0c058484 */
if(!s->budget--) { s->failed_pc=0x0c058484u; return 0; }
r[3]^=r[2];
goto P_0c058486;
P_0c058486: /* original f04c, guest PC 0x0c058486 */
if(!s->budget--) { s->failed_pc=0x0c058486u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c058488;
P_0c058488: /* original 6893, guest PC 0x0c058488 */
if(!s->budget--) { s->failed_pc=0x0c058488u; return 0; }
r[8]=r[9];
goto P_0c05848a;
P_0c05848a: /* original f48c, guest PC 0x0c05848a */
if(!s->budget--) { s->failed_pc=0x0c05848au; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c05848c;
P_0c05848c: /* original 4710, guest PC 0x0c05848c */
if(!s->budget--) { s->failed_pc=0x0c05848cu; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c05848e;
P_0c05848e: /* original 7e16, guest PC 0x0c05848e */
if(!s->budget--) { s->failed_pc=0x0c05848eu; return 0; }
r[14]+=0x00000016u;
goto P_0c058490;
P_0c058490: /* original 6963, guest PC 0x0c058490 */
if(!s->budget--) { s->failed_pc=0x0c058490u; return 0; }
r[9]=r[6];
goto P_0c058492;
P_0c058492: /* original 66e5, guest PC 0x0c058492 */
if(!s->budget--) { s->failed_pc=0x0c058492u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
goto P_0c058494;
P_0c058494: /* original 8b90, guest PC 0x0c058494 */
if(!s->budget--) { s->failed_pc=0x0c058494u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0583b8; }
goto P_0c058496;
P_0c058496: /* original a011, guest PC 0x0c058496 */
if(!s->budget--) { s->failed_pc=0x0c058496u; return 0; }
r[14]+=0xfffffffeu;
goto P_0c0584bc;
P_0c058498: /* original 7efe, guest PC 0x0c058498 */
if(!s->budget--) { s->failed_pc=0x0c058498u; return 0; }
r[14]+=0xfffffffeu;
goto P_0c05849a;
P_0c05849a: /* original b2df, guest PC 0x0c05849a */
if(!s->budget--) { s->failed_pc=0x0c05849au; return 0; }
target=0x0c058a5cu; r[16]=code_base|0x0c05849eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05849eu) { target=s->pc; goto dispatch; }
goto P_0c05849e;
P_0c05849c: /* original 0009, guest PC 0x0c05849c */
if(!s->budget--) { s->failed_pc=0x0c05849cu; return 0; }
goto P_0c05849e;
P_0c05849e: /* original 61c3, guest PC 0x0c05849e */
if(!s->budget--) { s->failed_pc=0x0c05849eu; return 0; }
r[1]=r[12];
goto P_0c0584a0;
P_0c0584a0: /* original 4121, guest PC 0x0c0584a0 */
if(!s->budget--) { s->failed_pc=0x0c0584a0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c0584a2;
P_0c0584a2: /* original f04c, guest PC 0x0c0584a2 */
if(!s->budget--) { s->failed_pc=0x0c0584a2u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0584a4;
P_0c0584a4: /* original 6893, guest PC 0x0c0584a4 */
if(!s->budget--) { s->failed_pc=0x0c0584a4u; return 0; }
r[8]=r[9];
goto P_0c0584a6;
P_0c0584a6: /* original f48c, guest PC 0x0c0584a6 */
if(!s->budget--) { s->failed_pc=0x0c0584a6u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0584a8;
P_0c0584a8: /* original 2c12, guest PC 0x0c0584a8 */
if(!s->budget--) { s->failed_pc=0x0c0584a8u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0584aa;
P_0c0584aa: /* original 7e16, guest PC 0x0c0584aa */
if(!s->budget--) { s->failed_pc=0x0c0584aau; return 0; }
r[14]+=0x00000016u;
goto P_0c0584ac;
P_0c0584ac: /* original 0c83, guest PC 0x0c0584ac */
if(!s->budget--) { s->failed_pc=0x0c0584acu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0584ae;
P_0c0584ae: /* original 4710, guest PC 0x0c0584ae */
if(!s->budget--) { s->failed_pc=0x0c0584aeu; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c0584b0;
P_0c0584b0: /* original 6963, guest PC 0x0c0584b0 */
if(!s->budget--) { s->failed_pc=0x0c0584b0u; return 0; }
r[9]=r[6];
goto P_0c0584b2;
P_0c0584b2: /* original 7c20, guest PC 0x0c0584b2 */
if(!s->budget--) { s->failed_pc=0x0c0584b2u; return 0; }
r[12]+=0x00000020u;
goto P_0c0584b4;
P_0c0584b4: /* original 8f80, guest PC 0x0c0584b4 */
if(!s->budget--) { s->failed_pc=0x0c0584b4u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
if(!cond) { goto P_0c0583b8; }
goto P_0c0584b8;
P_0c0584b6: /* original 66e5, guest PC 0x0c0584b6 */
if(!s->budget--) { s->failed_pc=0x0c0584b6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
goto P_0c0584b8;
P_0c0584b8: /* original a007, guest PC 0x0c0584b8 */
if(!s->budget--) { s->failed_pc=0x0c0584b8u; return 0; }
r[14]+=0xfffffffeu;
goto P_0c0584ca;
P_0c0584ba: /* original 7efe, guest PC 0x0c0584ba */
if(!s->budget--) { s->failed_pc=0x0c0584bau; return 0; }
r[14]+=0xfffffffeu;
goto P_0c0584bc;
P_0c0584bc: /* original 2558, guest PC 0x0c0584bc */
if(!s->budget--) { s->failed_pc=0x0c0584bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0584be;
P_0c0584be: /* original 8904, guest PC 0x0c0584be */
if(!s->budget--) { s->failed_pc=0x0c0584beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0584ca; }
goto P_0c0584c0;
P_0c0584c0: /* original 60c3, guest PC 0x0c0584c0 */
if(!s->budget--) { s->failed_pc=0x0c0584c0u; return 0; }
r[0]=r[12];
goto P_0c0584c2;
P_0c0584c2: /* original 4021, guest PC 0x0c0584c2 */
if(!s->budget--) { s->failed_pc=0x0c0584c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c0584c4;
P_0c0584c4: /* original 2c02, guest PC 0x0c0584c4 */
if(!s->budget--) { s->failed_pc=0x0c0584c4u; return 0; }
write(ram,r[12],r[0],4);
goto P_0c0584c6;
P_0c0584c6: /* original 0c83, guest PC 0x0c0584c6 */
if(!s->budget--) { s->failed_pc=0x0c0584c6u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0584c8;
P_0c0584c8: /* original 7c20, guest PC 0x0c0584c8 */
if(!s->budget--) { s->failed_pc=0x0c0584c8u; return 0; }
r[12]+=0x00000020u;
goto P_0c0584ca;
P_0c0584ca: /* original 4b10, guest PC 0x0c0584ca */
if(!s->budget--) { s->failed_pc=0x0c0584cau; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0584cc;
P_0c0584cc: /* original 8901, guest PC 0x0c0584cc */
if(!s->budget--) { s->failed_pc=0x0c0584ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0584d2; }
goto P_0c0584ce;
P_0c0584ce: /* original af55, guest PC 0x0c0584ce */
if(!s->budget--) { s->failed_pc=0x0c0584ceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[7]=tmp;
goto P_0c05837c;
P_0c0584d0: /* original 67e5, guest PC 0x0c0584d0 */
if(!s->budget--) { s->failed_pc=0x0c0584d0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[7]=tmp;
goto P_0c0584d2;
P_0c0584d2: /* original 01b2, guest PC 0x0c0584d2 */
if(!s->budget--) { s->failed_pc=0x0c0584d2u; return 0; }
if(!s->bank_known) goto unsupported;
r[1]=s->bank[3];
goto P_0c0584d4;
P_0c0584d4: /* original 21c2, guest PC 0x0c0584d4 */
if(!s->budget--) { s->failed_pc=0x0c0584d4u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c0584d6;
P_0c0584d6: /* original f2fc, guest PC 0x0c0584d6 */
if(!s->budget--) { s->failed_pc=0x0c0584d6u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0584d8;
P_0c0584d8: /* original f3fd, guest PC 0x0c0584d8 */
if(!s->budget--) { s->failed_pc=0x0c0584d8u; return 0; }
r[18]^=0x100000u;
goto P_0c0584da;
P_0c0584da: /* original 64e3, guest PC 0x0c0584da */
if(!s->budget--) { s->failed_pc=0x0c0584dau; return 0; }
r[4]=r[14];
goto P_0c0584dc;
P_0c0584dc: /* original 4f26, guest PC 0x0c0584dc */
if(!s->budget--) { s->failed_pc=0x0c0584dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0584de;
P_0c0584de: /* original 000b, guest PC 0x0c0584de */
if(!s->budget--) { s->failed_pc=0x0c0584deu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0584e0: /* original 6ef6, guest PC 0x0c0584e0 */
if(!s->budget--) { s->failed_pc=0x0c0584e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0584e2u,s,ram);
P_0c058540: /* original 2fe6, guest PC 0x0c058540 */
if(!s->budget--) { s->failed_pc=0x0c058540u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c058542;
P_0c058542: /* original 7e04, guest PC 0x0c058542 */
if(!s->budget--) { s->failed_pc=0x0c058542u; return 0; }
r[14]+=0x00000004u;
goto P_0c058544;
P_0c058544: /* original 60e5, guest PC 0x0c058544 */
if(!s->budget--) { s->failed_pc=0x0c058544u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c058546;
P_0c058546: /* original 61e5, guest PC 0x0c058546 */
if(!s->budget--) { s->failed_pc=0x0c058546u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[1]=tmp;
goto P_0c058548;
P_0c058548: /* original 62e5, guest PC 0x0c058548 */
if(!s->budget--) { s->failed_pc=0x0c058548u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[2]=tmp;
goto P_0c05854a;
P_0c05854a: /* original f38d, guest PC 0x0c05854a */
if(!s->budget--) { s->failed_pc=0x0c05854au; return 0; }
fr[3]=0;
goto P_0c05854c;
P_0c05854c: /* original 4028, guest PC 0x0c05854c */
if(!s->budget--) { s->failed_pc=0x0c05854cu; return 0; }
r[0]<<=16;
goto P_0c05854e;
P_0c05854e: /* original 405a, guest PC 0x0c05854e */
if(!s->budget--) { s->failed_pc=0x0c05854eu; return 0; }
r[53]=r[0];
goto P_0c058550;
P_0c058550: /* original 4128, guest PC 0x0c058550 */
if(!s->budget--) { s->failed_pc=0x0c058550u; return 0; }
r[1]<<=16;
goto P_0c058552;
P_0c058552: /* original f00d, guest PC 0x0c058552 */
if(!s->budget--) { s->failed_pc=0x0c058552u; return 0; }
fr[0]=r[53];
goto P_0c058554;
P_0c058554: /* original 4228, guest PC 0x0c058554 */
if(!s->budget--) { s->failed_pc=0x0c058554u; return 0; }
r[2]<<=16;
goto P_0c058556;
P_0c058556: /* original 415a, guest PC 0x0c058556 */
if(!s->budget--) { s->failed_pc=0x0c058556u; return 0; }
r[53]=r[1];
goto P_0c058558;
P_0c058558: /* original f10d, guest PC 0x0c058558 */
if(!s->budget--) { s->failed_pc=0x0c058558u; return 0; }
fr[1]=r[53];
goto P_0c05855a;
P_0c05855a: /* original 425a, guest PC 0x0c05855a */
if(!s->budget--) { s->failed_pc=0x0c05855au; return 0; }
r[53]=r[2];
goto P_0c05855c;
P_0c05855c: /* original f20d, guest PC 0x0c05855c */
if(!s->budget--) { s->failed_pc=0x0c05855cu; return 0; }
fr[2]=r[53];
goto P_0c05855e;
P_0c05855e: /* original f1fd, guest PC 0x0c05855e */
if(!s->budget--) { s->failed_pc=0x0c05855eu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c058560;
P_0c058560: /* original 60e5, guest PC 0x0c058560 */
if(!s->budget--) { s->failed_pc=0x0c058560u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c058562;
P_0c058562: /* original 61e5, guest PC 0x0c058562 */
if(!s->budget--) { s->failed_pc=0x0c058562u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[1]=tmp;
goto P_0c058564;
P_0c058564: /* original 62e5, guest PC 0x0c058564 */
if(!s->budget--) { s->failed_pc=0x0c058564u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[2]=tmp;
goto P_0c058566;
P_0c058566: /* original f78d, guest PC 0x0c058566 */
if(!s->budget--) { s->failed_pc=0x0c058566u; return 0; }
fr[7]=0;
goto P_0c058568;
P_0c058568: /* original 4028, guest PC 0x0c058568 */
if(!s->budget--) { s->failed_pc=0x0c058568u; return 0; }
r[0]<<=16;
goto P_0c05856a;
P_0c05856a: /* original 405a, guest PC 0x0c05856a */
if(!s->budget--) { s->failed_pc=0x0c05856au; return 0; }
r[53]=r[0];
goto P_0c05856c;
P_0c05856c: /* original 4128, guest PC 0x0c05856c */
if(!s->budget--) { s->failed_pc=0x0c05856cu; return 0; }
r[1]<<=16;
goto P_0c05856e;
P_0c05856e: /* original f40d, guest PC 0x0c05856e */
if(!s->budget--) { s->failed_pc=0x0c05856eu; return 0; }
fr[4]=r[53];
goto P_0c058570;
P_0c058570: /* original 4228, guest PC 0x0c058570 */
if(!s->budget--) { s->failed_pc=0x0c058570u; return 0; }
r[2]<<=16;
goto P_0c058572;
P_0c058572: /* original 415a, guest PC 0x0c058572 */
if(!s->budget--) { s->failed_pc=0x0c058572u; return 0; }
r[53]=r[1];
goto P_0c058574;
P_0c058574: /* original f50d, guest PC 0x0c058574 */
if(!s->budget--) { s->failed_pc=0x0c058574u; return 0; }
fr[5]=r[53];
goto P_0c058576;
P_0c058576: /* original 425a, guest PC 0x0c058576 */
if(!s->budget--) { s->failed_pc=0x0c058576u; return 0; }
r[53]=r[2];
goto P_0c058578;
P_0c058578: /* original f60d, guest PC 0x0c058578 */
if(!s->budget--) { s->failed_pc=0x0c058578u; return 0; }
fr[6]=r[53];
goto P_0c05857a;
P_0c05857a: /* original f5fd, guest PC 0x0c05857a */
if(!s->budget--) { s->failed_pc=0x0c05857au; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c05857c;
P_0c05857c: /* original 60e5, guest PC 0x0c05857c */
if(!s->budget--) { s->failed_pc=0x0c05857cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c05857e;
P_0c05857e: /* original 61e5, guest PC 0x0c05857e */
if(!s->budget--) { s->failed_pc=0x0c05857eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[1]=tmp;
goto P_0c058580;
P_0c058580: /* original 62e5, guest PC 0x0c058580 */
if(!s->budget--) { s->failed_pc=0x0c058580u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[2]=tmp;
goto P_0c058582;
P_0c058582: /* original fb8d, guest PC 0x0c058582 */
if(!s->budget--) { s->failed_pc=0x0c058582u; return 0; }
fr[11]=0;
goto P_0c058584;
P_0c058584: /* original 4028, guest PC 0x0c058584 */
if(!s->budget--) { s->failed_pc=0x0c058584u; return 0; }
r[0]<<=16;
goto P_0c058586;
P_0c058586: /* original 405a, guest PC 0x0c058586 */
if(!s->budget--) { s->failed_pc=0x0c058586u; return 0; }
r[53]=r[0];
goto P_0c058588;
P_0c058588: /* original 4128, guest PC 0x0c058588 */
if(!s->budget--) { s->failed_pc=0x0c058588u; return 0; }
r[1]<<=16;
goto P_0c05858a;
P_0c05858a: /* original f80d, guest PC 0x0c05858a */
if(!s->budget--) { s->failed_pc=0x0c05858au; return 0; }
fr[8]=r[53];
goto P_0c05858c;
P_0c05858c: /* original 4228, guest PC 0x0c05858c */
if(!s->budget--) { s->failed_pc=0x0c05858cu; return 0; }
r[2]<<=16;
goto P_0c05858e;
P_0c05858e: /* original 415a, guest PC 0x0c05858e */
if(!s->budget--) { s->failed_pc=0x0c05858eu; return 0; }
r[53]=r[1];
goto P_0c058590;
P_0c058590: /* original f90d, guest PC 0x0c058590 */
if(!s->budget--) { s->failed_pc=0x0c058590u; return 0; }
fr[9]=r[53];
goto P_0c058592;
P_0c058592: /* original 425a, guest PC 0x0c058592 */
if(!s->budget--) { s->failed_pc=0x0c058592u; return 0; }
r[53]=r[2];
goto P_0c058594;
P_0c058594: /* original fa0d, guest PC 0x0c058594 */
if(!s->budget--) { s->failed_pc=0x0c058594u; return 0; }
fr[10]=r[53];
goto P_0c058596;
P_0c058596: /* original f9fd, guest PC 0x0c058596 */
if(!s->budget--) { s->failed_pc=0x0c058596u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c058598;
P_0c058598: /* original 0c83, guest PC 0x0c058598 */
if(!s->budget--) { s->failed_pc=0x0c058598u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05859a;
P_0c05859a: /* original fcdc, guest PC 0x0c05859a */
if(!s->budget--) { s->failed_pc=0x0c05859au; return 0; }
vf3_matrix_move(s,12,13);
goto P_0c05859c;
P_0c05859c: /* original fefc, guest PC 0x0c05859c */
if(!s->budget--) { s->failed_pc=0x0c05859cu; return 0; }
vf3_matrix_move(s,14,15);
goto P_0c05859e;
P_0c05859e: /* original f3fd, guest PC 0x0c05859e */
if(!s->budget--) { s->failed_pc=0x0c05859eu; return 0; }
r[18]^=0x100000u;
goto P_0c0585a0;
P_0c0585a0: /* original 62f6, guest PC 0x0c0585a0 */
if(!s->budget--) { s->failed_pc=0x0c0585a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c0585a2;
P_0c0585a2: /* original f11d, guest PC 0x0c0585a2 */
if(!s->budget--) { s->failed_pc=0x0c0585a2u; return 0; }
r[53]=fr[1];
goto P_0c0585a4;
P_0c0585a4: /* original f14c, guest PC 0x0c0585a4 */
if(!s->budget--) { s->failed_pc=0x0c0585a4u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0585a6;
P_0c0585a6: /* original f40d, guest PC 0x0c0585a6 */
if(!s->budget--) { s->failed_pc=0x0c0585a6u; return 0; }
fr[4]=r[53];
goto P_0c0585a8;
P_0c0585a8: /* original f21d, guest PC 0x0c0585a8 */
if(!s->budget--) { s->failed_pc=0x0c0585a8u; return 0; }
r[53]=fr[2];
goto P_0c0585aa;
P_0c0585aa: /* original f28c, guest PC 0x0c0585aa */
if(!s->budget--) { s->failed_pc=0x0c0585aau; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c0585ac;
P_0c0585ac: /* original f80d, guest PC 0x0c0585ac */
if(!s->budget--) { s->failed_pc=0x0c0585acu; return 0; }
fr[8]=r[53];
goto P_0c0585ae;
P_0c0585ae: /* original f61d, guest PC 0x0c0585ae */
if(!s->budget--) { s->failed_pc=0x0c0585aeu; return 0; }
r[53]=fr[6];
goto P_0c0585b0;
P_0c0585b0: /* original f69c, guest PC 0x0c0585b0 */
if(!s->budget--) { s->failed_pc=0x0c0585b0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c0585b2;
P_0c0585b2: /* original f90d, guest PC 0x0c0585b2 */
if(!s->budget--) { s->failed_pc=0x0c0585b2u; return 0; }
fr[9]=r[53];
goto P_0c0585b4;
P_0c0585b4: /* original fbfd, guest PC 0x0c0585b4 */
if(!s->budget--) { s->failed_pc=0x0c0585b4u; return 0; }
vf3_matrix_swap(s);
goto P_0c0585b6;
P_0c0585b6: /* original ff8d, guest PC 0x0c0585b6 */
if(!s->budget--) { s->failed_pc=0x0c0585b6u; return 0; }
fr[15]=0;
goto P_0c0585b8;
P_0c0585b8: /* original fdfd, guest PC 0x0c0585b8 */
if(!s->budget--) { s->failed_pc=0x0c0585b8u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c0585ba;
P_0c0585ba: /* original 6125, guest PC 0x0c0585ba */
if(!s->budget--) { s->failed_pc=0x0c0585bau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c0585bc;
P_0c0585bc: /* original f3fd, guest PC 0x0c0585bc */
if(!s->budget--) { s->failed_pc=0x0c0585bcu; return 0; }
r[18]^=0x100000u;
goto P_0c0585be;
P_0c0585be: /* original 6221, guest PC 0x0c0585be */
if(!s->budget--) { s->failed_pc=0x0c0585beu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c0585c0;
P_0c0585c0: /* original fbfd, guest PC 0x0c0585c0 */
if(!s->budget--) { s->failed_pc=0x0c0585c0u; return 0; }
vf3_matrix_swap(s);
goto P_0c0585c2;
P_0c0585c2: /* original f4dc, guest PC 0x0c0585c2 */
if(!s->budget--) { s->failed_pc=0x0c0585c2u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0585c4;
P_0c0585c4: /* original f6fc, guest PC 0x0c0585c4 */
if(!s->budget--) { s->failed_pc=0x0c0585c4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0585c6;
P_0c0585c6: /* original fdcc, guest PC 0x0c0585c6 */
if(!s->budget--) { s->failed_pc=0x0c0585c6u; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c0585c8;
P_0c0585c8: /* original ffec, guest PC 0x0c0585c8 */
if(!s->budget--) { s->failed_pc=0x0c0585c8u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0585ca;
P_0c0585ca: /* original f3fd, guest PC 0x0c0585ca */
if(!s->budget--) { s->failed_pc=0x0c0585cau; return 0; }
r[18]^=0x100000u;
goto P_0c0585cc;
P_0c0585cc: /* original f38d, guest PC 0x0c0585cc */
if(!s->budget--) { s->failed_pc=0x0c0585ccu; return 0; }
fr[3]=0;
goto P_0c0585ce;
P_0c0585ce: /* original f345, guest PC 0x0c0585ce */
if(!s->budget--) { s->failed_pc=0x0c0585ceu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0585d0;
P_0c0585d0: /* original f45d, guest PC 0x0c0585d0 */
if(!s->budget--) { s->failed_pc=0x0c0585d0u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c0585d2;
P_0c0585d2: /* original 425a, guest PC 0x0c0585d2 */
if(!s->budget--) { s->failed_pc=0x0c0585d2u; return 0; }
r[53]=r[2];
goto P_0c0585d4;
P_0c0585d4: /* original f92d, guest PC 0x0c0585d4 */
if(!s->budget--) { s->failed_pc=0x0c0585d4u; return 0; }
fr[9]=vf3_fpu_float(r[53],r[18]);
goto P_0c0585d6;
P_0c0585d6: /* original 0529, guest PC 0x0c0585d6 */
if(!s->budget--) { s->failed_pc=0x0c0585d6u; return 0; }
r[5]=r[17]&1u;
goto P_0c0585d8;
P_0c0585d8: /* original f365, guest PC 0x0c0585d8 */
if(!s->budget--) { s->failed_pc=0x0c0585d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c0585da;
P_0c0585da: /* original f65d, guest PC 0x0c0585da */
if(!s->budget--) { s->failed_pc=0x0c0585dau; return 0; }
fr[6]&=0x7fffffffu;
goto P_0c0585dc;
P_0c0585dc: /* original 415a, guest PC 0x0c0585dc */
if(!s->budget--) { s->failed_pc=0x0c0585dcu; return 0; }
r[53]=r[1];
goto P_0c0585de;
P_0c0585de: /* original f82d, guest PC 0x0c0585de */
if(!s->budget--) { s->failed_pc=0x0c0585deu; return 0; }
fr[8]=vf3_fpu_float(r[53],r[18]);
goto P_0c0585e0;
P_0c0585e0: /* original 355e, guest PC 0x0c0585e0 */
if(!s->budget--) { s->failed_pc=0x0c0585e0u; return 0; }
wide=(uint64_t)r[5]+r[5]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0585e2;
P_0c0585e2: /* original f645, guest PC 0x0c0585e2 */
if(!s->budget--) { s->failed_pc=0x0c0585e2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[4]))!=0);
goto P_0c0585e4;
P_0c0585e4: /* original c75c, guest PC 0x0c0585e4 */
if(!s->budget--) { s->failed_pc=0x0c0585e4u; return 0; }
r[0]=0x0c058758u;
goto P_0c0585e6;
P_0c0585e6: /* original f61d, guest PC 0x0c0585e6 */
if(!s->budget--) { s->failed_pc=0x0c0585e6u; return 0; }
r[53]=fr[6];
goto P_0c0585e8;
P_0c0585e8: /* original 8b01, guest PC 0x0c0585e8 */
if(!s->budget--) { s->failed_pc=0x0c0585e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0585ee; }
goto P_0c0585ea;
P_0c0585ea: /* original f64c, guest PC 0x0c0585ea */
if(!s->budget--) { s->failed_pc=0x0c0585eau; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0585ec;
P_0c0585ec: /* original f40d, guest PC 0x0c0585ec */
if(!s->budget--) { s->failed_pc=0x0c0585ecu; return 0; }
fr[4]=r[53];
goto P_0c0585ee;
P_0c0585ee: /* original 355e, guest PC 0x0c0585ee */
if(!s->budget--) { s->failed_pc=0x0c0585eeu; return 0; }
wide=(uint64_t)r[5]+r[5]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0585f0;
P_0c0585f0: /* original f643, guest PC 0x0c0585f0 */
if(!s->budget--) { s->failed_pc=0x0c0585f0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'/');
goto P_0c0585f2;
P_0c0585f2: /* original 355c, guest PC 0x0c0585f2 */
if(!s->budget--) { s->failed_pc=0x0c0585f2u; return 0; }
r[5]+=r[5];
goto P_0c0585f4;
P_0c0585f4: /* original f9f2, guest PC 0x0c0585f4 */
if(!s->budget--) { s->failed_pc=0x0c0585f4u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[15],r[18],'*');
goto P_0c0585f6;
P_0c0585f6: /* original 025d, guest PC 0x0c0585f6 */
if(!s->budget--) { s->failed_pc=0x0c0585f6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0585f8;
P_0c0585f8: /* original f8f2, guest PC 0x0c0585f8 */
if(!s->budget--) { s->failed_pc=0x0c0585f8u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c0585fa;
P_0c0585fa: /* original c753, guest PC 0x0c0585fa */
if(!s->budget--) { s->failed_pc=0x0c0585fau; return 0; }
r[0]=0x0c058748u;
goto P_0c0585fc;
P_0c0585fc: /* original f009, guest PC 0x0c0585fc */
if(!s->budget--) { s->failed_pc=0x0c0585fcu; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c0585fe;
P_0c0585fe: /* original f409, guest PC 0x0c0585fe */
if(!s->budget--) { s->failed_pc=0x0c0585feu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c058600;
P_0c058600: /* original f355, guest PC 0x0c058600 */
if(!s->budget--) { s->failed_pc=0x0c058600u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c058602;
P_0c058602: /* original f309, guest PC 0x0c058602 */
if(!s->budget--) { s->failed_pc=0x0c058602u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c058604;
P_0c058604: /* original 6102, guest PC 0x0c058604 */
if(!s->budget--) { s->failed_pc=0x0c058604u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c058606;
P_0c058606: /* original 70fc, guest PC 0x0c058606 */
if(!s->budget--) { s->failed_pc=0x0c058606u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c058608;
P_0c058608: /* original 8905, guest PC 0x0c058608 */
if(!s->budget--) { s->failed_pc=0x0c058608u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058616; }
goto P_0c05860a;
P_0c05860a: /* original f352, guest PC 0x0c05860a */
if(!s->budget--) { s->failed_pc=0x0c05860au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c05860c;
P_0c05860c: /* original 4228, guest PC 0x0c05860c */
if(!s->budget--) { s->failed_pc=0x0c05860cu; return 0; }
r[2]<<=16;
goto P_0c05860e;
P_0c05860e: /* original f33d, guest PC 0x0c05860e */
if(!s->budget--) { s->failed_pc=0x0c05860eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c058610;
P_0c058610: /* original 055a, guest PC 0x0c058610 */
if(!s->budget--) { s->failed_pc=0x0c058610u; return 0; }
r[5]=r[53];
goto P_0c058612;
P_0c058612: /* original 355c, guest PC 0x0c058612 */
if(!s->budget--) { s->failed_pc=0x0c058612u; return 0; }
r[5]+=r[5];
goto P_0c058614;
P_0c058614: /* original 225d, guest PC 0x0c058614 */
if(!s->budget--) { s->failed_pc=0x0c058614u; return 0; }
r[2]=(r[2]>>16)|(r[5]<<16);
goto P_0c058616;
P_0c058616: /* original f46e, guest PC 0x0c058616 */
if(!s->budget--) { s->failed_pc=0x0c058616u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[6],fr[4],r[18]);
goto P_0c058618;
P_0c058618: /* original f608, guest PC 0x0c058618 */
if(!s->budget--) { s->failed_pc=0x0c058618u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c05861a;
P_0c05861a: /* original f552, guest PC 0x0c05861a */
if(!s->budget--) { s->failed_pc=0x0c05861au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[5],r[18],'*');
goto P_0c05861c;
P_0c05861c: /* original 4201, guest PC 0x0c05861c */
if(!s->budget--) { s->failed_pc=0x0c05861cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c05861e;
P_0c05861e: /* original f43d, guest PC 0x0c05861e */
if(!s->budget--) { s->failed_pc=0x0c05861eu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c058620;
P_0c058620: /* original f39d, guest PC 0x0c058620 */
if(!s->budget--) { s->failed_pc=0x0c058620u; return 0; }
fr[3]=0x3f800000u;
goto P_0c058622;
P_0c058622: /* original f351, guest PC 0x0c058622 */
if(!s->budget--) { s->failed_pc=0x0c058622u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c058624;
P_0c058624: /* original 005a, guest PC 0x0c058624 */
if(!s->budget--) { s->failed_pc=0x0c058624u; return 0; }
r[0]=r[53];
goto P_0c058626;
P_0c058626: /* original f36d, guest PC 0x0c058626 */
if(!s->budget--) { s->failed_pc=0x0c058626u; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c058628;
P_0c058628: /* original 600c, guest PC 0x0c058628 */
if(!s->budget--) { s->failed_pc=0x0c058628u; return 0; }
r[0]=r[0]&255u;
goto P_0c05862a;
P_0c05862a: /* original 011c, guest PC 0x0c05862a */
if(!s->budget--) { s->failed_pc=0x0c05862au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c05862c;
P_0c05862c: /* original f362, guest PC 0x0c05862c */
if(!s->budget--) { s->failed_pc=0x0c05862cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c05862e;
P_0c05862e: /* original 8b00, guest PC 0x0c05862e */
if(!s->budget--) { s->failed_pc=0x0c05862eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c058632; }
goto P_0c058630;
P_0c058630: /* original 611b, guest PC 0x0c058630 */
if(!s->budget--) { s->failed_pc=0x0c058630u; return 0; }
r[1]=0u-r[1];
goto P_0c058632;
P_0c058632: /* original 321c, guest PC 0x0c058632 */
if(!s->budget--) { s->failed_pc=0x0c058632u; return 0; }
r[2]+=r[1];
goto P_0c058634;
P_0c058634: /* original f33d, guest PC 0x0c058634 */
if(!s->budget--) { s->failed_pc=0x0c058634u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c058636;
P_0c058636: /* original 6563, guest PC 0x0c058636 */
if(!s->budget--) { s->failed_pc=0x0c058636u; return 0; }
r[5]=r[6];
goto P_0c058638;
P_0c058638: /* original 005a, guest PC 0x0c058638 */
if(!s->budget--) { s->failed_pc=0x0c058638u; return 0; }
r[0]=r[53];
goto P_0c05863a;
P_0c05863a: /* original 4018, guest PC 0x0c05863a */
if(!s->budget--) { s->failed_pc=0x0c05863au; return 0; }
r[0]<<=8;
goto P_0c05863c;
P_0c05863c: /* original 220b, guest PC 0x0c05863c */
if(!s->budget--) { s->failed_pc=0x0c05863cu; return 0; }
r[2]|=r[0];
goto P_0c05863e;
P_0c05863e: /* original c618, guest PC 0x0c05863e */
if(!s->budget--) { s->failed_pc=0x0c05863eu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+96,4);
goto P_0c058640;
P_0c058640: /* original f059, guest PC 0x0c058640 */
if(!s->budget--) { s->failed_pc=0x0c058640u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c058642;
P_0c058642: /* original f159, guest PC 0x0c058642 */
if(!s->budget--) { s->failed_pc=0x0c058642u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c058644;
P_0c058644: /* original 7c3c, guest PC 0x0c058644 */
if(!s->budget--) { s->failed_pc=0x0c058644u; return 0; }
r[12]+=0x0000003cu;
goto P_0c058646;
P_0c058646: /* original f258, guest PC 0x0c058646 */
if(!s->budget--) { s->failed_pc=0x0c058646u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c058648;
P_0c058648: /* original 2c22, guest PC 0x0c058648 */
if(!s->budget--) { s->failed_pc=0x0c058648u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c05864a;
P_0c05864a: /* original 2c06, guest PC 0x0c05864a */
if(!s->budget--) { s->failed_pc=0x0c05864au; return 0; }
tmp=r[0]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c05864c;
P_0c05864c: /* original fc9b, guest PC 0x0c05864c */
if(!s->budget--) { s->failed_pc=0x0c05864cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c05864e;
P_0c05864e: /* original fc8b, guest PC 0x0c05864e */
if(!s->budget--) { s->failed_pc=0x0c05864eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c058650;
P_0c058650: /* original fc2b, guest PC 0x0c058650 */
if(!s->budget--) { s->failed_pc=0x0c058650u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c058652;
P_0c058652: /* original fc1b, guest PC 0x0c058652 */
if(!s->budget--) { s->failed_pc=0x0c058652u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[12]);
goto P_0c058654;
P_0c058654: /* original fc0b, guest PC 0x0c058654 */
if(!s->budget--) { s->failed_pc=0x0c058654u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[12]);
goto P_0c058656;
P_0c058656: /* original f3fd, guest PC 0x0c058656 */
if(!s->budget--) { s->failed_pc=0x0c058656u; return 0; }
r[18]^=0x100000u;
goto P_0c058658;
P_0c058658: /* original 000b, guest PC 0x0c058658 */
if(!s->budget--) { s->failed_pc=0x0c058658u; return 0; }
target=r[16];
tmp=r[12]; r[12]-=4; write(ram,r[12],tmp,4);
s->pc=target; return ram->oob==0;
P_0c05865a: /* original 2cc6, guest PC 0x0c05865a */
if(!s->budget--) { s->failed_pc=0x0c05865au; return 0; }
tmp=r[12]; r[12]-=4; write(ram,r[12],tmp,4);
return vf3_matrix_family(0x0c05865cu,s,ram);
P_0c058768: /* original 6043, guest PC 0x0c058768 */
if(!s->budget--) { s->failed_pc=0x0c058768u; return 0; }
r[0]=r[4];
goto P_0c05876a;
P_0c05876a: /* original c92a, guest PC 0x0c05876a */
if(!s->budget--) { s->failed_pc=0x0c05876au; return 0; }
r[0]&=42u;
goto P_0c05876c;
P_0c05876c: /* original 6103, guest PC 0x0c05876c */
if(!s->budget--) { s->failed_pc=0x0c05876cu; return 0; }
r[1]=r[0];
goto P_0c05876e;
P_0c05876e: /* original 4109, guest PC 0x0c05876e */
if(!s->budget--) { s->failed_pc=0x0c05876eu; return 0; }
r[1]>>=2;
goto P_0c058770;
P_0c058770: /* original 300c, guest PC 0x0c058770 */
if(!s->budget--) { s->failed_pc=0x0c058770u; return 0; }
r[0]+=r[0];
goto P_0c058772;
P_0c058772: /* original 201b, guest PC 0x0c058772 */
if(!s->budget--) { s->failed_pc=0x0c058772u; return 0; }
r[0]|=r[1];
goto P_0c058774;
P_0c058774: /* original c91c, guest PC 0x0c058774 */
if(!s->budget--) { s->failed_pc=0x0c058774u; return 0; }
r[0]&=28u;
goto P_0c058776;
P_0c058776: /* original 0023, guest PC 0x0c058776 */
if(!s->budget--) { s->failed_pc=0x0c058776u; return 0; }
target=r[0]+0x0c05877au;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c058778: /* original 0009, guest PC 0x0c058778 */
if(!s->budget--) { s->failed_pc=0x0c058778u; return 0; }
return vf3_matrix_family(0x0c05877au,s,ram);
P_0c05877e: /* original a00c, guest PC 0x0c05877e */
if(!s->budget--) { s->failed_pc=0x0c05877eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05879a;
P_0c058780: /* original 4f22, guest PC 0x0c058780 */
if(!s->budget--) { s->failed_pc=0x0c058780u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058782;
P_0c058782: /* original a048, guest PC 0x0c058782 */
if(!s->budget--) { s->failed_pc=0x0c058782u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058816;
P_0c058784: /* original 4f22, guest PC 0x0c058784 */
if(!s->budget--) { s->failed_pc=0x0c058784u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058786;
P_0c058786: /* original a0c9, guest PC 0x0c058786 */
if(!s->budget--) { s->failed_pc=0x0c058786u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05891c;
P_0c058788: /* original 4f22, guest PC 0x0c058788 */
if(!s->budget--) { s->failed_pc=0x0c058788u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05878a;
P_0c05878a: /* original a025, guest PC 0x0c05878a */
if(!s->budget--) { s->failed_pc=0x0c05878au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0587d8;
P_0c05878c: /* original 4f22, guest PC 0x0c05878c */
if(!s->budget--) { s->failed_pc=0x0c05878cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05878e;
P_0c05878e: /* original a0af, guest PC 0x0c05878e */
if(!s->budget--) { s->failed_pc=0x0c05878eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0588f0;
P_0c058790: /* original 4f22, guest PC 0x0c058790 */
if(!s->budget--) { s->failed_pc=0x0c058790u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
return vf3_matrix_family(0x0c058792u,s,ram);
P_0c05879a: /* original bf5f, guest PC 0x0c05879a */
if(!s->budget--) { s->failed_pc=0x0c05879au; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c05879eu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05879eu) { target=s->pc; goto dispatch; }
goto P_0c05879e;
P_0c05879c: /* original 65e3, guest PC 0x0c05879c */
if(!s->budget--) { s->failed_pc=0x0c05879cu; return 0; }
r[5]=r[14];
goto P_0c05879e;
P_0c05879e: /* original 2f06, guest PC 0x0c05879e */
if(!s->budget--) { s->failed_pc=0x0c05879eu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0587a0;
P_0c0587a0: /* original e008, guest PC 0x0c0587a0 */
if(!s->budget--) { s->failed_pc=0x0c0587a0u; return 0; }
r[0]=0x00000008u;
goto P_0c0587a2;
P_0c0587a2: /* original f066, guest PC 0x0c0587a2 */
if(!s->budget--) { s->failed_pc=0x0c0587a2u; return 0; }
vf3_matrix_load(s,ram,0,r[6]+r[0]);
goto P_0c0587a4;
P_0c0587a4: /* original 62e3, guest PC 0x0c0587a4 */
if(!s->budget--) { s->failed_pc=0x0c0587a4u; return 0; }
r[2]=r[14];
goto P_0c0587a6;
P_0c0587a6: /* original 72d0, guest PC 0x0c0587a6 */
if(!s->budget--) { s->failed_pc=0x0c0587a6u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c0587a8;
P_0c0587a8: /* original 6583, guest PC 0x0c0587a8 */
if(!s->budget--) { s->failed_pc=0x0c0587a8u; return 0; }
r[5]=r[8];
goto P_0c0587aa;
P_0c0587aa: /* original f79d, guest PC 0x0c0587aa */
if(!s->budget--) { s->failed_pc=0x0c0587aau; return 0; }
fr[7]=0x3f800000u;
goto P_0c0587ac;
P_0c0587ac: /* original bea8, guest PC 0x0c0587ac */
if(!s->budget--) { s->failed_pc=0x0c0587acu; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c0587b0u;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0587b0u) { target=s->pc; goto dispatch; }
goto P_0c0587b0;
P_0c0587ae: /* original f703, guest PC 0x0c0587ae */
if(!s->budget--) { s->failed_pc=0x0c0587aeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
goto P_0c0587b0;
P_0c0587b0: /* original 0c83, guest PC 0x0c0587b0 */
if(!s->budget--) { s->failed_pc=0x0c0587b0u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0587b2;
P_0c0587b2: /* original 7c20, guest PC 0x0c0587b2 */
if(!s->budget--) { s->failed_pc=0x0c0587b2u; return 0; }
r[12]+=0x00000020u;
goto P_0c0587b4;
P_0c0587b4: /* original f80c, guest PC 0x0c0587b4 */
if(!s->budget--) { s->failed_pc=0x0c0587b4u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c0587b6;
P_0c0587b6: /* original fa9d, guest PC 0x0c0587b6 */
if(!s->budget--) { s->failed_pc=0x0c0587b6u; return 0; }
fr[10]=0x3f800000u;
goto P_0c0587b8;
P_0c0587b8: /* original fa23, guest PC 0x0c0587b8 */
if(!s->budget--) { s->failed_pc=0x0c0587b8u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c0587ba;
P_0c0587ba: /* original fc4c, guest PC 0x0c0587ba */
if(!s->budget--) { s->failed_pc=0x0c0587bau; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0587bc;
P_0c0587bc: /* original 62e3, guest PC 0x0c0587bc */
if(!s->budget--) { s->failed_pc=0x0c0587bcu; return 0; }
r[2]=r[14];
goto P_0c0587be;
P_0c0587be: /* original 72e8, guest PC 0x0c0587be */
if(!s->budget--) { s->failed_pc=0x0c0587beu; return 0; }
r[2]+=0xffffffe8u;
goto P_0c0587c0;
P_0c0587c0: /* original be9e, guest PC 0x0c0587c0 */
if(!s->budget--) { s->failed_pc=0x0c0587c0u; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c0587c4u;
r[5]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0587c4u) { target=s->pc; goto dispatch; }
goto P_0c0587c4;
P_0c0587c2: /* original 6593, guest PC 0x0c0587c2 */
if(!s->budget--) { s->failed_pc=0x0c0587c2u; return 0; }
r[5]=r[9];
goto P_0c0587c4;
P_0c0587c4: /* original 0c83, guest PC 0x0c0587c4 */
if(!s->budget--) { s->failed_pc=0x0c0587c4u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0587c6;
P_0c0587c6: /* original fb9d, guest PC 0x0c0587c6 */
if(!s->budget--) { s->failed_pc=0x0c0587c6u; return 0; }
fr[11]=0x3f800000u;
goto P_0c0587c8;
P_0c0587c8: /* original fb23, guest PC 0x0c0587c8 */
if(!s->budget--) { s->failed_pc=0x0c0587c8u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[2],r[18],'/');
goto P_0c0587ca;
P_0c0587ca: /* original f268, guest PC 0x0c0587ca */
if(!s->budget--) { s->failed_pc=0x0c0587cau; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c0587cc;
P_0c0587cc: /* original 62e3, guest PC 0x0c0587cc */
if(!s->budget--) { s->failed_pc=0x0c0587ccu; return 0; }
r[2]=r[14];
goto P_0c0587ce;
P_0c0587ce: /* original 6125, guest PC 0x0c0587ce */
if(!s->budget--) { s->failed_pc=0x0c0587ceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c0587d0;
P_0c0587d0: /* original f3fd, guest PC 0x0c0587d0 */
if(!s->budget--) { s->failed_pc=0x0c0587d0u; return 0; }
r[18]^=0x100000u;
goto P_0c0587d2;
P_0c0587d2: /* original 6221, guest PC 0x0c0587d2 */
if(!s->budget--) { s->failed_pc=0x0c0587d2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c0587d4;
P_0c0587d4: /* original a03d, guest PC 0x0c0587d4 */
if(!s->budget--) { s->failed_pc=0x0c0587d4u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058852;
P_0c0587d6: /* original f60c, guest PC 0x0c0587d6 */
if(!s->budget--) { s->failed_pc=0x0c0587d6u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c0587d8;
P_0c0587d8: /* original bf40, guest PC 0x0c0587d8 */
if(!s->budget--) { s->failed_pc=0x0c0587d8u; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c0587dcu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0587dcu) { target=s->pc; goto dispatch; }
goto P_0c0587dc;
P_0c0587da: /* original 65e3, guest PC 0x0c0587da */
if(!s->budget--) { s->failed_pc=0x0c0587dau; return 0; }
r[5]=r[14];
goto P_0c0587dc;
P_0c0587dc: /* original 2f06, guest PC 0x0c0587dc */
if(!s->budget--) { s->failed_pc=0x0c0587dcu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0587de;
P_0c0587de: /* original e008, guest PC 0x0c0587de */
if(!s->budget--) { s->failed_pc=0x0c0587deu; return 0; }
r[0]=0x00000008u;
goto P_0c0587e0;
P_0c0587e0: /* original f096, guest PC 0x0c0587e0 */
if(!s->budget--) { s->failed_pc=0x0c0587e0u; return 0; }
vf3_matrix_load(s,ram,0,r[9]+r[0]);
goto P_0c0587e2;
P_0c0587e2: /* original 62e3, guest PC 0x0c0587e2 */
if(!s->budget--) { s->failed_pc=0x0c0587e2u; return 0; }
r[2]=r[14];
goto P_0c0587e4;
P_0c0587e4: /* original 72d0, guest PC 0x0c0587e4 */
if(!s->budget--) { s->failed_pc=0x0c0587e4u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c0587e6;
P_0c0587e6: /* original 6583, guest PC 0x0c0587e6 */
if(!s->budget--) { s->failed_pc=0x0c0587e6u; return 0; }
r[5]=r[8];
goto P_0c0587e8;
P_0c0587e8: /* original f79d, guest PC 0x0c0587e8 */
if(!s->budget--) { s->failed_pc=0x0c0587e8u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0587ea;
P_0c0587ea: /* original be89, guest PC 0x0c0587ea */
if(!s->budget--) { s->failed_pc=0x0c0587eau; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c0587eeu;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0587eeu) { target=s->pc; goto dispatch; }
goto P_0c0587ee;
P_0c0587ec: /* original f703, guest PC 0x0c0587ec */
if(!s->budget--) { s->failed_pc=0x0c0587ecu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
goto P_0c0587ee;
P_0c0587ee: /* original 0c83, guest PC 0x0c0587ee */
if(!s->budget--) { s->failed_pc=0x0c0587eeu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0587f0;
P_0c0587f0: /* original 7c20, guest PC 0x0c0587f0 */
if(!s->budget--) { s->failed_pc=0x0c0587f0u; return 0; }
r[12]+=0x00000020u;
goto P_0c0587f2;
P_0c0587f2: /* original fa9d, guest PC 0x0c0587f2 */
if(!s->budget--) { s->failed_pc=0x0c0587f2u; return 0; }
fr[10]=0x3f800000u;
goto P_0c0587f4;
P_0c0587f4: /* original fa23, guest PC 0x0c0587f4 */
if(!s->budget--) { s->failed_pc=0x0c0587f4u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c0587f6;
P_0c0587f6: /* original f80c, guest PC 0x0c0587f6 */
if(!s->budget--) { s->failed_pc=0x0c0587f6u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c0587f8;
P_0c0587f8: /* original 62e3, guest PC 0x0c0587f8 */
if(!s->budget--) { s->failed_pc=0x0c0587f8u; return 0; }
r[2]=r[14];
goto P_0c0587fa;
P_0c0587fa: /* original fc4c, guest PC 0x0c0587fa */
if(!s->budget--) { s->failed_pc=0x0c0587fau; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0587fc;
P_0c0587fc: /* original be80, guest PC 0x0c0587fc */
if(!s->budget--) { s->failed_pc=0x0c0587fcu; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058800u;
r[5]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058800u) { target=s->pc; goto dispatch; }
goto P_0c058800;
P_0c0587fe: /* original 6563, guest PC 0x0c0587fe */
if(!s->budget--) { s->failed_pc=0x0c0587feu; return 0; }
r[5]=r[6];
goto P_0c058800;
P_0c058800: /* original 0c83, guest PC 0x0c058800 */
if(!s->budget--) { s->failed_pc=0x0c058800u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058802;
P_0c058802: /* original fb9d, guest PC 0x0c058802 */
if(!s->budget--) { s->failed_pc=0x0c058802u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058804;
P_0c058804: /* original 62e3, guest PC 0x0c058804 */
if(!s->budget--) { s->failed_pc=0x0c058804u; return 0; }
r[2]=r[14];
goto P_0c058806;
P_0c058806: /* original fb23, guest PC 0x0c058806 */
if(!s->budget--) { s->failed_pc=0x0c058806u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[2],r[18],'/');
goto P_0c058808;
P_0c058808: /* original f298, guest PC 0x0c058808 */
if(!s->budget--) { s->failed_pc=0x0c058808u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
goto P_0c05880a;
P_0c05880a: /* original 72e8, guest PC 0x0c05880a */
if(!s->budget--) { s->failed_pc=0x0c05880au; return 0; }
r[2]+=0xffffffe8u;
goto P_0c05880c;
P_0c05880c: /* original 6125, guest PC 0x0c05880c */
if(!s->budget--) { s->failed_pc=0x0c05880cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05880e;
P_0c05880e: /* original f3fd, guest PC 0x0c05880e */
if(!s->budget--) { s->failed_pc=0x0c05880eu; return 0; }
r[18]^=0x100000u;
goto P_0c058810;
P_0c058810: /* original 6221, guest PC 0x0c058810 */
if(!s->budget--) { s->failed_pc=0x0c058810u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058812;
P_0c058812: /* original a01e, guest PC 0x0c058812 */
if(!s->budget--) { s->failed_pc=0x0c058812u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058852;
P_0c058814: /* original f60c, guest PC 0x0c058814 */
if(!s->budget--) { s->failed_pc=0x0c058814u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058816;
P_0c058816: /* original bf21, guest PC 0x0c058816 */
if(!s->budget--) { s->failed_pc=0x0c058816u; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c05881au;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05881au) { target=s->pc; goto dispatch; }
goto P_0c05881a;
P_0c058818: /* original 65e3, guest PC 0x0c058818 */
if(!s->budget--) { s->failed_pc=0x0c058818u; return 0; }
r[5]=r[14];
goto P_0c05881a;
P_0c05881a: /* original 2f06, guest PC 0x0c05881a */
if(!s->budget--) { s->failed_pc=0x0c05881au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05881c;
P_0c05881c: /* original e008, guest PC 0x0c05881c */
if(!s->budget--) { s->failed_pc=0x0c05881cu; return 0; }
r[0]=0x00000008u;
goto P_0c05881e;
P_0c05881e: /* original f086, guest PC 0x0c05881e */
if(!s->budget--) { s->failed_pc=0x0c05881eu; return 0; }
vf3_matrix_load(s,ram,0,r[8]+r[0]);
goto P_0c058820;
P_0c058820: /* original 62e3, guest PC 0x0c058820 */
if(!s->budget--) { s->failed_pc=0x0c058820u; return 0; }
r[2]=r[14];
goto P_0c058822;
P_0c058822: /* original 72e8, guest PC 0x0c058822 */
if(!s->budget--) { s->failed_pc=0x0c058822u; return 0; }
r[2]+=0xffffffe8u;
goto P_0c058824;
P_0c058824: /* original 6593, guest PC 0x0c058824 */
if(!s->budget--) { s->failed_pc=0x0c058824u; return 0; }
r[5]=r[9];
goto P_0c058826;
P_0c058826: /* original f79d, guest PC 0x0c058826 */
if(!s->budget--) { s->failed_pc=0x0c058826u; return 0; }
fr[7]=0x3f800000u;
goto P_0c058828;
P_0c058828: /* original be6a, guest PC 0x0c058828 */
if(!s->budget--) { s->failed_pc=0x0c058828u; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c05882cu;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05882cu) { target=s->pc; goto dispatch; }
goto P_0c05882c;
P_0c05882a: /* original f703, guest PC 0x0c05882a */
if(!s->budget--) { s->failed_pc=0x0c05882au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
goto P_0c05882c;
P_0c05882c: /* original 0c83, guest PC 0x0c05882c */
if(!s->budget--) { s->failed_pc=0x0c05882cu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05882e;
P_0c05882e: /* original 7c20, guest PC 0x0c05882e */
if(!s->budget--) { s->failed_pc=0x0c05882eu; return 0; }
r[12]+=0x00000020u;
goto P_0c058830;
P_0c058830: /* original f80c, guest PC 0x0c058830 */
if(!s->budget--) { s->failed_pc=0x0c058830u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c058832;
P_0c058832: /* original fa9d, guest PC 0x0c058832 */
if(!s->budget--) { s->failed_pc=0x0c058832u; return 0; }
fr[10]=0x3f800000u;
goto P_0c058834;
P_0c058834: /* original fa23, guest PC 0x0c058834 */
if(!s->budget--) { s->failed_pc=0x0c058834u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c058836;
P_0c058836: /* original fc4c, guest PC 0x0c058836 */
if(!s->budget--) { s->failed_pc=0x0c058836u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c058838;
P_0c058838: /* original 62e3, guest PC 0x0c058838 */
if(!s->budget--) { s->failed_pc=0x0c058838u; return 0; }
r[2]=r[14];
goto P_0c05883a;
P_0c05883a: /* original be61, guest PC 0x0c05883a */
if(!s->budget--) { s->failed_pc=0x0c05883au; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c05883eu;
r[5]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05883eu) { target=s->pc; goto dispatch; }
goto P_0c05883e;
P_0c05883c: /* original 6563, guest PC 0x0c05883c */
if(!s->budget--) { s->failed_pc=0x0c05883cu; return 0; }
r[5]=r[6];
goto P_0c05883e;
P_0c05883e: /* original 0c83, guest PC 0x0c05883e */
if(!s->budget--) { s->failed_pc=0x0c05883eu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058840;
P_0c058840: /* original fb9d, guest PC 0x0c058840 */
if(!s->budget--) { s->failed_pc=0x0c058840u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058842;
P_0c058842: /* original 62e3, guest PC 0x0c058842 */
if(!s->budget--) { s->failed_pc=0x0c058842u; return 0; }
r[2]=r[14];
goto P_0c058844;
P_0c058844: /* original fb23, guest PC 0x0c058844 */
if(!s->budget--) { s->failed_pc=0x0c058844u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[2],r[18],'/');
goto P_0c058846;
P_0c058846: /* original 72d0, guest PC 0x0c058846 */
if(!s->budget--) { s->failed_pc=0x0c058846u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c058848;
P_0c058848: /* original f288, guest PC 0x0c058848 */
if(!s->budget--) { s->failed_pc=0x0c058848u; return 0; }
vf3_matrix_load(s,ram,2,r[8]);
goto P_0c05884a;
P_0c05884a: /* original 6125, guest PC 0x0c05884a */
if(!s->budget--) { s->failed_pc=0x0c05884au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05884c;
P_0c05884c: /* original f3fd, guest PC 0x0c05884c */
if(!s->budget--) { s->failed_pc=0x0c05884cu; return 0; }
r[18]^=0x100000u;
goto P_0c05884e;
P_0c05884e: /* original 6221, guest PC 0x0c05884e */
if(!s->budget--) { s->failed_pc=0x0c05884eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058850;
P_0c058850: /* original f60c, guest PC 0x0c058850 */
if(!s->budget--) { s->failed_pc=0x0c058850u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058852;
P_0c058852: /* original c607, guest PC 0x0c058852 */
if(!s->budget--) { s->failed_pc=0x0c058852u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+28,4);
goto P_0c058854;
P_0c058854: /* original f8a2, guest PC 0x0c058854 */
if(!s->budget--) { s->failed_pc=0x0c058854u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'*');
goto P_0c058856;
P_0c058856: /* original f9a2, guest PC 0x0c058856 */
if(!s->budget--) { s->failed_pc=0x0c058856u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c058858;
P_0c058858: /* original f272, guest PC 0x0c058858 */
if(!s->budget--) { s->failed_pc=0x0c058858u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c05885a;
P_0c05885a: /* original f372, guest PC 0x0c05885a */
if(!s->budget--) { s->failed_pc=0x0c05885au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c05885c;
P_0c05885c: /* original 405a, guest PC 0x0c05885c */
if(!s->budget--) { s->failed_pc=0x0c05885cu; return 0; }
r[53]=r[0];
goto P_0c05885e;
P_0c05885e: /* original fa71, guest PC 0x0c05885e */
if(!s->budget--) { s->failed_pc=0x0c05885eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'-');
goto P_0c058860;
P_0c058860: /* original f00d, guest PC 0x0c058860 */
if(!s->budget--) { s->failed_pc=0x0c058860u; return 0; }
fr[0]=r[53];
goto P_0c058862;
P_0c058862: /* original f071, guest PC 0x0c058862 */
if(!s->budget--) { s->failed_pc=0x0c058862u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[7],r[18],'-');
goto P_0c058864;
P_0c058864: /* original f6b2, guest PC 0x0c058864 */
if(!s->budget--) { s->failed_pc=0x0c058864u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c058866;
P_0c058866: /* original f1b2, guest PC 0x0c058866 */
if(!s->budget--) { s->failed_pc=0x0c058866u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'*');
goto P_0c058868;
P_0c058868: /* original fb71, guest PC 0x0c058868 */
if(!s->budget--) { s->failed_pc=0x0c058868u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'-');
return vf3_matrix_family(0x0c05886au,s,ram);
P_0c0588f0: /* original beb4, guest PC 0x0c0588f0 */
if(!s->budget--) { s->failed_pc=0x0c0588f0u; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c0588f4u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0588f4u) { target=s->pc; goto dispatch; }
goto P_0c0588f4;
P_0c0588f2: /* original 65e3, guest PC 0x0c0588f2 */
if(!s->budget--) { s->failed_pc=0x0c0588f2u; return 0; }
r[5]=r[14];
goto P_0c0588f4;
P_0c0588f4: /* original 2f06, guest PC 0x0c0588f4 */
if(!s->budget--) { s->failed_pc=0x0c0588f4u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0588f6;
P_0c0588f6: /* original e008, guest PC 0x0c0588f6 */
if(!s->budget--) { s->failed_pc=0x0c0588f6u; return 0; }
r[0]=0x00000008u;
goto P_0c0588f8;
P_0c0588f8: /* original f096, guest PC 0x0c0588f8 */
if(!s->budget--) { s->failed_pc=0x0c0588f8u; return 0; }
vf3_matrix_load(s,ram,0,r[9]+r[0]);
goto P_0c0588fa;
P_0c0588fa: /* original 62e3, guest PC 0x0c0588fa */
if(!s->budget--) { s->failed_pc=0x0c0588fau; return 0; }
r[2]=r[14];
goto P_0c0588fc;
P_0c0588fc: /* original 72d0, guest PC 0x0c0588fc */
if(!s->budget--) { s->failed_pc=0x0c0588fcu; return 0; }
r[2]+=0xffffffd0u;
goto P_0c0588fe;
P_0c0588fe: /* original 6583, guest PC 0x0c0588fe */
if(!s->budget--) { s->failed_pc=0x0c0588feu; return 0; }
r[5]=r[8];
goto P_0c058900;
P_0c058900: /* original fb9d, guest PC 0x0c058900 */
if(!s->budget--) { s->failed_pc=0x0c058900u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058902;
P_0c058902: /* original bdfd, guest PC 0x0c058902 */
if(!s->budget--) { s->failed_pc=0x0c058902u; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058906u;
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058906u) { target=s->pc; goto dispatch; }
goto P_0c058906;
P_0c058904: /* original fb03, guest PC 0x0c058904 */
if(!s->budget--) { s->failed_pc=0x0c058904u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
goto P_0c058906;
P_0c058906: /* original fa9d, guest PC 0x0c058906 */
if(!s->budget--) { s->failed_pc=0x0c058906u; return 0; }
fr[10]=0x3f800000u;
goto P_0c058908;
P_0c058908: /* original f80c, guest PC 0x0c058908 */
if(!s->budget--) { s->failed_pc=0x0c058908u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c05890a;
P_0c05890a: /* original fa23, guest PC 0x0c05890a */
if(!s->budget--) { s->failed_pc=0x0c05890au; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c05890c;
P_0c05890c: /* original 62e3, guest PC 0x0c05890c */
if(!s->budget--) { s->failed_pc=0x0c05890cu; return 0; }
r[2]=r[14];
goto P_0c05890e;
P_0c05890e: /* original 0c83, guest PC 0x0c05890e */
if(!s->budget--) { s->failed_pc=0x0c05890eu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058910;
P_0c058910: /* original 72e8, guest PC 0x0c058910 */
if(!s->budget--) { s->failed_pc=0x0c058910u; return 0; }
r[2]+=0xffffffe8u;
goto P_0c058912;
P_0c058912: /* original 6125, guest PC 0x0c058912 */
if(!s->budget--) { s->failed_pc=0x0c058912u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c058914;
P_0c058914: /* original 6221, guest PC 0x0c058914 */
if(!s->budget--) { s->failed_pc=0x0c058914u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058916;
P_0c058916: /* original f698, guest PC 0x0c058916 */
if(!s->budget--) { s->failed_pc=0x0c058916u; return 0; }
vf3_matrix_load(s,ram,6,r[9]);
goto P_0c058918;
P_0c058918: /* original a015, guest PC 0x0c058918 */
if(!s->budget--) { s->failed_pc=0x0c058918u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c058946;
P_0c05891a: /* original f268, guest PC 0x0c05891a */
if(!s->budget--) { s->failed_pc=0x0c05891au; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c05891c;
P_0c05891c: /* original be9e, guest PC 0x0c05891c */
if(!s->budget--) { s->failed_pc=0x0c05891cu; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c058920u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058920u) { target=s->pc; goto dispatch; }
goto P_0c058920;
P_0c05891e: /* original 65e3, guest PC 0x0c05891e */
if(!s->budget--) { s->failed_pc=0x0c05891eu; return 0; }
r[5]=r[14];
goto P_0c058920;
P_0c058920: /* original 2f06, guest PC 0x0c058920 */
if(!s->budget--) { s->failed_pc=0x0c058920u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c058922;
P_0c058922: /* original e008, guest PC 0x0c058922 */
if(!s->budget--) { s->failed_pc=0x0c058922u; return 0; }
r[0]=0x00000008u;
goto P_0c058924;
P_0c058924: /* original f086, guest PC 0x0c058924 */
if(!s->budget--) { s->failed_pc=0x0c058924u; return 0; }
vf3_matrix_load(s,ram,0,r[8]+r[0]);
goto P_0c058926;
P_0c058926: /* original 62e3, guest PC 0x0c058926 */
if(!s->budget--) { s->failed_pc=0x0c058926u; return 0; }
r[2]=r[14];
goto P_0c058928;
P_0c058928: /* original 72e8, guest PC 0x0c058928 */
if(!s->budget--) { s->failed_pc=0x0c058928u; return 0; }
r[2]+=0xffffffe8u;
goto P_0c05892a;
P_0c05892a: /* original 6593, guest PC 0x0c05892a */
if(!s->budget--) { s->failed_pc=0x0c05892au; return 0; }
r[5]=r[9];
goto P_0c05892c;
P_0c05892c: /* original fb9d, guest PC 0x0c05892c */
if(!s->budget--) { s->failed_pc=0x0c05892cu; return 0; }
fr[11]=0x3f800000u;
goto P_0c05892e;
P_0c05892e: /* original bde7, guest PC 0x0c05892e */
if(!s->budget--) { s->failed_pc=0x0c05892eu; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058932u;
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058932u) { target=s->pc; goto dispatch; }
goto P_0c058932;
P_0c058930: /* original fb03, guest PC 0x0c058930 */
if(!s->budget--) { s->failed_pc=0x0c058930u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
goto P_0c058932;
P_0c058932: /* original fa9d, guest PC 0x0c058932 */
if(!s->budget--) { s->failed_pc=0x0c058932u; return 0; }
fr[10]=0x3f800000u;
goto P_0c058934;
P_0c058934: /* original f80c, guest PC 0x0c058934 */
if(!s->budget--) { s->failed_pc=0x0c058934u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c058936;
P_0c058936: /* original fa23, guest PC 0x0c058936 */
if(!s->budget--) { s->failed_pc=0x0c058936u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c058938;
P_0c058938: /* original 62e3, guest PC 0x0c058938 */
if(!s->budget--) { s->failed_pc=0x0c058938u; return 0; }
r[2]=r[14];
goto P_0c05893a;
P_0c05893a: /* original 0c83, guest PC 0x0c05893a */
if(!s->budget--) { s->failed_pc=0x0c05893au; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05893c;
P_0c05893c: /* original 72d0, guest PC 0x0c05893c */
if(!s->budget--) { s->failed_pc=0x0c05893cu; return 0; }
r[2]+=0xffffffd0u;
goto P_0c05893e;
P_0c05893e: /* original 6125, guest PC 0x0c05893e */
if(!s->budget--) { s->failed_pc=0x0c05893eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c058940;
P_0c058940: /* original 6221, guest PC 0x0c058940 */
if(!s->budget--) { s->failed_pc=0x0c058940u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058942;
P_0c058942: /* original f688, guest PC 0x0c058942 */
if(!s->budget--) { s->failed_pc=0x0c058942u; return 0; }
vf3_matrix_load(s,ram,6,r[8]);
goto P_0c058944;
P_0c058944: /* original f268, guest PC 0x0c058944 */
if(!s->budget--) { s->failed_pc=0x0c058944u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c058946;
P_0c058946: /* original f3fd, guest PC 0x0c058946 */
if(!s->budget--) { s->failed_pc=0x0c058946u; return 0; }
r[18]^=0x100000u;
goto P_0c058948;
P_0c058948: /* original 415a, guest PC 0x0c058948 */
if(!s->budget--) { s->failed_pc=0x0c058948u; return 0; }
r[53]=r[1];
goto P_0c05894a;
P_0c05894a: /* original e008, guest PC 0x0c05894a */
if(!s->budget--) { s->failed_pc=0x0c05894au; return 0; }
r[0]=0x00000008u;
goto P_0c05894c;
P_0c05894c: /* original fc2d, guest PC 0x0c05894c */
if(!s->budget--) { s->failed_pc=0x0c05894cu; return 0; }
fr[12]=vf3_fpu_float(r[53],r[18]);
goto P_0c05894e;
P_0c05894e: /* original 425a, guest PC 0x0c05894e */
if(!s->budget--) { s->failed_pc=0x0c05894eu; return 0; }
r[53]=r[2];
goto P_0c058950;
P_0c058950: /* original fd2d, guest PC 0x0c058950 */
if(!s->budget--) { s->failed_pc=0x0c058950u; return 0; }
fr[13]=vf3_fpu_float(r[53],r[18]);
goto P_0c058952;
P_0c058952: /* original fe66, guest PC 0x0c058952 */
if(!s->budget--) { s->failed_pc=0x0c058952u; return 0; }
vf3_matrix_load(s,ram,14,r[6]+r[0]);
goto P_0c058954;
P_0c058954: /* original 62e3, guest PC 0x0c058954 */
if(!s->budget--) { s->failed_pc=0x0c058954u; return 0; }
r[2]=r[14];
goto P_0c058956;
P_0c058956: /* original c607, guest PC 0x0c058956 */
if(!s->budget--) { s->failed_pc=0x0c058956u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+28,4);
goto P_0c058958;
P_0c058958: /* original f6b2, guest PC 0x0c058958 */
if(!s->budget--) { s->failed_pc=0x0c058958u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c05895a;
P_0c05895a: /* original f7b2, guest PC 0x0c05895a */
if(!s->budget--) { s->failed_pc=0x0c05895au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c05895c;
P_0c05895c: /* original fcf2, guest PC 0x0c05895c */
if(!s->budget--) { s->failed_pc=0x0c05895cu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'*');
goto P_0c05895e;
P_0c05895e: /* original 7c2c, guest PC 0x0c05895e */
if(!s->budget--) { s->failed_pc=0x0c05895eu; return 0; }
r[12]+=0x0000002cu;
goto P_0c058960;
P_0c058960: /* original fdf2, guest PC 0x0c058960 */
if(!s->budget--) { s->failed_pc=0x0c058960u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c058962;
P_0c058962: /* original 405a, guest PC 0x0c058962 */
if(!s->budget--) { s->failed_pc=0x0c058962u; return 0; }
r[53]=r[0];
goto P_0c058964;
P_0c058964: /* original fba1, guest PC 0x0c058964 */
if(!s->budget--) { s->failed_pc=0x0c058964u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[10],r[18],'-');
goto P_0c058966;
P_0c058966: /* original 2ca2, guest PC 0x0c058966 */
if(!s->budget--) { s->failed_pc=0x0c058966u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c058968;
P_0c058968: /* original f00d, guest PC 0x0c058968 */
if(!s->budget--) { s->failed_pc=0x0c058968u; return 0; }
fr[0]=r[53];
goto P_0c05896a;
P_0c05896a: /* original f0a1, guest PC 0x0c05896a */
if(!s->budget--) { s->failed_pc=0x0c05896au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'-');
goto P_0c05896c;
P_0c05896c: /* original 6125, guest PC 0x0c05896c */
if(!s->budget--) { s->failed_pc=0x0c05896cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05896e;
P_0c05896e: /* original 6221, guest PC 0x0c05896e */
if(!s->budget--) { s->failed_pc=0x0c05896eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058970;
P_0c058970: /* original f9a2, guest PC 0x0c058970 */
if(!s->budget--) { s->failed_pc=0x0c058970u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c058972;
P_0c058972: /* original f01d, guest PC 0x0c058972 */
if(!s->budget--) { s->failed_pc=0x0c058972u; return 0; }
r[53]=fr[0];
goto P_0c058974;
P_0c058974: /* original a02c, guest PC 0x0c058974 */
if(!s->budget--) { s->failed_pc=0x0c058974u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'/');
return vf3_matrix_family(0x0c0589d0u,s,ram);
P_0c058976: /* original f0b3, guest PC 0x0c058976 */
if(!s->budget--) { s->failed_pc=0x0c058976u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'/');
return vf3_matrix_family(0x0c058978u,s,ram);
P_0c058a5c: /* original 4f22, guest PC 0x0c058a5c */
if(!s->budget--) { s->failed_pc=0x0c058a5cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058a5e;
P_0c058a5e: /* original bdfd, guest PC 0x0c058a5e */
if(!s->budget--) { s->failed_pc=0x0c058a5eu; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c058a62u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058a62u) { target=s->pc; goto dispatch; }
goto P_0c058a62;
P_0c058a60: /* original 65e3, guest PC 0x0c058a60 */
if(!s->budget--) { s->failed_pc=0x0c058a60u; return 0; }
r[5]=r[14];
goto P_0c058a62;
P_0c058a62: /* original 2f06, guest PC 0x0c058a62 */
if(!s->budget--) { s->failed_pc=0x0c058a62u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c058a64;
P_0c058a64: /* original e008, guest PC 0x0c058a64 */
if(!s->budget--) { s->failed_pc=0x0c058a64u; return 0; }
r[0]=0x00000008u;
goto P_0c058a66;
P_0c058a66: /* original f888, guest PC 0x0c058a66 */
if(!s->budget--) { s->failed_pc=0x0c058a66u; return 0; }
vf3_matrix_load(s,ram,8,r[8]);
goto P_0c058a68;
P_0c058a68: /* original 62e3, guest PC 0x0c058a68 */
if(!s->budget--) { s->failed_pc=0x0c058a68u; return 0; }
r[2]=r[14];
goto P_0c058a6a;
P_0c058a6a: /* original f086, guest PC 0x0c058a6a */
if(!s->budget--) { s->failed_pc=0x0c058a6au; return 0; }
vf3_matrix_load(s,ram,0,r[8]+r[0]);
goto P_0c058a6c;
P_0c058a6c: /* original 72d0, guest PC 0x0c058a6c */
if(!s->budget--) { s->failed_pc=0x0c058a6cu; return 0; }
r[2]+=0xffffffd0u;
goto P_0c058a6e;
P_0c058a6e: /* original fa9d, guest PC 0x0c058a6e */
if(!s->budget--) { s->failed_pc=0x0c058a6eu; return 0; }
fr[10]=0x3f800000u;
goto P_0c058a70;
P_0c058a70: /* original 6125, guest PC 0x0c058a70 */
if(!s->budget--) { s->failed_pc=0x0c058a70u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c058a72;
P_0c058a72: /* original fa03, guest PC 0x0c058a72 */
if(!s->budget--) { s->failed_pc=0x0c058a72u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[0],r[18],'/');
goto P_0c058a74;
P_0c058a74: /* original 6221, guest PC 0x0c058a74 */
if(!s->budget--) { s->failed_pc=0x0c058a74u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058a76;
P_0c058a76: /* original f266, guest PC 0x0c058a76 */
if(!s->budget--) { s->failed_pc=0x0c058a76u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c058a78;
P_0c058a78: /* original f668, guest PC 0x0c058a78 */
if(!s->budget--) { s->failed_pc=0x0c058a78u; return 0; }
vf3_matrix_load(s,ram,6,r[6]);
goto P_0c058a7a;
P_0c058a7a: /* original 415a, guest PC 0x0c058a7a */
if(!s->budget--) { s->failed_pc=0x0c058a7au; return 0; }
r[53]=r[1];
goto P_0c058a7c;
P_0c058a7c: /* original fc2d, guest PC 0x0c058a7c */
if(!s->budget--) { s->failed_pc=0x0c058a7cu; return 0; }
fr[12]=vf3_fpu_float(r[53],r[18]);
goto P_0c058a7e;
P_0c058a7e: /* original 0c83, guest PC 0x0c058a7e */
if(!s->budget--) { s->failed_pc=0x0c058a7eu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058a80;
P_0c058a80: /* original f08d, guest PC 0x0c058a80 */
if(!s->budget--) { s->failed_pc=0x0c058a80u; return 0; }
fr[0]=0;
goto P_0c058a82;
P_0c058a82: /* original f025, guest PC 0x0c058a82 */
if(!s->budget--) { s->failed_pc=0x0c058a82u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[2]))!=0);
goto P_0c058a84;
P_0c058a84: /* original 425a, guest PC 0x0c058a84 */
if(!s->budget--) { s->failed_pc=0x0c058a84u; return 0; }
r[53]=r[2];
goto P_0c058a86;
P_0c058a86: /* original f222, guest PC 0x0c058a86 */
if(!s->budget--) { s->failed_pc=0x0c058a86u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[2],r[18],'*');
goto P_0c058a88;
P_0c058a88: /* original 62e3, guest PC 0x0c058a88 */
if(!s->budget--) { s->failed_pc=0x0c058a88u; return 0; }
r[2]=r[14];
goto P_0c058a8a;
P_0c058a8a: /* original fd2d, guest PC 0x0c058a8a */
if(!s->budget--) { s->failed_pc=0x0c058a8au; return 0; }
fr[13]=vf3_fpu_float(r[53],r[18]);
goto P_0c058a8c;
P_0c058a8c: /* original 6125, guest PC 0x0c058a8c */
if(!s->budget--) { s->failed_pc=0x0c058a8cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c058a8e;
P_0c058a8e: /* original f27d, guest PC 0x0c058a8e */
if(!s->budget--) { s->failed_pc=0x0c058a8eu; return 0; }
if(!vf3_fpu_fsrra(fr[2],r[18],&fr[2])) goto unsupported;
goto P_0c058a90;
P_0c058a90: /* original 6221, guest PC 0x0c058a90 */
if(!s->budget--) { s->failed_pc=0x0c058a90u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058a92;
P_0c058a92: /* original fcf2, guest PC 0x0c058a92 */
if(!s->budget--) { s->failed_pc=0x0c058a92u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'*');
goto P_0c058a94;
P_0c058a94: /* original f498, guest PC 0x0c058a94 */
if(!s->budget--) { s->failed_pc=0x0c058a94u; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c058a96;
P_0c058a96: /* original fdf2, guest PC 0x0c058a96 */
if(!s->budget--) { s->failed_pc=0x0c058a96u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c058a98;
P_0c058a98: /* original f3fd, guest PC 0x0c058a98 */
if(!s->budget--) { s->failed_pc=0x0c058a98u; return 0; }
r[18]^=0x100000u;
goto P_0c058a9a;
P_0c058a9a: /* original 415a, guest PC 0x0c058a9a */
if(!s->budget--) { s->failed_pc=0x0c058a9au; return 0; }
r[53]=r[1];
goto P_0c058a9c;
P_0c058a9c: /* original f396, guest PC 0x0c058a9c */
if(!s->budget--) { s->failed_pc=0x0c058a9cu; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c058a9e;
P_0c058a9e: /* original c607, guest PC 0x0c058a9e */
if(!s->budget--) { s->failed_pc=0x0c058a9eu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+28,4);
goto P_0c058aa0;
P_0c058aa0: /* original fb2d, guest PC 0x0c058aa0 */
if(!s->budget--) { s->failed_pc=0x0c058aa0u; return 0; }
fr[11]=vf3_fpu_float(r[53],r[18]);
goto P_0c058aa2;
P_0c058aa2: /* original 425a, guest PC 0x0c058aa2 */
if(!s->budget--) { s->failed_pc=0x0c058aa2u; return 0; }
r[53]=r[2];
goto P_0c058aa4;
P_0c058aa4: /* original fe2d, guest PC 0x0c058aa4 */
if(!s->budget--) { s->failed_pc=0x0c058aa4u; return 0; }
fr[14]=vf3_fpu_float(r[53],r[18]);
goto P_0c058aa6;
P_0c058aa6: /* original 405a, guest PC 0x0c058aa6 */
if(!s->budget--) { s->failed_pc=0x0c058aa6u; return 0; }
r[53]=r[0];
goto P_0c058aa8;
P_0c058aa8: /* original 8b00, guest PC 0x0c058aa8 */
if(!s->budget--) { s->failed_pc=0x0c058aa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c058aac; }
goto P_0c058aaa;
P_0c058aaa: /* original f24d, guest PC 0x0c058aaa */
if(!s->budget--) { s->failed_pc=0x0c058aaau; return 0; }
fr[2]^=0x80000000u;
goto P_0c058aac;
P_0c058aac: /* original f00d, guest PC 0x0c058aac */
if(!s->budget--) { s->failed_pc=0x0c058aacu; return 0; }
fr[0]=r[53];
goto P_0c058aae;
P_0c058aae: /* original f021, guest PC 0x0c058aae */
if(!s->budget--) { s->failed_pc=0x0c058aaeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'-');
goto P_0c058ab0;
P_0c058ab0: /* original 62e3, guest PC 0x0c058ab0 */
if(!s->budget--) { s->failed_pc=0x0c058ab0u; return 0; }
r[2]=r[14];
goto P_0c058ab2;
P_0c058ab2: /* original f8a2, guest PC 0x0c058ab2 */
if(!s->budget--) { s->failed_pc=0x0c058ab2u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'*');
goto P_0c058ab4;
P_0c058ab4: /* original 72e8, guest PC 0x0c058ab4 */
if(!s->budget--) { s->failed_pc=0x0c058ab4u; return 0; }
r[2]+=0xffffffe8u;
goto P_0c058ab6;
P_0c058ab6: /* original f9a2, guest PC 0x0c058ab6 */
if(!s->budget--) { s->failed_pc=0x0c058ab6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c058ab8;
P_0c058ab8: /* original 6125, guest PC 0x0c058ab8 */
if(!s->budget--) { s->failed_pc=0x0c058ab8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c058aba;
P_0c058aba: /* original fa21, guest PC 0x0c058aba */
if(!s->budget--) { s->failed_pc=0x0c058abau; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'-');
goto P_0c058abc;
P_0c058abc: /* original f01d, guest PC 0x0c058abc */
if(!s->budget--) { s->failed_pc=0x0c058abcu; return 0; }
r[53]=fr[0];
goto P_0c058abe;
P_0c058abe: /* original fbf2, guest PC 0x0c058abe */
if(!s->budget--) { s->failed_pc=0x0c058abeu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[15],r[18],'*');
goto P_0c058ac0;
P_0c058ac0: /* original 6221, guest PC 0x0c058ac0 */
if(!s->budget--) { s->failed_pc=0x0c058ac0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058ac2;
P_0c058ac2: /* original fef2, guest PC 0x0c058ac2 */
if(!s->budget--) { s->failed_pc=0x0c058ac2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c058ac4;
P_0c058ac4: /* original f0a3, guest PC 0x0c058ac4 */
if(!s->budget--) { s->failed_pc=0x0c058ac4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'/');
goto P_0c058ac6;
P_0c058ac6: /* original 7c3c, guest PC 0x0c058ac6 */
if(!s->budget--) { s->failed_pc=0x0c058ac6u; return 0; }
r[12]+=0x0000003cu;
goto P_0c058ac8;
P_0c058ac8: /* original f722, guest PC 0x0c058ac8 */
if(!s->budget--) { s->failed_pc=0x0c058ac8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c058aca;
P_0c058aca: /* original 65f6, guest PC 0x0c058aca */
if(!s->budget--) { s->failed_pc=0x0c058acau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c058acc;
P_0c058acc: /* original f622, guest PC 0x0c058acc */
if(!s->budget--) { s->failed_pc=0x0c058accu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'*');
goto P_0c058ace;
P_0c058ace: /* original c618, guest PC 0x0c058ace */
if(!s->budget--) { s->failed_pc=0x0c058aceu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+96,4);
goto P_0c058ad0;
P_0c058ad0: /* original f18d, guest PC 0x0c058ad0 */
if(!s->budget--) { s->failed_pc=0x0c058ad0u; return 0; }
fr[1]=0;
goto P_0c058ad2;
P_0c058ad2: /* original f135, guest PC 0x0c058ad2 */
if(!s->budget--) { s->failed_pc=0x0c058ad2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[3]))!=0);
goto P_0c058ad4;
P_0c058ad4: /* original f332, guest PC 0x0c058ad4 */
if(!s->budget--) { s->failed_pc=0x0c058ad4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'*');
goto P_0c058ad6;
P_0c058ad6: /* original fde1, guest PC 0x0c058ad6 */
if(!s->budget--) { s->failed_pc=0x0c058ad6u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c058ad8;
P_0c058ad8: /* original 2c52, guest PC 0x0c058ad8 */
if(!s->budget--) { s->failed_pc=0x0c058ad8u; return 0; }
write(ram,r[12],r[5],4);
goto P_0c058ada;
P_0c058ada: /* original fcb1, guest PC 0x0c058ada */
if(!s->budget--) { s->failed_pc=0x0c058adau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[11],r[18],'-');
goto P_0c058adc;
P_0c058adc: /* original f971, guest PC 0x0c058adc */
if(!s->budget--) { s->failed_pc=0x0c058adcu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[7],r[18],'-');
goto P_0c058ade;
P_0c058ade: /* original f861, guest PC 0x0c058ade */
if(!s->budget--) { s->failed_pc=0x0c058adeu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
goto P_0c058ae0;
P_0c058ae0: /* original 2c06, guest PC 0x0c058ae0 */
if(!s->budget--) { s->failed_pc=0x0c058ae0u; return 0; }
tmp=r[0]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c058ae2;
P_0c058ae2: /* original f37d, guest PC 0x0c058ae2 */
if(!s->budget--) { s->failed_pc=0x0c058ae2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c058ae4;
P_0c058ae4: /* original f17c, guest PC 0x0c058ae4 */
if(!s->budget--) { s->failed_pc=0x0c058ae4u; return 0; }
vf3_matrix_move(s,1,7);
goto P_0c058ae6;
P_0c058ae6: /* original f19e, guest PC 0x0c058ae6 */
if(!s->budget--) { s->failed_pc=0x0c058ae6u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[9],fr[1],r[18]);
goto P_0c058ae8;
P_0c058ae8: /* original f96c, guest PC 0x0c058ae8 */
if(!s->budget--) { s->failed_pc=0x0c058ae8u; return 0; }
vf3_matrix_move(s,9,6);
goto P_0c058aea;
P_0c058aea: /* original f98e, guest PC 0x0c058aea */
if(!s->budget--) { s->failed_pc=0x0c058aeau; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[8],fr[9],r[18]);
goto P_0c058aec;
P_0c058aec: /* original f8ec, guest PC 0x0c058aec */
if(!s->budget--) { s->failed_pc=0x0c058aecu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c058aee;
P_0c058aee: /* original f8de, guest PC 0x0c058aee */
if(!s->budget--) { s->failed_pc=0x0c058aeeu; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[13],fr[8],r[18]);
goto P_0c058af0;
P_0c058af0: /* original fdbc, guest PC 0x0c058af0 */
if(!s->budget--) { s->failed_pc=0x0c058af0u; return 0; }
vf3_matrix_move(s,13,11);
goto P_0c058af2;
P_0c058af2: /* original fdce, guest PC 0x0c058af2 */
if(!s->budget--) { s->failed_pc=0x0c058af2u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[12],fr[13],r[18]);
goto P_0c058af4;
P_0c058af4: /* original f00d, guest PC 0x0c058af4 */
if(!s->budget--) { s->failed_pc=0x0c058af4u; return 0; }
fr[0]=r[53];
goto P_0c058af6;
P_0c058af6: /* original 4a5a, guest PC 0x0c058af6 */
if(!s->budget--) { s->failed_pc=0x0c058af6u; return 0; }
r[53]=r[10];
goto P_0c058af8;
P_0c058af8: /* original fc0d, guest PC 0x0c058af8 */
if(!s->budget--) { s->failed_pc=0x0c058af8u; return 0; }
fr[12]=r[53];
goto P_0c058afa;
P_0c058afa: /* original f1c2, guest PC 0x0c058afa */
if(!s->budget--) { s->failed_pc=0x0c058afau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[12],r[18],'*');
goto P_0c058afc;
P_0c058afc: /* original fc8b, guest PC 0x0c058afc */
if(!s->budget--) { s->failed_pc=0x0c058afcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c058afe;
P_0c058afe: /* original f9c2, guest PC 0x0c058afe */
if(!s->budget--) { s->failed_pc=0x0c058afeu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'*');
goto P_0c058b00;
P_0c058b00: /* original fcdb, guest PC 0x0c058b00 */
if(!s->budget--) { s->failed_pc=0x0c058b00u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c058b02;
P_0c058b02: /* original 8b00, guest PC 0x0c058b02 */
if(!s->budget--) { s->failed_pc=0x0c058b02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c058b06; }
goto P_0c058b04;
P_0c058b04: /* original f34d, guest PC 0x0c058b04 */
if(!s->budget--) { s->failed_pc=0x0c058b04u; return 0; }
fr[3]^=0x80000000u;
goto P_0c058b06;
P_0c058b06: /* original f532, guest PC 0x0c058b06 */
if(!s->budget--) { s->failed_pc=0x0c058b06u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c058b08;
P_0c058b08: /* original 425a, guest PC 0x0c058b08 */
if(!s->budget--) { s->failed_pc=0x0c058b08u; return 0; }
r[53]=r[2];
goto P_0c058b0a;
P_0c058b0a: /* original f432, guest PC 0x0c058b0a */
if(!s->budget--) { s->failed_pc=0x0c058b0au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c058b0c;
P_0c058b0c: /* original 2ca6, guest PC 0x0c058b0c */
if(!s->budget--) { s->failed_pc=0x0c058b0cu; return 0; }
tmp=r[10]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c058b0e;
P_0c058b0e: /* original f321, guest PC 0x0c058b0e */
if(!s->budget--) { s->failed_pc=0x0c058b0eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'-');
goto P_0c058b10;
P_0c058b10: /* original fc1b, guest PC 0x0c058b10 */
if(!s->budget--) { s->failed_pc=0x0c058b10u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[12]);
goto P_0c058b12;
P_0c058b12: /* original f82d, guest PC 0x0c058b12 */
if(!s->budget--) { s->failed_pc=0x0c058b12u; return 0; }
fr[8]=vf3_fpu_float(r[53],r[18]);
goto P_0c058b14;
P_0c058b14: /* original 415a, guest PC 0x0c058b14 */
if(!s->budget--) { s->failed_pc=0x0c058b14u; return 0; }
r[53]=r[1];
goto P_0c058b16;
P_0c058b16: /* original f12d, guest PC 0x0c058b16 */
if(!s->budget--) { s->failed_pc=0x0c058b16u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c058b18;
P_0c058b18: /* original fc9b, guest PC 0x0c058b18 */
if(!s->budget--) { s->failed_pc=0x0c058b18u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c058b1a;
P_0c058b1a: /* original f033, guest PC 0x0c058b1a */
if(!s->budget--) { s->failed_pc=0x0c058b1au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'/');
goto P_0c058b1c;
P_0c058b1c: /* original 2cc6, guest PC 0x0c058b1c */
if(!s->budget--) { s->failed_pc=0x0c058b1cu; return 0; }
tmp=r[12]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c058b1e;
P_0c058b1e: /* original f8f2, guest PC 0x0c058b1e */
if(!s->budget--) { s->failed_pc=0x0c058b1eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c058b20;
P_0c058b20: /* original 0c83, guest PC 0x0c058b20 */
if(!s->budget--) { s->failed_pc=0x0c058b20u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058b22;
P_0c058b22: /* original f1f2, guest PC 0x0c058b22 */
if(!s->budget--) { s->failed_pc=0x0c058b22u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'*');
goto P_0c058b24;
P_0c058b24: /* original f571, guest PC 0x0c058b24 */
if(!s->budget--) { s->failed_pc=0x0c058b24u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'-');
goto P_0c058b26;
P_0c058b26: /* original 7c2c, guest PC 0x0c058b26 */
if(!s->budget--) { s->failed_pc=0x0c058b26u; return 0; }
r[12]+=0x0000002cu;
goto P_0c058b28;
P_0c058b28: /* original f461, guest PC 0x0c058b28 */
if(!s->budget--) { s->failed_pc=0x0c058b28u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c058b2a;
P_0c058b2a: /* original 4f26, guest PC 0x0c058b2a */
if(!s->budget--) { s->failed_pc=0x0c058b2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c058b2c;
P_0c058b2c: /* original f8e1, guest PC 0x0c058b2c */
if(!s->budget--) { s->failed_pc=0x0c058b2cu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[14],r[18],'-');
goto P_0c058b2e;
P_0c058b2e: /* original 1c03, guest PC 0x0c058b2e */
if(!s->budget--) { s->failed_pc=0x0c058b2eu; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c058b30;
P_0c058b30: /* original f1b1, guest PC 0x0c058b30 */
if(!s->budget--) { s->failed_pc=0x0c058b30u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'-');
goto P_0c058b32;
P_0c058b32: /* original 2ca2, guest PC 0x0c058b32 */
if(!s->budget--) { s->failed_pc=0x0c058b32u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c058b34;
P_0c058b34: /* original f75e, guest PC 0x0c058b34 */
if(!s->budget--) { s->failed_pc=0x0c058b34u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[5],fr[7],r[18]);
goto P_0c058b36;
P_0c058b36: /* original 1c54, guest PC 0x0c058b36 */
if(!s->budget--) { s->failed_pc=0x0c058b36u; return 0; }
write(ram,r[12]+16,r[5],4);
goto P_0c058b38;
P_0c058b38: /* original f64e, guest PC 0x0c058b38 */
if(!s->budget--) { s->failed_pc=0x0c058b38u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c058b3a;
P_0c058b3a: /* original fe8e, guest PC 0x0c058b3a */
if(!s->budget--) { s->failed_pc=0x0c058b3au; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[8],fr[14],r[18]);
goto P_0c058b3c;
P_0c058b3c: /* original 7c08, guest PC 0x0c058b3c */
if(!s->budget--) { s->failed_pc=0x0c058b3cu; return 0; }
r[12]+=0x00000008u;
goto P_0c058b3e;
P_0c058b3e: /* original fb1e, guest PC 0x0c058b3e */
if(!s->budget--) { s->failed_pc=0x0c058b3eu; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[1],fr[11],r[18]);
goto P_0c058b40;
P_0c058b40: /* original f7c2, guest PC 0x0c058b40 */
if(!s->budget--) { s->failed_pc=0x0c058b40u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[12],r[18],'*');
goto P_0c058b42;
P_0c058b42: /* original e0fc, guest PC 0x0c058b42 */
if(!s->budget--) { s->failed_pc=0x0c058b42u; return 0; }
r[0]=0xfffffffcu;
goto P_0c058b44;
P_0c058b44: /* original f6c2, guest PC 0x0c058b44 */
if(!s->budget--) { s->failed_pc=0x0c058b44u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[12],r[18],'*');
goto P_0c058b46;
P_0c058b46: /* original fcea, guest PC 0x0c058b46 */
if(!s->budget--) { s->failed_pc=0x0c058b46u; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c058b48;
P_0c058b48: /* original fcb7, guest PC 0x0c058b48 */
if(!s->budget--) { s->failed_pc=0x0c058b48u; return 0; }
vf3_matrix_store(s,ram,11,r[12]+r[0]);
goto P_0c058b4a;
P_0c058b4a: /* original 7cf4, guest PC 0x0c058b4a */
if(!s->budget--) { s->failed_pc=0x0c058b4au; return 0; }
r[12]+=0xfffffff4u;
goto P_0c058b4c;
P_0c058b4c: /* original fc7a, guest PC 0x0c058b4c */
if(!s->budget--) { s->failed_pc=0x0c058b4cu; return 0; }
vf3_matrix_store(s,ram,7,r[12]);
goto P_0c058b4e;
P_0c058b4e: /* original fc6b, guest PC 0x0c058b4e */
if(!s->budget--) { s->failed_pc=0x0c058b4eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c058b50;
P_0c058b50: /* original f3fd, guest PC 0x0c058b50 */
if(!s->budget--) { s->failed_pc=0x0c058b50u; return 0; }
r[18]^=0x100000u;
goto P_0c058b52;
P_0c058b52: /* original 7cfc, guest PC 0x0c058b52 */
if(!s->budget--) { s->failed_pc=0x0c058b52u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c058b54;
P_0c058b54: /* original f498, guest PC 0x0c058b54 */
if(!s->budget--) { s->failed_pc=0x0c058b54u; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c058b56;
P_0c058b56: /* original 000b, guest PC 0x0c058b56 */
if(!s->budget--) { s->failed_pc=0x0c058b56u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,8,r[6]);
s->pc=target; return ram->oob==0;
P_0c058b58: /* original f868, guest PC 0x0c058b58 */
if(!s->budget--) { s->failed_pc=0x0c058b58u; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
return vf3_matrix_family(0x0c058b5au,s,ram);
P_0c059aea: /* original 4f22, guest PC 0x0c059aea */
if(!s->budget--) { s->failed_pc=0x0c059aeau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059aec;
P_0c059aec: /* original 7ff8, guest PC 0x0c059aec */
if(!s->budget--) { s->failed_pc=0x0c059aecu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059aee;
P_0c059aee: /* original 6322, guest PC 0x0c059aee */
if(!s->budget--) { s->failed_pc=0x0c059aeeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059af0;
P_0c059af0: /* original 2338, guest PC 0x0c059af0 */
if(!s->budget--) { s->failed_pc=0x0c059af0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059af2;
P_0c059af2: /* original 8f74, guest PC 0x0c059af2 */
if(!s->budget--) { s->failed_pc=0x0c059af2u; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c059bde; }
goto P_0c059af6;
P_0c059af4: /* original ed01, guest PC 0x0c059af4 */
if(!s->budget--) { s->failed_pc=0x0c059af4u; return 0; }
r[13]=0x00000001u;
goto P_0c059af6;
P_0c059af6: /* original d110, guest PC 0x0c059af6 */
if(!s->budget--) { s->failed_pc=0x0c059af6u; return 0; }
r[1]=read(ram,0x0c059b38u,4);
goto P_0c059af8;
P_0c059af8: /* original 6312, guest PC 0x0c059af8 */
if(!s->budget--) { s->failed_pc=0x0c059af8u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059afa;
P_0c059afa: /* original 2338, guest PC 0x0c059afa */
if(!s->budget--) { s->failed_pc=0x0c059afau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059afc;
P_0c059afc: /* original 8b20, guest PC 0x0c059afc */
if(!s->budget--) { s->failed_pc=0x0c059afcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059b40; }
goto P_0c059afe;
P_0c059afe: /* original d004, guest PC 0x0c059afe */
if(!s->budget--) { s->failed_pc=0x0c059afeu; return 0; }
r[0]=read(ram,0x0c059b10u,4);
goto P_0c059b00;
P_0c059b00: /* original 6302, guest PC 0x0c059b00 */
if(!s->budget--) { s->failed_pc=0x0c059b00u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059b02;
P_0c059b02: /* original 70f0, guest PC 0x0c059b02 */
if(!s->budget--) { s->failed_pc=0x0c059b02u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c059b04;
P_0c059b04: /* original 4308, guest PC 0x0c059b04 */
if(!s->budget--) { s->failed_pc=0x0c059b04u; return 0; }
r[3]<<=2;
goto P_0c059b06;
P_0c059b06: /* original 03d6, guest PC 0x0c059b06 */
if(!s->budget--) { s->failed_pc=0x0c059b06u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c059b08;
P_0c059b08: /* original d30c, guest PC 0x0c059b08 */
if(!s->budget--) { s->failed_pc=0x0c059b08u; return 0; }
r[3]=read(ram,0x0c059b3cu,4);
goto P_0c059b0a;
P_0c059b0a: /* original a068, guest PC 0x0c059b0a */
if(!s->budget--) { s->failed_pc=0x0c059b0au; return 0; }
write(ram,r[3],r[13],4);
goto P_0c059bde;
P_0c059b0c: /* original 23d2, guest PC 0x0c059b0c */
if(!s->budget--) { s->failed_pc=0x0c059b0cu; return 0; }
write(ram,r[3],r[13],4);
return vf3_matrix_family(0x0c059b0eu,s,ram);
P_0c059b40: /* original d538, guest PC 0x0c059b40 */
if(!s->budget--) { s->failed_pc=0x0c059b40u; return 0; }
r[5]=read(ram,0x0c059c24u,4);
goto P_0c059b42;
P_0c059b42: /* original d039, guest PC 0x0c059b42 */
if(!s->budget--) { s->failed_pc=0x0c059b42u; return 0; }
r[0]=read(ram,0x0c059c28u,4);
goto P_0c059b44;
P_0c059b44: /* original d239, guest PC 0x0c059b44 */
if(!s->budget--) { s->failed_pc=0x0c059b44u; return 0; }
r[2]=read(ram,0x0c059c2cu,4);
goto P_0c059b46;
P_0c059b46: /* original 6302, guest PC 0x0c059b46 */
if(!s->budget--) { s->failed_pc=0x0c059b46u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059b48;
P_0c059b48: /* original e048, guest PC 0x0c059b48 */
if(!s->budget--) { s->failed_pc=0x0c059b48u; return 0; }
r[0]=0x00000048u;
goto P_0c059b4a;
P_0c059b4a: /* original 0536, guest PC 0x0c059b4a */
if(!s->budget--) { s->failed_pc=0x0c059b4au; return 0; }
write(ram,r[5]+r[0],r[3],4);
goto P_0c059b4c;
P_0c059b4c: /* original 6422, guest PC 0x0c059b4c */
if(!s->budget--) { s->failed_pc=0x0c059b4cu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c059b4e;
P_0c059b4e: /* original d338, guest PC 0x0c059b4e */
if(!s->budget--) { s->failed_pc=0x0c059b4eu; return 0; }
r[3]=read(ram,0x0c059c30u,4);
goto P_0c059b50;
P_0c059b50: /* original 2342, guest PC 0x0c059b50 */
if(!s->budget--) { s->failed_pc=0x0c059b50u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c059b52;
P_0c059b52: /* original d138, guest PC 0x0c059b52 */
if(!s->budget--) { s->failed_pc=0x0c059b52u; return 0; }
r[1]=read(ram,0x0c059c34u,4);
goto P_0c059b54;
P_0c059b54: /* original 21d2, guest PC 0x0c059b54 */
if(!s->budget--) { s->failed_pc=0x0c059b54u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c059b56;
P_0c059b56: /* original d238, guest PC 0x0c059b56 */
if(!s->budget--) { s->failed_pc=0x0c059b56u; return 0; }
r[2]=read(ram,0x0c059c38u,4);
goto P_0c059b58;
P_0c059b58: /* original 22c2, guest PC 0x0c059b58 */
if(!s->budget--) { s->failed_pc=0x0c059b58u; return 0; }
write(ram,r[2],r[12],4);
goto P_0c059b5a;
P_0c059b5a: /* original d038, guest PC 0x0c059b5a */
if(!s->budget--) { s->failed_pc=0x0c059b5au; return 0; }
r[0]=read(ram,0x0c059c3cu,4);
goto P_0c059b5c;
P_0c059b5c: /* original 6302, guest PC 0x0c059b5c */
if(!s->budget--) { s->failed_pc=0x0c059b5cu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059b5e;
P_0c059b5e: /* original d138, guest PC 0x0c059b5e */
if(!s->budget--) { s->failed_pc=0x0c059b5eu; return 0; }
r[1]=read(ram,0x0c059c40u,4);
goto P_0c059b60;
P_0c059b60: /* original 2132, guest PC 0x0c059b60 */
if(!s->budget--) { s->failed_pc=0x0c059b60u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c059b62;
P_0c059b62: /* original 7208, guest PC 0x0c059b62 */
if(!s->budget--) { s->failed_pc=0x0c059b62u; return 0; }
r[2]+=0x00000008u;
goto P_0c059b64;
P_0c059b64: /* original 22d2, guest PC 0x0c059b64 */
if(!s->budget--) { s->failed_pc=0x0c059b64u; return 0; }
write(ram,r[2],r[13],4);
goto P_0c059b66;
P_0c059b66: /* original 4408, guest PC 0x0c059b66 */
if(!s->budget--) { s->failed_pc=0x0c059b66u; return 0; }
r[4]<<=2;
goto P_0c059b68;
P_0c059b68: /* original 15c1, guest PC 0x0c059b68 */
if(!s->budget--) { s->failed_pc=0x0c059b68u; return 0; }
write(ram,r[5]+4,r[12],4);
goto P_0c059b6a;
P_0c059b6a: /* original e302, guest PC 0x0c059b6a */
if(!s->budget--) { s->failed_pc=0x0c059b6au; return 0; }
r[3]=0x00000002u;
goto P_0c059b6c;
P_0c059b6c: /* original d035, guest PC 0x0c059b6c */
if(!s->budget--) { s->failed_pc=0x0c059b6cu; return 0; }
r[0]=read(ram,0x0c059c44u,4);
goto P_0c059b6e;
P_0c059b6e: /* original 0436, guest PC 0x0c059b6e */
if(!s->budget--) { s->failed_pc=0x0c059b6eu; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c059b70;
P_0c059b70: /* original d135, guest PC 0x0c059b70 */
if(!s->budget--) { s->failed_pc=0x0c059b70u; return 0; }
r[1]=read(ram,0x0c059c48u,4);
goto P_0c059b72;
P_0c059b72: /* original 6012, guest PC 0x0c059b72 */
if(!s->budget--) { s->failed_pc=0x0c059b72u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059b74;
P_0c059b74: /* original c820, guest PC 0x0c059b74 */
if(!s->budget--) { s->failed_pc=0x0c059b74u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c059b76;
P_0c059b76: /* original 890d, guest PC 0x0c059b76 */
if(!s->budget--) { s->failed_pc=0x0c059b76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059b94; }
goto P_0c059b78;
P_0c059b78: /* original d034, guest PC 0x0c059b78 */
if(!s->budget--) { s->failed_pc=0x0c059b78u; return 0; }
r[0]=read(ram,0x0c059c4cu,4);
goto P_0c059b7a;
P_0c059b7a: /* original e410, guest PC 0x0c059b7a */
if(!s->budget--) { s->failed_pc=0x0c059b7au; return 0; }
r[4]=0x00000010u;
goto P_0c059b7c;
P_0c059b7c: /* original 2042, guest PC 0x0c059b7c */
if(!s->budget--) { s->failed_pc=0x0c059b7cu; return 0; }
write(ram,r[0],r[4],4);
goto P_0c059b7e;
P_0c059b7e: /* original d334, guest PC 0x0c059b7e */
if(!s->budget--) { s->failed_pc=0x0c059b7eu; return 0; }
r[3]=read(ram,0x0c059c50u,4);
goto P_0c059b80;
P_0c059b80: /* original 2342, guest PC 0x0c059b80 */
if(!s->budget--) { s->failed_pc=0x0c059b80u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c059b82;
P_0c059b82: /* original d534, guest PC 0x0c059b82 */
if(!s->budget--) { s->failed_pc=0x0c059b82u; return 0; }
r[5]=read(ram,0x0c059c54u,4);
goto P_0c059b84;
P_0c059b84: /* original d434, guest PC 0x0c059b84 */
if(!s->budget--) { s->failed_pc=0x0c059b84u; return 0; }
r[4]=read(ram,0x0c059c58u,4);
goto P_0c059b86;
P_0c059b86: /* original d235, guest PC 0x0c059b86 */
if(!s->budget--) { s->failed_pc=0x0c059b86u; return 0; }
r[2]=read(ram,0x0c059c5cu,4);
goto P_0c059b88;
P_0c059b88: /* original 420b, guest PC 0x0c059b88 */
if(!s->budget--) { s->failed_pc=0x0c059b88u; return 0; }
target=r[2];
r[16]=code_base|0x0c059b8cu;
r[6]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059b8cu) { target=s->pc; goto dispatch; }
goto P_0c059b8c;
P_0c059b8a: /* original e604, guest PC 0x0c059b8a */
if(!s->budget--) { s->failed_pc=0x0c059b8au; return 0; }
r[6]=0x00000004u;
goto P_0c059b8c;
P_0c059b8c: /* original d332, guest PC 0x0c059b8c */
if(!s->budget--) { s->failed_pc=0x0c059b8cu; return 0; }
r[3]=read(ram,0x0c059c58u,4);
goto P_0c059b8e;
P_0c059b8e: /* original 0383, guest PC 0x0c059b8e */
if(!s->budget--) { s->failed_pc=0x0c059b8eu; return 0; }
if((r[3]&0xFC000000u)==0xE0000000u) pref(ram,r[3]);
goto P_0c059b90;
P_0c059b90: /* original a022, guest PC 0x0c059b90 */
if(!s->budget--) { s->failed_pc=0x0c059b90u; return 0; }
goto P_0c059bd8;
P_0c059b92: /* original 0009, guest PC 0x0c059b92 */
if(!s->budget--) { s->failed_pc=0x0c059b92u; return 0; }
goto P_0c059b94;
P_0c059b94: /* original d025, guest PC 0x0c059b94 */
if(!s->budget--) { s->failed_pc=0x0c059b94u; return 0; }
r[0]=read(ram,0x0c059c2cu,4);
goto P_0c059b96;
P_0c059b96: /* original 6902, guest PC 0x0c059b96 */
if(!s->budget--) { s->failed_pc=0x0c059b96u; return 0; }
tmp=read(ram,r[0],4);
r[9]=tmp;
goto P_0c059b98;
P_0c059b98: /* original d331, guest PC 0x0c059b98 */
if(!s->budget--) { s->failed_pc=0x0c059b98u; return 0; }
r[3]=read(ram,0x0c059c60u,4);
goto P_0c059b9a;
P_0c059b9a: /* original 6203, guest PC 0x0c059b9a */
if(!s->budget--) { s->failed_pc=0x0c059b9au; return 0; }
r[2]=r[0];
goto P_0c059b9c;
P_0c059b9c: /* original 6a22, guest PC 0x0c059b9c */
if(!s->budget--) { s->failed_pc=0x0c059b9cu; return 0; }
tmp=read(ram,r[2],4);
r[10]=tmp;
goto P_0c059b9e;
P_0c059b9e: /* original 4908, guest PC 0x0c059b9e */
if(!s->budget--) { s->failed_pc=0x0c059b9eu; return 0; }
r[9]<<=2;
goto P_0c059ba0;
P_0c059ba0: /* original d030, guest PC 0x0c059ba0 */
if(!s->budget--) { s->failed_pc=0x0c059ba0u; return 0; }
r[0]=read(ram,0x0c059c64u,4);
goto P_0c059ba2;
P_0c059ba2: /* original 4a08, guest PC 0x0c059ba2 */
if(!s->budget--) { s->failed_pc=0x0c059ba2u; return 0; }
r[10]<<=2;
goto P_0c059ba4;
P_0c059ba4: /* original 393c, guest PC 0x0c059ba4 */
if(!s->budget--) { s->failed_pc=0x0c059ba4u; return 0; }
r[9]+=r[3];
goto P_0c059ba6;
P_0c059ba6: /* original 7350, guest PC 0x0c059ba6 */
if(!s->budget--) { s->failed_pc=0x0c059ba6u; return 0; }
r[3]+=0x00000050u;
goto P_0c059ba8;
P_0c059ba8: /* original 3a3c, guest PC 0x0c059ba8 */
if(!s->budget--) { s->failed_pc=0x0c059ba8u; return 0; }
r[10]+=r[3];
goto P_0c059baa;
P_0c059baa: /* original 6102, guest PC 0x0c059baa */
if(!s->budget--) { s->failed_pc=0x0c059baau; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c059bac;
P_0c059bac: /* original 4108, guest PC 0x0c059bac */
if(!s->budget--) { s->failed_pc=0x0c059bacu; return 0; }
r[1]<<=2;
goto P_0c059bae;
P_0c059bae: /* original 4108, guest PC 0x0c059bae */
if(!s->budget--) { s->failed_pc=0x0c059baeu; return 0; }
r[1]<<=2;
goto P_0c059bb0;
P_0c059bb0: /* original 3a1c, guest PC 0x0c059bb0 */
if(!s->budget--) { s->failed_pc=0x0c059bb0u; return 0; }
r[10]+=r[1];
goto P_0c059bb2;
P_0c059bb2: /* original 6103, guest PC 0x0c059bb2 */
if(!s->budget--) { s->failed_pc=0x0c059bb2u; return 0; }
r[1]=r[0];
goto P_0c059bb4;
P_0c059bb4: /* original 6312, guest PC 0x0c059bb4 */
if(!s->budget--) { s->failed_pc=0x0c059bb4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059bb6;
P_0c059bb6: /* original 4308, guest PC 0x0c059bb6 */
if(!s->budget--) { s->failed_pc=0x0c059bb6u; return 0; }
r[3]<<=2;
goto P_0c059bb8;
P_0c059bb8: /* original d82b, guest PC 0x0c059bb8 */
if(!s->budget--) { s->failed_pc=0x0c059bb8u; return 0; }
r[8]=read(ram,0x0c059c68u,4);
goto P_0c059bba;
P_0c059bba: /* original 4308, guest PC 0x0c059bba */
if(!s->budget--) { s->failed_pc=0x0c059bbau; return 0; }
r[3]<<=2;
goto P_0c059bbc;
P_0c059bbc: /* original db2b, guest PC 0x0c059bbc */
if(!s->budget--) { s->failed_pc=0x0c059bbcu; return 0; }
r[11]=read(ram,0x0c059c6cu,4);
goto P_0c059bbe;
P_0c059bbe: /* original 393c, guest PC 0x0c059bbe */
if(!s->budget--) { s->failed_pc=0x0c059bbeu; return 0; }
r[9]+=r[3];
goto P_0c059bc0;
P_0c059bc0: /* original 9e2e, guest PC 0x0c059bc0 */
if(!s->budget--) { s->failed_pc=0x0c059bc0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059c20u,2);
goto P_0c059bc2;
P_0c059bc2: /* original 62f3, guest PC 0x0c059bc2 */
if(!s->budget--) { s->failed_pc=0x0c059bc2u; return 0; }
r[2]=r[15];
goto P_0c059bc4;
P_0c059bc4: /* original 2f26, guest PC 0x0c059bc4 */
if(!s->budget--) { s->failed_pc=0x0c059bc4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059bc6;
P_0c059bc6: /* original e710, guest PC 0x0c059bc6 */
if(!s->budget--) { s->failed_pc=0x0c059bc6u; return 0; }
r[7]=0x00000010u;
goto P_0c059bc8;
P_0c059bc8: /* original 66a2, guest PC 0x0c059bc8 */
if(!s->budget--) { s->failed_pc=0x0c059bc8u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c059bca;
P_0c059bca: /* original 7620, guest PC 0x0c059bca */
if(!s->budget--) { s->failed_pc=0x0c059bcau; return 0; }
r[6]+=0x00000020u;
goto P_0c059bcc;
P_0c059bcc: /* original 6592, guest PC 0x0c059bcc */
if(!s->budget--) { s->failed_pc=0x0c059bccu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c059bce;
P_0c059bce: /* original 480b, guest PC 0x0c059bce */
if(!s->budget--) { s->failed_pc=0x0c059bceu; return 0; }
target=r[8];
r[16]=code_base|0x0c059bd2u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059bd2u) { target=s->pc; goto dispatch; }
goto P_0c059bd2;
P_0c059bd0: /* original 64b3, guest PC 0x0c059bd0 */
if(!s->budget--) { s->failed_pc=0x0c059bd0u; return 0; }
r[4]=r[11];
goto P_0c059bd2;
P_0c059bd2: /* original 30e0, guest PC 0x0c059bd2 */
if(!s->budget--) { s->failed_pc=0x0c059bd2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[14])!=0);
goto P_0c059bd4;
P_0c059bd4: /* original 8df5, guest PC 0x0c059bd4 */
if(!s->budget--) { s->failed_pc=0x0c059bd4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c059bc2; }
goto P_0c059bd8;
P_0c059bd6: /* original 7f04, guest PC 0x0c059bd6 */
if(!s->budget--) { s->failed_pc=0x0c059bd6u; return 0; }
r[15]+=0x00000004u;
goto P_0c059bd8;
P_0c059bd8: /* original d222, guest PC 0x0c059bd8 */
if(!s->budget--) { s->failed_pc=0x0c059bd8u; return 0; }
r[2]=read(ram,0x0c059c64u,4);
goto P_0c059bda;
P_0c059bda: /* original bf21, guest PC 0x0c059bda */
if(!s->budget--) { s->failed_pc=0x0c059bdau; return 0; }
target=0x0c059a20u; r[16]=code_base|0x0c059bdeu;
tmp=read(ram,r[2],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059bdeu) { target=s->pc; goto dispatch; }
goto P_0c059bde;
P_0c059bdc: /* original 6422, guest PC 0x0c059bdc */
if(!s->budget--) { s->failed_pc=0x0c059bdcu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c059bde;
P_0c059bde: /* original d124, guest PC 0x0c059bde */
if(!s->budget--) { s->failed_pc=0x0c059bdeu; return 0; }
r[1]=read(ram,0x0c059c70u,4);
goto P_0c059be0;
P_0c059be0: /* original 21c2, guest PC 0x0c059be0 */
if(!s->budget--) { s->failed_pc=0x0c059be0u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c059be2;
P_0c059be2: /* original a010, guest PC 0x0c059be2 */
if(!s->budget--) { s->failed_pc=0x0c059be2u; return 0; }
r[14]=0x00000000u;
goto P_0c059c06;
P_0c059be4: /* original ee00, guest PC 0x0c059be4 */
if(!s->budget--) { s->failed_pc=0x0c059be4u; return 0; }
r[14]=0x00000000u;
goto P_0c059be6;
P_0c059be6: /* original d223, guest PC 0x0c059be6 */
if(!s->budget--) { s->failed_pc=0x0c059be6u; return 0; }
r[2]=read(ram,0x0c059c74u,4);
goto P_0c059be8;
P_0c059be8: /* original 6322, guest PC 0x0c059be8 */
if(!s->budget--) { s->failed_pc=0x0c059be8u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059bea;
P_0c059bea: /* original 430b, guest PC 0x0c059bea */
if(!s->budget--) { s->failed_pc=0x0c059beau; return 0; }
target=r[3];
r[16]=code_base|0x0c059beeu;
r[4]=read(ram,r[2]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059beeu) { target=s->pc; goto dispatch; }
goto P_0c059bee;
P_0c059bec: /* original 5421, guest PC 0x0c059bec */
if(!s->budget--) { s->failed_pc=0x0c059becu; return 0; }
r[4]=read(ram,r[2]+4,4);
goto P_0c059bee;
P_0c059bee: /* original d022, guest PC 0x0c059bee */
if(!s->budget--) { s->failed_pc=0x0c059beeu; return 0; }
r[0]=read(ram,0x0c059c78u,4);
goto P_0c059bf0;
P_0c059bf0: /* original 6302, guest PC 0x0c059bf0 */
if(!s->budget--) { s->failed_pc=0x0c059bf0u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059bf2;
P_0c059bf2: /* original d222, guest PC 0x0c059bf2 */
if(!s->budget--) { s->failed_pc=0x0c059bf2u; return 0; }
r[2]=read(ram,0x0c059c7cu,4);
goto P_0c059bf4;
P_0c059bf4: /* original 6122, guest PC 0x0c059bf4 */
if(!s->budget--) { s->failed_pc=0x0c059bf4u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c059bf6;
P_0c059bf6: /* original 313c, guest PC 0x0c059bf6 */
if(!s->budget--) { s->failed_pc=0x0c059bf6u; return 0; }
r[1]+=r[3];
goto P_0c059bf8;
P_0c059bf8: /* original d21d, guest PC 0x0c059bf8 */
if(!s->budget--) { s->failed_pc=0x0c059bf8u; return 0; }
r[2]=read(ram,0x0c059c70u,4);
goto P_0c059bfa;
P_0c059bfa: /* original 7101, guest PC 0x0c059bfa */
if(!s->budget--) { s->failed_pc=0x0c059bfau; return 0; }
r[1]+=0x00000001u;
goto P_0c059bfc;
P_0c059bfc: /* original 6322, guest PC 0x0c059bfc */
if(!s->budget--) { s->failed_pc=0x0c059bfcu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059bfe;
P_0c059bfe: /* original 3316, guest PC 0x0c059bfe */
if(!s->budget--) { s->failed_pc=0x0c059bfeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[1])!=0);
goto P_0c059c00;
P_0c059c00: /* original 8b01, guest PC 0x0c059c00 */
if(!s->budget--) { s->failed_pc=0x0c059c00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059c06; }
goto P_0c059c02;
P_0c059c02: /* original a004, guest PC 0x0c059c02 */
if(!s->budget--) { s->failed_pc=0x0c059c02u; return 0; }
r[14]=0x00000001u;
goto P_0c059c0e;
P_0c059c04: /* original ee01, guest PC 0x0c059c04 */
if(!s->budget--) { s->failed_pc=0x0c059c04u; return 0; }
r[14]=0x00000001u;
goto P_0c059c06;
P_0c059c06: /* original d31e, guest PC 0x0c059c06 */
if(!s->budget--) { s->failed_pc=0x0c059c06u; return 0; }
r[3]=read(ram,0x0c059c80u,4);
goto P_0c059c08;
P_0c059c08: /* original 6232, guest PC 0x0c059c08 */
if(!s->budget--) { s->failed_pc=0x0c059c08u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059c0a;
P_0c059c0a: /* original 2228, guest PC 0x0c059c0a */
if(!s->budget--) { s->failed_pc=0x0c059c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c059c0c;
P_0c059c0c: /* original 8beb, guest PC 0x0c059c0c */
if(!s->budget--) { s->failed_pc=0x0c059c0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059be6; }
goto P_0c059c0e;
P_0c059c0e: /* original 2ee8, guest PC 0x0c059c0e */
if(!s->budget--) { s->failed_pc=0x0c059c0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c059c10;
P_0c059c10: /* original 894d, guest PC 0x0c059c10 */
if(!s->budget--) { s->failed_pc=0x0c059c10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059cae; }
goto P_0c059c12;
P_0c059c12: /* original d31c, guest PC 0x0c059c12 */
if(!s->budget--) { s->failed_pc=0x0c059c12u; return 0; }
r[3]=read(ram,0x0c059c84u,4);
goto P_0c059c14;
P_0c059c14: /* original 23c2, guest PC 0x0c059c14 */
if(!s->budget--) { s->failed_pc=0x0c059c14u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c059c16;
P_0c059c16: /* original d216, guest PC 0x0c059c16 */
if(!s->budget--) { s->failed_pc=0x0c059c16u; return 0; }
r[2]=read(ram,0x0c059c70u,4);
goto P_0c059c18;
P_0c059c18: /* original 22c2, guest PC 0x0c059c18 */
if(!s->budget--) { s->failed_pc=0x0c059c18u; return 0; }
write(ram,r[2],r[12],4);
goto P_0c059c1a;
P_0c059c1a: /* original eb00, guest PC 0x0c059c1a */
if(!s->budget--) { s->failed_pc=0x0c059c1au; return 0; }
r[11]=0x00000000u;
goto P_0c059c1c;
P_0c059c1c: /* original a03e, guest PC 0x0c059c1c */
if(!s->budget--) { s->failed_pc=0x0c059c1cu; return 0; }
r[14]=0x00000014u;
goto P_0c059c9c;
P_0c059c1e: /* original ee14, guest PC 0x0c059c1e */
if(!s->budget--) { s->failed_pc=0x0c059c1eu; return 0; }
r[14]=0x00000014u;
return vf3_matrix_family(0x0c059c20u,s,ram);
P_0c059c88: /* original d340, guest PC 0x0c059c88 */
if(!s->budget--) { s->failed_pc=0x0c059c88u; return 0; }
r[3]=read(ram,0x0c059d8cu,4);
goto P_0c059c8a;
P_0c059c8a: /* original 6232, guest PC 0x0c059c8a */
if(!s->budget--) { s->failed_pc=0x0c059c8au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059c8c;
P_0c059c8c: /* original 420b, guest PC 0x0c059c8c */
if(!s->budget--) { s->failed_pc=0x0c059c8cu; return 0; }
target=r[2];
r[16]=code_base|0x0c059c90u;
r[4]=read(ram,r[3]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059c90u) { target=s->pc; goto dispatch; }
goto P_0c059c90;
P_0c059c8e: /* original 5431, guest PC 0x0c059c8e */
if(!s->budget--) { s->failed_pc=0x0c059c8eu; return 0; }
r[4]=read(ram,r[3]+4,4);
goto P_0c059c90;
P_0c059c90: /* original d23f, guest PC 0x0c059c90 */
if(!s->budget--) { s->failed_pc=0x0c059c90u; return 0; }
r[2]=read(ram,0x0c059d90u,4);
goto P_0c059c92;
P_0c059c92: /* original 6122, guest PC 0x0c059c92 */
if(!s->budget--) { s->failed_pc=0x0c059c92u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c059c94;
P_0c059c94: /* original 31e6, guest PC 0x0c059c94 */
if(!s->budget--) { s->failed_pc=0x0c059c94u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[14])!=0);
goto P_0c059c96;
P_0c059c96: /* original 8b01, guest PC 0x0c059c96 */
if(!s->budget--) { s->failed_pc=0x0c059c96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059c9c; }
goto P_0c059c98;
P_0c059c98: /* original a004, guest PC 0x0c059c98 */
if(!s->budget--) { s->failed_pc=0x0c059c98u; return 0; }
r[11]=0x00000001u;
goto P_0c059ca4;
P_0c059c9a: /* original eb01, guest PC 0x0c059c9a */
if(!s->budget--) { s->failed_pc=0x0c059c9au; return 0; }
r[11]=0x00000001u;
goto P_0c059c9c;
P_0c059c9c: /* original d23d, guest PC 0x0c059c9c */
if(!s->budget--) { s->failed_pc=0x0c059c9cu; return 0; }
r[2]=read(ram,0x0c059d94u,4);
goto P_0c059c9e;
P_0c059c9e: /* original 6322, guest PC 0x0c059c9e */
if(!s->budget--) { s->failed_pc=0x0c059c9eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059ca0;
P_0c059ca0: /* original 2338, guest PC 0x0c059ca0 */
if(!s->budget--) { s->failed_pc=0x0c059ca0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059ca2;
P_0c059ca2: /* original 8bf1, guest PC 0x0c059ca2 */
if(!s->budget--) { s->failed_pc=0x0c059ca2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059c88; }
goto P_0c059ca4;
P_0c059ca4: /* original 2bb8, guest PC 0x0c059ca4 */
if(!s->budget--) { s->failed_pc=0x0c059ca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c059ca6;
P_0c059ca6: /* original 8902, guest PC 0x0c059ca6 */
if(!s->budget--) { s->failed_pc=0x0c059ca6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059cae; }
goto P_0c059ca8;
P_0c059ca8: /* original d23b, guest PC 0x0c059ca8 */
if(!s->budget--) { s->failed_pc=0x0c059ca8u; return 0; }
r[2]=read(ram,0x0c059d98u,4);
goto P_0c059caa;
P_0c059caa: /* original 420b, guest PC 0x0c059caa */
if(!s->budget--) { s->failed_pc=0x0c059caau; return 0; }
target=r[2];
r[16]=code_base|0x0c059caeu;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059caeu) { target=s->pc; goto dispatch; }
goto P_0c059cae;
P_0c059cac: /* original e404, guest PC 0x0c059cac */
if(!s->budget--) { s->failed_pc=0x0c059cacu; return 0; }
r[4]=0x00000004u;
goto P_0c059cae;
P_0c059cae: /* original d33b, guest PC 0x0c059cae */
if(!s->budget--) { s->failed_pc=0x0c059caeu; return 0; }
r[3]=read(ram,0x0c059d9cu,4);
goto P_0c059cb0;
P_0c059cb0: /* original 6232, guest PC 0x0c059cb0 */
if(!s->budget--) { s->failed_pc=0x0c059cb0u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059cb2;
P_0c059cb2: /* original 7201, guest PC 0x0c059cb2 */
if(!s->budget--) { s->failed_pc=0x0c059cb2u; return 0; }
r[2]+=0x00000001u;
goto P_0c059cb4;
P_0c059cb4: /* original 2322, guest PC 0x0c059cb4 */
if(!s->budget--) { s->failed_pc=0x0c059cb4u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c059cb6;
P_0c059cb6: /* original 6032, guest PC 0x0c059cb6 */
if(!s->budget--) { s->failed_pc=0x0c059cb6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059cb8;
P_0c059cb8: /* original c903, guest PC 0x0c059cb8 */
if(!s->budget--) { s->failed_pc=0x0c059cb8u; return 0; }
r[0]&=3u;
goto P_0c059cba;
P_0c059cba: /* original 2302, guest PC 0x0c059cba */
if(!s->budget--) { s->failed_pc=0x0c059cbau; return 0; }
write(ram,r[3],r[0],4);
goto P_0c059cbc;
P_0c059cbc: /* original d038, guest PC 0x0c059cbc */
if(!s->budget--) { s->failed_pc=0x0c059cbcu; return 0; }
r[0]=read(ram,0x0c059da0u,4);
goto P_0c059cbe;
P_0c059cbe: /* original 6232, guest PC 0x0c059cbe */
if(!s->budget--) { s->failed_pc=0x0c059cbeu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059cc0;
P_0c059cc0: /* original 4208, guest PC 0x0c059cc0 */
if(!s->budget--) { s->failed_pc=0x0c059cc0u; return 0; }
r[2]<<=2;
goto P_0c059cc2;
P_0c059cc2: /* original 02c6, guest PC 0x0c059cc2 */
if(!s->budget--) { s->failed_pc=0x0c059cc2u; return 0; }
write(ram,r[2]+r[0],r[12],4);
goto P_0c059cc4;
P_0c059cc4: /* original d237, guest PC 0x0c059cc4 */
if(!s->budget--) { s->failed_pc=0x0c059cc4u; return 0; }
r[2]=read(ram,0x0c059da4u,4);
goto P_0c059cc6;
P_0c059cc6: /* original 6022, guest PC 0x0c059cc6 */
if(!s->budget--) { s->failed_pc=0x0c059cc6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c059cc8;
P_0c059cc8: /* original 8801, guest PC 0x0c059cc8 */
if(!s->budget--) { s->failed_pc=0x0c059cc8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059cca;
P_0c059cca: /* original 8903, guest PC 0x0c059cca */
if(!s->budget--) { s->failed_pc=0x0c059ccau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059cd4; }
goto P_0c059ccc;
P_0c059ccc: /* original d136, guest PC 0x0c059ccc */
if(!s->budget--) { s->failed_pc=0x0c059cccu; return 0; }
r[1]=read(ram,0x0c059da8u,4);
goto P_0c059cce;
P_0c059cce: /* original 6012, guest PC 0x0c059cce */
if(!s->budget--) { s->failed_pc=0x0c059cceu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059cd0;
P_0c059cd0: /* original 8801, guest PC 0x0c059cd0 */
if(!s->budget--) { s->failed_pc=0x0c059cd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059cd2;
P_0c059cd2: /* original 8b43, guest PC 0x0c059cd2 */
if(!s->budget--) { s->failed_pc=0x0c059cd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059d5c; }
goto P_0c059cd4;
P_0c059cd4: /* original d331, guest PC 0x0c059cd4 */
if(!s->budget--) { s->failed_pc=0x0c059cd4u; return 0; }
r[3]=read(ram,0x0c059d9cu,4);
goto P_0c059cd6;
P_0c059cd6: /* original 6232, guest PC 0x0c059cd6 */
if(!s->budget--) { s->failed_pc=0x0c059cd6u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059cd8;
P_0c059cd8: /* original 22d9, guest PC 0x0c059cd8 */
if(!s->budget--) { s->failed_pc=0x0c059cd8u; return 0; }
r[2]&=r[13];
goto P_0c059cda;
P_0c059cda: /* original e501, guest PC 0x0c059cda */
if(!s->budget--) { s->failed_pc=0x0c059cdau; return 0; }
r[5]=0x00000001u;
goto P_0c059cdc;
P_0c059cdc: /* original 1f21, guest PC 0x0c059cdc */
if(!s->budget--) { s->failed_pc=0x0c059cdcu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c059cde;
P_0c059cde: /* original de33, guest PC 0x0c059cde */
if(!s->budget--) { s->failed_pc=0x0c059cdeu; return 0; }
r[14]=read(ram,0x0c059dacu,4);
goto P_0c059ce0;
P_0c059ce0: /* original 4e0b, guest PC 0x0c059ce0 */
if(!s->budget--) { s->failed_pc=0x0c059ce0u; return 0; }
target=r[14];
r[16]=code_base|0x0c059ce4u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059ce4u) { target=s->pc; goto dispatch; }
goto P_0c059ce4;
P_0c059ce2: /* original e408, guest PC 0x0c059ce2 */
if(!s->budget--) { s->failed_pc=0x0c059ce2u; return 0; }
r[4]=0x00000008u;
goto P_0c059ce4;
P_0c059ce4: /* original e500, guest PC 0x0c059ce4 */
if(!s->budget--) { s->failed_pc=0x0c059ce4u; return 0; }
r[5]=0x00000000u;
goto P_0c059ce6;
P_0c059ce6: /* original 4e0b, guest PC 0x0c059ce6 */
if(!s->budget--) { s->failed_pc=0x0c059ce6u; return 0; }
target=r[14];
r[16]=code_base|0x0c059ceau;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059ceau) { target=s->pc; goto dispatch; }
goto P_0c059cea;
P_0c059ce8: /* original e408, guest PC 0x0c059ce8 */
if(!s->budget--) { s->failed_pc=0x0c059ce8u; return 0; }
r[4]=0x00000008u;
goto P_0c059cea;
P_0c059cea: /* original 5bf1, guest PC 0x0c059cea */
if(!s->budget--) { s->failed_pc=0x0c059ceau; return 0; }
r[11]=read(ram,r[15]+4,4);
goto P_0c059cec;
P_0c059cec: /* original d030, guest PC 0x0c059cec */
if(!s->budget--) { s->failed_pc=0x0c059cecu; return 0; }
r[0]=read(ram,0x0c059db0u,4);
goto P_0c059cee;
P_0c059cee: /* original 4b08, guest PC 0x0c059cee */
if(!s->budget--) { s->failed_pc=0x0c059ceeu; return 0; }
r[11]<<=2;
goto P_0c059cf0;
P_0c059cf0: /* original 9445, guest PC 0x0c059cf0 */
if(!s->budget--) { s->failed_pc=0x0c059cf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d7eu,2);
goto P_0c059cf2;
P_0c059cf2: /* original 4b08, guest PC 0x0c059cf2 */
if(!s->budget--) { s->failed_pc=0x0c059cf2u; return 0; }
r[11]<<=2;
goto P_0c059cf4;
P_0c059cf4: /* original 4b00, guest PC 0x0c059cf4 */
if(!s->budget--) { s->failed_pc=0x0c059cf4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c059cf6;
P_0c059cf6: /* original 4e0b, guest PC 0x0c059cf6 */
if(!s->budget--) { s->failed_pc=0x0c059cf6u; return 0; }
target=r[14];
r[16]=code_base|0x0c059cfau;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059cfau) { target=s->pc; goto dispatch; }
goto P_0c059cfa;
P_0c059cf8: /* original 05be, guest PC 0x0c059cf8 */
if(!s->budget--) { s->failed_pc=0x0c059cf8u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059cfa;
P_0c059cfa: /* original d02e, guest PC 0x0c059cfa */
if(!s->budget--) { s->failed_pc=0x0c059cfau; return 0; }
r[0]=read(ram,0x0c059db4u,4);
goto P_0c059cfc;
P_0c059cfc: /* original 9440, guest PC 0x0c059cfc */
if(!s->budget--) { s->failed_pc=0x0c059cfcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d80u,2);
goto P_0c059cfe;
P_0c059cfe: /* original 4e0b, guest PC 0x0c059cfe */
if(!s->budget--) { s->failed_pc=0x0c059cfeu; return 0; }
target=r[14];
r[16]=code_base|0x0c059d02u;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d02u) { target=s->pc; goto dispatch; }
goto P_0c059d02;
P_0c059d00: /* original 05be, guest PC 0x0c059d00 */
if(!s->budget--) { s->failed_pc=0x0c059d00u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d02;
P_0c059d02: /* original d02d, guest PC 0x0c059d02 */
if(!s->budget--) { s->failed_pc=0x0c059d02u; return 0; }
r[0]=read(ram,0x0c059db8u,4);
goto P_0c059d04;
P_0c059d04: /* original 943d, guest PC 0x0c059d04 */
if(!s->budget--) { s->failed_pc=0x0c059d04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d82u,2);
goto P_0c059d06;
P_0c059d06: /* original 4e0b, guest PC 0x0c059d06 */
if(!s->budget--) { s->failed_pc=0x0c059d06u; return 0; }
target=r[14];
r[16]=code_base|0x0c059d0au;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d0au) { target=s->pc; goto dispatch; }
goto P_0c059d0a;
P_0c059d08: /* original 05be, guest PC 0x0c059d08 */
if(!s->budget--) { s->failed_pc=0x0c059d08u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d0a;
P_0c059d0a: /* original d02c, guest PC 0x0c059d0a */
if(!s->budget--) { s->failed_pc=0x0c059d0au; return 0; }
r[0]=read(ram,0x0c059dbcu,4);
goto P_0c059d0c;
P_0c059d0c: /* original 943a, guest PC 0x0c059d0c */
if(!s->budget--) { s->failed_pc=0x0c059d0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d84u,2);
goto P_0c059d0e;
P_0c059d0e: /* original 4e0b, guest PC 0x0c059d0e */
if(!s->budget--) { s->failed_pc=0x0c059d0eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059d12u;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d12u) { target=s->pc; goto dispatch; }
goto P_0c059d12;
P_0c059d10: /* original 05be, guest PC 0x0c059d10 */
if(!s->budget--) { s->failed_pc=0x0c059d10u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d12;
P_0c059d12: /* original d02b, guest PC 0x0c059d12 */
if(!s->budget--) { s->failed_pc=0x0c059d12u; return 0; }
r[0]=read(ram,0x0c059dc0u,4);
goto P_0c059d14;
P_0c059d14: /* original 9437, guest PC 0x0c059d14 */
if(!s->budget--) { s->failed_pc=0x0c059d14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d86u,2);
goto P_0c059d16;
P_0c059d16: /* original 4e0b, guest PC 0x0c059d16 */
if(!s->budget--) { s->failed_pc=0x0c059d16u; return 0; }
target=r[14];
r[16]=code_base|0x0c059d1au;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d1au) { target=s->pc; goto dispatch; }
goto P_0c059d1a;
P_0c059d18: /* original 05be, guest PC 0x0c059d18 */
if(!s->budget--) { s->failed_pc=0x0c059d18u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d1a;
P_0c059d1a: /* original d52a, guest PC 0x0c059d1a */
if(!s->budget--) { s->failed_pc=0x0c059d1au; return 0; }
r[5]=read(ram,0x0c059dc4u,4);
goto P_0c059d1c;
P_0c059d1c: /* original 9434, guest PC 0x0c059d1c */
if(!s->budget--) { s->failed_pc=0x0c059d1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d88u,2);
goto P_0c059d1e;
P_0c059d1e: /* original 4e0b, guest PC 0x0c059d1e */
if(!s->budget--) { s->failed_pc=0x0c059d1eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059d22u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d22u) { target=s->pc; goto dispatch; }
goto P_0c059d22;
P_0c059d20: /* original 0009, guest PC 0x0c059d20 */
if(!s->budget--) { s->failed_pc=0x0c059d20u; return 0; }
goto P_0c059d22;
P_0c059d22: /* original 9431, guest PC 0x0c059d22 */
if(!s->budget--) { s->failed_pc=0x0c059d22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d88u,2);
goto P_0c059d24;
P_0c059d24: /* original d328, guest PC 0x0c059d24 */
if(!s->budget--) { s->failed_pc=0x0c059d24u; return 0; }
r[3]=read(ram,0x0c059dc8u,4);
goto P_0c059d26;
P_0c059d26: /* original 430b, guest PC 0x0c059d26 */
if(!s->budget--) { s->failed_pc=0x0c059d26u; return 0; }
target=r[3];
r[16]=code_base|0x0c059d2au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d2au) { target=s->pc; goto dispatch; }
goto P_0c059d2a;
P_0c059d28: /* original 0009, guest PC 0x0c059d28 */
if(!s->budget--) { s->failed_pc=0x0c059d28u; return 0; }
goto P_0c059d2a;
P_0c059d2a: /* original e200, guest PC 0x0c059d2a */
if(!s->budget--) { s->failed_pc=0x0c059d2au; return 0; }
r[2]=0x00000000u;
goto P_0c059d2c;
P_0c059d2c: /* original d327, guest PC 0x0c059d2c */
if(!s->budget--) { s->failed_pc=0x0c059d2cu; return 0; }
r[3]=read(ram,0x0c059dccu,4);
goto P_0c059d2e;
P_0c059d2e: /* original 2322, guest PC 0x0c059d2e */
if(!s->budget--) { s->failed_pc=0x0c059d2eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c059d30;
P_0c059d30: /* original d027, guest PC 0x0c059d30 */
if(!s->budget--) { s->failed_pc=0x0c059d30u; return 0; }
r[0]=read(ram,0x0c059dd0u,4);
goto P_0c059d32;
P_0c059d32: /* original 6102, guest PC 0x0c059d32 */
if(!s->budget--) { s->failed_pc=0x0c059d32u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c059d34;
P_0c059d34: /* original d227, guest PC 0x0c059d34 */
if(!s->budget--) { s->failed_pc=0x0c059d34u; return 0; }
r[2]=read(ram,0x0c059dd4u,4);
goto P_0c059d36;
P_0c059d36: /* original 2212, guest PC 0x0c059d36 */
if(!s->budget--) { s->failed_pc=0x0c059d36u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c059d38;
P_0c059d38: /* original d11b, guest PC 0x0c059d38 */
if(!s->budget--) { s->failed_pc=0x0c059d38u; return 0; }
r[1]=read(ram,0x0c059da8u,4);
goto P_0c059d3a;
P_0c059d3a: /* original 6312, guest PC 0x0c059d3a */
if(!s->budget--) { s->failed_pc=0x0c059d3au; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059d3c;
P_0c059d3c: /* original 2338, guest PC 0x0c059d3c */
if(!s->budget--) { s->failed_pc=0x0c059d3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059d3e;
P_0c059d3e: /* original 890d, guest PC 0x0c059d3e */
if(!s->budget--) { s->failed_pc=0x0c059d3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059d5c; }
goto P_0c059d40;
P_0c059d40: /* original d216, guest PC 0x0c059d40 */
if(!s->budget--) { s->failed_pc=0x0c059d40u; return 0; }
r[2]=read(ram,0x0c059d9cu,4);
goto P_0c059d42;
P_0c059d42: /* original 6322, guest PC 0x0c059d42 */
if(!s->budget--) { s->failed_pc=0x0c059d42u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059d44;
P_0c059d44: /* original d024, guest PC 0x0c059d44 */
if(!s->budget--) { s->failed_pc=0x0c059d44u; return 0; }
r[0]=read(ram,0x0c059dd8u,4);
goto P_0c059d46;
P_0c059d46: /* original 2032, guest PC 0x0c059d46 */
if(!s->budget--) { s->failed_pc=0x0c059d46u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c059d48;
P_0c059d48: /* original 70e8, guest PC 0x0c059d48 */
if(!s->budget--) { s->failed_pc=0x0c059d48u; return 0; }
r[0]+=0xffffffe8u;
goto P_0c059d4a;
P_0c059d4a: /* original 6323, guest PC 0x0c059d4a */
if(!s->budget--) { s->failed_pc=0x0c059d4au; return 0; }
r[3]=r[2];
goto P_0c059d4c;
P_0c059d4c: /* original 6132, guest PC 0x0c059d4c */
if(!s->budget--) { s->failed_pc=0x0c059d4cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c059d4e;
P_0c059d4e: /* original e202, guest PC 0x0c059d4e */
if(!s->budget--) { s->failed_pc=0x0c059d4eu; return 0; }
r[2]=0x00000002u;
goto P_0c059d50;
P_0c059d50: /* original 4108, guest PC 0x0c059d50 */
if(!s->budget--) { s->failed_pc=0x0c059d50u; return 0; }
r[1]<<=2;
goto P_0c059d52;
P_0c059d52: /* original 0126, guest PC 0x0c059d52 */
if(!s->budget--) { s->failed_pc=0x0c059d52u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c059d54;
P_0c059d54: /* original d121, guest PC 0x0c059d54 */
if(!s->budget--) { s->failed_pc=0x0c059d54u; return 0; }
r[1]=read(ram,0x0c059ddcu,4);
goto P_0c059d56;
P_0c059d56: /* original 21d2, guest PC 0x0c059d56 */
if(!s->budget--) { s->failed_pc=0x0c059d56u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c059d58;
P_0c059d58: /* original 7320, guest PC 0x0c059d58 */
if(!s->budget--) { s->failed_pc=0x0c059d58u; return 0; }
r[3]+=0x00000020u;
goto P_0c059d5a;
P_0c059d5a: /* original 23d2, guest PC 0x0c059d5a */
if(!s->budget--) { s->failed_pc=0x0c059d5au; return 0; }
write(ram,r[3],r[13],4);
goto P_0c059d5c;
P_0c059d5c: /* original e000, guest PC 0x0c059d5c */
if(!s->budget--) { s->failed_pc=0x0c059d5cu; return 0; }
r[0]=0x00000000u;
goto P_0c059d5e;
P_0c059d5e: /* original 7f08, guest PC 0x0c059d5e */
if(!s->budget--) { s->failed_pc=0x0c059d5eu; return 0; }
r[15]+=0x00000008u;
goto P_0c059d60;
P_0c059d60: /* original 4f26, guest PC 0x0c059d60 */
if(!s->budget--) { s->failed_pc=0x0c059d60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059d62;
P_0c059d62: /* original 68f6, guest PC 0x0c059d62 */
if(!s->budget--) { s->failed_pc=0x0c059d62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c059d64;
P_0c059d64: /* original 69f6, guest PC 0x0c059d64 */
if(!s->budget--) { s->failed_pc=0x0c059d64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c059d66;
P_0c059d66: /* original 6af6, guest PC 0x0c059d66 */
if(!s->budget--) { s->failed_pc=0x0c059d66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c059d68;
P_0c059d68: /* original 6bf6, guest PC 0x0c059d68 */
if(!s->budget--) { s->failed_pc=0x0c059d68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c059d6a;
P_0c059d6a: /* original 6cf6, guest PC 0x0c059d6a */
if(!s->budget--) { s->failed_pc=0x0c059d6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059d6c;
P_0c059d6c: /* original 6df6, guest PC 0x0c059d6c */
if(!s->budget--) { s->failed_pc=0x0c059d6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059d6e;
P_0c059d6e: /* original 000b, guest PC 0x0c059d6e */
if(!s->budget--) { s->failed_pc=0x0c059d6eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059d70: /* original 6ef6, guest PC 0x0c059d70 */
if(!s->budget--) { s->failed_pc=0x0c059d70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c059d72u,s,ram);
P_0c060fd6: /* original 4f22, guest PC 0x0c060fd6 */
if(!s->budget--) { s->failed_pc=0x0c060fd6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060fd8;
P_0c060fd8: /* original da12, guest PC 0x0c060fd8 */
if(!s->budget--) { s->failed_pc=0x0c060fd8u; return 0; }
r[10]=read(ram,0x0c061024u,4);
goto P_0c060fda;
P_0c060fda: /* original db13, guest PC 0x0c060fda */
if(!s->budget--) { s->failed_pc=0x0c060fdau; return 0; }
r[11]=read(ram,0x0c061028u,4);
goto P_0c060fdc;
P_0c060fdc: /* original dc0c, guest PC 0x0c060fdc */
if(!s->budget--) { s->failed_pc=0x0c060fdcu; return 0; }
r[12]=read(ram,0x0c061010u,4);
goto P_0c060fde;
P_0c060fde: /* original dd13, guest PC 0x0c060fde */
if(!s->budget--) { s->failed_pc=0x0c060fdeu; return 0; }
r[13]=read(ram,0x0c06102cu,4);
goto P_0c060fe0;
P_0c060fe0: /* original d813, guest PC 0x0c060fe0 */
if(!s->budget--) { s->failed_pc=0x0c060fe0u; return 0; }
r[8]=read(ram,0x0c061030u,4);
goto P_0c060fe2;
P_0c060fe2: /* original de14, guest PC 0x0c060fe2 */
if(!s->budget--) { s->failed_pc=0x0c060fe2u; return 0; }
r[14]=read(ram,0x0c061034u,4);
goto P_0c060fe4;
P_0c060fe4: /* original d314, guest PC 0x0c060fe4 */
if(!s->budget--) { s->failed_pc=0x0c060fe4u; return 0; }
r[3]=read(ram,0x0c061038u,4);
goto P_0c060fe6;
P_0c060fe6: /* original 6032, guest PC 0x0c060fe6 */
if(!s->budget--) { s->failed_pc=0x0c060fe6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060fe8;
P_0c060fe8: /* original 8801, guest PC 0x0c060fe8 */
if(!s->budget--) { s->failed_pc=0x0c060fe8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060fea;
P_0c060fea: /* original 8f56, guest PC 0x0c060fea */
if(!s->budget--) { s->failed_pc=0x0c060feau; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(!cond) { goto P_0c06109a; }
goto P_0c060fee;
P_0c060fec: /* original e900, guest PC 0x0c060fec */
if(!s->budget--) { s->failed_pc=0x0c060fecu; return 0; }
r[9]=0x00000000u;
goto P_0c060fee;
P_0c060fee: /* original d513, guest PC 0x0c060fee */
if(!s->budget--) { s->failed_pc=0x0c060feeu; return 0; }
r[5]=read(ram,0x0c06103cu,4);
goto P_0c060ff0;
P_0c060ff0: /* original d413, guest PC 0x0c060ff0 */
if(!s->budget--) { s->failed_pc=0x0c060ff0u; return 0; }
r[4]=read(ram,0x0c061040u,4);
goto P_0c060ff2;
P_0c060ff2: /* original d114, guest PC 0x0c060ff2 */
if(!s->budget--) { s->failed_pc=0x0c060ff2u; return 0; }
r[1]=read(ram,0x0c061044u,4);
goto P_0c060ff4;
P_0c060ff4: /* original 410b, guest PC 0x0c060ff4 */
if(!s->budget--) { s->failed_pc=0x0c060ff4u; return 0; }
target=r[1];
r[16]=code_base|0x0c060ff8u;
r[6]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060ff8u) { target=s->pc; goto dispatch; }
goto P_0c060ff8;
P_0c060ff6: /* original e600, guest PC 0x0c060ff6 */
if(!s->budget--) { s->failed_pc=0x0c060ff6u; return 0; }
r[6]=0x00000000u;
goto P_0c060ff8;
P_0c060ff8: /* original 8801, guest PC 0x0c060ff8 */
if(!s->budget--) { s->failed_pc=0x0c060ff8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060ffa;
P_0c060ffa: /* original 8b2b, guest PC 0x0c060ffa */
if(!s->budget--) { s->failed_pc=0x0c060ffau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061054; }
goto P_0c060ffc;
P_0c060ffc: /* original d212, guest PC 0x0c060ffc */
if(!s->budget--) { s->failed_pc=0x0c060ffcu; return 0; }
r[2]=read(ram,0x0c061048u,4);
goto P_0c060ffe;
P_0c060ffe: /* original 2282, guest PC 0x0c060ffe */
if(!s->budget--) { s->failed_pc=0x0c060ffeu; return 0; }
write(ram,r[2],r[8],4);
goto P_0c061000;
P_0c061000: /* original d312, guest PC 0x0c061000 */
if(!s->budget--) { s->failed_pc=0x0c061000u; return 0; }
r[3]=read(ram,0x0c06104cu,4);
goto P_0c061002;
P_0c061002: /* original 2382, guest PC 0x0c061002 */
if(!s->budget--) { s->failed_pc=0x0c061002u; return 0; }
write(ram,r[3],r[8],4);
goto P_0c061004;
P_0c061004: /* original 2a92, guest PC 0x0c061004 */
if(!s->budget--) { s->failed_pc=0x0c061004u; return 0; }
write(ram,r[10],r[9],4);
goto P_0c061006;
P_0c061006: /* original 2d82, guest PC 0x0c061006 */
if(!s->budget--) { s->failed_pc=0x0c061006u; return 0; }
write(ram,r[13],r[8],4);
goto P_0c061008;
P_0c061008: /* original d111, guest PC 0x0c061008 */
if(!s->budget--) { s->failed_pc=0x0c061008u; return 0; }
r[1]=read(ram,0x0c061050u,4);
goto P_0c06100a;
P_0c06100a: /* original a02b, guest PC 0x0c06100a */
if(!s->budget--) { s->failed_pc=0x0c06100au; return 0; }
write(ram,r[1],r[8],4);
goto P_0c061064;
P_0c06100c: /* original 2182, guest PC 0x0c06100c */
if(!s->budget--) { s->failed_pc=0x0c06100cu; return 0; }
write(ram,r[1],r[8],4);
return vf3_matrix_family(0x0c06100eu,s,ram);
P_0c061054: /* original d23b, guest PC 0x0c061054 */
if(!s->budget--) { s->failed_pc=0x0c061054u; return 0; }
r[2]=read(ram,0x0c061144u,4);
goto P_0c061056;
P_0c061056: /* original 22e2, guest PC 0x0c061056 */
if(!s->budget--) { s->failed_pc=0x0c061056u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c061058;
P_0c061058: /* original d33b, guest PC 0x0c061058 */
if(!s->budget--) { s->failed_pc=0x0c061058u; return 0; }
r[3]=read(ram,0x0c061148u,4);
goto P_0c06105a;
P_0c06105a: /* original 23e2, guest PC 0x0c06105a */
if(!s->budget--) { s->failed_pc=0x0c06105au; return 0; }
write(ram,r[3],r[14],4);
goto P_0c06105c;
P_0c06105c: /* original 2a92, guest PC 0x0c06105c */
if(!s->budget--) { s->failed_pc=0x0c06105cu; return 0; }
write(ram,r[10],r[9],4);
goto P_0c06105e;
P_0c06105e: /* original 2de2, guest PC 0x0c06105e */
if(!s->budget--) { s->failed_pc=0x0c06105eu; return 0; }
write(ram,r[13],r[14],4);
goto P_0c061060;
P_0c061060: /* original d13a, guest PC 0x0c061060 */
if(!s->budget--) { s->failed_pc=0x0c061060u; return 0; }
r[1]=read(ram,0x0c06114cu,4);
goto P_0c061062;
P_0c061062: /* original 21e2, guest PC 0x0c061062 */
if(!s->budget--) { s->failed_pc=0x0c061062u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c061064;
P_0c061064: /* original 2b92, guest PC 0x0c061064 */
if(!s->budget--) { s->failed_pc=0x0c061064u; return 0; }
write(ram,r[11],r[9],4);
goto P_0c061066;
P_0c061066: /* original 946c, guest PC 0x0c061066 */
if(!s->budget--) { s->failed_pc=0x0c061066u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061142u,2);
goto P_0c061068;
P_0c061068: /* original d339, guest PC 0x0c061068 */
if(!s->budget--) { s->failed_pc=0x0c061068u; return 0; }
r[3]=read(ram,0x0c061150u,4);
goto P_0c06106a;
P_0c06106a: /* original 430b, guest PC 0x0c06106a */
if(!s->budget--) { s->failed_pc=0x0c06106au; return 0; }
target=r[3];
r[16]=code_base|0x0c06106eu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06106eu) { target=s->pc; goto dispatch; }
goto P_0c06106e;
P_0c06106c: /* original e500, guest PC 0x0c06106c */
if(!s->budget--) { s->failed_pc=0x0c06106cu; return 0; }
r[5]=0x00000000u;
goto P_0c06106e;
P_0c06106e: /* original bf5b, guest PC 0x0c06106e */
if(!s->budget--) { s->failed_pc=0x0c06106eu; return 0; }
target=0x0c060f28u; r[16]=code_base|0x0c061072u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061072u) { target=s->pc; goto dispatch; }
goto P_0c061072;
P_0c061070: /* original 0009, guest PC 0x0c061070 */
if(!s->budget--) { s->failed_pc=0x0c061070u; return 0; }
goto P_0c061072;
P_0c061072: /* original 63d2, guest PC 0x0c061072 */
if(!s->budget--) { s->failed_pc=0x0c061072u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c061074;
P_0c061074: /* original 1c34, guest PC 0x0c061074 */
if(!s->budget--) { s->failed_pc=0x0c061074u; return 0; }
write(ram,r[12]+16,r[3],4);
goto P_0c061076;
P_0c061076: /* original 62b2, guest PC 0x0c061076 */
if(!s->budget--) { s->failed_pc=0x0c061076u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c061078;
P_0c061078: /* original d336, guest PC 0x0c061078 */
if(!s->budget--) { s->failed_pc=0x0c061078u; return 0; }
r[3]=read(ram,0x0c061154u,4);
goto P_0c06107a;
P_0c06107a: /* original 430b, guest PC 0x0c06107a */
if(!s->budget--) { s->failed_pc=0x0c06107au; return 0; }
target=r[3];
r[16]=code_base|0x0c06107eu;
write(ram,r[12]+36,r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06107eu) { target=s->pc; goto dispatch; }
goto P_0c06107e;
P_0c06107c: /* original 1c29, guest PC 0x0c06107c */
if(!s->budget--) { s->failed_pc=0x0c06107cu; return 0; }
write(ram,r[12]+36,r[2],4);
goto P_0c06107e;
P_0c06107e: /* original 6403, guest PC 0x0c06107e */
if(!s->budget--) { s->failed_pc=0x0c06107eu; return 0; }
r[4]=r[0];
goto P_0c061080;
P_0c061080: /* original 2448, guest PC 0x0c061080 */
if(!s->budget--) { s->failed_pc=0x0c061080u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061082;
P_0c061082: /* original 8945, guest PC 0x0c061082 */
if(!s->budget--) { s->failed_pc=0x0c061082u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061110; }
goto P_0c061084;
P_0c061084: /* original 63a2, guest PC 0x0c061084 */
if(!s->budget--) { s->failed_pc=0x0c061084u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c061086;
P_0c061086: /* original 65c3, guest PC 0x0c061086 */
if(!s->budget--) { s->failed_pc=0x0c061086u; return 0; }
r[5]=r[12];
goto P_0c061088;
P_0c061088: /* original 1433, guest PC 0x0c061088 */
if(!s->budget--) { s->failed_pc=0x0c061088u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c06108a;
P_0c06108a: /* original 62d2, guest PC 0x0c06108a */
if(!s->budget--) { s->failed_pc=0x0c06108au; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c06108c;
P_0c06108c: /* original 1424, guest PC 0x0c06108c */
if(!s->budget--) { s->failed_pc=0x0c06108cu; return 0; }
write(ram,r[4]+16,r[2],4);
goto P_0c06108e;
P_0c06108e: /* original 5352, guest PC 0x0c06108e */
if(!s->budget--) { s->failed_pc=0x0c06108eu; return 0; }
r[3]=read(ram,r[5]+8,4);
goto P_0c061090;
P_0c061090: /* original 1432, guest PC 0x0c061090 */
if(!s->budget--) { s->failed_pc=0x0c061090u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c061092;
P_0c061092: /* original 1542, guest PC 0x0c061092 */
if(!s->budget--) { s->failed_pc=0x0c061092u; return 0; }
write(ram,r[5]+8,r[4],4);
goto P_0c061094;
P_0c061094: /* original 5253, guest PC 0x0c061094 */
if(!s->budget--) { s->failed_pc=0x0c061094u; return 0; }
r[2]=read(ram,r[5]+12,4);
goto P_0c061096;
P_0c061096: /* original a049, guest PC 0x0c061096 */
if(!s->budget--) { s->failed_pc=0x0c061096u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c06112c;
P_0c061098: /* original 1421, guest PC 0x0c061098 */
if(!s->budget--) { s->failed_pc=0x0c061098u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c06109a;
P_0c06109a: /* original d52f, guest PC 0x0c06109a */
if(!s->budget--) { s->failed_pc=0x0c06109au; return 0; }
r[5]=read(ram,0x0c061158u,4);
goto P_0c06109c;
P_0c06109c: /* original d42f, guest PC 0x0c06109c */
if(!s->budget--) { s->failed_pc=0x0c06109cu; return 0; }
r[4]=read(ram,0x0c06115cu,4);
goto P_0c06109e;
P_0c06109e: /* original d230, guest PC 0x0c06109e */
if(!s->budget--) { s->failed_pc=0x0c06109eu; return 0; }
r[2]=read(ram,0x0c061160u,4);
goto P_0c0610a0;
P_0c0610a0: /* original 420b, guest PC 0x0c0610a0 */
if(!s->budget--) { s->failed_pc=0x0c0610a0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0610a4u;
r[6]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0610a4u) { target=s->pc; goto dispatch; }
goto P_0c0610a4;
P_0c0610a2: /* original e600, guest PC 0x0c0610a2 */
if(!s->budget--) { s->failed_pc=0x0c0610a2u; return 0; }
r[6]=0x00000000u;
goto P_0c0610a4;
P_0c0610a4: /* original 8801, guest PC 0x0c0610a4 */
if(!s->budget--) { s->failed_pc=0x0c0610a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0610a6;
P_0c0610a6: /* original 8f0a, guest PC 0x0c0610a6 */
if(!s->budget--) { s->failed_pc=0x0c0610a6u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c0610be; }
goto P_0c0610aa;
P_0c0610a8: /* original e500, guest PC 0x0c0610a8 */
if(!s->budget--) { s->failed_pc=0x0c0610a8u; return 0; }
r[5]=0x00000000u;
goto P_0c0610aa;
P_0c0610aa: /* original d226, guest PC 0x0c0610aa */
if(!s->budget--) { s->failed_pc=0x0c0610aau; return 0; }
r[2]=read(ram,0x0c061144u,4);
goto P_0c0610ac;
P_0c0610ac: /* original 2282, guest PC 0x0c0610ac */
if(!s->budget--) { s->failed_pc=0x0c0610acu; return 0; }
write(ram,r[2],r[8],4);
goto P_0c0610ae;
P_0c0610ae: /* original d326, guest PC 0x0c0610ae */
if(!s->budget--) { s->failed_pc=0x0c0610aeu; return 0; }
r[3]=read(ram,0x0c061148u,4);
goto P_0c0610b0;
P_0c0610b0: /* original d126, guest PC 0x0c0610b0 */
if(!s->budget--) { s->failed_pc=0x0c0610b0u; return 0; }
r[1]=read(ram,0x0c06114cu,4);
goto P_0c0610b2;
P_0c0610b2: /* original 23e2, guest PC 0x0c0610b2 */
if(!s->budget--) { s->failed_pc=0x0c0610b2u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c0610b4;
P_0c0610b4: /* original 2a92, guest PC 0x0c0610b4 */
if(!s->budget--) { s->failed_pc=0x0c0610b4u; return 0; }
write(ram,r[10],r[9],4);
goto P_0c0610b6;
P_0c0610b6: /* original 2de2, guest PC 0x0c0610b6 */
if(!s->budget--) { s->failed_pc=0x0c0610b6u; return 0; }
write(ram,r[13],r[14],4);
goto P_0c0610b8;
P_0c0610b8: /* original 21e2, guest PC 0x0c0610b8 */
if(!s->budget--) { s->failed_pc=0x0c0610b8u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c0610ba;
P_0c0610ba: /* original a00a, guest PC 0x0c0610ba */
if(!s->budget--) { s->failed_pc=0x0c0610bau; return 0; }
write(ram,r[11],r[14],4);
goto P_0c0610d2;
P_0c0610bc: /* original 2be2, guest PC 0x0c0610bc */
if(!s->budget--) { s->failed_pc=0x0c0610bcu; return 0; }
write(ram,r[11],r[14],4);
goto P_0c0610be;
P_0c0610be: /* original d221, guest PC 0x0c0610be */
if(!s->budget--) { s->failed_pc=0x0c0610beu; return 0; }
r[2]=read(ram,0x0c061144u,4);
goto P_0c0610c0;
P_0c0610c0: /* original 22e2, guest PC 0x0c0610c0 */
if(!s->budget--) { s->failed_pc=0x0c0610c0u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c0610c2;
P_0c0610c2: /* original d428, guest PC 0x0c0610c2 */
if(!s->budget--) { s->failed_pc=0x0c0610c2u; return 0; }
r[4]=read(ram,0x0c061164u,4);
goto P_0c0610c4;
P_0c0610c4: /* original d320, guest PC 0x0c0610c4 */
if(!s->budget--) { s->failed_pc=0x0c0610c4u; return 0; }
r[3]=read(ram,0x0c061148u,4);
goto P_0c0610c6;
P_0c0610c6: /* original 2342, guest PC 0x0c0610c6 */
if(!s->budget--) { s->failed_pc=0x0c0610c6u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0610c8;
P_0c0610c8: /* original 2a92, guest PC 0x0c0610c8 */
if(!s->budget--) { s->failed_pc=0x0c0610c8u; return 0; }
write(ram,r[10],r[9],4);
goto P_0c0610ca;
P_0c0610ca: /* original 2d42, guest PC 0x0c0610ca */
if(!s->budget--) { s->failed_pc=0x0c0610cau; return 0; }
write(ram,r[13],r[4],4);
goto P_0c0610cc;
P_0c0610cc: /* original d11f, guest PC 0x0c0610cc */
if(!s->budget--) { s->failed_pc=0x0c0610ccu; return 0; }
r[1]=read(ram,0x0c06114cu,4);
goto P_0c0610ce;
P_0c0610ce: /* original 2142, guest PC 0x0c0610ce */
if(!s->budget--) { s->failed_pc=0x0c0610ceu; return 0; }
write(ram,r[1],r[4],4);
goto P_0c0610d0;
P_0c0610d0: /* original 2b42, guest PC 0x0c0610d0 */
if(!s->budget--) { s->failed_pc=0x0c0610d0u; return 0; }
write(ram,r[11],r[4],4);
goto P_0c0610d2;
P_0c0610d2: /* original 9436, guest PC 0x0c0610d2 */
if(!s->budget--) { s->failed_pc=0x0c0610d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061142u,2);
goto P_0c0610d4;
P_0c0610d4: /* original d31e, guest PC 0x0c0610d4 */
if(!s->budget--) { s->failed_pc=0x0c0610d4u; return 0; }
r[3]=read(ram,0x0c061150u,4);
goto P_0c0610d6;
P_0c0610d6: /* original 430b, guest PC 0x0c0610d6 */
if(!s->budget--) { s->failed_pc=0x0c0610d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0610dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0610dau) { target=s->pc; goto dispatch; }
goto P_0c0610da;
P_0c0610d8: /* original 0009, guest PC 0x0c0610d8 */
if(!s->budget--) { s->failed_pc=0x0c0610d8u; return 0; }
goto P_0c0610da;
P_0c0610da: /* original bf25, guest PC 0x0c0610da */
if(!s->budget--) { s->failed_pc=0x0c0610dau; return 0; }
target=0x0c060f28u; r[16]=code_base|0x0c0610deu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0610deu) { target=s->pc; goto dispatch; }
goto P_0c0610de;
P_0c0610dc: /* original 0009, guest PC 0x0c0610dc */
if(!s->budget--) { s->failed_pc=0x0c0610dcu; return 0; }
goto P_0c0610de;
P_0c0610de: /* original 63d2, guest PC 0x0c0610de */
if(!s->budget--) { s->failed_pc=0x0c0610deu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0610e0;
P_0c0610e0: /* original 1c34, guest PC 0x0c0610e0 */
if(!s->budget--) { s->failed_pc=0x0c0610e0u; return 0; }
write(ram,r[12]+16,r[3],4);
goto P_0c0610e2;
P_0c0610e2: /* original 62b2, guest PC 0x0c0610e2 */
if(!s->budget--) { s->failed_pc=0x0c0610e2u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0610e4;
P_0c0610e4: /* original d31b, guest PC 0x0c0610e4 */
if(!s->budget--) { s->failed_pc=0x0c0610e4u; return 0; }
r[3]=read(ram,0x0c061154u,4);
goto P_0c0610e6;
P_0c0610e6: /* original 430b, guest PC 0x0c0610e6 */
if(!s->budget--) { s->failed_pc=0x0c0610e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0610eau;
write(ram,r[12]+36,r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0610eau) { target=s->pc; goto dispatch; }
goto P_0c0610ea;
P_0c0610e8: /* original 1c29, guest PC 0x0c0610e8 */
if(!s->budget--) { s->failed_pc=0x0c0610e8u; return 0; }
write(ram,r[12]+36,r[2],4);
goto P_0c0610ea;
P_0c0610ea: /* original 6403, guest PC 0x0c0610ea */
if(!s->budget--) { s->failed_pc=0x0c0610eau; return 0; }
r[4]=r[0];
goto P_0c0610ec;
P_0c0610ec: /* original 2448, guest PC 0x0c0610ec */
if(!s->budget--) { s->failed_pc=0x0c0610ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0610ee;
P_0c0610ee: /* original 890f, guest PC 0x0c0610ee */
if(!s->budget--) { s->failed_pc=0x0c0610eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061110; }
goto P_0c0610f0;
P_0c0610f0: /* original 62a2, guest PC 0x0c0610f0 */
if(!s->budget--) { s->failed_pc=0x0c0610f0u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0610f2;
P_0c0610f2: /* original 65c3, guest PC 0x0c0610f2 */
if(!s->budget--) { s->failed_pc=0x0c0610f2u; return 0; }
r[5]=r[12];
goto P_0c0610f4;
P_0c0610f4: /* original 1423, guest PC 0x0c0610f4 */
if(!s->budget--) { s->failed_pc=0x0c0610f4u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0610f6;
P_0c0610f6: /* original 63d2, guest PC 0x0c0610f6 */
if(!s->budget--) { s->failed_pc=0x0c0610f6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0610f8;
P_0c0610f8: /* original 1434, guest PC 0x0c0610f8 */
if(!s->budget--) { s->failed_pc=0x0c0610f8u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0610fa;
P_0c0610fa: /* original 5252, guest PC 0x0c0610fa */
if(!s->budget--) { s->failed_pc=0x0c0610fau; return 0; }
r[2]=read(ram,r[5]+8,4);
goto P_0c0610fc;
P_0c0610fc: /* original 1422, guest PC 0x0c0610fc */
if(!s->budget--) { s->failed_pc=0x0c0610fcu; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c0610fe;
P_0c0610fe: /* original 1542, guest PC 0x0c0610fe */
if(!s->budget--) { s->failed_pc=0x0c0610feu; return 0; }
write(ram,r[5]+8,r[4],4);
goto P_0c061100;
P_0c061100: /* original 5353, guest PC 0x0c061100 */
if(!s->budget--) { s->failed_pc=0x0c061100u; return 0; }
r[3]=read(ram,r[5]+12,4);
goto P_0c061102;
P_0c061102: /* original 1431, guest PC 0x0c061102 */
if(!s->budget--) { s->failed_pc=0x0c061102u; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c061104;
P_0c061104: /* original d213, guest PC 0x0c061104 */
if(!s->budget--) { s->failed_pc=0x0c061104u; return 0; }
r[2]=read(ram,0x0c061154u,4);
goto P_0c061106;
P_0c061106: /* original 420b, guest PC 0x0c061106 */
if(!s->budget--) { s->failed_pc=0x0c061106u; return 0; }
target=r[2];
r[16]=code_base|0x0c06110au;
write(ram,r[5]+12,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06110au) { target=s->pc; goto dispatch; }
goto P_0c06110a;
P_0c061108: /* original 1543, guest PC 0x0c061108 */
if(!s->budget--) { s->failed_pc=0x0c061108u; return 0; }
write(ram,r[5]+12,r[4],4);
goto P_0c06110a;
P_0c06110a: /* original 6403, guest PC 0x0c06110a */
if(!s->budget--) { s->failed_pc=0x0c06110au; return 0; }
r[4]=r[0];
goto P_0c06110c;
P_0c06110c: /* original 2448, guest PC 0x0c06110c */
if(!s->budget--) { s->failed_pc=0x0c06110cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06110e;
P_0c06110e: /* original 8b01, guest PC 0x0c06110e */
if(!s->budget--) { s->failed_pc=0x0c06110eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061114; }
goto P_0c061110;
P_0c061110: /* original a00e, guest PC 0x0c061110 */
if(!s->budget--) { s->failed_pc=0x0c061110u; return 0; }
r[0]=0x00000003u;
goto P_0c061130;
P_0c061112: /* original e003, guest PC 0x0c061112 */
if(!s->budget--) { s->failed_pc=0x0c061112u; return 0; }
r[0]=0x00000003u;
goto P_0c061114;
P_0c061114: /* original d30d, guest PC 0x0c061114 */
if(!s->budget--) { s->failed_pc=0x0c061114u; return 0; }
r[3]=read(ram,0x0c06114cu,4);
goto P_0c061116;
P_0c061116: /* original 65c3, guest PC 0x0c061116 */
if(!s->budget--) { s->failed_pc=0x0c061116u; return 0; }
r[5]=r[12];
goto P_0c061118;
P_0c061118: /* original 6232, guest PC 0x0c061118 */
if(!s->budget--) { s->failed_pc=0x0c061118u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c06111a;
P_0c06111a: /* original 7514, guest PC 0x0c06111a */
if(!s->budget--) { s->failed_pc=0x0c06111au; return 0; }
r[5]+=0x00000014u;
goto P_0c06111c;
P_0c06111c: /* original 1423, guest PC 0x0c06111c */
if(!s->budget--) { s->failed_pc=0x0c06111cu; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c06111e;
P_0c06111e: /* original 61b2, guest PC 0x0c06111e */
if(!s->budget--) { s->failed_pc=0x0c06111eu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c061120;
P_0c061120: /* original 1414, guest PC 0x0c061120 */
if(!s->budget--) { s->failed_pc=0x0c061120u; return 0; }
write(ram,r[4]+16,r[1],4);
goto P_0c061122;
P_0c061122: /* original 5252, guest PC 0x0c061122 */
if(!s->budget--) { s->failed_pc=0x0c061122u; return 0; }
r[2]=read(ram,r[5]+8,4);
goto P_0c061124;
P_0c061124: /* original 1422, guest PC 0x0c061124 */
if(!s->budget--) { s->failed_pc=0x0c061124u; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c061126;
P_0c061126: /* original 1542, guest PC 0x0c061126 */
if(!s->budget--) { s->failed_pc=0x0c061126u; return 0; }
write(ram,r[5]+8,r[4],4);
goto P_0c061128;
P_0c061128: /* original 5153, guest PC 0x0c061128 */
if(!s->budget--) { s->failed_pc=0x0c061128u; return 0; }
r[1]=read(ram,r[5]+12,4);
goto P_0c06112a;
P_0c06112a: /* original 1411, guest PC 0x0c06112a */
if(!s->budget--) { s->failed_pc=0x0c06112au; return 0; }
write(ram,r[4]+4,r[1],4);
goto P_0c06112c;
P_0c06112c: /* original 1543, guest PC 0x0c06112c */
if(!s->budget--) { s->failed_pc=0x0c06112cu; return 0; }
write(ram,r[5]+12,r[4],4);
goto P_0c06112e;
P_0c06112e: /* original e000, guest PC 0x0c06112e */
if(!s->budget--) { s->failed_pc=0x0c06112eu; return 0; }
r[0]=0x00000000u;
goto P_0c061130;
P_0c061130: /* original 4f26, guest PC 0x0c061130 */
if(!s->budget--) { s->failed_pc=0x0c061130u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c061132;
P_0c061132: /* original 68f6, guest PC 0x0c061132 */
if(!s->budget--) { s->failed_pc=0x0c061132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c061134;
P_0c061134: /* original 69f6, guest PC 0x0c061134 */
if(!s->budget--) { s->failed_pc=0x0c061134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c061136;
P_0c061136: /* original 6af6, guest PC 0x0c061136 */
if(!s->budget--) { s->failed_pc=0x0c061136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c061138;
P_0c061138: /* original 6bf6, guest PC 0x0c061138 */
if(!s->budget--) { s->failed_pc=0x0c061138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06113a;
P_0c06113a: /* original 6cf6, guest PC 0x0c06113a */
if(!s->budget--) { s->failed_pc=0x0c06113au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06113c;
P_0c06113c: /* original 6df6, guest PC 0x0c06113c */
if(!s->budget--) { s->failed_pc=0x0c06113cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06113e;
P_0c06113e: /* original 000b, guest PC 0x0c06113e */
if(!s->budget--) { s->failed_pc=0x0c06113eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061140: /* original 6ef6, guest PC 0x0c061140 */
if(!s->budget--) { s->failed_pc=0x0c061140u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c061142u,s,ram);
P_0c063446: /* original 4f22, guest PC 0x0c063446 */
if(!s->budget--) { s->failed_pc=0x0c063446u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c063448;
P_0c063448: /* original dc2a, guest PC 0x0c063448 */
if(!s->budget--) { s->failed_pc=0x0c063448u; return 0; }
r[12]=read(ram,0x0c0634f4u,4);
goto P_0c06344a;
P_0c06344a: /* original 7ff8, guest PC 0x0c06344a */
if(!s->budget--) { s->failed_pc=0x0c06344au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06344c;
P_0c06344c: /* original 2232, guest PC 0x0c06344c */
if(!s->budget--) { s->failed_pc=0x0c06344cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06344e;
P_0c06344e: /* original 6433, guest PC 0x0c06344e */
if(!s->budget--) { s->failed_pc=0x0c06344eu; return 0; }
r[4]=r[3];
goto P_0c063450;
P_0c063450: /* original d32a, guest PC 0x0c063450 */
if(!s->budget--) { s->failed_pc=0x0c063450u; return 0; }
r[3]=read(ram,0x0c0634fcu,4);
goto P_0c063452;
P_0c063452: /* original 430b, guest PC 0x0c063452 */
if(!s->budget--) { s->failed_pc=0x0c063452u; return 0; }
target=r[3];
r[16]=code_base|0x0c063456u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063456u) { target=s->pc; goto dispatch; }
goto P_0c063456;
P_0c063454: /* original 0009, guest PC 0x0c063454 */
if(!s->budget--) { s->failed_pc=0x0c063454u; return 0; }
goto P_0c063456;
P_0c063456: /* original 1f01, guest PC 0x0c063456 */
if(!s->budget--) { s->failed_pc=0x0c063456u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c063458;
P_0c063458: /* original d328, guest PC 0x0c063458 */
if(!s->budget--) { s->failed_pc=0x0c063458u; return 0; }
r[3]=read(ram,0x0c0634fcu,4);
goto P_0c06345a;
P_0c06345a: /* original 430b, guest PC 0x0c06345a */
if(!s->budget--) { s->failed_pc=0x0c06345au; return 0; }
target=r[3];
r[16]=code_base|0x0c06345eu;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06345eu) { target=s->pc; goto dispatch; }
goto P_0c06345e;
P_0c06345c: /* original e404, guest PC 0x0c06345c */
if(!s->budget--) { s->failed_pc=0x0c06345cu; return 0; }
r[4]=0x00000004u;
goto P_0c06345e;
P_0c06345e: /* original 6403, guest PC 0x0c06345e */
if(!s->budget--) { s->failed_pc=0x0c06345eu; return 0; }
r[4]=r[0];
goto P_0c063460;
P_0c063460: /* original d227, guest PC 0x0c063460 */
if(!s->budget--) { s->failed_pc=0x0c063460u; return 0; }
r[2]=read(ram,0x0c063500u,4);
goto P_0c063462;
P_0c063462: /* original e505, guest PC 0x0c063462 */
if(!s->budget--) { s->failed_pc=0x0c063462u; return 0; }
r[5]=0x00000005u;
goto P_0c063464;
P_0c063464: /* original 2252, guest PC 0x0c063464 */
if(!s->budget--) { s->failed_pc=0x0c063464u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c063466;
P_0c063466: /* original d327, guest PC 0x0c063466 */
if(!s->budget--) { s->failed_pc=0x0c063466u; return 0; }
r[3]=read(ram,0x0c063504u,4);
goto P_0c063468;
P_0c063468: /* original 51f1, guest PC 0x0c063468 */
if(!s->budget--) { s->failed_pc=0x0c063468u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06346a;
P_0c06346a: /* original 3130, guest PC 0x0c06346a */
if(!s->budget--) { s->failed_pc=0x0c06346au; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c06346c;
P_0c06346c: /* original 8b03, guest PC 0x0c06346c */
if(!s->budget--) { s->failed_pc=0x0c06346cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063476; }
goto P_0c06346e;
P_0c06346e: /* original 6043, guest PC 0x0c06346e */
if(!s->budget--) { s->failed_pc=0x0c06346eu; return 0; }
r[0]=r[4];
goto P_0c063470;
P_0c063470: /* original 0009, guest PC 0x0c063470 */
if(!s->budget--) { s->failed_pc=0x0c063470u; return 0; }
goto P_0c063472;
P_0c063472: /* original 8801, guest PC 0x0c063472 */
if(!s->budget--) { s->failed_pc=0x0c063472u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c063474;
P_0c063474: /* original 8b02, guest PC 0x0c063474 */
if(!s->budget--) { s->failed_pc=0x0c063474u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06347c; }
goto P_0c063476;
P_0c063476: /* original d322, guest PC 0x0c063476 */
if(!s->budget--) { s->failed_pc=0x0c063476u; return 0; }
r[3]=read(ram,0x0c063500u,4);
goto P_0c063478;
P_0c063478: /* original a00a, guest PC 0x0c063478 */
if(!s->budget--) { s->failed_pc=0x0c063478u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c063490;
P_0c06347a: /* original 2352, guest PC 0x0c06347a */
if(!s->budget--) { s->failed_pc=0x0c06347au; return 0; }
write(ram,r[3],r[5],4);
goto P_0c06347c;
P_0c06347c: /* original e111, guest PC 0x0c06347c */
if(!s->budget--) { s->failed_pc=0x0c06347cu; return 0; }
r[1]=0x00000011u;
goto P_0c06347e;
P_0c06347e: /* original 3412, guest PC 0x0c06347e */
if(!s->budget--) { s->failed_pc=0x0c06347eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[1])!=0);
goto P_0c063480;
P_0c063480: /* original 8b06, guest PC 0x0c063480 */
if(!s->budget--) { s->failed_pc=0x0c063480u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063490; }
goto P_0c063482;
P_0c063482: /* original e006, guest PC 0x0c063482 */
if(!s->budget--) { s->failed_pc=0x0c063482u; return 0; }
r[0]=0x00000006u;
goto P_0c063484;
P_0c063484: /* original d21e, guest PC 0x0c063484 */
if(!s->budget--) { s->failed_pc=0x0c063484u; return 0; }
r[2]=read(ram,0x0c063500u,4);
goto P_0c063486;
P_0c063486: /* original 2202, guest PC 0x0c063486 */
if(!s->budget--) { s->failed_pc=0x0c063486u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c063488;
P_0c063488: /* original d31f, guest PC 0x0c063488 */
if(!s->budget--) { s->failed_pc=0x0c063488u; return 0; }
r[3]=read(ram,0x0c063508u,4);
goto P_0c06348a;
P_0c06348a: /* original d01b, guest PC 0x0c06348a */
if(!s->budget--) { s->failed_pc=0x0c06348au; return 0; }
r[0]=read(ram,0x0c0634f8u,4);
goto P_0c06348c;
P_0c06348c: /* original 2032, guest PC 0x0c06348c */
if(!s->budget--) { s->failed_pc=0x0c06348cu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c06348e;
P_0c06348e: /* original dc1f, guest PC 0x0c06348e */
if(!s->budget--) { s->failed_pc=0x0c06348eu; return 0; }
r[12]=read(ram,0x0c06350cu,4);
goto P_0c063490;
P_0c063490: /* original d31f, guest PC 0x0c063490 */
if(!s->budget--) { s->failed_pc=0x0c063490u; return 0; }
r[3]=read(ram,0x0c063510u,4);
goto P_0c063492;
P_0c063492: /* original e56f, guest PC 0x0c063492 */
if(!s->budget--) { s->failed_pc=0x0c063492u; return 0; }
r[5]=0x0000006fu;
goto P_0c063494;
P_0c063494: /* original 6632, guest PC 0x0c063494 */
if(!s->budget--) { s->failed_pc=0x0c063494u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c063496;
P_0c063496: /* original 6063, guest PC 0x0c063496 */
if(!s->budget--) { s->failed_pc=0x0c063496u; return 0; }
r[0]=r[6];
goto P_0c063498;
P_0c063498: /* original 0009, guest PC 0x0c063498 */
if(!s->budget--) { s->failed_pc=0x0c063498u; return 0; }
goto P_0c06349a;
P_0c06349a: /* original 8800, guest PC 0x0c06349a */
if(!s->budget--) { s->failed_pc=0x0c06349au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c06349c;
P_0c06349c: /* original 8d10, guest PC 0x0c06349c */
if(!s->budget--) { s->failed_pc=0x0c06349cu; return 0; }
cond=r[17]&1u;
r[4]=0x0000007fu;
if(cond) { goto P_0c0634c0; }
goto P_0c0634a0;
P_0c06349e: /* original e47f, guest PC 0x0c06349e */
if(!s->budget--) { s->failed_pc=0x0c06349eu; return 0; }
r[4]=0x0000007fu;
goto P_0c0634a0;
P_0c0634a0: /* original 8801, guest PC 0x0c0634a0 */
if(!s->budget--) { s->failed_pc=0x0c0634a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0634a2;
P_0c0634a2: /* original 8911, guest PC 0x0c0634a2 */
if(!s->budget--) { s->failed_pc=0x0c0634a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634c8; }
goto P_0c0634a4;
P_0c0634a4: /* original 8802, guest PC 0x0c0634a4 */
if(!s->budget--) { s->failed_pc=0x0c0634a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0634a6;
P_0c0634a6: /* original 8914, guest PC 0x0c0634a6 */
if(!s->budget--) { s->failed_pc=0x0c0634a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634d2; }
goto P_0c0634a8;
P_0c0634a8: /* original 8804, guest PC 0x0c0634a8 */
if(!s->budget--) { s->failed_pc=0x0c0634a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0634aa;
P_0c0634aa: /* original 8916, guest PC 0x0c0634aa */
if(!s->budget--) { s->failed_pc=0x0c0634aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634da; }
goto P_0c0634ac;
P_0c0634ac: /* original 8805, guest PC 0x0c0634ac */
if(!s->budget--) { s->failed_pc=0x0c0634acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0634ae;
P_0c0634ae: /* original 8914, guest PC 0x0c0634ae */
if(!s->budget--) { s->failed_pc=0x0c0634aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634da; }
goto P_0c0634b0;
P_0c0634b0: /* original 8806, guest PC 0x0c0634b0 */
if(!s->budget--) { s->failed_pc=0x0c0634b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0634b2;
P_0c0634b2: /* original 8912, guest PC 0x0c0634b2 */
if(!s->budget--) { s->failed_pc=0x0c0634b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634da; }
goto P_0c0634b4;
P_0c0634b4: /* original 8808, guest PC 0x0c0634b4 */
if(!s->budget--) { s->failed_pc=0x0c0634b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0634b6;
P_0c0634b6: /* original 8914, guest PC 0x0c0634b6 */
if(!s->budget--) { s->failed_pc=0x0c0634b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634e2; }
goto P_0c0634b8;
P_0c0634b8: /* original 8809, guest PC 0x0c0634b8 */
if(!s->budget--) { s->failed_pc=0x0c0634b8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0634ba;
P_0c0634ba: /* original 8915, guest PC 0x0c0634ba */
if(!s->budget--) { s->failed_pc=0x0c0634bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634e8; }
goto P_0c0634bc;
P_0c0634bc: /* original a02e, guest PC 0x0c0634bc */
if(!s->budget--) { s->failed_pc=0x0c0634bcu; return 0; }
goto P_0c06351c;
P_0c0634be: /* original 0009, guest PC 0x0c0634be */
if(!s->budget--) { s->failed_pc=0x0c0634beu; return 0; }
goto P_0c0634c0;
P_0c0634c0: /* original d114, guest PC 0x0c0634c0 */
if(!s->budget--) { s->failed_pc=0x0c0634c0u; return 0; }
r[1]=read(ram,0x0c063514u,4);
goto P_0c0634c2;
P_0c0634c2: /* original e200, guest PC 0x0c0634c2 */
if(!s->budget--) { s->failed_pc=0x0c0634c2u; return 0; }
r[2]=0x00000000u;
goto P_0c0634c4;
P_0c0634c4: /* original a003, guest PC 0x0c0634c4 */
if(!s->budget--) { s->failed_pc=0x0c0634c4u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0634ce;
P_0c0634c6: /* original 2122, guest PC 0x0c0634c6 */
if(!s->budget--) { s->failed_pc=0x0c0634c6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0634c8;
P_0c0634c8: /* original d212, guest PC 0x0c0634c8 */
if(!s->budget--) { s->failed_pc=0x0c0634c8u; return 0; }
r[2]=read(ram,0x0c063514u,4);
goto P_0c0634ca;
P_0c0634ca: /* original e001, guest PC 0x0c0634ca */
if(!s->budget--) { s->failed_pc=0x0c0634cau; return 0; }
r[0]=0x00000001u;
goto P_0c0634cc;
P_0c0634cc: /* original 2202, guest PC 0x0c0634cc */
if(!s->budget--) { s->failed_pc=0x0c0634ccu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0634ce;
P_0c0634ce: /* original a028, guest PC 0x0c0634ce */
if(!s->budget--) { s->failed_pc=0x0c0634ceu; return 0; }
r[13]=0x00000000u;
goto P_0c063522;
P_0c0634d0: /* original ed00, guest PC 0x0c0634d0 */
if(!s->budget--) { s->failed_pc=0x0c0634d0u; return 0; }
r[13]=0x00000000u;
goto P_0c0634d2;
P_0c0634d2: /* original e203, guest PC 0x0c0634d2 */
if(!s->budget--) { s->failed_pc=0x0c0634d2u; return 0; }
r[2]=0x00000003u;
goto P_0c0634d4;
P_0c0634d4: /* original d10f, guest PC 0x0c0634d4 */
if(!s->budget--) { s->failed_pc=0x0c0634d4u; return 0; }
r[1]=read(ram,0x0c063514u,4);
goto P_0c0634d6;
P_0c0634d6: /* original a023, guest PC 0x0c0634d6 */
if(!s->budget--) { s->failed_pc=0x0c0634d6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c063520;
P_0c0634d8: /* original 2122, guest PC 0x0c0634d8 */
if(!s->budget--) { s->failed_pc=0x0c0634d8u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0634da;
P_0c0634da: /* original d00e, guest PC 0x0c0634da */
if(!s->budget--) { s->failed_pc=0x0c0634dau; return 0; }
r[0]=read(ram,0x0c063514u,4);
goto P_0c0634dc;
P_0c0634dc: /* original dd0e, guest PC 0x0c0634dc */
if(!s->budget--) { s->failed_pc=0x0c0634dcu; return 0; }
r[13]=read(ram,0x0c063518u,4);
goto P_0c0634de;
P_0c0634de: /* original a020, guest PC 0x0c0634de */
if(!s->budget--) { s->failed_pc=0x0c0634deu; return 0; }
write(ram,r[0],r[4],4);
goto P_0c063522;
P_0c0634e0: /* original 2042, guest PC 0x0c0634e0 */
if(!s->budget--) { s->failed_pc=0x0c0634e0u; return 0; }
write(ram,r[0],r[4],4);
goto P_0c0634e2;
P_0c0634e2: /* original d10c, guest PC 0x0c0634e2 */
if(!s->budget--) { s->failed_pc=0x0c0634e2u; return 0; }
r[1]=read(ram,0x0c063514u,4);
goto P_0c0634e4;
P_0c0634e4: /* original a01c, guest PC 0x0c0634e4 */
if(!s->budget--) { s->failed_pc=0x0c0634e4u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c063520;
P_0c0634e6: /* original 2142, guest PC 0x0c0634e6 */
if(!s->budget--) { s->failed_pc=0x0c0634e6u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c0634e8;
P_0c0634e8: /* original d20a, guest PC 0x0c0634e8 */
if(!s->budget--) { s->failed_pc=0x0c0634e8u; return 0; }
r[2]=read(ram,0x0c063514u,4);
goto P_0c0634ea;
P_0c0634ea: /* original a019, guest PC 0x0c0634ea */
if(!s->budget--) { s->failed_pc=0x0c0634eau; return 0; }
write(ram,r[2],r[5],4);
goto P_0c063520;
P_0c0634ec: /* original 2252, guest PC 0x0c0634ec */
if(!s->budget--) { s->failed_pc=0x0c0634ecu; return 0; }
write(ram,r[2],r[5],4);
return vf3_matrix_family(0x0c0634eeu,s,ram);
P_0c06351c: /* original d044, guest PC 0x0c06351c */
if(!s->budget--) { s->failed_pc=0x0c06351cu; return 0; }
r[0]=read(ram,0x0c063630u,4);
goto P_0c06351e;
P_0c06351e: /* original 2052, guest PC 0x0c06351e */
if(!s->budget--) { s->failed_pc=0x0c06351eu; return 0; }
write(ram,r[0],r[5],4);
goto P_0c063520;
P_0c063520: /* original 9d79, guest PC 0x0c063520 */
if(!s->budget--) { s->failed_pc=0x0c063520u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063616u,2);
goto P_0c063522;
P_0c063522: /* original de44, guest PC 0x0c063522 */
if(!s->budget--) { s->failed_pc=0x0c063522u; return 0; }
r[14]=read(ram,0x0c063634u,4);
goto P_0c063524;
P_0c063524: /* original 9478, guest PC 0x0c063524 */
if(!s->budget--) { s->failed_pc=0x0c063524u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063618u,2);
goto P_0c063526;
P_0c063526: /* original 4e0b, guest PC 0x0c063526 */
if(!s->budget--) { s->failed_pc=0x0c063526u; return 0; }
target=r[14];
r[16]=code_base|0x0c06352au;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06352au) { target=s->pc; goto dispatch; }
goto P_0c06352a;
P_0c063528: /* original 65c3, guest PC 0x0c063528 */
if(!s->budget--) { s->failed_pc=0x0c063528u; return 0; }
r[5]=r[12];
goto P_0c06352a;
P_0c06352a: /* original 9476, guest PC 0x0c06352a */
if(!s->budget--) { s->failed_pc=0x0c06352au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361au,2);
goto P_0c06352c;
P_0c06352c: /* original 4e0b, guest PC 0x0c06352c */
if(!s->budget--) { s->failed_pc=0x0c06352cu; return 0; }
target=r[14];
r[16]=code_base|0x0c063530u;
r[5]=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063530u) { target=s->pc; goto dispatch; }
goto P_0c063530;
P_0c06352e: /* original e520, guest PC 0x0c06352e */
if(!s->budget--) { s->failed_pc=0x0c06352eu; return 0; }
r[5]=0x00000020u;
goto P_0c063530;
P_0c063530: /* original e500, guest PC 0x0c063530 */
if(!s->budget--) { s->failed_pc=0x0c063530u; return 0; }
r[5]=0x00000000u;
goto P_0c063532;
P_0c063532: /* original 4e0b, guest PC 0x0c063532 */
if(!s->budget--) { s->failed_pc=0x0c063532u; return 0; }
target=r[14];
r[16]=code_base|0x0c063536u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063536u) { target=s->pc; goto dispatch; }
goto P_0c063536;
P_0c063534: /* original e408, guest PC 0x0c063534 */
if(!s->budget--) { s->failed_pc=0x0c063534u; return 0; }
r[4]=0x00000008u;
goto P_0c063536;
P_0c063536: /* original 9471, guest PC 0x0c063536 */
if(!s->budget--) { s->failed_pc=0x0c063536u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361cu,2);
goto P_0c063538;
P_0c063538: /* original 4e0b, guest PC 0x0c063538 */
if(!s->budget--) { s->failed_pc=0x0c063538u; return 0; }
target=r[14];
r[16]=code_base|0x0c06353cu;
r[5]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06353cu) { target=s->pc; goto dispatch; }
goto P_0c06353c;
P_0c06353a: /* original e503, guest PC 0x0c06353a */
if(!s->budget--) { s->failed_pc=0x0c06353au; return 0; }
r[5]=0x00000003u;
goto P_0c06353c;
P_0c06353c: /* original e509, guest PC 0x0c06353c */
if(!s->budget--) { s->failed_pc=0x0c06353cu; return 0; }
r[5]=0x00000009u;
goto P_0c06353e;
P_0c06353e: /* original 4e0b, guest PC 0x0c06353e */
if(!s->budget--) { s->failed_pc=0x0c06353eu; return 0; }
target=r[14];
r[16]=code_base|0x0c063542u;
r[4]=0x00000048u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063542u) { target=s->pc; goto dispatch; }
goto P_0c063542;
P_0c063540: /* original e448, guest PC 0x0c063540 */
if(!s->budget--) { s->failed_pc=0x0c063540u; return 0; }
r[4]=0x00000048u;
goto P_0c063542;
P_0c063542: /* original d23d, guest PC 0x0c063542 */
if(!s->budget--) { s->failed_pc=0x0c063542u; return 0; }
r[2]=read(ram,0x0c063638u,4);
goto P_0c063544;
P_0c063544: /* original 6022, guest PC 0x0c063544 */
if(!s->budget--) { s->failed_pc=0x0c063544u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c063546;
P_0c063546: /* original c801, guest PC 0x0c063546 */
if(!s->budget--) { s->failed_pc=0x0c063546u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c063548;
P_0c063548: /* original 8d03, guest PC 0x0c063548 */
if(!s->budget--) { s->failed_pc=0x0c063548u; return 0; }
cond=r[17]&1u;
r[4]=0x00000044u;
if(cond) { goto P_0c063552; }
goto P_0c06354c;
P_0c06354a: /* original e444, guest PC 0x0c06354a */
if(!s->budget--) { s->failed_pc=0x0c06354au; return 0; }
r[4]=0x00000044u;
goto P_0c06354c;
P_0c06354c: /* original d53b, guest PC 0x0c06354c */
if(!s->budget--) { s->failed_pc=0x0c06354cu; return 0; }
r[5]=read(ram,0x0c06363cu,4);
goto P_0c06354e;
P_0c06354e: /* original a001, guest PC 0x0c06354e */
if(!s->budget--) { s->failed_pc=0x0c06354eu; return 0; }
goto P_0c063554;
P_0c063550: /* original 0009, guest PC 0x0c063550 */
if(!s->budget--) { s->failed_pc=0x0c063550u; return 0; }
goto P_0c063552;
P_0c063552: /* original e500, guest PC 0x0c063552 */
if(!s->budget--) { s->failed_pc=0x0c063552u; return 0; }
r[5]=0x00000000u;
goto P_0c063554;
P_0c063554: /* original d13a, guest PC 0x0c063554 */
if(!s->budget--) { s->failed_pc=0x0c063554u; return 0; }
r[1]=read(ram,0x0c063640u,4);
goto P_0c063556;
P_0c063556: /* original 410b, guest PC 0x0c063556 */
if(!s->budget--) { s->failed_pc=0x0c063556u; return 0; }
target=r[1];
r[16]=code_base|0x0c06355au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06355au) { target=s->pc; goto dispatch; }
goto P_0c06355a;
P_0c063558: /* original 0009, guest PC 0x0c063558 */
if(!s->budget--) { s->failed_pc=0x0c063558u; return 0; }
goto P_0c06355a;
P_0c06355a: /* original e500, guest PC 0x0c06355a */
if(!s->budget--) { s->failed_pc=0x0c06355au; return 0; }
r[5]=0x00000000u;
goto P_0c06355c;
P_0c06355c: /* original 4e0b, guest PC 0x0c06355c */
if(!s->budget--) { s->failed_pc=0x0c06355cu; return 0; }
target=r[14];
r[16]=code_base|0x0c063560u;
r[4]=0x0000005cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063560u) { target=s->pc; goto dispatch; }
goto P_0c063560;
P_0c06355e: /* original e45c, guest PC 0x0c06355e */
if(!s->budget--) { s->failed_pc=0x0c06355eu; return 0; }
r[4]=0x0000005cu;
goto P_0c063560;
P_0c063560: /* original d538, guest PC 0x0c063560 */
if(!s->budget--) { s->failed_pc=0x0c063560u; return 0; }
r[5]=read(ram,0x0c063644u,4);
goto P_0c063562;
P_0c063562: /* original 4e0b, guest PC 0x0c063562 */
if(!s->budget--) { s->failed_pc=0x0c063562u; return 0; }
target=r[14];
r[16]=code_base|0x0c063566u;
r[4]=0x00000068u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063566u) { target=s->pc; goto dispatch; }
goto P_0c063566;
P_0c063564: /* original e468, guest PC 0x0c063564 */
if(!s->budget--) { s->failed_pc=0x0c063564u; return 0; }
r[4]=0x00000068u;
goto P_0c063566;
P_0c063566: /* original d538, guest PC 0x0c063566 */
if(!s->budget--) { s->failed_pc=0x0c063566u; return 0; }
r[5]=read(ram,0x0c063648u,4);
goto P_0c063568;
P_0c063568: /* original 4e0b, guest PC 0x0c063568 */
if(!s->budget--) { s->failed_pc=0x0c063568u; return 0; }
target=r[14];
r[16]=code_base|0x0c06356cu;
r[4]=0x0000006cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06356cu) { target=s->pc; goto dispatch; }
goto P_0c06356c;
P_0c06356a: /* original e46c, guest PC 0x0c06356a */
if(!s->budget--) { s->failed_pc=0x0c06356au; return 0; }
r[4]=0x0000006cu;
goto P_0c06356c;
P_0c06356c: /* original d337, guest PC 0x0c06356c */
if(!s->budget--) { s->failed_pc=0x0c06356cu; return 0; }
r[3]=read(ram,0x0c06364cu,4);
goto P_0c06356e;
P_0c06356e: /* original 6032, guest PC 0x0c06356e */
if(!s->budget--) { s->failed_pc=0x0c06356eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063570;
P_0c063570: /* original 8806, guest PC 0x0c063570 */
if(!s->budget--) { s->failed_pc=0x0c063570u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c063572;
P_0c063572: /* original 8b07, guest PC 0x0c063572 */
if(!s->budget--) { s->failed_pc=0x0c063572u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063584; }
goto P_0c063574;
P_0c063574: /* original d536, guest PC 0x0c063574 */
if(!s->budget--) { s->failed_pc=0x0c063574u; return 0; }
r[5]=read(ram,0x0c063650u,4);
goto P_0c063576;
P_0c063576: /* original 9452, guest PC 0x0c063576 */
if(!s->budget--) { s->failed_pc=0x0c063576u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361eu,2);
goto P_0c063578;
P_0c063578: /* original 4e0b, guest PC 0x0c063578 */
if(!s->budget--) { s->failed_pc=0x0c063578u; return 0; }
target=r[14];
r[16]=code_base|0x0c06357cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06357cu) { target=s->pc; goto dispatch; }
goto P_0c06357c;
P_0c06357a: /* original 0009, guest PC 0x0c06357a */
if(!s->budget--) { s->failed_pc=0x0c06357au; return 0; }
goto P_0c06357c;
P_0c06357c: /* original d335, guest PC 0x0c06357c */
if(!s->budget--) { s->failed_pc=0x0c06357cu; return 0; }
r[3]=read(ram,0x0c063654u,4);
goto P_0c06357e;
P_0c06357e: /* original 944f, guest PC 0x0c06357e */
if(!s->budget--) { s->failed_pc=0x0c06357eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063620u,2);
goto P_0c063580;
P_0c063580: /* original a002, guest PC 0x0c063580 */
if(!s->budget--) { s->failed_pc=0x0c063580u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c063588;
P_0c063582: /* original 6532, guest PC 0x0c063582 */
if(!s->budget--) { s->failed_pc=0x0c063582u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c063584;
P_0c063584: /* original d534, guest PC 0x0c063584 */
if(!s->budget--) { s->failed_pc=0x0c063584u; return 0; }
r[5]=read(ram,0x0c063658u,4);
goto P_0c063586;
P_0c063586: /* original 944a, guest PC 0x0c063586 */
if(!s->budget--) { s->failed_pc=0x0c063586u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361eu,2);
goto P_0c063588;
P_0c063588: /* original 4e0b, guest PC 0x0c063588 */
if(!s->budget--) { s->failed_pc=0x0c063588u; return 0; }
target=r[14];
r[16]=code_base|0x0c06358cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06358cu) { target=s->pc; goto dispatch; }
goto P_0c06358c;
P_0c06358a: /* original 0009, guest PC 0x0c06358a */
if(!s->budget--) { s->failed_pc=0x0c06358au; return 0; }
goto P_0c06358c;
P_0c06358c: /* original 9545, guest PC 0x0c06358c */
if(!s->budget--) { s->failed_pc=0x0c06358cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361au,2);
goto P_0c06358e;
P_0c06358e: /* original 4e0b, guest PC 0x0c06358e */
if(!s->budget--) { s->failed_pc=0x0c06358eu; return 0; }
target=r[14];
r[16]=code_base|0x0c063592u;
r[4]=0x0000004cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063592u) { target=s->pc; goto dispatch; }
goto P_0c063592;
P_0c063590: /* original e44c, guest PC 0x0c063590 */
if(!s->budget--) { s->failed_pc=0x0c063590u; return 0; }
r[4]=0x0000004cu;
goto P_0c063592;
P_0c063592: /* original e500, guest PC 0x0c063592 */
if(!s->budget--) { s->failed_pc=0x0c063592u; return 0; }
r[5]=0x00000000u;
goto P_0c063594;
P_0c063594: /* original 4e0b, guest PC 0x0c063594 */
if(!s->budget--) { s->failed_pc=0x0c063594u; return 0; }
target=r[14];
r[16]=code_base|0x0c063598u;
r[4]=0x00000074u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063598u) { target=s->pc; goto dispatch; }
goto P_0c063598;
P_0c063596: /* original e474, guest PC 0x0c063596 */
if(!s->budget--) { s->failed_pc=0x0c063596u; return 0; }
r[4]=0x00000074u;
goto P_0c063598;
P_0c063598: /* original d530, guest PC 0x0c063598 */
if(!s->budget--) { s->failed_pc=0x0c063598u; return 0; }
r[5]=read(ram,0x0c06365cu,4);
goto P_0c06359a;
P_0c06359a: /* original 4e0b, guest PC 0x0c06359a */
if(!s->budget--) { s->failed_pc=0x0c06359au; return 0; }
target=r[14];
r[16]=code_base|0x0c06359eu;
r[4]=0x00000078u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06359eu) { target=s->pc; goto dispatch; }
goto P_0c06359e;
P_0c06359c: /* original e478, guest PC 0x0c06359c */
if(!s->budget--) { s->failed_pc=0x0c06359cu; return 0; }
r[4]=0x00000078u;
goto P_0c06359e;
P_0c06359e: /* original 9440, guest PC 0x0c06359e */
if(!s->budget--) { s->failed_pc=0x0c06359eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063622u,2);
goto P_0c0635a0;
P_0c0635a0: /* original 4e0b, guest PC 0x0c0635a0 */
if(!s->budget--) { s->failed_pc=0x0c0635a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635a4u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635a4u) { target=s->pc; goto dispatch; }
goto P_0c0635a4;
P_0c0635a2: /* original e500, guest PC 0x0c0635a2 */
if(!s->budget--) { s->failed_pc=0x0c0635a2u; return 0; }
r[5]=0x00000000u;
goto P_0c0635a4;
P_0c0635a4: /* original 65d3, guest PC 0x0c0635a4 */
if(!s->budget--) { s->failed_pc=0x0c0635a4u; return 0; }
r[5]=r[13];
goto P_0c0635a6;
P_0c0635a6: /* original 4e0b, guest PC 0x0c0635a6 */
if(!s->budget--) { s->failed_pc=0x0c0635a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635aau;
r[4]=0x00000030u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635aau) { target=s->pc; goto dispatch; }
goto P_0c0635aa;
P_0c0635a8: /* original e430, guest PC 0x0c0635a8 */
if(!s->budget--) { s->failed_pc=0x0c0635a8u; return 0; }
r[4]=0x00000030u;
goto P_0c0635aa;
P_0c0635aa: /* original d52d, guest PC 0x0c0635aa */
if(!s->budget--) { s->failed_pc=0x0c0635aau; return 0; }
r[5]=read(ram,0x0c063660u,4);
goto P_0c0635ac;
P_0c0635ac: /* original 943a, guest PC 0x0c0635ac */
if(!s->budget--) { s->failed_pc=0x0c0635acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063624u,2);
goto P_0c0635ae;
P_0c0635ae: /* original 4e0b, guest PC 0x0c0635ae */
if(!s->budget--) { s->failed_pc=0x0c0635aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0635b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635b2u) { target=s->pc; goto dispatch; }
goto P_0c0635b2;
P_0c0635b0: /* original 0009, guest PC 0x0c0635b0 */
if(!s->budget--) { s->failed_pc=0x0c0635b0u; return 0; }
goto P_0c0635b2;
P_0c0635b2: /* original d52b, guest PC 0x0c0635b2 */
if(!s->budget--) { s->failed_pc=0x0c0635b2u; return 0; }
r[5]=read(ram,0x0c063660u,4);
goto P_0c0635b4;
P_0c0635b4: /* original 9437, guest PC 0x0c0635b4 */
if(!s->budget--) { s->failed_pc=0x0c0635b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063626u,2);
goto P_0c0635b6;
P_0c0635b6: /* original 4e0b, guest PC 0x0c0635b6 */
if(!s->budget--) { s->failed_pc=0x0c0635b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635bau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635bau) { target=s->pc; goto dispatch; }
goto P_0c0635ba;
P_0c0635b8: /* original 0009, guest PC 0x0c0635b8 */
if(!s->budget--) { s->failed_pc=0x0c0635b8u; return 0; }
goto P_0c0635ba;
P_0c0635ba: /* original 9435, guest PC 0x0c0635ba */
if(!s->budget--) { s->failed_pc=0x0c0635bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063628u,2);
goto P_0c0635bc;
P_0c0635bc: /* original 4e0b, guest PC 0x0c0635bc */
if(!s->budget--) { s->failed_pc=0x0c0635bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0635c0u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635c0u) { target=s->pc; goto dispatch; }
goto P_0c0635c0;
P_0c0635be: /* original e500, guest PC 0x0c0635be */
if(!s->budget--) { s->failed_pc=0x0c0635beu; return 0; }
r[5]=0x00000000u;
goto P_0c0635c0;
P_0c0635c0: /* original 9433, guest PC 0x0c0635c0 */
if(!s->budget--) { s->failed_pc=0x0c0635c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06362au,2);
goto P_0c0635c2;
P_0c0635c2: /* original 4e0b, guest PC 0x0c0635c2 */
if(!s->budget--) { s->failed_pc=0x0c0635c2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635c6u;
r[5]=0xffffffffu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635c6u) { target=s->pc; goto dispatch; }
goto P_0c0635c6;
P_0c0635c4: /* original e5ff, guest PC 0x0c0635c4 */
if(!s->budget--) { s->failed_pc=0x0c0635c4u; return 0; }
r[5]=0xffffffffu;
goto P_0c0635c6;
P_0c0635c6: /* original e507, guest PC 0x0c0635c6 */
if(!s->budget--) { s->failed_pc=0x0c0635c6u; return 0; }
r[5]=0x00000007u;
goto P_0c0635c8;
P_0c0635c8: /* original 6453, guest PC 0x0c0635c8 */
if(!s->budget--) { s->failed_pc=0x0c0635c8u; return 0; }
r[4]=r[5];
goto P_0c0635ca;
P_0c0635ca: /* original 4e0b, guest PC 0x0c0635ca */
if(!s->budget--) { s->failed_pc=0x0c0635cau; return 0; }
target=r[14];
r[16]=code_base|0x0c0635ceu;
r[4]+=0x00000079u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635ceu) { target=s->pc; goto dispatch; }
goto P_0c0635ce;
P_0c0635cc: /* original 7479, guest PC 0x0c0635cc */
if(!s->budget--) { s->failed_pc=0x0c0635ccu; return 0; }
r[4]+=0x00000079u;
goto P_0c0635ce;
P_0c0635ce: /* original d525, guest PC 0x0c0635ce */
if(!s->budget--) { s->failed_pc=0x0c0635ceu; return 0; }
r[5]=read(ram,0x0c063664u,4);
goto P_0c0635d0;
P_0c0635d0: /* original 942c, guest PC 0x0c0635d0 */
if(!s->budget--) { s->failed_pc=0x0c0635d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06362cu,2);
goto P_0c0635d2;
P_0c0635d2: /* original 4e0b, guest PC 0x0c0635d2 */
if(!s->budget--) { s->failed_pc=0x0c0635d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635d6u) { target=s->pc; goto dispatch; }
goto P_0c0635d6;
P_0c0635d4: /* original 0009, guest PC 0x0c0635d4 */
if(!s->budget--) { s->failed_pc=0x0c0635d4u; return 0; }
goto P_0c0635d6;
P_0c0635d6: /* original d524, guest PC 0x0c0635d6 */
if(!s->budget--) { s->failed_pc=0x0c0635d6u; return 0; }
r[5]=read(ram,0x0c063668u,4);
goto P_0c0635d8;
P_0c0635d8: /* original 9429, guest PC 0x0c0635d8 */
if(!s->budget--) { s->failed_pc=0x0c0635d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06362eu,2);
goto P_0c0635da;
P_0c0635da: /* original 4e0b, guest PC 0x0c0635da */
if(!s->budget--) { s->failed_pc=0x0c0635dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0635deu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635deu) { target=s->pc; goto dispatch; }
goto P_0c0635de;
P_0c0635dc: /* original 0009, guest PC 0x0c0635dc */
if(!s->budget--) { s->failed_pc=0x0c0635dcu; return 0; }
goto P_0c0635de;
P_0c0635de: /* original e501, guest PC 0x0c0635de */
if(!s->budget--) { s->failed_pc=0x0c0635deu; return 0; }
r[5]=0x00000001u;
goto P_0c0635e0;
P_0c0635e0: /* original 4e0b, guest PC 0x0c0635e0 */
if(!s->budget--) { s->failed_pc=0x0c0635e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635e4u;
r[4]=0x00000074u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635e4u) { target=s->pc; goto dispatch; }
goto P_0c0635e4;
P_0c0635e2: /* original e474, guest PC 0x0c0635e2 */
if(!s->budget--) { s->failed_pc=0x0c0635e2u; return 0; }
r[4]=0x00000074u;
goto P_0c0635e4;
P_0c0635e4: /* original d319, guest PC 0x0c0635e4 */
if(!s->budget--) { s->failed_pc=0x0c0635e4u; return 0; }
r[3]=read(ram,0x0c06364cu,4);
goto P_0c0635e6;
P_0c0635e6: /* original 6032, guest PC 0x0c0635e6 */
if(!s->budget--) { s->failed_pc=0x0c0635e6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0635e8;
P_0c0635e8: /* original 8806, guest PC 0x0c0635e8 */
if(!s->budget--) { s->failed_pc=0x0c0635e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0635ea;
P_0c0635ea: /* original 8901, guest PC 0x0c0635ea */
if(!s->budget--) { s->failed_pc=0x0c0635eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0635f0; }
goto P_0c0635ec;
P_0c0635ec: /* original affe, guest PC 0x0c0635ec */
if(!s->budget--) { s->failed_pc=0x0c0635ecu; return 0; }
goto P_0c0635ec;
P_0c0635ee: /* original 0009, guest PC 0x0c0635ee */
if(!s->budget--) { s->failed_pc=0x0c0635eeu; return 0; }
goto P_0c0635f0;
P_0c0635f0: /* original d216, guest PC 0x0c0635f0 */
if(!s->budget--) { s->failed_pc=0x0c0635f0u; return 0; }
r[2]=read(ram,0x0c06364cu,4);
goto P_0c0635f2;
P_0c0635f2: /* original 6022, guest PC 0x0c0635f2 */
if(!s->budget--) { s->failed_pc=0x0c0635f2u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0635f4;
P_0c0635f4: /* original 8806, guest PC 0x0c0635f4 */
if(!s->budget--) { s->failed_pc=0x0c0635f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0635f6;
P_0c0635f6: /* original 8f03, guest PC 0x0c0635f6 */
if(!s->budget--) { s->failed_pc=0x0c0635f6u; return 0; }
cond=r[17]&1u;
r[4]=0x0000007cu;
if(!cond) { goto P_0c063600; }
goto P_0c0635fa;
P_0c0635f8: /* original e47c, guest PC 0x0c0635f8 */
if(!s->budget--) { s->failed_pc=0x0c0635f8u; return 0; }
r[4]=0x0000007cu;
goto P_0c0635fa;
P_0c0635fa: /* original d51c, guest PC 0x0c0635fa */
if(!s->budget--) { s->failed_pc=0x0c0635fau; return 0; }
r[5]=read(ram,0x0c06366cu,4);
goto P_0c0635fc;
P_0c0635fc: /* original a001, guest PC 0x0c0635fc */
if(!s->budget--) { s->failed_pc=0x0c0635fcu; return 0; }
goto P_0c063602;
P_0c0635fe: /* original 0009, guest PC 0x0c0635fe */
if(!s->budget--) { s->failed_pc=0x0c0635feu; return 0; }
goto P_0c063600;
P_0c063600: /* original d51b, guest PC 0x0c063600 */
if(!s->budget--) { s->failed_pc=0x0c063600u; return 0; }
r[5]=read(ram,0x0c063670u,4);
goto P_0c063602;
P_0c063602: /* original 4e0b, guest PC 0x0c063602 */
if(!s->budget--) { s->failed_pc=0x0c063602u; return 0; }
target=r[14];
r[16]=code_base|0x0c063606u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063606u) { target=s->pc; goto dispatch; }
goto P_0c063606;
P_0c063604: /* original 0009, guest PC 0x0c063604 */
if(!s->budget--) { s->failed_pc=0x0c063604u; return 0; }
goto P_0c063606;
P_0c063606: /* original e300, guest PC 0x0c063606 */
if(!s->budget--) { s->failed_pc=0x0c063606u; return 0; }
r[3]=0x00000000u;
goto P_0c063608;
P_0c063608: /* original de1a, guest PC 0x0c063608 */
if(!s->budget--) { s->failed_pc=0x0c063608u; return 0; }
r[14]=read(ram,0x0c063674u,4);
goto P_0c06360a;
P_0c06360a: /* original 6d33, guest PC 0x0c06360a */
if(!s->budget--) { s->failed_pc=0x0c06360au; return 0; }
r[13]=r[3];
goto P_0c06360c;
P_0c06360c: /* original db1a, guest PC 0x0c06360c */
if(!s->budget--) { s->failed_pc=0x0c06360cu; return 0; }
r[11]=read(ram,0x0c063678u,4);
goto P_0c06360e;
P_0c06360e: /* original 2f32, guest PC 0x0c06360e */
if(!s->budget--) { s->failed_pc=0x0c06360eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c063610;
P_0c063610: /* original dc1a, guest PC 0x0c063610 */
if(!s->budget--) { s->failed_pc=0x0c063610u; return 0; }
r[12]=read(ram,0x0c06367cu,4);
goto P_0c063612;
P_0c063612: /* original a03b, guest PC 0x0c063612 */
if(!s->budget--) { s->failed_pc=0x0c063612u; return 0; }
goto P_0c06368c;
P_0c063614: /* original 0009, guest PC 0x0c063614 */
if(!s->budget--) { s->failed_pc=0x0c063614u; return 0; }
return vf3_matrix_family(0x0c063616u,s,ram);
P_0c063680: /* original e604, guest PC 0x0c063680 */
if(!s->budget--) { s->failed_pc=0x0c063680u; return 0; }
r[6]=0x00000004u;
goto P_0c063682;
P_0c063682: /* original 65f3, guest PC 0x0c063682 */
if(!s->budget--) { s->failed_pc=0x0c063682u; return 0; }
r[5]=r[15];
goto P_0c063684;
P_0c063684: /* original 4b0b, guest PC 0x0c063684 */
if(!s->budget--) { s->failed_pc=0x0c063684u; return 0; }
target=r[11];
r[16]=code_base|0x0c063688u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063688u) { target=s->pc; goto dispatch; }
goto P_0c063688;
P_0c063686: /* original 64e3, guest PC 0x0c063686 */
if(!s->budget--) { s->failed_pc=0x0c063686u; return 0; }
r[4]=r[14];
goto P_0c063688;
P_0c063688: /* original 7d01, guest PC 0x0c063688 */
if(!s->budget--) { s->failed_pc=0x0c063688u; return 0; }
r[13]+=0x00000001u;
goto P_0c06368a;
P_0c06368a: /* original 7e04, guest PC 0x0c06368a */
if(!s->budget--) { s->failed_pc=0x0c06368au; return 0; }
r[14]+=0x00000004u;
goto P_0c06368c;
P_0c06368c: /* original 3dc3, guest PC 0x0c06368c */
if(!s->budget--) { s->failed_pc=0x0c06368cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[12])!=0);
goto P_0c06368e;
P_0c06368e: /* original 8bf7, guest PC 0x0c06368e */
if(!s->budget--) { s->failed_pc=0x0c06368eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063680; }
goto P_0c063690;
P_0c063690: /* original e001, guest PC 0x0c063690 */
if(!s->budget--) { s->failed_pc=0x0c063690u; return 0; }
r[0]=0x00000001u;
goto P_0c063692;
P_0c063692: /* original 7f08, guest PC 0x0c063692 */
if(!s->budget--) { s->failed_pc=0x0c063692u; return 0; }
r[15]+=0x00000008u;
goto P_0c063694;
P_0c063694: /* original 4f26, guest PC 0x0c063694 */
if(!s->budget--) { s->failed_pc=0x0c063694u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063696;
P_0c063696: /* original 6bf6, guest PC 0x0c063696 */
if(!s->budget--) { s->failed_pc=0x0c063696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c063698;
P_0c063698: /* original 6cf6, guest PC 0x0c063698 */
if(!s->budget--) { s->failed_pc=0x0c063698u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06369a;
P_0c06369a: /* original 6df6, guest PC 0x0c06369a */
if(!s->budget--) { s->failed_pc=0x0c06369au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06369c;
P_0c06369c: /* original 000b, guest PC 0x0c06369c */
if(!s->budget--) { s->failed_pc=0x0c06369cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06369e: /* original 6ef6, guest PC 0x0c06369e */
if(!s->budget--) { s->failed_pc=0x0c06369eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0636a0u,s,ram);
P_0c07a856: /* original 4f22, guest PC 0x0c07a856 */
if(!s->budget--) { s->failed_pc=0x0c07a856u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a858;
P_0c07a858: /* original dc59, guest PC 0x0c07a858 */
if(!s->budget--) { s->failed_pc=0x0c07a858u; return 0; }
r[12]=read(ram,0x0c07a9c0u,4);
goto P_0c07a85a;
P_0c07a85a: /* original dd5c, guest PC 0x0c07a85a */
if(!s->budget--) { s->failed_pc=0x0c07a85au; return 0; }
r[13]=read(ram,0x0c07a9ccu,4);
goto P_0c07a85c;
P_0c07a85c: /* original 4c0b, guest PC 0x0c07a85c */
if(!s->budget--) { s->failed_pc=0x0c07a85cu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a860u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a860u) { target=s->pc; goto dispatch; }
goto P_0c07a860;
P_0c07a85e: /* original 64b3, guest PC 0x0c07a85e */
if(!s->budget--) { s->failed_pc=0x0c07a85eu; return 0; }
r[4]=r[11];
goto P_0c07a860;
P_0c07a860: /* original 60b3, guest PC 0x0c07a860 */
if(!s->budget--) { s->failed_pc=0x0c07a860u; return 0; }
r[0]=r[11];
goto P_0c07a862;
P_0c07a862: /* original 880f, guest PC 0x0c07a862 */
if(!s->budget--) { s->failed_pc=0x0c07a862u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c07a864;
P_0c07a864: /* original 8b0e, guest PC 0x0c07a864 */
if(!s->budget--) { s->failed_pc=0x0c07a864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a884; }
goto P_0c07a866;
P_0c07a866: /* original 4c0b, guest PC 0x0c07a866 */
if(!s->budget--) { s->failed_pc=0x0c07a866u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a86au;
r[4]=0x0000000fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a86au) { target=s->pc; goto dispatch; }
goto P_0c07a86a;
P_0c07a868: /* original e40f, guest PC 0x0c07a868 */
if(!s->budget--) { s->failed_pc=0x0c07a868u; return 0; }
r[4]=0x0000000fu;
goto P_0c07a86a;
P_0c07a86a: /* original d459, guest PC 0x0c07a86a */
if(!s->budget--) { s->failed_pc=0x0c07a86au; return 0; }
r[4]=read(ram,0x0c07a9d0u,4);
goto P_0c07a86c;
P_0c07a86c: /* original bfbc, guest PC 0x0c07a86c */
if(!s->budget--) { s->failed_pc=0x0c07a86cu; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a870u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a870u) { target=s->pc; goto dispatch; }
goto P_0c07a870;
P_0c07a86e: /* original 65e3, guest PC 0x0c07a86e */
if(!s->budget--) { s->failed_pc=0x0c07a86eu; return 0; }
r[5]=r[14];
goto P_0c07a870;
P_0c07a870: /* original 4c0b, guest PC 0x0c07a870 */
if(!s->budget--) { s->failed_pc=0x0c07a870u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a874u;
r[4]=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a874u) { target=s->pc; goto dispatch; }
goto P_0c07a874;
P_0c07a872: /* original e424, guest PC 0x0c07a872 */
if(!s->budget--) { s->failed_pc=0x0c07a872u; return 0; }
r[4]=0x00000024u;
goto P_0c07a874;
P_0c07a874: /* original d457, guest PC 0x0c07a874 */
if(!s->budget--) { s->failed_pc=0x0c07a874u; return 0; }
r[4]=read(ram,0x0c07a9d4u,4);
goto P_0c07a876;
P_0c07a876: /* original bfb7, guest PC 0x0c07a876 */
if(!s->budget--) { s->failed_pc=0x0c07a876u; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a87au;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a87au) { target=s->pc; goto dispatch; }
goto P_0c07a87a;
P_0c07a878: /* original 65e3, guest PC 0x0c07a878 */
if(!s->budget--) { s->failed_pc=0x0c07a878u; return 0; }
r[5]=r[14];
goto P_0c07a87a;
P_0c07a87a: /* original e00f, guest PC 0x0c07a87a */
if(!s->budget--) { s->failed_pc=0x0c07a87au; return 0; }
r[0]=0x0000000fu;
goto P_0c07a87c;
P_0c07a87c: /* original 81df, guest PC 0x0c07a87c */
if(!s->budget--) { s->failed_pc=0x0c07a87cu; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c07a87e;
P_0c07a87e: /* original e048, guest PC 0x0c07a87e */
if(!s->budget--) { s->failed_pc=0x0c07a87eu; return 0; }
r[0]=0x00000048u;
goto P_0c07a880;
P_0c07a880: /* original a096, guest PC 0x0c07a880 */
if(!s->budget--) { s->failed_pc=0x0c07a880u; return 0; }
r[3]=0x00000024u;
goto P_0c07a9b0;
P_0c07a882: /* original e324, guest PC 0x0c07a882 */
if(!s->budget--) { s->failed_pc=0x0c07a882u; return 0; }
r[3]=0x00000024u;
goto P_0c07a884;
P_0c07a884: /* original 60b3, guest PC 0x0c07a884 */
if(!s->budget--) { s->failed_pc=0x0c07a884u; return 0; }
r[0]=r[11];
goto P_0c07a886;
P_0c07a886: /* original d954, guest PC 0x0c07a886 */
if(!s->budget--) { s->failed_pc=0x0c07a886u; return 0; }
r[9]=read(ram,0x0c07a9d8u,4);
goto P_0c07a888;
P_0c07a888: /* original 8808, guest PC 0x0c07a888 */
if(!s->budget--) { s->failed_pc=0x0c07a888u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c07a88a;
P_0c07a88a: /* original 8b06, guest PC 0x0c07a88a */
if(!s->budget--) { s->failed_pc=0x0c07a88au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a89a; }
goto P_0c07a88c;
P_0c07a88c: /* original 4c0b, guest PC 0x0c07a88c */
if(!s->budget--) { s->failed_pc=0x0c07a88cu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a890u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a890u) { target=s->pc; goto dispatch; }
goto P_0c07a890;
P_0c07a88e: /* original e408, guest PC 0x0c07a88e */
if(!s->budget--) { s->failed_pc=0x0c07a88eu; return 0; }
r[4]=0x00000008u;
goto P_0c07a890;
P_0c07a890: /* original 65e3, guest PC 0x0c07a890 */
if(!s->budget--) { s->failed_pc=0x0c07a890u; return 0; }
r[5]=r[14];
goto P_0c07a892;
P_0c07a892: /* original bfa9, guest PC 0x0c07a892 */
if(!s->budget--) { s->failed_pc=0x0c07a892u; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a896u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a896u) { target=s->pc; goto dispatch; }
goto P_0c07a896;
P_0c07a894: /* original 6493, guest PC 0x0c07a894 */
if(!s->budget--) { s->failed_pc=0x0c07a894u; return 0; }
r[4]=r[9];
goto P_0c07a896;
P_0c07a896: /* original a008, guest PC 0x0c07a896 */
if(!s->budget--) { s->failed_pc=0x0c07a896u; return 0; }
r[4]=0x00000008u;
goto P_0c07a8aa;
P_0c07a898: /* original e408, guest PC 0x0c07a898 */
if(!s->budget--) { s->failed_pc=0x0c07a898u; return 0; }
r[4]=0x00000008u;
goto P_0c07a89a;
P_0c07a89a: /* original 8809, guest PC 0x0c07a89a */
if(!s->budget--) { s->failed_pc=0x0c07a89au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07a89c;
P_0c07a89c: /* original 8b0b, guest PC 0x0c07a89c */
if(!s->budget--) { s->failed_pc=0x0c07a89cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a8b6; }
goto P_0c07a89e;
P_0c07a89e: /* original 4c0b, guest PC 0x0c07a89e */
if(!s->budget--) { s->failed_pc=0x0c07a89eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a8a2u;
r[4]=0x00000009u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8a2u) { target=s->pc; goto dispatch; }
goto P_0c07a8a2;
P_0c07a8a0: /* original e409, guest PC 0x0c07a8a0 */
if(!s->budget--) { s->failed_pc=0x0c07a8a0u; return 0; }
r[4]=0x00000009u;
goto P_0c07a8a2;
P_0c07a8a2: /* original 65e3, guest PC 0x0c07a8a2 */
if(!s->budget--) { s->failed_pc=0x0c07a8a2u; return 0; }
r[5]=r[14];
goto P_0c07a8a4;
P_0c07a8a4: /* original bfa0, guest PC 0x0c07a8a4 */
if(!s->budget--) { s->failed_pc=0x0c07a8a4u; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a8a8u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8a8u) { target=s->pc; goto dispatch; }
goto P_0c07a8a8;
P_0c07a8a6: /* original 6493, guest PC 0x0c07a8a6 */
if(!s->budget--) { s->failed_pc=0x0c07a8a6u; return 0; }
r[4]=r[9];
goto P_0c07a8a8;
P_0c07a8a8: /* original e409, guest PC 0x0c07a8a8 */
if(!s->budget--) { s->failed_pc=0x0c07a8a8u; return 0; }
r[4]=0x00000009u;
goto P_0c07a8aa;
P_0c07a8aa: /* original 60ad, guest PC 0x0c07a8aa */
if(!s->budget--) { s->failed_pc=0x0c07a8aau; return 0; }
r[0]=r[10]&65535u;
goto P_0c07a8ac;
P_0c07a8ac: /* original 4000, guest PC 0x0c07a8ac */
if(!s->budget--) { s->failed_pc=0x0c07a8acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07a8ae;
P_0c07a8ae: /* original 0d45, guest PC 0x0c07a8ae */
if(!s->budget--) { s->failed_pc=0x0c07a8aeu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c07a8b0;
P_0c07a8b0: /* original 6043, guest PC 0x0c07a8b0 */
if(!s->budget--) { s->failed_pc=0x0c07a8b0u; return 0; }
r[0]=r[4];
goto P_0c07a8b2;
P_0c07a8b2: /* original a0b5, guest PC 0x0c07a8b2 */
if(!s->budget--) { s->failed_pc=0x0c07a8b2u; return 0; }
write(ram,r[13]+10,r[0],2);
goto P_0c07aa20;
P_0c07a8b4: /* original 81d5, guest PC 0x0c07a8b4 */
if(!s->budget--) { s->failed_pc=0x0c07a8b4u; return 0; }
write(ram,r[13]+10,r[0],2);
goto P_0c07a8b6;
P_0c07a8b6: /* original 60b3, guest PC 0x0c07a8b6 */
if(!s->budget--) { s->failed_pc=0x0c07a8b6u; return 0; }
r[0]=r[11];
goto P_0c07a8b8;
P_0c07a8b8: /* original d448, guest PC 0x0c07a8b8 */
if(!s->budget--) { s->failed_pc=0x0c07a8b8u; return 0; }
r[4]=read(ram,0x0c07a9dcu,4);
goto P_0c07a8ba;
P_0c07a8ba: /* original 880a, guest PC 0x0c07a8ba */
if(!s->budget--) { s->failed_pc=0x0c07a8bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c07a8bc;
P_0c07a8bc: /* original 8902, guest PC 0x0c07a8bc */
if(!s->budget--) { s->failed_pc=0x0c07a8bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a8c4; }
goto P_0c07a8be;
P_0c07a8be: /* original 60b3, guest PC 0x0c07a8be */
if(!s->budget--) { s->failed_pc=0x0c07a8beu; return 0; }
r[0]=r[11];
goto P_0c07a8c0;
P_0c07a8c0: /* original 880b, guest PC 0x0c07a8c0 */
if(!s->budget--) { s->failed_pc=0x0c07a8c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c07a8c2;
P_0c07a8c2: /* original 8b07, guest PC 0x0c07a8c2 */
if(!s->budget--) { s->failed_pc=0x0c07a8c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a8d4; }
goto P_0c07a8c4;
P_0c07a8c4: /* original bf9f, guest PC 0x0c07a8c4 */
if(!s->budget--) { s->failed_pc=0x0c07a8c4u; return 0; }
target=0x0c07a806u; r[16]=code_base|0x0c07a8c8u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8c8u) { target=s->pc; goto dispatch; }
goto P_0c07a8c8;
P_0c07a8c6: /* original 65e3, guest PC 0x0c07a8c6 */
if(!s->budget--) { s->failed_pc=0x0c07a8c6u; return 0; }
r[5]=r[14];
goto P_0c07a8c8;
P_0c07a8c8: /* original 60ad, guest PC 0x0c07a8c8 */
if(!s->budget--) { s->failed_pc=0x0c07a8c8u; return 0; }
r[0]=r[10]&65535u;
goto P_0c07a8ca;
P_0c07a8ca: /* original 4000, guest PC 0x0c07a8ca */
if(!s->budget--) { s->failed_pc=0x0c07a8cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07a8cc;
P_0c07a8cc: /* original 0db5, guest PC 0x0c07a8cc */
if(!s->budget--) { s->failed_pc=0x0c07a8ccu; return 0; }
write(ram,r[13]+r[0],r[11],2);
goto P_0c07a8ce;
P_0c07a8ce: /* original 60b3, guest PC 0x0c07a8ce */
if(!s->budget--) { s->failed_pc=0x0c07a8ceu; return 0; }
r[0]=r[11];
goto P_0c07a8d0;
P_0c07a8d0: /* original a0a6, guest PC 0x0c07a8d0 */
if(!s->budget--) { s->failed_pc=0x0c07a8d0u; return 0; }
write(ram,r[13]+12,r[0],2);
goto P_0c07aa20;
P_0c07a8d2: /* original 81d6, guest PC 0x0c07a8d2 */
if(!s->budget--) { s->failed_pc=0x0c07a8d2u; return 0; }
write(ram,r[13]+12,r[0],2);
goto P_0c07a8d4;
P_0c07a8d4: /* original 8812, guest PC 0x0c07a8d4 */
if(!s->budget--) { s->failed_pc=0x0c07a8d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c07a8d6;
P_0c07a8d6: /* original 8b15, guest PC 0x0c07a8d6 */
if(!s->budget--) { s->failed_pc=0x0c07a8d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a904; }
goto P_0c07a8d8;
P_0c07a8d8: /* original 4c0b, guest PC 0x0c07a8d8 */
if(!s->budget--) { s->failed_pc=0x0c07a8d8u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a8dcu;
r[4]=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8dcu) { target=s->pc; goto dispatch; }
goto P_0c07a8dc;
P_0c07a8da: /* original e423, guest PC 0x0c07a8da */
if(!s->budget--) { s->failed_pc=0x0c07a8dau; return 0; }
r[4]=0x00000023u;
goto P_0c07a8dc;
P_0c07a8dc: /* original db40, guest PC 0x0c07a8dc */
if(!s->budget--) { s->failed_pc=0x0c07a8dcu; return 0; }
r[11]=read(ram,0x0c07a9e0u,4);
goto P_0c07a8de;
P_0c07a8de: /* original 65e3, guest PC 0x0c07a8de */
if(!s->budget--) { s->failed_pc=0x0c07a8deu; return 0; }
r[5]=r[14];
goto P_0c07a8e0;
P_0c07a8e0: /* original bf82, guest PC 0x0c07a8e0 */
if(!s->budget--) { s->failed_pc=0x0c07a8e0u; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a8e4u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8e4u) { target=s->pc; goto dispatch; }
goto P_0c07a8e4;
P_0c07a8e2: /* original 64b3, guest PC 0x0c07a8e2 */
if(!s->budget--) { s->failed_pc=0x0c07a8e2u; return 0; }
r[4]=r[11];
goto P_0c07a8e4;
P_0c07a8e4: /* original 4c0b, guest PC 0x0c07a8e4 */
if(!s->budget--) { s->failed_pc=0x0c07a8e4u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a8e8u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8e8u) { target=s->pc; goto dispatch; }
goto P_0c07a8e8;
P_0c07a8e6: /* original e412, guest PC 0x0c07a8e6 */
if(!s->budget--) { s->failed_pc=0x0c07a8e6u; return 0; }
r[4]=0x00000012u;
goto P_0c07a8e8;
P_0c07a8e8: /* original 64b3, guest PC 0x0c07a8e8 */
if(!s->budget--) { s->failed_pc=0x0c07a8e8u; return 0; }
r[4]=r[11];
goto P_0c07a8ea;
P_0c07a8ea: /* original 65e3, guest PC 0x0c07a8ea */
if(!s->budget--) { s->failed_pc=0x0c07a8eau; return 0; }
r[5]=r[14];
goto P_0c07a8ec;
P_0c07a8ec: /* original bf7c, guest PC 0x0c07a8ec */
if(!s->budget--) { s->failed_pc=0x0c07a8ecu; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a8f0u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8f0u) { target=s->pc; goto dispatch; }
goto P_0c07a8f0;
P_0c07a8ee: /* original 7410, guest PC 0x0c07a8ee */
if(!s->budget--) { s->failed_pc=0x0c07a8eeu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a8f0;
P_0c07a8f0: /* original 4c0b, guest PC 0x0c07a8f0 */
if(!s->budget--) { s->failed_pc=0x0c07a8f0u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a8f4u;
r[4]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8f4u) { target=s->pc; goto dispatch; }
goto P_0c07a8f4;
P_0c07a8f2: /* original e418, guest PC 0x0c07a8f2 */
if(!s->budget--) { s->failed_pc=0x0c07a8f2u; return 0; }
r[4]=0x00000018u;
goto P_0c07a8f4;
P_0c07a8f4: /* original 64b3, guest PC 0x0c07a8f4 */
if(!s->budget--) { s->failed_pc=0x0c07a8f4u; return 0; }
r[4]=r[11];
goto P_0c07a8f6;
P_0c07a8f6: /* original 65e3, guest PC 0x0c07a8f6 */
if(!s->budget--) { s->failed_pc=0x0c07a8f6u; return 0; }
r[5]=r[14];
goto P_0c07a8f8;
P_0c07a8f8: /* original bf76, guest PC 0x0c07a8f8 */
if(!s->budget--) { s->failed_pc=0x0c07a8f8u; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a8fcu;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8fcu) { target=s->pc; goto dispatch; }
goto P_0c07a8fc;
P_0c07a8fa: /* original 7420, guest PC 0x0c07a8fa */
if(!s->budget--) { s->failed_pc=0x0c07a8fau; return 0; }
r[4]+=0x00000020u;
goto P_0c07a8fc;
P_0c07a8fc: /* original e212, guest PC 0x0c07a8fc */
if(!s->budget--) { s->failed_pc=0x0c07a8fcu; return 0; }
r[2]=0x00000012u;
goto P_0c07a8fe;
P_0c07a8fe: /* original e024, guest PC 0x0c07a8fe */
if(!s->budget--) { s->failed_pc=0x0c07a8feu; return 0; }
r[0]=0x00000024u;
goto P_0c07a900;
P_0c07a900: /* original a018, guest PC 0x0c07a900 */
if(!s->budget--) { s->failed_pc=0x0c07a900u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a934;
P_0c07a902: /* original 0d25, guest PC 0x0c07a902 */
if(!s->budget--) { s->failed_pc=0x0c07a902u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a904;
P_0c07a904: /* original 60b3, guest PC 0x0c07a904 */
if(!s->budget--) { s->failed_pc=0x0c07a904u; return 0; }
r[0]=r[11];
goto P_0c07a906;
P_0c07a906: /* original 8813, guest PC 0x0c07a906 */
if(!s->budget--) { s->failed_pc=0x0c07a906u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000013u)!=0);
goto P_0c07a908;
P_0c07a908: /* original 8b1b, guest PC 0x0c07a908 */
if(!s->budget--) { s->failed_pc=0x0c07a908u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a942; }
goto P_0c07a90a;
P_0c07a90a: /* original 4c0b, guest PC 0x0c07a90a */
if(!s->budget--) { s->failed_pc=0x0c07a90au; return 0; }
target=r[12];
r[16]=code_base|0x0c07a90eu;
r[4]=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a90eu) { target=s->pc; goto dispatch; }
goto P_0c07a90e;
P_0c07a90c: /* original e423, guest PC 0x0c07a90c */
if(!s->budget--) { s->failed_pc=0x0c07a90cu; return 0; }
r[4]=0x00000023u;
goto P_0c07a90e;
P_0c07a90e: /* original db35, guest PC 0x0c07a90e */
if(!s->budget--) { s->failed_pc=0x0c07a90eu; return 0; }
r[11]=read(ram,0x0c07a9e4u,4);
goto P_0c07a910;
P_0c07a910: /* original 65e3, guest PC 0x0c07a910 */
if(!s->budget--) { s->failed_pc=0x0c07a910u; return 0; }
r[5]=r[14];
goto P_0c07a912;
P_0c07a912: /* original bf69, guest PC 0x0c07a912 */
if(!s->budget--) { s->failed_pc=0x0c07a912u; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a916u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a916u) { target=s->pc; goto dispatch; }
goto P_0c07a916;
P_0c07a914: /* original 64b3, guest PC 0x0c07a914 */
if(!s->budget--) { s->failed_pc=0x0c07a914u; return 0; }
r[4]=r[11];
goto P_0c07a916;
P_0c07a916: /* original 4c0b, guest PC 0x0c07a916 */
if(!s->budget--) { s->failed_pc=0x0c07a916u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a91au;
r[4]=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a91au) { target=s->pc; goto dispatch; }
goto P_0c07a91a;
P_0c07a918: /* original e413, guest PC 0x0c07a918 */
if(!s->budget--) { s->failed_pc=0x0c07a918u; return 0; }
r[4]=0x00000013u;
goto P_0c07a91a;
P_0c07a91a: /* original 64b3, guest PC 0x0c07a91a */
if(!s->budget--) { s->failed_pc=0x0c07a91au; return 0; }
r[4]=r[11];
goto P_0c07a91c;
P_0c07a91c: /* original 65e3, guest PC 0x0c07a91c */
if(!s->budget--) { s->failed_pc=0x0c07a91cu; return 0; }
r[5]=r[14];
goto P_0c07a91e;
P_0c07a91e: /* original bf63, guest PC 0x0c07a91e */
if(!s->budget--) { s->failed_pc=0x0c07a91eu; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a922u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a922u) { target=s->pc; goto dispatch; }
goto P_0c07a922;
P_0c07a920: /* original 7410, guest PC 0x0c07a920 */
if(!s->budget--) { s->failed_pc=0x0c07a920u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a922;
P_0c07a922: /* original 4c0b, guest PC 0x0c07a922 */
if(!s->budget--) { s->failed_pc=0x0c07a922u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a926u;
r[4]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a926u) { target=s->pc; goto dispatch; }
goto P_0c07a926;
P_0c07a924: /* original e418, guest PC 0x0c07a924 */
if(!s->budget--) { s->failed_pc=0x0c07a924u; return 0; }
r[4]=0x00000018u;
goto P_0c07a926;
P_0c07a926: /* original 64b3, guest PC 0x0c07a926 */
if(!s->budget--) { s->failed_pc=0x0c07a926u; return 0; }
r[4]=r[11];
goto P_0c07a928;
P_0c07a928: /* original 65e3, guest PC 0x0c07a928 */
if(!s->budget--) { s->failed_pc=0x0c07a928u; return 0; }
r[5]=r[14];
goto P_0c07a92a;
P_0c07a92a: /* original bf5d, guest PC 0x0c07a92a */
if(!s->budget--) { s->failed_pc=0x0c07a92au; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a92eu;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a92eu) { target=s->pc; goto dispatch; }
goto P_0c07a92e;
P_0c07a92c: /* original 7420, guest PC 0x0c07a92c */
if(!s->budget--) { s->failed_pc=0x0c07a92cu; return 0; }
r[4]+=0x00000020u;
goto P_0c07a92e;
P_0c07a92e: /* original e313, guest PC 0x0c07a92e */
if(!s->budget--) { s->failed_pc=0x0c07a92eu; return 0; }
r[3]=0x00000013u;
goto P_0c07a930;
P_0c07a930: /* original e026, guest PC 0x0c07a930 */
if(!s->budget--) { s->failed_pc=0x0c07a930u; return 0; }
r[0]=0x00000026u;
goto P_0c07a932;
P_0c07a932: /* original 0d35, guest PC 0x0c07a932 */
if(!s->budget--) { s->failed_pc=0x0c07a932u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07a934;
P_0c07a934: /* original e223, guest PC 0x0c07a934 */
if(!s->budget--) { s->failed_pc=0x0c07a934u; return 0; }
r[2]=0x00000023u;
goto P_0c07a936;
P_0c07a936: /* original e046, guest PC 0x0c07a936 */
if(!s->budget--) { s->failed_pc=0x0c07a936u; return 0; }
r[0]=0x00000046u;
goto P_0c07a938;
P_0c07a938: /* original 0d25, guest PC 0x0c07a938 */
if(!s->budget--) { s->failed_pc=0x0c07a938u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a93a;
P_0c07a93a: /* original e318, guest PC 0x0c07a93a */
if(!s->budget--) { s->failed_pc=0x0c07a93au; return 0; }
r[3]=0x00000018u;
goto P_0c07a93c;
P_0c07a93c: /* original e030, guest PC 0x0c07a93c */
if(!s->budget--) { s->failed_pc=0x0c07a93cu; return 0; }
r[0]=0x00000030u;
goto P_0c07a93e;
P_0c07a93e: /* original a037, guest PC 0x0c07a93e */
if(!s->budget--) { s->failed_pc=0x0c07a93eu; return 0; }
goto P_0c07a9b0;
P_0c07a940: /* original 0009, guest PC 0x0c07a940 */
if(!s->budget--) { s->failed_pc=0x0c07a940u; return 0; }
goto P_0c07a942;
P_0c07a942: /* original 880e, guest PC 0x0c07a942 */
if(!s->budget--) { s->failed_pc=0x0c07a942u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c07a944;
P_0c07a944: /* original 8b01, guest PC 0x0c07a944 */
if(!s->budget--) { s->failed_pc=0x0c07a944u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a94a; }
goto P_0c07a946;
P_0c07a946: /* original a004, guest PC 0x0c07a946 */
if(!s->budget--) { s->failed_pc=0x0c07a946u; return 0; }
r[4]=0x0000000eu;
goto P_0c07a952;
P_0c07a948: /* original e40e, guest PC 0x0c07a948 */
if(!s->budget--) { s->failed_pc=0x0c07a948u; return 0; }
r[4]=0x0000000eu;
goto P_0c07a94a;
P_0c07a94a: /* original 60b3, guest PC 0x0c07a94a */
if(!s->budget--) { s->failed_pc=0x0c07a94au; return 0; }
r[0]=r[11];
goto P_0c07a94c;
P_0c07a94c: /* original 881b, guest PC 0x0c07a94c */
if(!s->budget--) { s->failed_pc=0x0c07a94cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c07a94e;
P_0c07a94e: /* original 8b07, guest PC 0x0c07a94e */
if(!s->budget--) { s->failed_pc=0x0c07a94eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a960; }
goto P_0c07a950;
P_0c07a950: /* original e41b, guest PC 0x0c07a950 */
if(!s->budget--) { s->failed_pc=0x0c07a950u; return 0; }
r[4]=0x0000001bu;
goto P_0c07a952;
P_0c07a952: /* original 4c0b, guest PC 0x0c07a952 */
if(!s->budget--) { s->failed_pc=0x0c07a952u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a956u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a956u) { target=s->pc; goto dispatch; }
goto P_0c07a956;
P_0c07a954: /* original 0009, guest PC 0x0c07a954 */
if(!s->budget--) { s->failed_pc=0x0c07a954u; return 0; }
goto P_0c07a956;
P_0c07a956: /* original 65e3, guest PC 0x0c07a956 */
if(!s->budget--) { s->failed_pc=0x0c07a956u; return 0; }
r[5]=r[14];
goto P_0c07a958;
P_0c07a958: /* original bf55, guest PC 0x0c07a958 */
if(!s->budget--) { s->failed_pc=0x0c07a958u; return 0; }
target=0x0c07a806u; r[16]=code_base|0x0c07a95cu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a95cu) { target=s->pc; goto dispatch; }
goto P_0c07a95c;
P_0c07a95a: /* original 6493, guest PC 0x0c07a95a */
if(!s->budget--) { s->failed_pc=0x0c07a95au; return 0; }
r[4]=r[9];
goto P_0c07a95c;
P_0c07a95c: /* original a05d, guest PC 0x0c07a95c */
if(!s->budget--) { s->failed_pc=0x0c07a95cu; return 0; }
goto P_0c07aa1a;
P_0c07a95e: /* original 0009, guest PC 0x0c07a95e */
if(!s->budget--) { s->failed_pc=0x0c07a95eu; return 0; }
goto P_0c07a960;
P_0c07a960: /* original 8814, guest PC 0x0c07a960 */
if(!s->budget--) { s->failed_pc=0x0c07a960u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c07a962;
P_0c07a962: /* original 8b10, guest PC 0x0c07a962 */
if(!s->budget--) { s->failed_pc=0x0c07a962u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a986; }
goto P_0c07a964;
P_0c07a964: /* original 4c0b, guest PC 0x0c07a964 */
if(!s->budget--) { s->failed_pc=0x0c07a964u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a968u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a968u) { target=s->pc; goto dispatch; }
goto P_0c07a968;
P_0c07a966: /* original e414, guest PC 0x0c07a966 */
if(!s->budget--) { s->failed_pc=0x0c07a966u; return 0; }
r[4]=0x00000014u;
goto P_0c07a968;
P_0c07a968: /* original d41f, guest PC 0x0c07a968 */
if(!s->budget--) { s->failed_pc=0x0c07a968u; return 0; }
r[4]=read(ram,0x0c07a9e8u,4);
goto P_0c07a96a;
P_0c07a96a: /* original bf3d, guest PC 0x0c07a96a */
if(!s->budget--) { s->failed_pc=0x0c07a96au; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a96eu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a96eu) { target=s->pc; goto dispatch; }
goto P_0c07a96e;
P_0c07a96c: /* original 65e3, guest PC 0x0c07a96c */
if(!s->budget--) { s->failed_pc=0x0c07a96cu; return 0; }
r[5]=r[14];
goto P_0c07a96e;
P_0c07a96e: /* original 4c0b, guest PC 0x0c07a96e */
if(!s->budget--) { s->failed_pc=0x0c07a96eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a972u;
r[4]=0x00000022u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a972u) { target=s->pc; goto dispatch; }
goto P_0c07a972;
P_0c07a970: /* original e422, guest PC 0x0c07a970 */
if(!s->budget--) { s->failed_pc=0x0c07a970u; return 0; }
r[4]=0x00000022u;
goto P_0c07a972;
P_0c07a972: /* original d41e, guest PC 0x0c07a972 */
if(!s->budget--) { s->failed_pc=0x0c07a972u; return 0; }
r[4]=read(ram,0x0c07a9ecu,4);
goto P_0c07a974;
P_0c07a974: /* original bf38, guest PC 0x0c07a974 */
if(!s->budget--) { s->failed_pc=0x0c07a974u; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a978u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a978u) { target=s->pc; goto dispatch; }
goto P_0c07a978;
P_0c07a976: /* original 65e3, guest PC 0x0c07a976 */
if(!s->budget--) { s->failed_pc=0x0c07a976u; return 0; }
r[5]=r[14];
goto P_0c07a978;
P_0c07a978: /* original e214, guest PC 0x0c07a978 */
if(!s->budget--) { s->failed_pc=0x0c07a978u; return 0; }
r[2]=0x00000014u;
goto P_0c07a97a;
P_0c07a97a: /* original e028, guest PC 0x0c07a97a */
if(!s->budget--) { s->failed_pc=0x0c07a97au; return 0; }
r[0]=0x00000028u;
goto P_0c07a97c;
P_0c07a97c: /* original 0d25, guest PC 0x0c07a97c */
if(!s->budget--) { s->failed_pc=0x0c07a97cu; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a97e;
P_0c07a97e: /* original e322, guest PC 0x0c07a97e */
if(!s->budget--) { s->failed_pc=0x0c07a97eu; return 0; }
r[3]=0x00000022u;
goto P_0c07a980;
P_0c07a980: /* original e044, guest PC 0x0c07a980 */
if(!s->budget--) { s->failed_pc=0x0c07a980u; return 0; }
r[0]=0x00000044u;
goto P_0c07a982;
P_0c07a982: /* original a015, guest PC 0x0c07a982 */
if(!s->budget--) { s->failed_pc=0x0c07a982u; return 0; }
goto P_0c07a9b0;
P_0c07a984: /* original 0009, guest PC 0x0c07a984 */
if(!s->budget--) { s->failed_pc=0x0c07a984u; return 0; }
goto P_0c07a986;
P_0c07a986: /* original 60b3, guest PC 0x0c07a986 */
if(!s->budget--) { s->failed_pc=0x0c07a986u; return 0; }
r[0]=r[11];
goto P_0c07a988;
P_0c07a988: /* original 8816, guest PC 0x0c07a988 */
if(!s->budget--) { s->failed_pc=0x0c07a988u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c07a98a;
P_0c07a98a: /* original 8b08, guest PC 0x0c07a98a */
if(!s->budget--) { s->failed_pc=0x0c07a98au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a99e; }
goto P_0c07a98c;
P_0c07a98c: /* original 4c0b, guest PC 0x0c07a98c */
if(!s->budget--) { s->failed_pc=0x0c07a98cu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a990u;
r[4]=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a990u) { target=s->pc; goto dispatch; }
goto P_0c07a990;
P_0c07a98e: /* original e416, guest PC 0x0c07a98e */
if(!s->budget--) { s->failed_pc=0x0c07a98eu; return 0; }
r[4]=0x00000016u;
goto P_0c07a990;
P_0c07a990: /* original d417, guest PC 0x0c07a990 */
if(!s->budget--) { s->failed_pc=0x0c07a990u; return 0; }
r[4]=read(ram,0x0c07a9f0u,4);
goto P_0c07a992;
P_0c07a992: /* original bf29, guest PC 0x0c07a992 */
if(!s->budget--) { s->failed_pc=0x0c07a992u; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a996u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a996u) { target=s->pc; goto dispatch; }
goto P_0c07a996;
P_0c07a994: /* original 65e3, guest PC 0x0c07a994 */
if(!s->budget--) { s->failed_pc=0x0c07a994u; return 0; }
r[5]=r[14];
goto P_0c07a996;
P_0c07a996: /* original e316, guest PC 0x0c07a996 */
if(!s->budget--) { s->failed_pc=0x0c07a996u; return 0; }
r[3]=0x00000016u;
goto P_0c07a998;
P_0c07a998: /* original e02c, guest PC 0x0c07a998 */
if(!s->budget--) { s->failed_pc=0x0c07a998u; return 0; }
r[0]=0x0000002cu;
goto P_0c07a99a;
P_0c07a99a: /* original a009, guest PC 0x0c07a99a */
if(!s->budget--) { s->failed_pc=0x0c07a99au; return 0; }
goto P_0c07a9b0;
P_0c07a99c: /* original 0009, guest PC 0x0c07a99c */
if(!s->budget--) { s->failed_pc=0x0c07a99cu; return 0; }
goto P_0c07a99e;
P_0c07a99e: /* original 8817, guest PC 0x0c07a99e */
if(!s->budget--) { s->failed_pc=0x0c07a99eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c07a9a0;
P_0c07a9a0: /* original 8b2a, guest PC 0x0c07a9a0 */
if(!s->budget--) { s->failed_pc=0x0c07a9a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a9f8; }
goto P_0c07a9a2;
P_0c07a9a2: /* original 4c0b, guest PC 0x0c07a9a2 */
if(!s->budget--) { s->failed_pc=0x0c07a9a2u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a9a6u;
r[4]=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a9a6u) { target=s->pc; goto dispatch; }
goto P_0c07a9a6;
P_0c07a9a4: /* original e417, guest PC 0x0c07a9a4 */
if(!s->budget--) { s->failed_pc=0x0c07a9a4u; return 0; }
r[4]=0x00000017u;
goto P_0c07a9a6;
P_0c07a9a6: /* original d413, guest PC 0x0c07a9a6 */
if(!s->budget--) { s->failed_pc=0x0c07a9a6u; return 0; }
r[4]=read(ram,0x0c07a9f4u,4);
goto P_0c07a9a8;
P_0c07a9a8: /* original bf1e, guest PC 0x0c07a9a8 */
if(!s->budget--) { s->failed_pc=0x0c07a9a8u; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07a9acu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a9acu) { target=s->pc; goto dispatch; }
goto P_0c07a9ac;
P_0c07a9aa: /* original 65e3, guest PC 0x0c07a9aa */
if(!s->budget--) { s->failed_pc=0x0c07a9aau; return 0; }
r[5]=r[14];
goto P_0c07a9ac;
P_0c07a9ac: /* original e317, guest PC 0x0c07a9ac */
if(!s->budget--) { s->failed_pc=0x0c07a9acu; return 0; }
r[3]=0x00000017u;
goto P_0c07a9ae;
P_0c07a9ae: /* original e02e, guest PC 0x0c07a9ae */
if(!s->budget--) { s->failed_pc=0x0c07a9aeu; return 0; }
r[0]=0x0000002eu;
goto P_0c07a9b0;
P_0c07a9b0: /* original a036, guest PC 0x0c07a9b0 */
if(!s->budget--) { s->failed_pc=0x0c07a9b0u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07aa20;
P_0c07a9b2: /* original 0d35, guest PC 0x0c07a9b2 */
if(!s->budget--) { s->failed_pc=0x0c07a9b2u; return 0; }
write(ram,r[13]+r[0],r[3],2);
return vf3_matrix_family(0x0c07a9b4u,s,ram);
P_0c07a9f8: /* original 60b3, guest PC 0x0c07a9f8 */
if(!s->budget--) { s->failed_pc=0x0c07a9f8u; return 0; }
r[0]=r[11];
goto P_0c07a9fa;
P_0c07a9fa: /* original 880c, guest PC 0x0c07a9fa */
if(!s->budget--) { s->failed_pc=0x0c07a9fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c07a9fc;
P_0c07a9fc: /* original 8902, guest PC 0x0c07a9fc */
if(!s->budget--) { s->failed_pc=0x0c07a9fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07aa04; }
goto P_0c07a9fe;
P_0c07a9fe: /* original 60b3, guest PC 0x0c07a9fe */
if(!s->budget--) { s->failed_pc=0x0c07a9feu; return 0; }
r[0]=r[11];
goto P_0c07aa00;
P_0c07aa00: /* original 880d, guest PC 0x0c07aa00 */
if(!s->budget--) { s->failed_pc=0x0c07aa00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c07aa02;
P_0c07aa02: /* original 8b08, guest PC 0x0c07aa02 */
if(!s->budget--) { s->failed_pc=0x0c07aa02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07aa16; }
goto P_0c07aa04;
P_0c07aa04: /* original 4c0b, guest PC 0x0c07aa04 */
if(!s->budget--) { s->failed_pc=0x0c07aa04u; return 0; }
target=r[12];
r[16]=code_base|0x0c07aa08u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aa08u) { target=s->pc; goto dispatch; }
goto P_0c07aa08;
P_0c07aa06: /* original 64b3, guest PC 0x0c07aa06 */
if(!s->budget--) { s->failed_pc=0x0c07aa06u; return 0; }
r[4]=r[11];
goto P_0c07aa08;
P_0c07aa08: /* original 65e3, guest PC 0x0c07aa08 */
if(!s->budget--) { s->failed_pc=0x0c07aa08u; return 0; }
r[5]=r[14];
goto P_0c07aa0a;
P_0c07aa0a: /* original beed, guest PC 0x0c07aa0a */
if(!s->budget--) { s->failed_pc=0x0c07aa0au; return 0; }
target=0x0c07a7e8u; r[16]=code_base|0x0c07aa0eu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aa0eu) { target=s->pc; goto dispatch; }
goto P_0c07aa0e;
P_0c07aa0c: /* original 6493, guest PC 0x0c07aa0c */
if(!s->budget--) { s->failed_pc=0x0c07aa0cu; return 0; }
r[4]=r[9];
goto P_0c07aa0e;
P_0c07aa0e: /* original 60ad, guest PC 0x0c07aa0e */
if(!s->budget--) { s->failed_pc=0x0c07aa0eu; return 0; }
r[0]=r[10]&65535u;
goto P_0c07aa10;
P_0c07aa10: /* original 4000, guest PC 0x0c07aa10 */
if(!s->budget--) { s->failed_pc=0x0c07aa10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07aa12;
P_0c07aa12: /* original a005, guest PC 0x0c07aa12 */
if(!s->budget--) { s->failed_pc=0x0c07aa12u; return 0; }
write(ram,r[13]+r[0],r[10],2);
goto P_0c07aa20;
P_0c07aa14: /* original 0da5, guest PC 0x0c07aa14 */
if(!s->budget--) { s->failed_pc=0x0c07aa14u; return 0; }
write(ram,r[13]+r[0],r[10],2);
goto P_0c07aa16;
P_0c07aa16: /* original bef6, guest PC 0x0c07aa16 */
if(!s->budget--) { s->failed_pc=0x0c07aa16u; return 0; }
target=0x0c07a806u; r[16]=code_base|0x0c07aa1au;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aa1au) { target=s->pc; goto dispatch; }
goto P_0c07aa1a;
P_0c07aa18: /* original 65e3, guest PC 0x0c07aa18 */
if(!s->budget--) { s->failed_pc=0x0c07aa18u; return 0; }
r[5]=r[14];
goto P_0c07aa1a;
P_0c07aa1a: /* original 60ad, guest PC 0x0c07aa1a */
if(!s->budget--) { s->failed_pc=0x0c07aa1au; return 0; }
r[0]=r[10]&65535u;
goto P_0c07aa1c;
P_0c07aa1c: /* original 4000, guest PC 0x0c07aa1c */
if(!s->budget--) { s->failed_pc=0x0c07aa1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07aa1e;
P_0c07aa1e: /* original 0db5, guest PC 0x0c07aa1e */
if(!s->budget--) { s->failed_pc=0x0c07aa1eu; return 0; }
write(ram,r[13]+r[0],r[11],2);
goto P_0c07aa20;
P_0c07aa20: /* original 4f26, guest PC 0x0c07aa20 */
if(!s->budget--) { s->failed_pc=0x0c07aa20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aa22;
P_0c07aa22: /* original 69f6, guest PC 0x0c07aa22 */
if(!s->budget--) { s->failed_pc=0x0c07aa22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07aa24;
P_0c07aa24: /* original 6af6, guest PC 0x0c07aa24 */
if(!s->budget--) { s->failed_pc=0x0c07aa24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07aa26;
P_0c07aa26: /* original 6bf6, guest PC 0x0c07aa26 */
if(!s->budget--) { s->failed_pc=0x0c07aa26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07aa28;
P_0c07aa28: /* original 6cf6, guest PC 0x0c07aa28 */
if(!s->budget--) { s->failed_pc=0x0c07aa28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07aa2a;
P_0c07aa2a: /* original 6df6, guest PC 0x0c07aa2a */
if(!s->budget--) { s->failed_pc=0x0c07aa2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07aa2c;
P_0c07aa2c: /* original 000b, guest PC 0x0c07aa2c */
if(!s->budget--) { s->failed_pc=0x0c07aa2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07aa2e: /* original 6ef6, guest PC 0x0c07aa2e */
if(!s->budget--) { s->failed_pc=0x0c07aa2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07aa30u,s,ram);
P_0c099d74: /* original 4f22, guest PC 0x0c099d74 */
if(!s->budget--) { s->failed_pc=0x0c099d74u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099d76;
P_0c099d76: /* original d318, guest PC 0x0c099d76 */
if(!s->budget--) { s->failed_pc=0x0c099d76u; return 0; }
r[3]=read(ram,0x0c099dd8u,4);
goto P_0c099d78;
P_0c099d78: /* original de10, guest PC 0x0c099d78 */
if(!s->budget--) { s->failed_pc=0x0c099d78u; return 0; }
r[14]=read(ram,0x0c099dbcu,4);
goto P_0c099d7a;
P_0c099d7a: /* original 7ff8, guest PC 0x0c099d7a */
if(!s->budget--) { s->failed_pc=0x0c099d7au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c099d7c;
P_0c099d7c: /* original dd10, guest PC 0x0c099d7c */
if(!s->budget--) { s->failed_pc=0x0c099d7cu; return 0; }
r[13]=read(ram,0x0c099dc0u,4);
goto P_0c099d7e;
P_0c099d7e: /* original 1f31, guest PC 0x0c099d7e */
if(!s->budget--) { s->failed_pc=0x0c099d7eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c099d80;
P_0c099d80: /* original d216, guest PC 0x0c099d80 */
if(!s->budget--) { s->failed_pc=0x0c099d80u; return 0; }
r[2]=read(ram,0x0c099ddcu,4);
goto P_0c099d82;
P_0c099d82: /* original 2f22, guest PC 0x0c099d82 */
if(!s->budget--) { s->failed_pc=0x0c099d82u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c099d84;
P_0c099d84: /* original db11, guest PC 0x0c099d84 */
if(!s->budget--) { s->failed_pc=0x0c099d84u; return 0; }
r[11]=read(ram,0x0c099dccu,4);
goto P_0c099d86;
P_0c099d86: /* original 03be, guest PC 0x0c099d86 */
if(!s->budget--) { s->failed_pc=0x0c099d86u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c099d88;
P_0c099d88: /* original 54b4, guest PC 0x0c099d88 */
if(!s->budget--) { s->failed_pc=0x0c099d88u; return 0; }
r[4]=read(ram,r[11]+16,4);
goto P_0c099d8a;
P_0c099d8a: /* original 6232, guest PC 0x0c099d8a */
if(!s->budget--) { s->failed_pc=0x0c099d8au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c099d8c;
P_0c099d8c: /* original 2268, guest PC 0x0c099d8c */
if(!s->budget--) { s->failed_pc=0x0c099d8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c099d8e;
P_0c099d8e: /* original 8d27, guest PC 0x0c099d8e */
if(!s->budget--) { s->failed_pc=0x0c099d8eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[11]+20,4);
if(cond) { goto P_0c099de0; }
goto P_0c099d92;
P_0c099d90: /* original 55b5, guest PC 0x0c099d90 */
if(!s->budget--) { s->failed_pc=0x0c099d90u; return 0; }
r[5]=read(ram,r[11]+20,4);
goto P_0c099d92;
P_0c099d92: /* original e054, guest PC 0x0c099d92 */
if(!s->budget--) { s->failed_pc=0x0c099d92u; return 0; }
r[0]=0x00000054u;
goto P_0c099d94;
P_0c099d94: /* original 054e, guest PC 0x0c099d94 */
if(!s->budget--) { s->failed_pc=0x0c099d94u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c099d96;
P_0c099d96: /* original e022, guest PC 0x0c099d96 */
if(!s->budget--) { s->failed_pc=0x0c099d96u; return 0; }
r[0]=0x00000022u;
goto P_0c099d98;
P_0c099d98: /* original 035d, guest PC 0x0c099d98 */
if(!s->budget--) { s->failed_pc=0x0c099d98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c099d9a;
P_0c099d9a: /* original 9004, guest PC 0x0c099d9a */
if(!s->budget--) { s->failed_pc=0x0c099d9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099da6u,2);
goto P_0c099d9c;
P_0c099d9c: /* original a02b, guest PC 0x0c099d9c */
if(!s->budget--) { s->failed_pc=0x0c099d9cu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c099df6;
P_0c099d9e: /* original 0435, guest PC 0x0c099d9e */
if(!s->budget--) { s->failed_pc=0x0c099d9eu; return 0; }
write(ram,r[4]+r[0],r[3],2);
return vf3_matrix_family(0x0c099da0u,s,ram);
P_0c099de0: /* original e064, guest PC 0x0c099de0 */
if(!s->budget--) { s->failed_pc=0x0c099de0u; return 0; }
r[0]=0x00000064u;
goto P_0c099de2;
P_0c099de2: /* original 01be, guest PC 0x0c099de2 */
if(!s->budget--) { s->failed_pc=0x0c099de2u; return 0; }
r[1]=read(ram,r[11]+r[0],4);
goto P_0c099de4;
P_0c099de4: /* original 6312, guest PC 0x0c099de4 */
if(!s->budget--) { s->failed_pc=0x0c099de4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c099de6;
P_0c099de6: /* original 2638, guest PC 0x0c099de6 */
if(!s->budget--) { s->failed_pc=0x0c099de6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c099de8;
P_0c099de8: /* original 8905, guest PC 0x0c099de8 */
if(!s->budget--) { s->failed_pc=0x0c099de8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099df6; }
goto P_0c099dea;
P_0c099dea: /* original e054, guest PC 0x0c099dea */
if(!s->budget--) { s->failed_pc=0x0c099deau; return 0; }
r[0]=0x00000054u;
goto P_0c099dec;
P_0c099dec: /* original 045e, guest PC 0x0c099dec */
if(!s->budget--) { s->failed_pc=0x0c099decu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c099dee;
P_0c099dee: /* original e022, guest PC 0x0c099dee */
if(!s->budget--) { s->failed_pc=0x0c099deeu; return 0; }
r[0]=0x00000022u;
goto P_0c099df0;
P_0c099df0: /* original 034d, guest PC 0x0c099df0 */
if(!s->budget--) { s->failed_pc=0x0c099df0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c099df2;
P_0c099df2: /* original 9071, guest PC 0x0c099df2 */
if(!s->budget--) { s->failed_pc=0x0c099df2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ed8u,2);
goto P_0c099df4;
P_0c099df4: /* original 0535, guest PC 0x0c099df4 */
if(!s->budget--) { s->failed_pc=0x0c099df4u; return 0; }
write(ram,r[5]+r[0],r[3],2);
goto P_0c099df6;
P_0c099df6: /* original d33c, guest PC 0x0c099df6 */
if(!s->budget--) { s->failed_pc=0x0c099df6u; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099df8;
P_0c099df8: /* original e060, guest PC 0x0c099df8 */
if(!s->budget--) { s->failed_pc=0x0c099df8u; return 0; }
r[0]=0x00000060u;
goto P_0c099dfa;
P_0c099dfa: /* original 430b, guest PC 0x0c099dfa */
if(!s->budget--) { s->failed_pc=0x0c099dfau; return 0; }
target=r[3];
r[16]=code_base|0x0c099dfeu;
r[4]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099dfeu) { target=s->pc; goto dispatch; }
goto P_0c099dfe;
P_0c099dfc: /* original 04be, guest PC 0x0c099dfc */
if(!s->budget--) { s->failed_pc=0x0c099dfcu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099dfe;
P_0c099dfe: /* original d33a, guest PC 0x0c099dfe */
if(!s->budget--) { s->failed_pc=0x0c099dfeu; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099e00;
P_0c099e00: /* original e064, guest PC 0x0c099e00 */
if(!s->budget--) { s->failed_pc=0x0c099e00u; return 0; }
r[0]=0x00000064u;
goto P_0c099e02;
P_0c099e02: /* original 430b, guest PC 0x0c099e02 */
if(!s->budget--) { s->failed_pc=0x0c099e02u; return 0; }
target=r[3];
r[16]=code_base|0x0c099e06u;
r[4]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099e06u) { target=s->pc; goto dispatch; }
goto P_0c099e06;
P_0c099e04: /* original 04be, guest PC 0x0c099e04 */
if(!s->budget--) { s->failed_pc=0x0c099e04u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099e06;
P_0c099e06: /* original d338, guest PC 0x0c099e06 */
if(!s->budget--) { s->failed_pc=0x0c099e06u; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099e08;
P_0c099e08: /* original e068, guest PC 0x0c099e08 */
if(!s->budget--) { s->failed_pc=0x0c099e08u; return 0; }
r[0]=0x00000068u;
goto P_0c099e0a;
P_0c099e0a: /* original 430b, guest PC 0x0c099e0a */
if(!s->budget--) { s->failed_pc=0x0c099e0au; return 0; }
target=r[3];
r[16]=code_base|0x0c099e0eu;
r[4]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099e0eu) { target=s->pc; goto dispatch; }
goto P_0c099e0e;
P_0c099e0c: /* original 04be, guest PC 0x0c099e0c */
if(!s->budget--) { s->failed_pc=0x0c099e0cu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099e0e;
P_0c099e0e: /* original d336, guest PC 0x0c099e0e */
if(!s->budget--) { s->failed_pc=0x0c099e0eu; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099e10;
P_0c099e10: /* original e06c, guest PC 0x0c099e10 */
if(!s->budget--) { s->failed_pc=0x0c099e10u; return 0; }
r[0]=0x0000006cu;
goto P_0c099e12;
P_0c099e12: /* original 430b, guest PC 0x0c099e12 */
if(!s->budget--) { s->failed_pc=0x0c099e12u; return 0; }
target=r[3];
r[16]=code_base|0x0c099e16u;
r[4]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099e16u) { target=s->pc; goto dispatch; }
goto P_0c099e16;
P_0c099e14: /* original 04be, guest PC 0x0c099e14 */
if(!s->budget--) { s->failed_pc=0x0c099e14u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099e16;
P_0c099e16: /* original 59e2, guest PC 0x0c099e16 */
if(!s->budget--) { s->failed_pc=0x0c099e16u; return 0; }
r[9]=read(ram,r[14]+8,4);
goto P_0c099e18;
P_0c099e18: /* original e210, guest PC 0x0c099e18 */
if(!s->budget--) { s->failed_pc=0x0c099e18u; return 0; }
r[2]=0x00000010u;
goto P_0c099e1a;
P_0c099e1a: /* original 2298, guest PC 0x0c099e1a */
if(!s->budget--) { s->failed_pc=0x0c099e1au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c099e1c;
P_0c099e1c: /* original 8d02, guest PC 0x0c099e1c */
if(!s->budget--) { s->failed_pc=0x0c099e1cu; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c099e24; }
goto P_0c099e20;
P_0c099e1e: /* original ec00, guest PC 0x0c099e1e */
if(!s->budget--) { s->failed_pc=0x0c099e1eu; return 0; }
r[12]=0x00000000u;
goto P_0c099e20;
P_0c099e20: /* original a102, guest PC 0x0c099e20 */
if(!s->budget--) { s->failed_pc=0x0c099e20u; return 0; }
goto P_0c09a028;
P_0c099e22: /* original 0009, guest PC 0x0c099e22 */
if(!s->budget--) { s->failed_pc=0x0c099e22u; return 0; }
goto P_0c099e24;
P_0c099e24: /* original d331, guest PC 0x0c099e24 */
if(!s->budget--) { s->failed_pc=0x0c099e24u; return 0; }
r[3]=read(ram,0x0c099eecu,4);
goto P_0c099e26;
P_0c099e26: /* original 2398, guest PC 0x0c099e26 */
if(!s->budget--) { s->failed_pc=0x0c099e26u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c099e28;
P_0c099e28: /* original 8f02, guest PC 0x0c099e28 */
if(!s->budget--) { s->failed_pc=0x0c099e28u; return 0; }
cond=r[17]&1u;
r[8]=0x00000004u;
if(!cond) { goto P_0c099e30; }
goto P_0c099e2c;
P_0c099e2a: /* original e804, guest PC 0x0c099e2a */
if(!s->budget--) { s->failed_pc=0x0c099e2au; return 0; }
r[8]=0x00000004u;
goto P_0c099e2c;
P_0c099e2c: /* original a0dc, guest PC 0x0c099e2c */
if(!s->budget--) { s->failed_pc=0x0c099e2cu; return 0; }
goto P_0c099fe8;
P_0c099e2e: /* original 0009, guest PC 0x0c099e2e */
if(!s->budget--) { s->failed_pc=0x0c099e2eu; return 0; }
goto P_0c099e30;
P_0c099e30: /* original e029, guest PC 0x0c099e30 */
if(!s->budget--) { s->failed_pc=0x0c099e30u; return 0; }
r[0]=0x00000029u;
goto P_0c099e32;
P_0c099e32: /* original 0aec, guest PC 0x0c099e32 */
if(!s->budget--) { s->failed_pc=0x0c099e32u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e34;
P_0c099e34: /* original 60ac, guest PC 0x0c099e34 */
if(!s->budget--) { s->failed_pc=0x0c099e34u; return 0; }
r[0]=r[10]&255u;
goto P_0c099e36;
P_0c099e36: /* original 8803, guest PC 0x0c099e36 */
if(!s->budget--) { s->failed_pc=0x0c099e36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099e38;
P_0c099e38: /* original 8d2c, guest PC 0x0c099e38 */
if(!s->budget--) { s->failed_pc=0x0c099e38u; return 0; }
cond=r[17]&1u;
r[10]=r[0];
if(cond) { goto P_0c099e94; }
goto P_0c099e3c;
P_0c099e3a: /* original 6a03, guest PC 0x0c099e3a */
if(!s->budget--) { s->failed_pc=0x0c099e3au; return 0; }
r[10]=r[0];
goto P_0c099e3c;
P_0c099e3c: /* original 2aa8, guest PC 0x0c099e3c */
if(!s->budget--) { s->failed_pc=0x0c099e3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c099e3e;
P_0c099e3e: /* original 8b01, guest PC 0x0c099e3e */
if(!s->budget--) { s->failed_pc=0x0c099e3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099e44; }
goto P_0c099e40;
P_0c099e40: /* original a0c2, guest PC 0x0c099e40 */
if(!s->budget--) { s->failed_pc=0x0c099e40u; return 0; }
goto P_0c099fc8;
P_0c099e42: /* original 0009, guest PC 0x0c099e42 */
if(!s->budget--) { s->failed_pc=0x0c099e42u; return 0; }
goto P_0c099e44;
P_0c099e44: /* original e02b, guest PC 0x0c099e44 */
if(!s->budget--) { s->failed_pc=0x0c099e44u; return 0; }
r[0]=0x0000002bu;
goto P_0c099e46;
P_0c099e46: /* original 00ec, guest PC 0x0c099e46 */
if(!s->budget--) { s->failed_pc=0x0c099e46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e48;
P_0c099e48: /* original 8809, guest PC 0x0c099e48 */
if(!s->budget--) { s->failed_pc=0x0c099e48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c099e4a;
P_0c099e4a: /* original 8b01, guest PC 0x0c099e4a */
if(!s->budget--) { s->failed_pc=0x0c099e4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099e50; }
goto P_0c099e4c;
P_0c099e4c: /* original a0ec, guest PC 0x0c099e4c */
if(!s->budget--) { s->failed_pc=0x0c099e4cu; return 0; }
goto P_0c09a028;
P_0c099e4e: /* original 0009, guest PC 0x0c099e4e */
if(!s->budget--) { s->failed_pc=0x0c099e4eu; return 0; }
goto P_0c099e50;
P_0c099e50: /* original e01d, guest PC 0x0c099e50 */
if(!s->budget--) { s->failed_pc=0x0c099e50u; return 0; }
r[0]=0x0000001du;
goto P_0c099e52;
P_0c099e52: /* original 04ec, guest PC 0x0c099e52 */
if(!s->budget--) { s->failed_pc=0x0c099e52u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e54;
P_0c099e54: /* original 644c, guest PC 0x0c099e54 */
if(!s->budget--) { s->failed_pc=0x0c099e54u; return 0; }
r[4]=r[4]&255u;
goto P_0c099e56;
P_0c099e56: /* original 7401, guest PC 0x0c099e56 */
if(!s->budget--) { s->failed_pc=0x0c099e56u; return 0; }
r[4]+=0x00000001u;
goto P_0c099e58;
P_0c099e58: /* original 3a40, guest PC 0x0c099e58 */
if(!s->budget--) { s->failed_pc=0x0c099e58u; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[4])!=0);
goto P_0c099e5a;
P_0c099e5a: /* original 8901, guest PC 0x0c099e5a */
if(!s->budget--) { s->failed_pc=0x0c099e5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099e60; }
goto P_0c099e5c;
P_0c099e5c: /* original a0b4, guest PC 0x0c099e5c */
if(!s->budget--) { s->failed_pc=0x0c099e5cu; return 0; }
goto P_0c099fc8;
P_0c099e5e: /* original 0009, guest PC 0x0c099e5e */
if(!s->budget--) { s->failed_pc=0x0c099e5eu; return 0; }
goto P_0c099e60;
P_0c099e60: /* original e02b, guest PC 0x0c099e60 */
if(!s->budget--) { s->failed_pc=0x0c099e60u; return 0; }
r[0]=0x0000002bu;
goto P_0c099e62;
P_0c099e62: /* original 923a, guest PC 0x0c099e62 */
if(!s->budget--) { s->failed_pc=0x0c099e62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099edau,2);
goto P_0c099e64;
P_0c099e64: /* original 03ec, guest PC 0x0c099e64 */
if(!s->budget--) { s->failed_pc=0x0c099e64u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e66;
P_0c099e66: /* original 706d, guest PC 0x0c099e66 */
if(!s->budget--) { s->failed_pc=0x0c099e66u; return 0; }
r[0]+=0x0000006du;
goto P_0c099e68;
P_0c099e68: /* original 01de, guest PC 0x0c099e68 */
if(!s->budget--) { s->failed_pc=0x0c099e68u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c099e6a;
P_0c099e6a: /* original 32ec, guest PC 0x0c099e6a */
if(!s->budget--) { s->failed_pc=0x0c099e6au; return 0; }
r[2]+=r[14];
goto P_0c099e6c;
P_0c099e6c: /* original 73ff, guest PC 0x0c099e6c */
if(!s->budget--) { s->failed_pc=0x0c099e6cu; return 0; }
r[3]+=0xffffffffu;
goto P_0c099e6e;
P_0c099e6e: /* original 4308, guest PC 0x0c099e6e */
if(!s->budget--) { s->failed_pc=0x0c099e6eu; return 0; }
r[3]<<=2;
goto P_0c099e70;
P_0c099e70: /* original 332c, guest PC 0x0c099e70 */
if(!s->budget--) { s->failed_pc=0x0c099e70u; return 0; }
r[3]+=r[2];
goto P_0c099e72;
P_0c099e72: /* original 2312, guest PC 0x0c099e72 */
if(!s->budget--) { s->failed_pc=0x0c099e72u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c099e74;
P_0c099e74: /* original d31e, guest PC 0x0c099e74 */
if(!s->budget--) { s->failed_pc=0x0c099e74u; return 0; }
r[3]=read(ram,0x0c099ef0u,4);
goto P_0c099e76;
P_0c099e76: /* original 430b, guest PC 0x0c099e76 */
if(!s->budget--) { s->failed_pc=0x0c099e76u; return 0; }
target=r[3];
r[16]=code_base|0x0c099e7au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099e7au) { target=s->pc; goto dispatch; }
goto P_0c099e7a;
P_0c099e78: /* original 0009, guest PC 0x0c099e78 */
if(!s->budget--) { s->failed_pc=0x0c099e78u; return 0; }
goto P_0c099e7a;
P_0c099e7a: /* original e02b, guest PC 0x0c099e7a */
if(!s->budget--) { s->failed_pc=0x0c099e7au; return 0; }
r[0]=0x0000002bu;
goto P_0c099e7c;
P_0c099e7c: /* original 02ec, guest PC 0x0c099e7c */
if(!s->budget--) { s->failed_pc=0x0c099e7cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e7e;
P_0c099e7e: /* original 7201, guest PC 0x0c099e7e */
if(!s->budget--) { s->failed_pc=0x0c099e7eu; return 0; }
r[2]+=0x00000001u;
goto P_0c099e80;
P_0c099e80: /* original 0e24, guest PC 0x0c099e80 */
if(!s->budget--) { s->failed_pc=0x0c099e80u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c099e82;
P_0c099e82: /* original 54ed, guest PC 0x0c099e82 */
if(!s->budget--) { s->failed_pc=0x0c099e82u; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c099e84;
P_0c099e84: /* original 53ee, guest PC 0x0c099e84 */
if(!s->budget--) { s->failed_pc=0x0c099e84u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c099e86;
P_0c099e86: /* original 343c, guest PC 0x0c099e86 */
if(!s->budget--) { s->failed_pc=0x0c099e86u; return 0; }
r[4]+=r[3];
goto P_0c099e88;
P_0c099e88: /* original 1e4c, guest PC 0x0c099e88 */
if(!s->budget--) { s->failed_pc=0x0c099e88u; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c099e8a;
P_0c099e8a: /* original 1e4d, guest PC 0x0c099e8a */
if(!s->budget--) { s->failed_pc=0x0c099e8au; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c099e8c;
P_0c099e8c: /* original 1ece, guest PC 0x0c099e8c */
if(!s->budget--) { s->failed_pc=0x0c099e8cu; return 0; }
write(ram,r[14]+56,r[12],4);
goto P_0c099e8e;
P_0c099e8e: /* original 60c3, guest PC 0x0c099e8e */
if(!s->budget--) { s->failed_pc=0x0c099e8eu; return 0; }
r[0]=r[12];
goto P_0c099e90;
P_0c099e90: /* original a0ef, guest PC 0x0c099e90 */
if(!s->budget--) { s->failed_pc=0x0c099e90u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09a072;
P_0c099e92: /* original 80db, guest PC 0x0c099e92 */
if(!s->budget--) { s->failed_pc=0x0c099e92u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c099e94;
P_0c099e94: /* original 9022, guest PC 0x0c099e94 */
if(!s->budget--) { s->failed_pc=0x0c099e94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099edcu,2);
goto P_0c099e96;
P_0c099e96: /* original 02dc, guest PC 0x0c099e96 */
if(!s->budget--) { s->failed_pc=0x0c099e96u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c099e98;
P_0c099e98: /* original 2228, guest PC 0x0c099e98 */
if(!s->budget--) { s->failed_pc=0x0c099e98u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c099e9a;
P_0c099e9a: /* original 8901, guest PC 0x0c099e9a */
if(!s->budget--) { s->failed_pc=0x0c099e9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ea0; }
goto P_0c099e9c;
P_0c099e9c: /* original a0d3, guest PC 0x0c099e9c */
if(!s->budget--) { s->failed_pc=0x0c099e9cu; return 0; }
goto P_0c09a046;
P_0c099e9e: /* original 0009, guest PC 0x0c099e9e */
if(!s->budget--) { s->failed_pc=0x0c099e9eu; return 0; }
goto P_0c099ea0;
P_0c099ea0: /* original 901d, guest PC 0x0c099ea0 */
if(!s->budget--) { s->failed_pc=0x0c099ea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099edeu,2);
goto P_0c099ea2;
P_0c099ea2: /* original 02ec, guest PC 0x0c099ea2 */
if(!s->budget--) { s->failed_pc=0x0c099ea2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099ea4;
P_0c099ea4: /* original 901c, guest PC 0x0c099ea4 */
if(!s->budget--) { s->failed_pc=0x0c099ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ee0u,2);
goto P_0c099ea6;
P_0c099ea6: /* original 0e24, guest PC 0x0c099ea6 */
if(!s->budget--) { s->failed_pc=0x0c099ea6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c099ea8;
P_0c099ea8: /* original d312, guest PC 0x0c099ea8 */
if(!s->budget--) { s->failed_pc=0x0c099ea8u; return 0; }
r[3]=read(ram,0x0c099ef4u,4);
goto P_0c099eaa;
P_0c099eaa: /* original 64f2, guest PC 0x0c099eaa */
if(!s->budget--) { s->failed_pc=0x0c099eaau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c099eac;
P_0c099eac: /* original 430b, guest PC 0x0c099eac */
if(!s->budget--) { s->failed_pc=0x0c099eacu; return 0; }
target=r[3];
r[16]=code_base|0x0c099eb0u;
r[4]+=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099eb0u) { target=s->pc; goto dispatch; }
goto P_0c099eb0;
P_0c099eae: /* original 7413, guest PC 0x0c099eae */
if(!s->budget--) { s->failed_pc=0x0c099eaeu; return 0; }
r[4]+=0x00000013u;
goto P_0c099eb0;
P_0c099eb0: /* original 640c, guest PC 0x0c099eb0 */
if(!s->budget--) { s->failed_pc=0x0c099eb0u; return 0; }
r[4]=r[0]&255u;
goto P_0c099eb2;
P_0c099eb2: /* original 2448, guest PC 0x0c099eb2 */
if(!s->budget--) { s->failed_pc=0x0c099eb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099eb4;
P_0c099eb4: /* original 8905, guest PC 0x0c099eb4 */
if(!s->budget--) { s->failed_pc=0x0c099eb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ec2; }
goto P_0c099eb6;
P_0c099eb6: /* original 9014, guest PC 0x0c099eb6 */
if(!s->budget--) { s->failed_pc=0x0c099eb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ee2u,2);
goto P_0c099eb8;
P_0c099eb8: /* original 0aee, guest PC 0x0c099eb8 */
if(!s->budget--) { s->failed_pc=0x0c099eb8u; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c099eba;
P_0c099eba: /* original 3a43, guest PC 0x0c099eba */
if(!s->budget--) { s->failed_pc=0x0c099ebau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[4])!=0);
goto P_0c099ebc;
P_0c099ebc: /* original 8b01, guest PC 0x0c099ebc */
if(!s->budget--) { s->failed_pc=0x0c099ebcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099ec2; }
goto P_0c099ebe;
P_0c099ebe: /* original a0c2, guest PC 0x0c099ebe */
if(!s->budget--) { s->failed_pc=0x0c099ebeu; return 0; }
goto P_0c09a046;
P_0c099ec0: /* original 0009, guest PC 0x0c099ec0 */
if(!s->budget--) { s->failed_pc=0x0c099ec0u; return 0; }
goto P_0c099ec2;
P_0c099ec2: /* original 900f, guest PC 0x0c099ec2 */
if(!s->budget--) { s->failed_pc=0x0c099ec2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ee4u,2);
goto P_0c099ec4;
P_0c099ec4: /* original 00ec, guest PC 0x0c099ec4 */
if(!s->budget--) { s->failed_pc=0x0c099ec4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099ec6;
P_0c099ec6: /* original 8801, guest PC 0x0c099ec6 */
if(!s->budget--) { s->failed_pc=0x0c099ec6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c099ec8;
P_0c099ec8: /* original 891a, guest PC 0x0c099ec8 */
if(!s->budget--) { s->failed_pc=0x0c099ec8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f00; }
goto P_0c099eca;
P_0c099eca: /* original d30b, guest PC 0x0c099eca */
if(!s->budget--) { s->failed_pc=0x0c099ecau; return 0; }
r[3]=read(ram,0x0c099ef8u,4);
goto P_0c099ecc;
P_0c099ecc: /* original 2398, guest PC 0x0c099ecc */
if(!s->budget--) { s->failed_pc=0x0c099eccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c099ece;
P_0c099ece: /* original 8920, guest PC 0x0c099ece */
if(!s->budget--) { s->failed_pc=0x0c099eceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f12; }
goto P_0c099ed0;
P_0c099ed0: /* original d20a, guest PC 0x0c099ed0 */
if(!s->budget--) { s->failed_pc=0x0c099ed0u; return 0; }
r[2]=read(ram,0x0c099efcu,4);
goto P_0c099ed2;
P_0c099ed2: /* original 2929, guest PC 0x0c099ed2 */
if(!s->budget--) { s->failed_pc=0x0c099ed2u; return 0; }
r[9]&=r[2];
goto P_0c099ed4;
P_0c099ed4: /* original a01a, guest PC 0x0c099ed4 */
if(!s->budget--) { s->failed_pc=0x0c099ed4u; return 0; }
r[10]+=0xffffffffu;
goto P_0c099f0c;
P_0c099ed6: /* original 7aff, guest PC 0x0c099ed6 */
if(!s->budget--) { s->failed_pc=0x0c099ed6u; return 0; }
r[10]+=0xffffffffu;
return vf3_matrix_family(0x0c099ed8u,s,ram);
P_0c099f00: /* original d242, guest PC 0x0c099f00 */
if(!s->budget--) { s->failed_pc=0x0c099f00u; return 0; }
r[2]=read(ram,0x0c09a00cu,4);
goto P_0c099f02;
P_0c099f02: /* original 2298, guest PC 0x0c099f02 */
if(!s->budget--) { s->failed_pc=0x0c099f02u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c099f04;
P_0c099f04: /* original 8905, guest PC 0x0c099f04 */
if(!s->budget--) { s->failed_pc=0x0c099f04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f12; }
goto P_0c099f06;
P_0c099f06: /* original d342, guest PC 0x0c099f06 */
if(!s->budget--) { s->failed_pc=0x0c099f06u; return 0; }
r[3]=read(ram,0x0c09a010u,4);
goto P_0c099f08;
P_0c099f08: /* original 7afe, guest PC 0x0c099f08 */
if(!s->budget--) { s->failed_pc=0x0c099f08u; return 0; }
r[10]+=0xfffffffeu;
goto P_0c099f0a;
P_0c099f0a: /* original 2939, guest PC 0x0c099f0a */
if(!s->budget--) { s->failed_pc=0x0c099f0au; return 0; }
r[9]&=r[3];
goto P_0c099f0c;
P_0c099f0c: /* original 9075, guest PC 0x0c099f0c */
if(!s->budget--) { s->failed_pc=0x0c099f0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffau,2);
goto P_0c099f0e;
P_0c099f0e: /* original 0ea4, guest PC 0x0c099f0e */
if(!s->budget--) { s->failed_pc=0x0c099f0eu; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c099f10;
P_0c099f10: /* original 1e92, guest PC 0x0c099f10 */
if(!s->budget--) { s->failed_pc=0x0c099f10u; return 0; }
write(ram,r[14]+8,r[9],4);
goto P_0c099f12;
P_0c099f12: /* original 9073, guest PC 0x0c099f12 */
if(!s->budget--) { s->failed_pc=0x0c099f12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffcu,2);
goto P_0c099f14;
P_0c099f14: /* original 00ec, guest PC 0x0c099f14 */
if(!s->budget--) { s->failed_pc=0x0c099f14u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f16;
P_0c099f16: /* original 8801, guest PC 0x0c099f16 */
if(!s->budget--) { s->failed_pc=0x0c099f16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c099f18;
P_0c099f18: /* original 8905, guest PC 0x0c099f18 */
if(!s->budget--) { s->failed_pc=0x0c099f18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f26; }
goto P_0c099f1a;
P_0c099f1a: /* original 9070, guest PC 0x0c099f1a */
if(!s->budget--) { s->failed_pc=0x0c099f1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffeu,2);
goto P_0c099f1c;
P_0c099f1c: /* original 05ec, guest PC 0x0c099f1c */
if(!s->budget--) { s->failed_pc=0x0c099f1cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f1e;
P_0c099f1e: /* original 7002, guest PC 0x0c099f1e */
if(!s->budget--) { s->failed_pc=0x0c099f1eu; return 0; }
r[0]+=0x00000002u;
goto P_0c099f20;
P_0c099f20: /* original 04ec, guest PC 0x0c099f20 */
if(!s->budget--) { s->failed_pc=0x0c099f20u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f22;
P_0c099f22: /* original 3540, guest PC 0x0c099f22 */
if(!s->budget--) { s->failed_pc=0x0c099f22u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c099f24;
P_0c099f24: /* original 8b5a, guest PC 0x0c099f24 */
if(!s->budget--) { s->failed_pc=0x0c099f24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099fdc; }
goto P_0c099f26;
P_0c099f26: /* original 53e2, guest PC 0x0c099f26 */
if(!s->budget--) { s->failed_pc=0x0c099f26u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c099f28;
P_0c099f28: /* original d73a, guest PC 0x0c099f28 */
if(!s->budget--) { s->failed_pc=0x0c099f28u; return 0; }
r[7]=read(ram,0x0c09a014u,4);
goto P_0c099f2a;
P_0c099f2a: /* original 9069, guest PC 0x0c099f2a */
if(!s->budget--) { s->failed_pc=0x0c099f2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a000u,2);
goto P_0c099f2c;
P_0c099f2c: /* original 2838, guest PC 0x0c099f2c */
if(!s->budget--) { s->failed_pc=0x0c099f2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c099f2e;
P_0c099f2e: /* original 8d2b, guest PC 0x0c099f2e */
if(!s->budget--) { s->failed_pc=0x0c099f2eu; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[13]+r[0],4);
if(cond) { goto P_0c099f88; }
goto P_0c099f32;
P_0c099f30: /* original 04de, guest PC 0x0c099f30 */
if(!s->budget--) { s->failed_pc=0x0c099f30u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099f32;
P_0c099f32: /* original e02a, guest PC 0x0c099f32 */
if(!s->budget--) { s->failed_pc=0x0c099f32u; return 0; }
r[0]=0x0000002au;
goto P_0c099f34;
P_0c099f34: /* original 00ec, guest PC 0x0c099f34 */
if(!s->budget--) { s->failed_pc=0x0c099f34u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f36;
P_0c099f36: /* original 600c, guest PC 0x0c099f36 */
if(!s->budget--) { s->failed_pc=0x0c099f36u; return 0; }
r[0]=r[0]&255u;
goto P_0c099f38;
P_0c099f38: /* original 8802, guest PC 0x0c099f38 */
if(!s->budget--) { s->failed_pc=0x0c099f38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099f3a;
P_0c099f3a: /* original 8b02, guest PC 0x0c099f3a */
if(!s->budget--) { s->failed_pc=0x0c099f3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099f42; }
goto P_0c099f3c;
P_0c099f3c: /* original 9b61, guest PC 0x0c099f3c */
if(!s->budget--) { s->failed_pc=0x0c099f3cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a002u,2);
goto P_0c099f3e;
P_0c099f3e: /* original a001, guest PC 0x0c099f3e */
if(!s->budget--) { s->failed_pc=0x0c099f3eu; return 0; }
goto P_0c099f44;
P_0c099f40: /* original 0009, guest PC 0x0c099f40 */
if(!s->budget--) { s->failed_pc=0x0c099f40u; return 0; }
goto P_0c099f42;
P_0c099f42: /* original 9b5f, guest PC 0x0c099f42 */
if(!s->budget--) { s->failed_pc=0x0c099f42u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a004u,2);
goto P_0c099f44;
P_0c099f44: /* original 66c3, guest PC 0x0c099f44 */
if(!s->budget--) { s->failed_pc=0x0c099f44u; return 0; }
r[6]=r[12];
goto P_0c099f46;
P_0c099f46: /* original 3bec, guest PC 0x0c099f46 */
if(!s->budget--) { s->failed_pc=0x0c099f46u; return 0; }
r[11]+=r[14];
goto P_0c099f48;
P_0c099f48: /* original 6063, guest PC 0x0c099f48 */
if(!s->budget--) { s->failed_pc=0x0c099f48u; return 0; }
r[0]=r[6];
goto P_0c099f4a;
P_0c099f4a: /* original 05bc, guest PC 0x0c099f4a */
if(!s->budget--) { s->failed_pc=0x0c099f4au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c099f4c;
P_0c099f4c: /* original e30d, guest PC 0x0c099f4c */
if(!s->budget--) { s->failed_pc=0x0c099f4cu; return 0; }
r[3]=0x0000000du;
goto P_0c099f4e;
P_0c099f4e: /* original 655c, guest PC 0x0c099f4e */
if(!s->budget--) { s->failed_pc=0x0c099f4eu; return 0; }
r[5]=r[5]&255u;
goto P_0c099f50;
P_0c099f50: /* original 3533, guest PC 0x0c099f50 */
if(!s->budget--) { s->failed_pc=0x0c099f50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c099f52;
P_0c099f52: /* original 8b00, guest PC 0x0c099f52 */
if(!s->budget--) { s->failed_pc=0x0c099f52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099f56; }
goto P_0c099f54;
P_0c099f54: /* original 75f3, guest PC 0x0c099f54 */
if(!s->budget--) { s->failed_pc=0x0c099f54u; return 0; }
r[5]+=0xfffffff3u;
goto P_0c099f56;
P_0c099f56: /* original 9a56, guest PC 0x0c099f56 */
if(!s->budget--) { s->failed_pc=0x0c099f56u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a006u,2);
goto P_0c099f58;
P_0c099f58: /* original 3aec, guest PC 0x0c099f58 */
if(!s->budget--) { s->failed_pc=0x0c099f58u; return 0; }
r[10]+=r[14];
goto P_0c099f5a;
P_0c099f5a: /* original 3a5c, guest PC 0x0c099f5a */
if(!s->budget--) { s->failed_pc=0x0c099f5au; return 0; }
r[10]+=r[5];
goto P_0c099f5c;
P_0c099f5c: /* original 2fa2, guest PC 0x0c099f5c */
if(!s->budget--) { s->failed_pc=0x0c099f5cu; return 0; }
write(ram,r[15],r[10],4);
goto P_0c099f5e;
P_0c099f5e: /* original 6aa0, guest PC 0x0c099f5e */
if(!s->budget--) { s->failed_pc=0x0c099f5eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[10]=tmp;
goto P_0c099f60;
P_0c099f60: /* original 63f2, guest PC 0x0c099f60 */
if(!s->budget--) { s->failed_pc=0x0c099f60u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099f62;
P_0c099f62: /* original 7aff, guest PC 0x0c099f62 */
if(!s->budget--) { s->failed_pc=0x0c099f62u; return 0; }
r[10]+=0xffffffffu;
goto P_0c099f64;
P_0c099f64: /* original 23a0, guest PC 0x0c099f64 */
if(!s->budget--) { s->failed_pc=0x0c099f64u; return 0; }
write(ram,r[3],r[10],1);
goto P_0c099f66;
P_0c099f66: /* original 6aae, guest PC 0x0c099f66 */
if(!s->budget--) { s->failed_pc=0x0c099f66u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)r[10];
goto P_0c099f68;
P_0c099f68: /* original 4a15, guest PC 0x0c099f68 */
if(!s->budget--) { s->failed_pc=0x0c099f68u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c099f6a;
P_0c099f6a: /* original 8d07, guest PC 0x0c099f6a */
if(!s->budget--) { s->failed_pc=0x0c099f6au; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(cond) { goto P_0c099f7c; }
goto P_0c099f6e;
P_0c099f6c: /* original 7601, guest PC 0x0c099f6c */
if(!s->budget--) { s->failed_pc=0x0c099f6cu; return 0; }
r[6]+=0x00000001u;
goto P_0c099f6e;
P_0c099f6e: /* original 655b, guest PC 0x0c099f6e */
if(!s->budget--) { s->failed_pc=0x0c099f6eu; return 0; }
r[5]=0u-r[5];
goto P_0c099f70;
P_0c099f70: /* original 6a73, guest PC 0x0c099f70 */
if(!s->budget--) { s->failed_pc=0x0c099f70u; return 0; }
r[10]=r[7];
goto P_0c099f72;
P_0c099f72: /* original 4a5d, guest PC 0x0c099f72 */
if(!s->budget--) { s->failed_pc=0x0c099f72u; return 0; }
r[10]=(r[5]&0x80000000u)?((r[5]&31u)?r[10]>>((-r[5])&31u):0):r[10]<<(r[5]&31u);
goto P_0c099f74;
P_0c099f74: /* original 9044, guest PC 0x0c099f74 */
if(!s->budget--) { s->failed_pc=0x0c099f74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a000u,2);
goto P_0c099f76;
P_0c099f76: /* original 6aa7, guest PC 0x0c099f76 */
if(!s->budget--) { s->failed_pc=0x0c099f76u; return 0; }
r[10]=~r[10];
goto P_0c099f78;
P_0c099f78: /* original 24a9, guest PC 0x0c099f78 */
if(!s->budget--) { s->failed_pc=0x0c099f78u; return 0; }
r[4]&=r[10];
goto P_0c099f7a;
P_0c099f7a: /* original 0d46, guest PC 0x0c099f7a */
if(!s->budget--) { s->failed_pc=0x0c099f7au; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c099f7c;
P_0c099f7c: /* original 9044, guest PC 0x0c099f7c */
if(!s->budget--) { s->failed_pc=0x0c099f7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a008u,2);
goto P_0c099f7e;
P_0c099f7e: /* original 03ec, guest PC 0x0c099f7e */
if(!s->budget--) { s->failed_pc=0x0c099f7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f80;
P_0c099f80: /* original 3633, guest PC 0x0c099f80 */
if(!s->budget--) { s->failed_pc=0x0c099f80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c099f82;
P_0c099f82: /* original 8be1, guest PC 0x0c099f82 */
if(!s->budget--) { s->failed_pc=0x0c099f82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099f48; }
goto P_0c099f84;
P_0c099f84: /* original af83, guest PC 0x0c099f84 */
if(!s->budget--) { s->failed_pc=0x0c099f84u; return 0; }
goto P_0c099e8e;
P_0c099f86: /* original 0009, guest PC 0x0c099f86 */
if(!s->budget--) { s->failed_pc=0x0c099f86u; return 0; }
goto P_0c099f88;
P_0c099f88: /* original e02a, guest PC 0x0c099f88 */
if(!s->budget--) { s->failed_pc=0x0c099f88u; return 0; }
r[0]=0x0000002au;
goto P_0c099f8a;
P_0c099f8a: /* original 00ec, guest PC 0x0c099f8a */
if(!s->budget--) { s->failed_pc=0x0c099f8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f8c;
P_0c099f8c: /* original 600c, guest PC 0x0c099f8c */
if(!s->budget--) { s->failed_pc=0x0c099f8cu; return 0; }
r[0]=r[0]&255u;
goto P_0c099f8e;
P_0c099f8e: /* original 8802, guest PC 0x0c099f8e */
if(!s->budget--) { s->failed_pc=0x0c099f8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099f90;
P_0c099f90: /* original 8f02, guest PC 0x0c099f90 */
if(!s->budget--) { s->failed_pc=0x0c099f90u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c099f98; }
goto P_0c099f94;
P_0c099f92: /* original e061, guest PC 0x0c099f92 */
if(!s->budget--) { s->failed_pc=0x0c099f92u; return 0; }
r[0]=0x00000061u;
goto P_0c099f94;
P_0c099f94: /* original a001, guest PC 0x0c099f94 */
if(!s->budget--) { s->failed_pc=0x0c099f94u; return 0; }
r[5]=read(ram,r[11]+16,4);
goto P_0c099f9a;
P_0c099f96: /* original 55b4, guest PC 0x0c099f96 */
if(!s->budget--) { s->failed_pc=0x0c099f96u; return 0; }
r[5]=read(ram,r[11]+16,4);
goto P_0c099f98;
P_0c099f98: /* original 55b5, guest PC 0x0c099f98 */
if(!s->budget--) { s->failed_pc=0x0c099f98u; return 0; }
r[5]=read(ram,r[11]+20,4);
goto P_0c099f9a;
P_0c099f9a: /* original 065c, guest PC 0x0c099f9a */
if(!s->budget--) { s->failed_pc=0x0c099f9au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c099f9c;
P_0c099f9c: /* original 9533, guest PC 0x0c099f9c */
if(!s->budget--) { s->failed_pc=0x0c099f9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a006u,2);
goto P_0c099f9e;
P_0c099f9e: /* original 666c, guest PC 0x0c099f9e */
if(!s->budget--) { s->failed_pc=0x0c099f9eu; return 0; }
r[6]=r[6]&255u;
goto P_0c099fa0;
P_0c099fa0: /* original 35ec, guest PC 0x0c099fa0 */
if(!s->budget--) { s->failed_pc=0x0c099fa0u; return 0; }
r[5]+=r[14];
goto P_0c099fa2;
P_0c099fa2: /* original 356c, guest PC 0x0c099fa2 */
if(!s->budget--) { s->failed_pc=0x0c099fa2u; return 0; }
r[5]+=r[6];
goto P_0c099fa4;
P_0c099fa4: /* original 2f52, guest PC 0x0c099fa4 */
if(!s->budget--) { s->failed_pc=0x0c099fa4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c099fa6;
P_0c099fa6: /* original 6550, guest PC 0x0c099fa6 */
if(!s->budget--) { s->failed_pc=0x0c099fa6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c099fa8;
P_0c099fa8: /* original 63f2, guest PC 0x0c099fa8 */
if(!s->budget--) { s->failed_pc=0x0c099fa8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099faa;
P_0c099faa: /* original 75ff, guest PC 0x0c099faa */
if(!s->budget--) { s->failed_pc=0x0c099faau; return 0; }
r[5]+=0xffffffffu;
goto P_0c099fac;
P_0c099fac: /* original 2350, guest PC 0x0c099fac */
if(!s->budget--) { s->failed_pc=0x0c099facu; return 0; }
write(ram,r[3],r[5],1);
goto P_0c099fae;
P_0c099fae: /* original 655e, guest PC 0x0c099fae */
if(!s->budget--) { s->failed_pc=0x0c099faeu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c099fb0;
P_0c099fb0: /* original 2558, guest PC 0x0c099fb0 */
if(!s->budget--) { s->failed_pc=0x0c099fb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c099fb2;
P_0c099fb2: /* original 8901, guest PC 0x0c099fb2 */
if(!s->budget--) { s->failed_pc=0x0c099fb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099fb8; }
goto P_0c099fb4;
P_0c099fb4: /* original af6b, guest PC 0x0c099fb4 */
if(!s->budget--) { s->failed_pc=0x0c099fb4u; return 0; }
goto P_0c099e8e;
P_0c099fb6: /* original 0009, guest PC 0x0c099fb6 */
if(!s->budget--) { s->failed_pc=0x0c099fb6u; return 0; }
goto P_0c099fb8;
P_0c099fb8: /* original 666b, guest PC 0x0c099fb8 */
if(!s->budget--) { s->failed_pc=0x0c099fb8u; return 0; }
r[6]=0u-r[6];
goto P_0c099fba;
P_0c099fba: /* original 6573, guest PC 0x0c099fba */
if(!s->budget--) { s->failed_pc=0x0c099fbau; return 0; }
r[5]=r[7];
goto P_0c099fbc;
P_0c099fbc: /* original 456d, guest PC 0x0c099fbc */
if(!s->budget--) { s->failed_pc=0x0c099fbcu; return 0; }
r[5]=(r[6]&0x80000000u)?((r[6]&31u)?r[5]>>((-r[6])&31u):0):r[5]<<(r[6]&31u);
goto P_0c099fbe;
P_0c099fbe: /* original 901f, guest PC 0x0c099fbe */
if(!s->budget--) { s->failed_pc=0x0c099fbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a000u,2);
goto P_0c099fc0;
P_0c099fc0: /* original 6557, guest PC 0x0c099fc0 */
if(!s->budget--) { s->failed_pc=0x0c099fc0u; return 0; }
r[5]=~r[5];
goto P_0c099fc2;
P_0c099fc2: /* original 2459, guest PC 0x0c099fc2 */
if(!s->budget--) { s->failed_pc=0x0c099fc2u; return 0; }
r[4]&=r[5];
goto P_0c099fc4;
P_0c099fc4: /* original af63, guest PC 0x0c099fc4 */
if(!s->budget--) { s->failed_pc=0x0c099fc4u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c099e8e;
P_0c099fc6: /* original 0d46, guest PC 0x0c099fc6 */
if(!s->budget--) { s->failed_pc=0x0c099fc6u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c099fc8;
P_0c099fc8: /* original 54ed, guest PC 0x0c099fc8 */
if(!s->budget--) { s->failed_pc=0x0c099fc8u; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c099fca;
P_0c099fca: /* original 52ee, guest PC 0x0c099fca */
if(!s->budget--) { s->failed_pc=0x0c099fcau; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c099fcc;
P_0c099fcc: /* original 342c, guest PC 0x0c099fcc */
if(!s->budget--) { s->failed_pc=0x0c099fccu; return 0; }
r[4]+=r[2];
goto P_0c099fce;
P_0c099fce: /* original 1e4c, guest PC 0x0c099fce */
if(!s->budget--) { s->failed_pc=0x0c099fceu; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c099fd0;
P_0c099fd0: /* original 1e4d, guest PC 0x0c099fd0 */
if(!s->budget--) { s->failed_pc=0x0c099fd0u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c099fd2;
P_0c099fd2: /* original 1ece, guest PC 0x0c099fd2 */
if(!s->budget--) { s->failed_pc=0x0c099fd2u; return 0; }
write(ram,r[14]+56,r[12],4);
goto P_0c099fd4;
P_0c099fd4: /* original 9011, guest PC 0x0c099fd4 */
if(!s->budget--) { s->failed_pc=0x0c099fd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffau,2);
goto P_0c099fd6;
P_0c099fd6: /* original 03ec, guest PC 0x0c099fd6 */
if(!s->budget--) { s->failed_pc=0x0c099fd6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099fd8;
P_0c099fd8: /* original 9017, guest PC 0x0c099fd8 */
if(!s->budget--) { s->failed_pc=0x0c099fd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a00au,2);
goto P_0c099fda;
P_0c099fda: /* original 0e34, guest PC 0x0c099fda */
if(!s->budget--) { s->failed_pc=0x0c099fdau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c099fdc;
P_0c099fdc: /* original d20e, guest PC 0x0c099fdc */
if(!s->budget--) { s->failed_pc=0x0c099fdcu; return 0; }
r[2]=read(ram,0x0c09a018u,4);
goto P_0c099fde;
P_0c099fde: /* original 420b, guest PC 0x0c099fde */
if(!s->budget--) { s->failed_pc=0x0c099fdeu; return 0; }
target=r[2];
r[16]=code_base|0x0c099fe2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099fe2u) { target=s->pc; goto dispatch; }
goto P_0c099fe2;
P_0c099fe0: /* original 0009, guest PC 0x0c099fe0 */
if(!s->budget--) { s->failed_pc=0x0c099fe0u; return 0; }
goto P_0c099fe2;
P_0c099fe2: /* original e008, guest PC 0x0c099fe2 */
if(!s->budget--) { s->failed_pc=0x0c099fe2u; return 0; }
r[0]=0x00000008u;
goto P_0c099fe4;
P_0c099fe4: /* original a045, guest PC 0x0c099fe4 */
if(!s->budget--) { s->failed_pc=0x0c099fe4u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a072;
P_0c099fe6: /* original 80da, guest PC 0x0c099fe6 */
if(!s->budget--) { s->failed_pc=0x0c099fe6u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c099fe8;
P_0c099fe8: /* original e01c, guest PC 0x0c099fe8 */
if(!s->budget--) { s->failed_pc=0x0c099fe8u; return 0; }
r[0]=0x0000001cu;
goto P_0c099fea;
P_0c099fea: /* original 03ec, guest PC 0x0c099fea */
if(!s->budget--) { s->failed_pc=0x0c099feau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099fec;
P_0c099fec: /* original 7301, guest PC 0x0c099fec */
if(!s->budget--) { s->failed_pc=0x0c099fecu; return 0; }
r[3]+=0x00000001u;
goto P_0c099fee;
P_0c099fee: /* original 0e34, guest PC 0x0c099fee */
if(!s->budget--) { s->failed_pc=0x0c099feeu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c099ff0;
P_0c099ff0: /* original 52e2, guest PC 0x0c099ff0 */
if(!s->budget--) { s->failed_pc=0x0c099ff0u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c099ff2;
P_0c099ff2: /* original 2288, guest PC 0x0c099ff2 */
if(!s->budget--) { s->failed_pc=0x0c099ff2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c099ff4;
P_0c099ff4: /* original 8912, guest PC 0x0c099ff4 */
if(!s->budget--) { s->failed_pc=0x0c099ff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a01c; }
goto P_0c099ff6;
P_0c099ff6: /* original a012, guest PC 0x0c099ff6 */
if(!s->budget--) { s->failed_pc=0x0c099ff6u; return 0; }
r[0]=0x00000011u;
goto P_0c09a01e;
P_0c099ff8: /* original e011, guest PC 0x0c099ff8 */
if(!s->budget--) { s->failed_pc=0x0c099ff8u; return 0; }
r[0]=0x00000011u;
return vf3_matrix_family(0x0c099ffau,s,ram);
P_0c09a01c: /* original 6083, guest PC 0x0c09a01c */
if(!s->budget--) { s->failed_pc=0x0c09a01cu; return 0; }
r[0]=r[8];
goto P_0c09a01e;
P_0c09a01e: /* original d345, guest PC 0x0c09a01e */
if(!s->budget--) { s->failed_pc=0x0c09a01eu; return 0; }
r[3]=read(ram,0x0c09a134u,4);
goto P_0c09a020;
P_0c09a020: /* original 430b, guest PC 0x0c09a020 */
if(!s->budget--) { s->failed_pc=0x0c09a020u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a024u;
write(ram,r[13]+11,r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09a024u) { target=s->pc; goto dispatch; }
goto P_0c09a024;
P_0c09a022: /* original 80db, guest PC 0x0c09a022 */
if(!s->budget--) { s->failed_pc=0x0c09a022u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09a024;
P_0c09a024: /* original a025, guest PC 0x0c09a024 */
if(!s->budget--) { s->failed_pc=0x0c09a024u; return 0; }
goto P_0c09a072;
P_0c09a026: /* original 0009, guest PC 0x0c09a026 */
if(!s->budget--) { s->failed_pc=0x0c09a026u; return 0; }
goto P_0c09a028;
P_0c09a028: /* original e00c, guest PC 0x0c09a028 */
if(!s->budget--) { s->failed_pc=0x0c09a028u; return 0; }
r[0]=0x0000000cu;
goto P_0c09a02a;
P_0c09a02a: /* original e500, guest PC 0x0c09a02a */
if(!s->budget--) { s->failed_pc=0x0c09a02au; return 0; }
r[5]=0x00000000u;
goto P_0c09a02c;
P_0c09a02c: /* original 80da, guest PC 0x0c09a02c */
if(!s->budget--) { s->failed_pc=0x0c09a02cu; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a02e;
P_0c09a02e: /* original 2fc6, guest PC 0x0c09a02e */
if(!s->budget--) { s->failed_pc=0x0c09a02eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a030;
P_0c09a030: /* original e731, guest PC 0x0c09a030 */
if(!s->budget--) { s->failed_pc=0x0c09a030u; return 0; }
r[7]=0x00000031u;
goto P_0c09a032;
P_0c09a032: /* original 54f2, guest PC 0x0c09a032 */
if(!s->budget--) { s->failed_pc=0x0c09a032u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09a034;
P_0c09a034: /* original e63f, guest PC 0x0c09a034 */
if(!s->budget--) { s->failed_pc=0x0c09a034u; return 0; }
r[6]=0x0000003fu;
goto P_0c09a036;
P_0c09a036: /* original d340, guest PC 0x0c09a036 */
if(!s->budget--) { s->failed_pc=0x0c09a036u; return 0; }
r[3]=read(ram,0x0c09a138u,4);
goto P_0c09a038;
P_0c09a038: /* original 430b, guest PC 0x0c09a038 */
if(!s->budget--) { s->failed_pc=0x0c09a038u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a03cu;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09a03cu) { target=s->pc; goto dispatch; }
goto P_0c09a03c;
P_0c09a03a: /* original 742c, guest PC 0x0c09a03a */
if(!s->budget--) { s->failed_pc=0x0c09a03au; return 0; }
r[4]+=0x0000002cu;
goto P_0c09a03c;
P_0c09a03c: /* original d23f, guest PC 0x0c09a03c */
if(!s->budget--) { s->failed_pc=0x0c09a03cu; return 0; }
r[2]=read(ram,0x0c09a13cu,4);
goto P_0c09a03e;
P_0c09a03e: /* original 420b, guest PC 0x0c09a03e */
if(!s->budget--) { s->failed_pc=0x0c09a03eu; return 0; }
target=r[2];
r[16]=code_base|0x0c09a042u;
r[15]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09a042u) { target=s->pc; goto dispatch; }
goto P_0c09a042;
P_0c09a040: /* original 7f04, guest PC 0x0c09a040 */
if(!s->budget--) { s->failed_pc=0x0c09a040u; return 0; }
r[15]+=0x00000004u;
goto P_0c09a042;
P_0c09a042: /* original a016, guest PC 0x0c09a042 */
if(!s->budget--) { s->failed_pc=0x0c09a042u; return 0; }
goto P_0c09a072;
P_0c09a044: /* original 0009, guest PC 0x0c09a044 */
if(!s->budget--) { s->failed_pc=0x0c09a044u; return 0; }
goto P_0c09a046;
P_0c09a046: /* original 9071, guest PC 0x0c09a046 */
if(!s->budget--) { s->failed_pc=0x0c09a046u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a12cu,2);
goto P_0c09a048;
P_0c09a048: /* original 03dc, guest PC 0x0c09a048 */
if(!s->budget--) { s->failed_pc=0x0c09a048u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09a04a;
P_0c09a04a: /* original 2338, guest PC 0x0c09a04a */
if(!s->budget--) { s->failed_pc=0x0c09a04au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09a04c;
P_0c09a04c: /* original 890f, guest PC 0x0c09a04c */
if(!s->budget--) { s->failed_pc=0x0c09a04cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a06e; }
goto P_0c09a04e;
P_0c09a04e: /* original 6083, guest PC 0x0c09a04e */
if(!s->budget--) { s->failed_pc=0x0c09a04eu; return 0; }
r[0]=r[8];
goto P_0c09a050;
P_0c09a050: /* original 80da, guest PC 0x0c09a050 */
if(!s->budget--) { s->failed_pc=0x0c09a050u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a052;
P_0c09a052: /* original 906c, guest PC 0x0c09a052 */
if(!s->budget--) { s->failed_pc=0x0c09a052u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a12eu,2);
goto P_0c09a054;
P_0c09a054: /* original 0dc6, guest PC 0x0c09a054 */
if(!s->budget--) { s->failed_pc=0x0c09a054u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c09a056;
P_0c09a056: /* original 60c3, guest PC 0x0c09a056 */
if(!s->budget--) { s->failed_pc=0x0c09a056u; return 0; }
r[0]=r[12];
goto P_0c09a058;
P_0c09a058: /* original d439, guest PC 0x0c09a058 */
if(!s->budget--) { s->failed_pc=0x0c09a058u; return 0; }
r[4]=read(ram,0x0c09a140u,4);
goto P_0c09a05a;
P_0c09a05a: /* original 24c0, guest PC 0x0c09a05a */
if(!s->budget--) { s->failed_pc=0x0c09a05au; return 0; }
write(ram,r[4],r[12],1);
goto P_0c09a05c;
P_0c09a05c: /* original 8041, guest PC 0x0c09a05c */
if(!s->budget--) { s->failed_pc=0x0c09a05cu; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c09a05e;
P_0c09a05e: /* original 54bb, guest PC 0x0c09a05e */
if(!s->budget--) { s->failed_pc=0x0c09a05eu; return 0; }
r[4]=read(ram,r[11]+44,4);
goto P_0c09a060;
P_0c09a060: /* original 55ba, guest PC 0x0c09a060 */
if(!s->budget--) { s->failed_pc=0x0c09a060u; return 0; }
r[5]=read(ram,r[11]+40,4);
goto P_0c09a062;
P_0c09a062: /* original 2502, guest PC 0x0c09a062 */
if(!s->budget--) { s->failed_pc=0x0c09a062u; return 0; }
write(ram,r[5],r[0],4);
goto P_0c09a064;
P_0c09a064: /* original 2402, guest PC 0x0c09a064 */
if(!s->budget--) { s->failed_pc=0x0c09a064u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c09a066;
P_0c09a066: /* original e06c, guest PC 0x0c09a066 */
if(!s->budget--) { s->failed_pc=0x0c09a066u; return 0; }
r[0]=0x0000006cu;
goto P_0c09a068;
P_0c09a068: /* original 05c6, guest PC 0x0c09a068 */
if(!s->budget--) { s->failed_pc=0x0c09a068u; return 0; }
write(ram,r[5]+r[0],r[12],4);
goto P_0c09a06a;
P_0c09a06a: /* original a002, guest PC 0x0c09a06a */
if(!s->budget--) { s->failed_pc=0x0c09a06au; return 0; }
write(ram,r[4]+r[0],r[12],4);
goto P_0c09a072;
P_0c09a06c: /* original 04c6, guest PC 0x0c09a06c */
if(!s->budget--) { s->failed_pc=0x0c09a06cu; return 0; }
write(ram,r[4]+r[0],r[12],4);
goto P_0c09a06e;
P_0c09a06e: /* original e012, guest PC 0x0c09a06e */
if(!s->budget--) { s->failed_pc=0x0c09a06eu; return 0; }
r[0]=0x00000012u;
goto P_0c09a070;
P_0c09a070: /* original 80da, guest PC 0x0c09a070 */
if(!s->budget--) { s->failed_pc=0x0c09a070u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a072;
P_0c09a072: /* original 7f08, guest PC 0x0c09a072 */
if(!s->budget--) { s->failed_pc=0x0c09a072u; return 0; }
r[15]+=0x00000008u;
goto P_0c09a074;
P_0c09a074: /* original 4f26, guest PC 0x0c09a074 */
if(!s->budget--) { s->failed_pc=0x0c09a074u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09a076;
P_0c09a076: /* original 68f6, guest PC 0x0c09a076 */
if(!s->budget--) { s->failed_pc=0x0c09a076u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09a078;
P_0c09a078: /* original 69f6, guest PC 0x0c09a078 */
if(!s->budget--) { s->failed_pc=0x0c09a078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09a07a;
P_0c09a07a: /* original 6af6, guest PC 0x0c09a07a */
if(!s->budget--) { s->failed_pc=0x0c09a07au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09a07c;
P_0c09a07c: /* original 6bf6, guest PC 0x0c09a07c */
if(!s->budget--) { s->failed_pc=0x0c09a07cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09a07e;
P_0c09a07e: /* original 6cf6, guest PC 0x0c09a07e */
if(!s->budget--) { s->failed_pc=0x0c09a07eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09a080;
P_0c09a080: /* original 6df6, guest PC 0x0c09a080 */
if(!s->budget--) { s->failed_pc=0x0c09a080u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09a082;
P_0c09a082: /* original 000b, guest PC 0x0c09a082 */
if(!s->budget--) { s->failed_pc=0x0c09a082u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09a084: /* original 6ef6, guest PC 0x0c09a084 */
if(!s->budget--) { s->failed_pc=0x0c09a084u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09a086u,s,ram);
P_0c0c76d4: /* original 4f22, guest PC 0x0c0c76d4 */
if(!s->budget--) { s->failed_pc=0x0c0c76d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c76d6;
P_0c0c76d6: /* original 09ec, guest PC 0x0c0c76d6 */
if(!s->budget--) { s->failed_pc=0x0c0c76d6u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c76d8;
P_0c0c76d8: /* original d024, guest PC 0x0c0c76d8 */
if(!s->budget--) { s->failed_pc=0x0c0c76d8u; return 0; }
r[0]=read(ram,0x0c0c776cu,4);
goto P_0c0c76da;
P_0c0c76da: /* original 699c, guest PC 0x0c0c76da */
if(!s->budget--) { s->failed_pc=0x0c0c76dau; return 0; }
r[9]=r[9]&255u;
goto P_0c0c76dc;
P_0c0c76dc: /* original d322, guest PC 0x0c0c76dc */
if(!s->budget--) { s->failed_pc=0x0c0c76dcu; return 0; }
r[3]=read(ram,0x0c0c7768u,4);
goto P_0c0c76de;
P_0c0c76de: /* original 2c99, guest PC 0x0c0c76de */
if(!s->budget--) { s->failed_pc=0x0c0c76deu; return 0; }
r[12]&=r[9];
goto P_0c0c76e0;
P_0c0c76e0: /* original db20, guest PC 0x0c0c76e0 */
if(!s->budget--) { s->failed_pc=0x0c0c76e0u; return 0; }
r[11]=read(ram,0x0c0c7764u,4);
goto P_0c0c76e2;
P_0c0c76e2: /* original 4c08, guest PC 0x0c0c76e2 */
if(!s->budget--) { s->failed_pc=0x0c0c76e2u; return 0; }
r[12]<<=2;
goto P_0c0c76e4;
P_0c0c76e4: /* original 4c00, guest PC 0x0c0c76e4 */
if(!s->budget--) { s->failed_pc=0x0c0c76e4u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c76e6;
P_0c0c76e6: /* original 00ce, guest PC 0x0c0c76e6 */
if(!s->budget--) { s->failed_pc=0x0c0c76e6u; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c0c76e8;
P_0c0c76e8: /* original 7ffc, guest PC 0x0c0c76e8 */
if(!s->budget--) { s->failed_pc=0x0c0c76e8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c76ea;
P_0c0c76ea: /* original 88ff, guest PC 0x0c0c76ea */
if(!s->budget--) { s->failed_pc=0x0c0c76eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c76ec;
P_0c0c76ec: /* original 8d44, guest PC 0x0c0c76ec */
if(!s->budget--) { s->failed_pc=0x0c0c76ecu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(cond) { goto P_0c0c7778; }
goto P_0c0c76f0;
P_0c0c76ee: /* original 6432, guest PC 0x0c0c76ee */
if(!s->budget--) { s->failed_pc=0x0c0c76eeu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c76f0;
P_0c0c76f0: /* original 902e, guest PC 0x0c0c76f0 */
if(!s->budget--) { s->failed_pc=0x0c0c76f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7750u,2);
goto P_0c0c76f2;
P_0c0c76f2: /* original 0e46, guest PC 0x0c0c76f2 */
if(!s->budget--) { s->failed_pc=0x0c0c76f2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c76f4;
P_0c0c76f4: /* original d51d, guest PC 0x0c0c76f4 */
if(!s->budget--) { s->failed_pc=0x0c0c76f4u; return 0; }
r[5]=read(ram,0x0c0c776cu,4);
goto P_0c0c76f6;
P_0c0c76f6: /* original d21e, guest PC 0x0c0c76f6 */
if(!s->budget--) { s->failed_pc=0x0c0c76f6u; return 0; }
r[2]=read(ram,0x0c0c7770u,4);
goto P_0c0c76f8;
P_0c0c76f8: /* original 35cc, guest PC 0x0c0c76f8 */
if(!s->budget--) { s->failed_pc=0x0c0c76f8u; return 0; }
r[5]+=r[12];
goto P_0c0c76fa;
P_0c0c76fa: /* original 0aee, guest PC 0x0c0c76fa */
if(!s->budget--) { s->failed_pc=0x0c0c76fau; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c0c76fc;
P_0c0c76fc: /* original 6721, guest PC 0x0c0c76fc */
if(!s->budget--) { s->failed_pc=0x0c0c76fcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[7]=tmp;
goto P_0c0c76fe;
P_0c0c76fe: /* original 2f52, guest PC 0x0c0c76fe */
if(!s->budget--) { s->failed_pc=0x0c0c76feu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c7700;
P_0c0c7700: /* original 66a3, guest PC 0x0c0c7700 */
if(!s->budget--) { s->failed_pc=0x0c0c7700u; return 0; }
r[6]=r[10];
goto P_0c0c7702;
P_0c0c7702: /* original 64f2, guest PC 0x0c0c7702 */
if(!s->budget--) { s->failed_pc=0x0c0c7702u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c7704;
P_0c0c7704: /* original 5551, guest PC 0x0c0c7704 */
if(!s->budget--) { s->failed_pc=0x0c0c7704u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c0c7706;
P_0c0c7706: /* original d31b, guest PC 0x0c0c7706 */
if(!s->budget--) { s->failed_pc=0x0c0c7706u; return 0; }
r[3]=read(ram,0x0c0c7774u,4);
goto P_0c0c7708;
P_0c0c7708: /* original 430b, guest PC 0x0c0c7708 */
if(!s->budget--) { s->failed_pc=0x0c0c7708u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c770cu;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c770cu) { target=s->pc; goto dispatch; }
goto P_0c0c770c;
P_0c0c770a: /* original 6442, guest PC 0x0c0c770a */
if(!s->budget--) { s->failed_pc=0x0c0c770au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c770c;
P_0c0c770c: /* original 52a4, guest PC 0x0c0c770c */
if(!s->budget--) { s->failed_pc=0x0c0c770cu; return 0; }
r[2]=read(ram,r[10]+16,4);
goto P_0c0c770e;
P_0c0c770e: /* original 2f22, guest PC 0x0c0c770e */
if(!s->budget--) { s->failed_pc=0x0c0c770eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c7710;
P_0c0c7710: /* original 981c, guest PC 0x0c0c7710 */
if(!s->budget--) { s->failed_pc=0x0c0c7710u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774cu,2);
goto P_0c0c7712;
P_0c0c7712: /* original a008, guest PC 0x0c0c7712 */
if(!s->budget--) { s->failed_pc=0x0c0c7712u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7726;
P_0c0c7714: /* original ed00, guest PC 0x0c0c7714 */
if(!s->budget--) { s->failed_pc=0x0c0c7714u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7716;
P_0c0c7716: /* original 60f2, guest PC 0x0c0c7716 */
if(!s->budget--) { s->failed_pc=0x0c0c7716u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c7718;
P_0c0c7718: /* original 65d3, guest PC 0x0c0c7718 */
if(!s->budget--) { s->failed_pc=0x0c0c7718u; return 0; }
r[5]=r[13];
goto P_0c0c771a;
P_0c0c771a: /* original 4508, guest PC 0x0c0c771a */
if(!s->budget--) { s->failed_pc=0x0c0c771au; return 0; }
r[5]<<=2;
goto P_0c0c771c;
P_0c0c771c: /* original 6483, guest PC 0x0c0c771c */
if(!s->budget--) { s->failed_pc=0x0c0c771cu; return 0; }
r[4]=r[8];
goto P_0c0c771e;
P_0c0c771e: /* original 055e, guest PC 0x0c0c771e */
if(!s->budget--) { s->failed_pc=0x0c0c771eu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0c7720;
P_0c0c7720: /* original 4b0b, guest PC 0x0c0c7720 */
if(!s->budget--) { s->failed_pc=0x0c0c7720u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c7724u;
r[8]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7724u) { target=s->pc; goto dispatch; }
goto P_0c0c7724;
P_0c0c7722: /* original 7801, guest PC 0x0c0c7722 */
if(!s->budget--) { s->failed_pc=0x0c0c7722u; return 0; }
r[8]+=0x00000001u;
goto P_0c0c7724;
P_0c0c7724: /* original 7d01, guest PC 0x0c0c7724 */
if(!s->budget--) { s->failed_pc=0x0c0c7724u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c7726;
P_0c0c7726: /* original 85a6, guest PC 0x0c0c7726 */
if(!s->budget--) { s->failed_pc=0x0c0c7726u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+12,2);
goto P_0c0c7728;
P_0c0c7728: /* original 600d, guest PC 0x0c0c7728 */
if(!s->budget--) { s->failed_pc=0x0c0c7728u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c772a;
P_0c0c772a: /* original 3d03, guest PC 0x0c0c772a */
if(!s->budget--) { s->failed_pc=0x0c0c772au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[0])!=0);
goto P_0c0c772c;
P_0c0c772c: /* original 8bf3, guest PC 0x0c0c772c */
if(!s->budget--) { s->failed_pc=0x0c0c772cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7716; }
goto P_0c0c772e;
P_0c0c772e: /* original 900f, guest PC 0x0c0c772e */
if(!s->budget--) { s->failed_pc=0x0c0c772eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7750u,2);
goto P_0c0c7730;
P_0c0c7730: /* original 53a6, guest PC 0x0c0c7730 */
if(!s->budget--) { s->failed_pc=0x0c0c7730u; return 0; }
r[3]=read(ram,r[10]+24,4);
goto P_0c0c7732;
P_0c0c7732: /* original 02ee, guest PC 0x0c0c7732 */
if(!s->budget--) { s->failed_pc=0x0c0c7732u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c7734;
P_0c0c7734: /* original 7004, guest PC 0x0c0c7734 */
if(!s->budget--) { s->failed_pc=0x0c0c7734u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7736;
P_0c0c7736: /* original 910c, guest PC 0x0c0c7736 */
if(!s->budget--) { s->failed_pc=0x0c0c7736u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7752u,2);
goto P_0c0c7738;
P_0c0c7738: /* original 323c, guest PC 0x0c0c7738 */
if(!s->budget--) { s->failed_pc=0x0c0c7738u; return 0; }
r[2]+=r[3];
goto P_0c0c773a;
P_0c0c773a: /* original 930b, guest PC 0x0c0c773a */
if(!s->budget--) { s->failed_pc=0x0c0c773au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7754u,2);
goto P_0c0c773c;
P_0c0c773c: /* original 321c, guest PC 0x0c0c773c */
if(!s->budget--) { s->failed_pc=0x0c0c773cu; return 0; }
r[2]+=r[1];
goto P_0c0c773e;
P_0c0c773e: /* original 2239, guest PC 0x0c0c773e */
if(!s->budget--) { s->failed_pc=0x0c0c773eu; return 0; }
r[2]&=r[3];
goto P_0c0c7740;
P_0c0c7740: /* original 0e26, guest PC 0x0c0c7740 */
if(!s->budget--) { s->failed_pc=0x0c0c7740u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c7742;
P_0c0c7742: /* original 70f8, guest PC 0x0c0c7742 */
if(!s->budget--) { s->failed_pc=0x0c0c7742u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c7744;
P_0c0c7744: /* original a01a, guest PC 0x0c0c7744 */
if(!s->budget--) { s->failed_pc=0x0c0c7744u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c777c;
P_0c0c7746: /* original 0e26, guest PC 0x0c0c7746 */
if(!s->budget--) { s->failed_pc=0x0c0c7746u; return 0; }
write(ram,r[14]+r[0],r[2],4);
return vf3_matrix_family(0x0c0c7748u,s,ram);
P_0c0c7778: /* original 9071, guest PC 0x0c0c7778 */
if(!s->budget--) { s->failed_pc=0x0c0c7778u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c777a;
P_0c0c777a: /* original 0e46, guest PC 0x0c0c777a */
if(!s->budget--) { s->failed_pc=0x0c0c777au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c777c;
P_0c0c777c: /* original d03a, guest PC 0x0c0c777c */
if(!s->budget--) { s->failed_pc=0x0c0c777cu; return 0; }
r[0]=read(ram,0x0c0c7868u,4);
goto P_0c0c777e;
P_0c0c777e: /* original 00ce, guest PC 0x0c0c777e */
if(!s->budget--) { s->failed_pc=0x0c0c777eu; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c0c7780;
P_0c0c7780: /* original 88ff, guest PC 0x0c0c7780 */
if(!s->budget--) { s->failed_pc=0x0c0c7780u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7782;
P_0c0c7782: /* original 8931, guest PC 0x0c0c7782 */
if(!s->budget--) { s->failed_pc=0x0c0c7782u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c77e8; }
goto P_0c0c7784;
P_0c0c7784: /* original 906b, guest PC 0x0c0c7784 */
if(!s->budget--) { s->failed_pc=0x0c0c7784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c7786;
P_0c0c7786: /* original d339, guest PC 0x0c0c7786 */
if(!s->budget--) { s->failed_pc=0x0c0c7786u; return 0; }
r[3]=read(ram,0x0c0c786cu,4);
goto P_0c0c7788;
P_0c0c7788: /* original 0dee, guest PC 0x0c0c7788 */
if(!s->budget--) { s->failed_pc=0x0c0c7788u; return 0; }
r[13]=read(ram,r[14]+r[0],4);
goto P_0c0c778a;
P_0c0c778a: /* original 6093, guest PC 0x0c0c778a */
if(!s->budget--) { s->failed_pc=0x0c0c778au; return 0; }
r[0]=r[9];
goto P_0c0c778c;
P_0c0c778c: /* original 8812, guest PC 0x0c0c778c */
if(!s->budget--) { s->failed_pc=0x0c0c778cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0c778e;
P_0c0c778e: /* original 8f08, guest PC 0x0c0c778e */
if(!s->budget--) { s->failed_pc=0x0c0c778eu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[7]=tmp;
if(!cond) { goto P_0c0c77a2; }
goto P_0c0c7792;
P_0c0c7790: /* original 6731, guest PC 0x0c0c7790 */
if(!s->budget--) { s->failed_pc=0x0c0c7790u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[7]=tmp;
goto P_0c0c7792;
P_0c0c7792: /* original 9565, guest PC 0x0c0c7792 */
if(!s->budget--) { s->failed_pc=0x0c0c7792u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7860u,2);
goto P_0c0c7794;
P_0c0c7794: /* original 66d3, guest PC 0x0c0c7794 */
if(!s->budget--) { s->failed_pc=0x0c0c7794u; return 0; }
r[6]=r[13];
goto P_0c0c7796;
P_0c0c7796: /* original d136, guest PC 0x0c0c7796 */
if(!s->budget--) { s->failed_pc=0x0c0c7796u; return 0; }
r[1]=read(ram,0x0c0c7870u,4);
goto P_0c0c7798;
P_0c0c7798: /* original 6453, guest PC 0x0c0c7798 */
if(!s->budget--) { s->failed_pc=0x0c0c7798u; return 0; }
r[4]=r[5];
goto P_0c0c779a;
P_0c0c779a: /* original 410b, guest PC 0x0c0c779a */
if(!s->budget--) { s->failed_pc=0x0c0c779au; return 0; }
target=r[1];
r[16]=code_base|0x0c0c779eu;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c779eu) { target=s->pc; goto dispatch; }
goto P_0c0c779e;
P_0c0c779c: /* original 7401, guest PC 0x0c0c779c */
if(!s->budget--) { s->failed_pc=0x0c0c779cu; return 0; }
r[4]+=0x00000001u;
goto P_0c0c779e;
P_0c0c779e: /* original a009, guest PC 0x0c0c779e */
if(!s->budget--) { s->failed_pc=0x0c0c779eu; return 0; }
goto P_0c0c77b4;
P_0c0c77a0: /* original 0009, guest PC 0x0c0c77a0 */
if(!s->budget--) { s->failed_pc=0x0c0c77a0u; return 0; }
goto P_0c0c77a2;
P_0c0c77a2: /* original d531, guest PC 0x0c0c77a2 */
if(!s->budget--) { s->failed_pc=0x0c0c77a2u; return 0; }
r[5]=read(ram,0x0c0c7868u,4);
goto P_0c0c77a4;
P_0c0c77a4: /* original 66d3, guest PC 0x0c0c77a4 */
if(!s->budget--) { s->failed_pc=0x0c0c77a4u; return 0; }
r[6]=r[13];
goto P_0c0c77a6;
P_0c0c77a6: /* original 35cc, guest PC 0x0c0c77a6 */
if(!s->budget--) { s->failed_pc=0x0c0c77a6u; return 0; }
r[5]+=r[12];
goto P_0c0c77a8;
P_0c0c77a8: /* original 2f52, guest PC 0x0c0c77a8 */
if(!s->budget--) { s->failed_pc=0x0c0c77a8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c77aa;
P_0c0c77aa: /* original 64f2, guest PC 0x0c0c77aa */
if(!s->budget--) { s->failed_pc=0x0c0c77aau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c77ac;
P_0c0c77ac: /* original d230, guest PC 0x0c0c77ac */
if(!s->budget--) { s->failed_pc=0x0c0c77acu; return 0; }
r[2]=read(ram,0x0c0c7870u,4);
goto P_0c0c77ae;
P_0c0c77ae: /* original 5551, guest PC 0x0c0c77ae */
if(!s->budget--) { s->failed_pc=0x0c0c77aeu; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c0c77b0;
P_0c0c77b0: /* original 420b, guest PC 0x0c0c77b0 */
if(!s->budget--) { s->failed_pc=0x0c0c77b0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c77b4u;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c77b4u) { target=s->pc; goto dispatch; }
goto P_0c0c77b4;
P_0c0c77b2: /* original 6442, guest PC 0x0c0c77b2 */
if(!s->budget--) { s->failed_pc=0x0c0c77b2u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c77b4;
P_0c0c77b4: /* original 9a55, guest PC 0x0c0c77b4 */
if(!s->budget--) { s->failed_pc=0x0c0c77b4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7862u,2);
goto P_0c0c77b6;
P_0c0c77b6: /* original 59d4, guest PC 0x0c0c77b6 */
if(!s->budget--) { s->failed_pc=0x0c0c77b6u; return 0; }
r[9]=read(ram,r[13]+16,4);
goto P_0c0c77b8;
P_0c0c77b8: /* original a007, guest PC 0x0c0c77b8 */
if(!s->budget--) { s->failed_pc=0x0c0c77b8u; return 0; }
r[12]=0x00000000u;
goto P_0c0c77ca;
P_0c0c77ba: /* original ec00, guest PC 0x0c0c77ba */
if(!s->budget--) { s->failed_pc=0x0c0c77bau; return 0; }
r[12]=0x00000000u;
goto P_0c0c77bc;
P_0c0c77bc: /* original 60c3, guest PC 0x0c0c77bc */
if(!s->budget--) { s->failed_pc=0x0c0c77bcu; return 0; }
r[0]=r[12];
goto P_0c0c77be;
P_0c0c77be: /* original 4008, guest PC 0x0c0c77be */
if(!s->budget--) { s->failed_pc=0x0c0c77beu; return 0; }
r[0]<<=2;
goto P_0c0c77c0;
P_0c0c77c0: /* original 059e, guest PC 0x0c0c77c0 */
if(!s->budget--) { s->failed_pc=0x0c0c77c0u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0c77c2;
P_0c0c77c2: /* original 64a3, guest PC 0x0c0c77c2 */
if(!s->budget--) { s->failed_pc=0x0c0c77c2u; return 0; }
r[4]=r[10];
goto P_0c0c77c4;
P_0c0c77c4: /* original 4b0b, guest PC 0x0c0c77c4 */
if(!s->budget--) { s->failed_pc=0x0c0c77c4u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c77c8u;
r[10]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c77c8u) { target=s->pc; goto dispatch; }
goto P_0c0c77c8;
P_0c0c77c6: /* original 7a01, guest PC 0x0c0c77c6 */
if(!s->budget--) { s->failed_pc=0x0c0c77c6u; return 0; }
r[10]+=0x00000001u;
goto P_0c0c77c8;
P_0c0c77c8: /* original 7c01, guest PC 0x0c0c77c8 */
if(!s->budget--) { s->failed_pc=0x0c0c77c8u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c77ca;
P_0c0c77ca: /* original 85d6, guest PC 0x0c0c77ca */
if(!s->budget--) { s->failed_pc=0x0c0c77cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+12,2);
goto P_0c0c77cc;
P_0c0c77cc: /* original 600d, guest PC 0x0c0c77cc */
if(!s->budget--) { s->failed_pc=0x0c0c77ccu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c77ce;
P_0c0c77ce: /* original 3c03, guest PC 0x0c0c77ce */
if(!s->budget--) { s->failed_pc=0x0c0c77ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0c77d0;
P_0c0c77d0: /* original 8bf4, guest PC 0x0c0c77d0 */
if(!s->budget--) { s->failed_pc=0x0c0c77d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c77bc; }
goto P_0c0c77d2;
P_0c0c77d2: /* original 9044, guest PC 0x0c0c77d2 */
if(!s->budget--) { s->failed_pc=0x0c0c77d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c77d4;
P_0c0c77d4: /* original 53d6, guest PC 0x0c0c77d4 */
if(!s->budget--) { s->failed_pc=0x0c0c77d4u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c0c77d6;
P_0c0c77d6: /* original 02ee, guest PC 0x0c0c77d6 */
if(!s->budget--) { s->failed_pc=0x0c0c77d6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c77d8;
P_0c0c77d8: /* original 7008, guest PC 0x0c0c77d8 */
if(!s->budget--) { s->failed_pc=0x0c0c77d8u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c77da;
P_0c0c77da: /* original 9143, guest PC 0x0c0c77da */
if(!s->budget--) { s->failed_pc=0x0c0c77dau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7864u,2);
goto P_0c0c77dc;
P_0c0c77dc: /* original 323c, guest PC 0x0c0c77dc */
if(!s->budget--) { s->failed_pc=0x0c0c77dcu; return 0; }
r[2]+=r[3];
goto P_0c0c77de;
P_0c0c77de: /* original 9342, guest PC 0x0c0c77de */
if(!s->budget--) { s->failed_pc=0x0c0c77deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7866u,2);
goto P_0c0c77e0;
P_0c0c77e0: /* original 321c, guest PC 0x0c0c77e0 */
if(!s->budget--) { s->failed_pc=0x0c0c77e0u; return 0; }
r[2]+=r[1];
goto P_0c0c77e2;
P_0c0c77e2: /* original 2239, guest PC 0x0c0c77e2 */
if(!s->budget--) { s->failed_pc=0x0c0c77e2u; return 0; }
r[2]&=r[3];
goto P_0c0c77e4;
P_0c0c77e4: /* original a003, guest PC 0x0c0c77e4 */
if(!s->budget--) { s->failed_pc=0x0c0c77e4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c77ee;
P_0c0c77e6: /* original 0e26, guest PC 0x0c0c77e6 */
if(!s->budget--) { s->failed_pc=0x0c0c77e6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c77e8;
P_0c0c77e8: /* original 9039, guest PC 0x0c0c77e8 */
if(!s->budget--) { s->failed_pc=0x0c0c77e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c77ea;
P_0c0c77ea: /* original e300, guest PC 0x0c0c77ea */
if(!s->budget--) { s->failed_pc=0x0c0c77eau; return 0; }
r[3]=0x00000000u;
goto P_0c0c77ec;
P_0c0c77ec: /* original 0e36, guest PC 0x0c0c77ec */
if(!s->budget--) { s->failed_pc=0x0c0c77ecu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c77ee;
P_0c0c77ee: /* original 7f04, guest PC 0x0c0c77ee */
if(!s->budget--) { s->failed_pc=0x0c0c77eeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c77f0;
P_0c0c77f0: /* original 4f26, guest PC 0x0c0c77f0 */
if(!s->budget--) { s->failed_pc=0x0c0c77f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c77f2;
P_0c0c77f2: /* original 68f6, guest PC 0x0c0c77f2 */
if(!s->budget--) { s->failed_pc=0x0c0c77f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c77f4;
P_0c0c77f4: /* original 69f6, guest PC 0x0c0c77f4 */
if(!s->budget--) { s->failed_pc=0x0c0c77f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c77f6;
P_0c0c77f6: /* original 6af6, guest PC 0x0c0c77f6 */
if(!s->budget--) { s->failed_pc=0x0c0c77f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c77f8;
P_0c0c77f8: /* original 6bf6, guest PC 0x0c0c77f8 */
if(!s->budget--) { s->failed_pc=0x0c0c77f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c77fa;
P_0c0c77fa: /* original 6cf6, guest PC 0x0c0c77fa */
if(!s->budget--) { s->failed_pc=0x0c0c77fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c77fc;
P_0c0c77fc: /* original 6df6, guest PC 0x0c0c77fc */
if(!s->budget--) { s->failed_pc=0x0c0c77fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c77fe;
P_0c0c77fe: /* original a000, guest PC 0x0c0c77fe */
if(!s->budget--) { s->failed_pc=0x0c0c77feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c7802;
P_0c0c7800: /* original 6ef6, guest PC 0x0c0c7800 */
if(!s->budget--) { s->failed_pc=0x0c0c7800u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c7802;
P_0c0c7802: /* original e01c, guest PC 0x0c0c7802 */
if(!s->budget--) { s->failed_pc=0x0c0c7802u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7804;
P_0c0c7804: /* original 2fe6, guest PC 0x0c0c7804 */
if(!s->budget--) { s->failed_pc=0x0c0c7804u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7806;
P_0c0c7806: /* original 2fd6, guest PC 0x0c0c7806 */
if(!s->budget--) { s->failed_pc=0x0c0c7806u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7808;
P_0c0c7808: /* original 2fc6, guest PC 0x0c0c7808 */
if(!s->budget--) { s->failed_pc=0x0c0c7808u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780a;
P_0c0c780a: /* original 2fb6, guest PC 0x0c0c780a */
if(!s->budget--) { s->failed_pc=0x0c0c780au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780c;
P_0c0c780c: /* original 2fa6, guest PC 0x0c0c780c */
if(!s->budget--) { s->failed_pc=0x0c0c780cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780e;
P_0c0c780e: /* original d419, guest PC 0x0c0c780e */
if(!s->budget--) { s->failed_pc=0x0c0c780eu; return 0; }
r[4]=read(ram,0x0c0c7874u,4);
goto P_0c0c7810;
P_0c0c7810: /* original 4f22, guest PC 0x0c0c7810 */
if(!s->budget--) { s->failed_pc=0x0c0c7810u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7812;
P_0c0c7812: /* original 004c, guest PC 0x0c0c7812 */
if(!s->budget--) { s->failed_pc=0x0c0c7812u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7814;
P_0c0c7814: /* original e40f, guest PC 0x0c0c7814 */
if(!s->budget--) { s->failed_pc=0x0c0c7814u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c7816;
P_0c0c7816: /* original 600c, guest PC 0x0c0c7816 */
if(!s->budget--) { s->failed_pc=0x0c0c7816u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7818;
P_0c0c7818: /* original 2409, guest PC 0x0c0c7818 */
if(!s->budget--) { s->failed_pc=0x0c0c7818u; return 0; }
r[4]&=r[0];
goto P_0c0c781a;
P_0c0c781a: /* original d017, guest PC 0x0c0c781a */
if(!s->budget--) { s->failed_pc=0x0c0c781au; return 0; }
r[0]=read(ram,0x0c0c7878u,4);
goto P_0c0c781c;
P_0c0c781c: /* original 6e43, guest PC 0x0c0c781c */
if(!s->budget--) { s->failed_pc=0x0c0c781cu; return 0; }
r[14]=r[4];
goto P_0c0c781e;
P_0c0c781e: /* original 4e08, guest PC 0x0c0c781e */
if(!s->budget--) { s->failed_pc=0x0c0c781eu; return 0; }
r[14]<<=2;
goto P_0c0c7820;
P_0c0c7820: /* original 0eee, guest PC 0x0c0c7820 */
if(!s->budget--) { s->failed_pc=0x0c0c7820u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0c7822;
P_0c0c7822: /* original 2ee8, guest PC 0x0c0c7822 */
if(!s->budget--) { s->failed_pc=0x0c0c7822u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c7824;
P_0c0c7824: /* original 8914, guest PC 0x0c0c7824 */
if(!s->budget--) { s->failed_pc=0x0c0c7824u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7850; }
goto P_0c0c7826;
P_0c0c7826: /* original dc17, guest PC 0x0c0c7826 */
if(!s->budget--) { s->failed_pc=0x0c0c7826u; return 0; }
r[12]=read(ram,0x0c0c7884u,4);
goto P_0c0c7828;
P_0c0c7828: /* original db15, guest PC 0x0c0c7828 */
if(!s->budget--) { s->failed_pc=0x0c0c7828u; return 0; }
r[11]=read(ram,0x0c0c7880u,4);
goto P_0c0c782a;
P_0c0c782a: /* original da14, guest PC 0x0c0c782a */
if(!s->budget--) { s->failed_pc=0x0c0c782au; return 0; }
r[10]=read(ram,0x0c0c787cu,4);
goto P_0c0c782c;
P_0c0c782c: /* original a00d, guest PC 0x0c0c782c */
if(!s->budget--) { s->failed_pc=0x0c0c782cu; return 0; }
r[13]=0x00000001u;
goto P_0c0c784a;
P_0c0c782e: /* original ed01, guest PC 0x0c0c782e */
if(!s->budget--) { s->failed_pc=0x0c0c782eu; return 0; }
r[13]=0x00000001u;
goto P_0c0c7830;
P_0c0c7830: /* original 60e5, guest PC 0x0c0c7830 */
if(!s->budget--) { s->failed_pc=0x0c0c7830u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c0c7832;
P_0c0c7832: /* original 600d, guest PC 0x0c0c7832 */
if(!s->budget--) { s->failed_pc=0x0c0c7832u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7834;
P_0c0c7834: /* original 4008, guest PC 0x0c0c7834 */
if(!s->budget--) { s->failed_pc=0x0c0c7834u; return 0; }
r[0]<<=2;
goto P_0c0c7836;
P_0c0c7836: /* original 04ce, guest PC 0x0c0c7836 */
if(!s->budget--) { s->failed_pc=0x0c0c7836u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0c7838;
P_0c0c7838: /* original 5341, guest PC 0x0c0c7838 */
if(!s->budget--) { s->failed_pc=0x0c0c7838u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0c783a;
P_0c0c783a: /* original 23d8, guest PC 0x0c0c783a */
if(!s->budget--) { s->failed_pc=0x0c0c783au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c783c;
P_0c0c783c: /* original 8903, guest PC 0x0c0c783c */
if(!s->budget--) { s->failed_pc=0x0c0c783cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7846; }
goto P_0c0c783e;
P_0c0c783e: /* original 4b0b, guest PC 0x0c0c783e */
if(!s->budget--) { s->failed_pc=0x0c0c783eu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c7842u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7842u) { target=s->pc; goto dispatch; }
goto P_0c0c7842;
P_0c0c7840: /* original 0009, guest PC 0x0c0c7840 */
if(!s->budget--) { s->failed_pc=0x0c0c7840u; return 0; }
goto P_0c0c7842;
P_0c0c7842: /* original a002, guest PC 0x0c0c7842 */
if(!s->budget--) { s->failed_pc=0x0c0c7842u; return 0; }
goto P_0c0c784a;
P_0c0c7844: /* original 0009, guest PC 0x0c0c7844 */
if(!s->budget--) { s->failed_pc=0x0c0c7844u; return 0; }
goto P_0c0c7846;
P_0c0c7846: /* original 4a0b, guest PC 0x0c0c7846 */
if(!s->budget--) { s->failed_pc=0x0c0c7846u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c784au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c784au) { target=s->pc; goto dispatch; }
goto P_0c0c784a;
P_0c0c7848: /* original 0009, guest PC 0x0c0c7848 */
if(!s->budget--) { s->failed_pc=0x0c0c7848u; return 0; }
goto P_0c0c784a;
P_0c0c784a: /* original 62e1, guest PC 0x0c0c784a */
if(!s->budget--) { s->failed_pc=0x0c0c784au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0c784c;
P_0c0c784c: /* original 2228, guest PC 0x0c0c784c */
if(!s->budget--) { s->failed_pc=0x0c0c784cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c784e;
P_0c0c784e: /* original 8bef, guest PC 0x0c0c784e */
if(!s->budget--) { s->failed_pc=0x0c0c784eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7830; }
goto P_0c0c7850;
P_0c0c7850: /* original 4f26, guest PC 0x0c0c7850 */
if(!s->budget--) { s->failed_pc=0x0c0c7850u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7852;
P_0c0c7852: /* original 6af6, guest PC 0x0c0c7852 */
if(!s->budget--) { s->failed_pc=0x0c0c7852u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7854;
P_0c0c7854: /* original 6bf6, guest PC 0x0c0c7854 */
if(!s->budget--) { s->failed_pc=0x0c0c7854u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7856;
P_0c0c7856: /* original 6cf6, guest PC 0x0c0c7856 */
if(!s->budget--) { s->failed_pc=0x0c0c7856u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7858;
P_0c0c7858: /* original 6df6, guest PC 0x0c0c7858 */
if(!s->budget--) { s->failed_pc=0x0c0c7858u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c785a;
P_0c0c785a: /* original 000b, guest PC 0x0c0c785a */
if(!s->budget--) { s->failed_pc=0x0c0c785au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c785c: /* original 6ef6, guest PC 0x0c0c785c */
if(!s->budget--) { s->failed_pc=0x0c0c785cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c785eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03757cu,0x0c03757eu,0x0c037580u,0x0c037582u,0x0c037584u,0x0c037586u,0x0c037588u,0x0c03758au,0x0c03758cu,0x0c03758eu,0x0c037590u,0x0c037592u,0x0c037594u,0x0c037596u,0x0c037598u,0x0c03759au,
0x0c03759cu,0x0c03759eu,0x0c0375a0u,0x0c0375a2u,0x0c0375a4u,0x0c0375a6u,0x0c0375a8u,0x0c0375aau,0x0c0375acu,0x0c0375aeu,0x0c0375b0u,0x0c0375b2u,0x0c0375b4u,0x0c0375b6u,0x0c0375b8u,0x0c0375bau,
0x0c0375bcu,0x0c0375beu,0x0c0375c0u,0x0c0375c2u,0x0c0375c4u,0x0c0375c6u,0x0c0375c8u,0x0c0375cau,0x0c0375ccu,0x0c0375ceu,0x0c0375d0u,0x0c0375d2u,0x0c0375d4u,0x0c0375d6u,0x0c0375d8u,0x0c0375dau,
0x0c0375dcu,0x0c0375deu,0x0c0375e0u,0x0c0375e2u,0x0c0375e4u,0x0c0375e6u,0x0c0375e8u,0x0c0375eau,0x0c0375ecu,0x0c0375eeu,0x0c0375f0u,0x0c0375f2u,0x0c0375f4u,0x0c0375f6u,0x0c0375f8u,0x0c0375fau,
0x0c0375fcu,0x0c0375feu,0x0c037600u,0x0c037602u,0x0c037604u,0x0c037606u,0x0c037608u,0x0c03760au,0x0c03760cu,0x0c03760eu,0x0c037610u,0x0c037612u,0x0c037614u,0x0c037616u,0x0c037618u,0x0c03761au,
0x0c03761cu,0x0c03761eu,0x0c037620u,0x0c037622u,0x0c037624u,0x0c037626u,0x0c037628u,0x0c03762au,0x0c03762cu,0x0c03762eu,0x0c037630u,0x0c037632u,0x0c037634u,0x0c037636u,0x0c037638u,0x0c03763au,
0x0c03763cu,0x0c03763eu,0x0c037640u,0x0c037642u,0x0c037644u,0x0c037646u,0x0c037648u,0x0c03764au,0x0c03764cu,0x0c03764eu,0x0c037650u,0x0c037652u,0x0c037654u,0x0c037656u,0x0c037658u,0x0c03765au,
0x0c03765cu,0x0c03765eu,0x0c037660u,0x0c037662u,0x0c037664u,0x0c037666u,0x0c037668u,0x0c03766au,0x0c03766cu,0x0c03766eu,0x0c037670u,0x0c037672u,0x0c037674u,0x0c037676u,0x0c037678u,0x0c03767au,
0x0c03767cu,0x0c03767eu,0x0c037680u,0x0c037682u,0x0c037684u,0x0c037686u,0x0c037688u,0x0c04d020u,0x0c04d022u,0x0c04d024u,0x0c04d026u,0x0c04d028u,0x0c04d02au,0x0c04d02cu,0x0c04d02eu,0x0c04d030u,
0x0c04d032u,0x0c04d034u,0x0c04d036u,0x0c04d038u,0x0c04d03au,0x0c04d03cu,0x0c04d03eu,0x0c04d040u,0x0c04d042u,0x0c04d044u,0x0c04d046u,0x0c04d048u,0x0c04d04au,0x0c04d04cu,0x0c04d04eu,0x0c04d050u,
0x0c04d052u,0x0c04d054u,0x0c04d056u,0x0c04d058u,0x0c04d05au,0x0c04d05cu,0x0c04d05eu,0x0c04d060u,0x0c04d062u,0x0c04d064u,0x0c04d066u,0x0c04d068u,0x0c04d06au,0x0c04d06cu,0x0c04d06eu,0x0c04d070u,
0x0c04d072u,0x0c04d09cu,0x0c04d09eu,0x0c04d0a0u,0x0c04d0a2u,0x0c04d0a4u,0x0c04d0a6u,0x0c04d0a8u,0x0c04d0aau,0x0c04d0acu,0x0c04d0aeu,0x0c04d0b0u,0x0c04d0b2u,0x0c04d0b4u,0x0c04d0b6u,0x0c04d0b8u,
0x0c04d0bau,0x0c04d0bcu,0x0c04d0beu,0x0c04d0c0u,0x0c04d0c2u,0x0c04d0c4u,0x0c04d0c6u,0x0c04d0c8u,0x0c04d0cau,0x0c04d0ccu,0x0c04d0ceu,0x0c04d0d0u,0x0c04d0d2u,0x0c04d0d4u,0x0c04d0d6u,0x0c04d0d8u,
0x0c04d0dau,0x0c04d0dcu,0x0c04d0deu,0x0c04d0e0u,0x0c04d0e2u,0x0c04d0e4u,0x0c04d0e6u,0x0c04d0e8u,0x0c04d0eau,0x0c04d0ecu,0x0c04d0eeu,0x0c04d0f0u,0x0c04d0f2u,0x0c04d0f4u,0x0c04d0f6u,0x0c04d0f8u,
0x0c04d0fau,0x0c04d0fcu,0x0c04d0feu,0x0c04d100u,0x0c04d102u,0x0c04d104u,0x0c04d106u,0x0c04d108u,0x0c04d10au,0x0c04d10cu,0x0c04d10eu,0x0c04d110u,0x0c04d112u,0x0c04d114u,0x0c04d116u,0x0c04d118u,
0x0c04d11au,0x0c04d11cu,0x0c04d11eu,0x0c04d120u,0x0c04d122u,0x0c04d124u,0x0c04d126u,0x0c04d128u,0x0c04d12au,0x0c04d12cu,0x0c04d12eu,0x0c04d130u,0x0c04d132u,0x0c04d134u,0x0c04d136u,0x0c04d138u,
0x0c04d13au,0x0c04d13cu,0x0c04d13eu,0x0c04d140u,0x0c04d142u,0x0c04d144u,0x0c04d146u,0x0c04d148u,0x0c04d14au,0x0c04d14cu,0x0c04d14eu,0x0c04d150u,0x0c04d152u,0x0c04d154u,0x0c04d156u,0x0c04d158u,
0x0c04d15au,0x0c04d15cu,0x0c04d15eu,0x0c04d160u,0x0c04d162u,0x0c04d164u,0x0c04d166u,0x0c04d168u,0x0c04d16au,0x0c04d16cu,0x0c04d16eu,0x0c04d170u,0x0c04d172u,0x0c04d174u,0x0c04d1a0u,0x0c04d1a2u,
0x0c04d1a4u,0x0c04d1a6u,0x0c04d1a8u,0x0c04d1aau,0x0c04d1acu,0x0c04d1aeu,0x0c04d1b0u,0x0c04d1b2u,0x0c04d1b4u,0x0c04d1b6u,0x0c04d1b8u,0x0c04d1bau,0x0c04d1bcu,0x0c04d1beu,0x0c04d1c0u,0x0c04d1c2u,
0x0c04d1c4u,0x0c04d1c6u,0x0c04d1c8u,0x0c04d1cau,0x0c04d1ccu,0x0c04d1ceu,0x0c04d1d0u,0x0c04d1d2u,0x0c04d1d4u,0x0c04d1d6u,0x0c04d1d8u,0x0c04d1dau,0x0c04d1dcu,0x0c04d1deu,0x0c04d1e0u,0x0c04d1e2u,
0x0c04d1e4u,0x0c04d1e6u,0x0c04d1e8u,0x0c04d1eau,0x0c04d1ecu,0x0c04d1eeu,0x0c04d1f0u,0x0c04d1f2u,0x0c04d1f4u,0x0c04d1f6u,0x0c04d1f8u,0x0c04d1fau,0x0c04d1fcu,0x0c04d1feu,0x0c04d200u,0x0c04d202u,
0x0c04d204u,0x0c04d206u,0x0c04d208u,0x0c04d20au,0x0c04d20cu,0x0c04d20eu,0x0c04d210u,0x0c04d212u,0x0c04d214u,0x0c04d216u,0x0c04d218u,0x0c04d21au,0x0c04d21cu,0x0c04d21eu,0x0c04d220u,0x0c04d222u,
0x0c04d224u,0x0c04d226u,0x0c04d228u,0x0c04d22au,0x0c04d22cu,0x0c04d22eu,0x0c04d230u,0x0c04d232u,0x0c04d234u,0x0c04d236u,0x0c04d238u,0x0c04d23au,0x0c04d23cu,0x0c04d23eu,0x0c04d240u,0x0c04d242u,
0x0c04d244u,0x0c04d246u,0x0c04d248u,0x0c04d24au,0x0c04d24cu,0x0c04d24eu,0x0c04d250u,0x0c04d252u,0x0c04d254u,0x0c04d256u,0x0c04d258u,0x0c04d25au,0x0c04d25cu,0x0c04d25eu,0x0c04d260u,0x0c04d262u,
0x0c04d264u,0x0c04d266u,0x0c04d268u,0x0c04d26au,0x0c04d26cu,0x0c04d26eu,0x0c04d270u,0x0c04d272u,0x0c04d274u,0x0c04d276u,0x0c04d278u,0x0c04d27au,0x0c04d27cu,0x0c04d27eu,0x0c04d280u,0x0c04d282u,
0x0c04d284u,0x0c04d286u,0x0c04d288u,0x0c04d28au,0x0c04d28cu,0x0c04d28eu,0x0c04d290u,0x0c04d292u,0x0c04d294u,0x0c04d296u,0x0c04d298u,0x0c04d29au,0x0c04d29cu,0x0c04d29eu,0x0c04d2a0u,0x0c04d2a2u,
0x0c04d2a4u,0x0c04d2a6u,0x0c04d2a8u,0x0c04d2aau,0x0c04d2acu,0x0c04d2aeu,0x0c04d2b0u,0x0c04d2b2u,0x0c04d2b4u,0x0c04d2b6u,0x0c04d2b8u,0x0c04d2bau,0x0c04d2bcu,0x0c04d2beu,0x0c04d2c0u,0x0c04d2c2u,
0x0c04d2c4u,0x0c04d2c6u,0x0c04d2c8u,0x0c04d2cau,0x0c04d2ccu,0x0c04d2ceu,0x0c04d2d0u,0x0c04d2d2u,0x0c04d2d4u,0x0c04d2d6u,0x0c04d2d8u,0x0c04d2dau,0x0c04d2dcu,0x0c04d2deu,0x0c04d2e0u,0x0c04d2e2u,
0x0c04d2e4u,0x0c04d2e6u,0x0c04d2e8u,0x0c04d2eau,0x0c04d2ecu,0x0c04d2eeu,0x0c04d2f0u,0x0c04d320u,0x0c04d322u,0x0c04d324u,0x0c04d326u,0x0c04d328u,0x0c04d32au,0x0c04d32cu,0x0c04d32eu,0x0c04d330u,
0x0c04d332u,0x0c04d334u,0x0c04d336u,0x0c04d338u,0x0c04d33au,0x0c04d33cu,0x0c04d33eu,0x0c04d340u,0x0c04d342u,0x0c04d344u,0x0c04d346u,0x0c04d348u,0x0c04d34au,0x0c04d34cu,0x0c04d34eu,0x0c04d350u,
0x0c04d352u,0x0c04d354u,0x0c04d356u,0x0c04d358u,0x0c04d35au,0x0c04d35cu,0x0c04d35eu,0x0c04d360u,0x0c04d362u,0x0c04d364u,0x0c04d366u,0x0c04d368u,0x0c04d36au,0x0c04d36cu,0x0c04d36eu,0x0c04d370u,
0x0c04d372u,0x0c04d374u,0x0c04d376u,0x0c04d378u,0x0c04d37au,0x0c04d37cu,0x0c04d37eu,0x0c04d380u,0x0c04d382u,0x0c04d384u,0x0c04d386u,0x0c04d388u,0x0c04d38au,0x0c04d38cu,0x0c04d38eu,0x0c04d390u,
0x0c04d392u,0x0c04d394u,0x0c04d396u,0x0c04d398u,0x0c04d39au,0x0c04d39cu,0x0c04d39eu,0x0c04d3a0u,0x0c04d3a2u,0x0c04d3a4u,0x0c04d3a6u,0x0c04d3a8u,0x0c04d3aau,0x0c04d3acu,0x0c04d3aeu,0x0c04d3b0u,
0x0c04d3b2u,0x0c04d3b4u,0x0c04d3b6u,0x0c04d3b8u,0x0c04d3bau,0x0c04d3bcu,0x0c04d3beu,0x0c04d3c0u,0x0c04d3c2u,0x0c04d3c4u,0x0c04d3c6u,0x0c04d3c8u,0x0c04d3cau,0x0c04d3ccu,0x0c04d3ceu,0x0c04d3d0u,
0x0c04d3d2u,0x0c04d3d4u,0x0c04d3d6u,0x0c04d3d8u,0x0c04d3dau,0x0c04d3dcu,0x0c04d3deu,0x0c04d3e0u,0x0c04d3e2u,0x0c04d3e4u,0x0c04d3e6u,0x0c04d3e8u,0x0c04d3eau,0x0c04d3ecu,0x0c04d3eeu,0x0c04d3f0u,
0x0c04d3f2u,0x0c04d3f4u,0x0c04d3f6u,0x0c04d3f8u,0x0c04d3fau,0x0c04d3fcu,0x0c04d3feu,0x0c04d400u,0x0c04d402u,0x0c04d404u,0x0c04d406u,0x0c04d408u,0x0c04d40au,0x0c04d40cu,0x0c04d40eu,0x0c04d410u,
0x0c04d412u,0x0c04d414u,0x0c04d416u,0x0c04e8f8u,0x0c04e8fau,0x0c04e8fcu,0x0c04e8feu,0x0c04e900u,0x0c04e902u,0x0c04e904u,0x0c04e906u,0x0c04e908u,0x0c04e90au,0x0c04e90cu,0x0c04e90eu,0x0c04e910u,
0x0c04e912u,0x0c04e914u,0x0c04e916u,0x0c04e918u,0x0c04e91au,0x0c04e91cu,0x0c04e91eu,0x0c04e920u,0x0c04e922u,0x0c04e924u,0x0c04e926u,0x0c04e928u,0x0c04e92au,0x0c04e92cu,0x0c04e92eu,0x0c04e930u,
0x0c04e932u,0x0c04e934u,0x0c04e936u,0x0c04e938u,0x0c04e93au,0x0c04e93cu,0x0c04e93eu,0x0c04e940u,0x0c04e942u,0x0c04e944u,0x0c04e946u,0x0c04e948u,0x0c04e94au,0x0c04e94cu,0x0c04e94eu,0x0c04e950u,
0x0c04e952u,0x0c04e954u,0x0c04e956u,0x0c04e958u,0x0c04e95au,0x0c04e95cu,0x0c04e95eu,0x0c04e960u,0x0c04e962u,0x0c04e964u,0x0c04e966u,0x0c04e968u,0x0c04e96au,0x0c04e96cu,0x0c04e96eu,0x0c04e970u,
0x0c04e972u,0x0c04e974u,0x0c04e976u,0x0c04e978u,0x0c04e97au,0x0c04e97cu,0x0c04e97eu,0x0c04e980u,0x0c04e982u,0x0c04e984u,0x0c04e986u,0x0c04e988u,0x0c04e98au,0x0c04e98cu,0x0c04e98eu,0x0c04e990u,
0x0c04e992u,0x0c04e994u,0x0c04e996u,0x0c04e998u,0x0c04e99au,0x0c04e99cu,0x0c04e99eu,0x0c04e9ccu,0x0c04e9ceu,0x0c04e9d0u,0x0c04e9d2u,0x0c04e9d4u,0x0c04e9d6u,0x0c04e9d8u,0x0c04e9dau,0x0c04e9dcu,
0x0c04e9deu,0x0c04e9e0u,0x0c04e9e2u,0x0c04e9e4u,0x0c04e9e6u,0x0c04e9e8u,0x0c04e9eau,0x0c04e9ecu,0x0c04e9eeu,0x0c04e9f0u,0x0c04e9f2u,0x0c04e9f4u,0x0c04e9f6u,0x0c04e9f8u,0x0c04e9fau,0x0c04e9fcu,
0x0c04e9feu,0x0c04ea00u,0x0c04ea02u,0x0c04ea04u,0x0c04ea06u,0x0c04ea08u,0x0c04ea0au,0x0c04ea0cu,0x0c04ea0eu,0x0c04ea10u,0x0c04ea12u,0x0c04ea14u,0x0c04ea16u,0x0c04ea18u,0x0c04ea1au,0x0c04ea1cu,
0x0c04ea1eu,0x0c04ea20u,0x0c04ea22u,0x0c04ea24u,0x0c04ea26u,0x0c04ea28u,0x0c04ea2au,0x0c04ea2cu,0x0c04ea2eu,0x0c04ea30u,0x0c04ea32u,0x0c04ea34u,0x0c04ea36u,0x0c04ea38u,0x0c04ea3au,0x0c04ea3cu,
0x0c04ea3eu,0x0c04ea40u,0x0c04ea42u,0x0c04f620u,0x0c04f622u,0x0c04f624u,0x0c04f626u,0x0c04f628u,0x0c04f62au,0x0c04f62cu,0x0c04f62eu,0x0c04f630u,0x0c052f36u,0x0c052f38u,0x0c052f3au,0x0c052f3cu,
0x0c052f3eu,0x0c052f40u,0x0c052f42u,0x0c052f44u,0x0c052f46u,0x0c052f48u,0x0c052f4au,0x0c052f4cu,0x0c052f4eu,0x0c052f50u,0x0c052f52u,0x0c052f54u,0x0c052f56u,0x0c052f58u,0x0c052f5au,0x0c052f5cu,
0x0c052f5eu,0x0c052f60u,0x0c052f62u,0x0c052f64u,0x0c052f66u,0x0c052f68u,0x0c052f6au,0x0c052f6cu,0x0c052f6eu,0x0c052f70u,0x0c052f72u,0x0c052f74u,0x0c052f76u,0x0c052f78u,0x0c052f7au,0x0c052f7cu,
0x0c052f7eu,0x0c052f80u,0x0c052f82u,0x0c052f84u,0x0c052f86u,0x0c052f88u,0x0c052f8au,0x0c052f8cu,0x0c052f8eu,0x0c052f90u,0x0c052f92u,0x0c052f94u,0x0c052f96u,0x0c052f98u,0x0c052f9au,0x0c052f9cu,
0x0c052f9eu,0x0c052fa0u,0x0c052fa2u,0x0c052fa4u,0x0c052fa6u,0x0c052fa8u,0x0c052faau,0x0c052facu,0x0c052faeu,0x0c052fb0u,0x0c052fb2u,0x0c052fb4u,0x0c052fb6u,0x0c052fb8u,0x0c052fbau,0x0c052fbcu,
0x0c052fbeu,0x0c052fc0u,0x0c052fc2u,0x0c052fc4u,0x0c052fc6u,0x0c052fc8u,0x0c052fcau,0x0c052fccu,0x0c052fceu,0x0c052fd0u,0x0c052fd2u,0x0c052fd4u,0x0c052fd6u,0x0c052fd8u,0x0c052fdau,0x0c052fdcu,
0x0c052fdeu,0x0c052fe0u,0x0c052fe2u,0x0c052fe4u,0x0c052fe6u,0x0c052fe8u,0x0c052feau,0x0c052fecu,0x0c052feeu,0x0c052ff0u,0x0c052ff2u,0x0c052ff4u,0x0c052ff6u,0x0c052ff8u,0x0c052ffau,0x0c052ffcu,
0x0c052ffeu,0x0c053000u,0x0c053002u,0x0c053004u,0x0c053006u,0x0c053008u,0x0c05300au,0x0c05300cu,0x0c05300eu,0x0c053010u,0x0c053012u,0x0c053014u,0x0c053016u,0x0c053018u,0x0c05301au,0x0c05301cu,
0x0c05301eu,0x0c053020u,0x0c053022u,0x0c053024u,0x0c053026u,0x0c053028u,0x0c05302au,0x0c05302cu,0x0c05302eu,0x0c053030u,0x0c053032u,0x0c053034u,0x0c053036u,0x0c053038u,0x0c05303au,0x0c05303cu,
0x0c05303eu,0x0c053040u,0x0c054348u,0x0c05434au,0x0c05434cu,0x0c05434eu,0x0c054350u,0x0c054352u,0x0c054354u,0x0c054356u,0x0c054358u,0x0c05435au,0x0c05435cu,0x0c05435eu,0x0c054360u,0x0c054362u,
0x0c054364u,0x0c054366u,0x0c054368u,0x0c05436au,0x0c05436cu,0x0c05436eu,0x0c054370u,0x0c054372u,0x0c054374u,0x0c054376u,0x0c054378u,0x0c05437au,0x0c05437cu,0x0c05437eu,0x0c054380u,0x0c054382u,
0x0c054650u,0x0c054652u,0x0c054654u,0x0c054656u,0x0c054658u,0x0c05465au,0x0c05465cu,0x0c05465eu,0x0c054660u,0x0c054662u,0x0c054664u,0x0c054666u,0x0c054668u,0x0c05466au,0x0c05466cu,0x0c05466eu,
0x0c054670u,0x0c054672u,0x0c054674u,0x0c054676u,0x0c054678u,0x0c05467au,0x0c05467cu,0x0c05467eu,0x0c054680u,0x0c054682u,0x0c054684u,0x0c054686u,0x0c054688u,0x0c05468au,0x0c05468cu,0x0c05468eu,
0x0c054690u,0x0c054692u,0x0c054694u,0x0c054696u,0x0c054698u,0x0c05469au,0x0c05469cu,0x0c05469eu,0x0c0546a0u,0x0c0546a2u,0x0c0546a4u,0x0c0546a6u,0x0c0546a8u,0x0c0546aau,0x0c0546acu,0x0c0546aeu,
0x0c0546b0u,0x0c0546b2u,0x0c0546b4u,0x0c0546b6u,0x0c0546b8u,0x0c0546bau,0x0c0546bcu,0x0c0546beu,0x0c0546c0u,0x0c0546c2u,0x0c0546c4u,0x0c0546c6u,0x0c0546c8u,0x0c0546cau,0x0c0546ccu,0x0c0546ceu,
0x0c0546d0u,0x0c0546d2u,0x0c0546d4u,0x0c0546d6u,0x0c0546d8u,0x0c0546dau,0x0c0546dcu,0x0c0546deu,0x0c0546e0u,0x0c0546e2u,0x0c0546e4u,0x0c0546e6u,0x0c0546e8u,0x0c054704u,0x0c054706u,0x0c054708u,
0x0c05470au,0x0c05470cu,0x0c05470eu,0x0c054710u,0x0c054712u,0x0c054714u,0x0c054716u,0x0c054718u,0x0c05471au,0x0c05471cu,0x0c05471eu,0x0c054720u,0x0c054722u,0x0c054724u,0x0c054726u,0x0c054728u,
0x0c05472au,0x0c05472cu,0x0c05472eu,0x0c054730u,0x0c054732u,0x0c054734u,0x0c054736u,0x0c054738u,0x0c05473au,0x0c05473cu,0x0c05473eu,0x0c054740u,0x0c054742u,0x0c054744u,0x0c054746u,0x0c054748u,
0x0c05474au,0x0c05474cu,0x0c05474eu,0x0c054750u,0x0c054752u,0x0c054754u,0x0c054756u,0x0c054758u,0x0c05475au,0x0c05475cu,0x0c05475eu,0x0c054760u,0x0c054762u,0x0c054764u,0x0c054766u,0x0c054768u,
0x0c05476au,0x0c05476cu,0x0c05476eu,0x0c054770u,0x0c054772u,0x0c054774u,0x0c054776u,0x0c054778u,0x0c05477au,0x0c05477cu,0x0c05477eu,0x0c054780u,0x0c054782u,0x0c054784u,0x0c054786u,0x0c054788u,
0x0c05478au,0x0c05478cu,0x0c05478eu,0x0c054790u,0x0c054792u,0x0c054794u,0x0c054796u,0x0c054798u,0x0c05479au,0x0c05479cu,0x0c05479eu,0x0c0547a0u,0x0c0547a2u,0x0c0547a4u,0x0c0547a6u,0x0c0547a8u,
0x0c0547aau,0x0c0547acu,0x0c0547aeu,0x0c0547b0u,0x0c0547b2u,0x0c0547b4u,0x0c0547b6u,0x0c0547b8u,0x0c0547bau,0x0c0547bcu,0x0c0547beu,0x0c0547c0u,0x0c0547c2u,0x0c0547c4u,0x0c0547c6u,0x0c0547c8u,
0x0c0547cau,0x0c0547ccu,0x0c0547ceu,0x0c0547d0u,0x0c0547d2u,0x0c0547d4u,0x0c0547d6u,0x0c0547d8u,0x0c0547dau,0x0c0547dcu,0x0c0547deu,0x0c0547e0u,0x0c0547e2u,0x0c0547e4u,0x0c0547e6u,0x0c0547e8u,
0x0c0547eau,0x0c0547ecu,0x0c0547eeu,0x0c0547f0u,0x0c0547f2u,0x0c0547f4u,0x0c0547f6u,0x0c0547f8u,0x0c0547fau,0x0c0547fcu,0x0c0547feu,0x0c054800u,0x0c054802u,0x0c054804u,0x0c054806u,0x0c058348u,
0x0c05834au,0x0c05834cu,0x0c05834eu,0x0c058350u,0x0c058352u,0x0c058354u,0x0c058356u,0x0c058358u,0x0c05835au,0x0c05835cu,0x0c05835eu,0x0c058360u,0x0c058362u,0x0c058364u,0x0c058366u,0x0c058368u,
0x0c05836au,0x0c05836cu,0x0c05836eu,0x0c058370u,0x0c058372u,0x0c058374u,0x0c058376u,0x0c058378u,0x0c05837au,0x0c05837cu,0x0c05837eu,0x0c058380u,0x0c058382u,0x0c058384u,0x0c058386u,0x0c058388u,
0x0c05838au,0x0c05838cu,0x0c05838eu,0x0c058390u,0x0c058392u,0x0c058394u,0x0c058396u,0x0c058398u,0x0c05839au,0x0c05839cu,0x0c05839eu,0x0c0583a0u,0x0c0583a2u,0x0c0583a4u,0x0c0583a6u,0x0c0583a8u,
0x0c0583aau,0x0c0583acu,0x0c0583aeu,0x0c0583b0u,0x0c0583b2u,0x0c0583b4u,0x0c0583b6u,0x0c0583b8u,0x0c0583bau,0x0c0583bcu,0x0c0583beu,0x0c0583c0u,0x0c0583c2u,0x0c0583c4u,0x0c0583c6u,0x0c0583c8u,
0x0c0583cau,0x0c0583ccu,0x0c0583ceu,0x0c0583d0u,0x0c0583d2u,0x0c0583d4u,0x0c0583d6u,0x0c0583d8u,0x0c0583dau,0x0c0583dcu,0x0c0583deu,0x0c0583e0u,0x0c0583e2u,0x0c0583e4u,0x0c0583e6u,0x0c0583e8u,
0x0c0583eau,0x0c0583ecu,0x0c0583eeu,0x0c0583f0u,0x0c0583f2u,0x0c0583f4u,0x0c0583f6u,0x0c0583f8u,0x0c0583fau,0x0c0583fcu,0x0c0583feu,0x0c058400u,0x0c058402u,0x0c058404u,0x0c058406u,0x0c058408u,
0x0c05840au,0x0c05840cu,0x0c05840eu,0x0c058410u,0x0c058412u,0x0c058414u,0x0c058416u,0x0c058418u,0x0c05841au,0x0c05841cu,0x0c05841eu,0x0c058420u,0x0c058422u,0x0c058424u,0x0c058426u,0x0c058428u,
0x0c05842au,0x0c05842cu,0x0c05842eu,0x0c058430u,0x0c058432u,0x0c058434u,0x0c058436u,0x0c058438u,0x0c05843au,0x0c05843cu,0x0c05843eu,0x0c058440u,0x0c058442u,0x0c058444u,0x0c058446u,0x0c058448u,
0x0c05844au,0x0c05844cu,0x0c05844eu,0x0c058450u,0x0c058452u,0x0c058454u,0x0c058456u,0x0c058458u,0x0c05845au,0x0c05845cu,0x0c05845eu,0x0c058460u,0x0c058462u,0x0c058464u,0x0c058466u,0x0c058468u,
0x0c05846au,0x0c05846cu,0x0c05846eu,0x0c058470u,0x0c058472u,0x0c058474u,0x0c058476u,0x0c058478u,0x0c05847au,0x0c05847cu,0x0c05847eu,0x0c058480u,0x0c058482u,0x0c058484u,0x0c058486u,0x0c058488u,
0x0c05848au,0x0c05848cu,0x0c05848eu,0x0c058490u,0x0c058492u,0x0c058494u,0x0c058496u,0x0c058498u,0x0c05849au,0x0c05849cu,0x0c05849eu,0x0c0584a0u,0x0c0584a2u,0x0c0584a4u,0x0c0584a6u,0x0c0584a8u,
0x0c0584aau,0x0c0584acu,0x0c0584aeu,0x0c0584b0u,0x0c0584b2u,0x0c0584b4u,0x0c0584b6u,0x0c0584b8u,0x0c0584bau,0x0c0584bcu,0x0c0584beu,0x0c0584c0u,0x0c0584c2u,0x0c0584c4u,0x0c0584c6u,0x0c0584c8u,
0x0c0584cau,0x0c0584ccu,0x0c0584ceu,0x0c0584d0u,0x0c0584d2u,0x0c0584d4u,0x0c0584d6u,0x0c0584d8u,0x0c0584dau,0x0c0584dcu,0x0c0584deu,0x0c0584e0u,0x0c058540u,0x0c058542u,0x0c058544u,0x0c058546u,
0x0c058548u,0x0c05854au,0x0c05854cu,0x0c05854eu,0x0c058550u,0x0c058552u,0x0c058554u,0x0c058556u,0x0c058558u,0x0c05855au,0x0c05855cu,0x0c05855eu,0x0c058560u,0x0c058562u,0x0c058564u,0x0c058566u,
0x0c058568u,0x0c05856au,0x0c05856cu,0x0c05856eu,0x0c058570u,0x0c058572u,0x0c058574u,0x0c058576u,0x0c058578u,0x0c05857au,0x0c05857cu,0x0c05857eu,0x0c058580u,0x0c058582u,0x0c058584u,0x0c058586u,
0x0c058588u,0x0c05858au,0x0c05858cu,0x0c05858eu,0x0c058590u,0x0c058592u,0x0c058594u,0x0c058596u,0x0c058598u,0x0c05859au,0x0c05859cu,0x0c05859eu,0x0c0585a0u,0x0c0585a2u,0x0c0585a4u,0x0c0585a6u,
0x0c0585a8u,0x0c0585aau,0x0c0585acu,0x0c0585aeu,0x0c0585b0u,0x0c0585b2u,0x0c0585b4u,0x0c0585b6u,0x0c0585b8u,0x0c0585bau,0x0c0585bcu,0x0c0585beu,0x0c0585c0u,0x0c0585c2u,0x0c0585c4u,0x0c0585c6u,
0x0c0585c8u,0x0c0585cau,0x0c0585ccu,0x0c0585ceu,0x0c0585d0u,0x0c0585d2u,0x0c0585d4u,0x0c0585d6u,0x0c0585d8u,0x0c0585dau,0x0c0585dcu,0x0c0585deu,0x0c0585e0u,0x0c0585e2u,0x0c0585e4u,0x0c0585e6u,
0x0c0585e8u,0x0c0585eau,0x0c0585ecu,0x0c0585eeu,0x0c0585f0u,0x0c0585f2u,0x0c0585f4u,0x0c0585f6u,0x0c0585f8u,0x0c0585fau,0x0c0585fcu,0x0c0585feu,0x0c058600u,0x0c058602u,0x0c058604u,0x0c058606u,
0x0c058608u,0x0c05860au,0x0c05860cu,0x0c05860eu,0x0c058610u,0x0c058612u,0x0c058614u,0x0c058616u,0x0c058618u,0x0c05861au,0x0c05861cu,0x0c05861eu,0x0c058620u,0x0c058622u,0x0c058624u,0x0c058626u,
0x0c058628u,0x0c05862au,0x0c05862cu,0x0c05862eu,0x0c058630u,0x0c058632u,0x0c058634u,0x0c058636u,0x0c058638u,0x0c05863au,0x0c05863cu,0x0c05863eu,0x0c058640u,0x0c058642u,0x0c058644u,0x0c058646u,
0x0c058648u,0x0c05864au,0x0c05864cu,0x0c05864eu,0x0c058650u,0x0c058652u,0x0c058654u,0x0c058656u,0x0c058658u,0x0c05865au,0x0c058768u,0x0c05876au,0x0c05876cu,0x0c05876eu,0x0c058770u,0x0c058772u,
0x0c058774u,0x0c058776u,0x0c058778u,0x0c05877eu,0x0c058780u,0x0c058782u,0x0c058784u,0x0c058786u,0x0c058788u,0x0c05878au,0x0c05878cu,0x0c05878eu,0x0c058790u,0x0c05879au,0x0c05879cu,0x0c05879eu,
0x0c0587a0u,0x0c0587a2u,0x0c0587a4u,0x0c0587a6u,0x0c0587a8u,0x0c0587aau,0x0c0587acu,0x0c0587aeu,0x0c0587b0u,0x0c0587b2u,0x0c0587b4u,0x0c0587b6u,0x0c0587b8u,0x0c0587bau,0x0c0587bcu,0x0c0587beu,
0x0c0587c0u,0x0c0587c2u,0x0c0587c4u,0x0c0587c6u,0x0c0587c8u,0x0c0587cau,0x0c0587ccu,0x0c0587ceu,0x0c0587d0u,0x0c0587d2u,0x0c0587d4u,0x0c0587d6u,0x0c0587d8u,0x0c0587dau,0x0c0587dcu,0x0c0587deu,
0x0c0587e0u,0x0c0587e2u,0x0c0587e4u,0x0c0587e6u,0x0c0587e8u,0x0c0587eau,0x0c0587ecu,0x0c0587eeu,0x0c0587f0u,0x0c0587f2u,0x0c0587f4u,0x0c0587f6u,0x0c0587f8u,0x0c0587fau,0x0c0587fcu,0x0c0587feu,
0x0c058800u,0x0c058802u,0x0c058804u,0x0c058806u,0x0c058808u,0x0c05880au,0x0c05880cu,0x0c05880eu,0x0c058810u,0x0c058812u,0x0c058814u,0x0c058816u,0x0c058818u,0x0c05881au,0x0c05881cu,0x0c05881eu,
0x0c058820u,0x0c058822u,0x0c058824u,0x0c058826u,0x0c058828u,0x0c05882au,0x0c05882cu,0x0c05882eu,0x0c058830u,0x0c058832u,0x0c058834u,0x0c058836u,0x0c058838u,0x0c05883au,0x0c05883cu,0x0c05883eu,
0x0c058840u,0x0c058842u,0x0c058844u,0x0c058846u,0x0c058848u,0x0c05884au,0x0c05884cu,0x0c05884eu,0x0c058850u,0x0c058852u,0x0c058854u,0x0c058856u,0x0c058858u,0x0c05885au,0x0c05885cu,0x0c05885eu,
0x0c058860u,0x0c058862u,0x0c058864u,0x0c058866u,0x0c058868u,0x0c0588f0u,0x0c0588f2u,0x0c0588f4u,0x0c0588f6u,0x0c0588f8u,0x0c0588fau,0x0c0588fcu,0x0c0588feu,0x0c058900u,0x0c058902u,0x0c058904u,
0x0c058906u,0x0c058908u,0x0c05890au,0x0c05890cu,0x0c05890eu,0x0c058910u,0x0c058912u,0x0c058914u,0x0c058916u,0x0c058918u,0x0c05891au,0x0c05891cu,0x0c05891eu,0x0c058920u,0x0c058922u,0x0c058924u,
0x0c058926u,0x0c058928u,0x0c05892au,0x0c05892cu,0x0c05892eu,0x0c058930u,0x0c058932u,0x0c058934u,0x0c058936u,0x0c058938u,0x0c05893au,0x0c05893cu,0x0c05893eu,0x0c058940u,0x0c058942u,0x0c058944u,
0x0c058946u,0x0c058948u,0x0c05894au,0x0c05894cu,0x0c05894eu,0x0c058950u,0x0c058952u,0x0c058954u,0x0c058956u,0x0c058958u,0x0c05895au,0x0c05895cu,0x0c05895eu,0x0c058960u,0x0c058962u,0x0c058964u,
0x0c058966u,0x0c058968u,0x0c05896au,0x0c05896cu,0x0c05896eu,0x0c058970u,0x0c058972u,0x0c058974u,0x0c058976u,0x0c058a5cu,0x0c058a5eu,0x0c058a60u,0x0c058a62u,0x0c058a64u,0x0c058a66u,0x0c058a68u,
0x0c058a6au,0x0c058a6cu,0x0c058a6eu,0x0c058a70u,0x0c058a72u,0x0c058a74u,0x0c058a76u,0x0c058a78u,0x0c058a7au,0x0c058a7cu,0x0c058a7eu,0x0c058a80u,0x0c058a82u,0x0c058a84u,0x0c058a86u,0x0c058a88u,
0x0c058a8au,0x0c058a8cu,0x0c058a8eu,0x0c058a90u,0x0c058a92u,0x0c058a94u,0x0c058a96u,0x0c058a98u,0x0c058a9au,0x0c058a9cu,0x0c058a9eu,0x0c058aa0u,0x0c058aa2u,0x0c058aa4u,0x0c058aa6u,0x0c058aa8u,
0x0c058aaau,0x0c058aacu,0x0c058aaeu,0x0c058ab0u,0x0c058ab2u,0x0c058ab4u,0x0c058ab6u,0x0c058ab8u,0x0c058abau,0x0c058abcu,0x0c058abeu,0x0c058ac0u,0x0c058ac2u,0x0c058ac4u,0x0c058ac6u,0x0c058ac8u,
0x0c058acau,0x0c058accu,0x0c058aceu,0x0c058ad0u,0x0c058ad2u,0x0c058ad4u,0x0c058ad6u,0x0c058ad8u,0x0c058adau,0x0c058adcu,0x0c058adeu,0x0c058ae0u,0x0c058ae2u,0x0c058ae4u,0x0c058ae6u,0x0c058ae8u,
0x0c058aeau,0x0c058aecu,0x0c058aeeu,0x0c058af0u,0x0c058af2u,0x0c058af4u,0x0c058af6u,0x0c058af8u,0x0c058afau,0x0c058afcu,0x0c058afeu,0x0c058b00u,0x0c058b02u,0x0c058b04u,0x0c058b06u,0x0c058b08u,
0x0c058b0au,0x0c058b0cu,0x0c058b0eu,0x0c058b10u,0x0c058b12u,0x0c058b14u,0x0c058b16u,0x0c058b18u,0x0c058b1au,0x0c058b1cu,0x0c058b1eu,0x0c058b20u,0x0c058b22u,0x0c058b24u,0x0c058b26u,0x0c058b28u,
0x0c058b2au,0x0c058b2cu,0x0c058b2eu,0x0c058b30u,0x0c058b32u,0x0c058b34u,0x0c058b36u,0x0c058b38u,0x0c058b3au,0x0c058b3cu,0x0c058b3eu,0x0c058b40u,0x0c058b42u,0x0c058b44u,0x0c058b46u,0x0c058b48u,
0x0c058b4au,0x0c058b4cu,0x0c058b4eu,0x0c058b50u,0x0c058b52u,0x0c058b54u,0x0c058b56u,0x0c058b58u,0x0c059aeau,0x0c059aecu,0x0c059aeeu,0x0c059af0u,0x0c059af2u,0x0c059af4u,0x0c059af6u,0x0c059af8u,
0x0c059afau,0x0c059afcu,0x0c059afeu,0x0c059b00u,0x0c059b02u,0x0c059b04u,0x0c059b06u,0x0c059b08u,0x0c059b0au,0x0c059b0cu,0x0c059b40u,0x0c059b42u,0x0c059b44u,0x0c059b46u,0x0c059b48u,0x0c059b4au,
0x0c059b4cu,0x0c059b4eu,0x0c059b50u,0x0c059b52u,0x0c059b54u,0x0c059b56u,0x0c059b58u,0x0c059b5au,0x0c059b5cu,0x0c059b5eu,0x0c059b60u,0x0c059b62u,0x0c059b64u,0x0c059b66u,0x0c059b68u,0x0c059b6au,
0x0c059b6cu,0x0c059b6eu,0x0c059b70u,0x0c059b72u,0x0c059b74u,0x0c059b76u,0x0c059b78u,0x0c059b7au,0x0c059b7cu,0x0c059b7eu,0x0c059b80u,0x0c059b82u,0x0c059b84u,0x0c059b86u,0x0c059b88u,0x0c059b8au,
0x0c059b8cu,0x0c059b8eu,0x0c059b90u,0x0c059b92u,0x0c059b94u,0x0c059b96u,0x0c059b98u,0x0c059b9au,0x0c059b9cu,0x0c059b9eu,0x0c059ba0u,0x0c059ba2u,0x0c059ba4u,0x0c059ba6u,0x0c059ba8u,0x0c059baau,
0x0c059bacu,0x0c059baeu,0x0c059bb0u,0x0c059bb2u,0x0c059bb4u,0x0c059bb6u,0x0c059bb8u,0x0c059bbau,0x0c059bbcu,0x0c059bbeu,0x0c059bc0u,0x0c059bc2u,0x0c059bc4u,0x0c059bc6u,0x0c059bc8u,0x0c059bcau,
0x0c059bccu,0x0c059bceu,0x0c059bd0u,0x0c059bd2u,0x0c059bd4u,0x0c059bd6u,0x0c059bd8u,0x0c059bdau,0x0c059bdcu,0x0c059bdeu,0x0c059be0u,0x0c059be2u,0x0c059be4u,0x0c059be6u,0x0c059be8u,0x0c059beau,
0x0c059becu,0x0c059beeu,0x0c059bf0u,0x0c059bf2u,0x0c059bf4u,0x0c059bf6u,0x0c059bf8u,0x0c059bfau,0x0c059bfcu,0x0c059bfeu,0x0c059c00u,0x0c059c02u,0x0c059c04u,0x0c059c06u,0x0c059c08u,0x0c059c0au,
0x0c059c0cu,0x0c059c0eu,0x0c059c10u,0x0c059c12u,0x0c059c14u,0x0c059c16u,0x0c059c18u,0x0c059c1au,0x0c059c1cu,0x0c059c1eu,0x0c059c88u,0x0c059c8au,0x0c059c8cu,0x0c059c8eu,0x0c059c90u,0x0c059c92u,
0x0c059c94u,0x0c059c96u,0x0c059c98u,0x0c059c9au,0x0c059c9cu,0x0c059c9eu,0x0c059ca0u,0x0c059ca2u,0x0c059ca4u,0x0c059ca6u,0x0c059ca8u,0x0c059caau,0x0c059cacu,0x0c059caeu,0x0c059cb0u,0x0c059cb2u,
0x0c059cb4u,0x0c059cb6u,0x0c059cb8u,0x0c059cbau,0x0c059cbcu,0x0c059cbeu,0x0c059cc0u,0x0c059cc2u,0x0c059cc4u,0x0c059cc6u,0x0c059cc8u,0x0c059ccau,0x0c059cccu,0x0c059cceu,0x0c059cd0u,0x0c059cd2u,
0x0c059cd4u,0x0c059cd6u,0x0c059cd8u,0x0c059cdau,0x0c059cdcu,0x0c059cdeu,0x0c059ce0u,0x0c059ce2u,0x0c059ce4u,0x0c059ce6u,0x0c059ce8u,0x0c059ceau,0x0c059cecu,0x0c059ceeu,0x0c059cf0u,0x0c059cf2u,
0x0c059cf4u,0x0c059cf6u,0x0c059cf8u,0x0c059cfau,0x0c059cfcu,0x0c059cfeu,0x0c059d00u,0x0c059d02u,0x0c059d04u,0x0c059d06u,0x0c059d08u,0x0c059d0au,0x0c059d0cu,0x0c059d0eu,0x0c059d10u,0x0c059d12u,
0x0c059d14u,0x0c059d16u,0x0c059d18u,0x0c059d1au,0x0c059d1cu,0x0c059d1eu,0x0c059d20u,0x0c059d22u,0x0c059d24u,0x0c059d26u,0x0c059d28u,0x0c059d2au,0x0c059d2cu,0x0c059d2eu,0x0c059d30u,0x0c059d32u,
0x0c059d34u,0x0c059d36u,0x0c059d38u,0x0c059d3au,0x0c059d3cu,0x0c059d3eu,0x0c059d40u,0x0c059d42u,0x0c059d44u,0x0c059d46u,0x0c059d48u,0x0c059d4au,0x0c059d4cu,0x0c059d4eu,0x0c059d50u,0x0c059d52u,
0x0c059d54u,0x0c059d56u,0x0c059d58u,0x0c059d5au,0x0c059d5cu,0x0c059d5eu,0x0c059d60u,0x0c059d62u,0x0c059d64u,0x0c059d66u,0x0c059d68u,0x0c059d6au,0x0c059d6cu,0x0c059d6eu,0x0c059d70u,0x0c060fd6u,
0x0c060fd8u,0x0c060fdau,0x0c060fdcu,0x0c060fdeu,0x0c060fe0u,0x0c060fe2u,0x0c060fe4u,0x0c060fe6u,0x0c060fe8u,0x0c060feau,0x0c060fecu,0x0c060feeu,0x0c060ff0u,0x0c060ff2u,0x0c060ff4u,0x0c060ff6u,
0x0c060ff8u,0x0c060ffau,0x0c060ffcu,0x0c060ffeu,0x0c061000u,0x0c061002u,0x0c061004u,0x0c061006u,0x0c061008u,0x0c06100au,0x0c06100cu,0x0c061054u,0x0c061056u,0x0c061058u,0x0c06105au,0x0c06105cu,
0x0c06105eu,0x0c061060u,0x0c061062u,0x0c061064u,0x0c061066u,0x0c061068u,0x0c06106au,0x0c06106cu,0x0c06106eu,0x0c061070u,0x0c061072u,0x0c061074u,0x0c061076u,0x0c061078u,0x0c06107au,0x0c06107cu,
0x0c06107eu,0x0c061080u,0x0c061082u,0x0c061084u,0x0c061086u,0x0c061088u,0x0c06108au,0x0c06108cu,0x0c06108eu,0x0c061090u,0x0c061092u,0x0c061094u,0x0c061096u,0x0c061098u,0x0c06109au,0x0c06109cu,
0x0c06109eu,0x0c0610a0u,0x0c0610a2u,0x0c0610a4u,0x0c0610a6u,0x0c0610a8u,0x0c0610aau,0x0c0610acu,0x0c0610aeu,0x0c0610b0u,0x0c0610b2u,0x0c0610b4u,0x0c0610b6u,0x0c0610b8u,0x0c0610bau,0x0c0610bcu,
0x0c0610beu,0x0c0610c0u,0x0c0610c2u,0x0c0610c4u,0x0c0610c6u,0x0c0610c8u,0x0c0610cau,0x0c0610ccu,0x0c0610ceu,0x0c0610d0u,0x0c0610d2u,0x0c0610d4u,0x0c0610d6u,0x0c0610d8u,0x0c0610dau,0x0c0610dcu,
0x0c0610deu,0x0c0610e0u,0x0c0610e2u,0x0c0610e4u,0x0c0610e6u,0x0c0610e8u,0x0c0610eau,0x0c0610ecu,0x0c0610eeu,0x0c0610f0u,0x0c0610f2u,0x0c0610f4u,0x0c0610f6u,0x0c0610f8u,0x0c0610fau,0x0c0610fcu,
0x0c0610feu,0x0c061100u,0x0c061102u,0x0c061104u,0x0c061106u,0x0c061108u,0x0c06110au,0x0c06110cu,0x0c06110eu,0x0c061110u,0x0c061112u,0x0c061114u,0x0c061116u,0x0c061118u,0x0c06111au,0x0c06111cu,
0x0c06111eu,0x0c061120u,0x0c061122u,0x0c061124u,0x0c061126u,0x0c061128u,0x0c06112au,0x0c06112cu,0x0c06112eu,0x0c061130u,0x0c061132u,0x0c061134u,0x0c061136u,0x0c061138u,0x0c06113au,0x0c06113cu,
0x0c06113eu,0x0c061140u,0x0c063446u,0x0c063448u,0x0c06344au,0x0c06344cu,0x0c06344eu,0x0c063450u,0x0c063452u,0x0c063454u,0x0c063456u,0x0c063458u,0x0c06345au,0x0c06345cu,0x0c06345eu,0x0c063460u,
0x0c063462u,0x0c063464u,0x0c063466u,0x0c063468u,0x0c06346au,0x0c06346cu,0x0c06346eu,0x0c063470u,0x0c063472u,0x0c063474u,0x0c063476u,0x0c063478u,0x0c06347au,0x0c06347cu,0x0c06347eu,0x0c063480u,
0x0c063482u,0x0c063484u,0x0c063486u,0x0c063488u,0x0c06348au,0x0c06348cu,0x0c06348eu,0x0c063490u,0x0c063492u,0x0c063494u,0x0c063496u,0x0c063498u,0x0c06349au,0x0c06349cu,0x0c06349eu,0x0c0634a0u,
0x0c0634a2u,0x0c0634a4u,0x0c0634a6u,0x0c0634a8u,0x0c0634aau,0x0c0634acu,0x0c0634aeu,0x0c0634b0u,0x0c0634b2u,0x0c0634b4u,0x0c0634b6u,0x0c0634b8u,0x0c0634bau,0x0c0634bcu,0x0c0634beu,0x0c0634c0u,
0x0c0634c2u,0x0c0634c4u,0x0c0634c6u,0x0c0634c8u,0x0c0634cau,0x0c0634ccu,0x0c0634ceu,0x0c0634d0u,0x0c0634d2u,0x0c0634d4u,0x0c0634d6u,0x0c0634d8u,0x0c0634dau,0x0c0634dcu,0x0c0634deu,0x0c0634e0u,
0x0c0634e2u,0x0c0634e4u,0x0c0634e6u,0x0c0634e8u,0x0c0634eau,0x0c0634ecu,0x0c06351cu,0x0c06351eu,0x0c063520u,0x0c063522u,0x0c063524u,0x0c063526u,0x0c063528u,0x0c06352au,0x0c06352cu,0x0c06352eu,
0x0c063530u,0x0c063532u,0x0c063534u,0x0c063536u,0x0c063538u,0x0c06353au,0x0c06353cu,0x0c06353eu,0x0c063540u,0x0c063542u,0x0c063544u,0x0c063546u,0x0c063548u,0x0c06354au,0x0c06354cu,0x0c06354eu,
0x0c063550u,0x0c063552u,0x0c063554u,0x0c063556u,0x0c063558u,0x0c06355au,0x0c06355cu,0x0c06355eu,0x0c063560u,0x0c063562u,0x0c063564u,0x0c063566u,0x0c063568u,0x0c06356au,0x0c06356cu,0x0c06356eu,
0x0c063570u,0x0c063572u,0x0c063574u,0x0c063576u,0x0c063578u,0x0c06357au,0x0c06357cu,0x0c06357eu,0x0c063580u,0x0c063582u,0x0c063584u,0x0c063586u,0x0c063588u,0x0c06358au,0x0c06358cu,0x0c06358eu,
0x0c063590u,0x0c063592u,0x0c063594u,0x0c063596u,0x0c063598u,0x0c06359au,0x0c06359cu,0x0c06359eu,0x0c0635a0u,0x0c0635a2u,0x0c0635a4u,0x0c0635a6u,0x0c0635a8u,0x0c0635aau,0x0c0635acu,0x0c0635aeu,
0x0c0635b0u,0x0c0635b2u,0x0c0635b4u,0x0c0635b6u,0x0c0635b8u,0x0c0635bau,0x0c0635bcu,0x0c0635beu,0x0c0635c0u,0x0c0635c2u,0x0c0635c4u,0x0c0635c6u,0x0c0635c8u,0x0c0635cau,0x0c0635ccu,0x0c0635ceu,
0x0c0635d0u,0x0c0635d2u,0x0c0635d4u,0x0c0635d6u,0x0c0635d8u,0x0c0635dau,0x0c0635dcu,0x0c0635deu,0x0c0635e0u,0x0c0635e2u,0x0c0635e4u,0x0c0635e6u,0x0c0635e8u,0x0c0635eau,0x0c0635ecu,0x0c0635eeu,
0x0c0635f0u,0x0c0635f2u,0x0c0635f4u,0x0c0635f6u,0x0c0635f8u,0x0c0635fau,0x0c0635fcu,0x0c0635feu,0x0c063600u,0x0c063602u,0x0c063604u,0x0c063606u,0x0c063608u,0x0c06360au,0x0c06360cu,0x0c06360eu,
0x0c063610u,0x0c063612u,0x0c063614u,0x0c063680u,0x0c063682u,0x0c063684u,0x0c063686u,0x0c063688u,0x0c06368au,0x0c06368cu,0x0c06368eu,0x0c063690u,0x0c063692u,0x0c063694u,0x0c063696u,0x0c063698u,
0x0c06369au,0x0c06369cu,0x0c06369eu,0x0c07a856u,0x0c07a858u,0x0c07a85au,0x0c07a85cu,0x0c07a85eu,0x0c07a860u,0x0c07a862u,0x0c07a864u,0x0c07a866u,0x0c07a868u,0x0c07a86au,0x0c07a86cu,0x0c07a86eu,
0x0c07a870u,0x0c07a872u,0x0c07a874u,0x0c07a876u,0x0c07a878u,0x0c07a87au,0x0c07a87cu,0x0c07a87eu,0x0c07a880u,0x0c07a882u,0x0c07a884u,0x0c07a886u,0x0c07a888u,0x0c07a88au,0x0c07a88cu,0x0c07a88eu,
0x0c07a890u,0x0c07a892u,0x0c07a894u,0x0c07a896u,0x0c07a898u,0x0c07a89au,0x0c07a89cu,0x0c07a89eu,0x0c07a8a0u,0x0c07a8a2u,0x0c07a8a4u,0x0c07a8a6u,0x0c07a8a8u,0x0c07a8aau,0x0c07a8acu,0x0c07a8aeu,
0x0c07a8b0u,0x0c07a8b2u,0x0c07a8b4u,0x0c07a8b6u,0x0c07a8b8u,0x0c07a8bau,0x0c07a8bcu,0x0c07a8beu,0x0c07a8c0u,0x0c07a8c2u,0x0c07a8c4u,0x0c07a8c6u,0x0c07a8c8u,0x0c07a8cau,0x0c07a8ccu,0x0c07a8ceu,
0x0c07a8d0u,0x0c07a8d2u,0x0c07a8d4u,0x0c07a8d6u,0x0c07a8d8u,0x0c07a8dau,0x0c07a8dcu,0x0c07a8deu,0x0c07a8e0u,0x0c07a8e2u,0x0c07a8e4u,0x0c07a8e6u,0x0c07a8e8u,0x0c07a8eau,0x0c07a8ecu,0x0c07a8eeu,
0x0c07a8f0u,0x0c07a8f2u,0x0c07a8f4u,0x0c07a8f6u,0x0c07a8f8u,0x0c07a8fau,0x0c07a8fcu,0x0c07a8feu,0x0c07a900u,0x0c07a902u,0x0c07a904u,0x0c07a906u,0x0c07a908u,0x0c07a90au,0x0c07a90cu,0x0c07a90eu,
0x0c07a910u,0x0c07a912u,0x0c07a914u,0x0c07a916u,0x0c07a918u,0x0c07a91au,0x0c07a91cu,0x0c07a91eu,0x0c07a920u,0x0c07a922u,0x0c07a924u,0x0c07a926u,0x0c07a928u,0x0c07a92au,0x0c07a92cu,0x0c07a92eu,
0x0c07a930u,0x0c07a932u,0x0c07a934u,0x0c07a936u,0x0c07a938u,0x0c07a93au,0x0c07a93cu,0x0c07a93eu,0x0c07a940u,0x0c07a942u,0x0c07a944u,0x0c07a946u,0x0c07a948u,0x0c07a94au,0x0c07a94cu,0x0c07a94eu,
0x0c07a950u,0x0c07a952u,0x0c07a954u,0x0c07a956u,0x0c07a958u,0x0c07a95au,0x0c07a95cu,0x0c07a95eu,0x0c07a960u,0x0c07a962u,0x0c07a964u,0x0c07a966u,0x0c07a968u,0x0c07a96au,0x0c07a96cu,0x0c07a96eu,
0x0c07a970u,0x0c07a972u,0x0c07a974u,0x0c07a976u,0x0c07a978u,0x0c07a97au,0x0c07a97cu,0x0c07a97eu,0x0c07a980u,0x0c07a982u,0x0c07a984u,0x0c07a986u,0x0c07a988u,0x0c07a98au,0x0c07a98cu,0x0c07a98eu,
0x0c07a990u,0x0c07a992u,0x0c07a994u,0x0c07a996u,0x0c07a998u,0x0c07a99au,0x0c07a99cu,0x0c07a99eu,0x0c07a9a0u,0x0c07a9a2u,0x0c07a9a4u,0x0c07a9a6u,0x0c07a9a8u,0x0c07a9aau,0x0c07a9acu,0x0c07a9aeu,
0x0c07a9b0u,0x0c07a9b2u,0x0c07a9f8u,0x0c07a9fau,0x0c07a9fcu,0x0c07a9feu,0x0c07aa00u,0x0c07aa02u,0x0c07aa04u,0x0c07aa06u,0x0c07aa08u,0x0c07aa0au,0x0c07aa0cu,0x0c07aa0eu,0x0c07aa10u,0x0c07aa12u,
0x0c07aa14u,0x0c07aa16u,0x0c07aa18u,0x0c07aa1au,0x0c07aa1cu,0x0c07aa1eu,0x0c07aa20u,0x0c07aa22u,0x0c07aa24u,0x0c07aa26u,0x0c07aa28u,0x0c07aa2au,0x0c07aa2cu,0x0c07aa2eu,0x0c099d74u,0x0c099d76u,
0x0c099d78u,0x0c099d7au,0x0c099d7cu,0x0c099d7eu,0x0c099d80u,0x0c099d82u,0x0c099d84u,0x0c099d86u,0x0c099d88u,0x0c099d8au,0x0c099d8cu,0x0c099d8eu,0x0c099d90u,0x0c099d92u,0x0c099d94u,0x0c099d96u,
0x0c099d98u,0x0c099d9au,0x0c099d9cu,0x0c099d9eu,0x0c099de0u,0x0c099de2u,0x0c099de4u,0x0c099de6u,0x0c099de8u,0x0c099deau,0x0c099decu,0x0c099deeu,0x0c099df0u,0x0c099df2u,0x0c099df4u,0x0c099df6u,
0x0c099df8u,0x0c099dfau,0x0c099dfcu,0x0c099dfeu,0x0c099e00u,0x0c099e02u,0x0c099e04u,0x0c099e06u,0x0c099e08u,0x0c099e0au,0x0c099e0cu,0x0c099e0eu,0x0c099e10u,0x0c099e12u,0x0c099e14u,0x0c099e16u,
0x0c099e18u,0x0c099e1au,0x0c099e1cu,0x0c099e1eu,0x0c099e20u,0x0c099e22u,0x0c099e24u,0x0c099e26u,0x0c099e28u,0x0c099e2au,0x0c099e2cu,0x0c099e2eu,0x0c099e30u,0x0c099e32u,0x0c099e34u,0x0c099e36u,
0x0c099e38u,0x0c099e3au,0x0c099e3cu,0x0c099e3eu,0x0c099e40u,0x0c099e42u,0x0c099e44u,0x0c099e46u,0x0c099e48u,0x0c099e4au,0x0c099e4cu,0x0c099e4eu,0x0c099e50u,0x0c099e52u,0x0c099e54u,0x0c099e56u,
0x0c099e58u,0x0c099e5au,0x0c099e5cu,0x0c099e5eu,0x0c099e60u,0x0c099e62u,0x0c099e64u,0x0c099e66u,0x0c099e68u,0x0c099e6au,0x0c099e6cu,0x0c099e6eu,0x0c099e70u,0x0c099e72u,0x0c099e74u,0x0c099e76u,
0x0c099e78u,0x0c099e7au,0x0c099e7cu,0x0c099e7eu,0x0c099e80u,0x0c099e82u,0x0c099e84u,0x0c099e86u,0x0c099e88u,0x0c099e8au,0x0c099e8cu,0x0c099e8eu,0x0c099e90u,0x0c099e92u,0x0c099e94u,0x0c099e96u,
0x0c099e98u,0x0c099e9au,0x0c099e9cu,0x0c099e9eu,0x0c099ea0u,0x0c099ea2u,0x0c099ea4u,0x0c099ea6u,0x0c099ea8u,0x0c099eaau,0x0c099eacu,0x0c099eaeu,0x0c099eb0u,0x0c099eb2u,0x0c099eb4u,0x0c099eb6u,
0x0c099eb8u,0x0c099ebau,0x0c099ebcu,0x0c099ebeu,0x0c099ec0u,0x0c099ec2u,0x0c099ec4u,0x0c099ec6u,0x0c099ec8u,0x0c099ecau,0x0c099eccu,0x0c099eceu,0x0c099ed0u,0x0c099ed2u,0x0c099ed4u,0x0c099ed6u,
0x0c099f00u,0x0c099f02u,0x0c099f04u,0x0c099f06u,0x0c099f08u,0x0c099f0au,0x0c099f0cu,0x0c099f0eu,0x0c099f10u,0x0c099f12u,0x0c099f14u,0x0c099f16u,0x0c099f18u,0x0c099f1au,0x0c099f1cu,0x0c099f1eu,
0x0c099f20u,0x0c099f22u,0x0c099f24u,0x0c099f26u,0x0c099f28u,0x0c099f2au,0x0c099f2cu,0x0c099f2eu,0x0c099f30u,0x0c099f32u,0x0c099f34u,0x0c099f36u,0x0c099f38u,0x0c099f3au,0x0c099f3cu,0x0c099f3eu,
0x0c099f40u,0x0c099f42u,0x0c099f44u,0x0c099f46u,0x0c099f48u,0x0c099f4au,0x0c099f4cu,0x0c099f4eu,0x0c099f50u,0x0c099f52u,0x0c099f54u,0x0c099f56u,0x0c099f58u,0x0c099f5au,0x0c099f5cu,0x0c099f5eu,
0x0c099f60u,0x0c099f62u,0x0c099f64u,0x0c099f66u,0x0c099f68u,0x0c099f6au,0x0c099f6cu,0x0c099f6eu,0x0c099f70u,0x0c099f72u,0x0c099f74u,0x0c099f76u,0x0c099f78u,0x0c099f7au,0x0c099f7cu,0x0c099f7eu,
0x0c099f80u,0x0c099f82u,0x0c099f84u,0x0c099f86u,0x0c099f88u,0x0c099f8au,0x0c099f8cu,0x0c099f8eu,0x0c099f90u,0x0c099f92u,0x0c099f94u,0x0c099f96u,0x0c099f98u,0x0c099f9au,0x0c099f9cu,0x0c099f9eu,
0x0c099fa0u,0x0c099fa2u,0x0c099fa4u,0x0c099fa6u,0x0c099fa8u,0x0c099faau,0x0c099facu,0x0c099faeu,0x0c099fb0u,0x0c099fb2u,0x0c099fb4u,0x0c099fb6u,0x0c099fb8u,0x0c099fbau,0x0c099fbcu,0x0c099fbeu,
0x0c099fc0u,0x0c099fc2u,0x0c099fc4u,0x0c099fc6u,0x0c099fc8u,0x0c099fcau,0x0c099fccu,0x0c099fceu,0x0c099fd0u,0x0c099fd2u,0x0c099fd4u,0x0c099fd6u,0x0c099fd8u,0x0c099fdau,0x0c099fdcu,0x0c099fdeu,
0x0c099fe0u,0x0c099fe2u,0x0c099fe4u,0x0c099fe6u,0x0c099fe8u,0x0c099feau,0x0c099fecu,0x0c099feeu,0x0c099ff0u,0x0c099ff2u,0x0c099ff4u,0x0c099ff6u,0x0c099ff8u,0x0c09a01cu,0x0c09a01eu,0x0c09a020u,
0x0c09a022u,0x0c09a024u,0x0c09a026u,0x0c09a028u,0x0c09a02au,0x0c09a02cu,0x0c09a02eu,0x0c09a030u,0x0c09a032u,0x0c09a034u,0x0c09a036u,0x0c09a038u,0x0c09a03au,0x0c09a03cu,0x0c09a03eu,0x0c09a040u,
0x0c09a042u,0x0c09a044u,0x0c09a046u,0x0c09a048u,0x0c09a04au,0x0c09a04cu,0x0c09a04eu,0x0c09a050u,0x0c09a052u,0x0c09a054u,0x0c09a056u,0x0c09a058u,0x0c09a05au,0x0c09a05cu,0x0c09a05eu,0x0c09a060u,
0x0c09a062u,0x0c09a064u,0x0c09a066u,0x0c09a068u,0x0c09a06au,0x0c09a06cu,0x0c09a06eu,0x0c09a070u,0x0c09a072u,0x0c09a074u,0x0c09a076u,0x0c09a078u,0x0c09a07au,0x0c09a07cu,0x0c09a07eu,0x0c09a080u,
0x0c09a082u,0x0c09a084u,0x0c0c76d4u,0x0c0c76d6u,0x0c0c76d8u,0x0c0c76dau,0x0c0c76dcu,0x0c0c76deu,0x0c0c76e0u,0x0c0c76e2u,0x0c0c76e4u,0x0c0c76e6u,0x0c0c76e8u,0x0c0c76eau,0x0c0c76ecu,0x0c0c76eeu,
0x0c0c76f0u,0x0c0c76f2u,0x0c0c76f4u,0x0c0c76f6u,0x0c0c76f8u,0x0c0c76fau,0x0c0c76fcu,0x0c0c76feu,0x0c0c7700u,0x0c0c7702u,0x0c0c7704u,0x0c0c7706u,0x0c0c7708u,0x0c0c770au,0x0c0c770cu,0x0c0c770eu,
0x0c0c7710u,0x0c0c7712u,0x0c0c7714u,0x0c0c7716u,0x0c0c7718u,0x0c0c771au,0x0c0c771cu,0x0c0c771eu,0x0c0c7720u,0x0c0c7722u,0x0c0c7724u,0x0c0c7726u,0x0c0c7728u,0x0c0c772au,0x0c0c772cu,0x0c0c772eu,
0x0c0c7730u,0x0c0c7732u,0x0c0c7734u,0x0c0c7736u,0x0c0c7738u,0x0c0c773au,0x0c0c773cu,0x0c0c773eu,0x0c0c7740u,0x0c0c7742u,0x0c0c7744u,0x0c0c7746u,0x0c0c7778u,0x0c0c777au,0x0c0c777cu,0x0c0c777eu,
0x0c0c7780u,0x0c0c7782u,0x0c0c7784u,0x0c0c7786u,0x0c0c7788u,0x0c0c778au,0x0c0c778cu,0x0c0c778eu,0x0c0c7790u,0x0c0c7792u,0x0c0c7794u,0x0c0c7796u,0x0c0c7798u,0x0c0c779au,0x0c0c779cu,0x0c0c779eu,
0x0c0c77a0u,0x0c0c77a2u,0x0c0c77a4u,0x0c0c77a6u,0x0c0c77a8u,0x0c0c77aau,0x0c0c77acu,0x0c0c77aeu,0x0c0c77b0u,0x0c0c77b2u,0x0c0c77b4u,0x0c0c77b6u,0x0c0c77b8u,0x0c0c77bau,0x0c0c77bcu,0x0c0c77beu,
0x0c0c77c0u,0x0c0c77c2u,0x0c0c77c4u,0x0c0c77c6u,0x0c0c77c8u,0x0c0c77cau,0x0c0c77ccu,0x0c0c77ceu,0x0c0c77d0u,0x0c0c77d2u,0x0c0c77d4u,0x0c0c77d6u,0x0c0c77d8u,0x0c0c77dau,0x0c0c77dcu,0x0c0c77deu,
0x0c0c77e0u,0x0c0c77e2u,0x0c0c77e4u,0x0c0c77e6u,0x0c0c77e8u,0x0c0c77eau,0x0c0c77ecu,0x0c0c77eeu,0x0c0c77f0u,0x0c0c77f2u,0x0c0c77f4u,0x0c0c77f6u,0x0c0c77f8u,0x0c0c77fau,0x0c0c77fcu,0x0c0c77feu,
0x0c0c7800u,0x0c0c7802u,0x0c0c7804u,0x0c0c7806u,0x0c0c7808u,0x0c0c780au,0x0c0c780cu,0x0c0c780eu,0x0c0c7810u,0x0c0c7812u,0x0c0c7814u,0x0c0c7816u,0x0c0c7818u,0x0c0c781au,0x0c0c781cu,0x0c0c781eu,
0x0c0c7820u,0x0c0c7822u,0x0c0c7824u,0x0c0c7826u,0x0c0c7828u,0x0c0c782au,0x0c0c782cu,0x0c0c782eu,0x0c0c7830u,0x0c0c7832u,0x0c0c7834u,0x0c0c7836u,0x0c0c7838u,0x0c0c783au,0x0c0c783cu,0x0c0c783eu,
0x0c0c7840u,0x0c0c7842u,0x0c0c7844u,0x0c0c7846u,0x0c0c7848u,0x0c0c784au,0x0c0c784cu,0x0c0c784eu,0x0c0c7850u,0x0c0c7852u,0x0c0c7854u,0x0c0c7856u,0x0c0c7858u,0x0c0c785au,0x0c0c785cu,
};
int vf3_c90_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
