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
int vf3_away_batch134_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a8d58u: goto P_0c0a8d58;
case 0x0c0a8d5au: goto P_0c0a8d5a;
case 0x0c0a8d5cu: goto P_0c0a8d5c;
case 0x0c0a8d5eu: goto P_0c0a8d5e;
case 0x0c0a8d60u: goto P_0c0a8d60;
case 0x0c0a8d62u: goto P_0c0a8d62;
case 0x0c0a8d64u: goto P_0c0a8d64;
case 0x0c0a8d66u: goto P_0c0a8d66;
case 0x0c0a8d68u: goto P_0c0a8d68;
case 0x0c0a8d6au: goto P_0c0a8d6a;
case 0x0c0a8d6cu: goto P_0c0a8d6c;
case 0x0c0a8d6eu: goto P_0c0a8d6e;
case 0x0c0a8d70u: goto P_0c0a8d70;
case 0x0c0a8d72u: goto P_0c0a8d72;
case 0x0c0a8d74u: goto P_0c0a8d74;
case 0x0c0a8d76u: goto P_0c0a8d76;
case 0x0c0a8d78u: goto P_0c0a8d78;
case 0x0c0a8d7au: goto P_0c0a8d7a;
case 0x0c0a8d7cu: goto P_0c0a8d7c;
case 0x0c0a8d7eu: goto P_0c0a8d7e;
case 0x0c0a8d80u: goto P_0c0a8d80;
case 0x0c0a8d82u: goto P_0c0a8d82;
case 0x0c0a8d84u: goto P_0c0a8d84;
case 0x0c0a8d86u: goto P_0c0a8d86;
case 0x0c0a8d88u: goto P_0c0a8d88;
case 0x0c0a8d8au: goto P_0c0a8d8a;
case 0x0c0a8d8cu: goto P_0c0a8d8c;
case 0x0c0a8d8eu: goto P_0c0a8d8e;
case 0x0c0a8d90u: goto P_0c0a8d90;
case 0x0c0a8d92u: goto P_0c0a8d92;
case 0x0c0a8d94u: goto P_0c0a8d94;
case 0x0c0a8d96u: goto P_0c0a8d96;
case 0x0c0a8d98u: goto P_0c0a8d98;
case 0x0c0a8d9au: goto P_0c0a8d9a;
case 0x0c0a8d9cu: goto P_0c0a8d9c;
case 0x0c0a8d9eu: goto P_0c0a8d9e;
case 0x0c0a8da0u: goto P_0c0a8da0;
case 0x0c0a8da2u: goto P_0c0a8da2;
case 0x0c0a8da4u: goto P_0c0a8da4;
case 0x0c0a8da6u: goto P_0c0a8da6;
case 0x0c0a8da8u: goto P_0c0a8da8;
case 0x0c0a8daau: goto P_0c0a8daa;
case 0x0c0a8dacu: goto P_0c0a8dac;
case 0x0c0a8daeu: goto P_0c0a8dae;
case 0x0c0a8db0u: goto P_0c0a8db0;
case 0x0c0a8db2u: goto P_0c0a8db2;
case 0x0c0a8db4u: goto P_0c0a8db4;
case 0x0c0a8db6u: goto P_0c0a8db6;
case 0x0c0a8db8u: goto P_0c0a8db8;
case 0x0c0a8dbau: goto P_0c0a8dba;
case 0x0c0a8dbcu: goto P_0c0a8dbc;
case 0x0c0a8dbeu: goto P_0c0a8dbe;
case 0x0c0a8dc0u: goto P_0c0a8dc0;
case 0x0c0a8dc2u: goto P_0c0a8dc2;
case 0x0c0a8dc4u: goto P_0c0a8dc4;
case 0x0c0a8dc6u: goto P_0c0a8dc6;
case 0x0c0a8dc8u: goto P_0c0a8dc8;
case 0x0c0a8dcau: goto P_0c0a8dca;
case 0x0c0a8dccu: goto P_0c0a8dcc;
case 0x0c0a8dceu: goto P_0c0a8dce;
case 0x0c0a8dd0u: goto P_0c0a8dd0;
case 0x0c0a8dd2u: goto P_0c0a8dd2;
case 0x0c0a8dd4u: goto P_0c0a8dd4;
case 0x0c0a8dd6u: goto P_0c0a8dd6;
case 0x0c0a8dd8u: goto P_0c0a8dd8;
case 0x0c0a8ddau: goto P_0c0a8dda;
case 0x0c0a8ddcu: goto P_0c0a8ddc;
case 0x0c0a8ddeu: goto P_0c0a8dde;
case 0x0c0a8de0u: goto P_0c0a8de0;
case 0x0c0a8de2u: goto P_0c0a8de2;
case 0x0c0a8de4u: goto P_0c0a8de4;
case 0x0c0a8de6u: goto P_0c0a8de6;
case 0x0c0a8de8u: goto P_0c0a8de8;
case 0x0c0a8deau: goto P_0c0a8dea;
case 0x0c0a8decu: goto P_0c0a8dec;
case 0x0c0a8deeu: goto P_0c0a8dee;
case 0x0c0a8df0u: goto P_0c0a8df0;
case 0x0c0a8df2u: goto P_0c0a8df2;
case 0x0c0a8df4u: goto P_0c0a8df4;
case 0x0c0a8df6u: goto P_0c0a8df6;
case 0x0c0a8df8u: goto P_0c0a8df8;
case 0x0c0a8dfau: goto P_0c0a8dfa;
case 0x0c0a8dfcu: goto P_0c0a8dfc;
case 0x0c0a8dfeu: goto P_0c0a8dfe;
case 0x0c0a91dau: goto P_0c0a91da;
case 0x0c0a91dcu: goto P_0c0a91dc;
case 0x0c0a91deu: goto P_0c0a91de;
case 0x0c0a91e0u: goto P_0c0a91e0;
case 0x0c0a91e2u: goto P_0c0a91e2;
case 0x0c0a91e4u: goto P_0c0a91e4;
case 0x0c0a91e6u: goto P_0c0a91e6;
case 0x0c0a91e8u: goto P_0c0a91e8;
case 0x0c0a91eau: goto P_0c0a91ea;
case 0x0c0a91ecu: goto P_0c0a91ec;
case 0x0c0a91eeu: goto P_0c0a91ee;
case 0x0c0a91f0u: goto P_0c0a91f0;
case 0x0c0a91f2u: goto P_0c0a91f2;
case 0x0c0a91f4u: goto P_0c0a91f4;
case 0x0c0a91f6u: goto P_0c0a91f6;
case 0x0c0a91f8u: goto P_0c0a91f8;
case 0x0c0a91fau: goto P_0c0a91fa;
case 0x0c0a91fcu: goto P_0c0a91fc;
case 0x0c0a91feu: goto P_0c0a91fe;
case 0x0c0a9200u: goto P_0c0a9200;
case 0x0c0a9202u: goto P_0c0a9202;
case 0x0c0a9204u: goto P_0c0a9204;
case 0x0c0a9206u: goto P_0c0a9206;
case 0x0c0a9208u: goto P_0c0a9208;
case 0x0c0a920au: goto P_0c0a920a;
case 0x0c0a920cu: goto P_0c0a920c;
case 0x0c0a920eu: goto P_0c0a920e;
case 0x0c0a9210u: goto P_0c0a9210;
case 0x0c0a9212u: goto P_0c0a9212;
case 0x0c0a9214u: goto P_0c0a9214;
case 0x0c0a9216u: goto P_0c0a9216;
case 0x0c0a9218u: goto P_0c0a9218;
case 0x0c0a921au: goto P_0c0a921a;
case 0x0c0a921cu: goto P_0c0a921c;
case 0x0c0a921eu: goto P_0c0a921e;
case 0x0c0a9220u: goto P_0c0a9220;
case 0x0c0a9222u: goto P_0c0a9222;
case 0x0c0a9224u: goto P_0c0a9224;
case 0x0c0a9226u: goto P_0c0a9226;
case 0x0c0a9228u: goto P_0c0a9228;
case 0x0c0a922au: goto P_0c0a922a;
case 0x0c0a922cu: goto P_0c0a922c;
case 0x0c0a922eu: goto P_0c0a922e;
case 0x0c0a9230u: goto P_0c0a9230;
case 0x0c0a9232u: goto P_0c0a9232;
case 0x0c0a9234u: goto P_0c0a9234;
case 0x0c0a9236u: goto P_0c0a9236;
case 0x0c0a9238u: goto P_0c0a9238;
case 0x0c0a923au: goto P_0c0a923a;
case 0x0c0a923cu: goto P_0c0a923c;
case 0x0c0a923eu: goto P_0c0a923e;
case 0x0c0a9240u: goto P_0c0a9240;
case 0x0c0a9242u: goto P_0c0a9242;
case 0x0c0a92c8u: goto P_0c0a92c8;
case 0x0c0a92cau: goto P_0c0a92ca;
case 0x0c0a92ccu: goto P_0c0a92cc;
case 0x0c0a92ceu: goto P_0c0a92ce;
case 0x0c0a92d0u: goto P_0c0a92d0;
case 0x0c0a92d2u: goto P_0c0a92d2;
case 0x0c0a92d4u: goto P_0c0a92d4;
case 0x0c0a92d6u: goto P_0c0a92d6;
case 0x0c0a92d8u: goto P_0c0a92d8;
case 0x0c0a92dau: goto P_0c0a92da;
case 0x0c0a92dcu: goto P_0c0a92dc;
case 0x0c0a92deu: goto P_0c0a92de;
case 0x0c0a92e0u: goto P_0c0a92e0;
case 0x0c0a92e2u: goto P_0c0a92e2;
case 0x0c0a92e4u: goto P_0c0a92e4;
case 0x0c0a92e6u: goto P_0c0a92e6;
case 0x0c0a92e8u: goto P_0c0a92e8;
case 0x0c0a92eau: goto P_0c0a92ea;
case 0x0c0a92ecu: goto P_0c0a92ec;
case 0x0c0a92eeu: goto P_0c0a92ee;
case 0x0c0a92f0u: goto P_0c0a92f0;
case 0x0c0a92f2u: goto P_0c0a92f2;
case 0x0c0a92f4u: goto P_0c0a92f4;
case 0x0c0a92f6u: goto P_0c0a92f6;
case 0x0c0a92f8u: goto P_0c0a92f8;
case 0x0c0a92fau: goto P_0c0a92fa;
case 0x0c0a92fcu: goto P_0c0a92fc;
case 0x0c0a92feu: goto P_0c0a92fe;
case 0x0c0a9300u: goto P_0c0a9300;
case 0x0c0a9302u: goto P_0c0a9302;
case 0x0c0a9304u: goto P_0c0a9304;
case 0x0c0a9306u: goto P_0c0a9306;
case 0x0c0a9308u: goto P_0c0a9308;
case 0x0c0a930au: goto P_0c0a930a;
case 0x0c0a930cu: goto P_0c0a930c;
case 0x0c0a930eu: goto P_0c0a930e;
case 0x0c0a9310u: goto P_0c0a9310;
case 0x0c0a9312u: goto P_0c0a9312;
case 0x0c0a9314u: goto P_0c0a9314;
case 0x0c0a9316u: goto P_0c0a9316;
case 0x0c0a9318u: goto P_0c0a9318;
case 0x0c0a931au: goto P_0c0a931a;
case 0x0c0a931cu: goto P_0c0a931c;
case 0x0c0a931eu: goto P_0c0a931e;
case 0x0c0a9320u: goto P_0c0a9320;
case 0x0c0a9322u: goto P_0c0a9322;
case 0x0c0a9324u: goto P_0c0a9324;
case 0x0c0a9326u: goto P_0c0a9326;
case 0x0c0a9328u: goto P_0c0a9328;
case 0x0c0a932au: goto P_0c0a932a;
case 0x0c0a932cu: goto P_0c0a932c;
case 0x0c0a932eu: goto P_0c0a932e;
case 0x0c0a9330u: goto P_0c0a9330;
case 0x0c0a9332u: goto P_0c0a9332;
case 0x0c0a9334u: goto P_0c0a9334;
case 0x0c0a9336u: goto P_0c0a9336;
case 0x0c0a9338u: goto P_0c0a9338;
case 0x0c0a933au: goto P_0c0a933a;
case 0x0c0a933cu: goto P_0c0a933c;
case 0x0c0a933eu: goto P_0c0a933e;
case 0x0c0a9340u: goto P_0c0a9340;
case 0x0c0a9342u: goto P_0c0a9342;
case 0x0c0a9344u: goto P_0c0a9344;
case 0x0c0a9346u: goto P_0c0a9346;
case 0x0c0a9348u: goto P_0c0a9348;
case 0x0c0a934au: goto P_0c0a934a;
case 0x0c0a934cu: goto P_0c0a934c;
case 0x0c0a934eu: goto P_0c0a934e;
case 0x0c0a9350u: goto P_0c0a9350;
case 0x0c0a9352u: goto P_0c0a9352;
case 0x0c0a9354u: goto P_0c0a9354;
case 0x0c0a9356u: goto P_0c0a9356;
case 0x0c0a9358u: goto P_0c0a9358;
case 0x0c0a935au: goto P_0c0a935a;
case 0x0c0a935cu: goto P_0c0a935c;
case 0x0c0a935eu: goto P_0c0a935e;
case 0x0c0a9360u: goto P_0c0a9360;
case 0x0c0a9362u: goto P_0c0a9362;
case 0x0c0a9364u: goto P_0c0a9364;
case 0x0c0a9366u: goto P_0c0a9366;
case 0x0c0a9368u: goto P_0c0a9368;
case 0x0c0a936au: goto P_0c0a936a;
case 0x0c0a936cu: goto P_0c0a936c;
case 0x0c0a936eu: goto P_0c0a936e;
case 0x0c0a9370u: goto P_0c0a9370;
case 0x0c0a9372u: goto P_0c0a9372;
case 0x0c0a9374u: goto P_0c0a9374;
case 0x0c0a9376u: goto P_0c0a9376;
case 0x0c0a9378u: goto P_0c0a9378;
case 0x0c0a937au: goto P_0c0a937a;
case 0x0c0a937cu: goto P_0c0a937c;
case 0x0c0a937eu: goto P_0c0a937e;
case 0x0c0a9380u: goto P_0c0a9380;
case 0x0c0a9382u: goto P_0c0a9382;
case 0x0c0a9384u: goto P_0c0a9384;
case 0x0c0a9386u: goto P_0c0a9386;
case 0x0c0a9388u: goto P_0c0a9388;
case 0x0c0a938au: goto P_0c0a938a;
case 0x0c0a938cu: goto P_0c0a938c;
case 0x0c0a938eu: goto P_0c0a938e;
case 0x0c0a9390u: goto P_0c0a9390;
case 0x0c0a9392u: goto P_0c0a9392;
case 0x0c0a9394u: goto P_0c0a9394;
case 0x0c0a9396u: goto P_0c0a9396;
case 0x0c0a9398u: goto P_0c0a9398;
case 0x0c0a939au: goto P_0c0a939a;
case 0x0c0a939cu: goto P_0c0a939c;
case 0x0c0a93c8u: goto P_0c0a93c8;
case 0x0c0a93cau: goto P_0c0a93ca;
case 0x0c0a93ccu: goto P_0c0a93cc;
case 0x0c0a93ceu: goto P_0c0a93ce;
case 0x0c0a93d0u: goto P_0c0a93d0;
case 0x0c0a93d2u: goto P_0c0a93d2;
case 0x0c0a93d4u: goto P_0c0a93d4;
case 0x0c0a93d6u: goto P_0c0a93d6;
case 0x0c0a93d8u: goto P_0c0a93d8;
case 0x0c0a93dau: goto P_0c0a93da;
case 0x0c0a93dcu: goto P_0c0a93dc;
case 0x0c0a93deu: goto P_0c0a93de;
case 0x0c0a93e0u: goto P_0c0a93e0;
case 0x0c0a93e2u: goto P_0c0a93e2;
case 0x0c0a93e4u: goto P_0c0a93e4;
case 0x0c0a93e6u: goto P_0c0a93e6;
case 0x0c0a93e8u: goto P_0c0a93e8;
case 0x0c0a93eau: goto P_0c0a93ea;
case 0x0c0a93ecu: goto P_0c0a93ec;
case 0x0c0a93eeu: goto P_0c0a93ee;
case 0x0c0a93f0u: goto P_0c0a93f0;
case 0x0c0a93f2u: goto P_0c0a93f2;
case 0x0c0a93f4u: goto P_0c0a93f4;
case 0x0c0a93f6u: goto P_0c0a93f6;
case 0x0c0a93f8u: goto P_0c0a93f8;
case 0x0c0a93fau: goto P_0c0a93fa;
case 0x0c0a93fcu: goto P_0c0a93fc;
case 0x0c0a93feu: goto P_0c0a93fe;
case 0x0c0a9400u: goto P_0c0a9400;
case 0x0c0a9402u: goto P_0c0a9402;
case 0x0c0a9404u: goto P_0c0a9404;
case 0x0c0a9406u: goto P_0c0a9406;
case 0x0c0a9408u: goto P_0c0a9408;
case 0x0c0a940au: goto P_0c0a940a;
case 0x0c0a940cu: goto P_0c0a940c;
case 0x0c0a940eu: goto P_0c0a940e;
case 0x0c0a9410u: goto P_0c0a9410;
case 0x0c0a9412u: goto P_0c0a9412;
case 0x0c0a9414u: goto P_0c0a9414;
case 0x0c0a9416u: goto P_0c0a9416;
case 0x0c0a9418u: goto P_0c0a9418;
case 0x0c0a941au: goto P_0c0a941a;
case 0x0c0a941cu: goto P_0c0a941c;
case 0x0c0a941eu: goto P_0c0a941e;
case 0x0c0a9420u: goto P_0c0a9420;
case 0x0c0a9422u: goto P_0c0a9422;
case 0x0c0a9424u: goto P_0c0a9424;
case 0x0c0a9426u: goto P_0c0a9426;
case 0x0c0a9428u: goto P_0c0a9428;
case 0x0c0a942au: goto P_0c0a942a;
case 0x0c0a942cu: goto P_0c0a942c;
case 0x0c0a942eu: goto P_0c0a942e;
case 0x0c0a9430u: goto P_0c0a9430;
case 0x0c0a9432u: goto P_0c0a9432;
case 0x0c0a9434u: goto P_0c0a9434;
case 0x0c0a9436u: goto P_0c0a9436;
case 0x0c0a9438u: goto P_0c0a9438;
case 0x0c0a943au: goto P_0c0a943a;
case 0x0c0a943cu: goto P_0c0a943c;
case 0x0c0a943eu: goto P_0c0a943e;
case 0x0c0a9440u: goto P_0c0a9440;
case 0x0c0a9442u: goto P_0c0a9442;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a8d58: /* original e004, guest PC 0x0c0a8d58 */
if(!s->budget--) { s->failed_pc=0x0c0a8d58u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8d5a;
P_0c0a8d5a: /* original 2fe6, guest PC 0x0c0a8d5a */
if(!s->budget--) { s->failed_pc=0x0c0a8d5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8d5c;
P_0c0a8d5c: /* original 4f22, guest PC 0x0c0a8d5c */
if(!s->budget--) { s->failed_pc=0x0c0a8d5cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8d5e;
P_0c0a8d5e: /* original 6e43, guest PC 0x0c0a8d5e */
if(!s->budget--) { s->failed_pc=0x0c0a8d5eu; return 0; }
r[14]=r[4];
goto P_0c0a8d60;
P_0c0a8d60: /* original 6262, guest PC 0x0c0a8d60 */
if(!s->budget--) { s->failed_pc=0x0c0a8d60u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a8d62;
P_0c0a8d62: /* original e3fe, guest PC 0x0c0a8d62 */
if(!s->budget--) { s->failed_pc=0x0c0a8d62u; return 0; }
r[3]=0xfffffffeu;
goto P_0c0a8d64;
P_0c0a8d64: /* original 7ff8, guest PC 0x0c0a8d64 */
if(!s->budget--) { s->failed_pc=0x0c0a8d64u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a8d66;
P_0c0a8d66: /* original 2239, guest PC 0x0c0a8d66 */
if(!s->budget--) { s->failed_pc=0x0c0a8d66u; return 0; }
r[2]&=r[3];
goto P_0c0a8d68;
P_0c0a8d68: /* original 2e22, guest PC 0x0c0a8d68 */
if(!s->budget--) { s->failed_pc=0x0c0a8d68u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8d6a;
P_0c0a8d6a: /* original f466, guest PC 0x0c0a8d6a */
if(!s->budget--) { s->failed_pc=0x0c0a8d6au; return 0; }
vf3_matrix_load(s,ram,4,r[6]+r[0]);
goto P_0c0a8d6c;
P_0c0a8d6c: /* original e008, guest PC 0x0c0a8d6c */
if(!s->budget--) { s->failed_pc=0x0c0a8d6cu; return 0; }
r[0]=0x00000008u;
goto P_0c0a8d6e;
P_0c0a8d6e: /* original f566, guest PC 0x0c0a8d6e */
if(!s->budget--) { s->failed_pc=0x0c0a8d6eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]+r[0]);
goto P_0c0a8d70;
P_0c0a8d70: /* original e00c, guest PC 0x0c0a8d70 */
if(!s->budget--) { s->failed_pc=0x0c0a8d70u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8d72;
P_0c0a8d72: /* original f666, guest PC 0x0c0a8d72 */
if(!s->budget--) { s->failed_pc=0x0c0a8d72u; return 0; }
vf3_matrix_load(s,ram,6,r[6]+r[0]);
goto P_0c0a8d74;
P_0c0a8d74: /* original 856a, guest PC 0x0c0a8d74 */
if(!s->budget--) { s->failed_pc=0x0c0a8d74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+20,2);
goto P_0c0a8d76;
P_0c0a8d76: /* original 5464, guest PC 0x0c0a8d76 */
if(!s->budget--) { s->failed_pc=0x0c0a8d76u; return 0; }
r[4]=read(ram,r[6]+16,4);
goto P_0c0a8d78;
P_0c0a8d78: /* original 6703, guest PC 0x0c0a8d78 */
if(!s->budget--) { s->failed_pc=0x0c0a8d78u; return 0; }
r[7]=r[0];
goto P_0c0a8d7a;
P_0c0a8d7a: /* original 856c, guest PC 0x0c0a8d7a */
if(!s->budget--) { s->failed_pc=0x0c0a8d7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+24,2);
goto P_0c0a8d7c;
P_0c0a8d7c: /* original 2f01, guest PC 0x0c0a8d7c */
if(!s->budget--) { s->failed_pc=0x0c0a8d7cu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c0a8d7e;
P_0c0a8d7e: /* original e010, guest PC 0x0c0a8d7e */
if(!s->budget--) { s->failed_pc=0x0c0a8d7eu; return 0; }
r[0]=0x00000010u;
goto P_0c0a8d80;
P_0c0a8d80: /* original 5267, guest PC 0x0c0a8d80 */
if(!s->budget--) { s->failed_pc=0x0c0a8d80u; return 0; }
r[2]=read(ram,r[6]+28,4);
goto P_0c0a8d82;
P_0c0a8d82: /* original 1f21, guest PC 0x0c0a8d82 */
if(!s->budget--) { s->failed_pc=0x0c0a8d82u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a8d84;
P_0c0a8d84: /* original fe47, guest PC 0x0c0a8d84 */
if(!s->budget--) { s->failed_pc=0x0c0a8d84u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a8d86;
P_0c0a8d86: /* original e014, guest PC 0x0c0a8d86 */
if(!s->budget--) { s->failed_pc=0x0c0a8d86u; return 0; }
r[0]=0x00000014u;
goto P_0c0a8d88;
P_0c0a8d88: /* original fe57, guest PC 0x0c0a8d88 */
if(!s->budget--) { s->failed_pc=0x0c0a8d88u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a8d8a;
P_0c0a8d8a: /* original e018, guest PC 0x0c0a8d8a */
if(!s->budget--) { s->failed_pc=0x0c0a8d8au; return 0; }
r[0]=0x00000018u;
goto P_0c0a8d8c;
P_0c0a8d8c: /* original fe67, guest PC 0x0c0a8d8c */
if(!s->budget--) { s->failed_pc=0x0c0a8d8cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a8d8e;
P_0c0a8d8e: /* original e048, guest PC 0x0c0a8d8e */
if(!s->budget--) { s->failed_pc=0x0c0a8d8eu; return 0; }
r[0]=0x00000048u;
goto P_0c0a8d90;
P_0c0a8d90: /* original 0e46, guest PC 0x0c0a8d90 */
if(!s->budget--) { s->failed_pc=0x0c0a8d90u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a8d92;
P_0c0a8d92: /* original 6073, guest PC 0x0c0a8d92 */
if(!s->budget--) { s->failed_pc=0x0c0a8d92u; return 0; }
r[0]=r[7];
goto P_0c0a8d94;
P_0c0a8d94: /* original 81ef, guest PC 0x0c0a8d94 */
if(!s->budget--) { s->failed_pc=0x0c0a8d94u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a8d96;
P_0c0a8d96: /* original 62f1, guest PC 0x0c0a8d96 */
if(!s->budget--) { s->failed_pc=0x0c0a8d96u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c0a8d98;
P_0c0a8d98: /* original e03e, guest PC 0x0c0a8d98 */
if(!s->budget--) { s->failed_pc=0x0c0a8d98u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a8d9a;
P_0c0a8d9a: /* original 0e25, guest PC 0x0c0a8d9a */
if(!s->budget--) { s->failed_pc=0x0c0a8d9au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a8d9c;
P_0c0a8d9c: /* original 9030, guest PC 0x0c0a8d9c */
if(!s->budget--) { s->failed_pc=0x0c0a8d9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8e00u,2);
goto P_0c0a8d9e;
P_0c0a8d9e: /* original 51f1, guest PC 0x0c0a8d9e */
if(!s->budget--) { s->failed_pc=0x0c0a8d9eu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0a8da0;
P_0c0a8da0: /* original 0e16, guest PC 0x0c0a8da0 */
if(!s->budget--) { s->failed_pc=0x0c0a8da0u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0a8da2;
P_0c0a8da2: /* original e03c, guest PC 0x0c0a8da2 */
if(!s->budget--) { s->failed_pc=0x0c0a8da2u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a8da4;
P_0c0a8da4: /* original 07ed, guest PC 0x0c0a8da4 */
if(!s->budget--) { s->failed_pc=0x0c0a8da4u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8da6;
P_0c0a8da6: /* original 856b, guest PC 0x0c0a8da6 */
if(!s->budget--) { s->failed_pc=0x0c0a8da6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a8da8;
P_0c0a8da8: /* original 6403, guest PC 0x0c0a8da8 */
if(!s->budget--) { s->failed_pc=0x0c0a8da8u; return 0; }
r[4]=r[0];
goto P_0c0a8daa;
P_0c0a8daa: /* original 664f, guest PC 0x0c0a8daa */
if(!s->budget--) { s->failed_pc=0x0c0a8daau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8dac;
P_0c0a8dac: /* original 2668, guest PC 0x0c0a8dac */
if(!s->budget--) { s->failed_pc=0x0c0a8dacu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a8dae;
P_0c0a8dae: /* original e03c, guest PC 0x0c0a8dae */
if(!s->budget--) { s->failed_pc=0x0c0a8daeu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a8db0;
P_0c0a8db0: /* original 8d22, guest PC 0x0c0a8db0 */
if(!s->budget--) { s->failed_pc=0x0c0a8db0u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0a8df8; }
goto P_0c0a8db4;
P_0c0a8db2: /* original 0e45, guest PC 0x0c0a8db2 */
if(!s->budget--) { s->failed_pc=0x0c0a8db2u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a8db4;
P_0c0a8db4: /* original 677f, guest PC 0x0c0a8db4 */
if(!s->budget--) { s->failed_pc=0x0c0a8db4u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c0a8db6;
P_0c0a8db6: /* original 3760, guest PC 0x0c0a8db6 */
if(!s->budget--) { s->failed_pc=0x0c0a8db6u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[6])!=0);
goto P_0c0a8db8;
P_0c0a8db8: /* original 8b06, guest PC 0x0c0a8db8 */
if(!s->budget--) { s->failed_pc=0x0c0a8db8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8dc8; }
goto P_0c0a8dba;
P_0c0a8dba: /* original e03e, guest PC 0x0c0a8dba */
if(!s->budget--) { s->failed_pc=0x0c0a8dbau; return 0; }
r[0]=0x0000003eu;
goto P_0c0a8dbc;
P_0c0a8dbc: /* original 04ed, guest PC 0x0c0a8dbc */
if(!s->budget--) { s->failed_pc=0x0c0a8dbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8dbe;
P_0c0a8dbe: /* original 604f, guest PC 0x0c0a8dbe */
if(!s->budget--) { s->failed_pc=0x0c0a8dbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8dc0;
P_0c0a8dc0: /* original 8801, guest PC 0x0c0a8dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a8dc2;
P_0c0a8dc2: /* original 890b, guest PC 0x0c0a8dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8ddc; }
goto P_0c0a8dc4;
P_0c0a8dc4: /* original a00f, guest PC 0x0c0a8dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc4u; return 0; }
goto P_0c0a8de6;
P_0c0a8dc6: /* original 0009, guest PC 0x0c0a8dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc6u; return 0; }
goto P_0c0a8dc8;
P_0c0a8dc8: /* original 02ed, guest PC 0x0c0a8dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8dca;
P_0c0a8dca: /* original 622d, guest PC 0x0c0a8dca */
if(!s->budget--) { s->failed_pc=0x0c0a8dcau; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a8dcc;
P_0c0a8dcc: /* original 6623, guest PC 0x0c0a8dcc */
if(!s->budget--) { s->failed_pc=0x0c0a8dccu; return 0; }
r[6]=r[2];
goto P_0c0a8dce;
P_0c0a8dce: /* original 2f22, guest PC 0x0c0a8dce */
if(!s->budget--) { s->failed_pc=0x0c0a8dceu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a8dd0;
P_0c0a8dd0: /* original d30c, guest PC 0x0c0a8dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd0u; return 0; }
r[3]=read(ram,0x0c0a8e04u,4);
goto P_0c0a8dd2;
P_0c0a8dd2: /* original 430b, guest PC 0x0c0a8dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8dd6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8dd6u) { target=s->pc; goto dispatch; }
goto P_0c0a8dd6;
P_0c0a8dd4: /* original 64e3, guest PC 0x0c0a8dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd4u; return 0; }
r[4]=r[14];
goto P_0c0a8dd6;
P_0c0a8dd6: /* original d20c, guest PC 0x0c0a8dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd6u; return 0; }
r[2]=read(ram,0x0c0a8e08u,4);
goto P_0c0a8dd8;
P_0c0a8dd8: /* original 420b, guest PC 0x0c0a8dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8ddcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8ddcu) { target=s->pc; goto dispatch; }
goto P_0c0a8ddc;
P_0c0a8dda: /* original 64e3, guest PC 0x0c0a8dda */
if(!s->budget--) { s->failed_pc=0x0c0a8ddau; return 0; }
r[4]=r[14];
goto P_0c0a8ddc;
P_0c0a8ddc: /* original d30b, guest PC 0x0c0a8ddc */
if(!s->budget--) { s->failed_pc=0x0c0a8ddcu; return 0; }
r[3]=read(ram,0x0c0a8e0cu,4);
goto P_0c0a8dde;
P_0c0a8dde: /* original 430b, guest PC 0x0c0a8dde */
if(!s->budget--) { s->failed_pc=0x0c0a8ddeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8de2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8de2u) { target=s->pc; goto dispatch; }
goto P_0c0a8de2;
P_0c0a8de0: /* original 64e3, guest PC 0x0c0a8de0 */
if(!s->budget--) { s->failed_pc=0x0c0a8de0u; return 0; }
r[4]=r[14];
goto P_0c0a8de2;
P_0c0a8de2: /* original a003, guest PC 0x0c0a8de2 */
if(!s->budget--) { s->failed_pc=0x0c0a8de2u; return 0; }
goto P_0c0a8dec;
P_0c0a8de4: /* original 0009, guest PC 0x0c0a8de4 */
if(!s->budget--) { s->failed_pc=0x0c0a8de4u; return 0; }
goto P_0c0a8de6;
P_0c0a8de6: /* original d30a, guest PC 0x0c0a8de6 */
if(!s->budget--) { s->failed_pc=0x0c0a8de6u; return 0; }
r[3]=read(ram,0x0c0a8e10u,4);
goto P_0c0a8de8;
P_0c0a8de8: /* original 430b, guest PC 0x0c0a8de8 */
if(!s->budget--) { s->failed_pc=0x0c0a8de8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8decu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8decu) { target=s->pc; goto dispatch; }
goto P_0c0a8dec;
P_0c0a8dea: /* original 64e3, guest PC 0x0c0a8dea */
if(!s->budget--) { s->failed_pc=0x0c0a8deau; return 0; }
r[4]=r[14];
goto P_0c0a8dec;
P_0c0a8dec: /* original 7f08, guest PC 0x0c0a8dec */
if(!s->budget--) { s->failed_pc=0x0c0a8decu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a8dee;
P_0c0a8dee: /* original d209, guest PC 0x0c0a8dee */
if(!s->budget--) { s->failed_pc=0x0c0a8deeu; return 0; }
r[2]=read(ram,0x0c0a8e14u,4);
goto P_0c0a8df0;
P_0c0a8df0: /* original 4f26, guest PC 0x0c0a8df0 */
if(!s->budget--) { s->failed_pc=0x0c0a8df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8df2;
P_0c0a8df2: /* original 64e3, guest PC 0x0c0a8df2 */
if(!s->budget--) { s->failed_pc=0x0c0a8df2u; return 0; }
r[4]=r[14];
goto P_0c0a8df4;
P_0c0a8df4: /* original 422b, guest PC 0x0c0a8df4 */
if(!s->budget--) { s->failed_pc=0x0c0a8df4u; return 0; }
target=r[2];
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
P_0c0a8df6: /* original 6ef6, guest PC 0x0c0a8df6 */
if(!s->budget--) { s->failed_pc=0x0c0a8df6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a8df8;
P_0c0a8df8: /* original 7f08, guest PC 0x0c0a8df8 */
if(!s->budget--) { s->failed_pc=0x0c0a8df8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a8dfa;
P_0c0a8dfa: /* original 4f26, guest PC 0x0c0a8dfa */
if(!s->budget--) { s->failed_pc=0x0c0a8dfau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8dfc;
P_0c0a8dfc: /* original 000b, guest PC 0x0c0a8dfc */
if(!s->budget--) { s->failed_pc=0x0c0a8dfcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8dfe: /* original 6ef6, guest PC 0x0c0a8dfe */
if(!s->budget--) { s->failed_pc=0x0c0a8dfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8e00u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8e00u; return 0; } return 1;
P_0c0a91da: /* original 2fe6, guest PC 0x0c0a91da */
if(!s->budget--) { s->failed_pc=0x0c0a91dau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91dc;
P_0c0a91dc: /* original e054, guest PC 0x0c0a91dc */
if(!s->budget--) { s->failed_pc=0x0c0a91dcu; return 0; }
r[0]=0x00000054u;
goto P_0c0a91de;
P_0c0a91de: /* original 2fd6, guest PC 0x0c0a91de */
if(!s->budget--) { s->failed_pc=0x0c0a91deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e0;
P_0c0a91e0: /* original 2fc6, guest PC 0x0c0a91e0 */
if(!s->budget--) { s->failed_pc=0x0c0a91e0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e2;
P_0c0a91e2: /* original 2fb6, guest PC 0x0c0a91e2 */
if(!s->budget--) { s->failed_pc=0x0c0a91e2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e4;
P_0c0a91e4: /* original de2e, guest PC 0x0c0a91e4 */
if(!s->budget--) { s->failed_pc=0x0c0a91e4u; return 0; }
r[14]=read(ram,0x0c0a92a0u,4);
goto P_0c0a91e6;
P_0c0a91e6: /* original 4f22, guest PC 0x0c0a91e6 */
if(!s->budget--) { s->failed_pc=0x0c0a91e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a91e8;
P_0c0a91e8: /* original 04ee, guest PC 0x0c0a91e8 */
if(!s->budget--) { s->failed_pc=0x0c0a91e8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a91ea;
P_0c0a91ea: /* original 5de4, guest PC 0x0c0a91ea */
if(!s->budget--) { s->failed_pc=0x0c0a91eau; return 0; }
r[13]=read(ram,r[14]+16,4);
goto P_0c0a91ec;
P_0c0a91ec: /* original 5445, guest PC 0x0c0a91ec */
if(!s->budget--) { s->failed_pc=0x0c0a91ecu; return 0; }
r[4]=read(ram,r[4]+20,4);
goto P_0c0a91ee;
P_0c0a91ee: /* original 74ff, guest PC 0x0c0a91ee */
if(!s->budget--) { s->failed_pc=0x0c0a91eeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a91f0;
P_0c0a91f0: /* original 4411, guest PC 0x0c0a91f0 */
if(!s->budget--) { s->failed_pc=0x0c0a91f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a91f2;
P_0c0a91f2: /* original 8d01, guest PC 0x0c0a91f2 */
if(!s->budget--) { s->failed_pc=0x0c0a91f2u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[14]+20,4);
if(cond) { goto P_0c0a91f8; }
goto P_0c0a91f6;
P_0c0a91f4: /* original 5be5, guest PC 0x0c0a91f4 */
if(!s->budget--) { s->failed_pc=0x0c0a91f4u; return 0; }
r[11]=read(ram,r[14]+20,4);
goto P_0c0a91f6;
P_0c0a91f6: /* original 944c, guest PC 0x0c0a91f6 */
if(!s->budget--) { s->failed_pc=0x0c0a91f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9292u,2);
goto P_0c0a91f8;
P_0c0a91f8: /* original 4408, guest PC 0x0c0a91f8 */
if(!s->budget--) { s->failed_pc=0x0c0a91f8u; return 0; }
r[4]<<=2;
goto P_0c0a91fa;
P_0c0a91fa: /* original dc2a, guest PC 0x0c0a91fa */
if(!s->budget--) { s->failed_pc=0x0c0a91fau; return 0; }
r[12]=read(ram,0x0c0a92a4u,4);
goto P_0c0a91fc;
P_0c0a91fc: /* original 4408, guest PC 0x0c0a91fc */
if(!s->budget--) { s->failed_pc=0x0c0a91fcu; return 0; }
r[4]<<=2;
goto P_0c0a91fe;
P_0c0a91fe: /* original 65d3, guest PC 0x0c0a91fe */
if(!s->budget--) { s->failed_pc=0x0c0a91feu; return 0; }
r[5]=r[13];
goto P_0c0a9200;
P_0c0a9200: /* original 4408, guest PC 0x0c0a9200 */
if(!s->budget--) { s->failed_pc=0x0c0a9200u; return 0; }
r[4]<<=2;
goto P_0c0a9202;
P_0c0a9202: /* original 66b3, guest PC 0x0c0a9202 */
if(!s->budget--) { s->failed_pc=0x0c0a9202u; return 0; }
r[6]=r[11];
goto P_0c0a9204;
P_0c0a9204: /* original 4400, guest PC 0x0c0a9204 */
if(!s->budget--) { s->failed_pc=0x0c0a9204u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a9206;
P_0c0a9206: /* original 3c4c, guest PC 0x0c0a9206 */
if(!s->budget--) { s->failed_pc=0x0c0a9206u; return 0; }
r[12]+=r[4];
goto P_0c0a9208;
P_0c0a9208: /* original b162, guest PC 0x0c0a9208 */
if(!s->budget--) { s->failed_pc=0x0c0a9208u; return 0; }
target=code_base|0x0c0a94d0u; r[16]=code_base|0x0c0a920cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a920cu) { target=s->pc; goto dispatch; }
goto P_0c0a920c;
P_0c0a920a: /* original 64c3, guest PC 0x0c0a920a */
if(!s->budget--) { s->failed_pc=0x0c0a920au; return 0; }
r[4]=r[12];
goto P_0c0a920c;
P_0c0a920c: /* original d326, guest PC 0x0c0a920c */
if(!s->budget--) { s->failed_pc=0x0c0a920cu; return 0; }
r[3]=read(ram,0x0c0a92a8u,4);
goto P_0c0a920e;
P_0c0a920e: /* original e028, guest PC 0x0c0a920e */
if(!s->budget--) { s->failed_pc=0x0c0a920eu; return 0; }
r[0]=0x00000028u;
goto P_0c0a9210;
P_0c0a9210: /* original 66d3, guest PC 0x0c0a9210 */
if(!s->budget--) { s->failed_pc=0x0c0a9210u; return 0; }
r[6]=r[13];
goto P_0c0a9212;
P_0c0a9212: /* original 65b3, guest PC 0x0c0a9212 */
if(!s->budget--) { s->failed_pc=0x0c0a9212u; return 0; }
r[5]=r[11];
goto P_0c0a9214;
P_0c0a9214: /* original f438, guest PC 0x0c0a9214 */
if(!s->budget--) { s->failed_pc=0x0c0a9214u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0a9216;
P_0c0a9216: /* original 7c40, guest PC 0x0c0a9216 */
if(!s->budget--) { s->failed_pc=0x0c0a9216u; return 0; }
r[12]+=0x00000040u;
goto P_0c0a9218;
P_0c0a9218: /* original fd47, guest PC 0x0c0a9218 */
if(!s->budget--) { s->failed_pc=0x0c0a9218u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a921a;
P_0c0a921a: /* original b159, guest PC 0x0c0a921a */
if(!s->budget--) { s->failed_pc=0x0c0a921au; return 0; }
target=code_base|0x0c0a94d0u; r[16]=code_base|0x0c0a921eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a921eu) { target=s->pc; goto dispatch; }
goto P_0c0a921e;
P_0c0a921c: /* original 64c3, guest PC 0x0c0a921c */
if(!s->budget--) { s->failed_pc=0x0c0a921cu; return 0; }
r[4]=r[12];
goto P_0c0a921e;
P_0c0a921e: /* original d323, guest PC 0x0c0a921e */
if(!s->budget--) { s->failed_pc=0x0c0a921eu; return 0; }
r[3]=read(ram,0x0c0a92acu,4);
goto P_0c0a9220;
P_0c0a9220: /* original e028, guest PC 0x0c0a9220 */
if(!s->budget--) { s->failed_pc=0x0c0a9220u; return 0; }
r[0]=0x00000028u;
goto P_0c0a9222;
P_0c0a9222: /* original f438, guest PC 0x0c0a9222 */
if(!s->budget--) { s->failed_pc=0x0c0a9222u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0a9224;
P_0c0a9224: /* original fd47, guest PC 0x0c0a9224 */
if(!s->budget--) { s->failed_pc=0x0c0a9224u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a9226;
P_0c0a9226: /* original 5de4, guest PC 0x0c0a9226 */
if(!s->budget--) { s->failed_pc=0x0c0a9226u; return 0; }
r[13]=read(ram,r[14]+16,4);
goto P_0c0a9228;
P_0c0a9228: /* original 5ee5, guest PC 0x0c0a9228 */
if(!s->budget--) { s->failed_pc=0x0c0a9228u; return 0; }
r[14]=read(ram,r[14]+20,4);
goto P_0c0a922a;
P_0c0a922a: /* original d221, guest PC 0x0c0a922a */
if(!s->budget--) { s->failed_pc=0x0c0a922au; return 0; }
r[2]=read(ram,0x0c0a92b0u,4);
goto P_0c0a922c;
P_0c0a922c: /* original 65e3, guest PC 0x0c0a922c */
if(!s->budget--) { s->failed_pc=0x0c0a922cu; return 0; }
r[5]=r[14];
goto P_0c0a922e;
P_0c0a922e: /* original 420b, guest PC 0x0c0a922e */
if(!s->budget--) { s->failed_pc=0x0c0a922eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9232u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9232u) { target=s->pc; goto dispatch; }
goto P_0c0a9232;
P_0c0a9230: /* original 64d3, guest PC 0x0c0a9230 */
if(!s->budget--) { s->failed_pc=0x0c0a9230u; return 0; }
r[4]=r[13];
goto P_0c0a9232;
P_0c0a9232: /* original 4f26, guest PC 0x0c0a9232 */
if(!s->budget--) { s->failed_pc=0x0c0a9232u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9234;
P_0c0a9234: /* original 65d3, guest PC 0x0c0a9234 */
if(!s->budget--) { s->failed_pc=0x0c0a9234u; return 0; }
r[5]=r[13];
goto P_0c0a9236;
P_0c0a9236: /* original d31e, guest PC 0x0c0a9236 */
if(!s->budget--) { s->failed_pc=0x0c0a9236u; return 0; }
r[3]=read(ram,0x0c0a92b0u,4);
goto P_0c0a9238;
P_0c0a9238: /* original 64e3, guest PC 0x0c0a9238 */
if(!s->budget--) { s->failed_pc=0x0c0a9238u; return 0; }
r[4]=r[14];
goto P_0c0a923a;
P_0c0a923a: /* original 6bf6, guest PC 0x0c0a923a */
if(!s->budget--) { s->failed_pc=0x0c0a923au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a923c;
P_0c0a923c: /* original 6cf6, guest PC 0x0c0a923c */
if(!s->budget--) { s->failed_pc=0x0c0a923cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a923e;
P_0c0a923e: /* original 6df6, guest PC 0x0c0a923e */
if(!s->budget--) { s->failed_pc=0x0c0a923eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9240;
P_0c0a9240: /* original 432b, guest PC 0x0c0a9240 */
if(!s->budget--) { s->failed_pc=0x0c0a9240u; return 0; }
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
P_0c0a9242: /* original 6ef6, guest PC 0x0c0a9242 */
if(!s->budget--) { s->failed_pc=0x0c0a9242u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a9244u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9244u; return 0; } return 1;
P_0c0a92c8: /* original 2fe6, guest PC 0x0c0a92c8 */
if(!s->budget--) { s->failed_pc=0x0c0a92c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a92ca;
P_0c0a92ca: /* original 6e43, guest PC 0x0c0a92ca */
if(!s->budget--) { s->failed_pc=0x0c0a92cau; return 0; }
r[14]=r[4];
goto P_0c0a92cc;
P_0c0a92cc: /* original 2fd6, guest PC 0x0c0a92cc */
if(!s->budget--) { s->failed_pc=0x0c0a92ccu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a92ce;
P_0c0a92ce: /* original ed01, guest PC 0x0c0a92ce */
if(!s->budget--) { s->failed_pc=0x0c0a92ceu; return 0; }
r[13]=0x00000001u;
goto P_0c0a92d0;
P_0c0a92d0: /* original 2fc6, guest PC 0x0c0a92d0 */
if(!s->budget--) { s->failed_pc=0x0c0a92d0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a92d2;
P_0c0a92d2: /* original dc39, guest PC 0x0c0a92d2 */
if(!s->budget--) { s->failed_pc=0x0c0a92d2u; return 0; }
r[12]=read(ram,0x0c0a93b8u,4);
goto P_0c0a92d4;
P_0c0a92d4: /* original 9063, guest PC 0x0c0a92d4 */
if(!s->budget--) { s->failed_pc=0x0c0a92d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a939eu,2);
goto P_0c0a92d6;
P_0c0a92d6: /* original 56c5, guest PC 0x0c0a92d6 */
if(!s->budget--) { s->failed_pc=0x0c0a92d6u; return 0; }
r[6]=read(ram,r[12]+20,4);
goto P_0c0a92d8;
P_0c0a92d8: /* original 54c4, guest PC 0x0c0a92d8 */
if(!s->budget--) { s->failed_pc=0x0c0a92d8u; return 0; }
r[4]=read(ram,r[12]+16,4);
goto P_0c0a92da;
P_0c0a92da: /* original 4f22, guest PC 0x0c0a92da */
if(!s->budget--) { s->failed_pc=0x0c0a92dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a92dc;
P_0c0a92dc: /* original 04d4, guest PC 0x0c0a92dc */
if(!s->budget--) { s->failed_pc=0x0c0a92dcu; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c0a92de;
P_0c0a92de: /* original 06d4, guest PC 0x0c0a92de */
if(!s->budget--) { s->failed_pc=0x0c0a92deu; return 0; }
write(ram,r[6]+r[0],r[13],1);
goto P_0c0a92e0;
P_0c0a92e0: /* original 84e4, guest PC 0x0c0a92e0 */
if(!s->budget--) { s->failed_pc=0x0c0a92e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0a92e2;
P_0c0a92e2: /* original 7ffc, guest PC 0x0c0a92e2 */
if(!s->budget--) { s->failed_pc=0x0c0a92e2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a92e4;
P_0c0a92e4: /* original d335, guest PC 0x0c0a92e4 */
if(!s->budget--) { s->failed_pc=0x0c0a92e4u; return 0; }
r[3]=read(ram,0x0c0a93bcu,4);
goto P_0c0a92e6;
P_0c0a92e6: /* original 660e, guest PC 0x0c0a92e6 */
if(!s->budget--) { s->failed_pc=0x0c0a92e6u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0a92e8;
P_0c0a92e8: /* original 2668, guest PC 0x0c0a92e8 */
if(!s->budget--) { s->failed_pc=0x0c0a92e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a92ea;
P_0c0a92ea: /* original 8d01, guest PC 0x0c0a92ea */
if(!s->budget--) { s->failed_pc=0x0c0a92eau; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(cond) { goto P_0c0a92f0; }
goto P_0c0a92ee;
P_0c0a92ec: /* original 6432, guest PC 0x0c0a92ec */
if(!s->budget--) { s->failed_pc=0x0c0a92ecu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0a92ee;
P_0c0a92ee: /* original 4419, guest PC 0x0c0a92ee */
if(!s->budget--) { s->failed_pc=0x0c0a92eeu; return 0; }
r[4]>>=8;
goto P_0c0a92f0;
P_0c0a92f0: /* original e061, guest PC 0x0c0a92f0 */
if(!s->budget--) { s->failed_pc=0x0c0a92f0u; return 0; }
r[0]=0x00000061u;
goto P_0c0a92f2;
P_0c0a92f2: /* original 03ec, guest PC 0x0c0a92f2 */
if(!s->budget--) { s->failed_pc=0x0c0a92f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a92f4;
P_0c0a92f4: /* original 2f30, guest PC 0x0c0a92f4 */
if(!s->budget--) { s->failed_pc=0x0c0a92f4u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0a92f6;
P_0c0a92f6: /* original 67f0, guest PC 0x0c0a92f6 */
if(!s->budget--) { s->failed_pc=0x0c0a92f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[7]=tmp;
goto P_0c0a92f8;
P_0c0a92f8: /* original 6073, guest PC 0x0c0a92f8 */
if(!s->budget--) { s->failed_pc=0x0c0a92f8u; return 0; }
r[0]=r[7];
goto P_0c0a92fa;
P_0c0a92fa: /* original 8803, guest PC 0x0c0a92fa */
if(!s->budget--) { s->failed_pc=0x0c0a92fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a92fc;
P_0c0a92fc: /* original 8d03, guest PC 0x0c0a92fc */
if(!s->budget--) { s->failed_pc=0x0c0a92fcu; return 0; }
cond=r[17]&1u;
r[6]=r[4];
if(cond) { goto P_0c0a9306; }
goto P_0c0a9300;
P_0c0a92fe: /* original 6643, guest PC 0x0c0a92fe */
if(!s->budget--) { s->failed_pc=0x0c0a92feu; return 0; }
r[6]=r[4];
goto P_0c0a9300;
P_0c0a9300: /* original 6073, guest PC 0x0c0a9300 */
if(!s->budget--) { s->failed_pc=0x0c0a9300u; return 0; }
r[0]=r[7];
goto P_0c0a9302;
P_0c0a9302: /* original 8801, guest PC 0x0c0a9302 */
if(!s->budget--) { s->failed_pc=0x0c0a9302u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a9304;
P_0c0a9304: /* original 8b11, guest PC 0x0c0a9304 */
if(!s->budget--) { s->failed_pc=0x0c0a9304u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a932a; }
goto P_0c0a9306;
P_0c0a9306: /* original d32e, guest PC 0x0c0a9306 */
if(!s->budget--) { s->failed_pc=0x0c0a9306u; return 0; }
r[3]=read(ram,0x0c0a93c0u,4);
goto P_0c0a9308;
P_0c0a9308: /* original 924a, guest PC 0x0c0a9308 */
if(!s->budget--) { s->failed_pc=0x0c0a9308u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a0u,2);
goto P_0c0a930a;
P_0c0a930a: /* original 2439, guest PC 0x0c0a930a */
if(!s->budget--) { s->failed_pc=0x0c0a930au; return 0; }
r[4]&=r[3];
goto P_0c0a930c;
P_0c0a930c: /* original 3420, guest PC 0x0c0a930c */
if(!s->budget--) { s->failed_pc=0x0c0a930cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0a930e;
P_0c0a930e: /* original 8b0c, guest PC 0x0c0a930e */
if(!s->budget--) { s->failed_pc=0x0c0a930eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a932a; }
goto P_0c0a9310;
P_0c0a9310: /* original 9047, guest PC 0x0c0a9310 */
if(!s->budget--) { s->failed_pc=0x0c0a9310u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a2u,2);
goto P_0c0a9312;
P_0c0a9312: /* original e31c, guest PC 0x0c0a9312 */
if(!s->budget--) { s->failed_pc=0x0c0a9312u; return 0; }
r[3]=0x0000001cu;
goto P_0c0a9314;
P_0c0a9314: /* original 54c8, guest PC 0x0c0a9314 */
if(!s->budget--) { s->failed_pc=0x0c0a9314u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c0a9316;
P_0c0a9316: /* original 0436, guest PC 0x0c0a9316 */
if(!s->budget--) { s->failed_pc=0x0c0a9316u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0a9318;
P_0c0a9318: /* original 9041, guest PC 0x0c0a9318 */
if(!s->budget--) { s->failed_pc=0x0c0a9318u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a939eu,2);
goto P_0c0a931a;
P_0c0a931a: /* original 0ed4, guest PC 0x0c0a931a */
if(!s->budget--) { s->failed_pc=0x0c0a931au; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a931c;
P_0c0a931c: /* original 6073, guest PC 0x0c0a931c */
if(!s->budget--) { s->failed_pc=0x0c0a931cu; return 0; }
r[0]=r[7];
goto P_0c0a931e;
P_0c0a931e: /* original 9441, guest PC 0x0c0a931e */
if(!s->budget--) { s->failed_pc=0x0c0a931eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a4u,2);
goto P_0c0a9320;
P_0c0a9320: /* original 8803, guest PC 0x0c0a9320 */
if(!s->budget--) { s->failed_pc=0x0c0a9320u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a9322;
P_0c0a9322: /* original 8971, guest PC 0x0c0a9322 */
if(!s->budget--) { s->failed_pc=0x0c0a9322u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9408; }
goto P_0c0a9324;
P_0c0a9324: /* original 943f, guest PC 0x0c0a9324 */
if(!s->budget--) { s->failed_pc=0x0c0a9324u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a6u,2);
goto P_0c0a9326;
P_0c0a9326: /* original a06f, guest PC 0x0c0a9326 */
if(!s->budget--) { s->failed_pc=0x0c0a9326u; return 0; }
goto P_0c0a9408;
P_0c0a9328: /* original 0009, guest PC 0x0c0a9328 */
if(!s->budget--) { s->failed_pc=0x0c0a9328u; return 0; }
goto P_0c0a932a;
P_0c0a932a: /* original d726, guest PC 0x0c0a932a */
if(!s->budget--) { s->failed_pc=0x0c0a932au; return 0; }
r[7]=read(ram,0x0c0a93c4u,4);
goto P_0c0a932c;
P_0c0a932c: /* original e018, guest PC 0x0c0a932c */
if(!s->budget--) { s->failed_pc=0x0c0a932cu; return 0; }
r[0]=0x00000018u;
goto P_0c0a932e;
P_0c0a932e: /* original 047c, guest PC 0x0c0a932e */
if(!s->budget--) { s->failed_pc=0x0c0a932eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0a9330;
P_0c0a9330: /* original 2448, guest PC 0x0c0a9330 */
if(!s->budget--) { s->failed_pc=0x0c0a9330u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9332;
P_0c0a9332: /* original 8b17, guest PC 0x0c0a9332 */
if(!s->budget--) { s->failed_pc=0x0c0a9332u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9364; }
goto P_0c0a9334;
P_0c0a9334: /* original 6403, guest PC 0x0c0a9334 */
if(!s->budget--) { s->failed_pc=0x0c0a9334u; return 0; }
r[4]=r[0];
goto P_0c0a9336;
P_0c0a9336: /* original 9037, guest PC 0x0c0a9336 */
if(!s->budget--) { s->failed_pc=0x0c0a9336u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a8u,2);
goto P_0c0a9338;
P_0c0a9338: /* original 02ed, guest PC 0x0c0a9338 */
if(!s->budget--) { s->failed_pc=0x0c0a9338u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a933a;
P_0c0a933a: /* original e046, guest PC 0x0c0a933a */
if(!s->budget--) { s->failed_pc=0x0c0a933au; return 0; }
r[0]=0x00000046u;
goto P_0c0a933c;
P_0c0a933c: /* original 03ed, guest PC 0x0c0a933c */
if(!s->budget--) { s->failed_pc=0x0c0a933cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a933e;
P_0c0a933e: /* original 633d, guest PC 0x0c0a933e */
if(!s->budget--) { s->failed_pc=0x0c0a933eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a9340;
P_0c0a9340: /* original 3230, guest PC 0x0c0a9340 */
if(!s->budget--) { s->failed_pc=0x0c0a9340u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0a9342;
P_0c0a9342: /* original 8b0f, guest PC 0x0c0a9342 */
if(!s->budget--) { s->failed_pc=0x0c0a9342u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9364; }
goto P_0c0a9344;
P_0c0a9344: /* original e061, guest PC 0x0c0a9344 */
if(!s->budget--) { s->failed_pc=0x0c0a9344u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9346;
P_0c0a9346: /* original 025c, guest PC 0x0c0a9346 */
if(!s->budget--) { s->failed_pc=0x0c0a9346u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a9348;
P_0c0a9348: /* original 2228, guest PC 0x0c0a9348 */
if(!s->budget--) { s->failed_pc=0x0c0a9348u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a934a;
P_0c0a934a: /* original 8b4d, guest PC 0x0c0a934a */
if(!s->budget--) { s->failed_pc=0x0c0a934au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a93e8; }
goto P_0c0a934c;
P_0c0a934c: /* original 00ec, guest PC 0x0c0a934c */
if(!s->budget--) { s->failed_pc=0x0c0a934cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a934e;
P_0c0a934e: /* original 600c, guest PC 0x0c0a934e */
if(!s->budget--) { s->failed_pc=0x0c0a934eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9350;
P_0c0a9350: /* original 8806, guest PC 0x0c0a9350 */
if(!s->budget--) { s->failed_pc=0x0c0a9350u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0a9352;
P_0c0a9352: /* original 8b49, guest PC 0x0c0a9352 */
if(!s->budget--) { s->failed_pc=0x0c0a9352u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a93e8; }
goto P_0c0a9354;
P_0c0a9354: /* original 9025, guest PC 0x0c0a9354 */
if(!s->budget--) { s->failed_pc=0x0c0a9354u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a2u,2);
goto P_0c0a9356;
P_0c0a9356: /* original e31c, guest PC 0x0c0a9356 */
if(!s->budget--) { s->failed_pc=0x0c0a9356u; return 0; }
r[3]=0x0000001cu;
goto P_0c0a9358;
P_0c0a9358: /* original 54c8, guest PC 0x0c0a9358 */
if(!s->budget--) { s->failed_pc=0x0c0a9358u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c0a935a;
P_0c0a935a: /* original 0436, guest PC 0x0c0a935a */
if(!s->budget--) { s->failed_pc=0x0c0a935au; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0a935c;
P_0c0a935c: /* original 9425, guest PC 0x0c0a935c */
if(!s->budget--) { s->failed_pc=0x0c0a935cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93aau,2);
goto P_0c0a935e;
P_0c0a935e: /* original 901e, guest PC 0x0c0a935e */
if(!s->budget--) { s->failed_pc=0x0c0a935eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a939eu,2);
goto P_0c0a9360;
P_0c0a9360: /* original a052, guest PC 0x0c0a9360 */
if(!s->budget--) { s->failed_pc=0x0c0a9360u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a9408;
P_0c0a9362: /* original 0ed4, guest PC 0x0c0a9362 */
if(!s->budget--) { s->failed_pc=0x0c0a9362u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a9364;
P_0c0a9364: /* original 9422, guest PC 0x0c0a9364 */
if(!s->budget--) { s->failed_pc=0x0c0a9364u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93acu,2);
goto P_0c0a9366;
P_0c0a9366: /* original 6263, guest PC 0x0c0a9366 */
if(!s->budget--) { s->failed_pc=0x0c0a9366u; return 0; }
r[2]=r[6];
goto P_0c0a9368;
P_0c0a9368: /* original 2249, guest PC 0x0c0a9368 */
if(!s->budget--) { s->failed_pc=0x0c0a9368u; return 0; }
r[2]&=r[4];
goto P_0c0a936a;
P_0c0a936a: /* original 3240, guest PC 0x0c0a936a */
if(!s->budget--) { s->failed_pc=0x0c0a936au; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[4])!=0);
goto P_0c0a936c;
P_0c0a936c: /* original 8b01, guest PC 0x0c0a936c */
if(!s->budget--) { s->failed_pc=0x0c0a936cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9372; }
goto P_0c0a936e;
P_0c0a936e: /* original a03b, guest PC 0x0c0a936e */
if(!s->budget--) { s->failed_pc=0x0c0a936eu; return 0; }
r[4]=0x00000010u;
goto P_0c0a93e8;
P_0c0a9370: /* original e410, guest PC 0x0c0a9370 */
if(!s->budget--) { s->failed_pc=0x0c0a9370u; return 0; }
r[4]=0x00000010u;
goto P_0c0a9372;
P_0c0a9372: /* original 941c, guest PC 0x0c0a9372 */
if(!s->budget--) { s->failed_pc=0x0c0a9372u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93aeu,2);
goto P_0c0a9374;
P_0c0a9374: /* original 6263, guest PC 0x0c0a9374 */
if(!s->budget--) { s->failed_pc=0x0c0a9374u; return 0; }
r[2]=r[6];
goto P_0c0a9376;
P_0c0a9376: /* original 2249, guest PC 0x0c0a9376 */
if(!s->budget--) { s->failed_pc=0x0c0a9376u; return 0; }
r[2]&=r[4];
goto P_0c0a9378;
P_0c0a9378: /* original 3240, guest PC 0x0c0a9378 */
if(!s->budget--) { s->failed_pc=0x0c0a9378u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[4])!=0);
goto P_0c0a937a;
P_0c0a937a: /* original 8b01, guest PC 0x0c0a937a */
if(!s->budget--) { s->failed_pc=0x0c0a937au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9380; }
goto P_0c0a937c;
P_0c0a937c: /* original a034, guest PC 0x0c0a937c */
if(!s->budget--) { s->failed_pc=0x0c0a937cu; return 0; }
r[4]=0x00000014u;
goto P_0c0a93e8;
P_0c0a937e: /* original e414, guest PC 0x0c0a937e */
if(!s->budget--) { s->failed_pc=0x0c0a937eu; return 0; }
r[4]=0x00000014u;
goto P_0c0a9380;
P_0c0a9380: /* original 9316, guest PC 0x0c0a9380 */
if(!s->budget--) { s->failed_pc=0x0c0a9380u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93b0u,2);
goto P_0c0a9382;
P_0c0a9382: /* original 2368, guest PC 0x0c0a9382 */
if(!s->budget--) { s->failed_pc=0x0c0a9382u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0a9384;
P_0c0a9384: /* original 8901, guest PC 0x0c0a9384 */
if(!s->budget--) { s->failed_pc=0x0c0a9384u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a938a; }
goto P_0c0a9386;
P_0c0a9386: /* original a02f, guest PC 0x0c0a9386 */
if(!s->budget--) { s->failed_pc=0x0c0a9386u; return 0; }
r[4]=0x00000000u;
goto P_0c0a93e8;
P_0c0a9388: /* original e400, guest PC 0x0c0a9388 */
if(!s->budget--) { s->failed_pc=0x0c0a9388u; return 0; }
r[4]=0x00000000u;
goto P_0c0a938a;
P_0c0a938a: /* original 9312, guest PC 0x0c0a938a */
if(!s->budget--) { s->failed_pc=0x0c0a938au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93b2u,2);
goto P_0c0a938c;
P_0c0a938c: /* original 2368, guest PC 0x0c0a938c */
if(!s->budget--) { s->failed_pc=0x0c0a938cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0a938e;
P_0c0a938e: /* original 8901, guest PC 0x0c0a938e */
if(!s->budget--) { s->failed_pc=0x0c0a938eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9394; }
goto P_0c0a9390;
P_0c0a9390: /* original a02a, guest PC 0x0c0a9390 */
if(!s->budget--) { s->failed_pc=0x0c0a9390u; return 0; }
r[4]=0x00000004u;
goto P_0c0a93e8;
P_0c0a9392: /* original e404, guest PC 0x0c0a9392 */
if(!s->budget--) { s->failed_pc=0x0c0a9392u; return 0; }
r[4]=0x00000004u;
goto P_0c0a9394;
P_0c0a9394: /* original 920e, guest PC 0x0c0a9394 */
if(!s->budget--) { s->failed_pc=0x0c0a9394u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93b4u,2);
goto P_0c0a9396;
P_0c0a9396: /* original 2268, guest PC 0x0c0a9396 */
if(!s->budget--) { s->failed_pc=0x0c0a9396u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0a9398;
P_0c0a9398: /* original 8916, guest PC 0x0c0a9398 */
if(!s->budget--) { s->failed_pc=0x0c0a9398u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a93c8; }
goto P_0c0a939a;
P_0c0a939a: /* original a025, guest PC 0x0c0a939a */
if(!s->budget--) { s->failed_pc=0x0c0a939au; return 0; }
r[4]=0x00000008u;
goto P_0c0a93e8;
P_0c0a939c: /* original e408, guest PC 0x0c0a939c */
if(!s->budget--) { s->failed_pc=0x0c0a939cu; return 0; }
r[4]=0x00000008u;
if(!vf3_matrix_family(0x0c0a939eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a939eu; return 0; } return 1;
P_0c0a93c8: /* original 926d, guest PC 0x0c0a93c8 */
if(!s->budget--) { s->failed_pc=0x0c0a93c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94a6u,2);
goto P_0c0a93ca;
P_0c0a93ca: /* original 2628, guest PC 0x0c0a93ca */
if(!s->budget--) { s->failed_pc=0x0c0a93cau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0a93cc;
P_0c0a93cc: /* original 8901, guest PC 0x0c0a93cc */
if(!s->budget--) { s->failed_pc=0x0c0a93ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a93d2; }
goto P_0c0a93ce;
P_0c0a93ce: /* original a00b, guest PC 0x0c0a93ce */
if(!s->budget--) { s->failed_pc=0x0c0a93ceu; return 0; }
r[4]=0x0000000cu;
goto P_0c0a93e8;
P_0c0a93d0: /* original e40c, guest PC 0x0c0a93d0 */
if(!s->budget--) { s->failed_pc=0x0c0a93d0u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a93d2;
P_0c0a93d2: /* original d138, guest PC 0x0c0a93d2 */
if(!s->budget--) { s->failed_pc=0x0c0a93d2u; return 0; }
r[1]=read(ram,0x0c0a94b4u,4);
goto P_0c0a93d4;
P_0c0a93d4: /* original d336, guest PC 0x0c0a93d4 */
if(!s->budget--) { s->failed_pc=0x0c0a93d4u; return 0; }
r[3]=read(ram,0x0c0a94b0u,4);
goto P_0c0a93d6;
P_0c0a93d6: /* original 5472, guest PC 0x0c0a93d6 */
if(!s->budget--) { s->failed_pc=0x0c0a93d6u; return 0; }
r[4]=read(ram,r[7]+8,4);
goto P_0c0a93d8;
P_0c0a93d8: /* original 410b, guest PC 0x0c0a93d8 */
if(!s->budget--) { s->failed_pc=0x0c0a93d8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a93dcu;
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a93dcu) { target=s->pc; goto dispatch; }
goto P_0c0a93dc;
P_0c0a93da: /* original 2438, guest PC 0x0c0a93da */
if(!s->budget--) { s->failed_pc=0x0c0a93dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0a93dc;
P_0c0a93dc: /* original d236, guest PC 0x0c0a93dc */
if(!s->budget--) { s->failed_pc=0x0c0a93dcu; return 0; }
r[2]=read(ram,0x0c0a94b8u,4);
goto P_0c0a93de;
P_0c0a93de: /* original 6103, guest PC 0x0c0a93de */
if(!s->budget--) { s->failed_pc=0x0c0a93deu; return 0; }
r[1]=r[0];
goto P_0c0a93e0;
P_0c0a93e0: /* original 420b, guest PC 0x0c0a93e0 */
if(!s->budget--) { s->failed_pc=0x0c0a93e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a93e4u;
r[0]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a93e4u) { target=s->pc; goto dispatch; }
goto P_0c0a93e4;
P_0c0a93e2: /* original e006, guest PC 0x0c0a93e2 */
if(!s->budget--) { s->failed_pc=0x0c0a93e2u; return 0; }
r[0]=0x00000006u;
goto P_0c0a93e4;
P_0c0a93e4: /* original 6403, guest PC 0x0c0a93e4 */
if(!s->budget--) { s->failed_pc=0x0c0a93e4u; return 0; }
r[4]=r[0];
goto P_0c0a93e6;
P_0c0a93e6: /* original 4408, guest PC 0x0c0a93e6 */
if(!s->budget--) { s->failed_pc=0x0c0a93e6u; return 0; }
r[4]<<=2;
goto P_0c0a93e8;
P_0c0a93e8: /* original 905e, guest PC 0x0c0a93e8 */
if(!s->budget--) { s->failed_pc=0x0c0a93e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94a8u,2);
goto P_0c0a93ea;
P_0c0a93ea: /* original 55c8, guest PC 0x0c0a93ea */
if(!s->budget--) { s->failed_pc=0x0c0a93eau; return 0; }
r[5]=read(ram,r[12]+32,4);
goto P_0c0a93ec;
P_0c0a93ec: /* original 0546, guest PC 0x0c0a93ec */
if(!s->budget--) { s->failed_pc=0x0c0a93ecu; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0a93ee;
P_0c0a93ee: /* original 4409, guest PC 0x0c0a93ee */
if(!s->budget--) { s->failed_pc=0x0c0a93eeu; return 0; }
r[4]>>=2;
goto P_0c0a93f0;
P_0c0a93f0: /* original 905b, guest PC 0x0c0a93f0 */
if(!s->budget--) { s->failed_pc=0x0c0a93f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94aau,2);
goto P_0c0a93f2;
P_0c0a93f2: /* original 6543, guest PC 0x0c0a93f2 */
if(!s->budget--) { s->failed_pc=0x0c0a93f2u; return 0; }
r[5]=r[4];
goto P_0c0a93f4;
P_0c0a93f4: /* original 4508, guest PC 0x0c0a93f4 */
if(!s->budget--) { s->failed_pc=0x0c0a93f4u; return 0; }
r[5]<<=2;
goto P_0c0a93f6;
P_0c0a93f6: /* original 0ed4, guest PC 0x0c0a93f6 */
if(!s->budget--) { s->failed_pc=0x0c0a93f6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a93f8;
P_0c0a93f8: /* original d030, guest PC 0x0c0a93f8 */
if(!s->budget--) { s->failed_pc=0x0c0a93f8u; return 0; }
r[0]=read(ram,0x0c0a94bcu,4);
goto P_0c0a93fa;
P_0c0a93fa: /* original 055e, guest PC 0x0c0a93fa */
if(!s->budget--) { s->failed_pc=0x0c0a93fau; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0a93fc;
P_0c0a93fc: /* original e061, guest PC 0x0c0a93fc */
if(!s->budget--) { s->failed_pc=0x0c0a93fcu; return 0; }
r[0]=0x00000061u;
goto P_0c0a93fe;
P_0c0a93fe: /* original 00ec, guest PC 0x0c0a93fe */
if(!s->budget--) { s->failed_pc=0x0c0a93feu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a9400;
P_0c0a9400: /* original 600c, guest PC 0x0c0a9400 */
if(!s->budget--) { s->failed_pc=0x0c0a9400u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9402;
P_0c0a9402: /* original 4000, guest PC 0x0c0a9402 */
if(!s->budget--) { s->failed_pc=0x0c0a9402u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0a9404;
P_0c0a9404: /* original 045d, guest PC 0x0c0a9404 */
if(!s->budget--) { s->failed_pc=0x0c0a9404u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a9406;
P_0c0a9406: /* original 644d, guest PC 0x0c0a9406 */
if(!s->budget--) { s->failed_pc=0x0c0a9406u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9408;
P_0c0a9408: /* original e03c, guest PC 0x0c0a9408 */
if(!s->budget--) { s->failed_pc=0x0c0a9408u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a940a;
P_0c0a940a: /* original 0e45, guest PC 0x0c0a940a */
if(!s->budget--) { s->failed_pc=0x0c0a940au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a940c;
P_0c0a940c: /* original e03e, guest PC 0x0c0a940c */
if(!s->budget--) { s->failed_pc=0x0c0a940cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0a940e;
P_0c0a940e: /* original 1e4d, guest PC 0x0c0a940e */
if(!s->budget--) { s->failed_pc=0x0c0a940eu; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c0a9410;
P_0c0a9410: /* original 0ed5, guest PC 0x0c0a9410 */
if(!s->budget--) { s->failed_pc=0x0c0a9410u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0a9412;
P_0c0a9412: /* original e010, guest PC 0x0c0a9412 */
if(!s->budget--) { s->failed_pc=0x0c0a9412u; return 0; }
r[0]=0x00000010u;
goto P_0c0a9414;
P_0c0a9414: /* original f4e6, guest PC 0x0c0a9414 */
if(!s->budget--) { s->failed_pc=0x0c0a9414u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a9416;
P_0c0a9416: /* original e018, guest PC 0x0c0a9416 */
if(!s->budget--) { s->failed_pc=0x0c0a9416u; return 0; }
r[0]=0x00000018u;
goto P_0c0a9418;
P_0c0a9418: /* original d329, guest PC 0x0c0a9418 */
if(!s->budget--) { s->failed_pc=0x0c0a9418u; return 0; }
r[3]=read(ram,0x0c0a94c0u,4);
goto P_0c0a941a;
P_0c0a941a: /* original f5e6, guest PC 0x0c0a941a */
if(!s->budget--) { s->failed_pc=0x0c0a941au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a941c;
P_0c0a941c: /* original 430b, guest PC 0x0c0a941c */
if(!s->budget--) { s->failed_pc=0x0c0a941cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9420u;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9420u) { target=s->pc; goto dispatch; }
goto P_0c0a9420;
P_0c0a941e: /* original f54d, guest PC 0x0c0a941e */
if(!s->budget--) { s->failed_pc=0x0c0a941eu; return 0; }
fr[5]^=0x80000000u;
goto P_0c0a9420;
P_0c0a9420: /* original e024, guest PC 0x0c0a9420 */
if(!s->budget--) { s->failed_pc=0x0c0a9420u; return 0; }
r[0]=0x00000024u;
goto P_0c0a9422;
P_0c0a9422: /* original f58d, guest PC 0x0c0a9422 */
if(!s->budget--) { s->failed_pc=0x0c0a9422u; return 0; }
fr[5]=0;
goto P_0c0a9424;
P_0c0a9424: /* original 7f04, guest PC 0x0c0a9424 */
if(!s->budget--) { s->failed_pc=0x0c0a9424u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a9426;
P_0c0a9426: /* original f40c, guest PC 0x0c0a9426 */
if(!s->budget--) { s->failed_pc=0x0c0a9426u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0a9428;
P_0c0a9428: /* original fe57, guest PC 0x0c0a9428 */
if(!s->budget--) { s->failed_pc=0x0c0a9428u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a942a;
P_0c0a942a: /* original e028, guest PC 0x0c0a942a */
if(!s->budget--) { s->failed_pc=0x0c0a942au; return 0; }
r[0]=0x00000028u;
goto P_0c0a942c;
P_0c0a942c: /* original fe57, guest PC 0x0c0a942c */
if(!s->budget--) { s->failed_pc=0x0c0a942cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a942e;
P_0c0a942e: /* original e02c, guest PC 0x0c0a942e */
if(!s->budget--) { s->failed_pc=0x0c0a942eu; return 0; }
r[0]=0x0000002cu;
goto P_0c0a9430;
P_0c0a9430: /* original 4f26, guest PC 0x0c0a9430 */
if(!s->budget--) { s->failed_pc=0x0c0a9430u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9432;
P_0c0a9432: /* original fe57, guest PC 0x0c0a9432 */
if(!s->budget--) { s->failed_pc=0x0c0a9432u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a9434;
P_0c0a9434: /* original e014, guest PC 0x0c0a9434 */
if(!s->budget--) { s->failed_pc=0x0c0a9434u; return 0; }
r[0]=0x00000014u;
goto P_0c0a9436;
P_0c0a9436: /* original fe47, guest PC 0x0c0a9436 */
if(!s->budget--) { s->failed_pc=0x0c0a9436u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9438;
P_0c0a9438: /* original 9038, guest PC 0x0c0a9438 */
if(!s->budget--) { s->failed_pc=0x0c0a9438u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94acu,2);
goto P_0c0a943a;
P_0c0a943a: /* original fe47, guest PC 0x0c0a943a */
if(!s->budget--) { s->failed_pc=0x0c0a943au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a943c;
P_0c0a943c: /* original 6cf6, guest PC 0x0c0a943c */
if(!s->budget--) { s->failed_pc=0x0c0a943cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a943e;
P_0c0a943e: /* original 6df6, guest PC 0x0c0a943e */
if(!s->budget--) { s->failed_pc=0x0c0a943eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9440;
P_0c0a9440: /* original 000b, guest PC 0x0c0a9440 */
if(!s->budget--) { s->failed_pc=0x0c0a9440u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9442: /* original 6ef6, guest PC 0x0c0a9442 */
if(!s->budget--) { s->failed_pc=0x0c0a9442u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a9444u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9444u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
