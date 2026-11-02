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
int vf3_away_batch18_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
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
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c042cc0u,s,ram); }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
return vf3_matrix_family(0x0c042cc0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
