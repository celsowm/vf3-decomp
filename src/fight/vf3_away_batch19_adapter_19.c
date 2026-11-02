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
int vf3_away_batch19_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b5b0u: goto P_0c07b5b0;
case 0x0c07b5b2u: goto P_0c07b5b2;
case 0x0c07b5b4u: goto P_0c07b5b4;
case 0x0c07b5b6u: goto P_0c07b5b6;
case 0x0c07b5b8u: goto P_0c07b5b8;
case 0x0c07b5bau: goto P_0c07b5ba;
case 0x0c07b5bcu: goto P_0c07b5bc;
case 0x0c07b5beu: goto P_0c07b5be;
case 0x0c07b5c0u: goto P_0c07b5c0;
case 0x0c07b5c2u: goto P_0c07b5c2;
case 0x0c07b5c4u: goto P_0c07b5c4;
case 0x0c07b5c6u: goto P_0c07b5c6;
case 0x0c07b5c8u: goto P_0c07b5c8;
case 0x0c07b5cau: goto P_0c07b5ca;
case 0x0c07b5ccu: goto P_0c07b5cc;
case 0x0c07b5f0u: goto P_0c07b5f0;
case 0x0c07b5f2u: goto P_0c07b5f2;
case 0x0c07b5f4u: goto P_0c07b5f4;
case 0x0c07b5f6u: goto P_0c07b5f6;
case 0x0c07b5f8u: goto P_0c07b5f8;
case 0x0c07b5fau: goto P_0c07b5fa;
case 0x0c07b5fcu: goto P_0c07b5fc;
case 0x0c07b5feu: goto P_0c07b5fe;
case 0x0c07b600u: goto P_0c07b600;
case 0x0c07b602u: goto P_0c07b602;
case 0x0c07b604u: goto P_0c07b604;
case 0x0c07b606u: goto P_0c07b606;
case 0x0c07b608u: goto P_0c07b608;
case 0x0c07b60au: goto P_0c07b60a;
case 0x0c07b60cu: goto P_0c07b60c;
case 0x0c07b60eu: goto P_0c07b60e;
case 0x0c07b610u: goto P_0c07b610;
case 0x0c07b612u: goto P_0c07b612;
case 0x0c07b614u: goto P_0c07b614;
case 0x0c07b616u: goto P_0c07b616;
case 0x0c07b618u: goto P_0c07b618;
case 0x0c07b61au: goto P_0c07b61a;
case 0x0c07b61cu: goto P_0c07b61c;
case 0x0c07b61eu: goto P_0c07b61e;
case 0x0c07b620u: goto P_0c07b620;
case 0x0c07b622u: goto P_0c07b622;
case 0x0c07b624u: goto P_0c07b624;
case 0x0c07b626u: goto P_0c07b626;
case 0x0c07b628u: goto P_0c07b628;
case 0x0c07b62au: goto P_0c07b62a;
case 0x0c07b62cu: goto P_0c07b62c;
case 0x0c07b62eu: goto P_0c07b62e;
case 0x0c07b630u: goto P_0c07b630;
case 0x0c07b632u: goto P_0c07b632;
case 0x0c07b634u: goto P_0c07b634;
case 0x0c07b636u: goto P_0c07b636;
case 0x0c07b638u: goto P_0c07b638;
case 0x0c07b63au: goto P_0c07b63a;
case 0x0c07b63cu: goto P_0c07b63c;
case 0x0c07b63eu: goto P_0c07b63e;
case 0x0c07b640u: goto P_0c07b640;
case 0x0c07b642u: goto P_0c07b642;
case 0x0c07b644u: goto P_0c07b644;
case 0x0c07b646u: goto P_0c07b646;
case 0x0c07b648u: goto P_0c07b648;
case 0x0c07b64au: goto P_0c07b64a;
case 0x0c07b64cu: goto P_0c07b64c;
case 0x0c07b64eu: goto P_0c07b64e;
case 0x0c07b650u: goto P_0c07b650;
case 0x0c07b652u: goto P_0c07b652;
case 0x0c07b654u: goto P_0c07b654;
case 0x0c07b656u: goto P_0c07b656;
case 0x0c07b658u: goto P_0c07b658;
case 0x0c07b65au: goto P_0c07b65a;
case 0x0c07b65cu: goto P_0c07b65c;
case 0x0c07b65eu: goto P_0c07b65e;
case 0x0c07b660u: goto P_0c07b660;
case 0x0c07b662u: goto P_0c07b662;
case 0x0c07b664u: goto P_0c07b664;
case 0x0c07b666u: goto P_0c07b666;
case 0x0c07b668u: goto P_0c07b668;
case 0x0c07b66au: goto P_0c07b66a;
case 0x0c07b66cu: goto P_0c07b66c;
case 0x0c08e5c4u: goto P_0c08e5c4;
case 0x0c08e5c6u: goto P_0c08e5c6;
case 0x0c08e5c8u: goto P_0c08e5c8;
case 0x0c08e5cau: goto P_0c08e5ca;
case 0x0c08e5ccu: goto P_0c08e5cc;
case 0x0c08e5ceu: goto P_0c08e5ce;
case 0x0c08e5d0u: goto P_0c08e5d0;
case 0x0c08e5d2u: goto P_0c08e5d2;
case 0x0c08e5d4u: goto P_0c08e5d4;
case 0x0c08e5d6u: goto P_0c08e5d6;
case 0x0c08e5d8u: goto P_0c08e5d8;
case 0x0c08e5dau: goto P_0c08e5da;
case 0x0c08e5dcu: goto P_0c08e5dc;
case 0x0c08e5deu: goto P_0c08e5de;
case 0x0c08e5e0u: goto P_0c08e5e0;
case 0x0c08e5e2u: goto P_0c08e5e2;
case 0x0c08e5e4u: goto P_0c08e5e4;
case 0x0c08e5e6u: goto P_0c08e5e6;
case 0x0c08e5e8u: goto P_0c08e5e8;
case 0x0c08e5eau: goto P_0c08e5ea;
case 0x0c08e5ecu: goto P_0c08e5ec;
case 0x0c08e5eeu: goto P_0c08e5ee;
case 0x0c08e5f0u: goto P_0c08e5f0;
case 0x0c08e5f2u: goto P_0c08e5f2;
case 0x0c08e5f4u: goto P_0c08e5f4;
case 0x0c08e5f6u: goto P_0c08e5f6;
case 0x0c08e5f8u: goto P_0c08e5f8;
case 0x0c08e5fau: goto P_0c08e5fa;
case 0x0c08e5fcu: goto P_0c08e5fc;
case 0x0c08e5feu: goto P_0c08e5fe;
case 0x0c08e600u: goto P_0c08e600;
case 0x0c08e602u: goto P_0c08e602;
case 0x0c08e604u: goto P_0c08e604;
case 0x0c08e606u: goto P_0c08e606;
case 0x0c08e608u: goto P_0c08e608;
case 0x0c08e60au: goto P_0c08e60a;
case 0x0c08e60cu: goto P_0c08e60c;
case 0x0c08e60eu: goto P_0c08e60e;
case 0x0c08e610u: goto P_0c08e610;
case 0x0c08e612u: goto P_0c08e612;
case 0x0c08e614u: goto P_0c08e614;
case 0x0c08e616u: goto P_0c08e616;
case 0x0c08e618u: goto P_0c08e618;
case 0x0c08e61au: goto P_0c08e61a;
case 0x0c08e61cu: goto P_0c08e61c;
case 0x0c08e61eu: goto P_0c08e61e;
case 0x0c08e620u: goto P_0c08e620;
case 0x0c08e622u: goto P_0c08e622;
case 0x0c08e624u: goto P_0c08e624;
case 0x0c08e626u: goto P_0c08e626;
case 0x0c08e628u: goto P_0c08e628;
case 0x0c08e62au: goto P_0c08e62a;
case 0x0c08e62cu: goto P_0c08e62c;
case 0x0c08e62eu: goto P_0c08e62e;
case 0x0c08e630u: goto P_0c08e630;
case 0x0c08e632u: goto P_0c08e632;
case 0x0c08e634u: goto P_0c08e634;
case 0x0c08e636u: goto P_0c08e636;
case 0x0c08e638u: goto P_0c08e638;
case 0x0c08e63au: goto P_0c08e63a;
case 0x0c08e63cu: goto P_0c08e63c;
case 0x0c08e63eu: goto P_0c08e63e;
case 0x0c08e640u: goto P_0c08e640;
case 0x0c08e642u: goto P_0c08e642;
case 0x0c08e644u: goto P_0c08e644;
case 0x0c08e646u: goto P_0c08e646;
case 0x0c08e648u: goto P_0c08e648;
case 0x0c08e64au: goto P_0c08e64a;
case 0x0c08e64cu: goto P_0c08e64c;
case 0x0c08e64eu: goto P_0c08e64e;
case 0x0c08e650u: goto P_0c08e650;
case 0x0c08e652u: goto P_0c08e652;
case 0x0c08e654u: goto P_0c08e654;
case 0x0c08e656u: goto P_0c08e656;
case 0x0c08e658u: goto P_0c08e658;
case 0x0c08e65au: goto P_0c08e65a;
case 0x0c08e65cu: goto P_0c08e65c;
case 0x0c08e65eu: goto P_0c08e65e;
case 0x0c08e660u: goto P_0c08e660;
case 0x0c08e662u: goto P_0c08e662;
case 0x0c08e664u: goto P_0c08e664;
case 0x0c08e666u: goto P_0c08e666;
case 0x0c08e668u: goto P_0c08e668;
case 0x0c08e66au: goto P_0c08e66a;
case 0x0c08e66cu: goto P_0c08e66c;
case 0x0c08e66eu: goto P_0c08e66e;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c096718u: goto P_0c096718;
case 0x0c09671au: goto P_0c09671a;
case 0x0c09671cu: goto P_0c09671c;
case 0x0c09671eu: goto P_0c09671e;
case 0x0c096720u: goto P_0c096720;
case 0x0c096722u: goto P_0c096722;
case 0x0c096724u: goto P_0c096724;
case 0x0c096726u: goto P_0c096726;
case 0x0c096728u: goto P_0c096728;
case 0x0c09672au: goto P_0c09672a;
case 0x0c09672cu: goto P_0c09672c;
case 0x0c09672eu: goto P_0c09672e;
case 0x0c096730u: goto P_0c096730;
case 0x0c096732u: goto P_0c096732;
case 0x0c096734u: goto P_0c096734;
case 0x0c096736u: goto P_0c096736;
case 0x0c096738u: goto P_0c096738;
case 0x0c09673au: goto P_0c09673a;
case 0x0c09673cu: goto P_0c09673c;
case 0x0c09673eu: goto P_0c09673e;
case 0x0c096740u: goto P_0c096740;
case 0x0c096742u: goto P_0c096742;
case 0x0c096744u: goto P_0c096744;
case 0x0c096746u: goto P_0c096746;
case 0x0c0967e8u: goto P_0c0967e8;
case 0x0c0967eau: goto P_0c0967ea;
case 0x0c0967ecu: goto P_0c0967ec;
case 0x0c0967eeu: goto P_0c0967ee;
case 0x0c0967f0u: goto P_0c0967f0;
case 0x0c0967f2u: goto P_0c0967f2;
case 0x0c0967f4u: goto P_0c0967f4;
case 0x0c0967f6u: goto P_0c0967f6;
case 0x0c0967f8u: goto P_0c0967f8;
case 0x0c0967fau: goto P_0c0967fa;
case 0x0c0967fcu: goto P_0c0967fc;
case 0x0c0967feu: goto P_0c0967fe;
case 0x0c096800u: goto P_0c096800;
case 0x0c096802u: goto P_0c096802;
case 0x0c096804u: goto P_0c096804;
case 0x0c096806u: goto P_0c096806;
case 0x0c096808u: goto P_0c096808;
case 0x0c09680au: goto P_0c09680a;
case 0x0c09680cu: goto P_0c09680c;
case 0x0c09680eu: goto P_0c09680e;
case 0x0c096810u: goto P_0c096810;
case 0x0c096812u: goto P_0c096812;
case 0x0c096814u: goto P_0c096814;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b5b0: /* original 920d, guest PC 0x0c07b5b0 */
if(!s->budget--) { s->failed_pc=0x0c07b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b5b2;
P_0c07b5b2: /* original 634d, guest PC 0x0c07b5b2 */
if(!s->budget--) { s->failed_pc=0x0c07b5b2u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5b4;
P_0c07b5b4: /* original 2328, guest PC 0x0c07b5b4 */
if(!s->budget--) { s->failed_pc=0x0c07b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c07b5b6;
P_0c07b5b6: /* original 8908, guest PC 0x0c07b5b6 */
if(!s->budget--) { s->failed_pc=0x0c07b5b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b5ca; }
goto P_0c07b5b8;
P_0c07b5b8: /* original 900a, guest PC 0x0c07b5b8 */
if(!s->budget--) { s->failed_pc=0x0c07b5b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b5ba;
P_0c07b5ba: /* original 2409, guest PC 0x0c07b5ba */
if(!s->budget--) { s->failed_pc=0x0c07b5bau; return 0; }
r[4]&=r[0];
goto P_0c07b5bc;
P_0c07b5bc: /* original d005, guest PC 0x0c07b5bc */
if(!s->budget--) { s->failed_pc=0x0c07b5bcu; return 0; }
r[0]=read(ram,0x0c07b5d4u,4);
goto P_0c07b5be;
P_0c07b5be: /* original 634d, guest PC 0x0c07b5be */
if(!s->budget--) { s->failed_pc=0x0c07b5beu; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5c0;
P_0c07b5c0: /* original 6133, guest PC 0x0c07b5c0 */
if(!s->budget--) { s->failed_pc=0x0c07b5c0u; return 0; }
r[1]=r[3];
goto P_0c07b5c2;
P_0c07b5c2: /* original 4108, guest PC 0x0c07b5c2 */
if(!s->budget--) { s->failed_pc=0x0c07b5c2u; return 0; }
r[1]<<=2;
goto P_0c07b5c4;
P_0c07b5c4: /* original 4300, guest PC 0x0c07b5c4 */
if(!s->budget--) { s->failed_pc=0x0c07b5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07b5c6;
P_0c07b5c6: /* original 331c, guest PC 0x0c07b5c6 */
if(!s->budget--) { s->failed_pc=0x0c07b5c6u; return 0; }
r[3]+=r[1];
goto P_0c07b5c8;
P_0c07b5c8: /* original 043d, guest PC 0x0c07b5c8 */
if(!s->budget--) { s->failed_pc=0x0c07b5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07b5ca;
P_0c07b5ca: /* original 000b, guest PC 0x0c07b5ca */
if(!s->budget--) { s->failed_pc=0x0c07b5cau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c07b5cc: /* original 6043, guest PC 0x0c07b5cc */
if(!s->budget--) { s->failed_pc=0x0c07b5ccu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c07b5ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5ceu; return 0; } return 1;
P_0c07b5f0: /* original 2fe6, guest PC 0x0c07b5f0 */
if(!s->budget--) { s->failed_pc=0x0c07b5f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f2;
P_0c07b5f2: /* original 2fd6, guest PC 0x0c07b5f2 */
if(!s->budget--) { s->failed_pc=0x0c07b5f2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f4;
P_0c07b5f4: /* original 6d43, guest PC 0x0c07b5f4 */
if(!s->budget--) { s->failed_pc=0x0c07b5f4u; return 0; }
r[13]=r[4];
goto P_0c07b5f6;
P_0c07b5f6: /* original 2fc6, guest PC 0x0c07b5f6 */
if(!s->budget--) { s->failed_pc=0x0c07b5f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f8;
P_0c07b5f8: /* original 4f22, guest PC 0x0c07b5f8 */
if(!s->budget--) { s->failed_pc=0x0c07b5f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b5fa;
P_0c07b5fa: /* original d22a, guest PC 0x0c07b5fa */
if(!s->budget--) { s->failed_pc=0x0c07b5fau; return 0; }
r[2]=read(ram,0x0c07b6a4u,4);
goto P_0c07b5fc;
P_0c07b5fc: /* original d32a, guest PC 0x0c07b5fc */
if(!s->budget--) { s->failed_pc=0x0c07b5fcu; return 0; }
r[3]=read(ram,0x0c07b6a8u,4);
goto P_0c07b5fe;
P_0c07b5fe: /* original 7fe0, guest PC 0x0c07b5fe */
if(!s->budget--) { s->failed_pc=0x0c07b5feu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07b600;
P_0c07b600: /* original 61f3, guest PC 0x0c07b600 */
if(!s->budget--) { s->failed_pc=0x0c07b600u; return 0; }
r[1]=r[15];
goto P_0c07b602;
P_0c07b602: /* original 430b, guest PC 0x0c07b602 */
if(!s->budget--) { s->failed_pc=0x0c07b602u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b606u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b606u) { target=s->pc; goto dispatch; }
goto P_0c07b606;
P_0c07b604: /* original e020, guest PC 0x0c07b604 */
if(!s->budget--) { s->failed_pc=0x0c07b604u; return 0; }
r[0]=0x00000020u;
goto P_0c07b606;
P_0c07b606: /* original 9149, guest PC 0x0c07b606 */
if(!s->budget--) { s->failed_pc=0x0c07b606u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69cu,2);
goto P_0c07b608;
P_0c07b608: /* original 6edd, guest PC 0x0c07b608 */
if(!s->budget--) { s->failed_pc=0x0c07b608u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b60a;
P_0c07b60a: /* original 21e8, guest PC 0x0c07b60a */
if(!s->budget--) { s->failed_pc=0x0c07b60au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c07b60c;
P_0c07b60c: /* original 8b29, guest PC 0x0c07b60c */
if(!s->budget--) { s->failed_pc=0x0c07b60cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b60e;
P_0c07b60e: /* original d227, guest PC 0x0c07b60e */
if(!s->budget--) { s->failed_pc=0x0c07b60eu; return 0; }
r[2]=read(ram,0x0c07b6acu,4);
goto P_0c07b610;
P_0c07b610: /* original 22e8, guest PC 0x0c07b610 */
if(!s->budget--) { s->failed_pc=0x0c07b610u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c07b612;
P_0c07b612: /* original 8b26, guest PC 0x0c07b612 */
if(!s->budget--) { s->failed_pc=0x0c07b612u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b614;
P_0c07b614: /* original 60e3, guest PC 0x0c07b614 */
if(!s->budget--) { s->failed_pc=0x0c07b614u; return 0; }
r[0]=r[14];
goto P_0c07b616;
P_0c07b616: /* original dc26, guest PC 0x0c07b616 */
if(!s->budget--) { s->failed_pc=0x0c07b616u; return 0; }
r[12]=read(ram,0x0c07b6b0u,4);
goto P_0c07b618;
P_0c07b618: /* original 8807, guest PC 0x0c07b618 */
if(!s->budget--) { s->failed_pc=0x0c07b618u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c07b61a;
P_0c07b61a: /* original 8b02, guest PC 0x0c07b61a */
if(!s->budget--) { s->failed_pc=0x0c07b61au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b622; }
goto P_0c07b61c;
P_0c07b61c: /* original 953f, guest PC 0x0c07b61c */
if(!s->budget--) { s->failed_pc=0x0c07b61cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b61e;
P_0c07b61e: /* original 4c0b, guest PC 0x0c07b61e */
if(!s->budget--) { s->failed_pc=0x0c07b61eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07b622u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b622u) { target=s->pc; goto dispatch; }
goto P_0c07b622;
P_0c07b620: /* original e401, guest PC 0x0c07b620 */
if(!s->budget--) { s->failed_pc=0x0c07b620u; return 0; }
r[4]=0x00000001u;
goto P_0c07b622;
P_0c07b622: /* original 60e3, guest PC 0x0c07b622 */
if(!s->budget--) { s->failed_pc=0x0c07b622u; return 0; }
r[0]=r[14];
goto P_0c07b624;
P_0c07b624: /* original 8805, guest PC 0x0c07b624 */
if(!s->budget--) { s->failed_pc=0x0c07b624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07b626;
P_0c07b626: /* original 8b02, guest PC 0x0c07b626 */
if(!s->budget--) { s->failed_pc=0x0c07b626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b62e; }
goto P_0c07b628;
P_0c07b628: /* original 953a, guest PC 0x0c07b628 */
if(!s->budget--) { s->failed_pc=0x0c07b628u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b6a0u,2);
goto P_0c07b62a;
P_0c07b62a: /* original 4c0b, guest PC 0x0c07b62a */
if(!s->budget--) { s->failed_pc=0x0c07b62au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b62eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b62eu) { target=s->pc; goto dispatch; }
goto P_0c07b62e;
P_0c07b62c: /* original e401, guest PC 0x0c07b62c */
if(!s->budget--) { s->failed_pc=0x0c07b62cu; return 0; }
r[4]=0x00000001u;
goto P_0c07b62e;
P_0c07b62e: /* original d021, guest PC 0x0c07b62e */
if(!s->budget--) { s->failed_pc=0x0c07b62eu; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b630;
P_0c07b630: /* original 64dd, guest PC 0x0c07b630 */
if(!s->budget--) { s->failed_pc=0x0c07b630u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b632;
P_0c07b632: /* original 4400, guest PC 0x0c07b632 */
if(!s->budget--) { s->failed_pc=0x0c07b632u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b634;
P_0c07b634: /* original 044d, guest PC 0x0c07b634 */
if(!s->budget--) { s->failed_pc=0x0c07b634u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07b636;
P_0c07b636: /* original 644d, guest PC 0x0c07b636 */
if(!s->budget--) { s->failed_pc=0x0c07b636u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b638;
P_0c07b638: /* original 2448, guest PC 0x0c07b638 */
if(!s->budget--) { s->failed_pc=0x0c07b638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b63a;
P_0c07b63a: /* original 8912, guest PC 0x0c07b63a */
if(!s->budget--) { s->failed_pc=0x0c07b63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b63c;
P_0c07b63c: /* original d21e, guest PC 0x0c07b63c */
if(!s->budget--) { s->failed_pc=0x0c07b63cu; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b63e;
P_0c07b63e: /* original 3420, guest PC 0x0c07b63e */
if(!s->budget--) { s->failed_pc=0x0c07b63eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07b640;
P_0c07b640: /* original 890f, guest PC 0x0c07b640 */
if(!s->budget--) { s->failed_pc=0x0c07b640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b642;
P_0c07b642: /* original d21e, guest PC 0x0c07b642 */
if(!s->budget--) { s->failed_pc=0x0c07b642u; return 0; }
r[2]=read(ram,0x0c07b6bcu,4);
goto P_0c07b644;
P_0c07b644: /* original 420b, guest PC 0x0c07b644 */
if(!s->budget--) { s->failed_pc=0x0c07b644u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b648u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b648u) { target=s->pc; goto dispatch; }
goto P_0c07b648;
P_0c07b646: /* original 0009, guest PC 0x0c07b646 */
if(!s->budget--) { s->failed_pc=0x0c07b646u; return 0; }
goto P_0c07b648;
P_0c07b648: /* original d31d, guest PC 0x0c07b648 */
if(!s->budget--) { s->failed_pc=0x0c07b648u; return 0; }
r[3]=read(ram,0x0c07b6c0u,4);
goto P_0c07b64a;
P_0c07b64a: /* original 430b, guest PC 0x0c07b64a */
if(!s->budget--) { s->failed_pc=0x0c07b64au; return 0; }
target=r[3];
r[16]=code_base|0x0c07b64eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b64eu) { target=s->pc; goto dispatch; }
goto P_0c07b64e;
P_0c07b64c: /* original 64f3, guest PC 0x0c07b64c */
if(!s->budget--) { s->failed_pc=0x0c07b64cu; return 0; }
r[4]=r[15];
goto P_0c07b64e;
P_0c07b64e: /* original 2008, guest PC 0x0c07b64e */
if(!s->budget--) { s->failed_pc=0x0c07b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b650;
P_0c07b650: /* original 8902, guest PC 0x0c07b650 */
if(!s->budget--) { s->failed_pc=0x0c07b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b658; }
goto P_0c07b652;
P_0c07b652: /* original 9524, guest PC 0x0c07b652 */
if(!s->budget--) { s->failed_pc=0x0c07b652u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b654;
P_0c07b654: /* original 4c0b, guest PC 0x0c07b654 */
if(!s->budget--) { s->failed_pc=0x0c07b654u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b658u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b658u) { target=s->pc; goto dispatch; }
goto P_0c07b658;
P_0c07b656: /* original e401, guest PC 0x0c07b656 */
if(!s->budget--) { s->failed_pc=0x0c07b656u; return 0; }
r[4]=0x00000001u;
goto P_0c07b658;
P_0c07b658: /* original d016, guest PC 0x0c07b658 */
if(!s->budget--) { s->failed_pc=0x0c07b658u; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b65a;
P_0c07b65a: /* original 6ddd, guest PC 0x0c07b65a */
if(!s->budget--) { s->failed_pc=0x0c07b65au; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b65c;
P_0c07b65c: /* original e300, guest PC 0x0c07b65c */
if(!s->budget--) { s->failed_pc=0x0c07b65cu; return 0; }
r[3]=0x00000000u;
goto P_0c07b65e;
P_0c07b65e: /* original 4d00, guest PC 0x0c07b65e */
if(!s->budget--) { s->failed_pc=0x0c07b65eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b660;
P_0c07b660: /* original 0d35, guest PC 0x0c07b660 */
if(!s->budget--) { s->failed_pc=0x0c07b660u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b662;
P_0c07b662: /* original 7f20, guest PC 0x0c07b662 */
if(!s->budget--) { s->failed_pc=0x0c07b662u; return 0; }
r[15]+=0x00000020u;
goto P_0c07b664;
P_0c07b664: /* original 4f26, guest PC 0x0c07b664 */
if(!s->budget--) { s->failed_pc=0x0c07b664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b666;
P_0c07b666: /* original 6cf6, guest PC 0x0c07b666 */
if(!s->budget--) { s->failed_pc=0x0c07b666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b668;
P_0c07b668: /* original 6df6, guest PC 0x0c07b668 */
if(!s->budget--) { s->failed_pc=0x0c07b668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b66a;
P_0c07b66a: /* original 000b, guest PC 0x0c07b66a */
if(!s->budget--) { s->failed_pc=0x0c07b66au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b66c: /* original 6ef6, guest PC 0x0c07b66c */
if(!s->budget--) { s->failed_pc=0x0c07b66cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b66eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b66eu; return 0; } return 1;
P_0c08e5c4: /* original 2fe6, guest PC 0x0c08e5c4 */
if(!s->budget--) { s->failed_pc=0x0c08e5c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5c6;
P_0c08e5c6: /* original e503, guest PC 0x0c08e5c6 */
if(!s->budget--) { s->failed_pc=0x0c08e5c6u; return 0; }
r[5]=0x00000003u;
goto P_0c08e5c8;
P_0c08e5c8: /* original 2fd6, guest PC 0x0c08e5c8 */
if(!s->budget--) { s->failed_pc=0x0c08e5c8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5ca;
P_0c08e5ca: /* original 2fc6, guest PC 0x0c08e5ca */
if(!s->budget--) { s->failed_pc=0x0c08e5cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5cc;
P_0c08e5cc: /* original 2fb6, guest PC 0x0c08e5cc */
if(!s->budget--) { s->failed_pc=0x0c08e5ccu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5ce;
P_0c08e5ce: /* original 4f22, guest PC 0x0c08e5ce */
if(!s->budget--) { s->failed_pc=0x0c08e5ceu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08e5d0;
P_0c08e5d0: /* original dd2b, guest PC 0x0c08e5d0 */
if(!s->budget--) { s->failed_pc=0x0c08e5d0u; return 0; }
r[13]=read(ram,0x0c08e680u,4);
goto P_0c08e5d2;
P_0c08e5d2: /* original de2a, guest PC 0x0c08e5d2 */
if(!s->budget--) { s->failed_pc=0x0c08e5d2u; return 0; }
r[14]=read(ram,0x0c08e67cu,4);
goto P_0c08e5d4;
P_0c08e5d4: /* original 4d0b, guest PC 0x0c08e5d4 */
if(!s->budget--) { s->failed_pc=0x0c08e5d4u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e5d8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5d8u) { target=s->pc; goto dispatch; }
goto P_0c08e5d8;
P_0c08e5d6: /* original 64e3, guest PC 0x0c08e5d6 */
if(!s->budget--) { s->failed_pc=0x0c08e5d6u; return 0; }
r[4]=r[14];
goto P_0c08e5d8;
P_0c08e5d8: /* original 64e3, guest PC 0x0c08e5d8 */
if(!s->budget--) { s->failed_pc=0x0c08e5d8u; return 0; }
r[4]=r[14];
goto P_0c08e5da;
P_0c08e5da: /* original e503, guest PC 0x0c08e5da */
if(!s->budget--) { s->failed_pc=0x0c08e5dau; return 0; }
r[5]=0x00000003u;
goto P_0c08e5dc;
P_0c08e5dc: /* original 4d0b, guest PC 0x0c08e5dc */
if(!s->budget--) { s->failed_pc=0x0c08e5dcu; return 0; }
target=r[13];
r[16]=code_base|0x0c08e5e0u;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5e0u) { target=s->pc; goto dispatch; }
goto P_0c08e5e0;
P_0c08e5de: /* original 7401, guest PC 0x0c08e5de */
if(!s->budget--) { s->failed_pc=0x0c08e5deu; return 0; }
r[4]+=0x00000001u;
goto P_0c08e5e0;
P_0c08e5e0: /* original 64e3, guest PC 0x0c08e5e0 */
if(!s->budget--) { s->failed_pc=0x0c08e5e0u; return 0; }
r[4]=r[14];
goto P_0c08e5e2;
P_0c08e5e2: /* original e501, guest PC 0x0c08e5e2 */
if(!s->budget--) { s->failed_pc=0x0c08e5e2u; return 0; }
r[5]=0x00000001u;
goto P_0c08e5e4;
P_0c08e5e4: /* original 4d0b, guest PC 0x0c08e5e4 */
if(!s->budget--) { s->failed_pc=0x0c08e5e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e5e8u;
r[4]+=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5e8u) { target=s->pc; goto dispatch; }
goto P_0c08e5e8;
P_0c08e5e6: /* original 7402, guest PC 0x0c08e5e6 */
if(!s->budget--) { s->failed_pc=0x0c08e5e6u; return 0; }
r[4]+=0x00000002u;
goto P_0c08e5e8;
P_0c08e5e8: /* original 9b46, guest PC 0x0c08e5e8 */
if(!s->budget--) { s->failed_pc=0x0c08e5e8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e678u,2);
goto P_0c08e5ea;
P_0c08e5ea: /* original 64e3, guest PC 0x0c08e5ea */
if(!s->budget--) { s->failed_pc=0x0c08e5eau; return 0; }
r[4]=r[14];
goto P_0c08e5ec;
P_0c08e5ec: /* original dc25, guest PC 0x0c08e5ec */
if(!s->budget--) { s->failed_pc=0x0c08e5ecu; return 0; }
r[12]=read(ram,0x0c08e684u,4);
goto P_0c08e5ee;
P_0c08e5ee: /* original 65b3, guest PC 0x0c08e5ee */
if(!s->budget--) { s->failed_pc=0x0c08e5eeu; return 0; }
r[5]=r[11];
goto P_0c08e5f0;
P_0c08e5f0: /* original 4c0b, guest PC 0x0c08e5f0 */
if(!s->budget--) { s->failed_pc=0x0c08e5f0u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e5f4u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5f4u) { target=s->pc; goto dispatch; }
goto P_0c08e5f4;
P_0c08e5f2: /* original 7404, guest PC 0x0c08e5f2 */
if(!s->budget--) { s->failed_pc=0x0c08e5f2u; return 0; }
r[4]+=0x00000004u;
goto P_0c08e5f4;
P_0c08e5f4: /* original 64e3, guest PC 0x0c08e5f4 */
if(!s->budget--) { s->failed_pc=0x0c08e5f4u; return 0; }
r[4]=r[14];
goto P_0c08e5f6;
P_0c08e5f6: /* original 65b3, guest PC 0x0c08e5f6 */
if(!s->budget--) { s->failed_pc=0x0c08e5f6u; return 0; }
r[5]=r[11];
goto P_0c08e5f8;
P_0c08e5f8: /* original 4c0b, guest PC 0x0c08e5f8 */
if(!s->budget--) { s->failed_pc=0x0c08e5f8u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e5fcu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5fcu) { target=s->pc; goto dispatch; }
goto P_0c08e5fc;
P_0c08e5fa: /* original 7408, guest PC 0x0c08e5fa */
if(!s->budget--) { s->failed_pc=0x0c08e5fau; return 0; }
r[4]+=0x00000008u;
goto P_0c08e5fc;
P_0c08e5fc: /* original 64e3, guest PC 0x0c08e5fc */
if(!s->budget--) { s->failed_pc=0x0c08e5fcu; return 0; }
r[4]=r[14];
goto P_0c08e5fe;
P_0c08e5fe: /* original 65b3, guest PC 0x0c08e5fe */
if(!s->budget--) { s->failed_pc=0x0c08e5feu; return 0; }
r[5]=r[11];
goto P_0c08e600;
P_0c08e600: /* original 4c0b, guest PC 0x0c08e600 */
if(!s->budget--) { s->failed_pc=0x0c08e600u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e604u;
r[4]+=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e604u) { target=s->pc; goto dispatch; }
goto P_0c08e604;
P_0c08e602: /* original 7406, guest PC 0x0c08e602 */
if(!s->budget--) { s->failed_pc=0x0c08e602u; return 0; }
r[4]+=0x00000006u;
goto P_0c08e604;
P_0c08e604: /* original 64e3, guest PC 0x0c08e604 */
if(!s->budget--) { s->failed_pc=0x0c08e604u; return 0; }
r[4]=r[14];
goto P_0c08e606;
P_0c08e606: /* original e501, guest PC 0x0c08e606 */
if(!s->budget--) { s->failed_pc=0x0c08e606u; return 0; }
r[5]=0x00000001u;
goto P_0c08e608;
P_0c08e608: /* original 4c0b, guest PC 0x0c08e608 */
if(!s->budget--) { s->failed_pc=0x0c08e608u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e60cu;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e60cu) { target=s->pc; goto dispatch; }
goto P_0c08e60c;
P_0c08e60a: /* original 740a, guest PC 0x0c08e60a */
if(!s->budget--) { s->failed_pc=0x0c08e60au; return 0; }
r[4]+=0x0000000au;
goto P_0c08e60c;
P_0c08e60c: /* original 64e3, guest PC 0x0c08e60c */
if(!s->budget--) { s->failed_pc=0x0c08e60cu; return 0; }
r[4]=r[14];
goto P_0c08e60e;
P_0c08e60e: /* original e500, guest PC 0x0c08e60e */
if(!s->budget--) { s->failed_pc=0x0c08e60eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e610;
P_0c08e610: /* original 4d0b, guest PC 0x0c08e610 */
if(!s->budget--) { s->failed_pc=0x0c08e610u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e614u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e614u) { target=s->pc; goto dispatch; }
goto P_0c08e614;
P_0c08e612: /* original 7403, guest PC 0x0c08e612 */
if(!s->budget--) { s->failed_pc=0x0c08e612u; return 0; }
r[4]+=0x00000003u;
goto P_0c08e614;
P_0c08e614: /* original 64e3, guest PC 0x0c08e614 */
if(!s->budget--) { s->failed_pc=0x0c08e614u; return 0; }
r[4]=r[14];
goto P_0c08e616;
P_0c08e616: /* original e500, guest PC 0x0c08e616 */
if(!s->budget--) { s->failed_pc=0x0c08e616u; return 0; }
r[5]=0x00000000u;
goto P_0c08e618;
P_0c08e618: /* original 4d0b, guest PC 0x0c08e618 */
if(!s->budget--) { s->failed_pc=0x0c08e618u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e61cu;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e61cu) { target=s->pc; goto dispatch; }
goto P_0c08e61c;
P_0c08e61a: /* original 740c, guest PC 0x0c08e61a */
if(!s->budget--) { s->failed_pc=0x0c08e61au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08e61c;
P_0c08e61c: /* original 64e3, guest PC 0x0c08e61c */
if(!s->budget--) { s->failed_pc=0x0c08e61cu; return 0; }
r[4]=r[14];
goto P_0c08e61e;
P_0c08e61e: /* original e500, guest PC 0x0c08e61e */
if(!s->budget--) { s->failed_pc=0x0c08e61eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e620;
P_0c08e620: /* original 4d0b, guest PC 0x0c08e620 */
if(!s->budget--) { s->failed_pc=0x0c08e620u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e624u;
r[4]+=0x0000000eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e624u) { target=s->pc; goto dispatch; }
goto P_0c08e624;
P_0c08e622: /* original 740e, guest PC 0x0c08e622 */
if(!s->budget--) { s->failed_pc=0x0c08e622u; return 0; }
r[4]+=0x0000000eu;
goto P_0c08e624;
P_0c08e624: /* original 64e3, guest PC 0x0c08e624 */
if(!s->budget--) { s->failed_pc=0x0c08e624u; return 0; }
r[4]=r[14];
goto P_0c08e626;
P_0c08e626: /* original e500, guest PC 0x0c08e626 */
if(!s->budget--) { s->failed_pc=0x0c08e626u; return 0; }
r[5]=0x00000000u;
goto P_0c08e628;
P_0c08e628: /* original 4d0b, guest PC 0x0c08e628 */
if(!s->budget--) { s->failed_pc=0x0c08e628u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e62cu;
r[4]+=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e62cu) { target=s->pc; goto dispatch; }
goto P_0c08e62c;
P_0c08e62a: /* original 740f, guest PC 0x0c08e62a */
if(!s->budget--) { s->failed_pc=0x0c08e62au; return 0; }
r[4]+=0x0000000fu;
goto P_0c08e62c;
P_0c08e62c: /* original 64e3, guest PC 0x0c08e62c */
if(!s->budget--) { s->failed_pc=0x0c08e62cu; return 0; }
r[4]=r[14];
goto P_0c08e62e;
P_0c08e62e: /* original e501, guest PC 0x0c08e62e */
if(!s->budget--) { s->failed_pc=0x0c08e62eu; return 0; }
r[5]=0x00000001u;
goto P_0c08e630;
P_0c08e630: /* original 4d0b, guest PC 0x0c08e630 */
if(!s->budget--) { s->failed_pc=0x0c08e630u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e634u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e634u) { target=s->pc; goto dispatch; }
goto P_0c08e634;
P_0c08e632: /* original 7410, guest PC 0x0c08e632 */
if(!s->budget--) { s->failed_pc=0x0c08e632u; return 0; }
r[4]+=0x00000010u;
goto P_0c08e634;
P_0c08e634: /* original 64e3, guest PC 0x0c08e634 */
if(!s->budget--) { s->failed_pc=0x0c08e634u; return 0; }
r[4]=r[14];
goto P_0c08e636;
P_0c08e636: /* original e500, guest PC 0x0c08e636 */
if(!s->budget--) { s->failed_pc=0x0c08e636u; return 0; }
r[5]=0x00000000u;
goto P_0c08e638;
P_0c08e638: /* original 4d0b, guest PC 0x0c08e638 */
if(!s->budget--) { s->failed_pc=0x0c08e638u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e63cu;
r[4]+=0x00000011u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e63cu) { target=s->pc; goto dispatch; }
goto P_0c08e63c;
P_0c08e63a: /* original 7411, guest PC 0x0c08e63a */
if(!s->budget--) { s->failed_pc=0x0c08e63au; return 0; }
r[4]+=0x00000011u;
goto P_0c08e63c;
P_0c08e63c: /* original 64e3, guest PC 0x0c08e63c */
if(!s->budget--) { s->failed_pc=0x0c08e63cu; return 0; }
r[4]=r[14];
goto P_0c08e63e;
P_0c08e63e: /* original e501, guest PC 0x0c08e63e */
if(!s->budget--) { s->failed_pc=0x0c08e63eu; return 0; }
r[5]=0x00000001u;
goto P_0c08e640;
P_0c08e640: /* original 4d0b, guest PC 0x0c08e640 */
if(!s->budget--) { s->failed_pc=0x0c08e640u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e644u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e644u) { target=s->pc; goto dispatch; }
goto P_0c08e644;
P_0c08e642: /* original 7412, guest PC 0x0c08e642 */
if(!s->budget--) { s->failed_pc=0x0c08e642u; return 0; }
r[4]+=0x00000012u;
goto P_0c08e644;
P_0c08e644: /* original 64e3, guest PC 0x0c08e644 */
if(!s->budget--) { s->failed_pc=0x0c08e644u; return 0; }
r[4]=r[14];
goto P_0c08e646;
P_0c08e646: /* original e500, guest PC 0x0c08e646 */
if(!s->budget--) { s->failed_pc=0x0c08e646u; return 0; }
r[5]=0x00000000u;
goto P_0c08e648;
P_0c08e648: /* original 4d0b, guest PC 0x0c08e648 */
if(!s->budget--) { s->failed_pc=0x0c08e648u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e64cu;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e64cu) { target=s->pc; goto dispatch; }
goto P_0c08e64c;
P_0c08e64a: /* original 7413, guest PC 0x0c08e64a */
if(!s->budget--) { s->failed_pc=0x0c08e64au; return 0; }
r[4]+=0x00000013u;
goto P_0c08e64c;
P_0c08e64c: /* original 64e3, guest PC 0x0c08e64c */
if(!s->budget--) { s->failed_pc=0x0c08e64cu; return 0; }
r[4]=r[14];
goto P_0c08e64e;
P_0c08e64e: /* original e500, guest PC 0x0c08e64e */
if(!s->budget--) { s->failed_pc=0x0c08e64eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e650;
P_0c08e650: /* original 4d0b, guest PC 0x0c08e650 */
if(!s->budget--) { s->failed_pc=0x0c08e650u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e654u;
r[4]+=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e654u) { target=s->pc; goto dispatch; }
goto P_0c08e654;
P_0c08e652: /* original 7415, guest PC 0x0c08e652 */
if(!s->budget--) { s->failed_pc=0x0c08e652u; return 0; }
r[4]+=0x00000015u;
goto P_0c08e654;
P_0c08e654: /* original 64e3, guest PC 0x0c08e654 */
if(!s->budget--) { s->failed_pc=0x0c08e654u; return 0; }
r[4]=r[14];
goto P_0c08e656;
P_0c08e656: /* original e500, guest PC 0x0c08e656 */
if(!s->budget--) { s->failed_pc=0x0c08e656u; return 0; }
r[5]=0x00000000u;
goto P_0c08e658;
P_0c08e658: /* original 4d0b, guest PC 0x0c08e658 */
if(!s->budget--) { s->failed_pc=0x0c08e658u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e65cu;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e65cu) { target=s->pc; goto dispatch; }
goto P_0c08e65c;
P_0c08e65a: /* original 7414, guest PC 0x0c08e65a */
if(!s->budget--) { s->failed_pc=0x0c08e65au; return 0; }
r[4]+=0x00000014u;
goto P_0c08e65c;
P_0c08e65c: /* original 64e3, guest PC 0x0c08e65c */
if(!s->budget--) { s->failed_pc=0x0c08e65cu; return 0; }
r[4]=r[14];
goto P_0c08e65e;
P_0c08e65e: /* original e500, guest PC 0x0c08e65e */
if(!s->budget--) { s->failed_pc=0x0c08e65eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e660;
P_0c08e660: /* original 4d0b, guest PC 0x0c08e660 */
if(!s->budget--) { s->failed_pc=0x0c08e660u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e664u;
r[4]+=0x00000016u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e664u) { target=s->pc; goto dispatch; }
goto P_0c08e664;
P_0c08e662: /* original 7416, guest PC 0x0c08e662 */
if(!s->budget--) { s->failed_pc=0x0c08e662u; return 0; }
r[4]+=0x00000016u;
goto P_0c08e664;
P_0c08e664: /* original 4f26, guest PC 0x0c08e664 */
if(!s->budget--) { s->failed_pc=0x0c08e664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08e666;
P_0c08e666: /* original 6bf6, guest PC 0x0c08e666 */
if(!s->budget--) { s->failed_pc=0x0c08e666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08e668;
P_0c08e668: /* original 6cf6, guest PC 0x0c08e668 */
if(!s->budget--) { s->failed_pc=0x0c08e668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08e66a;
P_0c08e66a: /* original 6df6, guest PC 0x0c08e66a */
if(!s->budget--) { s->failed_pc=0x0c08e66au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08e66c;
P_0c08e66c: /* original 000b, guest PC 0x0c08e66c */
if(!s->budget--) { s->failed_pc=0x0c08e66cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08e66e: /* original 6ef6, guest PC 0x0c08e66e */
if(!s->budget--) { s->failed_pc=0x0c08e66eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08e670u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08e670u; return 0; } return 1;
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c096718: /* original 4f22, guest PC 0x0c096718 */
if(!s->budget--) { s->failed_pc=0x0c096718u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09671a;
P_0c09671a: /* original d340, guest PC 0x0c09671a */
if(!s->budget--) { s->failed_pc=0x0c09671au; return 0; }
r[3]=read(ram,0x0c09681cu,4);
goto P_0c09671c;
P_0c09671c: /* original 430b, guest PC 0x0c09671c */
if(!s->budget--) { s->failed_pc=0x0c09671cu; return 0; }
target=r[3];
r[16]=code_base|0x0c096720u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096720u) { target=s->pc; goto dispatch; }
goto P_0c096720;
P_0c09671e: /* original 0009, guest PC 0x0c09671e */
if(!s->budget--) { s->failed_pc=0x0c09671eu; return 0; }
goto P_0c096720;
P_0c096720: /* original d23f, guest PC 0x0c096720 */
if(!s->budget--) { s->failed_pc=0x0c096720u; return 0; }
r[2]=read(ram,0x0c096820u,4);
goto P_0c096722;
P_0c096722: /* original 420b, guest PC 0x0c096722 */
if(!s->budget--) { s->failed_pc=0x0c096722u; return 0; }
target=r[2];
r[16]=code_base|0x0c096726u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096726u) { target=s->pc; goto dispatch; }
goto P_0c096726;
P_0c096724: /* original 0009, guest PC 0x0c096724 */
if(!s->budget--) { s->failed_pc=0x0c096724u; return 0; }
goto P_0c096726;
P_0c096726: /* original d33f, guest PC 0x0c096726 */
if(!s->budget--) { s->failed_pc=0x0c096726u; return 0; }
r[3]=read(ram,0x0c096824u,4);
goto P_0c096728;
P_0c096728: /* original 430b, guest PC 0x0c096728 */
if(!s->budget--) { s->failed_pc=0x0c096728u; return 0; }
target=r[3];
r[16]=code_base|0x0c09672cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09672cu) { target=s->pc; goto dispatch; }
goto P_0c09672c;
P_0c09672a: /* original 0009, guest PC 0x0c09672a */
if(!s->budget--) { s->failed_pc=0x0c09672au; return 0; }
goto P_0c09672c;
P_0c09672c: /* original d23e, guest PC 0x0c09672c */
if(!s->budget--) { s->failed_pc=0x0c09672cu; return 0; }
r[2]=read(ram,0x0c096828u,4);
goto P_0c09672e;
P_0c09672e: /* original 420b, guest PC 0x0c09672e */
if(!s->budget--) { s->failed_pc=0x0c09672eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096732u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096732u) { target=s->pc; goto dispatch; }
goto P_0c096732;
P_0c096730: /* original 0009, guest PC 0x0c096730 */
if(!s->budget--) { s->failed_pc=0x0c096730u; return 0; }
goto P_0c096732;
P_0c096732: /* original d33e, guest PC 0x0c096732 */
if(!s->budget--) { s->failed_pc=0x0c096732u; return 0; }
r[3]=read(ram,0x0c09682cu,4);
goto P_0c096734;
P_0c096734: /* original 430b, guest PC 0x0c096734 */
if(!s->budget--) { s->failed_pc=0x0c096734u; return 0; }
target=r[3];
r[16]=code_base|0x0c096738u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096738u) { target=s->pc; goto dispatch; }
goto P_0c096738;
P_0c096736: /* original 0009, guest PC 0x0c096736 */
if(!s->budget--) { s->failed_pc=0x0c096736u; return 0; }
goto P_0c096738;
P_0c096738: /* original d23d, guest PC 0x0c096738 */
if(!s->budget--) { s->failed_pc=0x0c096738u; return 0; }
r[2]=read(ram,0x0c096830u,4);
goto P_0c09673a;
P_0c09673a: /* original 420b, guest PC 0x0c09673a */
if(!s->budget--) { s->failed_pc=0x0c09673au; return 0; }
target=r[2];
r[16]=code_base|0x0c09673eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09673eu) { target=s->pc; goto dispatch; }
goto P_0c09673e;
P_0c09673c: /* original e400, guest PC 0x0c09673c */
if(!s->budget--) { s->failed_pc=0x0c09673cu; return 0; }
r[4]=0x00000000u;
goto P_0c09673e;
P_0c09673e: /* original d33d, guest PC 0x0c09673e */
if(!s->budget--) { s->failed_pc=0x0c09673eu; return 0; }
r[3]=read(ram,0x0c096834u,4);
goto P_0c096740;
P_0c096740: /* original 430b, guest PC 0x0c096740 */
if(!s->budget--) { s->failed_pc=0x0c096740u; return 0; }
target=r[3];
r[16]=code_base|0x0c096744u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096744u) { target=s->pc; goto dispatch; }
goto P_0c096744;
P_0c096742: /* original 0009, guest PC 0x0c096742 */
if(!s->budget--) { s->failed_pc=0x0c096742u; return 0; }
goto P_0c096744;
P_0c096744: /* original a050, guest PC 0x0c096744 */
if(!s->budget--) { s->failed_pc=0x0c096744u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0967e8;
P_0c096746: /* original 4f26, guest PC 0x0c096746 */
if(!s->budget--) { s->failed_pc=0x0c096746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c096748u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096748u; return 0; } return 1;
P_0c0967e8: /* original 2fe6, guest PC 0x0c0967e8 */
if(!s->budget--) { s->failed_pc=0x0c0967e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0967ea;
P_0c0967ea: /* original 2fd6, guest PC 0x0c0967ea */
if(!s->budget--) { s->failed_pc=0x0c0967eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0967ec;
P_0c0967ec: /* original de18, guest PC 0x0c0967ec */
if(!s->budget--) { s->failed_pc=0x0c0967ecu; return 0; }
r[14]=read(ram,0x0c096850u,4);
goto P_0c0967ee;
P_0c0967ee: /* original 4f22, guest PC 0x0c0967ee */
if(!s->budget--) { s->failed_pc=0x0c0967eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0967f0;
P_0c0967f0: /* original dd19, guest PC 0x0c0967f0 */
if(!s->budget--) { s->failed_pc=0x0c0967f0u; return 0; }
r[13]=read(ram,0x0c096858u,4);
goto P_0c0967f2;
P_0c0967f2: /* original 64e3, guest PC 0x0c0967f2 */
if(!s->budget--) { s->failed_pc=0x0c0967f2u; return 0; }
r[4]=r[14];
goto P_0c0967f4;
P_0c0967f4: /* original d517, guest PC 0x0c0967f4 */
if(!s->budget--) { s->failed_pc=0x0c0967f4u; return 0; }
r[5]=read(ram,0x0c096854u,4);
goto P_0c0967f6;
P_0c0967f6: /* original 4d0b, guest PC 0x0c0967f6 */
if(!s->budget--) { s->failed_pc=0x0c0967f6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0967fau;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0967fau) { target=s->pc; goto dispatch; }
goto P_0c0967fa;
P_0c0967f8: /* original 742c, guest PC 0x0c0967f8 */
if(!s->budget--) { s->failed_pc=0x0c0967f8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0967fa;
P_0c0967fa: /* original d518, guest PC 0x0c0967fa */
if(!s->budget--) { s->failed_pc=0x0c0967fau; return 0; }
r[5]=read(ram,0x0c09685cu,4);
goto P_0c0967fc;
P_0c0967fc: /* original 64e3, guest PC 0x0c0967fc */
if(!s->budget--) { s->failed_pc=0x0c0967fcu; return 0; }
r[4]=r[14];
goto P_0c0967fe;
P_0c0967fe: /* original 6552, guest PC 0x0c0967fe */
if(!s->budget--) { s->failed_pc=0x0c0967feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c096800;
P_0c096800: /* original 4d0b, guest PC 0x0c096800 */
if(!s->budget--) { s->failed_pc=0x0c096800u; return 0; }
target=r[13];
r[16]=code_base|0x0c096804u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096804u) { target=s->pc; goto dispatch; }
goto P_0c096804;
P_0c096802: /* original 7434, guest PC 0x0c096802 */
if(!s->budget--) { s->failed_pc=0x0c096802u; return 0; }
r[4]+=0x00000034u;
goto P_0c096804;
P_0c096804: /* original d516, guest PC 0x0c096804 */
if(!s->budget--) { s->failed_pc=0x0c096804u; return 0; }
r[5]=read(ram,0x0c096860u,4);
goto P_0c096806;
P_0c096806: /* original 64e3, guest PC 0x0c096806 */
if(!s->budget--) { s->failed_pc=0x0c096806u; return 0; }
r[4]=r[14];
goto P_0c096808;
P_0c096808: /* original 6552, guest PC 0x0c096808 */
if(!s->budget--) { s->failed_pc=0x0c096808u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09680a;
P_0c09680a: /* original 4d0b, guest PC 0x0c09680a */
if(!s->budget--) { s->failed_pc=0x0c09680au; return 0; }
target=r[13];
r[16]=code_base|0x0c09680eu;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09680eu) { target=s->pc; goto dispatch; }
goto P_0c09680e;
P_0c09680c: /* original 7438, guest PC 0x0c09680c */
if(!s->budget--) { s->failed_pc=0x0c09680cu; return 0; }
r[4]+=0x00000038u;
goto P_0c09680e;
P_0c09680e: /* original 4f26, guest PC 0x0c09680e */
if(!s->budget--) { s->failed_pc=0x0c09680eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096810;
P_0c096810: /* original 6df6, guest PC 0x0c096810 */
if(!s->budget--) { s->failed_pc=0x0c096810u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096812;
P_0c096812: /* original 000b, guest PC 0x0c096812 */
if(!s->budget--) { s->failed_pc=0x0c096812u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096814: /* original 6ef6, guest PC 0x0c096814 */
if(!s->budget--) { s->failed_pc=0x0c096814u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096816u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096816u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
