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
int vf3_away_batch249_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2d48u: goto P_0c0a2d48;
case 0x0c0a2d4au: goto P_0c0a2d4a;
case 0x0c0a2d4cu: goto P_0c0a2d4c;
case 0x0c0a2d4eu: goto P_0c0a2d4e;
case 0x0c0a2d50u: goto P_0c0a2d50;
case 0x0c0a2d52u: goto P_0c0a2d52;
case 0x0c0a2d54u: goto P_0c0a2d54;
case 0x0c0a2d56u: goto P_0c0a2d56;
case 0x0c0a2d58u: goto P_0c0a2d58;
case 0x0c0a2d5au: goto P_0c0a2d5a;
case 0x0c0a2d5cu: goto P_0c0a2d5c;
case 0x0c0a2d5eu: goto P_0c0a2d5e;
case 0x0c0a2d60u: goto P_0c0a2d60;
case 0x0c0a2d62u: goto P_0c0a2d62;
case 0x0c0a2d64u: goto P_0c0a2d64;
case 0x0c0a2d66u: goto P_0c0a2d66;
case 0x0c0a2d68u: goto P_0c0a2d68;
case 0x0c0a2d6au: goto P_0c0a2d6a;
case 0x0c0a2d6cu: goto P_0c0a2d6c;
case 0x0c0a2d6eu: goto P_0c0a2d6e;
case 0x0c0a2d70u: goto P_0c0a2d70;
case 0x0c0a2d72u: goto P_0c0a2d72;
case 0x0c0a2d74u: goto P_0c0a2d74;
case 0x0c0a2d76u: goto P_0c0a2d76;
case 0x0c0a2d78u: goto P_0c0a2d78;
case 0x0c0a2d7au: goto P_0c0a2d7a;
case 0x0c0a2d7cu: goto P_0c0a2d7c;
case 0x0c0a2d7eu: goto P_0c0a2d7e;
case 0x0c0a2d80u: goto P_0c0a2d80;
case 0x0c0a2d82u: goto P_0c0a2d82;
case 0x0c0a2d84u: goto P_0c0a2d84;
case 0x0c0a2d86u: goto P_0c0a2d86;
case 0x0c0a2d88u: goto P_0c0a2d88;
case 0x0c0a2d8au: goto P_0c0a2d8a;
case 0x0c0a2d8cu: goto P_0c0a2d8c;
case 0x0c0a2d8eu: goto P_0c0a2d8e;
case 0x0c0a2d90u: goto P_0c0a2d90;
case 0x0c0a2d92u: goto P_0c0a2d92;
case 0x0c0a2d94u: goto P_0c0a2d94;
case 0x0c0a2d96u: goto P_0c0a2d96;
case 0x0c0a2d98u: goto P_0c0a2d98;
case 0x0c0a2d9au: goto P_0c0a2d9a;
case 0x0c0a2d9cu: goto P_0c0a2d9c;
case 0x0c0a2d9eu: goto P_0c0a2d9e;
case 0x0c0a2da0u: goto P_0c0a2da0;
case 0x0c0a2da2u: goto P_0c0a2da2;
case 0x0c0a2da4u: goto P_0c0a2da4;
case 0x0c0a2da6u: goto P_0c0a2da6;
case 0x0c0a2da8u: goto P_0c0a2da8;
case 0x0c0a2daau: goto P_0c0a2daa;
case 0x0c0a2dacu: goto P_0c0a2dac;
case 0x0c0a2daeu: goto P_0c0a2dae;
case 0x0c0a2db0u: goto P_0c0a2db0;
case 0x0c0a2db2u: goto P_0c0a2db2;
case 0x0c0a2db4u: goto P_0c0a2db4;
case 0x0c0a2db6u: goto P_0c0a2db6;
case 0x0c0a2db8u: goto P_0c0a2db8;
case 0x0c0a2dbau: goto P_0c0a2dba;
case 0x0c0a2dbcu: goto P_0c0a2dbc;
case 0x0c0a2dbeu: goto P_0c0a2dbe;
case 0x0c0a2dc0u: goto P_0c0a2dc0;
case 0x0c0a2dc2u: goto P_0c0a2dc2;
case 0x0c0a2dc4u: goto P_0c0a2dc4;
case 0x0c0a2dc6u: goto P_0c0a2dc6;
case 0x0c0a2dc8u: goto P_0c0a2dc8;
case 0x0c0a2dcau: goto P_0c0a2dca;
case 0x0c0a2dccu: goto P_0c0a2dcc;
case 0x0c0a2dceu: goto P_0c0a2dce;
case 0x0c0a2dd0u: goto P_0c0a2dd0;
case 0x0c0a2dd2u: goto P_0c0a2dd2;
case 0x0c0a2dd4u: goto P_0c0a2dd4;
case 0x0c0a2dd6u: goto P_0c0a2dd6;
case 0x0c0a2dd8u: goto P_0c0a2dd8;
case 0x0c0a2ddau: goto P_0c0a2dda;
case 0x0c0a2ddcu: goto P_0c0a2ddc;
case 0x0c0a2ddeu: goto P_0c0a2dde;
case 0x0c0a2de0u: goto P_0c0a2de0;
case 0x0c0a2de2u: goto P_0c0a2de2;
case 0x0c0a2de4u: goto P_0c0a2de4;
case 0x0c0a2de6u: goto P_0c0a2de6;
case 0x0c0a2de8u: goto P_0c0a2de8;
case 0x0c0a2deau: goto P_0c0a2dea;
case 0x0c0a2decu: goto P_0c0a2dec;
case 0x0c0a2deeu: goto P_0c0a2dee;
case 0x0c0a2df0u: goto P_0c0a2df0;
case 0x0c0a2df2u: goto P_0c0a2df2;
case 0x0c0a2df4u: goto P_0c0a2df4;
case 0x0c0a2df6u: goto P_0c0a2df6;
case 0x0c0a7f14u: goto P_0c0a7f14;
case 0x0c0a7f16u: goto P_0c0a7f16;
case 0x0c0a7f18u: goto P_0c0a7f18;
case 0x0c0a7f1au: goto P_0c0a7f1a;
case 0x0c0a7f1cu: goto P_0c0a7f1c;
case 0x0c0a7f1eu: goto P_0c0a7f1e;
case 0x0c0a7f20u: goto P_0c0a7f20;
case 0x0c0a7f22u: goto P_0c0a7f22;
case 0x0c0a7f24u: goto P_0c0a7f24;
case 0x0c0a7f26u: goto P_0c0a7f26;
case 0x0c0a7f28u: goto P_0c0a7f28;
case 0x0c0a7f2au: goto P_0c0a7f2a;
case 0x0c0a7f2cu: goto P_0c0a7f2c;
case 0x0c0a7f2eu: goto P_0c0a7f2e;
case 0x0c0a7f30u: goto P_0c0a7f30;
case 0x0c0a7f32u: goto P_0c0a7f32;
case 0x0c0a7f34u: goto P_0c0a7f34;
case 0x0c0a7f36u: goto P_0c0a7f36;
case 0x0c0a7f38u: goto P_0c0a7f38;
case 0x0c0a7f3au: goto P_0c0a7f3a;
case 0x0c0a7f3cu: goto P_0c0a7f3c;
case 0x0c0a7f3eu: goto P_0c0a7f3e;
case 0x0c0a7f40u: goto P_0c0a7f40;
case 0x0c0a7f42u: goto P_0c0a7f42;
case 0x0c0a7f44u: goto P_0c0a7f44;
case 0x0c0a7f46u: goto P_0c0a7f46;
case 0x0c0a7f48u: goto P_0c0a7f48;
case 0x0c0a7f4au: goto P_0c0a7f4a;
case 0x0c0a7f4cu: goto P_0c0a7f4c;
case 0x0c0a7f4eu: goto P_0c0a7f4e;
case 0x0c0a7f50u: goto P_0c0a7f50;
case 0x0c0a7f52u: goto P_0c0a7f52;
case 0x0c0a7f54u: goto P_0c0a7f54;
case 0x0c0a81eeu: goto P_0c0a81ee;
case 0x0c0a81f0u: goto P_0c0a81f0;
case 0x0c0a81f2u: goto P_0c0a81f2;
case 0x0c0a81f4u: goto P_0c0a81f4;
case 0x0c0a81f6u: goto P_0c0a81f6;
case 0x0c0a81f8u: goto P_0c0a81f8;
case 0x0c0a81fau: goto P_0c0a81fa;
case 0x0c0a81fcu: goto P_0c0a81fc;
case 0x0c0a81feu: goto P_0c0a81fe;
case 0x0c0a8200u: goto P_0c0a8200;
case 0x0c0a8202u: goto P_0c0a8202;
case 0x0c0a8204u: goto P_0c0a8204;
case 0x0c0a8206u: goto P_0c0a8206;
case 0x0c0a8208u: goto P_0c0a8208;
case 0x0c0a820au: goto P_0c0a820a;
case 0x0c0a820cu: goto P_0c0a820c;
case 0x0c0a820eu: goto P_0c0a820e;
case 0x0c0a8210u: goto P_0c0a8210;
case 0x0c0a8212u: goto P_0c0a8212;
case 0x0c0a8214u: goto P_0c0a8214;
case 0x0c0a8216u: goto P_0c0a8216;
case 0x0c0a8218u: goto P_0c0a8218;
case 0x0c0a821au: goto P_0c0a821a;
case 0x0c0a821cu: goto P_0c0a821c;
case 0x0c0a821eu: goto P_0c0a821e;
case 0x0c0a8220u: goto P_0c0a8220;
case 0x0c0a8222u: goto P_0c0a8222;
case 0x0c0a8224u: goto P_0c0a8224;
case 0x0c0a8226u: goto P_0c0a8226;
case 0x0c0a8228u: goto P_0c0a8228;
case 0x0c0a822au: goto P_0c0a822a;
case 0x0c0a822cu: goto P_0c0a822c;
case 0x0c0a822eu: goto P_0c0a822e;
case 0x0c0a8230u: goto P_0c0a8230;
case 0x0c0a8232u: goto P_0c0a8232;
case 0x0c0a8234u: goto P_0c0a8234;
case 0x0c0a8236u: goto P_0c0a8236;
case 0x0c0a8238u: goto P_0c0a8238;
case 0x0c0a823au: goto P_0c0a823a;
case 0x0c0a823cu: goto P_0c0a823c;
case 0x0c0a823eu: goto P_0c0a823e;
case 0x0c0a8240u: goto P_0c0a8240;
case 0x0c0a8242u: goto P_0c0a8242;
case 0x0c0a8244u: goto P_0c0a8244;
case 0x0c0a8246u: goto P_0c0a8246;
case 0x0c0a8248u: goto P_0c0a8248;
case 0x0c0a824au: goto P_0c0a824a;
case 0x0c0a824cu: goto P_0c0a824c;
case 0x0c0a824eu: goto P_0c0a824e;
case 0x0c0a8250u: goto P_0c0a8250;
case 0x0c0a8252u: goto P_0c0a8252;
case 0x0c0a8254u: goto P_0c0a8254;
case 0x0c0a8256u: goto P_0c0a8256;
case 0x0c0a8258u: goto P_0c0a8258;
case 0x0c0a825au: goto P_0c0a825a;
case 0x0c0a825cu: goto P_0c0a825c;
case 0x0c0a825eu: goto P_0c0a825e;
case 0x0c0a8260u: goto P_0c0a8260;
case 0x0c0a8262u: goto P_0c0a8262;
case 0x0c0a8264u: goto P_0c0a8264;
case 0x0c0a8266u: goto P_0c0a8266;
case 0x0c0a8268u: goto P_0c0a8268;
case 0x0c0a826au: goto P_0c0a826a;
case 0x0c0a826cu: goto P_0c0a826c;
case 0x0c0a826eu: goto P_0c0a826e;
case 0x0c0a8270u: goto P_0c0a8270;
case 0x0c0a8272u: goto P_0c0a8272;
case 0x0c0a8274u: goto P_0c0a8274;
case 0x0c0a8276u: goto P_0c0a8276;
case 0x0c0a8278u: goto P_0c0a8278;
case 0x0c0a827au: goto P_0c0a827a;
case 0x0c0a827cu: goto P_0c0a827c;
case 0x0c0a827eu: goto P_0c0a827e;
case 0x0c0a8280u: goto P_0c0a8280;
case 0x0c0a8282u: goto P_0c0a8282;
case 0x0c0a8284u: goto P_0c0a8284;
case 0x0c0a8286u: goto P_0c0a8286;
case 0x0c0a8288u: goto P_0c0a8288;
case 0x0c0a828au: goto P_0c0a828a;
case 0x0c0a828cu: goto P_0c0a828c;
case 0x0c0a828eu: goto P_0c0a828e;
case 0x0c0a8290u: goto P_0c0a8290;
case 0x0c0a8292u: goto P_0c0a8292;
case 0x0c0a8294u: goto P_0c0a8294;
case 0x0c0a8296u: goto P_0c0a8296;
case 0x0c0a8298u: goto P_0c0a8298;
case 0x0c0a829au: goto P_0c0a829a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2d48: /* original 2fe6, guest PC 0x0c0a2d48 */
if(!s->budget--) { s->failed_pc=0x0c0a2d48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2d4a;
P_0c0a2d4a: /* original 6e43, guest PC 0x0c0a2d4a */
if(!s->budget--) { s->failed_pc=0x0c0a2d4au; return 0; }
r[14]=r[4];
goto P_0c0a2d4c;
P_0c0a2d4c: /* original 2fd6, guest PC 0x0c0a2d4c */
if(!s->budget--) { s->failed_pc=0x0c0a2d4cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2d4e;
P_0c0a2d4e: /* original 6d53, guest PC 0x0c0a2d4e */
if(!s->budget--) { s->failed_pc=0x0c0a2d4eu; return 0; }
r[13]=r[5];
goto P_0c0a2d50;
P_0c0a2d50: /* original 4f22, guest PC 0x0c0a2d50 */
if(!s->budget--) { s->failed_pc=0x0c0a2d50u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2d52;
P_0c0a2d52: /* original 53e1, guest PC 0x0c0a2d52 */
if(!s->budget--) { s->failed_pc=0x0c0a2d52u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d54;
P_0c0a2d54: /* original 2338, guest PC 0x0c0a2d54 */
if(!s->budget--) { s->failed_pc=0x0c0a2d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d56;
P_0c0a2d56: /* original 8933, guest PC 0x0c0a2d56 */
if(!s->budget--) { s->failed_pc=0x0c0a2d56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dc0; }
goto P_0c0a2d58;
P_0c0a2d58: /* original 53e1, guest PC 0x0c0a2d58 */
if(!s->budget--) { s->failed_pc=0x0c0a2d58u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d5a;
P_0c0a2d5a: /* original 33d2, guest PC 0x0c0a2d5a */
if(!s->budget--) { s->failed_pc=0x0c0a2d5au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d5c;
P_0c0a2d5c: /* original 8930, guest PC 0x0c0a2d5c */
if(!s->budget--) { s->failed_pc=0x0c0a2d5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dc0; }
goto P_0c0a2d5e;
P_0c0a2d5e: /* original 51e1, guest PC 0x0c0a2d5e */
if(!s->budget--) { s->failed_pc=0x0c0a2d5eu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c0a2d60;
P_0c0a2d60: /* original 31dc, guest PC 0x0c0a2d60 */
if(!s->budget--) { s->failed_pc=0x0c0a2d60u; return 0; }
r[1]+=r[13];
goto P_0c0a2d62;
P_0c0a2d62: /* original 6313, guest PC 0x0c0a2d62 */
if(!s->budget--) { s->failed_pc=0x0c0a2d62u; return 0; }
r[3]=r[1];
goto P_0c0a2d64;
P_0c0a2d64: /* original 1e11, guest PC 0x0c0a2d64 */
if(!s->budget--) { s->failed_pc=0x0c0a2d64u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c0a2d66;
P_0c0a2d66: /* original 5231, guest PC 0x0c0a2d66 */
if(!s->budget--) { s->failed_pc=0x0c0a2d66u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2d68;
P_0c0a2d68: /* original 2228, guest PC 0x0c0a2d68 */
if(!s->budget--) { s->failed_pc=0x0c0a2d68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2d6a;
P_0c0a2d6a: /* original 8907, guest PC 0x0c0a2d6a */
if(!s->budget--) { s->failed_pc=0x0c0a2d6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d7c; }
goto P_0c0a2d6c;
P_0c0a2d6c: /* original 52e1, guest PC 0x0c0a2d6c */
if(!s->budget--) { s->failed_pc=0x0c0a2d6cu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2d6e;
P_0c0a2d6e: /* original 5321, guest PC 0x0c0a2d6e */
if(!s->budget--) { s->failed_pc=0x0c0a2d6eu; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c0a2d70;
P_0c0a2d70: /* original 33d2, guest PC 0x0c0a2d70 */
if(!s->budget--) { s->failed_pc=0x0c0a2d70u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d72;
P_0c0a2d72: /* original 8903, guest PC 0x0c0a2d72 */
if(!s->budget--) { s->failed_pc=0x0c0a2d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d7c; }
goto P_0c0a2d74;
P_0c0a2d74: /* original 54e1, guest PC 0x0c0a2d74 */
if(!s->budget--) { s->failed_pc=0x0c0a2d74u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0a2d76;
P_0c0a2d76: /* original 5341, guest PC 0x0c0a2d76 */
if(!s->budget--) { s->failed_pc=0x0c0a2d76u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a2d78;
P_0c0a2d78: /* original 33dc, guest PC 0x0c0a2d78 */
if(!s->budget--) { s->failed_pc=0x0c0a2d78u; return 0; }
r[3]+=r[13];
goto P_0c0a2d7a;
P_0c0a2d7a: /* original 1431, guest PC 0x0c0a2d7a */
if(!s->budget--) { s->failed_pc=0x0c0a2d7au; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a2d7c;
P_0c0a2d7c: /* original 52e1, guest PC 0x0c0a2d7c */
if(!s->budget--) { s->failed_pc=0x0c0a2d7cu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2d7e;
P_0c0a2d7e: /* original 5323, guest PC 0x0c0a2d7e */
if(!s->budget--) { s->failed_pc=0x0c0a2d7eu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0a2d80;
P_0c0a2d80: /* original 2338, guest PC 0x0c0a2d80 */
if(!s->budget--) { s->failed_pc=0x0c0a2d80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d82;
P_0c0a2d82: /* original 8907, guest PC 0x0c0a2d82 */
if(!s->budget--) { s->failed_pc=0x0c0a2d82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d94; }
goto P_0c0a2d84;
P_0c0a2d84: /* original 53e1, guest PC 0x0c0a2d84 */
if(!s->budget--) { s->failed_pc=0x0c0a2d84u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d86;
P_0c0a2d86: /* original 5233, guest PC 0x0c0a2d86 */
if(!s->budget--) { s->failed_pc=0x0c0a2d86u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c0a2d88;
P_0c0a2d88: /* original 32d2, guest PC 0x0c0a2d88 */
if(!s->budget--) { s->failed_pc=0x0c0a2d88u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[13])!=0);
goto P_0c0a2d8a;
P_0c0a2d8a: /* original 8903, guest PC 0x0c0a2d8a */
if(!s->budget--) { s->failed_pc=0x0c0a2d8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d94; }
goto P_0c0a2d8c;
P_0c0a2d8c: /* original 54e1, guest PC 0x0c0a2d8c */
if(!s->budget--) { s->failed_pc=0x0c0a2d8cu; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0a2d8e;
P_0c0a2d8e: /* original 5243, guest PC 0x0c0a2d8e */
if(!s->budget--) { s->failed_pc=0x0c0a2d8eu; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0a2d90;
P_0c0a2d90: /* original 32dc, guest PC 0x0c0a2d90 */
if(!s->budget--) { s->failed_pc=0x0c0a2d90u; return 0; }
r[2]+=r[13];
goto P_0c0a2d92;
P_0c0a2d92: /* original 1423, guest PC 0x0c0a2d92 */
if(!s->budget--) { s->failed_pc=0x0c0a2d92u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0a2d94;
P_0c0a2d94: /* original c718, guest PC 0x0c0a2d94 */
if(!s->budget--) { s->failed_pc=0x0c0a2d94u; return 0; }
r[0]=code_base|0x000a2df8u;
goto P_0c0a2d96;
P_0c0a2d96: /* original 53e1, guest PC 0x0c0a2d96 */
if(!s->budget--) { s->failed_pc=0x0c0a2d96u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d98;
P_0c0a2d98: /* original f408, guest PC 0x0c0a2d98 */
if(!s->budget--) { s->failed_pc=0x0c0a2d98u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a2d9a;
P_0c0a2d9a: /* original e010, guest PC 0x0c0a2d9a */
if(!s->budget--) { s->failed_pc=0x0c0a2d9au; return 0; }
r[0]=0x00000010u;
goto P_0c0a2d9c;
P_0c0a2d9c: /* original f336, guest PC 0x0c0a2d9c */
if(!s->budget--) { s->failed_pc=0x0c0a2d9cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2d9e;
P_0c0a2d9e: /* original f342, guest PC 0x0c0a2d9e */
if(!s->budget--) { s->failed_pc=0x0c0a2d9eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2da0;
P_0c0a2da0: /* original f337, guest PC 0x0c0a2da0 */
if(!s->budget--) { s->failed_pc=0x0c0a2da0u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2da2;
P_0c0a2da2: /* original e014, guest PC 0x0c0a2da2 */
if(!s->budget--) { s->failed_pc=0x0c0a2da2u; return 0; }
r[0]=0x00000014u;
goto P_0c0a2da4;
P_0c0a2da4: /* original 53e1, guest PC 0x0c0a2da4 */
if(!s->budget--) { s->failed_pc=0x0c0a2da4u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2da6;
P_0c0a2da6: /* original f336, guest PC 0x0c0a2da6 */
if(!s->budget--) { s->failed_pc=0x0c0a2da6u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2da8;
P_0c0a2da8: /* original f342, guest PC 0x0c0a2da8 */
if(!s->budget--) { s->failed_pc=0x0c0a2da8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2daa;
P_0c0a2daa: /* original f337, guest PC 0x0c0a2daa */
if(!s->budget--) { s->failed_pc=0x0c0a2daau; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2dac;
P_0c0a2dac: /* original e018, guest PC 0x0c0a2dac */
if(!s->budget--) { s->failed_pc=0x0c0a2dacu; return 0; }
r[0]=0x00000018u;
goto P_0c0a2dae;
P_0c0a2dae: /* original 53e1, guest PC 0x0c0a2dae */
if(!s->budget--) { s->failed_pc=0x0c0a2daeu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2db0;
P_0c0a2db0: /* original f336, guest PC 0x0c0a2db0 */
if(!s->budget--) { s->failed_pc=0x0c0a2db0u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2db2;
P_0c0a2db2: /* original f342, guest PC 0x0c0a2db2 */
if(!s->budget--) { s->failed_pc=0x0c0a2db2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2db4;
P_0c0a2db4: /* original f337, guest PC 0x0c0a2db4 */
if(!s->budget--) { s->failed_pc=0x0c0a2db4u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2db6;
P_0c0a2db6: /* original e01c, guest PC 0x0c0a2db6 */
if(!s->budget--) { s->failed_pc=0x0c0a2db6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a2db8;
P_0c0a2db8: /* original 53e1, guest PC 0x0c0a2db8 */
if(!s->budget--) { s->failed_pc=0x0c0a2db8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2dba;
P_0c0a2dba: /* original f336, guest PC 0x0c0a2dba */
if(!s->budget--) { s->failed_pc=0x0c0a2dbau; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2dbc;
P_0c0a2dbc: /* original f342, guest PC 0x0c0a2dbc */
if(!s->budget--) { s->failed_pc=0x0c0a2dbcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2dbe;
P_0c0a2dbe: /* original f337, guest PC 0x0c0a2dbe */
if(!s->budget--) { s->failed_pc=0x0c0a2dbeu; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2dc0;
P_0c0a2dc0: /* original 53eb, guest PC 0x0c0a2dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc0u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0a2dc2;
P_0c0a2dc2: /* original 2338, guest PC 0x0c0a2dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2dc4;
P_0c0a2dc4: /* original 8908, guest PC 0x0c0a2dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dd8; }
goto P_0c0a2dc6;
P_0c0a2dc6: /* original 53eb, guest PC 0x0c0a2dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc6u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0a2dc8;
P_0c0a2dc8: /* original 33d2, guest PC 0x0c0a2dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2dca;
P_0c0a2dca: /* original 8905, guest PC 0x0c0a2dca */
if(!s->budget--) { s->failed_pc=0x0c0a2dcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dd8; }
goto P_0c0a2dcc;
P_0c0a2dcc: /* original 51eb, guest PC 0x0c0a2dcc */
if(!s->budget--) { s->failed_pc=0x0c0a2dccu; return 0; }
r[1]=read(ram,r[14]+44,4);
goto P_0c0a2dce;
P_0c0a2dce: /* original 65d3, guest PC 0x0c0a2dce */
if(!s->budget--) { s->failed_pc=0x0c0a2dceu; return 0; }
r[5]=r[13];
goto P_0c0a2dd0;
P_0c0a2dd0: /* original 31dc, guest PC 0x0c0a2dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd0u; return 0; }
r[1]+=r[13];
goto P_0c0a2dd2;
P_0c0a2dd2: /* original 1e1b, guest PC 0x0c0a2dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd2u; return 0; }
write(ram,r[14]+44,r[1],4);
goto P_0c0a2dd4;
P_0c0a2dd4: /* original bfb8, guest PC 0x0c0a2dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd4u; return 0; }
target=code_base|0x0c0a2d48u; r[16]=code_base|0x0c0a2dd8u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2dd8u) { target=s->pc; goto dispatch; }
goto P_0c0a2dd8;
P_0c0a2dd6: /* original 6413, guest PC 0x0c0a2dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd6u; return 0; }
r[4]=r[1];
goto P_0c0a2dd8;
P_0c0a2dd8: /* original 52ec, guest PC 0x0c0a2dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd8u; return 0; }
r[2]=read(ram,r[14]+48,4);
goto P_0c0a2dda;
P_0c0a2dda: /* original 2228, guest PC 0x0c0a2dda */
if(!s->budget--) { s->failed_pc=0x0c0a2ddau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2ddc;
P_0c0a2ddc: /* original 8908, guest PC 0x0c0a2ddc */
if(!s->budget--) { s->failed_pc=0x0c0a2ddcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2df0; }
goto P_0c0a2dde;
P_0c0a2dde: /* original 53ec, guest PC 0x0c0a2dde */
if(!s->budget--) { s->failed_pc=0x0c0a2ddeu; return 0; }
r[3]=read(ram,r[14]+48,4);
goto P_0c0a2de0;
P_0c0a2de0: /* original 33d2, guest PC 0x0c0a2de0 */
if(!s->budget--) { s->failed_pc=0x0c0a2de0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2de2;
P_0c0a2de2: /* original 8905, guest PC 0x0c0a2de2 */
if(!s->budget--) { s->failed_pc=0x0c0a2de2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2df0; }
goto P_0c0a2de4;
P_0c0a2de4: /* original 51ec, guest PC 0x0c0a2de4 */
if(!s->budget--) { s->failed_pc=0x0c0a2de4u; return 0; }
r[1]=read(ram,r[14]+48,4);
goto P_0c0a2de6;
P_0c0a2de6: /* original 64d3, guest PC 0x0c0a2de6 */
if(!s->budget--) { s->failed_pc=0x0c0a2de6u; return 0; }
r[4]=r[13];
goto P_0c0a2de8;
P_0c0a2de8: /* original 31dc, guest PC 0x0c0a2de8 */
if(!s->budget--) { s->failed_pc=0x0c0a2de8u; return 0; }
r[1]+=r[13];
goto P_0c0a2dea;
P_0c0a2dea: /* original 1e1c, guest PC 0x0c0a2dea */
if(!s->budget--) { s->failed_pc=0x0c0a2deau; return 0; }
write(ram,r[14]+48,r[1],4);
goto P_0c0a2dec;
P_0c0a2dec: /* original afb1, guest PC 0x0c0a2dec */
if(!s->budget--) { s->failed_pc=0x0c0a2decu; return 0; }
r[14]=r[1];
goto P_0c0a2d52;
P_0c0a2dee: /* original 6e13, guest PC 0x0c0a2dee */
if(!s->budget--) { s->failed_pc=0x0c0a2deeu; return 0; }
r[14]=r[1];
goto P_0c0a2df0;
P_0c0a2df0: /* original 4f26, guest PC 0x0c0a2df0 */
if(!s->budget--) { s->failed_pc=0x0c0a2df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2df2;
P_0c0a2df2: /* original 6df6, guest PC 0x0c0a2df2 */
if(!s->budget--) { s->failed_pc=0x0c0a2df2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2df4;
P_0c0a2df4: /* original 000b, guest PC 0x0c0a2df4 */
if(!s->budget--) { s->failed_pc=0x0c0a2df4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2df6: /* original 6ef6, guest PC 0x0c0a2df6 */
if(!s->budget--) { s->failed_pc=0x0c0a2df6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2df8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2df8u; return 0; } return 1;
P_0c0a7f14: /* original 2fe6, guest PC 0x0c0a7f14 */
if(!s->budget--) { s->failed_pc=0x0c0a7f14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f16;
P_0c0a7f16: /* original d324, guest PC 0x0c0a7f16 */
if(!s->budget--) { s->failed_pc=0x0c0a7f16u; return 0; }
r[3]=read(ram,0x0c0a7fa8u,4);
goto P_0c0a7f18;
P_0c0a7f18: /* original 4f12, guest PC 0x0c0a7f18 */
if(!s->budget--) { s->failed_pc=0x0c0a7f18u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a7f1a;
P_0c0a7f1a: /* original 6632, guest PC 0x0c0a7f1a */
if(!s->budget--) { s->failed_pc=0x0c0a7f1au; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0a7f1c;
P_0c0a7f1c: /* original 856d, guest PC 0x0c0a7f1c */
if(!s->budget--) { s->failed_pc=0x0c0a7f1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+26,2);
goto P_0c0a7f1e;
P_0c0a7f1e: /* original 670d, guest PC 0x0c0a7f1e */
if(!s->budget--) { s->failed_pc=0x0c0a7f1eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c0a7f20;
P_0c0a7f20: /* original a012, guest PC 0x0c0a7f20 */
if(!s->budget--) { s->failed_pc=0x0c0a7f20u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f48;
P_0c0a7f22: /* original ee1f, guest PC 0x0c0a7f22 */
if(!s->budget--) { s->failed_pc=0x0c0a7f22u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f24;
P_0c0a7f24: /* original 856b, guest PC 0x0c0a7f24 */
if(!s->budget--) { s->failed_pc=0x0c0a7f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a7f26;
P_0c0a7f26: /* original 600d, guest PC 0x0c0a7f26 */
if(!s->budget--) { s->failed_pc=0x0c0a7f26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a7f28;
P_0c0a7f28: /* original 3500, guest PC 0x0c0a7f28 */
if(!s->budget--) { s->failed_pc=0x0c0a7f28u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[0])!=0);
goto P_0c0a7f2a;
P_0c0a7f2a: /* original 8910, guest PC 0x0c0a7f2a */
if(!s->budget--) { s->failed_pc=0x0c0a7f2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7f4e; }
goto P_0c0a7f2c;
P_0c0a7f2c: /* original e334, guest PC 0x0c0a7f2c */
if(!s->budget--) { s->failed_pc=0x0c0a7f2cu; return 0; }
r[3]=0x00000034u;
goto P_0c0a7f2e;
P_0c0a7f2e: /* original 6263, guest PC 0x0c0a7f2e */
if(!s->budget--) { s->failed_pc=0x0c0a7f2eu; return 0; }
r[2]=r[6];
goto P_0c0a7f30;
P_0c0a7f30: /* original 253f, guest PC 0x0c0a7f30 */
if(!s->budget--) { s->failed_pc=0x0c0a7f30u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[5]*(int32_t)(int16_t)r[3]);
goto P_0c0a7f32;
P_0c0a7f32: /* original 721c, guest PC 0x0c0a7f32 */
if(!s->budget--) { s->failed_pc=0x0c0a7f32u; return 0; }
r[2]+=0x0000001cu;
goto P_0c0a7f34;
P_0c0a7f34: /* original e030, guest PC 0x0c0a7f34 */
if(!s->budget--) { s->failed_pc=0x0c0a7f34u; return 0; }
r[0]=0x00000030u;
goto P_0c0a7f36;
P_0c0a7f36: /* original 051a, guest PC 0x0c0a7f36 */
if(!s->budget--) { s->failed_pc=0x0c0a7f36u; return 0; }
r[5]=r[19];
goto P_0c0a7f38;
P_0c0a7f38: /* original 655f, guest PC 0x0c0a7f38 */
if(!s->budget--) { s->failed_pc=0x0c0a7f38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a7f3a;
P_0c0a7f3a: /* original 352c, guest PC 0x0c0a7f3a */
if(!s->budget--) { s->failed_pc=0x0c0a7f3au; return 0; }
r[5]+=r[2];
goto P_0c0a7f3c;
P_0c0a7f3c: /* original 015d, guest PC 0x0c0a7f3c */
if(!s->budget--) { s->failed_pc=0x0c0a7f3cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a7f3e;
P_0c0a7f3e: /* original 3140, guest PC 0x0c0a7f3e */
if(!s->budget--) { s->failed_pc=0x0c0a7f3eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c0a7f40;
P_0c0a7f40: /* original 8b01, guest PC 0x0c0a7f40 */
if(!s->budget--) { s->failed_pc=0x0c0a7f40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7f46; }
goto P_0c0a7f42;
P_0c0a7f42: /* original a005, guest PC 0x0c0a7f42 */
if(!s->budget--) { s->failed_pc=0x0c0a7f42u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f50;
P_0c0a7f44: /* original e001, guest PC 0x0c0a7f44 */
if(!s->budget--) { s->failed_pc=0x0c0a7f44u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f46;
P_0c0a7f46: /* original 77ff, guest PC 0x0c0a7f46 */
if(!s->budget--) { s->failed_pc=0x0c0a7f46u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0a7f48;
P_0c0a7f48: /* original 6573, guest PC 0x0c0a7f48 */
if(!s->budget--) { s->failed_pc=0x0c0a7f48u; return 0; }
r[5]=r[7];
goto P_0c0a7f4a;
P_0c0a7f4a: /* original afeb, guest PC 0x0c0a7f4a */
if(!s->budget--) { s->failed_pc=0x0c0a7f4au; return 0; }
r[5]&=r[14];
goto P_0c0a7f24;
P_0c0a7f4c: /* original 25e9, guest PC 0x0c0a7f4c */
if(!s->budget--) { s->failed_pc=0x0c0a7f4cu; return 0; }
r[5]&=r[14];
goto P_0c0a7f4e;
P_0c0a7f4e: /* original e000, guest PC 0x0c0a7f4e */
if(!s->budget--) { s->failed_pc=0x0c0a7f4eu; return 0; }
r[0]=0x00000000u;
goto P_0c0a7f50;
P_0c0a7f50: /* original 4f16, guest PC 0x0c0a7f50 */
if(!s->budget--) { s->failed_pc=0x0c0a7f50u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7f52;
P_0c0a7f52: /* original 000b, guest PC 0x0c0a7f52 */
if(!s->budget--) { s->failed_pc=0x0c0a7f52u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7f54: /* original 6ef6, guest PC 0x0c0a7f54 */
if(!s->budget--) { s->failed_pc=0x0c0a7f54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7f56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7f56u; return 0; } return 1;
P_0c0a81ee: /* original 2fe6, guest PC 0x0c0a81ee */
if(!s->budget--) { s->failed_pc=0x0c0a81eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f0;
P_0c0a81f0: /* original 2fd6, guest PC 0x0c0a81f0 */
if(!s->budget--) { s->failed_pc=0x0c0a81f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f2;
P_0c0a81f2: /* original 2fc6, guest PC 0x0c0a81f2 */
if(!s->budget--) { s->failed_pc=0x0c0a81f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f4;
P_0c0a81f4: /* original 2fb6, guest PC 0x0c0a81f4 */
if(!s->budget--) { s->failed_pc=0x0c0a81f4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f6;
P_0c0a81f6: /* original 6b43, guest PC 0x0c0a81f6 */
if(!s->budget--) { s->failed_pc=0x0c0a81f6u; return 0; }
r[11]=r[4];
goto P_0c0a81f8;
P_0c0a81f8: /* original 2fa6, guest PC 0x0c0a81f8 */
if(!s->budget--) { s->failed_pc=0x0c0a81f8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81fa;
P_0c0a81fa: /* original eaff, guest PC 0x0c0a81fa */
if(!s->budget--) { s->failed_pc=0x0c0a81fau; return 0; }
r[10]=0xffffffffu;
goto P_0c0a81fc;
P_0c0a81fc: /* original 4f22, guest PC 0x0c0a81fc */
if(!s->budget--) { s->failed_pc=0x0c0a81fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a81fe;
P_0c0a81fe: /* original 4f12, guest PC 0x0c0a81fe */
if(!s->budget--) { s->failed_pc=0x0c0a81feu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8200;
P_0c0a8200: /* original 7ff0, guest PC 0x0c0a8200 */
if(!s->budget--) { s->failed_pc=0x0c0a8200u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8202;
P_0c0a8202: /* original 1f51, guest PC 0x0c0a8202 */
if(!s->budget--) { s->failed_pc=0x0c0a8202u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a8204;
P_0c0a8204: /* original 2f62, guest PC 0x0c0a8204 */
if(!s->budget--) { s->failed_pc=0x0c0a8204u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a8206;
P_0c0a8206: /* original 1f72, guest PC 0x0c0a8206 */
if(!s->budget--) { s->failed_pc=0x0c0a8206u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a8208;
P_0c0a8208: /* original d32a, guest PC 0x0c0a8208 */
if(!s->budget--) { s->failed_pc=0x0c0a8208u; return 0; }
r[3]=read(ram,0x0c0a82b4u,4);
goto P_0c0a820a;
P_0c0a820a: /* original 9249, guest PC 0x0c0a820a */
if(!s->budget--) { s->failed_pc=0x0c0a820au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a82a0u,2);
goto P_0c0a820c;
P_0c0a820c: /* original 6e32, guest PC 0x0c0a820c */
if(!s->budget--) { s->failed_pc=0x0c0a820cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a820e;
P_0c0a820e: /* original 3b23, guest PC 0x0c0a820e */
if(!s->budget--) { s->failed_pc=0x0c0a820eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c0a8210;
P_0c0a8210: /* original 8f03, guest PC 0x0c0a8210 */
if(!s->budget--) { s->failed_pc=0x0c0a8210u; return 0; }
cond=r[17]&1u;
r[12]=r[10];
if(!cond) { goto P_0c0a821a; }
goto P_0c0a8214;
P_0c0a8212: /* original 6ca3, guest PC 0x0c0a8212 */
if(!s->budget--) { s->failed_pc=0x0c0a8212u; return 0; }
r[12]=r[10];
goto P_0c0a8214;
P_0c0a8214: /* original dc28, guest PC 0x0c0a8214 */
if(!s->budget--) { s->failed_pc=0x0c0a8214u; return 0; }
r[12]=read(ram,0x0c0a82b8u,4);
goto P_0c0a8216;
P_0c0a8216: /* original a037, guest PC 0x0c0a8216 */
if(!s->budget--) { s->failed_pc=0x0c0a8216u; return 0; }
goto P_0c0a8288;
P_0c0a8218: /* original 0009, guest PC 0x0c0a8218 */
if(!s->budget--) { s->failed_pc=0x0c0a8218u; return 0; }
goto P_0c0a821a;
P_0c0a821a: /* original d028, guest PC 0x0c0a821a */
if(!s->budget--) { s->failed_pc=0x0c0a821au; return 0; }
r[0]=read(ram,0x0c0a82bcu,4);
goto P_0c0a821c;
P_0c0a821c: /* original 63b3, guest PC 0x0c0a821c */
if(!s->budget--) { s->failed_pc=0x0c0a821cu; return 0; }
r[3]=r[11];
goto P_0c0a821e;
P_0c0a821e: /* original 4308, guest PC 0x0c0a821e */
if(!s->budget--) { s->failed_pc=0x0c0a821eu; return 0; }
r[3]<<=2;
goto P_0c0a8220;
P_0c0a8220: /* original 023e, guest PC 0x0c0a8220 */
if(!s->budget--) { s->failed_pc=0x0c0a8220u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a8222;
P_0c0a8222: /* original 1f23, guest PC 0x0c0a8222 */
if(!s->budget--) { s->failed_pc=0x0c0a8222u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0a8224;
P_0c0a8224: /* original 63f2, guest PC 0x0c0a8224 */
if(!s->budget--) { s->failed_pc=0x0c0a8224u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a8226;
P_0c0a8226: /* original 2338, guest PC 0x0c0a8226 */
if(!s->budget--) { s->failed_pc=0x0c0a8226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a8228;
P_0c0a8228: /* original 892e, guest PC 0x0c0a8228 */
if(!s->budget--) { s->failed_pc=0x0c0a8228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a822a;
P_0c0a822a: /* original 50f1, guest PC 0x0c0a822a */
if(!s->budget--) { s->failed_pc=0x0c0a822au; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a822c;
P_0c0a822c: /* original c803, guest PC 0x0c0a822c */
if(!s->budget--) { s->failed_pc=0x0c0a822cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&3u)==0)!=0);
goto P_0c0a822e;
P_0c0a822e: /* original 8b2b, guest PC 0x0c0a822e */
if(!s->budget--) { s->failed_pc=0x0c0a822eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a8230;
P_0c0a8230: /* original 85ed, guest PC 0x0c0a8230 */
if(!s->budget--) { s->failed_pc=0x0c0a8230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8232;
P_0c0a8232: /* original ed1f, guest PC 0x0c0a8232 */
if(!s->budget--) { s->failed_pc=0x0c0a8232u; return 0; }
r[13]=0x0000001fu;
goto P_0c0a8234;
P_0c0a8234: /* original 600d, guest PC 0x0c0a8234 */
if(!s->budget--) { s->failed_pc=0x0c0a8234u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a8236;
P_0c0a8236: /* original 7001, guest PC 0x0c0a8236 */
if(!s->budget--) { s->failed_pc=0x0c0a8236u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8238;
P_0c0a8238: /* original 2d09, guest PC 0x0c0a8238 */
if(!s->budget--) { s->failed_pc=0x0c0a8238u; return 0; }
r[13]&=r[0];
goto P_0c0a823a;
P_0c0a823a: /* original 85eb, guest PC 0x0c0a823a */
if(!s->budget--) { s->failed_pc=0x0c0a823au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a823c;
P_0c0a823c: /* original 600d, guest PC 0x0c0a823c */
if(!s->budget--) { s->failed_pc=0x0c0a823cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a823e;
P_0c0a823e: /* original 3d00, guest PC 0x0c0a823e */
if(!s->budget--) { s->failed_pc=0x0c0a823eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0a8240;
P_0c0a8240: /* original 8922, guest PC 0x0c0a8240 */
if(!s->budget--) { s->failed_pc=0x0c0a8240u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a8242;
P_0c0a8242: /* original be67, guest PC 0x0c0a8242 */
if(!s->budget--) { s->failed_pc=0x0c0a8242u; return 0; }
target=code_base|0x0c0a7f14u; r[16]=code_base|0x0c0a8246u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8246u) { target=s->pc; goto dispatch; }
goto P_0c0a8246;
P_0c0a8244: /* original 64b3, guest PC 0x0c0a8244 */
if(!s->budget--) { s->failed_pc=0x0c0a8244u; return 0; }
r[4]=r[11];
goto P_0c0a8246;
P_0c0a8246: /* original 2008, guest PC 0x0c0a8246 */
if(!s->budget--) { s->failed_pc=0x0c0a8246u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8248;
P_0c0a8248: /* original 8b1e, guest PC 0x0c0a8248 */
if(!s->budget--) { s->failed_pc=0x0c0a8248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a824a;
P_0c0a824a: /* original e434, guest PC 0x0c0a824a */
if(!s->budget--) { s->failed_pc=0x0c0a824au; return 0; }
r[4]=0x00000034u;
goto P_0c0a824c;
P_0c0a824c: /* original 63e3, guest PC 0x0c0a824c */
if(!s->budget--) { s->failed_pc=0x0c0a824cu; return 0; }
r[3]=r[14];
goto P_0c0a824e;
P_0c0a824e: /* original 2d4f, guest PC 0x0c0a824e */
if(!s->budget--) { s->failed_pc=0x0c0a824eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[4]);
goto P_0c0a8250;
P_0c0a8250: /* original 731c, guest PC 0x0c0a8250 */
if(!s->budget--) { s->failed_pc=0x0c0a8250u; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8252;
P_0c0a8252: /* original 60d3, guest PC 0x0c0a8252 */
if(!s->budget--) { s->failed_pc=0x0c0a8252u; return 0; }
r[0]=r[13];
goto P_0c0a8254;
P_0c0a8254: /* original 81ed, guest PC 0x0c0a8254 */
if(!s->budget--) { s->failed_pc=0x0c0a8254u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0a8256;
P_0c0a8256: /* original e030, guest PC 0x0c0a8256 */
if(!s->budget--) { s->failed_pc=0x0c0a8256u; return 0; }
r[0]=0x00000030u;
goto P_0c0a8258;
P_0c0a8258: /* original 62f2, guest PC 0x0c0a8258 */
if(!s->budget--) { s->failed_pc=0x0c0a8258u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a825a;
P_0c0a825a: /* original 6cd3, guest PC 0x0c0a825a */
if(!s->budget--) { s->failed_pc=0x0c0a825au; return 0; }
r[12]=r[13];
goto P_0c0a825c;
P_0c0a825c: /* original 041a, guest PC 0x0c0a825c */
if(!s->budget--) { s->failed_pc=0x0c0a825cu; return 0; }
r[4]=r[19];
goto P_0c0a825e;
P_0c0a825e: /* original 644f, guest PC 0x0c0a825e */
if(!s->budget--) { s->failed_pc=0x0c0a825eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8260;
P_0c0a8260: /* original 343c, guest PC 0x0c0a8260 */
if(!s->budget--) { s->failed_pc=0x0c0a8260u; return 0; }
r[4]+=r[3];
goto P_0c0a8262;
P_0c0a8262: /* original 6323, guest PC 0x0c0a8262 */
if(!s->budget--) { s->failed_pc=0x0c0a8262u; return 0; }
r[3]=r[2];
goto P_0c0a8264;
P_0c0a8264: /* original 2422, guest PC 0x0c0a8264 */
if(!s->budget--) { s->failed_pc=0x0c0a8264u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0a8266;
P_0c0a8266: /* original e200, guest PC 0x0c0a8266 */
if(!s->budget--) { s->failed_pc=0x0c0a8266u; return 0; }
r[2]=0x00000000u;
goto P_0c0a8268;
P_0c0a8268: /* original 2322, guest PC 0x0c0a8268 */
if(!s->budget--) { s->failed_pc=0x0c0a8268u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0a826a;
P_0c0a826a: /* original 53f1, guest PC 0x0c0a826a */
if(!s->budget--) { s->failed_pc=0x0c0a826au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a826c;
P_0c0a826c: /* original 1431, guest PC 0x0c0a826c */
if(!s->budget--) { s->failed_pc=0x0c0a826cu; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a826e;
P_0c0a826e: /* original 14a7, guest PC 0x0c0a826e */
if(!s->budget--) { s->failed_pc=0x0c0a826eu; return 0; }
write(ram,r[4]+28,r[10],4);
goto P_0c0a8270;
P_0c0a8270: /* original 14a2, guest PC 0x0c0a8270 */
if(!s->budget--) { s->failed_pc=0x0c0a8270u; return 0; }
write(ram,r[4]+8,r[10],4);
goto P_0c0a8272;
P_0c0a8272: /* original 53f3, guest PC 0x0c0a8272 */
if(!s->budget--) { s->failed_pc=0x0c0a8272u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a8274;
P_0c0a8274: /* original 1434, guest PC 0x0c0a8274 */
if(!s->budget--) { s->failed_pc=0x0c0a8274u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0a8276;
P_0c0a8276: /* original 52f2, guest PC 0x0c0a8276 */
if(!s->budget--) { s->failed_pc=0x0c0a8276u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a8278;
P_0c0a8278: /* original 1425, guest PC 0x0c0a8278 */
if(!s->budget--) { s->failed_pc=0x0c0a8278u; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c0a827a;
P_0c0a827a: /* original 53fb, guest PC 0x0c0a827a */
if(!s->budget--) { s->failed_pc=0x0c0a827au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0a827c;
P_0c0a827c: /* original 1436, guest PC 0x0c0a827c */
if(!s->budget--) { s->failed_pc=0x0c0a827cu; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0a827e;
P_0c0a827e: /* original 52fc, guest PC 0x0c0a827e */
if(!s->budget--) { s->failed_pc=0x0c0a827eu; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c0a8280;
P_0c0a8280: /* original 142a, guest PC 0x0c0a8280 */
if(!s->budget--) { s->failed_pc=0x0c0a8280u; return 0; }
write(ram,r[4]+40,r[2],4);
goto P_0c0a8282;
P_0c0a8282: /* original 53fd, guest PC 0x0c0a8282 */
if(!s->budget--) { s->failed_pc=0x0c0a8282u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0a8284;
P_0c0a8284: /* original 143b, guest PC 0x0c0a8284 */
if(!s->budget--) { s->failed_pc=0x0c0a8284u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0a8286;
P_0c0a8286: /* original 04b5, guest PC 0x0c0a8286 */
if(!s->budget--) { s->failed_pc=0x0c0a8286u; return 0; }
write(ram,r[4]+r[0],r[11],2);
goto P_0c0a8288;
P_0c0a8288: /* original 7f10, guest PC 0x0c0a8288 */
if(!s->budget--) { s->failed_pc=0x0c0a8288u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a828a;
P_0c0a828a: /* original 60c3, guest PC 0x0c0a828a */
if(!s->budget--) { s->failed_pc=0x0c0a828au; return 0; }
r[0]=r[12];
goto P_0c0a828c;
P_0c0a828c: /* original 4f16, guest PC 0x0c0a828c */
if(!s->budget--) { s->failed_pc=0x0c0a828cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a828e;
P_0c0a828e: /* original 4f26, guest PC 0x0c0a828e */
if(!s->budget--) { s->failed_pc=0x0c0a828eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8290;
P_0c0a8290: /* original 6af6, guest PC 0x0c0a8290 */
if(!s->budget--) { s->failed_pc=0x0c0a8290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8292;
P_0c0a8292: /* original 6bf6, guest PC 0x0c0a8292 */
if(!s->budget--) { s->failed_pc=0x0c0a8292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8294;
P_0c0a8294: /* original 6cf6, guest PC 0x0c0a8294 */
if(!s->budget--) { s->failed_pc=0x0c0a8294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8296;
P_0c0a8296: /* original 6df6, guest PC 0x0c0a8296 */
if(!s->budget--) { s->failed_pc=0x0c0a8296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8298;
P_0c0a8298: /* original 000b, guest PC 0x0c0a8298 */
if(!s->budget--) { s->failed_pc=0x0c0a8298u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a829a: /* original 6ef6, guest PC 0x0c0a829a */
if(!s->budget--) { s->failed_pc=0x0c0a829au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a829cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a829cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
