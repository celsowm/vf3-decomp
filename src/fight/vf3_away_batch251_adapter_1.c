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
int vf3_away_batch251_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07ae2cu: goto P_0c07ae2c;
case 0x0c07ae2eu: goto P_0c07ae2e;
case 0x0c07ae30u: goto P_0c07ae30;
case 0x0c07ae32u: goto P_0c07ae32;
case 0x0c07ae34u: goto P_0c07ae34;
case 0x0c07ae36u: goto P_0c07ae36;
case 0x0c07ae38u: goto P_0c07ae38;
case 0x0c07ae3au: goto P_0c07ae3a;
case 0x0c07ae3cu: goto P_0c07ae3c;
case 0x0c07ae3eu: goto P_0c07ae3e;
case 0x0c07ae40u: goto P_0c07ae40;
case 0x0c07ae42u: goto P_0c07ae42;
case 0x0c07ae44u: goto P_0c07ae44;
case 0x0c07ae46u: goto P_0c07ae46;
case 0x0c07ae48u: goto P_0c07ae48;
case 0x0c07ae4au: goto P_0c07ae4a;
case 0x0c07ae4cu: goto P_0c07ae4c;
case 0x0c07ae4eu: goto P_0c07ae4e;
case 0x0c07ae50u: goto P_0c07ae50;
case 0x0c07ae52u: goto P_0c07ae52;
case 0x0c07ae54u: goto P_0c07ae54;
case 0x0c07ae56u: goto P_0c07ae56;
case 0x0c07ae58u: goto P_0c07ae58;
case 0x0c07ae5au: goto P_0c07ae5a;
case 0x0c07ae5cu: goto P_0c07ae5c;
case 0x0c07ae5eu: goto P_0c07ae5e;
case 0x0c07ae60u: goto P_0c07ae60;
case 0x0c07ae62u: goto P_0c07ae62;
case 0x0c07ae64u: goto P_0c07ae64;
case 0x0c07ae66u: goto P_0c07ae66;
case 0x0c07ae68u: goto P_0c07ae68;
case 0x0c07ae6au: goto P_0c07ae6a;
case 0x0c07ae6cu: goto P_0c07ae6c;
case 0x0c07ae6eu: goto P_0c07ae6e;
case 0x0c07ae70u: goto P_0c07ae70;
case 0x0c07ae72u: goto P_0c07ae72;
case 0x0c07ae74u: goto P_0c07ae74;
case 0x0c07ae76u: goto P_0c07ae76;
case 0x0c07ae78u: goto P_0c07ae78;
case 0x0c07ae7au: goto P_0c07ae7a;
case 0x0c07ae7cu: goto P_0c07ae7c;
case 0x0c07ae7eu: goto P_0c07ae7e;
case 0x0c07ae80u: goto P_0c07ae80;
case 0x0c07ae82u: goto P_0c07ae82;
case 0x0c07ae84u: goto P_0c07ae84;
case 0x0c07ae86u: goto P_0c07ae86;
case 0x0c07ae88u: goto P_0c07ae88;
case 0x0c07ae8au: goto P_0c07ae8a;
case 0x0c07ae8cu: goto P_0c07ae8c;
case 0x0c07b398u: goto P_0c07b398;
case 0x0c07b39au: goto P_0c07b39a;
case 0x0c07b39cu: goto P_0c07b39c;
case 0x0c07b39eu: goto P_0c07b39e;
case 0x0c07b3a0u: goto P_0c07b3a0;
case 0x0c07b3a2u: goto P_0c07b3a2;
case 0x0c07b3a4u: goto P_0c07b3a4;
case 0x0c07b3a6u: goto P_0c07b3a6;
case 0x0c07b3a8u: goto P_0c07b3a8;
case 0x0c07b3aau: goto P_0c07b3aa;
case 0x0c07b3acu: goto P_0c07b3ac;
case 0x0c07b3aeu: goto P_0c07b3ae;
case 0x0c07b3b0u: goto P_0c07b3b0;
case 0x0c07b3b2u: goto P_0c07b3b2;
case 0x0c07b3b4u: goto P_0c07b3b4;
case 0x0c07b3b6u: goto P_0c07b3b6;
case 0x0c07b3b8u: goto P_0c07b3b8;
case 0x0c07b3bau: goto P_0c07b3ba;
case 0x0c07b3bcu: goto P_0c07b3bc;
case 0x0c07b3beu: goto P_0c07b3be;
case 0x0c07b3c0u: goto P_0c07b3c0;
case 0x0c07b3c2u: goto P_0c07b3c2;
case 0x0c07b3c4u: goto P_0c07b3c4;
case 0x0c07b3c6u: goto P_0c07b3c6;
case 0x0c07b3c8u: goto P_0c07b3c8;
case 0x0c07b3cau: goto P_0c07b3ca;
case 0x0c07b3ccu: goto P_0c07b3cc;
case 0x0c07b3ceu: goto P_0c07b3ce;
case 0x0c07b3d0u: goto P_0c07b3d0;
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
case 0x0c07b66eu: goto P_0c07b66e;
case 0x0c07b670u: goto P_0c07b670;
case 0x0c07b672u: goto P_0c07b672;
case 0x0c07b674u: goto P_0c07b674;
case 0x0c07b676u: goto P_0c07b676;
case 0x0c07b678u: goto P_0c07b678;
case 0x0c07b67au: goto P_0c07b67a;
case 0x0c07b67cu: goto P_0c07b67c;
case 0x0c07b67eu: goto P_0c07b67e;
case 0x0c07b680u: goto P_0c07b680;
case 0x0c07b682u: goto P_0c07b682;
case 0x0c07b684u: goto P_0c07b684;
case 0x0c07b686u: goto P_0c07b686;
case 0x0c07b688u: goto P_0c07b688;
case 0x0c07b68au: goto P_0c07b68a;
case 0x0c07b68cu: goto P_0c07b68c;
case 0x0c07b68eu: goto P_0c07b68e;
case 0x0c07b690u: goto P_0c07b690;
case 0x0c07b692u: goto P_0c07b692;
case 0x0c07b694u: goto P_0c07b694;
case 0x0c07b696u: goto P_0c07b696;
case 0x0c07b698u: goto P_0c07b698;
case 0x0c07b69au: goto P_0c07b69a;
case 0x0c07b6c4u: goto P_0c07b6c4;
case 0x0c07b6c6u: goto P_0c07b6c6;
case 0x0c07b6c8u: goto P_0c07b6c8;
case 0x0c07b6cau: goto P_0c07b6ca;
case 0x0c07b6ccu: goto P_0c07b6cc;
case 0x0c07b6ceu: goto P_0c07b6ce;
case 0x0c07b6d0u: goto P_0c07b6d0;
case 0x0c07b6d2u: goto P_0c07b6d2;
case 0x0c07b6d4u: goto P_0c07b6d4;
case 0x0c07b6d6u: goto P_0c07b6d6;
case 0x0c07b6d8u: goto P_0c07b6d8;
case 0x0c07b6dau: goto P_0c07b6da;
case 0x0c07b6dcu: goto P_0c07b6dc;
case 0x0c07b6deu: goto P_0c07b6de;
case 0x0c07b6e0u: goto P_0c07b6e0;
case 0x0c07b6e2u: goto P_0c07b6e2;
case 0x0c07b6e4u: goto P_0c07b6e4;
case 0x0c07b6e6u: goto P_0c07b6e6;
case 0x0c07b6e8u: goto P_0c07b6e8;
case 0x0c07b6eau: goto P_0c07b6ea;
case 0x0c07b6ecu: goto P_0c07b6ec;
case 0x0c07b6eeu: goto P_0c07b6ee;
case 0x0c07b6f0u: goto P_0c07b6f0;
case 0x0c07b6f2u: goto P_0c07b6f2;
case 0x0c09553cu: goto P_0c09553c;
case 0x0c09553eu: goto P_0c09553e;
case 0x0c095540u: goto P_0c095540;
case 0x0c095542u: goto P_0c095542;
case 0x0c095544u: goto P_0c095544;
case 0x0c095546u: goto P_0c095546;
case 0x0c095548u: goto P_0c095548;
case 0x0c09554au: goto P_0c09554a;
case 0x0c09554cu: goto P_0c09554c;
case 0x0c09554eu: goto P_0c09554e;
case 0x0c095550u: goto P_0c095550;
case 0x0c095552u: goto P_0c095552;
case 0x0c095554u: goto P_0c095554;
case 0x0c095556u: goto P_0c095556;
case 0x0c095558u: goto P_0c095558;
case 0x0c09555au: goto P_0c09555a;
case 0x0c09555cu: goto P_0c09555c;
case 0x0c09555eu: goto P_0c09555e;
case 0x0c095560u: goto P_0c095560;
case 0x0c095562u: goto P_0c095562;
case 0x0c095564u: goto P_0c095564;
case 0x0c095566u: goto P_0c095566;
case 0x0c095568u: goto P_0c095568;
case 0x0c09556au: goto P_0c09556a;
case 0x0c09556cu: goto P_0c09556c;
case 0x0c09556eu: goto P_0c09556e;
case 0x0c095570u: goto P_0c095570;
case 0x0c095572u: goto P_0c095572;
case 0x0c095574u: goto P_0c095574;
case 0x0c095576u: goto P_0c095576;
case 0x0c095578u: goto P_0c095578;
case 0x0c09557au: goto P_0c09557a;
case 0x0c09557cu: goto P_0c09557c;
case 0x0c09557eu: goto P_0c09557e;
case 0x0c095580u: goto P_0c095580;
case 0x0c095582u: goto P_0c095582;
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
P_0c07ae2c: /* original 2fe6, guest PC 0x0c07ae2c */
if(!s->budget--) { s->failed_pc=0x0c07ae2cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae2e;
P_0c07ae2e: /* original 2fd6, guest PC 0x0c07ae2e */
if(!s->budget--) { s->failed_pc=0x0c07ae2eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae30;
P_0c07ae30: /* original 4f22, guest PC 0x0c07ae30 */
if(!s->budget--) { s->failed_pc=0x0c07ae30u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ae32;
P_0c07ae32: /* original 7ffc, guest PC 0x0c07ae32 */
if(!s->budget--) { s->failed_pc=0x0c07ae32u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ae34;
P_0c07ae34: /* original 2f42, guest PC 0x0c07ae34 */
if(!s->budget--) { s->failed_pc=0x0c07ae34u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07ae36;
P_0c07ae36: /* original b3bb, guest PC 0x0c07ae36 */
if(!s->budget--) { s->failed_pc=0x0c07ae36u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07ae3au;
r[14]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ae3au) { target=s->pc; goto dispatch; }
goto P_0c07ae3a;
P_0c07ae38: /* original 6e53, guest PC 0x0c07ae38 */
if(!s->budget--) { s->failed_pc=0x0c07ae38u; return 0; }
r[14]=r[5];
goto P_0c07ae3a;
P_0c07ae3a: /* original 6d0d, guest PC 0x0c07ae3a */
if(!s->budget--) { s->failed_pc=0x0c07ae3au; return 0; }
r[13]=r[0]&65535u;
goto P_0c07ae3c;
P_0c07ae3c: /* original d33e, guest PC 0x0c07ae3c */
if(!s->budget--) { s->failed_pc=0x0c07ae3cu; return 0; }
r[3]=read(ram,0x0c07af38u,4);
goto P_0c07ae3e;
P_0c07ae3e: /* original 64d3, guest PC 0x0c07ae3e */
if(!s->budget--) { s->failed_pc=0x0c07ae3eu; return 0; }
r[4]=r[13];
goto P_0c07ae40;
P_0c07ae40: /* original 4400, guest PC 0x0c07ae40 */
if(!s->budget--) { s->failed_pc=0x0c07ae40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07ae42;
P_0c07ae42: /* original 343c, guest PC 0x0c07ae42 */
if(!s->budget--) { s->failed_pc=0x0c07ae42u; return 0; }
r[4]+=r[3];
goto P_0c07ae44;
P_0c07ae44: /* original d53b, guest PC 0x0c07ae44 */
if(!s->budget--) { s->failed_pc=0x0c07ae44u; return 0; }
r[5]=read(ram,0x0c07af34u,4);
goto P_0c07ae46;
P_0c07ae46: /* original 6241, guest PC 0x0c07ae46 */
if(!s->budget--) { s->failed_pc=0x0c07ae46u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c07ae48;
P_0c07ae48: /* original 2228, guest PC 0x0c07ae48 */
if(!s->budget--) { s->failed_pc=0x0c07ae48u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07ae4a;
P_0c07ae4a: /* original 8b12, guest PC 0x0c07ae4a */
if(!s->budget--) { s->failed_pc=0x0c07ae4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ae72; }
goto P_0c07ae4c;
P_0c07ae4c: /* original 2451, guest PC 0x0c07ae4c */
if(!s->budget--) { s->failed_pc=0x0c07ae4cu; return 0; }
write(ram,r[4],r[5],2);
goto P_0c07ae4e;
P_0c07ae4e: /* original 64d3, guest PC 0x0c07ae4e */
if(!s->budget--) { s->failed_pc=0x0c07ae4eu; return 0; }
r[4]=r[13];
goto P_0c07ae50;
P_0c07ae50: /* original 926f, guest PC 0x0c07ae50 */
if(!s->budget--) { s->failed_pc=0x0c07ae50u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07af32u,2);
goto P_0c07ae52;
P_0c07ae52: /* original 74bb, guest PC 0x0c07ae52 */
if(!s->budget--) { s->failed_pc=0x0c07ae52u; return 0; }
r[4]+=0xffffffbbu;
goto P_0c07ae54;
P_0c07ae54: /* original 4408, guest PC 0x0c07ae54 */
if(!s->budget--) { s->failed_pc=0x0c07ae54u; return 0; }
r[4]<<=2;
goto P_0c07ae56;
P_0c07ae56: /* original 66e3, guest PC 0x0c07ae56 */
if(!s->budget--) { s->failed_pc=0x0c07ae56u; return 0; }
r[6]=r[14];
goto P_0c07ae58;
P_0c07ae58: /* original 2f26, guest PC 0x0c07ae58 */
if(!s->budget--) { s->failed_pc=0x0c07ae58u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae5a;
P_0c07ae5a: /* original d138, guest PC 0x0c07ae5a */
if(!s->budget--) { s->failed_pc=0x0c07ae5au; return 0; }
r[1]=read(ram,0x0c07af3cu,4);
goto P_0c07ae5c;
P_0c07ae5c: /* original 2f16, guest PC 0x0c07ae5c */
if(!s->budget--) { s->failed_pc=0x0c07ae5cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae5e;
P_0c07ae5e: /* original 2fd6, guest PC 0x0c07ae5e */
if(!s->budget--) { s->failed_pc=0x0c07ae5eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae60;
P_0c07ae60: /* original d338, guest PC 0x0c07ae60 */
if(!s->budget--) { s->failed_pc=0x0c07ae60u; return 0; }
r[3]=read(ram,0x0c07af44u,4);
goto P_0c07ae62;
P_0c07ae62: /* original d039, guest PC 0x0c07ae62 */
if(!s->budget--) { s->failed_pc=0x0c07ae62u; return 0; }
r[0]=read(ram,0x0c07af48u,4);
goto P_0c07ae64;
P_0c07ae64: /* original 6532, guest PC 0x0c07ae64 */
if(!s->budget--) { s->failed_pc=0x0c07ae64u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c07ae66;
P_0c07ae66: /* original d339, guest PC 0x0c07ae66 */
if(!s->budget--) { s->failed_pc=0x0c07ae66u; return 0; }
r[3]=read(ram,0x0c07af4cu,4);
goto P_0c07ae68;
P_0c07ae68: /* original d735, guest PC 0x0c07ae68 */
if(!s->budget--) { s->failed_pc=0x0c07ae68u; return 0; }
r[7]=read(ram,0x0c07af40u,4);
goto P_0c07ae6a;
P_0c07ae6a: /* original 430b, guest PC 0x0c07ae6a */
if(!s->budget--) { s->failed_pc=0x0c07ae6au; return 0; }
target=r[3];
r[16]=code_base|0x0c07ae6eu;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ae6eu) { target=s->pc; goto dispatch; }
goto P_0c07ae6e;
P_0c07ae6c: /* original 044e, guest PC 0x0c07ae6c */
if(!s->budget--) { s->failed_pc=0x0c07ae6cu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07ae6e;
P_0c07ae6e: /* original a009, guest PC 0x0c07ae6e */
if(!s->budget--) { s->failed_pc=0x0c07ae6eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ae84;
P_0c07ae70: /* original 7f0c, guest PC 0x0c07ae70 */
if(!s->budget--) { s->failed_pc=0x0c07ae70u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ae72;
P_0c07ae72: /* original 6141, guest PC 0x0c07ae72 */
if(!s->budget--) { s->failed_pc=0x0c07ae72u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[1]=tmp;
goto P_0c07ae74;
P_0c07ae74: /* original 611d, guest PC 0x0c07ae74 */
if(!s->budget--) { s->failed_pc=0x0c07ae74u; return 0; }
r[1]=r[1]&65535u;
goto P_0c07ae76;
P_0c07ae76: /* original 3150, guest PC 0x0c07ae76 */
if(!s->budget--) { s->failed_pc=0x0c07ae76u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[5])!=0);
goto P_0c07ae78;
P_0c07ae78: /* original 8b02, guest PC 0x0c07ae78 */
if(!s->budget--) { s->failed_pc=0x0c07ae78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ae80; }
goto P_0c07ae7a;
P_0c07ae7a: /* original e100, guest PC 0x0c07ae7a */
if(!s->budget--) { s->failed_pc=0x0c07ae7au; return 0; }
r[1]=0x00000000u;
goto P_0c07ae7c;
P_0c07ae7c: /* original a002, guest PC 0x0c07ae7c */
if(!s->budget--) { s->failed_pc=0x0c07ae7cu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c07ae84;
P_0c07ae7e: /* original 2e12, guest PC 0x0c07ae7e */
if(!s->budget--) { s->failed_pc=0x0c07ae7eu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c07ae80;
P_0c07ae80: /* original e0ff, guest PC 0x0c07ae80 */
if(!s->budget--) { s->failed_pc=0x0c07ae80u; return 0; }
r[0]=0xffffffffu;
goto P_0c07ae82;
P_0c07ae82: /* original 2e02, guest PC 0x0c07ae82 */
if(!s->budget--) { s->failed_pc=0x0c07ae82u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c07ae84;
P_0c07ae84: /* original 7f04, guest PC 0x0c07ae84 */
if(!s->budget--) { s->failed_pc=0x0c07ae84u; return 0; }
r[15]+=0x00000004u;
goto P_0c07ae86;
P_0c07ae86: /* original 4f26, guest PC 0x0c07ae86 */
if(!s->budget--) { s->failed_pc=0x0c07ae86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ae88;
P_0c07ae88: /* original 6df6, guest PC 0x0c07ae88 */
if(!s->budget--) { s->failed_pc=0x0c07ae88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ae8a;
P_0c07ae8a: /* original 000b, guest PC 0x0c07ae8a */
if(!s->budget--) { s->failed_pc=0x0c07ae8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ae8c: /* original 6ef6, guest PC 0x0c07ae8c */
if(!s->budget--) { s->failed_pc=0x0c07ae8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ae8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ae8eu; return 0; } return 1;
P_0c07b398: /* original c748, guest PC 0x0c07b398 */
if(!s->budget--) { s->failed_pc=0x0c07b398u; return 0; }
r[0]=code_base|0x0007b4bcu;
goto P_0c07b39a;
P_0c07b39a: /* original f24c, guest PC 0x0c07b39a */
if(!s->budget--) { s->failed_pc=0x0c07b39au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b39c;
P_0c07b39c: /* original f308, guest PC 0x0c07b39c */
if(!s->budget--) { s->failed_pc=0x0c07b39cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b39e;
P_0c07b39e: /* original e018, guest PC 0x0c07b39e */
if(!s->budget--) { s->failed_pc=0x0c07b39eu; return 0; }
r[0]=0x00000018u;
goto P_0c07b3a0;
P_0c07b3a0: /* original f460, guest PC 0x0c07b3a0 */
if(!s->budget--) { s->failed_pc=0x0c07b3a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c07b3a2;
P_0c07b3a2: /* original f230, guest PC 0x0c07b3a2 */
if(!s->budget--) { s->failed_pc=0x0c07b3a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c07b3a4;
P_0c07b3a4: /* original f282, guest PC 0x0c07b3a4 */
if(!s->budget--) { s->failed_pc=0x0c07b3a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c07b3a6;
P_0c07b3a6: /* original f427, guest PC 0x0c07b3a6 */
if(!s->budget--) { s->failed_pc=0x0c07b3a6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07b3a8;
P_0c07b3a8: /* original c745, guest PC 0x0c07b3a8 */
if(!s->budget--) { s->failed_pc=0x0c07b3a8u; return 0; }
r[0]=code_base|0x0007b4c0u;
goto P_0c07b3aa;
P_0c07b3aa: /* original f208, guest PC 0x0c07b3aa */
if(!s->budget--) { s->failed_pc=0x0c07b3aau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b3ac;
P_0c07b3ac: /* original e01c, guest PC 0x0c07b3ac */
if(!s->budget--) { s->failed_pc=0x0c07b3acu; return 0; }
r[0]=0x0000001cu;
goto P_0c07b3ae;
P_0c07b3ae: /* original f15c, guest PC 0x0c07b3ae */
if(!s->budget--) { s->failed_pc=0x0c07b3aeu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c07b3b0;
P_0c07b3b0: /* original f570, guest PC 0x0c07b3b0 */
if(!s->budget--) { s->failed_pc=0x0c07b3b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c07b3b2;
P_0c07b3b2: /* original f120, guest PC 0x0c07b3b2 */
if(!s->budget--) { s->failed_pc=0x0c07b3b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c07b3b4;
P_0c07b3b4: /* original f192, guest PC 0x0c07b3b4 */
if(!s->budget--) { s->failed_pc=0x0c07b3b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07b3b6;
P_0c07b3b6: /* original f417, guest PC 0x0c07b3b6 */
if(!s->budget--) { s->failed_pc=0x0c07b3b6u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c07b3b8;
P_0c07b3b8: /* original c742, guest PC 0x0c07b3b8 */
if(!s->budget--) { s->failed_pc=0x0c07b3b8u; return 0; }
r[0]=code_base|0x0007b4c4u;
goto P_0c07b3ba;
P_0c07b3ba: /* original f108, guest PC 0x0c07b3ba */
if(!s->budget--) { s->failed_pc=0x0c07b3bau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c07b3bc;
P_0c07b3bc: /* original e020, guest PC 0x0c07b3bc */
if(!s->budget--) { s->failed_pc=0x0c07b3bcu; return 0; }
r[0]=0x00000020u;
goto P_0c07b3be;
P_0c07b3be: /* original f410, guest PC 0x0c07b3be */
if(!s->budget--) { s->failed_pc=0x0c07b3beu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c07b3c0;
P_0c07b3c0: /* original f482, guest PC 0x0c07b3c0 */
if(!s->budget--) { s->failed_pc=0x0c07b3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c07b3c2;
P_0c07b3c2: /* original f447, guest PC 0x0c07b3c2 */
if(!s->budget--) { s->failed_pc=0x0c07b3c2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b3c4;
P_0c07b3c4: /* original c740, guest PC 0x0c07b3c4 */
if(!s->budget--) { s->failed_pc=0x0c07b3c4u; return 0; }
r[0]=code_base|0x0007b4c8u;
goto P_0c07b3c6;
P_0c07b3c6: /* original f308, guest PC 0x0c07b3c6 */
if(!s->budget--) { s->failed_pc=0x0c07b3c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b3c8;
P_0c07b3c8: /* original e024, guest PC 0x0c07b3c8 */
if(!s->budget--) { s->failed_pc=0x0c07b3c8u; return 0; }
r[0]=0x00000024u;
goto P_0c07b3ca;
P_0c07b3ca: /* original f530, guest PC 0x0c07b3ca */
if(!s->budget--) { s->failed_pc=0x0c07b3cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c07b3cc;
P_0c07b3cc: /* original f592, guest PC 0x0c07b3cc */
if(!s->budget--) { s->failed_pc=0x0c07b3ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b3ce;
P_0c07b3ce: /* original 000b, guest PC 0x0c07b3ce */
if(!s->budget--) { s->failed_pc=0x0c07b3ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c07b3d0: /* original f457, guest PC 0x0c07b3d0 */
if(!s->budget--) { s->failed_pc=0x0c07b3d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07b3d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b3d2u; return 0; } return 1;
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
P_0c07b66e: /* original 4f22, guest PC 0x0c07b66e */
if(!s->budget--) { s->failed_pc=0x0c07b66eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b670;
P_0c07b670: /* original bf9e, guest PC 0x0c07b670 */
if(!s->budget--) { s->failed_pc=0x0c07b670u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07b674u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b674u) { target=s->pc; goto dispatch; }
goto P_0c07b674;
P_0c07b672: /* original 0009, guest PC 0x0c07b672 */
if(!s->budget--) { s->failed_pc=0x0c07b672u; return 0; }
goto P_0c07b674;
P_0c07b674: /* original 6403, guest PC 0x0c07b674 */
if(!s->budget--) { s->failed_pc=0x0c07b674u; return 0; }
r[4]=r[0];
goto P_0c07b676;
P_0c07b676: /* original d30f, guest PC 0x0c07b676 */
if(!s->budget--) { s->failed_pc=0x0c07b676u; return 0; }
r[3]=read(ram,0x0c07b6b4u,4);
goto P_0c07b678;
P_0c07b678: /* original 654d, guest PC 0x0c07b678 */
if(!s->budget--) { s->failed_pc=0x0c07b678u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b67a;
P_0c07b67a: /* original 4500, guest PC 0x0c07b67a */
if(!s->budget--) { s->failed_pc=0x0c07b67au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b67c;
P_0c07b67c: /* original 353c, guest PC 0x0c07b67c */
if(!s->budget--) { s->failed_pc=0x0c07b67cu; return 0; }
r[5]+=r[3];
goto P_0c07b67e;
P_0c07b67e: /* original 6251, guest PC 0x0c07b67e */
if(!s->budget--) { s->failed_pc=0x0c07b67eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c07b680;
P_0c07b680: /* original 2228, guest PC 0x0c07b680 */
if(!s->budget--) { s->failed_pc=0x0c07b680u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07b682;
P_0c07b682: /* original 8904, guest PC 0x0c07b682 */
if(!s->budget--) { s->failed_pc=0x0c07b682u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b68e; }
goto P_0c07b684;
P_0c07b684: /* original 6351, guest PC 0x0c07b684 */
if(!s->budget--) { s->failed_pc=0x0c07b684u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[3]=tmp;
goto P_0c07b686;
P_0c07b686: /* original d20c, guest PC 0x0c07b686 */
if(!s->budget--) { s->failed_pc=0x0c07b686u; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b688;
P_0c07b688: /* original 633d, guest PC 0x0c07b688 */
if(!s->budget--) { s->failed_pc=0x0c07b688u; return 0; }
r[3]=r[3]&65535u;
goto P_0c07b68a;
P_0c07b68a: /* original 3320, guest PC 0x0c07b68a */
if(!s->budget--) { s->failed_pc=0x0c07b68au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07b68c;
P_0c07b68c: /* original 8b02, guest PC 0x0c07b68c */
if(!s->budget--) { s->failed_pc=0x0c07b68cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b694; }
goto P_0c07b68e;
P_0c07b68e: /* original 4f26, guest PC 0x0c07b68e */
if(!s->budget--) { s->failed_pc=0x0c07b68eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b690;
P_0c07b690: /* original 000b, guest PC 0x0c07b690 */
if(!s->budget--) { s->failed_pc=0x0c07b690u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c07b692: /* original e000, guest PC 0x0c07b692 */
if(!s->budget--) { s->failed_pc=0x0c07b692u; return 0; }
r[0]=0x00000000u;
goto P_0c07b694;
P_0c07b694: /* original 6051, guest PC 0x0c07b694 */
if(!s->budget--) { s->failed_pc=0x0c07b694u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[0]=tmp;
goto P_0c07b696;
P_0c07b696: /* original 4f26, guest PC 0x0c07b696 */
if(!s->budget--) { s->failed_pc=0x0c07b696u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b698;
P_0c07b698: /* original 000b, guest PC 0x0c07b698 */
if(!s->budget--) { s->failed_pc=0x0c07b698u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b69a: /* original 0009, guest PC 0x0c07b69a */
if(!s->budget--) { s->failed_pc=0x0c07b69au; return 0; }
if(!vf3_matrix_family(0x0c07b69cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b69cu; return 0; } return 1;
P_0c07b6c4: /* original 4f22, guest PC 0x0c07b6c4 */
if(!s->budget--) { s->failed_pc=0x0c07b6c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6c6;
P_0c07b6c6: /* original 7ffc, guest PC 0x0c07b6c6 */
if(!s->budget--) { s->failed_pc=0x0c07b6c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b6c8;
P_0c07b6c8: /* original 2f72, guest PC 0x0c07b6c8 */
if(!s->budget--) { s->failed_pc=0x0c07b6c8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07b6ca;
P_0c07b6ca: /* original 53f2, guest PC 0x0c07b6ca */
if(!s->budget--) { s->failed_pc=0x0c07b6cau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6cc;
P_0c07b6cc: /* original 2f36, guest PC 0x0c07b6cc */
if(!s->budget--) { s->failed_pc=0x0c07b6ccu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ce;
P_0c07b6ce: /* original 52f1, guest PC 0x0c07b6ce */
if(!s->budget--) { s->failed_pc=0x0c07b6ceu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07b6d0;
P_0c07b6d0: /* original 2f26, guest PC 0x0c07b6d0 */
if(!s->budget--) { s->failed_pc=0x0c07b6d0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6d2;
P_0c07b6d2: /* original b004, guest PC 0x0c07b6d2 */
if(!s->budget--) { s->failed_pc=0x0c07b6d2u; return 0; }
target=code_base|0x0c07b6deu; r[16]=code_base|0x0c07b6d6u;
r[7]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6d6u) { target=s->pc; goto dispatch; }
goto P_0c07b6d6;
P_0c07b6d4: /* original e700, guest PC 0x0c07b6d4 */
if(!s->budget--) { s->failed_pc=0x0c07b6d4u; return 0; }
r[7]=0x00000000u;
goto P_0c07b6d6;
P_0c07b6d6: /* original 7f0c, guest PC 0x0c07b6d6 */
if(!s->budget--) { s->failed_pc=0x0c07b6d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07b6d8;
P_0c07b6d8: /* original 4f26, guest PC 0x0c07b6d8 */
if(!s->budget--) { s->failed_pc=0x0c07b6d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6da;
P_0c07b6da: /* original 000b, guest PC 0x0c07b6da */
if(!s->budget--) { s->failed_pc=0x0c07b6dau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6dc: /* original 0009, guest PC 0x0c07b6dc */
if(!s->budget--) { s->failed_pc=0x0c07b6dcu; return 0; }
goto P_0c07b6de;
P_0c07b6de: /* original 4f22, guest PC 0x0c07b6de */
if(!s->budget--) { s->failed_pc=0x0c07b6deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6e0;
P_0c07b6e0: /* original 53f2, guest PC 0x0c07b6e0 */
if(!s->budget--) { s->failed_pc=0x0c07b6e0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6e2;
P_0c07b6e2: /* original 2f36, guest PC 0x0c07b6e2 */
if(!s->budget--) { s->failed_pc=0x0c07b6e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6e4;
P_0c07b6e4: /* original d311, guest PC 0x0c07b6e4 */
if(!s->budget--) { s->failed_pc=0x0c07b6e4u; return 0; }
r[3]=read(ram,0x0c07b72cu,4);
goto P_0c07b6e6;
P_0c07b6e6: /* original 52f2, guest PC 0x0c07b6e6 */
if(!s->budget--) { s->failed_pc=0x0c07b6e6u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07b6e8;
P_0c07b6e8: /* original 430b, guest PC 0x0c07b6e8 */
if(!s->budget--) { s->failed_pc=0x0c07b6e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b6ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6ecu) { target=s->pc; goto dispatch; }
goto P_0c07b6ec;
P_0c07b6ea: /* original 2f26, guest PC 0x0c07b6ea */
if(!s->budget--) { s->failed_pc=0x0c07b6eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ec;
P_0c07b6ec: /* original 7f08, guest PC 0x0c07b6ec */
if(!s->budget--) { s->failed_pc=0x0c07b6ecu; return 0; }
r[15]+=0x00000008u;
goto P_0c07b6ee;
P_0c07b6ee: /* original 4f26, guest PC 0x0c07b6ee */
if(!s->budget--) { s->failed_pc=0x0c07b6eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6f0;
P_0c07b6f0: /* original 000b, guest PC 0x0c07b6f0 */
if(!s->budget--) { s->failed_pc=0x0c07b6f0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6f2: /* original 0009, guest PC 0x0c07b6f2 */
if(!s->budget--) { s->failed_pc=0x0c07b6f2u; return 0; }
if(!vf3_matrix_family(0x0c07b6f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b6f4u; return 0; } return 1;
P_0c09553c: /* original fffb, guest PC 0x0c09553c */
if(!s->budget--) { s->failed_pc=0x0c09553cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09553e;
P_0c09553e: /* original 4f22, guest PC 0x0c09553e */
if(!s->budget--) { s->failed_pc=0x0c09553eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095540;
P_0c095540: /* original 7ff0, guest PC 0x0c095540 */
if(!s->budget--) { s->failed_pc=0x0c095540u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c095542;
P_0c095542: /* original 1f42, guest PC 0x0c095542 */
if(!s->budget--) { s->failed_pc=0x0c095542u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c095544;
P_0c095544: /* original 2f52, guest PC 0x0c095544 */
if(!s->budget--) { s->failed_pc=0x0c095544u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c095546;
P_0c095546: /* original 1f61, guest PC 0x0c095546 */
if(!s->budget--) { s->failed_pc=0x0c095546u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c095548;
P_0c095548: /* original 54f2, guest PC 0x0c095548 */
if(!s->budget--) { s->failed_pc=0x0c095548u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09554a;
P_0c09554a: /* original d369, guest PC 0x0c09554a */
if(!s->budget--) { s->failed_pc=0x0c09554au; return 0; }
r[3]=read(ram,0x0c0956f0u,4);
goto P_0c09554c;
P_0c09554c: /* original 644f, guest PC 0x0c09554c */
if(!s->budget--) { s->failed_pc=0x0c09554cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09554e;
P_0c09554e: /* original 430b, guest PC 0x0c09554e */
if(!s->budget--) { s->failed_pc=0x0c09554eu; return 0; }
target=r[3];
r[16]=code_base|0x0c095552u;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095552u) { target=s->pc; goto dispatch; }
goto P_0c095552;
P_0c095550: /* original 1f43, guest PC 0x0c095550 */
if(!s->budget--) { s->failed_pc=0x0c095550u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c095552;
P_0c095552: /* original d368, guest PC 0x0c095552 */
if(!s->budget--) { s->failed_pc=0x0c095552u; return 0; }
r[3]=read(ram,0x0c0956f4u,4);
goto P_0c095554;
P_0c095554: /* original ff0c, guest PC 0x0c095554 */
if(!s->budget--) { s->failed_pc=0x0c095554u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c095556;
P_0c095556: /* original 430b, guest PC 0x0c095556 */
if(!s->budget--) { s->failed_pc=0x0c095556u; return 0; }
target=r[3];
r[16]=code_base|0x0c09555au;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09555au) { target=s->pc; goto dispatch; }
goto P_0c09555a;
P_0c095558: /* original 54f3, guest PC 0x0c095558 */
if(!s->budget--) { s->failed_pc=0x0c095558u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c09555a;
P_0c09555a: /* original 62f2, guest PC 0x0c09555a */
if(!s->budget--) { s->failed_pc=0x0c09555au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09555c;
P_0c09555c: /* original f70c, guest PC 0x0c09555c */
if(!s->budget--) { s->failed_pc=0x0c09555cu; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c09555e;
P_0c09555e: /* original f628, guest PC 0x0c09555e */
if(!s->budget--) { s->failed_pc=0x0c09555eu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c095560;
P_0c095560: /* original 53f1, guest PC 0x0c095560 */
if(!s->budget--) { s->failed_pc=0x0c095560u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c095562;
P_0c095562: /* original f762, guest PC 0x0c095562 */
if(!s->budget--) { s->failed_pc=0x0c095562u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c095564;
P_0c095564: /* original f40c, guest PC 0x0c095564 */
if(!s->budget--) { s->failed_pc=0x0c095564u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c095566;
P_0c095566: /* original f538, guest PC 0x0c095566 */
if(!s->budget--) { s->failed_pc=0x0c095566u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c095568;
P_0c095568: /* original 6323, guest PC 0x0c095568 */
if(!s->budget--) { s->failed_pc=0x0c095568u; return 0; }
r[3]=r[2];
goto P_0c09556a;
P_0c09556a: /* original f05c, guest PC 0x0c09556a */
if(!s->budget--) { s->failed_pc=0x0c09556au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09556c;
P_0c09556c: /* original f452, guest PC 0x0c09556c */
if(!s->budget--) { s->failed_pc=0x0c09556cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09556e;
P_0c09556e: /* original f7fe, guest PC 0x0c09556e */
if(!s->budget--) { s->failed_pc=0x0c09556eu; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[15],fr[7],r[18]);
goto P_0c095570;
P_0c095570: /* original ff62, guest PC 0x0c095570 */
if(!s->budget--) { s->failed_pc=0x0c095570u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c095572;
P_0c095572: /* original f57c, guest PC 0x0c095572 */
if(!s->budget--) { s->failed_pc=0x0c095572u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c095574;
P_0c095574: /* original f35a, guest PC 0x0c095574 */
if(!s->budget--) { s->failed_pc=0x0c095574u; return 0; }
vf3_matrix_store(s,ram,5,r[3]);
goto P_0c095576;
P_0c095576: /* original f4f1, guest PC 0x0c095576 */
if(!s->budget--) { s->failed_pc=0x0c095576u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c095578;
P_0c095578: /* original 53f1, guest PC 0x0c095578 */
if(!s->budget--) { s->failed_pc=0x0c095578u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09557a;
P_0c09557a: /* original 7f10, guest PC 0x0c09557a */
if(!s->budget--) { s->failed_pc=0x0c09557au; return 0; }
r[15]+=0x00000010u;
goto P_0c09557c;
P_0c09557c: /* original 4f26, guest PC 0x0c09557c */
if(!s->budget--) { s->failed_pc=0x0c09557cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09557e;
P_0c09557e: /* original f34a, guest PC 0x0c09557e */
if(!s->budget--) { s->failed_pc=0x0c09557eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c095580;
P_0c095580: /* original 000b, guest PC 0x0c095580 */
if(!s->budget--) { s->failed_pc=0x0c095580u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c095582: /* original fff9, guest PC 0x0c095582 */
if(!s->budget--) { s->failed_pc=0x0c095582u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c095584u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095584u; return 0; } return 1;
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
