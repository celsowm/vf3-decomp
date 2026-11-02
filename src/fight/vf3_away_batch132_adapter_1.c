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
int vf3_away_batch132_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03b300u: goto P_0c03b300;
case 0x0c03b302u: goto P_0c03b302;
case 0x0c03b304u: goto P_0c03b304;
case 0x0c03b306u: goto P_0c03b306;
case 0x0c03b308u: goto P_0c03b308;
case 0x0c03b30au: goto P_0c03b30a;
case 0x0c03b30cu: goto P_0c03b30c;
case 0x0c03b30eu: goto P_0c03b30e;
case 0x0c03b310u: goto P_0c03b310;
case 0x0c03b312u: goto P_0c03b312;
case 0x0c03b314u: goto P_0c03b314;
case 0x0c03b316u: goto P_0c03b316;
case 0x0c03b318u: goto P_0c03b318;
case 0x0c03b31au: goto P_0c03b31a;
case 0x0c03b31cu: goto P_0c03b31c;
case 0x0c03b31eu: goto P_0c03b31e;
case 0x0c03b320u: goto P_0c03b320;
case 0x0c03b322u: goto P_0c03b322;
case 0x0c03b324u: goto P_0c03b324;
case 0x0c03b326u: goto P_0c03b326;
case 0x0c03b328u: goto P_0c03b328;
case 0x0c03b32au: goto P_0c03b32a;
case 0x0c03b32cu: goto P_0c03b32c;
case 0x0c03b32eu: goto P_0c03b32e;
case 0x0c03b330u: goto P_0c03b330;
case 0x0c03b332u: goto P_0c03b332;
case 0x0c03b334u: goto P_0c03b334;
case 0x0c03b336u: goto P_0c03b336;
case 0x0c03b338u: goto P_0c03b338;
case 0x0c05e1b2u: goto P_0c05e1b2;
case 0x0c05e1b4u: goto P_0c05e1b4;
case 0x0c05e1b6u: goto P_0c05e1b6;
case 0x0c05e1b8u: goto P_0c05e1b8;
case 0x0c05e1bau: goto P_0c05e1ba;
case 0x0c05e1bcu: goto P_0c05e1bc;
case 0x0c05e1beu: goto P_0c05e1be;
case 0x0c05e1c0u: goto P_0c05e1c0;
case 0x0c05e3d6u: goto P_0c05e3d6;
case 0x0c05e3d8u: goto P_0c05e3d8;
case 0x0c05e3dau: goto P_0c05e3da;
case 0x0c05e3dcu: goto P_0c05e3dc;
case 0x0c05e3deu: goto P_0c05e3de;
case 0x0c05e3e0u: goto P_0c05e3e0;
case 0x0c05e3e2u: goto P_0c05e3e2;
case 0x0c05e3e4u: goto P_0c05e3e4;
case 0x0c05e3e6u: goto P_0c05e3e6;
case 0x0c05e3e8u: goto P_0c05e3e8;
case 0x0c05e3eau: goto P_0c05e3ea;
case 0x0c05e3ecu: goto P_0c05e3ec;
case 0x0c05e3eeu: goto P_0c05e3ee;
case 0x0c05e3f0u: goto P_0c05e3f0;
case 0x0c05e3f2u: goto P_0c05e3f2;
case 0x0c05e3f4u: goto P_0c05e3f4;
case 0x0c05e3f6u: goto P_0c05e3f6;
case 0x0c05e3f8u: goto P_0c05e3f8;
case 0x0c060d14u: goto P_0c060d14;
case 0x0c060d16u: goto P_0c060d16;
case 0x0c060d18u: goto P_0c060d18;
case 0x0c060d1au: goto P_0c060d1a;
case 0x0c060d1cu: goto P_0c060d1c;
case 0x0c0a7a0cu: goto P_0c0a7a0c;
case 0x0c0a7a0eu: goto P_0c0a7a0e;
case 0x0c0a7a10u: goto P_0c0a7a10;
case 0x0c0a7a12u: goto P_0c0a7a12;
case 0x0c0a7a14u: goto P_0c0a7a14;
case 0x0c0a7a16u: goto P_0c0a7a16;
case 0x0c0a7a18u: goto P_0c0a7a18;
case 0x0c0a7a1au: goto P_0c0a7a1a;
case 0x0c0a7a1cu: goto P_0c0a7a1c;
case 0x0c0a7a1eu: goto P_0c0a7a1e;
case 0x0c0a7a20u: goto P_0c0a7a20;
case 0x0c0a7a22u: goto P_0c0a7a22;
case 0x0c0a7a24u: goto P_0c0a7a24;
case 0x0c0a7a26u: goto P_0c0a7a26;
case 0x0c0a7a28u: goto P_0c0a7a28;
case 0x0c0a7a2au: goto P_0c0a7a2a;
case 0x0c0a7a2cu: goto P_0c0a7a2c;
case 0x0c0a7a2eu: goto P_0c0a7a2e;
case 0x0c0a7a30u: goto P_0c0a7a30;
case 0x0c0a7a32u: goto P_0c0a7a32;
case 0x0c0a7a34u: goto P_0c0a7a34;
case 0x0c0a7a36u: goto P_0c0a7a36;
case 0x0c0a7a38u: goto P_0c0a7a38;
case 0x0c0a7a3au: goto P_0c0a7a3a;
case 0x0c0a7a3cu: goto P_0c0a7a3c;
case 0x0c0a7a3eu: goto P_0c0a7a3e;
case 0x0c0a7a40u: goto P_0c0a7a40;
case 0x0c0a7a42u: goto P_0c0a7a42;
case 0x0c0a7a44u: goto P_0c0a7a44;
case 0x0c0a7a46u: goto P_0c0a7a46;
case 0x0c0a7a48u: goto P_0c0a7a48;
case 0x0c0a7a4au: goto P_0c0a7a4a;
case 0x0c0a7a4cu: goto P_0c0a7a4c;
case 0x0c0a7a4eu: goto P_0c0a7a4e;
case 0x0c0a7a50u: goto P_0c0a7a50;
case 0x0c0a7a52u: goto P_0c0a7a52;
case 0x0c0a7a54u: goto P_0c0a7a54;
case 0x0c0a7a56u: goto P_0c0a7a56;
case 0x0c0a7a58u: goto P_0c0a7a58;
case 0x0c0a7a5au: goto P_0c0a7a5a;
case 0x0c0a7a5cu: goto P_0c0a7a5c;
case 0x0c0a7a5eu: goto P_0c0a7a5e;
case 0x0c0a7a60u: goto P_0c0a7a60;
case 0x0c0a7a62u: goto P_0c0a7a62;
case 0x0c0a7a64u: goto P_0c0a7a64;
case 0x0c0a7a66u: goto P_0c0a7a66;
case 0x0c0a7a68u: goto P_0c0a7a68;
case 0x0c0a7a6au: goto P_0c0a7a6a;
case 0x0c0a7a6cu: goto P_0c0a7a6c;
case 0x0c0a7a6eu: goto P_0c0a7a6e;
case 0x0c0a7a70u: goto P_0c0a7a70;
case 0x0c0a7a72u: goto P_0c0a7a72;
case 0x0c0a7a74u: goto P_0c0a7a74;
case 0x0c0a7a76u: goto P_0c0a7a76;
case 0x0c0a7a78u: goto P_0c0a7a78;
case 0x0c0a7a7au: goto P_0c0a7a7a;
case 0x0c0a7a7cu: goto P_0c0a7a7c;
case 0x0c0a7a7eu: goto P_0c0a7a7e;
case 0x0c0a7a80u: goto P_0c0a7a80;
case 0x0c0a7a82u: goto P_0c0a7a82;
case 0x0c0a7a84u: goto P_0c0a7a84;
case 0x0c0a7a86u: goto P_0c0a7a86;
case 0x0c0a7a88u: goto P_0c0a7a88;
case 0x0c0a7a8au: goto P_0c0a7a8a;
case 0x0c0a7a8cu: goto P_0c0a7a8c;
case 0x0c0a7a8eu: goto P_0c0a7a8e;
case 0x0c0a7a90u: goto P_0c0a7a90;
case 0x0c0a7a92u: goto P_0c0a7a92;
case 0x0c0a7a94u: goto P_0c0a7a94;
case 0x0c0a7a96u: goto P_0c0a7a96;
case 0x0c0a7a98u: goto P_0c0a7a98;
case 0x0c0a7a9au: goto P_0c0a7a9a;
case 0x0c0a7a9cu: goto P_0c0a7a9c;
case 0x0c0a7a9eu: goto P_0c0a7a9e;
case 0x0c0a7aa0u: goto P_0c0a7aa0;
case 0x0c0a7aa2u: goto P_0c0a7aa2;
case 0x0c0a7ae0u: goto P_0c0a7ae0;
case 0x0c0a7ae2u: goto P_0c0a7ae2;
case 0x0c0a7ae4u: goto P_0c0a7ae4;
case 0x0c0a7ae6u: goto P_0c0a7ae6;
case 0x0c0a7ae8u: goto P_0c0a7ae8;
case 0x0c0a7aeau: goto P_0c0a7aea;
case 0x0c0a7aecu: goto P_0c0a7aec;
case 0x0c0a7aeeu: goto P_0c0a7aee;
case 0x0c0a7af0u: goto P_0c0a7af0;
case 0x0c0a7af2u: goto P_0c0a7af2;
case 0x0c0a7af4u: goto P_0c0a7af4;
case 0x0c0a7af6u: goto P_0c0a7af6;
case 0x0c0a7af8u: goto P_0c0a7af8;
case 0x0c0a7afau: goto P_0c0a7afa;
case 0x0c0a7afcu: goto P_0c0a7afc;
case 0x0c0a7afeu: goto P_0c0a7afe;
case 0x0c0a7b00u: goto P_0c0a7b00;
case 0x0c0a7b02u: goto P_0c0a7b02;
case 0x0c0a7b04u: goto P_0c0a7b04;
case 0x0c0a7b06u: goto P_0c0a7b06;
case 0x0c0a7b08u: goto P_0c0a7b08;
case 0x0c0a7b0au: goto P_0c0a7b0a;
case 0x0c0a7b0cu: goto P_0c0a7b0c;
case 0x0c0a7b0eu: goto P_0c0a7b0e;
case 0x0c0a7b10u: goto P_0c0a7b10;
case 0x0c0a7b12u: goto P_0c0a7b12;
case 0x0c0a7b14u: goto P_0c0a7b14;
case 0x0c0a7b16u: goto P_0c0a7b16;
case 0x0c0a7b18u: goto P_0c0a7b18;
case 0x0c0a7b1au: goto P_0c0a7b1a;
case 0x0c0a7b1cu: goto P_0c0a7b1c;
case 0x0c0a7b1eu: goto P_0c0a7b1e;
case 0x0c0a7b20u: goto P_0c0a7b20;
case 0x0c0a7b22u: goto P_0c0a7b22;
case 0x0c0a7b24u: goto P_0c0a7b24;
case 0x0c0a7b26u: goto P_0c0a7b26;
case 0x0c0a7b28u: goto P_0c0a7b28;
case 0x0c0a7b2au: goto P_0c0a7b2a;
case 0x0c0a7b2cu: goto P_0c0a7b2c;
case 0x0c0a7b2eu: goto P_0c0a7b2e;
case 0x0c0a7b30u: goto P_0c0a7b30;
case 0x0c0a7b32u: goto P_0c0a7b32;
case 0x0c0a7b34u: goto P_0c0a7b34;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c03b300: /* original 2fe6, guest PC 0x0c03b300 */
if(!s->budget--) { s->failed_pc=0x0c03b300u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b302;
P_0c03b302: /* original 6743, guest PC 0x0c03b302 */
if(!s->budget--) { s->failed_pc=0x0c03b302u; return 0; }
r[7]=r[4];
goto P_0c03b304;
P_0c03b304: /* original 4f22, guest PC 0x0c03b304 */
if(!s->budget--) { s->failed_pc=0x0c03b304u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b306;
P_0c03b306: /* original 4729, guest PC 0x0c03b306 */
if(!s->budget--) { s->failed_pc=0x0c03b306u; return 0; }
r[7]>>=16;
goto P_0c03b308;
P_0c03b308: /* original 6543, guest PC 0x0c03b308 */
if(!s->budget--) { s->failed_pc=0x0c03b308u; return 0; }
r[5]=r[4];
goto P_0c03b30a;
P_0c03b30a: /* original 4719, guest PC 0x0c03b30a */
if(!s->budget--) { s->failed_pc=0x0c03b30au; return 0; }
r[7]>>=8;
goto P_0c03b30c;
P_0c03b30c: /* original 6643, guest PC 0x0c03b30c */
if(!s->budget--) { s->failed_pc=0x0c03b30cu; return 0; }
r[6]=r[4];
goto P_0c03b30e;
P_0c03b30e: /* original 677e, guest PC 0x0c03b30e */
if(!s->budget--) { s->failed_pc=0x0c03b30eu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c03b310;
P_0c03b310: /* original 7ffc, guest PC 0x0c03b310 */
if(!s->budget--) { s->failed_pc=0x0c03b310u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03b312;
P_0c03b312: /* original 6073, guest PC 0x0c03b312 */
if(!s->budget--) { s->failed_pc=0x0c03b312u; return 0; }
r[0]=r[7];
goto P_0c03b314;
P_0c03b314: /* original 6ef3, guest PC 0x0c03b314 */
if(!s->budget--) { s->failed_pc=0x0c03b314u; return 0; }
r[14]=r[15];
goto P_0c03b316;
P_0c03b316: /* original 4529, guest PC 0x0c03b316 */
if(!s->budget--) { s->failed_pc=0x0c03b316u; return 0; }
r[5]>>=16;
goto P_0c03b318;
P_0c03b318: /* original 80e3, guest PC 0x0c03b318 */
if(!s->budget--) { s->failed_pc=0x0c03b318u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c03b31a;
P_0c03b31a: /* original 655f, guest PC 0x0c03b31a */
if(!s->budget--) { s->failed_pc=0x0c03b31au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c03b31c;
P_0c03b31c: /* original 6053, guest PC 0x0c03b31c */
if(!s->budget--) { s->failed_pc=0x0c03b31cu; return 0; }
r[0]=r[5];
goto P_0c03b31e;
P_0c03b31e: /* original e3f8, guest PC 0x0c03b31e */
if(!s->budget--) { s->failed_pc=0x0c03b31eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c03b320;
P_0c03b320: /* original 80e2, guest PC 0x0c03b320 */
if(!s->budget--) { s->failed_pc=0x0c03b320u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c03b322;
P_0c03b322: /* original 463c, guest PC 0x0c03b322 */
if(!s->budget--) { s->failed_pc=0x0c03b322u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c03b324;
P_0c03b324: /* original 6063, guest PC 0x0c03b324 */
if(!s->budget--) { s->failed_pc=0x0c03b324u; return 0; }
r[0]=r[6];
goto P_0c03b326;
P_0c03b326: /* original 80e1, guest PC 0x0c03b326 */
if(!s->budget--) { s->failed_pc=0x0c03b326u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c03b328;
P_0c03b328: /* original 2e40, guest PC 0x0c03b328 */
if(!s->budget--) { s->failed_pc=0x0c03b328u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c03b32a;
P_0c03b32a: /* original 63e2, guest PC 0x0c03b32a */
if(!s->budget--) { s->failed_pc=0x0c03b32au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03b32c;
P_0c03b32c: /* original d21e, guest PC 0x0c03b32c */
if(!s->budget--) { s->failed_pc=0x0c03b32cu; return 0; }
r[2]=read(ram,0x0c03b3a8u,4);
goto P_0c03b32e;
P_0c03b32e: /* original 420b, guest PC 0x0c03b32e */
if(!s->budget--) { s->failed_pc=0x0c03b32eu; return 0; }
target=r[2];
r[16]=code_base|0x0c03b332u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03b332u) { target=s->pc; goto dispatch; }
goto P_0c03b332;
P_0c03b330: /* original 2f36, guest PC 0x0c03b330 */
if(!s->budget--) { s->failed_pc=0x0c03b330u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b332;
P_0c03b332: /* original 7f08, guest PC 0x0c03b332 */
if(!s->budget--) { s->failed_pc=0x0c03b332u; return 0; }
r[15]+=0x00000008u;
goto P_0c03b334;
P_0c03b334: /* original 4f26, guest PC 0x0c03b334 */
if(!s->budget--) { s->failed_pc=0x0c03b334u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b336;
P_0c03b336: /* original 000b, guest PC 0x0c03b336 */
if(!s->budget--) { s->failed_pc=0x0c03b336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b338: /* original 6ef6, guest PC 0x0c03b338 */
if(!s->budget--) { s->failed_pc=0x0c03b338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03b33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b33au; return 0; } return 1;
P_0c05e1b2: /* original 4f22, guest PC 0x0c05e1b2 */
if(!s->budget--) { s->failed_pc=0x0c05e1b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e1b4;
P_0c05e1b4: /* original 9461, guest PC 0x0c05e1b4 */
if(!s->budget--) { s->failed_pc=0x0c05e1b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e27au,2);
goto P_0c05e1b6;
P_0c05e1b6: /* original d339, guest PC 0x0c05e1b6 */
if(!s->budget--) { s->failed_pc=0x0c05e1b6u; return 0; }
r[3]=read(ram,0x0c05e29cu,4);
goto P_0c05e1b8;
P_0c05e1b8: /* original 430b, guest PC 0x0c05e1b8 */
if(!s->budget--) { s->failed_pc=0x0c05e1b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e1bcu;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e1bcu) { target=s->pc; goto dispatch; }
goto P_0c05e1bc;
P_0c05e1ba: /* original 55f1, guest PC 0x0c05e1ba */
if(!s->budget--) { s->failed_pc=0x0c05e1bau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05e1bc;
P_0c05e1bc: /* original 4f26, guest PC 0x0c05e1bc */
if(!s->budget--) { s->failed_pc=0x0c05e1bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e1be;
P_0c05e1be: /* original 000b, guest PC 0x0c05e1be */
if(!s->budget--) { s->failed_pc=0x0c05e1beu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e1c0: /* original e000, guest PC 0x0c05e1c0 */
if(!s->budget--) { s->failed_pc=0x0c05e1c0u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c05e1c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e1c2u; return 0; } return 1;
P_0c05e3d6: /* original 6353, guest PC 0x0c05e3d6 */
if(!s->budget--) { s->failed_pc=0x0c05e3d6u; return 0; }
r[3]=r[5];
goto P_0c05e3d8;
P_0c05e3d8: /* original d011, guest PC 0x0c05e3d8 */
if(!s->budget--) { s->failed_pc=0x0c05e3d8u; return 0; }
r[0]=read(ram,0x0c05e420u,4);
goto P_0c05e3da;
P_0c05e3da: /* original 4308, guest PC 0x0c05e3da */
if(!s->budget--) { s->failed_pc=0x0c05e3dau; return 0; }
r[3]<<=2;
goto P_0c05e3dc;
P_0c05e3dc: /* original 4f22, guest PC 0x0c05e3dc */
if(!s->budget--) { s->failed_pc=0x0c05e3dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e3de;
P_0c05e3de: /* original 7ffc, guest PC 0x0c05e3de */
if(!s->budget--) { s->failed_pc=0x0c05e3deu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05e3e0;
P_0c05e3e0: /* original 2f52, guest PC 0x0c05e3e0 */
if(!s->budget--) { s->failed_pc=0x0c05e3e0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05e3e2;
P_0c05e3e2: /* original 033e, guest PC 0x0c05e3e2 */
if(!s->budget--) { s->failed_pc=0x0c05e3e2u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c05e3e4;
P_0c05e3e4: /* original 430b, guest PC 0x0c05e3e4 */
if(!s->budget--) { s->failed_pc=0x0c05e3e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e3e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e3e8u) { target=s->pc; goto dispatch; }
goto P_0c05e3e8;
P_0c05e3e6: /* original 0009, guest PC 0x0c05e3e6 */
if(!s->budget--) { s->failed_pc=0x0c05e3e6u; return 0; }
goto P_0c05e3e8;
P_0c05e3e8: /* original d30e, guest PC 0x0c05e3e8 */
if(!s->budget--) { s->failed_pc=0x0c05e3e8u; return 0; }
r[3]=read(ram,0x0c05e424u,4);
goto P_0c05e3ea;
P_0c05e3ea: /* original d20f, guest PC 0x0c05e3ea */
if(!s->budget--) { s->failed_pc=0x0c05e3eau; return 0; }
r[2]=read(ram,0x0c05e428u,4);
goto P_0c05e3ec;
P_0c05e3ec: /* original 6132, guest PC 0x0c05e3ec */
if(!s->budget--) { s->failed_pc=0x0c05e3ecu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c05e3ee;
P_0c05e3ee: /* original 2129, guest PC 0x0c05e3ee */
if(!s->budget--) { s->failed_pc=0x0c05e3eeu; return 0; }
r[1]&=r[2];
goto P_0c05e3f0;
P_0c05e3f0: /* original 2312, guest PC 0x0c05e3f0 */
if(!s->budget--) { s->failed_pc=0x0c05e3f0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05e3f2;
P_0c05e3f2: /* original 7f04, guest PC 0x0c05e3f2 */
if(!s->budget--) { s->failed_pc=0x0c05e3f2u; return 0; }
r[15]+=0x00000004u;
goto P_0c05e3f4;
P_0c05e3f4: /* original 4f26, guest PC 0x0c05e3f4 */
if(!s->budget--) { s->failed_pc=0x0c05e3f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e3f6;
P_0c05e3f6: /* original 000b, guest PC 0x0c05e3f6 */
if(!s->budget--) { s->failed_pc=0x0c05e3f6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05e3f8: /* original 0009, guest PC 0x0c05e3f8 */
if(!s->budget--) { s->failed_pc=0x0c05e3f8u; return 0; }
if(!vf3_matrix_family(0x0c05e3fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e3fau; return 0; } return 1;
P_0c060d14: /* original d344, guest PC 0x0c060d14 */
if(!s->budget--) { s->failed_pc=0x0c060d14u; return 0; }
r[3]=read(ram,0x0c060e28u,4);
goto P_0c060d16;
P_0c060d16: /* original 343c, guest PC 0x0c060d16 */
if(!s->budget--) { s->failed_pc=0x0c060d16u; return 0; }
r[4]+=r[3];
goto P_0c060d18;
P_0c060d18: /* original 2452, guest PC 0x0c060d18 */
if(!s->budget--) { s->failed_pc=0x0c060d18u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c060d1a;
P_0c060d1a: /* original 000b, guest PC 0x0c060d1a */
if(!s->budget--) { s->failed_pc=0x0c060d1au; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060d1c: /* original e001, guest PC 0x0c060d1c */
if(!s->budget--) { s->failed_pc=0x0c060d1cu; return 0; }
r[0]=0x00000001u;
if(!vf3_matrix_family(0x0c060d1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060d1eu; return 0; } return 1;
P_0c0a7a0c: /* original 2fe6, guest PC 0x0c0a7a0c */
if(!s->budget--) { s->failed_pc=0x0c0a7a0cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7a0e;
P_0c0a7a0e: /* original 6743, guest PC 0x0c0a7a0e */
if(!s->budget--) { s->failed_pc=0x0c0a7a0eu; return 0; }
r[7]=r[4];
goto P_0c0a7a10;
P_0c0a7a10: /* original 2fd6, guest PC 0x0c0a7a10 */
if(!s->budget--) { s->failed_pc=0x0c0a7a10u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7a12;
P_0c0a7a12: /* original 4728, guest PC 0x0c0a7a12 */
if(!s->budget--) { s->failed_pc=0x0c0a7a12u; return 0; }
r[7]<<=16;
goto P_0c0a7a14;
P_0c0a7a14: /* original fffb, guest PC 0x0c0a7a14 */
if(!s->budget--) { s->failed_pc=0x0c0a7a14u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a7a16;
P_0c0a7a16: /* original 6e73, guest PC 0x0c0a7a16 */
if(!s->budget--) { s->failed_pc=0x0c0a7a16u; return 0; }
r[14]=r[7];
goto P_0c0a7a18;
P_0c0a7a18: /* original 4518, guest PC 0x0c0a7a18 */
if(!s->budget--) { s->failed_pc=0x0c0a7a18u; return 0; }
r[5]<<=8;
goto P_0c0a7a1a;
P_0c0a7a1a: /* original 6463, guest PC 0x0c0a7a1a */
if(!s->budget--) { s->failed_pc=0x0c0a7a1au; return 0; }
r[4]=r[6];
goto P_0c0a7a1c;
P_0c0a7a1c: /* original 4f22, guest PC 0x0c0a7a1c */
if(!s->budget--) { s->failed_pc=0x0c0a7a1cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7a1e;
P_0c0a7a1e: /* original 2e5b, guest PC 0x0c0a7a1e */
if(!s->budget--) { s->failed_pc=0x0c0a7a1eu; return 0; }
r[14]|=r[5];
goto P_0c0a7a20;
P_0c0a7a20: /* original 2e4b, guest PC 0x0c0a7a20 */
if(!s->budget--) { s->failed_pc=0x0c0a7a20u; return 0; }
r[14]|=r[4];
goto P_0c0a7a22;
P_0c0a7a22: /* original 7ffc, guest PC 0x0c0a7a22 */
if(!s->budget--) { s->failed_pc=0x0c0a7a22u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7a24;
P_0c0a7a24: /* original ff4a, guest PC 0x0c0a7a24 */
if(!s->budget--) { s->failed_pc=0x0c0a7a24u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a7a26;
P_0c0a7a26: /* original d327, guest PC 0x0c0a7a26 */
if(!s->budget--) { s->failed_pc=0x0c0a7a26u; return 0; }
r[3]=read(ram,0x0c0a7ac4u,4);
goto P_0c0a7a28;
P_0c0a7a28: /* original 903c, guest PC 0x0c0a7a28 */
if(!s->budget--) { s->failed_pc=0x0c0a7a28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa4u,2);
goto P_0c0a7a2a;
P_0c0a7a2a: /* original dd27, guest PC 0x0c0a7a2a */
if(!s->budget--) { s->failed_pc=0x0c0a7a2au; return 0; }
r[13]=read(ram,0x0c0a7ac8u,4);
goto P_0c0a7a2c;
P_0c0a7a2c: /* original 2e3b, guest PC 0x0c0a7a2c */
if(!s->budget--) { s->failed_pc=0x0c0a7a2cu; return 0; }
r[14]|=r[3];
goto P_0c0a7a2e;
P_0c0a7a2e: /* original ff5c, guest PC 0x0c0a7a2e */
if(!s->budget--) { s->failed_pc=0x0c0a7a2eu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a7a30;
P_0c0a7a30: /* original 0de6, guest PC 0x0c0a7a30 */
if(!s->budget--) { s->failed_pc=0x0c0a7a30u; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c0a7a32;
P_0c0a7a32: /* original d226, guest PC 0x0c0a7a32 */
if(!s->budget--) { s->failed_pc=0x0c0a7a32u; return 0; }
r[2]=read(ram,0x0c0a7accu,4);
goto P_0c0a7a34;
P_0c0a7a34: /* original 420b, guest PC 0x0c0a7a34 */
if(!s->budget--) { s->failed_pc=0x0c0a7a34u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7a38u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7a38u) { target=s->pc; goto dispatch; }
goto P_0c0a7a38;
P_0c0a7a36: /* original 64e3, guest PC 0x0c0a7a36 */
if(!s->budget--) { s->failed_pc=0x0c0a7a36u; return 0; }
r[4]=r[14];
goto P_0c0a7a38;
P_0c0a7a38: /* original d325, guest PC 0x0c0a7a38 */
if(!s->budget--) { s->failed_pc=0x0c0a7a38u; return 0; }
r[3]=read(ram,0x0c0a7ad0u,4);
goto P_0c0a7a3a;
P_0c0a7a3a: /* original 65e3, guest PC 0x0c0a7a3a */
if(!s->budget--) { s->failed_pc=0x0c0a7a3au; return 0; }
r[5]=r[14];
goto P_0c0a7a3c;
P_0c0a7a3c: /* original 66e3, guest PC 0x0c0a7a3c */
if(!s->budget--) { s->failed_pc=0x0c0a7a3cu; return 0; }
r[6]=r[14];
goto P_0c0a7a3e;
P_0c0a7a3e: /* original 430b, guest PC 0x0c0a7a3e */
if(!s->budget--) { s->failed_pc=0x0c0a7a3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7a42u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7a42u) { target=s->pc; goto dispatch; }
goto P_0c0a7a42;
P_0c0a7a40: /* original 64e3, guest PC 0x0c0a7a40 */
if(!s->budget--) { s->failed_pc=0x0c0a7a40u; return 0; }
r[4]=r[14];
goto P_0c0a7a42;
P_0c0a7a42: /* original f2f8, guest PC 0x0c0a7a42 */
if(!s->budget--) { s->failed_pc=0x0c0a7a42u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a7a44;
P_0c0a7a44: /* original e500, guest PC 0x0c0a7a44 */
if(!s->budget--) { s->failed_pc=0x0c0a7a44u; return 0; }
r[5]=0x00000000u;
goto P_0c0a7a46;
P_0c0a7a46: /* original f38d, guest PC 0x0c0a7a46 */
if(!s->budget--) { s->failed_pc=0x0c0a7a46u; return 0; }
fr[3]=0;
goto P_0c0a7a48;
P_0c0a7a48: /* original e100, guest PC 0x0c0a7a48 */
if(!s->budget--) { s->failed_pc=0x0c0a7a48u; return 0; }
r[1]=0x00000000u;
goto P_0c0a7a4a;
P_0c0a7a4a: /* original f235, guest PC 0x0c0a7a4a */
if(!s->budget--) { s->failed_pc=0x0c0a7a4au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0a7a4c;
P_0c0a7a4c: /* original 9e2b, guest PC 0x0c0a7a4c */
if(!s->budget--) { s->failed_pc=0x0c0a7a4cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa6u,2);
goto P_0c0a7a4e;
P_0c0a7a4e: /* original 942b, guest PC 0x0c0a7a4e */
if(!s->budget--) { s->failed_pc=0x0c0a7a4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa8u,2);
goto P_0c0a7a50;
P_0c0a7a50: /* original 3edc, guest PC 0x0c0a7a50 */
if(!s->budget--) { s->failed_pc=0x0c0a7a50u; return 0; }
r[14]+=r[13];
goto P_0c0a7a52;
P_0c0a7a52: /* original f68d, guest PC 0x0c0a7a52 */
if(!s->budget--) { s->failed_pc=0x0c0a7a52u; return 0; }
fr[6]=0;
goto P_0c0a7a54;
P_0c0a7a54: /* original 8d0c, guest PC 0x0c0a7a54 */
if(!s->budget--) { s->failed_pc=0x0c0a7a54u; return 0; }
cond=r[17]&1u;
r[1]+=r[14];
if(cond) { goto P_0c0a7a70; }
goto P_0c0a7a58;
P_0c0a7a56: /* original 31ec, guest PC 0x0c0a7a56 */
if(!s->budget--) { s->failed_pc=0x0c0a7a56u; return 0; }
r[1]+=r[14];
goto P_0c0a7a58;
P_0c0a7a58: /* original 6653, guest PC 0x0c0a7a58 */
if(!s->budget--) { s->failed_pc=0x0c0a7a58u; return 0; }
r[6]=r[5];
goto P_0c0a7a5a;
P_0c0a7a5a: /* original 6513, guest PC 0x0c0a7a5a */
if(!s->budget--) { s->failed_pc=0x0c0a7a5au; return 0; }
r[5]=r[1];
goto P_0c0a7a5c;
P_0c0a7a5c: /* original 7601, guest PC 0x0c0a7a5c */
if(!s->budget--) { s->failed_pc=0x0c0a7a5cu; return 0; }
r[6]+=0x00000001u;
goto P_0c0a7a5e;
P_0c0a7a5e: /* original f56a, guest PC 0x0c0a7a5e */
if(!s->budget--) { s->failed_pc=0x0c0a7a5eu; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c0a7a60;
P_0c0a7a60: /* original 3647, guest PC 0x0c0a7a60 */
if(!s->budget--) { s->failed_pc=0x0c0a7a60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[4])!=0);
goto P_0c0a7a62;
P_0c0a7a62: /* original 8ffb, guest PC 0x0c0a7a62 */
if(!s->budget--) { s->failed_pc=0x0c0a7a62u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c0a7a5c; }
goto P_0c0a7a66;
P_0c0a7a64: /* original 7504, guest PC 0x0c0a7a64 */
if(!s->budget--) { s->failed_pc=0x0c0a7a64u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a7a66;
P_0c0a7a66: /* original c71b, guest PC 0x0c0a7a66 */
if(!s->budget--) { s->failed_pc=0x0c0a7a66u; return 0; }
r[0]=code_base|0x000a7ad4u;
goto P_0c0a7a68;
P_0c0a7a68: /* original f308, guest PC 0x0c0a7a68 */
if(!s->budget--) { s->failed_pc=0x0c0a7a68u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a6a;
P_0c0a7a6a: /* original 901e, guest PC 0x0c0a7a6a */
if(!s->budget--) { s->failed_pc=0x0c0a7a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a6c;
P_0c0a7a6c: /* original a049, guest PC 0x0c0a7a6c */
if(!s->budget--) { s->failed_pc=0x0c0a7a6cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7b02;
P_0c0a7a6e: /* original fd37, guest PC 0x0c0a7a6e */
if(!s->budget--) { s->failed_pc=0x0c0a7a6eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7a70;
P_0c0a7a70: /* original c719, guest PC 0x0c0a7a70 */
if(!s->budget--) { s->failed_pc=0x0c0a7a70u; return 0; }
r[0]=code_base|0x000a7ad8u;
goto P_0c0a7a72;
P_0c0a7a72: /* original f59d, guest PC 0x0c0a7a72 */
if(!s->budget--) { s->failed_pc=0x0c0a7a72u; return 0; }
fr[5]=0x3f800000u;
goto P_0c0a7a74;
P_0c0a7a74: /* original f308, guest PC 0x0c0a7a74 */
if(!s->budget--) { s->failed_pc=0x0c0a7a74u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a76;
P_0c0a7a76: /* original 6753, guest PC 0x0c0a7a76 */
if(!s->budget--) { s->failed_pc=0x0c0a7a76u; return 0; }
r[7]=r[5];
goto P_0c0a7a78;
P_0c0a7a78: /* original f75c, guest PC 0x0c0a7a78 */
if(!s->budget--) { s->failed_pc=0x0c0a7a78u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c0a7a7a;
P_0c0a7a7a: /* original f7f1, guest PC 0x0c0a7a7a */
if(!s->budget--) { s->failed_pc=0x0c0a7a7au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'-');
goto P_0c0a7a7c;
P_0c0a7a7c: /* original f232, guest PC 0x0c0a7a7c */
if(!s->budget--) { s->failed_pc=0x0c0a7a7cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a7a7e;
P_0c0a7a7e: /* original 9014, guest PC 0x0c0a7a7e */
if(!s->budget--) { s->failed_pc=0x0c0a7a7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a80;
P_0c0a7a80: /* original 6543, guest PC 0x0c0a7a80 */
if(!s->budget--) { s->failed_pc=0x0c0a7a80u; return 0; }
r[5]=r[4];
goto P_0c0a7a82;
P_0c0a7a82: /* original 6613, guest PC 0x0c0a7a82 */
if(!s->budget--) { s->failed_pc=0x0c0a7a82u; return 0; }
r[6]=r[1];
goto P_0c0a7a84;
P_0c0a7a84: /* original f47c, guest PC 0x0c0a7a84 */
if(!s->budget--) { s->failed_pc=0x0c0a7a84u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0a7a86;
P_0c0a7a86: /* original f423, guest PC 0x0c0a7a86 */
if(!s->budget--) { s->failed_pc=0x0c0a7a86u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c0a7a88;
P_0c0a7a88: /* original fd47, guest PC 0x0c0a7a88 */
if(!s->budget--) { s->failed_pc=0x0c0a7a88u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a7a8a;
P_0c0a7a8a: /* original c714, guest PC 0x0c0a7a8a */
if(!s->budget--) { s->failed_pc=0x0c0a7a8au; return 0; }
r[0]=code_base|0x000a7adcu;
goto P_0c0a7a8c;
P_0c0a7a8c: /* original f808, guest PC 0x0c0a7a8c */
if(!s->budget--) { s->failed_pc=0x0c0a7a8cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0a7a8e;
P_0c0a7a8e: /* original 455a, guest PC 0x0c0a7a8e */
if(!s->budget--) { s->failed_pc=0x0c0a7a8eu; return 0; }
r[53]=r[5];
goto P_0c0a7a90;
P_0c0a7a90: /* original f28d, guest PC 0x0c0a7a90 */
if(!s->budget--) { s->failed_pc=0x0c0a7a90u; return 0; }
fr[2]=0;
goto P_0c0a7a92;
P_0c0a7a92: /* original f32d, guest PC 0x0c0a7a92 */
if(!s->budget--) { s->failed_pc=0x0c0a7a92u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a7a94;
P_0c0a7a94: /* original f372, guest PC 0x0c0a7a94 */
if(!s->budget--) { s->failed_pc=0x0c0a7a94u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0a7a96;
P_0c0a7a96: /* original f383, guest PC 0x0c0a7a96 */
if(!s->budget--) { s->failed_pc=0x0c0a7a96u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'/');
goto P_0c0a7a98;
P_0c0a7a98: /* original f43c, guest PC 0x0c0a7a98 */
if(!s->budget--) { s->failed_pc=0x0c0a7a98u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a7a9a;
P_0c0a7a9a: /* original f4f0, guest PC 0x0c0a7a9a */
if(!s->budget--) { s->failed_pc=0x0c0a7a9au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c0a7a9c;
P_0c0a7a9c: /* original f245, guest PC 0x0c0a7a9c */
if(!s->budget--) { s->failed_pc=0x0c0a7a9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0a7a9e;
P_0c0a7a9e: /* original 8b1f, guest PC 0x0c0a7a9e */
if(!s->budget--) { s->failed_pc=0x0c0a7a9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae0; }
goto P_0c0a7aa0;
P_0c0a7aa0: /* original a021, guest PC 0x0c0a7aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0a7ae6;
P_0c0a7aa2: /* original f46c, guest PC 0x0c0a7aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa2u; return 0; }
vf3_matrix_move(s,4,6);
if(!vf3_matrix_family(0x0c0a7aa4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7aa4u; return 0; } return 1;
P_0c0a7ae0: /* original f455, guest PC 0x0c0a7ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a7ae2;
P_0c0a7ae2: /* original 8b00, guest PC 0x0c0a7ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae6; }
goto P_0c0a7ae4;
P_0c0a7ae4: /* original f45c, guest PC 0x0c0a7ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae4u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a7ae6;
P_0c0a7ae6: /* original 7701, guest PC 0x0c0a7ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae6u; return 0; }
r[7]+=0x00000001u;
goto P_0c0a7ae8;
P_0c0a7ae8: /* original f64a, guest PC 0x0c0a7ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae8u; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0a7aea;
P_0c0a7aea: /* original 3743, guest PC 0x0c0a7aea */
if(!s->budget--) { s->failed_pc=0x0c0a7aeau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[4])!=0);
goto P_0c0a7aec;
P_0c0a7aec: /* original 7604, guest PC 0x0c0a7aec */
if(!s->budget--) { s->failed_pc=0x0c0a7aecu; return 0; }
r[6]+=0x00000004u;
goto P_0c0a7aee;
P_0c0a7aee: /* original 8fce, guest PC 0x0c0a7aee */
if(!s->budget--) { s->failed_pc=0x0c0a7aeeu; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(!cond) { goto P_0c0a7a8e; }
goto P_0c0a7af2;
P_0c0a7af0: /* original 75ff, guest PC 0x0c0a7af0 */
if(!s->budget--) { s->failed_pc=0x0c0a7af0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a7af2;
P_0c0a7af2: /* original f28d, guest PC 0x0c0a7af2 */
if(!s->budget--) { s->failed_pc=0x0c0a7af2u; return 0; }
fr[2]=0;
goto P_0c0a7af4;
P_0c0a7af4: /* original f2f5, guest PC 0x0c0a7af4 */
if(!s->budget--) { s->failed_pc=0x0c0a7af4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c0a7af6;
P_0c0a7af6: /* original 8b01, guest PC 0x0c0a7af6 */
if(!s->budget--) { s->failed_pc=0x0c0a7af6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7afc; }
goto P_0c0a7af8;
P_0c0a7af8: /* original a001, guest PC 0x0c0a7af8 */
if(!s->budget--) { s->failed_pc=0x0c0a7af8u; return 0; }
fr[3]=0;
goto P_0c0a7afe;
P_0c0a7afa: /* original f38d, guest PC 0x0c0a7afa */
if(!s->budget--) { s->failed_pc=0x0c0a7afau; return 0; }
fr[3]=0;
goto P_0c0a7afc;
P_0c0a7afc: /* original f3fc, guest PC 0x0c0a7afc */
if(!s->budget--) { s->failed_pc=0x0c0a7afcu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0a7afe;
P_0c0a7afe: /* original 9042, guest PC 0x0c0a7afe */
if(!s->budget--) { s->failed_pc=0x0c0a7afeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b86u,2);
goto P_0c0a7b00;
P_0c0a7b00: /* original fe37, guest PC 0x0c0a7b00 */
if(!s->budget--) { s->failed_pc=0x0c0a7b00u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a7b02;
P_0c0a7b02: /* original 7f04, guest PC 0x0c0a7b02 */
if(!s->budget--) { s->failed_pc=0x0c0a7b02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7b04;
P_0c0a7b04: /* original 60d2, guest PC 0x0c0a7b04 */
if(!s->budget--) { s->failed_pc=0x0c0a7b04u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a7b06;
P_0c0a7b06: /* original 4f26, guest PC 0x0c0a7b06 */
if(!s->budget--) { s->failed_pc=0x0c0a7b06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7b08;
P_0c0a7b08: /* original cb01, guest PC 0x0c0a7b08 */
if(!s->budget--) { s->failed_pc=0x0c0a7b08u; return 0; }
r[0]|=1u;
goto P_0c0a7b0a;
P_0c0a7b0a: /* original 2d02, guest PC 0x0c0a7b0a */
if(!s->budget--) { s->failed_pc=0x0c0a7b0au; return 0; }
write(ram,r[13],r[0],4);
goto P_0c0a7b0c;
P_0c0a7b0c: /* original e500, guest PC 0x0c0a7b0c */
if(!s->budget--) { s->failed_pc=0x0c0a7b0cu; return 0; }
r[5]=0x00000000u;
goto P_0c0a7b0e;
P_0c0a7b0e: /* original fff9, guest PC 0x0c0a7b0e */
if(!s->budget--) { s->failed_pc=0x0c0a7b0eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7b10;
P_0c0a7b10: /* original d320, guest PC 0x0c0a7b10 */
if(!s->budget--) { s->failed_pc=0x0c0a7b10u; return 0; }
r[3]=read(ram,0x0c0a7b94u,4);
goto P_0c0a7b12;
P_0c0a7b12: /* original 6df6, guest PC 0x0c0a7b12 */
if(!s->budget--) { s->failed_pc=0x0c0a7b12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7b14;
P_0c0a7b14: /* original d41e, guest PC 0x0c0a7b14 */
if(!s->budget--) { s->failed_pc=0x0c0a7b14u; return 0; }
r[4]=read(ram,0x0c0a7b90u,4);
goto P_0c0a7b16;
P_0c0a7b16: /* original 432b, guest PC 0x0c0a7b16 */
if(!s->budget--) { s->failed_pc=0x0c0a7b16u; return 0; }
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
P_0c0a7b18: /* original 6ef6, guest PC 0x0c0a7b18 */
if(!s->budget--) { s->failed_pc=0x0c0a7b18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7b1a;
P_0c0a7b1a: /* original 2fe6, guest PC 0x0c0a7b1a */
if(!s->budget--) { s->failed_pc=0x0c0a7b1au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7b1c;
P_0c0a7b1c: /* original 6e43, guest PC 0x0c0a7b1c */
if(!s->budget--) { s->failed_pc=0x0c0a7b1cu; return 0; }
r[14]=r[4];
goto P_0c0a7b1e;
P_0c0a7b1e: /* original 9033, guest PC 0x0c0a7b1e */
if(!s->budget--) { s->failed_pc=0x0c0a7b1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b88u,2);
goto P_0c0a7b20;
P_0c0a7b20: /* original f5e6, guest PC 0x0c0a7b20 */
if(!s->budget--) { s->failed_pc=0x0c0a7b20u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a7b22;
P_0c0a7b22: /* original 70f8, guest PC 0x0c0a7b22 */
if(!s->budget--) { s->failed_pc=0x0c0a7b22u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0a7b24;
P_0c0a7b24: /* original f4e6, guest PC 0x0c0a7b24 */
if(!s->budget--) { s->failed_pc=0x0c0a7b24u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a7b26;
P_0c0a7b26: /* original 70fb, guest PC 0x0c0a7b26 */
if(!s->budget--) { s->failed_pc=0x0c0a7b26u; return 0; }
r[0]+=0xfffffffbu;
goto P_0c0a7b28;
P_0c0a7b28: /* original 06ec, guest PC 0x0c0a7b28 */
if(!s->budget--) { s->failed_pc=0x0c0a7b28u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7b2a;
P_0c0a7b2a: /* original 70ff, guest PC 0x0c0a7b2a */
if(!s->budget--) { s->failed_pc=0x0c0a7b2au; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a7b2c;
P_0c0a7b2c: /* original 05ec, guest PC 0x0c0a7b2c */
if(!s->budget--) { s->failed_pc=0x0c0a7b2cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7b2e;
P_0c0a7b2e: /* original 70ff, guest PC 0x0c0a7b2e */
if(!s->budget--) { s->failed_pc=0x0c0a7b2eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a7b30;
P_0c0a7b30: /* original 04ec, guest PC 0x0c0a7b30 */
if(!s->budget--) { s->failed_pc=0x0c0a7b30u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7b32;
P_0c0a7b32: /* original af6b, guest PC 0x0c0a7b32 */
if(!s->budget--) { s->failed_pc=0x0c0a7b32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7a0c;
P_0c0a7b34: /* original 6ef6, guest PC 0x0c0a7b34 */
if(!s->budget--) { s->failed_pc=0x0c0a7b34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7b36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7b36u; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
