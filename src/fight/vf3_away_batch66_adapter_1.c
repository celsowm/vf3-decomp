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
int vf3_away_batch66_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09341eu: goto P_0c09341e;
case 0x0c093420u: goto P_0c093420;
case 0x0c093422u: goto P_0c093422;
case 0x0c093424u: goto P_0c093424;
case 0x0c093426u: goto P_0c093426;
case 0x0c093428u: goto P_0c093428;
case 0x0c09342au: goto P_0c09342a;
case 0x0c09342cu: goto P_0c09342c;
case 0x0c09342eu: goto P_0c09342e;
case 0x0c093430u: goto P_0c093430;
case 0x0c093432u: goto P_0c093432;
case 0x0c093434u: goto P_0c093434;
case 0x0c093436u: goto P_0c093436;
case 0x0c093438u: goto P_0c093438;
case 0x0c09343au: goto P_0c09343a;
case 0x0c09343cu: goto P_0c09343c;
case 0x0c09343eu: goto P_0c09343e;
case 0x0c093440u: goto P_0c093440;
case 0x0c093442u: goto P_0c093442;
case 0x0c093444u: goto P_0c093444;
case 0x0c093446u: goto P_0c093446;
case 0x0c093448u: goto P_0c093448;
case 0x0c09344au: goto P_0c09344a;
case 0x0c09344cu: goto P_0c09344c;
case 0x0c09344eu: goto P_0c09344e;
case 0x0c093450u: goto P_0c093450;
case 0x0c093452u: goto P_0c093452;
case 0x0c093454u: goto P_0c093454;
case 0x0c093456u: goto P_0c093456;
case 0x0c093458u: goto P_0c093458;
case 0x0c09345au: goto P_0c09345a;
case 0x0c09345cu: goto P_0c09345c;
case 0x0c09345eu: goto P_0c09345e;
case 0x0c093460u: goto P_0c093460;
case 0x0c093462u: goto P_0c093462;
case 0x0c093464u: goto P_0c093464;
case 0x0c093466u: goto P_0c093466;
case 0x0c093468u: goto P_0c093468;
case 0x0c09346au: goto P_0c09346a;
case 0x0c09346cu: goto P_0c09346c;
case 0x0c09346eu: goto P_0c09346e;
case 0x0c093470u: goto P_0c093470;
case 0x0c093472u: goto P_0c093472;
case 0x0c093474u: goto P_0c093474;
case 0x0c093476u: goto P_0c093476;
case 0x0c093478u: goto P_0c093478;
case 0x0c09347au: goto P_0c09347a;
case 0x0c09347cu: goto P_0c09347c;
case 0x0c09347eu: goto P_0c09347e;
case 0x0c093480u: goto P_0c093480;
case 0x0c093482u: goto P_0c093482;
case 0x0c093484u: goto P_0c093484;
case 0x0c093486u: goto P_0c093486;
case 0x0c093488u: goto P_0c093488;
case 0x0c09348au: goto P_0c09348a;
case 0x0c09348cu: goto P_0c09348c;
case 0x0c09348eu: goto P_0c09348e;
case 0x0c093490u: goto P_0c093490;
case 0x0c093492u: goto P_0c093492;
case 0x0c093494u: goto P_0c093494;
case 0x0c093496u: goto P_0c093496;
case 0x0c093498u: goto P_0c093498;
case 0x0c09349au: goto P_0c09349a;
case 0x0c09349cu: goto P_0c09349c;
case 0x0c09349eu: goto P_0c09349e;
case 0x0c0934a0u: goto P_0c0934a0;
case 0x0c0934a2u: goto P_0c0934a2;
case 0x0c0934a4u: goto P_0c0934a4;
case 0x0c0934a6u: goto P_0c0934a6;
case 0x0c0934a8u: goto P_0c0934a8;
case 0x0c0934aau: goto P_0c0934aa;
case 0x0c0934acu: goto P_0c0934ac;
case 0x0c0934aeu: goto P_0c0934ae;
case 0x0c0934b0u: goto P_0c0934b0;
case 0x0c0934b2u: goto P_0c0934b2;
case 0x0c0934b4u: goto P_0c0934b4;
case 0x0c0934b6u: goto P_0c0934b6;
case 0x0c0934b8u: goto P_0c0934b8;
case 0x0c0934bau: goto P_0c0934ba;
case 0x0c0934bcu: goto P_0c0934bc;
case 0x0c0934beu: goto P_0c0934be;
case 0x0c0934c0u: goto P_0c0934c0;
case 0x0c0934c2u: goto P_0c0934c2;
case 0x0c0934c4u: goto P_0c0934c4;
case 0x0c0934c6u: goto P_0c0934c6;
case 0x0c0934c8u: goto P_0c0934c8;
case 0x0c0934cau: goto P_0c0934ca;
case 0x0c0934ccu: goto P_0c0934cc;
case 0x0c0934ceu: goto P_0c0934ce;
case 0x0c0934d0u: goto P_0c0934d0;
case 0x0c0934d2u: goto P_0c0934d2;
case 0x0c0934d4u: goto P_0c0934d4;
case 0x0c0934d6u: goto P_0c0934d6;
case 0x0c0934d8u: goto P_0c0934d8;
case 0x0c0934dau: goto P_0c0934da;
case 0x0c0934dcu: goto P_0c0934dc;
case 0x0c0934deu: goto P_0c0934de;
case 0x0c0934e0u: goto P_0c0934e0;
case 0x0c0934e2u: goto P_0c0934e2;
case 0x0c093504u: goto P_0c093504;
case 0x0c093506u: goto P_0c093506;
case 0x0c093508u: goto P_0c093508;
case 0x0c09350au: goto P_0c09350a;
case 0x0c09350cu: goto P_0c09350c;
case 0x0c09350eu: goto P_0c09350e;
case 0x0c093510u: goto P_0c093510;
case 0x0c093512u: goto P_0c093512;
case 0x0c093514u: goto P_0c093514;
case 0x0c093516u: goto P_0c093516;
case 0x0c093518u: goto P_0c093518;
case 0x0c09351au: goto P_0c09351a;
case 0x0c09351cu: goto P_0c09351c;
case 0x0c09351eu: goto P_0c09351e;
case 0x0c093520u: goto P_0c093520;
case 0x0c093522u: goto P_0c093522;
case 0x0c093524u: goto P_0c093524;
case 0x0c093526u: goto P_0c093526;
case 0x0c093528u: goto P_0c093528;
case 0x0c09352au: goto P_0c09352a;
case 0x0c09352cu: goto P_0c09352c;
case 0x0c09352eu: goto P_0c09352e;
case 0x0c093530u: goto P_0c093530;
case 0x0c093532u: goto P_0c093532;
case 0x0c093534u: goto P_0c093534;
case 0x0c093536u: goto P_0c093536;
case 0x0c093538u: goto P_0c093538;
case 0x0c09353au: goto P_0c09353a;
case 0x0c09353cu: goto P_0c09353c;
case 0x0c09353eu: goto P_0c09353e;
case 0x0c093540u: goto P_0c093540;
case 0x0c093542u: goto P_0c093542;
case 0x0c093544u: goto P_0c093544;
case 0x0c093546u: goto P_0c093546;
case 0x0c093548u: goto P_0c093548;
case 0x0c09354au: goto P_0c09354a;
case 0x0c09354cu: goto P_0c09354c;
case 0x0c09354eu: goto P_0c09354e;
case 0x0c093550u: goto P_0c093550;
case 0x0c093552u: goto P_0c093552;
case 0x0c093554u: goto P_0c093554;
case 0x0c093556u: goto P_0c093556;
case 0x0c093558u: goto P_0c093558;
case 0x0c09355au: goto P_0c09355a;
case 0x0c09355cu: goto P_0c09355c;
case 0x0c09355eu: goto P_0c09355e;
case 0x0c093560u: goto P_0c093560;
case 0x0c093562u: goto P_0c093562;
case 0x0c093564u: goto P_0c093564;
case 0x0c093566u: goto P_0c093566;
case 0x0c093568u: goto P_0c093568;
case 0x0c09356au: goto P_0c09356a;
case 0x0c09356cu: goto P_0c09356c;
case 0x0c09356eu: goto P_0c09356e;
case 0x0c093570u: goto P_0c093570;
case 0x0c093572u: goto P_0c093572;
case 0x0c093574u: goto P_0c093574;
case 0x0c093576u: goto P_0c093576;
case 0x0c093578u: goto P_0c093578;
case 0x0c09357au: goto P_0c09357a;
case 0x0c09357cu: goto P_0c09357c;
case 0x0c09357eu: goto P_0c09357e;
case 0x0c093580u: goto P_0c093580;
case 0x0c093582u: goto P_0c093582;
case 0x0c093584u: goto P_0c093584;
case 0x0c093586u: goto P_0c093586;
case 0x0c093588u: goto P_0c093588;
case 0x0c09358au: goto P_0c09358a;
case 0x0c09358cu: goto P_0c09358c;
case 0x0c09358eu: goto P_0c09358e;
case 0x0c093590u: goto P_0c093590;
case 0x0c093592u: goto P_0c093592;
case 0x0c09359cu: goto P_0c09359c;
case 0x0c09359eu: goto P_0c09359e;
case 0x0c0935a0u: goto P_0c0935a0;
case 0x0c0935a2u: goto P_0c0935a2;
case 0x0c0935a4u: goto P_0c0935a4;
case 0x0c0935a6u: goto P_0c0935a6;
case 0x0c0935a8u: goto P_0c0935a8;
case 0x0c0935aau: goto P_0c0935aa;
case 0x0c0935acu: goto P_0c0935ac;
case 0x0c0935aeu: goto P_0c0935ae;
case 0x0c0935b0u: goto P_0c0935b0;
case 0x0c0935b2u: goto P_0c0935b2;
case 0x0c0935b4u: goto P_0c0935b4;
case 0x0c0935b6u: goto P_0c0935b6;
case 0x0c0935b8u: goto P_0c0935b8;
case 0x0c0935bau: goto P_0c0935ba;
case 0x0c0935bcu: goto P_0c0935bc;
case 0x0c0935beu: goto P_0c0935be;
case 0x0c0935c0u: goto P_0c0935c0;
case 0x0c0935c2u: goto P_0c0935c2;
case 0x0c0935c4u: goto P_0c0935c4;
case 0x0c0935c6u: goto P_0c0935c6;
case 0x0c0935c8u: goto P_0c0935c8;
case 0x0c0935cau: goto P_0c0935ca;
case 0x0c0935ccu: goto P_0c0935cc;
case 0x0c0935ceu: goto P_0c0935ce;
case 0x0c0935d0u: goto P_0c0935d0;
case 0x0c0935d2u: goto P_0c0935d2;
case 0x0c0935d4u: goto P_0c0935d4;
case 0x0c0935d6u: goto P_0c0935d6;
case 0x0c0935d8u: goto P_0c0935d8;
case 0x0c0935dau: goto P_0c0935da;
case 0x0c0935dcu: goto P_0c0935dc;
case 0x0c0935deu: goto P_0c0935de;
case 0x0c0935e0u: goto P_0c0935e0;
case 0x0c0935e2u: goto P_0c0935e2;
case 0x0c0935e4u: goto P_0c0935e4;
case 0x0c0935e6u: goto P_0c0935e6;
case 0x0c0935e8u: goto P_0c0935e8;
case 0x0c0935eau: goto P_0c0935ea;
case 0x0c0935ecu: goto P_0c0935ec;
case 0x0c0935eeu: goto P_0c0935ee;
case 0x0c0935f0u: goto P_0c0935f0;
case 0x0c0935f2u: goto P_0c0935f2;
case 0x0c0935f4u: goto P_0c0935f4;
case 0x0c0935f6u: goto P_0c0935f6;
case 0x0c0935f8u: goto P_0c0935f8;
case 0x0c0935fau: goto P_0c0935fa;
case 0x0c0935fcu: goto P_0c0935fc;
case 0x0c0935feu: goto P_0c0935fe;
case 0x0c093600u: goto P_0c093600;
case 0x0c093602u: goto P_0c093602;
case 0x0c093604u: goto P_0c093604;
case 0x0c093606u: goto P_0c093606;
case 0x0c093608u: goto P_0c093608;
case 0x0c09360au: goto P_0c09360a;
case 0x0c09360cu: goto P_0c09360c;
case 0x0c09360eu: goto P_0c09360e;
case 0x0c093610u: goto P_0c093610;
case 0x0c093612u: goto P_0c093612;
case 0x0c093614u: goto P_0c093614;
case 0x0c093616u: goto P_0c093616;
case 0x0c093618u: goto P_0c093618;
case 0x0c09361au: goto P_0c09361a;
case 0x0c09361cu: goto P_0c09361c;
case 0x0c09361eu: goto P_0c09361e;
case 0x0c093620u: goto P_0c093620;
case 0x0c093622u: goto P_0c093622;
case 0x0c093624u: goto P_0c093624;
case 0x0c093626u: goto P_0c093626;
case 0x0c093628u: goto P_0c093628;
case 0x0c09362au: goto P_0c09362a;
case 0x0c09362cu: goto P_0c09362c;
case 0x0c09362eu: goto P_0c09362e;
case 0x0c093630u: goto P_0c093630;
case 0x0c093632u: goto P_0c093632;
case 0x0c093634u: goto P_0c093634;
case 0x0c093636u: goto P_0c093636;
case 0x0c093638u: goto P_0c093638;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09341e: /* original 2fe6, guest PC 0x0c09341e */
if(!s->budget--) { s->failed_pc=0x0c09341eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093420;
P_0c093420: /* original 6e43, guest PC 0x0c093420 */
if(!s->budget--) { s->failed_pc=0x0c093420u; return 0; }
r[14]=r[4];
goto P_0c093422;
P_0c093422: /* original 2fd6, guest PC 0x0c093422 */
if(!s->budget--) { s->failed_pc=0x0c093422u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093424;
P_0c093424: /* original 2fc6, guest PC 0x0c093424 */
if(!s->budget--) { s->failed_pc=0x0c093424u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093426;
P_0c093426: /* original 2fb6, guest PC 0x0c093426 */
if(!s->budget--) { s->failed_pc=0x0c093426u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093428;
P_0c093428: /* original 2fa6, guest PC 0x0c093428 */
if(!s->budget--) { s->failed_pc=0x0c093428u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09342a;
P_0c09342a: /* original 4f22, guest PC 0x0c09342a */
if(!s->budget--) { s->failed_pc=0x0c09342au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09342c;
P_0c09342c: /* original 905a, guest PC 0x0c09342c */
if(!s->budget--) { s->failed_pc=0x0c09342cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0934e4u,2);
goto P_0c09342e;
P_0c09342e: /* original 7f98, guest PC 0x0c09342e */
if(!s->budget--) { s->failed_pc=0x0c09342eu; return 0; }
r[15]+=0xffffff98u;
goto P_0c093430;
P_0c093430: /* original 0cfe, guest PC 0x0c093430 */
if(!s->budget--) { s->failed_pc=0x0c093430u; return 0; }
r[12]=read(ram,r[15]+r[0],4);
goto P_0c093432;
P_0c093432: /* original 9058, guest PC 0x0c093432 */
if(!s->budget--) { s->failed_pc=0x0c093432u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0934e6u,2);
goto P_0c093434;
P_0c093434: /* original 04fe, guest PC 0x0c093434 */
if(!s->budget--) { s->failed_pc=0x0c093434u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c093436;
P_0c093436: /* original 9057, guest PC 0x0c093436 */
if(!s->budget--) { s->failed_pc=0x0c093436u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0934e8u,2);
goto P_0c093438;
P_0c093438: /* original 03fe, guest PC 0x0c093438 */
if(!s->budget--) { s->failed_pc=0x0c093438u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c09343a;
P_0c09343a: /* original 2338, guest PC 0x0c09343a */
if(!s->budget--) { s->failed_pc=0x0c09343au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09343c;
P_0c09343c: /* original 8f03, guest PC 0x0c09343c */
if(!s->budget--) { s->failed_pc=0x0c09343cu; return 0; }
cond=r[17]&1u;
r[13]=r[6];
if(!cond) { goto P_0c093446; }
goto P_0c093440;
P_0c09343e: /* original 6d63, guest PC 0x0c09343e */
if(!s->budget--) { s->failed_pc=0x0c09343eu; return 0; }
r[13]=r[6];
goto P_0c093440;
P_0c093440: /* original d32e, guest PC 0x0c093440 */
if(!s->budget--) { s->failed_pc=0x0c093440u; return 0; }
r[3]=read(ram,0x0c0934fcu,4);
goto P_0c093442;
P_0c093442: /* original 432b, guest PC 0x0c093442 */
if(!s->budget--) { s->failed_pc=0x0c093442u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093562u: goto P_0c093562;
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
P_0c093444: /* original 0009, guest PC 0x0c093444 */
if(!s->budget--) { s->failed_pc=0x0c093444u; return 0; }
goto P_0c093446;
P_0c093446: /* original 6071, guest PC 0x0c093446 */
if(!s->budget--) { s->failed_pc=0x0c093446u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[0]=tmp;
goto P_0c093448;
P_0c093448: /* original c804, guest PC 0x0c093448 */
if(!s->budget--) { s->failed_pc=0x0c093448u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09344a;
P_0c09344a: /* original 892f, guest PC 0x0c09344a */
if(!s->budget--) { s->failed_pc=0x0c09344au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0934ac; }
goto P_0c09344c;
P_0c09344c: /* original 934e, guest PC 0x0c09344c */
if(!s->budget--) { s->failed_pc=0x0c09344cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0934ecu,2);
goto P_0c09344e;
P_0c09344e: /* original 6242, guest PC 0x0c09344e */
if(!s->budget--) { s->failed_pc=0x0c09344eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c093450;
P_0c093450: /* original 9a4a, guest PC 0x0c093450 */
if(!s->budget--) { s->failed_pc=0x0c093450u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0934e8u,2);
goto P_0c093452;
P_0c093452: /* original 9b4a, guest PC 0x0c093452 */
if(!s->budget--) { s->failed_pc=0x0c093452u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0934eau,2);
goto P_0c093454;
P_0c093454: /* original 2238, guest PC 0x0c093454 */
if(!s->budget--) { s->failed_pc=0x0c093454u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c093456;
P_0c093456: /* original 8909, guest PC 0x0c093456 */
if(!s->budget--) { s->failed_pc=0x0c093456u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09346c; }
goto P_0c093458;
P_0c093458: /* original 6042, guest PC 0x0c093458 */
if(!s->budget--) { s->failed_pc=0x0c093458u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09345a;
P_0c09345a: /* original 20b9, guest PC 0x0c09345a */
if(!s->budget--) { s->failed_pc=0x0c09345au; return 0; }
r[0]&=r[11];
goto P_0c09345c;
P_0c09345c: /* original 2402, guest PC 0x0c09345c */
if(!s->budget--) { s->failed_pc=0x0c09345cu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c09345e;
P_0c09345e: /* original 6071, guest PC 0x0c09345e */
if(!s->budget--) { s->failed_pc=0x0c09345eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[0]=tmp;
goto P_0c093460;
P_0c093460: /* original c808, guest PC 0x0c093460 */
if(!s->budget--) { s->failed_pc=0x0c093460u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c093462;
P_0c093462: /* original 8b23, guest PC 0x0c093462 */
if(!s->budget--) { s->failed_pc=0x0c093462u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0934ac; }
goto P_0c093464;
P_0c093464: /* original 6142, guest PC 0x0c093464 */
if(!s->budget--) { s->failed_pc=0x0c093464u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c093466;
P_0c093466: /* original 21ab, guest PC 0x0c093466 */
if(!s->budget--) { s->failed_pc=0x0c093466u; return 0; }
r[1]|=r[10];
goto P_0c093468;
P_0c093468: /* original a020, guest PC 0x0c093468 */
if(!s->budget--) { s->failed_pc=0x0c093468u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c0934ac;
P_0c09346a: /* original 2412, guest PC 0x0c09346a */
if(!s->budget--) { s->failed_pc=0x0c09346au; return 0; }
write(ram,r[4],r[1],4);
goto P_0c09346c;
P_0c09346c: /* original 66d3, guest PC 0x0c09346c */
if(!s->budget--) { s->failed_pc=0x0c09346cu; return 0; }
r[6]=r[13];
goto P_0c09346e;
P_0c09346e: /* original 7658, guest PC 0x0c09346e */
if(!s->budget--) { s->failed_pc=0x0c09346eu; return 0; }
r[6]+=0x00000058u;
goto P_0c093470;
P_0c093470: /* original e034, guest PC 0x0c093470 */
if(!s->budget--) { s->failed_pc=0x0c093470u; return 0; }
r[0]=0x00000034u;
goto P_0c093472;
P_0c093472: /* original 2f62, guest PC 0x0c093472 */
if(!s->budget--) { s->failed_pc=0x0c093472u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c093474;
P_0c093474: /* original 6242, guest PC 0x0c093474 */
if(!s->budget--) { s->failed_pc=0x0c093474u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c093476;
P_0c093476: /* original 066d, guest PC 0x0c093476 */
if(!s->budget--) { s->failed_pc=0x0c093476u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c093478;
P_0c093478: /* original 22b9, guest PC 0x0c093478 */
if(!s->budget--) { s->failed_pc=0x0c093478u; return 0; }
r[2]&=r[11];
goto P_0c09347a;
P_0c09347a: /* original 666d, guest PC 0x0c09347a */
if(!s->budget--) { s->failed_pc=0x0c09347au; return 0; }
r[6]=r[6]&65535u;
goto P_0c09347c;
P_0c09347c: /* original 2422, guest PC 0x0c09347c */
if(!s->budget--) { s->failed_pc=0x0c09347cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c09347e;
P_0c09347e: /* original 6071, guest PC 0x0c09347e */
if(!s->budget--) { s->failed_pc=0x0c09347eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[0]=tmp;
goto P_0c093480;
P_0c093480: /* original c808, guest PC 0x0c093480 */
if(!s->budget--) { s->failed_pc=0x0c093480u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c093482;
P_0c093482: /* original 8d10, guest PC 0x0c093482 */
if(!s->budget--) { s->failed_pc=0x0c093482u; return 0; }
cond=r[17]&1u;
r[6]&=r[11];
if(cond) { goto P_0c0934a6; }
goto P_0c093486;
P_0c093484: /* original 26b9, guest PC 0x0c093484 */
if(!s->budget--) { s->failed_pc=0x0c093484u; return 0; }
r[6]&=r[11];
goto P_0c093486;
P_0c093486: /* original e008, guest PC 0x0c093486 */
if(!s->budget--) { s->failed_pc=0x0c093486u; return 0; }
r[0]=0x00000008u;
goto P_0c093488;
P_0c093488: /* original 6142, guest PC 0x0c093488 */
if(!s->budget--) { s->failed_pc=0x0c093488u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c09348a;
P_0c09348a: /* original 26ab, guest PC 0x0c09348a */
if(!s->budget--) { s->failed_pc=0x0c09348au; return 0; }
r[6]|=r[10];
goto P_0c09348c;
P_0c09348c: /* original 21ab, guest PC 0x0c09348c */
if(!s->budget--) { s->failed_pc=0x0c09348cu; return 0; }
r[1]|=r[10];
goto P_0c09348e;
P_0c09348e: /* original 2412, guest PC 0x0c09348e */
if(!s->budget--) { s->failed_pc=0x0c09348eu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c093490;
P_0c093490: /* original f376, guest PC 0x0c093490 */
if(!s->budget--) { s->failed_pc=0x0c093490u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c093492;
P_0c093492: /* original e004, guest PC 0x0c093492 */
if(!s->budget--) { s->failed_pc=0x0c093492u; return 0; }
r[0]=0x00000004u;
goto P_0c093494;
P_0c093494: /* original ff37, guest PC 0x0c093494 */
if(!s->budget--) { s->failed_pc=0x0c093494u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093496;
P_0c093496: /* original e00c, guest PC 0x0c093496 */
if(!s->budget--) { s->failed_pc=0x0c093496u; return 0; }
r[0]=0x0000000cu;
goto P_0c093498;
P_0c093498: /* original f376, guest PC 0x0c093498 */
if(!s->budget--) { s->failed_pc=0x0c093498u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c09349a;
P_0c09349a: /* original e008, guest PC 0x0c09349a */
if(!s->budget--) { s->failed_pc=0x0c09349au; return 0; }
r[0]=0x00000008u;
goto P_0c09349c;
P_0c09349c: /* original ff37, guest PC 0x0c09349c */
if(!s->budget--) { s->failed_pc=0x0c09349cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09349e;
P_0c09349e: /* original e010, guest PC 0x0c09349e */
if(!s->budget--) { s->failed_pc=0x0c09349eu; return 0; }
r[0]=0x00000010u;
goto P_0c0934a0;
P_0c0934a0: /* original f376, guest PC 0x0c0934a0 */
if(!s->budget--) { s->failed_pc=0x0c0934a0u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0934a2;
P_0c0934a2: /* original e00c, guest PC 0x0c0934a2 */
if(!s->budget--) { s->failed_pc=0x0c0934a2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0934a4;
P_0c0934a4: /* original ff37, guest PC 0x0c0934a4 */
if(!s->budget--) { s->failed_pc=0x0c0934a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0934a6;
P_0c0934a6: /* original 63f2, guest PC 0x0c0934a6 */
if(!s->budget--) { s->failed_pc=0x0c0934a6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0934a8;
P_0c0934a8: /* original e034, guest PC 0x0c0934a8 */
if(!s->budget--) { s->failed_pc=0x0c0934a8u; return 0; }
r[0]=0x00000034u;
goto P_0c0934aa;
P_0c0934aa: /* original 0365, guest PC 0x0c0934aa */
if(!s->budget--) { s->failed_pc=0x0c0934aau; return 0; }
write(ram,r[3]+r[0],r[6],2);
goto P_0c0934ac;
P_0c0934ac: /* original 921f, guest PC 0x0c0934ac */
if(!s->budget--) { s->failed_pc=0x0c0934acu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0934eeu,2);
goto P_0c0934ae;
P_0c0934ae: /* original e054, guest PC 0x0c0934ae */
if(!s->budget--) { s->failed_pc=0x0c0934aeu; return 0; }
r[0]=0x00000054u;
goto P_0c0934b0;
P_0c0934b0: /* original 03dd, guest PC 0x0c0934b0 */
if(!s->budget--) { s->failed_pc=0x0c0934b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0934b2;
P_0c0934b2: /* original 325c, guest PC 0x0c0934b2 */
if(!s->budget--) { s->failed_pc=0x0c0934b2u; return 0; }
r[2]+=r[5];
goto P_0c0934b4;
P_0c0934b4: /* original 3258, guest PC 0x0c0934b4 */
if(!s->budget--) { s->failed_pc=0x0c0934b4u; return 0; }
r[2]-=r[5];
goto P_0c0934b6;
P_0c0934b6: /* original 633d, guest PC 0x0c0934b6 */
if(!s->budget--) { s->failed_pc=0x0c0934b6u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0934b8;
P_0c0934b8: /* original 3320, guest PC 0x0c0934b8 */
if(!s->budget--) { s->failed_pc=0x0c0934b8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0934ba;
P_0c0934ba: /* original 8b03, guest PC 0x0c0934ba */
if(!s->budget--) { s->failed_pc=0x0c0934bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0934c4; }
goto P_0c0934bc;
P_0c0934bc: /* original 9012, guest PC 0x0c0934bc */
if(!s->budget--) { s->failed_pc=0x0c0934bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0934e4u,2);
goto P_0c0934be;
P_0c0934be: /* original f3e6, guest PC 0x0c0934be */
if(!s->budget--) { s->failed_pc=0x0c0934beu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0934c0;
P_0c0934c0: /* original a003, guest PC 0x0c0934c0 */
if(!s->budget--) { s->failed_pc=0x0c0934c0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0934ca;
P_0c0934c2: /* original 7004, guest PC 0x0c0934c2 */
if(!s->budget--) { s->failed_pc=0x0c0934c2u; return 0; }
r[0]+=0x00000004u;
goto P_0c0934c4;
P_0c0934c4: /* original 9010, guest PC 0x0c0934c4 */
if(!s->budget--) { s->failed_pc=0x0c0934c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0934e8u,2);
goto P_0c0934c6;
P_0c0934c6: /* original f3e6, guest PC 0x0c0934c6 */
if(!s->budget--) { s->failed_pc=0x0c0934c6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0934c8;
P_0c0934c8: /* original 7008, guest PC 0x0c0934c8 */
if(!s->budget--) { s->failed_pc=0x0c0934c8u; return 0; }
r[0]+=0x00000008u;
goto P_0c0934ca;
P_0c0934ca: /* original fe37, guest PC 0x0c0934ca */
if(!s->budget--) { s->failed_pc=0x0c0934cau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0934cc;
P_0c0934cc: /* original e054, guest PC 0x0c0934cc */
if(!s->budget--) { s->failed_pc=0x0c0934ccu; return 0; }
r[0]=0x00000054u;
goto P_0c0934ce;
P_0c0934ce: /* original 04dd, guest PC 0x0c0934ce */
if(!s->budget--) { s->failed_pc=0x0c0934ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0934d0;
P_0c0934d0: /* original d30b, guest PC 0x0c0934d0 */
if(!s->budget--) { s->failed_pc=0x0c0934d0u; return 0; }
r[3]=read(ram,0x0c093500u,4);
goto P_0c0934d2;
P_0c0934d2: /* original 644d, guest PC 0x0c0934d2 */
if(!s->budget--) { s->failed_pc=0x0c0934d2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0934d4;
P_0c0934d4: /* original 430b, guest PC 0x0c0934d4 */
if(!s->budget--) { s->failed_pc=0x0c0934d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0934d8u;
r[4]+=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0934d8u) { target=s->pc; goto dispatch; }
goto P_0c0934d8;
P_0c0934d6: /* original 345c, guest PC 0x0c0934d6 */
if(!s->budget--) { s->failed_pc=0x0c0934d6u; return 0; }
r[4]+=r[5];
goto P_0c0934d8;
P_0c0934d8: /* original 64d3, guest PC 0x0c0934d8 */
if(!s->budget--) { s->failed_pc=0x0c0934d8u; return 0; }
r[4]=r[13];
goto P_0c0934da;
P_0c0934da: /* original 65f3, guest PC 0x0c0934da */
if(!s->budget--) { s->failed_pc=0x0c0934dau; return 0; }
r[5]=r[15];
goto P_0c0934dc;
P_0c0934dc: /* original 7438, guest PC 0x0c0934dc */
if(!s->budget--) { s->failed_pc=0x0c0934dcu; return 0; }
r[4]+=0x00000038u;
goto P_0c0934de;
P_0c0934de: /* original 751c, guest PC 0x0c0934de */
if(!s->budget--) { s->failed_pc=0x0c0934deu; return 0; }
r[5]+=0x0000001cu;
goto P_0c0934e0;
P_0c0934e0: /* original a010, guest PC 0x0c0934e0 */
if(!s->budget--) { s->failed_pc=0x0c0934e0u; return 0; }
goto P_0c093504;
P_0c0934e2: /* original 0009, guest PC 0x0c0934e2 */
if(!s->budget--) { s->failed_pc=0x0c0934e2u; return 0; }
if(!vf3_matrix_family(0x0c0934e4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0934e4u; return 0; } return 1;
P_0c093504: /* original f449, guest PC 0x0c093504 */
if(!s->budget--) { s->failed_pc=0x0c093504u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093506;
P_0c093506: /* original f549, guest PC 0x0c093506 */
if(!s->budget--) { s->failed_pc=0x0c093506u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093508;
P_0c093508: /* original f648, guest PC 0x0c093508 */
if(!s->budget--) { s->failed_pc=0x0c093508u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c09350a;
P_0c09350a: /* original f79d, guest PC 0x0c09350a */
if(!s->budget--) { s->failed_pc=0x0c09350au; return 0; }
fr[7]=0x3f800000u;
goto P_0c09350c;
P_0c09350c: /* original f5fd, guest PC 0x0c09350c */
if(!s->budget--) { s->failed_pc=0x0c09350cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c09350e;
P_0c09350e: /* original 750c, guest PC 0x0c09350e */
if(!s->budget--) { s->failed_pc=0x0c09350eu; return 0; }
r[5]+=0x0000000cu;
goto P_0c093510;
P_0c093510: /* original f56b, guest PC 0x0c093510 */
if(!s->budget--) { s->failed_pc=0x0c093510u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c093512;
P_0c093512: /* original f55b, guest PC 0x0c093512 */
if(!s->budget--) { s->failed_pc=0x0c093512u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c093514;
P_0c093514: /* original f54b, guest PC 0x0c093514 */
if(!s->budget--) { s->failed_pc=0x0c093514u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c093516;
P_0c093516: /* original 0009, guest PC 0x0c093516 */
if(!s->budget--) { s->failed_pc=0x0c093516u; return 0; }
goto P_0c093518;
P_0c093518: /* original 64d3, guest PC 0x0c093518 */
if(!s->budget--) { s->failed_pc=0x0c093518u; return 0; }
r[4]=r[13];
goto P_0c09351a;
P_0c09351a: /* original 65f3, guest PC 0x0c09351a */
if(!s->budget--) { s->failed_pc=0x0c09351au; return 0; }
r[5]=r[15];
goto P_0c09351c;
P_0c09351c: /* original 7444, guest PC 0x0c09351c */
if(!s->budget--) { s->failed_pc=0x0c09351cu; return 0; }
r[4]+=0x00000044u;
goto P_0c09351e;
P_0c09351e: /* original 7510, guest PC 0x0c09351e */
if(!s->budget--) { s->failed_pc=0x0c09351eu; return 0; }
r[5]+=0x00000010u;
goto P_0c093520;
P_0c093520: /* original f449, guest PC 0x0c093520 */
if(!s->budget--) { s->failed_pc=0x0c093520u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093522;
P_0c093522: /* original f549, guest PC 0x0c093522 */
if(!s->budget--) { s->failed_pc=0x0c093522u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093524;
P_0c093524: /* original f648, guest PC 0x0c093524 */
if(!s->budget--) { s->failed_pc=0x0c093524u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c093526;
P_0c093526: /* original f79d, guest PC 0x0c093526 */
if(!s->budget--) { s->failed_pc=0x0c093526u; return 0; }
fr[7]=0x3f800000u;
goto P_0c093528;
P_0c093528: /* original f5fd, guest PC 0x0c093528 */
if(!s->budget--) { s->failed_pc=0x0c093528u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c09352a;
P_0c09352a: /* original 750c, guest PC 0x0c09352a */
if(!s->budget--) { s->failed_pc=0x0c09352au; return 0; }
r[5]+=0x0000000cu;
goto P_0c09352c;
P_0c09352c: /* original f56b, guest PC 0x0c09352c */
if(!s->budget--) { s->failed_pc=0x0c09352cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c09352e;
P_0c09352e: /* original f55b, guest PC 0x0c09352e */
if(!s->budget--) { s->failed_pc=0x0c09352eu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c093530;
P_0c093530: /* original f54b, guest PC 0x0c093530 */
if(!s->budget--) { s->failed_pc=0x0c093530u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c093532;
P_0c093532: /* original 0009, guest PC 0x0c093532 */
if(!s->budget--) { s->failed_pc=0x0c093532u; return 0; }
goto P_0c093534;
P_0c093534: /* original 65f3, guest PC 0x0c093534 */
if(!s->budget--) { s->failed_pc=0x0c093534u; return 0; }
r[5]=r[15];
goto P_0c093536;
P_0c093536: /* original 64e3, guest PC 0x0c093536 */
if(!s->budget--) { s->failed_pc=0x0c093536u; return 0; }
r[4]=r[14];
goto P_0c093538;
P_0c093538: /* original 66f3, guest PC 0x0c093538 */
if(!s->budget--) { s->failed_pc=0x0c093538u; return 0; }
r[6]=r[15];
goto P_0c09353a;
P_0c09353a: /* original 745c, guest PC 0x0c09353a */
if(!s->budget--) { s->failed_pc=0x0c09353au; return 0; }
r[4]+=0x0000005cu;
goto P_0c09353c;
P_0c09353c: /* original 761c, guest PC 0x0c09353c */
if(!s->budget--) { s->failed_pc=0x0c09353cu; return 0; }
r[6]+=0x0000001cu;
goto P_0c09353e;
P_0c09353e: /* original 7510, guest PC 0x0c09353e */
if(!s->budget--) { s->failed_pc=0x0c09353eu; return 0; }
r[5]+=0x00000010u;
goto P_0c093540;
P_0c093540: /* original f059, guest PC 0x0c093540 */
if(!s->budget--) { s->failed_pc=0x0c093540u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093542;
P_0c093542: /* original f369, guest PC 0x0c093542 */
if(!s->budget--) { s->failed_pc=0x0c093542u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093544;
P_0c093544: /* original f159, guest PC 0x0c093544 */
if(!s->budget--) { s->failed_pc=0x0c093544u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093546;
P_0c093546: /* original f469, guest PC 0x0c093546 */
if(!s->budget--) { s->failed_pc=0x0c093546u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093548;
P_0c093548: /* original f031, guest PC 0x0c093548 */
if(!s->budget--) { s->failed_pc=0x0c093548u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c09354a;
P_0c09354a: /* original f258, guest PC 0x0c09354a */
if(!s->budget--) { s->failed_pc=0x0c09354au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c09354c;
P_0c09354c: /* original f568, guest PC 0x0c09354c */
if(!s->budget--) { s->failed_pc=0x0c09354cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c09354e;
P_0c09354e: /* original f141, guest PC 0x0c09354e */
if(!s->budget--) { s->failed_pc=0x0c09354eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c093550;
P_0c093550: /* original f251, guest PC 0x0c093550 */
if(!s->budget--) { s->failed_pc=0x0c093550u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c093552;
P_0c093552: /* original 7408, guest PC 0x0c093552 */
if(!s->budget--) { s->failed_pc=0x0c093552u; return 0; }
r[4]+=0x00000008u;
goto P_0c093554;
P_0c093554: /* original f42a, guest PC 0x0c093554 */
if(!s->budget--) { s->failed_pc=0x0c093554u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093556;
P_0c093556: /* original f41b, guest PC 0x0c093556 */
if(!s->budget--) { s->failed_pc=0x0c093556u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093558;
P_0c093558: /* original f40b, guest PC 0x0c093558 */
if(!s->budget--) { s->failed_pc=0x0c093558u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c09355a;
P_0c09355a: /* original 0009, guest PC 0x0c09355a */
if(!s->budget--) { s->failed_pc=0x0c09355au; return 0; }
goto P_0c09355c;
P_0c09355c: /* original d30d, guest PC 0x0c09355c */
if(!s->budget--) { s->failed_pc=0x0c09355cu; return 0; }
r[3]=read(ram,0x0c093594u,4);
goto P_0c09355e;
P_0c09355e: /* original 432b, guest PC 0x0c09355e */
if(!s->budget--) { s->failed_pc=0x0c09355eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093614u: goto P_0c093614;
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
P_0c093560: /* original 0009, guest PC 0x0c093560 */
if(!s->budget--) { s->failed_pc=0x0c093560u; return 0; }
goto P_0c093562;
P_0c093562: /* original e068, guest PC 0x0c093562 */
if(!s->budget--) { s->failed_pc=0x0c093562u; return 0; }
r[0]=0x00000068u;
goto P_0c093564;
P_0c093564: /* original f3e6, guest PC 0x0c093564 */
if(!s->budget--) { s->failed_pc=0x0c093564u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093566;
P_0c093566: /* original e01c, guest PC 0x0c093566 */
if(!s->budget--) { s->failed_pc=0x0c093566u; return 0; }
r[0]=0x0000001cu;
goto P_0c093568;
P_0c093568: /* original ff37, guest PC 0x0c093568 */
if(!s->budget--) { s->failed_pc=0x0c093568u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09356a;
P_0c09356a: /* original e06c, guest PC 0x0c09356a */
if(!s->budget--) { s->failed_pc=0x0c09356au; return 0; }
r[0]=0x0000006cu;
goto P_0c09356c;
P_0c09356c: /* original f3e6, guest PC 0x0c09356c */
if(!s->budget--) { s->failed_pc=0x0c09356cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09356e;
P_0c09356e: /* original e020, guest PC 0x0c09356e */
if(!s->budget--) { s->failed_pc=0x0c09356eu; return 0; }
r[0]=0x00000020u;
goto P_0c093570;
P_0c093570: /* original ff37, guest PC 0x0c093570 */
if(!s->budget--) { s->failed_pc=0x0c093570u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093572;
P_0c093572: /* original e070, guest PC 0x0c093572 */
if(!s->budget--) { s->failed_pc=0x0c093572u; return 0; }
r[0]=0x00000070u;
goto P_0c093574;
P_0c093574: /* original f3e6, guest PC 0x0c093574 */
if(!s->budget--) { s->failed_pc=0x0c093574u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093576;
P_0c093576: /* original e024, guest PC 0x0c093576 */
if(!s->budget--) { s->failed_pc=0x0c093576u; return 0; }
r[0]=0x00000024u;
goto P_0c093578;
P_0c093578: /* original ff37, guest PC 0x0c093578 */
if(!s->budget--) { s->failed_pc=0x0c093578u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09357a;
P_0c09357a: /* original e054, guest PC 0x0c09357a */
if(!s->budget--) { s->failed_pc=0x0c09357au; return 0; }
r[0]=0x00000054u;
goto P_0c09357c;
P_0c09357c: /* original 0bdd, guest PC 0x0c09357c */
if(!s->budget--) { s->failed_pc=0x0c09357cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c09357e;
P_0c09357e: /* original d306, guest PC 0x0c09357e */
if(!s->budget--) { s->failed_pc=0x0c09357eu; return 0; }
r[3]=read(ram,0x0c093598u,4);
goto P_0c093580;
P_0c093580: /* original 6bbd, guest PC 0x0c093580 */
if(!s->budget--) { s->failed_pc=0x0c093580u; return 0; }
r[11]=r[11]&65535u;
goto P_0c093582;
P_0c093582: /* original 3b5c, guest PC 0x0c093582 */
if(!s->budget--) { s->failed_pc=0x0c093582u; return 0; }
r[11]+=r[5];
goto P_0c093584;
P_0c093584: /* original 430b, guest PC 0x0c093584 */
if(!s->budget--) { s->failed_pc=0x0c093584u; return 0; }
target=r[3];
r[16]=code_base|0x0c093588u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c093588u) { target=s->pc; goto dispatch; }
goto P_0c093588;
P_0c093586: /* original 64b3, guest PC 0x0c093586 */
if(!s->budget--) { s->failed_pc=0x0c093586u; return 0; }
r[4]=r[11];
goto P_0c093588;
P_0c093588: /* original 64d3, guest PC 0x0c093588 */
if(!s->budget--) { s->failed_pc=0x0c093588u; return 0; }
r[4]=r[13];
goto P_0c09358a;
P_0c09358a: /* original 65f3, guest PC 0x0c09358a */
if(!s->budget--) { s->failed_pc=0x0c09358au; return 0; }
r[5]=r[15];
goto P_0c09358c;
P_0c09358c: /* original 7444, guest PC 0x0c09358c */
if(!s->budget--) { s->failed_pc=0x0c09358cu; return 0; }
r[4]+=0x00000044u;
goto P_0c09358e;
P_0c09358e: /* original 7504, guest PC 0x0c09358e */
if(!s->budget--) { s->failed_pc=0x0c09358eu; return 0; }
r[5]+=0x00000004u;
goto P_0c093590;
P_0c093590: /* original a004, guest PC 0x0c093590 */
if(!s->budget--) { s->failed_pc=0x0c093590u; return 0; }
goto P_0c09359c;
P_0c093592: /* original 0009, guest PC 0x0c093592 */
if(!s->budget--) { s->failed_pc=0x0c093592u; return 0; }
if(!vf3_matrix_family(0x0c093594u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093594u; return 0; } return 1;
P_0c09359c: /* original f449, guest PC 0x0c09359c */
if(!s->budget--) { s->failed_pc=0x0c09359cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09359e;
P_0c09359e: /* original f549, guest PC 0x0c09359e */
if(!s->budget--) { s->failed_pc=0x0c09359eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0935a0;
P_0c0935a0: /* original f648, guest PC 0x0c0935a0 */
if(!s->budget--) { s->failed_pc=0x0c0935a0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0935a2;
P_0c0935a2: /* original f79d, guest PC 0x0c0935a2 */
if(!s->budget--) { s->failed_pc=0x0c0935a2u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0935a4;
P_0c0935a4: /* original f5fd, guest PC 0x0c0935a4 */
if(!s->budget--) { s->failed_pc=0x0c0935a4u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c0935a6;
P_0c0935a6: /* original 750c, guest PC 0x0c0935a6 */
if(!s->budget--) { s->failed_pc=0x0c0935a6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0935a8;
P_0c0935a8: /* original f56b, guest PC 0x0c0935a8 */
if(!s->budget--) { s->failed_pc=0x0c0935a8u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c0935aa;
P_0c0935aa: /* original f55b, guest PC 0x0c0935aa */
if(!s->budget--) { s->failed_pc=0x0c0935aau; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c0935ac;
P_0c0935ac: /* original f54b, guest PC 0x0c0935ac */
if(!s->budget--) { s->failed_pc=0x0c0935acu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c0935ae;
P_0c0935ae: /* original 0009, guest PC 0x0c0935ae */
if(!s->budget--) { s->failed_pc=0x0c0935aeu; return 0; }
goto P_0c0935b0;
P_0c0935b0: /* original 64f3, guest PC 0x0c0935b0 */
if(!s->budget--) { s->failed_pc=0x0c0935b0u; return 0; }
r[4]=r[15];
goto P_0c0935b2;
P_0c0935b2: /* original 65e3, guest PC 0x0c0935b2 */
if(!s->budget--) { s->failed_pc=0x0c0935b2u; return 0; }
r[5]=r[14];
goto P_0c0935b4;
P_0c0935b4: /* original 7404, guest PC 0x0c0935b4 */
if(!s->budget--) { s->failed_pc=0x0c0935b4u; return 0; }
r[4]+=0x00000004u;
goto P_0c0935b6;
P_0c0935b6: /* original 7574, guest PC 0x0c0935b6 */
if(!s->budget--) { s->failed_pc=0x0c0935b6u; return 0; }
r[5]+=0x00000074u;
goto P_0c0935b8;
P_0c0935b8: /* original f049, guest PC 0x0c0935b8 */
if(!s->budget--) { s->failed_pc=0x0c0935b8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0935ba;
P_0c0935ba: /* original f359, guest PC 0x0c0935ba */
if(!s->budget--) { s->failed_pc=0x0c0935bau; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0935bc;
P_0c0935bc: /* original f149, guest PC 0x0c0935bc */
if(!s->budget--) { s->failed_pc=0x0c0935bcu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0935be;
P_0c0935be: /* original f459, guest PC 0x0c0935be */
if(!s->budget--) { s->failed_pc=0x0c0935beu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0935c0;
P_0c0935c0: /* original f249, guest PC 0x0c0935c0 */
if(!s->budget--) { s->failed_pc=0x0c0935c0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0935c2;
P_0c0935c2: /* original f559, guest PC 0x0c0935c2 */
if(!s->budget--) { s->failed_pc=0x0c0935c2u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0935c4;
P_0c0935c4: /* original f030, guest PC 0x0c0935c4 */
if(!s->budget--) { s->failed_pc=0x0c0935c4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0935c6;
P_0c0935c6: /* original f250, guest PC 0x0c0935c6 */
if(!s->budget--) { s->failed_pc=0x0c0935c6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0935c8;
P_0c0935c8: /* original f140, guest PC 0x0c0935c8 */
if(!s->budget--) { s->failed_pc=0x0c0935c8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0935ca;
P_0c0935ca: /* original f42b, guest PC 0x0c0935ca */
if(!s->budget--) { s->failed_pc=0x0c0935cau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0935cc;
P_0c0935cc: /* original f41b, guest PC 0x0c0935cc */
if(!s->budget--) { s->failed_pc=0x0c0935ccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0935ce;
P_0c0935ce: /* original f40b, guest PC 0x0c0935ce */
if(!s->budget--) { s->failed_pc=0x0c0935ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0935d0;
P_0c0935d0: /* original 65f3, guest PC 0x0c0935d0 */
if(!s->budget--) { s->failed_pc=0x0c0935d0u; return 0; }
r[5]=r[15];
goto P_0c0935d2;
P_0c0935d2: /* original 64e3, guest PC 0x0c0935d2 */
if(!s->budget--) { s->failed_pc=0x0c0935d2u; return 0; }
r[4]=r[14];
goto P_0c0935d4;
P_0c0935d4: /* original 66b3, guest PC 0x0c0935d4 */
if(!s->budget--) { s->failed_pc=0x0c0935d4u; return 0; }
r[6]=r[11];
goto P_0c0935d6;
P_0c0935d6: /* original 745c, guest PC 0x0c0935d6 */
if(!s->budget--) { s->failed_pc=0x0c0935d6u; return 0; }
r[4]+=0x0000005cu;
goto P_0c0935d8;
P_0c0935d8: /* original 7630, guest PC 0x0c0935d8 */
if(!s->budget--) { s->failed_pc=0x0c0935d8u; return 0; }
r[6]+=0x00000030u;
goto P_0c0935da;
P_0c0935da: /* original 7504, guest PC 0x0c0935da */
if(!s->budget--) { s->failed_pc=0x0c0935dau; return 0; }
r[5]+=0x00000004u;
goto P_0c0935dc;
P_0c0935dc: /* original f059, guest PC 0x0c0935dc */
if(!s->budget--) { s->failed_pc=0x0c0935dcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0935de;
P_0c0935de: /* original f369, guest PC 0x0c0935de */
if(!s->budget--) { s->failed_pc=0x0c0935deu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0935e0;
P_0c0935e0: /* original f159, guest PC 0x0c0935e0 */
if(!s->budget--) { s->failed_pc=0x0c0935e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0935e2;
P_0c0935e2: /* original f469, guest PC 0x0c0935e2 */
if(!s->budget--) { s->failed_pc=0x0c0935e2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0935e4;
P_0c0935e4: /* original f031, guest PC 0x0c0935e4 */
if(!s->budget--) { s->failed_pc=0x0c0935e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0935e6;
P_0c0935e6: /* original f258, guest PC 0x0c0935e6 */
if(!s->budget--) { s->failed_pc=0x0c0935e6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0935e8;
P_0c0935e8: /* original f568, guest PC 0x0c0935e8 */
if(!s->budget--) { s->failed_pc=0x0c0935e8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0935ea;
P_0c0935ea: /* original f141, guest PC 0x0c0935ea */
if(!s->budget--) { s->failed_pc=0x0c0935eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0935ec;
P_0c0935ec: /* original f251, guest PC 0x0c0935ec */
if(!s->budget--) { s->failed_pc=0x0c0935ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0935ee;
P_0c0935ee: /* original 7408, guest PC 0x0c0935ee */
if(!s->budget--) { s->failed_pc=0x0c0935eeu; return 0; }
r[4]+=0x00000008u;
goto P_0c0935f0;
P_0c0935f0: /* original f42a, guest PC 0x0c0935f0 */
if(!s->budget--) { s->failed_pc=0x0c0935f0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0935f2;
P_0c0935f2: /* original f41b, guest PC 0x0c0935f2 */
if(!s->budget--) { s->failed_pc=0x0c0935f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0935f4;
P_0c0935f4: /* original f40b, guest PC 0x0c0935f4 */
if(!s->budget--) { s->failed_pc=0x0c0935f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0935f6;
P_0c0935f6: /* original 0009, guest PC 0x0c0935f6 */
if(!s->budget--) { s->failed_pc=0x0c0935f6u; return 0; }
goto P_0c0935f8;
P_0c0935f8: /* original 64e3, guest PC 0x0c0935f8 */
if(!s->budget--) { s->failed_pc=0x0c0935f8u; return 0; }
r[4]=r[14];
goto P_0c0935fa;
P_0c0935fa: /* original 745c, guest PC 0x0c0935fa */
if(!s->budget--) { s->failed_pc=0x0c0935fau; return 0; }
r[4]+=0x0000005cu;
goto P_0c0935fc;
P_0c0935fc: /* original f049, guest PC 0x0c0935fc */
if(!s->budget--) { s->failed_pc=0x0c0935fcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0935fe;
P_0c0935fe: /* original f149, guest PC 0x0c0935fe */
if(!s->budget--) { s->failed_pc=0x0c0935feu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093600;
P_0c093600: /* original f249, guest PC 0x0c093600 */
if(!s->budget--) { s->failed_pc=0x0c093600u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093602;
P_0c093602: /* original f38d, guest PC 0x0c093602 */
if(!s->budget--) { s->failed_pc=0x0c093602u; return 0; }
fr[3]=0;
goto P_0c093604;
P_0c093604: /* original f0ed, guest PC 0x0c093604 */
if(!s->budget--) { s->failed_pc=0x0c093604u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c093606;
P_0c093606: /* original f37d, guest PC 0x0c093606 */
if(!s->budget--) { s->failed_pc=0x0c093606u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c093608;
P_0c093608: /* original f232, guest PC 0x0c093608 */
if(!s->budget--) { s->failed_pc=0x0c093608u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c09360a;
P_0c09360a: /* original f132, guest PC 0x0c09360a */
if(!s->budget--) { s->failed_pc=0x0c09360au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c09360c;
P_0c09360c: /* original f032, guest PC 0x0c09360c */
if(!s->budget--) { s->failed_pc=0x0c09360cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c09360e;
P_0c09360e: /* original f42b, guest PC 0x0c09360e */
if(!s->budget--) { s->failed_pc=0x0c09360eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093610;
P_0c093610: /* original f41b, guest PC 0x0c093610 */
if(!s->budget--) { s->failed_pc=0x0c093610u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093612;
P_0c093612: /* original f40b, guest PC 0x0c093612 */
if(!s->budget--) { s->failed_pc=0x0c093612u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093614;
P_0c093614: /* original e01c, guest PC 0x0c093614 */
if(!s->budget--) { s->failed_pc=0x0c093614u; return 0; }
r[0]=0x0000001cu;
goto P_0c093616;
P_0c093616: /* original f3f6, guest PC 0x0c093616 */
if(!s->budget--) { s->failed_pc=0x0c093616u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093618;
P_0c093618: /* original e020, guest PC 0x0c093618 */
if(!s->budget--) { s->failed_pc=0x0c093618u; return 0; }
r[0]=0x00000020u;
goto P_0c09361a;
P_0c09361a: /* original fc3a, guest PC 0x0c09361a */
if(!s->budget--) { s->failed_pc=0x0c09361au; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c09361c;
P_0c09361c: /* original f3f6, guest PC 0x0c09361c */
if(!s->budget--) { s->failed_pc=0x0c09361cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09361e;
P_0c09361e: /* original e004, guest PC 0x0c09361e */
if(!s->budget--) { s->failed_pc=0x0c09361eu; return 0; }
r[0]=0x00000004u;
goto P_0c093620;
P_0c093620: /* original fc37, guest PC 0x0c093620 */
if(!s->budget--) { s->failed_pc=0x0c093620u; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c093622;
P_0c093622: /* original e024, guest PC 0x0c093622 */
if(!s->budget--) { s->failed_pc=0x0c093622u; return 0; }
r[0]=0x00000024u;
goto P_0c093624;
P_0c093624: /* original f3f6, guest PC 0x0c093624 */
if(!s->budget--) { s->failed_pc=0x0c093624u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093626;
P_0c093626: /* original 7f68, guest PC 0x0c093626 */
if(!s->budget--) { s->failed_pc=0x0c093626u; return 0; }
r[15]+=0x00000068u;
goto P_0c093628;
P_0c093628: /* original 4f26, guest PC 0x0c093628 */
if(!s->budget--) { s->failed_pc=0x0c093628u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09362a;
P_0c09362a: /* original e008, guest PC 0x0c09362a */
if(!s->budget--) { s->failed_pc=0x0c09362au; return 0; }
r[0]=0x00000008u;
goto P_0c09362c;
P_0c09362c: /* original fc37, guest PC 0x0c09362c */
if(!s->budget--) { s->failed_pc=0x0c09362cu; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c09362e;
P_0c09362e: /* original 6af6, guest PC 0x0c09362e */
if(!s->budget--) { s->failed_pc=0x0c09362eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c093630;
P_0c093630: /* original 6bf6, guest PC 0x0c093630 */
if(!s->budget--) { s->failed_pc=0x0c093630u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c093632;
P_0c093632: /* original 6cf6, guest PC 0x0c093632 */
if(!s->budget--) { s->failed_pc=0x0c093632u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c093634;
P_0c093634: /* original 6df6, guest PC 0x0c093634 */
if(!s->budget--) { s->failed_pc=0x0c093634u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c093636;
P_0c093636: /* original 000b, guest PC 0x0c093636 */
if(!s->budget--) { s->failed_pc=0x0c093636u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093638: /* original 6ef6, guest PC 0x0c093638 */
if(!s->budget--) { s->failed_pc=0x0c093638u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09363au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
