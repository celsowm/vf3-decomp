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
int vf3_away_batch4_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04c714u: goto P_0c04c714;
case 0x0c04c716u: goto P_0c04c716;
case 0x0c04c718u: goto P_0c04c718;
case 0x0c04c71au: goto P_0c04c71a;
case 0x0c04c71cu: goto P_0c04c71c;
case 0x0c04c71eu: goto P_0c04c71e;
case 0x0c04c720u: goto P_0c04c720;
case 0x0c04c722u: goto P_0c04c722;
case 0x0c04c724u: goto P_0c04c724;
case 0x0c04c726u: goto P_0c04c726;
case 0x0c04c728u: goto P_0c04c728;
case 0x0c04c72au: goto P_0c04c72a;
case 0x0c04c72cu: goto P_0c04c72c;
case 0x0c04c72eu: goto P_0c04c72e;
case 0x0c04c730u: goto P_0c04c730;
case 0x0c04c732u: goto P_0c04c732;
case 0x0c04c734u: goto P_0c04c734;
case 0x0c04c736u: goto P_0c04c736;
case 0x0c04c738u: goto P_0c04c738;
case 0x0c04c73au: goto P_0c04c73a;
case 0x0c04c73cu: goto P_0c04c73c;
case 0x0c04c73eu: goto P_0c04c73e;
case 0x0c04c740u: goto P_0c04c740;
case 0x0c04c742u: goto P_0c04c742;
case 0x0c04c744u: goto P_0c04c744;
case 0x0c04c746u: goto P_0c04c746;
case 0x0c04c748u: goto P_0c04c748;
case 0x0c04c74au: goto P_0c04c74a;
case 0x0c04c74cu: goto P_0c04c74c;
case 0x0c04c74eu: goto P_0c04c74e;
case 0x0c04c750u: goto P_0c04c750;
case 0x0c04c752u: goto P_0c04c752;
case 0x0c04c754u: goto P_0c04c754;
case 0x0c04c756u: goto P_0c04c756;
case 0x0c04c758u: goto P_0c04c758;
case 0x0c04c75au: goto P_0c04c75a;
case 0x0c04c75cu: goto P_0c04c75c;
case 0x0c04c75eu: goto P_0c04c75e;
case 0x0c04c760u: goto P_0c04c760;
case 0x0c04c762u: goto P_0c04c762;
case 0x0c04c764u: goto P_0c04c764;
case 0x0c04c766u: goto P_0c04c766;
case 0x0c04c768u: goto P_0c04c768;
case 0x0c04c76au: goto P_0c04c76a;
case 0x0c04c76cu: goto P_0c04c76c;
case 0x0c04c76eu: goto P_0c04c76e;
case 0x0c04c770u: goto P_0c04c770;
case 0x0c04c772u: goto P_0c04c772;
case 0x0c04c774u: goto P_0c04c774;
case 0x0c04c776u: goto P_0c04c776;
case 0x0c04c778u: goto P_0c04c778;
case 0x0c04c77au: goto P_0c04c77a;
case 0x0c04c77cu: goto P_0c04c77c;
case 0x0c04c77eu: goto P_0c04c77e;
case 0x0c04c780u: goto P_0c04c780;
case 0x0c04c782u: goto P_0c04c782;
case 0x0c04c784u: goto P_0c04c784;
case 0x0c04c786u: goto P_0c04c786;
case 0x0c04c788u: goto P_0c04c788;
case 0x0c04c78au: goto P_0c04c78a;
case 0x0c04c78cu: goto P_0c04c78c;
case 0x0c04c78eu: goto P_0c04c78e;
case 0x0c04c790u: goto P_0c04c790;
case 0x0c04c792u: goto P_0c04c792;
case 0x0c04c794u: goto P_0c04c794;
case 0x0c04c796u: goto P_0c04c796;
case 0x0c04c798u: goto P_0c04c798;
case 0x0c04c79au: goto P_0c04c79a;
case 0x0c04c79cu: goto P_0c04c79c;
case 0x0c04c79eu: goto P_0c04c79e;
case 0x0c04c7a0u: goto P_0c04c7a0;
case 0x0c04c7a2u: goto P_0c04c7a2;
case 0x0c04c7a4u: goto P_0c04c7a4;
case 0x0c04c7a6u: goto P_0c04c7a6;
case 0x0c04c7a8u: goto P_0c04c7a8;
case 0x0c04c7aau: goto P_0c04c7aa;
case 0x0c04c7acu: goto P_0c04c7ac;
case 0x0c04c7aeu: goto P_0c04c7ae;
case 0x0c04c7b0u: goto P_0c04c7b0;
case 0x0c04c7b2u: goto P_0c04c7b2;
case 0x0c04c7dcu: goto P_0c04c7dc;
case 0x0c04c7deu: goto P_0c04c7de;
case 0x0c04c7e0u: goto P_0c04c7e0;
case 0x0c04c7e2u: goto P_0c04c7e2;
case 0x0c04c7e4u: goto P_0c04c7e4;
case 0x0c04c7e6u: goto P_0c04c7e6;
case 0x0c04c7e8u: goto P_0c04c7e8;
case 0x0c04c7eau: goto P_0c04c7ea;
case 0x0c04c7ecu: goto P_0c04c7ec;
case 0x0c04c7eeu: goto P_0c04c7ee;
case 0x0c04c7f0u: goto P_0c04c7f0;
case 0x0c04c7f2u: goto P_0c04c7f2;
case 0x0c04c7f4u: goto P_0c04c7f4;
case 0x0c04c7f6u: goto P_0c04c7f6;
case 0x0c04c7f8u: goto P_0c04c7f8;
case 0x0c04c7fau: goto P_0c04c7fa;
case 0x0c04c7fcu: goto P_0c04c7fc;
case 0x0c04c7feu: goto P_0c04c7fe;
case 0x0c04c800u: goto P_0c04c800;
case 0x0c04c802u: goto P_0c04c802;
case 0x0c04c804u: goto P_0c04c804;
case 0x0c04c806u: goto P_0c04c806;
case 0x0c04c808u: goto P_0c04c808;
case 0x0c04c80au: goto P_0c04c80a;
case 0x0c04c80cu: goto P_0c04c80c;
case 0x0c04c80eu: goto P_0c04c80e;
case 0x0c04c810u: goto P_0c04c810;
case 0x0c04c812u: goto P_0c04c812;
case 0x0c04c814u: goto P_0c04c814;
case 0x0c04c816u: goto P_0c04c816;
case 0x0c04c818u: goto P_0c04c818;
case 0x0c04c81au: goto P_0c04c81a;
case 0x0c04c81cu: goto P_0c04c81c;
case 0x0c04c81eu: goto P_0c04c81e;
case 0x0c04c820u: goto P_0c04c820;
case 0x0c04c822u: goto P_0c04c822;
case 0x0c04c824u: goto P_0c04c824;
case 0x0c04c826u: goto P_0c04c826;
case 0x0c04c828u: goto P_0c04c828;
case 0x0c04c82au: goto P_0c04c82a;
case 0x0c04c82cu: goto P_0c04c82c;
case 0x0c04c82eu: goto P_0c04c82e;
case 0x0c04c830u: goto P_0c04c830;
case 0x0c04c832u: goto P_0c04c832;
case 0x0c04c834u: goto P_0c04c834;
case 0x0c04c836u: goto P_0c04c836;
case 0x0c04c838u: goto P_0c04c838;
case 0x0c04c83au: goto P_0c04c83a;
case 0x0c04c83cu: goto P_0c04c83c;
case 0x0c04c83eu: goto P_0c04c83e;
case 0x0c04c840u: goto P_0c04c840;
case 0x0c04c842u: goto P_0c04c842;
case 0x0c04c844u: goto P_0c04c844;
case 0x0c04c846u: goto P_0c04c846;
case 0x0c04c848u: goto P_0c04c848;
case 0x0c04c84au: goto P_0c04c84a;
case 0x0c04c84cu: goto P_0c04c84c;
case 0x0c04c84eu: goto P_0c04c84e;
case 0x0c04c850u: goto P_0c04c850;
case 0x0c04c852u: goto P_0c04c852;
case 0x0c04c854u: goto P_0c04c854;
case 0x0c04c856u: goto P_0c04c856;
case 0x0c04c858u: goto P_0c04c858;
case 0x0c04c85au: goto P_0c04c85a;
case 0x0c04c85cu: goto P_0c04c85c;
case 0x0c04c85eu: goto P_0c04c85e;
case 0x0c04c860u: goto P_0c04c860;
case 0x0c04c862u: goto P_0c04c862;
case 0x0c04c864u: goto P_0c04c864;
case 0x0c04c866u: goto P_0c04c866;
case 0x0c04c868u: goto P_0c04c868;
case 0x0c04c86au: goto P_0c04c86a;
case 0x0c04c86cu: goto P_0c04c86c;
case 0x0c04c86eu: goto P_0c04c86e;
case 0x0c04c870u: goto P_0c04c870;
case 0x0c04c872u: goto P_0c04c872;
case 0x0c04c874u: goto P_0c04c874;
case 0x0c04c876u: goto P_0c04c876;
case 0x0c04c878u: goto P_0c04c878;
case 0x0c04c87au: goto P_0c04c87a;
case 0x0c04c87cu: goto P_0c04c87c;
case 0x0c04c87eu: goto P_0c04c87e;
case 0x0c04c880u: goto P_0c04c880;
case 0x0c04c882u: goto P_0c04c882;
case 0x0c04c884u: goto P_0c04c884;
case 0x0c04c886u: goto P_0c04c886;
case 0x0c04c888u: goto P_0c04c888;
case 0x0c04c88au: goto P_0c04c88a;
case 0x0c04c88cu: goto P_0c04c88c;
case 0x0c04c88eu: goto P_0c04c88e;
case 0x0c04c890u: goto P_0c04c890;
case 0x0c04c892u: goto P_0c04c892;
case 0x0c04c894u: goto P_0c04c894;
case 0x0c04c896u: goto P_0c04c896;
case 0x0c04c898u: goto P_0c04c898;
case 0x0c04c89au: goto P_0c04c89a;
case 0x0c04c89cu: goto P_0c04c89c;
case 0x0c04c89eu: goto P_0c04c89e;
case 0x0c04c8a0u: goto P_0c04c8a0;
case 0x0c04c8a2u: goto P_0c04c8a2;
case 0x0c04c8a4u: goto P_0c04c8a4;
case 0x0c04c8a6u: goto P_0c04c8a6;
case 0x0c04c8a8u: goto P_0c04c8a8;
case 0x0c04c8aau: goto P_0c04c8aa;
case 0x0c04c8acu: goto P_0c04c8ac;
case 0x0c04c8aeu: goto P_0c04c8ae;
case 0x0c04c8b0u: goto P_0c04c8b0;
case 0x0c04c8b2u: goto P_0c04c8b2;
case 0x0c04c8b4u: goto P_0c04c8b4;
case 0x0c04c8b6u: goto P_0c04c8b6;
case 0x0c04c8b8u: goto P_0c04c8b8;
case 0x0c04c8bau: goto P_0c04c8ba;
case 0x0c04c8bcu: goto P_0c04c8bc;
case 0x0c04c8beu: goto P_0c04c8be;
case 0x0c04c8c0u: goto P_0c04c8c0;
case 0x0c04c8c2u: goto P_0c04c8c2;
case 0x0c04c8c4u: goto P_0c04c8c4;
case 0x0c04c8c6u: goto P_0c04c8c6;
case 0x0c04c8c8u: goto P_0c04c8c8;
case 0x0c04c8cau: goto P_0c04c8ca;
case 0x0c04c8ccu: goto P_0c04c8cc;
case 0x0c04c8ceu: goto P_0c04c8ce;
case 0x0c04c8d0u: goto P_0c04c8d0;
case 0x0c04c8d2u: goto P_0c04c8d2;
case 0x0c04c8d4u: goto P_0c04c8d4;
case 0x0c04c8d6u: goto P_0c04c8d6;
case 0x0c04c8d8u: goto P_0c04c8d8;
case 0x0c04c8dau: goto P_0c04c8da;
case 0x0c04c8dcu: goto P_0c04c8dc;
case 0x0c04c8deu: goto P_0c04c8de;
case 0x0c04c8e0u: goto P_0c04c8e0;
case 0x0c04c8e2u: goto P_0c04c8e2;
case 0x0c04c8e4u: goto P_0c04c8e4;
case 0x0c04c8e6u: goto P_0c04c8e6;
case 0x0c04c8e8u: goto P_0c04c8e8;
case 0x0c04c8eau: goto P_0c04c8ea;
case 0x0c04c8ecu: goto P_0c04c8ec;
case 0x0c04c8eeu: goto P_0c04c8ee;
case 0x0c04c8f0u: goto P_0c04c8f0;
case 0x0c04c8f2u: goto P_0c04c8f2;
case 0x0c04c8f4u: goto P_0c04c8f4;
case 0x0c04c8f6u: goto P_0c04c8f6;
case 0x0c04c8f8u: goto P_0c04c8f8;
case 0x0c04c8fau: goto P_0c04c8fa;
case 0x0c04c8fcu: goto P_0c04c8fc;
case 0x0c04c8feu: goto P_0c04c8fe;
case 0x0c04c900u: goto P_0c04c900;
case 0x0c04c902u: goto P_0c04c902;
case 0x0c04c904u: goto P_0c04c904;
case 0x0c04c906u: goto P_0c04c906;
case 0x0c04c908u: goto P_0c04c908;
case 0x0c04c90au: goto P_0c04c90a;
case 0x0c04c90cu: goto P_0c04c90c;
case 0x0c04c90eu: goto P_0c04c90e;
case 0x0c04c910u: goto P_0c04c910;
case 0x0c04c912u: goto P_0c04c912;
case 0x0c04c914u: goto P_0c04c914;
case 0x0c04c916u: goto P_0c04c916;
case 0x0c04c918u: goto P_0c04c918;
case 0x0c04c91au: goto P_0c04c91a;
case 0x0c04c91cu: goto P_0c04c91c;
case 0x0c04c91eu: goto P_0c04c91e;
case 0x0c04c920u: goto P_0c04c920;
case 0x0c04c922u: goto P_0c04c922;
case 0x0c04c924u: goto P_0c04c924;
case 0x0c04c926u: goto P_0c04c926;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04c714: /* original 6043, guest PC 0x0c04c714 */
if(!s->budget--) { s->failed_pc=0x0c04c714u; return 0; }
r[0]=r[4];
goto P_0c04c716;
P_0c04c716: /* original d32d, guest PC 0x0c04c716 */
if(!s->budget--) { s->failed_pc=0x0c04c716u; return 0; }
r[3]=read(ram,0x0c04c7ccu,4);
goto P_0c04c718;
P_0c04c718: /* original 880f, guest PC 0x0c04c718 */
if(!s->budget--) { s->failed_pc=0x0c04c718u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c04c71a;
P_0c04c71a: /* original 8d08, guest PC 0x0c04c71a */
if(!s->budget--) { s->failed_pc=0x0c04c71au; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(cond) { goto P_0c04c72e; }
goto P_0c04c71e;
P_0c04c71c: /* original 6532, guest PC 0x0c04c71c */
if(!s->budget--) { s->failed_pc=0x0c04c71cu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c04c71e;
P_0c04c71e: /* original 8821, guest PC 0x0c04c71e */
if(!s->budget--) { s->failed_pc=0x0c04c71eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000021u)!=0);
goto P_0c04c720;
P_0c04c720: /* original 8908, guest PC 0x0c04c720 */
if(!s->budget--) { s->failed_pc=0x0c04c720u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c734; }
goto P_0c04c722;
P_0c04c722: /* original 8841, guest PC 0x0c04c722 */
if(!s->budget--) { s->failed_pc=0x0c04c722u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000041u)!=0);
goto P_0c04c724;
P_0c04c724: /* original 8908, guest PC 0x0c04c724 */
if(!s->budget--) { s->failed_pc=0x0c04c724u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c738; }
goto P_0c04c726;
P_0c04c726: /* original 887a, guest PC 0x0c04c726 */
if(!s->budget--) { s->failed_pc=0x0c04c726u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000007au)!=0);
goto P_0c04c728;
P_0c04c728: /* original 8909, guest PC 0x0c04c728 */
if(!s->budget--) { s->failed_pc=0x0c04c728u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c73e; }
goto P_0c04c72a;
P_0c04c72a: /* original a00b, guest PC 0x0c04c72a */
if(!s->budget--) { s->failed_pc=0x0c04c72au; return 0; }
goto P_0c04c744;
P_0c04c72c: /* original 0009, guest PC 0x0c04c72c */
if(!s->budget--) { s->failed_pc=0x0c04c72cu; return 0; }
goto P_0c04c72e;
P_0c04c72e: /* original e200, guest PC 0x0c04c72e */
if(!s->budget--) { s->failed_pc=0x0c04c72eu; return 0; }
r[2]=0x00000000u;
goto P_0c04c730;
P_0c04c730: /* original a00b, guest PC 0x0c04c730 */
if(!s->budget--) { s->failed_pc=0x0c04c730u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c04c74a;
P_0c04c732: /* original 1521, guest PC 0x0c04c732 */
if(!s->budget--) { s->failed_pc=0x0c04c732u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c04c734;
P_0c04c734: /* original a004, guest PC 0x0c04c734 */
if(!s->budget--) { s->failed_pc=0x0c04c734u; return 0; }
r[0]=0x00000001u;
goto P_0c04c740;
P_0c04c736: /* original e001, guest PC 0x0c04c736 */
if(!s->budget--) { s->failed_pc=0x0c04c736u; return 0; }
r[0]=0x00000001u;
goto P_0c04c738;
P_0c04c738: /* original e102, guest PC 0x0c04c738 */
if(!s->budget--) { s->failed_pc=0x0c04c738u; return 0; }
r[1]=0x00000002u;
goto P_0c04c73a;
P_0c04c73a: /* original a006, guest PC 0x0c04c73a */
if(!s->budget--) { s->failed_pc=0x0c04c73au; return 0; }
write(ram,r[5]+4,r[1],4);
goto P_0c04c74a;
P_0c04c73c: /* original 1511, guest PC 0x0c04c73c */
if(!s->budget--) { s->failed_pc=0x0c04c73cu; return 0; }
write(ram,r[5]+4,r[1],4);
goto P_0c04c73e;
P_0c04c73e: /* original e003, guest PC 0x0c04c73e */
if(!s->budget--) { s->failed_pc=0x0c04c73eu; return 0; }
r[0]=0x00000003u;
goto P_0c04c740;
P_0c04c740: /* original a003, guest PC 0x0c04c740 */
if(!s->budget--) { s->failed_pc=0x0c04c740u; return 0; }
write(ram,r[5]+4,r[0],4);
goto P_0c04c74a;
P_0c04c742: /* original 1501, guest PC 0x0c04c742 */
if(!s->budget--) { s->failed_pc=0x0c04c742u; return 0; }
write(ram,r[5]+4,r[0],4);
goto P_0c04c744;
P_0c04c744: /* original 9036, guest PC 0x0c04c744 */
if(!s->budget--) { s->failed_pc=0x0c04c744u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c7b4u,2);
goto P_0c04c746;
P_0c04c746: /* original 000b, guest PC 0x0c04c746 */
if(!s->budget--) { s->failed_pc=0x0c04c746u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04c748: /* original 0009, guest PC 0x0c04c748 */
if(!s->budget--) { s->failed_pc=0x0c04c748u; return 0; }
goto P_0c04c74a;
P_0c04c74a: /* original e000, guest PC 0x0c04c74a */
if(!s->budget--) { s->failed_pc=0x0c04c74au; return 0; }
r[0]=0x00000000u;
goto P_0c04c74c;
P_0c04c74c: /* original 000b, guest PC 0x0c04c74c */
if(!s->budget--) { s->failed_pc=0x0c04c74cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04c74e: /* original 0009, guest PC 0x0c04c74e */
if(!s->budget--) { s->failed_pc=0x0c04c74eu; return 0; }
goto P_0c04c750;
P_0c04c750: /* original 2fe6, guest PC 0x0c04c750 */
if(!s->budget--) { s->failed_pc=0x0c04c750u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c752;
P_0c04c752: /* original 2fd6, guest PC 0x0c04c752 */
if(!s->budget--) { s->failed_pc=0x0c04c752u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c754;
P_0c04c754: /* original ed00, guest PC 0x0c04c754 */
if(!s->budget--) { s->failed_pc=0x0c04c754u; return 0; }
r[13]=0x00000000u;
goto P_0c04c756;
P_0c04c756: /* original 2fc6, guest PC 0x0c04c756 */
if(!s->budget--) { s->failed_pc=0x0c04c756u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c758;
P_0c04c758: /* original 6c43, guest PC 0x0c04c758 */
if(!s->budget--) { s->failed_pc=0x0c04c758u; return 0; }
r[12]=r[4];
goto P_0c04c75a;
P_0c04c75a: /* original 2fb6, guest PC 0x0c04c75a */
if(!s->budget--) { s->failed_pc=0x0c04c75au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c75c;
P_0c04c75c: /* original 60c3, guest PC 0x0c04c75c */
if(!s->budget--) { s->failed_pc=0x0c04c75cu; return 0; }
r[0]=r[12];
goto P_0c04c75e;
P_0c04c75e: /* original 2fa6, guest PC 0x0c04c75e */
if(!s->budget--) { s->failed_pc=0x0c04c75eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c760;
P_0c04c760: /* original 880f, guest PC 0x0c04c760 */
if(!s->budget--) { s->failed_pc=0x0c04c760u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c04c762;
P_0c04c762: /* original 2f96, guest PC 0x0c04c762 */
if(!s->budget--) { s->failed_pc=0x0c04c762u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c764;
P_0c04c764: /* original ea01, guest PC 0x0c04c764 */
if(!s->budget--) { s->failed_pc=0x0c04c764u; return 0; }
r[10]=0x00000001u;
goto P_0c04c766;
P_0c04c766: /* original 2f86, guest PC 0x0c04c766 */
if(!s->budget--) { s->failed_pc=0x0c04c766u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c768;
P_0c04c768: /* original 4f22, guest PC 0x0c04c768 */
if(!s->budget--) { s->failed_pc=0x0c04c768u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c76a;
P_0c04c76a: /* original 4f12, guest PC 0x0c04c76a */
if(!s->budget--) { s->failed_pc=0x0c04c76au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04c76c;
P_0c04c76c: /* original 7fec, guest PC 0x0c04c76c */
if(!s->budget--) { s->failed_pc=0x0c04c76cu; return 0; }
r[15]+=0xffffffecu;
goto P_0c04c76e;
P_0c04c76e: /* original 1f52, guest PC 0x0c04c76e */
if(!s->budget--) { s->failed_pc=0x0c04c76eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c04c770;
P_0c04c770: /* original d419, guest PC 0x0c04c770 */
if(!s->budget--) { s->failed_pc=0x0c04c770u; return 0; }
r[4]=read(ram,0x0c04c7d8u,4);
goto P_0c04c772;
P_0c04c772: /* original d316, guest PC 0x0c04c772 */
if(!s->budget--) { s->failed_pc=0x0c04c772u; return 0; }
r[3]=read(ram,0x0c04c7ccu,4);
goto P_0c04c774;
P_0c04c774: /* original d717, guest PC 0x0c04c774 */
if(!s->budget--) { s->failed_pc=0x0c04c774u; return 0; }
r[7]=read(ram,0x0c04c7d4u,4);
goto P_0c04c776;
P_0c04c776: /* original de16, guest PC 0x0c04c776 */
if(!s->budget--) { s->failed_pc=0x0c04c776u; return 0; }
r[14]=read(ram,0x0c04c7d0u,4);
goto P_0c04c778;
P_0c04c778: /* original 8d08, guest PC 0x0c04c778 */
if(!s->budget--) { s->failed_pc=0x0c04c778u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(cond) { goto P_0c04c78c; }
goto P_0c04c77c;
P_0c04c77a: /* original 6532, guest PC 0x0c04c77a */
if(!s->budget--) { s->failed_pc=0x0c04c77au; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c04c77c;
P_0c04c77c: /* original 8821, guest PC 0x0c04c77c */
if(!s->budget--) { s->failed_pc=0x0c04c77cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000021u)!=0);
goto P_0c04c77e;
P_0c04c77e: /* original 8909, guest PC 0x0c04c77e */
if(!s->budget--) { s->failed_pc=0x0c04c77eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c794; }
goto P_0c04c780;
P_0c04c780: /* original 8841, guest PC 0x0c04c780 */
if(!s->budget--) { s->failed_pc=0x0c04c780u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000041u)!=0);
goto P_0c04c782;
P_0c04c782: /* original 890c, guest PC 0x0c04c782 */
if(!s->budget--) { s->failed_pc=0x0c04c782u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c79e; }
goto P_0c04c784;
P_0c04c784: /* original 887a, guest PC 0x0c04c784 */
if(!s->budget--) { s->failed_pc=0x0c04c784u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000007au)!=0);
goto P_0c04c786;
P_0c04c786: /* original 890f, guest PC 0x0c04c786 */
if(!s->budget--) { s->failed_pc=0x0c04c786u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c7a8; }
goto P_0c04c788;
P_0c04c788: /* original a028, guest PC 0x0c04c788 */
if(!s->budget--) { s->failed_pc=0x0c04c788u; return 0; }
goto P_0c04c7dc;
P_0c04c78a: /* original 0009, guest PC 0x0c04c78a */
if(!s->budget--) { s->failed_pc=0x0c04c78au; return 0; }
goto P_0c04c78c;
P_0c04c78c: /* original 15d1, guest PC 0x0c04c78c */
if(!s->budget--) { s->failed_pc=0x0c04c78cu; return 0; }
write(ram,r[5]+4,r[13],4);
goto P_0c04c78e;
P_0c04c78e: /* original 6872, guest PC 0x0c04c78e */
if(!s->budget--) { s->failed_pc=0x0c04c78eu; return 0; }
tmp=read(ram,r[7],4);
r[8]=tmp;
goto P_0c04c790;
P_0c04c790: /* original a003, guest PC 0x0c04c790 */
if(!s->budget--) { s->failed_pc=0x0c04c790u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c04c79a;
P_0c04c792: /* original 6242, guest PC 0x0c04c792 */
if(!s->budget--) { s->failed_pc=0x0c04c792u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c04c794;
P_0c04c794: /* original 15a1, guest PC 0x0c04c794 */
if(!s->budget--) { s->failed_pc=0x0c04c794u; return 0; }
write(ram,r[5]+4,r[10],4);
goto P_0c04c796;
P_0c04c796: /* original 5241, guest PC 0x0c04c796 */
if(!s->budget--) { s->failed_pc=0x0c04c796u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c04c798;
P_0c04c798: /* original 5871, guest PC 0x0c04c798 */
if(!s->budget--) { s->failed_pc=0x0c04c798u; return 0; }
r[8]=read(ram,r[7]+4,4);
goto P_0c04c79a;
P_0c04c79a: /* original a02a, guest PC 0x0c04c79a */
if(!s->budget--) { s->failed_pc=0x0c04c79au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c04c7f2;
P_0c04c79c: /* original 1f21, guest PC 0x0c04c79c */
if(!s->budget--) { s->failed_pc=0x0c04c79cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c04c79e;
P_0c04c79e: /* original e202, guest PC 0x0c04c79e */
if(!s->budget--) { s->failed_pc=0x0c04c79eu; return 0; }
r[2]=0x00000002u;
goto P_0c04c7a0;
P_0c04c7a0: /* original 1521, guest PC 0x0c04c7a0 */
if(!s->budget--) { s->failed_pc=0x0c04c7a0u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c04c7a2;
P_0c04c7a2: /* original 5872, guest PC 0x0c04c7a2 */
if(!s->budget--) { s->failed_pc=0x0c04c7a2u; return 0; }
r[8]=read(ram,r[7]+8,4);
goto P_0c04c7a4;
P_0c04c7a4: /* original a004, guest PC 0x0c04c7a4 */
if(!s->budget--) { s->failed_pc=0x0c04c7a4u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c04c7b0;
P_0c04c7a6: /* original 5142, guest PC 0x0c04c7a6 */
if(!s->budget--) { s->failed_pc=0x0c04c7a6u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c04c7a8;
P_0c04c7a8: /* original e203, guest PC 0x0c04c7a8 */
if(!s->budget--) { s->failed_pc=0x0c04c7a8u; return 0; }
r[2]=0x00000003u;
goto P_0c04c7aa;
P_0c04c7aa: /* original 1521, guest PC 0x0c04c7aa */
if(!s->budget--) { s->failed_pc=0x0c04c7aau; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c04c7ac;
P_0c04c7ac: /* original 5873, guest PC 0x0c04c7ac */
if(!s->budget--) { s->failed_pc=0x0c04c7acu; return 0; }
r[8]=read(ram,r[7]+12,4);
goto P_0c04c7ae;
P_0c04c7ae: /* original 5143, guest PC 0x0c04c7ae */
if(!s->budget--) { s->failed_pc=0x0c04c7aeu; return 0; }
r[1]=read(ram,r[4]+12,4);
goto P_0c04c7b0;
P_0c04c7b0: /* original a01f, guest PC 0x0c04c7b0 */
if(!s->budget--) { s->failed_pc=0x0c04c7b0u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c04c7f2;
P_0c04c7b2: /* original 1f11, guest PC 0x0c04c7b2 */
if(!s->budget--) { s->failed_pc=0x0c04c7b2u; return 0; }
write(ram,r[15]+4,r[1],4);
if(!vf3_matrix_family(0x0c04c7b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c7b4u; return 0; } return 1;
P_0c04c7dc: /* original 2fc6, guest PC 0x0c04c7dc */
if(!s->budget--) { s->failed_pc=0x0c04c7dcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c7de;
P_0c04c7de: /* original 91a3, guest PC 0x0c04c7de */
if(!s->budget--) { s->failed_pc=0x0c04c7deu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c928u,2);
goto P_0c04c7e0;
P_0c04c7e0: /* original 2f16, guest PC 0x0c04c7e0 */
if(!s->budget--) { s->failed_pc=0x0c04c7e0u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c7e2;
P_0c04c7e2: /* original d254, guest PC 0x0c04c7e2 */
if(!s->budget--) { s->failed_pc=0x0c04c7e2u; return 0; }
r[2]=read(ram,0x0c04c934u,4);
goto P_0c04c7e4;
P_0c04c7e4: /* original 2f26, guest PC 0x0c04c7e4 */
if(!s->budget--) { s->failed_pc=0x0c04c7e4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c7e6;
P_0c04c7e6: /* original d354, guest PC 0x0c04c7e6 */
if(!s->budget--) { s->failed_pc=0x0c04c7e6u; return 0; }
r[3]=read(ram,0x0c04c938u,4);
goto P_0c04c7e8;
P_0c04c7e8: /* original beda, guest PC 0x0c04c7e8 */
if(!s->budget--) { s->failed_pc=0x0c04c7e8u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04c7ecu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c7ecu) { target=s->pc; goto dispatch; }
goto P_0c04c7ec;
P_0c04c7ea: /* original 2f36, guest PC 0x0c04c7ea */
if(!s->budget--) { s->failed_pc=0x0c04c7eau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c7ec;
P_0c04c7ec: /* original 909d, guest PC 0x0c04c7ec */
if(!s->budget--) { s->failed_pc=0x0c04c7ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c92au,2);
goto P_0c04c7ee;
P_0c04c7ee: /* original a090, guest PC 0x0c04c7ee */
if(!s->budget--) { s->failed_pc=0x0c04c7eeu; return 0; }
r[15]+=0x00000010u;
goto P_0c04c912;
P_0c04c7f0: /* original 7f10, guest PC 0x0c04c7f0 */
if(!s->budget--) { s->failed_pc=0x0c04c7f0u; return 0; }
r[15]+=0x00000010u;
goto P_0c04c7f2;
P_0c04c7f2: /* original 4c18, guest PC 0x0c04c7f2 */
if(!s->budget--) { s->failed_pc=0x0c04c7f2u; return 0; }
r[12]<<=8;
goto P_0c04c7f4;
P_0c04c7f4: /* original 6b63, guest PC 0x0c04c7f4 */
if(!s->budget--) { s->failed_pc=0x0c04c7f4u; return 0; }
r[11]=r[6];
goto P_0c04c7f6;
P_0c04c7f6: /* original 4c00, guest PC 0x0c04c7f6 */
if(!s->budget--) { s->failed_pc=0x0c04c7f6u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c04c7f8;
P_0c04c7f8: /* original 7c20, guest PC 0x0c04c7f8 */
if(!s->budget--) { s->failed_pc=0x0c04c7f8u; return 0; }
r[12]+=0x00000020u;
goto P_0c04c7fa;
P_0c04c7fa: /* original 1fc4, guest PC 0x0c04c7fa */
if(!s->budget--) { s->failed_pc=0x0c04c7fau; return 0; }
write(ram,r[15]+16,r[12],4);
goto P_0c04c7fc;
P_0c04c7fc: /* original d24f, guest PC 0x0c04c7fc */
if(!s->budget--) { s->failed_pc=0x0c04c7fcu; return 0; }
r[2]=read(ram,0x0c04c93cu,4);
goto P_0c04c7fe;
P_0c04c7fe: /* original 6322, guest PC 0x0c04c7fe */
if(!s->budget--) { s->failed_pc=0x0c04c7feu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04c800;
P_0c04c800: /* original 2f36, guest PC 0x0c04c800 */
if(!s->budget--) { s->failed_pc=0x0c04c800u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c802;
P_0c04c802: /* original d14f, guest PC 0x0c04c802 */
if(!s->budget--) { s->failed_pc=0x0c04c802u; return 0; }
r[1]=read(ram,0x0c04c940u,4);
goto P_0c04c804;
P_0c04c804: /* original becc, guest PC 0x0c04c804 */
if(!s->budget--) { s->failed_pc=0x0c04c804u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04c808u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c808u) { target=s->pc; goto dispatch; }
goto P_0c04c808;
P_0c04c806: /* original 2f16, guest PC 0x0c04c806 */
if(!s->budget--) { s->failed_pc=0x0c04c806u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c808;
P_0c04c808: /* original 52f3, guest PC 0x0c04c808 */
if(!s->budget--) { s->failed_pc=0x0c04c808u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c04c80a;
P_0c04c80a: /* original e301, guest PC 0x0c04c80a */
if(!s->budget--) { s->failed_pc=0x0c04c80au; return 0; }
r[3]=0x00000001u;
goto P_0c04c80c;
P_0c04c80c: /* original 2f26, guest PC 0x0c04c80c */
if(!s->budget--) { s->failed_pc=0x0c04c80cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c80e;
P_0c04c80e: /* original 2f86, guest PC 0x0c04c80e */
if(!s->budget--) { s->failed_pc=0x0c04c80eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c810;
P_0c04c810: /* original 2f36, guest PC 0x0c04c810 */
if(!s->budget--) { s->failed_pc=0x0c04c810u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c812;
P_0c04c812: /* original d24c, guest PC 0x0c04c812 */
if(!s->budget--) { s->failed_pc=0x0c04c812u; return 0; }
r[2]=read(ram,0x0c04c944u,4);
goto P_0c04c814;
P_0c04c814: /* original bec4, guest PC 0x0c04c814 */
if(!s->budget--) { s->failed_pc=0x0c04c814u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04c818u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c818u) { target=s->pc; goto dispatch; }
goto P_0c04c818;
P_0c04c816: /* original 2f26, guest PC 0x0c04c816 */
if(!s->budget--) { s->failed_pc=0x0c04c816u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c818;
P_0c04c818: /* original 6383, guest PC 0x0c04c818 */
if(!s->budget--) { s->failed_pc=0x0c04c818u; return 0; }
r[3]=r[8];
goto P_0c04c81a;
P_0c04c81a: /* original 7301, guest PC 0x0c04c81a */
if(!s->budget--) { s->failed_pc=0x0c04c81au; return 0; }
r[3]+=0x00000001u;
goto P_0c04c81c;
P_0c04c81c: /* original 4318, guest PC 0x0c04c81c */
if(!s->budget--) { s->failed_pc=0x0c04c81cu; return 0; }
r[3]<<=8;
goto P_0c04c81e;
P_0c04c81e: /* original 69d3, guest PC 0x0c04c81e */
if(!s->budget--) { s->failed_pc=0x0c04c81eu; return 0; }
r[9]=r[13];
goto P_0c04c820;
P_0c04c820: /* original 7f18, guest PC 0x0c04c820 */
if(!s->budget--) { s->failed_pc=0x0c04c820u; return 0; }
r[15]+=0x00000018u;
goto P_0c04c822;
P_0c04c822: /* original 4300, guest PC 0x0c04c822 */
if(!s->budget--) { s->failed_pc=0x0c04c822u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c04c824;
P_0c04c824: /* original 2fa2, guest PC 0x0c04c824 */
if(!s->budget--) { s->failed_pc=0x0c04c824u; return 0; }
write(ram,r[15],r[10],4);
goto P_0c04c826;
P_0c04c826: /* original dc48, guest PC 0x0c04c826 */
if(!s->budget--) { s->failed_pc=0x0c04c826u; return 0; }
r[12]=read(ram,0x0c04c948u,4);
goto P_0c04c828;
P_0c04c828: /* original a06f, guest PC 0x0c04c828 */
if(!s->budget--) { s->failed_pc=0x0c04c828u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c04c90a;
P_0c04c82a: /* original 1f33, guest PC 0x0c04c82a */
if(!s->budget--) { s->failed_pc=0x0c04c82au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c04c82c;
P_0c04c82c: /* original 52f2, guest PC 0x0c04c82c */
if(!s->budget--) { s->failed_pc=0x0c04c82cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04c82e;
P_0c04c82e: /* original 63f2, guest PC 0x0c04c82e */
if(!s->budget--) { s->failed_pc=0x0c04c82eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04c830;
P_0c04c830: /* original 2238, guest PC 0x0c04c830 */
if(!s->budget--) { s->failed_pc=0x0c04c830u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c04c832;
P_0c04c832: /* original 8964, guest PC 0x0c04c832 */
if(!s->budget--) { s->failed_pc=0x0c04c832u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c8fe; }
goto P_0c04c834;
P_0c04c834: /* original e34c, guest PC 0x0c04c834 */
if(!s->budget--) { s->failed_pc=0x0c04c834u; return 0; }
r[3]=0x0000004cu;
goto P_0c04c836;
P_0c04c836: /* original 60a3, guest PC 0x0c04c836 */
if(!s->budget--) { s->failed_pc=0x0c04c836u; return 0; }
r[0]=r[10];
goto P_0c04c838;
P_0c04c838: /* original 293f, guest PC 0x0c04c838 */
if(!s->budget--) { s->failed_pc=0x0c04c838u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[9]*(int32_t)(int16_t)r[3]);
goto P_0c04c83a;
P_0c04c83a: /* original 80e2, guest PC 0x0c04c83a */
if(!s->budget--) { s->failed_pc=0x0c04c83au; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c04c83c;
P_0c04c83c: /* original 60d3, guest PC 0x0c04c83c */
if(!s->budget--) { s->failed_pc=0x0c04c83cu; return 0; }
r[0]=r[13];
goto P_0c04c83e;
P_0c04c83e: /* original 2e91, guest PC 0x0c04c83e */
if(!s->budget--) { s->failed_pc=0x0c04c83eu; return 0; }
write(ram,r[14],r[9],2);
goto P_0c04c840;
P_0c04c840: /* original d242, guest PC 0x0c04c840 */
if(!s->budget--) { s->failed_pc=0x0c04c840u; return 0; }
r[2]=read(ram,0x0c04c94cu,4);
goto P_0c04c842;
P_0c04c842: /* original 031a, guest PC 0x0c04c842 */
if(!s->budget--) { s->failed_pc=0x0c04c842u; return 0; }
r[3]=r[19];
goto P_0c04c844;
P_0c04c844: /* original 633f, guest PC 0x0c04c844 */
if(!s->budget--) { s->failed_pc=0x0c04c844u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04c846;
P_0c04c846: /* original 332c, guest PC 0x0c04c846 */
if(!s->budget--) { s->failed_pc=0x0c04c846u; return 0; }
r[3]+=r[2];
goto P_0c04c848;
P_0c04c848: /* original 1e37, guest PC 0x0c04c848 */
if(!s->budget--) { s->failed_pc=0x0c04c848u; return 0; }
write(ram,r[14]+28,r[3],4);
goto P_0c04c84a;
P_0c04c84a: /* original 63b3, guest PC 0x0c04c84a */
if(!s->budget--) { s->failed_pc=0x0c04c84au; return 0; }
r[3]=r[11];
goto P_0c04c84c;
P_0c04c84c: /* original 7320, guest PC 0x0c04c84c */
if(!s->budget--) { s->failed_pc=0x0c04c84cu; return 0; }
r[3]+=0x00000020u;
goto P_0c04c84e;
P_0c04c84e: /* original 80ea, guest PC 0x0c04c84e */
if(!s->budget--) { s->failed_pc=0x0c04c84eu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04c850;
P_0c04c850: /* original 80eb, guest PC 0x0c04c850 */
if(!s->budget--) { s->failed_pc=0x0c04c850u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04c852;
P_0c04c852: /* original 80ec, guest PC 0x0c04c852 */
if(!s->budget--) { s->failed_pc=0x0c04c852u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04c854;
P_0c04c854: /* original 60d3, guest PC 0x0c04c854 */
if(!s->budget--) { s->failed_pc=0x0c04c854u; return 0; }
r[0]=r[13];
goto P_0c04c856;
P_0c04c856: /* original 1ebb, guest PC 0x0c04c856 */
if(!s->budget--) { s->failed_pc=0x0c04c856u; return 0; }
write(ram,r[14]+44,r[11],4);
goto P_0c04c858;
P_0c04c858: /* original 1e38, guest PC 0x0c04c858 */
if(!s->budget--) { s->failed_pc=0x0c04c858u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c04c85a;
P_0c04c85a: /* original 9167, guest PC 0x0c04c85a */
if(!s->budget--) { s->failed_pc=0x0c04c85au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c92cu,2);
goto P_0c04c85c;
P_0c04c85c: /* original 31bc, guest PC 0x0c04c85c */
if(!s->budget--) { s->failed_pc=0x0c04c85cu; return 0; }
r[1]+=r[11];
goto P_0c04c85e;
P_0c04c85e: /* original 1e19, guest PC 0x0c04c85e */
if(!s->budget--) { s->failed_pc=0x0c04c85eu; return 0; }
write(ram,r[14]+36,r[1],4);
goto P_0c04c860;
P_0c04c860: /* original 53f3, guest PC 0x0c04c860 */
if(!s->budget--) { s->failed_pc=0x0c04c860u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c04c862;
P_0c04c862: /* original 33bc, guest PC 0x0c04c862 */
if(!s->budget--) { s->failed_pc=0x0c04c862u; return 0; }
r[3]+=r[11];
goto P_0c04c864;
P_0c04c864: /* original 7320, guest PC 0x0c04c864 */
if(!s->budget--) { s->failed_pc=0x0c04c864u; return 0; }
r[3]+=0x00000020u;
goto P_0c04c866;
P_0c04c866: /* original 1e3a, guest PC 0x0c04c866 */
if(!s->budget--) { s->failed_pc=0x0c04c866u; return 0; }
write(ram,r[14]+40,r[3],4);
goto P_0c04c868;
P_0c04c868: /* original 80e8, guest PC 0x0c04c868 */
if(!s->budget--) { s->failed_pc=0x0c04c868u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c04c86a;
P_0c04c86a: /* original 80e9, guest PC 0x0c04c86a */
if(!s->budget--) { s->failed_pc=0x0c04c86au; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c04c86c;
P_0c04c86c: /* original 60a3, guest PC 0x0c04c86c */
if(!s->budget--) { s->failed_pc=0x0c04c86cu; return 0; }
r[0]=r[10];
goto P_0c04c86e;
P_0c04c86e: /* original 81e7, guest PC 0x0c04c86e */
if(!s->budget--) { s->failed_pc=0x0c04c86eu; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c04c870;
P_0c04c870: /* original 6083, guest PC 0x0c04c870 */
if(!s->budget--) { s->failed_pc=0x0c04c870u; return 0; }
r[0]=r[8];
goto P_0c04c872;
P_0c04c872: /* original 81e8, guest PC 0x0c04c872 */
if(!s->budget--) { s->failed_pc=0x0c04c872u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c04c874;
P_0c04c874: /* original 85f2, guest PC 0x0c04c874 */
if(!s->budget--) { s->failed_pc=0x0c04c874u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04c876;
P_0c04c876: /* original e500, guest PC 0x0c04c876 */
if(!s->budget--) { s->failed_pc=0x0c04c876u; return 0; }
r[5]=0x00000000u;
goto P_0c04c878;
P_0c04c878: /* original 64e3, guest PC 0x0c04c878 */
if(!s->budget--) { s->failed_pc=0x0c04c878u; return 0; }
r[4]=r[14];
goto P_0c04c87a;
P_0c04c87a: /* original e610, guest PC 0x0c04c87a */
if(!s->budget--) { s->failed_pc=0x0c04c87au; return 0; }
r[6]=0x00000010u;
goto P_0c04c87c;
P_0c04c87c: /* original 81e9, guest PC 0x0c04c87c */
if(!s->budget--) { s->failed_pc=0x0c04c87cu; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c04c87e;
P_0c04c87e: /* original e020, guest PC 0x0c04c87e */
if(!s->budget--) { s->failed_pc=0x0c04c87eu; return 0; }
r[0]=0x00000020u;
goto P_0c04c880;
P_0c04c880: /* original 81ea, guest PC 0x0c04c880 */
if(!s->budget--) { s->failed_pc=0x0c04c880u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c04c882;
P_0c04c882: /* original 4c0b, guest PC 0x0c04c882 */
if(!s->budget--) { s->failed_pc=0x0c04c882u; return 0; }
target=r[12];
r[16]=code_base|0x0c04c886u;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c886u) { target=s->pc; goto dispatch; }
goto P_0c04c886;
P_0c04c884: /* original 7438, guest PC 0x0c04c884 */
if(!s->budget--) { s->failed_pc=0x0c04c884u; return 0; }
r[4]+=0x00000038u;
goto P_0c04c886;
P_0c04c886: /* original 9652, guest PC 0x0c04c886 */
if(!s->budget--) { s->failed_pc=0x0c04c886u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c92eu,2);
goto P_0c04c888;
P_0c04c888: /* original 64e3, guest PC 0x0c04c888 */
if(!s->budget--) { s->failed_pc=0x0c04c888u; return 0; }
r[4]=r[14];
goto P_0c04c88a;
P_0c04c88a: /* original e500, guest PC 0x0c04c88a */
if(!s->budget--) { s->failed_pc=0x0c04c88au; return 0; }
r[5]=0x00000000u;
goto P_0c04c88c;
P_0c04c88c: /* original 4c0b, guest PC 0x0c04c88c */
if(!s->budget--) { s->failed_pc=0x0c04c88cu; return 0; }
target=r[12];
r[16]=code_base|0x0c04c890u;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c890u) { target=s->pc; goto dispatch; }
goto P_0c04c890;
P_0c04c88e: /* original 7448, guest PC 0x0c04c88e */
if(!s->budget--) { s->failed_pc=0x0c04c88eu; return 0; }
r[4]+=0x00000048u;
goto P_0c04c890;
P_0c04c890: /* original e547, guest PC 0x0c04c890 */
if(!s->budget--) { s->failed_pc=0x0c04c890u; return 0; }
r[5]=0x00000047u;
goto P_0c04c892;
P_0c04c892: /* original e620, guest PC 0x0c04c892 */
if(!s->budget--) { s->failed_pc=0x0c04c892u; return 0; }
r[6]=0x00000020u;
goto P_0c04c894;
P_0c04c894: /* original 4c0b, guest PC 0x0c04c894 */
if(!s->budget--) { s->failed_pc=0x0c04c894u; return 0; }
target=r[12];
r[16]=code_base|0x0c04c898u;
r[4]=read(ram,r[14]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c898u) { target=s->pc; goto dispatch; }
goto P_0c04c898;
P_0c04c896: /* original 54eb, guest PC 0x0c04c896 */
if(!s->budget--) { s->failed_pc=0x0c04c896u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c04c898;
P_0c04c898: /* original e553, guest PC 0x0c04c898 */
if(!s->budget--) { s->failed_pc=0x0c04c898u; return 0; }
r[5]=0x00000053u;
goto P_0c04c89a;
P_0c04c89a: /* original e620, guest PC 0x0c04c89a */
if(!s->budget--) { s->failed_pc=0x0c04c89au; return 0; }
r[6]=0x00000020u;
goto P_0c04c89c;
P_0c04c89c: /* original 4c0b, guest PC 0x0c04c89c */
if(!s->budget--) { s->failed_pc=0x0c04c89cu; return 0; }
target=r[12];
r[16]=code_base|0x0c04c8a0u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c8a0u) { target=s->pc; goto dispatch; }
goto P_0c04c8a0;
P_0c04c89e: /* original 54e8, guest PC 0x0c04c89e */
if(!s->budget--) { s->failed_pc=0x0c04c89eu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04c8a0;
P_0c04c8a0: /* original e546, guest PC 0x0c04c8a0 */
if(!s->budget--) { s->failed_pc=0x0c04c8a0u; return 0; }
r[5]=0x00000046u;
goto P_0c04c8a2;
P_0c04c8a2: /* original e620, guest PC 0x0c04c8a2 */
if(!s->budget--) { s->failed_pc=0x0c04c8a2u; return 0; }
r[6]=0x00000020u;
goto P_0c04c8a4;
P_0c04c8a4: /* original 4c0b, guest PC 0x0c04c8a4 */
if(!s->budget--) { s->failed_pc=0x0c04c8a4u; return 0; }
target=r[12];
r[16]=code_base|0x0c04c8a8u;
r[4]=read(ram,r[14]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c8a8u) { target=s->pc; goto dispatch; }
goto P_0c04c8a8;
P_0c04c8a6: /* original 54e9, guest PC 0x0c04c8a6 */
if(!s->budget--) { s->failed_pc=0x0c04c8a6u; return 0; }
r[4]=read(ram,r[14]+36,4);
goto P_0c04c8a8;
P_0c04c8a8: /* original e544, guest PC 0x0c04c8a8 */
if(!s->budget--) { s->failed_pc=0x0c04c8a8u; return 0; }
r[5]=0x00000044u;
goto P_0c04c8aa;
P_0c04c8aa: /* original e620, guest PC 0x0c04c8aa */
if(!s->budget--) { s->failed_pc=0x0c04c8aau; return 0; }
r[6]=0x00000020u;
goto P_0c04c8ac;
P_0c04c8ac: /* original 4c0b, guest PC 0x0c04c8ac */
if(!s->budget--) { s->failed_pc=0x0c04c8acu; return 0; }
target=r[12];
r[16]=code_base|0x0c04c8b0u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c8b0u) { target=s->pc; goto dispatch; }
goto P_0c04c8b0;
P_0c04c8ae: /* original 54ea, guest PC 0x0c04c8ae */
if(!s->budget--) { s->failed_pc=0x0c04c8aeu; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04c8b0;
P_0c04c8b0: /* original 53f4, guest PC 0x0c04c8b0 */
if(!s->budget--) { s->failed_pc=0x0c04c8b0u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c04c8b2;
P_0c04c8b2: /* original 2f96, guest PC 0x0c04c8b2 */
if(!s->budget--) { s->failed_pc=0x0c04c8b2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8b4;
P_0c04c8b4: /* original 3b3c, guest PC 0x0c04c8b4 */
if(!s->budget--) { s->failed_pc=0x0c04c8b4u; return 0; }
r[11]+=r[3];
goto P_0c04c8b6;
P_0c04c8b6: /* original d326, guest PC 0x0c04c8b6 */
if(!s->budget--) { s->failed_pc=0x0c04c8b6u; return 0; }
r[3]=read(ram,0x0c04c950u,4);
goto P_0c04c8b8;
P_0c04c8b8: /* original be72, guest PC 0x0c04c8b8 */
if(!s->budget--) { s->failed_pc=0x0c04c8b8u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04c8bcu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c8bcu) { target=s->pc; goto dispatch; }
goto P_0c04c8bc;
P_0c04c8ba: /* original 2f36, guest PC 0x0c04c8ba */
if(!s->budget--) { s->failed_pc=0x0c04c8bau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8bc;
P_0c04c8bc: /* original 51e8, guest PC 0x0c04c8bc */
if(!s->budget--) { s->failed_pc=0x0c04c8bcu; return 0; }
r[1]=read(ram,r[14]+32,4);
goto P_0c04c8be;
P_0c04c8be: /* original 71ff, guest PC 0x0c04c8be */
if(!s->budget--) { s->failed_pc=0x0c04c8beu; return 0; }
r[1]+=0xffffffffu;
goto P_0c04c8c0;
P_0c04c8c0: /* original 2f16, guest PC 0x0c04c8c0 */
if(!s->budget--) { s->failed_pc=0x0c04c8c0u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8c2;
P_0c04c8c2: /* original 53eb, guest PC 0x0c04c8c2 */
if(!s->budget--) { s->failed_pc=0x0c04c8c2u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c04c8c4;
P_0c04c8c4: /* original 2f36, guest PC 0x0c04c8c4 */
if(!s->budget--) { s->failed_pc=0x0c04c8c4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8c6;
P_0c04c8c6: /* original d223, guest PC 0x0c04c8c6 */
if(!s->budget--) { s->failed_pc=0x0c04c8c6u; return 0; }
r[2]=read(ram,0x0c04c954u,4);
goto P_0c04c8c8;
P_0c04c8c8: /* original be6a, guest PC 0x0c04c8c8 */
if(!s->budget--) { s->failed_pc=0x0c04c8c8u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04c8ccu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c8ccu) { target=s->pc; goto dispatch; }
goto P_0c04c8cc;
P_0c04c8ca: /* original 2f26, guest PC 0x0c04c8ca */
if(!s->budget--) { s->failed_pc=0x0c04c8cau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8cc;
P_0c04c8cc: /* original 51e9, guest PC 0x0c04c8cc */
if(!s->budget--) { s->failed_pc=0x0c04c8ccu; return 0; }
r[1]=read(ram,r[14]+36,4);
goto P_0c04c8ce;
P_0c04c8ce: /* original 71ff, guest PC 0x0c04c8ce */
if(!s->budget--) { s->failed_pc=0x0c04c8ceu; return 0; }
r[1]+=0xffffffffu;
goto P_0c04c8d0;
P_0c04c8d0: /* original 2f16, guest PC 0x0c04c8d0 */
if(!s->budget--) { s->failed_pc=0x0c04c8d0u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8d2;
P_0c04c8d2: /* original 53e8, guest PC 0x0c04c8d2 */
if(!s->budget--) { s->failed_pc=0x0c04c8d2u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c04c8d4;
P_0c04c8d4: /* original 2f36, guest PC 0x0c04c8d4 */
if(!s->budget--) { s->failed_pc=0x0c04c8d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8d6;
P_0c04c8d6: /* original d220, guest PC 0x0c04c8d6 */
if(!s->budget--) { s->failed_pc=0x0c04c8d6u; return 0; }
r[2]=read(ram,0x0c04c958u,4);
goto P_0c04c8d8;
P_0c04c8d8: /* original be62, guest PC 0x0c04c8d8 */
if(!s->budget--) { s->failed_pc=0x0c04c8d8u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04c8dcu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c8dcu) { target=s->pc; goto dispatch; }
goto P_0c04c8dc;
P_0c04c8da: /* original 2f26, guest PC 0x0c04c8da */
if(!s->budget--) { s->failed_pc=0x0c04c8dau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8dc;
P_0c04c8dc: /* original 51ea, guest PC 0x0c04c8dc */
if(!s->budget--) { s->failed_pc=0x0c04c8dcu; return 0; }
r[1]=read(ram,r[14]+40,4);
goto P_0c04c8de;
P_0c04c8de: /* original 71ff, guest PC 0x0c04c8de */
if(!s->budget--) { s->failed_pc=0x0c04c8deu; return 0; }
r[1]+=0xffffffffu;
goto P_0c04c8e0;
P_0c04c8e0: /* original 2f16, guest PC 0x0c04c8e0 */
if(!s->budget--) { s->failed_pc=0x0c04c8e0u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8e2;
P_0c04c8e2: /* original 53e9, guest PC 0x0c04c8e2 */
if(!s->budget--) { s->failed_pc=0x0c04c8e2u; return 0; }
r[3]=read(ram,r[14]+36,4);
goto P_0c04c8e4;
P_0c04c8e4: /* original 2f36, guest PC 0x0c04c8e4 */
if(!s->budget--) { s->failed_pc=0x0c04c8e4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8e6;
P_0c04c8e6: /* original d21d, guest PC 0x0c04c8e6 */
if(!s->budget--) { s->failed_pc=0x0c04c8e6u; return 0; }
r[2]=read(ram,0x0c04c95cu,4);
goto P_0c04c8e8;
P_0c04c8e8: /* original be5a, guest PC 0x0c04c8e8 */
if(!s->budget--) { s->failed_pc=0x0c04c8e8u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04c8ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c8ecu) { target=s->pc; goto dispatch; }
goto P_0c04c8ec;
P_0c04c8ea: /* original 2f26, guest PC 0x0c04c8ea */
if(!s->budget--) { s->failed_pc=0x0c04c8eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8ec;
P_0c04c8ec: /* original 61b3, guest PC 0x0c04c8ec */
if(!s->budget--) { s->failed_pc=0x0c04c8ecu; return 0; }
r[1]=r[11];
goto P_0c04c8ee;
P_0c04c8ee: /* original 71ff, guest PC 0x0c04c8ee */
if(!s->budget--) { s->failed_pc=0x0c04c8eeu; return 0; }
r[1]+=0xffffffffu;
goto P_0c04c8f0;
P_0c04c8f0: /* original 2f16, guest PC 0x0c04c8f0 */
if(!s->budget--) { s->failed_pc=0x0c04c8f0u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8f2;
P_0c04c8f2: /* original 53ea, guest PC 0x0c04c8f2 */
if(!s->budget--) { s->failed_pc=0x0c04c8f2u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c04c8f4;
P_0c04c8f4: /* original 2f36, guest PC 0x0c04c8f4 */
if(!s->budget--) { s->failed_pc=0x0c04c8f4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8f6;
P_0c04c8f6: /* original d21a, guest PC 0x0c04c8f6 */
if(!s->budget--) { s->failed_pc=0x0c04c8f6u; return 0; }
r[2]=read(ram,0x0c04c960u,4);
goto P_0c04c8f8;
P_0c04c8f8: /* original be52, guest PC 0x0c04c8f8 */
if(!s->budget--) { s->failed_pc=0x0c04c8f8u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04c8fcu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c8fcu) { target=s->pc; goto dispatch; }
goto P_0c04c8fc;
P_0c04c8fa: /* original 2f26, guest PC 0x0c04c8fa */
if(!s->budget--) { s->failed_pc=0x0c04c8fau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c8fc;
P_0c04c8fc: /* original 7f38, guest PC 0x0c04c8fc */
if(!s->budget--) { s->failed_pc=0x0c04c8fcu; return 0; }
r[15]+=0x00000038u;
goto P_0c04c8fe;
P_0c04c8fe: /* original 62f2, guest PC 0x0c04c8fe */
if(!s->budget--) { s->failed_pc=0x0c04c8feu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04c900;
P_0c04c900: /* original 7901, guest PC 0x0c04c900 */
if(!s->budget--) { s->failed_pc=0x0c04c900u; return 0; }
r[9]+=0x00000001u;
goto P_0c04c902;
P_0c04c902: /* original 4200, guest PC 0x0c04c902 */
if(!s->budget--) { s->failed_pc=0x0c04c902u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c04c904;
P_0c04c904: /* original 2f22, guest PC 0x0c04c904 */
if(!s->budget--) { s->failed_pc=0x0c04c904u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04c906;
P_0c04c906: /* original 9313, guest PC 0x0c04c906 */
if(!s->budget--) { s->failed_pc=0x0c04c906u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c930u,2);
goto P_0c04c908;
P_0c04c908: /* original 3e3c, guest PC 0x0c04c908 */
if(!s->budget--) { s->failed_pc=0x0c04c908u; return 0; }
r[14]+=r[3];
goto P_0c04c90a;
P_0c04c90a: /* original e208, guest PC 0x0c04c90a */
if(!s->budget--) { s->failed_pc=0x0c04c90au; return 0; }
r[2]=0x00000008u;
goto P_0c04c90c;
P_0c04c90c: /* original 3923, guest PC 0x0c04c90c */
if(!s->budget--) { s->failed_pc=0x0c04c90cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[2])!=0);
goto P_0c04c90e;
P_0c04c90e: /* original 8b8d, guest PC 0x0c04c90e */
if(!s->budget--) { s->failed_pc=0x0c04c90eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04c82c; }
goto P_0c04c910;
P_0c04c910: /* original e000, guest PC 0x0c04c910 */
if(!s->budget--) { s->failed_pc=0x0c04c910u; return 0; }
r[0]=0x00000000u;
goto P_0c04c912;
P_0c04c912: /* original 7f14, guest PC 0x0c04c912 */
if(!s->budget--) { s->failed_pc=0x0c04c912u; return 0; }
r[15]+=0x00000014u;
goto P_0c04c914;
P_0c04c914: /* original 4f16, guest PC 0x0c04c914 */
if(!s->budget--) { s->failed_pc=0x0c04c914u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c916;
P_0c04c916: /* original 4f26, guest PC 0x0c04c916 */
if(!s->budget--) { s->failed_pc=0x0c04c916u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c918;
P_0c04c918: /* original 68f6, guest PC 0x0c04c918 */
if(!s->budget--) { s->failed_pc=0x0c04c918u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04c91a;
P_0c04c91a: /* original 69f6, guest PC 0x0c04c91a */
if(!s->budget--) { s->failed_pc=0x0c04c91au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04c91c;
P_0c04c91c: /* original 6af6, guest PC 0x0c04c91c */
if(!s->budget--) { s->failed_pc=0x0c04c91cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04c91e;
P_0c04c91e: /* original 6bf6, guest PC 0x0c04c91e */
if(!s->budget--) { s->failed_pc=0x0c04c91eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04c920;
P_0c04c920: /* original 6cf6, guest PC 0x0c04c920 */
if(!s->budget--) { s->failed_pc=0x0c04c920u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04c922;
P_0c04c922: /* original 6df6, guest PC 0x0c04c922 */
if(!s->budget--) { s->failed_pc=0x0c04c922u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04c924;
P_0c04c924: /* original 000b, guest PC 0x0c04c924 */
if(!s->budget--) { s->failed_pc=0x0c04c924u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c926: /* original 6ef6, guest PC 0x0c04c926 */
if(!s->budget--) { s->failed_pc=0x0c04c926u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04c928u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c928u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
