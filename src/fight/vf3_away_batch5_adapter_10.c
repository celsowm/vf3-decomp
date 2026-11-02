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
int vf3_away_batch5_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04c3c6u: goto P_0c04c3c6;
case 0x0c04c3c8u: goto P_0c04c3c8;
case 0x0c04c3cau: goto P_0c04c3ca;
case 0x0c04c3ccu: goto P_0c04c3cc;
case 0x0c04c3ceu: goto P_0c04c3ce;
case 0x0c04c3d0u: goto P_0c04c3d0;
case 0x0c04c3d2u: goto P_0c04c3d2;
case 0x0c04c3d4u: goto P_0c04c3d4;
case 0x0c04c3d6u: goto P_0c04c3d6;
case 0x0c04c3d8u: goto P_0c04c3d8;
case 0x0c04c3dau: goto P_0c04c3da;
case 0x0c04c3dcu: goto P_0c04c3dc;
case 0x0c04c3deu: goto P_0c04c3de;
case 0x0c04c3e0u: goto P_0c04c3e0;
case 0x0c04c3e2u: goto P_0c04c3e2;
case 0x0c04c3e4u: goto P_0c04c3e4;
case 0x0c04c3e6u: goto P_0c04c3e6;
case 0x0c04c5a0u: goto P_0c04c5a0;
case 0x0c04c5a2u: goto P_0c04c5a2;
case 0x0c04c5a4u: goto P_0c04c5a4;
case 0x0c04c5a6u: goto P_0c04c5a6;
case 0x0c04c5a8u: goto P_0c04c5a8;
case 0x0c04c5aau: goto P_0c04c5aa;
case 0x0c04c5acu: goto P_0c04c5ac;
case 0x0c04c5aeu: goto P_0c04c5ae;
case 0x0c04c5b0u: goto P_0c04c5b0;
case 0x0c04c5b2u: goto P_0c04c5b2;
case 0x0c04c5b4u: goto P_0c04c5b4;
case 0x0c04c5b6u: goto P_0c04c5b6;
case 0x0c04c5b8u: goto P_0c04c5b8;
case 0x0c04c5bau: goto P_0c04c5ba;
case 0x0c04c5bcu: goto P_0c04c5bc;
case 0x0c04c5beu: goto P_0c04c5be;
case 0x0c04c5c0u: goto P_0c04c5c0;
case 0x0c04c5c2u: goto P_0c04c5c2;
case 0x0c04c5c4u: goto P_0c04c5c4;
case 0x0c04c5c6u: goto P_0c04c5c6;
case 0x0c04c5c8u: goto P_0c04c5c8;
case 0x0c04c5cau: goto P_0c04c5ca;
case 0x0c04c5ccu: goto P_0c04c5cc;
case 0x0c04c5ceu: goto P_0c04c5ce;
case 0x0c04c5d0u: goto P_0c04c5d0;
case 0x0c04c5d2u: goto P_0c04c5d2;
case 0x0c04c5d4u: goto P_0c04c5d4;
case 0x0c04c5d6u: goto P_0c04c5d6;
case 0x0c04c5d8u: goto P_0c04c5d8;
case 0x0c04c5dau: goto P_0c04c5da;
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
case 0x0c04d448u: goto P_0c04d448;
case 0x0c04d44au: goto P_0c04d44a;
case 0x0c04d44cu: goto P_0c04d44c;
case 0x0c04d44eu: goto P_0c04d44e;
case 0x0c04d450u: goto P_0c04d450;
case 0x0c04d452u: goto P_0c04d452;
case 0x0c04d454u: goto P_0c04d454;
case 0x0c04d456u: goto P_0c04d456;
case 0x0c04d458u: goto P_0c04d458;
case 0x0c04d45au: goto P_0c04d45a;
case 0x0c04d45cu: goto P_0c04d45c;
case 0x0c04d45eu: goto P_0c04d45e;
case 0x0c04d460u: goto P_0c04d460;
case 0x0c04d462u: goto P_0c04d462;
case 0x0c04d464u: goto P_0c04d464;
case 0x0c04d466u: goto P_0c04d466;
case 0x0c04d468u: goto P_0c04d468;
case 0x0c04d46au: goto P_0c04d46a;
case 0x0c04d46cu: goto P_0c04d46c;
case 0x0c04d46eu: goto P_0c04d46e;
case 0x0c04d470u: goto P_0c04d470;
case 0x0c04d472u: goto P_0c04d472;
case 0x0c04d474u: goto P_0c04d474;
case 0x0c04d476u: goto P_0c04d476;
case 0x0c04d478u: goto P_0c04d478;
case 0x0c04d47au: goto P_0c04d47a;
case 0x0c04d47cu: goto P_0c04d47c;
case 0x0c04d47eu: goto P_0c04d47e;
case 0x0c04d480u: goto P_0c04d480;
case 0x0c04d482u: goto P_0c04d482;
case 0x0c04d484u: goto P_0c04d484;
case 0x0c04d486u: goto P_0c04d486;
case 0x0c04d488u: goto P_0c04d488;
case 0x0c04d48au: goto P_0c04d48a;
case 0x0c04d48cu: goto P_0c04d48c;
case 0x0c04d48eu: goto P_0c04d48e;
case 0x0c04d490u: goto P_0c04d490;
case 0x0c04d492u: goto P_0c04d492;
case 0x0c04d494u: goto P_0c04d494;
case 0x0c04d496u: goto P_0c04d496;
case 0x0c04d498u: goto P_0c04d498;
case 0x0c04d49au: goto P_0c04d49a;
case 0x0c04d49cu: goto P_0c04d49c;
case 0x0c04d49eu: goto P_0c04d49e;
case 0x0c04d4a0u: goto P_0c04d4a0;
case 0x0c04d4a2u: goto P_0c04d4a2;
case 0x0c04d4a4u: goto P_0c04d4a4;
case 0x0c04d4a6u: goto P_0c04d4a6;
case 0x0c04d4a8u: goto P_0c04d4a8;
case 0x0c04d4aau: goto P_0c04d4aa;
case 0x0c04d4acu: goto P_0c04d4ac;
case 0x0c04d4aeu: goto P_0c04d4ae;
case 0x0c04d4b0u: goto P_0c04d4b0;
case 0x0c04d4b2u: goto P_0c04d4b2;
case 0x0c04d4b4u: goto P_0c04d4b4;
case 0x0c04d4b6u: goto P_0c04d4b6;
case 0x0c04d4b8u: goto P_0c04d4b8;
case 0x0c04d4bau: goto P_0c04d4ba;
case 0x0c04d4bcu: goto P_0c04d4bc;
case 0x0c04d4beu: goto P_0c04d4be;
case 0x0c04d4c0u: goto P_0c04d4c0;
case 0x0c04d4c2u: goto P_0c04d4c2;
case 0x0c04d4c4u: goto P_0c04d4c4;
case 0x0c04d4c6u: goto P_0c04d4c6;
case 0x0c04d4c8u: goto P_0c04d4c8;
case 0x0c04d4cau: goto P_0c04d4ca;
case 0x0c04d4ccu: goto P_0c04d4cc;
case 0x0c04d4ceu: goto P_0c04d4ce;
case 0x0c04d4d0u: goto P_0c04d4d0;
case 0x0c04d4d2u: goto P_0c04d4d2;
case 0x0c04d4d4u: goto P_0c04d4d4;
case 0x0c04d4d6u: goto P_0c04d4d6;
case 0x0c04d4d8u: goto P_0c04d4d8;
case 0x0c04d4dau: goto P_0c04d4da;
case 0x0c04d4dcu: goto P_0c04d4dc;
case 0x0c04d4deu: goto P_0c04d4de;
case 0x0c04d4e0u: goto P_0c04d4e0;
case 0x0c04d4e2u: goto P_0c04d4e2;
case 0x0c04d4e4u: goto P_0c04d4e4;
case 0x0c04d4e6u: goto P_0c04d4e6;
case 0x0c04d4e8u: goto P_0c04d4e8;
case 0x0c04d4eau: goto P_0c04d4ea;
case 0x0c04d4ecu: goto P_0c04d4ec;
case 0x0c04d4eeu: goto P_0c04d4ee;
case 0x0c04d4f0u: goto P_0c04d4f0;
case 0x0c04d4f2u: goto P_0c04d4f2;
case 0x0c04d4f4u: goto P_0c04d4f4;
case 0x0c04d4f6u: goto P_0c04d4f6;
case 0x0c04d4f8u: goto P_0c04d4f8;
case 0x0c04d4fau: goto P_0c04d4fa;
case 0x0c04d4fcu: goto P_0c04d4fc;
case 0x0c04d4feu: goto P_0c04d4fe;
case 0x0c04d500u: goto P_0c04d500;
case 0x0c04d502u: goto P_0c04d502;
case 0x0c04d504u: goto P_0c04d504;
case 0x0c04d506u: goto P_0c04d506;
case 0x0c04d508u: goto P_0c04d508;
case 0x0c04d50au: goto P_0c04d50a;
case 0x0c04dd9cu: goto P_0c04dd9c;
case 0x0c04dd9eu: goto P_0c04dd9e;
case 0x0c04dda0u: goto P_0c04dda0;
case 0x0c04dda2u: goto P_0c04dda2;
case 0x0c04dda4u: goto P_0c04dda4;
case 0x0c04dda6u: goto P_0c04dda6;
case 0x0c04dda8u: goto P_0c04dda8;
case 0x0c04ddaau: goto P_0c04ddaa;
case 0x0c04ddacu: goto P_0c04ddac;
case 0x0c04ddaeu: goto P_0c04ddae;
case 0x0c04ddb0u: goto P_0c04ddb0;
case 0x0c04ddb2u: goto P_0c04ddb2;
case 0x0c04ddb4u: goto P_0c04ddb4;
case 0x0c04ddb6u: goto P_0c04ddb6;
case 0x0c04ddb8u: goto P_0c04ddb8;
case 0x0c04ddbau: goto P_0c04ddba;
case 0x0c04ddbcu: goto P_0c04ddbc;
case 0x0c04ddbeu: goto P_0c04ddbe;
case 0x0c04ddc0u: goto P_0c04ddc0;
case 0x0c04ddc2u: goto P_0c04ddc2;
case 0x0c04ddc4u: goto P_0c04ddc4;
case 0x0c04ddc6u: goto P_0c04ddc6;
case 0x0c04ddc8u: goto P_0c04ddc8;
case 0x0c04ddcau: goto P_0c04ddca;
case 0x0c04ddccu: goto P_0c04ddcc;
case 0x0c04ddceu: goto P_0c04ddce;
case 0x0c04ddd0u: goto P_0c04ddd0;
case 0x0c04ddd2u: goto P_0c04ddd2;
case 0x0c04ddd4u: goto P_0c04ddd4;
case 0x0c04ddd6u: goto P_0c04ddd6;
case 0x0c04ddd8u: goto P_0c04ddd8;
case 0x0c04dddau: goto P_0c04ddda;
case 0x0c04dddcu: goto P_0c04dddc;
case 0x0c04dddeu: goto P_0c04ddde;
case 0x0c04dde0u: goto P_0c04dde0;
case 0x0c04dde2u: goto P_0c04dde2;
case 0x0c04dde4u: goto P_0c04dde4;
case 0x0c04dde6u: goto P_0c04dde6;
case 0x0c04dde8u: goto P_0c04dde8;
case 0x0c04ddeau: goto P_0c04ddea;
case 0x0c04ddecu: goto P_0c04ddec;
case 0x0c04ddeeu: goto P_0c04ddee;
case 0x0c04ddf0u: goto P_0c04ddf0;
case 0x0c04ddf2u: goto P_0c04ddf2;
case 0x0c04ddf4u: goto P_0c04ddf4;
case 0x0c04ddf6u: goto P_0c04ddf6;
case 0x0c04ddf8u: goto P_0c04ddf8;
case 0x0c04ddfau: goto P_0c04ddfa;
case 0x0c04ddfcu: goto P_0c04ddfc;
case 0x0c04ddfeu: goto P_0c04ddfe;
case 0x0c04de00u: goto P_0c04de00;
case 0x0c04de02u: goto P_0c04de02;
case 0x0c04de04u: goto P_0c04de04;
case 0x0c04de06u: goto P_0c04de06;
case 0x0c04de08u: goto P_0c04de08;
case 0x0c04de0au: goto P_0c04de0a;
case 0x0c04de0cu: goto P_0c04de0c;
case 0x0c04de0eu: goto P_0c04de0e;
case 0x0c04de10u: goto P_0c04de10;
case 0x0c04de12u: goto P_0c04de12;
case 0x0c04de14u: goto P_0c04de14;
case 0x0c04de16u: goto P_0c04de16;
case 0x0c04de18u: goto P_0c04de18;
case 0x0c04de1au: goto P_0c04de1a;
case 0x0c04de1cu: goto P_0c04de1c;
case 0x0c04de1eu: goto P_0c04de1e;
case 0x0c04de20u: goto P_0c04de20;
case 0x0c04de22u: goto P_0c04de22;
case 0x0c04de24u: goto P_0c04de24;
case 0x0c04de26u: goto P_0c04de26;
case 0x0c04de28u: goto P_0c04de28;
case 0x0c04de2au: goto P_0c04de2a;
case 0x0c04de2cu: goto P_0c04de2c;
case 0x0c04de2eu: goto P_0c04de2e;
case 0x0c04de30u: goto P_0c04de30;
case 0x0c04de32u: goto P_0c04de32;
case 0x0c04de34u: goto P_0c04de34;
case 0x0c04de36u: goto P_0c04de36;
case 0x0c04de38u: goto P_0c04de38;
case 0x0c04de3au: goto P_0c04de3a;
case 0x0c04de3cu: goto P_0c04de3c;
case 0x0c04de3eu: goto P_0c04de3e;
case 0x0c04de40u: goto P_0c04de40;
case 0x0c04de42u: goto P_0c04de42;
case 0x0c04de44u: goto P_0c04de44;
case 0x0c04de46u: goto P_0c04de46;
case 0x0c04de48u: goto P_0c04de48;
case 0x0c04de4au: goto P_0c04de4a;
case 0x0c04de4cu: goto P_0c04de4c;
case 0x0c04de4eu: goto P_0c04de4e;
case 0x0c04de50u: goto P_0c04de50;
case 0x0c04de52u: goto P_0c04de52;
case 0x0c04de54u: goto P_0c04de54;
case 0x0c04de56u: goto P_0c04de56;
case 0x0c04de58u: goto P_0c04de58;
case 0x0c04de5au: goto P_0c04de5a;
case 0x0c04de5cu: goto P_0c04de5c;
case 0x0c04de5eu: goto P_0c04de5e;
case 0x0c04de60u: goto P_0c04de60;
case 0x0c04de62u: goto P_0c04de62;
case 0x0c04de64u: goto P_0c04de64;
case 0x0c04de66u: goto P_0c04de66;
case 0x0c04de68u: goto P_0c04de68;
case 0x0c04de6au: goto P_0c04de6a;
case 0x0c04de6cu: goto P_0c04de6c;
case 0x0c04de6eu: goto P_0c04de6e;
case 0x0c04de70u: goto P_0c04de70;
case 0x0c04de72u: goto P_0c04de72;
case 0x0c04de74u: goto P_0c04de74;
case 0x0c04de76u: goto P_0c04de76;
case 0x0c04de78u: goto P_0c04de78;
case 0x0c04de7au: goto P_0c04de7a;
case 0x0c04de7cu: goto P_0c04de7c;
case 0x0c04de7eu: goto P_0c04de7e;
case 0x0c04de80u: goto P_0c04de80;
case 0x0c04de82u: goto P_0c04de82;
case 0x0c04de84u: goto P_0c04de84;
case 0x0c04de86u: goto P_0c04de86;
case 0x0c04de88u: goto P_0c04de88;
case 0x0c04de8au: goto P_0c04de8a;
case 0x0c04de8cu: goto P_0c04de8c;
case 0x0c04de8eu: goto P_0c04de8e;
case 0x0c04de90u: goto P_0c04de90;
case 0x0c04de92u: goto P_0c04de92;
case 0x0c04de94u: goto P_0c04de94;
case 0x0c04de96u: goto P_0c04de96;
case 0x0c04de98u: goto P_0c04de98;
case 0x0c04de9au: goto P_0c04de9a;
case 0x0c04de9cu: goto P_0c04de9c;
case 0x0c04de9eu: goto P_0c04de9e;
case 0x0c04dea0u: goto P_0c04dea0;
case 0x0c04dea2u: goto P_0c04dea2;
case 0x0c04dea4u: goto P_0c04dea4;
case 0x0c04dea6u: goto P_0c04dea6;
case 0x0c04dea8u: goto P_0c04dea8;
case 0x0c04deaau: goto P_0c04deaa;
case 0x0c04deacu: goto P_0c04deac;
case 0x0c04deaeu: goto P_0c04deae;
case 0x0c04deb0u: goto P_0c04deb0;
case 0x0c04deb2u: goto P_0c04deb2;
case 0x0c04deb4u: goto P_0c04deb4;
case 0x0c04dee4u: goto P_0c04dee4;
case 0x0c04dee6u: goto P_0c04dee6;
case 0x0c04dee8u: goto P_0c04dee8;
case 0x0c04deeau: goto P_0c04deea;
case 0x0c04deecu: goto P_0c04deec;
case 0x0c04deeeu: goto P_0c04deee;
case 0x0c04def0u: goto P_0c04def0;
case 0x0c04def2u: goto P_0c04def2;
case 0x0c04def4u: goto P_0c04def4;
case 0x0c04def6u: goto P_0c04def6;
case 0x0c04def8u: goto P_0c04def8;
case 0x0c04defau: goto P_0c04defa;
case 0x0c04defcu: goto P_0c04defc;
case 0x0c04defeu: goto P_0c04defe;
case 0x0c04df00u: goto P_0c04df00;
case 0x0c04df02u: goto P_0c04df02;
case 0x0c04df04u: goto P_0c04df04;
case 0x0c04df06u: goto P_0c04df06;
case 0x0c04df08u: goto P_0c04df08;
case 0x0c04df0au: goto P_0c04df0a;
case 0x0c04df0cu: goto P_0c04df0c;
case 0x0c04df0eu: goto P_0c04df0e;
case 0x0c04df10u: goto P_0c04df10;
case 0x0c04df12u: goto P_0c04df12;
case 0x0c04df14u: goto P_0c04df14;
case 0x0c04df16u: goto P_0c04df16;
case 0x0c04df18u: goto P_0c04df18;
case 0x0c04df1au: goto P_0c04df1a;
case 0x0c04df1cu: goto P_0c04df1c;
case 0x0c04df1eu: goto P_0c04df1e;
case 0x0c04df20u: goto P_0c04df20;
case 0x0c04df22u: goto P_0c04df22;
case 0x0c04df24u: goto P_0c04df24;
case 0x0c04df26u: goto P_0c04df26;
case 0x0c04df28u: goto P_0c04df28;
case 0x0c04df2au: goto P_0c04df2a;
case 0x0c04df2cu: goto P_0c04df2c;
case 0x0c04df2eu: goto P_0c04df2e;
case 0x0c04df30u: goto P_0c04df30;
case 0x0c04df32u: goto P_0c04df32;
case 0x0c04df34u: goto P_0c04df34;
case 0x0c04df36u: goto P_0c04df36;
case 0x0c04df38u: goto P_0c04df38;
case 0x0c04df3au: goto P_0c04df3a;
case 0x0c04df3cu: goto P_0c04df3c;
case 0x0c04df3eu: goto P_0c04df3e;
case 0x0c04df40u: goto P_0c04df40;
case 0x0c04df42u: goto P_0c04df42;
case 0x0c04df44u: goto P_0c04df44;
case 0x0c04df46u: goto P_0c04df46;
case 0x0c04df48u: goto P_0c04df48;
case 0x0c04df4au: goto P_0c04df4a;
case 0x0c04df4cu: goto P_0c04df4c;
case 0x0c04df4eu: goto P_0c04df4e;
case 0x0c04df50u: goto P_0c04df50;
case 0x0c04df52u: goto P_0c04df52;
case 0x0c04df54u: goto P_0c04df54;
case 0x0c04df56u: goto P_0c04df56;
case 0x0c04df58u: goto P_0c04df58;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04c3c6: /* original 2fe6, guest PC 0x0c04c3c6 */
if(!s->budget--) { s->failed_pc=0x0c04c3c6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c3c8;
P_0c04c3c8: /* original 6e43, guest PC 0x0c04c3c8 */
if(!s->budget--) { s->failed_pc=0x0c04c3c8u; return 0; }
r[14]=r[4];
goto P_0c04c3ca;
P_0c04c3ca: /* original 4e08, guest PC 0x0c04c3ca */
if(!s->budget--) { s->failed_pc=0x0c04c3cau; return 0; }
r[14]<<=2;
goto P_0c04c3cc;
P_0c04c3cc: /* original d318, guest PC 0x0c04c3cc */
if(!s->budget--) { s->failed_pc=0x0c04c3ccu; return 0; }
r[3]=read(ram,0x0c04c430u,4);
goto P_0c04c3ce;
P_0c04c3ce: /* original 4e08, guest PC 0x0c04c3ce */
if(!s->budget--) { s->failed_pc=0x0c04c3ceu; return 0; }
r[14]<<=2;
goto P_0c04c3d0;
P_0c04c3d0: /* original 4e08, guest PC 0x0c04c3d0 */
if(!s->budget--) { s->failed_pc=0x0c04c3d0u; return 0; }
r[14]<<=2;
goto P_0c04c3d2;
P_0c04c3d2: /* original 4e00, guest PC 0x0c04c3d2 */
if(!s->budget--) { s->failed_pc=0x0c04c3d2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c04c3d4;
P_0c04c3d4: /* original e078, guest PC 0x0c04c3d4 */
if(!s->budget--) { s->failed_pc=0x0c04c3d4u; return 0; }
r[0]=0x00000078u;
goto P_0c04c3d6;
P_0c04c3d6: /* original 3e3c, guest PC 0x0c04c3d6 */
if(!s->budget--) { s->failed_pc=0x0c04c3d6u; return 0; }
r[14]+=r[3];
goto P_0c04c3d8;
P_0c04c3d8: /* original 02ee, guest PC 0x0c04c3d8 */
if(!s->budget--) { s->failed_pc=0x0c04c3d8u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c04c3da;
P_0c04c3da: /* original 2228, guest PC 0x0c04c3da */
if(!s->budget--) { s->failed_pc=0x0c04c3dau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04c3dc;
P_0c04c3dc: /* original 8902, guest PC 0x0c04c3dc */
if(!s->budget--) { s->failed_pc=0x0c04c3dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c3e4; }
goto P_0c04c3de;
P_0c04c3de: /* original 02ee, guest PC 0x0c04c3de */
if(!s->budget--) { s->failed_pc=0x0c04c3deu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c04c3e0;
P_0c04c3e0: /* original 422b, guest PC 0x0c04c3e0 */
if(!s->budget--) { s->failed_pc=0x0c04c3e0u; return 0; }
target=r[2];
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
P_0c04c3e2: /* original 6ef6, guest PC 0x0c04c3e2 */
if(!s->budget--) { s->failed_pc=0x0c04c3e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04c3e4;
P_0c04c3e4: /* original 000b, guest PC 0x0c04c3e4 */
if(!s->budget--) { s->failed_pc=0x0c04c3e4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c3e6: /* original 6ef6, guest PC 0x0c04c3e6 */
if(!s->budget--) { s->failed_pc=0x0c04c3e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04c3e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c3e8u; return 0; } return 1;
P_0c04c5a0: /* original 2fe6, guest PC 0x0c04c5a0 */
if(!s->budget--) { s->failed_pc=0x0c04c5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c5a2;
P_0c04c5a2: /* original e503, guest PC 0x0c04c5a2 */
if(!s->budget--) { s->failed_pc=0x0c04c5a2u; return 0; }
r[5]=0x00000003u;
goto P_0c04c5a4;
P_0c04c5a4: /* original 4f22, guest PC 0x0c04c5a4 */
if(!s->budget--) { s->failed_pc=0x0c04c5a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c5a6;
P_0c04c5a6: /* original 60f3, guest PC 0x0c04c5a6 */
if(!s->budget--) { s->failed_pc=0x0c04c5a6u; return 0; }
r[0]=r[15];
goto P_0c04c5a8;
P_0c04c5a8: /* original 7008, guest PC 0x0c04c5a8 */
if(!s->budget--) { s->failed_pc=0x0c04c5a8u; return 0; }
r[0]+=0x00000008u;
goto P_0c04c5aa;
P_0c04c5aa: /* original 7004, guest PC 0x0c04c5aa */
if(!s->budget--) { s->failed_pc=0x0c04c5aau; return 0; }
r[0]+=0x00000004u;
goto P_0c04c5ac;
P_0c04c5ac: /* original 2508, guest PC 0x0c04c5ac */
if(!s->budget--) { s->failed_pc=0x0c04c5acu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c04c5ae;
P_0c04c5ae: /* original 8903, guest PC 0x0c04c5ae */
if(!s->budget--) { s->failed_pc=0x0c04c5aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c5b8; }
goto P_0c04c5b0;
P_0c04c5b0: /* original 65f3, guest PC 0x0c04c5b0 */
if(!s->budget--) { s->failed_pc=0x0c04c5b0u; return 0; }
r[5]=r[15];
goto P_0c04c5b2;
P_0c04c5b2: /* original 7508, guest PC 0x0c04c5b2 */
if(!s->budget--) { s->failed_pc=0x0c04c5b2u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5b4;
P_0c04c5b4: /* original a003, guest PC 0x0c04c5b4 */
if(!s->budget--) { s->failed_pc=0x0c04c5b4u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5be;
P_0c04c5b6: /* original 7508, guest PC 0x0c04c5b6 */
if(!s->budget--) { s->failed_pc=0x0c04c5b6u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5b8;
P_0c04c5b8: /* original 65f3, guest PC 0x0c04c5b8 */
if(!s->budget--) { s->failed_pc=0x0c04c5b8u; return 0; }
r[5]=r[15];
goto P_0c04c5ba;
P_0c04c5ba: /* original 7508, guest PC 0x0c04c5ba */
if(!s->budget--) { s->failed_pc=0x0c04c5bau; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5bc;
P_0c04c5bc: /* original 7504, guest PC 0x0c04c5bc */
if(!s->budget--) { s->failed_pc=0x0c04c5bcu; return 0; }
r[5]+=0x00000004u;
goto P_0c04c5be;
P_0c04c5be: /* original d335, guest PC 0x0c04c5be */
if(!s->budget--) { s->failed_pc=0x0c04c5beu; return 0; }
r[3]=read(ram,0x0c04c694u,4);
goto P_0c04c5c0;
P_0c04c5c0: /* original 6653, guest PC 0x0c04c5c0 */
if(!s->budget--) { s->failed_pc=0x0c04c5c0u; return 0; }
r[6]=r[5];
goto P_0c04c5c2;
P_0c04c5c2: /* original d433, guest PC 0x0c04c5c2 */
if(!s->budget--) { s->failed_pc=0x0c04c5c2u; return 0; }
r[4]=read(ram,0x0c04c690u,4);
goto P_0c04c5c4;
P_0c04c5c4: /* original 430b, guest PC 0x0c04c5c4 */
if(!s->budget--) { s->failed_pc=0x0c04c5c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c04c5c8u;
r[5]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c5c8u) { target=s->pc; goto dispatch; }
goto P_0c04c5c8;
P_0c04c5c6: /* original 55f2, guest PC 0x0c04c5c6 */
if(!s->budget--) { s->failed_pc=0x0c04c5c6u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c04c5c8;
P_0c04c5c8: /* original d233, guest PC 0x0c04c5c8 */
if(!s->budget--) { s->failed_pc=0x0c04c5c8u; return 0; }
r[2]=read(ram,0x0c04c698u,4);
goto P_0c04c5ca;
P_0c04c5ca: /* original 6e22, guest PC 0x0c04c5ca */
if(!s->budget--) { s->failed_pc=0x0c04c5cau; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c04c5cc;
P_0c04c5cc: /* original 2ee8, guest PC 0x0c04c5cc */
if(!s->budget--) { s->failed_pc=0x0c04c5ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04c5ce;
P_0c04c5ce: /* original 8902, guest PC 0x0c04c5ce */
if(!s->budget--) { s->failed_pc=0x0c04c5ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c5d6; }
goto P_0c04c5d0;
P_0c04c5d0: /* original d42f, guest PC 0x0c04c5d0 */
if(!s->budget--) { s->failed_pc=0x0c04c5d0u; return 0; }
r[4]=read(ram,0x0c04c690u,4);
goto P_0c04c5d2;
P_0c04c5d2: /* original 4e0b, guest PC 0x0c04c5d2 */
if(!s->budget--) { s->failed_pc=0x0c04c5d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c04c5d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c5d6u) { target=s->pc; goto dispatch; }
goto P_0c04c5d6;
P_0c04c5d4: /* original 0009, guest PC 0x0c04c5d4 */
if(!s->budget--) { s->failed_pc=0x0c04c5d4u; return 0; }
goto P_0c04c5d6;
P_0c04c5d6: /* original 4f26, guest PC 0x0c04c5d6 */
if(!s->budget--) { s->failed_pc=0x0c04c5d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c5d8;
P_0c04c5d8: /* original 000b, guest PC 0x0c04c5d8 */
if(!s->budget--) { s->failed_pc=0x0c04c5d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c5da: /* original 6ef6, guest PC 0x0c04c5da */
if(!s->budget--) { s->failed_pc=0x0c04c5dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04c5dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c5dcu; return 0; } return 1;
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
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04cee8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cee8u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c04cf0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04cf0eu; return 0; } return 1;
P_0c04d448: /* original 2fe6, guest PC 0x0c04d448 */
if(!s->budget--) { s->failed_pc=0x0c04d448u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d44a;
P_0c04d44a: /* original 6e43, guest PC 0x0c04d44a */
if(!s->budget--) { s->failed_pc=0x0c04d44au; return 0; }
r[14]=r[4];
goto P_0c04d44c;
P_0c04d44c: /* original 2fd6, guest PC 0x0c04d44c */
if(!s->budget--) { s->failed_pc=0x0c04d44cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d44e;
P_0c04d44e: /* original 6053, guest PC 0x0c04d44e */
if(!s->budget--) { s->failed_pc=0x0c04d44eu; return 0; }
r[0]=r[5];
goto P_0c04d450;
P_0c04d450: /* original 4f22, guest PC 0x0c04d450 */
if(!s->budget--) { s->failed_pc=0x0c04d450u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d452;
P_0c04d452: /* original 4f12, guest PC 0x0c04d452 */
if(!s->budget--) { s->failed_pc=0x0c04d452u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d454;
P_0c04d454: /* original 7ff8, guest PC 0x0c04d454 */
if(!s->budget--) { s->failed_pc=0x0c04d454u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04d456;
P_0c04d456: /* original 81f2, guest PC 0x0c04d456 */
if(!s->budget--) { s->failed_pc=0x0c04d456u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c04d458;
P_0c04d458: /* original 9d79, guest PC 0x0c04d458 */
if(!s->budget--) { s->failed_pc=0x0c04d458u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d54eu,2);
goto P_0c04d45a;
P_0c04d45a: /* original d33d, guest PC 0x0c04d45a */
if(!s->budget--) { s->failed_pc=0x0c04d45au; return 0; }
r[3]=read(ram,0x0c04d550u,4);
goto P_0c04d45c;
P_0c04d45c: /* original 2edf, guest PC 0x0c04d45c */
if(!s->budget--) { s->failed_pc=0x0c04d45cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c04d45e;
P_0c04d45e: /* original 85f2, guest PC 0x0c04d45e */
if(!s->budget--) { s->failed_pc=0x0c04d45eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04d460;
P_0c04d460: /* original 0d1a, guest PC 0x0c04d460 */
if(!s->budget--) { s->failed_pc=0x0c04d460u; return 0; }
r[13]=r[19];
goto P_0c04d462;
P_0c04d462: /* original 6ddf, guest PC 0x0c04d462 */
if(!s->budget--) { s->failed_pc=0x0c04d462u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04d464;
P_0c04d464: /* original 3d3c, guest PC 0x0c04d464 */
if(!s->budget--) { s->failed_pc=0x0c04d464u; return 0; }
r[13]+=r[3];
goto P_0c04d466;
P_0c04d466: /* original 54d7, guest PC 0x0c04d466 */
if(!s->budget--) { s->failed_pc=0x0c04d466u; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c04d468;
P_0c04d468: /* original 5542, guest PC 0x0c04d468 */
if(!s->budget--) { s->failed_pc=0x0c04d468u; return 0; }
r[5]=read(ram,r[4]+8,4);
goto P_0c04d46a;
P_0c04d46a: /* original 5244, guest PC 0x0c04d46a */
if(!s->budget--) { s->failed_pc=0x0c04d46au; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c04d46c;
P_0c04d46c: /* original 3528, guest PC 0x0c04d46c */
if(!s->budget--) { s->failed_pc=0x0c04d46cu; return 0; }
r[5]-=r[2];
goto P_0c04d46e;
P_0c04d46e: /* original 5246, guest PC 0x0c04d46e */
if(!s->budget--) { s->failed_pc=0x0c04d46eu; return 0; }
r[2]=read(ram,r[4]+24,4);
goto P_0c04d470;
P_0c04d470: /* original 6753, guest PC 0x0c04d470 */
if(!s->budget--) { s->failed_pc=0x0c04d470u; return 0; }
r[7]=r[5];
goto P_0c04d472;
P_0c04d472: /* original 6653, guest PC 0x0c04d472 */
if(!s->budget--) { s->failed_pc=0x0c04d472u; return 0; }
r[6]=r[5];
goto P_0c04d474;
P_0c04d474: /* original 6503, guest PC 0x0c04d474 */
if(!s->budget--) { s->failed_pc=0x0c04d474u; return 0; }
r[5]=r[0];
goto P_0c04d476;
P_0c04d476: /* original 3628, guest PC 0x0c04d476 */
if(!s->budget--) { s->failed_pc=0x0c04d476u; return 0; }
r[6]-=r[2];
goto P_0c04d478;
P_0c04d478: /* original 77ff, guest PC 0x0c04d478 */
if(!s->budget--) { s->failed_pc=0x0c04d478u; return 0; }
r[7]+=0xffffffffu;
goto P_0c04d47a;
P_0c04d47a: /* original b01b, guest PC 0x0c04d47a */
if(!s->budget--) { s->failed_pc=0x0c04d47au; return 0; }
target=code_base|0x0c04d4b4u; r[16]=code_base|0x0c04d47eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d47eu) { target=s->pc; goto dispatch; }
goto P_0c04d47e;
P_0c04d47c: /* original 64e3, guest PC 0x0c04d47c */
if(!s->budget--) { s->failed_pc=0x0c04d47cu; return 0; }
r[4]=r[14];
goto P_0c04d47e;
P_0c04d47e: /* original 4015, guest PC 0x0c04d47e */
if(!s->budget--) { s->failed_pc=0x0c04d47eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c04d480;
P_0c04d480: /* original 8d0f, guest PC 0x0c04d480 */
if(!s->budget--) { s->failed_pc=0x0c04d480u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04d4a2; }
goto P_0c04d484;
P_0c04d482: /* original 6403, guest PC 0x0c04d482 */
if(!s->budget--) { s->failed_pc=0x0c04d482u; return 0; }
r[4]=r[0];
goto P_0c04d484;
P_0c04d484: /* original 54d7, guest PC 0x0c04d484 */
if(!s->budget--) { s->failed_pc=0x0c04d484u; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c04d486;
P_0c04d486: /* original 5347, guest PC 0x0c04d486 */
if(!s->budget--) { s->failed_pc=0x0c04d486u; return 0; }
r[3]=read(ram,r[4]+28,4);
goto P_0c04d488;
P_0c04d488: /* original 2f32, guest PC 0x0c04d488 */
if(!s->budget--) { s->failed_pc=0x0c04d488u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04d48a;
P_0c04d48a: /* original 67f2, guest PC 0x0c04d48a */
if(!s->budget--) { s->failed_pc=0x0c04d48au; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c04d48c;
P_0c04d48c: /* original 5348, guest PC 0x0c04d48c */
if(!s->budget--) { s->failed_pc=0x0c04d48cu; return 0; }
r[3]=read(ram,r[4]+32,4);
goto P_0c04d48e;
P_0c04d48e: /* original 85f2, guest PC 0x0c04d48e */
if(!s->budget--) { s->failed_pc=0x0c04d48eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04d490;
P_0c04d490: /* original 66f2, guest PC 0x0c04d490 */
if(!s->budget--) { s->failed_pc=0x0c04d490u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04d492;
P_0c04d492: /* original 373c, guest PC 0x0c04d492 */
if(!s->budget--) { s->failed_pc=0x0c04d492u; return 0; }
r[7]+=r[3];
goto P_0c04d494;
P_0c04d494: /* original 6503, guest PC 0x0c04d494 */
if(!s->budget--) { s->failed_pc=0x0c04d494u; return 0; }
r[5]=r[0];
goto P_0c04d496;
P_0c04d496: /* original 77ff, guest PC 0x0c04d496 */
if(!s->budget--) { s->failed_pc=0x0c04d496u; return 0; }
r[7]+=0xffffffffu;
goto P_0c04d498;
P_0c04d498: /* original b00c, guest PC 0x0c04d498 */
if(!s->budget--) { s->failed_pc=0x0c04d498u; return 0; }
target=code_base|0x0c04d4b4u; r[16]=code_base|0x0c04d49cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d49cu) { target=s->pc; goto dispatch; }
goto P_0c04d49c;
P_0c04d49a: /* original 64e3, guest PC 0x0c04d49a */
if(!s->budget--) { s->failed_pc=0x0c04d49au; return 0; }
r[4]=r[14];
goto P_0c04d49c;
P_0c04d49c: /* original 4015, guest PC 0x0c04d49c */
if(!s->budget--) { s->failed_pc=0x0c04d49cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c04d49e;
P_0c04d49e: /* original 8f02, guest PC 0x0c04d49e */
if(!s->budget--) { s->failed_pc=0x0c04d49eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c04d4a6; }
goto P_0c04d4a2;
P_0c04d4a0: /* original 6403, guest PC 0x0c04d4a0 */
if(!s->budget--) { s->failed_pc=0x0c04d4a0u; return 0; }
r[4]=r[0];
goto P_0c04d4a2;
P_0c04d4a2: /* original a001, guest PC 0x0c04d4a2 */
if(!s->budget--) { s->failed_pc=0x0c04d4a2u; return 0; }
r[0]=r[4];
goto P_0c04d4a8;
P_0c04d4a4: /* original 6043, guest PC 0x0c04d4a4 */
if(!s->budget--) { s->failed_pc=0x0c04d4a4u; return 0; }
r[0]=r[4];
goto P_0c04d4a6;
P_0c04d4a6: /* original e0ff, guest PC 0x0c04d4a6 */
if(!s->budget--) { s->failed_pc=0x0c04d4a6u; return 0; }
r[0]=0xffffffffu;
goto P_0c04d4a8;
P_0c04d4a8: /* original 7f08, guest PC 0x0c04d4a8 */
if(!s->budget--) { s->failed_pc=0x0c04d4a8u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d4aa;
P_0c04d4aa: /* original 4f16, guest PC 0x0c04d4aa */
if(!s->budget--) { s->failed_pc=0x0c04d4aau; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d4ac;
P_0c04d4ac: /* original 4f26, guest PC 0x0c04d4ac */
if(!s->budget--) { s->failed_pc=0x0c04d4acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d4ae;
P_0c04d4ae: /* original 6df6, guest PC 0x0c04d4ae */
if(!s->budget--) { s->failed_pc=0x0c04d4aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d4b0;
P_0c04d4b0: /* original 000b, guest PC 0x0c04d4b0 */
if(!s->budget--) { s->failed_pc=0x0c04d4b0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d4b2: /* original 6ef6, guest PC 0x0c04d4b2 */
if(!s->budget--) { s->failed_pc=0x0c04d4b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04d4b4;
P_0c04d4b4: /* original 2fe6, guest PC 0x0c04d4b4 */
if(!s->budget--) { s->failed_pc=0x0c04d4b4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d4b6;
P_0c04d4b6: /* original 6e73, guest PC 0x0c04d4b6 */
if(!s->budget--) { s->failed_pc=0x0c04d4b6u; return 0; }
r[14]=r[7];
goto P_0c04d4b8;
P_0c04d4b8: /* original 2fd6, guest PC 0x0c04d4b8 */
if(!s->budget--) { s->failed_pc=0x0c04d4b8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d4ba;
P_0c04d4ba: /* original 6d63, guest PC 0x0c04d4ba */
if(!s->budget--) { s->failed_pc=0x0c04d4bau; return 0; }
r[13]=r[6];
goto P_0c04d4bc;
P_0c04d4bc: /* original 2fc6, guest PC 0x0c04d4bc */
if(!s->budget--) { s->failed_pc=0x0c04d4bcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d4be;
P_0c04d4be: /* original 3ed3, guest PC 0x0c04d4be */
if(!s->budget--) { s->failed_pc=0x0c04d4beu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c04d4c0;
P_0c04d4c0: /* original 2fb6, guest PC 0x0c04d4c0 */
if(!s->budget--) { s->failed_pc=0x0c04d4c0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d4c2;
P_0c04d4c2: /* original 4f22, guest PC 0x0c04d4c2 */
if(!s->budget--) { s->failed_pc=0x0c04d4c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d4c4;
P_0c04d4c4: /* original 4f12, guest PC 0x0c04d4c4 */
if(!s->budget--) { s->failed_pc=0x0c04d4c4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d4c6;
P_0c04d4c6: /* original 7ffc, guest PC 0x0c04d4c6 */
if(!s->budget--) { s->failed_pc=0x0c04d4c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04d4c8;
P_0c04d4c8: /* original 2f51, guest PC 0x0c04d4c8 */
if(!s->budget--) { s->failed_pc=0x0c04d4c8u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c04d4ca;
P_0c04d4ca: /* original 9c40, guest PC 0x0c04d4ca */
if(!s->budget--) { s->failed_pc=0x0c04d4cau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d54eu,2);
goto P_0c04d4cc;
P_0c04d4cc: /* original db21, guest PC 0x0c04d4cc */
if(!s->budget--) { s->failed_pc=0x0c04d4ccu; return 0; }
r[11]=read(ram,0x0c04d554u,4);
goto P_0c04d4ce;
P_0c04d4ce: /* original 24cf, guest PC 0x0c04d4ce */
if(!s->budget--) { s->failed_pc=0x0c04d4ceu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[12]);
goto P_0c04d4d0;
P_0c04d4d0: /* original d31f, guest PC 0x0c04d4d0 */
if(!s->budget--) { s->failed_pc=0x0c04d4d0u; return 0; }
r[3]=read(ram,0x0c04d550u,4);
goto P_0c04d4d2;
P_0c04d4d2: /* original 0c1a, guest PC 0x0c04d4d2 */
if(!s->budget--) { s->failed_pc=0x0c04d4d2u; return 0; }
r[12]=r[19];
goto P_0c04d4d4;
P_0c04d4d4: /* original 6ccf, guest PC 0x0c04d4d4 */
if(!s->budget--) { s->failed_pc=0x0c04d4d4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04d4d6;
P_0c04d4d6: /* original 8f10, guest PC 0x0c04d4d6 */
if(!s->budget--) { s->failed_pc=0x0c04d4d6u; return 0; }
cond=r[17]&1u;
r[12]+=r[3];
if(!cond) { goto P_0c04d4fa; }
goto P_0c04d4da;
P_0c04d4d8: /* original 3c3c, guest PC 0x0c04d4d8 */
if(!s->budget--) { s->failed_pc=0x0c04d4d8u; return 0; }
r[12]+=r[3];
goto P_0c04d4da;
P_0c04d4da: /* original 63b2, guest PC 0x0c04d4da */
if(!s->budget--) { s->failed_pc=0x0c04d4dau; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d4dc;
P_0c04d4dc: /* original 65e3, guest PC 0x0c04d4dc */
if(!s->budget--) { s->failed_pc=0x0c04d4dcu; return 0; }
r[5]=r[14];
goto P_0c04d4de;
P_0c04d4de: /* original 4500, guest PC 0x0c04d4de */
if(!s->budget--) { s->failed_pc=0x0c04d4deu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04d4e0;
P_0c04d4e0: /* original 5233, guest PC 0x0c04d4e0 */
if(!s->budget--) { s->failed_pc=0x0c04d4e0u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04d4e2;
P_0c04d4e2: /* original 420b, guest PC 0x0c04d4e2 */
if(!s->budget--) { s->failed_pc=0x0c04d4e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d4e6u;
r[4]=read(ram,r[12]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d4e6u) { target=s->pc; goto dispatch; }
goto P_0c04d4e6;
P_0c04d4e4: /* original 54c9, guest PC 0x0c04d4e4 */
if(!s->budget--) { s->failed_pc=0x0c04d4e4u; return 0; }
r[4]=read(ram,r[12]+36,4);
goto P_0c04d4e6;
P_0c04d4e6: /* original 63f1, guest PC 0x0c04d4e6 */
if(!s->budget--) { s->failed_pc=0x0c04d4e6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c04d4e8;
P_0c04d4e8: /* original 600d, guest PC 0x0c04d4e8 */
if(!s->budget--) { s->failed_pc=0x0c04d4e8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d4ea;
P_0c04d4ea: /* original 633d, guest PC 0x0c04d4ea */
if(!s->budget--) { s->failed_pc=0x0c04d4eau; return 0; }
r[3]=r[3]&65535u;
goto P_0c04d4ec;
P_0c04d4ec: /* original 3030, guest PC 0x0c04d4ec */
if(!s->budget--) { s->failed_pc=0x0c04d4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c04d4ee;
P_0c04d4ee: /* original 8b01, guest PC 0x0c04d4ee */
if(!s->budget--) { s->failed_pc=0x0c04d4eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d4f4; }
goto P_0c04d4f0;
P_0c04d4f0: /* original a004, guest PC 0x0c04d4f0 */
if(!s->budget--) { s->failed_pc=0x0c04d4f0u; return 0; }
r[0]=r[14];
goto P_0c04d4fc;
P_0c04d4f2: /* original 60e3, guest PC 0x0c04d4f2 */
if(!s->budget--) { s->failed_pc=0x0c04d4f2u; return 0; }
r[0]=r[14];
goto P_0c04d4f4;
P_0c04d4f4: /* original 7eff, guest PC 0x0c04d4f4 */
if(!s->budget--) { s->failed_pc=0x0c04d4f4u; return 0; }
r[14]+=0xffffffffu;
goto P_0c04d4f6;
P_0c04d4f6: /* original 3ed3, guest PC 0x0c04d4f6 */
if(!s->budget--) { s->failed_pc=0x0c04d4f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c04d4f8;
P_0c04d4f8: /* original 89ef, guest PC 0x0c04d4f8 */
if(!s->budget--) { s->failed_pc=0x0c04d4f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d4da; }
goto P_0c04d4fa;
P_0c04d4fa: /* original e0ff, guest PC 0x0c04d4fa */
if(!s->budget--) { s->failed_pc=0x0c04d4fau; return 0; }
r[0]=0xffffffffu;
goto P_0c04d4fc;
P_0c04d4fc: /* original 7f04, guest PC 0x0c04d4fc */
if(!s->budget--) { s->failed_pc=0x0c04d4fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c04d4fe;
P_0c04d4fe: /* original 4f16, guest PC 0x0c04d4fe */
if(!s->budget--) { s->failed_pc=0x0c04d4feu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d500;
P_0c04d500: /* original 4f26, guest PC 0x0c04d500 */
if(!s->budget--) { s->failed_pc=0x0c04d500u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d502;
P_0c04d502: /* original 6bf6, guest PC 0x0c04d502 */
if(!s->budget--) { s->failed_pc=0x0c04d502u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d504;
P_0c04d504: /* original 6cf6, guest PC 0x0c04d504 */
if(!s->budget--) { s->failed_pc=0x0c04d504u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d506;
P_0c04d506: /* original 6df6, guest PC 0x0c04d506 */
if(!s->budget--) { s->failed_pc=0x0c04d506u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d508;
P_0c04d508: /* original 000b, guest PC 0x0c04d508 */
if(!s->budget--) { s->failed_pc=0x0c04d508u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d50a: /* original 6ef6, guest PC 0x0c04d50a */
if(!s->budget--) { s->failed_pc=0x0c04d50au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04d50cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d50cu; return 0; } return 1;
P_0c04dd9c: /* original 2fe6, guest PC 0x0c04dd9c */
if(!s->budget--) { s->failed_pc=0x0c04dd9cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dd9e;
P_0c04dd9e: /* original 6e43, guest PC 0x0c04dd9e */
if(!s->budget--) { s->failed_pc=0x0c04dd9eu; return 0; }
r[14]=r[4];
goto P_0c04dda0;
P_0c04dda0: /* original 2fd6, guest PC 0x0c04dda0 */
if(!s->budget--) { s->failed_pc=0x0c04dda0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dda2;
P_0c04dda2: /* original 2fc6, guest PC 0x0c04dda2 */
if(!s->budget--) { s->failed_pc=0x0c04dda2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dda4;
P_0c04dda4: /* original 2fb6, guest PC 0x0c04dda4 */
if(!s->budget--) { s->failed_pc=0x0c04dda4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dda6;
P_0c04dda6: /* original 2fa6, guest PC 0x0c04dda6 */
if(!s->budget--) { s->failed_pc=0x0c04dda6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dda8;
P_0c04dda8: /* original 4f22, guest PC 0x0c04dda8 */
if(!s->budget--) { s->failed_pc=0x0c04dda8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ddaa;
P_0c04ddaa: /* original 4f12, guest PC 0x0c04ddaa */
if(!s->budget--) { s->failed_pc=0x0c04ddaau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ddac;
P_0c04ddac: /* original 7ffc, guest PC 0x0c04ddac */
if(!s->budget--) { s->failed_pc=0x0c04ddacu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04ddae;
P_0c04ddae: /* original 2f52, guest PC 0x0c04ddae */
if(!s->budget--) { s->failed_pc=0x0c04ddaeu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04ddb0;
P_0c04ddb0: /* original d342, guest PC 0x0c04ddb0 */
if(!s->budget--) { s->failed_pc=0x0c04ddb0u; return 0; }
r[3]=read(ram,0x0c04debcu,4);
goto P_0c04ddb2;
P_0c04ddb2: /* original d243, guest PC 0x0c04ddb2 */
if(!s->budget--) { s->failed_pc=0x0c04ddb2u; return 0; }
r[2]=read(ram,0x0c04dec0u,4);
goto P_0c04ddb4;
P_0c04ddb4: /* original 420b, guest PC 0x0c04ddb4 */
if(!s->budget--) { s->failed_pc=0x0c04ddb4u; return 0; }
target=r[2];
r[16]=code_base|0x0c04ddb8u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ddb8u) { target=s->pc; goto dispatch; }
goto P_0c04ddb8;
P_0c04ddb6: /* original 2f36, guest PC 0x0c04ddb6 */
if(!s->budget--) { s->failed_pc=0x0c04ddb6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ddb8;
P_0c04ddb8: /* original 2ee8, guest PC 0x0c04ddb8 */
if(!s->budget--) { s->failed_pc=0x0c04ddb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04ddba;
P_0c04ddba: /* original 8f03, guest PC 0x0c04ddba */
if(!s->budget--) { s->failed_pc=0x0c04ddbau; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c04ddc4; }
goto P_0c04ddbe;
P_0c04ddbc: /* original 7f04, guest PC 0x0c04ddbc */
if(!s->budget--) { s->failed_pc=0x0c04ddbcu; return 0; }
r[15]+=0x00000004u;
goto P_0c04ddbe;
P_0c04ddbe: /* original 907a, guest PC 0x0c04ddbe */
if(!s->budget--) { s->failed_pc=0x0c04ddbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04deb6u,2);
goto P_0c04ddc0;
P_0c04ddc0: /* original a0c2, guest PC 0x0c04ddc0 */
if(!s->budget--) { s->failed_pc=0x0c04ddc0u; return 0; }
goto P_0c04df48;
P_0c04ddc2: /* original 0009, guest PC 0x0c04ddc2 */
if(!s->budget--) { s->failed_pc=0x0c04ddc2u; return 0; }
goto P_0c04ddc4;
P_0c04ddc4: /* original 53ea, guest PC 0x0c04ddc4 */
if(!s->budget--) { s->failed_pc=0x0c04ddc4u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c04ddc6;
P_0c04ddc6: /* original eb00, guest PC 0x0c04ddc6 */
if(!s->budget--) { s->failed_pc=0x0c04ddc6u; return 0; }
r[11]=0x00000000u;
goto P_0c04ddc8;
P_0c04ddc8: /* original 9276, guest PC 0x0c04ddc8 */
if(!s->budget--) { s->failed_pc=0x0c04ddc8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04deb8u,2);
goto P_0c04ddca;
P_0c04ddca: /* original da3e, guest PC 0x0c04ddca */
if(!s->budget--) { s->failed_pc=0x0c04ddcau; return 0; }
r[10]=read(ram,0x0c04dec4u,4);
goto P_0c04ddcc;
P_0c04ddcc: /* original 232f, guest PC 0x0c04ddcc */
if(!s->budget--) { s->failed_pc=0x0c04ddccu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[3]*(int32_t)(int16_t)r[2]);
goto P_0c04ddce;
P_0c04ddce: /* original 031a, guest PC 0x0c04ddce */
if(!s->budget--) { s->failed_pc=0x0c04ddceu; return 0; }
r[3]=r[19];
goto P_0c04ddd0;
P_0c04ddd0: /* original 633f, guest PC 0x0c04ddd0 */
if(!s->budget--) { s->failed_pc=0x0c04ddd0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04ddd2;
P_0c04ddd2: /* original 33ac, guest PC 0x0c04ddd2 */
if(!s->budget--) { s->failed_pc=0x0c04ddd2u; return 0; }
r[3]+=r[10];
goto P_0c04ddd4;
P_0c04ddd4: /* original 8432, guest PC 0x0c04ddd4 */
if(!s->budget--) { s->failed_pc=0x0c04ddd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c04ddd6;
P_0c04ddd6: /* original 2008, guest PC 0x0c04ddd6 */
if(!s->budget--) { s->failed_pc=0x0c04ddd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ddd8;
P_0c04ddd8: /* original 8f02, guest PC 0x0c04ddd8 */
if(!s->budget--) { s->failed_pc=0x0c04ddd8u; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(!cond) { goto P_0c04dde0; }
goto P_0c04dddc;
P_0c04ddda: /* original 6db3, guest PC 0x0c04ddda */
if(!s->budget--) { s->failed_pc=0x0c04dddau; return 0; }
r[13]=r[11];
goto P_0c04dddc;
P_0c04dddc: /* original a0b0, guest PC 0x0c04dddc */
if(!s->budget--) { s->failed_pc=0x0c04dddcu; return 0; }
goto P_0c04df40;
P_0c04ddde: /* original 0009, guest PC 0x0c04ddde */
if(!s->budget--) { s->failed_pc=0x0c04dddeu; return 0; }
goto P_0c04dde0;
P_0c04dde0: /* original d339, guest PC 0x0c04dde0 */
if(!s->budget--) { s->failed_pc=0x0c04dde0u; return 0; }
r[3]=read(ram,0x0c04dec8u,4);
goto P_0c04dde2;
P_0c04dde2: /* original 430b, guest PC 0x0c04dde2 */
if(!s->budget--) { s->failed_pc=0x0c04dde2u; return 0; }
target=r[3];
r[16]=code_base|0x0c04dde6u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dde6u) { target=s->pc; goto dispatch; }
goto P_0c04dde6;
P_0c04dde4: /* original 54ea, guest PC 0x0c04dde4 */
if(!s->budget--) { s->failed_pc=0x0c04dde4u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04dde6;
P_0c04dde6: /* original 2008, guest PC 0x0c04dde6 */
if(!s->budget--) { s->failed_pc=0x0c04dde6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04dde8;
P_0c04dde8: /* original 8b01, guest PC 0x0c04dde8 */
if(!s->budget--) { s->failed_pc=0x0c04dde8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ddee; }
goto P_0c04ddea;
P_0c04ddea: /* original a0a9, guest PC 0x0c04ddea */
if(!s->budget--) { s->failed_pc=0x0c04ddeau; return 0; }
goto P_0c04df40;
P_0c04ddec: /* original 0009, guest PC 0x0c04ddec */
if(!s->budget--) { s->failed_pc=0x0c04ddecu; return 0; }
goto P_0c04ddee;
P_0c04ddee: /* original 9363, guest PC 0x0c04ddee */
if(!s->budget--) { s->failed_pc=0x0c04ddeeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04deb8u,2);
goto P_0c04ddf0;
P_0c04ddf0: /* original 52ea, guest PC 0x0c04ddf0 */
if(!s->budget--) { s->failed_pc=0x0c04ddf0u; return 0; }
r[2]=read(ram,r[14]+40,4);
goto P_0c04ddf2;
P_0c04ddf2: /* original 223f, guest PC 0x0c04ddf2 */
if(!s->budget--) { s->failed_pc=0x0c04ddf2u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[3]);
goto P_0c04ddf4;
P_0c04ddf4: /* original 021a, guest PC 0x0c04ddf4 */
if(!s->budget--) { s->failed_pc=0x0c04ddf4u; return 0; }
r[2]=r[19];
goto P_0c04ddf6;
P_0c04ddf6: /* original 622f, guest PC 0x0c04ddf6 */
if(!s->budget--) { s->failed_pc=0x0c04ddf6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04ddf8;
P_0c04ddf8: /* original 32ac, guest PC 0x0c04ddf8 */
if(!s->budget--) { s->failed_pc=0x0c04ddf8u; return 0; }
r[2]+=r[10];
goto P_0c04ddfa;
P_0c04ddfa: /* original 8428, guest PC 0x0c04ddfa */
if(!s->budget--) { s->failed_pc=0x0c04ddfau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04ddfc;
P_0c04ddfc: /* original 2008, guest PC 0x0c04ddfc */
if(!s->budget--) { s->failed_pc=0x0c04ddfcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ddfe;
P_0c04ddfe: /* original 8b01, guest PC 0x0c04ddfe */
if(!s->budget--) { s->failed_pc=0x0c04ddfeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04de04; }
goto P_0c04de00;
P_0c04de00: /* original a09e, guest PC 0x0c04de00 */
if(!s->budget--) { s->failed_pc=0x0c04de00u; return 0; }
goto P_0c04df40;
P_0c04de02: /* original 0009, guest PC 0x0c04de02 */
if(!s->budget--) { s->failed_pc=0x0c04de02u; return 0; }
goto P_0c04de04;
P_0c04de04: /* original d331, guest PC 0x0c04de04 */
if(!s->budget--) { s->failed_pc=0x0c04de04u; return 0; }
r[3]=read(ram,0x0c04deccu,4);
goto P_0c04de06;
P_0c04de06: /* original 430b, guest PC 0x0c04de06 */
if(!s->budget--) { s->failed_pc=0x0c04de06u; return 0; }
target=r[3];
r[16]=code_base|0x0c04de0au;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04de0au) { target=s->pc; goto dispatch; }
goto P_0c04de0a;
P_0c04de08: /* original 54ea, guest PC 0x0c04de08 */
if(!s->budget--) { s->failed_pc=0x0c04de08u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04de0a;
P_0c04de0a: /* original 2008, guest PC 0x0c04de0a */
if(!s->budget--) { s->failed_pc=0x0c04de0au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04de0c;
P_0c04de0c: /* original 8b03, guest PC 0x0c04de0c */
if(!s->budget--) { s->failed_pc=0x0c04de0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04de16; }
goto P_0c04de0e;
P_0c04de0e: /* original b85e, guest PC 0x0c04de0e */
if(!s->budget--) { s->failed_pc=0x0c04de0eu; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04de12u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04de12u) { target=s->pc; goto dispatch; }
goto P_0c04de12;
P_0c04de10: /* original 54ea, guest PC 0x0c04de10 */
if(!s->budget--) { s->failed_pc=0x0c04de10u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04de12;
P_0c04de12: /* original a095, guest PC 0x0c04de12 */
if(!s->budget--) { s->failed_pc=0x0c04de12u; return 0; }
goto P_0c04df40;
P_0c04de14: /* original 0009, guest PC 0x0c04de14 */
if(!s->budget--) { s->failed_pc=0x0c04de14u; return 0; }
goto P_0c04de16;
P_0c04de16: /* original d32e, guest PC 0x0c04de16 */
if(!s->budget--) { s->failed_pc=0x0c04de16u; return 0; }
r[3]=read(ram,0x0c04ded0u,4);
goto P_0c04de18;
P_0c04de18: /* original 430b, guest PC 0x0c04de18 */
if(!s->budget--) { s->failed_pc=0x0c04de18u; return 0; }
target=r[3];
r[16]=code_base|0x0c04de1cu;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04de1cu) { target=s->pc; goto dispatch; }
goto P_0c04de1c;
P_0c04de1a: /* original 54ea, guest PC 0x0c04de1a */
if(!s->budget--) { s->failed_pc=0x0c04de1au; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04de1c;
P_0c04de1c: /* original 4011, guest PC 0x0c04de1c */
if(!s->budget--) { s->failed_pc=0x0c04de1cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04de1e;
P_0c04de1e: /* original 8901, guest PC 0x0c04de1e */
if(!s->budget--) { s->failed_pc=0x0c04de1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04de24; }
goto P_0c04de20;
P_0c04de20: /* original a08e, guest PC 0x0c04de20 */
if(!s->budget--) { s->failed_pc=0x0c04de20u; return 0; }
goto P_0c04df40;
P_0c04de22: /* original 0009, guest PC 0x0c04de22 */
if(!s->budget--) { s->failed_pc=0x0c04de22u; return 0; }
goto P_0c04de24;
P_0c04de24: /* original 52e1, guest PC 0x0c04de24 */
if(!s->budget--) { s->failed_pc=0x0c04de24u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c04de26;
P_0c04de26: /* original 2228, guest PC 0x0c04de26 */
if(!s->budget--) { s->failed_pc=0x0c04de26u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04de28;
P_0c04de28: /* original 8f02, guest PC 0x0c04de28 */
if(!s->budget--) { s->failed_pc=0x0c04de28u; return 0; }
cond=r[17]&1u;
r[12]=read(ram,r[14]+40,4);
if(!cond) { goto P_0c04de30; }
goto P_0c04de2c;
P_0c04de2a: /* original 5cea, guest PC 0x0c04de2a */
if(!s->budget--) { s->failed_pc=0x0c04de2au; return 0; }
r[12]=read(ram,r[14]+40,4);
goto P_0c04de2c;
P_0c04de2c: /* original a087, guest PC 0x0c04de2c */
if(!s->budget--) { s->failed_pc=0x0c04de2cu; return 0; }
goto P_0c04df3e;
P_0c04de2e: /* original 0009, guest PC 0x0c04de2e */
if(!s->budget--) { s->failed_pc=0x0c04de2eu; return 0; }
goto P_0c04de30;
P_0c04de30: /* original d223, guest PC 0x0c04de30 */
if(!s->budget--) { s->failed_pc=0x0c04de30u; return 0; }
r[2]=read(ram,0x0c04dec0u,4);
goto P_0c04de32;
P_0c04de32: /* original d328, guest PC 0x0c04de32 */
if(!s->budget--) { s->failed_pc=0x0c04de32u; return 0; }
r[3]=read(ram,0x0c04ded4u,4);
goto P_0c04de34;
P_0c04de34: /* original 420b, guest PC 0x0c04de34 */
if(!s->budget--) { s->failed_pc=0x0c04de34u; return 0; }
target=r[2];
r[16]=code_base|0x0c04de38u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04de38u) { target=s->pc; goto dispatch; }
goto P_0c04de38;
P_0c04de36: /* original 2f36, guest PC 0x0c04de36 */
if(!s->budget--) { s->failed_pc=0x0c04de36u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04de38;
P_0c04de38: /* original 7f04, guest PC 0x0c04de38 */
if(!s->budget--) { s->failed_pc=0x0c04de38u; return 0; }
r[15]+=0x00000004u;
goto P_0c04de3a;
P_0c04de3a: /* original 61f2, guest PC 0x0c04de3a */
if(!s->budget--) { s->failed_pc=0x0c04de3au; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c04de3c;
P_0c04de3c: /* original 2118, guest PC 0x0c04de3c */
if(!s->budget--) { s->failed_pc=0x0c04de3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04de3e;
P_0c04de3e: /* original 8910, guest PC 0x0c04de3e */
if(!s->budget--) { s->failed_pc=0x0c04de3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04de62; }
goto P_0c04de40;
P_0c04de40: /* original 943a, guest PC 0x0c04de40 */
if(!s->budget--) { s->failed_pc=0x0c04de40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04deb8u,2);
goto P_0c04de42;
P_0c04de42: /* original e301, guest PC 0x0c04de42 */
if(!s->budget--) { s->failed_pc=0x0c04de42u; return 0; }
r[3]=0x00000001u;
goto P_0c04de44;
P_0c04de44: /* original 2c4f, guest PC 0x0c04de44 */
if(!s->budget--) { s->failed_pc=0x0c04de44u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[4]);
goto P_0c04de46;
P_0c04de46: /* original 041a, guest PC 0x0c04de46 */
if(!s->budget--) { s->failed_pc=0x0c04de46u; return 0; }
r[4]=r[19];
goto P_0c04de48;
P_0c04de48: /* original 644f, guest PC 0x0c04de48 */
if(!s->budget--) { s->failed_pc=0x0c04de48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04de4a;
P_0c04de4a: /* original 34ac, guest PC 0x0c04de4a */
if(!s->budget--) { s->failed_pc=0x0c04de4au; return 0; }
r[4]+=r[10];
goto P_0c04de4c;
P_0c04de4c: /* original 143c, guest PC 0x0c04de4c */
if(!s->budget--) { s->failed_pc=0x0c04de4cu; return 0; }
write(ram,r[4]+48,r[3],4);
goto P_0c04de4e;
P_0c04de4e: /* original 5241, guest PC 0x0c04de4e */
if(!s->budget--) { s->failed_pc=0x0c04de4eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c04de50;
P_0c04de50: /* original d021, guest PC 0x0c04de50 */
if(!s->budget--) { s->failed_pc=0x0c04de50u; return 0; }
r[0]=read(ram,0x0c04ded8u,4);
goto P_0c04de52;
P_0c04de52: /* original 6323, guest PC 0x0c04de52 */
if(!s->budget--) { s->failed_pc=0x0c04de52u; return 0; }
r[3]=r[2];
goto P_0c04de54;
P_0c04de54: /* original 4208, guest PC 0x0c04de54 */
if(!s->budget--) { s->failed_pc=0x0c04de54u; return 0; }
r[2]<<=2;
goto P_0c04de56;
P_0c04de56: /* original 323c, guest PC 0x0c04de56 */
if(!s->budget--) { s->failed_pc=0x0c04de56u; return 0; }
r[2]+=r[3];
goto P_0c04de58;
P_0c04de58: /* original 4208, guest PC 0x0c04de58 */
if(!s->budget--) { s->failed_pc=0x0c04de58u; return 0; }
r[2]<<=2;
goto P_0c04de5a;
P_0c04de5a: /* original 4208, guest PC 0x0c04de5a */
if(!s->budget--) { s->failed_pc=0x0c04de5au; return 0; }
r[2]<<=2;
goto P_0c04de5c;
P_0c04de5c: /* original 622f, guest PC 0x0c04de5c */
if(!s->budget--) { s->failed_pc=0x0c04de5cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04de5e;
P_0c04de5e: /* original 012e, guest PC 0x0c04de5e */
if(!s->budget--) { s->failed_pc=0x0c04de5eu; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c04de60;
P_0c04de60: /* original 141d, guest PC 0x0c04de60 */
if(!s->budget--) { s->failed_pc=0x0c04de60u; return 0; }
write(ram,r[4]+52,r[1],4);
goto P_0c04de62;
P_0c04de62: /* original d31e, guest PC 0x0c04de62 */
if(!s->budget--) { s->failed_pc=0x0c04de62u; return 0; }
r[3]=read(ram,0x0c04dedcu,4);
goto P_0c04de64;
P_0c04de64: /* original 55eb, guest PC 0x0c04de64 */
if(!s->budget--) { s->failed_pc=0x0c04de64u; return 0; }
r[5]=read(ram,r[14]+44,4);
goto P_0c04de66;
P_0c04de66: /* original 430b, guest PC 0x0c04de66 */
if(!s->budget--) { s->failed_pc=0x0c04de66u; return 0; }
target=r[3];
r[16]=code_base|0x0c04de6au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04de6au) { target=s->pc; goto dispatch; }
goto P_0c04de6a;
P_0c04de68: /* original 64c3, guest PC 0x0c04de68 */
if(!s->budget--) { s->failed_pc=0x0c04de68u; return 0; }
r[4]=r[12];
goto P_0c04de6a;
P_0c04de6a: /* original 6d03, guest PC 0x0c04de6a */
if(!s->budget--) { s->failed_pc=0x0c04de6au; return 0; }
r[13]=r[0];
goto P_0c04de6c;
P_0c04de6c: /* original 50e2, guest PC 0x0c04de6c */
if(!s->budget--) { s->failed_pc=0x0c04de6cu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c04de6e;
P_0c04de6e: /* original 8801, guest PC 0x0c04de6e */
if(!s->budget--) { s->failed_pc=0x0c04de6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04de70;
P_0c04de70: /* original 8b02, guest PC 0x0c04de70 */
if(!s->budget--) { s->failed_pc=0x0c04de70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04de78; }
goto P_0c04de72;
P_0c04de72: /* original 9422, guest PC 0x0c04de72 */
if(!s->budget--) { s->failed_pc=0x0c04de72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04debau,2);
goto P_0c04de74;
P_0c04de74: /* original a001, guest PC 0x0c04de74 */
if(!s->budget--) { s->failed_pc=0x0c04de74u; return 0; }
goto P_0c04de7a;
P_0c04de76: /* original 0009, guest PC 0x0c04de76 */
if(!s->budget--) { s->failed_pc=0x0c04de76u; return 0; }
goto P_0c04de78;
P_0c04de78: /* original e433, guest PC 0x0c04de78 */
if(!s->budget--) { s->failed_pc=0x0c04de78u; return 0; }
r[4]=0x00000033u;
goto P_0c04de7a;
P_0c04de7a: /* original e502, guest PC 0x0c04de7a */
if(!s->budget--) { s->failed_pc=0x0c04de7au; return 0; }
r[5]=0x00000002u;
goto P_0c04de7c;
P_0c04de7c: /* original 2d40, guest PC 0x0c04de7c */
if(!s->budget--) { s->failed_pc=0x0c04de7cu; return 0; }
write(ram,r[13],r[4],1);
goto P_0c04de7e;
P_0c04de7e: /* original 84e1, guest PC 0x0c04de7e */
if(!s->budget--) { s->failed_pc=0x0c04de7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c04de80;
P_0c04de80: /* original 80d1, guest PC 0x0c04de80 */
if(!s->budget--) { s->failed_pc=0x0c04de80u; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c04de82;
P_0c04de82: /* original da17, guest PC 0x0c04de82 */
if(!s->budget--) { s->failed_pc=0x0c04de82u; return 0; }
r[10]=read(ram,0x0c04dee0u,4);
goto P_0c04de84;
P_0c04de84: /* original 56ee, guest PC 0x0c04de84 */
if(!s->budget--) { s->failed_pc=0x0c04de84u; return 0; }
r[6]=read(ram,r[14]+56,4);
goto P_0c04de86;
P_0c04de86: /* original 63a2, guest PC 0x0c04de86 */
if(!s->budget--) { s->failed_pc=0x0c04de86u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c04de88;
P_0c04de88: /* original 5234, guest PC 0x0c04de88 */
if(!s->budget--) { s->failed_pc=0x0c04de88u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04de8a;
P_0c04de8a: /* original 420b, guest PC 0x0c04de8a */
if(!s->budget--) { s->failed_pc=0x0c04de8au; return 0; }
target=r[2];
r[16]=code_base|0x0c04de8eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04de8eu) { target=s->pc; goto dispatch; }
goto P_0c04de8e;
P_0c04de8c: /* original 64d3, guest PC 0x0c04de8c */
if(!s->budget--) { s->failed_pc=0x0c04de8cu; return 0; }
r[4]=r[13];
goto P_0c04de8e;
P_0c04de8e: /* original 63a2, guest PC 0x0c04de8e */
if(!s->budget--) { s->failed_pc=0x0c04de8eu; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c04de90;
P_0c04de90: /* original e518, guest PC 0x0c04de90 */
if(!s->budget--) { s->failed_pc=0x0c04de90u; return 0; }
r[5]=0x00000018u;
goto P_0c04de92;
P_0c04de92: /* original 56ec, guest PC 0x0c04de92 */
if(!s->budget--) { s->failed_pc=0x0c04de92u; return 0; }
r[6]=read(ram,r[14]+48,4);
goto P_0c04de94;
P_0c04de94: /* original 5234, guest PC 0x0c04de94 */
if(!s->budget--) { s->failed_pc=0x0c04de94u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04de96;
P_0c04de96: /* original 420b, guest PC 0x0c04de96 */
if(!s->budget--) { s->failed_pc=0x0c04de96u; return 0; }
target=r[2];
r[16]=code_base|0x0c04de9au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04de9au) { target=s->pc; goto dispatch; }
goto P_0c04de9a;
P_0c04de98: /* original 64d3, guest PC 0x0c04de98 */
if(!s->budget--) { s->failed_pc=0x0c04de98u; return 0; }
r[4]=r[13];
goto P_0c04de9a;
P_0c04de9a: /* original 63a2, guest PC 0x0c04de9a */
if(!s->budget--) { s->failed_pc=0x0c04de9au; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c04de9c;
P_0c04de9c: /* original e51a, guest PC 0x0c04de9c */
if(!s->budget--) { s->failed_pc=0x0c04de9cu; return 0; }
r[5]=0x0000001au;
goto P_0c04de9e;
P_0c04de9e: /* original 85e1, guest PC 0x0c04de9e */
if(!s->budget--) { s->failed_pc=0x0c04de9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c04dea0;
P_0c04dea0: /* original 5234, guest PC 0x0c04dea0 */
if(!s->budget--) { s->failed_pc=0x0c04dea0u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04dea2;
P_0c04dea2: /* original 6603, guest PC 0x0c04dea2 */
if(!s->budget--) { s->failed_pc=0x0c04dea2u; return 0; }
r[6]=r[0];
goto P_0c04dea4;
P_0c04dea4: /* original 420b, guest PC 0x0c04dea4 */
if(!s->budget--) { s->failed_pc=0x0c04dea4u; return 0; }
target=r[2];
r[16]=code_base|0x0c04dea8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dea8u) { target=s->pc; goto dispatch; }
goto P_0c04dea8;
P_0c04dea6: /* original 64d3, guest PC 0x0c04dea6 */
if(!s->budget--) { s->failed_pc=0x0c04dea6u; return 0; }
r[4]=r[13];
goto P_0c04dea8;
P_0c04dea8: /* original 67e3, guest PC 0x0c04dea8 */
if(!s->budget--) { s->failed_pc=0x0c04dea8u; return 0; }
r[7]=r[14];
goto P_0c04deaa;
P_0c04deaa: /* original e60c, guest PC 0x0c04deaa */
if(!s->budget--) { s->failed_pc=0x0c04deaau; return 0; }
r[6]=0x0000000cu;
goto P_0c04deac;
P_0c04deac: /* original 64d3, guest PC 0x0c04deac */
if(!s->budget--) { s->failed_pc=0x0c04deacu; return 0; }
r[4]=r[13];
goto P_0c04deae;
P_0c04deae: /* original 65b3, guest PC 0x0c04deae */
if(!s->budget--) { s->failed_pc=0x0c04deaeu; return 0; }
r[5]=r[11];
goto P_0c04deb0;
P_0c04deb0: /* original 7710, guest PC 0x0c04deb0 */
if(!s->budget--) { s->failed_pc=0x0c04deb0u; return 0; }
r[7]+=0x00000010u;
goto P_0c04deb2;
P_0c04deb2: /* original a01b, guest PC 0x0c04deb2 */
if(!s->budget--) { s->failed_pc=0x0c04deb2u; return 0; }
r[4]+=0x00000004u;
goto P_0c04deec;
P_0c04deb4: /* original 7404, guest PC 0x0c04deb4 */
if(!s->budget--) { s->failed_pc=0x0c04deb4u; return 0; }
r[4]+=0x00000004u;
if(!vf3_matrix_family(0x0c04deb6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04deb6u; return 0; } return 1;
P_0c04dee4: /* original 6374, guest PC 0x0c04dee4 */
if(!s->budget--) { s->failed_pc=0x0c04dee4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04dee6;
P_0c04dee6: /* original 7501, guest PC 0x0c04dee6 */
if(!s->budget--) { s->failed_pc=0x0c04dee6u; return 0; }
r[5]+=0x00000001u;
goto P_0c04dee8;
P_0c04dee8: /* original 2430, guest PC 0x0c04dee8 */
if(!s->budget--) { s->failed_pc=0x0c04dee8u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04deea;
P_0c04deea: /* original 7401, guest PC 0x0c04deea */
if(!s->budget--) { s->failed_pc=0x0c04deeau; return 0; }
r[4]+=0x00000001u;
goto P_0c04deec;
P_0c04deec: /* original 3563, guest PC 0x0c04deec */
if(!s->budget--) { s->failed_pc=0x0c04deecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04deee;
P_0c04deee: /* original 8bf9, guest PC 0x0c04deee */
if(!s->budget--) { s->failed_pc=0x0c04deeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dee4; }
goto P_0c04def0;
P_0c04def0: /* original 67e3, guest PC 0x0c04def0 */
if(!s->budget--) { s->failed_pc=0x0c04def0u; return 0; }
r[7]=r[14];
goto P_0c04def2;
P_0c04def2: /* original e608, guest PC 0x0c04def2 */
if(!s->budget--) { s->failed_pc=0x0c04def2u; return 0; }
r[6]=0x00000008u;
goto P_0c04def4;
P_0c04def4: /* original 64d3, guest PC 0x0c04def4 */
if(!s->budget--) { s->failed_pc=0x0c04def4u; return 0; }
r[4]=r[13];
goto P_0c04def6;
P_0c04def6: /* original 65b3, guest PC 0x0c04def6 */
if(!s->budget--) { s->failed_pc=0x0c04def6u; return 0; }
r[5]=r[11];
goto P_0c04def8;
P_0c04def8: /* original 7720, guest PC 0x0c04def8 */
if(!s->budget--) { s->failed_pc=0x0c04def8u; return 0; }
r[7]+=0x00000020u;
goto P_0c04defa;
P_0c04defa: /* original a004, guest PC 0x0c04defa */
if(!s->budget--) { s->failed_pc=0x0c04defau; return 0; }
r[4]+=0x00000010u;
goto P_0c04df06;
P_0c04defc: /* original 7410, guest PC 0x0c04defc */
if(!s->budget--) { s->failed_pc=0x0c04defcu; return 0; }
r[4]+=0x00000010u;
goto P_0c04defe;
P_0c04defe: /* original 6374, guest PC 0x0c04defe */
if(!s->budget--) { s->failed_pc=0x0c04defeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04df00;
P_0c04df00: /* original 7501, guest PC 0x0c04df00 */
if(!s->budget--) { s->failed_pc=0x0c04df00u; return 0; }
r[5]+=0x00000001u;
goto P_0c04df02;
P_0c04df02: /* original 2430, guest PC 0x0c04df02 */
if(!s->budget--) { s->failed_pc=0x0c04df02u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04df04;
P_0c04df04: /* original 7401, guest PC 0x0c04df04 */
if(!s->budget--) { s->failed_pc=0x0c04df04u; return 0; }
r[4]+=0x00000001u;
goto P_0c04df06;
P_0c04df06: /* original 3563, guest PC 0x0c04df06 */
if(!s->budget--) { s->failed_pc=0x0c04df06u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04df08;
P_0c04df08: /* original 8bf9, guest PC 0x0c04df08 */
if(!s->budget--) { s->failed_pc=0x0c04df08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04defe; }
goto P_0c04df0a;
P_0c04df0a: /* original 53ee, guest PC 0x0c04df0a */
if(!s->budget--) { s->failed_pc=0x0c04df0au; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c04df0c;
P_0c04df0c: /* original 2f36, guest PC 0x0c04df0c */
if(!s->budget--) { s->failed_pc=0x0c04df0cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df0e;
P_0c04df0e: /* original d337, guest PC 0x0c04df0e */
if(!s->budget--) { s->failed_pc=0x0c04df0eu; return 0; }
r[3]=read(ram,0x0c04dfecu,4);
goto P_0c04df10;
P_0c04df10: /* original d235, guest PC 0x0c04df10 */
if(!s->budget--) { s->failed_pc=0x0c04df10u; return 0; }
r[2]=read(ram,0x0c04dfe8u,4);
goto P_0c04df12;
P_0c04df12: /* original 430b, guest PC 0x0c04df12 */
if(!s->budget--) { s->failed_pc=0x0c04df12u; return 0; }
target=r[3];
r[16]=code_base|0x0c04df16u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04df16u) { target=s->pc; goto dispatch; }
goto P_0c04df16;
P_0c04df14: /* original 2f26, guest PC 0x0c04df14 */
if(!s->budget--) { s->failed_pc=0x0c04df14u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df16;
P_0c04df16: /* original 51ec, guest PC 0x0c04df16 */
if(!s->budget--) { s->failed_pc=0x0c04df16u; return 0; }
r[1]=read(ram,r[14]+48,4);
goto P_0c04df18;
P_0c04df18: /* original 2f16, guest PC 0x0c04df18 */
if(!s->budget--) { s->failed_pc=0x0c04df18u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df1a;
P_0c04df1a: /* original d335, guest PC 0x0c04df1a */
if(!s->budget--) { s->failed_pc=0x0c04df1au; return 0; }
r[3]=read(ram,0x0c04dff0u,4);
goto P_0c04df1c;
P_0c04df1c: /* original d233, guest PC 0x0c04df1c */
if(!s->budget--) { s->failed_pc=0x0c04df1cu; return 0; }
r[2]=read(ram,0x0c04dfecu,4);
goto P_0c04df1e;
P_0c04df1e: /* original 420b, guest PC 0x0c04df1e */
if(!s->budget--) { s->failed_pc=0x0c04df1eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04df22u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04df22u) { target=s->pc; goto dispatch; }
goto P_0c04df22;
P_0c04df20: /* original 2f36, guest PC 0x0c04df20 */
if(!s->budget--) { s->failed_pc=0x0c04df20u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df22;
P_0c04df22: /* original d334, guest PC 0x0c04df22 */
if(!s->budget--) { s->failed_pc=0x0c04df22u; return 0; }
r[3]=read(ram,0x0c04dff4u,4);
goto P_0c04df24;
P_0c04df24: /* original 7f10, guest PC 0x0c04df24 */
if(!s->budget--) { s->failed_pc=0x0c04df24u; return 0; }
r[15]+=0x00000010u;
goto P_0c04df26;
P_0c04df26: /* original 55eb, guest PC 0x0c04df26 */
if(!s->budget--) { s->failed_pc=0x0c04df26u; return 0; }
r[5]=read(ram,r[14]+44,4);
goto P_0c04df28;
P_0c04df28: /* original 430b, guest PC 0x0c04df28 */
if(!s->budget--) { s->failed_pc=0x0c04df28u; return 0; }
target=r[3];
r[16]=code_base|0x0c04df2cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04df2cu) { target=s->pc; goto dispatch; }
goto P_0c04df2c;
P_0c04df2a: /* original 64c3, guest PC 0x0c04df2a */
if(!s->budget--) { s->failed_pc=0x0c04df2au; return 0; }
r[4]=r[12];
goto P_0c04df2c;
P_0c04df2c: /* original d232, guest PC 0x0c04df2c */
if(!s->budget--) { s->failed_pc=0x0c04df2cu; return 0; }
r[2]=read(ram,0x0c04dff8u,4);
goto P_0c04df2e;
P_0c04df2e: /* original 420b, guest PC 0x0c04df2e */
if(!s->budget--) { s->failed_pc=0x0c04df2eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04df32u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04df32u) { target=s->pc; goto dispatch; }
goto P_0c04df32;
P_0c04df30: /* original 64c3, guest PC 0x0c04df30 */
if(!s->budget--) { s->failed_pc=0x0c04df30u; return 0; }
r[4]=r[12];
goto P_0c04df32;
P_0c04df32: /* original 4011, guest PC 0x0c04df32 */
if(!s->budget--) { s->failed_pc=0x0c04df32u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04df34;
P_0c04df34: /* original 8f04, guest PC 0x0c04df34 */
if(!s->budget--) { s->failed_pc=0x0c04df34u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(!cond) { goto P_0c04df40; }
goto P_0c04df38;
P_0c04df36: /* original 6d03, guest PC 0x0c04df36 */
if(!s->budget--) { s->failed_pc=0x0c04df36u; return 0; }
r[13]=r[0];
goto P_0c04df38;
P_0c04df38: /* original d330, guest PC 0x0c04df38 */
if(!s->budget--) { s->failed_pc=0x0c04df38u; return 0; }
r[3]=read(ram,0x0c04dffcu,4);
goto P_0c04df3a;
P_0c04df3a: /* original 430b, guest PC 0x0c04df3a */
if(!s->budget--) { s->failed_pc=0x0c04df3au; return 0; }
target=r[3];
r[16]=code_base|0x0c04df3eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04df3eu) { target=s->pc; goto dispatch; }
goto P_0c04df3e;
P_0c04df3c: /* original 64c3, guest PC 0x0c04df3c */
if(!s->budget--) { s->failed_pc=0x0c04df3cu; return 0; }
r[4]=r[12];
goto P_0c04df3e;
P_0c04df3e: /* original 6db3, guest PC 0x0c04df3e */
if(!s->budget--) { s->failed_pc=0x0c04df3eu; return 0; }
r[13]=r[11];
goto P_0c04df40;
P_0c04df40: /* original d22f, guest PC 0x0c04df40 */
if(!s->budget--) { s->failed_pc=0x0c04df40u; return 0; }
r[2]=read(ram,0x0c04e000u,4);
goto P_0c04df42;
P_0c04df42: /* original 420b, guest PC 0x0c04df42 */
if(!s->budget--) { s->failed_pc=0x0c04df42u; return 0; }
target=r[2];
r[16]=code_base|0x0c04df46u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04df46u) { target=s->pc; goto dispatch; }
goto P_0c04df46;
P_0c04df44: /* original 64e3, guest PC 0x0c04df44 */
if(!s->budget--) { s->failed_pc=0x0c04df44u; return 0; }
r[4]=r[14];
goto P_0c04df46;
P_0c04df46: /* original 60d3, guest PC 0x0c04df46 */
if(!s->budget--) { s->failed_pc=0x0c04df46u; return 0; }
r[0]=r[13];
goto P_0c04df48;
P_0c04df48: /* original 7f04, guest PC 0x0c04df48 */
if(!s->budget--) { s->failed_pc=0x0c04df48u; return 0; }
r[15]+=0x00000004u;
goto P_0c04df4a;
P_0c04df4a: /* original 4f16, guest PC 0x0c04df4a */
if(!s->budget--) { s->failed_pc=0x0c04df4au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04df4c;
P_0c04df4c: /* original 4f26, guest PC 0x0c04df4c */
if(!s->budget--) { s->failed_pc=0x0c04df4cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04df4e;
P_0c04df4e: /* original 6af6, guest PC 0x0c04df4e */
if(!s->budget--) { s->failed_pc=0x0c04df4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04df50;
P_0c04df50: /* original 6bf6, guest PC 0x0c04df50 */
if(!s->budget--) { s->failed_pc=0x0c04df50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04df52;
P_0c04df52: /* original 6cf6, guest PC 0x0c04df52 */
if(!s->budget--) { s->failed_pc=0x0c04df52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04df54;
P_0c04df54: /* original 6df6, guest PC 0x0c04df54 */
if(!s->budget--) { s->failed_pc=0x0c04df54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04df56;
P_0c04df56: /* original 000b, guest PC 0x0c04df56 */
if(!s->budget--) { s->failed_pc=0x0c04df56u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04df58: /* original 6ef6, guest PC 0x0c04df58 */
if(!s->budget--) { s->failed_pc=0x0c04df58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04df5au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
