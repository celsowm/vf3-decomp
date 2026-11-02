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
int vf3_away_batch37_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06c7e4u: goto P_0c06c7e4;
case 0x0c06c7e6u: goto P_0c06c7e6;
case 0x0c06c7e8u: goto P_0c06c7e8;
case 0x0c06c7eau: goto P_0c06c7ea;
case 0x0c06c7ecu: goto P_0c06c7ec;
case 0x0c06c7eeu: goto P_0c06c7ee;
case 0x0c06c7f0u: goto P_0c06c7f0;
case 0x0c06c7f2u: goto P_0c06c7f2;
case 0x0c06c7f4u: goto P_0c06c7f4;
case 0x0c06c7f6u: goto P_0c06c7f6;
case 0x0c06c7f8u: goto P_0c06c7f8;
case 0x0c06c7fau: goto P_0c06c7fa;
case 0x0c06c7fcu: goto P_0c06c7fc;
case 0x0c06c7feu: goto P_0c06c7fe;
case 0x0c06c800u: goto P_0c06c800;
case 0x0c06c802u: goto P_0c06c802;
case 0x0c06c804u: goto P_0c06c804;
case 0x0c06c806u: goto P_0c06c806;
case 0x0c06c808u: goto P_0c06c808;
case 0x0c06c80au: goto P_0c06c80a;
case 0x0c06c80cu: goto P_0c06c80c;
case 0x0c06c80eu: goto P_0c06c80e;
case 0x0c06c810u: goto P_0c06c810;
case 0x0c06c812u: goto P_0c06c812;
case 0x0c06c814u: goto P_0c06c814;
case 0x0c06c816u: goto P_0c06c816;
case 0x0c06c818u: goto P_0c06c818;
case 0x0c06c81au: goto P_0c06c81a;
case 0x0c06c81cu: goto P_0c06c81c;
case 0x0c06c81eu: goto P_0c06c81e;
case 0x0c06c820u: goto P_0c06c820;
case 0x0c06c822u: goto P_0c06c822;
case 0x0c06c824u: goto P_0c06c824;
case 0x0c06c826u: goto P_0c06c826;
case 0x0c06c828u: goto P_0c06c828;
case 0x0c06c82au: goto P_0c06c82a;
case 0x0c06c82cu: goto P_0c06c82c;
case 0x0c06c82eu: goto P_0c06c82e;
case 0x0c06c830u: goto P_0c06c830;
case 0x0c06c832u: goto P_0c06c832;
case 0x0c06c834u: goto P_0c06c834;
case 0x0c06c836u: goto P_0c06c836;
case 0x0c06c838u: goto P_0c06c838;
case 0x0c06c83au: goto P_0c06c83a;
case 0x0c06c83cu: goto P_0c06c83c;
case 0x0c06c83eu: goto P_0c06c83e;
case 0x0c06c840u: goto P_0c06c840;
case 0x0c06c842u: goto P_0c06c842;
case 0x0c06c844u: goto P_0c06c844;
case 0x0c06c846u: goto P_0c06c846;
case 0x0c06c848u: goto P_0c06c848;
case 0x0c06c84au: goto P_0c06c84a;
case 0x0c06c84cu: goto P_0c06c84c;
case 0x0c06c84eu: goto P_0c06c84e;
case 0x0c06c850u: goto P_0c06c850;
case 0x0c06c852u: goto P_0c06c852;
case 0x0c06c854u: goto P_0c06c854;
case 0x0c06c856u: goto P_0c06c856;
case 0x0c06c858u: goto P_0c06c858;
case 0x0c06c85au: goto P_0c06c85a;
case 0x0c06c85cu: goto P_0c06c85c;
case 0x0c06c85eu: goto P_0c06c85e;
case 0x0c06c860u: goto P_0c06c860;
case 0x0c06c862u: goto P_0c06c862;
case 0x0c06c864u: goto P_0c06c864;
case 0x0c06c866u: goto P_0c06c866;
case 0x0c06c868u: goto P_0c06c868;
case 0x0c06c86au: goto P_0c06c86a;
case 0x0c06c86cu: goto P_0c06c86c;
case 0x0c06c86eu: goto P_0c06c86e;
case 0x0c06c870u: goto P_0c06c870;
case 0x0c06c872u: goto P_0c06c872;
case 0x0c06c874u: goto P_0c06c874;
case 0x0c06c876u: goto P_0c06c876;
case 0x0c06c878u: goto P_0c06c878;
case 0x0c06c87au: goto P_0c06c87a;
case 0x0c06c87cu: goto P_0c06c87c;
case 0x0c06c87eu: goto P_0c06c87e;
case 0x0c06c880u: goto P_0c06c880;
case 0x0c06c882u: goto P_0c06c882;
case 0x0c06c884u: goto P_0c06c884;
case 0x0c06c886u: goto P_0c06c886;
case 0x0c06c888u: goto P_0c06c888;
case 0x0c06c88au: goto P_0c06c88a;
case 0x0c06c88cu: goto P_0c06c88c;
case 0x0c06c88eu: goto P_0c06c88e;
case 0x0c06c890u: goto P_0c06c890;
case 0x0c06c892u: goto P_0c06c892;
case 0x0c06c894u: goto P_0c06c894;
case 0x0c06c896u: goto P_0c06c896;
case 0x0c06c898u: goto P_0c06c898;
case 0x0c06c89au: goto P_0c06c89a;
case 0x0c06c89cu: goto P_0c06c89c;
case 0x0c06c89eu: goto P_0c06c89e;
case 0x0c06c8a0u: goto P_0c06c8a0;
case 0x0c06c8a2u: goto P_0c06c8a2;
case 0x0c06cae6u: goto P_0c06cae6;
case 0x0c06cae8u: goto P_0c06cae8;
case 0x0c06caeau: goto P_0c06caea;
case 0x0c06caecu: goto P_0c06caec;
case 0x0c06caeeu: goto P_0c06caee;
case 0x0c06caf0u: goto P_0c06caf0;
case 0x0c06caf2u: goto P_0c06caf2;
case 0x0c06caf4u: goto P_0c06caf4;
case 0x0c06caf6u: goto P_0c06caf6;
case 0x0c06caf8u: goto P_0c06caf8;
case 0x0c06cafau: goto P_0c06cafa;
case 0x0c06cafcu: goto P_0c06cafc;
case 0x0c06cafeu: goto P_0c06cafe;
case 0x0c06cb00u: goto P_0c06cb00;
case 0x0c06cb02u: goto P_0c06cb02;
case 0x0c06cb04u: goto P_0c06cb04;
case 0x0c06cb06u: goto P_0c06cb06;
case 0x0c06cb08u: goto P_0c06cb08;
case 0x0c06cb0au: goto P_0c06cb0a;
case 0x0c06cb0cu: goto P_0c06cb0c;
case 0x0c06cb0eu: goto P_0c06cb0e;
case 0x0c06cb10u: goto P_0c06cb10;
case 0x0c06cb12u: goto P_0c06cb12;
case 0x0c06cb14u: goto P_0c06cb14;
case 0x0c06cb16u: goto P_0c06cb16;
case 0x0c06cb18u: goto P_0c06cb18;
case 0x0c06cb1au: goto P_0c06cb1a;
case 0x0c06cb1cu: goto P_0c06cb1c;
case 0x0c06cb1eu: goto P_0c06cb1e;
case 0x0c06cb20u: goto P_0c06cb20;
case 0x0c06cb22u: goto P_0c06cb22;
case 0x0c06cb24u: goto P_0c06cb24;
case 0x0c06cb26u: goto P_0c06cb26;
case 0x0c06cb28u: goto P_0c06cb28;
case 0x0c06cb2au: goto P_0c06cb2a;
case 0x0c06cb2cu: goto P_0c06cb2c;
case 0x0c06cb2eu: goto P_0c06cb2e;
case 0x0c06cb30u: goto P_0c06cb30;
case 0x0c06cb32u: goto P_0c06cb32;
case 0x0c06cb34u: goto P_0c06cb34;
case 0x0c06cb36u: goto P_0c06cb36;
case 0x0c06cb38u: goto P_0c06cb38;
case 0x0c06cb60u: goto P_0c06cb60;
case 0x0c06cb62u: goto P_0c06cb62;
case 0x0c06cb64u: goto P_0c06cb64;
case 0x0c06cb66u: goto P_0c06cb66;
case 0x0c06cb68u: goto P_0c06cb68;
case 0x0c06cb6au: goto P_0c06cb6a;
case 0x0c06cb6cu: goto P_0c06cb6c;
case 0x0c06cb6eu: goto P_0c06cb6e;
case 0x0c06cb70u: goto P_0c06cb70;
case 0x0c06cb72u: goto P_0c06cb72;
case 0x0c06cb74u: goto P_0c06cb74;
case 0x0c06cb76u: goto P_0c06cb76;
case 0x0c06cb78u: goto P_0c06cb78;
case 0x0c06cb7au: goto P_0c06cb7a;
case 0x0c06cb7cu: goto P_0c06cb7c;
case 0x0c06cb7eu: goto P_0c06cb7e;
case 0x0c06cb80u: goto P_0c06cb80;
case 0x0c06cb82u: goto P_0c06cb82;
case 0x0c06cb84u: goto P_0c06cb84;
case 0x0c06cb86u: goto P_0c06cb86;
case 0x0c06cb88u: goto P_0c06cb88;
case 0x0c06cb8au: goto P_0c06cb8a;
case 0x0c06cb8cu: goto P_0c06cb8c;
case 0x0c06cb8eu: goto P_0c06cb8e;
case 0x0c06cb90u: goto P_0c06cb90;
case 0x0c06cb92u: goto P_0c06cb92;
case 0x0c06cb94u: goto P_0c06cb94;
case 0x0c06cb96u: goto P_0c06cb96;
case 0x0c06cb98u: goto P_0c06cb98;
case 0x0c06cb9au: goto P_0c06cb9a;
case 0x0c06cb9cu: goto P_0c06cb9c;
case 0x0c06cb9eu: goto P_0c06cb9e;
case 0x0c06cba0u: goto P_0c06cba0;
case 0x0c06cba2u: goto P_0c06cba2;
case 0x0c06cba4u: goto P_0c06cba4;
case 0x0c06cba6u: goto P_0c06cba6;
case 0x0c06cba8u: goto P_0c06cba8;
case 0x0c06cbaau: goto P_0c06cbaa;
case 0x0c06cbacu: goto P_0c06cbac;
case 0x0c06cbaeu: goto P_0c06cbae;
case 0x0c06cbb0u: goto P_0c06cbb0;
case 0x0c06cbb2u: goto P_0c06cbb2;
case 0x0c06cbb4u: goto P_0c06cbb4;
case 0x0c06cbb6u: goto P_0c06cbb6;
case 0x0c06cbb8u: goto P_0c06cbb8;
case 0x0c06cbbau: goto P_0c06cbba;
case 0x0c06cbbcu: goto P_0c06cbbc;
case 0x0c06cbbeu: goto P_0c06cbbe;
case 0x0c06cbc0u: goto P_0c06cbc0;
case 0x0c06cbc2u: goto P_0c06cbc2;
case 0x0c06cbc4u: goto P_0c06cbc4;
case 0x0c06cbc6u: goto P_0c06cbc6;
case 0x0c06cbc8u: goto P_0c06cbc8;
case 0x0c06cbcau: goto P_0c06cbca;
case 0x0c06cbccu: goto P_0c06cbcc;
case 0x0c06cbceu: goto P_0c06cbce;
case 0x0c06cbd0u: goto P_0c06cbd0;
case 0x0c06cbd2u: goto P_0c06cbd2;
case 0x0c06cbd4u: goto P_0c06cbd4;
case 0x0c06cbd6u: goto P_0c06cbd6;
case 0x0c06cbd8u: goto P_0c06cbd8;
case 0x0c06cbdau: goto P_0c06cbda;
case 0x0c06cbdcu: goto P_0c06cbdc;
case 0x0c06cbdeu: goto P_0c06cbde;
case 0x0c06cbe0u: goto P_0c06cbe0;
case 0x0c06cbe2u: goto P_0c06cbe2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06c7e4: /* original 2fe6, guest PC 0x0c06c7e4 */
if(!s->budget--) { s->failed_pc=0x0c06c7e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7e6;
P_0c06c7e6: /* original 2fd6, guest PC 0x0c06c7e6 */
if(!s->budget--) { s->failed_pc=0x0c06c7e6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7e8;
P_0c06c7e8: /* original 2fc6, guest PC 0x0c06c7e8 */
if(!s->budget--) { s->failed_pc=0x0c06c7e8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7ea;
P_0c06c7ea: /* original 2fb6, guest PC 0x0c06c7ea */
if(!s->budget--) { s->failed_pc=0x0c06c7eau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7ec;
P_0c06c7ec: /* original 2f96, guest PC 0x0c06c7ec */
if(!s->budget--) { s->failed_pc=0x0c06c7ecu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7ee;
P_0c06c7ee: /* original de46, guest PC 0x0c06c7ee */
if(!s->budget--) { s->failed_pc=0x0c06c7eeu; return 0; }
r[14]=read(ram,0x0c06c908u,4);
goto P_0c06c7f0;
P_0c06c7f0: /* original 9081, guest PC 0x0c06c7f0 */
if(!s->budget--) { s->failed_pc=0x0c06c7f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f6u,2);
goto P_0c06c7f2;
P_0c06c7f2: /* original 4f22, guest PC 0x0c06c7f2 */
if(!s->budget--) { s->failed_pc=0x0c06c7f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c7f4;
P_0c06c7f4: /* original 06ec, guest PC 0x0c06c7f4 */
if(!s->budget--) { s->failed_pc=0x0c06c7f4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c7f6;
P_0c06c7f6: /* original 7005, guest PC 0x0c06c7f6 */
if(!s->budget--) { s->failed_pc=0x0c06c7f6u; return 0; }
r[0]+=0x00000005u;
goto P_0c06c7f8;
P_0c06c7f8: /* original 05ec, guest PC 0x0c06c7f8 */
if(!s->budget--) { s->failed_pc=0x0c06c7f8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c7fa;
P_0c06c7fa: /* original 907d, guest PC 0x0c06c7fa */
if(!s->budget--) { s->failed_pc=0x0c06c7fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f8u,2);
goto P_0c06c7fc;
P_0c06c7fc: /* original 7ff8, guest PC 0x0c06c7fc */
if(!s->budget--) { s->failed_pc=0x0c06c7fcu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c7fe;
P_0c06c7fe: /* original d441, guest PC 0x0c06c7fe */
if(!s->budget--) { s->failed_pc=0x0c06c7feu; return 0; }
r[4]=read(ram,0x0c06c904u,4);
goto P_0c06c800;
P_0c06c800: /* original 01ec, guest PC 0x0c06c800 */
if(!s->budget--) { s->failed_pc=0x0c06c800u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c802;
P_0c06c802: /* original 6063, guest PC 0x0c06c802 */
if(!s->budget--) { s->failed_pc=0x0c06c802u; return 0; }
r[0]=r[6];
goto P_0c06c804;
P_0c06c804: /* original 8801, guest PC 0x0c06c804 */
if(!s->budget--) { s->failed_pc=0x0c06c804u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c806;
P_0c06c806: /* original 8d22, guest PC 0x0c06c806 */
if(!s->budget--) { s->failed_pc=0x0c06c806u; return 0; }
cond=r[17]&1u;
r[7]=0x00000004u;
if(cond) { goto P_0c06c84e; }
goto P_0c06c80a;
P_0c06c808: /* original e704, guest PC 0x0c06c808 */
if(!s->budget--) { s->failed_pc=0x0c06c808u; return 0; }
r[7]=0x00000004u;
goto P_0c06c80a;
P_0c06c80a: /* original d340, guest PC 0x0c06c80a */
if(!s->budget--) { s->failed_pc=0x0c06c80au; return 0; }
r[3]=read(ram,0x0c06c90cu,4);
goto P_0c06c80c;
P_0c06c80c: /* original 6013, guest PC 0x0c06c80c */
if(!s->budget--) { s->failed_pc=0x0c06c80cu; return 0; }
r[0]=r[1];
goto P_0c06c80e;
P_0c06c80e: /* original 8801, guest PC 0x0c06c80e */
if(!s->budget--) { s->failed_pc=0x0c06c80eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c810;
P_0c06c810: /* original 6b53, guest PC 0x0c06c810 */
if(!s->budget--) { s->failed_pc=0x0c06c810u; return 0; }
r[11]=r[5];
goto P_0c06c812;
P_0c06c812: /* original 6c32, guest PC 0x0c06c812 */
if(!s->budget--) { s->failed_pc=0x0c06c812u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c06c814;
P_0c06c814: /* original 6d73, guest PC 0x0c06c814 */
if(!s->budget--) { s->failed_pc=0x0c06c814u; return 0; }
r[13]=r[7];
goto P_0c06c816;
P_0c06c816: /* original 8f01, guest PC 0x0c06c816 */
if(!s->budget--) { s->failed_pc=0x0c06c816u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c06c81c; }
goto P_0c06c81a;
P_0c06c818: /* original 7c01, guest PC 0x0c06c818 */
if(!s->budget--) { s->failed_pc=0x0c06c818u; return 0; }
r[12]+=0x00000001u;
goto P_0c06c81a;
P_0c06c81a: /* original ed27, guest PC 0x0c06c81a */
if(!s->budget--) { s->failed_pc=0x0c06c81au; return 0; }
r[13]=0x00000027u;
goto P_0c06c81c;
P_0c06c81c: /* original 63d3, guest PC 0x0c06c81c */
if(!s->budget--) { s->failed_pc=0x0c06c81cu; return 0; }
r[3]=r[13];
goto P_0c06c81e;
P_0c06c81e: /* original 65c3, guest PC 0x0c06c81e */
if(!s->budget--) { s->failed_pc=0x0c06c81eu; return 0; }
r[5]=r[12];
goto P_0c06c820;
P_0c06c820: /* original e207, guest PC 0x0c06c820 */
if(!s->budget--) { s->failed_pc=0x0c06c820u; return 0; }
r[2]=0x00000007u;
goto P_0c06c822;
P_0c06c822: /* original 73fd, guest PC 0x0c06c822 */
if(!s->budget--) { s->failed_pc=0x0c06c822u; return 0; }
r[3]+=0xfffffffdu;
goto P_0c06c824;
P_0c06c824: /* original 452d, guest PC 0x0c06c824 */
if(!s->budget--) { s->failed_pc=0x0c06c824u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?r[5]>>((-r[2])&31u):0):r[5]<<(r[2]&31u);
goto P_0c06c826;
P_0c06c826: /* original 2f32, guest PC 0x0c06c826 */
if(!s->budget--) { s->failed_pc=0x0c06c826u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c828;
P_0c06c828: /* original 1f51, guest PC 0x0c06c828 */
if(!s->budget--) { s->failed_pc=0x0c06c828u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c06c82a;
P_0c06c82a: /* original 4300, guest PC 0x0c06c82a */
if(!s->budget--) { s->failed_pc=0x0c06c82au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06c82c;
P_0c06c82c: /* original 253b, guest PC 0x0c06c82c */
if(!s->budget--) { s->failed_pc=0x0c06c82cu; return 0; }
r[5]|=r[3];
goto P_0c06c82e;
P_0c06c82e: /* original e320, guest PC 0x0c06c82e */
if(!s->budget--) { s->failed_pc=0x0c06c82eu; return 0; }
r[3]=0x00000020u;
goto P_0c06c830;
P_0c06c830: /* original e701, guest PC 0x0c06c830 */
if(!s->budget--) { s->failed_pc=0x0c06c830u; return 0; }
r[7]=0x00000001u;
goto P_0c06c832;
P_0c06c832: /* original 2f36, guest PC 0x0c06c832 */
if(!s->budget--) { s->failed_pc=0x0c06c832u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c834;
P_0c06c834: /* original d236, guest PC 0x0c06c834 */
if(!s->budget--) { s->failed_pc=0x0c06c834u; return 0; }
r[2]=read(ram,0x0c06c910u,4);
goto P_0c06c836;
P_0c06c836: /* original 420b, guest PC 0x0c06c836 */
if(!s->budget--) { s->failed_pc=0x0c06c836u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c83au;
r[6]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c83au) { target=s->pc; goto dispatch; }
goto P_0c06c83a;
P_0c06c838: /* original e618, guest PC 0x0c06c838 */
if(!s->budget--) { s->failed_pc=0x0c06c838u; return 0; }
r[6]=0x00000018u;
goto P_0c06c83a;
P_0c06c83a: /* original 905e, guest PC 0x0c06c83a */
if(!s->budget--) { s->failed_pc=0x0c06c83au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fau,2);
goto P_0c06c83c;
P_0c06c83c: /* original 7f04, guest PC 0x0c06c83c */
if(!s->budget--) { s->failed_pc=0x0c06c83cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c83e;
P_0c06c83e: /* original 64f2, guest PC 0x0c06c83e */
if(!s->budget--) { s->failed_pc=0x0c06c83eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c840;
P_0c06c840: /* original 09ec, guest PC 0x0c06c840 */
if(!s->budget--) { s->failed_pc=0x0c06c840u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c842;
P_0c06c842: /* original 700d, guest PC 0x0c06c842 */
if(!s->budget--) { s->failed_pc=0x0c06c842u; return 0; }
r[0]+=0x0000000du;
goto P_0c06c844;
P_0c06c844: /* original 53f1, guest PC 0x0c06c844 */
if(!s->budget--) { s->failed_pc=0x0c06c844u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06c846;
P_0c06c846: /* original 4400, guest PC 0x0c06c846 */
if(!s->budget--) { s->failed_pc=0x0c06c846u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c848;
P_0c06c848: /* original 0eec, guest PC 0x0c06c848 */
if(!s->budget--) { s->failed_pc=0x0c06c848u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c84a;
P_0c06c84a: /* original a018, guest PC 0x0c06c84a */
if(!s->budget--) { s->failed_pc=0x0c06c84au; return 0; }
r[4]|=r[3];
goto P_0c06c87e;
P_0c06c84c: /* original 243b, guest PC 0x0c06c84c */
if(!s->budget--) { s->failed_pc=0x0c06c84cu; return 0; }
r[4]|=r[3];
goto P_0c06c84e;
P_0c06c84e: /* original 9054, guest PC 0x0c06c84e */
if(!s->budget--) { s->failed_pc=0x0c06c84eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fau,2);
goto P_0c06c850;
P_0c06c850: /* original 6d73, guest PC 0x0c06c850 */
if(!s->budget--) { s->failed_pc=0x0c06c850u; return 0; }
r[13]=r[7];
goto P_0c06c852;
P_0c06c852: /* original d32e, guest PC 0x0c06c852 */
if(!s->budget--) { s->failed_pc=0x0c06c852u; return 0; }
r[3]=read(ram,0x0c06c90cu,4);
goto P_0c06c854;
P_0c06c854: /* original 09ec, guest PC 0x0c06c854 */
if(!s->budget--) { s->failed_pc=0x0c06c854u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c856;
P_0c06c856: /* original 6013, guest PC 0x0c06c856 */
if(!s->budget--) { s->failed_pc=0x0c06c856u; return 0; }
r[0]=r[1];
goto P_0c06c858;
P_0c06c858: /* original 6c32, guest PC 0x0c06c858 */
if(!s->budget--) { s->failed_pc=0x0c06c858u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c06c85a;
P_0c06c85a: /* original 8801, guest PC 0x0c06c85a */
if(!s->budget--) { s->failed_pc=0x0c06c85au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c85c;
P_0c06c85c: /* original 7c01, guest PC 0x0c06c85c */
if(!s->budget--) { s->failed_pc=0x0c06c85cu; return 0; }
r[12]+=0x00000001u;
goto P_0c06c85e;
P_0c06c85e: /* original 8f05, guest PC 0x0c06c85e */
if(!s->budget--) { s->failed_pc=0x0c06c85eu; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(!cond) { goto P_0c06c86c; }
goto P_0c06c862;
P_0c06c860: /* original 6b53, guest PC 0x0c06c860 */
if(!s->budget--) { s->failed_pc=0x0c06c860u; return 0; }
r[11]=r[5];
goto P_0c06c862;
P_0c06c862: /* original 904b, guest PC 0x0c06c862 */
if(!s->budget--) { s->failed_pc=0x0c06c862u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fcu,2);
goto P_0c06c864;
P_0c06c864: /* original ed27, guest PC 0x0c06c864 */
if(!s->budget--) { s->failed_pc=0x0c06c864u; return 0; }
r[13]=0x00000027u;
goto P_0c06c866;
P_0c06c866: /* original 0bec, guest PC 0x0c06c866 */
if(!s->budget--) { s->failed_pc=0x0c06c866u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c868;
P_0c06c868: /* original 7001, guest PC 0x0c06c868 */
if(!s->budget--) { s->failed_pc=0x0c06c868u; return 0; }
r[0]+=0x00000001u;
goto P_0c06c86a;
P_0c06c86a: /* original 09ec, guest PC 0x0c06c86a */
if(!s->budget--) { s->failed_pc=0x0c06c86au; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c86c;
P_0c06c86c: /* original 64d3, guest PC 0x0c06c86c */
if(!s->budget--) { s->failed_pc=0x0c06c86cu; return 0; }
r[4]=r[13];
goto P_0c06c86e;
P_0c06c86e: /* original 9046, guest PC 0x0c06c86e */
if(!s->budget--) { s->failed_pc=0x0c06c86eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8feu,2);
goto P_0c06c870;
P_0c06c870: /* original 62c3, guest PC 0x0c06c870 */
if(!s->budget--) { s->failed_pc=0x0c06c870u; return 0; }
r[2]=r[12];
goto P_0c06c872;
P_0c06c872: /* original e307, guest PC 0x0c06c872 */
if(!s->budget--) { s->failed_pc=0x0c06c872u; return 0; }
r[3]=0x00000007u;
goto P_0c06c874;
P_0c06c874: /* original 74fd, guest PC 0x0c06c874 */
if(!s->budget--) { s->failed_pc=0x0c06c874u; return 0; }
r[4]+=0xfffffffdu;
goto P_0c06c876;
P_0c06c876: /* original 0eec, guest PC 0x0c06c876 */
if(!s->budget--) { s->failed_pc=0x0c06c876u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c878;
P_0c06c878: /* original 423d, guest PC 0x0c06c878 */
if(!s->budget--) { s->failed_pc=0x0c06c878u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c06c87a;
P_0c06c87a: /* original 4400, guest PC 0x0c06c87a */
if(!s->budget--) { s->failed_pc=0x0c06c87au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c87c;
P_0c06c87c: /* original 242b, guest PC 0x0c06c87c */
if(!s->budget--) { s->failed_pc=0x0c06c87cu; return 0; }
r[4]|=r[2];
goto P_0c06c87e;
P_0c06c87e: /* original bd8b, guest PC 0x0c06c87e */
if(!s->budget--) { s->failed_pc=0x0c06c87eu; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06c882u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c882u) { target=s->pc; goto dispatch; }
goto P_0c06c882;
P_0c06c880: /* original 0009, guest PC 0x0c06c880 */
if(!s->budget--) { s->failed_pc=0x0c06c880u; return 0; }
goto P_0c06c882;
P_0c06c882: /* original 2008, guest PC 0x0c06c882 */
if(!s->budget--) { s->failed_pc=0x0c06c882u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c884;
P_0c06c884: /* original 8906, guest PC 0x0c06c884 */
if(!s->budget--) { s->failed_pc=0x0c06c884u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c894; }
goto P_0c06c886;
P_0c06c886: /* original 66b3, guest PC 0x0c06c886 */
if(!s->budget--) { s->failed_pc=0x0c06c886u; return 0; }
r[6]=r[11];
goto P_0c06c888;
P_0c06c888: /* original 65c3, guest PC 0x0c06c888 */
if(!s->budget--) { s->failed_pc=0x0c06c888u; return 0; }
r[5]=r[12];
goto P_0c06c88a;
P_0c06c88a: /* original 2fe6, guest PC 0x0c06c88a */
if(!s->budget--) { s->failed_pc=0x0c06c88au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c88c;
P_0c06c88c: /* original 6793, guest PC 0x0c06c88c */
if(!s->budget--) { s->failed_pc=0x0c06c88cu; return 0; }
r[7]=r[9];
goto P_0c06c88e;
P_0c06c88e: /* original b12a, guest PC 0x0c06c88e */
if(!s->budget--) { s->failed_pc=0x0c06c88eu; return 0; }
target=code_base|0x0c06cae6u; r[16]=code_base|0x0c06c892u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c892u) { target=s->pc; goto dispatch; }
goto P_0c06c892;
P_0c06c890: /* original 64d3, guest PC 0x0c06c890 */
if(!s->budget--) { s->failed_pc=0x0c06c890u; return 0; }
r[4]=r[13];
goto P_0c06c892;
P_0c06c892: /* original 7f04, guest PC 0x0c06c892 */
if(!s->budget--) { s->failed_pc=0x0c06c892u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c894;
P_0c06c894: /* original 7f08, guest PC 0x0c06c894 */
if(!s->budget--) { s->failed_pc=0x0c06c894u; return 0; }
r[15]+=0x00000008u;
goto P_0c06c896;
P_0c06c896: /* original 4f26, guest PC 0x0c06c896 */
if(!s->budget--) { s->failed_pc=0x0c06c896u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c898;
P_0c06c898: /* original 69f6, guest PC 0x0c06c898 */
if(!s->budget--) { s->failed_pc=0x0c06c898u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06c89a;
P_0c06c89a: /* original 6bf6, guest PC 0x0c06c89a */
if(!s->budget--) { s->failed_pc=0x0c06c89au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c89c;
P_0c06c89c: /* original 6cf6, guest PC 0x0c06c89c */
if(!s->budget--) { s->failed_pc=0x0c06c89cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c89e;
P_0c06c89e: /* original 6df6, guest PC 0x0c06c89e */
if(!s->budget--) { s->failed_pc=0x0c06c89eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c8a0;
P_0c06c8a0: /* original 000b, guest PC 0x0c06c8a0 */
if(!s->budget--) { s->failed_pc=0x0c06c8a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c8a2: /* original 6ef6, guest PC 0x0c06c8a2 */
if(!s->budget--) { s->failed_pc=0x0c06c8a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06c8a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c8a4u; return 0; } return 1;
P_0c06cae6: /* original 2fe6, guest PC 0x0c06cae6 */
if(!s->budget--) { s->failed_pc=0x0c06cae6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cae8;
P_0c06cae8: /* original 4400, guest PC 0x0c06cae8 */
if(!s->budget--) { s->failed_pc=0x0c06cae8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06caea;
P_0c06caea: /* original 2fd6, guest PC 0x0c06caea */
if(!s->budget--) { s->failed_pc=0x0c06caeau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caec;
P_0c06caec: /* original e307, guest PC 0x0c06caec */
if(!s->budget--) { s->failed_pc=0x0c06caecu; return 0; }
r[3]=0x00000007u;
goto P_0c06caee;
P_0c06caee: /* original 2fc6, guest PC 0x0c06caee */
if(!s->budget--) { s->failed_pc=0x0c06caeeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf0;
P_0c06caf0: /* original 6d43, guest PC 0x0c06caf0 */
if(!s->budget--) { s->failed_pc=0x0c06caf0u; return 0; }
r[13]=r[4];
goto P_0c06caf2;
P_0c06caf2: /* original 2fb6, guest PC 0x0c06caf2 */
if(!s->budget--) { s->failed_pc=0x0c06caf2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf4;
P_0c06caf4: /* original 453d, guest PC 0x0c06caf4 */
if(!s->budget--) { s->failed_pc=0x0c06caf4u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c06caf6;
P_0c06caf6: /* original 2fa6, guest PC 0x0c06caf6 */
if(!s->budget--) { s->failed_pc=0x0c06caf6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf8;
P_0c06caf8: /* original 2d5b, guest PC 0x0c06caf8 */
if(!s->budget--) { s->failed_pc=0x0c06caf8u; return 0; }
r[13]|=r[5];
goto P_0c06cafa;
P_0c06cafa: /* original 2f96, guest PC 0x0c06cafa */
if(!s->budget--) { s->failed_pc=0x0c06cafau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cafc;
P_0c06cafc: /* original 6e63, guest PC 0x0c06cafc */
if(!s->budget--) { s->failed_pc=0x0c06cafcu; return 0; }
r[14]=r[6];
goto P_0c06cafe;
P_0c06cafe: /* original d514, guest PC 0x0c06cafe */
if(!s->budget--) { s->failed_pc=0x0c06cafeu; return 0; }
r[5]=read(ram,0x0c06cb50u,4);
goto P_0c06cb00;
P_0c06cb00: /* original 901f, guest PC 0x0c06cb00 */
if(!s->budget--) { s->failed_pc=0x0c06cb00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb42u,2);
goto P_0c06cb02;
P_0c06cb02: /* original 4f22, guest PC 0x0c06cb02 */
if(!s->budget--) { s->failed_pc=0x0c06cb02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cb04;
P_0c06cb04: /* original 045c, guest PC 0x0c06cb04 */
if(!s->budget--) { s->failed_pc=0x0c06cb04u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c06cb06;
P_0c06cb06: /* original da13, guest PC 0x0c06cb06 */
if(!s->budget--) { s->failed_pc=0x0c06cb06u; return 0; }
r[10]=read(ram,0x0c06cb54u,4);
goto P_0c06cb08;
P_0c06cb08: /* original 6043, guest PC 0x0c06cb08 */
if(!s->budget--) { s->failed_pc=0x0c06cb08u; return 0; }
r[0]=r[4];
goto P_0c06cb0a;
P_0c06cb0a: /* original 5bf7, guest PC 0x0c06cb0a */
if(!s->budget--) { s->failed_pc=0x0c06cb0au; return 0; }
r[11]=read(ram,r[15]+28,4);
goto P_0c06cb0c;
P_0c06cb0c: /* original 8801, guest PC 0x0c06cb0c */
if(!s->budget--) { s->failed_pc=0x0c06cb0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb0e;
P_0c06cb0e: /* original 8d2e, guest PC 0x0c06cb0e */
if(!s->budget--) { s->failed_pc=0x0c06cb0eu; return 0; }
cond=r[17]&1u;
r[9]=r[7];
if(cond) { goto P_0c06cb6e; }
goto P_0c06cb12;
P_0c06cb10: /* original 6973, guest PC 0x0c06cb10 */
if(!s->budget--) { s->failed_pc=0x0c06cb10u; return 0; }
r[9]=r[7];
goto P_0c06cb12;
P_0c06cb12: /* original 9017, guest PC 0x0c06cb12 */
if(!s->budget--) { s->failed_pc=0x0c06cb12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb44u,2);
goto P_0c06cb14;
P_0c06cb14: /* original d411, guest PC 0x0c06cb14 */
if(!s->budget--) { s->failed_pc=0x0c06cb14u; return 0; }
r[4]=read(ram,0x0c06cb5cu,4);
goto P_0c06cb16;
P_0c06cb16: /* original 0c5c, guest PC 0x0c06cb16 */
if(!s->budget--) { s->failed_pc=0x0c06cb16u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c06cb18;
P_0c06cb18: /* original d50f, guest PC 0x0c06cb18 */
if(!s->budget--) { s->failed_pc=0x0c06cb18u; return 0; }
r[5]=read(ram,0x0c06cb58u,4);
goto P_0c06cb1a;
P_0c06cb1a: /* original 60c3, guest PC 0x0c06cb1a */
if(!s->budget--) { s->failed_pc=0x0c06cb1au; return 0; }
r[0]=r[12];
goto P_0c06cb1c;
P_0c06cb1c: /* original 8801, guest PC 0x0c06cb1c */
if(!s->budget--) { s->failed_pc=0x0c06cb1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb1e;
P_0c06cb1e: /* original 8d04, guest PC 0x0c06cb1e */
if(!s->budget--) { s->failed_pc=0x0c06cb1eu; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(cond) { goto P_0c06cb2a; }
goto P_0c06cb22;
P_0c06cb20: /* original e601, guest PC 0x0c06cb20 */
if(!s->budget--) { s->failed_pc=0x0c06cb20u; return 0; }
r[6]=0x00000001u;
goto P_0c06cb22;
P_0c06cb22: /* original 3c90, guest PC 0x0c06cb22 */
if(!s->budget--) { s->failed_pc=0x0c06cb22u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[9])!=0);
goto P_0c06cb24;
P_0c06cb24: /* original 8901, guest PC 0x0c06cb24 */
if(!s->budget--) { s->failed_pc=0x0c06cb24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cb2a; }
goto P_0c06cb26;
P_0c06cb26: /* original 2998, guest PC 0x0c06cb26 */
if(!s->budget--) { s->failed_pc=0x0c06cb26u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c06cb28;
P_0c06cb28: /* original 8b37, guest PC 0x0c06cb28 */
if(!s->budget--) { s->failed_pc=0x0c06cb28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cb9a; }
goto P_0c06cb2a;
P_0c06cb2a: /* original 60b3, guest PC 0x0c06cb2a */
if(!s->budget--) { s->failed_pc=0x0c06cb2au; return 0; }
r[0]=r[11];
goto P_0c06cb2c;
P_0c06cb2c: /* original 8801, guest PC 0x0c06cb2c */
if(!s->budget--) { s->failed_pc=0x0c06cb2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb2e;
P_0c06cb2e: /* original 8925, guest PC 0x0c06cb2e */
if(!s->budget--) { s->failed_pc=0x0c06cb2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cb7c; }
goto P_0c06cb30;
P_0c06cb30: /* original 3e66, guest PC 0x0c06cb30 */
if(!s->budget--) { s->failed_pc=0x0c06cb30u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cb32;
P_0c06cb32: /* original 8d15, guest PC 0x0c06cb32 */
if(!s->budget--) { s->failed_pc=0x0c06cb32u; return 0; }
cond=r[17]&1u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(cond) { goto P_0c06cb60; }
goto P_0c06cb36;
P_0c06cb34: /* original 2fb6, guest PC 0x0c06cb34 */
if(!s->budget--) { s->failed_pc=0x0c06cb34u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb36;
P_0c06cb36: /* original a014, guest PC 0x0c06cb36 */
if(!s->budget--) { s->failed_pc=0x0c06cb36u; return 0; }
r[6]=r[5];
goto P_0c06cb62;
P_0c06cb38: /* original 6653, guest PC 0x0c06cb38 */
if(!s->budget--) { s->failed_pc=0x0c06cb38u; return 0; }
r[6]=r[5];
if(!vf3_matrix_family(0x0c06cb3au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06cb3au; return 0; } return 1;
P_0c06cb60: /* original 6643, guest PC 0x0c06cb60 */
if(!s->budget--) { s->failed_pc=0x0c06cb60u; return 0; }
r[6]=r[4];
goto P_0c06cb62;
P_0c06cb62: /* original 65a3, guest PC 0x0c06cb62 */
if(!s->budget--) { s->failed_pc=0x0c06cb62u; return 0; }
r[5]=r[10];
goto P_0c06cb64;
P_0c06cb64: /* original 67e3, guest PC 0x0c06cb64 */
if(!s->budget--) { s->failed_pc=0x0c06cb64u; return 0; }
r[7]=r[14];
goto P_0c06cb66;
P_0c06cb66: /* original bc4e, guest PC 0x0c06cb66 */
if(!s->budget--) { s->failed_pc=0x0c06cb66u; return 0; }
target=code_base|0x0c06c406u; r[16]=code_base|0x0c06cb6au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cb6au) { target=s->pc; goto dispatch; }
goto P_0c06cb6a;
P_0c06cb68: /* original 64d3, guest PC 0x0c06cb68 */
if(!s->budget--) { s->failed_pc=0x0c06cb68u; return 0; }
r[4]=r[13];
goto P_0c06cb6a;
P_0c06cb6a: /* original a033, guest PC 0x0c06cb6a */
if(!s->budget--) { s->failed_pc=0x0c06cb6au; return 0; }
r[15]+=0x00000004u;
goto P_0c06cbd4;
P_0c06cb6c: /* original 7f04, guest PC 0x0c06cb6c */
if(!s->budget--) { s->failed_pc=0x0c06cb6cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06cb6e;
P_0c06cb6e: /* original d23c, guest PC 0x0c06cb6e */
if(!s->budget--) { s->failed_pc=0x0c06cb6eu; return 0; }
r[2]=read(ram,0x0c06cc60u,4);
goto P_0c06cb70;
P_0c06cb70: /* original e601, guest PC 0x0c06cb70 */
if(!s->budget--) { s->failed_pc=0x0c06cb70u; return 0; }
r[6]=0x00000001u;
goto P_0c06cb72;
P_0c06cb72: /* original d53a, guest PC 0x0c06cb72 */
if(!s->budget--) { s->failed_pc=0x0c06cb72u; return 0; }
r[5]=read(ram,0x0c06cc5cu,4);
goto P_0c06cb74;
P_0c06cb74: /* original 420b, guest PC 0x0c06cb74 */
if(!s->budget--) { s->failed_pc=0x0c06cb74u; return 0; }
target=r[2];
r[16]=code_base|0x0c06cb78u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cb78u) { target=s->pc; goto dispatch; }
goto P_0c06cb78;
P_0c06cb76: /* original 64d3, guest PC 0x0c06cb76 */
if(!s->budget--) { s->failed_pc=0x0c06cb76u; return 0; }
r[4]=r[13];
goto P_0c06cb78;
P_0c06cb78: /* original a02c, guest PC 0x0c06cb78 */
if(!s->budget--) { s->failed_pc=0x0c06cb78u; return 0; }
goto P_0c06cbd4;
P_0c06cb7a: /* original 0009, guest PC 0x0c06cb7a */
if(!s->budget--) { s->failed_pc=0x0c06cb7au; return 0; }
goto P_0c06cb7c;
P_0c06cb7c: /* original 3e66, guest PC 0x0c06cb7c */
if(!s->budget--) { s->failed_pc=0x0c06cb7cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cb7e;
P_0c06cb7e: /* original 8f02, guest PC 0x0c06cb7e */
if(!s->budget--) { s->failed_pc=0x0c06cb7eu; return 0; }
cond=r[17]&1u;
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
if(!cond) { goto P_0c06cb86; }
goto P_0c06cb82;
P_0c06cb80: /* original 2fe6, guest PC 0x0c06cb80 */
if(!s->budget--) { s->failed_pc=0x0c06cb80u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb82;
P_0c06cb82: /* original a001, guest PC 0x0c06cb82 */
if(!s->budget--) { s->failed_pc=0x0c06cb82u; return 0; }
r[6]=r[4];
goto P_0c06cb88;
P_0c06cb84: /* original 6643, guest PC 0x0c06cb84 */
if(!s->budget--) { s->failed_pc=0x0c06cb84u; return 0; }
r[6]=r[4];
goto P_0c06cb86;
P_0c06cb86: /* original 6653, guest PC 0x0c06cb86 */
if(!s->budget--) { s->failed_pc=0x0c06cb86u; return 0; }
r[6]=r[5];
goto P_0c06cb88;
P_0c06cb88: /* original 2f66, guest PC 0x0c06cb88 */
if(!s->budget--) { s->failed_pc=0x0c06cb88u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb8a;
P_0c06cb8a: /* original 2fa6, guest PC 0x0c06cb8a */
if(!s->budget--) { s->failed_pc=0x0c06cb8au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb8c;
P_0c06cb8c: /* original d335, guest PC 0x0c06cb8c */
if(!s->budget--) { s->failed_pc=0x0c06cb8cu; return 0; }
r[3]=read(ram,0x0c06cc64u,4);
goto P_0c06cb8e;
P_0c06cb8e: /* original 2f36, guest PC 0x0c06cb8e */
if(!s->budget--) { s->failed_pc=0x0c06cb8eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb90;
P_0c06cb90: /* original d235, guest PC 0x0c06cb90 */
if(!s->budget--) { s->failed_pc=0x0c06cb90u; return 0; }
r[2]=read(ram,0x0c06cc68u,4);
goto P_0c06cb92;
P_0c06cb92: /* original 420b, guest PC 0x0c06cb92 */
if(!s->budget--) { s->failed_pc=0x0c06cb92u; return 0; }
target=r[2];
r[16]=code_base|0x0c06cb96u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cb96u) { target=s->pc; goto dispatch; }
goto P_0c06cb96;
P_0c06cb94: /* original 64d3, guest PC 0x0c06cb94 */
if(!s->budget--) { s->failed_pc=0x0c06cb94u; return 0; }
r[4]=r[13];
goto P_0c06cb96;
P_0c06cb96: /* original a010, guest PC 0x0c06cb96 */
if(!s->budget--) { s->failed_pc=0x0c06cb96u; return 0; }
goto P_0c06cbba;
P_0c06cb98: /* original 0009, guest PC 0x0c06cb98 */
if(!s->budget--) { s->failed_pc=0x0c06cb98u; return 0; }
goto P_0c06cb9a;
P_0c06cb9a: /* original 60b3, guest PC 0x0c06cb9a */
if(!s->budget--) { s->failed_pc=0x0c06cb9au; return 0; }
r[0]=r[11];
goto P_0c06cb9c;
P_0c06cb9c: /* original d733, guest PC 0x0c06cb9c */
if(!s->budget--) { s->failed_pc=0x0c06cb9cu; return 0; }
r[7]=read(ram,0x0c06cc6cu,4);
goto P_0c06cb9e;
P_0c06cb9e: /* original 8801, guest PC 0x0c06cb9e */
if(!s->budget--) { s->failed_pc=0x0c06cb9eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cba0;
P_0c06cba0: /* original 890d, guest PC 0x0c06cba0 */
if(!s->budget--) { s->failed_pc=0x0c06cba0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cbbe; }
goto P_0c06cba2;
P_0c06cba2: /* original 3e66, guest PC 0x0c06cba2 */
if(!s->budget--) { s->failed_pc=0x0c06cba2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cba4;
P_0c06cba4: /* original 8d02, guest PC 0x0c06cba4 */
if(!s->budget--) { s->failed_pc=0x0c06cba4u; return 0; }
cond=r[17]&1u;
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
if(cond) { goto P_0c06cbac; }
goto P_0c06cba8;
P_0c06cba6: /* original 2fc6, guest PC 0x0c06cba6 */
if(!s->budget--) { s->failed_pc=0x0c06cba6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cba8;
P_0c06cba8: /* original a001, guest PC 0x0c06cba8 */
if(!s->budget--) { s->failed_pc=0x0c06cba8u; return 0; }
r[6]=r[5];
goto P_0c06cbae;
P_0c06cbaa: /* original 6653, guest PC 0x0c06cbaa */
if(!s->budget--) { s->failed_pc=0x0c06cbaau; return 0; }
r[6]=r[5];
goto P_0c06cbac;
P_0c06cbac: /* original 6643, guest PC 0x0c06cbac */
if(!s->budget--) { s->failed_pc=0x0c06cbacu; return 0; }
r[6]=r[4];
goto P_0c06cbae;
P_0c06cbae: /* original 2f96, guest PC 0x0c06cbae */
if(!s->budget--) { s->failed_pc=0x0c06cbaeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb0;
P_0c06cbb0: /* original 65a3, guest PC 0x0c06cbb0 */
if(!s->budget--) { s->failed_pc=0x0c06cbb0u; return 0; }
r[5]=r[10];
goto P_0c06cbb2;
P_0c06cbb2: /* original 2fb6, guest PC 0x0c06cbb2 */
if(!s->budget--) { s->failed_pc=0x0c06cbb2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb4;
P_0c06cbb4: /* original 2fe6, guest PC 0x0c06cbb4 */
if(!s->budget--) { s->failed_pc=0x0c06cbb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb6;
P_0c06cbb6: /* original b015, guest PC 0x0c06cbb6 */
if(!s->budget--) { s->failed_pc=0x0c06cbb6u; return 0; }
target=code_base|0x0c06cbe4u; r[16]=code_base|0x0c06cbbau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cbbau) { target=s->pc; goto dispatch; }
goto P_0c06cbba;
P_0c06cbb8: /* original 64d3, guest PC 0x0c06cbb8 */
if(!s->budget--) { s->failed_pc=0x0c06cbb8u; return 0; }
r[4]=r[13];
goto P_0c06cbba;
P_0c06cbba: /* original a00b, guest PC 0x0c06cbba */
if(!s->budget--) { s->failed_pc=0x0c06cbbau; return 0; }
r[15]+=0x00000010u;
goto P_0c06cbd4;
P_0c06cbbc: /* original 7f10, guest PC 0x0c06cbbc */
if(!s->budget--) { s->failed_pc=0x0c06cbbcu; return 0; }
r[15]+=0x00000010u;
goto P_0c06cbbe;
P_0c06cbbe: /* original 2fc6, guest PC 0x0c06cbbe */
if(!s->budget--) { s->failed_pc=0x0c06cbbeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc0;
P_0c06cbc0: /* original 2f96, guest PC 0x0c06cbc0 */
if(!s->budget--) { s->failed_pc=0x0c06cbc0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc2;
P_0c06cbc2: /* original 2f76, guest PC 0x0c06cbc2 */
if(!s->budget--) { s->failed_pc=0x0c06cbc2u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc4;
P_0c06cbc4: /* original 2fe6, guest PC 0x0c06cbc4 */
if(!s->budget--) { s->failed_pc=0x0c06cbc4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc6;
P_0c06cbc6: /* original 2fa6, guest PC 0x0c06cbc6 */
if(!s->budget--) { s->failed_pc=0x0c06cbc6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc8;
P_0c06cbc8: /* original d229, guest PC 0x0c06cbc8 */
if(!s->budget--) { s->failed_pc=0x0c06cbc8u; return 0; }
r[2]=read(ram,0x0c06cc70u,4);
goto P_0c06cbca;
P_0c06cbca: /* original 2f26, guest PC 0x0c06cbca */
if(!s->budget--) { s->failed_pc=0x0c06cbcau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbcc;
P_0c06cbcc: /* original d326, guest PC 0x0c06cbcc */
if(!s->budget--) { s->failed_pc=0x0c06cbccu; return 0; }
r[3]=read(ram,0x0c06cc68u,4);
goto P_0c06cbce;
P_0c06cbce: /* original 430b, guest PC 0x0c06cbce */
if(!s->budget--) { s->failed_pc=0x0c06cbceu; return 0; }
target=r[3];
r[16]=code_base|0x0c06cbd2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cbd2u) { target=s->pc; goto dispatch; }
goto P_0c06cbd2;
P_0c06cbd0: /* original 64d3, guest PC 0x0c06cbd0 */
if(!s->budget--) { s->failed_pc=0x0c06cbd0u; return 0; }
r[4]=r[13];
goto P_0c06cbd2;
P_0c06cbd2: /* original 7f18, guest PC 0x0c06cbd2 */
if(!s->budget--) { s->failed_pc=0x0c06cbd2u; return 0; }
r[15]+=0x00000018u;
goto P_0c06cbd4;
P_0c06cbd4: /* original 4f26, guest PC 0x0c06cbd4 */
if(!s->budget--) { s->failed_pc=0x0c06cbd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cbd6;
P_0c06cbd6: /* original 69f6, guest PC 0x0c06cbd6 */
if(!s->budget--) { s->failed_pc=0x0c06cbd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06cbd8;
P_0c06cbd8: /* original 6af6, guest PC 0x0c06cbd8 */
if(!s->budget--) { s->failed_pc=0x0c06cbd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06cbda;
P_0c06cbda: /* original 6bf6, guest PC 0x0c06cbda */
if(!s->budget--) { s->failed_pc=0x0c06cbdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06cbdc;
P_0c06cbdc: /* original 6cf6, guest PC 0x0c06cbdc */
if(!s->budget--) { s->failed_pc=0x0c06cbdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cbde;
P_0c06cbde: /* original 6df6, guest PC 0x0c06cbde */
if(!s->budget--) { s->failed_pc=0x0c06cbdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cbe0;
P_0c06cbe0: /* original 000b, guest PC 0x0c06cbe0 */
if(!s->budget--) { s->failed_pc=0x0c06cbe0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cbe2: /* original 6ef6, guest PC 0x0c06cbe2 */
if(!s->budget--) { s->failed_pc=0x0c06cbe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06cbe4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
