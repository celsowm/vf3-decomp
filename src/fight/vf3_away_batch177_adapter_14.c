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
int vf3_away_batch177_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b10a8u: goto P_0c0b10a8;
case 0x0c0b10aau: goto P_0c0b10aa;
case 0x0c0b10acu: goto P_0c0b10ac;
case 0x0c0b10aeu: goto P_0c0b10ae;
case 0x0c0b10b0u: goto P_0c0b10b0;
case 0x0c0b10b2u: goto P_0c0b10b2;
case 0x0c0b10b4u: goto P_0c0b10b4;
case 0x0c0b10b6u: goto P_0c0b10b6;
case 0x0c0b10b8u: goto P_0c0b10b8;
case 0x0c0b10bau: goto P_0c0b10ba;
case 0x0c0b10bcu: goto P_0c0b10bc;
case 0x0c0b10beu: goto P_0c0b10be;
case 0x0c0b10c0u: goto P_0c0b10c0;
case 0x0c0b10c2u: goto P_0c0b10c2;
case 0x0c0b10c4u: goto P_0c0b10c4;
case 0x0c0b10c6u: goto P_0c0b10c6;
case 0x0c0b10c8u: goto P_0c0b10c8;
case 0x0c0b10cau: goto P_0c0b10ca;
case 0x0c0b10ccu: goto P_0c0b10cc;
case 0x0c0b10ceu: goto P_0c0b10ce;
case 0x0c0b10d0u: goto P_0c0b10d0;
case 0x0c0b10d2u: goto P_0c0b10d2;
case 0x0c0b10d4u: goto P_0c0b10d4;
case 0x0c0b10d6u: goto P_0c0b10d6;
case 0x0c0b10d8u: goto P_0c0b10d8;
case 0x0c0b10dau: goto P_0c0b10da;
case 0x0c0b10dcu: goto P_0c0b10dc;
case 0x0c0b10deu: goto P_0c0b10de;
case 0x0c0b10e0u: goto P_0c0b10e0;
case 0x0c0b10e2u: goto P_0c0b10e2;
case 0x0c0b10e4u: goto P_0c0b10e4;
case 0x0c0b10e6u: goto P_0c0b10e6;
case 0x0c0b10e8u: goto P_0c0b10e8;
case 0x0c0b10eau: goto P_0c0b10ea;
case 0x0c0b10ecu: goto P_0c0b10ec;
case 0x0c0b10eeu: goto P_0c0b10ee;
case 0x0c0b10f0u: goto P_0c0b10f0;
case 0x0c0b10f2u: goto P_0c0b10f2;
case 0x0c0b10f4u: goto P_0c0b10f4;
case 0x0c0b10f6u: goto P_0c0b10f6;
case 0x0c0b10f8u: goto P_0c0b10f8;
case 0x0c0b10fau: goto P_0c0b10fa;
case 0x0c0b10fcu: goto P_0c0b10fc;
case 0x0c0b10feu: goto P_0c0b10fe;
case 0x0c0b1100u: goto P_0c0b1100;
case 0x0c0b1102u: goto P_0c0b1102;
case 0x0c0b1104u: goto P_0c0b1104;
case 0x0c0b1106u: goto P_0c0b1106;
case 0x0c0b1108u: goto P_0c0b1108;
case 0x0c0b110au: goto P_0c0b110a;
case 0x0c0b110cu: goto P_0c0b110c;
case 0x0c0b110eu: goto P_0c0b110e;
case 0x0c0b1110u: goto P_0c0b1110;
case 0x0c0b1112u: goto P_0c0b1112;
case 0x0c0b1114u: goto P_0c0b1114;
case 0x0c0b1116u: goto P_0c0b1116;
case 0x0c0b1118u: goto P_0c0b1118;
case 0x0c0b111au: goto P_0c0b111a;
case 0x0c0b111cu: goto P_0c0b111c;
case 0x0c0b111eu: goto P_0c0b111e;
case 0x0c0b1120u: goto P_0c0b1120;
case 0x0c0b1122u: goto P_0c0b1122;
case 0x0c0b1124u: goto P_0c0b1124;
case 0x0c0b1126u: goto P_0c0b1126;
case 0x0c0b1128u: goto P_0c0b1128;
case 0x0c0b112au: goto P_0c0b112a;
case 0x0c0b112cu: goto P_0c0b112c;
case 0x0c0b112eu: goto P_0c0b112e;
case 0x0c0b1130u: goto P_0c0b1130;
case 0x0c0b1132u: goto P_0c0b1132;
case 0x0c0c5c94u: goto P_0c0c5c94;
case 0x0c0c5c96u: goto P_0c0c5c96;
case 0x0c0c5c98u: goto P_0c0c5c98;
case 0x0c0c5c9au: goto P_0c0c5c9a;
case 0x0c0c5c9cu: goto P_0c0c5c9c;
case 0x0c0c5c9eu: goto P_0c0c5c9e;
case 0x0c0c5ca0u: goto P_0c0c5ca0;
case 0x0c0c5ca2u: goto P_0c0c5ca2;
case 0x0c0c5ca4u: goto P_0c0c5ca4;
case 0x0c0c5ca6u: goto P_0c0c5ca6;
case 0x0c0c5ca8u: goto P_0c0c5ca8;
case 0x0c0c5caau: goto P_0c0c5caa;
case 0x0c0c5cacu: goto P_0c0c5cac;
case 0x0c0c5caeu: goto P_0c0c5cae;
case 0x0c0c5cb0u: goto P_0c0c5cb0;
case 0x0c0c5cf4u: goto P_0c0c5cf4;
case 0x0c0c5cf6u: goto P_0c0c5cf6;
case 0x0c0c5cf8u: goto P_0c0c5cf8;
case 0x0c0c5cfau: goto P_0c0c5cfa;
case 0x0c0c5cfcu: goto P_0c0c5cfc;
case 0x0c0c5cfeu: goto P_0c0c5cfe;
case 0x0c0c5d00u: goto P_0c0c5d00;
case 0x0c0c5d02u: goto P_0c0c5d02;
case 0x0c0c5d04u: goto P_0c0c5d04;
case 0x0c0c5d06u: goto P_0c0c5d06;
case 0x0c0c5d08u: goto P_0c0c5d08;
case 0x0c0c5d0au: goto P_0c0c5d0a;
case 0x0c0c5d0cu: goto P_0c0c5d0c;
case 0x0c0c5d0eu: goto P_0c0c5d0e;
case 0x0c0c5d10u: goto P_0c0c5d10;
case 0x0c0c5d12u: goto P_0c0c5d12;
case 0x0c0c5d14u: goto P_0c0c5d14;
case 0x0c0c5d16u: goto P_0c0c5d16;
case 0x0c0c5d18u: goto P_0c0c5d18;
case 0x0c0c5d1au: goto P_0c0c5d1a;
case 0x0c0c5d1cu: goto P_0c0c5d1c;
case 0x0c0c5d1eu: goto P_0c0c5d1e;
case 0x0c0c5d20u: goto P_0c0c5d20;
case 0x0c0c5d22u: goto P_0c0c5d22;
case 0x0c0c5d24u: goto P_0c0c5d24;
case 0x0c0c5d26u: goto P_0c0c5d26;
case 0x0c0c5d28u: goto P_0c0c5d28;
case 0x0c0c5d2au: goto P_0c0c5d2a;
case 0x0c0c5d2cu: goto P_0c0c5d2c;
case 0x0c0c5d2eu: goto P_0c0c5d2e;
case 0x0c0c5d30u: goto P_0c0c5d30;
case 0x0c0c5d32u: goto P_0c0c5d32;
case 0x0c0c5d34u: goto P_0c0c5d34;
case 0x0c0c5d36u: goto P_0c0c5d36;
case 0x0c0c5d38u: goto P_0c0c5d38;
case 0x0c0c5d3au: goto P_0c0c5d3a;
case 0x0c0c5d3cu: goto P_0c0c5d3c;
case 0x0c0c5d3eu: goto P_0c0c5d3e;
case 0x0c0c5d40u: goto P_0c0c5d40;
case 0x0c0c5d42u: goto P_0c0c5d42;
case 0x0c0c5d44u: goto P_0c0c5d44;
case 0x0c0c5d46u: goto P_0c0c5d46;
case 0x0c0c5d48u: goto P_0c0c5d48;
case 0x0c0c5d4au: goto P_0c0c5d4a;
case 0x0c0c5d4cu: goto P_0c0c5d4c;
case 0x0c0c5d4eu: goto P_0c0c5d4e;
case 0x0c0c5d50u: goto P_0c0c5d50;
case 0x0c0c5d52u: goto P_0c0c5d52;
case 0x0c0c5d54u: goto P_0c0c5d54;
case 0x0c0c5d56u: goto P_0c0c5d56;
case 0x0c0c5d58u: goto P_0c0c5d58;
case 0x0c0c5d5au: goto P_0c0c5d5a;
case 0x0c0c5d5cu: goto P_0c0c5d5c;
case 0x0c0c5d5eu: goto P_0c0c5d5e;
case 0x0c0c5d60u: goto P_0c0c5d60;
case 0x0c0c5d62u: goto P_0c0c5d62;
case 0x0c0c5d64u: goto P_0c0c5d64;
case 0x0c0c5d66u: goto P_0c0c5d66;
case 0x0c0c5d68u: goto P_0c0c5d68;
case 0x0c0c5d6au: goto P_0c0c5d6a;
case 0x0c0c5d6cu: goto P_0c0c5d6c;
case 0x0c0c5d6eu: goto P_0c0c5d6e;
case 0x0c0c5d70u: goto P_0c0c5d70;
case 0x0c0c5d72u: goto P_0c0c5d72;
case 0x0c0c5d74u: goto P_0c0c5d74;
case 0x0c0c5d76u: goto P_0c0c5d76;
case 0x0c0c5d78u: goto P_0c0c5d78;
case 0x0c0c5d7au: goto P_0c0c5d7a;
case 0x0c0c5d7cu: goto P_0c0c5d7c;
case 0x0c0c5d7eu: goto P_0c0c5d7e;
case 0x0c0c5d80u: goto P_0c0c5d80;
case 0x0c0c5d82u: goto P_0c0c5d82;
case 0x0c0c5d84u: goto P_0c0c5d84;
case 0x0c0c5d86u: goto P_0c0c5d86;
case 0x0c0c5d88u: goto P_0c0c5d88;
case 0x0c0c5d8au: goto P_0c0c5d8a;
case 0x0c0c5d8cu: goto P_0c0c5d8c;
case 0x0c0c5d8eu: goto P_0c0c5d8e;
case 0x0c0c5d90u: goto P_0c0c5d90;
case 0x0c0c5d92u: goto P_0c0c5d92;
case 0x0c0c5d94u: goto P_0c0c5d94;
case 0x0c0c5d96u: goto P_0c0c5d96;
case 0x0c0c5d98u: goto P_0c0c5d98;
case 0x0c0c5d9au: goto P_0c0c5d9a;
case 0x0c0c5d9cu: goto P_0c0c5d9c;
case 0x0c0c5d9eu: goto P_0c0c5d9e;
case 0x0c0c5da0u: goto P_0c0c5da0;
case 0x0c0c5da2u: goto P_0c0c5da2;
case 0x0c0c5da4u: goto P_0c0c5da4;
case 0x0c0c5da6u: goto P_0c0c5da6;
case 0x0c0c5da8u: goto P_0c0c5da8;
case 0x0c0c5daau: goto P_0c0c5daa;
case 0x0c0c5dacu: goto P_0c0c5dac;
case 0x0c0c5daeu: goto P_0c0c5dae;
case 0x0c0c5db0u: goto P_0c0c5db0;
case 0x0c0c5db2u: goto P_0c0c5db2;
case 0x0c0c5db4u: goto P_0c0c5db4;
case 0x0c0c5db6u: goto P_0c0c5db6;
case 0x0c0c5db8u: goto P_0c0c5db8;
case 0x0c0c5dbau: goto P_0c0c5dba;
case 0x0c0c5dbcu: goto P_0c0c5dbc;
case 0x0c0c5dbeu: goto P_0c0c5dbe;
case 0x0c0c5dc0u: goto P_0c0c5dc0;
case 0x0c0c5dc2u: goto P_0c0c5dc2;
case 0x0c0c5dc4u: goto P_0c0c5dc4;
case 0x0c0c5dc6u: goto P_0c0c5dc6;
case 0x0c0c5dc8u: goto P_0c0c5dc8;
case 0x0c0c5dcau: goto P_0c0c5dca;
case 0x0c0c5dccu: goto P_0c0c5dcc;
case 0x0c0c5dceu: goto P_0c0c5dce;
case 0x0c0c5dd0u: goto P_0c0c5dd0;
case 0x0c0c5dd2u: goto P_0c0c5dd2;
case 0x0c0c5dd4u: goto P_0c0c5dd4;
case 0x0c0c5dd6u: goto P_0c0c5dd6;
case 0x0c0c5dd8u: goto P_0c0c5dd8;
case 0x0c0c5ddau: goto P_0c0c5dda;
case 0x0c0c5ddcu: goto P_0c0c5ddc;
case 0x0c0c5ddeu: goto P_0c0c5dde;
case 0x0c0c5de0u: goto P_0c0c5de0;
case 0x0c0c5de2u: goto P_0c0c5de2;
case 0x0c0c5de4u: goto P_0c0c5de4;
case 0x0c0c5de6u: goto P_0c0c5de6;
case 0x0c0c5de8u: goto P_0c0c5de8;
case 0x0c0c5deau: goto P_0c0c5dea;
case 0x0c0c5decu: goto P_0c0c5dec;
case 0x0c0c5deeu: goto P_0c0c5dee;
case 0x0c0c5df0u: goto P_0c0c5df0;
case 0x0c0c5df2u: goto P_0c0c5df2;
case 0x0c0c5df4u: goto P_0c0c5df4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b10a8: /* original 2fe6, guest PC 0x0c0b10a8 */
if(!s->budget--) { s->failed_pc=0x0c0b10a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b10aa;
P_0c0b10aa: /* original 4f22, guest PC 0x0c0b10aa */
if(!s->budget--) { s->failed_pc=0x0c0b10aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b10ac;
P_0c0b10ac: /* original 7ff0, guest PC 0x0c0b10ac */
if(!s->budget--) { s->failed_pc=0x0c0b10acu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0b10ae;
P_0c0b10ae: /* original 1f52, guest PC 0x0c0b10ae */
if(!s->budget--) { s->failed_pc=0x0c0b10aeu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0b10b0;
P_0c0b10b0: /* original 1f63, guest PC 0x0c0b10b0 */
if(!s->budget--) { s->failed_pc=0x0c0b10b0u; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c0b10b2;
P_0c0b10b2: /* original 53f2, guest PC 0x0c0b10b2 */
if(!s->budget--) { s->failed_pc=0x0c0b10b2u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0b10b4;
P_0c0b10b4: /* original d24a, guest PC 0x0c0b10b4 */
if(!s->budget--) { s->failed_pc=0x0c0b10b4u; return 0; }
r[2]=read(ram,0x0c0b11e0u,4);
goto P_0c0b10b6;
P_0c0b10b6: /* original 6132, guest PC 0x0c0b10b6 */
if(!s->budget--) { s->failed_pc=0x0c0b10b6u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0b10b8;
P_0c0b10b8: /* original 2128, guest PC 0x0c0b10b8 */
if(!s->budget--) { s->failed_pc=0x0c0b10b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0b10ba;
P_0c0b10ba: /* original 8d37, guest PC 0x0c0b10ba */
if(!s->budget--) { s->failed_pc=0x0c0b10bau; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c0b112c; }
goto P_0c0b10be;
P_0c0b10bc: /* original 6e43, guest PC 0x0c0b10bc */
if(!s->budget--) { s->failed_pc=0x0c0b10bcu; return 0; }
r[14]=r[4];
goto P_0c0b10be;
P_0c0b10be: /* original 9087, guest PC 0x0c0b10be */
if(!s->budget--) { s->failed_pc=0x0c0b10beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d0u,2);
goto P_0c0b10c0;
P_0c0b10c0: /* original 00ec, guest PC 0x0c0b10c0 */
if(!s->budget--) { s->failed_pc=0x0c0b10c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b10c2;
P_0c0b10c2: /* original 600c, guest PC 0x0c0b10c2 */
if(!s->budget--) { s->failed_pc=0x0c0b10c2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0b10c4;
P_0c0b10c4: /* original c801, guest PC 0x0c0b10c4 */
if(!s->budget--) { s->failed_pc=0x0c0b10c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0b10c6;
P_0c0b10c6: /* original 8b1a, guest PC 0x0c0b10c6 */
if(!s->budget--) { s->failed_pc=0x0c0b10c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b10fe; }
goto P_0c0b10c8;
P_0c0b10c8: /* original 85ef, guest PC 0x0c0b10c8 */
if(!s->budget--) { s->failed_pc=0x0c0b10c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0b10ca;
P_0c0b10ca: /* original 66f3, guest PC 0x0c0b10ca */
if(!s->budget--) { s->failed_pc=0x0c0b10cau; return 0; }
r[6]=r[15];
goto P_0c0b10cc;
P_0c0b10cc: /* original 7604, guest PC 0x0c0b10cc */
if(!s->budget--) { s->failed_pc=0x0c0b10ccu; return 0; }
r[6]+=0x00000004u;
goto P_0c0b10ce;
P_0c0b10ce: /* original 6403, guest PC 0x0c0b10ce */
if(!s->budget--) { s->failed_pc=0x0c0b10ceu; return 0; }
r[4]=r[0];
goto P_0c0b10d0;
P_0c0b10d0: /* original 907f, guest PC 0x0c0b10d0 */
if(!s->budget--) { s->failed_pc=0x0c0b10d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d2u,2);
goto P_0c0b10d2;
P_0c0b10d2: /* original f3e6, guest PC 0x0c0b10d2 */
if(!s->budget--) { s->failed_pc=0x0c0b10d2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0b10d4;
P_0c0b10d4: /* original ff3a, guest PC 0x0c0b10d4 */
if(!s->budget--) { s->failed_pc=0x0c0b10d4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0b10d6;
P_0c0b10d6: /* original 907d, guest PC 0x0c0b10d6 */
if(!s->budget--) { s->failed_pc=0x0c0b10d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d4u,2);
goto P_0c0b10d8;
P_0c0b10d8: /* original f3e6, guest PC 0x0c0b10d8 */
if(!s->budget--) { s->failed_pc=0x0c0b10d8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0b10da;
P_0c0b10da: /* original e004, guest PC 0x0c0b10da */
if(!s->budget--) { s->failed_pc=0x0c0b10dau; return 0; }
r[0]=0x00000004u;
goto P_0c0b10dc;
P_0c0b10dc: /* original ff37, guest PC 0x0c0b10dc */
if(!s->budget--) { s->failed_pc=0x0c0b10dcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0b10de;
P_0c0b10de: /* original d341, guest PC 0x0c0b10de */
if(!s->budget--) { s->failed_pc=0x0c0b10deu; return 0; }
r[3]=read(ram,0x0c0b11e4u,4);
goto P_0c0b10e0;
P_0c0b10e0: /* original 430b, guest PC 0x0c0b10e0 */
if(!s->budget--) { s->failed_pc=0x0c0b10e0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b10e4u;
r[5]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b10e4u) { target=s->pc; goto dispatch; }
goto P_0c0b10e4;
P_0c0b10e2: /* original 65f3, guest PC 0x0c0b10e2 */
if(!s->budget--) { s->failed_pc=0x0c0b10e2u; return 0; }
r[5]=r[15];
goto P_0c0b10e4;
P_0c0b10e4: /* original e010, guest PC 0x0c0b10e4 */
if(!s->budget--) { s->failed_pc=0x0c0b10e4u; return 0; }
r[0]=0x00000010u;
goto P_0c0b10e6;
P_0c0b10e6: /* original f3f8, guest PC 0x0c0b10e6 */
if(!s->budget--) { s->failed_pc=0x0c0b10e6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0b10e8;
P_0c0b10e8: /* original f4e6, guest PC 0x0c0b10e8 */
if(!s->budget--) { s->failed_pc=0x0c0b10e8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0b10ea;
P_0c0b10ea: /* original e018, guest PC 0x0c0b10ea */
if(!s->budget--) { s->failed_pc=0x0c0b10eau; return 0; }
r[0]=0x00000018u;
goto P_0c0b10ec;
P_0c0b10ec: /* original f5e6, guest PC 0x0c0b10ec */
if(!s->budget--) { s->failed_pc=0x0c0b10ecu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0b10ee;
P_0c0b10ee: /* original e004, guest PC 0x0c0b10ee */
if(!s->budget--) { s->failed_pc=0x0c0b10eeu; return 0; }
r[0]=0x00000004u;
goto P_0c0b10f0;
P_0c0b10f0: /* original f2f6, guest PC 0x0c0b10f0 */
if(!s->budget--) { s->failed_pc=0x0c0b10f0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0b10f2;
P_0c0b10f2: /* original f431, guest PC 0x0c0b10f2 */
if(!s->budget--) { s->failed_pc=0x0c0b10f2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0b10f4;
P_0c0b10f4: /* original e010, guest PC 0x0c0b10f4 */
if(!s->budget--) { s->failed_pc=0x0c0b10f4u; return 0; }
r[0]=0x00000010u;
goto P_0c0b10f6;
P_0c0b10f6: /* original f521, guest PC 0x0c0b10f6 */
if(!s->budget--) { s->failed_pc=0x0c0b10f6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0b10f8;
P_0c0b10f8: /* original fe47, guest PC 0x0c0b10f8 */
if(!s->budget--) { s->failed_pc=0x0c0b10f8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0b10fa;
P_0c0b10fa: /* original e018, guest PC 0x0c0b10fa */
if(!s->budget--) { s->failed_pc=0x0c0b10fau; return 0; }
r[0]=0x00000018u;
goto P_0c0b10fc;
P_0c0b10fc: /* original fe57, guest PC 0x0c0b10fc */
if(!s->budget--) { s->failed_pc=0x0c0b10fcu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0b10fe;
P_0c0b10fe: /* original 906a, guest PC 0x0c0b10fe */
if(!s->budget--) { s->failed_pc=0x0c0b10feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d6u,2);
goto P_0c0b1100;
P_0c0b1100: /* original f3e6, guest PC 0x0c0b1100 */
if(!s->budget--) { s->failed_pc=0x0c0b1100u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0b1102;
P_0c0b1102: /* original e014, guest PC 0x0c0b1102 */
if(!s->budget--) { s->failed_pc=0x0c0b1102u; return 0; }
r[0]=0x00000014u;
goto P_0c0b1104;
P_0c0b1104: /* original ff3a, guest PC 0x0c0b1104 */
if(!s->budget--) { s->failed_pc=0x0c0b1104u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0b1106;
P_0c0b1106: /* original f3e6, guest PC 0x0c0b1106 */
if(!s->budget--) { s->failed_pc=0x0c0b1106u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0b1108;
P_0c0b1108: /* original e004, guest PC 0x0c0b1108 */
if(!s->budget--) { s->failed_pc=0x0c0b1108u; return 0; }
r[0]=0x00000004u;
goto P_0c0b110a;
P_0c0b110a: /* original ff37, guest PC 0x0c0b110a */
if(!s->budget--) { s->failed_pc=0x0c0b110au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0b110c;
P_0c0b110c: /* original f2f8, guest PC 0x0c0b110c */
if(!s->budget--) { s->failed_pc=0x0c0b110cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0b110e;
P_0c0b110e: /* original f231, guest PC 0x0c0b110e */
if(!s->budget--) { s->failed_pc=0x0c0b110eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0b1110;
P_0c0b1110: /* original ff2a, guest PC 0x0c0b1110 */
if(!s->budget--) { s->failed_pc=0x0c0b1110u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0b1112;
P_0c0b1112: /* original 9061, guest PC 0x0c0b1112 */
if(!s->budget--) { s->failed_pc=0x0c0b1112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d8u,2);
goto P_0c0b1114;
P_0c0b1114: /* original f32c, guest PC 0x0c0b1114 */
if(!s->budget--) { s->failed_pc=0x0c0b1114u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0b1116;
P_0c0b1116: /* original fe37, guest PC 0x0c0b1116 */
if(!s->budget--) { s->failed_pc=0x0c0b1116u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0b1118;
P_0c0b1118: /* original 53f2, guest PC 0x0c0b1118 */
if(!s->budget--) { s->failed_pc=0x0c0b1118u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0b111a;
P_0c0b111a: /* original d233, guest PC 0x0c0b111a */
if(!s->budget--) { s->failed_pc=0x0c0b111au; return 0; }
r[2]=read(ram,0x0c0b11e8u,4);
goto P_0c0b111c;
P_0c0b111c: /* original 6132, guest PC 0x0c0b111c */
if(!s->budget--) { s->failed_pc=0x0c0b111cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0b111e;
P_0c0b111e: /* original 2129, guest PC 0x0c0b111e */
if(!s->budget--) { s->failed_pc=0x0c0b111eu; return 0; }
r[1]&=r[2];
goto P_0c0b1120;
P_0c0b1120: /* original 2312, guest PC 0x0c0b1120 */
if(!s->budget--) { s->failed_pc=0x0c0b1120u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0b1122;
P_0c0b1122: /* original 53f3, guest PC 0x0c0b1122 */
if(!s->budget--) { s->failed_pc=0x0c0b1122u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0b1124;
P_0c0b1124: /* original d131, guest PC 0x0c0b1124 */
if(!s->budget--) { s->failed_pc=0x0c0b1124u; return 0; }
r[1]=read(ram,0x0c0b11ecu,4);
goto P_0c0b1126;
P_0c0b1126: /* original 6032, guest PC 0x0c0b1126 */
if(!s->budget--) { s->failed_pc=0x0c0b1126u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0b1128;
P_0c0b1128: /* original 2019, guest PC 0x0c0b1128 */
if(!s->budget--) { s->failed_pc=0x0c0b1128u; return 0; }
r[0]&=r[1];
goto P_0c0b112a;
P_0c0b112a: /* original 2302, guest PC 0x0c0b112a */
if(!s->budget--) { s->failed_pc=0x0c0b112au; return 0; }
write(ram,r[3],r[0],4);
goto P_0c0b112c;
P_0c0b112c: /* original 7f10, guest PC 0x0c0b112c */
if(!s->budget--) { s->failed_pc=0x0c0b112cu; return 0; }
r[15]+=0x00000010u;
goto P_0c0b112e;
P_0c0b112e: /* original 4f26, guest PC 0x0c0b112e */
if(!s->budget--) { s->failed_pc=0x0c0b112eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1130;
P_0c0b1130: /* original 000b, guest PC 0x0c0b1130 */
if(!s->budget--) { s->failed_pc=0x0c0b1130u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1132: /* original 6ef6, guest PC 0x0c0b1132 */
if(!s->budget--) { s->failed_pc=0x0c0b1132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b1134u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1134u; return 0; } return 1;
P_0c0c5c94: /* original 2fe6, guest PC 0x0c0c5c94 */
if(!s->budget--) { s->failed_pc=0x0c0c5c94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c96;
P_0c0c5c96: /* original 6043, guest PC 0x0c0c5c96 */
if(!s->budget--) { s->failed_pc=0x0c0c5c96u; return 0; }
r[0]=r[4];
goto P_0c0c5c98;
P_0c0c5c98: /* original 2fd6, guest PC 0x0c0c5c98 */
if(!s->budget--) { s->failed_pc=0x0c0c5c98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9a;
P_0c0c5c9a: /* original 88ff, guest PC 0x0c0c5c9a */
if(!s->budget--) { s->failed_pc=0x0c0c5c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c5c9c;
P_0c0c5c9c: /* original 2fc6, guest PC 0x0c0c5c9c */
if(!s->budget--) { s->failed_pc=0x0c0c5c9cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9e;
P_0c0c5c9e: /* original 6d43, guest PC 0x0c0c5c9e */
if(!s->budget--) { s->failed_pc=0x0c0c5c9eu; return 0; }
r[13]=r[4];
goto P_0c0c5ca0;
P_0c0c5ca0: /* original 2fb6, guest PC 0x0c0c5ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5ca2;
P_0c0c5ca2: /* original 4f22, guest PC 0x0c0c5ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ca4;
P_0c0c5ca4: /* original 8d03, guest PC 0x0c0c5ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca4u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(cond) { goto P_0c0c5cae; }
goto P_0c0c5ca8;
P_0c0c5ca6: /* original 6b53, guest PC 0x0c0c5ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca6u; return 0; }
r[11]=r[5];
goto P_0c0c5ca8;
P_0c0c5ca8: /* original 930d, guest PC 0x0c0c5ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5cc6u,2);
goto P_0c0c5caa;
P_0c0c5caa: /* original 3d30, guest PC 0x0c0c5caa */
if(!s->budget--) { s->failed_pc=0x0c0c5caau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cac;
P_0c0c5cac: /* original 8b22, guest PC 0x0c0c5cac */
if(!s->budget--) { s->failed_pc=0x0c0c5cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5cf4; }
goto P_0c0c5cae;
P_0c0c5cae: /* original a064, guest PC 0x0c0c5cae */
if(!s->budget--) { s->failed_pc=0x0c0c5caeu; return 0; }
r[0]=0xffffffffu;
goto P_0c0c5d7a;
P_0c0c5cb0: /* original e0ff, guest PC 0x0c0c5cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5cb0u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c0c5cb2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5cb2u; return 0; } return 1;
P_0c0c5cf4: /* original 9381, guest PC 0x0c0c5cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfau,2);
goto P_0c0c5cf6;
P_0c0c5cf6: /* original de43, guest PC 0x0c0c5cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf6u; return 0; }
r[14]=read(ram,0x0c0c5e04u,4);
goto P_0c0c5cf8;
P_0c0c5cf8: /* original 3d30, guest PC 0x0c0c5cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cfa;
P_0c0c5cfa: /* original 8905, guest PC 0x0c0c5cfa */
if(!s->budget--) { s->failed_pc=0x0c0c5cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5cfc;
P_0c0c5cfc: /* original 917e, guest PC 0x0c0c5cfc */
if(!s->budget--) { s->failed_pc=0x0c0c5cfcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfcu,2);
goto P_0c0c5cfe;
P_0c0c5cfe: /* original 3d10, guest PC 0x0c0c5cfe */
if(!s->budget--) { s->failed_pc=0x0c0c5cfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d00;
P_0c0c5d00: /* original 8902, guest PC 0x0c0c5d00 */
if(!s->budget--) { s->failed_pc=0x0c0c5d00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5d02;
P_0c0c5d02: /* original 907c, guest PC 0x0c0c5d02 */
if(!s->budget--) { s->failed_pc=0x0c0c5d02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfeu,2);
goto P_0c0c5d04;
P_0c0c5d04: /* original 3d00, guest PC 0x0c0c5d04 */
if(!s->budget--) { s->failed_pc=0x0c0c5d04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0c5d06;
P_0c0c5d06: /* original 8b07, guest PC 0x0c0c5d06 */
if(!s->budget--) { s->failed_pc=0x0c0c5d06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d18; }
goto P_0c0c5d08;
P_0c0c5d08: /* original 65d3, guest PC 0x0c0c5d08 */
if(!s->budget--) { s->failed_pc=0x0c0c5d08u; return 0; }
r[5]=r[13];
goto P_0c0c5d0a;
P_0c0c5d0a: /* original 66b3, guest PC 0x0c0c5d0a */
if(!s->budget--) { s->failed_pc=0x0c0c5d0au; return 0; }
r[6]=r[11];
goto P_0c0c5d0c;
P_0c0c5d0c: /* original 4e0b, guest PC 0x0c0c5d0c */
if(!s->budget--) { s->failed_pc=0x0c0c5d0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d10u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d10u) { target=s->pc; goto dispatch; }
goto P_0c0c5d10;
P_0c0c5d0e: /* original e404, guest PC 0x0c0c5d0e */
if(!s->budget--) { s->failed_pc=0x0c0c5d0eu; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d10;
P_0c0c5d10: /* original 65d3, guest PC 0x0c0c5d10 */
if(!s->budget--) { s->failed_pc=0x0c0c5d10u; return 0; }
r[5]=r[13];
goto P_0c0c5d12;
P_0c0c5d12: /* original 66b3, guest PC 0x0c0c5d12 */
if(!s->budget--) { s->failed_pc=0x0c0c5d12u; return 0; }
r[6]=r[11];
goto P_0c0c5d14;
P_0c0c5d14: /* original a02f, guest PC 0x0c0c5d14 */
if(!s->budget--) { s->failed_pc=0x0c0c5d14u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d76;
P_0c0c5d16: /* original e403, guest PC 0x0c0c5d16 */
if(!s->budget--) { s->failed_pc=0x0c0c5d16u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d18;
P_0c0c5d18: /* original d33c, guest PC 0x0c0c5d18 */
if(!s->budget--) { s->failed_pc=0x0c0c5d18u; return 0; }
r[3]=read(ram,0x0c0c5e0cu,4);
goto P_0c0c5d1a;
P_0c0c5d1a: /* original dc3b, guest PC 0x0c0c5d1a */
if(!s->budget--) { s->failed_pc=0x0c0c5d1au; return 0; }
r[12]=read(ram,0x0c0c5e08u,4);
goto P_0c0c5d1c;
P_0c0c5d1c: /* original 3d30, guest PC 0x0c0c5d1c */
if(!s->budget--) { s->failed_pc=0x0c0c5d1cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5d1e;
P_0c0c5d1e: /* original 8b0b, guest PC 0x0c0c5d1e */
if(!s->budget--) { s->failed_pc=0x0c0c5d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d38; }
goto P_0c0c5d20;
P_0c0c5d20: /* original 65c3, guest PC 0x0c0c5d20 */
if(!s->budget--) { s->failed_pc=0x0c0c5d20u; return 0; }
r[5]=r[12];
goto P_0c0c5d22;
P_0c0c5d22: /* original e600, guest PC 0x0c0c5d22 */
if(!s->budget--) { s->failed_pc=0x0c0c5d22u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d24;
P_0c0c5d24: /* original 4e0b, guest PC 0x0c0c5d24 */
if(!s->budget--) { s->failed_pc=0x0c0c5d24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d28u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d28u) { target=s->pc; goto dispatch; }
goto P_0c0c5d28;
P_0c0c5d26: /* original e401, guest PC 0x0c0c5d26 */
if(!s->budget--) { s->failed_pc=0x0c0c5d26u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d28;
P_0c0c5d28: /* original 65c3, guest PC 0x0c0c5d28 */
if(!s->budget--) { s->failed_pc=0x0c0c5d28u; return 0; }
r[5]=r[12];
goto P_0c0c5d2a;
P_0c0c5d2a: /* original e600, guest PC 0x0c0c5d2a */
if(!s->budget--) { s->failed_pc=0x0c0c5d2au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d2c;
P_0c0c5d2c: /* original 4e0b, guest PC 0x0c0c5d2c */
if(!s->budget--) { s->failed_pc=0x0c0c5d2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d30u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d30u) { target=s->pc; goto dispatch; }
goto P_0c0c5d30;
P_0c0c5d2e: /* original e402, guest PC 0x0c0c5d2e */
if(!s->budget--) { s->failed_pc=0x0c0c5d2eu; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d30;
P_0c0c5d30: /* original 65c3, guest PC 0x0c0c5d30 */
if(!s->budget--) { s->failed_pc=0x0c0c5d30u; return 0; }
r[5]=r[12];
goto P_0c0c5d32;
P_0c0c5d32: /* original e600, guest PC 0x0c0c5d32 */
if(!s->budget--) { s->failed_pc=0x0c0c5d32u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d34;
P_0c0c5d34: /* original a00a, guest PC 0x0c0c5d34 */
if(!s->budget--) { s->failed_pc=0x0c0c5d34u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d4c;
P_0c0c5d36: /* original e403, guest PC 0x0c0c5d36 */
if(!s->budget--) { s->failed_pc=0x0c0c5d36u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d38;
P_0c0c5d38: /* original d135, guest PC 0x0c0c5d38 */
if(!s->budget--) { s->failed_pc=0x0c0c5d38u; return 0; }
r[1]=read(ram,0x0c0c5e10u,4);
goto P_0c0c5d3a;
P_0c0c5d3a: /* original 3d10, guest PC 0x0c0c5d3a */
if(!s->budget--) { s->failed_pc=0x0c0c5d3au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d3c;
P_0c0c5d3c: /* original 8b18, guest PC 0x0c0c5d3c */
if(!s->budget--) { s->failed_pc=0x0c0c5d3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d70; }
goto P_0c0c5d3e;
P_0c0c5d3e: /* original 65c3, guest PC 0x0c0c5d3e */
if(!s->budget--) { s->failed_pc=0x0c0c5d3eu; return 0; }
r[5]=r[12];
goto P_0c0c5d40;
P_0c0c5d40: /* original e600, guest PC 0x0c0c5d40 */
if(!s->budget--) { s->failed_pc=0x0c0c5d40u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d42;
P_0c0c5d42: /* original 4e0b, guest PC 0x0c0c5d42 */
if(!s->budget--) { s->failed_pc=0x0c0c5d42u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d46u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d46u) { target=s->pc; goto dispatch; }
goto P_0c0c5d46;
P_0c0c5d44: /* original e401, guest PC 0x0c0c5d44 */
if(!s->budget--) { s->failed_pc=0x0c0c5d44u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d46;
P_0c0c5d46: /* original e402, guest PC 0x0c0c5d46 */
if(!s->budget--) { s->failed_pc=0x0c0c5d46u; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d48;
P_0c0c5d48: /* original 65c3, guest PC 0x0c0c5d48 */
if(!s->budget--) { s->failed_pc=0x0c0c5d48u; return 0; }
r[5]=r[12];
goto P_0c0c5d4a;
P_0c0c5d4a: /* original e600, guest PC 0x0c0c5d4a */
if(!s->budget--) { s->failed_pc=0x0c0c5d4au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d4c;
P_0c0c5d4c: /* original 4e0b, guest PC 0x0c0c5d4c */
if(!s->budget--) { s->failed_pc=0x0c0c5d4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d50u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d50u) { target=s->pc; goto dispatch; }
goto P_0c0c5d50;
P_0c0c5d4e: /* original 0009, guest PC 0x0c0c5d4e */
if(!s->budget--) { s->failed_pc=0x0c0c5d4eu; return 0; }
goto P_0c0c5d50;
P_0c0c5d50: /* original 65c3, guest PC 0x0c0c5d50 */
if(!s->budget--) { s->failed_pc=0x0c0c5d50u; return 0; }
r[5]=r[12];
goto P_0c0c5d52;
P_0c0c5d52: /* original e600, guest PC 0x0c0c5d52 */
if(!s->budget--) { s->failed_pc=0x0c0c5d52u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d54;
P_0c0c5d54: /* original 4e0b, guest PC 0x0c0c5d54 */
if(!s->budget--) { s->failed_pc=0x0c0c5d54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d58u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d58u) { target=s->pc; goto dispatch; }
goto P_0c0c5d58;
P_0c0c5d56: /* original e404, guest PC 0x0c0c5d56 */
if(!s->budget--) { s->failed_pc=0x0c0c5d56u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d58;
P_0c0c5d58: /* original 65c3, guest PC 0x0c0c5d58 */
if(!s->budget--) { s->failed_pc=0x0c0c5d58u; return 0; }
r[5]=r[12];
goto P_0c0c5d5a;
P_0c0c5d5a: /* original e600, guest PC 0x0c0c5d5a */
if(!s->budget--) { s->failed_pc=0x0c0c5d5au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d5c;
P_0c0c5d5c: /* original 4e0b, guest PC 0x0c0c5d5c */
if(!s->budget--) { s->failed_pc=0x0c0c5d5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d60u;
r[4]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d60u) { target=s->pc; goto dispatch; }
goto P_0c0c5d60;
P_0c0c5d5e: /* original e405, guest PC 0x0c0c5d5e */
if(!s->budget--) { s->failed_pc=0x0c0c5d5eu; return 0; }
r[4]=0x00000005u;
goto P_0c0c5d60;
P_0c0c5d60: /* original 65c3, guest PC 0x0c0c5d60 */
if(!s->budget--) { s->failed_pc=0x0c0c5d60u; return 0; }
r[5]=r[12];
goto P_0c0c5d62;
P_0c0c5d62: /* original e600, guest PC 0x0c0c5d62 */
if(!s->budget--) { s->failed_pc=0x0c0c5d62u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d64;
P_0c0c5d64: /* original 4e0b, guest PC 0x0c0c5d64 */
if(!s->budget--) { s->failed_pc=0x0c0c5d64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d68u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d68u) { target=s->pc; goto dispatch; }
goto P_0c0c5d68;
P_0c0c5d66: /* original e406, guest PC 0x0c0c5d66 */
if(!s->budget--) { s->failed_pc=0x0c0c5d66u; return 0; }
r[4]=0x00000006u;
goto P_0c0c5d68;
P_0c0c5d68: /* original 65c3, guest PC 0x0c0c5d68 */
if(!s->budget--) { s->failed_pc=0x0c0c5d68u; return 0; }
r[5]=r[12];
goto P_0c0c5d6a;
P_0c0c5d6a: /* original e600, guest PC 0x0c0c5d6a */
if(!s->budget--) { s->failed_pc=0x0c0c5d6au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d6c;
P_0c0c5d6c: /* original a003, guest PC 0x0c0c5d6c */
if(!s->budget--) { s->failed_pc=0x0c0c5d6cu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d76;
P_0c0c5d6e: /* original e407, guest PC 0x0c0c5d6e */
if(!s->budget--) { s->failed_pc=0x0c0c5d6eu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d70;
P_0c0c5d70: /* original e400, guest PC 0x0c0c5d70 */
if(!s->budget--) { s->failed_pc=0x0c0c5d70u; return 0; }
r[4]=0x00000000u;
goto P_0c0c5d72;
P_0c0c5d72: /* original 65d3, guest PC 0x0c0c5d72 */
if(!s->budget--) { s->failed_pc=0x0c0c5d72u; return 0; }
r[5]=r[13];
goto P_0c0c5d74;
P_0c0c5d74: /* original 66b3, guest PC 0x0c0c5d74 */
if(!s->budget--) { s->failed_pc=0x0c0c5d74u; return 0; }
r[6]=r[11];
goto P_0c0c5d76;
P_0c0c5d76: /* original 4e0b, guest PC 0x0c0c5d76 */
if(!s->budget--) { s->failed_pc=0x0c0c5d76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d7au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d7au) { target=s->pc; goto dispatch; }
goto P_0c0c5d7a;
P_0c0c5d78: /* original 0009, guest PC 0x0c0c5d78 */
if(!s->budget--) { s->failed_pc=0x0c0c5d78u; return 0; }
goto P_0c0c5d7a;
P_0c0c5d7a: /* original 4f26, guest PC 0x0c0c5d7a */
if(!s->budget--) { s->failed_pc=0x0c0c5d7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5d7c;
P_0c0c5d7c: /* original 6bf6, guest PC 0x0c0c5d7c */
if(!s->budget--) { s->failed_pc=0x0c0c5d7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5d7e;
P_0c0c5d7e: /* original 6cf6, guest PC 0x0c0c5d7e */
if(!s->budget--) { s->failed_pc=0x0c0c5d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5d80;
P_0c0c5d80: /* original 6df6, guest PC 0x0c0c5d80 */
if(!s->budget--) { s->failed_pc=0x0c0c5d80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5d82;
P_0c0c5d82: /* original 000b, guest PC 0x0c0c5d82 */
if(!s->budget--) { s->failed_pc=0x0c0c5d82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5d84: /* original 6ef6, guest PC 0x0c0c5d84 */
if(!s->budget--) { s->failed_pc=0x0c0c5d84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c5d86;
P_0c0c5d86: /* original 4f22, guest PC 0x0c0c5d86 */
if(!s->budget--) { s->failed_pc=0x0c0c5d86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5d88;
P_0c0c5d88: /* original 7ff8, guest PC 0x0c0c5d88 */
if(!s->budget--) { s->failed_pc=0x0c0c5d88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5d8a;
P_0c0c5d8a: /* original 2f42, guest PC 0x0c0c5d8a */
if(!s->budget--) { s->failed_pc=0x0c0c5d8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c5d8c;
P_0c0c5d8c: /* original d421, guest PC 0x0c0c5d8c */
if(!s->budget--) { s->failed_pc=0x0c0c5d8cu; return 0; }
r[4]=read(ram,0x0c0c5e14u,4);
goto P_0c0c5d8e;
P_0c0c5d8e: /* original d322, guest PC 0x0c0c5d8e */
if(!s->budget--) { s->failed_pc=0x0c0c5d8eu; return 0; }
r[3]=read(ram,0x0c0c5e18u,4);
goto P_0c0c5d90;
P_0c0c5d90: /* original 1f31, guest PC 0x0c0c5d90 */
if(!s->budget--) { s->failed_pc=0x0c0c5d90u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5d92;
P_0c0c5d92: /* original 8448, guest PC 0x0c0c5d92 */
if(!s->budget--) { s->failed_pc=0x0c0c5d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0c5d94;
P_0c0c5d94: /* original 600c, guest PC 0x0c0c5d94 */
if(!s->budget--) { s->failed_pc=0x0c0c5d94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c5d96;
P_0c0c5d96: /* original 8803, guest PC 0x0c0c5d96 */
if(!s->budget--) { s->failed_pc=0x0c0c5d96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c5d98;
P_0c0c5d98: /* original 8f07, guest PC 0x0c0c5d98 */
if(!s->budget--) { s->failed_pc=0x0c0c5d98u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c5daa; }
goto P_0c0c5d9c;
P_0c0c5d9a: /* original 6403, guest PC 0x0c0c5d9a */
if(!s->budget--) { s->failed_pc=0x0c0c5d9au; return 0; }
r[4]=r[0];
goto P_0c0c5d9c;
P_0c0c5d9c: /* original d31f, guest PC 0x0c0c5d9c */
if(!s->budget--) { s->failed_pc=0x0c0c5d9cu; return 0; }
r[3]=read(ram,0x0c0c5e1cu,4);
goto P_0c0c5d9e;
P_0c0c5d9e: /* original 54f1, guest PC 0x0c0c5d9e */
if(!s->budget--) { s->failed_pc=0x0c0c5d9eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5da0;
P_0c0c5da0: /* original 430b, guest PC 0x0c0c5da0 */
if(!s->budget--) { s->failed_pc=0x0c0c5da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5da4u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5da4u) { target=s->pc; goto dispatch; }
goto P_0c0c5da4;
P_0c0c5da2: /* original 7403, guest PC 0x0c0c5da2 */
if(!s->budget--) { s->failed_pc=0x0c0c5da2u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c5da4;
P_0c0c5da4: /* original 640c, guest PC 0x0c0c5da4 */
if(!s->budget--) { s->failed_pc=0x0c0c5da4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c5da6;
P_0c0c5da6: /* original 2448, guest PC 0x0c0c5da6 */
if(!s->budget--) { s->failed_pc=0x0c0c5da6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c5da8;
P_0c0c5da8: /* original 8b03, guest PC 0x0c0c5da8 */
if(!s->budget--) { s->failed_pc=0x0c0c5da8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5db2; }
goto P_0c0c5daa;
P_0c0c5daa: /* original 64f2, guest PC 0x0c0c5daa */
if(!s->budget--) { s->failed_pc=0x0c0c5daau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c5dac;
P_0c0c5dac: /* original 7f08, guest PC 0x0c0c5dac */
if(!s->budget--) { s->failed_pc=0x0c0c5dacu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5dae;
P_0c0c5dae: /* original a004, guest PC 0x0c0c5dae */
if(!s->budget--) { s->failed_pc=0x0c0c5daeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5dba;
P_0c0c5db0: /* original 4f26, guest PC 0x0c0c5db0 */
if(!s->budget--) { s->failed_pc=0x0c0c5db0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db2;
P_0c0c5db2: /* original 7f08, guest PC 0x0c0c5db2 */
if(!s->budget--) { s->failed_pc=0x0c0c5db2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5db4;
P_0c0c5db4: /* original 4f26, guest PC 0x0c0c5db4 */
if(!s->budget--) { s->failed_pc=0x0c0c5db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db6;
P_0c0c5db6: /* original 000b, guest PC 0x0c0c5db6 */
if(!s->budget--) { s->failed_pc=0x0c0c5db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c5db8: /* original 0009, guest PC 0x0c0c5db8 */
if(!s->budget--) { s->failed_pc=0x0c0c5db8u; return 0; }
goto P_0c0c5dba;
P_0c0c5dba: /* original 2fe6, guest PC 0x0c0c5dba */
if(!s->budget--) { s->failed_pc=0x0c0c5dbau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5dbc;
P_0c0c5dbc: /* original 4411, guest PC 0x0c0c5dbc */
if(!s->budget--) { s->failed_pc=0x0c0c5dbcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c5dbe;
P_0c0c5dbe: /* original 4f22, guest PC 0x0c0c5dbe */
if(!s->budget--) { s->failed_pc=0x0c0c5dbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5dc0;
P_0c0c5dc0: /* original d517, guest PC 0x0c0c5dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc0u; return 0; }
r[5]=read(ram,0x0c0c5e20u,4);
goto P_0c0c5dc2;
P_0c0c5dc2: /* original 8b15, guest PC 0x0c0c5dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dc4;
P_0c0c5dc4: /* original 921c, guest PC 0x0c0c5dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5e00u,2);
goto P_0c0c5dc6;
P_0c0c5dc6: /* original 3423, guest PC 0x0c0c5dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c5dc8;
P_0c0c5dc8: /* original 8912, guest PC 0x0c0c5dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5dca;
P_0c0c5dca: /* original d016, guest PC 0x0c0c5dca */
if(!s->budget--) { s->failed_pc=0x0c0c5dcau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dcc;
P_0c0c5dcc: /* original 4408, guest PC 0x0c0c5dcc */
if(!s->budget--) { s->failed_pc=0x0c0c5dccu; return 0; }
r[4]<<=2;
goto P_0c0c5dce;
P_0c0c5dce: /* original 6e43, guest PC 0x0c0c5dce */
if(!s->budget--) { s->failed_pc=0x0c0c5dceu; return 0; }
r[14]=r[4];
goto P_0c0c5dd0;
P_0c0c5dd0: /* original 03ee, guest PC 0x0c0c5dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0c5dd2;
P_0c0c5dd2: /* original 4311, guest PC 0x0c0c5dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c5dd4;
P_0c0c5dd4: /* original 8b0c, guest PC 0x0c0c5dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dd6;
P_0c0c5dd6: /* original d414, guest PC 0x0c0c5dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd6u; return 0; }
r[4]=read(ram,0x0c0c5e28u,4);
goto P_0c0c5dd8;
P_0c0c5dd8: /* original 60e3, guest PC 0x0c0c5dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd8u; return 0; }
r[0]=r[14];
goto P_0c0c5dda;
P_0c0c5dda: /* original 6252, guest PC 0x0c0c5dda */
if(!s->budget--) { s->failed_pc=0x0c0c5ddau; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0c5ddc;
P_0c0c5ddc: /* original 034e, guest PC 0x0c0c5ddc */
if(!s->budget--) { s->failed_pc=0x0c0c5ddcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c5dde;
P_0c0c5dde: /* original 3320, guest PC 0x0c0c5dde */
if(!s->budget--) { s->failed_pc=0x0c0c5ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c5de0;
P_0c0c5de0: /* original 8906, guest PC 0x0c0c5de0 */
if(!s->budget--) { s->failed_pc=0x0c0c5de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5de2;
P_0c0c5de2: /* original 6352, guest PC 0x0c0c5de2 */
if(!s->budget--) { s->failed_pc=0x0c0c5de2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0c5de4;
P_0c0c5de4: /* original 60e3, guest PC 0x0c0c5de4 */
if(!s->budget--) { s->failed_pc=0x0c0c5de4u; return 0; }
r[0]=r[14];
goto P_0c0c5de6;
P_0c0c5de6: /* original 0436, guest PC 0x0c0c5de6 */
if(!s->budget--) { s->failed_pc=0x0c0c5de6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0c5de8;
P_0c0c5de8: /* original d310, guest PC 0x0c0c5de8 */
if(!s->budget--) { s->failed_pc=0x0c0c5de8u; return 0; }
r[3]=read(ram,0x0c0c5e2cu,4);
goto P_0c0c5dea;
P_0c0c5dea: /* original d00e, guest PC 0x0c0c5dea */
if(!s->budget--) { s->failed_pc=0x0c0c5deau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dec;
P_0c0c5dec: /* original 430b, guest PC 0x0c0c5dec */
if(!s->budget--) { s->failed_pc=0x0c0c5decu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5df0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5df0u) { target=s->pc; goto dispatch; }
goto P_0c0c5df0;
P_0c0c5dee: /* original 04ee, guest PC 0x0c0c5dee */
if(!s->budget--) { s->failed_pc=0x0c0c5deeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c5df0;
P_0c0c5df0: /* original 4f26, guest PC 0x0c0c5df0 */
if(!s->budget--) { s->failed_pc=0x0c0c5df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5df2;
P_0c0c5df2: /* original 000b, guest PC 0x0c0c5df2 */
if(!s->budget--) { s->failed_pc=0x0c0c5df2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5df4: /* original 6ef6, guest PC 0x0c0c5df4 */
if(!s->budget--) { s->failed_pc=0x0c0c5df4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5df6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5df6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
