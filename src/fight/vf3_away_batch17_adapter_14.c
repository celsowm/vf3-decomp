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
int vf3_away_batch17_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0945f2u: goto P_0c0945f2;
case 0x0c0945f4u: goto P_0c0945f4;
case 0x0c0945f6u: goto P_0c0945f6;
case 0x0c0945f8u: goto P_0c0945f8;
case 0x0c0945fau: goto P_0c0945fa;
case 0x0c0945fcu: goto P_0c0945fc;
case 0x0c0945feu: goto P_0c0945fe;
case 0x0c094600u: goto P_0c094600;
case 0x0c094602u: goto P_0c094602;
case 0x0c094604u: goto P_0c094604;
case 0x0c094606u: goto P_0c094606;
case 0x0c094608u: goto P_0c094608;
case 0x0c09460au: goto P_0c09460a;
case 0x0c09460cu: goto P_0c09460c;
case 0x0c09460eu: goto P_0c09460e;
case 0x0c094610u: goto P_0c094610;
case 0x0c094612u: goto P_0c094612;
case 0x0c094614u: goto P_0c094614;
case 0x0c094616u: goto P_0c094616;
case 0x0c094618u: goto P_0c094618;
case 0x0c09461au: goto P_0c09461a;
case 0x0c09461cu: goto P_0c09461c;
case 0x0c09461eu: goto P_0c09461e;
case 0x0c094620u: goto P_0c094620;
case 0x0c094622u: goto P_0c094622;
case 0x0c094624u: goto P_0c094624;
case 0x0c094626u: goto P_0c094626;
case 0x0c094628u: goto P_0c094628;
case 0x0c09462au: goto P_0c09462a;
case 0x0c09462cu: goto P_0c09462c;
case 0x0c09462eu: goto P_0c09462e;
case 0x0c094630u: goto P_0c094630;
case 0x0c094632u: goto P_0c094632;
case 0x0c094634u: goto P_0c094634;
case 0x0c094636u: goto P_0c094636;
case 0x0c094638u: goto P_0c094638;
case 0x0c09463au: goto P_0c09463a;
case 0x0c09463cu: goto P_0c09463c;
case 0x0c09463eu: goto P_0c09463e;
case 0x0c094640u: goto P_0c094640;
case 0x0c094642u: goto P_0c094642;
case 0x0c094644u: goto P_0c094644;
case 0x0c094646u: goto P_0c094646;
case 0x0c094648u: goto P_0c094648;
case 0x0c09464au: goto P_0c09464a;
case 0x0c09464cu: goto P_0c09464c;
case 0x0c09464eu: goto P_0c09464e;
case 0x0c094650u: goto P_0c094650;
case 0x0c094652u: goto P_0c094652;
case 0x0c094654u: goto P_0c094654;
case 0x0c094656u: goto P_0c094656;
case 0x0c094658u: goto P_0c094658;
case 0x0c09465au: goto P_0c09465a;
case 0x0c09465cu: goto P_0c09465c;
case 0x0c094688u: goto P_0c094688;
case 0x0c09468au: goto P_0c09468a;
case 0x0c09468cu: goto P_0c09468c;
case 0x0c09468eu: goto P_0c09468e;
case 0x0c094690u: goto P_0c094690;
case 0x0c094692u: goto P_0c094692;
case 0x0c094694u: goto P_0c094694;
case 0x0c094696u: goto P_0c094696;
case 0x0c094698u: goto P_0c094698;
case 0x0c09469au: goto P_0c09469a;
case 0x0c09469cu: goto P_0c09469c;
case 0x0c09469eu: goto P_0c09469e;
case 0x0c0946a0u: goto P_0c0946a0;
case 0x0c0946a2u: goto P_0c0946a2;
case 0x0c0946a4u: goto P_0c0946a4;
case 0x0c0946a6u: goto P_0c0946a6;
case 0x0c0946a8u: goto P_0c0946a8;
case 0x0c0946aau: goto P_0c0946aa;
case 0x0c0946acu: goto P_0c0946ac;
case 0x0c0946aeu: goto P_0c0946ae;
case 0x0c0946b0u: goto P_0c0946b0;
case 0x0c0946b2u: goto P_0c0946b2;
case 0x0c0946b4u: goto P_0c0946b4;
case 0x0c0946b6u: goto P_0c0946b6;
case 0x0c0946b8u: goto P_0c0946b8;
case 0x0c0946bau: goto P_0c0946ba;
case 0x0c0946bcu: goto P_0c0946bc;
case 0x0c0946beu: goto P_0c0946be;
case 0x0c0946c0u: goto P_0c0946c0;
case 0x0c0946c2u: goto P_0c0946c2;
case 0x0c0946c4u: goto P_0c0946c4;
case 0x0c0946c6u: goto P_0c0946c6;
case 0x0c0946c8u: goto P_0c0946c8;
case 0x0c0946cau: goto P_0c0946ca;
case 0x0c0946ccu: goto P_0c0946cc;
case 0x0c0946ceu: goto P_0c0946ce;
case 0x0c0946d0u: goto P_0c0946d0;
case 0x0c0946d2u: goto P_0c0946d2;
case 0x0c0946d4u: goto P_0c0946d4;
case 0x0c0946d6u: goto P_0c0946d6;
case 0x0c0946d8u: goto P_0c0946d8;
case 0x0c0946dau: goto P_0c0946da;
case 0x0c0946dcu: goto P_0c0946dc;
case 0x0c0946deu: goto P_0c0946de;
case 0x0c0946e0u: goto P_0c0946e0;
case 0x0c0946e2u: goto P_0c0946e2;
case 0x0c0946e4u: goto P_0c0946e4;
case 0x0c0946e6u: goto P_0c0946e6;
case 0x0c0946e8u: goto P_0c0946e8;
case 0x0c0946eau: goto P_0c0946ea;
case 0x0c0946ecu: goto P_0c0946ec;
case 0x0c0946eeu: goto P_0c0946ee;
case 0x0c0946f0u: goto P_0c0946f0;
case 0x0c0946f2u: goto P_0c0946f2;
case 0x0c0946f4u: goto P_0c0946f4;
case 0x0c0946f6u: goto P_0c0946f6;
case 0x0c0946f8u: goto P_0c0946f8;
case 0x0c0946fau: goto P_0c0946fa;
case 0x0c0946fcu: goto P_0c0946fc;
case 0x0c0946feu: goto P_0c0946fe;
case 0x0c094700u: goto P_0c094700;
case 0x0c094702u: goto P_0c094702;
case 0x0c094704u: goto P_0c094704;
case 0x0c094706u: goto P_0c094706;
case 0x0c094708u: goto P_0c094708;
case 0x0c09470au: goto P_0c09470a;
case 0x0c09470cu: goto P_0c09470c;
case 0x0c09470eu: goto P_0c09470e;
case 0x0c094710u: goto P_0c094710;
case 0x0c094712u: goto P_0c094712;
case 0x0c094714u: goto P_0c094714;
case 0x0c094716u: goto P_0c094716;
case 0x0c094718u: goto P_0c094718;
case 0x0c09471au: goto P_0c09471a;
case 0x0c09471cu: goto P_0c09471c;
case 0x0c09471eu: goto P_0c09471e;
case 0x0c094720u: goto P_0c094720;
case 0x0c094722u: goto P_0c094722;
case 0x0c094724u: goto P_0c094724;
case 0x0c094726u: goto P_0c094726;
case 0x0c094728u: goto P_0c094728;
case 0x0c09472au: goto P_0c09472a;
case 0x0c09472cu: goto P_0c09472c;
case 0x0c09472eu: goto P_0c09472e;
case 0x0c094730u: goto P_0c094730;
case 0x0c094732u: goto P_0c094732;
case 0x0c094734u: goto P_0c094734;
case 0x0c094736u: goto P_0c094736;
case 0x0c094738u: goto P_0c094738;
case 0x0c09473au: goto P_0c09473a;
case 0x0c09473cu: goto P_0c09473c;
case 0x0c09473eu: goto P_0c09473e;
case 0x0c094740u: goto P_0c094740;
case 0x0c094742u: goto P_0c094742;
case 0x0c094744u: goto P_0c094744;
case 0x0c094746u: goto P_0c094746;
case 0x0c094748u: goto P_0c094748;
case 0x0c09474au: goto P_0c09474a;
case 0x0c09474cu: goto P_0c09474c;
case 0x0c09474eu: goto P_0c09474e;
case 0x0c094750u: goto P_0c094750;
case 0x0c094752u: goto P_0c094752;
case 0x0c094754u: goto P_0c094754;
case 0x0c094756u: goto P_0c094756;
case 0x0c094758u: goto P_0c094758;
case 0x0c09477cu: goto P_0c09477c;
case 0x0c09477eu: goto P_0c09477e;
case 0x0c094780u: goto P_0c094780;
case 0x0c094782u: goto P_0c094782;
case 0x0c094784u: goto P_0c094784;
case 0x0c094786u: goto P_0c094786;
case 0x0c094788u: goto P_0c094788;
case 0x0c09478au: goto P_0c09478a;
case 0x0c09478cu: goto P_0c09478c;
case 0x0c09478eu: goto P_0c09478e;
case 0x0c094790u: goto P_0c094790;
case 0x0c094792u: goto P_0c094792;
case 0x0c094794u: goto P_0c094794;
case 0x0c094796u: goto P_0c094796;
case 0x0c094798u: goto P_0c094798;
case 0x0c09479au: goto P_0c09479a;
case 0x0c09479cu: goto P_0c09479c;
case 0x0c09479eu: goto P_0c09479e;
case 0x0c0947a0u: goto P_0c0947a0;
case 0x0c0947a2u: goto P_0c0947a2;
case 0x0c0947a4u: goto P_0c0947a4;
case 0x0c0947a6u: goto P_0c0947a6;
case 0x0c0947a8u: goto P_0c0947a8;
case 0x0c0947aau: goto P_0c0947aa;
case 0x0c0947acu: goto P_0c0947ac;
case 0x0c0947aeu: goto P_0c0947ae;
case 0x0c0947b0u: goto P_0c0947b0;
case 0x0c0947b2u: goto P_0c0947b2;
case 0x0c0947b4u: goto P_0c0947b4;
case 0x0c0947b6u: goto P_0c0947b6;
case 0x0c0947b8u: goto P_0c0947b8;
case 0x0c0947bau: goto P_0c0947ba;
case 0x0c0947bcu: goto P_0c0947bc;
case 0x0c0947beu: goto P_0c0947be;
case 0x0c0947c0u: goto P_0c0947c0;
case 0x0c0947c2u: goto P_0c0947c2;
case 0x0c0947c4u: goto P_0c0947c4;
case 0x0c0947c6u: goto P_0c0947c6;
case 0x0c0947c8u: goto P_0c0947c8;
case 0x0c0947cau: goto P_0c0947ca;
case 0x0c0947ccu: goto P_0c0947cc;
case 0x0c0947ceu: goto P_0c0947ce;
case 0x0c0947d0u: goto P_0c0947d0;
case 0x0c0947d2u: goto P_0c0947d2;
case 0x0c0947d4u: goto P_0c0947d4;
case 0x0c0947d6u: goto P_0c0947d6;
case 0x0c0947d8u: goto P_0c0947d8;
case 0x0c0947dau: goto P_0c0947da;
case 0x0c0947dcu: goto P_0c0947dc;
case 0x0c0947deu: goto P_0c0947de;
case 0x0c0947e0u: goto P_0c0947e0;
case 0x0c0947e2u: goto P_0c0947e2;
case 0x0c0947e4u: goto P_0c0947e4;
case 0x0c0947e6u: goto P_0c0947e6;
case 0x0c0947e8u: goto P_0c0947e8;
case 0x0c0947eau: goto P_0c0947ea;
case 0x0c0947ecu: goto P_0c0947ec;
case 0x0c0947eeu: goto P_0c0947ee;
case 0x0c0947f0u: goto P_0c0947f0;
case 0x0c0947f2u: goto P_0c0947f2;
case 0x0c0947f4u: goto P_0c0947f4;
case 0x0c0947f6u: goto P_0c0947f6;
case 0x0c0947f8u: goto P_0c0947f8;
case 0x0c0947fau: goto P_0c0947fa;
case 0x0c0947fcu: goto P_0c0947fc;
case 0x0c0947feu: goto P_0c0947fe;
case 0x0c094800u: goto P_0c094800;
case 0x0c094802u: goto P_0c094802;
case 0x0c094804u: goto P_0c094804;
case 0x0c094806u: goto P_0c094806;
case 0x0c094808u: goto P_0c094808;
case 0x0c09480au: goto P_0c09480a;
case 0x0c09480cu: goto P_0c09480c;
case 0x0c09480eu: goto P_0c09480e;
case 0x0c094810u: goto P_0c094810;
case 0x0c094812u: goto P_0c094812;
case 0x0c094814u: goto P_0c094814;
case 0x0c094816u: goto P_0c094816;
case 0x0c094818u: goto P_0c094818;
case 0x0c09481au: goto P_0c09481a;
case 0x0c09481cu: goto P_0c09481c;
case 0x0c09481eu: goto P_0c09481e;
case 0x0c094820u: goto P_0c094820;
case 0x0c094822u: goto P_0c094822;
case 0x0c094824u: goto P_0c094824;
case 0x0c094826u: goto P_0c094826;
case 0x0c094828u: goto P_0c094828;
case 0x0c09482au: goto P_0c09482a;
case 0x0c09482cu: goto P_0c09482c;
case 0x0c09482eu: goto P_0c09482e;
case 0x0c094830u: goto P_0c094830;
case 0x0c094832u: goto P_0c094832;
case 0x0c094834u: goto P_0c094834;
case 0x0c094836u: goto P_0c094836;
case 0x0c094838u: goto P_0c094838;
case 0x0c09483au: goto P_0c09483a;
case 0x0c09483cu: goto P_0c09483c;
case 0x0c09483eu: goto P_0c09483e;
case 0x0c094840u: goto P_0c094840;
case 0x0c094842u: goto P_0c094842;
case 0x0c094844u: goto P_0c094844;
case 0x0c094846u: goto P_0c094846;
case 0x0c094848u: goto P_0c094848;
case 0x0c09484au: goto P_0c09484a;
case 0x0c09484cu: goto P_0c09484c;
case 0x0c09484eu: goto P_0c09484e;
case 0x0c094850u: goto P_0c094850;
case 0x0c094852u: goto P_0c094852;
case 0x0c094854u: goto P_0c094854;
case 0x0c094856u: goto P_0c094856;
case 0x0c094858u: goto P_0c094858;
case 0x0c09485au: goto P_0c09485a;
case 0x0c09485cu: goto P_0c09485c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0945f2: /* original 2fe6, guest PC 0x0c0945f2 */
if(!s->budget--) { s->failed_pc=0x0c0945f2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0945f4;
P_0c0945f4: /* original 2fd6, guest PC 0x0c0945f4 */
if(!s->budget--) { s->failed_pc=0x0c0945f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0945f6;
P_0c0945f6: /* original 2fc6, guest PC 0x0c0945f6 */
if(!s->budget--) { s->failed_pc=0x0c0945f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0945f8;
P_0c0945f8: /* original 2fb6, guest PC 0x0c0945f8 */
if(!s->budget--) { s->failed_pc=0x0c0945f8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0945fa;
P_0c0945fa: /* original 2fa6, guest PC 0x0c0945fa */
if(!s->budget--) { s->failed_pc=0x0c0945fau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0945fc;
P_0c0945fc: /* original 2f96, guest PC 0x0c0945fc */
if(!s->budget--) { s->failed_pc=0x0c0945fcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0945fe;
P_0c0945fe: /* original 2f86, guest PC 0x0c0945fe */
if(!s->budget--) { s->failed_pc=0x0c0945feu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094600;
P_0c094600: /* original fffb, guest PC 0x0c094600 */
if(!s->budget--) { s->failed_pc=0x0c094600u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c094602;
P_0c094602: /* original ffeb, guest PC 0x0c094602 */
if(!s->budget--) { s->failed_pc=0x0c094602u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c094604;
P_0c094604: /* original ffdb, guest PC 0x0c094604 */
if(!s->budget--) { s->failed_pc=0x0c094604u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c094606;
P_0c094606: /* original ffcb, guest PC 0x0c094606 */
if(!s->budget--) { s->failed_pc=0x0c094606u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c094608;
P_0c094608: /* original d11d, guest PC 0x0c094608 */
if(!s->budget--) { s->failed_pc=0x0c094608u; return 0; }
r[1]=read(ram,0x0c094680u,4);
goto P_0c09460a;
P_0c09460a: /* original 4f22, guest PC 0x0c09460a */
if(!s->budget--) { s->failed_pc=0x0c09460au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09460c;
P_0c09460c: /* original d31b, guest PC 0x0c09460c */
if(!s->budget--) { s->failed_pc=0x0c09460cu; return 0; }
r[3]=read(ram,0x0c09467cu,4);
goto P_0c09460e;
P_0c09460e: /* original 6212, guest PC 0x0c09460e */
if(!s->budget--) { s->failed_pc=0x0c09460eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c094610;
P_0c094610: /* original 7fd8, guest PC 0x0c094610 */
if(!s->budget--) { s->failed_pc=0x0c094610u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c094612;
P_0c094612: /* original 2238, guest PC 0x0c094612 */
if(!s->budget--) { s->failed_pc=0x0c094612u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c094614;
P_0c094614: /* original 8901, guest PC 0x0c094614 */
if(!s->budget--) { s->failed_pc=0x0c094614u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09461a; }
goto P_0c094616;
P_0c094616: /* original a114, guest PC 0x0c094616 */
if(!s->budget--) { s->failed_pc=0x0c094616u; return 0; }
goto P_0c094842;
P_0c094618: /* original 0009, guest PC 0x0c094618 */
if(!s->budget--) { s->failed_pc=0x0c094618u; return 0; }
goto P_0c09461a;
P_0c09461a: /* original d61a, guest PC 0x0c09461a */
if(!s->budget--) { s->failed_pc=0x0c09461au; return 0; }
r[6]=read(ram,0x0c094684u,4);
goto P_0c09461c;
P_0c09461c: /* original e061, guest PC 0x0c09461c */
if(!s->budget--) { s->failed_pc=0x0c09461cu; return 0; }
r[0]=0x00000061u;
goto P_0c09461e;
P_0c09461e: /* original 5564, guest PC 0x0c09461e */
if(!s->budget--) { s->failed_pc=0x0c09461eu; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c094620;
P_0c094620: /* original 005c, guest PC 0x0c094620 */
if(!s->budget--) { s->failed_pc=0x0c094620u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c094622;
P_0c094622: /* original 600c, guest PC 0x0c094622 */
if(!s->budget--) { s->failed_pc=0x0c094622u; return 0; }
r[0]=r[0]&255u;
goto P_0c094624;
P_0c094624: /* original 880b, guest PC 0x0c094624 */
if(!s->budget--) { s->failed_pc=0x0c094624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c094626;
P_0c094626: /* original 8f07, guest PC 0x0c094626 */
if(!s->budget--) { s->failed_pc=0x0c094626u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[6]+20,4);
if(!cond) { goto P_0c094638; }
goto P_0c09462a;
P_0c094628: /* original 5665, guest PC 0x0c094628 */
if(!s->budget--) { s->failed_pc=0x0c094628u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c09462a;
P_0c09462a: /* original e061, guest PC 0x0c09462a */
if(!s->budget--) { s->failed_pc=0x0c09462au; return 0; }
r[0]=0x00000061u;
goto P_0c09462c;
P_0c09462c: /* original 006c, guest PC 0x0c09462c */
if(!s->budget--) { s->failed_pc=0x0c09462cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c09462e;
P_0c09462e: /* original 600c, guest PC 0x0c09462e */
if(!s->budget--) { s->failed_pc=0x0c09462eu; return 0; }
r[0]=r[0]&255u;
goto P_0c094630;
P_0c094630: /* original 8806, guest PC 0x0c094630 */
if(!s->budget--) { s->failed_pc=0x0c094630u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c094632;
P_0c094632: /* original 8b01, guest PC 0x0c094632 */
if(!s->budget--) { s->failed_pc=0x0c094632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094638; }
goto P_0c094634;
P_0c094634: /* original a105, guest PC 0x0c094634 */
if(!s->budget--) { s->failed_pc=0x0c094634u; return 0; }
goto P_0c094842;
P_0c094636: /* original 0009, guest PC 0x0c094636 */
if(!s->budget--) { s->failed_pc=0x0c094636u; return 0; }
goto P_0c094638;
P_0c094638: /* original 9011, guest PC 0x0c094638 */
if(!s->budget--) { s->failed_pc=0x0c094638u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09465eu,2);
goto P_0c09463a;
P_0c09463a: /* original 6e43, guest PC 0x0c09463a */
if(!s->budget--) { s->failed_pc=0x0c09463au; return 0; }
r[14]=r[4];
goto P_0c09463c;
P_0c09463c: /* original f356, guest PC 0x0c09463c */
if(!s->budget--) { s->failed_pc=0x0c09463cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c09463e;
P_0c09463e: /* original e020, guest PC 0x0c09463e */
if(!s->budget--) { s->failed_pc=0x0c09463eu; return 0; }
r[0]=0x00000020u;
goto P_0c094640;
P_0c094640: /* original ff37, guest PC 0x0c094640 */
if(!s->budget--) { s->failed_pc=0x0c094640u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c094642;
P_0c094642: /* original 900d, guest PC 0x0c094642 */
if(!s->budget--) { s->failed_pc=0x0c094642u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094660u,2);
goto P_0c094644;
P_0c094644: /* original f356, guest PC 0x0c094644 */
if(!s->budget--) { s->failed_pc=0x0c094644u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c094646;
P_0c094646: /* original e018, guest PC 0x0c094646 */
if(!s->budget--) { s->failed_pc=0x0c094646u; return 0; }
r[0]=0x00000018u;
goto P_0c094648;
P_0c094648: /* original ff37, guest PC 0x0c094648 */
if(!s->budget--) { s->failed_pc=0x0c094648u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09464a;
P_0c09464a: /* original 9008, guest PC 0x0c09464a */
if(!s->budget--) { s->failed_pc=0x0c09464au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09465eu,2);
goto P_0c09464c;
P_0c09464c: /* original f366, guest PC 0x0c09464c */
if(!s->budget--) { s->failed_pc=0x0c09464cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c09464e;
P_0c09464e: /* original e01c, guest PC 0x0c09464e */
if(!s->budget--) { s->failed_pc=0x0c09464eu; return 0; }
r[0]=0x0000001cu;
goto P_0c094650;
P_0c094650: /* original ff37, guest PC 0x0c094650 */
if(!s->budget--) { s->failed_pc=0x0c094650u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c094652;
P_0c094652: /* original 9005, guest PC 0x0c094652 */
if(!s->budget--) { s->failed_pc=0x0c094652u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094660u,2);
goto P_0c094654;
P_0c094654: /* original f366, guest PC 0x0c094654 */
if(!s->budget--) { s->failed_pc=0x0c094654u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c094656;
P_0c094656: /* original e024, guest PC 0x0c094656 */
if(!s->budget--) { s->failed_pc=0x0c094656u; return 0; }
r[0]=0x00000024u;
goto P_0c094658;
P_0c094658: /* original ff37, guest PC 0x0c094658 */
if(!s->budget--) { s->failed_pc=0x0c094658u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09465a;
P_0c09465a: /* original a0ec, guest PC 0x0c09465a */
if(!s->budget--) { s->failed_pc=0x0c09465au; return 0; }
r[3]=0x00000000u;
goto P_0c094836;
P_0c09465c: /* original e300, guest PC 0x0c09465c */
if(!s->budget--) { s->failed_pc=0x0c09465cu; return 0; }
r[3]=0x00000000u;
if(!vf3_matrix_family(0x0c09465eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09465eu; return 0; } return 1;
P_0c094688: /* original e004, guest PC 0x0c094688 */
if(!s->budget--) { s->failed_pc=0x0c094688u; return 0; }
r[0]=0x00000004u;
goto P_0c09468a;
P_0c09468a: /* original d934, guest PC 0x0c09468a */
if(!s->budget--) { s->failed_pc=0x0c09468au; return 0; }
r[9]=read(ram,0x0c09475cu,4);
goto P_0c09468c;
P_0c09468c: /* original fce6, guest PC 0x0c09468c */
if(!s->budget--) { s->failed_pc=0x0c09468cu; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c09468e;
P_0c09468e: /* original e008, guest PC 0x0c09468e */
if(!s->budget--) { s->failed_pc=0x0c09468eu; return 0; }
r[0]=0x00000008u;
goto P_0c094690;
P_0c094690: /* original fee6, guest PC 0x0c094690 */
if(!s->budget--) { s->failed_pc=0x0c094690u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c094692;
P_0c094692: /* original e00c, guest PC 0x0c094692 */
if(!s->budget--) { s->failed_pc=0x0c094692u; return 0; }
r[0]=0x0000000cu;
goto P_0c094694;
P_0c094694: /* original fde6, guest PC 0x0c094694 */
if(!s->budget--) { s->failed_pc=0x0c094694u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c094696;
P_0c094696: /* original e401, guest PC 0x0c094696 */
if(!s->budget--) { s->failed_pc=0x0c094696u; return 0; }
r[4]=0x00000001u;
goto P_0c094698;
P_0c094698: /* original 85e8, guest PC 0x0c094698 */
if(!s->budget--) { s->failed_pc=0x0c094698u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c09469a;
P_0c09469a: /* original 6b03, guest PC 0x0c09469a */
if(!s->budget--) { s->failed_pc=0x0c09469au; return 0; }
r[11]=r[0];
goto P_0c09469c;
P_0c09469c: /* original 85e9, guest PC 0x0c09469c */
if(!s->budget--) { s->failed_pc=0x0c09469cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+18,2);
goto P_0c09469e;
P_0c09469e: /* original 6803, guest PC 0x0c09469e */
if(!s->budget--) { s->failed_pc=0x0c09469eu; return 0; }
r[8]=r[0];
goto P_0c0946a0;
P_0c0946a0: /* original 85ea, guest PC 0x0c0946a0 */
if(!s->budget--) { s->failed_pc=0x0c0946a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+20,2);
goto P_0c0946a2;
P_0c0946a2: /* original 6d03, guest PC 0x0c0946a2 */
if(!s->budget--) { s->failed_pc=0x0c0946a2u; return 0; }
r[13]=r[0];
goto P_0c0946a4;
P_0c0946a4: /* original e016, guest PC 0x0c0946a4 */
if(!s->budget--) { s->failed_pc=0x0c0946a4u; return 0; }
r[0]=0x00000016u;
goto P_0c0946a6;
P_0c0946a6: /* original 0aec, guest PC 0x0c0946a6 */
if(!s->budget--) { s->failed_pc=0x0c0946a6u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0946a8;
P_0c0946a8: /* original e017, guest PC 0x0c0946a8 */
if(!s->budget--) { s->failed_pc=0x0c0946a8u; return 0; }
r[0]=0x00000017u;
goto P_0c0946aa;
P_0c0946aa: /* original 0cec, guest PC 0x0c0946aa */
if(!s->budget--) { s->failed_pc=0x0c0946aau; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0946ac;
P_0c0946ac: /* original 63ce, guest PC 0x0c0946ac */
if(!s->budget--) { s->failed_pc=0x0c0946acu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c0946ae;
P_0c0946ae: /* original 2348, guest PC 0x0c0946ae */
if(!s->budget--) { s->failed_pc=0x0c0946aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0946b0;
P_0c0946b0: /* original 8d64, guest PC 0x0c0946b0 */
if(!s->budget--) { s->failed_pc=0x0c0946b0u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[14]);
if(cond) { goto P_0c09477c; }
goto P_0c0946b4;
P_0c0946b2: /* original ffe8, guest PC 0x0c0946b2 */
if(!s->budget--) { s->failed_pc=0x0c0946b2u; return 0; }
vf3_matrix_load(s,ram,15,r[14]);
goto P_0c0946b4;
P_0c0946b4: /* original c72a, guest PC 0x0c0946b4 */
if(!s->budget--) { s->failed_pc=0x0c0946b4u; return 0; }
r[0]=code_base|0x00094760u;
goto P_0c0946b6;
P_0c0946b6: /* original f408, guest PC 0x0c0946b6 */
if(!s->budget--) { s->failed_pc=0x0c0946b6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0946b8;
P_0c0946b8: /* original e004, guest PC 0x0c0946b8 */
if(!s->budget--) { s->failed_pc=0x0c0946b8u; return 0; }
r[0]=0x00000004u;
goto P_0c0946ba;
P_0c0946ba: /* original 3b8c, guest PC 0x0c0946ba */
if(!s->budget--) { s->failed_pc=0x0c0946bau; return 0; }
r[11]+=r[8];
goto P_0c0946bc;
P_0c0946bc: /* original 6abf, guest PC 0x0c0946bc */
if(!s->budget--) { s->failed_pc=0x0c0946bcu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c0946be;
P_0c0946be: /* original ff47, guest PC 0x0c0946be */
if(!s->budget--) { s->failed_pc=0x0c0946beu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0946c0;
P_0c0946c0: /* original d328, guest PC 0x0c0946c0 */
if(!s->budget--) { s->failed_pc=0x0c0946c0u; return 0; }
r[3]=read(ram,0x0c094764u,4);
goto P_0c0946c2;
P_0c0946c2: /* original 430b, guest PC 0x0c0946c2 */
if(!s->budget--) { s->failed_pc=0x0c0946c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0946c6u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0946c6u) { target=s->pc; goto dispatch; }
goto P_0c0946c6;
P_0c0946c4: /* original 64a3, guest PC 0x0c0946c4 */
if(!s->budget--) { s->failed_pc=0x0c0946c4u; return 0; }
r[4]=r[10];
goto P_0c0946c6;
P_0c0946c6: /* original e010, guest PC 0x0c0946c6 */
if(!s->budget--) { s->failed_pc=0x0c0946c6u; return 0; }
r[0]=0x00000010u;
goto P_0c0946c8;
P_0c0946c8: /* original ff07, guest PC 0x0c0946c8 */
if(!s->budget--) { s->failed_pc=0x0c0946c8u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0946ca;
P_0c0946ca: /* original d327, guest PC 0x0c0946ca */
if(!s->budget--) { s->failed_pc=0x0c0946cau; return 0; }
r[3]=read(ram,0x0c094768u,4);
goto P_0c0946cc;
P_0c0946cc: /* original 430b, guest PC 0x0c0946cc */
if(!s->budget--) { s->failed_pc=0x0c0946ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0946d0u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0946d0u) { target=s->pc; goto dispatch; }
goto P_0c0946d0;
P_0c0946ce: /* original 64a3, guest PC 0x0c0946ce */
if(!s->budget--) { s->failed_pc=0x0c0946ceu; return 0; }
r[4]=r[10];
goto P_0c0946d0;
P_0c0946d0: /* original e004, guest PC 0x0c0946d0 */
if(!s->budget--) { s->failed_pc=0x0c0946d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0946d2;
P_0c0946d2: /* original f40c, guest PC 0x0c0946d2 */
if(!s->budget--) { s->failed_pc=0x0c0946d2u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0946d4;
P_0c0946d4: /* original f0f6, guest PC 0x0c0946d4 */
if(!s->budget--) { s->failed_pc=0x0c0946d4u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0946d6;
P_0c0946d6: /* original e010, guest PC 0x0c0946d6 */
if(!s->budget--) { s->failed_pc=0x0c0946d6u; return 0; }
r[0]=0x00000010u;
goto P_0c0946d8;
P_0c0946d8: /* original f3fc, guest PC 0x0c0946d8 */
if(!s->budget--) { s->failed_pc=0x0c0946d8u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0946da;
P_0c0946da: /* original f2f6, guest PC 0x0c0946da */
if(!s->budget--) { s->failed_pc=0x0c0946dau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0946dc;
P_0c0946dc: /* original f34e, guest PC 0x0c0946dc */
if(!s->budget--) { s->failed_pc=0x0c0946dcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0946de;
P_0c0946de: /* original c723, guest PC 0x0c0946de */
if(!s->budget--) { s->failed_pc=0x0c0946deu; return 0; }
r[0]=code_base|0x0009476cu;
goto P_0c0946e0;
P_0c0946e0: /* original f408, guest PC 0x0c0946e0 */
if(!s->budget--) { s->failed_pc=0x0c0946e0u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0946e2;
P_0c0946e2: /* original c723, guest PC 0x0c0946e2 */
if(!s->budget--) { s->failed_pc=0x0c0946e2u; return 0; }
r[0]=code_base|0x00094770u;
goto P_0c0946e4;
P_0c0946e4: /* original fd41, guest PC 0x0c0946e4 */
if(!s->budget--) { s->failed_pc=0x0c0946e4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'-');
goto P_0c0946e6;
P_0c0946e6: /* original ff3c, guest PC 0x0c0946e6 */
if(!s->budget--) { s->failed_pc=0x0c0946e6u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0946e8;
P_0c0946e8: /* original f408, guest PC 0x0c0946e8 */
if(!s->budget--) { s->failed_pc=0x0c0946e8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0946ea;
P_0c0946ea: /* original f3ec, guest PC 0x0c0946ea */
if(!s->budget--) { s->failed_pc=0x0c0946eau; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0946ec;
P_0c0946ec: /* original f32e, guest PC 0x0c0946ec */
if(!s->budget--) { s->failed_pc=0x0c0946ecu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0946ee;
P_0c0946ee: /* original f4d5, guest PC 0x0c0946ee */
if(!s->budget--) { s->failed_pc=0x0c0946eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[13]))!=0);
goto P_0c0946f0;
P_0c0946f0: /* original 8f01, guest PC 0x0c0946f0 */
if(!s->budget--) { s->failed_pc=0x0c0946f0u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,14,3);
if(!cond) { goto P_0c0946f6; }
goto P_0c0946f4;
P_0c0946f2: /* original fe3c, guest PC 0x0c0946f2 */
if(!s->budget--) { s->failed_pc=0x0c0946f2u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0946f4;
P_0c0946f4: /* original fd4c, guest PC 0x0c0946f4 */
if(!s->budget--) { s->failed_pc=0x0c0946f4u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c0946f6;
P_0c0946f6: /* original e020, guest PC 0x0c0946f6 */
if(!s->budget--) { s->failed_pc=0x0c0946f6u; return 0; }
r[0]=0x00000020u;
goto P_0c0946f8;
P_0c0946f8: /* original f2fc, guest PC 0x0c0946f8 */
if(!s->budget--) { s->failed_pc=0x0c0946f8u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0946fa;
P_0c0946fa: /* original f3f6, guest PC 0x0c0946fa */
if(!s->budget--) { s->failed_pc=0x0c0946fau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0946fc;
P_0c0946fc: /* original e018, guest PC 0x0c0946fc */
if(!s->budget--) { s->failed_pc=0x0c0946fcu; return 0; }
r[0]=0x00000018u;
goto P_0c0946fe;
P_0c0946fe: /* original f1ec, guest PC 0x0c0946fe */
if(!s->budget--) { s->failed_pc=0x0c0946feu; return 0; }
vf3_matrix_move(s,1,14);
goto P_0c094700;
P_0c094700: /* original f231, guest PC 0x0c094700 */
if(!s->budget--) { s->failed_pc=0x0c094700u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c094702;
P_0c094702: /* original f0fc, guest PC 0x0c094702 */
if(!s->budget--) { s->failed_pc=0x0c094702u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c094704;
P_0c094704: /* original f25d, guest PC 0x0c094704 */
if(!s->budget--) { s->failed_pc=0x0c094704u; return 0; }
fr[2]&=0x7fffffffu;
goto P_0c094706;
P_0c094706: /* original f52c, guest PC 0x0c094706 */
if(!s->budget--) { s->failed_pc=0x0c094706u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c094708;
P_0c094708: /* original f2f6, guest PC 0x0c094708 */
if(!s->budget--) { s->failed_pc=0x0c094708u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09470a;
P_0c09470a: /* original e01c, guest PC 0x0c09470a */
if(!s->budget--) { s->failed_pc=0x0c09470au; return 0; }
r[0]=0x0000001cu;
goto P_0c09470c;
P_0c09470c: /* original f121, guest PC 0x0c09470c */
if(!s->budget--) { s->failed_pc=0x0c09470cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
goto P_0c09470e;
P_0c09470e: /* original f15d, guest PC 0x0c09470e */
if(!s->budget--) { s->failed_pc=0x0c09470eu; return 0; }
fr[1]&=0x7fffffffu;
goto P_0c094710;
P_0c094710: /* original f71c, guest PC 0x0c094710 */
if(!s->budget--) { s->failed_pc=0x0c094710u; return 0; }
vf3_matrix_move(s,7,1);
goto P_0c094712;
P_0c094712: /* original f570, guest PC 0x0c094712 */
if(!s->budget--) { s->failed_pc=0x0c094712u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c094714;
P_0c094714: /* original f1f6, guest PC 0x0c094714 */
if(!s->budget--) { s->failed_pc=0x0c094714u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c094716;
P_0c094716: /* original e024, guest PC 0x0c094716 */
if(!s->budget--) { s->failed_pc=0x0c094716u; return 0; }
r[0]=0x00000024u;
goto P_0c094718;
P_0c094718: /* original f3f6, guest PC 0x0c094718 */
if(!s->budget--) { s->failed_pc=0x0c094718u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09471a;
P_0c09471a: /* original c716, guest PC 0x0c09471a */
if(!s->budget--) { s->failed_pc=0x0c09471au; return 0; }
r[0]=code_base|0x00094774u;
goto P_0c09471c;
P_0c09471c: /* original f011, guest PC 0x0c09471c */
if(!s->budget--) { s->failed_pc=0x0c09471cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c09471e;
P_0c09471e: /* original f05d, guest PC 0x0c09471e */
if(!s->budget--) { s->failed_pc=0x0c09471eu; return 0; }
fr[0]&=0x7fffffffu;
goto P_0c094720;
P_0c094720: /* original f60c, guest PC 0x0c094720 */
if(!s->budget--) { s->failed_pc=0x0c094720u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c094722;
P_0c094722: /* original f0ec, guest PC 0x0c094722 */
if(!s->budget--) { s->failed_pc=0x0c094722u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c094724;
P_0c094724: /* original f031, guest PC 0x0c094724 */
if(!s->budget--) { s->failed_pc=0x0c094724u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c094726;
P_0c094726: /* original f05d, guest PC 0x0c094726 */
if(!s->budget--) { s->failed_pc=0x0c094726u; return 0; }
fr[0]&=0x7fffffffu;
goto P_0c094728;
P_0c094728: /* original f40c, guest PC 0x0c094728 */
if(!s->budget--) { s->failed_pc=0x0c094728u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c09472a;
P_0c09472a: /* original f640, guest PC 0x0c09472a */
if(!s->budget--) { s->failed_pc=0x0c09472au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c09472c;
P_0c09472c: /* original f408, guest PC 0x0c09472c */
if(!s->budget--) { s->failed_pc=0x0c09472cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09472e;
P_0c09472e: /* original f455, guest PC 0x0c09472e */
if(!s->budget--) { s->failed_pc=0x0c09472eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c094730;
P_0c094730: /* original 8d09, guest PC 0x0c094730 */
if(!s->budget--) { s->failed_pc=0x0c094730u; return 0; }
cond=r[17]&1u;
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'+');
if(cond) { goto P_0c094746; }
goto P_0c094734;
P_0c094732: /* original fcd0, guest PC 0x0c094732 */
if(!s->budget--) { s->failed_pc=0x0c094732u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'+');
goto P_0c094734;
P_0c094734: /* original f465, guest PC 0x0c094734 */
if(!s->budget--) { s->failed_pc=0x0c094734u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c094736;
P_0c094736: /* original 8906, guest PC 0x0c094736 */
if(!s->budget--) { s->failed_pc=0x0c094736u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094746; }
goto P_0c094738;
P_0c094738: /* original 63df, guest PC 0x0c094738 */
if(!s->budget--) { s->failed_pc=0x0c094738u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c09473a;
P_0c09473a: /* original 2338, guest PC 0x0c09473a */
if(!s->budget--) { s->failed_pc=0x0c09473au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09473c;
P_0c09473c: /* original 8903, guest PC 0x0c09473c */
if(!s->budget--) { s->failed_pc=0x0c09473cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094746; }
goto P_0c09473e;
P_0c09473e: /* original c70e, guest PC 0x0c09473e */
if(!s->budget--) { s->failed_pc=0x0c09473eu; return 0; }
r[0]=code_base|0x00094778u;
goto P_0c094740;
P_0c094740: /* original f208, guest PC 0x0c094740 */
if(!s->budget--) { s->failed_pc=0x0c094740u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c094742;
P_0c094742: /* original f2c5, guest PC 0x0c094742 */
if(!s->budget--) { s->failed_pc=0x0c094742u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[12]))!=0);
goto P_0c094744;
P_0c094744: /* original 8b06, guest PC 0x0c094744 */
if(!s->budget--) { s->failed_pc=0x0c094744u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094754; }
goto P_0c094746;
P_0c094746: /* original e2fe, guest PC 0x0c094746 */
if(!s->budget--) { s->failed_pc=0x0c094746u; return 0; }
r[2]=0xfffffffeu;
goto P_0c094748;
P_0c094748: /* original e302, guest PC 0x0c094748 */
if(!s->budget--) { s->failed_pc=0x0c094748u; return 0; }
r[3]=0x00000002u;
goto P_0c09474a;
P_0c09474a: /* original 2c29, guest PC 0x0c09474a */
if(!s->budget--) { s->failed_pc=0x0c09474au; return 0; }
r[12]&=r[2];
goto P_0c09474c;
P_0c09474c: /* original 490b, guest PC 0x0c09474c */
if(!s->budget--) { s->failed_pc=0x0c09474cu; return 0; }
target=r[9];
r[16]=code_base|0x0c094750u;
r[12]|=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094750u) { target=s->pc; goto dispatch; }
goto P_0c094750;
P_0c09474e: /* original 2c3b, guest PC 0x0c09474e */
if(!s->budget--) { s->failed_pc=0x0c09474eu; return 0; }
r[12]|=r[3];
goto P_0c094750;
P_0c094750: /* original 9d03, guest PC 0x0c094750 */
if(!s->budget--) { s->failed_pc=0x0c094750u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09475au,2);
goto P_0c094752;
P_0c094752: /* original 2d09, guest PC 0x0c094752 */
if(!s->budget--) { s->failed_pc=0x0c094752u; return 0; }
r[13]&=r[0];
goto P_0c094754;
P_0c094754: /* original e407, guest PC 0x0c094754 */
if(!s->budget--) { s->failed_pc=0x0c094754u; return 0; }
r[4]=0x00000007u;
goto P_0c094756;
P_0c094756: /* original a048, guest PC 0x0c094756 */
if(!s->budget--) { s->failed_pc=0x0c094756u; return 0; }
r[10]=r[4];
goto P_0c0947ea;
P_0c094758: /* original 6a43, guest PC 0x0c094758 */
if(!s->budget--) { s->failed_pc=0x0c094758u; return 0; }
r[10]=r[4];
if(!vf3_matrix_family(0x0c09475au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09475au; return 0; } return 1;
P_0c09477c: /* original c739, guest PC 0x0c09477c */
if(!s->budget--) { s->failed_pc=0x0c09477cu; return 0; }
r[0]=code_base|0x00094864u;
goto P_0c09477e;
P_0c09477e: /* original f308, guest PC 0x0c09477e */
if(!s->budget--) { s->failed_pc=0x0c09477eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c094780;
P_0c094780: /* original e30f, guest PC 0x0c094780 */
if(!s->budget--) { s->failed_pc=0x0c094780u; return 0; }
r[3]=0x0000000fu;
goto P_0c094782;
P_0c094782: /* original 7a01, guest PC 0x0c094782 */
if(!s->budget--) { s->failed_pc=0x0c094782u; return 0; }
r[10]+=0x00000001u;
goto P_0c094784;
P_0c094784: /* original 2a39, guest PC 0x0c094784 */
if(!s->budget--) { s->failed_pc=0x0c094784u; return 0; }
r[10]&=r[3];
goto P_0c094786;
P_0c094786: /* original ff3a, guest PC 0x0c094786 */
if(!s->budget--) { s->failed_pc=0x0c094786u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c094788;
P_0c094788: /* original d237, guest PC 0x0c094788 */
if(!s->budget--) { s->failed_pc=0x0c094788u; return 0; }
r[2]=read(ram,0x0c094868u,4);
goto P_0c09478a;
P_0c09478a: /* original 64bf, guest PC 0x0c09478a */
if(!s->budget--) { s->failed_pc=0x0c09478au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c09478c;
P_0c09478c: /* original 420b, guest PC 0x0c09478c */
if(!s->budget--) { s->failed_pc=0x0c09478cu; return 0; }
target=r[2];
r[16]=code_base|0x0c094790u;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094790u) { target=s->pc; goto dispatch; }
goto P_0c094790;
P_0c09478e: /* original 1f43, guest PC 0x0c09478e */
if(!s->budget--) { s->failed_pc=0x0c09478eu; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c094790;
P_0c094790: /* original e014, guest PC 0x0c094790 */
if(!s->budget--) { s->failed_pc=0x0c094790u; return 0; }
r[0]=0x00000014u;
goto P_0c094792;
P_0c094792: /* original ff07, guest PC 0x0c094792 */
if(!s->budget--) { s->failed_pc=0x0c094792u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c094794;
P_0c094794: /* original d335, guest PC 0x0c094794 */
if(!s->budget--) { s->failed_pc=0x0c094794u; return 0; }
r[3]=read(ram,0x0c09486cu,4);
goto P_0c094796;
P_0c094796: /* original 430b, guest PC 0x0c094796 */
if(!s->budget--) { s->failed_pc=0x0c094796u; return 0; }
target=r[3];
r[16]=code_base|0x0c09479au;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09479au) { target=s->pc; goto dispatch; }
goto P_0c09479a;
P_0c094798: /* original 54f3, guest PC 0x0c094798 */
if(!s->budget--) { s->failed_pc=0x0c094798u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c09479a;
P_0c09479a: /* original f40c, guest PC 0x0c09479a */
if(!s->budget--) { s->failed_pc=0x0c09479au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c09479c;
P_0c09479c: /* original e014, guest PC 0x0c09479c */
if(!s->budget--) { s->failed_pc=0x0c09479cu; return 0; }
r[0]=0x00000014u;
goto P_0c09479e;
P_0c09479e: /* original f0f8, guest PC 0x0c09479e */
if(!s->budget--) { s->failed_pc=0x0c09479eu; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c0947a0;
P_0c0947a0: /* original f3fc, guest PC 0x0c0947a0 */
if(!s->budget--) { s->failed_pc=0x0c0947a0u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0947a2;
P_0c0947a2: /* original f34e, guest PC 0x0c0947a2 */
if(!s->budget--) { s->failed_pc=0x0c0947a2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0947a4;
P_0c0947a4: /* original f2f6, guest PC 0x0c0947a4 */
if(!s->budget--) { s->failed_pc=0x0c0947a4u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0947a6;
P_0c0947a6: /* original c732, guest PC 0x0c0947a6 */
if(!s->budget--) { s->failed_pc=0x0c0947a6u; return 0; }
r[0]=code_base|0x00094870u;
goto P_0c0947a8;
P_0c0947a8: /* original f408, guest PC 0x0c0947a8 */
if(!s->budget--) { s->failed_pc=0x0c0947a8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0947aa;
P_0c0947aa: /* original c72e, guest PC 0x0c0947aa */
if(!s->budget--) { s->failed_pc=0x0c0947aau; return 0; }
r[0]=code_base|0x00094864u;
goto P_0c0947ac;
P_0c0947ac: /* original ff3c, guest PC 0x0c0947ac */
if(!s->budget--) { s->failed_pc=0x0c0947acu; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0947ae;
P_0c0947ae: /* original fd40, guest PC 0x0c0947ae */
if(!s->budget--) { s->failed_pc=0x0c0947aeu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'+');
goto P_0c0947b0;
P_0c0947b0: /* original f3ec, guest PC 0x0c0947b0 */
if(!s->budget--) { s->failed_pc=0x0c0947b0u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0947b2;
P_0c0947b2: /* original f32e, guest PC 0x0c0947b2 */
if(!s->budget--) { s->failed_pc=0x0c0947b2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0947b4;
P_0c0947b4: /* original fe3c, guest PC 0x0c0947b4 */
if(!s->budget--) { s->failed_pc=0x0c0947b4u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0947b6;
P_0c0947b6: /* original f308, guest PC 0x0c0947b6 */
if(!s->budget--) { s->failed_pc=0x0c0947b6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0947b8;
P_0c0947b8: /* original fd35, guest PC 0x0c0947b8 */
if(!s->budget--) { s->failed_pc=0x0c0947b8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[3]))!=0);
goto P_0c0947ba;
P_0c0947ba: /* original 8b01, guest PC 0x0c0947ba */
if(!s->budget--) { s->failed_pc=0x0c0947bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0947c0; }
goto P_0c0947bc;
P_0c0947bc: /* original c729, guest PC 0x0c0947bc */
if(!s->budget--) { s->failed_pc=0x0c0947bcu; return 0; }
r[0]=code_base|0x00094864u;
goto P_0c0947be;
P_0c0947be: /* original fd08, guest PC 0x0c0947be */
if(!s->budget--) { s->failed_pc=0x0c0947beu; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c0947c0;
P_0c0947c0: /* original 7dff, guest PC 0x0c0947c0 */
if(!s->budget--) { s->failed_pc=0x0c0947c0u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0947c2;
P_0c0947c2: /* original 63df, guest PC 0x0c0947c2 */
if(!s->budget--) { s->failed_pc=0x0c0947c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0947c4;
P_0c0947c4: /* original 2338, guest PC 0x0c0947c4 */
if(!s->budget--) { s->failed_pc=0x0c0947c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0947c6;
P_0c0947c6: /* original 8d04, guest PC 0x0c0947c6 */
if(!s->budget--) { s->failed_pc=0x0c0947c6u; return 0; }
cond=r[17]&1u;
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'+');
if(cond) { goto P_0c0947d2; }
goto P_0c0947ca;
P_0c0947c8: /* original fcd0, guest PC 0x0c0947c8 */
if(!s->budget--) { s->failed_pc=0x0c0947c8u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'+');
goto P_0c0947ca;
P_0c0947ca: /* original c72a, guest PC 0x0c0947ca */
if(!s->budget--) { s->failed_pc=0x0c0947cau; return 0; }
r[0]=code_base|0x00094874u;
goto P_0c0947cc;
P_0c0947cc: /* original f308, guest PC 0x0c0947cc */
if(!s->budget--) { s->failed_pc=0x0c0947ccu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0947ce;
P_0c0947ce: /* original fc35, guest PC 0x0c0947ce */
if(!s->budget--) { s->failed_pc=0x0c0947ceu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c0947d0;
P_0c0947d0: /* original 8b0b, guest PC 0x0c0947d0 */
if(!s->budget--) { s->failed_pc=0x0c0947d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0947ea; }
goto P_0c0947d2;
P_0c0947d2: /* original 9844, guest PC 0x0c0947d2 */
if(!s->budget--) { s->failed_pc=0x0c0947d2u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09485eu,2);
goto P_0c0947d4;
P_0c0947d4: /* original e2fd, guest PC 0x0c0947d4 */
if(!s->budget--) { s->failed_pc=0x0c0947d4u; return 0; }
r[2]=0xfffffffdu;
goto P_0c0947d6;
P_0c0947d6: /* original 9d43, guest PC 0x0c0947d6 */
if(!s->budget--) { s->failed_pc=0x0c0947d6u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094860u,2);
goto P_0c0947d8;
P_0c0947d8: /* original 2c29, guest PC 0x0c0947d8 */
if(!s->budget--) { s->failed_pc=0x0c0947d8u; return 0; }
r[12]&=r[2];
goto P_0c0947da;
P_0c0947da: /* original e301, guest PC 0x0c0947da */
if(!s->budget--) { s->failed_pc=0x0c0947dau; return 0; }
r[3]=0x00000001u;
goto P_0c0947dc;
P_0c0947dc: /* original 490b, guest PC 0x0c0947dc */
if(!s->budget--) { s->failed_pc=0x0c0947dcu; return 0; }
target=r[9];
r[16]=code_base|0x0c0947e0u;
r[12]|=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0947e0u) { target=s->pc; goto dispatch; }
goto P_0c0947e0;
P_0c0947de: /* original 2c3b, guest PC 0x0c0947de */
if(!s->budget--) { s->failed_pc=0x0c0947deu; return 0; }
r[12]|=r[3];
goto P_0c0947e0;
P_0c0947e0: /* original 20d9, guest PC 0x0c0947e0 */
if(!s->budget--) { s->failed_pc=0x0c0947e0u; return 0; }
r[0]&=r[13];
goto P_0c0947e2;
P_0c0947e2: /* original 490b, guest PC 0x0c0947e2 */
if(!s->budget--) { s->failed_pc=0x0c0947e2u; return 0; }
target=r[9];
r[16]=code_base|0x0c0947e6u;
r[8]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0947e6u) { target=s->pc; goto dispatch; }
goto P_0c0947e6;
P_0c0947e4: /* original 380c, guest PC 0x0c0947e4 */
if(!s->budget--) { s->failed_pc=0x0c0947e4u; return 0; }
r[8]+=r[0];
goto P_0c0947e6;
P_0c0947e6: /* original 7dff, guest PC 0x0c0947e6 */
if(!s->budget--) { s->failed_pc=0x0c0947e6u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0947e8;
P_0c0947e8: /* original 2d09, guest PC 0x0c0947e8 */
if(!s->budget--) { s->failed_pc=0x0c0947e8u; return 0; }
r[13]&=r[0];
goto P_0c0947ea;
P_0c0947ea: /* original c723, guest PC 0x0c0947ea */
if(!s->budget--) { s->failed_pc=0x0c0947eau; return 0; }
r[0]=code_base|0x00094878u;
goto P_0c0947ec;
P_0c0947ec: /* original f508, guest PC 0x0c0947ec */
if(!s->budget--) { s->failed_pc=0x0c0947ecu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0947ee;
P_0c0947ee: /* original c723, guest PC 0x0c0947ee */
if(!s->budget--) { s->failed_pc=0x0c0947eeu; return 0; }
r[0]=code_base|0x0009487cu;
goto P_0c0947f0;
P_0c0947f0: /* original f5f5, guest PC 0x0c0947f0 */
if(!s->budget--) { s->failed_pc=0x0c0947f0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[15]))!=0);
goto P_0c0947f2;
P_0c0947f2: /* original 8d04, guest PC 0x0c0947f2 */
if(!s->budget--) { s->failed_pc=0x0c0947f2u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c0947fe; }
goto P_0c0947f6;
P_0c0947f4: /* original f408, guest PC 0x0c0947f4 */
if(!s->budget--) { s->failed_pc=0x0c0947f4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0947f6;
P_0c0947f6: /* original c722, guest PC 0x0c0947f6 */
if(!s->budget--) { s->failed_pc=0x0c0947f6u; return 0; }
r[0]=code_base|0x00094880u;
goto P_0c0947f8;
P_0c0947f8: /* original f308, guest PC 0x0c0947f8 */
if(!s->budget--) { s->failed_pc=0x0c0947f8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0947fa;
P_0c0947fa: /* original ff35, guest PC 0x0c0947fa */
if(!s->budget--) { s->failed_pc=0x0c0947fau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0947fc;
P_0c0947fc: /* original 8b00, guest PC 0x0c0947fc */
if(!s->budget--) { s->failed_pc=0x0c0947fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094800; }
goto P_0c0947fe;
P_0c0947fe: /* original ff42, guest PC 0x0c0947fe */
if(!s->budget--) { s->failed_pc=0x0c0947feu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'*');
goto P_0c094800;
P_0c094800: /* original f5e5, guest PC 0x0c094800 */
if(!s->budget--) { s->failed_pc=0x0c094800u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[14]))!=0);
goto P_0c094802;
P_0c094802: /* original 8903, guest PC 0x0c094802 */
if(!s->budget--) { s->failed_pc=0x0c094802u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09480c; }
goto P_0c094804;
P_0c094804: /* original c71e, guest PC 0x0c094804 */
if(!s->budget--) { s->failed_pc=0x0c094804u; return 0; }
r[0]=code_base|0x00094880u;
goto P_0c094806;
P_0c094806: /* original f308, guest PC 0x0c094806 */
if(!s->budget--) { s->failed_pc=0x0c094806u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c094808;
P_0c094808: /* original fe35, guest PC 0x0c094808 */
if(!s->budget--) { s->failed_pc=0x0c094808u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[3]))!=0);
goto P_0c09480a;
P_0c09480a: /* original 8b00, guest PC 0x0c09480a */
if(!s->budget--) { s->failed_pc=0x0c09480au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09480e; }
goto P_0c09480c;
P_0c09480c: /* original fe42, guest PC 0x0c09480c */
if(!s->budget--) { s->failed_pc=0x0c09480cu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c09480e;
P_0c09480e: /* original e004, guest PC 0x0c09480e */
if(!s->budget--) { s->failed_pc=0x0c09480eu; return 0; }
r[0]=0x00000004u;
goto P_0c094810;
P_0c094810: /* original fefa, guest PC 0x0c094810 */
if(!s->budget--) { s->failed_pc=0x0c094810u; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c094812;
P_0c094812: /* original fec7, guest PC 0x0c094812 */
if(!s->budget--) { s->failed_pc=0x0c094812u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c094814;
P_0c094814: /* original e008, guest PC 0x0c094814 */
if(!s->budget--) { s->failed_pc=0x0c094814u; return 0; }
r[0]=0x00000008u;
goto P_0c094816;
P_0c094816: /* original fee7, guest PC 0x0c094816 */
if(!s->budget--) { s->failed_pc=0x0c094816u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c094818;
P_0c094818: /* original e00c, guest PC 0x0c094818 */
if(!s->budget--) { s->failed_pc=0x0c094818u; return 0; }
r[0]=0x0000000cu;
goto P_0c09481a;
P_0c09481a: /* original fed7, guest PC 0x0c09481a */
if(!s->budget--) { s->failed_pc=0x0c09481au; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c09481c;
P_0c09481c: /* original 60b3, guest PC 0x0c09481c */
if(!s->budget--) { s->failed_pc=0x0c09481cu; return 0; }
r[0]=r[11];
goto P_0c09481e;
P_0c09481e: /* original 81e8, guest PC 0x0c09481e */
if(!s->budget--) { s->failed_pc=0x0c09481eu; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c094820;
P_0c094820: /* original 6083, guest PC 0x0c094820 */
if(!s->budget--) { s->failed_pc=0x0c094820u; return 0; }
r[0]=r[8];
goto P_0c094822;
P_0c094822: /* original 81e9, guest PC 0x0c094822 */
if(!s->budget--) { s->failed_pc=0x0c094822u; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c094824;
P_0c094824: /* original 60d3, guest PC 0x0c094824 */
if(!s->budget--) { s->failed_pc=0x0c094824u; return 0; }
r[0]=r[13];
goto P_0c094826;
P_0c094826: /* original 81ea, guest PC 0x0c094826 */
if(!s->budget--) { s->failed_pc=0x0c094826u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c094828;
P_0c094828: /* original e016, guest PC 0x0c094828 */
if(!s->budget--) { s->failed_pc=0x0c094828u; return 0; }
r[0]=0x00000016u;
goto P_0c09482a;
P_0c09482a: /* original 0ea4, guest PC 0x0c09482a */
if(!s->budget--) { s->failed_pc=0x0c09482au; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c09482c;
P_0c09482c: /* original e017, guest PC 0x0c09482c */
if(!s->budget--) { s->failed_pc=0x0c09482cu; return 0; }
r[0]=0x00000017u;
goto P_0c09482e;
P_0c09482e: /* original 0ec4, guest PC 0x0c09482e */
if(!s->budget--) { s->failed_pc=0x0c09482eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c094830;
P_0c094830: /* original 7e18, guest PC 0x0c094830 */
if(!s->budget--) { s->failed_pc=0x0c094830u; return 0; }
r[14]+=0x00000018u;
goto P_0c094832;
P_0c094832: /* original 53f2, guest PC 0x0c094832 */
if(!s->budget--) { s->failed_pc=0x0c094832u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c094834;
P_0c094834: /* original 7301, guest PC 0x0c094834 */
if(!s->budget--) { s->failed_pc=0x0c094834u; return 0; }
r[3]+=0x00000001u;
goto P_0c094836;
P_0c094836: /* original e432, guest PC 0x0c094836 */
if(!s->budget--) { s->failed_pc=0x0c094836u; return 0; }
r[4]=0x00000032u;
goto P_0c094838;
P_0c094838: /* original 3343, guest PC 0x0c094838 */
if(!s->budget--) { s->failed_pc=0x0c094838u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c09483a;
P_0c09483a: /* original 8d02, guest PC 0x0c09483a */
if(!s->budget--) { s->failed_pc=0x0c09483au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(cond) { goto P_0c094842; }
goto P_0c09483e;
P_0c09483c: /* original 1f32, guest PC 0x0c09483c */
if(!s->budget--) { s->failed_pc=0x0c09483cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c09483e;
P_0c09483e: /* original af23, guest PC 0x0c09483e */
if(!s->budget--) { s->failed_pc=0x0c09483eu; return 0; }
goto P_0c094688;
P_0c094840: /* original 0009, guest PC 0x0c094840 */
if(!s->budget--) { s->failed_pc=0x0c094840u; return 0; }
goto P_0c094842;
P_0c094842: /* original 7f28, guest PC 0x0c094842 */
if(!s->budget--) { s->failed_pc=0x0c094842u; return 0; }
r[15]+=0x00000028u;
goto P_0c094844;
P_0c094844: /* original 4f26, guest PC 0x0c094844 */
if(!s->budget--) { s->failed_pc=0x0c094844u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094846;
P_0c094846: /* original fcf9, guest PC 0x0c094846 */
if(!s->budget--) { s->failed_pc=0x0c094846u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c094848;
P_0c094848: /* original fdf9, guest PC 0x0c094848 */
if(!s->budget--) { s->failed_pc=0x0c094848u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09484a;
P_0c09484a: /* original fef9, guest PC 0x0c09484a */
if(!s->budget--) { s->failed_pc=0x0c09484au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09484c;
P_0c09484c: /* original fff9, guest PC 0x0c09484c */
if(!s->budget--) { s->failed_pc=0x0c09484cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09484e;
P_0c09484e: /* original 68f6, guest PC 0x0c09484e */
if(!s->budget--) { s->failed_pc=0x0c09484eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c094850;
P_0c094850: /* original 69f6, guest PC 0x0c094850 */
if(!s->budget--) { s->failed_pc=0x0c094850u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c094852;
P_0c094852: /* original 6af6, guest PC 0x0c094852 */
if(!s->budget--) { s->failed_pc=0x0c094852u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c094854;
P_0c094854: /* original 6bf6, guest PC 0x0c094854 */
if(!s->budget--) { s->failed_pc=0x0c094854u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c094856;
P_0c094856: /* original 6cf6, guest PC 0x0c094856 */
if(!s->budget--) { s->failed_pc=0x0c094856u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094858;
P_0c094858: /* original 6df6, guest PC 0x0c094858 */
if(!s->budget--) { s->failed_pc=0x0c094858u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09485a;
P_0c09485a: /* original 000b, guest PC 0x0c09485a */
if(!s->budget--) { s->failed_pc=0x0c09485au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09485c: /* original 6ef6, guest PC 0x0c09485c */
if(!s->budget--) { s->failed_pc=0x0c09485cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09485eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09485eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
