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
int vf3_away_batch49_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c07b4d4u: goto P_0c07b4d4;
case 0x0c07b4d6u: goto P_0c07b4d6;
case 0x0c07b4d8u: goto P_0c07b4d8;
case 0x0c07b4dau: goto P_0c07b4da;
case 0x0c07b4dcu: goto P_0c07b4dc;
case 0x0c07b4deu: goto P_0c07b4de;
case 0x0c07b4e0u: goto P_0c07b4e0;
case 0x0c07b4e2u: goto P_0c07b4e2;
case 0x0c07b4e4u: goto P_0c07b4e4;
case 0x0c07b4e6u: goto P_0c07b4e6;
case 0x0c07b4e8u: goto P_0c07b4e8;
case 0x0c07b4eau: goto P_0c07b4ea;
case 0x0c07b4ecu: goto P_0c07b4ec;
case 0x0c07b4eeu: goto P_0c07b4ee;
case 0x0c07b4f0u: goto P_0c07b4f0;
case 0x0c07b4f2u: goto P_0c07b4f2;
case 0x0c07b4f4u: goto P_0c07b4f4;
case 0x0c07b4f6u: goto P_0c07b4f6;
case 0x0c07b4f8u: goto P_0c07b4f8;
case 0x0c07b4fau: goto P_0c07b4fa;
case 0x0c07b4fcu: goto P_0c07b4fc;
case 0x0c07b4feu: goto P_0c07b4fe;
case 0x0c07b500u: goto P_0c07b500;
case 0x0c07b502u: goto P_0c07b502;
case 0x0c07b504u: goto P_0c07b504;
case 0x0c07b506u: goto P_0c07b506;
case 0x0c07b508u: goto P_0c07b508;
case 0x0c07b50au: goto P_0c07b50a;
case 0x0c07b50cu: goto P_0c07b50c;
case 0x0c07b50eu: goto P_0c07b50e;
case 0x0c07b510u: goto P_0c07b510;
case 0x0c07b512u: goto P_0c07b512;
case 0x0c07b514u: goto P_0c07b514;
case 0x0c07b516u: goto P_0c07b516;
case 0x0c07b518u: goto P_0c07b518;
case 0x0c07b51au: goto P_0c07b51a;
case 0x0c07b51cu: goto P_0c07b51c;
case 0x0c07b51eu: goto P_0c07b51e;
case 0x0c07b520u: goto P_0c07b520;
case 0x0c07b522u: goto P_0c07b522;
case 0x0c07b524u: goto P_0c07b524;
case 0x0c07b526u: goto P_0c07b526;
case 0x0c07b528u: goto P_0c07b528;
case 0x0c07b52au: goto P_0c07b52a;
case 0x0c07b52cu: goto P_0c07b52c;
case 0x0c07b52eu: goto P_0c07b52e;
case 0x0c07b530u: goto P_0c07b530;
case 0x0c07b532u: goto P_0c07b532;
case 0x0c07b534u: goto P_0c07b534;
case 0x0c07b536u: goto P_0c07b536;
case 0x0c07b538u: goto P_0c07b538;
case 0x0c07b53au: goto P_0c07b53a;
case 0x0c07b53cu: goto P_0c07b53c;
case 0x0c07b53eu: goto P_0c07b53e;
case 0x0c07b540u: goto P_0c07b540;
case 0x0c07b542u: goto P_0c07b542;
case 0x0c07b544u: goto P_0c07b544;
case 0x0c07b546u: goto P_0c07b546;
case 0x0c07b548u: goto P_0c07b548;
case 0x0c07b54au: goto P_0c07b54a;
case 0x0c07b54cu: goto P_0c07b54c;
case 0x0c07b54eu: goto P_0c07b54e;
case 0x0c07b550u: goto P_0c07b550;
case 0x0c07b552u: goto P_0c07b552;
case 0x0c07b554u: goto P_0c07b554;
case 0x0c07b556u: goto P_0c07b556;
case 0x0c07b558u: goto P_0c07b558;
case 0x0c07b55au: goto P_0c07b55a;
case 0x0c07b55cu: goto P_0c07b55c;
case 0x0c07b55eu: goto P_0c07b55e;
case 0x0c07b560u: goto P_0c07b560;
case 0x0c07b562u: goto P_0c07b562;
case 0x0c07b564u: goto P_0c07b564;
case 0x0c07b566u: goto P_0c07b566;
case 0x0c07b568u: goto P_0c07b568;
case 0x0c07b56au: goto P_0c07b56a;
case 0x0c07b56cu: goto P_0c07b56c;
case 0x0c07b56eu: goto P_0c07b56e;
case 0x0c07b570u: goto P_0c07b570;
case 0x0c07b572u: goto P_0c07b572;
case 0x0c07b574u: goto P_0c07b574;
case 0x0c07b576u: goto P_0c07b576;
case 0x0c07b578u: goto P_0c07b578;
case 0x0c07b57au: goto P_0c07b57a;
case 0x0c07b57cu: goto P_0c07b57c;
case 0x0c07b57eu: goto P_0c07b57e;
case 0x0c07b580u: goto P_0c07b580;
case 0x0c07b582u: goto P_0c07b582;
case 0x0c07b584u: goto P_0c07b584;
case 0x0c07b586u: goto P_0c07b586;
case 0x0c07b588u: goto P_0c07b588;
case 0x0c07b58au: goto P_0c07b58a;
case 0x0c07b58cu: goto P_0c07b58c;
case 0x0c07b58eu: goto P_0c07b58e;
case 0x0c07b590u: goto P_0c07b590;
case 0x0c07b592u: goto P_0c07b592;
case 0x0c07b594u: goto P_0c07b594;
case 0x0c07b596u: goto P_0c07b596;
case 0x0c07b598u: goto P_0c07b598;
case 0x0c07b59au: goto P_0c07b59a;
case 0x0c07b59cu: goto P_0c07b59c;
case 0x0c07b59eu: goto P_0c07b59e;
case 0x0c07b5a0u: goto P_0c07b5a0;
case 0x0c07b5a2u: goto P_0c07b5a2;
case 0x0c07b5a4u: goto P_0c07b5a4;
case 0x0c07b5a6u: goto P_0c07b5a6;
case 0x0c07b5a8u: goto P_0c07b5a8;
case 0x0c07b5aau: goto P_0c07b5aa;
case 0x0c07b5acu: goto P_0c07b5ac;
case 0x0c07b5aeu: goto P_0c07b5ae;
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
case 0x0c081ce8u: goto P_0c081ce8;
case 0x0c081ceau: goto P_0c081cea;
case 0x0c081cecu: goto P_0c081cec;
case 0x0c081ceeu: goto P_0c081cee;
case 0x0c081cf0u: goto P_0c081cf0;
case 0x0c081cf2u: goto P_0c081cf2;
case 0x0c081cf4u: goto P_0c081cf4;
case 0x0c081cf6u: goto P_0c081cf6;
case 0x0c081cf8u: goto P_0c081cf8;
case 0x0c081cfau: goto P_0c081cfa;
case 0x0c081cfcu: goto P_0c081cfc;
case 0x0c081cfeu: goto P_0c081cfe;
case 0x0c081d00u: goto P_0c081d00;
case 0x0c081d02u: goto P_0c081d02;
case 0x0c081d04u: goto P_0c081d04;
case 0x0c081d06u: goto P_0c081d06;
case 0x0c081d08u: goto P_0c081d08;
case 0x0c081d0au: goto P_0c081d0a;
case 0x0c081d0cu: goto P_0c081d0c;
case 0x0c081d0eu: goto P_0c081d0e;
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
P_0c07b4d4: /* original 654d, guest PC 0x0c07b4d4 */
if(!s->budget--) { s->failed_pc=0x0c07b4d4u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b4d6;
P_0c07b4d6: /* original 2fe6, guest PC 0x0c07b4d6 */
if(!s->budget--) { s->failed_pc=0x0c07b4d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4d8;
P_0c07b4d8: /* original 2fd6, guest PC 0x0c07b4d8 */
if(!s->budget--) { s->failed_pc=0x0c07b4d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4da;
P_0c07b4da: /* original 9378, guest PC 0x0c07b4da */
if(!s->budget--) { s->failed_pc=0x0c07b4dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b4dc;
P_0c07b4dc: /* original 2358, guest PC 0x0c07b4dc */
if(!s->budget--) { s->failed_pc=0x0c07b4dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c07b4de;
P_0c07b4de: /* original 8912, guest PC 0x0c07b4de */
if(!s->budget--) { s->failed_pc=0x0c07b4deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b506; }
goto P_0c07b4e0;
P_0c07b4e0: /* original 9476, guest PC 0x0c07b4e0 */
if(!s->budget--) { s->failed_pc=0x0c07b4e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b4e2;
P_0c07b4e2: /* original d23c, guest PC 0x0c07b4e2 */
if(!s->budget--) { s->failed_pc=0x0c07b4e2u; return 0; }
r[2]=read(ram,0x0c07b5d4u,4);
goto P_0c07b4e4;
P_0c07b4e4: /* original 2459, guest PC 0x0c07b4e4 */
if(!s->budget--) { s->failed_pc=0x0c07b4e4u; return 0; }
r[4]&=r[5];
goto P_0c07b4e6;
P_0c07b4e6: /* original 6343, guest PC 0x0c07b4e6 */
if(!s->budget--) { s->failed_pc=0x0c07b4e6u; return 0; }
r[3]=r[4];
goto P_0c07b4e8;
P_0c07b4e8: /* original 6543, guest PC 0x0c07b4e8 */
if(!s->budget--) { s->failed_pc=0x0c07b4e8u; return 0; }
r[5]=r[4];
goto P_0c07b4ea;
P_0c07b4ea: /* original 4308, guest PC 0x0c07b4ea */
if(!s->budget--) { s->failed_pc=0x0c07b4eau; return 0; }
r[3]<<=2;
goto P_0c07b4ec;
P_0c07b4ec: /* original 4500, guest PC 0x0c07b4ec */
if(!s->budget--) { s->failed_pc=0x0c07b4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b4ee;
P_0c07b4ee: /* original 353c, guest PC 0x0c07b4ee */
if(!s->budget--) { s->failed_pc=0x0c07b4eeu; return 0; }
r[5]+=r[3];
goto P_0c07b4f0;
P_0c07b4f0: /* original 352c, guest PC 0x0c07b4f0 */
if(!s->budget--) { s->failed_pc=0x0c07b4f0u; return 0; }
r[5]+=r[2];
goto P_0c07b4f2;
P_0c07b4f2: /* original 8452, guest PC 0x0c07b4f2 */
if(!s->budget--) { s->failed_pc=0x0c07b4f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+2,1);
goto P_0c07b4f4;
P_0c07b4f4: /* original 6451, guest PC 0x0c07b4f4 */
if(!s->budget--) { s->failed_pc=0x0c07b4f4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[4]=tmp;
goto P_0c07b4f6;
P_0c07b4f6: /* original 660c, guest PC 0x0c07b4f6 */
if(!s->budget--) { s->failed_pc=0x0c07b4f6u; return 0; }
r[6]=r[0]&255u;
goto P_0c07b4f8;
P_0c07b4f8: /* original 8453, guest PC 0x0c07b4f8 */
if(!s->budget--) { s->failed_pc=0x0c07b4f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c07b4fa;
P_0c07b4fa: /* original 670c, guest PC 0x0c07b4fa */
if(!s->budget--) { s->failed_pc=0x0c07b4fau; return 0; }
r[7]=r[0]&255u;
goto P_0c07b4fc;
P_0c07b4fc: /* original 8454, guest PC 0x0c07b4fc */
if(!s->budget--) { s->failed_pc=0x0c07b4fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c07b4fe;
P_0c07b4fe: /* original 6e0c, guest PC 0x0c07b4fe */
if(!s->budget--) { s->failed_pc=0x0c07b4feu; return 0; }
r[14]=r[0]&255u;
goto P_0c07b500;
P_0c07b500: /* original 8455, guest PC 0x0c07b500 */
if(!s->budget--) { s->failed_pc=0x0c07b500u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c07b502;
P_0c07b502: /* original a00a, guest PC 0x0c07b502 */
if(!s->budget--) { s->failed_pc=0x0c07b502u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b51a;
P_0c07b504: /* original 6d0c, guest PC 0x0c07b504 */
if(!s->budget--) { s->failed_pc=0x0c07b504u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b506;
P_0c07b506: /* original e500, guest PC 0x0c07b506 */
if(!s->budget--) { s->failed_pc=0x0c07b506u; return 0; }
r[5]=0x00000000u;
goto P_0c07b508;
P_0c07b508: /* original d333, guest PC 0x0c07b508 */
if(!s->budget--) { s->failed_pc=0x0c07b508u; return 0; }
r[3]=read(ram,0x0c07b5d8u,4);
goto P_0c07b50a;
P_0c07b50a: /* original 6753, guest PC 0x0c07b50a */
if(!s->budget--) { s->failed_pc=0x0c07b50au; return 0; }
r[7]=r[5];
goto P_0c07b50c;
P_0c07b50c: /* original 6653, guest PC 0x0c07b50c */
if(!s->budget--) { s->failed_pc=0x0c07b50cu; return 0; }
r[6]=r[5];
goto P_0c07b50e;
P_0c07b50e: /* original 654d, guest PC 0x0c07b50e */
if(!s->budget--) { s->failed_pc=0x0c07b50eu; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b510;
P_0c07b510: /* original 4508, guest PC 0x0c07b510 */
if(!s->budget--) { s->failed_pc=0x0c07b510u; return 0; }
r[5]<<=2;
goto P_0c07b512;
P_0c07b512: /* original 353c, guest PC 0x0c07b512 */
if(!s->budget--) { s->failed_pc=0x0c07b512u; return 0; }
r[5]+=r[3];
goto P_0c07b514;
P_0c07b514: /* original 8551, guest PC 0x0c07b514 */
if(!s->budget--) { s->failed_pc=0x0c07b514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b516;
P_0c07b516: /* original 6e51, guest PC 0x0c07b516 */
if(!s->budget--) { s->failed_pc=0x0c07b516u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[14]=tmp;
goto P_0c07b518;
P_0c07b518: /* original 6d03, guest PC 0x0c07b518 */
if(!s->budget--) { s->failed_pc=0x0c07b518u; return 0; }
r[13]=r[0];
goto P_0c07b51a;
P_0c07b51a: /* original 666d, guest PC 0x0c07b51a */
if(!s->budget--) { s->failed_pc=0x0c07b51au; return 0; }
r[6]=r[6]&65535u;
goto P_0c07b51c;
P_0c07b51c: /* original d22f, guest PC 0x0c07b51c */
if(!s->budget--) { s->failed_pc=0x0c07b51cu; return 0; }
r[2]=read(ram,0x0c07b5dcu,4);
goto P_0c07b51e;
P_0c07b51e: /* original 4608, guest PC 0x0c07b51e */
if(!s->budget--) { s->failed_pc=0x0c07b51eu; return 0; }
r[6]<<=2;
goto P_0c07b520;
P_0c07b520: /* original 4600, guest PC 0x0c07b520 */
if(!s->budget--) { s->failed_pc=0x0c07b520u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07b522;
P_0c07b522: /* original 677d, guest PC 0x0c07b522 */
if(!s->budget--) { s->failed_pc=0x0c07b522u; return 0; }
r[7]=r[7]&65535u;
goto P_0c07b524;
P_0c07b524: /* original 4708, guest PC 0x0c07b524 */
if(!s->budget--) { s->failed_pc=0x0c07b524u; return 0; }
r[7]<<=2;
goto P_0c07b526;
P_0c07b526: /* original 634d, guest PC 0x0c07b526 */
if(!s->budget--) { s->failed_pc=0x0c07b526u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b528;
P_0c07b528: /* original 2232, guest PC 0x0c07b528 */
if(!s->budget--) { s->failed_pc=0x0c07b528u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07b52a;
P_0c07b52a: /* original 4700, guest PC 0x0c07b52a */
if(!s->budget--) { s->failed_pc=0x0c07b52au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c07b52c;
P_0c07b52c: /* original 465a, guest PC 0x0c07b52c */
if(!s->budget--) { s->failed_pc=0x0c07b52cu; return 0; }
r[53]=r[6];
goto P_0c07b52e;
P_0c07b52e: /* original 6eed, guest PC 0x0c07b52e */
if(!s->budget--) { s->failed_pc=0x0c07b52eu; return 0; }
r[14]=r[14]&65535u;
goto P_0c07b530;
P_0c07b530: /* original d32b, guest PC 0x0c07b530 */
if(!s->budget--) { s->failed_pc=0x0c07b530u; return 0; }
r[3]=read(ram,0x0c07b5e0u,4);
goto P_0c07b532;
P_0c07b532: /* original 4e08, guest PC 0x0c07b532 */
if(!s->budget--) { s->failed_pc=0x0c07b532u; return 0; }
r[14]<<=2;
goto P_0c07b534;
P_0c07b534: /* original 4e00, guest PC 0x0c07b534 */
if(!s->budget--) { s->failed_pc=0x0c07b534u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07b536;
P_0c07b536: /* original f32d, guest PC 0x0c07b536 */
if(!s->budget--) { s->failed_pc=0x0c07b536u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b538;
P_0c07b538: /* original 6ddd, guest PC 0x0c07b538 */
if(!s->budget--) { s->failed_pc=0x0c07b538u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b53a;
P_0c07b53a: /* original 4d08, guest PC 0x0c07b53a */
if(!s->budget--) { s->failed_pc=0x0c07b53au; return 0; }
r[13]<<=2;
goto P_0c07b53c;
P_0c07b53c: /* original 4d00, guest PC 0x0c07b53c */
if(!s->budget--) { s->failed_pc=0x0c07b53cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b53e;
P_0c07b53e: /* original 72e8, guest PC 0x0c07b53e */
if(!s->budget--) { s->failed_pc=0x0c07b53eu; return 0; }
r[2]+=0xffffffe8u;
goto P_0c07b540;
P_0c07b540: /* original 654d, guest PC 0x0c07b540 */
if(!s->budget--) { s->failed_pc=0x0c07b540u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b542;
P_0c07b542: /* original f33a, guest PC 0x0c07b542 */
if(!s->budget--) { s->failed_pc=0x0c07b542u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b544;
P_0c07b544: /* original 730c, guest PC 0x0c07b544 */
if(!s->budget--) { s->failed_pc=0x0c07b544u; return 0; }
r[3]+=0x0000000cu;
goto P_0c07b546;
P_0c07b546: /* original 475a, guest PC 0x0c07b546 */
if(!s->budget--) { s->failed_pc=0x0c07b546u; return 0; }
r[53]=r[7];
goto P_0c07b548;
P_0c07b548: /* original d126, guest PC 0x0c07b548 */
if(!s->budget--) { s->failed_pc=0x0c07b548u; return 0; }
r[1]=read(ram,0x0c07b5e4u,4);
goto P_0c07b54a;
P_0c07b54a: /* original f32d, guest PC 0x0c07b54a */
if(!s->budget--) { s->failed_pc=0x0c07b54au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b54c;
P_0c07b54c: /* original f13a, guest PC 0x0c07b54c */
if(!s->budget--) { s->failed_pc=0x0c07b54cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c07b54e;
P_0c07b54e: /* original 4e5a, guest PC 0x0c07b54e */
if(!s->budget--) { s->failed_pc=0x0c07b54eu; return 0; }
r[53]=r[14];
goto P_0c07b550;
P_0c07b550: /* original f32d, guest PC 0x0c07b550 */
if(!s->budget--) { s->failed_pc=0x0c07b550u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b552;
P_0c07b552: /* original f23a, guest PC 0x0c07b552 */
if(!s->budget--) { s->failed_pc=0x0c07b552u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c07b554;
P_0c07b554: /* original 4d5a, guest PC 0x0c07b554 */
if(!s->budget--) { s->failed_pc=0x0c07b554u; return 0; }
r[53]=r[13];
goto P_0c07b556;
P_0c07b556: /* original f32d, guest PC 0x0c07b556 */
if(!s->budget--) { s->failed_pc=0x0c07b556u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b558;
P_0c07b558: /* original f33a, guest PC 0x0c07b558 */
if(!s->budget--) { s->failed_pc=0x0c07b558u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b55a;
P_0c07b55a: /* original d11f, guest PC 0x0c07b55a */
if(!s->budget--) { s->failed_pc=0x0c07b55au; return 0; }
r[1]=read(ram,0x0c07b5d8u,4);
goto P_0c07b55c;
P_0c07b55c: /* original 4508, guest PC 0x0c07b55c */
if(!s->budget--) { s->failed_pc=0x0c07b55cu; return 0; }
r[5]<<=2;
goto P_0c07b55e;
P_0c07b55e: /* original f49d, guest PC 0x0c07b55e */
if(!s->budget--) { s->failed_pc=0x0c07b55eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c07b560;
P_0c07b560: /* original 7308, guest PC 0x0c07b560 */
if(!s->budget--) { s->failed_pc=0x0c07b560u; return 0; }
r[3]+=0x00000008u;
goto P_0c07b562;
P_0c07b562: /* original 351c, guest PC 0x0c07b562 */
if(!s->budget--) { s->failed_pc=0x0c07b562u; return 0; }
r[5]+=r[1];
goto P_0c07b564;
P_0c07b564: /* original f24c, guest PC 0x0c07b564 */
if(!s->budget--) { s->failed_pc=0x0c07b564u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b566;
P_0c07b566: /* original 6251, guest PC 0x0c07b566 */
if(!s->budget--) { s->failed_pc=0x0c07b566u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c07b568;
P_0c07b568: /* original 8551, guest PC 0x0c07b568 */
if(!s->budget--) { s->failed_pc=0x0c07b568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b56a;
P_0c07b56a: /* original 642d, guest PC 0x0c07b56a */
if(!s->budget--) { s->failed_pc=0x0c07b56au; return 0; }
r[4]=r[2]&65535u;
goto P_0c07b56c;
P_0c07b56c: /* original d21e, guest PC 0x0c07b56c */
if(!s->budget--) { s->failed_pc=0x0c07b56cu; return 0; }
r[2]=read(ram,0x0c07b5e8u,4);
goto P_0c07b56e;
P_0c07b56e: /* original 4408, guest PC 0x0c07b56e */
if(!s->budget--) { s->failed_pc=0x0c07b56eu; return 0; }
r[4]<<=2;
goto P_0c07b570;
P_0c07b570: /* original 4400, guest PC 0x0c07b570 */
if(!s->budget--) { s->failed_pc=0x0c07b570u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b572;
P_0c07b572: /* original 6123, guest PC 0x0c07b572 */
if(!s->budget--) { s->failed_pc=0x0c07b572u; return 0; }
r[1]=r[2];
goto P_0c07b574;
P_0c07b574: /* original 644d, guest PC 0x0c07b574 */
if(!s->budget--) { s->failed_pc=0x0c07b574u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b576;
P_0c07b576: /* original 445a, guest PC 0x0c07b576 */
if(!s->budget--) { s->failed_pc=0x0c07b576u; return 0; }
r[53]=r[4];
goto P_0c07b578;
P_0c07b578: /* original 650d, guest PC 0x0c07b578 */
if(!s->budget--) { s->failed_pc=0x0c07b578u; return 0; }
r[5]=r[0]&65535u;
goto P_0c07b57a;
P_0c07b57a: /* original 4508, guest PC 0x0c07b57a */
if(!s->budget--) { s->failed_pc=0x0c07b57au; return 0; }
r[5]<<=2;
goto P_0c07b57c;
P_0c07b57c: /* original 4500, guest PC 0x0c07b57c */
if(!s->budget--) { s->failed_pc=0x0c07b57cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b57e;
P_0c07b57e: /* original f32d, guest PC 0x0c07b57e */
if(!s->budget--) { s->failed_pc=0x0c07b57eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b580;
P_0c07b580: /* original 655d, guest PC 0x0c07b580 */
if(!s->budget--) { s->failed_pc=0x0c07b580u; return 0; }
r[5]=r[5]&65535u;
goto P_0c07b582;
P_0c07b582: /* original f233, guest PC 0x0c07b582 */
if(!s->budget--) { s->failed_pc=0x0c07b582u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c07b584;
P_0c07b584: /* original f22a, guest PC 0x0c07b584 */
if(!s->budget--) { s->failed_pc=0x0c07b584u; return 0; }
vf3_matrix_store(s,ram,2,r[2]);
goto P_0c07b586;
P_0c07b586: /* original 72f8, guest PC 0x0c07b586 */
if(!s->budget--) { s->failed_pc=0x0c07b586u; return 0; }
r[2]+=0xfffffff8u;
goto P_0c07b588;
P_0c07b588: /* original 455a, guest PC 0x0c07b588 */
if(!s->budget--) { s->failed_pc=0x0c07b588u; return 0; }
r[53]=r[5];
goto P_0c07b58a;
P_0c07b58a: /* original f32d, guest PC 0x0c07b58a */
if(!s->budget--) { s->failed_pc=0x0c07b58au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b58c;
P_0c07b58c: /* original f433, guest PC 0x0c07b58c */
if(!s->budget--) { s->failed_pc=0x0c07b58cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c07b58e;
P_0c07b58e: /* original f34a, guest PC 0x0c07b58e */
if(!s->budget--) { s->failed_pc=0x0c07b58eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c07b590;
P_0c07b590: /* original 7304, guest PC 0x0c07b590 */
if(!s->budget--) { s->failed_pc=0x0c07b590u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b592;
P_0c07b592: /* original f318, guest PC 0x0c07b592 */
if(!s->budget--) { s->failed_pc=0x0c07b592u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c07b594;
P_0c07b594: /* original f228, guest PC 0x0c07b594 */
if(!s->budget--) { s->failed_pc=0x0c07b594u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c07b596;
P_0c07b596: /* original f232, guest PC 0x0c07b596 */
if(!s->budget--) { s->failed_pc=0x0c07b596u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b598;
P_0c07b598: /* original f32a, guest PC 0x0c07b598 */
if(!s->budget--) { s->failed_pc=0x0c07b598u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b59a;
P_0c07b59a: /* original d014, guest PC 0x0c07b59a */
if(!s->budget--) { s->failed_pc=0x0c07b59au; return 0; }
r[0]=read(ram,0x0c07b5ecu,4);
goto P_0c07b59c;
P_0c07b59c: /* original 720c, guest PC 0x0c07b59c */
if(!s->budget--) { s->failed_pc=0x0c07b59cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c07b59e;
P_0c07b59e: /* original f328, guest PC 0x0c07b59e */
if(!s->budget--) { s->failed_pc=0x0c07b59eu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c07b5a0;
P_0c07b5a0: /* original 7304, guest PC 0x0c07b5a0 */
if(!s->budget--) { s->failed_pc=0x0c07b5a0u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b5a2;
P_0c07b5a2: /* original f208, guest PC 0x0c07b5a2 */
if(!s->budget--) { s->failed_pc=0x0c07b5a2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b5a4;
P_0c07b5a4: /* original 70f4, guest PC 0x0c07b5a4 */
if(!s->budget--) { s->failed_pc=0x0c07b5a4u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c07b5a6;
P_0c07b5a6: /* original f232, guest PC 0x0c07b5a6 */
if(!s->budget--) { s->failed_pc=0x0c07b5a6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b5a8;
P_0c07b5a8: /* original f32a, guest PC 0x0c07b5a8 */
if(!s->budget--) { s->failed_pc=0x0c07b5a8u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b5aa;
P_0c07b5aa: /* original 6df6, guest PC 0x0c07b5aa */
if(!s->budget--) { s->failed_pc=0x0c07b5aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b5ac;
P_0c07b5ac: /* original 000b, guest PC 0x0c07b5ac */
if(!s->budget--) { s->failed_pc=0x0c07b5acu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b5ae: /* original 6ef6, guest PC 0x0c07b5ae */
if(!s->budget--) { s->failed_pc=0x0c07b5aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b5b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5b0u; return 0; } return 1;
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
P_0c081ce8: /* original 4f22, guest PC 0x0c081ce8 */
if(!s->budget--) { s->failed_pc=0x0c081ce8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081cea;
P_0c081cea: /* original e200, guest PC 0x0c081cea */
if(!s->budget--) { s->failed_pc=0x0c081ceau; return 0; }
r[2]=0x00000000u;
goto P_0c081cec;
P_0c081cec: /* original 4400, guest PC 0x0c081cec */
if(!s->budget--) { s->failed_pc=0x0c081cecu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081cee;
P_0c081cee: /* original 6723, guest PC 0x0c081cee */
if(!s->budget--) { s->failed_pc=0x0c081ceeu; return 0; }
r[7]=r[2];
goto P_0c081cf0;
P_0c081cf0: /* original 7ff8, guest PC 0x0c081cf0 */
if(!s->budget--) { s->failed_pc=0x0c081cf0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c081cf2;
P_0c081cf2: /* original 2f62, guest PC 0x0c081cf2 */
if(!s->budget--) { s->failed_pc=0x0c081cf2u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c081cf4;
P_0c081cf4: /* original d309, guest PC 0x0c081cf4 */
if(!s->budget--) { s->failed_pc=0x0c081cf4u; return 0; }
r[3]=read(ram,0x0c081d1cu,4);
goto P_0c081cf6;
P_0c081cf6: /* original 1f31, guest PC 0x0c081cf6 */
if(!s->budget--) { s->failed_pc=0x0c081cf6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c081cf8;
P_0c081cf8: /* original e307, guest PC 0x0c081cf8 */
if(!s->budget--) { s->failed_pc=0x0c081cf8u; return 0; }
r[3]=0x00000007u;
goto P_0c081cfa;
P_0c081cfa: /* original 2f26, guest PC 0x0c081cfa */
if(!s->budget--) { s->failed_pc=0x0c081cfau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081cfc;
P_0c081cfc: /* original 453c, guest PC 0x0c081cfc */
if(!s->budget--) { s->failed_pc=0x0c081cfcu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c081cfe;
P_0c081cfe: /* original 56f2, guest PC 0x0c081cfe */
if(!s->budget--) { s->failed_pc=0x0c081cfeu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c081d00;
P_0c081d00: /* original 245b, guest PC 0x0c081d00 */
if(!s->budget--) { s->failed_pc=0x0c081d00u; return 0; }
r[4]|=r[5];
goto P_0c081d02;
P_0c081d02: /* original d107, guest PC 0x0c081d02 */
if(!s->budget--) { s->failed_pc=0x0c081d02u; return 0; }
r[1]=read(ram,0x0c081d20u,4);
goto P_0c081d04;
P_0c081d04: /* original 410b, guest PC 0x0c081d04 */
if(!s->budget--) { s->failed_pc=0x0c081d04u; return 0; }
target=r[1];
r[16]=code_base|0x0c081d08u;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081d08u) { target=s->pc; goto dispatch; }
goto P_0c081d08;
P_0c081d06: /* original 55f1, guest PC 0x0c081d06 */
if(!s->budget--) { s->failed_pc=0x0c081d06u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c081d08;
P_0c081d08: /* original 7f0c, guest PC 0x0c081d08 */
if(!s->budget--) { s->failed_pc=0x0c081d08u; return 0; }
r[15]+=0x0000000cu;
goto P_0c081d0a;
P_0c081d0a: /* original 4f26, guest PC 0x0c081d0a */
if(!s->budget--) { s->failed_pc=0x0c081d0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081d0c;
P_0c081d0c: /* original 000b, guest PC 0x0c081d0c */
if(!s->budget--) { s->failed_pc=0x0c081d0cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c081d0e: /* original 0009, guest PC 0x0c081d0e */
if(!s->budget--) { s->failed_pc=0x0c081d0eu; return 0; }
if(!vf3_matrix_family(0x0c081d10u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081d10u; return 0; } return 1;
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
