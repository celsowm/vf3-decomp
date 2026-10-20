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
int vf3_c82_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c020024u: goto P_0c020024;
case 0x0c020026u: goto P_0c020026;
case 0x0c020028u: goto P_0c020028;
case 0x0c02002au: goto P_0c02002a;
case 0x0c02002cu: goto P_0c02002c;
case 0x0c02002eu: goto P_0c02002e;
case 0x0c020030u: goto P_0c020030;
case 0x0c020032u: goto P_0c020032;
case 0x0c020034u: goto P_0c020034;
case 0x0c020036u: goto P_0c020036;
case 0x0c020038u: goto P_0c020038;
case 0x0c02003au: goto P_0c02003a;
case 0x0c02003cu: goto P_0c02003c;
case 0x0c02003eu: goto P_0c02003e;
case 0x0c020040u: goto P_0c020040;
case 0x0c020042u: goto P_0c020042;
case 0x0c020044u: goto P_0c020044;
case 0x0c020046u: goto P_0c020046;
case 0x0c020048u: goto P_0c020048;
case 0x0c02004au: goto P_0c02004a;
case 0x0c02004cu: goto P_0c02004c;
case 0x0c02004eu: goto P_0c02004e;
case 0x0c020050u: goto P_0c020050;
case 0x0c020052u: goto P_0c020052;
case 0x0c020054u: goto P_0c020054;
case 0x0c020056u: goto P_0c020056;
case 0x0c020058u: goto P_0c020058;
case 0x0c02005au: goto P_0c02005a;
case 0x0c02005cu: goto P_0c02005c;
case 0x0c02005eu: goto P_0c02005e;
case 0x0c020060u: goto P_0c020060;
case 0x0c020062u: goto P_0c020062;
case 0x0c020064u: goto P_0c020064;
case 0x0c020066u: goto P_0c020066;
case 0x0c020068u: goto P_0c020068;
case 0x0c02006au: goto P_0c02006a;
case 0x0c02006cu: goto P_0c02006c;
case 0x0c02006eu: goto P_0c02006e;
case 0x0c020070u: goto P_0c020070;
case 0x0c020072u: goto P_0c020072;
case 0x0c020074u: goto P_0c020074;
case 0x0c020076u: goto P_0c020076;
case 0x0c020078u: goto P_0c020078;
case 0x0c02007au: goto P_0c02007a;
case 0x0c02007cu: goto P_0c02007c;
case 0x0c02007eu: goto P_0c02007e;
case 0x0c039fd0u: goto P_0c039fd0;
case 0x0c039fd2u: goto P_0c039fd2;
case 0x0c039fd4u: goto P_0c039fd4;
case 0x0c039fd6u: goto P_0c039fd6;
case 0x0c039fd8u: goto P_0c039fd8;
case 0x0c039fdau: goto P_0c039fda;
case 0x0c039fdcu: goto P_0c039fdc;
case 0x0c039fdeu: goto P_0c039fde;
case 0x0c039fe0u: goto P_0c039fe0;
case 0x0c039fe2u: goto P_0c039fe2;
case 0x0c039fe4u: goto P_0c039fe4;
case 0x0c039fe6u: goto P_0c039fe6;
case 0x0c039fe8u: goto P_0c039fe8;
case 0x0c039feau: goto P_0c039fea;
case 0x0c039fecu: goto P_0c039fec;
case 0x0c039feeu: goto P_0c039fee;
case 0x0c039ff0u: goto P_0c039ff0;
case 0x0c039ff2u: goto P_0c039ff2;
case 0x0c039ff4u: goto P_0c039ff4;
case 0x0c039ff6u: goto P_0c039ff6;
case 0x0c039ff8u: goto P_0c039ff8;
case 0x0c039ffau: goto P_0c039ffa;
case 0x0c039ffcu: goto P_0c039ffc;
case 0x0c039ffeu: goto P_0c039ffe;
case 0x0c03a000u: goto P_0c03a000;
case 0x0c03a002u: goto P_0c03a002;
case 0x0c03a004u: goto P_0c03a004;
case 0x0c03a006u: goto P_0c03a006;
case 0x0c03a008u: goto P_0c03a008;
case 0x0c03a00au: goto P_0c03a00a;
case 0x0c03a00cu: goto P_0c03a00c;
case 0x0c03a00eu: goto P_0c03a00e;
case 0x0c03a010u: goto P_0c03a010;
case 0x0c03a012u: goto P_0c03a012;
case 0x0c03a014u: goto P_0c03a014;
case 0x0c03a016u: goto P_0c03a016;
case 0x0c03a018u: goto P_0c03a018;
case 0x0c03a01au: goto P_0c03a01a;
case 0x0c03a01cu: goto P_0c03a01c;
case 0x0c03a01eu: goto P_0c03a01e;
case 0x0c03a020u: goto P_0c03a020;
case 0x0c03a022u: goto P_0c03a022;
case 0x0c03a024u: goto P_0c03a024;
case 0x0c03a026u: goto P_0c03a026;
case 0x0c03a028u: goto P_0c03a028;
case 0x0c03a02au: goto P_0c03a02a;
case 0x0c03a02cu: goto P_0c03a02c;
case 0x0c03a02eu: goto P_0c03a02e;
case 0x0c03a030u: goto P_0c03a030;
case 0x0c03a032u: goto P_0c03a032;
case 0x0c03a034u: goto P_0c03a034;
case 0x0c03a040u: goto P_0c03a040;
case 0x0c03a042u: goto P_0c03a042;
case 0x0c03a044u: goto P_0c03a044;
case 0x0c03a046u: goto P_0c03a046;
case 0x0c03a048u: goto P_0c03a048;
case 0x0c03a04au: goto P_0c03a04a;
case 0x0c03a04cu: goto P_0c03a04c;
case 0x0c03a04eu: goto P_0c03a04e;
case 0x0c03a050u: goto P_0c03a050;
case 0x0c03a052u: goto P_0c03a052;
case 0x0c03a054u: goto P_0c03a054;
case 0x0c03a07cu: goto P_0c03a07c;
case 0x0c03a07eu: goto P_0c03a07e;
case 0x0c03a080u: goto P_0c03a080;
case 0x0c03a082u: goto P_0c03a082;
case 0x0c03a084u: goto P_0c03a084;
case 0x0c03a086u: goto P_0c03a086;
case 0x0c03a088u: goto P_0c03a088;
case 0x0c03a08au: goto P_0c03a08a;
case 0x0c03a08cu: goto P_0c03a08c;
case 0x0c03a08eu: goto P_0c03a08e;
case 0x0c03a090u: goto P_0c03a090;
case 0x0c03a092u: goto P_0c03a092;
case 0x0c03a094u: goto P_0c03a094;
case 0x0c03a096u: goto P_0c03a096;
case 0x0c03a0a0u: goto P_0c03a0a0;
case 0x0c03a0a2u: goto P_0c03a0a2;
case 0x0c03a0a4u: goto P_0c03a0a4;
case 0x0c03a0a6u: goto P_0c03a0a6;
case 0x0c03a0a8u: goto P_0c03a0a8;
case 0x0c03a0aau: goto P_0c03a0aa;
case 0x0c03a0b0u: goto P_0c03a0b0;
case 0x0c03a0b2u: goto P_0c03a0b2;
case 0x0c03a0b4u: goto P_0c03a0b4;
case 0x0c03a0b6u: goto P_0c03a0b6;
case 0x0c03a0b8u: goto P_0c03a0b8;
case 0x0c03a0bau: goto P_0c03a0ba;
case 0x0c03a0c0u: goto P_0c03a0c0;
case 0x0c03a0c2u: goto P_0c03a0c2;
case 0x0c03a0c4u: goto P_0c03a0c4;
case 0x0c03a0c6u: goto P_0c03a0c6;
case 0x0c03a0c8u: goto P_0c03a0c8;
case 0x0c03a0d0u: goto P_0c03a0d0;
case 0x0c03a0d2u: goto P_0c03a0d2;
case 0x0c03a0d4u: goto P_0c03a0d4;
case 0x0c03a0d6u: goto P_0c03a0d6;
case 0x0c03a0d8u: goto P_0c03a0d8;
case 0x0c03a0dau: goto P_0c03a0da;
case 0x0c03a0dcu: goto P_0c03a0dc;
case 0x0c03a0deu: goto P_0c03a0de;
case 0x0c03a0e0u: goto P_0c03a0e0;
case 0x0c03a0e2u: goto P_0c03a0e2;
case 0x0c03a0e4u: goto P_0c03a0e4;
case 0x0c03a0e6u: goto P_0c03a0e6;
case 0x0c03a0e8u: goto P_0c03a0e8;
case 0x0c03a0f0u: goto P_0c03a0f0;
case 0x0c03a0f2u: goto P_0c03a0f2;
case 0x0c03a0f4u: goto P_0c03a0f4;
case 0x0c03a0f6u: goto P_0c03a0f6;
case 0x0c03a0f8u: goto P_0c03a0f8;
case 0x0c03a0fau: goto P_0c03a0fa;
case 0x0c03a100u: goto P_0c03a100;
case 0x0c03a102u: goto P_0c03a102;
case 0x0c03a104u: goto P_0c03a104;
case 0x0c03a106u: goto P_0c03a106;
case 0x0c03a108u: goto P_0c03a108;
case 0x0c03a10au: goto P_0c03a10a;
case 0x0c03a10cu: goto P_0c03a10c;
case 0x0c03a10eu: goto P_0c03a10e;
case 0x0c03a110u: goto P_0c03a110;
case 0x0c03a112u: goto P_0c03a112;
case 0x0c0406b2u: goto P_0c0406b2;
case 0x0c0406b4u: goto P_0c0406b4;
case 0x0c0406b6u: goto P_0c0406b6;
case 0x0c0406b8u: goto P_0c0406b8;
case 0x0c0406bau: goto P_0c0406ba;
case 0x0c0406bcu: goto P_0c0406bc;
case 0x0c0406beu: goto P_0c0406be;
case 0x0c0406c0u: goto P_0c0406c0;
case 0x0c0406c2u: goto P_0c0406c2;
case 0x0c0406c4u: goto P_0c0406c4;
case 0x0c0406c6u: goto P_0c0406c6;
case 0x0c0406c8u: goto P_0c0406c8;
case 0x0c0406cau: goto P_0c0406ca;
case 0x0c0406ccu: goto P_0c0406cc;
case 0x0c0406ceu: goto P_0c0406ce;
case 0x0c0406d0u: goto P_0c0406d0;
case 0x0c0406d2u: goto P_0c0406d2;
case 0x0c0406d4u: goto P_0c0406d4;
case 0x0c0406d6u: goto P_0c0406d6;
case 0x0c0406d8u: goto P_0c0406d8;
case 0x0c0406dau: goto P_0c0406da;
case 0x0c0406dcu: goto P_0c0406dc;
case 0x0c0406deu: goto P_0c0406de;
case 0x0c0406e0u: goto P_0c0406e0;
case 0x0c0406e2u: goto P_0c0406e2;
case 0x0c0406e4u: goto P_0c0406e4;
case 0x0c0406e6u: goto P_0c0406e6;
case 0x0c0406e8u: goto P_0c0406e8;
case 0x0c0406eau: goto P_0c0406ea;
case 0x0c0406ecu: goto P_0c0406ec;
case 0x0c0406eeu: goto P_0c0406ee;
case 0x0c0406f0u: goto P_0c0406f0;
case 0x0c0406f2u: goto P_0c0406f2;
case 0x0c0406f4u: goto P_0c0406f4;
case 0x0c0406f6u: goto P_0c0406f6;
case 0x0c0406f8u: goto P_0c0406f8;
case 0x0c0406fau: goto P_0c0406fa;
case 0x0c0406fcu: goto P_0c0406fc;
case 0x0c0406feu: goto P_0c0406fe;
case 0x0c040700u: goto P_0c040700;
case 0x0c040702u: goto P_0c040702;
case 0x0c040704u: goto P_0c040704;
case 0x0c040706u: goto P_0c040706;
case 0x0c040708u: goto P_0c040708;
case 0x0c04070au: goto P_0c04070a;
case 0x0c040714u: goto P_0c040714;
case 0x0c040716u: goto P_0c040716;
case 0x0c040718u: goto P_0c040718;
case 0x0c04071au: goto P_0c04071a;
case 0x0c04071cu: goto P_0c04071c;
case 0x0c04071eu: goto P_0c04071e;
case 0x0c040720u: goto P_0c040720;
case 0x0c040722u: goto P_0c040722;
case 0x0c040724u: goto P_0c040724;
case 0x0c040726u: goto P_0c040726;
case 0x0c040728u: goto P_0c040728;
case 0x0c04072au: goto P_0c04072a;
case 0x0c04072cu: goto P_0c04072c;
case 0x0c04072eu: goto P_0c04072e;
case 0x0c040730u: goto P_0c040730;
case 0x0c040732u: goto P_0c040732;
case 0x0c040734u: goto P_0c040734;
case 0x0c040736u: goto P_0c040736;
case 0x0c040738u: goto P_0c040738;
case 0x0c04073au: goto P_0c04073a;
case 0x0c04073cu: goto P_0c04073c;
case 0x0c04073eu: goto P_0c04073e;
case 0x0c040740u: goto P_0c040740;
case 0x0c040742u: goto P_0c040742;
case 0x0c040744u: goto P_0c040744;
case 0x0c040746u: goto P_0c040746;
case 0x0c040748u: goto P_0c040748;
case 0x0c04074au: goto P_0c04074a;
case 0x0c04074cu: goto P_0c04074c;
case 0x0c04074eu: goto P_0c04074e;
case 0x0c040750u: goto P_0c040750;
case 0x0c040752u: goto P_0c040752;
case 0x0c040754u: goto P_0c040754;
case 0x0c040756u: goto P_0c040756;
case 0x0c040758u: goto P_0c040758;
case 0x0c04075au: goto P_0c04075a;
case 0x0c04075cu: goto P_0c04075c;
case 0x0c04075eu: goto P_0c04075e;
case 0x0c040760u: goto P_0c040760;
case 0x0c040762u: goto P_0c040762;
case 0x0c040764u: goto P_0c040764;
case 0x0c040766u: goto P_0c040766;
case 0x0c040768u: goto P_0c040768;
case 0x0c04076au: goto P_0c04076a;
case 0x0c04076cu: goto P_0c04076c;
case 0x0c04076eu: goto P_0c04076e;
case 0x0c040770u: goto P_0c040770;
case 0x0c040772u: goto P_0c040772;
case 0x0c040774u: goto P_0c040774;
case 0x0c040776u: goto P_0c040776;
case 0x0c040778u: goto P_0c040778;
case 0x0c04077au: goto P_0c04077a;
case 0x0c04077cu: goto P_0c04077c;
case 0x0c04077eu: goto P_0c04077e;
case 0x0c040780u: goto P_0c040780;
case 0x0c040782u: goto P_0c040782;
case 0x0c040784u: goto P_0c040784;
case 0x0c040786u: goto P_0c040786;
case 0x0c040788u: goto P_0c040788;
case 0x0c04078au: goto P_0c04078a;
case 0x0c04078cu: goto P_0c04078c;
case 0x0c04078eu: goto P_0c04078e;
case 0x0c040790u: goto P_0c040790;
case 0x0c040792u: goto P_0c040792;
case 0x0c040794u: goto P_0c040794;
case 0x0c040796u: goto P_0c040796;
case 0x0c040798u: goto P_0c040798;
case 0x0c04079au: goto P_0c04079a;
case 0x0c04079cu: goto P_0c04079c;
case 0x0c04079eu: goto P_0c04079e;
case 0x0c0407b0u: goto P_0c0407b0;
case 0x0c0407b2u: goto P_0c0407b2;
case 0x0c0407b4u: goto P_0c0407b4;
case 0x0c0407b6u: goto P_0c0407b6;
case 0x0c0407b8u: goto P_0c0407b8;
case 0x0c0407bau: goto P_0c0407ba;
case 0x0c0407bcu: goto P_0c0407bc;
case 0x0c0407beu: goto P_0c0407be;
case 0x0c0407c0u: goto P_0c0407c0;
case 0x0c0407c2u: goto P_0c0407c2;
case 0x0c0407c4u: goto P_0c0407c4;
case 0x0c0407c6u: goto P_0c0407c6;
case 0x0c0407c8u: goto P_0c0407c8;
case 0x0c04ceceu: goto P_0c04cece;
case 0x0c04ced0u: goto P_0c04ced0;
case 0x0c04ced2u: goto P_0c04ced2;
case 0x0c04ced4u: goto P_0c04ced4;
case 0x0c04ced6u: goto P_0c04ced6;
case 0x0c04ced8u: goto P_0c04ced8;
case 0x0c04cedau: goto P_0c04ceda;
case 0x0c04cedcu: goto P_0c04cedc;
case 0x0c04cedeu: goto P_0c04cede;
case 0x0c04cee0u: goto P_0c04cee0;
case 0x0c04cee2u: goto P_0c04cee2;
case 0x0c04cee4u: goto P_0c04cee4;
case 0x0c04cee6u: goto P_0c04cee6;
case 0x0c04cee8u: goto P_0c04cee8;
case 0x0c04ceeau: goto P_0c04ceea;
case 0x0c04ceecu: goto P_0c04ceec;
case 0x0c04ceeeu: goto P_0c04ceee;
case 0x0c04cef0u: goto P_0c04cef0;
case 0x0c04cef2u: goto P_0c04cef2;
case 0x0c04cef4u: goto P_0c04cef4;
case 0x0c04cef6u: goto P_0c04cef6;
case 0x0c04cef8u: goto P_0c04cef8;
case 0x0c04cefau: goto P_0c04cefa;
case 0x0c04cefcu: goto P_0c04cefc;
case 0x0c04cefeu: goto P_0c04cefe;
case 0x0c04cf00u: goto P_0c04cf00;
case 0x0c04cf02u: goto P_0c04cf02;
case 0x0c04cf04u: goto P_0c04cf04;
case 0x0c04cf06u: goto P_0c04cf06;
case 0x0c04cf08u: goto P_0c04cf08;
case 0x0c04cf0au: goto P_0c04cf0a;
case 0x0c04cf0cu: goto P_0c04cf0c;
case 0x0c04ec8eu: goto P_0c04ec8e;
case 0x0c04ec90u: goto P_0c04ec90;
case 0x0c04ec92u: goto P_0c04ec92;
case 0x0c04ec94u: goto P_0c04ec94;
case 0x0c04ec96u: goto P_0c04ec96;
case 0x0c04ec98u: goto P_0c04ec98;
case 0x0c04ec9au: goto P_0c04ec9a;
case 0x0c04ec9cu: goto P_0c04ec9c;
case 0x0c04ec9eu: goto P_0c04ec9e;
case 0x0c04eca0u: goto P_0c04eca0;
case 0x0c04eca2u: goto P_0c04eca2;
case 0x0c04eca4u: goto P_0c04eca4;
case 0x0c04eca6u: goto P_0c04eca6;
case 0x0c04eca8u: goto P_0c04eca8;
case 0x0c04ecaau: goto P_0c04ecaa;
case 0x0c04ecacu: goto P_0c04ecac;
case 0x0c04ecaeu: goto P_0c04ecae;
case 0x0c04ecb0u: goto P_0c04ecb0;
case 0x0c04ecb2u: goto P_0c04ecb2;
case 0x0c04ecb4u: goto P_0c04ecb4;
case 0x0c04ecb6u: goto P_0c04ecb6;
case 0x0c04ecb8u: goto P_0c04ecb8;
case 0x0c04ecbau: goto P_0c04ecba;
case 0x0c04ecf0u: goto P_0c04ecf0;
case 0x0c04ecf2u: goto P_0c04ecf2;
case 0x0c04ecf4u: goto P_0c04ecf4;
case 0x0c04ecf6u: goto P_0c04ecf6;
case 0x0c04ecf8u: goto P_0c04ecf8;
case 0x0c04ecfau: goto P_0c04ecfa;
case 0x0c04ecfcu: goto P_0c04ecfc;
case 0x0c04ecfeu: goto P_0c04ecfe;
case 0x0c04ed00u: goto P_0c04ed00;
case 0x0c04ed02u: goto P_0c04ed02;
case 0x0c04ed04u: goto P_0c04ed04;
case 0x0c04ed06u: goto P_0c04ed06;
case 0x0c04ed08u: goto P_0c04ed08;
case 0x0c04ed0au: goto P_0c04ed0a;
case 0x0c04ed0cu: goto P_0c04ed0c;
case 0x0c04ed0eu: goto P_0c04ed0e;
case 0x0c04ed10u: goto P_0c04ed10;
case 0x0c04ed12u: goto P_0c04ed12;
case 0x0c04ed14u: goto P_0c04ed14;
case 0x0c04ed16u: goto P_0c04ed16;
case 0x0c04ed18u: goto P_0c04ed18;
case 0x0c04ed1au: goto P_0c04ed1a;
case 0x0c04ed1cu: goto P_0c04ed1c;
case 0x0c04ed1eu: goto P_0c04ed1e;
case 0x0c04ed20u: goto P_0c04ed20;
case 0x0c04ed22u: goto P_0c04ed22;
case 0x0c04ed24u: goto P_0c04ed24;
case 0x0c04ed26u: goto P_0c04ed26;
case 0x0c04ed28u: goto P_0c04ed28;
case 0x0c04ed2au: goto P_0c04ed2a;
case 0x0c04ed2cu: goto P_0c04ed2c;
case 0x0c04ed2eu: goto P_0c04ed2e;
case 0x0c04ed30u: goto P_0c04ed30;
case 0x0c04ed32u: goto P_0c04ed32;
case 0x0c04ed34u: goto P_0c04ed34;
case 0x0c04ed36u: goto P_0c04ed36;
case 0x0c04ed38u: goto P_0c04ed38;
case 0x0c04ed3au: goto P_0c04ed3a;
case 0x0c04ed3cu: goto P_0c04ed3c;
case 0x0c04ed3eu: goto P_0c04ed3e;
case 0x0c04ed40u: goto P_0c04ed40;
case 0x0c04ed42u: goto P_0c04ed42;
case 0x0c04ed44u: goto P_0c04ed44;
case 0x0c04ed46u: goto P_0c04ed46;
case 0x0c04ed48u: goto P_0c04ed48;
case 0x0c04ed4au: goto P_0c04ed4a;
case 0x0c04ed4cu: goto P_0c04ed4c;
case 0x0c04ed4eu: goto P_0c04ed4e;
case 0x0c04ed50u: goto P_0c04ed50;
case 0x0c04ed52u: goto P_0c04ed52;
case 0x0c04ed54u: goto P_0c04ed54;
case 0x0c04ed56u: goto P_0c04ed56;
case 0x0c04ed58u: goto P_0c04ed58;
case 0x0c04ed5au: goto P_0c04ed5a;
case 0x0c04ed5cu: goto P_0c04ed5c;
case 0x0c04ed5eu: goto P_0c04ed5e;
case 0x0c04ed60u: goto P_0c04ed60;
case 0x0c04ed62u: goto P_0c04ed62;
case 0x0c04ed64u: goto P_0c04ed64;
case 0x0c04ed66u: goto P_0c04ed66;
case 0x0c04ed68u: goto P_0c04ed68;
case 0x0c04ed6au: goto P_0c04ed6a;
case 0x0c04ed6cu: goto P_0c04ed6c;
case 0x0c04ed6eu: goto P_0c04ed6e;
case 0x0c04ed70u: goto P_0c04ed70;
case 0x0c04ed72u: goto P_0c04ed72;
case 0x0c04ed74u: goto P_0c04ed74;
case 0x0c04ed76u: goto P_0c04ed76;
case 0x0c04ed78u: goto P_0c04ed78;
case 0x0c04ed7au: goto P_0c04ed7a;
case 0x0c04ed7cu: goto P_0c04ed7c;
case 0x0c04ed7eu: goto P_0c04ed7e;
case 0x0c04f98eu: goto P_0c04f98e;
case 0x0c04f990u: goto P_0c04f990;
case 0x0c04f992u: goto P_0c04f992;
case 0x0c04f994u: goto P_0c04f994;
case 0x0c04f996u: goto P_0c04f996;
case 0x0c04f998u: goto P_0c04f998;
case 0x0c04f99au: goto P_0c04f99a;
case 0x0c04f99cu: goto P_0c04f99c;
case 0x0c04f99eu: goto P_0c04f99e;
case 0x0c04f9a0u: goto P_0c04f9a0;
case 0x0c04f9a2u: goto P_0c04f9a2;
case 0x0c04f9a4u: goto P_0c04f9a4;
case 0x0c04f9a6u: goto P_0c04f9a6;
case 0x0c04f9a8u: goto P_0c04f9a8;
case 0x0c04f9aau: goto P_0c04f9aa;
case 0x0c04f9acu: goto P_0c04f9ac;
case 0x0c04f9aeu: goto P_0c04f9ae;
case 0x0c04f9b0u: goto P_0c04f9b0;
case 0x0c04f9b2u: goto P_0c04f9b2;
case 0x0c04f9b4u: goto P_0c04f9b4;
case 0x0c04f9b6u: goto P_0c04f9b6;
case 0x0c04f9b8u: goto P_0c04f9b8;
case 0x0c04f9bau: goto P_0c04f9ba;
case 0x0c04f9bcu: goto P_0c04f9bc;
case 0x0c04f9beu: goto P_0c04f9be;
case 0x0c04f9c0u: goto P_0c04f9c0;
case 0x0c04f9c2u: goto P_0c04f9c2;
case 0x0c04f9c4u: goto P_0c04f9c4;
case 0x0c04f9c6u: goto P_0c04f9c6;
case 0x0c04f9c8u: goto P_0c04f9c8;
case 0x0c04f9cau: goto P_0c04f9ca;
case 0x0c04f9ccu: goto P_0c04f9cc;
case 0x0c04f9ceu: goto P_0c04f9ce;
case 0x0c04f9d0u: goto P_0c04f9d0;
case 0x0c04f9d2u: goto P_0c04f9d2;
case 0x0c04f9d4u: goto P_0c04f9d4;
case 0x0c04f9d6u: goto P_0c04f9d6;
case 0x0c04f9f0u: goto P_0c04f9f0;
case 0x0c04f9f2u: goto P_0c04f9f2;
case 0x0c04f9f4u: goto P_0c04f9f4;
case 0x0c04f9f6u: goto P_0c04f9f6;
case 0x0c04f9f8u: goto P_0c04f9f8;
case 0x0c04f9fau: goto P_0c04f9fa;
case 0x0c04f9fcu: goto P_0c04f9fc;
case 0x0c04f9feu: goto P_0c04f9fe;
case 0x0c04fa00u: goto P_0c04fa00;
case 0x0c04fa02u: goto P_0c04fa02;
case 0x0c04fa04u: goto P_0c04fa04;
case 0x0c04fa06u: goto P_0c04fa06;
case 0x0c04fa08u: goto P_0c04fa08;
case 0x0c04fa0au: goto P_0c04fa0a;
case 0x0c04fa0cu: goto P_0c04fa0c;
case 0x0c04fa0eu: goto P_0c04fa0e;
case 0x0c04fa10u: goto P_0c04fa10;
case 0x0c04fa12u: goto P_0c04fa12;
case 0x0c04fa14u: goto P_0c04fa14;
case 0x0c04fa16u: goto P_0c04fa16;
case 0x0c04fa18u: goto P_0c04fa18;
case 0x0c04fa1au: goto P_0c04fa1a;
case 0x0c04fa1cu: goto P_0c04fa1c;
case 0x0c04fa1eu: goto P_0c04fa1e;
case 0x0c04fa20u: goto P_0c04fa20;
case 0x0c04fa22u: goto P_0c04fa22;
case 0x0c04fa24u: goto P_0c04fa24;
case 0x0c04fa26u: goto P_0c04fa26;
case 0x0c04fa28u: goto P_0c04fa28;
case 0x0c04fa2au: goto P_0c04fa2a;
case 0x0c04fa2cu: goto P_0c04fa2c;
case 0x0c04fa2eu: goto P_0c04fa2e;
case 0x0c04fa30u: goto P_0c04fa30;
case 0x0c04fa32u: goto P_0c04fa32;
case 0x0c04fa34u: goto P_0c04fa34;
case 0x0c04fa36u: goto P_0c04fa36;
case 0x0c053ca4u: goto P_0c053ca4;
case 0x0c053ca6u: goto P_0c053ca6;
case 0x0c053ca8u: goto P_0c053ca8;
case 0x0c053caau: goto P_0c053caa;
case 0x0c053cacu: goto P_0c053cac;
case 0x0c053caeu: goto P_0c053cae;
case 0x0c053cb0u: goto P_0c053cb0;
case 0x0c053cb2u: goto P_0c053cb2;
case 0x0c053cb4u: goto P_0c053cb4;
case 0x0c053cb6u: goto P_0c053cb6;
case 0x0c053cb8u: goto P_0c053cb8;
case 0x0c053cbau: goto P_0c053cba;
case 0x0c053cbcu: goto P_0c053cbc;
case 0x0c053cbeu: goto P_0c053cbe;
case 0x0c053cc0u: goto P_0c053cc0;
case 0x0c053cc2u: goto P_0c053cc2;
case 0x0c053cc4u: goto P_0c053cc4;
case 0x0c053cc6u: goto P_0c053cc6;
case 0x0c053cc8u: goto P_0c053cc8;
case 0x0c053ccau: goto P_0c053cca;
case 0x0c053cccu: goto P_0c053ccc;
case 0x0c053cceu: goto P_0c053cce;
case 0x0c053cd0u: goto P_0c053cd0;
case 0x0c053cd2u: goto P_0c053cd2;
case 0x0c053cd4u: goto P_0c053cd4;
case 0x0c053cd6u: goto P_0c053cd6;
case 0x0c053cd8u: goto P_0c053cd8;
case 0x0c053cdau: goto P_0c053cda;
case 0x0c053cdcu: goto P_0c053cdc;
case 0x0c053cdeu: goto P_0c053cde;
case 0x0c053ce0u: goto P_0c053ce0;
case 0x0c053ce2u: goto P_0c053ce2;
case 0x0c05961eu: goto P_0c05961e;
case 0x0c059620u: goto P_0c059620;
case 0x0c059622u: goto P_0c059622;
case 0x0c059624u: goto P_0c059624;
case 0x0c059626u: goto P_0c059626;
case 0x0c059628u: goto P_0c059628;
case 0x0c05962au: goto P_0c05962a;
case 0x0c05962cu: goto P_0c05962c;
case 0x0c05962eu: goto P_0c05962e;
case 0x0c059630u: goto P_0c059630;
case 0x0c059632u: goto P_0c059632;
case 0x0c059634u: goto P_0c059634;
case 0x0c059636u: goto P_0c059636;
case 0x0c059638u: goto P_0c059638;
case 0x0c05963au: goto P_0c05963a;
case 0x0c05963cu: goto P_0c05963c;
case 0x0c05963eu: goto P_0c05963e;
case 0x0c059640u: goto P_0c059640;
case 0x0c059642u: goto P_0c059642;
case 0x0c059644u: goto P_0c059644;
case 0x0c059646u: goto P_0c059646;
case 0x0c059648u: goto P_0c059648;
case 0x0c05964au: goto P_0c05964a;
case 0x0c05964cu: goto P_0c05964c;
case 0x0c05964eu: goto P_0c05964e;
case 0x0c059650u: goto P_0c059650;
case 0x0c059652u: goto P_0c059652;
case 0x0c059654u: goto P_0c059654;
case 0x0c059656u: goto P_0c059656;
case 0x0c059658u: goto P_0c059658;
case 0x0c05965au: goto P_0c05965a;
case 0x0c05965cu: goto P_0c05965c;
case 0x0c05965eu: goto P_0c05965e;
case 0x0c059660u: goto P_0c059660;
case 0x0c059662u: goto P_0c059662;
case 0x0c059664u: goto P_0c059664;
case 0x0c059666u: goto P_0c059666;
case 0x0c059668u: goto P_0c059668;
case 0x0c05966au: goto P_0c05966a;
case 0x0c05966cu: goto P_0c05966c;
case 0x0c05966eu: goto P_0c05966e;
case 0x0c059670u: goto P_0c059670;
case 0x0c059672u: goto P_0c059672;
case 0x0c059674u: goto P_0c059674;
case 0x0c059676u: goto P_0c059676;
case 0x0c059678u: goto P_0c059678;
case 0x0c05967au: goto P_0c05967a;
case 0x0c05967cu: goto P_0c05967c;
case 0x0c05967eu: goto P_0c05967e;
case 0x0c059680u: goto P_0c059680;
case 0x0c059682u: goto P_0c059682;
case 0x0c059684u: goto P_0c059684;
case 0x0c0596b4u: goto P_0c0596b4;
case 0x0c0596b6u: goto P_0c0596b6;
case 0x0c0596b8u: goto P_0c0596b8;
case 0x0c0596bau: goto P_0c0596ba;
case 0x0c0596bcu: goto P_0c0596bc;
case 0x0c0596beu: goto P_0c0596be;
case 0x0c0596c0u: goto P_0c0596c0;
case 0x0c0596c2u: goto P_0c0596c2;
case 0x0c0596c4u: goto P_0c0596c4;
case 0x0c0596c6u: goto P_0c0596c6;
case 0x0c0596c8u: goto P_0c0596c8;
case 0x0c0596cau: goto P_0c0596ca;
case 0x0c0596ccu: goto P_0c0596cc;
case 0x0c0596ceu: goto P_0c0596ce;
case 0x0c0596d0u: goto P_0c0596d0;
case 0x0c0596d2u: goto P_0c0596d2;
case 0x0c0596d4u: goto P_0c0596d4;
case 0x0c0596d6u: goto P_0c0596d6;
case 0x0c0596d8u: goto P_0c0596d8;
case 0x0c0596dau: goto P_0c0596da;
case 0x0c0596dcu: goto P_0c0596dc;
case 0x0c0596deu: goto P_0c0596de;
case 0x0c0596e0u: goto P_0c0596e0;
case 0x0c0596e2u: goto P_0c0596e2;
case 0x0c0596e4u: goto P_0c0596e4;
case 0x0c0596e6u: goto P_0c0596e6;
case 0x0c0596e8u: goto P_0c0596e8;
case 0x0c0596eau: goto P_0c0596ea;
case 0x0c0596ecu: goto P_0c0596ec;
case 0x0c0596eeu: goto P_0c0596ee;
case 0x0c0596f0u: goto P_0c0596f0;
case 0x0c0596f2u: goto P_0c0596f2;
case 0x0c0596f4u: goto P_0c0596f4;
case 0x0c0596f6u: goto P_0c0596f6;
case 0x0c0596f8u: goto P_0c0596f8;
case 0x0c0596fau: goto P_0c0596fa;
case 0x0c0596fcu: goto P_0c0596fc;
case 0x0c0596feu: goto P_0c0596fe;
case 0x0c059700u: goto P_0c059700;
case 0x0c059702u: goto P_0c059702;
case 0x0c059704u: goto P_0c059704;
case 0x0c059706u: goto P_0c059706;
case 0x0c05e86au: goto P_0c05e86a;
case 0x0c05e86cu: goto P_0c05e86c;
case 0x0c05e86eu: goto P_0c05e86e;
case 0x0c05e870u: goto P_0c05e870;
case 0x0c05e872u: goto P_0c05e872;
case 0x0c05e874u: goto P_0c05e874;
case 0x0c05e876u: goto P_0c05e876;
case 0x0c05e878u: goto P_0c05e878;
case 0x0c05e87au: goto P_0c05e87a;
case 0x0c05e87cu: goto P_0c05e87c;
case 0x0c05e87eu: goto P_0c05e87e;
case 0x0c05e880u: goto P_0c05e880;
case 0x0c05e882u: goto P_0c05e882;
case 0x0c05e884u: goto P_0c05e884;
case 0x0c05e886u: goto P_0c05e886;
case 0x0c05e888u: goto P_0c05e888;
case 0x0c05e88au: goto P_0c05e88a;
case 0x0c05e88cu: goto P_0c05e88c;
case 0x0c05e88eu: goto P_0c05e88e;
case 0x0c05e890u: goto P_0c05e890;
case 0x0c05e892u: goto P_0c05e892;
case 0x0c05e894u: goto P_0c05e894;
case 0x0c05e896u: goto P_0c05e896;
case 0x0c05e898u: goto P_0c05e898;
case 0x0c05e89au: goto P_0c05e89a;
case 0x0c05e89cu: goto P_0c05e89c;
case 0x0c05e89eu: goto P_0c05e89e;
case 0x0c05e8a0u: goto P_0c05e8a0;
case 0x0c05e8a2u: goto P_0c05e8a2;
case 0x0c05e8a4u: goto P_0c05e8a4;
case 0x0c05e8a6u: goto P_0c05e8a6;
case 0x0c05e8a8u: goto P_0c05e8a8;
case 0x0c05e8aau: goto P_0c05e8aa;
case 0x0c05e8acu: goto P_0c05e8ac;
case 0x0c05e8aeu: goto P_0c05e8ae;
case 0x0c05e8b0u: goto P_0c05e8b0;
case 0x0c05e8b2u: goto P_0c05e8b2;
case 0x0c05e8b4u: goto P_0c05e8b4;
case 0x0c05e8b6u: goto P_0c05e8b6;
case 0x0c05e8b8u: goto P_0c05e8b8;
case 0x0c05e8bau: goto P_0c05e8ba;
case 0x0c05e8bcu: goto P_0c05e8bc;
case 0x0c05e8beu: goto P_0c05e8be;
case 0x0c05e8c0u: goto P_0c05e8c0;
case 0x0c05e8c2u: goto P_0c05e8c2;
case 0x0c05e8c4u: goto P_0c05e8c4;
case 0x0c05e8c6u: goto P_0c05e8c6;
case 0x0c05e8c8u: goto P_0c05e8c8;
case 0x0c05e8cau: goto P_0c05e8ca;
case 0x0c05e8ccu: goto P_0c05e8cc;
case 0x0c05e8ceu: goto P_0c05e8ce;
case 0x0c05e8d0u: goto P_0c05e8d0;
case 0x0c05e8d2u: goto P_0c05e8d2;
case 0x0c05e8d4u: goto P_0c05e8d4;
case 0x0c05e8d6u: goto P_0c05e8d6;
case 0x0c05e8d8u: goto P_0c05e8d8;
case 0x0c05e8dau: goto P_0c05e8da;
case 0x0c05e8dcu: goto P_0c05e8dc;
case 0x0c05e8deu: goto P_0c05e8de;
case 0x0c05e8e0u: goto P_0c05e8e0;
case 0x0c05e8e2u: goto P_0c05e8e2;
case 0x0c05e8e4u: goto P_0c05e8e4;
case 0x0c05e8e6u: goto P_0c05e8e6;
case 0x0c05e8e8u: goto P_0c05e8e8;
case 0x0c05e8eau: goto P_0c05e8ea;
case 0x0c05e8ecu: goto P_0c05e8ec;
case 0x0c05e8eeu: goto P_0c05e8ee;
case 0x0c05e8f0u: goto P_0c05e8f0;
case 0x0c05e8f2u: goto P_0c05e8f2;
case 0x0c05e8f4u: goto P_0c05e8f4;
case 0x0c05e8f6u: goto P_0c05e8f6;
case 0x0c05e8f8u: goto P_0c05e8f8;
case 0x0c05e8fau: goto P_0c05e8fa;
case 0x0c05e8fcu: goto P_0c05e8fc;
case 0x0c05e8feu: goto P_0c05e8fe;
case 0x0c05e900u: goto P_0c05e900;
case 0x0c05e902u: goto P_0c05e902;
case 0x0c05e904u: goto P_0c05e904;
case 0x0c05e906u: goto P_0c05e906;
case 0x0c05e908u: goto P_0c05e908;
case 0x0c05e90au: goto P_0c05e90a;
case 0x0c05e90cu: goto P_0c05e90c;
case 0x0c05e90eu: goto P_0c05e90e;
case 0x0c05e910u: goto P_0c05e910;
case 0x0c05e912u: goto P_0c05e912;
case 0x0c05e914u: goto P_0c05e914;
case 0x0c05e916u: goto P_0c05e916;
case 0x0c05e918u: goto P_0c05e918;
case 0x0c05e91au: goto P_0c05e91a;
case 0x0c05e91cu: goto P_0c05e91c;
case 0x0c05e91eu: goto P_0c05e91e;
case 0x0c05e920u: goto P_0c05e920;
case 0x0c05e922u: goto P_0c05e922;
case 0x0c05e924u: goto P_0c05e924;
case 0x0c05e926u: goto P_0c05e926;
case 0x0c05e928u: goto P_0c05e928;
case 0x0c05e92au: goto P_0c05e92a;
case 0x0c05e92cu: goto P_0c05e92c;
case 0x0c05e92eu: goto P_0c05e92e;
case 0x0c05e930u: goto P_0c05e930;
case 0x0c05e932u: goto P_0c05e932;
case 0x0c05e934u: goto P_0c05e934;
case 0x0c05e936u: goto P_0c05e936;
case 0x0c05e938u: goto P_0c05e938;
case 0x0c05e93au: goto P_0c05e93a;
case 0x0c05e93cu: goto P_0c05e93c;
case 0x0c05e93eu: goto P_0c05e93e;
case 0x0c05e940u: goto P_0c05e940;
case 0x0c05e942u: goto P_0c05e942;
case 0x0c05e944u: goto P_0c05e944;
case 0x0c05e946u: goto P_0c05e946;
case 0x0c05e948u: goto P_0c05e948;
case 0x0c05e94au: goto P_0c05e94a;
case 0x0c05e94cu: goto P_0c05e94c;
case 0x0c05ee64u: goto P_0c05ee64;
case 0x0c05ee66u: goto P_0c05ee66;
case 0x0c05ee68u: goto P_0c05ee68;
case 0x0c05ee6au: goto P_0c05ee6a;
case 0x0c05ee6cu: goto P_0c05ee6c;
case 0x0c05ee6eu: goto P_0c05ee6e;
case 0x0c05ee70u: goto P_0c05ee70;
case 0x0c05ee72u: goto P_0c05ee72;
case 0x0c05ee74u: goto P_0c05ee74;
case 0x0c05ee76u: goto P_0c05ee76;
case 0x0c05ee78u: goto P_0c05ee78;
case 0x0c05ee7au: goto P_0c05ee7a;
case 0x0c05ee7cu: goto P_0c05ee7c;
case 0x0c05ee7eu: goto P_0c05ee7e;
case 0x0c05ee80u: goto P_0c05ee80;
case 0x0c05ee82u: goto P_0c05ee82;
case 0x0c05ee84u: goto P_0c05ee84;
case 0x0c05ee86u: goto P_0c05ee86;
case 0x0c05ee88u: goto P_0c05ee88;
case 0x0c05ee8au: goto P_0c05ee8a;
case 0x0c05ee8cu: goto P_0c05ee8c;
case 0x0c05ee8eu: goto P_0c05ee8e;
case 0x0c05ee90u: goto P_0c05ee90;
case 0x0c05ee92u: goto P_0c05ee92;
case 0x0c05ee94u: goto P_0c05ee94;
case 0x0c05ee96u: goto P_0c05ee96;
case 0x0c05ee98u: goto P_0c05ee98;
case 0x0c05ee9au: goto P_0c05ee9a;
case 0x0c05ee9cu: goto P_0c05ee9c;
case 0x0c05ee9eu: goto P_0c05ee9e;
case 0x0c05eea0u: goto P_0c05eea0;
case 0x0c05eea2u: goto P_0c05eea2;
case 0x0c05eea4u: goto P_0c05eea4;
case 0x0c05eea6u: goto P_0c05eea6;
case 0x0c05eea8u: goto P_0c05eea8;
case 0x0c05eeaau: goto P_0c05eeaa;
case 0x0c05eeacu: goto P_0c05eeac;
case 0x0c05eeaeu: goto P_0c05eeae;
case 0x0c05eeb0u: goto P_0c05eeb0;
case 0x0c05eeb2u: goto P_0c05eeb2;
case 0x0c05eeb4u: goto P_0c05eeb4;
case 0x0c05eeb6u: goto P_0c05eeb6;
case 0x0c05eeb8u: goto P_0c05eeb8;
case 0x0c05eebau: goto P_0c05eeba;
case 0x0c05eebcu: goto P_0c05eebc;
case 0x0c05eebeu: goto P_0c05eebe;
case 0x0c05eec0u: goto P_0c05eec0;
case 0x0c05eec2u: goto P_0c05eec2;
case 0x0c05eec4u: goto P_0c05eec4;
case 0x0c05eec6u: goto P_0c05eec6;
case 0x0c05eec8u: goto P_0c05eec8;
case 0x0c05eecau: goto P_0c05eeca;
case 0x0c05eeccu: goto P_0c05eecc;
case 0x0c05eeceu: goto P_0c05eece;
case 0x0c05eed0u: goto P_0c05eed0;
case 0x0c05eed2u: goto P_0c05eed2;
case 0x0c05eed4u: goto P_0c05eed4;
case 0x0c05eed6u: goto P_0c05eed6;
case 0x0c05eed8u: goto P_0c05eed8;
case 0x0c05eedau: goto P_0c05eeda;
case 0x0c05eedcu: goto P_0c05eedc;
case 0x0c05eedeu: goto P_0c05eede;
case 0x0c05eee0u: goto P_0c05eee0;
case 0x0c05eee2u: goto P_0c05eee2;
case 0x0c05eee4u: goto P_0c05eee4;
case 0x0c05eee6u: goto P_0c05eee6;
case 0x0c05eee8u: goto P_0c05eee8;
case 0x0c05eeeau: goto P_0c05eeea;
case 0x0c05eeecu: goto P_0c05eeec;
case 0x0c05eeeeu: goto P_0c05eeee;
case 0x0c05eef0u: goto P_0c05eef0;
case 0x0c05eef2u: goto P_0c05eef2;
case 0x0c05eef4u: goto P_0c05eef4;
case 0x0c05eef6u: goto P_0c05eef6;
case 0x0c05eef8u: goto P_0c05eef8;
case 0x0c05eefau: goto P_0c05eefa;
case 0x0c05eefcu: goto P_0c05eefc;
case 0x0c05eefeu: goto P_0c05eefe;
case 0x0c05ef00u: goto P_0c05ef00;
case 0x0c05ef02u: goto P_0c05ef02;
case 0x0c05ef04u: goto P_0c05ef04;
case 0x0c05ef06u: goto P_0c05ef06;
case 0x0c05ef08u: goto P_0c05ef08;
case 0x0c05ef0au: goto P_0c05ef0a;
case 0x0c05ef0cu: goto P_0c05ef0c;
case 0x0c05ef0eu: goto P_0c05ef0e;
case 0x0c05ef10u: goto P_0c05ef10;
case 0x0c05ef40u: goto P_0c05ef40;
case 0x0c05ef42u: goto P_0c05ef42;
case 0x0c05ef44u: goto P_0c05ef44;
case 0x0c05ef46u: goto P_0c05ef46;
case 0x0c05ef48u: goto P_0c05ef48;
case 0x0c05ef4au: goto P_0c05ef4a;
case 0x0c05ef4cu: goto P_0c05ef4c;
case 0x0c05ef4eu: goto P_0c05ef4e;
case 0x0c05ef50u: goto P_0c05ef50;
case 0x0c05ef52u: goto P_0c05ef52;
case 0x0c05ef54u: goto P_0c05ef54;
case 0x0c05ef56u: goto P_0c05ef56;
case 0x0c05ef58u: goto P_0c05ef58;
case 0x0c05ef5au: goto P_0c05ef5a;
case 0x0c05ef5cu: goto P_0c05ef5c;
case 0x0c05ef5eu: goto P_0c05ef5e;
case 0x0c05ef60u: goto P_0c05ef60;
case 0x0c05ef62u: goto P_0c05ef62;
case 0x0c05ef64u: goto P_0c05ef64;
case 0x0c05ef66u: goto P_0c05ef66;
case 0x0c05ef68u: goto P_0c05ef68;
case 0x0c05ef6au: goto P_0c05ef6a;
case 0x0c05ef6cu: goto P_0c05ef6c;
case 0x0c05ef6eu: goto P_0c05ef6e;
case 0x0c05ef70u: goto P_0c05ef70;
case 0x0c05ef72u: goto P_0c05ef72;
case 0x0c05ef74u: goto P_0c05ef74;
case 0x0c05ef76u: goto P_0c05ef76;
case 0x0c05ef78u: goto P_0c05ef78;
case 0x0c05ef7au: goto P_0c05ef7a;
case 0x0c05ef7cu: goto P_0c05ef7c;
case 0x0c05ef7eu: goto P_0c05ef7e;
case 0x0c05ef80u: goto P_0c05ef80;
case 0x0c05ef82u: goto P_0c05ef82;
case 0x0c05ef84u: goto P_0c05ef84;
case 0x0c05ef86u: goto P_0c05ef86;
case 0x0c05ef88u: goto P_0c05ef88;
case 0x0c05ef8au: goto P_0c05ef8a;
case 0x0c05ef8cu: goto P_0c05ef8c;
case 0x0c05ef8eu: goto P_0c05ef8e;
case 0x0c05ef90u: goto P_0c05ef90;
case 0x0c05ef92u: goto P_0c05ef92;
case 0x0c05ef94u: goto P_0c05ef94;
case 0x0c05ef96u: goto P_0c05ef96;
case 0x0c05ef98u: goto P_0c05ef98;
case 0x0c05ef9au: goto P_0c05ef9a;
case 0x0c05ef9cu: goto P_0c05ef9c;
case 0x0c05ef9eu: goto P_0c05ef9e;
case 0x0c05efa0u: goto P_0c05efa0;
case 0x0c05efa2u: goto P_0c05efa2;
case 0x0c05efa4u: goto P_0c05efa4;
case 0x0c05efa6u: goto P_0c05efa6;
case 0x0c05efa8u: goto P_0c05efa8;
case 0x0c05efaau: goto P_0c05efaa;
case 0x0c05efacu: goto P_0c05efac;
case 0x0c05efaeu: goto P_0c05efae;
case 0x0c05efb0u: goto P_0c05efb0;
case 0x0c05efb2u: goto P_0c05efb2;
case 0x0c05efb4u: goto P_0c05efb4;
case 0x0c05efb6u: goto P_0c05efb6;
case 0x0c05efb8u: goto P_0c05efb8;
case 0x0c05efbau: goto P_0c05efba;
case 0x0c05efbcu: goto P_0c05efbc;
case 0x0c05efbeu: goto P_0c05efbe;
case 0x0c05efc0u: goto P_0c05efc0;
case 0x0c05efc2u: goto P_0c05efc2;
case 0x0c05efc4u: goto P_0c05efc4;
case 0x0c05efc6u: goto P_0c05efc6;
case 0x0c05efc8u: goto P_0c05efc8;
case 0x0c05efcau: goto P_0c05efca;
case 0x0c05efccu: goto P_0c05efcc;
case 0x0c05efceu: goto P_0c05efce;
case 0x0c05efd0u: goto P_0c05efd0;
case 0x0c05efd2u: goto P_0c05efd2;
case 0x0c05efd4u: goto P_0c05efd4;
case 0x0c05efd6u: goto P_0c05efd6;
case 0x0c05efd8u: goto P_0c05efd8;
case 0x0c05efdau: goto P_0c05efda;
case 0x0c05efdcu: goto P_0c05efdc;
case 0x0c05efdeu: goto P_0c05efde;
case 0x0c05efe0u: goto P_0c05efe0;
case 0x0c05efe2u: goto P_0c05efe2;
case 0x0c05efe4u: goto P_0c05efe4;
case 0x0c05efe6u: goto P_0c05efe6;
case 0x0c05efe8u: goto P_0c05efe8;
case 0x0c05efeau: goto P_0c05efea;
case 0x0c05efecu: goto P_0c05efec;
case 0x0c05efeeu: goto P_0c05efee;
case 0x0c05eff0u: goto P_0c05eff0;
case 0x0c05eff2u: goto P_0c05eff2;
case 0x0c05eff4u: goto P_0c05eff4;
case 0x0c05eff6u: goto P_0c05eff6;
case 0x0c05eff8u: goto P_0c05eff8;
case 0x0c05effau: goto P_0c05effa;
case 0x0c05f018u: goto P_0c05f018;
case 0x0c05f01au: goto P_0c05f01a;
case 0x0c05f01cu: goto P_0c05f01c;
case 0x0c05f01eu: goto P_0c05f01e;
case 0x0c05f020u: goto P_0c05f020;
case 0x0c05f022u: goto P_0c05f022;
case 0x0c05f024u: goto P_0c05f024;
case 0x0c05f026u: goto P_0c05f026;
case 0x0c05f028u: goto P_0c05f028;
case 0x0c05f02au: goto P_0c05f02a;
case 0x0c05f02cu: goto P_0c05f02c;
case 0x0c05f02eu: goto P_0c05f02e;
case 0x0c05f030u: goto P_0c05f030;
case 0x0c05f032u: goto P_0c05f032;
case 0x0c05f034u: goto P_0c05f034;
case 0x0c05f036u: goto P_0c05f036;
case 0x0c05f038u: goto P_0c05f038;
case 0x0c05f03au: goto P_0c05f03a;
case 0x0c05f03cu: goto P_0c05f03c;
case 0x0c05f03eu: goto P_0c05f03e;
case 0x0c05f040u: goto P_0c05f040;
case 0x0c05f042u: goto P_0c05f042;
case 0x0c05f044u: goto P_0c05f044;
case 0x0c05f046u: goto P_0c05f046;
case 0x0c05f048u: goto P_0c05f048;
case 0x0c05f04au: goto P_0c05f04a;
case 0x0c05f04cu: goto P_0c05f04c;
case 0x0c05f04eu: goto P_0c05f04e;
case 0x0c05f050u: goto P_0c05f050;
case 0x0c05f052u: goto P_0c05f052;
case 0x0c05f054u: goto P_0c05f054;
case 0x0c05f056u: goto P_0c05f056;
case 0x0c05f058u: goto P_0c05f058;
case 0x0c05f05au: goto P_0c05f05a;
case 0x0c05f05cu: goto P_0c05f05c;
case 0x0c05f05eu: goto P_0c05f05e;
case 0x0c05f060u: goto P_0c05f060;
case 0x0c05f062u: goto P_0c05f062;
case 0x0c05f064u: goto P_0c05f064;
case 0x0c05f066u: goto P_0c05f066;
case 0x0c05f068u: goto P_0c05f068;
case 0x0c05f06au: goto P_0c05f06a;
case 0x0c05f06cu: goto P_0c05f06c;
case 0x0c05f06eu: goto P_0c05f06e;
case 0x0c05f070u: goto P_0c05f070;
case 0x0c05f072u: goto P_0c05f072;
case 0x0c05f074u: goto P_0c05f074;
case 0x0c05f076u: goto P_0c05f076;
case 0x0c05f078u: goto P_0c05f078;
case 0x0c05f07au: goto P_0c05f07a;
case 0x0c05f07cu: goto P_0c05f07c;
case 0x0c05f07eu: goto P_0c05f07e;
case 0x0c05f080u: goto P_0c05f080;
case 0x0c05f082u: goto P_0c05f082;
case 0x0c05f084u: goto P_0c05f084;
case 0x0c05f086u: goto P_0c05f086;
case 0x0c05f088u: goto P_0c05f088;
case 0x0c05f08au: goto P_0c05f08a;
case 0x0c05f08cu: goto P_0c05f08c;
case 0x0c05f08eu: goto P_0c05f08e;
case 0x0c05f090u: goto P_0c05f090;
case 0x0c05f092u: goto P_0c05f092;
case 0x0c05f094u: goto P_0c05f094;
case 0x0c05f096u: goto P_0c05f096;
case 0x0c05f098u: goto P_0c05f098;
case 0x0c05f09au: goto P_0c05f09a;
case 0x0c05f09cu: goto P_0c05f09c;
case 0x0c060d46u: goto P_0c060d46;
case 0x0c060d48u: goto P_0c060d48;
case 0x0c060d4au: goto P_0c060d4a;
case 0x0c0644bcu: goto P_0c0644bc;
case 0x0c0644beu: goto P_0c0644be;
case 0x0c0644c0u: goto P_0c0644c0;
case 0x0c0644c2u: goto P_0c0644c2;
case 0x0c0644c4u: goto P_0c0644c4;
case 0x0c0644c6u: goto P_0c0644c6;
case 0x0c0644c8u: goto P_0c0644c8;
case 0x0c0644cau: goto P_0c0644ca;
case 0x0c0644ccu: goto P_0c0644cc;
case 0x0c0644ceu: goto P_0c0644ce;
case 0x0c0644d0u: goto P_0c0644d0;
case 0x0c0644d2u: goto P_0c0644d2;
case 0x0c0644d4u: goto P_0c0644d4;
case 0x0c06ac7au: goto P_0c06ac7a;
case 0x0c06ac7cu: goto P_0c06ac7c;
case 0x0c06ac7eu: goto P_0c06ac7e;
case 0x0c06ac80u: goto P_0c06ac80;
case 0x0c06ac82u: goto P_0c06ac82;
case 0x0c06ac84u: goto P_0c06ac84;
case 0x0c06ac86u: goto P_0c06ac86;
case 0x0c06ac88u: goto P_0c06ac88;
case 0x0c06ac8au: goto P_0c06ac8a;
case 0x0c06ac8cu: goto P_0c06ac8c;
case 0x0c06ac8eu: goto P_0c06ac8e;
case 0x0c06ac90u: goto P_0c06ac90;
case 0x0c06ac92u: goto P_0c06ac92;
case 0x0c06ac94u: goto P_0c06ac94;
case 0x0c06ac96u: goto P_0c06ac96;
case 0x0c06ac98u: goto P_0c06ac98;
case 0x0c06ac9au: goto P_0c06ac9a;
case 0x0c06ac9cu: goto P_0c06ac9c;
case 0x0c06ac9eu: goto P_0c06ac9e;
case 0x0c06aca0u: goto P_0c06aca0;
case 0x0c06aca2u: goto P_0c06aca2;
case 0x0c06aca4u: goto P_0c06aca4;
case 0x0c06aca6u: goto P_0c06aca6;
case 0x0c06aca8u: goto P_0c06aca8;
case 0x0c06acaau: goto P_0c06acaa;
case 0x0c06acacu: goto P_0c06acac;
case 0x0c06acaeu: goto P_0c06acae;
case 0x0c06acb0u: goto P_0c06acb0;
case 0x0c06acb2u: goto P_0c06acb2;
case 0x0c06acb4u: goto P_0c06acb4;
case 0x0c06acb6u: goto P_0c06acb6;
case 0x0c06acb8u: goto P_0c06acb8;
case 0x0c06acbau: goto P_0c06acba;
case 0x0c06acbcu: goto P_0c06acbc;
case 0x0c06acbeu: goto P_0c06acbe;
case 0x0c06acc0u: goto P_0c06acc0;
case 0x0c06acc2u: goto P_0c06acc2;
case 0x0c06acc4u: goto P_0c06acc4;
case 0x0c06acc6u: goto P_0c06acc6;
case 0x0c06acc8u: goto P_0c06acc8;
case 0x0c06accau: goto P_0c06acca;
case 0x0c06acccu: goto P_0c06accc;
case 0x0c06acceu: goto P_0c06acce;
case 0x0c06acd0u: goto P_0c06acd0;
case 0x0c06acd2u: goto P_0c06acd2;
case 0x0c06acd4u: goto P_0c06acd4;
case 0x0c06acd6u: goto P_0c06acd6;
case 0x0c06acd8u: goto P_0c06acd8;
case 0x0c06acdau: goto P_0c06acda;
case 0x0c06acdcu: goto P_0c06acdc;
case 0x0c06acdeu: goto P_0c06acde;
case 0x0c06ace0u: goto P_0c06ace0;
case 0x0c06ace2u: goto P_0c06ace2;
case 0x0c06ace4u: goto P_0c06ace4;
case 0x0c06ace6u: goto P_0c06ace6;
case 0x0c06ace8u: goto P_0c06ace8;
case 0x0c06aceau: goto P_0c06acea;
case 0x0c06acecu: goto P_0c06acec;
case 0x0c06aceeu: goto P_0c06acee;
case 0x0c06acf0u: goto P_0c06acf0;
case 0x0c06acf2u: goto P_0c06acf2;
case 0x0c06acf4u: goto P_0c06acf4;
case 0x0c06acf6u: goto P_0c06acf6;
case 0x0c06acf8u: goto P_0c06acf8;
case 0x0c06acfau: goto P_0c06acfa;
case 0x0c06acfcu: goto P_0c06acfc;
case 0x0c06acfeu: goto P_0c06acfe;
case 0x0c06ad00u: goto P_0c06ad00;
case 0x0c06ad02u: goto P_0c06ad02;
case 0x0c06ad04u: goto P_0c06ad04;
case 0x0c06ad06u: goto P_0c06ad06;
case 0x0c06ad08u: goto P_0c06ad08;
case 0x0c06ad0au: goto P_0c06ad0a;
case 0x0c06ad0cu: goto P_0c06ad0c;
case 0x0c06ad0eu: goto P_0c06ad0e;
case 0x0c06ad10u: goto P_0c06ad10;
case 0x0c06ad12u: goto P_0c06ad12;
case 0x0c06ad14u: goto P_0c06ad14;
case 0x0c06ad16u: goto P_0c06ad16;
case 0x0c06ad18u: goto P_0c06ad18;
case 0x0c06ad1au: goto P_0c06ad1a;
case 0x0c07b75au: goto P_0c07b75a;
case 0x0c07b75cu: goto P_0c07b75c;
case 0x0c07b75eu: goto P_0c07b75e;
case 0x0c07b760u: goto P_0c07b760;
case 0x0c07b762u: goto P_0c07b762;
case 0x0c07b764u: goto P_0c07b764;
case 0x0c07b766u: goto P_0c07b766;
case 0x0c07b768u: goto P_0c07b768;
case 0x0c07b76au: goto P_0c07b76a;
case 0x0c07b76cu: goto P_0c07b76c;
case 0x0c07b76eu: goto P_0c07b76e;
case 0x0c07b770u: goto P_0c07b770;
case 0x0c07b772u: goto P_0c07b772;
case 0x0c07b774u: goto P_0c07b774;
case 0x0c07b784u: goto P_0c07b784;
case 0x0c07b786u: goto P_0c07b786;
case 0x0c07b788u: goto P_0c07b788;
case 0x0c07b78au: goto P_0c07b78a;
case 0x0c07b78cu: goto P_0c07b78c;
case 0x0c07b78eu: goto P_0c07b78e;
case 0x0c07b790u: goto P_0c07b790;
case 0x0c07b792u: goto P_0c07b792;
case 0x0c07b794u: goto P_0c07b794;
case 0x0c07b796u: goto P_0c07b796;
case 0x0c07b798u: goto P_0c07b798;
case 0x0c07b79au: goto P_0c07b79a;
case 0x0c07b79cu: goto P_0c07b79c;
case 0x0c07b79eu: goto P_0c07b79e;
case 0x0c07b7a0u: goto P_0c07b7a0;
case 0x0c07b7a2u: goto P_0c07b7a2;
case 0x0c07b7a4u: goto P_0c07b7a4;
case 0x0c07b7a6u: goto P_0c07b7a6;
case 0x0c07b7a8u: goto P_0c07b7a8;
case 0x0c07b7aau: goto P_0c07b7aa;
case 0x0c07b7acu: goto P_0c07b7ac;
case 0x0c07b7aeu: goto P_0c07b7ae;
case 0x0c07b7b0u: goto P_0c07b7b0;
case 0x0c07b7b2u: goto P_0c07b7b2;
case 0x0c07b7b4u: goto P_0c07b7b4;
case 0x0c07b7b6u: goto P_0c07b7b6;
case 0x0c07b7b8u: goto P_0c07b7b8;
case 0x0c07b7bau: goto P_0c07b7ba;
case 0x0c07b7bcu: goto P_0c07b7bc;
case 0x0c07b7beu: goto P_0c07b7be;
case 0x0c07b7c0u: goto P_0c07b7c0;
case 0x0c07b7c2u: goto P_0c07b7c2;
case 0x0c07b7c4u: goto P_0c07b7c4;
case 0x0c07b7c6u: goto P_0c07b7c6;
case 0x0c07b7c8u: goto P_0c07b7c8;
case 0x0c07b7cau: goto P_0c07b7ca;
case 0x0c07b7ccu: goto P_0c07b7cc;
case 0x0c07b7ceu: goto P_0c07b7ce;
case 0x0c07b7d0u: goto P_0c07b7d0;
case 0x0c07b7d2u: goto P_0c07b7d2;
case 0x0c07b7d4u: goto P_0c07b7d4;
case 0x0c07b7d6u: goto P_0c07b7d6;
case 0x0c07b7d8u: goto P_0c07b7d8;
case 0x0c07b7dau: goto P_0c07b7da;
case 0x0c07b7dcu: goto P_0c07b7dc;
case 0x0c07b7deu: goto P_0c07b7de;
case 0x0c07b7e0u: goto P_0c07b7e0;
case 0x0c07b7e2u: goto P_0c07b7e2;
case 0x0c07b7e4u: goto P_0c07b7e4;
case 0x0c07b7e6u: goto P_0c07b7e6;
case 0x0c07b7e8u: goto P_0c07b7e8;
case 0x0c07b7eau: goto P_0c07b7ea;
case 0x0c07b7ecu: goto P_0c07b7ec;
case 0x0c07b7eeu: goto P_0c07b7ee;
case 0x0c07b7f0u: goto P_0c07b7f0;
case 0x0c07b7f2u: goto P_0c07b7f2;
case 0x0c07b7f4u: goto P_0c07b7f4;
case 0x0c07b7f6u: goto P_0c07b7f6;
case 0x0c07b7f8u: goto P_0c07b7f8;
case 0x0c07b7fau: goto P_0c07b7fa;
case 0x0c07b7fcu: goto P_0c07b7fc;
case 0x0c07b7feu: goto P_0c07b7fe;
case 0x0c07b800u: goto P_0c07b800;
case 0x0c07b802u: goto P_0c07b802;
case 0x0c07b804u: goto P_0c07b804;
case 0x0c07b806u: goto P_0c07b806;
case 0x0c07b808u: goto P_0c07b808;
case 0x0c07b80au: goto P_0c07b80a;
case 0x0c07b80cu: goto P_0c07b80c;
case 0x0c07b80eu: goto P_0c07b80e;
case 0x0c07b810u: goto P_0c07b810;
case 0x0c07b812u: goto P_0c07b812;
case 0x0c07b814u: goto P_0c07b814;
case 0x0c07b816u: goto P_0c07b816;
case 0x0c07b818u: goto P_0c07b818;
case 0x0c07b81au: goto P_0c07b81a;
case 0x0c07b81cu: goto P_0c07b81c;
case 0x0c07b81eu: goto P_0c07b81e;
case 0x0c07b820u: goto P_0c07b820;
case 0x0c07b822u: goto P_0c07b822;
case 0x0c07b824u: goto P_0c07b824;
case 0x0c07b826u: goto P_0c07b826;
case 0x0c07b828u: goto P_0c07b828;
case 0x0c07b82au: goto P_0c07b82a;
case 0x0c07b82cu: goto P_0c07b82c;
case 0x0c07b82eu: goto P_0c07b82e;
case 0x0c07b830u: goto P_0c07b830;
case 0x0c07b832u: goto P_0c07b832;
case 0x0c07b834u: goto P_0c07b834;
case 0x0c07b836u: goto P_0c07b836;
case 0x0c07b838u: goto P_0c07b838;
case 0x0c07b83au: goto P_0c07b83a;
case 0x0c07b83cu: goto P_0c07b83c;
case 0x0c07b83eu: goto P_0c07b83e;
case 0x0c082e0eu: goto P_0c082e0e;
case 0x0c082e10u: goto P_0c082e10;
case 0x0c082e12u: goto P_0c082e12;
case 0x0c082e14u: goto P_0c082e14;
case 0x0c082e16u: goto P_0c082e16;
case 0x0c082e18u: goto P_0c082e18;
case 0x0c082e1au: goto P_0c082e1a;
case 0x0c082e1cu: goto P_0c082e1c;
case 0x0c082e1eu: goto P_0c082e1e;
case 0x0c082e20u: goto P_0c082e20;
case 0x0c082e22u: goto P_0c082e22;
case 0x0c082e24u: goto P_0c082e24;
case 0x0c082e26u: goto P_0c082e26;
case 0x0c082e28u: goto P_0c082e28;
case 0x0c082e2au: goto P_0c082e2a;
case 0x0c082e2cu: goto P_0c082e2c;
case 0x0c082e2eu: goto P_0c082e2e;
case 0x0c082e30u: goto P_0c082e30;
case 0x0c082e32u: goto P_0c082e32;
case 0x0c082e34u: goto P_0c082e34;
case 0x0c082e36u: goto P_0c082e36;
case 0x0c082e38u: goto P_0c082e38;
case 0x0c082e3au: goto P_0c082e3a;
case 0x0c082e3cu: goto P_0c082e3c;
case 0x0c082e3eu: goto P_0c082e3e;
case 0x0c082e40u: goto P_0c082e40;
case 0x0c082e42u: goto P_0c082e42;
case 0x0c082e44u: goto P_0c082e44;
case 0x0c082e46u: goto P_0c082e46;
case 0x0c082e48u: goto P_0c082e48;
case 0x0c082e4au: goto P_0c082e4a;
case 0x0c082e4cu: goto P_0c082e4c;
case 0x0c082e4eu: goto P_0c082e4e;
case 0x0c082e50u: goto P_0c082e50;
case 0x0c082e52u: goto P_0c082e52;
case 0x0c082e54u: goto P_0c082e54;
case 0x0c082e56u: goto P_0c082e56;
case 0x0c082e58u: goto P_0c082e58;
case 0x0c082e5au: goto P_0c082e5a;
case 0x0c082e5cu: goto P_0c082e5c;
case 0x0c082e5eu: goto P_0c082e5e;
case 0x0c082e60u: goto P_0c082e60;
case 0x0c082e62u: goto P_0c082e62;
case 0x0c082e64u: goto P_0c082e64;
case 0x0c082e66u: goto P_0c082e66;
case 0x0c082ee4u: goto P_0c082ee4;
case 0x0c082ee6u: goto P_0c082ee6;
case 0x0c082ee8u: goto P_0c082ee8;
case 0x0c082eeau: goto P_0c082eea;
case 0x0c082eecu: goto P_0c082eec;
case 0x0c082eeeu: goto P_0c082eee;
case 0x0c082ef0u: goto P_0c082ef0;
case 0x0c082ef2u: goto P_0c082ef2;
case 0x0c082ef4u: goto P_0c082ef4;
case 0x0c082ef6u: goto P_0c082ef6;
case 0x0c082ef8u: goto P_0c082ef8;
case 0x0c082efau: goto P_0c082efa;
case 0x0c082efcu: goto P_0c082efc;
case 0x0c082efeu: goto P_0c082efe;
case 0x0c082f00u: goto P_0c082f00;
case 0x0c082f02u: goto P_0c082f02;
case 0x0c082f04u: goto P_0c082f04;
case 0x0c082f06u: goto P_0c082f06;
case 0x0c082f08u: goto P_0c082f08;
case 0x0c082f0au: goto P_0c082f0a;
case 0x0c082f0cu: goto P_0c082f0c;
case 0x0c0831b4u: goto P_0c0831b4;
case 0x0c0831b6u: goto P_0c0831b6;
case 0x0c0831b8u: goto P_0c0831b8;
case 0x0c0831bau: goto P_0c0831ba;
case 0x0c0831bcu: goto P_0c0831bc;
case 0x0c0831beu: goto P_0c0831be;
case 0x0c0831c0u: goto P_0c0831c0;
case 0x0c0831c2u: goto P_0c0831c2;
case 0x0c0831c4u: goto P_0c0831c4;
case 0x0c0831c6u: goto P_0c0831c6;
case 0x0c0831c8u: goto P_0c0831c8;
case 0x0c0831cau: goto P_0c0831ca;
case 0x0c0831ccu: goto P_0c0831cc;
case 0x0c0831ceu: goto P_0c0831ce;
case 0x0c0831d0u: goto P_0c0831d0;
case 0x0c0831d2u: goto P_0c0831d2;
case 0x0c0831d4u: goto P_0c0831d4;
case 0x0c0831d6u: goto P_0c0831d6;
case 0x0c0831d8u: goto P_0c0831d8;
case 0x0c0831dau: goto P_0c0831da;
case 0x0c0831dcu: goto P_0c0831dc;
case 0x0c0831deu: goto P_0c0831de;
case 0x0c0831e0u: goto P_0c0831e0;
case 0x0c0831e2u: goto P_0c0831e2;
case 0x0c0831e4u: goto P_0c0831e4;
case 0x0c0831e6u: goto P_0c0831e6;
case 0x0c0831e8u: goto P_0c0831e8;
case 0x0c086b20u: goto P_0c086b20;
case 0x0c086b22u: goto P_0c086b22;
case 0x0c086b24u: goto P_0c086b24;
case 0x0c086b26u: goto P_0c086b26;
case 0x0c086b28u: goto P_0c086b28;
case 0x0c086b2au: goto P_0c086b2a;
case 0x0c086b2cu: goto P_0c086b2c;
case 0x0c086b2eu: goto P_0c086b2e;
case 0x0c086b30u: goto P_0c086b30;
case 0x0c086b32u: goto P_0c086b32;
case 0x0c086b34u: goto P_0c086b34;
case 0x0c086b36u: goto P_0c086b36;
case 0x0c086b38u: goto P_0c086b38;
case 0x0c086b3au: goto P_0c086b3a;
case 0x0c086b3cu: goto P_0c086b3c;
case 0x0c086b3eu: goto P_0c086b3e;
case 0x0c086b40u: goto P_0c086b40;
case 0x0c086b42u: goto P_0c086b42;
case 0x0c086b44u: goto P_0c086b44;
case 0x0c086b46u: goto P_0c086b46;
case 0x0c086b48u: goto P_0c086b48;
case 0x0c086b4au: goto P_0c086b4a;
case 0x0c086b4cu: goto P_0c086b4c;
case 0x0c086b4eu: goto P_0c086b4e;
case 0x0c086b50u: goto P_0c086b50;
case 0x0c086b52u: goto P_0c086b52;
case 0x0c086b54u: goto P_0c086b54;
case 0x0c086b56u: goto P_0c086b56;
case 0x0c086b58u: goto P_0c086b58;
case 0x0c086b5au: goto P_0c086b5a;
case 0x0c086b5cu: goto P_0c086b5c;
case 0x0c086b5eu: goto P_0c086b5e;
case 0x0c086b60u: goto P_0c086b60;
case 0x0c086b62u: goto P_0c086b62;
case 0x0c086b64u: goto P_0c086b64;
case 0x0c086b66u: goto P_0c086b66;
case 0x0c086b68u: goto P_0c086b68;
case 0x0c086b6au: goto P_0c086b6a;
case 0x0c086b6cu: goto P_0c086b6c;
case 0x0c086b6eu: goto P_0c086b6e;
case 0x0c086b70u: goto P_0c086b70;
case 0x0c086b72u: goto P_0c086b72;
case 0x0c086b74u: goto P_0c086b74;
case 0x0c086b76u: goto P_0c086b76;
case 0x0c086b78u: goto P_0c086b78;
case 0x0c086b7au: goto P_0c086b7a;
case 0x0c086b7cu: goto P_0c086b7c;
case 0x0c086b7eu: goto P_0c086b7e;
case 0x0c086b80u: goto P_0c086b80;
case 0x0c086b9cu: goto P_0c086b9c;
case 0x0c086b9eu: goto P_0c086b9e;
case 0x0c086ba0u: goto P_0c086ba0;
case 0x0c086ba2u: goto P_0c086ba2;
case 0x0c086ba4u: goto P_0c086ba4;
case 0x0c086ba6u: goto P_0c086ba6;
case 0x0c086ba8u: goto P_0c086ba8;
case 0x0c086baau: goto P_0c086baa;
case 0x0c086bacu: goto P_0c086bac;
case 0x0c086baeu: goto P_0c086bae;
case 0x0c086bb0u: goto P_0c086bb0;
case 0x0c086bb2u: goto P_0c086bb2;
case 0x0c086bb4u: goto P_0c086bb4;
case 0x0c086bb6u: goto P_0c086bb6;
case 0x0c086bb8u: goto P_0c086bb8;
case 0x0c086bbau: goto P_0c086bba;
case 0x0c086bbcu: goto P_0c086bbc;
case 0x0c086bbeu: goto P_0c086bbe;
case 0x0c086bc0u: goto P_0c086bc0;
case 0x0c086bc2u: goto P_0c086bc2;
case 0x0c086bc4u: goto P_0c086bc4;
case 0x0c086bc6u: goto P_0c086bc6;
case 0x0c086bc8u: goto P_0c086bc8;
case 0x0c086bcau: goto P_0c086bca;
case 0x0c086bccu: goto P_0c086bcc;
case 0x0c086bceu: goto P_0c086bce;
case 0x0c086bd0u: goto P_0c086bd0;
case 0x0c086bd2u: goto P_0c086bd2;
case 0x0c086bd4u: goto P_0c086bd4;
case 0x0c086bd6u: goto P_0c086bd6;
case 0x0c086bd8u: goto P_0c086bd8;
case 0x0c086bdau: goto P_0c086bda;
case 0x0c086bdcu: goto P_0c086bdc;
case 0x0c086bdeu: goto P_0c086bde;
case 0x0c086be0u: goto P_0c086be0;
case 0x0c086be2u: goto P_0c086be2;
case 0x0c086be4u: goto P_0c086be4;
case 0x0c086be6u: goto P_0c086be6;
case 0x0c086be8u: goto P_0c086be8;
case 0x0c086beau: goto P_0c086bea;
case 0x0c086becu: goto P_0c086bec;
case 0x0c086beeu: goto P_0c086bee;
case 0x0c086bf0u: goto P_0c086bf0;
case 0x0c086bf2u: goto P_0c086bf2;
case 0x0c086bf4u: goto P_0c086bf4;
case 0x0c086bf6u: goto P_0c086bf6;
case 0x0c086bf8u: goto P_0c086bf8;
case 0x0c086bfau: goto P_0c086bfa;
case 0x0c086bfcu: goto P_0c086bfc;
case 0x0c086bfeu: goto P_0c086bfe;
case 0x0c086c00u: goto P_0c086c00;
case 0x0c086c02u: goto P_0c086c02;
case 0x0c086c04u: goto P_0c086c04;
case 0x0c086c06u: goto P_0c086c06;
case 0x0c086c08u: goto P_0c086c08;
case 0x0c086c0au: goto P_0c086c0a;
case 0x0c086c0cu: goto P_0c086c0c;
case 0x0c086c0eu: goto P_0c086c0e;
case 0x0c086c10u: goto P_0c086c10;
case 0x0c086c12u: goto P_0c086c12;
case 0x0c086c14u: goto P_0c086c14;
case 0x0c086c16u: goto P_0c086c16;
case 0x0c086c18u: goto P_0c086c18;
case 0x0c086c1au: goto P_0c086c1a;
case 0x0c086c1cu: goto P_0c086c1c;
case 0x0c086c1eu: goto P_0c086c1e;
case 0x0c086c20u: goto P_0c086c20;
case 0x0c086c22u: goto P_0c086c22;
case 0x0c086c24u: goto P_0c086c24;
case 0x0c086c26u: goto P_0c086c26;
case 0x0c086c28u: goto P_0c086c28;
case 0x0c086c2au: goto P_0c086c2a;
case 0x0c086c2cu: goto P_0c086c2c;
case 0x0c086c2eu: goto P_0c086c2e;
case 0x0c086c30u: goto P_0c086c30;
case 0x0c086c32u: goto P_0c086c32;
case 0x0c086c34u: goto P_0c086c34;
case 0x0c086c36u: goto P_0c086c36;
case 0x0c086c38u: goto P_0c086c38;
case 0x0c086c3au: goto P_0c086c3a;
case 0x0c086c3cu: goto P_0c086c3c;
case 0x0c086c3eu: goto P_0c086c3e;
case 0x0c086c40u: goto P_0c086c40;
case 0x0c086c42u: goto P_0c086c42;
case 0x0c086c44u: goto P_0c086c44;
case 0x0c086c46u: goto P_0c086c46;
case 0x0c086c48u: goto P_0c086c48;
case 0x0c086c4au: goto P_0c086c4a;
case 0x0c086c4cu: goto P_0c086c4c;
case 0x0c086c4eu: goto P_0c086c4e;
case 0x0c086c50u: goto P_0c086c50;
case 0x0c086c52u: goto P_0c086c52;
case 0x0c086c54u: goto P_0c086c54;
case 0x0c086c56u: goto P_0c086c56;
case 0x0c086c58u: goto P_0c086c58;
case 0x0c086c5au: goto P_0c086c5a;
case 0x0c086c5cu: goto P_0c086c5c;
case 0x0c086c5eu: goto P_0c086c5e;
case 0x0c086c60u: goto P_0c086c60;
case 0x0c086c62u: goto P_0c086c62;
case 0x0c086c64u: goto P_0c086c64;
case 0x0c086c66u: goto P_0c086c66;
case 0x0c086c68u: goto P_0c086c68;
case 0x0c086c6au: goto P_0c086c6a;
case 0x0c086c6cu: goto P_0c086c6c;
case 0x0c086c6eu: goto P_0c086c6e;
case 0x0c086c70u: goto P_0c086c70;
case 0x0c086c72u: goto P_0c086c72;
case 0x0c086c74u: goto P_0c086c74;
case 0x0c086c76u: goto P_0c086c76;
case 0x0c086c78u: goto P_0c086c78;
case 0x0c086c7au: goto P_0c086c7a;
case 0x0c086c7cu: goto P_0c086c7c;
case 0x0c086c7eu: goto P_0c086c7e;
case 0x0c086c80u: goto P_0c086c80;
case 0x0c086c82u: goto P_0c086c82;
case 0x0c086c84u: goto P_0c086c84;
case 0x0c086c86u: goto P_0c086c86;
case 0x0c086c88u: goto P_0c086c88;
case 0x0c086c8au: goto P_0c086c8a;
case 0x0c086c8cu: goto P_0c086c8c;
case 0x0c086c8eu: goto P_0c086c8e;
case 0x0c086c90u: goto P_0c086c90;
case 0x0c086c92u: goto P_0c086c92;
case 0x0c086c94u: goto P_0c086c94;
case 0x0c086c96u: goto P_0c086c96;
case 0x0c086c98u: goto P_0c086c98;
case 0x0c086c9au: goto P_0c086c9a;
case 0x0c086c9cu: goto P_0c086c9c;
case 0x0c086c9eu: goto P_0c086c9e;
case 0x0c086ca0u: goto P_0c086ca0;
case 0x0c086ca2u: goto P_0c086ca2;
case 0x0c086ca4u: goto P_0c086ca4;
case 0x0c086ca6u: goto P_0c086ca6;
case 0x0c086ca8u: goto P_0c086ca8;
case 0x0c086caau: goto P_0c086caa;
case 0x0c086cacu: goto P_0c086cac;
case 0x0c086caeu: goto P_0c086cae;
case 0x0c086cb0u: goto P_0c086cb0;
case 0x0c086cb2u: goto P_0c086cb2;
case 0x0c086cb4u: goto P_0c086cb4;
case 0x0c086cb6u: goto P_0c086cb6;
case 0x0c086cb8u: goto P_0c086cb8;
case 0x0c086cbau: goto P_0c086cba;
case 0x0c086cbcu: goto P_0c086cbc;
case 0x0c086cbeu: goto P_0c086cbe;
case 0x0c086cc0u: goto P_0c086cc0;
case 0x0c086cc2u: goto P_0c086cc2;
case 0x0c086cc4u: goto P_0c086cc4;
case 0x0c086cc6u: goto P_0c086cc6;
case 0x0c086cc8u: goto P_0c086cc8;
case 0x0c086ccau: goto P_0c086cca;
case 0x0c086cccu: goto P_0c086ccc;
case 0x0c086cceu: goto P_0c086cce;
case 0x0c086cd0u: goto P_0c086cd0;
case 0x0c086cd2u: goto P_0c086cd2;
case 0x0c086cfcu: goto P_0c086cfc;
case 0x0c086cfeu: goto P_0c086cfe;
case 0x0c086d00u: goto P_0c086d00;
case 0x0c086d02u: goto P_0c086d02;
case 0x0c086d04u: goto P_0c086d04;
case 0x0c086d06u: goto P_0c086d06;
case 0x0c086d08u: goto P_0c086d08;
case 0x0c086d0au: goto P_0c086d0a;
case 0x0c086d0cu: goto P_0c086d0c;
case 0x0c086d0eu: goto P_0c086d0e;
case 0x0c086d10u: goto P_0c086d10;
case 0x0c086d12u: goto P_0c086d12;
case 0x0c086d14u: goto P_0c086d14;
case 0x0c086d16u: goto P_0c086d16;
case 0x0c086d18u: goto P_0c086d18;
case 0x0c086d1au: goto P_0c086d1a;
case 0x0c086d1cu: goto P_0c086d1c;
case 0x0c086d1eu: goto P_0c086d1e;
case 0x0c086d20u: goto P_0c086d20;
case 0x0c086d22u: goto P_0c086d22;
case 0x0c086d24u: goto P_0c086d24;
case 0x0c086d26u: goto P_0c086d26;
case 0x0c086d28u: goto P_0c086d28;
case 0x0c086d2au: goto P_0c086d2a;
case 0x0c086d2cu: goto P_0c086d2c;
case 0x0c086d2eu: goto P_0c086d2e;
case 0x0c086d30u: goto P_0c086d30;
case 0x0c086d32u: goto P_0c086d32;
case 0x0c086d34u: goto P_0c086d34;
case 0x0c086d36u: goto P_0c086d36;
case 0x0c086d38u: goto P_0c086d38;
case 0x0c086d3au: goto P_0c086d3a;
case 0x0c086d3cu: goto P_0c086d3c;
case 0x0c086d3eu: goto P_0c086d3e;
case 0x0c086d40u: goto P_0c086d40;
case 0x0c086d42u: goto P_0c086d42;
case 0x0c086d44u: goto P_0c086d44;
case 0x0c086d46u: goto P_0c086d46;
case 0x0c086d48u: goto P_0c086d48;
case 0x0c086d4au: goto P_0c086d4a;
case 0x0c086d4cu: goto P_0c086d4c;
case 0x0c086d4eu: goto P_0c086d4e;
case 0x0c086d50u: goto P_0c086d50;
case 0x0c086d52u: goto P_0c086d52;
case 0x0c086d54u: goto P_0c086d54;
case 0x0c086d56u: goto P_0c086d56;
case 0x0c086d58u: goto P_0c086d58;
case 0x0c086d5au: goto P_0c086d5a;
case 0x0c086d5cu: goto P_0c086d5c;
case 0x0c086d5eu: goto P_0c086d5e;
case 0x0c086d60u: goto P_0c086d60;
case 0x0c086d62u: goto P_0c086d62;
case 0x0c086d64u: goto P_0c086d64;
case 0x0c086d66u: goto P_0c086d66;
case 0x0c086d68u: goto P_0c086d68;
case 0x0c086d6au: goto P_0c086d6a;
case 0x0c086d6cu: goto P_0c086d6c;
case 0x0c086d6eu: goto P_0c086d6e;
case 0x0c086d70u: goto P_0c086d70;
case 0x0c086d72u: goto P_0c086d72;
case 0x0c086d74u: goto P_0c086d74;
case 0x0c086d76u: goto P_0c086d76;
case 0x0c086d78u: goto P_0c086d78;
case 0x0c086d7au: goto P_0c086d7a;
case 0x0c086d7cu: goto P_0c086d7c;
case 0x0c086d7eu: goto P_0c086d7e;
case 0x0c086d80u: goto P_0c086d80;
case 0x0c086d82u: goto P_0c086d82;
case 0x0c086d84u: goto P_0c086d84;
case 0x0c086d86u: goto P_0c086d86;
case 0x0c086d88u: goto P_0c086d88;
case 0x0c086d8au: goto P_0c086d8a;
case 0x0c086d8cu: goto P_0c086d8c;
case 0x0c086d8eu: goto P_0c086d8e;
case 0x0c086d90u: goto P_0c086d90;
case 0x0c086d92u: goto P_0c086d92;
case 0x0c086d94u: goto P_0c086d94;
case 0x0c086d96u: goto P_0c086d96;
case 0x0c086d98u: goto P_0c086d98;
case 0x0c086d9au: goto P_0c086d9a;
case 0x0c086d9cu: goto P_0c086d9c;
case 0x0c086d9eu: goto P_0c086d9e;
case 0x0c086da0u: goto P_0c086da0;
case 0x0c086da2u: goto P_0c086da2;
case 0x0c086da4u: goto P_0c086da4;
case 0x0c086da6u: goto P_0c086da6;
case 0x0c086da8u: goto P_0c086da8;
case 0x0c086daau: goto P_0c086daa;
case 0x0c086dacu: goto P_0c086dac;
case 0x0c086daeu: goto P_0c086dae;
case 0x0c086db0u: goto P_0c086db0;
case 0x0c086db2u: goto P_0c086db2;
case 0x0c086db4u: goto P_0c086db4;
case 0x0c086db6u: goto P_0c086db6;
case 0x0c086db8u: goto P_0c086db8;
case 0x0c086dbau: goto P_0c086dba;
case 0x0c086dbcu: goto P_0c086dbc;
case 0x0c086dbeu: goto P_0c086dbe;
case 0x0c086dc0u: goto P_0c086dc0;
case 0x0c086dc2u: goto P_0c086dc2;
case 0x0c086dc4u: goto P_0c086dc4;
case 0x0c086dc6u: goto P_0c086dc6;
case 0x0c086dc8u: goto P_0c086dc8;
case 0x0c086dcau: goto P_0c086dca;
case 0x0c086dccu: goto P_0c086dcc;
case 0x0c086dceu: goto P_0c086dce;
case 0x0c086dd0u: goto P_0c086dd0;
case 0x0c086dd2u: goto P_0c086dd2;
case 0x0c086dd4u: goto P_0c086dd4;
case 0x0c086dd6u: goto P_0c086dd6;
case 0x0c086dd8u: goto P_0c086dd8;
case 0x0c086ddau: goto P_0c086dda;
case 0x0c086ddcu: goto P_0c086ddc;
case 0x0c086ddeu: goto P_0c086dde;
case 0x0c086de0u: goto P_0c086de0;
case 0x0c086de2u: goto P_0c086de2;
case 0x0c086de4u: goto P_0c086de4;
case 0x0c086de6u: goto P_0c086de6;
case 0x0c086de8u: goto P_0c086de8;
case 0x0c086deau: goto P_0c086dea;
case 0x0c086decu: goto P_0c086dec;
case 0x0c086deeu: goto P_0c086dee;
case 0x0c086df0u: goto P_0c086df0;
case 0x0c086df2u: goto P_0c086df2;
case 0x0c086df4u: goto P_0c086df4;
case 0x0c086df6u: goto P_0c086df6;
case 0x0c086df8u: goto P_0c086df8;
case 0x0c086dfau: goto P_0c086dfa;
case 0x0c086dfcu: goto P_0c086dfc;
case 0x0c086dfeu: goto P_0c086dfe;
case 0x0c086e00u: goto P_0c086e00;
case 0x0c086e02u: goto P_0c086e02;
case 0x0c086e04u: goto P_0c086e04;
case 0x0c086e06u: goto P_0c086e06;
case 0x0c086e08u: goto P_0c086e08;
case 0x0c086e0au: goto P_0c086e0a;
case 0x0c086e0cu: goto P_0c086e0c;
case 0x0c086e0eu: goto P_0c086e0e;
case 0x0c086e10u: goto P_0c086e10;
case 0x0c086e12u: goto P_0c086e12;
case 0x0c086e14u: goto P_0c086e14;
case 0x0c086e16u: goto P_0c086e16;
case 0x0c086e18u: goto P_0c086e18;
case 0x0c086e1au: goto P_0c086e1a;
case 0x0c086e1cu: goto P_0c086e1c;
case 0x0c086e1eu: goto P_0c086e1e;
case 0x0c086e20u: goto P_0c086e20;
case 0x0c086e22u: goto P_0c086e22;
case 0x0c086e24u: goto P_0c086e24;
case 0x0c086e4cu: goto P_0c086e4c;
case 0x0c086e4eu: goto P_0c086e4e;
case 0x0c086e50u: goto P_0c086e50;
case 0x0c086e52u: goto P_0c086e52;
case 0x0c086e54u: goto P_0c086e54;
case 0x0c086e56u: goto P_0c086e56;
case 0x0c086e58u: goto P_0c086e58;
case 0x0c086e5au: goto P_0c086e5a;
case 0x0c086e5cu: goto P_0c086e5c;
case 0x0c086e5eu: goto P_0c086e5e;
case 0x0c086e60u: goto P_0c086e60;
case 0x0c086e62u: goto P_0c086e62;
case 0x0c086e64u: goto P_0c086e64;
case 0x0c086e66u: goto P_0c086e66;
case 0x0c086e68u: goto P_0c086e68;
case 0x0c086e6au: goto P_0c086e6a;
case 0x0c086e6cu: goto P_0c086e6c;
case 0x0c086e6eu: goto P_0c086e6e;
case 0x0c086e70u: goto P_0c086e70;
case 0x0c086e72u: goto P_0c086e72;
case 0x0c086e74u: goto P_0c086e74;
case 0x0c086e76u: goto P_0c086e76;
case 0x0c086e78u: goto P_0c086e78;
case 0x0c086e7au: goto P_0c086e7a;
case 0x0c086e7cu: goto P_0c086e7c;
case 0x0c086e7eu: goto P_0c086e7e;
case 0x0c086e80u: goto P_0c086e80;
case 0x0c086e82u: goto P_0c086e82;
case 0x0c086e84u: goto P_0c086e84;
case 0x0c086e86u: goto P_0c086e86;
case 0x0c086e88u: goto P_0c086e88;
case 0x0c086e8au: goto P_0c086e8a;
case 0x0c086e8cu: goto P_0c086e8c;
case 0x0c086e8eu: goto P_0c086e8e;
case 0x0c086e90u: goto P_0c086e90;
case 0x0c086e92u: goto P_0c086e92;
case 0x0c086e94u: goto P_0c086e94;
case 0x0c086e96u: goto P_0c086e96;
case 0x0c086e98u: goto P_0c086e98;
case 0x0c086e9au: goto P_0c086e9a;
case 0x0c086e9cu: goto P_0c086e9c;
case 0x0c086e9eu: goto P_0c086e9e;
case 0x0c086ea0u: goto P_0c086ea0;
case 0x0c086ea2u: goto P_0c086ea2;
case 0x0c086ea4u: goto P_0c086ea4;
case 0x0c086ea6u: goto P_0c086ea6;
case 0x0c086ea8u: goto P_0c086ea8;
case 0x0c086eaau: goto P_0c086eaa;
case 0x0c086eacu: goto P_0c086eac;
case 0x0c086eaeu: goto P_0c086eae;
case 0x0c086eb0u: goto P_0c086eb0;
case 0x0c086eb2u: goto P_0c086eb2;
case 0x0c086eb4u: goto P_0c086eb4;
case 0x0c086eb6u: goto P_0c086eb6;
case 0x0c086eb8u: goto P_0c086eb8;
case 0x0c086ebau: goto P_0c086eba;
case 0x0c086ebcu: goto P_0c086ebc;
case 0x0c086ebeu: goto P_0c086ebe;
case 0x0c086ec0u: goto P_0c086ec0;
case 0x0c086ec2u: goto P_0c086ec2;
case 0x0c086ec4u: goto P_0c086ec4;
case 0x0c086ec6u: goto P_0c086ec6;
case 0x0c086ec8u: goto P_0c086ec8;
case 0x0c086ecau: goto P_0c086eca;
case 0x0c086eccu: goto P_0c086ecc;
case 0x0c086eceu: goto P_0c086ece;
case 0x0c086ed0u: goto P_0c086ed0;
case 0x0c086ed2u: goto P_0c086ed2;
case 0x0c086ed4u: goto P_0c086ed4;
case 0x0c086ed6u: goto P_0c086ed6;
case 0x0c086ed8u: goto P_0c086ed8;
case 0x0c086edau: goto P_0c086eda;
case 0x0c086edcu: goto P_0c086edc;
case 0x0c086edeu: goto P_0c086ede;
case 0x0c086ee0u: goto P_0c086ee0;
case 0x0c086ee2u: goto P_0c086ee2;
case 0x0c086ee4u: goto P_0c086ee4;
case 0x0c086ee6u: goto P_0c086ee6;
case 0x0c086ee8u: goto P_0c086ee8;
case 0x0c086eeau: goto P_0c086eea;
case 0x0c086eecu: goto P_0c086eec;
case 0x0c086eeeu: goto P_0c086eee;
case 0x0c086ef0u: goto P_0c086ef0;
case 0x0c086ef2u: goto P_0c086ef2;
case 0x0c086ef4u: goto P_0c086ef4;
case 0x0c086ef6u: goto P_0c086ef6;
case 0x0c086ef8u: goto P_0c086ef8;
case 0x0c086efau: goto P_0c086efa;
case 0x0c086efcu: goto P_0c086efc;
case 0x0c086efeu: goto P_0c086efe;
case 0x0c086f00u: goto P_0c086f00;
case 0x0c086f02u: goto P_0c086f02;
case 0x0c086f04u: goto P_0c086f04;
case 0x0c086f06u: goto P_0c086f06;
case 0x0c086f08u: goto P_0c086f08;
case 0x0c086f0au: goto P_0c086f0a;
case 0x0c086f0cu: goto P_0c086f0c;
case 0x0c086f0eu: goto P_0c086f0e;
case 0x0c086f10u: goto P_0c086f10;
case 0x0c086f12u: goto P_0c086f12;
case 0x0c086f14u: goto P_0c086f14;
case 0x0c086f16u: goto P_0c086f16;
case 0x0c086f18u: goto P_0c086f18;
case 0x0c086f1au: goto P_0c086f1a;
case 0x0c086f1cu: goto P_0c086f1c;
case 0x0c086f1eu: goto P_0c086f1e;
case 0x0c086f20u: goto P_0c086f20;
case 0x0c086f22u: goto P_0c086f22;
case 0x0c086f24u: goto P_0c086f24;
case 0x0c086f26u: goto P_0c086f26;
case 0x0c086f28u: goto P_0c086f28;
case 0x0c086f2au: goto P_0c086f2a;
case 0x0c086f2cu: goto P_0c086f2c;
case 0x0c086f2eu: goto P_0c086f2e;
case 0x0c086f30u: goto P_0c086f30;
case 0x0c086f32u: goto P_0c086f32;
case 0x0c086f34u: goto P_0c086f34;
case 0x0c086f36u: goto P_0c086f36;
case 0x0c086f38u: goto P_0c086f38;
case 0x0c086f3au: goto P_0c086f3a;
case 0x0c086f3cu: goto P_0c086f3c;
case 0x0c086f3eu: goto P_0c086f3e;
case 0x0c086f40u: goto P_0c086f40;
case 0x0c086f42u: goto P_0c086f42;
case 0x0c086f44u: goto P_0c086f44;
case 0x0c086f46u: goto P_0c086f46;
case 0x0c086f48u: goto P_0c086f48;
case 0x0c086f4au: goto P_0c086f4a;
case 0x0c086f4cu: goto P_0c086f4c;
case 0x0c086f4eu: goto P_0c086f4e;
case 0x0c086f50u: goto P_0c086f50;
case 0x0c086f52u: goto P_0c086f52;
case 0x0c086f54u: goto P_0c086f54;
case 0x0c086f56u: goto P_0c086f56;
case 0x0c086f58u: goto P_0c086f58;
case 0x0c086f5au: goto P_0c086f5a;
case 0x0c086f5cu: goto P_0c086f5c;
case 0x0c086f5eu: goto P_0c086f5e;
case 0x0c086f60u: goto P_0c086f60;
case 0x0c086f62u: goto P_0c086f62;
case 0x0c086f64u: goto P_0c086f64;
case 0x0c086f66u: goto P_0c086f66;
case 0x0c086f68u: goto P_0c086f68;
case 0x0c086f6au: goto P_0c086f6a;
case 0x0c086f80u: goto P_0c086f80;
case 0x0c086f82u: goto P_0c086f82;
case 0x0c086f84u: goto P_0c086f84;
case 0x0c086f86u: goto P_0c086f86;
case 0x0c086f88u: goto P_0c086f88;
case 0x0c086f8au: goto P_0c086f8a;
case 0x0c086f8cu: goto P_0c086f8c;
case 0x0c086f8eu: goto P_0c086f8e;
case 0x0c086f90u: goto P_0c086f90;
case 0x0c086f92u: goto P_0c086f92;
case 0x0c086f94u: goto P_0c086f94;
case 0x0c086f96u: goto P_0c086f96;
case 0x0c086f98u: goto P_0c086f98;
case 0x0c086f9au: goto P_0c086f9a;
case 0x0c086f9cu: goto P_0c086f9c;
case 0x0c086f9eu: goto P_0c086f9e;
case 0x0c086fa0u: goto P_0c086fa0;
case 0x0c086fa2u: goto P_0c086fa2;
case 0x0c086fa4u: goto P_0c086fa4;
case 0x0c086fa6u: goto P_0c086fa6;
case 0x0c086fa8u: goto P_0c086fa8;
case 0x0c086faau: goto P_0c086faa;
case 0x0c086facu: goto P_0c086fac;
case 0x0c086faeu: goto P_0c086fae;
case 0x0c086fb0u: goto P_0c086fb0;
case 0x0c086fb2u: goto P_0c086fb2;
case 0x0c086fb4u: goto P_0c086fb4;
case 0x0c086fb6u: goto P_0c086fb6;
case 0x0c086fb8u: goto P_0c086fb8;
case 0x0c086fbau: goto P_0c086fba;
case 0x0c086fbcu: goto P_0c086fbc;
case 0x0c086fbeu: goto P_0c086fbe;
case 0x0c086fc0u: goto P_0c086fc0;
case 0x0c086fc2u: goto P_0c086fc2;
case 0x0c086fc4u: goto P_0c086fc4;
case 0x0c086fc6u: goto P_0c086fc6;
case 0x0c086fc8u: goto P_0c086fc8;
case 0x0c086fcau: goto P_0c086fca;
case 0x0c086fccu: goto P_0c086fcc;
case 0x0c086fceu: goto P_0c086fce;
case 0x0c086fd0u: goto P_0c086fd0;
case 0x0c086fd2u: goto P_0c086fd2;
case 0x0c086fd4u: goto P_0c086fd4;
case 0x0c086fd6u: goto P_0c086fd6;
case 0x0c086fd8u: goto P_0c086fd8;
case 0x0c086fdau: goto P_0c086fda;
case 0x0c086fdcu: goto P_0c086fdc;
case 0x0c086fdeu: goto P_0c086fde;
case 0x0c086fe0u: goto P_0c086fe0;
case 0x0c086fe2u: goto P_0c086fe2;
case 0x0c086fe4u: goto P_0c086fe4;
case 0x0c086fe6u: goto P_0c086fe6;
case 0x0c086fe8u: goto P_0c086fe8;
case 0x0c086feau: goto P_0c086fea;
case 0x0c086fecu: goto P_0c086fec;
case 0x0c086feeu: goto P_0c086fee;
case 0x0c086ff0u: goto P_0c086ff0;
case 0x0c086ff2u: goto P_0c086ff2;
case 0x0c086ff4u: goto P_0c086ff4;
case 0x0c086ff6u: goto P_0c086ff6;
case 0x0c086ff8u: goto P_0c086ff8;
case 0x0c086ffau: goto P_0c086ffa;
case 0x0c086ffcu: goto P_0c086ffc;
case 0x0c086ffeu: goto P_0c086ffe;
case 0x0c087000u: goto P_0c087000;
case 0x0c087002u: goto P_0c087002;
case 0x0c087004u: goto P_0c087004;
case 0x0c087006u: goto P_0c087006;
case 0x0c087008u: goto P_0c087008;
case 0x0c08700au: goto P_0c08700a;
case 0x0c08700cu: goto P_0c08700c;
case 0x0c08700eu: goto P_0c08700e;
case 0x0c087010u: goto P_0c087010;
case 0x0c087012u: goto P_0c087012;
case 0x0c087014u: goto P_0c087014;
case 0x0c087016u: goto P_0c087016;
case 0x0c087018u: goto P_0c087018;
case 0x0c08701au: goto P_0c08701a;
case 0x0c08701cu: goto P_0c08701c;
case 0x0c08701eu: goto P_0c08701e;
case 0x0c087020u: goto P_0c087020;
case 0x0c087022u: goto P_0c087022;
case 0x0c087024u: goto P_0c087024;
case 0x0c087026u: goto P_0c087026;
case 0x0c087028u: goto P_0c087028;
case 0x0c08702au: goto P_0c08702a;
case 0x0c08702cu: goto P_0c08702c;
case 0x0c08702eu: goto P_0c08702e;
case 0x0c087030u: goto P_0c087030;
case 0x0c087032u: goto P_0c087032;
case 0x0c087034u: goto P_0c087034;
case 0x0c087036u: goto P_0c087036;
case 0x0c087038u: goto P_0c087038;
case 0x0c08703au: goto P_0c08703a;
case 0x0c08703cu: goto P_0c08703c;
case 0x0c08703eu: goto P_0c08703e;
case 0x0c087040u: goto P_0c087040;
case 0x0c087042u: goto P_0c087042;
case 0x0c087044u: goto P_0c087044;
case 0x0c087046u: goto P_0c087046;
case 0x0c087048u: goto P_0c087048;
case 0x0c08704au: goto P_0c08704a;
case 0x0c08704cu: goto P_0c08704c;
case 0x0c08704eu: goto P_0c08704e;
case 0x0c087050u: goto P_0c087050;
case 0x0c087052u: goto P_0c087052;
case 0x0c087054u: goto P_0c087054;
case 0x0c087056u: goto P_0c087056;
case 0x0c087058u: goto P_0c087058;
case 0x0c08705au: goto P_0c08705a;
case 0x0c08705cu: goto P_0c08705c;
case 0x0c08705eu: goto P_0c08705e;
case 0x0c087060u: goto P_0c087060;
case 0x0c087062u: goto P_0c087062;
case 0x0c087064u: goto P_0c087064;
case 0x0c087066u: goto P_0c087066;
case 0x0c087068u: goto P_0c087068;
case 0x0c08706au: goto P_0c08706a;
case 0x0c08706cu: goto P_0c08706c;
case 0x0c08706eu: goto P_0c08706e;
case 0x0c087070u: goto P_0c087070;
case 0x0c087072u: goto P_0c087072;
case 0x0c087074u: goto P_0c087074;
case 0x0c087076u: goto P_0c087076;
case 0x0c087078u: goto P_0c087078;
case 0x0c08707au: goto P_0c08707a;
case 0x0c0871eeu: goto P_0c0871ee;
case 0x0c0871f0u: goto P_0c0871f0;
case 0x0c0871f2u: goto P_0c0871f2;
case 0x0c0871f4u: goto P_0c0871f4;
case 0x0c0871f6u: goto P_0c0871f6;
case 0x0c0871f8u: goto P_0c0871f8;
case 0x0c0871fau: goto P_0c0871fa;
case 0x0c0871fcu: goto P_0c0871fc;
case 0x0c0871feu: goto P_0c0871fe;
case 0x0c087200u: goto P_0c087200;
case 0x0c087202u: goto P_0c087202;
case 0x0c087204u: goto P_0c087204;
case 0x0c087206u: goto P_0c087206;
case 0x0c087208u: goto P_0c087208;
case 0x0c08720au: goto P_0c08720a;
case 0x0c08720cu: goto P_0c08720c;
case 0x0c08720eu: goto P_0c08720e;
case 0x0c087210u: goto P_0c087210;
case 0x0c087212u: goto P_0c087212;
case 0x0c087214u: goto P_0c087214;
case 0x0c087216u: goto P_0c087216;
case 0x0c087218u: goto P_0c087218;
case 0x0c08721au: goto P_0c08721a;
case 0x0c08721cu: goto P_0c08721c;
case 0x0c08721eu: goto P_0c08721e;
case 0x0c087220u: goto P_0c087220;
case 0x0c087222u: goto P_0c087222;
case 0x0c087224u: goto P_0c087224;
case 0x0c087226u: goto P_0c087226;
case 0x0c087228u: goto P_0c087228;
case 0x0c08722au: goto P_0c08722a;
case 0x0c08722cu: goto P_0c08722c;
case 0x0c08722eu: goto P_0c08722e;
case 0x0c087230u: goto P_0c087230;
case 0x0c087232u: goto P_0c087232;
case 0x0c087234u: goto P_0c087234;
case 0x0c087236u: goto P_0c087236;
case 0x0c087238u: goto P_0c087238;
case 0x0c08723au: goto P_0c08723a;
case 0x0c08723cu: goto P_0c08723c;
case 0x0c08723eu: goto P_0c08723e;
case 0x0c087240u: goto P_0c087240;
case 0x0c087242u: goto P_0c087242;
case 0x0c087244u: goto P_0c087244;
case 0x0c087246u: goto P_0c087246;
case 0x0c087248u: goto P_0c087248;
case 0x0c08724au: goto P_0c08724a;
case 0x0c08724cu: goto P_0c08724c;
case 0x0c08724eu: goto P_0c08724e;
case 0x0c087250u: goto P_0c087250;
case 0x0c087252u: goto P_0c087252;
case 0x0c087254u: goto P_0c087254;
case 0x0c087256u: goto P_0c087256;
case 0x0c087258u: goto P_0c087258;
case 0x0c08725au: goto P_0c08725a;
case 0x0c08725cu: goto P_0c08725c;
case 0x0c08725eu: goto P_0c08725e;
case 0x0c087260u: goto P_0c087260;
case 0x0c087262u: goto P_0c087262;
case 0x0c087264u: goto P_0c087264;
case 0x0c087266u: goto P_0c087266;
case 0x0c087268u: goto P_0c087268;
case 0x0c08726au: goto P_0c08726a;
case 0x0c08726cu: goto P_0c08726c;
case 0x0c08726eu: goto P_0c08726e;
case 0x0c087270u: goto P_0c087270;
case 0x0c087272u: goto P_0c087272;
case 0x0c087274u: goto P_0c087274;
case 0x0c087276u: goto P_0c087276;
case 0x0c087278u: goto P_0c087278;
case 0x0c08727au: goto P_0c08727a;
case 0x0c08727cu: goto P_0c08727c;
case 0x0c0872b4u: goto P_0c0872b4;
case 0x0c0872b6u: goto P_0c0872b6;
case 0x0c0872b8u: goto P_0c0872b8;
case 0x0c0872bau: goto P_0c0872ba;
case 0x0c0872bcu: goto P_0c0872bc;
case 0x0c0872beu: goto P_0c0872be;
case 0x0c0872c0u: goto P_0c0872c0;
case 0x0c0872c2u: goto P_0c0872c2;
case 0x0c0872c4u: goto P_0c0872c4;
case 0x0c0872c6u: goto P_0c0872c6;
case 0x0c0872c8u: goto P_0c0872c8;
case 0x0c0872cau: goto P_0c0872ca;
case 0x0c0872ccu: goto P_0c0872cc;
case 0x0c0872ceu: goto P_0c0872ce;
case 0x0c0872d0u: goto P_0c0872d0;
case 0x0c0872d2u: goto P_0c0872d2;
case 0x0c0872d4u: goto P_0c0872d4;
case 0x0c0872d6u: goto P_0c0872d6;
case 0x0c0872d8u: goto P_0c0872d8;
case 0x0c0872dau: goto P_0c0872da;
case 0x0c0872dcu: goto P_0c0872dc;
case 0x0c0872deu: goto P_0c0872de;
case 0x0c0872e0u: goto P_0c0872e0;
case 0x0c0872e2u: goto P_0c0872e2;
case 0x0c0872e4u: goto P_0c0872e4;
case 0x0c0872e6u: goto P_0c0872e6;
case 0x0c0872e8u: goto P_0c0872e8;
case 0x0c0872eau: goto P_0c0872ea;
case 0x0c0872ecu: goto P_0c0872ec;
case 0x0c0872eeu: goto P_0c0872ee;
case 0x0c0872f0u: goto P_0c0872f0;
case 0x0c0872f2u: goto P_0c0872f2;
case 0x0c0872f4u: goto P_0c0872f4;
case 0x0c0872f6u: goto P_0c0872f6;
case 0x0c0872f8u: goto P_0c0872f8;
case 0x0c0872fau: goto P_0c0872fa;
case 0x0c0872fcu: goto P_0c0872fc;
case 0x0c0872feu: goto P_0c0872fe;
case 0x0c087300u: goto P_0c087300;
case 0x0c087302u: goto P_0c087302;
case 0x0c087304u: goto P_0c087304;
case 0x0c087306u: goto P_0c087306;
case 0x0c087308u: goto P_0c087308;
case 0x0c08730au: goto P_0c08730a;
case 0x0c08730cu: goto P_0c08730c;
case 0x0c08730eu: goto P_0c08730e;
case 0x0c087310u: goto P_0c087310;
case 0x0c087312u: goto P_0c087312;
case 0x0c087314u: goto P_0c087314;
case 0x0c087316u: goto P_0c087316;
case 0x0c087318u: goto P_0c087318;
case 0x0c08731au: goto P_0c08731a;
case 0x0c08731cu: goto P_0c08731c;
case 0x0c08731eu: goto P_0c08731e;
case 0x0c087320u: goto P_0c087320;
case 0x0c087322u: goto P_0c087322;
case 0x0c087324u: goto P_0c087324;
case 0x0c087326u: goto P_0c087326;
case 0x0c087328u: goto P_0c087328;
case 0x0c08732au: goto P_0c08732a;
case 0x0c08732cu: goto P_0c08732c;
case 0x0c08732eu: goto P_0c08732e;
case 0x0c087330u: goto P_0c087330;
case 0x0c087332u: goto P_0c087332;
case 0x0c087334u: goto P_0c087334;
case 0x0c087336u: goto P_0c087336;
case 0x0c087338u: goto P_0c087338;
case 0x0c08733au: goto P_0c08733a;
case 0x0c08733cu: goto P_0c08733c;
case 0x0c08733eu: goto P_0c08733e;
case 0x0c087340u: goto P_0c087340;
case 0x0c087342u: goto P_0c087342;
case 0x0c087344u: goto P_0c087344;
case 0x0c087346u: goto P_0c087346;
case 0x0c087348u: goto P_0c087348;
case 0x0c0881dcu: goto P_0c0881dc;
case 0x0c0881deu: goto P_0c0881de;
case 0x0c0881e0u: goto P_0c0881e0;
case 0x0c0881e2u: goto P_0c0881e2;
case 0x0c0881e4u: goto P_0c0881e4;
case 0x0c0881e6u: goto P_0c0881e6;
case 0x0c0881e8u: goto P_0c0881e8;
case 0x0c0881eau: goto P_0c0881ea;
case 0x0c0881ecu: goto P_0c0881ec;
case 0x0c0881eeu: goto P_0c0881ee;
case 0x0c0881f0u: goto P_0c0881f0;
case 0x0c0881f2u: goto P_0c0881f2;
case 0x0c0881f4u: goto P_0c0881f4;
case 0x0c0881f6u: goto P_0c0881f6;
case 0x0c0881f8u: goto P_0c0881f8;
case 0x0c0884d0u: goto P_0c0884d0;
case 0x0c0884d2u: goto P_0c0884d2;
case 0x0c0884d4u: goto P_0c0884d4;
case 0x0c0884d6u: goto P_0c0884d6;
case 0x0c0884d8u: goto P_0c0884d8;
case 0x0c0884dau: goto P_0c0884da;
case 0x0c0884dcu: goto P_0c0884dc;
case 0x0c0884deu: goto P_0c0884de;
case 0x0c0884e0u: goto P_0c0884e0;
case 0x0c0884e2u: goto P_0c0884e2;
case 0x0c0884e4u: goto P_0c0884e4;
case 0x0c0884e6u: goto P_0c0884e6;
case 0x0c0884e8u: goto P_0c0884e8;
case 0x0c0884eau: goto P_0c0884ea;
case 0x0c0884ecu: goto P_0c0884ec;
case 0x0c0884eeu: goto P_0c0884ee;
case 0x0c0884f0u: goto P_0c0884f0;
case 0x0c0884f2u: goto P_0c0884f2;
case 0x0c0884f4u: goto P_0c0884f4;
case 0x0c0884f6u: goto P_0c0884f6;
case 0x0c0884f8u: goto P_0c0884f8;
case 0x0c0884fau: goto P_0c0884fa;
case 0x0c0884fcu: goto P_0c0884fc;
case 0x0c0884feu: goto P_0c0884fe;
case 0x0c088500u: goto P_0c088500;
case 0x0c088502u: goto P_0c088502;
case 0x0c088504u: goto P_0c088504;
case 0x0c088506u: goto P_0c088506;
case 0x0c088508u: goto P_0c088508;
case 0x0c08850au: goto P_0c08850a;
case 0x0c08850cu: goto P_0c08850c;
case 0x0c08850eu: goto P_0c08850e;
case 0x0c088510u: goto P_0c088510;
case 0x0c088512u: goto P_0c088512;
case 0x0c088514u: goto P_0c088514;
case 0x0c088516u: goto P_0c088516;
case 0x0c088518u: goto P_0c088518;
case 0x0c08851au: goto P_0c08851a;
case 0x0c08851cu: goto P_0c08851c;
case 0x0c08851eu: goto P_0c08851e;
case 0x0c088520u: goto P_0c088520;
case 0x0c088522u: goto P_0c088522;
case 0x0c088524u: goto P_0c088524;
case 0x0c088526u: goto P_0c088526;
case 0x0c088528u: goto P_0c088528;
case 0x0c08852au: goto P_0c08852a;
case 0x0c08852cu: goto P_0c08852c;
case 0x0c08852eu: goto P_0c08852e;
case 0x0c088530u: goto P_0c088530;
case 0x0c088532u: goto P_0c088532;
case 0x0c088534u: goto P_0c088534;
case 0x0c088536u: goto P_0c088536;
case 0x0c088538u: goto P_0c088538;
case 0x0c08853au: goto P_0c08853a;
case 0x0c08853cu: goto P_0c08853c;
case 0x0c08853eu: goto P_0c08853e;
case 0x0c088540u: goto P_0c088540;
case 0x0c088542u: goto P_0c088542;
case 0x0c088544u: goto P_0c088544;
case 0x0c088546u: goto P_0c088546;
case 0x0c088548u: goto P_0c088548;
case 0x0c08854au: goto P_0c08854a;
case 0x0c08854cu: goto P_0c08854c;
case 0x0c08854eu: goto P_0c08854e;
case 0x0c088550u: goto P_0c088550;
case 0x0c088552u: goto P_0c088552;
case 0x0c088554u: goto P_0c088554;
case 0x0c088556u: goto P_0c088556;
case 0x0c088558u: goto P_0c088558;
case 0x0c08855au: goto P_0c08855a;
case 0x0c08855cu: goto P_0c08855c;
case 0x0c08855eu: goto P_0c08855e;
case 0x0c088560u: goto P_0c088560;
case 0x0c088562u: goto P_0c088562;
case 0x0c088564u: goto P_0c088564;
case 0x0c088566u: goto P_0c088566;
case 0x0c088568u: goto P_0c088568;
case 0x0c08856au: goto P_0c08856a;
case 0x0c08856cu: goto P_0c08856c;
case 0x0c08856eu: goto P_0c08856e;
case 0x0c088570u: goto P_0c088570;
case 0x0c088572u: goto P_0c088572;
case 0x0c088574u: goto P_0c088574;
case 0x0c088576u: goto P_0c088576;
case 0x0c088578u: goto P_0c088578;
case 0x0c08857au: goto P_0c08857a;
case 0x0c08857cu: goto P_0c08857c;
case 0x0c08857eu: goto P_0c08857e;
case 0x0c088580u: goto P_0c088580;
case 0x0c088582u: goto P_0c088582;
case 0x0c088584u: goto P_0c088584;
case 0x0c088586u: goto P_0c088586;
case 0x0c088588u: goto P_0c088588;
case 0x0c08858au: goto P_0c08858a;
case 0x0c08858cu: goto P_0c08858c;
case 0x0c08858eu: goto P_0c08858e;
case 0x0c088590u: goto P_0c088590;
case 0x0c088592u: goto P_0c088592;
case 0x0c088594u: goto P_0c088594;
case 0x0c088596u: goto P_0c088596;
case 0x0c088598u: goto P_0c088598;
case 0x0c08859au: goto P_0c08859a;
case 0x0c08859cu: goto P_0c08859c;
case 0x0c08859eu: goto P_0c08859e;
case 0x0c0885a0u: goto P_0c0885a0;
case 0x0c0885a2u: goto P_0c0885a2;
case 0x0c0885a4u: goto P_0c0885a4;
case 0x0c0885a6u: goto P_0c0885a6;
case 0x0c0885c4u: goto P_0c0885c4;
case 0x0c0885c6u: goto P_0c0885c6;
case 0x0c0885c8u: goto P_0c0885c8;
case 0x0c0885cau: goto P_0c0885ca;
case 0x0c0885ccu: goto P_0c0885cc;
case 0x0c0885ceu: goto P_0c0885ce;
case 0x0c0885d0u: goto P_0c0885d0;
case 0x0c0885d2u: goto P_0c0885d2;
case 0x0c0885d4u: goto P_0c0885d4;
case 0x0c0885d6u: goto P_0c0885d6;
case 0x0c0885d8u: goto P_0c0885d8;
case 0x0c0885dau: goto P_0c0885da;
case 0x0c0885dcu: goto P_0c0885dc;
case 0x0c0885deu: goto P_0c0885de;
case 0x0c0885e0u: goto P_0c0885e0;
case 0x0c0885e2u: goto P_0c0885e2;
case 0x0c0885e4u: goto P_0c0885e4;
case 0x0c0885e6u: goto P_0c0885e6;
case 0x0c0885e8u: goto P_0c0885e8;
case 0x0c0885eau: goto P_0c0885ea;
case 0x0c0885ecu: goto P_0c0885ec;
case 0x0c0885eeu: goto P_0c0885ee;
case 0x0c0885f0u: goto P_0c0885f0;
case 0x0c0885f2u: goto P_0c0885f2;
case 0x0c0885f4u: goto P_0c0885f4;
case 0x0c0885f6u: goto P_0c0885f6;
case 0x0c0885f8u: goto P_0c0885f8;
case 0x0c0885fau: goto P_0c0885fa;
case 0x0c0885fcu: goto P_0c0885fc;
case 0x0c0885feu: goto P_0c0885fe;
case 0x0c088600u: goto P_0c088600;
case 0x0c088602u: goto P_0c088602;
case 0x0c088604u: goto P_0c088604;
case 0x0c088606u: goto P_0c088606;
case 0x0c088608u: goto P_0c088608;
case 0x0c08860au: goto P_0c08860a;
case 0x0c08860cu: goto P_0c08860c;
case 0x0c08860eu: goto P_0c08860e;
case 0x0c088610u: goto P_0c088610;
case 0x0c088612u: goto P_0c088612;
case 0x0c088614u: goto P_0c088614;
case 0x0c088616u: goto P_0c088616;
case 0x0c088618u: goto P_0c088618;
case 0x0c08861au: goto P_0c08861a;
case 0x0c08861cu: goto P_0c08861c;
case 0x0c08861eu: goto P_0c08861e;
case 0x0c088620u: goto P_0c088620;
case 0x0c088622u: goto P_0c088622;
case 0x0c088624u: goto P_0c088624;
case 0x0c088626u: goto P_0c088626;
case 0x0c088628u: goto P_0c088628;
case 0x0c08862au: goto P_0c08862a;
case 0x0c08862cu: goto P_0c08862c;
case 0x0c08862eu: goto P_0c08862e;
case 0x0c088630u: goto P_0c088630;
case 0x0c088632u: goto P_0c088632;
case 0x0c088634u: goto P_0c088634;
case 0x0c088636u: goto P_0c088636;
case 0x0c088638u: goto P_0c088638;
case 0x0c08863au: goto P_0c08863a;
case 0x0c08863cu: goto P_0c08863c;
case 0x0c08863eu: goto P_0c08863e;
case 0x0c088640u: goto P_0c088640;
case 0x0c088642u: goto P_0c088642;
case 0x0c088644u: goto P_0c088644;
case 0x0c088646u: goto P_0c088646;
case 0x0c088648u: goto P_0c088648;
case 0x0c08864au: goto P_0c08864a;
case 0x0c08864cu: goto P_0c08864c;
case 0x0c08864eu: goto P_0c08864e;
case 0x0c088650u: goto P_0c088650;
case 0x0c088652u: goto P_0c088652;
case 0x0c088654u: goto P_0c088654;
case 0x0c088656u: goto P_0c088656;
case 0x0c088658u: goto P_0c088658;
case 0x0c08865au: goto P_0c08865a;
case 0x0c08865cu: goto P_0c08865c;
case 0x0c08865eu: goto P_0c08865e;
case 0x0c088660u: goto P_0c088660;
case 0x0c088662u: goto P_0c088662;
case 0x0c088664u: goto P_0c088664;
case 0x0c088666u: goto P_0c088666;
case 0x0c088668u: goto P_0c088668;
case 0x0c08866au: goto P_0c08866a;
case 0x0c08866cu: goto P_0c08866c;
case 0x0c08866eu: goto P_0c08866e;
case 0x0c088670u: goto P_0c088670;
case 0x0c088672u: goto P_0c088672;
case 0x0c088674u: goto P_0c088674;
case 0x0c088676u: goto P_0c088676;
case 0x0c088678u: goto P_0c088678;
case 0x0c08867au: goto P_0c08867a;
case 0x0c08867cu: goto P_0c08867c;
case 0x0c08867eu: goto P_0c08867e;
case 0x0c088680u: goto P_0c088680;
case 0x0c088682u: goto P_0c088682;
case 0x0c088684u: goto P_0c088684;
case 0x0c088686u: goto P_0c088686;
case 0x0c088688u: goto P_0c088688;
case 0x0c08868au: goto P_0c08868a;
case 0x0c08868cu: goto P_0c08868c;
case 0x0c08868eu: goto P_0c08868e;
case 0x0c088690u: goto P_0c088690;
case 0x0c088692u: goto P_0c088692;
case 0x0c088694u: goto P_0c088694;
case 0x0c088696u: goto P_0c088696;
case 0x0c088698u: goto P_0c088698;
case 0x0c08869au: goto P_0c08869a;
case 0x0c08869cu: goto P_0c08869c;
case 0x0c08869eu: goto P_0c08869e;
case 0x0c0886a0u: goto P_0c0886a0;
case 0x0c0886a2u: goto P_0c0886a2;
case 0x0c0886a4u: goto P_0c0886a4;
case 0x0c0886a6u: goto P_0c0886a6;
case 0x0c0886a8u: goto P_0c0886a8;
case 0x0c0886aau: goto P_0c0886aa;
case 0x0c0886acu: goto P_0c0886ac;
case 0x0c0886aeu: goto P_0c0886ae;
case 0x0c0886b0u: goto P_0c0886b0;
case 0x0c0886b2u: goto P_0c0886b2;
case 0x0c0886b4u: goto P_0c0886b4;
case 0x0c0886b6u: goto P_0c0886b6;
case 0x0c0886b8u: goto P_0c0886b8;
case 0x0c0886bau: goto P_0c0886ba;
case 0x0c0886bcu: goto P_0c0886bc;
case 0x0c0886beu: goto P_0c0886be;
case 0x0c0886c0u: goto P_0c0886c0;
case 0x0c0886c2u: goto P_0c0886c2;
case 0x0c0886c4u: goto P_0c0886c4;
case 0x0c0886c6u: goto P_0c0886c6;
case 0x0c0886c8u: goto P_0c0886c8;
case 0x0c0886cau: goto P_0c0886ca;
case 0x0c0886ccu: goto P_0c0886cc;
case 0x0c0886ceu: goto P_0c0886ce;
case 0x0c0886d0u: goto P_0c0886d0;
case 0x0c0886d2u: goto P_0c0886d2;
case 0x0c0886d4u: goto P_0c0886d4;
case 0x0c0886d6u: goto P_0c0886d6;
case 0x0c0886d8u: goto P_0c0886d8;
case 0x0c0886dau: goto P_0c0886da;
case 0x0c0886dcu: goto P_0c0886dc;
case 0x0c0886deu: goto P_0c0886de;
case 0x0c0886e0u: goto P_0c0886e0;
case 0x0c0886e2u: goto P_0c0886e2;
case 0x0c0886e4u: goto P_0c0886e4;
case 0x0c0886e6u: goto P_0c0886e6;
case 0x0c0886e8u: goto P_0c0886e8;
case 0x0c0886eau: goto P_0c0886ea;
case 0x0c0886ecu: goto P_0c0886ec;
case 0x0c0886eeu: goto P_0c0886ee;
case 0x0c0886f0u: goto P_0c0886f0;
case 0x0c0886f2u: goto P_0c0886f2;
case 0x0c0886f4u: goto P_0c0886f4;
case 0x0c0886f6u: goto P_0c0886f6;
case 0x0c0886f8u: goto P_0c0886f8;
case 0x0c0886fau: goto P_0c0886fa;
case 0x0c0886fcu: goto P_0c0886fc;
case 0x0c08870au: goto P_0c08870a;
case 0x0c08870cu: goto P_0c08870c;
case 0x0c08870eu: goto P_0c08870e;
case 0x0c088710u: goto P_0c088710;
case 0x0c088712u: goto P_0c088712;
case 0x0c088714u: goto P_0c088714;
case 0x0c088716u: goto P_0c088716;
case 0x0c088718u: goto P_0c088718;
case 0x0c08871au: goto P_0c08871a;
case 0x0c08871cu: goto P_0c08871c;
case 0x0c08871eu: goto P_0c08871e;
case 0x0c088720u: goto P_0c088720;
case 0x0c088722u: goto P_0c088722;
case 0x0c088724u: goto P_0c088724;
case 0x0c088726u: goto P_0c088726;
case 0x0c088728u: goto P_0c088728;
case 0x0c08872au: goto P_0c08872a;
case 0x0c08872cu: goto P_0c08872c;
case 0x0c08872eu: goto P_0c08872e;
case 0x0c088730u: goto P_0c088730;
case 0x0c088732u: goto P_0c088732;
case 0x0c088734u: goto P_0c088734;
case 0x0c088736u: goto P_0c088736;
case 0x0c088738u: goto P_0c088738;
case 0x0c08873au: goto P_0c08873a;
case 0x0c08873cu: goto P_0c08873c;
case 0x0c08873eu: goto P_0c08873e;
case 0x0c088740u: goto P_0c088740;
case 0x0c088742u: goto P_0c088742;
case 0x0c088744u: goto P_0c088744;
case 0x0c088746u: goto P_0c088746;
case 0x0c088748u: goto P_0c088748;
case 0x0c08874au: goto P_0c08874a;
case 0x0c08874cu: goto P_0c08874c;
case 0x0c08874eu: goto P_0c08874e;
case 0x0c088750u: goto P_0c088750;
case 0x0c088752u: goto P_0c088752;
case 0x0c088754u: goto P_0c088754;
case 0x0c088756u: goto P_0c088756;
case 0x0c088758u: goto P_0c088758;
case 0x0c08875au: goto P_0c08875a;
case 0x0c08875cu: goto P_0c08875c;
case 0x0c08875eu: goto P_0c08875e;
case 0x0c088760u: goto P_0c088760;
case 0x0c088762u: goto P_0c088762;
case 0x0c088764u: goto P_0c088764;
case 0x0c088766u: goto P_0c088766;
case 0x0c088768u: goto P_0c088768;
case 0x0c08876au: goto P_0c08876a;
case 0x0c08876cu: goto P_0c08876c;
case 0x0c08876eu: goto P_0c08876e;
case 0x0c088770u: goto P_0c088770;
case 0x0c088772u: goto P_0c088772;
case 0x0c088774u: goto P_0c088774;
case 0x0c088776u: goto P_0c088776;
case 0x0c088778u: goto P_0c088778;
case 0x0c08877au: goto P_0c08877a;
case 0x0c08877cu: goto P_0c08877c;
case 0x0c08877eu: goto P_0c08877e;
case 0x0c088780u: goto P_0c088780;
case 0x0c088782u: goto P_0c088782;
case 0x0c088784u: goto P_0c088784;
case 0x0c088786u: goto P_0c088786;
case 0x0c088788u: goto P_0c088788;
case 0x0c08878au: goto P_0c08878a;
case 0x0c08878cu: goto P_0c08878c;
case 0x0c08878eu: goto P_0c08878e;
case 0x0c088790u: goto P_0c088790;
case 0x0c088792u: goto P_0c088792;
case 0x0c088794u: goto P_0c088794;
case 0x0c088796u: goto P_0c088796;
case 0x0c088798u: goto P_0c088798;
case 0x0c08879au: goto P_0c08879a;
case 0x0c08879cu: goto P_0c08879c;
case 0x0c08879eu: goto P_0c08879e;
case 0x0c0887a0u: goto P_0c0887a0;
case 0x0c0887a2u: goto P_0c0887a2;
case 0x0c0887a4u: goto P_0c0887a4;
case 0x0c0887a6u: goto P_0c0887a6;
case 0x0c0887a8u: goto P_0c0887a8;
case 0x0c0887aau: goto P_0c0887aa;
case 0x0c0887acu: goto P_0c0887ac;
case 0x0c0887aeu: goto P_0c0887ae;
case 0x0c0887b0u: goto P_0c0887b0;
case 0x0c0887b2u: goto P_0c0887b2;
case 0x0c0887b4u: goto P_0c0887b4;
case 0x0c0887b6u: goto P_0c0887b6;
case 0x0c0887b8u: goto P_0c0887b8;
case 0x0c0887bau: goto P_0c0887ba;
case 0x0c0887bcu: goto P_0c0887bc;
case 0x0c0887beu: goto P_0c0887be;
case 0x0c0887c0u: goto P_0c0887c0;
case 0x0c0887c2u: goto P_0c0887c2;
case 0x0c0887c4u: goto P_0c0887c4;
case 0x0c0887c6u: goto P_0c0887c6;
case 0x0c0887c8u: goto P_0c0887c8;
case 0x0c0887cau: goto P_0c0887ca;
case 0x0c0887ccu: goto P_0c0887cc;
case 0x0c088b5cu: goto P_0c088b5c;
case 0x0c088b5eu: goto P_0c088b5e;
case 0x0c088b60u: goto P_0c088b60;
case 0x0c088b62u: goto P_0c088b62;
case 0x0c088b64u: goto P_0c088b64;
case 0x0c088b66u: goto P_0c088b66;
case 0x0c088b68u: goto P_0c088b68;
case 0x0c088b6au: goto P_0c088b6a;
case 0x0c088b6cu: goto P_0c088b6c;
case 0x0c088b6eu: goto P_0c088b6e;
case 0x0c088b70u: goto P_0c088b70;
case 0x0c088b72u: goto P_0c088b72;
case 0x0c088b74u: goto P_0c088b74;
case 0x0c088b76u: goto P_0c088b76;
case 0x0c088b78u: goto P_0c088b78;
case 0x0c088b7au: goto P_0c088b7a;
case 0x0c088b7cu: goto P_0c088b7c;
case 0x0c088b7eu: goto P_0c088b7e;
case 0x0c088b80u: goto P_0c088b80;
case 0x0c088b82u: goto P_0c088b82;
case 0x0c088b84u: goto P_0c088b84;
case 0x0c088b86u: goto P_0c088b86;
case 0x0c088b88u: goto P_0c088b88;
case 0x0c088b8au: goto P_0c088b8a;
case 0x0c088b8cu: goto P_0c088b8c;
case 0x0c088b8eu: goto P_0c088b8e;
case 0x0c088b90u: goto P_0c088b90;
case 0x0c088b92u: goto P_0c088b92;
case 0x0c088b94u: goto P_0c088b94;
case 0x0c088b96u: goto P_0c088b96;
case 0x0c088b98u: goto P_0c088b98;
case 0x0c088b9au: goto P_0c088b9a;
case 0x0c088b9cu: goto P_0c088b9c;
case 0x0c088b9eu: goto P_0c088b9e;
case 0x0c088ba0u: goto P_0c088ba0;
case 0x0c088ba2u: goto P_0c088ba2;
case 0x0c088ba4u: goto P_0c088ba4;
case 0x0c088ba6u: goto P_0c088ba6;
case 0x0c088ba8u: goto P_0c088ba8;
case 0x0c088baau: goto P_0c088baa;
case 0x0c088bacu: goto P_0c088bac;
case 0x0c088baeu: goto P_0c088bae;
case 0x0c088bb0u: goto P_0c088bb0;
case 0x0c088bb2u: goto P_0c088bb2;
case 0x0c088bb4u: goto P_0c088bb4;
case 0x0c088bb6u: goto P_0c088bb6;
case 0x0c088bb8u: goto P_0c088bb8;
case 0x0c088bbau: goto P_0c088bba;
case 0x0c088bbcu: goto P_0c088bbc;
case 0x0c088bbeu: goto P_0c088bbe;
case 0x0c088bc0u: goto P_0c088bc0;
case 0x0c088bc2u: goto P_0c088bc2;
case 0x0c088bc4u: goto P_0c088bc4;
case 0x0c088bc6u: goto P_0c088bc6;
case 0x0c088bc8u: goto P_0c088bc8;
case 0x0c088bcau: goto P_0c088bca;
case 0x0c088bccu: goto P_0c088bcc;
case 0x0c088bceu: goto P_0c088bce;
case 0x0c088bd0u: goto P_0c088bd0;
case 0x0c088bd2u: goto P_0c088bd2;
case 0x0c088bd4u: goto P_0c088bd4;
case 0x0c088bd6u: goto P_0c088bd6;
case 0x0c088bd8u: goto P_0c088bd8;
case 0x0c088bdau: goto P_0c088bda;
case 0x0c088bdcu: goto P_0c088bdc;
case 0x0c088bdeu: goto P_0c088bde;
case 0x0c088be0u: goto P_0c088be0;
case 0x0c088be2u: goto P_0c088be2;
case 0x0c088be4u: goto P_0c088be4;
case 0x0c088be6u: goto P_0c088be6;
case 0x0c088be8u: goto P_0c088be8;
case 0x0c088beau: goto P_0c088bea;
case 0x0c088becu: goto P_0c088bec;
case 0x0c088beeu: goto P_0c088bee;
case 0x0c088bf0u: goto P_0c088bf0;
case 0x0c088bf2u: goto P_0c088bf2;
case 0x0c088bf4u: goto P_0c088bf4;
case 0x0c088bf6u: goto P_0c088bf6;
case 0x0c088bf8u: goto P_0c088bf8;
case 0x0c088bfau: goto P_0c088bfa;
case 0x0c088bfcu: goto P_0c088bfc;
case 0x0c088bfeu: goto P_0c088bfe;
case 0x0c088c00u: goto P_0c088c00;
case 0x0c088c02u: goto P_0c088c02;
case 0x0c088c04u: goto P_0c088c04;
case 0x0c088c06u: goto P_0c088c06;
case 0x0c088c08u: goto P_0c088c08;
case 0x0c088c0au: goto P_0c088c0a;
case 0x0c088c0cu: goto P_0c088c0c;
case 0x0c088c0eu: goto P_0c088c0e;
case 0x0c088c10u: goto P_0c088c10;
case 0x0c08a6ecu: goto P_0c08a6ec;
case 0x0c08a6eeu: goto P_0c08a6ee;
case 0x0c08a6f0u: goto P_0c08a6f0;
case 0x0c08a6f2u: goto P_0c08a6f2;
case 0x0c08a6f4u: goto P_0c08a6f4;
case 0x0c08a6f6u: goto P_0c08a6f6;
case 0x0c08a6f8u: goto P_0c08a6f8;
case 0x0c08a6fau: goto P_0c08a6fa;
case 0x0c08a6fcu: goto P_0c08a6fc;
case 0x0c08a6feu: goto P_0c08a6fe;
case 0x0c08a700u: goto P_0c08a700;
case 0x0c08a702u: goto P_0c08a702;
case 0x0c08a704u: goto P_0c08a704;
case 0x0c08a706u: goto P_0c08a706;
case 0x0c08a708u: goto P_0c08a708;
case 0x0c08a70au: goto P_0c08a70a;
case 0x0c08a70cu: goto P_0c08a70c;
case 0x0c08a70eu: goto P_0c08a70e;
case 0x0c08a710u: goto P_0c08a710;
case 0x0c08a712u: goto P_0c08a712;
case 0x0c08a714u: goto P_0c08a714;
case 0x0c08a716u: goto P_0c08a716;
case 0x0c08a718u: goto P_0c08a718;
case 0x0c08a71au: goto P_0c08a71a;
case 0x0c08a71cu: goto P_0c08a71c;
case 0x0c08a71eu: goto P_0c08a71e;
case 0x0c08a720u: goto P_0c08a720;
case 0x0c08a722u: goto P_0c08a722;
case 0x0c08a724u: goto P_0c08a724;
case 0x0c08a726u: goto P_0c08a726;
case 0x0c08a728u: goto P_0c08a728;
case 0x0c08a72au: goto P_0c08a72a;
case 0x0c08a72cu: goto P_0c08a72c;
case 0x0c08a72eu: goto P_0c08a72e;
case 0x0c08a730u: goto P_0c08a730;
case 0x0c08a732u: goto P_0c08a732;
case 0x0c08a734u: goto P_0c08a734;
case 0x0c08a736u: goto P_0c08a736;
case 0x0c08a738u: goto P_0c08a738;
case 0x0c08a73au: goto P_0c08a73a;
case 0x0c08a73cu: goto P_0c08a73c;
case 0x0c08a73eu: goto P_0c08a73e;
case 0x0c08a740u: goto P_0c08a740;
case 0x0c08a742u: goto P_0c08a742;
case 0x0c08a744u: goto P_0c08a744;
case 0x0c08a746u: goto P_0c08a746;
case 0x0c08a748u: goto P_0c08a748;
case 0x0c08a74au: goto P_0c08a74a;
case 0x0c08a74cu: goto P_0c08a74c;
case 0x0c08a74eu: goto P_0c08a74e;
case 0x0c08a750u: goto P_0c08a750;
case 0x0c08a752u: goto P_0c08a752;
case 0x0c08a754u: goto P_0c08a754;
case 0x0c08a756u: goto P_0c08a756;
case 0x0c08a758u: goto P_0c08a758;
case 0x0c08a75au: goto P_0c08a75a;
case 0x0c08a75cu: goto P_0c08a75c;
case 0x0c08a75eu: goto P_0c08a75e;
case 0x0c08a760u: goto P_0c08a760;
case 0x0c08a762u: goto P_0c08a762;
case 0x0c08a764u: goto P_0c08a764;
case 0x0c08a766u: goto P_0c08a766;
case 0x0c08a768u: goto P_0c08a768;
case 0x0c08a76au: goto P_0c08a76a;
case 0x0c08a76cu: goto P_0c08a76c;
case 0x0c08a76eu: goto P_0c08a76e;
case 0x0c08a770u: goto P_0c08a770;
case 0x0c08a772u: goto P_0c08a772;
case 0x0c08a774u: goto P_0c08a774;
case 0x0c08a776u: goto P_0c08a776;
case 0x0c08a778u: goto P_0c08a778;
case 0x0c08a77au: goto P_0c08a77a;
case 0x0c08a77cu: goto P_0c08a77c;
case 0x0c08a77eu: goto P_0c08a77e;
case 0x0c08a780u: goto P_0c08a780;
case 0x0c08a782u: goto P_0c08a782;
case 0x0c08a784u: goto P_0c08a784;
case 0x0c08a786u: goto P_0c08a786;
case 0x0c08a788u: goto P_0c08a788;
case 0x0c08a78au: goto P_0c08a78a;
case 0x0c08a78cu: goto P_0c08a78c;
case 0x0c08a78eu: goto P_0c08a78e;
case 0x0c08a790u: goto P_0c08a790;
case 0x0c08a792u: goto P_0c08a792;
case 0x0c08a794u: goto P_0c08a794;
case 0x0c08a796u: goto P_0c08a796;
case 0x0c08a798u: goto P_0c08a798;
case 0x0c08a79au: goto P_0c08a79a;
case 0x0c08a79cu: goto P_0c08a79c;
case 0x0c08a79eu: goto P_0c08a79e;
case 0x0c08a7a0u: goto P_0c08a7a0;
case 0x0c08a7a2u: goto P_0c08a7a2;
case 0x0c08a7a4u: goto P_0c08a7a4;
case 0x0c08a7a6u: goto P_0c08a7a6;
case 0x0c08a7a8u: goto P_0c08a7a8;
case 0x0c08a7aau: goto P_0c08a7aa;
case 0x0c08a7acu: goto P_0c08a7ac;
case 0x0c08a7aeu: goto P_0c08a7ae;
case 0x0c08a7b0u: goto P_0c08a7b0;
case 0x0c08a7b2u: goto P_0c08a7b2;
case 0x0c08a7b4u: goto P_0c08a7b4;
case 0x0c08a7b6u: goto P_0c08a7b6;
case 0x0c08a7b8u: goto P_0c08a7b8;
case 0x0c08a7bau: goto P_0c08a7ba;
case 0x0c08a7bcu: goto P_0c08a7bc;
case 0x0c08a7beu: goto P_0c08a7be;
case 0x0c08a7c0u: goto P_0c08a7c0;
case 0x0c08a7c2u: goto P_0c08a7c2;
case 0x0c08a7c4u: goto P_0c08a7c4;
case 0x0c08a7c6u: goto P_0c08a7c6;
case 0x0c08a7c8u: goto P_0c08a7c8;
case 0x0c08a7cau: goto P_0c08a7ca;
case 0x0c08a7ccu: goto P_0c08a7cc;
case 0x0c08a7ceu: goto P_0c08a7ce;
case 0x0c08a7deu: goto P_0c08a7de;
case 0x0c08a7e0u: goto P_0c08a7e0;
case 0x0c08a7e2u: goto P_0c08a7e2;
case 0x0c08a7e4u: goto P_0c08a7e4;
case 0x0c08a7e6u: goto P_0c08a7e6;
case 0x0c08a7e8u: goto P_0c08a7e8;
case 0x0c08a7eau: goto P_0c08a7ea;
case 0x0c08a7ecu: goto P_0c08a7ec;
case 0x0c08a7eeu: goto P_0c08a7ee;
case 0x0c08a7f0u: goto P_0c08a7f0;
case 0x0c08a7f2u: goto P_0c08a7f2;
case 0x0c08a7f4u: goto P_0c08a7f4;
case 0x0c08a7f6u: goto P_0c08a7f6;
case 0x0c08a7f8u: goto P_0c08a7f8;
case 0x0c08a7fau: goto P_0c08a7fa;
case 0x0c08a7fcu: goto P_0c08a7fc;
case 0x0c08a7feu: goto P_0c08a7fe;
case 0x0c08a800u: goto P_0c08a800;
case 0x0c08a802u: goto P_0c08a802;
case 0x0c08a804u: goto P_0c08a804;
case 0x0c08a806u: goto P_0c08a806;
case 0x0c08a808u: goto P_0c08a808;
case 0x0c08a80au: goto P_0c08a80a;
case 0x0c08a80cu: goto P_0c08a80c;
case 0x0c08a80eu: goto P_0c08a80e;
case 0x0c08a810u: goto P_0c08a810;
case 0x0c08a812u: goto P_0c08a812;
case 0x0c08a814u: goto P_0c08a814;
case 0x0c08a816u: goto P_0c08a816;
case 0x0c08a818u: goto P_0c08a818;
case 0x0c08a81au: goto P_0c08a81a;
case 0x0c08a81cu: goto P_0c08a81c;
case 0x0c08a81eu: goto P_0c08a81e;
case 0x0c08a820u: goto P_0c08a820;
case 0x0c08a822u: goto P_0c08a822;
case 0x0c08a824u: goto P_0c08a824;
case 0x0c08a826u: goto P_0c08a826;
case 0x0c08a828u: goto P_0c08a828;
case 0x0c08a82au: goto P_0c08a82a;
case 0x0c08a82cu: goto P_0c08a82c;
case 0x0c08a82eu: goto P_0c08a82e;
case 0x0c08a830u: goto P_0c08a830;
case 0x0c08a832u: goto P_0c08a832;
case 0x0c08a834u: goto P_0c08a834;
case 0x0c08a836u: goto P_0c08a836;
case 0x0c08a838u: goto P_0c08a838;
case 0x0c08a83au: goto P_0c08a83a;
case 0x0c08a83cu: goto P_0c08a83c;
case 0x0c08a83eu: goto P_0c08a83e;
case 0x0c08a840u: goto P_0c08a840;
case 0x0c08a842u: goto P_0c08a842;
case 0x0c08a844u: goto P_0c08a844;
case 0x0c08a846u: goto P_0c08a846;
case 0x0c08a848u: goto P_0c08a848;
case 0x0c08a84au: goto P_0c08a84a;
case 0x0c08a84cu: goto P_0c08a84c;
case 0x0c08a84eu: goto P_0c08a84e;
case 0x0c08a850u: goto P_0c08a850;
case 0x0c08a852u: goto P_0c08a852;
case 0x0c08a854u: goto P_0c08a854;
case 0x0c08a856u: goto P_0c08a856;
case 0x0c08a858u: goto P_0c08a858;
case 0x0c08a85au: goto P_0c08a85a;
case 0x0c08a85cu: goto P_0c08a85c;
case 0x0c08a85eu: goto P_0c08a85e;
case 0x0c08a88cu: goto P_0c08a88c;
case 0x0c08a88eu: goto P_0c08a88e;
case 0x0c08a890u: goto P_0c08a890;
case 0x0c08a892u: goto P_0c08a892;
case 0x0c08a894u: goto P_0c08a894;
case 0x0c08a896u: goto P_0c08a896;
case 0x0c08a898u: goto P_0c08a898;
case 0x0c08a89au: goto P_0c08a89a;
case 0x0c08a89cu: goto P_0c08a89c;
case 0x0c08a89eu: goto P_0c08a89e;
case 0x0c08a8a0u: goto P_0c08a8a0;
case 0x0c08a8a2u: goto P_0c08a8a2;
case 0x0c08a8a4u: goto P_0c08a8a4;
case 0x0c08a8a6u: goto P_0c08a8a6;
case 0x0c08a8a8u: goto P_0c08a8a8;
case 0x0c08a8aau: goto P_0c08a8aa;
case 0x0c08a8acu: goto P_0c08a8ac;
case 0x0c08a8aeu: goto P_0c08a8ae;
case 0x0c08a8b0u: goto P_0c08a8b0;
case 0x0c08a8b2u: goto P_0c08a8b2;
case 0x0c08a8b4u: goto P_0c08a8b4;
case 0x0c08a8b6u: goto P_0c08a8b6;
case 0x0c08a8b8u: goto P_0c08a8b8;
case 0x0c08a8bau: goto P_0c08a8ba;
case 0x0c08a8bcu: goto P_0c08a8bc;
case 0x0c08a8beu: goto P_0c08a8be;
case 0x0c08a8c0u: goto P_0c08a8c0;
case 0x0c08e028u: goto P_0c08e028;
case 0x0c08e02au: goto P_0c08e02a;
case 0x0c08e02cu: goto P_0c08e02c;
case 0x0c08e02eu: goto P_0c08e02e;
case 0x0c08e030u: goto P_0c08e030;
case 0x0c08e032u: goto P_0c08e032;
case 0x0c08e034u: goto P_0c08e034;
case 0x0c08e036u: goto P_0c08e036;
case 0x0c08e038u: goto P_0c08e038;
case 0x0c08e03au: goto P_0c08e03a;
case 0x0c08e03cu: goto P_0c08e03c;
case 0x0c08e03eu: goto P_0c08e03e;
case 0x0c08e040u: goto P_0c08e040;
case 0x0c08e042u: goto P_0c08e042;
case 0x0c08e044u: goto P_0c08e044;
case 0x0c08e046u: goto P_0c08e046;
case 0x0c08e048u: goto P_0c08e048;
case 0x0c08e04au: goto P_0c08e04a;
case 0x0c08e04cu: goto P_0c08e04c;
case 0x0c08e04eu: goto P_0c08e04e;
case 0x0c08e050u: goto P_0c08e050;
case 0x0c08e052u: goto P_0c08e052;
case 0x0c08e054u: goto P_0c08e054;
case 0x0c08e056u: goto P_0c08e056;
case 0x0c08e058u: goto P_0c08e058;
case 0x0c08e05au: goto P_0c08e05a;
case 0x0c08e05cu: goto P_0c08e05c;
case 0x0c08e05eu: goto P_0c08e05e;
case 0x0c08e060u: goto P_0c08e060;
case 0x0c08e062u: goto P_0c08e062;
case 0x0c08e064u: goto P_0c08e064;
case 0x0c08e066u: goto P_0c08e066;
case 0x0c08e068u: goto P_0c08e068;
case 0x0c08e06au: goto P_0c08e06a;
case 0x0c08e06cu: goto P_0c08e06c;
case 0x0c08e06eu: goto P_0c08e06e;
case 0x0c08e070u: goto P_0c08e070;
case 0x0c08e072u: goto P_0c08e072;
case 0x0c08e074u: goto P_0c08e074;
case 0x0c08e076u: goto P_0c08e076;
case 0x0c08e078u: goto P_0c08e078;
case 0x0c08e07au: goto P_0c08e07a;
case 0x0c08e07cu: goto P_0c08e07c;
case 0x0c08e07eu: goto P_0c08e07e;
case 0x0c08e080u: goto P_0c08e080;
case 0x0c08e082u: goto P_0c08e082;
case 0x0c08e084u: goto P_0c08e084;
case 0x0c08e086u: goto P_0c08e086;
case 0x0c08e088u: goto P_0c08e088;
case 0x0c08e08au: goto P_0c08e08a;
case 0x0c08e08cu: goto P_0c08e08c;
case 0x0c08e08eu: goto P_0c08e08e;
case 0x0c08e090u: goto P_0c08e090;
case 0x0c08e092u: goto P_0c08e092;
case 0x0c08e094u: goto P_0c08e094;
case 0x0c08e096u: goto P_0c08e096;
case 0x0c08e098u: goto P_0c08e098;
case 0x0c08e09au: goto P_0c08e09a;
case 0x0c08e09cu: goto P_0c08e09c;
case 0x0c08e09eu: goto P_0c08e09e;
case 0x0c08e0a0u: goto P_0c08e0a0;
case 0x0c08e0a2u: goto P_0c08e0a2;
case 0x0c08e0a4u: goto P_0c08e0a4;
case 0x0c08e0a6u: goto P_0c08e0a6;
case 0x0c08e0a8u: goto P_0c08e0a8;
case 0x0c08e0aau: goto P_0c08e0aa;
case 0x0c08e0acu: goto P_0c08e0ac;
case 0x0c08e0aeu: goto P_0c08e0ae;
case 0x0c08e0b0u: goto P_0c08e0b0;
case 0x0c08e0b2u: goto P_0c08e0b2;
case 0x0c08e0b4u: goto P_0c08e0b4;
case 0x0c08e0b6u: goto P_0c08e0b6;
case 0x0c08e0b8u: goto P_0c08e0b8;
case 0x0c08e0bau: goto P_0c08e0ba;
case 0x0c08e0bcu: goto P_0c08e0bc;
case 0x0c08e0beu: goto P_0c08e0be;
case 0x0c08e0c0u: goto P_0c08e0c0;
case 0x0c08e0c2u: goto P_0c08e0c2;
case 0x0c08e0c4u: goto P_0c08e0c4;
case 0x0c08e0c6u: goto P_0c08e0c6;
case 0x0c096864u: goto P_0c096864;
case 0x0c096866u: goto P_0c096866;
case 0x0c096868u: goto P_0c096868;
case 0x0c09686au: goto P_0c09686a;
case 0x0c09686cu: goto P_0c09686c;
case 0x0c09686eu: goto P_0c09686e;
case 0x0c096870u: goto P_0c096870;
case 0x0c096872u: goto P_0c096872;
case 0x0c096874u: goto P_0c096874;
case 0x0c096876u: goto P_0c096876;
case 0x0c096878u: goto P_0c096878;
case 0x0c09687au: goto P_0c09687a;
case 0x0c09687cu: goto P_0c09687c;
case 0x0c09687eu: goto P_0c09687e;
case 0x0c096880u: goto P_0c096880;
case 0x0c096882u: goto P_0c096882;
case 0x0c096884u: goto P_0c096884;
case 0x0c096886u: goto P_0c096886;
case 0x0c096888u: goto P_0c096888;
case 0x0c09688au: goto P_0c09688a;
case 0x0c09688cu: goto P_0c09688c;
case 0x0c09688eu: goto P_0c09688e;
case 0x0c096890u: goto P_0c096890;
case 0x0c096892u: goto P_0c096892;
case 0x0c096894u: goto P_0c096894;
case 0x0c096896u: goto P_0c096896;
case 0x0c096898u: goto P_0c096898;
case 0x0c09689au: goto P_0c09689a;
case 0x0c09689cu: goto P_0c09689c;
case 0x0c09689eu: goto P_0c09689e;
case 0x0c0968a0u: goto P_0c0968a0;
case 0x0c0968a2u: goto P_0c0968a2;
case 0x0c0968a4u: goto P_0c0968a4;
case 0x0c0968a6u: goto P_0c0968a6;
case 0x0c0968a8u: goto P_0c0968a8;
case 0x0c0968aau: goto P_0c0968aa;
case 0x0c0968acu: goto P_0c0968ac;
case 0x0c0968aeu: goto P_0c0968ae;
case 0x0c0a2984u: goto P_0c0a2984;
case 0x0c0a2986u: goto P_0c0a2986;
case 0x0c0a2988u: goto P_0c0a2988;
case 0x0c0a298au: goto P_0c0a298a;
case 0x0c0a298cu: goto P_0c0a298c;
case 0x0c0a298eu: goto P_0c0a298e;
case 0x0c0a2990u: goto P_0c0a2990;
case 0x0c0a2992u: goto P_0c0a2992;
case 0x0c0a2994u: goto P_0c0a2994;
case 0x0c0a2996u: goto P_0c0a2996;
case 0x0c0a2998u: goto P_0c0a2998;
case 0x0c0a299au: goto P_0c0a299a;
case 0x0c0a299cu: goto P_0c0a299c;
case 0x0c0a299eu: goto P_0c0a299e;
case 0x0c0a29a0u: goto P_0c0a29a0;
case 0x0c0a29a2u: goto P_0c0a29a2;
case 0x0c0a29a4u: goto P_0c0a29a4;
case 0x0c0a29a6u: goto P_0c0a29a6;
case 0x0c0a29a8u: goto P_0c0a29a8;
case 0x0c0a29aau: goto P_0c0a29aa;
case 0x0c0a29acu: goto P_0c0a29ac;
case 0x0c0a29aeu: goto P_0c0a29ae;
case 0x0c0a29b0u: goto P_0c0a29b0;
case 0x0c0a29b2u: goto P_0c0a29b2;
case 0x0c0a29b4u: goto P_0c0a29b4;
case 0x0c0a29b6u: goto P_0c0a29b6;
case 0x0c0a29b8u: goto P_0c0a29b8;
case 0x0c0a29bau: goto P_0c0a29ba;
case 0x0c0a29bcu: goto P_0c0a29bc;
case 0x0c0a29beu: goto P_0c0a29be;
case 0x0c0a29c0u: goto P_0c0a29c0;
case 0x0c0a29c2u: goto P_0c0a29c2;
case 0x0c0a29c4u: goto P_0c0a29c4;
case 0x0c0a29c6u: goto P_0c0a29c6;
case 0x0c0a29c8u: goto P_0c0a29c8;
case 0x0c0a29cau: goto P_0c0a29ca;
case 0x0c0a29ccu: goto P_0c0a29cc;
case 0x0c0a29ceu: goto P_0c0a29ce;
case 0x0c0a29d0u: goto P_0c0a29d0;
case 0x0c0a29d2u: goto P_0c0a29d2;
case 0x0c0a29d4u: goto P_0c0a29d4;
case 0x0c0a29d6u: goto P_0c0a29d6;
case 0x0c0a29d8u: goto P_0c0a29d8;
case 0x0c0a29dau: goto P_0c0a29da;
case 0x0c0a29dcu: goto P_0c0a29dc;
case 0x0c0a29deu: goto P_0c0a29de;
case 0x0c0a29e0u: goto P_0c0a29e0;
case 0x0c0a29e2u: goto P_0c0a29e2;
case 0x0c0a29e4u: goto P_0c0a29e4;
case 0x0c0a29e6u: goto P_0c0a29e6;
case 0x0c0a29e8u: goto P_0c0a29e8;
case 0x0c0a29eau: goto P_0c0a29ea;
case 0x0c0a29ecu: goto P_0c0a29ec;
case 0x0c0a29eeu: goto P_0c0a29ee;
case 0x0c0a29f0u: goto P_0c0a29f0;
case 0x0c0a29f2u: goto P_0c0a29f2;
case 0x0c0a29f4u: goto P_0c0a29f4;
case 0x0c0a29f6u: goto P_0c0a29f6;
case 0x0c0a29f8u: goto P_0c0a29f8;
case 0x0c0a29fau: goto P_0c0a29fa;
case 0x0c0a29fcu: goto P_0c0a29fc;
case 0x0c0a29feu: goto P_0c0a29fe;
case 0x0c0a2a00u: goto P_0c0a2a00;
case 0x0c0a2a02u: goto P_0c0a2a02;
case 0x0c0a2a04u: goto P_0c0a2a04;
case 0x0c0a2a06u: goto P_0c0a2a06;
case 0x0c0a2a08u: goto P_0c0a2a08;
case 0x0c0a2a0au: goto P_0c0a2a0a;
case 0x0c0a2a0cu: goto P_0c0a2a0c;
case 0x0c0a2a0eu: goto P_0c0a2a0e;
case 0x0c0a2a10u: goto P_0c0a2a10;
case 0x0c0a2a12u: goto P_0c0a2a12;
case 0x0c0a2a14u: goto P_0c0a2a14;
case 0x0c0a2a16u: goto P_0c0a2a16;
case 0x0c0a2a18u: goto P_0c0a2a18;
case 0x0c0a2a1au: goto P_0c0a2a1a;
case 0x0c0a2a1cu: goto P_0c0a2a1c;
case 0x0c0a2a1eu: goto P_0c0a2a1e;
case 0x0c0a2a20u: goto P_0c0a2a20;
case 0x0c0a2a22u: goto P_0c0a2a22;
case 0x0c0a2a24u: goto P_0c0a2a24;
case 0x0c0a2a26u: goto P_0c0a2a26;
case 0x0c0a2a28u: goto P_0c0a2a28;
case 0x0c0a2a2au: goto P_0c0a2a2a;
case 0x0c0a2a2cu: goto P_0c0a2a2c;
case 0x0c0a2a2eu: goto P_0c0a2a2e;
case 0x0c0a2a30u: goto P_0c0a2a30;
case 0x0c0a2a32u: goto P_0c0a2a32;
case 0x0c0a2a34u: goto P_0c0a2a34;
case 0x0c0a2a36u: goto P_0c0a2a36;
case 0x0c0a2a38u: goto P_0c0a2a38;
case 0x0c0a2a3au: goto P_0c0a2a3a;
case 0x0c0a2a3cu: goto P_0c0a2a3c;
case 0x0c0a2a3eu: goto P_0c0a2a3e;
case 0x0c0a2a40u: goto P_0c0a2a40;
case 0x0c0a2a42u: goto P_0c0a2a42;
case 0x0c0a2a44u: goto P_0c0a2a44;
case 0x0c0a2a46u: goto P_0c0a2a46;
case 0x0c0a2a48u: goto P_0c0a2a48;
case 0x0c0a2a4au: goto P_0c0a2a4a;
case 0x0c0a2a4cu: goto P_0c0a2a4c;
case 0x0c0a2a4eu: goto P_0c0a2a4e;
case 0x0c0a2a50u: goto P_0c0a2a50;
case 0x0c0a2a52u: goto P_0c0a2a52;
case 0x0c0a2a54u: goto P_0c0a2a54;
case 0x0c0a2a56u: goto P_0c0a2a56;
case 0x0c0a2a58u: goto P_0c0a2a58;
case 0x0c0a2a5au: goto P_0c0a2a5a;
case 0x0c0a2a5cu: goto P_0c0a2a5c;
case 0x0c0a2a5eu: goto P_0c0a2a5e;
case 0x0c0a2a60u: goto P_0c0a2a60;
case 0x0c0a2a62u: goto P_0c0a2a62;
case 0x0c0a2a64u: goto P_0c0a2a64;
case 0x0c0a2a66u: goto P_0c0a2a66;
case 0x0c0a2a68u: goto P_0c0a2a68;
case 0x0c0a2a6au: goto P_0c0a2a6a;
case 0x0c0a2a6cu: goto P_0c0a2a6c;
case 0x0c0a2a6eu: goto P_0c0a2a6e;
case 0x0c0a2a70u: goto P_0c0a2a70;
case 0x0c0a2a72u: goto P_0c0a2a72;
case 0x0c0a2e86u: goto P_0c0a2e86;
case 0x0c0a2e88u: goto P_0c0a2e88;
case 0x0c0a2e8au: goto P_0c0a2e8a;
case 0x0c0a2e8cu: goto P_0c0a2e8c;
case 0x0c0a2e8eu: goto P_0c0a2e8e;
case 0x0c0a2e90u: goto P_0c0a2e90;
case 0x0c0a2e92u: goto P_0c0a2e92;
case 0x0c0a2e94u: goto P_0c0a2e94;
case 0x0c0a2e96u: goto P_0c0a2e96;
case 0x0c0a2e98u: goto P_0c0a2e98;
case 0x0c0a2e9au: goto P_0c0a2e9a;
case 0x0c0a2e9cu: goto P_0c0a2e9c;
case 0x0c0a2e9eu: goto P_0c0a2e9e;
case 0x0c0a2ea0u: goto P_0c0a2ea0;
case 0x0c0a2ea2u: goto P_0c0a2ea2;
case 0x0c0a2ea4u: goto P_0c0a2ea4;
case 0x0c0a2ea6u: goto P_0c0a2ea6;
case 0x0c0a2ea8u: goto P_0c0a2ea8;
case 0x0c0a2eaau: goto P_0c0a2eaa;
case 0x0c0a2eacu: goto P_0c0a2eac;
case 0x0c0a2eaeu: goto P_0c0a2eae;
case 0x0c0a2eb0u: goto P_0c0a2eb0;
case 0x0c0a2eb2u: goto P_0c0a2eb2;
case 0x0c0a2eb4u: goto P_0c0a2eb4;
case 0x0c0a2eb6u: goto P_0c0a2eb6;
case 0x0c0a2eb8u: goto P_0c0a2eb8;
case 0x0c0a2ebau: goto P_0c0a2eba;
case 0x0c0a2ebcu: goto P_0c0a2ebc;
case 0x0c0a2ebeu: goto P_0c0a2ebe;
case 0x0c0a2ec0u: goto P_0c0a2ec0;
case 0x0c0a2ec2u: goto P_0c0a2ec2;
case 0x0c0a2ec4u: goto P_0c0a2ec4;
case 0x0c0a2ec6u: goto P_0c0a2ec6;
case 0x0c0a2ec8u: goto P_0c0a2ec8;
case 0x0c0a2ecau: goto P_0c0a2eca;
case 0x0c0a2eccu: goto P_0c0a2ecc;
case 0x0c0a2eceu: goto P_0c0a2ece;
case 0x0c0a2ed0u: goto P_0c0a2ed0;
case 0x0c0a7f5au: goto P_0c0a7f5a;
case 0x0c0a7f5cu: goto P_0c0a7f5c;
case 0x0c0a7f5eu: goto P_0c0a7f5e;
case 0x0c0a7f60u: goto P_0c0a7f60;
case 0x0c0a7f62u: goto P_0c0a7f62;
case 0x0c0a7f64u: goto P_0c0a7f64;
case 0x0c0a7f66u: goto P_0c0a7f66;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
case 0x0c0a81eeu: goto P_0c0a81ee;
case 0x0c0a81f0u: goto P_0c0a81f0;
case 0x0c0a81f2u: goto P_0c0a81f2;
case 0x0c0a81f4u: goto P_0c0a81f4;
case 0x0c0a81f6u: goto P_0c0a81f6;
case 0x0c0a81f8u: goto P_0c0a81f8;
case 0x0c0a81fau: goto P_0c0a81fa;
case 0x0c0a81fcu: goto P_0c0a81fc;
case 0x0c0a81feu: goto P_0c0a81fe;
case 0x0c0a8200u: goto P_0c0a8200;
case 0x0c0a8202u: goto P_0c0a8202;
case 0x0c0a8204u: goto P_0c0a8204;
case 0x0c0a8206u: goto P_0c0a8206;
case 0x0c0a8208u: goto P_0c0a8208;
case 0x0c0a820au: goto P_0c0a820a;
case 0x0c0a820cu: goto P_0c0a820c;
case 0x0c0a820eu: goto P_0c0a820e;
case 0x0c0a8210u: goto P_0c0a8210;
case 0x0c0a8212u: goto P_0c0a8212;
case 0x0c0a8214u: goto P_0c0a8214;
case 0x0c0a8216u: goto P_0c0a8216;
case 0x0c0a8218u: goto P_0c0a8218;
case 0x0c0a821au: goto P_0c0a821a;
case 0x0c0a821cu: goto P_0c0a821c;
case 0x0c0a821eu: goto P_0c0a821e;
case 0x0c0a8220u: goto P_0c0a8220;
case 0x0c0a8222u: goto P_0c0a8222;
case 0x0c0a8224u: goto P_0c0a8224;
case 0x0c0a8226u: goto P_0c0a8226;
case 0x0c0a8228u: goto P_0c0a8228;
case 0x0c0a822au: goto P_0c0a822a;
case 0x0c0a822cu: goto P_0c0a822c;
case 0x0c0a822eu: goto P_0c0a822e;
case 0x0c0a8230u: goto P_0c0a8230;
case 0x0c0a8232u: goto P_0c0a8232;
case 0x0c0a8234u: goto P_0c0a8234;
case 0x0c0a8236u: goto P_0c0a8236;
case 0x0c0a8238u: goto P_0c0a8238;
case 0x0c0a823au: goto P_0c0a823a;
case 0x0c0a823cu: goto P_0c0a823c;
case 0x0c0a823eu: goto P_0c0a823e;
case 0x0c0a8240u: goto P_0c0a8240;
case 0x0c0a8242u: goto P_0c0a8242;
case 0x0c0a8244u: goto P_0c0a8244;
case 0x0c0a8246u: goto P_0c0a8246;
case 0x0c0a8248u: goto P_0c0a8248;
case 0x0c0a824au: goto P_0c0a824a;
case 0x0c0a824cu: goto P_0c0a824c;
case 0x0c0a824eu: goto P_0c0a824e;
case 0x0c0a8250u: goto P_0c0a8250;
case 0x0c0a8252u: goto P_0c0a8252;
case 0x0c0a8254u: goto P_0c0a8254;
case 0x0c0a8256u: goto P_0c0a8256;
case 0x0c0a8258u: goto P_0c0a8258;
case 0x0c0a825au: goto P_0c0a825a;
case 0x0c0a825cu: goto P_0c0a825c;
case 0x0c0a825eu: goto P_0c0a825e;
case 0x0c0a8260u: goto P_0c0a8260;
case 0x0c0a8262u: goto P_0c0a8262;
case 0x0c0a8264u: goto P_0c0a8264;
case 0x0c0a8266u: goto P_0c0a8266;
case 0x0c0a8268u: goto P_0c0a8268;
case 0x0c0a826au: goto P_0c0a826a;
case 0x0c0a826cu: goto P_0c0a826c;
case 0x0c0a826eu: goto P_0c0a826e;
case 0x0c0a8270u: goto P_0c0a8270;
case 0x0c0a8272u: goto P_0c0a8272;
case 0x0c0a8274u: goto P_0c0a8274;
case 0x0c0a8276u: goto P_0c0a8276;
case 0x0c0a8278u: goto P_0c0a8278;
case 0x0c0a827au: goto P_0c0a827a;
case 0x0c0a827cu: goto P_0c0a827c;
case 0x0c0a827eu: goto P_0c0a827e;
case 0x0c0a8280u: goto P_0c0a8280;
case 0x0c0a8282u: goto P_0c0a8282;
case 0x0c0a8284u: goto P_0c0a8284;
case 0x0c0a8286u: goto P_0c0a8286;
case 0x0c0a8288u: goto P_0c0a8288;
case 0x0c0a828au: goto P_0c0a828a;
case 0x0c0a828cu: goto P_0c0a828c;
case 0x0c0a828eu: goto P_0c0a828e;
case 0x0c0a8290u: goto P_0c0a8290;
case 0x0c0a8292u: goto P_0c0a8292;
case 0x0c0a8294u: goto P_0c0a8294;
case 0x0c0a8296u: goto P_0c0a8296;
case 0x0c0a8298u: goto P_0c0a8298;
case 0x0c0a829au: goto P_0c0a829a;
case 0x0c0c1208u: goto P_0c0c1208;
case 0x0c0c120au: goto P_0c0c120a;
case 0x0c0c120cu: goto P_0c0c120c;
case 0x0c0c120eu: goto P_0c0c120e;
case 0x0c0c1210u: goto P_0c0c1210;
case 0x0c0c1212u: goto P_0c0c1212;
case 0x0c0c1214u: goto P_0c0c1214;
case 0x0c0c1216u: goto P_0c0c1216;
case 0x0c0c1218u: goto P_0c0c1218;
case 0x0c0c121au: goto P_0c0c121a;
case 0x0c0c121cu: goto P_0c0c121c;
case 0x0c0c121eu: goto P_0c0c121e;
case 0x0c0c1220u: goto P_0c0c1220;
case 0x0c0c1222u: goto P_0c0c1222;
case 0x0c0c1224u: goto P_0c0c1224;
case 0x0c0c1226u: goto P_0c0c1226;
case 0x0c0c1228u: goto P_0c0c1228;
case 0x0c0c122au: goto P_0c0c122a;
case 0x0c0c122cu: goto P_0c0c122c;
case 0x0c0c122eu: goto P_0c0c122e;
case 0x0c0c1230u: goto P_0c0c1230;
case 0x0c0c1232u: goto P_0c0c1232;
case 0x0c0c1234u: goto P_0c0c1234;
case 0x0c0c1236u: goto P_0c0c1236;
case 0x0c0c1238u: goto P_0c0c1238;
case 0x0c0c123au: goto P_0c0c123a;
case 0x0c0c123cu: goto P_0c0c123c;
case 0x0c0c123eu: goto P_0c0c123e;
case 0x0c0c1240u: goto P_0c0c1240;
case 0x0c0c1242u: goto P_0c0c1242;
case 0x0c0c1244u: goto P_0c0c1244;
case 0x0c0c1246u: goto P_0c0c1246;
case 0x0c0c1248u: goto P_0c0c1248;
case 0x0c0c124au: goto P_0c0c124a;
case 0x0c0c124cu: goto P_0c0c124c;
case 0x0c0c182eu: goto P_0c0c182e;
case 0x0c0c1830u: goto P_0c0c1830;
case 0x0c0c1832u: goto P_0c0c1832;
case 0x0c0c1834u: goto P_0c0c1834;
case 0x0c0c3a26u: goto P_0c0c3a26;
case 0x0c0c3a28u: goto P_0c0c3a28;
case 0x0c0c3a2au: goto P_0c0c3a2a;
case 0x0c0c3a2cu: goto P_0c0c3a2c;
case 0x0c0c3a2eu: goto P_0c0c3a2e;
case 0x0c0c3a30u: goto P_0c0c3a30;
case 0x0c0c3a32u: goto P_0c0c3a32;
case 0x0c0c3a34u: goto P_0c0c3a34;
case 0x0c0c3a36u: goto P_0c0c3a36;
case 0x0c0c3a38u: goto P_0c0c3a38;
case 0x0c0c3a3au: goto P_0c0c3a3a;
case 0x0c0c3a3cu: goto P_0c0c3a3c;
case 0x0c0c3a3eu: goto P_0c0c3a3e;
case 0x0c0c3a40u: goto P_0c0c3a40;
case 0x0c0c3a42u: goto P_0c0c3a42;
case 0x0c0c3a44u: goto P_0c0c3a44;
case 0x0c0c3a46u: goto P_0c0c3a46;
case 0x0c0c3a48u: goto P_0c0c3a48;
case 0x0c0c3a84u: goto P_0c0c3a84;
case 0x0c0c3a86u: goto P_0c0c3a86;
case 0x0c0c3a88u: goto P_0c0c3a88;
case 0x0c0c3a8au: goto P_0c0c3a8a;
case 0x0c0c3a8cu: goto P_0c0c3a8c;
case 0x0c0c3a8eu: goto P_0c0c3a8e;
case 0x0c0c3a90u: goto P_0c0c3a90;
case 0x0c0c3a92u: goto P_0c0c3a92;
case 0x0c0c3a94u: goto P_0c0c3a94;
case 0x0c0c3a96u: goto P_0c0c3a96;
case 0x0c0c3a98u: goto P_0c0c3a98;
case 0x0c0c3a9au: goto P_0c0c3a9a;
case 0x0c0c3a9cu: goto P_0c0c3a9c;
case 0x0c0c3a9eu: goto P_0c0c3a9e;
case 0x0c0c3aa0u: goto P_0c0c3aa0;
case 0x0c0c3aa2u: goto P_0c0c3aa2;
case 0x0c0c3aa4u: goto P_0c0c3aa4;
case 0x0c0c3aa6u: goto P_0c0c3aa6;
case 0x0c0c3aa8u: goto P_0c0c3aa8;
case 0x0c0c3aaau: goto P_0c0c3aaa;
case 0x0c0c3aacu: goto P_0c0c3aac;
case 0x0c0c3aaeu: goto P_0c0c3aae;
case 0x0c0c3ab0u: goto P_0c0c3ab0;
case 0x0c0c3ab2u: goto P_0c0c3ab2;
case 0x0c0c3ab4u: goto P_0c0c3ab4;
case 0x0c0c3ab6u: goto P_0c0c3ab6;
case 0x0c0c3ab8u: goto P_0c0c3ab8;
case 0x0c0c3abau: goto P_0c0c3aba;
case 0x0c0c3abcu: goto P_0c0c3abc;
case 0x0c0c3abeu: goto P_0c0c3abe;
case 0x0c0c3ac0u: goto P_0c0c3ac0;
case 0x0c0c3ac2u: goto P_0c0c3ac2;
case 0x0c0c3ac4u: goto P_0c0c3ac4;
case 0x0c0c3ac6u: goto P_0c0c3ac6;
case 0x0c0c3ac8u: goto P_0c0c3ac8;
case 0x0c0c3acau: goto P_0c0c3aca;
case 0x0c0c3accu: goto P_0c0c3acc;
case 0x0c0c3aceu: goto P_0c0c3ace;
case 0x0c0c3ad0u: goto P_0c0c3ad0;
case 0x0c0c3ad2u: goto P_0c0c3ad2;
case 0x0c0c3ad4u: goto P_0c0c3ad4;
case 0x0c0c3ad6u: goto P_0c0c3ad6;
case 0x0c0c3ad8u: goto P_0c0c3ad8;
case 0x0c0c3adau: goto P_0c0c3ada;
case 0x0c0c3adcu: goto P_0c0c3adc;
case 0x0c0c3adeu: goto P_0c0c3ade;
case 0x0c0c3ae0u: goto P_0c0c3ae0;
case 0x0c0c3ae2u: goto P_0c0c3ae2;
case 0x0c0c3ae4u: goto P_0c0c3ae4;
case 0x0c0c3ae6u: goto P_0c0c3ae6;
case 0x0c0c3ae8u: goto P_0c0c3ae8;
case 0x0c0c3aeau: goto P_0c0c3aea;
case 0x0c0c3aecu: goto P_0c0c3aec;
case 0x0c0c3aeeu: goto P_0c0c3aee;
case 0x0c0c3af0u: goto P_0c0c3af0;
case 0x0c0c3af2u: goto P_0c0c3af2;
case 0x0c0c3af4u: goto P_0c0c3af4;
case 0x0c0c3af6u: goto P_0c0c3af6;
case 0x0c0c3af8u: goto P_0c0c3af8;
case 0x0c0c3afau: goto P_0c0c3afa;
case 0x0c0c3afcu: goto P_0c0c3afc;
case 0x0c0c3afeu: goto P_0c0c3afe;
case 0x0c0c3b00u: goto P_0c0c3b00;
case 0x0c0c3b02u: goto P_0c0c3b02;
case 0x0c0c3b04u: goto P_0c0c3b04;
case 0x0c0c3b06u: goto P_0c0c3b06;
case 0x0c0c3b08u: goto P_0c0c3b08;
case 0x0c0c3b0au: goto P_0c0c3b0a;
case 0x0c0c3b0cu: goto P_0c0c3b0c;
case 0x0c0c3b0eu: goto P_0c0c3b0e;
case 0x0c0c3b10u: goto P_0c0c3b10;
case 0x0c0c3b12u: goto P_0c0c3b12;
case 0x0c0c3b14u: goto P_0c0c3b14;
case 0x0c0c3b16u: goto P_0c0c3b16;
case 0x0c0c3b18u: goto P_0c0c3b18;
case 0x0c0c3b1au: goto P_0c0c3b1a;
case 0x0c0c5c94u: goto P_0c0c5c94;
case 0x0c0c5c96u: goto P_0c0c5c96;
case 0x0c0c5c98u: goto P_0c0c5c98;
case 0x0c0c5c9au: goto P_0c0c5c9a;
case 0x0c0c5c9cu: goto P_0c0c5c9c;
case 0x0c0c5c9eu: goto P_0c0c5c9e;
case 0x0c0c5ca0u: goto P_0c0c5ca0;
case 0x0c0c5ca2u: goto P_0c0c5ca2;
case 0x0c0c5ca4u: goto P_0c0c5ca4;
case 0x0c0c5ca6u: goto P_0c0c5ca6;
case 0x0c0c5ca8u: goto P_0c0c5ca8;
case 0x0c0c5caau: goto P_0c0c5caa;
case 0x0c0c5cacu: goto P_0c0c5cac;
case 0x0c0c5caeu: goto P_0c0c5cae;
case 0x0c0c5cb0u: goto P_0c0c5cb0;
case 0x0c0c5cf4u: goto P_0c0c5cf4;
case 0x0c0c5cf6u: goto P_0c0c5cf6;
case 0x0c0c5cf8u: goto P_0c0c5cf8;
case 0x0c0c5cfau: goto P_0c0c5cfa;
case 0x0c0c5cfcu: goto P_0c0c5cfc;
case 0x0c0c5cfeu: goto P_0c0c5cfe;
case 0x0c0c5d00u: goto P_0c0c5d00;
case 0x0c0c5d02u: goto P_0c0c5d02;
case 0x0c0c5d04u: goto P_0c0c5d04;
case 0x0c0c5d06u: goto P_0c0c5d06;
case 0x0c0c5d08u: goto P_0c0c5d08;
case 0x0c0c5d0au: goto P_0c0c5d0a;
case 0x0c0c5d0cu: goto P_0c0c5d0c;
case 0x0c0c5d0eu: goto P_0c0c5d0e;
case 0x0c0c5d10u: goto P_0c0c5d10;
case 0x0c0c5d12u: goto P_0c0c5d12;
case 0x0c0c5d14u: goto P_0c0c5d14;
case 0x0c0c5d16u: goto P_0c0c5d16;
case 0x0c0c5d18u: goto P_0c0c5d18;
case 0x0c0c5d1au: goto P_0c0c5d1a;
case 0x0c0c5d1cu: goto P_0c0c5d1c;
case 0x0c0c5d1eu: goto P_0c0c5d1e;
case 0x0c0c5d20u: goto P_0c0c5d20;
case 0x0c0c5d22u: goto P_0c0c5d22;
case 0x0c0c5d24u: goto P_0c0c5d24;
case 0x0c0c5d26u: goto P_0c0c5d26;
case 0x0c0c5d28u: goto P_0c0c5d28;
case 0x0c0c5d2au: goto P_0c0c5d2a;
case 0x0c0c5d2cu: goto P_0c0c5d2c;
case 0x0c0c5d2eu: goto P_0c0c5d2e;
case 0x0c0c5d30u: goto P_0c0c5d30;
case 0x0c0c5d32u: goto P_0c0c5d32;
case 0x0c0c5d34u: goto P_0c0c5d34;
case 0x0c0c5d36u: goto P_0c0c5d36;
case 0x0c0c5d38u: goto P_0c0c5d38;
case 0x0c0c5d3au: goto P_0c0c5d3a;
case 0x0c0c5d3cu: goto P_0c0c5d3c;
case 0x0c0c5d3eu: goto P_0c0c5d3e;
case 0x0c0c5d40u: goto P_0c0c5d40;
case 0x0c0c5d42u: goto P_0c0c5d42;
case 0x0c0c5d44u: goto P_0c0c5d44;
case 0x0c0c5d46u: goto P_0c0c5d46;
case 0x0c0c5d48u: goto P_0c0c5d48;
case 0x0c0c5d4au: goto P_0c0c5d4a;
case 0x0c0c5d4cu: goto P_0c0c5d4c;
case 0x0c0c5d4eu: goto P_0c0c5d4e;
case 0x0c0c5d50u: goto P_0c0c5d50;
case 0x0c0c5d52u: goto P_0c0c5d52;
case 0x0c0c5d54u: goto P_0c0c5d54;
case 0x0c0c5d56u: goto P_0c0c5d56;
case 0x0c0c5d58u: goto P_0c0c5d58;
case 0x0c0c5d5au: goto P_0c0c5d5a;
case 0x0c0c5d5cu: goto P_0c0c5d5c;
case 0x0c0c5d5eu: goto P_0c0c5d5e;
case 0x0c0c5d60u: goto P_0c0c5d60;
case 0x0c0c5d62u: goto P_0c0c5d62;
case 0x0c0c5d64u: goto P_0c0c5d64;
case 0x0c0c5d66u: goto P_0c0c5d66;
case 0x0c0c5d68u: goto P_0c0c5d68;
case 0x0c0c5d6au: goto P_0c0c5d6a;
case 0x0c0c5d6cu: goto P_0c0c5d6c;
case 0x0c0c5d6eu: goto P_0c0c5d6e;
case 0x0c0c5d70u: goto P_0c0c5d70;
case 0x0c0c5d72u: goto P_0c0c5d72;
case 0x0c0c5d74u: goto P_0c0c5d74;
case 0x0c0c5d76u: goto P_0c0c5d76;
case 0x0c0c5d78u: goto P_0c0c5d78;
case 0x0c0c5d7au: goto P_0c0c5d7a;
case 0x0c0c5d7cu: goto P_0c0c5d7c;
case 0x0c0c5d7eu: goto P_0c0c5d7e;
case 0x0c0c5d80u: goto P_0c0c5d80;
case 0x0c0c5d82u: goto P_0c0c5d82;
case 0x0c0c5d84u: goto P_0c0c5d84;
case 0x0c0c601cu: goto P_0c0c601c;
case 0x0c0c601eu: goto P_0c0c601e;
case 0x0c0c6020u: goto P_0c0c6020;
case 0x0c0c6022u: goto P_0c0c6022;
case 0x0c0c6024u: goto P_0c0c6024;
case 0x0c0c6026u: goto P_0c0c6026;
case 0x0c0c6028u: goto P_0c0c6028;
case 0x0c0c602au: goto P_0c0c602a;
case 0x0c0c602cu: goto P_0c0c602c;
case 0x0c0c602eu: goto P_0c0c602e;
case 0x0c0c6030u: goto P_0c0c6030;
case 0x0c0c6032u: goto P_0c0c6032;
case 0x0c0c6034u: goto P_0c0c6034;
case 0x0c0c6036u: goto P_0c0c6036;
case 0x0c0c6038u: goto P_0c0c6038;
case 0x0c0c603au: goto P_0c0c603a;
case 0x0c0c603cu: goto P_0c0c603c;
case 0x0c0c603eu: goto P_0c0c603e;
case 0x0c0c6040u: goto P_0c0c6040;
case 0x0c0c6042u: goto P_0c0c6042;
case 0x0c0c6044u: goto P_0c0c6044;
case 0x0c0c6046u: goto P_0c0c6046;
case 0x0c0c6048u: goto P_0c0c6048;
case 0x0c0c604au: goto P_0c0c604a;
case 0x0c0c604cu: goto P_0c0c604c;
case 0x0c0c604eu: goto P_0c0c604e;
case 0x0c0c6050u: goto P_0c0c6050;
case 0x0c0c6052u: goto P_0c0c6052;
case 0x0c0c6054u: goto P_0c0c6054;
case 0x0c0c6056u: goto P_0c0c6056;
case 0x0c0c6058u: goto P_0c0c6058;
case 0x0c0c605au: goto P_0c0c605a;
case 0x0c0c605cu: goto P_0c0c605c;
case 0x0c0c605eu: goto P_0c0c605e;
case 0x0c0c6060u: goto P_0c0c6060;
case 0x0c0c6062u: goto P_0c0c6062;
case 0x0c0c6064u: goto P_0c0c6064;
case 0x0c0c6066u: goto P_0c0c6066;
case 0x0c0c6068u: goto P_0c0c6068;
case 0x0c0c606au: goto P_0c0c606a;
case 0x0c0c606cu: goto P_0c0c606c;
case 0x0c0c606eu: goto P_0c0c606e;
case 0x0c0c6070u: goto P_0c0c6070;
case 0x0c0c6072u: goto P_0c0c6072;
case 0x0c0c6074u: goto P_0c0c6074;
case 0x0c0c6076u: goto P_0c0c6076;
case 0x0c0c6078u: goto P_0c0c6078;
case 0x0c0c607au: goto P_0c0c607a;
case 0x0c0c607cu: goto P_0c0c607c;
case 0x0c0c607eu: goto P_0c0c607e;
case 0x0c0c6080u: goto P_0c0c6080;
case 0x0c0c6082u: goto P_0c0c6082;
case 0x0c0c6084u: goto P_0c0c6084;
case 0x0c0c6086u: goto P_0c0c6086;
case 0x0c0c6088u: goto P_0c0c6088;
case 0x0c0c608au: goto P_0c0c608a;
case 0x0c0c608cu: goto P_0c0c608c;
case 0x0c0c608eu: goto P_0c0c608e;
case 0x0c0c6090u: goto P_0c0c6090;
case 0x0c0c6092u: goto P_0c0c6092;
case 0x0c0c6094u: goto P_0c0c6094;
case 0x0c0c6096u: goto P_0c0c6096;
case 0x0c0c6098u: goto P_0c0c6098;
case 0x0c0c609au: goto P_0c0c609a;
case 0x0c0c609cu: goto P_0c0c609c;
case 0x0c0c609eu: goto P_0c0c609e;
case 0x0c0c60a0u: goto P_0c0c60a0;
case 0x0c0c60a2u: goto P_0c0c60a2;
case 0x0c0c60a4u: goto P_0c0c60a4;
case 0x0c0c60a6u: goto P_0c0c60a6;
case 0x0c0c60a8u: goto P_0c0c60a8;
case 0x0c0c60aau: goto P_0c0c60aa;
case 0x0c0c60acu: goto P_0c0c60ac;
case 0x0c0c60aeu: goto P_0c0c60ae;
case 0x0c0c60b0u: goto P_0c0c60b0;
case 0x0c0c60b2u: goto P_0c0c60b2;
case 0x0c0c60b4u: goto P_0c0c60b4;
case 0x0c0c60b6u: goto P_0c0c60b6;
case 0x0c0c60b8u: goto P_0c0c60b8;
case 0x0c0c60bau: goto P_0c0c60ba;
case 0x0c0c60bcu: goto P_0c0c60bc;
case 0x0c0c60beu: goto P_0c0c60be;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c7562u: goto P_0c0c7562;
case 0x0c0c7564u: goto P_0c0c7564;
case 0x0c0c7566u: goto P_0c0c7566;
case 0x0c0c7568u: goto P_0c0c7568;
case 0x0c0c756au: goto P_0c0c756a;
case 0x0c0c756cu: goto P_0c0c756c;
case 0x0c0c756eu: goto P_0c0c756e;
case 0x0c0c7570u: goto P_0c0c7570;
case 0x0c0c7572u: goto P_0c0c7572;
case 0x0c0c7574u: goto P_0c0c7574;
case 0x0c0c7576u: goto P_0c0c7576;
case 0x0c0c7578u: goto P_0c0c7578;
case 0x0c0c757au: goto P_0c0c757a;
case 0x0c0c757cu: goto P_0c0c757c;
case 0x0c0c757eu: goto P_0c0c757e;
case 0x0c0c7580u: goto P_0c0c7580;
case 0x0c0c7582u: goto P_0c0c7582;
case 0x0c0c7584u: goto P_0c0c7584;
case 0x0c0c7586u: goto P_0c0c7586;
case 0x0c0c7588u: goto P_0c0c7588;
case 0x0c0c758au: goto P_0c0c758a;
case 0x0c0c758cu: goto P_0c0c758c;
case 0x0c0c758eu: goto P_0c0c758e;
case 0x0c0c7590u: goto P_0c0c7590;
case 0x0c0c7592u: goto P_0c0c7592;
case 0x0c0c7594u: goto P_0c0c7594;
case 0x0c0c7596u: goto P_0c0c7596;
case 0x0c0c7598u: goto P_0c0c7598;
case 0x0c0c759au: goto P_0c0c759a;
case 0x0c0c759cu: goto P_0c0c759c;
case 0x0c0c759eu: goto P_0c0c759e;
case 0x0c0c75a0u: goto P_0c0c75a0;
case 0x0c0c75a2u: goto P_0c0c75a2;
case 0x0c0c75a4u: goto P_0c0c75a4;
case 0x0c0c75a6u: goto P_0c0c75a6;
case 0x0c0c75a8u: goto P_0c0c75a8;
case 0x0c0c75aau: goto P_0c0c75aa;
case 0x0c0c75acu: goto P_0c0c75ac;
case 0x0c0c75aeu: goto P_0c0c75ae;
case 0x0c0c75b0u: goto P_0c0c75b0;
case 0x0c0c75b2u: goto P_0c0c75b2;
case 0x0c0c75b4u: goto P_0c0c75b4;
case 0x0c0c75b6u: goto P_0c0c75b6;
case 0x0c0c75b8u: goto P_0c0c75b8;
case 0x0c0c75bau: goto P_0c0c75ba;
case 0x0c0c75bcu: goto P_0c0c75bc;
case 0x0c0c75beu: goto P_0c0c75be;
case 0x0c0c75c0u: goto P_0c0c75c0;
case 0x0c0c75c2u: goto P_0c0c75c2;
case 0x0c0c75c4u: goto P_0c0c75c4;
case 0x0c0c75c6u: goto P_0c0c75c6;
case 0x0c0c75c8u: goto P_0c0c75c8;
case 0x0c0c75cau: goto P_0c0c75ca;
case 0x0c0c75ccu: goto P_0c0c75cc;
case 0x0c0c75ceu: goto P_0c0c75ce;
case 0x0c0c75d0u: goto P_0c0c75d0;
case 0x0c0c75d2u: goto P_0c0c75d2;
case 0x0c0c75d4u: goto P_0c0c75d4;
case 0x0c0c75d6u: goto P_0c0c75d6;
case 0x0c0c75d8u: goto P_0c0c75d8;
case 0x0c0c75dau: goto P_0c0c75da;
case 0x0c0c75dcu: goto P_0c0c75dc;
case 0x0c0c75deu: goto P_0c0c75de;
case 0x0c0c75e0u: goto P_0c0c75e0;
case 0x0c0c75e2u: goto P_0c0c75e2;
case 0x0c0c75e4u: goto P_0c0c75e4;
case 0x0c0c75e6u: goto P_0c0c75e6;
case 0x0c0c75e8u: goto P_0c0c75e8;
case 0x0c0c75eau: goto P_0c0c75ea;
case 0x0c0c75ecu: goto P_0c0c75ec;
case 0x0c0c75eeu: goto P_0c0c75ee;
case 0x0c0c75f0u: goto P_0c0c75f0;
case 0x0c0c75f2u: goto P_0c0c75f2;
case 0x0c0c75f4u: goto P_0c0c75f4;
case 0x0c0c75f6u: goto P_0c0c75f6;
case 0x0c0c75f8u: goto P_0c0c75f8;
case 0x0c0c75fau: goto P_0c0c75fa;
case 0x0c0c75fcu: goto P_0c0c75fc;
case 0x0c0c75feu: goto P_0c0c75fe;
case 0x0c0c7600u: goto P_0c0c7600;
case 0x0c0c7602u: goto P_0c0c7602;
case 0x0c0c7604u: goto P_0c0c7604;
case 0x0c0c7606u: goto P_0c0c7606;
case 0x0c0c7608u: goto P_0c0c7608;
case 0x0c0c760au: goto P_0c0c760a;
case 0x0c0c760cu: goto P_0c0c760c;
case 0x0c0c760eu: goto P_0c0c760e;
case 0x0c0c7610u: goto P_0c0c7610;
case 0x0c0c7612u: goto P_0c0c7612;
case 0x0c0c7614u: goto P_0c0c7614;
case 0x0c0c7616u: goto P_0c0c7616;
case 0x0c0c7618u: goto P_0c0c7618;
case 0x0c0c761au: goto P_0c0c761a;
case 0x0c0c761cu: goto P_0c0c761c;
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
case 0x0c0c78e0u: goto P_0c0c78e0;
case 0x0c0c78e2u: goto P_0c0c78e2;
case 0x0c0c78e4u: goto P_0c0c78e4;
case 0x0c0c78e6u: goto P_0c0c78e6;
case 0x0c0c78e8u: goto P_0c0c78e8;
case 0x0c0c78eau: goto P_0c0c78ea;
case 0x0c0c78ecu: goto P_0c0c78ec;
case 0x0c0c78eeu: goto P_0c0c78ee;
case 0x0c0c78f0u: goto P_0c0c78f0;
case 0x0c0c78f2u: goto P_0c0c78f2;
case 0x0c0c78f4u: goto P_0c0c78f4;
case 0x0c0c78f6u: goto P_0c0c78f6;
case 0x0c0c78f8u: goto P_0c0c78f8;
case 0x0c0c78fau: goto P_0c0c78fa;
case 0x0c0c78fcu: goto P_0c0c78fc;
case 0x0c0c78feu: goto P_0c0c78fe;
case 0x0c0c7900u: goto P_0c0c7900;
case 0x0c0c7902u: goto P_0c0c7902;
case 0x0c0c7904u: goto P_0c0c7904;
case 0x0c0c7906u: goto P_0c0c7906;
case 0x0c0c7908u: goto P_0c0c7908;
case 0x0c0c790au: goto P_0c0c790a;
case 0x0c0c790cu: goto P_0c0c790c;
case 0x0c0c790eu: goto P_0c0c790e;
case 0x0c0c7910u: goto P_0c0c7910;
case 0x0c0c7912u: goto P_0c0c7912;
case 0x0c0c7914u: goto P_0c0c7914;
case 0x0c0c7916u: goto P_0c0c7916;
case 0x0c0c7918u: goto P_0c0c7918;
case 0x0c0c791au: goto P_0c0c791a;
case 0x0c0c791cu: goto P_0c0c791c;
case 0x0c0c791eu: goto P_0c0c791e;
case 0x0c0c7920u: goto P_0c0c7920;
case 0x0c0c7922u: goto P_0c0c7922;
case 0x0c0c7924u: goto P_0c0c7924;
case 0x0c0c7926u: goto P_0c0c7926;
case 0x0c0c7928u: goto P_0c0c7928;
case 0x0c0c792au: goto P_0c0c792a;
case 0x0c0c792cu: goto P_0c0c792c;
case 0x0c0c792eu: goto P_0c0c792e;
case 0x0c0c7930u: goto P_0c0c7930;
case 0x0c0c7932u: goto P_0c0c7932;
case 0x0c0c7934u: goto P_0c0c7934;
case 0x0c0c7936u: goto P_0c0c7936;
case 0x0c0c7938u: goto P_0c0c7938;
case 0x0c0c793au: goto P_0c0c793a;
case 0x0c0c793cu: goto P_0c0c793c;
case 0x0c0c793eu: goto P_0c0c793e;
case 0x0c0c7940u: goto P_0c0c7940;
case 0x0c0c7942u: goto P_0c0c7942;
case 0x0c0c7944u: goto P_0c0c7944;
case 0x0c0c7946u: goto P_0c0c7946;
case 0x0c0c7948u: goto P_0c0c7948;
case 0x0c0c794au: goto P_0c0c794a;
case 0x0c0c794cu: goto P_0c0c794c;
case 0x0c0c794eu: goto P_0c0c794e;
case 0x0c0c7950u: goto P_0c0c7950;
case 0x0c0c7952u: goto P_0c0c7952;
case 0x0c0c7954u: goto P_0c0c7954;
case 0x0c0c7956u: goto P_0c0c7956;
case 0x0c0c7958u: goto P_0c0c7958;
case 0x0c0c795au: goto P_0c0c795a;
case 0x0c0c795cu: goto P_0c0c795c;
case 0x0c0c795eu: goto P_0c0c795e;
case 0x0c0c7960u: goto P_0c0c7960;
case 0x0c0c7962u: goto P_0c0c7962;
case 0x0c0c7964u: goto P_0c0c7964;
case 0x0c0c7966u: goto P_0c0c7966;
case 0x0c0c7968u: goto P_0c0c7968;
case 0x0c0c796au: goto P_0c0c796a;
case 0x0c0c796cu: goto P_0c0c796c;
case 0x0c0c796eu: goto P_0c0c796e;
case 0x0c0c7970u: goto P_0c0c7970;
case 0x0c0c7972u: goto P_0c0c7972;
case 0x0c0c7974u: goto P_0c0c7974;
case 0x0c0c7976u: goto P_0c0c7976;
case 0x0c0c7978u: goto P_0c0c7978;
case 0x0c0c797au: goto P_0c0c797a;
case 0x0c0c797cu: goto P_0c0c797c;
case 0x0c0c797eu: goto P_0c0c797e;
case 0x0c0c7980u: goto P_0c0c7980;
case 0x0c0c7982u: goto P_0c0c7982;
case 0x0c0c7984u: goto P_0c0c7984;
case 0x0c0c7986u: goto P_0c0c7986;
case 0x0c0c7988u: goto P_0c0c7988;
case 0x0c0c798au: goto P_0c0c798a;
case 0x0c0c798cu: goto P_0c0c798c;
case 0x0c0c798eu: goto P_0c0c798e;
case 0x0c0c7990u: goto P_0c0c7990;
case 0x0c0c7992u: goto P_0c0c7992;
case 0x0c0c7994u: goto P_0c0c7994;
case 0x0c0c7996u: goto P_0c0c7996;
case 0x0c0c7998u: goto P_0c0c7998;
case 0x0c0c799au: goto P_0c0c799a;
case 0x0c0c799cu: goto P_0c0c799c;
case 0x0c0c799eu: goto P_0c0c799e;
case 0x0c0c79a0u: goto P_0c0c79a0;
case 0x0c0c79a2u: goto P_0c0c79a2;
case 0x0c0c79a4u: goto P_0c0c79a4;
case 0x0c0c79a6u: goto P_0c0c79a6;
case 0x0c0c79a8u: goto P_0c0c79a8;
case 0x0c0c8e7cu: goto P_0c0c8e7c;
case 0x0c0c8e7eu: goto P_0c0c8e7e;
case 0x0c0c8e80u: goto P_0c0c8e80;
case 0x0c0c8e82u: goto P_0c0c8e82;
case 0x0c0c8e84u: goto P_0c0c8e84;
case 0x0c0c8e86u: goto P_0c0c8e86;
case 0x0c0c8e88u: goto P_0c0c8e88;
case 0x0c0c8e8au: goto P_0c0c8e8a;
case 0x0c0c8e8cu: goto P_0c0c8e8c;
case 0x0c0c8e8eu: goto P_0c0c8e8e;
case 0x0c0c8e90u: goto P_0c0c8e90;
case 0x0c0c8e92u: goto P_0c0c8e92;
case 0x0c0c8e94u: goto P_0c0c8e94;
case 0x0c0c8e96u: goto P_0c0c8e96;
case 0x0c0c8e98u: goto P_0c0c8e98;
case 0x0c0c8e9au: goto P_0c0c8e9a;
case 0x0c0c8e9cu: goto P_0c0c8e9c;
case 0x0c0c8e9eu: goto P_0c0c8e9e;
case 0x0c0c8ea0u: goto P_0c0c8ea0;
case 0x0c0c8ea2u: goto P_0c0c8ea2;
case 0x0c0c8ea4u: goto P_0c0c8ea4;
case 0x0c0c8ea6u: goto P_0c0c8ea6;
case 0x0c0c8ea8u: goto P_0c0c8ea8;
case 0x0c0c8eaau: goto P_0c0c8eaa;
case 0x0c0c8eacu: goto P_0c0c8eac;
case 0x0c0c8eaeu: goto P_0c0c8eae;
case 0x0c0c8eb0u: goto P_0c0c8eb0;
case 0x0c0c8eb2u: goto P_0c0c8eb2;
case 0x0c0c8eb4u: goto P_0c0c8eb4;
case 0x0c0c8eb6u: goto P_0c0c8eb6;
case 0x0c0c8eb8u: goto P_0c0c8eb8;
case 0x0c0c8ebau: goto P_0c0c8eba;
case 0x0c0c8ebcu: goto P_0c0c8ebc;
case 0x0c0c8ebeu: goto P_0c0c8ebe;
case 0x0c0c8ec0u: goto P_0c0c8ec0;
case 0x0c0c8ec2u: goto P_0c0c8ec2;
case 0x0c0c8ec4u: goto P_0c0c8ec4;
case 0x0c0c8ec6u: goto P_0c0c8ec6;
case 0x0c0c8ec8u: goto P_0c0c8ec8;
case 0x0c0c8ecau: goto P_0c0c8eca;
case 0x0c0c8eccu: goto P_0c0c8ecc;
case 0x0c0c8eceu: goto P_0c0c8ece;
case 0x0c0c8ed0u: goto P_0c0c8ed0;
case 0x0c0c8ed2u: goto P_0c0c8ed2;
case 0x0c0c8ed4u: goto P_0c0c8ed4;
case 0x0c0c8ed6u: goto P_0c0c8ed6;
case 0x0c0c8ed8u: goto P_0c0c8ed8;
case 0x0c0c8edau: goto P_0c0c8eda;
case 0x0c0c8edcu: goto P_0c0c8edc;
case 0x0c0c8edeu: goto P_0c0c8ede;
case 0x0c0c8ee0u: goto P_0c0c8ee0;
case 0x0c0c8ee2u: goto P_0c0c8ee2;
case 0x0c0c8ee4u: goto P_0c0c8ee4;
case 0x0c0c8ee6u: goto P_0c0c8ee6;
case 0x0c0c8ee8u: goto P_0c0c8ee8;
case 0x0c0c8eeau: goto P_0c0c8eea;
case 0x0c0c8eecu: goto P_0c0c8eec;
case 0x0c0c8eeeu: goto P_0c0c8eee;
case 0x0c0c8ef0u: goto P_0c0c8ef0;
case 0x0c0c8ef2u: goto P_0c0c8ef2;
case 0x0c0c8ef4u: goto P_0c0c8ef4;
case 0x0c0c8ef6u: goto P_0c0c8ef6;
case 0x0c0c8ef8u: goto P_0c0c8ef8;
case 0x0c0c8efau: goto P_0c0c8efa;
case 0x0c0c8efcu: goto P_0c0c8efc;
case 0x0c0c8efeu: goto P_0c0c8efe;
case 0x0c0c8f00u: goto P_0c0c8f00;
case 0x0c0c8f02u: goto P_0c0c8f02;
case 0x0c0c8f04u: goto P_0c0c8f04;
case 0x0c0c8f06u: goto P_0c0c8f06;
case 0x0c0c8f08u: goto P_0c0c8f08;
case 0x0c0c8f0au: goto P_0c0c8f0a;
case 0x0c0c8f0cu: goto P_0c0c8f0c;
case 0x0c0c8f0eu: goto P_0c0c8f0e;
case 0x0c0c8f10u: goto P_0c0c8f10;
case 0x0c0c8f12u: goto P_0c0c8f12;
case 0x0c0c8f14u: goto P_0c0c8f14;
case 0x0c0c8f16u: goto P_0c0c8f16;
case 0x0c0c8f18u: goto P_0c0c8f18;
case 0x0c0c8f1au: goto P_0c0c8f1a;
case 0x0c0c8f1cu: goto P_0c0c8f1c;
case 0x0c0c8f1eu: goto P_0c0c8f1e;
case 0x0c0c8f20u: goto P_0c0c8f20;
case 0x0c0c8f22u: goto P_0c0c8f22;
case 0x0c0c8f24u: goto P_0c0c8f24;
case 0x0c0c8f26u: goto P_0c0c8f26;
case 0x0c0c8f28u: goto P_0c0c8f28;
case 0x0c0c8f2au: goto P_0c0c8f2a;
case 0x0c0c8f2cu: goto P_0c0c8f2c;
case 0x0c0c8f2eu: goto P_0c0c8f2e;
case 0x0c0c8f30u: goto P_0c0c8f30;
case 0x0c0c8f32u: goto P_0c0c8f32;
case 0x0c0c8f34u: goto P_0c0c8f34;
default: return vf3_matrix_family(target,s,ram);
}
P_0c020024: /* original c719, guest PC 0x0c020024 */
if(!s->budget--) { s->failed_pc=0x0c020024u; return 0; }
r[0]=0x0c02008cu;
goto P_0c020026;
P_0c020026: /* original 6206, guest PC 0x0c020026 */
if(!s->budget--) { s->failed_pc=0x0c020026u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[2]=tmp;
goto P_0c020028;
P_0c020028: /* original e300, guest PC 0x0c020028 */
if(!s->budget--) { s->failed_pc=0x0c020028u; return 0; }
r[3]=0x00000000u;
goto P_0c02002a;
P_0c02002a: /* original 6406, guest PC 0x0c02002a */
if(!s->budget--) { s->failed_pc=0x0c02002au; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[4]=tmp;
goto P_0c02002c;
P_0c02002c: /* original 2232, guest PC 0x0c02002c */
if(!s->budget--) { s->failed_pc=0x0c02002cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c02002e;
P_0c02002e: /* original 4410, guest PC 0x0c02002e */
if(!s->budget--) { s->failed_pc=0x0c02002eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c020030;
P_0c020030: /* original 7204, guest PC 0x0c020030 */
if(!s->budget--) { s->failed_pc=0x0c020030u; return 0; }
r[2]+=0x00000004u;
goto P_0c020032;
P_0c020032: /* original 8bfb, guest PC 0x0c020032 */
if(!s->budget--) { s->failed_pc=0x0c020032u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c02002c; }
goto P_0c020034;
P_0c020034: /* original 0009, guest PC 0x0c020034 */
if(!s->budget--) { s->failed_pc=0x0c020034u; return 0; }
goto P_0c020036;
P_0c020036: /* original c719, guest PC 0x0c020036 */
if(!s->budget--) { s->failed_pc=0x0c020036u; return 0; }
r[0]=0x0c02009cu;
goto P_0c020038;
P_0c020038: /* original 6f06, guest PC 0x0c020038 */
if(!s->budget--) { s->failed_pc=0x0c020038u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[15]=tmp;
goto P_0c02003a;
P_0c02003a: /* original 6006, guest PC 0x0c02003a */
if(!s->budget--) { s->failed_pc=0x0c02003au; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c02003c;
P_0c02003c: /* original e100, guest PC 0x0c02003c */
if(!s->budget--) { s->failed_pc=0x0c02003cu; return 0; }
r[1]=0x00000000u;
goto P_0c02003e;
P_0c02003e: /* original e200, guest PC 0x0c02003e */
if(!s->budget--) { s->failed_pc=0x0c02003eu; return 0; }
r[2]=0x00000000u;
goto P_0c020040;
P_0c020040: /* original e300, guest PC 0x0c020040 */
if(!s->budget--) { s->failed_pc=0x0c020040u; return 0; }
r[3]=0x00000000u;
goto P_0c020042;
P_0c020042: /* original e400, guest PC 0x0c020042 */
if(!s->budget--) { s->failed_pc=0x0c020042u; return 0; }
r[4]=0x00000000u;
goto P_0c020044;
P_0c020044: /* original e500, guest PC 0x0c020044 */
if(!s->budget--) { s->failed_pc=0x0c020044u; return 0; }
r[5]=0x00000000u;
goto P_0c020046;
P_0c020046: /* original e600, guest PC 0x0c020046 */
if(!s->budget--) { s->failed_pc=0x0c020046u; return 0; }
r[6]=0x00000000u;
goto P_0c020048;
P_0c020048: /* original e700, guest PC 0x0c020048 */
if(!s->budget--) { s->failed_pc=0x0c020048u; return 0; }
r[7]=0x00000000u;
goto P_0c02004a;
P_0c02004a: /* original e800, guest PC 0x0c02004a */
if(!s->budget--) { s->failed_pc=0x0c02004au; return 0; }
r[8]=0x00000000u;
goto P_0c02004c;
P_0c02004c: /* original e900, guest PC 0x0c02004c */
if(!s->budget--) { s->failed_pc=0x0c02004cu; return 0; }
r[9]=0x00000000u;
goto P_0c02004e;
P_0c02004e: /* original ea00, guest PC 0x0c02004e */
if(!s->budget--) { s->failed_pc=0x0c02004eu; return 0; }
r[10]=0x00000000u;
goto P_0c020050;
P_0c020050: /* original eb00, guest PC 0x0c020050 */
if(!s->budget--) { s->failed_pc=0x0c020050u; return 0; }
r[11]=0x00000000u;
goto P_0c020052;
P_0c020052: /* original ec00, guest PC 0x0c020052 */
if(!s->budget--) { s->failed_pc=0x0c020052u; return 0; }
r[12]=0x00000000u;
goto P_0c020054;
P_0c020054: /* original ed00, guest PC 0x0c020054 */
if(!s->budget--) { s->failed_pc=0x0c020054u; return 0; }
r[13]=0x00000000u;
goto P_0c020056;
P_0c020056: /* original ee00, guest PC 0x0c020056 */
if(!s->budget--) { s->failed_pc=0x0c020056u; return 0; }
r[14]=0x00000000u;
goto P_0c020058;
P_0c020058: /* original f08d, guest PC 0x0c020058 */
if(!s->budget--) { s->failed_pc=0x0c020058u; return 0; }
fr[0]=0;
goto P_0c02005a;
P_0c02005a: /* original f10c, guest PC 0x0c02005a */
if(!s->budget--) { s->failed_pc=0x0c02005au; return 0; }
vf3_matrix_move(s,1,0);
goto P_0c02005c;
P_0c02005c: /* original f20c, guest PC 0x0c02005c */
if(!s->budget--) { s->failed_pc=0x0c02005cu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c02005e;
P_0c02005e: /* original f30c, guest PC 0x0c02005e */
if(!s->budget--) { s->failed_pc=0x0c02005eu; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c020060;
P_0c020060: /* original f40c, guest PC 0x0c020060 */
if(!s->budget--) { s->failed_pc=0x0c020060u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c020062;
P_0c020062: /* original f50c, guest PC 0x0c020062 */
if(!s->budget--) { s->failed_pc=0x0c020062u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c020064;
P_0c020064: /* original f60c, guest PC 0x0c020064 */
if(!s->budget--) { s->failed_pc=0x0c020064u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c020066;
P_0c020066: /* original f70c, guest PC 0x0c020066 */
if(!s->budget--) { s->failed_pc=0x0c020066u; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c020068;
P_0c020068: /* original f80c, guest PC 0x0c020068 */
if(!s->budget--) { s->failed_pc=0x0c020068u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c02006a;
P_0c02006a: /* original f90c, guest PC 0x0c02006a */
if(!s->budget--) { s->failed_pc=0x0c02006au; return 0; }
vf3_matrix_move(s,9,0);
goto P_0c02006c;
P_0c02006c: /* original fa0c, guest PC 0x0c02006c */
if(!s->budget--) { s->failed_pc=0x0c02006cu; return 0; }
vf3_matrix_move(s,10,0);
goto P_0c02006e;
P_0c02006e: /* original fb0c, guest PC 0x0c02006e */
if(!s->budget--) { s->failed_pc=0x0c02006eu; return 0; }
vf3_matrix_move(s,11,0);
goto P_0c020070;
P_0c020070: /* original fc0c, guest PC 0x0c020070 */
if(!s->budget--) { s->failed_pc=0x0c020070u; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c020072;
P_0c020072: /* original fd0c, guest PC 0x0c020072 */
if(!s->budget--) { s->failed_pc=0x0c020072u; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c020074;
P_0c020074: /* original fe0c, guest PC 0x0c020074 */
if(!s->budget--) { s->failed_pc=0x0c020074u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c020076;
P_0c020076: /* original ff0c, guest PC 0x0c020076 */
if(!s->budget--) { s->failed_pc=0x0c020076u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c020078;
P_0c020078: /* original 400b, guest PC 0x0c020078 */
if(!s->budget--) { s->failed_pc=0x0c020078u; return 0; }
target=r[0];
r[16]=code_base|0x0c02007cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c02007cu) { target=s->pc; goto dispatch; }
goto P_0c02007c;
P_0c02007a: /* original 0009, guest PC 0x0c02007a */
if(!s->budget--) { s->failed_pc=0x0c02007au; return 0; }
goto P_0c02007c;
P_0c02007c: /* original affe, guest PC 0x0c02007c */
if(!s->budget--) { s->failed_pc=0x0c02007cu; return 0; }
goto P_0c02007c;
P_0c02007e: /* original 0009, guest PC 0x0c02007e */
if(!s->budget--) { s->failed_pc=0x0c02007eu; return 0; }
return vf3_matrix_family(0x0c020080u,s,ram);
P_0c039fd0: /* original f34c, guest PC 0x0c039fd0 */
if(!s->budget--) { s->failed_pc=0x0c039fd0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c039fd2;
P_0c039fd2: /* original f35d, guest PC 0x0c039fd2 */
if(!s->budget--) { s->failed_pc=0x0c039fd2u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c039fd4;
P_0c039fd4: /* original f69d, guest PC 0x0c039fd4 */
if(!s->budget--) { s->failed_pc=0x0c039fd4u; return 0; }
fr[6]=0x3f800000u;
goto P_0c039fd6;
P_0c039fd6: /* original f365, guest PC 0x0c039fd6 */
if(!s->budget--) { s->failed_pc=0x0c039fd6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c039fd8;
P_0c039fd8: /* original 8d02, guest PC 0x0c039fd8 */
if(!s->budget--) { s->failed_pc=0x0c039fd8u; return 0; }
cond=r[17]&1u;
fr[7]=0;
if(cond) { goto P_0c039fe0; }
goto P_0c039fdc;
P_0c039fda: /* original f78d, guest PC 0x0c039fda */
if(!s->budget--) { s->failed_pc=0x0c039fdau; return 0; }
fr[7]=0;
goto P_0c039fdc;
P_0c039fdc: /* original a002, guest PC 0x0c039fdc */
if(!s->budget--) { s->failed_pc=0x0c039fdcu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe4;
P_0c039fde: /* original f54c, guest PC 0x0c039fde */
if(!s->budget--) { s->failed_pc=0x0c039fdeu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe0;
P_0c039fe0: /* original f56c, guest PC 0x0c039fe0 */
if(!s->budget--) { s->failed_pc=0x0c039fe0u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c039fe2;
P_0c039fe2: /* original f543, guest PC 0x0c039fe2 */
if(!s->budget--) { s->failed_pc=0x0c039fe2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c039fe4;
P_0c039fe4: /* original e40d, guest PC 0x0c039fe4 */
if(!s->budget--) { s->failed_pc=0x0c039fe4u; return 0; }
r[4]=0x0000000du;
goto P_0c039fe6;
P_0c039fe6: /* original e501, guest PC 0x0c039fe6 */
if(!s->budget--) { s->failed_pc=0x0c039fe6u; return 0; }
r[5]=0x00000001u;
goto P_0c039fe8;
P_0c039fe8: /* original 445a, guest PC 0x0c039fe8 */
if(!s->budget--) { s->failed_pc=0x0c039fe8u; return 0; }
r[53]=r[4];
goto P_0c039fea;
P_0c039fea: /* original 6343, guest PC 0x0c039fea */
if(!s->budget--) { s->failed_pc=0x0c039feau; return 0; }
r[3]=r[4];
goto P_0c039fec;
P_0c039fec: /* original 4300, guest PC 0x0c039fec */
if(!s->budget--) { s->failed_pc=0x0c039fecu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c039fee;
P_0c039fee: /* original 74ff, guest PC 0x0c039fee */
if(!s->budget--) { s->failed_pc=0x0c039feeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c039ff0;
P_0c039ff0: /* original f32d, guest PC 0x0c039ff0 */
if(!s->budget--) { s->failed_pc=0x0c039ff0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff2;
P_0c039ff2: /* original 435a, guest PC 0x0c039ff2 */
if(!s->budget--) { s->failed_pc=0x0c039ff2u; return 0; }
r[53]=r[3];
goto P_0c039ff4;
P_0c039ff4: /* original 3453, guest PC 0x0c039ff4 */
if(!s->budget--) { s->failed_pc=0x0c039ff4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c039ff6;
P_0c039ff6: /* original f22d, guest PC 0x0c039ff6 */
if(!s->budget--) { s->failed_pc=0x0c039ff6u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff8;
P_0c039ff8: /* original f83c, guest PC 0x0c039ff8 */
if(!s->budget--) { s->failed_pc=0x0c039ff8u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c039ffa;
P_0c039ffa: /* original f382, guest PC 0x0c039ffa */
if(!s->budget--) { s->failed_pc=0x0c039ffau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c039ffc;
P_0c039ffc: /* original f270, guest PC 0x0c039ffc */
if(!s->budget--) { s->failed_pc=0x0c039ffcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'+');
goto P_0c039ffe;
P_0c039ffe: /* original f352, guest PC 0x0c039ffe */
if(!s->budget--) { s->failed_pc=0x0c039ffeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a000;
P_0c03a000: /* original f260, guest PC 0x0c03a000 */
if(!s->budget--) { s->failed_pc=0x0c03a000u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'+');
goto P_0c03a002;
P_0c03a002: /* original f352, guest PC 0x0c03a002 */
if(!s->budget--) { s->failed_pc=0x0c03a002u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a004;
P_0c03a004: /* original f73c, guest PC 0x0c03a004 */
if(!s->budget--) { s->failed_pc=0x0c03a004u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c03a006;
P_0c03a006: /* original 8def, guest PC 0x0c03a006 */
if(!s->budget--) { s->failed_pc=0x0c03a006u; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
if(cond) { goto P_0c039fe8; }
goto P_0c03a00a;
P_0c03a008: /* original f723, guest PC 0x0c03a008 */
if(!s->budget--) { s->failed_pc=0x0c03a008u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
goto P_0c03a00a;
P_0c03a00a: /* original f760, guest PC 0x0c03a00a */
if(!s->budget--) { s->failed_pc=0x0c03a00au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'+');
goto P_0c03a00c;
P_0c03a00c: /* original c713, guest PC 0x0c03a00c */
if(!s->budget--) { s->failed_pc=0x0c03a00cu; return 0; }
r[0]=0x0c03a05cu;
goto P_0c03a00e;
P_0c03a00e: /* original f465, guest PC 0x0c03a00e */
if(!s->budget--) { s->failed_pc=0x0c03a00eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c03a010;
P_0c03a010: /* original d315, guest PC 0x0c03a010 */
if(!s->budget--) { s->failed_pc=0x0c03a010u; return 0; }
r[3]=read(ram,0x0c03a068u,4);
goto P_0c03a012;
P_0c03a012: /* original f573, guest PC 0x0c03a012 */
if(!s->budget--) { s->failed_pc=0x0c03a012u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'/');
goto P_0c03a014;
P_0c03a014: /* original f708, guest PC 0x0c03a014 */
if(!s->budget--) { s->failed_pc=0x0c03a014u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a016;
P_0c03a016: /* original c712, guest PC 0x0c03a016 */
if(!s->budget--) { s->failed_pc=0x0c03a016u; return 0; }
r[0]=0x0c03a060u;
goto P_0c03a018;
P_0c03a018: /* original f208, guest PC 0x0c03a018 */
if(!s->budget--) { s->failed_pc=0x0c03a018u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a01a;
P_0c03a01a: /* original c712, guest PC 0x0c03a01a */
if(!s->budget--) { s->failed_pc=0x0c03a01au; return 0; }
r[0]=0x0c03a064u;
goto P_0c03a01c;
P_0c03a01c: /* original f108, guest PC 0x0c03a01c */
if(!s->budget--) { s->failed_pc=0x0c03a01cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a01e;
P_0c03a01e: /* original f35c, guest PC 0x0c03a01e */
if(!s->budget--) { s->failed_pc=0x0c03a01eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03a020;
P_0c03a020: /* original f370, guest PC 0x0c03a020 */
if(!s->budget--) { s->failed_pc=0x0c03a020u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c03a022;
P_0c03a022: /* original f322, guest PC 0x0c03a022 */
if(!s->budget--) { s->failed_pc=0x0c03a022u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a024;
P_0c03a024: /* original f373, guest PC 0x0c03a024 */
if(!s->budget--) { s->failed_pc=0x0c03a024u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'/');
goto P_0c03a026;
P_0c03a026: /* original f310, guest PC 0x0c03a026 */
if(!s->budget--) { s->failed_pc=0x0c03a026u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'+');
goto P_0c03a028;
P_0c03a028: /* original f33d, guest PC 0x0c03a028 */
if(!s->budget--) { s->failed_pc=0x0c03a028u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a02a;
P_0c03a02a: /* original 045a, guest PC 0x0c03a02a */
if(!s->budget--) { s->failed_pc=0x0c03a02au; return 0; }
r[4]=r[53];
goto P_0c03a02c;
P_0c03a02c: /* original 8f08, guest PC 0x0c03a02c */
if(!s->budget--) { s->failed_pc=0x0c03a02cu; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(!cond) { goto P_0c03a040; }
goto P_0c03a030;
P_0c03a02e: /* original 2439, guest PC 0x0c03a02e */
if(!s->budget--) { s->failed_pc=0x0c03a02eu; return 0; }
r[4]&=r[3];
goto P_0c03a030;
P_0c03a030: /* original 9011, guest PC 0x0c03a030 */
if(!s->budget--) { s->failed_pc=0x0c03a030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a056u,2);
goto P_0c03a032;
P_0c03a032: /* original a00a, guest PC 0x0c03a032 */
if(!s->budget--) { s->failed_pc=0x0c03a032u; return 0; }
goto P_0c03a04a;
P_0c03a034: /* original 0009, guest PC 0x0c03a034 */
if(!s->budget--) { s->failed_pc=0x0c03a034u; return 0; }
return vf3_matrix_family(0x0c03a036u,s,ram);
P_0c03a040: /* original c70a, guest PC 0x0c03a040 */
if(!s->budget--) { s->failed_pc=0x0c03a040u; return 0; }
r[0]=0x0c03a06cu;
goto P_0c03a042;
P_0c03a042: /* original f308, guest PC 0x0c03a042 */
if(!s->budget--) { s->failed_pc=0x0c03a042u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a044;
P_0c03a044: /* original f345, guest PC 0x0c03a044 */
if(!s->budget--) { s->failed_pc=0x0c03a044u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c03a046;
P_0c03a046: /* original 8b03, guest PC 0x0c03a046 */
if(!s->budget--) { s->failed_pc=0x0c03a046u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a050; }
goto P_0c03a048;
P_0c03a048: /* original d003, guest PC 0x0c03a048 */
if(!s->budget--) { s->failed_pc=0x0c03a048u; return 0; }
r[0]=read(ram,0x0c03a058u,4);
goto P_0c03a04a;
P_0c03a04a: /* original 3048, guest PC 0x0c03a04a */
if(!s->budget--) { s->failed_pc=0x0c03a04au; return 0; }
r[0]-=r[4];
goto P_0c03a04c;
P_0c03a04c: /* original 000b, guest PC 0x0c03a04c */
if(!s->budget--) { s->failed_pc=0x0c03a04cu; return 0; }
target=r[16];
r[0]=r[0]&65535u;
s->pc=target; return ram->oob==0;
P_0c03a04e: /* original 600d, guest PC 0x0c03a04e */
if(!s->budget--) { s->failed_pc=0x0c03a04eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c03a050;
P_0c03a050: /* original 6043, guest PC 0x0c03a050 */
if(!s->budget--) { s->failed_pc=0x0c03a050u; return 0; }
r[0]=r[4];
goto P_0c03a052;
P_0c03a052: /* original 000b, guest PC 0x0c03a052 */
if(!s->budget--) { s->failed_pc=0x0c03a052u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a054: /* original 0009, guest PC 0x0c03a054 */
if(!s->budget--) { s->failed_pc=0x0c03a054u; return 0; }
return vf3_matrix_family(0x0c03a056u,s,ram);
P_0c03a07c: /* original 4f22, guest PC 0x0c03a07c */
if(!s->budget--) { s->failed_pc=0x0c03a07cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03a07e;
P_0c03a07e: /* original de2d, guest PC 0x0c03a07e */
if(!s->budget--) { s->failed_pc=0x0c03a07eu; return 0; }
r[14]=read(ram,0x0c03a134u,4);
goto P_0c03a080;
P_0c03a080: /* original f64c, guest PC 0x0c03a080 */
if(!s->budget--) { s->failed_pc=0x0c03a080u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a082;
P_0c03a082: /* original f64d, guest PC 0x0c03a082 */
if(!s->budget--) { s->failed_pc=0x0c03a082u; return 0; }
fr[6]^=0x80000000u;
goto P_0c03a084;
P_0c03a084: /* original fe5c, guest PC 0x0c03a084 */
if(!s->budget--) { s->failed_pc=0x0c03a084u; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c03a086;
P_0c03a086: /* original 8d23, guest PC 0x0c03a086 */
if(!s->budget--) { s->failed_pc=0x0c03a086u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
if(cond) { goto P_0c03a0d0; }
goto P_0c03a08a;
P_0c03a088: /* original fe43, guest PC 0x0c03a088 */
if(!s->budget--) { s->failed_pc=0x0c03a088u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
goto P_0c03a08a;
P_0c03a08a: /* original f655, guest PC 0x0c03a08a */
if(!s->budget--) { s->failed_pc=0x0c03a08au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c03a08c;
P_0c03a08c: /* original 8910, guest PC 0x0c03a08c */
if(!s->budget--) { s->failed_pc=0x0c03a08cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a0b0; }
goto P_0c03a08e;
P_0c03a08e: /* original f38d, guest PC 0x0c03a08e */
if(!s->budget--) { s->failed_pc=0x0c03a08eu; return 0; }
fr[3]=0;
goto P_0c03a090;
P_0c03a090: /* original f534, guest PC 0x0c03a090 */
if(!s->budget--) { s->failed_pc=0x0c03a090u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c03a092;
P_0c03a092: /* original 8b05, guest PC 0x0c03a092 */
if(!s->budget--) { s->failed_pc=0x0c03a092u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a0a0; }
goto P_0c03a094;
P_0c03a094: /* original a039, guest PC 0x0c03a094 */
if(!s->budget--) { s->failed_pc=0x0c03a094u; return 0; }
r[0]=0x00000000u;
goto P_0c03a10a;
P_0c03a096: /* original e000, guest PC 0x0c03a096 */
if(!s->budget--) { s->failed_pc=0x0c03a096u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c03a098u,s,ram);
P_0c03a0a0: /* original 4f26, guest PC 0x0c03a0a0 */
if(!s->budget--) { s->failed_pc=0x0c03a0a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03a0a2;
P_0c03a0a2: /* original f4fc, guest PC 0x0c03a0a2 */
if(!s->budget--) { s->failed_pc=0x0c03a0a2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c03a0a4;
P_0c03a0a4: /* original fef9, guest PC 0x0c03a0a4 */
if(!s->budget--) { s->failed_pc=0x0c03a0a4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a0a6;
P_0c03a0a6: /* original fff9, guest PC 0x0c03a0a6 */
if(!s->budget--) { s->failed_pc=0x0c03a0a6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a0a8;
P_0c03a0a8: /* original af92, guest PC 0x0c03a0a8 */
if(!s->budget--) { s->failed_pc=0x0c03a0a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c039fd0;
P_0c03a0aa: /* original 6ef6, guest PC 0x0c03a0aa */
if(!s->budget--) { s->failed_pc=0x0c03a0aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03a0acu,s,ram);
P_0c03a0b0: /* original f38d, guest PC 0x0c03a0b0 */
if(!s->budget--) { s->failed_pc=0x0c03a0b0u; return 0; }
fr[3]=0;
goto P_0c03a0b2;
P_0c03a0b2: /* original f434, guest PC 0x0c03a0b2 */
if(!s->budget--) { s->failed_pc=0x0c03a0b2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c03a0b4;
P_0c03a0b4: /* original 8b04, guest PC 0x0c03a0b4 */
if(!s->budget--) { s->failed_pc=0x0c03a0b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a0c0; }
goto P_0c03a0b6;
P_0c03a0b6: /* original d020, guest PC 0x0c03a0b6 */
if(!s->budget--) { s->failed_pc=0x0c03a0b6u; return 0; }
r[0]=read(ram,0x0c03a138u,4);
goto P_0c03a0b8;
P_0c03a0b8: /* original a027, guest PC 0x0c03a0b8 */
if(!s->budget--) { s->failed_pc=0x0c03a0b8u; return 0; }
goto P_0c03a10a;
P_0c03a0ba: /* original 0009, guest PC 0x0c03a0ba */
if(!s->budget--) { s->failed_pc=0x0c03a0bau; return 0; }
return vf3_matrix_family(0x0c03a0bcu,s,ram);
P_0c03a0c0: /* original bf86, guest PC 0x0c03a0c0 */
if(!s->budget--) { s->failed_pc=0x0c03a0c0u; return 0; }
target=0x0c039fd0u; r[16]=code_base|0x0c03a0c4u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03a0c4u) { target=s->pc; goto dispatch; }
goto P_0c03a0c4;
P_0c03a0c2: /* original f4ec, guest PC 0x0c03a0c2 */
if(!s->budget--) { s->failed_pc=0x0c03a0c2u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c03a0c4;
P_0c03a0c4: /* original d31c, guest PC 0x0c03a0c4 */
if(!s->budget--) { s->failed_pc=0x0c03a0c4u; return 0; }
r[3]=read(ram,0x0c03a138u,4);
goto P_0c03a0c6;
P_0c03a0c6: /* original a01e, guest PC 0x0c03a0c6 */
if(!s->budget--) { s->failed_pc=0x0c03a0c6u; return 0; }
r[0]=0u-r[0];
goto P_0c03a106;
P_0c03a0c8: /* original 600b, guest PC 0x0c03a0c8 */
if(!s->budget--) { s->failed_pc=0x0c03a0c8u; return 0; }
r[0]=0u-r[0];
return vf3_matrix_family(0x0c03a0cau,s,ram);
P_0c03a0d0: /* original f655, guest PC 0x0c03a0d0 */
if(!s->budget--) { s->failed_pc=0x0c03a0d0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c03a0d2;
P_0c03a0d2: /* original 890d, guest PC 0x0c03a0d2 */
if(!s->budget--) { s->failed_pc=0x0c03a0d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a0f0; }
goto P_0c03a0d4;
P_0c03a0d4: /* original f38d, guest PC 0x0c03a0d4 */
if(!s->budget--) { s->failed_pc=0x0c03a0d4u; return 0; }
fr[3]=0;
goto P_0c03a0d6;
P_0c03a0d6: /* original f434, guest PC 0x0c03a0d6 */
if(!s->budget--) { s->failed_pc=0x0c03a0d6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c03a0d8;
P_0c03a0d8: /* original 8b02, guest PC 0x0c03a0d8 */
if(!s->budget--) { s->failed_pc=0x0c03a0d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a0e0; }
goto P_0c03a0da;
P_0c03a0da: /* original 902a, guest PC 0x0c03a0da */
if(!s->budget--) { s->failed_pc=0x0c03a0dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a132u,2);
goto P_0c03a0dc;
P_0c03a0dc: /* original a015, guest PC 0x0c03a0dc */
if(!s->budget--) { s->failed_pc=0x0c03a0dcu; return 0; }
goto P_0c03a10a;
P_0c03a0de: /* original 0009, guest PC 0x0c03a0de */
if(!s->budget--) { s->failed_pc=0x0c03a0deu; return 0; }
goto P_0c03a0e0;
P_0c03a0e0: /* original bf76, guest PC 0x0c03a0e0 */
if(!s->budget--) { s->failed_pc=0x0c03a0e0u; return 0; }
target=0x0c039fd0u; r[16]=code_base|0x0c03a0e4u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03a0e4u) { target=s->pc; goto dispatch; }
goto P_0c03a0e4;
P_0c03a0e2: /* original f4ec, guest PC 0x0c03a0e2 */
if(!s->budget--) { s->failed_pc=0x0c03a0e2u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c03a0e4;
P_0c03a0e4: /* original 9325, guest PC 0x0c03a0e4 */
if(!s->budget--) { s->failed_pc=0x0c03a0e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a132u,2);
goto P_0c03a0e6;
P_0c03a0e6: /* original a00e, guest PC 0x0c03a0e6 */
if(!s->budget--) { s->failed_pc=0x0c03a0e6u; return 0; }
r[0]=0u-r[0];
goto P_0c03a106;
P_0c03a0e8: /* original 600b, guest PC 0x0c03a0e8 */
if(!s->budget--) { s->failed_pc=0x0c03a0e8u; return 0; }
r[0]=0u-r[0];
return vf3_matrix_family(0x0c03a0eau,s,ram);
P_0c03a0f0: /* original f38d, guest PC 0x0c03a0f0 */
if(!s->budget--) { s->failed_pc=0x0c03a0f0u; return 0; }
fr[3]=0;
goto P_0c03a0f2;
P_0c03a0f2: /* original f534, guest PC 0x0c03a0f2 */
if(!s->budget--) { s->failed_pc=0x0c03a0f2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c03a0f4;
P_0c03a0f4: /* original 8b04, guest PC 0x0c03a0f4 */
if(!s->budget--) { s->failed_pc=0x0c03a0f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a100; }
goto P_0c03a0f6;
P_0c03a0f6: /* original d011, guest PC 0x0c03a0f6 */
if(!s->budget--) { s->failed_pc=0x0c03a0f6u; return 0; }
r[0]=read(ram,0x0c03a13cu,4);
goto P_0c03a0f8;
P_0c03a0f8: /* original a007, guest PC 0x0c03a0f8 */
if(!s->budget--) { s->failed_pc=0x0c03a0f8u; return 0; }
goto P_0c03a10a;
P_0c03a0fa: /* original 0009, guest PC 0x0c03a0fa */
if(!s->budget--) { s->failed_pc=0x0c03a0fau; return 0; }
return vf3_matrix_family(0x0c03a0fcu,s,ram);
P_0c03a100: /* original bf66, guest PC 0x0c03a100 */
if(!s->budget--) { s->failed_pc=0x0c03a100u; return 0; }
target=0x0c039fd0u; r[16]=code_base|0x0c03a104u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03a104u) { target=s->pc; goto dispatch; }
goto P_0c03a104;
P_0c03a102: /* original f4fc, guest PC 0x0c03a102 */
if(!s->budget--) { s->failed_pc=0x0c03a102u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c03a104;
P_0c03a104: /* original d30d, guest PC 0x0c03a104 */
if(!s->budget--) { s->failed_pc=0x0c03a104u; return 0; }
r[3]=read(ram,0x0c03a13cu,4);
goto P_0c03a106;
P_0c03a106: /* original 303c, guest PC 0x0c03a106 */
if(!s->budget--) { s->failed_pc=0x0c03a106u; return 0; }
r[0]+=r[3];
goto P_0c03a108;
P_0c03a108: /* original 20e9, guest PC 0x0c03a108 */
if(!s->budget--) { s->failed_pc=0x0c03a108u; return 0; }
r[0]&=r[14];
goto P_0c03a10a;
P_0c03a10a: /* original 4f26, guest PC 0x0c03a10a */
if(!s->budget--) { s->failed_pc=0x0c03a10au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03a10c;
P_0c03a10c: /* original fef9, guest PC 0x0c03a10c */
if(!s->budget--) { s->failed_pc=0x0c03a10cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a10e;
P_0c03a10e: /* original fff9, guest PC 0x0c03a10e */
if(!s->budget--) { s->failed_pc=0x0c03a10eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a110;
P_0c03a110: /* original 000b, guest PC 0x0c03a110 */
if(!s->budget--) { s->failed_pc=0x0c03a110u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03a112: /* original 6ef6, guest PC 0x0c03a112 */
if(!s->budget--) { s->failed_pc=0x0c03a112u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03a114u,s,ram);
P_0c0406b2: /* original 2fe6, guest PC 0x0c0406b2 */
if(!s->budget--) { s->failed_pc=0x0c0406b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0406b4;
P_0c0406b4: /* original 2fd6, guest PC 0x0c0406b4 */
if(!s->budget--) { s->failed_pc=0x0c0406b4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0406b6;
P_0c0406b6: /* original 2fc6, guest PC 0x0c0406b6 */
if(!s->budget--) { s->failed_pc=0x0c0406b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0406b8;
P_0c0406b8: /* original 4f22, guest PC 0x0c0406b8 */
if(!s->budget--) { s->failed_pc=0x0c0406b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0406ba;
P_0c0406ba: /* original 7fe4, guest PC 0x0c0406ba */
if(!s->budget--) { s->failed_pc=0x0c0406bau; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0406bc;
P_0c0406bc: /* original 1f46, guest PC 0x0c0406bc */
if(!s->budget--) { s->failed_pc=0x0c0406bcu; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c0406be;
P_0c0406be: /* original 1f55, guest PC 0x0c0406be */
if(!s->budget--) { s->failed_pc=0x0c0406beu; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c0406c0;
P_0c0406c0: /* original 55f5, guest PC 0x0c0406c0 */
if(!s->budget--) { s->failed_pc=0x0c0406c0u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0406c2;
P_0c0406c2: /* original 54f6, guest PC 0x0c0406c2 */
if(!s->budget--) { s->failed_pc=0x0c0406c2u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0406c4;
P_0c0406c4: /* original bd46, guest PC 0x0c0406c4 */
if(!s->budget--) { s->failed_pc=0x0c0406c4u; return 0; }
target=0x0c040154u; r[16]=code_base|0x0c0406c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0406c8u) { target=s->pc; goto dispatch; }
goto P_0c0406c8;
P_0c0406c6: /* original 0009, guest PC 0x0c0406c6 */
if(!s->budget--) { s->failed_pc=0x0c0406c6u; return 0; }
goto P_0c0406c8;
P_0c0406c8: /* original 1f01, guest PC 0x0c0406c8 */
if(!s->budget--) { s->failed_pc=0x0c0406c8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0406ca;
P_0c0406ca: /* original 2008, guest PC 0x0c0406ca */
if(!s->budget--) { s->failed_pc=0x0c0406cau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0406cc;
P_0c0406cc: /* original 8901, guest PC 0x0c0406cc */
if(!s->budget--) { s->failed_pc=0x0c0406ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0406d2; }
goto P_0c0406ce;
P_0c0406ce: /* original a075, guest PC 0x0c0406ce */
if(!s->budget--) { s->failed_pc=0x0c0406ceu; return 0; }
goto P_0c0407bc;
P_0c0406d0: /* original 0009, guest PC 0x0c0406d0 */
if(!s->budget--) { s->failed_pc=0x0c0406d0u; return 0; }
goto P_0c0406d2;
P_0c0406d2: /* original 52f6, guest PC 0x0c0406d2 */
if(!s->budget--) { s->failed_pc=0x0c0406d2u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0406d4;
P_0c0406d4: /* original 5322, guest PC 0x0c0406d4 */
if(!s->budget--) { s->failed_pc=0x0c0406d4u; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c0406d6;
P_0c0406d6: /* original 1f33, guest PC 0x0c0406d6 */
if(!s->budget--) { s->failed_pc=0x0c0406d6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0406d8;
P_0c0406d8: /* original 5121, guest PC 0x0c0406d8 */
if(!s->budget--) { s->failed_pc=0x0c0406d8u; return 0; }
r[1]=read(ram,r[2]+4,4);
goto P_0c0406da;
P_0c0406da: /* original 1f12, guest PC 0x0c0406da */
if(!s->budget--) { s->failed_pc=0x0c0406dau; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0406dc;
P_0c0406dc: /* original 67f3, guest PC 0x0c0406dc */
if(!s->budget--) { s->failed_pc=0x0c0406dcu; return 0; }
r[7]=r[15];
goto P_0c0406de;
P_0c0406de: /* original 56f3, guest PC 0x0c0406de */
if(!s->budget--) { s->failed_pc=0x0c0406deu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0406e0;
P_0c0406e0: /* original 55f2, guest PC 0x0c0406e0 */
if(!s->budget--) { s->failed_pc=0x0c0406e0u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0406e2;
P_0c0406e2: /* original 54f5, guest PC 0x0c0406e2 */
if(!s->budget--) { s->failed_pc=0x0c0406e2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0406e4;
P_0c0406e4: /* original bd9d, guest PC 0x0c0406e4 */
if(!s->budget--) { s->failed_pc=0x0c0406e4u; return 0; }
target=0x0c040222u; r[16]=code_base|0x0c0406e8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0406e8u) { target=s->pc; goto dispatch; }
goto P_0c0406e8;
P_0c0406e6: /* original 0009, guest PC 0x0c0406e6 */
if(!s->budget--) { s->failed_pc=0x0c0406e6u; return 0; }
goto P_0c0406e8;
P_0c0406e8: /* original 1f04, guest PC 0x0c0406e8 */
if(!s->budget--) { s->failed_pc=0x0c0406e8u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c0406ea;
P_0c0406ea: /* original ee00, guest PC 0x0c0406ea */
if(!s->budget--) { s->failed_pc=0x0c0406eau; return 0; }
r[14]=0x00000000u;
goto P_0c0406ec;
P_0c0406ec: /* original a008, guest PC 0x0c0406ec */
if(!s->budget--) { s->failed_pc=0x0c0406ecu; return 0; }
goto P_0c040700;
P_0c0406ee: /* original 0009, guest PC 0x0c0406ee */
if(!s->budget--) { s->failed_pc=0x0c0406eeu; return 0; }
goto P_0c0406f0;
P_0c0406f0: /* original 940c, guest PC 0x0c0406f0 */
if(!s->budget--) { s->failed_pc=0x0c0406f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04070cu,2);
goto P_0c0406f2;
P_0c0406f2: /* original b414, guest PC 0x0c0406f2 */
if(!s->budget--) { s->failed_pc=0x0c0406f2u; return 0; }
target=0x0c040f1eu; r[16]=code_base|0x0c0406f6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0406f6u) { target=s->pc; goto dispatch; }
goto P_0c0406f6;
P_0c0406f4: /* original 0009, guest PC 0x0c0406f4 */
if(!s->budget--) { s->failed_pc=0x0c0406f4u; return 0; }
goto P_0c0406f6;
P_0c0406f6: /* original 2008, guest PC 0x0c0406f6 */
if(!s->budget--) { s->failed_pc=0x0c0406f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0406f8;
P_0c0406f8: /* original 8b01, guest PC 0x0c0406f8 */
if(!s->budget--) { s->failed_pc=0x0c0406f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0406fe; }
goto P_0c0406fa;
P_0c0406fa: /* original a00b, guest PC 0x0c0406fa */
if(!s->budget--) { s->failed_pc=0x0c0406fau; return 0; }
goto P_0c040714;
P_0c0406fc: /* original 0009, guest PC 0x0c0406fc */
if(!s->budget--) { s->failed_pc=0x0c0406fcu; return 0; }
goto P_0c0406fe;
P_0c0406fe: /* original 7e01, guest PC 0x0c0406fe */
if(!s->budget--) { s->failed_pc=0x0c0406feu; return 0; }
r[14]+=0x00000001u;
goto P_0c040700;
P_0c040700: /* original d303, guest PC 0x0c040700 */
if(!s->budget--) { s->failed_pc=0x0c040700u; return 0; }
r[3]=read(ram,0x0c040710u,4);
goto P_0c040702;
P_0c040702: /* original 3e33, guest PC 0x0c040702 */
if(!s->budget--) { s->failed_pc=0x0c040702u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c040704;
P_0c040704: /* original 8bf4, guest PC 0x0c040704 */
if(!s->budget--) { s->failed_pc=0x0c040704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0406f0; }
goto P_0c040706;
P_0c040706: /* original 9002, guest PC 0x0c040706 */
if(!s->budget--) { s->failed_pc=0x0c040706u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04070eu,2);
goto P_0c040708;
P_0c040708: /* original a058, guest PC 0x0c040708 */
if(!s->budget--) { s->failed_pc=0x0c040708u; return 0; }
goto P_0c0407bc;
P_0c04070a: /* original 0009, guest PC 0x0c04070a */
if(!s->budget--) { s->failed_pc=0x0c04070au; return 0; }
return vf3_matrix_family(0x0c04070cu,s,ram);
P_0c040714: /* original ee00, guest PC 0x0c040714 */
if(!s->budget--) { s->failed_pc=0x0c040714u; return 0; }
r[14]=0x00000000u;
goto P_0c040716;
P_0c040716: /* original a007, guest PC 0x0c040716 */
if(!s->budget--) { s->failed_pc=0x0c040716u; return 0; }
goto P_0c040728;
P_0c040718: /* original 0009, guest PC 0x0c040718 */
if(!s->budget--) { s->failed_pc=0x0c040718u; return 0; }
goto P_0c04071a;
P_0c04071a: /* original d322, guest PC 0x0c04071a */
if(!s->budget--) { s->failed_pc=0x0c04071au; return 0; }
r[3]=read(ram,0x0c0407a4u,4);
goto P_0c04071c;
P_0c04071c: /* original 6232, guest PC 0x0c04071c */
if(!s->budget--) { s->failed_pc=0x0c04071cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04071e;
P_0c04071e: /* original 2228, guest PC 0x0c04071e */
if(!s->budget--) { s->failed_pc=0x0c04071eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c040720;
P_0c040720: /* original 8901, guest PC 0x0c040720 */
if(!s->budget--) { s->failed_pc=0x0c040720u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040726; }
goto P_0c040722;
P_0c040722: /* original a007, guest PC 0x0c040722 */
if(!s->budget--) { s->failed_pc=0x0c040722u; return 0; }
goto P_0c040734;
P_0c040724: /* original 0009, guest PC 0x0c040724 */
if(!s->budget--) { s->failed_pc=0x0c040724u; return 0; }
goto P_0c040726;
P_0c040726: /* original 7e01, guest PC 0x0c040726 */
if(!s->budget--) { s->failed_pc=0x0c040726u; return 0; }
r[14]+=0x00000001u;
goto P_0c040728;
P_0c040728: /* original d31f, guest PC 0x0c040728 */
if(!s->budget--) { s->failed_pc=0x0c040728u; return 0; }
r[3]=read(ram,0x0c0407a8u,4);
goto P_0c04072a;
P_0c04072a: /* original 3e33, guest PC 0x0c04072a */
if(!s->budget--) { s->failed_pc=0x0c04072au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c04072c;
P_0c04072c: /* original 8bf5, guest PC 0x0c04072c */
if(!s->budget--) { s->failed_pc=0x0c04072cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04071a; }
goto P_0c04072e;
P_0c04072e: /* original 9037, guest PC 0x0c04072e */
if(!s->budget--) { s->failed_pc=0x0c04072eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0407a0u,2);
goto P_0c040730;
P_0c040730: /* original a044, guest PC 0x0c040730 */
if(!s->budget--) { s->failed_pc=0x0c040730u; return 0; }
goto P_0c0407bc;
P_0c040732: /* original 0009, guest PC 0x0c040732 */
if(!s->budget--) { s->failed_pc=0x0c040732u; return 0; }
goto P_0c040734;
P_0c040734: /* original 63f2, guest PC 0x0c040734 */
if(!s->budget--) { s->failed_pc=0x0c040734u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040736;
P_0c040736: /* original 2338, guest PC 0x0c040736 */
if(!s->budget--) { s->failed_pc=0x0c040736u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c040738;
P_0c040738: /* original 8911, guest PC 0x0c040738 */
if(!s->budget--) { s->failed_pc=0x0c040738u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04075e; }
goto P_0c04073a;
P_0c04073a: /* original 66f2, guest PC 0x0c04073a */
if(!s->budget--) { s->failed_pc=0x0c04073au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04073c;
P_0c04073c: /* original 53f3, guest PC 0x0c04073c */
if(!s->budget--) { s->failed_pc=0x0c04073cu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c04073e;
P_0c04073e: /* original 55f4, guest PC 0x0c04073e */
if(!s->budget--) { s->failed_pc=0x0c04073eu; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c040740;
P_0c040740: /* original 353c, guest PC 0x0c040740 */
if(!s->budget--) { s->failed_pc=0x0c040740u; return 0; }
r[5]+=r[3];
goto P_0c040742;
P_0c040742: /* original 54f4, guest PC 0x0c040742 */
if(!s->budget--) { s->failed_pc=0x0c040742u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c040744;
P_0c040744: /* original bcbc, guest PC 0x0c040744 */
if(!s->budget--) { s->failed_pc=0x0c040744u; return 0; }
target=0x0c0400c0u; r[16]=code_base|0x0c040748u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040748u) { target=s->pc; goto dispatch; }
goto P_0c040748;
P_0c040746: /* original 0009, guest PC 0x0c040746 */
if(!s->budget--) { s->failed_pc=0x0c040746u; return 0; }
goto P_0c040748;
P_0c040748: /* original 1f01, guest PC 0x0c040748 */
if(!s->budget--) { s->failed_pc=0x0c040748u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c04074a;
P_0c04074a: /* original 2008, guest PC 0x0c04074a */
if(!s->budget--) { s->failed_pc=0x0c04074au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04074c;
P_0c04074c: /* original 8901, guest PC 0x0c04074c */
if(!s->budget--) { s->failed_pc=0x0c04074cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040752; }
goto P_0c04074e;
P_0c04074e: /* original a035, guest PC 0x0c04074e */
if(!s->budget--) { s->failed_pc=0x0c04074eu; return 0; }
goto P_0c0407bc;
P_0c040750: /* original 0009, guest PC 0x0c040750 */
if(!s->budget--) { s->failed_pc=0x0c040750u; return 0; }
goto P_0c040752;
P_0c040752: /* original a000, guest PC 0x0c040752 */
if(!s->budget--) { s->failed_pc=0x0c040752u; return 0; }
goto P_0c040756;
P_0c040754: /* original 0009, guest PC 0x0c040754 */
if(!s->budget--) { s->failed_pc=0x0c040754u; return 0; }
goto P_0c040756;
P_0c040756: /* original bcf1, guest PC 0x0c040756 */
if(!s->budget--) { s->failed_pc=0x0c040756u; return 0; }
target=0x0c04013cu; r[16]=code_base|0x0c04075au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04075au) { target=s->pc; goto dispatch; }
goto P_0c04075a;
P_0c040758: /* original 0009, guest PC 0x0c040758 */
if(!s->budget--) { s->failed_pc=0x0c040758u; return 0; }
goto P_0c04075a;
P_0c04075a: /* original 2008, guest PC 0x0c04075a */
if(!s->budget--) { s->failed_pc=0x0c04075au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04075c;
P_0c04075c: /* original 8bfb, guest PC 0x0c04075c */
if(!s->budget--) { s->failed_pc=0x0c04075cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040756; }
goto P_0c04075e;
P_0c04075e: /* original 5df6, guest PC 0x0c04075e */
if(!s->budget--) { s->failed_pc=0x0c04075eu; return 0; }
r[13]=read(ram,r[15]+24,4);
goto P_0c040760;
P_0c040760: /* original 5cf4, guest PC 0x0c040760 */
if(!s->budget--) { s->failed_pc=0x0c040760u; return 0; }
r[12]=read(ram,r[15]+16,4);
goto P_0c040762;
P_0c040762: /* original ee00, guest PC 0x0c040762 */
if(!s->budget--) { s->failed_pc=0x0c040762u; return 0; }
r[14]=0x00000000u;
goto P_0c040764;
P_0c040764: /* original a005, guest PC 0x0c040764 */
if(!s->budget--) { s->failed_pc=0x0c040764u; return 0; }
goto P_0c040772;
P_0c040766: /* original 0009, guest PC 0x0c040766 */
if(!s->budget--) { s->failed_pc=0x0c040766u; return 0; }
goto P_0c040768;
P_0c040768: /* original 62c3, guest PC 0x0c040768 */
if(!s->budget--) { s->failed_pc=0x0c040768u; return 0; }
r[2]=r[12];
goto P_0c04076a;
P_0c04076a: /* original 7c04, guest PC 0x0c04076a */
if(!s->budget--) { s->failed_pc=0x0c04076au; return 0; }
r[12]+=0x00000004u;
goto P_0c04076c;
P_0c04076c: /* original 63d6, guest PC 0x0c04076c */
if(!s->budget--) { s->failed_pc=0x0c04076cu; return 0; }
tmp=read(ram,r[13],4);
r[13]+=4;
r[3]=tmp;
goto P_0c04076e;
P_0c04076e: /* original 2232, guest PC 0x0c04076e */
if(!s->budget--) { s->failed_pc=0x0c04076eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040770;
P_0c040770: /* original 7e01, guest PC 0x0c040770 */
if(!s->budget--) { s->failed_pc=0x0c040770u; return 0; }
r[14]+=0x00000001u;
goto P_0c040772;
P_0c040772: /* original 52f3, guest PC 0x0c040772 */
if(!s->budget--) { s->failed_pc=0x0c040772u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c040774;
P_0c040774: /* original 4209, guest PC 0x0c040774 */
if(!s->budget--) { s->failed_pc=0x0c040774u; return 0; }
r[2]>>=2;
goto P_0c040776;
P_0c040776: /* original 3e22, guest PC 0x0c040776 */
if(!s->budget--) { s->failed_pc=0x0c040776u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c040778;
P_0c040778: /* original 8bf6, guest PC 0x0c040778 */
if(!s->budget--) { s->failed_pc=0x0c040778u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040768; }
goto P_0c04077a;
P_0c04077a: /* original e201, guest PC 0x0c04077a */
if(!s->budget--) { s->failed_pc=0x0c04077au; return 0; }
r[2]=0x00000001u;
goto P_0c04077c;
P_0c04077c: /* original d30b, guest PC 0x0c04077c */
if(!s->budget--) { s->failed_pc=0x0c04077cu; return 0; }
r[3]=read(ram,0x0c0407acu,4);
goto P_0c04077e;
P_0c04077e: /* original 2322, guest PC 0x0c04077e */
if(!s->budget--) { s->failed_pc=0x0c04077eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040780;
P_0c040780: /* original ee00, guest PC 0x0c040780 */
if(!s->budget--) { s->failed_pc=0x0c040780u; return 0; }
r[14]=0x00000000u;
goto P_0c040782;
P_0c040782: /* original a007, guest PC 0x0c040782 */
if(!s->budget--) { s->failed_pc=0x0c040782u; return 0; }
goto P_0c040794;
P_0c040784: /* original 0009, guest PC 0x0c040784 */
if(!s->budget--) { s->failed_pc=0x0c040784u; return 0; }
goto P_0c040786;
P_0c040786: /* original d207, guest PC 0x0c040786 */
if(!s->budget--) { s->failed_pc=0x0c040786u; return 0; }
r[2]=read(ram,0x0c0407a4u,4);
goto P_0c040788;
P_0c040788: /* original 6322, guest PC 0x0c040788 */
if(!s->budget--) { s->failed_pc=0x0c040788u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04078a;
P_0c04078a: /* original 2338, guest PC 0x0c04078a */
if(!s->budget--) { s->failed_pc=0x0c04078au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04078c;
P_0c04078c: /* original 8b01, guest PC 0x0c04078c */
if(!s->budget--) { s->failed_pc=0x0c04078cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040792; }
goto P_0c04078e;
P_0c04078e: /* original a00f, guest PC 0x0c04078e */
if(!s->budget--) { s->failed_pc=0x0c04078eu; return 0; }
goto P_0c0407b0;
P_0c040790: /* original 0009, guest PC 0x0c040790 */
if(!s->budget--) { s->failed_pc=0x0c040790u; return 0; }
goto P_0c040792;
P_0c040792: /* original 7e01, guest PC 0x0c040792 */
if(!s->budget--) { s->failed_pc=0x0c040792u; return 0; }
r[14]+=0x00000001u;
goto P_0c040794;
P_0c040794: /* original d204, guest PC 0x0c040794 */
if(!s->budget--) { s->failed_pc=0x0c040794u; return 0; }
r[2]=read(ram,0x0c0407a8u,4);
goto P_0c040796;
P_0c040796: /* original 3e23, guest PC 0x0c040796 */
if(!s->budget--) { s->failed_pc=0x0c040796u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c040798;
P_0c040798: /* original 8bf5, guest PC 0x0c040798 */
if(!s->budget--) { s->failed_pc=0x0c040798u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040786; }
goto P_0c04079a;
P_0c04079a: /* original 9001, guest PC 0x0c04079a */
if(!s->budget--) { s->failed_pc=0x0c04079au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0407a0u,2);
goto P_0c04079c;
P_0c04079c: /* original a00e, guest PC 0x0c04079c */
if(!s->budget--) { s->failed_pc=0x0c04079cu; return 0; }
goto P_0c0407bc;
P_0c04079e: /* original 0009, guest PC 0x0c04079e */
if(!s->budget--) { s->failed_pc=0x0c04079eu; return 0; }
return vf3_matrix_family(0x0c0407a0u,s,ram);
P_0c0407b0: /* original e200, guest PC 0x0c0407b0 */
if(!s->budget--) { s->failed_pc=0x0c0407b0u; return 0; }
r[2]=0x00000000u;
goto P_0c0407b2;
P_0c0407b2: /* original d30e, guest PC 0x0c0407b2 */
if(!s->budget--) { s->failed_pc=0x0c0407b2u; return 0; }
r[3]=read(ram,0x0c0407ecu,4);
goto P_0c0407b4;
P_0c0407b4: /* original 2322, guest PC 0x0c0407b4 */
if(!s->budget--) { s->failed_pc=0x0c0407b4u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0407b6;
P_0c0407b6: /* original e000, guest PC 0x0c0407b6 */
if(!s->budget--) { s->failed_pc=0x0c0407b6u; return 0; }
r[0]=0x00000000u;
goto P_0c0407b8;
P_0c0407b8: /* original a000, guest PC 0x0c0407b8 */
if(!s->budget--) { s->failed_pc=0x0c0407b8u; return 0; }
goto P_0c0407bc;
P_0c0407ba: /* original 0009, guest PC 0x0c0407ba */
if(!s->budget--) { s->failed_pc=0x0c0407bau; return 0; }
goto P_0c0407bc;
P_0c0407bc: /* original 7f1c, guest PC 0x0c0407bc */
if(!s->budget--) { s->failed_pc=0x0c0407bcu; return 0; }
r[15]+=0x0000001cu;
goto P_0c0407be;
P_0c0407be: /* original 4f26, guest PC 0x0c0407be */
if(!s->budget--) { s->failed_pc=0x0c0407beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0407c0;
P_0c0407c0: /* original 6cf6, guest PC 0x0c0407c0 */
if(!s->budget--) { s->failed_pc=0x0c0407c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0407c2;
P_0c0407c2: /* original 6df6, guest PC 0x0c0407c2 */
if(!s->budget--) { s->failed_pc=0x0c0407c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0407c4;
P_0c0407c4: /* original 6ef6, guest PC 0x0c0407c4 */
if(!s->budget--) { s->failed_pc=0x0c0407c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0407c6;
P_0c0407c6: /* original 000b, guest PC 0x0c0407c6 */
if(!s->budget--) { s->failed_pc=0x0c0407c6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0407c8: /* original 0009, guest PC 0x0c0407c8 */
if(!s->budget--) { s->failed_pc=0x0c0407c8u; return 0; }
return vf3_matrix_family(0x0c0407cau,s,ram);
P_0c04cece: /* original 2fe6, guest PC 0x0c04cece */
if(!s->budget--) { s->failed_pc=0x0c04ceceu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ced0;
P_0c04ced0: /* original 4f22, guest PC 0x0c04ced0 */
if(!s->budget--) { s->failed_pc=0x0c04ced0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ced2;
P_0c04ced2: /* original 9e41, guest PC 0x0c04ced2 */
if(!s->budget--) { s->failed_pc=0x0c04ced2u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cf58u,2);
goto P_0c04ced4;
P_0c04ced4: /* original d321, guest PC 0x0c04ced4 */
if(!s->budget--) { s->failed_pc=0x0c04ced4u; return 0; }
r[3]=read(ram,0x0c04cf5cu,4);
goto P_0c04ced6;
P_0c04ced6: /* original 4f12, guest PC 0x0c04ced6 */
if(!s->budget--) { s->failed_pc=0x0c04ced6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ced8;
P_0c04ced8: /* original 24ef, guest PC 0x0c04ced8 */
if(!s->budget--) { s->failed_pc=0x0c04ced8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c04ceda;
P_0c04ceda: /* original 2f46, guest PC 0x0c04ceda */
if(!s->budget--) { s->failed_pc=0x0c04cedau; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cedc;
P_0c04cedc: /* original d225, guest PC 0x0c04cedc */
if(!s->budget--) { s->failed_pc=0x0c04cedcu; return 0; }
r[2]=read(ram,0x0c04cf74u,4);
goto P_0c04cede;
P_0c04cede: /* original 0e1a, guest PC 0x0c04cede */
if(!s->budget--) { s->failed_pc=0x0c04cedeu; return 0; }
r[14]=r[19];
goto P_0c04cee0;
P_0c04cee0: /* original 6eef, guest PC 0x0c04cee0 */
if(!s->budget--) { s->failed_pc=0x0c04cee0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04cee2;
P_0c04cee2: /* original 3e3c, guest PC 0x0c04cee2 */
if(!s->budget--) { s->failed_pc=0x0c04cee2u; return 0; }
r[14]+=r[3];
goto P_0c04cee4;
P_0c04cee4: /* original bb5c, guest PC 0x0c04cee4 */
if(!s->budget--) { s->failed_pc=0x0c04cee4u; return 0; }
target=0x0c04c5a0u; r[16]=code_base|0x0c04cee8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cee8u) { target=s->pc; goto dispatch; }
goto P_0c04cee8;
P_0c04cee6: /* original 2f26, guest PC 0x0c04cee6 */
if(!s->budget--) { s->failed_pc=0x0c04cee6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cee8;
P_0c04cee8: /* original 84e2, guest PC 0x0c04cee8 */
if(!s->budget--) { s->failed_pc=0x0c04cee8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04ceea;
P_0c04ceea: /* original 2008, guest PC 0x0c04ceea */
if(!s->budget--) { s->failed_pc=0x0c04ceeau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ceec;
P_0c04ceec: /* original 8f03, guest PC 0x0c04ceec */
if(!s->budget--) { s->failed_pc=0x0c04ceecu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(!cond) { goto P_0c04cef6; }
goto P_0c04cef0;
P_0c04ceee: /* original 7f08, guest PC 0x0c04ceee */
if(!s->budget--) { s->failed_pc=0x0c04ceeeu; return 0; }
r[15]+=0x00000008u;
goto P_0c04cef0;
P_0c04cef0: /* original 9033, guest PC 0x0c04cef0 */
if(!s->budget--) { s->failed_pc=0x0c04cef0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cf5au,2);
goto P_0c04cef2;
P_0c04cef2: /* original a008, guest PC 0x0c04cef2 */
if(!s->budget--) { s->failed_pc=0x0c04cef2u; return 0; }
goto P_0c04cf06;
P_0c04cef4: /* original 0009, guest PC 0x0c04cef4 */
if(!s->budget--) { s->failed_pc=0x0c04cef4u; return 0; }
goto P_0c04cef6;
P_0c04cef6: /* original e400, guest PC 0x0c04cef6 */
if(!s->budget--) { s->failed_pc=0x0c04cef6u; return 0; }
r[4]=0x00000000u;
goto P_0c04cef8;
P_0c04cef8: /* original 6043, guest PC 0x0c04cef8 */
if(!s->budget--) { s->failed_pc=0x0c04cef8u; return 0; }
r[0]=r[4];
goto P_0c04cefa;
P_0c04cefa: /* original 80e9, guest PC 0x0c04cefa */
if(!s->budget--) { s->failed_pc=0x0c04cefau; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c04cefc;
P_0c04cefc: /* original 80e8, guest PC 0x0c04cefc */
if(!s->budget--) { s->failed_pc=0x0c04cefcu; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c04cefe;
P_0c04cefe: /* original 80ea, guest PC 0x0c04cefe */
if(!s->budget--) { s->failed_pc=0x0c04cefeu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04cf00;
P_0c04cf00: /* original 80eb, guest PC 0x0c04cf00 */
if(!s->budget--) { s->failed_pc=0x0c04cf00u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04cf02;
P_0c04cf02: /* original 80ec, guest PC 0x0c04cf02 */
if(!s->budget--) { s->failed_pc=0x0c04cf02u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04cf04;
P_0c04cf04: /* original 1e01, guest PC 0x0c04cf04 */
if(!s->budget--) { s->failed_pc=0x0c04cf04u; return 0; }
write(ram,r[14]+4,r[0],4);
goto P_0c04cf06;
P_0c04cf06: /* original 4f16, guest PC 0x0c04cf06 */
if(!s->budget--) { s->failed_pc=0x0c04cf06u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cf08;
P_0c04cf08: /* original 4f26, guest PC 0x0c04cf08 */
if(!s->budget--) { s->failed_pc=0x0c04cf08u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cf0a;
P_0c04cf0a: /* original 000b, guest PC 0x0c04cf0a */
if(!s->budget--) { s->failed_pc=0x0c04cf0au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04cf0c: /* original 6ef6, guest PC 0x0c04cf0c */
if(!s->budget--) { s->failed_pc=0x0c04cf0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04cf0eu,s,ram);
P_0c04ec8e: /* original 4f22, guest PC 0x0c04ec8e */
if(!s->budget--) { s->failed_pc=0x0c04ec8eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ec90;
P_0c04ec90: /* original 4f12, guest PC 0x0c04ec90 */
if(!s->budget--) { s->failed_pc=0x0c04ec90u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ec92;
P_0c04ec92: /* original 7fc4, guest PC 0x0c04ec92 */
if(!s->budget--) { s->failed_pc=0x0c04ec92u; return 0; }
r[15]+=0xffffffc4u;
goto P_0c04ec94;
P_0c04ec94: /* original 2f52, guest PC 0x0c04ec94 */
if(!s->budget--) { s->failed_pc=0x0c04ec94u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04ec96;
P_0c04ec96: /* original 1f61, guest PC 0x0c04ec96 */
if(!s->budget--) { s->failed_pc=0x0c04ec96u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c04ec98;
P_0c04ec98: /* original 9314, guest PC 0x0c04ec98 */
if(!s->budget--) { s->failed_pc=0x0c04ec98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ecc4u,2);
goto P_0c04ec9a;
P_0c04ec9a: /* original d012, guest PC 0x0c04ec9a */
if(!s->budget--) { s->failed_pc=0x0c04ec9au; return 0; }
r[0]=read(ram,0x0c04ece4u,4);
goto P_0c04ec9c;
P_0c04ec9c: /* original 2e3f, guest PC 0x0c04ec9c */
if(!s->budget--) { s->failed_pc=0x0c04ec9cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04ec9e;
P_0c04ec9e: /* original 031a, guest PC 0x0c04ec9e */
if(!s->budget--) { s->failed_pc=0x0c04ec9eu; return 0; }
r[3]=r[19];
goto P_0c04eca0;
P_0c04eca0: /* original 633f, guest PC 0x0c04eca0 */
if(!s->budget--) { s->failed_pc=0x0c04eca0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04eca2;
P_0c04eca2: /* original 023c, guest PC 0x0c04eca2 */
if(!s->budget--) { s->failed_pc=0x0c04eca2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04eca4;
P_0c04eca4: /* original 2228, guest PC 0x0c04eca4 */
if(!s->budget--) { s->failed_pc=0x0c04eca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04eca6;
P_0c04eca6: /* original 8930, guest PC 0x0c04eca6 */
if(!s->budget--) { s->failed_pc=0x0c04eca6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ed0a; }
goto P_0c04eca8;
P_0c04eca8: /* original d30f, guest PC 0x0c04eca8 */
if(!s->budget--) { s->failed_pc=0x0c04eca8u; return 0; }
r[3]=read(ram,0x0c04ece8u,4);
goto P_0c04ecaa;
P_0c04ecaa: /* original 430b, guest PC 0x0c04ecaa */
if(!s->budget--) { s->failed_pc=0x0c04ecaau; return 0; }
target=r[3];
r[16]=code_base|0x0c04ecaeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ecaeu) { target=s->pc; goto dispatch; }
goto P_0c04ecae;
P_0c04ecac: /* original 64e3, guest PC 0x0c04ecac */
if(!s->budget--) { s->failed_pc=0x0c04ecacu; return 0; }
r[4]=r[14];
goto P_0c04ecae;
P_0c04ecae: /* original 2008, guest PC 0x0c04ecae */
if(!s->budget--) { s->failed_pc=0x0c04ecaeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ecb0;
P_0c04ecb0: /* original 8b1e, guest PC 0x0c04ecb0 */
if(!s->budget--) { s->failed_pc=0x0c04ecb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ecf0; }
goto P_0c04ecb2;
P_0c04ecb2: /* original d30e, guest PC 0x0c04ecb2 */
if(!s->budget--) { s->failed_pc=0x0c04ecb2u; return 0; }
r[3]=read(ram,0x0c04ececu,4);
goto P_0c04ecb4;
P_0c04ecb4: /* original 430b, guest PC 0x0c04ecb4 */
if(!s->budget--) { s->failed_pc=0x0c04ecb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ecb8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ecb8u) { target=s->pc; goto dispatch; }
goto P_0c04ecb8;
P_0c04ecb6: /* original 64e3, guest PC 0x0c04ecb6 */
if(!s->budget--) { s->failed_pc=0x0c04ecb6u; return 0; }
r[4]=r[14];
goto P_0c04ecb8;
P_0c04ecb8: /* original a027, guest PC 0x0c04ecb8 */
if(!s->budget--) { s->failed_pc=0x0c04ecb8u; return 0; }
goto P_0c04ed0a;
P_0c04ecba: /* original 0009, guest PC 0x0c04ecba */
if(!s->budget--) { s->failed_pc=0x0c04ecbau; return 0; }
return vf3_matrix_family(0x0c04ecbcu,s,ram);
P_0c04ecf0: /* original d242, guest PC 0x0c04ecf0 */
if(!s->budget--) { s->failed_pc=0x0c04ecf0u; return 0; }
r[2]=read(ram,0x0c04edfcu,4);
goto P_0c04ecf2;
P_0c04ecf2: /* original 420b, guest PC 0x0c04ecf2 */
if(!s->budget--) { s->failed_pc=0x0c04ecf2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04ecf6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ecf6u) { target=s->pc; goto dispatch; }
goto P_0c04ecf6;
P_0c04ecf4: /* original 64e3, guest PC 0x0c04ecf4 */
if(!s->budget--) { s->failed_pc=0x0c04ecf4u; return 0; }
r[4]=r[14];
goto P_0c04ecf6;
P_0c04ecf6: /* original 2008, guest PC 0x0c04ecf6 */
if(!s->budget--) { s->failed_pc=0x0c04ecf6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ecf8;
P_0c04ecf8: /* original 8907, guest PC 0x0c04ecf8 */
if(!s->budget--) { s->failed_pc=0x0c04ecf8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ed0a; }
goto P_0c04ecfa;
P_0c04ecfa: /* original 937a, guest PC 0x0c04ecfa */
if(!s->budget--) { s->failed_pc=0x0c04ecfau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04edf2u,2);
goto P_0c04ecfc;
P_0c04ecfc: /* original d040, guest PC 0x0c04ecfc */
if(!s->budget--) { s->failed_pc=0x0c04ecfcu; return 0; }
r[0]=read(ram,0x0c04ee00u,4);
goto P_0c04ecfe;
P_0c04ecfe: /* original 2e3f, guest PC 0x0c04ecfe */
if(!s->budget--) { s->failed_pc=0x0c04ecfeu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04ed00;
P_0c04ed00: /* original 031a, guest PC 0x0c04ed00 */
if(!s->budget--) { s->failed_pc=0x0c04ed00u; return 0; }
r[3]=r[19];
goto P_0c04ed02;
P_0c04ed02: /* original 633f, guest PC 0x0c04ed02 */
if(!s->budget--) { s->failed_pc=0x0c04ed02u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04ed04;
P_0c04ed04: /* original 023c, guest PC 0x0c04ed04 */
if(!s->budget--) { s->failed_pc=0x0c04ed04u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04ed06;
P_0c04ed06: /* original 2228, guest PC 0x0c04ed06 */
if(!s->budget--) { s->failed_pc=0x0c04ed06u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04ed08;
P_0c04ed08: /* original 8b02, guest PC 0x0c04ed08 */
if(!s->budget--) { s->failed_pc=0x0c04ed08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ed10; }
goto P_0c04ed0a;
P_0c04ed0a: /* original 9073, guest PC 0x0c04ed0a */
if(!s->budget--) { s->failed_pc=0x0c04ed0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04edf4u,2);
goto P_0c04ed0c;
P_0c04ed0c: /* original a033, guest PC 0x0c04ed0c */
if(!s->budget--) { s->failed_pc=0x0c04ed0cu; return 0; }
goto P_0c04ed76;
P_0c04ed0e: /* original 0009, guest PC 0x0c04ed0e */
if(!s->budget--) { s->failed_pc=0x0c04ed0eu; return 0; }
goto P_0c04ed10;
P_0c04ed10: /* original d33c, guest PC 0x0c04ed10 */
if(!s->budget--) { s->failed_pc=0x0c04ed10u; return 0; }
r[3]=read(ram,0x0c04ee04u,4);
goto P_0c04ed12;
P_0c04ed12: /* original 430b, guest PC 0x0c04ed12 */
if(!s->budget--) { s->failed_pc=0x0c04ed12u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ed16u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ed16u) { target=s->pc; goto dispatch; }
goto P_0c04ed16;
P_0c04ed14: /* original 64e3, guest PC 0x0c04ed14 */
if(!s->budget--) { s->failed_pc=0x0c04ed14u; return 0; }
r[4]=r[14];
goto P_0c04ed16;
P_0c04ed16: /* original 4011, guest PC 0x0c04ed16 */
if(!s->budget--) { s->failed_pc=0x0c04ed16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ed18;
P_0c04ed18: /* original 8902, guest PC 0x0c04ed18 */
if(!s->budget--) { s->failed_pc=0x0c04ed18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ed20; }
goto P_0c04ed1a;
P_0c04ed1a: /* original 906c, guest PC 0x0c04ed1a */
if(!s->budget--) { s->failed_pc=0x0c04ed1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04edf6u,2);
goto P_0c04ed1c;
P_0c04ed1c: /* original a02b, guest PC 0x0c04ed1c */
if(!s->budget--) { s->failed_pc=0x0c04ed1cu; return 0; }
goto P_0c04ed76;
P_0c04ed1e: /* original 0009, guest PC 0x0c04ed1e */
if(!s->budget--) { s->failed_pc=0x0c04ed1eu; return 0; }
goto P_0c04ed20;
P_0c04ed20: /* original d339, guest PC 0x0c04ed20 */
if(!s->budget--) { s->failed_pc=0x0c04ed20u; return 0; }
r[3]=read(ram,0x0c04ee08u,4);
goto P_0c04ed22;
P_0c04ed22: /* original 65f2, guest PC 0x0c04ed22 */
if(!s->budget--) { s->failed_pc=0x0c04ed22u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04ed24;
P_0c04ed24: /* original 430b, guest PC 0x0c04ed24 */
if(!s->budget--) { s->failed_pc=0x0c04ed24u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ed28u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ed28u) { target=s->pc; goto dispatch; }
goto P_0c04ed28;
P_0c04ed26: /* original 64e3, guest PC 0x0c04ed26 */
if(!s->budget--) { s->failed_pc=0x0c04ed26u; return 0; }
r[4]=r[14];
goto P_0c04ed28;
P_0c04ed28: /* original 4011, guest PC 0x0c04ed28 */
if(!s->budget--) { s->failed_pc=0x0c04ed28u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ed2a;
P_0c04ed2a: /* original 8902, guest PC 0x0c04ed2a */
if(!s->budget--) { s->failed_pc=0x0c04ed2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ed32; }
goto P_0c04ed2c;
P_0c04ed2c: /* original 9064, guest PC 0x0c04ed2c */
if(!s->budget--) { s->failed_pc=0x0c04ed2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04edf8u,2);
goto P_0c04ed2e;
P_0c04ed2e: /* original a022, guest PC 0x0c04ed2e */
if(!s->budget--) { s->failed_pc=0x0c04ed2eu; return 0; }
goto P_0c04ed76;
P_0c04ed30: /* original 0009, guest PC 0x0c04ed30 */
if(!s->budget--) { s->failed_pc=0x0c04ed30u; return 0; }
goto P_0c04ed32;
P_0c04ed32: /* original 65f2, guest PC 0x0c04ed32 */
if(!s->budget--) { s->failed_pc=0x0c04ed32u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04ed34;
P_0c04ed34: /* original 66f3, guest PC 0x0c04ed34 */
if(!s->budget--) { s->failed_pc=0x0c04ed34u; return 0; }
r[6]=r[15];
goto P_0c04ed36;
P_0c04ed36: /* original 7610, guest PC 0x0c04ed36 */
if(!s->budget--) { s->failed_pc=0x0c04ed36u; return 0; }
r[6]+=0x00000010u;
goto P_0c04ed38;
P_0c04ed38: /* original b629, guest PC 0x0c04ed38 */
if(!s->budget--) { s->failed_pc=0x0c04ed38u; return 0; }
target=0x0c04f98eu; r[16]=code_base|0x0c04ed3cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ed3cu) { target=s->pc; goto dispatch; }
goto P_0c04ed3c;
P_0c04ed3a: /* original 64e3, guest PC 0x0c04ed3a */
if(!s->budget--) { s->failed_pc=0x0c04ed3au; return 0; }
r[4]=r[14];
goto P_0c04ed3c;
P_0c04ed3c: /* original 6503, guest PC 0x0c04ed3c */
if(!s->budget--) { s->failed_pc=0x0c04ed3cu; return 0; }
r[5]=r[0];
goto P_0c04ed3e;
P_0c04ed3e: /* original 4511, guest PC 0x0c04ed3e */
if(!s->budget--) { s->failed_pc=0x0c04ed3eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c04ed40;
P_0c04ed40: /* original 8902, guest PC 0x0c04ed40 */
if(!s->budget--) { s->failed_pc=0x0c04ed40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ed48; }
goto P_0c04ed42;
P_0c04ed42: /* original 905a, guest PC 0x0c04ed42 */
if(!s->budget--) { s->failed_pc=0x0c04ed42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04edfau,2);
goto P_0c04ed44;
P_0c04ed44: /* original a017, guest PC 0x0c04ed44 */
if(!s->budget--) { s->failed_pc=0x0c04ed44u; return 0; }
goto P_0c04ed76;
P_0c04ed46: /* original 0009, guest PC 0x0c04ed46 */
if(!s->budget--) { s->failed_pc=0x0c04ed46u; return 0; }
goto P_0c04ed48;
P_0c04ed48: /* original d330, guest PC 0x0c04ed48 */
if(!s->budget--) { s->failed_pc=0x0c04ed48u; return 0; }
r[3]=read(ram,0x0c04ee0cu,4);
goto P_0c04ed4a;
P_0c04ed4a: /* original 430b, guest PC 0x0c04ed4a */
if(!s->budget--) { s->failed_pc=0x0c04ed4au; return 0; }
target=r[3];
r[16]=code_base|0x0c04ed4eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ed4eu) { target=s->pc; goto dispatch; }
goto P_0c04ed4e;
P_0c04ed4c: /* original 64e3, guest PC 0x0c04ed4c */
if(!s->budget--) { s->failed_pc=0x0c04ed4cu; return 0; }
r[4]=r[14];
goto P_0c04ed4e;
P_0c04ed4e: /* original e710, guest PC 0x0c04ed4e */
if(!s->budget--) { s->failed_pc=0x0c04ed4eu; return 0; }
r[7]=0x00000010u;
goto P_0c04ed50;
P_0c04ed50: /* original 6403, guest PC 0x0c04ed50 */
if(!s->budget--) { s->failed_pc=0x0c04ed50u; return 0; }
r[4]=r[0];
goto P_0c04ed52;
P_0c04ed52: /* original 374c, guest PC 0x0c04ed52 */
if(!s->budget--) { s->failed_pc=0x0c04ed52u; return 0; }
r[7]+=r[4];
goto P_0c04ed54;
P_0c04ed54: /* original 64f3, guest PC 0x0c04ed54 */
if(!s->budget--) { s->failed_pc=0x0c04ed54u; return 0; }
r[4]=r[15];
goto P_0c04ed56;
P_0c04ed56: /* original 7408, guest PC 0x0c04ed56 */
if(!s->budget--) { s->failed_pc=0x0c04ed56u; return 0; }
r[4]+=0x00000008u;
goto P_0c04ed58;
P_0c04ed58: /* original e500, guest PC 0x0c04ed58 */
if(!s->budget--) { s->failed_pc=0x0c04ed58u; return 0; }
r[5]=0x00000000u;
goto P_0c04ed5a;
P_0c04ed5a: /* original a004, guest PC 0x0c04ed5a */
if(!s->budget--) { s->failed_pc=0x0c04ed5au; return 0; }
r[6]=0x00000008u;
goto P_0c04ed66;
P_0c04ed5c: /* original e608, guest PC 0x0c04ed5c */
if(!s->budget--) { s->failed_pc=0x0c04ed5cu; return 0; }
r[6]=0x00000008u;
goto P_0c04ed5e;
P_0c04ed5e: /* original 6374, guest PC 0x0c04ed5e */
if(!s->budget--) { s->failed_pc=0x0c04ed5eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04ed60;
P_0c04ed60: /* original 7501, guest PC 0x0c04ed60 */
if(!s->budget--) { s->failed_pc=0x0c04ed60u; return 0; }
r[5]+=0x00000001u;
goto P_0c04ed62;
P_0c04ed62: /* original 2430, guest PC 0x0c04ed62 */
if(!s->budget--) { s->failed_pc=0x0c04ed62u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04ed64;
P_0c04ed64: /* original 7401, guest PC 0x0c04ed64 */
if(!s->budget--) { s->failed_pc=0x0c04ed64u; return 0; }
r[4]+=0x00000001u;
goto P_0c04ed66;
P_0c04ed66: /* original 3563, guest PC 0x0c04ed66 */
if(!s->budget--) { s->failed_pc=0x0c04ed66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04ed68;
P_0c04ed68: /* original 8bf9, guest PC 0x0c04ed68 */
if(!s->budget--) { s->failed_pc=0x0c04ed68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ed5e; }
goto P_0c04ed6a;
P_0c04ed6a: /* original d329, guest PC 0x0c04ed6a */
if(!s->budget--) { s->failed_pc=0x0c04ed6au; return 0; }
r[3]=read(ram,0x0c04ee10u,4);
goto P_0c04ed6c;
P_0c04ed6c: /* original 65f3, guest PC 0x0c04ed6c */
if(!s->budget--) { s->failed_pc=0x0c04ed6cu; return 0; }
r[5]=r[15];
goto P_0c04ed6e;
P_0c04ed6e: /* original 7508, guest PC 0x0c04ed6e */
if(!s->budget--) { s->failed_pc=0x0c04ed6eu; return 0; }
r[5]+=0x00000008u;
goto P_0c04ed70;
P_0c04ed70: /* original 430b, guest PC 0x0c04ed70 */
if(!s->budget--) { s->failed_pc=0x0c04ed70u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ed74u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ed74u) { target=s->pc; goto dispatch; }
goto P_0c04ed74;
P_0c04ed72: /* original 54f1, guest PC 0x0c04ed72 */
if(!s->budget--) { s->failed_pc=0x0c04ed72u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04ed74;
P_0c04ed74: /* original e000, guest PC 0x0c04ed74 */
if(!s->budget--) { s->failed_pc=0x0c04ed74u; return 0; }
r[0]=0x00000000u;
goto P_0c04ed76;
P_0c04ed76: /* original 7f3c, guest PC 0x0c04ed76 */
if(!s->budget--) { s->failed_pc=0x0c04ed76u; return 0; }
r[15]+=0x0000003cu;
goto P_0c04ed78;
P_0c04ed78: /* original 4f16, guest PC 0x0c04ed78 */
if(!s->budget--) { s->failed_pc=0x0c04ed78u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ed7a;
P_0c04ed7a: /* original 4f26, guest PC 0x0c04ed7a */
if(!s->budget--) { s->failed_pc=0x0c04ed7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ed7c;
P_0c04ed7c: /* original 000b, guest PC 0x0c04ed7c */
if(!s->budget--) { s->failed_pc=0x0c04ed7cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04ed7e: /* original 6ef6, guest PC 0x0c04ed7e */
if(!s->budget--) { s->failed_pc=0x0c04ed7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04ed80u,s,ram);
P_0c04f98e: /* original 2fe6, guest PC 0x0c04f98e */
if(!s->budget--) { s->failed_pc=0x0c04f98eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f990;
P_0c04f990: /* original 2fd6, guest PC 0x0c04f990 */
if(!s->budget--) { s->failed_pc=0x0c04f990u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f992;
P_0c04f992: /* original 2fc6, guest PC 0x0c04f992 */
if(!s->budget--) { s->failed_pc=0x0c04f992u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f994;
P_0c04f994: /* original 2fb6, guest PC 0x0c04f994 */
if(!s->budget--) { s->failed_pc=0x0c04f994u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f996;
P_0c04f996: /* original 6b53, guest PC 0x0c04f996 */
if(!s->budget--) { s->failed_pc=0x0c04f996u; return 0; }
r[11]=r[5];
goto P_0c04f998;
P_0c04f998: /* original 2fa6, guest PC 0x0c04f998 */
if(!s->budget--) { s->failed_pc=0x0c04f998u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f99a;
P_0c04f99a: /* original 4f22, guest PC 0x0c04f99a */
if(!s->budget--) { s->failed_pc=0x0c04f99au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f99c;
P_0c04f99c: /* original 4f12, guest PC 0x0c04f99c */
if(!s->budget--) { s->failed_pc=0x0c04f99cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f99e;
P_0c04f99e: /* original 7ffc, guest PC 0x0c04f99e */
if(!s->budget--) { s->failed_pc=0x0c04f99eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04f9a0;
P_0c04f9a0: /* original 2f62, guest PC 0x0c04f9a0 */
if(!s->budget--) { s->failed_pc=0x0c04f9a0u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04f9a2;
P_0c04f9a2: /* original 9c19, guest PC 0x0c04f9a2 */
if(!s->budget--) { s->failed_pc=0x0c04f9a2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f9d8u,2);
goto P_0c04f9a4;
P_0c04f9a4: /* original d30e, guest PC 0x0c04f9a4 */
if(!s->budget--) { s->failed_pc=0x0c04f9a4u; return 0; }
r[3]=read(ram,0x0c04f9e0u,4);
goto P_0c04f9a6;
P_0c04f9a6: /* original 24cf, guest PC 0x0c04f9a6 */
if(!s->budget--) { s->failed_pc=0x0c04f9a6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[12]);
goto P_0c04f9a8;
P_0c04f9a8: /* original 2fb6, guest PC 0x0c04f9a8 */
if(!s->budget--) { s->failed_pc=0x0c04f9a8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f9aa;
P_0c04f9aa: /* original d10f, guest PC 0x0c04f9aa */
if(!s->budget--) { s->failed_pc=0x0c04f9aau; return 0; }
r[1]=read(ram,0x0c04f9e8u,4);
goto P_0c04f9ac;
P_0c04f9ac: /* original d20d, guest PC 0x0c04f9ac */
if(!s->budget--) { s->failed_pc=0x0c04f9acu; return 0; }
r[2]=read(ram,0x0c04f9e4u,4);
goto P_0c04f9ae;
P_0c04f9ae: /* original 0c1a, guest PC 0x0c04f9ae */
if(!s->budget--) { s->failed_pc=0x0c04f9aeu; return 0; }
r[12]=r[19];
goto P_0c04f9b0;
P_0c04f9b0: /* original 6ccf, guest PC 0x0c04f9b0 */
if(!s->budget--) { s->failed_pc=0x0c04f9b0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04f9b2;
P_0c04f9b2: /* original 3c3c, guest PC 0x0c04f9b2 */
if(!s->budget--) { s->failed_pc=0x0c04f9b2u; return 0; }
r[12]+=r[3];
goto P_0c04f9b4;
P_0c04f9b4: /* original 410b, guest PC 0x0c04f9b4 */
if(!s->budget--) { s->failed_pc=0x0c04f9b4u; return 0; }
target=r[1];
r[16]=code_base|0x0c04f9b8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f9b8u) { target=s->pc; goto dispatch; }
goto P_0c04f9b8;
P_0c04f9b6: /* original 2f26, guest PC 0x0c04f9b6 */
if(!s->budget--) { s->failed_pc=0x0c04f9b6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f9b8;
P_0c04f9b8: /* original da0c, guest PC 0x0c04f9b8 */
if(!s->budget--) { s->failed_pc=0x0c04f9b8u; return 0; }
r[10]=read(ram,0x0c04f9ecu,4);
goto P_0c04f9ba;
P_0c04f9ba: /* original 7f08, guest PC 0x0c04f9ba */
if(!s->budget--) { s->failed_pc=0x0c04f9bau; return 0; }
r[15]+=0x00000008u;
goto P_0c04f9bc;
P_0c04f9bc: /* original 5eca, guest PC 0x0c04f9bc */
if(!s->budget--) { s->failed_pc=0x0c04f9bcu; return 0; }
r[14]=read(ram,r[12]+40,4);
goto P_0c04f9be;
P_0c04f9be: /* original a028, guest PC 0x0c04f9be */
if(!s->budget--) { s->failed_pc=0x0c04f9beu; return 0; }
r[13]=0x00000000u;
goto P_0c04fa12;
P_0c04f9c0: /* original ed00, guest PC 0x0c04f9c0 */
if(!s->budget--) { s->failed_pc=0x0c04f9c0u; return 0; }
r[13]=0x00000000u;
goto P_0c04f9c2;
P_0c04f9c2: /* original 64e0, guest PC 0x0c04f9c2 */
if(!s->budget--) { s->failed_pc=0x0c04f9c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c04f9c4;
P_0c04f9c4: /* original 604c, guest PC 0x0c04f9c4 */
if(!s->budget--) { s->failed_pc=0x0c04f9c4u; return 0; }
r[0]=r[4]&255u;
goto P_0c04f9c6;
P_0c04f9c6: /* original 8800, guest PC 0x0c04f9c6 */
if(!s->budget--) { s->failed_pc=0x0c04f9c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04f9c8;
P_0c04f9c8: /* original 8921, guest PC 0x0c04f9c8 */
if(!s->budget--) { s->failed_pc=0x0c04f9c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fa0e; }
goto P_0c04f9ca;
P_0c04f9ca: /* original 8833, guest PC 0x0c04f9ca */
if(!s->budget--) { s->failed_pc=0x0c04f9cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000033u)!=0);
goto P_0c04f9cc;
P_0c04f9cc: /* original 8910, guest PC 0x0c04f9cc */
if(!s->budget--) { s->failed_pc=0x0c04f9ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f9f0; }
goto P_0c04f9ce;
P_0c04f9ce: /* original 9104, guest PC 0x0c04f9ce */
if(!s->budget--) { s->failed_pc=0x0c04f9ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f9dau,2);
goto P_0c04f9d0;
P_0c04f9d0: /* original 3010, guest PC 0x0c04f9d0 */
if(!s->budget--) { s->failed_pc=0x0c04f9d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f9d2;
P_0c04f9d2: /* original 890d, guest PC 0x0c04f9d2 */
if(!s->budget--) { s->failed_pc=0x0c04f9d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f9f0; }
goto P_0c04f9d4;
P_0c04f9d4: /* original a01b, guest PC 0x0c04f9d4 */
if(!s->budget--) { s->failed_pc=0x0c04f9d4u; return 0; }
goto P_0c04fa0e;
P_0c04f9d6: /* original 0009, guest PC 0x0c04f9d6 */
if(!s->budget--) { s->failed_pc=0x0c04f9d6u; return 0; }
return vf3_matrix_family(0x0c04f9d8u,s,ram);
P_0c04f9f0: /* original 65e3, guest PC 0x0c04f9f0 */
if(!s->budget--) { s->failed_pc=0x0c04f9f0u; return 0; }
r[5]=r[14];
goto P_0c04f9f2;
P_0c04f9f2: /* original 7504, guest PC 0x0c04f9f2 */
if(!s->budget--) { s->failed_pc=0x0c04f9f2u; return 0; }
r[5]+=0x00000004u;
goto P_0c04f9f4;
P_0c04f9f4: /* original bf62, guest PC 0x0c04f9f4 */
if(!s->budget--) { s->failed_pc=0x0c04f9f4u; return 0; }
target=0x0c04f8bcu; r[16]=code_base|0x0c04f9f8u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f9f8u) { target=s->pc; goto dispatch; }
goto P_0c04f9f8;
P_0c04f9f6: /* original 64b3, guest PC 0x0c04f9f6 */
if(!s->budget--) { s->failed_pc=0x0c04f9f6u; return 0; }
r[4]=r[11];
goto P_0c04f9f8;
P_0c04f9f8: /* original 2008, guest PC 0x0c04f9f8 */
if(!s->budget--) { s->failed_pc=0x0c04f9f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f9fa;
P_0c04f9fa: /* original 8908, guest PC 0x0c04f9fa */
if(!s->budget--) { s->failed_pc=0x0c04f9fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fa0e; }
goto P_0c04f9fc;
P_0c04f9fc: /* original 65f2, guest PC 0x0c04f9fc */
if(!s->budget--) { s->failed_pc=0x0c04f9fcu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f9fe;
P_0c04f9fe: /* original bf82, guest PC 0x0c04f9fe */
if(!s->budget--) { s->failed_pc=0x0c04f9feu; return 0; }
target=0x0c04f906u; r[16]=code_base|0x0c04fa02u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fa02u) { target=s->pc; goto dispatch; }
goto P_0c04fa02;
P_0c04fa00: /* original 64e3, guest PC 0x0c04fa00 */
if(!s->budget--) { s->failed_pc=0x0c04fa00u; return 0; }
r[4]=r[14];
goto P_0c04fa02;
P_0c04fa02: /* original d239, guest PC 0x0c04fa02 */
if(!s->budget--) { s->failed_pc=0x0c04fa02u; return 0; }
r[2]=read(ram,0x0c04fae8u,4);
goto P_0c04fa04;
P_0c04fa04: /* original 420b, guest PC 0x0c04fa04 */
if(!s->budget--) { s->failed_pc=0x0c04fa04u; return 0; }
target=r[2];
r[16]=code_base|0x0c04fa08u;
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fa08u) { target=s->pc; goto dispatch; }
goto P_0c04fa08;
P_0c04fa06: /* original 2fa6, guest PC 0x0c04fa06 */
if(!s->budget--) { s->failed_pc=0x0c04fa06u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa08;
P_0c04fa08: /* original 7f04, guest PC 0x0c04fa08 */
if(!s->budget--) { s->failed_pc=0x0c04fa08u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa0a;
P_0c04fa0a: /* original a00c, guest PC 0x0c04fa0a */
if(!s->budget--) { s->failed_pc=0x0c04fa0au; return 0; }
r[0]=r[13];
goto P_0c04fa26;
P_0c04fa0c: /* original 60d3, guest PC 0x0c04fa0c */
if(!s->budget--) { s->failed_pc=0x0c04fa0cu; return 0; }
r[0]=r[13];
goto P_0c04fa0e;
P_0c04fa0e: /* original 7e20, guest PC 0x0c04fa0e */
if(!s->budget--) { s->failed_pc=0x0c04fa0eu; return 0; }
r[14]+=0x00000020u;
goto P_0c04fa10;
P_0c04fa10: /* original 7d01, guest PC 0x0c04fa10 */
if(!s->budget--) { s->failed_pc=0x0c04fa10u; return 0; }
r[13]+=0x00000001u;
goto P_0c04fa12;
P_0c04fa12: /* original 52c7, guest PC 0x0c04fa12 */
if(!s->budget--) { s->failed_pc=0x0c04fa12u; return 0; }
r[2]=read(ram,r[12]+28,4);
goto P_0c04fa14;
P_0c04fa14: /* original 532c, guest PC 0x0c04fa14 */
if(!s->budget--) { s->failed_pc=0x0c04fa14u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04fa16;
P_0c04fa16: /* original 3d33, guest PC 0x0c04fa16 */
if(!s->budget--) { s->failed_pc=0x0c04fa16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c04fa18;
P_0c04fa18: /* original 8bd3, guest PC 0x0c04fa18 */
if(!s->budget--) { s->failed_pc=0x0c04fa18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f9c2; }
goto P_0c04fa1a;
P_0c04fa1a: /* original d333, guest PC 0x0c04fa1a */
if(!s->budget--) { s->failed_pc=0x0c04fa1au; return 0; }
r[3]=read(ram,0x0c04fae8u,4);
goto P_0c04fa1c;
P_0c04fa1c: /* original d133, guest PC 0x0c04fa1c */
if(!s->budget--) { s->failed_pc=0x0c04fa1cu; return 0; }
r[1]=read(ram,0x0c04faecu,4);
goto P_0c04fa1e;
P_0c04fa1e: /* original 430b, guest PC 0x0c04fa1e */
if(!s->budget--) { s->failed_pc=0x0c04fa1eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04fa22u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fa22u) { target=s->pc; goto dispatch; }
goto P_0c04fa22;
P_0c04fa20: /* original 2f16, guest PC 0x0c04fa20 */
if(!s->budget--) { s->failed_pc=0x0c04fa20u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa22;
P_0c04fa22: /* original e0ff, guest PC 0x0c04fa22 */
if(!s->budget--) { s->failed_pc=0x0c04fa22u; return 0; }
r[0]=0xffffffffu;
goto P_0c04fa24;
P_0c04fa24: /* original 7f04, guest PC 0x0c04fa24 */
if(!s->budget--) { s->failed_pc=0x0c04fa24u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa26;
P_0c04fa26: /* original 7f04, guest PC 0x0c04fa26 */
if(!s->budget--) { s->failed_pc=0x0c04fa26u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa28;
P_0c04fa28: /* original 4f16, guest PC 0x0c04fa28 */
if(!s->budget--) { s->failed_pc=0x0c04fa28u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa2a;
P_0c04fa2a: /* original 4f26, guest PC 0x0c04fa2a */
if(!s->budget--) { s->failed_pc=0x0c04fa2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa2c;
P_0c04fa2c: /* original 6af6, guest PC 0x0c04fa2c */
if(!s->budget--) { s->failed_pc=0x0c04fa2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fa2e;
P_0c04fa2e: /* original 6bf6, guest PC 0x0c04fa2e */
if(!s->budget--) { s->failed_pc=0x0c04fa2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fa30;
P_0c04fa30: /* original 6cf6, guest PC 0x0c04fa30 */
if(!s->budget--) { s->failed_pc=0x0c04fa30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fa32;
P_0c04fa32: /* original 6df6, guest PC 0x0c04fa32 */
if(!s->budget--) { s->failed_pc=0x0c04fa32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fa34;
P_0c04fa34: /* original 000b, guest PC 0x0c04fa34 */
if(!s->budget--) { s->failed_pc=0x0c04fa34u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fa36: /* original 6ef6, guest PC 0x0c04fa36 */
if(!s->budget--) { s->failed_pc=0x0c04fa36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04fa38u,s,ram);
P_0c053ca4: /* original 2fe6, guest PC 0x0c053ca4 */
if(!s->budget--) { s->failed_pc=0x0c053ca4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053ca6;
P_0c053ca6: /* original 6e43, guest PC 0x0c053ca6 */
if(!s->budget--) { s->failed_pc=0x0c053ca6u; return 0; }
r[14]=r[4];
goto P_0c053ca8;
P_0c053ca8: /* original d026, guest PC 0x0c053ca8 */
if(!s->budget--) { s->failed_pc=0x0c053ca8u; return 0; }
r[0]=read(ram,0x0c053d44u,4);
goto P_0c053caa;
P_0c053caa: /* original 4e08, guest PC 0x0c053caa */
if(!s->budget--) { s->failed_pc=0x0c053caau; return 0; }
r[14]<<=2;
goto P_0c053cac;
P_0c053cac: /* original 4f22, guest PC 0x0c053cac */
if(!s->budget--) { s->failed_pc=0x0c053cacu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053cae;
P_0c053cae: /* original 0eee, guest PC 0x0c053cae */
if(!s->budget--) { s->failed_pc=0x0c053caeu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c053cb0;
P_0c053cb0: /* original d325, guest PC 0x0c053cb0 */
if(!s->budget--) { s->failed_pc=0x0c053cb0u; return 0; }
r[3]=read(ram,0x0c053d48u,4);
goto P_0c053cb2;
P_0c053cb2: /* original 7ffc, guest PC 0x0c053cb2 */
if(!s->budget--) { s->failed_pc=0x0c053cb2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c053cb4;
P_0c053cb4: /* original 430b, guest PC 0x0c053cb4 */
if(!s->budget--) { s->failed_pc=0x0c053cb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c053cb8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053cb8u) { target=s->pc; goto dispatch; }
goto P_0c053cb8;
P_0c053cb6: /* original 64e3, guest PC 0x0c053cb6 */
if(!s->budget--) { s->failed_pc=0x0c053cb6u; return 0; }
r[4]=r[14];
goto P_0c053cb8;
P_0c053cb8: /* original 2f02, guest PC 0x0c053cb8 */
if(!s->budget--) { s->failed_pc=0x0c053cb8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c053cba;
P_0c053cba: /* original d324, guest PC 0x0c053cba */
if(!s->budget--) { s->failed_pc=0x0c053cbau; return 0; }
r[3]=read(ram,0x0c053d4cu,4);
goto P_0c053cbc;
P_0c053cbc: /* original 430b, guest PC 0x0c053cbc */
if(!s->budget--) { s->failed_pc=0x0c053cbcu; return 0; }
target=r[3];
r[16]=code_base|0x0c053cc0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053cc0u) { target=s->pc; goto dispatch; }
goto P_0c053cc0;
P_0c053cbe: /* original 64e3, guest PC 0x0c053cbe */
if(!s->budget--) { s->failed_pc=0x0c053cbeu; return 0; }
r[4]=r[14];
goto P_0c053cc0;
P_0c053cc0: /* original 62f2, guest PC 0x0c053cc0 */
if(!s->budget--) { s->failed_pc=0x0c053cc0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c053cc2;
P_0c053cc2: /* original 6403, guest PC 0x0c053cc2 */
if(!s->budget--) { s->failed_pc=0x0c053cc2u; return 0; }
r[4]=r[0];
goto P_0c053cc4;
P_0c053cc4: /* original 6320, guest PC 0x0c053cc4 */
if(!s->budget--) { s->failed_pc=0x0c053cc4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c053cc6;
P_0c053cc6: /* original 2338, guest PC 0x0c053cc6 */
if(!s->budget--) { s->failed_pc=0x0c053cc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c053cc8;
P_0c053cc8: /* original 8902, guest PC 0x0c053cc8 */
if(!s->budget--) { s->failed_pc=0x0c053cc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053cd0; }
goto P_0c053cca;
P_0c053cca: /* original 6042, guest PC 0x0c053cca */
if(!s->budget--) { s->failed_pc=0x0c053ccau; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c053ccc;
P_0c053ccc: /* original c802, guest PC 0x0c053ccc */
if(!s->budget--) { s->failed_pc=0x0c053cccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c053cce;
P_0c053cce: /* original 8b04, guest PC 0x0c053cce */
if(!s->budget--) { s->failed_pc=0x0c053cceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053cda; }
goto P_0c053cd0;
P_0c053cd0: /* original 7f04, guest PC 0x0c053cd0 */
if(!s->budget--) { s->failed_pc=0x0c053cd0u; return 0; }
r[15]+=0x00000004u;
goto P_0c053cd2;
P_0c053cd2: /* original 4f26, guest PC 0x0c053cd2 */
if(!s->budget--) { s->failed_pc=0x0c053cd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053cd4;
P_0c053cd4: /* original e000, guest PC 0x0c053cd4 */
if(!s->budget--) { s->failed_pc=0x0c053cd4u; return 0; }
r[0]=0x00000000u;
goto P_0c053cd6;
P_0c053cd6: /* original 000b, guest PC 0x0c053cd6 */
if(!s->budget--) { s->failed_pc=0x0c053cd6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053cd8: /* original 6ef6, guest PC 0x0c053cd8 */
if(!s->budget--) { s->failed_pc=0x0c053cd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c053cda;
P_0c053cda: /* original e001, guest PC 0x0c053cda */
if(!s->budget--) { s->failed_pc=0x0c053cdau; return 0; }
r[0]=0x00000001u;
goto P_0c053cdc;
P_0c053cdc: /* original 7f04, guest PC 0x0c053cdc */
if(!s->budget--) { s->failed_pc=0x0c053cdcu; return 0; }
r[15]+=0x00000004u;
goto P_0c053cde;
P_0c053cde: /* original 4f26, guest PC 0x0c053cde */
if(!s->budget--) { s->failed_pc=0x0c053cdeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053ce0;
P_0c053ce0: /* original 000b, guest PC 0x0c053ce0 */
if(!s->budget--) { s->failed_pc=0x0c053ce0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053ce2: /* original 6ef6, guest PC 0x0c053ce2 */
if(!s->budget--) { s->failed_pc=0x0c053ce2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c053ce4u,s,ram);
P_0c05961e: /* original 4f22, guest PC 0x0c05961e */
if(!s->budget--) { s->failed_pc=0x0c05961eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059620;
P_0c059620: /* original d320, guest PC 0x0c059620 */
if(!s->budget--) { s->failed_pc=0x0c059620u; return 0; }
r[3]=read(ram,0x0c0596a4u,4);
goto P_0c059622;
P_0c059622: /* original 7ff8, guest PC 0x0c059622 */
if(!s->budget--) { s->failed_pc=0x0c059622u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059624;
P_0c059624: /* original 2f42, guest PC 0x0c059624 */
if(!s->budget--) { s->failed_pc=0x0c059624u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c059626;
P_0c059626: /* original 6032, guest PC 0x0c059626 */
if(!s->budget--) { s->failed_pc=0x0c059626u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059628;
P_0c059628: /* original c802, guest PC 0x0c059628 */
if(!s->budget--) { s->failed_pc=0x0c059628u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c05962a;
P_0c05962a: /* original 8d08, guest PC 0x0c05962a */
if(!s->budget--) { s->failed_pc=0x0c05962au; return 0; }
cond=r[17]&1u;
r[14]=0x00000001u;
if(cond) { goto P_0c05963e; }
goto P_0c05962e;
P_0c05962c: /* original ee01, guest PC 0x0c05962c */
if(!s->budget--) { s->failed_pc=0x0c05962cu; return 0; }
r[14]=0x00000001u;
goto P_0c05962e;
P_0c05962e: /* original 942c, guest PC 0x0c05962e */
if(!s->budget--) { s->failed_pc=0x0c05962eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05968au,2);
goto P_0c059630;
P_0c059630: /* original d11d, guest PC 0x0c059630 */
if(!s->budget--) { s->failed_pc=0x0c059630u; return 0; }
r[1]=read(ram,0x0c0596a8u,4);
goto P_0c059632;
P_0c059632: /* original 410b, guest PC 0x0c059632 */
if(!s->budget--) { s->failed_pc=0x0c059632u; return 0; }
target=r[1];
r[16]=code_base|0x0c059636u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059636u) { target=s->pc; goto dispatch; }
goto P_0c059636;
P_0c059634: /* original 0009, guest PC 0x0c059634 */
if(!s->budget--) { s->failed_pc=0x0c059634u; return 0; }
goto P_0c059636;
P_0c059636: /* original 6403, guest PC 0x0c059636 */
if(!s->budget--) { s->failed_pc=0x0c059636u; return 0; }
r[4]=r[0];
goto P_0c059638;
P_0c059638: /* original 9525, guest PC 0x0c059638 */
if(!s->budget--) { s->failed_pc=0x0c059638u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059686u,2);
goto P_0c05963a;
P_0c05963a: /* original a001, guest PC 0x0c05963a */
if(!s->budget--) { s->failed_pc=0x0c05963au; return 0; }
r[5]&=r[4];
goto P_0c059640;
P_0c05963c: /* original 2549, guest PC 0x0c05963c */
if(!s->budget--) { s->failed_pc=0x0c05963cu; return 0; }
r[5]&=r[4];
goto P_0c05963e;
P_0c05963e: /* original e500, guest PC 0x0c05963e */
if(!s->budget--) { s->failed_pc=0x0c05963eu; return 0; }
r[5]=0x00000000u;
goto P_0c059640;
P_0c059640: /* original d21a, guest PC 0x0c059640 */
if(!s->budget--) { s->failed_pc=0x0c059640u; return 0; }
r[2]=read(ram,0x0c0596acu,4);
goto P_0c059642;
P_0c059642: /* original 6322, guest PC 0x0c059642 */
if(!s->budget--) { s->failed_pc=0x0c059642u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059644;
P_0c059644: /* original d11a, guest PC 0x0c059644 */
if(!s->budget--) { s->failed_pc=0x0c059644u; return 0; }
r[1]=read(ram,0x0c0596b0u,4);
goto P_0c059646;
P_0c059646: /* original 6612, guest PC 0x0c059646 */
if(!s->budget--) { s->failed_pc=0x0c059646u; return 0; }
tmp=read(ram,r[1],4);
r[6]=tmp;
goto P_0c059648;
P_0c059648: /* original 363c, guest PC 0x0c059648 */
if(!s->budget--) { s->failed_pc=0x0c059648u; return 0; }
r[6]+=r[3];
goto P_0c05964a;
P_0c05964a: /* original d312, guest PC 0x0c05964a */
if(!s->budget--) { s->failed_pc=0x0c05964au; return 0; }
r[3]=read(ram,0x0c059694u,4);
goto P_0c05964c;
P_0c05964c: /* original 6032, guest PC 0x0c05964c */
if(!s->budget--) { s->failed_pc=0x0c05964cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05964e;
P_0c05964e: /* original 20e9, guest PC 0x0c05964e */
if(!s->budget--) { s->failed_pc=0x0c05964eu; return 0; }
r[0]&=r[14];
goto P_0c059650;
P_0c059650: /* original 8801, guest PC 0x0c059650 */
if(!s->budget--) { s->failed_pc=0x0c059650u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059652;
P_0c059652: /* original 8f05, guest PC 0x0c059652 */
if(!s->budget--) { s->failed_pc=0x0c059652u; return 0; }
cond=r[17]&1u;
fr[4]=0x3f800000u;
if(!cond) { goto P_0c059660; }
goto P_0c059656;
P_0c059654: /* original f49d, guest PC 0x0c059654 */
if(!s->budget--) { s->failed_pc=0x0c059654u; return 0; }
fr[4]=0x3f800000u;
goto P_0c059656;
P_0c059656: /* original 2ee8, guest PC 0x0c059656 */
if(!s->budget--) { s->failed_pc=0x0c059656u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c059658;
P_0c059658: /* original 8902, guest PC 0x0c059658 */
if(!s->budget--) { s->failed_pc=0x0c059658u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059660; }
goto P_0c05965a;
P_0c05965a: /* original 9717, guest PC 0x0c05965a */
if(!s->budget--) { s->failed_pc=0x0c05965au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05968cu,2);
goto P_0c05965c;
P_0c05965c: /* original a02e, guest PC 0x0c05965c */
if(!s->budget--) { s->failed_pc=0x0c05965cu; return 0; }
goto P_0c0596bc;
P_0c05965e: /* original 0009, guest PC 0x0c05965e */
if(!s->budget--) { s->failed_pc=0x0c05965eu; return 0; }
goto P_0c059660;
P_0c059660: /* original d30c, guest PC 0x0c059660 */
if(!s->budget--) { s->failed_pc=0x0c059660u; return 0; }
r[3]=read(ram,0x0c059694u,4);
goto P_0c059662;
P_0c059662: /* original 6032, guest PC 0x0c059662 */
if(!s->budget--) { s->failed_pc=0x0c059662u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059664;
P_0c059664: /* original 20e9, guest PC 0x0c059664 */
if(!s->budget--) { s->failed_pc=0x0c059664u; return 0; }
r[0]&=r[14];
goto P_0c059666;
P_0c059666: /* original 8801, guest PC 0x0c059666 */
if(!s->budget--) { s->failed_pc=0x0c059666u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059668;
P_0c059668: /* original 8927, guest PC 0x0c059668 */
if(!s->budget--) { s->failed_pc=0x0c059668u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0596ba; }
goto P_0c05966a;
P_0c05966a: /* original d20a, guest PC 0x0c05966a */
if(!s->budget--) { s->failed_pc=0x0c05966au; return 0; }
r[2]=read(ram,0x0c059694u,4);
goto P_0c05966c;
P_0c05966c: /* original 6022, guest PC 0x0c05966c */
if(!s->budget--) { s->failed_pc=0x0c05966cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05966e;
P_0c05966e: /* original c82c, guest PC 0x0c05966e */
if(!s->budget--) { s->failed_pc=0x0c05966eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c059670;
P_0c059670: /* original 8923, guest PC 0x0c059670 */
if(!s->budget--) { s->failed_pc=0x0c059670u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0596ba; }
goto P_0c059672;
P_0c059672: /* original 2ee8, guest PC 0x0c059672 */
if(!s->budget--) { s->failed_pc=0x0c059672u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c059674;
P_0c059674: /* original 8921, guest PC 0x0c059674 */
if(!s->budget--) { s->failed_pc=0x0c059674u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0596ba; }
goto P_0c059676;
P_0c059676: /* original d307, guest PC 0x0c059676 */
if(!s->budget--) { s->failed_pc=0x0c059676u; return 0; }
r[3]=read(ram,0x0c059694u,4);
goto P_0c059678;
P_0c059678: /* original 6032, guest PC 0x0c059678 */
if(!s->budget--) { s->failed_pc=0x0c059678u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05967a;
P_0c05967a: /* original c820, guest PC 0x0c05967a */
if(!s->budget--) { s->failed_pc=0x0c05967au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05967c;
P_0c05967c: /* original 891a, guest PC 0x0c05967c */
if(!s->budget--) { s->failed_pc=0x0c05967cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0596b4; }
goto P_0c05967e;
P_0c05967e: /* original f49d, guest PC 0x0c05967e */
if(!s->budget--) { s->failed_pc=0x0c05967eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c059680;
P_0c059680: /* original 9704, guest PC 0x0c059680 */
if(!s->budget--) { s->failed_pc=0x0c059680u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05968cu,2);
goto P_0c059682;
P_0c059682: /* original a01b, guest PC 0x0c059682 */
if(!s->budget--) { s->failed_pc=0x0c059682u; return 0; }
r[6]+=r[6];
goto P_0c0596bc;
P_0c059684: /* original 366c, guest PC 0x0c059684 */
if(!s->budget--) { s->failed_pc=0x0c059684u; return 0; }
r[6]+=r[6];
return vf3_matrix_family(0x0c059686u,s,ram);
P_0c0596b4: /* original c746, guest PC 0x0c0596b4 */
if(!s->budget--) { s->failed_pc=0x0c0596b4u; return 0; }
r[0]=0x0c0597d0u;
goto P_0c0596b6;
P_0c0596b6: /* original 366c, guest PC 0x0c0596b6 */
if(!s->budget--) { s->failed_pc=0x0c0596b6u; return 0; }
r[6]+=r[6];
goto P_0c0596b8;
P_0c0596b8: /* original f408, guest PC 0x0c0596b8 */
if(!s->budget--) { s->failed_pc=0x0c0596b8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0596ba;
P_0c0596ba: /* original 9788, guest PC 0x0c0596ba */
if(!s->budget--) { s->failed_pc=0x0c0596bau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0597ceu,2);
goto P_0c0596bc;
P_0c0596bc: /* original d345, guest PC 0x0c0596bc */
if(!s->budget--) { s->failed_pc=0x0c0596bcu; return 0; }
r[3]=read(ram,0x0c0597d4u,4);
goto P_0c0596be;
P_0c0596be: /* original 6232, guest PC 0x0c0596be */
if(!s->budget--) { s->failed_pc=0x0c0596beu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0596c0;
P_0c0596c0: /* original 4229, guest PC 0x0c0596c0 */
if(!s->budget--) { s->failed_pc=0x0c0596c0u; return 0; }
r[2]>>=16;
goto P_0c0596c2;
P_0c0596c2: /* original 1f21, guest PC 0x0c0596c2 */
if(!s->budget--) { s->failed_pc=0x0c0596c2u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0596c4;
P_0c0596c4: /* original d144, guest PC 0x0c0596c4 */
if(!s->budget--) { s->failed_pc=0x0c0596c4u; return 0; }
r[1]=read(ram,0x0c0597d8u,4);
goto P_0c0596c6;
P_0c0596c6: /* original 6012, guest PC 0x0c0596c6 */
if(!s->budget--) { s->failed_pc=0x0c0596c6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0596c8;
P_0c0596c8: /* original 20e9, guest PC 0x0c0596c8 */
if(!s->budget--) { s->failed_pc=0x0c0596c8u; return 0; }
r[0]&=r[14];
goto P_0c0596ca;
P_0c0596ca: /* original 8801, guest PC 0x0c0596ca */
if(!s->budget--) { s->failed_pc=0x0c0596cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0596cc;
P_0c0596cc: /* original 8909, guest PC 0x0c0596cc */
if(!s->budget--) { s->failed_pc=0x0c0596ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0596e2; }
goto P_0c0596ce;
P_0c0596ce: /* original d342, guest PC 0x0c0596ce */
if(!s->budget--) { s->failed_pc=0x0c0596ceu; return 0; }
r[3]=read(ram,0x0c0597d8u,4);
goto P_0c0596d0;
P_0c0596d0: /* original 6032, guest PC 0x0c0596d0 */
if(!s->budget--) { s->failed_pc=0x0c0596d0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0596d2;
P_0c0596d2: /* original c82c, guest PC 0x0c0596d2 */
if(!s->budget--) { s->failed_pc=0x0c0596d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c0596d4;
P_0c0596d4: /* original 8905, guest PC 0x0c0596d4 */
if(!s->budget--) { s->failed_pc=0x0c0596d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0596e2; }
goto P_0c0596d6;
P_0c0596d6: /* original 2ee8, guest PC 0x0c0596d6 */
if(!s->budget--) { s->failed_pc=0x0c0596d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0596d8;
P_0c0596d8: /* original 8903, guest PC 0x0c0596d8 */
if(!s->budget--) { s->failed_pc=0x0c0596d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0596e2; }
goto P_0c0596da;
P_0c0596da: /* original d240, guest PC 0x0c0596da */
if(!s->budget--) { s->failed_pc=0x0c0596dau; return 0; }
r[2]=read(ram,0x0c0597dcu,4);
goto P_0c0596dc;
P_0c0596dc: /* original 2428, guest PC 0x0c0596dc */
if(!s->budget--) { s->failed_pc=0x0c0596dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0596de;
P_0c0596de: /* original 8900, guest PC 0x0c0596de */
if(!s->budget--) { s->failed_pc=0x0c0596deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0596e2; }
goto P_0c0596e0;
P_0c0596e0: /* original 7501, guest PC 0x0c0596e0 */
if(!s->budget--) { s->failed_pc=0x0c0596e0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0596e2;
P_0c0596e2: /* original 3568, guest PC 0x0c0596e2 */
if(!s->budget--) { s->failed_pc=0x0c0596e2u; return 0; }
r[5]-=r[6];
goto P_0c0596e4;
P_0c0596e4: /* original 455a, guest PC 0x0c0596e4 */
if(!s->budget--) { s->failed_pc=0x0c0596e4u; return 0; }
r[53]=r[5];
goto P_0c0596e6;
P_0c0596e6: /* original f32d, guest PC 0x0c0596e6 */
if(!s->budget--) { s->failed_pc=0x0c0596e6u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0596e8;
P_0c0596e8: /* original f342, guest PC 0x0c0596e8 */
if(!s->budget--) { s->failed_pc=0x0c0596e8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0596ea;
P_0c0596ea: /* original f33d, guest PC 0x0c0596ea */
if(!s->budget--) { s->failed_pc=0x0c0596eau; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0596ec;
P_0c0596ec: /* original 055a, guest PC 0x0c0596ec */
if(!s->budget--) { s->failed_pc=0x0c0596ecu; return 0; }
r[5]=r[53];
goto P_0c0596ee;
P_0c0596ee: /* original 3577, guest PC 0x0c0596ee */
if(!s->budget--) { s->failed_pc=0x0c0596eeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[7])!=0);
goto P_0c0596f0;
P_0c0596f0: /* original 8901, guest PC 0x0c0596f0 */
if(!s->budget--) { s->failed_pc=0x0c0596f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0596f6; }
goto P_0c0596f2;
P_0c0596f2: /* original a003, guest PC 0x0c0596f2 */
if(!s->budget--) { s->failed_pc=0x0c0596f2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0596fc;
P_0c0596f4: /* original 62f2, guest PC 0x0c0596f4 */
if(!s->budget--) { s->failed_pc=0x0c0596f4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0596f6;
P_0c0596f6: /* original 62f2, guest PC 0x0c0596f6 */
if(!s->budget--) { s->failed_pc=0x0c0596f6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0596f8;
P_0c0596f8: /* original 53f1, guest PC 0x0c0596f8 */
if(!s->budget--) { s->failed_pc=0x0c0596f8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0596fa;
P_0c0596fa: /* original 3538, guest PC 0x0c0596fa */
if(!s->budget--) { s->failed_pc=0x0c0596fau; return 0; }
r[5]-=r[3];
goto P_0c0596fc;
P_0c0596fc: /* original 2252, guest PC 0x0c0596fc */
if(!s->budget--) { s->failed_pc=0x0c0596fcu; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0596fe;
P_0c0596fe: /* original e000, guest PC 0x0c0596fe */
if(!s->budget--) { s->failed_pc=0x0c0596feu; return 0; }
r[0]=0x00000000u;
goto P_0c059700;
P_0c059700: /* original 7f08, guest PC 0x0c059700 */
if(!s->budget--) { s->failed_pc=0x0c059700u; return 0; }
r[15]+=0x00000008u;
goto P_0c059702;
P_0c059702: /* original 4f26, guest PC 0x0c059702 */
if(!s->budget--) { s->failed_pc=0x0c059702u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059704;
P_0c059704: /* original 000b, guest PC 0x0c059704 */
if(!s->budget--) { s->failed_pc=0x0c059704u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059706: /* original 6ef6, guest PC 0x0c059706 */
if(!s->budget--) { s->failed_pc=0x0c059706u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c059708u,s,ram);
P_0c05e86a: /* original 4f22, guest PC 0x0c05e86a */
if(!s->budget--) { s->failed_pc=0x0c05e86au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e86c;
P_0c05e86c: /* original 7ff8, guest PC 0x0c05e86c */
if(!s->budget--) { s->failed_pc=0x0c05e86cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05e86e;
P_0c05e86e: /* original 1f61, guest PC 0x0c05e86e */
if(!s->budget--) { s->failed_pc=0x0c05e86eu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c05e870;
P_0c05e870: /* original 2f72, guest PC 0x0c05e870 */
if(!s->budget--) { s->failed_pc=0x0c05e870u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c05e872;
P_0c05e872: /* original 57fa, guest PC 0x0c05e872 */
if(!s->budget--) { s->failed_pc=0x0c05e872u; return 0; }
r[7]=read(ram,r[15]+40,4);
goto P_0c05e874;
P_0c05e874: /* original 66f2, guest PC 0x0c05e874 */
if(!s->budget--) { s->failed_pc=0x0c05e874u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c05e876;
P_0c05e876: /* original 55f1, guest PC 0x0c05e876 */
if(!s->budget--) { s->failed_pc=0x0c05e876u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05e878;
P_0c05e878: /* original b2f4, guest PC 0x0c05e878 */
if(!s->budget--) { s->failed_pc=0x0c05e878u; return 0; }
target=0x0c05ee64u; r[16]=code_base|0x0c05e87cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e87cu) { target=s->pc; goto dispatch; }
goto P_0c05e87c;
P_0c05e87a: /* original 64e3, guest PC 0x0c05e87a */
if(!s->budget--) { s->failed_pc=0x0c05e87au; return 0; }
r[4]=r[14];
goto P_0c05e87c;
P_0c05e87c: /* original 6b03, guest PC 0x0c05e87c */
if(!s->budget--) { s->failed_pc=0x0c05e87cu; return 0; }
r[11]=r[0];
goto P_0c05e87e;
P_0c05e87e: /* original 2bb8, guest PC 0x0c05e87e */
if(!s->budget--) { s->failed_pc=0x0c05e87eu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c05e880;
P_0c05e880: /* original 8b59, guest PC 0x0c05e880 */
if(!s->budget--) { s->failed_pc=0x0c05e880u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e936; }
goto P_0c05e882;
P_0c05e882: /* original 60e2, guest PC 0x0c05e882 */
if(!s->budget--) { s->failed_pc=0x0c05e882u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05e884;
P_0c05e884: /* original 600d, guest PC 0x0c05e884 */
if(!s->budget--) { s->failed_pc=0x0c05e884u; return 0; }
r[0]=r[0]&65535u;
goto P_0c05e886;
P_0c05e886: /* original 8803, guest PC 0x0c05e886 */
if(!s->budget--) { s->failed_pc=0x0c05e886u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05e888;
P_0c05e888: /* original 8b01, guest PC 0x0c05e888 */
if(!s->budget--) { s->failed_pc=0x0c05e888u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e88e; }
goto P_0c05e88a;
P_0c05e88a: /* original a056, guest PC 0x0c05e88a */
if(!s->budget--) { s->failed_pc=0x0c05e88au; return 0; }
r[0]=0x00000004u;
goto P_0c05e93a;
P_0c05e88c: /* original e004, guest PC 0x0c05e88c */
if(!s->budget--) { s->failed_pc=0x0c05e88cu; return 0; }
r[0]=0x00000004u;
goto P_0c05e88e;
P_0c05e88e: /* original e201, guest PC 0x0c05e88e */
if(!s->budget--) { s->failed_pc=0x0c05e88eu; return 0; }
r[2]=0x00000001u;
goto P_0c05e890;
P_0c05e890: /* original 3a27, guest PC 0x0c05e890 */
if(!s->budget--) { s->failed_pc=0x0c05e890u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>(int32_t)r[2])!=0);
goto P_0c05e892;
P_0c05e892: /* original 8b16, guest PC 0x0c05e892 */
if(!s->budget--) { s->failed_pc=0x0c05e892u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e8c2; }
goto P_0c05e894;
P_0c05e894: /* original 6523, guest PC 0x0c05e894 */
if(!s->budget--) { s->failed_pc=0x0c05e894u; return 0; }
r[5]=r[2];
goto P_0c05e896;
P_0c05e896: /* original 64e3, guest PC 0x0c05e896 */
if(!s->budget--) { s->failed_pc=0x0c05e896u; return 0; }
r[4]=r[14];
goto P_0c05e898;
P_0c05e898: /* original 35a3, guest PC 0x0c05e898 */
if(!s->budget--) { s->failed_pc=0x0c05e898u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[10])!=0);
goto P_0c05e89a;
P_0c05e89a: /* original 8d12, guest PC 0x0c05e89a */
if(!s->budget--) { s->failed_pc=0x0c05e89au; return 0; }
cond=r[17]&1u;
r[4]+=0x00000028u;
if(cond) { goto P_0c05e8c2; }
goto P_0c05e89e;
P_0c05e89c: /* original 7428, guest PC 0x0c05e89c */
if(!s->budget--) { s->failed_pc=0x0c05e89cu; return 0; }
r[4]+=0x00000028u;
goto P_0c05e89e;
P_0c05e89e: /* original 7501, guest PC 0x0c05e89e */
if(!s->budget--) { s->failed_pc=0x0c05e89eu; return 0; }
r[5]+=0x00000001u;
goto P_0c05e8a0;
P_0c05e8a0: /* original 63e2, guest PC 0x0c05e8a0 */
if(!s->budget--) { s->failed_pc=0x0c05e8a0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c05e8a2;
P_0c05e8a2: /* original 35a3, guest PC 0x0c05e8a2 */
if(!s->budget--) { s->failed_pc=0x0c05e8a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[10])!=0);
goto P_0c05e8a4;
P_0c05e8a4: /* original 2432, guest PC 0x0c05e8a4 */
if(!s->budget--) { s->failed_pc=0x0c05e8a4u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c05e8a6;
P_0c05e8a6: /* original 52e1, guest PC 0x0c05e8a6 */
if(!s->budget--) { s->failed_pc=0x0c05e8a6u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c05e8a8;
P_0c05e8a8: /* original 1421, guest PC 0x0c05e8a8 */
if(!s->budget--) { s->failed_pc=0x0c05e8a8u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c05e8aa;
P_0c05e8aa: /* original 53e2, guest PC 0x0c05e8aa */
if(!s->budget--) { s->failed_pc=0x0c05e8aau; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c05e8ac;
P_0c05e8ac: /* original 1432, guest PC 0x0c05e8ac */
if(!s->budget--) { s->failed_pc=0x0c05e8acu; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c05e8ae;
P_0c05e8ae: /* original 52e3, guest PC 0x0c05e8ae */
if(!s->budget--) { s->failed_pc=0x0c05e8aeu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c05e8b0;
P_0c05e8b0: /* original 1423, guest PC 0x0c05e8b0 */
if(!s->budget--) { s->failed_pc=0x0c05e8b0u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c05e8b2;
P_0c05e8b2: /* original 53e4, guest PC 0x0c05e8b2 */
if(!s->budget--) { s->failed_pc=0x0c05e8b2u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c05e8b4;
P_0c05e8b4: /* original 1434, guest PC 0x0c05e8b4 */
if(!s->budget--) { s->failed_pc=0x0c05e8b4u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c05e8b6;
P_0c05e8b6: /* original 52e5, guest PC 0x0c05e8b6 */
if(!s->budget--) { s->failed_pc=0x0c05e8b6u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c05e8b8;
P_0c05e8b8: /* original 1425, guest PC 0x0c05e8b8 */
if(!s->budget--) { s->failed_pc=0x0c05e8b8u; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c05e8ba;
P_0c05e8ba: /* original 53e6, guest PC 0x0c05e8ba */
if(!s->budget--) { s->failed_pc=0x0c05e8bau; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c05e8bc;
P_0c05e8bc: /* original 1436, guest PC 0x0c05e8bc */
if(!s->budget--) { s->failed_pc=0x0c05e8bcu; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c05e8be;
P_0c05e8be: /* original 8fee, guest PC 0x0c05e8be */
if(!s->budget--) { s->failed_pc=0x0c05e8beu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000028u;
if(!cond) { goto P_0c05e89e; }
goto P_0c05e8c2;
P_0c05e8c0: /* original 7428, guest PC 0x0c05e8c0 */
if(!s->budget--) { s->failed_pc=0x0c05e8c0u; return 0; }
r[4]+=0x00000028u;
goto P_0c05e8c2;
P_0c05e8c2: /* original 65e3, guest PC 0x0c05e8c2 */
if(!s->budget--) { s->failed_pc=0x0c05e8c2u; return 0; }
r[5]=r[14];
goto P_0c05e8c4;
P_0c05e8c4: /* original d26a, guest PC 0x0c05e8c4 */
if(!s->budget--) { s->failed_pc=0x0c05e8c4u; return 0; }
r[2]=read(ram,0x0c05ea70u,4);
goto P_0c05e8c6;
P_0c05e8c6: /* original 53e5, guest PC 0x0c05e8c6 */
if(!s->budget--) { s->failed_pc=0x0c05e8c6u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c05e8c8;
P_0c05e8c8: /* original 03a7, guest PC 0x0c05e8c8 */
if(!s->budget--) { s->failed_pc=0x0c05e8c8u; return 0; }
r[19]=r[3]*r[10];
goto P_0c05e8ca;
P_0c05e8ca: /* original 031a, guest PC 0x0c05e8ca */
if(!s->budget--) { s->failed_pc=0x0c05e8cau; return 0; }
r[3]=r[19];
goto P_0c05e8cc;
P_0c05e8cc: /* original 2f32, guest PC 0x0c05e8cc */
if(!s->budget--) { s->failed_pc=0x0c05e8ccu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05e8ce;
P_0c05e8ce: /* original 420b, guest PC 0x0c05e8ce */
if(!s->budget--) { s->failed_pc=0x0c05e8ceu; return 0; }
target=r[2];
r[16]=code_base|0x0c05e8d2u;
r[4]=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e8d2u) { target=s->pc; goto dispatch; }
goto P_0c05e8d2;
P_0c05e8d0: /* original 6433, guest PC 0x0c05e8d0 */
if(!s->budget--) { s->failed_pc=0x0c05e8d0u; return 0; }
r[4]=r[3];
goto P_0c05e8d2;
P_0c05e8d2: /* original 8803, guest PC 0x0c05e8d2 */
if(!s->budget--) { s->failed_pc=0x0c05e8d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05e8d4;
P_0c05e8d4: /* original 8f05, guest PC 0x0c05e8d4 */
if(!s->budget--) { s->failed_pc=0x0c05e8d4u; return 0; }
cond=r[17]&1u;
r[11]=r[0];
if(!cond) { goto P_0c05e8e2; }
goto P_0c05e8d8;
P_0c05e8d6: /* original 6b03, guest PC 0x0c05e8d6 */
if(!s->budget--) { s->failed_pc=0x0c05e8d6u; return 0; }
r[11]=r[0];
goto P_0c05e8d8;
P_0c05e8d8: /* original d266, guest PC 0x0c05e8d8 */
if(!s->budget--) { s->failed_pc=0x0c05e8d8u; return 0; }
r[2]=read(ram,0x0c05ea74u,4);
goto P_0c05e8da;
P_0c05e8da: /* original 420b, guest PC 0x0c05e8da */
if(!s->budget--) { s->failed_pc=0x0c05e8dau; return 0; }
target=r[2];
r[16]=code_base|0x0c05e8deu;
r[4]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e8deu) { target=s->pc; goto dispatch; }
goto P_0c05e8de;
P_0c05e8dc: /* original e403, guest PC 0x0c05e8dc */
if(!s->budget--) { s->failed_pc=0x0c05e8dcu; return 0; }
r[4]=0x00000003u;
goto P_0c05e8de;
P_0c05e8de: /* original a02a, guest PC 0x0c05e8de */
if(!s->budget--) { s->failed_pc=0x0c05e8deu; return 0; }
goto P_0c05e936;
P_0c05e8e0: /* original 0009, guest PC 0x0c05e8e0 */
if(!s->budget--) { s->failed_pc=0x0c05e8e0u; return 0; }
goto P_0c05e8e2;
P_0c05e8e2: /* original 58e7, guest PC 0x0c05e8e2 */
if(!s->budget--) { s->failed_pc=0x0c05e8e2u; return 0; }
r[8]=read(ram,r[14]+28,4);
goto P_0c05e8e4;
P_0c05e8e4: /* original d964, guest PC 0x0c05e8e4 */
if(!s->budget--) { s->failed_pc=0x0c05e8e4u; return 0; }
r[9]=read(ram,0x0c05ea78u,4);
goto P_0c05e8e6;
P_0c05e8e6: /* original 2f82, guest PC 0x0c05e8e6 */
if(!s->budget--) { s->failed_pc=0x0c05e8e6u; return 0; }
write(ram,r[15],r[8],4);
goto P_0c05e8e8;
P_0c05e8e8: /* original 490b, guest PC 0x0c05e8e8 */
if(!s->budget--) { s->failed_pc=0x0c05e8e8u; return 0; }
target=r[9];
r[16]=code_base|0x0c05e8ecu;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e8ecu) { target=s->pc; goto dispatch; }
goto P_0c05e8ec;
P_0c05e8ea: /* original 6483, guest PC 0x0c05e8ea */
if(!s->budget--) { s->failed_pc=0x0c05e8eau; return 0; }
r[4]=r[8];
goto P_0c05e8ec;
P_0c05e8ec: /* original a021, guest PC 0x0c05e8ec */
if(!s->budget--) { s->failed_pc=0x0c05e8ecu; return 0; }
r[12]=0x00000000u;
goto P_0c05e932;
P_0c05e8ee: /* original ec00, guest PC 0x0c05e8ee */
if(!s->budget--) { s->failed_pc=0x0c05e8eeu; return 0; }
r[12]=0x00000000u;
goto P_0c05e8f0;
P_0c05e8f0: /* original db62, guest PC 0x0c05e8f0 */
if(!s->budget--) { s->failed_pc=0x0c05e8f0u; return 0; }
r[11]=read(ram,0x0c05ea7cu,4);
goto P_0c05e8f2;
P_0c05e8f2: /* original 6dc3, guest PC 0x0c05e8f2 */
if(!s->budget--) { s->failed_pc=0x0c05e8f2u; return 0; }
r[13]=r[12];
goto P_0c05e8f4;
P_0c05e8f4: /* original 63c3, guest PC 0x0c05e8f4 */
if(!s->budget--) { s->failed_pc=0x0c05e8f4u; return 0; }
r[3]=r[12];
goto P_0c05e8f6;
P_0c05e8f6: /* original 4d08, guest PC 0x0c05e8f6 */
if(!s->budget--) { s->failed_pc=0x0c05e8f6u; return 0; }
r[13]<<=2;
goto P_0c05e8f8;
P_0c05e8f8: /* original 3d3c, guest PC 0x0c05e8f8 */
if(!s->budget--) { s->failed_pc=0x0c05e8f8u; return 0; }
r[13]+=r[3];
goto P_0c05e8fa;
P_0c05e8fa: /* original 4d08, guest PC 0x0c05e8fa */
if(!s->budget--) { s->failed_pc=0x0c05e8fau; return 0; }
r[13]<<=2;
goto P_0c05e8fc;
P_0c05e8fc: /* original 4d00, guest PC 0x0c05e8fc */
if(!s->budget--) { s->failed_pc=0x0c05e8fcu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c05e8fe;
P_0c05e8fe: /* original 3dec, guest PC 0x0c05e8fe */
if(!s->budget--) { s->failed_pc=0x0c05e8feu; return 0; }
r[13]+=r[14];
goto P_0c05e900;
P_0c05e900: /* original 1d87, guest PC 0x0c05e900 */
if(!s->budget--) { s->failed_pc=0x0c05e900u; return 0; }
write(ram,r[13]+28,r[8],4);
goto P_0c05e902;
P_0c05e902: /* original 65d3, guest PC 0x0c05e902 */
if(!s->budget--) { s->failed_pc=0x0c05e902u; return 0; }
r[5]=r[13];
goto P_0c05e904;
P_0c05e904: /* original 4b0b, guest PC 0x0c05e904 */
if(!s->budget--) { s->failed_pc=0x0c05e904u; return 0; }
target=r[11];
r[16]=code_base|0x0c05e908u;
r[4]=read(ram,r[13]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e908u) { target=s->pc; goto dispatch; }
goto P_0c05e908;
P_0c05e906: /* original 54d5, guest PC 0x0c05e906 */
if(!s->budget--) { s->failed_pc=0x0c05e906u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c05e908;
P_0c05e908: /* original 52d5, guest PC 0x0c05e908 */
if(!s->budget--) { s->failed_pc=0x0c05e908u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c05e90a;
P_0c05e90a: /* original 8803, guest PC 0x0c05e90a */
if(!s->budget--) { s->failed_pc=0x0c05e90au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05e90c;
P_0c05e90c: /* original 6b03, guest PC 0x0c05e90c */
if(!s->budget--) { s->failed_pc=0x0c05e90cu; return 0; }
r[11]=r[0];
goto P_0c05e90e;
P_0c05e90e: /* original 4209, guest PC 0x0c05e90e */
if(!s->budget--) { s->failed_pc=0x0c05e90eu; return 0; }
r[2]>>=2;
goto P_0c05e910;
P_0c05e910: /* original 4208, guest PC 0x0c05e910 */
if(!s->budget--) { s->failed_pc=0x0c05e910u; return 0; }
r[2]<<=2;
goto P_0c05e912;
P_0c05e912: /* original 8f0d, guest PC 0x0c05e912 */
if(!s->budget--) { s->failed_pc=0x0c05e912u; return 0; }
cond=r[17]&1u;
r[8]+=r[2];
if(!cond) { goto P_0c05e930; }
goto P_0c05e916;
P_0c05e914: /* original 382c, guest PC 0x0c05e914 */
if(!s->budget--) { s->failed_pc=0x0c05e914u; return 0; }
r[8]+=r[2];
goto P_0c05e916;
P_0c05e916: /* original 4c15, guest PC 0x0c05e916 */
if(!s->budget--) { s->failed_pc=0x0c05e916u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c05e918;
P_0c05e918: /* original 8f05, guest PC 0x0c05e918 */
if(!s->budget--) { s->failed_pc=0x0c05e918u; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(!cond) { goto P_0c05e926; }
goto P_0c05e91c;
P_0c05e91a: /* original ee00, guest PC 0x0c05e91a */
if(!s->budget--) { s->failed_pc=0x0c05e91au; return 0; }
r[14]=0x00000000u;
goto P_0c05e91c;
P_0c05e91c: /* original 490b, guest PC 0x0c05e91c */
if(!s->budget--) { s->failed_pc=0x0c05e91cu; return 0; }
target=r[9];
r[16]=code_base|0x0c05e920u;
r[4]=read(ram,r[13]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e920u) { target=s->pc; goto dispatch; }
goto P_0c05e920;
P_0c05e91e: /* original 54d7, guest PC 0x0c05e91e */
if(!s->budget--) { s->failed_pc=0x0c05e91eu; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c05e920;
P_0c05e920: /* original 7e01, guest PC 0x0c05e920 */
if(!s->budget--) { s->failed_pc=0x0c05e920u; return 0; }
r[14]+=0x00000001u;
goto P_0c05e922;
P_0c05e922: /* original 3ec3, guest PC 0x0c05e922 */
if(!s->budget--) { s->failed_pc=0x0c05e922u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c05e924;
P_0c05e924: /* original 8bfa, guest PC 0x0c05e924 */
if(!s->budget--) { s->failed_pc=0x0c05e924u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e91c; }
goto P_0c05e926;
P_0c05e926: /* original d253, guest PC 0x0c05e926 */
if(!s->budget--) { s->failed_pc=0x0c05e926u; return 0; }
r[2]=read(ram,0x0c05ea74u,4);
goto P_0c05e928;
P_0c05e928: /* original 420b, guest PC 0x0c05e928 */
if(!s->budget--) { s->failed_pc=0x0c05e928u; return 0; }
target=r[2];
r[16]=code_base|0x0c05e92cu;
r[4]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e92cu) { target=s->pc; goto dispatch; }
goto P_0c05e92c;
P_0c05e92a: /* original e403, guest PC 0x0c05e92a */
if(!s->budget--) { s->failed_pc=0x0c05e92au; return 0; }
r[4]=0x00000003u;
goto P_0c05e92c;
P_0c05e92c: /* original a003, guest PC 0x0c05e92c */
if(!s->budget--) { s->failed_pc=0x0c05e92cu; return 0; }
goto P_0c05e936;
P_0c05e92e: /* original 0009, guest PC 0x0c05e92e */
if(!s->budget--) { s->failed_pc=0x0c05e92eu; return 0; }
goto P_0c05e930;
P_0c05e930: /* original 7c01, guest PC 0x0c05e930 */
if(!s->budget--) { s->failed_pc=0x0c05e930u; return 0; }
r[12]+=0x00000001u;
goto P_0c05e932;
P_0c05e932: /* original 3ca3, guest PC 0x0c05e932 */
if(!s->budget--) { s->failed_pc=0x0c05e932u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[10])!=0);
goto P_0c05e934;
P_0c05e934: /* original 8bdc, guest PC 0x0c05e934 */
if(!s->budget--) { s->failed_pc=0x0c05e934u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e8f0; }
goto P_0c05e936;
P_0c05e936: /* original 60b3, guest PC 0x0c05e936 */
if(!s->budget--) { s->failed_pc=0x0c05e936u; return 0; }
r[0]=r[11];
goto P_0c05e938;
P_0c05e938: /* original 0009, guest PC 0x0c05e938 */
if(!s->budget--) { s->failed_pc=0x0c05e938u; return 0; }
goto P_0c05e93a;
P_0c05e93a: /* original 7f08, guest PC 0x0c05e93a */
if(!s->budget--) { s->failed_pc=0x0c05e93au; return 0; }
r[15]+=0x00000008u;
goto P_0c05e93c;
P_0c05e93c: /* original 4f26, guest PC 0x0c05e93c */
if(!s->budget--) { s->failed_pc=0x0c05e93cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e93e;
P_0c05e93e: /* original 68f6, guest PC 0x0c05e93e */
if(!s->budget--) { s->failed_pc=0x0c05e93eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05e940;
P_0c05e940: /* original 69f6, guest PC 0x0c05e940 */
if(!s->budget--) { s->failed_pc=0x0c05e940u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05e942;
P_0c05e942: /* original 6af6, guest PC 0x0c05e942 */
if(!s->budget--) { s->failed_pc=0x0c05e942u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05e944;
P_0c05e944: /* original 6bf6, guest PC 0x0c05e944 */
if(!s->budget--) { s->failed_pc=0x0c05e944u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05e946;
P_0c05e946: /* original 6cf6, guest PC 0x0c05e946 */
if(!s->budget--) { s->failed_pc=0x0c05e946u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05e948;
P_0c05e948: /* original 6df6, guest PC 0x0c05e948 */
if(!s->budget--) { s->failed_pc=0x0c05e948u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05e94a;
P_0c05e94a: /* original 000b, guest PC 0x0c05e94a */
if(!s->budget--) { s->failed_pc=0x0c05e94au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e94c: /* original 6ef6, guest PC 0x0c05e94c */
if(!s->budget--) { s->failed_pc=0x0c05e94cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05e94eu,s,ram);
P_0c05ee64: /* original 2fe6, guest PC 0x0c05ee64 */
if(!s->budget--) { s->failed_pc=0x0c05ee64u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ee66;
P_0c05ee66: /* original 2fd6, guest PC 0x0c05ee66 */
if(!s->budget--) { s->failed_pc=0x0c05ee66u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ee68;
P_0c05ee68: /* original 2fc6, guest PC 0x0c05ee68 */
if(!s->budget--) { s->failed_pc=0x0c05ee68u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ee6a;
P_0c05ee6a: /* original ed00, guest PC 0x0c05ee6a */
if(!s->budget--) { s->failed_pc=0x0c05ee6au; return 0; }
r[13]=0x00000000u;
goto P_0c05ee6c;
P_0c05ee6c: /* original de2c, guest PC 0x0c05ee6c */
if(!s->budget--) { s->failed_pc=0x0c05ee6cu; return 0; }
r[14]=read(ram,0x0c05ef20u,4);
goto P_0c05ee6e;
P_0c05ee6e: /* original 4f22, guest PC 0x0c05ee6e */
if(!s->budget--) { s->failed_pc=0x0c05ee6eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ee70;
P_0c05ee70: /* original 934f, guest PC 0x0c05ee70 */
if(!s->budget--) { s->failed_pc=0x0c05ee70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef12u,2);
goto P_0c05ee72;
P_0c05ee72: /* original 7ffc, guest PC 0x0c05ee72 */
if(!s->budget--) { s->failed_pc=0x0c05ee72u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05ee74;
P_0c05ee74: /* original 2e79, guest PC 0x0c05ee74 */
if(!s->budget--) { s->failed_pc=0x0c05ee74u; return 0; }
r[14]&=r[7];
goto P_0c05ee76;
P_0c05ee76: /* original 677c, guest PC 0x0c05ee76 */
if(!s->budget--) { s->failed_pc=0x0c05ee76u; return 0; }
r[7]=r[7]&255u;
goto P_0c05ee78;
P_0c05ee78: /* original 2f72, guest PC 0x0c05ee78 */
if(!s->budget--) { s->failed_pc=0x0c05ee78u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c05ee7a;
P_0c05ee7a: /* original 3e30, guest PC 0x0c05ee7a */
if(!s->budget--) { s->failed_pc=0x0c05ee7au; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05ee7c;
P_0c05ee7c: /* original 8d03, guest PC 0x0c05ee7c */
if(!s->budget--) { s->failed_pc=0x0c05ee7cu; return 0; }
cond=r[17]&1u;
r[12]=0x00000003u;
if(cond) { goto P_0c05ee86; }
goto P_0c05ee80;
P_0c05ee7e: /* original ec03, guest PC 0x0c05ee7e */
if(!s->budget--) { s->failed_pc=0x0c05ee7eu; return 0; }
r[12]=0x00000003u;
goto P_0c05ee80;
P_0c05ee80: /* original 9148, guest PC 0x0c05ee80 */
if(!s->budget--) { s->failed_pc=0x0c05ee80u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef14u,2);
goto P_0c05ee82;
P_0c05ee82: /* original 3e10, guest PC 0x0c05ee82 */
if(!s->budget--) { s->failed_pc=0x0c05ee82u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05ee84;
P_0c05ee84: /* original 8b01, guest PC 0x0c05ee84 */
if(!s->budget--) { s->failed_pc=0x0c05ee84u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ee8a; }
goto P_0c05ee86;
P_0c05ee86: /* original a002, guest PC 0x0c05ee86 */
if(!s->budget--) { s->failed_pc=0x0c05ee86u; return 0; }
write(ram,r[4],r[12],4);
goto P_0c05ee8e;
P_0c05ee88: /* original 24c2, guest PC 0x0c05ee88 */
if(!s->budget--) { s->failed_pc=0x0c05ee88u; return 0; }
write(ram,r[4],r[12],4);
goto P_0c05ee8a;
P_0c05ee8a: /* original e202, guest PC 0x0c05ee8a */
if(!s->budget--) { s->failed_pc=0x0c05ee8au; return 0; }
r[2]=0x00000002u;
goto P_0c05ee8c;
P_0c05ee8c: /* original 2422, guest PC 0x0c05ee8c */
if(!s->budget--) { s->failed_pc=0x0c05ee8cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ee8e;
P_0c05ee8e: /* original 9342, guest PC 0x0c05ee8e */
if(!s->budget--) { s->failed_pc=0x0c05ee8eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef16u,2);
goto P_0c05ee90;
P_0c05ee90: /* original 3e30, guest PC 0x0c05ee90 */
if(!s->budget--) { s->failed_pc=0x0c05ee90u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05ee92;
P_0c05ee92: /* original 8d03, guest PC 0x0c05ee92 */
if(!s->budget--) { s->failed_pc=0x0c05ee92u; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(cond) { goto P_0c05ee9c; }
goto P_0c05ee96;
P_0c05ee94: /* original e701, guest PC 0x0c05ee94 */
if(!s->budget--) { s->failed_pc=0x0c05ee94u; return 0; }
r[7]=0x00000001u;
goto P_0c05ee96;
P_0c05ee96: /* original 913f, guest PC 0x0c05ee96 */
if(!s->budget--) { s->failed_pc=0x0c05ee96u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef18u,2);
goto P_0c05ee98;
P_0c05ee98: /* original 3e10, guest PC 0x0c05ee98 */
if(!s->budget--) { s->failed_pc=0x0c05ee98u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05ee9a;
P_0c05ee9a: /* original 8b0b, guest PC 0x0c05ee9a */
if(!s->budget--) { s->failed_pc=0x0c05ee9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eeb4; }
goto P_0c05ee9c;
P_0c05ee9c: /* original d321, guest PC 0x0c05ee9c */
if(!s->budget--) { s->failed_pc=0x0c05ee9cu; return 0; }
r[3]=read(ram,0x0c05ef24u,4);
goto P_0c05ee9e;
P_0c05ee9e: /* original 6032, guest PC 0x0c05ee9e */
if(!s->budget--) { s->failed_pc=0x0c05ee9eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05eea0;
P_0c05eea0: /* original 913b, guest PC 0x0c05eea0 */
if(!s->budget--) { s->failed_pc=0x0c05eea0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef1au,2);
goto P_0c05eea2;
P_0c05eea2: /* original 001e, guest PC 0x0c05eea2 */
if(!s->budget--) { s->failed_pc=0x0c05eea2u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c05eea4;
P_0c05eea4: /* original 8803, guest PC 0x0c05eea4 */
if(!s->budget--) { s->failed_pc=0x0c05eea4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05eea6;
P_0c05eea6: /* original 8b01, guest PC 0x0c05eea6 */
if(!s->budget--) { s->failed_pc=0x0c05eea6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eeac; }
goto P_0c05eea8;
P_0c05eea8: /* original a001, guest PC 0x0c05eea8 */
if(!s->budget--) { s->failed_pc=0x0c05eea8u; return 0; }
write(ram,r[4]+4,r[12],4);
goto P_0c05eeae;
P_0c05eeaa: /* original 14c1, guest PC 0x0c05eeaa */
if(!s->budget--) { s->failed_pc=0x0c05eeaau; return 0; }
write(ram,r[4]+4,r[12],4);
goto P_0c05eeac;
P_0c05eeac: /* original 1471, guest PC 0x0c05eeac */
if(!s->budget--) { s->failed_pc=0x0c05eeacu; return 0; }
write(ram,r[4]+4,r[7],4);
goto P_0c05eeae;
P_0c05eeae: /* original d31e, guest PC 0x0c05eeae */
if(!s->budget--) { s->failed_pc=0x0c05eeaeu; return 0; }
r[3]=read(ram,0x0c05ef28u,4);
goto P_0c05eeb0;
P_0c05eeb0: /* original a021, guest PC 0x0c05eeb0 */
if(!s->budget--) { s->failed_pc=0x0c05eeb0u; return 0; }
goto P_0c05eef6;
P_0c05eeb2: /* original 0009, guest PC 0x0c05eeb2 */
if(!s->budget--) { s->failed_pc=0x0c05eeb2u; return 0; }
goto P_0c05eeb4;
P_0c05eeb4: /* original 9132, guest PC 0x0c05eeb4 */
if(!s->budget--) { s->failed_pc=0x0c05eeb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef1cu,2);
goto P_0c05eeb6;
P_0c05eeb6: /* original 3e10, guest PC 0x0c05eeb6 */
if(!s->budget--) { s->failed_pc=0x0c05eeb6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05eeb8;
P_0c05eeb8: /* original 8902, guest PC 0x0c05eeb8 */
if(!s->budget--) { s->failed_pc=0x0c05eeb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05eec0; }
goto P_0c05eeba;
P_0c05eeba: /* original 9230, guest PC 0x0c05eeba */
if(!s->budget--) { s->failed_pc=0x0c05eebau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef1eu,2);
goto P_0c05eebc;
P_0c05eebc: /* original 3e20, guest PC 0x0c05eebc */
if(!s->budget--) { s->failed_pc=0x0c05eebcu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05eebe;
P_0c05eebe: /* original 8b0b, guest PC 0x0c05eebe */
if(!s->budget--) { s->failed_pc=0x0c05eebeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eed8; }
goto P_0c05eec0;
P_0c05eec0: /* original d318, guest PC 0x0c05eec0 */
if(!s->budget--) { s->failed_pc=0x0c05eec0u; return 0; }
r[3]=read(ram,0x0c05ef24u,4);
goto P_0c05eec2;
P_0c05eec2: /* original 6032, guest PC 0x0c05eec2 */
if(!s->budget--) { s->failed_pc=0x0c05eec2u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05eec4;
P_0c05eec4: /* original 9129, guest PC 0x0c05eec4 */
if(!s->budget--) { s->failed_pc=0x0c05eec4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ef1au,2);
goto P_0c05eec6;
P_0c05eec6: /* original 001e, guest PC 0x0c05eec6 */
if(!s->budget--) { s->failed_pc=0x0c05eec6u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c05eec8;
P_0c05eec8: /* original 8803, guest PC 0x0c05eec8 */
if(!s->budget--) { s->failed_pc=0x0c05eec8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05eeca;
P_0c05eeca: /* original 8b01, guest PC 0x0c05eeca */
if(!s->budget--) { s->failed_pc=0x0c05eecau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eed0; }
goto P_0c05eecc;
P_0c05eecc: /* original a001, guest PC 0x0c05eecc */
if(!s->budget--) { s->failed_pc=0x0c05eeccu; return 0; }
write(ram,r[4]+4,r[12],4);
goto P_0c05eed2;
P_0c05eece: /* original 14c1, guest PC 0x0c05eece */
if(!s->budget--) { s->failed_pc=0x0c05eeceu; return 0; }
write(ram,r[4]+4,r[12],4);
goto P_0c05eed0;
P_0c05eed0: /* original 1471, guest PC 0x0c05eed0 */
if(!s->budget--) { s->failed_pc=0x0c05eed0u; return 0; }
write(ram,r[4]+4,r[7],4);
goto P_0c05eed2;
P_0c05eed2: /* original d316, guest PC 0x0c05eed2 */
if(!s->budget--) { s->failed_pc=0x0c05eed2u; return 0; }
r[3]=read(ram,0x0c05ef2cu,4);
goto P_0c05eed4;
P_0c05eed4: /* original a00f, guest PC 0x0c05eed4 */
if(!s->budget--) { s->failed_pc=0x0c05eed4u; return 0; }
goto P_0c05eef6;
P_0c05eed6: /* original 0009, guest PC 0x0c05eed6 */
if(!s->budget--) { s->failed_pc=0x0c05eed6u; return 0; }
goto P_0c05eed8;
P_0c05eed8: /* original 1471, guest PC 0x0c05eed8 */
if(!s->budget--) { s->failed_pc=0x0c05eed8u; return 0; }
write(ram,r[4]+4,r[7],4);
goto P_0c05eeda;
P_0c05eeda: /* original 60f2, guest PC 0x0c05eeda */
if(!s->budget--) { s->failed_pc=0x0c05eedau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05eedc;
P_0c05eedc: /* original 8800, guest PC 0x0c05eedc */
if(!s->budget--) { s->failed_pc=0x0c05eedcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05eede;
P_0c05eede: /* original 8909, guest PC 0x0c05eede */
if(!s->budget--) { s->failed_pc=0x0c05eedeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05eef4; }
goto P_0c05eee0;
P_0c05eee0: /* original 8801, guest PC 0x0c05eee0 */
if(!s->budget--) { s->failed_pc=0x0c05eee0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05eee2;
P_0c05eee2: /* original 890a, guest PC 0x0c05eee2 */
if(!s->budget--) { s->failed_pc=0x0c05eee2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05eefa; }
goto P_0c05eee4;
P_0c05eee4: /* original 8802, guest PC 0x0c05eee4 */
if(!s->budget--) { s->failed_pc=0x0c05eee4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05eee6;
P_0c05eee6: /* original 890b, guest PC 0x0c05eee6 */
if(!s->budget--) { s->failed_pc=0x0c05eee6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef00; }
goto P_0c05eee8;
P_0c05eee8: /* original 8803, guest PC 0x0c05eee8 */
if(!s->budget--) { s->failed_pc=0x0c05eee8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05eeea;
P_0c05eeea: /* original 890c, guest PC 0x0c05eeea */
if(!s->budget--) { s->failed_pc=0x0c05eeeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef06; }
goto P_0c05eeec;
P_0c05eeec: /* original 8804, guest PC 0x0c05eeec */
if(!s->budget--) { s->failed_pc=0x0c05eeecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05eeee;
P_0c05eeee: /* original 890d, guest PC 0x0c05eeee */
if(!s->budget--) { s->failed_pc=0x0c05eeeeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef0c; }
goto P_0c05eef0;
P_0c05eef0: /* original a026, guest PC 0x0c05eef0 */
if(!s->budget--) { s->failed_pc=0x0c05eef0u; return 0; }
goto P_0c05ef40;
P_0c05eef2: /* original 0009, guest PC 0x0c05eef2 */
if(!s->budget--) { s->failed_pc=0x0c05eef2u; return 0; }
goto P_0c05eef4;
P_0c05eef4: /* original e300, guest PC 0x0c05eef4 */
if(!s->budget--) { s->failed_pc=0x0c05eef4u; return 0; }
r[3]=0x00000000u;
goto P_0c05eef6;
P_0c05eef6: /* original a024, guest PC 0x0c05eef6 */
if(!s->budget--) { s->failed_pc=0x0c05eef6u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c05ef42;
P_0c05eef8: /* original 1432, guest PC 0x0c05eef8 */
if(!s->budget--) { s->failed_pc=0x0c05eef8u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c05eefa;
P_0c05eefa: /* original d10d, guest PC 0x0c05eefa */
if(!s->budget--) { s->failed_pc=0x0c05eefau; return 0; }
r[1]=read(ram,0x0c05ef30u,4);
goto P_0c05eefc;
P_0c05eefc: /* original a004, guest PC 0x0c05eefc */
if(!s->budget--) { s->failed_pc=0x0c05eefcu; return 0; }
goto P_0c05ef08;
P_0c05eefe: /* original 0009, guest PC 0x0c05eefe */
if(!s->budget--) { s->failed_pc=0x0c05eefeu; return 0; }
goto P_0c05ef00;
P_0c05ef00: /* original d20c, guest PC 0x0c05ef00 */
if(!s->budget--) { s->failed_pc=0x0c05ef00u; return 0; }
r[2]=read(ram,0x0c05ef34u,4);
goto P_0c05ef02;
P_0c05ef02: /* original a004, guest PC 0x0c05ef02 */
if(!s->budget--) { s->failed_pc=0x0c05ef02u; return 0; }
goto P_0c05ef0e;
P_0c05ef04: /* original 0009, guest PC 0x0c05ef04 */
if(!s->budget--) { s->failed_pc=0x0c05ef04u; return 0; }
goto P_0c05ef06;
P_0c05ef06: /* original d10c, guest PC 0x0c05ef06 */
if(!s->budget--) { s->failed_pc=0x0c05ef06u; return 0; }
r[1]=read(ram,0x0c05ef38u,4);
goto P_0c05ef08;
P_0c05ef08: /* original a01b, guest PC 0x0c05ef08 */
if(!s->budget--) { s->failed_pc=0x0c05ef08u; return 0; }
write(ram,r[4]+8,r[1],4);
goto P_0c05ef42;
P_0c05ef0a: /* original 1412, guest PC 0x0c05ef0a */
if(!s->budget--) { s->failed_pc=0x0c05ef0au; return 0; }
write(ram,r[4]+8,r[1],4);
goto P_0c05ef0c;
P_0c05ef0c: /* original d20b, guest PC 0x0c05ef0c */
if(!s->budget--) { s->failed_pc=0x0c05ef0cu; return 0; }
r[2]=read(ram,0x0c05ef3cu,4);
goto P_0c05ef0e;
P_0c05ef0e: /* original a018, guest PC 0x0c05ef0e */
if(!s->budget--) { s->failed_pc=0x0c05ef0eu; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c05ef42;
P_0c05ef10: /* original 1422, guest PC 0x0c05ef10 */
if(!s->budget--) { s->failed_pc=0x0c05ef10u; return 0; }
write(ram,r[4]+8,r[2],4);
return vf3_matrix_family(0x0c05ef12u,s,ram);
P_0c05ef40: /* original ed04, guest PC 0x0c05ef40 */
if(!s->budget--) { s->failed_pc=0x0c05ef40u; return 0; }
r[13]=0x00000004u;
goto P_0c05ef42;
P_0c05ef42: /* original 1453, guest PC 0x0c05ef42 */
if(!s->budget--) { s->failed_pc=0x0c05ef42u; return 0; }
write(ram,r[4]+12,r[5],4);
goto P_0c05ef44;
P_0c05ef44: /* original 6053, guest PC 0x0c05ef44 */
if(!s->budget--) { s->failed_pc=0x0c05ef44u; return 0; }
r[0]=r[5];
goto P_0c05ef46;
P_0c05ef46: /* original 0009, guest PC 0x0c05ef46 */
if(!s->budget--) { s->failed_pc=0x0c05ef46u; return 0; }
goto P_0c05ef48;
P_0c05ef48: /* original 8808, guest PC 0x0c05ef48 */
if(!s->budget--) { s->failed_pc=0x0c05ef48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05ef4a;
P_0c05ef4a: /* original 8d13, guest PC 0x0c05ef4a */
if(!s->budget--) { s->failed_pc=0x0c05ef4au; return 0; }
cond=r[17]&1u;
write(ram,r[4]+16,r[6],4);
if(cond) { goto P_0c05ef74; }
goto P_0c05ef4e;
P_0c05ef4c: /* original 1464, guest PC 0x0c05ef4c */
if(!s->budget--) { s->failed_pc=0x0c05ef4cu; return 0; }
write(ram,r[4]+16,r[6],4);
goto P_0c05ef4e;
P_0c05ef4e: /* original 8810, guest PC 0x0c05ef4e */
if(!s->budget--) { s->failed_pc=0x0c05ef4eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c05ef50;
P_0c05ef50: /* original 8910, guest PC 0x0c05ef50 */
if(!s->budget--) { s->failed_pc=0x0c05ef50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef52;
P_0c05ef52: /* original 8820, guest PC 0x0c05ef52 */
if(!s->budget--) { s->failed_pc=0x0c05ef52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05ef54;
P_0c05ef54: /* original 890e, guest PC 0x0c05ef54 */
if(!s->budget--) { s->failed_pc=0x0c05ef54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef56;
P_0c05ef56: /* original 8840, guest PC 0x0c05ef56 */
if(!s->budget--) { s->failed_pc=0x0c05ef56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c05ef58;
P_0c05ef58: /* original 890c, guest PC 0x0c05ef58 */
if(!s->budget--) { s->failed_pc=0x0c05ef58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef5a;
P_0c05ef5a: /* original 914f, guest PC 0x0c05ef5a */
if(!s->budget--) { s->failed_pc=0x0c05ef5au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05effcu,2);
goto P_0c05ef5c;
P_0c05ef5c: /* original 3010, guest PC 0x0c05ef5c */
if(!s->budget--) { s->failed_pc=0x0c05ef5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef5e;
P_0c05ef5e: /* original 8909, guest PC 0x0c05ef5e */
if(!s->budget--) { s->failed_pc=0x0c05ef5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef60;
P_0c05ef60: /* original 914d, guest PC 0x0c05ef60 */
if(!s->budget--) { s->failed_pc=0x0c05ef60u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05effeu,2);
goto P_0c05ef62;
P_0c05ef62: /* original 3010, guest PC 0x0c05ef62 */
if(!s->budget--) { s->failed_pc=0x0c05ef62u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef64;
P_0c05ef64: /* original 8906, guest PC 0x0c05ef64 */
if(!s->budget--) { s->failed_pc=0x0c05ef64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef66;
P_0c05ef66: /* original 914b, guest PC 0x0c05ef66 */
if(!s->budget--) { s->failed_pc=0x0c05ef66u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f000u,2);
goto P_0c05ef68;
P_0c05ef68: /* original 3010, guest PC 0x0c05ef68 */
if(!s->budget--) { s->failed_pc=0x0c05ef68u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef6a;
P_0c05ef6a: /* original 8903, guest PC 0x0c05ef6a */
if(!s->budget--) { s->failed_pc=0x0c05ef6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef6c;
P_0c05ef6c: /* original 9149, guest PC 0x0c05ef6c */
if(!s->budget--) { s->failed_pc=0x0c05ef6cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f002u,2);
goto P_0c05ef6e;
P_0c05ef6e: /* original 3010, guest PC 0x0c05ef6e */
if(!s->budget--) { s->failed_pc=0x0c05ef6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef70;
P_0c05ef70: /* original 8900, guest PC 0x0c05ef70 */
if(!s->budget--) { s->failed_pc=0x0c05ef70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ef74; }
goto P_0c05ef72;
P_0c05ef72: /* original ed04, guest PC 0x0c05ef72 */
if(!s->budget--) { s->failed_pc=0x0c05ef72u; return 0; }
r[13]=0x00000004u;
goto P_0c05ef74;
P_0c05ef74: /* original 6063, guest PC 0x0c05ef74 */
if(!s->budget--) { s->failed_pc=0x0c05ef74u; return 0; }
r[0]=r[6];
goto P_0c05ef76;
P_0c05ef76: /* original 0009, guest PC 0x0c05ef76 */
if(!s->budget--) { s->failed_pc=0x0c05ef76u; return 0; }
goto P_0c05ef78;
P_0c05ef78: /* original 8808, guest PC 0x0c05ef78 */
if(!s->budget--) { s->failed_pc=0x0c05ef78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05ef7a;
P_0c05ef7a: /* original 8912, guest PC 0x0c05ef7a */
if(!s->budget--) { s->failed_pc=0x0c05ef7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef7c;
P_0c05ef7c: /* original 8810, guest PC 0x0c05ef7c */
if(!s->budget--) { s->failed_pc=0x0c05ef7cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c05ef7e;
P_0c05ef7e: /* original 8910, guest PC 0x0c05ef7e */
if(!s->budget--) { s->failed_pc=0x0c05ef7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef80;
P_0c05ef80: /* original 8820, guest PC 0x0c05ef80 */
if(!s->budget--) { s->failed_pc=0x0c05ef80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05ef82;
P_0c05ef82: /* original 890e, guest PC 0x0c05ef82 */
if(!s->budget--) { s->failed_pc=0x0c05ef82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef84;
P_0c05ef84: /* original 8840, guest PC 0x0c05ef84 */
if(!s->budget--) { s->failed_pc=0x0c05ef84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c05ef86;
P_0c05ef86: /* original 890c, guest PC 0x0c05ef86 */
if(!s->budget--) { s->failed_pc=0x0c05ef86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef88;
P_0c05ef88: /* original 9138, guest PC 0x0c05ef88 */
if(!s->budget--) { s->failed_pc=0x0c05ef88u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05effcu,2);
goto P_0c05ef8a;
P_0c05ef8a: /* original 3010, guest PC 0x0c05ef8a */
if(!s->budget--) { s->failed_pc=0x0c05ef8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef8c;
P_0c05ef8c: /* original 8909, guest PC 0x0c05ef8c */
if(!s->budget--) { s->failed_pc=0x0c05ef8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef8e;
P_0c05ef8e: /* original 9136, guest PC 0x0c05ef8e */
if(!s->budget--) { s->failed_pc=0x0c05ef8eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05effeu,2);
goto P_0c05ef90;
P_0c05ef90: /* original 3010, guest PC 0x0c05ef90 */
if(!s->budget--) { s->failed_pc=0x0c05ef90u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef92;
P_0c05ef92: /* original 8906, guest PC 0x0c05ef92 */
if(!s->budget--) { s->failed_pc=0x0c05ef92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef94;
P_0c05ef94: /* original 9134, guest PC 0x0c05ef94 */
if(!s->budget--) { s->failed_pc=0x0c05ef94u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f000u,2);
goto P_0c05ef96;
P_0c05ef96: /* original 3010, guest PC 0x0c05ef96 */
if(!s->budget--) { s->failed_pc=0x0c05ef96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef98;
P_0c05ef98: /* original 8903, guest PC 0x0c05ef98 */
if(!s->budget--) { s->failed_pc=0x0c05ef98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05ef9a;
P_0c05ef9a: /* original 9132, guest PC 0x0c05ef9a */
if(!s->budget--) { s->failed_pc=0x0c05ef9au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f002u,2);
goto P_0c05ef9c;
P_0c05ef9c: /* original 3010, guest PC 0x0c05ef9c */
if(!s->budget--) { s->failed_pc=0x0c05ef9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05ef9e;
P_0c05ef9e: /* original 8900, guest PC 0x0c05ef9e */
if(!s->budget--) { s->failed_pc=0x0c05ef9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efa2; }
goto P_0c05efa0;
P_0c05efa0: /* original ed04, guest PC 0x0c05efa0 */
if(!s->budget--) { s->failed_pc=0x0c05efa0u; return 0; }
r[13]=0x00000004u;
goto P_0c05efa2;
P_0c05efa2: /* original 932f, guest PC 0x0c05efa2 */
if(!s->budget--) { s->failed_pc=0x0c05efa2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f004u,2);
goto P_0c05efa4;
P_0c05efa4: /* original 3e30, guest PC 0x0c05efa4 */
if(!s->budget--) { s->failed_pc=0x0c05efa4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05efa6;
P_0c05efa6: /* original 890e, guest PC 0x0c05efa6 */
if(!s->budget--) { s->failed_pc=0x0c05efa6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efa8;
P_0c05efa8: /* original 912d, guest PC 0x0c05efa8 */
if(!s->budget--) { s->failed_pc=0x0c05efa8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f006u,2);
goto P_0c05efaa;
P_0c05efaa: /* original 3e10, guest PC 0x0c05efaa */
if(!s->budget--) { s->failed_pc=0x0c05efaau; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05efac;
P_0c05efac: /* original 890b, guest PC 0x0c05efac */
if(!s->budget--) { s->failed_pc=0x0c05efacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efae;
P_0c05efae: /* original 902b, guest PC 0x0c05efae */
if(!s->budget--) { s->failed_pc=0x0c05efaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f008u,2);
goto P_0c05efb0;
P_0c05efb0: /* original 3e00, guest PC 0x0c05efb0 */
if(!s->budget--) { s->failed_pc=0x0c05efb0u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05efb2;
P_0c05efb2: /* original 8908, guest PC 0x0c05efb2 */
if(!s->budget--) { s->failed_pc=0x0c05efb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efb4;
P_0c05efb4: /* original 9229, guest PC 0x0c05efb4 */
if(!s->budget--) { s->failed_pc=0x0c05efb4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f00au,2);
goto P_0c05efb6;
P_0c05efb6: /* original 3e20, guest PC 0x0c05efb6 */
if(!s->budget--) { s->failed_pc=0x0c05efb6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05efb8;
P_0c05efb8: /* original 8905, guest PC 0x0c05efb8 */
if(!s->budget--) { s->failed_pc=0x0c05efb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efba;
P_0c05efba: /* original 9127, guest PC 0x0c05efba */
if(!s->budget--) { s->failed_pc=0x0c05efbau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f00cu,2);
goto P_0c05efbc;
P_0c05efbc: /* original 3e10, guest PC 0x0c05efbc */
if(!s->budget--) { s->failed_pc=0x0c05efbcu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05efbe;
P_0c05efbe: /* original 8902, guest PC 0x0c05efbe */
if(!s->budget--) { s->failed_pc=0x0c05efbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efc0;
P_0c05efc0: /* original 3560, guest PC 0x0c05efc0 */
if(!s->budget--) { s->failed_pc=0x0c05efc0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c05efc2;
P_0c05efc2: /* original 8900, guest PC 0x0c05efc2 */
if(!s->budget--) { s->failed_pc=0x0c05efc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efc6; }
goto P_0c05efc4;
P_0c05efc4: /* original ed04, guest PC 0x0c05efc4 */
if(!s->budget--) { s->failed_pc=0x0c05efc4u; return 0; }
r[13]=0x00000004u;
goto P_0c05efc6;
P_0c05efc6: /* original e300, guest PC 0x0c05efc6 */
if(!s->budget--) { s->failed_pc=0x0c05efc6u; return 0; }
r[3]=0x00000000u;
goto P_0c05efc8;
P_0c05efc8: /* original 9221, guest PC 0x0c05efc8 */
if(!s->budget--) { s->failed_pc=0x0c05efc8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f00eu,2);
goto P_0c05efca;
P_0c05efca: /* original 1436, guest PC 0x0c05efca */
if(!s->budget--) { s->failed_pc=0x0c05efcau; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c05efcc;
P_0c05efcc: /* original 3e20, guest PC 0x0c05efcc */
if(!s->budget--) { s->failed_pc=0x0c05efccu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05efce;
P_0c05efce: /* original 890e, guest PC 0x0c05efce */
if(!s->budget--) { s->failed_pc=0x0c05efceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efd0;
P_0c05efd0: /* original 9116, guest PC 0x0c05efd0 */
if(!s->budget--) { s->failed_pc=0x0c05efd0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f000u,2);
goto P_0c05efd2;
P_0c05efd2: /* original 3e10, guest PC 0x0c05efd2 */
if(!s->budget--) { s->failed_pc=0x0c05efd2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05efd4;
P_0c05efd4: /* original 890b, guest PC 0x0c05efd4 */
if(!s->budget--) { s->failed_pc=0x0c05efd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efd6;
P_0c05efd6: /* original 9014, guest PC 0x0c05efd6 */
if(!s->budget--) { s->failed_pc=0x0c05efd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f002u,2);
goto P_0c05efd8;
P_0c05efd8: /* original 3e00, guest PC 0x0c05efd8 */
if(!s->budget--) { s->failed_pc=0x0c05efd8u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05efda;
P_0c05efda: /* original 8908, guest PC 0x0c05efda */
if(!s->budget--) { s->failed_pc=0x0c05efdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efdc;
P_0c05efdc: /* original 9218, guest PC 0x0c05efdc */
if(!s->budget--) { s->failed_pc=0x0c05efdcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f010u,2);
goto P_0c05efde;
P_0c05efde: /* original 3e20, guest PC 0x0c05efde */
if(!s->budget--) { s->failed_pc=0x0c05efdeu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05efe0;
P_0c05efe0: /* original 8905, guest PC 0x0c05efe0 */
if(!s->budget--) { s->failed_pc=0x0c05efe0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efe2;
P_0c05efe2: /* original 9116, guest PC 0x0c05efe2 */
if(!s->budget--) { s->failed_pc=0x0c05efe2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f012u,2);
goto P_0c05efe4;
P_0c05efe4: /* original 3e10, guest PC 0x0c05efe4 */
if(!s->budget--) { s->failed_pc=0x0c05efe4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05efe6;
P_0c05efe6: /* original 8902, guest PC 0x0c05efe6 */
if(!s->budget--) { s->failed_pc=0x0c05efe6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05efee; }
goto P_0c05efe8;
P_0c05efe8: /* original 9214, guest PC 0x0c05efe8 */
if(!s->budget--) { s->failed_pc=0x0c05efe8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f014u,2);
goto P_0c05efea;
P_0c05efea: /* original 3e20, guest PC 0x0c05efea */
if(!s->budget--) { s->failed_pc=0x0c05efeau; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05efec;
P_0c05efec: /* original 8b02, guest PC 0x0c05efec */
if(!s->budget--) { s->failed_pc=0x0c05efecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05eff4; }
goto P_0c05efee;
P_0c05efee: /* original 5146, guest PC 0x0c05efee */
if(!s->budget--) { s->failed_pc=0x0c05efeeu; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c05eff0;
P_0c05eff0: /* original 217b, guest PC 0x0c05eff0 */
if(!s->budget--) { s->failed_pc=0x0c05eff0u; return 0; }
r[1]|=r[7];
goto P_0c05eff2;
P_0c05eff2: /* original 1416, guest PC 0x0c05eff2 */
if(!s->budget--) { s->failed_pc=0x0c05eff2u; return 0; }
write(ram,r[4]+24,r[1],4);
goto P_0c05eff4;
P_0c05eff4: /* original 930f, guest PC 0x0c05eff4 */
if(!s->budget--) { s->failed_pc=0x0c05eff4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f016u,2);
goto P_0c05eff6;
P_0c05eff6: /* original 3e30, guest PC 0x0c05eff6 */
if(!s->budget--) { s->failed_pc=0x0c05eff6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05eff8;
P_0c05eff8: /* original a00e, guest PC 0x0c05eff8 */
if(!s->budget--) { s->failed_pc=0x0c05eff8u; return 0; }
r[5]=0x00000004u;
goto P_0c05f018;
P_0c05effa: /* original e504, guest PC 0x0c05effa */
if(!s->budget--) { s->failed_pc=0x0c05effau; return 0; }
r[5]=0x00000004u;
return vf3_matrix_family(0x0c05effcu,s,ram);
P_0c05f018: /* original 8d0c, guest PC 0x0c05f018 */
if(!s->budget--) { s->failed_pc=0x0c05f018u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f034; }
goto P_0c05f01c;
P_0c05f01a: /* original 0009, guest PC 0x0c05f01a */
if(!s->budget--) { s->failed_pc=0x0c05f01au; return 0; }
goto P_0c05f01c;
P_0c05f01c: /* original 913f, guest PC 0x0c05f01c */
if(!s->budget--) { s->failed_pc=0x0c05f01cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f09eu,2);
goto P_0c05f01e;
P_0c05f01e: /* original 3e10, guest PC 0x0c05f01e */
if(!s->budget--) { s->failed_pc=0x0c05f01eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05f020;
P_0c05f020: /* original 8908, guest PC 0x0c05f020 */
if(!s->budget--) { s->failed_pc=0x0c05f020u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f034; }
goto P_0c05f022;
P_0c05f022: /* original 903d, guest PC 0x0c05f022 */
if(!s->budget--) { s->failed_pc=0x0c05f022u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a0u,2);
goto P_0c05f024;
P_0c05f024: /* original 3e00, guest PC 0x0c05f024 */
if(!s->budget--) { s->failed_pc=0x0c05f024u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05f026;
P_0c05f026: /* original 8905, guest PC 0x0c05f026 */
if(!s->budget--) { s->failed_pc=0x0c05f026u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f034; }
goto P_0c05f028;
P_0c05f028: /* original 923b, guest PC 0x0c05f028 */
if(!s->budget--) { s->failed_pc=0x0c05f028u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a2u,2);
goto P_0c05f02a;
P_0c05f02a: /* original 3e20, guest PC 0x0c05f02a */
if(!s->budget--) { s->failed_pc=0x0c05f02au; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05f02c;
P_0c05f02c: /* original 8902, guest PC 0x0c05f02c */
if(!s->budget--) { s->failed_pc=0x0c05f02cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f034; }
goto P_0c05f02e;
P_0c05f02e: /* original 9139, guest PC 0x0c05f02e */
if(!s->budget--) { s->failed_pc=0x0c05f02eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a4u,2);
goto P_0c05f030;
P_0c05f030: /* original 3e10, guest PC 0x0c05f030 */
if(!s->budget--) { s->failed_pc=0x0c05f030u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05f032;
P_0c05f032: /* original 8b02, guest PC 0x0c05f032 */
if(!s->budget--) { s->failed_pc=0x0c05f032u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f03a; }
goto P_0c05f034;
P_0c05f034: /* original 5246, guest PC 0x0c05f034 */
if(!s->budget--) { s->failed_pc=0x0c05f034u; return 0; }
r[2]=read(ram,r[4]+24,4);
goto P_0c05f036;
P_0c05f036: /* original 225b, guest PC 0x0c05f036 */
if(!s->budget--) { s->failed_pc=0x0c05f036u; return 0; }
r[2]|=r[5];
goto P_0c05f038;
P_0c05f038: /* original 1426, guest PC 0x0c05f038 */
if(!s->budget--) { s->failed_pc=0x0c05f038u; return 0; }
write(ram,r[4]+24,r[2],4);
goto P_0c05f03a;
P_0c05f03a: /* original 9334, guest PC 0x0c05f03a */
if(!s->budget--) { s->failed_pc=0x0c05f03au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a6u,2);
goto P_0c05f03c;
P_0c05f03c: /* original 3e30, guest PC 0x0c05f03c */
if(!s->budget--) { s->failed_pc=0x0c05f03cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05f03e;
P_0c05f03e: /* original 8908, guest PC 0x0c05f03e */
if(!s->budget--) { s->failed_pc=0x0c05f03eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f052; }
goto P_0c05f040;
P_0c05f040: /* original 9132, guest PC 0x0c05f040 */
if(!s->budget--) { s->failed_pc=0x0c05f040u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0a8u,2);
goto P_0c05f042;
P_0c05f042: /* original 3e10, guest PC 0x0c05f042 */
if(!s->budget--) { s->failed_pc=0x0c05f042u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05f044;
P_0c05f044: /* original 8905, guest PC 0x0c05f044 */
if(!s->budget--) { s->failed_pc=0x0c05f044u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f052; }
goto P_0c05f046;
P_0c05f046: /* original 9030, guest PC 0x0c05f046 */
if(!s->budget--) { s->failed_pc=0x0c05f046u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0aau,2);
goto P_0c05f048;
P_0c05f048: /* original 3e00, guest PC 0x0c05f048 */
if(!s->budget--) { s->failed_pc=0x0c05f048u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05f04a;
P_0c05f04a: /* original 8902, guest PC 0x0c05f04a */
if(!s->budget--) { s->failed_pc=0x0c05f04au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f052; }
goto P_0c05f04c;
P_0c05f04c: /* original 922e, guest PC 0x0c05f04c */
if(!s->budget--) { s->failed_pc=0x0c05f04cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0acu,2);
goto P_0c05f04e;
P_0c05f04e: /* original 3e20, guest PC 0x0c05f04e */
if(!s->budget--) { s->failed_pc=0x0c05f04eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05f050;
P_0c05f050: /* original 8b04, guest PC 0x0c05f050 */
if(!s->budget--) { s->failed_pc=0x0c05f050u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f05c; }
goto P_0c05f052;
P_0c05f052: /* original 5046, guest PC 0x0c05f052 */
if(!s->budget--) { s->failed_pc=0x0c05f052u; return 0; }
r[0]=read(ram,r[4]+24,4);
goto P_0c05f054;
P_0c05f054: /* original cb08, guest PC 0x0c05f054 */
if(!s->budget--) { s->failed_pc=0x0c05f054u; return 0; }
r[0]|=8u;
goto P_0c05f056;
P_0c05f056: /* original 6203, guest PC 0x0c05f056 */
if(!s->budget--) { s->failed_pc=0x0c05f056u; return 0; }
r[2]=r[0];
goto P_0c05f058;
P_0c05f058: /* original 225b, guest PC 0x0c05f058 */
if(!s->budget--) { s->failed_pc=0x0c05f058u; return 0; }
r[2]|=r[5];
goto P_0c05f05a;
P_0c05f05a: /* original 1426, guest PC 0x0c05f05a */
if(!s->budget--) { s->failed_pc=0x0c05f05au; return 0; }
write(ram,r[4]+24,r[2],4);
goto P_0c05f05c;
P_0c05f05c: /* original 9327, guest PC 0x0c05f05c */
if(!s->budget--) { s->failed_pc=0x0c05f05cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0aeu,2);
goto P_0c05f05e;
P_0c05f05e: /* original 3e30, guest PC 0x0c05f05e */
if(!s->budget--) { s->failed_pc=0x0c05f05eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05f060;
P_0c05f060: /* original 8b02, guest PC 0x0c05f060 */
if(!s->budget--) { s->failed_pc=0x0c05f060u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f068; }
goto P_0c05f062;
P_0c05f062: /* original 5046, guest PC 0x0c05f062 */
if(!s->budget--) { s->failed_pc=0x0c05f062u; return 0; }
r[0]=read(ram,r[4]+24,4);
goto P_0c05f064;
P_0c05f064: /* original cb10, guest PC 0x0c05f064 */
if(!s->budget--) { s->failed_pc=0x0c05f064u; return 0; }
r[0]|=16u;
goto P_0c05f066;
P_0c05f066: /* original 1406, guest PC 0x0c05f066 */
if(!s->budget--) { s->failed_pc=0x0c05f066u; return 0; }
write(ram,r[4]+24,r[0],4);
goto P_0c05f068;
P_0c05f068: /* original 9322, guest PC 0x0c05f068 */
if(!s->budget--) { s->failed_pc=0x0c05f068u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0b0u,2);
goto P_0c05f06a;
P_0c05f06a: /* original 3e30, guest PC 0x0c05f06a */
if(!s->budget--) { s->failed_pc=0x0c05f06au; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c05f06c;
P_0c05f06c: /* original 8908, guest PC 0x0c05f06c */
if(!s->budget--) { s->failed_pc=0x0c05f06cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f080; }
goto P_0c05f06e;
P_0c05f06e: /* original 9120, guest PC 0x0c05f06e */
if(!s->budget--) { s->failed_pc=0x0c05f06eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0b2u,2);
goto P_0c05f070;
P_0c05f070: /* original 3e10, guest PC 0x0c05f070 */
if(!s->budget--) { s->failed_pc=0x0c05f070u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c05f072;
P_0c05f072: /* original 8905, guest PC 0x0c05f072 */
if(!s->budget--) { s->failed_pc=0x0c05f072u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f080; }
goto P_0c05f074;
P_0c05f074: /* original 901e, guest PC 0x0c05f074 */
if(!s->budget--) { s->failed_pc=0x0c05f074u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0b4u,2);
goto P_0c05f076;
P_0c05f076: /* original 3e00, guest PC 0x0c05f076 */
if(!s->budget--) { s->failed_pc=0x0c05f076u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[0])!=0);
goto P_0c05f078;
P_0c05f078: /* original 8902, guest PC 0x0c05f078 */
if(!s->budget--) { s->failed_pc=0x0c05f078u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f080; }
goto P_0c05f07a;
P_0c05f07a: /* original 921c, guest PC 0x0c05f07a */
if(!s->budget--) { s->failed_pc=0x0c05f07au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f0b6u,2);
goto P_0c05f07c;
P_0c05f07c: /* original 3e20, guest PC 0x0c05f07c */
if(!s->budget--) { s->failed_pc=0x0c05f07cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c05f07e;
P_0c05f07e: /* original 8b04, guest PC 0x0c05f07e */
if(!s->budget--) { s->failed_pc=0x0c05f07eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f08a; }
goto P_0c05f080;
P_0c05f080: /* original 5046, guest PC 0x0c05f080 */
if(!s->budget--) { s->failed_pc=0x0c05f080u; return 0; }
r[0]=read(ram,r[4]+24,4);
goto P_0c05f082;
P_0c05f082: /* original cb20, guest PC 0x0c05f082 */
if(!s->budget--) { s->failed_pc=0x0c05f082u; return 0; }
r[0]|=32u;
goto P_0c05f084;
P_0c05f084: /* original 6203, guest PC 0x0c05f084 */
if(!s->budget--) { s->failed_pc=0x0c05f084u; return 0; }
r[2]=r[0];
goto P_0c05f086;
P_0c05f086: /* original 225b, guest PC 0x0c05f086 */
if(!s->budget--) { s->failed_pc=0x0c05f086u; return 0; }
r[2]|=r[5];
goto P_0c05f088;
P_0c05f088: /* original 1426, guest PC 0x0c05f088 */
if(!s->budget--) { s->failed_pc=0x0c05f088u; return 0; }
write(ram,r[4]+24,r[2],4);
goto P_0c05f08a;
P_0c05f08a: /* original b04d, guest PC 0x0c05f08a */
if(!s->budget--) { s->failed_pc=0x0c05f08au; return 0; }
target=0x0c05f128u; r[16]=code_base|0x0c05f08eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05f08eu) { target=s->pc; goto dispatch; }
goto P_0c05f08e;
P_0c05f08c: /* original 0009, guest PC 0x0c05f08c */
if(!s->budget--) { s->failed_pc=0x0c05f08cu; return 0; }
goto P_0c05f08e;
P_0c05f08e: /* original 60d3, guest PC 0x0c05f08e */
if(!s->budget--) { s->failed_pc=0x0c05f08eu; return 0; }
r[0]=r[13];
goto P_0c05f090;
P_0c05f090: /* original 0009, guest PC 0x0c05f090 */
if(!s->budget--) { s->failed_pc=0x0c05f090u; return 0; }
goto P_0c05f092;
P_0c05f092: /* original 7f04, guest PC 0x0c05f092 */
if(!s->budget--) { s->failed_pc=0x0c05f092u; return 0; }
r[15]+=0x00000004u;
goto P_0c05f094;
P_0c05f094: /* original 4f26, guest PC 0x0c05f094 */
if(!s->budget--) { s->failed_pc=0x0c05f094u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05f096;
P_0c05f096: /* original 6cf6, guest PC 0x0c05f096 */
if(!s->budget--) { s->failed_pc=0x0c05f096u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05f098;
P_0c05f098: /* original 6df6, guest PC 0x0c05f098 */
if(!s->budget--) { s->failed_pc=0x0c05f098u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05f09a;
P_0c05f09a: /* original 000b, guest PC 0x0c05f09a */
if(!s->budget--) { s->failed_pc=0x0c05f09au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05f09c: /* original 6ef6, guest PC 0x0c05f09c */
if(!s->budget--) { s->failed_pc=0x0c05f09cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05f09eu,s,ram);
P_0c060d46: /* original d038, guest PC 0x0c060d46 */
if(!s->budget--) { s->failed_pc=0x0c060d46u; return 0; }
r[0]=read(ram,0x0c060e28u,4);
goto P_0c060d48;
P_0c060d48: /* original 000b, guest PC 0x0c060d48 */
if(!s->budget--) { s->failed_pc=0x0c060d48u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c060d4a: /* original 004e, guest PC 0x0c060d4a */
if(!s->budget--) { s->failed_pc=0x0c060d4au; return 0; }
r[0]=read(ram,r[4]+r[0],4);
return vf3_matrix_family(0x0c060d4cu,s,ram);
P_0c0644bc: /* original d009, guest PC 0x0c0644bc */
if(!s->budget--) { s->failed_pc=0x0c0644bcu; return 0; }
r[0]=read(ram,0x0c0644e4u,4);
goto P_0c0644be;
P_0c0644be: /* original 7ff8, guest PC 0x0c0644be */
if(!s->budget--) { s->failed_pc=0x0c0644beu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0644c0;
P_0c0644c0: /* original 2f42, guest PC 0x0c0644c0 */
if(!s->budget--) { s->failed_pc=0x0c0644c0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0644c2;
P_0c0644c2: /* original 6343, guest PC 0x0c0644c2 */
if(!s->budget--) { s->failed_pc=0x0c0644c2u; return 0; }
r[3]=r[4];
goto P_0c0644c4;
P_0c0644c4: /* original 4308, guest PC 0x0c0644c4 */
if(!s->budget--) { s->failed_pc=0x0c0644c4u; return 0; }
r[3]<<=2;
goto P_0c0644c6;
P_0c0644c6: /* original 4300, guest PC 0x0c0644c6 */
if(!s->budget--) { s->failed_pc=0x0c0644c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0644c8;
P_0c0644c8: /* original 1f31, guest PC 0x0c0644c8 */
if(!s->budget--) { s->failed_pc=0x0c0644c8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0644ca;
P_0c0644ca: /* original 023e, guest PC 0x0c0644ca */
if(!s->budget--) { s->failed_pc=0x0c0644cau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0644cc;
P_0c0644cc: /* original 6403, guest PC 0x0c0644cc */
if(!s->budget--) { s->failed_pc=0x0c0644ccu; return 0; }
r[4]=r[0];
goto P_0c0644ce;
P_0c0644ce: /* original 343c, guest PC 0x0c0644ce */
if(!s->budget--) { s->failed_pc=0x0c0644ceu; return 0; }
r[4]+=r[3];
goto P_0c0644d0;
P_0c0644d0: /* original 5441, guest PC 0x0c0644d0 */
if(!s->budget--) { s->failed_pc=0x0c0644d0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0644d2;
P_0c0644d2: /* original 422b, guest PC 0x0c0644d2 */
if(!s->budget--) { s->failed_pc=0x0c0644d2u; return 0; }
target=r[2];
r[15]+=0x00000008u;
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
P_0c0644d4: /* original 7f08, guest PC 0x0c0644d4 */
if(!s->budget--) { s->failed_pc=0x0c0644d4u; return 0; }
r[15]+=0x00000008u;
return vf3_matrix_family(0x0c0644d6u,s,ram);
P_0c06ac7a: /* original 4f22, guest PC 0x0c06ac7a */
if(!s->budget--) { s->failed_pc=0x0c06ac7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06ac7c;
P_0c06ac7c: /* original f28d, guest PC 0x0c06ac7c */
if(!s->budget--) { s->failed_pc=0x0c06ac7cu; return 0; }
fr[2]=0;
goto P_0c06ac7e;
P_0c06ac7e: /* original f32d, guest PC 0x0c06ac7e */
if(!s->budget--) { s->failed_pc=0x0c06ac7eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06ac80;
P_0c06ac80: /* original f508, guest PC 0x0c06ac80 */
if(!s->budget--) { s->failed_pc=0x0c06ac80u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06ac82;
P_0c06ac82: /* original 4f12, guest PC 0x0c06ac82 */
if(!s->budget--) { s->failed_pc=0x0c06ac82u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06ac84;
P_0c06ac84: /* original 7ffc, guest PC 0x0c06ac84 */
if(!s->budget--) { s->failed_pc=0x0c06ac84u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06ac86;
P_0c06ac86: /* original f235, guest PC 0x0c06ac86 */
if(!s->budget--) { s->failed_pc=0x0c06ac86u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c06ac88;
P_0c06ac88: /* original 8f03, guest PC 0x0c06ac88 */
if(!s->budget--) { s->failed_pc=0x0c06ac88u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c06ac92; }
goto P_0c06ac8c;
P_0c06ac8a: /* original f43c, guest PC 0x0c06ac8a */
if(!s->budget--) { s->failed_pc=0x0c06ac8au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06ac8c;
P_0c06ac8c: /* original c752, guest PC 0x0c06ac8c */
if(!s->budget--) { s->failed_pc=0x0c06ac8cu; return 0; }
r[0]=0x0c06add8u;
goto P_0c06ac8e;
P_0c06ac8e: /* original f308, guest PC 0x0c06ac8e */
if(!s->budget--) { s->failed_pc=0x0c06ac8eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06ac90;
P_0c06ac90: /* original f430, guest PC 0x0c06ac90 */
if(!s->budget--) { s->failed_pc=0x0c06ac90u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c06ac92;
P_0c06ac92: /* original f64c, guest PC 0x0c06ac92 */
if(!s->budget--) { s->failed_pc=0x0c06ac92u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c06ac94;
P_0c06ac94: /* original f653, guest PC 0x0c06ac94 */
if(!s->budget--) { s->failed_pc=0x0c06ac94u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'/');
goto P_0c06ac96;
P_0c06ac96: /* original d351, guest PC 0x0c06ac96 */
if(!s->budget--) { s->failed_pc=0x0c06ac96u; return 0; }
r[3]=read(ram,0x0c06addcu,4);
goto P_0c06ac98;
P_0c06ac98: /* original e63c, guest PC 0x0c06ac98 */
if(!s->budget--) { s->failed_pc=0x0c06ac98u; return 0; }
r[6]=0x0000003cu;
goto P_0c06ac9a;
P_0c06ac9a: /* original f63d, guest PC 0x0c06ac9a */
if(!s->budget--) { s->failed_pc=0x0c06ac9au; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c06ac9c;
P_0c06ac9c: /* original 055a, guest PC 0x0c06ac9c */
if(!s->budget--) { s->failed_pc=0x0c06ac9cu; return 0; }
r[5]=r[53];
goto P_0c06ac9e;
P_0c06ac9e: /* original 455a, guest PC 0x0c06ac9e */
if(!s->budget--) { s->failed_pc=0x0c06ac9eu; return 0; }
r[53]=r[5];
goto P_0c06aca0;
P_0c06aca0: /* original f32d, guest PC 0x0c06aca0 */
if(!s->budget--) { s->failed_pc=0x0c06aca0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06aca2;
P_0c06aca2: /* original f63c, guest PC 0x0c06aca2 */
if(!s->budget--) { s->failed_pc=0x0c06aca2u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c06aca4;
P_0c06aca4: /* original f562, guest PC 0x0c06aca4 */
if(!s->budget--) { s->failed_pc=0x0c06aca4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c06aca6;
P_0c06aca6: /* original f63d, guest PC 0x0c06aca6 */
if(!s->budget--) { s->failed_pc=0x0c06aca6u; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c06aca8;
P_0c06aca8: /* original f451, guest PC 0x0c06aca8 */
if(!s->budget--) { s->failed_pc=0x0c06aca8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c06acaa;
P_0c06acaa: /* original 075a, guest PC 0x0c06acaa */
if(!s->budget--) { s->failed_pc=0x0c06acaau; return 0; }
r[7]=r[53];
goto P_0c06acac;
P_0c06acac: /* original f43d, guest PC 0x0c06acac */
if(!s->budget--) { s->failed_pc=0x0c06acacu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c06acae;
P_0c06acae: /* original 6173, guest PC 0x0c06acae */
if(!s->budget--) { s->failed_pc=0x0c06acaeu; return 0; }
r[1]=r[7];
goto P_0c06acb0;
P_0c06acb0: /* original 055a, guest PC 0x0c06acb0 */
if(!s->budget--) { s->failed_pc=0x0c06acb0u; return 0; }
r[5]=r[53];
goto P_0c06acb2;
P_0c06acb2: /* original 430b, guest PC 0x0c06acb2 */
if(!s->budget--) { s->failed_pc=0x0c06acb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c06acb6u;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06acb6u) { target=s->pc; goto dispatch; }
goto P_0c06acb6;
P_0c06acb4: /* original 6063, guest PC 0x0c06acb4 */
if(!s->budget--) { s->failed_pc=0x0c06acb4u; return 0; }
r[0]=r[6];
goto P_0c06acb6;
P_0c06acb6: /* original 6d03, guest PC 0x0c06acb6 */
if(!s->budget--) { s->failed_pc=0x0c06acb6u; return 0; }
r[13]=r[0];
goto P_0c06acb8;
P_0c06acb8: /* original 61d3, guest PC 0x0c06acb8 */
if(!s->budget--) { s->failed_pc=0x0c06acb8u; return 0; }
r[1]=r[13];
goto P_0c06acba;
P_0c06acba: /* original 0d67, guest PC 0x0c06acba */
if(!s->budget--) { s->failed_pc=0x0c06acbau; return 0; }
r[19]=r[13]*r[6];
goto P_0c06acbc;
P_0c06acbc: /* original 021a, guest PC 0x0c06acbc */
if(!s->budget--) { s->failed_pc=0x0c06acbcu; return 0; }
r[2]=r[19];
goto P_0c06acbe;
P_0c06acbe: /* original 2f22, guest PC 0x0c06acbe */
if(!s->budget--) { s->failed_pc=0x0c06acbeu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06acc0;
P_0c06acc0: /* original 3728, guest PC 0x0c06acc0 */
if(!s->budget--) { s->failed_pc=0x0c06acc0u; return 0; }
r[7]-=r[2];
goto P_0c06acc2;
P_0c06acc2: /* original d346, guest PC 0x0c06acc2 */
if(!s->budget--) { s->failed_pc=0x0c06acc2u; return 0; }
r[3]=read(ram,0x0c06addcu,4);
goto P_0c06acc4;
P_0c06acc4: /* original 430b, guest PC 0x0c06acc4 */
if(!s->budget--) { s->failed_pc=0x0c06acc4u; return 0; }
target=r[3];
r[16]=code_base|0x0c06acc8u;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06acc8u) { target=s->pc; goto dispatch; }
goto P_0c06acc8;
P_0c06acc6: /* original 6063, guest PC 0x0c06acc6 */
if(!s->budget--) { s->failed_pc=0x0c06acc6u; return 0; }
r[0]=r[6];
goto P_0c06acc8;
P_0c06acc8: /* original 6e03, guest PC 0x0c06acc8 */
if(!s->budget--) { s->failed_pc=0x0c06acc8u; return 0; }
r[14]=r[0];
goto P_0c06acca;
P_0c06acca: /* original 0e67, guest PC 0x0c06acca */
if(!s->budget--) { s->failed_pc=0x0c06accau; return 0; }
r[19]=r[14]*r[6];
goto P_0c06accc;
P_0c06accc: /* original 011a, guest PC 0x0c06accc */
if(!s->budget--) { s->failed_pc=0x0c06acccu; return 0; }
r[1]=r[19];
goto P_0c06acce;
P_0c06acce: /* original 3d18, guest PC 0x0c06acce */
if(!s->budget--) { s->failed_pc=0x0c06acceu; return 0; }
r[13]-=r[1];
goto P_0c06acd0;
P_0c06acd0: /* original 2f12, guest PC 0x0c06acd0 */
if(!s->budget--) { s->failed_pc=0x0c06acd0u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06acd2;
P_0c06acd2: /* original d342, guest PC 0x0c06acd2 */
if(!s->budget--) { s->failed_pc=0x0c06acd2u; return 0; }
r[3]=read(ram,0x0c06addcu,4);
goto P_0c06acd4;
P_0c06acd4: /* original 61e3, guest PC 0x0c06acd4 */
if(!s->budget--) { s->failed_pc=0x0c06acd4u; return 0; }
r[1]=r[14];
goto P_0c06acd6;
P_0c06acd6: /* original 430b, guest PC 0x0c06acd6 */
if(!s->budget--) { s->failed_pc=0x0c06acd6u; return 0; }
target=r[3];
r[16]=code_base|0x0c06acdau;
r[0]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06acdau) { target=s->pc; goto dispatch; }
goto P_0c06acda;
P_0c06acd8: /* original e018, guest PC 0x0c06acd8 */
if(!s->budget--) { s->failed_pc=0x0c06acd8u; return 0; }
r[0]=0x00000018u;
goto P_0c06acda;
P_0c06acda: /* original 6103, guest PC 0x0c06acda */
if(!s->budget--) { s->failed_pc=0x0c06acdau; return 0; }
r[1]=r[0];
goto P_0c06acdc;
P_0c06acdc: /* original 4100, guest PC 0x0c06acdc */
if(!s->budget--) { s->failed_pc=0x0c06acdcu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c06acde;
P_0c06acde: /* original 6303, guest PC 0x0c06acde */
if(!s->budget--) { s->failed_pc=0x0c06acdeu; return 0; }
r[3]=r[0];
goto P_0c06ace0;
P_0c06ace0: /* original 313c, guest PC 0x0c06ace0 */
if(!s->budget--) { s->failed_pc=0x0c06ace0u; return 0; }
r[1]+=r[3];
goto P_0c06ace2;
P_0c06ace2: /* original e364, guest PC 0x0c06ace2 */
if(!s->budget--) { s->failed_pc=0x0c06ace2u; return 0; }
r[3]=0x00000064u;
goto P_0c06ace4;
P_0c06ace4: /* original 6c03, guest PC 0x0c06ace4 */
if(!s->budget--) { s->failed_pc=0x0c06ace4u; return 0; }
r[12]=r[0];
goto P_0c06ace6;
P_0c06ace6: /* original 0537, guest PC 0x0c06ace6 */
if(!s->budget--) { s->failed_pc=0x0c06ace6u; return 0; }
r[19]=r[5]*r[3];
goto P_0c06ace8;
P_0c06ace8: /* original 4108, guest PC 0x0c06ace8 */
if(!s->budget--) { s->failed_pc=0x0c06ace8u; return 0; }
r[1]<<=2;
goto P_0c06acea;
P_0c06acea: /* original 4100, guest PC 0x0c06acea */
if(!s->budget--) { s->failed_pc=0x0c06aceau; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c06acec;
P_0c06acec: /* original 3e18, guest PC 0x0c06acec */
if(!s->budget--) { s->failed_pc=0x0c06acecu; return 0; }
r[14]-=r[1];
goto P_0c06acee;
P_0c06acee: /* original 2f12, guest PC 0x0c06acee */
if(!s->budget--) { s->failed_pc=0x0c06aceeu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06acf0;
P_0c06acf0: /* original 051a, guest PC 0x0c06acf0 */
if(!s->budget--) { s->failed_pc=0x0c06acf0u; return 0; }
r[5]=r[19];
goto P_0c06acf2;
P_0c06acf2: /* original d23a, guest PC 0x0c06acf2 */
if(!s->budget--) { s->failed_pc=0x0c06acf2u; return 0; }
r[2]=read(ram,0x0c06addcu,4);
goto P_0c06acf4;
P_0c06acf4: /* original 6153, guest PC 0x0c06acf4 */
if(!s->budget--) { s->failed_pc=0x0c06acf4u; return 0; }
r[1]=r[5];
goto P_0c06acf6;
P_0c06acf6: /* original 420b, guest PC 0x0c06acf6 */
if(!s->budget--) { s->failed_pc=0x0c06acf6u; return 0; }
target=r[2];
r[16]=code_base|0x0c06acfau;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06acfau) { target=s->pc; goto dispatch; }
goto P_0c06acfa;
P_0c06acf8: /* original 6063, guest PC 0x0c06acf8 */
if(!s->budget--) { s->failed_pc=0x0c06acf8u; return 0; }
r[0]=r[6];
goto P_0c06acfa;
P_0c06acfa: /* original 2f06, guest PC 0x0c06acfa */
if(!s->budget--) { s->failed_pc=0x0c06acfau; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06acfc;
P_0c06acfc: /* original 6503, guest PC 0x0c06acfc */
if(!s->budget--) { s->failed_pc=0x0c06acfcu; return 0; }
r[5]=r[0];
goto P_0c06acfe;
P_0c06acfe: /* original 2f76, guest PC 0x0c06acfe */
if(!s->budget--) { s->failed_pc=0x0c06acfeu; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad00;
P_0c06ad00: /* original 2fd6, guest PC 0x0c06ad00 */
if(!s->budget--) { s->failed_pc=0x0c06ad00u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad02;
P_0c06ad02: /* original 2fe6, guest PC 0x0c06ad02 */
if(!s->budget--) { s->failed_pc=0x0c06ad02u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad04;
P_0c06ad04: /* original 2fc6, guest PC 0x0c06ad04 */
if(!s->budget--) { s->failed_pc=0x0c06ad04u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad06;
P_0c06ad06: /* original d136, guest PC 0x0c06ad06 */
if(!s->budget--) { s->failed_pc=0x0c06ad06u; return 0; }
r[1]=read(ram,0x0c06ade0u,4);
goto P_0c06ad08;
P_0c06ad08: /* original d236, guest PC 0x0c06ad08 */
if(!s->budget--) { s->failed_pc=0x0c06ad08u; return 0; }
r[2]=read(ram,0x0c06ade4u,4);
goto P_0c06ad0a;
P_0c06ad0a: /* original 420b, guest PC 0x0c06ad0a */
if(!s->budget--) { s->failed_pc=0x0c06ad0au; return 0; }
target=r[2];
r[16]=code_base|0x0c06ad0eu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ad0eu) { target=s->pc; goto dispatch; }
goto P_0c06ad0e;
P_0c06ad0c: /* original 2f16, guest PC 0x0c06ad0c */
if(!s->budget--) { s->failed_pc=0x0c06ad0cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad0e;
P_0c06ad0e: /* original 7f1c, guest PC 0x0c06ad0e */
if(!s->budget--) { s->failed_pc=0x0c06ad0eu; return 0; }
r[15]+=0x0000001cu;
goto P_0c06ad10;
P_0c06ad10: /* original 4f16, guest PC 0x0c06ad10 */
if(!s->budget--) { s->failed_pc=0x0c06ad10u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ad12;
P_0c06ad12: /* original 4f26, guest PC 0x0c06ad12 */
if(!s->budget--) { s->failed_pc=0x0c06ad12u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ad14;
P_0c06ad14: /* original 6cf6, guest PC 0x0c06ad14 */
if(!s->budget--) { s->failed_pc=0x0c06ad14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06ad16;
P_0c06ad16: /* original 6df6, guest PC 0x0c06ad16 */
if(!s->budget--) { s->failed_pc=0x0c06ad16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06ad18;
P_0c06ad18: /* original 000b, guest PC 0x0c06ad18 */
if(!s->budget--) { s->failed_pc=0x0c06ad18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06ad1a: /* original 6ef6, guest PC 0x0c06ad1a */
if(!s->budget--) { s->failed_pc=0x0c06ad1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06ad1cu,s,ram);
P_0c07b75a: /* original d140, guest PC 0x0c07b75a */
if(!s->budget--) { s->failed_pc=0x0c07b75au; return 0; }
r[1]=read(ram,0x0c07b85cu,4);
goto P_0c07b75c;
P_0c07b75c: /* original 6312, guest PC 0x0c07b75c */
if(!s->budget--) { s->failed_pc=0x0c07b75cu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c07b75e;
P_0c07b75e: /* original 3433, guest PC 0x0c07b75e */
if(!s->budget--) { s->failed_pc=0x0c07b75eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c07b760;
P_0c07b760: /* original 8907, guest PC 0x0c07b760 */
if(!s->budget--) { s->failed_pc=0x0c07b760u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b772; }
goto P_0c07b762;
P_0c07b762: /* original d23d, guest PC 0x0c07b762 */
if(!s->budget--) { s->failed_pc=0x0c07b762u; return 0; }
r[2]=read(ram,0x0c07b858u,4);
goto P_0c07b764;
P_0c07b764: /* original 6022, guest PC 0x0c07b764 */
if(!s->budget--) { s->failed_pc=0x0c07b764u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c07b766;
P_0c07b766: /* original 3503, guest PC 0x0c07b766 */
if(!s->budget--) { s->failed_pc=0x0c07b766u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[0])!=0);
goto P_0c07b768;
P_0c07b768: /* original 8903, guest PC 0x0c07b768 */
if(!s->budget--) { s->failed_pc=0x0c07b768u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b772; }
goto P_0c07b76a;
P_0c07b76a: /* original d13d, guest PC 0x0c07b76a */
if(!s->budget--) { s->failed_pc=0x0c07b76au; return 0; }
r[1]=read(ram,0x0c07b860u,4);
goto P_0c07b76c;
P_0c07b76c: /* original 2142, guest PC 0x0c07b76c */
if(!s->budget--) { s->failed_pc=0x0c07b76cu; return 0; }
write(ram,r[1],r[4],4);
goto P_0c07b76e;
P_0c07b76e: /* original d33d, guest PC 0x0c07b76e */
if(!s->budget--) { s->failed_pc=0x0c07b76eu; return 0; }
r[3]=read(ram,0x0c07b864u,4);
goto P_0c07b770;
P_0c07b770: /* original 2352, guest PC 0x0c07b770 */
if(!s->budget--) { s->failed_pc=0x0c07b770u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c07b772;
P_0c07b772: /* original 000b, guest PC 0x0c07b772 */
if(!s->budget--) { s->failed_pc=0x0c07b772u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b774: /* original 0009, guest PC 0x0c07b774 */
if(!s->budget--) { s->failed_pc=0x0c07b774u; return 0; }
return vf3_matrix_family(0x0c07b776u,s,ram);
P_0c07b784: /* original 4f22, guest PC 0x0c07b784 */
if(!s->budget--) { s->failed_pc=0x0c07b784u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b786;
P_0c07b786: /* original 905d, guest PC 0x0c07b786 */
if(!s->budget--) { s->failed_pc=0x0c07b786u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b844u,2);
goto P_0c07b788;
P_0c07b788: /* original 3f0c, guest PC 0x0c07b788 */
if(!s->budget--) { s->failed_pc=0x0c07b788u; return 0; }
r[15]+=r[0];
goto P_0c07b78a;
P_0c07b78a: /* original 905c, guest PC 0x0c07b78a */
if(!s->budget--) { s->failed_pc=0x0c07b78au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b846u,2);
goto P_0c07b78c;
P_0c07b78c: /* original 30fc, guest PC 0x0c07b78c */
if(!s->budget--) { s->failed_pc=0x0c07b78cu; return 0; }
r[0]+=r[15];
goto P_0c07b78e;
P_0c07b78e: /* original 7004, guest PC 0x0c07b78e */
if(!s->budget--) { s->failed_pc=0x0c07b78eu; return 0; }
r[0]+=0x00000004u;
goto P_0c07b790;
P_0c07b790: /* original 2508, guest PC 0x0c07b790 */
if(!s->budget--) { s->failed_pc=0x0c07b790u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c07b792;
P_0c07b792: /* original 8903, guest PC 0x0c07b792 */
if(!s->budget--) { s->failed_pc=0x0c07b792u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b79c; }
goto P_0c07b794;
P_0c07b794: /* original 9557, guest PC 0x0c07b794 */
if(!s->budget--) { s->failed_pc=0x0c07b794u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b846u,2);
goto P_0c07b796;
P_0c07b796: /* original 35fc, guest PC 0x0c07b796 */
if(!s->budget--) { s->failed_pc=0x0c07b796u; return 0; }
r[5]+=r[15];
goto P_0c07b798;
P_0c07b798: /* original a003, guest PC 0x0c07b798 */
if(!s->budget--) { s->failed_pc=0x0c07b798u; return 0; }
r[5]+=0x00000008u;
goto P_0c07b7a2;
P_0c07b79a: /* original 7508, guest PC 0x0c07b79a */
if(!s->budget--) { s->failed_pc=0x0c07b79au; return 0; }
r[5]+=0x00000008u;
goto P_0c07b79c;
P_0c07b79c: /* original 9553, guest PC 0x0c07b79c */
if(!s->budget--) { s->failed_pc=0x0c07b79cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b846u,2);
goto P_0c07b79e;
P_0c07b79e: /* original 35fc, guest PC 0x0c07b79e */
if(!s->budget--) { s->failed_pc=0x0c07b79eu; return 0; }
r[5]+=r[15];
goto P_0c07b7a0;
P_0c07b7a0: /* original 7504, guest PC 0x0c07b7a0 */
if(!s->budget--) { s->failed_pc=0x0c07b7a0u; return 0; }
r[5]+=0x00000004u;
goto P_0c07b7a2;
P_0c07b7a2: /* original 9050, guest PC 0x0c07b7a2 */
if(!s->budget--) { s->failed_pc=0x0c07b7a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b846u,2);
goto P_0c07b7a4;
P_0c07b7a4: /* original 6653, guest PC 0x0c07b7a4 */
if(!s->budget--) { s->failed_pc=0x0c07b7a4u; return 0; }
r[6]=r[5];
goto P_0c07b7a6;
P_0c07b7a6: /* original d330, guest PC 0x0c07b7a6 */
if(!s->budget--) { s->failed_pc=0x0c07b7a6u; return 0; }
r[3]=read(ram,0x0c07b868u,4);
goto P_0c07b7a8;
P_0c07b7a8: /* original 05fe, guest PC 0x0c07b7a8 */
if(!s->budget--) { s->failed_pc=0x0c07b7a8u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c07b7aa;
P_0c07b7aa: /* original 430b, guest PC 0x0c07b7aa */
if(!s->budget--) { s->failed_pc=0x0c07b7aau; return 0; }
target=r[3];
r[16]=code_base|0x0c07b7aeu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b7aeu) { target=s->pc; goto dispatch; }
goto P_0c07b7ae;
P_0c07b7ac: /* original 64f3, guest PC 0x0c07b7ac */
if(!s->budget--) { s->failed_pc=0x0c07b7acu; return 0; }
r[4]=r[15];
goto P_0c07b7ae;
P_0c07b7ae: /* original d92b, guest PC 0x0c07b7ae */
if(!s->budget--) { s->failed_pc=0x0c07b7aeu; return 0; }
r[9]=read(ram,0x0c07b85cu,4);
goto P_0c07b7b0;
P_0c07b7b0: /* original da2b, guest PC 0x0c07b7b0 */
if(!s->budget--) { s->failed_pc=0x0c07b7b0u; return 0; }
r[10]=read(ram,0x0c07b860u,4);
goto P_0c07b7b2;
P_0c07b7b2: /* original 6392, guest PC 0x0c07b7b2 */
if(!s->budget--) { s->failed_pc=0x0c07b7b2u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c07b7b4;
P_0c07b7b4: /* original 64a2, guest PC 0x0c07b7b4 */
if(!s->budget--) { s->failed_pc=0x0c07b7b4u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c07b7b6;
P_0c07b7b6: /* original d22b, guest PC 0x0c07b7b6 */
if(!s->budget--) { s->failed_pc=0x0c07b7b6u; return 0; }
r[2]=read(ram,0x0c07b864u,4);
goto P_0c07b7b8;
P_0c07b7b8: /* original 3433, guest PC 0x0c07b7b8 */
if(!s->budget--) { s->failed_pc=0x0c07b7b8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c07b7ba;
P_0c07b7ba: /* original 8d37, guest PC 0x0c07b7ba */
if(!s->budget--) { s->failed_pc=0x0c07b7bau; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(cond) { goto P_0c07b82c; }
goto P_0c07b7be;
P_0c07b7bc: /* original 6522, guest PC 0x0c07b7bc */
if(!s->budget--) { s->failed_pc=0x0c07b7bcu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c07b7be;
P_0c07b7be: /* original dc26, guest PC 0x0c07b7be */
if(!s->budget--) { s->failed_pc=0x0c07b7beu; return 0; }
r[12]=read(ram,0x0c07b858u,4);
goto P_0c07b7c0;
P_0c07b7c0: /* original 63c2, guest PC 0x0c07b7c0 */
if(!s->budget--) { s->failed_pc=0x0c07b7c0u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c07b7c2;
P_0c07b7c2: /* original 3533, guest PC 0x0c07b7c2 */
if(!s->budget--) { s->failed_pc=0x0c07b7c2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c07b7c4;
P_0c07b7c4: /* original 8932, guest PC 0x0c07b7c4 */
if(!s->budget--) { s->failed_pc=0x0c07b7c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b82c; }
goto P_0c07b7c6;
P_0c07b7c6: /* original 6653, guest PC 0x0c07b7c6 */
if(!s->budget--) { s->failed_pc=0x0c07b7c6u; return 0; }
r[6]=r[5];
goto P_0c07b7c8;
P_0c07b7c8: /* original 4608, guest PC 0x0c07b7c8 */
if(!s->budget--) { s->failed_pc=0x0c07b7c8u; return 0; }
r[6]<<=2;
goto P_0c07b7ca;
P_0c07b7ca: /* original 4608, guest PC 0x0c07b7ca */
if(!s->budget--) { s->failed_pc=0x0c07b7cau; return 0; }
r[6]<<=2;
goto P_0c07b7cc;
P_0c07b7cc: /* original 6353, guest PC 0x0c07b7cc */
if(!s->budget--) { s->failed_pc=0x0c07b7ccu; return 0; }
r[3]=r[5];
goto P_0c07b7ce;
P_0c07b7ce: /* original 4608, guest PC 0x0c07b7ce */
if(!s->budget--) { s->failed_pc=0x0c07b7ceu; return 0; }
r[6]<<=2;
goto P_0c07b7d0;
P_0c07b7d0: /* original db26, guest PC 0x0c07b7d0 */
if(!s->budget--) { s->failed_pc=0x0c07b7d0u; return 0; }
r[11]=read(ram,0x0c07b86cu,4);
goto P_0c07b7d2;
P_0c07b7d2: /* original 363c, guest PC 0x0c07b7d2 */
if(!s->budget--) { s->failed_pc=0x0c07b7d2u; return 0; }
r[6]+=r[3];
goto P_0c07b7d4;
P_0c07b7d4: /* original 6df3, guest PC 0x0c07b7d4 */
if(!s->budget--) { s->failed_pc=0x0c07b7d4u; return 0; }
r[13]=r[15];
goto P_0c07b7d6;
P_0c07b7d6: /* original 4600, guest PC 0x0c07b7d6 */
if(!s->budget--) { s->failed_pc=0x0c07b7d6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07b7d8;
P_0c07b7d8: /* original 666f, guest PC 0x0c07b7d8 */
if(!s->budget--) { s->failed_pc=0x0c07b7d8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07b7da;
P_0c07b7da: /* original 36bc, guest PC 0x0c07b7da */
if(!s->budget--) { s->failed_pc=0x0c07b7dau; return 0; }
r[6]+=r[11];
goto P_0c07b7dc;
P_0c07b7dc: /* original 6763, guest PC 0x0c07b7dc */
if(!s->budget--) { s->failed_pc=0x0c07b7dcu; return 0; }
r[7]=r[6];
goto P_0c07b7de;
P_0c07b7de: /* original 7701, guest PC 0x0c07b7de */
if(!s->budget--) { s->failed_pc=0x0c07b7deu; return 0; }
r[7]+=0x00000001u;
goto P_0c07b7e0;
P_0c07b7e0: /* original ee01, guest PC 0x0c07b7e0 */
if(!s->budget--) { s->failed_pc=0x0c07b7e0u; return 0; }
r[14]=0x00000001u;
goto P_0c07b7e2;
P_0c07b7e2: /* original 374c, guest PC 0x0c07b7e2 */
if(!s->budget--) { s->failed_pc=0x0c07b7e2u; return 0; }
r[7]+=r[4];
goto P_0c07b7e4;
P_0c07b7e4: /* original a01c, guest PC 0x0c07b7e4 */
if(!s->budget--) { s->failed_pc=0x0c07b7e4u; return 0; }
write(ram,r[6],r[14],1);
goto P_0c07b820;
P_0c07b7e6: /* original 26e0, guest PC 0x0c07b7e6 */
if(!s->budget--) { s->failed_pc=0x0c07b7e6u; return 0; }
write(ram,r[6],r[14],1);
goto P_0c07b7e8;
P_0c07b7e8: /* original 606e, guest PC 0x0c07b7e8 */
if(!s->budget--) { s->failed_pc=0x0c07b7e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c07b7ea;
P_0c07b7ea: /* original 880a, guest PC 0x0c07b7ea */
if(!s->budget--) { s->failed_pc=0x0c07b7eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c07b7ec;
P_0c07b7ec: /* original 8b0f, guest PC 0x0c07b7ec */
if(!s->budget--) { s->failed_pc=0x0c07b7ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b80e; }
goto P_0c07b7ee;
P_0c07b7ee: /* original 7501, guest PC 0x0c07b7ee */
if(!s->budget--) { s->failed_pc=0x0c07b7eeu; return 0; }
r[5]+=0x00000001u;
goto P_0c07b7f0;
P_0c07b7f0: /* original 64a2, guest PC 0x0c07b7f0 */
if(!s->budget--) { s->failed_pc=0x0c07b7f0u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c07b7f2;
P_0c07b7f2: /* original 6653, guest PC 0x0c07b7f2 */
if(!s->budget--) { s->failed_pc=0x0c07b7f2u; return 0; }
r[6]=r[5];
goto P_0c07b7f4;
P_0c07b7f4: /* original 4608, guest PC 0x0c07b7f4 */
if(!s->budget--) { s->failed_pc=0x0c07b7f4u; return 0; }
r[6]<<=2;
goto P_0c07b7f6;
P_0c07b7f6: /* original 4608, guest PC 0x0c07b7f6 */
if(!s->budget--) { s->failed_pc=0x0c07b7f6u; return 0; }
r[6]<<=2;
goto P_0c07b7f8;
P_0c07b7f8: /* original 6353, guest PC 0x0c07b7f8 */
if(!s->budget--) { s->failed_pc=0x0c07b7f8u; return 0; }
r[3]=r[5];
goto P_0c07b7fa;
P_0c07b7fa: /* original 4608, guest PC 0x0c07b7fa */
if(!s->budget--) { s->failed_pc=0x0c07b7fau; return 0; }
r[6]<<=2;
goto P_0c07b7fc;
P_0c07b7fc: /* original 363c, guest PC 0x0c07b7fc */
if(!s->budget--) { s->failed_pc=0x0c07b7fcu; return 0; }
r[6]+=r[3];
goto P_0c07b7fe;
P_0c07b7fe: /* original 4600, guest PC 0x0c07b7fe */
if(!s->budget--) { s->failed_pc=0x0c07b7feu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07b800;
P_0c07b800: /* original 666f, guest PC 0x0c07b800 */
if(!s->budget--) { s->failed_pc=0x0c07b800u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07b802;
P_0c07b802: /* original 36bc, guest PC 0x0c07b802 */
if(!s->budget--) { s->failed_pc=0x0c07b802u; return 0; }
r[6]+=r[11];
goto P_0c07b804;
P_0c07b804: /* original 6763, guest PC 0x0c07b804 */
if(!s->budget--) { s->failed_pc=0x0c07b804u; return 0; }
r[7]=r[6];
goto P_0c07b806;
P_0c07b806: /* original 7701, guest PC 0x0c07b806 */
if(!s->budget--) { s->failed_pc=0x0c07b806u; return 0; }
r[7]+=0x00000001u;
goto P_0c07b808;
P_0c07b808: /* original 374c, guest PC 0x0c07b808 */
if(!s->budget--) { s->failed_pc=0x0c07b808u; return 0; }
r[7]+=r[4];
goto P_0c07b80a;
P_0c07b80a: /* original a003, guest PC 0x0c07b80a */
if(!s->budget--) { s->failed_pc=0x0c07b80au; return 0; }
write(ram,r[6],r[14],1);
goto P_0c07b814;
P_0c07b80c: /* original 26e0, guest PC 0x0c07b80c */
if(!s->budget--) { s->failed_pc=0x0c07b80cu; return 0; }
write(ram,r[6],r[14],1);
goto P_0c07b80e;
P_0c07b80e: /* original 2760, guest PC 0x0c07b80e */
if(!s->budget--) { s->failed_pc=0x0c07b80eu; return 0; }
write(ram,r[7],r[6],1);
goto P_0c07b810;
P_0c07b810: /* original 7401, guest PC 0x0c07b810 */
if(!s->budget--) { s->failed_pc=0x0c07b810u; return 0; }
r[4]+=0x00000001u;
goto P_0c07b812;
P_0c07b812: /* original 7701, guest PC 0x0c07b812 */
if(!s->budget--) { s->failed_pc=0x0c07b812u; return 0; }
r[7]+=0x00000001u;
goto P_0c07b814;
P_0c07b814: /* original 6292, guest PC 0x0c07b814 */
if(!s->budget--) { s->failed_pc=0x0c07b814u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c07b816;
P_0c07b816: /* original 3423, guest PC 0x0c07b816 */
if(!s->budget--) { s->failed_pc=0x0c07b816u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c07b818;
P_0c07b818: /* original 8906, guest PC 0x0c07b818 */
if(!s->budget--) { s->failed_pc=0x0c07b818u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b828; }
goto P_0c07b81a;
P_0c07b81a: /* original 63c2, guest PC 0x0c07b81a */
if(!s->budget--) { s->failed_pc=0x0c07b81au; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c07b81c;
P_0c07b81c: /* original 3533, guest PC 0x0c07b81c */
if(!s->budget--) { s->failed_pc=0x0c07b81cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c07b81e;
P_0c07b81e: /* original 8903, guest PC 0x0c07b81e */
if(!s->budget--) { s->failed_pc=0x0c07b81eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b828; }
goto P_0c07b820;
P_0c07b820: /* original 66d4, guest PC 0x0c07b820 */
if(!s->budget--) { s->failed_pc=0x0c07b820u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[6]=tmp;
goto P_0c07b822;
P_0c07b822: /* original 636e, guest PC 0x0c07b822 */
if(!s->budget--) { s->failed_pc=0x0c07b822u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c07b824;
P_0c07b824: /* original 2338, guest PC 0x0c07b824 */
if(!s->budget--) { s->failed_pc=0x0c07b824u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07b826;
P_0c07b826: /* original 8bdf, guest PC 0x0c07b826 */
if(!s->budget--) { s->failed_pc=0x0c07b826u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b7e8; }
goto P_0c07b828;
P_0c07b828: /* original bf97, guest PC 0x0c07b828 */
if(!s->budget--) { s->failed_pc=0x0c07b828u; return 0; }
target=0x0c07b75au; r[16]=code_base|0x0c07b82cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b82cu) { target=s->pc; goto dispatch; }
goto P_0c07b82c;
P_0c07b82a: /* original 0009, guest PC 0x0c07b82a */
if(!s->budget--) { s->failed_pc=0x0c07b82au; return 0; }
goto P_0c07b82c;
P_0c07b82c: /* original 910c, guest PC 0x0c07b82c */
if(!s->budget--) { s->failed_pc=0x0c07b82cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b848u,2);
goto P_0c07b82e;
P_0c07b82e: /* original 3f1c, guest PC 0x0c07b82e */
if(!s->budget--) { s->failed_pc=0x0c07b82eu; return 0; }
r[15]+=r[1];
goto P_0c07b830;
P_0c07b830: /* original 4f26, guest PC 0x0c07b830 */
if(!s->budget--) { s->failed_pc=0x0c07b830u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b832;
P_0c07b832: /* original 69f6, guest PC 0x0c07b832 */
if(!s->budget--) { s->failed_pc=0x0c07b832u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07b834;
P_0c07b834: /* original 6af6, guest PC 0x0c07b834 */
if(!s->budget--) { s->failed_pc=0x0c07b834u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07b836;
P_0c07b836: /* original 6bf6, guest PC 0x0c07b836 */
if(!s->budget--) { s->failed_pc=0x0c07b836u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b838;
P_0c07b838: /* original 6cf6, guest PC 0x0c07b838 */
if(!s->budget--) { s->failed_pc=0x0c07b838u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b83a;
P_0c07b83a: /* original 6df6, guest PC 0x0c07b83a */
if(!s->budget--) { s->failed_pc=0x0c07b83au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b83c;
P_0c07b83c: /* original 000b, guest PC 0x0c07b83c */
if(!s->budget--) { s->failed_pc=0x0c07b83cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b83e: /* original 6ef6, guest PC 0x0c07b83e */
if(!s->budget--) { s->failed_pc=0x0c07b83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07b840u,s,ram);
P_0c082e0e: /* original 4f22, guest PC 0x0c082e0e */
if(!s->budget--) { s->failed_pc=0x0c082e0eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c082e10;
P_0c082e10: /* original 7fec, guest PC 0x0c082e10 */
if(!s->budget--) { s->failed_pc=0x0c082e10u; return 0; }
r[15]+=0xffffffecu;
goto P_0c082e12;
P_0c082e12: /* original 1f43, guest PC 0x0c082e12 */
if(!s->budget--) { s->failed_pc=0x0c082e12u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c082e14;
P_0c082e14: /* original 1f54, guest PC 0x0c082e14 */
if(!s->budget--) { s->failed_pc=0x0c082e14u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c082e16;
P_0c082e16: /* original d32d, guest PC 0x0c082e16 */
if(!s->budget--) { s->failed_pc=0x0c082e16u; return 0; }
r[3]=read(ram,0x0c082eccu,4);
goto P_0c082e18;
P_0c082e18: /* original dc2b, guest PC 0x0c082e18 */
if(!s->budget--) { s->failed_pc=0x0c082e18u; return 0; }
r[12]=read(ram,0x0c082ec8u,4);
goto P_0c082e1a;
P_0c082e1a: /* original dd2a, guest PC 0x0c082e1a */
if(!s->budget--) { s->failed_pc=0x0c082e1au; return 0; }
r[13]=read(ram,0x0c082ec4u,4);
goto P_0c082e1c;
P_0c082e1c: /* original 1f32, guest PC 0x0c082e1c */
if(!s->budget--) { s->failed_pc=0x0c082e1cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c082e1e;
P_0c082e1e: /* original de2c, guest PC 0x0c082e1e */
if(!s->budget--) { s->failed_pc=0x0c082e1eu; return 0; }
r[14]=read(ram,0x0c082ed0u,4);
goto P_0c082e20;
P_0c082e20: /* original 1fe1, guest PC 0x0c082e20 */
if(!s->budget--) { s->failed_pc=0x0c082e20u; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c082e22;
P_0c082e22: /* original d32c, guest PC 0x0c082e22 */
if(!s->budget--) { s->failed_pc=0x0c082e22u; return 0; }
r[3]=read(ram,0x0c082ed4u,4);
goto P_0c082e24;
P_0c082e24: /* original 430b, guest PC 0x0c082e24 */
if(!s->budget--) { s->failed_pc=0x0c082e24u; return 0; }
target=r[3];
r[16]=code_base|0x0c082e28u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c082e28u) { target=s->pc; goto dispatch; }
goto P_0c082e28;
P_0c082e26: /* original 64e3, guest PC 0x0c082e26 */
if(!s->budget--) { s->failed_pc=0x0c082e26u; return 0; }
r[4]=r[14];
goto P_0c082e28;
P_0c082e28: /* original d215, guest PC 0x0c082e28 */
if(!s->budget--) { s->failed_pc=0x0c082e28u; return 0; }
r[2]=read(ram,0x0c082e80u,4);
goto P_0c082e2a;
P_0c082e2a: /* original e503, guest PC 0x0c082e2a */
if(!s->budget--) { s->failed_pc=0x0c082e2au; return 0; }
r[5]=0x00000003u;
goto P_0c082e2c;
P_0c082e2c: /* original 9622, guest PC 0x0c082e2c */
if(!s->budget--) { s->failed_pc=0x0c082e2cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e74u,2);
goto P_0c082e2e;
P_0c082e2e: /* original 420b, guest PC 0x0c082e2e */
if(!s->budget--) { s->failed_pc=0x0c082e2eu; return 0; }
target=r[2];
r[16]=code_base|0x0c082e32u;
r[4]=0x0000001au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c082e32u) { target=s->pc; goto dispatch; }
goto P_0c082e32;
P_0c082e30: /* original e41a, guest PC 0x0c082e30 */
if(!s->budget--) { s->failed_pc=0x0c082e30u; return 0; }
r[4]=0x0000001au;
goto P_0c082e32;
P_0c082e32: /* original d329, guest PC 0x0c082e32 */
if(!s->budget--) { s->failed_pc=0x0c082e32u; return 0; }
r[3]=read(ram,0x0c082ed8u,4);
goto P_0c082e34;
P_0c082e34: /* original 951f, guest PC 0x0c082e34 */
if(!s->budget--) { s->failed_pc=0x0c082e34u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e76u,2);
goto P_0c082e36;
P_0c082e36: /* original 430b, guest PC 0x0c082e36 */
if(!s->budget--) { s->failed_pc=0x0c082e36u; return 0; }
target=r[3];
r[16]=code_base|0x0c082e3au;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c082e3au) { target=s->pc; goto dispatch; }
goto P_0c082e3a;
P_0c082e38: /* original 54f1, guest PC 0x0c082e38 */
if(!s->budget--) { s->failed_pc=0x0c082e38u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c082e3a;
P_0c082e3a: /* original d928, guest PC 0x0c082e3a */
if(!s->budget--) { s->failed_pc=0x0c082e3au; return 0; }
r[9]=read(ram,0x0c082edcu,4);
goto P_0c082e3c;
P_0c082e3c: /* original ee00, guest PC 0x0c082e3c */
if(!s->budget--) { s->failed_pc=0x0c082e3cu; return 0; }
r[14]=0x00000000u;
goto P_0c082e3e;
P_0c082e3e: /* original db28, guest PC 0x0c082e3e */
if(!s->budget--) { s->failed_pc=0x0c082e3eu; return 0; }
r[11]=read(ram,0x0c082ee0u,4);
goto P_0c082e40;
P_0c082e40: /* original ea08, guest PC 0x0c082e40 */
if(!s->budget--) { s->failed_pc=0x0c082e40u; return 0; }
r[10]=0x00000008u;
goto P_0c082e42;
P_0c082e42: /* original 9819, guest PC 0x0c082e42 */
if(!s->budget--) { s->failed_pc=0x0c082e42u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e78u,2);
goto P_0c082e44;
P_0c082e44: /* original 9019, guest PC 0x0c082e44 */
if(!s->budget--) { s->failed_pc=0x0c082e44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e7au,2);
goto P_0c082e46;
P_0c082e46: /* original 02de, guest PC 0x0c082e46 */
if(!s->budget--) { s->failed_pc=0x0c082e46u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c082e48;
P_0c082e48: /* original 3e20, guest PC 0x0c082e48 */
if(!s->budget--) { s->failed_pc=0x0c082e48u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c082e4a;
P_0c082e4a: /* original 8b4b, guest PC 0x0c082e4a */
if(!s->budget--) { s->failed_pc=0x0c082e4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082ee4; }
goto P_0c082e4c;
P_0c082e4c: /* original 61f2, guest PC 0x0c082e4c */
if(!s->budget--) { s->failed_pc=0x0c082e4cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c082e4e;
P_0c082e4e: /* original e307, guest PC 0x0c082e4e */
if(!s->budget--) { s->failed_pc=0x0c082e4eu; return 0; }
r[3]=0x00000007u;
goto P_0c082e50;
P_0c082e50: /* original 413c, guest PC 0x0c082e50 */
if(!s->budget--) { s->failed_pc=0x0c082e50u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c082e52;
P_0c082e52: /* original 21ab, guest PC 0x0c082e52 */
if(!s->budget--) { s->failed_pc=0x0c082e52u; return 0; }
r[1]|=r[10];
goto P_0c082e54;
P_0c082e54: /* original 1f14, guest PC 0x0c082e54 */
if(!s->budget--) { s->failed_pc=0x0c082e54u; return 0; }
write(ram,r[15]+16,r[1],4);
goto P_0c082e56;
P_0c082e56: /* original 62f2, guest PC 0x0c082e56 */
if(!s->budget--) { s->failed_pc=0x0c082e56u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c082e58;
P_0c082e58: /* original 7203, guest PC 0x0c082e58 */
if(!s->budget--) { s->failed_pc=0x0c082e58u; return 0; }
r[2]+=0x00000003u;
goto P_0c082e5a;
P_0c082e5a: /* original 2f22, guest PC 0x0c082e5a */
if(!s->budget--) { s->failed_pc=0x0c082e5au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c082e5c;
P_0c082e5c: /* original 950e, guest PC 0x0c082e5c */
if(!s->budget--) { s->failed_pc=0x0c082e5cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e7cu,2);
goto P_0c082e5e;
P_0c082e5e: /* original d31e, guest PC 0x0c082e5e */
if(!s->budget--) { s->failed_pc=0x0c082e5eu; return 0; }
r[3]=read(ram,0x0c082ed8u,4);
goto P_0c082e60;
P_0c082e60: /* original 430b, guest PC 0x0c082e60 */
if(!s->budget--) { s->failed_pc=0x0c082e60u; return 0; }
target=r[3];
r[16]=code_base|0x0c082e64u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c082e64u) { target=s->pc; goto dispatch; }
goto P_0c082e64;
P_0c082e62: /* original 54f1, guest PC 0x0c082e62 */
if(!s->budget--) { s->failed_pc=0x0c082e62u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c082e64;
P_0c082e64: /* original a047, guest PC 0x0c082e64 */
if(!s->budget--) { s->failed_pc=0x0c082e64u; return 0; }
goto P_0c082ef6;
P_0c082e66: /* original 0009, guest PC 0x0c082e66 */
if(!s->budget--) { s->failed_pc=0x0c082e66u; return 0; }
return vf3_matrix_family(0x0c082e68u,s,ram);
P_0c082ee4: /* original 63f2, guest PC 0x0c082ee4 */
if(!s->budget--) { s->failed_pc=0x0c082ee4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c082ee6;
P_0c082ee6: /* original e207, guest PC 0x0c082ee6 */
if(!s->budget--) { s->failed_pc=0x0c082ee6u; return 0; }
r[2]=0x00000007u;
goto P_0c082ee8;
P_0c082ee8: /* original 7301, guest PC 0x0c082ee8 */
if(!s->budget--) { s->failed_pc=0x0c082ee8u; return 0; }
r[3]+=0x00000001u;
goto P_0c082eea;
P_0c082eea: /* original 432c, guest PC 0x0c082eea */
if(!s->budget--) { s->failed_pc=0x0c082eeau; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c082eec;
P_0c082eec: /* original 23ab, guest PC 0x0c082eec */
if(!s->budget--) { s->failed_pc=0x0c082eecu; return 0; }
r[3]|=r[10];
goto P_0c082eee;
P_0c082eee: /* original 1f34, guest PC 0x0c082eee */
if(!s->budget--) { s->failed_pc=0x0c082eeeu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c082ef0;
P_0c082ef0: /* original 61f2, guest PC 0x0c082ef0 */
if(!s->budget--) { s->failed_pc=0x0c082ef0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c082ef2;
P_0c082ef2: /* original 7103, guest PC 0x0c082ef2 */
if(!s->budget--) { s->failed_pc=0x0c082ef2u; return 0; }
r[1]+=0x00000003u;
goto P_0c082ef4;
P_0c082ef4: /* original 2f12, guest PC 0x0c082ef4 */
if(!s->budget--) { s->failed_pc=0x0c082ef4u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c082ef6;
P_0c082ef6: /* original 60e3, guest PC 0x0c082ef6 */
if(!s->budget--) { s->failed_pc=0x0c082ef6u; return 0; }
r[0]=r[14];
goto P_0c082ef8;
P_0c082ef8: /* original e10c, guest PC 0x0c082ef8 */
if(!s->budget--) { s->failed_pc=0x0c082ef8u; return 0; }
r[1]=0x0000000cu;
goto P_0c082efa;
P_0c082efa: /* original 3012, guest PC 0x0c082efa */
if(!s->budget--) { s->failed_pc=0x0c082efau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c082efc;
P_0c082efc: /* original 8b01, guest PC 0x0c082efc */
if(!s->budget--) { s->failed_pc=0x0c082efcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082f02; }
goto P_0c082efe;
P_0c082efe: /* original a159, guest PC 0x0c082efe */
if(!s->budget--) { s->failed_pc=0x0c082efeu; return 0; }
goto P_0c0831b4;
P_0c082f00: /* original 0009, guest PC 0x0c082f00 */
if(!s->budget--) { s->failed_pc=0x0c082f00u; return 0; }
goto P_0c082f02;
P_0c082f02: /* original 4000, guest PC 0x0c082f02 */
if(!s->budget--) { s->failed_pc=0x0c082f02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c082f04;
P_0c082f04: /* original 6103, guest PC 0x0c082f04 */
if(!s->budget--) { s->failed_pc=0x0c082f04u; return 0; }
r[1]=r[0];
goto P_0c082f06;
P_0c082f06: /* original c702, guest PC 0x0c082f06 */
if(!s->budget--) { s->failed_pc=0x0c082f06u; return 0; }
r[0]=0x0c082f10u;
goto P_0c082f08;
P_0c082f08: /* original 001d, guest PC 0x0c082f08 */
if(!s->budget--) { s->failed_pc=0x0c082f08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c082f0a;
P_0c082f0a: /* original 0023, guest PC 0x0c082f0a */
if(!s->budget--) { s->failed_pc=0x0c082f0au; return 0; }
target=r[0]+0x0c082f0eu;
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
P_0c082f0c: /* original 0009, guest PC 0x0c082f0c */
if(!s->budget--) { s->failed_pc=0x0c082f0cu; return 0; }
return vf3_matrix_family(0x0c082f0eu,s,ram);
P_0c0831b4: /* original 9048, guest PC 0x0c0831b4 */
if(!s->budget--) { s->failed_pc=0x0c0831b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083248u,2);
goto P_0c0831b6;
P_0c0831b6: /* original 02de, guest PC 0x0c0831b6 */
if(!s->budget--) { s->failed_pc=0x0c0831b6u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0831b8;
P_0c0831b8: /* original 3e20, guest PC 0x0c0831b8 */
if(!s->budget--) { s->failed_pc=0x0c0831b8u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c0831ba;
P_0c0831ba: /* original 8b03, guest PC 0x0c0831ba */
if(!s->budget--) { s->failed_pc=0x0c0831bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0831c4; }
goto P_0c0831bc;
P_0c0831bc: /* original d328, guest PC 0x0c0831bc */
if(!s->budget--) { s->failed_pc=0x0c0831bcu; return 0; }
r[3]=read(ram,0x0c083260u,4);
goto P_0c0831be;
P_0c0831be: /* original 9548, guest PC 0x0c0831be */
if(!s->budget--) { s->failed_pc=0x0c0831beu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083252u,2);
goto P_0c0831c0;
P_0c0831c0: /* original 430b, guest PC 0x0c0831c0 */
if(!s->budget--) { s->failed_pc=0x0c0831c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0831c4u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0831c4u) { target=s->pc; goto dispatch; }
goto P_0c0831c4;
P_0c0831c2: /* original 54f1, guest PC 0x0c0831c2 */
if(!s->budget--) { s->failed_pc=0x0c0831c2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0831c4;
P_0c0831c4: /* original e20c, guest PC 0x0c0831c4 */
if(!s->budget--) { s->failed_pc=0x0c0831c4u; return 0; }
r[2]=0x0000000cu;
goto P_0c0831c6;
P_0c0831c6: /* original 7e01, guest PC 0x0c0831c6 */
if(!s->budget--) { s->failed_pc=0x0c0831c6u; return 0; }
r[14]+=0x00000001u;
goto P_0c0831c8;
P_0c0831c8: /* original 3e23, guest PC 0x0c0831c8 */
if(!s->budget--) { s->failed_pc=0x0c0831c8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c0831ca;
P_0c0831ca: /* original 8901, guest PC 0x0c0831ca */
if(!s->budget--) { s->failed_pc=0x0c0831cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0831d0; }
goto P_0c0831cc;
P_0c0831cc: /* original ae3a, guest PC 0x0c0831cc */
if(!s->budget--) { s->failed_pc=0x0c0831ccu; return 0; }
goto P_0c082e44;
P_0c0831ce: /* original 0009, guest PC 0x0c0831ce */
if(!s->budget--) { s->failed_pc=0x0c0831ceu; return 0; }
goto P_0c0831d0;
P_0c0831d0: /* original 54f3, guest PC 0x0c0831d0 */
if(!s->budget--) { s->failed_pc=0x0c0831d0u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0831d2;
P_0c0831d2: /* original 55f4, guest PC 0x0c0831d2 */
if(!s->budget--) { s->failed_pc=0x0c0831d2u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c0831d4;
P_0c0831d4: /* original 7f14, guest PC 0x0c0831d4 */
if(!s->budget--) { s->failed_pc=0x0c0831d4u; return 0; }
r[15]+=0x00000014u;
goto P_0c0831d6;
P_0c0831d6: /* original 4f26, guest PC 0x0c0831d6 */
if(!s->budget--) { s->failed_pc=0x0c0831d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0831d8;
P_0c0831d8: /* original d322, guest PC 0x0c0831d8 */
if(!s->budget--) { s->failed_pc=0x0c0831d8u; return 0; }
r[3]=read(ram,0x0c083264u,4);
goto P_0c0831da;
P_0c0831da: /* original 68f6, guest PC 0x0c0831da */
if(!s->budget--) { s->failed_pc=0x0c0831dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0831dc;
P_0c0831dc: /* original 69f6, guest PC 0x0c0831dc */
if(!s->budget--) { s->failed_pc=0x0c0831dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0831de;
P_0c0831de: /* original 6af6, guest PC 0x0c0831de */
if(!s->budget--) { s->failed_pc=0x0c0831deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0831e0;
P_0c0831e0: /* original 6bf6, guest PC 0x0c0831e0 */
if(!s->budget--) { s->failed_pc=0x0c0831e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0831e2;
P_0c0831e2: /* original 6cf6, guest PC 0x0c0831e2 */
if(!s->budget--) { s->failed_pc=0x0c0831e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0831e4;
P_0c0831e4: /* original 6df6, guest PC 0x0c0831e4 */
if(!s->budget--) { s->failed_pc=0x0c0831e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0831e6;
P_0c0831e6: /* original 432b, guest PC 0x0c0831e6 */
if(!s->budget--) { s->failed_pc=0x0c0831e6u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0831e8: /* original 6ef6, guest PC 0x0c0831e8 */
if(!s->budget--) { s->failed_pc=0x0c0831e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0831eau,s,ram);
P_0c086b20: /* original 2fe6, guest PC 0x0c086b20 */
if(!s->budget--) { s->failed_pc=0x0c086b20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b22;
P_0c086b22: /* original 2fd6, guest PC 0x0c086b22 */
if(!s->budget--) { s->failed_pc=0x0c086b22u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b24;
P_0c086b24: /* original 6d43, guest PC 0x0c086b24 */
if(!s->budget--) { s->failed_pc=0x0c086b24u; return 0; }
r[13]=r[4];
goto P_0c086b26;
P_0c086b26: /* original 2fc6, guest PC 0x0c086b26 */
if(!s->budget--) { s->failed_pc=0x0c086b26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b28;
P_0c086b28: /* original 2fb6, guest PC 0x0c086b28 */
if(!s->budget--) { s->failed_pc=0x0c086b28u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b2a;
P_0c086b2a: /* original 2fa6, guest PC 0x0c086b2a */
if(!s->budget--) { s->failed_pc=0x0c086b2au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b2c;
P_0c086b2c: /* original 2f96, guest PC 0x0c086b2c */
if(!s->budget--) { s->failed_pc=0x0c086b2cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b2e;
P_0c086b2e: /* original 2f86, guest PC 0x0c086b2e */
if(!s->budget--) { s->failed_pc=0x0c086b2eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b30;
P_0c086b30: /* original fffb, guest PC 0x0c086b30 */
if(!s->budget--) { s->failed_pc=0x0c086b30u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c086b32;
P_0c086b32: /* original ffeb, guest PC 0x0c086b32 */
if(!s->budget--) { s->failed_pc=0x0c086b32u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c086b34;
P_0c086b34: /* original ffdb, guest PC 0x0c086b34 */
if(!s->budget--) { s->failed_pc=0x0c086b34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c086b36;
P_0c086b36: /* original ffcb, guest PC 0x0c086b36 */
if(!s->budget--) { s->failed_pc=0x0c086b36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c086b38;
P_0c086b38: /* original d412, guest PC 0x0c086b38 */
if(!s->budget--) { s->failed_pc=0x0c086b38u; return 0; }
r[4]=read(ram,0x0c086b84u,4);
goto P_0c086b3a;
P_0c086b3a: /* original 4f22, guest PC 0x0c086b3a */
if(!s->budget--) { s->failed_pc=0x0c086b3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086b3c;
P_0c086b3c: /* original 6242, guest PC 0x0c086b3c */
if(!s->budget--) { s->failed_pc=0x0c086b3cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c086b3e;
P_0c086b3e: /* original d312, guest PC 0x0c086b3e */
if(!s->budget--) { s->failed_pc=0x0c086b3eu; return 0; }
r[3]=read(ram,0x0c086b88u,4);
goto P_0c086b40;
P_0c086b40: /* original 7ff8, guest PC 0x0c086b40 */
if(!s->budget--) { s->failed_pc=0x0c086b40u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c086b42;
P_0c086b42: /* original 2238, guest PC 0x0c086b42 */
if(!s->budget--) { s->failed_pc=0x0c086b42u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c086b44;
P_0c086b44: /* original 8901, guest PC 0x0c086b44 */
if(!s->budget--) { s->failed_pc=0x0c086b44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086b4a; }
goto P_0c086b46;
P_0c086b46: /* original a0b7, guest PC 0x0c086b46 */
if(!s->budget--) { s->failed_pc=0x0c086b46u; return 0; }
goto P_0c086cb8;
P_0c086b48: /* original 0009, guest PC 0x0c086b48 */
if(!s->budget--) { s->failed_pc=0x0c086b48u; return 0; }
goto P_0c086b4a;
P_0c086b4a: /* original 5141, guest PC 0x0c086b4a */
if(!s->budget--) { s->failed_pc=0x0c086b4au; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c086b4c;
P_0c086b4c: /* original d30f, guest PC 0x0c086b4c */
if(!s->budget--) { s->failed_pc=0x0c086b4cu; return 0; }
r[3]=read(ram,0x0c086b8cu,4);
goto P_0c086b4e;
P_0c086b4e: /* original 2138, guest PC 0x0c086b4e */
if(!s->budget--) { s->failed_pc=0x0c086b4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c086b50;
P_0c086b50: /* original 8901, guest PC 0x0c086b50 */
if(!s->budget--) { s->failed_pc=0x0c086b50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086b56; }
goto P_0c086b52;
P_0c086b52: /* original a0b1, guest PC 0x0c086b52 */
if(!s->budget--) { s->failed_pc=0x0c086b52u; return 0; }
goto P_0c086cb8;
P_0c086b54: /* original 0009, guest PC 0x0c086b54 */
if(!s->budget--) { s->failed_pc=0x0c086b54u; return 0; }
goto P_0c086b56;
P_0c086b56: /* original d00e, guest PC 0x0c086b56 */
if(!s->budget--) { s->failed_pc=0x0c086b56u; return 0; }
r[0]=read(ram,0x0c086b90u,4);
goto P_0c086b58;
P_0c086b58: /* original ec01, guest PC 0x0c086b58 */
if(!s->budget--) { s->failed_pc=0x0c086b58u; return 0; }
r[12]=0x00000001u;
goto P_0c086b5a;
P_0c086b5a: /* original eb0f, guest PC 0x0c086b5a */
if(!s->budget--) { s->failed_pc=0x0c086b5au; return 0; }
r[11]=0x0000000fu;
goto P_0c086b5c;
P_0c086b5c: /* original 6802, guest PC 0x0c086b5c */
if(!s->budget--) { s->failed_pc=0x0c086b5cu; return 0; }
tmp=read(ram,r[0],4);
r[8]=tmp;
goto P_0c086b5e;
P_0c086b5e: /* original e00c, guest PC 0x0c086b5e */
if(!s->budget--) { s->failed_pc=0x0c086b5eu; return 0; }
r[0]=0x0000000cu;
goto P_0c086b60;
P_0c086b60: /* original fdd6, guest PC 0x0c086b60 */
if(!s->budget--) { s->failed_pc=0x0c086b60u; return 0; }
vf3_matrix_load(s,ram,13,r[13]+r[0]);
goto P_0c086b62;
P_0c086b62: /* original e010, guest PC 0x0c086b62 */
if(!s->budget--) { s->failed_pc=0x0c086b62u; return 0; }
r[0]=0x00000010u;
goto P_0c086b64;
P_0c086b64: /* original f3d6, guest PC 0x0c086b64 */
if(!s->budget--) { s->failed_pc=0x0c086b64u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c086b66;
P_0c086b66: /* original e014, guest PC 0x0c086b66 */
if(!s->budget--) { s->failed_pc=0x0c086b66u; return 0; }
r[0]=0x00000014u;
goto P_0c086b68;
P_0c086b68: /* original ff3a, guest PC 0x0c086b68 */
if(!s->budget--) { s->failed_pc=0x0c086b68u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c086b6a;
P_0c086b6a: /* original fcd6, guest PC 0x0c086b6a */
if(!s->budget--) { s->failed_pc=0x0c086b6au; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c086b6c;
P_0c086b6c: /* original e03c, guest PC 0x0c086b6c */
if(!s->budget--) { s->failed_pc=0x0c086b6cu; return 0; }
r[0]=0x0000003cu;
goto P_0c086b6e;
P_0c086b6e: /* original fed6, guest PC 0x0c086b6e */
if(!s->budget--) { s->failed_pc=0x0c086b6eu; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c086b70;
P_0c086b70: /* original e040, guest PC 0x0c086b70 */
if(!s->budget--) { s->failed_pc=0x0c086b70u; return 0; }
r[0]=0x00000040u;
goto P_0c086b72;
P_0c086b72: /* original f3d6, guest PC 0x0c086b72 */
if(!s->budget--) { s->failed_pc=0x0c086b72u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c086b74;
P_0c086b74: /* original e004, guest PC 0x0c086b74 */
if(!s->budget--) { s->failed_pc=0x0c086b74u; return 0; }
r[0]=0x00000004u;
goto P_0c086b76;
P_0c086b76: /* original ff37, guest PC 0x0c086b76 */
if(!s->budget--) { s->failed_pc=0x0c086b76u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c086b78;
P_0c086b78: /* original c706, guest PC 0x0c086b78 */
if(!s->budget--) { s->failed_pc=0x0c086b78u; return 0; }
r[0]=0x0c086b94u;
goto P_0c086b7a;
P_0c086b7a: /* original da07, guest PC 0x0c086b7a */
if(!s->budget--) { s->failed_pc=0x0c086b7au; return 0; }
r[10]=read(ram,0x0c086b98u,4);
goto P_0c086b7c;
P_0c086b7c: /* original ff08, guest PC 0x0c086b7c */
if(!s->budget--) { s->failed_pc=0x0c086b7cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c086b7e;
P_0c086b7e: /* original a072, guest PC 0x0c086b7e */
if(!s->budget--) { s->failed_pc=0x0c086b7eu; return 0; }
r[9]=0x00000002u;
goto P_0c086c66;
P_0c086b80: /* original e902, guest PC 0x0c086b80 */
if(!s->budget--) { s->failed_pc=0x0c086b80u; return 0; }
r[9]=0x00000002u;
return vf3_matrix_family(0x0c086b82u,s,ram);
P_0c086b9c: /* original d24f, guest PC 0x0c086b9c */
if(!s->budget--) { s->failed_pc=0x0c086b9cu; return 0; }
r[2]=read(ram,0x0c086cdcu,4);
goto P_0c086b9e;
P_0c086b9e: /* original 420b, guest PC 0x0c086b9e */
if(!s->budget--) { s->failed_pc=0x0c086b9eu; return 0; }
target=r[2];
r[16]=code_base|0x0c086ba2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086ba2u) { target=s->pc; goto dispatch; }
goto P_0c086ba2;
P_0c086ba0: /* original 64d3, guest PC 0x0c086ba0 */
if(!s->budget--) { s->failed_pc=0x0c086ba0u; return 0; }
r[4]=r[13];
goto P_0c086ba2;
P_0c086ba2: /* original 88ff, guest PC 0x0c086ba2 */
if(!s->budget--) { s->failed_pc=0x0c086ba2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086ba4;
P_0c086ba4: /* original 8f02, guest PC 0x0c086ba4 */
if(!s->budget--) { s->failed_pc=0x0c086ba4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c086bac; }
goto P_0c086ba8;
P_0c086ba6: /* original 6403, guest PC 0x0c086ba6 */
if(!s->budget--) { s->failed_pc=0x0c086ba6u; return 0; }
r[4]=r[0];
goto P_0c086ba8;
P_0c086ba8: /* original a086, guest PC 0x0c086ba8 */
if(!s->budget--) { s->failed_pc=0x0c086ba8u; return 0; }
goto P_0c086cb8;
P_0c086baa: /* original 0009, guest PC 0x0c086baa */
if(!s->budget--) { s->failed_pc=0x0c086baau; return 0; }
goto P_0c086bac;
P_0c086bac: /* original e00c, guest PC 0x0c086bac */
if(!s->budget--) { s->failed_pc=0x0c086bacu; return 0; }
r[0]=0x0000000cu;
goto P_0c086bae;
P_0c086bae: /* original 6e43, guest PC 0x0c086bae */
if(!s->budget--) { s->failed_pc=0x0c086baeu; return 0; }
r[14]=r[4];
goto P_0c086bb0;
P_0c086bb0: /* original fed7, guest PC 0x0c086bb0 */
if(!s->budget--) { s->failed_pc=0x0c086bb0u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c086bb2;
P_0c086bb2: /* original e010, guest PC 0x0c086bb2 */
if(!s->budget--) { s->failed_pc=0x0c086bb2u; return 0; }
r[0]=0x00000010u;
goto P_0c086bb4;
P_0c086bb4: /* original f3f8, guest PC 0x0c086bb4 */
if(!s->budget--) { s->failed_pc=0x0c086bb4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c086bb6;
P_0c086bb6: /* original fe37, guest PC 0x0c086bb6 */
if(!s->budget--) { s->failed_pc=0x0c086bb6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c086bb8;
P_0c086bb8: /* original e014, guest PC 0x0c086bb8 */
if(!s->budget--) { s->failed_pc=0x0c086bb8u; return 0; }
r[0]=0x00000014u;
goto P_0c086bba;
P_0c086bba: /* original 4a0b, guest PC 0x0c086bba */
if(!s->budget--) { s->failed_pc=0x0c086bbau; return 0; }
target=r[10];
r[16]=code_base|0x0c086bbeu;
vf3_matrix_store(s,ram,12,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086bbeu) { target=s->pc; goto dispatch; }
goto P_0c086bbe;
P_0c086bbc: /* original fec7, guest PC 0x0c086bbc */
if(!s->budget--) { s->failed_pc=0x0c086bbcu; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c086bbe;
P_0c086bbe: /* original 6503, guest PC 0x0c086bbe */
if(!s->budget--) { s->failed_pc=0x0c086bbeu; return 0; }
r[5]=r[0];
goto P_0c086bc0;
P_0c086bc0: /* original 25b9, guest PC 0x0c086bc0 */
if(!s->budget--) { s->failed_pc=0x0c086bc0u; return 0; }
r[5]&=r[11];
goto P_0c086bc2;
P_0c086bc2: /* original 455a, guest PC 0x0c086bc2 */
if(!s->budget--) { s->failed_pc=0x0c086bc2u; return 0; }
r[53]=r[5];
goto P_0c086bc4;
P_0c086bc4: /* original e3fb, guest PC 0x0c086bc4 */
if(!s->budget--) { s->failed_pc=0x0c086bc4u; return 0; }
r[3]=0xfffffffbu;
goto P_0c086bc6;
P_0c086bc6: /* original 6403, guest PC 0x0c086bc6 */
if(!s->budget--) { s->failed_pc=0x0c086bc6u; return 0; }
r[4]=r[0];
goto P_0c086bc8;
P_0c086bc8: /* original e61f, guest PC 0x0c086bc8 */
if(!s->budget--) { s->failed_pc=0x0c086bc8u; return 0; }
r[6]=0x0000001fu;
goto P_0c086bca;
P_0c086bca: /* original 403c, guest PC 0x0c086bca */
if(!s->budget--) { s->failed_pc=0x0c086bcau; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c086bcc;
P_0c086bcc: /* original f7fc, guest PC 0x0c086bcc */
if(!s->budget--) { s->failed_pc=0x0c086bccu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c086bce;
P_0c086bce: /* original f32d, guest PC 0x0c086bce */
if(!s->budget--) { s->failed_pc=0x0c086bceu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c086bd0;
P_0c086bd0: /* original 2609, guest PC 0x0c086bd0 */
if(!s->budget--) { s->failed_pc=0x0c086bd0u; return 0; }
r[6]&=r[0];
goto P_0c086bd2;
P_0c086bd2: /* original 465a, guest PC 0x0c086bd2 */
if(!s->budget--) { s->failed_pc=0x0c086bd2u; return 0; }
r[53]=r[6];
goto P_0c086bd4;
P_0c086bd4: /* original e3f7, guest PC 0x0c086bd4 */
if(!s->budget--) { s->failed_pc=0x0c086bd4u; return 0; }
r[3]=0xfffffff7u;
goto P_0c086bd6;
P_0c086bd6: /* original 443c, guest PC 0x0c086bd6 */
if(!s->budget--) { s->failed_pc=0x0c086bd6u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c086bd8;
P_0c086bd8: /* original 24b9, guest PC 0x0c086bd8 */
if(!s->budget--) { s->failed_pc=0x0c086bd8u; return 0; }
r[4]&=r[11];
goto P_0c086bda;
P_0c086bda: /* original f22d, guest PC 0x0c086bda */
if(!s->budget--) { s->failed_pc=0x0c086bdau; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c086bdc;
P_0c086bdc: /* original 445a, guest PC 0x0c086bdc */
if(!s->budget--) { s->failed_pc=0x0c086bdcu; return 0; }
r[53]=r[4];
goto P_0c086bde;
P_0c086bde: /* original f53c, guest PC 0x0c086bde */
if(!s->budget--) { s->failed_pc=0x0c086bdeu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c086be0;
P_0c086be0: /* original f572, guest PC 0x0c086be0 */
if(!s->budget--) { s->failed_pc=0x0c086be0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c086be2;
P_0c086be2: /* original 25c8, guest PC 0x0c086be2 */
if(!s->budget--) { s->failed_pc=0x0c086be2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[12])==0)!=0);
goto P_0c086be4;
P_0c086be4: /* original f32d, guest PC 0x0c086be4 */
if(!s->budget--) { s->failed_pc=0x0c086be4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c086be6;
P_0c086be6: /* original f62c, guest PC 0x0c086be6 */
if(!s->budget--) { s->failed_pc=0x0c086be6u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c086be8;
P_0c086be8: /* original f672, guest PC 0x0c086be8 */
if(!s->budget--) { s->failed_pc=0x0c086be8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c086bea;
P_0c086bea: /* original f43c, guest PC 0x0c086bea */
if(!s->budget--) { s->failed_pc=0x0c086beau; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c086bec;
P_0c086bec: /* original 8f01, guest PC 0x0c086bec */
if(!s->budget--) { s->failed_pc=0x0c086becu; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
if(!cond) { goto P_0c086bf2; }
goto P_0c086bf0;
P_0c086bee: /* original f472, guest PC 0x0c086bee */
if(!s->budget--) { s->failed_pc=0x0c086beeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c086bf0;
P_0c086bf0: /* original f54d, guest PC 0x0c086bf0 */
if(!s->budget--) { s->failed_pc=0x0c086bf0u; return 0; }
fr[5]^=0x80000000u;
goto P_0c086bf2;
P_0c086bf2: /* original 26c8, guest PC 0x0c086bf2 */
if(!s->budget--) { s->failed_pc=0x0c086bf2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[12])==0)!=0);
goto P_0c086bf4;
P_0c086bf4: /* original 8b00, guest PC 0x0c086bf4 */
if(!s->budget--) { s->failed_pc=0x0c086bf4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086bf8; }
goto P_0c086bf6;
P_0c086bf6: /* original f64d, guest PC 0x0c086bf6 */
if(!s->budget--) { s->failed_pc=0x0c086bf6u; return 0; }
fr[6]^=0x80000000u;
goto P_0c086bf8;
P_0c086bf8: /* original 24c8, guest PC 0x0c086bf8 */
if(!s->budget--) { s->failed_pc=0x0c086bf8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[12])==0)!=0);
goto P_0c086bfa;
P_0c086bfa: /* original 8f01, guest PC 0x0c086bfa */
if(!s->budget--) { s->failed_pc=0x0c086bfau; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'+');
if(!cond) { goto P_0c086c00; }
goto P_0c086bfe;
P_0c086bfc: /* original f5e0, guest PC 0x0c086bfc */
if(!s->budget--) { s->failed_pc=0x0c086bfcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'+');
goto P_0c086bfe;
P_0c086bfe: /* original f44d, guest PC 0x0c086bfe */
if(!s->budget--) { s->failed_pc=0x0c086bfeu; return 0; }
fr[4]^=0x80000000u;
goto P_0c086c00;
P_0c086c00: /* original e004, guest PC 0x0c086c00 */
if(!s->budget--) { s->failed_pc=0x0c086c00u; return 0; }
r[0]=0x00000004u;
goto P_0c086c02;
P_0c086c02: /* original f3f6, guest PC 0x0c086c02 */
if(!s->budget--) { s->failed_pc=0x0c086c02u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c086c04;
P_0c086c04: /* original e018, guest PC 0x0c086c04 */
if(!s->budget--) { s->failed_pc=0x0c086c04u; return 0; }
r[0]=0x00000018u;
goto P_0c086c06;
P_0c086c06: /* original fe57, guest PC 0x0c086c06 */
if(!s->budget--) { s->failed_pc=0x0c086c06u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c086c08;
P_0c086c08: /* original e01c, guest PC 0x0c086c08 */
if(!s->budget--) { s->failed_pc=0x0c086c08u; return 0; }
r[0]=0x0000001cu;
goto P_0c086c0a;
P_0c086c0a: /* original f430, guest PC 0x0c086c0a */
if(!s->budget--) { s->failed_pc=0x0c086c0au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c086c0c;
P_0c086c0c: /* original fe67, guest PC 0x0c086c0c */
if(!s->budget--) { s->failed_pc=0x0c086c0cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c086c0e;
P_0c086c0e: /* original e020, guest PC 0x0c086c0e */
if(!s->budget--) { s->failed_pc=0x0c086c0eu; return 0; }
r[0]=0x00000020u;
goto P_0c086c10;
P_0c086c10: /* original e300, guest PC 0x0c086c10 */
if(!s->budget--) { s->failed_pc=0x0c086c10u; return 0; }
r[3]=0x00000000u;
goto P_0c086c12;
P_0c086c12: /* original fe47, guest PC 0x0c086c12 */
if(!s->budget--) { s->failed_pc=0x0c086c12u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c086c14;
P_0c086c14: /* original e026, guest PC 0x0c086c14 */
if(!s->budget--) { s->failed_pc=0x0c086c14u; return 0; }
r[0]=0x00000026u;
goto P_0c086c16;
P_0c086c16: /* original 4a0b, guest PC 0x0c086c16 */
if(!s->budget--) { s->failed_pc=0x0c086c16u; return 0; }
target=r[10];
r[16]=code_base|0x0c086c1au;
write(ram,r[14]+r[0],r[3],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086c1au) { target=s->pc; goto dispatch; }
goto P_0c086c1a;
P_0c086c18: /* original 0e34, guest PC 0x0c086c18 */
if(!s->budget--) { s->failed_pc=0x0c086c18u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c086c1a;
P_0c086c1a: /* original e507, guest PC 0x0c086c1a */
if(!s->budget--) { s->failed_pc=0x0c086c1au; return 0; }
r[5]=0x00000007u;
goto P_0c086c1c;
P_0c086c1c: /* original 6403, guest PC 0x0c086c1c */
if(!s->budget--) { s->failed_pc=0x0c086c1cu; return 0; }
r[4]=r[0];
goto P_0c086c1e;
P_0c086c1e: /* original e038, guest PC 0x0c086c1e */
if(!s->budget--) { s->failed_pc=0x0c086c1eu; return 0; }
r[0]=0x00000038u;
goto P_0c086c20;
P_0c086c20: /* original 2549, guest PC 0x0c086c20 */
if(!s->budget--) { s->failed_pc=0x0c086c20u; return 0; }
r[5]&=r[4];
goto P_0c086c22;
P_0c086c22: /* original 04dc, guest PC 0x0c086c22 */
if(!s->budget--) { s->failed_pc=0x0c086c22u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086c24;
P_0c086c24: /* original d02e, guest PC 0x0c086c24 */
if(!s->budget--) { s->failed_pc=0x0c086c24u; return 0; }
r[0]=read(ram,0x0c086ce0u,4);
goto P_0c086c26;
P_0c086c26: /* original 4408, guest PC 0x0c086c26 */
if(!s->budget--) { s->failed_pc=0x0c086c26u; return 0; }
r[4]<<=2;
goto P_0c086c28;
P_0c086c28: /* original 4400, guest PC 0x0c086c28 */
if(!s->budget--) { s->failed_pc=0x0c086c28u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c086c2a;
P_0c086c2a: /* original 354c, guest PC 0x0c086c2a */
if(!s->budget--) { s->failed_pc=0x0c086c2au; return 0; }
r[5]+=r[4];
goto P_0c086c2c;
P_0c086c2c: /* original 055c, guest PC 0x0c086c2c */
if(!s->budget--) { s->failed_pc=0x0c086c2cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c086c2e;
P_0c086c2e: /* original d02d, guest PC 0x0c086c2e */
if(!s->budget--) { s->failed_pc=0x0c086c2eu; return 0; }
r[0]=read(ram,0x0c086ce4u,4);
goto P_0c086c30;
P_0c086c30: /* original 4508, guest PC 0x0c086c30 */
if(!s->budget--) { s->failed_pc=0x0c086c30u; return 0; }
r[5]<<=2;
goto P_0c086c32;
P_0c086c32: /* original 055e, guest PC 0x0c086c32 */
if(!s->budget--) { s->failed_pc=0x0c086c32u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c086c34;
P_0c086c34: /* original 1e5a, guest PC 0x0c086c34 */
if(!s->budget--) { s->failed_pc=0x0c086c34u; return 0; }
write(ram,r[14]+40,r[5],4);
goto P_0c086c36;
P_0c086c36: /* original d32c, guest PC 0x0c086c36 */
if(!s->budget--) { s->failed_pc=0x0c086c36u; return 0; }
r[3]=read(ram,0x0c086ce8u,4);
goto P_0c086c38;
P_0c086c38: /* original 430b, guest PC 0x0c086c38 */
if(!s->budget--) { s->failed_pc=0x0c086c38u; return 0; }
target=r[3];
r[16]=code_base|0x0c086c3cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086c3cu) { target=s->pc; goto dispatch; }
goto P_0c086c3c;
P_0c086c3a: /* original 64e3, guest PC 0x0c086c3a */
if(!s->budget--) { s->failed_pc=0x0c086c3au; return 0; }
r[4]=r[14];
goto P_0c086c3c;
P_0c086c3c: /* original 858f, guest PC 0x0c086c3c */
if(!s->budget--) { s->failed_pc=0x0c086c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+30,2);
goto P_0c086c3e;
P_0c086c3e: /* original 79ff, guest PC 0x0c086c3e */
if(!s->budget--) { s->failed_pc=0x0c086c3eu; return 0; }
r[9]+=0xffffffffu;
goto P_0c086c40;
P_0c086c40: /* original d32a, guest PC 0x0c086c40 */
if(!s->budget--) { s->failed_pc=0x0c086c40u; return 0; }
r[3]=read(ram,0x0c086cecu,4);
goto P_0c086c42;
P_0c086c42: /* original 6403, guest PC 0x0c086c42 */
if(!s->budget--) { s->failed_pc=0x0c086c42u; return 0; }
r[4]=r[0];
goto P_0c086c44;
P_0c086c44: /* original 9146, guest PC 0x0c086c44 */
if(!s->budget--) { s->failed_pc=0x0c086c44u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cd4u,2);
goto P_0c086c46;
P_0c086c46: /* original 6032, guest PC 0x0c086c46 */
if(!s->budget--) { s->failed_pc=0x0c086c46u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c086c48;
P_0c086c48: /* original e3f3, guest PC 0x0c086c48 */
if(!s->budget--) { s->failed_pc=0x0c086c48u; return 0; }
r[3]=0xfffffff3u;
goto P_0c086c4a;
P_0c086c4a: /* original c903, guest PC 0x0c086c4a */
if(!s->budget--) { s->failed_pc=0x0c086c4au; return 0; }
r[0]&=3u;
goto P_0c086c4c;
P_0c086c4c: /* original 6503, guest PC 0x0c086c4c */
if(!s->budget--) { s->failed_pc=0x0c086c4cu; return 0; }
r[5]=r[0];
goto P_0c086c4e;
P_0c086c4e: /* original d028, guest PC 0x0c086c4e */
if(!s->budget--) { s->failed_pc=0x0c086c4eu; return 0; }
r[0]=read(ram,0x0c086cf0u,4);
goto P_0c086c50;
P_0c086c50: /* original 4500, guest PC 0x0c086c50 */
if(!s->budget--) { s->failed_pc=0x0c086c50u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c086c52;
P_0c086c52: /* original 025d, guest PC 0x0c086c52 */
if(!s->budget--) { s->failed_pc=0x0c086c52u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c086c54;
P_0c086c54: /* original 903f, guest PC 0x0c086c54 */
if(!s->budget--) { s->failed_pc=0x0c086c54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cd6u,2);
goto P_0c086c56;
P_0c086c56: /* original 652d, guest PC 0x0c086c56 */
if(!s->budget--) { s->failed_pc=0x0c086c56u; return 0; }
r[5]=r[2]&65535u;
goto P_0c086c58;
P_0c086c58: /* original 345c, guest PC 0x0c086c58 */
if(!s->budget--) { s->failed_pc=0x0c086c58u; return 0; }
r[4]+=r[5];
goto P_0c086c5a;
P_0c086c5a: /* original 341c, guest PC 0x0c086c5a */
if(!s->budget--) { s->failed_pc=0x0c086c5au; return 0; }
r[4]+=r[1];
goto P_0c086c5c;
P_0c086c5c: /* original e503, guest PC 0x0c086c5c */
if(!s->budget--) { s->failed_pc=0x0c086c5cu; return 0; }
r[5]=0x00000003u;
goto P_0c086c5e;
P_0c086c5e: /* original 443c, guest PC 0x0c086c5e */
if(!s->budget--) { s->failed_pc=0x0c086c5eu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c086c60;
P_0c086c60: /* original 2549, guest PC 0x0c086c60 */
if(!s->budget--) { s->failed_pc=0x0c086c60u; return 0; }
r[5]&=r[4];
goto P_0c086c62;
P_0c086c62: /* original 305c, guest PC 0x0c086c62 */
if(!s->budget--) { s->failed_pc=0x0c086c62u; return 0; }
r[0]+=r[5];
goto P_0c086c64;
P_0c086c64: /* original 81e5, guest PC 0x0c086c64 */
if(!s->budget--) { s->failed_pc=0x0c086c64u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c086c66;
P_0c086c66: /* original 2998, guest PC 0x0c086c66 */
if(!s->budget--) { s->failed_pc=0x0c086c66u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c086c68;
P_0c086c68: /* original 8b98, guest PC 0x0c086c68 */
if(!s->budget--) { s->failed_pc=0x0c086c68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086b9c; }
goto P_0c086c6a;
P_0c086c6a: /* original e03b, guest PC 0x0c086c6a */
if(!s->budget--) { s->failed_pc=0x0c086c6au; return 0; }
r[0]=0x0000003bu;
goto P_0c086c6c;
P_0c086c6c: /* original 04dc, guest PC 0x0c086c6c */
if(!s->budget--) { s->failed_pc=0x0c086c6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086c6e;
P_0c086c6e: /* original 4410, guest PC 0x0c086c6e */
if(!s->budget--) { s->failed_pc=0x0c086c6eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c086c70;
P_0c086c70: /* original 8b20, guest PC 0x0c086c70 */
if(!s->budget--) { s->failed_pc=0x0c086c70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086cb4; }
goto P_0c086c72;
P_0c086c72: /* original c721, guest PC 0x0c086c72 */
if(!s->budget--) { s->failed_pc=0x0c086c72u; return 0; }
r[0]=0x0c086cf8u;
goto P_0c086c74;
P_0c086c74: /* original d31f, guest PC 0x0c086c74 */
if(!s->budget--) { s->failed_pc=0x0c086c74u; return 0; }
r[3]=read(ram,0x0c086cf4u,4);
goto P_0c086c76;
P_0c086c76: /* original f608, guest PC 0x0c086c76 */
if(!s->budget--) { s->failed_pc=0x0c086c76u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c086c78;
P_0c086c78: /* original e010, guest PC 0x0c086c78 */
if(!s->budget--) { s->failed_pc=0x0c086c78u; return 0; }
r[0]=0x00000010u;
goto P_0c086c7a;
P_0c086c7a: /* original f486, guest PC 0x0c086c7a */
if(!s->budget--) { s->failed_pc=0x0c086c7au; return 0; }
vf3_matrix_load(s,ram,4,r[8]+r[0]);
goto P_0c086c7c;
P_0c086c7c: /* original e018, guest PC 0x0c086c7c */
if(!s->budget--) { s->failed_pc=0x0c086c7cu; return 0; }
r[0]=0x00000018u;
goto P_0c086c7e;
P_0c086c7e: /* original f586, guest PC 0x0c086c7e */
if(!s->budget--) { s->failed_pc=0x0c086c7eu; return 0; }
vf3_matrix_load(s,ram,5,r[8]+r[0]);
goto P_0c086c80;
P_0c086c80: /* original e00c, guest PC 0x0c086c80 */
if(!s->budget--) { s->failed_pc=0x0c086c80u; return 0; }
r[0]=0x0000000cu;
goto P_0c086c82;
P_0c086c82: /* original f7d6, guest PC 0x0c086c82 */
if(!s->budget--) { s->failed_pc=0x0c086c82u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c086c84;
P_0c086c84: /* original e014, guest PC 0x0c086c84 */
if(!s->budget--) { s->failed_pc=0x0c086c84u; return 0; }
r[0]=0x00000014u;
goto P_0c086c86;
P_0c086c86: /* original f8d6, guest PC 0x0c086c86 */
if(!s->budget--) { s->failed_pc=0x0c086c86u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c086c88;
P_0c086c88: /* original e43f, guest PC 0x0c086c88 */
if(!s->budget--) { s->failed_pc=0x0c086c88u; return 0; }
r[4]=0x0000003fu;
goto P_0c086c8a;
P_0c086c8a: /* original f471, guest PC 0x0c086c8a */
if(!s->budget--) { s->failed_pc=0x0c086c8au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'-');
goto P_0c086c8c;
P_0c086c8c: /* original 2459, guest PC 0x0c086c8c */
if(!s->budget--) { s->failed_pc=0x0c086c8cu; return 0; }
r[4]&=r[5];
goto P_0c086c8e;
P_0c086c8e: /* original f581, guest PC 0x0c086c8e */
if(!s->budget--) { s->failed_pc=0x0c086c8eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c086c90;
P_0c086c90: /* original 6532, guest PC 0x0c086c90 */
if(!s->budget--) { s->failed_pc=0x0c086c90u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c086c92;
P_0c086c92: /* original 7407, guest PC 0x0c086c92 */
if(!s->budget--) { s->failed_pc=0x0c086c92u; return 0; }
r[4]+=0x00000007u;
goto P_0c086c94;
P_0c086c94: /* original f34c, guest PC 0x0c086c94 */
if(!s->budget--) { s->failed_pc=0x0c086c94u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c086c96;
P_0c086c96: /* original f432, guest PC 0x0c086c96 */
if(!s->budget--) { s->failed_pc=0x0c086c96u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c086c98;
P_0c086c98: /* original f35c, guest PC 0x0c086c98 */
if(!s->budget--) { s->failed_pc=0x0c086c98u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c086c9a;
P_0c086c9a: /* original f532, guest PC 0x0c086c9a */
if(!s->budget--) { s->failed_pc=0x0c086c9au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c086c9c;
P_0c086c9c: /* original f450, guest PC 0x0c086c9c */
if(!s->budget--) { s->failed_pc=0x0c086c9cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c086c9e;
P_0c086c9e: /* original f465, guest PC 0x0c086c9e */
if(!s->budget--) { s->failed_pc=0x0c086c9eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c086ca0;
P_0c086ca0: /* original 8d03, guest PC 0x0c086ca0 */
if(!s->budget--) { s->failed_pc=0x0c086ca0u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(cond) { goto P_0c086caa; }
goto P_0c086ca4;
P_0c086ca2: /* original 6552, guest PC 0x0c086ca2 */
if(!s->budget--) { s->failed_pc=0x0c086ca2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c086ca4;
P_0c086ca4: /* original 9118, guest PC 0x0c086ca4 */
if(!s->budget--) { s->failed_pc=0x0c086ca4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cd8u,2);
goto P_0c086ca6;
P_0c086ca6: /* original a002, guest PC 0x0c086ca6 */
if(!s->budget--) { s->failed_pc=0x0c086ca6u; return 0; }
r[5]|=r[1];
goto P_0c086cae;
P_0c086ca8: /* original 251b, guest PC 0x0c086ca8 */
if(!s->budget--) { s->failed_pc=0x0c086ca8u; return 0; }
r[5]|=r[1];
goto P_0c086caa;
P_0c086caa: /* original 9016, guest PC 0x0c086caa */
if(!s->budget--) { s->failed_pc=0x0c086caau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cdau,2);
goto P_0c086cac;
P_0c086cac: /* original 250b, guest PC 0x0c086cac */
if(!s->budget--) { s->failed_pc=0x0c086cacu; return 0; }
r[5]|=r[0];
goto P_0c086cae;
P_0c086cae: /* original d211, guest PC 0x0c086cae */
if(!s->budget--) { s->failed_pc=0x0c086caeu; return 0; }
r[2]=read(ram,0x0c086cf4u,4);
goto P_0c086cb0;
P_0c086cb0: /* original 6322, guest PC 0x0c086cb0 */
if(!s->budget--) { s->failed_pc=0x0c086cb0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c086cb2;
P_0c086cb2: /* original 2352, guest PC 0x0c086cb2 */
if(!s->budget--) { s->failed_pc=0x0c086cb2u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c086cb4;
P_0c086cb4: /* original e03b, guest PC 0x0c086cb4 */
if(!s->budget--) { s->failed_pc=0x0c086cb4u; return 0; }
r[0]=0x0000003bu;
goto P_0c086cb6;
P_0c086cb6: /* original 0d44, guest PC 0x0c086cb6 */
if(!s->budget--) { s->failed_pc=0x0c086cb6u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c086cb8;
P_0c086cb8: /* original 7f08, guest PC 0x0c086cb8 */
if(!s->budget--) { s->failed_pc=0x0c086cb8u; return 0; }
r[15]+=0x00000008u;
goto P_0c086cba;
P_0c086cba: /* original 4f26, guest PC 0x0c086cba */
if(!s->budget--) { s->failed_pc=0x0c086cbau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086cbc;
P_0c086cbc: /* original fcf9, guest PC 0x0c086cbc */
if(!s->budget--) { s->failed_pc=0x0c086cbcu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cbe;
P_0c086cbe: /* original fdf9, guest PC 0x0c086cbe */
if(!s->budget--) { s->failed_pc=0x0c086cbeu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cc0;
P_0c086cc0: /* original fef9, guest PC 0x0c086cc0 */
if(!s->budget--) { s->failed_pc=0x0c086cc0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cc2;
P_0c086cc2: /* original fff9, guest PC 0x0c086cc2 */
if(!s->budget--) { s->failed_pc=0x0c086cc2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cc4;
P_0c086cc4: /* original 68f6, guest PC 0x0c086cc4 */
if(!s->budget--) { s->failed_pc=0x0c086cc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c086cc6;
P_0c086cc6: /* original 69f6, guest PC 0x0c086cc6 */
if(!s->budget--) { s->failed_pc=0x0c086cc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c086cc8;
P_0c086cc8: /* original 6af6, guest PC 0x0c086cc8 */
if(!s->budget--) { s->failed_pc=0x0c086cc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c086cca;
P_0c086cca: /* original 6bf6, guest PC 0x0c086cca */
if(!s->budget--) { s->failed_pc=0x0c086ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c086ccc;
P_0c086ccc: /* original 6cf6, guest PC 0x0c086ccc */
if(!s->budget--) { s->failed_pc=0x0c086cccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086cce;
P_0c086cce: /* original 6df6, guest PC 0x0c086cce */
if(!s->budget--) { s->failed_pc=0x0c086cceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086cd0;
P_0c086cd0: /* original 000b, guest PC 0x0c086cd0 */
if(!s->budget--) { s->failed_pc=0x0c086cd0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086cd2: /* original 6ef6, guest PC 0x0c086cd2 */
if(!s->budget--) { s->failed_pc=0x0c086cd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c086cd4u,s,ram);
P_0c086cfc: /* original c74d, guest PC 0x0c086cfc */
if(!s->budget--) { s->failed_pc=0x0c086cfcu; return 0; }
r[0]=0x0c086e34u;
goto P_0c086cfe;
P_0c086cfe: /* original 2fd6, guest PC 0x0c086cfe */
if(!s->budget--) { s->failed_pc=0x0c086cfeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086d00;
P_0c086d00: /* original 2fc6, guest PC 0x0c086d00 */
if(!s->budget--) { s->failed_pc=0x0c086d00u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086d02;
P_0c086d02: /* original ec00, guest PC 0x0c086d02 */
if(!s->budget--) { s->failed_pc=0x0c086d02u; return 0; }
r[12]=0x00000000u;
goto P_0c086d04;
P_0c086d04: /* original 2fa6, guest PC 0x0c086d04 */
if(!s->budget--) { s->failed_pc=0x0c086d04u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086d06;
P_0c086d06: /* original fa08, guest PC 0x0c086d06 */
if(!s->budget--) { s->failed_pc=0x0c086d06u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c086d08;
P_0c086d08: /* original c74b, guest PC 0x0c086d08 */
if(!s->budget--) { s->failed_pc=0x0c086d08u; return 0; }
r[0]=0x0c086e38u;
goto P_0c086d0a;
P_0c086d0a: /* original da4c, guest PC 0x0c086d0a */
if(!s->budget--) { s->failed_pc=0x0c086d0au; return 0; }
r[10]=read(ram,0x0c086e3cu,4);
goto P_0c086d0c;
P_0c086d0c: /* original fb08, guest PC 0x0c086d0c */
if(!s->budget--) { s->failed_pc=0x0c086d0cu; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c086d0e;
P_0c086d0e: /* original 60c3, guest PC 0x0c086d0e */
if(!s->budget--) { s->failed_pc=0x0c086d0eu; return 0; }
r[0]=r[12];
goto P_0c086d10;
P_0c086d10: /* original 4000, guest PC 0x0c086d10 */
if(!s->budget--) { s->failed_pc=0x0c086d10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c086d12;
P_0c086d12: /* original 0dad, guest PC 0x0c086d12 */
if(!s->budget--) { s->failed_pc=0x0c086d12u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c086d14;
P_0c086d14: /* original d64a, guest PC 0x0c086d14 */
if(!s->budget--) { s->failed_pc=0x0c086d14u; return 0; }
r[6]=read(ram,0x0c086e40u,4);
goto P_0c086d16;
P_0c086d16: /* original 6ddd, guest PC 0x0c086d16 */
if(!s->budget--) { s->failed_pc=0x0c086d16u; return 0; }
r[13]=r[13]&65535u;
goto P_0c086d18;
P_0c086d18: /* original 3d60, guest PC 0x0c086d18 */
if(!s->budget--) { s->failed_pc=0x0c086d18u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[6])!=0);
goto P_0c086d1a;
P_0c086d1a: /* original 8946, guest PC 0x0c086d1a */
if(!s->budget--) { s->failed_pc=0x0c086d1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086daa; }
goto P_0c086d1c;
P_0c086d1c: /* original 66d3, guest PC 0x0c086d1c */
if(!s->budget--) { s->failed_pc=0x0c086d1cu; return 0; }
r[6]=r[13];
goto P_0c086d1e;
P_0c086d1e: /* original 4600, guest PC 0x0c086d1e */
if(!s->budget--) { s->failed_pc=0x0c086d1eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c086d20;
P_0c086d20: /* original 63d3, guest PC 0x0c086d20 */
if(!s->budget--) { s->failed_pc=0x0c086d20u; return 0; }
r[3]=r[13];
goto P_0c086d22;
P_0c086d22: /* original 9780, guest PC 0x0c086d22 */
if(!s->budget--) { s->failed_pc=0x0c086d22u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e26u,2);
goto P_0c086d24;
P_0c086d24: /* original 363c, guest PC 0x0c086d24 */
if(!s->budget--) { s->failed_pc=0x0c086d24u; return 0; }
r[6]+=r[3];
goto P_0c086d26;
P_0c086d26: /* original f28d, guest PC 0x0c086d26 */
if(!s->budget--) { s->failed_pc=0x0c086d26u; return 0; }
fr[2]=0;
goto P_0c086d28;
P_0c086d28: /* original 6063, guest PC 0x0c086d28 */
if(!s->budget--) { s->failed_pc=0x0c086d28u; return 0; }
r[0]=r[6];
goto P_0c086d2a;
P_0c086d2a: /* original 4008, guest PC 0x0c086d2a */
if(!s->budget--) { s->failed_pc=0x0c086d2au; return 0; }
r[0]<<=2;
goto P_0c086d2c;
P_0c086d2c: /* original 375c, guest PC 0x0c086d2c */
if(!s->budget--) { s->failed_pc=0x0c086d2cu; return 0; }
r[7]+=r[5];
goto P_0c086d2e;
P_0c086d2e: /* original f976, guest PC 0x0c086d2e */
if(!s->budget--) { s->failed_pc=0x0c086d2eu; return 0; }
vf3_matrix_load(s,ram,9,r[7]+r[0]);
goto P_0c086d30;
P_0c086d30: /* original 6063, guest PC 0x0c086d30 */
if(!s->budget--) { s->failed_pc=0x0c086d30u; return 0; }
r[0]=r[6];
goto P_0c086d32;
P_0c086d32: /* original 7001, guest PC 0x0c086d32 */
if(!s->budget--) { s->failed_pc=0x0c086d32u; return 0; }
r[0]+=0x00000001u;
goto P_0c086d34;
P_0c086d34: /* original f79c, guest PC 0x0c086d34 */
if(!s->budget--) { s->failed_pc=0x0c086d34u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c086d36;
P_0c086d36: /* original f741, guest PC 0x0c086d36 */
if(!s->budget--) { s->failed_pc=0x0c086d36u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'-');
goto P_0c086d38;
P_0c086d38: /* original 4008, guest PC 0x0c086d38 */
if(!s->budget--) { s->failed_pc=0x0c086d38u; return 0; }
r[0]<<=2;
goto P_0c086d3a;
P_0c086d3a: /* original f076, guest PC 0x0c086d3a */
if(!s->budget--) { s->failed_pc=0x0c086d3au; return 0; }
vf3_matrix_load(s,ram,0,r[7]+r[0]);
goto P_0c086d3c;
P_0c086d3c: /* original 6063, guest PC 0x0c086d3c */
if(!s->budget--) { s->failed_pc=0x0c086d3cu; return 0; }
r[0]=r[6];
goto P_0c086d3e;
P_0c086d3e: /* original 7002, guest PC 0x0c086d3e */
if(!s->budget--) { s->failed_pc=0x0c086d3eu; return 0; }
r[0]+=0x00000002u;
goto P_0c086d40;
P_0c086d40: /* original 4008, guest PC 0x0c086d40 */
if(!s->budget--) { s->failed_pc=0x0c086d40u; return 0; }
r[0]<<=2;
goto P_0c086d42;
P_0c086d42: /* original f275, guest PC 0x0c086d42 */
if(!s->budget--) { s->failed_pc=0x0c086d42u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[7]))!=0);
goto P_0c086d44;
P_0c086d44: /* original f376, guest PC 0x0c086d44 */
if(!s->budget--) { s->failed_pc=0x0c086d44u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c086d46;
P_0c086d46: /* original f83c, guest PC 0x0c086d46 */
if(!s->budget--) { s->failed_pc=0x0c086d46u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c086d48;
P_0c086d48: /* original 8d2d, guest PC 0x0c086d48 */
if(!s->budget--) { s->failed_pc=0x0c086d48u; return 0; }
cond=r[17]&1u;
fr[8]^=0x80000000u;
if(cond) { goto P_0c086da6; }
goto P_0c086d4c;
P_0c086d4a: /* original f84d, guest PC 0x0c086d4a */
if(!s->budget--) { s->failed_pc=0x0c086d4au; return 0; }
fr[8]^=0x80000000u;
goto P_0c086d4c;
P_0c086d4c: /* original f68c, guest PC 0x0c086d4c */
if(!s->budget--) { s->failed_pc=0x0c086d4cu; return 0; }
vf3_matrix_move(s,6,8);
goto P_0c086d4e;
P_0c086d4e: /* original f651, guest PC 0x0c086d4e */
if(!s->budget--) { s->failed_pc=0x0c086d4eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'-');
goto P_0c086d50;
P_0c086d50: /* original f38d, guest PC 0x0c086d50 */
if(!s->budget--) { s->failed_pc=0x0c086d50u; return 0; }
fr[3]=0;
goto P_0c086d52;
P_0c086d52: /* original f365, guest PC 0x0c086d52 */
if(!s->budget--) { s->failed_pc=0x0c086d52u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c086d54;
P_0c086d54: /* original 8927, guest PC 0x0c086d54 */
if(!s->budget--) { s->failed_pc=0x0c086d54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086da6; }
goto P_0c086d56;
P_0c086d56: /* original fa75, guest PC 0x0c086d56 */
if(!s->budget--) { s->failed_pc=0x0c086d56u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[7]))!=0);
goto P_0c086d58;
P_0c086d58: /* original 8b25, guest PC 0x0c086d58 */
if(!s->budget--) { s->failed_pc=0x0c086d58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086da6; }
goto P_0c086d5a;
P_0c086d5a: /* original fa65, guest PC 0x0c086d5a */
if(!s->budget--) { s->failed_pc=0x0c086d5au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[6]))!=0);
goto P_0c086d5c;
P_0c086d5c: /* original 8b23, guest PC 0x0c086d5c */
if(!s->budget--) { s->failed_pc=0x0c086d5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086da6; }
goto P_0c086d5e;
P_0c086d5e: /* original f6b2, guest PC 0x0c086d5e */
if(!s->budget--) { s->failed_pc=0x0c086d5eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c086d60;
P_0c086d60: /* original 9362, guest PC 0x0c086d60 */
if(!s->budget--) { s->failed_pc=0x0c086d60u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e28u,2);
goto P_0c086d62;
P_0c086d62: /* original f7b2, guest PC 0x0c086d62 */
if(!s->budget--) { s->failed_pc=0x0c086d62u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c086d64;
P_0c086d64: /* original 4d08, guest PC 0x0c086d64 */
if(!s->budget--) { s->failed_pc=0x0c086d64u; return 0; }
r[13]<<=2;
goto P_0c086d66;
P_0c086d66: /* original 335c, guest PC 0x0c086d66 */
if(!s->budget--) { s->failed_pc=0x0c086d66u; return 0; }
r[3]+=r[5];
goto P_0c086d68;
P_0c086d68: /* original 975f, guest PC 0x0c086d68 */
if(!s->budget--) { s->failed_pc=0x0c086d68u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e2au,2);
goto P_0c086d6a;
P_0c086d6a: /* original 3d3c, guest PC 0x0c086d6a */
if(!s->budget--) { s->failed_pc=0x0c086d6au; return 0; }
r[13]+=r[3];
goto P_0c086d6c;
P_0c086d6c: /* original f63d, guest PC 0x0c086d6c */
if(!s->budget--) { s->failed_pc=0x0c086d6cu; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c086d6e;
P_0c086d6e: /* original f6d8, guest PC 0x0c086d6e */
if(!s->budget--) { s->failed_pc=0x0c086d6eu; return 0; }
vf3_matrix_load(s,ram,6,r[13]);
goto P_0c086d70;
P_0c086d70: /* original 374c, guest PC 0x0c086d70 */
if(!s->budget--) { s->failed_pc=0x0c086d70u; return 0; }
r[7]+=r[4];
goto P_0c086d72;
P_0c086d72: /* original 005a, guest PC 0x0c086d72 */
if(!s->budget--) { s->failed_pc=0x0c086d72u; return 0; }
r[0]=r[53];
goto P_0c086d74;
P_0c086d74: /* original f73d, guest PC 0x0c086d74 */
if(!s->budget--) { s->failed_pc=0x0c086d74u; return 0; }
r[53]=truncate_float(fr[7]);
goto P_0c086d76;
P_0c086d76: /* original 6d03, guest PC 0x0c086d76 */
if(!s->budget--) { s->failed_pc=0x0c086d76u; return 0; }
r[13]=r[0];
goto P_0c086d78;
P_0c086d78: /* original 4018, guest PC 0x0c086d78 */
if(!s->budget--) { s->failed_pc=0x0c086d78u; return 0; }
r[0]<<=8;
goto P_0c086d7a;
P_0c086d7a: /* original 065a, guest PC 0x0c086d7a */
if(!s->budget--) { s->failed_pc=0x0c086d7au; return 0; }
r[6]=r[53];
goto P_0c086d7c;
P_0c086d7c: /* original 4d08, guest PC 0x0c086d7c */
if(!s->budget--) { s->failed_pc=0x0c086d7cu; return 0; }
r[13]<<=2;
goto P_0c086d7e;
P_0c086d7e: /* original 4d08, guest PC 0x0c086d7e */
if(!s->budget--) { s->failed_pc=0x0c086d7eu; return 0; }
r[13]<<=2;
goto P_0c086d80;
P_0c086d80: /* original 6163, guest PC 0x0c086d80 */
if(!s->budget--) { s->failed_pc=0x0c086d80u; return 0; }
r[1]=r[6];
goto P_0c086d82;
P_0c086d82: /* original 4608, guest PC 0x0c086d82 */
if(!s->budget--) { s->failed_pc=0x0c086d82u; return 0; }
r[6]<<=2;
goto P_0c086d84;
P_0c086d84: /* original 4608, guest PC 0x0c086d84 */
if(!s->budget--) { s->failed_pc=0x0c086d84u; return 0; }
r[6]<<=2;
goto P_0c086d86;
P_0c086d86: /* original 360c, guest PC 0x0c086d86 */
if(!s->budget--) { s->failed_pc=0x0c086d86u; return 0; }
r[6]+=r[0];
goto P_0c086d88;
P_0c086d88: /* original e004, guest PC 0x0c086d88 */
if(!s->budget--) { s->failed_pc=0x0c086d88u; return 0; }
r[0]=0x00000004u;
goto P_0c086d8a;
P_0c086d8a: /* original 376c, guest PC 0x0c086d8a */
if(!s->budget--) { s->failed_pc=0x0c086d8au; return 0; }
r[7]+=r[6];
goto P_0c086d8c;
P_0c086d8c: /* original f79a, guest PC 0x0c086d8c */
if(!s->budget--) { s->failed_pc=0x0c086d8cu; return 0; }
vf3_matrix_store(s,ram,9,r[7]);
goto P_0c086d8e;
P_0c086d8e: /* original f707, guest PC 0x0c086d8e */
if(!s->budget--) { s->failed_pc=0x0c086d8eu; return 0; }
vf3_matrix_store(s,ram,0,r[7]+r[0]);
goto P_0c086d90;
P_0c086d90: /* original e008, guest PC 0x0c086d90 */
if(!s->budget--) { s->failed_pc=0x0c086d90u; return 0; }
r[0]=0x00000008u;
goto P_0c086d92;
P_0c086d92: /* original f787, guest PC 0x0c086d92 */
if(!s->budget--) { s->failed_pc=0x0c086d92u; return 0; }
vf3_matrix_store(s,ram,8,r[7]+r[0]);
goto P_0c086d94;
P_0c086d94: /* original e00c, guest PC 0x0c086d94 */
if(!s->budget--) { s->failed_pc=0x0c086d94u; return 0; }
r[0]=0x0000000cu;
goto P_0c086d96;
P_0c086d96: /* original f767, guest PC 0x0c086d96 */
if(!s->budget--) { s->failed_pc=0x0c086d96u; return 0; }
vf3_matrix_store(s,ram,6,r[7]+r[0]);
goto P_0c086d98;
P_0c086d98: /* original 6043, guest PC 0x0c086d98 */
if(!s->budget--) { s->failed_pc=0x0c086d98u; return 0; }
r[0]=r[4];
goto P_0c086d9a;
P_0c086d9a: /* original 6713, guest PC 0x0c086d9a */
if(!s->budget--) { s->failed_pc=0x0c086d9au; return 0; }
r[7]=r[1];
goto P_0c086d9c;
P_0c086d9c: /* original 7020, guest PC 0x0c086d9c */
if(!s->budget--) { s->failed_pc=0x0c086d9cu; return 0; }
r[0]+=0x00000020u;
goto P_0c086d9e;
P_0c086d9e: /* original 37dc, guest PC 0x0c086d9e */
if(!s->budget--) { s->failed_pc=0x0c086d9eu; return 0; }
r[7]+=r[13];
goto P_0c086da0;
P_0c086da0: /* original 307c, guest PC 0x0c086da0 */
if(!s->budget--) { s->failed_pc=0x0c086da0u; return 0; }
r[0]+=r[7];
goto P_0c086da2;
P_0c086da2: /* original e601, guest PC 0x0c086da2 */
if(!s->budget--) { s->failed_pc=0x0c086da2u; return 0; }
r[6]=0x00000001u;
goto P_0c086da4;
P_0c086da4: /* original 2060, guest PC 0x0c086da4 */
if(!s->budget--) { s->failed_pc=0x0c086da4u; return 0; }
write(ram,r[0],r[6],1);
goto P_0c086da6;
P_0c086da6: /* original afb2, guest PC 0x0c086da6 */
if(!s->budget--) { s->failed_pc=0x0c086da6u; return 0; }
r[12]+=0x00000001u;
goto P_0c086d0e;
P_0c086da8: /* original 7c01, guest PC 0x0c086da8 */
if(!s->budget--) { s->failed_pc=0x0c086da8u; return 0; }
r[12]+=0x00000001u;
goto P_0c086daa;
P_0c086daa: /* original 6af6, guest PC 0x0c086daa */
if(!s->budget--) { s->failed_pc=0x0c086daau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c086dac;
P_0c086dac: /* original 6cf6, guest PC 0x0c086dac */
if(!s->budget--) { s->failed_pc=0x0c086dacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086dae;
P_0c086dae: /* original 000b, guest PC 0x0c086dae */
if(!s->budget--) { s->failed_pc=0x0c086daeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c086db0: /* original 6df6, guest PC 0x0c086db0 */
if(!s->budget--) { s->failed_pc=0x0c086db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086db2;
P_0c086db2: /* original fffb, guest PC 0x0c086db2 */
if(!s->budget--) { s->failed_pc=0x0c086db2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c086db4;
P_0c086db4: /* original e018, guest PC 0x0c086db4 */
if(!s->budget--) { s->failed_pc=0x0c086db4u; return 0; }
r[0]=0x00000018u;
goto P_0c086db6;
P_0c086db6: /* original ffeb, guest PC 0x0c086db6 */
if(!s->budget--) { s->failed_pc=0x0c086db6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c086db8;
P_0c086db8: /* original 4f22, guest PC 0x0c086db8 */
if(!s->budget--) { s->failed_pc=0x0c086db8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086dba;
P_0c086dba: /* original 7ff4, guest PC 0x0c086dba */
if(!s->budget--) { s->failed_pc=0x0c086dbau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c086dbc;
P_0c086dbc: /* original 2f42, guest PC 0x0c086dbc */
if(!s->budget--) { s->failed_pc=0x0c086dbcu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c086dbe;
P_0c086dbe: /* original 1f62, guest PC 0x0c086dbe */
if(!s->budget--) { s->failed_pc=0x0c086dbeu; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c086dc0;
P_0c086dc0: /* original 1f71, guest PC 0x0c086dc0 */
if(!s->budget--) { s->failed_pc=0x0c086dc0u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c086dc2;
P_0c086dc2: /* original ff56, guest PC 0x0c086dc2 */
if(!s->budget--) { s->failed_pc=0x0c086dc2u; return 0; }
vf3_matrix_load(s,ram,15,r[5]+r[0]);
goto P_0c086dc4;
P_0c086dc4: /* original e01c, guest PC 0x0c086dc4 */
if(!s->budget--) { s->failed_pc=0x0c086dc4u; return 0; }
r[0]=0x0000001cu;
goto P_0c086dc6;
P_0c086dc6: /* original fe56, guest PC 0x0c086dc6 */
if(!s->budget--) { s->failed_pc=0x0c086dc6u; return 0; }
vf3_matrix_load(s,ram,14,r[5]+r[0]);
goto P_0c086dc8;
P_0c086dc8: /* original 55f2, guest PC 0x0c086dc8 */
if(!s->budget--) { s->failed_pc=0x0c086dc8u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c086dca;
P_0c086dca: /* original f4fc, guest PC 0x0c086dca */
if(!s->budget--) { s->failed_pc=0x0c086dcau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c086dcc;
P_0c086dcc: /* original f5ec, guest PC 0x0c086dcc */
if(!s->budget--) { s->failed_pc=0x0c086dccu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c086dce;
P_0c086dce: /* original bf95, guest PC 0x0c086dce */
if(!s->budget--) { s->failed_pc=0x0c086dceu; return 0; }
target=0x0c086cfcu; r[16]=code_base|0x0c086dd2u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086dd2u) { target=s->pc; goto dispatch; }
goto P_0c086dd2;
P_0c086dd0: /* original 64f2, guest PC 0x0c086dd0 */
if(!s->budget--) { s->failed_pc=0x0c086dd0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c086dd2;
P_0c086dd2: /* original 55f1, guest PC 0x0c086dd2 */
if(!s->budget--) { s->failed_pc=0x0c086dd2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c086dd4;
P_0c086dd4: /* original 64f2, guest PC 0x0c086dd4 */
if(!s->budget--) { s->failed_pc=0x0c086dd4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c086dd6;
P_0c086dd6: /* original 7f0c, guest PC 0x0c086dd6 */
if(!s->budget--) { s->failed_pc=0x0c086dd6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c086dd8;
P_0c086dd8: /* original 4f26, guest PC 0x0c086dd8 */
if(!s->budget--) { s->failed_pc=0x0c086dd8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086dda;
P_0c086dda: /* original f5ec, guest PC 0x0c086dda */
if(!s->budget--) { s->failed_pc=0x0c086ddau; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c086ddc;
P_0c086ddc: /* original f4fc, guest PC 0x0c086ddc */
if(!s->budget--) { s->failed_pc=0x0c086ddcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c086dde;
P_0c086dde: /* original fef9, guest PC 0x0c086dde */
if(!s->budget--) { s->failed_pc=0x0c086ddeu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086de0;
P_0c086de0: /* original af8c, guest PC 0x0c086de0 */
if(!s->budget--) { s->failed_pc=0x0c086de0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cfc;
P_0c086de2: /* original fff9, guest PC 0x0c086de2 */
if(!s->budget--) { s->failed_pc=0x0c086de2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086de4;
P_0c086de4: /* original d717, guest PC 0x0c086de4 */
if(!s->budget--) { s->failed_pc=0x0c086de4u; return 0; }
r[7]=read(ram,0x0c086e44u,4);
goto P_0c086de6;
P_0c086de6: /* original e048, guest PC 0x0c086de6 */
if(!s->budget--) { s->failed_pc=0x0c086de6u; return 0; }
r[0]=0x00000048u;
goto P_0c086de8;
P_0c086de8: /* original d317, guest PC 0x0c086de8 */
if(!s->budget--) { s->failed_pc=0x0c086de8u; return 0; }
r[3]=read(ram,0x0c086e48u,4);
goto P_0c086dea;
P_0c086dea: /* original 5674, guest PC 0x0c086dea */
if(!s->budget--) { s->failed_pc=0x0c086deau; return 0; }
r[6]=read(ram,r[7]+16,4);
goto P_0c086dec;
P_0c086dec: /* original 026e, guest PC 0x0c086dec */
if(!s->budget--) { s->failed_pc=0x0c086decu; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c086dee;
P_0c086dee: /* original 2238, guest PC 0x0c086dee */
if(!s->budget--) { s->failed_pc=0x0c086deeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c086df0;
P_0c086df0: /* original 8d03, guest PC 0x0c086df0 */
if(!s->budget--) { s->failed_pc=0x0c086df0u; return 0; }
cond=r[17]&1u;
r[7]=read(ram,r[7]+20,4);
if(cond) { goto P_0c086dfa; }
goto P_0c086df4;
P_0c086df2: /* original 5775, guest PC 0x0c086df2 */
if(!s->budget--) { s->failed_pc=0x0c086df2u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c086df4;
P_0c086df4: /* original 2472, guest PC 0x0c086df4 */
if(!s->budget--) { s->failed_pc=0x0c086df4u; return 0; }
write(ram,r[4],r[7],4);
goto P_0c086df6;
P_0c086df6: /* original a002, guest PC 0x0c086df6 */
if(!s->budget--) { s->failed_pc=0x0c086df6u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c086dfe;
P_0c086df8: /* original 2562, guest PC 0x0c086df8 */
if(!s->budget--) { s->failed_pc=0x0c086df8u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c086dfa;
P_0c086dfa: /* original 2462, guest PC 0x0c086dfa */
if(!s->budget--) { s->failed_pc=0x0c086dfau; return 0; }
write(ram,r[4],r[6],4);
goto P_0c086dfc;
P_0c086dfc: /* original 2572, guest PC 0x0c086dfc */
if(!s->budget--) { s->failed_pc=0x0c086dfcu; return 0; }
write(ram,r[5],r[7],4);
goto P_0c086dfe;
P_0c086dfe: /* original 000b, guest PC 0x0c086dfe */
if(!s->budget--) { s->failed_pc=0x0c086dfeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c086e00: /* original 0009, guest PC 0x0c086e00 */
if(!s->budget--) { s->failed_pc=0x0c086e00u; return 0; }
goto P_0c086e02;
P_0c086e02: /* original 2fe6, guest PC 0x0c086e02 */
if(!s->budget--) { s->failed_pc=0x0c086e02u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e04;
P_0c086e04: /* original 6543, guest PC 0x0c086e04 */
if(!s->budget--) { s->failed_pc=0x0c086e04u; return 0; }
r[5]=r[4];
goto P_0c086e06;
P_0c086e06: /* original 2fd6, guest PC 0x0c086e06 */
if(!s->budget--) { s->failed_pc=0x0c086e06u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e08;
P_0c086e08: /* original 7520, guest PC 0x0c086e08 */
if(!s->budget--) { s->failed_pc=0x0c086e08u; return 0; }
r[5]+=0x00000020u;
goto P_0c086e0a;
P_0c086e0a: /* original 960e, guest PC 0x0c086e0a */
if(!s->budget--) { s->failed_pc=0x0c086e0au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e2au,2);
goto P_0c086e0c;
P_0c086e0c: /* original 9010, guest PC 0x0c086e0c */
if(!s->budget--) { s->failed_pc=0x0c086e0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e30u,2);
goto P_0c086e0e;
P_0c086e0e: /* original 9e0d, guest PC 0x0c086e0e */
if(!s->budget--) { s->failed_pc=0x0c086e0eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e2cu,2);
goto P_0c086e10;
P_0c086e10: /* original 364c, guest PC 0x0c086e10 */
if(!s->budget--) { s->failed_pc=0x0c086e10u; return 0; }
r[6]+=r[4];
goto P_0c086e12;
P_0c086e12: /* original 9d0c, guest PC 0x0c086e12 */
if(!s->budget--) { s->failed_pc=0x0c086e12u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e2eu,2);
goto P_0c086e14;
P_0c086e14: /* original 6103, guest PC 0x0c086e14 */
if(!s->budget--) { s->failed_pc=0x0c086e14u; return 0; }
r[1]=r[0];
goto P_0c086e16;
P_0c086e16: /* original e400, guest PC 0x0c086e16 */
if(!s->budget--) { s->failed_pc=0x0c086e16u; return 0; }
r[4]=0x00000000u;
goto P_0c086e18;
P_0c086e18: /* original f48d, guest PC 0x0c086e18 */
if(!s->budget--) { s->failed_pc=0x0c086e18u; return 0; }
fr[4]=0;
goto P_0c086e1a;
P_0c086e1a: /* original 316c, guest PC 0x0c086e1a */
if(!s->budget--) { s->failed_pc=0x0c086e1au; return 0; }
r[1]+=r[6];
goto P_0c086e1c;
P_0c086e1c: /* original 6763, guest PC 0x0c086e1c */
if(!s->budget--) { s->failed_pc=0x0c086e1cu; return 0; }
r[7]=r[6];
goto P_0c086e1e;
P_0c086e1e: /* original 3d6c, guest PC 0x0c086e1e */
if(!s->budget--) { s->failed_pc=0x0c086e1eu; return 0; }
r[13]+=r[6];
goto P_0c086e20;
P_0c086e20: /* original 3e6c, guest PC 0x0c086e20 */
if(!s->budget--) { s->failed_pc=0x0c086e20u; return 0; }
r[14]+=r[6];
goto P_0c086e22;
P_0c086e22: /* original a024, guest PC 0x0c086e22 */
if(!s->budget--) { s->failed_pc=0x0c086e22u; return 0; }
r[6]=0x00000040u;
goto P_0c086e6e;
P_0c086e24: /* original e640, guest PC 0x0c086e24 */
if(!s->budget--) { s->failed_pc=0x0c086e24u; return 0; }
r[6]=0x00000040u;
return vf3_matrix_family(0x0c086e26u,s,ram);
P_0c086e4c: /* original 2540, guest PC 0x0c086e4c */
if(!s->budget--) { s->failed_pc=0x0c086e4cu; return 0; }
write(ram,r[5],r[4],1);
goto P_0c086e4e;
P_0c086e4e: /* original 7501, guest PC 0x0c086e4e */
if(!s->budget--) { s->failed_pc=0x0c086e4eu; return 0; }
r[5]+=0x00000001u;
goto P_0c086e50;
P_0c086e50: /* original 2540, guest PC 0x0c086e50 */
if(!s->budget--) { s->failed_pc=0x0c086e50u; return 0; }
write(ram,r[5],r[4],1);
goto P_0c086e52;
P_0c086e52: /* original 7501, guest PC 0x0c086e52 */
if(!s->budget--) { s->failed_pc=0x0c086e52u; return 0; }
r[5]+=0x00000001u;
goto P_0c086e54;
P_0c086e54: /* original 2540, guest PC 0x0c086e54 */
if(!s->budget--) { s->failed_pc=0x0c086e54u; return 0; }
write(ram,r[5],r[4],1);
goto P_0c086e56;
P_0c086e56: /* original 7501, guest PC 0x0c086e56 */
if(!s->budget--) { s->failed_pc=0x0c086e56u; return 0; }
r[5]+=0x00000001u;
goto P_0c086e58;
P_0c086e58: /* original 2540, guest PC 0x0c086e58 */
if(!s->budget--) { s->failed_pc=0x0c086e58u; return 0; }
write(ram,r[5],r[4],1);
goto P_0c086e5a;
P_0c086e5a: /* original 76ff, guest PC 0x0c086e5a */
if(!s->budget--) { s->failed_pc=0x0c086e5au; return 0; }
r[6]+=0xffffffffu;
goto P_0c086e5c;
P_0c086e5c: /* original f74a, guest PC 0x0c086e5c */
if(!s->budget--) { s->failed_pc=0x0c086e5cu; return 0; }
vf3_matrix_store(s,ram,4,r[7]);
goto P_0c086e5e;
P_0c086e5e: /* original 7501, guest PC 0x0c086e5e */
if(!s->budget--) { s->failed_pc=0x0c086e5eu; return 0; }
r[5]+=0x00000001u;
goto P_0c086e60;
P_0c086e60: /* original fe4a, guest PC 0x0c086e60 */
if(!s->budget--) { s->failed_pc=0x0c086e60u; return 0; }
vf3_matrix_store(s,ram,4,r[14]);
goto P_0c086e62;
P_0c086e62: /* original 7e04, guest PC 0x0c086e62 */
if(!s->budget--) { s->failed_pc=0x0c086e62u; return 0; }
r[14]+=0x00000004u;
goto P_0c086e64;
P_0c086e64: /* original fd4a, guest PC 0x0c086e64 */
if(!s->budget--) { s->failed_pc=0x0c086e64u; return 0; }
vf3_matrix_store(s,ram,4,r[13]);
goto P_0c086e66;
P_0c086e66: /* original 7704, guest PC 0x0c086e66 */
if(!s->budget--) { s->failed_pc=0x0c086e66u; return 0; }
r[7]+=0x00000004u;
goto P_0c086e68;
P_0c086e68: /* original f14a, guest PC 0x0c086e68 */
if(!s->budget--) { s->failed_pc=0x0c086e68u; return 0; }
vf3_matrix_store(s,ram,4,r[1]);
goto P_0c086e6a;
P_0c086e6a: /* original 7104, guest PC 0x0c086e6a */
if(!s->budget--) { s->failed_pc=0x0c086e6au; return 0; }
r[1]+=0x00000004u;
goto P_0c086e6c;
P_0c086e6c: /* original 7d04, guest PC 0x0c086e6c */
if(!s->budget--) { s->failed_pc=0x0c086e6cu; return 0; }
r[13]+=0x00000004u;
goto P_0c086e6e;
P_0c086e6e: /* original 2668, guest PC 0x0c086e6e */
if(!s->budget--) { s->failed_pc=0x0c086e6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c086e70;
P_0c086e70: /* original 8bec, guest PC 0x0c086e70 */
if(!s->budget--) { s->failed_pc=0x0c086e70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086e4c; }
goto P_0c086e72;
P_0c086e72: /* original 6df6, guest PC 0x0c086e72 */
if(!s->budget--) { s->failed_pc=0x0c086e72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086e74;
P_0c086e74: /* original 000b, guest PC 0x0c086e74 */
if(!s->budget--) { s->failed_pc=0x0c086e74u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086e76: /* original 6ef6, guest PC 0x0c086e76 */
if(!s->budget--) { s->failed_pc=0x0c086e76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c086e78;
P_0c086e78: /* original 2fe6, guest PC 0x0c086e78 */
if(!s->budget--) { s->failed_pc=0x0c086e78u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e7a;
P_0c086e7a: /* original 2fd6, guest PC 0x0c086e7a */
if(!s->budget--) { s->failed_pc=0x0c086e7au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e7c;
P_0c086e7c: /* original 6d43, guest PC 0x0c086e7c */
if(!s->budget--) { s->failed_pc=0x0c086e7cu; return 0; }
r[13]=r[4];
goto P_0c086e7e;
P_0c086e7e: /* original 2fc6, guest PC 0x0c086e7e */
if(!s->budget--) { s->failed_pc=0x0c086e7eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e80;
P_0c086e80: /* original 60d2, guest PC 0x0c086e80 */
if(!s->budget--) { s->failed_pc=0x0c086e80u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c086e82;
P_0c086e82: /* original 4f22, guest PC 0x0c086e82 */
if(!s->budget--) { s->failed_pc=0x0c086e82u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086e84;
P_0c086e84: /* original 88ff, guest PC 0x0c086e84 */
if(!s->budget--) { s->failed_pc=0x0c086e84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086e86;
P_0c086e86: /* original 8d09, guest PC 0x0c086e86 */
if(!s->budget--) { s->failed_pc=0x0c086e86u; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(cond) { goto P_0c086e9c; }
goto P_0c086e8a;
P_0c086e88: /* original 6e03, guest PC 0x0c086e88 */
if(!s->budget--) { s->failed_pc=0x0c086e88u; return 0; }
r[14]=r[0];
goto P_0c086e8a;
P_0c086e8a: /* original dc39, guest PC 0x0c086e8a */
if(!s->budget--) { s->failed_pc=0x0c086e8au; return 0; }
r[12]=read(ram,0x0c086f70u,4);
goto P_0c086e8c;
P_0c086e8c: /* original 65e3, guest PC 0x0c086e8c */
if(!s->budget--) { s->failed_pc=0x0c086e8cu; return 0; }
r[5]=r[14];
goto P_0c086e8e;
P_0c086e8e: /* original 4c0b, guest PC 0x0c086e8e */
if(!s->budget--) { s->failed_pc=0x0c086e8eu; return 0; }
target=r[12];
r[16]=code_base|0x0c086e92u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086e92u) { target=s->pc; goto dispatch; }
goto P_0c086e92;
P_0c086e90: /* original 64d3, guest PC 0x0c086e90 */
if(!s->budget--) { s->failed_pc=0x0c086e90u; return 0; }
r[4]=r[13];
goto P_0c086e92;
P_0c086e92: /* original 6403, guest PC 0x0c086e92 */
if(!s->budget--) { s->failed_pc=0x0c086e92u; return 0; }
r[4]=r[0];
goto P_0c086e94;
P_0c086e94: /* original 6042, guest PC 0x0c086e94 */
if(!s->budget--) { s->failed_pc=0x0c086e94u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c086e96;
P_0c086e96: /* original 88ff, guest PC 0x0c086e96 */
if(!s->budget--) { s->failed_pc=0x0c086e96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086e98;
P_0c086e98: /* original 8ff8, guest PC 0x0c086e98 */
if(!s->budget--) { s->failed_pc=0x0c086e98u; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(!cond) { goto P_0c086e8c; }
goto P_0c086e9c;
P_0c086e9a: /* original 6e03, guest PC 0x0c086e9a */
if(!s->budget--) { s->failed_pc=0x0c086e9au; return 0; }
r[14]=r[0];
goto P_0c086e9c;
P_0c086e9c: /* original 4f26, guest PC 0x0c086e9c */
if(!s->budget--) { s->failed_pc=0x0c086e9cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086e9e;
P_0c086e9e: /* original 6cf6, guest PC 0x0c086e9e */
if(!s->budget--) { s->failed_pc=0x0c086e9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086ea0;
P_0c086ea0: /* original 6df6, guest PC 0x0c086ea0 */
if(!s->budget--) { s->failed_pc=0x0c086ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086ea2;
P_0c086ea2: /* original 000b, guest PC 0x0c086ea2 */
if(!s->budget--) { s->failed_pc=0x0c086ea2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086ea4: /* original 6ef6, guest PC 0x0c086ea4 */
if(!s->budget--) { s->failed_pc=0x0c086ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c086ea6;
P_0c086ea6: /* original c733, guest PC 0x0c086ea6 */
if(!s->budget--) { s->failed_pc=0x0c086ea6u; return 0; }
r[0]=0x0c086f74u;
goto P_0c086ea8;
P_0c086ea8: /* original 2fe6, guest PC 0x0c086ea8 */
if(!s->budget--) { s->failed_pc=0x0c086ea8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086eaa;
P_0c086eaa: /* original f708, guest PC 0x0c086eaa */
if(!s->budget--) { s->failed_pc=0x0c086eaau; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c086eac;
P_0c086eac: /* original c732, guest PC 0x0c086eac */
if(!s->budget--) { s->failed_pc=0x0c086eacu; return 0; }
r[0]=0x0c086f78u;
goto P_0c086eae;
P_0c086eae: /* original f808, guest PC 0x0c086eae */
if(!s->budget--) { s->failed_pc=0x0c086eaeu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c086eb0;
P_0c086eb0: /* original e00c, guest PC 0x0c086eb0 */
if(!s->budget--) { s->failed_pc=0x0c086eb0u; return 0; }
r[0]=0x0000000cu;
goto P_0c086eb2;
P_0c086eb2: /* original 6e63, guest PC 0x0c086eb2 */
if(!s->budget--) { s->failed_pc=0x0c086eb2u; return 0; }
r[14]=r[6];
goto P_0c086eb4;
P_0c086eb4: /* original f6e6, guest PC 0x0c086eb4 */
if(!s->budget--) { s->failed_pc=0x0c086eb4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c086eb6;
P_0c086eb6: /* original f34c, guest PC 0x0c086eb6 */
if(!s->budget--) { s->failed_pc=0x0c086eb6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c086eb8;
P_0c086eb8: /* original e014, guest PC 0x0c086eb8 */
if(!s->budget--) { s->failed_pc=0x0c086eb8u; return 0; }
r[0]=0x00000014u;
goto P_0c086eba;
P_0c086eba: /* original f46c, guest PC 0x0c086eba */
if(!s->budget--) { s->failed_pc=0x0c086ebau; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c086ebc;
P_0c086ebc: /* original f431, guest PC 0x0c086ebc */
if(!s->budget--) { s->failed_pc=0x0c086ebcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c086ebe;
P_0c086ebe: /* original fae6, guest PC 0x0c086ebe */
if(!s->budget--) { s->failed_pc=0x0c086ebeu; return 0; }
vf3_matrix_load(s,ram,10,r[14]+r[0]);
goto P_0c086ec0;
P_0c086ec0: /* original e310, guest PC 0x0c086ec0 */
if(!s->budget--) { s->failed_pc=0x0c086ec0u; return 0; }
r[3]=0x00000010u;
goto P_0c086ec2;
P_0c086ec2: /* original f35c, guest PC 0x0c086ec2 */
if(!s->budget--) { s->failed_pc=0x0c086ec2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c086ec4;
P_0c086ec4: /* original 7ffc, guest PC 0x0c086ec4 */
if(!s->budget--) { s->failed_pc=0x0c086ec4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c086ec6;
P_0c086ec6: /* original f5ac, guest PC 0x0c086ec6 */
if(!s->budget--) { s->failed_pc=0x0c086ec6u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c086ec8;
P_0c086ec8: /* original f531, guest PC 0x0c086ec8 */
if(!s->budget--) { s->failed_pc=0x0c086ec8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c086eca;
P_0c086eca: /* original f472, guest PC 0x0c086eca */
if(!s->budget--) { s->failed_pc=0x0c086ecau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c086ecc;
P_0c086ecc: /* original f572, guest PC 0x0c086ecc */
if(!s->budget--) { s->failed_pc=0x0c086eccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c086ece;
P_0c086ece: /* original f53d, guest PC 0x0c086ece */
if(!s->budget--) { s->failed_pc=0x0c086eceu; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c086ed0;
P_0c086ed0: /* original 075a, guest PC 0x0c086ed0 */
if(!s->budget--) { s->failed_pc=0x0c086ed0u; return 0; }
r[7]=r[53];
goto P_0c086ed2;
P_0c086ed2: /* original f43d, guest PC 0x0c086ed2 */
if(!s->budget--) { s->failed_pc=0x0c086ed2u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c086ed4;
P_0c086ed4: /* original 3737, guest PC 0x0c086ed4 */
if(!s->budget--) { s->failed_pc=0x0c086ed4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[3])!=0);
goto P_0c086ed6;
P_0c086ed6: /* original 8d46, guest PC 0x0c086ed6 */
if(!s->budget--) { s->failed_pc=0x0c086ed6u; return 0; }
cond=r[17]&1u;
r[6]=r[53];
if(cond) { goto P_0c086f66; }
goto P_0c086eda;
P_0c086ed8: /* original 065a, guest PC 0x0c086ed8 */
if(!s->budget--) { s->failed_pc=0x0c086ed8u; return 0; }
r[6]=r[53];
goto P_0c086eda;
P_0c086eda: /* original 3637, guest PC 0x0c086eda */
if(!s->budget--) { s->failed_pc=0x0c086edau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c086edc;
P_0c086edc: /* original 8943, guest PC 0x0c086edc */
if(!s->budget--) { s->failed_pc=0x0c086edcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086f66; }
goto P_0c086ede;
P_0c086ede: /* original 6173, guest PC 0x0c086ede */
if(!s->budget--) { s->failed_pc=0x0c086edeu; return 0; }
r[1]=r[7];
goto P_0c086ee0;
P_0c086ee0: /* original 4108, guest PC 0x0c086ee0 */
if(!s->budget--) { s->failed_pc=0x0c086ee0u; return 0; }
r[1]<<=2;
goto P_0c086ee2;
P_0c086ee2: /* original 6343, guest PC 0x0c086ee2 */
if(!s->budget--) { s->failed_pc=0x0c086ee2u; return 0; }
r[3]=r[4];
goto P_0c086ee4;
P_0c086ee4: /* original 4108, guest PC 0x0c086ee4 */
if(!s->budget--) { s->failed_pc=0x0c086ee4u; return 0; }
r[1]<<=2;
goto P_0c086ee6;
P_0c086ee6: /* original 7320, guest PC 0x0c086ee6 */
if(!s->budget--) { s->failed_pc=0x0c086ee6u; return 0; }
r[3]+=0x00000020u;
goto P_0c086ee8;
P_0c086ee8: /* original 316c, guest PC 0x0c086ee8 */
if(!s->budget--) { s->failed_pc=0x0c086ee8u; return 0; }
r[1]+=r[6];
goto P_0c086eea;
P_0c086eea: /* original 313c, guest PC 0x0c086eea */
if(!s->budget--) { s->failed_pc=0x0c086eeau; return 0; }
r[1]+=r[3];
goto P_0c086eec;
P_0c086eec: /* original 6210, guest PC 0x0c086eec */
if(!s->budget--) { s->failed_pc=0x0c086eecu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c086eee;
P_0c086eee: /* original 2228, guest PC 0x0c086eee */
if(!s->budget--) { s->failed_pc=0x0c086eeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c086ef0;
P_0c086ef0: /* original 8d39, guest PC 0x0c086ef0 */
if(!s->budget--) { s->failed_pc=0x0c086ef0u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(cond) { goto P_0c086f66; }
goto P_0c086ef4;
P_0c086ef2: /* original 2f22, guest PC 0x0c086ef2 */
if(!s->budget--) { s->failed_pc=0x0c086ef2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c086ef4;
P_0c086ef4: /* original 923a, guest PC 0x0c086ef4 */
if(!s->budget--) { s->failed_pc=0x0c086ef4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086f6cu,2);
goto P_0c086ef6;
P_0c086ef6: /* original 4608, guest PC 0x0c086ef6 */
if(!s->budget--) { s->failed_pc=0x0c086ef6u; return 0; }
r[6]<<=2;
goto P_0c086ef8;
P_0c086ef8: /* original 4718, guest PC 0x0c086ef8 */
if(!s->budget--) { s->failed_pc=0x0c086ef8u; return 0; }
r[7]<<=8;
goto P_0c086efa;
P_0c086efa: /* original 4608, guest PC 0x0c086efa */
if(!s->budget--) { s->failed_pc=0x0c086efau; return 0; }
r[6]<<=2;
goto P_0c086efc;
P_0c086efc: /* original 367c, guest PC 0x0c086efc */
if(!s->budget--) { s->failed_pc=0x0c086efcu; return 0; }
r[6]+=r[7];
goto P_0c086efe;
P_0c086efe: /* original 342c, guest PC 0x0c086efe */
if(!s->budget--) { s->failed_pc=0x0c086efeu; return 0; }
r[4]+=r[2];
goto P_0c086f00;
P_0c086f00: /* original e00c, guest PC 0x0c086f00 */
if(!s->budget--) { s->failed_pc=0x0c086f00u; return 0; }
r[0]=0x0000000cu;
goto P_0c086f02;
P_0c086f02: /* original 346c, guest PC 0x0c086f02 */
if(!s->budget--) { s->failed_pc=0x0c086f02u; return 0; }
r[4]+=r[6];
goto P_0c086f04;
P_0c086f04: /* original f946, guest PC 0x0c086f04 */
if(!s->budget--) { s->failed_pc=0x0c086f04u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c086f06;
P_0c086f06: /* original e004, guest PC 0x0c086f06 */
if(!s->budget--) { s->failed_pc=0x0c086f06u; return 0; }
r[0]=0x00000004u;
goto P_0c086f08;
P_0c086f08: /* original f346, guest PC 0x0c086f08 */
if(!s->budget--) { s->failed_pc=0x0c086f08u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c086f0a;
P_0c086f0a: /* original e010, guest PC 0x0c086f0a */
if(!s->budget--) { s->failed_pc=0x0c086f0au; return 0; }
r[0]=0x00000010u;
goto P_0c086f0c;
P_0c086f0c: /* original f49c, guest PC 0x0c086f0c */
if(!s->budget--) { s->failed_pc=0x0c086f0cu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c086f0e;
P_0c086f0e: /* original f430, guest PC 0x0c086f0e */
if(!s->budget--) { s->failed_pc=0x0c086f0eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c086f10;
P_0c086f10: /* original f5e6, guest PC 0x0c086f10 */
if(!s->budget--) { s->failed_pc=0x0c086f10u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c086f12;
P_0c086f12: /* original f545, guest PC 0x0c086f12 */
if(!s->budget--) { s->failed_pc=0x0c086f12u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c086f14;
P_0c086f14: /* original 8927, guest PC 0x0c086f14 */
if(!s->budget--) { s->failed_pc=0x0c086f14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086f66; }
goto P_0c086f16;
P_0c086f16: /* original fbe6, guest PC 0x0c086f16 */
if(!s->budget--) { s->failed_pc=0x0c086f16u; return 0; }
vf3_matrix_load(s,ram,11,r[14]+r[0]);
goto P_0c086f18;
P_0c086f18: /* original e004, guest PC 0x0c086f18 */
if(!s->budget--) { s->failed_pc=0x0c086f18u; return 0; }
r[0]=0x00000004u;
goto P_0c086f1a;
P_0c086f1a: /* original f746, guest PC 0x0c086f1a */
if(!s->budget--) { s->failed_pc=0x0c086f1au; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c086f1c;
P_0c086f1c: /* original e008, guest PC 0x0c086f1c */
if(!s->budget--) { s->failed_pc=0x0c086f1cu; return 0; }
r[0]=0x00000008u;
goto P_0c086f1e;
P_0c086f1e: /* original f548, guest PC 0x0c086f1e */
if(!s->budget--) { s->failed_pc=0x0c086f1eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c086f20;
P_0c086f20: /* original f7b1, guest PC 0x0c086f20 */
if(!s->budget--) { s->failed_pc=0x0c086f20u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'-');
goto P_0c086f22;
P_0c086f22: /* original f446, guest PC 0x0c086f22 */
if(!s->budget--) { s->failed_pc=0x0c086f22u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c086f24;
P_0c086f24: /* original f561, guest PC 0x0c086f24 */
if(!s->budget--) { s->failed_pc=0x0c086f24u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c086f26;
P_0c086f26: /* original f39c, guest PC 0x0c086f26 */
if(!s->budget--) { s->failed_pc=0x0c086f26u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c086f28;
P_0c086f28: /* original f4a1, guest PC 0x0c086f28 */
if(!s->budget--) { s->failed_pc=0x0c086f28u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'-');
goto P_0c086f2a;
P_0c086f2a: /* original f932, guest PC 0x0c086f2a */
if(!s->budget--) { s->failed_pc=0x0c086f2au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'*');
goto P_0c086f2c;
P_0c086f2c: /* original fa7c, guest PC 0x0c086f2c */
if(!s->budget--) { s->failed_pc=0x0c086f2cu; return 0; }
vf3_matrix_move(s,10,7);
goto P_0c086f2e;
P_0c086f2e: /* original fa72, guest PC 0x0c086f2e */
if(!s->budget--) { s->failed_pc=0x0c086f2eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'*');
goto P_0c086f30;
P_0c086f30: /* original f65c, guest PC 0x0c086f30 */
if(!s->budget--) { s->failed_pc=0x0c086f30u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c086f32;
P_0c086f32: /* original f652, guest PC 0x0c086f32 */
if(!s->budget--) { s->failed_pc=0x0c086f32u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c086f34;
P_0c086f34: /* original f74c, guest PC 0x0c086f34 */
if(!s->budget--) { s->failed_pc=0x0c086f34u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c086f36;
P_0c086f36: /* original f742, guest PC 0x0c086f36 */
if(!s->budget--) { s->failed_pc=0x0c086f36u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c086f38;
P_0c086f38: /* original f6a0, guest PC 0x0c086f38 */
if(!s->budget--) { s->failed_pc=0x0c086f38u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'+');
goto P_0c086f3a;
P_0c086f3a: /* original f670, guest PC 0x0c086f3a */
if(!s->budget--) { s->failed_pc=0x0c086f3au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c086f3c;
P_0c086f3c: /* original f695, guest PC 0x0c086f3c */
if(!s->budget--) { s->failed_pc=0x0c086f3cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[9]))!=0);
goto P_0c086f3e;
P_0c086f3e: /* original 8912, guest PC 0x0c086f3e */
if(!s->budget--) { s->failed_pc=0x0c086f3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086f66; }
goto P_0c086f40;
P_0c086f40: /* original f582, guest PC 0x0c086f40 */
if(!s->budget--) { s->failed_pc=0x0c086f40u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c086f42;
P_0c086f42: /* original e030, guest PC 0x0c086f42 */
if(!s->budget--) { s->failed_pc=0x0c086f42u; return 0; }
r[0]=0x00000030u;
goto P_0c086f44;
P_0c086f44: /* original f656, guest PC 0x0c086f44 */
if(!s->budget--) { s->failed_pc=0x0c086f44u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c086f46;
P_0c086f46: /* original e018, guest PC 0x0c086f46 */
if(!s->budget--) { s->failed_pc=0x0c086f46u; return 0; }
r[0]=0x00000018u;
goto P_0c086f48;
P_0c086f48: /* original f482, guest PC 0x0c086f48 */
if(!s->budget--) { s->failed_pc=0x0c086f48u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c086f4a;
P_0c086f4a: /* original e340, guest PC 0x0c086f4a */
if(!s->budget--) { s->failed_pc=0x0c086f4au; return 0; }
r[3]=0x00000040u;
goto P_0c086f4c;
P_0c086f4c: /* original 7f04, guest PC 0x0c086f4c */
if(!s->budget--) { s->failed_pc=0x0c086f4cu; return 0; }
r[15]+=0x00000004u;
goto P_0c086f4e;
P_0c086f4e: /* original 64e3, guest PC 0x0c086f4e */
if(!s->budget--) { s->failed_pc=0x0c086f4eu; return 0; }
r[4]=r[14];
goto P_0c086f50;
P_0c086f50: /* original fe57, guest PC 0x0c086f50 */
if(!s->budget--) { s->failed_pc=0x0c086f50u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c086f52;
P_0c086f52: /* original e01c, guest PC 0x0c086f52 */
if(!s->budget--) { s->failed_pc=0x0c086f52u; return 0; }
r[0]=0x0000001cu;
goto P_0c086f54;
P_0c086f54: /* original fe67, guest PC 0x0c086f54 */
if(!s->budget--) { s->failed_pc=0x0c086f54u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c086f56;
P_0c086f56: /* original e020, guest PC 0x0c086f56 */
if(!s->budget--) { s->failed_pc=0x0c086f56u; return 0; }
r[0]=0x00000020u;
goto P_0c086f58;
P_0c086f58: /* original fe47, guest PC 0x0c086f58 */
if(!s->budget--) { s->failed_pc=0x0c086f58u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c086f5a;
P_0c086f5a: /* original e026, guest PC 0x0c086f5a */
if(!s->budget--) { s->failed_pc=0x0c086f5au; return 0; }
r[0]=0x00000026u;
goto P_0c086f5c;
P_0c086f5c: /* original 0e34, guest PC 0x0c086f5c */
if(!s->budget--) { s->failed_pc=0x0c086f5cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c086f5e;
P_0c086f5e: /* original d307, guest PC 0x0c086f5e */
if(!s->budget--) { s->failed_pc=0x0c086f5eu; return 0; }
r[3]=read(ram,0x0c086f7cu,4);
goto P_0c086f60;
P_0c086f60: /* original 55ea, guest PC 0x0c086f60 */
if(!s->budget--) { s->failed_pc=0x0c086f60u; return 0; }
r[5]=read(ram,r[14]+40,4);
goto P_0c086f62;
P_0c086f62: /* original 432b, guest PC 0x0c086f62 */
if(!s->budget--) { s->failed_pc=0x0c086f62u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c086f64: /* original 6ef6, guest PC 0x0c086f64 */
if(!s->budget--) { s->failed_pc=0x0c086f64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c086f66;
P_0c086f66: /* original 7f04, guest PC 0x0c086f66 */
if(!s->budget--) { s->failed_pc=0x0c086f66u; return 0; }
r[15]+=0x00000004u;
goto P_0c086f68;
P_0c086f68: /* original 000b, guest PC 0x0c086f68 */
if(!s->budget--) { s->failed_pc=0x0c086f68u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086f6a: /* original 6ef6, guest PC 0x0c086f6a */
if(!s->budget--) { s->failed_pc=0x0c086f6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c086f6cu,s,ram);
P_0c086f80: /* original 2fe6, guest PC 0x0c086f80 */
if(!s->budget--) { s->failed_pc=0x0c086f80u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086f82;
P_0c086f82: /* original 2fd6, guest PC 0x0c086f82 */
if(!s->budget--) { s->failed_pc=0x0c086f82u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086f84;
P_0c086f84: /* original 6d53, guest PC 0x0c086f84 */
if(!s->budget--) { s->failed_pc=0x0c086f84u; return 0; }
r[13]=r[5];
goto P_0c086f86;
P_0c086f86: /* original 2fc6, guest PC 0x0c086f86 */
if(!s->budget--) { s->failed_pc=0x0c086f86u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086f88;
P_0c086f88: /* original fffb, guest PC 0x0c086f88 */
if(!s->budget--) { s->failed_pc=0x0c086f88u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c086f8a;
P_0c086f8a: /* original ffeb, guest PC 0x0c086f8a */
if(!s->budget--) { s->failed_pc=0x0c086f8au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c086f8c;
P_0c086f8c: /* original ffdb, guest PC 0x0c086f8c */
if(!s->budget--) { s->failed_pc=0x0c086f8cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c086f8e;
P_0c086f8e: /* original ffcb, guest PC 0x0c086f8e */
if(!s->budget--) { s->failed_pc=0x0c086f8eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c086f90;
P_0c086f90: /* original 4f22, guest PC 0x0c086f90 */
if(!s->budget--) { s->failed_pc=0x0c086f90u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086f92;
P_0c086f92: /* original 7ff8, guest PC 0x0c086f92 */
if(!s->budget--) { s->failed_pc=0x0c086f92u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c086f94;
P_0c086f94: /* original 2f42, guest PC 0x0c086f94 */
if(!s->budget--) { s->failed_pc=0x0c086f94u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c086f96;
P_0c086f96: /* original 60d2, guest PC 0x0c086f96 */
if(!s->budget--) { s->failed_pc=0x0c086f96u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c086f98;
P_0c086f98: /* original 88ff, guest PC 0x0c086f98 */
if(!s->budget--) { s->failed_pc=0x0c086f98u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086f9a;
P_0c086f9a: /* original 8d65, guest PC 0x0c086f9a */
if(!s->budget--) { s->failed_pc=0x0c086f9au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c087068; }
goto P_0c086f9e;
P_0c086f9c: /* original 6403, guest PC 0x0c086f9c */
if(!s->budget--) { s->failed_pc=0x0c086f9cu; return 0; }
r[4]=r[0];
goto P_0c086f9e;
P_0c086f9e: /* original c738, guest PC 0x0c086f9e */
if(!s->budget--) { s->failed_pc=0x0c086f9eu; return 0; }
r[0]=0x0c087080u;
goto P_0c086fa0;
P_0c086fa0: /* original fd08, guest PC 0x0c086fa0 */
if(!s->budget--) { s->failed_pc=0x0c086fa0u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c086fa2;
P_0c086fa2: /* original e018, guest PC 0x0c086fa2 */
if(!s->budget--) { s->failed_pc=0x0c086fa2u; return 0; }
r[0]=0x00000018u;
goto P_0c086fa4;
P_0c086fa4: /* original f3d6, guest PC 0x0c086fa4 */
if(!s->budget--) { s->failed_pc=0x0c086fa4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c086fa6;
P_0c086fa6: /* original e004, guest PC 0x0c086fa6 */
if(!s->budget--) { s->failed_pc=0x0c086fa6u; return 0; }
r[0]=0x00000004u;
goto P_0c086fa8;
P_0c086fa8: /* original ff37, guest PC 0x0c086fa8 */
if(!s->budget--) { s->failed_pc=0x0c086fa8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c086faa;
P_0c086faa: /* original e01c, guest PC 0x0c086faa */
if(!s->budget--) { s->failed_pc=0x0c086faau; return 0; }
r[0]=0x0000001cu;
goto P_0c086fac;
P_0c086fac: /* original fcd6, guest PC 0x0c086fac */
if(!s->budget--) { s->failed_pc=0x0c086facu; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c086fae;
P_0c086fae: /* original 6e43, guest PC 0x0c086fae */
if(!s->budget--) { s->failed_pc=0x0c086faeu; return 0; }
r[14]=r[4];
goto P_0c086fb0;
P_0c086fb0: /* original 84e8, guest PC 0x0c086fb0 */
if(!s->budget--) { s->failed_pc=0x0c086fb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c086fb2;
P_0c086fb2: /* original 88ff, guest PC 0x0c086fb2 */
if(!s->budget--) { s->failed_pc=0x0c086fb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086fb4;
P_0c086fb4: /* original 8b05, guest PC 0x0c086fb4 */
if(!s->budget--) { s->failed_pc=0x0c086fb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086fc2; }
goto P_0c086fb6;
P_0c086fb6: /* original dc33, guest PC 0x0c086fb6 */
if(!s->budget--) { s->failed_pc=0x0c086fb6u; return 0; }
r[12]=read(ram,0x0c087084u,4);
goto P_0c086fb8;
P_0c086fb8: /* original 65e3, guest PC 0x0c086fb8 */
if(!s->budget--) { s->failed_pc=0x0c086fb8u; return 0; }
r[5]=r[14];
goto P_0c086fba;
P_0c086fba: /* original 4c0b, guest PC 0x0c086fba */
if(!s->budget--) { s->failed_pc=0x0c086fbau; return 0; }
target=r[12];
r[16]=code_base|0x0c086fbeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086fbeu) { target=s->pc; goto dispatch; }
goto P_0c086fbe;
P_0c086fbc: /* original 64d3, guest PC 0x0c086fbc */
if(!s->budget--) { s->failed_pc=0x0c086fbcu; return 0; }
r[4]=r[13];
goto P_0c086fbe;
P_0c086fbe: /* original a04f, guest PC 0x0c086fbe */
if(!s->budget--) { s->failed_pc=0x0c086fbeu; return 0; }
r[14]=r[0];
goto P_0c087060;
P_0c086fc0: /* original 6e03, guest PC 0x0c086fc0 */
if(!s->budget--) { s->failed_pc=0x0c086fc0u; return 0; }
r[14]=r[0];
goto P_0c086fc2;
P_0c086fc2: /* original e018, guest PC 0x0c086fc2 */
if(!s->budget--) { s->failed_pc=0x0c086fc2u; return 0; }
r[0]=0x00000018u;
goto P_0c086fc4;
P_0c086fc4: /* original f3e6, guest PC 0x0c086fc4 */
if(!s->budget--) { s->failed_pc=0x0c086fc4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086fc6;
P_0c086fc6: /* original e00c, guest PC 0x0c086fc6 */
if(!s->budget--) { s->failed_pc=0x0c086fc6u; return 0; }
r[0]=0x0000000cu;
goto P_0c086fc8;
P_0c086fc8: /* original f2e6, guest PC 0x0c086fc8 */
if(!s->budget--) { s->failed_pc=0x0c086fc8u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c086fca;
P_0c086fca: /* original f230, guest PC 0x0c086fca */
if(!s->budget--) { s->failed_pc=0x0c086fcau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c086fcc;
P_0c086fcc: /* original fe27, guest PC 0x0c086fcc */
if(!s->budget--) { s->failed_pc=0x0c086fccu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c086fce;
P_0c086fce: /* original e020, guest PC 0x0c086fce */
if(!s->budget--) { s->failed_pc=0x0c086fceu; return 0; }
r[0]=0x00000020u;
goto P_0c086fd0;
P_0c086fd0: /* original f3e6, guest PC 0x0c086fd0 */
if(!s->budget--) { s->failed_pc=0x0c086fd0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086fd2;
P_0c086fd2: /* original e014, guest PC 0x0c086fd2 */
if(!s->budget--) { s->failed_pc=0x0c086fd2u; return 0; }
r[0]=0x00000014u;
goto P_0c086fd4;
P_0c086fd4: /* original f2e6, guest PC 0x0c086fd4 */
if(!s->budget--) { s->failed_pc=0x0c086fd4u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c086fd6;
P_0c086fd6: /* original f230, guest PC 0x0c086fd6 */
if(!s->budget--) { s->failed_pc=0x0c086fd6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c086fd8;
P_0c086fd8: /* original fe27, guest PC 0x0c086fd8 */
if(!s->budget--) { s->failed_pc=0x0c086fd8u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c086fda;
P_0c086fda: /* original e01c, guest PC 0x0c086fda */
if(!s->budget--) { s->failed_pc=0x0c086fdau; return 0; }
r[0]=0x0000001cu;
goto P_0c086fdc;
P_0c086fdc: /* original ffe6, guest PC 0x0c086fdc */
if(!s->budget--) { s->failed_pc=0x0c086fdcu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c086fde;
P_0c086fde: /* original e028, guest PC 0x0c086fde */
if(!s->budget--) { s->failed_pc=0x0c086fdeu; return 0; }
r[0]=0x00000028u;
goto P_0c086fe0;
P_0c086fe0: /* original fed6, guest PC 0x0c086fe0 */
if(!s->budget--) { s->failed_pc=0x0c086fe0u; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c086fe2;
P_0c086fe2: /* original e010, guest PC 0x0c086fe2 */
if(!s->budget--) { s->failed_pc=0x0c086fe2u; return 0; }
r[0]=0x00000010u;
goto P_0c086fe4;
P_0c086fe4: /* original f4e6, guest PC 0x0c086fe4 */
if(!s->budget--) { s->failed_pc=0x0c086fe4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c086fe6;
P_0c086fe6: /* original f4f0, guest PC 0x0c086fe6 */
if(!s->budget--) { s->failed_pc=0x0c086fe6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c086fe8;
P_0c086fe8: /* original fe45, guest PC 0x0c086fe8 */
if(!s->budget--) { s->failed_pc=0x0c086fe8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c086fea;
P_0c086fea: /* original 8b23, guest PC 0x0c086fea */
if(!s->budget--) { s->failed_pc=0x0c086feau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087034; }
goto P_0c086fec;
P_0c086fec: /* original dc26, guest PC 0x0c086fec */
if(!s->budget--) { s->failed_pc=0x0c086fecu; return 0; }
r[12]=read(ram,0x0c087088u,4);
goto P_0c086fee;
P_0c086fee: /* original 4c0b, guest PC 0x0c086fee */
if(!s->budget--) { s->failed_pc=0x0c086feeu; return 0; }
target=r[12];
r[16]=code_base|0x0c086ff2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086ff2u) { target=s->pc; goto dispatch; }
goto P_0c086ff2;
P_0c086ff0: /* original 0009, guest PC 0x0c086ff0 */
if(!s->budget--) { s->failed_pc=0x0c086ff0u; return 0; }
goto P_0c086ff2;
P_0c086ff2: /* original e407, guest PC 0x0c086ff2 */
if(!s->budget--) { s->failed_pc=0x0c086ff2u; return 0; }
r[4]=0x00000007u;
goto P_0c086ff4;
P_0c086ff4: /* original 6503, guest PC 0x0c086ff4 */
if(!s->budget--) { s->failed_pc=0x0c086ff4u; return 0; }
r[5]=r[0];
goto P_0c086ff6;
P_0c086ff6: /* original 2459, guest PC 0x0c086ff6 */
if(!s->budget--) { s->failed_pc=0x0c086ff6u; return 0; }
r[4]&=r[5];
goto P_0c086ff8;
P_0c086ff8: /* original 445a, guest PC 0x0c086ff8 */
if(!s->budget--) { s->failed_pc=0x0c086ff8u; return 0; }
r[53]=r[4];
goto P_0c086ffa;
P_0c086ffa: /* original e024, guest PC 0x0c086ffa */
if(!s->budget--) { s->failed_pc=0x0c086ffau; return 0; }
r[0]=0x00000024u;
goto P_0c086ffc;
P_0c086ffc: /* original f4d6, guest PC 0x0c086ffc */
if(!s->budget--) { s->failed_pc=0x0c086ffcu; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c086ffe;
P_0c086ffe: /* original e026, guest PC 0x0c086ffe */
if(!s->budget--) { s->failed_pc=0x0c086ffeu; return 0; }
r[0]=0x00000026u;
goto P_0c087000;
P_0c087000: /* original 943c, guest PC 0x0c087000 */
if(!s->budget--) { s->failed_pc=0x0c087000u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08707cu,2);
goto P_0c087002;
P_0c087002: /* original f32d, guest PC 0x0c087002 */
if(!s->budget--) { s->failed_pc=0x0c087002u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c087004;
P_0c087004: /* original 05ec, guest PC 0x0c087004 */
if(!s->budget--) { s->failed_pc=0x0c087004u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c087006;
P_0c087006: /* original 2459, guest PC 0x0c087006 */
if(!s->budget--) { s->failed_pc=0x0c087006u; return 0; }
r[4]&=r[5];
goto P_0c087008;
P_0c087008: /* original 2448, guest PC 0x0c087008 */
if(!s->budget--) { s->failed_pc=0x0c087008u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08700a;
P_0c08700a: /* original f53c, guest PC 0x0c08700a */
if(!s->budget--) { s->failed_pc=0x0c08700au; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08700c;
P_0c08700c: /* original f452, guest PC 0x0c08700c */
if(!s->budget--) { s->failed_pc=0x0c08700cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c08700e;
P_0c08700e: /* original f3fc, guest PC 0x0c08700e */
if(!s->budget--) { s->failed_pc=0x0c08700eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c087010;
P_0c087010: /* original ff4c, guest PC 0x0c087010 */
if(!s->budget--) { s->failed_pc=0x0c087010u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c087012;
P_0c087012: /* original ff32, guest PC 0x0c087012 */
if(!s->budget--) { s->failed_pc=0x0c087012u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c087014;
P_0c087014: /* original f5fc, guest PC 0x0c087014 */
if(!s->budget--) { s->failed_pc=0x0c087014u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c087016;
P_0c087016: /* original 8f08, guest PC 0x0c087016 */
if(!s->budget--) { s->failed_pc=0x0c087016u; return 0; }
cond=r[17]&1u;
fr[5]^=0x80000000u;
if(!cond) { goto P_0c08702a; }
goto P_0c08701a;
P_0c087018: /* original f54d, guest PC 0x0c087018 */
if(!s->budget--) { s->failed_pc=0x0c087018u; return 0; }
fr[5]^=0x80000000u;
goto P_0c08701a;
P_0c08701a: /* original e4c0, guest PC 0x0c08701a */
if(!s->budget--) { s->failed_pc=0x0c08701au; return 0; }
r[4]=0xffffffc0u;
goto P_0c08701c;
P_0c08701c: /* original 0e44, guest PC 0x0c08701c */
if(!s->budget--) { s->failed_pc=0x0c08701cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08701e;
P_0c08701e: /* original e018, guest PC 0x0c08701e */
if(!s->budget--) { s->failed_pc=0x0c08701eu; return 0; }
r[0]=0x00000018u;
goto P_0c087020;
P_0c087020: /* original f48d, guest PC 0x0c087020 */
if(!s->budget--) { s->failed_pc=0x0c087020u; return 0; }
fr[4]=0;
goto P_0c087022;
P_0c087022: /* original f54c, guest PC 0x0c087022 */
if(!s->budget--) { s->failed_pc=0x0c087022u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c087024;
P_0c087024: /* original fe57, guest PC 0x0c087024 */
if(!s->budget--) { s->failed_pc=0x0c087024u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c087026;
P_0c087026: /* original e020, guest PC 0x0c087026 */
if(!s->budget--) { s->failed_pc=0x0c087026u; return 0; }
r[0]=0x00000020u;
goto P_0c087028;
P_0c087028: /* original fe57, guest PC 0x0c087028 */
if(!s->budget--) { s->failed_pc=0x0c087028u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08702a;
P_0c08702a: /* original e010, guest PC 0x0c08702a */
if(!s->budget--) { s->failed_pc=0x0c08702au; return 0; }
r[0]=0x00000010u;
goto P_0c08702c;
P_0c08702c: /* original fee7, guest PC 0x0c08702c */
if(!s->budget--) { s->failed_pc=0x0c08702cu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08702e;
P_0c08702e: /* original e01c, guest PC 0x0c08702e */
if(!s->budget--) { s->failed_pc=0x0c08702eu; return 0; }
r[0]=0x0000001cu;
goto P_0c087030;
P_0c087030: /* original a016, guest PC 0x0c087030 */
if(!s->budget--) { s->failed_pc=0x0c087030u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c087060;
P_0c087032: /* original fe57, guest PC 0x0c087032 */
if(!s->budget--) { s->failed_pc=0x0c087032u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c087034;
P_0c087034: /* original ffd0, guest PC 0x0c087034 */
if(!s->budget--) { s->failed_pc=0x0c087034u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[13],r[18],'+');
goto P_0c087036;
P_0c087036: /* original fe47, guest PC 0x0c087036 */
if(!s->budget--) { s->failed_pc=0x0c087036u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c087038;
P_0c087038: /* original e02c, guest PC 0x0c087038 */
if(!s->budget--) { s->failed_pc=0x0c087038u; return 0; }
r[0]=0x0000002cu;
goto P_0c08703a;
P_0c08703a: /* original f4d6, guest PC 0x0c08703a */
if(!s->budget--) { s->failed_pc=0x0c08703au; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c08703c;
P_0c08703c: /* original ff45, guest PC 0x0c08703c */
if(!s->budget--) { s->failed_pc=0x0c08703cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c08703e;
P_0c08703e: /* original 8d01, guest PC 0x0c08703e */
if(!s->budget--) { s->failed_pc=0x0c08703eu; return 0; }
cond=r[17]&1u;
r[0]=0x0000001cu;
if(cond) { goto P_0c087044; }
goto P_0c087042;
P_0c087040: /* original e01c, guest PC 0x0c087040 */
if(!s->budget--) { s->failed_pc=0x0c087040u; return 0; }
r[0]=0x0000001cu;
goto P_0c087042;
P_0c087042: /* original ffd1, guest PC 0x0c087042 */
if(!s->budget--) { s->failed_pc=0x0c087042u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[13],r[18],'-');
goto P_0c087044;
P_0c087044: /* original fef7, guest PC 0x0c087044 */
if(!s->budget--) { s->failed_pc=0x0c087044u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c087046;
P_0c087046: /* original e026, guest PC 0x0c087046 */
if(!s->budget--) { s->failed_pc=0x0c087046u; return 0; }
r[0]=0x00000026u;
goto P_0c087048;
P_0c087048: /* original 9519, guest PC 0x0c087048 */
if(!s->budget--) { s->failed_pc=0x0c087048u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08707eu,2);
goto P_0c08704a;
P_0c08704a: /* original 04ec, guest PC 0x0c08704a */
if(!s->budget--) { s->failed_pc=0x0c08704au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08704c;
P_0c08704c: /* original 2459, guest PC 0x0c08704c */
if(!s->budget--) { s->failed_pc=0x0c08704cu; return 0; }
r[4]&=r[5];
goto P_0c08704e;
P_0c08704e: /* original 2448, guest PC 0x0c08704e */
if(!s->budget--) { s->failed_pc=0x0c08704eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087050;
P_0c087050: /* original 8b06, guest PC 0x0c087050 */
if(!s->budget--) { s->failed_pc=0x0c087050u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087060; }
goto P_0c087052;
P_0c087052: /* original e004, guest PC 0x0c087052 */
if(!s->budget--) { s->failed_pc=0x0c087052u; return 0; }
r[0]=0x00000004u;
goto P_0c087054;
P_0c087054: /* original 65d3, guest PC 0x0c087054 */
if(!s->budget--) { s->failed_pc=0x0c087054u; return 0; }
r[5]=r[13];
goto P_0c087056;
P_0c087056: /* original f4f6, guest PC 0x0c087056 */
if(!s->budget--) { s->failed_pc=0x0c087056u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087058;
P_0c087058: /* original 66e3, guest PC 0x0c087058 */
if(!s->budget--) { s->failed_pc=0x0c087058u; return 0; }
r[6]=r[14];
goto P_0c08705a;
P_0c08705a: /* original f5cc, guest PC 0x0c08705a */
if(!s->budget--) { s->failed_pc=0x0c08705au; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08705c;
P_0c08705c: /* original bf23, guest PC 0x0c08705c */
if(!s->budget--) { s->failed_pc=0x0c08705cu; return 0; }
target=0x0c086ea6u; r[16]=code_base|0x0c087060u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087060u) { target=s->pc; goto dispatch; }
goto P_0c087060;
P_0c08705e: /* original 64f2, guest PC 0x0c08705e */
if(!s->budget--) { s->failed_pc=0x0c08705eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c087060;
P_0c087060: /* original 60e2, guest PC 0x0c087060 */
if(!s->budget--) { s->failed_pc=0x0c087060u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c087062;
P_0c087062: /* original 88ff, guest PC 0x0c087062 */
if(!s->budget--) { s->failed_pc=0x0c087062u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087064;
P_0c087064: /* original 8fa3, guest PC 0x0c087064 */
if(!s->budget--) { s->failed_pc=0x0c087064u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c086fae; }
goto P_0c087068;
P_0c087066: /* original 6403, guest PC 0x0c087066 */
if(!s->budget--) { s->failed_pc=0x0c087066u; return 0; }
r[4]=r[0];
goto P_0c087068;
P_0c087068: /* original 7f08, guest PC 0x0c087068 */
if(!s->budget--) { s->failed_pc=0x0c087068u; return 0; }
r[15]+=0x00000008u;
goto P_0c08706a;
P_0c08706a: /* original 4f26, guest PC 0x0c08706a */
if(!s->budget--) { s->failed_pc=0x0c08706au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08706c;
P_0c08706c: /* original fcf9, guest PC 0x0c08706c */
if(!s->budget--) { s->failed_pc=0x0c08706cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08706e;
P_0c08706e: /* original fdf9, guest PC 0x0c08706e */
if(!s->budget--) { s->failed_pc=0x0c08706eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087070;
P_0c087070: /* original fef9, guest PC 0x0c087070 */
if(!s->budget--) { s->failed_pc=0x0c087070u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087072;
P_0c087072: /* original fff9, guest PC 0x0c087072 */
if(!s->budget--) { s->failed_pc=0x0c087072u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087074;
P_0c087074: /* original 6cf6, guest PC 0x0c087074 */
if(!s->budget--) { s->failed_pc=0x0c087074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087076;
P_0c087076: /* original 6df6, guest PC 0x0c087076 */
if(!s->budget--) { s->failed_pc=0x0c087076u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087078;
P_0c087078: /* original 000b, guest PC 0x0c087078 */
if(!s->budget--) { s->failed_pc=0x0c087078u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08707a: /* original 6ef6, guest PC 0x0c08707a */
if(!s->budget--) { s->failed_pc=0x0c08707au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08707cu,s,ram);
P_0c0871ee: /* original 4f22, guest PC 0x0c0871ee */
if(!s->budget--) { s->failed_pc=0x0c0871eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0871f0;
P_0c0871f0: /* original 6212, guest PC 0x0c0871f0 */
if(!s->budget--) { s->failed_pc=0x0c0871f0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0871f2;
P_0c0871f2: /* original d324, guest PC 0x0c0871f2 */
if(!s->budget--) { s->failed_pc=0x0c0871f2u; return 0; }
r[3]=read(ram,0x0c087284u,4);
goto P_0c0871f4;
P_0c0871f4: /* original 7ff8, guest PC 0x0c0871f4 */
if(!s->budget--) { s->failed_pc=0x0c0871f4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0871f6;
P_0c0871f6: /* original 2238, guest PC 0x0c0871f6 */
if(!s->budget--) { s->failed_pc=0x0c0871f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0871f8;
P_0c0871f8: /* original 8d02, guest PC 0x0c0871f8 */
if(!s->budget--) { s->failed_pc=0x0c0871f8u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(cond) { goto P_0c087200; }
goto P_0c0871fc;
P_0c0871fa: /* original 6c43, guest PC 0x0c0871fa */
if(!s->budget--) { s->failed_pc=0x0c0871fau; return 0; }
r[12]=r[4];
goto P_0c0871fc;
P_0c0871fc: /* original a09f, guest PC 0x0c0871fc */
if(!s->budget--) { s->failed_pc=0x0c0871fcu; return 0; }
goto P_0c08733e;
P_0c0871fe: /* original 0009, guest PC 0x0c0871fe */
if(!s->budget--) { s->failed_pc=0x0c0871feu; return 0; }
goto P_0c087200;
P_0c087200: /* original dd27, guest PC 0x0c087200 */
if(!s->budget--) { s->failed_pc=0x0c087200u; return 0; }
r[13]=read(ram,0x0c0872a0u,4);
goto P_0c087202;
P_0c087202: /* original d328, guest PC 0x0c087202 */
if(!s->budget--) { s->failed_pc=0x0c087202u; return 0; }
r[3]=read(ram,0x0c0872a4u,4);
goto P_0c087204;
P_0c087204: /* original 62d2, guest PC 0x0c087204 */
if(!s->budget--) { s->failed_pc=0x0c087204u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c087206;
P_0c087206: /* original 2238, guest PC 0x0c087206 */
if(!s->budget--) { s->failed_pc=0x0c087206u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c087208;
P_0c087208: /* original 8901, guest PC 0x0c087208 */
if(!s->budget--) { s->failed_pc=0x0c087208u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08720e; }
goto P_0c08720a;
P_0c08720a: /* original a098, guest PC 0x0c08720a */
if(!s->budget--) { s->failed_pc=0x0c08720au; return 0; }
goto P_0c08733e;
P_0c08720c: /* original 0009, guest PC 0x0c08720c */
if(!s->budget--) { s->failed_pc=0x0c08720cu; return 0; }
goto P_0c08720e;
P_0c08720e: /* original 9e36, guest PC 0x0c08720e */
if(!s->budget--) { s->failed_pc=0x0c08720eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08727eu,2);
goto P_0c087210;
P_0c087210: /* original 3ecc, guest PC 0x0c087210 */
if(!s->budget--) { s->failed_pc=0x0c087210u; return 0; }
r[14]+=r[12];
goto P_0c087212;
P_0c087212: /* original bdf6, guest PC 0x0c087212 */
if(!s->budget--) { s->failed_pc=0x0c087212u; return 0; }
target=0x0c086e02u; r[16]=code_base|0x0c087216u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087216u) { target=s->pc; goto dispatch; }
goto P_0c087216;
P_0c087214: /* original 64c3, guest PC 0x0c087214 */
if(!s->budget--) { s->failed_pc=0x0c087214u; return 0; }
r[4]=r[12];
goto P_0c087216;
P_0c087216: /* original 65f3, guest PC 0x0c087216 */
if(!s->budget--) { s->failed_pc=0x0c087216u; return 0; }
r[5]=r[15];
goto P_0c087218;
P_0c087218: /* original 7504, guest PC 0x0c087218 */
if(!s->budget--) { s->failed_pc=0x0c087218u; return 0; }
r[5]+=0x00000004u;
goto P_0c08721a;
P_0c08721a: /* original bde3, guest PC 0x0c08721a */
if(!s->budget--) { s->failed_pc=0x0c08721au; return 0; }
target=0x0c086de4u; r[16]=code_base|0x0c08721eu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08721eu) { target=s->pc; goto dispatch; }
goto P_0c08721e;
P_0c08721c: /* original 64f3, guest PC 0x0c08721c */
if(!s->budget--) { s->failed_pc=0x0c08721cu; return 0; }
r[4]=r[15];
goto P_0c08721e;
P_0c08721e: /* original 66f2, guest PC 0x0c08721e */
if(!s->budget--) { s->failed_pc=0x0c08721eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c087220;
P_0c087220: /* original 65e3, guest PC 0x0c087220 */
if(!s->budget--) { s->failed_pc=0x0c087220u; return 0; }
r[5]=r[14];
goto P_0c087222;
P_0c087222: /* original 57f1, guest PC 0x0c087222 */
if(!s->budget--) { s->failed_pc=0x0c087222u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c087224;
P_0c087224: /* original bdc5, guest PC 0x0c087224 */
if(!s->budget--) { s->failed_pc=0x0c087224u; return 0; }
target=0x0c086db2u; r[16]=code_base|0x0c087228u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087228u) { target=s->pc; goto dispatch; }
goto P_0c087228;
P_0c087226: /* original 64c3, guest PC 0x0c087226 */
if(!s->budget--) { s->failed_pc=0x0c087226u; return 0; }
r[4]=r[12];
goto P_0c087228;
P_0c087228: /* original 65e3, guest PC 0x0c087228 */
if(!s->budget--) { s->failed_pc=0x0c087228u; return 0; }
r[5]=r[14];
goto P_0c08722a;
P_0c08722a: /* original bea9, guest PC 0x0c08722a */
if(!s->budget--) { s->failed_pc=0x0c08722au; return 0; }
target=0x0c086f80u; r[16]=code_base|0x0c08722eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08722eu) { target=s->pc; goto dispatch; }
goto P_0c08722e;
P_0c08722c: /* original 64c3, guest PC 0x0c08722c */
if(!s->budget--) { s->failed_pc=0x0c08722cu; return 0; }
r[4]=r[12];
goto P_0c08722e;
P_0c08722e: /* original d31e, guest PC 0x0c08722e */
if(!s->budget--) { s->failed_pc=0x0c08722eu; return 0; }
r[3]=read(ram,0x0c0872a8u,4);
goto P_0c087230;
P_0c087230: /* original 5cd1, guest PC 0x0c087230 */
if(!s->budget--) { s->failed_pc=0x0c087230u; return 0; }
r[12]=read(ram,r[13]+4,4);
goto P_0c087232;
P_0c087232: /* original 23c8, guest PC 0x0c087232 */
if(!s->budget--) { s->failed_pc=0x0c087232u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c087234;
P_0c087234: /* original 8910, guest PC 0x0c087234 */
if(!s->budget--) { s->failed_pc=0x0c087234u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087258; }
goto P_0c087236;
P_0c087236: /* original d11d, guest PC 0x0c087236 */
if(!s->budget--) { s->failed_pc=0x0c087236u; return 0; }
r[1]=read(ram,0x0c0872acu,4);
goto P_0c087238;
P_0c087238: /* original 21c8, guest PC 0x0c087238 */
if(!s->budget--) { s->failed_pc=0x0c087238u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c08723a;
P_0c08723a: /* original 8901, guest PC 0x0c08723a */
if(!s->budget--) { s->failed_pc=0x0c08723au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087240; }
goto P_0c08723c;
P_0c08723c: /* original be1c, guest PC 0x0c08723c */
if(!s->budget--) { s->failed_pc=0x0c08723cu; return 0; }
target=0x0c086e78u; r[16]=code_base|0x0c087240u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087240u) { target=s->pc; goto dispatch; }
goto P_0c087240;
P_0c08723e: /* original 64e3, guest PC 0x0c08723e */
if(!s->budget--) { s->failed_pc=0x0c08723eu; return 0; }
r[4]=r[14];
goto P_0c087240;
P_0c087240: /* original 901f, guest PC 0x0c087240 */
if(!s->budget--) { s->failed_pc=0x0c087240u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087282u,2);
goto P_0c087242;
P_0c087242: /* original 04de, guest PC 0x0c087242 */
if(!s->budget--) { s->failed_pc=0x0c087242u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c087244;
P_0c087244: /* original 2448, guest PC 0x0c087244 */
if(!s->budget--) { s->failed_pc=0x0c087244u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087246;
P_0c087246: /* original 8963, guest PC 0x0c087246 */
if(!s->budget--) { s->failed_pc=0x0c087246u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087310; }
goto P_0c087248;
P_0c087248: /* original e02a, guest PC 0x0c087248 */
if(!s->budget--) { s->failed_pc=0x0c087248u; return 0; }
r[0]=0x0000002au;
goto P_0c08724a;
P_0c08724a: /* original 054d, guest PC 0x0c08724a */
if(!s->budget--) { s->failed_pc=0x0c08724au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08724c;
P_0c08724c: /* original 7440, guest PC 0x0c08724c */
if(!s->budget--) { s->failed_pc=0x0c08724cu; return 0; }
r[4]+=0x00000040u;
goto P_0c08724e;
P_0c08724e: /* original 2558, guest PC 0x0c08724e */
if(!s->budget--) { s->failed_pc=0x0c08724eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087250;
P_0c087250: /* original 8d02, guest PC 0x0c087250 */
if(!s->budget--) { s->failed_pc=0x0c087250u; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(cond) { goto P_0c087258; }
goto P_0c087254;
P_0c087252: /* original 044d, guest PC 0x0c087252 */
if(!s->budget--) { s->failed_pc=0x0c087252u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c087254;
P_0c087254: /* original 2448, guest PC 0x0c087254 */
if(!s->budget--) { s->failed_pc=0x0c087254u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087256;
P_0c087256: /* original 8b5b, guest PC 0x0c087256 */
if(!s->budget--) { s->failed_pc=0x0c087256u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087310; }
goto P_0c087258;
P_0c087258: /* original d215, guest PC 0x0c087258 */
if(!s->budget--) { s->failed_pc=0x0c087258u; return 0; }
r[2]=read(ram,0x0c0872b0u,4);
goto P_0c08725a;
P_0c08725a: /* original 2c28, guest PC 0x0c08725a */
if(!s->budget--) { s->failed_pc=0x0c08725au; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[2])==0)!=0);
goto P_0c08725c;
P_0c08725c: /* original 8905, guest PC 0x0c08725c */
if(!s->budget--) { s->failed_pc=0x0c08725cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08726a; }
goto P_0c08725e;
P_0c08725e: /* original e048, guest PC 0x0c08725e */
if(!s->budget--) { s->failed_pc=0x0c08725eu; return 0; }
r[0]=0x00000048u;
goto P_0c087260;
P_0c087260: /* original 04ed, guest PC 0x0c087260 */
if(!s->budget--) { s->failed_pc=0x0c087260u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c087262;
P_0c087262: /* original 74ff, guest PC 0x0c087262 */
if(!s->budget--) { s->failed_pc=0x0c087262u; return 0; }
r[4]+=0xffffffffu;
goto P_0c087264;
P_0c087264: /* original 4411, guest PC 0x0c087264 */
if(!s->budget--) { s->failed_pc=0x0c087264u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c087266;
P_0c087266: /* original 8b53, guest PC 0x0c087266 */
if(!s->budget--) { s->failed_pc=0x0c087266u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087310; }
goto P_0c087268;
P_0c087268: /* original 0e45, guest PC 0x0c087268 */
if(!s->budget--) { s->failed_pc=0x0c087268u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08726a;
P_0c08726a: /* original 85e4, guest PC 0x0c08726a */
if(!s->budget--) { s->failed_pc=0x0c08726au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c08726c;
P_0c08726c: /* original 6403, guest PC 0x0c08726c */
if(!s->budget--) { s->failed_pc=0x0c08726cu; return 0; }
r[4]=r[0];
goto P_0c08726e;
P_0c08726e: /* original 4410, guest PC 0x0c08726e */
if(!s->budget--) { s->failed_pc=0x0c08726eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c087270;
P_0c087270: /* original 8920, guest PC 0x0c087270 */
if(!s->budget--) { s->failed_pc=0x0c087270u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0872b4; }
goto P_0c087272;
P_0c087272: /* original 6043, guest PC 0x0c087272 */
if(!s->budget--) { s->failed_pc=0x0c087272u; return 0; }
r[0]=r[4];
goto P_0c087274;
P_0c087274: /* original 81e4, guest PC 0x0c087274 */
if(!s->budget--) { s->failed_pc=0x0c087274u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c087276;
P_0c087276: /* original e07e, guest PC 0x0c087276 */
if(!s->budget--) { s->failed_pc=0x0c087276u; return 0; }
r[0]=0x0000007eu;
goto P_0c087278;
P_0c087278: /* original e300, guest PC 0x0c087278 */
if(!s->budget--) { s->failed_pc=0x0c087278u; return 0; }
r[3]=0x00000000u;
goto P_0c08727a;
P_0c08727a: /* original a060, guest PC 0x0c08727a */
if(!s->budget--) { s->failed_pc=0x0c08727au; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08733e;
P_0c08727c: /* original 0d34, guest PC 0x0c08727c */
if(!s->budget--) { s->failed_pc=0x0c08727cu; return 0; }
write(ram,r[13]+r[0],r[3],1);
return vf3_matrix_family(0x0c08727eu,s,ram);
P_0c0872b4: /* original 85e5, guest PC 0x0c0872b4 */
if(!s->budget--) { s->failed_pc=0x0c0872b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c0872b6;
P_0c0872b6: /* original 6403, guest PC 0x0c0872b6 */
if(!s->budget--) { s->failed_pc=0x0c0872b6u; return 0; }
r[4]=r[0];
goto P_0c0872b8;
P_0c0872b8: /* original 4410, guest PC 0x0c0872b8 */
if(!s->budget--) { s->failed_pc=0x0c0872b8u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0872ba;
P_0c0872ba: /* original 8929, guest PC 0x0c0872ba */
if(!s->budget--) { s->failed_pc=0x0c0872bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087310; }
goto P_0c0872bc;
P_0c0872bc: /* original 6043, guest PC 0x0c0872bc */
if(!s->budget--) { s->failed_pc=0x0c0872bcu; return 0; }
r[0]=r[4];
goto P_0c0872be;
P_0c0872be: /* original 81e5, guest PC 0x0c0872be */
if(!s->budget--) { s->failed_pc=0x0c0872beu; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c0872c0;
P_0c0872c0: /* original e03a, guest PC 0x0c0872c0 */
if(!s->budget--) { s->failed_pc=0x0c0872c0u; return 0; }
r[0]=0x0000003au;
goto P_0c0872c2;
P_0c0872c2: /* original 04ec, guest PC 0x0c0872c2 */
if(!s->budget--) { s->failed_pc=0x0c0872c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0872c4;
P_0c0872c4: /* original 4410, guest PC 0x0c0872c4 */
if(!s->budget--) { s->failed_pc=0x0c0872c4u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0872c6;
P_0c0872c6: /* original 8b0c, guest PC 0x0c0872c6 */
if(!s->budget--) { s->failed_pc=0x0c0872c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0872e2; }
goto P_0c0872c8;
P_0c0872c8: /* original d245, guest PC 0x0c0872c8 */
if(!s->budget--) { s->failed_pc=0x0c0872c8u; return 0; }
r[2]=read(ram,0x0c0873e0u,4);
goto P_0c0872ca;
P_0c0872ca: /* original 420b, guest PC 0x0c0872ca */
if(!s->budget--) { s->failed_pc=0x0c0872cau; return 0; }
target=r[2];
r[16]=code_base|0x0c0872ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0872ceu) { target=s->pc; goto dispatch; }
goto P_0c0872ce;
P_0c0872cc: /* original 0009, guest PC 0x0c0872cc */
if(!s->budget--) { s->failed_pc=0x0c0872ccu; return 0; }
goto P_0c0872ce;
P_0c0872ce: /* original e40f, guest PC 0x0c0872ce */
if(!s->budget--) { s->failed_pc=0x0c0872ceu; return 0; }
r[4]=0x0000000fu;
goto P_0c0872d0;
P_0c0872d0: /* original 6503, guest PC 0x0c0872d0 */
if(!s->budget--) { s->failed_pc=0x0c0872d0u; return 0; }
r[5]=r[0];
goto P_0c0872d2;
P_0c0872d2: /* original e3fb, guest PC 0x0c0872d2 */
if(!s->budget--) { s->failed_pc=0x0c0872d2u; return 0; }
r[3]=0xfffffffbu;
goto P_0c0872d4;
P_0c0872d4: /* original 2459, guest PC 0x0c0872d4 */
if(!s->budget--) { s->failed_pc=0x0c0872d4u; return 0; }
r[4]&=r[5];
goto P_0c0872d6;
P_0c0872d6: /* original e207, guest PC 0x0c0872d6 */
if(!s->budget--) { s->failed_pc=0x0c0872d6u; return 0; }
r[2]=0x00000007u;
goto P_0c0872d8;
P_0c0872d8: /* original 453c, guest PC 0x0c0872d8 */
if(!s->budget--) { s->failed_pc=0x0c0872d8u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c0872da;
P_0c0872da: /* original e039, guest PC 0x0c0872da */
if(!s->budget--) { s->failed_pc=0x0c0872dau; return 0; }
r[0]=0x00000039u;
goto P_0c0872dc;
P_0c0872dc: /* original 2529, guest PC 0x0c0872dc */
if(!s->budget--) { s->failed_pc=0x0c0872dcu; return 0; }
r[5]&=r[2];
goto P_0c0872de;
P_0c0872de: /* original 0e54, guest PC 0x0c0872de */
if(!s->budget--) { s->failed_pc=0x0c0872deu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0872e0;
P_0c0872e0: /* original 7401, guest PC 0x0c0872e0 */
if(!s->budget--) { s->failed_pc=0x0c0872e0u; return 0; }
r[4]+=0x00000001u;
goto P_0c0872e2;
P_0c0872e2: /* original e03a, guest PC 0x0c0872e2 */
if(!s->budget--) { s->failed_pc=0x0c0872e2u; return 0; }
r[0]=0x0000003au;
goto P_0c0872e4;
P_0c0872e4: /* original 0e44, guest PC 0x0c0872e4 */
if(!s->budget--) { s->failed_pc=0x0c0872e4u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0872e6;
P_0c0872e6: /* original e039, guest PC 0x0c0872e6 */
if(!s->budget--) { s->failed_pc=0x0c0872e6u; return 0; }
r[0]=0x00000039u;
goto P_0c0872e8;
P_0c0872e8: /* original 05ec, guest PC 0x0c0872e8 */
if(!s->budget--) { s->failed_pc=0x0c0872e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0872ea;
P_0c0872ea: /* original d63e, guest PC 0x0c0872ea */
if(!s->budget--) { s->failed_pc=0x0c0872eau; return 0; }
r[6]=read(ram,0x0c0873e4u,4);
goto P_0c0872ec;
P_0c0872ec: /* original 4500, guest PC 0x0c0872ec */
if(!s->budget--) { s->failed_pc=0x0c0872ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0872ee;
P_0c0872ee: /* original 6053, guest PC 0x0c0872ee */
if(!s->budget--) { s->failed_pc=0x0c0872eeu; return 0; }
r[0]=r[5];
goto P_0c0872f0;
P_0c0872f0: /* original 4008, guest PC 0x0c0872f0 */
if(!s->budget--) { s->failed_pc=0x0c0872f0u; return 0; }
r[0]<<=2;
goto P_0c0872f2;
P_0c0872f2: /* original f366, guest PC 0x0c0872f2 */
if(!s->budget--) { s->failed_pc=0x0c0872f2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c0872f4;
P_0c0872f4: /* original e03c, guest PC 0x0c0872f4 */
if(!s->budget--) { s->failed_pc=0x0c0872f4u; return 0; }
r[0]=0x0000003cu;
goto P_0c0872f6;
P_0c0872f6: /* original fe37, guest PC 0x0c0872f6 */
if(!s->budget--) { s->failed_pc=0x0c0872f6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0872f8;
P_0c0872f8: /* original 6053, guest PC 0x0c0872f8 */
if(!s->budget--) { s->failed_pc=0x0c0872f8u; return 0; }
r[0]=r[5];
goto P_0c0872fa;
P_0c0872fa: /* original 7001, guest PC 0x0c0872fa */
if(!s->budget--) { s->failed_pc=0x0c0872fau; return 0; }
r[0]+=0x00000001u;
goto P_0c0872fc;
P_0c0872fc: /* original 4008, guest PC 0x0c0872fc */
if(!s->budget--) { s->failed_pc=0x0c0872fcu; return 0; }
r[0]<<=2;
goto P_0c0872fe;
P_0c0872fe: /* original f366, guest PC 0x0c0872fe */
if(!s->budget--) { s->failed_pc=0x0c0872feu; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c087300;
P_0c087300: /* original e040, guest PC 0x0c087300 */
if(!s->budget--) { s->failed_pc=0x0c087300u; return 0; }
r[0]=0x00000040u;
goto P_0c087302;
P_0c087302: /* original fe37, guest PC 0x0c087302 */
if(!s->budget--) { s->failed_pc=0x0c087302u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087304;
P_0c087304: /* original bc0c, guest PC 0x0c087304 */
if(!s->budget--) { s->failed_pc=0x0c087304u; return 0; }
target=0x0c086b20u; r[16]=code_base|0x0c087308u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087308u) { target=s->pc; goto dispatch; }
goto P_0c087308;
P_0c087306: /* original 64e3, guest PC 0x0c087306 */
if(!s->budget--) { s->failed_pc=0x0c087306u; return 0; }
r[4]=r[14];
goto P_0c087308;
P_0c087308: /* original e07e, guest PC 0x0c087308 */
if(!s->budget--) { s->failed_pc=0x0c087308u; return 0; }
r[0]=0x0000007eu;
goto P_0c08730a;
P_0c08730a: /* original e201, guest PC 0x0c08730a */
if(!s->budget--) { s->failed_pc=0x0c08730au; return 0; }
r[2]=0x00000001u;
goto P_0c08730c;
P_0c08730c: /* original a017, guest PC 0x0c08730c */
if(!s->budget--) { s->failed_pc=0x0c08730cu; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08733e;
P_0c08730e: /* original 0d24, guest PC 0x0c08730e */
if(!s->budget--) { s->failed_pc=0x0c08730eu; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c087310;
P_0c087310: /* original d333, guest PC 0x0c087310 */
if(!s->budget--) { s->failed_pc=0x0c087310u; return 0; }
r[3]=read(ram,0x0c0873e0u,4);
goto P_0c087312;
P_0c087312: /* original 430b, guest PC 0x0c087312 */
if(!s->budget--) { s->failed_pc=0x0c087312u; return 0; }
target=r[3];
r[16]=code_base|0x0c087316u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087316u) { target=s->pc; goto dispatch; }
goto P_0c087316;
P_0c087314: /* original 0009, guest PC 0x0c087314 */
if(!s->budget--) { s->failed_pc=0x0c087314u; return 0; }
goto P_0c087316;
P_0c087316: /* original d134, guest PC 0x0c087316 */
if(!s->budget--) { s->failed_pc=0x0c087316u; return 0; }
r[1]=read(ram,0x0c0873e8u,4);
goto P_0c087318;
P_0c087318: /* original e503, guest PC 0x0c087318 */
if(!s->budget--) { s->failed_pc=0x0c087318u; return 0; }
r[5]=0x00000003u;
goto P_0c08731a;
P_0c08731a: /* original 6403, guest PC 0x0c08731a */
if(!s->budget--) { s->failed_pc=0x0c08731au; return 0; }
r[4]=r[0];
goto P_0c08731c;
P_0c08731c: /* original 2059, guest PC 0x0c08731c */
if(!s->budget--) { s->failed_pc=0x0c08731cu; return 0; }
r[0]&=r[5];
goto P_0c08731e;
P_0c08731e: /* original e3f8, guest PC 0x0c08731e */
if(!s->budget--) { s->failed_pc=0x0c08731eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c087320;
P_0c087320: /* original 001c, guest PC 0x0c087320 */
if(!s->budget--) { s->failed_pc=0x0c087320u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c087322;
P_0c087322: /* original 443c, guest PC 0x0c087322 */
if(!s->budget--) { s->failed_pc=0x0c087322u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c087324;
P_0c087324: /* original 2459, guest PC 0x0c087324 */
if(!s->budget--) { s->failed_pc=0x0c087324u; return 0; }
r[4]&=r[5];
goto P_0c087326;
P_0c087326: /* original 81e4, guest PC 0x0c087326 */
if(!s->budget--) { s->failed_pc=0x0c087326u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c087328;
P_0c087328: /* original 6043, guest PC 0x0c087328 */
if(!s->budget--) { s->failed_pc=0x0c087328u; return 0; }
r[0]=r[4];
goto P_0c08732a;
P_0c08732a: /* original e501, guest PC 0x0c08732a */
if(!s->budget--) { s->failed_pc=0x0c08732au; return 0; }
r[5]=0x00000001u;
goto P_0c08732c;
P_0c08732c: /* original 4021, guest PC 0x0c08732c */
if(!s->budget--) { s->failed_pc=0x0c08732cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c08732e;
P_0c08732e: /* original 2509, guest PC 0x0c08732e */
if(!s->budget--) { s->failed_pc=0x0c08732eu; return 0; }
r[5]&=r[0];
goto P_0c087330;
P_0c087330: /* original e038, guest PC 0x0c087330 */
if(!s->budget--) { s->failed_pc=0x0c087330u; return 0; }
r[0]=0x00000038u;
goto P_0c087332;
P_0c087332: /* original 0e54, guest PC 0x0c087332 */
if(!s->budget--) { s->failed_pc=0x0c087332u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c087334;
P_0c087334: /* original e20a, guest PC 0x0c087334 */
if(!s->budget--) { s->failed_pc=0x0c087334u; return 0; }
r[2]=0x0000000au;
goto P_0c087336;
P_0c087336: /* original d02d, guest PC 0x0c087336 */
if(!s->budget--) { s->failed_pc=0x0c087336u; return 0; }
r[0]=read(ram,0x0c0873ecu,4);
goto P_0c087338;
P_0c087338: /* original 32ec, guest PC 0x0c087338 */
if(!s->budget--) { s->failed_pc=0x0c087338u; return 0; }
r[2]+=r[14];
goto P_0c08733a;
P_0c08733a: /* original 034c, guest PC 0x0c08733a */
if(!s->budget--) { s->failed_pc=0x0c08733au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08733c;
P_0c08733c: /* original 2231, guest PC 0x0c08733c */
if(!s->budget--) { s->failed_pc=0x0c08733cu; return 0; }
write(ram,r[2],r[3],2);
goto P_0c08733e;
P_0c08733e: /* original 7f08, guest PC 0x0c08733e */
if(!s->budget--) { s->failed_pc=0x0c08733eu; return 0; }
r[15]+=0x00000008u;
goto P_0c087340;
P_0c087340: /* original 4f26, guest PC 0x0c087340 */
if(!s->budget--) { s->failed_pc=0x0c087340u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087342;
P_0c087342: /* original 6cf6, guest PC 0x0c087342 */
if(!s->budget--) { s->failed_pc=0x0c087342u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087344;
P_0c087344: /* original 6df6, guest PC 0x0c087344 */
if(!s->budget--) { s->failed_pc=0x0c087344u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087346;
P_0c087346: /* original 000b, guest PC 0x0c087346 */
if(!s->budget--) { s->failed_pc=0x0c087346u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087348: /* original 6ef6, guest PC 0x0c087348 */
if(!s->budget--) { s->failed_pc=0x0c087348u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08734au,s,ram);
P_0c0881dc: /* original 5341, guest PC 0x0c0881dc */
if(!s->budget--) { s->failed_pc=0x0c0881dcu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0881de;
P_0c0881de: /* original d542, guest PC 0x0c0881de */
if(!s->budget--) { s->failed_pc=0x0c0881deu; return 0; }
r[5]=read(ram,0x0c0882e8u,4);
goto P_0c0881e0;
P_0c0881e0: /* original 4f12, guest PC 0x0c0881e0 */
if(!s->budget--) { s->failed_pc=0x0c0881e0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0881e2;
P_0c0881e2: /* original 0537, guest PC 0x0c0881e2 */
if(!s->budget--) { s->failed_pc=0x0c0881e2u; return 0; }
r[19]=r[5]*r[3];
goto P_0c0881e4;
P_0c0881e4: /* original 927d, guest PC 0x0c0881e4 */
if(!s->budget--) { s->failed_pc=0x0c0881e4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0882e2u,2);
goto P_0c0881e6;
P_0c0881e6: /* original 051a, guest PC 0x0c0881e6 */
if(!s->budget--) { s->failed_pc=0x0c0881e6u; return 0; }
r[5]=r[19];
goto P_0c0881e8;
P_0c0881e8: /* original 352c, guest PC 0x0c0881e8 */
if(!s->budget--) { s->failed_pc=0x0c0881e8u; return 0; }
r[5]+=r[2];
goto P_0c0881ea;
P_0c0881ea: /* original 1451, guest PC 0x0c0881ea */
if(!s->budget--) { s->failed_pc=0x0c0881eau; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c0881ec;
P_0c0881ec: /* original 4529, guest PC 0x0c0881ec */
if(!s->budget--) { s->failed_pc=0x0c0881ecu; return 0; }
r[5]>>=16;
goto P_0c0881ee;
P_0c0881ee: /* original 9379, guest PC 0x0c0881ee */
if(!s->budget--) { s->failed_pc=0x0c0881eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0882e4u,2);
goto P_0c0881f0;
P_0c0881f0: /* original 655f, guest PC 0x0c0881f0 */
if(!s->budget--) { s->failed_pc=0x0c0881f0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0881f2;
P_0c0881f2: /* original 2539, guest PC 0x0c0881f2 */
if(!s->budget--) { s->failed_pc=0x0c0881f2u; return 0; }
r[5]&=r[3];
goto P_0c0881f4;
P_0c0881f4: /* original 6053, guest PC 0x0c0881f4 */
if(!s->budget--) { s->failed_pc=0x0c0881f4u; return 0; }
r[0]=r[5];
goto P_0c0881f6;
P_0c0881f6: /* original 000b, guest PC 0x0c0881f6 */
if(!s->budget--) { s->failed_pc=0x0c0881f6u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0881f8: /* original 4f16, guest PC 0x0c0881f8 */
if(!s->budget--) { s->failed_pc=0x0c0881f8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0881fau,s,ram);
P_0c0884d0: /* original c737, guest PC 0x0c0884d0 */
if(!s->budget--) { s->failed_pc=0x0c0884d0u; return 0; }
r[0]=0x0c0885b0u;
goto P_0c0884d2;
P_0c0884d2: /* original 2fe6, guest PC 0x0c0884d2 */
if(!s->budget--) { s->failed_pc=0x0c0884d2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0884d4;
P_0c0884d4: /* original fffb, guest PC 0x0c0884d4 */
if(!s->budget--) { s->failed_pc=0x0c0884d4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0884d6;
P_0c0884d6: /* original 6e63, guest PC 0x0c0884d6 */
if(!s->budget--) { s->failed_pc=0x0c0884d6u; return 0; }
r[14]=r[6];
goto P_0c0884d8;
P_0c0884d8: /* original ffeb, guest PC 0x0c0884d8 */
if(!s->budget--) { s->failed_pc=0x0c0884d8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0884da;
P_0c0884da: /* original f608, guest PC 0x0c0884da */
if(!s->budget--) { s->failed_pc=0x0c0884dau; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0884dc;
P_0c0884dc: /* original c735, guest PC 0x0c0884dc */
if(!s->budget--) { s->failed_pc=0x0c0884dcu; return 0; }
r[0]=0x0c0885b4u;
goto P_0c0884de;
P_0c0884de: /* original f79d, guest PC 0x0c0884de */
if(!s->budget--) { s->failed_pc=0x0c0884deu; return 0; }
fr[7]=0x3f800000u;
goto P_0c0884e0;
P_0c0884e0: /* original f57c, guest PC 0x0c0884e0 */
if(!s->budget--) { s->failed_pc=0x0c0884e0u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0884e2;
P_0c0884e2: /* original f450, guest PC 0x0c0884e2 */
if(!s->budget--) { s->failed_pc=0x0c0884e2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c0884e4;
P_0c0884e4: /* original ff08, guest PC 0x0c0884e4 */
if(!s->budget--) { s->failed_pc=0x0c0884e4u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0884e6;
P_0c0884e6: /* original e004, guest PC 0x0c0884e6 */
if(!s->budget--) { s->failed_pc=0x0c0884e6u; return 0; }
r[0]=0x00000004u;
goto P_0c0884e8;
P_0c0884e8: /* original f356, guest PC 0x0c0884e8 */
if(!s->budget--) { s->failed_pc=0x0c0884e8u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0884ea;
P_0c0884ea: /* original 4f22, guest PC 0x0c0884ea */
if(!s->budget--) { s->failed_pc=0x0c0884eau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0884ec;
P_0c0884ec: /* original f431, guest PC 0x0c0884ec */
if(!s->budget--) { s->failed_pc=0x0c0884ecu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0884ee;
P_0c0884ee: /* original f38d, guest PC 0x0c0884ee */
if(!s->budget--) { s->failed_pc=0x0c0884eeu; return 0; }
fr[3]=0;
goto P_0c0884f0;
P_0c0884f0: /* original 7ffc, guest PC 0x0c0884f0 */
if(!s->budget--) { s->failed_pc=0x0c0884f0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0884f2;
P_0c0884f2: /* original 56f5, guest PC 0x0c0884f2 */
if(!s->budget--) { s->failed_pc=0x0c0884f2u; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c0884f4;
P_0c0884f4: /* original f435, guest PC 0x0c0884f4 */
if(!s->budget--) { s->failed_pc=0x0c0884f4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0884f6;
P_0c0884f6: /* original 8b51, guest PC 0x0c0884f6 */
if(!s->budget--) { s->failed_pc=0x0c0884f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08859c; }
goto P_0c0884f8;
P_0c0884f8: /* original f455, guest PC 0x0c0884f8 */
if(!s->budget--) { s->failed_pc=0x0c0884f8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0884fa;
P_0c0884fa: /* original 8f01, guest PC 0x0c0884fa */
if(!s->budget--) { s->failed_pc=0x0c0884fau; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,3,r[6]+r[0]);
if(!cond) { goto P_0c088500; }
goto P_0c0884fe;
P_0c0884fc: /* original f366, guest PC 0x0c0884fc */
if(!s->budget--) { s->failed_pc=0x0c0884fcu; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c0884fe;
P_0c0884fe: /* original f45c, guest PC 0x0c0884fe */
if(!s->budget--) { s->failed_pc=0x0c0884feu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c088500;
P_0c088500: /* original f342, guest PC 0x0c088500 */
if(!s->budget--) { s->failed_pc=0x0c088500u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c088502;
P_0c088502: /* original e008, guest PC 0x0c088502 */
if(!s->budget--) { s->failed_pc=0x0c088502u; return 0; }
r[0]=0x00000008u;
goto P_0c088504;
P_0c088504: /* original ff3a, guest PC 0x0c088504 */
if(!s->budget--) { s->failed_pc=0x0c088504u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c088506;
P_0c088506: /* original f558, guest PC 0x0c088506 */
if(!s->budget--) { s->failed_pc=0x0c088506u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c088508;
P_0c088508: /* original f378, guest PC 0x0c088508 */
if(!s->budget--) { s->failed_pc=0x0c088508u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c08850a;
P_0c08850a: /* original f456, guest PC 0x0c08850a */
if(!s->budget--) { s->failed_pc=0x0c08850au; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c08850c;
P_0c08850c: /* original f531, guest PC 0x0c08850c */
if(!s->budget--) { s->failed_pc=0x0c08850cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c08850e;
P_0c08850e: /* original f376, guest PC 0x0c08850e */
if(!s->budget--) { s->failed_pc=0x0c08850eu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c088510;
P_0c088510: /* original c729, guest PC 0x0c088510 */
if(!s->budget--) { s->failed_pc=0x0c088510u; return 0; }
r[0]=0x0c0885b8u;
goto P_0c088512;
P_0c088512: /* original f430, guest PC 0x0c088512 */
if(!s->budget--) { s->failed_pc=0x0c088512u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c088514;
P_0c088514: /* original f208, guest PC 0x0c088514 */
if(!s->budget--) { s->failed_pc=0x0c088514u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c088516;
P_0c088516: /* original f35c, guest PC 0x0c088516 */
if(!s->budget--) { s->failed_pc=0x0c088516u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c088518;
P_0c088518: /* original f352, guest PC 0x0c088518 */
if(!s->budget--) { s->failed_pc=0x0c088518u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c08851a;
P_0c08851a: /* original f04c, guest PC 0x0c08851a */
if(!s->budget--) { s->failed_pc=0x0c08851au; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c08851c;
P_0c08851c: /* original f34e, guest PC 0x0c08851c */
if(!s->budget--) { s->failed_pc=0x0c08851cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c08851e;
P_0c08851e: /* original f43c, guest PC 0x0c08851e */
if(!s->budget--) { s->failed_pc=0x0c08851eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c088520;
P_0c088520: /* original f245, guest PC 0x0c088520 */
if(!s->budget--) { s->failed_pc=0x0c088520u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c088522;
P_0c088522: /* original 8b01, guest PC 0x0c088522 */
if(!s->budget--) { s->failed_pc=0x0c088522u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088528; }
goto P_0c088524;
P_0c088524: /* original a001, guest PC 0x0c088524 */
if(!s->budget--) { s->failed_pc=0x0c088524u; return 0; }
fr[4]=0;
goto P_0c08852a;
P_0c088526: /* original f48d, guest PC 0x0c088526 */
if(!s->budget--) { s->failed_pc=0x0c088526u; return 0; }
fr[4]=0;
goto P_0c088528;
P_0c088528: /* original f47d, guest PC 0x0c088528 */
if(!s->budget--) { s->failed_pc=0x0c088528u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c08852a;
P_0c08852a: /* original f34c, guest PC 0x0c08852a */
if(!s->budget--) { s->failed_pc=0x0c08852au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08852c;
P_0c08852c: /* original f47c, guest PC 0x0c08852c */
if(!s->budget--) { s->failed_pc=0x0c08852cu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c08852e;
P_0c08852e: /* original f433, guest PC 0x0c08852e */
if(!s->budget--) { s->failed_pc=0x0c08852eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c088530;
P_0c088530: /* original f28d, guest PC 0x0c088530 */
if(!s->budget--) { s->failed_pc=0x0c088530u; return 0; }
fr[2]=0;
goto P_0c088532;
P_0c088532: /* original f34c, guest PC 0x0c088532 */
if(!s->budget--) { s->failed_pc=0x0c088532u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c088534;
P_0c088534: /* original f46c, guest PC 0x0c088534 */
if(!s->budget--) { s->failed_pc=0x0c088534u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c088536;
P_0c088536: /* original f431, guest PC 0x0c088536 */
if(!s->budget--) { s->failed_pc=0x0c088536u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c088538;
P_0c088538: /* original f425, guest PC 0x0c088538 */
if(!s->budget--) { s->failed_pc=0x0c088538u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c08853a;
P_0c08853a: /* original 8b2f, guest PC 0x0c08853a */
if(!s->budget--) { s->failed_pc=0x0c08853au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08859c; }
goto P_0c08853c;
P_0c08853c: /* original c71f, guest PC 0x0c08853c */
if(!s->budget--) { s->failed_pc=0x0c08853cu; return 0; }
r[0]=0x0c0885bcu;
goto P_0c08853e;
P_0c08853e: /* original f508, guest PC 0x0c08853e */
if(!s->budget--) { s->failed_pc=0x0c08853eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c088540;
P_0c088540: /* original f545, guest PC 0x0c088540 */
if(!s->budget--) { s->failed_pc=0x0c088540u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c088542;
P_0c088542: /* original 8b00, guest PC 0x0c088542 */
if(!s->budget--) { s->failed_pc=0x0c088542u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088546; }
goto P_0c088544;
P_0c088544: /* original f45c, guest PC 0x0c088544 */
if(!s->budget--) { s->failed_pc=0x0c088544u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c088546;
P_0c088546: /* original 53f6, guest PC 0x0c088546 */
if(!s->budget--) { s->failed_pc=0x0c088546u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c088548;
P_0c088548: /* original 6030, guest PC 0x0c088548 */
if(!s->budget--) { s->failed_pc=0x0c088548u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c08854a;
P_0c08854a: /* original cb01, guest PC 0x0c08854a */
if(!s->budget--) { s->failed_pc=0x0c08854au; return 0; }
r[0]|=1u;
goto P_0c08854c;
P_0c08854c: /* original 2300, guest PC 0x0c08854c */
if(!s->budget--) { s->failed_pc=0x0c08854cu; return 0; }
write(ram,r[3],r[0],1);
goto P_0c08854e;
P_0c08854e: /* original 53f6, guest PC 0x0c08854e */
if(!s->budget--) { s->failed_pc=0x0c08854eu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c088550;
P_0c088550: /* original 6030, guest PC 0x0c088550 */
if(!s->budget--) { s->failed_pc=0x0c088550u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c088552;
P_0c088552: /* original c9fd, guest PC 0x0c088552 */
if(!s->budget--) { s->failed_pc=0x0c088552u; return 0; }
r[0]&=253u;
goto P_0c088554;
P_0c088554: /* original 2300, guest PC 0x0c088554 */
if(!s->budget--) { s->failed_pc=0x0c088554u; return 0; }
write(ram,r[3],r[0],1);
goto P_0c088556;
P_0c088556: /* original e008, guest PC 0x0c088556 */
if(!s->budget--) { s->failed_pc=0x0c088556u; return 0; }
r[0]=0x00000008u;
goto P_0c088558;
P_0c088558: /* original fe4c, guest PC 0x0c088558 */
if(!s->budget--) { s->failed_pc=0x0c088558u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c08855a;
P_0c08855a: /* original fe40, guest PC 0x0c08855a */
if(!s->budget--) { s->failed_pc=0x0c08855au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'+');
goto P_0c08855c;
P_0c08855c: /* original f368, guest PC 0x0c08855c */
if(!s->budget--) { s->failed_pc=0x0c08855cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c08855e;
P_0c08855e: /* original f3e2, guest PC 0x0c08855e */
if(!s->budget--) { s->failed_pc=0x0c08855eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c088560;
P_0c088560: /* original fe3a, guest PC 0x0c088560 */
if(!s->budget--) { s->failed_pc=0x0c088560u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c088562;
P_0c088562: /* original f266, guest PC 0x0c088562 */
if(!s->budget--) { s->failed_pc=0x0c088562u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c088564;
P_0c088564: /* original f2e2, guest PC 0x0c088564 */
if(!s->budget--) { s->failed_pc=0x0c088564u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c088566;
P_0c088566: /* original be39, guest PC 0x0c088566 */
if(!s->budget--) { s->failed_pc=0x0c088566u; return 0; }
target=0x0c0881dcu; r[16]=code_base|0x0c08856au;
vf3_matrix_store(s,ram,2,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08856au) { target=s->pc; goto dispatch; }
goto P_0c08856a;
P_0c088568: /* original fe27, guest PC 0x0c088568 */
if(!s->budget--) { s->failed_pc=0x0c088568u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c08856a;
P_0c08856a: /* original 640c, guest PC 0x0c08856a */
if(!s->budget--) { s->failed_pc=0x0c08856au; return 0; }
r[4]=r[0]&255u;
goto P_0c08856c;
P_0c08856c: /* original f0fc, guest PC 0x0c08856c */
if(!s->budget--) { s->failed_pc=0x0c08856cu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c08856e;
P_0c08856e: /* original 445a, guest PC 0x0c08856e */
if(!s->budget--) { s->failed_pc=0x0c08856eu; return 0; }
r[53]=r[4];
goto P_0c088570;
P_0c088570: /* original c713, guest PC 0x0c088570 */
if(!s->budget--) { s->failed_pc=0x0c088570u; return 0; }
r[0]=0x0c0885c0u;
goto P_0c088572;
P_0c088572: /* original f408, guest PC 0x0c088572 */
if(!s->budget--) { s->failed_pc=0x0c088572u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c088574;
P_0c088574: /* original e004, guest PC 0x0c088574 */
if(!s->budget--) { s->failed_pc=0x0c088574u; return 0; }
r[0]=0x00000004u;
goto P_0c088576;
P_0c088576: /* original f32d, guest PC 0x0c088576 */
if(!s->budget--) { s->failed_pc=0x0c088576u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c088578;
P_0c088578: /* original f53c, guest PC 0x0c088578 */
if(!s->budget--) { s->failed_pc=0x0c088578u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08857a;
P_0c08857a: /* original f452, guest PC 0x0c08857a */
if(!s->budget--) { s->failed_pc=0x0c08857au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c08857c;
P_0c08857c: /* original f3e6, guest PC 0x0c08857c */
if(!s->budget--) { s->failed_pc=0x0c08857cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08857e;
P_0c08857e: /* original e004, guest PC 0x0c08857e */
if(!s->budget--) { s->failed_pc=0x0c08857eu; return 0; }
r[0]=0x00000004u;
goto P_0c088580;
P_0c088580: /* original f4ee, guest PC 0x0c088580 */
if(!s->budget--) { s->failed_pc=0x0c088580u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[14],fr[4],r[18]);
goto P_0c088582;
P_0c088582: /* original f0f8, guest PC 0x0c088582 */
if(!s->budget--) { s->failed_pc=0x0c088582u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c088584;
P_0c088584: /* original f34e, guest PC 0x0c088584 */
if(!s->budget--) { s->failed_pc=0x0c088584u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c088586;
P_0c088586: /* original f3f5, guest PC 0x0c088586 */
if(!s->budget--) { s->failed_pc=0x0c088586u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c088588;
P_0c088588: /* original 8f01, guest PC 0x0c088588 */
if(!s->budget--) { s->failed_pc=0x0c088588u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[14]+r[0]);
if(!cond) { goto P_0c08858e; }
goto P_0c08858c;
P_0c08858a: /* original fe37, guest PC 0x0c08858a */
if(!s->budget--) { s->failed_pc=0x0c08858au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08858c;
P_0c08858c: /* original fef7, guest PC 0x0c08858c */
if(!s->budget--) { s->failed_pc=0x0c08858cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08858e;
P_0c08858e: /* original 52f8, guest PC 0x0c08858e */
if(!s->budget--) { s->failed_pc=0x0c08858eu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c088590;
P_0c088590: /* original 53f7, guest PC 0x0c088590 */
if(!s->budget--) { s->failed_pc=0x0c088590u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c088592;
P_0c088592: /* original 6120, guest PC 0x0c088592 */
if(!s->budget--) { s->failed_pc=0x0c088592u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c088594;
P_0c088594: /* original 4118, guest PC 0x0c088594 */
if(!s->budget--) { s->failed_pc=0x0c088594u; return 0; }
r[1]<<=8;
goto P_0c088596;
P_0c088596: /* original 4108, guest PC 0x0c088596 */
if(!s->budget--) { s->failed_pc=0x0c088596u; return 0; }
r[1]<<=2;
goto P_0c088598;
P_0c088598: /* original 4108, guest PC 0x0c088598 */
if(!s->budget--) { s->failed_pc=0x0c088598u; return 0; }
r[1]<<=2;
goto P_0c08859a;
P_0c08859a: /* original 2311, guest PC 0x0c08859a */
if(!s->budget--) { s->failed_pc=0x0c08859au; return 0; }
write(ram,r[3],r[1],2);
goto P_0c08859c;
P_0c08859c: /* original 7f04, guest PC 0x0c08859c */
if(!s->budget--) { s->failed_pc=0x0c08859cu; return 0; }
r[15]+=0x00000004u;
goto P_0c08859e;
P_0c08859e: /* original 4f26, guest PC 0x0c08859e */
if(!s->budget--) { s->failed_pc=0x0c08859eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0885a0;
P_0c0885a0: /* original fef9, guest PC 0x0c0885a0 */
if(!s->budget--) { s->failed_pc=0x0c0885a0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0885a2;
P_0c0885a2: /* original fff9, guest PC 0x0c0885a2 */
if(!s->budget--) { s->failed_pc=0x0c0885a2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0885a4;
P_0c0885a4: /* original 000b, guest PC 0x0c0885a4 */
if(!s->budget--) { s->failed_pc=0x0c0885a4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0885a6: /* original 6ef6, guest PC 0x0c0885a6 */
if(!s->budget--) { s->failed_pc=0x0c0885a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0885a8u,s,ram);
P_0c0885c4: /* original 2fe6, guest PC 0x0c0885c4 */
if(!s->budget--) { s->failed_pc=0x0c0885c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0885c6;
P_0c0885c6: /* original 6e53, guest PC 0x0c0885c6 */
if(!s->budget--) { s->failed_pc=0x0c0885c6u; return 0; }
r[14]=r[5];
goto P_0c0885c8;
P_0c0885c8: /* original 2fd6, guest PC 0x0c0885c8 */
if(!s->budget--) { s->failed_pc=0x0c0885c8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0885ca;
P_0c0885ca: /* original 2fc6, guest PC 0x0c0885ca */
if(!s->budget--) { s->failed_pc=0x0c0885cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0885cc;
P_0c0885cc: /* original 6c43, guest PC 0x0c0885cc */
if(!s->budget--) { s->failed_pc=0x0c0885ccu; return 0; }
r[12]=r[4];
goto P_0c0885ce;
P_0c0885ce: /* original 2fb6, guest PC 0x0c0885ce */
if(!s->budget--) { s->failed_pc=0x0c0885ceu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0885d0;
P_0c0885d0: /* original 6b73, guest PC 0x0c0885d0 */
if(!s->budget--) { s->failed_pc=0x0c0885d0u; return 0; }
r[11]=r[7];
goto P_0c0885d2;
P_0c0885d2: /* original 2fa6, guest PC 0x0c0885d2 */
if(!s->budget--) { s->failed_pc=0x0c0885d2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0885d4;
P_0c0885d4: /* original fffb, guest PC 0x0c0885d4 */
if(!s->budget--) { s->failed_pc=0x0c0885d4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0885d6;
P_0c0885d6: /* original ffeb, guest PC 0x0c0885d6 */
if(!s->budget--) { s->failed_pc=0x0c0885d6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0885d8;
P_0c0885d8: /* original 4f22, guest PC 0x0c0885d8 */
if(!s->budget--) { s->failed_pc=0x0c0885d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0885da;
P_0c0885da: /* original 60b0, guest PC 0x0c0885da */
if(!s->budget--) { s->failed_pc=0x0c0885dau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[0]=tmp;
goto P_0c0885dc;
P_0c0885dc: /* original 7ffc, guest PC 0x0c0885dc */
if(!s->budget--) { s->failed_pc=0x0c0885dcu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0885de;
P_0c0885de: /* original 5dfa, guest PC 0x0c0885de */
if(!s->budget--) { s->failed_pc=0x0c0885deu; return 0; }
r[13]=read(ram,r[15]+40,4);
goto P_0c0885e0;
P_0c0885e0: /* original c802, guest PC 0x0c0885e0 */
if(!s->budget--) { s->failed_pc=0x0c0885e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0885e2;
P_0c0885e2: /* original 8d02, guest PC 0x0c0885e2 */
if(!s->budget--) { s->failed_pc=0x0c0885e2u; return 0; }
cond=r[17]&1u;
r[10]=r[6];
if(cond) { goto P_0c0885ea; }
goto P_0c0885e6;
P_0c0885e4: /* original 6a63, guest PC 0x0c0885e4 */
if(!s->budget--) { s->failed_pc=0x0c0885e4u; return 0; }
r[10]=r[6];
goto P_0c0885e6;
P_0c0885e6: /* original a080, guest PC 0x0c0885e6 */
if(!s->budget--) { s->failed_pc=0x0c0885e6u; return 0; }
goto P_0c0886ea;
P_0c0885e8: /* original 0009, guest PC 0x0c0885e8 */
if(!s->budget--) { s->failed_pc=0x0c0885e8u; return 0; }
goto P_0c0885ea;
P_0c0885ea: /* original c779, guest PC 0x0c0885ea */
if(!s->budget--) { s->failed_pc=0x0c0885eau; return 0; }
r[0]=0x0c0887d0u;
goto P_0c0885ec;
P_0c0885ec: /* original ff08, guest PC 0x0c0885ec */
if(!s->budget--) { s->failed_pc=0x0c0885ecu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0885ee;
P_0c0885ee: /* original c779, guest PC 0x0c0885ee */
if(!s->budget--) { s->failed_pc=0x0c0885eeu; return 0; }
r[0]=0x0c0887d4u;
goto P_0c0885f0;
P_0c0885f0: /* original fe08, guest PC 0x0c0885f0 */
if(!s->budget--) { s->failed_pc=0x0c0885f0u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0885f2;
P_0c0885f2: /* original c779, guest PC 0x0c0885f2 */
if(!s->budget--) { s->failed_pc=0x0c0885f2u; return 0; }
r[0]=0x0c0887d8u;
goto P_0c0885f4;
P_0c0885f4: /* original f508, guest PC 0x0c0885f4 */
if(!s->budget--) { s->failed_pc=0x0c0885f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0885f6;
P_0c0885f6: /* original c779, guest PC 0x0c0885f6 */
if(!s->budget--) { s->failed_pc=0x0c0885f6u; return 0; }
r[0]=0x0c0887dcu;
goto P_0c0885f8;
P_0c0885f8: /* original f408, guest PC 0x0c0885f8 */
if(!s->budget--) { s->failed_pc=0x0c0885f8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0885fa;
P_0c0885fa: /* original c779, guest PC 0x0c0885fa */
if(!s->budget--) { s->failed_pc=0x0c0885fau; return 0; }
r[0]=0x0c0887e0u;
goto P_0c0885fc;
P_0c0885fc: /* original f308, guest PC 0x0c0885fc */
if(!s->budget--) { s->failed_pc=0x0c0885fcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0885fe;
P_0c0885fe: /* original ff3a, guest PC 0x0c0885fe */
if(!s->budget--) { s->failed_pc=0x0c0885feu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c088600;
P_0c088600: /* original 60b0, guest PC 0x0c088600 */
if(!s->budget--) { s->failed_pc=0x0c088600u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[0]=tmp;
goto P_0c088602;
P_0c088602: /* original c801, guest PC 0x0c088602 */
if(!s->budget--) { s->failed_pc=0x0c088602u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c088604;
P_0c088604: /* original 8947, guest PC 0x0c088604 */
if(!s->budget--) { s->failed_pc=0x0c088604u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088696; }
goto P_0c088606;
P_0c088606: /* original e004, guest PC 0x0c088606 */
if(!s->budget--) { s->failed_pc=0x0c088606u; return 0; }
r[0]=0x00000004u;
goto P_0c088608;
P_0c088608: /* original f3e6, guest PC 0x0c088608 */
if(!s->budget--) { s->failed_pc=0x0c088608u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08860a;
P_0c08860a: /* original f350, guest PC 0x0c08860a */
if(!s->budget--) { s->failed_pc=0x0c08860au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c08860c;
P_0c08860c: /* original f23c, guest PC 0x0c08860c */
if(!s->budget--) { s->failed_pc=0x0c08860cu; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c08860e;
P_0c08860e: /* original f425, guest PC 0x0c08860e */
if(!s->budget--) { s->failed_pc=0x0c08860eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c088610;
P_0c088610: /* original 8f01, guest PC 0x0c088610 */
if(!s->budget--) { s->failed_pc=0x0c088610u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[14]+r[0]);
if(!cond) { goto P_0c088616; }
goto P_0c088614;
P_0c088612: /* original fe37, guest PC 0x0c088612 */
if(!s->budget--) { s->failed_pc=0x0c088612u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c088614;
P_0c088614: /* original fe47, guest PC 0x0c088614 */
if(!s->budget--) { s->failed_pc=0x0c088614u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c088616;
P_0c088616: /* original 6103, guest PC 0x0c088616 */
if(!s->budget--) { s->failed_pc=0x0c088616u; return 0; }
r[1]=r[0];
goto P_0c088618;
P_0c088618: /* original 31ec, guest PC 0x0c088618 */
if(!s->budget--) { s->failed_pc=0x0c088618u; return 0; }
r[1]+=r[14];
goto P_0c08861a;
P_0c08861a: /* original f2c6, guest PC 0x0c08861a */
if(!s->budget--) { s->failed_pc=0x0c08861au; return 0; }
vf3_matrix_load(s,ram,2,r[12]+r[0]);
goto P_0c08861c;
P_0c08861c: /* original f318, guest PC 0x0c08861c */
if(!s->budget--) { s->failed_pc=0x0c08861cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c08861e;
P_0c08861e: /* original f230, guest PC 0x0c08861e */
if(!s->budget--) { s->failed_pc=0x0c08861eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c088620;
P_0c088620: /* original fc27, guest PC 0x0c088620 */
if(!s->budget--) { s->failed_pc=0x0c088620u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c088622;
P_0c088622: /* original e008, guest PC 0x0c088622 */
if(!s->budget--) { s->failed_pc=0x0c088622u; return 0; }
r[0]=0x00000008u;
goto P_0c088624;
P_0c088624: /* original f2c8, guest PC 0x0c088624 */
if(!s->budget--) { s->failed_pc=0x0c088624u; return 0; }
vf3_matrix_load(s,ram,2,r[12]);
goto P_0c088626;
P_0c088626: /* original 6103, guest PC 0x0c088626 */
if(!s->budget--) { s->failed_pc=0x0c088626u; return 0; }
r[1]=r[0];
goto P_0c088628;
P_0c088628: /* original f3e8, guest PC 0x0c088628 */
if(!s->budget--) { s->failed_pc=0x0c088628u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c08862a;
P_0c08862a: /* original 31ec, guest PC 0x0c08862a */
if(!s->budget--) { s->failed_pc=0x0c08862au; return 0; }
r[1]+=r[14];
goto P_0c08862c;
P_0c08862c: /* original f230, guest PC 0x0c08862c */
if(!s->budget--) { s->failed_pc=0x0c08862cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c08862e;
P_0c08862e: /* original fc2a, guest PC 0x0c08862e */
if(!s->budget--) { s->failed_pc=0x0c08862eu; return 0; }
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c088630;
P_0c088630: /* original f2c6, guest PC 0x0c088630 */
if(!s->budget--) { s->failed_pc=0x0c088630u; return 0; }
vf3_matrix_load(s,ram,2,r[12]+r[0]);
goto P_0c088632;
P_0c088632: /* original f318, guest PC 0x0c088632 */
if(!s->budget--) { s->failed_pc=0x0c088632u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c088634;
P_0c088634: /* original f231, guest PC 0x0c088634 */
if(!s->budget--) { s->failed_pc=0x0c088634u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c088636;
P_0c088636: /* original fc27, guest PC 0x0c088636 */
if(!s->budget--) { s->failed_pc=0x0c088636u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c088638;
P_0c088638: /* original d36a, guest PC 0x0c088638 */
if(!s->budget--) { s->failed_pc=0x0c088638u; return 0; }
r[3]=read(ram,0x0c0887e4u,4);
goto P_0c08863a;
P_0c08863a: /* original f52c, guest PC 0x0c08863a */
if(!s->budget--) { s->failed_pc=0x0c08863au; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c08863c;
P_0c08863c: /* original f54d, guest PC 0x0c08863c */
if(!s->budget--) { s->failed_pc=0x0c08863cu; return 0; }
fr[5]^=0x80000000u;
goto P_0c08863e;
P_0c08863e: /* original 430b, guest PC 0x0c08863e */
if(!s->budget--) { s->failed_pc=0x0c08863eu; return 0; }
target=r[3];
r[16]=code_base|0x0c088642u;
vf3_matrix_load(s,ram,4,r[12]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088642u) { target=s->pc; goto dispatch; }
goto P_0c088642;
P_0c088640: /* original f4c8, guest PC 0x0c088640 */
if(!s->budget--) { s->failed_pc=0x0c088640u; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c088642;
P_0c088642: /* original e008, guest PC 0x0c088642 */
if(!s->budget--) { s->failed_pc=0x0c088642u; return 0; }
r[0]=0x00000008u;
goto P_0c088644;
P_0c088644: /* original fa0a, guest PC 0x0c088644 */
if(!s->budget--) { s->failed_pc=0x0c088644u; return 0; }
vf3_matrix_store(s,ram,0,r[10]);
goto P_0c088646;
P_0c088646: /* original f3e8, guest PC 0x0c088646 */
if(!s->budget--) { s->failed_pc=0x0c088646u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c088648;
P_0c088648: /* original f3f2, guest PC 0x0c088648 */
if(!s->budget--) { s->failed_pc=0x0c088648u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c08864a;
P_0c08864a: /* original fe3a, guest PC 0x0c08864a */
if(!s->budget--) { s->failed_pc=0x0c08864au; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c08864c;
P_0c08864c: /* original f2e6, guest PC 0x0c08864c */
if(!s->budget--) { s->failed_pc=0x0c08864cu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c08864e;
P_0c08864e: /* original f2f2, guest PC 0x0c08864e */
if(!s->budget--) { s->failed_pc=0x0c08864eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'*');
goto P_0c088650;
P_0c088650: /* original fe27, guest PC 0x0c088650 */
if(!s->budget--) { s->failed_pc=0x0c088650u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c088652;
P_0c088652: /* original e004, guest PC 0x0c088652 */
if(!s->budget--) { s->failed_pc=0x0c088652u; return 0; }
r[0]=0x00000004u;
goto P_0c088654;
P_0c088654: /* original f2c6, guest PC 0x0c088654 */
if(!s->budget--) { s->failed_pc=0x0c088654u; return 0; }
vf3_matrix_load(s,ram,2,r[12]+r[0]);
goto P_0c088656;
P_0c088656: /* original f3a8, guest PC 0x0c088656 */
if(!s->budget--) { s->failed_pc=0x0c088656u; return 0; }
vf3_matrix_load(s,ram,3,r[10]);
goto P_0c088658;
P_0c088658: /* original f235, guest PC 0x0c088658 */
if(!s->budget--) { s->failed_pc=0x0c088658u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c08865a;
P_0c08865a: /* original 8b14, guest PC 0x0c08865a */
if(!s->budget--) { s->failed_pc=0x0c08865au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088686; }
goto P_0c08865c;
P_0c08865c: /* original 62d0, guest PC 0x0c08865c */
if(!s->budget--) { s->failed_pc=0x0c08865cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[2]=tmp;
goto P_0c08865e;
P_0c08865e: /* original 7201, guest PC 0x0c08865e */
if(!s->budget--) { s->failed_pc=0x0c08865eu; return 0; }
r[2]+=0x00000001u;
goto P_0c088660;
P_0c088660: /* original 2d20, guest PC 0x0c088660 */
if(!s->budget--) { s->failed_pc=0x0c088660u; return 0; }
write(ram,r[13],r[2],1);
goto P_0c088662;
P_0c088662: /* original e220, guest PC 0x0c088662 */
if(!s->budget--) { s->failed_pc=0x0c088662u; return 0; }
r[2]=0x00000020u;
goto P_0c088664;
P_0c088664: /* original 63d0, guest PC 0x0c088664 */
if(!s->budget--) { s->failed_pc=0x0c088664u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[3]=tmp;
goto P_0c088666;
P_0c088666: /* original 3327, guest PC 0x0c088666 */
if(!s->budget--) { s->failed_pc=0x0c088666u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c088668;
P_0c088668: /* original 8b01, guest PC 0x0c088668 */
if(!s->budget--) { s->failed_pc=0x0c088668u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08866e; }
goto P_0c08866a;
P_0c08866a: /* original e100, guest PC 0x0c08866a */
if(!s->budget--) { s->failed_pc=0x0c08866au; return 0; }
r[1]=0x00000000u;
goto P_0c08866c;
P_0c08866c: /* original 2d10, guest PC 0x0c08866c */
if(!s->budget--) { s->failed_pc=0x0c08866cu; return 0; }
write(ram,r[13],r[1],1);
goto P_0c08866e;
P_0c08866e: /* original f4e6, guest PC 0x0c08866e */
if(!s->budget--) { s->failed_pc=0x0c08866eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c088670;
P_0c088670: /* original f3f8, guest PC 0x0c088670 */
if(!s->budget--) { s->failed_pc=0x0c088670u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c088672;
P_0c088672: /* original f45d, guest PC 0x0c088672 */
if(!s->budget--) { s->failed_pc=0x0c088672u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c088674;
P_0c088674: /* original f432, guest PC 0x0c088674 */
if(!s->budget--) { s->failed_pc=0x0c088674u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c088676;
P_0c088676: /* original 53f9, guest PC 0x0c088676 */
if(!s->budget--) { s->failed_pc=0x0c088676u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c088678;
P_0c088678: /* original 6231, guest PC 0x0c088678 */
if(!s->budget--) { s->failed_pc=0x0c088678u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c08867a;
P_0c08867a: /* original f43d, guest PC 0x0c08867a */
if(!s->budget--) { s->failed_pc=0x0c08867au; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c08867c;
P_0c08867c: /* original 045a, guest PC 0x0c08867c */
if(!s->budget--) { s->failed_pc=0x0c08867cu; return 0; }
r[4]=r[53];
goto P_0c08867e;
P_0c08867e: /* original 324c, guest PC 0x0c08867e */
if(!s->budget--) { s->failed_pc=0x0c08867eu; return 0; }
r[2]+=r[4];
goto P_0c088680;
P_0c088680: /* original 2321, guest PC 0x0c088680 */
if(!s->budget--) { s->failed_pc=0x0c088680u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c088682;
P_0c088682: /* original a032, guest PC 0x0c088682 */
if(!s->budget--) { s->failed_pc=0x0c088682u; return 0; }
goto P_0c0886ea;
P_0c088684: /* original 0009, guest PC 0x0c088684 */
if(!s->budget--) { s->failed_pc=0x0c088684u; return 0; }
goto P_0c088686;
P_0c088686: /* original 60b0, guest PC 0x0c088686 */
if(!s->budget--) { s->failed_pc=0x0c088686u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[0]=tmp;
goto P_0c088688;
P_0c088688: /* original c9fe, guest PC 0x0c088688 */
if(!s->budget--) { s->failed_pc=0x0c088688u; return 0; }
r[0]&=254u;
goto P_0c08868a;
P_0c08868a: /* original 2b00, guest PC 0x0c08868a */
if(!s->budget--) { s->failed_pc=0x0c08868au; return 0; }
write(ram,r[11],r[0],1);
goto P_0c08868c;
P_0c08868c: /* original e004, guest PC 0x0c08868c */
if(!s->budget--) { s->failed_pc=0x0c08868cu; return 0; }
r[0]=0x00000004u;
goto P_0c08868e;
P_0c08868e: /* original f38d, guest PC 0x0c08868e */
if(!s->budget--) { s->failed_pc=0x0c08868eu; return 0; }
fr[3]=0;
goto P_0c088690;
P_0c088690: /* original fe37, guest PC 0x0c088690 */
if(!s->budget--) { s->failed_pc=0x0c088690u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c088692;
P_0c088692: /* original f3a8, guest PC 0x0c088692 */
if(!s->budget--) { s->failed_pc=0x0c088692u; return 0; }
vf3_matrix_load(s,ram,3,r[10]);
goto P_0c088694;
P_0c088694: /* original fc37, guest PC 0x0c088694 */
if(!s->budget--) { s->failed_pc=0x0c088694u; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c088696;
P_0c088696: /* original e008, guest PC 0x0c088696 */
if(!s->budget--) { s->failed_pc=0x0c088696u; return 0; }
r[0]=0x00000008u;
goto P_0c088698;
P_0c088698: /* original f3e8, guest PC 0x0c088698 */
if(!s->budget--) { s->failed_pc=0x0c088698u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c08869a;
P_0c08869a: /* original f3e2, guest PC 0x0c08869a */
if(!s->budget--) { s->failed_pc=0x0c08869au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c08869c;
P_0c08869c: /* original fe3a, guest PC 0x0c08869c */
if(!s->budget--) { s->failed_pc=0x0c08869cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c08869e;
P_0c08869e: /* original f2e6, guest PC 0x0c08869e */
if(!s->budget--) { s->failed_pc=0x0c08869eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0886a0;
P_0c0886a0: /* original f2e2, guest PC 0x0c0886a0 */
if(!s->budget--) { s->failed_pc=0x0c0886a0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c0886a2;
P_0c0886a2: /* original fe27, guest PC 0x0c0886a2 */
if(!s->budget--) { s->failed_pc=0x0c0886a2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0886a4;
P_0c0886a4: /* original 63d0, guest PC 0x0c0886a4 */
if(!s->budget--) { s->failed_pc=0x0c0886a4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[3]=tmp;
goto P_0c0886a6;
P_0c0886a6: /* original 2338, guest PC 0x0c0886a6 */
if(!s->budget--) { s->failed_pc=0x0c0886a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0886a8;
P_0c0886a8: /* original 8911, guest PC 0x0c0886a8 */
if(!s->budget--) { s->failed_pc=0x0c0886a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0886ce; }
goto P_0c0886aa;
P_0c0886aa: /* original 61d0, guest PC 0x0c0886aa */
if(!s->budget--) { s->failed_pc=0x0c0886aau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[1]=tmp;
goto P_0c0886ac;
P_0c0886ac: /* original e310, guest PC 0x0c0886ac */
if(!s->budget--) { s->failed_pc=0x0c0886acu; return 0; }
r[3]=0x00000010u;
goto P_0c0886ae;
P_0c0886ae: /* original 3133, guest PC 0x0c0886ae */
if(!s->budget--) { s->failed_pc=0x0c0886aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c0886b0;
P_0c0886b0: /* original 8903, guest PC 0x0c0886b0 */
if(!s->budget--) { s->failed_pc=0x0c0886b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0886ba; }
goto P_0c0886b2;
P_0c0886b2: /* original 61d0, guest PC 0x0c0886b2 */
if(!s->budget--) { s->failed_pc=0x0c0886b2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[1]=tmp;
goto P_0c0886b4;
P_0c0886b4: /* original 71ff, guest PC 0x0c0886b4 */
if(!s->budget--) { s->failed_pc=0x0c0886b4u; return 0; }
r[1]+=0xffffffffu;
goto P_0c0886b6;
P_0c0886b6: /* original a018, guest PC 0x0c0886b6 */
if(!s->budget--) { s->failed_pc=0x0c0886b6u; return 0; }
write(ram,r[13],r[1],1);
goto P_0c0886ea;
P_0c0886b8: /* original 2d10, guest PC 0x0c0886b8 */
if(!s->budget--) { s->failed_pc=0x0c0886b8u; return 0; }
write(ram,r[13],r[1],1);
goto P_0c0886ba;
P_0c0886ba: /* original 60d0, guest PC 0x0c0886ba */
if(!s->budget--) { s->failed_pc=0x0c0886bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[0]=tmp;
goto P_0c0886bc;
P_0c0886bc: /* original e120, guest PC 0x0c0886bc */
if(!s->budget--) { s->failed_pc=0x0c0886bcu; return 0; }
r[1]=0x00000020u;
goto P_0c0886be;
P_0c0886be: /* original 7001, guest PC 0x0c0886be */
if(!s->budget--) { s->failed_pc=0x0c0886beu; return 0; }
r[0]+=0x00000001u;
goto P_0c0886c0;
P_0c0886c0: /* original 2d00, guest PC 0x0c0886c0 */
if(!s->budget--) { s->failed_pc=0x0c0886c0u; return 0; }
write(ram,r[13],r[0],1);
goto P_0c0886c2;
P_0c0886c2: /* original 62d0, guest PC 0x0c0886c2 */
if(!s->budget--) { s->failed_pc=0x0c0886c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[2]=tmp;
goto P_0c0886c4;
P_0c0886c4: /* original 3217, guest PC 0x0c0886c4 */
if(!s->budget--) { s->failed_pc=0x0c0886c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[1])!=0);
goto P_0c0886c6;
P_0c0886c6: /* original 8b10, guest PC 0x0c0886c6 */
if(!s->budget--) { s->failed_pc=0x0c0886c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0886ea; }
goto P_0c0886c8;
P_0c0886c8: /* original e000, guest PC 0x0c0886c8 */
if(!s->budget--) { s->failed_pc=0x0c0886c8u; return 0; }
r[0]=0x00000000u;
goto P_0c0886ca;
P_0c0886ca: /* original a00e, guest PC 0x0c0886ca */
if(!s->budget--) { s->failed_pc=0x0c0886cau; return 0; }
write(ram,r[13],r[0],1);
goto P_0c0886ea;
P_0c0886cc: /* original 2d00, guest PC 0x0c0886cc */
if(!s->budget--) { s->failed_pc=0x0c0886ccu; return 0; }
write(ram,r[13],r[0],1);
goto P_0c0886ce;
P_0c0886ce: /* original 50f9, guest PC 0x0c0886ce */
if(!s->budget--) { s->failed_pc=0x0c0886ceu; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c0886d0;
P_0c0886d0: /* original e3f5, guest PC 0x0c0886d0 */
if(!s->budget--) { s->failed_pc=0x0c0886d0u; return 0; }
r[3]=0xfffffff5u;
goto P_0c0886d2;
P_0c0886d2: /* original 52fb, guest PC 0x0c0886d2 */
if(!s->budget--) { s->failed_pc=0x0c0886d2u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c0886d4;
P_0c0886d4: /* original 6001, guest PC 0x0c0886d4 */
if(!s->budget--) { s->failed_pc=0x0c0886d4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[0],2);
r[0]=tmp;
goto P_0c0886d6;
P_0c0886d6: /* original 403c, guest PC 0x0c0886d6 */
if(!s->budget--) { s->failed_pc=0x0c0886d6u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c0886d8;
P_0c0886d8: /* original c90f, guest PC 0x0c0886d8 */
if(!s->budget--) { s->failed_pc=0x0c0886d8u; return 0; }
r[0]&=15u;
goto P_0c0886da;
P_0c0886da: /* original 2200, guest PC 0x0c0886da */
if(!s->budget--) { s->failed_pc=0x0c0886dau; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0886dc;
P_0c0886dc: /* original 60b0, guest PC 0x0c0886dc */
if(!s->budget--) { s->failed_pc=0x0c0886dcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[0]=tmp;
goto P_0c0886de;
P_0c0886de: /* original cb02, guest PC 0x0c0886de */
if(!s->budget--) { s->failed_pc=0x0c0886deu; return 0; }
r[0]|=2u;
goto P_0c0886e0;
P_0c0886e0: /* original 2b00, guest PC 0x0c0886e0 */
if(!s->budget--) { s->failed_pc=0x0c0886e0u; return 0; }
write(ram,r[11],r[0],1);
goto P_0c0886e2;
P_0c0886e2: /* original e008, guest PC 0x0c0886e2 */
if(!s->budget--) { s->failed_pc=0x0c0886e2u; return 0; }
r[0]=0x00000008u;
goto P_0c0886e4;
P_0c0886e4: /* original f38d, guest PC 0x0c0886e4 */
if(!s->budget--) { s->failed_pc=0x0c0886e4u; return 0; }
fr[3]=0;
goto P_0c0886e6;
P_0c0886e6: /* original fe37, guest PC 0x0c0886e6 */
if(!s->budget--) { s->failed_pc=0x0c0886e6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0886e8;
P_0c0886e8: /* original fe3a, guest PC 0x0c0886e8 */
if(!s->budget--) { s->failed_pc=0x0c0886e8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0886ea;
P_0c0886ea: /* original 7f04, guest PC 0x0c0886ea */
if(!s->budget--) { s->failed_pc=0x0c0886eau; return 0; }
r[15]+=0x00000004u;
goto P_0c0886ec;
P_0c0886ec: /* original 4f26, guest PC 0x0c0886ec */
if(!s->budget--) { s->failed_pc=0x0c0886ecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0886ee;
P_0c0886ee: /* original fef9, guest PC 0x0c0886ee */
if(!s->budget--) { s->failed_pc=0x0c0886eeu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0886f0;
P_0c0886f0: /* original fff9, guest PC 0x0c0886f0 */
if(!s->budget--) { s->failed_pc=0x0c0886f0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0886f2;
P_0c0886f2: /* original 6af6, guest PC 0x0c0886f2 */
if(!s->budget--) { s->failed_pc=0x0c0886f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0886f4;
P_0c0886f4: /* original 6bf6, guest PC 0x0c0886f4 */
if(!s->budget--) { s->failed_pc=0x0c0886f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0886f6;
P_0c0886f6: /* original 6cf6, guest PC 0x0c0886f6 */
if(!s->budget--) { s->failed_pc=0x0c0886f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0886f8;
P_0c0886f8: /* original 6df6, guest PC 0x0c0886f8 */
if(!s->budget--) { s->failed_pc=0x0c0886f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0886fa;
P_0c0886fa: /* original 000b, guest PC 0x0c0886fa */
if(!s->budget--) { s->failed_pc=0x0c0886fau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0886fc: /* original 6ef6, guest PC 0x0c0886fc */
if(!s->budget--) { s->failed_pc=0x0c0886fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0886feu,s,ram);
P_0c08870a: /* original 4f22, guest PC 0x0c08870a */
if(!s->budget--) { s->failed_pc=0x0c08870au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08870c;
P_0c08870c: /* original 6403, guest PC 0x0c08870c */
if(!s->budget--) { s->failed_pc=0x0c08870cu; return 0; }
r[4]=r[0];
goto P_0c08870e;
P_0c08870e: /* original 4415, guest PC 0x0c08870e */
if(!s->budget--) { s->failed_pc=0x0c08870eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c088710;
P_0c088710: /* original 7fe4, guest PC 0x0c088710 */
if(!s->budget--) { s->failed_pc=0x0c088710u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c088712;
P_0c088712: /* original 8f04, guest PC 0x0c088712 */
if(!s->budget--) { s->failed_pc=0x0c088712u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(!cond) { goto P_0c08871e; }
goto P_0c088716;
P_0c088714: /* original 6e53, guest PC 0x0c088714 */
if(!s->budget--) { s->failed_pc=0x0c088714u; return 0; }
r[14]=r[5];
goto P_0c088716;
P_0c088716: /* original 74ff, guest PC 0x0c088716 */
if(!s->budget--) { s->failed_pc=0x0c088716u; return 0; }
r[4]+=0xffffffffu;
goto P_0c088718;
P_0c088718: /* original 6043, guest PC 0x0c088718 */
if(!s->budget--) { s->failed_pc=0x0c088718u; return 0; }
r[0]=r[4];
goto P_0c08871a;
P_0c08871a: /* original a051, guest PC 0x0c08871a */
if(!s->budget--) { s->failed_pc=0x0c08871au; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c0887c0;
P_0c08871c: /* original 80d1, guest PC 0x0c08871c */
if(!s->budget--) { s->failed_pc=0x0c08871cu; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c08871e;
P_0c08871e: /* original e008, guest PC 0x0c08871e */
if(!s->budget--) { s->failed_pc=0x0c08871eu; return 0; }
r[0]=0x00000008u;
goto P_0c088720;
P_0c088720: /* original f38d, guest PC 0x0c088720 */
if(!s->budget--) { s->failed_pc=0x0c088720u; return 0; }
fr[3]=0;
goto P_0c088722;
P_0c088722: /* original ffd6, guest PC 0x0c088722 */
if(!s->budget--) { s->failed_pc=0x0c088722u; return 0; }
vf3_matrix_load(s,ram,15,r[13]+r[0]);
goto P_0c088724;
P_0c088724: /* original ff34, guest PC 0x0c088724 */
if(!s->budget--) { s->failed_pc=0x0c088724u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[3]))!=0);
goto P_0c088726;
P_0c088726: /* original 8917, guest PC 0x0c088726 */
if(!s->budget--) { s->failed_pc=0x0c088726u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088758; }
goto P_0c088728;
P_0c088728: /* original e00c, guest PC 0x0c088728 */
if(!s->budget--) { s->failed_pc=0x0c088728u; return 0; }
r[0]=0x0000000cu;
goto P_0c08872a;
P_0c08872a: /* original f2d6, guest PC 0x0c08872a */
if(!s->budget--) { s->failed_pc=0x0c08872au; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c08872c;
P_0c08872c: /* original e010, guest PC 0x0c08872c */
if(!s->budget--) { s->failed_pc=0x0c08872cu; return 0; }
r[0]=0x00000010u;
goto P_0c08872e;
P_0c08872e: /* original ff27, guest PC 0x0c08872e */
if(!s->budget--) { s->failed_pc=0x0c08872eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c088730;
P_0c088730: /* original e010, guest PC 0x0c088730 */
if(!s->budget--) { s->failed_pc=0x0c088730u; return 0; }
r[0]=0x00000010u;
goto P_0c088732;
P_0c088732: /* original f2d6, guest PC 0x0c088732 */
if(!s->budget--) { s->failed_pc=0x0c088732u; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c088734;
P_0c088734: /* original e014, guest PC 0x0c088734 */
if(!s->budget--) { s->failed_pc=0x0c088734u; return 0; }
r[0]=0x00000014u;
goto P_0c088736;
P_0c088736: /* original ff27, guest PC 0x0c088736 */
if(!s->budget--) { s->failed_pc=0x0c088736u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c088738;
P_0c088738: /* original e014, guest PC 0x0c088738 */
if(!s->budget--) { s->failed_pc=0x0c088738u; return 0; }
r[0]=0x00000014u;
goto P_0c08873a;
P_0c08873a: /* original f2d6, guest PC 0x0c08873a */
if(!s->budget--) { s->failed_pc=0x0c08873au; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c08873c;
P_0c08873c: /* original e018, guest PC 0x0c08873c */
if(!s->budget--) { s->failed_pc=0x0c08873cu; return 0; }
r[0]=0x00000018u;
goto P_0c08873e;
P_0c08873e: /* original ff27, guest PC 0x0c08873e */
if(!s->budget--) { s->failed_pc=0x0c08873eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c088740;
P_0c088740: /* original e018, guest PC 0x0c088740 */
if(!s->budget--) { s->failed_pc=0x0c088740u; return 0; }
r[0]=0x00000018u;
goto P_0c088742;
P_0c088742: /* original f2d6, guest PC 0x0c088742 */
if(!s->budget--) { s->failed_pc=0x0c088742u; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c088744;
P_0c088744: /* original e004, guest PC 0x0c088744 */
if(!s->budget--) { s->failed_pc=0x0c088744u; return 0; }
r[0]=0x00000004u;
goto P_0c088746;
P_0c088746: /* original ff27, guest PC 0x0c088746 */
if(!s->budget--) { s->failed_pc=0x0c088746u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c088748;
P_0c088748: /* original e01c, guest PC 0x0c088748 */
if(!s->budget--) { s->failed_pc=0x0c088748u; return 0; }
r[0]=0x0000001cu;
goto P_0c08874a;
P_0c08874a: /* original f2d6, guest PC 0x0c08874a */
if(!s->budget--) { s->failed_pc=0x0c08874au; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c08874c;
P_0c08874c: /* original e008, guest PC 0x0c08874c */
if(!s->budget--) { s->failed_pc=0x0c08874cu; return 0; }
r[0]=0x00000008u;
goto P_0c08874e;
P_0c08874e: /* original ff27, guest PC 0x0c08874e */
if(!s->budget--) { s->failed_pc=0x0c08874eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c088750;
P_0c088750: /* original e020, guest PC 0x0c088750 */
if(!s->budget--) { s->failed_pc=0x0c088750u; return 0; }
r[0]=0x00000020u;
goto P_0c088752;
P_0c088752: /* original f2d6, guest PC 0x0c088752 */
if(!s->budget--) { s->failed_pc=0x0c088752u; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c088754;
P_0c088754: /* original e00c, guest PC 0x0c088754 */
if(!s->budget--) { s->failed_pc=0x0c088754u; return 0; }
r[0]=0x0000000cu;
goto P_0c088756;
P_0c088756: /* original ff27, guest PC 0x0c088756 */
if(!s->budget--) { s->failed_pc=0x0c088756u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c088758;
P_0c088758: /* original e024, guest PC 0x0c088758 */
if(!s->budget--) { s->failed_pc=0x0c088758u; return 0; }
r[0]=0x00000024u;
goto P_0c08875a;
P_0c08875a: /* original f3d6, guest PC 0x0c08875a */
if(!s->budget--) { s->failed_pc=0x0c08875au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08875c;
P_0c08875c: /* original ff3a, guest PC 0x0c08875c */
if(!s->budget--) { s->failed_pc=0x0c08875cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08875e;
P_0c08875e: /* original a02d, guest PC 0x0c08875e */
if(!s->budget--) { s->failed_pc=0x0c08875eu; return 0; }
r[12]=read(ram,r[13]+40,4);
goto P_0c0887bc;
P_0c088760: /* original 5cda, guest PC 0x0c088760 */
if(!s->budget--) { s->failed_pc=0x0c088760u; return 0; }
r[12]=read(ram,r[13]+40,4);
goto P_0c088762;
P_0c088762: /* original f38d, guest PC 0x0c088762 */
if(!s->budget--) { s->failed_pc=0x0c088762u; return 0; }
fr[3]=0;
goto P_0c088764;
P_0c088764: /* original ff34, guest PC 0x0c088764 */
if(!s->budget--) { s->failed_pc=0x0c088764u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[3]))!=0);
goto P_0c088766;
P_0c088766: /* original 8915, guest PC 0x0c088766 */
if(!s->budget--) { s->failed_pc=0x0c088766u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088794; }
goto P_0c088768;
P_0c088768: /* original 62e3, guest PC 0x0c088768 */
if(!s->budget--) { s->failed_pc=0x0c088768u; return 0; }
r[2]=r[14];
goto P_0c08876a;
P_0c08876a: /* original 7220, guest PC 0x0c08876a */
if(!s->budget--) { s->failed_pc=0x0c08876au; return 0; }
r[2]+=0x00000020u;
goto P_0c08876c;
P_0c08876c: /* original 63e3, guest PC 0x0c08876c */
if(!s->budget--) { s->failed_pc=0x0c08876cu; return 0; }
r[3]=r[14];
goto P_0c08876e;
P_0c08876e: /* original 2f26, guest PC 0x0c08876e */
if(!s->budget--) { s->failed_pc=0x0c08876eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088770;
P_0c088770: /* original 62e3, guest PC 0x0c088770 */
if(!s->budget--) { s->failed_pc=0x0c088770u; return 0; }
r[2]=r[14];
goto P_0c088772;
P_0c088772: /* original 731c, guest PC 0x0c088772 */
if(!s->budget--) { s->failed_pc=0x0c088772u; return 0; }
r[3]+=0x0000001cu;
goto P_0c088774;
P_0c088774: /* original 7223, guest PC 0x0c088774 */
if(!s->budget--) { s->failed_pc=0x0c088774u; return 0; }
r[2]+=0x00000023u;
goto P_0c088776;
P_0c088776: /* original 2f36, guest PC 0x0c088776 */
if(!s->budget--) { s->failed_pc=0x0c088776u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088778;
P_0c088778: /* original 2f26, guest PC 0x0c088778 */
if(!s->budget--) { s->failed_pc=0x0c088778u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08877a;
P_0c08877a: /* original e010, guest PC 0x0c08877a */
if(!s->budget--) { s->failed_pc=0x0c08877au; return 0; }
r[0]=0x00000010u;
goto P_0c08877c;
P_0c08877c: /* original 63f3, guest PC 0x0c08877c */
if(!s->budget--) { s->failed_pc=0x0c08877cu; return 0; }
r[3]=r[15];
goto P_0c08877e;
P_0c08877e: /* original 7310, guest PC 0x0c08877e */
if(!s->budget--) { s->failed_pc=0x0c08877eu; return 0; }
r[3]+=0x00000010u;
goto P_0c088780;
P_0c088780: /* original 2f36, guest PC 0x0c088780 */
if(!s->budget--) { s->failed_pc=0x0c088780u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088782;
P_0c088782: /* original 66e3, guest PC 0x0c088782 */
if(!s->budget--) { s->failed_pc=0x0c088782u; return 0; }
r[6]=r[14];
goto P_0c088784;
P_0c088784: /* original 67f3, guest PC 0x0c088784 */
if(!s->budget--) { s->failed_pc=0x0c088784u; return 0; }
r[7]=r[15];
goto P_0c088786;
P_0c088786: /* original f4f6, guest PC 0x0c088786 */
if(!s->budget--) { s->failed_pc=0x0c088786u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c088788;
P_0c088788: /* original 65e3, guest PC 0x0c088788 */
if(!s->budget--) { s->failed_pc=0x0c088788u; return 0; }
r[5]=r[14];
goto P_0c08878a;
P_0c08878a: /* original 760c, guest PC 0x0c08878a */
if(!s->budget--) { s->failed_pc=0x0c08878au; return 0; }
r[6]+=0x0000000cu;
goto P_0c08878c;
P_0c08878c: /* original 7720, guest PC 0x0c08878c */
if(!s->budget--) { s->failed_pc=0x0c08878cu; return 0; }
r[7]+=0x00000020u;
goto P_0c08878e;
P_0c08878e: /* original be9f, guest PC 0x0c08878e */
if(!s->budget--) { s->failed_pc=0x0c08878eu; return 0; }
target=0x0c0884d0u; r[16]=code_base|0x0c088792u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088792u) { target=s->pc; goto dispatch; }
goto P_0c088792;
P_0c088790: /* original 64d3, guest PC 0x0c088790 */
if(!s->budget--) { s->failed_pc=0x0c088790u; return 0; }
r[4]=r[13];
goto P_0c088792;
P_0c088792: /* original 7f10, guest PC 0x0c088792 */
if(!s->budget--) { s->failed_pc=0x0c088792u; return 0; }
r[15]+=0x00000010u;
goto P_0c088794;
P_0c088794: /* original 62e3, guest PC 0x0c088794 */
if(!s->budget--) { s->failed_pc=0x0c088794u; return 0; }
r[2]=r[14];
goto P_0c088796;
P_0c088796: /* original 7220, guest PC 0x0c088796 */
if(!s->budget--) { s->failed_pc=0x0c088796u; return 0; }
r[2]+=0x00000020u;
goto P_0c088798;
P_0c088798: /* original 63e3, guest PC 0x0c088798 */
if(!s->budget--) { s->failed_pc=0x0c088798u; return 0; }
r[3]=r[14];
goto P_0c08879a;
P_0c08879a: /* original 2f26, guest PC 0x0c08879a */
if(!s->budget--) { s->failed_pc=0x0c08879au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08879c;
P_0c08879c: /* original 62e3, guest PC 0x0c08879c */
if(!s->budget--) { s->failed_pc=0x0c08879cu; return 0; }
r[2]=r[14];
goto P_0c08879e;
P_0c08879e: /* original 7321, guest PC 0x0c08879e */
if(!s->budget--) { s->failed_pc=0x0c08879eu; return 0; }
r[3]+=0x00000021u;
goto P_0c0887a0;
P_0c0887a0: /* original 721c, guest PC 0x0c0887a0 */
if(!s->budget--) { s->failed_pc=0x0c0887a0u; return 0; }
r[2]+=0x0000001cu;
goto P_0c0887a2;
P_0c0887a2: /* original 2f36, guest PC 0x0c0887a2 */
if(!s->budget--) { s->failed_pc=0x0c0887a2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0887a4;
P_0c0887a4: /* original 2f26, guest PC 0x0c0887a4 */
if(!s->budget--) { s->failed_pc=0x0c0887a4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0887a6;
P_0c0887a6: /* original 65e3, guest PC 0x0c0887a6 */
if(!s->budget--) { s->failed_pc=0x0c0887a6u; return 0; }
r[5]=r[14];
goto P_0c0887a8;
P_0c0887a8: /* original 66f3, guest PC 0x0c0887a8 */
if(!s->budget--) { s->failed_pc=0x0c0887a8u; return 0; }
r[6]=r[15];
goto P_0c0887aa;
P_0c0887aa: /* original 67e3, guest PC 0x0c0887aa */
if(!s->budget--) { s->failed_pc=0x0c0887aau; return 0; }
r[7]=r[14];
goto P_0c0887ac;
P_0c0887ac: /* original 750c, guest PC 0x0c0887ac */
if(!s->budget--) { s->failed_pc=0x0c0887acu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0887ae;
P_0c0887ae: /* original 7723, guest PC 0x0c0887ae */
if(!s->budget--) { s->failed_pc=0x0c0887aeu; return 0; }
r[7]+=0x00000023u;
goto P_0c0887b0;
P_0c0887b0: /* original 760c, guest PC 0x0c0887b0 */
if(!s->budget--) { s->failed_pc=0x0c0887b0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0887b2;
P_0c0887b2: /* original bf07, guest PC 0x0c0887b2 */
if(!s->budget--) { s->failed_pc=0x0c0887b2u; return 0; }
target=0x0c0885c4u; r[16]=code_base|0x0c0887b6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0887b6u) { target=s->pc; goto dispatch; }
goto P_0c0887b6;
P_0c0887b4: /* original 64e3, guest PC 0x0c0887b4 */
if(!s->budget--) { s->failed_pc=0x0c0887b4u; return 0; }
r[4]=r[14];
goto P_0c0887b6;
P_0c0887b6: /* original 7cff, guest PC 0x0c0887b6 */
if(!s->budget--) { s->failed_pc=0x0c0887b6u; return 0; }
r[12]+=0xffffffffu;
goto P_0c0887b8;
P_0c0887b8: /* original 7e24, guest PC 0x0c0887b8 */
if(!s->budget--) { s->failed_pc=0x0c0887b8u; return 0; }
r[14]+=0x00000024u;
goto P_0c0887ba;
P_0c0887ba: /* original 7f0c, guest PC 0x0c0887ba */
if(!s->budget--) { s->failed_pc=0x0c0887bau; return 0; }
r[15]+=0x0000000cu;
goto P_0c0887bc;
P_0c0887bc: /* original 2cc8, guest PC 0x0c0887bc */
if(!s->budget--) { s->failed_pc=0x0c0887bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0887be;
P_0c0887be: /* original 8bd0, guest PC 0x0c0887be */
if(!s->budget--) { s->failed_pc=0x0c0887beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088762; }
goto P_0c0887c0;
P_0c0887c0: /* original 7f1c, guest PC 0x0c0887c0 */
if(!s->budget--) { s->failed_pc=0x0c0887c0u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0887c2;
P_0c0887c2: /* original 4f26, guest PC 0x0c0887c2 */
if(!s->budget--) { s->failed_pc=0x0c0887c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0887c4;
P_0c0887c4: /* original fff9, guest PC 0x0c0887c4 */
if(!s->budget--) { s->failed_pc=0x0c0887c4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0887c6;
P_0c0887c6: /* original 6cf6, guest PC 0x0c0887c6 */
if(!s->budget--) { s->failed_pc=0x0c0887c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0887c8;
P_0c0887c8: /* original 6df6, guest PC 0x0c0887c8 */
if(!s->budget--) { s->failed_pc=0x0c0887c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0887ca;
P_0c0887ca: /* original 000b, guest PC 0x0c0887ca */
if(!s->budget--) { s->failed_pc=0x0c0887cau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0887cc: /* original 6ef6, guest PC 0x0c0887cc */
if(!s->budget--) { s->failed_pc=0x0c0887ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0887ceu,s,ram);
P_0c088b5c: /* original 4f22, guest PC 0x0c088b5c */
if(!s->budget--) { s->failed_pc=0x0c088b5cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088b5e;
P_0c088b5e: /* original d32d, guest PC 0x0c088b5e */
if(!s->budget--) { s->failed_pc=0x0c088b5eu; return 0; }
r[3]=read(ram,0x0c088c14u,4);
goto P_0c088b60;
P_0c088b60: /* original 7fec, guest PC 0x0c088b60 */
if(!s->budget--) { s->failed_pc=0x0c088b60u; return 0; }
r[15]+=0xffffffecu;
goto P_0c088b62;
P_0c088b62: /* original 2f32, guest PC 0x0c088b62 */
if(!s->budget--) { s->failed_pc=0x0c088b62u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c088b64;
P_0c088b64: /* original d32d, guest PC 0x0c088b64 */
if(!s->budget--) { s->failed_pc=0x0c088b64u; return 0; }
r[3]=read(ram,0x0c088c1cu,4);
goto P_0c088b66;
P_0c088b66: /* original dd2c, guest PC 0x0c088b66 */
if(!s->budget--) { s->failed_pc=0x0c088b66u; return 0; }
r[13]=read(ram,0x0c088c18u,4);
goto P_0c088b68;
P_0c088b68: /* original 1f34, guest PC 0x0c088b68 */
if(!s->budget--) { s->failed_pc=0x0c088b68u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c088b6a;
P_0c088b6a: /* original 1f22, guest PC 0x0c088b6a */
if(!s->budget--) { s->failed_pc=0x0c088b6au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c088b6c;
P_0c088b6c: /* original 8543, guest PC 0x0c088b6c */
if(!s->budget--) { s->failed_pc=0x0c088b6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c088b6e;
P_0c088b6e: /* original 81f6, guest PC 0x0c088b6e */
if(!s->budget--) { s->failed_pc=0x0c088b6eu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c088b70;
P_0c088b70: /* original e001, guest PC 0x0c088b70 */
if(!s->budget--) { s->failed_pc=0x0c088b70u; return 0; }
r[0]=0x00000001u;
goto P_0c088b72;
P_0c088b72: /* original 81f2, guest PC 0x0c088b72 */
if(!s->budget--) { s->failed_pc=0x0c088b72u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088b74;
P_0c088b74: /* original d32a, guest PC 0x0c088b74 */
if(!s->budget--) { s->failed_pc=0x0c088b74u; return 0; }
r[3]=read(ram,0x0c088c20u,4);
goto P_0c088b76;
P_0c088b76: /* original 430b, guest PC 0x0c088b76 */
if(!s->budget--) { s->failed_pc=0x0c088b76u; return 0; }
target=r[3];
r[16]=code_base|0x0c088b7au;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088b7au) { target=s->pc; goto dispatch; }
goto P_0c088b7a;
P_0c088b78: /* original e400, guest PC 0x0c088b78 */
if(!s->budget--) { s->failed_pc=0x0c088b78u; return 0; }
r[4]=0x00000000u;
goto P_0c088b7a;
P_0c088b7a: /* original dc2c, guest PC 0x0c088b7a */
if(!s->budget--) { s->failed_pc=0x0c088b7au; return 0; }
r[12]=read(ram,0x0c088c2cu,4);
goto P_0c088b7c;
P_0c088b7c: /* original e80e, guest PC 0x0c088b7c */
if(!s->budget--) { s->failed_pc=0x0c088b7cu; return 0; }
r[8]=0x0000000eu;
goto P_0c088b7e;
P_0c088b7e: /* original db2a, guest PC 0x0c088b7e */
if(!s->budget--) { s->failed_pc=0x0c088b7eu; return 0; }
r[11]=read(ram,0x0c088c28u,4);
goto P_0c088b80;
P_0c088b80: /* original da28, guest PC 0x0c088b80 */
if(!s->budget--) { s->failed_pc=0x0c088b80u; return 0; }
r[10]=read(ram,0x0c088c24u,4);
goto P_0c088b82;
P_0c088b82: /* original 85f6, guest PC 0x0c088b82 */
if(!s->budget--) { s->failed_pc=0x0c088b82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c088b84;
P_0c088b84: /* original fed9, guest PC 0x0c088b84 */
if(!s->budget--) { s->failed_pc=0x0c088b84u; return 0; }
vf3_matrix_load(s,ram,14,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c088b86;
P_0c088b86: /* original 600d, guest PC 0x0c088b86 */
if(!s->budget--) { s->failed_pc=0x0c088b86u; return 0; }
r[0]=r[0]&65535u;
goto P_0c088b88;
P_0c088b88: /* original fdd9, guest PC 0x0c088b88 */
if(!s->budget--) { s->failed_pc=0x0c088b88u; return 0; }
vf3_matrix_load(s,ram,13,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c088b8a;
P_0c088b8a: /* original 6303, guest PC 0x0c088b8a */
if(!s->budget--) { s->failed_pc=0x0c088b8au; return 0; }
r[3]=r[0];
goto P_0c088b8c;
P_0c088b8c: /* original 85f2, guest PC 0x0c088b8c */
if(!s->budget--) { s->failed_pc=0x0c088b8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088b8e;
P_0c088b8e: /* original f4d9, guest PC 0x0c088b8e */
if(!s->budget--) { s->failed_pc=0x0c088b8eu; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c088b90;
P_0c088b90: /* original 600d, guest PC 0x0c088b90 */
if(!s->budget--) { s->failed_pc=0x0c088b90u; return 0; }
r[0]=r[0]&65535u;
goto P_0c088b92;
P_0c088b92: /* original 2308, guest PC 0x0c088b92 */
if(!s->budget--) { s->failed_pc=0x0c088b92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[0])==0)!=0);
goto P_0c088b94;
P_0c088b94: /* original ff4c, guest PC 0x0c088b94 */
if(!s->budget--) { s->failed_pc=0x0c088b94u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c088b96;
P_0c088b96: /* original 8d02, guest PC 0x0c088b96 */
if(!s->budget--) { s->failed_pc=0x0c088b96u; return 0; }
cond=r[17]&1u;
fr[15]^=0x80000000u;
if(cond) { goto P_0c088b9e; }
goto P_0c088b9a;
P_0c088b98: /* original ff4d, guest PC 0x0c088b98 */
if(!s->budget--) { s->failed_pc=0x0c088b98u; return 0; }
fr[15]^=0x80000000u;
goto P_0c088b9a;
P_0c088b9a: /* original a002, guest PC 0x0c088b9a */
if(!s->budget--) { s->failed_pc=0x0c088b9au; return 0; }
r[14]=0x00000010u;
goto P_0c088ba2;
P_0c088b9c: /* original ee10, guest PC 0x0c088b9c */
if(!s->budget--) { s->failed_pc=0x0c088b9cu; return 0; }
r[14]=0x00000010u;
goto P_0c088b9e;
P_0c088b9e: /* original 5ef2, guest PC 0x0c088b9e */
if(!s->budget--) { s->failed_pc=0x0c088b9eu; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c088ba0;
P_0c088ba0: /* original 6ee1, guest PC 0x0c088ba0 */
if(!s->budget--) { s->failed_pc=0x0c088ba0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]=tmp;
goto P_0c088ba2;
P_0c088ba2: /* original 69f2, guest PC 0x0c088ba2 */
if(!s->budget--) { s->failed_pc=0x0c088ba2u; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c088ba4;
P_0c088ba4: /* original 60ef, guest PC 0x0c088ba4 */
if(!s->budget--) { s->failed_pc=0x0c088ba4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c088ba6;
P_0c088ba6: /* original 8810, guest PC 0x0c088ba6 */
if(!s->budget--) { s->failed_pc=0x0c088ba6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c088ba8;
P_0c088ba8: /* original 7902, guest PC 0x0c088ba8 */
if(!s->budget--) { s->failed_pc=0x0c088ba8u; return 0; }
r[9]+=0x00000002u;
goto P_0c088baa;
P_0c088baa: /* original 2f92, guest PC 0x0c088baa */
if(!s->budget--) { s->failed_pc=0x0c088baau; return 0; }
write(ram,r[15],r[9],4);
goto P_0c088bac;
P_0c088bac: /* original 79fe, guest PC 0x0c088bac */
if(!s->budget--) { s->failed_pc=0x0c088bacu; return 0; }
r[9]+=0xfffffffeu;
goto P_0c088bae;
P_0c088bae: /* original 64f2, guest PC 0x0c088bae */
if(!s->budget--) { s->failed_pc=0x0c088baeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c088bb0;
P_0c088bb0: /* original 6991, guest PC 0x0c088bb0 */
if(!s->budget--) { s->failed_pc=0x0c088bb0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[9],2);
r[9]=tmp;
goto P_0c088bb2;
P_0c088bb2: /* original 7402, guest PC 0x0c088bb2 */
if(!s->budget--) { s->failed_pc=0x0c088bb2u; return 0; }
r[4]+=0x00000002u;
goto P_0c088bb4;
P_0c088bb4: /* original 2f42, guest PC 0x0c088bb4 */
if(!s->budget--) { s->failed_pc=0x0c088bb4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c088bb6;
P_0c088bb6: /* original 74fe, guest PC 0x0c088bb6 */
if(!s->budget--) { s->failed_pc=0x0c088bb6u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c088bb8;
P_0c088bb8: /* original 8f01, guest PC 0x0c088bb8 */
if(!s->budget--) { s->failed_pc=0x0c088bb8u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
if(!cond) { goto P_0c088bbe; }
goto P_0c088bbc;
P_0c088bba: /* original 6441, guest PC 0x0c088bba */
if(!s->budget--) { s->failed_pc=0x0c088bbau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c088bbc;
P_0c088bbc: /* original 6943, guest PC 0x0c088bbc */
if(!s->budget--) { s->failed_pc=0x0c088bbcu; return 0; }
r[9]=r[4];
goto P_0c088bbe;
P_0c088bbe: /* original 4a0b, guest PC 0x0c088bbe */
if(!s->budget--) { s->failed_pc=0x0c088bbeu; return 0; }
target=r[10];
r[16]=code_base|0x0c088bc2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088bc2u) { target=s->pc; goto dispatch; }
goto P_0c088bc2;
P_0c088bc0: /* original 0009, guest PC 0x0c088bc0 */
if(!s->budget--) { s->failed_pc=0x0c088bc0u; return 0; }
goto P_0c088bc2;
P_0c088bc2: /* original f5dc, guest PC 0x0c088bc2 */
if(!s->budget--) { s->failed_pc=0x0c088bc2u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088bc4;
P_0c088bc4: /* original f6fc, guest PC 0x0c088bc4 */
if(!s->budget--) { s->failed_pc=0x0c088bc4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c088bc6;
P_0c088bc6: /* original 4b0b, guest PC 0x0c088bc6 */
if(!s->budget--) { s->failed_pc=0x0c088bc6u; return 0; }
target=r[11];
r[16]=code_base|0x0c088bcau;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088bcau) { target=s->pc; goto dispatch; }
goto P_0c088bca;
P_0c088bc8: /* original f4ec, guest PC 0x0c088bc8 */
if(!s->budget--) { s->failed_pc=0x0c088bc8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088bca;
P_0c088bca: /* original 4c0b, guest PC 0x0c088bca */
if(!s->budget--) { s->failed_pc=0x0c088bcau; return 0; }
target=r[12];
r[16]=code_base|0x0c088bceu;
r[4]=(uint32_t)(int32_t)(int16_t)r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088bceu) { target=s->pc; goto dispatch; }
goto P_0c088bce;
P_0c088bcc: /* original 649f, guest PC 0x0c088bcc */
if(!s->budget--) { s->failed_pc=0x0c088bccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c088bce;
P_0c088bce: /* original 50f4, guest PC 0x0c088bce */
if(!s->budget--) { s->failed_pc=0x0c088bceu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c088bd0;
P_0c088bd0: /* original 6eef, guest PC 0x0c088bd0 */
if(!s->budget--) { s->failed_pc=0x0c088bd0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c088bd2;
P_0c088bd2: /* original 4e00, guest PC 0x0c088bd2 */
if(!s->budget--) { s->failed_pc=0x0c088bd2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c088bd4;
P_0c088bd4: /* original 4a0b, guest PC 0x0c088bd4 */
if(!s->budget--) { s->failed_pc=0x0c088bd4u; return 0; }
target=r[10];
r[16]=code_base|0x0c088bd8u;
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088bd8u) { target=s->pc; goto dispatch; }
goto P_0c088bd8;
P_0c088bd6: /* original 0eed, guest PC 0x0c088bd6 */
if(!s->budget--) { s->failed_pc=0x0c088bd6u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c088bd8;
P_0c088bd8: /* original f5dc, guest PC 0x0c088bd8 */
if(!s->budget--) { s->failed_pc=0x0c088bd8u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088bda;
P_0c088bda: /* original f6fc, guest PC 0x0c088bda */
if(!s->budget--) { s->failed_pc=0x0c088bdau; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c088bdc;
P_0c088bdc: /* original 4b0b, guest PC 0x0c088bdc */
if(!s->budget--) { s->failed_pc=0x0c088bdcu; return 0; }
target=r[11];
r[16]=code_base|0x0c088be0u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088be0u) { target=s->pc; goto dispatch; }
goto P_0c088be0;
P_0c088bde: /* original f4ec, guest PC 0x0c088bde */
if(!s->budget--) { s->failed_pc=0x0c088bdeu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088be0;
P_0c088be0: /* original 4c0b, guest PC 0x0c088be0 */
if(!s->budget--) { s->failed_pc=0x0c088be0u; return 0; }
target=r[12];
r[16]=code_base|0x0c088be4u;
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088be4u) { target=s->pc; goto dispatch; }
goto P_0c088be4;
P_0c088be2: /* original 64ef, guest PC 0x0c088be2 */
if(!s->budget--) { s->failed_pc=0x0c088be2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c088be4;
P_0c088be4: /* original 85f2, guest PC 0x0c088be4 */
if(!s->budget--) { s->failed_pc=0x0c088be4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088be6;
P_0c088be6: /* original 4000, guest PC 0x0c088be6 */
if(!s->budget--) { s->failed_pc=0x0c088be6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c088be8;
P_0c088be8: /* original 4810, guest PC 0x0c088be8 */
if(!s->budget--) { s->failed_pc=0x0c088be8u; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c088bea;
P_0c088bea: /* original 81f2, guest PC 0x0c088bea */
if(!s->budget--) { s->failed_pc=0x0c088beau; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088bec;
P_0c088bec: /* original 53f2, guest PC 0x0c088bec */
if(!s->budget--) { s->failed_pc=0x0c088becu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c088bee;
P_0c088bee: /* original 7304, guest PC 0x0c088bee */
if(!s->budget--) { s->failed_pc=0x0c088beeu; return 0; }
r[3]+=0x00000004u;
goto P_0c088bf0;
P_0c088bf0: /* original 8fc7, guest PC 0x0c088bf0 */
if(!s->budget--) { s->failed_pc=0x0c088bf0u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(!cond) { goto P_0c088b82; }
goto P_0c088bf4;
P_0c088bf2: /* original 1f32, guest PC 0x0c088bf2 */
if(!s->budget--) { s->failed_pc=0x0c088bf2u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c088bf4;
P_0c088bf4: /* original 7f14, guest PC 0x0c088bf4 */
if(!s->budget--) { s->failed_pc=0x0c088bf4u; return 0; }
r[15]+=0x00000014u;
goto P_0c088bf6;
P_0c088bf6: /* original d30e, guest PC 0x0c088bf6 */
if(!s->budget--) { s->failed_pc=0x0c088bf6u; return 0; }
r[3]=read(ram,0x0c088c30u,4);
goto P_0c088bf8;
P_0c088bf8: /* original 4f26, guest PC 0x0c088bf8 */
if(!s->budget--) { s->failed_pc=0x0c088bf8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088bfa;
P_0c088bfa: /* original e401, guest PC 0x0c088bfa */
if(!s->budget--) { s->failed_pc=0x0c088bfau; return 0; }
r[4]=0x00000001u;
goto P_0c088bfc;
P_0c088bfc: /* original fdf9, guest PC 0x0c088bfc */
if(!s->budget--) { s->failed_pc=0x0c088bfcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088bfe;
P_0c088bfe: /* original fef9, guest PC 0x0c088bfe */
if(!s->budget--) { s->failed_pc=0x0c088bfeu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088c00;
P_0c088c00: /* original fff9, guest PC 0x0c088c00 */
if(!s->budget--) { s->failed_pc=0x0c088c00u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088c02;
P_0c088c02: /* original 68f6, guest PC 0x0c088c02 */
if(!s->budget--) { s->failed_pc=0x0c088c02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088c04;
P_0c088c04: /* original 69f6, guest PC 0x0c088c04 */
if(!s->budget--) { s->failed_pc=0x0c088c04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c088c06;
P_0c088c06: /* original 6af6, guest PC 0x0c088c06 */
if(!s->budget--) { s->failed_pc=0x0c088c06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088c08;
P_0c088c08: /* original 6bf6, guest PC 0x0c088c08 */
if(!s->budget--) { s->failed_pc=0x0c088c08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088c0a;
P_0c088c0a: /* original 6cf6, guest PC 0x0c088c0a */
if(!s->budget--) { s->failed_pc=0x0c088c0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088c0c;
P_0c088c0c: /* original 6df6, guest PC 0x0c088c0c */
if(!s->budget--) { s->failed_pc=0x0c088c0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088c0e;
P_0c088c0e: /* original 432b, guest PC 0x0c088c0e */
if(!s->budget--) { s->failed_pc=0x0c088c0eu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c088c10: /* original 6ef6, guest PC 0x0c088c10 */
if(!s->budget--) { s->failed_pc=0x0c088c10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c088c12u,s,ram);
P_0c08a6ec: /* original 2fe6, guest PC 0x0c08a6ec */
if(!s->budget--) { s->failed_pc=0x0c08a6ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a6ee;
P_0c08a6ee: /* original 6e53, guest PC 0x0c08a6ee */
if(!s->budget--) { s->failed_pc=0x0c08a6eeu; return 0; }
r[14]=r[5];
goto P_0c08a6f0;
P_0c08a6f0: /* original 2fd6, guest PC 0x0c08a6f0 */
if(!s->budget--) { s->failed_pc=0x0c08a6f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a6f2;
P_0c08a6f2: /* original e309, guest PC 0x0c08a6f2 */
if(!s->budget--) { s->failed_pc=0x0c08a6f2u; return 0; }
r[3]=0x00000009u;
goto P_0c08a6f4;
P_0c08a6f4: /* original fffb, guest PC 0x0c08a6f4 */
if(!s->budget--) { s->failed_pc=0x0c08a6f4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08a6f6;
P_0c08a6f6: /* original 6d63, guest PC 0x0c08a6f6 */
if(!s->budget--) { s->failed_pc=0x0c08a6f6u; return 0; }
r[13]=r[6];
goto P_0c08a6f8;
P_0c08a6f8: /* original 4f22, guest PC 0x0c08a6f8 */
if(!s->budget--) { s->failed_pc=0x0c08a6f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a6fa;
P_0c08a6fa: /* original 7ff4, guest PC 0x0c08a6fa */
if(!s->budget--) { s->failed_pc=0x0c08a6fau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08a6fc;
P_0c08a6fc: /* original 1f72, guest PC 0x0c08a6fc */
if(!s->budget--) { s->failed_pc=0x0c08a6fcu; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c08a6fe;
P_0c08a6fe: /* original 8541, guest PC 0x0c08a6fe */
if(!s->budget--) { s->failed_pc=0x0c08a6feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c08a700;
P_0c08a700: /* original 6503, guest PC 0x0c08a700 */
if(!s->budget--) { s->failed_pc=0x0c08a700u; return 0; }
r[5]=r[0];
goto P_0c08a702;
P_0c08a702: /* original 7501, guest PC 0x0c08a702 */
if(!s->budget--) { s->failed_pc=0x0c08a702u; return 0; }
r[5]+=0x00000001u;
goto P_0c08a704;
P_0c08a704: /* original 3537, guest PC 0x0c08a704 */
if(!s->budget--) { s->failed_pc=0x0c08a704u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[3])!=0);
goto P_0c08a706;
P_0c08a706: /* original 8f01, guest PC 0x0c08a706 */
if(!s->budget--) { s->failed_pc=0x0c08a706u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+14,r[0],2);
if(!cond) { goto P_0c08a70c; }
goto P_0c08a70a;
P_0c08a708: /* original 81e7, guest PC 0x0c08a708 */
if(!s->budget--) { s->failed_pc=0x0c08a708u; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c08a70a;
P_0c08a70a: /* original e500, guest PC 0x0c08a70a */
if(!s->budget--) { s->failed_pc=0x0c08a70au; return 0; }
r[5]=0x00000000u;
goto P_0c08a70c;
P_0c08a70c: /* original d355, guest PC 0x0c08a70c */
if(!s->budget--) { s->failed_pc=0x0c08a70cu; return 0; }
r[3]=read(ram,0x0c08a864u,4);
goto P_0c08a70e;
P_0c08a70e: /* original 6053, guest PC 0x0c08a70e */
if(!s->budget--) { s->failed_pc=0x0c08a70eu; return 0; }
r[0]=r[5];
goto P_0c08a710;
P_0c08a710: /* original 430b, guest PC 0x0c08a710 */
if(!s->budget--) { s->failed_pc=0x0c08a710u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a714u;
write(ram,r[4]+2,r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a714u) { target=s->pc; goto dispatch; }
goto P_0c08a714;
P_0c08a712: /* original 8141, guest PC 0x0c08a712 */
if(!s->budget--) { s->failed_pc=0x0c08a712u; return 0; }
write(ram,r[4]+2,r[0],2);
goto P_0c08a714;
P_0c08a714: /* original 6503, guest PC 0x0c08a714 */
if(!s->budget--) { s->failed_pc=0x0c08a714u; return 0; }
r[5]=r[0];
goto P_0c08a716;
P_0c08a716: /* original 97a3, guest PC 0x0c08a716 */
if(!s->budget--) { s->failed_pc=0x0c08a716u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a860u,2);
goto P_0c08a718;
P_0c08a718: /* original 4518, guest PC 0x0c08a718 */
if(!s->budget--) { s->failed_pc=0x0c08a718u; return 0; }
r[5]<<=8;
goto P_0c08a71a;
P_0c08a71a: /* original 6403, guest PC 0x0c08a71a */
if(!s->budget--) { s->failed_pc=0x0c08a71au; return 0; }
r[4]=r[0];
goto P_0c08a71c;
P_0c08a71c: /* original 2579, guest PC 0x0c08a71c */
if(!s->budget--) { s->failed_pc=0x0c08a71cu; return 0; }
r[5]&=r[7];
goto P_0c08a71e;
P_0c08a71e: /* original 6603, guest PC 0x0c08a71e */
if(!s->budget--) { s->failed_pc=0x0c08a71eu; return 0; }
r[6]=r[0];
goto P_0c08a720;
P_0c08a720: /* original 455a, guest PC 0x0c08a720 */
if(!s->budget--) { s->failed_pc=0x0c08a720u; return 0; }
r[53]=r[5];
goto P_0c08a722;
P_0c08a722: /* original 4421, guest PC 0x0c08a722 */
if(!s->budget--) { s->failed_pc=0x0c08a722u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c08a724;
P_0c08a724: /* original 2479, guest PC 0x0c08a724 */
if(!s->budget--) { s->failed_pc=0x0c08a724u; return 0; }
r[4]&=r[7];
goto P_0c08a726;
P_0c08a726: /* original 939c, guest PC 0x0c08a726 */
if(!s->budget--) { s->failed_pc=0x0c08a726u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a862u,2);
goto P_0c08a728;
P_0c08a728: /* original 4608, guest PC 0x0c08a728 */
if(!s->budget--) { s->failed_pc=0x0c08a728u; return 0; }
r[6]<<=2;
goto P_0c08a72a;
P_0c08a72a: /* original f32d, guest PC 0x0c08a72a */
if(!s->budget--) { s->failed_pc=0x0c08a72au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08a72c;
P_0c08a72c: /* original 2639, guest PC 0x0c08a72c */
if(!s->budget--) { s->failed_pc=0x0c08a72cu; return 0; }
r[6]&=r[3];
goto P_0c08a72e;
P_0c08a72e: /* original e004, guest PC 0x0c08a72e */
if(!s->budget--) { s->failed_pc=0x0c08a72eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a730;
P_0c08a730: /* original ff37, guest PC 0x0c08a730 */
if(!s->budget--) { s->failed_pc=0x0c08a730u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a732;
P_0c08a732: /* original c74d, guest PC 0x0c08a732 */
if(!s->budget--) { s->failed_pc=0x0c08a732u; return 0; }
r[0]=0x0c08a868u;
goto P_0c08a734;
P_0c08a734: /* original 445a, guest PC 0x0c08a734 */
if(!s->budget--) { s->failed_pc=0x0c08a734u; return 0; }
r[53]=r[4];
goto P_0c08a736;
P_0c08a736: /* original f22d, guest PC 0x0c08a736 */
if(!s->budget--) { s->failed_pc=0x0c08a736u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c08a738;
P_0c08a738: /* original ff2a, guest PC 0x0c08a738 */
if(!s->budget--) { s->failed_pc=0x0c08a738u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c08a73a;
P_0c08a73a: /* original 465a, guest PC 0x0c08a73a */
if(!s->budget--) { s->failed_pc=0x0c08a73au; return 0; }
r[53]=r[6];
goto P_0c08a73c;
P_0c08a73c: /* original f408, guest PC 0x0c08a73c */
if(!s->budget--) { s->failed_pc=0x0c08a73cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a73e;
P_0c08a73e: /* original e004, guest PC 0x0c08a73e */
if(!s->budget--) { s->failed_pc=0x0c08a73eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a740;
P_0c08a740: /* original f12d, guest PC 0x0c08a740 */
if(!s->budget--) { s->failed_pc=0x0c08a740u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c08a742;
P_0c08a742: /* original ff1c, guest PC 0x0c08a742 */
if(!s->budget--) { s->failed_pc=0x0c08a742u; return 0; }
vf3_matrix_move(s,15,1);
goto P_0c08a744;
P_0c08a744: /* original ff43, guest PC 0x0c08a744 */
if(!s->budget--) { s->failed_pc=0x0c08a744u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'/');
goto P_0c08a746;
P_0c08a746: /* original f1f6, guest PC 0x0c08a746 */
if(!s->budget--) { s->failed_pc=0x0c08a746u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08a748;
P_0c08a748: /* original e004, guest PC 0x0c08a748 */
if(!s->budget--) { s->failed_pc=0x0c08a748u; return 0; }
r[0]=0x00000004u;
goto P_0c08a74a;
P_0c08a74a: /* original f143, guest PC 0x0c08a74a */
if(!s->budget--) { s->failed_pc=0x0c08a74au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'/');
goto P_0c08a74c;
P_0c08a74c: /* original ff17, guest PC 0x0c08a74c */
if(!s->budget--) { s->failed_pc=0x0c08a74cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c08a74e;
P_0c08a74e: /* original f3f8, guest PC 0x0c08a74e */
if(!s->budget--) { s->failed_pc=0x0c08a74eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08a750;
P_0c08a750: /* original f343, guest PC 0x0c08a750 */
if(!s->budget--) { s->failed_pc=0x0c08a750u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'/');
goto P_0c08a752;
P_0c08a752: /* original ff3a, guest PC 0x0c08a752 */
if(!s->budget--) { s->failed_pc=0x0c08a752u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08a754;
P_0c08a754: /* original d245, guest PC 0x0c08a754 */
if(!s->budget--) { s->failed_pc=0x0c08a754u; return 0; }
r[2]=read(ram,0x0c08a86cu,4);
goto P_0c08a756;
P_0c08a756: /* original 65f3, guest PC 0x0c08a756 */
if(!s->budget--) { s->failed_pc=0x0c08a756u; return 0; }
r[5]=r[15];
goto P_0c08a758;
P_0c08a758: /* original 66f3, guest PC 0x0c08a758 */
if(!s->budget--) { s->failed_pc=0x0c08a758u; return 0; }
r[6]=r[15];
goto P_0c08a75a;
P_0c08a75a: /* original 7504, guest PC 0x0c08a75a */
if(!s->budget--) { s->failed_pc=0x0c08a75au; return 0; }
r[5]+=0x00000004u;
goto P_0c08a75c;
P_0c08a75c: /* original 420b, guest PC 0x0c08a75c */
if(!s->budget--) { s->failed_pc=0x0c08a75cu; return 0; }
target=r[2];
r[16]=code_base|0x0c08a760u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a760u) { target=s->pc; goto dispatch; }
goto P_0c08a760;
P_0c08a75e: /* original 54f2, guest PC 0x0c08a75e */
if(!s->budget--) { s->failed_pc=0x0c08a75eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c08a760;
P_0c08a760: /* original e004, guest PC 0x0c08a760 */
if(!s->budget--) { s->failed_pc=0x0c08a760u; return 0; }
r[0]=0x00000004u;
goto P_0c08a762;
P_0c08a762: /* original f3d8, guest PC 0x0c08a762 */
if(!s->budget--) { s->failed_pc=0x0c08a762u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c08a764;
P_0c08a764: /* original f2f6, guest PC 0x0c08a764 */
if(!s->budget--) { s->failed_pc=0x0c08a764u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08a766;
P_0c08a766: /* original e004, guest PC 0x0c08a766 */
if(!s->budget--) { s->failed_pc=0x0c08a766u; return 0; }
r[0]=0x00000004u;
goto P_0c08a768;
P_0c08a768: /* original f230, guest PC 0x0c08a768 */
if(!s->budget--) { s->failed_pc=0x0c08a768u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c08a76a;
P_0c08a76a: /* original fe2a, guest PC 0x0c08a76a */
if(!s->budget--) { s->failed_pc=0x0c08a76au; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c08a76c;
P_0c08a76c: /* original f3d6, guest PC 0x0c08a76c */
if(!s->budget--) { s->failed_pc=0x0c08a76cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08a76e;
P_0c08a76e: /* original ff30, guest PC 0x0c08a76e */
if(!s->budget--) { s->failed_pc=0x0c08a76eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c08a770;
P_0c08a770: /* original fef7, guest PC 0x0c08a770 */
if(!s->budget--) { s->failed_pc=0x0c08a770u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08a772;
P_0c08a772: /* original e008, guest PC 0x0c08a772 */
if(!s->budget--) { s->failed_pc=0x0c08a772u; return 0; }
r[0]=0x00000008u;
goto P_0c08a774;
P_0c08a774: /* original f3f8, guest PC 0x0c08a774 */
if(!s->budget--) { s->failed_pc=0x0c08a774u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08a776;
P_0c08a776: /* original 7f0c, guest PC 0x0c08a776 */
if(!s->budget--) { s->failed_pc=0x0c08a776u; return 0; }
r[15]+=0x0000000cu;
goto P_0c08a778;
P_0c08a778: /* original 4f26, guest PC 0x0c08a778 */
if(!s->budget--) { s->failed_pc=0x0c08a778u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a77a;
P_0c08a77a: /* original f2d6, guest PC 0x0c08a77a */
if(!s->budget--) { s->failed_pc=0x0c08a77au; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c08a77c;
P_0c08a77c: /* original f34d, guest PC 0x0c08a77c */
if(!s->budget--) { s->failed_pc=0x0c08a77cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c08a77e;
P_0c08a77e: /* original f321, guest PC 0x0c08a77e */
if(!s->budget--) { s->failed_pc=0x0c08a77eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'-');
goto P_0c08a780;
P_0c08a780: /* original fe37, guest PC 0x0c08a780 */
if(!s->budget--) { s->failed_pc=0x0c08a780u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08a782;
P_0c08a782: /* original fff9, guest PC 0x0c08a782 */
if(!s->budget--) { s->failed_pc=0x0c08a782u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a784;
P_0c08a784: /* original 6df6, guest PC 0x0c08a784 */
if(!s->budget--) { s->failed_pc=0x0c08a784u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a786;
P_0c08a786: /* original 000b, guest PC 0x0c08a786 */
if(!s->budget--) { s->failed_pc=0x0c08a786u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a788: /* original 6ef6, guest PC 0x0c08a788 */
if(!s->budget--) { s->failed_pc=0x0c08a788u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08a78a;
P_0c08a78a: /* original c739, guest PC 0x0c08a78a */
if(!s->budget--) { s->failed_pc=0x0c08a78au; return 0; }
r[0]=0x0c08a870u;
goto P_0c08a78c;
P_0c08a78c: /* original f848, guest PC 0x0c08a78c */
if(!s->budget--) { s->failed_pc=0x0c08a78cu; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
goto P_0c08a78e;
P_0c08a78e: /* original f908, guest PC 0x0c08a78e */
if(!s->budget--) { s->failed_pc=0x0c08a78eu; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a790;
P_0c08a790: /* original c738, guest PC 0x0c08a790 */
if(!s->budget--) { s->failed_pc=0x0c08a790u; return 0; }
r[0]=0x0c08a874u;
goto P_0c08a792;
P_0c08a792: /* original fa08, guest PC 0x0c08a792 */
if(!s->budget--) { s->failed_pc=0x0c08a792u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08a794;
P_0c08a794: /* original e004, guest PC 0x0c08a794 */
if(!s->budget--) { s->failed_pc=0x0c08a794u; return 0; }
r[0]=0x00000004u;
goto P_0c08a796;
P_0c08a796: /* original f646, guest PC 0x0c08a796 */
if(!s->budget--) { s->failed_pc=0x0c08a796u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c08a798;
P_0c08a798: /* original e008, guest PC 0x0c08a798 */
if(!s->budget--) { s->failed_pc=0x0c08a798u; return 0; }
r[0]=0x00000008u;
goto P_0c08a79a;
P_0c08a79a: /* original f690, guest PC 0x0c08a79a */
if(!s->budget--) { s->failed_pc=0x0c08a79au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'+');
goto P_0c08a79c;
P_0c08a79c: /* original f6a5, guest PC 0x0c08a79c */
if(!s->budget--) { s->failed_pc=0x0c08a79cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[10]))!=0);
goto P_0c08a79e;
P_0c08a79e: /* original 8d02, guest PC 0x0c08a79e */
if(!s->budget--) { s->failed_pc=0x0c08a79eu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,7,r[4]+r[0]);
if(cond) { goto P_0c08a7a6; }
goto P_0c08a7a2;
P_0c08a7a0: /* original f746, guest PC 0x0c08a7a0 */
if(!s->budget--) { s->failed_pc=0x0c08a7a0u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c08a7a2;
P_0c08a7a2: /* original 000b, guest PC 0x0c08a7a2 */
if(!s->budget--) { s->failed_pc=0x0c08a7a2u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c08a7a4: /* original e001, guest PC 0x0c08a7a4 */
if(!s->budget--) { s->failed_pc=0x0c08a7a4u; return 0; }
r[0]=0x00000001u;
goto P_0c08a7a6;
P_0c08a7a6: /* original 8547, guest PC 0x0c08a7a6 */
if(!s->budget--) { s->failed_pc=0x0c08a7a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+14,2);
goto P_0c08a7a8;
P_0c08a7a8: /* original 6603, guest PC 0x0c08a7a8 */
if(!s->budget--) { s->failed_pc=0x0c08a7a8u; return 0; }
r[6]=r[0];
goto P_0c08a7aa;
P_0c08a7aa: /* original 4608, guest PC 0x0c08a7aa */
if(!s->budget--) { s->failed_pc=0x0c08a7aau; return 0; }
r[6]<<=2;
goto P_0c08a7ac;
P_0c08a7ac: /* original 4608, guest PC 0x0c08a7ac */
if(!s->budget--) { s->failed_pc=0x0c08a7acu; return 0; }
r[6]<<=2;
goto P_0c08a7ae;
P_0c08a7ae: /* original e008, guest PC 0x0c08a7ae */
if(!s->budget--) { s->failed_pc=0x0c08a7aeu; return 0; }
r[0]=0x00000008u;
goto P_0c08a7b0;
P_0c08a7b0: /* original 356c, guest PC 0x0c08a7b0 */
if(!s->budget--) { s->failed_pc=0x0c08a7b0u; return 0; }
r[5]+=r[6];
goto P_0c08a7b2;
P_0c08a7b2: /* original f356, guest PC 0x0c08a7b2 */
if(!s->budget--) { s->failed_pc=0x0c08a7b2u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08a7b4;
P_0c08a7b4: /* original e00c, guest PC 0x0c08a7b4 */
if(!s->budget--) { s->failed_pc=0x0c08a7b4u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a7b6;
P_0c08a7b6: /* original f830, guest PC 0x0c08a7b6 */
if(!s->budget--) { s->failed_pc=0x0c08a7b6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'+');
goto P_0c08a7b8;
P_0c08a7b8: /* original f356, guest PC 0x0c08a7b8 */
if(!s->budget--) { s->failed_pc=0x0c08a7b8u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08a7ba;
P_0c08a7ba: /* original e004, guest PC 0x0c08a7ba */
if(!s->budget--) { s->failed_pc=0x0c08a7bau; return 0; }
r[0]=0x00000004u;
goto P_0c08a7bc;
P_0c08a7bc: /* original f730, guest PC 0x0c08a7bc */
if(!s->budget--) { s->failed_pc=0x0c08a7bcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c08a7be;
P_0c08a7be: /* original f840, guest PC 0x0c08a7be */
if(!s->budget--) { s->failed_pc=0x0c08a7beu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'+');
goto P_0c08a7c0;
P_0c08a7c0: /* original f751, guest PC 0x0c08a7c0 */
if(!s->budget--) { s->failed_pc=0x0c08a7c0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'-');
goto P_0c08a7c2;
P_0c08a7c2: /* original f48a, guest PC 0x0c08a7c2 */
if(!s->budget--) { s->failed_pc=0x0c08a7c2u; return 0; }
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c08a7c4;
P_0c08a7c4: /* original f467, guest PC 0x0c08a7c4 */
if(!s->budget--) { s->failed_pc=0x0c08a7c4u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a7c6;
P_0c08a7c6: /* original e008, guest PC 0x0c08a7c6 */
if(!s->budget--) { s->failed_pc=0x0c08a7c6u; return 0; }
r[0]=0x00000008u;
goto P_0c08a7c8;
P_0c08a7c8: /* original f477, guest PC 0x0c08a7c8 */
if(!s->budget--) { s->failed_pc=0x0c08a7c8u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a7ca;
P_0c08a7ca: /* original e000, guest PC 0x0c08a7ca */
if(!s->budget--) { s->failed_pc=0x0c08a7cau; return 0; }
r[0]=0x00000000u;
goto P_0c08a7cc;
P_0c08a7cc: /* original 000b, guest PC 0x0c08a7cc */
if(!s->budget--) { s->failed_pc=0x0c08a7ccu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c08a7ce: /* original 0009, guest PC 0x0c08a7ce */
if(!s->budget--) { s->failed_pc=0x0c08a7ceu; return 0; }
return vf3_matrix_family(0x0c08a7d0u,s,ram);
P_0c08a7de: /* original 4f22, guest PC 0x0c08a7de */
if(!s->budget--) { s->failed_pc=0x0c08a7deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a7e0;
P_0c08a7e0: /* original 7fe8, guest PC 0x0c08a7e0 */
if(!s->budget--) { s->failed_pc=0x0c08a7e0u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c08a7e2;
P_0c08a7e2: /* original 1f52, guest PC 0x0c08a7e2 */
if(!s->budget--) { s->failed_pc=0x0c08a7e2u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c08a7e4;
P_0c08a7e4: /* original 6db1, guest PC 0x0c08a7e4 */
if(!s->budget--) { s->failed_pc=0x0c08a7e4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[13]=tmp;
goto P_0c08a7e6;
P_0c08a7e6: /* original 4d15, guest PC 0x0c08a7e6 */
if(!s->budget--) { s->failed_pc=0x0c08a7e6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c08a7e8;
P_0c08a7e8: /* original 8f62, guest PC 0x0c08a7e8 */
if(!s->budget--) { s->failed_pc=0x0c08a7e8u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(!cond) { goto P_0c08a8b0; }
goto P_0c08a7ec;
P_0c08a7ea: /* original 6e63, guest PC 0x0c08a7ea */
if(!s->budget--) { s->failed_pc=0x0c08a7eau; return 0; }
r[14]=r[6];
goto P_0c08a7ec;
P_0c08a7ec: /* original d222, guest PC 0x0c08a7ec */
if(!s->budget--) { s->failed_pc=0x0c08a7ecu; return 0; }
r[2]=read(ram,0x0c08a878u,4);
goto P_0c08a7ee;
P_0c08a7ee: /* original 66f3, guest PC 0x0c08a7ee */
if(!s->budget--) { s->failed_pc=0x0c08a7eeu; return 0; }
r[6]=r[15];
goto P_0c08a7f0;
P_0c08a7f0: /* original d322, guest PC 0x0c08a7f0 */
if(!s->budget--) { s->failed_pc=0x0c08a7f0u; return 0; }
r[3]=read(ram,0x0c08a87cu,4);
goto P_0c08a7f2;
P_0c08a7f2: /* original 65f3, guest PC 0x0c08a7f2 */
if(!s->budget--) { s->failed_pc=0x0c08a7f2u; return 0; }
r[5]=r[15];
goto P_0c08a7f4;
P_0c08a7f4: /* original 6422, guest PC 0x0c08a7f4 */
if(!s->budget--) { s->failed_pc=0x0c08a7f4u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c08a7f6;
P_0c08a7f6: /* original 7604, guest PC 0x0c08a7f6 */
if(!s->budget--) { s->failed_pc=0x0c08a7f6u; return 0; }
r[6]+=0x00000004u;
goto P_0c08a7f8;
P_0c08a7f8: /* original 854f, guest PC 0x0c08a7f8 */
if(!s->budget--) { s->failed_pc=0x0c08a7f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c08a7fa;
P_0c08a7fa: /* original 6c03, guest PC 0x0c08a7fa */
if(!s->budget--) { s->failed_pc=0x0c08a7fau; return 0; }
r[12]=r[0];
goto P_0c08a7fc;
P_0c08a7fc: /* original e010, guest PC 0x0c08a7fc */
if(!s->budget--) { s->failed_pc=0x0c08a7fcu; return 0; }
r[0]=0x00000010u;
goto P_0c08a7fe;
P_0c08a7fe: /* original f346, guest PC 0x0c08a7fe */
if(!s->budget--) { s->failed_pc=0x0c08a7feu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c08a800;
P_0c08a800: /* original e00c, guest PC 0x0c08a800 */
if(!s->budget--) { s->failed_pc=0x0c08a800u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a802;
P_0c08a802: /* original 3c3c, guest PC 0x0c08a802 */
if(!s->budget--) { s->failed_pc=0x0c08a802u; return 0; }
r[12]+=r[3];
goto P_0c08a804;
P_0c08a804: /* original ff37, guest PC 0x0c08a804 */
if(!s->budget--) { s->failed_pc=0x0c08a804u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a806;
P_0c08a806: /* original e014, guest PC 0x0c08a806 */
if(!s->budget--) { s->failed_pc=0x0c08a806u; return 0; }
r[0]=0x00000014u;
goto P_0c08a808;
P_0c08a808: /* original f346, guest PC 0x0c08a808 */
if(!s->budget--) { s->failed_pc=0x0c08a808u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c08a80a;
P_0c08a80a: /* original e010, guest PC 0x0c08a80a */
if(!s->budget--) { s->failed_pc=0x0c08a80au; return 0; }
r[0]=0x00000010u;
goto P_0c08a80c;
P_0c08a80c: /* original ff37, guest PC 0x0c08a80c */
if(!s->budget--) { s->failed_pc=0x0c08a80cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a80e;
P_0c08a80e: /* original e018, guest PC 0x0c08a80e */
if(!s->budget--) { s->failed_pc=0x0c08a80eu; return 0; }
r[0]=0x00000018u;
goto P_0c08a810;
P_0c08a810: /* original f346, guest PC 0x0c08a810 */
if(!s->budget--) { s->failed_pc=0x0c08a810u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c08a812;
P_0c08a812: /* original e014, guest PC 0x0c08a812 */
if(!s->budget--) { s->failed_pc=0x0c08a812u; return 0; }
r[0]=0x00000014u;
goto P_0c08a814;
P_0c08a814: /* original f34d, guest PC 0x0c08a814 */
if(!s->budget--) { s->failed_pc=0x0c08a814u; return 0; }
fr[3]^=0x80000000u;
goto P_0c08a816;
P_0c08a816: /* original ff37, guest PC 0x0c08a816 */
if(!s->budget--) { s->failed_pc=0x0c08a816u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a818;
P_0c08a818: /* original c719, guest PC 0x0c08a818 */
if(!s->budget--) { s->failed_pc=0x0c08a818u; return 0; }
r[0]=0x0c08a880u;
goto P_0c08a81a;
P_0c08a81a: /* original f308, guest PC 0x0c08a81a */
if(!s->budget--) { s->failed_pc=0x0c08a81au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a81c;
P_0c08a81c: /* original c715, guest PC 0x0c08a81c */
if(!s->budget--) { s->failed_pc=0x0c08a81cu; return 0; }
r[0]=0x0c08a874u;
goto P_0c08a81e;
P_0c08a81e: /* original ff3a, guest PC 0x0c08a81e */
if(!s->budget--) { s->failed_pc=0x0c08a81eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08a820;
P_0c08a820: /* original f308, guest PC 0x0c08a820 */
if(!s->budget--) { s->failed_pc=0x0c08a820u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a822;
P_0c08a822: /* original e004, guest PC 0x0c08a822 */
if(!s->budget--) { s->failed_pc=0x0c08a822u; return 0; }
r[0]=0x00000004u;
goto P_0c08a824;
P_0c08a824: /* original ff37, guest PC 0x0c08a824 */
if(!s->budget--) { s->failed_pc=0x0c08a824u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a826;
P_0c08a826: /* original d111, guest PC 0x0c08a826 */
if(!s->budget--) { s->failed_pc=0x0c08a826u; return 0; }
r[1]=read(ram,0x0c08a86cu,4);
goto P_0c08a828;
P_0c08a828: /* original 410b, guest PC 0x0c08a828 */
if(!s->budget--) { s->failed_pc=0x0c08a828u; return 0; }
target=r[1];
r[16]=code_base|0x0c08a82cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a82cu) { target=s->pc; goto dispatch; }
goto P_0c08a82c;
P_0c08a82a: /* original 64c3, guest PC 0x0c08a82a */
if(!s->budget--) { s->failed_pc=0x0c08a82au; return 0; }
r[4]=r[12];
goto P_0c08a82c;
P_0c08a82c: /* original e00c, guest PC 0x0c08a82c */
if(!s->budget--) { s->failed_pc=0x0c08a82cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08a82e;
P_0c08a82e: /* original f3f8, guest PC 0x0c08a82e */
if(!s->budget--) { s->failed_pc=0x0c08a82eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08a830;
P_0c08a830: /* original f2f6, guest PC 0x0c08a830 */
if(!s->budget--) { s->failed_pc=0x0c08a830u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08a832;
P_0c08a832: /* original e00c, guest PC 0x0c08a832 */
if(!s->budget--) { s->failed_pc=0x0c08a832u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a834;
P_0c08a834: /* original f230, guest PC 0x0c08a834 */
if(!s->budget--) { s->failed_pc=0x0c08a834u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c08a836;
P_0c08a836: /* original ff27, guest PC 0x0c08a836 */
if(!s->budget--) { s->failed_pc=0x0c08a836u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08a838;
P_0c08a838: /* original e004, guest PC 0x0c08a838 */
if(!s->budget--) { s->failed_pc=0x0c08a838u; return 0; }
r[0]=0x00000004u;
goto P_0c08a83a;
P_0c08a83a: /* original f2f6, guest PC 0x0c08a83a */
if(!s->budget--) { s->failed_pc=0x0c08a83au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08a83c;
P_0c08a83c: /* original e014, guest PC 0x0c08a83c */
if(!s->budget--) { s->failed_pc=0x0c08a83cu; return 0; }
r[0]=0x00000014u;
goto P_0c08a83e;
P_0c08a83e: /* original f1f6, guest PC 0x0c08a83e */
if(!s->budget--) { s->failed_pc=0x0c08a83eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08a840;
P_0c08a840: /* original e014, guest PC 0x0c08a840 */
if(!s->budget--) { s->failed_pc=0x0c08a840u; return 0; }
r[0]=0x00000014u;
goto P_0c08a842;
P_0c08a842: /* original f120, guest PC 0x0c08a842 */
if(!s->budget--) { s->failed_pc=0x0c08a842u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c08a844;
P_0c08a844: /* original ff17, guest PC 0x0c08a844 */
if(!s->budget--) { s->failed_pc=0x0c08a844u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c08a846;
P_0c08a846: /* original c70f, guest PC 0x0c08a846 */
if(!s->budget--) { s->failed_pc=0x0c08a846u; return 0; }
r[0]=0x0c08a884u;
goto P_0c08a848;
P_0c08a848: /* original f108, guest PC 0x0c08a848 */
if(!s->budget--) { s->failed_pc=0x0c08a848u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c08a84a;
P_0c08a84a: /* original e008, guest PC 0x0c08a84a */
if(!s->budget--) { s->failed_pc=0x0c08a84au; return 0; }
r[0]=0x00000008u;
goto P_0c08a84c;
P_0c08a84c: /* original ff1a, guest PC 0x0c08a84c */
if(!s->budget--) { s->failed_pc=0x0c08a84cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c08a84e;
P_0c08a84e: /* original d40e, guest PC 0x0c08a84e */
if(!s->budget--) { s->failed_pc=0x0c08a84eu; return 0; }
r[4]=read(ram,0x0c08a888u,4);
goto P_0c08a850;
P_0c08a850: /* original fe1c, guest PC 0x0c08a850 */
if(!s->budget--) { s->failed_pc=0x0c08a850u; return 0; }
vf3_matrix_move(s,14,1);
goto P_0c08a852;
P_0c08a852: /* original f348, guest PC 0x0c08a852 */
if(!s->budget--) { s->failed_pc=0x0c08a852u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c08a854;
P_0c08a854: /* original ff46, guest PC 0x0c08a854 */
if(!s->budget--) { s->failed_pc=0x0c08a854u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c08a856;
P_0c08a856: /* original fe32, guest PC 0x0c08a856 */
if(!s->budget--) { s->failed_pc=0x0c08a856u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c08a858;
P_0c08a858: /* original f3fc, guest PC 0x0c08a858 */
if(!s->budget--) { s->failed_pc=0x0c08a858u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c08a85a;
P_0c08a85a: /* original ff1c, guest PC 0x0c08a85a */
if(!s->budget--) { s->failed_pc=0x0c08a85au; return 0; }
vf3_matrix_move(s,15,1);
goto P_0c08a85c;
P_0c08a85c: /* original a026, guest PC 0x0c08a85c */
if(!s->budget--) { s->failed_pc=0x0c08a85cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c08a8ac;
P_0c08a85e: /* original ff32, guest PC 0x0c08a85e */
if(!s->budget--) { s->failed_pc=0x0c08a85eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
return vf3_matrix_family(0x0c08a860u,s,ram);
P_0c08a88c: /* original 55f2, guest PC 0x0c08a88c */
if(!s->budget--) { s->failed_pc=0x0c08a88cu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c08a88e;
P_0c08a88e: /* original f4ec, guest PC 0x0c08a88e */
if(!s->budget--) { s->failed_pc=0x0c08a88eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08a890;
P_0c08a890: /* original f5fc, guest PC 0x0c08a890 */
if(!s->budget--) { s->failed_pc=0x0c08a890u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08a892;
P_0c08a892: /* original bf7a, guest PC 0x0c08a892 */
if(!s->budget--) { s->failed_pc=0x0c08a892u; return 0; }
target=0x0c08a78au; r[16]=code_base|0x0c08a896u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a896u) { target=s->pc; goto dispatch; }
goto P_0c08a896;
P_0c08a894: /* original 64e3, guest PC 0x0c08a894 */
if(!s->budget--) { s->failed_pc=0x0c08a894u; return 0; }
r[4]=r[14];
goto P_0c08a896;
P_0c08a896: /* original 6403, guest PC 0x0c08a896 */
if(!s->budget--) { s->failed_pc=0x0c08a896u; return 0; }
r[4]=r[0];
goto P_0c08a898;
P_0c08a898: /* original 2448, guest PC 0x0c08a898 */
if(!s->budget--) { s->failed_pc=0x0c08a898u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08a89a;
P_0c08a89a: /* original 8905, guest PC 0x0c08a89a */
if(!s->budget--) { s->failed_pc=0x0c08a89au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08a8a8; }
goto P_0c08a89c;
P_0c08a89c: /* original 66f3, guest PC 0x0c08a89c */
if(!s->budget--) { s->failed_pc=0x0c08a89cu; return 0; }
r[6]=r[15];
goto P_0c08a89e;
P_0c08a89e: /* original 65e3, guest PC 0x0c08a89e */
if(!s->budget--) { s->failed_pc=0x0c08a89eu; return 0; }
r[5]=r[14];
goto P_0c08a8a0;
P_0c08a8a0: /* original 760c, guest PC 0x0c08a8a0 */
if(!s->budget--) { s->failed_pc=0x0c08a8a0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c08a8a2;
P_0c08a8a2: /* original 67c3, guest PC 0x0c08a8a2 */
if(!s->budget--) { s->failed_pc=0x0c08a8a2u; return 0; }
r[7]=r[12];
goto P_0c08a8a4;
P_0c08a8a4: /* original bf22, guest PC 0x0c08a8a4 */
if(!s->budget--) { s->failed_pc=0x0c08a8a4u; return 0; }
target=0x0c08a6ecu; r[16]=code_base|0x0c08a8a8u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a8a8u) { target=s->pc; goto dispatch; }
goto P_0c08a8a8;
P_0c08a8a6: /* original 64b3, guest PC 0x0c08a8a6 */
if(!s->budget--) { s->failed_pc=0x0c08a8a6u; return 0; }
r[4]=r[11];
goto P_0c08a8a8;
P_0c08a8a8: /* original 7dff, guest PC 0x0c08a8a8 */
if(!s->budget--) { s->failed_pc=0x0c08a8a8u; return 0; }
r[13]+=0xffffffffu;
goto P_0c08a8aa;
P_0c08a8aa: /* original 7e10, guest PC 0x0c08a8aa */
if(!s->budget--) { s->failed_pc=0x0c08a8aau; return 0; }
r[14]+=0x00000010u;
goto P_0c08a8ac;
P_0c08a8ac: /* original 2dd8, guest PC 0x0c08a8ac */
if(!s->budget--) { s->failed_pc=0x0c08a8acu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c08a8ae;
P_0c08a8ae: /* original 8bed, guest PC 0x0c08a8ae */
if(!s->budget--) { s->failed_pc=0x0c08a8aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08a88c; }
goto P_0c08a8b0;
P_0c08a8b0: /* original 7f18, guest PC 0x0c08a8b0 */
if(!s->budget--) { s->failed_pc=0x0c08a8b0u; return 0; }
r[15]+=0x00000018u;
goto P_0c08a8b2;
P_0c08a8b2: /* original 4f26, guest PC 0x0c08a8b2 */
if(!s->budget--) { s->failed_pc=0x0c08a8b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a8b4;
P_0c08a8b4: /* original fef9, guest PC 0x0c08a8b4 */
if(!s->budget--) { s->failed_pc=0x0c08a8b4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a8b6;
P_0c08a8b6: /* original fff9, guest PC 0x0c08a8b6 */
if(!s->budget--) { s->failed_pc=0x0c08a8b6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a8b8;
P_0c08a8b8: /* original 6bf6, guest PC 0x0c08a8b8 */
if(!s->budget--) { s->failed_pc=0x0c08a8b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a8ba;
P_0c08a8ba: /* original 6cf6, guest PC 0x0c08a8ba */
if(!s->budget--) { s->failed_pc=0x0c08a8bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a8bc;
P_0c08a8bc: /* original 6df6, guest PC 0x0c08a8bc */
if(!s->budget--) { s->failed_pc=0x0c08a8bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a8be;
P_0c08a8be: /* original 000b, guest PC 0x0c08a8be */
if(!s->budget--) { s->failed_pc=0x0c08a8beu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a8c0: /* original 6ef6, guest PC 0x0c08a8c0 */
if(!s->budget--) { s->failed_pc=0x0c08a8c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08a8c2u,s,ram);
P_0c08e028: /* original 4f22, guest PC 0x0c08e028 */
if(!s->budget--) { s->failed_pc=0x0c08e028u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08e02a;
P_0c08e02a: /* original 6d63, guest PC 0x0c08e02a */
if(!s->budget--) { s->failed_pc=0x0c08e02au; return 0; }
r[13]=r[6];
goto P_0c08e02c;
P_0c08e02c: /* original 6043, guest PC 0x0c08e02c */
if(!s->budget--) { s->failed_pc=0x0c08e02cu; return 0; }
r[0]=r[4];
goto P_0c08e02e;
P_0c08e02e: /* original 473c, guest PC 0x0c08e02e */
if(!s->budget--) { s->failed_pc=0x0c08e02eu; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[7]>>((-r[3])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[3]&31u);
goto P_0c08e030;
P_0c08e030: /* original 8800, guest PC 0x0c08e030 */
if(!s->budget--) { s->failed_pc=0x0c08e030u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c08e032;
P_0c08e032: /* original 7ffc, guest PC 0x0c08e032 */
if(!s->budget--) { s->failed_pc=0x0c08e032u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08e034;
P_0c08e034: /* original 2f52, guest PC 0x0c08e034 */
if(!s->budget--) { s->failed_pc=0x0c08e034u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c08e036;
P_0c08e036: /* original 2d7b, guest PC 0x0c08e036 */
if(!s->budget--) { s->failed_pc=0x0c08e036u; return 0; }
r[13]|=r[7];
goto P_0c08e038;
P_0c08e038: /* original 8d12, guest PC 0x0c08e038 */
if(!s->budget--) { s->failed_pc=0x0c08e038u; return 0; }
cond=r[17]&1u;
r[5]<<=2;
if(cond) { goto P_0c08e060; }
goto P_0c08e03c;
P_0c08e03a: /* original 4508, guest PC 0x0c08e03a */
if(!s->budget--) { s->failed_pc=0x0c08e03au; return 0; }
r[5]<<=2;
goto P_0c08e03c;
P_0c08e03c: /* original 8801, guest PC 0x0c08e03c */
if(!s->budget--) { s->failed_pc=0x0c08e03cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08e03e;
P_0c08e03e: /* original 8912, guest PC 0x0c08e03e */
if(!s->budget--) { s->failed_pc=0x0c08e03eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e066; }
goto P_0c08e040;
P_0c08e040: /* original 8802, guest PC 0x0c08e040 */
if(!s->budget--) { s->failed_pc=0x0c08e040u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08e042;
P_0c08e042: /* original 8913, guest PC 0x0c08e042 */
if(!s->budget--) { s->failed_pc=0x0c08e042u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e06c; }
goto P_0c08e044;
P_0c08e044: /* original 8803, guest PC 0x0c08e044 */
if(!s->budget--) { s->failed_pc=0x0c08e044u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c08e046;
P_0c08e046: /* original 8914, guest PC 0x0c08e046 */
if(!s->budget--) { s->failed_pc=0x0c08e046u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e072; }
goto P_0c08e048;
P_0c08e048: /* original 8804, guest PC 0x0c08e048 */
if(!s->budget--) { s->failed_pc=0x0c08e048u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c08e04a;
P_0c08e04a: /* original 8915, guest PC 0x0c08e04a */
if(!s->budget--) { s->failed_pc=0x0c08e04au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e078; }
goto P_0c08e04c;
P_0c08e04c: /* original 8805, guest PC 0x0c08e04c */
if(!s->budget--) { s->failed_pc=0x0c08e04cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c08e04e;
P_0c08e04e: /* original 8916, guest PC 0x0c08e04e */
if(!s->budget--) { s->failed_pc=0x0c08e04eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e07e; }
goto P_0c08e050;
P_0c08e050: /* original 8806, guest PC 0x0c08e050 */
if(!s->budget--) { s->failed_pc=0x0c08e050u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c08e052;
P_0c08e052: /* original 8917, guest PC 0x0c08e052 */
if(!s->budget--) { s->failed_pc=0x0c08e052u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e084; }
goto P_0c08e054;
P_0c08e054: /* original 8807, guest PC 0x0c08e054 */
if(!s->budget--) { s->failed_pc=0x0c08e054u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c08e056;
P_0c08e056: /* original 8918, guest PC 0x0c08e056 */
if(!s->budget--) { s->failed_pc=0x0c08e056u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e08a; }
goto P_0c08e058;
P_0c08e058: /* original 8808, guest PC 0x0c08e058 */
if(!s->budget--) { s->failed_pc=0x0c08e058u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c08e05a;
P_0c08e05a: /* original 8919, guest PC 0x0c08e05a */
if(!s->budget--) { s->failed_pc=0x0c08e05au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e090; }
goto P_0c08e05c;
P_0c08e05c: /* original 8809, guest PC 0x0c08e05c */
if(!s->budget--) { s->failed_pc=0x0c08e05cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c08e05e;
P_0c08e05e: /* original 891a, guest PC 0x0c08e05e */
if(!s->budget--) { s->failed_pc=0x0c08e05eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e096; }
goto P_0c08e060;
P_0c08e060: /* original d083, guest PC 0x0c08e060 */
if(!s->budget--) { s->failed_pc=0x0c08e060u; return 0; }
r[0]=read(ram,0x0c08e270u,4);
goto P_0c08e062;
P_0c08e062: /* original a019, guest PC 0x0c08e062 */
if(!s->budget--) { s->failed_pc=0x0c08e062u; return 0; }
goto P_0c08e098;
P_0c08e064: /* original 0009, guest PC 0x0c08e064 */
if(!s->budget--) { s->failed_pc=0x0c08e064u; return 0; }
goto P_0c08e066;
P_0c08e066: /* original d083, guest PC 0x0c08e066 */
if(!s->budget--) { s->failed_pc=0x0c08e066u; return 0; }
r[0]=read(ram,0x0c08e274u,4);
goto P_0c08e068;
P_0c08e068: /* original a016, guest PC 0x0c08e068 */
if(!s->budget--) { s->failed_pc=0x0c08e068u; return 0; }
goto P_0c08e098;
P_0c08e06a: /* original 0009, guest PC 0x0c08e06a */
if(!s->budget--) { s->failed_pc=0x0c08e06au; return 0; }
goto P_0c08e06c;
P_0c08e06c: /* original d082, guest PC 0x0c08e06c */
if(!s->budget--) { s->failed_pc=0x0c08e06cu; return 0; }
r[0]=read(ram,0x0c08e278u,4);
goto P_0c08e06e;
P_0c08e06e: /* original a013, guest PC 0x0c08e06e */
if(!s->budget--) { s->failed_pc=0x0c08e06eu; return 0; }
goto P_0c08e098;
P_0c08e070: /* original 0009, guest PC 0x0c08e070 */
if(!s->budget--) { s->failed_pc=0x0c08e070u; return 0; }
goto P_0c08e072;
P_0c08e072: /* original d082, guest PC 0x0c08e072 */
if(!s->budget--) { s->failed_pc=0x0c08e072u; return 0; }
r[0]=read(ram,0x0c08e27cu,4);
goto P_0c08e074;
P_0c08e074: /* original a010, guest PC 0x0c08e074 */
if(!s->budget--) { s->failed_pc=0x0c08e074u; return 0; }
goto P_0c08e098;
P_0c08e076: /* original 0009, guest PC 0x0c08e076 */
if(!s->budget--) { s->failed_pc=0x0c08e076u; return 0; }
goto P_0c08e078;
P_0c08e078: /* original d081, guest PC 0x0c08e078 */
if(!s->budget--) { s->failed_pc=0x0c08e078u; return 0; }
r[0]=read(ram,0x0c08e280u,4);
goto P_0c08e07a;
P_0c08e07a: /* original a00d, guest PC 0x0c08e07a */
if(!s->budget--) { s->failed_pc=0x0c08e07au; return 0; }
goto P_0c08e098;
P_0c08e07c: /* original 0009, guest PC 0x0c08e07c */
if(!s->budget--) { s->failed_pc=0x0c08e07cu; return 0; }
goto P_0c08e07e;
P_0c08e07e: /* original d081, guest PC 0x0c08e07e */
if(!s->budget--) { s->failed_pc=0x0c08e07eu; return 0; }
r[0]=read(ram,0x0c08e284u,4);
goto P_0c08e080;
P_0c08e080: /* original a00a, guest PC 0x0c08e080 */
if(!s->budget--) { s->failed_pc=0x0c08e080u; return 0; }
goto P_0c08e098;
P_0c08e082: /* original 0009, guest PC 0x0c08e082 */
if(!s->budget--) { s->failed_pc=0x0c08e082u; return 0; }
goto P_0c08e084;
P_0c08e084: /* original de80, guest PC 0x0c08e084 */
if(!s->budget--) { s->failed_pc=0x0c08e084u; return 0; }
r[14]=read(ram,0x0c08e288u,4);
goto P_0c08e086;
P_0c08e086: /* original a008, guest PC 0x0c08e086 */
if(!s->budget--) { s->failed_pc=0x0c08e086u; return 0; }
goto P_0c08e09a;
P_0c08e088: /* original 0009, guest PC 0x0c08e088 */
if(!s->budget--) { s->failed_pc=0x0c08e088u; return 0; }
goto P_0c08e08a;
P_0c08e08a: /* original d080, guest PC 0x0c08e08a */
if(!s->budget--) { s->failed_pc=0x0c08e08au; return 0; }
r[0]=read(ram,0x0c08e28cu,4);
goto P_0c08e08c;
P_0c08e08c: /* original a004, guest PC 0x0c08e08c */
if(!s->budget--) { s->failed_pc=0x0c08e08cu; return 0; }
goto P_0c08e098;
P_0c08e08e: /* original 0009, guest PC 0x0c08e08e */
if(!s->budget--) { s->failed_pc=0x0c08e08eu; return 0; }
goto P_0c08e090;
P_0c08e090: /* original d07f, guest PC 0x0c08e090 */
if(!s->budget--) { s->failed_pc=0x0c08e090u; return 0; }
r[0]=read(ram,0x0c08e290u,4);
goto P_0c08e092;
P_0c08e092: /* original a001, guest PC 0x0c08e092 */
if(!s->budget--) { s->failed_pc=0x0c08e092u; return 0; }
goto P_0c08e098;
P_0c08e094: /* original 0009, guest PC 0x0c08e094 */
if(!s->budget--) { s->failed_pc=0x0c08e094u; return 0; }
goto P_0c08e096;
P_0c08e096: /* original d07f, guest PC 0x0c08e096 */
if(!s->budget--) { s->failed_pc=0x0c08e096u; return 0; }
r[0]=read(ram,0x0c08e294u,4);
goto P_0c08e098;
P_0c08e098: /* original 0e5e, guest PC 0x0c08e098 */
if(!s->budget--) { s->failed_pc=0x0c08e098u; return 0; }
r[14]=read(ram,r[5]+r[0],4);
goto P_0c08e09a;
P_0c08e09a: /* original 6043, guest PC 0x0c08e09a */
if(!s->budget--) { s->failed_pc=0x0c08e09au; return 0; }
r[0]=r[4];
goto P_0c08e09c;
P_0c08e09c: /* original 8806, guest PC 0x0c08e09c */
if(!s->budget--) { s->failed_pc=0x0c08e09cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c08e09e;
P_0c08e09e: /* original 8908, guest PC 0x0c08e09e */
if(!s->budget--) { s->failed_pc=0x0c08e09eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e0b2; }
goto P_0c08e0a0;
P_0c08e0a0: /* original 7f04, guest PC 0x0c08e0a0 */
if(!s->budget--) { s->failed_pc=0x0c08e0a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c08e0a2;
P_0c08e0a2: /* original 64d3, guest PC 0x0c08e0a2 */
if(!s->budget--) { s->failed_pc=0x0c08e0a2u; return 0; }
r[4]=r[13];
goto P_0c08e0a4;
P_0c08e0a4: /* original 4f26, guest PC 0x0c08e0a4 */
if(!s->budget--) { s->failed_pc=0x0c08e0a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08e0a6;
P_0c08e0a6: /* original d27c, guest PC 0x0c08e0a6 */
if(!s->budget--) { s->failed_pc=0x0c08e0a6u; return 0; }
r[2]=read(ram,0x0c08e298u,4);
goto P_0c08e0a8;
P_0c08e0a8: /* original 65e3, guest PC 0x0c08e0a8 */
if(!s->budget--) { s->failed_pc=0x0c08e0a8u; return 0; }
r[5]=r[14];
goto P_0c08e0aa;
P_0c08e0aa: /* original e601, guest PC 0x0c08e0aa */
if(!s->budget--) { s->failed_pc=0x0c08e0aau; return 0; }
r[6]=0x00000001u;
goto P_0c08e0ac;
P_0c08e0ac: /* original 6df6, guest PC 0x0c08e0ac */
if(!s->budget--) { s->failed_pc=0x0c08e0acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08e0ae;
P_0c08e0ae: /* original 422b, guest PC 0x0c08e0ae */
if(!s->budget--) { s->failed_pc=0x0c08e0aeu; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c08e0b0: /* original 6ef6, guest PC 0x0c08e0b0 */
if(!s->budget--) { s->failed_pc=0x0c08e0b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08e0b2;
P_0c08e0b2: /* original 62f2, guest PC 0x0c08e0b2 */
if(!s->budget--) { s->failed_pc=0x0c08e0b2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c08e0b4;
P_0c08e0b4: /* original 2f26, guest PC 0x0c08e0b4 */
if(!s->budget--) { s->failed_pc=0x0c08e0b4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e0b6;
P_0c08e0b6: /* original 2fe6, guest PC 0x0c08e0b6 */
if(!s->budget--) { s->failed_pc=0x0c08e0b6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e0b8;
P_0c08e0b8: /* original d378, guest PC 0x0c08e0b8 */
if(!s->budget--) { s->failed_pc=0x0c08e0b8u; return 0; }
r[3]=read(ram,0x0c08e29cu,4);
goto P_0c08e0ba;
P_0c08e0ba: /* original 430b, guest PC 0x0c08e0ba */
if(!s->budget--) { s->failed_pc=0x0c08e0bau; return 0; }
target=r[3];
r[16]=code_base|0x0c08e0beu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e0beu) { target=s->pc; goto dispatch; }
goto P_0c08e0be;
P_0c08e0bc: /* original 64d3, guest PC 0x0c08e0bc */
if(!s->budget--) { s->failed_pc=0x0c08e0bcu; return 0; }
r[4]=r[13];
goto P_0c08e0be;
P_0c08e0be: /* original 7f0c, guest PC 0x0c08e0be */
if(!s->budget--) { s->failed_pc=0x0c08e0beu; return 0; }
r[15]+=0x0000000cu;
goto P_0c08e0c0;
P_0c08e0c0: /* original 4f26, guest PC 0x0c08e0c0 */
if(!s->budget--) { s->failed_pc=0x0c08e0c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08e0c2;
P_0c08e0c2: /* original 6df6, guest PC 0x0c08e0c2 */
if(!s->budget--) { s->failed_pc=0x0c08e0c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08e0c4;
P_0c08e0c4: /* original 000b, guest PC 0x0c08e0c4 */
if(!s->budget--) { s->failed_pc=0x0c08e0c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08e0c6: /* original 6ef6, guest PC 0x0c08e0c6 */
if(!s->budget--) { s->failed_pc=0x0c08e0c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08e0c8u,s,ram);
P_0c096864: /* original 2fe6, guest PC 0x0c096864 */
if(!s->budget--) { s->failed_pc=0x0c096864u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096866;
P_0c096866: /* original 4f22, guest PC 0x0c096866 */
if(!s->budget--) { s->failed_pc=0x0c096866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096868;
P_0c096868: /* original 7ff8, guest PC 0x0c096868 */
if(!s->budget--) { s->failed_pc=0x0c096868u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09686a;
P_0c09686a: /* original 2f42, guest PC 0x0c09686a */
if(!s->budget--) { s->failed_pc=0x0c09686au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09686c;
P_0c09686c: /* original d311, guest PC 0x0c09686c */
if(!s->budget--) { s->failed_pc=0x0c09686cu; return 0; }
r[3]=read(ram,0x0c0968b4u,4);
goto P_0c09686e;
P_0c09686e: /* original 430b, guest PC 0x0c09686e */
if(!s->budget--) { s->failed_pc=0x0c09686eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096872u;
write(ram,r[15]+4,r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096872u) { target=s->pc; goto dispatch; }
goto P_0c096872;
P_0c096870: /* original 1f51, guest PC 0x0c096870 */
if(!s->budget--) { s->failed_pc=0x0c096870u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c096872;
P_0c096872: /* original 6e03, guest PC 0x0c096872 */
if(!s->budget--) { s->failed_pc=0x0c096872u; return 0; }
r[14]=r[0];
goto P_0c096874;
P_0c096874: /* original 2ee8, guest PC 0x0c096874 */
if(!s->budget--) { s->failed_pc=0x0c096874u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c096876;
P_0c096876: /* original 8905, guest PC 0x0c096876 */
if(!s->budget--) { s->failed_pc=0x0c096876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096884; }
goto P_0c096878;
P_0c096878: /* original d30f, guest PC 0x0c096878 */
if(!s->budget--) { s->failed_pc=0x0c096878u; return 0; }
r[3]=read(ram,0x0c0968b8u,4);
goto P_0c09687a;
P_0c09687a: /* original 430b, guest PC 0x0c09687a */
if(!s->budget--) { s->failed_pc=0x0c09687au; return 0; }
target=r[3];
r[16]=code_base|0x0c09687eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09687eu) { target=s->pc; goto dispatch; }
goto P_0c09687e;
P_0c09687c: /* original 64e3, guest PC 0x0c09687c */
if(!s->budget--) { s->failed_pc=0x0c09687cu; return 0; }
r[4]=r[14];
goto P_0c09687e;
P_0c09687e: /* original d20f, guest PC 0x0c09687e */
if(!s->budget--) { s->failed_pc=0x0c09687eu; return 0; }
r[2]=read(ram,0x0c0968bcu,4);
goto P_0c096880;
P_0c096880: /* original 420b, guest PC 0x0c096880 */
if(!s->budget--) { s->failed_pc=0x0c096880u; return 0; }
target=r[2];
r[16]=code_base|0x0c096884u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096884u) { target=s->pc; goto dispatch; }
goto P_0c096884;
P_0c096882: /* original 64e3, guest PC 0x0c096882 */
if(!s->budget--) { s->failed_pc=0x0c096882u; return 0; }
r[4]=r[14];
goto P_0c096884;
P_0c096884: /* original 0002, guest PC 0x0c096884 */
if(!s->budget--) { s->failed_pc=0x0c096884u; return 0; }
r[0]=r[17];
goto P_0c096886;
P_0c096886: /* original 9313, guest PC 0x0c096886 */
if(!s->budget--) { s->failed_pc=0x0c096886u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c096888;
P_0c096888: /* original 2039, guest PC 0x0c096888 */
if(!s->budget--) { s->failed_pc=0x0c096888u; return 0; }
r[0]&=r[3];
goto P_0c09688a;
P_0c09688a: /* original cbe0, guest PC 0x0c09688a */
if(!s->budget--) { s->failed_pc=0x0c09688au; return 0; }
r[0]|=224u;
goto P_0c09688c;
P_0c09688c: /* original 400e, guest PC 0x0c09688c */
if(!s->budget--) { s->failed_pc=0x0c09688cu; return 0; }
r[17]=r[0];
goto P_0c09688e;
P_0c09688e: /* original d20c, guest PC 0x0c09688e */
if(!s->budget--) { s->failed_pc=0x0c09688eu; return 0; }
r[2]=read(ram,0x0c0968c0u,4);
goto P_0c096890;
P_0c096890: /* original 420b, guest PC 0x0c096890 */
if(!s->budget--) { s->failed_pc=0x0c096890u; return 0; }
target=r[2];
r[16]=code_base|0x0c096894u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096894u) { target=s->pc; goto dispatch; }
goto P_0c096894;
P_0c096892: /* original 0009, guest PC 0x0c096892 */
if(!s->budget--) { s->failed_pc=0x0c096892u; return 0; }
goto P_0c096894;
P_0c096894: /* original d10b, guest PC 0x0c096894 */
if(!s->budget--) { s->failed_pc=0x0c096894u; return 0; }
r[1]=read(ram,0x0c0968c4u,4);
goto P_0c096896;
P_0c096896: /* original 410b, guest PC 0x0c096896 */
if(!s->budget--) { s->failed_pc=0x0c096896u; return 0; }
target=r[1];
r[16]=code_base|0x0c09689au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09689au) { target=s->pc; goto dispatch; }
goto P_0c09689a;
P_0c096898: /* original 0009, guest PC 0x0c096898 */
if(!s->budget--) { s->failed_pc=0x0c096898u; return 0; }
goto P_0c09689a;
P_0c09689a: /* original 0002, guest PC 0x0c09689a */
if(!s->budget--) { s->failed_pc=0x0c09689au; return 0; }
r[0]=r[17];
goto P_0c09689c;
P_0c09689c: /* original 9208, guest PC 0x0c09689c */
if(!s->budget--) { s->failed_pc=0x0c09689cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c09689e;
P_0c09689e: /* original 2029, guest PC 0x0c09689e */
if(!s->budget--) { s->failed_pc=0x0c09689eu; return 0; }
r[0]&=r[2];
goto P_0c0968a0;
P_0c0968a0: /* original 400e, guest PC 0x0c0968a0 */
if(!s->budget--) { s->failed_pc=0x0c0968a0u; return 0; }
r[17]=r[0];
goto P_0c0968a2;
P_0c0968a2: /* original 64f2, guest PC 0x0c0968a2 */
if(!s->budget--) { s->failed_pc=0x0c0968a2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0968a4;
P_0c0968a4: /* original 55f1, guest PC 0x0c0968a4 */
if(!s->budget--) { s->failed_pc=0x0c0968a4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0968a6;
P_0c0968a6: /* original 7f08, guest PC 0x0c0968a6 */
if(!s->budget--) { s->failed_pc=0x0c0968a6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0968a8;
P_0c0968a8: /* original 4f26, guest PC 0x0c0968a8 */
if(!s->budget--) { s->failed_pc=0x0c0968a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0968aa;
P_0c0968aa: /* original d307, guest PC 0x0c0968aa */
if(!s->budget--) { s->failed_pc=0x0c0968aau; return 0; }
r[3]=read(ram,0x0c0968c8u,4);
goto P_0c0968ac;
P_0c0968ac: /* original 432b, guest PC 0x0c0968ac */
if(!s->budget--) { s->failed_pc=0x0c0968acu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0968ae: /* original 6ef6, guest PC 0x0c0968ae */
if(!s->budget--) { s->failed_pc=0x0c0968aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0968b0u,s,ram);
P_0c0a2984: /* original 2fe6, guest PC 0x0c0a2984 */
if(!s->budget--) { s->failed_pc=0x0c0a2984u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2986;
P_0c0a2986: /* original 6e43, guest PC 0x0c0a2986 */
if(!s->budget--) { s->failed_pc=0x0c0a2986u; return 0; }
r[14]=r[4];
goto P_0c0a2988;
P_0c0a2988: /* original 2fd6, guest PC 0x0c0a2988 */
if(!s->budget--) { s->failed_pc=0x0c0a2988u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298a;
P_0c0a298a: /* original 2fc6, guest PC 0x0c0a298a */
if(!s->budget--) { s->failed_pc=0x0c0a298au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298c;
P_0c0a298c: /* original 2fb6, guest PC 0x0c0a298c */
if(!s->budget--) { s->failed_pc=0x0c0a298cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298e;
P_0c0a298e: /* original 2fa6, guest PC 0x0c0a298e */
if(!s->budget--) { s->failed_pc=0x0c0a298eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2990;
P_0c0a2990: /* original 2f96, guest PC 0x0c0a2990 */
if(!s->budget--) { s->failed_pc=0x0c0a2990u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2992;
P_0c0a2992: /* original 2f86, guest PC 0x0c0a2992 */
if(!s->budget--) { s->failed_pc=0x0c0a2992u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2994;
P_0c0a2994: /* original 4f22, guest PC 0x0c0a2994 */
if(!s->budget--) { s->failed_pc=0x0c0a2994u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2996;
P_0c0a2996: /* original 7ff8, guest PC 0x0c0a2996 */
if(!s->budget--) { s->failed_pc=0x0c0a2996u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2998;
P_0c0a2998: /* original 2f61, guest PC 0x0c0a2998 */
if(!s->budget--) { s->failed_pc=0x0c0a2998u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c0a299a;
P_0c0a299a: /* original b14c, guest PC 0x0c0a299a */
if(!s->budget--) { s->failed_pc=0x0c0a299au; return 0; }
target=0x0c0a2c36u; r[16]=code_base|0x0c0a299eu;
r[10]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a299eu) { target=s->pc; goto dispatch; }
goto P_0c0a299e;
P_0c0a299c: /* original 6a53, guest PC 0x0c0a299c */
if(!s->budget--) { s->failed_pc=0x0c0a299cu; return 0; }
r[10]=r[5];
goto P_0c0a299e;
P_0c0a299e: /* original 6403, guest PC 0x0c0a299e */
if(!s->budget--) { s->failed_pc=0x0c0a299eu; return 0; }
r[4]=r[0];
goto P_0c0a29a0;
P_0c0a29a0: /* original 2448, guest PC 0x0c0a29a0 */
if(!s->budget--) { s->failed_pc=0x0c0a29a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a29a2;
P_0c0a29a2: /* original 8902, guest PC 0x0c0a29a2 */
if(!s->budget--) { s->failed_pc=0x0c0a29a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a29aa; }
goto P_0c0a29a4;
P_0c0a29a4: /* original d375, guest PC 0x0c0a29a4 */
if(!s->budget--) { s->failed_pc=0x0c0a29a4u; return 0; }
r[3]=read(ram,0x0c0a2b7cu,4);
goto P_0c0a29a6;
P_0c0a29a6: /* original 3430, guest PC 0x0c0a29a6 */
if(!s->budget--) { s->failed_pc=0x0c0a29a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0a29a8;
P_0c0a29a8: /* original 8b59, guest PC 0x0c0a29a8 */
if(!s->budget--) { s->failed_pc=0x0c0a29a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29aa;
P_0c0a29aa: /* original e020, guest PC 0x0c0a29aa */
if(!s->budget--) { s->failed_pc=0x0c0a29aau; return 0; }
r[0]=0x00000020u;
goto P_0c0a29ac;
P_0c0a29ac: /* original 01ed, guest PC 0x0c0a29ac */
if(!s->budget--) { s->failed_pc=0x0c0a29acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ae;
P_0c0a29ae: /* original e022, guest PC 0x0c0a29ae */
if(!s->budget--) { s->failed_pc=0x0c0a29aeu; return 0; }
r[0]=0x00000022u;
goto P_0c0a29b0;
P_0c0a29b0: /* original 03ed, guest PC 0x0c0a29b0 */
if(!s->budget--) { s->failed_pc=0x0c0a29b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29b2;
P_0c0a29b2: /* original 611d, guest PC 0x0c0a29b2 */
if(!s->budget--) { s->failed_pc=0x0c0a29b2u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a29b4;
P_0c0a29b4: /* original 633d, guest PC 0x0c0a29b4 */
if(!s->budget--) { s->failed_pc=0x0c0a29b4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a29b6;
P_0c0a29b6: /* original 213b, guest PC 0x0c0a29b6 */
if(!s->budget--) { s->failed_pc=0x0c0a29b6u; return 0; }
r[1]|=r[3];
goto P_0c0a29b8;
P_0c0a29b8: /* original 2118, guest PC 0x0c0a29b8 */
if(!s->budget--) { s->failed_pc=0x0c0a29b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a29ba;
P_0c0a29ba: /* original 8b50, guest PC 0x0c0a29ba */
if(!s->budget--) { s->failed_pc=0x0c0a29bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29bc;
P_0c0a29bc: /* original e020, guest PC 0x0c0a29bc */
if(!s->budget--) { s->failed_pc=0x0c0a29bcu; return 0; }
r[0]=0x00000020u;
goto P_0c0a29be;
P_0c0a29be: /* original 52e4, guest PC 0x0c0a29be */
if(!s->budget--) { s->failed_pc=0x0c0a29beu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0a29c0;
P_0c0a29c0: /* original 1f21, guest PC 0x0c0a29c0 */
if(!s->budget--) { s->failed_pc=0x0c0a29c0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a29c2;
P_0c0a29c2: /* original 63f1, guest PC 0x0c0a29c2 */
if(!s->budget--) { s->failed_pc=0x0c0a29c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a29c4;
P_0c0a29c4: /* original 5ce5, guest PC 0x0c0a29c4 */
if(!s->budget--) { s->failed_pc=0x0c0a29c4u; return 0; }
r[12]=read(ram,r[14]+20,4);
goto P_0c0a29c6;
P_0c0a29c6: /* original 0e35, guest PC 0x0c0a29c6 */
if(!s->budget--) { s->failed_pc=0x0c0a29c6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a29c8;
P_0c0a29c8: /* original 04ed, guest PC 0x0c0a29c8 */
if(!s->budget--) { s->failed_pc=0x0c0a29c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ca;
P_0c0a29ca: /* original d36d, guest PC 0x0c0a29ca */
if(!s->budget--) { s->failed_pc=0x0c0a29cau; return 0; }
r[3]=read(ram,0x0c0a2b80u,4);
goto P_0c0a29cc;
P_0c0a29cc: /* original 430b, guest PC 0x0c0a29cc */
if(!s->budget--) { s->failed_pc=0x0c0a29ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a29d0u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a29d0u) { target=s->pc; goto dispatch; }
goto P_0c0a29d0;
P_0c0a29ce: /* original 644d, guest PC 0x0c0a29ce */
if(!s->budget--) { s->failed_pc=0x0c0a29ceu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a29d0;
P_0c0a29d0: /* original eb00, guest PC 0x0c0a29d0 */
if(!s->budget--) { s->failed_pc=0x0c0a29d0u; return 0; }
r[11]=0x00000000u;
goto P_0c0a29d2;
P_0c0a29d2: /* original a039, guest PC 0x0c0a29d2 */
if(!s->budget--) { s->failed_pc=0x0c0a29d2u; return 0; }
r[8]=r[11];
goto P_0c0a2a48;
P_0c0a29d4: /* original 68b3, guest PC 0x0c0a29d4 */
if(!s->budget--) { s->failed_pc=0x0c0a29d4u; return 0; }
r[8]=r[11];
goto P_0c0a29d6;
P_0c0a29d6: /* original 53f1, guest PC 0x0c0a29d6 */
if(!s->budget--) { s->failed_pc=0x0c0a29d6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a29d8;
P_0c0a29d8: /* original 6d83, guest PC 0x0c0a29d8 */
if(!s->budget--) { s->failed_pc=0x0c0a29d8u; return 0; }
r[13]=r[8];
goto P_0c0a29da;
P_0c0a29da: /* original 4d08, guest PC 0x0c0a29da */
if(!s->budget--) { s->failed_pc=0x0c0a29dau; return 0; }
r[13]<<=2;
goto P_0c0a29dc;
P_0c0a29dc: /* original 3d3c, guest PC 0x0c0a29dc */
if(!s->budget--) { s->failed_pc=0x0c0a29dcu; return 0; }
r[13]+=r[3];
goto P_0c0a29de;
P_0c0a29de: /* original 60d2, guest PC 0x0c0a29de */
if(!s->budget--) { s->failed_pc=0x0c0a29deu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a29e0;
P_0c0a29e0: /* original 5001, guest PC 0x0c0a29e0 */
if(!s->budget--) { s->failed_pc=0x0c0a29e0u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0a29e2;
P_0c0a29e2: /* original c801, guest PC 0x0c0a29e2 */
if(!s->budget--) { s->failed_pc=0x0c0a29e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a29e4;
P_0c0a29e4: /* original 8922, guest PC 0x0c0a29e4 */
if(!s->budget--) { s->failed_pc=0x0c0a29e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2a2c; }
goto P_0c0a29e6;
P_0c0a29e6: /* original a008, guest PC 0x0c0a29e6 */
if(!s->budget--) { s->failed_pc=0x0c0a29e6u; return 0; }
r[4]=r[11];
goto P_0c0a29fa;
P_0c0a29e8: /* original 64b3, guest PC 0x0c0a29e8 */
if(!s->budget--) { s->failed_pc=0x0c0a29e8u; return 0; }
r[4]=r[11];
goto P_0c0a29ea;
P_0c0a29ea: /* original 6343, guest PC 0x0c0a29ea */
if(!s->budget--) { s->failed_pc=0x0c0a29eau; return 0; }
r[3]=r[4];
goto P_0c0a29ec;
P_0c0a29ec: /* original 4308, guest PC 0x0c0a29ec */
if(!s->budget--) { s->failed_pc=0x0c0a29ecu; return 0; }
r[3]<<=2;
goto P_0c0a29ee;
P_0c0a29ee: /* original 4308, guest PC 0x0c0a29ee */
if(!s->budget--) { s->failed_pc=0x0c0a29eeu; return 0; }
r[3]<<=2;
goto P_0c0a29f0;
P_0c0a29f0: /* original 33cc, guest PC 0x0c0a29f0 */
if(!s->budget--) { s->failed_pc=0x0c0a29f0u; return 0; }
r[3]+=r[12];
goto P_0c0a29f2;
P_0c0a29f2: /* original 5232, guest PC 0x0c0a29f2 */
if(!s->budget--) { s->failed_pc=0x0c0a29f2u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a29f4;
P_0c0a29f4: /* original 7401, guest PC 0x0c0a29f4 */
if(!s->budget--) { s->failed_pc=0x0c0a29f4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a29f6;
P_0c0a29f6: /* original 32ac, guest PC 0x0c0a29f6 */
if(!s->budget--) { s->failed_pc=0x0c0a29f6u; return 0; }
r[2]+=r[10];
goto P_0c0a29f8;
P_0c0a29f8: /* original 1322, guest PC 0x0c0a29f8 */
if(!s->budget--) { s->failed_pc=0x0c0a29f8u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a29fa;
P_0c0a29fa: /* original 85e7, guest PC 0x0c0a29fa */
if(!s->budget--) { s->failed_pc=0x0c0a29fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a29fc;
P_0c0a29fc: /* original 600d, guest PC 0x0c0a29fc */
if(!s->budget--) { s->failed_pc=0x0c0a29fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a29fe;
P_0c0a29fe: /* original 3403, guest PC 0x0c0a29fe */
if(!s->budget--) { s->failed_pc=0x0c0a29feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a00;
P_0c0a2a00: /* original 8bf3, guest PC 0x0c0a2a00 */
if(!s->budget--) { s->failed_pc=0x0c0a2a00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29ea; }
goto P_0c0a2a02;
P_0c0a2a02: /* original d260, guest PC 0x0c0a2a02 */
if(!s->budget--) { s->failed_pc=0x0c0a2a02u; return 0; }
r[2]=read(ram,0x0c0a2b84u,4);
goto P_0c0a2a04;
P_0c0a2a04: /* original 65c3, guest PC 0x0c0a2a04 */
if(!s->budget--) { s->failed_pc=0x0c0a2a04u; return 0; }
r[5]=r[12];
goto P_0c0a2a06;
P_0c0a2a06: /* original 420b, guest PC 0x0c0a2a06 */
if(!s->budget--) { s->failed_pc=0x0c0a2a06u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2a0au;
tmp=read(ram,r[13],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2a0au) { target=s->pc; goto dispatch; }
goto P_0c0a2a0a;
P_0c0a2a08: /* original 64d2, guest PC 0x0c0a2a08 */
if(!s->budget--) { s->failed_pc=0x0c0a2a08u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a0a;
P_0c0a2a0a: /* original 2008, guest PC 0x0c0a2a0a */
if(!s->budget--) { s->failed_pc=0x0c0a2a0au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a0c;
P_0c0a2a0c: /* original a008, guest PC 0x0c0a2a0c */
if(!s->budget--) { s->failed_pc=0x0c0a2a0cu; return 0; }
r[4]=r[11];
goto P_0c0a2a20;
P_0c0a2a0e: /* original 64b3, guest PC 0x0c0a2a0e */
if(!s->budget--) { s->failed_pc=0x0c0a2a0eu; return 0; }
r[4]=r[11];
goto P_0c0a2a10;
P_0c0a2a10: /* original 6343, guest PC 0x0c0a2a10 */
if(!s->budget--) { s->failed_pc=0x0c0a2a10u; return 0; }
r[3]=r[4];
goto P_0c0a2a12;
P_0c0a2a12: /* original 4308, guest PC 0x0c0a2a12 */
if(!s->budget--) { s->failed_pc=0x0c0a2a12u; return 0; }
r[3]<<=2;
goto P_0c0a2a14;
P_0c0a2a14: /* original 4308, guest PC 0x0c0a2a14 */
if(!s->budget--) { s->failed_pc=0x0c0a2a14u; return 0; }
r[3]<<=2;
goto P_0c0a2a16;
P_0c0a2a16: /* original 33cc, guest PC 0x0c0a2a16 */
if(!s->budget--) { s->failed_pc=0x0c0a2a16u; return 0; }
r[3]+=r[12];
goto P_0c0a2a18;
P_0c0a2a18: /* original 5232, guest PC 0x0c0a2a18 */
if(!s->budget--) { s->failed_pc=0x0c0a2a18u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2a1a;
P_0c0a2a1a: /* original 7401, guest PC 0x0c0a2a1a */
if(!s->budget--) { s->failed_pc=0x0c0a2a1au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2a1c;
P_0c0a2a1c: /* original 32a8, guest PC 0x0c0a2a1c */
if(!s->budget--) { s->failed_pc=0x0c0a2a1cu; return 0; }
r[2]-=r[10];
goto P_0c0a2a1e;
P_0c0a2a1e: /* original 1322, guest PC 0x0c0a2a1e */
if(!s->budget--) { s->failed_pc=0x0c0a2a1eu; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2a20;
P_0c0a2a20: /* original 85e7, guest PC 0x0c0a2a20 */
if(!s->budget--) { s->failed_pc=0x0c0a2a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a22;
P_0c0a2a22: /* original 600d, guest PC 0x0c0a2a22 */
if(!s->budget--) { s->failed_pc=0x0c0a2a22u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a24;
P_0c0a2a24: /* original 3403, guest PC 0x0c0a2a24 */
if(!s->budget--) { s->failed_pc=0x0c0a2a24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a26;
P_0c0a2a26: /* original 8bf3, guest PC 0x0c0a2a26 */
if(!s->budget--) { s->failed_pc=0x0c0a2a26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a10; }
goto P_0c0a2a28;
P_0c0a2a28: /* original a00d, guest PC 0x0c0a2a28 */
if(!s->budget--) { s->failed_pc=0x0c0a2a28u; return 0; }
goto P_0c0a2a46;
P_0c0a2a2a: /* original 0009, guest PC 0x0c0a2a2a */
if(!s->budget--) { s->failed_pc=0x0c0a2a2au; return 0; }
goto P_0c0a2a2c;
P_0c0a2a2c: /* original 64d2, guest PC 0x0c0a2a2c */
if(!s->budget--) { s->failed_pc=0x0c0a2a2cu; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a2e;
P_0c0a2a2e: /* original 66a3, guest PC 0x0c0a2a2e */
if(!s->budget--) { s->failed_pc=0x0c0a2a2eu; return 0; }
r[6]=r[10];
goto P_0c0a2a30;
P_0c0a2a30: /* original d355, guest PC 0x0c0a2a30 */
if(!s->budget--) { s->failed_pc=0x0c0a2a30u; return 0; }
r[3]=read(ram,0x0c0a2b88u,4);
goto P_0c0a2a32;
P_0c0a2a32: /* original 65c3, guest PC 0x0c0a2a32 */
if(!s->budget--) { s->failed_pc=0x0c0a2a32u; return 0; }
r[5]=r[12];
goto P_0c0a2a34;
P_0c0a2a34: /* original 430b, guest PC 0x0c0a2a34 */
if(!s->budget--) { s->failed_pc=0x0c0a2a34u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a38u;
r[4]=read(ram,r[4]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2a38u) { target=s->pc; goto dispatch; }
goto P_0c0a2a38;
P_0c0a2a36: /* original 5441, guest PC 0x0c0a2a36 */
if(!s->budget--) { s->failed_pc=0x0c0a2a36u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2a38;
P_0c0a2a38: /* original 69d2, guest PC 0x0c0a2a38 */
if(!s->budget--) { s->failed_pc=0x0c0a2a38u; return 0; }
tmp=read(ram,r[13],4);
r[9]=tmp;
goto P_0c0a2a3a;
P_0c0a2a3a: /* original 2008, guest PC 0x0c0a2a3a */
if(!s->budget--) { s->failed_pc=0x0c0a2a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a3c;
P_0c0a2a3c: /* original d353, guest PC 0x0c0a2a3c */
if(!s->budget--) { s->failed_pc=0x0c0a2a3cu; return 0; }
r[3]=read(ram,0x0c0a2b8cu,4);
goto P_0c0a2a3e;
P_0c0a2a3e: /* original 5591, guest PC 0x0c0a2a3e */
if(!s->budget--) { s->failed_pc=0x0c0a2a3eu; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0a2a40;
P_0c0a2a40: /* original 5692, guest PC 0x0c0a2a40 */
if(!s->budget--) { s->failed_pc=0x0c0a2a40u; return 0; }
r[6]=read(ram,r[9]+8,4);
goto P_0c0a2a42;
P_0c0a2a42: /* original 430b, guest PC 0x0c0a2a42 */
if(!s->budget--) { s->failed_pc=0x0c0a2a42u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a46u;
tmp=read(ram,r[9],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2a46u) { target=s->pc; goto dispatch; }
goto P_0c0a2a46;
P_0c0a2a44: /* original 6492, guest PC 0x0c0a2a44 */
if(!s->budget--) { s->failed_pc=0x0c0a2a44u; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0a2a46;
P_0c0a2a46: /* original 7801, guest PC 0x0c0a2a46 */
if(!s->budget--) { s->failed_pc=0x0c0a2a46u; return 0; }
r[8]+=0x00000001u;
goto P_0c0a2a48;
P_0c0a2a48: /* original 85e6, guest PC 0x0c0a2a48 */
if(!s->budget--) { s->failed_pc=0x0c0a2a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2a4a;
P_0c0a2a4a: /* original 600d, guest PC 0x0c0a2a4a */
if(!s->budget--) { s->failed_pc=0x0c0a2a4au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a4c;
P_0c0a2a4c: /* original 3803, guest PC 0x0c0a2a4c */
if(!s->budget--) { s->failed_pc=0x0c0a2a4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[0])!=0);
goto P_0c0a2a4e;
P_0c0a2a4e: /* original 8bc2, guest PC 0x0c0a2a4e */
if(!s->budget--) { s->failed_pc=0x0c0a2a4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29d6; }
goto P_0c0a2a50;
P_0c0a2a50: /* original 63f1, guest PC 0x0c0a2a50 */
if(!s->budget--) { s->failed_pc=0x0c0a2a50u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2a52;
P_0c0a2a52: /* original e222, guest PC 0x0c0a2a52 */
if(!s->budget--) { s->failed_pc=0x0c0a2a52u; return 0; }
r[2]=0x00000022u;
goto P_0c0a2a54;
P_0c0a2a54: /* original 85e7, guest PC 0x0c0a2a54 */
if(!s->budget--) { s->failed_pc=0x0c0a2a54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a56;
P_0c0a2a56: /* original 32ec, guest PC 0x0c0a2a56 */
if(!s->budget--) { s->failed_pc=0x0c0a2a56u; return 0; }
r[2]+=r[14];
goto P_0c0a2a58;
P_0c0a2a58: /* original 64b3, guest PC 0x0c0a2a58 */
if(!s->budget--) { s->failed_pc=0x0c0a2a58u; return 0; }
r[4]=r[11];
goto P_0c0a2a5a;
P_0c0a2a5a: /* original 303c, guest PC 0x0c0a2a5a */
if(!s->budget--) { s->failed_pc=0x0c0a2a5au; return 0; }
r[0]+=r[3];
goto P_0c0a2a5c;
P_0c0a2a5c: /* original 2201, guest PC 0x0c0a2a5c */
if(!s->budget--) { s->failed_pc=0x0c0a2a5cu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a2a5e;
P_0c0a2a5e: /* original 7f08, guest PC 0x0c0a2a5e */
if(!s->budget--) { s->failed_pc=0x0c0a2a5eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a2a60;
P_0c0a2a60: /* original 6043, guest PC 0x0c0a2a60 */
if(!s->budget--) { s->failed_pc=0x0c0a2a60u; return 0; }
r[0]=r[4];
goto P_0c0a2a62;
P_0c0a2a62: /* original 4f26, guest PC 0x0c0a2a62 */
if(!s->budget--) { s->failed_pc=0x0c0a2a62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2a64;
P_0c0a2a64: /* original 68f6, guest PC 0x0c0a2a64 */
if(!s->budget--) { s->failed_pc=0x0c0a2a64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2a66;
P_0c0a2a66: /* original 69f6, guest PC 0x0c0a2a66 */
if(!s->budget--) { s->failed_pc=0x0c0a2a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2a68;
P_0c0a2a68: /* original 6af6, guest PC 0x0c0a2a68 */
if(!s->budget--) { s->failed_pc=0x0c0a2a68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2a6a;
P_0c0a2a6a: /* original 6bf6, guest PC 0x0c0a2a6a */
if(!s->budget--) { s->failed_pc=0x0c0a2a6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2a6c;
P_0c0a2a6c: /* original 6cf6, guest PC 0x0c0a2a6c */
if(!s->budget--) { s->failed_pc=0x0c0a2a6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2a6e;
P_0c0a2a6e: /* original 6df6, guest PC 0x0c0a2a6e */
if(!s->budget--) { s->failed_pc=0x0c0a2a6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2a70;
P_0c0a2a70: /* original 000b, guest PC 0x0c0a2a70 */
if(!s->budget--) { s->failed_pc=0x0c0a2a70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2a72: /* original 6ef6, guest PC 0x0c0a2a72 */
if(!s->budget--) { s->failed_pc=0x0c0a2a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a2a74u,s,ram);
P_0c0a2e86: /* original 2fe6, guest PC 0x0c0a2e86 */
if(!s->budget--) { s->failed_pc=0x0c0a2e86u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2e88;
P_0c0a2e88: /* original 4411, guest PC 0x0c0a2e88 */
if(!s->budget--) { s->failed_pc=0x0c0a2e88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a2e8a;
P_0c0a2e8a: /* original 2fd6, guest PC 0x0c0a2e8a */
if(!s->budget--) { s->failed_pc=0x0c0a2e8au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2e8c;
P_0c0a2e8c: /* original 4f22, guest PC 0x0c0a2e8c */
if(!s->budget--) { s->failed_pc=0x0c0a2e8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2e8e;
P_0c0a2e8e: /* original 8b1c, guest PC 0x0c0a2e8e */
if(!s->budget--) { s->failed_pc=0x0c0a2e8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2eca; }
goto P_0c0a2e90;
P_0c0a2e90: /* original e21a, guest PC 0x0c0a2e90 */
if(!s->budget--) { s->failed_pc=0x0c0a2e90u; return 0; }
r[2]=0x0000001au;
goto P_0c0a2e92;
P_0c0a2e92: /* original 3423, guest PC 0x0c0a2e92 */
if(!s->budget--) { s->failed_pc=0x0c0a2e92u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0a2e94;
P_0c0a2e94: /* original 8919, guest PC 0x0c0a2e94 */
if(!s->budget--) { s->failed_pc=0x0c0a2e94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2eca; }
goto P_0c0a2e96;
P_0c0a2e96: /* original 6e43, guest PC 0x0c0a2e96 */
if(!s->budget--) { s->failed_pc=0x0c0a2e96u; return 0; }
r[14]=r[4];
goto P_0c0a2e98;
P_0c0a2e98: /* original 4e08, guest PC 0x0c0a2e98 */
if(!s->budget--) { s->failed_pc=0x0c0a2e98u; return 0; }
r[14]<<=2;
goto P_0c0a2e9a;
P_0c0a2e9a: /* original 4e00, guest PC 0x0c0a2e9a */
if(!s->budget--) { s->failed_pc=0x0c0a2e9au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0a2e9c;
P_0c0a2e9c: /* original 6343, guest PC 0x0c0a2e9c */
if(!s->budget--) { s->failed_pc=0x0c0a2e9cu; return 0; }
r[3]=r[4];
goto P_0c0a2e9e;
P_0c0a2e9e: /* original 3e3c, guest PC 0x0c0a2e9e */
if(!s->budget--) { s->failed_pc=0x0c0a2e9eu; return 0; }
r[14]+=r[3];
goto P_0c0a2ea0;
P_0c0a2ea0: /* original d233, guest PC 0x0c0a2ea0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea0u; return 0; }
r[2]=read(ram,0x0c0a2f70u,4);
goto P_0c0a2ea2;
P_0c0a2ea2: /* original 4e08, guest PC 0x0c0a2ea2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea2u; return 0; }
r[14]<<=2;
goto P_0c0a2ea4;
P_0c0a2ea4: /* original 6eef, guest PC 0x0c0a2ea4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0a2ea6;
P_0c0a2ea6: /* original 3e2c, guest PC 0x0c0a2ea6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea6u; return 0; }
r[14]+=r[2];
goto P_0c0a2ea8;
P_0c0a2ea8: /* original 53e6, guest PC 0x0c0a2ea8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea8u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c0a2eaa;
P_0c0a2eaa: /* original 2338, guest PC 0x0c0a2eaa */
if(!s->budget--) { s->failed_pc=0x0c0a2eaau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2eac;
P_0c0a2eac: /* original 890d, guest PC 0x0c0a2eac */
if(!s->budget--) { s->failed_pc=0x0c0a2eacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2eca; }
goto P_0c0a2eae;
P_0c0a2eae: /* original 5de6, guest PC 0x0c0a2eae */
if(!s->budget--) { s->failed_pc=0x0c0a2eaeu; return 0; }
r[13]=read(ram,r[14]+24,4);
goto P_0c0a2eb0;
P_0c0a2eb0: /* original d330, guest PC 0x0c0a2eb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb0u; return 0; }
r[3]=read(ram,0x0c0a2f74u,4);
goto P_0c0a2eb2;
P_0c0a2eb2: /* original 2d3b, guest PC 0x0c0a2eb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb2u; return 0; }
r[13]|=r[3];
goto P_0c0a2eb4;
P_0c0a2eb4: /* original 62d2, guest PC 0x0c0a2eb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb4u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0a2eb6;
P_0c0a2eb6: /* original 2228, guest PC 0x0c0a2eb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2eb8;
P_0c0a2eb8: /* original 8905, guest PC 0x0c0a2eb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2ec6; }
goto P_0c0a2eba;
P_0c0a2eba: /* original 52e8, guest PC 0x0c0a2eba */
if(!s->budget--) { s->failed_pc=0x0c0a2ebau; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c0a2ebc;
P_0c0a2ebc: /* original 420b, guest PC 0x0c0a2ebc */
if(!s->budget--) { s->failed_pc=0x0c0a2ebcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2ec0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2ec0u) { target=s->pc; goto dispatch; }
goto P_0c0a2ec0;
P_0c0a2ebe: /* original 0009, guest PC 0x0c0a2ebe */
if(!s->budget--) { s->failed_pc=0x0c0a2ebeu; return 0; }
goto P_0c0a2ec0;
P_0c0a2ec0: /* original d32d, guest PC 0x0c0a2ec0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec0u; return 0; }
r[3]=read(ram,0x0c0a2f78u,4);
goto P_0c0a2ec2;
P_0c0a2ec2: /* original 430b, guest PC 0x0c0a2ec2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ec6u;
r[4]=read(ram,r[14]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2ec6u) { target=s->pc; goto dispatch; }
goto P_0c0a2ec6;
P_0c0a2ec4: /* original 54e6, guest PC 0x0c0a2ec4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec4u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c0a2ec6;
P_0c0a2ec6: /* original e200, guest PC 0x0c0a2ec6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec6u; return 0; }
r[2]=0x00000000u;
goto P_0c0a2ec8;
P_0c0a2ec8: /* original 2d22, guest PC 0x0c0a2ec8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec8u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0a2eca;
P_0c0a2eca: /* original 4f26, guest PC 0x0c0a2eca */
if(!s->budget--) { s->failed_pc=0x0c0a2ecau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2ecc;
P_0c0a2ecc: /* original 6df6, guest PC 0x0c0a2ecc */
if(!s->budget--) { s->failed_pc=0x0c0a2eccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2ece;
P_0c0a2ece: /* original 000b, guest PC 0x0c0a2ece */
if(!s->budget--) { s->failed_pc=0x0c0a2eceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2ed0: /* original 6ef6, guest PC 0x0c0a2ed0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ed0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a2ed2u,s,ram);
P_0c0a7f5a: /* original 2fe6, guest PC 0x0c0a7f5a */
if(!s->budget--) { s->failed_pc=0x0c0a7f5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5c;
P_0c0a7f5c: /* original 2fd6, guest PC 0x0c0a7f5c */
if(!s->budget--) { s->failed_pc=0x0c0a7f5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5e;
P_0c0a7f5e: /* original 2fc6, guest PC 0x0c0a7f5e */
if(!s->budget--) { s->failed_pc=0x0c0a7f5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f60;
P_0c0a7f60: /* original 2fb6, guest PC 0x0c0a7f60 */
if(!s->budget--) { s->failed_pc=0x0c0a7f60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f62;
P_0c0a7f62: /* original 6b43, guest PC 0x0c0a7f62 */
if(!s->budget--) { s->failed_pc=0x0c0a7f62u; return 0; }
r[11]=r[4];
goto P_0c0a7f64;
P_0c0a7f64: /* original 2fa6, guest PC 0x0c0a7f64 */
if(!s->budget--) { s->failed_pc=0x0c0a7f64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f66;
P_0c0a7f66: /* original e400, guest PC 0x0c0a7f66 */
if(!s->budget--) { s->failed_pc=0x0c0a7f66u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7f68;
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
return vf3_matrix_family(0x0c0a7fa6u,s,ram);
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7fc8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a7fd6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7ff6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8000u;
r[5]=0x00000072u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8006u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a801au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8024u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a802au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a803cu,s,ram);
P_0c0a81ee: /* original 2fe6, guest PC 0x0c0a81ee */
if(!s->budget--) { s->failed_pc=0x0c0a81eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f0;
P_0c0a81f0: /* original 2fd6, guest PC 0x0c0a81f0 */
if(!s->budget--) { s->failed_pc=0x0c0a81f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f2;
P_0c0a81f2: /* original 2fc6, guest PC 0x0c0a81f2 */
if(!s->budget--) { s->failed_pc=0x0c0a81f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f4;
P_0c0a81f4: /* original 2fb6, guest PC 0x0c0a81f4 */
if(!s->budget--) { s->failed_pc=0x0c0a81f4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f6;
P_0c0a81f6: /* original 6b43, guest PC 0x0c0a81f6 */
if(!s->budget--) { s->failed_pc=0x0c0a81f6u; return 0; }
r[11]=r[4];
goto P_0c0a81f8;
P_0c0a81f8: /* original 2fa6, guest PC 0x0c0a81f8 */
if(!s->budget--) { s->failed_pc=0x0c0a81f8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81fa;
P_0c0a81fa: /* original eaff, guest PC 0x0c0a81fa */
if(!s->budget--) { s->failed_pc=0x0c0a81fau; return 0; }
r[10]=0xffffffffu;
goto P_0c0a81fc;
P_0c0a81fc: /* original 4f22, guest PC 0x0c0a81fc */
if(!s->budget--) { s->failed_pc=0x0c0a81fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a81fe;
P_0c0a81fe: /* original 4f12, guest PC 0x0c0a81fe */
if(!s->budget--) { s->failed_pc=0x0c0a81feu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8200;
P_0c0a8200: /* original 7ff0, guest PC 0x0c0a8200 */
if(!s->budget--) { s->failed_pc=0x0c0a8200u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8202;
P_0c0a8202: /* original 1f51, guest PC 0x0c0a8202 */
if(!s->budget--) { s->failed_pc=0x0c0a8202u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a8204;
P_0c0a8204: /* original 2f62, guest PC 0x0c0a8204 */
if(!s->budget--) { s->failed_pc=0x0c0a8204u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a8206;
P_0c0a8206: /* original 1f72, guest PC 0x0c0a8206 */
if(!s->budget--) { s->failed_pc=0x0c0a8206u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a8208;
P_0c0a8208: /* original d32a, guest PC 0x0c0a8208 */
if(!s->budget--) { s->failed_pc=0x0c0a8208u; return 0; }
r[3]=read(ram,0x0c0a82b4u,4);
goto P_0c0a820a;
P_0c0a820a: /* original 9249, guest PC 0x0c0a820a */
if(!s->budget--) { s->failed_pc=0x0c0a820au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a82a0u,2);
goto P_0c0a820c;
P_0c0a820c: /* original 6e32, guest PC 0x0c0a820c */
if(!s->budget--) { s->failed_pc=0x0c0a820cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a820e;
P_0c0a820e: /* original 3b23, guest PC 0x0c0a820e */
if(!s->budget--) { s->failed_pc=0x0c0a820eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c0a8210;
P_0c0a8210: /* original 8f03, guest PC 0x0c0a8210 */
if(!s->budget--) { s->failed_pc=0x0c0a8210u; return 0; }
cond=r[17]&1u;
r[12]=r[10];
if(!cond) { goto P_0c0a821a; }
goto P_0c0a8214;
P_0c0a8212: /* original 6ca3, guest PC 0x0c0a8212 */
if(!s->budget--) { s->failed_pc=0x0c0a8212u; return 0; }
r[12]=r[10];
goto P_0c0a8214;
P_0c0a8214: /* original dc28, guest PC 0x0c0a8214 */
if(!s->budget--) { s->failed_pc=0x0c0a8214u; return 0; }
r[12]=read(ram,0x0c0a82b8u,4);
goto P_0c0a8216;
P_0c0a8216: /* original a037, guest PC 0x0c0a8216 */
if(!s->budget--) { s->failed_pc=0x0c0a8216u; return 0; }
goto P_0c0a8288;
P_0c0a8218: /* original 0009, guest PC 0x0c0a8218 */
if(!s->budget--) { s->failed_pc=0x0c0a8218u; return 0; }
goto P_0c0a821a;
P_0c0a821a: /* original d028, guest PC 0x0c0a821a */
if(!s->budget--) { s->failed_pc=0x0c0a821au; return 0; }
r[0]=read(ram,0x0c0a82bcu,4);
goto P_0c0a821c;
P_0c0a821c: /* original 63b3, guest PC 0x0c0a821c */
if(!s->budget--) { s->failed_pc=0x0c0a821cu; return 0; }
r[3]=r[11];
goto P_0c0a821e;
P_0c0a821e: /* original 4308, guest PC 0x0c0a821e */
if(!s->budget--) { s->failed_pc=0x0c0a821eu; return 0; }
r[3]<<=2;
goto P_0c0a8220;
P_0c0a8220: /* original 023e, guest PC 0x0c0a8220 */
if(!s->budget--) { s->failed_pc=0x0c0a8220u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a8222;
P_0c0a8222: /* original 1f23, guest PC 0x0c0a8222 */
if(!s->budget--) { s->failed_pc=0x0c0a8222u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0a8224;
P_0c0a8224: /* original 63f2, guest PC 0x0c0a8224 */
if(!s->budget--) { s->failed_pc=0x0c0a8224u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a8226;
P_0c0a8226: /* original 2338, guest PC 0x0c0a8226 */
if(!s->budget--) { s->failed_pc=0x0c0a8226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a8228;
P_0c0a8228: /* original 892e, guest PC 0x0c0a8228 */
if(!s->budget--) { s->failed_pc=0x0c0a8228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a822a;
P_0c0a822a: /* original 50f1, guest PC 0x0c0a822a */
if(!s->budget--) { s->failed_pc=0x0c0a822au; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a822c;
P_0c0a822c: /* original c803, guest PC 0x0c0a822c */
if(!s->budget--) { s->failed_pc=0x0c0a822cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&3u)==0)!=0);
goto P_0c0a822e;
P_0c0a822e: /* original 8b2b, guest PC 0x0c0a822e */
if(!s->budget--) { s->failed_pc=0x0c0a822eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a8230;
P_0c0a8230: /* original 85ed, guest PC 0x0c0a8230 */
if(!s->budget--) { s->failed_pc=0x0c0a8230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8232;
P_0c0a8232: /* original ed1f, guest PC 0x0c0a8232 */
if(!s->budget--) { s->failed_pc=0x0c0a8232u; return 0; }
r[13]=0x0000001fu;
goto P_0c0a8234;
P_0c0a8234: /* original 600d, guest PC 0x0c0a8234 */
if(!s->budget--) { s->failed_pc=0x0c0a8234u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a8236;
P_0c0a8236: /* original 7001, guest PC 0x0c0a8236 */
if(!s->budget--) { s->failed_pc=0x0c0a8236u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8238;
P_0c0a8238: /* original 2d09, guest PC 0x0c0a8238 */
if(!s->budget--) { s->failed_pc=0x0c0a8238u; return 0; }
r[13]&=r[0];
goto P_0c0a823a;
P_0c0a823a: /* original 85eb, guest PC 0x0c0a823a */
if(!s->budget--) { s->failed_pc=0x0c0a823au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a823c;
P_0c0a823c: /* original 600d, guest PC 0x0c0a823c */
if(!s->budget--) { s->failed_pc=0x0c0a823cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a823e;
P_0c0a823e: /* original 3d00, guest PC 0x0c0a823e */
if(!s->budget--) { s->failed_pc=0x0c0a823eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0a8240;
P_0c0a8240: /* original 8922, guest PC 0x0c0a8240 */
if(!s->budget--) { s->failed_pc=0x0c0a8240u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a8242;
P_0c0a8242: /* original be67, guest PC 0x0c0a8242 */
if(!s->budget--) { s->failed_pc=0x0c0a8242u; return 0; }
target=0x0c0a7f14u; r[16]=code_base|0x0c0a8246u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8246u) { target=s->pc; goto dispatch; }
goto P_0c0a8246;
P_0c0a8244: /* original 64b3, guest PC 0x0c0a8244 */
if(!s->budget--) { s->failed_pc=0x0c0a8244u; return 0; }
r[4]=r[11];
goto P_0c0a8246;
P_0c0a8246: /* original 2008, guest PC 0x0c0a8246 */
if(!s->budget--) { s->failed_pc=0x0c0a8246u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8248;
P_0c0a8248: /* original 8b1e, guest PC 0x0c0a8248 */
if(!s->budget--) { s->failed_pc=0x0c0a8248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a824a;
P_0c0a824a: /* original e434, guest PC 0x0c0a824a */
if(!s->budget--) { s->failed_pc=0x0c0a824au; return 0; }
r[4]=0x00000034u;
goto P_0c0a824c;
P_0c0a824c: /* original 63e3, guest PC 0x0c0a824c */
if(!s->budget--) { s->failed_pc=0x0c0a824cu; return 0; }
r[3]=r[14];
goto P_0c0a824e;
P_0c0a824e: /* original 2d4f, guest PC 0x0c0a824e */
if(!s->budget--) { s->failed_pc=0x0c0a824eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[4]);
goto P_0c0a8250;
P_0c0a8250: /* original 731c, guest PC 0x0c0a8250 */
if(!s->budget--) { s->failed_pc=0x0c0a8250u; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8252;
P_0c0a8252: /* original 60d3, guest PC 0x0c0a8252 */
if(!s->budget--) { s->failed_pc=0x0c0a8252u; return 0; }
r[0]=r[13];
goto P_0c0a8254;
P_0c0a8254: /* original 81ed, guest PC 0x0c0a8254 */
if(!s->budget--) { s->failed_pc=0x0c0a8254u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0a8256;
P_0c0a8256: /* original e030, guest PC 0x0c0a8256 */
if(!s->budget--) { s->failed_pc=0x0c0a8256u; return 0; }
r[0]=0x00000030u;
goto P_0c0a8258;
P_0c0a8258: /* original 62f2, guest PC 0x0c0a8258 */
if(!s->budget--) { s->failed_pc=0x0c0a8258u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a825a;
P_0c0a825a: /* original 6cd3, guest PC 0x0c0a825a */
if(!s->budget--) { s->failed_pc=0x0c0a825au; return 0; }
r[12]=r[13];
goto P_0c0a825c;
P_0c0a825c: /* original 041a, guest PC 0x0c0a825c */
if(!s->budget--) { s->failed_pc=0x0c0a825cu; return 0; }
r[4]=r[19];
goto P_0c0a825e;
P_0c0a825e: /* original 644f, guest PC 0x0c0a825e */
if(!s->budget--) { s->failed_pc=0x0c0a825eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8260;
P_0c0a8260: /* original 343c, guest PC 0x0c0a8260 */
if(!s->budget--) { s->failed_pc=0x0c0a8260u; return 0; }
r[4]+=r[3];
goto P_0c0a8262;
P_0c0a8262: /* original 6323, guest PC 0x0c0a8262 */
if(!s->budget--) { s->failed_pc=0x0c0a8262u; return 0; }
r[3]=r[2];
goto P_0c0a8264;
P_0c0a8264: /* original 2422, guest PC 0x0c0a8264 */
if(!s->budget--) { s->failed_pc=0x0c0a8264u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0a8266;
P_0c0a8266: /* original e200, guest PC 0x0c0a8266 */
if(!s->budget--) { s->failed_pc=0x0c0a8266u; return 0; }
r[2]=0x00000000u;
goto P_0c0a8268;
P_0c0a8268: /* original 2322, guest PC 0x0c0a8268 */
if(!s->budget--) { s->failed_pc=0x0c0a8268u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0a826a;
P_0c0a826a: /* original 53f1, guest PC 0x0c0a826a */
if(!s->budget--) { s->failed_pc=0x0c0a826au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a826c;
P_0c0a826c: /* original 1431, guest PC 0x0c0a826c */
if(!s->budget--) { s->failed_pc=0x0c0a826cu; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a826e;
P_0c0a826e: /* original 14a7, guest PC 0x0c0a826e */
if(!s->budget--) { s->failed_pc=0x0c0a826eu; return 0; }
write(ram,r[4]+28,r[10],4);
goto P_0c0a8270;
P_0c0a8270: /* original 14a2, guest PC 0x0c0a8270 */
if(!s->budget--) { s->failed_pc=0x0c0a8270u; return 0; }
write(ram,r[4]+8,r[10],4);
goto P_0c0a8272;
P_0c0a8272: /* original 53f3, guest PC 0x0c0a8272 */
if(!s->budget--) { s->failed_pc=0x0c0a8272u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a8274;
P_0c0a8274: /* original 1434, guest PC 0x0c0a8274 */
if(!s->budget--) { s->failed_pc=0x0c0a8274u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0a8276;
P_0c0a8276: /* original 52f2, guest PC 0x0c0a8276 */
if(!s->budget--) { s->failed_pc=0x0c0a8276u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a8278;
P_0c0a8278: /* original 1425, guest PC 0x0c0a8278 */
if(!s->budget--) { s->failed_pc=0x0c0a8278u; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c0a827a;
P_0c0a827a: /* original 53fb, guest PC 0x0c0a827a */
if(!s->budget--) { s->failed_pc=0x0c0a827au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0a827c;
P_0c0a827c: /* original 1436, guest PC 0x0c0a827c */
if(!s->budget--) { s->failed_pc=0x0c0a827cu; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0a827e;
P_0c0a827e: /* original 52fc, guest PC 0x0c0a827e */
if(!s->budget--) { s->failed_pc=0x0c0a827eu; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c0a8280;
P_0c0a8280: /* original 142a, guest PC 0x0c0a8280 */
if(!s->budget--) { s->failed_pc=0x0c0a8280u; return 0; }
write(ram,r[4]+40,r[2],4);
goto P_0c0a8282;
P_0c0a8282: /* original 53fd, guest PC 0x0c0a8282 */
if(!s->budget--) { s->failed_pc=0x0c0a8282u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0a8284;
P_0c0a8284: /* original 143b, guest PC 0x0c0a8284 */
if(!s->budget--) { s->failed_pc=0x0c0a8284u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0a8286;
P_0c0a8286: /* original 04b5, guest PC 0x0c0a8286 */
if(!s->budget--) { s->failed_pc=0x0c0a8286u; return 0; }
write(ram,r[4]+r[0],r[11],2);
goto P_0c0a8288;
P_0c0a8288: /* original 7f10, guest PC 0x0c0a8288 */
if(!s->budget--) { s->failed_pc=0x0c0a8288u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a828a;
P_0c0a828a: /* original 60c3, guest PC 0x0c0a828a */
if(!s->budget--) { s->failed_pc=0x0c0a828au; return 0; }
r[0]=r[12];
goto P_0c0a828c;
P_0c0a828c: /* original 4f16, guest PC 0x0c0a828c */
if(!s->budget--) { s->failed_pc=0x0c0a828cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a828e;
P_0c0a828e: /* original 4f26, guest PC 0x0c0a828e */
if(!s->budget--) { s->failed_pc=0x0c0a828eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8290;
P_0c0a8290: /* original 6af6, guest PC 0x0c0a8290 */
if(!s->budget--) { s->failed_pc=0x0c0a8290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8292;
P_0c0a8292: /* original 6bf6, guest PC 0x0c0a8292 */
if(!s->budget--) { s->failed_pc=0x0c0a8292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8294;
P_0c0a8294: /* original 6cf6, guest PC 0x0c0a8294 */
if(!s->budget--) { s->failed_pc=0x0c0a8294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8296;
P_0c0a8296: /* original 6df6, guest PC 0x0c0a8296 */
if(!s->budget--) { s->failed_pc=0x0c0a8296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8298;
P_0c0a8298: /* original 000b, guest PC 0x0c0a8298 */
if(!s->budget--) { s->failed_pc=0x0c0a8298u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a829a: /* original 6ef6, guest PC 0x0c0a829a */
if(!s->budget--) { s->failed_pc=0x0c0a829au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a829cu,s,ram);
P_0c0c1208: /* original 2fe6, guest PC 0x0c0c1208 */
if(!s->budget--) { s->failed_pc=0x0c0c1208u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c120a;
P_0c0c120a: /* original e603, guest PC 0x0c0c120a */
if(!s->budget--) { s->failed_pc=0x0c0c120au; return 0; }
r[6]=0x00000003u;
goto P_0c0c120c;
P_0c0c120c: /* original 4f22, guest PC 0x0c0c120c */
if(!s->budget--) { s->failed_pc=0x0c0c120cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c120e;
P_0c0c120e: /* original 9063, guest PC 0x0c0c120e */
if(!s->budget--) { s->failed_pc=0x0c0c120eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12d8u,2);
goto P_0c0c1210;
P_0c0c1210: /* original 3f0c, guest PC 0x0c0c1210 */
if(!s->budget--) { s->failed_pc=0x0c0c1210u; return 0; }
r[15]+=r[0];
goto P_0c0c1212;
P_0c0c1212: /* original 2f42, guest PC 0x0c0c1212 */
if(!s->budget--) { s->failed_pc=0x0c0c1212u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c1214;
P_0c0c1214: /* original 6ef3, guest PC 0x0c0c1214 */
if(!s->budget--) { s->failed_pc=0x0c0c1214u; return 0; }
r[14]=r[15];
goto P_0c0c1216;
P_0c0c1216: /* original 9060, guest PC 0x0c0c1216 */
if(!s->budget--) { s->failed_pc=0x0c0c1216u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1218;
P_0c0c1218: /* original 30fc, guest PC 0x0c0c1218 */
if(!s->budget--) { s->failed_pc=0x0c0c1218u; return 0; }
r[0]+=r[15];
goto P_0c0c121a;
P_0c0c121a: /* original 7004, guest PC 0x0c0c121a */
if(!s->budget--) { s->failed_pc=0x0c0c121au; return 0; }
r[0]+=0x00000004u;
goto P_0c0c121c;
P_0c0c121c: /* original 2608, guest PC 0x0c0c121c */
if(!s->budget--) { s->failed_pc=0x0c0c121cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[0])==0)!=0);
goto P_0c0c121e;
P_0c0c121e: /* original 8d04, guest PC 0x0c0c121e */
if(!s->budget--) { s->failed_pc=0x0c0c121eu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000004u;
if(cond) { goto P_0c0c122a; }
goto P_0c0c1222;
P_0c0c1220: /* original 7e04, guest PC 0x0c0c1220 */
if(!s->budget--) { s->failed_pc=0x0c0c1220u; return 0; }
r[14]+=0x00000004u;
goto P_0c0c1222;
P_0c0c1222: /* original 965a, guest PC 0x0c0c1222 */
if(!s->budget--) { s->failed_pc=0x0c0c1222u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1224;
P_0c0c1224: /* original 36fc, guest PC 0x0c0c1224 */
if(!s->budget--) { s->failed_pc=0x0c0c1224u; return 0; }
r[6]+=r[15];
goto P_0c0c1226;
P_0c0c1226: /* original a003, guest PC 0x0c0c1226 */
if(!s->budget--) { s->failed_pc=0x0c0c1226u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c1230;
P_0c0c1228: /* original 7608, guest PC 0x0c0c1228 */
if(!s->budget--) { s->failed_pc=0x0c0c1228u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c122a;
P_0c0c122a: /* original 9656, guest PC 0x0c0c122a */
if(!s->budget--) { s->failed_pc=0x0c0c122au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c122c;
P_0c0c122c: /* original 36fc, guest PC 0x0c0c122c */
if(!s->budget--) { s->failed_pc=0x0c0c122cu; return 0; }
r[6]+=r[15];
goto P_0c0c122e;
P_0c0c122e: /* original 7604, guest PC 0x0c0c122e */
if(!s->budget--) { s->failed_pc=0x0c0c122eu; return 0; }
r[6]+=0x00000004u;
goto P_0c0c1230;
P_0c0c1230: /* original 9053, guest PC 0x0c0c1230 */
if(!s->budget--) { s->failed_pc=0x0c0c1230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1232;
P_0c0c1232: /* original d32d, guest PC 0x0c0c1232 */
if(!s->budget--) { s->failed_pc=0x0c0c1232u; return 0; }
r[3]=read(ram,0x0c0c12e8u,4);
goto P_0c0c1234;
P_0c0c1234: /* original 05fe, guest PC 0x0c0c1234 */
if(!s->budget--) { s->failed_pc=0x0c0c1234u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0c1236;
P_0c0c1236: /* original 430b, guest PC 0x0c0c1236 */
if(!s->budget--) { s->failed_pc=0x0c0c1236u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c123au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c123au) { target=s->pc; goto dispatch; }
goto P_0c0c123a;
P_0c0c1238: /* original 64e3, guest PC 0x0c0c1238 */
if(!s->budget--) { s->failed_pc=0x0c0c1238u; return 0; }
r[4]=r[14];
goto P_0c0c123a;
P_0c0c123a: /* original d42a, guest PC 0x0c0c123a */
if(!s->budget--) { s->failed_pc=0x0c0c123au; return 0; }
r[4]=read(ram,0x0c0c12e4u,4);
goto P_0c0c123c;
P_0c0c123c: /* original 66e3, guest PC 0x0c0c123c */
if(!s->budget--) { s->failed_pc=0x0c0c123cu; return 0; }
r[6]=r[14];
goto P_0c0c123e;
P_0c0c123e: /* original e701, guest PC 0x0c0c123e */
if(!s->budget--) { s->failed_pc=0x0c0c123eu; return 0; }
r[7]=0x00000001u;
goto P_0c0c1240;
P_0c0c1240: /* original b288, guest PC 0x0c0c1240 */
if(!s->budget--) { s->failed_pc=0x0c0c1240u; return 0; }
target=0x0c0c1754u; r[16]=code_base|0x0c0c1244u;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1244u) { target=s->pc; goto dispatch; }
goto P_0c0c1244;
P_0c0c1242: /* original 65f2, guest PC 0x0c0c1242 */
if(!s->budget--) { s->failed_pc=0x0c0c1242u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c1244;
P_0c0c1244: /* original 914a, guest PC 0x0c0c1244 */
if(!s->budget--) { s->failed_pc=0x0c0c1244u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dcu,2);
goto P_0c0c1246;
P_0c0c1246: /* original 3f1c, guest PC 0x0c0c1246 */
if(!s->budget--) { s->failed_pc=0x0c0c1246u; return 0; }
r[15]+=r[1];
goto P_0c0c1248;
P_0c0c1248: /* original 4f26, guest PC 0x0c0c1248 */
if(!s->budget--) { s->failed_pc=0x0c0c1248u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c124a;
P_0c0c124a: /* original 000b, guest PC 0x0c0c124a */
if(!s->budget--) { s->failed_pc=0x0c0c124au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c124c: /* original 6ef6, guest PC 0x0c0c124c */
if(!s->budget--) { s->failed_pc=0x0c0c124cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c124eu,s,ram);
P_0c0c182e: /* original e020, guest PC 0x0c0c182e */
if(!s->budget--) { s->failed_pc=0x0c0c182eu; return 0; }
r[0]=0x00000020u;
goto P_0c0c1830;
P_0c0c1830: /* original 0455, guest PC 0x0c0c1830 */
if(!s->budget--) { s->failed_pc=0x0c0c1830u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c0c1832;
P_0c0c1832: /* original 000b, guest PC 0x0c0c1832 */
if(!s->budget--) { s->failed_pc=0x0c0c1832u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c0c1834: /* original 6053, guest PC 0x0c0c1834 */
if(!s->budget--) { s->failed_pc=0x0c0c1834u; return 0; }
r[0]=r[5];
return vf3_matrix_family(0x0c0c1836u,s,ram);
P_0c0c3a26: /* original 4f22, guest PC 0x0c0c3a26 */
if(!s->budget--) { s->failed_pc=0x0c0c3a26u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c3a28;
P_0c0c3a28: /* original 6632, guest PC 0x0c0c3a28 */
if(!s->budget--) { s->failed_pc=0x0c0c3a28u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0c3a2a;
P_0c0c3a2a: /* original 670c, guest PC 0x0c0c3a2a */
if(!s->budget--) { s->failed_pc=0x0c0c3a2au; return 0; }
r[7]=r[0]&255u;
goto P_0c0c3a2c;
P_0c0c3a2c: /* original d214, guest PC 0x0c0c3a2c */
if(!s->budget--) { s->failed_pc=0x0c0c3a2cu; return 0; }
r[2]=read(ram,0x0c0c3a80u,4);
goto P_0c0c3a2e;
P_0c0c3a2e: /* original 2778, guest PC 0x0c0c3a2e */
if(!s->budget--) { s->failed_pc=0x0c0c3a2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c3a30;
P_0c0c3a30: /* original d411, guest PC 0x0c0c3a30 */
if(!s->budget--) { s->failed_pc=0x0c0c3a30u; return 0; }
r[4]=read(ram,0x0c0c3a78u,4);
goto P_0c0c3a32;
P_0c0c3a32: /* original 8f27, guest PC 0x0c0c3a32 */
if(!s->budget--) { s->failed_pc=0x0c0c3a32u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!cond) { goto P_0c0c3a84; }
goto P_0c0c3a36;
P_0c0c3a34: /* original 6522, guest PC 0x0c0c3a34 */
if(!s->budget--) { s->failed_pc=0x0c0c3a34u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c3a36;
P_0c0c3a36: /* original 6743, guest PC 0x0c0c3a36 */
if(!s->budget--) { s->failed_pc=0x0c0c3a36u; return 0; }
r[7]=r[4];
goto P_0c0c3a38;
P_0c0c3a38: /* original 6a43, guest PC 0x0c0c3a38 */
if(!s->budget--) { s->failed_pc=0x0c0c3a38u; return 0; }
r[10]=r[4];
goto P_0c0c3a3a;
P_0c0c3a3a: /* original 6c43, guest PC 0x0c0c3a3a */
if(!s->budget--) { s->failed_pc=0x0c0c3a3au; return 0; }
r[12]=r[4];
goto P_0c0c3a3c;
P_0c0c3a3c: /* original 6d43, guest PC 0x0c0c3a3c */
if(!s->budget--) { s->failed_pc=0x0c0c3a3cu; return 0; }
r[13]=r[4];
goto P_0c0c3a3e;
P_0c0c3a3e: /* original 772c, guest PC 0x0c0c3a3e */
if(!s->budget--) { s->failed_pc=0x0c0c3a3eu; return 0; }
r[7]+=0x0000002cu;
goto P_0c0c3a40;
P_0c0c3a40: /* original 7a24, guest PC 0x0c0c3a40 */
if(!s->budget--) { s->failed_pc=0x0c0c3a40u; return 0; }
r[10]+=0x00000024u;
goto P_0c0c3a42;
P_0c0c3a42: /* original 7d20, guest PC 0x0c0c3a42 */
if(!s->budget--) { s->failed_pc=0x0c0c3a42u; return 0; }
r[13]+=0x00000020u;
goto P_0c0c3a44;
P_0c0c3a44: /* original 7c28, guest PC 0x0c0c3a44 */
if(!s->budget--) { s->failed_pc=0x0c0c3a44u; return 0; }
r[12]+=0x00000028u;
goto P_0c0c3a46;
P_0c0c3a46: /* original a026, guest PC 0x0c0c3a46 */
if(!s->budget--) { s->failed_pc=0x0c0c3a46u; return 0; }
r[11]=r[6];
goto P_0c0c3a96;
P_0c0c3a48: /* original 6b63, guest PC 0x0c0c3a48 */
if(!s->budget--) { s->failed_pc=0x0c0c3a48u; return 0; }
r[11]=r[6];
return vf3_matrix_family(0x0c0c3a4au,s,ram);
P_0c0c3a84: /* original 6a43, guest PC 0x0c0c3a84 */
if(!s->budget--) { s->failed_pc=0x0c0c3a84u; return 0; }
r[10]=r[4];
goto P_0c0c3a86;
P_0c0c3a86: /* original 6743, guest PC 0x0c0c3a86 */
if(!s->budget--) { s->failed_pc=0x0c0c3a86u; return 0; }
r[7]=r[4];
goto P_0c0c3a88;
P_0c0c3a88: /* original 6c43, guest PC 0x0c0c3a88 */
if(!s->budget--) { s->failed_pc=0x0c0c3a88u; return 0; }
r[12]=r[4];
goto P_0c0c3a8a;
P_0c0c3a8a: /* original 6d43, guest PC 0x0c0c3a8a */
if(!s->budget--) { s->failed_pc=0x0c0c3a8au; return 0; }
r[13]=r[4];
goto P_0c0c3a8c;
P_0c0c3a8c: /* original 7728, guest PC 0x0c0c3a8c */
if(!s->budget--) { s->failed_pc=0x0c0c3a8cu; return 0; }
r[7]+=0x00000028u;
goto P_0c0c3a8e;
P_0c0c3a8e: /* original 6b53, guest PC 0x0c0c3a8e */
if(!s->budget--) { s->failed_pc=0x0c0c3a8eu; return 0; }
r[11]=r[5];
goto P_0c0c3a90;
P_0c0c3a90: /* original 7c2c, guest PC 0x0c0c3a90 */
if(!s->budget--) { s->failed_pc=0x0c0c3a90u; return 0; }
r[12]+=0x0000002cu;
goto P_0c0c3a92;
P_0c0c3a92: /* original 7d24, guest PC 0x0c0c3a92 */
if(!s->budget--) { s->failed_pc=0x0c0c3a92u; return 0; }
r[13]+=0x00000024u;
goto P_0c0c3a94;
P_0c0c3a94: /* original 7a20, guest PC 0x0c0c3a94 */
if(!s->budget--) { s->failed_pc=0x0c0c3a94u; return 0; }
r[10]+=0x00000020u;
goto P_0c0c3a96;
P_0c0c3a96: /* original e036, guest PC 0x0c0c3a96 */
if(!s->budget--) { s->failed_pc=0x0c0c3a96u; return 0; }
r[0]=0x00000036u;
goto P_0c0c3a98;
P_0c0c3a98: /* original 03ec, guest PC 0x0c0c3a98 */
if(!s->budget--) { s->failed_pc=0x0c0c3a98u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3a9a;
P_0c0c3a9a: /* original 2338, guest PC 0x0c0c3a9a */
if(!s->budget--) { s->failed_pc=0x0c0c3a9au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c3a9c;
P_0c0c3a9c: /* original 8d15, guest PC 0x0c0c3a9c */
if(!s->budget--) { s->failed_pc=0x0c0c3a9cu; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c0c3aca; }
goto P_0c0c3aa0;
P_0c0c3a9e: /* original e400, guest PC 0x0c0c3a9e */
if(!s->budget--) { s->failed_pc=0x0c0c3a9eu; return 0; }
r[4]=0x00000000u;
goto P_0c0c3aa0;
P_0c0c3aa0: /* original 52ef, guest PC 0x0c0c3aa0 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa0u; return 0; }
r[2]=read(ram,r[14]+60,4);
goto P_0c0c3aa2;
P_0c0c3aa2: /* original e106, guest PC 0x0c0c3aa2 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa2u; return 0; }
r[1]=0x00000006u;
goto P_0c0c3aa4;
P_0c0c3aa4: /* original 3213, guest PC 0x0c0c3aa4 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0c3aa6;
P_0c0c3aa6: /* original 8912, guest PC 0x0c0c3aa6 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3ace; }
goto P_0c0c3aa8;
P_0c0c3aa8: /* original 60d2, guest PC 0x0c0c3aa8 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa8u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c3aaa;
P_0c0c3aaa: /* original 88ff, guest PC 0x0c0c3aaa */
if(!s->budget--) { s->failed_pc=0x0c0c3aaau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3aac;
P_0c0c3aac: /* original 8b09, guest PC 0x0c0c3aac */
if(!s->budget--) { s->failed_pc=0x0c0c3aacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3ac2; }
goto P_0c0c3aae;
P_0c0c3aae: /* original 60c2, guest PC 0x0c0c3aae */
if(!s->budget--) { s->failed_pc=0x0c0c3aaeu; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c0c3ab0;
P_0c0c3ab0: /* original 88ff, guest PC 0x0c0c3ab0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ab2;
P_0c0c3ab2: /* original 8b06, guest PC 0x0c0c3ab2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3ac2; }
goto P_0c0c3ab4;
P_0c0c3ab4: /* original d335, guest PC 0x0c0c3ab4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab4u; return 0; }
r[3]=read(ram,0x0c0c3b8cu,4);
goto P_0c0c3ab6;
P_0c0c3ab6: /* original e040, guest PC 0x0c0c3ab6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab6u; return 0; }
r[0]=0x00000040u;
goto P_0c0c3ab8;
P_0c0c3ab8: /* original 430b, guest PC 0x0c0c3ab8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c3abcu;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3abcu) { target=s->pc; goto dispatch; }
goto P_0c0c3abc;
P_0c0c3aba: /* original 04ee, guest PC 0x0c0c3aba */
if(!s->budget--) { s->failed_pc=0x0c0c3abau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c3abc;
P_0c0c3abc: /* original e040, guest PC 0x0c0c3abc */
if(!s->budget--) { s->failed_pc=0x0c0c3abcu; return 0; }
r[0]=0x00000040u;
goto P_0c0c3abe;
P_0c0c3abe: /* original e2ff, guest PC 0x0c0c3abe */
if(!s->budget--) { s->failed_pc=0x0c0c3abeu; return 0; }
r[2]=0xffffffffu;
goto P_0c0c3ac0;
P_0c0c3ac0: /* original 0e26, guest PC 0x0c0c3ac0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c3ac2;
P_0c0c3ac2: /* original 53ef, guest PC 0x0c0c3ac2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac2u; return 0; }
r[3]=read(ram,r[14]+60,4);
goto P_0c0c3ac4;
P_0c0c3ac4: /* original 7301, guest PC 0x0c0c3ac4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac4u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c3ac6;
P_0c0c3ac6: /* original a022, guest PC 0x0c0c3ac6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac6u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c0c3b0e;
P_0c0c3ac8: /* original 1e3f, guest PC 0x0c0c3ac8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac8u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c0c3aca;
P_0c0c3aca: /* original a020, guest PC 0x0c0c3aca */
if(!s->budget--) { s->failed_pc=0x0c0c3acau; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c0c3b0e;
P_0c0c3acc: /* original 1e4f, guest PC 0x0c0c3acc */
if(!s->budget--) { s->failed_pc=0x0c0c3accu; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c0c3ace;
P_0c0c3ace: /* original 60a2, guest PC 0x0c0c3ace */
if(!s->budget--) { s->failed_pc=0x0c0c3aceu; return 0; }
tmp=read(ram,r[10],4);
r[0]=tmp;
goto P_0c0c3ad0;
P_0c0c3ad0: /* original 88ff, guest PC 0x0c0c3ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ad2;
P_0c0c3ad2: /* original 8b1c, guest PC 0x0c0c3ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3b0e; }
goto P_0c0c3ad4;
P_0c0c3ad4: /* original 6072, guest PC 0x0c0c3ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad4u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c0c3ad6;
P_0c0c3ad6: /* original 88ff, guest PC 0x0c0c3ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ad8;
P_0c0c3ad8: /* original 8b19, guest PC 0x0c0c3ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3b0e; }
goto P_0c0c3ada;
P_0c0c3ada: /* original 60d2, guest PC 0x0c0c3ada */
if(!s->budget--) { s->failed_pc=0x0c0c3adau; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c3adc;
P_0c0c3adc: /* original 88ff, guest PC 0x0c0c3adc */
if(!s->budget--) { s->failed_pc=0x0c0c3adcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ade;
P_0c0c3ade: /* original 8b16, guest PC 0x0c0c3ade */
if(!s->budget--) { s->failed_pc=0x0c0c3adeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3b0e; }
goto P_0c0c3ae0;
P_0c0c3ae0: /* original 60c2, guest PC 0x0c0c3ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae0u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c0c3ae2;
P_0c0c3ae2: /* original 88ff, guest PC 0x0c0c3ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ae4;
P_0c0c3ae4: /* original 8b13, guest PC 0x0c0c3ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3b0e; }
goto P_0c0c3ae6;
P_0c0c3ae6: /* original e036, guest PC 0x0c0c3ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae6u; return 0; }
r[0]=0x00000036u;
goto P_0c0c3ae8;
P_0c0c3ae8: /* original 0e44, guest PC 0x0c0c3ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c3aea;
P_0c0c3aea: /* original e040, guest PC 0x0c0c3aea */
if(!s->budget--) { s->failed_pc=0x0c0c3aeau; return 0; }
r[0]=0x00000040u;
goto P_0c0c3aec;
P_0c0c3aec: /* original 2d42, guest PC 0x0c0c3aec */
if(!s->budget--) { s->failed_pc=0x0c0c3aecu; return 0; }
write(ram,r[13],r[4],4);
goto P_0c0c3aee;
P_0c0c3aee: /* original 2c42, guest PC 0x0c0c3aee */
if(!s->budget--) { s->failed_pc=0x0c0c3aeeu; return 0; }
write(ram,r[12],r[4],4);
goto P_0c0c3af0;
P_0c0c3af0: /* original d326, guest PC 0x0c0c3af0 */
if(!s->budget--) { s->failed_pc=0x0c0c3af0u; return 0; }
r[3]=read(ram,0x0c0c3b8cu,4);
goto P_0c0c3af2;
P_0c0c3af2: /* original 430b, guest PC 0x0c0c3af2 */
if(!s->budget--) { s->failed_pc=0x0c0c3af2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c3af6u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3af6u) { target=s->pc; goto dispatch; }
goto P_0c0c3af6;
P_0c0c3af4: /* original 04ee, guest PC 0x0c0c3af4 */
if(!s->budget--) { s->failed_pc=0x0c0c3af4u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c3af6;
P_0c0c3af6: /* original e060, guest PC 0x0c0c3af6 */
if(!s->budget--) { s->failed_pc=0x0c0c3af6u; return 0; }
r[0]=0x00000060u;
goto P_0c0c3af8;
P_0c0c3af8: /* original d325, guest PC 0x0c0c3af8 */
if(!s->budget--) { s->failed_pc=0x0c0c3af8u; return 0; }
r[3]=read(ram,0x0c0c3b90u,4);
goto P_0c0c3afa;
P_0c0c3afa: /* original 04bc, guest PC 0x0c0c3afa */
if(!s->budget--) { s->failed_pc=0x0c0c3afau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c3afc;
P_0c0c3afc: /* original 65d3, guest PC 0x0c0c3afc */
if(!s->budget--) { s->failed_pc=0x0c0c3afcu; return 0; }
r[5]=r[13];
goto P_0c0c3afe;
P_0c0c3afe: /* original 66c3, guest PC 0x0c0c3afe */
if(!s->budget--) { s->failed_pc=0x0c0c3afeu; return 0; }
r[6]=r[12];
goto P_0c0c3b00;
P_0c0c3b00: /* original 430b, guest PC 0x0c0c3b00 */
if(!s->budget--) { s->failed_pc=0x0c0c3b00u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c3b04u;
r[4]=r[4]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c3b04u) { target=s->pc; goto dispatch; }
goto P_0c0c3b04;
P_0c0c3b02: /* original 644c, guest PC 0x0c0c3b02 */
if(!s->budget--) { s->failed_pc=0x0c0c3b02u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c3b04;
P_0c0c3b04: /* original e060, guest PC 0x0c0c3b04 */
if(!s->budget--) { s->failed_pc=0x0c0c3b04u; return 0; }
r[0]=0x00000060u;
goto P_0c0c3b06;
P_0c0c3b06: /* original 02bc, guest PC 0x0c0c3b06 */
if(!s->budget--) { s->failed_pc=0x0c0c3b06u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c3b08;
P_0c0c3b08: /* original e040, guest PC 0x0c0c3b08 */
if(!s->budget--) { s->failed_pc=0x0c0c3b08u; return 0; }
r[0]=0x00000040u;
goto P_0c0c3b0a;
P_0c0c3b0a: /* original 622c, guest PC 0x0c0c3b0a */
if(!s->budget--) { s->failed_pc=0x0c0c3b0au; return 0; }
r[2]=r[2]&255u;
goto P_0c0c3b0c;
P_0c0c3b0c: /* original 0e26, guest PC 0x0c0c3b0c */
if(!s->budget--) { s->failed_pc=0x0c0c3b0cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c3b0e;
P_0c0c3b0e: /* original 4f26, guest PC 0x0c0c3b0e */
if(!s->budget--) { s->failed_pc=0x0c0c3b0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c3b10;
P_0c0c3b10: /* original 6af6, guest PC 0x0c0c3b10 */
if(!s->budget--) { s->failed_pc=0x0c0c3b10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c3b12;
P_0c0c3b12: /* original 6bf6, guest PC 0x0c0c3b12 */
if(!s->budget--) { s->failed_pc=0x0c0c3b12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c3b14;
P_0c0c3b14: /* original 6cf6, guest PC 0x0c0c3b14 */
if(!s->budget--) { s->failed_pc=0x0c0c3b14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c3b16;
P_0c0c3b16: /* original 6df6, guest PC 0x0c0c3b16 */
if(!s->budget--) { s->failed_pc=0x0c0c3b16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c3b18;
P_0c0c3b18: /* original 000b, guest PC 0x0c0c3b18 */
if(!s->budget--) { s->failed_pc=0x0c0c3b18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c3b1a: /* original 6ef6, guest PC 0x0c0c3b1a */
if(!s->budget--) { s->failed_pc=0x0c0c3b1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c3b1cu,s,ram);
P_0c0c5c94: /* original 2fe6, guest PC 0x0c0c5c94 */
if(!s->budget--) { s->failed_pc=0x0c0c5c94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c96;
P_0c0c5c96: /* original 6043, guest PC 0x0c0c5c96 */
if(!s->budget--) { s->failed_pc=0x0c0c5c96u; return 0; }
r[0]=r[4];
goto P_0c0c5c98;
P_0c0c5c98: /* original 2fd6, guest PC 0x0c0c5c98 */
if(!s->budget--) { s->failed_pc=0x0c0c5c98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9a;
P_0c0c5c9a: /* original 88ff, guest PC 0x0c0c5c9a */
if(!s->budget--) { s->failed_pc=0x0c0c5c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c5c9c;
P_0c0c5c9c: /* original 2fc6, guest PC 0x0c0c5c9c */
if(!s->budget--) { s->failed_pc=0x0c0c5c9cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9e;
P_0c0c5c9e: /* original 6d43, guest PC 0x0c0c5c9e */
if(!s->budget--) { s->failed_pc=0x0c0c5c9eu; return 0; }
r[13]=r[4];
goto P_0c0c5ca0;
P_0c0c5ca0: /* original 2fb6, guest PC 0x0c0c5ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5ca2;
P_0c0c5ca2: /* original 4f22, guest PC 0x0c0c5ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ca4;
P_0c0c5ca4: /* original 8d03, guest PC 0x0c0c5ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca4u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(cond) { goto P_0c0c5cae; }
goto P_0c0c5ca8;
P_0c0c5ca6: /* original 6b53, guest PC 0x0c0c5ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca6u; return 0; }
r[11]=r[5];
goto P_0c0c5ca8;
P_0c0c5ca8: /* original 930d, guest PC 0x0c0c5ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5cc6u,2);
goto P_0c0c5caa;
P_0c0c5caa: /* original 3d30, guest PC 0x0c0c5caa */
if(!s->budget--) { s->failed_pc=0x0c0c5caau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cac;
P_0c0c5cac: /* original 8b22, guest PC 0x0c0c5cac */
if(!s->budget--) { s->failed_pc=0x0c0c5cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5cf4; }
goto P_0c0c5cae;
P_0c0c5cae: /* original a064, guest PC 0x0c0c5cae */
if(!s->budget--) { s->failed_pc=0x0c0c5caeu; return 0; }
r[0]=0xffffffffu;
goto P_0c0c5d7a;
P_0c0c5cb0: /* original e0ff, guest PC 0x0c0c5cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5cb0u; return 0; }
r[0]=0xffffffffu;
return vf3_matrix_family(0x0c0c5cb2u,s,ram);
P_0c0c5cf4: /* original 9381, guest PC 0x0c0c5cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfau,2);
goto P_0c0c5cf6;
P_0c0c5cf6: /* original de43, guest PC 0x0c0c5cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf6u; return 0; }
r[14]=read(ram,0x0c0c5e04u,4);
goto P_0c0c5cf8;
P_0c0c5cf8: /* original 3d30, guest PC 0x0c0c5cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cfa;
P_0c0c5cfa: /* original 8905, guest PC 0x0c0c5cfa */
if(!s->budget--) { s->failed_pc=0x0c0c5cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5cfc;
P_0c0c5cfc: /* original 917e, guest PC 0x0c0c5cfc */
if(!s->budget--) { s->failed_pc=0x0c0c5cfcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfcu,2);
goto P_0c0c5cfe;
P_0c0c5cfe: /* original 3d10, guest PC 0x0c0c5cfe */
if(!s->budget--) { s->failed_pc=0x0c0c5cfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d00;
P_0c0c5d00: /* original 8902, guest PC 0x0c0c5d00 */
if(!s->budget--) { s->failed_pc=0x0c0c5d00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5d02;
P_0c0c5d02: /* original 907c, guest PC 0x0c0c5d02 */
if(!s->budget--) { s->failed_pc=0x0c0c5d02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfeu,2);
goto P_0c0c5d04;
P_0c0c5d04: /* original 3d00, guest PC 0x0c0c5d04 */
if(!s->budget--) { s->failed_pc=0x0c0c5d04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0c5d06;
P_0c0c5d06: /* original 8b07, guest PC 0x0c0c5d06 */
if(!s->budget--) { s->failed_pc=0x0c0c5d06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d18; }
goto P_0c0c5d08;
P_0c0c5d08: /* original 65d3, guest PC 0x0c0c5d08 */
if(!s->budget--) { s->failed_pc=0x0c0c5d08u; return 0; }
r[5]=r[13];
goto P_0c0c5d0a;
P_0c0c5d0a: /* original 66b3, guest PC 0x0c0c5d0a */
if(!s->budget--) { s->failed_pc=0x0c0c5d0au; return 0; }
r[6]=r[11];
goto P_0c0c5d0c;
P_0c0c5d0c: /* original 4e0b, guest PC 0x0c0c5d0c */
if(!s->budget--) { s->failed_pc=0x0c0c5d0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d10u;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5d10u) { target=s->pc; goto dispatch; }
goto P_0c0c5d10;
P_0c0c5d0e: /* original e404, guest PC 0x0c0c5d0e */
if(!s->budget--) { s->failed_pc=0x0c0c5d0eu; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d10;
P_0c0c5d10: /* original 65d3, guest PC 0x0c0c5d10 */
if(!s->budget--) { s->failed_pc=0x0c0c5d10u; return 0; }
r[5]=r[13];
goto P_0c0c5d12;
P_0c0c5d12: /* original 66b3, guest PC 0x0c0c5d12 */
if(!s->budget--) { s->failed_pc=0x0c0c5d12u; return 0; }
r[6]=r[11];
goto P_0c0c5d14;
P_0c0c5d14: /* original a02f, guest PC 0x0c0c5d14 */
if(!s->budget--) { s->failed_pc=0x0c0c5d14u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d76;
P_0c0c5d16: /* original e403, guest PC 0x0c0c5d16 */
if(!s->budget--) { s->failed_pc=0x0c0c5d16u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d18;
P_0c0c5d18: /* original d33c, guest PC 0x0c0c5d18 */
if(!s->budget--) { s->failed_pc=0x0c0c5d18u; return 0; }
r[3]=read(ram,0x0c0c5e0cu,4);
goto P_0c0c5d1a;
P_0c0c5d1a: /* original dc3b, guest PC 0x0c0c5d1a */
if(!s->budget--) { s->failed_pc=0x0c0c5d1au; return 0; }
r[12]=read(ram,0x0c0c5e08u,4);
goto P_0c0c5d1c;
P_0c0c5d1c: /* original 3d30, guest PC 0x0c0c5d1c */
if(!s->budget--) { s->failed_pc=0x0c0c5d1cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5d1e;
P_0c0c5d1e: /* original 8b0b, guest PC 0x0c0c5d1e */
if(!s->budget--) { s->failed_pc=0x0c0c5d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d38; }
goto P_0c0c5d20;
P_0c0c5d20: /* original 65c3, guest PC 0x0c0c5d20 */
if(!s->budget--) { s->failed_pc=0x0c0c5d20u; return 0; }
r[5]=r[12];
goto P_0c0c5d22;
P_0c0c5d22: /* original e600, guest PC 0x0c0c5d22 */
if(!s->budget--) { s->failed_pc=0x0c0c5d22u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d24;
P_0c0c5d24: /* original 4e0b, guest PC 0x0c0c5d24 */
if(!s->budget--) { s->failed_pc=0x0c0c5d24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d28u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5d28u) { target=s->pc; goto dispatch; }
goto P_0c0c5d28;
P_0c0c5d26: /* original e401, guest PC 0x0c0c5d26 */
if(!s->budget--) { s->failed_pc=0x0c0c5d26u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d28;
P_0c0c5d28: /* original 65c3, guest PC 0x0c0c5d28 */
if(!s->budget--) { s->failed_pc=0x0c0c5d28u; return 0; }
r[5]=r[12];
goto P_0c0c5d2a;
P_0c0c5d2a: /* original e600, guest PC 0x0c0c5d2a */
if(!s->budget--) { s->failed_pc=0x0c0c5d2au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d2c;
P_0c0c5d2c: /* original 4e0b, guest PC 0x0c0c5d2c */
if(!s->budget--) { s->failed_pc=0x0c0c5d2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d30u;
r[4]=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5d30u) { target=s->pc; goto dispatch; }
goto P_0c0c5d30;
P_0c0c5d2e: /* original e402, guest PC 0x0c0c5d2e */
if(!s->budget--) { s->failed_pc=0x0c0c5d2eu; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d30;
P_0c0c5d30: /* original 65c3, guest PC 0x0c0c5d30 */
if(!s->budget--) { s->failed_pc=0x0c0c5d30u; return 0; }
r[5]=r[12];
goto P_0c0c5d32;
P_0c0c5d32: /* original e600, guest PC 0x0c0c5d32 */
if(!s->budget--) { s->failed_pc=0x0c0c5d32u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d34;
P_0c0c5d34: /* original a00a, guest PC 0x0c0c5d34 */
if(!s->budget--) { s->failed_pc=0x0c0c5d34u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d4c;
P_0c0c5d36: /* original e403, guest PC 0x0c0c5d36 */
if(!s->budget--) { s->failed_pc=0x0c0c5d36u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d38;
P_0c0c5d38: /* original d135, guest PC 0x0c0c5d38 */
if(!s->budget--) { s->failed_pc=0x0c0c5d38u; return 0; }
r[1]=read(ram,0x0c0c5e10u,4);
goto P_0c0c5d3a;
P_0c0c5d3a: /* original 3d10, guest PC 0x0c0c5d3a */
if(!s->budget--) { s->failed_pc=0x0c0c5d3au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d3c;
P_0c0c5d3c: /* original 8b18, guest PC 0x0c0c5d3c */
if(!s->budget--) { s->failed_pc=0x0c0c5d3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d70; }
goto P_0c0c5d3e;
P_0c0c5d3e: /* original 65c3, guest PC 0x0c0c5d3e */
if(!s->budget--) { s->failed_pc=0x0c0c5d3eu; return 0; }
r[5]=r[12];
goto P_0c0c5d40;
P_0c0c5d40: /* original e600, guest PC 0x0c0c5d40 */
if(!s->budget--) { s->failed_pc=0x0c0c5d40u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d42;
P_0c0c5d42: /* original 4e0b, guest PC 0x0c0c5d42 */
if(!s->budget--) { s->failed_pc=0x0c0c5d42u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d46u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5d46u) { target=s->pc; goto dispatch; }
goto P_0c0c5d46;
P_0c0c5d44: /* original e401, guest PC 0x0c0c5d44 */
if(!s->budget--) { s->failed_pc=0x0c0c5d44u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d46;
P_0c0c5d46: /* original e402, guest PC 0x0c0c5d46 */
if(!s->budget--) { s->failed_pc=0x0c0c5d46u; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d48;
P_0c0c5d48: /* original 65c3, guest PC 0x0c0c5d48 */
if(!s->budget--) { s->failed_pc=0x0c0c5d48u; return 0; }
r[5]=r[12];
goto P_0c0c5d4a;
P_0c0c5d4a: /* original e600, guest PC 0x0c0c5d4a */
if(!s->budget--) { s->failed_pc=0x0c0c5d4au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d4c;
P_0c0c5d4c: /* original 4e0b, guest PC 0x0c0c5d4c */
if(!s->budget--) { s->failed_pc=0x0c0c5d4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d50u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5d50u) { target=s->pc; goto dispatch; }
goto P_0c0c5d50;
P_0c0c5d4e: /* original 0009, guest PC 0x0c0c5d4e */
if(!s->budget--) { s->failed_pc=0x0c0c5d4eu; return 0; }
goto P_0c0c5d50;
P_0c0c5d50: /* original 65c3, guest PC 0x0c0c5d50 */
if(!s->budget--) { s->failed_pc=0x0c0c5d50u; return 0; }
r[5]=r[12];
goto P_0c0c5d52;
P_0c0c5d52: /* original e600, guest PC 0x0c0c5d52 */
if(!s->budget--) { s->failed_pc=0x0c0c5d52u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d54;
P_0c0c5d54: /* original 4e0b, guest PC 0x0c0c5d54 */
if(!s->budget--) { s->failed_pc=0x0c0c5d54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d58u;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5d58u) { target=s->pc; goto dispatch; }
goto P_0c0c5d58;
P_0c0c5d56: /* original e404, guest PC 0x0c0c5d56 */
if(!s->budget--) { s->failed_pc=0x0c0c5d56u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d58;
P_0c0c5d58: /* original 65c3, guest PC 0x0c0c5d58 */
if(!s->budget--) { s->failed_pc=0x0c0c5d58u; return 0; }
r[5]=r[12];
goto P_0c0c5d5a;
P_0c0c5d5a: /* original e600, guest PC 0x0c0c5d5a */
if(!s->budget--) { s->failed_pc=0x0c0c5d5au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d5c;
P_0c0c5d5c: /* original 4e0b, guest PC 0x0c0c5d5c */
if(!s->budget--) { s->failed_pc=0x0c0c5d5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d60u;
r[4]=0x00000005u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5d60u) { target=s->pc; goto dispatch; }
goto P_0c0c5d60;
P_0c0c5d5e: /* original e405, guest PC 0x0c0c5d5e */
if(!s->budget--) { s->failed_pc=0x0c0c5d5eu; return 0; }
r[4]=0x00000005u;
goto P_0c0c5d60;
P_0c0c5d60: /* original 65c3, guest PC 0x0c0c5d60 */
if(!s->budget--) { s->failed_pc=0x0c0c5d60u; return 0; }
r[5]=r[12];
goto P_0c0c5d62;
P_0c0c5d62: /* original e600, guest PC 0x0c0c5d62 */
if(!s->budget--) { s->failed_pc=0x0c0c5d62u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d64;
P_0c0c5d64: /* original 4e0b, guest PC 0x0c0c5d64 */
if(!s->budget--) { s->failed_pc=0x0c0c5d64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d68u;
r[4]=0x00000006u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5d68u) { target=s->pc; goto dispatch; }
goto P_0c0c5d68;
P_0c0c5d66: /* original e406, guest PC 0x0c0c5d66 */
if(!s->budget--) { s->failed_pc=0x0c0c5d66u; return 0; }
r[4]=0x00000006u;
goto P_0c0c5d68;
P_0c0c5d68: /* original 65c3, guest PC 0x0c0c5d68 */
if(!s->budget--) { s->failed_pc=0x0c0c5d68u; return 0; }
r[5]=r[12];
goto P_0c0c5d6a;
P_0c0c5d6a: /* original e600, guest PC 0x0c0c5d6a */
if(!s->budget--) { s->failed_pc=0x0c0c5d6au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d6c;
P_0c0c5d6c: /* original a003, guest PC 0x0c0c5d6c */
if(!s->budget--) { s->failed_pc=0x0c0c5d6cu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d76;
P_0c0c5d6e: /* original e407, guest PC 0x0c0c5d6e */
if(!s->budget--) { s->failed_pc=0x0c0c5d6eu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d70;
P_0c0c5d70: /* original e400, guest PC 0x0c0c5d70 */
if(!s->budget--) { s->failed_pc=0x0c0c5d70u; return 0; }
r[4]=0x00000000u;
goto P_0c0c5d72;
P_0c0c5d72: /* original 65d3, guest PC 0x0c0c5d72 */
if(!s->budget--) { s->failed_pc=0x0c0c5d72u; return 0; }
r[5]=r[13];
goto P_0c0c5d74;
P_0c0c5d74: /* original 66b3, guest PC 0x0c0c5d74 */
if(!s->budget--) { s->failed_pc=0x0c0c5d74u; return 0; }
r[6]=r[11];
goto P_0c0c5d76;
P_0c0c5d76: /* original 4e0b, guest PC 0x0c0c5d76 */
if(!s->budget--) { s->failed_pc=0x0c0c5d76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d7au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5d7au) { target=s->pc; goto dispatch; }
goto P_0c0c5d7a;
P_0c0c5d78: /* original 0009, guest PC 0x0c0c5d78 */
if(!s->budget--) { s->failed_pc=0x0c0c5d78u; return 0; }
goto P_0c0c5d7a;
P_0c0c5d7a: /* original 4f26, guest PC 0x0c0c5d7a */
if(!s->budget--) { s->failed_pc=0x0c0c5d7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5d7c;
P_0c0c5d7c: /* original 6bf6, guest PC 0x0c0c5d7c */
if(!s->budget--) { s->failed_pc=0x0c0c5d7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5d7e;
P_0c0c5d7e: /* original 6cf6, guest PC 0x0c0c5d7e */
if(!s->budget--) { s->failed_pc=0x0c0c5d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5d80;
P_0c0c5d80: /* original 6df6, guest PC 0x0c0c5d80 */
if(!s->budget--) { s->failed_pc=0x0c0c5d80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5d82;
P_0c0c5d82: /* original 000b, guest PC 0x0c0c5d82 */
if(!s->budget--) { s->failed_pc=0x0c0c5d82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5d84: /* original 6ef6, guest PC 0x0c0c5d84 */
if(!s->budget--) { s->failed_pc=0x0c0c5d84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c5d86u,s,ram);
P_0c0c601c: /* original 4f22, guest PC 0x0c0c601c */
if(!s->budget--) { s->failed_pc=0x0c0c601cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c601e;
P_0c0c601e: /* original d32a, guest PC 0x0c0c601e */
if(!s->budget--) { s->failed_pc=0x0c0c601eu; return 0; }
r[3]=read(ram,0x0c0c60c8u,4);
goto P_0c0c6020;
P_0c0c6020: /* original 7ff8, guest PC 0x0c0c6020 */
if(!s->budget--) { s->failed_pc=0x0c0c6020u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c6022;
P_0c0c6022: /* original 1f31, guest PC 0x0c0c6022 */
if(!s->budget--) { s->failed_pc=0x0c0c6022u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c6024;
P_0c0c6024: /* original 8b42, guest PC 0x0c0c6024 */
if(!s->budget--) { s->failed_pc=0x0c0c6024u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c60ac; }
goto P_0c0c6026;
P_0c0c6026: /* original 924b, guest PC 0x0c0c6026 */
if(!s->budget--) { s->failed_pc=0x0c0c6026u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c60c0u,2);
goto P_0c0c6028;
P_0c0c6028: /* original 3423, guest PC 0x0c0c6028 */
if(!s->budget--) { s->failed_pc=0x0c0c6028u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c602a;
P_0c0c602a: /* original 893f, guest PC 0x0c0c602a */
if(!s->budget--) { s->failed_pc=0x0c0c602au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c60ac; }
goto P_0c0c602c;
P_0c0c602c: /* original d027, guest PC 0x0c0c602c */
if(!s->budget--) { s->failed_pc=0x0c0c602cu; return 0; }
r[0]=read(ram,0x0c0c60ccu,4);
goto P_0c0c602e;
P_0c0c602e: /* original 6143, guest PC 0x0c0c602e */
if(!s->budget--) { s->failed_pc=0x0c0c602eu; return 0; }
r[1]=r[4];
goto P_0c0c6030;
P_0c0c6030: /* original 4108, guest PC 0x0c0c6030 */
if(!s->budget--) { s->failed_pc=0x0c0c6030u; return 0; }
r[1]<<=2;
goto P_0c0c6032;
P_0c0c6032: /* original 031e, guest PC 0x0c0c6032 */
if(!s->budget--) { s->failed_pc=0x0c0c6032u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c0c6034;
P_0c0c6034: /* original 4311, guest PC 0x0c0c6034 */
if(!s->budget--) { s->failed_pc=0x0c0c6034u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c6036;
P_0c0c6036: /* original 8b39, guest PC 0x0c0c6036 */
if(!s->budget--) { s->failed_pc=0x0c0c6036u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c60ac; }
goto P_0c0c6038;
P_0c0c6038: /* original d325, guest PC 0x0c0c6038 */
if(!s->budget--) { s->failed_pc=0x0c0c6038u; return 0; }
r[3]=read(ram,0x0c0c60d0u,4);
goto P_0c0c603a;
P_0c0c603a: /* original ec00, guest PC 0x0c0c603a */
if(!s->budget--) { s->failed_pc=0x0c0c603au; return 0; }
r[12]=0x00000000u;
goto P_0c0c603c;
P_0c0c603c: /* original e8ff, guest PC 0x0c0c603c */
if(!s->budget--) { s->failed_pc=0x0c0c603cu; return 0; }
r[8]=0xffffffffu;
goto P_0c0c603e;
P_0c0c603e: /* original 2f32, guest PC 0x0c0c603e */
if(!s->budget--) { s->failed_pc=0x0c0c603eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c6040;
P_0c0c6040: /* original da24, guest PC 0x0c0c6040 */
if(!s->budget--) { s->failed_pc=0x0c0c6040u; return 0; }
r[10]=read(ram,0x0c0c60d4u,4);
goto P_0c0c6042;
P_0c0c6042: /* original 993e, guest PC 0x0c0c6042 */
if(!s->budget--) { s->failed_pc=0x0c0c6042u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c60c2u,2);
goto P_0c0c6044;
P_0c0c6044: /* original dd25, guest PC 0x0c0c6044 */
if(!s->budget--) { s->failed_pc=0x0c0c6044u; return 0; }
r[13]=read(ram,0x0c0c60dcu,4);
goto P_0c0c6046;
P_0c0c6046: /* original db24, guest PC 0x0c0c6046 */
if(!s->budget--) { s->failed_pc=0x0c0c6046u; return 0; }
r[11]=read(ram,0x0c0c60d8u,4);
goto P_0c0c6048;
P_0c0c6048: /* original 6ec3, guest PC 0x0c0c6048 */
if(!s->budget--) { s->failed_pc=0x0c0c6048u; return 0; }
r[14]=r[12];
goto P_0c0c604a;
P_0c0c604a: /* original 4e08, guest PC 0x0c0c604a */
if(!s->budget--) { s->failed_pc=0x0c0c604au; return 0; }
r[14]<<=2;
goto P_0c0c604c;
P_0c0c604c: /* original 4e00, guest PC 0x0c0c604c */
if(!s->budget--) { s->failed_pc=0x0c0c604cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c604e;
P_0c0c604e: /* original 3eac, guest PC 0x0c0c604e */
if(!s->budget--) { s->failed_pc=0x0c0c604eu; return 0; }
r[14]+=r[10];
goto P_0c0c6050;
P_0c0c6050: /* original 53e1, guest PC 0x0c0c6050 */
if(!s->budget--) { s->failed_pc=0x0c0c6050u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c6052;
P_0c0c6052: /* original 2338, guest PC 0x0c0c6052 */
if(!s->budget--) { s->failed_pc=0x0c0c6052u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c6054;
P_0c0c6054: /* original 892a, guest PC 0x0c0c6054 */
if(!s->budget--) { s->failed_pc=0x0c0c6054u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c60ac; }
goto P_0c0c6056;
P_0c0c6056: /* original 52e1, guest PC 0x0c0c6056 */
if(!s->budget--) { s->failed_pc=0x0c0c6056u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c6058;
P_0c0c6058: /* original 3420, guest PC 0x0c0c6058 */
if(!s->budget--) { s->failed_pc=0x0c0c6058u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c605a;
P_0c0c605a: /* original 8b25, guest PC 0x0c0c605a */
if(!s->budget--) { s->failed_pc=0x0c0c605au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c60a8; }
goto P_0c0c605c;
P_0c0c605c: /* original 61f2, guest PC 0x0c0c605c */
if(!s->budget--) { s->failed_pc=0x0c0c605cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0c605e;
P_0c0c605e: /* original 63e2, guest PC 0x0c0c605e */
if(!s->budget--) { s->failed_pc=0x0c0c605eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0c6060;
P_0c0c6060: /* original 6212, guest PC 0x0c0c6060 */
if(!s->budget--) { s->failed_pc=0x0c0c6060u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c6062;
P_0c0c6062: /* original 3230, guest PC 0x0c0c6062 */
if(!s->budget--) { s->failed_pc=0x0c0c6062u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0c6064;
P_0c0c6064: /* original 891b, guest PC 0x0c0c6064 */
if(!s->budget--) { s->failed_pc=0x0c0c6064u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c609e; }
goto P_0c0c6066;
P_0c0c6066: /* original 65b2, guest PC 0x0c0c6066 */
if(!s->budget--) { s->failed_pc=0x0c0c6066u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0c6068;
P_0c0c6068: /* original d31d, guest PC 0x0c0c6068 */
if(!s->budget--) { s->failed_pc=0x0c0c6068u; return 0; }
r[3]=read(ram,0x0c0c60e0u,4);
goto P_0c0c606a;
P_0c0c606a: /* original 35dc, guest PC 0x0c0c606a */
if(!s->budget--) { s->failed_pc=0x0c0c606au; return 0; }
r[5]+=r[13];
goto P_0c0c606c;
P_0c0c606c: /* original 430b, guest PC 0x0c0c606c */
if(!s->budget--) { s->failed_pc=0x0c0c606cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6070u;
tmp=read(ram,r[14],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6070u) { target=s->pc; goto dispatch; }
goto P_0c0c6070;
P_0c0c606e: /* original 64e2, guest PC 0x0c0c606e */
if(!s->budget--) { s->failed_pc=0x0c0c606eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c6070;
P_0c0c6070: /* original d41c, guest PC 0x0c0c6070 */
if(!s->budget--) { s->failed_pc=0x0c0c6070u; return 0; }
r[4]=read(ram,0x0c0c60e4u,4);
goto P_0c0c6072;
P_0c0c6072: /* original be0f, guest PC 0x0c0c6072 */
if(!s->budget--) { s->failed_pc=0x0c0c6072u; return 0; }
target=0x0c0c5c94u; r[16]=code_base|0x0c0c6076u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6076u) { target=s->pc; goto dispatch; }
goto P_0c0c6076;
P_0c0c6074: /* original e500, guest PC 0x0c0c6074 */
if(!s->budget--) { s->failed_pc=0x0c0c6074u; return 0; }
r[5]=0x00000000u;
goto P_0c0c6076;
P_0c0c6076: /* original d31c, guest PC 0x0c0c6076 */
if(!s->budget--) { s->failed_pc=0x0c0c6076u; return 0; }
r[3]=read(ram,0x0c0c60e8u,4);
goto P_0c0c6078;
P_0c0c6078: /* original 430b, guest PC 0x0c0c6078 */
if(!s->budget--) { s->failed_pc=0x0c0c6078u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c607cu;
r[4]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c607cu) { target=s->pc; goto dispatch; }
goto P_0c0c607c;
P_0c0c607a: /* original e403, guest PC 0x0c0c607a */
if(!s->budget--) { s->failed_pc=0x0c0c607au; return 0; }
r[4]=0x00000003u;
goto P_0c0c607c;
P_0c0c607c: /* original d21b, guest PC 0x0c0c607c */
if(!s->budget--) { s->failed_pc=0x0c0c607cu; return 0; }
r[2]=read(ram,0x0c0c60ecu,4);
goto P_0c0c607e;
P_0c0c607e: /* original e503, guest PC 0x0c0c607e */
if(!s->budget--) { s->failed_pc=0x0c0c607eu; return 0; }
r[5]=0x00000003u;
goto P_0c0c6080;
P_0c0c6080: /* original 64b2, guest PC 0x0c0c6080 */
if(!s->budget--) { s->failed_pc=0x0c0c6080u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0c6082;
P_0c0c6082: /* original 420b, guest PC 0x0c0c6082 */
if(!s->budget--) { s->failed_pc=0x0c0c6082u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6086u;
r[4]+=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6086u) { target=s->pc; goto dispatch; }
goto P_0c0c6086;
P_0c0c6084: /* original 34dc, guest PC 0x0c0c6084 */
if(!s->budget--) { s->failed_pc=0x0c0c6084u; return 0; }
r[4]+=r[13];
goto P_0c0c6086;
P_0c0c6086: /* original 2008, guest PC 0x0c0c6086 */
if(!s->budget--) { s->failed_pc=0x0c0c6086u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c6088;
P_0c0c6088: /* original 8903, guest PC 0x0c0c6088 */
if(!s->budget--) { s->failed_pc=0x0c0c6088u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6092; }
goto P_0c0c608a;
P_0c0c608a: /* original d219, guest PC 0x0c0c608a */
if(!s->budget--) { s->failed_pc=0x0c0c608au; return 0; }
r[2]=read(ram,0x0c0c60f0u,4);
goto P_0c0c608c;
P_0c0c608c: /* original 6593, guest PC 0x0c0c608c */
if(!s->budget--) { s->failed_pc=0x0c0c608cu; return 0; }
r[5]=r[9];
goto P_0c0c608e;
P_0c0c608e: /* original 420b, guest PC 0x0c0c608e */
if(!s->budget--) { s->failed_pc=0x0c0c608eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6092u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6092u) { target=s->pc; goto dispatch; }
goto P_0c0c6092;
P_0c0c6090: /* original e401, guest PC 0x0c0c6090 */
if(!s->budget--) { s->failed_pc=0x0c0c6090u; return 0; }
r[4]=0x00000001u;
goto P_0c0c6092;
P_0c0c6092: /* original 4c08, guest PC 0x0c0c6092 */
if(!s->budget--) { s->failed_pc=0x0c0c6092u; return 0; }
r[12]<<=2;
goto P_0c0c6094;
P_0c0c6094: /* original 63f2, guest PC 0x0c0c6094 */
if(!s->budget--) { s->failed_pc=0x0c0c6094u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c6096;
P_0c0c6096: /* original 4c00, guest PC 0x0c0c6096 */
if(!s->budget--) { s->failed_pc=0x0c0c6096u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c6098;
P_0c0c6098: /* original 3cac, guest PC 0x0c0c6098 */
if(!s->budget--) { s->failed_pc=0x0c0c6098u; return 0; }
r[12]+=r[10];
goto P_0c0c609a;
P_0c0c609a: /* original 62c2, guest PC 0x0c0c609a */
if(!s->budget--) { s->failed_pc=0x0c0c609au; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0c609c;
P_0c0c609c: /* original 2322, guest PC 0x0c0c609c */
if(!s->budget--) { s->failed_pc=0x0c0c609cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0c609e;
P_0c0c609e: /* original 9011, guest PC 0x0c0c609e */
if(!s->budget--) { s->failed_pc=0x0c0c609eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c60c4u,2);
goto P_0c0c60a0;
P_0c0c60a0: /* original 53f1, guest PC 0x0c0c60a0 */
if(!s->budget--) { s->failed_pc=0x0c0c60a0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c60a2;
P_0c0c60a2: /* original 0386, guest PC 0x0c0c60a2 */
if(!s->budget--) { s->failed_pc=0x0c0c60a2u; return 0; }
write(ram,r[3]+r[0],r[8],4);
goto P_0c0c60a4;
P_0c0c60a4: /* original a002, guest PC 0x0c0c60a4 */
if(!s->budget--) { s->failed_pc=0x0c0c60a4u; return 0; }
goto P_0c0c60ac;
P_0c0c60a6: /* original 0009, guest PC 0x0c0c60a6 */
if(!s->budget--) { s->failed_pc=0x0c0c60a6u; return 0; }
goto P_0c0c60a8;
P_0c0c60a8: /* original afce, guest PC 0x0c0c60a8 */
if(!s->budget--) { s->failed_pc=0x0c0c60a8u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c6048;
P_0c0c60aa: /* original 7c01, guest PC 0x0c0c60aa */
if(!s->budget--) { s->failed_pc=0x0c0c60aau; return 0; }
r[12]+=0x00000001u;
goto P_0c0c60ac;
P_0c0c60ac: /* original 7f08, guest PC 0x0c0c60ac */
if(!s->budget--) { s->failed_pc=0x0c0c60acu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c60ae;
P_0c0c60ae: /* original 4f26, guest PC 0x0c0c60ae */
if(!s->budget--) { s->failed_pc=0x0c0c60aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c60b0;
P_0c0c60b0: /* original 68f6, guest PC 0x0c0c60b0 */
if(!s->budget--) { s->failed_pc=0x0c0c60b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c60b2;
P_0c0c60b2: /* original 69f6, guest PC 0x0c0c60b2 */
if(!s->budget--) { s->failed_pc=0x0c0c60b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c60b4;
P_0c0c60b4: /* original 6af6, guest PC 0x0c0c60b4 */
if(!s->budget--) { s->failed_pc=0x0c0c60b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c60b6;
P_0c0c60b6: /* original 6bf6, guest PC 0x0c0c60b6 */
if(!s->budget--) { s->failed_pc=0x0c0c60b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c60b8;
P_0c0c60b8: /* original 6cf6, guest PC 0x0c0c60b8 */
if(!s->budget--) { s->failed_pc=0x0c0c60b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c60ba;
P_0c0c60ba: /* original 6df6, guest PC 0x0c0c60ba */
if(!s->budget--) { s->failed_pc=0x0c0c60bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c60bc;
P_0c0c60bc: /* original 000b, guest PC 0x0c0c60bc */
if(!s->budget--) { s->failed_pc=0x0c0c60bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c60be: /* original 6ef6, guest PC 0x0c0c60be */
if(!s->budget--) { s->failed_pc=0x0c0c60beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c60c0u,s,ram);
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
return vf3_matrix_family(0x0c0c66bcu,s,ram);
P_0c0c7562: /* original 4f22, guest PC 0x0c0c7562 */
if(!s->budget--) { s->failed_pc=0x0c0c7562u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7564;
P_0c0c7564: /* original d333, guest PC 0x0c0c7564 */
if(!s->budget--) { s->failed_pc=0x0c0c7564u; return 0; }
r[3]=read(ram,0x0c0c7634u,4);
goto P_0c0c7566;
P_0c0c7566: /* original 7ffc, guest PC 0x0c0c7566 */
if(!s->budget--) { s->failed_pc=0x0c0c7566u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c7568;
P_0c0c7568: /* original 2f32, guest PC 0x0c0c7568 */
if(!s->budget--) { s->failed_pc=0x0c0c7568u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c756a;
P_0c0c756a: /* original 50e2, guest PC 0x0c0c756a */
if(!s->budget--) { s->failed_pc=0x0c0c756au; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c0c756c;
P_0c0c756c: /* original c804, guest PC 0x0c0c756c */
if(!s->budget--) { s->failed_pc=0x0c0c756cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0c756e;
P_0c0c756e: /* original 8d05, guest PC 0x0c0c756e */
if(!s->budget--) { s->failed_pc=0x0c0c756eu; return 0; }
cond=r[17]&1u;
r[5]=0x00000001u;
if(cond) { goto P_0c0c757c; }
goto P_0c0c7572;
P_0c0c7570: /* original e501, guest PC 0x0c0c7570 */
if(!s->budget--) { s->failed_pc=0x0c0c7570u; return 0; }
r[5]=0x00000001u;
goto P_0c0c7572;
P_0c0c7572: /* original d331, guest PC 0x0c0c7572 */
if(!s->budget--) { s->failed_pc=0x0c0c7572u; return 0; }
r[3]=read(ram,0x0c0c7638u,4);
goto P_0c0c7574;
P_0c0c7574: /* original 64f2, guest PC 0x0c0c7574 */
if(!s->budget--) { s->failed_pc=0x0c0c7574u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c7576;
P_0c0c7576: /* original 430b, guest PC 0x0c0c7576 */
if(!s->budget--) { s->failed_pc=0x0c0c7576u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c757au;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c757au) { target=s->pc; goto dispatch; }
goto P_0c0c757a;
P_0c0c7578: /* original 7401, guest PC 0x0c0c7578 */
if(!s->budget--) { s->failed_pc=0x0c0c7578u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c757a;
P_0c0c757a: /* original 650c, guest PC 0x0c0c757a */
if(!s->budget--) { s->failed_pc=0x0c0c757au; return 0; }
r[5]=r[0]&255u;
goto P_0c0c757c;
P_0c0c757c: /* original 9457, guest PC 0x0c0c757c */
if(!s->budget--) { s->failed_pc=0x0c0c757cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c762eu,2);
goto P_0c0c757e;
P_0c0c757e: /* original 6753, guest PC 0x0c0c757e */
if(!s->budget--) { s->failed_pc=0x0c0c757eu; return 0; }
r[7]=r[5];
goto P_0c0c7580;
P_0c0c7580: /* original 34ec, guest PC 0x0c0c7580 */
if(!s->budget--) { s->failed_pc=0x0c0c7580u; return 0; }
r[4]+=r[14];
goto P_0c0c7582;
P_0c0c7582: /* original ed09, guest PC 0x0c0c7582 */
if(!s->budget--) { s->failed_pc=0x0c0c7582u; return 0; }
r[13]=0x00000009u;
goto P_0c0c7584;
P_0c0c7584: /* original e600, guest PC 0x0c0c7584 */
if(!s->budget--) { s->failed_pc=0x0c0c7584u; return 0; }
r[6]=0x00000000u;
goto P_0c0c7586;
P_0c0c7586: /* original 2460, guest PC 0x0c0c7586 */
if(!s->budget--) { s->failed_pc=0x0c0c7586u; return 0; }
write(ram,r[4],r[6],1);
goto P_0c0c7588;
P_0c0c7588: /* original 4d10, guest PC 0x0c0c7588 */
if(!s->budget--) { s->failed_pc=0x0c0c7588u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c0c758a;
P_0c0c758a: /* original 7401, guest PC 0x0c0c758a */
if(!s->budget--) { s->failed_pc=0x0c0c758au; return 0; }
r[4]+=0x00000001u;
goto P_0c0c758c;
P_0c0c758c: /* original 8ffb, guest PC 0x0c0c758c */
if(!s->budget--) { s->failed_pc=0x0c0c758cu; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c0c7586; }
goto P_0c0c7590;
P_0c0c758e: /* original 7601, guest PC 0x0c0c758e */
if(!s->budget--) { s->failed_pc=0x0c0c758eu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c7590;
P_0c0c7590: /* original e603, guest PC 0x0c0c7590 */
if(!s->budget--) { s->failed_pc=0x0c0c7590u; return 0; }
r[6]=0x00000003u;
goto P_0c0c7592;
P_0c0c7592: /* original ed0a, guest PC 0x0c0c7592 */
if(!s->budget--) { s->failed_pc=0x0c0c7592u; return 0; }
r[13]=0x0000000au;
goto P_0c0c7594;
P_0c0c7594: /* original 24d0, guest PC 0x0c0c7594 */
if(!s->budget--) { s->failed_pc=0x0c0c7594u; return 0; }
write(ram,r[4],r[13],1);
goto P_0c0c7596;
P_0c0c7596: /* original 4610, guest PC 0x0c0c7596 */
if(!s->budget--) { s->failed_pc=0x0c0c7596u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c0c7598;
P_0c0c7598: /* original 7401, guest PC 0x0c0c7598 */
if(!s->budget--) { s->failed_pc=0x0c0c7598u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c759a;
P_0c0c759a: /* original 8ffb, guest PC 0x0c0c759a */
if(!s->budget--) { s->failed_pc=0x0c0c759au; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c0c7594; }
goto P_0c0c759e;
P_0c0c759c: /* original 7d01, guest PC 0x0c0c759c */
if(!s->budget--) { s->failed_pc=0x0c0c759cu; return 0; }
r[13]+=0x00000001u;
goto P_0c0c759e;
P_0c0c759e: /* original 77ff, guest PC 0x0c0c759e */
if(!s->budget--) { s->failed_pc=0x0c0c759eu; return 0; }
r[7]+=0xffffffffu;
goto P_0c0c75a0;
P_0c0c75a0: /* original 4715, guest PC 0x0c0c75a0 */
if(!s->budget--) { s->failed_pc=0x0c0c75a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c0c75a2;
P_0c0c75a2: /* original 89ee, guest PC 0x0c0c75a2 */
if(!s->budget--) { s->failed_pc=0x0c0c75a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7582; }
goto P_0c0c75a4;
P_0c0c75a4: /* original 9343, guest PC 0x0c0c75a4 */
if(!s->budget--) { s->failed_pc=0x0c0c75a4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c762eu,2);
goto P_0c0c75a6;
P_0c0c75a6: /* original ed0c, guest PC 0x0c0c75a6 */
if(!s->budget--) { s->failed_pc=0x0c0c75a6u; return 0; }
r[13]=0x0000000cu;
goto P_0c0c75a8;
P_0c0c75a8: /* original 6b53, guest PC 0x0c0c75a8 */
if(!s->budget--) { s->failed_pc=0x0c0c75a8u; return 0; }
r[11]=r[5];
goto P_0c0c75aa;
P_0c0c75aa: /* original 3e3c, guest PC 0x0c0c75aa */
if(!s->budget--) { s->failed_pc=0x0c0c75aau; return 0; }
r[14]+=r[3];
goto P_0c0c75ac;
P_0c0c75ac: /* original ec20, guest PC 0x0c0c75ac */
if(!s->budget--) { s->failed_pc=0x0c0c75acu; return 0; }
r[12]=0x00000020u;
goto P_0c0c75ae;
P_0c0c75ae: /* original d223, guest PC 0x0c0c75ae */
if(!s->budget--) { s->failed_pc=0x0c0c75aeu; return 0; }
r[2]=read(ram,0x0c0c763cu,4);
goto P_0c0c75b0;
P_0c0c75b0: /* original 420b, guest PC 0x0c0c75b0 */
if(!s->budget--) { s->failed_pc=0x0c0c75b0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c75b4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c75b4u) { target=s->pc; goto dispatch; }
goto P_0c0c75b4;
P_0c0c75b2: /* original 0009, guest PC 0x0c0c75b2 */
if(!s->budget--) { s->failed_pc=0x0c0c75b2u; return 0; }
goto P_0c0c75b4;
P_0c0c75b4: /* original e3f8, guest PC 0x0c0c75b4 */
if(!s->budget--) { s->failed_pc=0x0c0c75b4u; return 0; }
r[3]=0xfffffff8u;
goto P_0c0c75b6;
P_0c0c75b6: /* original 6503, guest PC 0x0c0c75b6 */
if(!s->budget--) { s->failed_pc=0x0c0c75b6u; return 0; }
r[5]=r[0];
goto P_0c0c75b8;
P_0c0c75b8: /* original 6403, guest PC 0x0c0c75b8 */
if(!s->budget--) { s->failed_pc=0x0c0c75b8u; return 0; }
r[4]=r[0];
goto P_0c0c75ba;
P_0c0c75ba: /* original 644c, guest PC 0x0c0c75ba */
if(!s->budget--) { s->failed_pc=0x0c0c75bau; return 0; }
r[4]=r[4]&255u;
goto P_0c0c75bc;
P_0c0c75bc: /* original d220, guest PC 0x0c0c75bc */
if(!s->budget--) { s->failed_pc=0x0c0c75bcu; return 0; }
r[2]=read(ram,0x0c0c7640u,4);
goto P_0c0c75be;
P_0c0c75be: /* original 453c, guest PC 0x0c0c75be */
if(!s->budget--) { s->failed_pc=0x0c0c75beu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c0c75c0;
P_0c0c75c0: /* original 6143, guest PC 0x0c0c75c0 */
if(!s->budget--) { s->failed_pc=0x0c0c75c0u; return 0; }
r[1]=r[4];
goto P_0c0c75c2;
P_0c0c75c2: /* original 655c, guest PC 0x0c0c75c2 */
if(!s->budget--) { s->failed_pc=0x0c0c75c2u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c75c4;
P_0c0c75c4: /* original 420b, guest PC 0x0c0c75c4 */
if(!s->budget--) { s->failed_pc=0x0c0c75c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c75c8u;
r[0]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c75c8u) { target=s->pc; goto dispatch; }
goto P_0c0c75c8;
P_0c0c75c6: /* original 60d3, guest PC 0x0c0c75c6 */
if(!s->budget--) { s->failed_pc=0x0c0c75c6u; return 0; }
r[0]=r[13];
goto P_0c0c75c8;
P_0c0c75c8: /* original 6603, guest PC 0x0c0c75c8 */
if(!s->budget--) { s->failed_pc=0x0c0c75c8u; return 0; }
r[6]=r[0];
goto P_0c0c75ca;
P_0c0c75ca: /* original 4600, guest PC 0x0c0c75ca */
if(!s->budget--) { s->failed_pc=0x0c0c75cau; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0c75cc;
P_0c0c75cc: /* original 6303, guest PC 0x0c0c75cc */
if(!s->budget--) { s->failed_pc=0x0c0c75ccu; return 0; }
r[3]=r[0];
goto P_0c0c75ce;
P_0c0c75ce: /* original 363c, guest PC 0x0c0c75ce */
if(!s->budget--) { s->failed_pc=0x0c0c75ceu; return 0; }
r[6]+=r[3];
goto P_0c0c75d0;
P_0c0c75d0: /* original d21b, guest PC 0x0c0c75d0 */
if(!s->budget--) { s->failed_pc=0x0c0c75d0u; return 0; }
r[2]=read(ram,0x0c0c7640u,4);
goto P_0c0c75d2;
P_0c0c75d2: /* original 4608, guest PC 0x0c0c75d2 */
if(!s->budget--) { s->failed_pc=0x0c0c75d2u; return 0; }
r[6]<<=2;
goto P_0c0c75d4;
P_0c0c75d4: /* original 6153, guest PC 0x0c0c75d4 */
if(!s->budget--) { s->failed_pc=0x0c0c75d4u; return 0; }
r[1]=r[5];
goto P_0c0c75d6;
P_0c0c75d6: /* original 3468, guest PC 0x0c0c75d6 */
if(!s->budget--) { s->failed_pc=0x0c0c75d6u; return 0; }
r[4]-=r[6];
goto P_0c0c75d8;
P_0c0c75d8: /* original 420b, guest PC 0x0c0c75d8 */
if(!s->budget--) { s->failed_pc=0x0c0c75d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c75dcu;
r[0]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c75dcu) { target=s->pc; goto dispatch; }
goto P_0c0c75dc;
P_0c0c75da: /* original 60d3, guest PC 0x0c0c75da */
if(!s->budget--) { s->failed_pc=0x0c0c75dau; return 0; }
r[0]=r[13];
goto P_0c0c75dc;
P_0c0c75dc: /* original 6603, guest PC 0x0c0c75dc */
if(!s->budget--) { s->failed_pc=0x0c0c75dcu; return 0; }
r[6]=r[0];
goto P_0c0c75de;
P_0c0c75de: /* original 4600, guest PC 0x0c0c75de */
if(!s->budget--) { s->failed_pc=0x0c0c75deu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0c75e0;
P_0c0c75e0: /* original 6303, guest PC 0x0c0c75e0 */
if(!s->budget--) { s->failed_pc=0x0c0c75e0u; return 0; }
r[3]=r[0];
goto P_0c0c75e2;
P_0c0c75e2: /* original 363c, guest PC 0x0c0c75e2 */
if(!s->budget--) { s->failed_pc=0x0c0c75e2u; return 0; }
r[6]+=r[3];
goto P_0c0c75e4;
P_0c0c75e4: /* original 4608, guest PC 0x0c0c75e4 */
if(!s->budget--) { s->failed_pc=0x0c0c75e4u; return 0; }
r[6]<<=2;
goto P_0c0c75e6;
P_0c0c75e6: /* original 3568, guest PC 0x0c0c75e6 */
if(!s->budget--) { s->failed_pc=0x0c0c75e6u; return 0; }
r[5]-=r[6];
goto P_0c0c75e8;
P_0c0c75e8: /* original 6643, guest PC 0x0c0c75e8 */
if(!s->budget--) { s->failed_pc=0x0c0c75e8u; return 0; }
r[6]=r[4];
goto P_0c0c75ea;
P_0c0c75ea: /* original 6753, guest PC 0x0c0c75ea */
if(!s->budget--) { s->failed_pc=0x0c0c75eau; return 0; }
r[7]=r[5];
goto P_0c0c75ec;
P_0c0c75ec: /* original 37ec, guest PC 0x0c0c75ec */
if(!s->budget--) { s->failed_pc=0x0c0c75ecu; return 0; }
r[7]+=r[14];
goto P_0c0c75ee;
P_0c0c75ee: /* original 36ec, guest PC 0x0c0c75ee */
if(!s->budget--) { s->failed_pc=0x0c0c75eeu; return 0; }
r[6]+=r[14];
goto P_0c0c75f0;
P_0c0c75f0: /* original 2f62, guest PC 0x0c0c75f0 */
if(!s->budget--) { s->failed_pc=0x0c0c75f0u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0c75f2;
P_0c0c75f2: /* original 4c10, guest PC 0x0c0c75f2 */
if(!s->budget--) { s->failed_pc=0x0c0c75f2u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c0c75f4;
P_0c0c75f4: /* original 6470, guest PC 0x0c0c75f4 */
if(!s->budget--) { s->failed_pc=0x0c0c75f4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[4]=tmp;
goto P_0c0c75f6;
P_0c0c75f6: /* original 6660, guest PC 0x0c0c75f6 */
if(!s->budget--) { s->failed_pc=0x0c0c75f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c0c75f8;
P_0c0c75f8: /* original 63f2, guest PC 0x0c0c75f8 */
if(!s->budget--) { s->failed_pc=0x0c0c75f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c75fa;
P_0c0c75fa: /* original 644c, guest PC 0x0c0c75fa */
if(!s->budget--) { s->failed_pc=0x0c0c75fau; return 0; }
r[4]=r[4]&255u;
goto P_0c0c75fc;
P_0c0c75fc: /* original 666c, guest PC 0x0c0c75fc */
if(!s->budget--) { s->failed_pc=0x0c0c75fcu; return 0; }
r[6]=r[6]&255u;
goto P_0c0c75fe;
P_0c0c75fe: /* original 2340, guest PC 0x0c0c75fe */
if(!s->budget--) { s->failed_pc=0x0c0c75feu; return 0; }
write(ram,r[3],r[4],1);
goto P_0c0c7600;
P_0c0c7600: /* original 8fd5, guest PC 0x0c0c7600 */
if(!s->budget--) { s->failed_pc=0x0c0c7600u; return 0; }
cond=r[17]&1u;
write(ram,r[7],r[6],1);
if(!cond) { goto P_0c0c75ae; }
goto P_0c0c7604;
P_0c0c7602: /* original 2760, guest PC 0x0c0c7602 */
if(!s->budget--) { s->failed_pc=0x0c0c7602u; return 0; }
write(ram,r[7],r[6],1);
goto P_0c0c7604;
P_0c0c7604: /* original 7bff, guest PC 0x0c0c7604 */
if(!s->budget--) { s->failed_pc=0x0c0c7604u; return 0; }
r[11]+=0xffffffffu;
goto P_0c0c7606;
P_0c0c7606: /* original e009, guest PC 0x0c0c7606 */
if(!s->budget--) { s->failed_pc=0x0c0c7606u; return 0; }
r[0]=0x00000009u;
goto P_0c0c7608;
P_0c0c7608: /* original 4b15, guest PC 0x0c0c7608 */
if(!s->budget--) { s->failed_pc=0x0c0c7608u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c0c760a;
P_0c0c760a: /* original 80e8, guest PC 0x0c0c760a */
if(!s->budget--) { s->failed_pc=0x0c0c760au; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c0c760c;
P_0c0c760c: /* original 8dce, guest PC 0x0c0c760c */
if(!s->budget--) { s->failed_pc=0x0c0c760cu; return 0; }
cond=r[17]&1u;
r[14]+=0x0000000cu;
if(cond) { goto P_0c0c75ac; }
goto P_0c0c7610;
P_0c0c760e: /* original 7e0c, guest PC 0x0c0c760e */
if(!s->budget--) { s->failed_pc=0x0c0c760eu; return 0; }
r[14]+=0x0000000cu;
goto P_0c0c7610;
P_0c0c7610: /* original 7f04, guest PC 0x0c0c7610 */
if(!s->budget--) { s->failed_pc=0x0c0c7610u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7612;
P_0c0c7612: /* original 4f26, guest PC 0x0c0c7612 */
if(!s->budget--) { s->failed_pc=0x0c0c7612u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7614;
P_0c0c7614: /* original 6bf6, guest PC 0x0c0c7614 */
if(!s->budget--) { s->failed_pc=0x0c0c7614u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7616;
P_0c0c7616: /* original 6cf6, guest PC 0x0c0c7616 */
if(!s->budget--) { s->failed_pc=0x0c0c7616u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7618;
P_0c0c7618: /* original 6df6, guest PC 0x0c0c7618 */
if(!s->budget--) { s->failed_pc=0x0c0c7618u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c761a;
P_0c0c761a: /* original 000b, guest PC 0x0c0c761a */
if(!s->budget--) { s->failed_pc=0x0c0c761au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c761c: /* original 6ef6, guest PC 0x0c0c761c */
if(!s->budget--) { s->failed_pc=0x0c0c761cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c761eu,s,ram);
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
P_0c0c78e0: /* original 4f22, guest PC 0x0c0c78e0 */
if(!s->budget--) { s->failed_pc=0x0c0c78e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c78e2;
P_0c0c78e2: /* original de37, guest PC 0x0c0c78e2 */
if(!s->budget--) { s->failed_pc=0x0c0c78e2u; return 0; }
r[14]=read(ram,0x0c0c79c0u,4);
goto P_0c0c78e4;
P_0c0c78e4: /* original 7ffc, guest PC 0x0c0c78e4 */
if(!s->budget--) { s->failed_pc=0x0c0c78e4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c78e6;
P_0c0c78e6: /* original 8f55, guest PC 0x0c0c78e6 */
if(!s->budget--) { s->failed_pc=0x0c0c78e6u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[4]+24,4);
if(!cond) { goto P_0c0c7994; }
goto P_0c0c78ea;
P_0c0c78e8: /* original 5b46, guest PC 0x0c0c78e8 */
if(!s->budget--) { s->failed_pc=0x0c0c78e8u; return 0; }
r[11]=read(ram,r[4]+24,4);
goto P_0c0c78ea;
P_0c0c78ea: /* original d33d, guest PC 0x0c0c78ea */
if(!s->budget--) { s->failed_pc=0x0c0c78eau; return 0; }
r[3]=read(ram,0x0c0c79e0u,4);
goto P_0c0c78ec;
P_0c0c78ec: /* original d23d, guest PC 0x0c0c78ec */
if(!s->budget--) { s->failed_pc=0x0c0c78ecu; return 0; }
r[2]=read(ram,0x0c0c79e4u,4);
goto P_0c0c78ee;
P_0c0c78ee: /* original 905e, guest PC 0x0c0c78ee */
if(!s->budget--) { s->failed_pc=0x0c0c78eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79aeu,2);
goto P_0c0c78f0;
P_0c0c78f0: /* original 6522, guest PC 0x0c0c78f0 */
if(!s->budget--) { s->failed_pc=0x0c0c78f0u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c78f2;
P_0c0c78f2: /* original d13d, guest PC 0x0c0c78f2 */
if(!s->budget--) { s->failed_pc=0x0c0c78f2u; return 0; }
r[1]=read(ram,0x0c0c79e8u,4);
goto P_0c0c78f4;
P_0c0c78f4: /* original 0cee, guest PC 0x0c0c78f4 */
if(!s->budget--) { s->failed_pc=0x0c0c78f4u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0c78f6;
P_0c0c78f6: /* original 6631, guest PC 0x0c0c78f6 */
if(!s->budget--) { s->failed_pc=0x0c0c78f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[6]=tmp;
goto P_0c0c78f8;
P_0c0c78f8: /* original 410b, guest PC 0x0c0c78f8 */
if(!s->budget--) { s->failed_pc=0x0c0c78f8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c78fcu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c78fcu) { target=s->pc; goto dispatch; }
goto P_0c0c78fc;
P_0c0c78fa: /* original 64c3, guest PC 0x0c0c78fa */
if(!s->budget--) { s->failed_pc=0x0c0c78fau; return 0; }
r[4]=r[12];
goto P_0c0c78fc;
P_0c0c78fc: /* original d83b, guest PC 0x0c0c78fc */
if(!s->budget--) { s->failed_pc=0x0c0c78fcu; return 0; }
r[8]=read(ram,0x0c0c79ecu,4);
goto P_0c0c78fe;
P_0c0c78fe: /* original 9a57, guest PC 0x0c0c78fe */
if(!s->budget--) { s->failed_pc=0x0c0c78feu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b0u,2);
goto P_0c0c7900;
P_0c0c7900: /* original 59c4, guest PC 0x0c0c7900 */
if(!s->budget--) { s->failed_pc=0x0c0c7900u; return 0; }
r[9]=read(ram,r[12]+16,4);
goto P_0c0c7902;
P_0c0c7902: /* original a007, guest PC 0x0c0c7902 */
if(!s->budget--) { s->failed_pc=0x0c0c7902u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7914;
P_0c0c7904: /* original ed00, guest PC 0x0c0c7904 */
if(!s->budget--) { s->failed_pc=0x0c0c7904u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7906;
P_0c0c7906: /* original 60d3, guest PC 0x0c0c7906 */
if(!s->budget--) { s->failed_pc=0x0c0c7906u; return 0; }
r[0]=r[13];
goto P_0c0c7908;
P_0c0c7908: /* original 4008, guest PC 0x0c0c7908 */
if(!s->budget--) { s->failed_pc=0x0c0c7908u; return 0; }
r[0]<<=2;
goto P_0c0c790a;
P_0c0c790a: /* original 059e, guest PC 0x0c0c790a */
if(!s->budget--) { s->failed_pc=0x0c0c790au; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0c790c;
P_0c0c790c: /* original 64a3, guest PC 0x0c0c790c */
if(!s->budget--) { s->failed_pc=0x0c0c790cu; return 0; }
r[4]=r[10];
goto P_0c0c790e;
P_0c0c790e: /* original 480b, guest PC 0x0c0c790e */
if(!s->budget--) { s->failed_pc=0x0c0c790eu; return 0; }
target=r[8];
r[16]=code_base|0x0c0c7912u;
r[10]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7912u) { target=s->pc; goto dispatch; }
goto P_0c0c7912;
P_0c0c7910: /* original 7a01, guest PC 0x0c0c7910 */
if(!s->budget--) { s->failed_pc=0x0c0c7910u; return 0; }
r[10]+=0x00000001u;
goto P_0c0c7912;
P_0c0c7912: /* original 7d01, guest PC 0x0c0c7912 */
if(!s->budget--) { s->failed_pc=0x0c0c7912u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c7914;
P_0c0c7914: /* original 85c6, guest PC 0x0c0c7914 */
if(!s->budget--) { s->failed_pc=0x0c0c7914u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7916;
P_0c0c7916: /* original 600d, guest PC 0x0c0c7916 */
if(!s->budget--) { s->failed_pc=0x0c0c7916u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7918;
P_0c0c7918: /* original 3d03, guest PC 0x0c0c7918 */
if(!s->budget--) { s->failed_pc=0x0c0c7918u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[0])!=0);
goto P_0c0c791a;
P_0c0c791a: /* original 8bf4, guest PC 0x0c0c791a */
if(!s->budget--) { s->failed_pc=0x0c0c791au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7906; }
goto P_0c0c791c;
P_0c0c791c: /* original 9047, guest PC 0x0c0c791c */
if(!s->budget--) { s->failed_pc=0x0c0c791cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79aeu,2);
goto P_0c0c791e;
P_0c0c791e: /* original 6db3, guest PC 0x0c0c791e */
if(!s->budget--) { s->failed_pc=0x0c0c791eu; return 0; }
r[13]=r[11];
goto P_0c0c7920;
P_0c0c7920: /* original 53c6, guest PC 0x0c0c7920 */
if(!s->budget--) { s->failed_pc=0x0c0c7920u; return 0; }
r[3]=read(ram,r[12]+24,4);
goto P_0c0c7922;
P_0c0c7922: /* original 4d08, guest PC 0x0c0c7922 */
if(!s->budget--) { s->failed_pc=0x0c0c7922u; return 0; }
r[13]<<=2;
goto P_0c0c7924;
P_0c0c7924: /* original 02ee, guest PC 0x0c0c7924 */
if(!s->budget--) { s->failed_pc=0x0c0c7924u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c7926;
P_0c0c7926: /* original 7004, guest PC 0x0c0c7926 */
if(!s->budget--) { s->failed_pc=0x0c0c7926u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7928;
P_0c0c7928: /* original 9143, guest PC 0x0c0c7928 */
if(!s->budget--) { s->failed_pc=0x0c0c7928u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b2u,2);
goto P_0c0c792a;
P_0c0c792a: /* original 4d00, guest PC 0x0c0c792a */
if(!s->budget--) { s->failed_pc=0x0c0c792au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0c792c;
P_0c0c792c: /* original 323c, guest PC 0x0c0c792c */
if(!s->budget--) { s->failed_pc=0x0c0c792cu; return 0; }
r[2]+=r[3];
goto P_0c0c792e;
P_0c0c792e: /* original 9341, guest PC 0x0c0c792e */
if(!s->budget--) { s->failed_pc=0x0c0c792eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b4u,2);
goto P_0c0c7930;
P_0c0c7930: /* original 321c, guest PC 0x0c0c7930 */
if(!s->budget--) { s->failed_pc=0x0c0c7930u; return 0; }
r[2]+=r[1];
goto P_0c0c7932;
P_0c0c7932: /* original 2239, guest PC 0x0c0c7932 */
if(!s->budget--) { s->failed_pc=0x0c0c7932u; return 0; }
r[2]&=r[3];
goto P_0c0c7934;
P_0c0c7934: /* original 0e26, guest PC 0x0c0c7934 */
if(!s->budget--) { s->failed_pc=0x0c0c7934u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c7936;
P_0c0c7936: /* original 70f8, guest PC 0x0c0c7936 */
if(!s->budget--) { s->failed_pc=0x0c0c7936u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c7938;
P_0c0c7938: /* original 0e26, guest PC 0x0c0c7938 */
if(!s->budget--) { s->failed_pc=0x0c0c7938u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c793a;
P_0c0c793a: /* original d22d, guest PC 0x0c0c793a */
if(!s->budget--) { s->failed_pc=0x0c0c793au; return 0; }
r[2]=read(ram,0x0c0c79f0u,4);
goto P_0c0c793c;
P_0c0c793c: /* original 3d2c, guest PC 0x0c0c793c */
if(!s->budget--) { s->failed_pc=0x0c0c793cu; return 0; }
r[13]+=r[2];
goto P_0c0c793e;
P_0c0c793e: /* original 60d2, guest PC 0x0c0c793e */
if(!s->budget--) { s->failed_pc=0x0c0c793eu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c7940;
P_0c0c7940: /* original 88ff, guest PC 0x0c0c7940 */
if(!s->budget--) { s->failed_pc=0x0c0c7940u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7942;
P_0c0c7942: /* original 891f, guest PC 0x0c0c7942 */
if(!s->budget--) { s->failed_pc=0x0c0c7942u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7984; }
goto P_0c0c7944;
P_0c0c7944: /* original 9137, guest PC 0x0c0c7944 */
if(!s->budget--) { s->failed_pc=0x0c0c7944u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b6u,2);
goto P_0c0c7946;
P_0c0c7946: /* original e700, guest PC 0x0c0c7946 */
if(!s->budget--) { s->failed_pc=0x0c0c7946u; return 0; }
r[7]=0x00000000u;
goto P_0c0c7948;
P_0c0c7948: /* original 2f16, guest PC 0x0c0c7948 */
if(!s->budget--) { s->failed_pc=0x0c0c7948u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c794a;
P_0c0c794a: /* original d32a, guest PC 0x0c0c794a */
if(!s->budget--) { s->failed_pc=0x0c0c794au; return 0; }
r[3]=read(ram,0x0c0c79f4u,4);
goto P_0c0c794c;
P_0c0c794c: /* original 2f36, guest PC 0x0c0c794c */
if(!s->budget--) { s->failed_pc=0x0c0c794cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c794e;
P_0c0c794e: /* original 2fb6, guest PC 0x0c0c794e */
if(!s->budget--) { s->failed_pc=0x0c0c794eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7950;
P_0c0c7950: /* original 9632, guest PC 0x0c0c7950 */
if(!s->budget--) { s->failed_pc=0x0c0c7950u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b8u,2);
goto P_0c0c7952;
P_0c0c7952: /* original 9032, guest PC 0x0c0c7952 */
if(!s->budget--) { s->failed_pc=0x0c0c7952u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79bau,2);
goto P_0c0c7954;
P_0c0c7954: /* original 36ec, guest PC 0x0c0c7954 */
if(!s->budget--) { s->failed_pc=0x0c0c7954u; return 0; }
r[6]+=r[14];
goto P_0c0c7956;
P_0c0c7956: /* original 05ee, guest PC 0x0c0c7956 */
if(!s->budget--) { s->failed_pc=0x0c0c7956u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c7958;
P_0c0c7958: /* original 7608, guest PC 0x0c0c7958 */
if(!s->budget--) { s->failed_pc=0x0c0c7958u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c795a;
P_0c0c795a: /* original 1fd3, guest PC 0x0c0c795a */
if(!s->budget--) { s->failed_pc=0x0c0c795au; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0c795c;
P_0c0c795c: /* original d326, guest PC 0x0c0c795c */
if(!s->budget--) { s->failed_pc=0x0c0c795cu; return 0; }
r[3]=read(ram,0x0c0c79f8u,4);
goto P_0c0c795e;
P_0c0c795e: /* original 430b, guest PC 0x0c0c795e */
if(!s->budget--) { s->failed_pc=0x0c0c795eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7962u;
tmp=read(ram,r[13],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7962u) { target=s->pc; goto dispatch; }
goto P_0c0c7962;
P_0c0c7960: /* original 64d2, guest PC 0x0c0c7960 */
if(!s->budget--) { s->failed_pc=0x0c0c7960u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0c7962;
P_0c0c7962: /* original 922b, guest PC 0x0c0c7962 */
if(!s->budget--) { s->failed_pc=0x0c0c7962u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79bcu,2);
goto P_0c0c7964;
P_0c0c7964: /* original 2f26, guest PC 0x0c0c7964 */
if(!s->budget--) { s->failed_pc=0x0c0c7964u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7966;
P_0c0c7966: /* original d323, guest PC 0x0c0c7966 */
if(!s->budget--) { s->failed_pc=0x0c0c7966u; return 0; }
r[3]=read(ram,0x0c0c79f4u,4);
goto P_0c0c7968;
P_0c0c7968: /* original 2f36, guest PC 0x0c0c7968 */
if(!s->budget--) { s->failed_pc=0x0c0c7968u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c796a;
P_0c0c796a: /* original 2fb6, guest PC 0x0c0c796a */
if(!s->budget--) { s->failed_pc=0x0c0c796au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c796c;
P_0c0c796c: /* original 9624, guest PC 0x0c0c796c */
if(!s->budget--) { s->failed_pc=0x0c0c796cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b8u,2);
goto P_0c0c796e;
P_0c0c796e: /* original d11d, guest PC 0x0c0c796e */
if(!s->budget--) { s->failed_pc=0x0c0c796eu; return 0; }
r[1]=read(ram,0x0c0c79e4u,4);
goto P_0c0c7970;
P_0c0c7970: /* original 53f6, guest PC 0x0c0c7970 */
if(!s->budget--) { s->failed_pc=0x0c0c7970u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c7972;
P_0c0c7972: /* original 36ec, guest PC 0x0c0c7972 */
if(!s->budget--) { s->failed_pc=0x0c0c7972u; return 0; }
r[6]+=r[14];
goto P_0c0c7974;
P_0c0c7974: /* original 6512, guest PC 0x0c0c7974 */
if(!s->budget--) { s->failed_pc=0x0c0c7974u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c0c7976;
P_0c0c7976: /* original 7608, guest PC 0x0c0c7976 */
if(!s->budget--) { s->failed_pc=0x0c0c7976u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7978;
P_0c0c7978: /* original d720, guest PC 0x0c0c7978 */
if(!s->budget--) { s->failed_pc=0x0c0c7978u; return 0; }
r[7]=read(ram,0x0c0c79fcu,4);
goto P_0c0c797a;
P_0c0c797a: /* original d21f, guest PC 0x0c0c797a */
if(!s->budget--) { s->failed_pc=0x0c0c797au; return 0; }
r[2]=read(ram,0x0c0c79f8u,4);
goto P_0c0c797c;
P_0c0c797c: /* original 420b, guest PC 0x0c0c797c */
if(!s->budget--) { s->failed_pc=0x0c0c797cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7980u;
r[4]=read(ram,r[3]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7980u) { target=s->pc; goto dispatch; }
goto P_0c0c7980;
P_0c0c797e: /* original 5431, guest PC 0x0c0c797e */
if(!s->budget--) { s->failed_pc=0x0c0c797eu; return 0; }
r[4]=read(ram,r[3]+4,4);
goto P_0c0c7980;
P_0c0c7980: /* original a008, guest PC 0x0c0c7980 */
if(!s->budget--) { s->failed_pc=0x0c0c7980u; return 0; }
r[15]+=0x00000018u;
goto P_0c0c7994;
P_0c0c7982: /* original 7f18, guest PC 0x0c0c7982 */
if(!s->budget--) { s->failed_pc=0x0c0c7982u; return 0; }
r[15]+=0x00000018u;
goto P_0c0c7984;
P_0c0c7984: /* original 9119, guest PC 0x0c0c7984 */
if(!s->budget--) { s->failed_pc=0x0c0c7984u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79bau,2);
goto P_0c0c7986;
P_0c0c7986: /* original e000, guest PC 0x0c0c7986 */
if(!s->budget--) { s->failed_pc=0x0c0c7986u; return 0; }
r[0]=0x00000000u;
goto P_0c0c7988;
P_0c0c7988: /* original e3ff, guest PC 0x0c0c7988 */
if(!s->budget--) { s->failed_pc=0x0c0c7988u; return 0; }
r[3]=0xffffffffu;
goto P_0c0c798a;
P_0c0c798a: /* original 31ec, guest PC 0x0c0c798a */
if(!s->budget--) { s->failed_pc=0x0c0c798au; return 0; }
r[1]+=r[14];
goto P_0c0c798c;
P_0c0c798c: /* original 2102, guest PC 0x0c0c798c */
if(!s->budget--) { s->failed_pc=0x0c0c798cu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0c798e;
P_0c0c798e: /* original 900d, guest PC 0x0c0c798e */
if(!s->budget--) { s->failed_pc=0x0c0c798eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79acu,2);
goto P_0c0c7990;
P_0c0c7990: /* original bf37, guest PC 0x0c0c7990 */
if(!s->budget--) { s->failed_pc=0x0c0c7990u; return 0; }
target=0x0c0c7802u; r[16]=code_base|0x0c0c7994u;
write(ram,r[14]+r[0],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7994u) { target=s->pc; goto dispatch; }
goto P_0c0c7994;
P_0c0c7992: /* original 0e36, guest PC 0x0c0c7992 */
if(!s->budget--) { s->failed_pc=0x0c0c7992u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c7994;
P_0c0c7994: /* original 7f04, guest PC 0x0c0c7994 */
if(!s->budget--) { s->failed_pc=0x0c0c7994u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7996;
P_0c0c7996: /* original 4f26, guest PC 0x0c0c7996 */
if(!s->budget--) { s->failed_pc=0x0c0c7996u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7998;
P_0c0c7998: /* original e000, guest PC 0x0c0c7998 */
if(!s->budget--) { s->failed_pc=0x0c0c7998u; return 0; }
r[0]=0x00000000u;
goto P_0c0c799a;
P_0c0c799a: /* original 68f6, guest PC 0x0c0c799a */
if(!s->budget--) { s->failed_pc=0x0c0c799au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c799c;
P_0c0c799c: /* original 69f6, guest PC 0x0c0c799c */
if(!s->budget--) { s->failed_pc=0x0c0c799cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c799e;
P_0c0c799e: /* original 6af6, guest PC 0x0c0c799e */
if(!s->budget--) { s->failed_pc=0x0c0c799eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c79a0;
P_0c0c79a0: /* original 6bf6, guest PC 0x0c0c79a0 */
if(!s->budget--) { s->failed_pc=0x0c0c79a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c79a2;
P_0c0c79a2: /* original 6cf6, guest PC 0x0c0c79a2 */
if(!s->budget--) { s->failed_pc=0x0c0c79a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c79a4;
P_0c0c79a4: /* original 6df6, guest PC 0x0c0c79a4 */
if(!s->budget--) { s->failed_pc=0x0c0c79a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c79a6;
P_0c0c79a6: /* original 000b, guest PC 0x0c0c79a6 */
if(!s->budget--) { s->failed_pc=0x0c0c79a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c79a8: /* original 6ef6, guest PC 0x0c0c79a8 */
if(!s->budget--) { s->failed_pc=0x0c0c79a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c79aau,s,ram);
P_0c0c8e7c: /* original 4f22, guest PC 0x0c0c8e7c */
if(!s->budget--) { s->failed_pc=0x0c0c8e7cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8e7e;
P_0c0c8e7e: /* original 0ecc, guest PC 0x0c0c8e7e */
if(!s->budget--) { s->failed_pc=0x0c0c8e7eu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c8e80;
P_0c0c8e80: /* original d032, guest PC 0x0c0c8e80 */
if(!s->budget--) { s->failed_pc=0x0c0c8e80u; return 0; }
r[0]=read(ram,0x0c0c8f4cu,4);
goto P_0c0c8e82;
P_0c0c8e82: /* original 7ffc, guest PC 0x0c0c8e82 */
if(!s->budget--) { s->failed_pc=0x0c0c8e82u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c8e84;
P_0c0c8e84: /* original db2f, guest PC 0x0c0c8e84 */
if(!s->budget--) { s->failed_pc=0x0c0c8e84u; return 0; }
r[11]=read(ram,0x0c0c8f44u,4);
goto P_0c0c8e86;
P_0c0c8e86: /* original 04ec, guest PC 0x0c0c8e86 */
if(!s->budget--) { s->failed_pc=0x0c0c8e86u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8e88;
P_0c0c8e88: /* original 644c, guest PC 0x0c0c8e88 */
if(!s->budget--) { s->failed_pc=0x0c0c8e88u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c8e8a;
P_0c0c8e8a: /* original 443c, guest PC 0x0c0c8e8a */
if(!s->budget--) { s->failed_pc=0x0c0c8e8au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0c8e8c;
P_0c0c8e8c: /* original 242b, guest PC 0x0c0c8e8c */
if(!s->budget--) { s->failed_pc=0x0c0c8e8cu; return 0; }
r[4]|=r[2];
goto P_0c0c8e8e;
P_0c0c8e8e: /* original 2f42, guest PC 0x0c0c8e8e */
if(!s->budget--) { s->failed_pc=0x0c0c8e8eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c8e90;
P_0c0c8e90: /* original d12f, guest PC 0x0c0c8e90 */
if(!s->budget--) { s->failed_pc=0x0c0c8e90u; return 0; }
r[1]=read(ram,0x0c0c8f50u,4);
goto P_0c0c8e92;
P_0c0c8e92: /* original 2f16, guest PC 0x0c0c8e92 */
if(!s->budget--) { s->failed_pc=0x0c0c8e92u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e94;
P_0c0c8e94: /* original d32f, guest PC 0x0c0c8e94 */
if(!s->budget--) { s->failed_pc=0x0c0c8e94u; return 0; }
r[3]=read(ram,0x0c0c8f54u,4);
goto P_0c0c8e96;
P_0c0c8e96: /* original 430b, guest PC 0x0c0c8e96 */
if(!s->budget--) { s->failed_pc=0x0c0c8e96u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8e9au;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8e9au) { target=s->pc; goto dispatch; }
goto P_0c0c8e9a;
P_0c0c8e98: /* original 54f1, guest PC 0x0c0c8e98 */
if(!s->budget--) { s->failed_pc=0x0c0c8e98u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c8e9a;
P_0c0c8e9a: /* original 904e, guest PC 0x0c0c8e9a */
if(!s->budget--) { s->failed_pc=0x0c0c8e9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f3au,2);
goto P_0c0c8e9c;
P_0c0c8e9c: /* original 7f04, guest PC 0x0c0c8e9c */
if(!s->budget--) { s->failed_pc=0x0c0c8e9cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8e9e;
P_0c0c8e9e: /* original 934d, guest PC 0x0c0c8e9e */
if(!s->budget--) { s->failed_pc=0x0c0c8e9eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f3cu,2);
goto P_0c0c8ea0;
P_0c0c8ea0: /* original 0dbe, guest PC 0x0c0c8ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea0u; return 0; }
r[13]=read(ram,r[11]+r[0],4);
goto P_0c0c8ea2;
P_0c0c8ea2: /* original 23d8, guest PC 0x0c0c8ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8ea4;
P_0c0c8ea4: /* original 8f14, guest PC 0x0c0c8ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea4u; return 0; }
cond=r[17]&1u;
r[4]=0x0000000fu;
if(!cond) { goto P_0c0c8ed0; }
goto P_0c0c8ea8;
P_0c0c8ea6: /* original e40f, guest PC 0x0c0c8ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea6u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c8ea8;
P_0c0c8ea8: /* original 9249, guest PC 0x0c0c8ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f3eu,2);
goto P_0c0c8eaa;
P_0c0c8eaa: /* original 22d8, guest PC 0x0c0c8eaa */
if(!s->budget--) { s->failed_pc=0x0c0c8eaau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c8eac;
P_0c0c8eac: /* original 8b15, guest PC 0x0c0c8eac */
if(!s->budget--) { s->failed_pc=0x0c0c8eacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8eda; }
goto P_0c0c8eae;
P_0c0c8eae: /* original e308, guest PC 0x0c0c8eae */
if(!s->budget--) { s->failed_pc=0x0c0c8eaeu; return 0; }
r[3]=0x00000008u;
goto P_0c0c8eb0;
P_0c0c8eb0: /* original 23d8, guest PC 0x0c0c8eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8eb2;
P_0c0c8eb2: /* original 8b12, guest PC 0x0c0c8eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8eda; }
goto P_0c0c8eb4;
P_0c0c8eb4: /* original d228, guest PC 0x0c0c8eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb4u; return 0; }
r[2]=read(ram,0x0c0c8f58u,4);
goto P_0c0c8eb6;
P_0c0c8eb6: /* original 22d8, guest PC 0x0c0c8eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c8eb8;
P_0c0c8eb8: /* original 8b0f, guest PC 0x0c0c8eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8eda; }
goto P_0c0c8eba;
P_0c0c8eba: /* original 9341, guest PC 0x0c0c8eba */
if(!s->budget--) { s->failed_pc=0x0c0c8ebau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f40u,2);
goto P_0c0c8ebc;
P_0c0c8ebc: /* original 23d8, guest PC 0x0c0c8ebc */
if(!s->budget--) { s->failed_pc=0x0c0c8ebcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8ebe;
P_0c0c8ebe: /* original 8b11, guest PC 0x0c0c8ebe */
if(!s->budget--) { s->failed_pc=0x0c0c8ebeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ee4; }
goto P_0c0c8ec0;
P_0c0c8ec0: /* original e204, guest PC 0x0c0c8ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec0u; return 0; }
r[2]=0x00000004u;
goto P_0c0c8ec2;
P_0c0c8ec2: /* original 22d8, guest PC 0x0c0c8ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c8ec4;
P_0c0c8ec4: /* original 8b0e, guest PC 0x0c0c8ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ee4; }
goto P_0c0c8ec6;
P_0c0c8ec6: /* original d325, guest PC 0x0c0c8ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec6u; return 0; }
r[3]=read(ram,0x0c0c8f5cu,4);
goto P_0c0c8ec8;
P_0c0c8ec8: /* original 23d8, guest PC 0x0c0c8ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8eca;
P_0c0c8eca: /* original 8b0b, guest PC 0x0c0c8eca */
if(!s->budget--) { s->failed_pc=0x0c0c8ecau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ee4; }
goto P_0c0c8ecc;
P_0c0c8ecc: /* original a014, guest PC 0x0c0c8ecc */
if(!s->budget--) { s->failed_pc=0x0c0c8eccu; return 0; }
goto P_0c0c8ef8;
P_0c0c8ece: /* original 0009, guest PC 0x0c0c8ece */
if(!s->budget--) { s->failed_pc=0x0c0c8eceu; return 0; }
goto P_0c0c8ed0;
P_0c0c8ed0: /* original 7eff, guest PC 0x0c0c8ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed0u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c8ed2;
P_0c0c8ed2: /* original 4e11, guest PC 0x0c0c8ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0c8ed4;
P_0c0c8ed4: /* original 8910, guest PC 0x0c0c8ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8ef8; }
goto P_0c0c8ed6;
P_0c0c8ed6: /* original a00f, guest PC 0x0c0c8ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed6u; return 0; }
r[14]=r[4];
goto P_0c0c8ef8;
P_0c0c8ed8: /* original 6e43, guest PC 0x0c0c8ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed8u; return 0; }
r[14]=r[4];
goto P_0c0c8eda;
P_0c0c8eda: /* original 7e01, guest PC 0x0c0c8eda */
if(!s->budget--) { s->failed_pc=0x0c0c8edau; return 0; }
r[14]+=0x00000001u;
goto P_0c0c8edc;
P_0c0c8edc: /* original 3e47, guest PC 0x0c0c8edc */
if(!s->budget--) { s->failed_pc=0x0c0c8edcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[4])!=0);
goto P_0c0c8ede;
P_0c0c8ede: /* original 8b0b, guest PC 0x0c0c8ede */
if(!s->budget--) { s->failed_pc=0x0c0c8edeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ef8; }
goto P_0c0c8ee0;
P_0c0c8ee0: /* original a00a, guest PC 0x0c0c8ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee0u; return 0; }
r[14]=0x00000000u;
goto P_0c0c8ef8;
P_0c0c8ee2: /* original ee00, guest PC 0x0c0c8ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee2u; return 0; }
r[14]=0x00000000u;
goto P_0c0c8ee4;
P_0c0c8ee4: /* original 60e3, guest PC 0x0c0c8ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee4u; return 0; }
r[0]=r[14];
goto P_0c0c8ee6;
P_0c0c8ee6: /* original 880f, guest PC 0x0c0c8ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0c8ee8;
P_0c0c8ee8: /* original 8b02, guest PC 0x0c0c8ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ef0; }
goto P_0c0c8eea;
P_0c0c8eea: /* original d21d, guest PC 0x0c0c8eea */
if(!s->budget--) { s->failed_pc=0x0c0c8eeau; return 0; }
r[2]=read(ram,0x0c0c8f60u,4);
goto P_0c0c8eec;
P_0c0c8eec: /* original 420b, guest PC 0x0c0c8eec */
if(!s->budget--) { s->failed_pc=0x0c0c8eecu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8ef0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8ef0u) { target=s->pc; goto dispatch; }
goto P_0c0c8ef0;
P_0c0c8eee: /* original 0009, guest PC 0x0c0c8eee */
if(!s->budget--) { s->failed_pc=0x0c0c8eeeu; return 0; }
goto P_0c0c8ef0;
P_0c0c8ef0: /* original 60e3, guest PC 0x0c0c8ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef0u; return 0; }
r[0]=r[14];
goto P_0c0c8ef2;
P_0c0c8ef2: /* original 7001, guest PC 0x0c0c8ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef2u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c8ef4;
P_0c0c8ef4: /* original 4000, guest PC 0x0c0c8ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c8ef6;
P_0c0c8ef6: /* original 80bb, guest PC 0x0c0c8ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef6u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c0c8ef8;
P_0c0c8ef8: /* original 60e3, guest PC 0x0c0c8ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef8u; return 0; }
r[0]=r[14];
goto P_0c0c8efa;
P_0c0c8efa: /* original 880e, guest PC 0x0c0c8efa */
if(!s->budget--) { s->failed_pc=0x0c0c8efau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0c8efc;
P_0c0c8efc: /* original 8b05, guest PC 0x0c0c8efc */
if(!s->budget--) { s->failed_pc=0x0c0c8efcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8f0a; }
goto P_0c0c8efe;
P_0c0c8efe: /* original d319, guest PC 0x0c0c8efe */
if(!s->budget--) { s->failed_pc=0x0c0c8efeu; return 0; }
r[3]=read(ram,0x0c0c8f64u,4);
goto P_0c0c8f00;
P_0c0c8f00: /* original 2d38, guest PC 0x0c0c8f00 */
if(!s->budget--) { s->failed_pc=0x0c0c8f00u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c0c8f02;
P_0c0c8f02: /* original 8901, guest PC 0x0c0c8f02 */
if(!s->budget--) { s->failed_pc=0x0c0c8f02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8f08; }
goto P_0c0c8f04;
P_0c0c8f04: /* original a001, guest PC 0x0c0c8f04 */
if(!s->budget--) { s->failed_pc=0x0c0c8f04u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c8f0a;
P_0c0c8f06: /* original 7e01, guest PC 0x0c0c8f06 */
if(!s->budget--) { s->failed_pc=0x0c0c8f06u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c8f08;
P_0c0c8f08: /* original 7eff, guest PC 0x0c0c8f08 */
if(!s->budget--) { s->failed_pc=0x0c0c8f08u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c8f0a;
P_0c0c8f0a: /* original e043, guest PC 0x0c0c8f0a */
if(!s->budget--) { s->failed_pc=0x0c0c8f0au; return 0; }
r[0]=0x00000043u;
goto P_0c0c8f0c;
P_0c0c8f0c: /* original 0ce4, guest PC 0x0c0c8f0c */
if(!s->budget--) { s->failed_pc=0x0c0c8f0cu; return 0; }
write(ram,r[12]+r[0],r[14],1);
goto P_0c0c8f0e;
P_0c0c8f0e: /* original e307, guest PC 0x0c0c8f0e */
if(!s->budget--) { s->failed_pc=0x0c0c8f0eu; return 0; }
r[3]=0x00000007u;
goto P_0c0c8f10;
P_0c0c8f10: /* original d00e, guest PC 0x0c0c8f10 */
if(!s->budget--) { s->failed_pc=0x0c0c8f10u; return 0; }
r[0]=read(ram,0x0c0c8f4cu,4);
goto P_0c0c8f12;
P_0c0c8f12: /* original e228, guest PC 0x0c0c8f12 */
if(!s->budget--) { s->failed_pc=0x0c0c8f12u; return 0; }
r[2]=0x00000028u;
goto P_0c0c8f14;
P_0c0c8f14: /* original 04ec, guest PC 0x0c0c8f14 */
if(!s->budget--) { s->failed_pc=0x0c0c8f14u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8f16;
P_0c0c8f16: /* original 644c, guest PC 0x0c0c8f16 */
if(!s->budget--) { s->failed_pc=0x0c0c8f16u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c8f18;
P_0c0c8f18: /* original 443c, guest PC 0x0c0c8f18 */
if(!s->budget--) { s->failed_pc=0x0c0c8f18u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0c8f1a;
P_0c0c8f1a: /* original 242b, guest PC 0x0c0c8f1a */
if(!s->budget--) { s->failed_pc=0x0c0c8f1au; return 0; }
r[4]|=r[2];
goto P_0c0c8f1c;
P_0c0c8f1c: /* original 2f42, guest PC 0x0c0c8f1c */
if(!s->budget--) { s->failed_pc=0x0c0c8f1cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c8f1e;
P_0c0c8f1e: /* original d512, guest PC 0x0c0c8f1e */
if(!s->budget--) { s->failed_pc=0x0c0c8f1eu; return 0; }
r[5]=read(ram,0x0c0c8f68u,4);
goto P_0c0c8f20;
P_0c0c8f20: /* original d112, guest PC 0x0c0c8f20 */
if(!s->budget--) { s->failed_pc=0x0c0c8f20u; return 0; }
r[1]=read(ram,0x0c0c8f6cu,4);
goto P_0c0c8f22;
P_0c0c8f22: /* original 410b, guest PC 0x0c0c8f22 */
if(!s->budget--) { s->failed_pc=0x0c0c8f22u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c8f26u;
r[6]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8f26u) { target=s->pc; goto dispatch; }
goto P_0c0c8f26;
P_0c0c8f24: /* original e600, guest PC 0x0c0c8f24 */
if(!s->budget--) { s->failed_pc=0x0c0c8f24u; return 0; }
r[6]=0x00000000u;
goto P_0c0c8f26;
P_0c0c8f26: /* original 7f04, guest PC 0x0c0c8f26 */
if(!s->budget--) { s->failed_pc=0x0c0c8f26u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8f28;
P_0c0c8f28: /* original d311, guest PC 0x0c0c8f28 */
if(!s->budget--) { s->failed_pc=0x0c0c8f28u; return 0; }
r[3]=read(ram,0x0c0c8f70u,4);
goto P_0c0c8f2a;
P_0c0c8f2a: /* original 4f26, guest PC 0x0c0c8f2a */
if(!s->budget--) { s->failed_pc=0x0c0c8f2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8f2c;
P_0c0c8f2c: /* original 6bf6, guest PC 0x0c0c8f2c */
if(!s->budget--) { s->failed_pc=0x0c0c8f2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c8f2e;
P_0c0c8f2e: /* original 6cf6, guest PC 0x0c0c8f2e */
if(!s->budget--) { s->failed_pc=0x0c0c8f2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c8f30;
P_0c0c8f30: /* original 6df6, guest PC 0x0c0c8f30 */
if(!s->budget--) { s->failed_pc=0x0c0c8f30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c8f32;
P_0c0c8f32: /* original 432b, guest PC 0x0c0c8f32 */
if(!s->budget--) { s->failed_pc=0x0c0c8f32u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0c8f34: /* original 6ef6, guest PC 0x0c0c8f34 */
if(!s->budget--) { s->failed_pc=0x0c0c8f34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c8f36u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c020024u,0x0c020026u,0x0c020028u,0x0c02002au,0x0c02002cu,0x0c02002eu,0x0c020030u,0x0c020032u,0x0c020034u,0x0c020036u,0x0c020038u,0x0c02003au,0x0c02003cu,0x0c02003eu,0x0c020040u,0x0c020042u,
0x0c020044u,0x0c020046u,0x0c020048u,0x0c02004au,0x0c02004cu,0x0c02004eu,0x0c020050u,0x0c020052u,0x0c020054u,0x0c020056u,0x0c020058u,0x0c02005au,0x0c02005cu,0x0c02005eu,0x0c020060u,0x0c020062u,
0x0c020064u,0x0c020066u,0x0c020068u,0x0c02006au,0x0c02006cu,0x0c02006eu,0x0c020070u,0x0c020072u,0x0c020074u,0x0c020076u,0x0c020078u,0x0c02007au,0x0c02007cu,0x0c02007eu,0x0c039fd0u,0x0c039fd2u,
0x0c039fd4u,0x0c039fd6u,0x0c039fd8u,0x0c039fdau,0x0c039fdcu,0x0c039fdeu,0x0c039fe0u,0x0c039fe2u,0x0c039fe4u,0x0c039fe6u,0x0c039fe8u,0x0c039feau,0x0c039fecu,0x0c039feeu,0x0c039ff0u,0x0c039ff2u,
0x0c039ff4u,0x0c039ff6u,0x0c039ff8u,0x0c039ffau,0x0c039ffcu,0x0c039ffeu,0x0c03a000u,0x0c03a002u,0x0c03a004u,0x0c03a006u,0x0c03a008u,0x0c03a00au,0x0c03a00cu,0x0c03a00eu,0x0c03a010u,0x0c03a012u,
0x0c03a014u,0x0c03a016u,0x0c03a018u,0x0c03a01au,0x0c03a01cu,0x0c03a01eu,0x0c03a020u,0x0c03a022u,0x0c03a024u,0x0c03a026u,0x0c03a028u,0x0c03a02au,0x0c03a02cu,0x0c03a02eu,0x0c03a030u,0x0c03a032u,
0x0c03a034u,0x0c03a040u,0x0c03a042u,0x0c03a044u,0x0c03a046u,0x0c03a048u,0x0c03a04au,0x0c03a04cu,0x0c03a04eu,0x0c03a050u,0x0c03a052u,0x0c03a054u,0x0c03a07cu,0x0c03a07eu,0x0c03a080u,0x0c03a082u,
0x0c03a084u,0x0c03a086u,0x0c03a088u,0x0c03a08au,0x0c03a08cu,0x0c03a08eu,0x0c03a090u,0x0c03a092u,0x0c03a094u,0x0c03a096u,0x0c03a0a0u,0x0c03a0a2u,0x0c03a0a4u,0x0c03a0a6u,0x0c03a0a8u,0x0c03a0aau,
0x0c03a0b0u,0x0c03a0b2u,0x0c03a0b4u,0x0c03a0b6u,0x0c03a0b8u,0x0c03a0bau,0x0c03a0c0u,0x0c03a0c2u,0x0c03a0c4u,0x0c03a0c6u,0x0c03a0c8u,0x0c03a0d0u,0x0c03a0d2u,0x0c03a0d4u,0x0c03a0d6u,0x0c03a0d8u,
0x0c03a0dau,0x0c03a0dcu,0x0c03a0deu,0x0c03a0e0u,0x0c03a0e2u,0x0c03a0e4u,0x0c03a0e6u,0x0c03a0e8u,0x0c03a0f0u,0x0c03a0f2u,0x0c03a0f4u,0x0c03a0f6u,0x0c03a0f8u,0x0c03a0fau,0x0c03a100u,0x0c03a102u,
0x0c03a104u,0x0c03a106u,0x0c03a108u,0x0c03a10au,0x0c03a10cu,0x0c03a10eu,0x0c03a110u,0x0c03a112u,0x0c0406b2u,0x0c0406b4u,0x0c0406b6u,0x0c0406b8u,0x0c0406bau,0x0c0406bcu,0x0c0406beu,0x0c0406c0u,
0x0c0406c2u,0x0c0406c4u,0x0c0406c6u,0x0c0406c8u,0x0c0406cau,0x0c0406ccu,0x0c0406ceu,0x0c0406d0u,0x0c0406d2u,0x0c0406d4u,0x0c0406d6u,0x0c0406d8u,0x0c0406dau,0x0c0406dcu,0x0c0406deu,0x0c0406e0u,
0x0c0406e2u,0x0c0406e4u,0x0c0406e6u,0x0c0406e8u,0x0c0406eau,0x0c0406ecu,0x0c0406eeu,0x0c0406f0u,0x0c0406f2u,0x0c0406f4u,0x0c0406f6u,0x0c0406f8u,0x0c0406fau,0x0c0406fcu,0x0c0406feu,0x0c040700u,
0x0c040702u,0x0c040704u,0x0c040706u,0x0c040708u,0x0c04070au,0x0c040714u,0x0c040716u,0x0c040718u,0x0c04071au,0x0c04071cu,0x0c04071eu,0x0c040720u,0x0c040722u,0x0c040724u,0x0c040726u,0x0c040728u,
0x0c04072au,0x0c04072cu,0x0c04072eu,0x0c040730u,0x0c040732u,0x0c040734u,0x0c040736u,0x0c040738u,0x0c04073au,0x0c04073cu,0x0c04073eu,0x0c040740u,0x0c040742u,0x0c040744u,0x0c040746u,0x0c040748u,
0x0c04074au,0x0c04074cu,0x0c04074eu,0x0c040750u,0x0c040752u,0x0c040754u,0x0c040756u,0x0c040758u,0x0c04075au,0x0c04075cu,0x0c04075eu,0x0c040760u,0x0c040762u,0x0c040764u,0x0c040766u,0x0c040768u,
0x0c04076au,0x0c04076cu,0x0c04076eu,0x0c040770u,0x0c040772u,0x0c040774u,0x0c040776u,0x0c040778u,0x0c04077au,0x0c04077cu,0x0c04077eu,0x0c040780u,0x0c040782u,0x0c040784u,0x0c040786u,0x0c040788u,
0x0c04078au,0x0c04078cu,0x0c04078eu,0x0c040790u,0x0c040792u,0x0c040794u,0x0c040796u,0x0c040798u,0x0c04079au,0x0c04079cu,0x0c04079eu,0x0c0407b0u,0x0c0407b2u,0x0c0407b4u,0x0c0407b6u,0x0c0407b8u,
0x0c0407bau,0x0c0407bcu,0x0c0407beu,0x0c0407c0u,0x0c0407c2u,0x0c0407c4u,0x0c0407c6u,0x0c0407c8u,0x0c04ceceu,0x0c04ced0u,0x0c04ced2u,0x0c04ced4u,0x0c04ced6u,0x0c04ced8u,0x0c04cedau,0x0c04cedcu,
0x0c04cedeu,0x0c04cee0u,0x0c04cee2u,0x0c04cee4u,0x0c04cee6u,0x0c04cee8u,0x0c04ceeau,0x0c04ceecu,0x0c04ceeeu,0x0c04cef0u,0x0c04cef2u,0x0c04cef4u,0x0c04cef6u,0x0c04cef8u,0x0c04cefau,0x0c04cefcu,
0x0c04cefeu,0x0c04cf00u,0x0c04cf02u,0x0c04cf04u,0x0c04cf06u,0x0c04cf08u,0x0c04cf0au,0x0c04cf0cu,0x0c04ec8eu,0x0c04ec90u,0x0c04ec92u,0x0c04ec94u,0x0c04ec96u,0x0c04ec98u,0x0c04ec9au,0x0c04ec9cu,
0x0c04ec9eu,0x0c04eca0u,0x0c04eca2u,0x0c04eca4u,0x0c04eca6u,0x0c04eca8u,0x0c04ecaau,0x0c04ecacu,0x0c04ecaeu,0x0c04ecb0u,0x0c04ecb2u,0x0c04ecb4u,0x0c04ecb6u,0x0c04ecb8u,0x0c04ecbau,0x0c04ecf0u,
0x0c04ecf2u,0x0c04ecf4u,0x0c04ecf6u,0x0c04ecf8u,0x0c04ecfau,0x0c04ecfcu,0x0c04ecfeu,0x0c04ed00u,0x0c04ed02u,0x0c04ed04u,0x0c04ed06u,0x0c04ed08u,0x0c04ed0au,0x0c04ed0cu,0x0c04ed0eu,0x0c04ed10u,
0x0c04ed12u,0x0c04ed14u,0x0c04ed16u,0x0c04ed18u,0x0c04ed1au,0x0c04ed1cu,0x0c04ed1eu,0x0c04ed20u,0x0c04ed22u,0x0c04ed24u,0x0c04ed26u,0x0c04ed28u,0x0c04ed2au,0x0c04ed2cu,0x0c04ed2eu,0x0c04ed30u,
0x0c04ed32u,0x0c04ed34u,0x0c04ed36u,0x0c04ed38u,0x0c04ed3au,0x0c04ed3cu,0x0c04ed3eu,0x0c04ed40u,0x0c04ed42u,0x0c04ed44u,0x0c04ed46u,0x0c04ed48u,0x0c04ed4au,0x0c04ed4cu,0x0c04ed4eu,0x0c04ed50u,
0x0c04ed52u,0x0c04ed54u,0x0c04ed56u,0x0c04ed58u,0x0c04ed5au,0x0c04ed5cu,0x0c04ed5eu,0x0c04ed60u,0x0c04ed62u,0x0c04ed64u,0x0c04ed66u,0x0c04ed68u,0x0c04ed6au,0x0c04ed6cu,0x0c04ed6eu,0x0c04ed70u,
0x0c04ed72u,0x0c04ed74u,0x0c04ed76u,0x0c04ed78u,0x0c04ed7au,0x0c04ed7cu,0x0c04ed7eu,0x0c04f98eu,0x0c04f990u,0x0c04f992u,0x0c04f994u,0x0c04f996u,0x0c04f998u,0x0c04f99au,0x0c04f99cu,0x0c04f99eu,
0x0c04f9a0u,0x0c04f9a2u,0x0c04f9a4u,0x0c04f9a6u,0x0c04f9a8u,0x0c04f9aau,0x0c04f9acu,0x0c04f9aeu,0x0c04f9b0u,0x0c04f9b2u,0x0c04f9b4u,0x0c04f9b6u,0x0c04f9b8u,0x0c04f9bau,0x0c04f9bcu,0x0c04f9beu,
0x0c04f9c0u,0x0c04f9c2u,0x0c04f9c4u,0x0c04f9c6u,0x0c04f9c8u,0x0c04f9cau,0x0c04f9ccu,0x0c04f9ceu,0x0c04f9d0u,0x0c04f9d2u,0x0c04f9d4u,0x0c04f9d6u,0x0c04f9f0u,0x0c04f9f2u,0x0c04f9f4u,0x0c04f9f6u,
0x0c04f9f8u,0x0c04f9fau,0x0c04f9fcu,0x0c04f9feu,0x0c04fa00u,0x0c04fa02u,0x0c04fa04u,0x0c04fa06u,0x0c04fa08u,0x0c04fa0au,0x0c04fa0cu,0x0c04fa0eu,0x0c04fa10u,0x0c04fa12u,0x0c04fa14u,0x0c04fa16u,
0x0c04fa18u,0x0c04fa1au,0x0c04fa1cu,0x0c04fa1eu,0x0c04fa20u,0x0c04fa22u,0x0c04fa24u,0x0c04fa26u,0x0c04fa28u,0x0c04fa2au,0x0c04fa2cu,0x0c04fa2eu,0x0c04fa30u,0x0c04fa32u,0x0c04fa34u,0x0c04fa36u,
0x0c053ca4u,0x0c053ca6u,0x0c053ca8u,0x0c053caau,0x0c053cacu,0x0c053caeu,0x0c053cb0u,0x0c053cb2u,0x0c053cb4u,0x0c053cb6u,0x0c053cb8u,0x0c053cbau,0x0c053cbcu,0x0c053cbeu,0x0c053cc0u,0x0c053cc2u,
0x0c053cc4u,0x0c053cc6u,0x0c053cc8u,0x0c053ccau,0x0c053cccu,0x0c053cceu,0x0c053cd0u,0x0c053cd2u,0x0c053cd4u,0x0c053cd6u,0x0c053cd8u,0x0c053cdau,0x0c053cdcu,0x0c053cdeu,0x0c053ce0u,0x0c053ce2u,
0x0c05961eu,0x0c059620u,0x0c059622u,0x0c059624u,0x0c059626u,0x0c059628u,0x0c05962au,0x0c05962cu,0x0c05962eu,0x0c059630u,0x0c059632u,0x0c059634u,0x0c059636u,0x0c059638u,0x0c05963au,0x0c05963cu,
0x0c05963eu,0x0c059640u,0x0c059642u,0x0c059644u,0x0c059646u,0x0c059648u,0x0c05964au,0x0c05964cu,0x0c05964eu,0x0c059650u,0x0c059652u,0x0c059654u,0x0c059656u,0x0c059658u,0x0c05965au,0x0c05965cu,
0x0c05965eu,0x0c059660u,0x0c059662u,0x0c059664u,0x0c059666u,0x0c059668u,0x0c05966au,0x0c05966cu,0x0c05966eu,0x0c059670u,0x0c059672u,0x0c059674u,0x0c059676u,0x0c059678u,0x0c05967au,0x0c05967cu,
0x0c05967eu,0x0c059680u,0x0c059682u,0x0c059684u,0x0c0596b4u,0x0c0596b6u,0x0c0596b8u,0x0c0596bau,0x0c0596bcu,0x0c0596beu,0x0c0596c0u,0x0c0596c2u,0x0c0596c4u,0x0c0596c6u,0x0c0596c8u,0x0c0596cau,
0x0c0596ccu,0x0c0596ceu,0x0c0596d0u,0x0c0596d2u,0x0c0596d4u,0x0c0596d6u,0x0c0596d8u,0x0c0596dau,0x0c0596dcu,0x0c0596deu,0x0c0596e0u,0x0c0596e2u,0x0c0596e4u,0x0c0596e6u,0x0c0596e8u,0x0c0596eau,
0x0c0596ecu,0x0c0596eeu,0x0c0596f0u,0x0c0596f2u,0x0c0596f4u,0x0c0596f6u,0x0c0596f8u,0x0c0596fau,0x0c0596fcu,0x0c0596feu,0x0c059700u,0x0c059702u,0x0c059704u,0x0c059706u,0x0c05e86au,0x0c05e86cu,
0x0c05e86eu,0x0c05e870u,0x0c05e872u,0x0c05e874u,0x0c05e876u,0x0c05e878u,0x0c05e87au,0x0c05e87cu,0x0c05e87eu,0x0c05e880u,0x0c05e882u,0x0c05e884u,0x0c05e886u,0x0c05e888u,0x0c05e88au,0x0c05e88cu,
0x0c05e88eu,0x0c05e890u,0x0c05e892u,0x0c05e894u,0x0c05e896u,0x0c05e898u,0x0c05e89au,0x0c05e89cu,0x0c05e89eu,0x0c05e8a0u,0x0c05e8a2u,0x0c05e8a4u,0x0c05e8a6u,0x0c05e8a8u,0x0c05e8aau,0x0c05e8acu,
0x0c05e8aeu,0x0c05e8b0u,0x0c05e8b2u,0x0c05e8b4u,0x0c05e8b6u,0x0c05e8b8u,0x0c05e8bau,0x0c05e8bcu,0x0c05e8beu,0x0c05e8c0u,0x0c05e8c2u,0x0c05e8c4u,0x0c05e8c6u,0x0c05e8c8u,0x0c05e8cau,0x0c05e8ccu,
0x0c05e8ceu,0x0c05e8d0u,0x0c05e8d2u,0x0c05e8d4u,0x0c05e8d6u,0x0c05e8d8u,0x0c05e8dau,0x0c05e8dcu,0x0c05e8deu,0x0c05e8e0u,0x0c05e8e2u,0x0c05e8e4u,0x0c05e8e6u,0x0c05e8e8u,0x0c05e8eau,0x0c05e8ecu,
0x0c05e8eeu,0x0c05e8f0u,0x0c05e8f2u,0x0c05e8f4u,0x0c05e8f6u,0x0c05e8f8u,0x0c05e8fau,0x0c05e8fcu,0x0c05e8feu,0x0c05e900u,0x0c05e902u,0x0c05e904u,0x0c05e906u,0x0c05e908u,0x0c05e90au,0x0c05e90cu,
0x0c05e90eu,0x0c05e910u,0x0c05e912u,0x0c05e914u,0x0c05e916u,0x0c05e918u,0x0c05e91au,0x0c05e91cu,0x0c05e91eu,0x0c05e920u,0x0c05e922u,0x0c05e924u,0x0c05e926u,0x0c05e928u,0x0c05e92au,0x0c05e92cu,
0x0c05e92eu,0x0c05e930u,0x0c05e932u,0x0c05e934u,0x0c05e936u,0x0c05e938u,0x0c05e93au,0x0c05e93cu,0x0c05e93eu,0x0c05e940u,0x0c05e942u,0x0c05e944u,0x0c05e946u,0x0c05e948u,0x0c05e94au,0x0c05e94cu,
0x0c05ee64u,0x0c05ee66u,0x0c05ee68u,0x0c05ee6au,0x0c05ee6cu,0x0c05ee6eu,0x0c05ee70u,0x0c05ee72u,0x0c05ee74u,0x0c05ee76u,0x0c05ee78u,0x0c05ee7au,0x0c05ee7cu,0x0c05ee7eu,0x0c05ee80u,0x0c05ee82u,
0x0c05ee84u,0x0c05ee86u,0x0c05ee88u,0x0c05ee8au,0x0c05ee8cu,0x0c05ee8eu,0x0c05ee90u,0x0c05ee92u,0x0c05ee94u,0x0c05ee96u,0x0c05ee98u,0x0c05ee9au,0x0c05ee9cu,0x0c05ee9eu,0x0c05eea0u,0x0c05eea2u,
0x0c05eea4u,0x0c05eea6u,0x0c05eea8u,0x0c05eeaau,0x0c05eeacu,0x0c05eeaeu,0x0c05eeb0u,0x0c05eeb2u,0x0c05eeb4u,0x0c05eeb6u,0x0c05eeb8u,0x0c05eebau,0x0c05eebcu,0x0c05eebeu,0x0c05eec0u,0x0c05eec2u,
0x0c05eec4u,0x0c05eec6u,0x0c05eec8u,0x0c05eecau,0x0c05eeccu,0x0c05eeceu,0x0c05eed0u,0x0c05eed2u,0x0c05eed4u,0x0c05eed6u,0x0c05eed8u,0x0c05eedau,0x0c05eedcu,0x0c05eedeu,0x0c05eee0u,0x0c05eee2u,
0x0c05eee4u,0x0c05eee6u,0x0c05eee8u,0x0c05eeeau,0x0c05eeecu,0x0c05eeeeu,0x0c05eef0u,0x0c05eef2u,0x0c05eef4u,0x0c05eef6u,0x0c05eef8u,0x0c05eefau,0x0c05eefcu,0x0c05eefeu,0x0c05ef00u,0x0c05ef02u,
0x0c05ef04u,0x0c05ef06u,0x0c05ef08u,0x0c05ef0au,0x0c05ef0cu,0x0c05ef0eu,0x0c05ef10u,0x0c05ef40u,0x0c05ef42u,0x0c05ef44u,0x0c05ef46u,0x0c05ef48u,0x0c05ef4au,0x0c05ef4cu,0x0c05ef4eu,0x0c05ef50u,
0x0c05ef52u,0x0c05ef54u,0x0c05ef56u,0x0c05ef58u,0x0c05ef5au,0x0c05ef5cu,0x0c05ef5eu,0x0c05ef60u,0x0c05ef62u,0x0c05ef64u,0x0c05ef66u,0x0c05ef68u,0x0c05ef6au,0x0c05ef6cu,0x0c05ef6eu,0x0c05ef70u,
0x0c05ef72u,0x0c05ef74u,0x0c05ef76u,0x0c05ef78u,0x0c05ef7au,0x0c05ef7cu,0x0c05ef7eu,0x0c05ef80u,0x0c05ef82u,0x0c05ef84u,0x0c05ef86u,0x0c05ef88u,0x0c05ef8au,0x0c05ef8cu,0x0c05ef8eu,0x0c05ef90u,
0x0c05ef92u,0x0c05ef94u,0x0c05ef96u,0x0c05ef98u,0x0c05ef9au,0x0c05ef9cu,0x0c05ef9eu,0x0c05efa0u,0x0c05efa2u,0x0c05efa4u,0x0c05efa6u,0x0c05efa8u,0x0c05efaau,0x0c05efacu,0x0c05efaeu,0x0c05efb0u,
0x0c05efb2u,0x0c05efb4u,0x0c05efb6u,0x0c05efb8u,0x0c05efbau,0x0c05efbcu,0x0c05efbeu,0x0c05efc0u,0x0c05efc2u,0x0c05efc4u,0x0c05efc6u,0x0c05efc8u,0x0c05efcau,0x0c05efccu,0x0c05efceu,0x0c05efd0u,
0x0c05efd2u,0x0c05efd4u,0x0c05efd6u,0x0c05efd8u,0x0c05efdau,0x0c05efdcu,0x0c05efdeu,0x0c05efe0u,0x0c05efe2u,0x0c05efe4u,0x0c05efe6u,0x0c05efe8u,0x0c05efeau,0x0c05efecu,0x0c05efeeu,0x0c05eff0u,
0x0c05eff2u,0x0c05eff4u,0x0c05eff6u,0x0c05eff8u,0x0c05effau,0x0c05f018u,0x0c05f01au,0x0c05f01cu,0x0c05f01eu,0x0c05f020u,0x0c05f022u,0x0c05f024u,0x0c05f026u,0x0c05f028u,0x0c05f02au,0x0c05f02cu,
0x0c05f02eu,0x0c05f030u,0x0c05f032u,0x0c05f034u,0x0c05f036u,0x0c05f038u,0x0c05f03au,0x0c05f03cu,0x0c05f03eu,0x0c05f040u,0x0c05f042u,0x0c05f044u,0x0c05f046u,0x0c05f048u,0x0c05f04au,0x0c05f04cu,
0x0c05f04eu,0x0c05f050u,0x0c05f052u,0x0c05f054u,0x0c05f056u,0x0c05f058u,0x0c05f05au,0x0c05f05cu,0x0c05f05eu,0x0c05f060u,0x0c05f062u,0x0c05f064u,0x0c05f066u,0x0c05f068u,0x0c05f06au,0x0c05f06cu,
0x0c05f06eu,0x0c05f070u,0x0c05f072u,0x0c05f074u,0x0c05f076u,0x0c05f078u,0x0c05f07au,0x0c05f07cu,0x0c05f07eu,0x0c05f080u,0x0c05f082u,0x0c05f084u,0x0c05f086u,0x0c05f088u,0x0c05f08au,0x0c05f08cu,
0x0c05f08eu,0x0c05f090u,0x0c05f092u,0x0c05f094u,0x0c05f096u,0x0c05f098u,0x0c05f09au,0x0c05f09cu,0x0c060d46u,0x0c060d48u,0x0c060d4au,0x0c0644bcu,0x0c0644beu,0x0c0644c0u,0x0c0644c2u,0x0c0644c4u,
0x0c0644c6u,0x0c0644c8u,0x0c0644cau,0x0c0644ccu,0x0c0644ceu,0x0c0644d0u,0x0c0644d2u,0x0c0644d4u,0x0c06ac7au,0x0c06ac7cu,0x0c06ac7eu,0x0c06ac80u,0x0c06ac82u,0x0c06ac84u,0x0c06ac86u,0x0c06ac88u,
0x0c06ac8au,0x0c06ac8cu,0x0c06ac8eu,0x0c06ac90u,0x0c06ac92u,0x0c06ac94u,0x0c06ac96u,0x0c06ac98u,0x0c06ac9au,0x0c06ac9cu,0x0c06ac9eu,0x0c06aca0u,0x0c06aca2u,0x0c06aca4u,0x0c06aca6u,0x0c06aca8u,
0x0c06acaau,0x0c06acacu,0x0c06acaeu,0x0c06acb0u,0x0c06acb2u,0x0c06acb4u,0x0c06acb6u,0x0c06acb8u,0x0c06acbau,0x0c06acbcu,0x0c06acbeu,0x0c06acc0u,0x0c06acc2u,0x0c06acc4u,0x0c06acc6u,0x0c06acc8u,
0x0c06accau,0x0c06acccu,0x0c06acceu,0x0c06acd0u,0x0c06acd2u,0x0c06acd4u,0x0c06acd6u,0x0c06acd8u,0x0c06acdau,0x0c06acdcu,0x0c06acdeu,0x0c06ace0u,0x0c06ace2u,0x0c06ace4u,0x0c06ace6u,0x0c06ace8u,
0x0c06aceau,0x0c06acecu,0x0c06aceeu,0x0c06acf0u,0x0c06acf2u,0x0c06acf4u,0x0c06acf6u,0x0c06acf8u,0x0c06acfau,0x0c06acfcu,0x0c06acfeu,0x0c06ad00u,0x0c06ad02u,0x0c06ad04u,0x0c06ad06u,0x0c06ad08u,
0x0c06ad0au,0x0c06ad0cu,0x0c06ad0eu,0x0c06ad10u,0x0c06ad12u,0x0c06ad14u,0x0c06ad16u,0x0c06ad18u,0x0c06ad1au,0x0c07b75au,0x0c07b75cu,0x0c07b75eu,0x0c07b760u,0x0c07b762u,0x0c07b764u,0x0c07b766u,
0x0c07b768u,0x0c07b76au,0x0c07b76cu,0x0c07b76eu,0x0c07b770u,0x0c07b772u,0x0c07b774u,0x0c07b784u,0x0c07b786u,0x0c07b788u,0x0c07b78au,0x0c07b78cu,0x0c07b78eu,0x0c07b790u,0x0c07b792u,0x0c07b794u,
0x0c07b796u,0x0c07b798u,0x0c07b79au,0x0c07b79cu,0x0c07b79eu,0x0c07b7a0u,0x0c07b7a2u,0x0c07b7a4u,0x0c07b7a6u,0x0c07b7a8u,0x0c07b7aau,0x0c07b7acu,0x0c07b7aeu,0x0c07b7b0u,0x0c07b7b2u,0x0c07b7b4u,
0x0c07b7b6u,0x0c07b7b8u,0x0c07b7bau,0x0c07b7bcu,0x0c07b7beu,0x0c07b7c0u,0x0c07b7c2u,0x0c07b7c4u,0x0c07b7c6u,0x0c07b7c8u,0x0c07b7cau,0x0c07b7ccu,0x0c07b7ceu,0x0c07b7d0u,0x0c07b7d2u,0x0c07b7d4u,
0x0c07b7d6u,0x0c07b7d8u,0x0c07b7dau,0x0c07b7dcu,0x0c07b7deu,0x0c07b7e0u,0x0c07b7e2u,0x0c07b7e4u,0x0c07b7e6u,0x0c07b7e8u,0x0c07b7eau,0x0c07b7ecu,0x0c07b7eeu,0x0c07b7f0u,0x0c07b7f2u,0x0c07b7f4u,
0x0c07b7f6u,0x0c07b7f8u,0x0c07b7fau,0x0c07b7fcu,0x0c07b7feu,0x0c07b800u,0x0c07b802u,0x0c07b804u,0x0c07b806u,0x0c07b808u,0x0c07b80au,0x0c07b80cu,0x0c07b80eu,0x0c07b810u,0x0c07b812u,0x0c07b814u,
0x0c07b816u,0x0c07b818u,0x0c07b81au,0x0c07b81cu,0x0c07b81eu,0x0c07b820u,0x0c07b822u,0x0c07b824u,0x0c07b826u,0x0c07b828u,0x0c07b82au,0x0c07b82cu,0x0c07b82eu,0x0c07b830u,0x0c07b832u,0x0c07b834u,
0x0c07b836u,0x0c07b838u,0x0c07b83au,0x0c07b83cu,0x0c07b83eu,0x0c082e0eu,0x0c082e10u,0x0c082e12u,0x0c082e14u,0x0c082e16u,0x0c082e18u,0x0c082e1au,0x0c082e1cu,0x0c082e1eu,0x0c082e20u,0x0c082e22u,
0x0c082e24u,0x0c082e26u,0x0c082e28u,0x0c082e2au,0x0c082e2cu,0x0c082e2eu,0x0c082e30u,0x0c082e32u,0x0c082e34u,0x0c082e36u,0x0c082e38u,0x0c082e3au,0x0c082e3cu,0x0c082e3eu,0x0c082e40u,0x0c082e42u,
0x0c082e44u,0x0c082e46u,0x0c082e48u,0x0c082e4au,0x0c082e4cu,0x0c082e4eu,0x0c082e50u,0x0c082e52u,0x0c082e54u,0x0c082e56u,0x0c082e58u,0x0c082e5au,0x0c082e5cu,0x0c082e5eu,0x0c082e60u,0x0c082e62u,
0x0c082e64u,0x0c082e66u,0x0c082ee4u,0x0c082ee6u,0x0c082ee8u,0x0c082eeau,0x0c082eecu,0x0c082eeeu,0x0c082ef0u,0x0c082ef2u,0x0c082ef4u,0x0c082ef6u,0x0c082ef8u,0x0c082efau,0x0c082efcu,0x0c082efeu,
0x0c082f00u,0x0c082f02u,0x0c082f04u,0x0c082f06u,0x0c082f08u,0x0c082f0au,0x0c082f0cu,0x0c0831b4u,0x0c0831b6u,0x0c0831b8u,0x0c0831bau,0x0c0831bcu,0x0c0831beu,0x0c0831c0u,0x0c0831c2u,0x0c0831c4u,
0x0c0831c6u,0x0c0831c8u,0x0c0831cau,0x0c0831ccu,0x0c0831ceu,0x0c0831d0u,0x0c0831d2u,0x0c0831d4u,0x0c0831d6u,0x0c0831d8u,0x0c0831dau,0x0c0831dcu,0x0c0831deu,0x0c0831e0u,0x0c0831e2u,0x0c0831e4u,
0x0c0831e6u,0x0c0831e8u,0x0c086b20u,0x0c086b22u,0x0c086b24u,0x0c086b26u,0x0c086b28u,0x0c086b2au,0x0c086b2cu,0x0c086b2eu,0x0c086b30u,0x0c086b32u,0x0c086b34u,0x0c086b36u,0x0c086b38u,0x0c086b3au,
0x0c086b3cu,0x0c086b3eu,0x0c086b40u,0x0c086b42u,0x0c086b44u,0x0c086b46u,0x0c086b48u,0x0c086b4au,0x0c086b4cu,0x0c086b4eu,0x0c086b50u,0x0c086b52u,0x0c086b54u,0x0c086b56u,0x0c086b58u,0x0c086b5au,
0x0c086b5cu,0x0c086b5eu,0x0c086b60u,0x0c086b62u,0x0c086b64u,0x0c086b66u,0x0c086b68u,0x0c086b6au,0x0c086b6cu,0x0c086b6eu,0x0c086b70u,0x0c086b72u,0x0c086b74u,0x0c086b76u,0x0c086b78u,0x0c086b7au,
0x0c086b7cu,0x0c086b7eu,0x0c086b80u,0x0c086b9cu,0x0c086b9eu,0x0c086ba0u,0x0c086ba2u,0x0c086ba4u,0x0c086ba6u,0x0c086ba8u,0x0c086baau,0x0c086bacu,0x0c086baeu,0x0c086bb0u,0x0c086bb2u,0x0c086bb4u,
0x0c086bb6u,0x0c086bb8u,0x0c086bbau,0x0c086bbcu,0x0c086bbeu,0x0c086bc0u,0x0c086bc2u,0x0c086bc4u,0x0c086bc6u,0x0c086bc8u,0x0c086bcau,0x0c086bccu,0x0c086bceu,0x0c086bd0u,0x0c086bd2u,0x0c086bd4u,
0x0c086bd6u,0x0c086bd8u,0x0c086bdau,0x0c086bdcu,0x0c086bdeu,0x0c086be0u,0x0c086be2u,0x0c086be4u,0x0c086be6u,0x0c086be8u,0x0c086beau,0x0c086becu,0x0c086beeu,0x0c086bf0u,0x0c086bf2u,0x0c086bf4u,
0x0c086bf6u,0x0c086bf8u,0x0c086bfau,0x0c086bfcu,0x0c086bfeu,0x0c086c00u,0x0c086c02u,0x0c086c04u,0x0c086c06u,0x0c086c08u,0x0c086c0au,0x0c086c0cu,0x0c086c0eu,0x0c086c10u,0x0c086c12u,0x0c086c14u,
0x0c086c16u,0x0c086c18u,0x0c086c1au,0x0c086c1cu,0x0c086c1eu,0x0c086c20u,0x0c086c22u,0x0c086c24u,0x0c086c26u,0x0c086c28u,0x0c086c2au,0x0c086c2cu,0x0c086c2eu,0x0c086c30u,0x0c086c32u,0x0c086c34u,
0x0c086c36u,0x0c086c38u,0x0c086c3au,0x0c086c3cu,0x0c086c3eu,0x0c086c40u,0x0c086c42u,0x0c086c44u,0x0c086c46u,0x0c086c48u,0x0c086c4au,0x0c086c4cu,0x0c086c4eu,0x0c086c50u,0x0c086c52u,0x0c086c54u,
0x0c086c56u,0x0c086c58u,0x0c086c5au,0x0c086c5cu,0x0c086c5eu,0x0c086c60u,0x0c086c62u,0x0c086c64u,0x0c086c66u,0x0c086c68u,0x0c086c6au,0x0c086c6cu,0x0c086c6eu,0x0c086c70u,0x0c086c72u,0x0c086c74u,
0x0c086c76u,0x0c086c78u,0x0c086c7au,0x0c086c7cu,0x0c086c7eu,0x0c086c80u,0x0c086c82u,0x0c086c84u,0x0c086c86u,0x0c086c88u,0x0c086c8au,0x0c086c8cu,0x0c086c8eu,0x0c086c90u,0x0c086c92u,0x0c086c94u,
0x0c086c96u,0x0c086c98u,0x0c086c9au,0x0c086c9cu,0x0c086c9eu,0x0c086ca0u,0x0c086ca2u,0x0c086ca4u,0x0c086ca6u,0x0c086ca8u,0x0c086caau,0x0c086cacu,0x0c086caeu,0x0c086cb0u,0x0c086cb2u,0x0c086cb4u,
0x0c086cb6u,0x0c086cb8u,0x0c086cbau,0x0c086cbcu,0x0c086cbeu,0x0c086cc0u,0x0c086cc2u,0x0c086cc4u,0x0c086cc6u,0x0c086cc8u,0x0c086ccau,0x0c086cccu,0x0c086cceu,0x0c086cd0u,0x0c086cd2u,0x0c086cfcu,
0x0c086cfeu,0x0c086d00u,0x0c086d02u,0x0c086d04u,0x0c086d06u,0x0c086d08u,0x0c086d0au,0x0c086d0cu,0x0c086d0eu,0x0c086d10u,0x0c086d12u,0x0c086d14u,0x0c086d16u,0x0c086d18u,0x0c086d1au,0x0c086d1cu,
0x0c086d1eu,0x0c086d20u,0x0c086d22u,0x0c086d24u,0x0c086d26u,0x0c086d28u,0x0c086d2au,0x0c086d2cu,0x0c086d2eu,0x0c086d30u,0x0c086d32u,0x0c086d34u,0x0c086d36u,0x0c086d38u,0x0c086d3au,0x0c086d3cu,
0x0c086d3eu,0x0c086d40u,0x0c086d42u,0x0c086d44u,0x0c086d46u,0x0c086d48u,0x0c086d4au,0x0c086d4cu,0x0c086d4eu,0x0c086d50u,0x0c086d52u,0x0c086d54u,0x0c086d56u,0x0c086d58u,0x0c086d5au,0x0c086d5cu,
0x0c086d5eu,0x0c086d60u,0x0c086d62u,0x0c086d64u,0x0c086d66u,0x0c086d68u,0x0c086d6au,0x0c086d6cu,0x0c086d6eu,0x0c086d70u,0x0c086d72u,0x0c086d74u,0x0c086d76u,0x0c086d78u,0x0c086d7au,0x0c086d7cu,
0x0c086d7eu,0x0c086d80u,0x0c086d82u,0x0c086d84u,0x0c086d86u,0x0c086d88u,0x0c086d8au,0x0c086d8cu,0x0c086d8eu,0x0c086d90u,0x0c086d92u,0x0c086d94u,0x0c086d96u,0x0c086d98u,0x0c086d9au,0x0c086d9cu,
0x0c086d9eu,0x0c086da0u,0x0c086da2u,0x0c086da4u,0x0c086da6u,0x0c086da8u,0x0c086daau,0x0c086dacu,0x0c086daeu,0x0c086db0u,0x0c086db2u,0x0c086db4u,0x0c086db6u,0x0c086db8u,0x0c086dbau,0x0c086dbcu,
0x0c086dbeu,0x0c086dc0u,0x0c086dc2u,0x0c086dc4u,0x0c086dc6u,0x0c086dc8u,0x0c086dcau,0x0c086dccu,0x0c086dceu,0x0c086dd0u,0x0c086dd2u,0x0c086dd4u,0x0c086dd6u,0x0c086dd8u,0x0c086ddau,0x0c086ddcu,
0x0c086ddeu,0x0c086de0u,0x0c086de2u,0x0c086de4u,0x0c086de6u,0x0c086de8u,0x0c086deau,0x0c086decu,0x0c086deeu,0x0c086df0u,0x0c086df2u,0x0c086df4u,0x0c086df6u,0x0c086df8u,0x0c086dfau,0x0c086dfcu,
0x0c086dfeu,0x0c086e00u,0x0c086e02u,0x0c086e04u,0x0c086e06u,0x0c086e08u,0x0c086e0au,0x0c086e0cu,0x0c086e0eu,0x0c086e10u,0x0c086e12u,0x0c086e14u,0x0c086e16u,0x0c086e18u,0x0c086e1au,0x0c086e1cu,
0x0c086e1eu,0x0c086e20u,0x0c086e22u,0x0c086e24u,0x0c086e4cu,0x0c086e4eu,0x0c086e50u,0x0c086e52u,0x0c086e54u,0x0c086e56u,0x0c086e58u,0x0c086e5au,0x0c086e5cu,0x0c086e5eu,0x0c086e60u,0x0c086e62u,
0x0c086e64u,0x0c086e66u,0x0c086e68u,0x0c086e6au,0x0c086e6cu,0x0c086e6eu,0x0c086e70u,0x0c086e72u,0x0c086e74u,0x0c086e76u,0x0c086e78u,0x0c086e7au,0x0c086e7cu,0x0c086e7eu,0x0c086e80u,0x0c086e82u,
0x0c086e84u,0x0c086e86u,0x0c086e88u,0x0c086e8au,0x0c086e8cu,0x0c086e8eu,0x0c086e90u,0x0c086e92u,0x0c086e94u,0x0c086e96u,0x0c086e98u,0x0c086e9au,0x0c086e9cu,0x0c086e9eu,0x0c086ea0u,0x0c086ea2u,
0x0c086ea4u,0x0c086ea6u,0x0c086ea8u,0x0c086eaau,0x0c086eacu,0x0c086eaeu,0x0c086eb0u,0x0c086eb2u,0x0c086eb4u,0x0c086eb6u,0x0c086eb8u,0x0c086ebau,0x0c086ebcu,0x0c086ebeu,0x0c086ec0u,0x0c086ec2u,
0x0c086ec4u,0x0c086ec6u,0x0c086ec8u,0x0c086ecau,0x0c086eccu,0x0c086eceu,0x0c086ed0u,0x0c086ed2u,0x0c086ed4u,0x0c086ed6u,0x0c086ed8u,0x0c086edau,0x0c086edcu,0x0c086edeu,0x0c086ee0u,0x0c086ee2u,
0x0c086ee4u,0x0c086ee6u,0x0c086ee8u,0x0c086eeau,0x0c086eecu,0x0c086eeeu,0x0c086ef0u,0x0c086ef2u,0x0c086ef4u,0x0c086ef6u,0x0c086ef8u,0x0c086efau,0x0c086efcu,0x0c086efeu,0x0c086f00u,0x0c086f02u,
0x0c086f04u,0x0c086f06u,0x0c086f08u,0x0c086f0au,0x0c086f0cu,0x0c086f0eu,0x0c086f10u,0x0c086f12u,0x0c086f14u,0x0c086f16u,0x0c086f18u,0x0c086f1au,0x0c086f1cu,0x0c086f1eu,0x0c086f20u,0x0c086f22u,
0x0c086f24u,0x0c086f26u,0x0c086f28u,0x0c086f2au,0x0c086f2cu,0x0c086f2eu,0x0c086f30u,0x0c086f32u,0x0c086f34u,0x0c086f36u,0x0c086f38u,0x0c086f3au,0x0c086f3cu,0x0c086f3eu,0x0c086f40u,0x0c086f42u,
0x0c086f44u,0x0c086f46u,0x0c086f48u,0x0c086f4au,0x0c086f4cu,0x0c086f4eu,0x0c086f50u,0x0c086f52u,0x0c086f54u,0x0c086f56u,0x0c086f58u,0x0c086f5au,0x0c086f5cu,0x0c086f5eu,0x0c086f60u,0x0c086f62u,
0x0c086f64u,0x0c086f66u,0x0c086f68u,0x0c086f6au,0x0c086f80u,0x0c086f82u,0x0c086f84u,0x0c086f86u,0x0c086f88u,0x0c086f8au,0x0c086f8cu,0x0c086f8eu,0x0c086f90u,0x0c086f92u,0x0c086f94u,0x0c086f96u,
0x0c086f98u,0x0c086f9au,0x0c086f9cu,0x0c086f9eu,0x0c086fa0u,0x0c086fa2u,0x0c086fa4u,0x0c086fa6u,0x0c086fa8u,0x0c086faau,0x0c086facu,0x0c086faeu,0x0c086fb0u,0x0c086fb2u,0x0c086fb4u,0x0c086fb6u,
0x0c086fb8u,0x0c086fbau,0x0c086fbcu,0x0c086fbeu,0x0c086fc0u,0x0c086fc2u,0x0c086fc4u,0x0c086fc6u,0x0c086fc8u,0x0c086fcau,0x0c086fccu,0x0c086fceu,0x0c086fd0u,0x0c086fd2u,0x0c086fd4u,0x0c086fd6u,
0x0c086fd8u,0x0c086fdau,0x0c086fdcu,0x0c086fdeu,0x0c086fe0u,0x0c086fe2u,0x0c086fe4u,0x0c086fe6u,0x0c086fe8u,0x0c086feau,0x0c086fecu,0x0c086feeu,0x0c086ff0u,0x0c086ff2u,0x0c086ff4u,0x0c086ff6u,
0x0c086ff8u,0x0c086ffau,0x0c086ffcu,0x0c086ffeu,0x0c087000u,0x0c087002u,0x0c087004u,0x0c087006u,0x0c087008u,0x0c08700au,0x0c08700cu,0x0c08700eu,0x0c087010u,0x0c087012u,0x0c087014u,0x0c087016u,
0x0c087018u,0x0c08701au,0x0c08701cu,0x0c08701eu,0x0c087020u,0x0c087022u,0x0c087024u,0x0c087026u,0x0c087028u,0x0c08702au,0x0c08702cu,0x0c08702eu,0x0c087030u,0x0c087032u,0x0c087034u,0x0c087036u,
0x0c087038u,0x0c08703au,0x0c08703cu,0x0c08703eu,0x0c087040u,0x0c087042u,0x0c087044u,0x0c087046u,0x0c087048u,0x0c08704au,0x0c08704cu,0x0c08704eu,0x0c087050u,0x0c087052u,0x0c087054u,0x0c087056u,
0x0c087058u,0x0c08705au,0x0c08705cu,0x0c08705eu,0x0c087060u,0x0c087062u,0x0c087064u,0x0c087066u,0x0c087068u,0x0c08706au,0x0c08706cu,0x0c08706eu,0x0c087070u,0x0c087072u,0x0c087074u,0x0c087076u,
0x0c087078u,0x0c08707au,0x0c0871eeu,0x0c0871f0u,0x0c0871f2u,0x0c0871f4u,0x0c0871f6u,0x0c0871f8u,0x0c0871fau,0x0c0871fcu,0x0c0871feu,0x0c087200u,0x0c087202u,0x0c087204u,0x0c087206u,0x0c087208u,
0x0c08720au,0x0c08720cu,0x0c08720eu,0x0c087210u,0x0c087212u,0x0c087214u,0x0c087216u,0x0c087218u,0x0c08721au,0x0c08721cu,0x0c08721eu,0x0c087220u,0x0c087222u,0x0c087224u,0x0c087226u,0x0c087228u,
0x0c08722au,0x0c08722cu,0x0c08722eu,0x0c087230u,0x0c087232u,0x0c087234u,0x0c087236u,0x0c087238u,0x0c08723au,0x0c08723cu,0x0c08723eu,0x0c087240u,0x0c087242u,0x0c087244u,0x0c087246u,0x0c087248u,
0x0c08724au,0x0c08724cu,0x0c08724eu,0x0c087250u,0x0c087252u,0x0c087254u,0x0c087256u,0x0c087258u,0x0c08725au,0x0c08725cu,0x0c08725eu,0x0c087260u,0x0c087262u,0x0c087264u,0x0c087266u,0x0c087268u,
0x0c08726au,0x0c08726cu,0x0c08726eu,0x0c087270u,0x0c087272u,0x0c087274u,0x0c087276u,0x0c087278u,0x0c08727au,0x0c08727cu,0x0c0872b4u,0x0c0872b6u,0x0c0872b8u,0x0c0872bau,0x0c0872bcu,0x0c0872beu,
0x0c0872c0u,0x0c0872c2u,0x0c0872c4u,0x0c0872c6u,0x0c0872c8u,0x0c0872cau,0x0c0872ccu,0x0c0872ceu,0x0c0872d0u,0x0c0872d2u,0x0c0872d4u,0x0c0872d6u,0x0c0872d8u,0x0c0872dau,0x0c0872dcu,0x0c0872deu,
0x0c0872e0u,0x0c0872e2u,0x0c0872e4u,0x0c0872e6u,0x0c0872e8u,0x0c0872eau,0x0c0872ecu,0x0c0872eeu,0x0c0872f0u,0x0c0872f2u,0x0c0872f4u,0x0c0872f6u,0x0c0872f8u,0x0c0872fau,0x0c0872fcu,0x0c0872feu,
0x0c087300u,0x0c087302u,0x0c087304u,0x0c087306u,0x0c087308u,0x0c08730au,0x0c08730cu,0x0c08730eu,0x0c087310u,0x0c087312u,0x0c087314u,0x0c087316u,0x0c087318u,0x0c08731au,0x0c08731cu,0x0c08731eu,
0x0c087320u,0x0c087322u,0x0c087324u,0x0c087326u,0x0c087328u,0x0c08732au,0x0c08732cu,0x0c08732eu,0x0c087330u,0x0c087332u,0x0c087334u,0x0c087336u,0x0c087338u,0x0c08733au,0x0c08733cu,0x0c08733eu,
0x0c087340u,0x0c087342u,0x0c087344u,0x0c087346u,0x0c087348u,0x0c0881dcu,0x0c0881deu,0x0c0881e0u,0x0c0881e2u,0x0c0881e4u,0x0c0881e6u,0x0c0881e8u,0x0c0881eau,0x0c0881ecu,0x0c0881eeu,0x0c0881f0u,
0x0c0881f2u,0x0c0881f4u,0x0c0881f6u,0x0c0881f8u,0x0c0884d0u,0x0c0884d2u,0x0c0884d4u,0x0c0884d6u,0x0c0884d8u,0x0c0884dau,0x0c0884dcu,0x0c0884deu,0x0c0884e0u,0x0c0884e2u,0x0c0884e4u,0x0c0884e6u,
0x0c0884e8u,0x0c0884eau,0x0c0884ecu,0x0c0884eeu,0x0c0884f0u,0x0c0884f2u,0x0c0884f4u,0x0c0884f6u,0x0c0884f8u,0x0c0884fau,0x0c0884fcu,0x0c0884feu,0x0c088500u,0x0c088502u,0x0c088504u,0x0c088506u,
0x0c088508u,0x0c08850au,0x0c08850cu,0x0c08850eu,0x0c088510u,0x0c088512u,0x0c088514u,0x0c088516u,0x0c088518u,0x0c08851au,0x0c08851cu,0x0c08851eu,0x0c088520u,0x0c088522u,0x0c088524u,0x0c088526u,
0x0c088528u,0x0c08852au,0x0c08852cu,0x0c08852eu,0x0c088530u,0x0c088532u,0x0c088534u,0x0c088536u,0x0c088538u,0x0c08853au,0x0c08853cu,0x0c08853eu,0x0c088540u,0x0c088542u,0x0c088544u,0x0c088546u,
0x0c088548u,0x0c08854au,0x0c08854cu,0x0c08854eu,0x0c088550u,0x0c088552u,0x0c088554u,0x0c088556u,0x0c088558u,0x0c08855au,0x0c08855cu,0x0c08855eu,0x0c088560u,0x0c088562u,0x0c088564u,0x0c088566u,
0x0c088568u,0x0c08856au,0x0c08856cu,0x0c08856eu,0x0c088570u,0x0c088572u,0x0c088574u,0x0c088576u,0x0c088578u,0x0c08857au,0x0c08857cu,0x0c08857eu,0x0c088580u,0x0c088582u,0x0c088584u,0x0c088586u,
0x0c088588u,0x0c08858au,0x0c08858cu,0x0c08858eu,0x0c088590u,0x0c088592u,0x0c088594u,0x0c088596u,0x0c088598u,0x0c08859au,0x0c08859cu,0x0c08859eu,0x0c0885a0u,0x0c0885a2u,0x0c0885a4u,0x0c0885a6u,
0x0c0885c4u,0x0c0885c6u,0x0c0885c8u,0x0c0885cau,0x0c0885ccu,0x0c0885ceu,0x0c0885d0u,0x0c0885d2u,0x0c0885d4u,0x0c0885d6u,0x0c0885d8u,0x0c0885dau,0x0c0885dcu,0x0c0885deu,0x0c0885e0u,0x0c0885e2u,
0x0c0885e4u,0x0c0885e6u,0x0c0885e8u,0x0c0885eau,0x0c0885ecu,0x0c0885eeu,0x0c0885f0u,0x0c0885f2u,0x0c0885f4u,0x0c0885f6u,0x0c0885f8u,0x0c0885fau,0x0c0885fcu,0x0c0885feu,0x0c088600u,0x0c088602u,
0x0c088604u,0x0c088606u,0x0c088608u,0x0c08860au,0x0c08860cu,0x0c08860eu,0x0c088610u,0x0c088612u,0x0c088614u,0x0c088616u,0x0c088618u,0x0c08861au,0x0c08861cu,0x0c08861eu,0x0c088620u,0x0c088622u,
0x0c088624u,0x0c088626u,0x0c088628u,0x0c08862au,0x0c08862cu,0x0c08862eu,0x0c088630u,0x0c088632u,0x0c088634u,0x0c088636u,0x0c088638u,0x0c08863au,0x0c08863cu,0x0c08863eu,0x0c088640u,0x0c088642u,
0x0c088644u,0x0c088646u,0x0c088648u,0x0c08864au,0x0c08864cu,0x0c08864eu,0x0c088650u,0x0c088652u,0x0c088654u,0x0c088656u,0x0c088658u,0x0c08865au,0x0c08865cu,0x0c08865eu,0x0c088660u,0x0c088662u,
0x0c088664u,0x0c088666u,0x0c088668u,0x0c08866au,0x0c08866cu,0x0c08866eu,0x0c088670u,0x0c088672u,0x0c088674u,0x0c088676u,0x0c088678u,0x0c08867au,0x0c08867cu,0x0c08867eu,0x0c088680u,0x0c088682u,
0x0c088684u,0x0c088686u,0x0c088688u,0x0c08868au,0x0c08868cu,0x0c08868eu,0x0c088690u,0x0c088692u,0x0c088694u,0x0c088696u,0x0c088698u,0x0c08869au,0x0c08869cu,0x0c08869eu,0x0c0886a0u,0x0c0886a2u,
0x0c0886a4u,0x0c0886a6u,0x0c0886a8u,0x0c0886aau,0x0c0886acu,0x0c0886aeu,0x0c0886b0u,0x0c0886b2u,0x0c0886b4u,0x0c0886b6u,0x0c0886b8u,0x0c0886bau,0x0c0886bcu,0x0c0886beu,0x0c0886c0u,0x0c0886c2u,
0x0c0886c4u,0x0c0886c6u,0x0c0886c8u,0x0c0886cau,0x0c0886ccu,0x0c0886ceu,0x0c0886d0u,0x0c0886d2u,0x0c0886d4u,0x0c0886d6u,0x0c0886d8u,0x0c0886dau,0x0c0886dcu,0x0c0886deu,0x0c0886e0u,0x0c0886e2u,
0x0c0886e4u,0x0c0886e6u,0x0c0886e8u,0x0c0886eau,0x0c0886ecu,0x0c0886eeu,0x0c0886f0u,0x0c0886f2u,0x0c0886f4u,0x0c0886f6u,0x0c0886f8u,0x0c0886fau,0x0c0886fcu,0x0c08870au,0x0c08870cu,0x0c08870eu,
0x0c088710u,0x0c088712u,0x0c088714u,0x0c088716u,0x0c088718u,0x0c08871au,0x0c08871cu,0x0c08871eu,0x0c088720u,0x0c088722u,0x0c088724u,0x0c088726u,0x0c088728u,0x0c08872au,0x0c08872cu,0x0c08872eu,
0x0c088730u,0x0c088732u,0x0c088734u,0x0c088736u,0x0c088738u,0x0c08873au,0x0c08873cu,0x0c08873eu,0x0c088740u,0x0c088742u,0x0c088744u,0x0c088746u,0x0c088748u,0x0c08874au,0x0c08874cu,0x0c08874eu,
0x0c088750u,0x0c088752u,0x0c088754u,0x0c088756u,0x0c088758u,0x0c08875au,0x0c08875cu,0x0c08875eu,0x0c088760u,0x0c088762u,0x0c088764u,0x0c088766u,0x0c088768u,0x0c08876au,0x0c08876cu,0x0c08876eu,
0x0c088770u,0x0c088772u,0x0c088774u,0x0c088776u,0x0c088778u,0x0c08877au,0x0c08877cu,0x0c08877eu,0x0c088780u,0x0c088782u,0x0c088784u,0x0c088786u,0x0c088788u,0x0c08878au,0x0c08878cu,0x0c08878eu,
0x0c088790u,0x0c088792u,0x0c088794u,0x0c088796u,0x0c088798u,0x0c08879au,0x0c08879cu,0x0c08879eu,0x0c0887a0u,0x0c0887a2u,0x0c0887a4u,0x0c0887a6u,0x0c0887a8u,0x0c0887aau,0x0c0887acu,0x0c0887aeu,
0x0c0887b0u,0x0c0887b2u,0x0c0887b4u,0x0c0887b6u,0x0c0887b8u,0x0c0887bau,0x0c0887bcu,0x0c0887beu,0x0c0887c0u,0x0c0887c2u,0x0c0887c4u,0x0c0887c6u,0x0c0887c8u,0x0c0887cau,0x0c0887ccu,0x0c088b5cu,
0x0c088b5eu,0x0c088b60u,0x0c088b62u,0x0c088b64u,0x0c088b66u,0x0c088b68u,0x0c088b6au,0x0c088b6cu,0x0c088b6eu,0x0c088b70u,0x0c088b72u,0x0c088b74u,0x0c088b76u,0x0c088b78u,0x0c088b7au,0x0c088b7cu,
0x0c088b7eu,0x0c088b80u,0x0c088b82u,0x0c088b84u,0x0c088b86u,0x0c088b88u,0x0c088b8au,0x0c088b8cu,0x0c088b8eu,0x0c088b90u,0x0c088b92u,0x0c088b94u,0x0c088b96u,0x0c088b98u,0x0c088b9au,0x0c088b9cu,
0x0c088b9eu,0x0c088ba0u,0x0c088ba2u,0x0c088ba4u,0x0c088ba6u,0x0c088ba8u,0x0c088baau,0x0c088bacu,0x0c088baeu,0x0c088bb0u,0x0c088bb2u,0x0c088bb4u,0x0c088bb6u,0x0c088bb8u,0x0c088bbau,0x0c088bbcu,
0x0c088bbeu,0x0c088bc0u,0x0c088bc2u,0x0c088bc4u,0x0c088bc6u,0x0c088bc8u,0x0c088bcau,0x0c088bccu,0x0c088bceu,0x0c088bd0u,0x0c088bd2u,0x0c088bd4u,0x0c088bd6u,0x0c088bd8u,0x0c088bdau,0x0c088bdcu,
0x0c088bdeu,0x0c088be0u,0x0c088be2u,0x0c088be4u,0x0c088be6u,0x0c088be8u,0x0c088beau,0x0c088becu,0x0c088beeu,0x0c088bf0u,0x0c088bf2u,0x0c088bf4u,0x0c088bf6u,0x0c088bf8u,0x0c088bfau,0x0c088bfcu,
0x0c088bfeu,0x0c088c00u,0x0c088c02u,0x0c088c04u,0x0c088c06u,0x0c088c08u,0x0c088c0au,0x0c088c0cu,0x0c088c0eu,0x0c088c10u,0x0c08a6ecu,0x0c08a6eeu,0x0c08a6f0u,0x0c08a6f2u,0x0c08a6f4u,0x0c08a6f6u,
0x0c08a6f8u,0x0c08a6fau,0x0c08a6fcu,0x0c08a6feu,0x0c08a700u,0x0c08a702u,0x0c08a704u,0x0c08a706u,0x0c08a708u,0x0c08a70au,0x0c08a70cu,0x0c08a70eu,0x0c08a710u,0x0c08a712u,0x0c08a714u,0x0c08a716u,
0x0c08a718u,0x0c08a71au,0x0c08a71cu,0x0c08a71eu,0x0c08a720u,0x0c08a722u,0x0c08a724u,0x0c08a726u,0x0c08a728u,0x0c08a72au,0x0c08a72cu,0x0c08a72eu,0x0c08a730u,0x0c08a732u,0x0c08a734u,0x0c08a736u,
0x0c08a738u,0x0c08a73au,0x0c08a73cu,0x0c08a73eu,0x0c08a740u,0x0c08a742u,0x0c08a744u,0x0c08a746u,0x0c08a748u,0x0c08a74au,0x0c08a74cu,0x0c08a74eu,0x0c08a750u,0x0c08a752u,0x0c08a754u,0x0c08a756u,
0x0c08a758u,0x0c08a75au,0x0c08a75cu,0x0c08a75eu,0x0c08a760u,0x0c08a762u,0x0c08a764u,0x0c08a766u,0x0c08a768u,0x0c08a76au,0x0c08a76cu,0x0c08a76eu,0x0c08a770u,0x0c08a772u,0x0c08a774u,0x0c08a776u,
0x0c08a778u,0x0c08a77au,0x0c08a77cu,0x0c08a77eu,0x0c08a780u,0x0c08a782u,0x0c08a784u,0x0c08a786u,0x0c08a788u,0x0c08a78au,0x0c08a78cu,0x0c08a78eu,0x0c08a790u,0x0c08a792u,0x0c08a794u,0x0c08a796u,
0x0c08a798u,0x0c08a79au,0x0c08a79cu,0x0c08a79eu,0x0c08a7a0u,0x0c08a7a2u,0x0c08a7a4u,0x0c08a7a6u,0x0c08a7a8u,0x0c08a7aau,0x0c08a7acu,0x0c08a7aeu,0x0c08a7b0u,0x0c08a7b2u,0x0c08a7b4u,0x0c08a7b6u,
0x0c08a7b8u,0x0c08a7bau,0x0c08a7bcu,0x0c08a7beu,0x0c08a7c0u,0x0c08a7c2u,0x0c08a7c4u,0x0c08a7c6u,0x0c08a7c8u,0x0c08a7cau,0x0c08a7ccu,0x0c08a7ceu,0x0c08a7deu,0x0c08a7e0u,0x0c08a7e2u,0x0c08a7e4u,
0x0c08a7e6u,0x0c08a7e8u,0x0c08a7eau,0x0c08a7ecu,0x0c08a7eeu,0x0c08a7f0u,0x0c08a7f2u,0x0c08a7f4u,0x0c08a7f6u,0x0c08a7f8u,0x0c08a7fau,0x0c08a7fcu,0x0c08a7feu,0x0c08a800u,0x0c08a802u,0x0c08a804u,
0x0c08a806u,0x0c08a808u,0x0c08a80au,0x0c08a80cu,0x0c08a80eu,0x0c08a810u,0x0c08a812u,0x0c08a814u,0x0c08a816u,0x0c08a818u,0x0c08a81au,0x0c08a81cu,0x0c08a81eu,0x0c08a820u,0x0c08a822u,0x0c08a824u,
0x0c08a826u,0x0c08a828u,0x0c08a82au,0x0c08a82cu,0x0c08a82eu,0x0c08a830u,0x0c08a832u,0x0c08a834u,0x0c08a836u,0x0c08a838u,0x0c08a83au,0x0c08a83cu,0x0c08a83eu,0x0c08a840u,0x0c08a842u,0x0c08a844u,
0x0c08a846u,0x0c08a848u,0x0c08a84au,0x0c08a84cu,0x0c08a84eu,0x0c08a850u,0x0c08a852u,0x0c08a854u,0x0c08a856u,0x0c08a858u,0x0c08a85au,0x0c08a85cu,0x0c08a85eu,0x0c08a88cu,0x0c08a88eu,0x0c08a890u,
0x0c08a892u,0x0c08a894u,0x0c08a896u,0x0c08a898u,0x0c08a89au,0x0c08a89cu,0x0c08a89eu,0x0c08a8a0u,0x0c08a8a2u,0x0c08a8a4u,0x0c08a8a6u,0x0c08a8a8u,0x0c08a8aau,0x0c08a8acu,0x0c08a8aeu,0x0c08a8b0u,
0x0c08a8b2u,0x0c08a8b4u,0x0c08a8b6u,0x0c08a8b8u,0x0c08a8bau,0x0c08a8bcu,0x0c08a8beu,0x0c08a8c0u,0x0c08e028u,0x0c08e02au,0x0c08e02cu,0x0c08e02eu,0x0c08e030u,0x0c08e032u,0x0c08e034u,0x0c08e036u,
0x0c08e038u,0x0c08e03au,0x0c08e03cu,0x0c08e03eu,0x0c08e040u,0x0c08e042u,0x0c08e044u,0x0c08e046u,0x0c08e048u,0x0c08e04au,0x0c08e04cu,0x0c08e04eu,0x0c08e050u,0x0c08e052u,0x0c08e054u,0x0c08e056u,
0x0c08e058u,0x0c08e05au,0x0c08e05cu,0x0c08e05eu,0x0c08e060u,0x0c08e062u,0x0c08e064u,0x0c08e066u,0x0c08e068u,0x0c08e06au,0x0c08e06cu,0x0c08e06eu,0x0c08e070u,0x0c08e072u,0x0c08e074u,0x0c08e076u,
0x0c08e078u,0x0c08e07au,0x0c08e07cu,0x0c08e07eu,0x0c08e080u,0x0c08e082u,0x0c08e084u,0x0c08e086u,0x0c08e088u,0x0c08e08au,0x0c08e08cu,0x0c08e08eu,0x0c08e090u,0x0c08e092u,0x0c08e094u,0x0c08e096u,
0x0c08e098u,0x0c08e09au,0x0c08e09cu,0x0c08e09eu,0x0c08e0a0u,0x0c08e0a2u,0x0c08e0a4u,0x0c08e0a6u,0x0c08e0a8u,0x0c08e0aau,0x0c08e0acu,0x0c08e0aeu,0x0c08e0b0u,0x0c08e0b2u,0x0c08e0b4u,0x0c08e0b6u,
0x0c08e0b8u,0x0c08e0bau,0x0c08e0bcu,0x0c08e0beu,0x0c08e0c0u,0x0c08e0c2u,0x0c08e0c4u,0x0c08e0c6u,0x0c096864u,0x0c096866u,0x0c096868u,0x0c09686au,0x0c09686cu,0x0c09686eu,0x0c096870u,0x0c096872u,
0x0c096874u,0x0c096876u,0x0c096878u,0x0c09687au,0x0c09687cu,0x0c09687eu,0x0c096880u,0x0c096882u,0x0c096884u,0x0c096886u,0x0c096888u,0x0c09688au,0x0c09688cu,0x0c09688eu,0x0c096890u,0x0c096892u,
0x0c096894u,0x0c096896u,0x0c096898u,0x0c09689au,0x0c09689cu,0x0c09689eu,0x0c0968a0u,0x0c0968a2u,0x0c0968a4u,0x0c0968a6u,0x0c0968a8u,0x0c0968aau,0x0c0968acu,0x0c0968aeu,0x0c0a2984u,0x0c0a2986u,
0x0c0a2988u,0x0c0a298au,0x0c0a298cu,0x0c0a298eu,0x0c0a2990u,0x0c0a2992u,0x0c0a2994u,0x0c0a2996u,0x0c0a2998u,0x0c0a299au,0x0c0a299cu,0x0c0a299eu,0x0c0a29a0u,0x0c0a29a2u,0x0c0a29a4u,0x0c0a29a6u,
0x0c0a29a8u,0x0c0a29aau,0x0c0a29acu,0x0c0a29aeu,0x0c0a29b0u,0x0c0a29b2u,0x0c0a29b4u,0x0c0a29b6u,0x0c0a29b8u,0x0c0a29bau,0x0c0a29bcu,0x0c0a29beu,0x0c0a29c0u,0x0c0a29c2u,0x0c0a29c4u,0x0c0a29c6u,
0x0c0a29c8u,0x0c0a29cau,0x0c0a29ccu,0x0c0a29ceu,0x0c0a29d0u,0x0c0a29d2u,0x0c0a29d4u,0x0c0a29d6u,0x0c0a29d8u,0x0c0a29dau,0x0c0a29dcu,0x0c0a29deu,0x0c0a29e0u,0x0c0a29e2u,0x0c0a29e4u,0x0c0a29e6u,
0x0c0a29e8u,0x0c0a29eau,0x0c0a29ecu,0x0c0a29eeu,0x0c0a29f0u,0x0c0a29f2u,0x0c0a29f4u,0x0c0a29f6u,0x0c0a29f8u,0x0c0a29fau,0x0c0a29fcu,0x0c0a29feu,0x0c0a2a00u,0x0c0a2a02u,0x0c0a2a04u,0x0c0a2a06u,
0x0c0a2a08u,0x0c0a2a0au,0x0c0a2a0cu,0x0c0a2a0eu,0x0c0a2a10u,0x0c0a2a12u,0x0c0a2a14u,0x0c0a2a16u,0x0c0a2a18u,0x0c0a2a1au,0x0c0a2a1cu,0x0c0a2a1eu,0x0c0a2a20u,0x0c0a2a22u,0x0c0a2a24u,0x0c0a2a26u,
0x0c0a2a28u,0x0c0a2a2au,0x0c0a2a2cu,0x0c0a2a2eu,0x0c0a2a30u,0x0c0a2a32u,0x0c0a2a34u,0x0c0a2a36u,0x0c0a2a38u,0x0c0a2a3au,0x0c0a2a3cu,0x0c0a2a3eu,0x0c0a2a40u,0x0c0a2a42u,0x0c0a2a44u,0x0c0a2a46u,
0x0c0a2a48u,0x0c0a2a4au,0x0c0a2a4cu,0x0c0a2a4eu,0x0c0a2a50u,0x0c0a2a52u,0x0c0a2a54u,0x0c0a2a56u,0x0c0a2a58u,0x0c0a2a5au,0x0c0a2a5cu,0x0c0a2a5eu,0x0c0a2a60u,0x0c0a2a62u,0x0c0a2a64u,0x0c0a2a66u,
0x0c0a2a68u,0x0c0a2a6au,0x0c0a2a6cu,0x0c0a2a6eu,0x0c0a2a70u,0x0c0a2a72u,0x0c0a2e86u,0x0c0a2e88u,0x0c0a2e8au,0x0c0a2e8cu,0x0c0a2e8eu,0x0c0a2e90u,0x0c0a2e92u,0x0c0a2e94u,0x0c0a2e96u,0x0c0a2e98u,
0x0c0a2e9au,0x0c0a2e9cu,0x0c0a2e9eu,0x0c0a2ea0u,0x0c0a2ea2u,0x0c0a2ea4u,0x0c0a2ea6u,0x0c0a2ea8u,0x0c0a2eaau,0x0c0a2eacu,0x0c0a2eaeu,0x0c0a2eb0u,0x0c0a2eb2u,0x0c0a2eb4u,0x0c0a2eb6u,0x0c0a2eb8u,
0x0c0a2ebau,0x0c0a2ebcu,0x0c0a2ebeu,0x0c0a2ec0u,0x0c0a2ec2u,0x0c0a2ec4u,0x0c0a2ec6u,0x0c0a2ec8u,0x0c0a2ecau,0x0c0a2eccu,0x0c0a2eceu,0x0c0a2ed0u,0x0c0a7f5au,0x0c0a7f5cu,0x0c0a7f5eu,0x0c0a7f60u,
0x0c0a7f62u,0x0c0a7f64u,0x0c0a7f66u,0x0c0a7f68u,0x0c0a7f6au,0x0c0a7f6cu,0x0c0a7f6eu,0x0c0a7f70u,0x0c0a7f72u,0x0c0a7f74u,0x0c0a7f76u,0x0c0a7f78u,0x0c0a7f7au,0x0c0a7f7cu,0x0c0a7f7eu,0x0c0a7f80u,
0x0c0a7f82u,0x0c0a7f84u,0x0c0a7f86u,0x0c0a7f88u,0x0c0a7f8au,0x0c0a7f8cu,0x0c0a7f8eu,0x0c0a7f90u,0x0c0a7f92u,0x0c0a7f94u,0x0c0a7f96u,0x0c0a7f98u,0x0c0a7f9au,0x0c0a7f9cu,0x0c0a7f9eu,0x0c0a7fa0u,
0x0c0a7fa2u,0x0c0a7fa4u,0x0c0a7fc0u,0x0c0a7fc2u,0x0c0a7fc4u,0x0c0a7fc6u,0x0c0a7fc8u,0x0c0a7fcau,0x0c0a7fccu,0x0c0a7fceu,0x0c0a7fd0u,0x0c0a7fd2u,0x0c0a7fd4u,0x0c0a7fd6u,0x0c0a7fd8u,0x0c0a7fdau,
0x0c0a7fdcu,0x0c0a7fdeu,0x0c0a7fe0u,0x0c0a7fe2u,0x0c0a7fe4u,0x0c0a7fe6u,0x0c0a7fe8u,0x0c0a7feau,0x0c0a7fecu,0x0c0a7feeu,0x0c0a7ff0u,0x0c0a7ff2u,0x0c0a7ff4u,0x0c0a7ff6u,0x0c0a7ff8u,0x0c0a7ffau,
0x0c0a7ffcu,0x0c0a7ffeu,0x0c0a8000u,0x0c0a8002u,0x0c0a8004u,0x0c0a8006u,0x0c0a8008u,0x0c0a800au,0x0c0a800cu,0x0c0a800eu,0x0c0a8010u,0x0c0a8012u,0x0c0a8014u,0x0c0a8016u,0x0c0a8018u,0x0c0a801au,
0x0c0a801cu,0x0c0a801eu,0x0c0a8020u,0x0c0a8022u,0x0c0a8024u,0x0c0a8026u,0x0c0a8028u,0x0c0a802au,0x0c0a802cu,0x0c0a802eu,0x0c0a8030u,0x0c0a8032u,0x0c0a8034u,0x0c0a8036u,0x0c0a8038u,0x0c0a803au,
0x0c0a81eeu,0x0c0a81f0u,0x0c0a81f2u,0x0c0a81f4u,0x0c0a81f6u,0x0c0a81f8u,0x0c0a81fau,0x0c0a81fcu,0x0c0a81feu,0x0c0a8200u,0x0c0a8202u,0x0c0a8204u,0x0c0a8206u,0x0c0a8208u,0x0c0a820au,0x0c0a820cu,
0x0c0a820eu,0x0c0a8210u,0x0c0a8212u,0x0c0a8214u,0x0c0a8216u,0x0c0a8218u,0x0c0a821au,0x0c0a821cu,0x0c0a821eu,0x0c0a8220u,0x0c0a8222u,0x0c0a8224u,0x0c0a8226u,0x0c0a8228u,0x0c0a822au,0x0c0a822cu,
0x0c0a822eu,0x0c0a8230u,0x0c0a8232u,0x0c0a8234u,0x0c0a8236u,0x0c0a8238u,0x0c0a823au,0x0c0a823cu,0x0c0a823eu,0x0c0a8240u,0x0c0a8242u,0x0c0a8244u,0x0c0a8246u,0x0c0a8248u,0x0c0a824au,0x0c0a824cu,
0x0c0a824eu,0x0c0a8250u,0x0c0a8252u,0x0c0a8254u,0x0c0a8256u,0x0c0a8258u,0x0c0a825au,0x0c0a825cu,0x0c0a825eu,0x0c0a8260u,0x0c0a8262u,0x0c0a8264u,0x0c0a8266u,0x0c0a8268u,0x0c0a826au,0x0c0a826cu,
0x0c0a826eu,0x0c0a8270u,0x0c0a8272u,0x0c0a8274u,0x0c0a8276u,0x0c0a8278u,0x0c0a827au,0x0c0a827cu,0x0c0a827eu,0x0c0a8280u,0x0c0a8282u,0x0c0a8284u,0x0c0a8286u,0x0c0a8288u,0x0c0a828au,0x0c0a828cu,
0x0c0a828eu,0x0c0a8290u,0x0c0a8292u,0x0c0a8294u,0x0c0a8296u,0x0c0a8298u,0x0c0a829au,0x0c0c1208u,0x0c0c120au,0x0c0c120cu,0x0c0c120eu,0x0c0c1210u,0x0c0c1212u,0x0c0c1214u,0x0c0c1216u,0x0c0c1218u,
0x0c0c121au,0x0c0c121cu,0x0c0c121eu,0x0c0c1220u,0x0c0c1222u,0x0c0c1224u,0x0c0c1226u,0x0c0c1228u,0x0c0c122au,0x0c0c122cu,0x0c0c122eu,0x0c0c1230u,0x0c0c1232u,0x0c0c1234u,0x0c0c1236u,0x0c0c1238u,
0x0c0c123au,0x0c0c123cu,0x0c0c123eu,0x0c0c1240u,0x0c0c1242u,0x0c0c1244u,0x0c0c1246u,0x0c0c1248u,0x0c0c124au,0x0c0c124cu,0x0c0c182eu,0x0c0c1830u,0x0c0c1832u,0x0c0c1834u,0x0c0c3a26u,0x0c0c3a28u,
0x0c0c3a2au,0x0c0c3a2cu,0x0c0c3a2eu,0x0c0c3a30u,0x0c0c3a32u,0x0c0c3a34u,0x0c0c3a36u,0x0c0c3a38u,0x0c0c3a3au,0x0c0c3a3cu,0x0c0c3a3eu,0x0c0c3a40u,0x0c0c3a42u,0x0c0c3a44u,0x0c0c3a46u,0x0c0c3a48u,
0x0c0c3a84u,0x0c0c3a86u,0x0c0c3a88u,0x0c0c3a8au,0x0c0c3a8cu,0x0c0c3a8eu,0x0c0c3a90u,0x0c0c3a92u,0x0c0c3a94u,0x0c0c3a96u,0x0c0c3a98u,0x0c0c3a9au,0x0c0c3a9cu,0x0c0c3a9eu,0x0c0c3aa0u,0x0c0c3aa2u,
0x0c0c3aa4u,0x0c0c3aa6u,0x0c0c3aa8u,0x0c0c3aaau,0x0c0c3aacu,0x0c0c3aaeu,0x0c0c3ab0u,0x0c0c3ab2u,0x0c0c3ab4u,0x0c0c3ab6u,0x0c0c3ab8u,0x0c0c3abau,0x0c0c3abcu,0x0c0c3abeu,0x0c0c3ac0u,0x0c0c3ac2u,
0x0c0c3ac4u,0x0c0c3ac6u,0x0c0c3ac8u,0x0c0c3acau,0x0c0c3accu,0x0c0c3aceu,0x0c0c3ad0u,0x0c0c3ad2u,0x0c0c3ad4u,0x0c0c3ad6u,0x0c0c3ad8u,0x0c0c3adau,0x0c0c3adcu,0x0c0c3adeu,0x0c0c3ae0u,0x0c0c3ae2u,
0x0c0c3ae4u,0x0c0c3ae6u,0x0c0c3ae8u,0x0c0c3aeau,0x0c0c3aecu,0x0c0c3aeeu,0x0c0c3af0u,0x0c0c3af2u,0x0c0c3af4u,0x0c0c3af6u,0x0c0c3af8u,0x0c0c3afau,0x0c0c3afcu,0x0c0c3afeu,0x0c0c3b00u,0x0c0c3b02u,
0x0c0c3b04u,0x0c0c3b06u,0x0c0c3b08u,0x0c0c3b0au,0x0c0c3b0cu,0x0c0c3b0eu,0x0c0c3b10u,0x0c0c3b12u,0x0c0c3b14u,0x0c0c3b16u,0x0c0c3b18u,0x0c0c3b1au,0x0c0c5c94u,0x0c0c5c96u,0x0c0c5c98u,0x0c0c5c9au,
0x0c0c5c9cu,0x0c0c5c9eu,0x0c0c5ca0u,0x0c0c5ca2u,0x0c0c5ca4u,0x0c0c5ca6u,0x0c0c5ca8u,0x0c0c5caau,0x0c0c5cacu,0x0c0c5caeu,0x0c0c5cb0u,0x0c0c5cf4u,0x0c0c5cf6u,0x0c0c5cf8u,0x0c0c5cfau,0x0c0c5cfcu,
0x0c0c5cfeu,0x0c0c5d00u,0x0c0c5d02u,0x0c0c5d04u,0x0c0c5d06u,0x0c0c5d08u,0x0c0c5d0au,0x0c0c5d0cu,0x0c0c5d0eu,0x0c0c5d10u,0x0c0c5d12u,0x0c0c5d14u,0x0c0c5d16u,0x0c0c5d18u,0x0c0c5d1au,0x0c0c5d1cu,
0x0c0c5d1eu,0x0c0c5d20u,0x0c0c5d22u,0x0c0c5d24u,0x0c0c5d26u,0x0c0c5d28u,0x0c0c5d2au,0x0c0c5d2cu,0x0c0c5d2eu,0x0c0c5d30u,0x0c0c5d32u,0x0c0c5d34u,0x0c0c5d36u,0x0c0c5d38u,0x0c0c5d3au,0x0c0c5d3cu,
0x0c0c5d3eu,0x0c0c5d40u,0x0c0c5d42u,0x0c0c5d44u,0x0c0c5d46u,0x0c0c5d48u,0x0c0c5d4au,0x0c0c5d4cu,0x0c0c5d4eu,0x0c0c5d50u,0x0c0c5d52u,0x0c0c5d54u,0x0c0c5d56u,0x0c0c5d58u,0x0c0c5d5au,0x0c0c5d5cu,
0x0c0c5d5eu,0x0c0c5d60u,0x0c0c5d62u,0x0c0c5d64u,0x0c0c5d66u,0x0c0c5d68u,0x0c0c5d6au,0x0c0c5d6cu,0x0c0c5d6eu,0x0c0c5d70u,0x0c0c5d72u,0x0c0c5d74u,0x0c0c5d76u,0x0c0c5d78u,0x0c0c5d7au,0x0c0c5d7cu,
0x0c0c5d7eu,0x0c0c5d80u,0x0c0c5d82u,0x0c0c5d84u,0x0c0c601cu,0x0c0c601eu,0x0c0c6020u,0x0c0c6022u,0x0c0c6024u,0x0c0c6026u,0x0c0c6028u,0x0c0c602au,0x0c0c602cu,0x0c0c602eu,0x0c0c6030u,0x0c0c6032u,
0x0c0c6034u,0x0c0c6036u,0x0c0c6038u,0x0c0c603au,0x0c0c603cu,0x0c0c603eu,0x0c0c6040u,0x0c0c6042u,0x0c0c6044u,0x0c0c6046u,0x0c0c6048u,0x0c0c604au,0x0c0c604cu,0x0c0c604eu,0x0c0c6050u,0x0c0c6052u,
0x0c0c6054u,0x0c0c6056u,0x0c0c6058u,0x0c0c605au,0x0c0c605cu,0x0c0c605eu,0x0c0c6060u,0x0c0c6062u,0x0c0c6064u,0x0c0c6066u,0x0c0c6068u,0x0c0c606au,0x0c0c606cu,0x0c0c606eu,0x0c0c6070u,0x0c0c6072u,
0x0c0c6074u,0x0c0c6076u,0x0c0c6078u,0x0c0c607au,0x0c0c607cu,0x0c0c607eu,0x0c0c6080u,0x0c0c6082u,0x0c0c6084u,0x0c0c6086u,0x0c0c6088u,0x0c0c608au,0x0c0c608cu,0x0c0c608eu,0x0c0c6090u,0x0c0c6092u,
0x0c0c6094u,0x0c0c6096u,0x0c0c6098u,0x0c0c609au,0x0c0c609cu,0x0c0c609eu,0x0c0c60a0u,0x0c0c60a2u,0x0c0c60a4u,0x0c0c60a6u,0x0c0c60a8u,0x0c0c60aau,0x0c0c60acu,0x0c0c60aeu,0x0c0c60b0u,0x0c0c60b2u,
0x0c0c60b4u,0x0c0c60b6u,0x0c0c60b8u,0x0c0c60bau,0x0c0c60bcu,0x0c0c60beu,0x0c0c66b8u,0x0c0c66bau,0x0c0c7562u,0x0c0c7564u,0x0c0c7566u,0x0c0c7568u,0x0c0c756au,0x0c0c756cu,0x0c0c756eu,0x0c0c7570u,
0x0c0c7572u,0x0c0c7574u,0x0c0c7576u,0x0c0c7578u,0x0c0c757au,0x0c0c757cu,0x0c0c757eu,0x0c0c7580u,0x0c0c7582u,0x0c0c7584u,0x0c0c7586u,0x0c0c7588u,0x0c0c758au,0x0c0c758cu,0x0c0c758eu,0x0c0c7590u,
0x0c0c7592u,0x0c0c7594u,0x0c0c7596u,0x0c0c7598u,0x0c0c759au,0x0c0c759cu,0x0c0c759eu,0x0c0c75a0u,0x0c0c75a2u,0x0c0c75a4u,0x0c0c75a6u,0x0c0c75a8u,0x0c0c75aau,0x0c0c75acu,0x0c0c75aeu,0x0c0c75b0u,
0x0c0c75b2u,0x0c0c75b4u,0x0c0c75b6u,0x0c0c75b8u,0x0c0c75bau,0x0c0c75bcu,0x0c0c75beu,0x0c0c75c0u,0x0c0c75c2u,0x0c0c75c4u,0x0c0c75c6u,0x0c0c75c8u,0x0c0c75cau,0x0c0c75ccu,0x0c0c75ceu,0x0c0c75d0u,
0x0c0c75d2u,0x0c0c75d4u,0x0c0c75d6u,0x0c0c75d8u,0x0c0c75dau,0x0c0c75dcu,0x0c0c75deu,0x0c0c75e0u,0x0c0c75e2u,0x0c0c75e4u,0x0c0c75e6u,0x0c0c75e8u,0x0c0c75eau,0x0c0c75ecu,0x0c0c75eeu,0x0c0c75f0u,
0x0c0c75f2u,0x0c0c75f4u,0x0c0c75f6u,0x0c0c75f8u,0x0c0c75fau,0x0c0c75fcu,0x0c0c75feu,0x0c0c7600u,0x0c0c7602u,0x0c0c7604u,0x0c0c7606u,0x0c0c7608u,0x0c0c760au,0x0c0c760cu,0x0c0c760eu,0x0c0c7610u,
0x0c0c7612u,0x0c0c7614u,0x0c0c7616u,0x0c0c7618u,0x0c0c761au,0x0c0c761cu,0x0c0c7802u,0x0c0c7804u,0x0c0c7806u,0x0c0c7808u,0x0c0c780au,0x0c0c780cu,0x0c0c780eu,0x0c0c7810u,0x0c0c7812u,0x0c0c7814u,
0x0c0c7816u,0x0c0c7818u,0x0c0c781au,0x0c0c781cu,0x0c0c781eu,0x0c0c7820u,0x0c0c7822u,0x0c0c7824u,0x0c0c7826u,0x0c0c7828u,0x0c0c782au,0x0c0c782cu,0x0c0c782eu,0x0c0c7830u,0x0c0c7832u,0x0c0c7834u,
0x0c0c7836u,0x0c0c7838u,0x0c0c783au,0x0c0c783cu,0x0c0c783eu,0x0c0c7840u,0x0c0c7842u,0x0c0c7844u,0x0c0c7846u,0x0c0c7848u,0x0c0c784au,0x0c0c784cu,0x0c0c784eu,0x0c0c7850u,0x0c0c7852u,0x0c0c7854u,
0x0c0c7856u,0x0c0c7858u,0x0c0c785au,0x0c0c785cu,0x0c0c78e0u,0x0c0c78e2u,0x0c0c78e4u,0x0c0c78e6u,0x0c0c78e8u,0x0c0c78eau,0x0c0c78ecu,0x0c0c78eeu,0x0c0c78f0u,0x0c0c78f2u,0x0c0c78f4u,0x0c0c78f6u,
0x0c0c78f8u,0x0c0c78fau,0x0c0c78fcu,0x0c0c78feu,0x0c0c7900u,0x0c0c7902u,0x0c0c7904u,0x0c0c7906u,0x0c0c7908u,0x0c0c790au,0x0c0c790cu,0x0c0c790eu,0x0c0c7910u,0x0c0c7912u,0x0c0c7914u,0x0c0c7916u,
0x0c0c7918u,0x0c0c791au,0x0c0c791cu,0x0c0c791eu,0x0c0c7920u,0x0c0c7922u,0x0c0c7924u,0x0c0c7926u,0x0c0c7928u,0x0c0c792au,0x0c0c792cu,0x0c0c792eu,0x0c0c7930u,0x0c0c7932u,0x0c0c7934u,0x0c0c7936u,
0x0c0c7938u,0x0c0c793au,0x0c0c793cu,0x0c0c793eu,0x0c0c7940u,0x0c0c7942u,0x0c0c7944u,0x0c0c7946u,0x0c0c7948u,0x0c0c794au,0x0c0c794cu,0x0c0c794eu,0x0c0c7950u,0x0c0c7952u,0x0c0c7954u,0x0c0c7956u,
0x0c0c7958u,0x0c0c795au,0x0c0c795cu,0x0c0c795eu,0x0c0c7960u,0x0c0c7962u,0x0c0c7964u,0x0c0c7966u,0x0c0c7968u,0x0c0c796au,0x0c0c796cu,0x0c0c796eu,0x0c0c7970u,0x0c0c7972u,0x0c0c7974u,0x0c0c7976u,
0x0c0c7978u,0x0c0c797au,0x0c0c797cu,0x0c0c797eu,0x0c0c7980u,0x0c0c7982u,0x0c0c7984u,0x0c0c7986u,0x0c0c7988u,0x0c0c798au,0x0c0c798cu,0x0c0c798eu,0x0c0c7990u,0x0c0c7992u,0x0c0c7994u,0x0c0c7996u,
0x0c0c7998u,0x0c0c799au,0x0c0c799cu,0x0c0c799eu,0x0c0c79a0u,0x0c0c79a2u,0x0c0c79a4u,0x0c0c79a6u,0x0c0c79a8u,0x0c0c8e7cu,0x0c0c8e7eu,0x0c0c8e80u,0x0c0c8e82u,0x0c0c8e84u,0x0c0c8e86u,0x0c0c8e88u,
0x0c0c8e8au,0x0c0c8e8cu,0x0c0c8e8eu,0x0c0c8e90u,0x0c0c8e92u,0x0c0c8e94u,0x0c0c8e96u,0x0c0c8e98u,0x0c0c8e9au,0x0c0c8e9cu,0x0c0c8e9eu,0x0c0c8ea0u,0x0c0c8ea2u,0x0c0c8ea4u,0x0c0c8ea6u,0x0c0c8ea8u,
0x0c0c8eaau,0x0c0c8eacu,0x0c0c8eaeu,0x0c0c8eb0u,0x0c0c8eb2u,0x0c0c8eb4u,0x0c0c8eb6u,0x0c0c8eb8u,0x0c0c8ebau,0x0c0c8ebcu,0x0c0c8ebeu,0x0c0c8ec0u,0x0c0c8ec2u,0x0c0c8ec4u,0x0c0c8ec6u,0x0c0c8ec8u,
0x0c0c8ecau,0x0c0c8eccu,0x0c0c8eceu,0x0c0c8ed0u,0x0c0c8ed2u,0x0c0c8ed4u,0x0c0c8ed6u,0x0c0c8ed8u,0x0c0c8edau,0x0c0c8edcu,0x0c0c8edeu,0x0c0c8ee0u,0x0c0c8ee2u,0x0c0c8ee4u,0x0c0c8ee6u,0x0c0c8ee8u,
0x0c0c8eeau,0x0c0c8eecu,0x0c0c8eeeu,0x0c0c8ef0u,0x0c0c8ef2u,0x0c0c8ef4u,0x0c0c8ef6u,0x0c0c8ef8u,0x0c0c8efau,0x0c0c8efcu,0x0c0c8efeu,0x0c0c8f00u,0x0c0c8f02u,0x0c0c8f04u,0x0c0c8f06u,0x0c0c8f08u,
0x0c0c8f0au,0x0c0c8f0cu,0x0c0c8f0eu,0x0c0c8f10u,0x0c0c8f12u,0x0c0c8f14u,0x0c0c8f16u,0x0c0c8f18u,0x0c0c8f1au,0x0c0c8f1cu,0x0c0c8f1eu,0x0c0c8f20u,0x0c0c8f22u,0x0c0c8f24u,0x0c0c8f26u,0x0c0c8f28u,
0x0c0c8f2au,0x0c0c8f2cu,0x0c0c8f2eu,0x0c0c8f30u,0x0c0c8f32u,0x0c0c8f34u,
};
int vf3_c82_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
