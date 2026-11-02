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
int vf3_away_batch47_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c081098u: goto P_0c081098;
case 0x0c08109au: goto P_0c08109a;
case 0x0c08109cu: goto P_0c08109c;
case 0x0c08109eu: goto P_0c08109e;
case 0x0c0810a0u: goto P_0c0810a0;
case 0x0c0810a2u: goto P_0c0810a2;
case 0x0c0810a4u: goto P_0c0810a4;
case 0x0c0810a6u: goto P_0c0810a6;
case 0x0c0810a8u: goto P_0c0810a8;
case 0x0c0810aau: goto P_0c0810aa;
case 0x0c0810acu: goto P_0c0810ac;
case 0x0c0810aeu: goto P_0c0810ae;
case 0x0c0810b0u: goto P_0c0810b0;
case 0x0c0810b2u: goto P_0c0810b2;
case 0x0c0810b4u: goto P_0c0810b4;
case 0x0c0810b6u: goto P_0c0810b6;
case 0x0c0810b8u: goto P_0c0810b8;
case 0x0c0810bau: goto P_0c0810ba;
case 0x0c081978u: goto P_0c081978;
case 0x0c08197au: goto P_0c08197a;
case 0x0c08197cu: goto P_0c08197c;
case 0x0c08197eu: goto P_0c08197e;
case 0x0c081980u: goto P_0c081980;
case 0x0c081982u: goto P_0c081982;
case 0x0c081984u: goto P_0c081984;
case 0x0c081986u: goto P_0c081986;
case 0x0c081988u: goto P_0c081988;
case 0x0c08198au: goto P_0c08198a;
case 0x0c08198cu: goto P_0c08198c;
case 0x0c08198eu: goto P_0c08198e;
case 0x0c081990u: goto P_0c081990;
case 0x0c081992u: goto P_0c081992;
case 0x0c081994u: goto P_0c081994;
case 0x0c081996u: goto P_0c081996;
case 0x0c081998u: goto P_0c081998;
case 0x0c08199au: goto P_0c08199a;
case 0x0c08199cu: goto P_0c08199c;
case 0x0c08199eu: goto P_0c08199e;
case 0x0c0819a0u: goto P_0c0819a0;
case 0x0c0819a2u: goto P_0c0819a2;
case 0x0c0819a4u: goto P_0c0819a4;
case 0x0c0819a6u: goto P_0c0819a6;
case 0x0c0819a8u: goto P_0c0819a8;
case 0x0c0819aau: goto P_0c0819aa;
case 0x0c0819acu: goto P_0c0819ac;
case 0x0c0819aeu: goto P_0c0819ae;
case 0x0c0819b0u: goto P_0c0819b0;
case 0x0c0819b2u: goto P_0c0819b2;
case 0x0c0819b4u: goto P_0c0819b4;
case 0x0c0819b6u: goto P_0c0819b6;
case 0x0c0819b8u: goto P_0c0819b8;
case 0x0c0819bau: goto P_0c0819ba;
case 0x0c0819bcu: goto P_0c0819bc;
case 0x0c0819beu: goto P_0c0819be;
case 0x0c0819c0u: goto P_0c0819c0;
case 0x0c0819c2u: goto P_0c0819c2;
case 0x0c0819c4u: goto P_0c0819c4;
case 0x0c0819c6u: goto P_0c0819c6;
case 0x0c0819c8u: goto P_0c0819c8;
case 0x0c0819cau: goto P_0c0819ca;
case 0x0c0819ccu: goto P_0c0819cc;
case 0x0c0819ceu: goto P_0c0819ce;
case 0x0c0819d0u: goto P_0c0819d0;
case 0x0c0819d2u: goto P_0c0819d2;
case 0x0c0819e8u: goto P_0c0819e8;
case 0x0c0819eau: goto P_0c0819ea;
case 0x0c0819ecu: goto P_0c0819ec;
case 0x0c0819eeu: goto P_0c0819ee;
case 0x0c0819f0u: goto P_0c0819f0;
case 0x0c0819f2u: goto P_0c0819f2;
case 0x0c0819f4u: goto P_0c0819f4;
case 0x0c0819f6u: goto P_0c0819f6;
case 0x0c0819f8u: goto P_0c0819f8;
case 0x0c0819fau: goto P_0c0819fa;
case 0x0c0819fcu: goto P_0c0819fc;
case 0x0c0819feu: goto P_0c0819fe;
case 0x0c081a00u: goto P_0c081a00;
case 0x0c081a02u: goto P_0c081a02;
case 0x0c081a04u: goto P_0c081a04;
case 0x0c081a06u: goto P_0c081a06;
case 0x0c081a08u: goto P_0c081a08;
case 0x0c081a0au: goto P_0c081a0a;
case 0x0c081a0cu: goto P_0c081a0c;
case 0x0c081a0eu: goto P_0c081a0e;
case 0x0c081a10u: goto P_0c081a10;
case 0x0c081a12u: goto P_0c081a12;
case 0x0c081a14u: goto P_0c081a14;
case 0x0c081a16u: goto P_0c081a16;
case 0x0c081a18u: goto P_0c081a18;
case 0x0c081a1au: goto P_0c081a1a;
case 0x0c081a1cu: goto P_0c081a1c;
case 0x0c081a1eu: goto P_0c081a1e;
case 0x0c081a20u: goto P_0c081a20;
case 0x0c081a22u: goto P_0c081a22;
case 0x0c081a24u: goto P_0c081a24;
case 0x0c081a26u: goto P_0c081a26;
case 0x0c081a28u: goto P_0c081a28;
case 0x0c081a2au: goto P_0c081a2a;
case 0x0c081a2cu: goto P_0c081a2c;
case 0x0c081a2eu: goto P_0c081a2e;
case 0x0c081a30u: goto P_0c081a30;
case 0x0c081a32u: goto P_0c081a32;
case 0x0c081a34u: goto P_0c081a34;
case 0x0c081a36u: goto P_0c081a36;
case 0x0c081a38u: goto P_0c081a38;
case 0x0c081a3au: goto P_0c081a3a;
case 0x0c081a3cu: goto P_0c081a3c;
case 0x0c081a3eu: goto P_0c081a3e;
case 0x0c081a40u: goto P_0c081a40;
case 0x0c081a42u: goto P_0c081a42;
case 0x0c081a44u: goto P_0c081a44;
case 0x0c081d24u: goto P_0c081d24;
case 0x0c081d26u: goto P_0c081d26;
case 0x0c081d28u: goto P_0c081d28;
case 0x0c081d2au: goto P_0c081d2a;
case 0x0c081d2cu: goto P_0c081d2c;
case 0x0c081d2eu: goto P_0c081d2e;
case 0x0c081d30u: goto P_0c081d30;
case 0x0c081d32u: goto P_0c081d32;
case 0x0c081d34u: goto P_0c081d34;
case 0x0c081d36u: goto P_0c081d36;
case 0x0c081d38u: goto P_0c081d38;
case 0x0c081d3au: goto P_0c081d3a;
case 0x0c081d3cu: goto P_0c081d3c;
case 0x0c081d3eu: goto P_0c081d3e;
case 0x0c081d40u: goto P_0c081d40;
case 0x0c081d42u: goto P_0c081d42;
case 0x0c081d44u: goto P_0c081d44;
case 0x0c081d46u: goto P_0c081d46;
case 0x0c081d48u: goto P_0c081d48;
case 0x0c081d4au: goto P_0c081d4a;
case 0x0c081d4cu: goto P_0c081d4c;
case 0x0c081d4eu: goto P_0c081d4e;
case 0x0c081d50u: goto P_0c081d50;
case 0x0c081d52u: goto P_0c081d52;
case 0x0c081d54u: goto P_0c081d54;
case 0x0c081d56u: goto P_0c081d56;
case 0x0c081d58u: goto P_0c081d58;
case 0x0c081d5au: goto P_0c081d5a;
case 0x0c081d5cu: goto P_0c081d5c;
case 0x0c081d5eu: goto P_0c081d5e;
case 0x0c081d60u: goto P_0c081d60;
case 0x0c081d62u: goto P_0c081d62;
case 0x0c081d64u: goto P_0c081d64;
case 0x0c081d66u: goto P_0c081d66;
case 0x0c081d68u: goto P_0c081d68;
case 0x0c081d6au: goto P_0c081d6a;
case 0x0c081d6cu: goto P_0c081d6c;
case 0x0c081d6eu: goto P_0c081d6e;
case 0x0c081d70u: goto P_0c081d70;
case 0x0c081d72u: goto P_0c081d72;
case 0x0c081d74u: goto P_0c081d74;
case 0x0c081d76u: goto P_0c081d76;
case 0x0c081d78u: goto P_0c081d78;
case 0x0c081d7au: goto P_0c081d7a;
case 0x0c081d7cu: goto P_0c081d7c;
case 0x0c081d7eu: goto P_0c081d7e;
case 0x0c081d80u: goto P_0c081d80;
case 0x0c081d82u: goto P_0c081d82;
case 0x0c081d84u: goto P_0c081d84;
case 0x0c081d86u: goto P_0c081d86;
case 0x0c081d88u: goto P_0c081d88;
case 0x0c081d8au: goto P_0c081d8a;
case 0x0c081d8cu: goto P_0c081d8c;
case 0x0c081d8eu: goto P_0c081d8e;
case 0x0c081d90u: goto P_0c081d90;
case 0x0c081d92u: goto P_0c081d92;
case 0x0c081d94u: goto P_0c081d94;
case 0x0c081d96u: goto P_0c081d96;
case 0x0c081d98u: goto P_0c081d98;
case 0x0c081d9au: goto P_0c081d9a;
case 0x0c081d9cu: goto P_0c081d9c;
case 0x0c081d9eu: goto P_0c081d9e;
case 0x0c081da0u: goto P_0c081da0;
case 0x0c081da2u: goto P_0c081da2;
case 0x0c081da4u: goto P_0c081da4;
case 0x0c081da6u: goto P_0c081da6;
case 0x0c081da8u: goto P_0c081da8;
case 0x0c081daau: goto P_0c081daa;
case 0x0c081dacu: goto P_0c081dac;
case 0x0c081daeu: goto P_0c081dae;
case 0x0c081db0u: goto P_0c081db0;
case 0x0c081db2u: goto P_0c081db2;
case 0x0c081db4u: goto P_0c081db4;
case 0x0c081db6u: goto P_0c081db6;
case 0x0c081db8u: goto P_0c081db8;
case 0x0c081dbau: goto P_0c081dba;
case 0x0c081dbcu: goto P_0c081dbc;
case 0x0c081dbeu: goto P_0c081dbe;
case 0x0c081dc0u: goto P_0c081dc0;
case 0x0c081dc2u: goto P_0c081dc2;
case 0x0c081dc4u: goto P_0c081dc4;
case 0x0c081dc6u: goto P_0c081dc6;
case 0x0c081dc8u: goto P_0c081dc8;
case 0x0c081dcau: goto P_0c081dca;
case 0x0c081dccu: goto P_0c081dcc;
case 0x0c081dceu: goto P_0c081dce;
case 0x0c081dd0u: goto P_0c081dd0;
case 0x0c081dd2u: goto P_0c081dd2;
case 0x0c081dd4u: goto P_0c081dd4;
case 0x0c081dd6u: goto P_0c081dd6;
case 0x0c081dd8u: goto P_0c081dd8;
case 0x0c081ddau: goto P_0c081dda;
case 0x0c081ddcu: goto P_0c081ddc;
case 0x0c081ddeu: goto P_0c081dde;
case 0x0c081de0u: goto P_0c081de0;
case 0x0c081de2u: goto P_0c081de2;
case 0x0c081de4u: goto P_0c081de4;
case 0x0c081de6u: goto P_0c081de6;
case 0x0c081de8u: goto P_0c081de8;
case 0x0c081deau: goto P_0c081dea;
case 0x0c081decu: goto P_0c081dec;
case 0x0c081deeu: goto P_0c081dee;
case 0x0c081df0u: goto P_0c081df0;
case 0x0c081df2u: goto P_0c081df2;
case 0x0c081df4u: goto P_0c081df4;
case 0x0c081df6u: goto P_0c081df6;
case 0x0c081df8u: goto P_0c081df8;
case 0x0c081dfau: goto P_0c081dfa;
case 0x0c081dfcu: goto P_0c081dfc;
case 0x0c081dfeu: goto P_0c081dfe;
case 0x0c081e00u: goto P_0c081e00;
case 0x0c081e02u: goto P_0c081e02;
case 0x0c081e04u: goto P_0c081e04;
case 0x0c081e06u: goto P_0c081e06;
case 0x0c081e08u: goto P_0c081e08;
case 0x0c081e0au: goto P_0c081e0a;
case 0x0c081e0cu: goto P_0c081e0c;
case 0x0c081e0eu: goto P_0c081e0e;
case 0x0c081e10u: goto P_0c081e10;
case 0x0c081e12u: goto P_0c081e12;
case 0x0c081e14u: goto P_0c081e14;
case 0x0c081e16u: goto P_0c081e16;
case 0x0c081e18u: goto P_0c081e18;
case 0x0c081e1au: goto P_0c081e1a;
case 0x0c081e1cu: goto P_0c081e1c;
case 0x0c081e1eu: goto P_0c081e1e;
case 0x0c081e20u: goto P_0c081e20;
case 0x0c081e22u: goto P_0c081e22;
case 0x0c081e24u: goto P_0c081e24;
case 0x0c081e26u: goto P_0c081e26;
case 0x0c081e28u: goto P_0c081e28;
case 0x0c081e2au: goto P_0c081e2a;
case 0x0c081e2cu: goto P_0c081e2c;
case 0x0c081e2eu: goto P_0c081e2e;
case 0x0c081e30u: goto P_0c081e30;
case 0x0c081e32u: goto P_0c081e32;
case 0x0c081e34u: goto P_0c081e34;
case 0x0c081e36u: goto P_0c081e36;
case 0x0c081e38u: goto P_0c081e38;
case 0x0c081e3au: goto P_0c081e3a;
case 0x0c081e3cu: goto P_0c081e3c;
case 0x0c081e3eu: goto P_0c081e3e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c081098: /* original 4f22, guest PC 0x0c081098 */
if(!s->budget--) { s->failed_pc=0x0c081098u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08109a;
P_0c08109a: /* original 6742, guest PC 0x0c08109a */
if(!s->budget--) { s->failed_pc=0x0c08109au; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c08109c;
P_0c08109c: /* original d330, guest PC 0x0c08109c */
if(!s->budget--) { s->failed_pc=0x0c08109cu; return 0; }
r[3]=read(ram,0x0c081160u,4);
goto P_0c08109e;
P_0c08109e: /* original 4f12, guest PC 0x0c08109e */
if(!s->budget--) { s->failed_pc=0x0c08109eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0810a0;
P_0c0810a0: /* original 6173, guest PC 0x0c0810a0 */
if(!s->budget--) { s->failed_pc=0x0c0810a0u; return 0; }
r[1]=r[7];
goto P_0c0810a2;
P_0c0810a2: /* original 430b, guest PC 0x0c0810a2 */
if(!s->budget--) { s->failed_pc=0x0c0810a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0810a6u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0810a6u) { target=s->pc; goto dispatch; }
goto P_0c0810a6;
P_0c0810a4: /* original 6053, guest PC 0x0c0810a4 */
if(!s->budget--) { s->failed_pc=0x0c0810a4u; return 0; }
r[0]=r[5];
goto P_0c0810a6;
P_0c0810a6: /* original 6603, guest PC 0x0c0810a6 */
if(!s->budget--) { s->failed_pc=0x0c0810a6u; return 0; }
r[6]=r[0];
goto P_0c0810a8;
P_0c0810a8: /* original 6273, guest PC 0x0c0810a8 */
if(!s->budget--) { s->failed_pc=0x0c0810a8u; return 0; }
r[2]=r[7];
goto P_0c0810aa;
P_0c0810aa: /* original 0567, guest PC 0x0c0810aa */
if(!s->budget--) { s->failed_pc=0x0c0810aau; return 0; }
r[19]=r[5]*r[6];
goto P_0c0810ac;
P_0c0810ac: /* original 2462, guest PC 0x0c0810ac */
if(!s->budget--) { s->failed_pc=0x0c0810acu; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0810ae;
P_0c0810ae: /* original 051a, guest PC 0x0c0810ae */
if(!s->budget--) { s->failed_pc=0x0c0810aeu; return 0; }
r[5]=r[19];
goto P_0c0810b0;
P_0c0810b0: /* original 4f16, guest PC 0x0c0810b0 */
if(!s->budget--) { s->failed_pc=0x0c0810b0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810b2;
P_0c0810b2: /* original 3258, guest PC 0x0c0810b2 */
if(!s->budget--) { s->failed_pc=0x0c0810b2u; return 0; }
r[2]-=r[5];
goto P_0c0810b4;
P_0c0810b4: /* original 4f26, guest PC 0x0c0810b4 */
if(!s->budget--) { s->failed_pc=0x0c0810b4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810b6;
P_0c0810b6: /* original 6023, guest PC 0x0c0810b6 */
if(!s->budget--) { s->failed_pc=0x0c0810b6u; return 0; }
r[0]=r[2];
goto P_0c0810b8;
P_0c0810b8: /* original 000b, guest PC 0x0c0810b8 */
if(!s->budget--) { s->failed_pc=0x0c0810b8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0810ba: /* original 0009, guest PC 0x0c0810ba */
if(!s->budget--) { s->failed_pc=0x0c0810bau; return 0; }
if(!vf3_matrix_family(0x0c0810bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0810bcu; return 0; } return 1;
P_0c081978: /* original 2fe6, guest PC 0x0c081978 */
if(!s->budget--) { s->failed_pc=0x0c081978u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08197a;
P_0c08197a: /* original e5f0, guest PC 0x0c08197a */
if(!s->budget--) { s->failed_pc=0x0c08197au; return 0; }
r[5]=0xfffffff0u;
goto P_0c08197c;
P_0c08197c: /* original d319, guest PC 0x0c08197c */
if(!s->budget--) { s->failed_pc=0x0c08197cu; return 0; }
r[3]=read(ram,0x0c0819e4u,4);
goto P_0c08197e;
P_0c08197e: /* original 9029, guest PC 0x0c08197e */
if(!s->budget--) { s->failed_pc=0x0c08197eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0819d4u,2);
goto P_0c081980;
P_0c081980: /* original 6e32, guest PC 0x0c081980 */
if(!s->budget--) { s->failed_pc=0x0c081980u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c081982;
P_0c081982: /* original 4f22, guest PC 0x0c081982 */
if(!s->budget--) { s->failed_pc=0x0c081982u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081984;
P_0c081984: /* original 02ec, guest PC 0x0c081984 */
if(!s->budget--) { s->failed_pc=0x0c081984u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c081986;
P_0c081986: /* original 7ffc, guest PC 0x0c081986 */
if(!s->budget--) { s->failed_pc=0x0c081986u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c081988;
P_0c081988: /* original 66f3, guest PC 0x0c081988 */
if(!s->budget--) { s->failed_pc=0x0c081988u; return 0; }
r[6]=r[15];
goto P_0c08198a;
P_0c08198a: /* original 2f20, guest PC 0x0c08198a */
if(!s->budget--) { s->failed_pc=0x0c08198au; return 0; }
write(ram,r[15],r[2],1);
goto P_0c08198c;
P_0c08198c: /* original b051, guest PC 0x0c08198c */
if(!s->budget--) { s->failed_pc=0x0c08198cu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081990u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081990u) { target=s->pc; goto dispatch; }
goto P_0c081990;
P_0c08198e: /* original 64e3, guest PC 0x0c08198e */
if(!s->budget--) { s->failed_pc=0x0c08198eu; return 0; }
r[4]=r[14];
goto P_0c081990;
P_0c081990: /* original e593, guest PC 0x0c081990 */
if(!s->budget--) { s->failed_pc=0x0c081990u; return 0; }
r[5]=0xffffff93u;
goto P_0c081992;
P_0c081992: /* original 66f3, guest PC 0x0c081992 */
if(!s->budget--) { s->failed_pc=0x0c081992u; return 0; }
r[6]=r[15];
goto P_0c081994;
P_0c081994: /* original b04d, guest PC 0x0c081994 */
if(!s->budget--) { s->failed_pc=0x0c081994u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081998u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081998u) { target=s->pc; goto dispatch; }
goto P_0c081998;
P_0c081996: /* original 64e3, guest PC 0x0c081996 */
if(!s->budget--) { s->failed_pc=0x0c081996u; return 0; }
r[4]=r[14];
goto P_0c081998;
P_0c081998: /* original 62f0, guest PC 0x0c081998 */
if(!s->budget--) { s->failed_pc=0x0c081998u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[2]=tmp;
goto P_0c08199a;
P_0c08199a: /* original 7f04, guest PC 0x0c08199a */
if(!s->budget--) { s->failed_pc=0x0c08199au; return 0; }
r[15]+=0x00000004u;
goto P_0c08199c;
P_0c08199c: /* original 4f26, guest PC 0x0c08199c */
if(!s->budget--) { s->failed_pc=0x0c08199cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08199e;
P_0c08199e: /* original 9019, guest PC 0x0c08199e */
if(!s->budget--) { s->failed_pc=0x0c08199eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0819d4u,2);
goto P_0c0819a0;
P_0c0819a0: /* original 0e24, guest PC 0x0c0819a0 */
if(!s->budget--) { s->failed_pc=0x0c0819a0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0819a2;
P_0c0819a2: /* original 000b, guest PC 0x0c0819a2 */
if(!s->budget--) { s->failed_pc=0x0c0819a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0819a4: /* original 6ef6, guest PC 0x0c0819a4 */
if(!s->budget--) { s->failed_pc=0x0c0819a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0819a6;
P_0c0819a6: /* original 2fe6, guest PC 0x0c0819a6 */
if(!s->budget--) { s->failed_pc=0x0c0819a6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0819a8;
P_0c0819a8: /* original e5f9, guest PC 0x0c0819a8 */
if(!s->budget--) { s->failed_pc=0x0c0819a8u; return 0; }
r[5]=0xfffffff9u;
goto P_0c0819aa;
P_0c0819aa: /* original d30e, guest PC 0x0c0819aa */
if(!s->budget--) { s->failed_pc=0x0c0819aau; return 0; }
r[3]=read(ram,0x0c0819e4u,4);
goto P_0c0819ac;
P_0c0819ac: /* original 9012, guest PC 0x0c0819ac */
if(!s->budget--) { s->failed_pc=0x0c0819acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0819d4u,2);
goto P_0c0819ae;
P_0c0819ae: /* original 6e32, guest PC 0x0c0819ae */
if(!s->budget--) { s->failed_pc=0x0c0819aeu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0819b0;
P_0c0819b0: /* original 4f22, guest PC 0x0c0819b0 */
if(!s->budget--) { s->failed_pc=0x0c0819b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0819b2;
P_0c0819b2: /* original 02ec, guest PC 0x0c0819b2 */
if(!s->budget--) { s->failed_pc=0x0c0819b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0819b4;
P_0c0819b4: /* original 7ffc, guest PC 0x0c0819b4 */
if(!s->budget--) { s->failed_pc=0x0c0819b4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0819b6;
P_0c0819b6: /* original 66f3, guest PC 0x0c0819b6 */
if(!s->budget--) { s->failed_pc=0x0c0819b6u; return 0; }
r[6]=r[15];
goto P_0c0819b8;
P_0c0819b8: /* original 2f20, guest PC 0x0c0819b8 */
if(!s->budget--) { s->failed_pc=0x0c0819b8u; return 0; }
write(ram,r[15],r[2],1);
goto P_0c0819ba;
P_0c0819ba: /* original b03a, guest PC 0x0c0819ba */
if(!s->budget--) { s->failed_pc=0x0c0819bau; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0819beu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0819beu) { target=s->pc; goto dispatch; }
goto P_0c0819be;
P_0c0819bc: /* original 64e3, guest PC 0x0c0819bc */
if(!s->budget--) { s->failed_pc=0x0c0819bcu; return 0; }
r[4]=r[14];
goto P_0c0819be;
P_0c0819be: /* original e59b, guest PC 0x0c0819be */
if(!s->budget--) { s->failed_pc=0x0c0819beu; return 0; }
r[5]=0xffffff9bu;
goto P_0c0819c0;
P_0c0819c0: /* original 66f3, guest PC 0x0c0819c0 */
if(!s->budget--) { s->failed_pc=0x0c0819c0u; return 0; }
r[6]=r[15];
goto P_0c0819c2;
P_0c0819c2: /* original b036, guest PC 0x0c0819c2 */
if(!s->budget--) { s->failed_pc=0x0c0819c2u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0819c6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0819c6u) { target=s->pc; goto dispatch; }
goto P_0c0819c6;
P_0c0819c4: /* original 64e3, guest PC 0x0c0819c4 */
if(!s->budget--) { s->failed_pc=0x0c0819c4u; return 0; }
r[4]=r[14];
goto P_0c0819c6;
P_0c0819c6: /* original 62f0, guest PC 0x0c0819c6 */
if(!s->budget--) { s->failed_pc=0x0c0819c6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[2]=tmp;
goto P_0c0819c8;
P_0c0819c8: /* original 7f04, guest PC 0x0c0819c8 */
if(!s->budget--) { s->failed_pc=0x0c0819c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0819ca;
P_0c0819ca: /* original 4f26, guest PC 0x0c0819ca */
if(!s->budget--) { s->failed_pc=0x0c0819cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0819cc;
P_0c0819cc: /* original 9002, guest PC 0x0c0819cc */
if(!s->budget--) { s->failed_pc=0x0c0819ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0819d4u,2);
goto P_0c0819ce;
P_0c0819ce: /* original 0e24, guest PC 0x0c0819ce */
if(!s->budget--) { s->failed_pc=0x0c0819ceu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0819d0;
P_0c0819d0: /* original 000b, guest PC 0x0c0819d0 */
if(!s->budget--) { s->failed_pc=0x0c0819d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0819d2: /* original 6ef6, guest PC 0x0c0819d2 */
if(!s->budget--) { s->failed_pc=0x0c0819d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0819d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0819d4u; return 0; } return 1;
P_0c0819e8: /* original 2fe6, guest PC 0x0c0819e8 */
if(!s->budget--) { s->failed_pc=0x0c0819e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0819ea;
P_0c0819ea: /* original 2fd6, guest PC 0x0c0819ea */
if(!s->budget--) { s->failed_pc=0x0c0819eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0819ec;
P_0c0819ec: /* original 2fc6, guest PC 0x0c0819ec */
if(!s->budget--) { s->failed_pc=0x0c0819ecu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0819ee;
P_0c0819ee: /* original ec00, guest PC 0x0c0819ee */
if(!s->budget--) { s->failed_pc=0x0c0819eeu; return 0; }
r[12]=0x00000000u;
goto P_0c0819f0;
P_0c0819f0: /* original 2fb6, guest PC 0x0c0819f0 */
if(!s->budget--) { s->failed_pc=0x0c0819f0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0819f2;
P_0c0819f2: /* original 2fa6, guest PC 0x0c0819f2 */
if(!s->budget--) { s->failed_pc=0x0c0819f2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0819f4;
P_0c0819f4: /* original d34e, guest PC 0x0c0819f4 */
if(!s->budget--) { s->failed_pc=0x0c0819f4u; return 0; }
r[3]=read(ram,0x0c081b30u,4);
goto P_0c0819f6;
P_0c0819f6: /* original 9096, guest PC 0x0c0819f6 */
if(!s->budget--) { s->failed_pc=0x0c0819f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081b26u,2);
goto P_0c0819f8;
P_0c0819f8: /* original 6d32, guest PC 0x0c0819f8 */
if(!s->budget--) { s->failed_pc=0x0c0819f8u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c0819fa;
P_0c0819fa: /* original 4f22, guest PC 0x0c0819fa */
if(!s->budget--) { s->failed_pc=0x0c0819fau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0819fc;
P_0c0819fc: /* original 02dc, guest PC 0x0c0819fc */
if(!s->budget--) { s->failed_pc=0x0c0819fcu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0819fe;
P_0c0819fe: /* original 7ffc, guest PC 0x0c0819fe */
if(!s->budget--) { s->failed_pc=0x0c0819feu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c081a00;
P_0c081a00: /* original 2f20, guest PC 0x0c081a00 */
if(!s->budget--) { s->failed_pc=0x0c081a00u; return 0; }
write(ram,r[15],r[2],1);
goto P_0c081a02;
P_0c081a02: /* original da4c, guest PC 0x0c081a02 */
if(!s->budget--) { s->failed_pc=0x0c081a02u; return 0; }
r[10]=read(ram,0x0c081b34u,4);
goto P_0c081a04;
P_0c081a04: /* original 9b90, guest PC 0x0c081a04 */
if(!s->budget--) { s->failed_pc=0x0c081a04u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081b28u,2);
goto P_0c081a06;
P_0c081a06: /* original 60c3, guest PC 0x0c081a06 */
if(!s->budget--) { s->failed_pc=0x0c081a06u; return 0; }
r[0]=r[12];
goto P_0c081a08;
P_0c081a08: /* original 0eac, guest PC 0x0c081a08 */
if(!s->budget--) { s->failed_pc=0x0c081a08u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c081a0a;
P_0c081a0a: /* original 63ec, guest PC 0x0c081a0a */
if(!s->budget--) { s->failed_pc=0x0c081a0au; return 0; }
r[3]=r[14]&255u;
goto P_0c081a0c;
P_0c081a0c: /* original 33b0, guest PC 0x0c081a0c */
if(!s->budget--) { s->failed_pc=0x0c081a0cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c081a0e;
P_0c081a0e: /* original 8905, guest PC 0x0c081a0e */
if(!s->budget--) { s->failed_pc=0x0c081a0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081a1c; }
goto P_0c081a10;
P_0c081a10: /* original 65e3, guest PC 0x0c081a10 */
if(!s->budget--) { s->failed_pc=0x0c081a10u; return 0; }
r[5]=r[14];
goto P_0c081a12;
P_0c081a12: /* original 66f3, guest PC 0x0c081a12 */
if(!s->budget--) { s->failed_pc=0x0c081a12u; return 0; }
r[6]=r[15];
goto P_0c081a14;
P_0c081a14: /* original b00d, guest PC 0x0c081a14 */
if(!s->budget--) { s->failed_pc=0x0c081a14u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081a18u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081a18u) { target=s->pc; goto dispatch; }
goto P_0c081a18;
P_0c081a16: /* original 64d3, guest PC 0x0c081a16 */
if(!s->budget--) { s->failed_pc=0x0c081a16u; return 0; }
r[4]=r[13];
goto P_0c081a18;
P_0c081a18: /* original aff5, guest PC 0x0c081a18 */
if(!s->budget--) { s->failed_pc=0x0c081a18u; return 0; }
r[12]+=0x00000001u;
goto P_0c081a06;
P_0c081a1a: /* original 7c01, guest PC 0x0c081a1a */
if(!s->budget--) { s->failed_pc=0x0c081a1au; return 0; }
r[12]+=0x00000001u;
goto P_0c081a1c;
P_0c081a1c: /* original 62f0, guest PC 0x0c081a1c */
if(!s->budget--) { s->failed_pc=0x0c081a1cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[2]=tmp;
goto P_0c081a1e;
P_0c081a1e: /* original 7f04, guest PC 0x0c081a1e */
if(!s->budget--) { s->failed_pc=0x0c081a1eu; return 0; }
r[15]+=0x00000004u;
goto P_0c081a20;
P_0c081a20: /* original 4f26, guest PC 0x0c081a20 */
if(!s->budget--) { s->failed_pc=0x0c081a20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081a22;
P_0c081a22: /* original 9080, guest PC 0x0c081a22 */
if(!s->budget--) { s->failed_pc=0x0c081a22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081b26u,2);
goto P_0c081a24;
P_0c081a24: /* original 0d24, guest PC 0x0c081a24 */
if(!s->budget--) { s->failed_pc=0x0c081a24u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c081a26;
P_0c081a26: /* original 6af6, guest PC 0x0c081a26 */
if(!s->budget--) { s->failed_pc=0x0c081a26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c081a28;
P_0c081a28: /* original 6bf6, guest PC 0x0c081a28 */
if(!s->budget--) { s->failed_pc=0x0c081a28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c081a2a;
P_0c081a2a: /* original 6cf6, guest PC 0x0c081a2a */
if(!s->budget--) { s->failed_pc=0x0c081a2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c081a2c;
P_0c081a2c: /* original 6df6, guest PC 0x0c081a2c */
if(!s->budget--) { s->failed_pc=0x0c081a2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c081a2e;
P_0c081a2e: /* original 000b, guest PC 0x0c081a2e */
if(!s->budget--) { s->failed_pc=0x0c081a2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081a30: /* original 6ef6, guest PC 0x0c081a30 */
if(!s->budget--) { s->failed_pc=0x0c081a30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c081a32;
P_0c081a32: /* original 937a, guest PC 0x0c081a32 */
if(!s->budget--) { s->failed_pc=0x0c081a32u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081b2au,2);
goto P_0c081a34;
P_0c081a34: /* original 6743, guest PC 0x0c081a34 */
if(!s->budget--) { s->failed_pc=0x0c081a34u; return 0; }
r[7]=r[4];
goto P_0c081a36;
P_0c081a36: /* original 6060, guest PC 0x0c081a36 */
if(!s->budget--) { s->failed_pc=0x0c081a36u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[0]=tmp;
goto P_0c081a38;
P_0c081a38: /* original e10f, guest PC 0x0c081a38 */
if(!s->budget--) { s->failed_pc=0x0c081a38u; return 0; }
r[1]=0x0000000fu;
goto P_0c081a3a;
P_0c081a3a: /* original 373c, guest PC 0x0c081a3a */
if(!s->budget--) { s->failed_pc=0x0c081a3au; return 0; }
r[7]+=r[3];
goto P_0c081a3c;
P_0c081a3c: /* original 0754, guest PC 0x0c081a3c */
if(!s->budget--) { s->failed_pc=0x0c081a3cu; return 0; }
write(ram,r[7]+r[0],r[5],1);
goto P_0c081a3e;
P_0c081a3e: /* original 7001, guest PC 0x0c081a3e */
if(!s->budget--) { s->failed_pc=0x0c081a3eu; return 0; }
r[0]+=0x00000001u;
goto P_0c081a40;
P_0c081a40: /* original 2019, guest PC 0x0c081a40 */
if(!s->budget--) { s->failed_pc=0x0c081a40u; return 0; }
r[0]&=r[1];
goto P_0c081a42;
P_0c081a42: /* original 000b, guest PC 0x0c081a42 */
if(!s->budget--) { s->failed_pc=0x0c081a42u; return 0; }
target=r[16];
write(ram,r[6],r[0],1);
s->pc=target; return ram->oob==0;
P_0c081a44: /* original 2600, guest PC 0x0c081a44 */
if(!s->budget--) { s->failed_pc=0x0c081a44u; return 0; }
write(ram,r[6],r[0],1);
if(!vf3_matrix_family(0x0c081a46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081a46u; return 0; } return 1;
P_0c081d24: /* original 2fe6, guest PC 0x0c081d24 */
if(!s->budget--) { s->failed_pc=0x0c081d24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d26;
P_0c081d26: /* original e307, guest PC 0x0c081d26 */
if(!s->budget--) { s->failed_pc=0x0c081d26u; return 0; }
r[3]=0x00000007u;
goto P_0c081d28;
P_0c081d28: /* original 2fd6, guest PC 0x0c081d28 */
if(!s->budget--) { s->failed_pc=0x0c081d28u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d2a;
P_0c081d2a: /* original 453c, guest PC 0x0c081d2a */
if(!s->budget--) { s->failed_pc=0x0c081d2au; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c081d2c;
P_0c081d2c: /* original 2fc6, guest PC 0x0c081d2c */
if(!s->budget--) { s->failed_pc=0x0c081d2cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d2e;
P_0c081d2e: /* original 6c43, guest PC 0x0c081d2e */
if(!s->budget--) { s->failed_pc=0x0c081d2eu; return 0; }
r[12]=r[4];
goto P_0c081d30;
P_0c081d30: /* original 2fb6, guest PC 0x0c081d30 */
if(!s->budget--) { s->failed_pc=0x0c081d30u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d32;
P_0c081d32: /* original 7c02, guest PC 0x0c081d32 */
if(!s->budget--) { s->failed_pc=0x0c081d32u; return 0; }
r[12]+=0x00000002u;
goto P_0c081d34;
P_0c081d34: /* original 2fa6, guest PC 0x0c081d34 */
if(!s->budget--) { s->failed_pc=0x0c081d34u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d36;
P_0c081d36: /* original 6d63, guest PC 0x0c081d36 */
if(!s->budget--) { s->failed_pc=0x0c081d36u; return 0; }
r[13]=r[6];
goto P_0c081d38;
P_0c081d38: /* original 4f22, guest PC 0x0c081d38 */
if(!s->budget--) { s->failed_pc=0x0c081d38u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081d3a;
P_0c081d3a: /* original db4a, guest PC 0x0c081d3a */
if(!s->budget--) { s->failed_pc=0x0c081d3au; return 0; }
r[11]=read(ram,0x0c081e64u,4);
goto P_0c081d3c;
P_0c081d3c: /* original 4c00, guest PC 0x0c081d3c */
if(!s->budget--) { s->failed_pc=0x0c081d3cu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c081d3e;
P_0c081d3e: /* original de48, guest PC 0x0c081d3e */
if(!s->budget--) { s->failed_pc=0x0c081d3eu; return 0; }
r[14]=read(ram,0x0c081e60u,4);
goto P_0c081d40;
P_0c081d40: /* original 2dd8, guest PC 0x0c081d40 */
if(!s->budget--) { s->failed_pc=0x0c081d40u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c081d42;
P_0c081d42: /* original 2c5b, guest PC 0x0c081d42 */
if(!s->budget--) { s->failed_pc=0x0c081d42u; return 0; }
r[12]|=r[5];
goto P_0c081d44;
P_0c081d44: /* original 8f07, guest PC 0x0c081d44 */
if(!s->budget--) { s->failed_pc=0x0c081d44u; return 0; }
cond=r[17]&1u;
r[10]=0x00000010u;
if(!cond) { goto P_0c081d56; }
goto P_0c081d48;
P_0c081d46: /* original ea10, guest PC 0x0c081d46 */
if(!s->budget--) { s->failed_pc=0x0c081d46u; return 0; }
r[10]=0x00000010u;
goto P_0c081d48;
P_0c081d48: /* original 66e3, guest PC 0x0c081d48 */
if(!s->budget--) { s->failed_pc=0x0c081d48u; return 0; }
r[6]=r[14];
goto P_0c081d4a;
P_0c081d4a: /* original 2fa6, guest PC 0x0c081d4a */
if(!s->budget--) { s->failed_pc=0x0c081d4au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d4c;
P_0c081d4c: /* original 9578, guest PC 0x0c081d4c */
if(!s->budget--) { s->failed_pc=0x0c081d4cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e40u,2);
goto P_0c081d4e;
P_0c081d4e: /* original e700, guest PC 0x0c081d4e */
if(!s->budget--) { s->failed_pc=0x0c081d4eu; return 0; }
r[7]=0x00000000u;
goto P_0c081d50;
P_0c081d50: /* original 4b0b, guest PC 0x0c081d50 */
if(!s->budget--) { s->failed_pc=0x0c081d50u; return 0; }
target=r[11];
r[16]=code_base|0x0c081d54u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081d54u) { target=s->pc; goto dispatch; }
goto P_0c081d54;
P_0c081d52: /* original 64c3, guest PC 0x0c081d52 */
if(!s->budget--) { s->failed_pc=0x0c081d52u; return 0; }
r[4]=r[12];
goto P_0c081d54;
P_0c081d54: /* original 7f04, guest PC 0x0c081d54 */
if(!s->budget--) { s->failed_pc=0x0c081d54u; return 0; }
r[15]+=0x00000004u;
goto P_0c081d56;
P_0c081d56: /* original 60d3, guest PC 0x0c081d56 */
if(!s->budget--) { s->failed_pc=0x0c081d56u; return 0; }
r[0]=r[13];
goto P_0c081d58;
P_0c081d58: /* original 8801, guest PC 0x0c081d58 */
if(!s->budget--) { s->failed_pc=0x0c081d58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081d5a;
P_0c081d5a: /* original 8b06, guest PC 0x0c081d5a */
if(!s->budget--) { s->failed_pc=0x0c081d5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081d6a; }
goto P_0c081d5c;
P_0c081d5c: /* original 66e3, guest PC 0x0c081d5c */
if(!s->budget--) { s->failed_pc=0x0c081d5cu; return 0; }
r[6]=r[14];
goto P_0c081d5e;
P_0c081d5e: /* original 2fa6, guest PC 0x0c081d5e */
if(!s->budget--) { s->failed_pc=0x0c081d5eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d60;
P_0c081d60: /* original 956f, guest PC 0x0c081d60 */
if(!s->budget--) { s->failed_pc=0x0c081d60u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e42u,2);
goto P_0c081d62;
P_0c081d62: /* original e700, guest PC 0x0c081d62 */
if(!s->budget--) { s->failed_pc=0x0c081d62u; return 0; }
r[7]=0x00000000u;
goto P_0c081d64;
P_0c081d64: /* original 4b0b, guest PC 0x0c081d64 */
if(!s->budget--) { s->failed_pc=0x0c081d64u; return 0; }
target=r[11];
r[16]=code_base|0x0c081d68u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081d68u) { target=s->pc; goto dispatch; }
goto P_0c081d68;
P_0c081d66: /* original 64c3, guest PC 0x0c081d66 */
if(!s->budget--) { s->failed_pc=0x0c081d66u; return 0; }
r[4]=r[12];
goto P_0c081d68;
P_0c081d68: /* original 7f04, guest PC 0x0c081d68 */
if(!s->budget--) { s->failed_pc=0x0c081d68u; return 0; }
r[15]+=0x00000004u;
goto P_0c081d6a;
P_0c081d6a: /* original 60d3, guest PC 0x0c081d6a */
if(!s->budget--) { s->failed_pc=0x0c081d6au; return 0; }
r[0]=r[13];
goto P_0c081d6c;
P_0c081d6c: /* original 8802, guest PC 0x0c081d6c */
if(!s->budget--) { s->failed_pc=0x0c081d6cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c081d6e;
P_0c081d6e: /* original 8b06, guest PC 0x0c081d6e */
if(!s->budget--) { s->failed_pc=0x0c081d6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081d7e; }
goto P_0c081d70;
P_0c081d70: /* original 66e3, guest PC 0x0c081d70 */
if(!s->budget--) { s->failed_pc=0x0c081d70u; return 0; }
r[6]=r[14];
goto P_0c081d72;
P_0c081d72: /* original 2fa6, guest PC 0x0c081d72 */
if(!s->budget--) { s->failed_pc=0x0c081d72u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d74;
P_0c081d74: /* original 9566, guest PC 0x0c081d74 */
if(!s->budget--) { s->failed_pc=0x0c081d74u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e44u,2);
goto P_0c081d76;
P_0c081d76: /* original e700, guest PC 0x0c081d76 */
if(!s->budget--) { s->failed_pc=0x0c081d76u; return 0; }
r[7]=0x00000000u;
goto P_0c081d78;
P_0c081d78: /* original 4b0b, guest PC 0x0c081d78 */
if(!s->budget--) { s->failed_pc=0x0c081d78u; return 0; }
target=r[11];
r[16]=code_base|0x0c081d7cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081d7cu) { target=s->pc; goto dispatch; }
goto P_0c081d7c;
P_0c081d7a: /* original 64c3, guest PC 0x0c081d7a */
if(!s->budget--) { s->failed_pc=0x0c081d7au; return 0; }
r[4]=r[12];
goto P_0c081d7c;
P_0c081d7c: /* original 7f04, guest PC 0x0c081d7c */
if(!s->budget--) { s->failed_pc=0x0c081d7cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081d7e;
P_0c081d7e: /* original 60d3, guest PC 0x0c081d7e */
if(!s->budget--) { s->failed_pc=0x0c081d7eu; return 0; }
r[0]=r[13];
goto P_0c081d80;
P_0c081d80: /* original 8804, guest PC 0x0c081d80 */
if(!s->budget--) { s->failed_pc=0x0c081d80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c081d82;
P_0c081d82: /* original 8b06, guest PC 0x0c081d82 */
if(!s->budget--) { s->failed_pc=0x0c081d82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081d92; }
goto P_0c081d84;
P_0c081d84: /* original 66e3, guest PC 0x0c081d84 */
if(!s->budget--) { s->failed_pc=0x0c081d84u; return 0; }
r[6]=r[14];
goto P_0c081d86;
P_0c081d86: /* original 2fa6, guest PC 0x0c081d86 */
if(!s->budget--) { s->failed_pc=0x0c081d86u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d88;
P_0c081d88: /* original 955d, guest PC 0x0c081d88 */
if(!s->budget--) { s->failed_pc=0x0c081d88u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e46u,2);
goto P_0c081d8a;
P_0c081d8a: /* original e700, guest PC 0x0c081d8a */
if(!s->budget--) { s->failed_pc=0x0c081d8au; return 0; }
r[7]=0x00000000u;
goto P_0c081d8c;
P_0c081d8c: /* original 4b0b, guest PC 0x0c081d8c */
if(!s->budget--) { s->failed_pc=0x0c081d8cu; return 0; }
target=r[11];
r[16]=code_base|0x0c081d90u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081d90u) { target=s->pc; goto dispatch; }
goto P_0c081d90;
P_0c081d8e: /* original 64c3, guest PC 0x0c081d8e */
if(!s->budget--) { s->failed_pc=0x0c081d8eu; return 0; }
r[4]=r[12];
goto P_0c081d90;
P_0c081d90: /* original 7f04, guest PC 0x0c081d90 */
if(!s->budget--) { s->failed_pc=0x0c081d90u; return 0; }
r[15]+=0x00000004u;
goto P_0c081d92;
P_0c081d92: /* original 60d3, guest PC 0x0c081d92 */
if(!s->budget--) { s->failed_pc=0x0c081d92u; return 0; }
r[0]=r[13];
goto P_0c081d94;
P_0c081d94: /* original 8808, guest PC 0x0c081d94 */
if(!s->budget--) { s->failed_pc=0x0c081d94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c081d96;
P_0c081d96: /* original 8b06, guest PC 0x0c081d96 */
if(!s->budget--) { s->failed_pc=0x0c081d96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081da6; }
goto P_0c081d98;
P_0c081d98: /* original 66e3, guest PC 0x0c081d98 */
if(!s->budget--) { s->failed_pc=0x0c081d98u; return 0; }
r[6]=r[14];
goto P_0c081d9a;
P_0c081d9a: /* original 2fa6, guest PC 0x0c081d9a */
if(!s->budget--) { s->failed_pc=0x0c081d9au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d9c;
P_0c081d9c: /* original 9554, guest PC 0x0c081d9c */
if(!s->budget--) { s->failed_pc=0x0c081d9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e48u,2);
goto P_0c081d9e;
P_0c081d9e: /* original e700, guest PC 0x0c081d9e */
if(!s->budget--) { s->failed_pc=0x0c081d9eu; return 0; }
r[7]=0x00000000u;
goto P_0c081da0;
P_0c081da0: /* original 4b0b, guest PC 0x0c081da0 */
if(!s->budget--) { s->failed_pc=0x0c081da0u; return 0; }
target=r[11];
r[16]=code_base|0x0c081da4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081da4u) { target=s->pc; goto dispatch; }
goto P_0c081da4;
P_0c081da2: /* original 64c3, guest PC 0x0c081da2 */
if(!s->budget--) { s->failed_pc=0x0c081da2u; return 0; }
r[4]=r[12];
goto P_0c081da4;
P_0c081da4: /* original 7f04, guest PC 0x0c081da4 */
if(!s->budget--) { s->failed_pc=0x0c081da4u; return 0; }
r[15]+=0x00000004u;
goto P_0c081da6;
P_0c081da6: /* original 60d3, guest PC 0x0c081da6 */
if(!s->budget--) { s->failed_pc=0x0c081da6u; return 0; }
r[0]=r[13];
goto P_0c081da8;
P_0c081da8: /* original 8810, guest PC 0x0c081da8 */
if(!s->budget--) { s->failed_pc=0x0c081da8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c081daa;
P_0c081daa: /* original 8b06, guest PC 0x0c081daa */
if(!s->budget--) { s->failed_pc=0x0c081daau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081dba; }
goto P_0c081dac;
P_0c081dac: /* original 66e3, guest PC 0x0c081dac */
if(!s->budget--) { s->failed_pc=0x0c081dacu; return 0; }
r[6]=r[14];
goto P_0c081dae;
P_0c081dae: /* original 2fa6, guest PC 0x0c081dae */
if(!s->budget--) { s->failed_pc=0x0c081daeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081db0;
P_0c081db0: /* original 954b, guest PC 0x0c081db0 */
if(!s->budget--) { s->failed_pc=0x0c081db0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e4au,2);
goto P_0c081db2;
P_0c081db2: /* original e700, guest PC 0x0c081db2 */
if(!s->budget--) { s->failed_pc=0x0c081db2u; return 0; }
r[7]=0x00000000u;
goto P_0c081db4;
P_0c081db4: /* original 4b0b, guest PC 0x0c081db4 */
if(!s->budget--) { s->failed_pc=0x0c081db4u; return 0; }
target=r[11];
r[16]=code_base|0x0c081db8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081db8u) { target=s->pc; goto dispatch; }
goto P_0c081db8;
P_0c081db6: /* original 64c3, guest PC 0x0c081db6 */
if(!s->budget--) { s->failed_pc=0x0c081db6u; return 0; }
r[4]=r[12];
goto P_0c081db8;
P_0c081db8: /* original 7f04, guest PC 0x0c081db8 */
if(!s->budget--) { s->failed_pc=0x0c081db8u; return 0; }
r[15]+=0x00000004u;
goto P_0c081dba;
P_0c081dba: /* original 60d3, guest PC 0x0c081dba */
if(!s->budget--) { s->failed_pc=0x0c081dbau; return 0; }
r[0]=r[13];
goto P_0c081dbc;
P_0c081dbc: /* original 8820, guest PC 0x0c081dbc */
if(!s->budget--) { s->failed_pc=0x0c081dbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c081dbe;
P_0c081dbe: /* original 8b06, guest PC 0x0c081dbe */
if(!s->budget--) { s->failed_pc=0x0c081dbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081dce; }
goto P_0c081dc0;
P_0c081dc0: /* original 66e3, guest PC 0x0c081dc0 */
if(!s->budget--) { s->failed_pc=0x0c081dc0u; return 0; }
r[6]=r[14];
goto P_0c081dc2;
P_0c081dc2: /* original 2fa6, guest PC 0x0c081dc2 */
if(!s->budget--) { s->failed_pc=0x0c081dc2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081dc4;
P_0c081dc4: /* original 9542, guest PC 0x0c081dc4 */
if(!s->budget--) { s->failed_pc=0x0c081dc4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e4cu,2);
goto P_0c081dc6;
P_0c081dc6: /* original e700, guest PC 0x0c081dc6 */
if(!s->budget--) { s->failed_pc=0x0c081dc6u; return 0; }
r[7]=0x00000000u;
goto P_0c081dc8;
P_0c081dc8: /* original 4b0b, guest PC 0x0c081dc8 */
if(!s->budget--) { s->failed_pc=0x0c081dc8u; return 0; }
target=r[11];
r[16]=code_base|0x0c081dccu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081dccu) { target=s->pc; goto dispatch; }
goto P_0c081dcc;
P_0c081dca: /* original 64c3, guest PC 0x0c081dca */
if(!s->budget--) { s->failed_pc=0x0c081dcau; return 0; }
r[4]=r[12];
goto P_0c081dcc;
P_0c081dcc: /* original 7f04, guest PC 0x0c081dcc */
if(!s->budget--) { s->failed_pc=0x0c081dccu; return 0; }
r[15]+=0x00000004u;
goto P_0c081dce;
P_0c081dce: /* original 60d3, guest PC 0x0c081dce */
if(!s->budget--) { s->failed_pc=0x0c081dceu; return 0; }
r[0]=r[13];
goto P_0c081dd0;
P_0c081dd0: /* original 8840, guest PC 0x0c081dd0 */
if(!s->budget--) { s->failed_pc=0x0c081dd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c081dd2;
P_0c081dd2: /* original 8b06, guest PC 0x0c081dd2 */
if(!s->budget--) { s->failed_pc=0x0c081dd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081de2; }
goto P_0c081dd4;
P_0c081dd4: /* original 66e3, guest PC 0x0c081dd4 */
if(!s->budget--) { s->failed_pc=0x0c081dd4u; return 0; }
r[6]=r[14];
goto P_0c081dd6;
P_0c081dd6: /* original 2fa6, guest PC 0x0c081dd6 */
if(!s->budget--) { s->failed_pc=0x0c081dd6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081dd8;
P_0c081dd8: /* original 9539, guest PC 0x0c081dd8 */
if(!s->budget--) { s->failed_pc=0x0c081dd8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e4eu,2);
goto P_0c081dda;
P_0c081dda: /* original e700, guest PC 0x0c081dda */
if(!s->budget--) { s->failed_pc=0x0c081ddau; return 0; }
r[7]=0x00000000u;
goto P_0c081ddc;
P_0c081ddc: /* original 4b0b, guest PC 0x0c081ddc */
if(!s->budget--) { s->failed_pc=0x0c081ddcu; return 0; }
target=r[11];
r[16]=code_base|0x0c081de0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081de0u) { target=s->pc; goto dispatch; }
goto P_0c081de0;
P_0c081dde: /* original 64c3, guest PC 0x0c081dde */
if(!s->budget--) { s->failed_pc=0x0c081ddeu; return 0; }
r[4]=r[12];
goto P_0c081de0;
P_0c081de0: /* original 7f04, guest PC 0x0c081de0 */
if(!s->budget--) { s->failed_pc=0x0c081de0u; return 0; }
r[15]+=0x00000004u;
goto P_0c081de2;
P_0c081de2: /* original 9235, guest PC 0x0c081de2 */
if(!s->budget--) { s->failed_pc=0x0c081de2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e50u,2);
goto P_0c081de4;
P_0c081de4: /* original 3d20, guest PC 0x0c081de4 */
if(!s->budget--) { s->failed_pc=0x0c081de4u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081de6;
P_0c081de6: /* original 8b06, guest PC 0x0c081de6 */
if(!s->budget--) { s->failed_pc=0x0c081de6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081df6; }
goto P_0c081de8;
P_0c081de8: /* original 66e3, guest PC 0x0c081de8 */
if(!s->budget--) { s->failed_pc=0x0c081de8u; return 0; }
r[6]=r[14];
goto P_0c081dea;
P_0c081dea: /* original 2fa6, guest PC 0x0c081dea */
if(!s->budget--) { s->failed_pc=0x0c081deau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081dec;
P_0c081dec: /* original 9531, guest PC 0x0c081dec */
if(!s->budget--) { s->failed_pc=0x0c081decu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e52u,2);
goto P_0c081dee;
P_0c081dee: /* original e700, guest PC 0x0c081dee */
if(!s->budget--) { s->failed_pc=0x0c081deeu; return 0; }
r[7]=0x00000000u;
goto P_0c081df0;
P_0c081df0: /* original 4b0b, guest PC 0x0c081df0 */
if(!s->budget--) { s->failed_pc=0x0c081df0u; return 0; }
target=r[11];
r[16]=code_base|0x0c081df4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081df4u) { target=s->pc; goto dispatch; }
goto P_0c081df4;
P_0c081df2: /* original 64c3, guest PC 0x0c081df2 */
if(!s->budget--) { s->failed_pc=0x0c081df2u; return 0; }
r[4]=r[12];
goto P_0c081df4;
P_0c081df4: /* original 7f04, guest PC 0x0c081df4 */
if(!s->budget--) { s->failed_pc=0x0c081df4u; return 0; }
r[15]+=0x00000004u;
goto P_0c081df6;
P_0c081df6: /* original 922d, guest PC 0x0c081df6 */
if(!s->budget--) { s->failed_pc=0x0c081df6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e54u,2);
goto P_0c081df8;
P_0c081df8: /* original 3d20, guest PC 0x0c081df8 */
if(!s->budget--) { s->failed_pc=0x0c081df8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081dfa;
P_0c081dfa: /* original 8b06, guest PC 0x0c081dfa */
if(!s->budget--) { s->failed_pc=0x0c081dfau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081e0a; }
goto P_0c081dfc;
P_0c081dfc: /* original 66e3, guest PC 0x0c081dfc */
if(!s->budget--) { s->failed_pc=0x0c081dfcu; return 0; }
r[6]=r[14];
goto P_0c081dfe;
P_0c081dfe: /* original 2fa6, guest PC 0x0c081dfe */
if(!s->budget--) { s->failed_pc=0x0c081dfeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e00;
P_0c081e00: /* original 9529, guest PC 0x0c081e00 */
if(!s->budget--) { s->failed_pc=0x0c081e00u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e56u,2);
goto P_0c081e02;
P_0c081e02: /* original e700, guest PC 0x0c081e02 */
if(!s->budget--) { s->failed_pc=0x0c081e02u; return 0; }
r[7]=0x00000000u;
goto P_0c081e04;
P_0c081e04: /* original 4b0b, guest PC 0x0c081e04 */
if(!s->budget--) { s->failed_pc=0x0c081e04u; return 0; }
target=r[11];
r[16]=code_base|0x0c081e08u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081e08u) { target=s->pc; goto dispatch; }
goto P_0c081e08;
P_0c081e06: /* original 64c3, guest PC 0x0c081e06 */
if(!s->budget--) { s->failed_pc=0x0c081e06u; return 0; }
r[4]=r[12];
goto P_0c081e08;
P_0c081e08: /* original 7f04, guest PC 0x0c081e08 */
if(!s->budget--) { s->failed_pc=0x0c081e08u; return 0; }
r[15]+=0x00000004u;
goto P_0c081e0a;
P_0c081e0a: /* original 9225, guest PC 0x0c081e0a */
if(!s->budget--) { s->failed_pc=0x0c081e0au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e58u,2);
goto P_0c081e0c;
P_0c081e0c: /* original 3d20, guest PC 0x0c081e0c */
if(!s->budget--) { s->failed_pc=0x0c081e0cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081e0e;
P_0c081e0e: /* original 8b06, guest PC 0x0c081e0e */
if(!s->budget--) { s->failed_pc=0x0c081e0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081e1e; }
goto P_0c081e10;
P_0c081e10: /* original 66e3, guest PC 0x0c081e10 */
if(!s->budget--) { s->failed_pc=0x0c081e10u; return 0; }
r[6]=r[14];
goto P_0c081e12;
P_0c081e12: /* original 2fa6, guest PC 0x0c081e12 */
if(!s->budget--) { s->failed_pc=0x0c081e12u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e14;
P_0c081e14: /* original 9521, guest PC 0x0c081e14 */
if(!s->budget--) { s->failed_pc=0x0c081e14u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e5au,2);
goto P_0c081e16;
P_0c081e16: /* original e700, guest PC 0x0c081e16 */
if(!s->budget--) { s->failed_pc=0x0c081e16u; return 0; }
r[7]=0x00000000u;
goto P_0c081e18;
P_0c081e18: /* original 4b0b, guest PC 0x0c081e18 */
if(!s->budget--) { s->failed_pc=0x0c081e18u; return 0; }
target=r[11];
r[16]=code_base|0x0c081e1cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081e1cu) { target=s->pc; goto dispatch; }
goto P_0c081e1c;
P_0c081e1a: /* original 64c3, guest PC 0x0c081e1a */
if(!s->budget--) { s->failed_pc=0x0c081e1au; return 0; }
r[4]=r[12];
goto P_0c081e1c;
P_0c081e1c: /* original 7f04, guest PC 0x0c081e1c */
if(!s->budget--) { s->failed_pc=0x0c081e1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081e1e;
P_0c081e1e: /* original 921d, guest PC 0x0c081e1e */
if(!s->budget--) { s->failed_pc=0x0c081e1eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e5cu,2);
goto P_0c081e20;
P_0c081e20: /* original 3d20, guest PC 0x0c081e20 */
if(!s->budget--) { s->failed_pc=0x0c081e20u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081e22;
P_0c081e22: /* original 8b06, guest PC 0x0c081e22 */
if(!s->budget--) { s->failed_pc=0x0c081e22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081e32; }
goto P_0c081e24;
P_0c081e24: /* original 66e3, guest PC 0x0c081e24 */
if(!s->budget--) { s->failed_pc=0x0c081e24u; return 0; }
r[6]=r[14];
goto P_0c081e26;
P_0c081e26: /* original 2fa6, guest PC 0x0c081e26 */
if(!s->budget--) { s->failed_pc=0x0c081e26u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e28;
P_0c081e28: /* original 9519, guest PC 0x0c081e28 */
if(!s->budget--) { s->failed_pc=0x0c081e28u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e5eu,2);
goto P_0c081e2a;
P_0c081e2a: /* original e700, guest PC 0x0c081e2a */
if(!s->budget--) { s->failed_pc=0x0c081e2au; return 0; }
r[7]=0x00000000u;
goto P_0c081e2c;
P_0c081e2c: /* original 4b0b, guest PC 0x0c081e2c */
if(!s->budget--) { s->failed_pc=0x0c081e2cu; return 0; }
target=r[11];
r[16]=code_base|0x0c081e30u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081e30u) { target=s->pc; goto dispatch; }
goto P_0c081e30;
P_0c081e2e: /* original 64c3, guest PC 0x0c081e2e */
if(!s->budget--) { s->failed_pc=0x0c081e2eu; return 0; }
r[4]=r[12];
goto P_0c081e30;
P_0c081e30: /* original 7f04, guest PC 0x0c081e30 */
if(!s->budget--) { s->failed_pc=0x0c081e30u; return 0; }
r[15]+=0x00000004u;
goto P_0c081e32;
P_0c081e32: /* original 4f26, guest PC 0x0c081e32 */
if(!s->budget--) { s->failed_pc=0x0c081e32u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081e34;
P_0c081e34: /* original 6af6, guest PC 0x0c081e34 */
if(!s->budget--) { s->failed_pc=0x0c081e34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c081e36;
P_0c081e36: /* original 6bf6, guest PC 0x0c081e36 */
if(!s->budget--) { s->failed_pc=0x0c081e36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c081e38;
P_0c081e38: /* original 6cf6, guest PC 0x0c081e38 */
if(!s->budget--) { s->failed_pc=0x0c081e38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c081e3a;
P_0c081e3a: /* original 6df6, guest PC 0x0c081e3a */
if(!s->budget--) { s->failed_pc=0x0c081e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c081e3c;
P_0c081e3c: /* original 000b, guest PC 0x0c081e3c */
if(!s->budget--) { s->failed_pc=0x0c081e3cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081e3e: /* original 6ef6, guest PC 0x0c081e3e */
if(!s->budget--) { s->failed_pc=0x0c081e3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c081e40u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081e40u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
