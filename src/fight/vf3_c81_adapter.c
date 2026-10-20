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
int vf3_c81_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0376a0u: goto P_0c0376a0;
case 0x0c0376a2u: goto P_0c0376a2;
case 0x0c0376a4u: goto P_0c0376a4;
case 0x0c0376a6u: goto P_0c0376a6;
case 0x0c0376a8u: goto P_0c0376a8;
case 0x0c0376aau: goto P_0c0376aa;
case 0x0c0376acu: goto P_0c0376ac;
case 0x0c0376aeu: goto P_0c0376ae;
case 0x0c0376b0u: goto P_0c0376b0;
case 0x0c0376b2u: goto P_0c0376b2;
case 0x0c0376b4u: goto P_0c0376b4;
case 0x0c0376b6u: goto P_0c0376b6;
case 0x0c0376b8u: goto P_0c0376b8;
case 0x0c0376bau: goto P_0c0376ba;
case 0x0c0376bcu: goto P_0c0376bc;
case 0x0c0376beu: goto P_0c0376be;
case 0x0c0376c0u: goto P_0c0376c0;
case 0x0c0376c2u: goto P_0c0376c2;
case 0x0c0376c4u: goto P_0c0376c4;
case 0x0c0376c6u: goto P_0c0376c6;
case 0x0c0376c8u: goto P_0c0376c8;
case 0x0c0376cau: goto P_0c0376ca;
case 0x0c0376ccu: goto P_0c0376cc;
case 0x0c0376ceu: goto P_0c0376ce;
case 0x0c0376d0u: goto P_0c0376d0;
case 0x0c0376d2u: goto P_0c0376d2;
case 0x0c0376d4u: goto P_0c0376d4;
case 0x0c0376d6u: goto P_0c0376d6;
case 0x0c0376d8u: goto P_0c0376d8;
case 0x0c0376dau: goto P_0c0376da;
case 0x0c0376dcu: goto P_0c0376dc;
case 0x0c0376deu: goto P_0c0376de;
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
case 0x0c04ea52u: goto P_0c04ea52;
case 0x0c04ea54u: goto P_0c04ea54;
case 0x0c04ea56u: goto P_0c04ea56;
case 0x0c04ea58u: goto P_0c04ea58;
case 0x0c04ea5au: goto P_0c04ea5a;
case 0x0c04ea5cu: goto P_0c04ea5c;
case 0x0c04ea5eu: goto P_0c04ea5e;
case 0x0c04ea60u: goto P_0c04ea60;
case 0x0c04ea62u: goto P_0c04ea62;
case 0x0c04ea64u: goto P_0c04ea64;
case 0x0c04ea66u: goto P_0c04ea66;
case 0x0c04ea68u: goto P_0c04ea68;
case 0x0c04ea6au: goto P_0c04ea6a;
case 0x0c04ea6cu: goto P_0c04ea6c;
case 0x0c04ea6eu: goto P_0c04ea6e;
case 0x0c04ea70u: goto P_0c04ea70;
case 0x0c04ea72u: goto P_0c04ea72;
case 0x0c04ea74u: goto P_0c04ea74;
case 0x0c04ea76u: goto P_0c04ea76;
case 0x0c04ea78u: goto P_0c04ea78;
case 0x0c04ea7au: goto P_0c04ea7a;
case 0x0c04ea7cu: goto P_0c04ea7c;
case 0x0c04ea7eu: goto P_0c04ea7e;
case 0x0c04ea80u: goto P_0c04ea80;
case 0x0c04ea82u: goto P_0c04ea82;
case 0x0c04ea84u: goto P_0c04ea84;
case 0x0c04ea86u: goto P_0c04ea86;
case 0x0c04ea88u: goto P_0c04ea88;
case 0x0c04ea8au: goto P_0c04ea8a;
case 0x0c04ea8cu: goto P_0c04ea8c;
case 0x0c04ea8eu: goto P_0c04ea8e;
case 0x0c04ea90u: goto P_0c04ea90;
case 0x0c04ea92u: goto P_0c04ea92;
case 0x0c04ea94u: goto P_0c04ea94;
case 0x0c04ea96u: goto P_0c04ea96;
case 0x0c04ea98u: goto P_0c04ea98;
case 0x0c04ea9au: goto P_0c04ea9a;
case 0x0c04ea9cu: goto P_0c04ea9c;
case 0x0c04ea9eu: goto P_0c04ea9e;
case 0x0c04eaa0u: goto P_0c04eaa0;
case 0x0c04eaa2u: goto P_0c04eaa2;
case 0x0c04eaa4u: goto P_0c04eaa4;
case 0x0c04eaa6u: goto P_0c04eaa6;
case 0x0c04eaccu: goto P_0c04eacc;
case 0x0c04eaceu: goto P_0c04eace;
case 0x0c04ead0u: goto P_0c04ead0;
case 0x0c04ead2u: goto P_0c04ead2;
case 0x0c04ead4u: goto P_0c04ead4;
case 0x0c04ead6u: goto P_0c04ead6;
case 0x0c04ead8u: goto P_0c04ead8;
case 0x0c04eadau: goto P_0c04eada;
case 0x0c04eadcu: goto P_0c04eadc;
case 0x0c04eadeu: goto P_0c04eade;
case 0x0c04eae0u: goto P_0c04eae0;
case 0x0c04eae2u: goto P_0c04eae2;
case 0x0c04eae4u: goto P_0c04eae4;
case 0x0c04eae6u: goto P_0c04eae6;
case 0x0c04eae8u: goto P_0c04eae8;
case 0x0c04eaeau: goto P_0c04eaea;
case 0x0c04eaecu: goto P_0c04eaec;
case 0x0c04eaeeu: goto P_0c04eaee;
case 0x0c04eaf0u: goto P_0c04eaf0;
case 0x0c04eaf2u: goto P_0c04eaf2;
case 0x0c04eaf4u: goto P_0c04eaf4;
case 0x0c04eaf6u: goto P_0c04eaf6;
case 0x0c04eaf8u: goto P_0c04eaf8;
case 0x0c04eafau: goto P_0c04eafa;
case 0x0c04eafcu: goto P_0c04eafc;
case 0x0c04eafeu: goto P_0c04eafe;
case 0x0c04eb00u: goto P_0c04eb00;
case 0x0c04eb02u: goto P_0c04eb02;
case 0x0c04eb04u: goto P_0c04eb04;
case 0x0c04eb06u: goto P_0c04eb06;
case 0x0c04eb08u: goto P_0c04eb08;
case 0x0c04eb0au: goto P_0c04eb0a;
case 0x0c04eb0cu: goto P_0c04eb0c;
case 0x0c04eb0eu: goto P_0c04eb0e;
case 0x0c04eb10u: goto P_0c04eb10;
case 0x0c04eb12u: goto P_0c04eb12;
case 0x0c04eb14u: goto P_0c04eb14;
case 0x0c04eb16u: goto P_0c04eb16;
case 0x0c04eb18u: goto P_0c04eb18;
case 0x0c04eb1au: goto P_0c04eb1a;
case 0x0c04eb1cu: goto P_0c04eb1c;
case 0x0c04eb1eu: goto P_0c04eb1e;
case 0x0c04eb20u: goto P_0c04eb20;
case 0x0c04eb22u: goto P_0c04eb22;
case 0x0c04eb24u: goto P_0c04eb24;
case 0x0c04eb26u: goto P_0c04eb26;
case 0x0c04eb28u: goto P_0c04eb28;
case 0x0c04eb2au: goto P_0c04eb2a;
case 0x0c04eb2cu: goto P_0c04eb2c;
case 0x0c04eb2eu: goto P_0c04eb2e;
case 0x0c04eb30u: goto P_0c04eb30;
case 0x0c04eb32u: goto P_0c04eb32;
case 0x0c04eb34u: goto P_0c04eb34;
case 0x0c04eb36u: goto P_0c04eb36;
case 0x0c04eb38u: goto P_0c04eb38;
case 0x0c04eb3au: goto P_0c04eb3a;
case 0x0c04eb3cu: goto P_0c04eb3c;
case 0x0c04eb3eu: goto P_0c04eb3e;
case 0x0c04eb40u: goto P_0c04eb40;
case 0x0c04eb42u: goto P_0c04eb42;
case 0x0c04eb44u: goto P_0c04eb44;
case 0x0c04eb46u: goto P_0c04eb46;
case 0x0c04eb48u: goto P_0c04eb48;
case 0x0c04eb4au: goto P_0c04eb4a;
case 0x0c04eb4cu: goto P_0c04eb4c;
case 0x0c04eb4eu: goto P_0c04eb4e;
case 0x0c04eb50u: goto P_0c04eb50;
case 0x0c04eb52u: goto P_0c04eb52;
case 0x0c04eb54u: goto P_0c04eb54;
case 0x0c04eb56u: goto P_0c04eb56;
case 0x0c04eb58u: goto P_0c04eb58;
case 0x0c04eb5au: goto P_0c04eb5a;
case 0x0c04eb5cu: goto P_0c04eb5c;
case 0x0c04eb5eu: goto P_0c04eb5e;
case 0x0c04eb60u: goto P_0c04eb60;
case 0x0c04eb62u: goto P_0c04eb62;
case 0x0c04eb64u: goto P_0c04eb64;
case 0x0c04eb66u: goto P_0c04eb66;
case 0x0c04eb68u: goto P_0c04eb68;
case 0x0c04eb6au: goto P_0c04eb6a;
case 0x0c04eb6cu: goto P_0c04eb6c;
case 0x0c04eb6eu: goto P_0c04eb6e;
case 0x0c04ed8cu: goto P_0c04ed8c;
case 0x0c04ed8eu: goto P_0c04ed8e;
case 0x0c04ed90u: goto P_0c04ed90;
case 0x0c04ed92u: goto P_0c04ed92;
case 0x0c04ed94u: goto P_0c04ed94;
case 0x0c04ed96u: goto P_0c04ed96;
case 0x0c04ed98u: goto P_0c04ed98;
case 0x0c04ed9au: goto P_0c04ed9a;
case 0x0c04ed9cu: goto P_0c04ed9c;
case 0x0c04ed9eu: goto P_0c04ed9e;
case 0x0c04eda0u: goto P_0c04eda0;
case 0x0c04eda2u: goto P_0c04eda2;
case 0x0c04eda4u: goto P_0c04eda4;
case 0x0c04eda6u: goto P_0c04eda6;
case 0x0c04eda8u: goto P_0c04eda8;
case 0x0c04edaau: goto P_0c04edaa;
case 0x0c04edacu: goto P_0c04edac;
case 0x0c04edaeu: goto P_0c04edae;
case 0x0c04edb0u: goto P_0c04edb0;
case 0x0c04edb2u: goto P_0c04edb2;
case 0x0c04edb4u: goto P_0c04edb4;
case 0x0c04edb6u: goto P_0c04edb6;
case 0x0c04edb8u: goto P_0c04edb8;
case 0x0c04edbau: goto P_0c04edba;
case 0x0c04edbcu: goto P_0c04edbc;
case 0x0c04edbeu: goto P_0c04edbe;
case 0x0c04edc0u: goto P_0c04edc0;
case 0x0c04edc2u: goto P_0c04edc2;
case 0x0c04edc4u: goto P_0c04edc4;
case 0x0c04edc6u: goto P_0c04edc6;
case 0x0c04edc8u: goto P_0c04edc8;
case 0x0c04edcau: goto P_0c04edca;
case 0x0c04edccu: goto P_0c04edcc;
case 0x0c04edceu: goto P_0c04edce;
case 0x0c04edd0u: goto P_0c04edd0;
case 0x0c04edd2u: goto P_0c04edd2;
case 0x0c04edd4u: goto P_0c04edd4;
case 0x0c04edd6u: goto P_0c04edd6;
case 0x0c04edd8u: goto P_0c04edd8;
case 0x0c04eddau: goto P_0c04edda;
case 0x0c04eddcu: goto P_0c04eddc;
case 0x0c04eddeu: goto P_0c04edde;
case 0x0c04ede0u: goto P_0c04ede0;
case 0x0c04ede2u: goto P_0c04ede2;
case 0x0c04ede4u: goto P_0c04ede4;
case 0x0c04ede6u: goto P_0c04ede6;
case 0x0c04ede8u: goto P_0c04ede8;
case 0x0c04edeau: goto P_0c04edea;
case 0x0c04edecu: goto P_0c04edec;
case 0x0c04edeeu: goto P_0c04edee;
case 0x0c04edf0u: goto P_0c04edf0;
case 0x0c04ee2cu: goto P_0c04ee2c;
case 0x0c04ee2eu: goto P_0c04ee2e;
case 0x0c04ee30u: goto P_0c04ee30;
case 0x0c04ee32u: goto P_0c04ee32;
case 0x0c04ee34u: goto P_0c04ee34;
case 0x0c04ee36u: goto P_0c04ee36;
case 0x0c04ee38u: goto P_0c04ee38;
case 0x0c04ee3au: goto P_0c04ee3a;
case 0x0c04ee3cu: goto P_0c04ee3c;
case 0x0c04ee3eu: goto P_0c04ee3e;
case 0x0c04ee40u: goto P_0c04ee40;
case 0x0c04ee42u: goto P_0c04ee42;
case 0x0c04ee44u: goto P_0c04ee44;
case 0x0c04ee46u: goto P_0c04ee46;
case 0x0c04ee48u: goto P_0c04ee48;
case 0x0c04ee4au: goto P_0c04ee4a;
case 0x0c04ee4cu: goto P_0c04ee4c;
case 0x0c04ee4eu: goto P_0c04ee4e;
case 0x0c04ee50u: goto P_0c04ee50;
case 0x0c04ee52u: goto P_0c04ee52;
case 0x0c04ee54u: goto P_0c04ee54;
case 0x0c04ee56u: goto P_0c04ee56;
case 0x0c04ee58u: goto P_0c04ee58;
case 0x0c04ee5au: goto P_0c04ee5a;
case 0x0c04ee5cu: goto P_0c04ee5c;
case 0x0c04ee5eu: goto P_0c04ee5e;
case 0x0c04ee60u: goto P_0c04ee60;
case 0x0c04ee62u: goto P_0c04ee62;
case 0x0c04ee64u: goto P_0c04ee64;
case 0x0c04ee66u: goto P_0c04ee66;
case 0x0c04ee68u: goto P_0c04ee68;
case 0x0c04ee6au: goto P_0c04ee6a;
case 0x0c04ee6cu: goto P_0c04ee6c;
case 0x0c04ee6eu: goto P_0c04ee6e;
case 0x0c04ee70u: goto P_0c04ee70;
case 0x0c04ee72u: goto P_0c04ee72;
case 0x0c04ee74u: goto P_0c04ee74;
case 0x0c04ee76u: goto P_0c04ee76;
case 0x0c04ee78u: goto P_0c04ee78;
case 0x0c04ee7au: goto P_0c04ee7a;
case 0x0c04ee7cu: goto P_0c04ee7c;
case 0x0c04ee7eu: goto P_0c04ee7e;
case 0x0c04ee80u: goto P_0c04ee80;
case 0x0c04ee82u: goto P_0c04ee82;
case 0x0c04ee84u: goto P_0c04ee84;
case 0x0c04ee86u: goto P_0c04ee86;
case 0x0c04ee88u: goto P_0c04ee88;
case 0x0c04ee8au: goto P_0c04ee8a;
case 0x0c04ee8cu: goto P_0c04ee8c;
case 0x0c04ee8eu: goto P_0c04ee8e;
case 0x0c04ee90u: goto P_0c04ee90;
case 0x0c04ee92u: goto P_0c04ee92;
case 0x0c04ee94u: goto P_0c04ee94;
case 0x0c04ee96u: goto P_0c04ee96;
case 0x0c04ee98u: goto P_0c04ee98;
case 0x0c04ee9au: goto P_0c04ee9a;
case 0x0c04ee9cu: goto P_0c04ee9c;
case 0x0c04ee9eu: goto P_0c04ee9e;
case 0x0c04eea0u: goto P_0c04eea0;
case 0x0c04eea2u: goto P_0c04eea2;
case 0x0c04eea4u: goto P_0c04eea4;
case 0x0c04eea6u: goto P_0c04eea6;
case 0x0c04eea8u: goto P_0c04eea8;
case 0x0c04eeaau: goto P_0c04eeaa;
case 0x0c04eeacu: goto P_0c04eeac;
case 0x0c04eeaeu: goto P_0c04eeae;
case 0x0c04eeb0u: goto P_0c04eeb0;
case 0x0c04eeb2u: goto P_0c04eeb2;
case 0x0c04eeb4u: goto P_0c04eeb4;
case 0x0c04eeb6u: goto P_0c04eeb6;
case 0x0c04eeb8u: goto P_0c04eeb8;
case 0x0c04eebau: goto P_0c04eeba;
case 0x0c04eebcu: goto P_0c04eebc;
case 0x0c04f632u: goto P_0c04f632;
case 0x0c04f634u: goto P_0c04f634;
case 0x0c04f636u: goto P_0c04f636;
case 0x0c04f638u: goto P_0c04f638;
case 0x0c04f63au: goto P_0c04f63a;
case 0x0c04f63cu: goto P_0c04f63c;
case 0x0c04f63eu: goto P_0c04f63e;
case 0x0c04f640u: goto P_0c04f640;
case 0x0c04f642u: goto P_0c04f642;
case 0x0c04f644u: goto P_0c04f644;
case 0x0c04f646u: goto P_0c04f646;
case 0x0c04f648u: goto P_0c04f648;
case 0x0c04f64au: goto P_0c04f64a;
case 0x0c04f64cu: goto P_0c04f64c;
case 0x0c04f64eu: goto P_0c04f64e;
case 0x0c04f650u: goto P_0c04f650;
case 0x0c04f652u: goto P_0c04f652;
case 0x0c04f654u: goto P_0c04f654;
case 0x0c04f656u: goto P_0c04f656;
case 0x0c04f658u: goto P_0c04f658;
case 0x0c04f65au: goto P_0c04f65a;
case 0x0c04f65cu: goto P_0c04f65c;
case 0x0c04f65eu: goto P_0c04f65e;
case 0x0c04f660u: goto P_0c04f660;
case 0x0c04f662u: goto P_0c04f662;
case 0x0c04f664u: goto P_0c04f664;
case 0x0c04f666u: goto P_0c04f666;
case 0x0c04f668u: goto P_0c04f668;
case 0x0c04f66au: goto P_0c04f66a;
case 0x0c04f66cu: goto P_0c04f66c;
case 0x0c04f66eu: goto P_0c04f66e;
case 0x0c04f670u: goto P_0c04f670;
case 0x0c04f672u: goto P_0c04f672;
case 0x0c04f674u: goto P_0c04f674;
case 0x0c04f676u: goto P_0c04f676;
case 0x0c04f678u: goto P_0c04f678;
case 0x0c04f67au: goto P_0c04f67a;
case 0x0c04f67cu: goto P_0c04f67c;
case 0x0c04f67eu: goto P_0c04f67e;
case 0x0c04f680u: goto P_0c04f680;
case 0x0c04f682u: goto P_0c04f682;
case 0x0c04f684u: goto P_0c04f684;
case 0x0c04f686u: goto P_0c04f686;
case 0x0c04f688u: goto P_0c04f688;
case 0x0c04f68au: goto P_0c04f68a;
case 0x0c04f68cu: goto P_0c04f68c;
case 0x0c04f68eu: goto P_0c04f68e;
case 0x0c04f690u: goto P_0c04f690;
case 0x0c04f692u: goto P_0c04f692;
case 0x0c04f694u: goto P_0c04f694;
case 0x0c04f696u: goto P_0c04f696;
case 0x0c04f698u: goto P_0c04f698;
case 0x0c04f69au: goto P_0c04f69a;
case 0x0c04f69cu: goto P_0c04f69c;
case 0x0c04f69eu: goto P_0c04f69e;
case 0x0c04f6a0u: goto P_0c04f6a0;
case 0x0c04f6a2u: goto P_0c04f6a2;
case 0x0c04f6a4u: goto P_0c04f6a4;
case 0x0c04f6a6u: goto P_0c04f6a6;
case 0x0c04f6a8u: goto P_0c04f6a8;
case 0x0c04f6aau: goto P_0c04f6aa;
case 0x0c04f6acu: goto P_0c04f6ac;
case 0x0c04f6aeu: goto P_0c04f6ae;
case 0x0c04f6b0u: goto P_0c04f6b0;
case 0x0c04f6b2u: goto P_0c04f6b2;
case 0x0c04f6b4u: goto P_0c04f6b4;
case 0x0c04f6b6u: goto P_0c04f6b6;
case 0x0c04f6b8u: goto P_0c04f6b8;
case 0x0c04f6bau: goto P_0c04f6ba;
case 0x0c04f6bcu: goto P_0c04f6bc;
case 0x0c04f6beu: goto P_0c04f6be;
case 0x0c04f6c0u: goto P_0c04f6c0;
case 0x0c04f6c2u: goto P_0c04f6c2;
case 0x0c04f6c4u: goto P_0c04f6c4;
case 0x0c04f6e0u: goto P_0c04f6e0;
case 0x0c04f6e2u: goto P_0c04f6e2;
case 0x0c04f6e4u: goto P_0c04f6e4;
case 0x0c04f6e6u: goto P_0c04f6e6;
case 0x0c04f6e8u: goto P_0c04f6e8;
case 0x0c04f6eau: goto P_0c04f6ea;
case 0x0c04f6ecu: goto P_0c04f6ec;
case 0x0c04f6eeu: goto P_0c04f6ee;
case 0x0c04f6f0u: goto P_0c04f6f0;
case 0x0c04f6f2u: goto P_0c04f6f2;
case 0x0c04f6f4u: goto P_0c04f6f4;
case 0x0c04f6f6u: goto P_0c04f6f6;
case 0x0c04f6f8u: goto P_0c04f6f8;
case 0x0c04f6fau: goto P_0c04f6fa;
case 0x0c04f6fcu: goto P_0c04f6fc;
case 0x0c04f6feu: goto P_0c04f6fe;
case 0x0c04f700u: goto P_0c04f700;
case 0x0c04f702u: goto P_0c04f702;
case 0x0c04f704u: goto P_0c04f704;
case 0x0c04f706u: goto P_0c04f706;
case 0x0c04f708u: goto P_0c04f708;
case 0x0c04f70au: goto P_0c04f70a;
case 0x0c04f70cu: goto P_0c04f70c;
case 0x0c04f70eu: goto P_0c04f70e;
case 0x0c04f710u: goto P_0c04f710;
case 0x0c04f712u: goto P_0c04f712;
case 0x0c04f714u: goto P_0c04f714;
case 0x0c04f716u: goto P_0c04f716;
case 0x0c04f718u: goto P_0c04f718;
case 0x0c04f71au: goto P_0c04f71a;
case 0x0c04f71cu: goto P_0c04f71c;
case 0x0c04f71eu: goto P_0c04f71e;
case 0x0c04f720u: goto P_0c04f720;
case 0x0c04f722u: goto P_0c04f722;
case 0x0c04f724u: goto P_0c04f724;
case 0x0c04f726u: goto P_0c04f726;
case 0x0c04f728u: goto P_0c04f728;
case 0x0c04f72au: goto P_0c04f72a;
case 0x0c04f72cu: goto P_0c04f72c;
case 0x0c04f72eu: goto P_0c04f72e;
case 0x0c04f730u: goto P_0c04f730;
case 0x0c04f732u: goto P_0c04f732;
case 0x0c04f734u: goto P_0c04f734;
case 0x0c04f736u: goto P_0c04f736;
case 0x0c04f738u: goto P_0c04f738;
case 0x0c04f73au: goto P_0c04f73a;
case 0x0c04f73cu: goto P_0c04f73c;
case 0x0c04f73eu: goto P_0c04f73e;
case 0x0c04f740u: goto P_0c04f740;
case 0x0c04f742u: goto P_0c04f742;
case 0x0c04f744u: goto P_0c04f744;
case 0x0c04f746u: goto P_0c04f746;
case 0x0c04f748u: goto P_0c04f748;
case 0x0c04f74au: goto P_0c04f74a;
case 0x0c04f74cu: goto P_0c04f74c;
case 0x0c04f74eu: goto P_0c04f74e;
case 0x0c04f750u: goto P_0c04f750;
case 0x0c04f752u: goto P_0c04f752;
case 0x0c04f754u: goto P_0c04f754;
case 0x0c04f756u: goto P_0c04f756;
case 0x0c04f758u: goto P_0c04f758;
case 0x0c04f75au: goto P_0c04f75a;
case 0x0c04f75cu: goto P_0c04f75c;
case 0x0c04f75eu: goto P_0c04f75e;
case 0x0c04f760u: goto P_0c04f760;
case 0x0c04f762u: goto P_0c04f762;
case 0x0c04f764u: goto P_0c04f764;
case 0x0c04f766u: goto P_0c04f766;
case 0x0c04f768u: goto P_0c04f768;
case 0x0c04f76au: goto P_0c04f76a;
case 0x0c04f76cu: goto P_0c04f76c;
case 0x0c04f76eu: goto P_0c04f76e;
case 0x0c04f770u: goto P_0c04f770;
case 0x0c04f772u: goto P_0c04f772;
case 0x0c04f774u: goto P_0c04f774;
case 0x0c04f776u: goto P_0c04f776;
case 0x0c04f778u: goto P_0c04f778;
case 0x0c04f77au: goto P_0c04f77a;
case 0x0c04f77cu: goto P_0c04f77c;
case 0x0c04f77eu: goto P_0c04f77e;
case 0x0c04f780u: goto P_0c04f780;
case 0x0c04f782u: goto P_0c04f782;
case 0x0c04f784u: goto P_0c04f784;
case 0x0c04f786u: goto P_0c04f786;
case 0x0c04f788u: goto P_0c04f788;
case 0x0c04f78au: goto P_0c04f78a;
case 0x0c04f78cu: goto P_0c04f78c;
case 0x0c04f78eu: goto P_0c04f78e;
case 0x0c04f790u: goto P_0c04f790;
case 0x0c04f792u: goto P_0c04f792;
case 0x0c04f794u: goto P_0c04f794;
case 0x0c04f796u: goto P_0c04f796;
case 0x0c04f798u: goto P_0c04f798;
case 0x0c04f79au: goto P_0c04f79a;
case 0x0c04f79cu: goto P_0c04f79c;
case 0x0c04f79eu: goto P_0c04f79e;
case 0x0c04f7a0u: goto P_0c04f7a0;
case 0x0c04f7a2u: goto P_0c04f7a2;
case 0x0c04f7a4u: goto P_0c04f7a4;
case 0x0c04f7a6u: goto P_0c04f7a6;
case 0x0c04f7a8u: goto P_0c04f7a8;
case 0x0c04f7aau: goto P_0c04f7aa;
case 0x0c04f7acu: goto P_0c04f7ac;
case 0x0c04f7aeu: goto P_0c04f7ae;
case 0x0c04f7b0u: goto P_0c04f7b0;
case 0x0c04f7b2u: goto P_0c04f7b2;
case 0x0c04f7b4u: goto P_0c04f7b4;
case 0x0c04f7b6u: goto P_0c04f7b6;
case 0x0c04f7b8u: goto P_0c04f7b8;
case 0x0c04f7bau: goto P_0c04f7ba;
case 0x0c04f7bcu: goto P_0c04f7bc;
case 0x0c04f7beu: goto P_0c04f7be;
case 0x0c04f7c0u: goto P_0c04f7c0;
case 0x0c04f7c2u: goto P_0c04f7c2;
case 0x0c04f7c4u: goto P_0c04f7c4;
case 0x0c04f7c6u: goto P_0c04f7c6;
case 0x0c04f7c8u: goto P_0c04f7c8;
case 0x0c04f7cau: goto P_0c04f7ca;
case 0x0c04f7ccu: goto P_0c04f7cc;
case 0x0c04f7e8u: goto P_0c04f7e8;
case 0x0c04f7eau: goto P_0c04f7ea;
case 0x0c04f7ecu: goto P_0c04f7ec;
case 0x0c04f7eeu: goto P_0c04f7ee;
case 0x0c04f7f0u: goto P_0c04f7f0;
case 0x0c04f7f2u: goto P_0c04f7f2;
case 0x0c04f7f4u: goto P_0c04f7f4;
case 0x0c04f7f6u: goto P_0c04f7f6;
case 0x0c04f7f8u: goto P_0c04f7f8;
case 0x0c04f7fau: goto P_0c04f7fa;
case 0x0c04f7fcu: goto P_0c04f7fc;
case 0x0c04f7feu: goto P_0c04f7fe;
case 0x0c04f800u: goto P_0c04f800;
case 0x0c04f802u: goto P_0c04f802;
case 0x0c04f804u: goto P_0c04f804;
case 0x0c04f806u: goto P_0c04f806;
case 0x0c04f808u: goto P_0c04f808;
case 0x0c04f80au: goto P_0c04f80a;
case 0x0c04f80cu: goto P_0c04f80c;
case 0x0c04f80eu: goto P_0c04f80e;
case 0x0c04f810u: goto P_0c04f810;
case 0x0c04f812u: goto P_0c04f812;
case 0x0c04f814u: goto P_0c04f814;
case 0x0c04f816u: goto P_0c04f816;
case 0x0c04f818u: goto P_0c04f818;
case 0x0c04f81au: goto P_0c04f81a;
case 0x0c04f81cu: goto P_0c04f81c;
case 0x0c04f81eu: goto P_0c04f81e;
case 0x0c04f820u: goto P_0c04f820;
case 0x0c04f822u: goto P_0c04f822;
case 0x0c04f824u: goto P_0c04f824;
case 0x0c04f826u: goto P_0c04f826;
case 0x0c04f828u: goto P_0c04f828;
case 0x0c04f82au: goto P_0c04f82a;
case 0x0c04f82cu: goto P_0c04f82c;
case 0x0c04f82eu: goto P_0c04f82e;
case 0x0c04f830u: goto P_0c04f830;
case 0x0c04f832u: goto P_0c04f832;
case 0x0c04f834u: goto P_0c04f834;
case 0x0c04f836u: goto P_0c04f836;
case 0x0c04f838u: goto P_0c04f838;
case 0x0c04f83au: goto P_0c04f83a;
case 0x0c04f83cu: goto P_0c04f83c;
case 0x0c04f83eu: goto P_0c04f83e;
case 0x0c04f840u: goto P_0c04f840;
case 0x0c04f842u: goto P_0c04f842;
case 0x0c04f844u: goto P_0c04f844;
case 0x0c04f846u: goto P_0c04f846;
case 0x0c04f848u: goto P_0c04f848;
case 0x0c04f84au: goto P_0c04f84a;
case 0x0c04f84cu: goto P_0c04f84c;
case 0x0c04f84eu: goto P_0c04f84e;
case 0x0c04f850u: goto P_0c04f850;
case 0x0c04f852u: goto P_0c04f852;
case 0x0c04f854u: goto P_0c04f854;
case 0x0c04f856u: goto P_0c04f856;
case 0x0c04f858u: goto P_0c04f858;
case 0x0c04f85au: goto P_0c04f85a;
case 0x0c04f85cu: goto P_0c04f85c;
case 0x0c04f85eu: goto P_0c04f85e;
case 0x0c04f860u: goto P_0c04f860;
case 0x0c04f862u: goto P_0c04f862;
case 0x0c04f864u: goto P_0c04f864;
case 0x0c04f866u: goto P_0c04f866;
case 0x0c04f868u: goto P_0c04f868;
case 0x0c04f86au: goto P_0c04f86a;
case 0x0c04f86cu: goto P_0c04f86c;
case 0x0c04f86eu: goto P_0c04f86e;
case 0x0c04f870u: goto P_0c04f870;
case 0x0c04f872u: goto P_0c04f872;
case 0x0c04f874u: goto P_0c04f874;
case 0x0c04f876u: goto P_0c04f876;
case 0x0c04f878u: goto P_0c04f878;
case 0x0c04f87au: goto P_0c04f87a;
case 0x0c04f87cu: goto P_0c04f87c;
case 0x0c04f87eu: goto P_0c04f87e;
case 0x0c04f880u: goto P_0c04f880;
case 0x0c04f882u: goto P_0c04f882;
case 0x0c04f884u: goto P_0c04f884;
case 0x0c04f886u: goto P_0c04f886;
case 0x0c04f888u: goto P_0c04f888;
case 0x0c04f88au: goto P_0c04f88a;
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
case 0x0c04fafcu: goto P_0c04fafc;
case 0x0c04fafeu: goto P_0c04fafe;
case 0x0c04fb00u: goto P_0c04fb00;
case 0x0c04fb02u: goto P_0c04fb02;
case 0x0c04fb04u: goto P_0c04fb04;
case 0x0c04fb06u: goto P_0c04fb06;
case 0x0c04fb08u: goto P_0c04fb08;
case 0x0c04fb0au: goto P_0c04fb0a;
case 0x0c04fb0cu: goto P_0c04fb0c;
case 0x0c04fb0eu: goto P_0c04fb0e;
case 0x0c04fb10u: goto P_0c04fb10;
case 0x0c04fb12u: goto P_0c04fb12;
case 0x0c04fb14u: goto P_0c04fb14;
case 0x0c04fb16u: goto P_0c04fb16;
case 0x0c04fb18u: goto P_0c04fb18;
case 0x0c04fb1au: goto P_0c04fb1a;
case 0x0c04fb1cu: goto P_0c04fb1c;
case 0x0c04fb1eu: goto P_0c04fb1e;
case 0x0c04fb20u: goto P_0c04fb20;
case 0x0c04fb22u: goto P_0c04fb22;
case 0x0c04fb24u: goto P_0c04fb24;
case 0x0c04fb26u: goto P_0c04fb26;
case 0x0c04fb28u: goto P_0c04fb28;
case 0x0c04fb2au: goto P_0c04fb2a;
case 0x0c04fb2cu: goto P_0c04fb2c;
case 0x0c04fb2eu: goto P_0c04fb2e;
case 0x0c04fd30u: goto P_0c04fd30;
case 0x0c04fd32u: goto P_0c04fd32;
case 0x0c04fd34u: goto P_0c04fd34;
case 0x0c04fd36u: goto P_0c04fd36;
case 0x0c04fd38u: goto P_0c04fd38;
case 0x0c04fd3au: goto P_0c04fd3a;
case 0x0c04fd3cu: goto P_0c04fd3c;
case 0x0c04fd3eu: goto P_0c04fd3e;
case 0x0c04fd40u: goto P_0c04fd40;
case 0x0c04fd42u: goto P_0c04fd42;
case 0x0c04fd44u: goto P_0c04fd44;
case 0x0c04fd46u: goto P_0c04fd46;
case 0x0c04fd48u: goto P_0c04fd48;
case 0x0c04fd4au: goto P_0c04fd4a;
case 0x0c04fd4cu: goto P_0c04fd4c;
case 0x0c04fd4eu: goto P_0c04fd4e;
case 0x0c04fd50u: goto P_0c04fd50;
case 0x0c04fd52u: goto P_0c04fd52;
case 0x0c04fd54u: goto P_0c04fd54;
case 0x0c04fd56u: goto P_0c04fd56;
case 0x0c04fd58u: goto P_0c04fd58;
case 0x0c04fd5au: goto P_0c04fd5a;
case 0x0c04fd5cu: goto P_0c04fd5c;
case 0x0c04fd5eu: goto P_0c04fd5e;
case 0x0c04fd60u: goto P_0c04fd60;
case 0x0c04fd62u: goto P_0c04fd62;
case 0x0c04fd64u: goto P_0c04fd64;
case 0x0c04fd66u: goto P_0c04fd66;
case 0x0c04fd68u: goto P_0c04fd68;
case 0x0c04fd6au: goto P_0c04fd6a;
case 0x0c04fd6cu: goto P_0c04fd6c;
case 0x0c04fd6eu: goto P_0c04fd6e;
case 0x0c04fd70u: goto P_0c04fd70;
case 0x0c04fd72u: goto P_0c04fd72;
case 0x0c04fd74u: goto P_0c04fd74;
case 0x0c04fd76u: goto P_0c04fd76;
case 0x0c04fd78u: goto P_0c04fd78;
case 0x0c04fd7au: goto P_0c04fd7a;
case 0x0c04fd7cu: goto P_0c04fd7c;
case 0x0c04fd7eu: goto P_0c04fd7e;
case 0x0c04fd80u: goto P_0c04fd80;
case 0x0c04fd82u: goto P_0c04fd82;
case 0x0c04fd84u: goto P_0c04fd84;
case 0x0c04fd86u: goto P_0c04fd86;
case 0x0c04fd88u: goto P_0c04fd88;
case 0x0c04fd8au: goto P_0c04fd8a;
case 0x0c04fd8cu: goto P_0c04fd8c;
case 0x0c04fd8eu: goto P_0c04fd8e;
case 0x0c04fd90u: goto P_0c04fd90;
case 0x0c04fd92u: goto P_0c04fd92;
case 0x0c04fd94u: goto P_0c04fd94;
case 0x0c04fd96u: goto P_0c04fd96;
case 0x0c04fd98u: goto P_0c04fd98;
case 0x0c04fd9au: goto P_0c04fd9a;
case 0x0c04fd9cu: goto P_0c04fd9c;
case 0x0c04fd9eu: goto P_0c04fd9e;
case 0x0c04fda0u: goto P_0c04fda0;
case 0x0c04fda2u: goto P_0c04fda2;
case 0x0c04fda4u: goto P_0c04fda4;
case 0x0c04fda6u: goto P_0c04fda6;
case 0x0c04fda8u: goto P_0c04fda8;
case 0x0c04fdaau: goto P_0c04fdaa;
case 0x0c04fdacu: goto P_0c04fdac;
case 0x0c04fdaeu: goto P_0c04fdae;
case 0x0c04fdb0u: goto P_0c04fdb0;
case 0x0c04fdb2u: goto P_0c04fdb2;
case 0x0c04fdb4u: goto P_0c04fdb4;
case 0x0c04fdb6u: goto P_0c04fdb6;
case 0x0c04fdb8u: goto P_0c04fdb8;
case 0x0c04fdbau: goto P_0c04fdba;
case 0x0c04fdbcu: goto P_0c04fdbc;
case 0x0c04fdbeu: goto P_0c04fdbe;
case 0x0c04fdc0u: goto P_0c04fdc0;
case 0x0c04fdc2u: goto P_0c04fdc2;
case 0x0c04fdc4u: goto P_0c04fdc4;
case 0x0c04fdc6u: goto P_0c04fdc6;
case 0x0c04fdc8u: goto P_0c04fdc8;
case 0x0c04fdcau: goto P_0c04fdca;
case 0x0c04fdccu: goto P_0c04fdcc;
case 0x0c04fdceu: goto P_0c04fdce;
case 0x0c04fdd0u: goto P_0c04fdd0;
case 0x0c04fdd2u: goto P_0c04fdd2;
case 0x0c04fdd4u: goto P_0c04fdd4;
case 0x0c04fe40u: goto P_0c04fe40;
case 0x0c04fe42u: goto P_0c04fe42;
case 0x0c04fe44u: goto P_0c04fe44;
case 0x0c04fe46u: goto P_0c04fe46;
case 0x0c04fe48u: goto P_0c04fe48;
case 0x0c04fe4au: goto P_0c04fe4a;
case 0x0c04fe4cu: goto P_0c04fe4c;
case 0x0c04fe4eu: goto P_0c04fe4e;
case 0x0c04fe50u: goto P_0c04fe50;
case 0x0c04fe52u: goto P_0c04fe52;
case 0x0c04fe54u: goto P_0c04fe54;
case 0x0c04fe56u: goto P_0c04fe56;
case 0x0c04fe58u: goto P_0c04fe58;
case 0x0c04fe5au: goto P_0c04fe5a;
case 0x0c04fe5cu: goto P_0c04fe5c;
case 0x0c04fe5eu: goto P_0c04fe5e;
case 0x0c04fe60u: goto P_0c04fe60;
case 0x0c04fe62u: goto P_0c04fe62;
case 0x0c04fe64u: goto P_0c04fe64;
case 0x0c04fe66u: goto P_0c04fe66;
case 0x0c04fe68u: goto P_0c04fe68;
case 0x0c04fe6au: goto P_0c04fe6a;
case 0x0c04fe6cu: goto P_0c04fe6c;
case 0x0c04fe6eu: goto P_0c04fe6e;
case 0x0c04fe70u: goto P_0c04fe70;
case 0x0c04fe72u: goto P_0c04fe72;
case 0x0c04fe74u: goto P_0c04fe74;
case 0x0c04fe76u: goto P_0c04fe76;
case 0x0c04fe78u: goto P_0c04fe78;
case 0x0c04fe7au: goto P_0c04fe7a;
case 0x0c04fe7cu: goto P_0c04fe7c;
case 0x0c04fe7eu: goto P_0c04fe7e;
case 0x0c04fe80u: goto P_0c04fe80;
case 0x0c04fe82u: goto P_0c04fe82;
case 0x0c04fe84u: goto P_0c04fe84;
case 0x0c04fe86u: goto P_0c04fe86;
case 0x0c04fe88u: goto P_0c04fe88;
case 0x0c04fe8au: goto P_0c04fe8a;
case 0x0c04fe8cu: goto P_0c04fe8c;
case 0x0c04fe8eu: goto P_0c04fe8e;
case 0x0c04fe90u: goto P_0c04fe90;
case 0x0c04fe92u: goto P_0c04fe92;
case 0x0c04fe94u: goto P_0c04fe94;
case 0x0c04fe96u: goto P_0c04fe96;
case 0x0c04fe98u: goto P_0c04fe98;
case 0x0c04fe9au: goto P_0c04fe9a;
case 0x0c04fe9cu: goto P_0c04fe9c;
case 0x0c04fe9eu: goto P_0c04fe9e;
case 0x0c04fea0u: goto P_0c04fea0;
case 0x0c04fea2u: goto P_0c04fea2;
case 0x0c04fea4u: goto P_0c04fea4;
case 0x0c04fea6u: goto P_0c04fea6;
case 0x0c04fea8u: goto P_0c04fea8;
case 0x0c04feaau: goto P_0c04feaa;
case 0x0c04feacu: goto P_0c04feac;
case 0x0c04feaeu: goto P_0c04feae;
case 0x0c04feb0u: goto P_0c04feb0;
case 0x0c04feb2u: goto P_0c04feb2;
case 0x0c04feb4u: goto P_0c04feb4;
case 0x0c04feb6u: goto P_0c04feb6;
case 0x0c04feb8u: goto P_0c04feb8;
case 0x0c04febau: goto P_0c04feba;
case 0x0c04febcu: goto P_0c04febc;
case 0x0c04febeu: goto P_0c04febe;
case 0x0c04fec0u: goto P_0c04fec0;
case 0x0c04fec2u: goto P_0c04fec2;
case 0x0c04ff80u: goto P_0c04ff80;
case 0x0c04ff82u: goto P_0c04ff82;
case 0x0c04ff84u: goto P_0c04ff84;
case 0x0c04ff86u: goto P_0c04ff86;
case 0x0c04ff88u: goto P_0c04ff88;
case 0x0c04ff8au: goto P_0c04ff8a;
case 0x0c04ff8cu: goto P_0c04ff8c;
case 0x0c04ff8eu: goto P_0c04ff8e;
case 0x0c04ff90u: goto P_0c04ff90;
case 0x0c04ff92u: goto P_0c04ff92;
case 0x0c04ff94u: goto P_0c04ff94;
case 0x0c04ff96u: goto P_0c04ff96;
case 0x0c04ff98u: goto P_0c04ff98;
case 0x0c04ff9au: goto P_0c04ff9a;
case 0x0c04ff9cu: goto P_0c04ff9c;
case 0x0c04ff9eu: goto P_0c04ff9e;
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
case 0x0c068c58u: goto P_0c068c58;
case 0x0c068c5au: goto P_0c068c5a;
case 0x0c068c5cu: goto P_0c068c5c;
case 0x0c068c5eu: goto P_0c068c5e;
case 0x0c068c60u: goto P_0c068c60;
case 0x0c068c62u: goto P_0c068c62;
case 0x0c068c64u: goto P_0c068c64;
case 0x0c068c66u: goto P_0c068c66;
case 0x0c068c68u: goto P_0c068c68;
case 0x0c068c6au: goto P_0c068c6a;
case 0x0c068c6cu: goto P_0c068c6c;
case 0x0c068c6eu: goto P_0c068c6e;
case 0x0c068c70u: goto P_0c068c70;
case 0x0c068c72u: goto P_0c068c72;
case 0x0c068c74u: goto P_0c068c74;
case 0x0c068c76u: goto P_0c068c76;
case 0x0c068c78u: goto P_0c068c78;
case 0x0c068c7au: goto P_0c068c7a;
case 0x0c068c7cu: goto P_0c068c7c;
case 0x0c068c7eu: goto P_0c068c7e;
case 0x0c068c80u: goto P_0c068c80;
case 0x0c068c82u: goto P_0c068c82;
case 0x0c068c84u: goto P_0c068c84;
case 0x0c068c86u: goto P_0c068c86;
case 0x0c068c88u: goto P_0c068c88;
case 0x0c068c8au: goto P_0c068c8a;
case 0x0c068c8cu: goto P_0c068c8c;
case 0x0c068c8eu: goto P_0c068c8e;
case 0x0c068c90u: goto P_0c068c90;
case 0x0c068c92u: goto P_0c068c92;
case 0x0c068c94u: goto P_0c068c94;
case 0x0c068c96u: goto P_0c068c96;
case 0x0c068c98u: goto P_0c068c98;
case 0x0c068c9au: goto P_0c068c9a;
case 0x0c068c9cu: goto P_0c068c9c;
case 0x0c068c9eu: goto P_0c068c9e;
case 0x0c068ca0u: goto P_0c068ca0;
case 0x0c068ca2u: goto P_0c068ca2;
case 0x0c068ca4u: goto P_0c068ca4;
case 0x0c068ca6u: goto P_0c068ca6;
case 0x0c068ca8u: goto P_0c068ca8;
case 0x0c068caau: goto P_0c068caa;
case 0x0c068cacu: goto P_0c068cac;
case 0x0c068caeu: goto P_0c068cae;
case 0x0c068cb0u: goto P_0c068cb0;
case 0x0c068cb2u: goto P_0c068cb2;
case 0x0c068cb4u: goto P_0c068cb4;
case 0x0c068cb6u: goto P_0c068cb6;
case 0x0c068cb8u: goto P_0c068cb8;
case 0x0c068cbau: goto P_0c068cba;
case 0x0c068cbcu: goto P_0c068cbc;
case 0x0c068cbeu: goto P_0c068cbe;
case 0x0c068cc0u: goto P_0c068cc0;
case 0x0c068cc2u: goto P_0c068cc2;
case 0x0c068cc4u: goto P_0c068cc4;
case 0x0c068cc6u: goto P_0c068cc6;
case 0x0c068cc8u: goto P_0c068cc8;
case 0x0c068ccau: goto P_0c068cca;
case 0x0c068cccu: goto P_0c068ccc;
case 0x0c068cceu: goto P_0c068cce;
case 0x0c068cd0u: goto P_0c068cd0;
case 0x0c068cd2u: goto P_0c068cd2;
case 0x0c068cd4u: goto P_0c068cd4;
case 0x0c068cd6u: goto P_0c068cd6;
case 0x0c068cd8u: goto P_0c068cd8;
case 0x0c068cdau: goto P_0c068cda;
case 0x0c068cdcu: goto P_0c068cdc;
case 0x0c068cdeu: goto P_0c068cde;
case 0x0c068ce0u: goto P_0c068ce0;
case 0x0c068ce2u: goto P_0c068ce2;
case 0x0c068ce4u: goto P_0c068ce4;
case 0x0c068ce6u: goto P_0c068ce6;
case 0x0c068ce8u: goto P_0c068ce8;
case 0x0c068ceau: goto P_0c068cea;
case 0x0c068cecu: goto P_0c068cec;
case 0x0c068ceeu: goto P_0c068cee;
case 0x0c068cf0u: goto P_0c068cf0;
case 0x0c068cf2u: goto P_0c068cf2;
case 0x0c068cf4u: goto P_0c068cf4;
case 0x0c068cf6u: goto P_0c068cf6;
case 0x0c068cf8u: goto P_0c068cf8;
case 0x0c068cfau: goto P_0c068cfa;
case 0x0c068cfcu: goto P_0c068cfc;
case 0x0c068cfeu: goto P_0c068cfe;
case 0x0c068d00u: goto P_0c068d00;
case 0x0c068d02u: goto P_0c068d02;
case 0x0c068d04u: goto P_0c068d04;
case 0x0c068d06u: goto P_0c068d06;
case 0x0c068d08u: goto P_0c068d08;
case 0x0c068d0au: goto P_0c068d0a;
case 0x0c068d0cu: goto P_0c068d0c;
case 0x0c074800u: goto P_0c074800;
case 0x0c074802u: goto P_0c074802;
case 0x0c074804u: goto P_0c074804;
case 0x0c074806u: goto P_0c074806;
case 0x0c074808u: goto P_0c074808;
case 0x0c07480au: goto P_0c07480a;
case 0x0c07480cu: goto P_0c07480c;
case 0x0c07480eu: goto P_0c07480e;
case 0x0c074810u: goto P_0c074810;
case 0x0c074812u: goto P_0c074812;
case 0x0c074814u: goto P_0c074814;
case 0x0c074816u: goto P_0c074816;
case 0x0c074818u: goto P_0c074818;
case 0x0c07481au: goto P_0c07481a;
case 0x0c07481cu: goto P_0c07481c;
case 0x0c07481eu: goto P_0c07481e;
case 0x0c074820u: goto P_0c074820;
case 0x0c074822u: goto P_0c074822;
case 0x0c074824u: goto P_0c074824;
case 0x0c074826u: goto P_0c074826;
case 0x0c074828u: goto P_0c074828;
case 0x0c07482au: goto P_0c07482a;
case 0x0c07482cu: goto P_0c07482c;
case 0x0c088dd4u: goto P_0c088dd4;
case 0x0c088dd6u: goto P_0c088dd6;
case 0x0c088dd8u: goto P_0c088dd8;
case 0x0c088ddau: goto P_0c088dda;
case 0x0c088ddcu: goto P_0c088ddc;
case 0x0c088ddeu: goto P_0c088dde;
case 0x0c088de0u: goto P_0c088de0;
case 0x0c088de2u: goto P_0c088de2;
case 0x0c088de4u: goto P_0c088de4;
case 0x0c088de6u: goto P_0c088de6;
case 0x0c088de8u: goto P_0c088de8;
case 0x0c088deau: goto P_0c088dea;
case 0x0c088decu: goto P_0c088dec;
case 0x0c088deeu: goto P_0c088dee;
case 0x0c088df0u: goto P_0c088df0;
case 0x0c088df2u: goto P_0c088df2;
case 0x0c088df4u: goto P_0c088df4;
case 0x0c088df6u: goto P_0c088df6;
case 0x0c088df8u: goto P_0c088df8;
case 0x0c088dfau: goto P_0c088dfa;
case 0x0c088dfcu: goto P_0c088dfc;
case 0x0c088dfeu: goto P_0c088dfe;
case 0x0c088e00u: goto P_0c088e00;
case 0x0c088e02u: goto P_0c088e02;
case 0x0c088e04u: goto P_0c088e04;
case 0x0c088e06u: goto P_0c088e06;
case 0x0c088e08u: goto P_0c088e08;
case 0x0c088e0au: goto P_0c088e0a;
case 0x0c088e0cu: goto P_0c088e0c;
case 0x0c088e0eu: goto P_0c088e0e;
case 0x0c088e10u: goto P_0c088e10;
case 0x0c088e12u: goto P_0c088e12;
case 0x0c088e14u: goto P_0c088e14;
case 0x0c088e16u: goto P_0c088e16;
case 0x0c088e18u: goto P_0c088e18;
case 0x0c088e1au: goto P_0c088e1a;
case 0x0c088e1cu: goto P_0c088e1c;
case 0x0c088e1eu: goto P_0c088e1e;
case 0x0c088e20u: goto P_0c088e20;
case 0x0c088e22u: goto P_0c088e22;
case 0x0c088e24u: goto P_0c088e24;
case 0x0c088e26u: goto P_0c088e26;
case 0x0c088e28u: goto P_0c088e28;
case 0x0c088e2au: goto P_0c088e2a;
case 0x0c088e2cu: goto P_0c088e2c;
case 0x0c088e2eu: goto P_0c088e2e;
case 0x0c088e30u: goto P_0c088e30;
case 0x0c088e32u: goto P_0c088e32;
case 0x0c088e34u: goto P_0c088e34;
case 0x0c088e36u: goto P_0c088e36;
case 0x0c088e38u: goto P_0c088e38;
case 0x0c088e3au: goto P_0c088e3a;
case 0x0c088e3cu: goto P_0c088e3c;
case 0x0c088e3eu: goto P_0c088e3e;
case 0x0c088e40u: goto P_0c088e40;
case 0x0c088e42u: goto P_0c088e42;
case 0x0c088e44u: goto P_0c088e44;
case 0x0c088e46u: goto P_0c088e46;
case 0x0c088e48u: goto P_0c088e48;
case 0x0c088e4au: goto P_0c088e4a;
case 0x0c088e4cu: goto P_0c088e4c;
case 0x0c088e4eu: goto P_0c088e4e;
case 0x0c088e50u: goto P_0c088e50;
case 0x0c088e52u: goto P_0c088e52;
case 0x0c088e54u: goto P_0c088e54;
case 0x0c088e56u: goto P_0c088e56;
case 0x0c088e58u: goto P_0c088e58;
case 0x0c088e5au: goto P_0c088e5a;
case 0x0c088e5cu: goto P_0c088e5c;
case 0x0c088e5eu: goto P_0c088e5e;
case 0x0c088e60u: goto P_0c088e60;
case 0x0c088e62u: goto P_0c088e62;
case 0x0c088e64u: goto P_0c088e64;
case 0x0c088e66u: goto P_0c088e66;
case 0x0c088e68u: goto P_0c088e68;
case 0x0c088e6au: goto P_0c088e6a;
case 0x0c088e6cu: goto P_0c088e6c;
case 0x0c088e6eu: goto P_0c088e6e;
case 0x0c088e70u: goto P_0c088e70;
case 0x0c088e72u: goto P_0c088e72;
case 0x0c088e74u: goto P_0c088e74;
case 0x0c088e76u: goto P_0c088e76;
case 0x0c088e78u: goto P_0c088e78;
case 0x0c088e7au: goto P_0c088e7a;
case 0x0c088e7cu: goto P_0c088e7c;
case 0x0c088e7eu: goto P_0c088e7e;
case 0x0c088e80u: goto P_0c088e80;
case 0x0c088e82u: goto P_0c088e82;
case 0x0c088e84u: goto P_0c088e84;
case 0x0c088e86u: goto P_0c088e86;
case 0x0c088e88u: goto P_0c088e88;
case 0x0c088e8au: goto P_0c088e8a;
case 0x0c088e8cu: goto P_0c088e8c;
case 0x0c088e8eu: goto P_0c088e8e;
case 0x0c088e90u: goto P_0c088e90;
case 0x0c088e92u: goto P_0c088e92;
case 0x0c088e94u: goto P_0c088e94;
case 0x0c088e96u: goto P_0c088e96;
case 0x0c088e98u: goto P_0c088e98;
case 0x0c088e9au: goto P_0c088e9a;
case 0x0c088e9cu: goto P_0c088e9c;
case 0x0c088e9eu: goto P_0c088e9e;
case 0x0c088ea0u: goto P_0c088ea0;
case 0x0c088ea2u: goto P_0c088ea2;
case 0x0c088ea4u: goto P_0c088ea4;
case 0x0c088ea6u: goto P_0c088ea6;
case 0x0c088ea8u: goto P_0c088ea8;
case 0x0c088eaau: goto P_0c088eaa;
case 0x0c088eacu: goto P_0c088eac;
case 0x0c088eaeu: goto P_0c088eae;
case 0x0c088eb0u: goto P_0c088eb0;
case 0x0c088eb2u: goto P_0c088eb2;
case 0x0c088eb4u: goto P_0c088eb4;
case 0x0c088eb6u: goto P_0c088eb6;
case 0x0c088eb8u: goto P_0c088eb8;
case 0x0c088ebau: goto P_0c088eba;
case 0x0c088ebcu: goto P_0c088ebc;
case 0x0c088ebeu: goto P_0c088ebe;
case 0x0c088ec0u: goto P_0c088ec0;
case 0x0c088ec2u: goto P_0c088ec2;
case 0x0c088ec4u: goto P_0c088ec4;
case 0x0c088ec6u: goto P_0c088ec6;
case 0x0c088ec8u: goto P_0c088ec8;
case 0x0c0993e8u: goto P_0c0993e8;
case 0x0c0993eau: goto P_0c0993ea;
case 0x0c0993ecu: goto P_0c0993ec;
case 0x0c0993eeu: goto P_0c0993ee;
case 0x0c0993f0u: goto P_0c0993f0;
case 0x0c0993f2u: goto P_0c0993f2;
case 0x0c0993f4u: goto P_0c0993f4;
case 0x0c0993f6u: goto P_0c0993f6;
case 0x0c0993f8u: goto P_0c0993f8;
case 0x0c0993fau: goto P_0c0993fa;
case 0x0c0993fcu: goto P_0c0993fc;
case 0x0c0993feu: goto P_0c0993fe;
case 0x0c099400u: goto P_0c099400;
case 0x0c099402u: goto P_0c099402;
case 0x0c099404u: goto P_0c099404;
case 0x0c099406u: goto P_0c099406;
case 0x0c099408u: goto P_0c099408;
case 0x0c09940au: goto P_0c09940a;
case 0x0c09940cu: goto P_0c09940c;
case 0x0c09940eu: goto P_0c09940e;
case 0x0c099410u: goto P_0c099410;
case 0x0c099412u: goto P_0c099412;
case 0x0c099414u: goto P_0c099414;
case 0x0c099416u: goto P_0c099416;
case 0x0c099418u: goto P_0c099418;
case 0x0c09941au: goto P_0c09941a;
case 0x0c09941cu: goto P_0c09941c;
case 0x0c09941eu: goto P_0c09941e;
case 0x0c099420u: goto P_0c099420;
case 0x0c099422u: goto P_0c099422;
case 0x0c099424u: goto P_0c099424;
case 0x0c099426u: goto P_0c099426;
case 0x0c099428u: goto P_0c099428;
case 0x0c09942au: goto P_0c09942a;
case 0x0c09942cu: goto P_0c09942c;
case 0x0c09942eu: goto P_0c09942e;
case 0x0c099430u: goto P_0c099430;
case 0x0c099432u: goto P_0c099432;
case 0x0c099434u: goto P_0c099434;
case 0x0c099436u: goto P_0c099436;
case 0x0c099438u: goto P_0c099438;
case 0x0c09943au: goto P_0c09943a;
case 0x0c09943cu: goto P_0c09943c;
case 0x0c09943eu: goto P_0c09943e;
case 0x0c099440u: goto P_0c099440;
case 0x0c099442u: goto P_0c099442;
case 0x0c099444u: goto P_0c099444;
case 0x0c099446u: goto P_0c099446;
case 0x0c099448u: goto P_0c099448;
case 0x0c09944au: goto P_0c09944a;
case 0x0c09944cu: goto P_0c09944c;
case 0x0c09944eu: goto P_0c09944e;
case 0x0c099450u: goto P_0c099450;
case 0x0c099452u: goto P_0c099452;
case 0x0c099454u: goto P_0c099454;
case 0x0c099456u: goto P_0c099456;
case 0x0c099458u: goto P_0c099458;
case 0x0c09945au: goto P_0c09945a;
case 0x0c09945cu: goto P_0c09945c;
case 0x0c09945eu: goto P_0c09945e;
case 0x0c099460u: goto P_0c099460;
case 0x0c099462u: goto P_0c099462;
case 0x0c099464u: goto P_0c099464;
case 0x0c099466u: goto P_0c099466;
case 0x0c099468u: goto P_0c099468;
case 0x0c09946au: goto P_0c09946a;
case 0x0c09946cu: goto P_0c09946c;
case 0x0c09946eu: goto P_0c09946e;
case 0x0c099470u: goto P_0c099470;
case 0x0c099472u: goto P_0c099472;
case 0x0c099474u: goto P_0c099474;
case 0x0c099476u: goto P_0c099476;
case 0x0c099478u: goto P_0c099478;
case 0x0c09947au: goto P_0c09947a;
case 0x0c09947cu: goto P_0c09947c;
case 0x0c09947eu: goto P_0c09947e;
case 0x0c099480u: goto P_0c099480;
case 0x0c099482u: goto P_0c099482;
case 0x0c099484u: goto P_0c099484;
case 0x0c099486u: goto P_0c099486;
case 0x0c099488u: goto P_0c099488;
case 0x0c09948au: goto P_0c09948a;
case 0x0c09948cu: goto P_0c09948c;
case 0x0c09948eu: goto P_0c09948e;
case 0x0c099490u: goto P_0c099490;
case 0x0c099492u: goto P_0c099492;
case 0x0c099494u: goto P_0c099494;
case 0x0c099496u: goto P_0c099496;
case 0x0c099498u: goto P_0c099498;
case 0x0c09949au: goto P_0c09949a;
case 0x0c09949cu: goto P_0c09949c;
case 0x0c09949eu: goto P_0c09949e;
case 0x0c0994a0u: goto P_0c0994a0;
case 0x0c0994a2u: goto P_0c0994a2;
case 0x0c0994a4u: goto P_0c0994a4;
case 0x0c0994a6u: goto P_0c0994a6;
case 0x0c0994a8u: goto P_0c0994a8;
case 0x0c0994aau: goto P_0c0994aa;
case 0x0c0994d4u: goto P_0c0994d4;
case 0x0c0994d6u: goto P_0c0994d6;
case 0x0c0994d8u: goto P_0c0994d8;
case 0x0c0994dau: goto P_0c0994da;
case 0x0c0994dcu: goto P_0c0994dc;
case 0x0c0994deu: goto P_0c0994de;
case 0x0c0994e0u: goto P_0c0994e0;
case 0x0c0994e2u: goto P_0c0994e2;
case 0x0c0994e4u: goto P_0c0994e4;
case 0x0c0994e6u: goto P_0c0994e6;
case 0x0c0994e8u: goto P_0c0994e8;
case 0x0c0994eau: goto P_0c0994ea;
case 0x0c0994ecu: goto P_0c0994ec;
case 0x0c0994eeu: goto P_0c0994ee;
case 0x0c0994f0u: goto P_0c0994f0;
case 0x0c0994f2u: goto P_0c0994f2;
case 0x0c0994f4u: goto P_0c0994f4;
case 0x0c0994f6u: goto P_0c0994f6;
case 0x0c0994f8u: goto P_0c0994f8;
case 0x0c0994fau: goto P_0c0994fa;
case 0x0c0994fcu: goto P_0c0994fc;
case 0x0c0994feu: goto P_0c0994fe;
case 0x0c099500u: goto P_0c099500;
case 0x0c099502u: goto P_0c099502;
case 0x0c099504u: goto P_0c099504;
case 0x0c099506u: goto P_0c099506;
case 0x0c099508u: goto P_0c099508;
case 0x0c09950au: goto P_0c09950a;
case 0x0c09950cu: goto P_0c09950c;
case 0x0c09950eu: goto P_0c09950e;
case 0x0c099510u: goto P_0c099510;
case 0x0c099512u: goto P_0c099512;
case 0x0c099514u: goto P_0c099514;
case 0x0c099516u: goto P_0c099516;
case 0x0c099518u: goto P_0c099518;
case 0x0c09951au: goto P_0c09951a;
case 0x0c09951cu: goto P_0c09951c;
case 0x0c09951eu: goto P_0c09951e;
case 0x0c099520u: goto P_0c099520;
case 0x0c099522u: goto P_0c099522;
case 0x0c099524u: goto P_0c099524;
case 0x0c099526u: goto P_0c099526;
case 0x0c099528u: goto P_0c099528;
case 0x0c09952au: goto P_0c09952a;
case 0x0c09952cu: goto P_0c09952c;
case 0x0c09952eu: goto P_0c09952e;
case 0x0c099530u: goto P_0c099530;
case 0x0c099532u: goto P_0c099532;
case 0x0c099534u: goto P_0c099534;
case 0x0c099536u: goto P_0c099536;
case 0x0c099538u: goto P_0c099538;
case 0x0c09953au: goto P_0c09953a;
case 0x0c09953cu: goto P_0c09953c;
case 0x0c09953eu: goto P_0c09953e;
case 0x0c099540u: goto P_0c099540;
case 0x0c099542u: goto P_0c099542;
case 0x0c099544u: goto P_0c099544;
case 0x0c099546u: goto P_0c099546;
case 0x0c099548u: goto P_0c099548;
case 0x0c09954au: goto P_0c09954a;
case 0x0c09954cu: goto P_0c09954c;
case 0x0c09954eu: goto P_0c09954e;
case 0x0c099550u: goto P_0c099550;
case 0x0c099552u: goto P_0c099552;
case 0x0c099554u: goto P_0c099554;
case 0x0c099556u: goto P_0c099556;
case 0x0c099558u: goto P_0c099558;
case 0x0c09955au: goto P_0c09955a;
case 0x0c09955cu: goto P_0c09955c;
case 0x0c09955eu: goto P_0c09955e;
case 0x0c099560u: goto P_0c099560;
case 0x0c099562u: goto P_0c099562;
case 0x0c099564u: goto P_0c099564;
case 0x0c099566u: goto P_0c099566;
case 0x0c099568u: goto P_0c099568;
case 0x0c09956au: goto P_0c09956a;
case 0x0c09956cu: goto P_0c09956c;
case 0x0c09956eu: goto P_0c09956e;
case 0x0c099570u: goto P_0c099570;
case 0x0c099572u: goto P_0c099572;
case 0x0c099574u: goto P_0c099574;
case 0x0c099576u: goto P_0c099576;
case 0x0c099578u: goto P_0c099578;
case 0x0c09957au: goto P_0c09957a;
case 0x0c09957cu: goto P_0c09957c;
case 0x0c09957eu: goto P_0c09957e;
case 0x0c099580u: goto P_0c099580;
case 0x0c099582u: goto P_0c099582;
case 0x0c099584u: goto P_0c099584;
case 0x0c099586u: goto P_0c099586;
case 0x0c099588u: goto P_0c099588;
case 0x0c09958au: goto P_0c09958a;
case 0x0c09958cu: goto P_0c09958c;
case 0x0c09958eu: goto P_0c09958e;
case 0x0c099590u: goto P_0c099590;
case 0x0c099592u: goto P_0c099592;
case 0x0c099594u: goto P_0c099594;
case 0x0c099596u: goto P_0c099596;
case 0x0c099598u: goto P_0c099598;
case 0x0c09959au: goto P_0c09959a;
case 0x0c09959cu: goto P_0c09959c;
case 0x0c09959eu: goto P_0c09959e;
case 0x0c0995a0u: goto P_0c0995a0;
case 0x0c0995dcu: goto P_0c0995dc;
case 0x0c0995deu: goto P_0c0995de;
case 0x0c0995e0u: goto P_0c0995e0;
case 0x0c0995e2u: goto P_0c0995e2;
case 0x0c0995e4u: goto P_0c0995e4;
case 0x0c0995e6u: goto P_0c0995e6;
case 0x0c0995e8u: goto P_0c0995e8;
case 0x0c0995eau: goto P_0c0995ea;
case 0x0c0995ecu: goto P_0c0995ec;
case 0x0c0995eeu: goto P_0c0995ee;
case 0x0c0995f0u: goto P_0c0995f0;
case 0x0c0995f2u: goto P_0c0995f2;
case 0x0c0995f4u: goto P_0c0995f4;
case 0x0c0995f6u: goto P_0c0995f6;
case 0x0c0995f8u: goto P_0c0995f8;
case 0x0c0995fau: goto P_0c0995fa;
case 0x0c0995fcu: goto P_0c0995fc;
case 0x0c0995feu: goto P_0c0995fe;
case 0x0c099600u: goto P_0c099600;
case 0x0c099602u: goto P_0c099602;
case 0x0c099604u: goto P_0c099604;
case 0x0c099606u: goto P_0c099606;
case 0x0c099608u: goto P_0c099608;
case 0x0c09960au: goto P_0c09960a;
case 0x0c09960cu: goto P_0c09960c;
case 0x0c09960eu: goto P_0c09960e;
case 0x0c099610u: goto P_0c099610;
case 0x0c099612u: goto P_0c099612;
case 0x0c099614u: goto P_0c099614;
case 0x0c099616u: goto P_0c099616;
case 0x0c099618u: goto P_0c099618;
case 0x0c09961au: goto P_0c09961a;
case 0x0c09961cu: goto P_0c09961c;
case 0x0c09961eu: goto P_0c09961e;
case 0x0c099620u: goto P_0c099620;
case 0x0c099622u: goto P_0c099622;
case 0x0c099624u: goto P_0c099624;
case 0x0c099626u: goto P_0c099626;
case 0x0c099628u: goto P_0c099628;
case 0x0c09962au: goto P_0c09962a;
case 0x0c09962cu: goto P_0c09962c;
case 0x0c09962eu: goto P_0c09962e;
case 0x0c099630u: goto P_0c099630;
case 0x0c099632u: goto P_0c099632;
case 0x0c099634u: goto P_0c099634;
case 0x0c099636u: goto P_0c099636;
case 0x0c099638u: goto P_0c099638;
case 0x0c09963au: goto P_0c09963a;
case 0x0c09963cu: goto P_0c09963c;
case 0x0c09963eu: goto P_0c09963e;
case 0x0c099640u: goto P_0c099640;
case 0x0c099642u: goto P_0c099642;
case 0x0c099644u: goto P_0c099644;
case 0x0c099646u: goto P_0c099646;
case 0x0c099648u: goto P_0c099648;
case 0x0c09964au: goto P_0c09964a;
case 0x0c09964cu: goto P_0c09964c;
case 0x0c09964eu: goto P_0c09964e;
case 0x0c099650u: goto P_0c099650;
case 0x0c099652u: goto P_0c099652;
case 0x0c099654u: goto P_0c099654;
case 0x0c099656u: goto P_0c099656;
case 0x0c099658u: goto P_0c099658;
case 0x0c09965au: goto P_0c09965a;
case 0x0c09965cu: goto P_0c09965c;
case 0x0c09965eu: goto P_0c09965e;
case 0x0c099660u: goto P_0c099660;
case 0x0c099662u: goto P_0c099662;
case 0x0c099664u: goto P_0c099664;
case 0x0c099666u: goto P_0c099666;
case 0x0c099668u: goto P_0c099668;
case 0x0c09966au: goto P_0c09966a;
case 0x0c09966cu: goto P_0c09966c;
case 0x0c09966eu: goto P_0c09966e;
case 0x0c099670u: goto P_0c099670;
case 0x0c099672u: goto P_0c099672;
case 0x0c099674u: goto P_0c099674;
case 0x0c099676u: goto P_0c099676;
case 0x0c099678u: goto P_0c099678;
case 0x0c09967au: goto P_0c09967a;
case 0x0c09967cu: goto P_0c09967c;
case 0x0c09967eu: goto P_0c09967e;
case 0x0c099680u: goto P_0c099680;
case 0x0c099682u: goto P_0c099682;
case 0x0c099684u: goto P_0c099684;
case 0x0c099686u: goto P_0c099686;
case 0x0c099688u: goto P_0c099688;
case 0x0c09968au: goto P_0c09968a;
case 0x0c09968cu: goto P_0c09968c;
case 0x0c09968eu: goto P_0c09968e;
case 0x0c099690u: goto P_0c099690;
case 0x0c099692u: goto P_0c099692;
case 0x0c099694u: goto P_0c099694;
case 0x0c099696u: goto P_0c099696;
case 0x0c099698u: goto P_0c099698;
case 0x0c09969au: goto P_0c09969a;
case 0x0c09969cu: goto P_0c09969c;
case 0x0c09969eu: goto P_0c09969e;
case 0x0c0996a0u: goto P_0c0996a0;
case 0x0c0996a2u: goto P_0c0996a2;
case 0x0c0996a4u: goto P_0c0996a4;
case 0x0c0996a6u: goto P_0c0996a6;
case 0x0c0996a8u: goto P_0c0996a8;
case 0x0c0996aau: goto P_0c0996aa;
case 0x0c0996acu: goto P_0c0996ac;
case 0x0c0996aeu: goto P_0c0996ae;
case 0x0c0996b0u: goto P_0c0996b0;
case 0x0c0996b2u: goto P_0c0996b2;
case 0x0c0996b4u: goto P_0c0996b4;
case 0x0c0996b6u: goto P_0c0996b6;
case 0x0c0996b8u: goto P_0c0996b8;
case 0x0c0996bau: goto P_0c0996ba;
case 0x0c0996bcu: goto P_0c0996bc;
case 0x0c0996beu: goto P_0c0996be;
case 0x0c0996c0u: goto P_0c0996c0;
case 0x0c0996c2u: goto P_0c0996c2;
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
case 0x0c0a8acau: goto P_0c0a8aca;
case 0x0c0a8accu: goto P_0c0a8acc;
case 0x0c0a8aceu: goto P_0c0a8ace;
case 0x0c0a8ad0u: goto P_0c0a8ad0;
case 0x0c0a8ad2u: goto P_0c0a8ad2;
case 0x0c0a8ad4u: goto P_0c0a8ad4;
case 0x0c0a8ad6u: goto P_0c0a8ad6;
case 0x0c0a8ad8u: goto P_0c0a8ad8;
case 0x0c0a8adau: goto P_0c0a8ada;
case 0x0c0a8adcu: goto P_0c0a8adc;
case 0x0c0a8adeu: goto P_0c0a8ade;
case 0x0c0a8ae0u: goto P_0c0a8ae0;
case 0x0c0a8ae2u: goto P_0c0a8ae2;
case 0x0c0a8ae4u: goto P_0c0a8ae4;
case 0x0c0a8ae6u: goto P_0c0a8ae6;
case 0x0c0a8ae8u: goto P_0c0a8ae8;
case 0x0c0a8aeau: goto P_0c0a8aea;
case 0x0c0a8aecu: goto P_0c0a8aec;
case 0x0c0a8aeeu: goto P_0c0a8aee;
case 0x0c0a8af0u: goto P_0c0a8af0;
case 0x0c0a8af2u: goto P_0c0a8af2;
case 0x0c0a8af4u: goto P_0c0a8af4;
case 0x0c0a8af6u: goto P_0c0a8af6;
case 0x0c0a8af8u: goto P_0c0a8af8;
case 0x0c0a8afau: goto P_0c0a8afa;
case 0x0c0a8afcu: goto P_0c0a8afc;
case 0x0c0a8afeu: goto P_0c0a8afe;
case 0x0c0a8b00u: goto P_0c0a8b00;
case 0x0c0a8b02u: goto P_0c0a8b02;
case 0x0c0a8b04u: goto P_0c0a8b04;
case 0x0c0a8b06u: goto P_0c0a8b06;
case 0x0c0a8b08u: goto P_0c0a8b08;
case 0x0c0a8b0au: goto P_0c0a8b0a;
case 0x0c0a8b0cu: goto P_0c0a8b0c;
case 0x0c0a8b0eu: goto P_0c0a8b0e;
case 0x0c0a8b10u: goto P_0c0a8b10;
case 0x0c0a8b12u: goto P_0c0a8b12;
case 0x0c0a8b14u: goto P_0c0a8b14;
case 0x0c0a8b16u: goto P_0c0a8b16;
case 0x0c0a8b18u: goto P_0c0a8b18;
case 0x0c0a8b1au: goto P_0c0a8b1a;
case 0x0c0a8b1cu: goto P_0c0a8b1c;
case 0x0c0a8b1eu: goto P_0c0a8b1e;
case 0x0c0a8b20u: goto P_0c0a8b20;
case 0x0c0a8b22u: goto P_0c0a8b22;
case 0x0c0a8b24u: goto P_0c0a8b24;
case 0x0c0a8b26u: goto P_0c0a8b26;
case 0x0c0a8b28u: goto P_0c0a8b28;
case 0x0c0a8b2au: goto P_0c0a8b2a;
case 0x0c0a8b2cu: goto P_0c0a8b2c;
case 0x0c0a8b2eu: goto P_0c0a8b2e;
case 0x0c0a8b30u: goto P_0c0a8b30;
case 0x0c0a8b32u: goto P_0c0a8b32;
case 0x0c0a8b34u: goto P_0c0a8b34;
case 0x0c0a8b36u: goto P_0c0a8b36;
case 0x0c0a8b38u: goto P_0c0a8b38;
case 0x0c0a8b3au: goto P_0c0a8b3a;
case 0x0c0a8b3cu: goto P_0c0a8b3c;
case 0x0c0a8b3eu: goto P_0c0a8b3e;
case 0x0c0a8b40u: goto P_0c0a8b40;
case 0x0c0a8b42u: goto P_0c0a8b42;
case 0x0c0a8b44u: goto P_0c0a8b44;
case 0x0c0a8b46u: goto P_0c0a8b46;
case 0x0c0a8b48u: goto P_0c0a8b48;
case 0x0c0a8b4au: goto P_0c0a8b4a;
case 0x0c0a8b4cu: goto P_0c0a8b4c;
case 0x0c0a8b4eu: goto P_0c0a8b4e;
case 0x0c0a8b50u: goto P_0c0a8b50;
case 0x0c0a8b52u: goto P_0c0a8b52;
case 0x0c0a8b54u: goto P_0c0a8b54;
case 0x0c0a8b56u: goto P_0c0a8b56;
case 0x0c0a8b58u: goto P_0c0a8b58;
case 0x0c0a8b5au: goto P_0c0a8b5a;
case 0x0c0a8b5cu: goto P_0c0a8b5c;
case 0x0c0a8b5eu: goto P_0c0a8b5e;
case 0x0c0a8b60u: goto P_0c0a8b60;
case 0x0c0a8b62u: goto P_0c0a8b62;
case 0x0c0a8b64u: goto P_0c0a8b64;
case 0x0c0a8b66u: goto P_0c0a8b66;
case 0x0c0a8b68u: goto P_0c0a8b68;
case 0x0c0a8b6au: goto P_0c0a8b6a;
case 0x0c0a8b6cu: goto P_0c0a8b6c;
case 0x0c0a8b6eu: goto P_0c0a8b6e;
case 0x0c0a8b70u: goto P_0c0a8b70;
case 0x0c0a8b72u: goto P_0c0a8b72;
case 0x0c0a8b74u: goto P_0c0a8b74;
case 0x0c0a8b76u: goto P_0c0a8b76;
case 0x0c0a8b78u: goto P_0c0a8b78;
case 0x0c0a8b7au: goto P_0c0a8b7a;
case 0x0c0a8b7cu: goto P_0c0a8b7c;
case 0x0c0a8b7eu: goto P_0c0a8b7e;
case 0x0c0a8b80u: goto P_0c0a8b80;
case 0x0c0a8b82u: goto P_0c0a8b82;
case 0x0c0a8b84u: goto P_0c0a8b84;
case 0x0c0a8b86u: goto P_0c0a8b86;
case 0x0c0a8b88u: goto P_0c0a8b88;
case 0x0c0a8b8au: goto P_0c0a8b8a;
case 0x0c0a8b8cu: goto P_0c0a8b8c;
case 0x0c0a8b8eu: goto P_0c0a8b8e;
case 0x0c0a8b90u: goto P_0c0a8b90;
case 0x0c0a8b92u: goto P_0c0a8b92;
case 0x0c0a8b94u: goto P_0c0a8b94;
case 0x0c0a8b96u: goto P_0c0a8b96;
case 0x0c0a8b98u: goto P_0c0a8b98;
case 0x0c0a8b9au: goto P_0c0a8b9a;
case 0x0c0a8b9cu: goto P_0c0a8b9c;
case 0x0c0a8b9eu: goto P_0c0a8b9e;
case 0x0c0a8ba0u: goto P_0c0a8ba0;
case 0x0c0a8ba2u: goto P_0c0a8ba2;
case 0x0c0a8ba4u: goto P_0c0a8ba4;
case 0x0c0a8ba6u: goto P_0c0a8ba6;
case 0x0c0a8ba8u: goto P_0c0a8ba8;
case 0x0c0a8baau: goto P_0c0a8baa;
case 0x0c0a8bacu: goto P_0c0a8bac;
case 0x0c0a8baeu: goto P_0c0a8bae;
case 0x0c0a8bb0u: goto P_0c0a8bb0;
case 0x0c0a8bb2u: goto P_0c0a8bb2;
case 0x0c0a8bb4u: goto P_0c0a8bb4;
case 0x0c0a8bb6u: goto P_0c0a8bb6;
case 0x0c0a8bb8u: goto P_0c0a8bb8;
case 0x0c0a8bbau: goto P_0c0a8bba;
case 0x0c0a8bbcu: goto P_0c0a8bbc;
case 0x0c0a8bbeu: goto P_0c0a8bbe;
case 0x0c0a8bc0u: goto P_0c0a8bc0;
case 0x0c0a8bc2u: goto P_0c0a8bc2;
case 0x0c0a8bc4u: goto P_0c0a8bc4;
case 0x0c0a8bc6u: goto P_0c0a8bc6;
case 0x0c0a8bc8u: goto P_0c0a8bc8;
case 0x0c0a8bcau: goto P_0c0a8bca;
case 0x0c0a8bccu: goto P_0c0a8bcc;
case 0x0c0a8bceu: goto P_0c0a8bce;
case 0x0c0a8bd0u: goto P_0c0a8bd0;
case 0x0c0a8bd2u: goto P_0c0a8bd2;
case 0x0c0a8bd4u: goto P_0c0a8bd4;
case 0x0c0a8bd6u: goto P_0c0a8bd6;
case 0x0c0a8bd8u: goto P_0c0a8bd8;
case 0x0c0a8bdau: goto P_0c0a8bda;
case 0x0c0a8bdcu: goto P_0c0a8bdc;
case 0x0c0a8bdeu: goto P_0c0a8bde;
case 0x0c0a8be0u: goto P_0c0a8be0;
case 0x0c0a8be2u: goto P_0c0a8be2;
case 0x0c0a8be4u: goto P_0c0a8be4;
case 0x0c0a8be6u: goto P_0c0a8be6;
case 0x0c0a8be8u: goto P_0c0a8be8;
case 0x0c0a8beau: goto P_0c0a8bea;
case 0x0c0a8becu: goto P_0c0a8bec;
case 0x0c0a8beeu: goto P_0c0a8bee;
case 0x0c0a8bf0u: goto P_0c0a8bf0;
case 0x0c0a8bf2u: goto P_0c0a8bf2;
case 0x0c0a8bf4u: goto P_0c0a8bf4;
case 0x0c0a8bf6u: goto P_0c0a8bf6;
case 0x0c0a8c38u: goto P_0c0a8c38;
case 0x0c0a8c3au: goto P_0c0a8c3a;
case 0x0c0a8c3cu: goto P_0c0a8c3c;
case 0x0c0a8c3eu: goto P_0c0a8c3e;
case 0x0c0a8c40u: goto P_0c0a8c40;
case 0x0c0a8c42u: goto P_0c0a8c42;
case 0x0c0a8c44u: goto P_0c0a8c44;
case 0x0c0a8c46u: goto P_0c0a8c46;
case 0x0c0a8c48u: goto P_0c0a8c48;
case 0x0c0a8c4au: goto P_0c0a8c4a;
case 0x0c0a8c4cu: goto P_0c0a8c4c;
case 0x0c0a8c4eu: goto P_0c0a8c4e;
case 0x0c0a8c50u: goto P_0c0a8c50;
case 0x0c0a8c52u: goto P_0c0a8c52;
case 0x0c0a8c54u: goto P_0c0a8c54;
case 0x0c0a8c56u: goto P_0c0a8c56;
case 0x0c0a8c58u: goto P_0c0a8c58;
case 0x0c0a8c5au: goto P_0c0a8c5a;
case 0x0c0a8c5cu: goto P_0c0a8c5c;
case 0x0c0a8c5eu: goto P_0c0a8c5e;
case 0x0c0a8c60u: goto P_0c0a8c60;
case 0x0c0a8c62u: goto P_0c0a8c62;
case 0x0c0a8c64u: goto P_0c0a8c64;
case 0x0c0a8c66u: goto P_0c0a8c66;
case 0x0c0a8c68u: goto P_0c0a8c68;
case 0x0c0a8c6au: goto P_0c0a8c6a;
case 0x0c0a8c6cu: goto P_0c0a8c6c;
case 0x0c0a8c6eu: goto P_0c0a8c6e;
case 0x0c0a8c70u: goto P_0c0a8c70;
case 0x0c0a8c72u: goto P_0c0a8c72;
case 0x0c0a8c74u: goto P_0c0a8c74;
case 0x0c0a8c76u: goto P_0c0a8c76;
case 0x0c0a8c78u: goto P_0c0a8c78;
case 0x0c0a8c7au: goto P_0c0a8c7a;
case 0x0c0a8c7cu: goto P_0c0a8c7c;
case 0x0c0a8c7eu: goto P_0c0a8c7e;
case 0x0c0a8c80u: goto P_0c0a8c80;
case 0x0c0a8c82u: goto P_0c0a8c82;
case 0x0c0a8c84u: goto P_0c0a8c84;
case 0x0c0a8c86u: goto P_0c0a8c86;
case 0x0c0a8c88u: goto P_0c0a8c88;
case 0x0c0a8c8au: goto P_0c0a8c8a;
case 0x0c0a8c8cu: goto P_0c0a8c8c;
case 0x0c0a8c8eu: goto P_0c0a8c8e;
case 0x0c0a8c90u: goto P_0c0a8c90;
case 0x0c0a8c92u: goto P_0c0a8c92;
case 0x0c0a8c94u: goto P_0c0a8c94;
case 0x0c0a8c96u: goto P_0c0a8c96;
case 0x0c0a8c98u: goto P_0c0a8c98;
case 0x0c0a8c9au: goto P_0c0a8c9a;
case 0x0c0a8c9cu: goto P_0c0a8c9c;
case 0x0c0a8c9eu: goto P_0c0a8c9e;
case 0x0c0a8ca0u: goto P_0c0a8ca0;
case 0x0c0a8ca2u: goto P_0c0a8ca2;
case 0x0c0a8ca4u: goto P_0c0a8ca4;
case 0x0c0a8ca6u: goto P_0c0a8ca6;
case 0x0c0a8ca8u: goto P_0c0a8ca8;
case 0x0c0a8caau: goto P_0c0a8caa;
case 0x0c0a8cacu: goto P_0c0a8cac;
case 0x0c0a8caeu: goto P_0c0a8cae;
case 0x0c0a8cb0u: goto P_0c0a8cb0;
case 0x0c0a8cb2u: goto P_0c0a8cb2;
case 0x0c0a8cb4u: goto P_0c0a8cb4;
case 0x0c0a8cb6u: goto P_0c0a8cb6;
case 0x0c0a8cb8u: goto P_0c0a8cb8;
case 0x0c0a8cbau: goto P_0c0a8cba;
case 0x0c0a8cbcu: goto P_0c0a8cbc;
case 0x0c0a8cbeu: goto P_0c0a8cbe;
case 0x0c0a8cc0u: goto P_0c0a8cc0;
case 0x0c0a8cc2u: goto P_0c0a8cc2;
case 0x0c0a8cc4u: goto P_0c0a8cc4;
case 0x0c0a8cc6u: goto P_0c0a8cc6;
case 0x0c0a8cc8u: goto P_0c0a8cc8;
case 0x0c0a8ccau: goto P_0c0a8cca;
case 0x0c0a8cccu: goto P_0c0a8ccc;
case 0x0c0a8cceu: goto P_0c0a8cce;
case 0x0c0a8cd0u: goto P_0c0a8cd0;
case 0x0c0a8cd2u: goto P_0c0a8cd2;
case 0x0c0a8cd4u: goto P_0c0a8cd4;
case 0x0c0a8cd6u: goto P_0c0a8cd6;
case 0x0c0a8cd8u: goto P_0c0a8cd8;
case 0x0c0a8cdau: goto P_0c0a8cda;
case 0x0c0a8cdcu: goto P_0c0a8cdc;
case 0x0c0a8cdeu: goto P_0c0a8cde;
case 0x0c0a8ce0u: goto P_0c0a8ce0;
case 0x0c0a8ce2u: goto P_0c0a8ce2;
case 0x0c0a8ce4u: goto P_0c0a8ce4;
case 0x0c0a8ce6u: goto P_0c0a8ce6;
case 0x0c0a8ce8u: goto P_0c0a8ce8;
case 0x0c0a8ceau: goto P_0c0a8cea;
case 0x0c0a8cecu: goto P_0c0a8cec;
case 0x0c0a8ceeu: goto P_0c0a8cee;
case 0x0c0a8cf0u: goto P_0c0a8cf0;
case 0x0c0a8cf2u: goto P_0c0a8cf2;
case 0x0c0a8cf4u: goto P_0c0a8cf4;
case 0x0c0a8cf6u: goto P_0c0a8cf6;
case 0x0c0a8cf8u: goto P_0c0a8cf8;
case 0x0c0a8cfau: goto P_0c0a8cfa;
case 0x0c0a8cfcu: goto P_0c0a8cfc;
case 0x0c0a8cfeu: goto P_0c0a8cfe;
case 0x0c0a8d00u: goto P_0c0a8d00;
case 0x0c0a8d02u: goto P_0c0a8d02;
case 0x0c0a8d04u: goto P_0c0a8d04;
case 0x0c0a8d06u: goto P_0c0a8d06;
case 0x0c0a8d08u: goto P_0c0a8d08;
case 0x0c0a8d0au: goto P_0c0a8d0a;
case 0x0c0a8d0cu: goto P_0c0a8d0c;
case 0x0c0a8d0eu: goto P_0c0a8d0e;
case 0x0c0a8d10u: goto P_0c0a8d10;
case 0x0c0a8d12u: goto P_0c0a8d12;
case 0x0c0a8d14u: goto P_0c0a8d14;
case 0x0c0a8d16u: goto P_0c0a8d16;
case 0x0c0a8d18u: goto P_0c0a8d18;
case 0x0c0a8d1au: goto P_0c0a8d1a;
case 0x0c0a8d1cu: goto P_0c0a8d1c;
case 0x0c0a8d1eu: goto P_0c0a8d1e;
case 0x0c0a8d20u: goto P_0c0a8d20;
case 0x0c0a8d22u: goto P_0c0a8d22;
case 0x0c0a8d24u: goto P_0c0a8d24;
case 0x0c0a8d26u: goto P_0c0a8d26;
case 0x0c0a8d28u: goto P_0c0a8d28;
case 0x0c0a8d58u: goto P_0c0a8d58;
case 0x0c0a8d5au: goto P_0c0a8d5a;
case 0x0c0a8d5cu: goto P_0c0a8d5c;
case 0x0c0a8d5eu: goto P_0c0a8d5e;
case 0x0c0a8d60u: goto P_0c0a8d60;
case 0x0c0a8d62u: goto P_0c0a8d62;
case 0x0c0a8d64u: goto P_0c0a8d64;
case 0x0c0a8d66u: goto P_0c0a8d66;
case 0x0c0a8d68u: goto P_0c0a8d68;
case 0x0c0a8d6au: goto P_0c0a8d6a;
case 0x0c0a8d6cu: goto P_0c0a8d6c;
case 0x0c0a8d6eu: goto P_0c0a8d6e;
case 0x0c0a8d70u: goto P_0c0a8d70;
case 0x0c0a8d72u: goto P_0c0a8d72;
case 0x0c0a8d74u: goto P_0c0a8d74;
case 0x0c0a8d76u: goto P_0c0a8d76;
case 0x0c0a8d78u: goto P_0c0a8d78;
case 0x0c0a8d7au: goto P_0c0a8d7a;
case 0x0c0a8d7cu: goto P_0c0a8d7c;
case 0x0c0a8d7eu: goto P_0c0a8d7e;
case 0x0c0a8d80u: goto P_0c0a8d80;
case 0x0c0a8d82u: goto P_0c0a8d82;
case 0x0c0a8d84u: goto P_0c0a8d84;
case 0x0c0a8d86u: goto P_0c0a8d86;
case 0x0c0a8d88u: goto P_0c0a8d88;
case 0x0c0a8d8au: goto P_0c0a8d8a;
case 0x0c0a8d8cu: goto P_0c0a8d8c;
case 0x0c0a8d8eu: goto P_0c0a8d8e;
case 0x0c0a8d90u: goto P_0c0a8d90;
case 0x0c0a8d92u: goto P_0c0a8d92;
case 0x0c0a8d94u: goto P_0c0a8d94;
case 0x0c0a8d96u: goto P_0c0a8d96;
case 0x0c0a8d98u: goto P_0c0a8d98;
case 0x0c0a8d9au: goto P_0c0a8d9a;
case 0x0c0a8d9cu: goto P_0c0a8d9c;
case 0x0c0a8d9eu: goto P_0c0a8d9e;
case 0x0c0a8da0u: goto P_0c0a8da0;
case 0x0c0a8da2u: goto P_0c0a8da2;
case 0x0c0a8da4u: goto P_0c0a8da4;
case 0x0c0a8da6u: goto P_0c0a8da6;
case 0x0c0a8da8u: goto P_0c0a8da8;
case 0x0c0a8daau: goto P_0c0a8daa;
case 0x0c0a8dacu: goto P_0c0a8dac;
case 0x0c0a8daeu: goto P_0c0a8dae;
case 0x0c0a8db0u: goto P_0c0a8db0;
case 0x0c0a8db2u: goto P_0c0a8db2;
case 0x0c0a8db4u: goto P_0c0a8db4;
case 0x0c0a8db6u: goto P_0c0a8db6;
case 0x0c0a8db8u: goto P_0c0a8db8;
case 0x0c0a8dbau: goto P_0c0a8dba;
case 0x0c0a8dbcu: goto P_0c0a8dbc;
case 0x0c0a8dbeu: goto P_0c0a8dbe;
case 0x0c0a8dc0u: goto P_0c0a8dc0;
case 0x0c0a8dc2u: goto P_0c0a8dc2;
case 0x0c0a8dc4u: goto P_0c0a8dc4;
case 0x0c0a8dc6u: goto P_0c0a8dc6;
case 0x0c0a8dc8u: goto P_0c0a8dc8;
case 0x0c0a8dcau: goto P_0c0a8dca;
case 0x0c0a8dccu: goto P_0c0a8dcc;
case 0x0c0a8dceu: goto P_0c0a8dce;
case 0x0c0a8dd0u: goto P_0c0a8dd0;
case 0x0c0a8dd2u: goto P_0c0a8dd2;
case 0x0c0a8dd4u: goto P_0c0a8dd4;
case 0x0c0a8dd6u: goto P_0c0a8dd6;
case 0x0c0a8dd8u: goto P_0c0a8dd8;
case 0x0c0a8ddau: goto P_0c0a8dda;
case 0x0c0a8ddcu: goto P_0c0a8ddc;
case 0x0c0a8ddeu: goto P_0c0a8dde;
case 0x0c0a8de0u: goto P_0c0a8de0;
case 0x0c0a8de2u: goto P_0c0a8de2;
case 0x0c0a8de4u: goto P_0c0a8de4;
case 0x0c0a8de6u: goto P_0c0a8de6;
case 0x0c0a8de8u: goto P_0c0a8de8;
case 0x0c0a8deau: goto P_0c0a8dea;
case 0x0c0a8decu: goto P_0c0a8dec;
case 0x0c0a8deeu: goto P_0c0a8dee;
case 0x0c0a8df0u: goto P_0c0a8df0;
case 0x0c0a8df2u: goto P_0c0a8df2;
case 0x0c0a8df4u: goto P_0c0a8df4;
case 0x0c0a8df6u: goto P_0c0a8df6;
case 0x0c0a8df8u: goto P_0c0a8df8;
case 0x0c0a8dfau: goto P_0c0a8dfa;
case 0x0c0a8dfcu: goto P_0c0a8dfc;
case 0x0c0a8dfeu: goto P_0c0a8dfe;
case 0x0c0a91dau: goto P_0c0a91da;
case 0x0c0a91dcu: goto P_0c0a91dc;
case 0x0c0a91deu: goto P_0c0a91de;
case 0x0c0a91e0u: goto P_0c0a91e0;
case 0x0c0a91e2u: goto P_0c0a91e2;
case 0x0c0a91e4u: goto P_0c0a91e4;
case 0x0c0a91e6u: goto P_0c0a91e6;
case 0x0c0a91e8u: goto P_0c0a91e8;
case 0x0c0a91eau: goto P_0c0a91ea;
case 0x0c0a91ecu: goto P_0c0a91ec;
case 0x0c0a91eeu: goto P_0c0a91ee;
case 0x0c0a91f0u: goto P_0c0a91f0;
case 0x0c0a91f2u: goto P_0c0a91f2;
case 0x0c0a91f4u: goto P_0c0a91f4;
case 0x0c0a91f6u: goto P_0c0a91f6;
case 0x0c0a91f8u: goto P_0c0a91f8;
case 0x0c0a91fau: goto P_0c0a91fa;
case 0x0c0a91fcu: goto P_0c0a91fc;
case 0x0c0a91feu: goto P_0c0a91fe;
case 0x0c0a9200u: goto P_0c0a9200;
case 0x0c0a9202u: goto P_0c0a9202;
case 0x0c0a9204u: goto P_0c0a9204;
case 0x0c0a9206u: goto P_0c0a9206;
case 0x0c0a9208u: goto P_0c0a9208;
case 0x0c0a920au: goto P_0c0a920a;
case 0x0c0a920cu: goto P_0c0a920c;
case 0x0c0a920eu: goto P_0c0a920e;
case 0x0c0a9210u: goto P_0c0a9210;
case 0x0c0a9212u: goto P_0c0a9212;
case 0x0c0a9214u: goto P_0c0a9214;
case 0x0c0a9216u: goto P_0c0a9216;
case 0x0c0a9218u: goto P_0c0a9218;
case 0x0c0a921au: goto P_0c0a921a;
case 0x0c0a921cu: goto P_0c0a921c;
case 0x0c0a921eu: goto P_0c0a921e;
case 0x0c0a9220u: goto P_0c0a9220;
case 0x0c0a9222u: goto P_0c0a9222;
case 0x0c0a9224u: goto P_0c0a9224;
case 0x0c0a9226u: goto P_0c0a9226;
case 0x0c0a9228u: goto P_0c0a9228;
case 0x0c0a922au: goto P_0c0a922a;
case 0x0c0a922cu: goto P_0c0a922c;
case 0x0c0a922eu: goto P_0c0a922e;
case 0x0c0a9230u: goto P_0c0a9230;
case 0x0c0a9232u: goto P_0c0a9232;
case 0x0c0a9234u: goto P_0c0a9234;
case 0x0c0a9236u: goto P_0c0a9236;
case 0x0c0a9238u: goto P_0c0a9238;
case 0x0c0a923au: goto P_0c0a923a;
case 0x0c0a923cu: goto P_0c0a923c;
case 0x0c0a923eu: goto P_0c0a923e;
case 0x0c0a9240u: goto P_0c0a9240;
case 0x0c0a9242u: goto P_0c0a9242;
case 0x0c0a926au: goto P_0c0a926a;
case 0x0c0a926cu: goto P_0c0a926c;
case 0x0c0a926eu: goto P_0c0a926e;
case 0x0c0a9270u: goto P_0c0a9270;
case 0x0c0a9272u: goto P_0c0a9272;
case 0x0c0a9274u: goto P_0c0a9274;
case 0x0c0a9276u: goto P_0c0a9276;
case 0x0c0a9278u: goto P_0c0a9278;
case 0x0c0a927au: goto P_0c0a927a;
case 0x0c0a927cu: goto P_0c0a927c;
case 0x0c0a927eu: goto P_0c0a927e;
case 0x0c0a9280u: goto P_0c0a9280;
case 0x0c0a9282u: goto P_0c0a9282;
case 0x0c0a9284u: goto P_0c0a9284;
case 0x0c0a9286u: goto P_0c0a9286;
case 0x0c0a9288u: goto P_0c0a9288;
case 0x0c0a928au: goto P_0c0a928a;
case 0x0c0a928cu: goto P_0c0a928c;
case 0x0c0a928eu: goto P_0c0a928e;
case 0x0c0a9290u: goto P_0c0a9290;
case 0x0c0a9444u: goto P_0c0a9444;
case 0x0c0a9446u: goto P_0c0a9446;
case 0x0c0a9448u: goto P_0c0a9448;
case 0x0c0a944au: goto P_0c0a944a;
case 0x0c0a944cu: goto P_0c0a944c;
case 0x0c0a944eu: goto P_0c0a944e;
case 0x0c0a9450u: goto P_0c0a9450;
case 0x0c0a94d0u: goto P_0c0a94d0;
case 0x0c0a94d2u: goto P_0c0a94d2;
case 0x0c0a94d4u: goto P_0c0a94d4;
case 0x0c0a94d6u: goto P_0c0a94d6;
case 0x0c0a94d8u: goto P_0c0a94d8;
case 0x0c0a94dau: goto P_0c0a94da;
case 0x0c0a94dcu: goto P_0c0a94dc;
case 0x0c0a94deu: goto P_0c0a94de;
case 0x0c0a94e0u: goto P_0c0a94e0;
case 0x0c0a94e2u: goto P_0c0a94e2;
case 0x0c0a94e4u: goto P_0c0a94e4;
case 0x0c0a94e6u: goto P_0c0a94e6;
case 0x0c0a94e8u: goto P_0c0a94e8;
case 0x0c0a94eau: goto P_0c0a94ea;
case 0x0c0a94ecu: goto P_0c0a94ec;
case 0x0c0a94eeu: goto P_0c0a94ee;
case 0x0c0a94f0u: goto P_0c0a94f0;
case 0x0c0a94f2u: goto P_0c0a94f2;
case 0x0c0a94f4u: goto P_0c0a94f4;
case 0x0c0a94f6u: goto P_0c0a94f6;
case 0x0c0a94f8u: goto P_0c0a94f8;
case 0x0c0a94fau: goto P_0c0a94fa;
case 0x0c0a94fcu: goto P_0c0a94fc;
case 0x0c0a94feu: goto P_0c0a94fe;
case 0x0c0a9500u: goto P_0c0a9500;
case 0x0c0a9502u: goto P_0c0a9502;
case 0x0c0a9504u: goto P_0c0a9504;
case 0x0c0a9506u: goto P_0c0a9506;
case 0x0c0a9508u: goto P_0c0a9508;
case 0x0c0a950au: goto P_0c0a950a;
case 0x0c0a950cu: goto P_0c0a950c;
case 0x0c0a950eu: goto P_0c0a950e;
case 0x0c0a9510u: goto P_0c0a9510;
case 0x0c0a9512u: goto P_0c0a9512;
case 0x0c0a9514u: goto P_0c0a9514;
case 0x0c0a9516u: goto P_0c0a9516;
case 0x0c0a9518u: goto P_0c0a9518;
case 0x0c0a951au: goto P_0c0a951a;
case 0x0c0a951cu: goto P_0c0a951c;
case 0x0c0a951eu: goto P_0c0a951e;
case 0x0c0a9520u: goto P_0c0a9520;
case 0x0c0a9522u: goto P_0c0a9522;
case 0x0c0a9524u: goto P_0c0a9524;
case 0x0c0a9526u: goto P_0c0a9526;
case 0x0c0a9528u: goto P_0c0a9528;
case 0x0c0a952au: goto P_0c0a952a;
case 0x0c0a952cu: goto P_0c0a952c;
case 0x0c0a952eu: goto P_0c0a952e;
case 0x0c0a9530u: goto P_0c0a9530;
case 0x0c0a9532u: goto P_0c0a9532;
case 0x0c0a9534u: goto P_0c0a9534;
case 0x0c0a9536u: goto P_0c0a9536;
case 0x0c0a9538u: goto P_0c0a9538;
case 0x0c0a953au: goto P_0c0a953a;
case 0x0c0a953cu: goto P_0c0a953c;
case 0x0c0a953eu: goto P_0c0a953e;
case 0x0c0a9540u: goto P_0c0a9540;
case 0x0c0a9542u: goto P_0c0a9542;
case 0x0c0a9544u: goto P_0c0a9544;
case 0x0c0a9546u: goto P_0c0a9546;
case 0x0c0a9548u: goto P_0c0a9548;
case 0x0c0a954au: goto P_0c0a954a;
case 0x0c0a954cu: goto P_0c0a954c;
case 0x0c0a954eu: goto P_0c0a954e;
case 0x0c0a9550u: goto P_0c0a9550;
case 0x0c0a9552u: goto P_0c0a9552;
case 0x0c0a9554u: goto P_0c0a9554;
case 0x0c0a9556u: goto P_0c0a9556;
case 0x0c0a9558u: goto P_0c0a9558;
case 0x0c0a955au: goto P_0c0a955a;
case 0x0c0a955cu: goto P_0c0a955c;
case 0x0c0a955eu: goto P_0c0a955e;
case 0x0c0a9560u: goto P_0c0a9560;
case 0x0c0a9562u: goto P_0c0a9562;
case 0x0c0a9564u: goto P_0c0a9564;
case 0x0c0a9566u: goto P_0c0a9566;
case 0x0c0a9568u: goto P_0c0a9568;
case 0x0c0a956au: goto P_0c0a956a;
case 0x0c0a956cu: goto P_0c0a956c;
case 0x0c0a956eu: goto P_0c0a956e;
case 0x0c0a9570u: goto P_0c0a9570;
case 0x0c0a9572u: goto P_0c0a9572;
case 0x0c0a9574u: goto P_0c0a9574;
case 0x0c0a9576u: goto P_0c0a9576;
case 0x0c0a9578u: goto P_0c0a9578;
case 0x0c0a957au: goto P_0c0a957a;
case 0x0c0a957cu: goto P_0c0a957c;
case 0x0c0a957eu: goto P_0c0a957e;
case 0x0c0a9580u: goto P_0c0a9580;
case 0x0c0a9582u: goto P_0c0a9582;
case 0x0c0a9584u: goto P_0c0a9584;
case 0x0c0a9586u: goto P_0c0a9586;
case 0x0c0a9588u: goto P_0c0a9588;
case 0x0c0a958au: goto P_0c0a958a;
case 0x0c0a958cu: goto P_0c0a958c;
case 0x0c0a958eu: goto P_0c0a958e;
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
case 0x0c0bef2eu: goto P_0c0bef2e;
case 0x0c0bef30u: goto P_0c0bef30;
case 0x0c0bef32u: goto P_0c0bef32;
case 0x0c0bef34u: goto P_0c0bef34;
case 0x0c0bef36u: goto P_0c0bef36;
case 0x0c0bef38u: goto P_0c0bef38;
case 0x0c0bef3au: goto P_0c0bef3a;
case 0x0c0bef3cu: goto P_0c0bef3c;
case 0x0c0bef3eu: goto P_0c0bef3e;
case 0x0c0bef40u: goto P_0c0bef40;
case 0x0c0bef42u: goto P_0c0bef42;
case 0x0c0bef44u: goto P_0c0bef44;
case 0x0c0bef46u: goto P_0c0bef46;
case 0x0c0bef48u: goto P_0c0bef48;
case 0x0c0bef4au: goto P_0c0bef4a;
case 0x0c0bef4cu: goto P_0c0bef4c;
case 0x0c0bef4eu: goto P_0c0bef4e;
case 0x0c0bef50u: goto P_0c0bef50;
case 0x0c0bef52u: goto P_0c0bef52;
case 0x0c0bef54u: goto P_0c0bef54;
case 0x0c0bef56u: goto P_0c0bef56;
case 0x0c0bef58u: goto P_0c0bef58;
case 0x0c0bef5au: goto P_0c0bef5a;
case 0x0c0bef5cu: goto P_0c0bef5c;
case 0x0c0bef5eu: goto P_0c0bef5e;
case 0x0c0bef60u: goto P_0c0bef60;
case 0x0c0bef62u: goto P_0c0bef62;
case 0x0c0bef64u: goto P_0c0bef64;
case 0x0c0bef66u: goto P_0c0bef66;
case 0x0c0bef68u: goto P_0c0bef68;
case 0x0c0bef6au: goto P_0c0bef6a;
case 0x0c0bef6cu: goto P_0c0bef6c;
case 0x0c0bef6eu: goto P_0c0bef6e;
case 0x0c0bef70u: goto P_0c0bef70;
case 0x0c0bef72u: goto P_0c0bef72;
case 0x0c0bef74u: goto P_0c0bef74;
case 0x0c0bef76u: goto P_0c0bef76;
case 0x0c0bef78u: goto P_0c0bef78;
case 0x0c0bef7au: goto P_0c0bef7a;
case 0x0c0bef7cu: goto P_0c0bef7c;
case 0x0c0bef7eu: goto P_0c0bef7e;
case 0x0c0bef80u: goto P_0c0bef80;
case 0x0c0bef82u: goto P_0c0bef82;
case 0x0c0bef84u: goto P_0c0bef84;
case 0x0c0bef86u: goto P_0c0bef86;
case 0x0c0bef88u: goto P_0c0bef88;
case 0x0c0bef8au: goto P_0c0bef8a;
case 0x0c0bef8cu: goto P_0c0bef8c;
case 0x0c0bef8eu: goto P_0c0bef8e;
case 0x0c0bef90u: goto P_0c0bef90;
case 0x0c0bef92u: goto P_0c0bef92;
case 0x0c0bef94u: goto P_0c0bef94;
case 0x0c0bef96u: goto P_0c0bef96;
case 0x0c0bef98u: goto P_0c0bef98;
case 0x0c0bef9au: goto P_0c0bef9a;
case 0x0c0bef9cu: goto P_0c0bef9c;
case 0x0c0bef9eu: goto P_0c0bef9e;
case 0x0c0befa0u: goto P_0c0befa0;
case 0x0c0befa2u: goto P_0c0befa2;
case 0x0c0befa4u: goto P_0c0befa4;
case 0x0c0befa6u: goto P_0c0befa6;
case 0x0c0befa8u: goto P_0c0befa8;
case 0x0c0befaau: goto P_0c0befaa;
case 0x0c0befacu: goto P_0c0befac;
case 0x0c0befaeu: goto P_0c0befae;
case 0x0c0befb0u: goto P_0c0befb0;
case 0x0c0befb2u: goto P_0c0befb2;
case 0x0c0befb4u: goto P_0c0befb4;
case 0x0c0befb6u: goto P_0c0befb6;
case 0x0c0befb8u: goto P_0c0befb8;
case 0x0c0befbau: goto P_0c0befba;
case 0x0c0befbcu: goto P_0c0befbc;
case 0x0c0befbeu: goto P_0c0befbe;
case 0x0c0befc0u: goto P_0c0befc0;
case 0x0c0befc2u: goto P_0c0befc2;
case 0x0c0befc4u: goto P_0c0befc4;
case 0x0c0befc6u: goto P_0c0befc6;
case 0x0c0befc8u: goto P_0c0befc8;
case 0x0c0befcau: goto P_0c0befca;
case 0x0c0befccu: goto P_0c0befcc;
case 0x0c0befceu: goto P_0c0befce;
case 0x0c0befd0u: goto P_0c0befd0;
case 0x0c0befd2u: goto P_0c0befd2;
case 0x0c0befd4u: goto P_0c0befd4;
case 0x0c0befd6u: goto P_0c0befd6;
case 0x0c0befd8u: goto P_0c0befd8;
case 0x0c0befdau: goto P_0c0befda;
case 0x0c0befdcu: goto P_0c0befdc;
case 0x0c0befdeu: goto P_0c0befde;
case 0x0c0befe0u: goto P_0c0befe0;
case 0x0c0befe2u: goto P_0c0befe2;
case 0x0c0befe4u: goto P_0c0befe4;
case 0x0c0befe6u: goto P_0c0befe6;
case 0x0c0befe8u: goto P_0c0befe8;
case 0x0c0befeau: goto P_0c0befea;
case 0x0c0befecu: goto P_0c0befec;
case 0x0c0befeeu: goto P_0c0befee;
case 0x0c0beff0u: goto P_0c0beff0;
case 0x0c0beff2u: goto P_0c0beff2;
case 0x0c0beff4u: goto P_0c0beff4;
case 0x0c0beff6u: goto P_0c0beff6;
case 0x0c0beff8u: goto P_0c0beff8;
case 0x0c0beffau: goto P_0c0beffa;
case 0x0c0beffcu: goto P_0c0beffc;
case 0x0c0beffeu: goto P_0c0beffe;
case 0x0c0bf000u: goto P_0c0bf000;
case 0x0c0bf002u: goto P_0c0bf002;
case 0x0c0bf004u: goto P_0c0bf004;
case 0x0c0bf006u: goto P_0c0bf006;
case 0x0c0bf008u: goto P_0c0bf008;
case 0x0c0bf00au: goto P_0c0bf00a;
case 0x0c0bf00cu: goto P_0c0bf00c;
case 0x0c0bf00eu: goto P_0c0bf00e;
case 0x0c0bf010u: goto P_0c0bf010;
case 0x0c0bf012u: goto P_0c0bf012;
case 0x0c0bf014u: goto P_0c0bf014;
case 0x0c0bf016u: goto P_0c0bf016;
case 0x0c0bf018u: goto P_0c0bf018;
case 0x0c0bf01au: goto P_0c0bf01a;
case 0x0c0bf01cu: goto P_0c0bf01c;
case 0x0c0bf01eu: goto P_0c0bf01e;
case 0x0c0bf020u: goto P_0c0bf020;
case 0x0c0bf022u: goto P_0c0bf022;
case 0x0c0bf024u: goto P_0c0bf024;
case 0x0c0bf026u: goto P_0c0bf026;
case 0x0c0bf028u: goto P_0c0bf028;
case 0x0c0bf02au: goto P_0c0bf02a;
case 0x0c0bf02cu: goto P_0c0bf02c;
case 0x0c0bf02eu: goto P_0c0bf02e;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c7e1cu: goto P_0c0c7e1c;
case 0x0c0c7e1eu: goto P_0c0c7e1e;
case 0x0c0c7e20u: goto P_0c0c7e20;
case 0x0c0c7e22u: goto P_0c0c7e22;
case 0x0c0c7e24u: goto P_0c0c7e24;
case 0x0c0c7e26u: goto P_0c0c7e26;
case 0x0c0c7e28u: goto P_0c0c7e28;
case 0x0c0c7e2au: goto P_0c0c7e2a;
case 0x0c0c7e2cu: goto P_0c0c7e2c;
case 0x0c0c7e2eu: goto P_0c0c7e2e;
case 0x0c0c7e30u: goto P_0c0c7e30;
case 0x0c0c7e32u: goto P_0c0c7e32;
case 0x0c0c7e34u: goto P_0c0c7e34;
case 0x0c0c7e36u: goto P_0c0c7e36;
case 0x0c0c7e38u: goto P_0c0c7e38;
case 0x0c0c7e3au: goto P_0c0c7e3a;
case 0x0c0c7e3cu: goto P_0c0c7e3c;
case 0x0c0c7e3eu: goto P_0c0c7e3e;
case 0x0c0c7e40u: goto P_0c0c7e40;
case 0x0c0c7e42u: goto P_0c0c7e42;
case 0x0c0c7e44u: goto P_0c0c7e44;
case 0x0c0c7e46u: goto P_0c0c7e46;
case 0x0c0c7e48u: goto P_0c0c7e48;
case 0x0c0c7e4au: goto P_0c0c7e4a;
case 0x0c0c7e4cu: goto P_0c0c7e4c;
case 0x0c0c7e4eu: goto P_0c0c7e4e;
case 0x0c0c7e50u: goto P_0c0c7e50;
case 0x0c0c7e52u: goto P_0c0c7e52;
case 0x0c0c7e54u: goto P_0c0c7e54;
case 0x0c0c7e56u: goto P_0c0c7e56;
case 0x0c0c7e58u: goto P_0c0c7e58;
case 0x0c0c7e5au: goto P_0c0c7e5a;
case 0x0c0c7e5cu: goto P_0c0c7e5c;
case 0x0c0c7e5eu: goto P_0c0c7e5e;
case 0x0c0c7e60u: goto P_0c0c7e60;
case 0x0c0c7e62u: goto P_0c0c7e62;
case 0x0c0c7e64u: goto P_0c0c7e64;
case 0x0c0c7e66u: goto P_0c0c7e66;
case 0x0c0c7e68u: goto P_0c0c7e68;
case 0x0c0c7e6au: goto P_0c0c7e6a;
case 0x0c0c7e6cu: goto P_0c0c7e6c;
case 0x0c0c7e6eu: goto P_0c0c7e6e;
case 0x0c0c7e70u: goto P_0c0c7e70;
case 0x0c0c7e72u: goto P_0c0c7e72;
case 0x0c0c7e74u: goto P_0c0c7e74;
case 0x0c0c7e76u: goto P_0c0c7e76;
case 0x0c0c7e78u: goto P_0c0c7e78;
case 0x0c0c7e7au: goto P_0c0c7e7a;
case 0x0c0c7e7cu: goto P_0c0c7e7c;
case 0x0c0c7e7eu: goto P_0c0c7e7e;
case 0x0c0c7e80u: goto P_0c0c7e80;
case 0x0c0c7e82u: goto P_0c0c7e82;
case 0x0c0c7e84u: goto P_0c0c7e84;
case 0x0c0c7e86u: goto P_0c0c7e86;
case 0x0c0c7e88u: goto P_0c0c7e88;
case 0x0c0c7e8au: goto P_0c0c7e8a;
case 0x0c0c7e8cu: goto P_0c0c7e8c;
case 0x0c0c7e8eu: goto P_0c0c7e8e;
case 0x0c0c7e90u: goto P_0c0c7e90;
case 0x0c0c7e92u: goto P_0c0c7e92;
case 0x0c0c7e94u: goto P_0c0c7e94;
case 0x0c0c7e96u: goto P_0c0c7e96;
case 0x0c0c7e98u: goto P_0c0c7e98;
case 0x0c0c7e9au: goto P_0c0c7e9a;
case 0x0c0c7e9cu: goto P_0c0c7e9c;
case 0x0c0c7e9eu: goto P_0c0c7e9e;
case 0x0c0c7ea0u: goto P_0c0c7ea0;
case 0x0c0c7ea2u: goto P_0c0c7ea2;
case 0x0c0c7ea4u: goto P_0c0c7ea4;
case 0x0c0c7ea6u: goto P_0c0c7ea6;
case 0x0c0c7ea8u: goto P_0c0c7ea8;
case 0x0c0c7eaau: goto P_0c0c7eaa;
case 0x0c0c7eacu: goto P_0c0c7eac;
case 0x0c0c7eaeu: goto P_0c0c7eae;
case 0x0c0c7eb0u: goto P_0c0c7eb0;
case 0x0c0c7eb2u: goto P_0c0c7eb2;
case 0x0c0c7eb4u: goto P_0c0c7eb4;
case 0x0c0c7eb6u: goto P_0c0c7eb6;
case 0x0c0c7eb8u: goto P_0c0c7eb8;
case 0x0c0c7ebau: goto P_0c0c7eba;
case 0x0c0c7ebcu: goto P_0c0c7ebc;
case 0x0c0c7ebeu: goto P_0c0c7ebe;
case 0x0c0c7ec0u: goto P_0c0c7ec0;
case 0x0c0c7ec2u: goto P_0c0c7ec2;
case 0x0c0c7ec4u: goto P_0c0c7ec4;
case 0x0c0c7ec6u: goto P_0c0c7ec6;
case 0x0c0c7ec8u: goto P_0c0c7ec8;
case 0x0c0c7ecau: goto P_0c0c7eca;
case 0x0c0c7eccu: goto P_0c0c7ecc;
case 0x0c0c7eceu: goto P_0c0c7ece;
case 0x0c0c7ed0u: goto P_0c0c7ed0;
case 0x0c0c7ed2u: goto P_0c0c7ed2;
case 0x0c0c7ed4u: goto P_0c0c7ed4;
case 0x0c0c7ed6u: goto P_0c0c7ed6;
case 0x0c0c7ed8u: goto P_0c0c7ed8;
case 0x0c0c7edau: goto P_0c0c7eda;
case 0x0c0c7edcu: goto P_0c0c7edc;
case 0x0c0c7edeu: goto P_0c0c7ede;
case 0x0c0c7ee0u: goto P_0c0c7ee0;
case 0x0c0c7ee2u: goto P_0c0c7ee2;
case 0x0c0c7ee4u: goto P_0c0c7ee4;
case 0x0c0c7ee6u: goto P_0c0c7ee6;
case 0x0c0c7ee8u: goto P_0c0c7ee8;
case 0x0c0c7eeau: goto P_0c0c7eea;
case 0x0c0c7eecu: goto P_0c0c7eec;
case 0x0c0c7eeeu: goto P_0c0c7eee;
case 0x0c0c7ef0u: goto P_0c0c7ef0;
case 0x0c0c7ef2u: goto P_0c0c7ef2;
case 0x0c0c7ef4u: goto P_0c0c7ef4;
case 0x0c0c7ef6u: goto P_0c0c7ef6;
case 0x0c0c7ef8u: goto P_0c0c7ef8;
case 0x0c0c7efau: goto P_0c0c7efa;
case 0x0c0c7efcu: goto P_0c0c7efc;
case 0x0c0c7efeu: goto P_0c0c7efe;
case 0x0c0c7f00u: goto P_0c0c7f00;
case 0x0c0c7f02u: goto P_0c0c7f02;
case 0x0c0c7f44u: goto P_0c0c7f44;
case 0x0c0c7f46u: goto P_0c0c7f46;
case 0x0c0c7f48u: goto P_0c0c7f48;
case 0x0c0c7f4au: goto P_0c0c7f4a;
case 0x0c0c7f4cu: goto P_0c0c7f4c;
case 0x0c0c7f4eu: goto P_0c0c7f4e;
case 0x0c0c7f50u: goto P_0c0c7f50;
case 0x0c0c7f52u: goto P_0c0c7f52;
case 0x0c0c7f54u: goto P_0c0c7f54;
case 0x0c0c7f56u: goto P_0c0c7f56;
case 0x0c0c7f58u: goto P_0c0c7f58;
case 0x0c0c7f5au: goto P_0c0c7f5a;
case 0x0c0c7f5cu: goto P_0c0c7f5c;
case 0x0c0c7f5eu: goto P_0c0c7f5e;
case 0x0c0c7f60u: goto P_0c0c7f60;
case 0x0c0c7f62u: goto P_0c0c7f62;
case 0x0c0c7f64u: goto P_0c0c7f64;
case 0x0c0c7f66u: goto P_0c0c7f66;
case 0x0c0c7f68u: goto P_0c0c7f68;
case 0x0c0c7f6au: goto P_0c0c7f6a;
case 0x0c0c7f6cu: goto P_0c0c7f6c;
case 0x0c0c7f6eu: goto P_0c0c7f6e;
case 0x0c0c7f70u: goto P_0c0c7f70;
case 0x0c0c7f72u: goto P_0c0c7f72;
case 0x0c0c7f74u: goto P_0c0c7f74;
case 0x0c0c7f76u: goto P_0c0c7f76;
case 0x0c0c7f78u: goto P_0c0c7f78;
case 0x0c0c7f7au: goto P_0c0c7f7a;
case 0x0c0c7f7cu: goto P_0c0c7f7c;
case 0x0c0c7f7eu: goto P_0c0c7f7e;
case 0x0c0c7f80u: goto P_0c0c7f80;
case 0x0c0c7f82u: goto P_0c0c7f82;
case 0x0c0c7f84u: goto P_0c0c7f84;
case 0x0c0c7f86u: goto P_0c0c7f86;
case 0x0c0c7f88u: goto P_0c0c7f88;
case 0x0c0c7f8au: goto P_0c0c7f8a;
case 0x0c0c7f8cu: goto P_0c0c7f8c;
case 0x0c0c7f8eu: goto P_0c0c7f8e;
case 0x0c0c7f90u: goto P_0c0c7f90;
case 0x0c0c7f92u: goto P_0c0c7f92;
case 0x0c0c7f94u: goto P_0c0c7f94;
case 0x0c0c7f96u: goto P_0c0c7f96;
case 0x0c0c7f98u: goto P_0c0c7f98;
case 0x0c0c7f9au: goto P_0c0c7f9a;
case 0x0c0c7f9cu: goto P_0c0c7f9c;
case 0x0c0c7f9eu: goto P_0c0c7f9e;
case 0x0c0c7fa0u: goto P_0c0c7fa0;
case 0x0c0c7fa2u: goto P_0c0c7fa2;
case 0x0c0c7fa4u: goto P_0c0c7fa4;
case 0x0c0c7fa6u: goto P_0c0c7fa6;
case 0x0c0c7fa8u: goto P_0c0c7fa8;
case 0x0c0c7faau: goto P_0c0c7faa;
case 0x0c0c7facu: goto P_0c0c7fac;
case 0x0c0c7faeu: goto P_0c0c7fae;
case 0x0c0c7fb0u: goto P_0c0c7fb0;
case 0x0c0c7fb2u: goto P_0c0c7fb2;
case 0x0c0c7fb4u: goto P_0c0c7fb4;
case 0x0c0cc5e6u: goto P_0c0cc5e6;
case 0x0c0cc5e8u: goto P_0c0cc5e8;
case 0x0c0cc5eau: goto P_0c0cc5ea;
case 0x0c0cc5ecu: goto P_0c0cc5ec;
case 0x0c0cc5eeu: goto P_0c0cc5ee;
case 0x0c0cc5f0u: goto P_0c0cc5f0;
case 0x0c0cc5f2u: goto P_0c0cc5f2;
case 0x0c0cc5f4u: goto P_0c0cc5f4;
case 0x0c0cc5f6u: goto P_0c0cc5f6;
case 0x0c0cc5f8u: goto P_0c0cc5f8;
case 0x0c0cc5fau: goto P_0c0cc5fa;
case 0x0c0cc5fcu: goto P_0c0cc5fc;
case 0x0c0cc5feu: goto P_0c0cc5fe;
case 0x0c0cc600u: goto P_0c0cc600;
case 0x0c0cc602u: goto P_0c0cc602;
case 0x0c0cc604u: goto P_0c0cc604;
case 0x0c0cc606u: goto P_0c0cc606;
case 0x0c0cc608u: goto P_0c0cc608;
case 0x0c0cc60au: goto P_0c0cc60a;
case 0x0c0cc60cu: goto P_0c0cc60c;
case 0x0c0cc60eu: goto P_0c0cc60e;
case 0x0c0cc610u: goto P_0c0cc610;
case 0x0c0cc612u: goto P_0c0cc612;
case 0x0c0cc614u: goto P_0c0cc614;
case 0x0c0cc616u: goto P_0c0cc616;
case 0x0c0cc618u: goto P_0c0cc618;
case 0x0c0cc61au: goto P_0c0cc61a;
case 0x0c0cc61cu: goto P_0c0cc61c;
case 0x0c0cc61eu: goto P_0c0cc61e;
case 0x0c0cc620u: goto P_0c0cc620;
case 0x0c0cc622u: goto P_0c0cc622;
case 0x0c0cc624u: goto P_0c0cc624;
case 0x0c0cc626u: goto P_0c0cc626;
case 0x0c0cc628u: goto P_0c0cc628;
case 0x0c0cc62au: goto P_0c0cc62a;
case 0x0c0cc62cu: goto P_0c0cc62c;
case 0x0c0cc62eu: goto P_0c0cc62e;
case 0x0c0cc630u: goto P_0c0cc630;
case 0x0c0cc632u: goto P_0c0cc632;
case 0x0c0cc634u: goto P_0c0cc634;
case 0x0c0cc636u: goto P_0c0cc636;
case 0x0c0cc638u: goto P_0c0cc638;
case 0x0c0cc63au: goto P_0c0cc63a;
case 0x0c0cc63cu: goto P_0c0cc63c;
case 0x0c0cc63eu: goto P_0c0cc63e;
case 0x0c0cc640u: goto P_0c0cc640;
case 0x0c0cc642u: goto P_0c0cc642;
case 0x0c0cc644u: goto P_0c0cc644;
case 0x0c0cc646u: goto P_0c0cc646;
case 0x0c0cc648u: goto P_0c0cc648;
case 0x0c0cc64au: goto P_0c0cc64a;
case 0x0c0cc64cu: goto P_0c0cc64c;
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
P_0c0376a0: /* original 4f22, guest PC 0x0c0376a0 */
if(!s->budget--) { s->failed_pc=0x0c0376a0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0376a2;
P_0c0376a2: /* original e202, guest PC 0x0c0376a2 */
if(!s->budget--) { s->failed_pc=0x0c0376a2u; return 0; }
r[2]=0x00000002u;
goto P_0c0376a4;
P_0c0376a4: /* original 635c, guest PC 0x0c0376a4 */
if(!s->budget--) { s->failed_pc=0x0c0376a4u; return 0; }
r[3]=r[5]&255u;
goto P_0c0376a6;
P_0c0376a6: /* original 4f12, guest PC 0x0c0376a6 */
if(!s->budget--) { s->failed_pc=0x0c0376a6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0376a8;
P_0c0376a8: /* original 3327, guest PC 0x0c0376a8 */
if(!s->budget--) { s->failed_pc=0x0c0376a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c0376aa;
P_0c0376aa: /* original 8901, guest PC 0x0c0376aa */
if(!s->budget--) { s->failed_pc=0x0c0376aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0376b0; }
goto P_0c0376ac;
P_0c0376ac: /* original 750c, guest PC 0x0c0376ac */
if(!s->budget--) { s->failed_pc=0x0c0376acu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0376ae;
P_0c0376ae: /* original 74ff, guest PC 0x0c0376ae */
if(!s->budget--) { s->failed_pc=0x0c0376aeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c0376b0;
P_0c0376b0: /* original e30d, guest PC 0x0c0376b0 */
if(!s->budget--) { s->failed_pc=0x0c0376b0u; return 0; }
r[3]=0x0000000du;
goto P_0c0376b2;
P_0c0376b2: /* original d237, guest PC 0x0c0376b2 */
if(!s->budget--) { s->failed_pc=0x0c0376b2u; return 0; }
r[2]=read(ram,0x0c037790u,4);
goto P_0c0376b4;
P_0c0376b4: /* original 615c, guest PC 0x0c0376b4 */
if(!s->budget--) { s->failed_pc=0x0c0376b4u; return 0; }
r[1]=r[5]&255u;
goto P_0c0376b6;
P_0c0376b6: /* original 213e, guest PC 0x0c0376b6 */
if(!s->budget--) { s->failed_pc=0x0c0376b6u; return 0; }
r[19]=(r[1]&65535u)*(r[3]&65535u);
goto P_0c0376b8;
P_0c0376b8: /* original 011a, guest PC 0x0c0376b8 */
if(!s->budget--) { s->failed_pc=0x0c0376b8u; return 0; }
r[1]=r[19];
goto P_0c0376ba;
P_0c0376ba: /* original 7108, guest PC 0x0c0376ba */
if(!s->budget--) { s->failed_pc=0x0c0376bau; return 0; }
r[1]+=0x00000008u;
goto P_0c0376bc;
P_0c0376bc: /* original 420b, guest PC 0x0c0376bc */
if(!s->budget--) { s->failed_pc=0x0c0376bcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0376c0u;
r[0]=0x00000005u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0376c0u) { target=s->pc; goto dispatch; }
goto P_0c0376c0;
P_0c0376be: /* original e005, guest PC 0x0c0376be */
if(!s->budget--) { s->failed_pc=0x0c0376beu; return 0; }
r[0]=0x00000005u;
goto P_0c0376c0;
P_0c0376c0: /* original 674d, guest PC 0x0c0376c0 */
if(!s->budget--) { s->failed_pc=0x0c0376c0u; return 0; }
r[7]=r[4]&65535u;
goto P_0c0376c2;
P_0c0376c2: /* original d234, guest PC 0x0c0376c2 */
if(!s->budget--) { s->failed_pc=0x0c0376c2u; return 0; }
r[2]=read(ram,0x0c037794u,4);
goto P_0c0376c4;
P_0c0376c4: /* original 6173, guest PC 0x0c0376c4 */
if(!s->budget--) { s->failed_pc=0x0c0376c4u; return 0; }
r[1]=r[7];
goto P_0c0376c6;
P_0c0376c6: /* original 4121, guest PC 0x0c0376c6 */
if(!s->budget--) { s->failed_pc=0x0c0376c6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c0376c8;
P_0c0376c8: /* original 4121, guest PC 0x0c0376c8 */
if(!s->budget--) { s->failed_pc=0x0c0376c8u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c0376ca;
P_0c0376ca: /* original 310c, guest PC 0x0c0376ca */
if(!s->budget--) { s->failed_pc=0x0c0376cau; return 0; }
r[1]+=r[0];
goto P_0c0376cc;
P_0c0376cc: /* original 666c, guest PC 0x0c0376cc */
if(!s->budget--) { s->failed_pc=0x0c0376ccu; return 0; }
r[6]=r[6]&255u;
goto P_0c0376ce;
P_0c0376ce: /* original 317c, guest PC 0x0c0376ce */
if(!s->budget--) { s->failed_pc=0x0c0376ceu; return 0; }
r[1]+=r[7];
goto P_0c0376d0;
P_0c0376d0: /* original 316c, guest PC 0x0c0376d0 */
if(!s->budget--) { s->failed_pc=0x0c0376d0u; return 0; }
r[1]+=r[6];
goto P_0c0376d2;
P_0c0376d2: /* original 71f1, guest PC 0x0c0376d2 */
if(!s->budget--) { s->failed_pc=0x0c0376d2u; return 0; }
r[1]+=0xfffffff1u;
goto P_0c0376d4;
P_0c0376d4: /* original 420b, guest PC 0x0c0376d4 */
if(!s->budget--) { s->failed_pc=0x0c0376d4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0376d8u;
r[0]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0376d8u) { target=s->pc; goto dispatch; }
goto P_0c0376d8;
P_0c0376d6: /* original e007, guest PC 0x0c0376d6 */
if(!s->budget--) { s->failed_pc=0x0c0376d6u; return 0; }
r[0]=0x00000007u;
goto P_0c0376d8;
P_0c0376d8: /* original 4f16, guest PC 0x0c0376d8 */
if(!s->budget--) { s->failed_pc=0x0c0376d8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0376da;
P_0c0376da: /* original 4f26, guest PC 0x0c0376da */
if(!s->budget--) { s->failed_pc=0x0c0376dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0376dc;
P_0c0376dc: /* original 000b, guest PC 0x0c0376dc */
if(!s->budget--) { s->failed_pc=0x0c0376dcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0376de: /* original 0009, guest PC 0x0c0376de */
if(!s->budget--) { s->failed_pc=0x0c0376deu; return 0; }
return vf3_matrix_family(0x0c0376e0u,s,ram);
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
target=0x0c04d4b4u; r[16]=code_base|0x0c04d47eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d47eu) { target=s->pc; goto dispatch; }
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
target=0x0c04d4b4u; r[16]=code_base|0x0c04d49cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d49cu) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c04d4b4u,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ddb8u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dde6u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04de0au) { target=s->pc; goto dispatch; }
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
target=0x0c04ceceu; r[16]=code_base|0x0c04de12u;
r[4]=read(ram,r[14]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04de12u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04de1cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04de38u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04de6au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04de8eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04de9au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dea8u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c04deb6u,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04df16u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04df22u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04df2cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04df32u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04df3eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04df46u) { target=s->pc; goto dispatch; }
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
P_0c04ea52: /* original 4f22, guest PC 0x0c04ea52 */
if(!s->budget--) { s->failed_pc=0x0c04ea52u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ea54;
P_0c04ea54: /* original 4f12, guest PC 0x0c04ea54 */
if(!s->budget--) { s->failed_pc=0x0c04ea54u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ea56;
P_0c04ea56: /* original 7fd0, guest PC 0x0c04ea56 */
if(!s->budget--) { s->failed_pc=0x0c04ea56u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04ea58;
P_0c04ea58: /* original 2f66, guest PC 0x0c04ea58 */
if(!s->budget--) { s->failed_pc=0x0c04ea58u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea5a;
P_0c04ea5a: /* original 2fb6, guest PC 0x0c04ea5a */
if(!s->budget--) { s->failed_pc=0x0c04ea5au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea5c;
P_0c04ea5c: /* original 2fe6, guest PC 0x0c04ea5c */
if(!s->budget--) { s->failed_pc=0x0c04ea5cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea5e;
P_0c04ea5e: /* original d216, guest PC 0x0c04ea5e */
if(!s->budget--) { s->failed_pc=0x0c04ea5eu; return 0; }
r[2]=read(ram,0x0c04eab8u,4);
goto P_0c04ea60;
P_0c04ea60: /* original d314, guest PC 0x0c04ea60 */
if(!s->budget--) { s->failed_pc=0x0c04ea60u; return 0; }
r[3]=read(ram,0x0c04eab4u,4);
goto P_0c04ea62;
P_0c04ea62: /* original 420b, guest PC 0x0c04ea62 */
if(!s->budget--) { s->failed_pc=0x0c04ea62u; return 0; }
target=r[2];
r[16]=code_base|0x0c04ea66u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ea66u) { target=s->pc; goto dispatch; }
goto P_0c04ea66;
P_0c04ea64: /* original 2f36, guest PC 0x0c04ea64 */
if(!s->budget--) { s->failed_pc=0x0c04ea64u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea66;
P_0c04ea66: /* original 9d20, guest PC 0x0c04ea66 */
if(!s->budget--) { s->failed_pc=0x0c04ea66u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04eaaau,2);
goto P_0c04ea68;
P_0c04ea68: /* original 7f10, guest PC 0x0c04ea68 */
if(!s->budget--) { s->failed_pc=0x0c04ea68u; return 0; }
r[15]+=0x00000010u;
goto P_0c04ea6a;
P_0c04ea6a: /* original e201, guest PC 0x0c04ea6a */
if(!s->budget--) { s->failed_pc=0x0c04ea6au; return 0; }
r[2]=0x00000001u;
goto P_0c04ea6c;
P_0c04ea6c: /* original 2edf, guest PC 0x0c04ea6c */
if(!s->budget--) { s->failed_pc=0x0c04ea6cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c04ea6e;
P_0c04ea6e: /* original 0d1a, guest PC 0x0c04ea6e */
if(!s->budget--) { s->failed_pc=0x0c04ea6eu; return 0; }
r[13]=r[19];
goto P_0c04ea70;
P_0c04ea70: /* original 6ddf, guest PC 0x0c04ea70 */
if(!s->budget--) { s->failed_pc=0x0c04ea70u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04ea72;
P_0c04ea72: /* original 2fd2, guest PC 0x0c04ea72 */
if(!s->budget--) { s->failed_pc=0x0c04ea72u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04ea74;
P_0c04ea74: /* original d311, guest PC 0x0c04ea74 */
if(!s->budget--) { s->failed_pc=0x0c04ea74u; return 0; }
r[3]=read(ram,0x0c04eabcu,4);
goto P_0c04ea76;
P_0c04ea76: /* original 3d3c, guest PC 0x0c04ea76 */
if(!s->budget--) { s->failed_pc=0x0c04ea76u; return 0; }
r[13]+=r[3];
goto P_0c04ea78;
P_0c04ea78: /* original 1d2c, guest PC 0x0c04ea78 */
if(!s->budget--) { s->failed_pc=0x0c04ea78u; return 0; }
write(ram,r[13]+48,r[2],4);
goto P_0c04ea7a;
P_0c04ea7a: /* original 51d1, guest PC 0x0c04ea7a */
if(!s->budget--) { s->failed_pc=0x0c04ea7au; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c04ea7c;
P_0c04ea7c: /* original d010, guest PC 0x0c04ea7c */
if(!s->budget--) { s->failed_pc=0x0c04ea7cu; return 0; }
r[0]=read(ram,0x0c04eac0u,4);
goto P_0c04ea7e;
P_0c04ea7e: /* original 6213, guest PC 0x0c04ea7e */
if(!s->budget--) { s->failed_pc=0x0c04ea7eu; return 0; }
r[2]=r[1];
goto P_0c04ea80;
P_0c04ea80: /* original 4108, guest PC 0x0c04ea80 */
if(!s->budget--) { s->failed_pc=0x0c04ea80u; return 0; }
r[1]<<=2;
goto P_0c04ea82;
P_0c04ea82: /* original 312c, guest PC 0x0c04ea82 */
if(!s->budget--) { s->failed_pc=0x0c04ea82u; return 0; }
r[1]+=r[2];
goto P_0c04ea84;
P_0c04ea84: /* original 4108, guest PC 0x0c04ea84 */
if(!s->budget--) { s->failed_pc=0x0c04ea84u; return 0; }
r[1]<<=2;
goto P_0c04ea86;
P_0c04ea86: /* original 4108, guest PC 0x0c04ea86 */
if(!s->budget--) { s->failed_pc=0x0c04ea86u; return 0; }
r[1]<<=2;
goto P_0c04ea88;
P_0c04ea88: /* original 611f, guest PC 0x0c04ea88 */
if(!s->budget--) { s->failed_pc=0x0c04ea88u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04ea8a;
P_0c04ea8a: /* original 001e, guest PC 0x0c04ea8a */
if(!s->budget--) { s->failed_pc=0x0c04ea8au; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c04ea8c;
P_0c04ea8c: /* original 1d0d, guest PC 0x0c04ea8c */
if(!s->budget--) { s->failed_pc=0x0c04ea8cu; return 0; }
write(ram,r[13]+52,r[0],4);
goto P_0c04ea8e;
P_0c04ea8e: /* original 84d2, guest PC 0x0c04ea8e */
if(!s->budget--) { s->failed_pc=0x0c04ea8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c04ea90;
P_0c04ea90: /* original 2008, guest PC 0x0c04ea90 */
if(!s->budget--) { s->failed_pc=0x0c04ea90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ea92;
P_0c04ea92: /* original 8926, guest PC 0x0c04ea92 */
if(!s->budget--) { s->failed_pc=0x0c04ea92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eae2; }
goto P_0c04ea94;
P_0c04ea94: /* original d30b, guest PC 0x0c04ea94 */
if(!s->budget--) { s->failed_pc=0x0c04ea94u; return 0; }
r[3]=read(ram,0x0c04eac4u,4);
goto P_0c04ea96;
P_0c04ea96: /* original 430b, guest PC 0x0c04ea96 */
if(!s->budget--) { s->failed_pc=0x0c04ea96u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ea9au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ea9au) { target=s->pc; goto dispatch; }
goto P_0c04ea9a;
P_0c04ea98: /* original 64e3, guest PC 0x0c04ea98 */
if(!s->budget--) { s->failed_pc=0x0c04ea98u; return 0; }
r[4]=r[14];
goto P_0c04ea9a;
P_0c04ea9a: /* original 2008, guest PC 0x0c04ea9a */
if(!s->budget--) { s->failed_pc=0x0c04ea9au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ea9c;
P_0c04ea9c: /* original 8b16, guest PC 0x0c04ea9c */
if(!s->budget--) { s->failed_pc=0x0c04ea9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04eacc; }
goto P_0c04ea9e;
P_0c04ea9e: /* original d30a, guest PC 0x0c04ea9e */
if(!s->budget--) { s->failed_pc=0x0c04ea9eu; return 0; }
r[3]=read(ram,0x0c04eac8u,4);
goto P_0c04eaa0;
P_0c04eaa0: /* original 430b, guest PC 0x0c04eaa0 */
if(!s->budget--) { s->failed_pc=0x0c04eaa0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04eaa4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eaa4u) { target=s->pc; goto dispatch; }
goto P_0c04eaa4;
P_0c04eaa2: /* original 64e3, guest PC 0x0c04eaa2 */
if(!s->budget--) { s->failed_pc=0x0c04eaa2u; return 0; }
r[4]=r[14];
goto P_0c04eaa4;
P_0c04eaa4: /* original a01d, guest PC 0x0c04eaa4 */
if(!s->budget--) { s->failed_pc=0x0c04eaa4u; return 0; }
goto P_0c04eae2;
P_0c04eaa6: /* original 0009, guest PC 0x0c04eaa6 */
if(!s->budget--) { s->failed_pc=0x0c04eaa6u; return 0; }
return vf3_matrix_family(0x0c04eaa8u,s,ram);
P_0c04eacc: /* original d23f, guest PC 0x0c04eacc */
if(!s->budget--) { s->failed_pc=0x0c04eaccu; return 0; }
r[2]=read(ram,0x0c04ebccu,4);
goto P_0c04eace;
P_0c04eace: /* original 420b, guest PC 0x0c04eace */
if(!s->budget--) { s->failed_pc=0x0c04eaceu; return 0; }
target=r[2];
r[16]=code_base|0x0c04ead2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ead2u) { target=s->pc; goto dispatch; }
goto P_0c04ead2;
P_0c04ead0: /* original 64e3, guest PC 0x0c04ead0 */
if(!s->budget--) { s->failed_pc=0x0c04ead0u; return 0; }
r[4]=r[14];
goto P_0c04ead2;
P_0c04ead2: /* original 2008, guest PC 0x0c04ead2 */
if(!s->budget--) { s->failed_pc=0x0c04ead2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ead4;
P_0c04ead4: /* original 8905, guest PC 0x0c04ead4 */
if(!s->budget--) { s->failed_pc=0x0c04ead4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eae2; }
goto P_0c04ead6;
P_0c04ead6: /* original 62f2, guest PC 0x0c04ead6 */
if(!s->budget--) { s->failed_pc=0x0c04ead6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04ead8;
P_0c04ead8: /* original d33d, guest PC 0x0c04ead8 */
if(!s->budget--) { s->failed_pc=0x0c04ead8u; return 0; }
r[3]=read(ram,0x0c04ebd0u,4);
goto P_0c04eada;
P_0c04eada: /* original 323c, guest PC 0x0c04eada */
if(!s->budget--) { s->failed_pc=0x0c04eadau; return 0; }
r[2]+=r[3];
goto P_0c04eadc;
P_0c04eadc: /* original 8428, guest PC 0x0c04eadc */
if(!s->budget--) { s->failed_pc=0x0c04eadcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04eade;
P_0c04eade: /* original 2008, guest PC 0x0c04eade */
if(!s->budget--) { s->failed_pc=0x0c04eadeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04eae0;
P_0c04eae0: /* original 8b02, guest PC 0x0c04eae0 */
if(!s->budget--) { s->failed_pc=0x0c04eae0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04eae8; }
goto P_0c04eae2;
P_0c04eae2: /* original 906d, guest PC 0x0c04eae2 */
if(!s->budget--) { s->failed_pc=0x0c04eae2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc0u,2);
goto P_0c04eae4;
P_0c04eae4: /* original a03c, guest PC 0x0c04eae4 */
if(!s->budget--) { s->failed_pc=0x0c04eae4u; return 0; }
goto P_0c04eb60;
P_0c04eae6: /* original 0009, guest PC 0x0c04eae6 */
if(!s->budget--) { s->failed_pc=0x0c04eae6u; return 0; }
goto P_0c04eae8;
P_0c04eae8: /* original d33a, guest PC 0x0c04eae8 */
if(!s->budget--) { s->failed_pc=0x0c04eae8u; return 0; }
r[3]=read(ram,0x0c04ebd4u,4);
goto P_0c04eaea;
P_0c04eaea: /* original 430b, guest PC 0x0c04eaea */
if(!s->budget--) { s->failed_pc=0x0c04eaeau; return 0; }
target=r[3];
r[16]=code_base|0x0c04eaeeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eaeeu) { target=s->pc; goto dispatch; }
goto P_0c04eaee;
P_0c04eaec: /* original 64e3, guest PC 0x0c04eaec */
if(!s->budget--) { s->failed_pc=0x0c04eaecu; return 0; }
r[4]=r[14];
goto P_0c04eaee;
P_0c04eaee: /* original 4011, guest PC 0x0c04eaee */
if(!s->budget--) { s->failed_pc=0x0c04eaeeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04eaf0;
P_0c04eaf0: /* original 8902, guest PC 0x0c04eaf0 */
if(!s->budget--) { s->failed_pc=0x0c04eaf0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eaf8; }
goto P_0c04eaf2;
P_0c04eaf2: /* original 9066, guest PC 0x0c04eaf2 */
if(!s->budget--) { s->failed_pc=0x0c04eaf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc2u,2);
goto P_0c04eaf4;
P_0c04eaf4: /* original a034, guest PC 0x0c04eaf4 */
if(!s->budget--) { s->failed_pc=0x0c04eaf4u; return 0; }
goto P_0c04eb60;
P_0c04eaf6: /* original 0009, guest PC 0x0c04eaf6 */
if(!s->budget--) { s->failed_pc=0x0c04eaf6u; return 0; }
goto P_0c04eaf8;
P_0c04eaf8: /* original d337, guest PC 0x0c04eaf8 */
if(!s->budget--) { s->failed_pc=0x0c04eaf8u; return 0; }
r[3]=read(ram,0x0c04ebd8u,4);
goto P_0c04eafa;
P_0c04eafa: /* original 65b3, guest PC 0x0c04eafa */
if(!s->budget--) { s->failed_pc=0x0c04eafau; return 0; }
r[5]=r[11];
goto P_0c04eafc;
P_0c04eafc: /* original 430b, guest PC 0x0c04eafc */
if(!s->budget--) { s->failed_pc=0x0c04eafcu; return 0; }
target=r[3];
r[16]=code_base|0x0c04eb00u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eb00u) { target=s->pc; goto dispatch; }
goto P_0c04eb00;
P_0c04eafe: /* original 64e3, guest PC 0x0c04eafe */
if(!s->budget--) { s->failed_pc=0x0c04eafeu; return 0; }
r[4]=r[14];
goto P_0c04eb00;
P_0c04eb00: /* original 4011, guest PC 0x0c04eb00 */
if(!s->budget--) { s->failed_pc=0x0c04eb00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04eb02;
P_0c04eb02: /* original 8902, guest PC 0x0c04eb02 */
if(!s->budget--) { s->failed_pc=0x0c04eb02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eb0a; }
goto P_0c04eb04;
P_0c04eb04: /* original 905e, guest PC 0x0c04eb04 */
if(!s->budget--) { s->failed_pc=0x0c04eb04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc4u,2);
goto P_0c04eb06;
P_0c04eb06: /* original a02b, guest PC 0x0c04eb06 */
if(!s->budget--) { s->failed_pc=0x0c04eb06u; return 0; }
goto P_0c04eb60;
P_0c04eb08: /* original 0009, guest PC 0x0c04eb08 */
if(!s->budget--) { s->failed_pc=0x0c04eb08u; return 0; }
goto P_0c04eb0a;
P_0c04eb0a: /* original 66f3, guest PC 0x0c04eb0a */
if(!s->budget--) { s->failed_pc=0x0c04eb0au; return 0; }
r[6]=r[15];
goto P_0c04eb0c;
P_0c04eb0c: /* original 65b3, guest PC 0x0c04eb0c */
if(!s->budget--) { s->failed_pc=0x0c04eb0cu; return 0; }
r[5]=r[11];
goto P_0c04eb0e;
P_0c04eb0e: /* original 7604, guest PC 0x0c04eb0e */
if(!s->budget--) { s->failed_pc=0x0c04eb0eu; return 0; }
r[6]+=0x00000004u;
goto P_0c04eb10;
P_0c04eb10: /* original b73d, guest PC 0x0c04eb10 */
if(!s->budget--) { s->failed_pc=0x0c04eb10u; return 0; }
target=0x0c04f98eu; r[16]=code_base|0x0c04eb14u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eb14u) { target=s->pc; goto dispatch; }
goto P_0c04eb14;
P_0c04eb12: /* original 64e3, guest PC 0x0c04eb12 */
if(!s->budget--) { s->failed_pc=0x0c04eb12u; return 0; }
r[4]=r[14];
goto P_0c04eb14;
P_0c04eb14: /* original 6d03, guest PC 0x0c04eb14 */
if(!s->budget--) { s->failed_pc=0x0c04eb14u; return 0; }
r[13]=r[0];
goto P_0c04eb16;
P_0c04eb16: /* original 4d11, guest PC 0x0c04eb16 */
if(!s->budget--) { s->failed_pc=0x0c04eb16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c04eb18;
P_0c04eb18: /* original 8902, guest PC 0x0c04eb18 */
if(!s->budget--) { s->failed_pc=0x0c04eb18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eb20; }
goto P_0c04eb1a;
P_0c04eb1a: /* original 9054, guest PC 0x0c04eb1a */
if(!s->budget--) { s->failed_pc=0x0c04eb1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc6u,2);
goto P_0c04eb1c;
P_0c04eb1c: /* original a020, guest PC 0x0c04eb1c */
if(!s->budget--) { s->failed_pc=0x0c04eb1cu; return 0; }
goto P_0c04eb60;
P_0c04eb1e: /* original 0009, guest PC 0x0c04eb1e */
if(!s->budget--) { s->failed_pc=0x0c04eb1eu; return 0; }
goto P_0c04eb20;
P_0c04eb20: /* original 66f3, guest PC 0x0c04eb20 */
if(!s->budget--) { s->failed_pc=0x0c04eb20u; return 0; }
r[6]=r[15];
goto P_0c04eb22;
P_0c04eb22: /* original 65c3, guest PC 0x0c04eb22 */
if(!s->budget--) { s->failed_pc=0x0c04eb22u; return 0; }
r[5]=r[12];
goto P_0c04eb24;
P_0c04eb24: /* original 7604, guest PC 0x0c04eb24 */
if(!s->budget--) { s->failed_pc=0x0c04eb24u; return 0; }
r[6]+=0x00000004u;
goto P_0c04eb26;
P_0c04eb26: /* original b732, guest PC 0x0c04eb26 */
if(!s->budget--) { s->failed_pc=0x0c04eb26u; return 0; }
target=0x0c04f98eu; r[16]=code_base|0x0c04eb2au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eb2au) { target=s->pc; goto dispatch; }
goto P_0c04eb2a;
P_0c04eb28: /* original 64e3, guest PC 0x0c04eb28 */
if(!s->budget--) { s->failed_pc=0x0c04eb28u; return 0; }
r[4]=r[14];
goto P_0c04eb2a;
P_0c04eb2a: /* original 4011, guest PC 0x0c04eb2a */
if(!s->budget--) { s->failed_pc=0x0c04eb2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04eb2c;
P_0c04eb2c: /* original 8b02, guest PC 0x0c04eb2c */
if(!s->budget--) { s->failed_pc=0x0c04eb2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04eb34; }
goto P_0c04eb2e;
P_0c04eb2e: /* original 904b, guest PC 0x0c04eb2e */
if(!s->budget--) { s->failed_pc=0x0c04eb2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc8u,2);
goto P_0c04eb30;
P_0c04eb30: /* original a016, guest PC 0x0c04eb30 */
if(!s->budget--) { s->failed_pc=0x0c04eb30u; return 0; }
goto P_0c04eb60;
P_0c04eb32: /* original 0009, guest PC 0x0c04eb32 */
if(!s->budget--) { s->failed_pc=0x0c04eb32u; return 0; }
goto P_0c04eb34;
P_0c04eb34: /* original d329, guest PC 0x0c04eb34 */
if(!s->budget--) { s->failed_pc=0x0c04eb34u; return 0; }
r[3]=read(ram,0x0c04ebdcu,4);
goto P_0c04eb36;
P_0c04eb36: /* original 65d3, guest PC 0x0c04eb36 */
if(!s->budget--) { s->failed_pc=0x0c04eb36u; return 0; }
r[5]=r[13];
goto P_0c04eb38;
P_0c04eb38: /* original 430b, guest PC 0x0c04eb38 */
if(!s->budget--) { s->failed_pc=0x0c04eb38u; return 0; }
target=r[3];
r[16]=code_base|0x0c04eb3cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eb3cu) { target=s->pc; goto dispatch; }
goto P_0c04eb3c;
P_0c04eb3a: /* original 64e3, guest PC 0x0c04eb3a */
if(!s->budget--) { s->failed_pc=0x0c04eb3au; return 0; }
r[4]=r[14];
goto P_0c04eb3c;
P_0c04eb3c: /* original 6403, guest PC 0x0c04eb3c */
if(!s->budget--) { s->failed_pc=0x0c04eb3cu; return 0; }
r[4]=r[0];
goto P_0c04eb3e;
P_0c04eb3e: /* original 7404, guest PC 0x0c04eb3e */
if(!s->budget--) { s->failed_pc=0x0c04eb3eu; return 0; }
r[4]+=0x00000004u;
goto P_0c04eb40;
P_0c04eb40: /* original 67c3, guest PC 0x0c04eb40 */
if(!s->budget--) { s->failed_pc=0x0c04eb40u; return 0; }
r[7]=r[12];
goto P_0c04eb42;
P_0c04eb42: /* original e500, guest PC 0x0c04eb42 */
if(!s->budget--) { s->failed_pc=0x0c04eb42u; return 0; }
r[5]=0x00000000u;
goto P_0c04eb44;
P_0c04eb44: /* original a004, guest PC 0x0c04eb44 */
if(!s->budget--) { s->failed_pc=0x0c04eb44u; return 0; }
r[6]=0x0000000cu;
goto P_0c04eb50;
P_0c04eb46: /* original e60c, guest PC 0x0c04eb46 */
if(!s->budget--) { s->failed_pc=0x0c04eb46u; return 0; }
r[6]=0x0000000cu;
goto P_0c04eb48;
P_0c04eb48: /* original 6374, guest PC 0x0c04eb48 */
if(!s->budget--) { s->failed_pc=0x0c04eb48u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04eb4a;
P_0c04eb4a: /* original 7501, guest PC 0x0c04eb4a */
if(!s->budget--) { s->failed_pc=0x0c04eb4au; return 0; }
r[5]+=0x00000001u;
goto P_0c04eb4c;
P_0c04eb4c: /* original 2430, guest PC 0x0c04eb4c */
if(!s->budget--) { s->failed_pc=0x0c04eb4cu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04eb4e;
P_0c04eb4e: /* original 7401, guest PC 0x0c04eb4e */
if(!s->budget--) { s->failed_pc=0x0c04eb4eu; return 0; }
r[4]+=0x00000001u;
goto P_0c04eb50;
P_0c04eb50: /* original 3563, guest PC 0x0c04eb50 */
if(!s->budget--) { s->failed_pc=0x0c04eb50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04eb52;
P_0c04eb52: /* original 8bf9, guest PC 0x0c04eb52 */
if(!s->budget--) { s->failed_pc=0x0c04eb52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04eb48; }
goto P_0c04eb54;
P_0c04eb54: /* original d322, guest PC 0x0c04eb54 */
if(!s->budget--) { s->failed_pc=0x0c04eb54u; return 0; }
r[3]=read(ram,0x0c04ebe0u,4);
goto P_0c04eb56;
P_0c04eb56: /* original 65d3, guest PC 0x0c04eb56 */
if(!s->budget--) { s->failed_pc=0x0c04eb56u; return 0; }
r[5]=r[13];
goto P_0c04eb58;
P_0c04eb58: /* original 430b, guest PC 0x0c04eb58 */
if(!s->budget--) { s->failed_pc=0x0c04eb58u; return 0; }
target=r[3];
r[16]=code_base|0x0c04eb5cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eb5cu) { target=s->pc; goto dispatch; }
goto P_0c04eb5c;
P_0c04eb5a: /* original 64e3, guest PC 0x0c04eb5a */
if(!s->budget--) { s->failed_pc=0x0c04eb5au; return 0; }
r[4]=r[14];
goto P_0c04eb5c;
P_0c04eb5c: /* original b5f7, guest PC 0x0c04eb5c */
if(!s->budget--) { s->failed_pc=0x0c04eb5cu; return 0; }
target=0x0c04f74eu; r[16]=code_base|0x0c04eb60u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eb60u) { target=s->pc; goto dispatch; }
goto P_0c04eb60;
P_0c04eb5e: /* original 64e3, guest PC 0x0c04eb5e */
if(!s->budget--) { s->failed_pc=0x0c04eb5eu; return 0; }
r[4]=r[14];
goto P_0c04eb60;
P_0c04eb60: /* original 7f30, guest PC 0x0c04eb60 */
if(!s->budget--) { s->failed_pc=0x0c04eb60u; return 0; }
r[15]+=0x00000030u;
goto P_0c04eb62;
P_0c04eb62: /* original 4f16, guest PC 0x0c04eb62 */
if(!s->budget--) { s->failed_pc=0x0c04eb62u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04eb64;
P_0c04eb64: /* original 4f26, guest PC 0x0c04eb64 */
if(!s->budget--) { s->failed_pc=0x0c04eb64u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04eb66;
P_0c04eb66: /* original 6bf6, guest PC 0x0c04eb66 */
if(!s->budget--) { s->failed_pc=0x0c04eb66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04eb68;
P_0c04eb68: /* original 6cf6, guest PC 0x0c04eb68 */
if(!s->budget--) { s->failed_pc=0x0c04eb68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04eb6a;
P_0c04eb6a: /* original 6df6, guest PC 0x0c04eb6a */
if(!s->budget--) { s->failed_pc=0x0c04eb6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04eb6c;
P_0c04eb6c: /* original 000b, guest PC 0x0c04eb6c */
if(!s->budget--) { s->failed_pc=0x0c04eb6cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04eb6e: /* original 6ef6, guest PC 0x0c04eb6e */
if(!s->budget--) { s->failed_pc=0x0c04eb6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04eb70u,s,ram);
P_0c04ed8c: /* original 4f22, guest PC 0x0c04ed8c */
if(!s->budget--) { s->failed_pc=0x0c04ed8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ed8e;
P_0c04ed8e: /* original 4f12, guest PC 0x0c04ed8e */
if(!s->budget--) { s->failed_pc=0x0c04ed8eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ed90;
P_0c04ed90: /* original 7fc8, guest PC 0x0c04ed90 */
if(!s->budget--) { s->failed_pc=0x0c04ed90u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c04ed92;
P_0c04ed92: /* original 2f61, guest PC 0x0c04ed92 */
if(!s->budget--) { s->failed_pc=0x0c04ed92u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c04ed94;
P_0c04ed94: /* original 80f4, guest PC 0x0c04ed94 */
if(!s->budget--) { s->failed_pc=0x0c04ed94u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c04ed96;
P_0c04ed96: /* original 84f4, guest PC 0x0c04ed96 */
if(!s->budget--) { s->failed_pc=0x0c04ed96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04ed98;
P_0c04ed98: /* original 600c, guest PC 0x0c04ed98 */
if(!s->budget--) { s->failed_pc=0x0c04ed98u; return 0; }
r[0]=r[0]&255u;
goto P_0c04ed9a;
P_0c04ed9a: /* original 2f06, guest PC 0x0c04ed9a */
if(!s->budget--) { s->failed_pc=0x0c04ed9au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ed9c;
P_0c04ed9c: /* original 85f2, guest PC 0x0c04ed9c */
if(!s->budget--) { s->failed_pc=0x0c04ed9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04ed9e;
P_0c04ed9e: /* original 6303, guest PC 0x0c04ed9e */
if(!s->budget--) { s->failed_pc=0x0c04ed9eu; return 0; }
r[3]=r[0];
goto P_0c04eda0;
P_0c04eda0: /* original 633d, guest PC 0x0c04eda0 */
if(!s->budget--) { s->failed_pc=0x0c04eda0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c04eda2;
P_0c04eda2: /* original 2f36, guest PC 0x0c04eda2 */
if(!s->budget--) { s->failed_pc=0x0c04eda2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04eda4;
P_0c04eda4: /* original 2fc6, guest PC 0x0c04eda4 */
if(!s->budget--) { s->failed_pc=0x0c04eda4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04eda6;
P_0c04eda6: /* original 2fe6, guest PC 0x0c04eda6 */
if(!s->budget--) { s->failed_pc=0x0c04eda6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04eda8;
P_0c04eda8: /* original d31a, guest PC 0x0c04eda8 */
if(!s->budget--) { s->failed_pc=0x0c04eda8u; return 0; }
r[3]=read(ram,0x0c04ee14u,4);
goto P_0c04edaa;
P_0c04edaa: /* original d21b, guest PC 0x0c04edaa */
if(!s->budget--) { s->failed_pc=0x0c04edaau; return 0; }
r[2]=read(ram,0x0c04ee18u,4);
goto P_0c04edac;
P_0c04edac: /* original 420b, guest PC 0x0c04edac */
if(!s->budget--) { s->failed_pc=0x0c04edacu; return 0; }
target=r[2];
r[16]=code_base|0x0c04edb0u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04edb0u) { target=s->pc; goto dispatch; }
goto P_0c04edb0;
P_0c04edae: /* original 2f36, guest PC 0x0c04edae */
if(!s->budget--) { s->failed_pc=0x0c04edaeu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04edb0;
P_0c04edb0: /* original 9d1f, guest PC 0x0c04edb0 */
if(!s->budget--) { s->failed_pc=0x0c04edb0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04edf2u,2);
goto P_0c04edb2;
P_0c04edb2: /* original 7f14, guest PC 0x0c04edb2 */
if(!s->budget--) { s->failed_pc=0x0c04edb2u; return 0; }
r[15]+=0x00000014u;
goto P_0c04edb4;
P_0c04edb4: /* original e201, guest PC 0x0c04edb4 */
if(!s->budget--) { s->failed_pc=0x0c04edb4u; return 0; }
r[2]=0x00000001u;
goto P_0c04edb6;
P_0c04edb6: /* original 2edf, guest PC 0x0c04edb6 */
if(!s->budget--) { s->failed_pc=0x0c04edb6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c04edb8;
P_0c04edb8: /* original 0d1a, guest PC 0x0c04edb8 */
if(!s->budget--) { s->failed_pc=0x0c04edb8u; return 0; }
r[13]=r[19];
goto P_0c04edba;
P_0c04edba: /* original 6ddf, guest PC 0x0c04edba */
if(!s->budget--) { s->failed_pc=0x0c04edbau; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04edbc;
P_0c04edbc: /* original 1fd2, guest PC 0x0c04edbc */
if(!s->budget--) { s->failed_pc=0x0c04edbcu; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c04edbe;
P_0c04edbe: /* original d317, guest PC 0x0c04edbe */
if(!s->budget--) { s->failed_pc=0x0c04edbeu; return 0; }
r[3]=read(ram,0x0c04ee1cu,4);
goto P_0c04edc0;
P_0c04edc0: /* original 3d3c, guest PC 0x0c04edc0 */
if(!s->budget--) { s->failed_pc=0x0c04edc0u; return 0; }
r[13]+=r[3];
goto P_0c04edc2;
P_0c04edc2: /* original 1d2c, guest PC 0x0c04edc2 */
if(!s->budget--) { s->failed_pc=0x0c04edc2u; return 0; }
write(ram,r[13]+48,r[2],4);
goto P_0c04edc4;
P_0c04edc4: /* original 51d1, guest PC 0x0c04edc4 */
if(!s->budget--) { s->failed_pc=0x0c04edc4u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c04edc6;
P_0c04edc6: /* original d016, guest PC 0x0c04edc6 */
if(!s->budget--) { s->failed_pc=0x0c04edc6u; return 0; }
r[0]=read(ram,0x0c04ee20u,4);
goto P_0c04edc8;
P_0c04edc8: /* original 6213, guest PC 0x0c04edc8 */
if(!s->budget--) { s->failed_pc=0x0c04edc8u; return 0; }
r[2]=r[1];
goto P_0c04edca;
P_0c04edca: /* original 4108, guest PC 0x0c04edca */
if(!s->budget--) { s->failed_pc=0x0c04edcau; return 0; }
r[1]<<=2;
goto P_0c04edcc;
P_0c04edcc: /* original 312c, guest PC 0x0c04edcc */
if(!s->budget--) { s->failed_pc=0x0c04edccu; return 0; }
r[1]+=r[2];
goto P_0c04edce;
P_0c04edce: /* original 4108, guest PC 0x0c04edce */
if(!s->budget--) { s->failed_pc=0x0c04edceu; return 0; }
r[1]<<=2;
goto P_0c04edd0;
P_0c04edd0: /* original 4108, guest PC 0x0c04edd0 */
if(!s->budget--) { s->failed_pc=0x0c04edd0u; return 0; }
r[1]<<=2;
goto P_0c04edd2;
P_0c04edd2: /* original 611f, guest PC 0x0c04edd2 */
if(!s->budget--) { s->failed_pc=0x0c04edd2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04edd4;
P_0c04edd4: /* original 001e, guest PC 0x0c04edd4 */
if(!s->budget--) { s->failed_pc=0x0c04edd4u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c04edd6;
P_0c04edd6: /* original 1d0d, guest PC 0x0c04edd6 */
if(!s->budget--) { s->failed_pc=0x0c04edd6u; return 0; }
write(ram,r[13]+52,r[0],4);
goto P_0c04edd8;
P_0c04edd8: /* original 84d2, guest PC 0x0c04edd8 */
if(!s->budget--) { s->failed_pc=0x0c04edd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c04edda;
P_0c04edda: /* original 2008, guest PC 0x0c04edda */
if(!s->budget--) { s->failed_pc=0x0c04eddau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04eddc;
P_0c04eddc: /* original 8931, guest PC 0x0c04eddc */
if(!s->budget--) { s->failed_pc=0x0c04eddcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee42; }
goto P_0c04edde;
P_0c04edde: /* original d311, guest PC 0x0c04edde */
if(!s->budget--) { s->failed_pc=0x0c04eddeu; return 0; }
r[3]=read(ram,0x0c04ee24u,4);
goto P_0c04ede0;
P_0c04ede0: /* original 430b, guest PC 0x0c04ede0 */
if(!s->budget--) { s->failed_pc=0x0c04ede0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ede4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ede4u) { target=s->pc; goto dispatch; }
goto P_0c04ede4;
P_0c04ede2: /* original 64e3, guest PC 0x0c04ede2 */
if(!s->budget--) { s->failed_pc=0x0c04ede2u; return 0; }
r[4]=r[14];
goto P_0c04ede4;
P_0c04ede4: /* original 2008, guest PC 0x0c04ede4 */
if(!s->budget--) { s->failed_pc=0x0c04ede4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ede6;
P_0c04ede6: /* original 8b21, guest PC 0x0c04ede6 */
if(!s->budget--) { s->failed_pc=0x0c04ede6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ee2c; }
goto P_0c04ede8;
P_0c04ede8: /* original d30f, guest PC 0x0c04ede8 */
if(!s->budget--) { s->failed_pc=0x0c04ede8u; return 0; }
r[3]=read(ram,0x0c04ee28u,4);
goto P_0c04edea;
P_0c04edea: /* original 430b, guest PC 0x0c04edea */
if(!s->budget--) { s->failed_pc=0x0c04edeau; return 0; }
target=r[3];
r[16]=code_base|0x0c04edeeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04edeeu) { target=s->pc; goto dispatch; }
goto P_0c04edee;
P_0c04edec: /* original 64e3, guest PC 0x0c04edec */
if(!s->budget--) { s->failed_pc=0x0c04edecu; return 0; }
r[4]=r[14];
goto P_0c04edee;
P_0c04edee: /* original a028, guest PC 0x0c04edee */
if(!s->budget--) { s->failed_pc=0x0c04edeeu; return 0; }
goto P_0c04ee42;
P_0c04edf0: /* original 0009, guest PC 0x0c04edf0 */
if(!s->budget--) { s->failed_pc=0x0c04edf0u; return 0; }
return vf3_matrix_family(0x0c04edf2u,s,ram);
P_0c04ee2c: /* original d23a, guest PC 0x0c04ee2c */
if(!s->budget--) { s->failed_pc=0x0c04ee2cu; return 0; }
r[2]=read(ram,0x0c04ef18u,4);
goto P_0c04ee2e;
P_0c04ee2e: /* original 420b, guest PC 0x0c04ee2e */
if(!s->budget--) { s->failed_pc=0x0c04ee2eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04ee32u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ee32u) { target=s->pc; goto dispatch; }
goto P_0c04ee32;
P_0c04ee30: /* original 64e3, guest PC 0x0c04ee30 */
if(!s->budget--) { s->failed_pc=0x0c04ee30u; return 0; }
r[4]=r[14];
goto P_0c04ee32;
P_0c04ee32: /* original 2008, guest PC 0x0c04ee32 */
if(!s->budget--) { s->failed_pc=0x0c04ee32u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ee34;
P_0c04ee34: /* original 8905, guest PC 0x0c04ee34 */
if(!s->budget--) { s->failed_pc=0x0c04ee34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee42; }
goto P_0c04ee36;
P_0c04ee36: /* original 52f2, guest PC 0x0c04ee36 */
if(!s->budget--) { s->failed_pc=0x0c04ee36u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04ee38;
P_0c04ee38: /* original d338, guest PC 0x0c04ee38 */
if(!s->budget--) { s->failed_pc=0x0c04ee38u; return 0; }
r[3]=read(ram,0x0c04ef1cu,4);
goto P_0c04ee3a;
P_0c04ee3a: /* original 323c, guest PC 0x0c04ee3a */
if(!s->budget--) { s->failed_pc=0x0c04ee3au; return 0; }
r[2]+=r[3];
goto P_0c04ee3c;
P_0c04ee3c: /* original 8428, guest PC 0x0c04ee3c */
if(!s->budget--) { s->failed_pc=0x0c04ee3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04ee3e;
P_0c04ee3e: /* original 2008, guest PC 0x0c04ee3e */
if(!s->budget--) { s->failed_pc=0x0c04ee3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ee40;
P_0c04ee40: /* original 8b02, guest PC 0x0c04ee40 */
if(!s->budget--) { s->failed_pc=0x0c04ee40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ee48; }
goto P_0c04ee42;
P_0c04ee42: /* original 9064, guest PC 0x0c04ee42 */
if(!s->budget--) { s->failed_pc=0x0c04ee42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef0eu,2);
goto P_0c04ee44;
P_0c04ee44: /* original a034, guest PC 0x0c04ee44 */
if(!s->budget--) { s->failed_pc=0x0c04ee44u; return 0; }
goto P_0c04eeb0;
P_0c04ee46: /* original 0009, guest PC 0x0c04ee46 */
if(!s->budget--) { s->failed_pc=0x0c04ee46u; return 0; }
goto P_0c04ee48;
P_0c04ee48: /* original d335, guest PC 0x0c04ee48 */
if(!s->budget--) { s->failed_pc=0x0c04ee48u; return 0; }
r[3]=read(ram,0x0c04ef20u,4);
goto P_0c04ee4a;
P_0c04ee4a: /* original 430b, guest PC 0x0c04ee4a */
if(!s->budget--) { s->failed_pc=0x0c04ee4au; return 0; }
target=r[3];
r[16]=code_base|0x0c04ee4eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ee4eu) { target=s->pc; goto dispatch; }
goto P_0c04ee4e;
P_0c04ee4c: /* original 64e3, guest PC 0x0c04ee4c */
if(!s->budget--) { s->failed_pc=0x0c04ee4cu; return 0; }
r[4]=r[14];
goto P_0c04ee4e;
P_0c04ee4e: /* original 4011, guest PC 0x0c04ee4e */
if(!s->budget--) { s->failed_pc=0x0c04ee4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ee50;
P_0c04ee50: /* original 8902, guest PC 0x0c04ee50 */
if(!s->budget--) { s->failed_pc=0x0c04ee50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee58; }
goto P_0c04ee52;
P_0c04ee52: /* original 905d, guest PC 0x0c04ee52 */
if(!s->budget--) { s->failed_pc=0x0c04ee52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef10u,2);
goto P_0c04ee54;
P_0c04ee54: /* original a02c, guest PC 0x0c04ee54 */
if(!s->budget--) { s->failed_pc=0x0c04ee54u; return 0; }
goto P_0c04eeb0;
P_0c04ee56: /* original 0009, guest PC 0x0c04ee56 */
if(!s->budget--) { s->failed_pc=0x0c04ee56u; return 0; }
goto P_0c04ee58;
P_0c04ee58: /* original d332, guest PC 0x0c04ee58 */
if(!s->budget--) { s->failed_pc=0x0c04ee58u; return 0; }
r[3]=read(ram,0x0c04ef24u,4);
goto P_0c04ee5a;
P_0c04ee5a: /* original 65c3, guest PC 0x0c04ee5a */
if(!s->budget--) { s->failed_pc=0x0c04ee5au; return 0; }
r[5]=r[12];
goto P_0c04ee5c;
P_0c04ee5c: /* original 430b, guest PC 0x0c04ee5c */
if(!s->budget--) { s->failed_pc=0x0c04ee5cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04ee60u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ee60u) { target=s->pc; goto dispatch; }
goto P_0c04ee60;
P_0c04ee5e: /* original 64e3, guest PC 0x0c04ee5e */
if(!s->budget--) { s->failed_pc=0x0c04ee5eu; return 0; }
r[4]=r[14];
goto P_0c04ee60;
P_0c04ee60: /* original 4011, guest PC 0x0c04ee60 */
if(!s->budget--) { s->failed_pc=0x0c04ee60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ee62;
P_0c04ee62: /* original 8902, guest PC 0x0c04ee62 */
if(!s->budget--) { s->failed_pc=0x0c04ee62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee6a; }
goto P_0c04ee64;
P_0c04ee64: /* original 9055, guest PC 0x0c04ee64 */
if(!s->budget--) { s->failed_pc=0x0c04ee64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef12u,2);
goto P_0c04ee66;
P_0c04ee66: /* original a023, guest PC 0x0c04ee66 */
if(!s->budget--) { s->failed_pc=0x0c04ee66u; return 0; }
goto P_0c04eeb0;
P_0c04ee68: /* original 0009, guest PC 0x0c04ee68 */
if(!s->budget--) { s->failed_pc=0x0c04ee68u; return 0; }
goto P_0c04ee6a;
P_0c04ee6a: /* original 66f3, guest PC 0x0c04ee6a */
if(!s->budget--) { s->failed_pc=0x0c04ee6au; return 0; }
r[6]=r[15];
goto P_0c04ee6c;
P_0c04ee6c: /* original 65c3, guest PC 0x0c04ee6c */
if(!s->budget--) { s->failed_pc=0x0c04ee6cu; return 0; }
r[5]=r[12];
goto P_0c04ee6e;
P_0c04ee6e: /* original 760c, guest PC 0x0c04ee6e */
if(!s->budget--) { s->failed_pc=0x0c04ee6eu; return 0; }
r[6]+=0x0000000cu;
goto P_0c04ee70;
P_0c04ee70: /* original b58d, guest PC 0x0c04ee70 */
if(!s->budget--) { s->failed_pc=0x0c04ee70u; return 0; }
target=0x0c04f98eu; r[16]=code_base|0x0c04ee74u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ee74u) { target=s->pc; goto dispatch; }
goto P_0c04ee74;
P_0c04ee72: /* original 64e3, guest PC 0x0c04ee72 */
if(!s->budget--) { s->failed_pc=0x0c04ee72u; return 0; }
r[4]=r[14];
goto P_0c04ee74;
P_0c04ee74: /* original 6d03, guest PC 0x0c04ee74 */
if(!s->budget--) { s->failed_pc=0x0c04ee74u; return 0; }
r[13]=r[0];
goto P_0c04ee76;
P_0c04ee76: /* original 4d11, guest PC 0x0c04ee76 */
if(!s->budget--) { s->failed_pc=0x0c04ee76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c04ee78;
P_0c04ee78: /* original 8902, guest PC 0x0c04ee78 */
if(!s->budget--) { s->failed_pc=0x0c04ee78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee80; }
goto P_0c04ee7a;
P_0c04ee7a: /* original 904b, guest PC 0x0c04ee7a */
if(!s->budget--) { s->failed_pc=0x0c04ee7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef14u,2);
goto P_0c04ee7c;
P_0c04ee7c: /* original a018, guest PC 0x0c04ee7c */
if(!s->budget--) { s->failed_pc=0x0c04ee7cu; return 0; }
goto P_0c04eeb0;
P_0c04ee7e: /* original 0009, guest PC 0x0c04ee7e */
if(!s->budget--) { s->failed_pc=0x0c04ee7eu; return 0; }
goto P_0c04ee80;
P_0c04ee80: /* original d329, guest PC 0x0c04ee80 */
if(!s->budget--) { s->failed_pc=0x0c04ee80u; return 0; }
r[3]=read(ram,0x0c04ef28u,4);
goto P_0c04ee82;
P_0c04ee82: /* original 65d3, guest PC 0x0c04ee82 */
if(!s->budget--) { s->failed_pc=0x0c04ee82u; return 0; }
r[5]=r[13];
goto P_0c04ee84;
P_0c04ee84: /* original 430b, guest PC 0x0c04ee84 */
if(!s->budget--) { s->failed_pc=0x0c04ee84u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ee88u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ee88u) { target=s->pc; goto dispatch; }
goto P_0c04ee88;
P_0c04ee86: /* original 64e3, guest PC 0x0c04ee86 */
if(!s->budget--) { s->failed_pc=0x0c04ee86u; return 0; }
r[4]=r[14];
goto P_0c04ee88;
P_0c04ee88: /* original d328, guest PC 0x0c04ee88 */
if(!s->budget--) { s->failed_pc=0x0c04ee88u; return 0; }
r[3]=read(ram,0x0c04ef2cu,4);
goto P_0c04ee8a;
P_0c04ee8a: /* original 6232, guest PC 0x0c04ee8a */
if(!s->budget--) { s->failed_pc=0x0c04ee8au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04ee8c;
P_0c04ee8c: /* original 2228, guest PC 0x0c04ee8c */
if(!s->budget--) { s->failed_pc=0x0c04ee8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04ee8e;
P_0c04ee8e: /* original 8d07, guest PC 0x0c04ee8e */
if(!s->budget--) { s->failed_pc=0x0c04ee8eu; return 0; }
cond=r[17]&1u;
r[12]=r[0];
if(cond) { goto P_0c04eea0; }
goto P_0c04ee92;
P_0c04ee90: /* original 6c03, guest PC 0x0c04ee90 */
if(!s->budget--) { s->failed_pc=0x0c04ee90u; return 0; }
r[12]=r[0];
goto P_0c04ee92;
P_0c04ee92: /* original d127, guest PC 0x0c04ee92 */
if(!s->budget--) { s->failed_pc=0x0c04ee92u; return 0; }
r[1]=read(ram,0x0c04ef30u,4);
goto P_0c04ee94;
P_0c04ee94: /* original e51a, guest PC 0x0c04ee94 */
if(!s->budget--) { s->failed_pc=0x0c04ee94u; return 0; }
r[5]=0x0000001au;
goto P_0c04ee96;
P_0c04ee96: /* original 66f1, guest PC 0x0c04ee96 */
if(!s->budget--) { s->failed_pc=0x0c04ee96u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c04ee98;
P_0c04ee98: /* original 6212, guest PC 0x0c04ee98 */
if(!s->budget--) { s->failed_pc=0x0c04ee98u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c04ee9a;
P_0c04ee9a: /* original 5024, guest PC 0x0c04ee9a */
if(!s->budget--) { s->failed_pc=0x0c04ee9au; return 0; }
r[0]=read(ram,r[2]+16,4);
goto P_0c04ee9c;
P_0c04ee9c: /* original 400b, guest PC 0x0c04ee9c */
if(!s->budget--) { s->failed_pc=0x0c04ee9cu; return 0; }
target=r[0];
r[16]=code_base|0x0c04eea0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eea0u) { target=s->pc; goto dispatch; }
goto P_0c04eea0;
P_0c04ee9e: /* original 64c3, guest PC 0x0c04ee9e */
if(!s->budget--) { s->failed_pc=0x0c04ee9eu; return 0; }
r[4]=r[12];
goto P_0c04eea0;
P_0c04eea0: /* original 84f4, guest PC 0x0c04eea0 */
if(!s->budget--) { s->failed_pc=0x0c04eea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04eea2;
P_0c04eea2: /* original 65d3, guest PC 0x0c04eea2 */
if(!s->budget--) { s->failed_pc=0x0c04eea2u; return 0; }
r[5]=r[13];
goto P_0c04eea4;
P_0c04eea4: /* original 80c1, guest PC 0x0c04eea4 */
if(!s->budget--) { s->failed_pc=0x0c04eea4u; return 0; }
write(ram,r[12]+1,r[0],1);
goto P_0c04eea6;
P_0c04eea6: /* original d323, guest PC 0x0c04eea6 */
if(!s->budget--) { s->failed_pc=0x0c04eea6u; return 0; }
r[3]=read(ram,0x0c04ef34u,4);
goto P_0c04eea8;
P_0c04eea8: /* original 430b, guest PC 0x0c04eea8 */
if(!s->budget--) { s->failed_pc=0x0c04eea8u; return 0; }
target=r[3];
r[16]=code_base|0x0c04eeacu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eeacu) { target=s->pc; goto dispatch; }
goto P_0c04eeac;
P_0c04eeaa: /* original 64e3, guest PC 0x0c04eeaa */
if(!s->budget--) { s->failed_pc=0x0c04eeaau; return 0; }
r[4]=r[14];
goto P_0c04eeac;
P_0c04eeac: /* original b44f, guest PC 0x0c04eeac */
if(!s->budget--) { s->failed_pc=0x0c04eeacu; return 0; }
target=0x0c04f74eu; r[16]=code_base|0x0c04eeb0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eeb0u) { target=s->pc; goto dispatch; }
goto P_0c04eeb0;
P_0c04eeae: /* original 64e3, guest PC 0x0c04eeae */
if(!s->budget--) { s->failed_pc=0x0c04eeaeu; return 0; }
r[4]=r[14];
goto P_0c04eeb0;
P_0c04eeb0: /* original 7f38, guest PC 0x0c04eeb0 */
if(!s->budget--) { s->failed_pc=0x0c04eeb0u; return 0; }
r[15]+=0x00000038u;
goto P_0c04eeb2;
P_0c04eeb2: /* original 4f16, guest PC 0x0c04eeb2 */
if(!s->budget--) { s->failed_pc=0x0c04eeb2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04eeb4;
P_0c04eeb4: /* original 4f26, guest PC 0x0c04eeb4 */
if(!s->budget--) { s->failed_pc=0x0c04eeb4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04eeb6;
P_0c04eeb6: /* original 6cf6, guest PC 0x0c04eeb6 */
if(!s->budget--) { s->failed_pc=0x0c04eeb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04eeb8;
P_0c04eeb8: /* original 6df6, guest PC 0x0c04eeb8 */
if(!s->budget--) { s->failed_pc=0x0c04eeb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04eeba;
P_0c04eeba: /* original 000b, guest PC 0x0c04eeba */
if(!s->budget--) { s->failed_pc=0x0c04eebau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04eebc: /* original 6ef6, guest PC 0x0c04eebc */
if(!s->budget--) { s->failed_pc=0x0c04eebcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04eebeu,s,ram);
P_0c04f632: /* original 4f22, guest PC 0x0c04f632 */
if(!s->budget--) { s->failed_pc=0x0c04f632u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f634;
P_0c04f634: /* original 9947, guest PC 0x0c04f634 */
if(!s->budget--) { s->failed_pc=0x0c04f634u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f6c6u,2);
goto P_0c04f636;
P_0c04f636: /* original d325, guest PC 0x0c04f636 */
if(!s->budget--) { s->failed_pc=0x0c04f636u; return 0; }
r[3]=read(ram,0x0c04f6ccu,4);
goto P_0c04f638;
P_0c04f638: /* original 4f12, guest PC 0x0c04f638 */
if(!s->budget--) { s->failed_pc=0x0c04f638u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f63a;
P_0c04f63a: /* original 2e9f, guest PC 0x0c04f63a */
if(!s->budget--) { s->failed_pc=0x0c04f63au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[9]);
goto P_0c04f63c;
P_0c04f63c: /* original 7ff0, guest PC 0x0c04f63c */
if(!s->budget--) { s->failed_pc=0x0c04f63cu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c04f63e;
P_0c04f63e: /* original 091a, guest PC 0x0c04f63e */
if(!s->budget--) { s->failed_pc=0x0c04f63eu; return 0; }
r[9]=r[19];
goto P_0c04f640;
P_0c04f640: /* original 699f, guest PC 0x0c04f640 */
if(!s->budget--) { s->failed_pc=0x0c04f640u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c04f642;
P_0c04f642: /* original 393c, guest PC 0x0c04f642 */
if(!s->budget--) { s->failed_pc=0x0c04f642u; return 0; }
r[9]+=r[3];
goto P_0c04f644;
P_0c04f644: /* original 5497, guest PC 0x0c04f644 */
if(!s->budget--) { s->failed_pc=0x0c04f644u; return 0; }
r[4]=read(ram,r[9]+28,4);
goto P_0c04f646;
P_0c04f646: /* original 854a, guest PC 0x0c04f646 */
if(!s->budget--) { s->failed_pc=0x0c04f646u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+20,2);
goto P_0c04f648;
P_0c04f648: /* original 81f2, guest PC 0x0c04f648 */
if(!s->budget--) { s->failed_pc=0x0c04f648u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c04f64a;
P_0c04f64a: /* original da21, guest PC 0x0c04f64a */
if(!s->budget--) { s->failed_pc=0x0c04f64au; return 0; }
r[10]=read(ram,0x0c04f6d0u,4);
goto P_0c04f64c;
P_0c04f64c: /* original 85f2, guest PC 0x0c04f64c */
if(!s->budget--) { s->failed_pc=0x0c04f64cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04f64e;
P_0c04f64e: /* original 5846, guest PC 0x0c04f64e */
if(!s->budget--) { s->failed_pc=0x0c04f64eu; return 0; }
r[8]=read(ram,r[4]+24,4);
goto P_0c04f650;
P_0c04f650: /* original 6da3, guest PC 0x0c04f650 */
if(!s->budget--) { s->failed_pc=0x0c04f650u; return 0; }
r[13]=r[10];
goto P_0c04f652;
P_0c04f652: /* original 6c03, guest PC 0x0c04f652 */
if(!s->budget--) { s->failed_pc=0x0c04f652u; return 0; }
r[12]=r[0];
goto P_0c04f654;
P_0c04f654: /* original 4815, guest PC 0x0c04f654 */
if(!s->budget--) { s->failed_pc=0x0c04f654u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c04f656;
P_0c04f656: /* original 8f12, guest PC 0x0c04f656 */
if(!s->budget--) { s->failed_pc=0x0c04f656u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c04f67e; }
goto P_0c04f65a;
P_0c04f658: /* original 7d02, guest PC 0x0c04f658 */
if(!s->budget--) { s->failed_pc=0x0c04f658u; return 0; }
r[13]+=0x00000002u;
goto P_0c04f65a;
P_0c04f65a: /* original 65cd, guest PC 0x0c04f65a */
if(!s->budget--) { s->failed_pc=0x0c04f65au; return 0; }
r[5]=r[12]&65535u;
goto P_0c04f65c;
P_0c04f65c: /* original 2f52, guest PC 0x0c04f65c */
if(!s->budget--) { s->failed_pc=0x0c04f65cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04f65e;
P_0c04f65e: /* original b41e, guest PC 0x0c04f65e */
if(!s->budget--) { s->failed_pc=0x0c04f65eu; return 0; }
target=0x0c04fe9eu; r[16]=code_base|0x0c04f662u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f662u) { target=s->pc; goto dispatch; }
goto P_0c04f662;
P_0c04f660: /* original 64e3, guest PC 0x0c04f660 */
if(!s->budget--) { s->failed_pc=0x0c04f660u; return 0; }
r[4]=r[14];
goto P_0c04f662;
P_0c04f662: /* original 65f2, guest PC 0x0c04f662 */
if(!s->budget--) { s->failed_pc=0x0c04f662u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f664;
P_0c04f664: /* original 66d3, guest PC 0x0c04f664 */
if(!s->budget--) { s->failed_pc=0x0c04f664u; return 0; }
r[6]=r[13];
goto P_0c04f666;
P_0c04f666: /* original 6c03, guest PC 0x0c04f666 */
if(!s->budget--) { s->failed_pc=0x0c04f666u; return 0; }
r[12]=r[0];
goto P_0c04f668;
P_0c04f668: /* original b3ea, guest PC 0x0c04f668 */
if(!s->budget--) { s->failed_pc=0x0c04f668u; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04f66cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f66cu) { target=s->pc; goto dispatch; }
goto P_0c04f66c;
P_0c04f66a: /* original 64e3, guest PC 0x0c04f66a */
if(!s->budget--) { s->failed_pc=0x0c04f66au; return 0; }
r[4]=r[14];
goto P_0c04f66c;
P_0c04f66c: /* original 62cd, guest PC 0x0c04f66c */
if(!s->budget--) { s->failed_pc=0x0c04f66cu; return 0; }
r[2]=r[12]&65535u;
goto P_0c04f66e;
P_0c04f66e: /* original 32a0, guest PC 0x0c04f66e */
if(!s->budget--) { s->failed_pc=0x0c04f66eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[10])!=0);
goto P_0c04f670;
P_0c04f670: /* original 8905, guest PC 0x0c04f670 */
if(!s->budget--) { s->failed_pc=0x0c04f670u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f67e; }
goto P_0c04f672;
P_0c04f672: /* original 63cd, guest PC 0x0c04f672 */
if(!s->budget--) { s->failed_pc=0x0c04f672u; return 0; }
r[3]=r[12]&65535u;
goto P_0c04f674;
P_0c04f674: /* original 33d0, guest PC 0x0c04f674 */
if(!s->budget--) { s->failed_pc=0x0c04f674u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[13])!=0);
goto P_0c04f676;
P_0c04f676: /* original 8902, guest PC 0x0c04f676 */
if(!s->budget--) { s->failed_pc=0x0c04f676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f67e; }
goto P_0c04f678;
P_0c04f678: /* original 7b01, guest PC 0x0c04f678 */
if(!s->budget--) { s->failed_pc=0x0c04f678u; return 0; }
r[11]+=0x00000001u;
goto P_0c04f67a;
P_0c04f67a: /* original 3b83, guest PC 0x0c04f67a */
if(!s->budget--) { s->failed_pc=0x0c04f67au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[8])!=0);
goto P_0c04f67c;
P_0c04f67c: /* original 8bed, guest PC 0x0c04f67c */
if(!s->budget--) { s->failed_pc=0x0c04f67cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f65a; }
goto P_0c04f67e;
P_0c04f67e: /* original 85f2, guest PC 0x0c04f67e */
if(!s->budget--) { s->failed_pc=0x0c04f67eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04f680;
P_0c04f680: /* original 6383, guest PC 0x0c04f680 */
if(!s->budget--) { s->failed_pc=0x0c04f680u; return 0; }
r[3]=r[8];
goto P_0c04f682;
P_0c04f682: /* original 73ff, guest PC 0x0c04f682 */
if(!s->budget--) { s->failed_pc=0x0c04f682u; return 0; }
r[3]+=0xffffffffu;
goto P_0c04f684;
P_0c04f684: /* original 6c03, guest PC 0x0c04f684 */
if(!s->budget--) { s->failed_pc=0x0c04f684u; return 0; }
r[12]=r[0];
goto P_0c04f686;
P_0c04f686: /* original eb00, guest PC 0x0c04f686 */
if(!s->budget--) { s->failed_pc=0x0c04f686u; return 0; }
r[11]=0x00000000u;
goto P_0c04f688;
P_0c04f688: /* original a041, guest PC 0x0c04f688 */
if(!s->budget--) { s->failed_pc=0x0c04f688u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04f70e;
P_0c04f68a: /* original 1f32, guest PC 0x0c04f68a */
if(!s->budget--) { s->failed_pc=0x0c04f68au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04f68c;
P_0c04f68c: /* original 61b3, guest PC 0x0c04f68c */
if(!s->budget--) { s->failed_pc=0x0c04f68cu; return 0; }
r[1]=r[11];
goto P_0c04f68e;
P_0c04f68e: /* original 4118, guest PC 0x0c04f68e */
if(!s->budget--) { s->failed_pc=0x0c04f68eu; return 0; }
r[1]<<=8;
goto P_0c04f690;
P_0c04f690: /* original 4100, guest PC 0x0c04f690 */
if(!s->budget--) { s->failed_pc=0x0c04f690u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c04f692;
P_0c04f692: /* original 2f12, guest PC 0x0c04f692 */
if(!s->budget--) { s->failed_pc=0x0c04f692u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c04f694;
P_0c04f694: /* original 569a, guest PC 0x0c04f694 */
if(!s->budget--) { s->failed_pc=0x0c04f694u; return 0; }
r[6]=read(ram,r[9]+40,4);
goto P_0c04f696;
P_0c04f696: /* original 65cd, guest PC 0x0c04f696 */
if(!s->budget--) { s->failed_pc=0x0c04f696u; return 0; }
r[5]=r[12]&65535u;
goto P_0c04f698;
P_0c04f698: /* original 63f2, guest PC 0x0c04f698 */
if(!s->budget--) { s->failed_pc=0x0c04f698u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04f69a;
P_0c04f69a: /* original d20e, guest PC 0x0c04f69a */
if(!s->budget--) { s->failed_pc=0x0c04f69au; return 0; }
r[2]=read(ram,0x0c04f6d4u,4);
goto P_0c04f69c;
P_0c04f69c: /* original 363c, guest PC 0x0c04f69c */
if(!s->budget--) { s->failed_pc=0x0c04f69cu; return 0; }
r[6]+=r[3];
goto P_0c04f69e;
P_0c04f69e: /* original 420b, guest PC 0x0c04f69e */
if(!s->budget--) { s->failed_pc=0x0c04f69eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f6a2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f6a2u) { target=s->pc; goto dispatch; }
goto P_0c04f6a2;
P_0c04f6a0: /* original 64e3, guest PC 0x0c04f6a0 */
if(!s->budget--) { s->failed_pc=0x0c04f6a0u; return 0; }
r[4]=r[14];
goto P_0c04f6a2;
P_0c04f6a2: /* original 6403, guest PC 0x0c04f6a2 */
if(!s->budget--) { s->failed_pc=0x0c04f6a2u; return 0; }
r[4]=r[0];
goto P_0c04f6a4;
P_0c04f6a4: /* original 2448, guest PC 0x0c04f6a4 */
if(!s->budget--) { s->failed_pc=0x0c04f6a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04f6a6;
P_0c04f6a6: /* original 891b, guest PC 0x0c04f6a6 */
if(!s->budget--) { s->failed_pc=0x0c04f6a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f6e0; }
goto P_0c04f6a8;
P_0c04f6a8: /* original 930e, guest PC 0x0c04f6a8 */
if(!s->budget--) { s->failed_pc=0x0c04f6a8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f6c8u,2);
goto P_0c04f6aa;
P_0c04f6aa: /* original 3430, guest PC 0x0c04f6aa */
if(!s->budget--) { s->failed_pc=0x0c04f6aau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c04f6ac;
P_0c04f6ac: /* original 8b01, guest PC 0x0c04f6ac */
if(!s->budget--) { s->failed_pc=0x0c04f6acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f6b2; }
goto P_0c04f6ae;
P_0c04f6ae: /* original a043, guest PC 0x0c04f6ae */
if(!s->budget--) { s->failed_pc=0x0c04f6aeu; return 0; }
r[0]=r[4];
goto P_0c04f738;
P_0c04f6b0: /* original 6043, guest PC 0x0c04f6b0 */
if(!s->budget--) { s->failed_pc=0x0c04f6b0u; return 0; }
r[0]=r[4];
goto P_0c04f6b2;
P_0c04f6b2: /* original d609, guest PC 0x0c04f6b2 */
if(!s->budget--) { s->failed_pc=0x0c04f6b2u; return 0; }
r[6]=read(ram,0x0c04f6d8u,4);
goto P_0c04f6b4;
P_0c04f6b4: /* original 65cd, guest PC 0x0c04f6b4 */
if(!s->budget--) { s->failed_pc=0x0c04f6b4u; return 0; }
r[5]=r[12]&65535u;
goto P_0c04f6b6;
P_0c04f6b6: /* original b3c3, guest PC 0x0c04f6b6 */
if(!s->budget--) { s->failed_pc=0x0c04f6b6u; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04f6bau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f6bau) { target=s->pc; goto dispatch; }
goto P_0c04f6ba;
P_0c04f6b8: /* original 64e3, guest PC 0x0c04f6b8 */
if(!s->budget--) { s->failed_pc=0x0c04f6b8u; return 0; }
r[4]=r[14];
goto P_0c04f6ba;
P_0c04f6ba: /* original d208, guest PC 0x0c04f6ba */
if(!s->budget--) { s->failed_pc=0x0c04f6bau; return 0; }
r[2]=read(ram,0x0c04f6dcu,4);
goto P_0c04f6bc;
P_0c04f6bc: /* original 65d3, guest PC 0x0c04f6bc */
if(!s->budget--) { s->failed_pc=0x0c04f6bcu; return 0; }
r[5]=r[13];
goto P_0c04f6be;
P_0c04f6be: /* original 420b, guest PC 0x0c04f6be */
if(!s->budget--) { s->failed_pc=0x0c04f6beu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f6c2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f6c2u) { target=s->pc; goto dispatch; }
goto P_0c04f6c2;
P_0c04f6c0: /* original 64e3, guest PC 0x0c04f6c0 */
if(!s->budget--) { s->failed_pc=0x0c04f6c0u; return 0; }
r[4]=r[14];
goto P_0c04f6c2;
P_0c04f6c2: /* original afe7, guest PC 0x0c04f6c2 */
if(!s->budget--) { s->failed_pc=0x0c04f6c2u; return 0; }
r[12]=r[0];
goto P_0c04f694;
P_0c04f6c4: /* original 6c03, guest PC 0x0c04f6c4 */
if(!s->budget--) { s->failed_pc=0x0c04f6c4u; return 0; }
r[12]=r[0];
return vf3_matrix_family(0x0c04f6c6u,s,ram);
P_0c04f6e0: /* original 2bb8, guest PC 0x0c04f6e0 */
if(!s->budget--) { s->failed_pc=0x0c04f6e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c04f6e2;
P_0c04f6e2: /* original 8f02, guest PC 0x0c04f6e2 */
if(!s->budget--) { s->failed_pc=0x0c04f6e2u; return 0; }
cond=r[17]&1u;
r[6]=r[10];
if(!cond) { goto P_0c04f6ea; }
goto P_0c04f6e6;
P_0c04f6e4: /* original 66a3, guest PC 0x0c04f6e4 */
if(!s->budget--) { s->failed_pc=0x0c04f6e4u; return 0; }
r[6]=r[10];
goto P_0c04f6e6;
P_0c04f6e6: /* original 60c3, guest PC 0x0c04f6e6 */
if(!s->budget--) { s->failed_pc=0x0c04f6e6u; return 0; }
r[0]=r[12];
goto P_0c04f6e8;
P_0c04f6e8: /* original 81f2, guest PC 0x0c04f6e8 */
if(!s->budget--) { s->failed_pc=0x0c04f6e8u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c04f6ea;
P_0c04f6ea: /* original 65cd, guest PC 0x0c04f6ea */
if(!s->budget--) { s->failed_pc=0x0c04f6eau; return 0; }
r[5]=r[12]&65535u;
goto P_0c04f6ec;
P_0c04f6ec: /* original 1f53, guest PC 0x0c04f6ec */
if(!s->budget--) { s->failed_pc=0x0c04f6ecu; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c04f6ee;
P_0c04f6ee: /* original b3a7, guest PC 0x0c04f6ee */
if(!s->budget--) { s->failed_pc=0x0c04f6eeu; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04f6f2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f6f2u) { target=s->pc; goto dispatch; }
goto P_0c04f6f2;
P_0c04f6f0: /* original 64e3, guest PC 0x0c04f6f0 */
if(!s->budget--) { s->failed_pc=0x0c04f6f0u; return 0; }
r[4]=r[14];
goto P_0c04f6f2;
P_0c04f6f2: /* original 52f2, guest PC 0x0c04f6f2 */
if(!s->budget--) { s->failed_pc=0x0c04f6f2u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04f6f4;
P_0c04f6f4: /* original 3b20, guest PC 0x0c04f6f4 */
if(!s->budget--) { s->failed_pc=0x0c04f6f4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[2])!=0);
goto P_0c04f6f6;
P_0c04f6f6: /* original 8909, guest PC 0x0c04f6f6 */
if(!s->budget--) { s->failed_pc=0x0c04f6f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f70c; }
goto P_0c04f6f8;
P_0c04f6f8: /* original d235, guest PC 0x0c04f6f8 */
if(!s->budget--) { s->failed_pc=0x0c04f6f8u; return 0; }
r[2]=read(ram,0x0c04f7d0u,4);
goto P_0c04f6fa;
P_0c04f6fa: /* original 65d3, guest PC 0x0c04f6fa */
if(!s->budget--) { s->failed_pc=0x0c04f6fau; return 0; }
r[5]=r[13];
goto P_0c04f6fc;
P_0c04f6fc: /* original 420b, guest PC 0x0c04f6fc */
if(!s->budget--) { s->failed_pc=0x0c04f6fcu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f700u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f700u) { target=s->pc; goto dispatch; }
goto P_0c04f700;
P_0c04f6fe: /* original 64e3, guest PC 0x0c04f6fe */
if(!s->budget--) { s->failed_pc=0x0c04f6feu; return 0; }
r[4]=r[14];
goto P_0c04f700;
P_0c04f700: /* original 6603, guest PC 0x0c04f700 */
if(!s->budget--) { s->failed_pc=0x0c04f700u; return 0; }
r[6]=r[0];
goto P_0c04f702;
P_0c04f702: /* original 2f01, guest PC 0x0c04f702 */
if(!s->budget--) { s->failed_pc=0x0c04f702u; return 0; }
write(ram,r[15],r[0],2);
goto P_0c04f704;
P_0c04f704: /* original 55f3, guest PC 0x0c04f704 */
if(!s->budget--) { s->failed_pc=0x0c04f704u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c04f706;
P_0c04f706: /* original b39b, guest PC 0x0c04f706 */
if(!s->budget--) { s->failed_pc=0x0c04f706u; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04f70au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f70au) { target=s->pc; goto dispatch; }
goto P_0c04f70a;
P_0c04f708: /* original 64e3, guest PC 0x0c04f708 */
if(!s->budget--) { s->failed_pc=0x0c04f708u; return 0; }
r[4]=r[14];
goto P_0c04f70a;
P_0c04f70a: /* original 6cf1, guest PC 0x0c04f70a */
if(!s->budget--) { s->failed_pc=0x0c04f70au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[12]=tmp;
goto P_0c04f70c;
P_0c04f70c: /* original 7b01, guest PC 0x0c04f70c */
if(!s->budget--) { s->failed_pc=0x0c04f70cu; return 0; }
r[11]+=0x00000001u;
goto P_0c04f70e;
P_0c04f70e: /* original 3b83, guest PC 0x0c04f70e */
if(!s->budget--) { s->failed_pc=0x0c04f70eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[8])!=0);
goto P_0c04f710;
P_0c04f710: /* original 8bbc, guest PC 0x0c04f710 */
if(!s->budget--) { s->failed_pc=0x0c04f710u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f68c; }
goto P_0c04f712;
P_0c04f712: /* original 5397, guest PC 0x0c04f712 */
if(!s->budget--) { s->failed_pc=0x0c04f712u; return 0; }
r[3]=read(ram,r[9]+28,4);
goto P_0c04f714;
P_0c04f714: /* original 85f2, guest PC 0x0c04f714 */
if(!s->budget--) { s->failed_pc=0x0c04f714u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04f716;
P_0c04f716: /* original 5235, guest PC 0x0c04f716 */
if(!s->budget--) { s->failed_pc=0x0c04f716u; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c04f718;
P_0c04f718: /* original 600d, guest PC 0x0c04f718 */
if(!s->budget--) { s->failed_pc=0x0c04f718u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f71a;
P_0c04f71a: /* original 3020, guest PC 0x0c04f71a */
if(!s->budget--) { s->failed_pc=0x0c04f71au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c04f71c;
P_0c04f71c: /* original 890b, guest PC 0x0c04f71c */
if(!s->budget--) { s->failed_pc=0x0c04f71cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f736; }
goto P_0c04f71e;
P_0c04f71e: /* original d32d, guest PC 0x0c04f71e */
if(!s->budget--) { s->failed_pc=0x0c04f71eu; return 0; }
r[3]=read(ram,0x0c04f7d4u,4);
goto P_0c04f720;
P_0c04f720: /* original e54a, guest PC 0x0c04f720 */
if(!s->budget--) { s->failed_pc=0x0c04f720u; return 0; }
r[5]=0x0000004au;
goto P_0c04f722;
P_0c04f722: /* original 85f2, guest PC 0x0c04f722 */
if(!s->budget--) { s->failed_pc=0x0c04f722u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04f724;
P_0c04f724: /* original 6132, guest PC 0x0c04f724 */
if(!s->budget--) { s->failed_pc=0x0c04f724u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c04f726;
P_0c04f726: /* original 6603, guest PC 0x0c04f726 */
if(!s->budget--) { s->failed_pc=0x0c04f726u; return 0; }
r[6]=r[0];
goto P_0c04f728;
P_0c04f728: /* original 5214, guest PC 0x0c04f728 */
if(!s->budget--) { s->failed_pc=0x0c04f728u; return 0; }
r[2]=read(ram,r[1]+16,4);
goto P_0c04f72a;
P_0c04f72a: /* original 420b, guest PC 0x0c04f72a */
if(!s->budget--) { s->failed_pc=0x0c04f72au; return 0; }
target=r[2];
r[16]=code_base|0x0c04f72eu;
r[4]=read(ram,r[9]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f72eu) { target=s->pc; goto dispatch; }
goto P_0c04f72e;
P_0c04f72c: /* original 5498, guest PC 0x0c04f72c */
if(!s->budget--) { s->failed_pc=0x0c04f72cu; return 0; }
r[4]=read(ram,r[9]+32,4);
goto P_0c04f72e;
P_0c04f72e: /* original b2ff, guest PC 0x0c04f72e */
if(!s->budget--) { s->failed_pc=0x0c04f72eu; return 0; }
target=0x0c04fd30u; r[16]=code_base|0x0c04f732u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f732u) { target=s->pc; goto dispatch; }
goto P_0c04f732;
P_0c04f730: /* original 64e3, guest PC 0x0c04f730 */
if(!s->budget--) { s->failed_pc=0x0c04f730u; return 0; }
r[4]=r[14];
goto P_0c04f732;
P_0c04f732: /* original b1e3, guest PC 0x0c04f732 */
if(!s->budget--) { s->failed_pc=0x0c04f732u; return 0; }
target=0x0c04fafcu; r[16]=code_base|0x0c04f736u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f736u) { target=s->pc; goto dispatch; }
goto P_0c04f736;
P_0c04f734: /* original 64e3, guest PC 0x0c04f734 */
if(!s->budget--) { s->failed_pc=0x0c04f734u; return 0; }
r[4]=r[14];
goto P_0c04f736;
P_0c04f736: /* original e000, guest PC 0x0c04f736 */
if(!s->budget--) { s->failed_pc=0x0c04f736u; return 0; }
r[0]=0x00000000u;
goto P_0c04f738;
P_0c04f738: /* original 7f10, guest PC 0x0c04f738 */
if(!s->budget--) { s->failed_pc=0x0c04f738u; return 0; }
r[15]+=0x00000010u;
goto P_0c04f73a;
P_0c04f73a: /* original 4f16, guest PC 0x0c04f73a */
if(!s->budget--) { s->failed_pc=0x0c04f73au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f73c;
P_0c04f73c: /* original 4f26, guest PC 0x0c04f73c */
if(!s->budget--) { s->failed_pc=0x0c04f73cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f73e;
P_0c04f73e: /* original 68f6, guest PC 0x0c04f73e */
if(!s->budget--) { s->failed_pc=0x0c04f73eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04f740;
P_0c04f740: /* original 69f6, guest PC 0x0c04f740 */
if(!s->budget--) { s->failed_pc=0x0c04f740u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04f742;
P_0c04f742: /* original 6af6, guest PC 0x0c04f742 */
if(!s->budget--) { s->failed_pc=0x0c04f742u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04f744;
P_0c04f744: /* original 6bf6, guest PC 0x0c04f744 */
if(!s->budget--) { s->failed_pc=0x0c04f744u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04f746;
P_0c04f746: /* original 6cf6, guest PC 0x0c04f746 */
if(!s->budget--) { s->failed_pc=0x0c04f746u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f748;
P_0c04f748: /* original 6df6, guest PC 0x0c04f748 */
if(!s->budget--) { s->failed_pc=0x0c04f748u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f74a;
P_0c04f74a: /* original 000b, guest PC 0x0c04f74a */
if(!s->budget--) { s->failed_pc=0x0c04f74au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f74c: /* original 6ef6, guest PC 0x0c04f74c */
if(!s->budget--) { s->failed_pc=0x0c04f74cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f74e;
P_0c04f74e: /* original 2fe6, guest PC 0x0c04f74e */
if(!s->budget--) { s->failed_pc=0x0c04f74eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f750;
P_0c04f750: /* original 2fd6, guest PC 0x0c04f750 */
if(!s->budget--) { s->failed_pc=0x0c04f750u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f752;
P_0c04f752: /* original 6d43, guest PC 0x0c04f752 */
if(!s->budget--) { s->failed_pc=0x0c04f752u; return 0; }
r[13]=r[4];
goto P_0c04f754;
P_0c04f754: /* original 2fc6, guest PC 0x0c04f754 */
if(!s->budget--) { s->failed_pc=0x0c04f754u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f756;
P_0c04f756: /* original 2fb6, guest PC 0x0c04f756 */
if(!s->budget--) { s->failed_pc=0x0c04f756u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f758;
P_0c04f758: /* original 2fa6, guest PC 0x0c04f758 */
if(!s->budget--) { s->failed_pc=0x0c04f758u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f75a;
P_0c04f75a: /* original 2f96, guest PC 0x0c04f75a */
if(!s->budget--) { s->failed_pc=0x0c04f75au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f75c;
P_0c04f75c: /* original 2f86, guest PC 0x0c04f75c */
if(!s->budget--) { s->failed_pc=0x0c04f75cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f75e;
P_0c04f75e: /* original 4f22, guest PC 0x0c04f75e */
if(!s->budget--) { s->failed_pc=0x0c04f75eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f760;
P_0c04f760: /* original 9935, guest PC 0x0c04f760 */
if(!s->budget--) { s->failed_pc=0x0c04f760u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f7ceu,2);
goto P_0c04f762;
P_0c04f762: /* original d31d, guest PC 0x0c04f762 */
if(!s->budget--) { s->failed_pc=0x0c04f762u; return 0; }
r[3]=read(ram,0x0c04f7d8u,4);
goto P_0c04f764;
P_0c04f764: /* original 4f12, guest PC 0x0c04f764 */
if(!s->budget--) { s->failed_pc=0x0c04f764u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f766;
P_0c04f766: /* original 2d9f, guest PC 0x0c04f766 */
if(!s->budget--) { s->failed_pc=0x0c04f766u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[9]);
goto P_0c04f768;
P_0c04f768: /* original 7ff4, guest PC 0x0c04f768 */
if(!s->budget--) { s->failed_pc=0x0c04f768u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c04f76a;
P_0c04f76a: /* original 2f46, guest PC 0x0c04f76a */
if(!s->budget--) { s->failed_pc=0x0c04f76au; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f76c;
P_0c04f76c: /* original 091a, guest PC 0x0c04f76c */
if(!s->budget--) { s->failed_pc=0x0c04f76cu; return 0; }
r[9]=r[19];
goto P_0c04f76e;
P_0c04f76e: /* original d21b, guest PC 0x0c04f76e */
if(!s->budget--) { s->failed_pc=0x0c04f76eu; return 0; }
r[2]=read(ram,0x0c04f7dcu,4);
goto P_0c04f770;
P_0c04f770: /* original d11b, guest PC 0x0c04f770 */
if(!s->budget--) { s->failed_pc=0x0c04f770u; return 0; }
r[1]=read(ram,0x0c04f7e0u,4);
goto P_0c04f772;
P_0c04f772: /* original 699f, guest PC 0x0c04f772 */
if(!s->budget--) { s->failed_pc=0x0c04f772u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c04f774;
P_0c04f774: /* original 393c, guest PC 0x0c04f774 */
if(!s->budget--) { s->failed_pc=0x0c04f774u; return 0; }
r[9]+=r[3];
goto P_0c04f776;
P_0c04f776: /* original 410b, guest PC 0x0c04f776 */
if(!s->budget--) { s->failed_pc=0x0c04f776u; return 0; }
target=r[1];
r[16]=code_base|0x0c04f77au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f77au) { target=s->pc; goto dispatch; }
goto P_0c04f77a;
P_0c04f778: /* original 2f26, guest PC 0x0c04f778 */
if(!s->budget--) { s->failed_pc=0x0c04f778u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f77a;
P_0c04f77a: /* original 5597, guest PC 0x0c04f77a */
if(!s->budget--) { s->failed_pc=0x0c04f77au; return 0; }
r[5]=read(ram,r[9]+28,4);
goto P_0c04f77c;
P_0c04f77c: /* original 7f08, guest PC 0x0c04f77c */
if(!s->budget--) { s->failed_pc=0x0c04f77cu; return 0; }
r[15]+=0x00000008u;
goto P_0c04f77e;
P_0c04f77e: /* original 5356, guest PC 0x0c04f77e */
if(!s->budget--) { s->failed_pc=0x0c04f77eu; return 0; }
r[3]=read(ram,r[5]+24,4);
goto P_0c04f780;
P_0c04f780: /* original 5455, guest PC 0x0c04f780 */
if(!s->budget--) { s->failed_pc=0x0c04f780u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c04f782;
P_0c04f782: /* original 1f31, guest PC 0x0c04f782 */
if(!s->budget--) { s->failed_pc=0x0c04f782u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04f784;
P_0c04f784: /* original e300, guest PC 0x0c04f784 */
if(!s->budget--) { s->failed_pc=0x0c04f784u; return 0; }
r[3]=0x00000000u;
goto P_0c04f786;
P_0c04f786: /* original 6a33, guest PC 0x0c04f786 */
if(!s->budget--) { s->failed_pc=0x0c04f786u; return 0; }
r[10]=r[3];
goto P_0c04f788;
P_0c04f788: /* original 1f32, guest PC 0x0c04f788 */
if(!s->budget--) { s->failed_pc=0x0c04f788u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04f78a;
P_0c04f78a: /* original a061, guest PC 0x0c04f78a */
if(!s->budget--) { s->failed_pc=0x0c04f78au; return 0; }
r[14]=r[4]&65535u;
goto P_0c04f850;
P_0c04f78c: /* original 6e4d, guest PC 0x0c04f78c */
if(!s->budget--) { s->failed_pc=0x0c04f78cu; return 0; }
r[14]=r[4]&65535u;
goto P_0c04f78e;
P_0c04f78e: /* original 6293, guest PC 0x0c04f78e */
if(!s->budget--) { s->failed_pc=0x0c04f78eu; return 0; }
r[2]=r[9];
goto P_0c04f790;
P_0c04f790: /* original 7248, guest PC 0x0c04f790 */
if(!s->budget--) { s->failed_pc=0x0c04f790u; return 0; }
r[2]+=0x00000048u;
goto P_0c04f792;
P_0c04f792: /* original 32ac, guest PC 0x0c04f792 */
if(!s->budget--) { s->failed_pc=0x0c04f792u; return 0; }
r[2]+=r[10];
goto P_0c04f794;
P_0c04f794: /* original 6320, guest PC 0x0c04f794 */
if(!s->budget--) { s->failed_pc=0x0c04f794u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c04f796;
P_0c04f796: /* original 2338, guest PC 0x0c04f796 */
if(!s->budget--) { s->failed_pc=0x0c04f796u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04f798;
P_0c04f798: /* original 8953, guest PC 0x0c04f798 */
if(!s->budget--) { s->failed_pc=0x0c04f798u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f842; }
goto P_0c04f79a;
P_0c04f79a: /* original 63a3, guest PC 0x0c04f79a */
if(!s->budget--) { s->failed_pc=0x0c04f79au; return 0; }
r[3]=r[10];
goto P_0c04f79c;
P_0c04f79c: /* original 4318, guest PC 0x0c04f79c */
if(!s->budget--) { s->failed_pc=0x0c04f79cu; return 0; }
r[3]<<=8;
goto P_0c04f79e;
P_0c04f79e: /* original 4300, guest PC 0x0c04f79e */
if(!s->budget--) { s->failed_pc=0x0c04f79eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c04f7a0;
P_0c04f7a0: /* original 2f32, guest PC 0x0c04f7a0 */
if(!s->budget--) { s->failed_pc=0x0c04f7a0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04f7a2;
P_0c04f7a2: /* original 569a, guest PC 0x0c04f7a2 */
if(!s->budget--) { s->failed_pc=0x0c04f7a2u; return 0; }
r[6]=read(ram,r[9]+40,4);
goto P_0c04f7a4;
P_0c04f7a4: /* original 65e3, guest PC 0x0c04f7a4 */
if(!s->budget--) { s->failed_pc=0x0c04f7a4u; return 0; }
r[5]=r[14];
goto P_0c04f7a6;
P_0c04f7a6: /* original 63f2, guest PC 0x0c04f7a6 */
if(!s->budget--) { s->failed_pc=0x0c04f7a6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04f7a8;
P_0c04f7a8: /* original d20e, guest PC 0x0c04f7a8 */
if(!s->budget--) { s->failed_pc=0x0c04f7a8u; return 0; }
r[2]=read(ram,0x0c04f7e4u,4);
goto P_0c04f7aa;
P_0c04f7aa: /* original 363c, guest PC 0x0c04f7aa */
if(!s->budget--) { s->failed_pc=0x0c04f7aau; return 0; }
r[6]+=r[3];
goto P_0c04f7ac;
P_0c04f7ac: /* original 420b, guest PC 0x0c04f7ac */
if(!s->budget--) { s->failed_pc=0x0c04f7acu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f7b0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f7b0u) { target=s->pc; goto dispatch; }
goto P_0c04f7b0;
P_0c04f7ae: /* original 64d3, guest PC 0x0c04f7ae */
if(!s->budget--) { s->failed_pc=0x0c04f7aeu; return 0; }
r[4]=r[13];
goto P_0c04f7b0;
P_0c04f7b0: /* original 6403, guest PC 0x0c04f7b0 */
if(!s->budget--) { s->failed_pc=0x0c04f7b0u; return 0; }
r[4]=r[0];
goto P_0c04f7b2;
P_0c04f7b2: /* original 2448, guest PC 0x0c04f7b2 */
if(!s->budget--) { s->failed_pc=0x0c04f7b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04f7b4;
P_0c04f7b4: /* original 8b18, guest PC 0x0c04f7b4 */
if(!s->budget--) { s->failed_pc=0x0c04f7b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f7e8; }
goto P_0c04f7b6;
P_0c04f7b6: /* original 65e3, guest PC 0x0c04f7b6 */
if(!s->budget--) { s->failed_pc=0x0c04f7b6u; return 0; }
r[5]=r[14];
goto P_0c04f7b8;
P_0c04f7b8: /* original b371, guest PC 0x0c04f7b8 */
if(!s->budget--) { s->failed_pc=0x0c04f7b8u; return 0; }
target=0x0c04fe9eu; r[16]=code_base|0x0c04f7bcu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f7bcu) { target=s->pc; goto dispatch; }
goto P_0c04f7bc;
P_0c04f7ba: /* original 64d3, guest PC 0x0c04f7ba */
if(!s->budget--) { s->failed_pc=0x0c04f7bau; return 0; }
r[4]=r[13];
goto P_0c04f7bc;
P_0c04f7bc: /* original 6393, guest PC 0x0c04f7bc */
if(!s->budget--) { s->failed_pc=0x0c04f7bcu; return 0; }
r[3]=r[9];
goto P_0c04f7be;
P_0c04f7be: /* original 7348, guest PC 0x0c04f7be */
if(!s->budget--) { s->failed_pc=0x0c04f7beu; return 0; }
r[3]+=0x00000048u;
goto P_0c04f7c0;
P_0c04f7c0: /* original 33ac, guest PC 0x0c04f7c0 */
if(!s->budget--) { s->failed_pc=0x0c04f7c0u; return 0; }
r[3]+=r[10];
goto P_0c04f7c2;
P_0c04f7c2: /* original 68e3, guest PC 0x0c04f7c2 */
if(!s->budget--) { s->failed_pc=0x0c04f7c2u; return 0; }
r[8]=r[14];
goto P_0c04f7c4;
P_0c04f7c4: /* original e200, guest PC 0x0c04f7c4 */
if(!s->budget--) { s->failed_pc=0x0c04f7c4u; return 0; }
r[2]=0x00000000u;
goto P_0c04f7c6;
P_0c04f7c6: /* original 2320, guest PC 0x0c04f7c6 */
if(!s->budget--) { s->failed_pc=0x0c04f7c6u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c04f7c8;
P_0c04f7c8: /* original 6b0d, guest PC 0x0c04f7c8 */
if(!s->budget--) { s->failed_pc=0x0c04f7c8u; return 0; }
r[11]=r[0]&65535u;
goto P_0c04f7ca;
P_0c04f7ca: /* original a040, guest PC 0x0c04f7ca */
if(!s->budget--) { s->failed_pc=0x0c04f7cau; return 0; }
r[14]=r[11];
goto P_0c04f84e;
P_0c04f7cc: /* original 6eb3, guest PC 0x0c04f7cc */
if(!s->budget--) { s->failed_pc=0x0c04f7ccu; return 0; }
r[14]=r[11];
return vf3_matrix_family(0x0c04f7ceu,s,ram);
P_0c04f7e8: /* original 925d, guest PC 0x0c04f7e8 */
if(!s->budget--) { s->failed_pc=0x0c04f7e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f8a6u,2);
goto P_0c04f7ea;
P_0c04f7ea: /* original 3420, guest PC 0x0c04f7ea */
if(!s->budget--) { s->failed_pc=0x0c04f7eau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c04f7ec;
P_0c04f7ec: /* original 8940, guest PC 0x0c04f7ec */
if(!s->budget--) { s->failed_pc=0x0c04f7ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f870; }
goto P_0c04f7ee;
P_0c04f7ee: /* original e201, guest PC 0x0c04f7ee */
if(!s->budget--) { s->failed_pc=0x0c04f7eeu; return 0; }
r[2]=0x00000001u;
goto P_0c04f7f0;
P_0c04f7f0: /* original 65e3, guest PC 0x0c04f7f0 */
if(!s->budget--) { s->failed_pc=0x0c04f7f0u; return 0; }
r[5]=r[14];
goto P_0c04f7f2;
P_0c04f7f2: /* original 1f22, guest PC 0x0c04f7f2 */
if(!s->budget--) { s->failed_pc=0x0c04f7f2u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c04f7f4;
P_0c04f7f4: /* original b353, guest PC 0x0c04f7f4 */
if(!s->budget--) { s->failed_pc=0x0c04f7f4u; return 0; }
target=0x0c04fe9eu; r[16]=code_base|0x0c04f7f8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f7f8u) { target=s->pc; goto dispatch; }
goto P_0c04f7f8;
P_0c04f7f6: /* original 64d3, guest PC 0x0c04f7f6 */
if(!s->budget--) { s->failed_pc=0x0c04f7f6u; return 0; }
r[4]=r[13];
goto P_0c04f7f8;
P_0c04f7f8: /* original d62c, guest PC 0x0c04f7f8 */
if(!s->budget--) { s->failed_pc=0x0c04f7f8u; return 0; }
r[6]=read(ram,0x0c04f8acu,4);
goto P_0c04f7fa;
P_0c04f7fa: /* original 65e3, guest PC 0x0c04f7fa */
if(!s->budget--) { s->failed_pc=0x0c04f7fau; return 0; }
r[5]=r[14];
goto P_0c04f7fc;
P_0c04f7fc: /* original 6b0d, guest PC 0x0c04f7fc */
if(!s->budget--) { s->failed_pc=0x0c04f7fcu; return 0; }
r[11]=r[0]&65535u;
goto P_0c04f7fe;
P_0c04f7fe: /* original b31f, guest PC 0x0c04f7fe */
if(!s->budget--) { s->failed_pc=0x0c04f7feu; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04f802u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f802u) { target=s->pc; goto dispatch; }
goto P_0c04f802;
P_0c04f800: /* original 64d3, guest PC 0x0c04f800 */
if(!s->budget--) { s->failed_pc=0x0c04f800u; return 0; }
r[4]=r[13];
goto P_0c04f802;
P_0c04f802: /* original d32c, guest PC 0x0c04f802 */
if(!s->budget--) { s->failed_pc=0x0c04f802u; return 0; }
r[3]=read(ram,0x0c04f8b4u,4);
goto P_0c04f804;
P_0c04f804: /* original d52a, guest PC 0x0c04f804 */
if(!s->budget--) { s->failed_pc=0x0c04f804u; return 0; }
r[5]=read(ram,0x0c04f8b0u,4);
goto P_0c04f806;
P_0c04f806: /* original 430b, guest PC 0x0c04f806 */
if(!s->budget--) { s->failed_pc=0x0c04f806u; return 0; }
target=r[3];
r[16]=code_base|0x0c04f80au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f80au) { target=s->pc; goto dispatch; }
goto P_0c04f80a;
P_0c04f808: /* original 64d3, guest PC 0x0c04f808 */
if(!s->budget--) { s->failed_pc=0x0c04f808u; return 0; }
r[4]=r[13];
goto P_0c04f80a;
P_0c04f80a: /* original 6c03, guest PC 0x0c04f80a */
if(!s->budget--) { s->failed_pc=0x0c04f80au; return 0; }
r[12]=r[0];
goto P_0c04f80c;
P_0c04f80c: /* original 4c11, guest PC 0x0c04f80c */
if(!s->budget--) { s->failed_pc=0x0c04f80cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c04f80e;
P_0c04f80e: /* original 8902, guest PC 0x0c04f80e */
if(!s->budget--) { s->failed_pc=0x0c04f80eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f816; }
goto P_0c04f810;
P_0c04f810: /* original 904a, guest PC 0x0c04f810 */
if(!s->budget--) { s->failed_pc=0x0c04f810u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f8a8u,2);
goto P_0c04f812;
P_0c04f812: /* original a030, guest PC 0x0c04f812 */
if(!s->budget--) { s->failed_pc=0x0c04f812u; return 0; }
goto P_0c04f876;
P_0c04f814: /* original 0009, guest PC 0x0c04f814 */
if(!s->budget--) { s->failed_pc=0x0c04f814u; return 0; }
goto P_0c04f816;
P_0c04f816: /* original 65c3, guest PC 0x0c04f816 */
if(!s->budget--) { s->failed_pc=0x0c04f816u; return 0; }
r[5]=r[12];
goto P_0c04f818;
P_0c04f818: /* original 66b3, guest PC 0x0c04f818 */
if(!s->budget--) { s->failed_pc=0x0c04f818u; return 0; }
r[6]=r[11];
goto P_0c04f81a;
P_0c04f81a: /* original b311, guest PC 0x0c04f81a */
if(!s->budget--) { s->failed_pc=0x0c04f81au; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04f81eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f81eu) { target=s->pc; goto dispatch; }
goto P_0c04f81e;
P_0c04f81c: /* original 64d3, guest PC 0x0c04f81c */
if(!s->budget--) { s->failed_pc=0x0c04f81cu; return 0; }
r[4]=r[13];
goto P_0c04f81e;
P_0c04f81e: /* original 2aa8, guest PC 0x0c04f81e */
if(!s->budget--) { s->failed_pc=0x0c04f81eu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c04f820;
P_0c04f820: /* original 8b08, guest PC 0x0c04f820 */
if(!s->budget--) { s->failed_pc=0x0c04f820u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f834; }
goto P_0c04f822;
P_0c04f822: /* original d225, guest PC 0x0c04f822 */
if(!s->budget--) { s->failed_pc=0x0c04f822u; return 0; }
r[2]=read(ram,0x0c04f8b8u,4);
goto P_0c04f824;
P_0c04f824: /* original e54a, guest PC 0x0c04f824 */
if(!s->budget--) { s->failed_pc=0x0c04f824u; return 0; }
r[5]=0x0000004au;
goto P_0c04f826;
P_0c04f826: /* original 66c3, guest PC 0x0c04f826 */
if(!s->budget--) { s->failed_pc=0x0c04f826u; return 0; }
r[6]=r[12];
goto P_0c04f828;
P_0c04f828: /* original 6322, guest PC 0x0c04f828 */
if(!s->budget--) { s->failed_pc=0x0c04f828u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04f82a;
P_0c04f82a: /* original 5134, guest PC 0x0c04f82a */
if(!s->budget--) { s->failed_pc=0x0c04f82au; return 0; }
r[1]=read(ram,r[3]+16,4);
goto P_0c04f82c;
P_0c04f82c: /* original 410b, guest PC 0x0c04f82c */
if(!s->budget--) { s->failed_pc=0x0c04f82cu; return 0; }
target=r[1];
r[16]=code_base|0x0c04f830u;
r[4]=read(ram,r[9]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f830u) { target=s->pc; goto dispatch; }
goto P_0c04f830;
P_0c04f82e: /* original 5498, guest PC 0x0c04f82e */
if(!s->budget--) { s->failed_pc=0x0c04f82eu; return 0; }
r[4]=read(ram,r[9]+32,4);
goto P_0c04f830;
P_0c04f830: /* original a004, guest PC 0x0c04f830 */
if(!s->budget--) { s->failed_pc=0x0c04f830u; return 0; }
goto P_0c04f83c;
P_0c04f832: /* original 0009, guest PC 0x0c04f832 */
if(!s->budget--) { s->failed_pc=0x0c04f832u; return 0; }
goto P_0c04f834;
P_0c04f834: /* original 6583, guest PC 0x0c04f834 */
if(!s->budget--) { s->failed_pc=0x0c04f834u; return 0; }
r[5]=r[8];
goto P_0c04f836;
P_0c04f836: /* original 66c3, guest PC 0x0c04f836 */
if(!s->budget--) { s->failed_pc=0x0c04f836u; return 0; }
r[6]=r[12];
goto P_0c04f838;
P_0c04f838: /* original b302, guest PC 0x0c04f838 */
if(!s->budget--) { s->failed_pc=0x0c04f838u; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04f83cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f83cu) { target=s->pc; goto dispatch; }
goto P_0c04f83c;
P_0c04f83a: /* original 64d3, guest PC 0x0c04f83a */
if(!s->budget--) { s->failed_pc=0x0c04f83au; return 0; }
r[4]=r[13];
goto P_0c04f83c;
P_0c04f83c: /* original 68e3, guest PC 0x0c04f83c */
if(!s->budget--) { s->failed_pc=0x0c04f83cu; return 0; }
r[8]=r[14];
goto P_0c04f83e;
P_0c04f83e: /* original afb0, guest PC 0x0c04f83e */
if(!s->budget--) { s->failed_pc=0x0c04f83eu; return 0; }
r[14]=r[12];
goto P_0c04f7a2;
P_0c04f840: /* original 6ec3, guest PC 0x0c04f840 */
if(!s->budget--) { s->failed_pc=0x0c04f840u; return 0; }
r[14]=r[12];
goto P_0c04f842;
P_0c04f842: /* original 65e3, guest PC 0x0c04f842 */
if(!s->budget--) { s->failed_pc=0x0c04f842u; return 0; }
r[5]=r[14];
goto P_0c04f844;
P_0c04f844: /* original b32b, guest PC 0x0c04f844 */
if(!s->budget--) { s->failed_pc=0x0c04f844u; return 0; }
target=0x0c04fe9eu; r[16]=code_base|0x0c04f848u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f848u) { target=s->pc; goto dispatch; }
goto P_0c04f848;
P_0c04f846: /* original 64d3, guest PC 0x0c04f846 */
if(!s->budget--) { s->failed_pc=0x0c04f846u; return 0; }
r[4]=r[13];
goto P_0c04f848;
P_0c04f848: /* original 68e3, guest PC 0x0c04f848 */
if(!s->budget--) { s->failed_pc=0x0c04f848u; return 0; }
r[8]=r[14];
goto P_0c04f84a;
P_0c04f84a: /* original 6b0d, guest PC 0x0c04f84a */
if(!s->budget--) { s->failed_pc=0x0c04f84au; return 0; }
r[11]=r[0]&65535u;
goto P_0c04f84c;
P_0c04f84c: /* original 6eb3, guest PC 0x0c04f84c */
if(!s->budget--) { s->failed_pc=0x0c04f84cu; return 0; }
r[14]=r[11];
goto P_0c04f84e;
P_0c04f84e: /* original 7a01, guest PC 0x0c04f84e */
if(!s->budget--) { s->failed_pc=0x0c04f84eu; return 0; }
r[10]+=0x00000001u;
goto P_0c04f850;
P_0c04f850: /* original 53f1, guest PC 0x0c04f850 */
if(!s->budget--) { s->failed_pc=0x0c04f850u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04f852;
P_0c04f852: /* original 3a33, guest PC 0x0c04f852 */
if(!s->budget--) { s->failed_pc=0x0c04f852u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c04f854;
P_0c04f854: /* original 8b9b, guest PC 0x0c04f854 */
if(!s->budget--) { s->failed_pc=0x0c04f854u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f78e; }
goto P_0c04f856;
P_0c04f856: /* original 51f2, guest PC 0x0c04f856 */
if(!s->budget--) { s->failed_pc=0x0c04f856u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c04f858;
P_0c04f858: /* original 2118, guest PC 0x0c04f858 */
if(!s->budget--) { s->failed_pc=0x0c04f858u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04f85a;
P_0c04f85a: /* original 890b, guest PC 0x0c04f85a */
if(!s->budget--) { s->failed_pc=0x0c04f85au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f874; }
goto P_0c04f85c;
P_0c04f85c: /* original b268, guest PC 0x0c04f85c */
if(!s->budget--) { s->failed_pc=0x0c04f85cu; return 0; }
target=0x0c04fd30u; r[16]=code_base|0x0c04f860u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f860u) { target=s->pc; goto dispatch; }
goto P_0c04f860;
P_0c04f85e: /* original 64d3, guest PC 0x0c04f85e */
if(!s->budget--) { s->failed_pc=0x0c04f85eu; return 0; }
r[4]=r[13];
goto P_0c04f860;
P_0c04f860: /* original 6403, guest PC 0x0c04f860 */
if(!s->budget--) { s->failed_pc=0x0c04f860u; return 0; }
r[4]=r[0];
goto P_0c04f862;
P_0c04f862: /* original 4411, guest PC 0x0c04f862 */
if(!s->budget--) { s->failed_pc=0x0c04f862u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04f864;
P_0c04f864: /* original 8b04, guest PC 0x0c04f864 */
if(!s->budget--) { s->failed_pc=0x0c04f864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f870; }
goto P_0c04f866;
P_0c04f866: /* original b149, guest PC 0x0c04f866 */
if(!s->budget--) { s->failed_pc=0x0c04f866u; return 0; }
target=0x0c04fafcu; r[16]=code_base|0x0c04f86au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f86au) { target=s->pc; goto dispatch; }
goto P_0c04f86a;
P_0c04f868: /* original 64d3, guest PC 0x0c04f868 */
if(!s->budget--) { s->failed_pc=0x0c04f868u; return 0; }
r[4]=r[13];
goto P_0c04f86a;
P_0c04f86a: /* original 6403, guest PC 0x0c04f86a */
if(!s->budget--) { s->failed_pc=0x0c04f86au; return 0; }
r[4]=r[0];
goto P_0c04f86c;
P_0c04f86c: /* original 4411, guest PC 0x0c04f86c */
if(!s->budget--) { s->failed_pc=0x0c04f86cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04f86e;
P_0c04f86e: /* original 8901, guest PC 0x0c04f86e */
if(!s->budget--) { s->failed_pc=0x0c04f86eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f874; }
goto P_0c04f870;
P_0c04f870: /* original a001, guest PC 0x0c04f870 */
if(!s->budget--) { s->failed_pc=0x0c04f870u; return 0; }
r[0]=r[4];
goto P_0c04f876;
P_0c04f872: /* original 6043, guest PC 0x0c04f872 */
if(!s->budget--) { s->failed_pc=0x0c04f872u; return 0; }
r[0]=r[4];
goto P_0c04f874;
P_0c04f874: /* original e000, guest PC 0x0c04f874 */
if(!s->budget--) { s->failed_pc=0x0c04f874u; return 0; }
r[0]=0x00000000u;
goto P_0c04f876;
P_0c04f876: /* original 7f0c, guest PC 0x0c04f876 */
if(!s->budget--) { s->failed_pc=0x0c04f876u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04f878;
P_0c04f878: /* original 4f16, guest PC 0x0c04f878 */
if(!s->budget--) { s->failed_pc=0x0c04f878u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f87a;
P_0c04f87a: /* original 4f26, guest PC 0x0c04f87a */
if(!s->budget--) { s->failed_pc=0x0c04f87au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f87c;
P_0c04f87c: /* original 68f6, guest PC 0x0c04f87c */
if(!s->budget--) { s->failed_pc=0x0c04f87cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04f87e;
P_0c04f87e: /* original 69f6, guest PC 0x0c04f87e */
if(!s->budget--) { s->failed_pc=0x0c04f87eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04f880;
P_0c04f880: /* original 6af6, guest PC 0x0c04f880 */
if(!s->budget--) { s->failed_pc=0x0c04f880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04f882;
P_0c04f882: /* original 6bf6, guest PC 0x0c04f882 */
if(!s->budget--) { s->failed_pc=0x0c04f882u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04f884;
P_0c04f884: /* original 6cf6, guest PC 0x0c04f884 */
if(!s->budget--) { s->failed_pc=0x0c04f884u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f886;
P_0c04f886: /* original 6df6, guest PC 0x0c04f886 */
if(!s->budget--) { s->failed_pc=0x0c04f886u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f888;
P_0c04f888: /* original 000b, guest PC 0x0c04f888 */
if(!s->budget--) { s->failed_pc=0x0c04f888u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f88a: /* original 6ef6, guest PC 0x0c04f88a */
if(!s->budget--) { s->failed_pc=0x0c04f88au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04f88cu,s,ram);
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
P_0c04fafc: /* original 2fe6, guest PC 0x0c04fafc */
if(!s->budget--) { s->failed_pc=0x0c04fafcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fafe;
P_0c04fafe: /* original 6e43, guest PC 0x0c04fafe */
if(!s->budget--) { s->failed_pc=0x0c04fafeu; return 0; }
r[14]=r[4];
goto P_0c04fb00;
P_0c04fb00: /* original 4f22, guest PC 0x0c04fb00 */
if(!s->budget--) { s->failed_pc=0x0c04fb00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fb02;
P_0c04fb02: /* original 4f12, guest PC 0x0c04fb02 */
if(!s->budget--) { s->failed_pc=0x0c04fb02u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fb04;
P_0c04fb04: /* original 7ffc, guest PC 0x0c04fb04 */
if(!s->budget--) { s->failed_pc=0x0c04fb04u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04fb06;
P_0c04fb06: /* original 2f42, guest PC 0x0c04fb06 */
if(!s->budget--) { s->failed_pc=0x0c04fb06u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04fb08;
P_0c04fb08: /* original 9356, guest PC 0x0c04fb08 */
if(!s->budget--) { s->failed_pc=0x0c04fb08u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fbb8u,2);
goto P_0c04fb0a;
P_0c04fb0a: /* original d22c, guest PC 0x0c04fb0a */
if(!s->budget--) { s->failed_pc=0x0c04fb0au; return 0; }
r[2]=read(ram,0x0c04fbbcu,4);
goto P_0c04fb0c;
P_0c04fb0c: /* original 2e3f, guest PC 0x0c04fb0c */
if(!s->budget--) { s->failed_pc=0x0c04fb0cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04fb0e;
P_0c04fb0e: /* original d32d, guest PC 0x0c04fb0e */
if(!s->budget--) { s->failed_pc=0x0c04fb0eu; return 0; }
r[3]=read(ram,0x0c04fbc4u,4);
goto P_0c04fb10;
P_0c04fb10: /* original d12b, guest PC 0x0c04fb10 */
if(!s->budget--) { s->failed_pc=0x0c04fb10u; return 0; }
r[1]=read(ram,0x0c04fbc0u,4);
goto P_0c04fb12;
P_0c04fb12: /* original 0e1a, guest PC 0x0c04fb12 */
if(!s->budget--) { s->failed_pc=0x0c04fb12u; return 0; }
r[14]=r[19];
goto P_0c04fb14;
P_0c04fb14: /* original 6eef, guest PC 0x0c04fb14 */
if(!s->budget--) { s->failed_pc=0x0c04fb14u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04fb16;
P_0c04fb16: /* original 3e2c, guest PC 0x0c04fb16 */
if(!s->budget--) { s->failed_pc=0x0c04fb16u; return 0; }
r[14]+=r[2];
goto P_0c04fb18;
P_0c04fb18: /* original 430b, guest PC 0x0c04fb18 */
if(!s->budget--) { s->failed_pc=0x0c04fb18u; return 0; }
target=r[3];
r[16]=code_base|0x0c04fb1cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fb1cu) { target=s->pc; goto dispatch; }
goto P_0c04fb1c;
P_0c04fb1a: /* original 2f16, guest PC 0x0c04fb1a */
if(!s->budget--) { s->failed_pc=0x0c04fb1au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fb1c;
P_0c04fb1c: /* original 54f1, guest PC 0x0c04fb1c */
if(!s->budget--) { s->failed_pc=0x0c04fb1cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04fb1e;
P_0c04fb1e: /* original 7f08, guest PC 0x0c04fb1e */
if(!s->budget--) { s->failed_pc=0x0c04fb1eu; return 0; }
r[15]+=0x00000008u;
goto P_0c04fb20;
P_0c04fb20: /* original 4f16, guest PC 0x0c04fb20 */
if(!s->budget--) { s->failed_pc=0x0c04fb20u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fb22;
P_0c04fb22: /* original 55e7, guest PC 0x0c04fb22 */
if(!s->budget--) { s->failed_pc=0x0c04fb22u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04fb24;
P_0c04fb24: /* original d328, guest PC 0x0c04fb24 */
if(!s->budget--) { s->failed_pc=0x0c04fb24u; return 0; }
r[3]=read(ram,0x0c04fbc8u,4);
goto P_0c04fb26;
P_0c04fb26: /* original 4f26, guest PC 0x0c04fb26 */
if(!s->budget--) { s->failed_pc=0x0c04fb26u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fb28;
P_0c04fb28: /* original 56e8, guest PC 0x0c04fb28 */
if(!s->budget--) { s->failed_pc=0x0c04fb28u; return 0; }
r[6]=read(ram,r[14]+32,4);
goto P_0c04fb2a;
P_0c04fb2a: /* original 5552, guest PC 0x0c04fb2a */
if(!s->budget--) { s->failed_pc=0x0c04fb2au; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04fb2c;
P_0c04fb2c: /* original 432b, guest PC 0x0c04fb2c */
if(!s->budget--) { s->failed_pc=0x0c04fb2cu; return 0; }
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
P_0c04fb2e: /* original 6ef6, guest PC 0x0c04fb2e */
if(!s->budget--) { s->failed_pc=0x0c04fb2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04fb30u,s,ram);
P_0c04fd30: /* original 2fe6, guest PC 0x0c04fd30 */
if(!s->budget--) { s->failed_pc=0x0c04fd30u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd32;
P_0c04fd32: /* original 2fd6, guest PC 0x0c04fd32 */
if(!s->budget--) { s->failed_pc=0x0c04fd32u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd34;
P_0c04fd34: /* original 2fc6, guest PC 0x0c04fd34 */
if(!s->budget--) { s->failed_pc=0x0c04fd34u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd36;
P_0c04fd36: /* original 6c43, guest PC 0x0c04fd36 */
if(!s->budget--) { s->failed_pc=0x0c04fd36u; return 0; }
r[12]=r[4];
goto P_0c04fd38;
P_0c04fd38: /* original 2fb6, guest PC 0x0c04fd38 */
if(!s->budget--) { s->failed_pc=0x0c04fd38u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd3a;
P_0c04fd3a: /* original 2fa6, guest PC 0x0c04fd3a */
if(!s->budget--) { s->failed_pc=0x0c04fd3au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd3c;
P_0c04fd3c: /* original ea00, guest PC 0x0c04fd3c */
if(!s->budget--) { s->failed_pc=0x0c04fd3cu; return 0; }
r[10]=0x00000000u;
goto P_0c04fd3e;
P_0c04fd3e: /* original 2f96, guest PC 0x0c04fd3e */
if(!s->budget--) { s->failed_pc=0x0c04fd3eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd40;
P_0c04fd40: /* original e901, guest PC 0x0c04fd40 */
if(!s->budget--) { s->failed_pc=0x0c04fd40u; return 0; }
r[9]=0x00000001u;
goto P_0c04fd42;
P_0c04fd42: /* original 2f86, guest PC 0x0c04fd42 */
if(!s->budget--) { s->failed_pc=0x0c04fd42u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd44;
P_0c04fd44: /* original 6da3, guest PC 0x0c04fd44 */
if(!s->budget--) { s->failed_pc=0x0c04fd44u; return 0; }
r[13]=r[10];
goto P_0c04fd46;
P_0c04fd46: /* original 4f22, guest PC 0x0c04fd46 */
if(!s->budget--) { s->failed_pc=0x0c04fd46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fd48;
P_0c04fd48: /* original 9e45, guest PC 0x0c04fd48 */
if(!s->budget--) { s->failed_pc=0x0c04fd48u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fdd6u,2);
goto P_0c04fd4a;
P_0c04fd4a: /* original d324, guest PC 0x0c04fd4a */
if(!s->budget--) { s->failed_pc=0x0c04fd4au; return 0; }
r[3]=read(ram,0x0c04fddcu,4);
goto P_0c04fd4c;
P_0c04fd4c: /* original 4f12, guest PC 0x0c04fd4c */
if(!s->budget--) { s->failed_pc=0x0c04fd4cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fd4e;
P_0c04fd4e: /* original 2cef, guest PC 0x0c04fd4e */
if(!s->budget--) { s->failed_pc=0x0c04fd4eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[14]);
goto P_0c04fd50;
P_0c04fd50: /* original d823, guest PC 0x0c04fd50 */
if(!s->budget--) { s->failed_pc=0x0c04fd50u; return 0; }
r[8]=read(ram,0x0c04fde0u,4);
goto P_0c04fd52;
P_0c04fd52: /* original db24, guest PC 0x0c04fd52 */
if(!s->budget--) { s->failed_pc=0x0c04fd52u; return 0; }
r[11]=read(ram,0x0c04fde4u,4);
goto P_0c04fd54;
P_0c04fd54: /* original 0e1a, guest PC 0x0c04fd54 */
if(!s->budget--) { s->failed_pc=0x0c04fd54u; return 0; }
r[14]=r[19];
goto P_0c04fd56;
P_0c04fd56: /* original 6eef, guest PC 0x0c04fd56 */
if(!s->budget--) { s->failed_pc=0x0c04fd56u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04fd58;
P_0c04fd58: /* original 3e3c, guest PC 0x0c04fd58 */
if(!s->budget--) { s->failed_pc=0x0c04fd58u; return 0; }
r[14]+=r[3];
goto P_0c04fd5a;
P_0c04fd5a: /* original bf3f, guest PC 0x0c04fd5a */
if(!s->budget--) { s->failed_pc=0x0c04fd5au; return 0; }
target=0x0c04fbdcu; r[16]=code_base|0x0c04fd5eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fd5eu) { target=s->pc; goto dispatch; }
goto P_0c04fd5e;
P_0c04fd5c: /* original 64c3, guest PC 0x0c04fd5c */
if(!s->budget--) { s->failed_pc=0x0c04fd5cu; return 0; }
r[4]=r[12];
goto P_0c04fd5e;
P_0c04fd5e: /* original 913b, guest PC 0x0c04fd5e */
if(!s->budget--) { s->failed_pc=0x0c04fd5eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fdd8u,2);
goto P_0c04fd60;
P_0c04fd60: /* original 3010, guest PC 0x0c04fd60 */
if(!s->budget--) { s->failed_pc=0x0c04fd60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04fd62;
P_0c04fd62: /* original 8d07, guest PC 0x0c04fd62 */
if(!s->budget--) { s->failed_pc=0x0c04fd62u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04fd74; }
goto P_0c04fd66;
P_0c04fd64: /* original 6403, guest PC 0x0c04fd64 */
if(!s->budget--) { s->failed_pc=0x0c04fd64u; return 0; }
r[4]=r[0];
goto P_0c04fd66;
P_0c04fd66: /* original 9138, guest PC 0x0c04fd66 */
if(!s->budget--) { s->failed_pc=0x0c04fd66u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fddau,2);
goto P_0c04fd68;
P_0c04fd68: /* original 3010, guest PC 0x0c04fd68 */
if(!s->budget--) { s->failed_pc=0x0c04fd68u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04fd6a;
P_0c04fd6a: /* original 8906, guest PC 0x0c04fd6a */
if(!s->budget--) { s->failed_pc=0x0c04fd6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fd7a; }
goto P_0c04fd6c;
P_0c04fd6c: /* original 8800, guest PC 0x0c04fd6c */
if(!s->budget--) { s->failed_pc=0x0c04fd6cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04fd6e;
P_0c04fd6e: /* original 8923, guest PC 0x0c04fd6e */
if(!s->budget--) { s->failed_pc=0x0c04fd6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fdb8; }
goto P_0c04fd70;
P_0c04fd70: /* original a022, guest PC 0x0c04fd70 */
if(!s->budget--) { s->failed_pc=0x0c04fd70u; return 0; }
goto P_0c04fdb8;
P_0c04fd72: /* original 0009, guest PC 0x0c04fd72 */
if(!s->budget--) { s->failed_pc=0x0c04fd72u; return 0; }
goto P_0c04fd74;
P_0c04fd74: /* original 9030, guest PC 0x0c04fd74 */
if(!s->budget--) { s->failed_pc=0x0c04fd74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fdd8u,2);
goto P_0c04fd76;
P_0c04fd76: /* original a024, guest PC 0x0c04fd76 */
if(!s->budget--) { s->failed_pc=0x0c04fd76u; return 0; }
goto P_0c04fdc2;
P_0c04fd78: /* original 0009, guest PC 0x0c04fd78 */
if(!s->budget--) { s->failed_pc=0x0c04fd78u; return 0; }
goto P_0c04fd7a;
P_0c04fd7a: /* original bf84, guest PC 0x0c04fd7a */
if(!s->budget--) { s->failed_pc=0x0c04fd7au; return 0; }
target=0x0c04fc86u; r[16]=code_base|0x0c04fd7eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fd7eu) { target=s->pc; goto dispatch; }
goto P_0c04fd7e;
P_0c04fd7c: /* original 64c3, guest PC 0x0c04fd7c */
if(!s->budget--) { s->failed_pc=0x0c04fd7cu; return 0; }
r[4]=r[12];
goto P_0c04fd7e;
P_0c04fd7e: /* original 6d03, guest PC 0x0c04fd7e */
if(!s->budget--) { s->failed_pc=0x0c04fd7eu; return 0; }
r[13]=r[0];
goto P_0c04fd80;
P_0c04fd80: /* original 4d11, guest PC 0x0c04fd80 */
if(!s->budget--) { s->failed_pc=0x0c04fd80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c04fd82;
P_0c04fd82: /* original 8902, guest PC 0x0c04fd82 */
if(!s->budget--) { s->failed_pc=0x0c04fd82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fd8a; }
goto P_0c04fd84;
P_0c04fd84: /* original 9029, guest PC 0x0c04fd84 */
if(!s->budget--) { s->failed_pc=0x0c04fd84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fddau,2);
goto P_0c04fd86;
P_0c04fd86: /* original a01c, guest PC 0x0c04fd86 */
if(!s->budget--) { s->failed_pc=0x0c04fd86u; return 0; }
goto P_0c04fdc2;
P_0c04fd88: /* original 0009, guest PC 0x0c04fd88 */
if(!s->budget--) { s->failed_pc=0x0c04fd88u; return 0; }
goto P_0c04fd8a;
P_0c04fd8a: /* original 52e7, guest PC 0x0c04fd8a */
if(!s->budget--) { s->failed_pc=0x0c04fd8au; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04fd8c;
P_0c04fd8c: /* original e546, guest PC 0x0c04fd8c */
if(!s->budget--) { s->failed_pc=0x0c04fd8cu; return 0; }
r[5]=0x00000046u;
goto P_0c04fd8e;
P_0c04fd8e: /* original 66d3, guest PC 0x0c04fd8e */
if(!s->budget--) { s->failed_pc=0x0c04fd8eu; return 0; }
r[6]=r[13];
goto P_0c04fd90;
P_0c04fd90: /* original 12d3, guest PC 0x0c04fd90 */
if(!s->budget--) { s->failed_pc=0x0c04fd90u; return 0; }
write(ram,r[2]+12,r[13],4);
goto P_0c04fd92;
P_0c04fd92: /* original 6382, guest PC 0x0c04fd92 */
if(!s->budget--) { s->failed_pc=0x0c04fd92u; return 0; }
tmp=read(ram,r[8],4);
r[3]=tmp;
goto P_0c04fd94;
P_0c04fd94: /* original 5234, guest PC 0x0c04fd94 */
if(!s->budget--) { s->failed_pc=0x0c04fd94u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04fd96;
P_0c04fd96: /* original 420b, guest PC 0x0c04fd96 */
if(!s->budget--) { s->failed_pc=0x0c04fd96u; return 0; }
target=r[2];
r[16]=code_base|0x0c04fd9au;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fd9au) { target=s->pc; goto dispatch; }
goto P_0c04fd9a;
P_0c04fd98: /* original 54e8, guest PC 0x0c04fd98 */
if(!s->budget--) { s->failed_pc=0x0c04fd98u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04fd9a;
P_0c04fd9a: /* original a007, guest PC 0x0c04fd9a */
if(!s->budget--) { s->failed_pc=0x0c04fd9au; return 0; }
r[13]=r[10];
goto P_0c04fdac;
P_0c04fd9c: /* original 6da3, guest PC 0x0c04fd9c */
if(!s->budget--) { s->failed_pc=0x0c04fd9cu; return 0; }
r[13]=r[10];
goto P_0c04fd9e;
P_0c04fd9e: /* original 55e7, guest PC 0x0c04fd9e */
if(!s->budget--) { s->failed_pc=0x0c04fd9eu; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04fda0;
P_0c04fda0: /* original 66b3, guest PC 0x0c04fda0 */
if(!s->budget--) { s->failed_pc=0x0c04fda0u; return 0; }
r[6]=r[11];
goto P_0c04fda2;
P_0c04fda2: /* original 5553, guest PC 0x0c04fda2 */
if(!s->budget--) { s->failed_pc=0x0c04fda2u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04fda4;
P_0c04fda4: /* original 35dc, guest PC 0x0c04fda4 */
if(!s->budget--) { s->failed_pc=0x0c04fda4u; return 0; }
r[5]+=r[13];
goto P_0c04fda6;
P_0c04fda6: /* original b04b, guest PC 0x0c04fda6 */
if(!s->budget--) { s->failed_pc=0x0c04fda6u; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04fdaau;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fdaau) { target=s->pc; goto dispatch; }
goto P_0c04fdaa;
P_0c04fda8: /* original 64c3, guest PC 0x0c04fda8 */
if(!s->budget--) { s->failed_pc=0x0c04fda8u; return 0; }
r[4]=r[12];
goto P_0c04fdaa;
P_0c04fdaa: /* original 7d01, guest PC 0x0c04fdaa */
if(!s->budget--) { s->failed_pc=0x0c04fdaau; return 0; }
r[13]+=0x00000001u;
goto P_0c04fdac;
P_0c04fdac: /* original 52e7, guest PC 0x0c04fdac */
if(!s->budget--) { s->failed_pc=0x0c04fdacu; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04fdae;
P_0c04fdae: /* original 5324, guest PC 0x0c04fdae */
if(!s->budget--) { s->failed_pc=0x0c04fdaeu; return 0; }
r[3]=read(ram,r[2]+16,4);
goto P_0c04fdb0;
P_0c04fdb0: /* original 3d33, guest PC 0x0c04fdb0 */
if(!s->budget--) { s->failed_pc=0x0c04fdb0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c04fdb2;
P_0c04fdb2: /* original 8bf4, guest PC 0x0c04fdb2 */
if(!s->budget--) { s->failed_pc=0x0c04fdb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fd9e; }
goto P_0c04fdb4;
P_0c04fdb4: /* original afd1, guest PC 0x0c04fdb4 */
if(!s->budget--) { s->failed_pc=0x0c04fdb4u; return 0; }
r[13]=r[9];
goto P_0c04fd5a;
P_0c04fdb6: /* original 6d93, guest PC 0x0c04fdb6 */
if(!s->budget--) { s->failed_pc=0x0c04fdb6u; return 0; }
r[13]=r[9];
goto P_0c04fdb8;
P_0c04fdb8: /* original 2dd8, guest PC 0x0c04fdb8 */
if(!s->budget--) { s->failed_pc=0x0c04fdb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c04fdba;
P_0c04fdba: /* original 8901, guest PC 0x0c04fdba */
if(!s->budget--) { s->failed_pc=0x0c04fdbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fdc0; }
goto P_0c04fdbc;
P_0c04fdbc: /* original be9e, guest PC 0x0c04fdbc */
if(!s->budget--) { s->failed_pc=0x0c04fdbcu; return 0; }
target=0x0c04fafcu; r[16]=code_base|0x0c04fdc0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fdc0u) { target=s->pc; goto dispatch; }
goto P_0c04fdc0;
P_0c04fdbe: /* original 64c3, guest PC 0x0c04fdbe */
if(!s->budget--) { s->failed_pc=0x0c04fdbeu; return 0; }
r[4]=r[12];
goto P_0c04fdc0;
P_0c04fdc0: /* original e000, guest PC 0x0c04fdc0 */
if(!s->budget--) { s->failed_pc=0x0c04fdc0u; return 0; }
r[0]=0x00000000u;
goto P_0c04fdc2;
P_0c04fdc2: /* original 4f16, guest PC 0x0c04fdc2 */
if(!s->budget--) { s->failed_pc=0x0c04fdc2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fdc4;
P_0c04fdc4: /* original 4f26, guest PC 0x0c04fdc4 */
if(!s->budget--) { s->failed_pc=0x0c04fdc4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fdc6;
P_0c04fdc6: /* original 68f6, guest PC 0x0c04fdc6 */
if(!s->budget--) { s->failed_pc=0x0c04fdc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04fdc8;
P_0c04fdc8: /* original 69f6, guest PC 0x0c04fdc8 */
if(!s->budget--) { s->failed_pc=0x0c04fdc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04fdca;
P_0c04fdca: /* original 6af6, guest PC 0x0c04fdca */
if(!s->budget--) { s->failed_pc=0x0c04fdcau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fdcc;
P_0c04fdcc: /* original 6bf6, guest PC 0x0c04fdcc */
if(!s->budget--) { s->failed_pc=0x0c04fdccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fdce;
P_0c04fdce: /* original 6cf6, guest PC 0x0c04fdce */
if(!s->budget--) { s->failed_pc=0x0c04fdceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fdd0;
P_0c04fdd0: /* original 6df6, guest PC 0x0c04fdd0 */
if(!s->budget--) { s->failed_pc=0x0c04fdd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fdd2;
P_0c04fdd2: /* original 000b, guest PC 0x0c04fdd2 */
if(!s->budget--) { s->failed_pc=0x0c04fdd2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fdd4: /* original 6ef6, guest PC 0x0c04fdd4 */
if(!s->budget--) { s->failed_pc=0x0c04fdd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04fdd6u,s,ram);
P_0c04fe40: /* original 2fe6, guest PC 0x0c04fe40 */
if(!s->budget--) { s->failed_pc=0x0c04fe40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe42;
P_0c04fe42: /* original 2fd6, guest PC 0x0c04fe42 */
if(!s->budget--) { s->failed_pc=0x0c04fe42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe44;
P_0c04fe44: /* original 6d53, guest PC 0x0c04fe44 */
if(!s->budget--) { s->failed_pc=0x0c04fe44u; return 0; }
r[13]=r[5];
goto P_0c04fe46;
P_0c04fe46: /* original 4f22, guest PC 0x0c04fe46 */
if(!s->budget--) { s->failed_pc=0x0c04fe46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fe48;
P_0c04fe48: /* original 4f12, guest PC 0x0c04fe48 */
if(!s->budget--) { s->failed_pc=0x0c04fe48u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fe4a;
P_0c04fe4a: /* original 7ffc, guest PC 0x0c04fe4a */
if(!s->budget--) { s->failed_pc=0x0c04fe4au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04fe4c;
P_0c04fe4c: /* original 2f61, guest PC 0x0c04fe4c */
if(!s->budget--) { s->failed_pc=0x0c04fe4cu; return 0; }
write(ram,r[15],r[6],2);
goto P_0c04fe4e;
P_0c04fe4e: /* original 9e39, guest PC 0x0c04fe4e */
if(!s->budget--) { s->failed_pc=0x0c04fe4eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fec4u,2);
goto P_0c04fe50;
P_0c04fe50: /* original d31d, guest PC 0x0c04fe50 */
if(!s->budget--) { s->failed_pc=0x0c04fe50u; return 0; }
r[3]=read(ram,0x0c04fec8u,4);
goto P_0c04fe52;
P_0c04fe52: /* original 24ef, guest PC 0x0c04fe52 */
if(!s->budget--) { s->failed_pc=0x0c04fe52u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c04fe54;
P_0c04fe54: /* original 0e1a, guest PC 0x0c04fe54 */
if(!s->budget--) { s->failed_pc=0x0c04fe54u; return 0; }
r[14]=r[19];
goto P_0c04fe56;
P_0c04fe56: /* original 6eef, guest PC 0x0c04fe56 */
if(!s->budget--) { s->failed_pc=0x0c04fe56u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04fe58;
P_0c04fe58: /* original 3e3c, guest PC 0x0c04fe58 */
if(!s->budget--) { s->failed_pc=0x0c04fe58u; return 0; }
r[14]+=r[3];
goto P_0c04fe5a;
P_0c04fe5a: /* original 52e7, guest PC 0x0c04fe5a */
if(!s->budget--) { s->failed_pc=0x0c04fe5au; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04fe5c;
P_0c04fe5c: /* original 6122, guest PC 0x0c04fe5c */
if(!s->budget--) { s->failed_pc=0x0c04fe5cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c04fe5e;
P_0c04fe5e: /* original 3d17, guest PC 0x0c04fe5e */
if(!s->budget--) { s->failed_pc=0x0c04fe5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[1])!=0);
goto P_0c04fe60;
P_0c04fe60: /* original 8b0a, guest PC 0x0c04fe60 */
if(!s->budget--) { s->failed_pc=0x0c04fe60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fe78; }
goto P_0c04fe62;
P_0c04fe62: /* original 60f1, guest PC 0x0c04fe62 */
if(!s->budget--) { s->failed_pc=0x0c04fe62u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c04fe64;
P_0c04fe64: /* original 600d, guest PC 0x0c04fe64 */
if(!s->budget--) { s->failed_pc=0x0c04fe64u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04fe66;
P_0c04fe66: /* original 2f06, guest PC 0x0c04fe66 */
if(!s->budget--) { s->failed_pc=0x0c04fe66u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe68;
P_0c04fe68: /* original 2fd6, guest PC 0x0c04fe68 */
if(!s->budget--) { s->failed_pc=0x0c04fe68u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe6a;
P_0c04fe6a: /* original 2f46, guest PC 0x0c04fe6a */
if(!s->budget--) { s->failed_pc=0x0c04fe6au; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe6c;
P_0c04fe6c: /* original d218, guest PC 0x0c04fe6c */
if(!s->budget--) { s->failed_pc=0x0c04fe6cu; return 0; }
r[2]=read(ram,0x0c04fed0u,4);
goto P_0c04fe6e;
P_0c04fe6e: /* original d119, guest PC 0x0c04fe6e */
if(!s->budget--) { s->failed_pc=0x0c04fe6eu; return 0; }
r[1]=read(ram,0x0c04fed4u,4);
goto P_0c04fe70;
P_0c04fe70: /* original 410b, guest PC 0x0c04fe70 */
if(!s->budget--) { s->failed_pc=0x0c04fe70u; return 0; }
target=r[1];
r[16]=code_base|0x0c04fe74u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fe74u) { target=s->pc; goto dispatch; }
goto P_0c04fe74;
P_0c04fe72: /* original 2f26, guest PC 0x0c04fe72 */
if(!s->budget--) { s->failed_pc=0x0c04fe72u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe74;
P_0c04fe74: /* original a00d, guest PC 0x0c04fe74 */
if(!s->budget--) { s->failed_pc=0x0c04fe74u; return 0; }
r[15]+=0x00000010u;
goto P_0c04fe92;
P_0c04fe76: /* original 7f10, guest PC 0x0c04fe76 */
if(!s->budget--) { s->failed_pc=0x0c04fe76u; return 0; }
r[15]+=0x00000010u;
goto P_0c04fe78;
P_0c04fe78: /* original 66f1, guest PC 0x0c04fe78 */
if(!s->budget--) { s->failed_pc=0x0c04fe78u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c04fe7a;
P_0c04fe7a: /* original 7f04, guest PC 0x0c04fe7a */
if(!s->budget--) { s->failed_pc=0x0c04fe7au; return 0; }
r[15]+=0x00000004u;
goto P_0c04fe7c;
P_0c04fe7c: /* original 4f16, guest PC 0x0c04fe7c */
if(!s->budget--) { s->failed_pc=0x0c04fe7cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe7e;
P_0c04fe7e: /* original d113, guest PC 0x0c04fe7e */
if(!s->budget--) { s->failed_pc=0x0c04fe7eu; return 0; }
r[1]=read(ram,0x0c04feccu,4);
goto P_0c04fe80;
P_0c04fe80: /* original 65d3, guest PC 0x0c04fe80 */
if(!s->budget--) { s->failed_pc=0x0c04fe80u; return 0; }
r[5]=r[13];
goto P_0c04fe82;
P_0c04fe82: /* original 54e9, guest PC 0x0c04fe82 */
if(!s->budget--) { s->failed_pc=0x0c04fe82u; return 0; }
r[4]=read(ram,r[14]+36,4);
goto P_0c04fe84;
P_0c04fe84: /* original 4500, guest PC 0x0c04fe84 */
if(!s->budget--) { s->failed_pc=0x0c04fe84u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04fe86;
P_0c04fe86: /* original 4f26, guest PC 0x0c04fe86 */
if(!s->budget--) { s->failed_pc=0x0c04fe86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe88;
P_0c04fe88: /* original 6312, guest PC 0x0c04fe88 */
if(!s->budget--) { s->failed_pc=0x0c04fe88u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c04fe8a;
P_0c04fe8a: /* original 5234, guest PC 0x0c04fe8a */
if(!s->budget--) { s->failed_pc=0x0c04fe8au; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04fe8c;
P_0c04fe8c: /* original 6df6, guest PC 0x0c04fe8c */
if(!s->budget--) { s->failed_pc=0x0c04fe8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fe8e;
P_0c04fe8e: /* original 422b, guest PC 0x0c04fe8e */
if(!s->budget--) { s->failed_pc=0x0c04fe8eu; return 0; }
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
P_0c04fe90: /* original 6ef6, guest PC 0x0c04fe90 */
if(!s->budget--) { s->failed_pc=0x0c04fe90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fe92;
P_0c04fe92: /* original 7f04, guest PC 0x0c04fe92 */
if(!s->budget--) { s->failed_pc=0x0c04fe92u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fe94;
P_0c04fe94: /* original 4f16, guest PC 0x0c04fe94 */
if(!s->budget--) { s->failed_pc=0x0c04fe94u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe96;
P_0c04fe96: /* original 4f26, guest PC 0x0c04fe96 */
if(!s->budget--) { s->failed_pc=0x0c04fe96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe98;
P_0c04fe98: /* original 6df6, guest PC 0x0c04fe98 */
if(!s->budget--) { s->failed_pc=0x0c04fe98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fe9a;
P_0c04fe9a: /* original 000b, guest PC 0x0c04fe9a */
if(!s->budget--) { s->failed_pc=0x0c04fe9au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fe9c: /* original 6ef6, guest PC 0x0c04fe9c */
if(!s->budget--) { s->failed_pc=0x0c04fe9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fe9e;
P_0c04fe9e: /* original 4f12, guest PC 0x0c04fe9e */
if(!s->budget--) { s->failed_pc=0x0c04fe9eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fea0;
P_0c04fea0: /* original 7ff8, guest PC 0x0c04fea0 */
if(!s->budget--) { s->failed_pc=0x0c04fea0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04fea2;
P_0c04fea2: /* original 2f52, guest PC 0x0c04fea2 */
if(!s->budget--) { s->failed_pc=0x0c04fea2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04fea4;
P_0c04fea4: /* original 930e, guest PC 0x0c04fea4 */
if(!s->budget--) { s->failed_pc=0x0c04fea4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fec4u,2);
goto P_0c04fea6;
P_0c04fea6: /* original d208, guest PC 0x0c04fea6 */
if(!s->budget--) { s->failed_pc=0x0c04fea6u; return 0; }
r[2]=read(ram,0x0c04fec8u,4);
goto P_0c04fea8;
P_0c04fea8: /* original 243f, guest PC 0x0c04fea8 */
if(!s->budget--) { s->failed_pc=0x0c04fea8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04feaa;
P_0c04feaa: /* original 041a, guest PC 0x0c04feaa */
if(!s->budget--) { s->failed_pc=0x0c04feaau; return 0; }
r[4]=r[19];
goto P_0c04feac;
P_0c04feac: /* original 644f, guest PC 0x0c04feac */
if(!s->budget--) { s->failed_pc=0x0c04feacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04feae;
P_0c04feae: /* original 342c, guest PC 0x0c04feae */
if(!s->budget--) { s->failed_pc=0x0c04feaeu; return 0; }
r[4]+=r[2];
goto P_0c04feb0;
P_0c04feb0: /* original 1f41, guest PC 0x0c04feb0 */
if(!s->budget--) { s->failed_pc=0x0c04feb0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c04feb2;
P_0c04feb2: /* original d106, guest PC 0x0c04feb2 */
if(!s->budget--) { s->failed_pc=0x0c04feb2u; return 0; }
r[1]=read(ram,0x0c04feccu,4);
goto P_0c04feb4;
P_0c04feb4: /* original 65f2, guest PC 0x0c04feb4 */
if(!s->budget--) { s->failed_pc=0x0c04feb4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04feb6;
P_0c04feb6: /* original 7f08, guest PC 0x0c04feb6 */
if(!s->budget--) { s->failed_pc=0x0c04feb6u; return 0; }
r[15]+=0x00000008u;
goto P_0c04feb8;
P_0c04feb8: /* original 6012, guest PC 0x0c04feb8 */
if(!s->budget--) { s->failed_pc=0x0c04feb8u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c04feba;
P_0c04feba: /* original 5449, guest PC 0x0c04feba */
if(!s->budget--) { s->failed_pc=0x0c04febau; return 0; }
r[4]=read(ram,r[4]+36,4);
goto P_0c04febc;
P_0c04febc: /* original 4500, guest PC 0x0c04febc */
if(!s->budget--) { s->failed_pc=0x0c04febcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04febe;
P_0c04febe: /* original 5003, guest PC 0x0c04febe */
if(!s->budget--) { s->failed_pc=0x0c04febeu; return 0; }
r[0]=read(ram,r[0]+12,4);
goto P_0c04fec0;
P_0c04fec0: /* original 402b, guest PC 0x0c04fec0 */
if(!s->budget--) { s->failed_pc=0x0c04fec0u; return 0; }
target=r[0];
r[19]=read(ram,r[15],4); r[15]+=4;
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
P_0c04fec2: /* original 4f16, guest PC 0x0c04fec2 */
if(!s->budget--) { s->failed_pc=0x0c04fec2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c04fec4u,s,ram);
P_0c04ff80: /* original 932b, guest PC 0x0c04ff80 */
if(!s->budget--) { s->failed_pc=0x0c04ff80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdau,2);
goto P_0c04ff82;
P_0c04ff82: /* original e1fc, guest PC 0x0c04ff82 */
if(!s->budget--) { s->failed_pc=0x0c04ff82u; return 0; }
r[1]=0xfffffffcu;
goto P_0c04ff84;
P_0c04ff84: /* original 4f12, guest PC 0x0c04ff84 */
if(!s->budget--) { s->failed_pc=0x0c04ff84u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ff86;
P_0c04ff86: /* original 243f, guest PC 0x0c04ff86 */
if(!s->budget--) { s->failed_pc=0x0c04ff86u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04ff88;
P_0c04ff88: /* original d215, guest PC 0x0c04ff88 */
if(!s->budget--) { s->failed_pc=0x0c04ff88u; return 0; }
r[2]=read(ram,0x0c04ffe0u,4);
goto P_0c04ff8a;
P_0c04ff8a: /* original 451c, guest PC 0x0c04ff8a */
if(!s->budget--) { s->failed_pc=0x0c04ff8au; return 0; }
r[5]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[5]>>((-r[1])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[1]&31u);
goto P_0c04ff8c;
P_0c04ff8c: /* original e101, guest PC 0x0c04ff8c */
if(!s->budget--) { s->failed_pc=0x0c04ff8cu; return 0; }
r[1]=0x00000001u;
goto P_0c04ff8e;
P_0c04ff8e: /* original 041a, guest PC 0x0c04ff8e */
if(!s->budget--) { s->failed_pc=0x0c04ff8eu; return 0; }
r[4]=r[19];
goto P_0c04ff90;
P_0c04ff90: /* original 644f, guest PC 0x0c04ff90 */
if(!s->budget--) { s->failed_pc=0x0c04ff90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04ff92;
P_0c04ff92: /* original 342c, guest PC 0x0c04ff92 */
if(!s->budget--) { s->failed_pc=0x0c04ff92u; return 0; }
r[4]+=r[2];
goto P_0c04ff94;
P_0c04ff94: /* original 6043, guest PC 0x0c04ff94 */
if(!s->budget--) { s->failed_pc=0x0c04ff94u; return 0; }
r[0]=r[4];
goto P_0c04ff96;
P_0c04ff96: /* original 7048, guest PC 0x0c04ff96 */
if(!s->budget--) { s->failed_pc=0x0c04ff96u; return 0; }
r[0]+=0x00000048u;
goto P_0c04ff98;
P_0c04ff98: /* original 350c, guest PC 0x0c04ff98 */
if(!s->budget--) { s->failed_pc=0x0c04ff98u; return 0; }
r[5]+=r[0];
goto P_0c04ff9a;
P_0c04ff9a: /* original 2510, guest PC 0x0c04ff9a */
if(!s->budget--) { s->failed_pc=0x0c04ff9au; return 0; }
write(ram,r[5],r[1],1);
goto P_0c04ff9c;
P_0c04ff9c: /* original 000b, guest PC 0x0c04ff9c */
if(!s->budget--) { s->failed_pc=0x0c04ff9cu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04ff9e: /* original 4f16, guest PC 0x0c04ff9e */
if(!s->budget--) { s->failed_pc=0x0c04ff9eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c04ffa0u,s,ram);
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
P_0c068c58: /* original 2fe6, guest PC 0x0c068c58 */
if(!s->budget--) { s->failed_pc=0x0c068c58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5a;
P_0c068c5a: /* original 2fd6, guest PC 0x0c068c5a */
if(!s->budget--) { s->failed_pc=0x0c068c5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5c;
P_0c068c5c: /* original 2fc6, guest PC 0x0c068c5c */
if(!s->budget--) { s->failed_pc=0x0c068c5cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5e;
P_0c068c5e: /* original ec0f, guest PC 0x0c068c5e */
if(!s->budget--) { s->failed_pc=0x0c068c5eu; return 0; }
r[12]=0x0000000fu;
goto P_0c068c60;
P_0c068c60: /* original 2fb6, guest PC 0x0c068c60 */
if(!s->budget--) { s->failed_pc=0x0c068c60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c62;
P_0c068c62: /* original 2fa6, guest PC 0x0c068c62 */
if(!s->budget--) { s->failed_pc=0x0c068c62u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c64;
P_0c068c64: /* original 2f96, guest PC 0x0c068c64 */
if(!s->budget--) { s->failed_pc=0x0c068c64u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c66;
P_0c068c66: /* original 2f86, guest PC 0x0c068c66 */
if(!s->budget--) { s->failed_pc=0x0c068c66u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c68;
P_0c068c68: /* original d92b, guest PC 0x0c068c68 */
if(!s->budget--) { s->failed_pc=0x0c068c68u; return 0; }
r[9]=read(ram,0x0c068d18u,4);
goto P_0c068c6a;
P_0c068c6a: /* original d833, guest PC 0x0c068c6a */
if(!s->budget--) { s->failed_pc=0x0c068c6au; return 0; }
r[8]=read(ram,0x0c068d38u,4);
goto P_0c068c6c;
P_0c068c6c: /* original 6393, guest PC 0x0c068c6c */
if(!s->budget--) { s->failed_pc=0x0c068c6cu; return 0; }
r[3]=r[9];
goto P_0c068c6e;
P_0c068c6e: /* original 731c, guest PC 0x0c068c6e */
if(!s->budget--) { s->failed_pc=0x0c068c6eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c068c70;
P_0c068c70: /* original 6030, guest PC 0x0c068c70 */
if(!s->budget--) { s->failed_pc=0x0c068c70u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c068c72;
P_0c068c72: /* original 4f22, guest PC 0x0c068c72 */
if(!s->budget--) { s->failed_pc=0x0c068c72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068c74;
P_0c068c74: /* original 600c, guest PC 0x0c068c74 */
if(!s->budget--) { s->failed_pc=0x0c068c74u; return 0; }
r[0]=r[0]&255u;
goto P_0c068c76;
P_0c068c76: /* original da31, guest PC 0x0c068c76 */
if(!s->budget--) { s->failed_pc=0x0c068c76u; return 0; }
r[10]=read(ram,0x0c068d3cu,4);
goto P_0c068c78;
P_0c068c78: /* original 2c09, guest PC 0x0c068c78 */
if(!s->budget--) { s->failed_pc=0x0c068c78u; return 0; }
r[12]&=r[0];
goto P_0c068c7a;
P_0c068c7a: /* original de2a, guest PC 0x0c068c7a */
if(!s->budget--) { s->failed_pc=0x0c068c7au; return 0; }
r[14]=read(ram,0x0c068d24u,4);
goto P_0c068c7c;
P_0c068c7c: /* original 6bc3, guest PC 0x0c068c7c */
if(!s->budget--) { s->failed_pc=0x0c068c7cu; return 0; }
r[11]=r[12];
goto P_0c068c7e;
P_0c068c7e: /* original 4b08, guest PC 0x0c068c7e */
if(!s->budget--) { s->failed_pc=0x0c068c7eu; return 0; }
r[11]<<=2;
goto P_0c068c80;
P_0c068c80: /* original 60b3, guest PC 0x0c068c80 */
if(!s->budget--) { s->failed_pc=0x0c068c80u; return 0; }
r[0]=r[11];
goto P_0c068c82;
P_0c068c82: /* original 008e, guest PC 0x0c068c82 */
if(!s->budget--) { s->failed_pc=0x0c068c82u; return 0; }
r[0]=read(ram,r[8]+r[0],4);
goto P_0c068c84;
P_0c068c84: /* original 88ff, guest PC 0x0c068c84 */
if(!s->budget--) { s->failed_pc=0x0c068c84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c068c86;
P_0c068c86: /* original 8d36, guest PC 0x0c068c86 */
if(!s->budget--) { s->failed_pc=0x0c068c86u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c068cf6; }
goto P_0c068c8a;
P_0c068c88: /* original e400, guest PC 0x0c068c88 */
if(!s->budget--) { s->failed_pc=0x0c068c88u; return 0; }
r[4]=0x00000000u;
goto P_0c068c8a;
P_0c068c8a: /* original 6192, guest PC 0x0c068c8a */
if(!s->budget--) { s->failed_pc=0x0c068c8au; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c068c8c;
P_0c068c8c: /* original d22c, guest PC 0x0c068c8c */
if(!s->budget--) { s->failed_pc=0x0c068c8cu; return 0; }
r[2]=read(ram,0x0c068d40u,4);
goto P_0c068c8e;
P_0c068c8e: /* original dd23, guest PC 0x0c068c8e */
if(!s->budget--) { s->failed_pc=0x0c068c8eu; return 0; }
r[13]=read(ram,0x0c068d1cu,4);
goto P_0c068c90;
P_0c068c90: /* original 2128, guest PC 0x0c068c90 */
if(!s->budget--) { s->failed_pc=0x0c068c90u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c068c92;
P_0c068c92: /* original 8912, guest PC 0x0c068c92 */
if(!s->budget--) { s->failed_pc=0x0c068c92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068cba; }
goto P_0c068c94;
P_0c068c94: /* original 903d, guest PC 0x0c068c94 */
if(!s->budget--) { s->failed_pc=0x0c068c94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068c96;
P_0c068c96: /* original 0a46, guest PC 0x0c068c96 */
if(!s->budget--) { s->failed_pc=0x0c068c96u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c068c98;
P_0c068c98: /* original 60b3, guest PC 0x0c068c98 */
if(!s->budget--) { s->failed_pc=0x0c068c98u; return 0; }
r[0]=r[11];
goto P_0c068c9a;
P_0c068c9a: /* original 2e42, guest PC 0x0c068c9a */
if(!s->budget--) { s->failed_pc=0x0c068c9au; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068c9c;
P_0c068c9c: /* original 933a, guest PC 0x0c068c9c */
if(!s->budget--) { s->failed_pc=0x0c068c9cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d14u,2);
goto P_0c068c9e;
P_0c068c9e: /* original 2f36, guest PC 0x0c068c9e */
if(!s->budget--) { s->failed_pc=0x0c068c9eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca0;
P_0c068ca0: /* original d228, guest PC 0x0c068ca0 */
if(!s->budget--) { s->failed_pc=0x0c068ca0u; return 0; }
r[2]=read(ram,0x0c068d44u,4);
goto P_0c068ca2;
P_0c068ca2: /* original 2f26, guest PC 0x0c068ca2 */
if(!s->budget--) { s->failed_pc=0x0c068ca2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca4;
P_0c068ca4: /* original 2fc6, guest PC 0x0c068ca4 */
if(!s->budget--) { s->failed_pc=0x0c068ca4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca6;
P_0c068ca6: /* original 9636, guest PC 0x0c068ca6 */
if(!s->budget--) { s->failed_pc=0x0c068ca6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d16u,2);
goto P_0c068ca8;
P_0c068ca8: /* original d727, guest PC 0x0c068ca8 */
if(!s->budget--) { s->failed_pc=0x0c068ca8u; return 0; }
r[7]=read(ram,0x0c068d48u,4);
goto P_0c068caa;
P_0c068caa: /* original 369c, guest PC 0x0c068caa */
if(!s->budget--) { s->failed_pc=0x0c068caau; return 0; }
r[6]+=r[9];
goto P_0c068cac;
P_0c068cac: /* original 65d2, guest PC 0x0c068cac */
if(!s->budget--) { s->failed_pc=0x0c068cacu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c068cae;
P_0c068cae: /* original d327, guest PC 0x0c068cae */
if(!s->budget--) { s->failed_pc=0x0c068caeu; return 0; }
r[3]=read(ram,0x0c068d4cu,4);
goto P_0c068cb0;
P_0c068cb0: /* original 7608, guest PC 0x0c068cb0 */
if(!s->budget--) { s->failed_pc=0x0c068cb0u; return 0; }
r[6]+=0x00000008u;
goto P_0c068cb2;
P_0c068cb2: /* original 430b, guest PC 0x0c068cb2 */
if(!s->budget--) { s->failed_pc=0x0c068cb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c068cb6u;
r[4]=read(ram,r[8]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068cb6u) { target=s->pc; goto dispatch; }
goto P_0c068cb6;
P_0c068cb4: /* original 048e, guest PC 0x0c068cb4 */
if(!s->budget--) { s->failed_pc=0x0c068cb4u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c068cb6;
P_0c068cb6: /* original a021, guest PC 0x0c068cb6 */
if(!s->budget--) { s->failed_pc=0x0c068cb6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c068cfc;
P_0c068cb8: /* original 7f0c, guest PC 0x0c068cb8 */
if(!s->budget--) { s->failed_pc=0x0c068cb8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c068cba;
P_0c068cba: /* original d325, guest PC 0x0c068cba */
if(!s->budget--) { s->failed_pc=0x0c068cbau; return 0; }
r[3]=read(ram,0x0c068d50u,4);
goto P_0c068cbc;
P_0c068cbc: /* original 60b3, guest PC 0x0c068cbc */
if(!s->budget--) { s->failed_pc=0x0c068cbcu; return 0; }
r[0]=r[11];
goto P_0c068cbe;
P_0c068cbe: /* original 65d2, guest PC 0x0c068cbe */
if(!s->budget--) { s->failed_pc=0x0c068cbeu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c068cc0;
P_0c068cc0: /* original 430b, guest PC 0x0c068cc0 */
if(!s->budget--) { s->failed_pc=0x0c068cc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c068cc4u;
r[4]=read(ram,r[8]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c068cc4u) { target=s->pc; goto dispatch; }
goto P_0c068cc4;
P_0c068cc2: /* original 048e, guest PC 0x0c068cc2 */
if(!s->budget--) { s->failed_pc=0x0c068cc2u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c068cc4;
P_0c068cc4: /* original 64d2, guest PC 0x0c068cc4 */
if(!s->budget--) { s->failed_pc=0x0c068cc4u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c068cc6;
P_0c068cc6: /* original 9024, guest PC 0x0c068cc6 */
if(!s->budget--) { s->failed_pc=0x0c068cc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068cc8;
P_0c068cc8: /* original 6542, guest PC 0x0c068cc8 */
if(!s->budget--) { s->failed_pc=0x0c068cc8u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c068cca;
P_0c068cca: /* original 6343, guest PC 0x0c068cca */
if(!s->budget--) { s->failed_pc=0x0c068ccau; return 0; }
r[3]=r[4];
goto P_0c068ccc;
P_0c068ccc: /* original 353c, guest PC 0x0c068ccc */
if(!s->budget--) { s->failed_pc=0x0c068cccu; return 0; }
r[5]+=r[3];
goto P_0c068cce;
P_0c068cce: /* original 0a56, guest PC 0x0c068cce */
if(!s->budget--) { s->failed_pc=0x0c068cceu; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c068cd0;
P_0c068cd0: /* original 60c3, guest PC 0x0c068cd0 */
if(!s->budget--) { s->failed_pc=0x0c068cd0u; return 0; }
r[0]=r[12];
goto P_0c068cd2;
P_0c068cd2: /* original 5441, guest PC 0x0c068cd2 */
if(!s->budget--) { s->failed_pc=0x0c068cd2u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c068cd4;
P_0c068cd4: /* original 880c, guest PC 0x0c068cd4 */
if(!s->budget--) { s->failed_pc=0x0c068cd4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c068cd6;
P_0c068cd6: /* original 63d2, guest PC 0x0c068cd6 */
if(!s->budget--) { s->failed_pc=0x0c068cd6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c068cd8;
P_0c068cd8: /* original 343c, guest PC 0x0c068cd8 */
if(!s->budget--) { s->failed_pc=0x0c068cd8u; return 0; }
r[4]+=r[3];
goto P_0c068cda;
P_0c068cda: /* original 8f0f, guest PC 0x0c068cda */
if(!s->budget--) { s->failed_pc=0x0c068cdau; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[4],4);
if(!cond) { goto P_0c068cfc; }
goto P_0c068cde;
P_0c068cdc: /* original 2e42, guest PC 0x0c068cdc */
if(!s->budget--) { s->failed_pc=0x0c068cdcu; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068cde;
P_0c068cde: /* original c713, guest PC 0x0c068cde */
if(!s->budget--) { s->failed_pc=0x0c068cdeu; return 0; }
r[0]=0x0c068d2cu;
goto P_0c068ce0;
P_0c068ce0: /* original 63e2, guest PC 0x0c068ce0 */
if(!s->budget--) { s->failed_pc=0x0c068ce0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c068ce2;
P_0c068ce2: /* original f308, guest PC 0x0c068ce2 */
if(!s->budget--) { s->failed_pc=0x0c068ce2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c068ce4;
P_0c068ce4: /* original d012, guest PC 0x0c068ce4 */
if(!s->budget--) { s->failed_pc=0x0c068ce4u; return 0; }
r[0]=read(ram,0x0c068d30u,4);
goto P_0c068ce6;
P_0c068ce6: /* original f337, guest PC 0x0c068ce6 */
if(!s->budget--) { s->failed_pc=0x0c068ce6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c068ce8;
P_0c068ce8: /* original c712, guest PC 0x0c068ce8 */
if(!s->budget--) { s->failed_pc=0x0c068ce8u; return 0; }
r[0]=0x0c068d34u;
goto P_0c068cea;
P_0c068cea: /* original f308, guest PC 0x0c068cea */
if(!s->budget--) { s->failed_pc=0x0c068ceau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c068cec;
P_0c068cec: /* original 900f, guest PC 0x0c068cec */
if(!s->budget--) { s->failed_pc=0x0c068cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d0eu,2);
goto P_0c068cee;
P_0c068cee: /* original 63e2, guest PC 0x0c068cee */
if(!s->budget--) { s->failed_pc=0x0c068ceeu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c068cf0;
P_0c068cf0: /* original f337, guest PC 0x0c068cf0 */
if(!s->budget--) { s->failed_pc=0x0c068cf0u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c068cf2;
P_0c068cf2: /* original a003, guest PC 0x0c068cf2 */
if(!s->budget--) { s->failed_pc=0x0c068cf2u; return 0; }
goto P_0c068cfc;
P_0c068cf4: /* original 0009, guest PC 0x0c068cf4 */
if(!s->budget--) { s->failed_pc=0x0c068cf4u; return 0; }
goto P_0c068cf6;
P_0c068cf6: /* original 900c, guest PC 0x0c068cf6 */
if(!s->budget--) { s->failed_pc=0x0c068cf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068cf8;
P_0c068cf8: /* original 0a46, guest PC 0x0c068cf8 */
if(!s->budget--) { s->failed_pc=0x0c068cf8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c068cfa;
P_0c068cfa: /* original 2e42, guest PC 0x0c068cfa */
if(!s->budget--) { s->failed_pc=0x0c068cfau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068cfc;
P_0c068cfc: /* original 4f26, guest PC 0x0c068cfc */
if(!s->budget--) { s->failed_pc=0x0c068cfcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068cfe;
P_0c068cfe: /* original 68f6, guest PC 0x0c068cfe */
if(!s->budget--) { s->failed_pc=0x0c068cfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c068d00;
P_0c068d00: /* original 69f6, guest PC 0x0c068d00 */
if(!s->budget--) { s->failed_pc=0x0c068d00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c068d02;
P_0c068d02: /* original 6af6, guest PC 0x0c068d02 */
if(!s->budget--) { s->failed_pc=0x0c068d02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c068d04;
P_0c068d04: /* original 6bf6, guest PC 0x0c068d04 */
if(!s->budget--) { s->failed_pc=0x0c068d04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c068d06;
P_0c068d06: /* original 6cf6, guest PC 0x0c068d06 */
if(!s->budget--) { s->failed_pc=0x0c068d06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c068d08;
P_0c068d08: /* original 6df6, guest PC 0x0c068d08 */
if(!s->budget--) { s->failed_pc=0x0c068d08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c068d0a;
P_0c068d0a: /* original 000b, guest PC 0x0c068d0a */
if(!s->budget--) { s->failed_pc=0x0c068d0au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c068d0c: /* original 6ef6, guest PC 0x0c068d0c */
if(!s->budget--) { s->failed_pc=0x0c068d0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c068d0eu,s,ram);
P_0c074800: /* original d12e, guest PC 0x0c074800 */
if(!s->budget--) { s->failed_pc=0x0c074800u; return 0; }
r[1]=read(ram,0x0c0748bcu,4);
goto P_0c074802;
P_0c074802: /* original d32d, guest PC 0x0c074802 */
if(!s->budget--) { s->failed_pc=0x0c074802u; return 0; }
r[3]=read(ram,0x0c0748b8u,4);
goto P_0c074804;
P_0c074804: /* original 6212, guest PC 0x0c074804 */
if(!s->budget--) { s->failed_pc=0x0c074804u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c074806;
P_0c074806: /* original 2238, guest PC 0x0c074806 */
if(!s->budget--) { s->failed_pc=0x0c074806u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c074808;
P_0c074808: /* original 8b0f, guest PC 0x0c074808 */
if(!s->budget--) { s->failed_pc=0x0c074808u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07482a; }
goto P_0c07480a;
P_0c07480a: /* original 914d, guest PC 0x0c07480a */
if(!s->budget--) { s->failed_pc=0x0c07480au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748a8u,2);
goto P_0c07480c;
P_0c07480c: /* original e014, guest PC 0x0c07480c */
if(!s->budget--) { s->failed_pc=0x0c07480cu; return 0; }
r[0]=0x00000014u;
goto P_0c07480e;
P_0c07480e: /* original f246, guest PC 0x0c07480e */
if(!s->budget--) { s->failed_pc=0x0c07480eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074810;
P_0c074810: /* original 314c, guest PC 0x0c074810 */
if(!s->budget--) { s->failed_pc=0x0c074810u; return 0; }
r[1]+=r[4];
goto P_0c074812;
P_0c074812: /* original f318, guest PC 0x0c074812 */
if(!s->budget--) { s->failed_pc=0x0c074812u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c074814;
P_0c074814: /* original f230, guest PC 0x0c074814 */
if(!s->budget--) { s->failed_pc=0x0c074814u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c074816;
P_0c074816: /* original f427, guest PC 0x0c074816 */
if(!s->budget--) { s->failed_pc=0x0c074816u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c074818;
P_0c074818: /* original 9146, guest PC 0x0c074818 */
if(!s->budget--) { s->failed_pc=0x0c074818u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748a8u,2);
goto P_0c07481a;
P_0c07481a: /* original f256, guest PC 0x0c07481a */
if(!s->budget--) { s->failed_pc=0x0c07481au; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c07481c;
P_0c07481c: /* original 315c, guest PC 0x0c07481c */
if(!s->budget--) { s->failed_pc=0x0c07481cu; return 0; }
r[1]+=r[5];
goto P_0c07481e;
P_0c07481e: /* original f318, guest PC 0x0c07481e */
if(!s->budget--) { s->failed_pc=0x0c07481eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c074820;
P_0c074820: /* original f230, guest PC 0x0c074820 */
if(!s->budget--) { s->failed_pc=0x0c074820u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c074822;
P_0c074822: /* original f527, guest PC 0x0c074822 */
if(!s->budget--) { s->failed_pc=0x0c074822u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c074824;
P_0c074824: /* original 9042, guest PC 0x0c074824 */
if(!s->budget--) { s->failed_pc=0x0c074824u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748acu,2);
goto P_0c074826;
P_0c074826: /* original f38d, guest PC 0x0c074826 */
if(!s->budget--) { s->failed_pc=0x0c074826u; return 0; }
fr[3]=0;
goto P_0c074828;
P_0c074828: /* original f437, guest PC 0x0c074828 */
if(!s->budget--) { s->failed_pc=0x0c074828u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07482a;
P_0c07482a: /* original 000b, guest PC 0x0c07482a */
if(!s->budget--) { s->failed_pc=0x0c07482au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07482c: /* original 0009, guest PC 0x0c07482c */
if(!s->budget--) { s->failed_pc=0x0c07482cu; return 0; }
return vf3_matrix_family(0x0c07482eu,s,ram);
P_0c088dd4: /* original 4f22, guest PC 0x0c088dd4 */
if(!s->budget--) { s->failed_pc=0x0c088dd4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088dd6;
P_0c088dd6: /* original 7ff0, guest PC 0x0c088dd6 */
if(!s->budget--) { s->failed_pc=0x0c088dd6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c088dd8;
P_0c088dd8: /* original 1f43, guest PC 0x0c088dd8 */
if(!s->budget--) { s->failed_pc=0x0c088dd8u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c088dda;
P_0c088dda: /* original d33c, guest PC 0x0c088dda */
if(!s->budget--) { s->failed_pc=0x0c088ddau; return 0; }
r[3]=read(ram,0x0c088eccu,4);
goto P_0c088ddc;
P_0c088ddc: /* original 430b, guest PC 0x0c088ddc */
if(!s->budget--) { s->failed_pc=0x0c088ddcu; return 0; }
target=r[3];
r[16]=code_base|0x0c088de0u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088de0u) { target=s->pc; goto dispatch; }
goto P_0c088de0;
P_0c088dde: /* original e400, guest PC 0x0c088dde */
if(!s->budget--) { s->failed_pc=0x0c088ddeu; return 0; }
r[4]=0x00000000u;
goto P_0c088de0;
P_0c088de0: /* original 84d2, guest PC 0x0c088de0 */
if(!s->budget--) { s->failed_pc=0x0c088de0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c088de2;
P_0c088de2: /* original e808, guest PC 0x0c088de2 */
if(!s->budget--) { s->failed_pc=0x0c088de2u; return 0; }
r[8]=0x00000008u;
goto P_0c088de4;
P_0c088de4: /* original 80f8, guest PC 0x0c088de4 */
if(!s->budget--) { s->failed_pc=0x0c088de4u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c088de6;
P_0c088de6: /* original 84f8, guest PC 0x0c088de6 */
if(!s->budget--) { s->failed_pc=0x0c088de6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c088de8;
P_0c088de8: /* original de39, guest PC 0x0c088de8 */
if(!s->budget--) { s->failed_pc=0x0c088de8u; return 0; }
r[14]=read(ram,0x0c088ed0u,4);
goto P_0c088dea;
P_0c088dea: /* original 4008, guest PC 0x0c088dea */
if(!s->budget--) { s->failed_pc=0x0c088deau; return 0; }
r[0]<<=2;
goto P_0c088dec;
P_0c088dec: /* original 2f02, guest PC 0x0c088dec */
if(!s->budget--) { s->failed_pc=0x0c088decu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c088dee;
P_0c088dee: /* original da3a, guest PC 0x0c088dee */
if(!s->budget--) { s->failed_pc=0x0c088deeu; return 0; }
r[10]=read(ram,0x0c088ed8u,4);
goto P_0c088df0;
P_0c088df0: /* original db3a, guest PC 0x0c088df0 */
if(!s->budget--) { s->failed_pc=0x0c088df0u; return 0; }
r[11]=read(ram,0x0c088edcu,4);
goto P_0c088df2;
P_0c088df2: /* original dc3b, guest PC 0x0c088df2 */
if(!s->budget--) { s->failed_pc=0x0c088df2u; return 0; }
r[12]=read(ram,0x0c088ee0u,4);
goto P_0c088df4;
P_0c088df4: /* original d937, guest PC 0x0c088df4 */
if(!s->budget--) { s->failed_pc=0x0c088df4u; return 0; }
r[9]=read(ram,0x0c088ed4u,4);
goto P_0c088df6;
P_0c088df6: /* original ff9d, guest PC 0x0c088df6 */
if(!s->budget--) { s->failed_pc=0x0c088df6u; return 0; }
fr[15]=0x3f800000u;
goto P_0c088df8;
P_0c088df8: /* original e004, guest PC 0x0c088df8 */
if(!s->budget--) { s->failed_pc=0x0c088df8u; return 0; }
r[0]=0x00000004u;
goto P_0c088dfa;
P_0c088dfa: /* original 63f2, guest PC 0x0c088dfa */
if(!s->budget--) { s->failed_pc=0x0c088dfau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c088dfc;
P_0c088dfc: /* original f3e6, guest PC 0x0c088dfc */
if(!s->budget--) { s->failed_pc=0x0c088dfcu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c088dfe;
P_0c088dfe: /* original 50e4, guest PC 0x0c088dfe */
if(!s->budget--) { s->failed_pc=0x0c088dfeu; return 0; }
r[0]=read(ram,r[14]+16,4);
goto P_0c088e00;
P_0c088e00: /* original f3f2, guest PC 0x0c088e00 */
if(!s->budget--) { s->failed_pc=0x0c088e00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c088e02;
P_0c088e02: /* original fee8, guest PC 0x0c088e02 */
if(!s->budget--) { s->failed_pc=0x0c088e02u; return 0; }
vf3_matrix_load(s,ram,14,r[14]);
goto P_0c088e04;
P_0c088e04: /* original fc3c, guest PC 0x0c088e04 */
if(!s->budget--) { s->failed_pc=0x0c088e04u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c088e06;
P_0c088e06: /* original fc4d, guest PC 0x0c088e06 */
if(!s->budget--) { s->failed_pc=0x0c088e06u; return 0; }
fr[12]^=0x80000000u;
goto P_0c088e08;
P_0c088e08: /* original 4a0b, guest PC 0x0c088e08 */
if(!s->budget--) { s->failed_pc=0x0c088e08u; return 0; }
target=r[10];
r[16]=code_base|0x0c088e0cu;
vf3_matrix_load(s,ram,13,r[3]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e0cu) { target=s->pc; goto dispatch; }
goto P_0c088e0c;
P_0c088e0a: /* original fd36, guest PC 0x0c088e0a */
if(!s->budget--) { s->failed_pc=0x0c088e0au; return 0; }
vf3_matrix_load(s,ram,13,r[3]+r[0]);
goto P_0c088e0c;
P_0c088e0c: /* original f5dc, guest PC 0x0c088e0c */
if(!s->budget--) { s->failed_pc=0x0c088e0cu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088e0e;
P_0c088e0e: /* original f6cc, guest PC 0x0c088e0e */
if(!s->budget--) { s->failed_pc=0x0c088e0eu; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c088e10;
P_0c088e10: /* original 4b0b, guest PC 0x0c088e10 */
if(!s->budget--) { s->failed_pc=0x0c088e10u; return 0; }
target=r[11];
r[16]=code_base|0x0c088e14u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e14u) { target=s->pc; goto dispatch; }
goto P_0c088e14;
P_0c088e12: /* original f4ec, guest PC 0x0c088e12 */
if(!s->budget--) { s->failed_pc=0x0c088e12u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088e14;
P_0c088e14: /* original 53e3, guest PC 0x0c088e14 */
if(!s->budget--) { s->failed_pc=0x0c088e14u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c088e16;
P_0c088e16: /* original 2338, guest PC 0x0c088e16 */
if(!s->budget--) { s->failed_pc=0x0c088e16u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c088e18;
P_0c088e18: /* original 8b02, guest PC 0x0c088e18 */
if(!s->budget--) { s->failed_pc=0x0c088e18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088e20; }
goto P_0c088e1a;
P_0c088e1a: /* original 85d2, guest PC 0x0c088e1a */
if(!s->budget--) { s->failed_pc=0x0c088e1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c088e1c;
P_0c088e1c: /* original a002, guest PC 0x0c088e1c */
if(!s->budget--) { s->failed_pc=0x0c088e1cu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e24;
P_0c088e1e: /* original 81f2, guest PC 0x0c088e1e */
if(!s->budget--) { s->failed_pc=0x0c088e1eu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e20;
P_0c088e20: /* original 85d3, guest PC 0x0c088e20 */
if(!s->budget--) { s->failed_pc=0x0c088e20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+6,2);
goto P_0c088e22;
P_0c088e22: /* original 81f2, guest PC 0x0c088e22 */
if(!s->budget--) { s->failed_pc=0x0c088e22u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e24;
P_0c088e24: /* original 85f2, guest PC 0x0c088e24 */
if(!s->budget--) { s->failed_pc=0x0c088e24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088e26;
P_0c088e26: /* original 490b, guest PC 0x0c088e26 */
if(!s->budget--) { s->failed_pc=0x0c088e26u; return 0; }
target=r[9];
r[16]=code_base|0x0c088e2au;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e2au) { target=s->pc; goto dispatch; }
goto P_0c088e2a;
P_0c088e28: /* original 6403, guest PC 0x0c088e28 */
if(!s->budget--) { s->failed_pc=0x0c088e28u; return 0; }
r[4]=r[0];
goto P_0c088e2a;
P_0c088e2a: /* original 4c0b, guest PC 0x0c088e2a */
if(!s->budget--) { s->failed_pc=0x0c088e2au; return 0; }
target=r[12];
r[16]=code_base|0x0c088e2eu;
r[4]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e2eu) { target=s->pc; goto dispatch; }
goto P_0c088e2e;
P_0c088e2c: /* original 54e2, guest PC 0x0c088e2c */
if(!s->budget--) { s->failed_pc=0x0c088e2cu; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c088e2e;
P_0c088e2e: /* original 4810, guest PC 0x0c088e2e */
if(!s->budget--) { s->failed_pc=0x0c088e2eu; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c088e30;
P_0c088e30: /* original 8fe2, guest PC 0x0c088e30 */
if(!s->budget--) { s->failed_pc=0x0c088e30u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000014u;
if(!cond) { goto P_0c088df8; }
goto P_0c088e34;
P_0c088e32: /* original 7e14, guest PC 0x0c088e32 */
if(!s->budget--) { s->failed_pc=0x0c088e32u; return 0; }
r[14]+=0x00000014u;
goto P_0c088e34;
P_0c088e34: /* original de2b, guest PC 0x0c088e34 */
if(!s->budget--) { s->failed_pc=0x0c088e34u; return 0; }
r[14]=read(ram,0x0c088ee4u,4);
goto P_0c088e36;
P_0c088e36: /* original e802, guest PC 0x0c088e36 */
if(!s->budget--) { s->failed_pc=0x0c088e36u; return 0; }
r[8]=0x00000002u;
goto P_0c088e38;
P_0c088e38: /* original e004, guest PC 0x0c088e38 */
if(!s->budget--) { s->failed_pc=0x0c088e38u; return 0; }
r[0]=0x00000004u;
goto P_0c088e3a;
P_0c088e3a: /* original 63f2, guest PC 0x0c088e3a */
if(!s->budget--) { s->failed_pc=0x0c088e3au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c088e3c;
P_0c088e3c: /* original f3e6, guest PC 0x0c088e3c */
if(!s->budget--) { s->failed_pc=0x0c088e3cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c088e3e;
P_0c088e3e: /* original 50e4, guest PC 0x0c088e3e */
if(!s->budget--) { s->failed_pc=0x0c088e3eu; return 0; }
r[0]=read(ram,r[14]+16,4);
goto P_0c088e40;
P_0c088e40: /* original f3f2, guest PC 0x0c088e40 */
if(!s->budget--) { s->failed_pc=0x0c088e40u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c088e42;
P_0c088e42: /* original fee8, guest PC 0x0c088e42 */
if(!s->budget--) { s->failed_pc=0x0c088e42u; return 0; }
vf3_matrix_load(s,ram,14,r[14]);
goto P_0c088e44;
P_0c088e44: /* original fc3c, guest PC 0x0c088e44 */
if(!s->budget--) { s->failed_pc=0x0c088e44u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c088e46;
P_0c088e46: /* original fc4d, guest PC 0x0c088e46 */
if(!s->budget--) { s->failed_pc=0x0c088e46u; return 0; }
fr[12]^=0x80000000u;
goto P_0c088e48;
P_0c088e48: /* original 4a0b, guest PC 0x0c088e48 */
if(!s->budget--) { s->failed_pc=0x0c088e48u; return 0; }
target=r[10];
r[16]=code_base|0x0c088e4cu;
vf3_matrix_load(s,ram,13,r[3]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e4cu) { target=s->pc; goto dispatch; }
goto P_0c088e4c;
P_0c088e4a: /* original fd36, guest PC 0x0c088e4a */
if(!s->budget--) { s->failed_pc=0x0c088e4au; return 0; }
vf3_matrix_load(s,ram,13,r[3]+r[0]);
goto P_0c088e4c;
P_0c088e4c: /* original f5dc, guest PC 0x0c088e4c */
if(!s->budget--) { s->failed_pc=0x0c088e4cu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088e4e;
P_0c088e4e: /* original f6cc, guest PC 0x0c088e4e */
if(!s->budget--) { s->failed_pc=0x0c088e4eu; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c088e50;
P_0c088e50: /* original 4b0b, guest PC 0x0c088e50 */
if(!s->budget--) { s->failed_pc=0x0c088e50u; return 0; }
target=r[11];
r[16]=code_base|0x0c088e54u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e54u) { target=s->pc; goto dispatch; }
goto P_0c088e54;
P_0c088e52: /* original f4ec, guest PC 0x0c088e52 */
if(!s->budget--) { s->failed_pc=0x0c088e52u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088e54;
P_0c088e54: /* original 53e3, guest PC 0x0c088e54 */
if(!s->budget--) { s->failed_pc=0x0c088e54u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c088e56;
P_0c088e56: /* original 2338, guest PC 0x0c088e56 */
if(!s->budget--) { s->failed_pc=0x0c088e56u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c088e58;
P_0c088e58: /* original 8b02, guest PC 0x0c088e58 */
if(!s->budget--) { s->failed_pc=0x0c088e58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088e60; }
goto P_0c088e5a;
P_0c088e5a: /* original 85d2, guest PC 0x0c088e5a */
if(!s->budget--) { s->failed_pc=0x0c088e5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c088e5c;
P_0c088e5c: /* original a002, guest PC 0x0c088e5c */
if(!s->budget--) { s->failed_pc=0x0c088e5cu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e64;
P_0c088e5e: /* original 81f2, guest PC 0x0c088e5e */
if(!s->budget--) { s->failed_pc=0x0c088e5eu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e60;
P_0c088e60: /* original 85d3, guest PC 0x0c088e60 */
if(!s->budget--) { s->failed_pc=0x0c088e60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+6,2);
goto P_0c088e62;
P_0c088e62: /* original 81f2, guest PC 0x0c088e62 */
if(!s->budget--) { s->failed_pc=0x0c088e62u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e64;
P_0c088e64: /* original 85f2, guest PC 0x0c088e64 */
if(!s->budget--) { s->failed_pc=0x0c088e64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088e66;
P_0c088e66: /* original 490b, guest PC 0x0c088e66 */
if(!s->budget--) { s->failed_pc=0x0c088e66u; return 0; }
target=r[9];
r[16]=code_base|0x0c088e6au;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e6au) { target=s->pc; goto dispatch; }
goto P_0c088e6a;
P_0c088e68: /* original 6403, guest PC 0x0c088e68 */
if(!s->budget--) { s->failed_pc=0x0c088e68u; return 0; }
r[4]=r[0];
goto P_0c088e6a;
P_0c088e6a: /* original 4c0b, guest PC 0x0c088e6a */
if(!s->budget--) { s->failed_pc=0x0c088e6au; return 0; }
target=r[12];
r[16]=code_base|0x0c088e6eu;
r[4]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e6eu) { target=s->pc; goto dispatch; }
goto P_0c088e6e;
P_0c088e6c: /* original 54e2, guest PC 0x0c088e6c */
if(!s->budget--) { s->failed_pc=0x0c088e6cu; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c088e6e;
P_0c088e6e: /* original 4810, guest PC 0x0c088e6e */
if(!s->budget--) { s->failed_pc=0x0c088e6eu; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c088e70;
P_0c088e70: /* original 8fe2, guest PC 0x0c088e70 */
if(!s->budget--) { s->failed_pc=0x0c088e70u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000014u;
if(!cond) { goto P_0c088e38; }
goto P_0c088e74;
P_0c088e72: /* original 7e14, guest PC 0x0c088e72 */
if(!s->budget--) { s->failed_pc=0x0c088e72u; return 0; }
r[14]+=0x00000014u;
goto P_0c088e74;
P_0c088e74: /* original 84f8, guest PC 0x0c088e74 */
if(!s->budget--) { s->failed_pc=0x0c088e74u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c088e76;
P_0c088e76: /* original 9428, guest PC 0x0c088e76 */
if(!s->budget--) { s->failed_pc=0x0c088e76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088ecau,2);
goto P_0c088e78;
P_0c088e78: /* original d31b, guest PC 0x0c088e78 */
if(!s->budget--) { s->failed_pc=0x0c088e78u; return 0; }
r[3]=read(ram,0x0c088ee8u,4);
goto P_0c088e7a;
P_0c088e7a: /* original 6903, guest PC 0x0c088e7a */
if(!s->budget--) { s->failed_pc=0x0c088e7au; return 0; }
r[9]=r[0];
goto P_0c088e7c;
P_0c088e7c: /* original 430b, guest PC 0x0c088e7c */
if(!s->budget--) { s->failed_pc=0x0c088e7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c088e80u;
r[4]+=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e80u) { target=s->pc; goto dispatch; }
goto P_0c088e80;
P_0c088e7e: /* original 349c, guest PC 0x0c088e7e */
if(!s->budget--) { s->failed_pc=0x0c088e7eu; return 0; }
r[4]+=r[9];
goto P_0c088e80;
P_0c088e80: /* original 5ef3, guest PC 0x0c088e80 */
if(!s->budget--) { s->failed_pc=0x0c088e80u; return 0; }
r[14]=read(ram,r[15]+12,4);
goto P_0c088e82;
P_0c088e82: /* original ed1f, guest PC 0x0c088e82 */
if(!s->budget--) { s->failed_pc=0x0c088e82u; return 0; }
r[13]=0x0000001fu;
goto P_0c088e84;
P_0c088e84: /* original fd8d, guest PC 0x0c088e84 */
if(!s->budget--) { s->failed_pc=0x0c088e84u; return 0; }
fr[13]=0;
goto P_0c088e86;
P_0c088e86: /* original 7e10, guest PC 0x0c088e86 */
if(!s->budget--) { s->failed_pc=0x0c088e86u; return 0; }
r[14]+=0x00000010u;
goto P_0c088e88;
P_0c088e88: /* original e004, guest PC 0x0c088e88 */
if(!s->budget--) { s->failed_pc=0x0c088e88u; return 0; }
r[0]=0x00000004u;
goto P_0c088e8a;
P_0c088e8a: /* original fce8, guest PC 0x0c088e8a */
if(!s->budget--) { s->failed_pc=0x0c088e8au; return 0; }
vf3_matrix_load(s,ram,12,r[14]);
goto P_0c088e8c;
P_0c088e8c: /* original f3e6, guest PC 0x0c088e8c */
if(!s->budget--) { s->failed_pc=0x0c088e8cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c088e8e;
P_0c088e8e: /* original f3f2, guest PC 0x0c088e8e */
if(!s->budget--) { s->failed_pc=0x0c088e8eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c088e90;
P_0c088e90: /* original fe3c, guest PC 0x0c088e90 */
if(!s->budget--) { s->failed_pc=0x0c088e90u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c088e92;
P_0c088e92: /* original 4a0b, guest PC 0x0c088e92 */
if(!s->budget--) { s->failed_pc=0x0c088e92u; return 0; }
target=r[10];
r[16]=code_base|0x0c088e96u;
fr[14]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e96u) { target=s->pc; goto dispatch; }
goto P_0c088e96;
P_0c088e94: /* original fe4d, guest PC 0x0c088e94 */
if(!s->budget--) { s->failed_pc=0x0c088e94u; return 0; }
fr[14]^=0x80000000u;
goto P_0c088e96;
P_0c088e96: /* original f5dc, guest PC 0x0c088e96 */
if(!s->budget--) { s->failed_pc=0x0c088e96u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088e98;
P_0c088e98: /* original f6ec, guest PC 0x0c088e98 */
if(!s->budget--) { s->failed_pc=0x0c088e98u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c088e9a;
P_0c088e9a: /* original 4b0b, guest PC 0x0c088e9a */
if(!s->budget--) { s->failed_pc=0x0c088e9au; return 0; }
target=r[11];
r[16]=code_base|0x0c088e9eu;
vf3_matrix_move(s,4,12);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088e9eu) { target=s->pc; goto dispatch; }
goto P_0c088e9e;
P_0c088e9c: /* original f4cc, guest PC 0x0c088e9c */
if(!s->budget--) { s->failed_pc=0x0c088e9cu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c088e9e;
P_0c088e9e: /* original 54e2, guest PC 0x0c088e9e */
if(!s->budget--) { s->failed_pc=0x0c088e9eu; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c088ea0;
P_0c088ea0: /* original 4c0b, guest PC 0x0c088ea0 */
if(!s->budget--) { s->failed_pc=0x0c088ea0u; return 0; }
target=r[12];
r[16]=code_base|0x0c088ea4u;
r[4]+=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088ea4u) { target=s->pc; goto dispatch; }
goto P_0c088ea4;
P_0c088ea2: /* original 349c, guest PC 0x0c088ea2 */
if(!s->budget--) { s->failed_pc=0x0c088ea2u; return 0; }
r[4]+=r[9];
goto P_0c088ea4;
P_0c088ea4: /* original 4d10, guest PC 0x0c088ea4 */
if(!s->budget--) { s->failed_pc=0x0c088ea4u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c088ea6;
P_0c088ea6: /* original 8fef, guest PC 0x0c088ea6 */
if(!s->budget--) { s->failed_pc=0x0c088ea6u; return 0; }
cond=r[17]&1u;
r[14]+=0x0000000cu;
if(!cond) { goto P_0c088e88; }
goto P_0c088eaa;
P_0c088ea8: /* original 7e0c, guest PC 0x0c088ea8 */
if(!s->budget--) { s->failed_pc=0x0c088ea8u; return 0; }
r[14]+=0x0000000cu;
goto P_0c088eaa;
P_0c088eaa: /* original 7f10, guest PC 0x0c088eaa */
if(!s->budget--) { s->failed_pc=0x0c088eaau; return 0; }
r[15]+=0x00000010u;
goto P_0c088eac;
P_0c088eac: /* original d20f, guest PC 0x0c088eac */
if(!s->budget--) { s->failed_pc=0x0c088eacu; return 0; }
r[2]=read(ram,0x0c088eecu,4);
goto P_0c088eae;
P_0c088eae: /* original 4f26, guest PC 0x0c088eae */
if(!s->budget--) { s->failed_pc=0x0c088eaeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088eb0;
P_0c088eb0: /* original e401, guest PC 0x0c088eb0 */
if(!s->budget--) { s->failed_pc=0x0c088eb0u; return 0; }
r[4]=0x00000001u;
goto P_0c088eb2;
P_0c088eb2: /* original fcf9, guest PC 0x0c088eb2 */
if(!s->budget--) { s->failed_pc=0x0c088eb2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088eb4;
P_0c088eb4: /* original fdf9, guest PC 0x0c088eb4 */
if(!s->budget--) { s->failed_pc=0x0c088eb4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088eb6;
P_0c088eb6: /* original fef9, guest PC 0x0c088eb6 */
if(!s->budget--) { s->failed_pc=0x0c088eb6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088eb8;
P_0c088eb8: /* original fff9, guest PC 0x0c088eb8 */
if(!s->budget--) { s->failed_pc=0x0c088eb8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088eba;
P_0c088eba: /* original 68f6, guest PC 0x0c088eba */
if(!s->budget--) { s->failed_pc=0x0c088ebau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088ebc;
P_0c088ebc: /* original 69f6, guest PC 0x0c088ebc */
if(!s->budget--) { s->failed_pc=0x0c088ebcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c088ebe;
P_0c088ebe: /* original 6af6, guest PC 0x0c088ebe */
if(!s->budget--) { s->failed_pc=0x0c088ebeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088ec0;
P_0c088ec0: /* original 6bf6, guest PC 0x0c088ec0 */
if(!s->budget--) { s->failed_pc=0x0c088ec0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088ec2;
P_0c088ec2: /* original 6cf6, guest PC 0x0c088ec2 */
if(!s->budget--) { s->failed_pc=0x0c088ec2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088ec4;
P_0c088ec4: /* original 6df6, guest PC 0x0c088ec4 */
if(!s->budget--) { s->failed_pc=0x0c088ec4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088ec6;
P_0c088ec6: /* original 422b, guest PC 0x0c088ec6 */
if(!s->budget--) { s->failed_pc=0x0c088ec6u; return 0; }
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
P_0c088ec8: /* original 6ef6, guest PC 0x0c088ec8 */
if(!s->budget--) { s->failed_pc=0x0c088ec8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c088ecau,s,ram);
P_0c0993e8: /* original 4f22, guest PC 0x0c0993e8 */
if(!s->budget--) { s->failed_pc=0x0c0993e8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0993ea;
P_0c0993ea: /* original d334, guest PC 0x0c0993ea */
if(!s->budget--) { s->failed_pc=0x0c0993eau; return 0; }
r[3]=read(ram,0x0c0994bcu,4);
goto P_0c0993ec;
P_0c0993ec: /* original de31, guest PC 0x0c0993ec */
if(!s->budget--) { s->failed_pc=0x0c0993ecu; return 0; }
r[14]=read(ram,0x0c0994b4u,4);
goto P_0c0993ee;
P_0c0993ee: /* original 7ffc, guest PC 0x0c0993ee */
if(!s->budget--) { s->failed_pc=0x0c0993eeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0993f0;
P_0c0993f0: /* original dc31, guest PC 0x0c0993f0 */
if(!s->budget--) { s->failed_pc=0x0c0993f0u; return 0; }
r[12]=read(ram,0x0c0994b8u,4);
goto P_0c0993f2;
P_0c0993f2: /* original 2f32, guest PC 0x0c0993f2 */
if(!s->budget--) { s->failed_pc=0x0c0993f2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0993f4;
P_0c0993f4: /* original d133, guest PC 0x0c0993f4 */
if(!s->budget--) { s->failed_pc=0x0c0993f4u; return 0; }
r[1]=read(ram,0x0c0994c4u,4);
goto P_0c0993f6;
P_0c0993f6: /* original d332, guest PC 0x0c0993f6 */
if(!s->budget--) { s->failed_pc=0x0c0993f6u; return 0; }
r[3]=read(ram,0x0c0994c0u,4);
goto P_0c0993f8;
P_0c0993f8: /* original 6212, guest PC 0x0c0993f8 */
if(!s->budget--) { s->failed_pc=0x0c0993f8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0993fa;
P_0c0993fa: /* original 2238, guest PC 0x0c0993fa */
if(!s->budget--) { s->failed_pc=0x0c0993fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0993fc;
P_0c0993fc: /* original 8b44, guest PC 0x0c0993fc */
if(!s->budget--) { s->failed_pc=0x0c0993fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099488; }
goto P_0c0993fe;
P_0c0993fe: /* original 9055, guest PC 0x0c0993fe */
if(!s->budget--) { s->failed_pc=0x0c0993feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994acu,2);
goto P_0c099400;
P_0c099400: /* original 00ed, guest PC 0x0c099400 */
if(!s->budget--) { s->failed_pc=0x0c099400u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c099402;
P_0c099402: /* original 4015, guest PC 0x0c099402 */
if(!s->budget--) { s->failed_pc=0x0c099402u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c099404;
P_0c099404: /* original 8b03, guest PC 0x0c099404 */
if(!s->budget--) { s->failed_pc=0x0c099404u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09940e; }
goto P_0c099406;
P_0c099406: /* original 9051, guest PC 0x0c099406 */
if(!s->budget--) { s->failed_pc=0x0c099406u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994acu,2);
goto P_0c099408;
P_0c099408: /* original 03ed, guest PC 0x0c099408 */
if(!s->budget--) { s->failed_pc=0x0c099408u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09940a;
P_0c09940a: /* original 73ff, guest PC 0x0c09940a */
if(!s->budget--) { s->failed_pc=0x0c09940au; return 0; }
r[3]+=0xffffffffu;
goto P_0c09940c;
P_0c09940c: /* original 0e35, guest PC 0x0c09940c */
if(!s->budget--) { s->failed_pc=0x0c09940cu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c09940e;
P_0c09940e: /* original 904e, guest PC 0x0c09940e */
if(!s->budget--) { s->failed_pc=0x0c09940eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994aeu,2);
goto P_0c099410;
P_0c099410: /* original e3f8, guest PC 0x0c099410 */
if(!s->budget--) { s->failed_pc=0x0c099410u; return 0; }
r[3]=0xfffffff8u;
goto P_0c099412;
P_0c099412: /* original 04ce, guest PC 0x0c099412 */
if(!s->budget--) { s->failed_pc=0x0c099412u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c099414;
P_0c099414: /* original 7004, guest PC 0x0c099414 */
if(!s->budget--) { s->failed_pc=0x0c099414u; return 0; }
r[0]+=0x00000004u;
goto P_0c099416;
P_0c099416: /* original 0dce, guest PC 0x0c099416 */
if(!s->budget--) { s->failed_pc=0x0c099416u; return 0; }
r[13]=read(ram,r[12]+r[0],4);
goto P_0c099418;
P_0c099418: /* original e029, guest PC 0x0c099418 */
if(!s->budget--) { s->failed_pc=0x0c099418u; return 0; }
r[0]=0x00000029u;
goto P_0c09941a;
P_0c09941a: /* original 00ec, guest PC 0x0c09941a */
if(!s->budget--) { s->failed_pc=0x0c09941au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09941c;
P_0c09941c: /* original 6143, guest PC 0x0c09941c */
if(!s->budget--) { s->failed_pc=0x0c09941cu; return 0; }
r[1]=r[4];
goto P_0c09941e;
P_0c09941e: /* original 6bd3, guest PC 0x0c09941e */
if(!s->budget--) { s->failed_pc=0x0c09941eu; return 0; }
r[11]=r[13];
goto P_0c099420;
P_0c099420: /* original 413c, guest PC 0x0c099420 */
if(!s->budget--) { s->failed_pc=0x0c099420u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c099422;
P_0c099422: /* original 600c, guest PC 0x0c099422 */
if(!s->budget--) { s->failed_pc=0x0c099422u; return 0; }
r[0]=r[0]&255u;
goto P_0c099424;
P_0c099424: /* original 4b21, guest PC 0x0c099424 */
if(!s->budget--) { s->failed_pc=0x0c099424u; return 0; }
r[17]=(r[17]&~1u)|((r[11]&1)!=0);
r[11]=(uint32_t)((int32_t)r[11]>>1);
goto P_0c099426;
P_0c099426: /* original 8803, guest PC 0x0c099426 */
if(!s->budget--) { s->failed_pc=0x0c099426u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099428;
P_0c099428: /* original 8b02, guest PC 0x0c099428 */
if(!s->budget--) { s->failed_pc=0x0c099428u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099430; }
goto P_0c09942a;
P_0c09942a: /* original 241b, guest PC 0x0c09942a */
if(!s->budget--) { s->failed_pc=0x0c09942au; return 0; }
r[4]|=r[1];
goto P_0c09942c;
P_0c09942c: /* original a004, guest PC 0x0c09942c */
if(!s->budget--) { s->failed_pc=0x0c09942cu; return 0; }
r[13]|=r[11];
goto P_0c099438;
P_0c09942e: /* original 2dbb, guest PC 0x0c09942e */
if(!s->budget--) { s->failed_pc=0x0c09942eu; return 0; }
r[13]|=r[11];
goto P_0c099430;
P_0c099430: /* original 8801, guest PC 0x0c099430 */
if(!s->budget--) { s->failed_pc=0x0c099430u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c099432;
P_0c099432: /* original 8901, guest PC 0x0c099432 */
if(!s->budget--) { s->failed_pc=0x0c099432u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099438; }
goto P_0c099434;
P_0c099434: /* original 6db3, guest PC 0x0c099434 */
if(!s->budget--) { s->failed_pc=0x0c099434u; return 0; }
r[13]=r[11];
goto P_0c099436;
P_0c099436: /* original 6413, guest PC 0x0c099436 */
if(!s->budget--) { s->failed_pc=0x0c099436u; return 0; }
r[4]=r[1];
goto P_0c099438;
P_0c099438: /* original 933a, guest PC 0x0c099438 */
if(!s->budget--) { s->failed_pc=0x0c099438u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994b0u,2);
goto P_0c09943a;
P_0c09943a: /* original 2438, guest PC 0x0c09943a */
if(!s->budget--) { s->failed_pc=0x0c09943au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c09943c;
P_0c09943c: /* original 8b15, guest PC 0x0c09943c */
if(!s->budget--) { s->failed_pc=0x0c09943cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09946a; }
goto P_0c09943e;
P_0c09943e: /* original d322, guest PC 0x0c09943e */
if(!s->budget--) { s->failed_pc=0x0c09943eu; return 0; }
r[3]=read(ram,0x0c0994c8u,4);
goto P_0c099440;
P_0c099440: /* original 64f2, guest PC 0x0c099440 */
if(!s->budget--) { s->failed_pc=0x0c099440u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c099442;
P_0c099442: /* original 5be2, guest PC 0x0c099442 */
if(!s->budget--) { s->failed_pc=0x0c099442u; return 0; }
r[11]=read(ram,r[14]+8,4);
goto P_0c099444;
P_0c099444: /* original 430b, guest PC 0x0c099444 */
if(!s->budget--) { s->failed_pc=0x0c099444u; return 0; }
target=r[3];
r[16]=code_base|0x0c099448u;
r[4]+=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099448u) { target=s->pc; goto dispatch; }
goto P_0c099448;
P_0c099446: /* original 7413, guest PC 0x0c099446 */
if(!s->budget--) { s->failed_pc=0x0c099446u; return 0; }
r[4]+=0x00000013u;
goto P_0c099448;
P_0c099448: /* original 640c, guest PC 0x0c099448 */
if(!s->budget--) { s->failed_pc=0x0c099448u; return 0; }
r[4]=r[0]&255u;
goto P_0c09944a;
P_0c09944a: /* original e029, guest PC 0x0c09944a */
if(!s->budget--) { s->failed_pc=0x0c09944au; return 0; }
r[0]=0x00000029u;
goto P_0c09944c;
P_0c09944c: /* original 00ec, guest PC 0x0c09944c */
if(!s->budget--) { s->failed_pc=0x0c09944cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09944e;
P_0c09944e: /* original 600c, guest PC 0x0c09944e */
if(!s->budget--) { s->failed_pc=0x0c09944eu; return 0; }
r[0]=r[0]&255u;
goto P_0c099450;
P_0c099450: /* original 8803, guest PC 0x0c099450 */
if(!s->budget--) { s->failed_pc=0x0c099450u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099452;
P_0c099452: /* original 8b07, guest PC 0x0c099452 */
if(!s->budget--) { s->failed_pc=0x0c099452u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099464; }
goto P_0c099454;
P_0c099454: /* original 2448, guest PC 0x0c099454 */
if(!s->budget--) { s->failed_pc=0x0c099454u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099456;
P_0c099456: /* original 8905, guest PC 0x0c099456 */
if(!s->budget--) { s->failed_pc=0x0c099456u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099464; }
goto P_0c099458;
P_0c099458: /* original d31c, guest PC 0x0c099458 */
if(!s->budget--) { s->failed_pc=0x0c099458u; return 0; }
r[3]=read(ram,0x0c0994ccu,4);
goto P_0c09945a;
P_0c09945a: /* original 23b8, guest PC 0x0c09945a */
if(!s->budget--) { s->failed_pc=0x0c09945au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c09945c;
P_0c09945c: /* original 8b02, guest PC 0x0c09945c */
if(!s->budget--) { s->failed_pc=0x0c09945cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099464; }
goto P_0c09945e;
P_0c09945e: /* original e204, guest PC 0x0c09945e */
if(!s->budget--) { s->failed_pc=0x0c09945eu; return 0; }
r[2]=0x00000004u;
goto P_0c099460;
P_0c099460: /* original 2b28, guest PC 0x0c099460 */
if(!s->budget--) { s->failed_pc=0x0c099460u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[2])==0)!=0);
goto P_0c099462;
P_0c099462: /* original 8b02, guest PC 0x0c099462 */
if(!s->budget--) { s->failed_pc=0x0c099462u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09946a; }
goto P_0c099464;
P_0c099464: /* original e310, guest PC 0x0c099464 */
if(!s->budget--) { s->failed_pc=0x0c099464u; return 0; }
r[3]=0x00000010u;
goto P_0c099466;
P_0c099466: /* original 2d38, guest PC 0x0c099466 */
if(!s->budget--) { s->failed_pc=0x0c099466u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c099468;
P_0c099468: /* original 8b02, guest PC 0x0c099468 */
if(!s->budget--) { s->failed_pc=0x0c099468u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099470; }
goto P_0c09946a;
P_0c09946a: /* original 52c3, guest PC 0x0c09946a */
if(!s->budget--) { s->failed_pc=0x0c09946au; return 0; }
r[2]=read(ram,r[12]+12,4);
goto P_0c09946c;
P_0c09946c: /* original 4215, guest PC 0x0c09946c */
if(!s->budget--) { s->failed_pc=0x0c09946cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c09946e;
P_0c09946e: /* original 8906, guest PC 0x0c09946e */
if(!s->budget--) { s->failed_pc=0x0c09946eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09947e; }
goto P_0c099470;
P_0c099470: /* original 7f04, guest PC 0x0c099470 */
if(!s->budget--) { s->failed_pc=0x0c099470u; return 0; }
r[15]+=0x00000004u;
goto P_0c099472;
P_0c099472: /* original 4f26, guest PC 0x0c099472 */
if(!s->budget--) { s->failed_pc=0x0c099472u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099474;
P_0c099474: /* original 6bf6, guest PC 0x0c099474 */
if(!s->budget--) { s->failed_pc=0x0c099474u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099476;
P_0c099476: /* original 6cf6, guest PC 0x0c099476 */
if(!s->budget--) { s->failed_pc=0x0c099476u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099478;
P_0c099478: /* original 6df6, guest PC 0x0c099478 */
if(!s->budget--) { s->failed_pc=0x0c099478u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09947a;
P_0c09947a: /* original a061, guest PC 0x0c09947a */
if(!s->budget--) { s->failed_pc=0x0c09947au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099540;
P_0c09947c: /* original 6ef6, guest PC 0x0c09947c */
if(!s->budget--) { s->failed_pc=0x0c09947cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09947e;
P_0c09947e: /* original 9018, guest PC 0x0c09947e */
if(!s->budget--) { s->failed_pc=0x0c09947eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994b2u,2);
goto P_0c099480;
P_0c099480: /* original 04ec, guest PC 0x0c099480 */
if(!s->budget--) { s->failed_pc=0x0c099480u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099482;
P_0c099482: /* original 644c, guest PC 0x0c099482 */
if(!s->budget--) { s->failed_pc=0x0c099482u; return 0; }
r[4]=r[4]&255u;
goto P_0c099484;
P_0c099484: /* original 2448, guest PC 0x0c099484 */
if(!s->budget--) { s->failed_pc=0x0c099484u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099486;
P_0c099486: /* original 8b07, guest PC 0x0c099486 */
if(!s->budget--) { s->failed_pc=0x0c099486u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099498; }
goto P_0c099488;
P_0c099488: /* original 7f04, guest PC 0x0c099488 */
if(!s->budget--) { s->failed_pc=0x0c099488u; return 0; }
r[15]+=0x00000004u;
goto P_0c09948a;
P_0c09948a: /* original d211, guest PC 0x0c09948a */
if(!s->budget--) { s->failed_pc=0x0c09948au; return 0; }
r[2]=read(ram,0x0c0994d0u,4);
goto P_0c09948c;
P_0c09948c: /* original 4f26, guest PC 0x0c09948c */
if(!s->budget--) { s->failed_pc=0x0c09948cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09948e;
P_0c09948e: /* original 6bf6, guest PC 0x0c09948e */
if(!s->budget--) { s->failed_pc=0x0c09948eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099490;
P_0c099490: /* original 6cf6, guest PC 0x0c099490 */
if(!s->budget--) { s->failed_pc=0x0c099490u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099492;
P_0c099492: /* original 6df6, guest PC 0x0c099492 */
if(!s->budget--) { s->failed_pc=0x0c099492u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099494;
P_0c099494: /* original 422b, guest PC 0x0c099494 */
if(!s->budget--) { s->failed_pc=0x0c099494u; return 0; }
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
P_0c099496: /* original 6ef6, guest PC 0x0c099496 */
if(!s->budget--) { s->failed_pc=0x0c099496u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099498;
P_0c099498: /* original 6043, guest PC 0x0c099498 */
if(!s->budget--) { s->failed_pc=0x0c099498u; return 0; }
r[0]=r[4];
goto P_0c09949a;
P_0c09949a: /* original 8801, guest PC 0x0c09949a */
if(!s->budget--) { s->failed_pc=0x0c09949au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09949c;
P_0c09949c: /* original 891a, guest PC 0x0c09949c */
if(!s->budget--) { s->failed_pc=0x0c09949cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0994d4; }
goto P_0c09949e;
P_0c09949e: /* original 7f04, guest PC 0x0c09949e */
if(!s->budget--) { s->failed_pc=0x0c09949eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0994a0;
P_0c0994a0: /* original 4f26, guest PC 0x0c0994a0 */
if(!s->budget--) { s->failed_pc=0x0c0994a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0994a2;
P_0c0994a2: /* original 6bf6, guest PC 0x0c0994a2 */
if(!s->budget--) { s->failed_pc=0x0c0994a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0994a4;
P_0c0994a4: /* original 6cf6, guest PC 0x0c0994a4 */
if(!s->budget--) { s->failed_pc=0x0c0994a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0994a6;
P_0c0994a6: /* original 6df6, guest PC 0x0c0994a6 */
if(!s->budget--) { s->failed_pc=0x0c0994a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0994a8;
P_0c0994a8: /* original a02c, guest PC 0x0c0994a8 */
if(!s->budget--) { s->failed_pc=0x0c0994a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099504;
P_0c0994aa: /* original 6ef6, guest PC 0x0c0994aa */
if(!s->budget--) { s->failed_pc=0x0c0994aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0994acu,s,ram);
P_0c0994d4: /* original d238, guest PC 0x0c0994d4 */
if(!s->budget--) { s->failed_pc=0x0c0994d4u; return 0; }
r[2]=read(ram,0x0c0995b8u,4);
goto P_0c0994d6;
P_0c0994d6: /* original d337, guest PC 0x0c0994d6 */
if(!s->budget--) { s->failed_pc=0x0c0994d6u; return 0; }
r[3]=read(ram,0x0c0995b4u,4);
goto P_0c0994d8;
P_0c0994d8: /* original d535, guest PC 0x0c0994d8 */
if(!s->budget--) { s->failed_pc=0x0c0994d8u; return 0; }
r[5]=read(ram,0x0c0995b0u,4);
goto P_0c0994da;
P_0c0994da: /* original 420b, guest PC 0x0c0994da */
if(!s->budget--) { s->failed_pc=0x0c0994dau; return 0; }
target=r[2];
r[16]=code_base|0x0c0994deu;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0994deu) { target=s->pc; goto dispatch; }
goto P_0c0994de;
P_0c0994dc: /* original 6432, guest PC 0x0c0994dc */
if(!s->budget--) { s->failed_pc=0x0c0994dcu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0994de;
P_0c0994de: /* original 9060, guest PC 0x0c0994de */
if(!s->budget--) { s->failed_pc=0x0c0994deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a2u,2);
goto P_0c0994e0;
P_0c0994e0: /* original 01ec, guest PC 0x0c0994e0 */
if(!s->budget--) { s->failed_pc=0x0c0994e0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0994e2;
P_0c0994e2: /* original 2118, guest PC 0x0c0994e2 */
if(!s->budget--) { s->failed_pc=0x0c0994e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0994e4;
P_0c0994e4: /* original 8b02, guest PC 0x0c0994e4 */
if(!s->budget--) { s->failed_pc=0x0c0994e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0994ec; }
goto P_0c0994e6;
P_0c0994e6: /* original d335, guest PC 0x0c0994e6 */
if(!s->budget--) { s->failed_pc=0x0c0994e6u; return 0; }
r[3]=read(ram,0x0c0995bcu,4);
goto P_0c0994e8;
P_0c0994e8: /* original 430b, guest PC 0x0c0994e8 */
if(!s->budget--) { s->failed_pc=0x0c0994e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0994ecu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0994ecu) { target=s->pc; goto dispatch; }
goto P_0c0994ec;
P_0c0994ea: /* original 0009, guest PC 0x0c0994ea */
if(!s->budget--) { s->failed_pc=0x0c0994eau; return 0; }
goto P_0c0994ec;
P_0c0994ec: /* original 7f04, guest PC 0x0c0994ec */
if(!s->budget--) { s->failed_pc=0x0c0994ecu; return 0; }
r[15]+=0x00000004u;
goto P_0c0994ee;
P_0c0994ee: /* original 4f26, guest PC 0x0c0994ee */
if(!s->budget--) { s->failed_pc=0x0c0994eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0994f0;
P_0c0994f0: /* original 6bf6, guest PC 0x0c0994f0 */
if(!s->budget--) { s->failed_pc=0x0c0994f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0994f2;
P_0c0994f2: /* original 6cf6, guest PC 0x0c0994f2 */
if(!s->budget--) { s->failed_pc=0x0c0994f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0994f4;
P_0c0994f4: /* original 6df6, guest PC 0x0c0994f4 */
if(!s->budget--) { s->failed_pc=0x0c0994f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0994f6;
P_0c0994f6: /* original a000, guest PC 0x0c0994f6 */
if(!s->budget--) { s->failed_pc=0x0c0994f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0994fa;
P_0c0994f8: /* original 6ef6, guest PC 0x0c0994f8 */
if(!s->budget--) { s->failed_pc=0x0c0994f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0994fa;
P_0c0994fa: /* original 9053, guest PC 0x0c0994fa */
if(!s->budget--) { s->failed_pc=0x0c0994fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a4u,2);
goto P_0c0994fc;
P_0c0994fc: /* original e302, guest PC 0x0c0994fc */
if(!s->budget--) { s->failed_pc=0x0c0994fcu; return 0; }
r[3]=0x00000002u;
goto P_0c0994fe;
P_0c0994fe: /* original d430, guest PC 0x0c0994fe */
if(!s->budget--) { s->failed_pc=0x0c0994feu; return 0; }
r[4]=read(ram,0x0c0995c0u,4);
goto P_0c099500;
P_0c099500: /* original a000, guest PC 0x0c099500 */
if(!s->budget--) { s->failed_pc=0x0c099500u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c099504;
P_0c099502: /* original 0434, guest PC 0x0c099502 */
if(!s->budget--) { s->failed_pc=0x0c099502u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c099504;
P_0c099504: /* original 2fe6, guest PC 0x0c099504 */
if(!s->budget--) { s->failed_pc=0x0c099504u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099506;
P_0c099506: /* original 904e, guest PC 0x0c099506 */
if(!s->budget--) { s->failed_pc=0x0c099506u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a6u,2);
goto P_0c099508;
P_0c099508: /* original de2d, guest PC 0x0c099508 */
if(!s->budget--) { s->failed_pc=0x0c099508u; return 0; }
r[14]=read(ram,0x0c0995c0u,4);
goto P_0c09950a;
P_0c09950a: /* original 4f22, guest PC 0x0c09950a */
if(!s->budget--) { s->failed_pc=0x0c09950au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09950c;
P_0c09950c: /* original 03ec, guest PC 0x0c09950c */
if(!s->budget--) { s->failed_pc=0x0c09950cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09950e;
P_0c09950e: /* original 2338, guest PC 0x0c09950e */
if(!s->budget--) { s->failed_pc=0x0c09950eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c099510;
P_0c099510: /* original 8b03, guest PC 0x0c099510 */
if(!s->budget--) { s->failed_pc=0x0c099510u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09951a; }
goto P_0c099512;
P_0c099512: /* original d32c, guest PC 0x0c099512 */
if(!s->budget--) { s->failed_pc=0x0c099512u; return 0; }
r[3]=read(ram,0x0c0995c4u,4);
goto P_0c099514;
P_0c099514: /* original 9048, guest PC 0x0c099514 */
if(!s->budget--) { s->failed_pc=0x0c099514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a8u,2);
goto P_0c099516;
P_0c099516: /* original 430b, guest PC 0x0c099516 */
if(!s->budget--) { s->failed_pc=0x0c099516u; return 0; }
target=r[3];
r[16]=code_base|0x0c09951au;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09951au) { target=s->pc; goto dispatch; }
goto P_0c09951a;
P_0c099518: /* original 04ee, guest PC 0x0c099518 */
if(!s->budget--) { s->failed_pc=0x0c099518u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09951a;
P_0c09951a: /* original 9046, guest PC 0x0c09951a */
if(!s->budget--) { s->failed_pc=0x0c09951au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995aau,2);
goto P_0c09951c;
P_0c09951c: /* original 02ec, guest PC 0x0c09951c */
if(!s->budget--) { s->failed_pc=0x0c09951cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09951e;
P_0c09951e: /* original 2228, guest PC 0x0c09951e */
if(!s->budget--) { s->failed_pc=0x0c09951eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c099520;
P_0c099520: /* original 8906, guest PC 0x0c099520 */
if(!s->budget--) { s->failed_pc=0x0c099520u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099530; }
goto P_0c099522;
P_0c099522: /* original 9040, guest PC 0x0c099522 */
if(!s->budget--) { s->failed_pc=0x0c099522u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a6u,2);
goto P_0c099524;
P_0c099524: /* original 03ec, guest PC 0x0c099524 */
if(!s->budget--) { s->failed_pc=0x0c099524u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099526;
P_0c099526: /* original 2338, guest PC 0x0c099526 */
if(!s->budget--) { s->failed_pc=0x0c099526u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c099528;
P_0c099528: /* original 8906, guest PC 0x0c099528 */
if(!s->budget--) { s->failed_pc=0x0c099528u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099538; }
goto P_0c09952a;
P_0c09952a: /* original 4f26, guest PC 0x0c09952a */
if(!s->budget--) { s->failed_pc=0x0c09952au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09952c;
P_0c09952c: /* original a018, guest PC 0x0c09952c */
if(!s->budget--) { s->failed_pc=0x0c09952cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099560;
P_0c09952e: /* original 6ef6, guest PC 0x0c09952e */
if(!s->budget--) { s->failed_pc=0x0c09952eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099530;
P_0c099530: /* original d325, guest PC 0x0c099530 */
if(!s->budget--) { s->failed_pc=0x0c099530u; return 0; }
r[3]=read(ram,0x0c0995c8u,4);
goto P_0c099532;
P_0c099532: /* original 903b, guest PC 0x0c099532 */
if(!s->budget--) { s->failed_pc=0x0c099532u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995acu,2);
goto P_0c099534;
P_0c099534: /* original 430b, guest PC 0x0c099534 */
if(!s->budget--) { s->failed_pc=0x0c099534u; return 0; }
target=r[3];
r[16]=code_base|0x0c099538u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099538u) { target=s->pc; goto dispatch; }
goto P_0c099538;
P_0c099536: /* original 04ee, guest PC 0x0c099536 */
if(!s->budget--) { s->failed_pc=0x0c099536u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c099538;
P_0c099538: /* original 4f26, guest PC 0x0c099538 */
if(!s->budget--) { s->failed_pc=0x0c099538u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09953a;
P_0c09953a: /* original d224, guest PC 0x0c09953a */
if(!s->budget--) { s->failed_pc=0x0c09953au; return 0; }
r[2]=read(ram,0x0c0995ccu,4);
goto P_0c09953c;
P_0c09953c: /* original 422b, guest PC 0x0c09953c */
if(!s->budget--) { s->failed_pc=0x0c09953cu; return 0; }
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
P_0c09953e: /* original 6ef6, guest PC 0x0c09953e */
if(!s->budget--) { s->failed_pc=0x0c09953eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099540;
P_0c099540: /* original 902f, guest PC 0x0c099540 */
if(!s->budget--) { s->failed_pc=0x0c099540u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a2u,2);
goto P_0c099542;
P_0c099542: /* original d41f, guest PC 0x0c099542 */
if(!s->budget--) { s->failed_pc=0x0c099542u; return 0; }
r[4]=read(ram,0x0c0995c0u,4);
goto P_0c099544;
P_0c099544: /* original 4f22, guest PC 0x0c099544 */
if(!s->budget--) { s->failed_pc=0x0c099544u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099546;
P_0c099546: /* original 034c, guest PC 0x0c099546 */
if(!s->budget--) { s->failed_pc=0x0c099546u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c099548;
P_0c099548: /* original 2338, guest PC 0x0c099548 */
if(!s->budget--) { s->failed_pc=0x0c099548u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09954a;
P_0c09954a: /* original 8b02, guest PC 0x0c09954a */
if(!s->budget--) { s->failed_pc=0x0c09954au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099552; }
goto P_0c09954c;
P_0c09954c: /* original d21b, guest PC 0x0c09954c */
if(!s->budget--) { s->failed_pc=0x0c09954cu; return 0; }
r[2]=read(ram,0x0c0995bcu,4);
goto P_0c09954e;
P_0c09954e: /* original 420b, guest PC 0x0c09954e */
if(!s->budget--) { s->failed_pc=0x0c09954eu; return 0; }
target=r[2];
r[16]=code_base|0x0c099552u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099552u) { target=s->pc; goto dispatch; }
goto P_0c099552;
P_0c099550: /* original 0009, guest PC 0x0c099550 */
if(!s->budget--) { s->failed_pc=0x0c099550u; return 0; }
goto P_0c099552;
P_0c099552: /* original d219, guest PC 0x0c099552 */
if(!s->budget--) { s->failed_pc=0x0c099552u; return 0; }
r[2]=read(ram,0x0c0995b8u,4);
goto P_0c099554;
P_0c099554: /* original d317, guest PC 0x0c099554 */
if(!s->budget--) { s->failed_pc=0x0c099554u; return 0; }
r[3]=read(ram,0x0c0995b4u,4);
goto P_0c099556;
P_0c099556: /* original d516, guest PC 0x0c099556 */
if(!s->budget--) { s->failed_pc=0x0c099556u; return 0; }
r[5]=read(ram,0x0c0995b0u,4);
goto P_0c099558;
P_0c099558: /* original 420b, guest PC 0x0c099558 */
if(!s->budget--) { s->failed_pc=0x0c099558u; return 0; }
target=r[2];
r[16]=code_base|0x0c09955cu;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09955cu) { target=s->pc; goto dispatch; }
goto P_0c09955c;
P_0c09955a: /* original 6432, guest PC 0x0c09955a */
if(!s->budget--) { s->failed_pc=0x0c09955au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c09955c;
P_0c09955c: /* original a000, guest PC 0x0c09955c */
if(!s->budget--) { s->failed_pc=0x0c09955cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099560;
P_0c09955e: /* original 4f26, guest PC 0x0c09955e */
if(!s->budget--) { s->failed_pc=0x0c09955eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099560;
P_0c099560: /* original 2fe6, guest PC 0x0c099560 */
if(!s->budget--) { s->failed_pc=0x0c099560u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099562;
P_0c099562: /* original e054, guest PC 0x0c099562 */
if(!s->budget--) { s->failed_pc=0x0c099562u; return 0; }
r[0]=0x00000054u;
goto P_0c099564;
P_0c099564: /* original 2fd6, guest PC 0x0c099564 */
if(!s->budget--) { s->failed_pc=0x0c099564u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099566;
P_0c099566: /* original 2fc6, guest PC 0x0c099566 */
if(!s->budget--) { s->failed_pc=0x0c099566u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099568;
P_0c099568: /* original 4f22, guest PC 0x0c099568 */
if(!s->budget--) { s->failed_pc=0x0c099568u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09956a;
P_0c09956a: /* original d319, guest PC 0x0c09956a */
if(!s->budget--) { s->failed_pc=0x0c09956au; return 0; }
r[3]=read(ram,0x0c0995d0u,4);
goto P_0c09956c;
P_0c09956c: /* original dd14, guest PC 0x0c09956c */
if(!s->budget--) { s->failed_pc=0x0c09956cu; return 0; }
r[13]=read(ram,0x0c0995c0u,4);
goto P_0c09956e;
P_0c09956e: /* original 7fe8, guest PC 0x0c09956e */
if(!s->budget--) { s->failed_pc=0x0c09956eu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c099570;
P_0c099570: /* original 1f32, guest PC 0x0c099570 */
if(!s->budget--) { s->failed_pc=0x0c099570u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c099572;
P_0c099572: /* original d319, guest PC 0x0c099572 */
if(!s->budget--) { s->failed_pc=0x0c099572u; return 0; }
r[3]=read(ram,0x0c0995d8u,4);
goto P_0c099574;
P_0c099574: /* original dc17, guest PC 0x0c099574 */
if(!s->budget--) { s->failed_pc=0x0c099574u; return 0; }
r[12]=read(ram,0x0c0995d4u,4);
goto P_0c099576;
P_0c099576: /* original 430b, guest PC 0x0c099576 */
if(!s->budget--) { s->failed_pc=0x0c099576u; return 0; }
target=r[3];
r[16]=code_base|0x0c09957au;
r[4]=read(ram,r[12]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09957au) { target=s->pc; goto dispatch; }
goto P_0c09957a;
P_0c099578: /* original 04ce, guest PC 0x0c099578 */
if(!s->budget--) { s->failed_pc=0x0c099578u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c09957a;
P_0c09957a: /* original 55c4, guest PC 0x0c09957a */
if(!s->budget--) { s->failed_pc=0x0c09957au; return 0; }
r[5]=read(ram,r[12]+16,4);
goto P_0c09957c;
P_0c09957c: /* original e401, guest PC 0x0c09957c */
if(!s->budget--) { s->failed_pc=0x0c09957cu; return 0; }
r[4]=0x00000001u;
goto P_0c09957e;
P_0c09957e: /* original 6252, guest PC 0x0c09957e */
if(!s->budget--) { s->failed_pc=0x0c09957eu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c099580;
P_0c099580: /* original 224b, guest PC 0x0c099580 */
if(!s->budget--) { s->failed_pc=0x0c099580u; return 0; }
r[2]|=r[4];
goto P_0c099582;
P_0c099582: /* original 2522, guest PC 0x0c099582 */
if(!s->budget--) { s->failed_pc=0x0c099582u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c099584;
P_0c099584: /* original 55c5, guest PC 0x0c099584 */
if(!s->budget--) { s->failed_pc=0x0c099584u; return 0; }
r[5]=read(ram,r[12]+20,4);
goto P_0c099586;
P_0c099586: /* original 6352, guest PC 0x0c099586 */
if(!s->budget--) { s->failed_pc=0x0c099586u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c099588;
P_0c099588: /* original 234b, guest PC 0x0c099588 */
if(!s->budget--) { s->failed_pc=0x0c099588u; return 0; }
r[3]|=r[4];
goto P_0c09958a;
P_0c09958a: /* original 2532, guest PC 0x0c09958a */
if(!s->budget--) { s->failed_pc=0x0c09958au; return 0; }
write(ram,r[5],r[3],4);
goto P_0c09958c;
P_0c09958c: /* original 900e, guest PC 0x0c09958c */
if(!s->budget--) { s->failed_pc=0x0c09958cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995acu,2);
goto P_0c09958e;
P_0c09958e: /* original 53c4, guest PC 0x0c09958e */
if(!s->budget--) { s->failed_pc=0x0c09958eu; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c099590;
P_0c099590: /* original 0ede, guest PC 0x0c099590 */
if(!s->budget--) { s->failed_pc=0x0c099590u; return 0; }
r[14]=read(ram,r[13]+r[0],4);
goto P_0c099592;
P_0c099592: /* original 33e0, guest PC 0x0c099592 */
if(!s->budget--) { s->failed_pc=0x0c099592u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[14])!=0);
goto P_0c099594;
P_0c099594: /* original 8b22, guest PC 0x0c099594 */
if(!s->budget--) { s->failed_pc=0x0c099594u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0995dc; }
goto P_0c099596;
P_0c099596: /* original 900a, guest PC 0x0c099596 */
if(!s->budget--) { s->failed_pc=0x0c099596u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995aeu,2);
goto P_0c099598;
P_0c099598: /* original 02dc, guest PC 0x0c099598 */
if(!s->budget--) { s->failed_pc=0x0c099598u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09959a;
P_0c09959a: /* original 2248, guest PC 0x0c09959a */
if(!s->budget--) { s->failed_pc=0x0c09959au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c09959c;
P_0c09959c: /* original 8b31, guest PC 0x0c09959c */
if(!s->budget--) { s->failed_pc=0x0c09959cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099602; }
goto P_0c09959e;
P_0c09959e: /* original a021, guest PC 0x0c09959e */
if(!s->budget--) { s->failed_pc=0x0c09959eu; return 0; }
goto P_0c0995e4;
P_0c0995a0: /* original 0009, guest PC 0x0c0995a0 */
if(!s->budget--) { s->failed_pc=0x0c0995a0u; return 0; }
return vf3_matrix_family(0x0c0995a2u,s,ram);
P_0c0995dc: /* original 9072, guest PC 0x0c0995dc */
if(!s->budget--) { s->failed_pc=0x0c0995dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c4u,2);
goto P_0c0995de;
P_0c0995de: /* original 00dc, guest PC 0x0c0995de */
if(!s->budget--) { s->failed_pc=0x0c0995deu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0995e0;
P_0c0995e0: /* original c802, guest PC 0x0c0995e0 */
if(!s->budget--) { s->failed_pc=0x0c0995e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0995e2;
P_0c0995e2: /* original 8b0e, guest PC 0x0c0995e2 */
if(!s->budget--) { s->failed_pc=0x0c0995e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099602; }
goto P_0c0995e4;
P_0c0995e4: /* original 906f, guest PC 0x0c0995e4 */
if(!s->budget--) { s->failed_pc=0x0c0995e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c6u,2);
goto P_0c0995e6;
P_0c0995e6: /* original 00ec, guest PC 0x0c0995e6 */
if(!s->budget--) { s->failed_pc=0x0c0995e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0995e8;
P_0c0995e8: /* original 600c, guest PC 0x0c0995e8 */
if(!s->budget--) { s->failed_pc=0x0c0995e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0995ea;
P_0c0995ea: /* original c840, guest PC 0x0c0995ea */
if(!s->budget--) { s->failed_pc=0x0c0995eau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0995ec;
P_0c0995ec: /* original 8b09, guest PC 0x0c0995ec */
if(!s->budget--) { s->failed_pc=0x0c0995ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099602; }
goto P_0c0995ee;
P_0c0995ee: /* original e018, guest PC 0x0c0995ee */
if(!s->budget--) { s->failed_pc=0x0c0995eeu; return 0; }
r[0]=0x00000018u;
goto P_0c0995f0;
P_0c0995f0: /* original d338, guest PC 0x0c0995f0 */
if(!s->budget--) { s->failed_pc=0x0c0995f0u; return 0; }
r[3]=read(ram,0x0c0996d4u,4);
goto P_0c0995f2;
P_0c0995f2: /* original f5e6, guest PC 0x0c0995f2 */
if(!s->budget--) { s->failed_pc=0x0c0995f2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0995f4;
P_0c0995f4: /* original 64f3, guest PC 0x0c0995f4 */
if(!s->budget--) { s->failed_pc=0x0c0995f4u; return 0; }
r[4]=r[15];
goto P_0c0995f6;
P_0c0995f6: /* original 740c, guest PC 0x0c0995f6 */
if(!s->budget--) { s->failed_pc=0x0c0995f6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0995f8;
P_0c0995f8: /* original e010, guest PC 0x0c0995f8 */
if(!s->budget--) { s->failed_pc=0x0c0995f8u; return 0; }
r[0]=0x00000010u;
goto P_0c0995fa;
P_0c0995fa: /* original 430b, guest PC 0x0c0995fa */
if(!s->budget--) { s->failed_pc=0x0c0995fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0995feu;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0995feu) { target=s->pc; goto dispatch; }
goto P_0c0995fe;
P_0c0995fc: /* original f4e6, guest PC 0x0c0995fc */
if(!s->budget--) { s->failed_pc=0x0c0995fcu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0995fe;
P_0c0995fe: /* original c804, guest PC 0x0c0995fe */
if(!s->budget--) { s->failed_pc=0x0c0995feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c099600;
P_0c099600: /* original 8b2c, guest PC 0x0c099600 */
if(!s->budget--) { s->failed_pc=0x0c099600u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09965c; }
goto P_0c099602;
P_0c099602: /* original e048, guest PC 0x0c099602 */
if(!s->budget--) { s->failed_pc=0x0c099602u; return 0; }
r[0]=0x00000048u;
goto P_0c099604;
P_0c099604: /* original 62e2, guest PC 0x0c099604 */
if(!s->budget--) { s->failed_pc=0x0c099604u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c099606;
P_0c099606: /* original 66f3, guest PC 0x0c099606 */
if(!s->budget--) { s->failed_pc=0x0c099606u; return 0; }
r[6]=r[15];
goto P_0c099608;
P_0c099608: /* original 65f3, guest PC 0x0c099608 */
if(!s->budget--) { s->failed_pc=0x0c099608u; return 0; }
r[5]=r[15];
goto P_0c09960a;
P_0c09960a: /* original 2f22, guest PC 0x0c09960a */
if(!s->budget--) { s->failed_pc=0x0c09960au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09960c;
P_0c09960c: /* original 7604, guest PC 0x0c09960c */
if(!s->budget--) { s->failed_pc=0x0c09960cu; return 0; }
r[6]+=0x00000004u;
goto P_0c09960e;
P_0c09960e: /* original 03ee, guest PC 0x0c09960e */
if(!s->budget--) { s->failed_pc=0x0c09960eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c099610;
P_0c099610: /* original 1f31, guest PC 0x0c099610 */
if(!s->budget--) { s->failed_pc=0x0c099610u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c099612;
P_0c099612: /* original d331, guest PC 0x0c099612 */
if(!s->budget--) { s->failed_pc=0x0c099612u; return 0; }
r[3]=read(ram,0x0c0996d8u,4);
goto P_0c099614;
P_0c099614: /* original 430b, guest PC 0x0c099614 */
if(!s->budget--) { s->failed_pc=0x0c099614u; return 0; }
target=r[3];
r[16]=code_base|0x0c099618u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099618u) { target=s->pc; goto dispatch; }
goto P_0c099618;
P_0c099616: /* original 64e3, guest PC 0x0c099616 */
if(!s->budget--) { s->failed_pc=0x0c099616u; return 0; }
r[4]=r[14];
goto P_0c099618;
P_0c099618: /* original 62f2, guest PC 0x0c099618 */
if(!s->budget--) { s->failed_pc=0x0c099618u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09961a;
P_0c09961a: /* original e048, guest PC 0x0c09961a */
if(!s->budget--) { s->failed_pc=0x0c09961au; return 0; }
r[0]=0x00000048u;
goto P_0c09961c;
P_0c09961c: /* original d32f, guest PC 0x0c09961c */
if(!s->budget--) { s->failed_pc=0x0c09961cu; return 0; }
r[3]=read(ram,0x0c0996dcu,4);
goto P_0c09961e;
P_0c09961e: /* original 223b, guest PC 0x0c09961e */
if(!s->budget--) { s->failed_pc=0x0c09961eu; return 0; }
r[2]|=r[3];
goto P_0c099620;
P_0c099620: /* original 6123, guest PC 0x0c099620 */
if(!s->budget--) { s->failed_pc=0x0c099620u; return 0; }
r[1]=r[2];
goto P_0c099622;
P_0c099622: /* original 2f22, guest PC 0x0c099622 */
if(!s->budget--) { s->failed_pc=0x0c099622u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c099624;
P_0c099624: /* original 2e22, guest PC 0x0c099624 */
if(!s->budget--) { s->failed_pc=0x0c099624u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c099626;
P_0c099626: /* original 52f1, guest PC 0x0c099626 */
if(!s->budget--) { s->failed_pc=0x0c099626u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c099628;
P_0c099628: /* original 0e26, guest PC 0x0c099628 */
if(!s->budget--) { s->failed_pc=0x0c099628u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09962a;
P_0c09962a: /* original e010, guest PC 0x0c09962a */
if(!s->budget--) { s->failed_pc=0x0c09962au; return 0; }
r[0]=0x00000010u;
goto P_0c09962c;
P_0c09962c: /* original 61e2, guest PC 0x0c09962c */
if(!s->budget--) { s->failed_pc=0x0c09962cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c09962e;
P_0c09962e: /* original 924b, guest PC 0x0c09962e */
if(!s->budget--) { s->failed_pc=0x0c09962eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c8u,2);
goto P_0c099630;
P_0c099630: /* original 2129, guest PC 0x0c099630 */
if(!s->budget--) { s->failed_pc=0x0c099630u; return 0; }
r[1]&=r[2];
goto P_0c099632;
P_0c099632: /* original 2e12, guest PC 0x0c099632 */
if(!s->budget--) { s->failed_pc=0x0c099632u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c099634;
P_0c099634: /* original f48d, guest PC 0x0c099634 */
if(!s->budget--) { s->failed_pc=0x0c099634u; return 0; }
fr[4]=0;
goto P_0c099636;
P_0c099636: /* original fe47, guest PC 0x0c099636 */
if(!s->budget--) { s->failed_pc=0x0c099636u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099638;
P_0c099638: /* original e018, guest PC 0x0c099638 */
if(!s->budget--) { s->failed_pc=0x0c099638u; return 0; }
r[0]=0x00000018u;
goto P_0c09963a;
P_0c09963a: /* original fe47, guest PC 0x0c09963a */
if(!s->budget--) { s->failed_pc=0x0c09963au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09963c;
P_0c09963c: /* original e024, guest PC 0x0c09963c */
if(!s->budget--) { s->failed_pc=0x0c09963cu; return 0; }
r[0]=0x00000024u;
goto P_0c09963e;
P_0c09963e: /* original fe47, guest PC 0x0c09963e */
if(!s->budget--) { s->failed_pc=0x0c09963eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099640;
P_0c099640: /* original e02c, guest PC 0x0c099640 */
if(!s->budget--) { s->failed_pc=0x0c099640u; return 0; }
r[0]=0x0000002cu;
goto P_0c099642;
P_0c099642: /* original fe47, guest PC 0x0c099642 */
if(!s->budget--) { s->failed_pc=0x0c099642u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099644;
P_0c099644: /* original 9041, guest PC 0x0c099644 */
if(!s->budget--) { s->failed_pc=0x0c099644u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996cau,2);
goto P_0c099646;
P_0c099646: /* original fe47, guest PC 0x0c099646 */
if(!s->budget--) { s->failed_pc=0x0c099646u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099648;
P_0c099648: /* original 7008, guest PC 0x0c099648 */
if(!s->budget--) { s->failed_pc=0x0c099648u; return 0; }
r[0]+=0x00000008u;
goto P_0c09964a;
P_0c09964a: /* original fe47, guest PC 0x0c09964a */
if(!s->budget--) { s->failed_pc=0x0c09964au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09964c;
P_0c09964c: /* original 903e, guest PC 0x0c09964c */
if(!s->budget--) { s->failed_pc=0x0c09964cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996ccu,2);
goto P_0c09964e;
P_0c09964e: /* original fe47, guest PC 0x0c09964e */
if(!s->budget--) { s->failed_pc=0x0c09964eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099650;
P_0c099650: /* original 7008, guest PC 0x0c099650 */
if(!s->budget--) { s->failed_pc=0x0c099650u; return 0; }
r[0]+=0x00000008u;
goto P_0c099652;
P_0c099652: /* original fe47, guest PC 0x0c099652 */
if(!s->budget--) { s->failed_pc=0x0c099652u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099654;
P_0c099654: /* original 9039, guest PC 0x0c099654 */
if(!s->budget--) { s->failed_pc=0x0c099654u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996cau,2);
goto P_0c099656;
P_0c099656: /* original fe47, guest PC 0x0c099656 */
if(!s->budget--) { s->failed_pc=0x0c099656u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099658;
P_0c099658: /* original 7008, guest PC 0x0c099658 */
if(!s->budget--) { s->failed_pc=0x0c099658u; return 0; }
r[0]+=0x00000008u;
goto P_0c09965a;
P_0c09965a: /* original fe47, guest PC 0x0c09965a */
if(!s->budget--) { s->failed_pc=0x0c09965au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09965c;
P_0c09965c: /* original 9037, guest PC 0x0c09965c */
if(!s->budget--) { s->failed_pc=0x0c09965cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996ceu,2);
goto P_0c09965e;
P_0c09965e: /* original e500, guest PC 0x0c09965e */
if(!s->budget--) { s->failed_pc=0x0c09965eu; return 0; }
r[5]=0x00000000u;
goto P_0c099660;
P_0c099660: /* original 0e56, guest PC 0x0c099660 */
if(!s->budget--) { s->failed_pc=0x0c099660u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c099662;
P_0c099662: /* original 700c, guest PC 0x0c099662 */
if(!s->budget--) { s->failed_pc=0x0c099662u; return 0; }
r[0]+=0x0000000cu;
goto P_0c099664;
P_0c099664: /* original 0e56, guest PC 0x0c099664 */
if(!s->budget--) { s->failed_pc=0x0c099664u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c099666;
P_0c099666: /* original 9033, guest PC 0x0c099666 */
if(!s->budget--) { s->failed_pc=0x0c099666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996d0u,2);
goto P_0c099668;
P_0c099668: /* original 04de, guest PC 0x0c099668 */
if(!s->budget--) { s->failed_pc=0x0c099668u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09966a;
P_0c09966a: /* original e018, guest PC 0x0c09966a */
if(!s->budget--) { s->failed_pc=0x0c09966au; return 0; }
r[0]=0x00000018u;
goto P_0c09966c;
P_0c09966c: /* original 00dc, guest PC 0x0c09966c */
if(!s->budget--) { s->failed_pc=0x0c09966cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09966e;
P_0c09966e: /* original 600c, guest PC 0x0c09966e */
if(!s->budget--) { s->failed_pc=0x0c09966eu; return 0; }
r[0]=r[0]&255u;
goto P_0c099670;
P_0c099670: /* original 8802, guest PC 0x0c099670 */
if(!s->budget--) { s->failed_pc=0x0c099670u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099672;
P_0c099672: /* original 8906, guest PC 0x0c099672 */
if(!s->budget--) { s->failed_pc=0x0c099672u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099682; }
goto P_0c099674;
P_0c099674: /* original e046, guest PC 0x0c099674 */
if(!s->budget--) { s->failed_pc=0x0c099674u; return 0; }
r[0]=0x00000046u;
goto P_0c099676;
P_0c099676: /* original 0455, guest PC 0x0c099676 */
if(!s->budget--) { s->failed_pc=0x0c099676u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c099678;
P_0c099678: /* original 9025, guest PC 0x0c099678 */
if(!s->budget--) { s->failed_pc=0x0c099678u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c6u,2);
goto P_0c09967a;
P_0c09967a: /* original 004c, guest PC 0x0c09967a */
if(!s->budget--) { s->failed_pc=0x0c09967au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09967c;
P_0c09967c: /* original 600c, guest PC 0x0c09967c */
if(!s->budget--) { s->failed_pc=0x0c09967cu; return 0; }
r[0]=r[0]&255u;
goto P_0c09967e;
P_0c09967e: /* original c840, guest PC 0x0c09967e */
if(!s->budget--) { s->failed_pc=0x0c09967eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c099680;
P_0c099680: /* original 8b07, guest PC 0x0c099680 */
if(!s->budget--) { s->failed_pc=0x0c099680u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099692; }
goto P_0c099682;
P_0c099682: /* original 6242, guest PC 0x0c099682 */
if(!s->budget--) { s->failed_pc=0x0c099682u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c099684;
P_0c099684: /* original d316, guest PC 0x0c099684 */
if(!s->budget--) { s->failed_pc=0x0c099684u; return 0; }
r[3]=read(ram,0x0c0996e0u,4);
goto P_0c099686;
P_0c099686: /* original 2238, guest PC 0x0c099686 */
if(!s->budget--) { s->failed_pc=0x0c099686u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c099688;
P_0c099688: /* original 8b03, guest PC 0x0c099688 */
if(!s->budget--) { s->failed_pc=0x0c099688u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099692; }
goto P_0c09968a;
P_0c09968a: /* original d316, guest PC 0x0c09968a */
if(!s->budget--) { s->failed_pc=0x0c09968au; return 0; }
r[3]=read(ram,0x0c0996e4u,4);
goto P_0c09968c;
P_0c09968c: /* original 9020, guest PC 0x0c09968c */
if(!s->budget--) { s->failed_pc=0x0c09968cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996d0u,2);
goto P_0c09968e;
P_0c09968e: /* original 430b, guest PC 0x0c09968e */
if(!s->budget--) { s->failed_pc=0x0c09968eu; return 0; }
target=r[3];
r[16]=code_base|0x0c099692u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c099692u) { target=s->pc; goto dispatch; }
goto P_0c099692;
P_0c099690: /* original 04de, guest PC 0x0c099690 */
if(!s->budget--) { s->failed_pc=0x0c099690u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099692;
P_0c099692: /* original 901d, guest PC 0x0c099692 */
if(!s->budget--) { s->failed_pc=0x0c099692u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996d0u,2);
goto P_0c099694;
P_0c099694: /* original d314, guest PC 0x0c099694 */
if(!s->budget--) { s->failed_pc=0x0c099694u; return 0; }
r[3]=read(ram,0x0c0996e8u,4);
goto P_0c099696;
P_0c099696: /* original 05de, guest PC 0x0c099696 */
if(!s->budget--) { s->failed_pc=0x0c099696u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c099698;
P_0c099698: /* original 70fc, guest PC 0x0c099698 */
if(!s->budget--) { s->failed_pc=0x0c099698u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09969a;
P_0c09969a: /* original 430b, guest PC 0x0c09969a */
if(!s->budget--) { s->failed_pc=0x0c09969au; return 0; }
target=r[3];
r[16]=code_base|0x0c09969eu;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09969eu) { target=s->pc; goto dispatch; }
goto P_0c09969e;
P_0c09969c: /* original 04de, guest PC 0x0c09969c */
if(!s->budget--) { s->failed_pc=0x0c09969cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09969e;
P_0c09969e: /* original c713, guest PC 0x0c09969e */
if(!s->budget--) { s->failed_pc=0x0c09969eu; return 0; }
r[0]=0x0c0996ecu;
goto P_0c0996a0;
P_0c0996a0: /* original f308, guest PC 0x0c0996a0 */
if(!s->budget--) { s->failed_pc=0x0c0996a0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0996a2;
P_0c0996a2: /* original fd3a, guest PC 0x0c0996a2 */
if(!s->budget--) { s->failed_pc=0x0c0996a2u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c0996a4;
P_0c0996a4: /* original 52d2, guest PC 0x0c0996a4 */
if(!s->budget--) { s->failed_pc=0x0c0996a4u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0996a6;
P_0c0996a6: /* original 930f, guest PC 0x0c0996a6 */
if(!s->budget--) { s->failed_pc=0x0c0996a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c8u,2);
goto P_0c0996a8;
P_0c0996a8: /* original 2239, guest PC 0x0c0996a8 */
if(!s->budget--) { s->failed_pc=0x0c0996a8u; return 0; }
r[2]&=r[3];
goto P_0c0996aa;
P_0c0996aa: /* original 1d22, guest PC 0x0c0996aa */
if(!s->budget--) { s->failed_pc=0x0c0996aau; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0996ac;
P_0c0996ac: /* original 51f2, guest PC 0x0c0996ac */
if(!s->budget--) { s->failed_pc=0x0c0996acu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0996ae;
P_0c0996ae: /* original d210, guest PC 0x0c0996ae */
if(!s->budget--) { s->failed_pc=0x0c0996aeu; return 0; }
r[2]=read(ram,0x0c0996f0u,4);
goto P_0c0996b0;
P_0c0996b0: /* original 841b, guest PC 0x0c0996b0 */
if(!s->budget--) { s->failed_pc=0x0c0996b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+11,1);
goto P_0c0996b2;
P_0c0996b2: /* original 7001, guest PC 0x0c0996b2 */
if(!s->budget--) { s->failed_pc=0x0c0996b2u; return 0; }
r[0]+=0x00000001u;
goto P_0c0996b4;
P_0c0996b4: /* original 420b, guest PC 0x0c0996b4 */
if(!s->budget--) { s->failed_pc=0x0c0996b4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0996b8u;
write(ram,r[1]+11,r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0996b8u) { target=s->pc; goto dispatch; }
goto P_0c0996b8;
P_0c0996b6: /* original 801b, guest PC 0x0c0996b6 */
if(!s->budget--) { s->failed_pc=0x0c0996b6u; return 0; }
write(ram,r[1]+11,r[0],1);
goto P_0c0996b8;
P_0c0996b8: /* original 7f18, guest PC 0x0c0996b8 */
if(!s->budget--) { s->failed_pc=0x0c0996b8u; return 0; }
r[15]+=0x00000018u;
goto P_0c0996ba;
P_0c0996ba: /* original 4f26, guest PC 0x0c0996ba */
if(!s->budget--) { s->failed_pc=0x0c0996bau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0996bc;
P_0c0996bc: /* original 6cf6, guest PC 0x0c0996bc */
if(!s->budget--) { s->failed_pc=0x0c0996bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0996be;
P_0c0996be: /* original 6df6, guest PC 0x0c0996be */
if(!s->budget--) { s->failed_pc=0x0c0996beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0996c0;
P_0c0996c0: /* original 000b, guest PC 0x0c0996c0 */
if(!s->budget--) { s->failed_pc=0x0c0996c0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0996c2: /* original 6ef6, guest PC 0x0c0996c2 */
if(!s->budget--) { s->failed_pc=0x0c0996c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0996c4u,s,ram);
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
P_0c0a8aca: /* original 4f22, guest PC 0x0c0a8aca */
if(!s->budget--) { s->failed_pc=0x0c0a8acau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8acc;
P_0c0a8acc: /* original d34f, guest PC 0x0c0a8acc */
if(!s->budget--) { s->failed_pc=0x0c0a8accu; return 0; }
r[3]=read(ram,0x0c0a8c0cu,4);
goto P_0c0a8ace;
P_0c0a8ace: /* original 4f12, guest PC 0x0c0a8ace */
if(!s->budget--) { s->failed_pc=0x0c0a8aceu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8ad0;
P_0c0a8ad0: /* original 7ff8, guest PC 0x0c0a8ad0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a8ad2;
P_0c0a8ad2: /* original 430b, guest PC 0x0c0a8ad2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8ad6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8ad6u) { target=s->pc; goto dispatch; }
goto P_0c0a8ad6;
P_0c0a8ad4: /* original 0009, guest PC 0x0c0a8ad4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad4u; return 0; }
goto P_0c0a8ad6;
P_0c0a8ad6: /* original 2008, guest PC 0x0c0a8ad6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8ad8;
P_0c0a8ad8: /* original 8b01, guest PC 0x0c0a8ad8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ad8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8ade; }
goto P_0c0a8ada;
P_0c0a8ada: /* original a11d, guest PC 0x0c0a8ada */
if(!s->budget--) { s->failed_pc=0x0c0a8adau; return 0; }
goto P_0c0a8d18;
P_0c0a8adc: /* original 0009, guest PC 0x0c0a8adc */
if(!s->budget--) { s->failed_pc=0x0c0a8adcu; return 0; }
goto P_0c0a8ade;
P_0c0a8ade: /* original de4c, guest PC 0x0c0a8ade */
if(!s->budget--) { s->failed_pc=0x0c0a8adeu; return 0; }
r[14]=read(ram,0x0c0a8c10u,4);
goto P_0c0a8ae0;
P_0c0a8ae0: /* original 53e4, guest PC 0x0c0a8ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae0u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0a8ae2;
P_0c0a8ae2: /* original 2f32, guest PC 0x0c0a8ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a8ae4;
P_0c0a8ae4: /* original 52e5, guest PC 0x0c0a8ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae4u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c0a8ae6;
P_0c0a8ae6: /* original 1f21, guest PC 0x0c0a8ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae6u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a8ae8;
P_0c0a8ae8: /* original dd4a, guest PC 0x0c0a8ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ae8u; return 0; }
r[13]=read(ram,0x0c0a8c14u,4);
goto P_0c0a8aea;
P_0c0a8aea: /* original 9085, guest PC 0x0c0a8aea */
if(!s->budget--) { s->failed_pc=0x0c0a8aeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bf8u,2);
goto P_0c0a8aec;
P_0c0a8aec: /* original 0bdc, guest PC 0x0c0a8aec */
if(!s->budget--) { s->failed_pc=0x0c0a8aecu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8aee;
P_0c0a8aee: /* original 64bc, guest PC 0x0c0a8aee */
if(!s->budget--) { s->failed_pc=0x0c0a8aeeu; return 0; }
r[4]=r[11]&255u;
goto P_0c0a8af0;
P_0c0a8af0: /* original 6043, guest PC 0x0c0a8af0 */
if(!s->budget--) { s->failed_pc=0x0c0a8af0u; return 0; }
r[0]=r[4];
goto P_0c0a8af2;
P_0c0a8af2: /* original 8802, guest PC 0x0c0a8af2 */
if(!s->budget--) { s->failed_pc=0x0c0a8af2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a8af4;
P_0c0a8af4: /* original 8b03, guest PC 0x0c0a8af4 */
if(!s->budget--) { s->failed_pc=0x0c0a8af4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8afe; }
goto P_0c0a8af6;
P_0c0a8af6: /* original 9080, guest PC 0x0c0a8af6 */
if(!s->budget--) { s->failed_pc=0x0c0a8af6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bfau,2);
goto P_0c0a8af8;
P_0c0a8af8: /* original e20e, guest PC 0x0c0a8af8 */
if(!s->budget--) { s->failed_pc=0x0c0a8af8u; return 0; }
r[2]=0x0000000eu;
goto P_0c0a8afa;
P_0c0a8afa: /* original 55e8, guest PC 0x0c0a8afa */
if(!s->budget--) { s->failed_pc=0x0c0a8afau; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c0a8afc;
P_0c0a8afc: /* original 0524, guest PC 0x0c0a8afc */
if(!s->budget--) { s->failed_pc=0x0c0a8afcu; return 0; }
write(ram,r[5]+r[0],r[2],1);
goto P_0c0a8afe;
P_0c0a8afe: /* original 6043, guest PC 0x0c0a8afe */
if(!s->budget--) { s->failed_pc=0x0c0a8afeu; return 0; }
r[0]=r[4];
goto P_0c0a8b00;
P_0c0a8b00: /* original dc46, guest PC 0x0c0a8b00 */
if(!s->budget--) { s->failed_pc=0x0c0a8b00u; return 0; }
r[12]=read(ram,0x0c0a8c1cu,4);
goto P_0c0a8b02;
P_0c0a8b02: /* original da45, guest PC 0x0c0a8b02 */
if(!s->budget--) { s->failed_pc=0x0c0a8b02u; return 0; }
r[10]=read(ram,0x0c0a8c18u,4);
goto P_0c0a8b04;
P_0c0a8b04: /* original 8804, guest PC 0x0c0a8b04 */
if(!s->budget--) { s->failed_pc=0x0c0a8b04u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0a8b06;
P_0c0a8b06: /* original 8b04, guest PC 0x0c0a8b06 */
if(!s->budget--) { s->failed_pc=0x0c0a8b06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8b12; }
goto P_0c0a8b08;
P_0c0a8b08: /* original 9678, guest PC 0x0c0a8b08 */
if(!s->budget--) { s->failed_pc=0x0c0a8b08u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bfcu,2);
goto P_0c0a8b0a;
P_0c0a8b0a: /* original 9478, guest PC 0x0c0a8b0a */
if(!s->budget--) { s->failed_pc=0x0c0a8b0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bfeu,2);
goto P_0c0a8b0c;
P_0c0a8b0c: /* original 36cc, guest PC 0x0c0a8b0c */
if(!s->budget--) { s->failed_pc=0x0c0a8b0cu; return 0; }
r[6]+=r[12];
goto P_0c0a8b0e;
P_0c0a8b0e: /* original 4a0b, guest PC 0x0c0a8b0e */
if(!s->budget--) { s->failed_pc=0x0c0a8b0eu; return 0; }
target=r[10];
r[16]=code_base|0x0c0a8b12u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8b12u) { target=s->pc; goto dispatch; }
goto P_0c0a8b12;
P_0c0a8b10: /* original 65c3, guest PC 0x0c0a8b10 */
if(!s->budget--) { s->failed_pc=0x0c0a8b10u; return 0; }
r[5]=r[12];
goto P_0c0a8b12;
P_0c0a8b12: /* original 9075, guest PC 0x0c0a8b12 */
if(!s->budget--) { s->failed_pc=0x0c0a8b12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c00u,2);
goto P_0c0a8b14;
P_0c0a8b14: /* original e208, guest PC 0x0c0a8b14 */
if(!s->budget--) { s->failed_pc=0x0c0a8b14u; return 0; }
r[2]=0x00000008u;
goto P_0c0a8b16;
P_0c0a8b16: /* original 04dc, guest PC 0x0c0a8b16 */
if(!s->budget--) { s->failed_pc=0x0c0a8b16u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8b18;
P_0c0a8b18: /* original 3423, guest PC 0x0c0a8b18 */
if(!s->budget--) { s->failed_pc=0x0c0a8b18u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0a8b1a;
P_0c0a8b1a: /* original 8b01, guest PC 0x0c0a8b1a */
if(!s->budget--) { s->failed_pc=0x0c0a8b1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8b20; }
goto P_0c0a8b1c;
P_0c0a8b1c: /* original a0f4, guest PC 0x0c0a8b1c */
if(!s->budget--) { s->failed_pc=0x0c0a8b1cu; return 0; }
goto P_0c0a8d08;
P_0c0a8b1e: /* original 0009, guest PC 0x0c0a8b1e */
if(!s->budget--) { s->failed_pc=0x0c0a8b1eu; return 0; }
goto P_0c0a8b20;
P_0c0a8b20: /* original 936f, guest PC 0x0c0a8b20 */
if(!s->budget--) { s->failed_pc=0x0c0a8b20u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c02u,2);
goto P_0c0a8b22;
P_0c0a8b22: /* original 644e, guest PC 0x0c0a8b22 */
if(!s->budget--) { s->failed_pc=0x0c0a8b22u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8b24;
P_0c0a8b24: /* original 65bc, guest PC 0x0c0a8b24 */
if(!s->budget--) { s->failed_pc=0x0c0a8b24u; return 0; }
r[5]=r[11]&255u;
goto P_0c0a8b26;
P_0c0a8b26: /* original d23e, guest PC 0x0c0a8b26 */
if(!s->budget--) { s->failed_pc=0x0c0a8b26u; return 0; }
r[2]=read(ram,0x0c0a8c20u,4);
goto P_0c0a8b28;
P_0c0a8b28: /* original 243f, guest PC 0x0c0a8b28 */
if(!s->budget--) { s->failed_pc=0x0c0a8b28u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0a8b2a;
P_0c0a8b2a: /* original 4508, guest PC 0x0c0a8b2a */
if(!s->budget--) { s->failed_pc=0x0c0a8b2au; return 0; }
r[5]<<=2;
goto P_0c0a8b2c;
P_0c0a8b2c: /* original 4508, guest PC 0x0c0a8b2c */
if(!s->budget--) { s->failed_pc=0x0c0a8b2cu; return 0; }
r[5]<<=2;
goto P_0c0a8b2e;
P_0c0a8b2e: /* original 4508, guest PC 0x0c0a8b2e */
if(!s->budget--) { s->failed_pc=0x0c0a8b2eu; return 0; }
r[5]<<=2;
goto P_0c0a8b30;
P_0c0a8b30: /* original 041a, guest PC 0x0c0a8b30 */
if(!s->budget--) { s->failed_pc=0x0c0a8b30u; return 0; }
r[4]=r[19];
goto P_0c0a8b32;
P_0c0a8b32: /* original e01a, guest PC 0x0c0a8b32 */
if(!s->budget--) { s->failed_pc=0x0c0a8b32u; return 0; }
r[0]=0x0000001au;
goto P_0c0a8b34;
P_0c0a8b34: /* original 6b43, guest PC 0x0c0a8b34 */
if(!s->budget--) { s->failed_pc=0x0c0a8b34u; return 0; }
r[11]=r[4];
goto P_0c0a8b36;
P_0c0a8b36: /* original 3b5c, guest PC 0x0c0a8b36 */
if(!s->budget--) { s->failed_pc=0x0c0a8b36u; return 0; }
r[11]+=r[5];
goto P_0c0a8b38;
P_0c0a8b38: /* original 3b2c, guest PC 0x0c0a8b38 */
if(!s->budget--) { s->failed_pc=0x0c0a8b38u; return 0; }
r[11]+=r[2];
goto P_0c0a8b3a;
P_0c0a8b3a: /* original 04bc, guest PC 0x0c0a8b3a */
if(!s->budget--) { s->failed_pc=0x0c0a8b3au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0a8b3c;
P_0c0a8b3c: /* original 644c, guest PC 0x0c0a8b3c */
if(!s->budget--) { s->failed_pc=0x0c0a8b3cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0a8b3e;
P_0c0a8b3e: /* original 2448, guest PC 0x0c0a8b3e */
if(!s->budget--) { s->failed_pc=0x0c0a8b3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a8b40;
P_0c0a8b40: /* original 8911, guest PC 0x0c0a8b40 */
if(!s->budget--) { s->failed_pc=0x0c0a8b40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8b66; }
goto P_0c0a8b42;
P_0c0a8b42: /* original 55f1, guest PC 0x0c0a8b42 */
if(!s->budget--) { s->failed_pc=0x0c0a8b42u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0a8b44;
P_0c0a8b44: /* original 66b3, guest PC 0x0c0a8b44 */
if(!s->budget--) { s->failed_pc=0x0c0a8b44u; return 0; }
r[6]=r[11];
goto P_0c0a8b46;
P_0c0a8b46: /* original b107, guest PC 0x0c0a8b46 */
if(!s->budget--) { s->failed_pc=0x0c0a8b46u; return 0; }
target=0x0c0a8d58u; r[16]=code_base|0x0c0a8b4au;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8b4au) { target=s->pc; goto dispatch; }
goto P_0c0a8b4a;
P_0c0a8b48: /* original 64f2, guest PC 0x0c0a8b48 */
if(!s->budget--) { s->failed_pc=0x0c0a8b48u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a8b4a;
P_0c0a8b4a: /* original 54e5, guest PC 0x0c0a8b4a */
if(!s->budget--) { s->failed_pc=0x0c0a8b4au; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0a8b4c;
P_0c0a8b4c: /* original 7b20, guest PC 0x0c0a8b4c */
if(!s->budget--) { s->failed_pc=0x0c0a8b4cu; return 0; }
r[11]+=0x00000020u;
goto P_0c0a8b4e;
P_0c0a8b4e: /* original 55e4, guest PC 0x0c0a8b4e */
if(!s->budget--) { s->failed_pc=0x0c0a8b4eu; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0a8b50;
P_0c0a8b50: /* original b102, guest PC 0x0c0a8b50 */
if(!s->budget--) { s->failed_pc=0x0c0a8b50u; return 0; }
target=0x0c0a8d58u; r[16]=code_base|0x0c0a8b54u;
r[6]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8b54u) { target=s->pc; goto dispatch; }
goto P_0c0a8b54;
P_0c0a8b52: /* original 66b3, guest PC 0x0c0a8b52 */
if(!s->budget--) { s->failed_pc=0x0c0a8b52u; return 0; }
r[6]=r[11];
goto P_0c0a8b54;
P_0c0a8b54: /* original 9050, guest PC 0x0c0a8b54 */
if(!s->budget--) { s->failed_pc=0x0c0a8b54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8bf8u,2);
goto P_0c0a8b56;
P_0c0a8b56: /* original 9255, guest PC 0x0c0a8b56 */
if(!s->budget--) { s->failed_pc=0x0c0a8b56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c04u,2);
goto P_0c0a8b58;
P_0c0a8b58: /* original 04dc, guest PC 0x0c0a8b58 */
if(!s->budget--) { s->failed_pc=0x0c0a8b58u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8b5a;
P_0c0a8b5a: /* original 7401, guest PC 0x0c0a8b5a */
if(!s->budget--) { s->failed_pc=0x0c0a8b5au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8b5c;
P_0c0a8b5c: /* original 634c, guest PC 0x0c0a8b5c */
if(!s->budget--) { s->failed_pc=0x0c0a8b5cu; return 0; }
r[3]=r[4]&255u;
goto P_0c0a8b5e;
P_0c0a8b5e: /* original 3323, guest PC 0x0c0a8b5e */
if(!s->budget--) { s->failed_pc=0x0c0a8b5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0a8b60;
P_0c0a8b60: /* original 8901, guest PC 0x0c0a8b60 */
if(!s->budget--) { s->failed_pc=0x0c0a8b60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8b66; }
goto P_0c0a8b62;
P_0c0a8b62: /* original a099, guest PC 0x0c0a8b62 */
if(!s->budget--) { s->failed_pc=0x0c0a8b62u; return 0; }
goto P_0c0a8c98;
P_0c0a8b64: /* original 0009, guest PC 0x0c0a8b64 */
if(!s->budget--) { s->failed_pc=0x0c0a8b64u; return 0; }
goto P_0c0a8b66;
P_0c0a8b66: /* original 944e, guest PC 0x0c0a8b66 */
if(!s->budget--) { s->failed_pc=0x0c0a8b66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c06u,2);
goto P_0c0a8b68;
P_0c0a8b68: /* original 66c3, guest PC 0x0c0a8b68 */
if(!s->budget--) { s->failed_pc=0x0c0a8b68u; return 0; }
r[6]=r[12];
goto P_0c0a8b6a;
P_0c0a8b6a: /* original 7658, guest PC 0x0c0a8b6a */
if(!s->budget--) { s->failed_pc=0x0c0a8b6au; return 0; }
r[6]+=0x00000058u;
goto P_0c0a8b6c;
P_0c0a8b6c: /* original 4a0b, guest PC 0x0c0a8b6c */
if(!s->budget--) { s->failed_pc=0x0c0a8b6cu; return 0; }
target=r[10];
r[16]=code_base|0x0c0a8b70u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8b70u) { target=s->pc; goto dispatch; }
goto P_0c0a8b70;
P_0c0a8b6e: /* original 65c3, guest PC 0x0c0a8b6e */
if(!s->budget--) { s->failed_pc=0x0c0a8b6eu; return 0; }
r[5]=r[12];
goto P_0c0a8b70;
P_0c0a8b70: /* original 9046, guest PC 0x0c0a8b70 */
if(!s->budget--) { s->failed_pc=0x0c0a8b70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c00u,2);
goto P_0c0a8b72;
P_0c0a8b72: /* original e208, guest PC 0x0c0a8b72 */
if(!s->budget--) { s->failed_pc=0x0c0a8b72u; return 0; }
r[2]=0x00000008u;
goto P_0c0a8b74;
P_0c0a8b74: /* original 04dc, guest PC 0x0c0a8b74 */
if(!s->budget--) { s->failed_pc=0x0c0a8b74u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8b76;
P_0c0a8b76: /* original 7401, guest PC 0x0c0a8b76 */
if(!s->budget--) { s->failed_pc=0x0c0a8b76u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8b78;
P_0c0a8b78: /* original 634e, guest PC 0x0c0a8b78 */
if(!s->budget--) { s->failed_pc=0x0c0a8b78u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8b7a;
P_0c0a8b7a: /* original 3323, guest PC 0x0c0a8b7a */
if(!s->budget--) { s->failed_pc=0x0c0a8b7au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0a8b7c;
P_0c0a8b7c: /* original 8f02, guest PC 0x0c0a8b7c */
if(!s->budget--) { s->failed_pc=0x0c0a8b7cu; return 0; }
cond=r[17]&1u;
write(ram,r[13]+r[0],r[4],1);
if(!cond) { goto P_0c0a8b84; }
goto P_0c0a8b80;
P_0c0a8b7e: /* original 0d44, guest PC 0x0c0a8b7e */
if(!s->budget--) { s->failed_pc=0x0c0a8b7eu; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0a8b80;
P_0c0a8b80: /* original a0c2, guest PC 0x0c0a8b80 */
if(!s->budget--) { s->failed_pc=0x0c0a8b80u; return 0; }
goto P_0c0a8d08;
P_0c0a8b82: /* original 0009, guest PC 0x0c0a8b82 */
if(!s->budget--) { s->failed_pc=0x0c0a8b82u; return 0; }
goto P_0c0a8b84;
P_0c0a8b84: /* original 6c4e, guest PC 0x0c0a8b84 */
if(!s->budget--) { s->failed_pc=0x0c0a8b84u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8b86;
P_0c0a8b86: /* original 923f, guest PC 0x0c0a8b86 */
if(!s->budget--) { s->failed_pc=0x0c0a8b86u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c08u,2);
goto P_0c0a8b88;
P_0c0a8b88: /* original 63c3, guest PC 0x0c0a8b88 */
if(!s->budget--) { s->failed_pc=0x0c0a8b88u; return 0; }
r[3]=r[12];
goto P_0c0a8b8a;
P_0c0a8b8a: /* original 4c00, guest PC 0x0c0a8b8a */
if(!s->budget--) { s->failed_pc=0x0c0a8b8au; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0a8b8c;
P_0c0a8b8c: /* original 32dc, guest PC 0x0c0a8b8c */
if(!s->budget--) { s->failed_pc=0x0c0a8b8cu; return 0; }
r[2]+=r[13];
goto P_0c0a8b8e;
P_0c0a8b8e: /* original 57e5, guest PC 0x0c0a8b8e */
if(!s->budget--) { s->failed_pc=0x0c0a8b8eu; return 0; }
r[7]=read(ram,r[14]+20,4);
goto P_0c0a8b90;
P_0c0a8b90: /* original 3c3c, guest PC 0x0c0a8b90 */
if(!s->budget--) { s->failed_pc=0x0c0a8b90u; return 0; }
r[12]+=r[3];
goto P_0c0a8b92;
P_0c0a8b92: /* original 56e4, guest PC 0x0c0a8b92 */
if(!s->budget--) { s->failed_pc=0x0c0a8b92u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c0a8b94;
P_0c0a8b94: /* original 3c2c, guest PC 0x0c0a8b94 */
if(!s->budget--) { s->failed_pc=0x0c0a8b94u; return 0; }
r[12]+=r[2];
goto P_0c0a8b96;
P_0c0a8b96: /* original 63c0, guest PC 0x0c0a8b96 */
if(!s->budget--) { s->failed_pc=0x0c0a8b96u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[3]=tmp;
goto P_0c0a8b98;
P_0c0a8b98: /* original e20d, guest PC 0x0c0a8b98 */
if(!s->budget--) { s->failed_pc=0x0c0a8b98u; return 0; }
r[2]=0x0000000du;
goto P_0c0a8b9a;
P_0c0a8b9a: /* original 2f30, guest PC 0x0c0a8b9a */
if(!s->budget--) { s->failed_pc=0x0c0a8b9au; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0a8b9c;
P_0c0a8b9c: /* original 84c1, guest PC 0x0c0a8b9c */
if(!s->budget--) { s->failed_pc=0x0c0a8b9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+1,1);
goto P_0c0a8b9e;
P_0c0a8b9e: /* original 6503, guest PC 0x0c0a8b9e */
if(!s->budget--) { s->failed_pc=0x0c0a8b9eu; return 0; }
r[5]=r[0];
goto P_0c0a8ba0;
P_0c0a8ba0: /* original 84c2, guest PC 0x0c0a8ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+2,1);
goto P_0c0a8ba2;
P_0c0a8ba2: /* original 635e, guest PC 0x0c0a8ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0a8ba4;
P_0c0a8ba4: /* original 6403, guest PC 0x0c0a8ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba4u; return 0; }
r[4]=r[0];
goto P_0c0a8ba6;
P_0c0a8ba6: /* original 3323, guest PC 0x0c0a8ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0a8ba8;
P_0c0a8ba8: /* original e060, guest PC 0x0c0a8ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ba8u; return 0; }
r[0]=0x00000060u;
goto P_0c0a8baa;
P_0c0a8baa: /* original 8f01, guest PC 0x0c0a8baa */
if(!s->budget--) { s->failed_pc=0x0c0a8baau; return 0; }
cond=r[17]&1u;
write(ram,r[6]+r[0],r[5],1);
if(!cond) { goto P_0c0a8bb0; }
goto P_0c0a8bae;
P_0c0a8bac: /* original 0654, guest PC 0x0c0a8bac */
if(!s->budget--) { s->failed_pc=0x0c0a8bacu; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c0a8bae;
P_0c0a8bae: /* original 3528, guest PC 0x0c0a8bae */
if(!s->budget--) { s->failed_pc=0x0c0a8baeu; return 0; }
r[5]-=r[2];
goto P_0c0a8bb0;
P_0c0a8bb0: /* original e061, guest PC 0x0c0a8bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb0u; return 0; }
r[0]=0x00000061u;
goto P_0c0a8bb2;
P_0c0a8bb2: /* original 634e, guest PC 0x0c0a8bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8bb4;
P_0c0a8bb4: /* original 0654, guest PC 0x0c0a8bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb4u; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c0a8bb6;
P_0c0a8bb6: /* original e20d, guest PC 0x0c0a8bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb6u; return 0; }
r[2]=0x0000000du;
goto P_0c0a8bb8;
P_0c0a8bb8: /* original 3323, guest PC 0x0c0a8bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a8bb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0a8bba;
P_0c0a8bba: /* original e060, guest PC 0x0c0a8bba */
if(!s->budget--) { s->failed_pc=0x0c0a8bbau; return 0; }
r[0]=0x00000060u;
goto P_0c0a8bbc;
P_0c0a8bbc: /* original 8f01, guest PC 0x0c0a8bbc */
if(!s->budget--) { s->failed_pc=0x0c0a8bbcu; return 0; }
cond=r[17]&1u;
write(ram,r[7]+r[0],r[4],1);
if(!cond) { goto P_0c0a8bc2; }
goto P_0c0a8bc0;
P_0c0a8bbe: /* original 0744, guest PC 0x0c0a8bbe */
if(!s->budget--) { s->failed_pc=0x0c0a8bbeu; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c0a8bc0;
P_0c0a8bc0: /* original 3428, guest PC 0x0c0a8bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc0u; return 0; }
r[4]-=r[2];
goto P_0c0a8bc2;
P_0c0a8bc2: /* original e061, guest PC 0x0c0a8bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc2u; return 0; }
r[0]=0x00000061u;
goto P_0c0a8bc4;
P_0c0a8bc4: /* original 0744, guest PC 0x0c0a8bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc4u; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c0a8bc6;
P_0c0a8bc6: /* original d217, guest PC 0x0c0a8bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc6u; return 0; }
r[2]=read(ram,0x0c0a8c24u,4);
goto P_0c0a8bc8;
P_0c0a8bc8: /* original d117, guest PC 0x0c0a8bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8bc8u; return 0; }
r[1]=read(ram,0x0c0a8c28u,4);
goto P_0c0a8bca;
P_0c0a8bca: /* original 63f0, guest PC 0x0c0a8bca */
if(!s->budget--) { s->failed_pc=0x0c0a8bcau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c0a8bcc;
P_0c0a8bcc: /* original 410b, guest PC 0x0c0a8bcc */
if(!s->budget--) { s->failed_pc=0x0c0a8bccu; return 0; }
target=r[1];
r[16]=code_base|0x0c0a8bd0u;
write(ram,r[2],r[3],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8bd0u) { target=s->pc; goto dispatch; }
goto P_0c0a8bd0;
P_0c0a8bce: /* original 2230, guest PC 0x0c0a8bce */
if(!s->budget--) { s->failed_pc=0x0c0a8bceu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c0a8bd0;
P_0c0a8bd0: /* original d316, guest PC 0x0c0a8bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd0u; return 0; }
r[3]=read(ram,0x0c0a8c2cu,4);
goto P_0c0a8bd2;
P_0c0a8bd2: /* original 430b, guest PC 0x0c0a8bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8bd6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8bd6u) { target=s->pc; goto dispatch; }
goto P_0c0a8bd6;
P_0c0a8bd4: /* original 0009, guest PC 0x0c0a8bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd4u; return 0; }
goto P_0c0a8bd6;
P_0c0a8bd6: /* original d516, guest PC 0x0c0a8bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd6u; return 0; }
r[5]=read(ram,0x0c0a8c30u,4);
goto P_0c0a8bd8;
P_0c0a8bd8: /* original e201, guest PC 0x0c0a8bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8bd8u; return 0; }
r[2]=0x00000001u;
goto P_0c0a8bda;
P_0c0a8bda: /* original 5451, guest PC 0x0c0a8bda */
if(!s->budget--) { s->failed_pc=0x0c0a8bdau; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c0a8bdc;
P_0c0a8bdc: /* original 242b, guest PC 0x0c0a8bdc */
if(!s->budget--) { s->failed_pc=0x0c0a8bdcu; return 0; }
r[4]|=r[2];
goto P_0c0a8bde;
P_0c0a8bde: /* original 1541, guest PC 0x0c0a8bde */
if(!s->budget--) { s->failed_pc=0x0c0a8bdeu; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c0a8be0;
P_0c0a8be0: /* original 900e, guest PC 0x0c0a8be0 */
if(!s->budget--) { s->failed_pc=0x0c0a8be0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c00u,2);
goto P_0c0a8be2;
P_0c0a8be2: /* original 9312, guest PC 0x0c0a8be2 */
if(!s->budget--) { s->failed_pc=0x0c0a8be2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8c0au,2);
goto P_0c0a8be4;
P_0c0a8be4: /* original 04dc, guest PC 0x0c0a8be4 */
if(!s->budget--) { s->failed_pc=0x0c0a8be4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8be6;
P_0c0a8be6: /* original 33dc, guest PC 0x0c0a8be6 */
if(!s->budget--) { s->failed_pc=0x0c0a8be6u; return 0; }
r[3]+=r[13];
goto P_0c0a8be8;
P_0c0a8be8: /* original d112, guest PC 0x0c0a8be8 */
if(!s->budget--) { s->failed_pc=0x0c0a8be8u; return 0; }
r[1]=read(ram,0x0c0a8c34u,4);
goto P_0c0a8bea;
P_0c0a8bea: /* original 654e, guest PC 0x0c0a8bea */
if(!s->budget--) { s->failed_pc=0x0c0a8beau; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8bec;
P_0c0a8bec: /* original 4508, guest PC 0x0c0a8bec */
if(!s->budget--) { s->failed_pc=0x0c0a8becu; return 0; }
r[5]<<=2;
goto P_0c0a8bee;
P_0c0a8bee: /* original 353c, guest PC 0x0c0a8bee */
if(!s->budget--) { s->failed_pc=0x0c0a8beeu; return 0; }
r[5]+=r[3];
goto P_0c0a8bf0;
P_0c0a8bf0: /* original 6552, guest PC 0x0c0a8bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a8bf0u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0a8bf2;
P_0c0a8bf2: /* original 2152, guest PC 0x0c0a8bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a8bf2u; return 0; }
write(ram,r[1],r[5],4);
goto P_0c0a8bf4;
P_0c0a8bf4: /* original a020, guest PC 0x0c0a8bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a8bf4u; return 0; }
goto P_0c0a8c38;
P_0c0a8bf6: /* original 0009, guest PC 0x0c0a8bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a8bf6u; return 0; }
return vf3_matrix_family(0x0c0a8bf8u,s,ram);
P_0c0a8c38: /* original 9377, guest PC 0x0c0a8c38 */
if(!s->budget--) { s->failed_pc=0x0c0a8c38u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8d2au,2);
goto P_0c0a8c3a;
P_0c0a8c3a: /* original 644e, guest PC 0x0c0a8c3a */
if(!s->budget--) { s->failed_pc=0x0c0a8c3au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8c3c;
P_0c0a8c3c: /* original 70ff, guest PC 0x0c0a8c3c */
if(!s->budget--) { s->failed_pc=0x0c0a8c3cu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a8c3e;
P_0c0a8c3e: /* original d23d, guest PC 0x0c0a8c3e */
if(!s->budget--) { s->failed_pc=0x0c0a8c3eu; return 0; }
r[2]=read(ram,0x0c0a8d34u,4);
goto P_0c0a8c40;
P_0c0a8c40: /* original 243f, guest PC 0x0c0a8c40 */
if(!s->budget--) { s->failed_pc=0x0c0a8c40u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0a8c42;
P_0c0a8c42: /* original 05dc, guest PC 0x0c0a8c42 */
if(!s->budget--) { s->failed_pc=0x0c0a8c42u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8c44;
P_0c0a8c44: /* original e004, guest PC 0x0c0a8c44 */
if(!s->budget--) { s->failed_pc=0x0c0a8c44u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8c46;
P_0c0a8c46: /* original 655c, guest PC 0x0c0a8c46 */
if(!s->budget--) { s->failed_pc=0x0c0a8c46u; return 0; }
r[5]=r[5]&255u;
goto P_0c0a8c48;
P_0c0a8c48: /* original 041a, guest PC 0x0c0a8c48 */
if(!s->budget--) { s->failed_pc=0x0c0a8c48u; return 0; }
r[4]=r[19];
goto P_0c0a8c4a;
P_0c0a8c4a: /* original 4508, guest PC 0x0c0a8c4a */
if(!s->budget--) { s->failed_pc=0x0c0a8c4au; return 0; }
r[5]<<=2;
goto P_0c0a8c4c;
P_0c0a8c4c: /* original 4508, guest PC 0x0c0a8c4c */
if(!s->budget--) { s->failed_pc=0x0c0a8c4cu; return 0; }
r[5]<<=2;
goto P_0c0a8c4e;
P_0c0a8c4e: /* original 6c43, guest PC 0x0c0a8c4e */
if(!s->budget--) { s->failed_pc=0x0c0a8c4eu; return 0; }
r[12]=r[4];
goto P_0c0a8c50;
P_0c0a8c50: /* original 4508, guest PC 0x0c0a8c50 */
if(!s->budget--) { s->failed_pc=0x0c0a8c50u; return 0; }
r[5]<<=2;
goto P_0c0a8c52;
P_0c0a8c52: /* original 3c5c, guest PC 0x0c0a8c52 */
if(!s->budget--) { s->failed_pc=0x0c0a8c52u; return 0; }
r[12]+=r[5];
goto P_0c0a8c54;
P_0c0a8c54: /* original 3c2c, guest PC 0x0c0a8c54 */
if(!s->budget--) { s->failed_pc=0x0c0a8c54u; return 0; }
r[12]+=r[2];
goto P_0c0a8c56;
P_0c0a8c56: /* original f4c6, guest PC 0x0c0a8c56 */
if(!s->budget--) { s->failed_pc=0x0c0a8c56u; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c0a8c58;
P_0c0a8c58: /* original e008, guest PC 0x0c0a8c58 */
if(!s->budget--) { s->failed_pc=0x0c0a8c58u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8c5a;
P_0c0a8c5a: /* original f5c6, guest PC 0x0c0a8c5a */
if(!s->budget--) { s->failed_pc=0x0c0a8c5au; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c0a8c5c;
P_0c0a8c5c: /* original e00c, guest PC 0x0c0a8c5c */
if(!s->budget--) { s->failed_pc=0x0c0a8c5cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8c5e;
P_0c0a8c5e: /* original f6c6, guest PC 0x0c0a8c5e */
if(!s->budget--) { s->failed_pc=0x0c0a8c5eu; return 0; }
vf3_matrix_load(s,ram,6,r[12]+r[0]);
goto P_0c0a8c60;
P_0c0a8c60: /* original 85ca, guest PC 0x0c0a8c60 */
if(!s->budget--) { s->failed_pc=0x0c0a8c60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+20,2);
goto P_0c0a8c62;
P_0c0a8c62: /* original 81f2, guest PC 0x0c0a8c62 */
if(!s->budget--) { s->failed_pc=0x0c0a8c62u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0a8c64;
P_0c0a8c64: /* original 51e4, guest PC 0x0c0a8c64 */
if(!s->budget--) { s->failed_pc=0x0c0a8c64u; return 0; }
r[1]=read(ram,r[14]+16,4);
goto P_0c0a8c66;
P_0c0a8c66: /* original 6413, guest PC 0x0c0a8c66 */
if(!s->budget--) { s->failed_pc=0x0c0a8c66u; return 0; }
r[4]=r[1];
goto P_0c0a8c68;
P_0c0a8c68: /* original 2f12, guest PC 0x0c0a8c68 */
if(!s->budget--) { s->failed_pc=0x0c0a8c68u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0a8c6a;
P_0c0a8c6a: /* original 85f2, guest PC 0x0c0a8c6a */
if(!s->budget--) { s->failed_pc=0x0c0a8c6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0a8c6c;
P_0c0a8c6c: /* original d132, guest PC 0x0c0a8c6c */
if(!s->budget--) { s->failed_pc=0x0c0a8c6cu; return 0; }
r[1]=read(ram,0x0c0a8d38u,4);
goto P_0c0a8c6e;
P_0c0a8c6e: /* original 6603, guest PC 0x0c0a8c6e */
if(!s->budget--) { s->failed_pc=0x0c0a8c6eu; return 0; }
r[6]=r[0];
goto P_0c0a8c70;
P_0c0a8c70: /* original 410b, guest PC 0x0c0a8c70 */
if(!s->budget--) { s->failed_pc=0x0c0a8c70u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a8c74u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8c74u) { target=s->pc; goto dispatch; }
goto P_0c0a8c74;
P_0c0a8c72: /* original e500, guest PC 0x0c0a8c72 */
if(!s->budget--) { s->failed_pc=0x0c0a8c72u; return 0; }
r[5]=0x00000000u;
goto P_0c0a8c74;
P_0c0a8c74: /* original e004, guest PC 0x0c0a8c74 */
if(!s->budget--) { s->failed_pc=0x0c0a8c74u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8c76;
P_0c0a8c76: /* original 7c20, guest PC 0x0c0a8c76 */
if(!s->budget--) { s->failed_pc=0x0c0a8c76u; return 0; }
r[12]+=0x00000020u;
goto P_0c0a8c78;
P_0c0a8c78: /* original f4c6, guest PC 0x0c0a8c78 */
if(!s->budget--) { s->failed_pc=0x0c0a8c78u; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c0a8c7a;
P_0c0a8c7a: /* original e008, guest PC 0x0c0a8c7a */
if(!s->budget--) { s->failed_pc=0x0c0a8c7au; return 0; }
r[0]=0x00000008u;
goto P_0c0a8c7c;
P_0c0a8c7c: /* original f5c6, guest PC 0x0c0a8c7c */
if(!s->budget--) { s->failed_pc=0x0c0a8c7cu; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c0a8c7e;
P_0c0a8c7e: /* original e00c, guest PC 0x0c0a8c7e */
if(!s->budget--) { s->failed_pc=0x0c0a8c7eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8c80;
P_0c0a8c80: /* original f6c6, guest PC 0x0c0a8c80 */
if(!s->budget--) { s->failed_pc=0x0c0a8c80u; return 0; }
vf3_matrix_load(s,ram,6,r[12]+r[0]);
goto P_0c0a8c82;
P_0c0a8c82: /* original 85ca, guest PC 0x0c0a8c82 */
if(!s->budget--) { s->failed_pc=0x0c0a8c82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+20,2);
goto P_0c0a8c84;
P_0c0a8c84: /* original 81f2, guest PC 0x0c0a8c84 */
if(!s->budget--) { s->failed_pc=0x0c0a8c84u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0a8c86;
P_0c0a8c86: /* original 53e5, guest PC 0x0c0a8c86 */
if(!s->budget--) { s->failed_pc=0x0c0a8c86u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c0a8c88;
P_0c0a8c88: /* original 6433, guest PC 0x0c0a8c88 */
if(!s->budget--) { s->failed_pc=0x0c0a8c88u; return 0; }
r[4]=r[3];
goto P_0c0a8c8a;
P_0c0a8c8a: /* original 2f32, guest PC 0x0c0a8c8a */
if(!s->budget--) { s->failed_pc=0x0c0a8c8au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a8c8c;
P_0c0a8c8c: /* original 85f2, guest PC 0x0c0a8c8c */
if(!s->budget--) { s->failed_pc=0x0c0a8c8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0a8c8e;
P_0c0a8c8e: /* original d32a, guest PC 0x0c0a8c8e */
if(!s->budget--) { s->failed_pc=0x0c0a8c8eu; return 0; }
r[3]=read(ram,0x0c0a8d38u,4);
goto P_0c0a8c90;
P_0c0a8c90: /* original 6603, guest PC 0x0c0a8c90 */
if(!s->budget--) { s->failed_pc=0x0c0a8c90u; return 0; }
r[6]=r[0];
goto P_0c0a8c92;
P_0c0a8c92: /* original 430b, guest PC 0x0c0a8c92 */
if(!s->budget--) { s->failed_pc=0x0c0a8c92u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8c96u;
r[5]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8c96u) { target=s->pc; goto dispatch; }
goto P_0c0a8c96;
P_0c0a8c94: /* original e501, guest PC 0x0c0a8c94 */
if(!s->budget--) { s->failed_pc=0x0c0a8c94u; return 0; }
r[5]=0x00000001u;
goto P_0c0a8c96;
P_0c0a8c96: /* original e400, guest PC 0x0c0a8c96 */
if(!s->budget--) { s->failed_pc=0x0c0a8c96u; return 0; }
r[4]=0x00000000u;
goto P_0c0a8c98;
P_0c0a8c98: /* original 9048, guest PC 0x0c0a8c98 */
if(!s->budget--) { s->failed_pc=0x0c0a8c98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8d2cu,2);
goto P_0c0a8c9a;
P_0c0a8c9a: /* original 0d44, guest PC 0x0c0a8c9a */
if(!s->budget--) { s->failed_pc=0x0c0a8c9au; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0a8c9c;
P_0c0a8c9c: /* original d327, guest PC 0x0c0a8c9c */
if(!s->budget--) { s->failed_pc=0x0c0a8c9cu; return 0; }
r[3]=read(ram,0x0c0a8d3cu,4);
goto P_0c0a8c9e;
P_0c0a8c9e: /* original 54e4, guest PC 0x0c0a8c9e */
if(!s->budget--) { s->failed_pc=0x0c0a8c9eu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0a8ca0;
P_0c0a8ca0: /* original 430b, guest PC 0x0c0a8ca0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8ca4u;
r[5]=read(ram,r[14]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8ca4u) { target=s->pc; goto dispatch; }
goto P_0c0a8ca4;
P_0c0a8ca2: /* original 55e5, guest PC 0x0c0a8ca2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca2u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0a8ca4;
P_0c0a8ca4: /* original d225, guest PC 0x0c0a8ca4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca4u; return 0; }
r[2]=read(ram,0x0c0a8d3cu,4);
goto P_0c0a8ca6;
P_0c0a8ca6: /* original 54e5, guest PC 0x0c0a8ca6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca6u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0a8ca8;
P_0c0a8ca8: /* original 420b, guest PC 0x0c0a8ca8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ca8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8cacu;
r[5]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8cacu) { target=s->pc; goto dispatch; }
goto P_0c0a8cac;
P_0c0a8caa: /* original 55e4, guest PC 0x0c0a8caa */
if(!s->budget--) { s->failed_pc=0x0c0a8caau; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0a8cac;
P_0c0a8cac: /* original 5de5, guest PC 0x0c0a8cac */
if(!s->budget--) { s->failed_pc=0x0c0a8cacu; return 0; }
r[13]=read(ram,r[14]+20,4);
goto P_0c0a8cae;
P_0c0a8cae: /* original d324, guest PC 0x0c0a8cae */
if(!s->budget--) { s->failed_pc=0x0c0a8caeu; return 0; }
r[3]=read(ram,0x0c0a8d40u,4);
goto P_0c0a8cb0;
P_0c0a8cb0: /* original 5ce4, guest PC 0x0c0a8cb0 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb0u; return 0; }
r[12]=read(ram,r[14]+16,4);
goto P_0c0a8cb2;
P_0c0a8cb2: /* original 65d3, guest PC 0x0c0a8cb2 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb2u; return 0; }
r[5]=r[13];
goto P_0c0a8cb4;
P_0c0a8cb4: /* original 430b, guest PC 0x0c0a8cb4 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8cb8u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8cb8u) { target=s->pc; goto dispatch; }
goto P_0c0a8cb8;
P_0c0a8cb6: /* original 64c3, guest PC 0x0c0a8cb6 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb6u; return 0; }
r[4]=r[12];
goto P_0c0a8cb8;
P_0c0a8cb8: /* original d222, guest PC 0x0c0a8cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a8cb8u; return 0; }
r[2]=read(ram,0x0c0a8d44u,4);
goto P_0c0a8cba;
P_0c0a8cba: /* original 65d3, guest PC 0x0c0a8cba */
if(!s->budget--) { s->failed_pc=0x0c0a8cbau; return 0; }
r[5]=r[13];
goto P_0c0a8cbc;
P_0c0a8cbc: /* original 420b, guest PC 0x0c0a8cbc */
if(!s->budget--) { s->failed_pc=0x0c0a8cbcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8cc0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8cc0u) { target=s->pc; goto dispatch; }
goto P_0c0a8cc0;
P_0c0a8cbe: /* original 64c3, guest PC 0x0c0a8cbe */
if(!s->budget--) { s->failed_pc=0x0c0a8cbeu; return 0; }
r[4]=r[12];
goto P_0c0a8cc0;
P_0c0a8cc0: /* original d321, guest PC 0x0c0a8cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc0u; return 0; }
r[3]=read(ram,0x0c0a8d48u,4);
goto P_0c0a8cc2;
P_0c0a8cc2: /* original 65d3, guest PC 0x0c0a8cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc2u; return 0; }
r[5]=r[13];
goto P_0c0a8cc4;
P_0c0a8cc4: /* original 430b, guest PC 0x0c0a8cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8cc8u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8cc8u) { target=s->pc; goto dispatch; }
goto P_0c0a8cc8;
P_0c0a8cc6: /* original 64c3, guest PC 0x0c0a8cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc6u; return 0; }
r[4]=r[12];
goto P_0c0a8cc8;
P_0c0a8cc8: /* original d220, guest PC 0x0c0a8cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8cc8u; return 0; }
r[2]=read(ram,0x0c0a8d4cu,4);
goto P_0c0a8cca;
P_0c0a8cca: /* original 65d3, guest PC 0x0c0a8cca */
if(!s->budget--) { s->failed_pc=0x0c0a8ccau; return 0; }
r[5]=r[13];
goto P_0c0a8ccc;
P_0c0a8ccc: /* original 420b, guest PC 0x0c0a8ccc */
if(!s->budget--) { s->failed_pc=0x0c0a8cccu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8cd0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8cd0u) { target=s->pc; goto dispatch; }
goto P_0c0a8cd0;
P_0c0a8cce: /* original 64c3, guest PC 0x0c0a8cce */
if(!s->budget--) { s->failed_pc=0x0c0a8cceu; return 0; }
r[4]=r[12];
goto P_0c0a8cd0;
P_0c0a8cd0: /* original 54e4, guest PC 0x0c0a8cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd0u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0a8cd2;
P_0c0a8cd2: /* original e061, guest PC 0x0c0a8cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd2u; return 0; }
r[0]=0x00000061u;
goto P_0c0a8cd4;
P_0c0a8cd4: /* original 054c, guest PC 0x0c0a8cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd4u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a8cd6;
P_0c0a8cd6: /* original 605c, guest PC 0x0c0a8cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd6u; return 0; }
r[0]=r[5]&255u;
goto P_0c0a8cd8;
P_0c0a8cd8: /* original 880c, guest PC 0x0c0a8cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8cd8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a8cda;
P_0c0a8cda: /* original 8906, guest PC 0x0c0a8cda */
if(!s->budget--) { s->failed_pc=0x0c0a8cdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8cea; }
goto P_0c0a8cdc;
P_0c0a8cdc: /* original d31c, guest PC 0x0c0a8cdc */
if(!s->budget--) { s->failed_pc=0x0c0a8cdcu; return 0; }
r[3]=read(ram,0x0c0a8d50u,4);
goto P_0c0a8cde;
P_0c0a8cde: /* original 6230, guest PC 0x0c0a8cde */
if(!s->budget--) { s->failed_pc=0x0c0a8cdeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0a8ce0;
P_0c0a8ce0: /* original 2228, guest PC 0x0c0a8ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a8ce2;
P_0c0a8ce2: /* original 8b02, guest PC 0x0c0a8ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8cea; }
goto P_0c0a8ce4;
P_0c0a8ce4: /* original d31b, guest PC 0x0c0a8ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce4u; return 0; }
r[3]=read(ram,0x0c0a8d54u,4);
goto P_0c0a8ce6;
P_0c0a8ce6: /* original 430b, guest PC 0x0c0a8ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8ceau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8ceau) { target=s->pc; goto dispatch; }
goto P_0c0a8cea;
P_0c0a8ce8: /* original 0009, guest PC 0x0c0a8ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ce8u; return 0; }
goto P_0c0a8cea;
P_0c0a8cea: /* original 54e5, guest PC 0x0c0a8cea */
if(!s->budget--) { s->failed_pc=0x0c0a8ceau; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0a8cec;
P_0c0a8cec: /* original e061, guest PC 0x0c0a8cec */
if(!s->budget--) { s->failed_pc=0x0c0a8cecu; return 0; }
r[0]=0x00000061u;
goto P_0c0a8cee;
P_0c0a8cee: /* original 054c, guest PC 0x0c0a8cee */
if(!s->budget--) { s->failed_pc=0x0c0a8ceeu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a8cf0;
P_0c0a8cf0: /* original 605c, guest PC 0x0c0a8cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf0u; return 0; }
r[0]=r[5]&255u;
goto P_0c0a8cf2;
P_0c0a8cf2: /* original 880c, guest PC 0x0c0a8cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a8cf4;
P_0c0a8cf4: /* original 8910, guest PC 0x0c0a8cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8d18; }
goto P_0c0a8cf6;
P_0c0a8cf6: /* original d316, guest PC 0x0c0a8cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf6u; return 0; }
r[3]=read(ram,0x0c0a8d50u,4);
goto P_0c0a8cf8;
P_0c0a8cf8: /* original 6230, guest PC 0x0c0a8cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a8cf8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0a8cfa;
P_0c0a8cfa: /* original 2228, guest PC 0x0c0a8cfa */
if(!s->budget--) { s->failed_pc=0x0c0a8cfau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a8cfc;
P_0c0a8cfc: /* original 8b0c, guest PC 0x0c0a8cfc */
if(!s->budget--) { s->failed_pc=0x0c0a8cfcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8d18; }
goto P_0c0a8cfe;
P_0c0a8cfe: /* original d315, guest PC 0x0c0a8cfe */
if(!s->budget--) { s->failed_pc=0x0c0a8cfeu; return 0; }
r[3]=read(ram,0x0c0a8d54u,4);
goto P_0c0a8d00;
P_0c0a8d00: /* original 430b, guest PC 0x0c0a8d00 */
if(!s->budget--) { s->failed_pc=0x0c0a8d00u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8d04u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8d04u) { target=s->pc; goto dispatch; }
goto P_0c0a8d04;
P_0c0a8d02: /* original 0009, guest PC 0x0c0a8d02 */
if(!s->budget--) { s->failed_pc=0x0c0a8d02u; return 0; }
goto P_0c0a8d04;
P_0c0a8d04: /* original a008, guest PC 0x0c0a8d04 */
if(!s->budget--) { s->failed_pc=0x0c0a8d04u; return 0; }
goto P_0c0a8d18;
P_0c0a8d06: /* original 0009, guest PC 0x0c0a8d06 */
if(!s->budget--) { s->failed_pc=0x0c0a8d06u; return 0; }
goto P_0c0a8d08;
P_0c0a8d08: /* original 9011, guest PC 0x0c0a8d08 */
if(!s->budget--) { s->failed_pc=0x0c0a8d08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8d2eu,2);
goto P_0c0a8d0a;
P_0c0a8d0a: /* original 66c3, guest PC 0x0c0a8d0a */
if(!s->budget--) { s->failed_pc=0x0c0a8d0au; return 0; }
r[6]=r[12];
goto P_0c0a8d0c;
P_0c0a8d0c: /* original e201, guest PC 0x0c0a8d0c */
if(!s->budget--) { s->failed_pc=0x0c0a8d0cu; return 0; }
r[2]=0x00000001u;
goto P_0c0a8d0e;
P_0c0a8d0e: /* original 7658, guest PC 0x0c0a8d0e */
if(!s->budget--) { s->failed_pc=0x0c0a8d0eu; return 0; }
r[6]+=0x00000058u;
goto P_0c0a8d10;
P_0c0a8d10: /* original 0d24, guest PC 0x0c0a8d10 */
if(!s->budget--) { s->failed_pc=0x0c0a8d10u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0a8d12;
P_0c0a8d12: /* original 940d, guest PC 0x0c0a8d12 */
if(!s->budget--) { s->failed_pc=0x0c0a8d12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8d30u,2);
goto P_0c0a8d14;
P_0c0a8d14: /* original 4a0b, guest PC 0x0c0a8d14 */
if(!s->budget--) { s->failed_pc=0x0c0a8d14u; return 0; }
target=r[10];
r[16]=code_base|0x0c0a8d18u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8d18u) { target=s->pc; goto dispatch; }
goto P_0c0a8d18;
P_0c0a8d16: /* original 65c3, guest PC 0x0c0a8d16 */
if(!s->budget--) { s->failed_pc=0x0c0a8d16u; return 0; }
r[5]=r[12];
goto P_0c0a8d18;
P_0c0a8d18: /* original 7f08, guest PC 0x0c0a8d18 */
if(!s->budget--) { s->failed_pc=0x0c0a8d18u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a8d1a;
P_0c0a8d1a: /* original 4f16, guest PC 0x0c0a8d1a */
if(!s->budget--) { s->failed_pc=0x0c0a8d1au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8d1c;
P_0c0a8d1c: /* original 4f26, guest PC 0x0c0a8d1c */
if(!s->budget--) { s->failed_pc=0x0c0a8d1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8d1e;
P_0c0a8d1e: /* original 6af6, guest PC 0x0c0a8d1e */
if(!s->budget--) { s->failed_pc=0x0c0a8d1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8d20;
P_0c0a8d20: /* original 6bf6, guest PC 0x0c0a8d20 */
if(!s->budget--) { s->failed_pc=0x0c0a8d20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8d22;
P_0c0a8d22: /* original 6cf6, guest PC 0x0c0a8d22 */
if(!s->budget--) { s->failed_pc=0x0c0a8d22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8d24;
P_0c0a8d24: /* original 6df6, guest PC 0x0c0a8d24 */
if(!s->budget--) { s->failed_pc=0x0c0a8d24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8d26;
P_0c0a8d26: /* original 000b, guest PC 0x0c0a8d26 */
if(!s->budget--) { s->failed_pc=0x0c0a8d26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8d28: /* original 6ef6, guest PC 0x0c0a8d28 */
if(!s->budget--) { s->failed_pc=0x0c0a8d28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a8d2au,s,ram);
P_0c0a8d58: /* original e004, guest PC 0x0c0a8d58 */
if(!s->budget--) { s->failed_pc=0x0c0a8d58u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8d5a;
P_0c0a8d5a: /* original 2fe6, guest PC 0x0c0a8d5a */
if(!s->budget--) { s->failed_pc=0x0c0a8d5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8d5c;
P_0c0a8d5c: /* original 4f22, guest PC 0x0c0a8d5c */
if(!s->budget--) { s->failed_pc=0x0c0a8d5cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8d5e;
P_0c0a8d5e: /* original 6e43, guest PC 0x0c0a8d5e */
if(!s->budget--) { s->failed_pc=0x0c0a8d5eu; return 0; }
r[14]=r[4];
goto P_0c0a8d60;
P_0c0a8d60: /* original 6262, guest PC 0x0c0a8d60 */
if(!s->budget--) { s->failed_pc=0x0c0a8d60u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a8d62;
P_0c0a8d62: /* original e3fe, guest PC 0x0c0a8d62 */
if(!s->budget--) { s->failed_pc=0x0c0a8d62u; return 0; }
r[3]=0xfffffffeu;
goto P_0c0a8d64;
P_0c0a8d64: /* original 7ff8, guest PC 0x0c0a8d64 */
if(!s->budget--) { s->failed_pc=0x0c0a8d64u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a8d66;
P_0c0a8d66: /* original 2239, guest PC 0x0c0a8d66 */
if(!s->budget--) { s->failed_pc=0x0c0a8d66u; return 0; }
r[2]&=r[3];
goto P_0c0a8d68;
P_0c0a8d68: /* original 2e22, guest PC 0x0c0a8d68 */
if(!s->budget--) { s->failed_pc=0x0c0a8d68u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8d6a;
P_0c0a8d6a: /* original f466, guest PC 0x0c0a8d6a */
if(!s->budget--) { s->failed_pc=0x0c0a8d6au; return 0; }
vf3_matrix_load(s,ram,4,r[6]+r[0]);
goto P_0c0a8d6c;
P_0c0a8d6c: /* original e008, guest PC 0x0c0a8d6c */
if(!s->budget--) { s->failed_pc=0x0c0a8d6cu; return 0; }
r[0]=0x00000008u;
goto P_0c0a8d6e;
P_0c0a8d6e: /* original f566, guest PC 0x0c0a8d6e */
if(!s->budget--) { s->failed_pc=0x0c0a8d6eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]+r[0]);
goto P_0c0a8d70;
P_0c0a8d70: /* original e00c, guest PC 0x0c0a8d70 */
if(!s->budget--) { s->failed_pc=0x0c0a8d70u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8d72;
P_0c0a8d72: /* original f666, guest PC 0x0c0a8d72 */
if(!s->budget--) { s->failed_pc=0x0c0a8d72u; return 0; }
vf3_matrix_load(s,ram,6,r[6]+r[0]);
goto P_0c0a8d74;
P_0c0a8d74: /* original 856a, guest PC 0x0c0a8d74 */
if(!s->budget--) { s->failed_pc=0x0c0a8d74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+20,2);
goto P_0c0a8d76;
P_0c0a8d76: /* original 5464, guest PC 0x0c0a8d76 */
if(!s->budget--) { s->failed_pc=0x0c0a8d76u; return 0; }
r[4]=read(ram,r[6]+16,4);
goto P_0c0a8d78;
P_0c0a8d78: /* original 6703, guest PC 0x0c0a8d78 */
if(!s->budget--) { s->failed_pc=0x0c0a8d78u; return 0; }
r[7]=r[0];
goto P_0c0a8d7a;
P_0c0a8d7a: /* original 856c, guest PC 0x0c0a8d7a */
if(!s->budget--) { s->failed_pc=0x0c0a8d7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+24,2);
goto P_0c0a8d7c;
P_0c0a8d7c: /* original 2f01, guest PC 0x0c0a8d7c */
if(!s->budget--) { s->failed_pc=0x0c0a8d7cu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c0a8d7e;
P_0c0a8d7e: /* original e010, guest PC 0x0c0a8d7e */
if(!s->budget--) { s->failed_pc=0x0c0a8d7eu; return 0; }
r[0]=0x00000010u;
goto P_0c0a8d80;
P_0c0a8d80: /* original 5267, guest PC 0x0c0a8d80 */
if(!s->budget--) { s->failed_pc=0x0c0a8d80u; return 0; }
r[2]=read(ram,r[6]+28,4);
goto P_0c0a8d82;
P_0c0a8d82: /* original 1f21, guest PC 0x0c0a8d82 */
if(!s->budget--) { s->failed_pc=0x0c0a8d82u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a8d84;
P_0c0a8d84: /* original fe47, guest PC 0x0c0a8d84 */
if(!s->budget--) { s->failed_pc=0x0c0a8d84u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a8d86;
P_0c0a8d86: /* original e014, guest PC 0x0c0a8d86 */
if(!s->budget--) { s->failed_pc=0x0c0a8d86u; return 0; }
r[0]=0x00000014u;
goto P_0c0a8d88;
P_0c0a8d88: /* original fe57, guest PC 0x0c0a8d88 */
if(!s->budget--) { s->failed_pc=0x0c0a8d88u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a8d8a;
P_0c0a8d8a: /* original e018, guest PC 0x0c0a8d8a */
if(!s->budget--) { s->failed_pc=0x0c0a8d8au; return 0; }
r[0]=0x00000018u;
goto P_0c0a8d8c;
P_0c0a8d8c: /* original fe67, guest PC 0x0c0a8d8c */
if(!s->budget--) { s->failed_pc=0x0c0a8d8cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a8d8e;
P_0c0a8d8e: /* original e048, guest PC 0x0c0a8d8e */
if(!s->budget--) { s->failed_pc=0x0c0a8d8eu; return 0; }
r[0]=0x00000048u;
goto P_0c0a8d90;
P_0c0a8d90: /* original 0e46, guest PC 0x0c0a8d90 */
if(!s->budget--) { s->failed_pc=0x0c0a8d90u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a8d92;
P_0c0a8d92: /* original 6073, guest PC 0x0c0a8d92 */
if(!s->budget--) { s->failed_pc=0x0c0a8d92u; return 0; }
r[0]=r[7];
goto P_0c0a8d94;
P_0c0a8d94: /* original 81ef, guest PC 0x0c0a8d94 */
if(!s->budget--) { s->failed_pc=0x0c0a8d94u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a8d96;
P_0c0a8d96: /* original 62f1, guest PC 0x0c0a8d96 */
if(!s->budget--) { s->failed_pc=0x0c0a8d96u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c0a8d98;
P_0c0a8d98: /* original e03e, guest PC 0x0c0a8d98 */
if(!s->budget--) { s->failed_pc=0x0c0a8d98u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a8d9a;
P_0c0a8d9a: /* original 0e25, guest PC 0x0c0a8d9a */
if(!s->budget--) { s->failed_pc=0x0c0a8d9au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a8d9c;
P_0c0a8d9c: /* original 9030, guest PC 0x0c0a8d9c */
if(!s->budget--) { s->failed_pc=0x0c0a8d9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8e00u,2);
goto P_0c0a8d9e;
P_0c0a8d9e: /* original 51f1, guest PC 0x0c0a8d9e */
if(!s->budget--) { s->failed_pc=0x0c0a8d9eu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0a8da0;
P_0c0a8da0: /* original 0e16, guest PC 0x0c0a8da0 */
if(!s->budget--) { s->failed_pc=0x0c0a8da0u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0a8da2;
P_0c0a8da2: /* original e03c, guest PC 0x0c0a8da2 */
if(!s->budget--) { s->failed_pc=0x0c0a8da2u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a8da4;
P_0c0a8da4: /* original 07ed, guest PC 0x0c0a8da4 */
if(!s->budget--) { s->failed_pc=0x0c0a8da4u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8da6;
P_0c0a8da6: /* original 856b, guest PC 0x0c0a8da6 */
if(!s->budget--) { s->failed_pc=0x0c0a8da6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a8da8;
P_0c0a8da8: /* original 6403, guest PC 0x0c0a8da8 */
if(!s->budget--) { s->failed_pc=0x0c0a8da8u; return 0; }
r[4]=r[0];
goto P_0c0a8daa;
P_0c0a8daa: /* original 664f, guest PC 0x0c0a8daa */
if(!s->budget--) { s->failed_pc=0x0c0a8daau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8dac;
P_0c0a8dac: /* original 2668, guest PC 0x0c0a8dac */
if(!s->budget--) { s->failed_pc=0x0c0a8dacu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a8dae;
P_0c0a8dae: /* original e03c, guest PC 0x0c0a8dae */
if(!s->budget--) { s->failed_pc=0x0c0a8daeu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a8db0;
P_0c0a8db0: /* original 8d22, guest PC 0x0c0a8db0 */
if(!s->budget--) { s->failed_pc=0x0c0a8db0u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0a8df8; }
goto P_0c0a8db4;
P_0c0a8db2: /* original 0e45, guest PC 0x0c0a8db2 */
if(!s->budget--) { s->failed_pc=0x0c0a8db2u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a8db4;
P_0c0a8db4: /* original 677f, guest PC 0x0c0a8db4 */
if(!s->budget--) { s->failed_pc=0x0c0a8db4u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c0a8db6;
P_0c0a8db6: /* original 3760, guest PC 0x0c0a8db6 */
if(!s->budget--) { s->failed_pc=0x0c0a8db6u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[6])!=0);
goto P_0c0a8db8;
P_0c0a8db8: /* original 8b06, guest PC 0x0c0a8db8 */
if(!s->budget--) { s->failed_pc=0x0c0a8db8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8dc8; }
goto P_0c0a8dba;
P_0c0a8dba: /* original e03e, guest PC 0x0c0a8dba */
if(!s->budget--) { s->failed_pc=0x0c0a8dbau; return 0; }
r[0]=0x0000003eu;
goto P_0c0a8dbc;
P_0c0a8dbc: /* original 04ed, guest PC 0x0c0a8dbc */
if(!s->budget--) { s->failed_pc=0x0c0a8dbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8dbe;
P_0c0a8dbe: /* original 604f, guest PC 0x0c0a8dbe */
if(!s->budget--) { s->failed_pc=0x0c0a8dbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8dc0;
P_0c0a8dc0: /* original 8801, guest PC 0x0c0a8dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a8dc2;
P_0c0a8dc2: /* original 890b, guest PC 0x0c0a8dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8ddc; }
goto P_0c0a8dc4;
P_0c0a8dc4: /* original a00f, guest PC 0x0c0a8dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc4u; return 0; }
goto P_0c0a8de6;
P_0c0a8dc6: /* original 0009, guest PC 0x0c0a8dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc6u; return 0; }
goto P_0c0a8dc8;
P_0c0a8dc8: /* original 02ed, guest PC 0x0c0a8dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8dca;
P_0c0a8dca: /* original 622d, guest PC 0x0c0a8dca */
if(!s->budget--) { s->failed_pc=0x0c0a8dcau; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a8dcc;
P_0c0a8dcc: /* original 6623, guest PC 0x0c0a8dcc */
if(!s->budget--) { s->failed_pc=0x0c0a8dccu; return 0; }
r[6]=r[2];
goto P_0c0a8dce;
P_0c0a8dce: /* original 2f22, guest PC 0x0c0a8dce */
if(!s->budget--) { s->failed_pc=0x0c0a8dceu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a8dd0;
P_0c0a8dd0: /* original d30c, guest PC 0x0c0a8dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd0u; return 0; }
r[3]=read(ram,0x0c0a8e04u,4);
goto P_0c0a8dd2;
P_0c0a8dd2: /* original 430b, guest PC 0x0c0a8dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8dd6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8dd6u) { target=s->pc; goto dispatch; }
goto P_0c0a8dd6;
P_0c0a8dd4: /* original 64e3, guest PC 0x0c0a8dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd4u; return 0; }
r[4]=r[14];
goto P_0c0a8dd6;
P_0c0a8dd6: /* original d20c, guest PC 0x0c0a8dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd6u; return 0; }
r[2]=read(ram,0x0c0a8e08u,4);
goto P_0c0a8dd8;
P_0c0a8dd8: /* original 420b, guest PC 0x0c0a8dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8ddcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8ddcu) { target=s->pc; goto dispatch; }
goto P_0c0a8ddc;
P_0c0a8dda: /* original 64e3, guest PC 0x0c0a8dda */
if(!s->budget--) { s->failed_pc=0x0c0a8ddau; return 0; }
r[4]=r[14];
goto P_0c0a8ddc;
P_0c0a8ddc: /* original d30b, guest PC 0x0c0a8ddc */
if(!s->budget--) { s->failed_pc=0x0c0a8ddcu; return 0; }
r[3]=read(ram,0x0c0a8e0cu,4);
goto P_0c0a8dde;
P_0c0a8dde: /* original 430b, guest PC 0x0c0a8dde */
if(!s->budget--) { s->failed_pc=0x0c0a8ddeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8de2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8de2u) { target=s->pc; goto dispatch; }
goto P_0c0a8de2;
P_0c0a8de0: /* original 64e3, guest PC 0x0c0a8de0 */
if(!s->budget--) { s->failed_pc=0x0c0a8de0u; return 0; }
r[4]=r[14];
goto P_0c0a8de2;
P_0c0a8de2: /* original a003, guest PC 0x0c0a8de2 */
if(!s->budget--) { s->failed_pc=0x0c0a8de2u; return 0; }
goto P_0c0a8dec;
P_0c0a8de4: /* original 0009, guest PC 0x0c0a8de4 */
if(!s->budget--) { s->failed_pc=0x0c0a8de4u; return 0; }
goto P_0c0a8de6;
P_0c0a8de6: /* original d30a, guest PC 0x0c0a8de6 */
if(!s->budget--) { s->failed_pc=0x0c0a8de6u; return 0; }
r[3]=read(ram,0x0c0a8e10u,4);
goto P_0c0a8de8;
P_0c0a8de8: /* original 430b, guest PC 0x0c0a8de8 */
if(!s->budget--) { s->failed_pc=0x0c0a8de8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8decu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8decu) { target=s->pc; goto dispatch; }
goto P_0c0a8dec;
P_0c0a8dea: /* original 64e3, guest PC 0x0c0a8dea */
if(!s->budget--) { s->failed_pc=0x0c0a8deau; return 0; }
r[4]=r[14];
goto P_0c0a8dec;
P_0c0a8dec: /* original 7f08, guest PC 0x0c0a8dec */
if(!s->budget--) { s->failed_pc=0x0c0a8decu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a8dee;
P_0c0a8dee: /* original d209, guest PC 0x0c0a8dee */
if(!s->budget--) { s->failed_pc=0x0c0a8deeu; return 0; }
r[2]=read(ram,0x0c0a8e14u,4);
goto P_0c0a8df0;
P_0c0a8df0: /* original 4f26, guest PC 0x0c0a8df0 */
if(!s->budget--) { s->failed_pc=0x0c0a8df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8df2;
P_0c0a8df2: /* original 64e3, guest PC 0x0c0a8df2 */
if(!s->budget--) { s->failed_pc=0x0c0a8df2u; return 0; }
r[4]=r[14];
goto P_0c0a8df4;
P_0c0a8df4: /* original 422b, guest PC 0x0c0a8df4 */
if(!s->budget--) { s->failed_pc=0x0c0a8df4u; return 0; }
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
P_0c0a8df6: /* original 6ef6, guest PC 0x0c0a8df6 */
if(!s->budget--) { s->failed_pc=0x0c0a8df6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a8df8;
P_0c0a8df8: /* original 7f08, guest PC 0x0c0a8df8 */
if(!s->budget--) { s->failed_pc=0x0c0a8df8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a8dfa;
P_0c0a8dfa: /* original 4f26, guest PC 0x0c0a8dfa */
if(!s->budget--) { s->failed_pc=0x0c0a8dfau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8dfc;
P_0c0a8dfc: /* original 000b, guest PC 0x0c0a8dfc */
if(!s->budget--) { s->failed_pc=0x0c0a8dfcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8dfe: /* original 6ef6, guest PC 0x0c0a8dfe */
if(!s->budget--) { s->failed_pc=0x0c0a8dfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a8e00u,s,ram);
P_0c0a91da: /* original 2fe6, guest PC 0x0c0a91da */
if(!s->budget--) { s->failed_pc=0x0c0a91dau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91dc;
P_0c0a91dc: /* original e054, guest PC 0x0c0a91dc */
if(!s->budget--) { s->failed_pc=0x0c0a91dcu; return 0; }
r[0]=0x00000054u;
goto P_0c0a91de;
P_0c0a91de: /* original 2fd6, guest PC 0x0c0a91de */
if(!s->budget--) { s->failed_pc=0x0c0a91deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e0;
P_0c0a91e0: /* original 2fc6, guest PC 0x0c0a91e0 */
if(!s->budget--) { s->failed_pc=0x0c0a91e0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e2;
P_0c0a91e2: /* original 2fb6, guest PC 0x0c0a91e2 */
if(!s->budget--) { s->failed_pc=0x0c0a91e2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e4;
P_0c0a91e4: /* original de2e, guest PC 0x0c0a91e4 */
if(!s->budget--) { s->failed_pc=0x0c0a91e4u; return 0; }
r[14]=read(ram,0x0c0a92a0u,4);
goto P_0c0a91e6;
P_0c0a91e6: /* original 4f22, guest PC 0x0c0a91e6 */
if(!s->budget--) { s->failed_pc=0x0c0a91e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a91e8;
P_0c0a91e8: /* original 04ee, guest PC 0x0c0a91e8 */
if(!s->budget--) { s->failed_pc=0x0c0a91e8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a91ea;
P_0c0a91ea: /* original 5de4, guest PC 0x0c0a91ea */
if(!s->budget--) { s->failed_pc=0x0c0a91eau; return 0; }
r[13]=read(ram,r[14]+16,4);
goto P_0c0a91ec;
P_0c0a91ec: /* original 5445, guest PC 0x0c0a91ec */
if(!s->budget--) { s->failed_pc=0x0c0a91ecu; return 0; }
r[4]=read(ram,r[4]+20,4);
goto P_0c0a91ee;
P_0c0a91ee: /* original 74ff, guest PC 0x0c0a91ee */
if(!s->budget--) { s->failed_pc=0x0c0a91eeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a91f0;
P_0c0a91f0: /* original 4411, guest PC 0x0c0a91f0 */
if(!s->budget--) { s->failed_pc=0x0c0a91f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a91f2;
P_0c0a91f2: /* original 8d01, guest PC 0x0c0a91f2 */
if(!s->budget--) { s->failed_pc=0x0c0a91f2u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[14]+20,4);
if(cond) { goto P_0c0a91f8; }
goto P_0c0a91f6;
P_0c0a91f4: /* original 5be5, guest PC 0x0c0a91f4 */
if(!s->budget--) { s->failed_pc=0x0c0a91f4u; return 0; }
r[11]=read(ram,r[14]+20,4);
goto P_0c0a91f6;
P_0c0a91f6: /* original 944c, guest PC 0x0c0a91f6 */
if(!s->budget--) { s->failed_pc=0x0c0a91f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9292u,2);
goto P_0c0a91f8;
P_0c0a91f8: /* original 4408, guest PC 0x0c0a91f8 */
if(!s->budget--) { s->failed_pc=0x0c0a91f8u; return 0; }
r[4]<<=2;
goto P_0c0a91fa;
P_0c0a91fa: /* original dc2a, guest PC 0x0c0a91fa */
if(!s->budget--) { s->failed_pc=0x0c0a91fau; return 0; }
r[12]=read(ram,0x0c0a92a4u,4);
goto P_0c0a91fc;
P_0c0a91fc: /* original 4408, guest PC 0x0c0a91fc */
if(!s->budget--) { s->failed_pc=0x0c0a91fcu; return 0; }
r[4]<<=2;
goto P_0c0a91fe;
P_0c0a91fe: /* original 65d3, guest PC 0x0c0a91fe */
if(!s->budget--) { s->failed_pc=0x0c0a91feu; return 0; }
r[5]=r[13];
goto P_0c0a9200;
P_0c0a9200: /* original 4408, guest PC 0x0c0a9200 */
if(!s->budget--) { s->failed_pc=0x0c0a9200u; return 0; }
r[4]<<=2;
goto P_0c0a9202;
P_0c0a9202: /* original 66b3, guest PC 0x0c0a9202 */
if(!s->budget--) { s->failed_pc=0x0c0a9202u; return 0; }
r[6]=r[11];
goto P_0c0a9204;
P_0c0a9204: /* original 4400, guest PC 0x0c0a9204 */
if(!s->budget--) { s->failed_pc=0x0c0a9204u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a9206;
P_0c0a9206: /* original 3c4c, guest PC 0x0c0a9206 */
if(!s->budget--) { s->failed_pc=0x0c0a9206u; return 0; }
r[12]+=r[4];
goto P_0c0a9208;
P_0c0a9208: /* original b162, guest PC 0x0c0a9208 */
if(!s->budget--) { s->failed_pc=0x0c0a9208u; return 0; }
target=0x0c0a94d0u; r[16]=code_base|0x0c0a920cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a920cu) { target=s->pc; goto dispatch; }
goto P_0c0a920c;
P_0c0a920a: /* original 64c3, guest PC 0x0c0a920a */
if(!s->budget--) { s->failed_pc=0x0c0a920au; return 0; }
r[4]=r[12];
goto P_0c0a920c;
P_0c0a920c: /* original d326, guest PC 0x0c0a920c */
if(!s->budget--) { s->failed_pc=0x0c0a920cu; return 0; }
r[3]=read(ram,0x0c0a92a8u,4);
goto P_0c0a920e;
P_0c0a920e: /* original e028, guest PC 0x0c0a920e */
if(!s->budget--) { s->failed_pc=0x0c0a920eu; return 0; }
r[0]=0x00000028u;
goto P_0c0a9210;
P_0c0a9210: /* original 66d3, guest PC 0x0c0a9210 */
if(!s->budget--) { s->failed_pc=0x0c0a9210u; return 0; }
r[6]=r[13];
goto P_0c0a9212;
P_0c0a9212: /* original 65b3, guest PC 0x0c0a9212 */
if(!s->budget--) { s->failed_pc=0x0c0a9212u; return 0; }
r[5]=r[11];
goto P_0c0a9214;
P_0c0a9214: /* original f438, guest PC 0x0c0a9214 */
if(!s->budget--) { s->failed_pc=0x0c0a9214u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0a9216;
P_0c0a9216: /* original 7c40, guest PC 0x0c0a9216 */
if(!s->budget--) { s->failed_pc=0x0c0a9216u; return 0; }
r[12]+=0x00000040u;
goto P_0c0a9218;
P_0c0a9218: /* original fd47, guest PC 0x0c0a9218 */
if(!s->budget--) { s->failed_pc=0x0c0a9218u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a921a;
P_0c0a921a: /* original b159, guest PC 0x0c0a921a */
if(!s->budget--) { s->failed_pc=0x0c0a921au; return 0; }
target=0x0c0a94d0u; r[16]=code_base|0x0c0a921eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a921eu) { target=s->pc; goto dispatch; }
goto P_0c0a921e;
P_0c0a921c: /* original 64c3, guest PC 0x0c0a921c */
if(!s->budget--) { s->failed_pc=0x0c0a921cu; return 0; }
r[4]=r[12];
goto P_0c0a921e;
P_0c0a921e: /* original d323, guest PC 0x0c0a921e */
if(!s->budget--) { s->failed_pc=0x0c0a921eu; return 0; }
r[3]=read(ram,0x0c0a92acu,4);
goto P_0c0a9220;
P_0c0a9220: /* original e028, guest PC 0x0c0a9220 */
if(!s->budget--) { s->failed_pc=0x0c0a9220u; return 0; }
r[0]=0x00000028u;
goto P_0c0a9222;
P_0c0a9222: /* original f438, guest PC 0x0c0a9222 */
if(!s->budget--) { s->failed_pc=0x0c0a9222u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0a9224;
P_0c0a9224: /* original fd47, guest PC 0x0c0a9224 */
if(!s->budget--) { s->failed_pc=0x0c0a9224u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a9226;
P_0c0a9226: /* original 5de4, guest PC 0x0c0a9226 */
if(!s->budget--) { s->failed_pc=0x0c0a9226u; return 0; }
r[13]=read(ram,r[14]+16,4);
goto P_0c0a9228;
P_0c0a9228: /* original 5ee5, guest PC 0x0c0a9228 */
if(!s->budget--) { s->failed_pc=0x0c0a9228u; return 0; }
r[14]=read(ram,r[14]+20,4);
goto P_0c0a922a;
P_0c0a922a: /* original d221, guest PC 0x0c0a922a */
if(!s->budget--) { s->failed_pc=0x0c0a922au; return 0; }
r[2]=read(ram,0x0c0a92b0u,4);
goto P_0c0a922c;
P_0c0a922c: /* original 65e3, guest PC 0x0c0a922c */
if(!s->budget--) { s->failed_pc=0x0c0a922cu; return 0; }
r[5]=r[14];
goto P_0c0a922e;
P_0c0a922e: /* original 420b, guest PC 0x0c0a922e */
if(!s->budget--) { s->failed_pc=0x0c0a922eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9232u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9232u) { target=s->pc; goto dispatch; }
goto P_0c0a9232;
P_0c0a9230: /* original 64d3, guest PC 0x0c0a9230 */
if(!s->budget--) { s->failed_pc=0x0c0a9230u; return 0; }
r[4]=r[13];
goto P_0c0a9232;
P_0c0a9232: /* original 4f26, guest PC 0x0c0a9232 */
if(!s->budget--) { s->failed_pc=0x0c0a9232u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9234;
P_0c0a9234: /* original 65d3, guest PC 0x0c0a9234 */
if(!s->budget--) { s->failed_pc=0x0c0a9234u; return 0; }
r[5]=r[13];
goto P_0c0a9236;
P_0c0a9236: /* original d31e, guest PC 0x0c0a9236 */
if(!s->budget--) { s->failed_pc=0x0c0a9236u; return 0; }
r[3]=read(ram,0x0c0a92b0u,4);
goto P_0c0a9238;
P_0c0a9238: /* original 64e3, guest PC 0x0c0a9238 */
if(!s->budget--) { s->failed_pc=0x0c0a9238u; return 0; }
r[4]=r[14];
goto P_0c0a923a;
P_0c0a923a: /* original 6bf6, guest PC 0x0c0a923a */
if(!s->budget--) { s->failed_pc=0x0c0a923au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a923c;
P_0c0a923c: /* original 6cf6, guest PC 0x0c0a923c */
if(!s->budget--) { s->failed_pc=0x0c0a923cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a923e;
P_0c0a923e: /* original 6df6, guest PC 0x0c0a923e */
if(!s->budget--) { s->failed_pc=0x0c0a923eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9240;
P_0c0a9240: /* original 432b, guest PC 0x0c0a9240 */
if(!s->budget--) { s->failed_pc=0x0c0a9240u; return 0; }
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
P_0c0a9242: /* original 6ef6, guest PC 0x0c0a9242 */
if(!s->budget--) { s->failed_pc=0x0c0a9242u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9244u,s,ram);
P_0c0a926a: /* original 9013, guest PC 0x0c0a926a */
if(!s->budget--) { s->failed_pc=0x0c0a926au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9294u,2);
goto P_0c0a926c;
P_0c0a926c: /* original e601, guest PC 0x0c0a926c */
if(!s->budget--) { s->failed_pc=0x0c0a926cu; return 0; }
r[6]=0x00000001u;
goto P_0c0a926e;
P_0c0a926e: /* original d715, guest PC 0x0c0a926e */
if(!s->budget--) { s->failed_pc=0x0c0a926eu; return 0; }
r[7]=read(ram,0x0c0a92c4u,4);
goto P_0c0a9270;
P_0c0a9270: /* original 0764, guest PC 0x0c0a9270 */
if(!s->budget--) { s->failed_pc=0x0c0a9270u; return 0; }
write(ram,r[7]+r[0],r[6],1);
goto P_0c0a9272;
P_0c0a9272: /* original 6542, guest PC 0x0c0a9272 */
if(!s->budget--) { s->failed_pc=0x0c0a9272u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0a9274;
P_0c0a9274: /* original d310, guest PC 0x0c0a9274 */
if(!s->budget--) { s->failed_pc=0x0c0a9274u; return 0; }
r[3]=read(ram,0x0c0a92b8u,4);
goto P_0c0a9276;
P_0c0a9276: /* original 2538, guest PC 0x0c0a9276 */
if(!s->budget--) { s->failed_pc=0x0c0a9276u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0a9278;
P_0c0a9278: /* original 8b07, guest PC 0x0c0a9278 */
if(!s->budget--) { s->failed_pc=0x0c0a9278u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a928a; }
goto P_0c0a927a;
P_0c0a927a: /* original e048, guest PC 0x0c0a927a */
if(!s->budget--) { s->failed_pc=0x0c0a927au; return 0; }
r[0]=0x00000048u;
goto P_0c0a927c;
P_0c0a927c: /* original d30f, guest PC 0x0c0a927c */
if(!s->budget--) { s->failed_pc=0x0c0a927cu; return 0; }
r[3]=read(ram,0x0c0a92bcu,4);
goto P_0c0a927e;
P_0c0a927e: /* original 044e, guest PC 0x0c0a927e */
if(!s->budget--) { s->failed_pc=0x0c0a927eu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0a9280;
P_0c0a9280: /* original 2348, guest PC 0x0c0a9280 */
if(!s->budget--) { s->failed_pc=0x0c0a9280u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0a9282;
P_0c0a9282: /* original 8b02, guest PC 0x0c0a9282 */
if(!s->budget--) { s->failed_pc=0x0c0a9282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a928a; }
goto P_0c0a9284;
P_0c0a9284: /* original d50e, guest PC 0x0c0a9284 */
if(!s->budget--) { s->failed_pc=0x0c0a9284u; return 0; }
r[5]=read(ram,0x0c0a92c0u,4);
goto P_0c0a9286;
P_0c0a9286: /* original 2548, guest PC 0x0c0a9286 */
if(!s->budget--) { s->failed_pc=0x0c0a9286u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[4])==0)!=0);
goto P_0c0a9288;
P_0c0a9288: /* original 8b01, guest PC 0x0c0a9288 */
if(!s->budget--) { s->failed_pc=0x0c0a9288u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a928e; }
goto P_0c0a928a;
P_0c0a928a: /* original 9003, guest PC 0x0c0a928a */
if(!s->budget--) { s->failed_pc=0x0c0a928au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9294u,2);
goto P_0c0a928c;
P_0c0a928c: /* original 0764, guest PC 0x0c0a928c */
if(!s->budget--) { s->failed_pc=0x0c0a928cu; return 0; }
write(ram,r[7]+r[0],r[6],1);
goto P_0c0a928e;
P_0c0a928e: /* original 000b, guest PC 0x0c0a928e */
if(!s->budget--) { s->failed_pc=0x0c0a928eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a9290: /* original 0009, guest PC 0x0c0a9290 */
if(!s->budget--) { s->failed_pc=0x0c0a9290u; return 0; }
return vf3_matrix_family(0x0c0a9292u,s,ram);
P_0c0a9444: /* original 2fe6, guest PC 0x0c0a9444 */
if(!s->budget--) { s->failed_pc=0x0c0a9444u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9446;
P_0c0a9446: /* original 6e43, guest PC 0x0c0a9446 */
if(!s->budget--) { s->failed_pc=0x0c0a9446u; return 0; }
r[14]=r[4];
goto P_0c0a9448;
P_0c0a9448: /* original d41e, guest PC 0x0c0a9448 */
if(!s->budget--) { s->failed_pc=0x0c0a9448u; return 0; }
r[4]=read(ram,0x0c0a94c4u,4);
goto P_0c0a944a;
P_0c0a944a: /* original 902e, guest PC 0x0c0a944a */
if(!s->budget--) { s->failed_pc=0x0c0a944au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94aau,2);
goto P_0c0a944c;
P_0c0a944c: /* original 5645, guest PC 0x0c0a944c */
if(!s->budget--) { s->failed_pc=0x0c0a944cu; return 0; }
r[6]=read(ram,r[4]+20,4);
goto P_0c0a944e;
P_0c0a944e: /* original 5544, guest PC 0x0c0a944e */
if(!s->budget--) { s->failed_pc=0x0c0a944eu; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c0a9450;
P_0c0a9450: /* original e401, guest PC 0x0c0a9450 */
if(!s->budget--) { s->failed_pc=0x0c0a9450u; return 0; }
r[4]=0x00000001u;
return vf3_matrix_family(0x0c0a9452u,s,ram);
P_0c0a94d0: /* original e004, guest PC 0x0c0a94d0 */
if(!s->budget--) { s->failed_pc=0x0c0a94d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0a94d2;
P_0c0a94d2: /* original 2fe6, guest PC 0x0c0a94d2 */
if(!s->budget--) { s->failed_pc=0x0c0a94d2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a94d4;
P_0c0a94d4: /* original 4f22, guest PC 0x0c0a94d4 */
if(!s->budget--) { s->failed_pc=0x0c0a94d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a94d6;
P_0c0a94d6: /* original 6e53, guest PC 0x0c0a94d6 */
if(!s->budget--) { s->failed_pc=0x0c0a94d6u; return 0; }
r[14]=r[5];
goto P_0c0a94d8;
P_0c0a94d8: /* original 7fec, guest PC 0x0c0a94d8 */
if(!s->budget--) { s->failed_pc=0x0c0a94d8u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0a94da;
P_0c0a94da: /* original 1f61, guest PC 0x0c0a94da */
if(!s->budget--) { s->failed_pc=0x0c0a94dau; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a94dc;
P_0c0a94dc: /* original f446, guest PC 0x0c0a94dc */
if(!s->budget--) { s->failed_pc=0x0c0a94dcu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0a94de;
P_0c0a94de: /* original e008, guest PC 0x0c0a94de */
if(!s->budget--) { s->failed_pc=0x0c0a94deu; return 0; }
r[0]=0x00000008u;
goto P_0c0a94e0;
P_0c0a94e0: /* original f546, guest PC 0x0c0a94e0 */
if(!s->budget--) { s->failed_pc=0x0c0a94e0u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0a94e2;
P_0c0a94e2: /* original e00c, guest PC 0x0c0a94e2 */
if(!s->budget--) { s->failed_pc=0x0c0a94e2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a94e4;
P_0c0a94e4: /* original f646, guest PC 0x0c0a94e4 */
if(!s->budget--) { s->failed_pc=0x0c0a94e4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0a94e6;
P_0c0a94e6: /* original e020, guest PC 0x0c0a94e6 */
if(!s->budget--) { s->failed_pc=0x0c0a94e6u; return 0; }
r[0]=0x00000020u;
goto P_0c0a94e8;
P_0c0a94e8: /* original 064d, guest PC 0x0c0a94e8 */
if(!s->budget--) { s->failed_pc=0x0c0a94e8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a94ea;
P_0c0a94ea: /* original e024, guest PC 0x0c0a94ea */
if(!s->budget--) { s->failed_pc=0x0c0a94eau; return 0; }
r[0]=0x00000024u;
goto P_0c0a94ec;
P_0c0a94ec: /* original 074d, guest PC 0x0c0a94ec */
if(!s->budget--) { s->failed_pc=0x0c0a94ecu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a94ee;
P_0c0a94ee: /* original e038, guest PC 0x0c0a94ee */
if(!s->budget--) { s->failed_pc=0x0c0a94eeu; return 0; }
r[0]=0x00000038u;
goto P_0c0a94f0;
P_0c0a94f0: /* original 5344, guest PC 0x0c0a94f0 */
if(!s->budget--) { s->failed_pc=0x0c0a94f0u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c0a94f2;
P_0c0a94f2: /* original 6542, guest PC 0x0c0a94f2 */
if(!s->budget--) { s->failed_pc=0x0c0a94f2u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0a94f4;
P_0c0a94f4: /* original 2f32, guest PC 0x0c0a94f4 */
if(!s->budget--) { s->failed_pc=0x0c0a94f4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a94f6;
P_0c0a94f6: /* original 524b, guest PC 0x0c0a94f6 */
if(!s->budget--) { s->failed_pc=0x0c0a94f6u; return 0; }
r[2]=read(ram,r[4]+44,4);
goto P_0c0a94f8;
P_0c0a94f8: /* original 1f24, guest PC 0x0c0a94f8 */
if(!s->budget--) { s->failed_pc=0x0c0a94f8u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0a94fa;
P_0c0a94fa: /* original 534c, guest PC 0x0c0a94fa */
if(!s->budget--) { s->failed_pc=0x0c0a94fau; return 0; }
r[3]=read(ram,r[4]+48,4);
goto P_0c0a94fc;
P_0c0a94fc: /* original 1f33, guest PC 0x0c0a94fc */
if(!s->budget--) { s->failed_pc=0x0c0a94fcu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a94fe;
P_0c0a94fe: /* original 004c, guest PC 0x0c0a94fe */
if(!s->budget--) { s->failed_pc=0x0c0a94feu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a9500;
P_0c0a9500: /* original 80f8, guest PC 0x0c0a9500 */
if(!s->budget--) { s->failed_pc=0x0c0a9500u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c0a9502;
P_0c0a9502: /* original e010, guest PC 0x0c0a9502 */
if(!s->budget--) { s->failed_pc=0x0c0a9502u; return 0; }
r[0]=0x00000010u;
goto P_0c0a9504;
P_0c0a9504: /* original 2e52, guest PC 0x0c0a9504 */
if(!s->budget--) { s->failed_pc=0x0c0a9504u; return 0; }
write(ram,r[14],r[5],4);
goto P_0c0a9506;
P_0c0a9506: /* original fe47, guest PC 0x0c0a9506 */
if(!s->budget--) { s->failed_pc=0x0c0a9506u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9508;
P_0c0a9508: /* original e014, guest PC 0x0c0a9508 */
if(!s->budget--) { s->failed_pc=0x0c0a9508u; return 0; }
r[0]=0x00000014u;
goto P_0c0a950a;
P_0c0a950a: /* original fe57, guest PC 0x0c0a950a */
if(!s->budget--) { s->failed_pc=0x0c0a950au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a950c;
P_0c0a950c: /* original e018, guest PC 0x0c0a950c */
if(!s->budget--) { s->failed_pc=0x0c0a950cu; return 0; }
r[0]=0x00000018u;
goto P_0c0a950e;
P_0c0a950e: /* original fe67, guest PC 0x0c0a950e */
if(!s->budget--) { s->failed_pc=0x0c0a950eu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a9510;
P_0c0a9510: /* original 6063, guest PC 0x0c0a9510 */
if(!s->budget--) { s->failed_pc=0x0c0a9510u; return 0; }
r[0]=r[6];
goto P_0c0a9512;
P_0c0a9512: /* original 81ef, guest PC 0x0c0a9512 */
if(!s->budget--) { s->failed_pc=0x0c0a9512u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a9514;
P_0c0a9514: /* original e03e, guest PC 0x0c0a9514 */
if(!s->budget--) { s->failed_pc=0x0c0a9514u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9516;
P_0c0a9516: /* original 0e75, guest PC 0x0c0a9516 */
if(!s->budget--) { s->failed_pc=0x0c0a9516u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c0a9518;
P_0c0a9518: /* original e048, guest PC 0x0c0a9518 */
if(!s->budget--) { s->failed_pc=0x0c0a9518u; return 0; }
r[0]=0x00000048u;
goto P_0c0a951a;
P_0c0a951a: /* original 63f2, guest PC 0x0c0a951a */
if(!s->budget--) { s->failed_pc=0x0c0a951au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a951c;
P_0c0a951c: /* original 0e36, guest PC 0x0c0a951c */
if(!s->budget--) { s->failed_pc=0x0c0a951cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0a951e;
P_0c0a951e: /* original 9037, guest PC 0x0c0a951e */
if(!s->budget--) { s->failed_pc=0x0c0a951eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9590u,2);
goto P_0c0a9520;
P_0c0a9520: /* original 52f4, guest PC 0x0c0a9520 */
if(!s->budget--) { s->failed_pc=0x0c0a9520u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0a9522;
P_0c0a9522: /* original 0e26, guest PC 0x0c0a9522 */
if(!s->budget--) { s->failed_pc=0x0c0a9522u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0a9524;
P_0c0a9524: /* original 9035, guest PC 0x0c0a9524 */
if(!s->budget--) { s->failed_pc=0x0c0a9524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9592u,2);
goto P_0c0a9526;
P_0c0a9526: /* original 53f3, guest PC 0x0c0a9526 */
if(!s->budget--) { s->failed_pc=0x0c0a9526u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a9528;
P_0c0a9528: /* original 0e36, guest PC 0x0c0a9528 */
if(!s->budget--) { s->failed_pc=0x0c0a9528u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0a952a;
P_0c0a952a: /* original 9133, guest PC 0x0c0a952a */
if(!s->budget--) { s->failed_pc=0x0c0a952au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9594u,2);
goto P_0c0a952c;
P_0c0a952c: /* original 84f8, guest PC 0x0c0a952c */
if(!s->budget--) { s->failed_pc=0x0c0a952cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c0a952e;
P_0c0a952e: /* original 31ec, guest PC 0x0c0a952e */
if(!s->budget--) { s->failed_pc=0x0c0a952eu; return 0; }
r[1]+=r[14];
goto P_0c0a9530;
P_0c0a9530: /* original 2100, guest PC 0x0c0a9530 */
if(!s->budget--) { s->failed_pc=0x0c0a9530u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a9532;
P_0c0a9532: /* original e03c, guest PC 0x0c0a9532 */
if(!s->budget--) { s->failed_pc=0x0c0a9532u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9534;
P_0c0a9534: /* original 06ed, guest PC 0x0c0a9534 */
if(!s->budget--) { s->failed_pc=0x0c0a9534u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9536;
P_0c0a9536: /* original e022, guest PC 0x0c0a9536 */
if(!s->budget--) { s->failed_pc=0x0c0a9536u; return 0; }
r[0]=0x00000022u;
goto P_0c0a9538;
P_0c0a9538: /* original 044d, guest PC 0x0c0a9538 */
if(!s->budget--) { s->failed_pc=0x0c0a9538u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a953a;
P_0c0a953a: /* original e03c, guest PC 0x0c0a953a */
if(!s->budget--) { s->failed_pc=0x0c0a953au; return 0; }
r[0]=0x0000003cu;
goto P_0c0a953c;
P_0c0a953c: /* original 654f, guest PC 0x0c0a953c */
if(!s->budget--) { s->failed_pc=0x0c0a953cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a953e;
P_0c0a953e: /* original 2558, guest PC 0x0c0a953e */
if(!s->budget--) { s->failed_pc=0x0c0a953eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a9540;
P_0c0a9540: /* original 8d22, guest PC 0x0c0a9540 */
if(!s->budget--) { s->failed_pc=0x0c0a9540u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0a9588; }
goto P_0c0a9544;
P_0c0a9542: /* original 0e45, guest PC 0x0c0a9542 */
if(!s->budget--) { s->failed_pc=0x0c0a9542u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9544;
P_0c0a9544: /* original 666f, guest PC 0x0c0a9544 */
if(!s->budget--) { s->failed_pc=0x0c0a9544u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0a9546;
P_0c0a9546: /* original 3650, guest PC 0x0c0a9546 */
if(!s->budget--) { s->failed_pc=0x0c0a9546u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[5])!=0);
goto P_0c0a9548;
P_0c0a9548: /* original 8b06, guest PC 0x0c0a9548 */
if(!s->budget--) { s->failed_pc=0x0c0a9548u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9558; }
goto P_0c0a954a;
P_0c0a954a: /* original e03e, guest PC 0x0c0a954a */
if(!s->budget--) { s->failed_pc=0x0c0a954au; return 0; }
r[0]=0x0000003eu;
goto P_0c0a954c;
P_0c0a954c: /* original 04ed, guest PC 0x0c0a954c */
if(!s->budget--) { s->failed_pc=0x0c0a954cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a954e;
P_0c0a954e: /* original 604f, guest PC 0x0c0a954e */
if(!s->budget--) { s->failed_pc=0x0c0a954eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a9550;
P_0c0a9550: /* original 8801, guest PC 0x0c0a9550 */
if(!s->budget--) { s->failed_pc=0x0c0a9550u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a9552;
P_0c0a9552: /* original 890b, guest PC 0x0c0a9552 */
if(!s->budget--) { s->failed_pc=0x0c0a9552u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a956c; }
goto P_0c0a9554;
P_0c0a9554: /* original a00f, guest PC 0x0c0a9554 */
if(!s->budget--) { s->failed_pc=0x0c0a9554u; return 0; }
goto P_0c0a9576;
P_0c0a9556: /* original 0009, guest PC 0x0c0a9556 */
if(!s->budget--) { s->failed_pc=0x0c0a9556u; return 0; }
goto P_0c0a9558;
P_0c0a9558: /* original 02ed, guest PC 0x0c0a9558 */
if(!s->budget--) { s->failed_pc=0x0c0a9558u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a955a;
P_0c0a955a: /* original 2f21, guest PC 0x0c0a955a */
if(!s->budget--) { s->failed_pc=0x0c0a955au; return 0; }
write(ram,r[15],r[2],2);
goto P_0c0a955c;
P_0c0a955c: /* original 55f1, guest PC 0x0c0a955c */
if(!s->budget--) { s->failed_pc=0x0c0a955cu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0a955e;
P_0c0a955e: /* original d30e, guest PC 0x0c0a955e */
if(!s->budget--) { s->failed_pc=0x0c0a955eu; return 0; }
r[3]=read(ram,0x0c0a9598u,4);
goto P_0c0a9560;
P_0c0a9560: /* original 66f1, guest PC 0x0c0a9560 */
if(!s->budget--) { s->failed_pc=0x0c0a9560u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c0a9562;
P_0c0a9562: /* original 430b, guest PC 0x0c0a9562 */
if(!s->budget--) { s->failed_pc=0x0c0a9562u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9566u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9566u) { target=s->pc; goto dispatch; }
goto P_0c0a9566;
P_0c0a9564: /* original 64e3, guest PC 0x0c0a9564 */
if(!s->budget--) { s->failed_pc=0x0c0a9564u; return 0; }
r[4]=r[14];
goto P_0c0a9566;
P_0c0a9566: /* original d20d, guest PC 0x0c0a9566 */
if(!s->budget--) { s->failed_pc=0x0c0a9566u; return 0; }
r[2]=read(ram,0x0c0a959cu,4);
goto P_0c0a9568;
P_0c0a9568: /* original 420b, guest PC 0x0c0a9568 */
if(!s->budget--) { s->failed_pc=0x0c0a9568u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a956cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a956cu) { target=s->pc; goto dispatch; }
goto P_0c0a956c;
P_0c0a956a: /* original 64e3, guest PC 0x0c0a956a */
if(!s->budget--) { s->failed_pc=0x0c0a956au; return 0; }
r[4]=r[14];
goto P_0c0a956c;
P_0c0a956c: /* original d30c, guest PC 0x0c0a956c */
if(!s->budget--) { s->failed_pc=0x0c0a956cu; return 0; }
r[3]=read(ram,0x0c0a95a0u,4);
goto P_0c0a956e;
P_0c0a956e: /* original 430b, guest PC 0x0c0a956e */
if(!s->budget--) { s->failed_pc=0x0c0a956eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9572u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9572u) { target=s->pc; goto dispatch; }
goto P_0c0a9572;
P_0c0a9570: /* original 64e3, guest PC 0x0c0a9570 */
if(!s->budget--) { s->failed_pc=0x0c0a9570u; return 0; }
r[4]=r[14];
goto P_0c0a9572;
P_0c0a9572: /* original a003, guest PC 0x0c0a9572 */
if(!s->budget--) { s->failed_pc=0x0c0a9572u; return 0; }
goto P_0c0a957c;
P_0c0a9574: /* original 0009, guest PC 0x0c0a9574 */
if(!s->budget--) { s->failed_pc=0x0c0a9574u; return 0; }
goto P_0c0a9576;
P_0c0a9576: /* original d30b, guest PC 0x0c0a9576 */
if(!s->budget--) { s->failed_pc=0x0c0a9576u; return 0; }
r[3]=read(ram,0x0c0a95a4u,4);
goto P_0c0a9578;
P_0c0a9578: /* original 430b, guest PC 0x0c0a9578 */
if(!s->budget--) { s->failed_pc=0x0c0a9578u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a957cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a957cu) { target=s->pc; goto dispatch; }
goto P_0c0a957c;
P_0c0a957a: /* original 64e3, guest PC 0x0c0a957a */
if(!s->budget--) { s->failed_pc=0x0c0a957au; return 0; }
r[4]=r[14];
goto P_0c0a957c;
P_0c0a957c: /* original 7f14, guest PC 0x0c0a957c */
if(!s->budget--) { s->failed_pc=0x0c0a957cu; return 0; }
r[15]+=0x00000014u;
goto P_0c0a957e;
P_0c0a957e: /* original d20a, guest PC 0x0c0a957e */
if(!s->budget--) { s->failed_pc=0x0c0a957eu; return 0; }
r[2]=read(ram,0x0c0a95a8u,4);
goto P_0c0a9580;
P_0c0a9580: /* original 4f26, guest PC 0x0c0a9580 */
if(!s->budget--) { s->failed_pc=0x0c0a9580u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9582;
P_0c0a9582: /* original 64e3, guest PC 0x0c0a9582 */
if(!s->budget--) { s->failed_pc=0x0c0a9582u; return 0; }
r[4]=r[14];
goto P_0c0a9584;
P_0c0a9584: /* original 422b, guest PC 0x0c0a9584 */
if(!s->budget--) { s->failed_pc=0x0c0a9584u; return 0; }
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
P_0c0a9586: /* original 6ef6, guest PC 0x0c0a9586 */
if(!s->budget--) { s->failed_pc=0x0c0a9586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9588;
P_0c0a9588: /* original 7f14, guest PC 0x0c0a9588 */
if(!s->budget--) { s->failed_pc=0x0c0a9588u; return 0; }
r[15]+=0x00000014u;
goto P_0c0a958a;
P_0c0a958a: /* original 4f26, guest PC 0x0c0a958a */
if(!s->budget--) { s->failed_pc=0x0c0a958au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a958c;
P_0c0a958c: /* original 000b, guest PC 0x0c0a958c */
if(!s->budget--) { s->failed_pc=0x0c0a958cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a958e: /* original 6ef6, guest PC 0x0c0a958e */
if(!s->budget--) { s->failed_pc=0x0c0a958eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9590u,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae13au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae14cu) { target=s->pc; goto dispatch; }
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
target=0x0c0ad178u; r[16]=code_base|0x0c0ae15cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae15cu) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c0ae160u,s,ram);
P_0c0ae184: /* original d33a, guest PC 0x0c0ae184 */
if(!s->budget--) { s->failed_pc=0x0c0ae184u; return 0; }
r[3]=read(ram,0x0c0ae270u,4);
goto P_0c0ae186;
P_0c0ae186: /* original 430b, guest PC 0x0c0ae186 */
if(!s->budget--) { s->failed_pc=0x0c0ae186u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae18au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae18au) { target=s->pc; goto dispatch; }
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
target=0x0c0ae29cu; r[16]=code_base|0x0c0ae252u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae252u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c0ae25cu,s,ram);
P_0c0bef2e: /* original 4f22, guest PC 0x0c0bef2e */
if(!s->budget--) { s->failed_pc=0x0c0bef2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bef30;
P_0c0bef30: /* original 5a46, guest PC 0x0c0bef30 */
if(!s->budget--) { s->failed_pc=0x0c0bef30u; return 0; }
r[10]=read(ram,r[4]+24,4);
goto P_0c0bef32;
P_0c0bef32: /* original de48, guest PC 0x0c0bef32 */
if(!s->budget--) { s->failed_pc=0x0c0bef32u; return 0; }
r[14]=read(ram,0x0c0bf054u,4);
goto P_0c0bef34;
P_0c0bef34: /* original 6da3, guest PC 0x0c0bef34 */
if(!s->budget--) { s->failed_pc=0x0c0bef34u; return 0; }
r[13]=r[10];
goto P_0c0bef36;
P_0c0bef36: /* original 7ffc, guest PC 0x0c0bef36 */
if(!s->budget--) { s->failed_pc=0x0c0bef36u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0bef38;
P_0c0bef38: /* original 8d10, guest PC 0x0c0bef38 */
if(!s->budget--) { s->failed_pc=0x0c0bef38u; return 0; }
cond=r[17]&1u;
r[13]<<=2;
if(cond) { goto P_0c0bef5c; }
goto P_0c0bef3c;
P_0c0bef3a: /* original 4d08, guest PC 0x0c0bef3a */
if(!s->budget--) { s->failed_pc=0x0c0bef3au; return 0; }
r[13]<<=2;
goto P_0c0bef3c;
P_0c0bef3c: /* original 9278, guest PC 0x0c0bef3c */
if(!s->budget--) { s->failed_pc=0x0c0bef3cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf030u,2);
goto P_0c0bef3e;
P_0c0bef3e: /* original e400, guest PC 0x0c0bef3e */
if(!s->budget--) { s->failed_pc=0x0c0bef3eu; return 0; }
r[4]=0x00000000u;
goto P_0c0bef40;
P_0c0bef40: /* original 32ec, guest PC 0x0c0bef40 */
if(!s->budget--) { s->failed_pc=0x0c0bef40u; return 0; }
r[2]+=r[14];
goto P_0c0bef42;
P_0c0bef42: /* original 32dc, guest PC 0x0c0bef42 */
if(!s->budget--) { s->failed_pc=0x0c0bef42u; return 0; }
r[2]+=r[13];
goto P_0c0bef44;
P_0c0bef44: /* original 2242, guest PC 0x0c0bef44 */
if(!s->budget--) { s->failed_pc=0x0c0bef44u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0bef46;
P_0c0bef46: /* original 9374, guest PC 0x0c0bef46 */
if(!s->budget--) { s->failed_pc=0x0c0bef46u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf032u,2);
goto P_0c0bef48;
P_0c0bef48: /* original 33ec, guest PC 0x0c0bef48 */
if(!s->budget--) { s->failed_pc=0x0c0bef48u; return 0; }
r[3]+=r[14];
goto P_0c0bef4a;
P_0c0bef4a: /* original 33dc, guest PC 0x0c0bef4a */
if(!s->budget--) { s->failed_pc=0x0c0bef4au; return 0; }
r[3]+=r[13];
goto P_0c0bef4c;
P_0c0bef4c: /* original 2342, guest PC 0x0c0bef4c */
if(!s->budget--) { s->failed_pc=0x0c0bef4cu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0bef4e;
P_0c0bef4e: /* original e3ff, guest PC 0x0c0bef4e */
if(!s->budget--) { s->failed_pc=0x0c0bef4eu; return 0; }
r[3]=0xffffffffu;
goto P_0c0bef50;
P_0c0bef50: /* original 9270, guest PC 0x0c0bef50 */
if(!s->budget--) { s->failed_pc=0x0c0bef50u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf034u,2);
goto P_0c0bef52;
P_0c0bef52: /* original 32ec, guest PC 0x0c0bef52 */
if(!s->budget--) { s->failed_pc=0x0c0bef52u; return 0; }
r[2]+=r[14];
goto P_0c0bef54;
P_0c0bef54: /* original 32dc, guest PC 0x0c0bef54 */
if(!s->budget--) { s->failed_pc=0x0c0bef54u; return 0; }
r[2]+=r[13];
goto P_0c0bef56;
P_0c0bef56: /* original 2232, guest PC 0x0c0bef56 */
if(!s->budget--) { s->failed_pc=0x0c0bef56u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0bef58;
P_0c0bef58: /* original a061, guest PC 0x0c0bef58 */
if(!s->budget--) { s->failed_pc=0x0c0bef58u; return 0; }
goto P_0c0bf01e;
P_0c0bef5a: /* original 0009, guest PC 0x0c0bef5a */
if(!s->budget--) { s->failed_pc=0x0c0bef5au; return 0; }
goto P_0c0bef5c;
P_0c0bef5c: /* original 9368, guest PC 0x0c0bef5c */
if(!s->budget--) { s->failed_pc=0x0c0bef5cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf030u,2);
goto P_0c0bef5e;
P_0c0bef5e: /* original d03e, guest PC 0x0c0bef5e */
if(!s->budget--) { s->failed_pc=0x0c0bef5eu; return 0; }
r[0]=read(ram,0x0c0bf058u,4);
goto P_0c0bef60;
P_0c0bef60: /* original 33ec, guest PC 0x0c0bef60 */
if(!s->budget--) { s->failed_pc=0x0c0bef60u; return 0; }
r[3]+=r[14];
goto P_0c0bef62;
P_0c0bef62: /* original 9c67, guest PC 0x0c0bef62 */
if(!s->budget--) { s->failed_pc=0x0c0bef62u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf034u,2);
goto P_0c0bef64;
P_0c0bef64: /* original 02de, guest PC 0x0c0bef64 */
if(!s->budget--) { s->failed_pc=0x0c0bef64u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0bef66;
P_0c0bef66: /* original 33dc, guest PC 0x0c0bef66 */
if(!s->budget--) { s->failed_pc=0x0c0bef66u; return 0; }
r[3]+=r[13];
goto P_0c0bef68;
P_0c0bef68: /* original 3cec, guest PC 0x0c0bef68 */
if(!s->budget--) { s->failed_pc=0x0c0bef68u; return 0; }
r[12]+=r[14];
goto P_0c0bef6a;
P_0c0bef6a: /* original 3cdc, guest PC 0x0c0bef6a */
if(!s->budget--) { s->failed_pc=0x0c0bef6au; return 0; }
r[12]+=r[13];
goto P_0c0bef6c;
P_0c0bef6c: /* original 6cc2, guest PC 0x0c0bef6c */
if(!s->budget--) { s->failed_pc=0x0c0bef6cu; return 0; }
tmp=read(ram,r[12],4);
r[12]=tmp;
goto P_0c0bef6e;
P_0c0bef6e: /* original 2322, guest PC 0x0c0bef6e */
if(!s->budget--) { s->failed_pc=0x0c0bef6eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0bef70;
P_0c0bef70: /* original 9b5e, guest PC 0x0c0bef70 */
if(!s->budget--) { s->failed_pc=0x0c0bef70u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf030u,2);
goto P_0c0bef72;
P_0c0bef72: /* original d03a, guest PC 0x0c0bef72 */
if(!s->budget--) { s->failed_pc=0x0c0bef72u; return 0; }
r[0]=read(ram,0x0c0bf05cu,4);
goto P_0c0bef74;
P_0c0bef74: /* original 3bec, guest PC 0x0c0bef74 */
if(!s->budget--) { s->failed_pc=0x0c0bef74u; return 0; }
r[11]+=r[14];
goto P_0c0bef76;
P_0c0bef76: /* original 3bdc, guest PC 0x0c0bef76 */
if(!s->budget--) { s->failed_pc=0x0c0bef76u; return 0; }
r[11]+=r[13];
goto P_0c0bef78;
P_0c0bef78: /* original 03dd, guest PC 0x0c0bef78 */
if(!s->budget--) { s->failed_pc=0x0c0bef78u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0bef7a;
P_0c0bef7a: /* original 6bb2, guest PC 0x0c0bef7a */
if(!s->budget--) { s->failed_pc=0x0c0bef7au; return 0; }
tmp=read(ram,r[11],4);
r[11]=tmp;
goto P_0c0bef7c;
P_0c0bef7c: /* original 2f32, guest PC 0x0c0bef7c */
if(!s->budget--) { s->failed_pc=0x0c0bef7cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0bef7e;
P_0c0bef7e: /* original 6633, guest PC 0x0c0bef7e */
if(!s->budget--) { s->failed_pc=0x0c0bef7eu; return 0; }
r[6]=r[3];
goto P_0c0bef80;
P_0c0bef80: /* original d132, guest PC 0x0c0bef80 */
if(!s->budget--) { s->failed_pc=0x0c0bef80u; return 0; }
r[1]=read(ram,0x0c0bf04cu,4);
goto P_0c0bef82;
P_0c0bef82: /* original d231, guest PC 0x0c0bef82 */
if(!s->budget--) { s->failed_pc=0x0c0bef82u; return 0; }
r[2]=read(ram,0x0c0bf048u,4);
goto P_0c0bef84;
P_0c0bef84: /* original 6512, guest PC 0x0c0bef84 */
if(!s->budget--) { s->failed_pc=0x0c0bef84u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c0bef86;
P_0c0bef86: /* original 352c, guest PC 0x0c0bef86 */
if(!s->budget--) { s->failed_pc=0x0c0bef86u; return 0; }
r[5]+=r[2];
goto P_0c0bef88;
P_0c0bef88: /* original d235, guest PC 0x0c0bef88 */
if(!s->budget--) { s->failed_pc=0x0c0bef88u; return 0; }
r[2]=read(ram,0x0c0bf060u,4);
goto P_0c0bef8a;
P_0c0bef8a: /* original 420b, guest PC 0x0c0bef8a */
if(!s->budget--) { s->failed_pc=0x0c0bef8au; return 0; }
target=r[2];
r[16]=code_base|0x0c0bef8eu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bef8eu) { target=s->pc; goto dispatch; }
goto P_0c0bef8e;
P_0c0bef8c: /* original 64b3, guest PC 0x0c0bef8c */
if(!s->budget--) { s->failed_pc=0x0c0bef8cu; return 0; }
r[4]=r[11];
goto P_0c0bef8e;
P_0c0bef8e: /* original 60c3, guest PC 0x0c0bef8e */
if(!s->budget--) { s->failed_pc=0x0c0bef8eu; return 0; }
r[0]=r[12];
goto P_0c0bef90;
P_0c0bef90: /* original 8809, guest PC 0x0c0bef90 */
if(!s->budget--) { s->failed_pc=0x0c0bef90u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0bef92;
P_0c0bef92: /* original 8934, guest PC 0x0c0bef92 */
if(!s->budget--) { s->failed_pc=0x0c0bef92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0beffe; }
goto P_0c0bef94;
P_0c0bef94: /* original 60c3, guest PC 0x0c0bef94 */
if(!s->budget--) { s->failed_pc=0x0c0bef94u; return 0; }
r[0]=r[12];
goto P_0c0bef96;
P_0c0bef96: /* original 8816, guest PC 0x0c0bef96 */
if(!s->budget--) { s->failed_pc=0x0c0bef96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c0bef98;
P_0c0bef98: /* original 8931, guest PC 0x0c0bef98 */
if(!s->budget--) { s->failed_pc=0x0c0bef98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0beffe; }
goto P_0c0bef9a;
P_0c0bef9a: /* original 54b6, guest PC 0x0c0bef9a */
if(!s->budget--) { s->failed_pc=0x0c0bef9au; return 0; }
r[4]=read(ram,r[11]+24,4);
goto P_0c0bef9c;
P_0c0bef9c: /* original e700, guest PC 0x0c0bef9c */
if(!s->budget--) { s->failed_pc=0x0c0bef9cu; return 0; }
r[7]=0x00000000u;
goto P_0c0bef9e;
P_0c0bef9e: /* original 9148, guest PC 0x0c0bef9e */
if(!s->budget--) { s->failed_pc=0x0c0bef9eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf032u,2);
goto P_0c0befa0;
P_0c0befa0: /* original 9349, guest PC 0x0c0befa0 */
if(!s->budget--) { s->failed_pc=0x0c0befa0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf036u,2);
goto P_0c0befa2;
P_0c0befa2: /* original 34bc, guest PC 0x0c0befa2 */
if(!s->budget--) { s->failed_pc=0x0c0befa2u; return 0; }
r[4]+=r[11];
goto P_0c0befa4;
P_0c0befa4: /* original 9248, guest PC 0x0c0befa4 */
if(!s->budget--) { s->failed_pc=0x0c0befa4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf038u,2);
goto P_0c0befa6;
P_0c0befa6: /* original 31ec, guest PC 0x0c0befa6 */
if(!s->budget--) { s->failed_pc=0x0c0befa6u; return 0; }
r[1]+=r[14];
goto P_0c0befa8;
P_0c0befa8: /* original 343c, guest PC 0x0c0befa8 */
if(!s->budget--) { s->failed_pc=0x0c0befa8u; return 0; }
r[4]+=r[3];
goto P_0c0befaa;
P_0c0befaa: /* original 31dc, guest PC 0x0c0befaa */
if(!s->budget--) { s->failed_pc=0x0c0befaau; return 0; }
r[1]+=r[13];
goto P_0c0befac;
P_0c0befac: /* original 2429, guest PC 0x0c0befac */
if(!s->budget--) { s->failed_pc=0x0c0befacu; return 0; }
r[4]&=r[2];
goto P_0c0befae;
P_0c0befae: /* original 62c3, guest PC 0x0c0befae */
if(!s->budget--) { s->failed_pc=0x0c0befaeu; return 0; }
r[2]=r[12];
goto P_0c0befb0;
P_0c0befb0: /* original 2142, guest PC 0x0c0befb0 */
if(!s->budget--) { s->failed_pc=0x0c0befb0u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c0befb2;
P_0c0befb2: /* original 64c3, guest PC 0x0c0befb2 */
if(!s->budget--) { s->failed_pc=0x0c0befb2u; return 0; }
r[4]=r[12];
goto P_0c0befb4;
P_0c0befb4: /* original 4408, guest PC 0x0c0befb4 */
if(!s->budget--) { s->failed_pc=0x0c0befb4u; return 0; }
r[4]<<=2;
goto P_0c0befb6;
P_0c0befb6: /* original 9040, guest PC 0x0c0befb6 */
if(!s->budget--) { s->failed_pc=0x0c0befb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf03au,2);
goto P_0c0befb8;
P_0c0befb8: /* original 4400, guest PC 0x0c0befb8 */
if(!s->budget--) { s->failed_pc=0x0c0befb8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0befba;
P_0c0befba: /* original 342c, guest PC 0x0c0befba */
if(!s->budget--) { s->failed_pc=0x0c0befbau; return 0; }
r[4]+=r[2];
goto P_0c0befbc;
P_0c0befbc: /* original 2f06, guest PC 0x0c0befbc */
if(!s->budget--) { s->failed_pc=0x0c0befbcu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0befbe;
P_0c0befbe: /* original d329, guest PC 0x0c0befbe */
if(!s->budget--) { s->failed_pc=0x0c0befbeu; return 0; }
r[3]=read(ram,0x0c0bf064u,4);
goto P_0c0befc0;
P_0c0befc0: /* original 4408, guest PC 0x0c0befc0 */
if(!s->budget--) { s->failed_pc=0x0c0befc0u; return 0; }
r[4]<<=2;
goto P_0c0befc2;
P_0c0befc2: /* original 2f36, guest PC 0x0c0befc2 */
if(!s->budget--) { s->failed_pc=0x0c0befc2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0befc4;
P_0c0befc4: /* original 2fa6, guest PC 0x0c0befc4 */
if(!s->budget--) { s->failed_pc=0x0c0befc4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0befc6;
P_0c0befc6: /* original 9534, guest PC 0x0c0befc6 */
if(!s->budget--) { s->failed_pc=0x0c0befc6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf032u,2);
goto P_0c0befc8;
P_0c0befc8: /* original d128, guest PC 0x0c0befc8 */
if(!s->budget--) { s->failed_pc=0x0c0befc8u; return 0; }
r[1]=read(ram,0x0c0bf06cu,4);
goto P_0c0befca;
P_0c0befca: /* original 35ec, guest PC 0x0c0befca */
if(!s->budget--) { s->failed_pc=0x0c0befcau; return 0; }
r[5]+=r[14];
goto P_0c0befcc;
P_0c0befcc: /* original d626, guest PC 0x0c0befcc */
if(!s->budget--) { s->failed_pc=0x0c0befccu; return 0; }
r[6]=read(ram,0x0c0bf068u,4);
goto P_0c0befce;
P_0c0befce: /* original 35dc, guest PC 0x0c0befce */
if(!s->budget--) { s->failed_pc=0x0c0befceu; return 0; }
r[5]+=r[13];
goto P_0c0befd0;
P_0c0befd0: /* original 341c, guest PC 0x0c0befd0 */
if(!s->budget--) { s->failed_pc=0x0c0befd0u; return 0; }
r[4]+=r[1];
goto P_0c0befd2;
P_0c0befd2: /* original 6552, guest PC 0x0c0befd2 */
if(!s->budget--) { s->failed_pc=0x0c0befd2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0befd4;
P_0c0befd4: /* original 1f43, guest PC 0x0c0befd4 */
if(!s->budget--) { s->failed_pc=0x0c0befd4u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c0befd6;
P_0c0befd6: /* original d31e, guest PC 0x0c0befd6 */
if(!s->budget--) { s->failed_pc=0x0c0befd6u; return 0; }
r[3]=read(ram,0x0c0bf050u,4);
goto P_0c0befd8;
P_0c0befd8: /* original 430b, guest PC 0x0c0befd8 */
if(!s->budget--) { s->failed_pc=0x0c0befd8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0befdcu;
r[4]=read(ram,r[4]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0befdcu) { target=s->pc; goto dispatch; }
goto P_0c0befdc;
P_0c0befda: /* original 5444, guest PC 0x0c0befda */
if(!s->budget--) { s->failed_pc=0x0c0befdau; return 0; }
r[4]=read(ram,r[4]+16,4);
goto P_0c0befdc;
P_0c0befdc: /* original 922e, guest PC 0x0c0befdc */
if(!s->budget--) { s->failed_pc=0x0c0befdcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf03cu,2);
goto P_0c0befde;
P_0c0befde: /* original 2f26, guest PC 0x0c0befde */
if(!s->budget--) { s->failed_pc=0x0c0befdeu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0befe0;
P_0c0befe0: /* original d320, guest PC 0x0c0befe0 */
if(!s->budget--) { s->failed_pc=0x0c0befe0u; return 0; }
r[3]=read(ram,0x0c0bf064u,4);
goto P_0c0befe2;
P_0c0befe2: /* original 2f36, guest PC 0x0c0befe2 */
if(!s->budget--) { s->failed_pc=0x0c0befe2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0befe4;
P_0c0befe4: /* original 2fa6, guest PC 0x0c0befe4 */
if(!s->budget--) { s->failed_pc=0x0c0befe4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0befe6;
P_0c0befe6: /* original d319, guest PC 0x0c0befe6 */
if(!s->budget--) { s->failed_pc=0x0c0befe6u; return 0; }
r[3]=read(ram,0x0c0bf04cu,4);
goto P_0c0befe8;
P_0c0befe8: /* original d117, guest PC 0x0c0befe8 */
if(!s->budget--) { s->failed_pc=0x0c0befe8u; return 0; }
r[1]=read(ram,0x0c0bf048u,4);
goto P_0c0befea;
P_0c0befea: /* original 6532, guest PC 0x0c0befea */
if(!s->budget--) { s->failed_pc=0x0c0befeau; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0befec;
P_0c0befec: /* original d318, guest PC 0x0c0befec */
if(!s->budget--) { s->failed_pc=0x0c0befecu; return 0; }
r[3]=read(ram,0x0c0bf050u,4);
goto P_0c0befee;
P_0c0befee: /* original 54f6, guest PC 0x0c0befee */
if(!s->budget--) { s->failed_pc=0x0c0befeeu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0beff0;
P_0c0beff0: /* original 351c, guest PC 0x0c0beff0 */
if(!s->budget--) { s->failed_pc=0x0c0beff0u; return 0; }
r[5]+=r[1];
goto P_0c0beff2;
P_0c0beff2: /* original d71f, guest PC 0x0c0beff2 */
if(!s->budget--) { s->failed_pc=0x0c0beff2u; return 0; }
r[7]=read(ram,0x0c0bf070u,4);
goto P_0c0beff4;
P_0c0beff4: /* original d61c, guest PC 0x0c0beff4 */
if(!s->budget--) { s->failed_pc=0x0c0beff4u; return 0; }
r[6]=read(ram,0x0c0bf068u,4);
goto P_0c0beff6;
P_0c0beff6: /* original 430b, guest PC 0x0c0beff6 */
if(!s->budget--) { s->failed_pc=0x0c0beff6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0beffau;
r[4]=read(ram,r[4]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0beffau) { target=s->pc; goto dispatch; }
goto P_0c0beffa;
P_0c0beff8: /* original 5445, guest PC 0x0c0beff8 */
if(!s->budget--) { s->failed_pc=0x0c0beff8u; return 0; }
r[4]=read(ram,r[4]+20,4);
goto P_0c0beffa;
P_0c0beffa: /* original a010, guest PC 0x0c0beffa */
if(!s->budget--) { s->failed_pc=0x0c0beffau; return 0; }
r[15]+=0x00000018u;
goto P_0c0bf01e;
P_0c0beffc: /* original 7f18, guest PC 0x0c0beffc */
if(!s->budget--) { s->failed_pc=0x0c0beffcu; return 0; }
r[15]+=0x00000018u;
goto P_0c0beffe;
P_0c0beffe: /* original 63c3, guest PC 0x0c0beffe */
if(!s->budget--) { s->failed_pc=0x0c0beffeu; return 0; }
r[3]=r[12];
goto P_0c0bf000;
P_0c0bf000: /* original 4c08, guest PC 0x0c0bf000 */
if(!s->budget--) { s->failed_pc=0x0c0bf000u; return 0; }
r[12]<<=2;
goto P_0c0bf002;
P_0c0bf002: /* original 4c00, guest PC 0x0c0bf002 */
if(!s->budget--) { s->failed_pc=0x0c0bf002u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0bf004;
P_0c0bf004: /* original d01b, guest PC 0x0c0bf004 */
if(!s->budget--) { s->failed_pc=0x0c0bf004u; return 0; }
r[0]=read(ram,0x0c0bf074u,4);
goto P_0c0bf006;
P_0c0bf006: /* original 3c3c, guest PC 0x0c0bf006 */
if(!s->budget--) { s->failed_pc=0x0c0bf006u; return 0; }
r[12]+=r[3];
goto P_0c0bf008;
P_0c0bf008: /* original 4c08, guest PC 0x0c0bf008 */
if(!s->budget--) { s->failed_pc=0x0c0bf008u; return 0; }
r[12]<<=2;
goto P_0c0bf00a;
P_0c0bf00a: /* original 02ce, guest PC 0x0c0bf00a */
if(!s->budget--) { s->failed_pc=0x0c0bf00au; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0bf00c;
P_0c0bf00c: /* original 6323, guest PC 0x0c0bf00c */
if(!s->budget--) { s->failed_pc=0x0c0bf00cu; return 0; }
r[3]=r[2];
goto P_0c0bf00e;
P_0c0bf00e: /* original 2f22, guest PC 0x0c0bf00e */
if(!s->budget--) { s->failed_pc=0x0c0bf00eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0bf010;
P_0c0bf010: /* original 430b, guest PC 0x0c0bf010 */
if(!s->budget--) { s->failed_pc=0x0c0bf010u; return 0; }
target=r[3];
r[16]=code_base|0x0c0bf014u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bf014u) { target=s->pc; goto dispatch; }
goto P_0c0bf014;
P_0c0bf012: /* original 64b3, guest PC 0x0c0bf012 */
if(!s->budget--) { s->failed_pc=0x0c0bf012u; return 0; }
r[4]=r[11];
goto P_0c0bf014;
P_0c0bf014: /* original 9313, guest PC 0x0c0bf014 */
if(!s->budget--) { s->failed_pc=0x0c0bf014u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf03eu,2);
goto P_0c0bf016;
P_0c0bf016: /* original e2ff, guest PC 0x0c0bf016 */
if(!s->budget--) { s->failed_pc=0x0c0bf016u; return 0; }
r[2]=0xffffffffu;
goto P_0c0bf018;
P_0c0bf018: /* original 33ec, guest PC 0x0c0bf018 */
if(!s->budget--) { s->failed_pc=0x0c0bf018u; return 0; }
r[3]+=r[14];
goto P_0c0bf01a;
P_0c0bf01a: /* original 33dc, guest PC 0x0c0bf01a */
if(!s->budget--) { s->failed_pc=0x0c0bf01au; return 0; }
r[3]+=r[13];
goto P_0c0bf01c;
P_0c0bf01c: /* original 2322, guest PC 0x0c0bf01c */
if(!s->budget--) { s->failed_pc=0x0c0bf01cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0bf01e;
P_0c0bf01e: /* original 7f04, guest PC 0x0c0bf01e */
if(!s->budget--) { s->failed_pc=0x0c0bf01eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0bf020;
P_0c0bf020: /* original 4f26, guest PC 0x0c0bf020 */
if(!s->budget--) { s->failed_pc=0x0c0bf020u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bf022;
P_0c0bf022: /* original e000, guest PC 0x0c0bf022 */
if(!s->budget--) { s->failed_pc=0x0c0bf022u; return 0; }
r[0]=0x00000000u;
goto P_0c0bf024;
P_0c0bf024: /* original 6af6, guest PC 0x0c0bf024 */
if(!s->budget--) { s->failed_pc=0x0c0bf024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bf026;
P_0c0bf026: /* original 6bf6, guest PC 0x0c0bf026 */
if(!s->budget--) { s->failed_pc=0x0c0bf026u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bf028;
P_0c0bf028: /* original 6cf6, guest PC 0x0c0bf028 */
if(!s->budget--) { s->failed_pc=0x0c0bf028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bf02a;
P_0c0bf02a: /* original 6df6, guest PC 0x0c0bf02a */
if(!s->budget--) { s->failed_pc=0x0c0bf02au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bf02c;
P_0c0bf02c: /* original 000b, guest PC 0x0c0bf02c */
if(!s->budget--) { s->failed_pc=0x0c0bf02cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bf02e: /* original 6ef6, guest PC 0x0c0bf02e */
if(!s->budget--) { s->failed_pc=0x0c0bf02eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0bf030u,s,ram);
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
P_0c0c7e1c: /* original 2fe6, guest PC 0x0c0c7e1c */
if(!s->budget--) { s->failed_pc=0x0c0c7e1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e1e;
P_0c0c7e1e: /* original e00c, guest PC 0x0c0c7e1e */
if(!s->budget--) { s->failed_pc=0x0c0c7e1eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e20;
P_0c0c7e20: /* original 2fd6, guest PC 0x0c0c7e20 */
if(!s->budget--) { s->failed_pc=0x0c0c7e20u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e22;
P_0c0c7e22: /* original 6d53, guest PC 0x0c0c7e22 */
if(!s->budget--) { s->failed_pc=0x0c0c7e22u; return 0; }
r[13]=r[5];
goto P_0c0c7e24;
P_0c0c7e24: /* original 2fc6, guest PC 0x0c0c7e24 */
if(!s->budget--) { s->failed_pc=0x0c0c7e24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e26;
P_0c0c7e26: /* original 2fb6, guest PC 0x0c0c7e26 */
if(!s->budget--) { s->failed_pc=0x0c0c7e26u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e28;
P_0c0c7e28: /* original fffb, guest PC 0x0c0c7e28 */
if(!s->budget--) { s->failed_pc=0x0c0c7e28u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c7e2a;
P_0c0c7e2a: /* original 4f22, guest PC 0x0c0c7e2a */
if(!s->budget--) { s->failed_pc=0x0c0c7e2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7e2c;
P_0c0c7e2c: /* original 7fec, guest PC 0x0c0c7e2c */
if(!s->budget--) { s->failed_pc=0x0c0c7e2cu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0c7e2e;
P_0c0c7e2e: /* original ff47, guest PC 0x0c0c7e2e */
if(!s->budget--) { s->failed_pc=0x0c0c7e2eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e30;
P_0c0c7e30: /* original e010, guest PC 0x0c0c7e30 */
if(!s->budget--) { s->failed_pc=0x0c0c7e30u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e32;
P_0c0c7e32: /* original ff67, guest PC 0x0c0c7e32 */
if(!s->budget--) { s->failed_pc=0x0c0c7e32u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0c7e34;
P_0c0c7e34: /* original 1f62, guest PC 0x0c0c7e34 */
if(!s->budget--) { s->failed_pc=0x0c0c7e34u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0c7e36;
P_0c0c7e36: /* original dc37, guest PC 0x0c0c7e36 */
if(!s->budget--) { s->failed_pc=0x0c0c7e36u; return 0; }
r[12]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7e38;
P_0c0c7e38: /* original bfd6, guest PC 0x0c0c7e38 */
if(!s->budget--) { s->failed_pc=0x0c0c7e38u; return 0; }
target=0x0c0c7de8u; r[16]=code_base|0x0c0c7e3cu;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7e3cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e3c;
P_0c0c7e3a: /* original 6e43, guest PC 0x0c0c7e3a */
if(!s->budget--) { s->failed_pc=0x0c0c7e3au; return 0; }
r[14]=r[4];
goto P_0c0c7e3c;
P_0c0c7e3c: /* original 60d3, guest PC 0x0c0c7e3c */
if(!s->budget--) { s->failed_pc=0x0c0c7e3cu; return 0; }
r[0]=r[13];
goto P_0c0c7e3e;
P_0c0c7e3e: /* original 80e4, guest PC 0x0c0c7e3e */
if(!s->budget--) { s->failed_pc=0x0c0c7e3eu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0c7e40;
P_0c0c7e40: /* original e01c, guest PC 0x0c0c7e40 */
if(!s->budget--) { s->failed_pc=0x0c0c7e40u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7e42;
P_0c0c7e42: /* original d337, guest PC 0x0c0c7e42 */
if(!s->budget--) { s->failed_pc=0x0c0c7e42u; return 0; }
r[3]=read(ram,0x0c0c7f20u,4);
goto P_0c0c7e44;
P_0c0c7e44: /* original 04cc, guest PC 0x0c0c7e44 */
if(!s->budget--) { s->failed_pc=0x0c0c7e44u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c7e46;
P_0c0c7e46: /* original e032, guest PC 0x0c0c7e46 */
if(!s->budget--) { s->failed_pc=0x0c0c7e46u; return 0; }
r[0]=0x00000032u;
goto P_0c0c7e48;
P_0c0c7e48: /* original 65f3, guest PC 0x0c0c7e48 */
if(!s->budget--) { s->failed_pc=0x0c0c7e48u; return 0; }
r[5]=r[15];
goto P_0c0c7e4a;
P_0c0c7e4a: /* original 7504, guest PC 0x0c0c7e4a */
if(!s->budget--) { s->failed_pc=0x0c0c7e4au; return 0; }
r[5]+=0x00000004u;
goto P_0c0c7e4c;
P_0c0c7e4c: /* original 644c, guest PC 0x0c0c7e4c */
if(!s->budget--) { s->failed_pc=0x0c0c7e4cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7e4e;
P_0c0c7e4e: /* original 66f3, guest PC 0x0c0c7e4e */
if(!s->budget--) { s->failed_pc=0x0c0c7e4eu; return 0; }
r[6]=r[15];
goto P_0c0c7e50;
P_0c0c7e50: /* original 4408, guest PC 0x0c0c7e50 */
if(!s->budget--) { s->failed_pc=0x0c0c7e50u; return 0; }
r[4]<<=2;
goto P_0c0c7e52;
P_0c0c7e52: /* original 4408, guest PC 0x0c0c7e52 */
if(!s->budget--) { s->failed_pc=0x0c0c7e52u; return 0; }
r[4]<<=2;
goto P_0c0c7e54;
P_0c0c7e54: /* original 4408, guest PC 0x0c0c7e54 */
if(!s->budget--) { s->failed_pc=0x0c0c7e54u; return 0; }
r[4]<<=2;
goto P_0c0c7e56;
P_0c0c7e56: /* original 343c, guest PC 0x0c0c7e56 */
if(!s->budget--) { s->failed_pc=0x0c0c7e56u; return 0; }
r[4]+=r[3];
goto P_0c0c7e58;
P_0c0c7e58: /* original 0b4d, guest PC 0x0c0c7e58 */
if(!s->budget--) { s->failed_pc=0x0c0c7e58u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c7e5a;
P_0c0c7e5a: /* original e028, guest PC 0x0c0c7e5a */
if(!s->budget--) { s->failed_pc=0x0c0c7e5au; return 0; }
r[0]=0x00000028u;
goto P_0c0c7e5c;
P_0c0c7e5c: /* original f446, guest PC 0x0c0c7e5c */
if(!s->budget--) { s->failed_pc=0x0c0c7e5cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0c7e5e;
P_0c0c7e5e: /* original e00c, guest PC 0x0c0c7e5e */
if(!s->budget--) { s->failed_pc=0x0c0c7e5eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e60;
P_0c0c7e60: /* original f34c, guest PC 0x0c0c7e60 */
if(!s->budget--) { s->failed_pc=0x0c0c7e60u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0c7e62;
P_0c0c7e62: /* original f4f6, guest PC 0x0c0c7e62 */
if(!s->budget--) { s->failed_pc=0x0c0c7e62u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e64;
P_0c0c7e64: /* original e010, guest PC 0x0c0c7e64 */
if(!s->budget--) { s->failed_pc=0x0c0c7e64u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e66;
P_0c0c7e66: /* original f5f6, guest PC 0x0c0c7e66 */
if(!s->budget--) { s->failed_pc=0x0c0c7e66u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c7e68;
P_0c0c7e68: /* original e004, guest PC 0x0c0c7e68 */
if(!s->budget--) { s->failed_pc=0x0c0c7e68u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e6a;
P_0c0c7e6a: /* original f430, guest PC 0x0c0c7e6a */
if(!s->budget--) { s->failed_pc=0x0c0c7e6au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0c7e6c;
P_0c0c7e6c: /* original ff47, guest PC 0x0c0c7e6c */
if(!s->budget--) { s->failed_pc=0x0c0c7e6cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e6e;
P_0c0c7e6e: /* original ff5a, guest PC 0x0c0c7e6e */
if(!s->budget--) { s->failed_pc=0x0c0c7e6eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c0c7e70;
P_0c0c7e70: /* original d22c, guest PC 0x0c0c7e70 */
if(!s->budget--) { s->failed_pc=0x0c0c7e70u; return 0; }
r[2]=read(ram,0x0c0c7f24u,4);
goto P_0c0c7e72;
P_0c0c7e72: /* original 420b, guest PC 0x0c0c7e72 */
if(!s->budget--) { s->failed_pc=0x0c0c7e72u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7e76u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7e76u) { target=s->pc; goto dispatch; }
goto P_0c0c7e76;
P_0c0c7e74: /* original 64b3, guest PC 0x0c0c7e74 */
if(!s->budget--) { s->failed_pc=0x0c0c7e74u; return 0; }
r[4]=r[11];
goto P_0c0c7e76;
P_0c0c7e76: /* original e004, guest PC 0x0c0c7e76 */
if(!s->budget--) { s->failed_pc=0x0c0c7e76u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e78;
P_0c0c7e78: /* original fff8, guest PC 0x0c0c7e78 */
if(!s->budget--) { s->failed_pc=0x0c0c7e78u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0c7e7a;
P_0c0c7e7a: /* original f4f6, guest PC 0x0c0c7e7a */
if(!s->budget--) { s->failed_pc=0x0c0c7e7au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e7c;
P_0c0c7e7c: /* original e010, guest PC 0x0c0c7e7c */
if(!s->budget--) { s->failed_pc=0x0c0c7e7cu; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e7e;
P_0c0c7e7e: /* original 54f2, guest PC 0x0c0c7e7e */
if(!s->budget--) { s->failed_pc=0x0c0c7e7eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c7e80;
P_0c0c7e80: /* original fe47, guest PC 0x0c0c7e80 */
if(!s->budget--) { s->failed_pc=0x0c0c7e80u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e82;
P_0c0c7e82: /* original e018, guest PC 0x0c0c7e82 */
if(!s->budget--) { s->failed_pc=0x0c0c7e82u; return 0; }
r[0]=0x00000018u;
goto P_0c0c7e84;
P_0c0c7e84: /* original fef7, guest PC 0x0c0c7e84 */
if(!s->budget--) { s->failed_pc=0x0c0c7e84u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e86;
P_0c0c7e86: /* original 34bc, guest PC 0x0c0c7e86 */
if(!s->budget--) { s->failed_pc=0x0c0c7e86u; return 0; }
r[4]+=r[11];
goto P_0c0c7e88;
P_0c0c7e88: /* original 903d, guest PC 0x0c0c7e88 */
if(!s->budget--) { s->failed_pc=0x0c0c7e88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f06u,2);
goto P_0c0c7e8a;
P_0c0c7e8a: /* original fe47, guest PC 0x0c0c7e8a */
if(!s->budget--) { s->failed_pc=0x0c0c7e8au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e8c;
P_0c0c7e8c: /* original 7008, guest PC 0x0c0c7e8c */
if(!s->budget--) { s->failed_pc=0x0c0c7e8cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c7e8e;
P_0c0c7e8e: /* original fef7, guest PC 0x0c0c7e8e */
if(!s->budget--) { s->failed_pc=0x0c0c7e8eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e90;
P_0c0c7e90: /* original 6043, guest PC 0x0c0c7e90 */
if(!s->budget--) { s->failed_pc=0x0c0c7e90u; return 0; }
r[0]=r[4];
goto P_0c0c7e92;
P_0c0c7e92: /* original 81ef, guest PC 0x0c0c7e92 */
if(!s->budget--) { s->failed_pc=0x0c0c7e92u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0c7e94;
P_0c0c7e94: /* original d324, guest PC 0x0c0c7e94 */
if(!s->budget--) { s->failed_pc=0x0c0c7e94u; return 0; }
r[3]=read(ram,0x0c0c7f28u,4);
goto P_0c0c7e96;
P_0c0c7e96: /* original f5fc, guest PC 0x0c0c7e96 */
if(!s->budget--) { s->failed_pc=0x0c0c7e96u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c7e98;
P_0c0c7e98: /* original 430b, guest PC 0x0c0c7e98 */
if(!s->budget--) { s->failed_pc=0x0c0c7e98u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7e9cu;
fr[5]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7e9cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e9c;
P_0c0c7e9a: /* original f54d, guest PC 0x0c0c7e9a */
if(!s->budget--) { s->failed_pc=0x0c0c7e9au; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c7e9c;
P_0c0c7e9c: /* original e014, guest PC 0x0c0c7e9c */
if(!s->budget--) { s->failed_pc=0x0c0c7e9cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c7e9e;
P_0c0c7e9e: /* original f40c, guest PC 0x0c0c7e9e */
if(!s->budget--) { s->failed_pc=0x0c0c7e9eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c7ea0;
P_0c0c7ea0: /* original fe47, guest PC 0x0c0c7ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea2;
P_0c0c7ea2: /* original e30d, guest PC 0x0c0c7ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea2u; return 0; }
r[3]=0x0000000du;
goto P_0c0c7ea4;
P_0c0c7ea4: /* original 9030, guest PC 0x0c0c7ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f08u,2);
goto P_0c0c7ea6;
P_0c0c7ea6: /* original fe47, guest PC 0x0c0c7ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea8;
P_0c0c7ea8: /* original e060, guest PC 0x0c0c7ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea8u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7eaa;
P_0c0c7eaa: /* original 04ec, guest PC 0x0c0c7eaa */
if(!s->budget--) { s->failed_pc=0x0c0c7eaau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7eac;
P_0c0c7eac: /* original 644c, guest PC 0x0c0c7eac */
if(!s->budget--) { s->failed_pc=0x0c0c7eacu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7eae;
P_0c0c7eae: /* original 3433, guest PC 0x0c0c7eae */
if(!s->budget--) { s->failed_pc=0x0c0c7eaeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c7eb0;
P_0c0c7eb0: /* original 8f01, guest PC 0x0c0c7eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb0u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0c7eb6; }
goto P_0c0c7eb4;
P_0c0c7eb2: /* original e061, guest PC 0x0c0c7eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb2u; return 0; }
r[0]=0x00000061u;
goto P_0c0c7eb4;
P_0c0c7eb4: /* original 74f3, guest PC 0x0c0c7eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb4u; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0c7eb6;
P_0c0c7eb6: /* original 634b, guest PC 0x0c0c7eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb6u; return 0; }
r[3]=0u-r[4];
goto P_0c0c7eb8;
P_0c0c7eb8: /* original 0e44, guest PC 0x0c0c7eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7eba;
P_0c0c7eba: /* original d41c, guest PC 0x0c0c7eba */
if(!s->budget--) { s->failed_pc=0x0c0c7ebau; return 0; }
r[4]=read(ram,0x0c0c7f2cu,4);
goto P_0c0c7ebc;
P_0c0c7ebc: /* original 9025, guest PC 0x0c0c7ebc */
if(!s->budget--) { s->failed_pc=0x0c0c7ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0au,2);
goto P_0c0c7ebe;
P_0c0c7ebe: /* original 443d, guest PC 0x0c0c7ebe */
if(!s->budget--) { s->failed_pc=0x0c0c7ebeu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0c7ec0;
P_0c0c7ec0: /* original 0e46, guest PC 0x0c0c7ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ec2;
P_0c0c7ec2: /* original e400, guest PC 0x0c0c7ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec2u; return 0; }
r[4]=0x00000000u;
goto P_0c0c7ec4;
P_0c0c7ec4: /* original e022, guest PC 0x0c0c7ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c7ec6;
P_0c0c7ec6: /* original d31a, guest PC 0x0c0c7ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec6u; return 0; }
r[3]=read(ram,0x0c0c7f30u,4);
goto P_0c0c7ec8;
P_0c0c7ec8: /* original 1e33, guest PC 0x0c0c7ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec8u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0c7eca;
P_0c0c7eca: /* original 0e44, guest PC 0x0c0c7eca */
if(!s->budget--) { s->failed_pc=0x0c0c7ecau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ecc;
P_0c0c7ecc: /* original 901e, guest PC 0x0c0c7ecc */
if(!s->budget--) { s->failed_pc=0x0c0c7eccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0cu,2);
goto P_0c0c7ece;
P_0c0c7ece: /* original 0e46, guest PC 0x0c0c7ece */
if(!s->budget--) { s->failed_pc=0x0c0c7eceu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed0;
P_0c0c7ed0: /* original 700c, guest PC 0x0c0c7ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed0u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7ed2;
P_0c0c7ed2: /* original 0e46, guest PC 0x0c0c7ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed4;
P_0c0c7ed4: /* original 901b, guest PC 0x0c0c7ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0eu,2);
goto P_0c0c7ed6;
P_0c0c7ed6: /* original 0e46, guest PC 0x0c0c7ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed8;
P_0c0c7ed8: /* original 700c, guest PC 0x0c0c7ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed8u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7eda;
P_0c0c7eda: /* original 0e46, guest PC 0x0c0c7eda */
if(!s->budget--) { s->failed_pc=0x0c0c7edau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7edc;
P_0c0c7edc: /* original 9018, guest PC 0x0c0c7edc */
if(!s->budget--) { s->failed_pc=0x0c0c7edcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f10u,2);
goto P_0c0c7ede;
P_0c0c7ede: /* original 0e44, guest PC 0x0c0c7ede */
if(!s->budget--) { s->failed_pc=0x0c0c7edeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ee0;
P_0c0c7ee0: /* original e401, guest PC 0x0c0c7ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee0u; return 0; }
r[4]=0x00000001u;
goto P_0c0c7ee2;
P_0c0c7ee2: /* original 60e2, guest PC 0x0c0c7ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c7ee4;
P_0c0c7ee4: /* original d313, guest PC 0x0c0c7ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee4u; return 0; }
r[3]=read(ram,0x0c0c7f34u,4);
goto P_0c0c7ee6;
P_0c0c7ee6: /* original 2039, guest PC 0x0c0c7ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee6u; return 0; }
r[0]&=r[3];
goto P_0c0c7ee8;
P_0c0c7ee8: /* original 240b, guest PC 0x0c0c7ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee8u; return 0; }
r[4]|=r[0];
goto P_0c0c7eea;
P_0c0c7eea: /* original 2e42, guest PC 0x0c0c7eea */
if(!s->budget--) { s->failed_pc=0x0c0c7eeau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0c7eec;
P_0c0c7eec: /* original d212, guest PC 0x0c0c7eec */
if(!s->budget--) { s->failed_pc=0x0c0c7eecu; return 0; }
r[2]=read(ram,0x0c0c7f38u,4);
goto P_0c0c7eee;
P_0c0c7eee: /* original 420b, guest PC 0x0c0c7eee */
if(!s->budget--) { s->failed_pc=0x0c0c7eeeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7ef2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7ef2u) { target=s->pc; goto dispatch; }
goto P_0c0c7ef2;
P_0c0c7ef0: /* original 64e3, guest PC 0x0c0c7ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef0u; return 0; }
r[4]=r[14];
goto P_0c0c7ef2;
P_0c0c7ef2: /* original 62c2, guest PC 0x0c0c7ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef2u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0c7ef4;
P_0c0c7ef4: /* original d311, guest PC 0x0c0c7ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef4u; return 0; }
r[3]=read(ram,0x0c0c7f3cu,4);
goto P_0c0c7ef6;
P_0c0c7ef6: /* original 2238, guest PC 0x0c0c7ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c7ef8;
P_0c0c7ef8: /* original 8924, guest PC 0x0c0c7ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f44; }
goto P_0c0c7efa;
P_0c0c7efa: /* original d211, guest PC 0x0c0c7efa */
if(!s->budget--) { s->failed_pc=0x0c0c7efau; return 0; }
r[2]=read(ram,0x0c0c7f40u,4);
goto P_0c0c7efc;
P_0c0c7efc: /* original 420b, guest PC 0x0c0c7efc */
if(!s->budget--) { s->failed_pc=0x0c0c7efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f00u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7f00u) { target=s->pc; goto dispatch; }
goto P_0c0c7f00;
P_0c0c7efe: /* original 64e3, guest PC 0x0c0c7efe */
if(!s->budget--) { s->failed_pc=0x0c0c7efeu; return 0; }
r[4]=r[14];
goto P_0c0c7f00;
P_0c0c7f00: /* original a02a, guest PC 0x0c0c7f00 */
if(!s->budget--) { s->failed_pc=0x0c0c7f00u; return 0; }
goto P_0c0c7f58;
P_0c0c7f02: /* original 0009, guest PC 0x0c0c7f02 */
if(!s->budget--) { s->failed_pc=0x0c0c7f02u; return 0; }
return vf3_matrix_family(0x0c0c7f04u,s,ram);
P_0c0c7f44: /* original e060, guest PC 0x0c0c7f44 */
if(!s->budget--) { s->failed_pc=0x0c0c7f44u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f46;
P_0c0c7f46: /* original d247, guest PC 0x0c0c7f46 */
if(!s->budget--) { s->failed_pc=0x0c0c7f46u; return 0; }
r[2]=read(ram,0x0c0c8064u,4);
goto P_0c0c7f48;
P_0c0c7f48: /* original 05ec, guest PC 0x0c0c7f48 */
if(!s->budget--) { s->failed_pc=0x0c0c7f48u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f4a;
P_0c0c7f4a: /* original 84e4, guest PC 0x0c0c7f4a */
if(!s->budget--) { s->failed_pc=0x0c0c7f4au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c7f4c;
P_0c0c7f4c: /* original 655c, guest PC 0x0c0c7f4c */
if(!s->budget--) { s->failed_pc=0x0c0c7f4cu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c7f4e;
P_0c0c7f4e: /* original 420b, guest PC 0x0c0c7f4e */
if(!s->budget--) { s->failed_pc=0x0c0c7f4eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f52u;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7f52u) { target=s->pc; goto dispatch; }
goto P_0c0c7f52;
P_0c0c7f50: /* original 640c, guest PC 0x0c0c7f50 */
if(!s->budget--) { s->failed_pc=0x0c0c7f50u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c7f52;
P_0c0c7f52: /* original d345, guest PC 0x0c0c7f52 */
if(!s->budget--) { s->failed_pc=0x0c0c7f52u; return 0; }
r[3]=read(ram,0x0c0c8068u,4);
goto P_0c0c7f54;
P_0c0c7f54: /* original 430b, guest PC 0x0c0c7f54 */
if(!s->budget--) { s->failed_pc=0x0c0c7f54u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f58u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7f58u) { target=s->pc; goto dispatch; }
goto P_0c0c7f58;
P_0c0c7f56: /* original 64e3, guest PC 0x0c0c7f56 */
if(!s->budget--) { s->failed_pc=0x0c0c7f56u; return 0; }
r[4]=r[14];
goto P_0c0c7f58;
P_0c0c7f58: /* original e060, guest PC 0x0c0c7f58 */
if(!s->budget--) { s->failed_pc=0x0c0c7f58u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f5a;
P_0c0c7f5a: /* original 02ec, guest PC 0x0c0c7f5a */
if(!s->budget--) { s->failed_pc=0x0c0c7f5au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f5c;
P_0c0c7f5c: /* original 907e, guest PC 0x0c0c7f5c */
if(!s->budget--) { s->failed_pc=0x0c0c7f5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c805cu,2);
goto P_0c0c7f5e;
P_0c0c7f5e: /* original 0e24, guest PC 0x0c0c7f5e */
if(!s->budget--) { s->failed_pc=0x0c0c7f5eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c7f60;
P_0c0c7f60: /* original d342, guest PC 0x0c0c7f60 */
if(!s->budget--) { s->failed_pc=0x0c0c7f60u; return 0; }
r[3]=read(ram,0x0c0c806cu,4);
goto P_0c0c7f62;
P_0c0c7f62: /* original 61c2, guest PC 0x0c0c7f62 */
if(!s->budget--) { s->failed_pc=0x0c0c7f62u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0c7f64;
P_0c0c7f64: /* original 2138, guest PC 0x0c0c7f64 */
if(!s->budget--) { s->failed_pc=0x0c0c7f64u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7f66;
P_0c0c7f66: /* original 8904, guest PC 0x0c0c7f66 */
if(!s->budget--) { s->failed_pc=0x0c0c7f66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f72; }
goto P_0c0c7f68;
P_0c0c7f68: /* original d241, guest PC 0x0c0c7f68 */
if(!s->budget--) { s->failed_pc=0x0c0c7f68u; return 0; }
r[2]=read(ram,0x0c0c8070u,4);
goto P_0c0c7f6a;
P_0c0c7f6a: /* original 420b, guest PC 0x0c0c7f6a */
if(!s->budget--) { s->failed_pc=0x0c0c7f6au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f6eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7f6eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f6e;
P_0c0c7f6c: /* original 0009, guest PC 0x0c0c7f6c */
if(!s->budget--) { s->failed_pc=0x0c0c7f6cu; return 0; }
goto P_0c0c7f6e;
P_0c0c7f6e: /* original a006, guest PC 0x0c0c7f6e */
if(!s->budget--) { s->failed_pc=0x0c0c7f6eu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f70: /* original 0009, guest PC 0x0c0c7f70 */
if(!s->budget--) { s->failed_pc=0x0c0c7f70u; return 0; }
goto P_0c0c7f72;
P_0c0c7f72: /* original 60d3, guest PC 0x0c0c7f72 */
if(!s->budget--) { s->failed_pc=0x0c0c7f72u; return 0; }
r[0]=r[13];
goto P_0c0c7f74;
P_0c0c7f74: /* original 8801, guest PC 0x0c0c7f74 */
if(!s->budget--) { s->failed_pc=0x0c0c7f74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c7f76;
P_0c0c7f76: /* original 8b02, guest PC 0x0c0c7f76 */
if(!s->budget--) { s->failed_pc=0x0c0c7f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f7e; }
goto P_0c0c7f78;
P_0c0c7f78: /* original d13e, guest PC 0x0c0c7f78 */
if(!s->budget--) { s->failed_pc=0x0c0c7f78u; return 0; }
r[1]=read(ram,0x0c0c8074u,4);
goto P_0c0c7f7a;
P_0c0c7f7a: /* original 410b, guest PC 0x0c0c7f7a */
if(!s->budget--) { s->failed_pc=0x0c0c7f7au; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7f7eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7f7eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f7e;
P_0c0c7f7c: /* original 0009, guest PC 0x0c0c7f7c */
if(!s->budget--) { s->failed_pc=0x0c0c7f7cu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f7e: /* original d33e, guest PC 0x0c0c7f7e */
if(!s->budget--) { s->failed_pc=0x0c0c7f7eu; return 0; }
r[3]=read(ram,0x0c0c8078u,4);
goto P_0c0c7f80;
P_0c0c7f80: /* original 430b, guest PC 0x0c0c7f80 */
if(!s->budget--) { s->failed_pc=0x0c0c7f80u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f84u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7f84u) { target=s->pc; goto dispatch; }
goto P_0c0c7f84;
P_0c0c7f82: /* original 64e3, guest PC 0x0c0c7f82 */
if(!s->budget--) { s->failed_pc=0x0c0c7f82u; return 0; }
r[4]=r[14];
goto P_0c0c7f84;
P_0c0c7f84: /* original d23d, guest PC 0x0c0c7f84 */
if(!s->budget--) { s->failed_pc=0x0c0c7f84u; return 0; }
r[2]=read(ram,0x0c0c807cu,4);
goto P_0c0c7f86;
P_0c0c7f86: /* original 420b, guest PC 0x0c0c7f86 */
if(!s->budget--) { s->failed_pc=0x0c0c7f86u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f8au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7f8au) { target=s->pc; goto dispatch; }
goto P_0c0c7f8a;
P_0c0c7f88: /* original 0009, guest PC 0x0c0c7f88 */
if(!s->budget--) { s->failed_pc=0x0c0c7f88u; return 0; }
goto P_0c0c7f8a;
P_0c0c7f8a: /* original 2dd8, guest PC 0x0c0c7f8a */
if(!s->budget--) { s->failed_pc=0x0c0c7f8au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0c7f8c;
P_0c0c7f8c: /* original 8b06, guest PC 0x0c0c7f8c */
if(!s->budget--) { s->failed_pc=0x0c0c7f8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f9c; }
goto P_0c0c7f8e;
P_0c0c7f8e: /* original d33e, guest PC 0x0c0c7f8e */
if(!s->budget--) { s->failed_pc=0x0c0c7f8eu; return 0; }
r[3]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f90;
P_0c0c7f90: /* original d23c, guest PC 0x0c0c7f90 */
if(!s->budget--) { s->failed_pc=0x0c0c7f90u; return 0; }
r[2]=read(ram,0x0c0c8084u,4);
goto P_0c0c7f92;
P_0c0c7f92: /* original d53b, guest PC 0x0c0c7f92 */
if(!s->budget--) { s->failed_pc=0x0c0c7f92u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7f94;
P_0c0c7f94: /* original 430b, guest PC 0x0c0c7f94 */
if(!s->budget--) { s->failed_pc=0x0c0c7f94u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f98u;
tmp=read(ram,r[2],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7f98u) { target=s->pc; goto dispatch; }
goto P_0c0c7f98;
P_0c0c7f96: /* original 6422, guest PC 0x0c0c7f96 */
if(!s->budget--) { s->failed_pc=0x0c0c7f96u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c7f98;
P_0c0c7f98: /* original a005, guest PC 0x0c0c7f98 */
if(!s->budget--) { s->failed_pc=0x0c0c7f98u; return 0; }
goto P_0c0c7fa6;
P_0c0c7f9a: /* original 0009, guest PC 0x0c0c7f9a */
if(!s->budget--) { s->failed_pc=0x0c0c7f9au; return 0; }
goto P_0c0c7f9c;
P_0c0c7f9c: /* original d23a, guest PC 0x0c0c7f9c */
if(!s->budget--) { s->failed_pc=0x0c0c7f9cu; return 0; }
r[2]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f9e;
P_0c0c7f9e: /* original d33b, guest PC 0x0c0c7f9e */
if(!s->budget--) { s->failed_pc=0x0c0c7f9eu; return 0; }
r[3]=read(ram,0x0c0c808cu,4);
goto P_0c0c7fa0;
P_0c0c7fa0: /* original d537, guest PC 0x0c0c7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa0u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7fa2;
P_0c0c7fa2: /* original 420b, guest PC 0x0c0c7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7fa6u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7fa6u) { target=s->pc; goto dispatch; }
goto P_0c0c7fa6;
P_0c0c7fa4: /* original 6432, guest PC 0x0c0c7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c7fa6;
P_0c0c7fa6: /* original 7f14, guest PC 0x0c0c7fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa6u; return 0; }
r[15]+=0x00000014u;
goto P_0c0c7fa8;
P_0c0c7fa8: /* original 4f26, guest PC 0x0c0c7fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7faa;
P_0c0c7faa: /* original fff9, guest PC 0x0c0c7faa */
if(!s->budget--) { s->failed_pc=0x0c0c7faau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c7fac;
P_0c0c7fac: /* original 6bf6, guest PC 0x0c0c7fac */
if(!s->budget--) { s->failed_pc=0x0c0c7facu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7fae;
P_0c0c7fae: /* original 6cf6, guest PC 0x0c0c7fae */
if(!s->budget--) { s->failed_pc=0x0c0c7faeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7fb0;
P_0c0c7fb0: /* original 6df6, guest PC 0x0c0c7fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7fb2;
P_0c0c7fb2: /* original 000b, guest PC 0x0c0c7fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7fb4: /* original 6ef6, guest PC 0x0c0c7fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c7fb6u,s,ram);
P_0c0cc5e6: /* original 2fe6, guest PC 0x0c0cc5e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc5e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5e8;
P_0c0cc5e8: /* original 2fd6, guest PC 0x0c0cc5e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc5e8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5ea;
P_0c0cc5ea: /* original 2fc6, guest PC 0x0c0cc5ea */
if(!s->budget--) { s->failed_pc=0x0c0cc5eau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5ec;
P_0c0cc5ec: /* original 2fb6, guest PC 0x0c0cc5ec */
if(!s->budget--) { s->failed_pc=0x0c0cc5ecu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5ee;
P_0c0cc5ee: /* original 2fa6, guest PC 0x0c0cc5ee */
if(!s->budget--) { s->failed_pc=0x0c0cc5eeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5f0;
P_0c0cc5f0: /* original 2f96, guest PC 0x0c0cc5f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5f2;
P_0c0cc5f2: /* original d11f, guest PC 0x0c0cc5f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f2u; return 0; }
r[1]=read(ram,0x0c0cc670u,4);
goto P_0c0cc5f4;
P_0c0cc5f4: /* original 4f22, guest PC 0x0c0cc5f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc5f6;
P_0c0cc5f6: /* original 6212, guest PC 0x0c0cc5f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0cc5f8;
P_0c0cc5f8: /* original d31c, guest PC 0x0c0cc5f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f8u; return 0; }
r[3]=read(ram,0x0c0cc66cu,4);
goto P_0c0cc5fa;
P_0c0cc5fa: /* original 2238, guest PC 0x0c0cc5fa */
if(!s->budget--) { s->failed_pc=0x0c0cc5fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cc5fc;
P_0c0cc5fc: /* original 8f1f, guest PC 0x0c0cc5fc */
if(!s->budget--) { s->failed_pc=0x0c0cc5fcu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c0cc63e; }
goto P_0c0cc600;
P_0c0cc5fe: /* original 6e43, guest PC 0x0c0cc5fe */
if(!s->budget--) { s->failed_pc=0x0c0cc5feu; return 0; }
r[14]=r[4];
goto P_0c0cc600;
P_0c0cc600: /* original 902b, guest PC 0x0c0cc600 */
if(!s->budget--) { s->failed_pc=0x0c0cc600u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc65au,2);
goto P_0c0cc602;
P_0c0cc602: /* original ec00, guest PC 0x0c0cc602 */
if(!s->budget--) { s->failed_pc=0x0c0cc602u; return 0; }
r[12]=0x00000000u;
goto P_0c0cc604;
P_0c0cc604: /* original d91b, guest PC 0x0c0cc604 */
if(!s->budget--) { s->failed_pc=0x0c0cc604u; return 0; }
r[9]=read(ram,0x0c0cc674u,4);
goto P_0c0cc606;
P_0c0cc606: /* original dd1c, guest PC 0x0c0cc606 */
if(!s->budget--) { s->failed_pc=0x0c0cc606u; return 0; }
r[13]=read(ram,0x0c0cc678u,4);
goto P_0c0cc608;
P_0c0cc608: /* original 0bee, guest PC 0x0c0cc608 */
if(!s->budget--) { s->failed_pc=0x0c0cc608u; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c0cc60a;
P_0c0cc60a: /* original a006, guest PC 0x0c0cc60a */
if(!s->budget--) { s->failed_pc=0x0c0cc60au; return 0; }
r[10]=0x00000008u;
goto P_0c0cc61a;
P_0c0cc60c: /* original ea08, guest PC 0x0c0cc60c */
if(!s->budget--) { s->failed_pc=0x0c0cc60cu; return 0; }
r[10]=0x00000008u;
goto P_0c0cc60e;
P_0c0cc60e: /* original 65d5, guest PC 0x0c0cc60e */
if(!s->budget--) { s->failed_pc=0x0c0cc60eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[5]=tmp;
goto P_0c0cc610;
P_0c0cc610: /* original 35ec, guest PC 0x0c0cc610 */
if(!s->budget--) { s->failed_pc=0x0c0cc610u; return 0; }
r[5]+=r[14];
goto P_0c0cc612;
P_0c0cc612: /* original 490b, guest PC 0x0c0cc612 */
if(!s->budget--) { s->failed_pc=0x0c0cc612u; return 0; }
target=r[9];
r[16]=code_base|0x0c0cc616u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc616u) { target=s->pc; goto dispatch; }
goto P_0c0cc616;
P_0c0cc614: /* original 64b3, guest PC 0x0c0cc614 */
if(!s->budget--) { s->failed_pc=0x0c0cc614u; return 0; }
r[4]=r[11];
goto P_0c0cc616;
P_0c0cc616: /* original 7c01, guest PC 0x0c0cc616 */
if(!s->budget--) { s->failed_pc=0x0c0cc616u; return 0; }
r[12]+=0x00000001u;
goto P_0c0cc618;
P_0c0cc618: /* original 7b40, guest PC 0x0c0cc618 */
if(!s->budget--) { s->failed_pc=0x0c0cc618u; return 0; }
r[11]+=0x00000040u;
goto P_0c0cc61a;
P_0c0cc61a: /* original 3ca3, guest PC 0x0c0cc61a */
if(!s->budget--) { s->failed_pc=0x0c0cc61au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[10])!=0);
goto P_0c0cc61c;
P_0c0cc61c: /* original 8bf7, guest PC 0x0c0cc61c */
if(!s->budget--) { s->failed_pc=0x0c0cc61cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc60e; }
goto P_0c0cc61e;
P_0c0cc61e: /* original 9016, guest PC 0x0c0cc61e */
if(!s->budget--) { s->failed_pc=0x0c0cc61eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc64eu,2);
goto P_0c0cc620;
P_0c0cc620: /* original 04ee, guest PC 0x0c0cc620 */
if(!s->budget--) { s->failed_pc=0x0c0cc620u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0cc622;
P_0c0cc622: /* original 7004, guest PC 0x0c0cc622 */
if(!s->budget--) { s->failed_pc=0x0c0cc622u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc624;
P_0c0cc624: /* original 07ee, guest PC 0x0c0cc624 */
if(!s->budget--) { s->failed_pc=0x0c0cc624u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0cc626;
P_0c0cc626: /* original 7004, guest PC 0x0c0cc626 */
if(!s->budget--) { s->failed_pc=0x0c0cc626u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc628;
P_0c0cc628: /* original 05ee, guest PC 0x0c0cc628 */
if(!s->budget--) { s->failed_pc=0x0c0cc628u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0cc62a;
P_0c0cc62a: /* original 7004, guest PC 0x0c0cc62a */
if(!s->budget--) { s->failed_pc=0x0c0cc62au; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc62c;
P_0c0cc62c: /* original 06ee, guest PC 0x0c0cc62c */
if(!s->budget--) { s->failed_pc=0x0c0cc62cu; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0cc62e;
P_0c0cc62e: /* original 70f8, guest PC 0x0c0cc62e */
if(!s->budget--) { s->failed_pc=0x0c0cc62eu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cc630;
P_0c0cc630: /* original 0e46, guest PC 0x0c0cc630 */
if(!s->budget--) { s->failed_pc=0x0c0cc630u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0cc632;
P_0c0cc632: /* original 7004, guest PC 0x0c0cc632 */
if(!s->budget--) { s->failed_pc=0x0c0cc632u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc634;
P_0c0cc634: /* original 0e76, guest PC 0x0c0cc634 */
if(!s->budget--) { s->failed_pc=0x0c0cc634u; return 0; }
write(ram,r[14]+r[0],r[7],4);
goto P_0c0cc636;
P_0c0cc636: /* original 7004, guest PC 0x0c0cc636 */
if(!s->budget--) { s->failed_pc=0x0c0cc636u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc638;
P_0c0cc638: /* original 0e56, guest PC 0x0c0cc638 */
if(!s->budget--) { s->failed_pc=0x0c0cc638u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0cc63a;
P_0c0cc63a: /* original 70f4, guest PC 0x0c0cc63a */
if(!s->budget--) { s->failed_pc=0x0c0cc63au; return 0; }
r[0]+=0xfffffff4u;
goto P_0c0cc63c;
P_0c0cc63c: /* original 0e66, guest PC 0x0c0cc63c */
if(!s->budget--) { s->failed_pc=0x0c0cc63cu; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c0cc63e;
P_0c0cc63e: /* original 4f26, guest PC 0x0c0cc63e */
if(!s->budget--) { s->failed_pc=0x0c0cc63eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc640;
P_0c0cc640: /* original 69f6, guest PC 0x0c0cc640 */
if(!s->budget--) { s->failed_pc=0x0c0cc640u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cc642;
P_0c0cc642: /* original 6af6, guest PC 0x0c0cc642 */
if(!s->budget--) { s->failed_pc=0x0c0cc642u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc644;
P_0c0cc644: /* original 6bf6, guest PC 0x0c0cc644 */
if(!s->budget--) { s->failed_pc=0x0c0cc644u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc646;
P_0c0cc646: /* original 6cf6, guest PC 0x0c0cc646 */
if(!s->budget--) { s->failed_pc=0x0c0cc646u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc648;
P_0c0cc648: /* original 6df6, guest PC 0x0c0cc648 */
if(!s->budget--) { s->failed_pc=0x0c0cc648u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc64a;
P_0c0cc64a: /* original 000b, guest PC 0x0c0cc64a */
if(!s->budget--) { s->failed_pc=0x0c0cc64au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc64c: /* original 6ef6, guest PC 0x0c0cc64c */
if(!s->budget--) { s->failed_pc=0x0c0cc64cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cc64eu,s,ram);
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
0x0c03767cu,0x0c03767eu,0x0c037680u,0x0c037682u,0x0c037684u,0x0c037686u,0x0c037688u,0x0c0376a0u,0x0c0376a2u,0x0c0376a4u,0x0c0376a6u,0x0c0376a8u,0x0c0376aau,0x0c0376acu,0x0c0376aeu,0x0c0376b0u,
0x0c0376b2u,0x0c0376b4u,0x0c0376b6u,0x0c0376b8u,0x0c0376bau,0x0c0376bcu,0x0c0376beu,0x0c0376c0u,0x0c0376c2u,0x0c0376c4u,0x0c0376c6u,0x0c0376c8u,0x0c0376cau,0x0c0376ccu,0x0c0376ceu,0x0c0376d0u,
0x0c0376d2u,0x0c0376d4u,0x0c0376d6u,0x0c0376d8u,0x0c0376dau,0x0c0376dcu,0x0c0376deu,0x0c04ceceu,0x0c04ced0u,0x0c04ced2u,0x0c04ced4u,0x0c04ced6u,0x0c04ced8u,0x0c04cedau,0x0c04cedcu,0x0c04cedeu,
0x0c04cee0u,0x0c04cee2u,0x0c04cee4u,0x0c04cee6u,0x0c04cee8u,0x0c04ceeau,0x0c04ceecu,0x0c04ceeeu,0x0c04cef0u,0x0c04cef2u,0x0c04cef4u,0x0c04cef6u,0x0c04cef8u,0x0c04cefau,0x0c04cefcu,0x0c04cefeu,
0x0c04cf00u,0x0c04cf02u,0x0c04cf04u,0x0c04cf06u,0x0c04cf08u,0x0c04cf0au,0x0c04cf0cu,0x0c04d448u,0x0c04d44au,0x0c04d44cu,0x0c04d44eu,0x0c04d450u,0x0c04d452u,0x0c04d454u,0x0c04d456u,0x0c04d458u,
0x0c04d45au,0x0c04d45cu,0x0c04d45eu,0x0c04d460u,0x0c04d462u,0x0c04d464u,0x0c04d466u,0x0c04d468u,0x0c04d46au,0x0c04d46cu,0x0c04d46eu,0x0c04d470u,0x0c04d472u,0x0c04d474u,0x0c04d476u,0x0c04d478u,
0x0c04d47au,0x0c04d47cu,0x0c04d47eu,0x0c04d480u,0x0c04d482u,0x0c04d484u,0x0c04d486u,0x0c04d488u,0x0c04d48au,0x0c04d48cu,0x0c04d48eu,0x0c04d490u,0x0c04d492u,0x0c04d494u,0x0c04d496u,0x0c04d498u,
0x0c04d49au,0x0c04d49cu,0x0c04d49eu,0x0c04d4a0u,0x0c04d4a2u,0x0c04d4a4u,0x0c04d4a6u,0x0c04d4a8u,0x0c04d4aau,0x0c04d4acu,0x0c04d4aeu,0x0c04d4b0u,0x0c04d4b2u,0x0c04dda8u,0x0c04ddaau,0x0c04ddacu,
0x0c04ddaeu,0x0c04ddb0u,0x0c04ddb2u,0x0c04ddb4u,0x0c04ddb6u,0x0c04ddb8u,0x0c04ddbau,0x0c04ddbcu,0x0c04ddbeu,0x0c04ddc0u,0x0c04ddc2u,0x0c04ddc4u,0x0c04ddc6u,0x0c04ddc8u,0x0c04ddcau,0x0c04ddccu,
0x0c04ddceu,0x0c04ddd0u,0x0c04ddd2u,0x0c04ddd4u,0x0c04ddd6u,0x0c04ddd8u,0x0c04dddau,0x0c04dddcu,0x0c04dddeu,0x0c04dde0u,0x0c04dde2u,0x0c04dde4u,0x0c04dde6u,0x0c04dde8u,0x0c04ddeau,0x0c04ddecu,
0x0c04ddeeu,0x0c04ddf0u,0x0c04ddf2u,0x0c04ddf4u,0x0c04ddf6u,0x0c04ddf8u,0x0c04ddfau,0x0c04ddfcu,0x0c04ddfeu,0x0c04de00u,0x0c04de02u,0x0c04de04u,0x0c04de06u,0x0c04de08u,0x0c04de0au,0x0c04de0cu,
0x0c04de0eu,0x0c04de10u,0x0c04de12u,0x0c04de14u,0x0c04de16u,0x0c04de18u,0x0c04de1au,0x0c04de1cu,0x0c04de1eu,0x0c04de20u,0x0c04de22u,0x0c04de24u,0x0c04de26u,0x0c04de28u,0x0c04de2au,0x0c04de2cu,
0x0c04de2eu,0x0c04de30u,0x0c04de32u,0x0c04de34u,0x0c04de36u,0x0c04de38u,0x0c04de3au,0x0c04de3cu,0x0c04de3eu,0x0c04de40u,0x0c04de42u,0x0c04de44u,0x0c04de46u,0x0c04de48u,0x0c04de4au,0x0c04de4cu,
0x0c04de4eu,0x0c04de50u,0x0c04de52u,0x0c04de54u,0x0c04de56u,0x0c04de58u,0x0c04de5au,0x0c04de5cu,0x0c04de5eu,0x0c04de60u,0x0c04de62u,0x0c04de64u,0x0c04de66u,0x0c04de68u,0x0c04de6au,0x0c04de6cu,
0x0c04de6eu,0x0c04de70u,0x0c04de72u,0x0c04de74u,0x0c04de76u,0x0c04de78u,0x0c04de7au,0x0c04de7cu,0x0c04de7eu,0x0c04de80u,0x0c04de82u,0x0c04de84u,0x0c04de86u,0x0c04de88u,0x0c04de8au,0x0c04de8cu,
0x0c04de8eu,0x0c04de90u,0x0c04de92u,0x0c04de94u,0x0c04de96u,0x0c04de98u,0x0c04de9au,0x0c04de9cu,0x0c04de9eu,0x0c04dea0u,0x0c04dea2u,0x0c04dea4u,0x0c04dea6u,0x0c04dea8u,0x0c04deaau,0x0c04deacu,
0x0c04deaeu,0x0c04deb0u,0x0c04deb2u,0x0c04deb4u,0x0c04dee4u,0x0c04dee6u,0x0c04dee8u,0x0c04deeau,0x0c04deecu,0x0c04deeeu,0x0c04def0u,0x0c04def2u,0x0c04def4u,0x0c04def6u,0x0c04def8u,0x0c04defau,
0x0c04defcu,0x0c04defeu,0x0c04df00u,0x0c04df02u,0x0c04df04u,0x0c04df06u,0x0c04df08u,0x0c04df0au,0x0c04df0cu,0x0c04df0eu,0x0c04df10u,0x0c04df12u,0x0c04df14u,0x0c04df16u,0x0c04df18u,0x0c04df1au,
0x0c04df1cu,0x0c04df1eu,0x0c04df20u,0x0c04df22u,0x0c04df24u,0x0c04df26u,0x0c04df28u,0x0c04df2au,0x0c04df2cu,0x0c04df2eu,0x0c04df30u,0x0c04df32u,0x0c04df34u,0x0c04df36u,0x0c04df38u,0x0c04df3au,
0x0c04df3cu,0x0c04df3eu,0x0c04df40u,0x0c04df42u,0x0c04df44u,0x0c04df46u,0x0c04df48u,0x0c04df4au,0x0c04df4cu,0x0c04df4eu,0x0c04df50u,0x0c04df52u,0x0c04df54u,0x0c04df56u,0x0c04df58u,0x0c04ea52u,
0x0c04ea54u,0x0c04ea56u,0x0c04ea58u,0x0c04ea5au,0x0c04ea5cu,0x0c04ea5eu,0x0c04ea60u,0x0c04ea62u,0x0c04ea64u,0x0c04ea66u,0x0c04ea68u,0x0c04ea6au,0x0c04ea6cu,0x0c04ea6eu,0x0c04ea70u,0x0c04ea72u,
0x0c04ea74u,0x0c04ea76u,0x0c04ea78u,0x0c04ea7au,0x0c04ea7cu,0x0c04ea7eu,0x0c04ea80u,0x0c04ea82u,0x0c04ea84u,0x0c04ea86u,0x0c04ea88u,0x0c04ea8au,0x0c04ea8cu,0x0c04ea8eu,0x0c04ea90u,0x0c04ea92u,
0x0c04ea94u,0x0c04ea96u,0x0c04ea98u,0x0c04ea9au,0x0c04ea9cu,0x0c04ea9eu,0x0c04eaa0u,0x0c04eaa2u,0x0c04eaa4u,0x0c04eaa6u,0x0c04eaccu,0x0c04eaceu,0x0c04ead0u,0x0c04ead2u,0x0c04ead4u,0x0c04ead6u,
0x0c04ead8u,0x0c04eadau,0x0c04eadcu,0x0c04eadeu,0x0c04eae0u,0x0c04eae2u,0x0c04eae4u,0x0c04eae6u,0x0c04eae8u,0x0c04eaeau,0x0c04eaecu,0x0c04eaeeu,0x0c04eaf0u,0x0c04eaf2u,0x0c04eaf4u,0x0c04eaf6u,
0x0c04eaf8u,0x0c04eafau,0x0c04eafcu,0x0c04eafeu,0x0c04eb00u,0x0c04eb02u,0x0c04eb04u,0x0c04eb06u,0x0c04eb08u,0x0c04eb0au,0x0c04eb0cu,0x0c04eb0eu,0x0c04eb10u,0x0c04eb12u,0x0c04eb14u,0x0c04eb16u,
0x0c04eb18u,0x0c04eb1au,0x0c04eb1cu,0x0c04eb1eu,0x0c04eb20u,0x0c04eb22u,0x0c04eb24u,0x0c04eb26u,0x0c04eb28u,0x0c04eb2au,0x0c04eb2cu,0x0c04eb2eu,0x0c04eb30u,0x0c04eb32u,0x0c04eb34u,0x0c04eb36u,
0x0c04eb38u,0x0c04eb3au,0x0c04eb3cu,0x0c04eb3eu,0x0c04eb40u,0x0c04eb42u,0x0c04eb44u,0x0c04eb46u,0x0c04eb48u,0x0c04eb4au,0x0c04eb4cu,0x0c04eb4eu,0x0c04eb50u,0x0c04eb52u,0x0c04eb54u,0x0c04eb56u,
0x0c04eb58u,0x0c04eb5au,0x0c04eb5cu,0x0c04eb5eu,0x0c04eb60u,0x0c04eb62u,0x0c04eb64u,0x0c04eb66u,0x0c04eb68u,0x0c04eb6au,0x0c04eb6cu,0x0c04eb6eu,0x0c04ed8cu,0x0c04ed8eu,0x0c04ed90u,0x0c04ed92u,
0x0c04ed94u,0x0c04ed96u,0x0c04ed98u,0x0c04ed9au,0x0c04ed9cu,0x0c04ed9eu,0x0c04eda0u,0x0c04eda2u,0x0c04eda4u,0x0c04eda6u,0x0c04eda8u,0x0c04edaau,0x0c04edacu,0x0c04edaeu,0x0c04edb0u,0x0c04edb2u,
0x0c04edb4u,0x0c04edb6u,0x0c04edb8u,0x0c04edbau,0x0c04edbcu,0x0c04edbeu,0x0c04edc0u,0x0c04edc2u,0x0c04edc4u,0x0c04edc6u,0x0c04edc8u,0x0c04edcau,0x0c04edccu,0x0c04edceu,0x0c04edd0u,0x0c04edd2u,
0x0c04edd4u,0x0c04edd6u,0x0c04edd8u,0x0c04eddau,0x0c04eddcu,0x0c04eddeu,0x0c04ede0u,0x0c04ede2u,0x0c04ede4u,0x0c04ede6u,0x0c04ede8u,0x0c04edeau,0x0c04edecu,0x0c04edeeu,0x0c04edf0u,0x0c04ee2cu,
0x0c04ee2eu,0x0c04ee30u,0x0c04ee32u,0x0c04ee34u,0x0c04ee36u,0x0c04ee38u,0x0c04ee3au,0x0c04ee3cu,0x0c04ee3eu,0x0c04ee40u,0x0c04ee42u,0x0c04ee44u,0x0c04ee46u,0x0c04ee48u,0x0c04ee4au,0x0c04ee4cu,
0x0c04ee4eu,0x0c04ee50u,0x0c04ee52u,0x0c04ee54u,0x0c04ee56u,0x0c04ee58u,0x0c04ee5au,0x0c04ee5cu,0x0c04ee5eu,0x0c04ee60u,0x0c04ee62u,0x0c04ee64u,0x0c04ee66u,0x0c04ee68u,0x0c04ee6au,0x0c04ee6cu,
0x0c04ee6eu,0x0c04ee70u,0x0c04ee72u,0x0c04ee74u,0x0c04ee76u,0x0c04ee78u,0x0c04ee7au,0x0c04ee7cu,0x0c04ee7eu,0x0c04ee80u,0x0c04ee82u,0x0c04ee84u,0x0c04ee86u,0x0c04ee88u,0x0c04ee8au,0x0c04ee8cu,
0x0c04ee8eu,0x0c04ee90u,0x0c04ee92u,0x0c04ee94u,0x0c04ee96u,0x0c04ee98u,0x0c04ee9au,0x0c04ee9cu,0x0c04ee9eu,0x0c04eea0u,0x0c04eea2u,0x0c04eea4u,0x0c04eea6u,0x0c04eea8u,0x0c04eeaau,0x0c04eeacu,
0x0c04eeaeu,0x0c04eeb0u,0x0c04eeb2u,0x0c04eeb4u,0x0c04eeb6u,0x0c04eeb8u,0x0c04eebau,0x0c04eebcu,0x0c04f632u,0x0c04f634u,0x0c04f636u,0x0c04f638u,0x0c04f63au,0x0c04f63cu,0x0c04f63eu,0x0c04f640u,
0x0c04f642u,0x0c04f644u,0x0c04f646u,0x0c04f648u,0x0c04f64au,0x0c04f64cu,0x0c04f64eu,0x0c04f650u,0x0c04f652u,0x0c04f654u,0x0c04f656u,0x0c04f658u,0x0c04f65au,0x0c04f65cu,0x0c04f65eu,0x0c04f660u,
0x0c04f662u,0x0c04f664u,0x0c04f666u,0x0c04f668u,0x0c04f66au,0x0c04f66cu,0x0c04f66eu,0x0c04f670u,0x0c04f672u,0x0c04f674u,0x0c04f676u,0x0c04f678u,0x0c04f67au,0x0c04f67cu,0x0c04f67eu,0x0c04f680u,
0x0c04f682u,0x0c04f684u,0x0c04f686u,0x0c04f688u,0x0c04f68au,0x0c04f68cu,0x0c04f68eu,0x0c04f690u,0x0c04f692u,0x0c04f694u,0x0c04f696u,0x0c04f698u,0x0c04f69au,0x0c04f69cu,0x0c04f69eu,0x0c04f6a0u,
0x0c04f6a2u,0x0c04f6a4u,0x0c04f6a6u,0x0c04f6a8u,0x0c04f6aau,0x0c04f6acu,0x0c04f6aeu,0x0c04f6b0u,0x0c04f6b2u,0x0c04f6b4u,0x0c04f6b6u,0x0c04f6b8u,0x0c04f6bau,0x0c04f6bcu,0x0c04f6beu,0x0c04f6c0u,
0x0c04f6c2u,0x0c04f6c4u,0x0c04f6e0u,0x0c04f6e2u,0x0c04f6e4u,0x0c04f6e6u,0x0c04f6e8u,0x0c04f6eau,0x0c04f6ecu,0x0c04f6eeu,0x0c04f6f0u,0x0c04f6f2u,0x0c04f6f4u,0x0c04f6f6u,0x0c04f6f8u,0x0c04f6fau,
0x0c04f6fcu,0x0c04f6feu,0x0c04f700u,0x0c04f702u,0x0c04f704u,0x0c04f706u,0x0c04f708u,0x0c04f70au,0x0c04f70cu,0x0c04f70eu,0x0c04f710u,0x0c04f712u,0x0c04f714u,0x0c04f716u,0x0c04f718u,0x0c04f71au,
0x0c04f71cu,0x0c04f71eu,0x0c04f720u,0x0c04f722u,0x0c04f724u,0x0c04f726u,0x0c04f728u,0x0c04f72au,0x0c04f72cu,0x0c04f72eu,0x0c04f730u,0x0c04f732u,0x0c04f734u,0x0c04f736u,0x0c04f738u,0x0c04f73au,
0x0c04f73cu,0x0c04f73eu,0x0c04f740u,0x0c04f742u,0x0c04f744u,0x0c04f746u,0x0c04f748u,0x0c04f74au,0x0c04f74cu,0x0c04f74eu,0x0c04f750u,0x0c04f752u,0x0c04f754u,0x0c04f756u,0x0c04f758u,0x0c04f75au,
0x0c04f75cu,0x0c04f75eu,0x0c04f760u,0x0c04f762u,0x0c04f764u,0x0c04f766u,0x0c04f768u,0x0c04f76au,0x0c04f76cu,0x0c04f76eu,0x0c04f770u,0x0c04f772u,0x0c04f774u,0x0c04f776u,0x0c04f778u,0x0c04f77au,
0x0c04f77cu,0x0c04f77eu,0x0c04f780u,0x0c04f782u,0x0c04f784u,0x0c04f786u,0x0c04f788u,0x0c04f78au,0x0c04f78cu,0x0c04f78eu,0x0c04f790u,0x0c04f792u,0x0c04f794u,0x0c04f796u,0x0c04f798u,0x0c04f79au,
0x0c04f79cu,0x0c04f79eu,0x0c04f7a0u,0x0c04f7a2u,0x0c04f7a4u,0x0c04f7a6u,0x0c04f7a8u,0x0c04f7aau,0x0c04f7acu,0x0c04f7aeu,0x0c04f7b0u,0x0c04f7b2u,0x0c04f7b4u,0x0c04f7b6u,0x0c04f7b8u,0x0c04f7bau,
0x0c04f7bcu,0x0c04f7beu,0x0c04f7c0u,0x0c04f7c2u,0x0c04f7c4u,0x0c04f7c6u,0x0c04f7c8u,0x0c04f7cau,0x0c04f7ccu,0x0c04f7e8u,0x0c04f7eau,0x0c04f7ecu,0x0c04f7eeu,0x0c04f7f0u,0x0c04f7f2u,0x0c04f7f4u,
0x0c04f7f6u,0x0c04f7f8u,0x0c04f7fau,0x0c04f7fcu,0x0c04f7feu,0x0c04f800u,0x0c04f802u,0x0c04f804u,0x0c04f806u,0x0c04f808u,0x0c04f80au,0x0c04f80cu,0x0c04f80eu,0x0c04f810u,0x0c04f812u,0x0c04f814u,
0x0c04f816u,0x0c04f818u,0x0c04f81au,0x0c04f81cu,0x0c04f81eu,0x0c04f820u,0x0c04f822u,0x0c04f824u,0x0c04f826u,0x0c04f828u,0x0c04f82au,0x0c04f82cu,0x0c04f82eu,0x0c04f830u,0x0c04f832u,0x0c04f834u,
0x0c04f836u,0x0c04f838u,0x0c04f83au,0x0c04f83cu,0x0c04f83eu,0x0c04f840u,0x0c04f842u,0x0c04f844u,0x0c04f846u,0x0c04f848u,0x0c04f84au,0x0c04f84cu,0x0c04f84eu,0x0c04f850u,0x0c04f852u,0x0c04f854u,
0x0c04f856u,0x0c04f858u,0x0c04f85au,0x0c04f85cu,0x0c04f85eu,0x0c04f860u,0x0c04f862u,0x0c04f864u,0x0c04f866u,0x0c04f868u,0x0c04f86au,0x0c04f86cu,0x0c04f86eu,0x0c04f870u,0x0c04f872u,0x0c04f874u,
0x0c04f876u,0x0c04f878u,0x0c04f87au,0x0c04f87cu,0x0c04f87eu,0x0c04f880u,0x0c04f882u,0x0c04f884u,0x0c04f886u,0x0c04f888u,0x0c04f88au,0x0c04f98eu,0x0c04f990u,0x0c04f992u,0x0c04f994u,0x0c04f996u,
0x0c04f998u,0x0c04f99au,0x0c04f99cu,0x0c04f99eu,0x0c04f9a0u,0x0c04f9a2u,0x0c04f9a4u,0x0c04f9a6u,0x0c04f9a8u,0x0c04f9aau,0x0c04f9acu,0x0c04f9aeu,0x0c04f9b0u,0x0c04f9b2u,0x0c04f9b4u,0x0c04f9b6u,
0x0c04f9b8u,0x0c04f9bau,0x0c04f9bcu,0x0c04f9beu,0x0c04f9c0u,0x0c04f9c2u,0x0c04f9c4u,0x0c04f9c6u,0x0c04f9c8u,0x0c04f9cau,0x0c04f9ccu,0x0c04f9ceu,0x0c04f9d0u,0x0c04f9d2u,0x0c04f9d4u,0x0c04f9d6u,
0x0c04f9f0u,0x0c04f9f2u,0x0c04f9f4u,0x0c04f9f6u,0x0c04f9f8u,0x0c04f9fau,0x0c04f9fcu,0x0c04f9feu,0x0c04fa00u,0x0c04fa02u,0x0c04fa04u,0x0c04fa06u,0x0c04fa08u,0x0c04fa0au,0x0c04fa0cu,0x0c04fa0eu,
0x0c04fa10u,0x0c04fa12u,0x0c04fa14u,0x0c04fa16u,0x0c04fa18u,0x0c04fa1au,0x0c04fa1cu,0x0c04fa1eu,0x0c04fa20u,0x0c04fa22u,0x0c04fa24u,0x0c04fa26u,0x0c04fa28u,0x0c04fa2au,0x0c04fa2cu,0x0c04fa2eu,
0x0c04fa30u,0x0c04fa32u,0x0c04fa34u,0x0c04fa36u,0x0c04fafcu,0x0c04fafeu,0x0c04fb00u,0x0c04fb02u,0x0c04fb04u,0x0c04fb06u,0x0c04fb08u,0x0c04fb0au,0x0c04fb0cu,0x0c04fb0eu,0x0c04fb10u,0x0c04fb12u,
0x0c04fb14u,0x0c04fb16u,0x0c04fb18u,0x0c04fb1au,0x0c04fb1cu,0x0c04fb1eu,0x0c04fb20u,0x0c04fb22u,0x0c04fb24u,0x0c04fb26u,0x0c04fb28u,0x0c04fb2au,0x0c04fb2cu,0x0c04fb2eu,0x0c04fd30u,0x0c04fd32u,
0x0c04fd34u,0x0c04fd36u,0x0c04fd38u,0x0c04fd3au,0x0c04fd3cu,0x0c04fd3eu,0x0c04fd40u,0x0c04fd42u,0x0c04fd44u,0x0c04fd46u,0x0c04fd48u,0x0c04fd4au,0x0c04fd4cu,0x0c04fd4eu,0x0c04fd50u,0x0c04fd52u,
0x0c04fd54u,0x0c04fd56u,0x0c04fd58u,0x0c04fd5au,0x0c04fd5cu,0x0c04fd5eu,0x0c04fd60u,0x0c04fd62u,0x0c04fd64u,0x0c04fd66u,0x0c04fd68u,0x0c04fd6au,0x0c04fd6cu,0x0c04fd6eu,0x0c04fd70u,0x0c04fd72u,
0x0c04fd74u,0x0c04fd76u,0x0c04fd78u,0x0c04fd7au,0x0c04fd7cu,0x0c04fd7eu,0x0c04fd80u,0x0c04fd82u,0x0c04fd84u,0x0c04fd86u,0x0c04fd88u,0x0c04fd8au,0x0c04fd8cu,0x0c04fd8eu,0x0c04fd90u,0x0c04fd92u,
0x0c04fd94u,0x0c04fd96u,0x0c04fd98u,0x0c04fd9au,0x0c04fd9cu,0x0c04fd9eu,0x0c04fda0u,0x0c04fda2u,0x0c04fda4u,0x0c04fda6u,0x0c04fda8u,0x0c04fdaau,0x0c04fdacu,0x0c04fdaeu,0x0c04fdb0u,0x0c04fdb2u,
0x0c04fdb4u,0x0c04fdb6u,0x0c04fdb8u,0x0c04fdbau,0x0c04fdbcu,0x0c04fdbeu,0x0c04fdc0u,0x0c04fdc2u,0x0c04fdc4u,0x0c04fdc6u,0x0c04fdc8u,0x0c04fdcau,0x0c04fdccu,0x0c04fdceu,0x0c04fdd0u,0x0c04fdd2u,
0x0c04fdd4u,0x0c04fe40u,0x0c04fe42u,0x0c04fe44u,0x0c04fe46u,0x0c04fe48u,0x0c04fe4au,0x0c04fe4cu,0x0c04fe4eu,0x0c04fe50u,0x0c04fe52u,0x0c04fe54u,0x0c04fe56u,0x0c04fe58u,0x0c04fe5au,0x0c04fe5cu,
0x0c04fe5eu,0x0c04fe60u,0x0c04fe62u,0x0c04fe64u,0x0c04fe66u,0x0c04fe68u,0x0c04fe6au,0x0c04fe6cu,0x0c04fe6eu,0x0c04fe70u,0x0c04fe72u,0x0c04fe74u,0x0c04fe76u,0x0c04fe78u,0x0c04fe7au,0x0c04fe7cu,
0x0c04fe7eu,0x0c04fe80u,0x0c04fe82u,0x0c04fe84u,0x0c04fe86u,0x0c04fe88u,0x0c04fe8au,0x0c04fe8cu,0x0c04fe8eu,0x0c04fe90u,0x0c04fe92u,0x0c04fe94u,0x0c04fe96u,0x0c04fe98u,0x0c04fe9au,0x0c04fe9cu,
0x0c04fe9eu,0x0c04fea0u,0x0c04fea2u,0x0c04fea4u,0x0c04fea6u,0x0c04fea8u,0x0c04feaau,0x0c04feacu,0x0c04feaeu,0x0c04feb0u,0x0c04feb2u,0x0c04feb4u,0x0c04feb6u,0x0c04feb8u,0x0c04febau,0x0c04febcu,
0x0c04febeu,0x0c04fec0u,0x0c04fec2u,0x0c04ff80u,0x0c04ff82u,0x0c04ff84u,0x0c04ff86u,0x0c04ff88u,0x0c04ff8au,0x0c04ff8cu,0x0c04ff8eu,0x0c04ff90u,0x0c04ff92u,0x0c04ff94u,0x0c04ff96u,0x0c04ff98u,
0x0c04ff9au,0x0c04ff9cu,0x0c04ff9eu,0x0c053ca4u,0x0c053ca6u,0x0c053ca8u,0x0c053caau,0x0c053cacu,0x0c053caeu,0x0c053cb0u,0x0c053cb2u,0x0c053cb4u,0x0c053cb6u,0x0c053cb8u,0x0c053cbau,0x0c053cbcu,
0x0c053cbeu,0x0c053cc0u,0x0c053cc2u,0x0c053cc4u,0x0c053cc6u,0x0c053cc8u,0x0c053ccau,0x0c053cccu,0x0c053cceu,0x0c053cd0u,0x0c053cd2u,0x0c053cd4u,0x0c053cd6u,0x0c053cd8u,0x0c053cdau,0x0c053cdcu,
0x0c053cdeu,0x0c053ce0u,0x0c053ce2u,0x0c068c58u,0x0c068c5au,0x0c068c5cu,0x0c068c5eu,0x0c068c60u,0x0c068c62u,0x0c068c64u,0x0c068c66u,0x0c068c68u,0x0c068c6au,0x0c068c6cu,0x0c068c6eu,0x0c068c70u,
0x0c068c72u,0x0c068c74u,0x0c068c76u,0x0c068c78u,0x0c068c7au,0x0c068c7cu,0x0c068c7eu,0x0c068c80u,0x0c068c82u,0x0c068c84u,0x0c068c86u,0x0c068c88u,0x0c068c8au,0x0c068c8cu,0x0c068c8eu,0x0c068c90u,
0x0c068c92u,0x0c068c94u,0x0c068c96u,0x0c068c98u,0x0c068c9au,0x0c068c9cu,0x0c068c9eu,0x0c068ca0u,0x0c068ca2u,0x0c068ca4u,0x0c068ca6u,0x0c068ca8u,0x0c068caau,0x0c068cacu,0x0c068caeu,0x0c068cb0u,
0x0c068cb2u,0x0c068cb4u,0x0c068cb6u,0x0c068cb8u,0x0c068cbau,0x0c068cbcu,0x0c068cbeu,0x0c068cc0u,0x0c068cc2u,0x0c068cc4u,0x0c068cc6u,0x0c068cc8u,0x0c068ccau,0x0c068cccu,0x0c068cceu,0x0c068cd0u,
0x0c068cd2u,0x0c068cd4u,0x0c068cd6u,0x0c068cd8u,0x0c068cdau,0x0c068cdcu,0x0c068cdeu,0x0c068ce0u,0x0c068ce2u,0x0c068ce4u,0x0c068ce6u,0x0c068ce8u,0x0c068ceau,0x0c068cecu,0x0c068ceeu,0x0c068cf0u,
0x0c068cf2u,0x0c068cf4u,0x0c068cf6u,0x0c068cf8u,0x0c068cfau,0x0c068cfcu,0x0c068cfeu,0x0c068d00u,0x0c068d02u,0x0c068d04u,0x0c068d06u,0x0c068d08u,0x0c068d0au,0x0c068d0cu,0x0c074800u,0x0c074802u,
0x0c074804u,0x0c074806u,0x0c074808u,0x0c07480au,0x0c07480cu,0x0c07480eu,0x0c074810u,0x0c074812u,0x0c074814u,0x0c074816u,0x0c074818u,0x0c07481au,0x0c07481cu,0x0c07481eu,0x0c074820u,0x0c074822u,
0x0c074824u,0x0c074826u,0x0c074828u,0x0c07482au,0x0c07482cu,0x0c088dd4u,0x0c088dd6u,0x0c088dd8u,0x0c088ddau,0x0c088ddcu,0x0c088ddeu,0x0c088de0u,0x0c088de2u,0x0c088de4u,0x0c088de6u,0x0c088de8u,
0x0c088deau,0x0c088decu,0x0c088deeu,0x0c088df0u,0x0c088df2u,0x0c088df4u,0x0c088df6u,0x0c088df8u,0x0c088dfau,0x0c088dfcu,0x0c088dfeu,0x0c088e00u,0x0c088e02u,0x0c088e04u,0x0c088e06u,0x0c088e08u,
0x0c088e0au,0x0c088e0cu,0x0c088e0eu,0x0c088e10u,0x0c088e12u,0x0c088e14u,0x0c088e16u,0x0c088e18u,0x0c088e1au,0x0c088e1cu,0x0c088e1eu,0x0c088e20u,0x0c088e22u,0x0c088e24u,0x0c088e26u,0x0c088e28u,
0x0c088e2au,0x0c088e2cu,0x0c088e2eu,0x0c088e30u,0x0c088e32u,0x0c088e34u,0x0c088e36u,0x0c088e38u,0x0c088e3au,0x0c088e3cu,0x0c088e3eu,0x0c088e40u,0x0c088e42u,0x0c088e44u,0x0c088e46u,0x0c088e48u,
0x0c088e4au,0x0c088e4cu,0x0c088e4eu,0x0c088e50u,0x0c088e52u,0x0c088e54u,0x0c088e56u,0x0c088e58u,0x0c088e5au,0x0c088e5cu,0x0c088e5eu,0x0c088e60u,0x0c088e62u,0x0c088e64u,0x0c088e66u,0x0c088e68u,
0x0c088e6au,0x0c088e6cu,0x0c088e6eu,0x0c088e70u,0x0c088e72u,0x0c088e74u,0x0c088e76u,0x0c088e78u,0x0c088e7au,0x0c088e7cu,0x0c088e7eu,0x0c088e80u,0x0c088e82u,0x0c088e84u,0x0c088e86u,0x0c088e88u,
0x0c088e8au,0x0c088e8cu,0x0c088e8eu,0x0c088e90u,0x0c088e92u,0x0c088e94u,0x0c088e96u,0x0c088e98u,0x0c088e9au,0x0c088e9cu,0x0c088e9eu,0x0c088ea0u,0x0c088ea2u,0x0c088ea4u,0x0c088ea6u,0x0c088ea8u,
0x0c088eaau,0x0c088eacu,0x0c088eaeu,0x0c088eb0u,0x0c088eb2u,0x0c088eb4u,0x0c088eb6u,0x0c088eb8u,0x0c088ebau,0x0c088ebcu,0x0c088ebeu,0x0c088ec0u,0x0c088ec2u,0x0c088ec4u,0x0c088ec6u,0x0c088ec8u,
0x0c0993e8u,0x0c0993eau,0x0c0993ecu,0x0c0993eeu,0x0c0993f0u,0x0c0993f2u,0x0c0993f4u,0x0c0993f6u,0x0c0993f8u,0x0c0993fau,0x0c0993fcu,0x0c0993feu,0x0c099400u,0x0c099402u,0x0c099404u,0x0c099406u,
0x0c099408u,0x0c09940au,0x0c09940cu,0x0c09940eu,0x0c099410u,0x0c099412u,0x0c099414u,0x0c099416u,0x0c099418u,0x0c09941au,0x0c09941cu,0x0c09941eu,0x0c099420u,0x0c099422u,0x0c099424u,0x0c099426u,
0x0c099428u,0x0c09942au,0x0c09942cu,0x0c09942eu,0x0c099430u,0x0c099432u,0x0c099434u,0x0c099436u,0x0c099438u,0x0c09943au,0x0c09943cu,0x0c09943eu,0x0c099440u,0x0c099442u,0x0c099444u,0x0c099446u,
0x0c099448u,0x0c09944au,0x0c09944cu,0x0c09944eu,0x0c099450u,0x0c099452u,0x0c099454u,0x0c099456u,0x0c099458u,0x0c09945au,0x0c09945cu,0x0c09945eu,0x0c099460u,0x0c099462u,0x0c099464u,0x0c099466u,
0x0c099468u,0x0c09946au,0x0c09946cu,0x0c09946eu,0x0c099470u,0x0c099472u,0x0c099474u,0x0c099476u,0x0c099478u,0x0c09947au,0x0c09947cu,0x0c09947eu,0x0c099480u,0x0c099482u,0x0c099484u,0x0c099486u,
0x0c099488u,0x0c09948au,0x0c09948cu,0x0c09948eu,0x0c099490u,0x0c099492u,0x0c099494u,0x0c099496u,0x0c099498u,0x0c09949au,0x0c09949cu,0x0c09949eu,0x0c0994a0u,0x0c0994a2u,0x0c0994a4u,0x0c0994a6u,
0x0c0994a8u,0x0c0994aau,0x0c0994d4u,0x0c0994d6u,0x0c0994d8u,0x0c0994dau,0x0c0994dcu,0x0c0994deu,0x0c0994e0u,0x0c0994e2u,0x0c0994e4u,0x0c0994e6u,0x0c0994e8u,0x0c0994eau,0x0c0994ecu,0x0c0994eeu,
0x0c0994f0u,0x0c0994f2u,0x0c0994f4u,0x0c0994f6u,0x0c0994f8u,0x0c0994fau,0x0c0994fcu,0x0c0994feu,0x0c099500u,0x0c099502u,0x0c099504u,0x0c099506u,0x0c099508u,0x0c09950au,0x0c09950cu,0x0c09950eu,
0x0c099510u,0x0c099512u,0x0c099514u,0x0c099516u,0x0c099518u,0x0c09951au,0x0c09951cu,0x0c09951eu,0x0c099520u,0x0c099522u,0x0c099524u,0x0c099526u,0x0c099528u,0x0c09952au,0x0c09952cu,0x0c09952eu,
0x0c099530u,0x0c099532u,0x0c099534u,0x0c099536u,0x0c099538u,0x0c09953au,0x0c09953cu,0x0c09953eu,0x0c099540u,0x0c099542u,0x0c099544u,0x0c099546u,0x0c099548u,0x0c09954au,0x0c09954cu,0x0c09954eu,
0x0c099550u,0x0c099552u,0x0c099554u,0x0c099556u,0x0c099558u,0x0c09955au,0x0c09955cu,0x0c09955eu,0x0c099560u,0x0c099562u,0x0c099564u,0x0c099566u,0x0c099568u,0x0c09956au,0x0c09956cu,0x0c09956eu,
0x0c099570u,0x0c099572u,0x0c099574u,0x0c099576u,0x0c099578u,0x0c09957au,0x0c09957cu,0x0c09957eu,0x0c099580u,0x0c099582u,0x0c099584u,0x0c099586u,0x0c099588u,0x0c09958au,0x0c09958cu,0x0c09958eu,
0x0c099590u,0x0c099592u,0x0c099594u,0x0c099596u,0x0c099598u,0x0c09959au,0x0c09959cu,0x0c09959eu,0x0c0995a0u,0x0c0995dcu,0x0c0995deu,0x0c0995e0u,0x0c0995e2u,0x0c0995e4u,0x0c0995e6u,0x0c0995e8u,
0x0c0995eau,0x0c0995ecu,0x0c0995eeu,0x0c0995f0u,0x0c0995f2u,0x0c0995f4u,0x0c0995f6u,0x0c0995f8u,0x0c0995fau,0x0c0995fcu,0x0c0995feu,0x0c099600u,0x0c099602u,0x0c099604u,0x0c099606u,0x0c099608u,
0x0c09960au,0x0c09960cu,0x0c09960eu,0x0c099610u,0x0c099612u,0x0c099614u,0x0c099616u,0x0c099618u,0x0c09961au,0x0c09961cu,0x0c09961eu,0x0c099620u,0x0c099622u,0x0c099624u,0x0c099626u,0x0c099628u,
0x0c09962au,0x0c09962cu,0x0c09962eu,0x0c099630u,0x0c099632u,0x0c099634u,0x0c099636u,0x0c099638u,0x0c09963au,0x0c09963cu,0x0c09963eu,0x0c099640u,0x0c099642u,0x0c099644u,0x0c099646u,0x0c099648u,
0x0c09964au,0x0c09964cu,0x0c09964eu,0x0c099650u,0x0c099652u,0x0c099654u,0x0c099656u,0x0c099658u,0x0c09965au,0x0c09965cu,0x0c09965eu,0x0c099660u,0x0c099662u,0x0c099664u,0x0c099666u,0x0c099668u,
0x0c09966au,0x0c09966cu,0x0c09966eu,0x0c099670u,0x0c099672u,0x0c099674u,0x0c099676u,0x0c099678u,0x0c09967au,0x0c09967cu,0x0c09967eu,0x0c099680u,0x0c099682u,0x0c099684u,0x0c099686u,0x0c099688u,
0x0c09968au,0x0c09968cu,0x0c09968eu,0x0c099690u,0x0c099692u,0x0c099694u,0x0c099696u,0x0c099698u,0x0c09969au,0x0c09969cu,0x0c09969eu,0x0c0996a0u,0x0c0996a2u,0x0c0996a4u,0x0c0996a6u,0x0c0996a8u,
0x0c0996aau,0x0c0996acu,0x0c0996aeu,0x0c0996b0u,0x0c0996b2u,0x0c0996b4u,0x0c0996b6u,0x0c0996b8u,0x0c0996bau,0x0c0996bcu,0x0c0996beu,0x0c0996c0u,0x0c0996c2u,0x0c0a81eeu,0x0c0a81f0u,0x0c0a81f2u,
0x0c0a81f4u,0x0c0a81f6u,0x0c0a81f8u,0x0c0a81fau,0x0c0a81fcu,0x0c0a81feu,0x0c0a8200u,0x0c0a8202u,0x0c0a8204u,0x0c0a8206u,0x0c0a8208u,0x0c0a820au,0x0c0a820cu,0x0c0a820eu,0x0c0a8210u,0x0c0a8212u,
0x0c0a8214u,0x0c0a8216u,0x0c0a8218u,0x0c0a821au,0x0c0a821cu,0x0c0a821eu,0x0c0a8220u,0x0c0a8222u,0x0c0a8224u,0x0c0a8226u,0x0c0a8228u,0x0c0a822au,0x0c0a822cu,0x0c0a822eu,0x0c0a8230u,0x0c0a8232u,
0x0c0a8234u,0x0c0a8236u,0x0c0a8238u,0x0c0a823au,0x0c0a823cu,0x0c0a823eu,0x0c0a8240u,0x0c0a8242u,0x0c0a8244u,0x0c0a8246u,0x0c0a8248u,0x0c0a824au,0x0c0a824cu,0x0c0a824eu,0x0c0a8250u,0x0c0a8252u,
0x0c0a8254u,0x0c0a8256u,0x0c0a8258u,0x0c0a825au,0x0c0a825cu,0x0c0a825eu,0x0c0a8260u,0x0c0a8262u,0x0c0a8264u,0x0c0a8266u,0x0c0a8268u,0x0c0a826au,0x0c0a826cu,0x0c0a826eu,0x0c0a8270u,0x0c0a8272u,
0x0c0a8274u,0x0c0a8276u,0x0c0a8278u,0x0c0a827au,0x0c0a827cu,0x0c0a827eu,0x0c0a8280u,0x0c0a8282u,0x0c0a8284u,0x0c0a8286u,0x0c0a8288u,0x0c0a828au,0x0c0a828cu,0x0c0a828eu,0x0c0a8290u,0x0c0a8292u,
0x0c0a8294u,0x0c0a8296u,0x0c0a8298u,0x0c0a829au,0x0c0a8acau,0x0c0a8accu,0x0c0a8aceu,0x0c0a8ad0u,0x0c0a8ad2u,0x0c0a8ad4u,0x0c0a8ad6u,0x0c0a8ad8u,0x0c0a8adau,0x0c0a8adcu,0x0c0a8adeu,0x0c0a8ae0u,
0x0c0a8ae2u,0x0c0a8ae4u,0x0c0a8ae6u,0x0c0a8ae8u,0x0c0a8aeau,0x0c0a8aecu,0x0c0a8aeeu,0x0c0a8af0u,0x0c0a8af2u,0x0c0a8af4u,0x0c0a8af6u,0x0c0a8af8u,0x0c0a8afau,0x0c0a8afcu,0x0c0a8afeu,0x0c0a8b00u,
0x0c0a8b02u,0x0c0a8b04u,0x0c0a8b06u,0x0c0a8b08u,0x0c0a8b0au,0x0c0a8b0cu,0x0c0a8b0eu,0x0c0a8b10u,0x0c0a8b12u,0x0c0a8b14u,0x0c0a8b16u,0x0c0a8b18u,0x0c0a8b1au,0x0c0a8b1cu,0x0c0a8b1eu,0x0c0a8b20u,
0x0c0a8b22u,0x0c0a8b24u,0x0c0a8b26u,0x0c0a8b28u,0x0c0a8b2au,0x0c0a8b2cu,0x0c0a8b2eu,0x0c0a8b30u,0x0c0a8b32u,0x0c0a8b34u,0x0c0a8b36u,0x0c0a8b38u,0x0c0a8b3au,0x0c0a8b3cu,0x0c0a8b3eu,0x0c0a8b40u,
0x0c0a8b42u,0x0c0a8b44u,0x0c0a8b46u,0x0c0a8b48u,0x0c0a8b4au,0x0c0a8b4cu,0x0c0a8b4eu,0x0c0a8b50u,0x0c0a8b52u,0x0c0a8b54u,0x0c0a8b56u,0x0c0a8b58u,0x0c0a8b5au,0x0c0a8b5cu,0x0c0a8b5eu,0x0c0a8b60u,
0x0c0a8b62u,0x0c0a8b64u,0x0c0a8b66u,0x0c0a8b68u,0x0c0a8b6au,0x0c0a8b6cu,0x0c0a8b6eu,0x0c0a8b70u,0x0c0a8b72u,0x0c0a8b74u,0x0c0a8b76u,0x0c0a8b78u,0x0c0a8b7au,0x0c0a8b7cu,0x0c0a8b7eu,0x0c0a8b80u,
0x0c0a8b82u,0x0c0a8b84u,0x0c0a8b86u,0x0c0a8b88u,0x0c0a8b8au,0x0c0a8b8cu,0x0c0a8b8eu,0x0c0a8b90u,0x0c0a8b92u,0x0c0a8b94u,0x0c0a8b96u,0x0c0a8b98u,0x0c0a8b9au,0x0c0a8b9cu,0x0c0a8b9eu,0x0c0a8ba0u,
0x0c0a8ba2u,0x0c0a8ba4u,0x0c0a8ba6u,0x0c0a8ba8u,0x0c0a8baau,0x0c0a8bacu,0x0c0a8baeu,0x0c0a8bb0u,0x0c0a8bb2u,0x0c0a8bb4u,0x0c0a8bb6u,0x0c0a8bb8u,0x0c0a8bbau,0x0c0a8bbcu,0x0c0a8bbeu,0x0c0a8bc0u,
0x0c0a8bc2u,0x0c0a8bc4u,0x0c0a8bc6u,0x0c0a8bc8u,0x0c0a8bcau,0x0c0a8bccu,0x0c0a8bceu,0x0c0a8bd0u,0x0c0a8bd2u,0x0c0a8bd4u,0x0c0a8bd6u,0x0c0a8bd8u,0x0c0a8bdau,0x0c0a8bdcu,0x0c0a8bdeu,0x0c0a8be0u,
0x0c0a8be2u,0x0c0a8be4u,0x0c0a8be6u,0x0c0a8be8u,0x0c0a8beau,0x0c0a8becu,0x0c0a8beeu,0x0c0a8bf0u,0x0c0a8bf2u,0x0c0a8bf4u,0x0c0a8bf6u,0x0c0a8c38u,0x0c0a8c3au,0x0c0a8c3cu,0x0c0a8c3eu,0x0c0a8c40u,
0x0c0a8c42u,0x0c0a8c44u,0x0c0a8c46u,0x0c0a8c48u,0x0c0a8c4au,0x0c0a8c4cu,0x0c0a8c4eu,0x0c0a8c50u,0x0c0a8c52u,0x0c0a8c54u,0x0c0a8c56u,0x0c0a8c58u,0x0c0a8c5au,0x0c0a8c5cu,0x0c0a8c5eu,0x0c0a8c60u,
0x0c0a8c62u,0x0c0a8c64u,0x0c0a8c66u,0x0c0a8c68u,0x0c0a8c6au,0x0c0a8c6cu,0x0c0a8c6eu,0x0c0a8c70u,0x0c0a8c72u,0x0c0a8c74u,0x0c0a8c76u,0x0c0a8c78u,0x0c0a8c7au,0x0c0a8c7cu,0x0c0a8c7eu,0x0c0a8c80u,
0x0c0a8c82u,0x0c0a8c84u,0x0c0a8c86u,0x0c0a8c88u,0x0c0a8c8au,0x0c0a8c8cu,0x0c0a8c8eu,0x0c0a8c90u,0x0c0a8c92u,0x0c0a8c94u,0x0c0a8c96u,0x0c0a8c98u,0x0c0a8c9au,0x0c0a8c9cu,0x0c0a8c9eu,0x0c0a8ca0u,
0x0c0a8ca2u,0x0c0a8ca4u,0x0c0a8ca6u,0x0c0a8ca8u,0x0c0a8caau,0x0c0a8cacu,0x0c0a8caeu,0x0c0a8cb0u,0x0c0a8cb2u,0x0c0a8cb4u,0x0c0a8cb6u,0x0c0a8cb8u,0x0c0a8cbau,0x0c0a8cbcu,0x0c0a8cbeu,0x0c0a8cc0u,
0x0c0a8cc2u,0x0c0a8cc4u,0x0c0a8cc6u,0x0c0a8cc8u,0x0c0a8ccau,0x0c0a8cccu,0x0c0a8cceu,0x0c0a8cd0u,0x0c0a8cd2u,0x0c0a8cd4u,0x0c0a8cd6u,0x0c0a8cd8u,0x0c0a8cdau,0x0c0a8cdcu,0x0c0a8cdeu,0x0c0a8ce0u,
0x0c0a8ce2u,0x0c0a8ce4u,0x0c0a8ce6u,0x0c0a8ce8u,0x0c0a8ceau,0x0c0a8cecu,0x0c0a8ceeu,0x0c0a8cf0u,0x0c0a8cf2u,0x0c0a8cf4u,0x0c0a8cf6u,0x0c0a8cf8u,0x0c0a8cfau,0x0c0a8cfcu,0x0c0a8cfeu,0x0c0a8d00u,
0x0c0a8d02u,0x0c0a8d04u,0x0c0a8d06u,0x0c0a8d08u,0x0c0a8d0au,0x0c0a8d0cu,0x0c0a8d0eu,0x0c0a8d10u,0x0c0a8d12u,0x0c0a8d14u,0x0c0a8d16u,0x0c0a8d18u,0x0c0a8d1au,0x0c0a8d1cu,0x0c0a8d1eu,0x0c0a8d20u,
0x0c0a8d22u,0x0c0a8d24u,0x0c0a8d26u,0x0c0a8d28u,0x0c0a8d58u,0x0c0a8d5au,0x0c0a8d5cu,0x0c0a8d5eu,0x0c0a8d60u,0x0c0a8d62u,0x0c0a8d64u,0x0c0a8d66u,0x0c0a8d68u,0x0c0a8d6au,0x0c0a8d6cu,0x0c0a8d6eu,
0x0c0a8d70u,0x0c0a8d72u,0x0c0a8d74u,0x0c0a8d76u,0x0c0a8d78u,0x0c0a8d7au,0x0c0a8d7cu,0x0c0a8d7eu,0x0c0a8d80u,0x0c0a8d82u,0x0c0a8d84u,0x0c0a8d86u,0x0c0a8d88u,0x0c0a8d8au,0x0c0a8d8cu,0x0c0a8d8eu,
0x0c0a8d90u,0x0c0a8d92u,0x0c0a8d94u,0x0c0a8d96u,0x0c0a8d98u,0x0c0a8d9au,0x0c0a8d9cu,0x0c0a8d9eu,0x0c0a8da0u,0x0c0a8da2u,0x0c0a8da4u,0x0c0a8da6u,0x0c0a8da8u,0x0c0a8daau,0x0c0a8dacu,0x0c0a8daeu,
0x0c0a8db0u,0x0c0a8db2u,0x0c0a8db4u,0x0c0a8db6u,0x0c0a8db8u,0x0c0a8dbau,0x0c0a8dbcu,0x0c0a8dbeu,0x0c0a8dc0u,0x0c0a8dc2u,0x0c0a8dc4u,0x0c0a8dc6u,0x0c0a8dc8u,0x0c0a8dcau,0x0c0a8dccu,0x0c0a8dceu,
0x0c0a8dd0u,0x0c0a8dd2u,0x0c0a8dd4u,0x0c0a8dd6u,0x0c0a8dd8u,0x0c0a8ddau,0x0c0a8ddcu,0x0c0a8ddeu,0x0c0a8de0u,0x0c0a8de2u,0x0c0a8de4u,0x0c0a8de6u,0x0c0a8de8u,0x0c0a8deau,0x0c0a8decu,0x0c0a8deeu,
0x0c0a8df0u,0x0c0a8df2u,0x0c0a8df4u,0x0c0a8df6u,0x0c0a8df8u,0x0c0a8dfau,0x0c0a8dfcu,0x0c0a8dfeu,0x0c0a91dau,0x0c0a91dcu,0x0c0a91deu,0x0c0a91e0u,0x0c0a91e2u,0x0c0a91e4u,0x0c0a91e6u,0x0c0a91e8u,
0x0c0a91eau,0x0c0a91ecu,0x0c0a91eeu,0x0c0a91f0u,0x0c0a91f2u,0x0c0a91f4u,0x0c0a91f6u,0x0c0a91f8u,0x0c0a91fau,0x0c0a91fcu,0x0c0a91feu,0x0c0a9200u,0x0c0a9202u,0x0c0a9204u,0x0c0a9206u,0x0c0a9208u,
0x0c0a920au,0x0c0a920cu,0x0c0a920eu,0x0c0a9210u,0x0c0a9212u,0x0c0a9214u,0x0c0a9216u,0x0c0a9218u,0x0c0a921au,0x0c0a921cu,0x0c0a921eu,0x0c0a9220u,0x0c0a9222u,0x0c0a9224u,0x0c0a9226u,0x0c0a9228u,
0x0c0a922au,0x0c0a922cu,0x0c0a922eu,0x0c0a9230u,0x0c0a9232u,0x0c0a9234u,0x0c0a9236u,0x0c0a9238u,0x0c0a923au,0x0c0a923cu,0x0c0a923eu,0x0c0a9240u,0x0c0a9242u,0x0c0a926au,0x0c0a926cu,0x0c0a926eu,
0x0c0a9270u,0x0c0a9272u,0x0c0a9274u,0x0c0a9276u,0x0c0a9278u,0x0c0a927au,0x0c0a927cu,0x0c0a927eu,0x0c0a9280u,0x0c0a9282u,0x0c0a9284u,0x0c0a9286u,0x0c0a9288u,0x0c0a928au,0x0c0a928cu,0x0c0a928eu,
0x0c0a9290u,0x0c0a9444u,0x0c0a9446u,0x0c0a9448u,0x0c0a944au,0x0c0a944cu,0x0c0a944eu,0x0c0a9450u,0x0c0a94d0u,0x0c0a94d2u,0x0c0a94d4u,0x0c0a94d6u,0x0c0a94d8u,0x0c0a94dau,0x0c0a94dcu,0x0c0a94deu,
0x0c0a94e0u,0x0c0a94e2u,0x0c0a94e4u,0x0c0a94e6u,0x0c0a94e8u,0x0c0a94eau,0x0c0a94ecu,0x0c0a94eeu,0x0c0a94f0u,0x0c0a94f2u,0x0c0a94f4u,0x0c0a94f6u,0x0c0a94f8u,0x0c0a94fau,0x0c0a94fcu,0x0c0a94feu,
0x0c0a9500u,0x0c0a9502u,0x0c0a9504u,0x0c0a9506u,0x0c0a9508u,0x0c0a950au,0x0c0a950cu,0x0c0a950eu,0x0c0a9510u,0x0c0a9512u,0x0c0a9514u,0x0c0a9516u,0x0c0a9518u,0x0c0a951au,0x0c0a951cu,0x0c0a951eu,
0x0c0a9520u,0x0c0a9522u,0x0c0a9524u,0x0c0a9526u,0x0c0a9528u,0x0c0a952au,0x0c0a952cu,0x0c0a952eu,0x0c0a9530u,0x0c0a9532u,0x0c0a9534u,0x0c0a9536u,0x0c0a9538u,0x0c0a953au,0x0c0a953cu,0x0c0a953eu,
0x0c0a9540u,0x0c0a9542u,0x0c0a9544u,0x0c0a9546u,0x0c0a9548u,0x0c0a954au,0x0c0a954cu,0x0c0a954eu,0x0c0a9550u,0x0c0a9552u,0x0c0a9554u,0x0c0a9556u,0x0c0a9558u,0x0c0a955au,0x0c0a955cu,0x0c0a955eu,
0x0c0a9560u,0x0c0a9562u,0x0c0a9564u,0x0c0a9566u,0x0c0a9568u,0x0c0a956au,0x0c0a956cu,0x0c0a956eu,0x0c0a9570u,0x0c0a9572u,0x0c0a9574u,0x0c0a9576u,0x0c0a9578u,0x0c0a957au,0x0c0a957cu,0x0c0a957eu,
0x0c0a9580u,0x0c0a9582u,0x0c0a9584u,0x0c0a9586u,0x0c0a9588u,0x0c0a958au,0x0c0a958cu,0x0c0a958eu,0x0c0ae0ecu,0x0c0ae0eeu,0x0c0ae0f0u,0x0c0ae0f2u,0x0c0ae0f4u,0x0c0ae0f6u,0x0c0ae0f8u,0x0c0ae0fau,
0x0c0ae0fcu,0x0c0ae0feu,0x0c0ae100u,0x0c0ae102u,0x0c0ae104u,0x0c0ae106u,0x0c0ae108u,0x0c0ae10au,0x0c0ae10cu,0x0c0ae10eu,0x0c0ae110u,0x0c0ae112u,0x0c0ae114u,0x0c0ae116u,0x0c0ae118u,0x0c0ae11au,
0x0c0ae11cu,0x0c0ae11eu,0x0c0ae120u,0x0c0ae122u,0x0c0ae124u,0x0c0ae126u,0x0c0ae128u,0x0c0ae12au,0x0c0ae12cu,0x0c0ae12eu,0x0c0ae130u,0x0c0ae132u,0x0c0ae134u,0x0c0ae136u,0x0c0ae138u,0x0c0ae13au,
0x0c0ae13cu,0x0c0ae13eu,0x0c0ae140u,0x0c0ae142u,0x0c0ae144u,0x0c0ae146u,0x0c0ae148u,0x0c0ae14au,0x0c0ae14cu,0x0c0ae14eu,0x0c0ae150u,0x0c0ae152u,0x0c0ae154u,0x0c0ae156u,0x0c0ae158u,0x0c0ae15au,
0x0c0ae15cu,0x0c0ae15eu,0x0c0ae184u,0x0c0ae186u,0x0c0ae188u,0x0c0ae18au,0x0c0ae18cu,0x0c0ae18eu,0x0c0ae190u,0x0c0ae192u,0x0c0ae194u,0x0c0ae196u,0x0c0ae198u,0x0c0ae19au,0x0c0ae19cu,0x0c0ae19eu,
0x0c0ae1a0u,0x0c0ae1a2u,0x0c0ae1a4u,0x0c0ae1a6u,0x0c0ae1a8u,0x0c0ae1aau,0x0c0ae1acu,0x0c0ae1aeu,0x0c0ae1b0u,0x0c0ae1b2u,0x0c0ae1b4u,0x0c0ae1b6u,0x0c0ae1b8u,0x0c0ae1bau,0x0c0ae1bcu,0x0c0ae1beu,
0x0c0ae1c0u,0x0c0ae1c2u,0x0c0ae1c4u,0x0c0ae1c6u,0x0c0ae1c8u,0x0c0ae1cau,0x0c0ae1ccu,0x0c0ae1ceu,0x0c0ae1d0u,0x0c0ae1d2u,0x0c0ae1d4u,0x0c0ae1d6u,0x0c0ae1d8u,0x0c0ae1dau,0x0c0ae1dcu,0x0c0ae1deu,
0x0c0ae1e0u,0x0c0ae1e2u,0x0c0ae1e4u,0x0c0ae1e6u,0x0c0ae1e8u,0x0c0ae1eau,0x0c0ae1ecu,0x0c0ae1eeu,0x0c0ae1f0u,0x0c0ae1f2u,0x0c0ae1f4u,0x0c0ae1f6u,0x0c0ae1f8u,0x0c0ae1fau,0x0c0ae1fcu,0x0c0ae1feu,
0x0c0ae200u,0x0c0ae202u,0x0c0ae204u,0x0c0ae206u,0x0c0ae208u,0x0c0ae20au,0x0c0ae20cu,0x0c0ae20eu,0x0c0ae210u,0x0c0ae212u,0x0c0ae214u,0x0c0ae216u,0x0c0ae218u,0x0c0ae21au,0x0c0ae21cu,0x0c0ae21eu,
0x0c0ae220u,0x0c0ae222u,0x0c0ae224u,0x0c0ae226u,0x0c0ae228u,0x0c0ae22au,0x0c0ae22cu,0x0c0ae22eu,0x0c0ae230u,0x0c0ae232u,0x0c0ae234u,0x0c0ae236u,0x0c0ae238u,0x0c0ae23au,0x0c0ae23cu,0x0c0ae23eu,
0x0c0ae240u,0x0c0ae242u,0x0c0ae244u,0x0c0ae246u,0x0c0ae248u,0x0c0ae24au,0x0c0ae24cu,0x0c0ae24eu,0x0c0ae250u,0x0c0ae252u,0x0c0ae254u,0x0c0ae256u,0x0c0ae258u,0x0c0ae25au,0x0c0bef2eu,0x0c0bef30u,
0x0c0bef32u,0x0c0bef34u,0x0c0bef36u,0x0c0bef38u,0x0c0bef3au,0x0c0bef3cu,0x0c0bef3eu,0x0c0bef40u,0x0c0bef42u,0x0c0bef44u,0x0c0bef46u,0x0c0bef48u,0x0c0bef4au,0x0c0bef4cu,0x0c0bef4eu,0x0c0bef50u,
0x0c0bef52u,0x0c0bef54u,0x0c0bef56u,0x0c0bef58u,0x0c0bef5au,0x0c0bef5cu,0x0c0bef5eu,0x0c0bef60u,0x0c0bef62u,0x0c0bef64u,0x0c0bef66u,0x0c0bef68u,0x0c0bef6au,0x0c0bef6cu,0x0c0bef6eu,0x0c0bef70u,
0x0c0bef72u,0x0c0bef74u,0x0c0bef76u,0x0c0bef78u,0x0c0bef7au,0x0c0bef7cu,0x0c0bef7eu,0x0c0bef80u,0x0c0bef82u,0x0c0bef84u,0x0c0bef86u,0x0c0bef88u,0x0c0bef8au,0x0c0bef8cu,0x0c0bef8eu,0x0c0bef90u,
0x0c0bef92u,0x0c0bef94u,0x0c0bef96u,0x0c0bef98u,0x0c0bef9au,0x0c0bef9cu,0x0c0bef9eu,0x0c0befa0u,0x0c0befa2u,0x0c0befa4u,0x0c0befa6u,0x0c0befa8u,0x0c0befaau,0x0c0befacu,0x0c0befaeu,0x0c0befb0u,
0x0c0befb2u,0x0c0befb4u,0x0c0befb6u,0x0c0befb8u,0x0c0befbau,0x0c0befbcu,0x0c0befbeu,0x0c0befc0u,0x0c0befc2u,0x0c0befc4u,0x0c0befc6u,0x0c0befc8u,0x0c0befcau,0x0c0befccu,0x0c0befceu,0x0c0befd0u,
0x0c0befd2u,0x0c0befd4u,0x0c0befd6u,0x0c0befd8u,0x0c0befdau,0x0c0befdcu,0x0c0befdeu,0x0c0befe0u,0x0c0befe2u,0x0c0befe4u,0x0c0befe6u,0x0c0befe8u,0x0c0befeau,0x0c0befecu,0x0c0befeeu,0x0c0beff0u,
0x0c0beff2u,0x0c0beff4u,0x0c0beff6u,0x0c0beff8u,0x0c0beffau,0x0c0beffcu,0x0c0beffeu,0x0c0bf000u,0x0c0bf002u,0x0c0bf004u,0x0c0bf006u,0x0c0bf008u,0x0c0bf00au,0x0c0bf00cu,0x0c0bf00eu,0x0c0bf010u,
0x0c0bf012u,0x0c0bf014u,0x0c0bf016u,0x0c0bf018u,0x0c0bf01au,0x0c0bf01cu,0x0c0bf01eu,0x0c0bf020u,0x0c0bf022u,0x0c0bf024u,0x0c0bf026u,0x0c0bf028u,0x0c0bf02au,0x0c0bf02cu,0x0c0bf02eu,0x0c0c66b8u,
0x0c0c66bau,0x0c0c7e1cu,0x0c0c7e1eu,0x0c0c7e20u,0x0c0c7e22u,0x0c0c7e24u,0x0c0c7e26u,0x0c0c7e28u,0x0c0c7e2au,0x0c0c7e2cu,0x0c0c7e2eu,0x0c0c7e30u,0x0c0c7e32u,0x0c0c7e34u,0x0c0c7e36u,0x0c0c7e38u,
0x0c0c7e3au,0x0c0c7e3cu,0x0c0c7e3eu,0x0c0c7e40u,0x0c0c7e42u,0x0c0c7e44u,0x0c0c7e46u,0x0c0c7e48u,0x0c0c7e4au,0x0c0c7e4cu,0x0c0c7e4eu,0x0c0c7e50u,0x0c0c7e52u,0x0c0c7e54u,0x0c0c7e56u,0x0c0c7e58u,
0x0c0c7e5au,0x0c0c7e5cu,0x0c0c7e5eu,0x0c0c7e60u,0x0c0c7e62u,0x0c0c7e64u,0x0c0c7e66u,0x0c0c7e68u,0x0c0c7e6au,0x0c0c7e6cu,0x0c0c7e6eu,0x0c0c7e70u,0x0c0c7e72u,0x0c0c7e74u,0x0c0c7e76u,0x0c0c7e78u,
0x0c0c7e7au,0x0c0c7e7cu,0x0c0c7e7eu,0x0c0c7e80u,0x0c0c7e82u,0x0c0c7e84u,0x0c0c7e86u,0x0c0c7e88u,0x0c0c7e8au,0x0c0c7e8cu,0x0c0c7e8eu,0x0c0c7e90u,0x0c0c7e92u,0x0c0c7e94u,0x0c0c7e96u,0x0c0c7e98u,
0x0c0c7e9au,0x0c0c7e9cu,0x0c0c7e9eu,0x0c0c7ea0u,0x0c0c7ea2u,0x0c0c7ea4u,0x0c0c7ea6u,0x0c0c7ea8u,0x0c0c7eaau,0x0c0c7eacu,0x0c0c7eaeu,0x0c0c7eb0u,0x0c0c7eb2u,0x0c0c7eb4u,0x0c0c7eb6u,0x0c0c7eb8u,
0x0c0c7ebau,0x0c0c7ebcu,0x0c0c7ebeu,0x0c0c7ec0u,0x0c0c7ec2u,0x0c0c7ec4u,0x0c0c7ec6u,0x0c0c7ec8u,0x0c0c7ecau,0x0c0c7eccu,0x0c0c7eceu,0x0c0c7ed0u,0x0c0c7ed2u,0x0c0c7ed4u,0x0c0c7ed6u,0x0c0c7ed8u,
0x0c0c7edau,0x0c0c7edcu,0x0c0c7edeu,0x0c0c7ee0u,0x0c0c7ee2u,0x0c0c7ee4u,0x0c0c7ee6u,0x0c0c7ee8u,0x0c0c7eeau,0x0c0c7eecu,0x0c0c7eeeu,0x0c0c7ef0u,0x0c0c7ef2u,0x0c0c7ef4u,0x0c0c7ef6u,0x0c0c7ef8u,
0x0c0c7efau,0x0c0c7efcu,0x0c0c7efeu,0x0c0c7f00u,0x0c0c7f02u,0x0c0c7f44u,0x0c0c7f46u,0x0c0c7f48u,0x0c0c7f4au,0x0c0c7f4cu,0x0c0c7f4eu,0x0c0c7f50u,0x0c0c7f52u,0x0c0c7f54u,0x0c0c7f56u,0x0c0c7f58u,
0x0c0c7f5au,0x0c0c7f5cu,0x0c0c7f5eu,0x0c0c7f60u,0x0c0c7f62u,0x0c0c7f64u,0x0c0c7f66u,0x0c0c7f68u,0x0c0c7f6au,0x0c0c7f6cu,0x0c0c7f6eu,0x0c0c7f70u,0x0c0c7f72u,0x0c0c7f74u,0x0c0c7f76u,0x0c0c7f78u,
0x0c0c7f7au,0x0c0c7f7cu,0x0c0c7f7eu,0x0c0c7f80u,0x0c0c7f82u,0x0c0c7f84u,0x0c0c7f86u,0x0c0c7f88u,0x0c0c7f8au,0x0c0c7f8cu,0x0c0c7f8eu,0x0c0c7f90u,0x0c0c7f92u,0x0c0c7f94u,0x0c0c7f96u,0x0c0c7f98u,
0x0c0c7f9au,0x0c0c7f9cu,0x0c0c7f9eu,0x0c0c7fa0u,0x0c0c7fa2u,0x0c0c7fa4u,0x0c0c7fa6u,0x0c0c7fa8u,0x0c0c7faau,0x0c0c7facu,0x0c0c7faeu,0x0c0c7fb0u,0x0c0c7fb2u,0x0c0c7fb4u,0x0c0cc5e6u,0x0c0cc5e8u,
0x0c0cc5eau,0x0c0cc5ecu,0x0c0cc5eeu,0x0c0cc5f0u,0x0c0cc5f2u,0x0c0cc5f4u,0x0c0cc5f6u,0x0c0cc5f8u,0x0c0cc5fau,0x0c0cc5fcu,0x0c0cc5feu,0x0c0cc600u,0x0c0cc602u,0x0c0cc604u,0x0c0cc606u,0x0c0cc608u,
0x0c0cc60au,0x0c0cc60cu,0x0c0cc60eu,0x0c0cc610u,0x0c0cc612u,0x0c0cc614u,0x0c0cc616u,0x0c0cc618u,0x0c0cc61au,0x0c0cc61cu,0x0c0cc61eu,0x0c0cc620u,0x0c0cc622u,0x0c0cc624u,0x0c0cc626u,0x0c0cc628u,
0x0c0cc62au,0x0c0cc62cu,0x0c0cc62eu,0x0c0cc630u,0x0c0cc632u,0x0c0cc634u,0x0c0cc636u,0x0c0cc638u,0x0c0cc63au,0x0c0cc63cu,0x0c0cc63eu,0x0c0cc640u,0x0c0cc642u,0x0c0cc644u,0x0c0cc646u,0x0c0cc648u,
0x0c0cc64au,0x0c0cc64cu,
};
int vf3_c81_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
