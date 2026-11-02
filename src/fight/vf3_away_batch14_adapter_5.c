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
int vf3_away_batch14_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c08675eu: goto P_0c08675e;
case 0x0c086760u: goto P_0c086760;
case 0x0c086762u: goto P_0c086762;
case 0x0c086764u: goto P_0c086764;
case 0x0c086766u: goto P_0c086766;
case 0x0c086768u: goto P_0c086768;
case 0x0c08676au: goto P_0c08676a;
case 0x0c08676cu: goto P_0c08676c;
case 0x0c08676eu: goto P_0c08676e;
case 0x0c086770u: goto P_0c086770;
case 0x0c086772u: goto P_0c086772;
case 0x0c086774u: goto P_0c086774;
case 0x0c086776u: goto P_0c086776;
case 0x0c086778u: goto P_0c086778;
case 0x0c08677au: goto P_0c08677a;
case 0x0c08677cu: goto P_0c08677c;
case 0x0c08677eu: goto P_0c08677e;
case 0x0c086780u: goto P_0c086780;
case 0x0c086782u: goto P_0c086782;
case 0x0c086784u: goto P_0c086784;
case 0x0c086786u: goto P_0c086786;
case 0x0c086788u: goto P_0c086788;
case 0x0c08678au: goto P_0c08678a;
case 0x0c08678cu: goto P_0c08678c;
case 0x0c08678eu: goto P_0c08678e;
case 0x0c086790u: goto P_0c086790;
case 0x0c086792u: goto P_0c086792;
case 0x0c086794u: goto P_0c086794;
case 0x0c086796u: goto P_0c086796;
case 0x0c086798u: goto P_0c086798;
case 0x0c08679au: goto P_0c08679a;
case 0x0c08679cu: goto P_0c08679c;
case 0x0c08679eu: goto P_0c08679e;
case 0x0c0867a0u: goto P_0c0867a0;
case 0x0c0867a2u: goto P_0c0867a2;
case 0x0c0867a4u: goto P_0c0867a4;
case 0x0c0867a6u: goto P_0c0867a6;
case 0x0c0867a8u: goto P_0c0867a8;
case 0x0c0867aau: goto P_0c0867aa;
case 0x0c0867acu: goto P_0c0867ac;
case 0x0c0867aeu: goto P_0c0867ae;
case 0x0c0867b0u: goto P_0c0867b0;
case 0x0c0867b2u: goto P_0c0867b2;
case 0x0c0867b4u: goto P_0c0867b4;
case 0x0c0867b6u: goto P_0c0867b6;
case 0x0c0867b8u: goto P_0c0867b8;
case 0x0c0867d0u: goto P_0c0867d0;
case 0x0c0867d2u: goto P_0c0867d2;
case 0x0c0867d4u: goto P_0c0867d4;
case 0x0c0867d6u: goto P_0c0867d6;
case 0x0c0867d8u: goto P_0c0867d8;
case 0x0c0867dau: goto P_0c0867da;
case 0x0c0867dcu: goto P_0c0867dc;
case 0x0c0867deu: goto P_0c0867de;
case 0x0c0867e0u: goto P_0c0867e0;
case 0x0c0867e2u: goto P_0c0867e2;
case 0x0c0867e4u: goto P_0c0867e4;
case 0x0c0867e6u: goto P_0c0867e6;
case 0x0c0867e8u: goto P_0c0867e8;
case 0x0c0867eau: goto P_0c0867ea;
case 0x0c0867ecu: goto P_0c0867ec;
case 0x0c0867eeu: goto P_0c0867ee;
case 0x0c0867f0u: goto P_0c0867f0;
case 0x0c0867f2u: goto P_0c0867f2;
case 0x0c0867f4u: goto P_0c0867f4;
case 0x0c0867f6u: goto P_0c0867f6;
case 0x0c0867f8u: goto P_0c0867f8;
case 0x0c0867fau: goto P_0c0867fa;
case 0x0c0867fcu: goto P_0c0867fc;
case 0x0c0867feu: goto P_0c0867fe;
default: return vf3_matrix_family(target,s,ram);
}
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
goto P_0c08675e;
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
goto P_0c08675e;
P_0c08675e: /* original e028, guest PC 0x0c08675e */
if(!s->budget--) { s->failed_pc=0x0c08675eu; return 0; }
r[0]=0x00000028u;
goto P_0c086760;
P_0c086760: /* original 6453, guest PC 0x0c086760 */
if(!s->budget--) { s->failed_pc=0x0c086760u; return 0; }
r[4]=r[5];
goto P_0c086762;
P_0c086762: /* original 034d, guest PC 0x0c086762 */
if(!s->budget--) { s->failed_pc=0x0c086762u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086764;
P_0c086764: /* original e034, guest PC 0x0c086764 */
if(!s->budget--) { s->failed_pc=0x0c086764u; return 0; }
r[0]=0x00000034u;
goto P_0c086766;
P_0c086766: /* original 064d, guest PC 0x0c086766 */
if(!s->budget--) { s->failed_pc=0x0c086766u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086768;
P_0c086768: /* original 3638, guest PC 0x0c086768 */
if(!s->budget--) { s->failed_pc=0x0c086768u; return 0; }
r[6]-=r[3];
goto P_0c08676a;
P_0c08676a: /* original 626f, guest PC 0x0c08676a */
if(!s->budget--) { s->failed_pc=0x0c08676au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08676c;
P_0c08676c: /* original 4211, guest PC 0x0c08676c */
if(!s->budget--) { s->failed_pc=0x0c08676cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c08676e;
P_0c08676e: /* original 8900, guest PC 0x0c08676e */
if(!s->budget--) { s->failed_pc=0x0c08676eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086772; }
goto P_0c086770;
P_0c086770: /* original 666b, guest PC 0x0c086770 */
if(!s->budget--) { s->failed_pc=0x0c086770u; return 0; }
r[6]=0u-r[6];
goto P_0c086772;
P_0c086772: /* original 9523, guest PC 0x0c086772 */
if(!s->budget--) { s->failed_pc=0x0c086772u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0867bcu,2);
goto P_0c086774;
P_0c086774: /* original 666f, guest PC 0x0c086774 */
if(!s->budget--) { s->failed_pc=0x0c086774u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c086776;
P_0c086776: /* original 3653, guest PC 0x0c086776 */
if(!s->budget--) { s->failed_pc=0x0c086776u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c086778;
P_0c086778: /* original 8b07, guest PC 0x0c086778 */
if(!s->budget--) { s->failed_pc=0x0c086778u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08678a; }
goto P_0c08677a;
P_0c08677a: /* original e32e, guest PC 0x0c08677a */
if(!s->budget--) { s->failed_pc=0x0c08677au; return 0; }
r[3]=0x0000002eu;
goto P_0c08677c;
P_0c08677c: /* original 334c, guest PC 0x0c08677c */
if(!s->budget--) { s->failed_pc=0x0c08677cu; return 0; }
r[3]+=r[4];
goto P_0c08677e;
P_0c08677e: /* original e028, guest PC 0x0c08677e */
if(!s->budget--) { s->failed_pc=0x0c08677eu; return 0; }
r[0]=0x00000028u;
goto P_0c086780;
P_0c086780: /* original 6331, guest PC 0x0c086780 */
if(!s->budget--) { s->failed_pc=0x0c086780u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c086782;
P_0c086782: /* original 024d, guest PC 0x0c086782 */
if(!s->budget--) { s->failed_pc=0x0c086782u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086784;
P_0c086784: /* original 323c, guest PC 0x0c086784 */
if(!s->budget--) { s->failed_pc=0x0c086784u; return 0; }
r[2]+=r[3];
goto P_0c086786;
P_0c086786: /* original a004, guest PC 0x0c086786 */
if(!s->budget--) { s->failed_pc=0x0c086786u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c086792;
P_0c086788: /* original 0425, guest PC 0x0c086788 */
if(!s->budget--) { s->failed_pc=0x0c086788u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c08678a;
P_0c08678a: /* original e128, guest PC 0x0c08678a */
if(!s->budget--) { s->failed_pc=0x0c08678au; return 0; }
r[1]=0x00000028u;
goto P_0c08678c;
P_0c08678c: /* original 004d, guest PC 0x0c08678c */
if(!s->budget--) { s->failed_pc=0x0c08678cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08678e;
P_0c08678e: /* original 314c, guest PC 0x0c08678e */
if(!s->budget--) { s->failed_pc=0x0c08678eu; return 0; }
r[1]+=r[4];
goto P_0c086790;
P_0c086790: /* original 2101, guest PC 0x0c086790 */
if(!s->budget--) { s->failed_pc=0x0c086790u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c086792;
P_0c086792: /* original e026, guest PC 0x0c086792 */
if(!s->budget--) { s->failed_pc=0x0c086792u; return 0; }
r[0]=0x00000026u;
goto P_0c086794;
P_0c086794: /* original 034d, guest PC 0x0c086794 */
if(!s->budget--) { s->failed_pc=0x0c086794u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086796;
P_0c086796: /* original e032, guest PC 0x0c086796 */
if(!s->budget--) { s->failed_pc=0x0c086796u; return 0; }
r[0]=0x00000032u;
goto P_0c086798;
P_0c086798: /* original 064d, guest PC 0x0c086798 */
if(!s->budget--) { s->failed_pc=0x0c086798u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08679a;
P_0c08679a: /* original 3638, guest PC 0x0c08679a */
if(!s->budget--) { s->failed_pc=0x0c08679au; return 0; }
r[6]-=r[3];
goto P_0c08679c;
P_0c08679c: /* original 626f, guest PC 0x0c08679c */
if(!s->budget--) { s->failed_pc=0x0c08679cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08679e;
P_0c08679e: /* original 4211, guest PC 0x0c08679e */
if(!s->budget--) { s->failed_pc=0x0c08679eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0867a0;
P_0c0867a0: /* original 8900, guest PC 0x0c0867a0 */
if(!s->budget--) { s->failed_pc=0x0c0867a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0867a4; }
goto P_0c0867a2;
P_0c0867a2: /* original 666b, guest PC 0x0c0867a2 */
if(!s->budget--) { s->failed_pc=0x0c0867a2u; return 0; }
r[6]=0u-r[6];
goto P_0c0867a4;
P_0c0867a4: /* original 666f, guest PC 0x0c0867a4 */
if(!s->budget--) { s->failed_pc=0x0c0867a4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0867a6;
P_0c0867a6: /* original 3653, guest PC 0x0c0867a6 */
if(!s->budget--) { s->failed_pc=0x0c0867a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c0867a8;
P_0c0867a8: /* original 8b12, guest PC 0x0c0867a8 */
if(!s->budget--) { s->failed_pc=0x0c0867a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0867d0; }
goto P_0c0867aa;
P_0c0867aa: /* original e32c, guest PC 0x0c0867aa */
if(!s->budget--) { s->failed_pc=0x0c0867aau; return 0; }
r[3]=0x0000002cu;
goto P_0c0867ac;
P_0c0867ac: /* original 334c, guest PC 0x0c0867ac */
if(!s->budget--) { s->failed_pc=0x0c0867acu; return 0; }
r[3]+=r[4];
goto P_0c0867ae;
P_0c0867ae: /* original e026, guest PC 0x0c0867ae */
if(!s->budget--) { s->failed_pc=0x0c0867aeu; return 0; }
r[0]=0x00000026u;
goto P_0c0867b0;
P_0c0867b0: /* original 6331, guest PC 0x0c0867b0 */
if(!s->budget--) { s->failed_pc=0x0c0867b0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c0867b2;
P_0c0867b2: /* original 024d, guest PC 0x0c0867b2 */
if(!s->budget--) { s->failed_pc=0x0c0867b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867b4;
P_0c0867b4: /* original 323c, guest PC 0x0c0867b4 */
if(!s->budget--) { s->failed_pc=0x0c0867b4u; return 0; }
r[2]+=r[3];
goto P_0c0867b6;
P_0c0867b6: /* original a00f, guest PC 0x0c0867b6 */
if(!s->budget--) { s->failed_pc=0x0c0867b6u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0867d8;
P_0c0867b8: /* original 0425, guest PC 0x0c0867b8 */
if(!s->budget--) { s->failed_pc=0x0c0867b8u; return 0; }
write(ram,r[4]+r[0],r[2],2);
if(!vf3_matrix_family(0x0c0867bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0867bau; return 0; } return 1;
P_0c0867d0: /* original e126, guest PC 0x0c0867d0 */
if(!s->budget--) { s->failed_pc=0x0c0867d0u; return 0; }
r[1]=0x00000026u;
goto P_0c0867d2;
P_0c0867d2: /* original 004d, guest PC 0x0c0867d2 */
if(!s->budget--) { s->failed_pc=0x0c0867d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867d4;
P_0c0867d4: /* original 314c, guest PC 0x0c0867d4 */
if(!s->budget--) { s->failed_pc=0x0c0867d4u; return 0; }
r[1]+=r[4];
goto P_0c0867d6;
P_0c0867d6: /* original 2101, guest PC 0x0c0867d6 */
if(!s->budget--) { s->failed_pc=0x0c0867d6u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0867d8;
P_0c0867d8: /* original e024, guest PC 0x0c0867d8 */
if(!s->budget--) { s->failed_pc=0x0c0867d8u; return 0; }
r[0]=0x00000024u;
goto P_0c0867da;
P_0c0867da: /* original 034d, guest PC 0x0c0867da */
if(!s->budget--) { s->failed_pc=0x0c0867dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867dc;
P_0c0867dc: /* original e030, guest PC 0x0c0867dc */
if(!s->budget--) { s->failed_pc=0x0c0867dcu; return 0; }
r[0]=0x00000030u;
goto P_0c0867de;
P_0c0867de: /* original 064d, guest PC 0x0c0867de */
if(!s->budget--) { s->failed_pc=0x0c0867deu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867e0;
P_0c0867e0: /* original 3638, guest PC 0x0c0867e0 */
if(!s->budget--) { s->failed_pc=0x0c0867e0u; return 0; }
r[6]-=r[3];
goto P_0c0867e2;
P_0c0867e2: /* original 626f, guest PC 0x0c0867e2 */
if(!s->budget--) { s->failed_pc=0x0c0867e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0867e4;
P_0c0867e4: /* original 4211, guest PC 0x0c0867e4 */
if(!s->budget--) { s->failed_pc=0x0c0867e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0867e6;
P_0c0867e6: /* original 8900, guest PC 0x0c0867e6 */
if(!s->budget--) { s->failed_pc=0x0c0867e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0867ea; }
goto P_0c0867e8;
P_0c0867e8: /* original 666b, guest PC 0x0c0867e8 */
if(!s->budget--) { s->failed_pc=0x0c0867e8u; return 0; }
r[6]=0u-r[6];
goto P_0c0867ea;
P_0c0867ea: /* original 666f, guest PC 0x0c0867ea */
if(!s->budget--) { s->failed_pc=0x0c0867eau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0867ec;
P_0c0867ec: /* original 3653, guest PC 0x0c0867ec */
if(!s->budget--) { s->failed_pc=0x0c0867ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c0867ee;
P_0c0867ee: /* original 8b07, guest PC 0x0c0867ee */
if(!s->budget--) { s->failed_pc=0x0c0867eeu; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c086800u,s,ram); }
goto P_0c0867f0;
P_0c0867f0: /* original e32a, guest PC 0x0c0867f0 */
if(!s->budget--) { s->failed_pc=0x0c0867f0u; return 0; }
r[3]=0x0000002au;
goto P_0c0867f2;
P_0c0867f2: /* original 334c, guest PC 0x0c0867f2 */
if(!s->budget--) { s->failed_pc=0x0c0867f2u; return 0; }
r[3]+=r[4];
goto P_0c0867f4;
P_0c0867f4: /* original e024, guest PC 0x0c0867f4 */
if(!s->budget--) { s->failed_pc=0x0c0867f4u; return 0; }
r[0]=0x00000024u;
goto P_0c0867f6;
P_0c0867f6: /* original 6331, guest PC 0x0c0867f6 */
if(!s->budget--) { s->failed_pc=0x0c0867f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c0867f8;
P_0c0867f8: /* original 024d, guest PC 0x0c0867f8 */
if(!s->budget--) { s->failed_pc=0x0c0867f8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867fa;
P_0c0867fa: /* original 323c, guest PC 0x0c0867fa */
if(!s->budget--) { s->failed_pc=0x0c0867fau; return 0; }
r[2]+=r[3];
goto P_0c0867fc;
P_0c0867fc: /* original 000b, guest PC 0x0c0867fc */
if(!s->budget--) { s->failed_pc=0x0c0867fcu; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[2],2);
s->pc=target; return ram->oob==0;
P_0c0867fe: /* original 0425, guest PC 0x0c0867fe */
if(!s->budget--) { s->failed_pc=0x0c0867feu; return 0; }
write(ram,r[4]+r[0],r[2],2);
return vf3_matrix_family(0x0c086800u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
