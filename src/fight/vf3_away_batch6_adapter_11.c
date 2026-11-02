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
int vf3_away_batch6_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04db58u: goto P_0c04db58;
case 0x0c04db5au: goto P_0c04db5a;
case 0x0c04db5cu: goto P_0c04db5c;
case 0x0c04db5eu: goto P_0c04db5e;
case 0x0c04db60u: goto P_0c04db60;
case 0x0c04db62u: goto P_0c04db62;
case 0x0c04db64u: goto P_0c04db64;
case 0x0c04db66u: goto P_0c04db66;
case 0x0c04db68u: goto P_0c04db68;
case 0x0c04db6au: goto P_0c04db6a;
case 0x0c04db6cu: goto P_0c04db6c;
case 0x0c04db6eu: goto P_0c04db6e;
case 0x0c04db70u: goto P_0c04db70;
case 0x0c04db72u: goto P_0c04db72;
case 0x0c04db74u: goto P_0c04db74;
case 0x0c04db76u: goto P_0c04db76;
case 0x0c04db78u: goto P_0c04db78;
case 0x0c04db7au: goto P_0c04db7a;
case 0x0c04db7cu: goto P_0c04db7c;
case 0x0c04db7eu: goto P_0c04db7e;
case 0x0c04db80u: goto P_0c04db80;
case 0x0c04db82u: goto P_0c04db82;
case 0x0c04db84u: goto P_0c04db84;
case 0x0c04db86u: goto P_0c04db86;
case 0x0c04db88u: goto P_0c04db88;
case 0x0c04db8au: goto P_0c04db8a;
case 0x0c04db8cu: goto P_0c04db8c;
case 0x0c04db8eu: goto P_0c04db8e;
case 0x0c04db90u: goto P_0c04db90;
case 0x0c04db92u: goto P_0c04db92;
case 0x0c04db94u: goto P_0c04db94;
case 0x0c04db96u: goto P_0c04db96;
case 0x0c04db98u: goto P_0c04db98;
case 0x0c04db9au: goto P_0c04db9a;
case 0x0c04db9cu: goto P_0c04db9c;
case 0x0c04db9eu: goto P_0c04db9e;
case 0x0c04dba0u: goto P_0c04dba0;
case 0x0c04dba2u: goto P_0c04dba2;
case 0x0c04dba4u: goto P_0c04dba4;
case 0x0c04dba6u: goto P_0c04dba6;
case 0x0c04dba8u: goto P_0c04dba8;
case 0x0c04dbaau: goto P_0c04dbaa;
case 0x0c04dbacu: goto P_0c04dbac;
case 0x0c04dbaeu: goto P_0c04dbae;
case 0x0c04dbb0u: goto P_0c04dbb0;
case 0x0c04dbb2u: goto P_0c04dbb2;
case 0x0c04dbb4u: goto P_0c04dbb4;
case 0x0c04dbb6u: goto P_0c04dbb6;
case 0x0c04dbb8u: goto P_0c04dbb8;
case 0x0c04dbbau: goto P_0c04dbba;
case 0x0c04dbbcu: goto P_0c04dbbc;
case 0x0c04dbbeu: goto P_0c04dbbe;
case 0x0c04dbc0u: goto P_0c04dbc0;
case 0x0c04dbc2u: goto P_0c04dbc2;
case 0x0c04dbc4u: goto P_0c04dbc4;
case 0x0c04dbc6u: goto P_0c04dbc6;
case 0x0c04dbc8u: goto P_0c04dbc8;
case 0x0c04dbcau: goto P_0c04dbca;
case 0x0c04dbccu: goto P_0c04dbcc;
case 0x0c04dbceu: goto P_0c04dbce;
case 0x0c04dbd0u: goto P_0c04dbd0;
case 0x0c04dbd2u: goto P_0c04dbd2;
case 0x0c04dbd4u: goto P_0c04dbd4;
case 0x0c04dbd6u: goto P_0c04dbd6;
case 0x0c04dbd8u: goto P_0c04dbd8;
case 0x0c04dbdau: goto P_0c04dbda;
case 0x0c04dbdcu: goto P_0c04dbdc;
case 0x0c04dbdeu: goto P_0c04dbde;
case 0x0c04dbe0u: goto P_0c04dbe0;
case 0x0c04dbe2u: goto P_0c04dbe2;
case 0x0c04dbe4u: goto P_0c04dbe4;
case 0x0c04dbe6u: goto P_0c04dbe6;
case 0x0c04dbe8u: goto P_0c04dbe8;
case 0x0c04dbeau: goto P_0c04dbea;
case 0x0c04dbecu: goto P_0c04dbec;
case 0x0c04dbeeu: goto P_0c04dbee;
case 0x0c04dbf0u: goto P_0c04dbf0;
case 0x0c04dbf2u: goto P_0c04dbf2;
case 0x0c04dbf4u: goto P_0c04dbf4;
case 0x0c04dbf6u: goto P_0c04dbf6;
case 0x0c04dbf8u: goto P_0c04dbf8;
case 0x0c04dbfau: goto P_0c04dbfa;
case 0x0c04dbfcu: goto P_0c04dbfc;
case 0x0c04dbfeu: goto P_0c04dbfe;
case 0x0c04dc00u: goto P_0c04dc00;
case 0x0c04dc02u: goto P_0c04dc02;
case 0x0c04dc04u: goto P_0c04dc04;
case 0x0c04dc06u: goto P_0c04dc06;
case 0x0c04dc08u: goto P_0c04dc08;
case 0x0c04dc0au: goto P_0c04dc0a;
case 0x0c04dc0cu: goto P_0c04dc0c;
case 0x0c04dc0eu: goto P_0c04dc0e;
case 0x0c04dc10u: goto P_0c04dc10;
case 0x0c04dc12u: goto P_0c04dc12;
case 0x0c04dc14u: goto P_0c04dc14;
case 0x0c04dc16u: goto P_0c04dc16;
case 0x0c04dc18u: goto P_0c04dc18;
case 0x0c04dc50u: goto P_0c04dc50;
case 0x0c04dc52u: goto P_0c04dc52;
case 0x0c04dc54u: goto P_0c04dc54;
case 0x0c04dc56u: goto P_0c04dc56;
case 0x0c04dc58u: goto P_0c04dc58;
case 0x0c04dc5au: goto P_0c04dc5a;
case 0x0c04dc5cu: goto P_0c04dc5c;
case 0x0c04dc5eu: goto P_0c04dc5e;
case 0x0c04dc60u: goto P_0c04dc60;
case 0x0c04dc62u: goto P_0c04dc62;
case 0x0c04dc64u: goto P_0c04dc64;
case 0x0c04dc66u: goto P_0c04dc66;
case 0x0c04dc68u: goto P_0c04dc68;
case 0x0c04dc6au: goto P_0c04dc6a;
case 0x0c04dc6cu: goto P_0c04dc6c;
case 0x0c04dc6eu: goto P_0c04dc6e;
case 0x0c04dc70u: goto P_0c04dc70;
case 0x0c04dc72u: goto P_0c04dc72;
case 0x0c04dc74u: goto P_0c04dc74;
case 0x0c04dc76u: goto P_0c04dc76;
case 0x0c04dc78u: goto P_0c04dc78;
case 0x0c04dc7au: goto P_0c04dc7a;
case 0x0c04dc7cu: goto P_0c04dc7c;
case 0x0c04dc7eu: goto P_0c04dc7e;
case 0x0c04dc80u: goto P_0c04dc80;
case 0x0c04dc82u: goto P_0c04dc82;
case 0x0c04dc84u: goto P_0c04dc84;
case 0x0c04dc86u: goto P_0c04dc86;
case 0x0c04dc88u: goto P_0c04dc88;
case 0x0c04dc8au: goto P_0c04dc8a;
case 0x0c04dc8cu: goto P_0c04dc8c;
case 0x0c04dc8eu: goto P_0c04dc8e;
case 0x0c04dc90u: goto P_0c04dc90;
case 0x0c04dc92u: goto P_0c04dc92;
case 0x0c04dc94u: goto P_0c04dc94;
case 0x0c04dc96u: goto P_0c04dc96;
case 0x0c04dc98u: goto P_0c04dc98;
case 0x0c04dc9au: goto P_0c04dc9a;
case 0x0c04dc9cu: goto P_0c04dc9c;
case 0x0c04dc9eu: goto P_0c04dc9e;
case 0x0c04dca0u: goto P_0c04dca0;
case 0x0c04dca2u: goto P_0c04dca2;
case 0x0c04dca4u: goto P_0c04dca4;
case 0x0c04dca6u: goto P_0c04dca6;
case 0x0c04dca8u: goto P_0c04dca8;
case 0x0c04dcaau: goto P_0c04dcaa;
case 0x0c04dcacu: goto P_0c04dcac;
case 0x0c04dcaeu: goto P_0c04dcae;
case 0x0c04dcb0u: goto P_0c04dcb0;
case 0x0c04dcb2u: goto P_0c04dcb2;
case 0x0c04dcb4u: goto P_0c04dcb4;
case 0x0c04dcb6u: goto P_0c04dcb6;
case 0x0c04dcb8u: goto P_0c04dcb8;
case 0x0c04dcbau: goto P_0c04dcba;
case 0x0c04dcbcu: goto P_0c04dcbc;
case 0x0c04dcbeu: goto P_0c04dcbe;
case 0x0c04dcc0u: goto P_0c04dcc0;
case 0x0c04dcc2u: goto P_0c04dcc2;
case 0x0c04dcc4u: goto P_0c04dcc4;
case 0x0c04dcc6u: goto P_0c04dcc6;
case 0x0c04dcc8u: goto P_0c04dcc8;
case 0x0c04dccau: goto P_0c04dcca;
case 0x0c04dcccu: goto P_0c04dccc;
case 0x0c04dcceu: goto P_0c04dcce;
case 0x0c04e712u: goto P_0c04e712;
case 0x0c04e714u: goto P_0c04e714;
case 0x0c04e716u: goto P_0c04e716;
case 0x0c04e718u: goto P_0c04e718;
case 0x0c04e71au: goto P_0c04e71a;
case 0x0c04e71cu: goto P_0c04e71c;
case 0x0c04e71eu: goto P_0c04e71e;
case 0x0c04e720u: goto P_0c04e720;
case 0x0c04e722u: goto P_0c04e722;
case 0x0c04e724u: goto P_0c04e724;
case 0x0c04e726u: goto P_0c04e726;
case 0x0c04e728u: goto P_0c04e728;
case 0x0c04e72au: goto P_0c04e72a;
case 0x0c04e72cu: goto P_0c04e72c;
case 0x0c04e72eu: goto P_0c04e72e;
case 0x0c04e730u: goto P_0c04e730;
case 0x0c04e732u: goto P_0c04e732;
case 0x0c04e734u: goto P_0c04e734;
case 0x0c04e736u: goto P_0c04e736;
case 0x0c04e738u: goto P_0c04e738;
case 0x0c04e73au: goto P_0c04e73a;
case 0x0c04e73cu: goto P_0c04e73c;
case 0x0c04e73eu: goto P_0c04e73e;
case 0x0c04e740u: goto P_0c04e740;
case 0x0c04e742u: goto P_0c04e742;
case 0x0c04e744u: goto P_0c04e744;
case 0x0c04e746u: goto P_0c04e746;
case 0x0c04e748u: goto P_0c04e748;
case 0x0c04e74au: goto P_0c04e74a;
case 0x0c04e74cu: goto P_0c04e74c;
case 0x0c04e74eu: goto P_0c04e74e;
case 0x0c04e750u: goto P_0c04e750;
case 0x0c04e752u: goto P_0c04e752;
case 0x0c04e754u: goto P_0c04e754;
case 0x0c04e756u: goto P_0c04e756;
case 0x0c04e758u: goto P_0c04e758;
case 0x0c04e75au: goto P_0c04e75a;
case 0x0c04e75cu: goto P_0c04e75c;
case 0x0c04e75eu: goto P_0c04e75e;
case 0x0c04e760u: goto P_0c04e760;
case 0x0c04e762u: goto P_0c04e762;
case 0x0c04e764u: goto P_0c04e764;
case 0x0c04e766u: goto P_0c04e766;
case 0x0c04e768u: goto P_0c04e768;
case 0x0c04e76au: goto P_0c04e76a;
case 0x0c04e76cu: goto P_0c04e76c;
case 0x0c04e76eu: goto P_0c04e76e;
case 0x0c04e770u: goto P_0c04e770;
case 0x0c04e772u: goto P_0c04e772;
case 0x0c04e774u: goto P_0c04e774;
case 0x0c04e776u: goto P_0c04e776;
case 0x0c04e778u: goto P_0c04e778;
case 0x0c04e77au: goto P_0c04e77a;
case 0x0c04e77cu: goto P_0c04e77c;
case 0x0c04e77eu: goto P_0c04e77e;
case 0x0c04e780u: goto P_0c04e780;
case 0x0c04e782u: goto P_0c04e782;
case 0x0c04e784u: goto P_0c04e784;
case 0x0c04e786u: goto P_0c04e786;
case 0x0c04e788u: goto P_0c04e788;
case 0x0c04e78au: goto P_0c04e78a;
case 0x0c04e78cu: goto P_0c04e78c;
case 0x0c04e78eu: goto P_0c04e78e;
case 0x0c04e790u: goto P_0c04e790;
case 0x0c04e792u: goto P_0c04e792;
case 0x0c04e794u: goto P_0c04e794;
case 0x0c04e796u: goto P_0c04e796;
case 0x0c04e798u: goto P_0c04e798;
case 0x0c04e79au: goto P_0c04e79a;
case 0x0c04e79cu: goto P_0c04e79c;
case 0x0c04e79eu: goto P_0c04e79e;
case 0x0c04e7a0u: goto P_0c04e7a0;
case 0x0c04e7a2u: goto P_0c04e7a2;
case 0x0c04e7a4u: goto P_0c04e7a4;
case 0x0c04e7a6u: goto P_0c04e7a6;
case 0x0c04e7a8u: goto P_0c04e7a8;
case 0x0c04e7aau: goto P_0c04e7aa;
case 0x0c04e7acu: goto P_0c04e7ac;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04db58: /* original 2fe6, guest PC 0x0c04db58 */
if(!s->budget--) { s->failed_pc=0x0c04db58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db5a;
P_0c04db5a: /* original 2fd6, guest PC 0x0c04db5a */
if(!s->budget--) { s->failed_pc=0x0c04db5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db5c;
P_0c04db5c: /* original 6d43, guest PC 0x0c04db5c */
if(!s->budget--) { s->failed_pc=0x0c04db5cu; return 0; }
r[13]=r[4];
goto P_0c04db5e;
P_0c04db5e: /* original 2fc6, guest PC 0x0c04db5e */
if(!s->budget--) { s->failed_pc=0x0c04db5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db60;
P_0c04db60: /* original 6c53, guest PC 0x0c04db60 */
if(!s->budget--) { s->failed_pc=0x0c04db60u; return 0; }
r[12]=r[5];
goto P_0c04db62;
P_0c04db62: /* original 2fb6, guest PC 0x0c04db62 */
if(!s->budget--) { s->failed_pc=0x0c04db62u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db64;
P_0c04db64: /* original 2fa6, guest PC 0x0c04db64 */
if(!s->budget--) { s->failed_pc=0x0c04db64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db66;
P_0c04db66: /* original 6a73, guest PC 0x0c04db66 */
if(!s->budget--) { s->failed_pc=0x0c04db66u; return 0; }
r[10]=r[7];
goto P_0c04db68;
P_0c04db68: /* original 2f96, guest PC 0x0c04db68 */
if(!s->budget--) { s->failed_pc=0x0c04db68u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db6a;
P_0c04db6a: /* original 4f22, guest PC 0x0c04db6a */
if(!s->budget--) { s->failed_pc=0x0c04db6au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04db6c;
P_0c04db6c: /* original 4f12, guest PC 0x0c04db6c */
if(!s->budget--) { s->failed_pc=0x0c04db6cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04db6e;
P_0c04db6e: /* original 7fd0, guest PC 0x0c04db6e */
if(!s->budget--) { s->failed_pc=0x0c04db6eu; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04db70;
P_0c04db70: /* original 2f62, guest PC 0x0c04db70 */
if(!s->budget--) { s->failed_pc=0x0c04db70u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04db72;
P_0c04db72: /* original 2f76, guest PC 0x0c04db72 */
if(!s->budget--) { s->failed_pc=0x0c04db72u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db74;
P_0c04db74: /* original 53f1, guest PC 0x0c04db74 */
if(!s->budget--) { s->failed_pc=0x0c04db74u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04db76;
P_0c04db76: /* original 2f36, guest PC 0x0c04db76 */
if(!s->budget--) { s->failed_pc=0x0c04db76u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db78;
P_0c04db78: /* original 2fc6, guest PC 0x0c04db78 */
if(!s->budget--) { s->failed_pc=0x0c04db78u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db7a;
P_0c04db7a: /* original 2fd6, guest PC 0x0c04db7a */
if(!s->budget--) { s->failed_pc=0x0c04db7au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db7c;
P_0c04db7c: /* original d22b, guest PC 0x0c04db7c */
if(!s->budget--) { s->failed_pc=0x0c04db7cu; return 0; }
r[2]=read(ram,0x0c04dc2cu,4);
goto P_0c04db7e;
P_0c04db7e: /* original d32a, guest PC 0x0c04db7e */
if(!s->budget--) { s->failed_pc=0x0c04db7eu; return 0; }
r[3]=read(ram,0x0c04dc28u,4);
goto P_0c04db80;
P_0c04db80: /* original 420b, guest PC 0x0c04db80 */
if(!s->budget--) { s->failed_pc=0x0c04db80u; return 0; }
target=r[2];
r[16]=code_base|0x0c04db84u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04db84u) { target=s->pc; goto dispatch; }
goto P_0c04db84;
P_0c04db82: /* original 2f36, guest PC 0x0c04db82 */
if(!s->budget--) { s->failed_pc=0x0c04db82u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db84;
P_0c04db84: /* original eb00, guest PC 0x0c04db84 */
if(!s->budget--) { s->failed_pc=0x0c04db84u; return 0; }
r[11]=0x00000000u;
goto P_0c04db86;
P_0c04db86: /* original 2ab2, guest PC 0x0c04db86 */
if(!s->budget--) { s->failed_pc=0x0c04db86u; return 0; }
write(ram,r[10],r[11],4);
goto P_0c04db88;
P_0c04db88: /* original 9347, guest PC 0x0c04db88 */
if(!s->budget--) { s->failed_pc=0x0c04db88u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1au,2);
goto P_0c04db8a;
P_0c04db8a: /* original d029, guest PC 0x0c04db8a */
if(!s->budget--) { s->failed_pc=0x0c04db8au; return 0; }
r[0]=read(ram,0x0c04dc30u,4);
goto P_0c04db8c;
P_0c04db8c: /* original 2d3f, guest PC 0x0c04db8c */
if(!s->budget--) { s->failed_pc=0x0c04db8cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[3]);
goto P_0c04db8e;
P_0c04db8e: /* original 031a, guest PC 0x0c04db8e */
if(!s->budget--) { s->failed_pc=0x0c04db8eu; return 0; }
r[3]=r[19];
goto P_0c04db90;
P_0c04db90: /* original 633f, guest PC 0x0c04db90 */
if(!s->budget--) { s->failed_pc=0x0c04db90u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04db92;
P_0c04db92: /* original 023c, guest PC 0x0c04db92 */
if(!s->budget--) { s->failed_pc=0x0c04db92u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04db94;
P_0c04db94: /* original 2228, guest PC 0x0c04db94 */
if(!s->budget--) { s->failed_pc=0x0c04db94u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04db96;
P_0c04db96: /* original 8d16, guest PC 0x0c04db96 */
if(!s->budget--) { s->failed_pc=0x0c04db96u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000014u;
if(cond) { goto P_0c04dbc6; }
goto P_0c04db9a;
P_0c04db98: /* original 7f14, guest PC 0x0c04db98 */
if(!s->budget--) { s->failed_pc=0x0c04db98u; return 0; }
r[15]+=0x00000014u;
goto P_0c04db9a;
P_0c04db9a: /* original d326, guest PC 0x0c04db9a */
if(!s->budget--) { s->failed_pc=0x0c04db9au; return 0; }
r[3]=read(ram,0x0c04dc34u,4);
goto P_0c04db9c;
P_0c04db9c: /* original 430b, guest PC 0x0c04db9c */
if(!s->budget--) { s->failed_pc=0x0c04db9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04dba0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dba0u) { target=s->pc; goto dispatch; }
goto P_0c04dba0;
P_0c04db9e: /* original 64d3, guest PC 0x0c04db9e */
if(!s->budget--) { s->failed_pc=0x0c04db9eu; return 0; }
r[4]=r[13];
goto P_0c04dba0;
P_0c04dba0: /* original 2008, guest PC 0x0c04dba0 */
if(!s->budget--) { s->failed_pc=0x0c04dba0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04dba2;
P_0c04dba2: /* original 8b03, guest PC 0x0c04dba2 */
if(!s->budget--) { s->failed_pc=0x0c04dba2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dbac; }
goto P_0c04dba4;
P_0c04dba4: /* original b993, guest PC 0x0c04dba4 */
if(!s->budget--) { s->failed_pc=0x0c04dba4u; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04dba8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dba8u) { target=s->pc; goto dispatch; }
goto P_0c04dba8;
P_0c04dba6: /* original 64d3, guest PC 0x0c04dba6 */
if(!s->budget--) { s->failed_pc=0x0c04dba6u; return 0; }
r[4]=r[13];
goto P_0c04dba8;
P_0c04dba8: /* original a00d, guest PC 0x0c04dba8 */
if(!s->budget--) { s->failed_pc=0x0c04dba8u; return 0; }
goto P_0c04dbc6;
P_0c04dbaa: /* original 0009, guest PC 0x0c04dbaa */
if(!s->budget--) { s->failed_pc=0x0c04dbaau; return 0; }
goto P_0c04dbac;
P_0c04dbac: /* original d222, guest PC 0x0c04dbac */
if(!s->budget--) { s->failed_pc=0x0c04dbacu; return 0; }
r[2]=read(ram,0x0c04dc38u,4);
goto P_0c04dbae;
P_0c04dbae: /* original 420b, guest PC 0x0c04dbae */
if(!s->budget--) { s->failed_pc=0x0c04dbaeu; return 0; }
target=r[2];
r[16]=code_base|0x0c04dbb2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbb2u) { target=s->pc; goto dispatch; }
goto P_0c04dbb2;
P_0c04dbb0: /* original 64d3, guest PC 0x0c04dbb0 */
if(!s->budget--) { s->failed_pc=0x0c04dbb0u; return 0; }
r[4]=r[13];
goto P_0c04dbb2;
P_0c04dbb2: /* original 2008, guest PC 0x0c04dbb2 */
if(!s->budget--) { s->failed_pc=0x0c04dbb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04dbb4;
P_0c04dbb4: /* original 8907, guest PC 0x0c04dbb4 */
if(!s->budget--) { s->failed_pc=0x0c04dbb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dbc6; }
goto P_0c04dbb6;
P_0c04dbb6: /* original 9330, guest PC 0x0c04dbb6 */
if(!s->budget--) { s->failed_pc=0x0c04dbb6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1au,2);
goto P_0c04dbb8;
P_0c04dbb8: /* original d020, guest PC 0x0c04dbb8 */
if(!s->budget--) { s->failed_pc=0x0c04dbb8u; return 0; }
r[0]=read(ram,0x0c04dc3cu,4);
goto P_0c04dbba;
P_0c04dbba: /* original 2d3f, guest PC 0x0c04dbba */
if(!s->budget--) { s->failed_pc=0x0c04dbbau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[3]);
goto P_0c04dbbc;
P_0c04dbbc: /* original 031a, guest PC 0x0c04dbbc */
if(!s->budget--) { s->failed_pc=0x0c04dbbcu; return 0; }
r[3]=r[19];
goto P_0c04dbbe;
P_0c04dbbe: /* original 633f, guest PC 0x0c04dbbe */
if(!s->budget--) { s->failed_pc=0x0c04dbbeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04dbc0;
P_0c04dbc0: /* original 023c, guest PC 0x0c04dbc0 */
if(!s->budget--) { s->failed_pc=0x0c04dbc0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04dbc2;
P_0c04dbc2: /* original 2228, guest PC 0x0c04dbc2 */
if(!s->budget--) { s->failed_pc=0x0c04dbc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04dbc4;
P_0c04dbc4: /* original 8b02, guest PC 0x0c04dbc4 */
if(!s->budget--) { s->failed_pc=0x0c04dbc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dbcc; }
goto P_0c04dbc6;
P_0c04dbc6: /* original 9029, guest PC 0x0c04dbc6 */
if(!s->budget--) { s->failed_pc=0x0c04dbc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1cu,2);
goto P_0c04dbc8;
P_0c04dbc8: /* original a078, guest PC 0x0c04dbc8 */
if(!s->budget--) { s->failed_pc=0x0c04dbc8u; return 0; }
goto P_0c04dcbc;
P_0c04dbca: /* original 0009, guest PC 0x0c04dbca */
if(!s->budget--) { s->failed_pc=0x0c04dbcau; return 0; }
goto P_0c04dbcc;
P_0c04dbcc: /* original d31c, guest PC 0x0c04dbcc */
if(!s->budget--) { s->failed_pc=0x0c04dbccu; return 0; }
r[3]=read(ram,0x0c04dc40u,4);
goto P_0c04dbce;
P_0c04dbce: /* original 430b, guest PC 0x0c04dbce */
if(!s->budget--) { s->failed_pc=0x0c04dbceu; return 0; }
target=r[3];
r[16]=code_base|0x0c04dbd2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbd2u) { target=s->pc; goto dispatch; }
goto P_0c04dbd2;
P_0c04dbd0: /* original 64d3, guest PC 0x0c04dbd0 */
if(!s->budget--) { s->failed_pc=0x0c04dbd0u; return 0; }
r[4]=r[13];
goto P_0c04dbd2;
P_0c04dbd2: /* original 4011, guest PC 0x0c04dbd2 */
if(!s->budget--) { s->failed_pc=0x0c04dbd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dbd4;
P_0c04dbd4: /* original 8902, guest PC 0x0c04dbd4 */
if(!s->budget--) { s->failed_pc=0x0c04dbd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dbdc; }
goto P_0c04dbd6;
P_0c04dbd6: /* original 9022, guest PC 0x0c04dbd6 */
if(!s->budget--) { s->failed_pc=0x0c04dbd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1eu,2);
goto P_0c04dbd8;
P_0c04dbd8: /* original a070, guest PC 0x0c04dbd8 */
if(!s->budget--) { s->failed_pc=0x0c04dbd8u; return 0; }
goto P_0c04dcbc;
P_0c04dbda: /* original 0009, guest PC 0x0c04dbda */
if(!s->budget--) { s->failed_pc=0x0c04dbdau; return 0; }
goto P_0c04dbdc;
P_0c04dbdc: /* original d319, guest PC 0x0c04dbdc */
if(!s->budget--) { s->failed_pc=0x0c04dbdcu; return 0; }
r[3]=read(ram,0x0c04dc44u,4);
goto P_0c04dbde;
P_0c04dbde: /* original 65c3, guest PC 0x0c04dbde */
if(!s->budget--) { s->failed_pc=0x0c04dbdeu; return 0; }
r[5]=r[12];
goto P_0c04dbe0;
P_0c04dbe0: /* original 430b, guest PC 0x0c04dbe0 */
if(!s->budget--) { s->failed_pc=0x0c04dbe0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04dbe4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbe4u) { target=s->pc; goto dispatch; }
goto P_0c04dbe4;
P_0c04dbe2: /* original 64d3, guest PC 0x0c04dbe2 */
if(!s->budget--) { s->failed_pc=0x0c04dbe2u; return 0; }
r[4]=r[13];
goto P_0c04dbe4;
P_0c04dbe4: /* original 4011, guest PC 0x0c04dbe4 */
if(!s->budget--) { s->failed_pc=0x0c04dbe4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dbe6;
P_0c04dbe6: /* original 8b15, guest PC 0x0c04dbe6 */
if(!s->budget--) { s->failed_pc=0x0c04dbe6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dc14; }
goto P_0c04dbe8;
P_0c04dbe8: /* original d217, guest PC 0x0c04dbe8 */
if(!s->budget--) { s->failed_pc=0x0c04dbe8u; return 0; }
r[2]=read(ram,0x0c04dc48u,4);
goto P_0c04dbea;
P_0c04dbea: /* original 66f3, guest PC 0x0c04dbea */
if(!s->budget--) { s->failed_pc=0x0c04dbeau; return 0; }
r[6]=r[15];
goto P_0c04dbec;
P_0c04dbec: /* original 65c3, guest PC 0x0c04dbec */
if(!s->budget--) { s->failed_pc=0x0c04dbecu; return 0; }
r[5]=r[12];
goto P_0c04dbee;
P_0c04dbee: /* original 7604, guest PC 0x0c04dbee */
if(!s->budget--) { s->failed_pc=0x0c04dbeeu; return 0; }
r[6]+=0x00000004u;
goto P_0c04dbf0;
P_0c04dbf0: /* original 420b, guest PC 0x0c04dbf0 */
if(!s->budget--) { s->failed_pc=0x0c04dbf0u; return 0; }
target=r[2];
r[16]=code_base|0x0c04dbf4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbf4u) { target=s->pc; goto dispatch; }
goto P_0c04dbf4;
P_0c04dbf2: /* original 64d3, guest PC 0x0c04dbf2 */
if(!s->budget--) { s->failed_pc=0x0c04dbf2u; return 0; }
r[4]=r[13];
goto P_0c04dbf4;
P_0c04dbf4: /* original 4011, guest PC 0x0c04dbf4 */
if(!s->budget--) { s->failed_pc=0x0c04dbf4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dbf6;
P_0c04dbf6: /* original 8b07, guest PC 0x0c04dbf6 */
if(!s->budget--) { s->failed_pc=0x0c04dbf6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dc08; }
goto P_0c04dbf8;
P_0c04dbf8: /* original 65c3, guest PC 0x0c04dbf8 */
if(!s->budget--) { s->failed_pc=0x0c04dbf8u; return 0; }
r[5]=r[12];
goto P_0c04dbfa;
P_0c04dbfa: /* original b58a, guest PC 0x0c04dbfa */
if(!s->budget--) { s->failed_pc=0x0c04dbfau; return 0; }
target=code_base|0x0c04e712u; r[16]=code_base|0x0c04dbfeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbfeu) { target=s->pc; goto dispatch; }
goto P_0c04dbfe;
P_0c04dbfc: /* original 64d3, guest PC 0x0c04dbfc */
if(!s->budget--) { s->failed_pc=0x0c04dbfcu; return 0; }
r[4]=r[13];
goto P_0c04dbfe;
P_0c04dbfe: /* original 4011, guest PC 0x0c04dbfe */
if(!s->budget--) { s->failed_pc=0x0c04dbfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dc00;
P_0c04dc00: /* original 8d02, guest PC 0x0c04dc00 */
if(!s->budget--) { s->failed_pc=0x0c04dc00u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04dc08; }
goto P_0c04dc04;
P_0c04dc02: /* original 6403, guest PC 0x0c04dc02 */
if(!s->budget--) { s->failed_pc=0x0c04dc02u; return 0; }
r[4]=r[0];
goto P_0c04dc04;
P_0c04dc04: /* original a05a, guest PC 0x0c04dc04 */
if(!s->budget--) { s->failed_pc=0x0c04dc04u; return 0; }
r[0]=r[4];
goto P_0c04dcbc;
P_0c04dc06: /* original 6043, guest PC 0x0c04dc06 */
if(!s->budget--) { s->failed_pc=0x0c04dc06u; return 0; }
r[0]=r[4];
goto P_0c04dc08;
P_0c04dc08: /* original d210, guest PC 0x0c04dc08 */
if(!s->budget--) { s->failed_pc=0x0c04dc08u; return 0; }
r[2]=read(ram,0x0c04dc4cu,4);
goto P_0c04dc0a;
P_0c04dc0a: /* original 420b, guest PC 0x0c04dc0a */
if(!s->budget--) { s->failed_pc=0x0c04dc0au; return 0; }
target=r[2];
r[16]=code_base|0x0c04dc0eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc0eu) { target=s->pc; goto dispatch; }
goto P_0c04dc0e;
P_0c04dc0c: /* original 64d3, guest PC 0x0c04dc0c */
if(!s->budget--) { s->failed_pc=0x0c04dc0cu; return 0; }
r[4]=r[13];
goto P_0c04dc0e;
P_0c04dc0e: /* original 6903, guest PC 0x0c04dc0e */
if(!s->budget--) { s->failed_pc=0x0c04dc0eu; return 0; }
r[9]=r[0];
goto P_0c04dc10;
P_0c04dc10: /* original 4911, guest PC 0x0c04dc10 */
if(!s->budget--) { s->failed_pc=0x0c04dc10u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=0)!=0);
goto P_0c04dc12;
P_0c04dc12: /* original 891d, guest PC 0x0c04dc12 */
if(!s->budget--) { s->failed_pc=0x0c04dc12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dc50; }
goto P_0c04dc14;
P_0c04dc14: /* original 9004, guest PC 0x0c04dc14 */
if(!s->budget--) { s->failed_pc=0x0c04dc14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc20u,2);
goto P_0c04dc16;
P_0c04dc16: /* original a051, guest PC 0x0c04dc16 */
if(!s->budget--) { s->failed_pc=0x0c04dc16u; return 0; }
goto P_0c04dcbc;
P_0c04dc18: /* original 0009, guest PC 0x0c04dc18 */
if(!s->budget--) { s->failed_pc=0x0c04dc18u; return 0; }
if(!vf3_matrix_family(0x0c04dc1au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04dc1au; return 0; } return 1;
P_0c04dc50: /* original d240, guest PC 0x0c04dc50 */
if(!s->budget--) { s->failed_pc=0x0c04dc50u; return 0; }
r[2]=read(ram,0x0c04dd54u,4);
goto P_0c04dc52;
P_0c04dc52: /* original 6593, guest PC 0x0c04dc52 */
if(!s->budget--) { s->failed_pc=0x0c04dc52u; return 0; }
r[5]=r[9];
goto P_0c04dc54;
P_0c04dc54: /* original 420b, guest PC 0x0c04dc54 */
if(!s->budget--) { s->failed_pc=0x0c04dc54u; return 0; }
target=r[2];
r[16]=code_base|0x0c04dc58u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc58u) { target=s->pc; goto dispatch; }
goto P_0c04dc58;
P_0c04dc56: /* original 64d3, guest PC 0x0c04dc56 */
if(!s->budget--) { s->failed_pc=0x0c04dc56u; return 0; }
r[4]=r[13];
goto P_0c04dc58;
P_0c04dc58: /* original d33f, guest PC 0x0c04dc58 */
if(!s->budget--) { s->failed_pc=0x0c04dc58u; return 0; }
r[3]=read(ram,0x0c04dd58u,4);
goto P_0c04dc5a;
P_0c04dc5a: /* original 430b, guest PC 0x0c04dc5a */
if(!s->budget--) { s->failed_pc=0x0c04dc5au; return 0; }
target=r[3];
r[16]=code_base|0x0c04dc5eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc5eu) { target=s->pc; goto dispatch; }
goto P_0c04dc5e;
P_0c04dc5c: /* original 64d3, guest PC 0x0c04dc5c */
if(!s->budget--) { s->failed_pc=0x0c04dc5cu; return 0; }
r[4]=r[13];
goto P_0c04dc5e;
P_0c04dc5e: /* original 6e03, guest PC 0x0c04dc5e */
if(!s->budget--) { s->failed_pc=0x0c04dc5eu; return 0; }
r[14]=r[0];
goto P_0c04dc60;
P_0c04dc60: /* original 2ee8, guest PC 0x0c04dc60 */
if(!s->budget--) { s->failed_pc=0x0c04dc60u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04dc62;
P_0c04dc62: /* original 8b02, guest PC 0x0c04dc62 */
if(!s->budget--) { s->failed_pc=0x0c04dc62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dc6a; }
goto P_0c04dc64;
P_0c04dc64: /* original 9071, guest PC 0x0c04dc64 */
if(!s->budget--) { s->failed_pc=0x0c04dc64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dd4au,2);
goto P_0c04dc66;
P_0c04dc66: /* original a029, guest PC 0x0c04dc66 */
if(!s->budget--) { s->failed_pc=0x0c04dc66u; return 0; }
goto P_0c04dcbc;
P_0c04dc68: /* original 0009, guest PC 0x0c04dc68 */
if(!s->budget--) { s->failed_pc=0x0c04dc68u; return 0; }
goto P_0c04dc6a;
P_0c04dc6a: /* original e301, guest PC 0x0c04dc6a */
if(!s->budget--) { s->failed_pc=0x0c04dc6au; return 0; }
r[3]=0x00000001u;
goto P_0c04dc6c;
P_0c04dc6c: /* original 60b3, guest PC 0x0c04dc6c */
if(!s->budget--) { s->failed_pc=0x0c04dc6cu; return 0; }
r[0]=r[11];
goto P_0c04dc6e;
P_0c04dc6e: /* original 1eb2, guest PC 0x0c04dc6e */
if(!s->budget--) { s->failed_pc=0x0c04dc6eu; return 0; }
write(ram,r[14]+8,r[11],4);
goto P_0c04dc70;
P_0c04dc70: /* original 1e31, guest PC 0x0c04dc70 */
if(!s->budget--) { s->failed_pc=0x0c04dc70u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c04dc72;
P_0c04dc72: /* original 1e9b, guest PC 0x0c04dc72 */
if(!s->budget--) { s->failed_pc=0x0c04dc72u; return 0; }
write(ram,r[14]+44,r[9],4);
goto P_0c04dc74;
P_0c04dc74: /* original d239, guest PC 0x0c04dc74 */
if(!s->budget--) { s->failed_pc=0x0c04dc74u; return 0; }
r[2]=read(ram,0x0c04dd5cu,4);
goto P_0c04dc76;
P_0c04dc76: /* original 1e2e, guest PC 0x0c04dc76 */
if(!s->budget--) { s->failed_pc=0x0c04dc76u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c04dc78;
P_0c04dc78: /* original 1ebc, guest PC 0x0c04dc78 */
if(!s->budget--) { s->failed_pc=0x0c04dc78u; return 0; }
write(ram,r[14]+48,r[11],4);
goto P_0c04dc7a;
P_0c04dc7a: /* original 1eda, guest PC 0x0c04dc7a */
if(!s->budget--) { s->failed_pc=0x0c04dc7au; return 0; }
write(ram,r[14]+40,r[13],4);
goto P_0c04dc7c;
P_0c04dc7c: /* original 81e1, guest PC 0x0c04dc7c */
if(!s->budget--) { s->failed_pc=0x0c04dc7cu; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c04dc7e;
P_0c04dc7e: /* original 80e1, guest PC 0x0c04dc7e */
if(!s->budget--) { s->failed_pc=0x0c04dc7eu; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c04dc80;
P_0c04dc80: /* original 53e1, guest PC 0x0c04dc80 */
if(!s->budget--) { s->failed_pc=0x0c04dc80u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c04dc82;
P_0c04dc82: /* original 2f36, guest PC 0x0c04dc82 */
if(!s->budget--) { s->failed_pc=0x0c04dc82u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc84;
P_0c04dc84: /* original d337, guest PC 0x0c04dc84 */
if(!s->budget--) { s->failed_pc=0x0c04dc84u; return 0; }
r[3]=read(ram,0x0c04dd64u,4);
goto P_0c04dc86;
P_0c04dc86: /* original d236, guest PC 0x0c04dc86 */
if(!s->budget--) { s->failed_pc=0x0c04dc86u; return 0; }
r[2]=read(ram,0x0c04dd60u,4);
goto P_0c04dc88;
P_0c04dc88: /* original 430b, guest PC 0x0c04dc88 */
if(!s->budget--) { s->failed_pc=0x0c04dc88u; return 0; }
target=r[3];
r[16]=code_base|0x0c04dc8cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc8cu) { target=s->pc; goto dispatch; }
goto P_0c04dc8c;
P_0c04dc8a: /* original 2f26, guest PC 0x0c04dc8a */
if(!s->budget--) { s->failed_pc=0x0c04dc8au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc8c;
P_0c04dc8c: /* original 51eb, guest PC 0x0c04dc8c */
if(!s->budget--) { s->failed_pc=0x0c04dc8cu; return 0; }
r[1]=read(ram,r[14]+44,4);
goto P_0c04dc8e;
P_0c04dc8e: /* original 2f16, guest PC 0x0c04dc8e */
if(!s->budget--) { s->failed_pc=0x0c04dc8eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc90;
P_0c04dc90: /* original d335, guest PC 0x0c04dc90 */
if(!s->budget--) { s->failed_pc=0x0c04dc90u; return 0; }
r[3]=read(ram,0x0c04dd68u,4);
goto P_0c04dc92;
P_0c04dc92: /* original d234, guest PC 0x0c04dc92 */
if(!s->budget--) { s->failed_pc=0x0c04dc92u; return 0; }
r[2]=read(ram,0x0c04dd64u,4);
goto P_0c04dc94;
P_0c04dc94: /* original 420b, guest PC 0x0c04dc94 */
if(!s->budget--) { s->failed_pc=0x0c04dc94u; return 0; }
target=r[2];
r[16]=code_base|0x0c04dc98u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc98u) { target=s->pc; goto dispatch; }
goto P_0c04dc98;
P_0c04dc96: /* original 2f36, guest PC 0x0c04dc96 */
if(!s->budget--) { s->failed_pc=0x0c04dc96u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc98;
P_0c04dc98: /* original 64e3, guest PC 0x0c04dc98 */
if(!s->budget--) { s->failed_pc=0x0c04dc98u; return 0; }
r[4]=r[14];
goto P_0c04dc9a;
P_0c04dc9a: /* original 7f10, guest PC 0x0c04dc9a */
if(!s->budget--) { s->failed_pc=0x0c04dc9au; return 0; }
r[15]+=0x00000010u;
goto P_0c04dc9c;
P_0c04dc9c: /* original a003, guest PC 0x0c04dc9c */
if(!s->budget--) { s->failed_pc=0x0c04dc9cu; return 0; }
r[4]+=0x00000010u;
goto P_0c04dca6;
P_0c04dc9e: /* original 7410, guest PC 0x0c04dc9e */
if(!s->budget--) { s->failed_pc=0x0c04dc9eu; return 0; }
r[4]+=0x00000010u;
goto P_0c04dca0;
P_0c04dca0: /* original 63c4, guest PC 0x0c04dca0 */
if(!s->budget--) { s->failed_pc=0x0c04dca0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c04dca2;
P_0c04dca2: /* original 2430, guest PC 0x0c04dca2 */
if(!s->budget--) { s->failed_pc=0x0c04dca2u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04dca4;
P_0c04dca4: /* original 7401, guest PC 0x0c04dca4 */
if(!s->budget--) { s->failed_pc=0x0c04dca4u; return 0; }
r[4]+=0x00000001u;
goto P_0c04dca6;
P_0c04dca6: /* original 62c0, guest PC 0x0c04dca6 */
if(!s->budget--) { s->failed_pc=0x0c04dca6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c04dca8;
P_0c04dca8: /* original 2228, guest PC 0x0c04dca8 */
if(!s->budget--) { s->failed_pc=0x0c04dca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04dcaa;
P_0c04dcaa: /* original 8bf9, guest PC 0x0c04dcaa */
if(!s->budget--) { s->failed_pc=0x0c04dcaau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dca0; }
goto P_0c04dcac;
P_0c04dcac: /* original 24b0, guest PC 0x0c04dcac */
if(!s->budget--) { s->failed_pc=0x0c04dcacu; return 0; }
write(ram,r[4],r[11],1);
goto P_0c04dcae;
P_0c04dcae: /* original 64e3, guest PC 0x0c04dcae */
if(!s->budget--) { s->failed_pc=0x0c04dcaeu; return 0; }
r[4]=r[14];
goto P_0c04dcb0;
P_0c04dcb0: /* original d32e, guest PC 0x0c04dcb0 */
if(!s->budget--) { s->failed_pc=0x0c04dcb0u; return 0; }
r[3]=read(ram,0x0c04dd6cu,4);
goto P_0c04dcb2;
P_0c04dcb2: /* original 65f2, guest PC 0x0c04dcb2 */
if(!s->budget--) { s->failed_pc=0x0c04dcb2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04dcb4;
P_0c04dcb4: /* original 430b, guest PC 0x0c04dcb4 */
if(!s->budget--) { s->failed_pc=0x0c04dcb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c04dcb8u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dcb8u) { target=s->pc; goto dispatch; }
goto P_0c04dcb8;
P_0c04dcb6: /* original 7420, guest PC 0x0c04dcb6 */
if(!s->budget--) { s->failed_pc=0x0c04dcb6u; return 0; }
r[4]+=0x00000020u;
goto P_0c04dcb8;
P_0c04dcb8: /* original e000, guest PC 0x0c04dcb8 */
if(!s->budget--) { s->failed_pc=0x0c04dcb8u; return 0; }
r[0]=0x00000000u;
goto P_0c04dcba;
P_0c04dcba: /* original 2ae2, guest PC 0x0c04dcba */
if(!s->budget--) { s->failed_pc=0x0c04dcbau; return 0; }
write(ram,r[10],r[14],4);
goto P_0c04dcbc;
P_0c04dcbc: /* original 7f30, guest PC 0x0c04dcbc */
if(!s->budget--) { s->failed_pc=0x0c04dcbcu; return 0; }
r[15]+=0x00000030u;
goto P_0c04dcbe;
P_0c04dcbe: /* original 4f16, guest PC 0x0c04dcbe */
if(!s->budget--) { s->failed_pc=0x0c04dcbeu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04dcc0;
P_0c04dcc0: /* original 4f26, guest PC 0x0c04dcc0 */
if(!s->budget--) { s->failed_pc=0x0c04dcc0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04dcc2;
P_0c04dcc2: /* original 69f6, guest PC 0x0c04dcc2 */
if(!s->budget--) { s->failed_pc=0x0c04dcc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04dcc4;
P_0c04dcc4: /* original 6af6, guest PC 0x0c04dcc4 */
if(!s->budget--) { s->failed_pc=0x0c04dcc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04dcc6;
P_0c04dcc6: /* original 6bf6, guest PC 0x0c04dcc6 */
if(!s->budget--) { s->failed_pc=0x0c04dcc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04dcc8;
P_0c04dcc8: /* original 6cf6, guest PC 0x0c04dcc8 */
if(!s->budget--) { s->failed_pc=0x0c04dcc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04dcca;
P_0c04dcca: /* original 6df6, guest PC 0x0c04dcca */
if(!s->budget--) { s->failed_pc=0x0c04dccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04dccc;
P_0c04dccc: /* original 000b, guest PC 0x0c04dccc */
if(!s->budget--) { s->failed_pc=0x0c04dcccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04dcce: /* original 6ef6, guest PC 0x0c04dcce */
if(!s->budget--) { s->failed_pc=0x0c04dcceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04dcd0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04dcd0u; return 0; } return 1;
P_0c04e712: /* original 2fe6, guest PC 0x0c04e712 */
if(!s->budget--) { s->failed_pc=0x0c04e712u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e714;
P_0c04e714: /* original 6e43, guest PC 0x0c04e714 */
if(!s->budget--) { s->failed_pc=0x0c04e714u; return 0; }
r[14]=r[4];
goto P_0c04e716;
P_0c04e716: /* original 2fd6, guest PC 0x0c04e716 */
if(!s->budget--) { s->failed_pc=0x0c04e716u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e718;
P_0c04e718: /* original 6d53, guest PC 0x0c04e718 */
if(!s->budget--) { s->failed_pc=0x0c04e718u; return 0; }
r[13]=r[5];
goto P_0c04e71a;
P_0c04e71a: /* original 2fc6, guest PC 0x0c04e71a */
if(!s->budget--) { s->failed_pc=0x0c04e71au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e71c;
P_0c04e71c: /* original 2fb6, guest PC 0x0c04e71c */
if(!s->budget--) { s->failed_pc=0x0c04e71cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e71e;
P_0c04e71e: /* original 2fa6, guest PC 0x0c04e71e */
if(!s->budget--) { s->failed_pc=0x0c04e71eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e720;
P_0c04e720: /* original 2f96, guest PC 0x0c04e720 */
if(!s->budget--) { s->failed_pc=0x0c04e720u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e722;
P_0c04e722: /* original 4f22, guest PC 0x0c04e722 */
if(!s->budget--) { s->failed_pc=0x0c04e722u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e724;
P_0c04e724: /* original 7fd0, guest PC 0x0c04e724 */
if(!s->budget--) { s->failed_pc=0x0c04e724u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04e726;
P_0c04e726: /* original 2f56, guest PC 0x0c04e726 */
if(!s->budget--) { s->failed_pc=0x0c04e726u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e728;
P_0c04e728: /* original 2fe6, guest PC 0x0c04e728 */
if(!s->budget--) { s->failed_pc=0x0c04e728u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e72a;
P_0c04e72a: /* original d322, guest PC 0x0c04e72a */
if(!s->budget--) { s->failed_pc=0x0c04e72au; return 0; }
r[3]=read(ram,0x0c04e7b4u,4);
goto P_0c04e72c;
P_0c04e72c: /* original d222, guest PC 0x0c04e72c */
if(!s->budget--) { s->failed_pc=0x0c04e72cu; return 0; }
r[2]=read(ram,0x0c04e7b8u,4);
goto P_0c04e72e;
P_0c04e72e: /* original 420b, guest PC 0x0c04e72e */
if(!s->budget--) { s->failed_pc=0x0c04e72eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04e732u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e732u) { target=s->pc; goto dispatch; }
goto P_0c04e732;
P_0c04e730: /* original 2f36, guest PC 0x0c04e730 */
if(!s->budget--) { s->failed_pc=0x0c04e730u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e732;
P_0c04e732: /* original 7f0c, guest PC 0x0c04e732 */
if(!s->budget--) { s->failed_pc=0x0c04e732u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04e734;
P_0c04e734: /* original d321, guest PC 0x0c04e734 */
if(!s->budget--) { s->failed_pc=0x0c04e734u; return 0; }
r[3]=read(ram,0x0c04e7bcu,4);
goto P_0c04e736;
P_0c04e736: /* original 66f3, guest PC 0x0c04e736 */
if(!s->budget--) { s->failed_pc=0x0c04e736u; return 0; }
r[6]=r[15];
goto P_0c04e738;
P_0c04e738: /* original 65d3, guest PC 0x0c04e738 */
if(!s->budget--) { s->failed_pc=0x0c04e738u; return 0; }
r[5]=r[13];
goto P_0c04e73a;
P_0c04e73a: /* original 7604, guest PC 0x0c04e73a */
if(!s->budget--) { s->failed_pc=0x0c04e73au; return 0; }
r[6]+=0x00000004u;
goto P_0c04e73c;
P_0c04e73c: /* original 430b, guest PC 0x0c04e73c */
if(!s->budget--) { s->failed_pc=0x0c04e73cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e740u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e740u) { target=s->pc; goto dispatch; }
goto P_0c04e740;
P_0c04e73e: /* original 64e3, guest PC 0x0c04e73e */
if(!s->budget--) { s->failed_pc=0x0c04e73eu; return 0; }
r[4]=r[14];
goto P_0c04e740;
P_0c04e740: /* original 6c03, guest PC 0x0c04e740 */
if(!s->budget--) { s->failed_pc=0x0c04e740u; return 0; }
r[12]=r[0];
goto P_0c04e742;
P_0c04e742: /* original 4c11, guest PC 0x0c04e742 */
if(!s->budget--) { s->failed_pc=0x0c04e742u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c04e744;
P_0c04e744: /* original 8902, guest PC 0x0c04e744 */
if(!s->budget--) { s->failed_pc=0x0c04e744u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e74c; }
goto P_0c04e746;
P_0c04e746: /* original 9033, guest PC 0x0c04e746 */
if(!s->budget--) { s->failed_pc=0x0c04e746u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e7b0u,2);
goto P_0c04e748;
P_0c04e748: /* original a028, guest PC 0x0c04e748 */
if(!s->budget--) { s->failed_pc=0x0c04e748u; return 0; }
goto P_0c04e79c;
P_0c04e74a: /* original 0009, guest PC 0x0c04e74a */
if(!s->budget--) { s->failed_pc=0x0c04e74au; return 0; }
goto P_0c04e74c;
P_0c04e74c: /* original d31c, guest PC 0x0c04e74c */
if(!s->budget--) { s->failed_pc=0x0c04e74cu; return 0; }
r[3]=read(ram,0x0c04e7c0u,4);
goto P_0c04e74e;
P_0c04e74e: /* original 65c3, guest PC 0x0c04e74e */
if(!s->budget--) { s->failed_pc=0x0c04e74eu; return 0; }
r[5]=r[12];
goto P_0c04e750;
P_0c04e750: /* original 430b, guest PC 0x0c04e750 */
if(!s->budget--) { s->failed_pc=0x0c04e750u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e754u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e754u) { target=s->pc; goto dispatch; }
goto P_0c04e754;
P_0c04e752: /* original 64e3, guest PC 0x0c04e752 */
if(!s->budget--) { s->failed_pc=0x0c04e752u; return 0; }
r[4]=r[14];
goto P_0c04e754;
P_0c04e754: /* original 65d3, guest PC 0x0c04e754 */
if(!s->budget--) { s->failed_pc=0x0c04e754u; return 0; }
r[5]=r[13];
goto P_0c04e756;
P_0c04e756: /* original 2f02, guest PC 0x0c04e756 */
if(!s->budget--) { s->failed_pc=0x0c04e756u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c04e758;
P_0c04e758: /* original d31a, guest PC 0x0c04e758 */
if(!s->budget--) { s->failed_pc=0x0c04e758u; return 0; }
r[3]=read(ram,0x0c04e7c4u,4);
goto P_0c04e75a;
P_0c04e75a: /* original 430b, guest PC 0x0c04e75a */
if(!s->budget--) { s->failed_pc=0x0c04e75au; return 0; }
target=r[3];
r[16]=code_base|0x0c04e75eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e75eu) { target=s->pc; goto dispatch; }
goto P_0c04e75e;
P_0c04e75c: /* original 64e3, guest PC 0x0c04e75c */
if(!s->budget--) { s->failed_pc=0x0c04e75cu; return 0; }
r[4]=r[14];
goto P_0c04e75e;
P_0c04e75e: /* original 2008, guest PC 0x0c04e75e */
if(!s->budget--) { s->failed_pc=0x0c04e75eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e760;
P_0c04e760: /* original 8b12, guest PC 0x0c04e760 */
if(!s->budget--) { s->failed_pc=0x0c04e760u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e788; }
goto P_0c04e762;
P_0c04e762: /* original da19, guest PC 0x0c04e762 */
if(!s->budget--) { s->failed_pc=0x0c04e762u; return 0; }
r[10]=read(ram,0x0c04e7c8u,4);
goto P_0c04e764;
P_0c04e764: /* original 5df4, guest PC 0x0c04e764 */
if(!s->budget--) { s->failed_pc=0x0c04e764u; return 0; }
r[13]=read(ram,r[15]+16,4);
goto P_0c04e766;
P_0c04e766: /* original a00c, guest PC 0x0c04e766 */
if(!s->budget--) { s->failed_pc=0x0c04e766u; return 0; }
r[11]=0x00000000u;
goto P_0c04e782;
P_0c04e768: /* original eb00, guest PC 0x0c04e768 */
if(!s->budget--) { s->failed_pc=0x0c04e768u; return 0; }
r[11]=0x00000000u;
goto P_0c04e76a;
P_0c04e76a: /* original d218, guest PC 0x0c04e76a */
if(!s->budget--) { s->failed_pc=0x0c04e76au; return 0; }
r[2]=read(ram,0x0c04e7ccu,4);
goto P_0c04e76c;
P_0c04e76c: /* original 65d3, guest PC 0x0c04e76c */
if(!s->budget--) { s->failed_pc=0x0c04e76cu; return 0; }
r[5]=r[13];
goto P_0c04e76e;
P_0c04e76e: /* original 420b, guest PC 0x0c04e76e */
if(!s->budget--) { s->failed_pc=0x0c04e76eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04e772u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e772u) { target=s->pc; goto dispatch; }
goto P_0c04e772;
P_0c04e770: /* original 64e3, guest PC 0x0c04e770 */
if(!s->budget--) { s->failed_pc=0x0c04e770u; return 0; }
r[4]=r[14];
goto P_0c04e772;
P_0c04e772: /* original d317, guest PC 0x0c04e772 */
if(!s->budget--) { s->failed_pc=0x0c04e772u; return 0; }
r[3]=read(ram,0x0c04e7d0u,4);
goto P_0c04e774;
P_0c04e774: /* original 65d3, guest PC 0x0c04e774 */
if(!s->budget--) { s->failed_pc=0x0c04e774u; return 0; }
r[5]=r[13];
goto P_0c04e776;
P_0c04e776: /* original 690d, guest PC 0x0c04e776 */
if(!s->budget--) { s->failed_pc=0x0c04e776u; return 0; }
r[9]=r[0]&65535u;
goto P_0c04e778;
P_0c04e778: /* original 66a3, guest PC 0x0c04e778 */
if(!s->budget--) { s->failed_pc=0x0c04e778u; return 0; }
r[6]=r[10];
goto P_0c04e77a;
P_0c04e77a: /* original 430b, guest PC 0x0c04e77a */
if(!s->budget--) { s->failed_pc=0x0c04e77au; return 0; }
target=r[3];
r[16]=code_base|0x0c04e77eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e77eu) { target=s->pc; goto dispatch; }
goto P_0c04e77e;
P_0c04e77c: /* original 64e3, guest PC 0x0c04e77c */
if(!s->budget--) { s->failed_pc=0x0c04e77cu; return 0; }
r[4]=r[14];
goto P_0c04e77e;
P_0c04e77e: /* original 7b01, guest PC 0x0c04e77e */
if(!s->budget--) { s->failed_pc=0x0c04e77eu; return 0; }
r[11]+=0x00000001u;
goto P_0c04e780;
P_0c04e780: /* original 6d93, guest PC 0x0c04e780 */
if(!s->budget--) { s->failed_pc=0x0c04e780u; return 0; }
r[13]=r[9];
goto P_0c04e782;
P_0c04e782: /* original 52fb, guest PC 0x0c04e782 */
if(!s->budget--) { s->failed_pc=0x0c04e782u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c04e784;
P_0c04e784: /* original 3b23, guest PC 0x0c04e784 */
if(!s->budget--) { s->failed_pc=0x0c04e784u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c04e786;
P_0c04e786: /* original 8bf0, guest PC 0x0c04e786 */
if(!s->budget--) { s->failed_pc=0x0c04e786u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e76a; }
goto P_0c04e788;
P_0c04e788: /* original d312, guest PC 0x0c04e788 */
if(!s->budget--) { s->failed_pc=0x0c04e788u; return 0; }
r[3]=read(ram,0x0c04e7d4u,4);
goto P_0c04e78a;
P_0c04e78a: /* original e500, guest PC 0x0c04e78a */
if(!s->budget--) { s->failed_pc=0x0c04e78au; return 0; }
r[5]=0x00000000u;
goto P_0c04e78c;
P_0c04e78c: /* original e620, guest PC 0x0c04e78c */
if(!s->budget--) { s->failed_pc=0x0c04e78cu; return 0; }
r[6]=0x00000020u;
goto P_0c04e78e;
P_0c04e78e: /* original 430b, guest PC 0x0c04e78e */
if(!s->budget--) { s->failed_pc=0x0c04e78eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e792u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e792u) { target=s->pc; goto dispatch; }
goto P_0c04e792;
P_0c04e790: /* original 64f2, guest PC 0x0c04e790 */
if(!s->budget--) { s->failed_pc=0x0c04e790u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04e792;
P_0c04e792: /* original d211, guest PC 0x0c04e792 */
if(!s->budget--) { s->failed_pc=0x0c04e792u; return 0; }
r[2]=read(ram,0x0c04e7d8u,4);
goto P_0c04e794;
P_0c04e794: /* original 65c3, guest PC 0x0c04e794 */
if(!s->budget--) { s->failed_pc=0x0c04e794u; return 0; }
r[5]=r[12];
goto P_0c04e796;
P_0c04e796: /* original 420b, guest PC 0x0c04e796 */
if(!s->budget--) { s->failed_pc=0x0c04e796u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e79au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e79au) { target=s->pc; goto dispatch; }
goto P_0c04e79a;
P_0c04e798: /* original 64e3, guest PC 0x0c04e798 */
if(!s->budget--) { s->failed_pc=0x0c04e798u; return 0; }
r[4]=r[14];
goto P_0c04e79a;
P_0c04e79a: /* original e000, guest PC 0x0c04e79a */
if(!s->budget--) { s->failed_pc=0x0c04e79au; return 0; }
r[0]=0x00000000u;
goto P_0c04e79c;
P_0c04e79c: /* original 7f30, guest PC 0x0c04e79c */
if(!s->budget--) { s->failed_pc=0x0c04e79cu; return 0; }
r[15]+=0x00000030u;
goto P_0c04e79e;
P_0c04e79e: /* original 4f26, guest PC 0x0c04e79e */
if(!s->budget--) { s->failed_pc=0x0c04e79eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e7a0;
P_0c04e7a0: /* original 69f6, guest PC 0x0c04e7a0 */
if(!s->budget--) { s->failed_pc=0x0c04e7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04e7a2;
P_0c04e7a2: /* original 6af6, guest PC 0x0c04e7a2 */
if(!s->budget--) { s->failed_pc=0x0c04e7a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e7a4;
P_0c04e7a4: /* original 6bf6, guest PC 0x0c04e7a4 */
if(!s->budget--) { s->failed_pc=0x0c04e7a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e7a6;
P_0c04e7a6: /* original 6cf6, guest PC 0x0c04e7a6 */
if(!s->budget--) { s->failed_pc=0x0c04e7a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e7a8;
P_0c04e7a8: /* original 6df6, guest PC 0x0c04e7a8 */
if(!s->budget--) { s->failed_pc=0x0c04e7a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e7aa;
P_0c04e7aa: /* original 000b, guest PC 0x0c04e7aa */
if(!s->budget--) { s->failed_pc=0x0c04e7aau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e7ac: /* original 6ef6, guest PC 0x0c04e7ac */
if(!s->budget--) { s->failed_pc=0x0c04e7acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04e7aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e7aeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
