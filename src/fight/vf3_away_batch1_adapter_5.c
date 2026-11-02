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
int vf3_away_batch1_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0369c8u: goto P_0c0369c8;
case 0x0c0369cau: goto P_0c0369ca;
case 0x0c0369ccu: goto P_0c0369cc;
case 0x0c0369ceu: goto P_0c0369ce;
case 0x0c0369d0u: goto P_0c0369d0;
case 0x0c0369d2u: goto P_0c0369d2;
case 0x0c0369d4u: goto P_0c0369d4;
case 0x0c0369d6u: goto P_0c0369d6;
case 0x0c0369d8u: goto P_0c0369d8;
case 0x0c0369dau: goto P_0c0369da;
case 0x0c0369dcu: goto P_0c0369dc;
case 0x0c0369deu: goto P_0c0369de;
case 0x0c0369e0u: goto P_0c0369e0;
case 0x0c0369e2u: goto P_0c0369e2;
case 0x0c0369e4u: goto P_0c0369e4;
case 0x0c0369e6u: goto P_0c0369e6;
case 0x0c0369e8u: goto P_0c0369e8;
case 0x0c0369eau: goto P_0c0369ea;
case 0x0c0369ecu: goto P_0c0369ec;
case 0x0c0369eeu: goto P_0c0369ee;
case 0x0c0369f0u: goto P_0c0369f0;
case 0x0c0369f2u: goto P_0c0369f2;
case 0x0c0369f4u: goto P_0c0369f4;
case 0x0c0369f6u: goto P_0c0369f6;
case 0x0c0369f8u: goto P_0c0369f8;
case 0x0c0369fau: goto P_0c0369fa;
case 0x0c0369fcu: goto P_0c0369fc;
case 0x0c0369feu: goto P_0c0369fe;
case 0x0c036a00u: goto P_0c036a00;
case 0x0c036a02u: goto P_0c036a02;
case 0x0c036a04u: goto P_0c036a04;
case 0x0c036a06u: goto P_0c036a06;
case 0x0c036a08u: goto P_0c036a08;
case 0x0c036a0au: goto P_0c036a0a;
case 0x0c036a0cu: goto P_0c036a0c;
case 0x0c036a0eu: goto P_0c036a0e;
case 0x0c036a10u: goto P_0c036a10;
case 0x0c036a12u: goto P_0c036a12;
case 0x0c036a14u: goto P_0c036a14;
case 0x0c036a16u: goto P_0c036a16;
case 0x0c036a18u: goto P_0c036a18;
case 0x0c036a1au: goto P_0c036a1a;
case 0x0c036a1cu: goto P_0c036a1c;
case 0x0c036a1eu: goto P_0c036a1e;
case 0x0c036a20u: goto P_0c036a20;
case 0x0c036a22u: goto P_0c036a22;
case 0x0c036a24u: goto P_0c036a24;
case 0x0c036a26u: goto P_0c036a26;
case 0x0c036a28u: goto P_0c036a28;
case 0x0c036a2au: goto P_0c036a2a;
case 0x0c036a2cu: goto P_0c036a2c;
case 0x0c036a2eu: goto P_0c036a2e;
case 0x0c036a30u: goto P_0c036a30;
case 0x0c036a32u: goto P_0c036a32;
case 0x0c036a34u: goto P_0c036a34;
case 0x0c036a36u: goto P_0c036a36;
case 0x0c036a38u: goto P_0c036a38;
case 0x0c036a3au: goto P_0c036a3a;
case 0x0c036a3cu: goto P_0c036a3c;
case 0x0c036a3eu: goto P_0c036a3e;
case 0x0c036a40u: goto P_0c036a40;
case 0x0c036a42u: goto P_0c036a42;
case 0x0c036a44u: goto P_0c036a44;
case 0x0c036a46u: goto P_0c036a46;
case 0x0c036a48u: goto P_0c036a48;
case 0x0c036a4au: goto P_0c036a4a;
case 0x0c036a4cu: goto P_0c036a4c;
case 0x0c036a4eu: goto P_0c036a4e;
case 0x0c036a50u: goto P_0c036a50;
case 0x0c036a52u: goto P_0c036a52;
case 0x0c036a54u: goto P_0c036a54;
case 0x0c036a56u: goto P_0c036a56;
case 0x0c036a58u: goto P_0c036a58;
case 0x0c036a5au: goto P_0c036a5a;
case 0x0c036a5cu: goto P_0c036a5c;
case 0x0c036a5eu: goto P_0c036a5e;
case 0x0c036a60u: goto P_0c036a60;
case 0x0c036a62u: goto P_0c036a62;
case 0x0c036a64u: goto P_0c036a64;
case 0x0c036a66u: goto P_0c036a66;
case 0x0c036a68u: goto P_0c036a68;
case 0x0c036a6au: goto P_0c036a6a;
case 0x0c036a6cu: goto P_0c036a6c;
case 0x0c036a6eu: goto P_0c036a6e;
case 0x0c036a70u: goto P_0c036a70;
case 0x0c036a72u: goto P_0c036a72;
case 0x0c036a74u: goto P_0c036a74;
case 0x0c036a76u: goto P_0c036a76;
case 0x0c036a78u: goto P_0c036a78;
case 0x0c036a7au: goto P_0c036a7a;
case 0x0c036a7cu: goto P_0c036a7c;
case 0x0c036a7eu: goto P_0c036a7e;
case 0x0c036a80u: goto P_0c036a80;
case 0x0c036a82u: goto P_0c036a82;
case 0x0c036a84u: goto P_0c036a84;
case 0x0c036a86u: goto P_0c036a86;
case 0x0c036a88u: goto P_0c036a88;
case 0x0c036a8au: goto P_0c036a8a;
case 0x0c036a8cu: goto P_0c036a8c;
case 0x0c036a8eu: goto P_0c036a8e;
case 0x0c036a90u: goto P_0c036a90;
case 0x0c036a92u: goto P_0c036a92;
case 0x0c036a94u: goto P_0c036a94;
case 0x0c036a96u: goto P_0c036a96;
case 0x0c036a98u: goto P_0c036a98;
case 0x0c036a9au: goto P_0c036a9a;
case 0x0c036a9cu: goto P_0c036a9c;
case 0x0c036a9eu: goto P_0c036a9e;
case 0x0c036aa0u: goto P_0c036aa0;
case 0x0c036aa2u: goto P_0c036aa2;
case 0x0c036aa4u: goto P_0c036aa4;
case 0x0c036aa6u: goto P_0c036aa6;
case 0x0c036aa8u: goto P_0c036aa8;
case 0x0c036aaau: goto P_0c036aaa;
case 0x0c036aacu: goto P_0c036aac;
case 0x0c036aaeu: goto P_0c036aae;
case 0x0c036ab0u: goto P_0c036ab0;
case 0x0c036ab2u: goto P_0c036ab2;
case 0x0c036ab4u: goto P_0c036ab4;
case 0x0c036ab6u: goto P_0c036ab6;
case 0x0c036ab8u: goto P_0c036ab8;
case 0x0c036abau: goto P_0c036aba;
case 0x0c036abcu: goto P_0c036abc;
case 0x0c036abeu: goto P_0c036abe;
case 0x0c036ac0u: goto P_0c036ac0;
case 0x0c036ac2u: goto P_0c036ac2;
case 0x0c036ac4u: goto P_0c036ac4;
case 0x0c036ac6u: goto P_0c036ac6;
case 0x0c036ac8u: goto P_0c036ac8;
case 0x0c036acau: goto P_0c036aca;
case 0x0c036accu: goto P_0c036acc;
case 0x0c036aceu: goto P_0c036ace;
case 0x0c036ad0u: goto P_0c036ad0;
case 0x0c036ad2u: goto P_0c036ad2;
case 0x0c036ad4u: goto P_0c036ad4;
case 0x0c036ad6u: goto P_0c036ad6;
case 0x0c036ad8u: goto P_0c036ad8;
case 0x0c036adau: goto P_0c036ada;
case 0x0c036adcu: goto P_0c036adc;
case 0x0c036adeu: goto P_0c036ade;
case 0x0c036ae0u: goto P_0c036ae0;
case 0x0c036ae2u: goto P_0c036ae2;
case 0x0c036ae4u: goto P_0c036ae4;
case 0x0c036ae6u: goto P_0c036ae6;
case 0x0c036b20u: goto P_0c036b20;
case 0x0c036b22u: goto P_0c036b22;
case 0x0c036b24u: goto P_0c036b24;
case 0x0c036b26u: goto P_0c036b26;
case 0x0c036b28u: goto P_0c036b28;
case 0x0c036b2au: goto P_0c036b2a;
case 0x0c036b2cu: goto P_0c036b2c;
case 0x0c036b2eu: goto P_0c036b2e;
case 0x0c036b30u: goto P_0c036b30;
case 0x0c036b32u: goto P_0c036b32;
case 0x0c036b34u: goto P_0c036b34;
case 0x0c036b36u: goto P_0c036b36;
case 0x0c036b38u: goto P_0c036b38;
case 0x0c036b3au: goto P_0c036b3a;
case 0x0c036b3cu: goto P_0c036b3c;
case 0x0c036b3eu: goto P_0c036b3e;
case 0x0c036b40u: goto P_0c036b40;
case 0x0c036b42u: goto P_0c036b42;
case 0x0c036b44u: goto P_0c036b44;
case 0x0c036b46u: goto P_0c036b46;
case 0x0c036b48u: goto P_0c036b48;
case 0x0c036b4au: goto P_0c036b4a;
case 0x0c036b4cu: goto P_0c036b4c;
case 0x0c036b4eu: goto P_0c036b4e;
case 0x0c036b50u: goto P_0c036b50;
case 0x0c036b52u: goto P_0c036b52;
case 0x0c036b54u: goto P_0c036b54;
case 0x0c036b56u: goto P_0c036b56;
case 0x0c036b58u: goto P_0c036b58;
case 0x0c036b5au: goto P_0c036b5a;
case 0x0c036b5cu: goto P_0c036b5c;
case 0x0c036b5eu: goto P_0c036b5e;
case 0x0c036b60u: goto P_0c036b60;
case 0x0c036b62u: goto P_0c036b62;
case 0x0c036b64u: goto P_0c036b64;
case 0x0c036b66u: goto P_0c036b66;
case 0x0c036b68u: goto P_0c036b68;
case 0x0c036b6au: goto P_0c036b6a;
case 0x0c036b6cu: goto P_0c036b6c;
case 0x0c036b6eu: goto P_0c036b6e;
case 0x0c036b70u: goto P_0c036b70;
case 0x0c036b72u: goto P_0c036b72;
case 0x0c036b74u: goto P_0c036b74;
case 0x0c036b76u: goto P_0c036b76;
case 0x0c036b78u: goto P_0c036b78;
case 0x0c036b7au: goto P_0c036b7a;
case 0x0c036b7cu: goto P_0c036b7c;
case 0x0c036b7eu: goto P_0c036b7e;
case 0x0c036b80u: goto P_0c036b80;
case 0x0c036b82u: goto P_0c036b82;
case 0x0c036b84u: goto P_0c036b84;
case 0x0c036b86u: goto P_0c036b86;
case 0x0c036b88u: goto P_0c036b88;
case 0x0c036b8au: goto P_0c036b8a;
case 0x0c036b8cu: goto P_0c036b8c;
case 0x0c036b8eu: goto P_0c036b8e;
case 0x0c036b90u: goto P_0c036b90;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0369c8: /* original 2fe6, guest PC 0x0c0369c8 */
if(!s->budget--) { s->failed_pc=0x0c0369c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0369ca;
P_0c0369ca: /* original e101, guest PC 0x0c0369ca */
if(!s->budget--) { s->failed_pc=0x0c0369cau; return 0; }
r[1]=0x00000001u;
goto P_0c0369cc;
P_0c0369cc: /* original 2fd6, guest PC 0x0c0369cc */
if(!s->budget--) { s->failed_pc=0x0c0369ccu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0369ce;
P_0c0369ce: /* original ed00, guest PC 0x0c0369ce */
if(!s->budget--) { s->failed_pc=0x0c0369ceu; return 0; }
r[13]=0x00000000u;
goto P_0c0369d0;
P_0c0369d0: /* original 2fc6, guest PC 0x0c0369d0 */
if(!s->budget--) { s->failed_pc=0x0c0369d0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0369d2;
P_0c0369d2: /* original 2fb6, guest PC 0x0c0369d2 */
if(!s->budget--) { s->failed_pc=0x0c0369d2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0369d4;
P_0c0369d4: /* original 2fa6, guest PC 0x0c0369d4 */
if(!s->budget--) { s->failed_pc=0x0c0369d4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0369d6;
P_0c0369d6: /* original 4f22, guest PC 0x0c0369d6 */
if(!s->budget--) { s->failed_pc=0x0c0369d6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0369d8;
P_0c0369d8: /* original 4f12, guest PC 0x0c0369d8 */
if(!s->budget--) { s->failed_pc=0x0c0369d8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0369da;
P_0c0369da: /* original 7ff8, guest PC 0x0c0369da */
if(!s->budget--) { s->failed_pc=0x0c0369dau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0369dc;
P_0c0369dc: /* original 1f51, guest PC 0x0c0369dc */
if(!s->budget--) { s->failed_pc=0x0c0369dcu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0369de;
P_0c0369de: /* original 2f62, guest PC 0x0c0369de */
if(!s->budget--) { s->failed_pc=0x0c0369deu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0369e0;
P_0c0369e0: /* original d542, guest PC 0x0c0369e0 */
if(!s->budget--) { s->failed_pc=0x0c0369e0u; return 0; }
r[5]=read(ram,0x0c036aecu,4);
goto P_0c0369e2;
P_0c0369e2: /* original 15d1, guest PC 0x0c0369e2 */
if(!s->budget--) { s->failed_pc=0x0c0369e2u; return 0; }
write(ram,r[5]+4,r[13],4);
goto P_0c0369e4;
P_0c0369e4: /* original 25d2, guest PC 0x0c0369e4 */
if(!s->budget--) { s->failed_pc=0x0c0369e4u; return 0; }
write(ram,r[5],r[13],4);
goto P_0c0369e6;
P_0c0369e6: /* original 65d3, guest PC 0x0c0369e6 */
if(!s->budget--) { s->failed_pc=0x0c0369e6u; return 0; }
r[5]=r[13];
goto P_0c0369e8;
P_0c0369e8: /* original d341, guest PC 0x0c0369e8 */
if(!s->budget--) { s->failed_pc=0x0c0369e8u; return 0; }
r[3]=read(ram,0x0c036af0u,4);
goto P_0c0369ea;
P_0c0369ea: /* original 2342, guest PC 0x0c0369ea */
if(!s->budget--) { s->failed_pc=0x0c0369eau; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0369ec;
P_0c0369ec: /* original d241, guest PC 0x0c0369ec */
if(!s->budget--) { s->failed_pc=0x0c0369ecu; return 0; }
r[2]=read(ram,0x0c036af4u,4);
goto P_0c0369ee;
P_0c0369ee: /* original 22d0, guest PC 0x0c0369ee */
if(!s->budget--) { s->failed_pc=0x0c0369eeu; return 0; }
write(ram,r[2],r[13],1);
goto P_0c0369f0;
P_0c0369f0: /* original d041, guest PC 0x0c0369f0 */
if(!s->budget--) { s->failed_pc=0x0c0369f0u; return 0; }
r[0]=read(ram,0x0c036af8u,4);
goto P_0c0369f2;
P_0c0369f2: /* original 2010, guest PC 0x0c0369f2 */
if(!s->budget--) { s->failed_pc=0x0c0369f2u; return 0; }
write(ram,r[0],r[1],1);
goto P_0c0369f4;
P_0c0369f4: /* original 9678, guest PC 0x0c0369f4 */
if(!s->budget--) { s->failed_pc=0x0c0369f4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036ae8u,2);
goto P_0c0369f6;
P_0c0369f6: /* original dc41, guest PC 0x0c0369f6 */
if(!s->budget--) { s->failed_pc=0x0c0369f6u; return 0; }
r[12]=read(ram,0x0c036afcu,4);
goto P_0c0369f8;
P_0c0369f8: /* original d341, guest PC 0x0c0369f8 */
if(!s->budget--) { s->failed_pc=0x0c0369f8u; return 0; }
r[3]=read(ram,0x0c036b00u,4);
goto P_0c0369fa;
P_0c0369fa: /* original 430b, guest PC 0x0c0369fa */
if(!s->budget--) { s->failed_pc=0x0c0369fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0369feu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0369feu) { target=s->pc; goto dispatch; }
goto P_0c0369fe;
P_0c0369fc: /* original 64c3, guest PC 0x0c0369fc */
if(!s->budget--) { s->failed_pc=0x0c0369fcu; return 0; }
r[4]=r[12];
goto P_0c0369fe;
P_0c0369fe: /* original da41, guest PC 0x0c0369fe */
if(!s->budget--) { s->failed_pc=0x0c0369feu; return 0; }
r[10]=read(ram,0x0c036b04u,4);
goto P_0c036a00;
P_0c036a00: /* original 6ed3, guest PC 0x0c036a00 */
if(!s->budget--) { s->failed_pc=0x0c036a00u; return 0; }
r[14]=r[13];
goto P_0c036a02;
P_0c036a02: /* original eb18, guest PC 0x0c036a02 */
if(!s->budget--) { s->failed_pc=0x0c036a02u; return 0; }
r[11]=0x00000018u;
goto P_0c036a04;
P_0c036a04: /* original e434, guest PC 0x0c036a04 */
if(!s->budget--) { s->failed_pc=0x0c036a04u; return 0; }
r[4]=0x00000034u;
goto P_0c036a06;
P_0c036a06: /* original 2e4f, guest PC 0x0c036a06 */
if(!s->budget--) { s->failed_pc=0x0c036a06u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[4]);
goto P_0c036a08;
P_0c036a08: /* original 041a, guest PC 0x0c036a08 */
if(!s->budget--) { s->failed_pc=0x0c036a08u; return 0; }
r[4]=r[19];
goto P_0c036a0a;
P_0c036a0a: /* original 644f, guest PC 0x0c036a0a */
if(!s->budget--) { s->failed_pc=0x0c036a0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c036a0c;
P_0c036a0c: /* original b024, guest PC 0x0c036a0c */
if(!s->budget--) { s->failed_pc=0x0c036a0cu; return 0; }
target=code_base|0x0c036a58u; r[16]=code_base|0x0c036a10u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036a10u) { target=s->pc; goto dispatch; }
goto P_0c036a10;
P_0c036a0e: /* original 34cc, guest PC 0x0c036a0e */
if(!s->budget--) { s->failed_pc=0x0c036a0eu; return 0; }
r[4]+=r[12];
goto P_0c036a10;
P_0c036a10: /* original 60e3, guest PC 0x0c036a10 */
if(!s->budget--) { s->failed_pc=0x0c036a10u; return 0; }
r[0]=r[14];
goto P_0c036a12;
P_0c036a12: /* original 7e01, guest PC 0x0c036a12 */
if(!s->budget--) { s->failed_pc=0x0c036a12u; return 0; }
r[14]+=0x00000001u;
goto P_0c036a14;
P_0c036a14: /* original 3eb3, guest PC 0x0c036a14 */
if(!s->budget--) { s->failed_pc=0x0c036a14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[11])!=0);
goto P_0c036a16;
P_0c036a16: /* original 4008, guest PC 0x0c036a16 */
if(!s->budget--) { s->failed_pc=0x0c036a16u; return 0; }
r[0]<<=2;
goto P_0c036a18;
P_0c036a18: /* original 8ff4, guest PC 0x0c036a18 */
if(!s->budget--) { s->failed_pc=0x0c036a18u; return 0; }
cond=r[17]&1u;
write(ram,r[10]+r[0],r[13],4);
if(!cond) { goto P_0c036a04; }
goto P_0c036a1c;
P_0c036a1a: /* original 0ad6, guest PC 0x0c036a1a */
if(!s->budget--) { s->failed_pc=0x0c036a1au; return 0; }
write(ram,r[10]+r[0],r[13],4);
goto P_0c036a1c;
P_0c036a1c: /* original 62f2, guest PC 0x0c036a1c */
if(!s->budget--) { s->failed_pc=0x0c036a1cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c036a1e;
P_0c036a1e: /* original 2228, guest PC 0x0c036a1e */
if(!s->budget--) { s->failed_pc=0x0c036a1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c036a20;
P_0c036a20: /* original 8911, guest PC 0x0c036a20 */
if(!s->budget--) { s->failed_pc=0x0c036a20u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036a46; }
goto P_0c036a22;
P_0c036a22: /* original 53f1, guest PC 0x0c036a22 */
if(!s->budget--) { s->failed_pc=0x0c036a22u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c036a24;
P_0c036a24: /* original 2338, guest PC 0x0c036a24 */
if(!s->budget--) { s->failed_pc=0x0c036a24u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c036a26;
P_0c036a26: /* original 890e, guest PC 0x0c036a26 */
if(!s->budget--) { s->failed_pc=0x0c036a26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036a46; }
goto P_0c036a28;
P_0c036a28: /* original d232, guest PC 0x0c036a28 */
if(!s->budget--) { s->failed_pc=0x0c036a28u; return 0; }
r[2]=read(ram,0x0c036af4u,4);
goto P_0c036a2a;
P_0c036a2a: /* original e301, guest PC 0x0c036a2a */
if(!s->budget--) { s->failed_pc=0x0c036a2au; return 0; }
r[3]=0x00000001u;
goto P_0c036a2c;
P_0c036a2c: /* original 2230, guest PC 0x0c036a2c */
if(!s->budget--) { s->failed_pc=0x0c036a2cu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c036a2e;
P_0c036a2e: /* original 64f2, guest PC 0x0c036a2e */
if(!s->budget--) { s->failed_pc=0x0c036a2eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c036a30;
P_0c036a30: /* original 55f1, guest PC 0x0c036a30 */
if(!s->budget--) { s->failed_pc=0x0c036a30u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c036a32;
P_0c036a32: /* original 7f08, guest PC 0x0c036a32 */
if(!s->budget--) { s->failed_pc=0x0c036a32u; return 0; }
r[15]+=0x00000008u;
goto P_0c036a34;
P_0c036a34: /* original 4f16, guest PC 0x0c036a34 */
if(!s->budget--) { s->failed_pc=0x0c036a34u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c036a36;
P_0c036a36: /* original d334, guest PC 0x0c036a36 */
if(!s->budget--) { s->failed_pc=0x0c036a36u; return 0; }
r[3]=read(ram,0x0c036b08u,4);
goto P_0c036a38;
P_0c036a38: /* original 4f26, guest PC 0x0c036a38 */
if(!s->budget--) { s->failed_pc=0x0c036a38u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036a3a;
P_0c036a3a: /* original 6af6, guest PC 0x0c036a3a */
if(!s->budget--) { s->failed_pc=0x0c036a3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c036a3c;
P_0c036a3c: /* original 6bf6, guest PC 0x0c036a3c */
if(!s->budget--) { s->failed_pc=0x0c036a3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c036a3e;
P_0c036a3e: /* original 6cf6, guest PC 0x0c036a3e */
if(!s->budget--) { s->failed_pc=0x0c036a3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036a40;
P_0c036a40: /* original 6df6, guest PC 0x0c036a40 */
if(!s->budget--) { s->failed_pc=0x0c036a40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036a42;
P_0c036a42: /* original 432b, guest PC 0x0c036a42 */
if(!s->budget--) { s->failed_pc=0x0c036a42u; return 0; }
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
P_0c036a44: /* original 6ef6, guest PC 0x0c036a44 */
if(!s->budget--) { s->failed_pc=0x0c036a44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c036a46;
P_0c036a46: /* original 7f08, guest PC 0x0c036a46 */
if(!s->budget--) { s->failed_pc=0x0c036a46u; return 0; }
r[15]+=0x00000008u;
goto P_0c036a48;
P_0c036a48: /* original 4f16, guest PC 0x0c036a48 */
if(!s->budget--) { s->failed_pc=0x0c036a48u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c036a4a;
P_0c036a4a: /* original 4f26, guest PC 0x0c036a4a */
if(!s->budget--) { s->failed_pc=0x0c036a4au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036a4c;
P_0c036a4c: /* original 6af6, guest PC 0x0c036a4c */
if(!s->budget--) { s->failed_pc=0x0c036a4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c036a4e;
P_0c036a4e: /* original 6bf6, guest PC 0x0c036a4e */
if(!s->budget--) { s->failed_pc=0x0c036a4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c036a50;
P_0c036a50: /* original 6cf6, guest PC 0x0c036a50 */
if(!s->budget--) { s->failed_pc=0x0c036a50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036a52;
P_0c036a52: /* original 6df6, guest PC 0x0c036a52 */
if(!s->budget--) { s->failed_pc=0x0c036a52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036a54;
P_0c036a54: /* original 000b, guest PC 0x0c036a54 */
if(!s->budget--) { s->failed_pc=0x0c036a54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036a56: /* original 6ef6, guest PC 0x0c036a56 */
if(!s->budget--) { s->failed_pc=0x0c036a56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c036a58;
P_0c036a58: /* original e500, guest PC 0x0c036a58 */
if(!s->budget--) { s->failed_pc=0x0c036a58u; return 0; }
r[5]=0x00000000u;
goto P_0c036a5a;
P_0c036a5a: /* original 2452, guest PC 0x0c036a5a */
if(!s->budget--) { s->failed_pc=0x0c036a5au; return 0; }
write(ram,r[4],r[5],4);
goto P_0c036a5c;
P_0c036a5c: /* original 1451, guest PC 0x0c036a5c */
if(!s->budget--) { s->failed_pc=0x0c036a5cu; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c036a5e;
P_0c036a5e: /* original d224, guest PC 0x0c036a5e */
if(!s->budget--) { s->failed_pc=0x0c036a5eu; return 0; }
r[2]=read(ram,0x0c036af0u,4);
goto P_0c036a60;
P_0c036a60: /* original 6322, guest PC 0x0c036a60 */
if(!s->budget--) { s->failed_pc=0x0c036a60u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c036a62;
P_0c036a62: /* original 2338, guest PC 0x0c036a62 */
if(!s->budget--) { s->failed_pc=0x0c036a62u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c036a64;
P_0c036a64: /* original 8f05, guest PC 0x0c036a64 */
if(!s->budget--) { s->failed_pc=0x0c036a64u; return 0; }
cond=r[17]&1u;
r[6]=0xffffffffu;
if(!cond) { goto P_0c036a72; }
goto P_0c036a68;
P_0c036a66: /* original e6ff, guest PC 0x0c036a66 */
if(!s->budget--) { s->failed_pc=0x0c036a66u; return 0; }
r[6]=0xffffffffu;
goto P_0c036a68;
P_0c036a68: /* original 1452, guest PC 0x0c036a68 */
if(!s->budget--) { s->failed_pc=0x0c036a68u; return 0; }
write(ram,r[4]+8,r[5],4);
goto P_0c036a6a;
P_0c036a6a: /* original 1463, guest PC 0x0c036a6a */
if(!s->budget--) { s->failed_pc=0x0c036a6au; return 0; }
write(ram,r[4]+12,r[6],4);
goto P_0c036a6c;
P_0c036a6c: /* original 1454, guest PC 0x0c036a6c */
if(!s->budget--) { s->failed_pc=0x0c036a6cu; return 0; }
write(ram,r[4]+16,r[5],4);
goto P_0c036a6e;
P_0c036a6e: /* original a004, guest PC 0x0c036a6e */
if(!s->budget--) { s->failed_pc=0x0c036a6eu; return 0; }
write(ram,r[4]+20,r[5],4);
goto P_0c036a7a;
P_0c036a70: /* original 1455, guest PC 0x0c036a70 */
if(!s->budget--) { s->failed_pc=0x0c036a70u; return 0; }
write(ram,r[4]+20,r[5],4);
goto P_0c036a72;
P_0c036a72: /* original 1462, guest PC 0x0c036a72 */
if(!s->budget--) { s->failed_pc=0x0c036a72u; return 0; }
write(ram,r[4]+8,r[6],4);
goto P_0c036a74;
P_0c036a74: /* original 1453, guest PC 0x0c036a74 */
if(!s->budget--) { s->failed_pc=0x0c036a74u; return 0; }
write(ram,r[4]+12,r[5],4);
goto P_0c036a76;
P_0c036a76: /* original 1464, guest PC 0x0c036a76 */
if(!s->budget--) { s->failed_pc=0x0c036a76u; return 0; }
write(ram,r[4]+16,r[6],4);
goto P_0c036a78;
P_0c036a78: /* original 1465, guest PC 0x0c036a78 */
if(!s->budget--) { s->failed_pc=0x0c036a78u; return 0; }
write(ram,r[4]+20,r[6],4);
goto P_0c036a7a;
P_0c036a7a: /* original 6053, guest PC 0x0c036a7a */
if(!s->budget--) { s->failed_pc=0x0c036a7au; return 0; }
r[0]=r[5];
goto P_0c036a7c;
P_0c036a7c: /* original 814c, guest PC 0x0c036a7c */
if(!s->budget--) { s->failed_pc=0x0c036a7cu; return 0; }
write(ram,r[4]+24,r[0],2);
goto P_0c036a7e;
P_0c036a7e: /* original 814d, guest PC 0x0c036a7e */
if(!s->budget--) { s->failed_pc=0x0c036a7eu; return 0; }
write(ram,r[4]+26,r[0],2);
goto P_0c036a80;
P_0c036a80: /* original e022, guest PC 0x0c036a80 */
if(!s->budget--) { s->failed_pc=0x0c036a80u; return 0; }
r[0]=0x00000022u;
goto P_0c036a82;
P_0c036a82: /* original 0455, guest PC 0x0c036a82 */
if(!s->budget--) { s->failed_pc=0x0c036a82u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c036a84;
P_0c036a84: /* original e020, guest PC 0x0c036a84 */
if(!s->budget--) { s->failed_pc=0x0c036a84u; return 0; }
r[0]=0x00000020u;
goto P_0c036a86;
P_0c036a86: /* original 0455, guest PC 0x0c036a86 */
if(!s->budget--) { s->failed_pc=0x0c036a86u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c036a88;
P_0c036a88: /* original 6053, guest PC 0x0c036a88 */
if(!s->budget--) { s->failed_pc=0x0c036a88u; return 0; }
r[0]=r[5];
goto P_0c036a8a;
P_0c036a8a: /* original 814f, guest PC 0x0c036a8a */
if(!s->budget--) { s->failed_pc=0x0c036a8au; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c036a8c;
P_0c036a8c: /* original 814e, guest PC 0x0c036a8c */
if(!s->budget--) { s->failed_pc=0x0c036a8cu; return 0; }
write(ram,r[4]+28,r[0],2);
goto P_0c036a8e;
P_0c036a8e: /* original 140a, guest PC 0x0c036a8e */
if(!s->budget--) { s->failed_pc=0x0c036a8eu; return 0; }
write(ram,r[4]+40,r[0],4);
goto P_0c036a90;
P_0c036a90: /* original d31e, guest PC 0x0c036a90 */
if(!s->budget--) { s->failed_pc=0x0c036a90u; return 0; }
r[3]=read(ram,0x0c036b0cu,4);
goto P_0c036a92;
P_0c036a92: /* original 000b, guest PC 0x0c036a92 */
if(!s->budget--) { s->failed_pc=0x0c036a92u; return 0; }
target=r[16];
write(ram,r[4]+36,r[3],4);
s->pc=target; return ram->oob==0;
P_0c036a94: /* original 1439, guest PC 0x0c036a94 */
if(!s->budget--) { s->failed_pc=0x0c036a94u; return 0; }
write(ram,r[4]+36,r[3],4);
goto P_0c036a96;
P_0c036a96: /* original 2fe6, guest PC 0x0c036a96 */
if(!s->budget--) { s->failed_pc=0x0c036a96u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036a98;
P_0c036a98: /* original 5552, guest PC 0x0c036a98 */
if(!s->budget--) { s->failed_pc=0x0c036a98u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c036a9a;
P_0c036a9a: /* original d31d, guest PC 0x0c036a9a */
if(!s->budget--) { s->failed_pc=0x0c036a9au; return 0; }
r[3]=read(ram,0x0c036b10u,4);
goto P_0c036a9c;
P_0c036a9c: /* original 7508, guest PC 0x0c036a9c */
if(!s->budget--) { s->failed_pc=0x0c036a9cu; return 0; }
r[5]+=0x00000008u;
goto P_0c036a9e;
P_0c036a9e: /* original 8451, guest PC 0x0c036a9e */
if(!s->budget--) { s->failed_pc=0x0c036a9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+1,1);
goto P_0c036aa0;
P_0c036aa0: /* original 6753, guest PC 0x0c036aa0 */
if(!s->budget--) { s->failed_pc=0x0c036aa0u; return 0; }
r[7]=r[5];
goto P_0c036aa2;
P_0c036aa2: /* original 6650, guest PC 0x0c036aa2 */
if(!s->budget--) { s->failed_pc=0x0c036aa2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[6]=tmp;
goto P_0c036aa4;
P_0c036aa4: /* original 7703, guest PC 0x0c036aa4 */
if(!s->budget--) { s->failed_pc=0x0c036aa4u; return 0; }
r[7]+=0x00000003u;
goto P_0c036aa6;
P_0c036aa6: /* original 600c, guest PC 0x0c036aa6 */
if(!s->budget--) { s->failed_pc=0x0c036aa6u; return 0; }
r[0]=r[0]&255u;
goto P_0c036aa8;
P_0c036aa8: /* original 666c, guest PC 0x0c036aa8 */
if(!s->budget--) { s->failed_pc=0x0c036aa8u; return 0; }
r[6]=r[6]&255u;
goto P_0c036aaa;
P_0c036aaa: /* original 4018, guest PC 0x0c036aaa */
if(!s->budget--) { s->failed_pc=0x0c036aaau; return 0; }
r[0]<<=8;
goto P_0c036aac;
P_0c036aac: /* original 260b, guest PC 0x0c036aac */
if(!s->budget--) { s->failed_pc=0x0c036aacu; return 0; }
r[6]|=r[0];
goto P_0c036aae;
P_0c036aae: /* original 6070, guest PC 0x0c036aae */
if(!s->budget--) { s->failed_pc=0x0c036aaeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[0]=tmp;
goto P_0c036ab0;
P_0c036ab0: /* original 600c, guest PC 0x0c036ab0 */
if(!s->budget--) { s->failed_pc=0x0c036ab0u; return 0; }
r[0]=r[0]&255u;
goto P_0c036ab2;
P_0c036ab2: /* original c880, guest PC 0x0c036ab2 */
if(!s->budget--) { s->failed_pc=0x0c036ab2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c036ab4;
P_0c036ab4: /* original 8d02, guest PC 0x0c036ab4 */
if(!s->budget--) { s->failed_pc=0x0c036ab4u; return 0; }
cond=r[17]&1u;
r[6]|=r[3];
if(cond) { goto P_0c036abc; }
goto P_0c036ab8;
P_0c036ab6: /* original 263b, guest PC 0x0c036ab6 */
if(!s->budget--) { s->failed_pc=0x0c036ab6u; return 0; }
r[6]|=r[3];
goto P_0c036ab8;
P_0c036ab8: /* original d116, guest PC 0x0c036ab8 */
if(!s->budget--) { s->failed_pc=0x0c036ab8u; return 0; }
r[1]=read(ram,0x0c036b14u,4);
goto P_0c036aba;
P_0c036aba: /* original 2619, guest PC 0x0c036aba */
if(!s->budget--) { s->failed_pc=0x0c036abau; return 0; }
r[6]&=r[1];
goto P_0c036abc;
P_0c036abc: /* original 6e53, guest PC 0x0c036abc */
if(!s->budget--) { s->failed_pc=0x0c036abcu; return 0; }
r[14]=r[5];
goto P_0c036abe;
P_0c036abe: /* original 7e02, guest PC 0x0c036abe */
if(!s->budget--) { s->failed_pc=0x0c036abeu; return 0; }
r[14]+=0x00000002u;
goto P_0c036ac0;
P_0c036ac0: /* original 60e0, guest PC 0x0c036ac0 */
if(!s->budget--) { s->failed_pc=0x0c036ac0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c036ac2;
P_0c036ac2: /* original 600c, guest PC 0x0c036ac2 */
if(!s->budget--) { s->failed_pc=0x0c036ac2u; return 0; }
r[0]=r[0]&255u;
goto P_0c036ac4;
P_0c036ac4: /* original c880, guest PC 0x0c036ac4 */
if(!s->budget--) { s->failed_pc=0x0c036ac4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c036ac6;
P_0c036ac6: /* original 8901, guest PC 0x0c036ac6 */
if(!s->budget--) { s->failed_pc=0x0c036ac6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036acc; }
goto P_0c036ac8;
P_0c036ac8: /* original d213, guest PC 0x0c036ac8 */
if(!s->budget--) { s->failed_pc=0x0c036ac8u; return 0; }
r[2]=read(ram,0x0c036b18u,4);
goto P_0c036aca;
P_0c036aca: /* original 2629, guest PC 0x0c036aca */
if(!s->budget--) { s->failed_pc=0x0c036acau; return 0; }
r[6]&=r[2];
goto P_0c036acc;
P_0c036acc: /* original d108, guest PC 0x0c036acc */
if(!s->budget--) { s->failed_pc=0x0c036accu; return 0; }
r[1]=read(ram,0x0c036af0u,4);
goto P_0c036ace;
P_0c036ace: /* original 6312, guest PC 0x0c036ace */
if(!s->budget--) { s->failed_pc=0x0c036aceu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c036ad0;
P_0c036ad0: /* original 2338, guest PC 0x0c036ad0 */
if(!s->budget--) { s->failed_pc=0x0c036ad0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c036ad2;
P_0c036ad2: /* original 8b01, guest PC 0x0c036ad2 */
if(!s->budget--) { s->failed_pc=0x0c036ad2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036ad8; }
goto P_0c036ad4;
P_0c036ad4: /* original e3ff, guest PC 0x0c036ad4 */
if(!s->budget--) { s->failed_pc=0x0c036ad4u; return 0; }
r[3]=0xffffffffu;
goto P_0c036ad6;
P_0c036ad6: /* original 263a, guest PC 0x0c036ad6 */
if(!s->budget--) { s->failed_pc=0x0c036ad6u; return 0; }
r[6]^=r[3];
goto P_0c036ad8;
P_0c036ad8: /* original 1462, guest PC 0x0c036ad8 */
if(!s->budget--) { s->failed_pc=0x0c036ad8u; return 0; }
write(ram,r[4]+8,r[6],4);
goto P_0c036ada;
P_0c036ada: /* original 5041, guest PC 0x0c036ada */
if(!s->budget--) { s->failed_pc=0x0c036adau; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c036adc;
P_0c036adc: /* original d30f, guest PC 0x0c036adc */
if(!s->budget--) { s->failed_pc=0x0c036adcu; return 0; }
r[3]=read(ram,0x0c036b1cu,4);
goto P_0c036ade;
P_0c036ade: /* original 2038, guest PC 0x0c036ade */
if(!s->budget--) { s->failed_pc=0x0c036adeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c036ae0;
P_0c036ae0: /* original 891e, guest PC 0x0c036ae0 */
if(!s->budget--) { s->failed_pc=0x0c036ae0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036b20; }
goto P_0c036ae2;
P_0c036ae2: /* original 60e0, guest PC 0x0c036ae2 */
if(!s->budget--) { s->failed_pc=0x0c036ae2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c036ae4;
P_0c036ae4: /* original a01d, guest PC 0x0c036ae4 */
if(!s->budget--) { s->failed_pc=0x0c036ae4u; return 0; }
r[0]=r[0]&255u;
goto P_0c036b22;
P_0c036ae6: /* original 600c, guest PC 0x0c036ae6 */
if(!s->budget--) { s->failed_pc=0x0c036ae6u; return 0; }
r[0]=r[0]&255u;
if(!vf3_matrix_family(0x0c036ae8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036ae8u; return 0; } return 1;
P_0c036b20: /* original e000, guest PC 0x0c036b20 */
if(!s->budget--) { s->failed_pc=0x0c036b20u; return 0; }
r[0]=0x00000000u;
goto P_0c036b22;
P_0c036b22: /* original 814c, guest PC 0x0c036b22 */
if(!s->budget--) { s->failed_pc=0x0c036b22u; return 0; }
write(ram,r[4]+24,r[0],2);
goto P_0c036b24;
P_0c036b24: /* original 5041, guest PC 0x0c036b24 */
if(!s->budget--) { s->failed_pc=0x0c036b24u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c036b26;
P_0c036b26: /* original d332, guest PC 0x0c036b26 */
if(!s->budget--) { s->failed_pc=0x0c036b26u; return 0; }
r[3]=read(ram,0x0c036bf0u,4);
goto P_0c036b28;
P_0c036b28: /* original 2038, guest PC 0x0c036b28 */
if(!s->budget--) { s->failed_pc=0x0c036b28u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c036b2a;
P_0c036b2a: /* original 8902, guest PC 0x0c036b2a */
if(!s->budget--) { s->failed_pc=0x0c036b2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036b32; }
goto P_0c036b2c;
P_0c036b2c: /* original 6070, guest PC 0x0c036b2c */
if(!s->budget--) { s->failed_pc=0x0c036b2cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[0]=tmp;
goto P_0c036b2e;
P_0c036b2e: /* original a001, guest PC 0x0c036b2e */
if(!s->budget--) { s->failed_pc=0x0c036b2eu; return 0; }
r[0]=r[0]&255u;
goto P_0c036b34;
P_0c036b30: /* original 600c, guest PC 0x0c036b30 */
if(!s->budget--) { s->failed_pc=0x0c036b30u; return 0; }
r[0]=r[0]&255u;
goto P_0c036b32;
P_0c036b32: /* original e000, guest PC 0x0c036b32 */
if(!s->budget--) { s->failed_pc=0x0c036b32u; return 0; }
r[0]=0x00000000u;
goto P_0c036b34;
P_0c036b34: /* original 814d, guest PC 0x0c036b34 */
if(!s->budget--) { s->failed_pc=0x0c036b34u; return 0; }
write(ram,r[4]+26,r[0],2);
goto P_0c036b36;
P_0c036b36: /* original 5041, guest PC 0x0c036b36 */
if(!s->budget--) { s->failed_pc=0x0c036b36u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c036b38;
P_0c036b38: /* original d32e, guest PC 0x0c036b38 */
if(!s->budget--) { s->failed_pc=0x0c036b38u; return 0; }
r[3]=read(ram,0x0c036bf4u,4);
goto P_0c036b3a;
P_0c036b3a: /* original 2038, guest PC 0x0c036b3a */
if(!s->budget--) { s->failed_pc=0x0c036b3au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c036b3c;
P_0c036b3c: /* original 8903, guest PC 0x0c036b3c */
if(!s->budget--) { s->failed_pc=0x0c036b3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036b46; }
goto P_0c036b3e;
P_0c036b3e: /* original 8454, guest PC 0x0c036b3e */
if(!s->budget--) { s->failed_pc=0x0c036b3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c036b40;
P_0c036b40: /* original 600c, guest PC 0x0c036b40 */
if(!s->budget--) { s->failed_pc=0x0c036b40u; return 0; }
r[0]=r[0]&255u;
goto P_0c036b42;
P_0c036b42: /* original a001, guest PC 0x0c036b42 */
if(!s->budget--) { s->failed_pc=0x0c036b42u; return 0; }
r[0]+=0xffffff80u;
goto P_0c036b48;
P_0c036b44: /* original 7080, guest PC 0x0c036b44 */
if(!s->budget--) { s->failed_pc=0x0c036b44u; return 0; }
r[0]+=0xffffff80u;
goto P_0c036b46;
P_0c036b46: /* original e000, guest PC 0x0c036b46 */
if(!s->budget--) { s->failed_pc=0x0c036b46u; return 0; }
r[0]=0x00000000u;
goto P_0c036b48;
P_0c036b48: /* original 814e, guest PC 0x0c036b48 */
if(!s->budget--) { s->failed_pc=0x0c036b48u; return 0; }
write(ram,r[4]+28,r[0],2);
goto P_0c036b4a;
P_0c036b4a: /* original 5041, guest PC 0x0c036b4a */
if(!s->budget--) { s->failed_pc=0x0c036b4au; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c036b4c;
P_0c036b4c: /* original d32a, guest PC 0x0c036b4c */
if(!s->budget--) { s->failed_pc=0x0c036b4cu; return 0; }
r[3]=read(ram,0x0c036bf8u,4);
goto P_0c036b4e;
P_0c036b4e: /* original 2038, guest PC 0x0c036b4e */
if(!s->budget--) { s->failed_pc=0x0c036b4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c036b50;
P_0c036b50: /* original 8903, guest PC 0x0c036b50 */
if(!s->budget--) { s->failed_pc=0x0c036b50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036b5a; }
goto P_0c036b52;
P_0c036b52: /* original 8455, guest PC 0x0c036b52 */
if(!s->budget--) { s->failed_pc=0x0c036b52u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c036b54;
P_0c036b54: /* original 600c, guest PC 0x0c036b54 */
if(!s->budget--) { s->failed_pc=0x0c036b54u; return 0; }
r[0]=r[0]&255u;
goto P_0c036b56;
P_0c036b56: /* original a001, guest PC 0x0c036b56 */
if(!s->budget--) { s->failed_pc=0x0c036b56u; return 0; }
r[0]+=0xffffff80u;
goto P_0c036b5c;
P_0c036b58: /* original 7080, guest PC 0x0c036b58 */
if(!s->budget--) { s->failed_pc=0x0c036b58u; return 0; }
r[0]+=0xffffff80u;
goto P_0c036b5a;
P_0c036b5a: /* original e000, guest PC 0x0c036b5a */
if(!s->budget--) { s->failed_pc=0x0c036b5au; return 0; }
r[0]=0x00000000u;
goto P_0c036b5c;
P_0c036b5c: /* original 814f, guest PC 0x0c036b5c */
if(!s->budget--) { s->failed_pc=0x0c036b5cu; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c036b5e;
P_0c036b5e: /* original 5241, guest PC 0x0c036b5e */
if(!s->budget--) { s->failed_pc=0x0c036b5eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c036b60;
P_0c036b60: /* original d326, guest PC 0x0c036b60 */
if(!s->budget--) { s->failed_pc=0x0c036b60u; return 0; }
r[3]=read(ram,0x0c036bfcu,4);
goto P_0c036b62;
P_0c036b62: /* original 2238, guest PC 0x0c036b62 */
if(!s->budget--) { s->failed_pc=0x0c036b62u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c036b64;
P_0c036b64: /* original 8904, guest PC 0x0c036b64 */
if(!s->budget--) { s->failed_pc=0x0c036b64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036b70; }
goto P_0c036b66;
P_0c036b66: /* original 8456, guest PC 0x0c036b66 */
if(!s->budget--) { s->failed_pc=0x0c036b66u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+6,1);
goto P_0c036b68;
P_0c036b68: /* original 600c, guest PC 0x0c036b68 */
if(!s->budget--) { s->failed_pc=0x0c036b68u; return 0; }
r[0]=r[0]&255u;
goto P_0c036b6a;
P_0c036b6a: /* original 6203, guest PC 0x0c036b6a */
if(!s->budget--) { s->failed_pc=0x0c036b6au; return 0; }
r[2]=r[0];
goto P_0c036b6c;
P_0c036b6c: /* original a001, guest PC 0x0c036b6c */
if(!s->budget--) { s->failed_pc=0x0c036b6cu; return 0; }
r[2]+=0xffffff80u;
goto P_0c036b72;
P_0c036b6e: /* original 7280, guest PC 0x0c036b6e */
if(!s->budget--) { s->failed_pc=0x0c036b6eu; return 0; }
r[2]+=0xffffff80u;
goto P_0c036b70;
P_0c036b70: /* original e200, guest PC 0x0c036b70 */
if(!s->budget--) { s->failed_pc=0x0c036b70u; return 0; }
r[2]=0x00000000u;
goto P_0c036b72;
P_0c036b72: /* original e020, guest PC 0x0c036b72 */
if(!s->budget--) { s->failed_pc=0x0c036b72u; return 0; }
r[0]=0x00000020u;
goto P_0c036b74;
P_0c036b74: /* original 0425, guest PC 0x0c036b74 */
if(!s->budget--) { s->failed_pc=0x0c036b74u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c036b76;
P_0c036b76: /* original d322, guest PC 0x0c036b76 */
if(!s->budget--) { s->failed_pc=0x0c036b76u; return 0; }
r[3]=read(ram,0x0c036c00u,4);
goto P_0c036b78;
P_0c036b78: /* original 5141, guest PC 0x0c036b78 */
if(!s->budget--) { s->failed_pc=0x0c036b78u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c036b7a;
P_0c036b7a: /* original 2138, guest PC 0x0c036b7a */
if(!s->budget--) { s->failed_pc=0x0c036b7au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c036b7c;
P_0c036b7c: /* original 8904, guest PC 0x0c036b7c */
if(!s->budget--) { s->failed_pc=0x0c036b7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036b88; }
goto P_0c036b7e;
P_0c036b7e: /* original 8457, guest PC 0x0c036b7e */
if(!s->budget--) { s->failed_pc=0x0c036b7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+7,1);
goto P_0c036b80;
P_0c036b80: /* original 600c, guest PC 0x0c036b80 */
if(!s->budget--) { s->failed_pc=0x0c036b80u; return 0; }
r[0]=r[0]&255u;
goto P_0c036b82;
P_0c036b82: /* original 6303, guest PC 0x0c036b82 */
if(!s->budget--) { s->failed_pc=0x0c036b82u; return 0; }
r[3]=r[0];
goto P_0c036b84;
P_0c036b84: /* original a001, guest PC 0x0c036b84 */
if(!s->budget--) { s->failed_pc=0x0c036b84u; return 0; }
r[3]+=0xffffff80u;
goto P_0c036b8a;
P_0c036b86: /* original 7380, guest PC 0x0c036b86 */
if(!s->budget--) { s->failed_pc=0x0c036b86u; return 0; }
r[3]+=0xffffff80u;
goto P_0c036b88;
P_0c036b88: /* original e300, guest PC 0x0c036b88 */
if(!s->budget--) { s->failed_pc=0x0c036b88u; return 0; }
r[3]=0x00000000u;
goto P_0c036b8a;
P_0c036b8a: /* original e022, guest PC 0x0c036b8a */
if(!s->budget--) { s->failed_pc=0x0c036b8au; return 0; }
r[0]=0x00000022u;
goto P_0c036b8c;
P_0c036b8c: /* original 0435, guest PC 0x0c036b8c */
if(!s->budget--) { s->failed_pc=0x0c036b8cu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c036b8e;
P_0c036b8e: /* original 000b, guest PC 0x0c036b8e */
if(!s->budget--) { s->failed_pc=0x0c036b8eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036b90: /* original 6ef6, guest PC 0x0c036b90 */
if(!s->budget--) { s->failed_pc=0x0c036b90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c036b92u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
