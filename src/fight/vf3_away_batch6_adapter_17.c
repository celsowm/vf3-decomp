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
int vf3_away_batch6_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c050a20u: goto P_0c050a20;
case 0x0c050a22u: goto P_0c050a22;
case 0x0c050a24u: goto P_0c050a24;
case 0x0c050a26u: goto P_0c050a26;
case 0x0c050a28u: goto P_0c050a28;
case 0x0c050a2au: goto P_0c050a2a;
case 0x0c050a2cu: goto P_0c050a2c;
case 0x0c050a2eu: goto P_0c050a2e;
case 0x0c050a30u: goto P_0c050a30;
case 0x0c050a32u: goto P_0c050a32;
case 0x0c050a34u: goto P_0c050a34;
case 0x0c050a36u: goto P_0c050a36;
case 0x0c050a38u: goto P_0c050a38;
case 0x0c050a3au: goto P_0c050a3a;
case 0x0c050a3cu: goto P_0c050a3c;
case 0x0c050a3eu: goto P_0c050a3e;
case 0x0c050a40u: goto P_0c050a40;
case 0x0c050a42u: goto P_0c050a42;
case 0x0c050a44u: goto P_0c050a44;
case 0x0c050a46u: goto P_0c050a46;
case 0x0c050a48u: goto P_0c050a48;
case 0x0c050a4au: goto P_0c050a4a;
case 0x0c050a4cu: goto P_0c050a4c;
case 0x0c050a4eu: goto P_0c050a4e;
case 0x0c050a50u: goto P_0c050a50;
case 0x0c050a52u: goto P_0c050a52;
case 0x0c050a54u: goto P_0c050a54;
case 0x0c050a56u: goto P_0c050a56;
case 0x0c050a58u: goto P_0c050a58;
case 0x0c050a5au: goto P_0c050a5a;
case 0x0c050a5cu: goto P_0c050a5c;
case 0x0c050a5eu: goto P_0c050a5e;
case 0x0c050a60u: goto P_0c050a60;
case 0x0c050a62u: goto P_0c050a62;
case 0x0c050a64u: goto P_0c050a64;
case 0x0c050a66u: goto P_0c050a66;
case 0x0c050a68u: goto P_0c050a68;
case 0x0c050a6au: goto P_0c050a6a;
case 0x0c050a6cu: goto P_0c050a6c;
case 0x0c050a6eu: goto P_0c050a6e;
case 0x0c050a70u: goto P_0c050a70;
case 0x0c050a72u: goto P_0c050a72;
case 0x0c050a74u: goto P_0c050a74;
case 0x0c050a76u: goto P_0c050a76;
case 0x0c050a78u: goto P_0c050a78;
case 0x0c050a7au: goto P_0c050a7a;
case 0x0c050a7cu: goto P_0c050a7c;
case 0x0c050a7eu: goto P_0c050a7e;
case 0x0c050a80u: goto P_0c050a80;
case 0x0c050a82u: goto P_0c050a82;
case 0x0c050a84u: goto P_0c050a84;
case 0x0c050a86u: goto P_0c050a86;
case 0x0c050a88u: goto P_0c050a88;
case 0x0c050a8au: goto P_0c050a8a;
case 0x0c050a8cu: goto P_0c050a8c;
case 0x0c050a8eu: goto P_0c050a8e;
case 0x0c050a90u: goto P_0c050a90;
case 0x0c050a92u: goto P_0c050a92;
case 0x0c050a94u: goto P_0c050a94;
case 0x0c050a96u: goto P_0c050a96;
case 0x0c050a98u: goto P_0c050a98;
case 0x0c050a9au: goto P_0c050a9a;
case 0x0c050a9cu: goto P_0c050a9c;
case 0x0c050a9eu: goto P_0c050a9e;
case 0x0c050aa0u: goto P_0c050aa0;
case 0x0c050aa2u: goto P_0c050aa2;
case 0x0c050aa4u: goto P_0c050aa4;
case 0x0c050aa6u: goto P_0c050aa6;
case 0x0c050aa8u: goto P_0c050aa8;
case 0x0c050aaau: goto P_0c050aaa;
case 0x0c050aacu: goto P_0c050aac;
case 0x0c050aaeu: goto P_0c050aae;
case 0x0c050ab0u: goto P_0c050ab0;
case 0x0c050ab2u: goto P_0c050ab2;
case 0x0c050ab4u: goto P_0c050ab4;
case 0x0c050ab6u: goto P_0c050ab6;
case 0x0c050ab8u: goto P_0c050ab8;
case 0x0c050abau: goto P_0c050aba;
case 0x0c050abcu: goto P_0c050abc;
case 0x0c050abeu: goto P_0c050abe;
case 0x0c050ad4u: goto P_0c050ad4;
case 0x0c050ad6u: goto P_0c050ad6;
case 0x0c050ad8u: goto P_0c050ad8;
case 0x0c050adau: goto P_0c050ada;
case 0x0c050adcu: goto P_0c050adc;
case 0x0c050adeu: goto P_0c050ade;
case 0x0c050ae0u: goto P_0c050ae0;
case 0x0c050ae2u: goto P_0c050ae2;
case 0x0c050ae4u: goto P_0c050ae4;
case 0x0c050ae6u: goto P_0c050ae6;
case 0x0c050ae8u: goto P_0c050ae8;
case 0x0c050aeau: goto P_0c050aea;
case 0x0c050aecu: goto P_0c050aec;
case 0x0c050aeeu: goto P_0c050aee;
case 0x0c050af0u: goto P_0c050af0;
case 0x0c050af2u: goto P_0c050af2;
case 0x0c050af4u: goto P_0c050af4;
case 0x0c050af6u: goto P_0c050af6;
case 0x0c050af8u: goto P_0c050af8;
case 0x0c050afau: goto P_0c050afa;
case 0x0c050afcu: goto P_0c050afc;
case 0x0c050afeu: goto P_0c050afe;
case 0x0c050b00u: goto P_0c050b00;
case 0x0c050b02u: goto P_0c050b02;
case 0x0c050b04u: goto P_0c050b04;
case 0x0c050b06u: goto P_0c050b06;
case 0x0c050b08u: goto P_0c050b08;
case 0x0c050b0au: goto P_0c050b0a;
case 0x0c050b0cu: goto P_0c050b0c;
case 0x0c050b0eu: goto P_0c050b0e;
case 0x0c050b10u: goto P_0c050b10;
case 0x0c050b12u: goto P_0c050b12;
case 0x0c050b14u: goto P_0c050b14;
case 0x0c050b16u: goto P_0c050b16;
case 0x0c050b18u: goto P_0c050b18;
case 0x0c050b1au: goto P_0c050b1a;
case 0x0c050b1cu: goto P_0c050b1c;
case 0x0c050b1eu: goto P_0c050b1e;
case 0x0c050b20u: goto P_0c050b20;
case 0x0c050b22u: goto P_0c050b22;
case 0x0c050b24u: goto P_0c050b24;
case 0x0c050b26u: goto P_0c050b26;
case 0x0c050b28u: goto P_0c050b28;
case 0x0c050b2au: goto P_0c050b2a;
case 0x0c050b2cu: goto P_0c050b2c;
case 0x0c050b2eu: goto P_0c050b2e;
case 0x0c050b30u: goto P_0c050b30;
case 0x0c050b32u: goto P_0c050b32;
case 0x0c050b34u: goto P_0c050b34;
case 0x0c050b36u: goto P_0c050b36;
case 0x0c050b38u: goto P_0c050b38;
case 0x0c050b3au: goto P_0c050b3a;
case 0x0c050b3cu: goto P_0c050b3c;
case 0x0c050b3eu: goto P_0c050b3e;
case 0x0c050b40u: goto P_0c050b40;
case 0x0c050b42u: goto P_0c050b42;
case 0x0c052f24u: goto P_0c052f24;
case 0x0c052f26u: goto P_0c052f26;
case 0x0c052f28u: goto P_0c052f28;
case 0x0c052f2au: goto P_0c052f2a;
case 0x0c052f2cu: goto P_0c052f2c;
case 0x0c052f2eu: goto P_0c052f2e;
case 0x0c052f30u: goto P_0c052f30;
case 0x0c052f32u: goto P_0c052f32;
case 0x0c052f34u: goto P_0c052f34;
case 0x0c052f36u: goto P_0c052f36;
case 0x0c052f38u: goto P_0c052f38;
case 0x0c052f3au: goto P_0c052f3a;
case 0x0c052f3cu: goto P_0c052f3c;
case 0x0c052f3eu: goto P_0c052f3e;
case 0x0c052f40u: goto P_0c052f40;
case 0x0c052f42u: goto P_0c052f42;
case 0x0c052f44u: goto P_0c052f44;
case 0x0c052f46u: goto P_0c052f46;
case 0x0c052f48u: goto P_0c052f48;
case 0x0c052f4au: goto P_0c052f4a;
case 0x0c052f4cu: goto P_0c052f4c;
case 0x0c052f4eu: goto P_0c052f4e;
case 0x0c052f50u: goto P_0c052f50;
case 0x0c052f52u: goto P_0c052f52;
case 0x0c052f54u: goto P_0c052f54;
case 0x0c052f56u: goto P_0c052f56;
case 0x0c052f58u: goto P_0c052f58;
case 0x0c052f5au: goto P_0c052f5a;
case 0x0c052f5cu: goto P_0c052f5c;
case 0x0c052f5eu: goto P_0c052f5e;
case 0x0c052f60u: goto P_0c052f60;
case 0x0c052f62u: goto P_0c052f62;
case 0x0c052f64u: goto P_0c052f64;
case 0x0c052f66u: goto P_0c052f66;
case 0x0c052f68u: goto P_0c052f68;
case 0x0c052f6au: goto P_0c052f6a;
case 0x0c052f6cu: goto P_0c052f6c;
case 0x0c052f6eu: goto P_0c052f6e;
case 0x0c052f70u: goto P_0c052f70;
case 0x0c052f72u: goto P_0c052f72;
case 0x0c052f74u: goto P_0c052f74;
case 0x0c052f76u: goto P_0c052f76;
case 0x0c052f78u: goto P_0c052f78;
case 0x0c052f7au: goto P_0c052f7a;
case 0x0c052f7cu: goto P_0c052f7c;
case 0x0c052f7eu: goto P_0c052f7e;
case 0x0c052f80u: goto P_0c052f80;
case 0x0c052f82u: goto P_0c052f82;
case 0x0c052f84u: goto P_0c052f84;
case 0x0c052f86u: goto P_0c052f86;
case 0x0c052f88u: goto P_0c052f88;
case 0x0c052f8au: goto P_0c052f8a;
case 0x0c052f8cu: goto P_0c052f8c;
case 0x0c052f8eu: goto P_0c052f8e;
case 0x0c052f90u: goto P_0c052f90;
case 0x0c052f92u: goto P_0c052f92;
case 0x0c052f94u: goto P_0c052f94;
case 0x0c052f96u: goto P_0c052f96;
case 0x0c052f98u: goto P_0c052f98;
case 0x0c052f9au: goto P_0c052f9a;
case 0x0c052f9cu: goto P_0c052f9c;
case 0x0c052f9eu: goto P_0c052f9e;
case 0x0c052fa0u: goto P_0c052fa0;
case 0x0c052fa2u: goto P_0c052fa2;
case 0x0c052fa4u: goto P_0c052fa4;
case 0x0c052fa6u: goto P_0c052fa6;
case 0x0c052fa8u: goto P_0c052fa8;
case 0x0c052faau: goto P_0c052faa;
case 0x0c052facu: goto P_0c052fac;
case 0x0c052faeu: goto P_0c052fae;
case 0x0c052fb0u: goto P_0c052fb0;
case 0x0c052fb2u: goto P_0c052fb2;
case 0x0c052fb4u: goto P_0c052fb4;
case 0x0c052fb6u: goto P_0c052fb6;
case 0x0c052fb8u: goto P_0c052fb8;
case 0x0c052fbau: goto P_0c052fba;
case 0x0c052fbcu: goto P_0c052fbc;
case 0x0c052fbeu: goto P_0c052fbe;
case 0x0c052fc0u: goto P_0c052fc0;
case 0x0c052fc2u: goto P_0c052fc2;
case 0x0c052fc4u: goto P_0c052fc4;
case 0x0c052fc6u: goto P_0c052fc6;
case 0x0c052fc8u: goto P_0c052fc8;
case 0x0c052fcau: goto P_0c052fca;
case 0x0c052fccu: goto P_0c052fcc;
case 0x0c052fceu: goto P_0c052fce;
case 0x0c052fd0u: goto P_0c052fd0;
case 0x0c052fd2u: goto P_0c052fd2;
case 0x0c052fd4u: goto P_0c052fd4;
case 0x0c052fd6u: goto P_0c052fd6;
case 0x0c052fd8u: goto P_0c052fd8;
case 0x0c052fdau: goto P_0c052fda;
case 0x0c052fdcu: goto P_0c052fdc;
case 0x0c052fdeu: goto P_0c052fde;
case 0x0c052fe0u: goto P_0c052fe0;
case 0x0c052fe2u: goto P_0c052fe2;
case 0x0c052fe4u: goto P_0c052fe4;
case 0x0c052fe6u: goto P_0c052fe6;
case 0x0c052fe8u: goto P_0c052fe8;
case 0x0c052feau: goto P_0c052fea;
case 0x0c052fecu: goto P_0c052fec;
case 0x0c052feeu: goto P_0c052fee;
case 0x0c052ff0u: goto P_0c052ff0;
case 0x0c052ff2u: goto P_0c052ff2;
case 0x0c052ff4u: goto P_0c052ff4;
case 0x0c052ff6u: goto P_0c052ff6;
case 0x0c052ff8u: goto P_0c052ff8;
case 0x0c052ffau: goto P_0c052ffa;
case 0x0c052ffcu: goto P_0c052ffc;
case 0x0c052ffeu: goto P_0c052ffe;
case 0x0c053000u: goto P_0c053000;
case 0x0c053002u: goto P_0c053002;
case 0x0c053004u: goto P_0c053004;
case 0x0c053006u: goto P_0c053006;
case 0x0c053008u: goto P_0c053008;
case 0x0c05300au: goto P_0c05300a;
case 0x0c05300cu: goto P_0c05300c;
case 0x0c05300eu: goto P_0c05300e;
case 0x0c053010u: goto P_0c053010;
case 0x0c053012u: goto P_0c053012;
case 0x0c053014u: goto P_0c053014;
case 0x0c053016u: goto P_0c053016;
case 0x0c053018u: goto P_0c053018;
case 0x0c05301au: goto P_0c05301a;
case 0x0c05301cu: goto P_0c05301c;
case 0x0c05301eu: goto P_0c05301e;
case 0x0c053020u: goto P_0c053020;
case 0x0c053022u: goto P_0c053022;
case 0x0c053024u: goto P_0c053024;
case 0x0c053026u: goto P_0c053026;
case 0x0c053028u: goto P_0c053028;
case 0x0c05302au: goto P_0c05302a;
case 0x0c05302cu: goto P_0c05302c;
case 0x0c05302eu: goto P_0c05302e;
case 0x0c053030u: goto P_0c053030;
case 0x0c053032u: goto P_0c053032;
case 0x0c053034u: goto P_0c053034;
case 0x0c053036u: goto P_0c053036;
case 0x0c053038u: goto P_0c053038;
case 0x0c05303au: goto P_0c05303a;
case 0x0c05303cu: goto P_0c05303c;
case 0x0c05303eu: goto P_0c05303e;
case 0x0c053040u: goto P_0c053040;
default: return vf3_matrix_family(target,s,ram);
}
P_0c050a20: /* original 2fe6, guest PC 0x0c050a20 */
if(!s->budget--) { s->failed_pc=0x0c050a20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a22;
P_0c050a22: /* original 6e43, guest PC 0x0c050a22 */
if(!s->budget--) { s->failed_pc=0x0c050a22u; return 0; }
r[14]=r[4];
goto P_0c050a24;
P_0c050a24: /* original 2fd6, guest PC 0x0c050a24 */
if(!s->budget--) { s->failed_pc=0x0c050a24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a26;
P_0c050a26: /* original 2fc6, guest PC 0x0c050a26 */
if(!s->budget--) { s->failed_pc=0x0c050a26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a28;
P_0c050a28: /* original 6c53, guest PC 0x0c050a28 */
if(!s->budget--) { s->failed_pc=0x0c050a28u; return 0; }
r[12]=r[5];
goto P_0c050a2a;
P_0c050a2a: /* original 2fb6, guest PC 0x0c050a2a */
if(!s->budget--) { s->failed_pc=0x0c050a2au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a2c;
P_0c050a2c: /* original 4f22, guest PC 0x0c050a2c */
if(!s->budget--) { s->failed_pc=0x0c050a2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c050a2e;
P_0c050a2e: /* original d324, guest PC 0x0c050a2e */
if(!s->budget--) { s->failed_pc=0x0c050a2eu; return 0; }
r[3]=read(ram,0x0c050ac0u,4);
goto P_0c050a30;
P_0c050a30: /* original d224, guest PC 0x0c050a30 */
if(!s->budget--) { s->failed_pc=0x0c050a30u; return 0; }
r[2]=read(ram,0x0c050ac4u,4);
goto P_0c050a32;
P_0c050a32: /* original 420b, guest PC 0x0c050a32 */
if(!s->budget--) { s->failed_pc=0x0c050a32u; return 0; }
target=r[2];
r[16]=code_base|0x0c050a36u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050a36u) { target=s->pc; goto dispatch; }
goto P_0c050a36;
P_0c050a34: /* original 2f36, guest PC 0x0c050a34 */
if(!s->budget--) { s->failed_pc=0x0c050a34u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a36;
P_0c050a36: /* original 53ee, guest PC 0x0c050a36 */
if(!s->budget--) { s->failed_pc=0x0c050a36u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c050a38;
P_0c050a38: /* original e040, guest PC 0x0c050a38 */
if(!s->budget--) { s->failed_pc=0x0c050a38u; return 0; }
r[0]=0x00000040u;
goto P_0c050a3a;
P_0c050a3a: /* original ed00, guest PC 0x0c050a3a */
if(!s->budget--) { s->failed_pc=0x0c050a3au; return 0; }
r[13]=0x00000000u;
goto P_0c050a3c;
P_0c050a3c: /* original 5bea, guest PC 0x0c050a3c */
if(!s->budget--) { s->failed_pc=0x0c050a3cu; return 0; }
r[11]=read(ram,r[14]+40,4);
goto P_0c050a3e;
P_0c050a3e: /* original 0e36, guest PC 0x0c050a3e */
if(!s->budget--) { s->failed_pc=0x0c050a3eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c050a40;
P_0c050a40: /* original 63d3, guest PC 0x0c050a40 */
if(!s->budget--) { s->failed_pc=0x0c050a40u; return 0; }
r[3]=r[13];
goto P_0c050a42;
P_0c050a42: /* original 33c2, guest PC 0x0c050a42 */
if(!s->budget--) { s->failed_pc=0x0c050a42u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[12])!=0);
goto P_0c050a44;
P_0c050a44: /* original 8d1d, guest PC 0x0c050a44 */
if(!s->budget--) { s->failed_pc=0x0c050a44u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c050a82; }
goto P_0c050a48;
P_0c050a46: /* original 7f04, guest PC 0x0c050a46 */
if(!s->budget--) { s->failed_pc=0x0c050a46u; return 0; }
r[15]+=0x00000004u;
goto P_0c050a48;
P_0c050a48: /* original e040, guest PC 0x0c050a48 */
if(!s->budget--) { s->failed_pc=0x0c050a48u; return 0; }
r[0]=0x00000040u;
goto P_0c050a4a;
P_0c050a4a: /* original d41f, guest PC 0x0c050a4a */
if(!s->budget--) { s->failed_pc=0x0c050a4au; return 0; }
r[4]=read(ram,0x0c050ac8u,4);
goto P_0c050a4c;
P_0c050a4c: /* original 03ee, guest PC 0x0c050a4c */
if(!s->budget--) { s->failed_pc=0x0c050a4cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c050a4e;
P_0c050a4e: /* original 3340, guest PC 0x0c050a4e */
if(!s->budget--) { s->failed_pc=0x0c050a4eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c050a50;
P_0c050a50: /* original 8b04, guest PC 0x0c050a50 */
if(!s->budget--) { s->failed_pc=0x0c050a50u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050a5c; }
goto P_0c050a52;
P_0c050a52: /* original 51ed, guest PC 0x0c050a52 */
if(!s->budget--) { s->failed_pc=0x0c050a52u; return 0; }
r[1]=read(ram,r[14]+52,4);
goto P_0c050a54;
P_0c050a54: /* original 2118, guest PC 0x0c050a54 */
if(!s->budget--) { s->failed_pc=0x0c050a54u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c050a56;
P_0c050a56: /* original 8b04, guest PC 0x0c050a56 */
if(!s->budget--) { s->failed_pc=0x0c050a56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050a62; }
goto P_0c050a58;
P_0c050a58: /* original a014, guest PC 0x0c050a58 */
if(!s->budget--) { s->failed_pc=0x0c050a58u; return 0; }
r[0]=0x00000000u;
goto P_0c050a84;
P_0c050a5a: /* original e000, guest PC 0x0c050a5a */
if(!s->budget--) { s->failed_pc=0x0c050a5au; return 0; }
r[0]=0x00000000u;
goto P_0c050a5c;
P_0c050a5c: /* original 53ed, guest PC 0x0c050a5c */
if(!s->budget--) { s->failed_pc=0x0c050a5cu; return 0; }
r[3]=read(ram,r[14]+52,4);
goto P_0c050a5e;
P_0c050a5e: /* original 2338, guest PC 0x0c050a5e */
if(!s->budget--) { s->failed_pc=0x0c050a5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c050a60;
P_0c050a60: /* original 8b02, guest PC 0x0c050a60 */
if(!s->budget--) { s->failed_pc=0x0c050a60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050a68; }
goto P_0c050a62;
P_0c050a62: /* original d01a, guest PC 0x0c050a62 */
if(!s->budget--) { s->failed_pc=0x0c050a62u; return 0; }
r[0]=read(ram,0x0c050accu,4);
goto P_0c050a64;
P_0c050a64: /* original a00e, guest PC 0x0c050a64 */
if(!s->budget--) { s->failed_pc=0x0c050a64u; return 0; }
goto P_0c050a84;
P_0c050a66: /* original 0009, guest PC 0x0c050a66 */
if(!s->budget--) { s->failed_pc=0x0c050a66u; return 0; }
goto P_0c050a68;
P_0c050a68: /* original 05ee, guest PC 0x0c050a68 */
if(!s->budget--) { s->failed_pc=0x0c050a68u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c050a6a;
P_0c050a6a: /* original ba18, guest PC 0x0c050a6a */
if(!s->budget--) { s->failed_pc=0x0c050a6au; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c050a6eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050a6eu) { target=s->pc; goto dispatch; }
goto P_0c050a6e;
P_0c050a6c: /* original 64b3, guest PC 0x0c050a6c */
if(!s->budget--) { s->failed_pc=0x0c050a6cu; return 0; }
r[4]=r[11];
goto P_0c050a6e;
P_0c050a6e: /* original e140, guest PC 0x0c050a6e */
if(!s->budget--) { s->failed_pc=0x0c050a6eu; return 0; }
r[1]=0x00000040u;
goto P_0c050a70;
P_0c050a70: /* original 7d01, guest PC 0x0c050a70 */
if(!s->budget--) { s->failed_pc=0x0c050a70u; return 0; }
r[13]+=0x00000001u;
goto P_0c050a72;
P_0c050a72: /* original 600d, guest PC 0x0c050a72 */
if(!s->budget--) { s->failed_pc=0x0c050a72u; return 0; }
r[0]=r[0]&65535u;
goto P_0c050a74;
P_0c050a74: /* original 3dc2, guest PC 0x0c050a74 */
if(!s->budget--) { s->failed_pc=0x0c050a74u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[12])!=0);
goto P_0c050a76;
P_0c050a76: /* original 31ec, guest PC 0x0c050a76 */
if(!s->budget--) { s->failed_pc=0x0c050a76u; return 0; }
r[1]+=r[14];
goto P_0c050a78;
P_0c050a78: /* original 2102, guest PC 0x0c050a78 */
if(!s->budget--) { s->failed_pc=0x0c050a78u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c050a7a;
P_0c050a7a: /* original 53ed, guest PC 0x0c050a7a */
if(!s->budget--) { s->failed_pc=0x0c050a7au; return 0; }
r[3]=read(ram,r[14]+52,4);
goto P_0c050a7c;
P_0c050a7c: /* original 73ff, guest PC 0x0c050a7c */
if(!s->budget--) { s->failed_pc=0x0c050a7cu; return 0; }
r[3]+=0xffffffffu;
goto P_0c050a7e;
P_0c050a7e: /* original 8fe3, guest PC 0x0c050a7e */
if(!s->budget--) { s->failed_pc=0x0c050a7eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+52,r[3],4);
if(!cond) { goto P_0c050a48; }
goto P_0c050a82;
P_0c050a80: /* original 1e3d, guest PC 0x0c050a80 */
if(!s->budget--) { s->failed_pc=0x0c050a80u; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c050a82;
P_0c050a82: /* original 50ed, guest PC 0x0c050a82 */
if(!s->budget--) { s->failed_pc=0x0c050a82u; return 0; }
r[0]=read(ram,r[14]+52,4);
goto P_0c050a84;
P_0c050a84: /* original 4f26, guest PC 0x0c050a84 */
if(!s->budget--) { s->failed_pc=0x0c050a84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c050a86;
P_0c050a86: /* original 6bf6, guest PC 0x0c050a86 */
if(!s->budget--) { s->failed_pc=0x0c050a86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c050a88;
P_0c050a88: /* original 6cf6, guest PC 0x0c050a88 */
if(!s->budget--) { s->failed_pc=0x0c050a88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c050a8a;
P_0c050a8a: /* original 6df6, guest PC 0x0c050a8a */
if(!s->budget--) { s->failed_pc=0x0c050a8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c050a8c;
P_0c050a8c: /* original 000b, guest PC 0x0c050a8c */
if(!s->budget--) { s->failed_pc=0x0c050a8cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c050a8e: /* original 6ef6, guest PC 0x0c050a8e */
if(!s->budget--) { s->failed_pc=0x0c050a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c050a90;
P_0c050a90: /* original 2fe6, guest PC 0x0c050a90 */
if(!s->budget--) { s->failed_pc=0x0c050a90u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a92;
P_0c050a92: /* original 2fd6, guest PC 0x0c050a92 */
if(!s->budget--) { s->failed_pc=0x0c050a92u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a94;
P_0c050a94: /* original 2fc6, guest PC 0x0c050a94 */
if(!s->budget--) { s->failed_pc=0x0c050a94u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a96;
P_0c050a96: /* original 2fb6, guest PC 0x0c050a96 */
if(!s->budget--) { s->failed_pc=0x0c050a96u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a98;
P_0c050a98: /* original 2fa6, guest PC 0x0c050a98 */
if(!s->budget--) { s->failed_pc=0x0c050a98u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050a9a;
P_0c050a9a: /* original 4f22, guest PC 0x0c050a9a */
if(!s->budget--) { s->failed_pc=0x0c050a9au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c050a9c;
P_0c050a9c: /* original 4f12, guest PC 0x0c050a9c */
if(!s->budget--) { s->failed_pc=0x0c050a9cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c050a9e;
P_0c050a9e: /* original 7ff0, guest PC 0x0c050a9e */
if(!s->budget--) { s->failed_pc=0x0c050a9eu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c050aa0;
P_0c050aa0: /* original 1f52, guest PC 0x0c050aa0 */
if(!s->budget--) { s->failed_pc=0x0c050aa0u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c050aa2;
P_0c050aa2: /* original 1f63, guest PC 0x0c050aa2 */
if(!s->budget--) { s->failed_pc=0x0c050aa2u; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c050aa4;
P_0c050aa4: /* original 1f71, guest PC 0x0c050aa4 */
if(!s->budget--) { s->failed_pc=0x0c050aa4u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c050aa6;
P_0c050aa6: /* original 5dfb, guest PC 0x0c050aa6 */
if(!s->budget--) { s->failed_pc=0x0c050aa6u; return 0; }
r[13]=read(ram,r[15]+44,4);
goto P_0c050aa8;
P_0c050aa8: /* original 2dd8, guest PC 0x0c050aa8 */
if(!s->budget--) { s->failed_pc=0x0c050aa8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c050aaa;
P_0c050aaa: /* original 8f16, guest PC 0x0c050aaa */
if(!s->budget--) { s->failed_pc=0x0c050aaau; return 0; }
cond=r[17]&1u;
r[11]=r[4];
if(!cond) { goto P_0c050ada; }
goto P_0c050aae;
P_0c050aac: /* original 6b43, guest PC 0x0c050aac */
if(!s->budget--) { s->failed_pc=0x0c050aacu; return 0; }
r[11]=r[4];
goto P_0c050aae;
P_0c050aae: /* original d308, guest PC 0x0c050aae */
if(!s->budget--) { s->failed_pc=0x0c050aaeu; return 0; }
r[3]=read(ram,0x0c050ad0u,4);
goto P_0c050ab0;
P_0c050ab0: /* original 55f2, guest PC 0x0c050ab0 */
if(!s->budget--) { s->failed_pc=0x0c050ab0u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c050ab2;
P_0c050ab2: /* original 430b, guest PC 0x0c050ab2 */
if(!s->budget--) { s->failed_pc=0x0c050ab2u; return 0; }
target=r[3];
r[16]=code_base|0x0c050ab6u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050ab6u) { target=s->pc; goto dispatch; }
goto P_0c050ab6;
P_0c050ab4: /* original 64b3, guest PC 0x0c050ab4 */
if(!s->budget--) { s->failed_pc=0x0c050ab4u; return 0; }
r[4]=r[11];
goto P_0c050ab6;
P_0c050ab6: /* original 6403, guest PC 0x0c050ab6 */
if(!s->budget--) { s->failed_pc=0x0c050ab6u; return 0; }
r[4]=r[0];
goto P_0c050ab8;
P_0c050ab8: /* original 4411, guest PC 0x0c050ab8 */
if(!s->budget--) { s->failed_pc=0x0c050ab8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c050aba;
P_0c050aba: /* original 890b, guest PC 0x0c050aba */
if(!s->budget--) { s->failed_pc=0x0c050abau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050ad4; }
goto P_0c050abc;
P_0c050abc: /* original a039, guest PC 0x0c050abc */
if(!s->budget--) { s->failed_pc=0x0c050abcu; return 0; }
r[0]=r[4];
goto P_0c050b32;
P_0c050abe: /* original 6043, guest PC 0x0c050abe */
if(!s->budget--) { s->failed_pc=0x0c050abeu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c050ac0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050ac0u; return 0; } return 1;
P_0c050ad4: /* original 53f1, guest PC 0x0c050ad4 */
if(!s->budget--) { s->failed_pc=0x0c050ad4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c050ad6;
P_0c050ad6: /* original 6d43, guest PC 0x0c050ad6 */
if(!s->budget--) { s->failed_pc=0x0c050ad6u; return 0; }
r[13]=r[4];
goto P_0c050ad8;
P_0c050ad8: /* original 3d38, guest PC 0x0c050ad8 */
if(!s->budget--) { s->failed_pc=0x0c050ad8u; return 0; }
r[13]-=r[3];
goto P_0c050ada;
P_0c050ada: /* original d33c, guest PC 0x0c050ada */
if(!s->budget--) { s->failed_pc=0x0c050adau; return 0; }
r[3]=read(ram,0x0c050bccu,4);
goto P_0c050adc;
P_0c050adc: /* original 66f3, guest PC 0x0c050adc */
if(!s->budget--) { s->failed_pc=0x0c050adcu; return 0; }
r[6]=r[15];
goto P_0c050ade;
P_0c050ade: /* original 55f2, guest PC 0x0c050ade */
if(!s->budget--) { s->failed_pc=0x0c050adeu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c050ae0;
P_0c050ae0: /* original 430b, guest PC 0x0c050ae0 */
if(!s->budget--) { s->failed_pc=0x0c050ae0u; return 0; }
target=r[3];
r[16]=code_base|0x0c050ae4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050ae4u) { target=s->pc; goto dispatch; }
goto P_0c050ae4;
P_0c050ae2: /* original 64b3, guest PC 0x0c050ae2 */
if(!s->budget--) { s->failed_pc=0x0c050ae2u; return 0; }
r[4]=r[11];
goto P_0c050ae4;
P_0c050ae4: /* original 6e03, guest PC 0x0c050ae4 */
if(!s->budget--) { s->failed_pc=0x0c050ae4u; return 0; }
r[14]=r[0];
goto P_0c050ae6;
P_0c050ae6: /* original 4e11, guest PC 0x0c050ae6 */
if(!s->budget--) { s->failed_pc=0x0c050ae6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c050ae8;
P_0c050ae8: /* original 8b22, guest PC 0x0c050ae8 */
if(!s->budget--) { s->failed_pc=0x0c050ae8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050b30; }
goto P_0c050aea;
P_0c050aea: /* original 946b, guest PC 0x0c050aea */
if(!s->budget--) { s->failed_pc=0x0c050aeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050bc4u,2);
goto P_0c050aec;
P_0c050aec: /* original e201, guest PC 0x0c050aec */
if(!s->budget--) { s->failed_pc=0x0c050aecu; return 0; }
r[2]=0x00000001u;
goto P_0c050aee;
P_0c050aee: /* original d338, guest PC 0x0c050aee */
if(!s->budget--) { s->failed_pc=0x0c050aeeu; return 0; }
r[3]=read(ram,0x0c050bd0u,4);
goto P_0c050af0;
P_0c050af0: /* original e600, guest PC 0x0c050af0 */
if(!s->budget--) { s->failed_pc=0x0c050af0u; return 0; }
r[6]=0x00000000u;
goto P_0c050af2;
P_0c050af2: /* original 2b4f, guest PC 0x0c050af2 */
if(!s->budget--) { s->failed_pc=0x0c050af2u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[4]);
goto P_0c050af4;
P_0c050af4: /* original 5cf3, guest PC 0x0c050af4 */
if(!s->budget--) { s->failed_pc=0x0c050af4u; return 0; }
r[12]=read(ram,r[15]+12,4);
goto P_0c050af6;
P_0c050af6: /* original 041a, guest PC 0x0c050af6 */
if(!s->budget--) { s->failed_pc=0x0c050af6u; return 0; }
r[4]=r[19];
goto P_0c050af8;
P_0c050af8: /* original 644f, guest PC 0x0c050af8 */
if(!s->budget--) { s->failed_pc=0x0c050af8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c050afa;
P_0c050afa: /* original 343c, guest PC 0x0c050afa */
if(!s->budget--) { s->failed_pc=0x0c050afau; return 0; }
r[4]+=r[3];
goto P_0c050afc;
P_0c050afc: /* original 142c, guest PC 0x0c050afc */
if(!s->budget--) { s->failed_pc=0x0c050afcu; return 0; }
write(ram,r[4]+48,r[2],4);
goto P_0c050afe;
P_0c050afe: /* original 14dd, guest PC 0x0c050afe */
if(!s->budget--) { s->failed_pc=0x0c050afeu; return 0; }
write(ram,r[4]+52,r[13],4);
goto P_0c050b00;
P_0c050b00: /* original 55f1, guest PC 0x0c050b00 */
if(!s->budget--) { s->failed_pc=0x0c050b00u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c050b02;
P_0c050b02: /* original bf8d, guest PC 0x0c050b02 */
if(!s->budget--) { s->failed_pc=0x0c050b02u; return 0; }
target=code_base|0x0c050a20u; r[16]=code_base|0x0c050b06u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050b06u) { target=s->pc; goto dispatch; }
goto P_0c050b06;
P_0c050b04: /* original 64f2, guest PC 0x0c050b04 */
if(!s->budget--) { s->failed_pc=0x0c050b04u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c050b06;
P_0c050b06: /* original eb00, guest PC 0x0c050b06 */
if(!s->budget--) { s->failed_pc=0x0c050b06u; return 0; }
r[11]=0x00000000u;
goto P_0c050b08;
P_0c050b08: /* original 63b3, guest PC 0x0c050b08 */
if(!s->budget--) { s->failed_pc=0x0c050b08u; return 0; }
r[3]=r[11];
goto P_0c050b0a;
P_0c050b0a: /* original 33d2, guest PC 0x0c050b0a */
if(!s->budget--) { s->failed_pc=0x0c050b0au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c050b0c;
P_0c050b0c: /* original 890b, guest PC 0x0c050b0c */
if(!s->budget--) { s->failed_pc=0x0c050b0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050b26; }
goto P_0c050b0e;
P_0c050b0e: /* original 9a5a, guest PC 0x0c050b0e */
if(!s->budget--) { s->failed_pc=0x0c050b0eu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050bc6u,2);
goto P_0c050b10;
P_0c050b10: /* original d330, guest PC 0x0c050b10 */
if(!s->budget--) { s->failed_pc=0x0c050b10u; return 0; }
r[3]=read(ram,0x0c050bd4u,4);
goto P_0c050b12;
P_0c050b12: /* original 65c3, guest PC 0x0c050b12 */
if(!s->budget--) { s->failed_pc=0x0c050b12u; return 0; }
r[5]=r[12];
goto P_0c050b14;
P_0c050b14: /* original 430b, guest PC 0x0c050b14 */
if(!s->budget--) { s->failed_pc=0x0c050b14u; return 0; }
target=r[3];
r[16]=code_base|0x0c050b18u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050b18u) { target=s->pc; goto dispatch; }
goto P_0c050b18;
P_0c050b16: /* original 64f2, guest PC 0x0c050b16 */
if(!s->budget--) { s->failed_pc=0x0c050b16u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c050b18;
P_0c050b18: /* original 6e03, guest PC 0x0c050b18 */
if(!s->budget--) { s->failed_pc=0x0c050b18u; return 0; }
r[14]=r[0];
goto P_0c050b1a;
P_0c050b1a: /* original 4e11, guest PC 0x0c050b1a */
if(!s->budget--) { s->failed_pc=0x0c050b1au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c050b1c;
P_0c050b1c: /* original 8b04, guest PC 0x0c050b1c */
if(!s->budget--) { s->failed_pc=0x0c050b1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050b28; }
goto P_0c050b1e;
P_0c050b1e: /* original 7b01, guest PC 0x0c050b1e */
if(!s->budget--) { s->failed_pc=0x0c050b1eu; return 0; }
r[11]+=0x00000001u;
goto P_0c050b20;
P_0c050b20: /* original 3bd2, guest PC 0x0c050b20 */
if(!s->budget--) { s->failed_pc=0x0c050b20u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[13])!=0);
goto P_0c050b22;
P_0c050b22: /* original 8ff5, guest PC 0x0c050b22 */
if(!s->budget--) { s->failed_pc=0x0c050b22u; return 0; }
cond=r[17]&1u;
r[12]+=r[10];
if(!cond) { goto P_0c050b10; }
goto P_0c050b26;
P_0c050b24: /* original 3cac, guest PC 0x0c050b24 */
if(!s->budget--) { s->failed_pc=0x0c050b24u; return 0; }
r[12]+=r[10];
goto P_0c050b26;
P_0c050b26: /* original ee00, guest PC 0x0c050b26 */
if(!s->budget--) { s->failed_pc=0x0c050b26u; return 0; }
r[14]=0x00000000u;
goto P_0c050b28;
P_0c050b28: /* original d32b, guest PC 0x0c050b28 */
if(!s->budget--) { s->failed_pc=0x0c050b28u; return 0; }
r[3]=read(ram,0x0c050bd8u,4);
goto P_0c050b2a;
P_0c050b2a: /* original e500, guest PC 0x0c050b2a */
if(!s->budget--) { s->failed_pc=0x0c050b2au; return 0; }
r[5]=0x00000000u;
goto P_0c050b2c;
P_0c050b2c: /* original 430b, guest PC 0x0c050b2c */
if(!s->budget--) { s->failed_pc=0x0c050b2cu; return 0; }
target=r[3];
r[16]=code_base|0x0c050b30u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050b30u) { target=s->pc; goto dispatch; }
goto P_0c050b30;
P_0c050b2e: /* original 64f2, guest PC 0x0c050b2e */
if(!s->budget--) { s->failed_pc=0x0c050b2eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c050b30;
P_0c050b30: /* original 60e3, guest PC 0x0c050b30 */
if(!s->budget--) { s->failed_pc=0x0c050b30u; return 0; }
r[0]=r[14];
goto P_0c050b32;
P_0c050b32: /* original 7f10, guest PC 0x0c050b32 */
if(!s->budget--) { s->failed_pc=0x0c050b32u; return 0; }
r[15]+=0x00000010u;
goto P_0c050b34;
P_0c050b34: /* original 4f16, guest PC 0x0c050b34 */
if(!s->budget--) { s->failed_pc=0x0c050b34u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c050b36;
P_0c050b36: /* original 4f26, guest PC 0x0c050b36 */
if(!s->budget--) { s->failed_pc=0x0c050b36u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c050b38;
P_0c050b38: /* original 6af6, guest PC 0x0c050b38 */
if(!s->budget--) { s->failed_pc=0x0c050b38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c050b3a;
P_0c050b3a: /* original 6bf6, guest PC 0x0c050b3a */
if(!s->budget--) { s->failed_pc=0x0c050b3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c050b3c;
P_0c050b3c: /* original 6cf6, guest PC 0x0c050b3c */
if(!s->budget--) { s->failed_pc=0x0c050b3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c050b3e;
P_0c050b3e: /* original 6df6, guest PC 0x0c050b3e */
if(!s->budget--) { s->failed_pc=0x0c050b3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c050b40;
P_0c050b40: /* original 000b, guest PC 0x0c050b40 */
if(!s->budget--) { s->failed_pc=0x0c050b40u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c050b42: /* original 6ef6, guest PC 0x0c050b42 */
if(!s->budget--) { s->failed_pc=0x0c050b42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c050b44u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050b44u; return 0; } return 1;
P_0c052f24: /* original 2fe6, guest PC 0x0c052f24 */
if(!s->budget--) { s->failed_pc=0x0c052f24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c052f26;
P_0c052f26: /* original e301, guest PC 0x0c052f26 */
if(!s->budget--) { s->failed_pc=0x0c052f26u; return 0; }
r[3]=0x00000001u;
goto P_0c052f28;
P_0c052f28: /* original 2fd6, guest PC 0x0c052f28 */
if(!s->budget--) { s->failed_pc=0x0c052f28u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c052f2a;
P_0c052f2a: /* original e200, guest PC 0x0c052f2a */
if(!s->budget--) { s->failed_pc=0x0c052f2au; return 0; }
r[2]=0x00000000u;
goto P_0c052f2c;
P_0c052f2c: /* original 2fc6, guest PC 0x0c052f2c */
if(!s->budget--) { s->failed_pc=0x0c052f2cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c052f2e;
P_0c052f2e: /* original 2fb6, guest PC 0x0c052f2e */
if(!s->budget--) { s->failed_pc=0x0c052f2eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c052f30;
P_0c052f30: /* original 2fa6, guest PC 0x0c052f30 */
if(!s->budget--) { s->failed_pc=0x0c052f30u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c052f32;
P_0c052f32: /* original 2f96, guest PC 0x0c052f32 */
if(!s->budget--) { s->failed_pc=0x0c052f32u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c052f34;
P_0c052f34: /* original 2f86, guest PC 0x0c052f34 */
if(!s->budget--) { s->failed_pc=0x0c052f34u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c052f36;
P_0c052f36: /* original 4f22, guest PC 0x0c052f36 */
if(!s->budget--) { s->failed_pc=0x0c052f36u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c052f38;
P_0c052f38: /* original 7fd4, guest PC 0x0c052f38 */
if(!s->budget--) { s->failed_pc=0x0c052f38u; return 0; }
r[15]+=0xffffffd4u;
goto P_0c052f3a;
P_0c052f3a: /* original 69f3, guest PC 0x0c052f3a */
if(!s->budget--) { s->failed_pc=0x0c052f3au; return 0; }
r[9]=r[15];
goto P_0c052f3c;
P_0c052f3c: /* original 1f53, guest PC 0x0c052f3c */
if(!s->budget--) { s->failed_pc=0x0c052f3cu; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c052f3e;
P_0c052f3e: /* original 7924, guest PC 0x0c052f3e */
if(!s->budget--) { s->failed_pc=0x0c052f3eu; return 0; }
r[9]+=0x00000024u;
goto P_0c052f40;
P_0c052f40: /* original 2f62, guest PC 0x0c052f40 */
if(!s->budget--) { s->failed_pc=0x0c052f40u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c052f42;
P_0c052f42: /* original 6543, guest PC 0x0c052f42 */
if(!s->budget--) { s->failed_pc=0x0c052f42u; return 0; }
r[5]=r[4];
goto P_0c052f44;
P_0c052f44: /* original 1f36, guest PC 0x0c052f44 */
if(!s->budget--) { s->failed_pc=0x0c052f44u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c052f46;
P_0c052f46: /* original e608, guest PC 0x0c052f46 */
if(!s->budget--) { s->failed_pc=0x0c052f46u; return 0; }
r[6]=0x00000008u;
goto P_0c052f48;
P_0c052f48: /* original 53f3, guest PC 0x0c052f48 */
if(!s->budget--) { s->failed_pc=0x0c052f48u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c052f4a;
P_0c052f4a: /* original 6bf2, guest PC 0x0c052f4a */
if(!s->budget--) { s->failed_pc=0x0c052f4au; return 0; }
tmp=read(ram,r[15],4);
r[11]=tmp;
goto P_0c052f4c;
P_0c052f4c: /* original 3b3c, guest PC 0x0c052f4c */
if(!s->budget--) { s->failed_pc=0x0c052f4cu; return 0; }
r[11]+=r[3];
goto P_0c052f4e;
P_0c052f4e: /* original 2b20, guest PC 0x0c052f4e */
if(!s->budget--) { s->failed_pc=0x0c052f4eu; return 0; }
write(ram,r[11],r[2],1);
goto P_0c052f50;
P_0c052f50: /* original d33c, guest PC 0x0c052f50 */
if(!s->budget--) { s->failed_pc=0x0c052f50u; return 0; }
r[3]=read(ram,0x0c053044u,4);
goto P_0c052f52;
P_0c052f52: /* original 430b, guest PC 0x0c052f52 */
if(!s->budget--) { s->failed_pc=0x0c052f52u; return 0; }
target=r[3];
r[16]=code_base|0x0c052f56u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c052f56u) { target=s->pc; goto dispatch; }
goto P_0c052f56;
P_0c052f54: /* original 6493, guest PC 0x0c052f54 */
if(!s->budget--) { s->failed_pc=0x0c052f54u; return 0; }
r[4]=r[9];
goto P_0c052f56;
P_0c052f56: /* original e808, guest PC 0x0c052f56 */
if(!s->budget--) { s->failed_pc=0x0c052f56u; return 0; }
r[8]=0x00000008u;
goto P_0c052f58;
P_0c052f58: /* original 62f2, guest PC 0x0c052f58 */
if(!s->budget--) { s->failed_pc=0x0c052f58u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c052f5a;
P_0c052f5a: /* original 6cf3, guest PC 0x0c052f5a */
if(!s->budget--) { s->failed_pc=0x0c052f5au; return 0; }
r[12]=r[15];
goto P_0c052f5c;
P_0c052f5c: /* original d33a, guest PC 0x0c052f5c */
if(!s->budget--) { s->failed_pc=0x0c052f5cu; return 0; }
r[3]=read(ram,0x0c053048u,4);
goto P_0c052f5e;
P_0c052f5e: /* original 72ff, guest PC 0x0c052f5e */
if(!s->budget--) { s->failed_pc=0x0c052f5eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c052f60;
P_0c052f60: /* original 1f21, guest PC 0x0c052f60 */
if(!s->budget--) { s->failed_pc=0x0c052f60u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c052f62;
P_0c052f62: /* original 7c1c, guest PC 0x0c052f62 */
if(!s->budget--) { s->failed_pc=0x0c052f62u; return 0; }
r[12]+=0x0000001cu;
goto P_0c052f64;
P_0c052f64: /* original 4208, guest PC 0x0c052f64 */
if(!s->budget--) { s->failed_pc=0x0c052f64u; return 0; }
r[2]<<=2;
goto P_0c052f66;
P_0c052f66: /* original 4200, guest PC 0x0c052f66 */
if(!s->budget--) { s->failed_pc=0x0c052f66u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c052f68;
P_0c052f68: /* original 323c, guest PC 0x0c052f68 */
if(!s->budget--) { s->failed_pc=0x0c052f68u; return 0; }
r[2]+=r[3];
goto P_0c052f6a;
P_0c052f6a: /* original 1f25, guest PC 0x0c052f6a */
if(!s->budget--) { s->failed_pc=0x0c052f6au; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c052f6c;
P_0c052f6c: /* original 53f1, guest PC 0x0c052f6c */
if(!s->budget--) { s->failed_pc=0x0c052f6cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c052f6e;
P_0c052f6e: /* original 7301, guest PC 0x0c052f6e */
if(!s->budget--) { s->failed_pc=0x0c052f6eu; return 0; }
r[3]+=0x00000001u;
goto P_0c052f70;
P_0c052f70: /* original a059, guest PC 0x0c052f70 */
if(!s->budget--) { s->failed_pc=0x0c052f70u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c053026;
P_0c052f72: /* original 1f34, guest PC 0x0c052f72 */
if(!s->budget--) { s->failed_pc=0x0c052f72u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c052f74;
P_0c052f74: /* original 51f4, guest PC 0x0c052f74 */
if(!s->budget--) { s->failed_pc=0x0c052f74u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c052f76;
P_0c052f76: /* original d335, guest PC 0x0c052f76 */
if(!s->budget--) { s->failed_pc=0x0c052f76u; return 0; }
r[3]=read(ram,0x0c05304cu,4);
goto P_0c052f78;
P_0c052f78: /* original 430b, guest PC 0x0c052f78 */
if(!s->budget--) { s->failed_pc=0x0c052f78u; return 0; }
target=r[3];
r[16]=code_base|0x0c052f7cu;
r[0]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c052f7cu) { target=s->pc; goto dispatch; }
goto P_0c052f7c;
P_0c052f7a: /* original e005, guest PC 0x0c052f7a */
if(!s->budget--) { s->failed_pc=0x0c052f7au; return 0; }
r[0]=0x00000005u;
goto P_0c052f7c;
P_0c052f7c: /* original 55f5, guest PC 0x0c052f7c */
if(!s->budget--) { s->failed_pc=0x0c052f7cu; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c052f7e;
P_0c052f7e: /* original 7001, guest PC 0x0c052f7e */
if(!s->budget--) { s->failed_pc=0x0c052f7eu; return 0; }
r[0]+=0x00000001u;
goto P_0c052f80;
P_0c052f80: /* original d330, guest PC 0x0c052f80 */
if(!s->budget--) { s->failed_pc=0x0c052f80u; return 0; }
r[3]=read(ram,0x0c053044u,4);
goto P_0c052f82;
P_0c052f82: /* original 6e83, guest PC 0x0c052f82 */
if(!s->budget--) { s->failed_pc=0x0c052f82u; return 0; }
r[14]=r[8];
goto P_0c052f84;
P_0c052f84: /* original 4000, guest PC 0x0c052f84 */
if(!s->budget--) { s->failed_pc=0x0c052f84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c052f86;
P_0c052f86: /* original 3e08, guest PC 0x0c052f86 */
if(!s->budget--) { s->failed_pc=0x0c052f86u; return 0; }
r[14]-=r[0];
goto P_0c052f88;
P_0c052f88: /* original 6d83, guest PC 0x0c052f88 */
if(!s->budget--) { s->failed_pc=0x0c052f88u; return 0; }
r[13]=r[8];
goto P_0c052f8a;
P_0c052f8a: /* original 3de8, guest PC 0x0c052f8a */
if(!s->budget--) { s->failed_pc=0x0c052f8au; return 0; }
r[13]-=r[14];
goto P_0c052f8c;
P_0c052f8c: /* original 66d3, guest PC 0x0c052f8c */
if(!s->budget--) { s->failed_pc=0x0c052f8cu; return 0; }
r[6]=r[13];
goto P_0c052f8e;
P_0c052f8e: /* original 35ec, guest PC 0x0c052f8e */
if(!s->budget--) { s->failed_pc=0x0c052f8eu; return 0; }
r[5]+=r[14];
goto P_0c052f90;
P_0c052f90: /* original 64e3, guest PC 0x0c052f90 */
if(!s->budget--) { s->failed_pc=0x0c052f90u; return 0; }
r[4]=r[14];
goto P_0c052f92;
P_0c052f92: /* original 430b, guest PC 0x0c052f92 */
if(!s->budget--) { s->failed_pc=0x0c052f92u; return 0; }
target=r[3];
r[16]=code_base|0x0c052f96u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c052f96u) { target=s->pc; goto dispatch; }
goto P_0c052f96;
P_0c052f94: /* original 34cc, guest PC 0x0c052f94 */
if(!s->budget--) { s->failed_pc=0x0c052f94u; return 0; }
r[4]+=r[12];
goto P_0c052f96;
P_0c052f96: /* original ea08, guest PC 0x0c052f96 */
if(!s->budget--) { s->failed_pc=0x0c052f96u; return 0; }
r[10]=0x00000008u;
goto P_0c052f98;
P_0c052f98: /* original e200, guest PC 0x0c052f98 */
if(!s->budget--) { s->failed_pc=0x0c052f98u; return 0; }
r[2]=0x00000000u;
goto P_0c052f9a;
P_0c052f9a: /* original 6323, guest PC 0x0c052f9a */
if(!s->budget--) { s->failed_pc=0x0c052f9au; return 0; }
r[3]=r[2];
goto P_0c052f9c;
P_0c052f9c: /* original 1f22, guest PC 0x0c052f9c */
if(!s->budget--) { s->failed_pc=0x0c052f9cu; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c052f9e;
P_0c052f9e: /* original 2f32, guest PC 0x0c052f9e */
if(!s->budget--) { s->failed_pc=0x0c052f9eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c052fa0;
P_0c052fa0: /* original d32b, guest PC 0x0c052fa0 */
if(!s->budget--) { s->failed_pc=0x0c052fa0u; return 0; }
r[3]=read(ram,0x0c053050u,4);
goto P_0c052fa2;
P_0c052fa2: /* original 66d3, guest PC 0x0c052fa2 */
if(!s->budget--) { s->failed_pc=0x0c052fa2u; return 0; }
r[6]=r[13];
goto P_0c052fa4;
P_0c052fa4: /* original 65e3, guest PC 0x0c052fa4 */
if(!s->budget--) { s->failed_pc=0x0c052fa4u; return 0; }
r[5]=r[14];
goto P_0c052fa6;
P_0c052fa6: /* original 35cc, guest PC 0x0c052fa6 */
if(!s->budget--) { s->failed_pc=0x0c052fa6u; return 0; }
r[5]+=r[12];
goto P_0c052fa8;
P_0c052fa8: /* original 64e3, guest PC 0x0c052fa8 */
if(!s->budget--) { s->failed_pc=0x0c052fa8u; return 0; }
r[4]=r[14];
goto P_0c052faa;
P_0c052faa: /* original 430b, guest PC 0x0c052faa */
if(!s->budget--) { s->failed_pc=0x0c052faau; return 0; }
target=r[3];
r[16]=code_base|0x0c052faeu;
r[4]+=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c052faeu) { target=s->pc; goto dispatch; }
goto P_0c052fae;
P_0c052fac: /* original 349c, guest PC 0x0c052fac */
if(!s->budget--) { s->failed_pc=0x0c052facu; return 0; }
r[4]+=r[9];
goto P_0c052fae;
P_0c052fae: /* original 4011, guest PC 0x0c052fae */
if(!s->budget--) { s->failed_pc=0x0c052faeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c052fb0;
P_0c052fb0: /* original 8f0c, guest PC 0x0c052fb0 */
if(!s->budget--) { s->failed_pc=0x0c052fb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c052fcc; }
goto P_0c052fb4;
P_0c052fb2: /* original 0009, guest PC 0x0c052fb2 */
if(!s->budget--) { s->failed_pc=0x0c052fb2u; return 0; }
goto P_0c052fb4;
P_0c052fb4: /* original d327, guest PC 0x0c052fb4 */
if(!s->budget--) { s->failed_pc=0x0c052fb4u; return 0; }
r[3]=read(ram,0x0c053054u,4);
goto P_0c052fb6;
P_0c052fb6: /* original 67d3, guest PC 0x0c052fb6 */
if(!s->budget--) { s->failed_pc=0x0c052fb6u; return 0; }
r[7]=r[13];
goto P_0c052fb8;
P_0c052fb8: /* original 66e3, guest PC 0x0c052fb8 */
if(!s->budget--) { s->failed_pc=0x0c052fb8u; return 0; }
r[6]=r[14];
goto P_0c052fba;
P_0c052fba: /* original 36cc, guest PC 0x0c052fba */
if(!s->budget--) { s->failed_pc=0x0c052fbau; return 0; }
r[6]+=r[12];
goto P_0c052fbc;
P_0c052fbc: /* original 65e3, guest PC 0x0c052fbc */
if(!s->budget--) { s->failed_pc=0x0c052fbcu; return 0; }
r[5]=r[14];
goto P_0c052fbe;
P_0c052fbe: /* original 359c, guest PC 0x0c052fbe */
if(!s->budget--) { s->failed_pc=0x0c052fbeu; return 0; }
r[5]+=r[9];
goto P_0c052fc0;
P_0c052fc0: /* original 430b, guest PC 0x0c052fc0 */
if(!s->budget--) { s->failed_pc=0x0c052fc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c052fc4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c052fc4u) { target=s->pc; goto dispatch; }
goto P_0c052fc4;
P_0c052fc2: /* original e400, guest PC 0x0c052fc2 */
if(!s->budget--) { s->failed_pc=0x0c052fc2u; return 0; }
r[4]=0x00000000u;
goto P_0c052fc4;
P_0c052fc4: /* original 1f06, guest PC 0x0c052fc4 */
if(!s->budget--) { s->failed_pc=0x0c052fc4u; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c052fc6;
P_0c052fc6: /* original 53f2, guest PC 0x0c052fc6 */
if(!s->budget--) { s->failed_pc=0x0c052fc6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c052fc8;
P_0c052fc8: /* original 33ac, guest PC 0x0c052fc8 */
if(!s->budget--) { s->failed_pc=0x0c052fc8u; return 0; }
r[3]+=r[10];
goto P_0c052fca;
P_0c052fca: /* original 1f32, guest PC 0x0c052fca */
if(!s->budget--) { s->failed_pc=0x0c052fcau; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c052fcc;
P_0c052fcc: /* original e300, guest PC 0x0c052fcc */
if(!s->budget--) { s->failed_pc=0x0c052fccu; return 0; }
r[3]=0x00000000u;
goto P_0c052fce;
P_0c052fce: /* original 33a7, guest PC 0x0c052fce */
if(!s->budget--) { s->failed_pc=0x0c052fceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[10])!=0);
goto P_0c052fd0;
P_0c052fd0: /* original 3a3e, guest PC 0x0c052fd0 */
if(!s->budget--) { s->failed_pc=0x0c052fd0u; return 0; }
wide=(uint64_t)r[10]+r[3]+(r[17]&1u); r[10]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c052fd2;
P_0c052fd2: /* original 4a21, guest PC 0x0c052fd2 */
if(!s->budget--) { s->failed_pc=0x0c052fd2u; return 0; }
r[17]=(r[17]&~1u)|((r[10]&1)!=0);
r[10]=(uint32_t)((int32_t)r[10]>>1);
goto P_0c052fd4;
P_0c052fd4: /* original 2aa8, guest PC 0x0c052fd4 */
if(!s->budget--) { s->failed_pc=0x0c052fd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c052fd6;
P_0c052fd6: /* original 8d0c, guest PC 0x0c052fd6 */
if(!s->budget--) { s->failed_pc=0x0c052fd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c052ff2; }
goto P_0c052fda;
P_0c052fd8: /* original 0009, guest PC 0x0c052fd8 */
if(!s->budget--) { s->failed_pc=0x0c052fd8u; return 0; }
goto P_0c052fda;
P_0c052fda: /* original e601, guest PC 0x0c052fda */
if(!s->budget--) { s->failed_pc=0x0c052fdau; return 0; }
r[6]=0x00000001u;
goto P_0c052fdc;
P_0c052fdc: /* original d31e, guest PC 0x0c052fdc */
if(!s->budget--) { s->failed_pc=0x0c052fdcu; return 0; }
r[3]=read(ram,0x0c053058u,4);
goto P_0c052fde;
P_0c052fde: /* original 65d3, guest PC 0x0c052fde */
if(!s->budget--) { s->failed_pc=0x0c052fdeu; return 0; }
r[5]=r[13];
goto P_0c052fe0;
P_0c052fe0: /* original 64e3, guest PC 0x0c052fe0 */
if(!s->budget--) { s->failed_pc=0x0c052fe0u; return 0; }
r[4]=r[14];
goto P_0c052fe2;
P_0c052fe2: /* original 430b, guest PC 0x0c052fe2 */
if(!s->budget--) { s->failed_pc=0x0c052fe2u; return 0; }
target=r[3];
r[16]=code_base|0x0c052fe6u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c052fe6u) { target=s->pc; goto dispatch; }
goto P_0c052fe6;
P_0c052fe4: /* original 34cc, guest PC 0x0c052fe4 */
if(!s->budget--) { s->failed_pc=0x0c052fe4u; return 0; }
r[4]+=r[12];
goto P_0c052fe6;
P_0c052fe6: /* original e304, guest PC 0x0c052fe6 */
if(!s->budget--) { s->failed_pc=0x0c052fe6u; return 0; }
r[3]=0x00000004u;
goto P_0c052fe8;
P_0c052fe8: /* original 62f2, guest PC 0x0c052fe8 */
if(!s->budget--) { s->failed_pc=0x0c052fe8u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c052fea;
P_0c052fea: /* original 7201, guest PC 0x0c052fea */
if(!s->budget--) { s->failed_pc=0x0c052feau; return 0; }
r[2]+=0x00000001u;
goto P_0c052fec;
P_0c052fec: /* original 3233, guest PC 0x0c052fec */
if(!s->budget--) { s->failed_pc=0x0c052fecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c052fee;
P_0c052fee: /* original 8fd7, guest PC 0x0c052fee */
if(!s->budget--) { s->failed_pc=0x0c052feeu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(!cond) { goto P_0c052fa0; }
goto P_0c052ff2;
P_0c052ff0: /* original 2f22, guest PC 0x0c052ff0 */
if(!s->budget--) { s->failed_pc=0x0c052ff0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c052ff2;
P_0c052ff2: /* original 54f2, guest PC 0x0c052ff2 */
if(!s->budget--) { s->failed_pc=0x0c052ff2u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c052ff4;
P_0c052ff4: /* original 53f6, guest PC 0x0c052ff4 */
if(!s->budget--) { s->failed_pc=0x0c052ff4u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c052ff6;
P_0c052ff6: /* original 2338, guest PC 0x0c052ff6 */
if(!s->budget--) { s->failed_pc=0x0c052ff6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c052ff8;
P_0c052ff8: /* original 8f0b, guest PC 0x0c052ff8 */
if(!s->budget--) { s->failed_pc=0x0c052ff8u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000030u;
if(!cond) { goto P_0c053012; }
goto P_0c052ffc;
P_0c052ffa: /* original 7430, guest PC 0x0c052ffa */
if(!s->budget--) { s->failed_pc=0x0c052ffau; return 0; }
r[4]+=0x00000030u;
goto P_0c052ffc;
P_0c052ffc: /* original a002, guest PC 0x0c052ffc */
if(!s->budget--) { s->failed_pc=0x0c052ffcu; return 0; }
tmp=r[4]; r[11]-=1; write(ram,r[11],tmp,1);
goto P_0c053004;
P_0c052ffe: /* original 2b44, guest PC 0x0c052ffe */
if(!s->budget--) { s->failed_pc=0x0c052ffeu; return 0; }
tmp=r[4]; r[11]-=1; write(ram,r[11],tmp,1);
goto P_0c053000;
P_0c053000: /* original e230, guest PC 0x0c053000 */
if(!s->budget--) { s->failed_pc=0x0c053000u; return 0; }
r[2]=0x00000030u;
goto P_0c053002;
P_0c053002: /* original 2b20, guest PC 0x0c053002 */
if(!s->budget--) { s->failed_pc=0x0c053002u; return 0; }
write(ram,r[11],r[2],1);
goto P_0c053004;
P_0c053004: /* original 53f3, guest PC 0x0c053004 */
if(!s->budget--) { s->failed_pc=0x0c053004u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c053006;
P_0c053006: /* original 7bff, guest PC 0x0c053006 */
if(!s->budget--) { s->failed_pc=0x0c053006u; return 0; }
r[11]+=0xffffffffu;
goto P_0c053008;
P_0c053008: /* original 3b32, guest PC 0x0c053008 */
if(!s->budget--) { s->failed_pc=0x0c053008u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[3])!=0);
goto P_0c05300a;
P_0c05300a: /* original 8df9, guest PC 0x0c05300a */
if(!s->budget--) { s->failed_pc=0x0c05300au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053000; }
goto P_0c05300e;
P_0c05300c: /* original 0009, guest PC 0x0c05300c */
if(!s->budget--) { s->failed_pc=0x0c05300cu; return 0; }
goto P_0c05300e;
P_0c05300e: /* original a00e, guest PC 0x0c05300e */
if(!s->budget--) { s->failed_pc=0x0c05300eu; return 0; }
goto P_0c05302e;
P_0c053010: /* original 0009, guest PC 0x0c053010 */
if(!s->budget--) { s->failed_pc=0x0c053010u; return 0; }
goto P_0c053012;
P_0c053012: /* original 2b44, guest PC 0x0c053012 */
if(!s->budget--) { s->failed_pc=0x0c053012u; return 0; }
tmp=r[4]; r[11]-=1; write(ram,r[11],tmp,1);
goto P_0c053014;
P_0c053014: /* original 53f1, guest PC 0x0c053014 */
if(!s->budget--) { s->failed_pc=0x0c053014u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053016;
P_0c053016: /* original 73ff, guest PC 0x0c053016 */
if(!s->budget--) { s->failed_pc=0x0c053016u; return 0; }
r[3]+=0xffffffffu;
goto P_0c053018;
P_0c053018: /* original 1f31, guest PC 0x0c053018 */
if(!s->budget--) { s->failed_pc=0x0c053018u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c05301a;
P_0c05301a: /* original 52f5, guest PC 0x0c05301a */
if(!s->budget--) { s->failed_pc=0x0c05301au; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c05301c;
P_0c05301c: /* original 72f8, guest PC 0x0c05301c */
if(!s->budget--) { s->failed_pc=0x0c05301cu; return 0; }
r[2]+=0xfffffff8u;
goto P_0c05301e;
P_0c05301e: /* original 1f25, guest PC 0x0c05301e */
if(!s->budget--) { s->failed_pc=0x0c05301eu; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c053020;
P_0c053020: /* original 51f4, guest PC 0x0c053020 */
if(!s->budget--) { s->failed_pc=0x0c053020u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c053022;
P_0c053022: /* original 71ff, guest PC 0x0c053022 */
if(!s->budget--) { s->failed_pc=0x0c053022u; return 0; }
r[1]+=0xffffffffu;
goto P_0c053024;
P_0c053024: /* original 1f14, guest PC 0x0c053024 */
if(!s->budget--) { s->failed_pc=0x0c053024u; return 0; }
write(ram,r[15]+16,r[1],4);
goto P_0c053026;
P_0c053026: /* original 53f1, guest PC 0x0c053026 */
if(!s->budget--) { s->failed_pc=0x0c053026u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053028;
P_0c053028: /* original 4311, guest PC 0x0c053028 */
if(!s->budget--) { s->failed_pc=0x0c053028u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c05302a;
P_0c05302a: /* original 8da3, guest PC 0x0c05302a */
if(!s->budget--) { s->failed_pc=0x0c05302au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c052f74; }
goto P_0c05302e;
P_0c05302c: /* original 0009, guest PC 0x0c05302c */
if(!s->budget--) { s->failed_pc=0x0c05302cu; return 0; }
goto P_0c05302e;
P_0c05302e: /* original 7f2c, guest PC 0x0c05302e */
if(!s->budget--) { s->failed_pc=0x0c05302eu; return 0; }
r[15]+=0x0000002cu;
goto P_0c053030;
P_0c053030: /* original 4f26, guest PC 0x0c053030 */
if(!s->budget--) { s->failed_pc=0x0c053030u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053032;
P_0c053032: /* original 68f6, guest PC 0x0c053032 */
if(!s->budget--) { s->failed_pc=0x0c053032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c053034;
P_0c053034: /* original 69f6, guest PC 0x0c053034 */
if(!s->budget--) { s->failed_pc=0x0c053034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c053036;
P_0c053036: /* original 6af6, guest PC 0x0c053036 */
if(!s->budget--) { s->failed_pc=0x0c053036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c053038;
P_0c053038: /* original 6bf6, guest PC 0x0c053038 */
if(!s->budget--) { s->failed_pc=0x0c053038u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05303a;
P_0c05303a: /* original 6cf6, guest PC 0x0c05303a */
if(!s->budget--) { s->failed_pc=0x0c05303au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05303c;
P_0c05303c: /* original 6df6, guest PC 0x0c05303c */
if(!s->budget--) { s->failed_pc=0x0c05303cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05303e;
P_0c05303e: /* original 000b, guest PC 0x0c05303e */
if(!s->budget--) { s->failed_pc=0x0c05303eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053040: /* original 6ef6, guest PC 0x0c053040 */
if(!s->budget--) { s->failed_pc=0x0c053040u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c053042u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c053042u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
