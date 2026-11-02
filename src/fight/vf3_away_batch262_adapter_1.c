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
int vf3_away_batch262_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08648cu: goto P_0c08648c;
case 0x0c08648eu: goto P_0c08648e;
case 0x0c086490u: goto P_0c086490;
case 0x0c086492u: goto P_0c086492;
case 0x0c086494u: goto P_0c086494;
case 0x0c086496u: goto P_0c086496;
case 0x0c086498u: goto P_0c086498;
case 0x0c08649au: goto P_0c08649a;
case 0x0c08649cu: goto P_0c08649c;
case 0x0c08649eu: goto P_0c08649e;
case 0x0c0864a0u: goto P_0c0864a0;
case 0x0c0864a2u: goto P_0c0864a2;
case 0x0c0864a4u: goto P_0c0864a4;
case 0x0c0864a6u: goto P_0c0864a6;
case 0x0c0864a8u: goto P_0c0864a8;
case 0x0c0864aau: goto P_0c0864aa;
case 0x0c0864acu: goto P_0c0864ac;
case 0x0c0864aeu: goto P_0c0864ae;
case 0x0c0864b0u: goto P_0c0864b0;
case 0x0c0864b2u: goto P_0c0864b2;
case 0x0c0864b4u: goto P_0c0864b4;
case 0x0c0864b6u: goto P_0c0864b6;
case 0x0c0864b8u: goto P_0c0864b8;
case 0x0c0864bau: goto P_0c0864ba;
case 0x0c0864bcu: goto P_0c0864bc;
case 0x0c0864beu: goto P_0c0864be;
case 0x0c0864c0u: goto P_0c0864c0;
case 0x0c0864c2u: goto P_0c0864c2;
case 0x0c0864c4u: goto P_0c0864c4;
case 0x0c0864c6u: goto P_0c0864c6;
case 0x0c0864c8u: goto P_0c0864c8;
case 0x0c0864cau: goto P_0c0864ca;
case 0x0c0864ccu: goto P_0c0864cc;
case 0x0c0864ceu: goto P_0c0864ce;
case 0x0c0864d0u: goto P_0c0864d0;
case 0x0c0864d2u: goto P_0c0864d2;
case 0x0c0864d4u: goto P_0c0864d4;
case 0x0c0864d6u: goto P_0c0864d6;
case 0x0c0864d8u: goto P_0c0864d8;
case 0x0c0864dau: goto P_0c0864da;
case 0x0c0864dcu: goto P_0c0864dc;
case 0x0c0864deu: goto P_0c0864de;
case 0x0c0864e0u: goto P_0c0864e0;
case 0x0c0864e2u: goto P_0c0864e2;
case 0x0c0864e4u: goto P_0c0864e4;
case 0x0c0864e6u: goto P_0c0864e6;
case 0x0c0864e8u: goto P_0c0864e8;
case 0x0c0864eau: goto P_0c0864ea;
case 0x0c0864ecu: goto P_0c0864ec;
case 0x0c0864eeu: goto P_0c0864ee;
case 0x0c0864f0u: goto P_0c0864f0;
case 0x0c0864f2u: goto P_0c0864f2;
case 0x0c0864f4u: goto P_0c0864f4;
case 0x0c0864f6u: goto P_0c0864f6;
case 0x0c0864f8u: goto P_0c0864f8;
case 0x0c0864fau: goto P_0c0864fa;
case 0x0c0864fcu: goto P_0c0864fc;
case 0x0c0864feu: goto P_0c0864fe;
case 0x0c086500u: goto P_0c086500;
case 0x0c086502u: goto P_0c086502;
case 0x0c086504u: goto P_0c086504;
case 0x0c086506u: goto P_0c086506;
case 0x0c086508u: goto P_0c086508;
case 0x0c08650au: goto P_0c08650a;
case 0x0c08650cu: goto P_0c08650c;
case 0x0c08650eu: goto P_0c08650e;
case 0x0c086538u: goto P_0c086538;
case 0x0c08653au: goto P_0c08653a;
case 0x0c08653cu: goto P_0c08653c;
case 0x0c08653eu: goto P_0c08653e;
case 0x0c086540u: goto P_0c086540;
case 0x0c086542u: goto P_0c086542;
case 0x0c086544u: goto P_0c086544;
case 0x0c086546u: goto P_0c086546;
case 0x0c086548u: goto P_0c086548;
case 0x0c08654au: goto P_0c08654a;
case 0x0c08654cu: goto P_0c08654c;
case 0x0c08654eu: goto P_0c08654e;
case 0x0c086550u: goto P_0c086550;
case 0x0c086552u: goto P_0c086552;
case 0x0c086554u: goto P_0c086554;
case 0x0c086556u: goto P_0c086556;
case 0x0c086558u: goto P_0c086558;
case 0x0c08655au: goto P_0c08655a;
case 0x0c08655cu: goto P_0c08655c;
case 0x0c08655eu: goto P_0c08655e;
case 0x0c086560u: goto P_0c086560;
case 0x0c086562u: goto P_0c086562;
case 0x0c086564u: goto P_0c086564;
case 0x0c086566u: goto P_0c086566;
case 0x0c086568u: goto P_0c086568;
case 0x0c08656au: goto P_0c08656a;
case 0x0c08656cu: goto P_0c08656c;
case 0x0c08656eu: goto P_0c08656e;
case 0x0c086570u: goto P_0c086570;
case 0x0c086572u: goto P_0c086572;
case 0x0c086574u: goto P_0c086574;
case 0x0c086576u: goto P_0c086576;
case 0x0c086578u: goto P_0c086578;
case 0x0c08657au: goto P_0c08657a;
case 0x0c08657cu: goto P_0c08657c;
case 0x0c08657eu: goto P_0c08657e;
case 0x0c086580u: goto P_0c086580;
case 0x0c086582u: goto P_0c086582;
case 0x0c086584u: goto P_0c086584;
case 0x0c086586u: goto P_0c086586;
case 0x0c086588u: goto P_0c086588;
case 0x0c08658au: goto P_0c08658a;
case 0x0c08658cu: goto P_0c08658c;
case 0x0c08658eu: goto P_0c08658e;
case 0x0c086590u: goto P_0c086590;
case 0x0c086592u: goto P_0c086592;
case 0x0c086594u: goto P_0c086594;
case 0x0c086596u: goto P_0c086596;
case 0x0c086598u: goto P_0c086598;
case 0x0c08659au: goto P_0c08659a;
case 0x0c08659cu: goto P_0c08659c;
case 0x0c08659eu: goto P_0c08659e;
case 0x0c0865a0u: goto P_0c0865a0;
case 0x0c0865a2u: goto P_0c0865a2;
case 0x0c0865a4u: goto P_0c0865a4;
case 0x0c0865a6u: goto P_0c0865a6;
case 0x0c0865a8u: goto P_0c0865a8;
case 0x0c0865aau: goto P_0c0865aa;
case 0x0c0865acu: goto P_0c0865ac;
case 0x0c0865aeu: goto P_0c0865ae;
case 0x0c0865b0u: goto P_0c0865b0;
case 0x0c0865b2u: goto P_0c0865b2;
case 0x0c0865b4u: goto P_0c0865b4;
case 0x0c0865b6u: goto P_0c0865b6;
case 0x0c0865b8u: goto P_0c0865b8;
case 0x0c0865bau: goto P_0c0865ba;
case 0x0c0865bcu: goto P_0c0865bc;
case 0x0c0865beu: goto P_0c0865be;
case 0x0c0865c0u: goto P_0c0865c0;
case 0x0c0865c2u: goto P_0c0865c2;
case 0x0c0865c4u: goto P_0c0865c4;
case 0x0c0865c6u: goto P_0c0865c6;
case 0x0c0865c8u: goto P_0c0865c8;
case 0x0c0865cau: goto P_0c0865ca;
case 0x0c0865ccu: goto P_0c0865cc;
case 0x0c0865ceu: goto P_0c0865ce;
case 0x0c0865d0u: goto P_0c0865d0;
case 0x0c0865d2u: goto P_0c0865d2;
case 0x0c0865d4u: goto P_0c0865d4;
case 0x0c0865d6u: goto P_0c0865d6;
case 0x0c0865d8u: goto P_0c0865d8;
case 0x0c0865dau: goto P_0c0865da;
case 0x0c0865dcu: goto P_0c0865dc;
case 0x0c0865deu: goto P_0c0865de;
case 0x0c0865e0u: goto P_0c0865e0;
case 0x0c0865e2u: goto P_0c0865e2;
case 0x0c0865e4u: goto P_0c0865e4;
case 0x0c0865e6u: goto P_0c0865e6;
case 0x0c0865e8u: goto P_0c0865e8;
case 0x0c0865eau: goto P_0c0865ea;
case 0x0c0865ecu: goto P_0c0865ec;
case 0x0c0865eeu: goto P_0c0865ee;
case 0x0c0865f0u: goto P_0c0865f0;
case 0x0c0865f2u: goto P_0c0865f2;
case 0x0c0865f4u: goto P_0c0865f4;
case 0x0c0865f6u: goto P_0c0865f6;
case 0x0c0865f8u: goto P_0c0865f8;
case 0x0c0865fau: goto P_0c0865fa;
case 0x0c0865fcu: goto P_0c0865fc;
case 0x0c0865feu: goto P_0c0865fe;
case 0x0c086600u: goto P_0c086600;
case 0x0c086602u: goto P_0c086602;
case 0x0c086604u: goto P_0c086604;
case 0x0c086606u: goto P_0c086606;
case 0x0c086608u: goto P_0c086608;
case 0x0c08660au: goto P_0c08660a;
case 0x0c08660cu: goto P_0c08660c;
case 0x0c08660eu: goto P_0c08660e;
case 0x0c086610u: goto P_0c086610;
case 0x0c086612u: goto P_0c086612;
case 0x0c086614u: goto P_0c086614;
case 0x0c086616u: goto P_0c086616;
case 0x0c086618u: goto P_0c086618;
case 0x0c08661au: goto P_0c08661a;
case 0x0c08661cu: goto P_0c08661c;
case 0x0c08661eu: goto P_0c08661e;
case 0x0c086620u: goto P_0c086620;
case 0x0c086622u: goto P_0c086622;
case 0x0c086624u: goto P_0c086624;
case 0x0c086626u: goto P_0c086626;
case 0x0c086628u: goto P_0c086628;
case 0x0c08662au: goto P_0c08662a;
case 0x0c08662cu: goto P_0c08662c;
case 0x0c08662eu: goto P_0c08662e;
case 0x0c086630u: goto P_0c086630;
case 0x0c086632u: goto P_0c086632;
case 0x0c086634u: goto P_0c086634;
case 0x0c086636u: goto P_0c086636;
case 0x0c086638u: goto P_0c086638;
case 0x0c08663au: goto P_0c08663a;
case 0x0c08663cu: goto P_0c08663c;
case 0x0c08663eu: goto P_0c08663e;
case 0x0c086640u: goto P_0c086640;
case 0x0c086642u: goto P_0c086642;
case 0x0c086644u: goto P_0c086644;
case 0x0c086646u: goto P_0c086646;
case 0x0c086648u: goto P_0c086648;
case 0x0c08664au: goto P_0c08664a;
case 0x0c08664cu: goto P_0c08664c;
case 0x0c08664eu: goto P_0c08664e;
case 0x0c086650u: goto P_0c086650;
case 0x0c086652u: goto P_0c086652;
case 0x0c086654u: goto P_0c086654;
case 0x0c086656u: goto P_0c086656;
case 0x0c086658u: goto P_0c086658;
case 0x0c08665au: goto P_0c08665a;
case 0x0c08665cu: goto P_0c08665c;
case 0x0c08665eu: goto P_0c08665e;
case 0x0c086660u: goto P_0c086660;
case 0x0c086662u: goto P_0c086662;
case 0x0c086664u: goto P_0c086664;
case 0x0c086666u: goto P_0c086666;
case 0x0c086668u: goto P_0c086668;
case 0x0c08666au: goto P_0c08666a;
case 0x0c08666cu: goto P_0c08666c;
case 0x0c08666eu: goto P_0c08666e;
case 0x0c086670u: goto P_0c086670;
case 0x0c086672u: goto P_0c086672;
case 0x0c086674u: goto P_0c086674;
case 0x0c086676u: goto P_0c086676;
case 0x0c086678u: goto P_0c086678;
case 0x0c08667au: goto P_0c08667a;
case 0x0c08667cu: goto P_0c08667c;
case 0x0c08667eu: goto P_0c08667e;
case 0x0c086680u: goto P_0c086680;
case 0x0c0866a0u: goto P_0c0866a0;
case 0x0c0866a2u: goto P_0c0866a2;
case 0x0c0866a4u: goto P_0c0866a4;
case 0x0c0866a6u: goto P_0c0866a6;
case 0x0c0866a8u: goto P_0c0866a8;
case 0x0c0866aau: goto P_0c0866aa;
case 0x0c0866acu: goto P_0c0866ac;
case 0x0c0866aeu: goto P_0c0866ae;
case 0x0c0866b0u: goto P_0c0866b0;
case 0x0c0866b2u: goto P_0c0866b2;
case 0x0c0866b4u: goto P_0c0866b4;
case 0x0c0866b6u: goto P_0c0866b6;
case 0x0c0866b8u: goto P_0c0866b8;
case 0x0c0866bau: goto P_0c0866ba;
case 0x0c0866bcu: goto P_0c0866bc;
case 0x0c0866beu: goto P_0c0866be;
case 0x0c0866c0u: goto P_0c0866c0;
case 0x0c0866c2u: goto P_0c0866c2;
case 0x0c0866c4u: goto P_0c0866c4;
case 0x0c0866c6u: goto P_0c0866c6;
case 0x0c0866c8u: goto P_0c0866c8;
case 0x0c0866cau: goto P_0c0866ca;
case 0x0c0866ccu: goto P_0c0866cc;
case 0x0c0866ceu: goto P_0c0866ce;
case 0x0c0866d0u: goto P_0c0866d0;
case 0x0c0866d2u: goto P_0c0866d2;
case 0x0c0866d4u: goto P_0c0866d4;
case 0x0c0866d6u: goto P_0c0866d6;
case 0x0c0866d8u: goto P_0c0866d8;
case 0x0c0866dau: goto P_0c0866da;
case 0x0c0866dcu: goto P_0c0866dc;
case 0x0c0866deu: goto P_0c0866de;
case 0x0c0866e0u: goto P_0c0866e0;
case 0x0c0866e2u: goto P_0c0866e2;
case 0x0c0866e4u: goto P_0c0866e4;
case 0x0c0866e6u: goto P_0c0866e6;
case 0x0c0866e8u: goto P_0c0866e8;
case 0x0c0866eau: goto P_0c0866ea;
case 0x0c0866ecu: goto P_0c0866ec;
case 0x0c0866eeu: goto P_0c0866ee;
case 0x0c0866f0u: goto P_0c0866f0;
case 0x0c0866f2u: goto P_0c0866f2;
case 0x0c0866f4u: goto P_0c0866f4;
case 0x0c0866f6u: goto P_0c0866f6;
case 0x0c0866f8u: goto P_0c0866f8;
case 0x0c0866fau: goto P_0c0866fa;
case 0x0c0866fcu: goto P_0c0866fc;
case 0x0c0866feu: goto P_0c0866fe;
case 0x0c086700u: goto P_0c086700;
case 0x0c086702u: goto P_0c086702;
case 0x0c086704u: goto P_0c086704;
case 0x0c086706u: goto P_0c086706;
case 0x0c086708u: goto P_0c086708;
case 0x0c08670au: goto P_0c08670a;
case 0x0c08670cu: goto P_0c08670c;
case 0x0c08670eu: goto P_0c08670e;
case 0x0c086710u: goto P_0c086710;
case 0x0c086712u: goto P_0c086712;
case 0x0c086714u: goto P_0c086714;
case 0x0c086716u: goto P_0c086716;
case 0x0c086718u: goto P_0c086718;
case 0x0c08671au: goto P_0c08671a;
case 0x0c08671cu: goto P_0c08671c;
case 0x0c08671eu: goto P_0c08671e;
case 0x0c086720u: goto P_0c086720;
case 0x0c086722u: goto P_0c086722;
case 0x0c086724u: goto P_0c086724;
case 0x0c086726u: goto P_0c086726;
case 0x0c086728u: goto P_0c086728;
case 0x0c08672au: goto P_0c08672a;
case 0x0c08672cu: goto P_0c08672c;
case 0x0c08672eu: goto P_0c08672e;
case 0x0c086730u: goto P_0c086730;
case 0x0c086732u: goto P_0c086732;
case 0x0c086734u: goto P_0c086734;
case 0x0c086736u: goto P_0c086736;
case 0x0c086738u: goto P_0c086738;
case 0x0c08673au: goto P_0c08673a;
case 0x0c08673cu: goto P_0c08673c;
case 0x0c08673eu: goto P_0c08673e;
case 0x0c086740u: goto P_0c086740;
case 0x0c086742u: goto P_0c086742;
case 0x0c086744u: goto P_0c086744;
case 0x0c086746u: goto P_0c086746;
case 0x0c086748u: goto P_0c086748;
case 0x0c08674au: goto P_0c08674a;
case 0x0c08674cu: goto P_0c08674c;
case 0x0c08674eu: goto P_0c08674e;
case 0x0c086750u: goto P_0c086750;
case 0x0c086752u: goto P_0c086752;
case 0x0c086754u: goto P_0c086754;
case 0x0c086756u: goto P_0c086756;
case 0x0c086758u: goto P_0c086758;
case 0x0c08675au: goto P_0c08675a;
case 0x0c08675cu: goto P_0c08675c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08648c: /* original 2fe6, guest PC 0x0c08648c */
if(!s->budget--) { s->failed_pc=0x0c08648cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08648e;
P_0c08648e: /* original 2fd6, guest PC 0x0c08648e */
if(!s->budget--) { s->failed_pc=0x0c08648eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086490;
P_0c086490: /* original 2fc6, guest PC 0x0c086490 */
if(!s->budget--) { s->failed_pc=0x0c086490u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086492;
P_0c086492: /* original 2fb6, guest PC 0x0c086492 */
if(!s->budget--) { s->failed_pc=0x0c086492u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086494;
P_0c086494: /* original 2fa6, guest PC 0x0c086494 */
if(!s->budget--) { s->failed_pc=0x0c086494u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086496;
P_0c086496: /* original 2f96, guest PC 0x0c086496 */
if(!s->budget--) { s->failed_pc=0x0c086496u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086498;
P_0c086498: /* original 2f86, guest PC 0x0c086498 */
if(!s->budget--) { s->failed_pc=0x0c086498u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08649a;
P_0c08649a: /* original d126, guest PC 0x0c08649a */
if(!s->budget--) { s->failed_pc=0x0c08649au; return 0; }
r[1]=read(ram,0x0c086534u,4);
goto P_0c08649c;
P_0c08649c: /* original 4f22, guest PC 0x0c08649c */
if(!s->budget--) { s->failed_pc=0x0c08649cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08649e;
P_0c08649e: /* original 6212, guest PC 0x0c08649e */
if(!s->budget--) { s->failed_pc=0x0c08649eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0864a0;
P_0c0864a0: /* original d323, guest PC 0x0c0864a0 */
if(!s->budget--) { s->failed_pc=0x0c0864a0u; return 0; }
r[3]=read(ram,0x0c086530u,4);
goto P_0c0864a2;
P_0c0864a2: /* original 2238, guest PC 0x0c0864a2 */
if(!s->budget--) { s->failed_pc=0x0c0864a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0864a4;
P_0c0864a4: /* original 8b54, guest PC 0x0c0864a4 */
if(!s->budget--) { s->failed_pc=0x0c0864a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086550; }
goto P_0c0864a6;
P_0c0864a6: /* original da1b, guest PC 0x0c0864a6 */
if(!s->budget--) { s->failed_pc=0x0c0864a6u; return 0; }
r[10]=read(ram,0x0c086514u,4);
goto P_0c0864a8;
P_0c0864a8: /* original 6c43, guest PC 0x0c0864a8 */
if(!s->budget--) { s->failed_pc=0x0c0864a8u; return 0; }
r[12]=r[4];
goto P_0c0864aa;
P_0c0864aa: /* original e900, guest PC 0x0c0864aa */
if(!s->budget--) { s->failed_pc=0x0c0864aau; return 0; }
r[9]=0x00000000u;
goto P_0c0864ac;
P_0c0864ac: /* original 6d43, guest PC 0x0c0864ac */
if(!s->budget--) { s->failed_pc=0x0c0864acu; return 0; }
r[13]=r[4];
goto P_0c0864ae;
P_0c0864ae: /* original 5ea4, guest PC 0x0c0864ae */
if(!s->budget--) { s->failed_pc=0x0c0864aeu; return 0; }
r[14]=read(ram,r[10]+16,4);
goto P_0c0864b0;
P_0c0864b0: /* original 7c28, guest PC 0x0c0864b0 */
if(!s->budget--) { s->failed_pc=0x0c0864b0u; return 0; }
r[12]+=0x00000028u;
goto P_0c0864b2;
P_0c0864b2: /* original a049, guest PC 0x0c0864b2 */
if(!s->budget--) { s->failed_pc=0x0c0864b2u; return 0; }
r[8]=r[9];
goto P_0c086548;
P_0c0864b4: /* original 6893, guest PC 0x0c0864b4 */
if(!s->budget--) { s->failed_pc=0x0c0864b4u; return 0; }
r[8]=r[9];
goto P_0c0864b6;
P_0c0864b6: /* original e061, guest PC 0x0c0864b6 */
if(!s->budget--) { s->failed_pc=0x0c0864b6u; return 0; }
r[0]=0x00000061u;
goto P_0c0864b8;
P_0c0864b8: /* original 00ec, guest PC 0x0c0864b8 */
if(!s->budget--) { s->failed_pc=0x0c0864b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0864ba;
P_0c0864ba: /* original 600c, guest PC 0x0c0864ba */
if(!s->budget--) { s->failed_pc=0x0c0864bau; return 0; }
r[0]=r[0]&255u;
goto P_0c0864bc;
P_0c0864bc: /* original 880c, guest PC 0x0c0864bc */
if(!s->budget--) { s->failed_pc=0x0c0864bcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0864be;
P_0c0864be: /* original 893f, guest PC 0x0c0864be */
if(!s->budget--) { s->failed_pc=0x0c0864beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086540; }
goto P_0c0864c0;
P_0c0864c0: /* original 9026, guest PC 0x0c0864c0 */
if(!s->budget--) { s->failed_pc=0x0c0864c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086510u,2);
goto P_0c0864c2;
P_0c0864c2: /* original e504, guest PC 0x0c0864c2 */
if(!s->budget--) { s->failed_pc=0x0c0864c2u; return 0; }
r[5]=0x00000004u;
goto P_0c0864c4;
P_0c0864c4: /* original 06ee, guest PC 0x0c0864c4 */
if(!s->budget--) { s->failed_pc=0x0c0864c4u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0864c6;
P_0c0864c6: /* original 6363, guest PC 0x0c0864c6 */
if(!s->budget--) { s->failed_pc=0x0c0864c6u; return 0; }
r[3]=r[6];
goto P_0c0864c8;
P_0c0864c8: /* original 2358, guest PC 0x0c0864c8 */
if(!s->budget--) { s->failed_pc=0x0c0864c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0864ca;
P_0c0864ca: /* original 8f0c, guest PC 0x0c0864ca */
if(!s->budget--) { s->failed_pc=0x0c0864cau; return 0; }
cond=r[17]&1u;
r[11]=r[4];
if(!cond) { goto P_0c0864e6; }
goto P_0c0864ce;
P_0c0864cc: /* original 6b43, guest PC 0x0c0864cc */
if(!s->budget--) { s->failed_pc=0x0c0864ccu; return 0; }
r[11]=r[4];
goto P_0c0864ce;
P_0c0864ce: /* original 2468, guest PC 0x0c0864ce */
if(!s->budget--) { s->failed_pc=0x0c0864ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[6])==0)!=0);
goto P_0c0864d0;
P_0c0864d0: /* original e501, guest PC 0x0c0864d0 */
if(!s->budget--) { s->failed_pc=0x0c0864d0u; return 0; }
r[5]=0x00000001u;
goto P_0c0864d2;
P_0c0864d2: /* original 8f08, guest PC 0x0c0864d2 */
if(!s->budget--) { s->failed_pc=0x0c0864d2u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(!cond) { goto P_0c0864e6; }
goto P_0c0864d6;
P_0c0864d4: /* original 6b53, guest PC 0x0c0864d4 */
if(!s->budget--) { s->failed_pc=0x0c0864d4u; return 0; }
r[11]=r[5];
goto P_0c0864d6;
P_0c0864d6: /* original 2658, guest PC 0x0c0864d6 */
if(!s->budget--) { s->failed_pc=0x0c0864d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[5])==0)!=0);
goto P_0c0864d8;
P_0c0864d8: /* original 8d05, guest PC 0x0c0864d8 */
if(!s->budget--) { s->failed_pc=0x0c0864d8u; return 0; }
cond=r[17]&1u;
r[11]=r[9];
if(cond) { goto P_0c0864e6; }
goto P_0c0864dc;
P_0c0864da: /* original 6b93, guest PC 0x0c0864da */
if(!s->budget--) { s->failed_pc=0x0c0864dau; return 0; }
r[11]=r[9];
goto P_0c0864dc;
P_0c0864dc: /* original 6b53, guest PC 0x0c0864dc */
if(!s->budget--) { s->failed_pc=0x0c0864dcu; return 0; }
r[11]=r[5];
goto P_0c0864de;
P_0c0864de: /* original 65c3, guest PC 0x0c0864de */
if(!s->budget--) { s->failed_pc=0x0c0864deu; return 0; }
r[5]=r[12];
goto P_0c0864e0;
P_0c0864e0: /* original 66e3, guest PC 0x0c0864e0 */
if(!s->budget--) { s->failed_pc=0x0c0864e0u; return 0; }
r[6]=r[14];
goto P_0c0864e2;
P_0c0864e2: /* original b03e, guest PC 0x0c0864e2 */
if(!s->budget--) { s->failed_pc=0x0c0864e2u; return 0; }
target=code_base|0x0c086562u; r[16]=code_base|0x0c0864e6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0864e6u) { target=s->pc; goto dispatch; }
goto P_0c0864e6;
P_0c0864e4: /* original 64d3, guest PC 0x0c0864e4 */
if(!s->budget--) { s->failed_pc=0x0c0864e4u; return 0; }
r[4]=r[13];
goto P_0c0864e6;
P_0c0864e6: /* original 60bf, guest PC 0x0c0864e6 */
if(!s->budget--) { s->failed_pc=0x0c0864e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c0864e8;
P_0c0864e8: /* original 8800, guest PC 0x0c0864e8 */
if(!s->budget--) { s->failed_pc=0x0c0864e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0864ea;
P_0c0864ea: /* original 8905, guest PC 0x0c0864ea */
if(!s->budget--) { s->failed_pc=0x0c0864eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0864f8; }
goto P_0c0864ec;
P_0c0864ec: /* original 8801, guest PC 0x0c0864ec */
if(!s->budget--) { s->failed_pc=0x0c0864ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0864ee;
P_0c0864ee: /* original 8909, guest PC 0x0c0864ee */
if(!s->budget--) { s->failed_pc=0x0c0864eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086504; }
goto P_0c0864f0;
P_0c0864f0: /* original 8802, guest PC 0x0c0864f0 */
if(!s->budget--) { s->failed_pc=0x0c0864f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0864f2;
P_0c0864f2: /* original 8921, guest PC 0x0c0864f2 */
if(!s->budget--) { s->failed_pc=0x0c0864f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086538; }
goto P_0c0864f4;
P_0c0864f4: /* original a024, guest PC 0x0c0864f4 */
if(!s->budget--) { s->failed_pc=0x0c0864f4u; return 0; }
goto P_0c086540;
P_0c0864f6: /* original 0009, guest PC 0x0c0864f6 */
if(!s->budget--) { s->failed_pc=0x0c0864f6u; return 0; }
goto P_0c0864f8;
P_0c0864f8: /* original 65c3, guest PC 0x0c0864f8 */
if(!s->budget--) { s->failed_pc=0x0c0864f8u; return 0; }
r[5]=r[12];
goto P_0c0864fa;
P_0c0864fa: /* original 66e3, guest PC 0x0c0864fa */
if(!s->budget--) { s->failed_pc=0x0c0864fau; return 0; }
r[6]=r[14];
goto P_0c0864fc;
P_0c0864fc: /* original b058, guest PC 0x0c0864fc */
if(!s->budget--) { s->failed_pc=0x0c0864fcu; return 0; }
target=code_base|0x0c0865b0u; r[16]=code_base|0x0c086500u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086500u) { target=s->pc; goto dispatch; }
goto P_0c086500;
P_0c0864fe: /* original 64d3, guest PC 0x0c0864fe */
if(!s->budget--) { s->failed_pc=0x0c0864feu; return 0; }
r[4]=r[13];
goto P_0c086500;
P_0c086500: /* original a01e, guest PC 0x0c086500 */
if(!s->budget--) { s->failed_pc=0x0c086500u; return 0; }
goto P_0c086540;
P_0c086502: /* original 0009, guest PC 0x0c086502 */
if(!s->budget--) { s->failed_pc=0x0c086502u; return 0; }
goto P_0c086504;
P_0c086504: /* original 65c3, guest PC 0x0c086504 */
if(!s->budget--) { s->failed_pc=0x0c086504u; return 0; }
r[5]=r[12];
goto P_0c086506;
P_0c086506: /* original 66e3, guest PC 0x0c086506 */
if(!s->budget--) { s->failed_pc=0x0c086506u; return 0; }
r[6]=r[14];
goto P_0c086508;
P_0c086508: /* original b073, guest PC 0x0c086508 */
if(!s->budget--) { s->failed_pc=0x0c086508u; return 0; }
target=code_base|0x0c0865f2u; r[16]=code_base|0x0c08650cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08650cu) { target=s->pc; goto dispatch; }
goto P_0c08650c;
P_0c08650a: /* original 64d3, guest PC 0x0c08650a */
if(!s->budget--) { s->failed_pc=0x0c08650au; return 0; }
r[4]=r[13];
goto P_0c08650c;
P_0c08650c: /* original a018, guest PC 0x0c08650c */
if(!s->budget--) { s->failed_pc=0x0c08650cu; return 0; }
goto P_0c086540;
P_0c08650e: /* original 0009, guest PC 0x0c08650e */
if(!s->budget--) { s->failed_pc=0x0c08650eu; return 0; }
if(!vf3_matrix_family(0x0c086510u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c086510u; return 0; } return 1;
P_0c086538: /* original 65c3, guest PC 0x0c086538 */
if(!s->budget--) { s->failed_pc=0x0c086538u; return 0; }
r[5]=r[12];
goto P_0c08653a;
P_0c08653a: /* original 66e3, guest PC 0x0c08653a */
if(!s->budget--) { s->failed_pc=0x0c08653au; return 0; }
r[6]=r[14];
goto P_0c08653c;
P_0c08653c: /* original b049, guest PC 0x0c08653c */
if(!s->budget--) { s->failed_pc=0x0c08653cu; return 0; }
target=code_base|0x0c0865d2u; r[16]=code_base|0x0c086540u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086540u) { target=s->pc; goto dispatch; }
goto P_0c086540;
P_0c08653e: /* original 64d3, guest PC 0x0c08653e */
if(!s->budget--) { s->failed_pc=0x0c08653eu; return 0; }
r[4]=r[13];
goto P_0c086540;
P_0c086540: /* original 6cd3, guest PC 0x0c086540 */
if(!s->budget--) { s->failed_pc=0x0c086540u; return 0; }
r[12]=r[13];
goto P_0c086542;
P_0c086542: /* original 5ea5, guest PC 0x0c086542 */
if(!s->budget--) { s->failed_pc=0x0c086542u; return 0; }
r[14]=read(ram,r[10]+20,4);
goto P_0c086544;
P_0c086544: /* original 7801, guest PC 0x0c086544 */
if(!s->budget--) { s->failed_pc=0x0c086544u; return 0; }
r[8]+=0x00000001u;
goto P_0c086546;
P_0c086546: /* original 7c78, guest PC 0x0c086546 */
if(!s->budget--) { s->failed_pc=0x0c086546u; return 0; }
r[12]+=0x00000078u;
goto P_0c086548;
P_0c086548: /* original 628f, guest PC 0x0c086548 */
if(!s->budget--) { s->failed_pc=0x0c086548u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[8];
goto P_0c08654a;
P_0c08654a: /* original e402, guest PC 0x0c08654a */
if(!s->budget--) { s->failed_pc=0x0c08654au; return 0; }
r[4]=0x00000002u;
goto P_0c08654c;
P_0c08654c: /* original 3243, guest PC 0x0c08654c */
if(!s->budget--) { s->failed_pc=0x0c08654cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c08654e;
P_0c08654e: /* original 8bb2, guest PC 0x0c08654e */
if(!s->budget--) { s->failed_pc=0x0c08654eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0864b6; }
goto P_0c086550;
P_0c086550: /* original 4f26, guest PC 0x0c086550 */
if(!s->budget--) { s->failed_pc=0x0c086550u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086552;
P_0c086552: /* original 68f6, guest PC 0x0c086552 */
if(!s->budget--) { s->failed_pc=0x0c086552u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c086554;
P_0c086554: /* original 69f6, guest PC 0x0c086554 */
if(!s->budget--) { s->failed_pc=0x0c086554u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c086556;
P_0c086556: /* original 6af6, guest PC 0x0c086556 */
if(!s->budget--) { s->failed_pc=0x0c086556u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c086558;
P_0c086558: /* original 6bf6, guest PC 0x0c086558 */
if(!s->budget--) { s->failed_pc=0x0c086558u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08655a;
P_0c08655a: /* original 6cf6, guest PC 0x0c08655a */
if(!s->budget--) { s->failed_pc=0x0c08655au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08655c;
P_0c08655c: /* original 6df6, guest PC 0x0c08655c */
if(!s->budget--) { s->failed_pc=0x0c08655cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08655e;
P_0c08655e: /* original 000b, guest PC 0x0c08655e */
if(!s->budget--) { s->failed_pc=0x0c08655eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086560: /* original 6ef6, guest PC 0x0c086560 */
if(!s->budget--) { s->failed_pc=0x0c086560u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c086562;
P_0c086562: /* original 2fe6, guest PC 0x0c086562 */
if(!s->budget--) { s->failed_pc=0x0c086562u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086564;
P_0c086564: /* original 6e63, guest PC 0x0c086564 */
if(!s->budget--) { s->failed_pc=0x0c086564u; return 0; }
r[14]=r[6];
goto P_0c086566;
P_0c086566: /* original e3fa, guest PC 0x0c086566 */
if(!s->budget--) { s->failed_pc=0x0c086566u; return 0; }
r[3]=0xfffffffau;
goto P_0c086568;
P_0c086568: /* original 7ffc, guest PC 0x0c086568 */
if(!s->budget--) { s->failed_pc=0x0c086568u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08656a;
P_0c08656a: /* original 2f42, guest PC 0x0c08656a */
if(!s->budget--) { s->failed_pc=0x0c08656au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c08656c;
P_0c08656c: /* original e401, guest PC 0x0c08656c */
if(!s->budget--) { s->failed_pc=0x0c08656cu; return 0; }
r[4]=0x00000001u;
goto P_0c08656e;
P_0c08656e: /* original 9088, guest PC 0x0c08656e */
if(!s->budget--) { s->failed_pc=0x0c08656eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086682u,2);
goto P_0c086570;
P_0c086570: /* original 02ee, guest PC 0x0c086570 */
if(!s->budget--) { s->failed_pc=0x0c086570u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c086572;
P_0c086572: /* original 2239, guest PC 0x0c086572 */
if(!s->budget--) { s->failed_pc=0x0c086572u; return 0; }
r[2]&=r[3];
goto P_0c086574;
P_0c086574: /* original 0e26, guest PC 0x0c086574 */
if(!s->budget--) { s->failed_pc=0x0c086574u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c086576;
P_0c086576: /* original e202, guest PC 0x0c086576 */
if(!s->budget--) { s->failed_pc=0x0c086576u; return 0; }
r[2]=0x00000002u;
goto P_0c086578;
P_0c086578: /* original 01ee, guest PC 0x0c086578 */
if(!s->budget--) { s->failed_pc=0x0c086578u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c08657a;
P_0c08657a: /* original 212b, guest PC 0x0c08657a */
if(!s->budget--) { s->failed_pc=0x0c08657au; return 0; }
r[1]|=r[2];
goto P_0c08657c;
P_0c08657c: /* original 0e16, guest PC 0x0c08657c */
if(!s->budget--) { s->failed_pc=0x0c08657cu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c08657e;
P_0c08657e: /* original 9081, guest PC 0x0c08657e */
if(!s->budget--) { s->failed_pc=0x0c08657eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086684u,2);
goto P_0c086580;
P_0c086580: /* original f3e6, guest PC 0x0c086580 */
if(!s->budget--) { s->failed_pc=0x0c086580u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086582;
P_0c086582: /* original e004, guest PC 0x0c086582 */
if(!s->budget--) { s->failed_pc=0x0c086582u; return 0; }
r[0]=0x00000004u;
goto P_0c086584;
P_0c086584: /* original f537, guest PC 0x0c086584 */
if(!s->budget--) { s->failed_pc=0x0c086584u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c086586;
P_0c086586: /* original 907e, guest PC 0x0c086586 */
if(!s->budget--) { s->failed_pc=0x0c086586u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086686u,2);
goto P_0c086588;
P_0c086588: /* original f3e6, guest PC 0x0c086588 */
if(!s->budget--) { s->failed_pc=0x0c086588u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08658a;
P_0c08658a: /* original e008, guest PC 0x0c08658a */
if(!s->budget--) { s->failed_pc=0x0c08658au; return 0; }
r[0]=0x00000008u;
goto P_0c08658c;
P_0c08658c: /* original f537, guest PC 0x0c08658c */
if(!s->budget--) { s->failed_pc=0x0c08658cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c08658e;
P_0c08658e: /* original 907b, guest PC 0x0c08658e */
if(!s->budget--) { s->failed_pc=0x0c08658eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086688u,2);
goto P_0c086590;
P_0c086590: /* original f3e6, guest PC 0x0c086590 */
if(!s->budget--) { s->failed_pc=0x0c086590u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086592;
P_0c086592: /* original e00c, guest PC 0x0c086592 */
if(!s->budget--) { s->failed_pc=0x0c086592u; return 0; }
r[0]=0x0000000cu;
goto P_0c086594;
P_0c086594: /* original f537, guest PC 0x0c086594 */
if(!s->budget--) { s->failed_pc=0x0c086594u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c086596;
P_0c086596: /* original e024, guest PC 0x0c086596 */
if(!s->budget--) { s->failed_pc=0x0c086596u; return 0; }
r[0]=0x00000024u;
goto P_0c086598;
P_0c086598: /* original 0545, guest PC 0x0c086598 */
if(!s->budget--) { s->failed_pc=0x0c086598u; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c08659a;
P_0c08659a: /* original e026, guest PC 0x0c08659a */
if(!s->budget--) { s->failed_pc=0x0c08659au; return 0; }
r[0]=0x00000026u;
goto P_0c08659c;
P_0c08659c: /* original 0545, guest PC 0x0c08659c */
if(!s->budget--) { s->failed_pc=0x0c08659cu; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c08659e;
P_0c08659e: /* original e028, guest PC 0x0c08659e */
if(!s->budget--) { s->failed_pc=0x0c08659eu; return 0; }
r[0]=0x00000028u;
goto P_0c0865a0;
P_0c0865a0: /* original 0545, guest PC 0x0c0865a0 */
if(!s->budget--) { s->failed_pc=0x0c0865a0u; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c0865a2;
P_0c0865a2: /* original e300, guest PC 0x0c0865a2 */
if(!s->budget--) { s->failed_pc=0x0c0865a2u; return 0; }
r[3]=0x00000000u;
goto P_0c0865a4;
P_0c0865a4: /* original 66e3, guest PC 0x0c0865a4 */
if(!s->budget--) { s->failed_pc=0x0c0865a4u; return 0; }
r[6]=r[14];
goto P_0c0865a6;
P_0c0865a6: /* original 153e, guest PC 0x0c0865a6 */
if(!s->budget--) { s->failed_pc=0x0c0865a6u; return 0; }
write(ram,r[5]+56,r[3],4);
goto P_0c0865a8;
P_0c0865a8: /* original 64f2, guest PC 0x0c0865a8 */
if(!s->budget--) { s->failed_pc=0x0c0865a8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0865aa;
P_0c0865aa: /* original 7f04, guest PC 0x0c0865aa */
if(!s->budget--) { s->failed_pc=0x0c0865aau; return 0; }
r[15]+=0x00000004u;
goto P_0c0865ac;
P_0c0865ac: /* original a12d, guest PC 0x0c0865ac */
if(!s->budget--) { s->failed_pc=0x0c0865acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08680au,s,ram);
P_0c0865ae: /* original 6ef6, guest PC 0x0c0865ae */
if(!s->budget--) { s->failed_pc=0x0c0865aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0865b0;
P_0c0865b0: /* original 9068, guest PC 0x0c0865b0 */
if(!s->budget--) { s->failed_pc=0x0c0865b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086684u,2);
goto P_0c0865b2;
P_0c0865b2: /* original 6463, guest PC 0x0c0865b2 */
if(!s->budget--) { s->failed_pc=0x0c0865b2u; return 0; }
r[4]=r[6];
goto P_0c0865b4;
P_0c0865b4: /* original f346, guest PC 0x0c0865b4 */
if(!s->budget--) { s->failed_pc=0x0c0865b4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0865b6;
P_0c0865b6: /* original e004, guest PC 0x0c0865b6 */
if(!s->budget--) { s->failed_pc=0x0c0865b6u; return 0; }
r[0]=0x00000004u;
goto P_0c0865b8;
P_0c0865b8: /* original f537, guest PC 0x0c0865b8 */
if(!s->budget--) { s->failed_pc=0x0c0865b8u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0865ba;
P_0c0865ba: /* original c734, guest PC 0x0c0865ba */
if(!s->budget--) { s->failed_pc=0x0c0865bau; return 0; }
r[0]=code_base|0x0008668cu;
goto P_0c0865bc;
P_0c0865bc: /* original f308, guest PC 0x0c0865bc */
if(!s->budget--) { s->failed_pc=0x0c0865bcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0865be;
P_0c0865be: /* original 9062, guest PC 0x0c0865be */
if(!s->budget--) { s->failed_pc=0x0c0865beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086686u,2);
goto P_0c0865c0;
P_0c0865c0: /* original f246, guest PC 0x0c0865c0 */
if(!s->budget--) { s->failed_pc=0x0c0865c0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0865c2;
P_0c0865c2: /* original e008, guest PC 0x0c0865c2 */
if(!s->budget--) { s->failed_pc=0x0c0865c2u; return 0; }
r[0]=0x00000008u;
goto P_0c0865c4;
P_0c0865c4: /* original f230, guest PC 0x0c0865c4 */
if(!s->budget--) { s->failed_pc=0x0c0865c4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0865c6;
P_0c0865c6: /* original f527, guest PC 0x0c0865c6 */
if(!s->budget--) { s->failed_pc=0x0c0865c6u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0865c8;
P_0c0865c8: /* original 905e, guest PC 0x0c0865c8 */
if(!s->budget--) { s->failed_pc=0x0c0865c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086688u,2);
goto P_0c0865ca;
P_0c0865ca: /* original f246, guest PC 0x0c0865ca */
if(!s->budget--) { s->failed_pc=0x0c0865cau; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0865cc;
P_0c0865cc: /* original e00c, guest PC 0x0c0865cc */
if(!s->budget--) { s->failed_pc=0x0c0865ccu; return 0; }
r[0]=0x0000000cu;
goto P_0c0865ce;
P_0c0865ce: /* original 000b, guest PC 0x0c0865ce */
if(!s->budget--) { s->failed_pc=0x0c0865ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[5]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0865d0: /* original f527, guest PC 0x0c0865d0 */
if(!s->budget--) { s->failed_pc=0x0c0865d0u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0865d2;
P_0c0865d2: /* original 2fe6, guest PC 0x0c0865d2 */
if(!s->budget--) { s->failed_pc=0x0c0865d2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0865d4;
P_0c0865d4: /* original 6e53, guest PC 0x0c0865d4 */
if(!s->budget--) { s->failed_pc=0x0c0865d4u; return 0; }
r[14]=r[5];
goto P_0c0865d6;
P_0c0865d6: /* original 4f22, guest PC 0x0c0865d6 */
if(!s->budget--) { s->failed_pc=0x0c0865d6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0865d8;
P_0c0865d8: /* original 7ff8, guest PC 0x0c0865d8 */
if(!s->budget--) { s->failed_pc=0x0c0865d8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0865da;
P_0c0865da: /* original 1f41, guest PC 0x0c0865da */
if(!s->budget--) { s->failed_pc=0x0c0865dau; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0865dc;
P_0c0865dc: /* original 2f62, guest PC 0x0c0865dc */
if(!s->budget--) { s->failed_pc=0x0c0865dcu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0865de;
P_0c0865de: /* original d32c, guest PC 0x0c0865de */
if(!s->budget--) { s->failed_pc=0x0c0865deu; return 0; }
r[3]=read(ram,0x0c086690u,4);
goto P_0c0865e0;
P_0c0865e0: /* original 430b, guest PC 0x0c0865e0 */
if(!s->budget--) { s->failed_pc=0x0c0865e0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0865e4u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0865e4u) { target=s->pc; goto dispatch; }
goto P_0c0865e4;
P_0c0865e2: /* original 6453, guest PC 0x0c0865e2 */
if(!s->budget--) { s->failed_pc=0x0c0865e2u; return 0; }
r[4]=r[5];
goto P_0c0865e4;
P_0c0865e4: /* original 54f1, guest PC 0x0c0865e4 */
if(!s->budget--) { s->failed_pc=0x0c0865e4u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0865e6;
P_0c0865e6: /* original 65e3, guest PC 0x0c0865e6 */
if(!s->budget--) { s->failed_pc=0x0c0865e6u; return 0; }
r[5]=r[14];
goto P_0c0865e8;
P_0c0865e8: /* original 66f2, guest PC 0x0c0865e8 */
if(!s->budget--) { s->failed_pc=0x0c0865e8u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0865ea;
P_0c0865ea: /* original 7f08, guest PC 0x0c0865ea */
if(!s->budget--) { s->failed_pc=0x0c0865eau; return 0; }
r[15]+=0x00000008u;
goto P_0c0865ec;
P_0c0865ec: /* original 4f26, guest PC 0x0c0865ec */
if(!s->budget--) { s->failed_pc=0x0c0865ecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0865ee;
P_0c0865ee: /* original a0b6, guest PC 0x0c0865ee */
if(!s->budget--) { s->failed_pc=0x0c0865eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08675eu,s,ram);
P_0c0865f0: /* original 6ef6, guest PC 0x0c0865f0 */
if(!s->budget--) { s->failed_pc=0x0c0865f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0865f2;
P_0c0865f2: /* original 2fe6, guest PC 0x0c0865f2 */
if(!s->budget--) { s->failed_pc=0x0c0865f2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0865f4;
P_0c0865f4: /* original e004, guest PC 0x0c0865f4 */
if(!s->budget--) { s->failed_pc=0x0c0865f4u; return 0; }
r[0]=0x00000004u;
goto P_0c0865f6;
P_0c0865f6: /* original 2fd6, guest PC 0x0c0865f6 */
if(!s->budget--) { s->failed_pc=0x0c0865f6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0865f8;
P_0c0865f8: /* original 6e53, guest PC 0x0c0865f8 */
if(!s->budget--) { s->failed_pc=0x0c0865f8u; return 0; }
r[14]=r[5];
goto P_0c0865fa;
P_0c0865fa: /* original 2fc6, guest PC 0x0c0865fa */
if(!s->budget--) { s->failed_pc=0x0c0865fau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0865fc;
P_0c0865fc: /* original 6c43, guest PC 0x0c0865fc */
if(!s->budget--) { s->failed_pc=0x0c0865fcu; return 0; }
r[12]=r[4];
goto P_0c0865fe;
P_0c0865fe: /* original fffb, guest PC 0x0c0865fe */
if(!s->budget--) { s->failed_pc=0x0c0865feu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c086600;
P_0c086600: /* original 6d63, guest PC 0x0c086600 */
if(!s->budget--) { s->failed_pc=0x0c086600u; return 0; }
r[13]=r[6];
goto P_0c086602;
P_0c086602: /* original ffeb, guest PC 0x0c086602 */
if(!s->budget--) { s->failed_pc=0x0c086602u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c086604;
P_0c086604: /* original ffdb, guest PC 0x0c086604 */
if(!s->budget--) { s->failed_pc=0x0c086604u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c086606;
P_0c086606: /* original ffe6, guest PC 0x0c086606 */
if(!s->budget--) { s->failed_pc=0x0c086606u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c086608;
P_0c086608: /* original e008, guest PC 0x0c086608 */
if(!s->budget--) { s->failed_pc=0x0c086608u; return 0; }
r[0]=0x00000008u;
goto P_0c08660a;
P_0c08660a: /* original fde6, guest PC 0x0c08660a */
if(!s->budget--) { s->failed_pc=0x0c08660au; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c08660c;
P_0c08660c: /* original e00c, guest PC 0x0c08660c */
if(!s->budget--) { s->failed_pc=0x0c08660cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08660e;
P_0c08660e: /* original d721, guest PC 0x0c08660e */
if(!s->budget--) { s->failed_pc=0x0c08660eu; return 0; }
r[7]=read(ram,0x0c086694u,4);
goto P_0c086610;
P_0c086610: /* original fee6, guest PC 0x0c086610 */
if(!s->budget--) { s->failed_pc=0x0c086610u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c086612;
P_0c086612: /* original e048, guest PC 0x0c086612 */
if(!s->budget--) { s->failed_pc=0x0c086612u; return 0; }
r[0]=0x00000048u;
goto P_0c086614;
P_0c086614: /* original f378, guest PC 0x0c086614 */
if(!s->budget--) { s->failed_pc=0x0c086614u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c086616;
P_0c086616: /* original f2e6, guest PC 0x0c086616 */
if(!s->budget--) { s->failed_pc=0x0c086616u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c086618;
P_0c086618: /* original 4f22, guest PC 0x0c086618 */
if(!s->budget--) { s->failed_pc=0x0c086618u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08661a;
P_0c08661a: /* original f231, guest PC 0x0c08661a */
if(!s->budget--) { s->failed_pc=0x0c08661au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c08661c;
P_0c08661c: /* original fe27, guest PC 0x0c08661c */
if(!s->budget--) { s->failed_pc=0x0c08661cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c08661e;
P_0c08661e: /* original e044, guest PC 0x0c08661e */
if(!s->budget--) { s->failed_pc=0x0c08661eu; return 0; }
r[0]=0x00000044u;
goto P_0c086620;
P_0c086620: /* original f3e6, guest PC 0x0c086620 */
if(!s->budget--) { s->failed_pc=0x0c086620u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086622;
P_0c086622: /* original e04c, guest PC 0x0c086622 */
if(!s->budget--) { s->failed_pc=0x0c086622u; return 0; }
r[0]=0x0000004cu;
goto P_0c086624;
P_0c086624: /* original ff30, guest PC 0x0c086624 */
if(!s->budget--) { s->failed_pc=0x0c086624u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c086626;
P_0c086626: /* original f3e6, guest PC 0x0c086626 */
if(!s->budget--) { s->failed_pc=0x0c086626u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086628;
P_0c086628: /* original e048, guest PC 0x0c086628 */
if(!s->budget--) { s->failed_pc=0x0c086628u; return 0; }
r[0]=0x00000048u;
goto P_0c08662a;
P_0c08662a: /* original fe30, guest PC 0x0c08662a */
if(!s->budget--) { s->failed_pc=0x0c08662au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'+');
goto P_0c08662c;
P_0c08662c: /* original f3e6, guest PC 0x0c08662c */
if(!s->budget--) { s->failed_pc=0x0c08662cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08662e;
P_0c08662e: /* original fd30, guest PC 0x0c08662e */
if(!s->budget--) { s->failed_pc=0x0c08662eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c086630;
P_0c086630: /* original f5ec, guest PC 0x0c086630 */
if(!s->budget--) { s->failed_pc=0x0c086630u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c086632;
P_0c086632: /* original d319, guest PC 0x0c086632 */
if(!s->budget--) { s->failed_pc=0x0c086632u; return 0; }
r[3]=read(ram,0x0c086698u,4);
goto P_0c086634;
P_0c086634: /* original f54d, guest PC 0x0c086634 */
if(!s->budget--) { s->failed_pc=0x0c086634u; return 0; }
fr[5]^=0x80000000u;
goto P_0c086636;
P_0c086636: /* original 430b, guest PC 0x0c086636 */
if(!s->budget--) { s->failed_pc=0x0c086636u; return 0; }
target=r[3];
r[16]=code_base|0x0c08663au;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08663au) { target=s->pc; goto dispatch; }
goto P_0c08663a;
P_0c086638: /* original f4fc, guest PC 0x0c086638 */
if(!s->budget--) { s->failed_pc=0x0c086638u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08663a;
P_0c08663a: /* original e060, guest PC 0x0c08663a */
if(!s->budget--) { s->failed_pc=0x0c08663au; return 0; }
r[0]=0x00000060u;
goto P_0c08663c;
P_0c08663c: /* original d517, guest PC 0x0c08663c */
if(!s->budget--) { s->failed_pc=0x0c08663cu; return 0; }
r[5]=read(ram,0x0c08669cu,4);
goto P_0c08663e;
P_0c08663e: /* original 00dc, guest PC 0x0c08663e */
if(!s->budget--) { s->failed_pc=0x0c08663eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086640;
P_0c086640: /* original f40c, guest PC 0x0c086640 */
if(!s->budget--) { s->failed_pc=0x0c086640u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c086642;
P_0c086642: /* original 600c, guest PC 0x0c086642 */
if(!s->budget--) { s->failed_pc=0x0c086642u; return 0; }
r[0]=r[0]&255u;
goto P_0c086644;
P_0c086644: /* original 4008, guest PC 0x0c086644 */
if(!s->budget--) { s->failed_pc=0x0c086644u; return 0; }
r[0]<<=2;
goto P_0c086646;
P_0c086646: /* original f356, guest PC 0x0c086646 */
if(!s->budget--) { s->failed_pc=0x0c086646u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c086648;
P_0c086648: /* original f430, guest PC 0x0c086648 */
if(!s->budget--) { s->failed_pc=0x0c086648u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c08664a;
P_0c08664a: /* original fd45, guest PC 0x0c08664a */
if(!s->budget--) { s->failed_pc=0x0c08664au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[4]))!=0);
goto P_0c08664c;
P_0c08664c: /* original 8f28, guest PC 0x0c08664c */
if(!s->budget--) { s->failed_pc=0x0c08664cu; return 0; }
cond=r[17]&1u;
r[4]=0x00000001u;
if(!cond) { goto P_0c0866a0; }
goto P_0c086650;
P_0c08664e: /* original e401, guest PC 0x0c08664e */
if(!s->budget--) { s->failed_pc=0x0c08664eu; return 0; }
r[4]=0x00000001u;
goto P_0c086650;
P_0c086650: /* original 53ee, guest PC 0x0c086650 */
if(!s->budget--) { s->failed_pc=0x0c086650u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c086652;
P_0c086652: /* original 2438, guest PC 0x0c086652 */
if(!s->budget--) { s->failed_pc=0x0c086652u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c086654;
P_0c086654: /* original 8b71, guest PC 0x0c086654 */
if(!s->budget--) { s->failed_pc=0x0c086654u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08673a; }
goto P_0c086656;
P_0c086656: /* original e32a, guest PC 0x0c086656 */
if(!s->budget--) { s->failed_pc=0x0c086656u; return 0; }
r[3]=0x0000002au;
goto P_0c086658;
P_0c086658: /* original 33ec, guest PC 0x0c086658 */
if(!s->budget--) { s->failed_pc=0x0c086658u; return 0; }
r[3]+=r[14];
goto P_0c08665a;
P_0c08665a: /* original e024, guest PC 0x0c08665a */
if(!s->budget--) { s->failed_pc=0x0c08665au; return 0; }
r[0]=0x00000024u;
goto P_0c08665c;
P_0c08665c: /* original 6331, guest PC 0x0c08665c */
if(!s->budget--) { s->failed_pc=0x0c08665cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c08665e;
P_0c08665e: /* original 02ed, guest PC 0x0c08665e */
if(!s->budget--) { s->failed_pc=0x0c08665eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c086660;
P_0c086660: /* original 323c, guest PC 0x0c086660 */
if(!s->budget--) { s->failed_pc=0x0c086660u; return 0; }
r[2]+=r[3];
goto P_0c086662;
P_0c086662: /* original e32c, guest PC 0x0c086662 */
if(!s->budget--) { s->failed_pc=0x0c086662u; return 0; }
r[3]=0x0000002cu;
goto P_0c086664;
P_0c086664: /* original 0e25, guest PC 0x0c086664 */
if(!s->budget--) { s->failed_pc=0x0c086664u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c086666;
P_0c086666: /* original 33ec, guest PC 0x0c086666 */
if(!s->budget--) { s->failed_pc=0x0c086666u; return 0; }
r[3]+=r[14];
goto P_0c086668;
P_0c086668: /* original e026, guest PC 0x0c086668 */
if(!s->budget--) { s->failed_pc=0x0c086668u; return 0; }
r[0]=0x00000026u;
goto P_0c08666a;
P_0c08666a: /* original 6331, guest PC 0x0c08666a */
if(!s->budget--) { s->failed_pc=0x0c08666au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c08666c;
P_0c08666c: /* original 02ed, guest PC 0x0c08666c */
if(!s->budget--) { s->failed_pc=0x0c08666cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08666e;
P_0c08666e: /* original 323c, guest PC 0x0c08666e */
if(!s->budget--) { s->failed_pc=0x0c08666eu; return 0; }
r[2]+=r[3];
goto P_0c086670;
P_0c086670: /* original e32e, guest PC 0x0c086670 */
if(!s->budget--) { s->failed_pc=0x0c086670u; return 0; }
r[3]=0x0000002eu;
goto P_0c086672;
P_0c086672: /* original 0e25, guest PC 0x0c086672 */
if(!s->budget--) { s->failed_pc=0x0c086672u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c086674;
P_0c086674: /* original 33ec, guest PC 0x0c086674 */
if(!s->budget--) { s->failed_pc=0x0c086674u; return 0; }
r[3]+=r[14];
goto P_0c086676;
P_0c086676: /* original e028, guest PC 0x0c086676 */
if(!s->budget--) { s->failed_pc=0x0c086676u; return 0; }
r[0]=0x00000028u;
goto P_0c086678;
P_0c086678: /* original 6331, guest PC 0x0c086678 */
if(!s->budget--) { s->failed_pc=0x0c086678u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c08667a;
P_0c08667a: /* original 02ed, guest PC 0x0c08667a */
if(!s->budget--) { s->failed_pc=0x0c08667au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08667c;
P_0c08667c: /* original 323c, guest PC 0x0c08667c */
if(!s->budget--) { s->failed_pc=0x0c08667cu; return 0; }
r[2]+=r[3];
goto P_0c08667e;
P_0c08667e: /* original a060, guest PC 0x0c08667e */
if(!s->budget--) { s->failed_pc=0x0c08667eu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c086742;
P_0c086680: /* original 0e25, guest PC 0x0c086680 */
if(!s->budget--) { s->failed_pc=0x0c086680u; return 0; }
write(ram,r[14]+r[0],r[2],2);
if(!vf3_matrix_family(0x0c086682u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c086682u; return 0; } return 1;
P_0c0866a0: /* original e114, guest PC 0x0c0866a0 */
if(!s->budget--) { s->failed_pc=0x0c0866a0u; return 0; }
r[1]=0x00000014u;
goto P_0c0866a2;
P_0c0866a2: /* original fd4c, guest PC 0x0c0866a2 */
if(!s->budget--) { s->failed_pc=0x0c0866a2u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c0866a4;
P_0c0866a4: /* original 31cc, guest PC 0x0c0866a4 */
if(!s->budget--) { s->failed_pc=0x0c0866a4u; return 0; }
r[1]+=r[12];
goto P_0c0866a6;
P_0c0866a6: /* original e044, guest PC 0x0c0866a6 */
if(!s->budget--) { s->failed_pc=0x0c0866a6u; return 0; }
r[0]=0x00000044u;
goto P_0c0866a8;
P_0c0866a8: /* original f318, guest PC 0x0c0866a8 */
if(!s->budget--) { s->failed_pc=0x0c0866a8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0866aa;
P_0c0866aa: /* original f2e6, guest PC 0x0c0866aa */
if(!s->budget--) { s->failed_pc=0x0c0866aau; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0866ac;
P_0c0866ac: /* original e110, guest PC 0x0c0866ac */
if(!s->budget--) { s->failed_pc=0x0c0866acu; return 0; }
r[1]=0x00000010u;
goto P_0c0866ae;
P_0c0866ae: /* original 31cc, guest PC 0x0c0866ae */
if(!s->budget--) { s->failed_pc=0x0c0866aeu; return 0; }
r[1]+=r[12];
goto P_0c0866b0;
P_0c0866b0: /* original f232, guest PC 0x0c0866b0 */
if(!s->budget--) { s->failed_pc=0x0c0866b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0866b2;
P_0c0866b2: /* original fe27, guest PC 0x0c0866b2 */
if(!s->budget--) { s->failed_pc=0x0c0866b2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0866b4;
P_0c0866b4: /* original e048, guest PC 0x0c0866b4 */
if(!s->budget--) { s->failed_pc=0x0c0866b4u; return 0; }
r[0]=0x00000048u;
goto P_0c0866b6;
P_0c0866b6: /* original f2e6, guest PC 0x0c0866b6 */
if(!s->budget--) { s->failed_pc=0x0c0866b6u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0866b8;
P_0c0866b8: /* original f318, guest PC 0x0c0866b8 */
if(!s->budget--) { s->failed_pc=0x0c0866b8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0866ba;
P_0c0866ba: /* original f232, guest PC 0x0c0866ba */
if(!s->budget--) { s->failed_pc=0x0c0866bau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0866bc;
P_0c0866bc: /* original fe27, guest PC 0x0c0866bc */
if(!s->budget--) { s->failed_pc=0x0c0866bcu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0866be;
P_0c0866be: /* original d140, guest PC 0x0c0866be */
if(!s->budget--) { s->failed_pc=0x0c0866beu; return 0; }
r[1]=read(ram,0x0c0867c0u,4);
goto P_0c0866c0;
P_0c0866c0: /* original 415a, guest PC 0x0c0866c0 */
if(!s->budget--) { s->failed_pc=0x0c0866c0u; return 0; }
r[53]=r[1];
goto P_0c0866c2;
P_0c0866c2: /* original e114, guest PC 0x0c0866c2 */
if(!s->budget--) { s->failed_pc=0x0c0866c2u; return 0; }
r[1]=0x00000014u;
goto P_0c0866c4;
P_0c0866c4: /* original 31cc, guest PC 0x0c0866c4 */
if(!s->budget--) { s->failed_pc=0x0c0866c4u; return 0; }
r[1]+=r[12];
goto P_0c0866c6;
P_0c0866c6: /* original f30d, guest PC 0x0c0866c6 */
if(!s->budget--) { s->failed_pc=0x0c0866c6u; return 0; }
fr[3]=r[53];
goto P_0c0866c8;
P_0c0866c8: /* original f232, guest PC 0x0c0866c8 */
if(!s->budget--) { s->failed_pc=0x0c0866c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0866ca;
P_0c0866ca: /* original fe27, guest PC 0x0c0866ca */
if(!s->budget--) { s->failed_pc=0x0c0866cau; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0866cc;
P_0c0866cc: /* original e04c, guest PC 0x0c0866cc */
if(!s->budget--) { s->failed_pc=0x0c0866ccu; return 0; }
r[0]=0x0000004cu;
goto P_0c0866ce;
P_0c0866ce: /* original f1e6, guest PC 0x0c0866ce */
if(!s->budget--) { s->failed_pc=0x0c0866ceu; return 0; }
vf3_matrix_load(s,ram,1,r[14]+r[0]);
goto P_0c0866d0;
P_0c0866d0: /* original f218, guest PC 0x0c0866d0 */
if(!s->budget--) { s->failed_pc=0x0c0866d0u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0866d2;
P_0c0866d2: /* original f122, guest PC 0x0c0866d2 */
if(!s->budget--) { s->failed_pc=0x0c0866d2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0866d4;
P_0c0866d4: /* original fe17, guest PC 0x0c0866d4 */
if(!s->budget--) { s->failed_pc=0x0c0866d4u; return 0; }
vf3_matrix_store(s,ram,1,r[14]+r[0]);
goto P_0c0866d6;
P_0c0866d6: /* original c73b, guest PC 0x0c0866d6 */
if(!s->budget--) { s->failed_pc=0x0c0866d6u; return 0; }
r[0]=code_base|0x000867c4u;
goto P_0c0866d8;
P_0c0866d8: /* original f408, guest PC 0x0c0866d8 */
if(!s->budget--) { s->failed_pc=0x0c0866d8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0866da;
P_0c0866da: /* original e044, guest PC 0x0c0866da */
if(!s->budget--) { s->failed_pc=0x0c0866dau; return 0; }
r[0]=0x00000044u;
goto P_0c0866dc;
P_0c0866dc: /* original f2e6, guest PC 0x0c0866dc */
if(!s->budget--) { s->failed_pc=0x0c0866dcu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0866de;
P_0c0866de: /* original f245, guest PC 0x0c0866de */
if(!s->budget--) { s->failed_pc=0x0c0866deu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0866e0;
P_0c0866e0: /* original 8921, guest PC 0x0c0866e0 */
if(!s->budget--) { s->failed_pc=0x0c0866e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086726; }
goto P_0c0866e2;
P_0c0866e2: /* original e048, guest PC 0x0c0866e2 */
if(!s->budget--) { s->failed_pc=0x0c0866e2u; return 0; }
r[0]=0x00000048u;
goto P_0c0866e4;
P_0c0866e4: /* original f3e6, guest PC 0x0c0866e4 */
if(!s->budget--) { s->failed_pc=0x0c0866e4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0866e6;
P_0c0866e6: /* original f345, guest PC 0x0c0866e6 */
if(!s->budget--) { s->failed_pc=0x0c0866e6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0866e8;
P_0c0866e8: /* original 891d, guest PC 0x0c0866e8 */
if(!s->budget--) { s->failed_pc=0x0c0866e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086726; }
goto P_0c0866ea;
P_0c0866ea: /* original e04c, guest PC 0x0c0866ea */
if(!s->budget--) { s->failed_pc=0x0c0866eau; return 0; }
r[0]=0x0000004cu;
goto P_0c0866ec;
P_0c0866ec: /* original f3e6, guest PC 0x0c0866ec */
if(!s->budget--) { s->failed_pc=0x0c0866ecu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0866ee;
P_0c0866ee: /* original f345, guest PC 0x0c0866ee */
if(!s->budget--) { s->failed_pc=0x0c0866eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0866f0;
P_0c0866f0: /* original 8919, guest PC 0x0c0866f0 */
if(!s->budget--) { s->failed_pc=0x0c0866f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086726; }
goto P_0c0866f2;
P_0c0866f2: /* original 9062, guest PC 0x0c0866f2 */
if(!s->budget--) { s->failed_pc=0x0c0866f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0867bau,2);
goto P_0c0866f4;
P_0c0866f4: /* original e3fc, guest PC 0x0c0866f4 */
if(!s->budget--) { s->failed_pc=0x0c0866f4u; return 0; }
r[3]=0xfffffffcu;
goto P_0c0866f6;
P_0c0866f6: /* original 02de, guest PC 0x0c0866f6 */
if(!s->budget--) { s->failed_pc=0x0c0866f6u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0866f8;
P_0c0866f8: /* original 2239, guest PC 0x0c0866f8 */
if(!s->budget--) { s->failed_pc=0x0c0866f8u; return 0; }
r[2]&=r[3];
goto P_0c0866fa;
P_0c0866fa: /* original 0d26, guest PC 0x0c0866fa */
if(!s->budget--) { s->failed_pc=0x0c0866fau; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c0866fc;
P_0c0866fc: /* original e204, guest PC 0x0c0866fc */
if(!s->budget--) { s->failed_pc=0x0c0866fcu; return 0; }
r[2]=0x00000004u;
goto P_0c0866fe;
P_0c0866fe: /* original 01de, guest PC 0x0c0866fe */
if(!s->budget--) { s->failed_pc=0x0c0866feu; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c086700;
P_0c086700: /* original 212b, guest PC 0x0c086700 */
if(!s->budget--) { s->failed_pc=0x0c086700u; return 0; }
r[1]|=r[2];
goto P_0c086702;
P_0c086702: /* original 0d16, guest PC 0x0c086702 */
if(!s->budget--) { s->failed_pc=0x0c086702u; return 0; }
write(ram,r[13]+r[0],r[1],4);
goto P_0c086704;
P_0c086704: /* original e060, guest PC 0x0c086704 */
if(!s->budget--) { s->failed_pc=0x0c086704u; return 0; }
r[0]=0x00000060u;
goto P_0c086706;
P_0c086706: /* original 00dc, guest PC 0x0c086706 */
if(!s->budget--) { s->failed_pc=0x0c086706u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086708;
P_0c086708: /* original 600c, guest PC 0x0c086708 */
if(!s->budget--) { s->failed_pc=0x0c086708u; return 0; }
r[0]=r[0]&255u;
goto P_0c08670a;
P_0c08670a: /* original 4008, guest PC 0x0c08670a */
if(!s->budget--) { s->failed_pc=0x0c08670au; return 0; }
r[0]<<=2;
goto P_0c08670c;
P_0c08670c: /* original f356, guest PC 0x0c08670c */
if(!s->budget--) { s->failed_pc=0x0c08670cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08670e;
P_0c08670e: /* original e014, guest PC 0x0c08670e */
if(!s->budget--) { s->failed_pc=0x0c08670eu; return 0; }
r[0]=0x00000014u;
goto P_0c086710;
P_0c086710: /* original f34d, guest PC 0x0c086710 */
if(!s->budget--) { s->failed_pc=0x0c086710u; return 0; }
fr[3]^=0x80000000u;
goto P_0c086712;
P_0c086712: /* original fe37, guest PC 0x0c086712 */
if(!s->budget--) { s->failed_pc=0x0c086712u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c086714;
P_0c086714: /* original c72c, guest PC 0x0c086714 */
if(!s->budget--) { s->failed_pc=0x0c086714u; return 0; }
r[0]=code_base|0x000867c8u;
goto P_0c086716;
P_0c086716: /* original f308, guest PC 0x0c086716 */
if(!s->budget--) { s->failed_pc=0x0c086716u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c086718;
P_0c086718: /* original e01c, guest PC 0x0c086718 */
if(!s->budget--) { s->failed_pc=0x0c086718u; return 0; }
r[0]=0x0000001cu;
goto P_0c08671a;
P_0c08671a: /* original fe37, guest PC 0x0c08671a */
if(!s->budget--) { s->failed_pc=0x0c08671au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08671c;
P_0c08671c: /* original d32b, guest PC 0x0c08671c */
if(!s->budget--) { s->failed_pc=0x0c08671cu; return 0; }
r[3]=read(ram,0x0c0867ccu,4);
goto P_0c08671e;
P_0c08671e: /* original 430b, guest PC 0x0c08671e */
if(!s->budget--) { s->failed_pc=0x0c08671eu; return 0; }
target=r[3];
r[16]=code_base|0x0c086722u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086722u) { target=s->pc; goto dispatch; }
goto P_0c086722;
P_0c086720: /* original 64e3, guest PC 0x0c086720 */
if(!s->budget--) { s->failed_pc=0x0c086720u; return 0; }
r[4]=r[14];
goto P_0c086722;
P_0c086722: /* original a00a, guest PC 0x0c086722 */
if(!s->budget--) { s->failed_pc=0x0c086722u; return 0; }
goto P_0c08673a;
P_0c086724: /* original 0009, guest PC 0x0c086724 */
if(!s->budget--) { s->failed_pc=0x0c086724u; return 0; }
goto P_0c086726;
P_0c086726: /* original 53ee, guest PC 0x0c086726 */
if(!s->budget--) { s->failed_pc=0x0c086726u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c086728;
P_0c086728: /* original 2348, guest PC 0x0c086728 */
if(!s->budget--) { s->failed_pc=0x0c086728u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c08672a;
P_0c08672a: /* original 8b06, guest PC 0x0c08672a */
if(!s->budget--) { s->failed_pc=0x0c08672au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08673a; }
goto P_0c08672c;
P_0c08672c: /* original 52ee, guest PC 0x0c08672c */
if(!s->budget--) { s->failed_pc=0x0c08672cu; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c08672e;
P_0c08672e: /* original 65e3, guest PC 0x0c08672e */
if(!s->budget--) { s->failed_pc=0x0c08672eu; return 0; }
r[5]=r[14];
goto P_0c086730;
P_0c086730: /* original 66d3, guest PC 0x0c086730 */
if(!s->budget--) { s->failed_pc=0x0c086730u; return 0; }
r[6]=r[13];
goto P_0c086732;
P_0c086732: /* original 224b, guest PC 0x0c086732 */
if(!s->budget--) { s->failed_pc=0x0c086732u; return 0; }
r[2]|=r[4];
goto P_0c086734;
P_0c086734: /* original 1e2e, guest PC 0x0c086734 */
if(!s->budget--) { s->failed_pc=0x0c086734u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c086736;
P_0c086736: /* original b09b, guest PC 0x0c086736 */
if(!s->budget--) { s->failed_pc=0x0c086736u; return 0; }
target=code_base|0x0c086870u; r[16]=code_base|0x0c08673au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08673au) { target=s->pc; goto dispatch; }
goto P_0c08673a;
P_0c086738: /* original 64c3, guest PC 0x0c086738 */
if(!s->budget--) { s->failed_pc=0x0c086738u; return 0; }
r[4]=r[12];
goto P_0c08673a;
P_0c08673a: /* original 65e3, guest PC 0x0c08673a */
if(!s->budget--) { s->failed_pc=0x0c08673au; return 0; }
r[5]=r[14];
goto P_0c08673c;
P_0c08673c: /* original 66d3, guest PC 0x0c08673c */
if(!s->budget--) { s->failed_pc=0x0c08673cu; return 0; }
r[6]=r[13];
goto P_0c08673e;
P_0c08673e: /* original b00e, guest PC 0x0c08673e */
if(!s->budget--) { s->failed_pc=0x0c08673eu; return 0; }
target=code_base|0x0c08675eu; r[16]=code_base|0x0c086742u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086742u) { target=s->pc; goto dispatch; }
goto P_0c086742;
P_0c086740: /* original 64c3, guest PC 0x0c086740 */
if(!s->budget--) { s->failed_pc=0x0c086740u; return 0; }
r[4]=r[12];
goto P_0c086742;
P_0c086742: /* original e004, guest PC 0x0c086742 */
if(!s->budget--) { s->failed_pc=0x0c086742u; return 0; }
r[0]=0x00000004u;
goto P_0c086744;
P_0c086744: /* original 4f26, guest PC 0x0c086744 */
if(!s->budget--) { s->failed_pc=0x0c086744u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086746;
P_0c086746: /* original fef7, guest PC 0x0c086746 */
if(!s->budget--) { s->failed_pc=0x0c086746u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c086748;
P_0c086748: /* original e008, guest PC 0x0c086748 */
if(!s->budget--) { s->failed_pc=0x0c086748u; return 0; }
r[0]=0x00000008u;
goto P_0c08674a;
P_0c08674a: /* original fed7, guest PC 0x0c08674a */
if(!s->budget--) { s->failed_pc=0x0c08674au; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08674c;
P_0c08674c: /* original e00c, guest PC 0x0c08674c */
if(!s->budget--) { s->failed_pc=0x0c08674cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08674e;
P_0c08674e: /* original fee7, guest PC 0x0c08674e */
if(!s->budget--) { s->failed_pc=0x0c08674eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c086750;
P_0c086750: /* original fdf9, guest PC 0x0c086750 */
if(!s->budget--) { s->failed_pc=0x0c086750u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086752;
P_0c086752: /* original fef9, guest PC 0x0c086752 */
if(!s->budget--) { s->failed_pc=0x0c086752u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086754;
P_0c086754: /* original fff9, guest PC 0x0c086754 */
if(!s->budget--) { s->failed_pc=0x0c086754u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086756;
P_0c086756: /* original 6cf6, guest PC 0x0c086756 */
if(!s->budget--) { s->failed_pc=0x0c086756u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086758;
P_0c086758: /* original 6df6, guest PC 0x0c086758 */
if(!s->budget--) { s->failed_pc=0x0c086758u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08675a;
P_0c08675a: /* original 000b, guest PC 0x0c08675a */
if(!s->budget--) { s->failed_pc=0x0c08675au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08675c: /* original 6ef6, guest PC 0x0c08675c */
if(!s->budget--) { s->failed_pc=0x0c08675cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08675eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
