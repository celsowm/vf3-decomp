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
int vf3_away_batch18_adapter_31(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c096342u: goto P_0c096342;
case 0x0c096344u: goto P_0c096344;
case 0x0c096346u: goto P_0c096346;
case 0x0c096348u: goto P_0c096348;
case 0x0c09634au: goto P_0c09634a;
case 0x0c09634cu: goto P_0c09634c;
case 0x0c09634eu: goto P_0c09634e;
case 0x0c096350u: goto P_0c096350;
case 0x0c096352u: goto P_0c096352;
case 0x0c096354u: goto P_0c096354;
case 0x0c096356u: goto P_0c096356;
case 0x0c096358u: goto P_0c096358;
case 0x0c09635au: goto P_0c09635a;
case 0x0c09635cu: goto P_0c09635c;
case 0x0c09635eu: goto P_0c09635e;
case 0x0c096360u: goto P_0c096360;
case 0x0c096362u: goto P_0c096362;
case 0x0c096364u: goto P_0c096364;
case 0x0c096366u: goto P_0c096366;
case 0x0c096368u: goto P_0c096368;
case 0x0c09636au: goto P_0c09636a;
case 0x0c09636cu: goto P_0c09636c;
case 0x0c09636eu: goto P_0c09636e;
case 0x0c096370u: goto P_0c096370;
case 0x0c096372u: goto P_0c096372;
case 0x0c096374u: goto P_0c096374;
case 0x0c096376u: goto P_0c096376;
case 0x0c096378u: goto P_0c096378;
case 0x0c09637au: goto P_0c09637a;
case 0x0c09637cu: goto P_0c09637c;
case 0x0c09637eu: goto P_0c09637e;
case 0x0c096380u: goto P_0c096380;
case 0x0c096382u: goto P_0c096382;
case 0x0c096384u: goto P_0c096384;
case 0x0c096386u: goto P_0c096386;
case 0x0c096388u: goto P_0c096388;
case 0x0c09638au: goto P_0c09638a;
case 0x0c09638cu: goto P_0c09638c;
case 0x0c09638eu: goto P_0c09638e;
case 0x0c096390u: goto P_0c096390;
case 0x0c096392u: goto P_0c096392;
case 0x0c096394u: goto P_0c096394;
case 0x0c096396u: goto P_0c096396;
case 0x0c096398u: goto P_0c096398;
case 0x0c09639au: goto P_0c09639a;
case 0x0c09639cu: goto P_0c09639c;
case 0x0c09639eu: goto P_0c09639e;
case 0x0c0963a0u: goto P_0c0963a0;
case 0x0c0963a2u: goto P_0c0963a2;
case 0x0c0963a4u: goto P_0c0963a4;
case 0x0c0963a6u: goto P_0c0963a6;
case 0x0c0963a8u: goto P_0c0963a8;
case 0x0c0963aau: goto P_0c0963aa;
case 0x0c0963d0u: goto P_0c0963d0;
case 0x0c0963d2u: goto P_0c0963d2;
case 0x0c0963d4u: goto P_0c0963d4;
case 0x0c0963d6u: goto P_0c0963d6;
case 0x0c0963d8u: goto P_0c0963d8;
case 0x0c0963dau: goto P_0c0963da;
case 0x0c0963dcu: goto P_0c0963dc;
case 0x0c0963deu: goto P_0c0963de;
case 0x0c0963e0u: goto P_0c0963e0;
case 0x0c0963e2u: goto P_0c0963e2;
case 0x0c0963e4u: goto P_0c0963e4;
case 0x0c0963e6u: goto P_0c0963e6;
case 0x0c0963e8u: goto P_0c0963e8;
case 0x0c0963eau: goto P_0c0963ea;
case 0x0c0963ecu: goto P_0c0963ec;
case 0x0c0963eeu: goto P_0c0963ee;
case 0x0c0963f0u: goto P_0c0963f0;
case 0x0c0963f2u: goto P_0c0963f2;
case 0x0c0963f4u: goto P_0c0963f4;
case 0x0c0963f6u: goto P_0c0963f6;
case 0x0c0963f8u: goto P_0c0963f8;
case 0x0c0963fau: goto P_0c0963fa;
case 0x0c0963fcu: goto P_0c0963fc;
case 0x0c0963feu: goto P_0c0963fe;
case 0x0c096400u: goto P_0c096400;
case 0x0c096402u: goto P_0c096402;
case 0x0c096404u: goto P_0c096404;
case 0x0c096406u: goto P_0c096406;
case 0x0c096408u: goto P_0c096408;
case 0x0c09640au: goto P_0c09640a;
case 0x0c09640cu: goto P_0c09640c;
case 0x0c09640eu: goto P_0c09640e;
case 0x0c096410u: goto P_0c096410;
case 0x0c096412u: goto P_0c096412;
case 0x0c096414u: goto P_0c096414;
case 0x0c096416u: goto P_0c096416;
case 0x0c096418u: goto P_0c096418;
case 0x0c09641au: goto P_0c09641a;
case 0x0c09641cu: goto P_0c09641c;
case 0x0c09641eu: goto P_0c09641e;
case 0x0c096420u: goto P_0c096420;
case 0x0c096422u: goto P_0c096422;
case 0x0c096424u: goto P_0c096424;
case 0x0c096426u: goto P_0c096426;
case 0x0c096428u: goto P_0c096428;
case 0x0c09642au: goto P_0c09642a;
case 0x0c09642cu: goto P_0c09642c;
case 0x0c09642eu: goto P_0c09642e;
case 0x0c096430u: goto P_0c096430;
case 0x0c096432u: goto P_0c096432;
case 0x0c096434u: goto P_0c096434;
case 0x0c096436u: goto P_0c096436;
case 0x0c096438u: goto P_0c096438;
case 0x0c09643au: goto P_0c09643a;
case 0x0c09643cu: goto P_0c09643c;
case 0x0c09643eu: goto P_0c09643e;
case 0x0c096440u: goto P_0c096440;
case 0x0c096442u: goto P_0c096442;
case 0x0c096444u: goto P_0c096444;
case 0x0c096446u: goto P_0c096446;
case 0x0c096448u: goto P_0c096448;
case 0x0c09644au: goto P_0c09644a;
case 0x0c09644cu: goto P_0c09644c;
case 0x0c09644eu: goto P_0c09644e;
case 0x0c096450u: goto P_0c096450;
case 0x0c096452u: goto P_0c096452;
case 0x0c096454u: goto P_0c096454;
case 0x0c096456u: goto P_0c096456;
case 0x0c096458u: goto P_0c096458;
case 0x0c09645au: goto P_0c09645a;
case 0x0c09645cu: goto P_0c09645c;
case 0x0c09645eu: goto P_0c09645e;
case 0x0c096460u: goto P_0c096460;
case 0x0c096462u: goto P_0c096462;
case 0x0c096464u: goto P_0c096464;
case 0x0c096466u: goto P_0c096466;
case 0x0c096468u: goto P_0c096468;
case 0x0c09646au: goto P_0c09646a;
case 0x0c09646cu: goto P_0c09646c;
case 0x0c09646eu: goto P_0c09646e;
case 0x0c096470u: goto P_0c096470;
case 0x0c096472u: goto P_0c096472;
case 0x0c096474u: goto P_0c096474;
case 0x0c096476u: goto P_0c096476;
case 0x0c096478u: goto P_0c096478;
case 0x0c09647au: goto P_0c09647a;
case 0x0c09647cu: goto P_0c09647c;
case 0x0c09647eu: goto P_0c09647e;
case 0x0c096480u: goto P_0c096480;
case 0x0c096482u: goto P_0c096482;
case 0x0c096484u: goto P_0c096484;
case 0x0c096486u: goto P_0c096486;
case 0x0c096488u: goto P_0c096488;
case 0x0c09648au: goto P_0c09648a;
case 0x0c09648cu: goto P_0c09648c;
case 0x0c09648eu: goto P_0c09648e;
case 0x0c096490u: goto P_0c096490;
case 0x0c096492u: goto P_0c096492;
case 0x0c096494u: goto P_0c096494;
case 0x0c096496u: goto P_0c096496;
case 0x0c096498u: goto P_0c096498;
case 0x0c09649au: goto P_0c09649a;
case 0x0c09649cu: goto P_0c09649c;
case 0x0c09649eu: goto P_0c09649e;
case 0x0c0964a0u: goto P_0c0964a0;
case 0x0c0964a2u: goto P_0c0964a2;
case 0x0c0964a4u: goto P_0c0964a4;
case 0x0c0964a6u: goto P_0c0964a6;
case 0x0c0964a8u: goto P_0c0964a8;
case 0x0c0964aau: goto P_0c0964aa;
case 0x0c0964acu: goto P_0c0964ac;
case 0x0c0964aeu: goto P_0c0964ae;
case 0x0c0964b0u: goto P_0c0964b0;
case 0x0c0964b2u: goto P_0c0964b2;
case 0x0c0964b4u: goto P_0c0964b4;
case 0x0c0964b6u: goto P_0c0964b6;
case 0x0c0964b8u: goto P_0c0964b8;
case 0x0c0964bau: goto P_0c0964ba;
case 0x0c0964bcu: goto P_0c0964bc;
case 0x0c0964beu: goto P_0c0964be;
case 0x0c0964c0u: goto P_0c0964c0;
case 0x0c0964c2u: goto P_0c0964c2;
case 0x0c09650cu: goto P_0c09650c;
case 0x0c09650eu: goto P_0c09650e;
case 0x0c096510u: goto P_0c096510;
case 0x0c096512u: goto P_0c096512;
case 0x0c096514u: goto P_0c096514;
case 0x0c096516u: goto P_0c096516;
case 0x0c096518u: goto P_0c096518;
case 0x0c09651au: goto P_0c09651a;
case 0x0c09651cu: goto P_0c09651c;
case 0x0c09651eu: goto P_0c09651e;
case 0x0c096520u: goto P_0c096520;
case 0x0c096522u: goto P_0c096522;
case 0x0c096524u: goto P_0c096524;
case 0x0c096526u: goto P_0c096526;
case 0x0c096528u: goto P_0c096528;
case 0x0c09652au: goto P_0c09652a;
case 0x0c09652cu: goto P_0c09652c;
case 0x0c09652eu: goto P_0c09652e;
case 0x0c096530u: goto P_0c096530;
case 0x0c096532u: goto P_0c096532;
case 0x0c096534u: goto P_0c096534;
case 0x0c096536u: goto P_0c096536;
case 0x0c096538u: goto P_0c096538;
case 0x0c09653au: goto P_0c09653a;
case 0x0c09653cu: goto P_0c09653c;
case 0x0c09653eu: goto P_0c09653e;
case 0x0c096540u: goto P_0c096540;
case 0x0c096542u: goto P_0c096542;
case 0x0c096544u: goto P_0c096544;
case 0x0c096546u: goto P_0c096546;
case 0x0c096548u: goto P_0c096548;
case 0x0c09654au: goto P_0c09654a;
case 0x0c09654cu: goto P_0c09654c;
case 0x0c09654eu: goto P_0c09654e;
case 0x0c096550u: goto P_0c096550;
case 0x0c096552u: goto P_0c096552;
case 0x0c096554u: goto P_0c096554;
case 0x0c096556u: goto P_0c096556;
case 0x0c096558u: goto P_0c096558;
case 0x0c09655au: goto P_0c09655a;
case 0x0c09655cu: goto P_0c09655c;
case 0x0c09655eu: goto P_0c09655e;
case 0x0c096560u: goto P_0c096560;
case 0x0c096562u: goto P_0c096562;
case 0x0c096564u: goto P_0c096564;
case 0x0c096566u: goto P_0c096566;
case 0x0c096568u: goto P_0c096568;
case 0x0c09656au: goto P_0c09656a;
case 0x0c09656cu: goto P_0c09656c;
case 0x0c09656eu: goto P_0c09656e;
case 0x0c096570u: goto P_0c096570;
case 0x0c096572u: goto P_0c096572;
case 0x0c096574u: goto P_0c096574;
case 0x0c096576u: goto P_0c096576;
case 0x0c096578u: goto P_0c096578;
case 0x0c09657au: goto P_0c09657a;
case 0x0c09657cu: goto P_0c09657c;
case 0x0c09657eu: goto P_0c09657e;
case 0x0c096580u: goto P_0c096580;
case 0x0c096582u: goto P_0c096582;
case 0x0c096584u: goto P_0c096584;
case 0x0c096586u: goto P_0c096586;
case 0x0c096588u: goto P_0c096588;
case 0x0c09658au: goto P_0c09658a;
case 0x0c09658cu: goto P_0c09658c;
case 0x0c09658eu: goto P_0c09658e;
case 0x0c096590u: goto P_0c096590;
case 0x0c096592u: goto P_0c096592;
case 0x0c096594u: goto P_0c096594;
case 0x0c096596u: goto P_0c096596;
case 0x0c096598u: goto P_0c096598;
case 0x0c09659au: goto P_0c09659a;
case 0x0c09659cu: goto P_0c09659c;
case 0x0c09659eu: goto P_0c09659e;
case 0x0c0965a0u: goto P_0c0965a0;
case 0x0c0965a2u: goto P_0c0965a2;
case 0x0c0965a4u: goto P_0c0965a4;
case 0x0c0965a6u: goto P_0c0965a6;
case 0x0c0965a8u: goto P_0c0965a8;
case 0x0c0965aau: goto P_0c0965aa;
case 0x0c0965acu: goto P_0c0965ac;
case 0x0c0965aeu: goto P_0c0965ae;
case 0x0c0965b0u: goto P_0c0965b0;
case 0x0c0965b2u: goto P_0c0965b2;
case 0x0c0965b4u: goto P_0c0965b4;
case 0x0c0965b6u: goto P_0c0965b6;
case 0x0c0965b8u: goto P_0c0965b8;
case 0x0c0965bau: goto P_0c0965ba;
case 0x0c0965bcu: goto P_0c0965bc;
case 0x0c0965beu: goto P_0c0965be;
case 0x0c0965c0u: goto P_0c0965c0;
case 0x0c0965c2u: goto P_0c0965c2;
case 0x0c0965c4u: goto P_0c0965c4;
case 0x0c0965c6u: goto P_0c0965c6;
case 0x0c0965c8u: goto P_0c0965c8;
case 0x0c0965cau: goto P_0c0965ca;
case 0x0c0965ccu: goto P_0c0965cc;
case 0x0c0965ecu: goto P_0c0965ec;
case 0x0c0965eeu: goto P_0c0965ee;
case 0x0c0965f0u: goto P_0c0965f0;
case 0x0c0965f2u: goto P_0c0965f2;
case 0x0c0965f4u: goto P_0c0965f4;
case 0x0c0965f6u: goto P_0c0965f6;
case 0x0c0965f8u: goto P_0c0965f8;
case 0x0c0965fau: goto P_0c0965fa;
case 0x0c0965fcu: goto P_0c0965fc;
case 0x0c0965feu: goto P_0c0965fe;
case 0x0c096600u: goto P_0c096600;
case 0x0c096602u: goto P_0c096602;
case 0x0c096604u: goto P_0c096604;
case 0x0c096606u: goto P_0c096606;
case 0x0c096608u: goto P_0c096608;
case 0x0c09660au: goto P_0c09660a;
case 0x0c09660cu: goto P_0c09660c;
case 0x0c09660eu: goto P_0c09660e;
case 0x0c096610u: goto P_0c096610;
case 0x0c096612u: goto P_0c096612;
case 0x0c096614u: goto P_0c096614;
case 0x0c096616u: goto P_0c096616;
case 0x0c096618u: goto P_0c096618;
case 0x0c09661au: goto P_0c09661a;
case 0x0c09661cu: goto P_0c09661c;
case 0x0c09661eu: goto P_0c09661e;
case 0x0c096620u: goto P_0c096620;
case 0x0c096622u: goto P_0c096622;
case 0x0c096624u: goto P_0c096624;
case 0x0c096626u: goto P_0c096626;
case 0x0c096628u: goto P_0c096628;
case 0x0c09662au: goto P_0c09662a;
case 0x0c09662cu: goto P_0c09662c;
case 0x0c09662eu: goto P_0c09662e;
case 0x0c096630u: goto P_0c096630;
case 0x0c096632u: goto P_0c096632;
case 0x0c096634u: goto P_0c096634;
case 0x0c096636u: goto P_0c096636;
case 0x0c096638u: goto P_0c096638;
case 0x0c09663au: goto P_0c09663a;
case 0x0c09663cu: goto P_0c09663c;
case 0x0c09663eu: goto P_0c09663e;
case 0x0c096640u: goto P_0c096640;
case 0x0c096642u: goto P_0c096642;
case 0x0c096644u: goto P_0c096644;
case 0x0c096646u: goto P_0c096646;
case 0x0c096648u: goto P_0c096648;
case 0x0c09664au: goto P_0c09664a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c096342: /* original 2fe6, guest PC 0x0c096342 */
if(!s->budget--) { s->failed_pc=0x0c096342u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096344;
P_0c096344: /* original e300, guest PC 0x0c096344 */
if(!s->budget--) { s->failed_pc=0x0c096344u; return 0; }
r[3]=0x00000000u;
goto P_0c096346;
P_0c096346: /* original 2fd6, guest PC 0x0c096346 */
if(!s->budget--) { s->failed_pc=0x0c096346u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096348;
P_0c096348: /* original 6533, guest PC 0x0c096348 */
if(!s->budget--) { s->failed_pc=0x0c096348u; return 0; }
r[5]=r[3];
goto P_0c09634a;
P_0c09634a: /* original 2fc6, guest PC 0x0c09634a */
if(!s->budget--) { s->failed_pc=0x0c09634au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09634c;
P_0c09634c: /* original 2fb6, guest PC 0x0c09634c */
if(!s->budget--) { s->failed_pc=0x0c09634cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09634e;
P_0c09634e: /* original 2fa6, guest PC 0x0c09634e */
if(!s->budget--) { s->failed_pc=0x0c09634eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096350;
P_0c096350: /* original ea08, guest PC 0x0c096350 */
if(!s->budget--) { s->failed_pc=0x0c096350u; return 0; }
r[10]=0x00000008u;
goto P_0c096352;
P_0c096352: /* original 2f96, guest PC 0x0c096352 */
if(!s->budget--) { s->failed_pc=0x0c096352u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096354;
P_0c096354: /* original 2f86, guest PC 0x0c096354 */
if(!s->budget--) { s->failed_pc=0x0c096354u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096356;
P_0c096356: /* original d417, guest PC 0x0c096356 */
if(!s->budget--) { s->failed_pc=0x0c096356u; return 0; }
r[4]=read(ram,0x0c0963b4u,4);
goto P_0c096358;
P_0c096358: /* original 902a, guest PC 0x0c096358 */
if(!s->budget--) { s->failed_pc=0x0c096358u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0963b0u,2);
goto P_0c09635a;
P_0c09635a: /* original 4f22, guest PC 0x0c09635a */
if(!s->budget--) { s->failed_pc=0x0c09635au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09635c;
P_0c09635c: /* original dc16, guest PC 0x0c09635c */
if(!s->budget--) { s->failed_pc=0x0c09635cu; return 0; }
r[12]=read(ram,0x0c0963b8u,4);
goto P_0c09635e;
P_0c09635e: /* original de17, guest PC 0x0c09635e */
if(!s->budget--) { s->failed_pc=0x0c09635eu; return 0; }
r[14]=read(ram,0x0c0963bcu,4);
goto P_0c096360;
P_0c096360: /* original 0436, guest PC 0x0c096360 */
if(!s->budget--) { s->failed_pc=0x0c096360u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c096362;
P_0c096362: /* original 70fc, guest PC 0x0c096362 */
if(!s->budget--) { s->failed_pc=0x0c096362u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c096364;
P_0c096364: /* original 0436, guest PC 0x0c096364 */
if(!s->budget--) { s->failed_pc=0x0c096364u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c096366;
P_0c096366: /* original 70fc, guest PC 0x0c096366 */
if(!s->budget--) { s->failed_pc=0x0c096366u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c096368;
P_0c096368: /* original 0436, guest PC 0x0c096368 */
if(!s->budget--) { s->failed_pc=0x0c096368u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c09636a;
P_0c09636a: /* original 6433, guest PC 0x0c09636a */
if(!s->budget--) { s->failed_pc=0x0c09636au; return 0; }
r[4]=r[3];
goto P_0c09636c;
P_0c09636c: /* original d614, guest PC 0x0c09636c */
if(!s->budget--) { s->failed_pc=0x0c09636cu; return 0; }
r[6]=read(ram,0x0c0963c0u,4);
goto P_0c09636e;
P_0c09636e: /* original 7ffc, guest PC 0x0c09636e */
if(!s->budget--) { s->failed_pc=0x0c09636eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096370;
P_0c096370: /* original bf6a, guest PC 0x0c096370 */
if(!s->budget--) { s->failed_pc=0x0c096370u; return 0; }
target=code_base|0x0c096248u; r[16]=code_base|0x0c096374u;
r[13]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096374u) { target=s->pc; goto dispatch; }
goto P_0c096374;
P_0c096372: /* original ed01, guest PC 0x0c096372 */
if(!s->budget--) { s->failed_pc=0x0c096372u; return 0; }
r[13]=0x00000001u;
goto P_0c096374;
P_0c096374: /* original d613, guest PC 0x0c096374 */
if(!s->budget--) { s->failed_pc=0x0c096374u; return 0; }
r[6]=read(ram,0x0c0963c4u,4);
goto P_0c096376;
P_0c096376: /* original 65d3, guest PC 0x0c096376 */
if(!s->budget--) { s->failed_pc=0x0c096376u; return 0; }
r[5]=r[13];
goto P_0c096378;
P_0c096378: /* original bf66, guest PC 0x0c096378 */
if(!s->budget--) { s->failed_pc=0x0c096378u; return 0; }
target=code_base|0x0c096248u; r[16]=code_base|0x0c09637cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09637cu) { target=s->pc; goto dispatch; }
goto P_0c09637c;
P_0c09637a: /* original 64d3, guest PC 0x0c09637a */
if(!s->budget--) { s->failed_pc=0x0c09637au; return 0; }
r[4]=r[13];
goto P_0c09637c;
P_0c09637c: /* original 9b19, guest PC 0x0c09637c */
if(!s->budget--) { s->failed_pc=0x0c09637cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0963b2u,2);
goto P_0c09637e;
P_0c09637e: /* original d912, guest PC 0x0c09637e */
if(!s->budget--) { s->failed_pc=0x0c09637eu; return 0; }
r[9]=read(ram,0x0c0963c8u,4);
goto P_0c096380;
P_0c096380: /* original a059, guest PC 0x0c096380 */
if(!s->budget--) { s->failed_pc=0x0c096380u; return 0; }
r[8]=0x00000000u;
goto P_0c096436;
P_0c096382: /* original e800, guest PC 0x0c096382 */
if(!s->budget--) { s->failed_pc=0x0c096382u; return 0; }
r[8]=0x00000000u;
goto P_0c096384;
P_0c096384: /* original 4c0b, guest PC 0x0c096384 */
if(!s->budget--) { s->failed_pc=0x0c096384u; return 0; }
target=r[12];
r[16]=code_base|0x0c096388u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096388u) { target=s->pc; goto dispatch; }
goto P_0c096388;
P_0c096386: /* original 6483, guest PC 0x0c096386 */
if(!s->budget--) { s->failed_pc=0x0c096386u; return 0; }
r[4]=r[8];
goto P_0c096388;
P_0c096388: /* original 6403, guest PC 0x0c096388 */
if(!s->budget--) { s->failed_pc=0x0c096388u; return 0; }
r[4]=r[0];
goto P_0c09638a;
P_0c09638a: /* original 5244, guest PC 0x0c09638a */
if(!s->budget--) { s->failed_pc=0x0c09638au; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c09638c;
P_0c09638c: /* original 22b9, guest PC 0x0c09638c */
if(!s->budget--) { s->failed_pc=0x0c09638cu; return 0; }
r[2]&=r[11];
goto P_0c09638e;
P_0c09638e: /* original 32b0, guest PC 0x0c09638e */
if(!s->budget--) { s->failed_pc=0x0c09638eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c096390;
P_0c096390: /* original 8b50, guest PC 0x0c096390 */
if(!s->budget--) { s->failed_pc=0x0c096390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096434; }
goto P_0c096392;
P_0c096392: /* original 5242, guest PC 0x0c096392 */
if(!s->budget--) { s->failed_pc=0x0c096392u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c096394;
P_0c096394: /* original 22a8, guest PC 0x0c096394 */
if(!s->budget--) { s->failed_pc=0x0c096394u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c096396;
P_0c096396: /* original 894d, guest PC 0x0c096396 */
if(!s->budget--) { s->failed_pc=0x0c096396u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096434; }
goto P_0c096398;
P_0c096398: /* original d106, guest PC 0x0c096398 */
if(!s->budget--) { s->failed_pc=0x0c096398u; return 0; }
r[1]=read(ram,0x0c0963b4u,4);
goto P_0c09639a;
P_0c09639a: /* original d30c, guest PC 0x0c09639a */
if(!s->budget--) { s->failed_pc=0x0c09639au; return 0; }
r[3]=read(ram,0x0c0963ccu,4);
goto P_0c09639c;
P_0c09639c: /* original 6412, guest PC 0x0c09639c */
if(!s->budget--) { s->failed_pc=0x0c09639cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c09639e;
P_0c09639e: /* original 2348, guest PC 0x0c09639e */
if(!s->budget--) { s->failed_pc=0x0c09639eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0963a0;
P_0c0963a0: /* original 8916, guest PC 0x0c0963a0 */
if(!s->budget--) { s->failed_pc=0x0c0963a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0963d0; }
goto P_0c0963a2;
P_0c0963a2: /* original e500, guest PC 0x0c0963a2 */
if(!s->budget--) { s->failed_pc=0x0c0963a2u; return 0; }
r[5]=0x00000000u;
goto P_0c0963a4;
P_0c0963a4: /* original b25e, guest PC 0x0c0963a4 */
if(!s->budget--) { s->failed_pc=0x0c0963a4u; return 0; }
target=code_base|0x0c096864u; r[16]=code_base|0x0c0963a8u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0963a8u) { target=s->pc; goto dispatch; }
goto P_0c0963a8;
P_0c0963a6: /* original 6453, guest PC 0x0c0963a6 */
if(!s->budget--) { s->failed_pc=0x0c0963a6u; return 0; }
r[4]=r[5];
goto P_0c0963a8;
P_0c0963a8: /* original a044, guest PC 0x0c0963a8 */
if(!s->budget--) { s->failed_pc=0x0c0963a8u; return 0; }
goto P_0c096434;
P_0c0963aa: /* original 0009, guest PC 0x0c0963aa */
if(!s->budget--) { s->failed_pc=0x0c0963aau; return 0; }
if(!vf3_matrix_family(0x0c0963acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0963acu; return 0; } return 1;
P_0c0963d0: /* original d33d, guest PC 0x0c0963d0 */
if(!s->budget--) { s->failed_pc=0x0c0963d0u; return 0; }
r[3]=read(ram,0x0c0964c8u,4);
goto P_0c0963d2;
P_0c0963d2: /* original 2438, guest PC 0x0c0963d2 */
if(!s->budget--) { s->failed_pc=0x0c0963d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0963d4;
P_0c0963d4: /* original 8b2e, guest PC 0x0c0963d4 */
if(!s->budget--) { s->failed_pc=0x0c0963d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096434; }
goto P_0c0963d6;
P_0c0963d6: /* original d23d, guest PC 0x0c0963d6 */
if(!s->budget--) { s->failed_pc=0x0c0963d6u; return 0; }
r[2]=read(ram,0x0c0964ccu,4);
goto P_0c0963d8;
P_0c0963d8: /* original e600, guest PC 0x0c0963d8 */
if(!s->budget--) { s->failed_pc=0x0c0963d8u; return 0; }
r[6]=0x00000000u;
goto P_0c0963da;
P_0c0963da: /* original 6563, guest PC 0x0c0963da */
if(!s->budget--) { s->failed_pc=0x0c0963dau; return 0; }
r[5]=r[6];
goto P_0c0963dc;
P_0c0963dc: /* original 22d2, guest PC 0x0c0963dc */
if(!s->budget--) { s->failed_pc=0x0c0963dcu; return 0; }
write(ram,r[2],r[13],4);
goto P_0c0963de;
P_0c0963de: /* original d13c, guest PC 0x0c0963de */
if(!s->budget--) { s->failed_pc=0x0c0963deu; return 0; }
r[1]=read(ram,0x0c0964d0u,4);
goto P_0c0963e0;
P_0c0963e0: /* original 410b, guest PC 0x0c0963e0 */
if(!s->budget--) { s->failed_pc=0x0c0963e0u; return 0; }
target=r[1];
r[16]=code_base|0x0c0963e4u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0963e4u) { target=s->pc; goto dispatch; }
goto P_0c0963e4;
P_0c0963e2: /* original 6463, guest PC 0x0c0963e2 */
if(!s->budget--) { s->failed_pc=0x0c0963e2u; return 0; }
r[4]=r[6];
goto P_0c0963e4;
P_0c0963e4: /* original d33b, guest PC 0x0c0963e4 */
if(!s->budget--) { s->failed_pc=0x0c0963e4u; return 0; }
r[3]=read(ram,0x0c0964d4u,4);
goto P_0c0963e6;
P_0c0963e6: /* original 430b, guest PC 0x0c0963e6 */
if(!s->budget--) { s->failed_pc=0x0c0963e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0963eau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0963eau) { target=s->pc; goto dispatch; }
goto P_0c0963ea;
P_0c0963e8: /* original 0009, guest PC 0x0c0963e8 */
if(!s->budget--) { s->failed_pc=0x0c0963e8u; return 0; }
goto P_0c0963ea;
P_0c0963ea: /* original 0002, guest PC 0x0c0963ea */
if(!s->budget--) { s->failed_pc=0x0c0963eau; return 0; }
r[0]=r[17];
goto P_0c0963ec;
P_0c0963ec: /* original 926a, guest PC 0x0c0963ec */
if(!s->budget--) { s->failed_pc=0x0c0963ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0964c4u,2);
goto P_0c0963ee;
P_0c0963ee: /* original 2029, guest PC 0x0c0963ee */
if(!s->budget--) { s->failed_pc=0x0c0963eeu; return 0; }
r[0]&=r[2];
goto P_0c0963f0;
P_0c0963f0: /* original cbe0, guest PC 0x0c0963f0 */
if(!s->budget--) { s->failed_pc=0x0c0963f0u; return 0; }
r[0]|=224u;
goto P_0c0963f2;
P_0c0963f2: /* original 400e, guest PC 0x0c0963f2 */
if(!s->budget--) { s->failed_pc=0x0c0963f2u; return 0; }
r[17]=r[0];
goto P_0c0963f4;
P_0c0963f4: /* original d338, guest PC 0x0c0963f4 */
if(!s->budget--) { s->failed_pc=0x0c0963f4u; return 0; }
r[3]=read(ram,0x0c0964d8u,4);
goto P_0c0963f6;
P_0c0963f6: /* original 430b, guest PC 0x0c0963f6 */
if(!s->budget--) { s->failed_pc=0x0c0963f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0963fau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0963fau) { target=s->pc; goto dispatch; }
goto P_0c0963fa;
P_0c0963f8: /* original 0009, guest PC 0x0c0963f8 */
if(!s->budget--) { s->failed_pc=0x0c0963f8u; return 0; }
goto P_0c0963fa;
P_0c0963fa: /* original d138, guest PC 0x0c0963fa */
if(!s->budget--) { s->failed_pc=0x0c0963fau; return 0; }
r[1]=read(ram,0x0c0964dcu,4);
goto P_0c0963fc;
P_0c0963fc: /* original 410b, guest PC 0x0c0963fc */
if(!s->budget--) { s->failed_pc=0x0c0963fcu; return 0; }
target=r[1];
r[16]=code_base|0x0c096400u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096400u) { target=s->pc; goto dispatch; }
goto P_0c096400;
P_0c0963fe: /* original 0009, guest PC 0x0c0963fe */
if(!s->budget--) { s->failed_pc=0x0c0963feu; return 0; }
goto P_0c096400;
P_0c096400: /* original 0002, guest PC 0x0c096400 */
if(!s->budget--) { s->failed_pc=0x0c096400u; return 0; }
r[0]=r[17];
goto P_0c096402;
P_0c096402: /* original 935f, guest PC 0x0c096402 */
if(!s->budget--) { s->failed_pc=0x0c096402u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0964c4u,2);
goto P_0c096404;
P_0c096404: /* original 2039, guest PC 0x0c096404 */
if(!s->budget--) { s->failed_pc=0x0c096404u; return 0; }
r[0]&=r[3];
goto P_0c096406;
P_0c096406: /* original 400e, guest PC 0x0c096406 */
if(!s->budget--) { s->failed_pc=0x0c096406u; return 0; }
r[17]=r[0];
goto P_0c096408;
P_0c096408: /* original d235, guest PC 0x0c096408 */
if(!s->budget--) { s->failed_pc=0x0c096408u; return 0; }
r[2]=read(ram,0x0c0964e0u,4);
goto P_0c09640a;
P_0c09640a: /* original 420b, guest PC 0x0c09640a */
if(!s->budget--) { s->failed_pc=0x0c09640au; return 0; }
target=r[2];
r[16]=code_base|0x0c09640eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09640eu) { target=s->pc; goto dispatch; }
goto P_0c09640e;
P_0c09640c: /* original 0009, guest PC 0x0c09640c */
if(!s->budget--) { s->failed_pc=0x0c09640cu; return 0; }
goto P_0c09640e;
P_0c09640e: /* original d134, guest PC 0x0c09640e */
if(!s->budget--) { s->failed_pc=0x0c09640eu; return 0; }
r[1]=read(ram,0x0c0964e0u,4);
goto P_0c096410;
P_0c096410: /* original 410b, guest PC 0x0c096410 */
if(!s->budget--) { s->failed_pc=0x0c096410u; return 0; }
target=r[1];
r[16]=code_base|0x0c096414u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096414u) { target=s->pc; goto dispatch; }
goto P_0c096414;
P_0c096412: /* original 0009, guest PC 0x0c096412 */
if(!s->budget--) { s->failed_pc=0x0c096412u; return 0; }
goto P_0c096414;
P_0c096414: /* original d233, guest PC 0x0c096414 */
if(!s->budget--) { s->failed_pc=0x0c096414u; return 0; }
r[2]=read(ram,0x0c0964e4u,4);
goto P_0c096416;
P_0c096416: /* original 229b, guest PC 0x0c096416 */
if(!s->budget--) { s->failed_pc=0x0c096416u; return 0; }
r[2]|=r[9];
goto P_0c096418;
P_0c096418: /* original 420b, guest PC 0x0c096418 */
if(!s->budget--) { s->failed_pc=0x0c096418u; return 0; }
target=r[2];
r[16]=code_base|0x0c09641cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09641cu) { target=s->pc; goto dispatch; }
goto P_0c09641c;
P_0c09641a: /* original e400, guest PC 0x0c09641a */
if(!s->budget--) { s->failed_pc=0x0c09641au; return 0; }
r[4]=0x00000000u;
goto P_0c09641c;
P_0c09641c: /* original d332, guest PC 0x0c09641c */
if(!s->budget--) { s->failed_pc=0x0c09641cu; return 0; }
r[3]=read(ram,0x0c0964e8u,4);
goto P_0c09641e;
P_0c09641e: /* original 239b, guest PC 0x0c09641e */
if(!s->budget--) { s->failed_pc=0x0c09641eu; return 0; }
r[3]|=r[9];
goto P_0c096420;
P_0c096420: /* original 430b, guest PC 0x0c096420 */
if(!s->budget--) { s->failed_pc=0x0c096420u; return 0; }
target=r[3];
r[16]=code_base|0x0c096424u;
r[4]=0x0000003fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096424u) { target=s->pc; goto dispatch; }
goto P_0c096424;
P_0c096422: /* original e43f, guest PC 0x0c096422 */
if(!s->budget--) { s->failed_pc=0x0c096422u; return 0; }
r[4]=0x0000003fu;
goto P_0c096424;
P_0c096424: /* original 0002, guest PC 0x0c096424 */
if(!s->budget--) { s->failed_pc=0x0c096424u; return 0; }
r[0]=r[17];
goto P_0c096426;
P_0c096426: /* original 924d, guest PC 0x0c096426 */
if(!s->budget--) { s->failed_pc=0x0c096426u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0964c4u,2);
goto P_0c096428;
P_0c096428: /* original 2029, guest PC 0x0c096428 */
if(!s->budget--) { s->failed_pc=0x0c096428u; return 0; }
r[0]&=r[2];
goto P_0c09642a;
P_0c09642a: /* original cbe0, guest PC 0x0c09642a */
if(!s->budget--) { s->failed_pc=0x0c09642au; return 0; }
r[0]|=224u;
goto P_0c09642c;
P_0c09642c: /* original 400e, guest PC 0x0c09642c */
if(!s->budget--) { s->failed_pc=0x0c09642cu; return 0; }
r[17]=r[0];
goto P_0c09642e;
P_0c09642e: /* original d32f, guest PC 0x0c09642e */
if(!s->budget--) { s->failed_pc=0x0c09642eu; return 0; }
r[3]=read(ram,0x0c0964ecu,4);
goto P_0c096430;
P_0c096430: /* original 430b, guest PC 0x0c096430 */
if(!s->budget--) { s->failed_pc=0x0c096430u; return 0; }
target=r[3];
r[16]=code_base|0x0c096434u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096434u) { target=s->pc; goto dispatch; }
goto P_0c096434;
P_0c096432: /* original 0009, guest PC 0x0c096432 */
if(!s->budget--) { s->failed_pc=0x0c096432u; return 0; }
goto P_0c096434;
P_0c096434: /* original 7801, guest PC 0x0c096434 */
if(!s->budget--) { s->failed_pc=0x0c096434u; return 0; }
r[8]+=0x00000001u;
goto P_0c096436;
P_0c096436: /* original e202, guest PC 0x0c096436 */
if(!s->budget--) { s->failed_pc=0x0c096436u; return 0; }
r[2]=0x00000002u;
goto P_0c096438;
P_0c096438: /* original 3823, guest PC 0x0c096438 */
if(!s->budget--) { s->failed_pc=0x0c096438u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[2])!=0);
goto P_0c09643a;
P_0c09643a: /* original 8ba3, guest PC 0x0c09643a */
if(!s->budget--) { s->failed_pc=0x0c09643au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096384; }
goto P_0c09643c;
P_0c09643c: /* original d12c, guest PC 0x0c09643c */
if(!s->budget--) { s->failed_pc=0x0c09643cu; return 0; }
r[1]=read(ram,0x0c0964f0u,4);
goto P_0c09643e;
P_0c09643e: /* original 410b, guest PC 0x0c09643e */
if(!s->budget--) { s->failed_pc=0x0c09643eu; return 0; }
target=r[1];
r[16]=code_base|0x0c096442u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096442u) { target=s->pc; goto dispatch; }
goto P_0c096442;
P_0c096440: /* original 0009, guest PC 0x0c096440 */
if(!s->budget--) { s->failed_pc=0x0c096440u; return 0; }
goto P_0c096442;
P_0c096442: /* original 8806, guest PC 0x0c096442 */
if(!s->budget--) { s->failed_pc=0x0c096442u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c096444;
P_0c096444: /* original 8f03, guest PC 0x0c096444 */
if(!s->budget--) { s->failed_pc=0x0c096444u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c09644e; }
goto P_0c096448;
P_0c096446: /* original 6403, guest PC 0x0c096446 */
if(!s->budget--) { s->failed_pc=0x0c096446u; return 0; }
r[4]=r[0];
goto P_0c096448;
P_0c096448: /* original e500, guest PC 0x0c096448 */
if(!s->budget--) { s->failed_pc=0x0c096448u; return 0; }
r[5]=0x00000000u;
goto P_0c09644a;
P_0c09644a: /* original b20b, guest PC 0x0c09644a */
if(!s->budget--) { s->failed_pc=0x0c09644au; return 0; }
target=code_base|0x0c096864u; r[16]=code_base|0x0c09644eu;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09644eu) { target=s->pc; goto dispatch; }
goto P_0c09644e;
P_0c09644c: /* original 6453, guest PC 0x0c09644c */
if(!s->budget--) { s->failed_pc=0x0c09644cu; return 0; }
r[4]=r[5];
goto P_0c09644e;
P_0c09644e: /* original d429, guest PC 0x0c09644e */
if(!s->budget--) { s->failed_pc=0x0c09644eu; return 0; }
r[4]=read(ram,0x0c0964f4u,4);
goto P_0c096450;
P_0c096450: /* original d32b, guest PC 0x0c096450 */
if(!s->budget--) { s->failed_pc=0x0c096450u; return 0; }
r[3]=read(ram,0x0c096500u,4);
goto P_0c096452;
P_0c096452: /* original 6242, guest PC 0x0c096452 */
if(!s->budget--) { s->failed_pc=0x0c096452u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c096454;
P_0c096454: /* original db28, guest PC 0x0c096454 */
if(!s->budget--) { s->failed_pc=0x0c096454u; return 0; }
r[11]=read(ram,0x0c0964f8u,4);
goto P_0c096456;
P_0c096456: /* original d529, guest PC 0x0c096456 */
if(!s->budget--) { s->failed_pc=0x0c096456u; return 0; }
r[5]=read(ram,0x0c0964fcu,4);
goto P_0c096458;
P_0c096458: /* original 2238, guest PC 0x0c096458 */
if(!s->budget--) { s->failed_pc=0x0c096458u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09645a;
P_0c09645a: /* original 8b01, guest PC 0x0c09645a */
if(!s->budget--) { s->failed_pc=0x0c09645au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096460; }
goto P_0c09645c;
P_0c09645c: /* original a0d4, guest PC 0x0c09645c */
if(!s->budget--) { s->failed_pc=0x0c09645cu; return 0; }
goto P_0c096608;
P_0c09645e: /* original 0009, guest PC 0x0c09645e */
if(!s->budget--) { s->failed_pc=0x0c09645eu; return 0; }
goto P_0c096460;
P_0c096460: /* original 5141, guest PC 0x0c096460 */
if(!s->budget--) { s->failed_pc=0x0c096460u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c096462;
P_0c096462: /* original d228, guest PC 0x0c096462 */
if(!s->budget--) { s->failed_pc=0x0c096462u; return 0; }
r[2]=read(ram,0x0c096504u,4);
goto P_0c096464;
P_0c096464: /* original 2128, guest PC 0x0c096464 */
if(!s->budget--) { s->failed_pc=0x0c096464u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c096466;
P_0c096466: /* original 8b01, guest PC 0x0c096466 */
if(!s->budget--) { s->failed_pc=0x0c096466u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09646c; }
goto P_0c096468;
P_0c096468: /* original a0c7, guest PC 0x0c096468 */
if(!s->budget--) { s->failed_pc=0x0c096468u; return 0; }
goto P_0c0965fa;
P_0c09646a: /* original 0009, guest PC 0x0c09646a */
if(!s->budget--) { s->failed_pc=0x0c09646au; return 0; }
goto P_0c09646c;
P_0c09646c: /* original e800, guest PC 0x0c09646c */
if(!s->budget--) { s->failed_pc=0x0c09646cu; return 0; }
r[8]=0x00000000u;
goto P_0c09646e;
P_0c09646e: /* original 6183, guest PC 0x0c09646e */
if(!s->budget--) { s->failed_pc=0x0c09646eu; return 0; }
r[1]=r[8];
goto P_0c096470;
P_0c096470: /* original 6913, guest PC 0x0c096470 */
if(!s->budget--) { s->failed_pc=0x0c096470u; return 0; }
r[9]=r[1];
goto P_0c096472;
P_0c096472: /* original 2f12, guest PC 0x0c096472 */
if(!s->budget--) { s->failed_pc=0x0c096472u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c096474;
P_0c096474: /* original 50b2, guest PC 0x0c096474 */
if(!s->budget--) { s->failed_pc=0x0c096474u; return 0; }
r[0]=read(ram,r[11]+8,4);
goto P_0c096476;
P_0c096476: /* original d124, guest PC 0x0c096476 */
if(!s->budget--) { s->failed_pc=0x0c096476u; return 0; }
r[1]=read(ram,0x0c096508u,4);
goto P_0c096478;
P_0c096478: /* original 2018, guest PC 0x0c096478 */
if(!s->budget--) { s->failed_pc=0x0c096478u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c09647a;
P_0c09647a: /* original 8904, guest PC 0x0c09647a */
if(!s->budget--) { s->failed_pc=0x0c09647au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096486; }
goto P_0c09647c;
P_0c09647c: /* original e029, guest PC 0x0c09647c */
if(!s->budget--) { s->failed_pc=0x0c09647cu; return 0; }
r[0]=0x00000029u;
goto P_0c09647e;
P_0c09647e: /* original 00bc, guest PC 0x0c09647e */
if(!s->budget--) { s->failed_pc=0x0c09647eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c096480;
P_0c096480: /* original 600c, guest PC 0x0c096480 */
if(!s->budget--) { s->failed_pc=0x0c096480u; return 0; }
r[0]=r[0]&255u;
goto P_0c096482;
P_0c096482: /* original 8802, guest PC 0x0c096482 */
if(!s->budget--) { s->failed_pc=0x0c096482u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c096484;
P_0c096484: /* original 8903, guest PC 0x0c096484 */
if(!s->budget--) { s->failed_pc=0x0c096484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09648e; }
goto P_0c096486;
P_0c096486: /* original 4c0b, guest PC 0x0c096486 */
if(!s->budget--) { s->failed_pc=0x0c096486u; return 0; }
target=r[12];
r[16]=code_base|0x0c09648au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09648au) { target=s->pc; goto dispatch; }
goto P_0c09648a;
P_0c096488: /* original e400, guest PC 0x0c096488 */
if(!s->budget--) { s->failed_pc=0x0c096488u; return 0; }
r[4]=0x00000000u;
goto P_0c09648a;
P_0c09648a: /* original 6403, guest PC 0x0c09648a */
if(!s->budget--) { s->failed_pc=0x0c09648au; return 0; }
r[4]=r[0];
goto P_0c09648c;
P_0c09648c: /* original 5842, guest PC 0x0c09648c */
if(!s->budget--) { s->failed_pc=0x0c09648cu; return 0; }
r[8]=read(ram,r[4]+8,4);
goto P_0c09648e;
P_0c09648e: /* original 52b2, guest PC 0x0c09648e */
if(!s->budget--) { s->failed_pc=0x0c09648eu; return 0; }
r[2]=read(ram,r[11]+8,4);
goto P_0c096490;
P_0c096490: /* original d31d, guest PC 0x0c096490 */
if(!s->budget--) { s->failed_pc=0x0c096490u; return 0; }
r[3]=read(ram,0x0c096508u,4);
goto P_0c096492;
P_0c096492: /* original 2238, guest PC 0x0c096492 */
if(!s->budget--) { s->failed_pc=0x0c096492u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c096494;
P_0c096494: /* original 8904, guest PC 0x0c096494 */
if(!s->budget--) { s->failed_pc=0x0c096494u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0964a0; }
goto P_0c096496;
P_0c096496: /* original e029, guest PC 0x0c096496 */
if(!s->budget--) { s->failed_pc=0x0c096496u; return 0; }
r[0]=0x00000029u;
goto P_0c096498;
P_0c096498: /* original 00bc, guest PC 0x0c096498 */
if(!s->budget--) { s->failed_pc=0x0c096498u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c09649a;
P_0c09649a: /* original 600c, guest PC 0x0c09649a */
if(!s->budget--) { s->failed_pc=0x0c09649au; return 0; }
r[0]=r[0]&255u;
goto P_0c09649c;
P_0c09649c: /* original 8801, guest PC 0x0c09649c */
if(!s->budget--) { s->failed_pc=0x0c09649cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09649e;
P_0c09649e: /* original 8904, guest PC 0x0c09649e */
if(!s->budget--) { s->failed_pc=0x0c09649eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0964aa; }
goto P_0c0964a0;
P_0c0964a0: /* original 4c0b, guest PC 0x0c0964a0 */
if(!s->budget--) { s->failed_pc=0x0c0964a0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0964a4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0964a4u) { target=s->pc; goto dispatch; }
goto P_0c0964a4;
P_0c0964a2: /* original e401, guest PC 0x0c0964a2 */
if(!s->budget--) { s->failed_pc=0x0c0964a2u; return 0; }
r[4]=0x00000001u;
goto P_0c0964a4;
P_0c0964a4: /* original 6403, guest PC 0x0c0964a4 */
if(!s->budget--) { s->failed_pc=0x0c0964a4u; return 0; }
r[4]=r[0];
goto P_0c0964a6;
P_0c0964a6: /* original 5342, guest PC 0x0c0964a6 */
if(!s->budget--) { s->failed_pc=0x0c0964a6u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0964a8;
P_0c0964a8: /* original 2f32, guest PC 0x0c0964a8 */
if(!s->budget--) { s->failed_pc=0x0c0964a8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0964aa;
P_0c0964aa: /* original e029, guest PC 0x0c0964aa */
if(!s->budget--) { s->failed_pc=0x0c0964aau; return 0; }
r[0]=0x00000029u;
goto P_0c0964ac;
P_0c0964ac: /* original 00bc, guest PC 0x0c0964ac */
if(!s->budget--) { s->failed_pc=0x0c0964acu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0964ae;
P_0c0964ae: /* original 600c, guest PC 0x0c0964ae */
if(!s->budget--) { s->failed_pc=0x0c0964aeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0964b0;
P_0c0964b0: /* original 8801, guest PC 0x0c0964b0 */
if(!s->budget--) { s->failed_pc=0x0c0964b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0964b2;
P_0c0964b2: /* original 8b2b, guest PC 0x0c0964b2 */
if(!s->budget--) { s->failed_pc=0x0c0964b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09650c; }
goto P_0c0964b4;
P_0c0964b4: /* original 4c0b, guest PC 0x0c0964b4 */
if(!s->budget--) { s->failed_pc=0x0c0964b4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0964b8u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0964b8u) { target=s->pc; goto dispatch; }
goto P_0c0964b8;
P_0c0964b6: /* original e400, guest PC 0x0c0964b6 */
if(!s->budget--) { s->failed_pc=0x0c0964b6u; return 0; }
r[4]=0x00000000u;
goto P_0c0964b8;
P_0c0964b8: /* original 6403, guest PC 0x0c0964b8 */
if(!s->budget--) { s->failed_pc=0x0c0964b8u; return 0; }
r[4]=r[0];
goto P_0c0964ba;
P_0c0964ba: /* original 6042, guest PC 0x0c0964ba */
if(!s->budget--) { s->failed_pc=0x0c0964bau; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0964bc;
P_0c0964bc: /* original 88fe, guest PC 0x0c0964bc */
if(!s->budget--) { s->failed_pc=0x0c0964bcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c0964be;
P_0c0964be: /* original 892d, guest PC 0x0c0964be */
if(!s->budget--) { s->failed_pc=0x0c0964beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09651c; }
goto P_0c0964c0;
P_0c0964c0: /* original a03d, guest PC 0x0c0964c0 */
if(!s->budget--) { s->failed_pc=0x0c0964c0u; return 0; }
goto P_0c09653e;
P_0c0964c2: /* original 0009, guest PC 0x0c0964c2 */
if(!s->budget--) { s->failed_pc=0x0c0964c2u; return 0; }
if(!vf3_matrix_family(0x0c0964c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0964c4u; return 0; } return 1;
P_0c09650c: /* original 8802, guest PC 0x0c09650c */
if(!s->budget--) { s->failed_pc=0x0c09650cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09650e;
P_0c09650e: /* original 8b07, guest PC 0x0c09650e */
if(!s->budget--) { s->failed_pc=0x0c09650eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096520; }
goto P_0c096510;
P_0c096510: /* original 4c0b, guest PC 0x0c096510 */
if(!s->budget--) { s->failed_pc=0x0c096510u; return 0; }
target=r[12];
r[16]=code_base|0x0c096514u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096514u) { target=s->pc; goto dispatch; }
goto P_0c096514;
P_0c096512: /* original e401, guest PC 0x0c096512 */
if(!s->budget--) { s->failed_pc=0x0c096512u; return 0; }
r[4]=0x00000001u;
goto P_0c096514;
P_0c096514: /* original 6403, guest PC 0x0c096514 */
if(!s->budget--) { s->failed_pc=0x0c096514u; return 0; }
r[4]=r[0];
goto P_0c096516;
P_0c096516: /* original 6042, guest PC 0x0c096516 */
if(!s->budget--) { s->failed_pc=0x0c096516u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096518;
P_0c096518: /* original 88fe, guest PC 0x0c096518 */
if(!s->budget--) { s->failed_pc=0x0c096518u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09651a;
P_0c09651a: /* original 8b10, guest PC 0x0c09651a */
if(!s->budget--) { s->failed_pc=0x0c09651au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09653e; }
goto P_0c09651c;
P_0c09651c: /* original a00f, guest PC 0x0c09651c */
if(!s->budget--) { s->failed_pc=0x0c09651cu; return 0; }
r[9]=r[13];
goto P_0c09653e;
P_0c09651e: /* original 69d3, guest PC 0x0c09651e */
if(!s->budget--) { s->failed_pc=0x0c09651eu; return 0; }
r[9]=r[13];
goto P_0c096520;
P_0c096520: /* original 4c0b, guest PC 0x0c096520 */
if(!s->budget--) { s->failed_pc=0x0c096520u; return 0; }
target=r[12];
r[16]=code_base|0x0c096524u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096524u) { target=s->pc; goto dispatch; }
goto P_0c096524;
P_0c096522: /* original e400, guest PC 0x0c096522 */
if(!s->budget--) { s->failed_pc=0x0c096522u; return 0; }
r[4]=0x00000000u;
goto P_0c096524;
P_0c096524: /* original 6403, guest PC 0x0c096524 */
if(!s->budget--) { s->failed_pc=0x0c096524u; return 0; }
r[4]=r[0];
goto P_0c096526;
P_0c096526: /* original 6042, guest PC 0x0c096526 */
if(!s->budget--) { s->failed_pc=0x0c096526u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096528;
P_0c096528: /* original 88fe, guest PC 0x0c096528 */
if(!s->budget--) { s->failed_pc=0x0c096528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09652a;
P_0c09652a: /* original 8f01, guest PC 0x0c09652a */
if(!s->budget--) { s->failed_pc=0x0c09652au; return 0; }
cond=r[17]&1u;
r[4]=0x00000001u;
if(!cond) { goto P_0c096530; }
goto P_0c09652e;
P_0c09652c: /* original e401, guest PC 0x0c09652c */
if(!s->budget--) { s->failed_pc=0x0c09652cu; return 0; }
r[4]=0x00000001u;
goto P_0c09652e;
P_0c09652e: /* original 69d3, guest PC 0x0c09652e */
if(!s->budget--) { s->failed_pc=0x0c09652eu; return 0; }
r[9]=r[13];
goto P_0c096530;
P_0c096530: /* original 4c0b, guest PC 0x0c096530 */
if(!s->budget--) { s->failed_pc=0x0c096530u; return 0; }
target=r[12];
r[16]=code_base|0x0c096534u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096534u) { target=s->pc; goto dispatch; }
goto P_0c096534;
P_0c096532: /* original 0009, guest PC 0x0c096532 */
if(!s->budget--) { s->failed_pc=0x0c096532u; return 0; }
goto P_0c096534;
P_0c096534: /* original 6403, guest PC 0x0c096534 */
if(!s->budget--) { s->failed_pc=0x0c096534u; return 0; }
r[4]=r[0];
goto P_0c096536;
P_0c096536: /* original 6042, guest PC 0x0c096536 */
if(!s->budget--) { s->failed_pc=0x0c096536u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096538;
P_0c096538: /* original 88fe, guest PC 0x0c096538 */
if(!s->budget--) { s->failed_pc=0x0c096538u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09653a;
P_0c09653a: /* original 8b00, guest PC 0x0c09653a */
if(!s->budget--) { s->failed_pc=0x0c09653au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09653e; }
goto P_0c09653c;
P_0c09653c: /* original 29db, guest PC 0x0c09653c */
if(!s->budget--) { s->failed_pc=0x0c09653cu; return 0; }
r[9]|=r[13];
goto P_0c09653e;
P_0c09653e: /* original 64e2, guest PC 0x0c09653e */
if(!s->budget--) { s->failed_pc=0x0c09653eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c096540;
P_0c096540: /* original 2998, guest PC 0x0c096540 */
if(!s->budget--) { s->failed_pc=0x0c096540u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c096542;
P_0c096542: /* original d523, guest PC 0x0c096542 */
if(!s->budget--) { s->failed_pc=0x0c096542u; return 0; }
r[5]=read(ram,0x0c0965d0u,4);
goto P_0c096544;
P_0c096544: /* original 8d06, guest PC 0x0c096544 */
if(!s->budget--) { s->failed_pc=0x0c096544u; return 0; }
cond=r[17]&1u;
r[4]&=r[5];
if(cond) { goto P_0c096554; }
goto P_0c096548;
P_0c096546: /* original 2459, guest PC 0x0c096546 */
if(!s->budget--) { s->failed_pc=0x0c096546u; return 0; }
r[4]&=r[5];
goto P_0c096548;
P_0c096548: /* original 2448, guest PC 0x0c096548 */
if(!s->budget--) { s->failed_pc=0x0c096548u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c09654a;
P_0c09654a: /* original 8b6a, guest PC 0x0c09654a */
if(!s->budget--) { s->failed_pc=0x0c09654au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096622; }
goto P_0c09654c;
P_0c09654c: /* original 63e2, guest PC 0x0c09654c */
if(!s->budget--) { s->failed_pc=0x0c09654cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c09654e;
P_0c09654e: /* original 235b, guest PC 0x0c09654e */
if(!s->budget--) { s->failed_pc=0x0c09654eu; return 0; }
r[3]|=r[5];
goto P_0c096550;
P_0c096550: /* original a037, guest PC 0x0c096550 */
if(!s->budget--) { s->failed_pc=0x0c096550u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0965c2;
P_0c096552: /* original 2e32, guest PC 0x0c096552 */
if(!s->budget--) { s->failed_pc=0x0c096552u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c096554;
P_0c096554: /* original 2448, guest PC 0x0c096554 */
if(!s->budget--) { s->failed_pc=0x0c096554u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c096556;
P_0c096556: /* original 8904, guest PC 0x0c096556 */
if(!s->budget--) { s->failed_pc=0x0c096556u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096562; }
goto P_0c096558;
P_0c096558: /* original 62e2, guest PC 0x0c096558 */
if(!s->budget--) { s->failed_pc=0x0c096558u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09655a;
P_0c09655a: /* original d31e, guest PC 0x0c09655a */
if(!s->budget--) { s->failed_pc=0x0c09655au; return 0; }
r[3]=read(ram,0x0c0965d4u,4);
goto P_0c09655c;
P_0c09655c: /* original 2239, guest PC 0x0c09655c */
if(!s->budget--) { s->failed_pc=0x0c09655cu; return 0; }
r[2]&=r[3];
goto P_0c09655e;
P_0c09655e: /* original a030, guest PC 0x0c09655e */
if(!s->budget--) { s->failed_pc=0x0c09655eu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965c2;
P_0c096560: /* original 2e22, guest PC 0x0c096560 */
if(!s->budget--) { s->failed_pc=0x0c096560u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c096562;
P_0c096562: /* original 60f2, guest PC 0x0c096562 */
if(!s->budget--) { s->failed_pc=0x0c096562u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c096564;
P_0c096564: /* original 208b, guest PC 0x0c096564 */
if(!s->budget--) { s->failed_pc=0x0c096564u; return 0; }
r[0]|=r[8];
goto P_0c096566;
P_0c096566: /* original 20a8, guest PC 0x0c096566 */
if(!s->budget--) { s->failed_pc=0x0c096566u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[10])==0)!=0);
goto P_0c096568;
P_0c096568: /* original 895b, guest PC 0x0c096568 */
if(!s->budget--) { s->failed_pc=0x0c096568u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c09656a;
P_0c09656a: /* original 62e2, guest PC 0x0c09656a */
if(!s->budget--) { s->failed_pc=0x0c09656au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09656c;
P_0c09656c: /* original 6483, guest PC 0x0c09656c */
if(!s->budget--) { s->failed_pc=0x0c09656cu; return 0; }
r[4]=r[8];
goto P_0c09656e;
P_0c09656e: /* original 22d8, guest PC 0x0c09656e */
if(!s->budget--) { s->failed_pc=0x0c09656eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c096570;
P_0c096570: /* original 8d19, guest PC 0x0c096570 */
if(!s->budget--) { s->failed_pc=0x0c096570u; return 0; }
cond=r[17]&1u;
r[4]&=r[10];
if(cond) { goto P_0c0965a6; }
goto P_0c096574;
P_0c096572: /* original 24a9, guest PC 0x0c096572 */
if(!s->budget--) { s->failed_pc=0x0c096572u; return 0; }
r[4]&=r[10];
goto P_0c096574;
P_0c096574: /* original 2448, guest PC 0x0c096574 */
if(!s->budget--) { s->failed_pc=0x0c096574u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c096576;
P_0c096576: /* original 8909, guest PC 0x0c096576 */
if(!s->budget--) { s->failed_pc=0x0c096576u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09658c; }
goto P_0c096578;
P_0c096578: /* original d018, guest PC 0x0c096578 */
if(!s->budget--) { s->failed_pc=0x0c096578u; return 0; }
r[0]=read(ram,0x0c0965dcu,4);
goto P_0c09657a;
P_0c09657a: /* original d317, guest PC 0x0c09657a */
if(!s->budget--) { s->failed_pc=0x0c09657au; return 0; }
r[3]=read(ram,0x0c0965d8u,4);
goto P_0c09657c;
P_0c09657c: /* original 6102, guest PC 0x0c09657c */
if(!s->budget--) { s->failed_pc=0x0c09657cu; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c09657e;
P_0c09657e: /* original 2138, guest PC 0x0c09657e */
if(!s->budget--) { s->failed_pc=0x0c09657eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c096580;
P_0c096580: /* original 8904, guest PC 0x0c096580 */
if(!s->budget--) { s->failed_pc=0x0c096580u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09658c; }
goto P_0c096582;
P_0c096582: /* original 62e2, guest PC 0x0c096582 */
if(!s->budget--) { s->failed_pc=0x0c096582u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c096584;
P_0c096584: /* original d316, guest PC 0x0c096584 */
if(!s->budget--) { s->failed_pc=0x0c096584u; return 0; }
r[3]=read(ram,0x0c0965e0u,4);
goto P_0c096586;
P_0c096586: /* original 223a, guest PC 0x0c096586 */
if(!s->budget--) { s->failed_pc=0x0c096586u; return 0; }
r[2]^=r[3];
goto P_0c096588;
P_0c096588: /* original a01b, guest PC 0x0c096588 */
if(!s->budget--) { s->failed_pc=0x0c096588u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965c2;
P_0c09658a: /* original 2e22, guest PC 0x0c09658a */
if(!s->budget--) { s->failed_pc=0x0c09658au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c09658c;
P_0c09658c: /* original 61f2, guest PC 0x0c09658c */
if(!s->budget--) { s->failed_pc=0x0c09658cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c09658e;
P_0c09658e: /* original 21a8, guest PC 0x0c09658e */
if(!s->budget--) { s->failed_pc=0x0c09658eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[10])==0)!=0);
goto P_0c096590;
P_0c096590: /* original 8947, guest PC 0x0c096590 */
if(!s->budget--) { s->failed_pc=0x0c096590u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c096592;
P_0c096592: /* original d112, guest PC 0x0c096592 */
if(!s->budget--) { s->failed_pc=0x0c096592u; return 0; }
r[1]=read(ram,0x0c0965dcu,4);
goto P_0c096594;
P_0c096594: /* original d313, guest PC 0x0c096594 */
if(!s->budget--) { s->failed_pc=0x0c096594u; return 0; }
r[3]=read(ram,0x0c0965e4u,4);
goto P_0c096596;
P_0c096596: /* original 6212, guest PC 0x0c096596 */
if(!s->budget--) { s->failed_pc=0x0c096596u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c096598;
P_0c096598: /* original 2238, guest PC 0x0c096598 */
if(!s->budget--) { s->failed_pc=0x0c096598u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09659a;
P_0c09659a: /* original 8942, guest PC 0x0c09659a */
if(!s->budget--) { s->failed_pc=0x0c09659au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c09659c;
P_0c09659c: /* original 60e2, guest PC 0x0c09659c */
if(!s->budget--) { s->failed_pc=0x0c09659cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c09659e;
P_0c09659e: /* original d312, guest PC 0x0c09659e */
if(!s->budget--) { s->failed_pc=0x0c09659eu; return 0; }
r[3]=read(ram,0x0c0965e8u,4);
goto P_0c0965a0;
P_0c0965a0: /* original 203a, guest PC 0x0c0965a0 */
if(!s->budget--) { s->failed_pc=0x0c0965a0u; return 0; }
r[0]^=r[3];
goto P_0c0965a2;
P_0c0965a2: /* original a00e, guest PC 0x0c0965a2 */
if(!s->budget--) { s->failed_pc=0x0c0965a2u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0965c2;
P_0c0965a4: /* original 2e02, guest PC 0x0c0965a4 */
if(!s->budget--) { s->failed_pc=0x0c0965a4u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0965a6;
P_0c0965a6: /* original 61e2, guest PC 0x0c0965a6 */
if(!s->budget--) { s->failed_pc=0x0c0965a6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0965a8;
P_0c0965a8: /* original 2448, guest PC 0x0c0965a8 */
if(!s->budget--) { s->failed_pc=0x0c0965a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0965aa;
P_0c0965aa: /* original 21da, guest PC 0x0c0965aa */
if(!s->budget--) { s->failed_pc=0x0c0965aau; return 0; }
r[1]^=r[13];
goto P_0c0965ac;
P_0c0965ac: /* original 8d05, guest PC 0x0c0965ac */
if(!s->budget--) { s->failed_pc=0x0c0965acu; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[1],4);
if(cond) { goto P_0c0965ba; }
goto P_0c0965b0;
P_0c0965ae: /* original 2e12, guest PC 0x0c0965ae */
if(!s->budget--) { s->failed_pc=0x0c0965aeu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0965b0;
P_0c0965b0: /* original 62e2, guest PC 0x0c0965b0 */
if(!s->budget--) { s->failed_pc=0x0c0965b0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0965b2;
P_0c0965b2: /* original d309, guest PC 0x0c0965b2 */
if(!s->budget--) { s->failed_pc=0x0c0965b2u; return 0; }
r[3]=read(ram,0x0c0965d8u,4);
goto P_0c0965b4;
P_0c0965b4: /* original 223b, guest PC 0x0c0965b4 */
if(!s->budget--) { s->failed_pc=0x0c0965b4u; return 0; }
r[2]|=r[3];
goto P_0c0965b6;
P_0c0965b6: /* original a004, guest PC 0x0c0965b6 */
if(!s->budget--) { s->failed_pc=0x0c0965b6u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965c2;
P_0c0965b8: /* original 2e22, guest PC 0x0c0965b8 */
if(!s->budget--) { s->failed_pc=0x0c0965b8u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965ba;
P_0c0965ba: /* original 61e2, guest PC 0x0c0965ba */
if(!s->budget--) { s->failed_pc=0x0c0965bau; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0965bc;
P_0c0965bc: /* original d309, guest PC 0x0c0965bc */
if(!s->budget--) { s->failed_pc=0x0c0965bcu; return 0; }
r[3]=read(ram,0x0c0965e4u,4);
goto P_0c0965be;
P_0c0965be: /* original 213b, guest PC 0x0c0965be */
if(!s->budget--) { s->failed_pc=0x0c0965beu; return 0; }
r[1]|=r[3];
goto P_0c0965c0;
P_0c0965c0: /* original 2e12, guest PC 0x0c0965c0 */
if(!s->budget--) { s->failed_pc=0x0c0965c0u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0965c2;
P_0c0965c2: /* original 62e2, guest PC 0x0c0965c2 */
if(!s->budget--) { s->failed_pc=0x0c0965c2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0965c4;
P_0c0965c4: /* original 22d8, guest PC 0x0c0965c4 */
if(!s->budget--) { s->failed_pc=0x0c0965c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0965c6;
P_0c0965c6: /* original 8911, guest PC 0x0c0965c6 */
if(!s->budget--) { s->failed_pc=0x0c0965c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0965ec; }
goto P_0c0965c8;
P_0c0965c8: /* original 9401, guest PC 0x0c0965c8 */
if(!s->budget--) { s->failed_pc=0x0c0965c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0965ceu,2);
goto P_0c0965ca;
P_0c0965ca: /* original a011, guest PC 0x0c0965ca */
if(!s->budget--) { s->failed_pc=0x0c0965cau; return 0; }
r[5]=0x00000000u;
goto P_0c0965f0;
P_0c0965cc: /* original e500, guest PC 0x0c0965cc */
if(!s->budget--) { s->failed_pc=0x0c0965ccu; return 0; }
r[5]=0x00000000u;
if(!vf3_matrix_family(0x0c0965ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0965ceu; return 0; } return 1;
P_0c0965ec: /* original 947c, guest PC 0x0c0965ec */
if(!s->budget--) { s->failed_pc=0x0c0965ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966e8u,2);
goto P_0c0965ee;
P_0c0965ee: /* original e500, guest PC 0x0c0965ee */
if(!s->budget--) { s->failed_pc=0x0c0965eeu; return 0; }
r[5]=0x00000000u;
goto P_0c0965f0;
P_0c0965f0: /* original d23f, guest PC 0x0c0965f0 */
if(!s->budget--) { s->failed_pc=0x0c0965f0u; return 0; }
r[2]=read(ram,0x0c0966f0u,4);
goto P_0c0965f2;
P_0c0965f2: /* original 420b, guest PC 0x0c0965f2 */
if(!s->budget--) { s->failed_pc=0x0c0965f2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0965f6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0965f6u) { target=s->pc; goto dispatch; }
goto P_0c0965f6;
P_0c0965f4: /* original 0009, guest PC 0x0c0965f4 */
if(!s->budget--) { s->failed_pc=0x0c0965f4u; return 0; }
goto P_0c0965f6;
P_0c0965f6: /* original a014, guest PC 0x0c0965f6 */
if(!s->budget--) { s->failed_pc=0x0c0965f6u; return 0; }
goto P_0c096622;
P_0c0965f8: /* original 0009, guest PC 0x0c0965f8 */
if(!s->budget--) { s->failed_pc=0x0c0965f8u; return 0; }
goto P_0c0965fa;
P_0c0965fa: /* original 2518, guest PC 0x0c0965fa */
if(!s->budget--) { s->failed_pc=0x0c0965fau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0965fc;
P_0c0965fc: /* original 8911, guest PC 0x0c0965fc */
if(!s->budget--) { s->failed_pc=0x0c0965fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c0965fe;
P_0c0965fe: /* original 61e2, guest PC 0x0c0965fe */
if(!s->budget--) { s->failed_pc=0x0c0965feu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c096600;
P_0c096600: /* original 21d8, guest PC 0x0c096600 */
if(!s->budget--) { s->failed_pc=0x0c096600u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c096602;
P_0c096602: /* original 8b06, guest PC 0x0c096602 */
if(!s->budget--) { s->failed_pc=0x0c096602u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096612; }
goto P_0c096604;
P_0c096604: /* original a00d, guest PC 0x0c096604 */
if(!s->budget--) { s->failed_pc=0x0c096604u; return 0; }
goto P_0c096622;
P_0c096606: /* original 0009, guest PC 0x0c096606 */
if(!s->budget--) { s->failed_pc=0x0c096606u; return 0; }
goto P_0c096608;
P_0c096608: /* original 2528, guest PC 0x0c096608 */
if(!s->budget--) { s->failed_pc=0x0c096608u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c09660a;
P_0c09660a: /* original 890a, guest PC 0x0c09660a */
if(!s->budget--) { s->failed_pc=0x0c09660au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c09660c;
P_0c09660c: /* original 60e2, guest PC 0x0c09660c */
if(!s->budget--) { s->failed_pc=0x0c09660cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c09660e;
P_0c09660e: /* original 20d8, guest PC 0x0c09660e */
if(!s->budget--) { s->failed_pc=0x0c09660eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[13])==0)!=0);
goto P_0c096610;
P_0c096610: /* original 8907, guest PC 0x0c096610 */
if(!s->budget--) { s->failed_pc=0x0c096610u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c096612;
P_0c096612: /* original d337, guest PC 0x0c096612 */
if(!s->budget--) { s->failed_pc=0x0c096612u; return 0; }
r[3]=read(ram,0x0c0966f0u,4);
goto P_0c096614;
P_0c096614: /* original 9469, guest PC 0x0c096614 */
if(!s->budget--) { s->failed_pc=0x0c096614u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966eau,2);
goto P_0c096616;
P_0c096616: /* original 430b, guest PC 0x0c096616 */
if(!s->budget--) { s->failed_pc=0x0c096616u; return 0; }
target=r[3];
r[16]=code_base|0x0c09661au;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09661au) { target=s->pc; goto dispatch; }
goto P_0c09661a;
P_0c096618: /* original e500, guest PC 0x0c096618 */
if(!s->budget--) { s->failed_pc=0x0c096618u; return 0; }
r[5]=0x00000000u;
goto P_0c09661a;
P_0c09661a: /* original 62e2, guest PC 0x0c09661a */
if(!s->budget--) { s->failed_pc=0x0c09661au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09661c;
P_0c09661c: /* original e3fe, guest PC 0x0c09661c */
if(!s->budget--) { s->failed_pc=0x0c09661cu; return 0; }
r[3]=0xfffffffeu;
goto P_0c09661e;
P_0c09661e: /* original 2239, guest PC 0x0c09661e */
if(!s->budget--) { s->failed_pc=0x0c09661eu; return 0; }
r[2]&=r[3];
goto P_0c096620;
P_0c096620: /* original 2e22, guest PC 0x0c096620 */
if(!s->budget--) { s->failed_pc=0x0c096620u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c096622;
P_0c096622: /* original 4c0b, guest PC 0x0c096622 */
if(!s->budget--) { s->failed_pc=0x0c096622u; return 0; }
target=r[12];
r[16]=code_base|0x0c096626u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096626u) { target=s->pc; goto dispatch; }
goto P_0c096626;
P_0c096624: /* original e401, guest PC 0x0c096624 */
if(!s->budget--) { s->failed_pc=0x0c096624u; return 0; }
r[4]=0x00000001u;
goto P_0c096626;
P_0c096626: /* original 6403, guest PC 0x0c096626 */
if(!s->budget--) { s->failed_pc=0x0c096626u; return 0; }
r[4]=r[0];
goto P_0c096628;
P_0c096628: /* original 5242, guest PC 0x0c096628 */
if(!s->budget--) { s->failed_pc=0x0c096628u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09662a;
P_0c09662a: /* original d332, guest PC 0x0c09662a */
if(!s->budget--) { s->failed_pc=0x0c09662au; return 0; }
r[3]=read(ram,0x0c0966f4u,4);
goto P_0c09662c;
P_0c09662c: /* original 2238, guest PC 0x0c09662c */
if(!s->budget--) { s->failed_pc=0x0c09662cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09662e;
P_0c09662e: /* original 8b03, guest PC 0x0c09662e */
if(!s->budget--) { s->failed_pc=0x0c09662eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096638; }
goto P_0c096630;
P_0c096630: /* original 5242, guest PC 0x0c096630 */
if(!s->budget--) { s->failed_pc=0x0c096630u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c096632;
P_0c096632: /* original 955b, guest PC 0x0c096632 */
if(!s->budget--) { s->failed_pc=0x0c096632u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966ecu,2);
goto P_0c096634;
P_0c096634: /* original 2259, guest PC 0x0c096634 */
if(!s->budget--) { s->failed_pc=0x0c096634u; return 0; }
r[2]&=r[5];
goto P_0c096636;
P_0c096636: /* original 3250, guest PC 0x0c096636 */
if(!s->budget--) { s->failed_pc=0x0c096636u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[5])!=0);
goto P_0c096638;
P_0c096638: /* original 7f04, guest PC 0x0c096638 */
if(!s->budget--) { s->failed_pc=0x0c096638u; return 0; }
r[15]+=0x00000004u;
goto P_0c09663a;
P_0c09663a: /* original 4f26, guest PC 0x0c09663a */
if(!s->budget--) { s->failed_pc=0x0c09663au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09663c;
P_0c09663c: /* original 68f6, guest PC 0x0c09663c */
if(!s->budget--) { s->failed_pc=0x0c09663cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09663e;
P_0c09663e: /* original 69f6, guest PC 0x0c09663e */
if(!s->budget--) { s->failed_pc=0x0c09663eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c096640;
P_0c096640: /* original 6af6, guest PC 0x0c096640 */
if(!s->budget--) { s->failed_pc=0x0c096640u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c096642;
P_0c096642: /* original 6bf6, guest PC 0x0c096642 */
if(!s->budget--) { s->failed_pc=0x0c096642u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c096644;
P_0c096644: /* original 6cf6, guest PC 0x0c096644 */
if(!s->budget--) { s->failed_pc=0x0c096644u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096646;
P_0c096646: /* original 6df6, guest PC 0x0c096646 */
if(!s->budget--) { s->failed_pc=0x0c096646u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096648;
P_0c096648: /* original 000b, guest PC 0x0c096648 */
if(!s->budget--) { s->failed_pc=0x0c096648u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09664a: /* original 6ef6, guest PC 0x0c09664a */
if(!s->budget--) { s->failed_pc=0x0c09664au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09664cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09664cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
