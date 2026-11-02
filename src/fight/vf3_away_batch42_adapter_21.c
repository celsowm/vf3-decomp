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
int vf3_away_batch42_adapter_21(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c9c1cu: goto P_0c0c9c1c;
case 0x0c0c9c1eu: goto P_0c0c9c1e;
case 0x0c0ca6c6u: goto P_0c0ca6c6;
case 0x0c0ca6c8u: goto P_0c0ca6c8;
case 0x0c0ca6cau: goto P_0c0ca6ca;
case 0x0c0ca6ccu: goto P_0c0ca6cc;
case 0x0c0ca6ceu: goto P_0c0ca6ce;
case 0x0c0ca6d0u: goto P_0c0ca6d0;
case 0x0c0ca6d2u: goto P_0c0ca6d2;
case 0x0c0ca6d4u: goto P_0c0ca6d4;
case 0x0c0ca6d6u: goto P_0c0ca6d6;
case 0x0c0ca6d8u: goto P_0c0ca6d8;
case 0x0c0ca6dau: goto P_0c0ca6da;
case 0x0c0ca6dcu: goto P_0c0ca6dc;
case 0x0c0ca6deu: goto P_0c0ca6de;
case 0x0c0ca6e0u: goto P_0c0ca6e0;
case 0x0c0ca6e2u: goto P_0c0ca6e2;
case 0x0c0ca6e4u: goto P_0c0ca6e4;
case 0x0c0ca6e6u: goto P_0c0ca6e6;
case 0x0c0ca6e8u: goto P_0c0ca6e8;
case 0x0c0ca6eau: goto P_0c0ca6ea;
case 0x0c0ca6ecu: goto P_0c0ca6ec;
case 0x0c0ca6eeu: goto P_0c0ca6ee;
case 0x0c0ca6f0u: goto P_0c0ca6f0;
case 0x0c0ca6f2u: goto P_0c0ca6f2;
case 0x0c0ca6f4u: goto P_0c0ca6f4;
case 0x0c0ca6f6u: goto P_0c0ca6f6;
case 0x0c0ca6f8u: goto P_0c0ca6f8;
case 0x0c0ca6fau: goto P_0c0ca6fa;
case 0x0c0ca6fcu: goto P_0c0ca6fc;
case 0x0c0ca6feu: goto P_0c0ca6fe;
case 0x0c0ca700u: goto P_0c0ca700;
case 0x0c0ca702u: goto P_0c0ca702;
case 0x0c0ca704u: goto P_0c0ca704;
case 0x0c0ca706u: goto P_0c0ca706;
case 0x0c0ca708u: goto P_0c0ca708;
case 0x0c0ca70au: goto P_0c0ca70a;
case 0x0c0ca70cu: goto P_0c0ca70c;
case 0x0c0ca70eu: goto P_0c0ca70e;
case 0x0c0ca710u: goto P_0c0ca710;
case 0x0c0ca712u: goto P_0c0ca712;
case 0x0c0ca714u: goto P_0c0ca714;
case 0x0c0ca716u: goto P_0c0ca716;
case 0x0c0ca718u: goto P_0c0ca718;
case 0x0c0ca71au: goto P_0c0ca71a;
case 0x0c0ca71cu: goto P_0c0ca71c;
case 0x0c0ca71eu: goto P_0c0ca71e;
case 0x0c0ca720u: goto P_0c0ca720;
case 0x0c0ca722u: goto P_0c0ca722;
case 0x0c0ca724u: goto P_0c0ca724;
case 0x0c0ca726u: goto P_0c0ca726;
case 0x0c0ca728u: goto P_0c0ca728;
case 0x0c0ca72au: goto P_0c0ca72a;
case 0x0c0ca72cu: goto P_0c0ca72c;
case 0x0c0ca72eu: goto P_0c0ca72e;
case 0x0c0ca730u: goto P_0c0ca730;
case 0x0c0ca732u: goto P_0c0ca732;
case 0x0c0ca734u: goto P_0c0ca734;
case 0x0c0ca736u: goto P_0c0ca736;
case 0x0c0ca738u: goto P_0c0ca738;
case 0x0c0ca73au: goto P_0c0ca73a;
case 0x0c0ca73cu: goto P_0c0ca73c;
case 0x0c0ca73eu: goto P_0c0ca73e;
case 0x0c0ca740u: goto P_0c0ca740;
case 0x0c0ca742u: goto P_0c0ca742;
case 0x0c0ca744u: goto P_0c0ca744;
case 0x0c0ca746u: goto P_0c0ca746;
case 0x0c0ca748u: goto P_0c0ca748;
case 0x0c0ca74au: goto P_0c0ca74a;
case 0x0c0ca74cu: goto P_0c0ca74c;
case 0x0c0ca74eu: goto P_0c0ca74e;
case 0x0c0ca750u: goto P_0c0ca750;
case 0x0c0ca752u: goto P_0c0ca752;
case 0x0c0ca754u: goto P_0c0ca754;
case 0x0c0ca756u: goto P_0c0ca756;
case 0x0c0ca758u: goto P_0c0ca758;
case 0x0c0ca75au: goto P_0c0ca75a;
case 0x0c0ca75cu: goto P_0c0ca75c;
case 0x0c0ca75eu: goto P_0c0ca75e;
case 0x0c0ca760u: goto P_0c0ca760;
case 0x0c0ca762u: goto P_0c0ca762;
case 0x0c0ca764u: goto P_0c0ca764;
case 0x0c0ca766u: goto P_0c0ca766;
case 0x0c0ca768u: goto P_0c0ca768;
case 0x0c0ca76au: goto P_0c0ca76a;
case 0x0c0ca76cu: goto P_0c0ca76c;
case 0x0c0ca76eu: goto P_0c0ca76e;
case 0x0c0ca770u: goto P_0c0ca770;
case 0x0c0ca772u: goto P_0c0ca772;
case 0x0c0ca774u: goto P_0c0ca774;
case 0x0c0ca776u: goto P_0c0ca776;
case 0x0c0ca778u: goto P_0c0ca778;
case 0x0c0ca77au: goto P_0c0ca77a;
case 0x0c0ca77cu: goto P_0c0ca77c;
case 0x0c0ca77eu: goto P_0c0ca77e;
case 0x0c0ca780u: goto P_0c0ca780;
case 0x0c0ca782u: goto P_0c0ca782;
case 0x0c0ca784u: goto P_0c0ca784;
case 0x0c0ca786u: goto P_0c0ca786;
case 0x0c0ca788u: goto P_0c0ca788;
case 0x0c0ca78au: goto P_0c0ca78a;
case 0x0c0ca78cu: goto P_0c0ca78c;
case 0x0c0ca78eu: goto P_0c0ca78e;
case 0x0c0ca790u: goto P_0c0ca790;
case 0x0c0ca792u: goto P_0c0ca792;
case 0x0c0ca794u: goto P_0c0ca794;
case 0x0c0ca796u: goto P_0c0ca796;
case 0x0c0ca798u: goto P_0c0ca798;
case 0x0c0ca79au: goto P_0c0ca79a;
case 0x0c0ca79cu: goto P_0c0ca79c;
case 0x0c0ca79eu: goto P_0c0ca79e;
case 0x0c0ca7a0u: goto P_0c0ca7a0;
case 0x0c0ca7a2u: goto P_0c0ca7a2;
case 0x0c0ca7a4u: goto P_0c0ca7a4;
case 0x0c0ca7a6u: goto P_0c0ca7a6;
case 0x0c0ca7a8u: goto P_0c0ca7a8;
case 0x0c0ca7aau: goto P_0c0ca7aa;
case 0x0c0ca7acu: goto P_0c0ca7ac;
case 0x0c0ca7aeu: goto P_0c0ca7ae;
case 0x0c0ca7b0u: goto P_0c0ca7b0;
case 0x0c0ca7dcu: goto P_0c0ca7dc;
case 0x0c0ca7deu: goto P_0c0ca7de;
case 0x0c0ca7e0u: goto P_0c0ca7e0;
case 0x0c0ca7e2u: goto P_0c0ca7e2;
case 0x0c0ca7e4u: goto P_0c0ca7e4;
case 0x0c0ca7e6u: goto P_0c0ca7e6;
case 0x0c0ca7e8u: goto P_0c0ca7e8;
case 0x0c0ca7eau: goto P_0c0ca7ea;
case 0x0c0ca7ecu: goto P_0c0ca7ec;
case 0x0c0ca7eeu: goto P_0c0ca7ee;
case 0x0c0ca7f0u: goto P_0c0ca7f0;
case 0x0c0ca7f2u: goto P_0c0ca7f2;
case 0x0c0ca7f4u: goto P_0c0ca7f4;
case 0x0c0ca7f6u: goto P_0c0ca7f6;
case 0x0c0ca7f8u: goto P_0c0ca7f8;
case 0x0c0ca7fau: goto P_0c0ca7fa;
case 0x0c0ca7fcu: goto P_0c0ca7fc;
case 0x0c0ca7feu: goto P_0c0ca7fe;
case 0x0c0ca800u: goto P_0c0ca800;
case 0x0c0ca802u: goto P_0c0ca802;
case 0x0c0ca804u: goto P_0c0ca804;
case 0x0c0ca806u: goto P_0c0ca806;
case 0x0c0ca808u: goto P_0c0ca808;
case 0x0c0ca80au: goto P_0c0ca80a;
case 0x0c0ca80cu: goto P_0c0ca80c;
case 0x0c0ca80eu: goto P_0c0ca80e;
case 0x0c0ca810u: goto P_0c0ca810;
case 0x0c0ca812u: goto P_0c0ca812;
case 0x0c0ca814u: goto P_0c0ca814;
case 0x0c0ca816u: goto P_0c0ca816;
case 0x0c0ca818u: goto P_0c0ca818;
case 0x0c0ca81au: goto P_0c0ca81a;
case 0x0c0ca81cu: goto P_0c0ca81c;
case 0x0c0ca81eu: goto P_0c0ca81e;
case 0x0c0ca820u: goto P_0c0ca820;
case 0x0c0ca822u: goto P_0c0ca822;
case 0x0c0ca824u: goto P_0c0ca824;
case 0x0c0ca826u: goto P_0c0ca826;
case 0x0c0ca828u: goto P_0c0ca828;
case 0x0c0ca82au: goto P_0c0ca82a;
case 0x0c0ca82cu: goto P_0c0ca82c;
case 0x0c0ca82eu: goto P_0c0ca82e;
case 0x0c0ca830u: goto P_0c0ca830;
case 0x0c0ca832u: goto P_0c0ca832;
case 0x0c0ca834u: goto P_0c0ca834;
case 0x0c0ca836u: goto P_0c0ca836;
case 0x0c0caa9cu: goto P_0c0caa9c;
case 0x0c0caa9eu: goto P_0c0caa9e;
case 0x0c0caaa0u: goto P_0c0caaa0;
case 0x0c0caaa2u: goto P_0c0caaa2;
case 0x0c0caaa4u: goto P_0c0caaa4;
case 0x0c0caaa6u: goto P_0c0caaa6;
case 0x0c0caaa8u: goto P_0c0caaa8;
case 0x0c0caaaau: goto P_0c0caaaa;
case 0x0c0caaacu: goto P_0c0caaac;
case 0x0c0caaaeu: goto P_0c0caaae;
case 0x0c0caab0u: goto P_0c0caab0;
case 0x0c0caab2u: goto P_0c0caab2;
case 0x0c0caab4u: goto P_0c0caab4;
case 0x0c0caab6u: goto P_0c0caab6;
case 0x0c0caab8u: goto P_0c0caab8;
case 0x0c0caabau: goto P_0c0caaba;
case 0x0c0caabcu: goto P_0c0caabc;
case 0x0c0caabeu: goto P_0c0caabe;
case 0x0c0caac0u: goto P_0c0caac0;
case 0x0c0caac2u: goto P_0c0caac2;
case 0x0c0caac4u: goto P_0c0caac4;
case 0x0c0caac6u: goto P_0c0caac6;
case 0x0c0caac8u: goto P_0c0caac8;
case 0x0c0caacau: goto P_0c0caaca;
case 0x0c0caaccu: goto P_0c0caacc;
case 0x0c0caaceu: goto P_0c0caace;
case 0x0c0caad0u: goto P_0c0caad0;
case 0x0c0caad2u: goto P_0c0caad2;
case 0x0c0caad4u: goto P_0c0caad4;
case 0x0c0caad6u: goto P_0c0caad6;
case 0x0c0caad8u: goto P_0c0caad8;
case 0x0c0caadau: goto P_0c0caada;
case 0x0c0caadcu: goto P_0c0caadc;
case 0x0c0caadeu: goto P_0c0caade;
case 0x0c0caae0u: goto P_0c0caae0;
case 0x0c0caae2u: goto P_0c0caae2;
case 0x0c0caae4u: goto P_0c0caae4;
case 0x0c0caae6u: goto P_0c0caae6;
case 0x0c0caae8u: goto P_0c0caae8;
case 0x0c0caaeau: goto P_0c0caaea;
case 0x0c0caaecu: goto P_0c0caaec;
case 0x0c0caaeeu: goto P_0c0caaee;
case 0x0c0caaf0u: goto P_0c0caaf0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c9c1c: /* original 000b, guest PC 0x0c0c9c1c */
if(!s->budget--) { s->failed_pc=0x0c0c9c1cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9c1e: /* original 0009, guest PC 0x0c0c9c1e */
if(!s->budget--) { s->failed_pc=0x0c0c9c1eu; return 0; }
if(!vf3_matrix_family(0x0c0c9c20u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9c20u; return 0; } return 1;
P_0c0ca6c6: /* original 2fe6, guest PC 0x0c0ca6c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca6c6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6c8;
P_0c0ca6c8: /* original 6e43, guest PC 0x0c0ca6c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca6c8u; return 0; }
r[14]=r[4];
goto P_0c0ca6ca;
P_0c0ca6ca: /* original 2fd6, guest PC 0x0c0ca6ca */
if(!s->budget--) { s->failed_pc=0x0c0ca6cau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6cc;
P_0c0ca6cc: /* original 2fc6, guest PC 0x0c0ca6cc */
if(!s->budget--) { s->failed_pc=0x0c0ca6ccu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6ce;
P_0c0ca6ce: /* original 2fb6, guest PC 0x0c0ca6ce */
if(!s->budget--) { s->failed_pc=0x0c0ca6ceu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6d0;
P_0c0ca6d0: /* original 2fa6, guest PC 0x0c0ca6d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6d2;
P_0c0ca6d2: /* original 2f96, guest PC 0x0c0ca6d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6d4;
P_0c0ca6d4: /* original 2f86, guest PC 0x0c0ca6d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca6d6;
P_0c0ca6d6: /* original fffb, guest PC 0x0c0ca6d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ca6d8;
P_0c0ca6d8: /* original ffeb, guest PC 0x0c0ca6d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca6d8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0ca6da;
P_0c0ca6da: /* original ffdb, guest PC 0x0c0ca6da */
if(!s->budget--) { s->failed_pc=0x0c0ca6dau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0ca6dc;
P_0c0ca6dc: /* original ffcb, guest PC 0x0c0ca6dc */
if(!s->budget--) { s->failed_pc=0x0c0ca6dcu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0ca6de;
P_0c0ca6de: /* original 4f22, guest PC 0x0c0ca6de */
if(!s->budget--) { s->failed_pc=0x0c0ca6deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca6e0;
P_0c0ca6e0: /* original 9067, guest PC 0x0c0ca6e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b2u,2);
goto P_0c0ca6e2;
P_0c0ca6e2: /* original db37, guest PC 0x0c0ca6e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e2u; return 0; }
r[11]=read(ram,0x0c0ca7c0u,4);
goto P_0c0ca6e4;
P_0c0ca6e4: /* original 7ff0, guest PC 0x0c0ca6e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e4u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0ca6e6;
P_0c0ca6e6: /* original f5e6, guest PC 0x0c0ca6e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e6u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ca6e8;
P_0c0ca6e8: /* original 64f3, guest PC 0x0c0ca6e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca6e8u; return 0; }
r[4]=r[15];
goto P_0c0ca6ea;
P_0c0ca6ea: /* original 70f8, guest PC 0x0c0ca6ea */
if(!s->budget--) { s->failed_pc=0x0c0ca6eau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0ca6ec;
P_0c0ca6ec: /* original 7404, guest PC 0x0c0ca6ec */
if(!s->budget--) { s->failed_pc=0x0c0ca6ecu; return 0; }
r[4]+=0x00000004u;
goto P_0c0ca6ee;
P_0c0ca6ee: /* original 4b0b, guest PC 0x0c0ca6ee */
if(!s->budget--) { s->failed_pc=0x0c0ca6eeu; return 0; }
target=r[11];
r[16]=code_base|0x0c0ca6f2u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca6f2u) { target=s->pc; goto dispatch; }
goto P_0c0ca6f2;
P_0c0ca6f0: /* original f4e6, guest PC 0x0c0ca6f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0ca6f2;
P_0c0ca6f2: /* original 6403, guest PC 0x0c0ca6f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f2u; return 0; }
r[4]=r[0];
goto P_0c0ca6f4;
P_0c0ca6f4: /* original 905e, guest PC 0x0c0ca6f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b4u,2);
goto P_0c0ca6f6;
P_0c0ca6f6: /* original 0e46, guest PC 0x0c0ca6f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0ca6f8;
P_0c0ca6f8: /* original e004, guest PC 0x0c0ca6f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca6f8u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca6fa;
P_0c0ca6fa: /* original fff6, guest PC 0x0c0ca6fa */
if(!s->budget--) { s->failed_pc=0x0c0ca6fau; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0ca6fc;
P_0c0ca6fc: /* original e008, guest PC 0x0c0ca6fc */
if(!s->budget--) { s->failed_pc=0x0c0ca6fcu; return 0; }
r[0]=0x00000008u;
goto P_0c0ca6fe;
P_0c0ca6fe: /* original fdf6, guest PC 0x0c0ca6fe */
if(!s->budget--) { s->failed_pc=0x0c0ca6feu; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0ca700;
P_0c0ca700: /* original e00c, guest PC 0x0c0ca700 */
if(!s->budget--) { s->failed_pc=0x0c0ca700u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca702;
P_0c0ca702: /* original d330, guest PC 0x0c0ca702 */
if(!s->budget--) { s->failed_pc=0x0c0ca702u; return 0; }
r[3]=read(ram,0x0c0ca7c4u,4);
goto P_0c0ca704;
P_0c0ca704: /* original e40f, guest PC 0x0c0ca704 */
if(!s->budget--) { s->failed_pc=0x0c0ca704u; return 0; }
r[4]=0x0000000fu;
goto P_0c0ca706;
P_0c0ca706: /* original fef6, guest PC 0x0c0ca706 */
if(!s->budget--) { s->failed_pc=0x0c0ca706u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0ca708;
P_0c0ca708: /* original 6030, guest PC 0x0c0ca708 */
if(!s->budget--) { s->failed_pc=0x0c0ca708u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0ca70a;
P_0c0ca70a: /* original d52f, guest PC 0x0c0ca70a */
if(!s->budget--) { s->failed_pc=0x0c0ca70au; return 0; }
r[5]=read(ram,0x0c0ca7c8u,4);
goto P_0c0ca70c;
P_0c0ca70c: /* original 600c, guest PC 0x0c0ca70c */
if(!s->budget--) { s->failed_pc=0x0c0ca70cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ca70e;
P_0c0ca70e: /* original fe4d, guest PC 0x0c0ca70e */
if(!s->budget--) { s->failed_pc=0x0c0ca70eu; return 0; }
fr[14]^=0x80000000u;
goto P_0c0ca710;
P_0c0ca710: /* original 2409, guest PC 0x0c0ca710 */
if(!s->budget--) { s->failed_pc=0x0c0ca710u; return 0; }
r[4]&=r[0];
goto P_0c0ca712;
P_0c0ca712: /* original 6043, guest PC 0x0c0ca712 */
if(!s->budget--) { s->failed_pc=0x0c0ca712u; return 0; }
r[0]=r[4];
goto P_0c0ca714;
P_0c0ca714: /* original 880f, guest PC 0x0c0ca714 */
if(!s->budget--) { s->failed_pc=0x0c0ca714u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0ca716;
P_0c0ca716: /* original 8d3e, guest PC 0x0c0ca716 */
if(!s->budget--) { s->failed_pc=0x0c0ca716u; return 0; }
cond=r[17]&1u;
r[6]=0x0000000du;
if(cond) { goto P_0c0ca796; }
goto P_0c0ca71a;
P_0c0ca718: /* original e60d, guest PC 0x0c0ca718 */
if(!s->budget--) { s->failed_pc=0x0c0ca718u; return 0; }
r[6]=0x0000000du;
goto P_0c0ca71a;
P_0c0ca71a: /* original 904c, guest PC 0x0c0ca71a */
if(!s->budget--) { s->failed_pc=0x0c0ca71au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b6u,2);
goto P_0c0ca71c;
P_0c0ca71c: /* original 994c, guest PC 0x0c0ca71c */
if(!s->budget--) { s->failed_pc=0x0c0ca71cu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b8u,2);
goto P_0c0ca71e;
P_0c0ca71e: /* original 07ee, guest PC 0x0c0ca71e */
if(!s->budget--) { s->failed_pc=0x0c0ca71eu; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0ca720;
P_0c0ca720: /* original 6043, guest PC 0x0c0ca720 */
if(!s->budget--) { s->failed_pc=0x0c0ca720u; return 0; }
r[0]=r[4];
goto P_0c0ca722;
P_0c0ca722: /* original 8804, guest PC 0x0c0ca722 */
if(!s->budget--) { s->failed_pc=0x0c0ca722u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0ca724;
P_0c0ca724: /* original 6a73, guest PC 0x0c0ca724 */
if(!s->budget--) { s->failed_pc=0x0c0ca724u; return 0; }
r[10]=r[7];
goto P_0c0ca726;
P_0c0ca726: /* original 6873, guest PC 0x0c0ca726 */
if(!s->budget--) { s->failed_pc=0x0c0ca726u; return 0; }
r[8]=r[7];
goto P_0c0ca728;
P_0c0ca728: /* original 7a08, guest PC 0x0c0ca728 */
if(!s->budget--) { s->failed_pc=0x0c0ca728u; return 0; }
r[10]+=0x00000008u;
goto P_0c0ca72a;
P_0c0ca72a: /* original 8d03, guest PC 0x0c0ca72a */
if(!s->budget--) { s->failed_pc=0x0c0ca72au; return 0; }
cond=r[17]&1u;
r[9]+=r[14];
if(cond) { goto P_0c0ca734; }
goto P_0c0ca72e;
P_0c0ca72c: /* original 39ec, guest PC 0x0c0ca72c */
if(!s->budget--) { s->failed_pc=0x0c0ca72cu; return 0; }
r[9]+=r[14];
goto P_0c0ca72e;
P_0c0ca72e: /* original 6043, guest PC 0x0c0ca72e */
if(!s->budget--) { s->failed_pc=0x0c0ca72eu; return 0; }
r[0]=r[4];
goto P_0c0ca730;
P_0c0ca730: /* original 8801, guest PC 0x0c0ca730 */
if(!s->budget--) { s->failed_pc=0x0c0ca730u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ca732;
P_0c0ca732: /* original 8b05, guest PC 0x0c0ca732 */
if(!s->budget--) { s->failed_pc=0x0c0ca732u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca740; }
goto P_0c0ca734;
P_0c0ca734: /* original d325, guest PC 0x0c0ca734 */
if(!s->budget--) { s->failed_pc=0x0c0ca734u; return 0; }
r[3]=read(ram,0x0c0ca7ccu,4);
goto P_0c0ca736;
P_0c0ca736: /* original c726, guest PC 0x0c0ca736 */
if(!s->budget--) { s->failed_pc=0x0c0ca736u; return 0; }
r[0]=code_base|0x000ca7d0u;
goto P_0c0ca738;
P_0c0ca738: /* original ed07, guest PC 0x0c0ca738 */
if(!s->budget--) { s->failed_pc=0x0c0ca738u; return 0; }
r[13]=0x00000007u;
goto P_0c0ca73a;
P_0c0ca73a: /* original 2f32, guest PC 0x0c0ca73a */
if(!s->budget--) { s->failed_pc=0x0c0ca73au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ca73c;
P_0c0ca73c: /* original a004, guest PC 0x0c0ca73c */
if(!s->budget--) { s->failed_pc=0x0c0ca73cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ca748;
P_0c0ca73e: /* original f408, guest PC 0x0c0ca73e */
if(!s->budget--) { s->failed_pc=0x0c0ca73eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ca740;
P_0c0ca740: /* original c724, guest PC 0x0c0ca740 */
if(!s->budget--) { s->failed_pc=0x0c0ca740u; return 0; }
r[0]=code_base|0x000ca7d4u;
goto P_0c0ca742;
P_0c0ca742: /* original 6d63, guest PC 0x0c0ca742 */
if(!s->budget--) { s->failed_pc=0x0c0ca742u; return 0; }
r[13]=r[6];
goto P_0c0ca744;
P_0c0ca744: /* original 2f52, guest PC 0x0c0ca744 */
if(!s->budget--) { s->failed_pc=0x0c0ca744u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ca746;
P_0c0ca746: /* original f408, guest PC 0x0c0ca746 */
if(!s->budget--) { s->failed_pc=0x0c0ca746u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ca748;
P_0c0ca748: /* original a01f, guest PC 0x0c0ca748 */
if(!s->budget--) { s->failed_pc=0x0c0ca748u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0ca78a;
P_0c0ca74a: /* original fc4c, guest PC 0x0c0ca74a */
if(!s->budget--) { s->failed_pc=0x0c0ca74au; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0ca74c;
P_0c0ca74c: /* original 6cf2, guest PC 0x0c0ca74c */
if(!s->budget--) { s->failed_pc=0x0c0ca74cu; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c0ca74e;
P_0c0ca74e: /* original 7c01, guest PC 0x0c0ca74e */
if(!s->budget--) { s->failed_pc=0x0c0ca74eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0ca750;
P_0c0ca750: /* original 2fc2, guest PC 0x0c0ca750 */
if(!s->budget--) { s->failed_pc=0x0c0ca750u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0ca752;
P_0c0ca752: /* original 7cff, guest PC 0x0c0ca752 */
if(!s->budget--) { s->failed_pc=0x0c0ca752u; return 0; }
r[12]+=0xffffffffu;
goto P_0c0ca754;
P_0c0ca754: /* original 6cc0, guest PC 0x0c0ca754 */
if(!s->budget--) { s->failed_pc=0x0c0ca754u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]=tmp;
goto P_0c0ca756;
P_0c0ca756: /* original 65c3, guest PC 0x0c0ca756 */
if(!s->budget--) { s->failed_pc=0x0c0ca756u; return 0; }
r[5]=r[12];
goto P_0c0ca758;
P_0c0ca758: /* original 4500, guest PC 0x0c0ca758 */
if(!s->budget--) { s->failed_pc=0x0c0ca758u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0ca75a;
P_0c0ca75a: /* original 63c3, guest PC 0x0c0ca75a */
if(!s->budget--) { s->failed_pc=0x0c0ca75au; return 0; }
r[3]=r[12];
goto P_0c0ca75c;
P_0c0ca75c: /* original 353c, guest PC 0x0c0ca75c */
if(!s->budget--) { s->failed_pc=0x0c0ca75cu; return 0; }
r[5]+=r[3];
goto P_0c0ca75e;
P_0c0ca75e: /* original 4508, guest PC 0x0c0ca75e */
if(!s->budget--) { s->failed_pc=0x0c0ca75eu; return 0; }
r[5]<<=2;
goto P_0c0ca760;
P_0c0ca760: /* original 6053, guest PC 0x0c0ca760 */
if(!s->budget--) { s->failed_pc=0x0c0ca760u; return 0; }
r[0]=r[5];
goto P_0c0ca762;
P_0c0ca762: /* original f486, guest PC 0x0c0ca762 */
if(!s->budget--) { s->failed_pc=0x0c0ca762u; return 0; }
vf3_matrix_load(s,ram,4,r[8]+r[0]);
goto P_0c0ca764;
P_0c0ca764: /* original f5a6, guest PC 0x0c0ca764 */
if(!s->budget--) { s->failed_pc=0x0c0ca764u; return 0; }
vf3_matrix_load(s,ram,5,r[10]+r[0]);
goto P_0c0ca766;
P_0c0ca766: /* original 6453, guest PC 0x0c0ca766 */
if(!s->budget--) { s->failed_pc=0x0c0ca766u; return 0; }
r[4]=r[5];
goto P_0c0ca768;
P_0c0ca768: /* original 64f3, guest PC 0x0c0ca768 */
if(!s->budget--) { s->failed_pc=0x0c0ca768u; return 0; }
r[4]=r[15];
goto P_0c0ca76a;
P_0c0ca76a: /* original 4b0b, guest PC 0x0c0ca76a */
if(!s->budget--) { s->failed_pc=0x0c0ca76au; return 0; }
target=r[11];
r[16]=code_base|0x0c0ca76eu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca76eu) { target=s->pc; goto dispatch; }
goto P_0c0ca76e;
P_0c0ca76c: /* original 7404, guest PC 0x0c0ca76c */
if(!s->budget--) { s->failed_pc=0x0c0ca76cu; return 0; }
r[4]+=0x00000004u;
goto P_0c0ca76e;
P_0c0ca76e: /* original 6403, guest PC 0x0c0ca76e */
if(!s->budget--) { s->failed_pc=0x0c0ca76eu; return 0; }
r[4]=r[0];
goto P_0c0ca770;
P_0c0ca770: /* original e004, guest PC 0x0c0ca770 */
if(!s->budget--) { s->failed_pc=0x0c0ca770u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca772;
P_0c0ca772: /* original f3f6, guest PC 0x0c0ca772 */
if(!s->budget--) { s->failed_pc=0x0c0ca772u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca774;
P_0c0ca774: /* original e008, guest PC 0x0c0ca774 */
if(!s->budget--) { s->failed_pc=0x0c0ca774u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca776;
P_0c0ca776: /* original 7dff, guest PC 0x0c0ca776 */
if(!s->budget--) { s->failed_pc=0x0c0ca776u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0ca778;
P_0c0ca778: /* original ff30, guest PC 0x0c0ca778 */
if(!s->budget--) { s->failed_pc=0x0c0ca778u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0ca77a;
P_0c0ca77a: /* original f3f6, guest PC 0x0c0ca77a */
if(!s->budget--) { s->failed_pc=0x0c0ca77au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca77c;
P_0c0ca77c: /* original e00c, guest PC 0x0c0ca77c */
if(!s->budget--) { s->failed_pc=0x0c0ca77cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca77e;
P_0c0ca77e: /* original fd30, guest PC 0x0c0ca77e */
if(!s->budget--) { s->failed_pc=0x0c0ca77eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c0ca780;
P_0c0ca780: /* original f3f6, guest PC 0x0c0ca780 */
if(!s->budget--) { s->failed_pc=0x0c0ca780u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca782;
P_0c0ca782: /* original 60c3, guest PC 0x0c0ca782 */
if(!s->budget--) { s->failed_pc=0x0c0ca782u; return 0; }
r[0]=r[12];
goto P_0c0ca784;
P_0c0ca784: /* original 4008, guest PC 0x0c0ca784 */
if(!s->budget--) { s->failed_pc=0x0c0ca784u; return 0; }
r[0]<<=2;
goto P_0c0ca786;
P_0c0ca786: /* original fe31, guest PC 0x0c0ca786 */
if(!s->budget--) { s->failed_pc=0x0c0ca786u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0ca788;
P_0c0ca788: /* original 0946, guest PC 0x0c0ca788 */
if(!s->budget--) { s->failed_pc=0x0c0ca788u; return 0; }
write(ram,r[9]+r[0],r[4],4);
goto P_0c0ca78a;
P_0c0ca78a: /* original 2dd8, guest PC 0x0c0ca78a */
if(!s->budget--) { s->failed_pc=0x0c0ca78au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0ca78c;
P_0c0ca78c: /* original 8bde, guest PC 0x0c0ca78c */
if(!s->budget--) { s->failed_pc=0x0c0ca78cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca74c; }
goto P_0c0ca78e;
P_0c0ca78e: /* original fdc2, guest PC 0x0c0ca78e */
if(!s->budget--) { s->failed_pc=0x0c0ca78eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[12],r[18],'*');
goto P_0c0ca790;
P_0c0ca790: /* original ffc2, guest PC 0x0c0ca790 */
if(!s->budget--) { s->failed_pc=0x0c0ca790u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0ca792;
P_0c0ca792: /* original a03d, guest PC 0x0c0ca792 */
if(!s->budget--) { s->failed_pc=0x0c0ca792u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[12],r[18],'*');
goto P_0c0ca810;
P_0c0ca794: /* original fec2, guest PC 0x0c0ca794 */
if(!s->budget--) { s->failed_pc=0x0c0ca794u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[12],r[18],'*');
goto P_0c0ca796;
P_0c0ca796: /* original 900e, guest PC 0x0c0ca796 */
if(!s->budget--) { s->failed_pc=0x0c0ca796u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b6u,2);
goto P_0c0ca798;
P_0c0ca798: /* original 6a53, guest PC 0x0c0ca798 */
if(!s->budget--) { s->failed_pc=0x0c0ca798u; return 0; }
r[10]=r[5];
goto P_0c0ca79a;
P_0c0ca79a: /* original 990d, guest PC 0x0c0ca79a */
if(!s->budget--) { s->failed_pc=0x0c0ca79au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7b8u,2);
goto P_0c0ca79c;
P_0c0ca79c: /* original 04ee, guest PC 0x0c0ca79c */
if(!s->budget--) { s->failed_pc=0x0c0ca79cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ca79e;
P_0c0ca79e: /* original c70e, guest PC 0x0c0ca79e */
if(!s->budget--) { s->failed_pc=0x0c0ca79eu; return 0; }
r[0]=code_base|0x000ca7d8u;
goto P_0c0ca7a0;
P_0c0ca7a0: /* original 9b0b, guest PC 0x0c0ca7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a0u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca7bau,2);
goto P_0c0ca7a2;
P_0c0ca7a2: /* original 39ec, guest PC 0x0c0ca7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a2u; return 0; }
r[9]+=r[14];
goto P_0c0ca7a4;
P_0c0ca7a4: /* original 6843, guest PC 0x0c0ca7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a4u; return 0; }
r[8]=r[4];
goto P_0c0ca7a6;
P_0c0ca7a6: /* original f608, guest PC 0x0c0ca7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a6u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0ca7a8;
P_0c0ca7a8: /* original 7808, guest PC 0x0c0ca7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ca7a8u; return 0; }
r[8]+=0x00000008u;
goto P_0c0ca7aa;
P_0c0ca7aa: /* original 67b3, guest PC 0x0c0ca7aa */
if(!s->budget--) { s->failed_pc=0x0c0ca7aau; return 0; }
r[7]=r[11];
goto P_0c0ca7ac;
P_0c0ca7ac: /* original 6d43, guest PC 0x0c0ca7ac */
if(!s->budget--) { s->failed_pc=0x0c0ca7acu; return 0; }
r[13]=r[4];
goto P_0c0ca7ae;
P_0c0ca7ae: /* original a02d, guest PC 0x0c0ca7ae */
if(!s->budget--) { s->failed_pc=0x0c0ca7aeu; return 0; }
r[7]+=0xfffffffcu;
goto P_0c0ca80c;
P_0c0ca7b0: /* original 77fc, guest PC 0x0c0ca7b0 */
if(!s->budget--) { s->failed_pc=0x0c0ca7b0u; return 0; }
r[7]+=0xfffffffcu;
if(!vf3_matrix_family(0x0c0ca7b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca7b2u; return 0; } return 1;
P_0c0ca7dc: /* original 65a4, guest PC 0x0c0ca7dc */
if(!s->budget--) { s->failed_pc=0x0c0ca7dcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[10]+=1;
r[5]=tmp;
goto P_0c0ca7de;
P_0c0ca7de: /* original 6453, guest PC 0x0c0ca7de */
if(!s->budget--) { s->failed_pc=0x0c0ca7deu; return 0; }
r[4]=r[5];
goto P_0c0ca7e0;
P_0c0ca7e0: /* original 4400, guest PC 0x0c0ca7e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0ca7e2;
P_0c0ca7e2: /* original 6353, guest PC 0x0c0ca7e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e2u; return 0; }
r[3]=r[5];
goto P_0c0ca7e4;
P_0c0ca7e4: /* original 343c, guest PC 0x0c0ca7e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e4u; return 0; }
r[4]+=r[3];
goto P_0c0ca7e6;
P_0c0ca7e6: /* original 4408, guest PC 0x0c0ca7e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e6u; return 0; }
r[4]<<=2;
goto P_0c0ca7e8;
P_0c0ca7e8: /* original 6043, guest PC 0x0c0ca7e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca7e8u; return 0; }
r[0]=r[4];
goto P_0c0ca7ea;
P_0c0ca7ea: /* original f4d6, guest PC 0x0c0ca7ea */
if(!s->budget--) { s->failed_pc=0x0c0ca7eau; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0ca7ec;
P_0c0ca7ec: /* original f586, guest PC 0x0c0ca7ec */
if(!s->budget--) { s->failed_pc=0x0c0ca7ecu; return 0; }
vf3_matrix_load(s,ram,5,r[8]+r[0]);
goto P_0c0ca7ee;
P_0c0ca7ee: /* original 6c43, guest PC 0x0c0ca7ee */
if(!s->budget--) { s->failed_pc=0x0c0ca7eeu; return 0; }
r[12]=r[4];
goto P_0c0ca7f0;
P_0c0ca7f0: /* original f74c, guest PC 0x0c0ca7f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f0u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0ca7f2;
P_0c0ca7f2: /* original f742, guest PC 0x0c0ca7f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0ca7f4;
P_0c0ca7f4: /* original f05c, guest PC 0x0c0ca7f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0ca7f6;
P_0c0ca7f6: /* original f46c, guest PC 0x0c0ca7f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f6u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0ca7f8;
P_0c0ca7f8: /* original f75e, guest PC 0x0c0ca7f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca7f8u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[5],fr[7],r[18]);
goto P_0c0ca7fa;
P_0c0ca7fa: /* original f57c, guest PC 0x0c0ca7fa */
if(!s->budget--) { s->failed_pc=0x0c0ca7fau; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0ca7fc;
P_0c0ca7fc: /* original f545, guest PC 0x0c0ca7fc */
if(!s->budget--) { s->failed_pc=0x0c0ca7fcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0ca7fe;
P_0c0ca7fe: /* original 8d01, guest PC 0x0c0ca7fe */
if(!s->budget--) { s->failed_pc=0x0c0ca7feu; return 0; }
cond=r[17]&1u;
r[4]=r[7];
if(cond) { goto P_0c0ca804; }
goto P_0c0ca802;
P_0c0ca800: /* original 6473, guest PC 0x0c0ca800 */
if(!s->budget--) { s->failed_pc=0x0c0ca800u; return 0; }
r[4]=r[7];
goto P_0c0ca802;
P_0c0ca802: /* original 64b3, guest PC 0x0c0ca802 */
if(!s->budget--) { s->failed_pc=0x0c0ca802u; return 0; }
r[4]=r[11];
goto P_0c0ca804;
P_0c0ca804: /* original 6053, guest PC 0x0c0ca804 */
if(!s->budget--) { s->failed_pc=0x0c0ca804u; return 0; }
r[0]=r[5];
goto P_0c0ca806;
P_0c0ca806: /* original 4008, guest PC 0x0c0ca806 */
if(!s->budget--) { s->failed_pc=0x0c0ca806u; return 0; }
r[0]<<=2;
goto P_0c0ca808;
P_0c0ca808: /* original 76ff, guest PC 0x0c0ca808 */
if(!s->budget--) { s->failed_pc=0x0c0ca808u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0ca80a;
P_0c0ca80a: /* original 0946, guest PC 0x0c0ca80a */
if(!s->budget--) { s->failed_pc=0x0c0ca80au; return 0; }
write(ram,r[9]+r[0],r[4],4);
goto P_0c0ca80c;
P_0c0ca80c: /* original 2668, guest PC 0x0c0ca80c */
if(!s->budget--) { s->failed_pc=0x0c0ca80cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ca80e;
P_0c0ca80e: /* original 8be5, guest PC 0x0c0ca80e */
if(!s->budget--) { s->failed_pc=0x0c0ca80eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca7dc; }
goto P_0c0ca810;
P_0c0ca810: /* original 7f10, guest PC 0x0c0ca810 */
if(!s->budget--) { s->failed_pc=0x0c0ca810u; return 0; }
r[15]+=0x00000010u;
goto P_0c0ca812;
P_0c0ca812: /* original 9078, guest PC 0x0c0ca812 */
if(!s->budget--) { s->failed_pc=0x0c0ca812u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca906u,2);
goto P_0c0ca814;
P_0c0ca814: /* original 4f26, guest PC 0x0c0ca814 */
if(!s->budget--) { s->failed_pc=0x0c0ca814u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca816;
P_0c0ca816: /* original fef7, guest PC 0x0c0ca816 */
if(!s->budget--) { s->failed_pc=0x0c0ca816u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0ca818;
P_0c0ca818: /* original 7004, guest PC 0x0c0ca818 */
if(!s->budget--) { s->failed_pc=0x0c0ca818u; return 0; }
r[0]+=0x00000004u;
goto P_0c0ca81a;
P_0c0ca81a: /* original fed7, guest PC 0x0c0ca81a */
if(!s->budget--) { s->failed_pc=0x0c0ca81au; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c0ca81c;
P_0c0ca81c: /* original 7004, guest PC 0x0c0ca81c */
if(!s->budget--) { s->failed_pc=0x0c0ca81cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0ca81e;
P_0c0ca81e: /* original fee7, guest PC 0x0c0ca81e */
if(!s->budget--) { s->failed_pc=0x0c0ca81eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0ca820;
P_0c0ca820: /* original fcf9, guest PC 0x0c0ca820 */
if(!s->budget--) { s->failed_pc=0x0c0ca820u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca822;
P_0c0ca822: /* original fdf9, guest PC 0x0c0ca822 */
if(!s->budget--) { s->failed_pc=0x0c0ca822u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca824;
P_0c0ca824: /* original fef9, guest PC 0x0c0ca824 */
if(!s->budget--) { s->failed_pc=0x0c0ca824u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca826;
P_0c0ca826: /* original fff9, guest PC 0x0c0ca826 */
if(!s->budget--) { s->failed_pc=0x0c0ca826u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca828;
P_0c0ca828: /* original 68f6, guest PC 0x0c0ca828 */
if(!s->budget--) { s->failed_pc=0x0c0ca828u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0ca82a;
P_0c0ca82a: /* original 69f6, guest PC 0x0c0ca82a */
if(!s->budget--) { s->failed_pc=0x0c0ca82au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ca82c;
P_0c0ca82c: /* original 6af6, guest PC 0x0c0ca82c */
if(!s->budget--) { s->failed_pc=0x0c0ca82cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ca82e;
P_0c0ca82e: /* original 6bf6, guest PC 0x0c0ca82e */
if(!s->budget--) { s->failed_pc=0x0c0ca82eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ca830;
P_0c0ca830: /* original 6cf6, guest PC 0x0c0ca830 */
if(!s->budget--) { s->failed_pc=0x0c0ca830u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ca832;
P_0c0ca832: /* original 6df6, guest PC 0x0c0ca832 */
if(!s->budget--) { s->failed_pc=0x0c0ca832u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ca834;
P_0c0ca834: /* original 000b, guest PC 0x0c0ca834 */
if(!s->budget--) { s->failed_pc=0x0c0ca834u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ca836: /* original 6ef6, guest PC 0x0c0ca836 */
if(!s->budget--) { s->failed_pc=0x0c0ca836u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ca838u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca838u; return 0; } return 1;
P_0c0caa9c: /* original 903d, guest PC 0x0c0caa9c */
if(!s->budget--) { s->failed_pc=0x0c0caa9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab1au,2);
goto P_0c0caa9e;
P_0c0caa9e: /* original e340, guest PC 0x0c0caa9e */
if(!s->budget--) { s->failed_pc=0x0c0caa9eu; return 0; }
r[3]=0x00000040u;
goto P_0c0caaa0;
P_0c0caaa0: /* original 054c, guest PC 0x0c0caaa0 */
if(!s->budget--) { s->failed_pc=0x0c0caaa0u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0caaa2;
P_0c0caaa2: /* original 655c, guest PC 0x0c0caaa2 */
if(!s->budget--) { s->failed_pc=0x0c0caaa2u; return 0; }
r[5]=r[5]&255u;
goto P_0c0caaa4;
P_0c0caaa4: /* original 2358, guest PC 0x0c0caaa4 */
if(!s->budget--) { s->failed_pc=0x0c0caaa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0caaa6;
P_0c0caaa6: /* original 8922, guest PC 0x0c0caaa6 */
if(!s->budget--) { s->failed_pc=0x0c0caaa6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caaee; }
goto P_0c0caaa8;
P_0c0caaa8: /* original 9038, guest PC 0x0c0caaa8 */
if(!s->budget--) { s->failed_pc=0x0c0caaa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab1cu,2);
goto P_0c0caaaa;
P_0c0caaaa: /* original f646, guest PC 0x0c0caaaa */
if(!s->budget--) { s->failed_pc=0x0c0caaaau; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0caaac;
P_0c0caaac: /* original 700c, guest PC 0x0c0caaac */
if(!s->budget--) { s->failed_pc=0x0c0caaacu; return 0; }
r[0]+=0x0000000cu;
goto P_0c0caaae;
P_0c0caaae: /* original f746, guest PC 0x0c0caaae */
if(!s->budget--) { s->failed_pc=0x0c0caaaeu; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0caab0;
P_0c0caab0: /* original 70dc, guest PC 0x0c0caab0 */
if(!s->budget--) { s->failed_pc=0x0c0caab0u; return 0; }
r[0]+=0xffffffdcu;
goto P_0c0caab2;
P_0c0caab2: /* original f846, guest PC 0x0c0caab2 */
if(!s->budget--) { s->failed_pc=0x0c0caab2u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c0caab4;
P_0c0caab4: /* original 700c, guest PC 0x0c0caab4 */
if(!s->budget--) { s->failed_pc=0x0c0caab4u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0caab6;
P_0c0caab6: /* original f946, guest PC 0x0c0caab6 */
if(!s->budget--) { s->failed_pc=0x0c0caab6u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c0caab8;
P_0c0caab8: /* original c719, guest PC 0x0c0caab8 */
if(!s->budget--) { s->failed_pc=0x0c0caab8u; return 0; }
r[0]=code_base|0x000cab20u;
goto P_0c0caaba;
P_0c0caaba: /* original f508, guest PC 0x0c0caaba */
if(!s->budget--) { s->failed_pc=0x0c0caabau; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0caabc;
P_0c0caabc: /* original c719, guest PC 0x0c0caabc */
if(!s->budget--) { s->failed_pc=0x0c0caabcu; return 0; }
r[0]=code_base|0x000cab24u;
goto P_0c0caabe;
P_0c0caabe: /* original f655, guest PC 0x0c0caabe */
if(!s->budget--) { s->failed_pc=0x0c0caabeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0caac0;
P_0c0caac0: /* original 8d0e, guest PC 0x0c0caac0 */
if(!s->budget--) { s->failed_pc=0x0c0caac0u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c0caae0; }
goto P_0c0caac4;
P_0c0caac2: /* original f408, guest PC 0x0c0caac2 */
if(!s->budget--) { s->failed_pc=0x0c0caac2u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0caac4;
P_0c0caac4: /* original f465, guest PC 0x0c0caac4 */
if(!s->budget--) { s->failed_pc=0x0c0caac4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0caac6;
P_0c0caac6: /* original 890b, guest PC 0x0c0caac6 */
if(!s->budget--) { s->failed_pc=0x0c0caac6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caac8;
P_0c0caac8: /* original f755, guest PC 0x0c0caac8 */
if(!s->budget--) { s->failed_pc=0x0c0caac8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c0caaca;
P_0c0caaca: /* original 8909, guest PC 0x0c0caaca */
if(!s->budget--) { s->failed_pc=0x0c0caacau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caacc;
P_0c0caacc: /* original f475, guest PC 0x0c0caacc */
if(!s->budget--) { s->failed_pc=0x0c0caaccu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c0caace;
P_0c0caace: /* original 8907, guest PC 0x0c0caace */
if(!s->budget--) { s->failed_pc=0x0c0caaceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caad0;
P_0c0caad0: /* original f855, guest PC 0x0c0caad0 */
if(!s->budget--) { s->failed_pc=0x0c0caad0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c0caad2;
P_0c0caad2: /* original 8905, guest PC 0x0c0caad2 */
if(!s->budget--) { s->failed_pc=0x0c0caad2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caad4;
P_0c0caad4: /* original f485, guest PC 0x0c0caad4 */
if(!s->budget--) { s->failed_pc=0x0c0caad4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[8]))!=0);
goto P_0c0caad6;
P_0c0caad6: /* original 8903, guest PC 0x0c0caad6 */
if(!s->budget--) { s->failed_pc=0x0c0caad6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caad8;
P_0c0caad8: /* original f955, guest PC 0x0c0caad8 */
if(!s->budget--) { s->failed_pc=0x0c0caad8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[5]))!=0);
goto P_0c0caada;
P_0c0caada: /* original 8901, guest PC 0x0c0caada */
if(!s->budget--) { s->failed_pc=0x0c0caadau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caadc;
P_0c0caadc: /* original f495, guest PC 0x0c0caadc */
if(!s->budget--) { s->failed_pc=0x0c0caadcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[9]))!=0);
goto P_0c0caade;
P_0c0caade: /* original 8b02, guest PC 0x0c0caade */
if(!s->budget--) { s->failed_pc=0x0c0caadeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caae6; }
goto P_0c0caae0;
P_0c0caae0: /* original e310, guest PC 0x0c0caae0 */
if(!s->budget--) { s->failed_pc=0x0c0caae0u; return 0; }
r[3]=0x00000010u;
goto P_0c0caae2;
P_0c0caae2: /* original a002, guest PC 0x0c0caae2 */
if(!s->budget--) { s->failed_pc=0x0c0caae2u; return 0; }
r[5]|=r[3];
goto P_0c0caaea;
P_0c0caae4: /* original 253b, guest PC 0x0c0caae4 */
if(!s->budget--) { s->failed_pc=0x0c0caae4u; return 0; }
r[5]|=r[3];
goto P_0c0caae6;
P_0c0caae6: /* original e1ef, guest PC 0x0c0caae6 */
if(!s->budget--) { s->failed_pc=0x0c0caae6u; return 0; }
r[1]=0xffffffefu;
goto P_0c0caae8;
P_0c0caae8: /* original 2519, guest PC 0x0c0caae8 */
if(!s->budget--) { s->failed_pc=0x0c0caae8u; return 0; }
r[5]&=r[1];
goto P_0c0caaea;
P_0c0caaea: /* original 9016, guest PC 0x0c0caaea */
if(!s->budget--) { s->failed_pc=0x0c0caaeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab1au,2);
goto P_0c0caaec;
P_0c0caaec: /* original 0454, guest PC 0x0c0caaec */
if(!s->budget--) { s->failed_pc=0x0c0caaecu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0caaee;
P_0c0caaee: /* original 000b, guest PC 0x0c0caaee */
if(!s->budget--) { s->failed_pc=0x0c0caaeeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0caaf0: /* original 0009, guest PC 0x0c0caaf0 */
if(!s->budget--) { s->failed_pc=0x0c0caaf0u; return 0; }
return vf3_matrix_family(0x0c0caaf2u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
