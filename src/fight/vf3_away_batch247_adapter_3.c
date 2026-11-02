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
int vf3_away_batch247_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0409d2u: goto P_0c0409d2;
case 0x0c0409d4u: goto P_0c0409d4;
case 0x0c0409d6u: goto P_0c0409d6;
case 0x0c0409d8u: goto P_0c0409d8;
case 0x0c0409dau: goto P_0c0409da;
case 0x0c0409dcu: goto P_0c0409dc;
case 0x0c0409deu: goto P_0c0409de;
case 0x0c0409e0u: goto P_0c0409e0;
case 0x0c0409e2u: goto P_0c0409e2;
case 0x0c0409e4u: goto P_0c0409e4;
case 0x0c0409e6u: goto P_0c0409e6;
case 0x0c0409e8u: goto P_0c0409e8;
case 0x0c0409eau: goto P_0c0409ea;
case 0x0c0409ecu: goto P_0c0409ec;
case 0x0c0409eeu: goto P_0c0409ee;
case 0x0c0409f0u: goto P_0c0409f0;
case 0x0c0409f2u: goto P_0c0409f2;
case 0x0c0409f4u: goto P_0c0409f4;
case 0x0c0409f6u: goto P_0c0409f6;
case 0x0c0409f8u: goto P_0c0409f8;
case 0x0c0409fau: goto P_0c0409fa;
case 0x0c0409fcu: goto P_0c0409fc;
case 0x0c0409feu: goto P_0c0409fe;
case 0x0c040a00u: goto P_0c040a00;
case 0x0c040a02u: goto P_0c040a02;
case 0x0c040a04u: goto P_0c040a04;
case 0x0c040a06u: goto P_0c040a06;
case 0x0c040a08u: goto P_0c040a08;
case 0x0c040a0au: goto P_0c040a0a;
case 0x0c040a0cu: goto P_0c040a0c;
case 0x0c040a0eu: goto P_0c040a0e;
case 0x0c040a10u: goto P_0c040a10;
case 0x0c040a12u: goto P_0c040a12;
case 0x0c040a14u: goto P_0c040a14;
case 0x0c040a16u: goto P_0c040a16;
case 0x0c040a18u: goto P_0c040a18;
case 0x0c040a1au: goto P_0c040a1a;
case 0x0c040a1cu: goto P_0c040a1c;
case 0x0c040a1eu: goto P_0c040a1e;
case 0x0c040a20u: goto P_0c040a20;
case 0x0c040a30u: goto P_0c040a30;
case 0x0c040a32u: goto P_0c040a32;
case 0x0c040a34u: goto P_0c040a34;
case 0x0c040a36u: goto P_0c040a36;
case 0x0c040a38u: goto P_0c040a38;
case 0x0c040a3au: goto P_0c040a3a;
case 0x0c040a3cu: goto P_0c040a3c;
case 0x0c040a3eu: goto P_0c040a3e;
case 0x0c040a40u: goto P_0c040a40;
case 0x0c040a42u: goto P_0c040a42;
case 0x0c040a44u: goto P_0c040a44;
case 0x0c040a46u: goto P_0c040a46;
case 0x0c040a48u: goto P_0c040a48;
case 0x0c040a4au: goto P_0c040a4a;
case 0x0c040a4cu: goto P_0c040a4c;
case 0x0c040a4eu: goto P_0c040a4e;
case 0x0c040a50u: goto P_0c040a50;
case 0x0c040a52u: goto P_0c040a52;
case 0x0c040a54u: goto P_0c040a54;
case 0x0c040a56u: goto P_0c040a56;
case 0x0c040a58u: goto P_0c040a58;
case 0x0c040a5au: goto P_0c040a5a;
case 0x0c040a5cu: goto P_0c040a5c;
case 0x0c040a5eu: goto P_0c040a5e;
case 0x0c040a60u: goto P_0c040a60;
case 0x0c040a62u: goto P_0c040a62;
case 0x0c040a64u: goto P_0c040a64;
case 0x0c040a66u: goto P_0c040a66;
case 0x0c040a68u: goto P_0c040a68;
case 0x0c040a6au: goto P_0c040a6a;
case 0x0c040a6cu: goto P_0c040a6c;
case 0x0c040a6eu: goto P_0c040a6e;
case 0x0c040a70u: goto P_0c040a70;
case 0x0c040a72u: goto P_0c040a72;
case 0x0c040a74u: goto P_0c040a74;
case 0x0c040a76u: goto P_0c040a76;
case 0x0c040a78u: goto P_0c040a78;
case 0x0c040a7au: goto P_0c040a7a;
case 0x0c040a7cu: goto P_0c040a7c;
case 0x0c040a7eu: goto P_0c040a7e;
case 0x0c040a80u: goto P_0c040a80;
case 0x0c040a82u: goto P_0c040a82;
case 0x0c040a84u: goto P_0c040a84;
case 0x0c040a86u: goto P_0c040a86;
case 0x0c040a88u: goto P_0c040a88;
case 0x0c040a8au: goto P_0c040a8a;
case 0x0c040a8cu: goto P_0c040a8c;
case 0x0c040a8eu: goto P_0c040a8e;
case 0x0c040a90u: goto P_0c040a90;
case 0x0c040a92u: goto P_0c040a92;
case 0x0c040a94u: goto P_0c040a94;
case 0x0c040a96u: goto P_0c040a96;
case 0x0c040a98u: goto P_0c040a98;
case 0x0c040a9au: goto P_0c040a9a;
case 0x0c040a9cu: goto P_0c040a9c;
case 0x0c040a9eu: goto P_0c040a9e;
case 0x0c040aa0u: goto P_0c040aa0;
case 0x0c040aa2u: goto P_0c040aa2;
case 0x0c040aa4u: goto P_0c040aa4;
case 0x0c040aa6u: goto P_0c040aa6;
case 0x0c040aa8u: goto P_0c040aa8;
case 0x0c040aaau: goto P_0c040aaa;
case 0x0c040aacu: goto P_0c040aac;
case 0x0c040aaeu: goto P_0c040aae;
case 0x0c040ab0u: goto P_0c040ab0;
case 0x0c040ab2u: goto P_0c040ab2;
case 0x0c040ab4u: goto P_0c040ab4;
case 0x0c040ab6u: goto P_0c040ab6;
case 0x0c040ab8u: goto P_0c040ab8;
case 0x0c040abau: goto P_0c040aba;
case 0x0c040accu: goto P_0c040acc;
case 0x0c040aceu: goto P_0c040ace;
case 0x0c040ad0u: goto P_0c040ad0;
case 0x0c040ad2u: goto P_0c040ad2;
case 0x0c040ad4u: goto P_0c040ad4;
case 0x0c040ad6u: goto P_0c040ad6;
case 0x0c040ad8u: goto P_0c040ad8;
case 0x0c040adau: goto P_0c040ada;
case 0x0c040adcu: goto P_0c040adc;
case 0x0c040adeu: goto P_0c040ade;
case 0x0c040ae0u: goto P_0c040ae0;
case 0x0c040ae2u: goto P_0c040ae2;
case 0x0c040ae4u: goto P_0c040ae4;
case 0x0c040ae6u: goto P_0c040ae6;
case 0x0c040ae8u: goto P_0c040ae8;
case 0x0c040aeau: goto P_0c040aea;
case 0x0c040aecu: goto P_0c040aec;
case 0x0c040aeeu: goto P_0c040aee;
case 0x0c040af0u: goto P_0c040af0;
case 0x0c040af2u: goto P_0c040af2;
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
case 0x0c046314u: goto P_0c046314;
case 0x0c046316u: goto P_0c046316;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c096864u: goto P_0c096864;
case 0x0c096866u: goto P_0c096866;
case 0x0c096868u: goto P_0c096868;
case 0x0c09686au: goto P_0c09686a;
case 0x0c09686cu: goto P_0c09686c;
case 0x0c09686eu: goto P_0c09686e;
case 0x0c096870u: goto P_0c096870;
case 0x0c096872u: goto P_0c096872;
case 0x0c096874u: goto P_0c096874;
case 0x0c096876u: goto P_0c096876;
case 0x0c096878u: goto P_0c096878;
case 0x0c09687au: goto P_0c09687a;
case 0x0c09687cu: goto P_0c09687c;
case 0x0c09687eu: goto P_0c09687e;
case 0x0c096880u: goto P_0c096880;
case 0x0c096882u: goto P_0c096882;
case 0x0c096884u: goto P_0c096884;
case 0x0c096886u: goto P_0c096886;
case 0x0c096888u: goto P_0c096888;
case 0x0c09688au: goto P_0c09688a;
case 0x0c09688cu: goto P_0c09688c;
case 0x0c09688eu: goto P_0c09688e;
case 0x0c096890u: goto P_0c096890;
case 0x0c096892u: goto P_0c096892;
case 0x0c096894u: goto P_0c096894;
case 0x0c096896u: goto P_0c096896;
case 0x0c096898u: goto P_0c096898;
case 0x0c09689au: goto P_0c09689a;
case 0x0c09689cu: goto P_0c09689c;
case 0x0c09689eu: goto P_0c09689e;
case 0x0c0968a0u: goto P_0c0968a0;
case 0x0c0968a2u: goto P_0c0968a2;
case 0x0c0968a4u: goto P_0c0968a4;
case 0x0c0968a6u: goto P_0c0968a6;
case 0x0c0968a8u: goto P_0c0968a8;
case 0x0c0968aau: goto P_0c0968aa;
case 0x0c0968acu: goto P_0c0968ac;
case 0x0c0968aeu: goto P_0c0968ae;
case 0x0c0a7f5au: goto P_0c0a7f5a;
case 0x0c0a7f5cu: goto P_0c0a7f5c;
case 0x0c0a7f5eu: goto P_0c0a7f5e;
case 0x0c0a7f60u: goto P_0c0a7f60;
case 0x0c0a7f62u: goto P_0c0a7f62;
case 0x0c0a7f64u: goto P_0c0a7f64;
case 0x0c0a7f66u: goto P_0c0a7f66;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0409d2: /* original 4f22, guest PC 0x0c0409d2 */
if(!s->budget--) { s->failed_pc=0x0c0409d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0409d4;
P_0c0409d4: /* original 7fe8, guest PC 0x0c0409d4 */
if(!s->budget--) { s->failed_pc=0x0c0409d4u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0409d6;
P_0c0409d6: /* original 1f45, guest PC 0x0c0409d6 */
if(!s->budget--) { s->failed_pc=0x0c0409d6u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c0409d8;
P_0c0409d8: /* original 54f5, guest PC 0x0c0409d8 */
if(!s->budget--) { s->failed_pc=0x0c0409d8u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0409da;
P_0c0409da: /* original bccd, guest PC 0x0c0409da */
if(!s->budget--) { s->failed_pc=0x0c0409dau; return 0; }
target=code_base|0x0c040378u; r[16]=code_base|0x0c0409deu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0409deu) { target=s->pc; goto dispatch; }
goto P_0c0409de;
P_0c0409dc: /* original 0009, guest PC 0x0c0409dc */
if(!s->budget--) { s->failed_pc=0x0c0409dcu; return 0; }
goto P_0c0409de;
P_0c0409de: /* original 2f02, guest PC 0x0c0409de */
if(!s->budget--) { s->failed_pc=0x0c0409deu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0409e0;
P_0c0409e0: /* original 2008, guest PC 0x0c0409e0 */
if(!s->budget--) { s->failed_pc=0x0c0409e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0409e2;
P_0c0409e2: /* original 8903, guest PC 0x0c0409e2 */
if(!s->budget--) { s->failed_pc=0x0c0409e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0409ec; }
goto P_0c0409e4;
P_0c0409e4: /* original 7f18, guest PC 0x0c0409e4 */
if(!s->budget--) { s->failed_pc=0x0c0409e4u; return 0; }
r[15]+=0x00000018u;
goto P_0c0409e6;
P_0c0409e6: /* original 4f26, guest PC 0x0c0409e6 */
if(!s->budget--) { s->failed_pc=0x0c0409e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0409e8;
P_0c0409e8: /* original 000b, guest PC 0x0c0409e8 */
if(!s->budget--) { s->failed_pc=0x0c0409e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0409ea: /* original 0009, guest PC 0x0c0409ea */
if(!s->budget--) { s->failed_pc=0x0c0409eau; return 0; }
goto P_0c0409ec;
P_0c0409ec: /* original 52f5, guest PC 0x0c0409ec */
if(!s->budget--) { s->failed_pc=0x0c0409ecu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0409ee;
P_0c0409ee: /* original 6323, guest PC 0x0c0409ee */
if(!s->budget--) { s->failed_pc=0x0c0409eeu; return 0; }
r[3]=r[2];
goto P_0c0409f0;
P_0c0409f0: /* original 4200, guest PC 0x0c0409f0 */
if(!s->budget--) { s->failed_pc=0x0c0409f0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0409f2;
P_0c0409f2: /* original 323c, guest PC 0x0c0409f2 */
if(!s->budget--) { s->failed_pc=0x0c0409f2u; return 0; }
r[2]+=r[3];
goto P_0c0409f4;
P_0c0409f4: /* original 4208, guest PC 0x0c0409f4 */
if(!s->budget--) { s->failed_pc=0x0c0409f4u; return 0; }
r[2]<<=2;
goto P_0c0409f6;
P_0c0409f6: /* original 622e, guest PC 0x0c0409f6 */
if(!s->budget--) { s->failed_pc=0x0c0409f6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c0409f8;
P_0c0409f8: /* original d00c, guest PC 0x0c0409f8 */
if(!s->budget--) { s->failed_pc=0x0c0409f8u; return 0; }
r[0]=read(ram,0x0c040a2cu,4);
goto P_0c0409fa;
P_0c0409fa: /* original 012e, guest PC 0x0c0409fa */
if(!s->budget--) { s->failed_pc=0x0c0409fau; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c0409fc;
P_0c0409fc: /* original 1f11, guest PC 0x0c0409fc */
if(!s->budget--) { s->failed_pc=0x0c0409fcu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0409fe;
P_0c0409fe: /* original 66f3, guest PC 0x0c0409fe */
if(!s->budget--) { s->failed_pc=0x0c0409feu; return 0; }
r[6]=r[15];
goto P_0c040a00;
P_0c040a00: /* original 7608, guest PC 0x0c040a00 */
if(!s->budget--) { s->failed_pc=0x0c040a00u; return 0; }
r[6]+=0x00000008u;
goto P_0c040a02;
P_0c040a02: /* original 55f1, guest PC 0x0c040a02 */
if(!s->budget--) { s->failed_pc=0x0c040a02u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c040a04;
P_0c040a04: /* original 54f5, guest PC 0x0c040a04 */
if(!s->budget--) { s->failed_pc=0x0c040a04u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c040a06;
P_0c040a06: /* original bcdb, guest PC 0x0c040a06 */
if(!s->budget--) { s->failed_pc=0x0c040a06u; return 0; }
target=code_base|0x0c0403c0u; r[16]=code_base|0x0c040a0au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040a0au) { target=s->pc; goto dispatch; }
goto P_0c040a0a;
P_0c040a08: /* original 0009, guest PC 0x0c040a08 */
if(!s->budget--) { s->failed_pc=0x0c040a08u; return 0; }
goto P_0c040a0a;
P_0c040a0a: /* original 1f04, guest PC 0x0c040a0a */
if(!s->budget--) { s->failed_pc=0x0c040a0au; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c040a0c;
P_0c040a0c: /* original e300, guest PC 0x0c040a0c */
if(!s->budget--) { s->failed_pc=0x0c040a0cu; return 0; }
r[3]=0x00000000u;
goto P_0c040a0e;
P_0c040a0e: /* original 1f33, guest PC 0x0c040a0e */
if(!s->budget--) { s->failed_pc=0x0c040a0eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c040a10;
P_0c040a10: /* original a011, guest PC 0x0c040a10 */
if(!s->budget--) { s->failed_pc=0x0c040a10u; return 0; }
goto P_0c040a36;
P_0c040a12: /* original 0009, guest PC 0x0c040a12 */
if(!s->budget--) { s->failed_pc=0x0c040a12u; return 0; }
goto P_0c040a14;
P_0c040a14: /* original 9405, guest PC 0x0c040a14 */
if(!s->budget--) { s->failed_pc=0x0c040a14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040a22u,2);
goto P_0c040a16;
P_0c040a16: /* original b282, guest PC 0x0c040a16 */
if(!s->budget--) { s->failed_pc=0x0c040a16u; return 0; }
target=code_base|0x0c040f1eu; r[16]=code_base|0x0c040a1au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040a1au) { target=s->pc; goto dispatch; }
goto P_0c040a1a;
P_0c040a18: /* original 0009, guest PC 0x0c040a18 */
if(!s->budget--) { s->failed_pc=0x0c040a18u; return 0; }
goto P_0c040a1a;
P_0c040a1a: /* original 2008, guest PC 0x0c040a1a */
if(!s->budget--) { s->failed_pc=0x0c040a1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c040a1c;
P_0c040a1c: /* original 8b08, guest PC 0x0c040a1c */
if(!s->budget--) { s->failed_pc=0x0c040a1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040a30; }
goto P_0c040a1e;
P_0c040a1e: /* original a013, guest PC 0x0c040a1e */
if(!s->budget--) { s->failed_pc=0x0c040a1eu; return 0; }
goto P_0c040a48;
P_0c040a20: /* original 0009, guest PC 0x0c040a20 */
if(!s->budget--) { s->failed_pc=0x0c040a20u; return 0; }
if(!vf3_matrix_family(0x0c040a22u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040a22u; return 0; } return 1;
P_0c040a30: /* original 52f3, guest PC 0x0c040a30 */
if(!s->budget--) { s->failed_pc=0x0c040a30u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c040a32;
P_0c040a32: /* original 7201, guest PC 0x0c040a32 */
if(!s->budget--) { s->failed_pc=0x0c040a32u; return 0; }
r[2]+=0x00000001u;
goto P_0c040a34;
P_0c040a34: /* original 1f23, guest PC 0x0c040a34 */
if(!s->budget--) { s->failed_pc=0x0c040a34u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c040a36;
P_0c040a36: /* original d322, guest PC 0x0c040a36 */
if(!s->budget--) { s->failed_pc=0x0c040a36u; return 0; }
r[3]=read(ram,0x0c040ac0u,4);
goto P_0c040a38;
P_0c040a38: /* original 51f3, guest PC 0x0c040a38 */
if(!s->budget--) { s->failed_pc=0x0c040a38u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c040a3a;
P_0c040a3a: /* original 3133, guest PC 0x0c040a3a */
if(!s->budget--) { s->failed_pc=0x0c040a3au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c040a3c;
P_0c040a3c: /* original 8bea, guest PC 0x0c040a3c */
if(!s->budget--) { s->failed_pc=0x0c040a3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040a14; }
goto P_0c040a3e;
P_0c040a3e: /* original 903d, guest PC 0x0c040a3e */
if(!s->budget--) { s->failed_pc=0x0c040a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040abcu,2);
goto P_0c040a40;
P_0c040a40: /* original 7f18, guest PC 0x0c040a40 */
if(!s->budget--) { s->failed_pc=0x0c040a40u; return 0; }
r[15]+=0x00000018u;
goto P_0c040a42;
P_0c040a42: /* original 4f26, guest PC 0x0c040a42 */
if(!s->budget--) { s->failed_pc=0x0c040a42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040a44;
P_0c040a44: /* original 000b, guest PC 0x0c040a44 */
if(!s->budget--) { s->failed_pc=0x0c040a44u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040a46: /* original 0009, guest PC 0x0c040a46 */
if(!s->budget--) { s->failed_pc=0x0c040a46u; return 0; }
goto P_0c040a48;
P_0c040a48: /* original e300, guest PC 0x0c040a48 */
if(!s->budget--) { s->failed_pc=0x0c040a48u; return 0; }
r[3]=0x00000000u;
goto P_0c040a4a;
P_0c040a4a: /* original 1f33, guest PC 0x0c040a4a */
if(!s->budget--) { s->failed_pc=0x0c040a4au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c040a4c;
P_0c040a4c: /* original a009, guest PC 0x0c040a4c */
if(!s->budget--) { s->failed_pc=0x0c040a4cu; return 0; }
goto P_0c040a62;
P_0c040a4e: /* original 0009, guest PC 0x0c040a4e */
if(!s->budget--) { s->failed_pc=0x0c040a4eu; return 0; }
goto P_0c040a50;
P_0c040a50: /* original d21c, guest PC 0x0c040a50 */
if(!s->budget--) { s->failed_pc=0x0c040a50u; return 0; }
r[2]=read(ram,0x0c040ac4u,4);
goto P_0c040a52;
P_0c040a52: /* original 6122, guest PC 0x0c040a52 */
if(!s->budget--) { s->failed_pc=0x0c040a52u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040a54;
P_0c040a54: /* original 2118, guest PC 0x0c040a54 */
if(!s->budget--) { s->failed_pc=0x0c040a54u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040a56;
P_0c040a56: /* original 8901, guest PC 0x0c040a56 */
if(!s->budget--) { s->failed_pc=0x0c040a56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040a5c; }
goto P_0c040a58;
P_0c040a58: /* original a00c, guest PC 0x0c040a58 */
if(!s->budget--) { s->failed_pc=0x0c040a58u; return 0; }
goto P_0c040a74;
P_0c040a5a: /* original 0009, guest PC 0x0c040a5a */
if(!s->budget--) { s->failed_pc=0x0c040a5au; return 0; }
goto P_0c040a5c;
P_0c040a5c: /* original 52f3, guest PC 0x0c040a5c */
if(!s->budget--) { s->failed_pc=0x0c040a5cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c040a5e;
P_0c040a5e: /* original 7201, guest PC 0x0c040a5e */
if(!s->budget--) { s->failed_pc=0x0c040a5eu; return 0; }
r[2]+=0x00000001u;
goto P_0c040a60;
P_0c040a60: /* original 1f23, guest PC 0x0c040a60 */
if(!s->budget--) { s->failed_pc=0x0c040a60u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c040a62;
P_0c040a62: /* original d317, guest PC 0x0c040a62 */
if(!s->budget--) { s->failed_pc=0x0c040a62u; return 0; }
r[3]=read(ram,0x0c040ac0u,4);
goto P_0c040a64;
P_0c040a64: /* original 51f3, guest PC 0x0c040a64 */
if(!s->budget--) { s->failed_pc=0x0c040a64u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c040a66;
P_0c040a66: /* original 3133, guest PC 0x0c040a66 */
if(!s->budget--) { s->failed_pc=0x0c040a66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c040a68;
P_0c040a68: /* original 8bf2, guest PC 0x0c040a68 */
if(!s->budget--) { s->failed_pc=0x0c040a68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040a50; }
goto P_0c040a6a;
P_0c040a6a: /* original 9027, guest PC 0x0c040a6a */
if(!s->budget--) { s->failed_pc=0x0c040a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040abcu,2);
goto P_0c040a6c;
P_0c040a6c: /* original 7f18, guest PC 0x0c040a6c */
if(!s->budget--) { s->failed_pc=0x0c040a6cu; return 0; }
r[15]+=0x00000018u;
goto P_0c040a6e;
P_0c040a6e: /* original 4f26, guest PC 0x0c040a6e */
if(!s->budget--) { s->failed_pc=0x0c040a6eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040a70;
P_0c040a70: /* original 000b, guest PC 0x0c040a70 */
if(!s->budget--) { s->failed_pc=0x0c040a70u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040a72: /* original 0009, guest PC 0x0c040a72 */
if(!s->budget--) { s->failed_pc=0x0c040a72u; return 0; }
goto P_0c040a74;
P_0c040a74: /* original 53f4, guest PC 0x0c040a74 */
if(!s->budget--) { s->failed_pc=0x0c040a74u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c040a76;
P_0c040a76: /* original 2338, guest PC 0x0c040a76 */
if(!s->budget--) { s->failed_pc=0x0c040a76u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c040a78;
P_0c040a78: /* original 8913, guest PC 0x0c040a78 */
if(!s->budget--) { s->failed_pc=0x0c040a78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040aa2; }
goto P_0c040a7a;
P_0c040a7a: /* original 56f2, guest PC 0x0c040a7a */
if(!s->budget--) { s->failed_pc=0x0c040a7au; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c040a7c;
P_0c040a7c: /* original 53f1, guest PC 0x0c040a7c */
if(!s->budget--) { s->failed_pc=0x0c040a7cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c040a7e;
P_0c040a7e: /* original 55f4, guest PC 0x0c040a7e */
if(!s->budget--) { s->failed_pc=0x0c040a7eu; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c040a80;
P_0c040a80: /* original 3538, guest PC 0x0c040a80 */
if(!s->budget--) { s->failed_pc=0x0c040a80u; return 0; }
r[5]-=r[3];
goto P_0c040a82;
P_0c040a82: /* original 54f4, guest PC 0x0c040a82 */
if(!s->budget--) { s->failed_pc=0x0c040a82u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c040a84;
P_0c040a84: /* original bb1c, guest PC 0x0c040a84 */
if(!s->budget--) { s->failed_pc=0x0c040a84u; return 0; }
target=code_base|0x0c0400c0u; r[16]=code_base|0x0c040a88u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040a88u) { target=s->pc; goto dispatch; }
goto P_0c040a88;
P_0c040a86: /* original 0009, guest PC 0x0c040a86 */
if(!s->budget--) { s->failed_pc=0x0c040a86u; return 0; }
goto P_0c040a88;
P_0c040a88: /* original 2f02, guest PC 0x0c040a88 */
if(!s->budget--) { s->failed_pc=0x0c040a88u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c040a8a;
P_0c040a8a: /* original 2008, guest PC 0x0c040a8a */
if(!s->budget--) { s->failed_pc=0x0c040a8au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c040a8c;
P_0c040a8c: /* original 8903, guest PC 0x0c040a8c */
if(!s->budget--) { s->failed_pc=0x0c040a8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040a96; }
goto P_0c040a8e;
P_0c040a8e: /* original 7f18, guest PC 0x0c040a8e */
if(!s->budget--) { s->failed_pc=0x0c040a8eu; return 0; }
r[15]+=0x00000018u;
goto P_0c040a90;
P_0c040a90: /* original 4f26, guest PC 0x0c040a90 */
if(!s->budget--) { s->failed_pc=0x0c040a90u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040a92;
P_0c040a92: /* original 000b, guest PC 0x0c040a92 */
if(!s->budget--) { s->failed_pc=0x0c040a92u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040a94: /* original 0009, guest PC 0x0c040a94 */
if(!s->budget--) { s->failed_pc=0x0c040a94u; return 0; }
goto P_0c040a96;
P_0c040a96: /* original a000, guest PC 0x0c040a96 */
if(!s->budget--) { s->failed_pc=0x0c040a96u; return 0; }
goto P_0c040a9a;
P_0c040a98: /* original 0009, guest PC 0x0c040a98 */
if(!s->budget--) { s->failed_pc=0x0c040a98u; return 0; }
goto P_0c040a9a;
P_0c040a9a: /* original bb4f, guest PC 0x0c040a9a */
if(!s->budget--) { s->failed_pc=0x0c040a9au; return 0; }
target=code_base|0x0c04013cu; r[16]=code_base|0x0c040a9eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040a9eu) { target=s->pc; goto dispatch; }
goto P_0c040a9e;
P_0c040a9c: /* original 0009, guest PC 0x0c040a9c */
if(!s->budget--) { s->failed_pc=0x0c040a9cu; return 0; }
goto P_0c040a9e;
P_0c040a9e: /* original 2008, guest PC 0x0c040a9e */
if(!s->budget--) { s->failed_pc=0x0c040a9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c040aa0;
P_0c040aa0: /* original 8bfb, guest PC 0x0c040aa0 */
if(!s->budget--) { s->failed_pc=0x0c040aa0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040a9a; }
goto P_0c040aa2;
P_0c040aa2: /* original e301, guest PC 0x0c040aa2 */
if(!s->budget--) { s->failed_pc=0x0c040aa2u; return 0; }
r[3]=0x00000001u;
goto P_0c040aa4;
P_0c040aa4: /* original d208, guest PC 0x0c040aa4 */
if(!s->budget--) { s->failed_pc=0x0c040aa4u; return 0; }
r[2]=read(ram,0x0c040ac8u,4);
goto P_0c040aa6;
P_0c040aa6: /* original 2232, guest PC 0x0c040aa6 */
if(!s->budget--) { s->failed_pc=0x0c040aa6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040aa8;
P_0c040aa8: /* original e100, guest PC 0x0c040aa8 */
if(!s->budget--) { s->failed_pc=0x0c040aa8u; return 0; }
r[1]=0x00000000u;
goto P_0c040aaa;
P_0c040aaa: /* original 1f13, guest PC 0x0c040aaa */
if(!s->budget--) { s->failed_pc=0x0c040aaau; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c040aac;
P_0c040aac: /* original a011, guest PC 0x0c040aac */
if(!s->budget--) { s->failed_pc=0x0c040aacu; return 0; }
goto P_0c040ad2;
P_0c040aae: /* original 0009, guest PC 0x0c040aae */
if(!s->budget--) { s->failed_pc=0x0c040aaeu; return 0; }
goto P_0c040ab0;
P_0c040ab0: /* original d304, guest PC 0x0c040ab0 */
if(!s->budget--) { s->failed_pc=0x0c040ab0u; return 0; }
r[3]=read(ram,0x0c040ac4u,4);
goto P_0c040ab2;
P_0c040ab2: /* original 6232, guest PC 0x0c040ab2 */
if(!s->budget--) { s->failed_pc=0x0c040ab2u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040ab4;
P_0c040ab4: /* original 2228, guest PC 0x0c040ab4 */
if(!s->budget--) { s->failed_pc=0x0c040ab4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c040ab6;
P_0c040ab6: /* original 8b09, guest PC 0x0c040ab6 */
if(!s->budget--) { s->failed_pc=0x0c040ab6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040acc; }
goto P_0c040ab8;
P_0c040ab8: /* original a014, guest PC 0x0c040ab8 */
if(!s->budget--) { s->failed_pc=0x0c040ab8u; return 0; }
goto P_0c040ae4;
P_0c040aba: /* original 0009, guest PC 0x0c040aba */
if(!s->budget--) { s->failed_pc=0x0c040abau; return 0; }
if(!vf3_matrix_family(0x0c040abcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040abcu; return 0; } return 1;
P_0c040acc: /* original 53f3, guest PC 0x0c040acc */
if(!s->budget--) { s->failed_pc=0x0c040accu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c040ace;
P_0c040ace: /* original 7301, guest PC 0x0c040ace */
if(!s->budget--) { s->failed_pc=0x0c040aceu; return 0; }
r[3]+=0x00000001u;
goto P_0c040ad0;
P_0c040ad0: /* original 1f33, guest PC 0x0c040ad0 */
if(!s->budget--) { s->failed_pc=0x0c040ad0u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c040ad2;
P_0c040ad2: /* original d211, guest PC 0x0c040ad2 */
if(!s->budget--) { s->failed_pc=0x0c040ad2u; return 0; }
r[2]=read(ram,0x0c040b18u,4);
goto P_0c040ad4;
P_0c040ad4: /* original 51f3, guest PC 0x0c040ad4 */
if(!s->budget--) { s->failed_pc=0x0c040ad4u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c040ad6;
P_0c040ad6: /* original 3123, guest PC 0x0c040ad6 */
if(!s->budget--) { s->failed_pc=0x0c040ad6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c040ad8;
P_0c040ad8: /* original 8bea, guest PC 0x0c040ad8 */
if(!s->budget--) { s->failed_pc=0x0c040ad8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040ab0; }
goto P_0c040ada;
P_0c040ada: /* original 901c, guest PC 0x0c040ada */
if(!s->budget--) { s->failed_pc=0x0c040adau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040b16u,2);
goto P_0c040adc;
P_0c040adc: /* original 7f18, guest PC 0x0c040adc */
if(!s->budget--) { s->failed_pc=0x0c040adcu; return 0; }
r[15]+=0x00000018u;
goto P_0c040ade;
P_0c040ade: /* original 4f26, guest PC 0x0c040ade */
if(!s->budget--) { s->failed_pc=0x0c040adeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040ae0;
P_0c040ae0: /* original 000b, guest PC 0x0c040ae0 */
if(!s->budget--) { s->failed_pc=0x0c040ae0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040ae2: /* original 0009, guest PC 0x0c040ae2 */
if(!s->budget--) { s->failed_pc=0x0c040ae2u; return 0; }
goto P_0c040ae4;
P_0c040ae4: /* original e200, guest PC 0x0c040ae4 */
if(!s->budget--) { s->failed_pc=0x0c040ae4u; return 0; }
r[2]=0x00000000u;
goto P_0c040ae6;
P_0c040ae6: /* original d30d, guest PC 0x0c040ae6 */
if(!s->budget--) { s->failed_pc=0x0c040ae6u; return 0; }
r[3]=read(ram,0x0c040b1cu,4);
goto P_0c040ae8;
P_0c040ae8: /* original 2322, guest PC 0x0c040ae8 */
if(!s->budget--) { s->failed_pc=0x0c040ae8u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040aea;
P_0c040aea: /* original e000, guest PC 0x0c040aea */
if(!s->budget--) { s->failed_pc=0x0c040aeau; return 0; }
r[0]=0x00000000u;
goto P_0c040aec;
P_0c040aec: /* original 7f18, guest PC 0x0c040aec */
if(!s->budget--) { s->failed_pc=0x0c040aecu; return 0; }
r[15]+=0x00000018u;
goto P_0c040aee;
P_0c040aee: /* original 4f26, guest PC 0x0c040aee */
if(!s->budget--) { s->failed_pc=0x0c040aeeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040af0;
P_0c040af0: /* original 000b, guest PC 0x0c040af0 */
if(!s->budget--) { s->failed_pc=0x0c040af0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040af2: /* original 0009, guest PC 0x0c040af2 */
if(!s->budget--) { s->failed_pc=0x0c040af2u; return 0; }
if(!vf3_matrix_family(0x0c040af4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040af4u; return 0; } return 1;
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
if(!vf3_matrix_family(0x0c040f68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040f68u; return 0; } return 1;
P_0c046314: /* original 000b, guest PC 0x0c046314 */
if(!s->budget--) { s->failed_pc=0x0c046314u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c046316: /* original 0009, guest PC 0x0c046316 */
if(!s->budget--) { s->failed_pc=0x0c046316u; return 0; }
if(!vf3_matrix_family(0x0c046318u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c046318u; return 0; } return 1;
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
P_0c096864: /* original 2fe6, guest PC 0x0c096864 */
if(!s->budget--) { s->failed_pc=0x0c096864u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096866;
P_0c096866: /* original 4f22, guest PC 0x0c096866 */
if(!s->budget--) { s->failed_pc=0x0c096866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096868;
P_0c096868: /* original 7ff8, guest PC 0x0c096868 */
if(!s->budget--) { s->failed_pc=0x0c096868u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09686a;
P_0c09686a: /* original 2f42, guest PC 0x0c09686a */
if(!s->budget--) { s->failed_pc=0x0c09686au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09686c;
P_0c09686c: /* original d311, guest PC 0x0c09686c */
if(!s->budget--) { s->failed_pc=0x0c09686cu; return 0; }
r[3]=read(ram,0x0c0968b4u,4);
goto P_0c09686e;
P_0c09686e: /* original 430b, guest PC 0x0c09686e */
if(!s->budget--) { s->failed_pc=0x0c09686eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096872u;
write(ram,r[15]+4,r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096872u) { target=s->pc; goto dispatch; }
goto P_0c096872;
P_0c096870: /* original 1f51, guest PC 0x0c096870 */
if(!s->budget--) { s->failed_pc=0x0c096870u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c096872;
P_0c096872: /* original 6e03, guest PC 0x0c096872 */
if(!s->budget--) { s->failed_pc=0x0c096872u; return 0; }
r[14]=r[0];
goto P_0c096874;
P_0c096874: /* original 2ee8, guest PC 0x0c096874 */
if(!s->budget--) { s->failed_pc=0x0c096874u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c096876;
P_0c096876: /* original 8905, guest PC 0x0c096876 */
if(!s->budget--) { s->failed_pc=0x0c096876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096884; }
goto P_0c096878;
P_0c096878: /* original d30f, guest PC 0x0c096878 */
if(!s->budget--) { s->failed_pc=0x0c096878u; return 0; }
r[3]=read(ram,0x0c0968b8u,4);
goto P_0c09687a;
P_0c09687a: /* original 430b, guest PC 0x0c09687a */
if(!s->budget--) { s->failed_pc=0x0c09687au; return 0; }
target=r[3];
r[16]=code_base|0x0c09687eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09687eu) { target=s->pc; goto dispatch; }
goto P_0c09687e;
P_0c09687c: /* original 64e3, guest PC 0x0c09687c */
if(!s->budget--) { s->failed_pc=0x0c09687cu; return 0; }
r[4]=r[14];
goto P_0c09687e;
P_0c09687e: /* original d20f, guest PC 0x0c09687e */
if(!s->budget--) { s->failed_pc=0x0c09687eu; return 0; }
r[2]=read(ram,0x0c0968bcu,4);
goto P_0c096880;
P_0c096880: /* original 420b, guest PC 0x0c096880 */
if(!s->budget--) { s->failed_pc=0x0c096880u; return 0; }
target=r[2];
r[16]=code_base|0x0c096884u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096884u) { target=s->pc; goto dispatch; }
goto P_0c096884;
P_0c096882: /* original 64e3, guest PC 0x0c096882 */
if(!s->budget--) { s->failed_pc=0x0c096882u; return 0; }
r[4]=r[14];
goto P_0c096884;
P_0c096884: /* original 0002, guest PC 0x0c096884 */
if(!s->budget--) { s->failed_pc=0x0c096884u; return 0; }
r[0]=r[17];
goto P_0c096886;
P_0c096886: /* original 9313, guest PC 0x0c096886 */
if(!s->budget--) { s->failed_pc=0x0c096886u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c096888;
P_0c096888: /* original 2039, guest PC 0x0c096888 */
if(!s->budget--) { s->failed_pc=0x0c096888u; return 0; }
r[0]&=r[3];
goto P_0c09688a;
P_0c09688a: /* original cbe0, guest PC 0x0c09688a */
if(!s->budget--) { s->failed_pc=0x0c09688au; return 0; }
r[0]|=224u;
goto P_0c09688c;
P_0c09688c: /* original 400e, guest PC 0x0c09688c */
if(!s->budget--) { s->failed_pc=0x0c09688cu; return 0; }
r[17]=r[0];
goto P_0c09688e;
P_0c09688e: /* original d20c, guest PC 0x0c09688e */
if(!s->budget--) { s->failed_pc=0x0c09688eu; return 0; }
r[2]=read(ram,0x0c0968c0u,4);
goto P_0c096890;
P_0c096890: /* original 420b, guest PC 0x0c096890 */
if(!s->budget--) { s->failed_pc=0x0c096890u; return 0; }
target=r[2];
r[16]=code_base|0x0c096894u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096894u) { target=s->pc; goto dispatch; }
goto P_0c096894;
P_0c096892: /* original 0009, guest PC 0x0c096892 */
if(!s->budget--) { s->failed_pc=0x0c096892u; return 0; }
goto P_0c096894;
P_0c096894: /* original d10b, guest PC 0x0c096894 */
if(!s->budget--) { s->failed_pc=0x0c096894u; return 0; }
r[1]=read(ram,0x0c0968c4u,4);
goto P_0c096896;
P_0c096896: /* original 410b, guest PC 0x0c096896 */
if(!s->budget--) { s->failed_pc=0x0c096896u; return 0; }
target=r[1];
r[16]=code_base|0x0c09689au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09689au) { target=s->pc; goto dispatch; }
goto P_0c09689a;
P_0c096898: /* original 0009, guest PC 0x0c096898 */
if(!s->budget--) { s->failed_pc=0x0c096898u; return 0; }
goto P_0c09689a;
P_0c09689a: /* original 0002, guest PC 0x0c09689a */
if(!s->budget--) { s->failed_pc=0x0c09689au; return 0; }
r[0]=r[17];
goto P_0c09689c;
P_0c09689c: /* original 9208, guest PC 0x0c09689c */
if(!s->budget--) { s->failed_pc=0x0c09689cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c09689e;
P_0c09689e: /* original 2029, guest PC 0x0c09689e */
if(!s->budget--) { s->failed_pc=0x0c09689eu; return 0; }
r[0]&=r[2];
goto P_0c0968a0;
P_0c0968a0: /* original 400e, guest PC 0x0c0968a0 */
if(!s->budget--) { s->failed_pc=0x0c0968a0u; return 0; }
r[17]=r[0];
goto P_0c0968a2;
P_0c0968a2: /* original 64f2, guest PC 0x0c0968a2 */
if(!s->budget--) { s->failed_pc=0x0c0968a2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0968a4;
P_0c0968a4: /* original 55f1, guest PC 0x0c0968a4 */
if(!s->budget--) { s->failed_pc=0x0c0968a4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0968a6;
P_0c0968a6: /* original 7f08, guest PC 0x0c0968a6 */
if(!s->budget--) { s->failed_pc=0x0c0968a6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0968a8;
P_0c0968a8: /* original 4f26, guest PC 0x0c0968a8 */
if(!s->budget--) { s->failed_pc=0x0c0968a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0968aa;
P_0c0968aa: /* original d307, guest PC 0x0c0968aa */
if(!s->budget--) { s->failed_pc=0x0c0968aau; return 0; }
r[3]=read(ram,0x0c0968c8u,4);
goto P_0c0968ac;
P_0c0968ac: /* original 432b, guest PC 0x0c0968ac */
if(!s->budget--) { s->failed_pc=0x0c0968acu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
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
P_0c0968ae: /* original 6ef6, guest PC 0x0c0968ae */
if(!s->budget--) { s->failed_pc=0x0c0968aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0968b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0968b0u; return 0; } return 1;
P_0c0a7f5a: /* original 2fe6, guest PC 0x0c0a7f5a */
if(!s->budget--) { s->failed_pc=0x0c0a7f5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5c;
P_0c0a7f5c: /* original 2fd6, guest PC 0x0c0a7f5c */
if(!s->budget--) { s->failed_pc=0x0c0a7f5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5e;
P_0c0a7f5e: /* original 2fc6, guest PC 0x0c0a7f5e */
if(!s->budget--) { s->failed_pc=0x0c0a7f5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f60;
P_0c0a7f60: /* original 2fb6, guest PC 0x0c0a7f60 */
if(!s->budget--) { s->failed_pc=0x0c0a7f60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f62;
P_0c0a7f62: /* original 6b43, guest PC 0x0c0a7f62 */
if(!s->budget--) { s->failed_pc=0x0c0a7f62u; return 0; }
r[11]=r[4];
goto P_0c0a7f64;
P_0c0a7f64: /* original 2fa6, guest PC 0x0c0a7f64 */
if(!s->budget--) { s->failed_pc=0x0c0a7f64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f66;
P_0c0a7f66: /* original e400, guest PC 0x0c0a7f66 */
if(!s->budget--) { s->failed_pc=0x0c0a7f66u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7f68;
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
if(!vf3_matrix_family(0x0c0a7fa6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7fa6u; return 0; } return 1;
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7fc8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a7fd6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7ff6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8000u;
r[5]=0x00000072u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8006u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a801au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8024u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a802au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a803cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a803cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
