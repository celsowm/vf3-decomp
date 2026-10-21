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
int vf3_c105_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!s->lost_pc) s->lost_pc=target; if(!vf3_matrix_family(target,s,ram)) return 0; return 1;
}
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063456u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06345eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c0634eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0634eeu; return 0; } return 1;
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06352au) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063530u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063536u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06353cu) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063542u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06355au) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063560u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063566u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06356cu) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06357cu) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06358cu) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063592u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063598u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06359eu) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635a4u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635aau) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635b2u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635bau) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635c0u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635c6u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635ceu) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635d6u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635deu) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0635e4u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063606u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c063616u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c063616u; return 0; } return 1;
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063688u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c0636a0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0636a0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c063446u,0x0c063448u,0x0c06344au,0x0c06344cu,0x0c06344eu,0x0c063450u,0x0c063452u,0x0c063454u,0x0c063456u,0x0c063458u,0x0c06345au,0x0c06345cu,0x0c06345eu,0x0c063460u,0x0c063462u,0x0c063464u,
0x0c063466u,0x0c063468u,0x0c06346au,0x0c06346cu,0x0c06346eu,0x0c063470u,0x0c063472u,0x0c063474u,0x0c063476u,0x0c063478u,0x0c06347au,0x0c06347cu,0x0c06347eu,0x0c063480u,0x0c063482u,0x0c063484u,
0x0c063486u,0x0c063488u,0x0c06348au,0x0c06348cu,0x0c06348eu,0x0c063490u,0x0c063492u,0x0c063494u,0x0c063496u,0x0c063498u,0x0c06349au,0x0c06349cu,0x0c06349eu,0x0c0634a0u,0x0c0634a2u,0x0c0634a4u,
0x0c0634a6u,0x0c0634a8u,0x0c0634aau,0x0c0634acu,0x0c0634aeu,0x0c0634b0u,0x0c0634b2u,0x0c0634b4u,0x0c0634b6u,0x0c0634b8u,0x0c0634bau,0x0c0634bcu,0x0c0634beu,0x0c0634c0u,0x0c0634c2u,0x0c0634c4u,
0x0c0634c6u,0x0c0634c8u,0x0c0634cau,0x0c0634ccu,0x0c0634ceu,0x0c0634d0u,0x0c0634d2u,0x0c0634d4u,0x0c0634d6u,0x0c0634d8u,0x0c0634dau,0x0c0634dcu,0x0c0634deu,0x0c0634e0u,0x0c0634e2u,0x0c0634e4u,
0x0c0634e6u,0x0c0634e8u,0x0c0634eau,0x0c0634ecu,0x0c06351cu,0x0c06351eu,0x0c063520u,0x0c063522u,0x0c063524u,0x0c063526u,0x0c063528u,0x0c06352au,0x0c06352cu,0x0c06352eu,0x0c063530u,0x0c063532u,
0x0c063534u,0x0c063536u,0x0c063538u,0x0c06353au,0x0c06353cu,0x0c06353eu,0x0c063540u,0x0c063542u,0x0c063544u,0x0c063546u,0x0c063548u,0x0c06354au,0x0c06354cu,0x0c06354eu,0x0c063550u,0x0c063552u,
0x0c063554u,0x0c063556u,0x0c063558u,0x0c06355au,0x0c06355cu,0x0c06355eu,0x0c063560u,0x0c063562u,0x0c063564u,0x0c063566u,0x0c063568u,0x0c06356au,0x0c06356cu,0x0c06356eu,0x0c063570u,0x0c063572u,
0x0c063574u,0x0c063576u,0x0c063578u,0x0c06357au,0x0c06357cu,0x0c06357eu,0x0c063580u,0x0c063582u,0x0c063584u,0x0c063586u,0x0c063588u,0x0c06358au,0x0c06358cu,0x0c06358eu,0x0c063590u,0x0c063592u,
0x0c063594u,0x0c063596u,0x0c063598u,0x0c06359au,0x0c06359cu,0x0c06359eu,0x0c0635a0u,0x0c0635a2u,0x0c0635a4u,0x0c0635a6u,0x0c0635a8u,0x0c0635aau,0x0c0635acu,0x0c0635aeu,0x0c0635b0u,0x0c0635b2u,
0x0c0635b4u,0x0c0635b6u,0x0c0635b8u,0x0c0635bau,0x0c0635bcu,0x0c0635beu,0x0c0635c0u,0x0c0635c2u,0x0c0635c4u,0x0c0635c6u,0x0c0635c8u,0x0c0635cau,0x0c0635ccu,0x0c0635ceu,0x0c0635d0u,0x0c0635d2u,
0x0c0635d4u,0x0c0635d6u,0x0c0635d8u,0x0c0635dau,0x0c0635dcu,0x0c0635deu,0x0c0635e0u,0x0c0635e2u,0x0c0635e4u,0x0c0635e6u,0x0c0635e8u,0x0c0635eau,0x0c0635ecu,0x0c0635eeu,0x0c0635f0u,0x0c0635f2u,
0x0c0635f4u,0x0c0635f6u,0x0c0635f8u,0x0c0635fau,0x0c0635fcu,0x0c0635feu,0x0c063600u,0x0c063602u,0x0c063604u,0x0c063606u,0x0c063608u,0x0c06360au,0x0c06360cu,0x0c06360eu,0x0c063610u,0x0c063612u,
0x0c063614u,0x0c063680u,0x0c063682u,0x0c063684u,0x0c063686u,0x0c063688u,0x0c06368au,0x0c06368cu,0x0c06368eu,0x0c063690u,0x0c063692u,0x0c063694u,0x0c063696u,0x0c063698u,0x0c06369au,0x0c06369cu,
0x0c06369eu,
};
static const uint32_t claim_pcs[]={
0x0c063446u,
};
int vf3_c105_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
