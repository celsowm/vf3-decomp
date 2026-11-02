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
int vf3_away_batch51_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08497cu: goto P_0c08497c;
case 0x0c08497eu: goto P_0c08497e;
case 0x0c084980u: goto P_0c084980;
case 0x0c084982u: goto P_0c084982;
case 0x0c084984u: goto P_0c084984;
case 0x0c084986u: goto P_0c084986;
case 0x0c084988u: goto P_0c084988;
case 0x0c08498au: goto P_0c08498a;
case 0x0c08498cu: goto P_0c08498c;
case 0x0c08498eu: goto P_0c08498e;
case 0x0c084990u: goto P_0c084990;
case 0x0c084992u: goto P_0c084992;
case 0x0c084994u: goto P_0c084994;
case 0x0c084996u: goto P_0c084996;
case 0x0c084998u: goto P_0c084998;
case 0x0c08499au: goto P_0c08499a;
case 0x0c08499cu: goto P_0c08499c;
case 0x0c08499eu: goto P_0c08499e;
case 0x0c0849a0u: goto P_0c0849a0;
case 0x0c0849a2u: goto P_0c0849a2;
case 0x0c0849a4u: goto P_0c0849a4;
case 0x0c0849a6u: goto P_0c0849a6;
case 0x0c0849a8u: goto P_0c0849a8;
case 0x0c0849aau: goto P_0c0849aa;
case 0x0c0849acu: goto P_0c0849ac;
case 0x0c0849aeu: goto P_0c0849ae;
case 0x0c0849b0u: goto P_0c0849b0;
case 0x0c0849b2u: goto P_0c0849b2;
case 0x0c0849b4u: goto P_0c0849b4;
case 0x0c0849b6u: goto P_0c0849b6;
case 0x0c0849b8u: goto P_0c0849b8;
case 0x0c0849bau: goto P_0c0849ba;
case 0x0c0849bcu: goto P_0c0849bc;
case 0x0c0849beu: goto P_0c0849be;
case 0x0c0849c0u: goto P_0c0849c0;
case 0x0c0849c2u: goto P_0c0849c2;
case 0x0c0849c4u: goto P_0c0849c4;
case 0x0c0849c6u: goto P_0c0849c6;
case 0x0c0849c8u: goto P_0c0849c8;
case 0x0c0849cau: goto P_0c0849ca;
case 0x0c0849ccu: goto P_0c0849cc;
case 0x0c0849ceu: goto P_0c0849ce;
case 0x0c0849d0u: goto P_0c0849d0;
case 0x0c0849d2u: goto P_0c0849d2;
case 0x0c0849d4u: goto P_0c0849d4;
case 0x0c0849d6u: goto P_0c0849d6;
case 0x0c0849d8u: goto P_0c0849d8;
case 0x0c0849dau: goto P_0c0849da;
case 0x0c0849dcu: goto P_0c0849dc;
case 0x0c0849deu: goto P_0c0849de;
case 0x0c0849e0u: goto P_0c0849e0;
case 0x0c0849e2u: goto P_0c0849e2;
case 0x0c0849e4u: goto P_0c0849e4;
case 0x0c0849e6u: goto P_0c0849e6;
case 0x0c0849e8u: goto P_0c0849e8;
case 0x0c0849eau: goto P_0c0849ea;
case 0x0c0849ecu: goto P_0c0849ec;
case 0x0c0849eeu: goto P_0c0849ee;
case 0x0c0849f0u: goto P_0c0849f0;
case 0x0c0849f2u: goto P_0c0849f2;
case 0x0c0849f4u: goto P_0c0849f4;
case 0x0c0849f6u: goto P_0c0849f6;
case 0x0c0849f8u: goto P_0c0849f8;
case 0x0c0849fau: goto P_0c0849fa;
case 0x0c0849fcu: goto P_0c0849fc;
case 0x0c0849feu: goto P_0c0849fe;
case 0x0c084a00u: goto P_0c084a00;
case 0x0c084a02u: goto P_0c084a02;
case 0x0c084a04u: goto P_0c084a04;
case 0x0c084a06u: goto P_0c084a06;
case 0x0c084a08u: goto P_0c084a08;
case 0x0c084a0au: goto P_0c084a0a;
case 0x0c084a0cu: goto P_0c084a0c;
case 0x0c084a0eu: goto P_0c084a0e;
case 0x0c084a10u: goto P_0c084a10;
case 0x0c084a12u: goto P_0c084a12;
case 0x0c084a14u: goto P_0c084a14;
case 0x0c084a16u: goto P_0c084a16;
case 0x0c084a18u: goto P_0c084a18;
case 0x0c084a1au: goto P_0c084a1a;
case 0x0c084a1cu: goto P_0c084a1c;
case 0x0c084a1eu: goto P_0c084a1e;
case 0x0c084a20u: goto P_0c084a20;
case 0x0c084a22u: goto P_0c084a22;
case 0x0c084a24u: goto P_0c084a24;
case 0x0c084a26u: goto P_0c084a26;
case 0x0c084a28u: goto P_0c084a28;
case 0x0c084a2au: goto P_0c084a2a;
case 0x0c084a2cu: goto P_0c084a2c;
case 0x0c084a2eu: goto P_0c084a2e;
case 0x0c084a30u: goto P_0c084a30;
case 0x0c084a32u: goto P_0c084a32;
case 0x0c084a34u: goto P_0c084a34;
case 0x0c084a36u: goto P_0c084a36;
case 0x0c084a38u: goto P_0c084a38;
case 0x0c084a3au: goto P_0c084a3a;
case 0x0c084a3cu: goto P_0c084a3c;
case 0x0c084a3eu: goto P_0c084a3e;
case 0x0c084a40u: goto P_0c084a40;
case 0x0c084a42u: goto P_0c084a42;
case 0x0c084a44u: goto P_0c084a44;
case 0x0c084a46u: goto P_0c084a46;
case 0x0c084a48u: goto P_0c084a48;
case 0x0c084a4au: goto P_0c084a4a;
case 0x0c084a4cu: goto P_0c084a4c;
case 0x0c084a4eu: goto P_0c084a4e;
case 0x0c084a50u: goto P_0c084a50;
case 0x0c084a52u: goto P_0c084a52;
case 0x0c084a54u: goto P_0c084a54;
case 0x0c084a56u: goto P_0c084a56;
case 0x0c084a58u: goto P_0c084a58;
case 0x0c084a5au: goto P_0c084a5a;
case 0x0c084a5cu: goto P_0c084a5c;
case 0x0c084a5eu: goto P_0c084a5e;
case 0x0c084a60u: goto P_0c084a60;
case 0x0c084a62u: goto P_0c084a62;
case 0x0c084a64u: goto P_0c084a64;
case 0x0c084a66u: goto P_0c084a66;
case 0x0c084a68u: goto P_0c084a68;
case 0x0c084a6au: goto P_0c084a6a;
case 0x0c084a6cu: goto P_0c084a6c;
case 0x0c084a6eu: goto P_0c084a6e;
case 0x0c084a70u: goto P_0c084a70;
case 0x0c084a72u: goto P_0c084a72;
case 0x0c084a74u: goto P_0c084a74;
case 0x0c084a76u: goto P_0c084a76;
case 0x0c084a78u: goto P_0c084a78;
case 0x0c084a7au: goto P_0c084a7a;
case 0x0c084a7cu: goto P_0c084a7c;
case 0x0c084a7eu: goto P_0c084a7e;
case 0x0c084a80u: goto P_0c084a80;
case 0x0c084a82u: goto P_0c084a82;
case 0x0c084a84u: goto P_0c084a84;
case 0x0c084a86u: goto P_0c084a86;
case 0x0c084a88u: goto P_0c084a88;
case 0x0c084a8au: goto P_0c084a8a;
case 0x0c084a8cu: goto P_0c084a8c;
case 0x0c084a8eu: goto P_0c084a8e;
case 0x0c084a90u: goto P_0c084a90;
case 0x0c084a92u: goto P_0c084a92;
case 0x0c084a94u: goto P_0c084a94;
case 0x0c084b00u: goto P_0c084b00;
case 0x0c084b02u: goto P_0c084b02;
case 0x0c084b04u: goto P_0c084b04;
case 0x0c084b06u: goto P_0c084b06;
case 0x0c084b08u: goto P_0c084b08;
case 0x0c084b0au: goto P_0c084b0a;
case 0x0c084b0cu: goto P_0c084b0c;
case 0x0c084b0eu: goto P_0c084b0e;
case 0x0c084b10u: goto P_0c084b10;
case 0x0c084b12u: goto P_0c084b12;
case 0x0c084b14u: goto P_0c084b14;
case 0x0c084b16u: goto P_0c084b16;
case 0x0c084b18u: goto P_0c084b18;
case 0x0c084b1au: goto P_0c084b1a;
case 0x0c084b1cu: goto P_0c084b1c;
case 0x0c084b1eu: goto P_0c084b1e;
case 0x0c084b20u: goto P_0c084b20;
case 0x0c084b22u: goto P_0c084b22;
case 0x0c084b24u: goto P_0c084b24;
case 0x0c084b26u: goto P_0c084b26;
case 0x0c084b28u: goto P_0c084b28;
case 0x0c084b2au: goto P_0c084b2a;
case 0x0c084b2cu: goto P_0c084b2c;
case 0x0c084b2eu: goto P_0c084b2e;
case 0x0c084b30u: goto P_0c084b30;
case 0x0c084b32u: goto P_0c084b32;
case 0x0c084b34u: goto P_0c084b34;
case 0x0c084b36u: goto P_0c084b36;
case 0x0c084b38u: goto P_0c084b38;
case 0x0c084b3au: goto P_0c084b3a;
case 0x0c084b3cu: goto P_0c084b3c;
case 0x0c084b3eu: goto P_0c084b3e;
case 0x0c084b40u: goto P_0c084b40;
case 0x0c084b42u: goto P_0c084b42;
case 0x0c084b44u: goto P_0c084b44;
case 0x0c084b46u: goto P_0c084b46;
case 0x0c084b48u: goto P_0c084b48;
case 0x0c084b4au: goto P_0c084b4a;
case 0x0c084b4cu: goto P_0c084b4c;
case 0x0c084b4eu: goto P_0c084b4e;
case 0x0c084b50u: goto P_0c084b50;
case 0x0c084b52u: goto P_0c084b52;
case 0x0c084b54u: goto P_0c084b54;
case 0x0c084b56u: goto P_0c084b56;
case 0x0c084b58u: goto P_0c084b58;
case 0x0c084b5au: goto P_0c084b5a;
case 0x0c084b5cu: goto P_0c084b5c;
case 0x0c084b5eu: goto P_0c084b5e;
case 0x0c084b60u: goto P_0c084b60;
case 0x0c084b62u: goto P_0c084b62;
case 0x0c084b64u: goto P_0c084b64;
case 0x0c084b66u: goto P_0c084b66;
case 0x0c084b68u: goto P_0c084b68;
case 0x0c084b6au: goto P_0c084b6a;
case 0x0c084b6cu: goto P_0c084b6c;
case 0x0c084b6eu: goto P_0c084b6e;
case 0x0c084b70u: goto P_0c084b70;
case 0x0c084b72u: goto P_0c084b72;
case 0x0c084b74u: goto P_0c084b74;
case 0x0c084b76u: goto P_0c084b76;
case 0x0c084b78u: goto P_0c084b78;
case 0x0c084b7au: goto P_0c084b7a;
case 0x0c084b7cu: goto P_0c084b7c;
case 0x0c084b7eu: goto P_0c084b7e;
case 0x0c084b80u: goto P_0c084b80;
case 0x0c084b82u: goto P_0c084b82;
case 0x0c084b84u: goto P_0c084b84;
case 0x0c084b86u: goto P_0c084b86;
case 0x0c084b88u: goto P_0c084b88;
case 0x0c084b8au: goto P_0c084b8a;
case 0x0c084b8cu: goto P_0c084b8c;
case 0x0c084b8eu: goto P_0c084b8e;
case 0x0c084b90u: goto P_0c084b90;
case 0x0c084b92u: goto P_0c084b92;
case 0x0c084b94u: goto P_0c084b94;
case 0x0c084b96u: goto P_0c084b96;
case 0x0c084b98u: goto P_0c084b98;
case 0x0c084b9au: goto P_0c084b9a;
case 0x0c084b9cu: goto P_0c084b9c;
case 0x0c084b9eu: goto P_0c084b9e;
case 0x0c084ba0u: goto P_0c084ba0;
case 0x0c084ba2u: goto P_0c084ba2;
case 0x0c084ba4u: goto P_0c084ba4;
case 0x0c084ba6u: goto P_0c084ba6;
case 0x0c084ba8u: goto P_0c084ba8;
case 0x0c084baau: goto P_0c084baa;
case 0x0c084bacu: goto P_0c084bac;
case 0x0c084baeu: goto P_0c084bae;
case 0x0c084bb0u: goto P_0c084bb0;
case 0x0c084bb2u: goto P_0c084bb2;
case 0x0c084bb4u: goto P_0c084bb4;
case 0x0c084bb6u: goto P_0c084bb6;
case 0x0c084bb8u: goto P_0c084bb8;
case 0x0c084bbau: goto P_0c084bba;
case 0x0c084bbcu: goto P_0c084bbc;
case 0x0c084bbeu: goto P_0c084bbe;
case 0x0c084bc0u: goto P_0c084bc0;
case 0x0c084bc2u: goto P_0c084bc2;
case 0x0c084bc4u: goto P_0c084bc4;
case 0x0c084bc6u: goto P_0c084bc6;
case 0x0c084bc8u: goto P_0c084bc8;
case 0x0c084bcau: goto P_0c084bca;
case 0x0c084bccu: goto P_0c084bcc;
case 0x0c084bceu: goto P_0c084bce;
case 0x0c084bd0u: goto P_0c084bd0;
case 0x0c084bd2u: goto P_0c084bd2;
case 0x0c084bd4u: goto P_0c084bd4;
case 0x0c084bd6u: goto P_0c084bd6;
case 0x0c084bd8u: goto P_0c084bd8;
case 0x0c084bdau: goto P_0c084bda;
case 0x0c084bdcu: goto P_0c084bdc;
case 0x0c084bdeu: goto P_0c084bde;
case 0x0c084be0u: goto P_0c084be0;
case 0x0c084be2u: goto P_0c084be2;
case 0x0c084be4u: goto P_0c084be4;
case 0x0c084be6u: goto P_0c084be6;
case 0x0c084be8u: goto P_0c084be8;
case 0x0c084beau: goto P_0c084bea;
case 0x0c084becu: goto P_0c084bec;
case 0x0c084beeu: goto P_0c084bee;
case 0x0c084bf0u: goto P_0c084bf0;
case 0x0c084bf2u: goto P_0c084bf2;
case 0x0c084bf4u: goto P_0c084bf4;
case 0x0c084bf6u: goto P_0c084bf6;
case 0x0c084bf8u: goto P_0c084bf8;
case 0x0c084bfau: goto P_0c084bfa;
case 0x0c084bfcu: goto P_0c084bfc;
case 0x0c084bfeu: goto P_0c084bfe;
case 0x0c084c00u: goto P_0c084c00;
case 0x0c084c02u: goto P_0c084c02;
case 0x0c084c04u: goto P_0c084c04;
case 0x0c084c06u: goto P_0c084c06;
case 0x0c084c08u: goto P_0c084c08;
case 0x0c084c0au: goto P_0c084c0a;
case 0x0c084c0cu: goto P_0c084c0c;
case 0x0c084c0eu: goto P_0c084c0e;
case 0x0c084c10u: goto P_0c084c10;
case 0x0c084c12u: goto P_0c084c12;
case 0x0c084c14u: goto P_0c084c14;
case 0x0c084c16u: goto P_0c084c16;
case 0x0c084c18u: goto P_0c084c18;
case 0x0c084c1au: goto P_0c084c1a;
case 0x0c084c1cu: goto P_0c084c1c;
case 0x0c084c1eu: goto P_0c084c1e;
case 0x0c084c20u: goto P_0c084c20;
case 0x0c084c22u: goto P_0c084c22;
case 0x0c084c24u: goto P_0c084c24;
case 0x0c084c26u: goto P_0c084c26;
case 0x0c084c28u: goto P_0c084c28;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08497c: /* original 2fe6, guest PC 0x0c08497c */
if(!s->budget--) { s->failed_pc=0x0c08497cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08497e;
P_0c08497e: /* original c758, guest PC 0x0c08497e */
if(!s->budget--) { s->failed_pc=0x0c08497eu; return 0; }
r[0]=code_base|0x00084ae0u;
goto P_0c084980;
P_0c084980: /* original 2fd6, guest PC 0x0c084980 */
if(!s->budget--) { s->failed_pc=0x0c084980u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084982;
P_0c084982: /* original e30f, guest PC 0x0c084982 */
if(!s->budget--) { s->failed_pc=0x0c084982u; return 0; }
r[3]=0x0000000fu;
goto P_0c084984;
P_0c084984: /* original 2fc6, guest PC 0x0c084984 */
if(!s->budget--) { s->failed_pc=0x0c084984u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084986;
P_0c084986: /* original 6c43, guest PC 0x0c084986 */
if(!s->budget--) { s->failed_pc=0x0c084986u; return 0; }
r[12]=r[4];
goto P_0c084988;
P_0c084988: /* original fffb, guest PC 0x0c084988 */
if(!s->budget--) { s->failed_pc=0x0c084988u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08498a;
P_0c08498a: /* original e201, guest PC 0x0c08498a */
if(!s->budget--) { s->failed_pc=0x0c08498au; return 0; }
r[2]=0x00000001u;
goto P_0c08498c;
P_0c08498c: /* original ffeb, guest PC 0x0c08498c */
if(!s->budget--) { s->failed_pc=0x0c08498cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08498e;
P_0c08498e: /* original 6e53, guest PC 0x0c08498e */
if(!s->budget--) { s->failed_pc=0x0c08498eu; return 0; }
r[14]=r[5];
goto P_0c084990;
P_0c084990: /* original ffdb, guest PC 0x0c084990 */
if(!s->budget--) { s->failed_pc=0x0c084990u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c084992;
P_0c084992: /* original 6dc1, guest PC 0x0c084992 */
if(!s->budget--) { s->failed_pc=0x0c084992u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[13]=tmp;
goto P_0c084994;
P_0c084994: /* original 4f22, guest PC 0x0c084994 */
if(!s->budget--) { s->failed_pc=0x0c084994u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084996;
P_0c084996: /* original 7d01, guest PC 0x0c084996 */
if(!s->budget--) { s->failed_pc=0x0c084996u; return 0; }
r[13]+=0x00000001u;
goto P_0c084998;
P_0c084998: /* original ff08, guest PC 0x0c084998 */
if(!s->budget--) { s->failed_pc=0x0c084998u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08499a;
P_0c08499a: /* original 2d39, guest PC 0x0c08499a */
if(!s->budget--) { s->failed_pc=0x0c08499au; return 0; }
r[13]&=r[3];
goto P_0c08499c;
P_0c08499c: /* original 3d23, guest PC 0x0c08499c */
if(!s->budget--) { s->failed_pc=0x0c08499cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[2])!=0);
goto P_0c08499e;
P_0c08499e: /* original 7fe8, guest PC 0x0c08499e */
if(!s->budget--) { s->failed_pc=0x0c08499eu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0849a0;
P_0c0849a0: /* original c750, guest PC 0x0c0849a0 */
if(!s->budget--) { s->failed_pc=0x0c0849a0u; return 0; }
r[0]=code_base|0x00084ae4u;
goto P_0c0849a2;
P_0c0849a2: /* original 8f03, guest PC 0x0c0849a2 */
if(!s->budget--) { s->failed_pc=0x0c0849a2u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,14,r[0]);
if(!cond) { goto P_0c0849ac; }
goto P_0c0849a6;
P_0c0849a4: /* original fe08, guest PC 0x0c0849a4 */
if(!s->budget--) { s->failed_pc=0x0c0849a4u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0849a6;
P_0c0849a6: /* original 85c2, guest PC 0x0c0849a6 */
if(!s->budget--) { s->failed_pc=0x0c0849a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+4,2);
goto P_0c0849a8;
P_0c0849a8: /* original 2008, guest PC 0x0c0849a8 */
if(!s->budget--) { s->failed_pc=0x0c0849a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0849aa;
P_0c0849aa: /* original 896b, guest PC 0x0c0849aa */
if(!s->budget--) { s->failed_pc=0x0c0849aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084a84; }
goto P_0c0849ac;
P_0c0849ac: /* original 62d3, guest PC 0x0c0849ac */
if(!s->budget--) { s->failed_pc=0x0c0849acu; return 0; }
r[2]=r[13];
goto P_0c0849ae;
P_0c0849ae: /* original 63d3, guest PC 0x0c0849ae */
if(!s->budget--) { s->failed_pc=0x0c0849aeu; return 0; }
r[3]=r[13];
goto P_0c0849b0;
P_0c0849b0: /* original 4208, guest PC 0x0c0849b0 */
if(!s->budget--) { s->failed_pc=0x0c0849b0u; return 0; }
r[2]<<=2;
goto P_0c0849b2;
P_0c0849b2: /* original d44d, guest PC 0x0c0849b2 */
if(!s->budget--) { s->failed_pc=0x0c0849b2u; return 0; }
r[4]=read(ram,0x0c084ae8u,4);
goto P_0c0849b4;
P_0c0849b4: /* original 4300, guest PC 0x0c0849b4 */
if(!s->budget--) { s->failed_pc=0x0c0849b4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0849b6;
P_0c0849b6: /* original 332c, guest PC 0x0c0849b6 */
if(!s->budget--) { s->failed_pc=0x0c0849b6u; return 0; }
r[3]+=r[2];
goto P_0c0849b8;
P_0c0849b8: /* original 4308, guest PC 0x0c0849b8 */
if(!s->budget--) { s->failed_pc=0x0c0849b8u; return 0; }
r[3]<<=2;
goto P_0c0849ba;
P_0c0849ba: /* original 343c, guest PC 0x0c0849ba */
if(!s->budget--) { s->failed_pc=0x0c0849bau; return 0; }
r[4]+=r[3];
goto P_0c0849bc;
P_0c0849bc: /* original f349, guest PC 0x0c0849bc */
if(!s->budget--) { s->failed_pc=0x0c0849bcu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849be;
P_0c0849be: /* original e00c, guest PC 0x0c0849be */
if(!s->budget--) { s->failed_pc=0x0c0849beu; return 0; }
r[0]=0x0000000cu;
goto P_0c0849c0;
P_0c0849c0: /* original ff37, guest PC 0x0c0849c0 */
if(!s->budget--) { s->failed_pc=0x0c0849c0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849c2;
P_0c0849c2: /* original e014, guest PC 0x0c0849c2 */
if(!s->budget--) { s->failed_pc=0x0c0849c2u; return 0; }
r[0]=0x00000014u;
goto P_0c0849c4;
P_0c0849c4: /* original fd49, guest PC 0x0c0849c4 */
if(!s->budget--) { s->failed_pc=0x0c0849c4u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849c6;
P_0c0849c6: /* original f349, guest PC 0x0c0849c6 */
if(!s->budget--) { s->failed_pc=0x0c0849c6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849c8;
P_0c0849c8: /* original ff37, guest PC 0x0c0849c8 */
if(!s->budget--) { s->failed_pc=0x0c0849c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849ca;
P_0c0849ca: /* original e004, guest PC 0x0c0849ca */
if(!s->budget--) { s->failed_pc=0x0c0849cau; return 0; }
r[0]=0x00000004u;
goto P_0c0849cc;
P_0c0849cc: /* original f349, guest PC 0x0c0849cc */
if(!s->budget--) { s->failed_pc=0x0c0849ccu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849ce;
P_0c0849ce: /* original ff37, guest PC 0x0c0849ce */
if(!s->budget--) { s->failed_pc=0x0c0849ceu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849d0;
P_0c0849d0: /* original e010, guest PC 0x0c0849d0 */
if(!s->budget--) { s->failed_pc=0x0c0849d0u; return 0; }
r[0]=0x00000010u;
goto P_0c0849d2;
P_0c0849d2: /* original f349, guest PC 0x0c0849d2 */
if(!s->budget--) { s->failed_pc=0x0c0849d2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849d4;
P_0c0849d4: /* original ff37, guest PC 0x0c0849d4 */
if(!s->budget--) { s->failed_pc=0x0c0849d4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849d6;
P_0c0849d6: /* original e008, guest PC 0x0c0849d6 */
if(!s->budget--) { s->failed_pc=0x0c0849d6u; return 0; }
r[0]=0x00000008u;
goto P_0c0849d8;
P_0c0849d8: /* original d344, guest PC 0x0c0849d8 */
if(!s->budget--) { s->failed_pc=0x0c0849d8u; return 0; }
r[3]=read(ram,0x0c084aecu,4);
goto P_0c0849da;
P_0c0849da: /* original f348, guest PC 0x0c0849da */
if(!s->budget--) { s->failed_pc=0x0c0849dau; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c0849dc;
P_0c0849dc: /* original 430b, guest PC 0x0c0849dc */
if(!s->budget--) { s->failed_pc=0x0c0849dcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0849e0u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0849e0u) { target=s->pc; goto dispatch; }
goto P_0c0849e0;
P_0c0849de: /* original ff37, guest PC 0x0c0849de */
if(!s->budget--) { s->failed_pc=0x0c0849deu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849e0;
P_0c0849e0: /* original 957d, guest PC 0x0c0849e0 */
if(!s->budget--) { s->failed_pc=0x0c0849e0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084adeu,2);
goto P_0c0849e2;
P_0c0849e2: /* original 6603, guest PC 0x0c0849e2 */
if(!s->budget--) { s->failed_pc=0x0c0849e2u; return 0; }
r[6]=r[0];
goto P_0c0849e4;
P_0c0849e4: /* original e203, guest PC 0x0c0849e4 */
if(!s->budget--) { s->failed_pc=0x0c0849e4u; return 0; }
r[2]=0x00000003u;
goto P_0c0849e6;
P_0c0849e6: /* original 6403, guest PC 0x0c0849e6 */
if(!s->budget--) { s->failed_pc=0x0c0849e6u; return 0; }
r[4]=r[0];
goto P_0c0849e8;
P_0c0849e8: /* original 2659, guest PC 0x0c0849e8 */
if(!s->budget--) { s->failed_pc=0x0c0849e8u; return 0; }
r[6]&=r[5];
goto P_0c0849ea;
P_0c0849ea: /* original d041, guest PC 0x0c0849ea */
if(!s->budget--) { s->failed_pc=0x0c0849eau; return 0; }
r[0]=read(ram,0x0c084af0u,4);
goto P_0c0849ec;
P_0c0849ec: /* original 465a, guest PC 0x0c0849ec */
if(!s->budget--) { s->failed_pc=0x0c0849ecu; return 0; }
r[53]=r[6];
goto P_0c0849ee;
P_0c0849ee: /* original e3f9, guest PC 0x0c0849ee */
if(!s->budget--) { s->failed_pc=0x0c0849eeu; return 0; }
r[3]=0xfffffff9u;
goto P_0c0849f0;
P_0c0849f0: /* original 6643, guest PC 0x0c0849f0 */
if(!s->budget--) { s->failed_pc=0x0c0849f0u; return 0; }
r[6]=r[4];
goto P_0c0849f2;
P_0c0849f2: /* original 2249, guest PC 0x0c0849f2 */
if(!s->budget--) { s->failed_pc=0x0c0849f2u; return 0; }
r[2]&=r[4];
goto P_0c0849f4;
P_0c0849f4: /* original e70e, guest PC 0x0c0849f4 */
if(!s->budget--) { s->failed_pc=0x0c0849f4u; return 0; }
r[7]=0x0000000eu;
goto P_0c0849f6;
P_0c0849f6: /* original 463c, guest PC 0x0c0849f6 */
if(!s->budget--) { s->failed_pc=0x0c0849f6u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c0849f8;
P_0c0849f8: /* original f32d, guest PC 0x0c0849f8 */
if(!s->budget--) { s->failed_pc=0x0c0849f8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0849fa;
P_0c0849fa: /* original 4208, guest PC 0x0c0849fa */
if(!s->budget--) { s->failed_pc=0x0c0849fau; return 0; }
r[2]<<=2;
goto P_0c0849fc;
P_0c0849fc: /* original 6343, guest PC 0x0c0849fc */
if(!s->budget--) { s->failed_pc=0x0c0849fcu; return 0; }
r[3]=r[4];
goto P_0c0849fe;
P_0c0849fe: /* original 2679, guest PC 0x0c0849fe */
if(!s->budget--) { s->failed_pc=0x0c0849feu; return 0; }
r[6]&=r[7];
goto P_0c084a00;
P_0c084a00: /* original f626, guest PC 0x0c084a00 */
if(!s->budget--) { s->failed_pc=0x0c084a00u; return 0; }
vf3_matrix_load(s,ram,6,r[2]+r[0]);
goto P_0c084a02;
P_0c084a02: /* original 4601, guest PC 0x0c084a02 */
if(!s->budget--) { s->failed_pc=0x0c084a02u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c084a04;
P_0c084a04: /* original d03b, guest PC 0x0c084a04 */
if(!s->budget--) { s->failed_pc=0x0c084a04u; return 0; }
r[0]=read(ram,0x0c084af4u,4);
goto P_0c084a06;
P_0c084a06: /* original 4600, guest PC 0x0c084a06 */
if(!s->budget--) { s->failed_pc=0x0c084a06u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c084a08;
P_0c084a08: /* original 066d, guest PC 0x0c084a08 */
if(!s->budget--) { s->failed_pc=0x0c084a08u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c084a0a;
P_0c084a0a: /* original c73b, guest PC 0x0c084a0a */
if(!s->budget--) { s->failed_pc=0x0c084a0au; return 0; }
r[0]=code_base|0x00084af8u;
goto P_0c084a0c;
P_0c084a0c: /* original f508, guest PC 0x0c084a0c */
if(!s->budget--) { s->failed_pc=0x0c084a0cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c084a0e;
P_0c084a0e: /* original 4318, guest PC 0x0c084a0e */
if(!s->budget--) { s->failed_pc=0x0c084a0eu; return 0; }
r[3]<<=8;
goto P_0c084a10;
P_0c084a10: /* original f43c, guest PC 0x0c084a10 */
if(!s->budget--) { s->failed_pc=0x0c084a10u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c084a12;
P_0c084a12: /* original 2359, guest PC 0x0c084a12 */
if(!s->budget--) { s->failed_pc=0x0c084a12u; return 0; }
r[3]&=r[5];
goto P_0c084a14;
P_0c084a14: /* original f453, guest PC 0x0c084a14 */
if(!s->budget--) { s->failed_pc=0x0c084a14u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c084a16;
P_0c084a16: /* original 2f32, guest PC 0x0c084a16 */
if(!s->budget--) { s->failed_pc=0x0c084a16u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c084a18;
P_0c084a18: /* original 435a, guest PC 0x0c084a18 */
if(!s->budget--) { s->failed_pc=0x0c084a18u; return 0; }
r[53]=r[3];
goto P_0c084a1a;
P_0c084a1a: /* original f32d, guest PC 0x0c084a1a */
if(!s->budget--) { s->failed_pc=0x0c084a1au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c084a1c;
P_0c084a1c: /* original ff40, guest PC 0x0c084a1c */
if(!s->budget--) { s->failed_pc=0x0c084a1cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'+');
goto P_0c084a1e;
P_0c084a1e: /* original f43c, guest PC 0x0c084a1e */
if(!s->budget--) { s->failed_pc=0x0c084a1eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c084a20;
P_0c084a20: /* original f453, guest PC 0x0c084a20 */
if(!s->budget--) { s->failed_pc=0x0c084a20u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c084a22;
P_0c084a22: /* original 6343, guest PC 0x0c084a22 */
if(!s->budget--) { s->failed_pc=0x0c084a22u; return 0; }
r[3]=r[4];
goto P_0c084a24;
P_0c084a24: /* original 4418, guest PC 0x0c084a24 */
if(!s->budget--) { s->failed_pc=0x0c084a24u; return 0; }
r[4]<<=8;
goto P_0c084a26;
P_0c084a26: /* original d033, guest PC 0x0c084a26 */
if(!s->budget--) { s->failed_pc=0x0c084a26u; return 0; }
r[0]=read(ram,0x0c084af4u,4);
goto P_0c084a28;
P_0c084a28: /* original 4408, guest PC 0x0c084a28 */
if(!s->budget--) { s->failed_pc=0x0c084a28u; return 0; }
r[4]<<=2;
goto P_0c084a2a;
P_0c084a2a: /* original 2459, guest PC 0x0c084a2a */
if(!s->budget--) { s->failed_pc=0x0c084a2au; return 0; }
r[4]&=r[5];
goto P_0c084a2c;
P_0c084a2c: /* original 445a, guest PC 0x0c084a2c */
if(!s->budget--) { s->failed_pc=0x0c084a2cu; return 0; }
r[53]=r[4];
goto P_0c084a2e;
P_0c084a2e: /* original e2f7, guest PC 0x0c084a2e */
if(!s->budget--) { s->failed_pc=0x0c084a2eu; return 0; }
r[2]=0xfffffff7u;
goto P_0c084a30;
P_0c084a30: /* original 432c, guest PC 0x0c084a30 */
if(!s->budget--) { s->failed_pc=0x0c084a30u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c084a32;
P_0c084a32: /* original 2379, guest PC 0x0c084a32 */
if(!s->budget--) { s->failed_pc=0x0c084a32u; return 0; }
r[3]&=r[7];
goto P_0c084a34;
P_0c084a34: /* original f32d, guest PC 0x0c084a34 */
if(!s->budget--) { s->failed_pc=0x0c084a34u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c084a36;
P_0c084a36: /* original 4301, guest PC 0x0c084a36 */
if(!s->budget--) { s->failed_pc=0x0c084a36u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c084a38;
P_0c084a38: /* original 4300, guest PC 0x0c084a38 */
if(!s->budget--) { s->failed_pc=0x0c084a38u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c084a3a;
P_0c084a3a: /* original 073d, guest PC 0x0c084a3a */
if(!s->budget--) { s->failed_pc=0x0c084a3au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c084a3c;
P_0c084a3c: /* original e028, guest PC 0x0c084a3c */
if(!s->budget--) { s->failed_pc=0x0c084a3cu; return 0; }
r[0]=0x00000028u;
goto P_0c084a3e;
P_0c084a3e: /* original fd40, guest PC 0x0c084a3e */
if(!s->budget--) { s->failed_pc=0x0c084a3eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'+');
goto P_0c084a40;
P_0c084a40: /* original f43c, guest PC 0x0c084a40 */
if(!s->budget--) { s->failed_pc=0x0c084a40u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c084a42;
P_0c084a42: /* original f453, guest PC 0x0c084a42 */
if(!s->budget--) { s->failed_pc=0x0c084a42u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c084a44;
P_0c084a44: /* original 0e65, guest PC 0x0c084a44 */
if(!s->budget--) { s->failed_pc=0x0c084a44u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c084a46;
P_0c084a46: /* original e02a, guest PC 0x0c084a46 */
if(!s->budget--) { s->failed_pc=0x0c084a46u; return 0; }
r[0]=0x0000002au;
goto P_0c084a48;
P_0c084a48: /* original 0e75, guest PC 0x0c084a48 */
if(!s->budget--) { s->failed_pc=0x0c084a48u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c084a4a;
P_0c084a4a: /* original e014, guest PC 0x0c084a4a */
if(!s->budget--) { s->failed_pc=0x0c084a4au; return 0; }
r[0]=0x00000014u;
goto P_0c084a4c;
P_0c084a4c: /* original fe67, guest PC 0x0c084a4c */
if(!s->budget--) { s->failed_pc=0x0c084a4cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c084a4e;
P_0c084a4e: /* original e014, guest PC 0x0c084a4e */
if(!s->budget--) { s->failed_pc=0x0c084a4eu; return 0; }
r[0]=0x00000014u;
goto P_0c084a50;
P_0c084a50: /* original f3f6, guest PC 0x0c084a50 */
if(!s->budget--) { s->failed_pc=0x0c084a50u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a52;
P_0c084a52: /* original e00c, guest PC 0x0c084a52 */
if(!s->budget--) { s->failed_pc=0x0c084a52u; return 0; }
r[0]=0x0000000cu;
goto P_0c084a54;
P_0c084a54: /* original fe37, guest PC 0x0c084a54 */
if(!s->budget--) { s->failed_pc=0x0c084a54u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a56;
P_0c084a56: /* original e010, guest PC 0x0c084a56 */
if(!s->budget--) { s->failed_pc=0x0c084a56u; return 0; }
r[0]=0x00000010u;
goto P_0c084a58;
P_0c084a58: /* original f3f6, guest PC 0x0c084a58 */
if(!s->budget--) { s->failed_pc=0x0c084a58u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a5a;
P_0c084a5a: /* original e018, guest PC 0x0c084a5a */
if(!s->budget--) { s->failed_pc=0x0c084a5au; return 0; }
r[0]=0x00000018u;
goto P_0c084a5c;
P_0c084a5c: /* original fe37, guest PC 0x0c084a5c */
if(!s->budget--) { s->failed_pc=0x0c084a5cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a5e;
P_0c084a5e: /* original fe40, guest PC 0x0c084a5e */
if(!s->budget--) { s->failed_pc=0x0c084a5eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'+');
goto P_0c084a60;
P_0c084a60: /* original e00c, guest PC 0x0c084a60 */
if(!s->budget--) { s->failed_pc=0x0c084a60u; return 0; }
r[0]=0x0000000cu;
goto P_0c084a62;
P_0c084a62: /* original f3f6, guest PC 0x0c084a62 */
if(!s->budget--) { s->failed_pc=0x0c084a62u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a64;
P_0c084a64: /* original e01c, guest PC 0x0c084a64 */
if(!s->budget--) { s->failed_pc=0x0c084a64u; return 0; }
r[0]=0x0000001cu;
goto P_0c084a66;
P_0c084a66: /* original fe37, guest PC 0x0c084a66 */
if(!s->budget--) { s->failed_pc=0x0c084a66u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a68;
P_0c084a68: /* original e008, guest PC 0x0c084a68 */
if(!s->budget--) { s->failed_pc=0x0c084a68u; return 0; }
r[0]=0x00000008u;
goto P_0c084a6a;
P_0c084a6a: /* original f3f6, guest PC 0x0c084a6a */
if(!s->budget--) { s->failed_pc=0x0c084a6au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a6c;
P_0c084a6c: /* original e020, guest PC 0x0c084a6c */
if(!s->budget--) { s->failed_pc=0x0c084a6cu; return 0; }
r[0]=0x00000020u;
goto P_0c084a6e;
P_0c084a6e: /* original fe37, guest PC 0x0c084a6e */
if(!s->budget--) { s->failed_pc=0x0c084a6eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a70;
P_0c084a70: /* original e004, guest PC 0x0c084a70 */
if(!s->budget--) { s->failed_pc=0x0c084a70u; return 0; }
r[0]=0x00000004u;
goto P_0c084a72;
P_0c084a72: /* original f3f6, guest PC 0x0c084a72 */
if(!s->budget--) { s->failed_pc=0x0c084a72u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a74;
P_0c084a74: /* original e010, guest PC 0x0c084a74 */
if(!s->budget--) { s->failed_pc=0x0c084a74u; return 0; }
r[0]=0x00000010u;
goto P_0c084a76;
P_0c084a76: /* original fe37, guest PC 0x0c084a76 */
if(!s->budget--) { s->failed_pc=0x0c084a76u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a78;
P_0c084a78: /* original e004, guest PC 0x0c084a78 */
if(!s->budget--) { s->failed_pc=0x0c084a78u; return 0; }
r[0]=0x00000004u;
goto P_0c084a7a;
P_0c084a7a: /* original fefa, guest PC 0x0c084a7a */
if(!s->budget--) { s->failed_pc=0x0c084a7au; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c084a7c;
P_0c084a7c: /* original fed7, guest PC 0x0c084a7c */
if(!s->budget--) { s->failed_pc=0x0c084a7cu; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c084a7e;
P_0c084a7e: /* original e008, guest PC 0x0c084a7e */
if(!s->budget--) { s->failed_pc=0x0c084a7eu; return 0; }
r[0]=0x00000008u;
goto P_0c084a80;
P_0c084a80: /* original fee7, guest PC 0x0c084a80 */
if(!s->budget--) { s->failed_pc=0x0c084a80u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c084a82;
P_0c084a82: /* original 2cd1, guest PC 0x0c084a82 */
if(!s->budget--) { s->failed_pc=0x0c084a82u; return 0; }
write(ram,r[12],r[13],2);
goto P_0c084a84;
P_0c084a84: /* original 7f18, guest PC 0x0c084a84 */
if(!s->budget--) { s->failed_pc=0x0c084a84u; return 0; }
r[15]+=0x00000018u;
goto P_0c084a86;
P_0c084a86: /* original 4f26, guest PC 0x0c084a86 */
if(!s->budget--) { s->failed_pc=0x0c084a86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084a88;
P_0c084a88: /* original fdf9, guest PC 0x0c084a88 */
if(!s->budget--) { s->failed_pc=0x0c084a88u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084a8a;
P_0c084a8a: /* original fef9, guest PC 0x0c084a8a */
if(!s->budget--) { s->failed_pc=0x0c084a8au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084a8c;
P_0c084a8c: /* original fff9, guest PC 0x0c084a8c */
if(!s->budget--) { s->failed_pc=0x0c084a8cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084a8e;
P_0c084a8e: /* original 6cf6, guest PC 0x0c084a8e */
if(!s->budget--) { s->failed_pc=0x0c084a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084a90;
P_0c084a90: /* original 6df6, guest PC 0x0c084a90 */
if(!s->budget--) { s->failed_pc=0x0c084a90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084a92;
P_0c084a92: /* original 000b, guest PC 0x0c084a92 */
if(!s->budget--) { s->failed_pc=0x0c084a92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084a94: /* original 6ef6, guest PC 0x0c084a94 */
if(!s->budget--) { s->failed_pc=0x0c084a94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c084a96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084a96u; return 0; } return 1;
P_0c084b00: /* original 2fe6, guest PC 0x0c084b00 */
if(!s->budget--) { s->failed_pc=0x0c084b00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b02;
P_0c084b02: /* original 2fd6, guest PC 0x0c084b02 */
if(!s->budget--) { s->failed_pc=0x0c084b02u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b04;
P_0c084b04: /* original 2fc6, guest PC 0x0c084b04 */
if(!s->budget--) { s->failed_pc=0x0c084b04u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b06;
P_0c084b06: /* original 2fb6, guest PC 0x0c084b06 */
if(!s->budget--) { s->failed_pc=0x0c084b06u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b08;
P_0c084b08: /* original 2fa6, guest PC 0x0c084b08 */
if(!s->budget--) { s->failed_pc=0x0c084b08u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b0a;
P_0c084b0a: /* original 2f96, guest PC 0x0c084b0a */
if(!s->budget--) { s->failed_pc=0x0c084b0au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084b0c;
P_0c084b0c: /* original fffb, guest PC 0x0c084b0c */
if(!s->budget--) { s->failed_pc=0x0c084b0cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c084b0e;
P_0c084b0e: /* original ffeb, guest PC 0x0c084b0e */
if(!s->budget--) { s->failed_pc=0x0c084b0eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c084b10;
P_0c084b10: /* original ffdb, guest PC 0x0c084b10 */
if(!s->budget--) { s->failed_pc=0x0c084b10u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c084b12;
P_0c084b12: /* original ffcb, guest PC 0x0c084b12 */
if(!s->budget--) { s->failed_pc=0x0c084b12u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c084b14;
P_0c084b14: /* original d146, guest PC 0x0c084b14 */
if(!s->budget--) { s->failed_pc=0x0c084b14u; return 0; }
r[1]=read(ram,0x0c084c30u,4);
goto P_0c084b16;
P_0c084b16: /* original 4f22, guest PC 0x0c084b16 */
if(!s->budget--) { s->failed_pc=0x0c084b16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084b18;
P_0c084b18: /* original d344, guest PC 0x0c084b18 */
if(!s->budget--) { s->failed_pc=0x0c084b18u; return 0; }
r[3]=read(ram,0x0c084c2cu,4);
goto P_0c084b1a;
P_0c084b1a: /* original 6212, guest PC 0x0c084b1a */
if(!s->budget--) { s->failed_pc=0x0c084b1au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c084b1c;
P_0c084b1c: /* original 7ffc, guest PC 0x0c084b1c */
if(!s->budget--) { s->failed_pc=0x0c084b1cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c084b1e;
P_0c084b1e: /* original 2238, guest PC 0x0c084b1e */
if(!s->budget--) { s->failed_pc=0x0c084b1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c084b20;
P_0c084b20: /* original 8b76, guest PC 0x0c084b20 */
if(!s->budget--) { s->failed_pc=0x0c084b20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084c10; }
goto P_0c084b22;
P_0c084b22: /* original 6d43, guest PC 0x0c084b22 */
if(!s->budget--) { s->failed_pc=0x0c084b22u; return 0; }
r[13]=r[4];
goto P_0c084b24;
P_0c084b24: /* original 85d1, guest PC 0x0c084b24 */
if(!s->budget--) { s->failed_pc=0x0c084b24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c084b26;
P_0c084b26: /* original 6403, guest PC 0x0c084b26 */
if(!s->budget--) { s->failed_pc=0x0c084b26u; return 0; }
r[4]=r[0];
goto P_0c084b28;
P_0c084b28: /* original 74ff, guest PC 0x0c084b28 */
if(!s->budget--) { s->failed_pc=0x0c084b28u; return 0; }
r[4]+=0xffffffffu;
goto P_0c084b2a;
P_0c084b2a: /* original 4415, guest PC 0x0c084b2a */
if(!s->budget--) { s->failed_pc=0x0c084b2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c084b2c;
P_0c084b2c: /* original 6043, guest PC 0x0c084b2c */
if(!s->budget--) { s->failed_pc=0x0c084b2cu; return 0; }
r[0]=r[4];
goto P_0c084b2e;
P_0c084b2e: /* original 8d16, guest PC 0x0c084b2e */
if(!s->budget--) { s->failed_pc=0x0c084b2eu; return 0; }
cond=r[17]&1u;
write(ram,r[13]+2,r[0],2);
if(cond) { goto P_0c084b5e; }
goto P_0c084b32;
P_0c084b30: /* original 81d1, guest PC 0x0c084b30 */
if(!s->budget--) { s->failed_pc=0x0c084b30u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c084b32;
P_0c084b32: /* original d240, guest PC 0x0c084b32 */
if(!s->budget--) { s->failed_pc=0x0c084b32u; return 0; }
r[2]=read(ram,0x0c084c34u,4);
goto P_0c084b34;
P_0c084b34: /* original 420b, guest PC 0x0c084b34 */
if(!s->budget--) { s->failed_pc=0x0c084b34u; return 0; }
target=r[2];
r[16]=code_base|0x0c084b38u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084b38u) { target=s->pc; goto dispatch; }
goto P_0c084b38;
P_0c084b36: /* original 0009, guest PC 0x0c084b36 */
if(!s->budget--) { s->failed_pc=0x0c084b36u; return 0; }
goto P_0c084b38;
P_0c084b38: /* original 6503, guest PC 0x0c084b38 */
if(!s->budget--) { s->failed_pc=0x0c084b38u; return 0; }
r[5]=r[0];
goto P_0c084b3a;
P_0c084b3a: /* original e60e, guest PC 0x0c084b3a */
if(!s->budget--) { s->failed_pc=0x0c084b3au; return 0; }
r[6]=0x0000000eu;
goto P_0c084b3c;
P_0c084b3c: /* original 2569, guest PC 0x0c084b3c */
if(!s->budget--) { s->failed_pc=0x0c084b3cu; return 0; }
r[5]&=r[6];
goto P_0c084b3e;
P_0c084b3e: /* original 6403, guest PC 0x0c084b3e */
if(!s->budget--) { s->failed_pc=0x0c084b3eu; return 0; }
r[4]=r[0];
goto P_0c084b40;
P_0c084b40: /* original 4501, guest PC 0x0c084b40 */
if(!s->budget--) { s->failed_pc=0x0c084b40u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c084b42;
P_0c084b42: /* original d13d, guest PC 0x0c084b42 */
if(!s->budget--) { s->failed_pc=0x0c084b42u; return 0; }
r[1]=read(ram,0x0c084c38u,4);
goto P_0c084b44;
P_0c084b44: /* original 6053, guest PC 0x0c084b44 */
if(!s->budget--) { s->failed_pc=0x0c084b44u; return 0; }
r[0]=r[5];
goto P_0c084b46;
P_0c084b46: /* original e3f9, guest PC 0x0c084b46 */
if(!s->budget--) { s->failed_pc=0x0c084b46u; return 0; }
r[3]=0xfffffff9u;
goto P_0c084b48;
P_0c084b48: /* original 4000, guest PC 0x0c084b48 */
if(!s->budget--) { s->failed_pc=0x0c084b48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c084b4a;
P_0c084b4a: /* original 443c, guest PC 0x0c084b4a */
if(!s->budget--) { s->failed_pc=0x0c084b4au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c084b4c;
P_0c084b4c: /* original 001d, guest PC 0x0c084b4c */
if(!s->budget--) { s->failed_pc=0x0c084b4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c084b4e;
P_0c084b4e: /* original 2469, guest PC 0x0c084b4e */
if(!s->budget--) { s->failed_pc=0x0c084b4eu; return 0; }
r[4]&=r[6];
goto P_0c084b50;
P_0c084b50: /* original 4401, guest PC 0x0c084b50 */
if(!s->budget--) { s->failed_pc=0x0c084b50u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c084b52;
P_0c084b52: /* original 81d2, guest PC 0x0c084b52 */
if(!s->budget--) { s->failed_pc=0x0c084b52u; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c084b54;
P_0c084b54: /* original d239, guest PC 0x0c084b54 */
if(!s->budget--) { s->failed_pc=0x0c084b54u; return 0; }
r[2]=read(ram,0x0c084c3cu,4);
goto P_0c084b56;
P_0c084b56: /* original 6043, guest PC 0x0c084b56 */
if(!s->budget--) { s->failed_pc=0x0c084b56u; return 0; }
r[0]=r[4];
goto P_0c084b58;
P_0c084b58: /* original 4000, guest PC 0x0c084b58 */
if(!s->budget--) { s->failed_pc=0x0c084b58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c084b5a;
P_0c084b5a: /* original 002d, guest PC 0x0c084b5a */
if(!s->budget--) { s->failed_pc=0x0c084b5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c084b5c;
P_0c084b5c: /* original 81d1, guest PC 0x0c084b5c */
if(!s->budget--) { s->failed_pc=0x0c084b5cu; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c084b5e;
P_0c084b5e: /* original c738, guest PC 0x0c084b5e */
if(!s->budget--) { s->failed_pc=0x0c084b5eu; return 0; }
r[0]=code_base|0x00084c40u;
goto P_0c084b60;
P_0c084b60: /* original da38, guest PC 0x0c084b60 */
if(!s->budget--) { s->failed_pc=0x0c084b60u; return 0; }
r[10]=read(ram,0x0c084c44u,4);
goto P_0c084b62;
P_0c084b62: /* original fc08, guest PC 0x0c084b62 */
if(!s->budget--) { s->failed_pc=0x0c084b62u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c084b64;
P_0c084b64: /* original 6ed3, guest PC 0x0c084b64 */
if(!s->budget--) { s->failed_pc=0x0c084b64u; return 0; }
r[14]=r[13];
goto P_0c084b66;
P_0c084b66: /* original 7e14, guest PC 0x0c084b66 */
if(!s->budget--) { s->failed_pc=0x0c084b66u; return 0; }
r[14]+=0x00000014u;
goto P_0c084b68;
P_0c084b68: /* original fd9d, guest PC 0x0c084b68 */
if(!s->budget--) { s->failed_pc=0x0c084b68u; return 0; }
fr[13]=0x3f800000u;
goto P_0c084b6a;
P_0c084b6a: /* original a04a, guest PC 0x0c084b6a */
if(!s->budget--) { s->failed_pc=0x0c084b6au; return 0; }
r[9]=0x0000000au;
goto P_0c084c02;
P_0c084b6c: /* original e90a, guest PC 0x0c084b6c */
if(!s->budget--) { s->failed_pc=0x0c084b6cu; return 0; }
r[9]=0x0000000au;
goto P_0c084b6e;
P_0c084b6e: /* original e010, guest PC 0x0c084b6e */
if(!s->budget--) { s->failed_pc=0x0c084b6eu; return 0; }
r[0]=0x00000010u;
goto P_0c084b70;
P_0c084b70: /* original f3e6, guest PC 0x0c084b70 */
if(!s->budget--) { s->failed_pc=0x0c084b70u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c084b72;
P_0c084b72: /* original e024, guest PC 0x0c084b72 */
if(!s->budget--) { s->failed_pc=0x0c084b72u; return 0; }
r[0]=0x00000024u;
goto P_0c084b74;
P_0c084b74: /* original ff3a, guest PC 0x0c084b74 */
if(!s->budget--) { s->failed_pc=0x0c084b74u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c084b76;
P_0c084b76: /* original 0bed, guest PC 0x0c084b76 */
if(!s->budget--) { s->failed_pc=0x0c084b76u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084b78;
P_0c084b78: /* original e028, guest PC 0x0c084b78 */
if(!s->budget--) { s->failed_pc=0x0c084b78u; return 0; }
r[0]=0x00000028u;
goto P_0c084b7a;
P_0c084b7a: /* original 03ed, guest PC 0x0c084b7a */
if(!s->budget--) { s->failed_pc=0x0c084b7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084b7c;
P_0c084b7c: /* original e024, guest PC 0x0c084b7c */
if(!s->budget--) { s->failed_pc=0x0c084b7cu; return 0; }
r[0]=0x00000024u;
goto P_0c084b7e;
P_0c084b7e: /* original 3b3c, guest PC 0x0c084b7e */
if(!s->budget--) { s->failed_pc=0x0c084b7eu; return 0; }
r[11]+=r[3];
goto P_0c084b80;
P_0c084b80: /* original 0eb5, guest PC 0x0c084b80 */
if(!s->budget--) { s->failed_pc=0x0c084b80u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c084b82;
P_0c084b82: /* original e026, guest PC 0x0c084b82 */
if(!s->budget--) { s->failed_pc=0x0c084b82u; return 0; }
r[0]=0x00000026u;
goto P_0c084b84;
P_0c084b84: /* original 0ced, guest PC 0x0c084b84 */
if(!s->budget--) { s->failed_pc=0x0c084b84u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084b86;
P_0c084b86: /* original e02a, guest PC 0x0c084b86 */
if(!s->budget--) { s->failed_pc=0x0c084b86u; return 0; }
r[0]=0x0000002au;
goto P_0c084b88;
P_0c084b88: /* original 03ed, guest PC 0x0c084b88 */
if(!s->budget--) { s->failed_pc=0x0c084b88u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084b8a;
P_0c084b8a: /* original e026, guest PC 0x0c084b8a */
if(!s->budget--) { s->failed_pc=0x0c084b8au; return 0; }
r[0]=0x00000026u;
goto P_0c084b8c;
P_0c084b8c: /* original 3c3c, guest PC 0x0c084b8c */
if(!s->budget--) { s->failed_pc=0x0c084b8cu; return 0; }
r[12]+=r[3];
goto P_0c084b8e;
P_0c084b8e: /* original 0ec5, guest PC 0x0c084b8e */
if(!s->budget--) { s->failed_pc=0x0c084b8eu; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c084b90;
P_0c084b90: /* original e020, guest PC 0x0c084b90 */
if(!s->budget--) { s->failed_pc=0x0c084b90u; return 0; }
r[0]=0x00000020u;
goto P_0c084b92;
P_0c084b92: /* original ffe6, guest PC 0x0c084b92 */
if(!s->budget--) { s->failed_pc=0x0c084b92u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c084b94;
P_0c084b94: /* original 4a0b, guest PC 0x0c084b94 */
if(!s->budget--) { s->failed_pc=0x0c084b94u; return 0; }
target=r[10];
r[16]=code_base|0x0c084b98u;
r[4]=(uint32_t)(int32_t)(int16_t)r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084b98u) { target=s->pc; goto dispatch; }
goto P_0c084b98;
P_0c084b96: /* original 64bf, guest PC 0x0c084b96 */
if(!s->budget--) { s->failed_pc=0x0c084b96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c084b98;
P_0c084b98: /* original fe0c, guest PC 0x0c084b98 */
if(!s->budget--) { s->failed_pc=0x0c084b98u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c084b9a;
P_0c084b9a: /* original fef2, guest PC 0x0c084b9a */
if(!s->budget--) { s->failed_pc=0x0c084b9au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c084b9c;
P_0c084b9c: /* original 4a0b, guest PC 0x0c084b9c */
if(!s->budget--) { s->failed_pc=0x0c084b9cu; return 0; }
target=r[10];
r[16]=code_base|0x0c084ba0u;
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084ba0u) { target=s->pc; goto dispatch; }
goto P_0c084ba0;
P_0c084b9e: /* original 64cf, guest PC 0x0c084b9e */
if(!s->budget--) { s->failed_pc=0x0c084b9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c084ba0;
P_0c084ba0: /* original e004, guest PC 0x0c084ba0 */
if(!s->budget--) { s->failed_pc=0x0c084ba0u; return 0; }
r[0]=0x00000004u;
goto P_0c084ba2;
P_0c084ba2: /* original f3f8, guest PC 0x0c084ba2 */
if(!s->budget--) { s->failed_pc=0x0c084ba2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c084ba4;
P_0c084ba4: /* original f6e6, guest PC 0x0c084ba4 */
if(!s->budget--) { s->failed_pc=0x0c084ba4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c084ba6;
P_0c084ba6: /* original e008, guest PC 0x0c084ba6 */
if(!s->budget--) { s->failed_pc=0x0c084ba6u; return 0; }
r[0]=0x00000008u;
goto P_0c084ba8;
P_0c084ba8: /* original f8e6, guest PC 0x0c084ba8 */
if(!s->budget--) { s->failed_pc=0x0c084ba8u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c084baa;
P_0c084baa: /* original e014, guest PC 0x0c084baa */
if(!s->budget--) { s->failed_pc=0x0c084baau; return 0; }
r[0]=0x00000014u;
goto P_0c084bac;
P_0c084bac: /* original f5e6, guest PC 0x0c084bac */
if(!s->budget--) { s->failed_pc=0x0c084bacu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c084bae;
P_0c084bae: /* original e00c, guest PC 0x0c084bae */
if(!s->budget--) { s->failed_pc=0x0c084baeu; return 0; }
r[0]=0x0000000cu;
goto P_0c084bb0;
P_0c084bb0: /* original f4e6, guest PC 0x0c084bb0 */
if(!s->budget--) { s->failed_pc=0x0c084bb0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c084bb2;
P_0c084bb2: /* original e018, guest PC 0x0c084bb2 */
if(!s->budget--) { s->failed_pc=0x0c084bb2u; return 0; }
r[0]=0x00000018u;
goto P_0c084bb4;
P_0c084bb4: /* original fa0c, guest PC 0x0c084bb4 */
if(!s->budget--) { s->failed_pc=0x0c084bb4u; return 0; }
vf3_matrix_move(s,10,0);
goto P_0c084bb6;
P_0c084bb6: /* original faf2, guest PC 0x0c084bb6 */
if(!s->budget--) { s->failed_pc=0x0c084bb6u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c084bb8;
P_0c084bb8: /* original f640, guest PC 0x0c084bb8 */
if(!s->budget--) { s->failed_pc=0x0c084bb8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c084bba;
P_0c084bba: /* original f9e6, guest PC 0x0c084bba */
if(!s->budget--) { s->failed_pc=0x0c084bbau; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c084bbc;
P_0c084bbc: /* original f431, guest PC 0x0c084bbc */
if(!s->budget--) { s->failed_pc=0x0c084bbcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c084bbe;
P_0c084bbe: /* original f7e8, guest PC 0x0c084bbe */
if(!s->budget--) { s->failed_pc=0x0c084bbeu; return 0; }
vf3_matrix_load(s,ram,7,r[14]);
goto P_0c084bc0;
P_0c084bc0: /* original f591, guest PC 0x0c084bc0 */
if(!s->budget--) { s->failed_pc=0x0c084bc0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'-');
goto P_0c084bc2;
P_0c084bc2: /* original f9cc, guest PC 0x0c084bc2 */
if(!s->budget--) { s->failed_pc=0x0c084bc2u; return 0; }
vf3_matrix_move(s,9,12);
goto P_0c084bc4;
P_0c084bc4: /* original f7e0, guest PC 0x0c084bc4 */
if(!s->budget--) { s->failed_pc=0x0c084bc4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'+');
goto P_0c084bc6;
P_0c084bc6: /* original f8a0, guest PC 0x0c084bc6 */
if(!s->budget--) { s->failed_pc=0x0c084bc6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'+');
goto P_0c084bc8;
P_0c084bc8: /* original f945, guest PC 0x0c084bc8 */
if(!s->budget--) { s->failed_pc=0x0c084bc8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c084bca;
P_0c084bca: /* original 8f02, guest PC 0x0c084bca */
if(!s->budget--) { s->failed_pc=0x0c084bcau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,10,13);
if(!cond) { goto P_0c084bd2; }
goto P_0c084bce;
P_0c084bcc: /* original fadc, guest PC 0x0c084bcc */
if(!s->budget--) { s->failed_pc=0x0c084bccu; return 0; }
vf3_matrix_move(s,10,13);
goto P_0c084bce;
P_0c084bce: /* original a003, guest PC 0x0c084bce */
if(!s->budget--) { s->failed_pc=0x0c084bceu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c084bd8;
P_0c084bd0: /* original f49c, guest PC 0x0c084bd0 */
if(!s->budget--) { s->failed_pc=0x0c084bd0u; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c084bd2;
P_0c084bd2: /* original f4a5, guest PC 0x0c084bd2 */
if(!s->budget--) { s->failed_pc=0x0c084bd2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[10]))!=0);
goto P_0c084bd4;
P_0c084bd4: /* original 8b00, guest PC 0x0c084bd4 */
if(!s->budget--) { s->failed_pc=0x0c084bd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084bd8; }
goto P_0c084bd6;
P_0c084bd6: /* original f4ac, guest PC 0x0c084bd6 */
if(!s->budget--) { s->failed_pc=0x0c084bd6u; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c084bd8;
P_0c084bd8: /* original e004, guest PC 0x0c084bd8 */
if(!s->budget--) { s->failed_pc=0x0c084bd8u; return 0; }
r[0]=0x00000004u;
goto P_0c084bda;
P_0c084bda: /* original fe7a, guest PC 0x0c084bda */
if(!s->budget--) { s->failed_pc=0x0c084bdau; return 0; }
vf3_matrix_store(s,ram,7,r[14]);
goto P_0c084bdc;
P_0c084bdc: /* original fe67, guest PC 0x0c084bdc */
if(!s->budget--) { s->failed_pc=0x0c084bdcu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c084bde;
P_0c084bde: /* original e008, guest PC 0x0c084bde */
if(!s->budget--) { s->failed_pc=0x0c084bdeu; return 0; }
r[0]=0x00000008u;
goto P_0c084be0;
P_0c084be0: /* original fe87, guest PC 0x0c084be0 */
if(!s->budget--) { s->failed_pc=0x0c084be0u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c084be2;
P_0c084be2: /* original e014, guest PC 0x0c084be2 */
if(!s->budget--) { s->failed_pc=0x0c084be2u; return 0; }
r[0]=0x00000014u;
goto P_0c084be4;
P_0c084be4: /* original fe57, guest PC 0x0c084be4 */
if(!s->budget--) { s->failed_pc=0x0c084be4u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c084be6;
P_0c084be6: /* original e00c, guest PC 0x0c084be6 */
if(!s->budget--) { s->failed_pc=0x0c084be6u; return 0; }
r[0]=0x0000000cu;
goto P_0c084be8;
P_0c084be8: /* original f38d, guest PC 0x0c084be8 */
if(!s->budget--) { s->failed_pc=0x0c084be8u; return 0; }
fr[3]=0;
goto P_0c084bea;
P_0c084bea: /* original f355, guest PC 0x0c084bea */
if(!s->budget--) { s->failed_pc=0x0c084beau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c084bec;
P_0c084bec: /* original 8d04, guest PC 0x0c084bec */
if(!s->budget--) { s->failed_pc=0x0c084becu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[14]+r[0]);
if(cond) { goto P_0c084bf8; }
goto P_0c084bf0;
P_0c084bee: /* original fe47, guest PC 0x0c084bee */
if(!s->budget--) { s->failed_pc=0x0c084beeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c084bf0;
P_0c084bf0: /* original e01c, guest PC 0x0c084bf0 */
if(!s->budget--) { s->failed_pc=0x0c084bf0u; return 0; }
r[0]=0x0000001cu;
goto P_0c084bf2;
P_0c084bf2: /* original f3e6, guest PC 0x0c084bf2 */
if(!s->budget--) { s->failed_pc=0x0c084bf2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c084bf4;
P_0c084bf4: /* original f365, guest PC 0x0c084bf4 */
if(!s->budget--) { s->failed_pc=0x0c084bf4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c084bf6;
P_0c084bf6: /* original 8902, guest PC 0x0c084bf6 */
if(!s->budget--) { s->failed_pc=0x0c084bf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084bfe; }
goto P_0c084bf8;
P_0c084bf8: /* original 65e3, guest PC 0x0c084bf8 */
if(!s->budget--) { s->failed_pc=0x0c084bf8u; return 0; }
r[5]=r[14];
goto P_0c084bfa;
P_0c084bfa: /* original bebf, guest PC 0x0c084bfa */
if(!s->budget--) { s->failed_pc=0x0c084bfau; return 0; }
target=code_base|0x0c08497cu; r[16]=code_base|0x0c084bfeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084bfeu) { target=s->pc; goto dispatch; }
goto P_0c084bfe;
P_0c084bfc: /* original 64d3, guest PC 0x0c084bfc */
if(!s->budget--) { s->failed_pc=0x0c084bfcu; return 0; }
r[4]=r[13];
goto P_0c084bfe;
P_0c084bfe: /* original 79ff, guest PC 0x0c084bfe */
if(!s->budget--) { s->failed_pc=0x0c084bfeu; return 0; }
r[9]+=0xffffffffu;
goto P_0c084c00;
P_0c084c00: /* original 7e2c, guest PC 0x0c084c00 */
if(!s->budget--) { s->failed_pc=0x0c084c00u; return 0; }
r[14]+=0x0000002cu;
goto P_0c084c02;
P_0c084c02: /* original 2998, guest PC 0x0c084c02 */
if(!s->budget--) { s->failed_pc=0x0c084c02u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c084c04;
P_0c084c04: /* original 8bb3, guest PC 0x0c084c04 */
if(!s->budget--) { s->failed_pc=0x0c084c04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084b6e; }
goto P_0c084c06;
P_0c084c06: /* original 52d2, guest PC 0x0c084c06 */
if(!s->budget--) { s->failed_pc=0x0c084c06u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c084c08;
P_0c084c08: /* original 7201, guest PC 0x0c084c08 */
if(!s->budget--) { s->failed_pc=0x0c084c08u; return 0; }
r[2]+=0x00000001u;
goto P_0c084c0a;
P_0c084c0a: /* original 6023, guest PC 0x0c084c0a */
if(!s->budget--) { s->failed_pc=0x0c084c0au; return 0; }
r[0]=r[2];
goto P_0c084c0c;
P_0c084c0c: /* original c97f, guest PC 0x0c084c0c */
if(!s->budget--) { s->failed_pc=0x0c084c0cu; return 0; }
r[0]&=127u;
goto P_0c084c0e;
P_0c084c0e: /* original 1d02, guest PC 0x0c084c0e */
if(!s->budget--) { s->failed_pc=0x0c084c0eu; return 0; }
write(ram,r[13]+8,r[0],4);
goto P_0c084c10;
P_0c084c10: /* original 7f04, guest PC 0x0c084c10 */
if(!s->budget--) { s->failed_pc=0x0c084c10u; return 0; }
r[15]+=0x00000004u;
goto P_0c084c12;
P_0c084c12: /* original 4f26, guest PC 0x0c084c12 */
if(!s->budget--) { s->failed_pc=0x0c084c12u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084c14;
P_0c084c14: /* original fcf9, guest PC 0x0c084c14 */
if(!s->budget--) { s->failed_pc=0x0c084c14u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084c16;
P_0c084c16: /* original fdf9, guest PC 0x0c084c16 */
if(!s->budget--) { s->failed_pc=0x0c084c16u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084c18;
P_0c084c18: /* original fef9, guest PC 0x0c084c18 */
if(!s->budget--) { s->failed_pc=0x0c084c18u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084c1a;
P_0c084c1a: /* original fff9, guest PC 0x0c084c1a */
if(!s->budget--) { s->failed_pc=0x0c084c1au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084c1c;
P_0c084c1c: /* original 69f6, guest PC 0x0c084c1c */
if(!s->budget--) { s->failed_pc=0x0c084c1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c084c1e;
P_0c084c1e: /* original 6af6, guest PC 0x0c084c1e */
if(!s->budget--) { s->failed_pc=0x0c084c1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c084c20;
P_0c084c20: /* original 6bf6, guest PC 0x0c084c20 */
if(!s->budget--) { s->failed_pc=0x0c084c20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c084c22;
P_0c084c22: /* original 6cf6, guest PC 0x0c084c22 */
if(!s->budget--) { s->failed_pc=0x0c084c22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084c24;
P_0c084c24: /* original 6df6, guest PC 0x0c084c24 */
if(!s->budget--) { s->failed_pc=0x0c084c24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084c26;
P_0c084c26: /* original 000b, guest PC 0x0c084c26 */
if(!s->budget--) { s->failed_pc=0x0c084c26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084c28: /* original 6ef6, guest PC 0x0c084c28 */
if(!s->budget--) { s->failed_pc=0x0c084c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c084c2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084c2au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
