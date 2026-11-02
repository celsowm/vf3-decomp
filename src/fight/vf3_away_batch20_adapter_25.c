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
int vf3_away_batch20_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09d9eau: goto P_0c09d9ea;
case 0x0c09d9ecu: goto P_0c09d9ec;
case 0x0c09d9eeu: goto P_0c09d9ee;
case 0x0c09d9f0u: goto P_0c09d9f0;
case 0x0c09d9f2u: goto P_0c09d9f2;
case 0x0c09d9f4u: goto P_0c09d9f4;
case 0x0c09d9f6u: goto P_0c09d9f6;
case 0x0c09d9f8u: goto P_0c09d9f8;
case 0x0c09d9fau: goto P_0c09d9fa;
case 0x0c09d9fcu: goto P_0c09d9fc;
case 0x0c09d9feu: goto P_0c09d9fe;
case 0x0c09da00u: goto P_0c09da00;
case 0x0c09da02u: goto P_0c09da02;
case 0x0c09da04u: goto P_0c09da04;
case 0x0c09da06u: goto P_0c09da06;
case 0x0c09da08u: goto P_0c09da08;
case 0x0c09da0au: goto P_0c09da0a;
case 0x0c09da0cu: goto P_0c09da0c;
case 0x0c09da0eu: goto P_0c09da0e;
case 0x0c09da10u: goto P_0c09da10;
case 0x0c09da12u: goto P_0c09da12;
case 0x0c09da14u: goto P_0c09da14;
case 0x0c09da16u: goto P_0c09da16;
case 0x0c09da18u: goto P_0c09da18;
case 0x0c09da1au: goto P_0c09da1a;
case 0x0c09da1cu: goto P_0c09da1c;
case 0x0c09da1eu: goto P_0c09da1e;
case 0x0c09da20u: goto P_0c09da20;
case 0x0c09da22u: goto P_0c09da22;
case 0x0c09da24u: goto P_0c09da24;
case 0x0c09da26u: goto P_0c09da26;
case 0x0c09da28u: goto P_0c09da28;
case 0x0c09da2au: goto P_0c09da2a;
case 0x0c09da2cu: goto P_0c09da2c;
case 0x0c09da2eu: goto P_0c09da2e;
case 0x0c09da30u: goto P_0c09da30;
case 0x0c09da32u: goto P_0c09da32;
case 0x0c09da34u: goto P_0c09da34;
case 0x0c09da36u: goto P_0c09da36;
case 0x0c09da38u: goto P_0c09da38;
case 0x0c09da3au: goto P_0c09da3a;
case 0x0c09da3cu: goto P_0c09da3c;
case 0x0c09da3eu: goto P_0c09da3e;
case 0x0c09da40u: goto P_0c09da40;
case 0x0c09da42u: goto P_0c09da42;
case 0x0c09da44u: goto P_0c09da44;
case 0x0c09da46u: goto P_0c09da46;
case 0x0c09da48u: goto P_0c09da48;
case 0x0c09da4au: goto P_0c09da4a;
case 0x0c09da4cu: goto P_0c09da4c;
case 0x0c09da4eu: goto P_0c09da4e;
case 0x0c09da50u: goto P_0c09da50;
case 0x0c09da52u: goto P_0c09da52;
case 0x0c09da54u: goto P_0c09da54;
case 0x0c09da56u: goto P_0c09da56;
case 0x0c09da58u: goto P_0c09da58;
case 0x0c09da5au: goto P_0c09da5a;
case 0x0c09da5cu: goto P_0c09da5c;
case 0x0c09da5eu: goto P_0c09da5e;
case 0x0c09da60u: goto P_0c09da60;
case 0x0c09da62u: goto P_0c09da62;
case 0x0c09da64u: goto P_0c09da64;
case 0x0c09da66u: goto P_0c09da66;
case 0x0c09da68u: goto P_0c09da68;
case 0x0c09da6au: goto P_0c09da6a;
case 0x0c09da6cu: goto P_0c09da6c;
case 0x0c09da6eu: goto P_0c09da6e;
case 0x0c09da70u: goto P_0c09da70;
case 0x0c09da72u: goto P_0c09da72;
case 0x0c09da74u: goto P_0c09da74;
case 0x0c09da76u: goto P_0c09da76;
case 0x0c09da78u: goto P_0c09da78;
case 0x0c09da7au: goto P_0c09da7a;
case 0x0c09da7cu: goto P_0c09da7c;
case 0x0c09da7eu: goto P_0c09da7e;
case 0x0c09da80u: goto P_0c09da80;
case 0x0c09da82u: goto P_0c09da82;
case 0x0c09da84u: goto P_0c09da84;
case 0x0c09da86u: goto P_0c09da86;
case 0x0c09da88u: goto P_0c09da88;
case 0x0c09da8au: goto P_0c09da8a;
case 0x0c09da8cu: goto P_0c09da8c;
case 0x0c09da8eu: goto P_0c09da8e;
case 0x0c09da90u: goto P_0c09da90;
case 0x0c09da92u: goto P_0c09da92;
case 0x0c09da94u: goto P_0c09da94;
case 0x0c09da96u: goto P_0c09da96;
case 0x0c09da98u: goto P_0c09da98;
case 0x0c09da9au: goto P_0c09da9a;
case 0x0c09da9cu: goto P_0c09da9c;
case 0x0c09da9eu: goto P_0c09da9e;
case 0x0c09daa0u: goto P_0c09daa0;
case 0x0c09daa2u: goto P_0c09daa2;
case 0x0c09daa4u: goto P_0c09daa4;
case 0x0c09daa6u: goto P_0c09daa6;
case 0x0c09daa8u: goto P_0c09daa8;
case 0x0c09daaau: goto P_0c09daaa;
case 0x0c09daacu: goto P_0c09daac;
case 0x0c09daaeu: goto P_0c09daae;
case 0x0c09dab0u: goto P_0c09dab0;
case 0x0c09dab2u: goto P_0c09dab2;
case 0x0c09dab4u: goto P_0c09dab4;
case 0x0c09dab6u: goto P_0c09dab6;
case 0x0c09dab8u: goto P_0c09dab8;
case 0x0c09dabau: goto P_0c09daba;
case 0x0c09dabcu: goto P_0c09dabc;
case 0x0c09dabeu: goto P_0c09dabe;
case 0x0c09dac0u: goto P_0c09dac0;
case 0x0c09dac2u: goto P_0c09dac2;
case 0x0c09dac4u: goto P_0c09dac4;
case 0x0c09dac6u: goto P_0c09dac6;
case 0x0c09dac8u: goto P_0c09dac8;
case 0x0c09dacau: goto P_0c09daca;
case 0x0c09daf4u: goto P_0c09daf4;
case 0x0c09daf6u: goto P_0c09daf6;
case 0x0c09daf8u: goto P_0c09daf8;
case 0x0c09dafau: goto P_0c09dafa;
case 0x0c09dafcu: goto P_0c09dafc;
case 0x0c09dafeu: goto P_0c09dafe;
case 0x0c09db00u: goto P_0c09db00;
case 0x0c09db02u: goto P_0c09db02;
case 0x0c09db04u: goto P_0c09db04;
case 0x0c09db06u: goto P_0c09db06;
case 0x0c09db08u: goto P_0c09db08;
case 0x0c09db0au: goto P_0c09db0a;
case 0x0c09db0cu: goto P_0c09db0c;
case 0x0c09db0eu: goto P_0c09db0e;
case 0x0c09db10u: goto P_0c09db10;
case 0x0c09db12u: goto P_0c09db12;
case 0x0c09db14u: goto P_0c09db14;
case 0x0c09db16u: goto P_0c09db16;
case 0x0c09db18u: goto P_0c09db18;
case 0x0c09db1au: goto P_0c09db1a;
case 0x0c09db1cu: goto P_0c09db1c;
case 0x0c09db1eu: goto P_0c09db1e;
case 0x0c09db20u: goto P_0c09db20;
case 0x0c09db22u: goto P_0c09db22;
case 0x0c09db24u: goto P_0c09db24;
case 0x0c09db26u: goto P_0c09db26;
case 0x0c09db28u: goto P_0c09db28;
case 0x0c09db2au: goto P_0c09db2a;
case 0x0c09db2cu: goto P_0c09db2c;
case 0x0c09db2eu: goto P_0c09db2e;
case 0x0c09db30u: goto P_0c09db30;
case 0x0c09db32u: goto P_0c09db32;
case 0x0c09db34u: goto P_0c09db34;
case 0x0c09db36u: goto P_0c09db36;
case 0x0c09db38u: goto P_0c09db38;
case 0x0c09db3au: goto P_0c09db3a;
case 0x0c09db3cu: goto P_0c09db3c;
case 0x0c09db3eu: goto P_0c09db3e;
case 0x0c09db40u: goto P_0c09db40;
case 0x0c09db42u: goto P_0c09db42;
case 0x0c09db44u: goto P_0c09db44;
case 0x0c09db46u: goto P_0c09db46;
case 0x0c09db48u: goto P_0c09db48;
case 0x0c09db4au: goto P_0c09db4a;
case 0x0c09db4cu: goto P_0c09db4c;
case 0x0c09db4eu: goto P_0c09db4e;
case 0x0c09db50u: goto P_0c09db50;
case 0x0c09db52u: goto P_0c09db52;
case 0x0c09db54u: goto P_0c09db54;
case 0x0c09db56u: goto P_0c09db56;
case 0x0c09db58u: goto P_0c09db58;
case 0x0c09db5au: goto P_0c09db5a;
case 0x0c09db5cu: goto P_0c09db5c;
case 0x0c09db5eu: goto P_0c09db5e;
case 0x0c09db60u: goto P_0c09db60;
case 0x0c09db62u: goto P_0c09db62;
case 0x0c09db64u: goto P_0c09db64;
case 0x0c09db66u: goto P_0c09db66;
case 0x0c09db68u: goto P_0c09db68;
case 0x0c09db6au: goto P_0c09db6a;
case 0x0c09db6cu: goto P_0c09db6c;
case 0x0c09db6eu: goto P_0c09db6e;
case 0x0c09db70u: goto P_0c09db70;
case 0x0c09db72u: goto P_0c09db72;
case 0x0c09db74u: goto P_0c09db74;
case 0x0c09db76u: goto P_0c09db76;
case 0x0c09db78u: goto P_0c09db78;
case 0x0c09db7au: goto P_0c09db7a;
case 0x0c09db7cu: goto P_0c09db7c;
case 0x0c09db7eu: goto P_0c09db7e;
case 0x0c09db80u: goto P_0c09db80;
case 0x0c09db82u: goto P_0c09db82;
case 0x0c09db84u: goto P_0c09db84;
case 0x0c09db86u: goto P_0c09db86;
case 0x0c09db88u: goto P_0c09db88;
case 0x0c09db8au: goto P_0c09db8a;
case 0x0c09db8cu: goto P_0c09db8c;
case 0x0c09db8eu: goto P_0c09db8e;
case 0x0c09db90u: goto P_0c09db90;
case 0x0c09db92u: goto P_0c09db92;
case 0x0c09db94u: goto P_0c09db94;
case 0x0c09db96u: goto P_0c09db96;
case 0x0c09db98u: goto P_0c09db98;
case 0x0c09db9au: goto P_0c09db9a;
case 0x0c09db9cu: goto P_0c09db9c;
case 0x0c09db9eu: goto P_0c09db9e;
case 0x0c09dba0u: goto P_0c09dba0;
case 0x0c09dba2u: goto P_0c09dba2;
case 0x0c09dba4u: goto P_0c09dba4;
case 0x0c09dba6u: goto P_0c09dba6;
case 0x0c09dba8u: goto P_0c09dba8;
case 0x0c09dbaau: goto P_0c09dbaa;
case 0x0c09dbacu: goto P_0c09dbac;
case 0x0c09dbaeu: goto P_0c09dbae;
case 0x0c09dbb0u: goto P_0c09dbb0;
case 0x0c09dbb2u: goto P_0c09dbb2;
case 0x0c09dbb4u: goto P_0c09dbb4;
case 0x0c09dbb6u: goto P_0c09dbb6;
case 0x0c09dbb8u: goto P_0c09dbb8;
case 0x0c09dbbau: goto P_0c09dbba;
case 0x0c09dbbcu: goto P_0c09dbbc;
case 0x0c09dbbeu: goto P_0c09dbbe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09d9ea: /* original 2fe6, guest PC 0x0c09d9ea */
if(!s->budget--) { s->failed_pc=0x0c09d9eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d9ec;
P_0c09d9ec: /* original 4f22, guest PC 0x0c09d9ec */
if(!s->budget--) { s->failed_pc=0x0c09d9ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d9ee;
P_0c09d9ee: /* original d33a, guest PC 0x0c09d9ee */
if(!s->budget--) { s->failed_pc=0x0c09d9eeu; return 0; }
r[3]=read(ram,0x0c09dad8u,4);
goto P_0c09d9f0;
P_0c09d9f0: /* original 430b, guest PC 0x0c09d9f0 */
if(!s->budget--) { s->failed_pc=0x0c09d9f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d9f4u;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d9f4u) { target=s->pc; goto dispatch; }
goto P_0c09d9f4;
P_0c09d9f2: /* original 6e43, guest PC 0x0c09d9f2 */
if(!s->budget--) { s->failed_pc=0x0c09d9f2u; return 0; }
r[14]=r[4];
goto P_0c09d9f4;
P_0c09d9f4: /* original d339, guest PC 0x0c09d9f4 */
if(!s->budget--) { s->failed_pc=0x0c09d9f4u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09d9f6;
P_0c09d9f6: /* original 85ef, guest PC 0x0c09d9f6 */
if(!s->budget--) { s->failed_pc=0x0c09d9f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c09d9f8;
P_0c09d9f8: /* original 430b, guest PC 0x0c09d9f8 */
if(!s->budget--) { s->failed_pc=0x0c09d9f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d9fcu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d9fcu) { target=s->pc; goto dispatch; }
goto P_0c09d9fc;
P_0c09d9fa: /* original 6403, guest PC 0x0c09d9fa */
if(!s->budget--) { s->failed_pc=0x0c09d9fau; return 0; }
r[4]=r[0];
goto P_0c09d9fc;
P_0c09d9fc: /* original 9066, guest PC 0x0c09d9fc */
if(!s->budget--) { s->failed_pc=0x0c09d9fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09daccu,2);
goto P_0c09d9fe;
P_0c09d9fe: /* original d338, guest PC 0x0c09d9fe */
if(!s->budget--) { s->failed_pc=0x0c09d9feu; return 0; }
r[3]=read(ram,0x0c09dae0u,4);
goto P_0c09da00;
P_0c09da00: /* original 04ed, guest PC 0x0c09da00 */
if(!s->budget--) { s->failed_pc=0x0c09da00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09da02;
P_0c09da02: /* original 430b, guest PC 0x0c09da02 */
if(!s->budget--) { s->failed_pc=0x0c09da02u; return 0; }
target=r[3];
r[16]=code_base|0x0c09da06u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da06u) { target=s->pc; goto dispatch; }
goto P_0c09da06;
P_0c09da04: /* original 644d, guest PC 0x0c09da04 */
if(!s->budget--) { s->failed_pc=0x0c09da04u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09da06;
P_0c09da06: /* original 9062, guest PC 0x0c09da06 */
if(!s->budget--) { s->failed_pc=0x0c09da06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09daceu,2);
goto P_0c09da08;
P_0c09da08: /* original d334, guest PC 0x0c09da08 */
if(!s->budget--) { s->failed_pc=0x0c09da08u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09da0a;
P_0c09da0a: /* original 04ed, guest PC 0x0c09da0a */
if(!s->budget--) { s->failed_pc=0x0c09da0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09da0c;
P_0c09da0c: /* original 430b, guest PC 0x0c09da0c */
if(!s->budget--) { s->failed_pc=0x0c09da0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da10u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da10u) { target=s->pc; goto dispatch; }
goto P_0c09da10;
P_0c09da0e: /* original 644d, guest PC 0x0c09da0e */
if(!s->budget--) { s->failed_pc=0x0c09da0eu; return 0; }
r[4]=r[4]&65535u;
goto P_0c09da10;
P_0c09da10: /* original 905e, guest PC 0x0c09da10 */
if(!s->budget--) { s->failed_pc=0x0c09da10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dad0u,2);
goto P_0c09da12;
P_0c09da12: /* original 4f26, guest PC 0x0c09da12 */
if(!s->budget--) { s->failed_pc=0x0c09da12u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09da14;
P_0c09da14: /* original 04ed, guest PC 0x0c09da14 */
if(!s->budget--) { s->failed_pc=0x0c09da14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09da16;
P_0c09da16: /* original d333, guest PC 0x0c09da16 */
if(!s->budget--) { s->failed_pc=0x0c09da16u; return 0; }
r[3]=read(ram,0x0c09dae4u,4);
goto P_0c09da18;
P_0c09da18: /* original 644d, guest PC 0x0c09da18 */
if(!s->budget--) { s->failed_pc=0x0c09da18u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09da1a;
P_0c09da1a: /* original 432b, guest PC 0x0c09da1a */
if(!s->budget--) { s->failed_pc=0x0c09da1au; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c09da1c: /* original 6ef6, guest PC 0x0c09da1c */
if(!s->budget--) { s->failed_pc=0x0c09da1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09da1e;
P_0c09da1e: /* original 2fe6, guest PC 0x0c09da1e */
if(!s->budget--) { s->failed_pc=0x0c09da1eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09da20;
P_0c09da20: /* original 6e43, guest PC 0x0c09da20 */
if(!s->budget--) { s->failed_pc=0x0c09da20u; return 0; }
r[14]=r[4];
goto P_0c09da22;
P_0c09da22: /* original 4f22, guest PC 0x0c09da22 */
if(!s->budget--) { s->failed_pc=0x0c09da22u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09da24;
P_0c09da24: /* original 7ff0, guest PC 0x0c09da24 */
if(!s->budget--) { s->failed_pc=0x0c09da24u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09da26;
P_0c09da26: /* original 64f3, guest PC 0x0c09da26 */
if(!s->budget--) { s->failed_pc=0x0c09da26u; return 0; }
r[4]=r[15];
goto P_0c09da28;
P_0c09da28: /* original 2f52, guest PC 0x0c09da28 */
if(!s->budget--) { s->failed_pc=0x0c09da28u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09da2a;
P_0c09da2a: /* original d32f, guest PC 0x0c09da2a */
if(!s->budget--) { s->failed_pc=0x0c09da2au; return 0; }
r[3]=read(ram,0x0c09dae8u,4);
goto P_0c09da2c;
P_0c09da2c: /* original 430b, guest PC 0x0c09da2c */
if(!s->budget--) { s->failed_pc=0x0c09da2cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da30u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da30u) { target=s->pc; goto dispatch; }
goto P_0c09da30;
P_0c09da2e: /* original 7404, guest PC 0x0c09da2e */
if(!s->budget--) { s->failed_pc=0x0c09da2eu; return 0; }
r[4]+=0x00000004u;
goto P_0c09da30;
P_0c09da30: /* original d229, guest PC 0x0c09da30 */
if(!s->budget--) { s->failed_pc=0x0c09da30u; return 0; }
r[2]=read(ram,0x0c09dad8u,4);
goto P_0c09da32;
P_0c09da32: /* original 420b, guest PC 0x0c09da32 */
if(!s->budget--) { s->failed_pc=0x0c09da32u; return 0; }
target=r[2];
r[16]=code_base|0x0c09da36u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da36u) { target=s->pc; goto dispatch; }
goto P_0c09da36;
P_0c09da34: /* original 0009, guest PC 0x0c09da34 */
if(!s->budget--) { s->failed_pc=0x0c09da34u; return 0; }
goto P_0c09da36;
P_0c09da36: /* original 64f2, guest PC 0x0c09da36 */
if(!s->budget--) { s->failed_pc=0x0c09da36u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09da38;
P_0c09da38: /* original d328, guest PC 0x0c09da38 */
if(!s->budget--) { s->failed_pc=0x0c09da38u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09da3a;
P_0c09da3a: /* original 854f, guest PC 0x0c09da3a */
if(!s->budget--) { s->failed_pc=0x0c09da3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c09da3c;
P_0c09da3c: /* original 430b, guest PC 0x0c09da3c */
if(!s->budget--) { s->failed_pc=0x0c09da3cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da40u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da40u) { target=s->pc; goto dispatch; }
goto P_0c09da40;
P_0c09da3e: /* original 6403, guest PC 0x0c09da3e */
if(!s->budget--) { s->failed_pc=0x0c09da3eu; return 0; }
r[4]=r[0];
goto P_0c09da40;
P_0c09da40: /* original d227, guest PC 0x0c09da40 */
if(!s->budget--) { s->failed_pc=0x0c09da40u; return 0; }
r[2]=read(ram,0x0c09dae0u,4);
goto P_0c09da42;
P_0c09da42: /* original 64e1, guest PC 0x0c09da42 */
if(!s->budget--) { s->failed_pc=0x0c09da42u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c09da44;
P_0c09da44: /* original 420b, guest PC 0x0c09da44 */
if(!s->budget--) { s->failed_pc=0x0c09da44u; return 0; }
target=r[2];
r[16]=code_base|0x0c09da48u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da48u) { target=s->pc; goto dispatch; }
goto P_0c09da48;
P_0c09da46: /* original 644d, guest PC 0x0c09da46 */
if(!s->budget--) { s->failed_pc=0x0c09da46u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09da48;
P_0c09da48: /* original d324, guest PC 0x0c09da48 */
if(!s->budget--) { s->failed_pc=0x0c09da48u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09da4a;
P_0c09da4a: /* original 85e1, guest PC 0x0c09da4a */
if(!s->budget--) { s->failed_pc=0x0c09da4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c09da4c;
P_0c09da4c: /* original 430b, guest PC 0x0c09da4c */
if(!s->budget--) { s->failed_pc=0x0c09da4cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da50u;
r[4]=r[0]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da50u) { target=s->pc; goto dispatch; }
goto P_0c09da50;
P_0c09da4e: /* original 640d, guest PC 0x0c09da4e */
if(!s->budget--) { s->failed_pc=0x0c09da4eu; return 0; }
r[4]=r[0]&65535u;
goto P_0c09da50;
P_0c09da50: /* original 64f2, guest PC 0x0c09da50 */
if(!s->budget--) { s->failed_pc=0x0c09da50u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09da52;
P_0c09da52: /* original 923e, guest PC 0x0c09da52 */
if(!s->budget--) { s->failed_pc=0x0c09da52u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dad2u,2);
goto P_0c09da54;
P_0c09da54: /* original 85e2, guest PC 0x0c09da54 */
if(!s->budget--) { s->failed_pc=0x0c09da54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+4,2);
goto P_0c09da56;
P_0c09da56: /* original 324c, guest PC 0x0c09da56 */
if(!s->budget--) { s->failed_pc=0x0c09da56u; return 0; }
r[2]+=r[4];
goto P_0c09da58;
P_0c09da58: /* original d322, guest PC 0x0c09da58 */
if(!s->budget--) { s->failed_pc=0x0c09da58u; return 0; }
r[3]=read(ram,0x0c09dae4u,4);
goto P_0c09da5a;
P_0c09da5a: /* original 6421, guest PC 0x0c09da5a */
if(!s->budget--) { s->failed_pc=0x0c09da5au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[4]=tmp;
goto P_0c09da5c;
P_0c09da5c: /* original 600d, guest PC 0x0c09da5c */
if(!s->budget--) { s->failed_pc=0x0c09da5cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c09da5e;
P_0c09da5e: /* original 430b, guest PC 0x0c09da5e */
if(!s->budget--) { s->failed_pc=0x0c09da5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da62u;
r[4]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da62u) { target=s->pc; goto dispatch; }
goto P_0c09da62;
P_0c09da60: /* original 340c, guest PC 0x0c09da60 */
if(!s->budget--) { s->failed_pc=0x0c09da60u; return 0; }
r[4]+=r[0];
goto P_0c09da62;
P_0c09da62: /* original d222, guest PC 0x0c09da62 */
if(!s->budget--) { s->failed_pc=0x0c09da62u; return 0; }
r[2]=read(ram,0x0c09daecu,4);
goto P_0c09da64;
P_0c09da64: /* original 64f3, guest PC 0x0c09da64 */
if(!s->budget--) { s->failed_pc=0x0c09da64u; return 0; }
r[4]=r[15];
goto P_0c09da66;
P_0c09da66: /* original 420b, guest PC 0x0c09da66 */
if(!s->budget--) { s->failed_pc=0x0c09da66u; return 0; }
target=r[2];
r[16]=code_base|0x0c09da6au;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da6au) { target=s->pc; goto dispatch; }
goto P_0c09da6a;
P_0c09da68: /* original 7404, guest PC 0x0c09da68 */
if(!s->budget--) { s->failed_pc=0x0c09da68u; return 0; }
r[4]+=0x00000004u;
goto P_0c09da6a;
P_0c09da6a: /* original 7f10, guest PC 0x0c09da6a */
if(!s->budget--) { s->failed_pc=0x0c09da6au; return 0; }
r[15]+=0x00000010u;
goto P_0c09da6c;
P_0c09da6c: /* original 4f26, guest PC 0x0c09da6c */
if(!s->budget--) { s->failed_pc=0x0c09da6cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09da6e;
P_0c09da6e: /* original 000b, guest PC 0x0c09da6e */
if(!s->budget--) { s->failed_pc=0x0c09da6eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09da70: /* original 6ef6, guest PC 0x0c09da70 */
if(!s->budget--) { s->failed_pc=0x0c09da70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09da72;
P_0c09da72: /* original 2fe6, guest PC 0x0c09da72 */
if(!s->budget--) { s->failed_pc=0x0c09da72u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09da74;
P_0c09da74: /* original e010, guest PC 0x0c09da74 */
if(!s->budget--) { s->failed_pc=0x0c09da74u; return 0; }
r[0]=0x00000010u;
goto P_0c09da76;
P_0c09da76: /* original 2fd6, guest PC 0x0c09da76 */
if(!s->budget--) { s->failed_pc=0x0c09da76u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09da78;
P_0c09da78: /* original 6e43, guest PC 0x0c09da78 */
if(!s->budget--) { s->failed_pc=0x0c09da78u; return 0; }
r[14]=r[4];
goto P_0c09da7a;
P_0c09da7a: /* original 2fc6, guest PC 0x0c09da7a */
if(!s->budget--) { s->failed_pc=0x0c09da7au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09da7c;
P_0c09da7c: /* original 2fb6, guest PC 0x0c09da7c */
if(!s->budget--) { s->failed_pc=0x0c09da7cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09da7e;
P_0c09da7e: /* original 2fa6, guest PC 0x0c09da7e */
if(!s->budget--) { s->failed_pc=0x0c09da7eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09da80;
P_0c09da80: /* original 2f96, guest PC 0x0c09da80 */
if(!s->budget--) { s->failed_pc=0x0c09da80u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09da82;
P_0c09da82: /* original 2f86, guest PC 0x0c09da82 */
if(!s->budget--) { s->failed_pc=0x0c09da82u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09da84;
P_0c09da84: /* original fffb, guest PC 0x0c09da84 */
if(!s->budget--) { s->failed_pc=0x0c09da84u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09da86;
P_0c09da86: /* original 4f22, guest PC 0x0c09da86 */
if(!s->budget--) { s->failed_pc=0x0c09da86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09da88;
P_0c09da88: /* original f3e6, guest PC 0x0c09da88 */
if(!s->budget--) { s->failed_pc=0x0c09da88u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09da8a;
P_0c09da8a: /* original e024, guest PC 0x0c09da8a */
if(!s->budget--) { s->failed_pc=0x0c09da8au; return 0; }
r[0]=0x00000024u;
goto P_0c09da8c;
P_0c09da8c: /* original 9c22, guest PC 0x0c09da8c */
if(!s->budget--) { s->failed_pc=0x0c09da8cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dad4u,2);
goto P_0c09da8e;
P_0c09da8e: /* original 7fd0, guest PC 0x0c09da8e */
if(!s->budget--) { s->failed_pc=0x0c09da8eu; return 0; }
r[15]+=0xffffffd0u;
goto P_0c09da90;
P_0c09da90: /* original 9b21, guest PC 0x0c09da90 */
if(!s->budget--) { s->failed_pc=0x0c09da90u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dad6u,2);
goto P_0c09da92;
P_0c09da92: /* original ff37, guest PC 0x0c09da92 */
if(!s->budget--) { s->failed_pc=0x0c09da92u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09da94;
P_0c09da94: /* original e014, guest PC 0x0c09da94 */
if(!s->budget--) { s->failed_pc=0x0c09da94u; return 0; }
r[0]=0x00000014u;
goto P_0c09da96;
P_0c09da96: /* original f3e6, guest PC 0x0c09da96 */
if(!s->budget--) { s->failed_pc=0x0c09da96u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09da98;
P_0c09da98: /* original e028, guest PC 0x0c09da98 */
if(!s->budget--) { s->failed_pc=0x0c09da98u; return 0; }
r[0]=0x00000028u;
goto P_0c09da9a;
P_0c09da9a: /* original 3cec, guest PC 0x0c09da9a */
if(!s->budget--) { s->failed_pc=0x0c09da9au; return 0; }
r[12]+=r[14];
goto P_0c09da9c;
P_0c09da9c: /* original ff37, guest PC 0x0c09da9c */
if(!s->budget--) { s->failed_pc=0x0c09da9cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09da9e;
P_0c09da9e: /* original e018, guest PC 0x0c09da9e */
if(!s->budget--) { s->failed_pc=0x0c09da9eu; return 0; }
r[0]=0x00000018u;
goto P_0c09daa0;
P_0c09daa0: /* original f3e6, guest PC 0x0c09daa0 */
if(!s->budget--) { s->failed_pc=0x0c09daa0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09daa2;
P_0c09daa2: /* original e02c, guest PC 0x0c09daa2 */
if(!s->budget--) { s->failed_pc=0x0c09daa2u; return 0; }
r[0]=0x0000002cu;
goto P_0c09daa4;
P_0c09daa4: /* original ff37, guest PC 0x0c09daa4 */
if(!s->budget--) { s->failed_pc=0x0c09daa4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09daa6;
P_0c09daa6: /* original e048, guest PC 0x0c09daa6 */
if(!s->budget--) { s->failed_pc=0x0c09daa6u; return 0; }
r[0]=0x00000048u;
goto P_0c09daa8;
P_0c09daa8: /* original 04ee, guest PC 0x0c09daa8 */
if(!s->budget--) { s->failed_pc=0x0c09daa8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09daaa;
P_0c09daaa: /* original d311, guest PC 0x0c09daaa */
if(!s->budget--) { s->failed_pc=0x0c09daaau; return 0; }
r[3]=read(ram,0x0c09daf0u,4);
goto P_0c09daac;
P_0c09daac: /* original 2438, guest PC 0x0c09daac */
if(!s->budget--) { s->failed_pc=0x0c09daacu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c09daae;
P_0c09daae: /* original 8f31, guest PC 0x0c09daae */
if(!s->budget--) { s->failed_pc=0x0c09daaeu; return 0; }
cond=r[17]&1u;
r[11]+=r[14];
if(!cond) { goto P_0c09db14; }
goto P_0c09dab2;
P_0c09dab0: /* original 3bec, guest PC 0x0c09dab0 */
if(!s->budget--) { s->failed_pc=0x0c09dab0u; return 0; }
r[11]+=r[14];
goto P_0c09dab2;
P_0c09dab2: /* original e061, guest PC 0x0c09dab2 */
if(!s->budget--) { s->failed_pc=0x0c09dab2u; return 0; }
r[0]=0x00000061u;
goto P_0c09dab4;
P_0c09dab4: /* original 00ec, guest PC 0x0c09dab4 */
if(!s->budget--) { s->failed_pc=0x0c09dab4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09dab6;
P_0c09dab6: /* original 600c, guest PC 0x0c09dab6 */
if(!s->budget--) { s->failed_pc=0x0c09dab6u; return 0; }
r[0]=r[0]&255u;
goto P_0c09dab8;
P_0c09dab8: /* original 8806, guest PC 0x0c09dab8 */
if(!s->budget--) { s->failed_pc=0x0c09dab8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c09daba;
P_0c09daba: /* original 891b, guest PC 0x0c09daba */
if(!s->budget--) { s->failed_pc=0x0c09dabau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09daf4; }
goto P_0c09dabc;
P_0c09dabc: /* original 8808, guest PC 0x0c09dabc */
if(!s->budget--) { s->failed_pc=0x0c09dabcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09dabe;
P_0c09dabe: /* original 891c, guest PC 0x0c09dabe */
if(!s->budget--) { s->failed_pc=0x0c09dabeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09dafa; }
goto P_0c09dac0;
P_0c09dac0: /* original 880b, guest PC 0x0c09dac0 */
if(!s->budget--) { s->failed_pc=0x0c09dac0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c09dac2;
P_0c09dac2: /* original 8920, guest PC 0x0c09dac2 */
if(!s->budget--) { s->failed_pc=0x0c09dac2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09db06; }
goto P_0c09dac4;
P_0c09dac4: /* original 880c, guest PC 0x0c09dac4 */
if(!s->budget--) { s->failed_pc=0x0c09dac4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c09dac6;
P_0c09dac6: /* original 891b, guest PC 0x0c09dac6 */
if(!s->budget--) { s->failed_pc=0x0c09dac6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09db00; }
goto P_0c09dac8;
P_0c09dac8: /* original a024, guest PC 0x0c09dac8 */
if(!s->budget--) { s->failed_pc=0x0c09dac8u; return 0; }
goto P_0c09db14;
P_0c09daca: /* original 0009, guest PC 0x0c09daca */
if(!s->budget--) { s->failed_pc=0x0c09dacau; return 0; }
if(!vf3_matrix_family(0x0c09daccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09daccu; return 0; } return 1;
P_0c09daf4: /* original c73e, guest PC 0x0c09daf4 */
if(!s->budget--) { s->failed_pc=0x0c09daf4u; return 0; }
r[0]=code_base|0x0009dbf0u;
goto P_0c09daf6;
P_0c09daf6: /* original a008, guest PC 0x0c09daf6 */
if(!s->budget--) { s->failed_pc=0x0c09daf6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09db0a;
P_0c09daf8: /* original f308, guest PC 0x0c09daf8 */
if(!s->budget--) { s->failed_pc=0x0c09daf8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09dafa;
P_0c09dafa: /* original c73e, guest PC 0x0c09dafa */
if(!s->budget--) { s->failed_pc=0x0c09dafau; return 0; }
r[0]=code_base|0x0009dbf4u;
goto P_0c09dafc;
P_0c09dafc: /* original a005, guest PC 0x0c09dafc */
if(!s->budget--) { s->failed_pc=0x0c09dafcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09db0a;
P_0c09dafe: /* original f308, guest PC 0x0c09dafe */
if(!s->budget--) { s->failed_pc=0x0c09dafeu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09db00;
P_0c09db00: /* original c73d, guest PC 0x0c09db00 */
if(!s->budget--) { s->failed_pc=0x0c09db00u; return 0; }
r[0]=code_base|0x0009dbf8u;
goto P_0c09db02;
P_0c09db02: /* original a002, guest PC 0x0c09db02 */
if(!s->budget--) { s->failed_pc=0x0c09db02u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09db0a;
P_0c09db04: /* original f308, guest PC 0x0c09db04 */
if(!s->budget--) { s->failed_pc=0x0c09db04u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09db06;
P_0c09db06: /* original c73d, guest PC 0x0c09db06 */
if(!s->budget--) { s->failed_pc=0x0c09db06u; return 0; }
r[0]=code_base|0x0009dbfcu;
goto P_0c09db08;
P_0c09db08: /* original f308, guest PC 0x0c09db08 */
if(!s->budget--) { s->failed_pc=0x0c09db08u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09db0a;
P_0c09db0a: /* original e028, guest PC 0x0c09db0a */
if(!s->budget--) { s->failed_pc=0x0c09db0au; return 0; }
r[0]=0x00000028u;
goto P_0c09db0c;
P_0c09db0c: /* original f2f6, guest PC 0x0c09db0c */
if(!s->budget--) { s->failed_pc=0x0c09db0cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09db0e;
P_0c09db0e: /* original e028, guest PC 0x0c09db0e */
if(!s->budget--) { s->failed_pc=0x0c09db0eu; return 0; }
r[0]=0x00000028u;
goto P_0c09db10;
P_0c09db10: /* original f231, guest PC 0x0c09db10 */
if(!s->budget--) { s->failed_pc=0x0c09db10u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c09db12;
P_0c09db12: /* original ff27, guest PC 0x0c09db12 */
if(!s->budget--) { s->failed_pc=0x0c09db12u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09db14;
P_0c09db14: /* original 62e2, guest PC 0x0c09db14 */
if(!s->budget--) { s->failed_pc=0x0c09db14u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09db16;
P_0c09db16: /* original d33a, guest PC 0x0c09db16 */
if(!s->budget--) { s->failed_pc=0x0c09db16u; return 0; }
r[3]=read(ram,0x0c09dc00u,4);
goto P_0c09db18;
P_0c09db18: /* original 2238, guest PC 0x0c09db18 */
if(!s->budget--) { s->failed_pc=0x0c09db18u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09db1a;
P_0c09db1a: /* original 8d0c, guest PC 0x0c09db1a */
if(!s->budget--) { s->failed_pc=0x0c09db1au; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(cond) { goto P_0c09db36; }
goto P_0c09db1e;
P_0c09db1c: /* original ff8d, guest PC 0x0c09db1c */
if(!s->budget--) { s->failed_pc=0x0c09db1cu; return 0; }
fr[15]=0;
goto P_0c09db1e;
P_0c09db1e: /* original 9062, guest PC 0x0c09db1e */
if(!s->budget--) { s->failed_pc=0x0c09db1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dbe6u,2);
goto P_0c09db20;
P_0c09db20: /* original f3e6, guest PC 0x0c09db20 */
if(!s->budget--) { s->failed_pc=0x0c09db20u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09db22;
P_0c09db22: /* original ff3a, guest PC 0x0c09db22 */
if(!s->budget--) { s->failed_pc=0x0c09db22u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09db24;
P_0c09db24: /* original 9060, guest PC 0x0c09db24 */
if(!s->budget--) { s->failed_pc=0x0c09db24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dbe8u,2);
goto P_0c09db26;
P_0c09db26: /* original f3e6, guest PC 0x0c09db26 */
if(!s->budget--) { s->failed_pc=0x0c09db26u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09db28;
P_0c09db28: /* original e004, guest PC 0x0c09db28 */
if(!s->budget--) { s->failed_pc=0x0c09db28u; return 0; }
r[0]=0x00000004u;
goto P_0c09db2a;
P_0c09db2a: /* original ff37, guest PC 0x0c09db2a */
if(!s->budget--) { s->failed_pc=0x0c09db2au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09db2c;
P_0c09db2c: /* original 905d, guest PC 0x0c09db2c */
if(!s->budget--) { s->failed_pc=0x0c09db2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dbeau,2);
goto P_0c09db2e;
P_0c09db2e: /* original f3e6, guest PC 0x0c09db2e */
if(!s->budget--) { s->failed_pc=0x0c09db2eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09db30;
P_0c09db30: /* original e008, guest PC 0x0c09db30 */
if(!s->budget--) { s->failed_pc=0x0c09db30u; return 0; }
r[0]=0x00000008u;
goto P_0c09db32;
P_0c09db32: /* original a005, guest PC 0x0c09db32 */
if(!s->budget--) { s->failed_pc=0x0c09db32u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09db40;
P_0c09db34: /* original ff37, guest PC 0x0c09db34 */
if(!s->budget--) { s->failed_pc=0x0c09db34u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09db36;
P_0c09db36: /* original e004, guest PC 0x0c09db36 */
if(!s->budget--) { s->failed_pc=0x0c09db36u; return 0; }
r[0]=0x00000004u;
goto P_0c09db38;
P_0c09db38: /* original fffa, guest PC 0x0c09db38 */
if(!s->budget--) { s->failed_pc=0x0c09db38u; return 0; }
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09db3a;
P_0c09db3a: /* original fff7, guest PC 0x0c09db3a */
if(!s->budget--) { s->failed_pc=0x0c09db3au; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c09db3c;
P_0c09db3c: /* original e008, guest PC 0x0c09db3c */
if(!s->budget--) { s->failed_pc=0x0c09db3cu; return 0; }
r[0]=0x00000008u;
goto P_0c09db3e;
P_0c09db3e: /* original fff7, guest PC 0x0c09db3e */
if(!s->budget--) { s->failed_pc=0x0c09db3eu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c09db40;
P_0c09db40: /* original d330, guest PC 0x0c09db40 */
if(!s->budget--) { s->failed_pc=0x0c09db40u; return 0; }
r[3]=read(ram,0x0c09dc04u,4);
goto P_0c09db42;
P_0c09db42: /* original 430b, guest PC 0x0c09db42 */
if(!s->budget--) { s->failed_pc=0x0c09db42u; return 0; }
target=r[3];
r[16]=code_base|0x0c09db46u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09db46u) { target=s->pc; goto dispatch; }
goto P_0c09db46;
P_0c09db44: /* original e400, guest PC 0x0c09db44 */
if(!s->budget--) { s->failed_pc=0x0c09db44u; return 0; }
r[4]=0x00000000u;
goto P_0c09db46;
P_0c09db46: /* original d230, guest PC 0x0c09db46 */
if(!s->budget--) { s->failed_pc=0x0c09db46u; return 0; }
r[2]=read(ram,0x0c09dc08u,4);
goto P_0c09db48;
P_0c09db48: /* original 420b, guest PC 0x0c09db48 */
if(!s->budget--) { s->failed_pc=0x0c09db48u; return 0; }
target=r[2];
r[16]=code_base|0x0c09db4cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09db4cu) { target=s->pc; goto dispatch; }
goto P_0c09db4c;
P_0c09db4a: /* original 0009, guest PC 0x0c09db4a */
if(!s->budget--) { s->failed_pc=0x0c09db4au; return 0; }
goto P_0c09db4c;
P_0c09db4c: /* original d32f, guest PC 0x0c09db4c */
if(!s->budget--) { s->failed_pc=0x0c09db4cu; return 0; }
r[3]=read(ram,0x0c09dc0cu,4);
goto P_0c09db4e;
P_0c09db4e: /* original 64f3, guest PC 0x0c09db4e */
if(!s->budget--) { s->failed_pc=0x0c09db4eu; return 0; }
r[4]=r[15];
goto P_0c09db50;
P_0c09db50: /* original 430b, guest PC 0x0c09db50 */
if(!s->budget--) { s->failed_pc=0x0c09db50u; return 0; }
target=r[3];
r[16]=code_base|0x0c09db54u;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09db54u) { target=s->pc; goto dispatch; }
goto P_0c09db54;
P_0c09db52: /* original 7424, guest PC 0x0c09db52 */
if(!s->budget--) { s->failed_pc=0x0c09db52u; return 0; }
r[4]+=0x00000024u;
goto P_0c09db54;
P_0c09db54: /* original d32e, guest PC 0x0c09db54 */
if(!s->budget--) { s->failed_pc=0x0c09db54u; return 0; }
r[3]=read(ram,0x0c09dc10u,4);
goto P_0c09db56;
P_0c09db56: /* original 85ef, guest PC 0x0c09db56 */
if(!s->budget--) { s->failed_pc=0x0c09db56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c09db58;
P_0c09db58: /* original 430b, guest PC 0x0c09db58 */
if(!s->budget--) { s->failed_pc=0x0c09db58u; return 0; }
target=r[3];
r[16]=code_base|0x0c09db5cu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09db5cu) { target=s->pc; goto dispatch; }
goto P_0c09db5c;
P_0c09db5a: /* original 6403, guest PC 0x0c09db5a */
if(!s->budget--) { s->failed_pc=0x0c09db5au; return 0; }
r[4]=r[0];
goto P_0c09db5c;
P_0c09db5c: /* original da2e, guest PC 0x0c09db5c */
if(!s->budget--) { s->failed_pc=0x0c09db5cu; return 0; }
r[10]=read(ram,0x0c09dc18u,4);
goto P_0c09db5e;
P_0c09db5e: /* original ed07, guest PC 0x0c09db5e */
if(!s->budget--) { s->failed_pc=0x0c09db5eu; return 0; }
r[13]=0x00000007u;
goto P_0c09db60;
P_0c09db60: /* original 9944, guest PC 0x0c09db60 */
if(!s->budget--) { s->failed_pc=0x0c09db60u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dbecu,2);
goto P_0c09db62;
P_0c09db62: /* original d82c, guest PC 0x0c09db62 */
if(!s->budget--) { s->failed_pc=0x0c09db62u; return 0; }
r[8]=read(ram,0x0c09dc14u,4);
goto P_0c09db64;
P_0c09db64: /* original d22d, guest PC 0x0c09db64 */
if(!s->budget--) { s->failed_pc=0x0c09db64u; return 0; }
r[2]=read(ram,0x0c09dc1cu,4);
goto P_0c09db66;
P_0c09db66: /* original 64f3, guest PC 0x0c09db66 */
if(!s->budget--) { s->failed_pc=0x0c09db66u; return 0; }
r[4]=r[15];
goto P_0c09db68;
P_0c09db68: /* original 66f3, guest PC 0x0c09db68 */
if(!s->budget--) { s->failed_pc=0x0c09db68u; return 0; }
r[6]=r[15];
goto P_0c09db6a;
P_0c09db6a: /* original 65c3, guest PC 0x0c09db6a */
if(!s->budget--) { s->failed_pc=0x0c09db6au; return 0; }
r[5]=r[12];
goto P_0c09db6c;
P_0c09db6c: /* original 420b, guest PC 0x0c09db6c */
if(!s->budget--) { s->failed_pc=0x0c09db6cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09db70u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09db70u) { target=s->pc; goto dispatch; }
goto P_0c09db70;
P_0c09db6e: /* original 7418, guest PC 0x0c09db6e */
if(!s->budget--) { s->failed_pc=0x0c09db6eu; return 0; }
r[4]+=0x00000018u;
goto P_0c09db70;
P_0c09db70: /* original d22b, guest PC 0x0c09db70 */
if(!s->budget--) { s->failed_pc=0x0c09db70u; return 0; }
r[2]=read(ram,0x0c09dc20u,4);
goto P_0c09db72;
P_0c09db72: /* original 6322, guest PC 0x0c09db72 */
if(!s->budget--) { s->failed_pc=0x0c09db72u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c09db74;
P_0c09db74: /* original 2398, guest PC 0x0c09db74 */
if(!s->budget--) { s->failed_pc=0x0c09db74u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c09db76;
P_0c09db76: /* original 8d0d, guest PC 0x0c09db76 */
if(!s->budget--) { s->failed_pc=0x0c09db76u; return 0; }
cond=r[17]&1u;
r[12]+=0x0000000cu;
if(cond) { goto P_0c09db94; }
goto P_0c09db7a;
P_0c09db78: /* original 7c0c, guest PC 0x0c09db78 */
if(!s->budget--) { s->failed_pc=0x0c09db78u; return 0; }
r[12]+=0x0000000cu;
goto P_0c09db7a;
P_0c09db7a: /* original 60e2, guest PC 0x0c09db7a */
if(!s->budget--) { s->failed_pc=0x0c09db7au; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c09db7c;
P_0c09db7c: /* original 2088, guest PC 0x0c09db7c */
if(!s->budget--) { s->failed_pc=0x0c09db7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[8])==0)!=0);
goto P_0c09db7e;
P_0c09db7e: /* original 8b09, guest PC 0x0c09db7e */
if(!s->budget--) { s->failed_pc=0x0c09db7eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09db94; }
goto P_0c09db80;
P_0c09db80: /* original 61e2, guest PC 0x0c09db80 */
if(!s->budget--) { s->failed_pc=0x0c09db80u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c09db82;
P_0c09db82: /* original d328, guest PC 0x0c09db82 */
if(!s->budget--) { s->failed_pc=0x0c09db82u; return 0; }
r[3]=read(ram,0x0c09dc24u,4);
goto P_0c09db84;
P_0c09db84: /* original 2138, guest PC 0x0c09db84 */
if(!s->budget--) { s->failed_pc=0x0c09db84u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c09db86;
P_0c09db86: /* original 8905, guest PC 0x0c09db86 */
if(!s->budget--) { s->failed_pc=0x0c09db86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09db94; }
goto P_0c09db88;
P_0c09db88: /* original e048, guest PC 0x0c09db88 */
if(!s->budget--) { s->failed_pc=0x0c09db88u; return 0; }
r[0]=0x00000048u;
goto P_0c09db8a;
P_0c09db8a: /* original 01ee, guest PC 0x0c09db8a */
if(!s->budget--) { s->failed_pc=0x0c09db8au; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09db8c;
P_0c09db8c: /* original 21a8, guest PC 0x0c09db8c */
if(!s->budget--) { s->failed_pc=0x0c09db8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[10])==0)!=0);
goto P_0c09db8e;
P_0c09db8e: /* original 8901, guest PC 0x0c09db8e */
if(!s->budget--) { s->failed_pc=0x0c09db8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09db94; }
goto P_0c09db90;
P_0c09db90: /* original e01c, guest PC 0x0c09db90 */
if(!s->budget--) { s->failed_pc=0x0c09db90u; return 0; }
r[0]=0x0000001cu;
goto P_0c09db92;
P_0c09db92: /* original fff7, guest PC 0x0c09db92 */
if(!s->budget--) { s->failed_pc=0x0c09db92u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c09db94;
P_0c09db94: /* original d324, guest PC 0x0c09db94 */
if(!s->budget--) { s->failed_pc=0x0c09db94u; return 0; }
r[3]=read(ram,0x0c09dc28u,4);
goto P_0c09db96;
P_0c09db96: /* original 64f3, guest PC 0x0c09db96 */
if(!s->budget--) { s->failed_pc=0x0c09db96u; return 0; }
r[4]=r[15];
goto P_0c09db98;
P_0c09db98: /* original 65b3, guest PC 0x0c09db98 */
if(!s->budget--) { s->failed_pc=0x0c09db98u; return 0; }
r[5]=r[11];
goto P_0c09db9a;
P_0c09db9a: /* original 430b, guest PC 0x0c09db9a */
if(!s->budget--) { s->failed_pc=0x0c09db9au; return 0; }
target=r[3];
r[16]=code_base|0x0c09db9eu;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09db9eu) { target=s->pc; goto dispatch; }
goto P_0c09db9e;
P_0c09db9c: /* original 7418, guest PC 0x0c09db9c */
if(!s->budget--) { s->failed_pc=0x0c09db9cu; return 0; }
r[4]+=0x00000018u;
goto P_0c09db9e;
P_0c09db9e: /* original 4d10, guest PC 0x0c09db9e */
if(!s->budget--) { s->failed_pc=0x0c09db9eu; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c09dba0;
P_0c09dba0: /* original 8fe0, guest PC 0x0c09dba0 */
if(!s->budget--) { s->failed_pc=0x0c09dba0u; return 0; }
cond=r[17]&1u;
r[11]+=0x0000000cu;
if(!cond) { goto P_0c09db64; }
goto P_0c09dba4;
P_0c09dba2: /* original 7b0c, guest PC 0x0c09dba2 */
if(!s->budget--) { s->failed_pc=0x0c09dba2u; return 0; }
r[11]+=0x0000000cu;
goto P_0c09dba4;
P_0c09dba4: /* original d321, guest PC 0x0c09dba4 */
if(!s->budget--) { s->failed_pc=0x0c09dba4u; return 0; }
r[3]=read(ram,0x0c09dc2cu,4);
goto P_0c09dba6;
P_0c09dba6: /* original 430b, guest PC 0x0c09dba6 */
if(!s->budget--) { s->failed_pc=0x0c09dba6u; return 0; }
target=r[3];
r[16]=code_base|0x0c09dbaau;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dbaau) { target=s->pc; goto dispatch; }
goto P_0c09dbaa;
P_0c09dba8: /* original e401, guest PC 0x0c09dba8 */
if(!s->budget--) { s->failed_pc=0x0c09dba8u; return 0; }
r[4]=0x00000001u;
goto P_0c09dbaa;
P_0c09dbaa: /* original 7f30, guest PC 0x0c09dbaa */
if(!s->budget--) { s->failed_pc=0x0c09dbaau; return 0; }
r[15]+=0x00000030u;
goto P_0c09dbac;
P_0c09dbac: /* original 4f26, guest PC 0x0c09dbac */
if(!s->budget--) { s->failed_pc=0x0c09dbacu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09dbae;
P_0c09dbae: /* original fff9, guest PC 0x0c09dbae */
if(!s->budget--) { s->failed_pc=0x0c09dbaeu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09dbb0;
P_0c09dbb0: /* original 68f6, guest PC 0x0c09dbb0 */
if(!s->budget--) { s->failed_pc=0x0c09dbb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09dbb2;
P_0c09dbb2: /* original 69f6, guest PC 0x0c09dbb2 */
if(!s->budget--) { s->failed_pc=0x0c09dbb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09dbb4;
P_0c09dbb4: /* original 6af6, guest PC 0x0c09dbb4 */
if(!s->budget--) { s->failed_pc=0x0c09dbb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09dbb6;
P_0c09dbb6: /* original 6bf6, guest PC 0x0c09dbb6 */
if(!s->budget--) { s->failed_pc=0x0c09dbb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09dbb8;
P_0c09dbb8: /* original 6cf6, guest PC 0x0c09dbb8 */
if(!s->budget--) { s->failed_pc=0x0c09dbb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09dbba;
P_0c09dbba: /* original 6df6, guest PC 0x0c09dbba */
if(!s->budget--) { s->failed_pc=0x0c09dbbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09dbbc;
P_0c09dbbc: /* original 000b, guest PC 0x0c09dbbc */
if(!s->budget--) { s->failed_pc=0x0c09dbbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09dbbe: /* original 6ef6, guest PC 0x0c09dbbe */
if(!s->budget--) { s->failed_pc=0x0c09dbbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09dbc0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
