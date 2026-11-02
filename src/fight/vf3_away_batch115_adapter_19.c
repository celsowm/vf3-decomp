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
int vf3_away_batch115_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b22c4u: goto P_0c0b22c4;
case 0x0c0b22c6u: goto P_0c0b22c6;
case 0x0c0b22c8u: goto P_0c0b22c8;
case 0x0c0b22cau: goto P_0c0b22ca;
case 0x0c0b22ccu: goto P_0c0b22cc;
case 0x0c0b22ceu: goto P_0c0b22ce;
case 0x0c0b22d0u: goto P_0c0b22d0;
case 0x0c0b22d2u: goto P_0c0b22d2;
case 0x0c0b22d4u: goto P_0c0b22d4;
case 0x0c0b22d6u: goto P_0c0b22d6;
case 0x0c0b22d8u: goto P_0c0b22d8;
case 0x0c0b22dau: goto P_0c0b22da;
case 0x0c0b22dcu: goto P_0c0b22dc;
case 0x0c0b22deu: goto P_0c0b22de;
case 0x0c0b22e0u: goto P_0c0b22e0;
case 0x0c0b22e2u: goto P_0c0b22e2;
case 0x0c0b22e4u: goto P_0c0b22e4;
case 0x0c0b22e6u: goto P_0c0b22e6;
case 0x0c0b22e8u: goto P_0c0b22e8;
case 0x0c0b22eau: goto P_0c0b22ea;
case 0x0c0b22ecu: goto P_0c0b22ec;
case 0x0c0b22eeu: goto P_0c0b22ee;
case 0x0c0b22f0u: goto P_0c0b22f0;
case 0x0c0b22f2u: goto P_0c0b22f2;
case 0x0c0b22f4u: goto P_0c0b22f4;
case 0x0c0b22f6u: goto P_0c0b22f6;
case 0x0c0b22f8u: goto P_0c0b22f8;
case 0x0c0b22fau: goto P_0c0b22fa;
case 0x0c0b22fcu: goto P_0c0b22fc;
case 0x0c0b22feu: goto P_0c0b22fe;
case 0x0c0b2300u: goto P_0c0b2300;
case 0x0c0b2302u: goto P_0c0b2302;
case 0x0c0b2304u: goto P_0c0b2304;
case 0x0c0b2306u: goto P_0c0b2306;
case 0x0c0b2308u: goto P_0c0b2308;
case 0x0c0b230au: goto P_0c0b230a;
case 0x0c0b230cu: goto P_0c0b230c;
case 0x0c0b230eu: goto P_0c0b230e;
case 0x0c0b2310u: goto P_0c0b2310;
case 0x0c0b2312u: goto P_0c0b2312;
case 0x0c0b2314u: goto P_0c0b2314;
case 0x0c0b2316u: goto P_0c0b2316;
case 0x0c0b2318u: goto P_0c0b2318;
case 0x0c0b231au: goto P_0c0b231a;
case 0x0c0b231cu: goto P_0c0b231c;
case 0x0c0b231eu: goto P_0c0b231e;
case 0x0c0b2320u: goto P_0c0b2320;
case 0x0c0b2322u: goto P_0c0b2322;
case 0x0c0b2324u: goto P_0c0b2324;
case 0x0c0b2326u: goto P_0c0b2326;
case 0x0c0b2328u: goto P_0c0b2328;
case 0x0c0b232au: goto P_0c0b232a;
case 0x0c0b232cu: goto P_0c0b232c;
case 0x0c0b232eu: goto P_0c0b232e;
case 0x0c0b2330u: goto P_0c0b2330;
case 0x0c0b2332u: goto P_0c0b2332;
case 0x0c0b2334u: goto P_0c0b2334;
case 0x0c0b2336u: goto P_0c0b2336;
case 0x0c0b2338u: goto P_0c0b2338;
case 0x0c0b233au: goto P_0c0b233a;
case 0x0c0b233cu: goto P_0c0b233c;
case 0x0c0b233eu: goto P_0c0b233e;
case 0x0c0b2340u: goto P_0c0b2340;
case 0x0c0b2342u: goto P_0c0b2342;
case 0x0c0b2344u: goto P_0c0b2344;
case 0x0c0b2346u: goto P_0c0b2346;
case 0x0c0b2348u: goto P_0c0b2348;
case 0x0c0b234au: goto P_0c0b234a;
case 0x0c0b234cu: goto P_0c0b234c;
case 0x0c0b234eu: goto P_0c0b234e;
case 0x0c0b2350u: goto P_0c0b2350;
case 0x0c0b2352u: goto P_0c0b2352;
case 0x0c0b2354u: goto P_0c0b2354;
case 0x0c0b2356u: goto P_0c0b2356;
case 0x0c0b2358u: goto P_0c0b2358;
case 0x0c0b235au: goto P_0c0b235a;
case 0x0c0b235cu: goto P_0c0b235c;
case 0x0c0b235eu: goto P_0c0b235e;
case 0x0c0b2360u: goto P_0c0b2360;
case 0x0c0b2362u: goto P_0c0b2362;
case 0x0c0b2364u: goto P_0c0b2364;
case 0x0c0b2366u: goto P_0c0b2366;
case 0x0c0b2368u: goto P_0c0b2368;
case 0x0c0b236au: goto P_0c0b236a;
case 0x0c0b236cu: goto P_0c0b236c;
case 0x0c0b236eu: goto P_0c0b236e;
case 0x0c0b2370u: goto P_0c0b2370;
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
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c66d0u: goto P_0c0c66d0;
case 0x0c0c66d2u: goto P_0c0c66d2;
case 0x0c0c761eu: goto P_0c0c761e;
case 0x0c0c7620u: goto P_0c0c7620;
case 0x0c0c7622u: goto P_0c0c7622;
case 0x0c0c7624u: goto P_0c0c7624;
case 0x0c0c7626u: goto P_0c0c7626;
case 0x0c0c7628u: goto P_0c0c7628;
case 0x0c0c762au: goto P_0c0c762a;
case 0x0c0c762cu: goto P_0c0c762c;
case 0x0c0c7648u: goto P_0c0c7648;
case 0x0c0c764au: goto P_0c0c764a;
case 0x0c0c764cu: goto P_0c0c764c;
case 0x0c0c764eu: goto P_0c0c764e;
case 0x0c0c7650u: goto P_0c0c7650;
case 0x0c0c7652u: goto P_0c0c7652;
case 0x0c0c7654u: goto P_0c0c7654;
case 0x0c0c7656u: goto P_0c0c7656;
case 0x0c0c7658u: goto P_0c0c7658;
case 0x0c0c765au: goto P_0c0c765a;
case 0x0c0c765cu: goto P_0c0c765c;
case 0x0c0c765eu: goto P_0c0c765e;
case 0x0c0c7660u: goto P_0c0c7660;
case 0x0c0c7662u: goto P_0c0c7662;
case 0x0c0c7664u: goto P_0c0c7664;
case 0x0c0c7666u: goto P_0c0c7666;
case 0x0c0c7668u: goto P_0c0c7668;
case 0x0c0c766au: goto P_0c0c766a;
case 0x0c0c766cu: goto P_0c0c766c;
case 0x0c0c766eu: goto P_0c0c766e;
case 0x0c0c7670u: goto P_0c0c7670;
case 0x0c0c7672u: goto P_0c0c7672;
case 0x0c0c7674u: goto P_0c0c7674;
case 0x0c0c7676u: goto P_0c0c7676;
case 0x0c0c7678u: goto P_0c0c7678;
case 0x0c0c767au: goto P_0c0c767a;
case 0x0c0c767cu: goto P_0c0c767c;
case 0x0c0c767eu: goto P_0c0c767e;
case 0x0c0c7680u: goto P_0c0c7680;
case 0x0c0c7682u: goto P_0c0c7682;
case 0x0c0c7684u: goto P_0c0c7684;
case 0x0c0c7686u: goto P_0c0c7686;
case 0x0c0c7688u: goto P_0c0c7688;
case 0x0c0c768au: goto P_0c0c768a;
case 0x0c0c768cu: goto P_0c0c768c;
case 0x0c0c768eu: goto P_0c0c768e;
case 0x0c0c7690u: goto P_0c0c7690;
case 0x0c0c7692u: goto P_0c0c7692;
case 0x0c0c7694u: goto P_0c0c7694;
case 0x0c0c7696u: goto P_0c0c7696;
case 0x0c0c7698u: goto P_0c0c7698;
case 0x0c0c769au: goto P_0c0c769a;
case 0x0c0c769cu: goto P_0c0c769c;
case 0x0c0c769eu: goto P_0c0c769e;
case 0x0c0c76a0u: goto P_0c0c76a0;
case 0x0c0c76a2u: goto P_0c0c76a2;
case 0x0c0c76a4u: goto P_0c0c76a4;
case 0x0c0c76a6u: goto P_0c0c76a6;
case 0x0c0c76a8u: goto P_0c0c76a8;
case 0x0c0c76aau: goto P_0c0c76aa;
case 0x0c0c76acu: goto P_0c0c76ac;
case 0x0c0c76aeu: goto P_0c0c76ae;
case 0x0c0c76b0u: goto P_0c0c76b0;
case 0x0c0c76b2u: goto P_0c0c76b2;
case 0x0c0c76b4u: goto P_0c0c76b4;
case 0x0c0c76b6u: goto P_0c0c76b6;
case 0x0c0c76b8u: goto P_0c0c76b8;
case 0x0c0c76bau: goto P_0c0c76ba;
case 0x0c0c76bcu: goto P_0c0c76bc;
case 0x0c0c76beu: goto P_0c0c76be;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b22c4: /* original 2fe6, guest PC 0x0c0b22c4 */
if(!s->budget--) { s->failed_pc=0x0c0b22c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22c6;
P_0c0b22c6: /* original e3ff, guest PC 0x0c0b22c6 */
if(!s->budget--) { s->failed_pc=0x0c0b22c6u; return 0; }
r[3]=0xffffffffu;
goto P_0c0b22c8;
P_0c0b22c8: /* original 2fd6, guest PC 0x0c0b22c8 */
if(!s->budget--) { s->failed_pc=0x0c0b22c8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22ca;
P_0c0b22ca: /* original 2fc6, guest PC 0x0c0b22ca */
if(!s->budget--) { s->failed_pc=0x0c0b22cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22cc;
P_0c0b22cc: /* original ec00, guest PC 0x0c0b22cc */
if(!s->budget--) { s->failed_pc=0x0c0b22ccu; return 0; }
r[12]=0x00000000u;
goto P_0c0b22ce;
P_0c0b22ce: /* original 2fb6, guest PC 0x0c0b22ce */
if(!s->budget--) { s->failed_pc=0x0c0b22ceu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22d0;
P_0c0b22d0: /* original 2fa6, guest PC 0x0c0b22d0 */
if(!s->budget--) { s->failed_pc=0x0c0b22d0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22d2;
P_0c0b22d2: /* original 6ac3, guest PC 0x0c0b22d2 */
if(!s->budget--) { s->failed_pc=0x0c0b22d2u; return 0; }
r[10]=r[12];
goto P_0c0b22d4;
P_0c0b22d4: /* original 2f96, guest PC 0x0c0b22d4 */
if(!s->budget--) { s->failed_pc=0x0c0b22d4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22d6;
P_0c0b22d6: /* original e91a, guest PC 0x0c0b22d6 */
if(!s->budget--) { s->failed_pc=0x0c0b22d6u; return 0; }
r[9]=0x0000001au;
goto P_0c0b22d8;
P_0c0b22d8: /* original 2f86, guest PC 0x0c0b22d8 */
if(!s->budget--) { s->failed_pc=0x0c0b22d8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22da;
P_0c0b22da: /* original de28, guest PC 0x0c0b22da */
if(!s->budget--) { s->failed_pc=0x0c0b22dau; return 0; }
r[14]=read(ram,0x0c0b237cu,4);
goto P_0c0b22dc;
P_0c0b22dc: /* original 9049, guest PC 0x0c0b22dc */
if(!s->budget--) { s->failed_pc=0x0c0b22dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2372u,2);
goto P_0c0b22de;
P_0c0b22de: /* original 4f22, guest PC 0x0c0b22de */
if(!s->budget--) { s->failed_pc=0x0c0b22deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b22e0;
P_0c0b22e0: /* original 0e36, guest PC 0x0c0b22e0 */
if(!s->budget--) { s->failed_pc=0x0c0b22e0u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0b22e2;
P_0c0b22e2: /* original 7008, guest PC 0x0c0b22e2 */
if(!s->budget--) { s->failed_pc=0x0c0b22e2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0b22e4;
P_0c0b22e4: /* original 0ec6, guest PC 0x0c0b22e4 */
if(!s->budget--) { s->failed_pc=0x0c0b22e4u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0b22e6;
P_0c0b22e6: /* original 70fc, guest PC 0x0c0b22e6 */
if(!s->budget--) { s->failed_pc=0x0c0b22e6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0b22e8;
P_0c0b22e8: /* original 0ec6, guest PC 0x0c0b22e8 */
if(!s->budget--) { s->failed_pc=0x0c0b22e8u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0b22ea;
P_0c0b22ea: /* original dd25, guest PC 0x0c0b22ea */
if(!s->budget--) { s->failed_pc=0x0c0b22eau; return 0; }
r[13]=read(ram,0x0c0b2380u,4);
goto P_0c0b22ec;
P_0c0b22ec: /* original 5bd3, guest PC 0x0c0b22ec */
if(!s->budget--) { s->failed_pc=0x0c0b22ecu; return 0; }
r[11]=read(ram,r[13]+12,4);
goto P_0c0b22ee;
P_0c0b22ee: /* original 4b0b, guest PC 0x0c0b22ee */
if(!s->budget--) { s->failed_pc=0x0c0b22eeu; return 0; }
target=r[11];
r[16]=code_base|0x0c0b22f2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b22f2u) { target=s->pc; goto dispatch; }
goto P_0c0b22f2;
P_0c0b22f0: /* original 0009, guest PC 0x0c0b22f0 */
if(!s->budget--) { s->failed_pc=0x0c0b22f0u; return 0; }
goto P_0c0b22f2;
P_0c0b22f2: /* original 5bd8, guest PC 0x0c0b22f2 */
if(!s->budget--) { s->failed_pc=0x0c0b22f2u; return 0; }
r[11]=read(ram,r[13]+32,4);
goto P_0c0b22f4;
P_0c0b22f4: /* original 2bb8, guest PC 0x0c0b22f4 */
if(!s->budget--) { s->failed_pc=0x0c0b22f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0b22f6;
P_0c0b22f6: /* original 8901, guest PC 0x0c0b22f6 */
if(!s->budget--) { s->failed_pc=0x0c0b22f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b22fc; }
goto P_0c0b22f8;
P_0c0b22f8: /* original 4b0b, guest PC 0x0c0b22f8 */
if(!s->budget--) { s->failed_pc=0x0c0b22f8u; return 0; }
target=r[11];
r[16]=code_base|0x0c0b22fcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b22fcu) { target=s->pc; goto dispatch; }
goto P_0c0b22fc;
P_0c0b22fa: /* original 0009, guest PC 0x0c0b22fa */
if(!s->budget--) { s->failed_pc=0x0c0b22fau; return 0; }
goto P_0c0b22fc;
P_0c0b22fc: /* original 7a01, guest PC 0x0c0b22fc */
if(!s->budget--) { s->failed_pc=0x0c0b22fcu; return 0; }
r[10]+=0x00000001u;
goto P_0c0b22fe;
P_0c0b22fe: /* original 3a93, guest PC 0x0c0b22fe */
if(!s->budget--) { s->failed_pc=0x0c0b22feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c0b2300;
P_0c0b2300: /* original 8ff4, guest PC 0x0c0b2300 */
if(!s->budget--) { s->failed_pc=0x0c0b2300u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000024u;
if(!cond) { goto P_0c0b22ec; }
goto P_0c0b2304;
P_0c0b2302: /* original 7d24, guest PC 0x0c0b2302 */
if(!s->budget--) { s->failed_pc=0x0c0b2302u; return 0; }
r[13]+=0x00000024u;
goto P_0c0b2304;
P_0c0b2304: /* original 9436, guest PC 0x0c0b2304 */
if(!s->budget--) { s->failed_pc=0x0c0b2304u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2374u,2);
goto P_0c0b2306;
P_0c0b2306: /* original 69c3, guest PC 0x0c0b2306 */
if(!s->budget--) { s->failed_pc=0x0c0b2306u; return 0; }
r[9]=r[12];
goto P_0c0b2308;
P_0c0b2308: /* original 6dc3, guest PC 0x0c0b2308 */
if(!s->budget--) { s->failed_pc=0x0c0b2308u; return 0; }
r[13]=r[12];
goto P_0c0b230a;
P_0c0b230a: /* original 34ec, guest PC 0x0c0b230a */
if(!s->budget--) { s->failed_pc=0x0c0b230au; return 0; }
r[4]+=r[14];
goto P_0c0b230c;
P_0c0b230c: /* original 6a43, guest PC 0x0c0b230c */
if(!s->budget--) { s->failed_pc=0x0c0b230cu; return 0; }
r[10]=r[4];
goto P_0c0b230e;
P_0c0b230e: /* original 6b43, guest PC 0x0c0b230e */
if(!s->budget--) { s->failed_pc=0x0c0b230eu; return 0; }
r[11]=r[4];
goto P_0c0b2310;
P_0c0b2310: /* original 9331, guest PC 0x0c0b2310 */
if(!s->budget--) { s->failed_pc=0x0c0b2310u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2376u,2);
goto P_0c0b2312;
P_0c0b2312: /* original 6893, guest PC 0x0c0b2312 */
if(!s->budget--) { s->failed_pc=0x0c0b2312u; return 0; }
r[8]=r[9];
goto P_0c0b2314;
P_0c0b2314: /* original 4808, guest PC 0x0c0b2314 */
if(!s->budget--) { s->failed_pc=0x0c0b2314u; return 0; }
r[8]<<=2;
goto P_0c0b2316;
P_0c0b2316: /* original 33ec, guest PC 0x0c0b2316 */
if(!s->budget--) { s->failed_pc=0x0c0b2316u; return 0; }
r[3]+=r[14];
goto P_0c0b2318;
P_0c0b2318: /* original 338c, guest PC 0x0c0b2318 */
if(!s->budget--) { s->failed_pc=0x0c0b2318u; return 0; }
r[3]+=r[8];
goto P_0c0b231a;
P_0c0b231a: /* original 6232, guest PC 0x0c0b231a */
if(!s->budget--) { s->failed_pc=0x0c0b231au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0b231c;
P_0c0b231c: /* original 2228, guest PC 0x0c0b231c */
if(!s->budget--) { s->failed_pc=0x0c0b231cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b231e;
P_0c0b231e: /* original 8905, guest PC 0x0c0b231e */
if(!s->budget--) { s->failed_pc=0x0c0b231eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b232c; }
goto P_0c0b2320;
P_0c0b2320: /* original 9429, guest PC 0x0c0b2320 */
if(!s->budget--) { s->failed_pc=0x0c0b2320u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2376u,2);
goto P_0c0b2322;
P_0c0b2322: /* original d318, guest PC 0x0c0b2322 */
if(!s->budget--) { s->failed_pc=0x0c0b2322u; return 0; }
r[3]=read(ram,0x0c0b2384u,4);
goto P_0c0b2324;
P_0c0b2324: /* original 34ec, guest PC 0x0c0b2324 */
if(!s->budget--) { s->failed_pc=0x0c0b2324u; return 0; }
r[4]+=r[14];
goto P_0c0b2326;
P_0c0b2326: /* original 348c, guest PC 0x0c0b2326 */
if(!s->budget--) { s->failed_pc=0x0c0b2326u; return 0; }
r[4]+=r[8];
goto P_0c0b2328;
P_0c0b2328: /* original 430b, guest PC 0x0c0b2328 */
if(!s->budget--) { s->failed_pc=0x0c0b2328u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b232cu;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b232cu) { target=s->pc; goto dispatch; }
goto P_0c0b232c;
P_0c0b232a: /* original 6442, guest PC 0x0c0b232a */
if(!s->budget--) { s->failed_pc=0x0c0b232au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0b232c;
P_0c0b232c: /* original 62b2, guest PC 0x0c0b232c */
if(!s->budget--) { s->failed_pc=0x0c0b232cu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0b232e;
P_0c0b232e: /* original 2228, guest PC 0x0c0b232e */
if(!s->budget--) { s->failed_pc=0x0c0b232eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b2330;
P_0c0b2330: /* original 8902, guest PC 0x0c0b2330 */
if(!s->budget--) { s->failed_pc=0x0c0b2330u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b2338; }
goto P_0c0b2332;
P_0c0b2332: /* original d314, guest PC 0x0c0b2332 */
if(!s->budget--) { s->failed_pc=0x0c0b2332u; return 0; }
r[3]=read(ram,0x0c0b2384u,4);
goto P_0c0b2334;
P_0c0b2334: /* original 430b, guest PC 0x0c0b2334 */
if(!s->budget--) { s->failed_pc=0x0c0b2334u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b2338u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2338u) { target=s->pc; goto dispatch; }
goto P_0c0b2338;
P_0c0b2336: /* original 64a2, guest PC 0x0c0b2336 */
if(!s->budget--) { s->failed_pc=0x0c0b2336u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0b2338;
P_0c0b2338: /* original 921d, guest PC 0x0c0b2338 */
if(!s->budget--) { s->failed_pc=0x0c0b2338u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2376u,2);
goto P_0c0b233a;
P_0c0b233a: /* original 7901, guest PC 0x0c0b233a */
if(!s->budget--) { s->failed_pc=0x0c0b233au; return 0; }
r[9]+=0x00000001u;
goto P_0c0b233c;
P_0c0b233c: /* original 931a, guest PC 0x0c0b233c */
if(!s->budget--) { s->failed_pc=0x0c0b233cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2374u,2);
goto P_0c0b233e;
P_0c0b233e: /* original 7a04, guest PC 0x0c0b233e */
if(!s->budget--) { s->failed_pc=0x0c0b233eu; return 0; }
r[10]+=0x00000004u;
goto P_0c0b2340;
P_0c0b2340: /* original 32ec, guest PC 0x0c0b2340 */
if(!s->budget--) { s->failed_pc=0x0c0b2340u; return 0; }
r[2]+=r[14];
goto P_0c0b2342;
P_0c0b2342: /* original 32dc, guest PC 0x0c0b2342 */
if(!s->budget--) { s->failed_pc=0x0c0b2342u; return 0; }
r[2]+=r[13];
goto P_0c0b2344;
P_0c0b2344: /* original 33ec, guest PC 0x0c0b2344 */
if(!s->budget--) { s->failed_pc=0x0c0b2344u; return 0; }
r[3]+=r[14];
goto P_0c0b2346;
P_0c0b2346: /* original 33dc, guest PC 0x0c0b2346 */
if(!s->budget--) { s->failed_pc=0x0c0b2346u; return 0; }
r[3]+=r[13];
goto P_0c0b2348;
P_0c0b2348: /* original 23c2, guest PC 0x0c0b2348 */
if(!s->budget--) { s->failed_pc=0x0c0b2348u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c0b234a;
P_0c0b234a: /* original e3ff, guest PC 0x0c0b234a */
if(!s->budget--) { s->failed_pc=0x0c0b234au; return 0; }
r[3]=0xffffffffu;
goto P_0c0b234c;
P_0c0b234c: /* original 22c2, guest PC 0x0c0b234c */
if(!s->budget--) { s->failed_pc=0x0c0b234cu; return 0; }
write(ram,r[2],r[12],4);
goto P_0c0b234e;
P_0c0b234e: /* original 9213, guest PC 0x0c0b234e */
if(!s->budget--) { s->failed_pc=0x0c0b234eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2378u,2);
goto P_0c0b2350;
P_0c0b2350: /* original 32ec, guest PC 0x0c0b2350 */
if(!s->budget--) { s->failed_pc=0x0c0b2350u; return 0; }
r[2]+=r[14];
goto P_0c0b2352;
P_0c0b2352: /* original 32dc, guest PC 0x0c0b2352 */
if(!s->budget--) { s->failed_pc=0x0c0b2352u; return 0; }
r[2]+=r[13];
goto P_0c0b2354;
P_0c0b2354: /* original 2232, guest PC 0x0c0b2354 */
if(!s->budget--) { s->failed_pc=0x0c0b2354u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0b2356;
P_0c0b2356: /* original e202, guest PC 0x0c0b2356 */
if(!s->budget--) { s->failed_pc=0x0c0b2356u; return 0; }
r[2]=0x00000002u;
goto P_0c0b2358;
P_0c0b2358: /* original 3923, guest PC 0x0c0b2358 */
if(!s->budget--) { s->failed_pc=0x0c0b2358u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[2])!=0);
goto P_0c0b235a;
P_0c0b235a: /* original 7d04, guest PC 0x0c0b235a */
if(!s->budget--) { s->failed_pc=0x0c0b235au; return 0; }
r[13]+=0x00000004u;
goto P_0c0b235c;
P_0c0b235c: /* original 8fd8, guest PC 0x0c0b235c */
if(!s->budget--) { s->failed_pc=0x0c0b235cu; return 0; }
cond=r[17]&1u;
r[11]+=0x00000004u;
if(!cond) { goto P_0c0b2310; }
goto P_0c0b2360;
P_0c0b235e: /* original 7b04, guest PC 0x0c0b235e */
if(!s->budget--) { s->failed_pc=0x0c0b235eu; return 0; }
r[11]+=0x00000004u;
goto P_0c0b2360;
P_0c0b2360: /* original 4f26, guest PC 0x0c0b2360 */
if(!s->budget--) { s->failed_pc=0x0c0b2360u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b2362;
P_0c0b2362: /* original 68f6, guest PC 0x0c0b2362 */
if(!s->budget--) { s->failed_pc=0x0c0b2362u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0b2364;
P_0c0b2364: /* original 69f6, guest PC 0x0c0b2364 */
if(!s->budget--) { s->failed_pc=0x0c0b2364u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b2366;
P_0c0b2366: /* original 6af6, guest PC 0x0c0b2366 */
if(!s->budget--) { s->failed_pc=0x0c0b2366u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b2368;
P_0c0b2368: /* original 6bf6, guest PC 0x0c0b2368 */
if(!s->budget--) { s->failed_pc=0x0c0b2368u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b236a;
P_0c0b236a: /* original 6cf6, guest PC 0x0c0b236a */
if(!s->budget--) { s->failed_pc=0x0c0b236au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b236c;
P_0c0b236c: /* original 6df6, guest PC 0x0c0b236c */
if(!s->budget--) { s->failed_pc=0x0c0b236cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b236e;
P_0c0b236e: /* original 000b, guest PC 0x0c0b236e */
if(!s->budget--) { s->failed_pc=0x0c0b236eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b2370: /* original 6ef6, guest PC 0x0c0b2370 */
if(!s->budget--) { s->failed_pc=0x0c0b2370u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b2372u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b2372u; return 0; } return 1;
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
if(!vf3_matrix_family(0x0c0c5d86u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5d86u; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c66d0: /* original 000b, guest PC 0x0c0c66d0 */
if(!s->budget--) { s->failed_pc=0x0c0c66d0u; return 0; }
target=r[16];
write(ram,r[4],r[5],1);
s->pc=target; return ram->oob==0;
P_0c0c66d2: /* original 2450, guest PC 0x0c0c66d2 */
if(!s->budget--) { s->failed_pc=0x0c0c66d2u; return 0; }
write(ram,r[4],r[5],1);
if(!vf3_matrix_family(0x0c0c66d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66d4u; return 0; } return 1;
P_0c0c761e: /* original 4f22, guest PC 0x0c0c761e */
if(!s->budget--) { s->failed_pc=0x0c0c761eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7620;
P_0c0c7620: /* original b012, guest PC 0x0c0c7620 */
if(!s->budget--) { s->failed_pc=0x0c0c7620u; return 0; }
target=code_base|0x0c0c7648u; r[16]=code_base|0x0c0c7624u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7624u) { target=s->pc; goto dispatch; }
goto P_0c0c7624;
P_0c0c7622: /* original 0009, guest PC 0x0c0c7622 */
if(!s->budget--) { s->failed_pc=0x0c0c7622u; return 0; }
goto P_0c0c7624;
P_0c0c7624: /* original 4f26, guest PC 0x0c0c7624 */
if(!s->budget--) { s->failed_pc=0x0c0c7624u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7626;
P_0c0c7626: /* original d307, guest PC 0x0c0c7626 */
if(!s->budget--) { s->failed_pc=0x0c0c7626u; return 0; }
r[3]=read(ram,0x0c0c7644u,4);
goto P_0c0c7628;
P_0c0c7628: /* original e2ff, guest PC 0x0c0c7628 */
if(!s->budget--) { s->failed_pc=0x0c0c7628u; return 0; }
r[2]=0xffffffffu;
goto P_0c0c762a;
P_0c0c762a: /* original 000b, guest PC 0x0c0c762a */
if(!s->budget--) { s->failed_pc=0x0c0c762au; return 0; }
target=r[16];
write(ram,r[3],r[2],4);
s->pc=target; return ram->oob==0;
P_0c0c762c: /* original 2322, guest PC 0x0c0c762c */
if(!s->budget--) { s->failed_pc=0x0c0c762cu; return 0; }
write(ram,r[3],r[2],4);
if(!vf3_matrix_family(0x0c0c762eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c762eu; return 0; } return 1;
P_0c0c7648: /* original 2fe6, guest PC 0x0c0c7648 */
if(!s->budget--) { s->failed_pc=0x0c0c7648u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764a;
P_0c0c764a: /* original 2fd6, guest PC 0x0c0c764a */
if(!s->budget--) { s->failed_pc=0x0c0c764au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764c;
P_0c0c764c: /* original 2fc6, guest PC 0x0c0c764c */
if(!s->budget--) { s->failed_pc=0x0c0c764cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764e;
P_0c0c764e: /* original 2fb6, guest PC 0x0c0c764e */
if(!s->budget--) { s->failed_pc=0x0c0c764eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7650;
P_0c0c7650: /* original 2fa6, guest PC 0x0c0c7650 */
if(!s->budget--) { s->failed_pc=0x0c0c7650u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7652;
P_0c0c7652: /* original 2f96, guest PC 0x0c0c7652 */
if(!s->budget--) { s->failed_pc=0x0c0c7652u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7654;
P_0c0c7654: /* original da40, guest PC 0x0c0c7654 */
if(!s->budget--) { s->failed_pc=0x0c0c7654u; return 0; }
r[10]=read(ram,0x0c0c7758u,4);
goto P_0c0c7656;
P_0c0c7656: /* original 9077, guest PC 0x0c0c7656 */
if(!s->budget--) { s->failed_pc=0x0c0c7656u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7748u,2);
goto P_0c0c7658;
P_0c0c7658: /* original 4f22, guest PC 0x0c0c7658 */
if(!s->budget--) { s->failed_pc=0x0c0c7658u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c765a;
P_0c0c765a: /* original 0cae, guest PC 0x0c0c765a */
if(!s->budget--) { s->failed_pc=0x0c0c765au; return 0; }
r[12]=read(ram,r[10]+r[0],4);
goto P_0c0c765c;
P_0c0c765c: /* original 7004, guest PC 0x0c0c765c */
if(!s->budget--) { s->failed_pc=0x0c0c765cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c765e;
P_0c0c765e: /* original dd3f, guest PC 0x0c0c765e */
if(!s->budget--) { s->failed_pc=0x0c0c765eu; return 0; }
r[13]=read(ram,0x0c0c775cu,4);
goto P_0c0c7660;
P_0c0c7660: /* original 2cc8, guest PC 0x0c0c7660 */
if(!s->budget--) { s->failed_pc=0x0c0c7660u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c7662;
P_0c0c7662: /* original 8d0e, guest PC 0x0c0c7662 */
if(!s->budget--) { s->failed_pc=0x0c0c7662u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c0c7682; }
goto P_0c0c7666;
P_0c0c7664: /* original 0bae, guest PC 0x0c0c7664 */
if(!s->budget--) { s->failed_pc=0x0c0c7664u; return 0; }
r[11]=read(ram,r[10]+r[0],4);
goto P_0c0c7666;
P_0c0c7666: /* original 85c6, guest PC 0x0c0c7666 */
if(!s->budget--) { s->failed_pc=0x0c0c7666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7668;
P_0c0c7668: /* original 996f, guest PC 0x0c0c7668 */
if(!s->budget--) { s->failed_pc=0x0c0c7668u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774au,2);
goto P_0c0c766a;
P_0c0c766a: /* original 6e0d, guest PC 0x0c0c766a */
if(!s->budget--) { s->failed_pc=0x0c0c766au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c766c;
P_0c0c766c: /* original 4e15, guest PC 0x0c0c766c */
if(!s->budget--) { s->failed_pc=0x0c0c766cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c766e;
P_0c0c766e: /* original 8b05, guest PC 0x0c0c766e */
if(!s->budget--) { s->failed_pc=0x0c0c766eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c767c; }
goto P_0c0c7670;
P_0c0c7670: /* original 6493, guest PC 0x0c0c7670 */
if(!s->budget--) { s->failed_pc=0x0c0c7670u; return 0; }
r[4]=r[9];
goto P_0c0c7672;
P_0c0c7672: /* original 4d0b, guest PC 0x0c0c7672 */
if(!s->budget--) { s->failed_pc=0x0c0c7672u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7676u;
r[9]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7676u) { target=s->pc; goto dispatch; }
goto P_0c0c7676;
P_0c0c7674: /* original 7901, guest PC 0x0c0c7674 */
if(!s->budget--) { s->failed_pc=0x0c0c7674u; return 0; }
r[9]+=0x00000001u;
goto P_0c0c7676;
P_0c0c7676: /* original 7eff, guest PC 0x0c0c7676 */
if(!s->budget--) { s->failed_pc=0x0c0c7676u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7678;
P_0c0c7678: /* original 4e15, guest PC 0x0c0c7678 */
if(!s->budget--) { s->failed_pc=0x0c0c7678u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c767a;
P_0c0c767a: /* original 89f9, guest PC 0x0c0c767a */
if(!s->budget--) { s->failed_pc=0x0c0c767au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7670; }
goto P_0c0c767c;
P_0c0c767c: /* original d338, guest PC 0x0c0c767c */
if(!s->budget--) { s->failed_pc=0x0c0c767cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c767e;
P_0c0c767e: /* original 430b, guest PC 0x0c0c767e */
if(!s->budget--) { s->failed_pc=0x0c0c767eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7682u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7682u) { target=s->pc; goto dispatch; }
goto P_0c0c7682;
P_0c0c7680: /* original 64c3, guest PC 0x0c0c7680 */
if(!s->budget--) { s->failed_pc=0x0c0c7680u; return 0; }
r[4]=r[12];
goto P_0c0c7682;
P_0c0c7682: /* original 2bb8, guest PC 0x0c0c7682 */
if(!s->budget--) { s->failed_pc=0x0c0c7682u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c7684;
P_0c0c7684: /* original 890d, guest PC 0x0c0c7684 */
if(!s->budget--) { s->failed_pc=0x0c0c7684u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c76a2; }
goto P_0c0c7686;
P_0c0c7686: /* original 85b6, guest PC 0x0c0c7686 */
if(!s->budget--) { s->failed_pc=0x0c0c7686u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+12,2);
goto P_0c0c7688;
P_0c0c7688: /* original 9c60, guest PC 0x0c0c7688 */
if(!s->budget--) { s->failed_pc=0x0c0c7688u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774cu,2);
goto P_0c0c768a;
P_0c0c768a: /* original 6e0d, guest PC 0x0c0c768a */
if(!s->budget--) { s->failed_pc=0x0c0c768au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c768c;
P_0c0c768c: /* original 4e15, guest PC 0x0c0c768c */
if(!s->budget--) { s->failed_pc=0x0c0c768cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c768e;
P_0c0c768e: /* original 8b05, guest PC 0x0c0c768e */
if(!s->budget--) { s->failed_pc=0x0c0c768eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c769c; }
goto P_0c0c7690;
P_0c0c7690: /* original 64c3, guest PC 0x0c0c7690 */
if(!s->budget--) { s->failed_pc=0x0c0c7690u; return 0; }
r[4]=r[12];
goto P_0c0c7692;
P_0c0c7692: /* original 4d0b, guest PC 0x0c0c7692 */
if(!s->budget--) { s->failed_pc=0x0c0c7692u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7696u;
r[12]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7696u) { target=s->pc; goto dispatch; }
goto P_0c0c7696;
P_0c0c7694: /* original 7c01, guest PC 0x0c0c7694 */
if(!s->budget--) { s->failed_pc=0x0c0c7694u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c7696;
P_0c0c7696: /* original 7eff, guest PC 0x0c0c7696 */
if(!s->budget--) { s->failed_pc=0x0c0c7696u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7698;
P_0c0c7698: /* original 4e15, guest PC 0x0c0c7698 */
if(!s->budget--) { s->failed_pc=0x0c0c7698u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c769a;
P_0c0c769a: /* original 89f9, guest PC 0x0c0c769a */
if(!s->budget--) { s->failed_pc=0x0c0c769au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7690; }
goto P_0c0c769c;
P_0c0c769c: /* original d330, guest PC 0x0c0c769c */
if(!s->budget--) { s->failed_pc=0x0c0c769cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c769e;
P_0c0c769e: /* original 430b, guest PC 0x0c0c769e */
if(!s->budget--) { s->failed_pc=0x0c0c769eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c76a2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c76a2u) { target=s->pc; goto dispatch; }
goto P_0c0c76a2;
P_0c0c76a0: /* original 64b3, guest PC 0x0c0c76a0 */
if(!s->budget--) { s->failed_pc=0x0c0c76a0u; return 0; }
r[4]=r[11];
goto P_0c0c76a2;
P_0c0c76a2: /* original 9054, guest PC 0x0c0c76a2 */
if(!s->budget--) { s->failed_pc=0x0c0c76a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774eu,2);
goto P_0c0c76a4;
P_0c0c76a4: /* original e400, guest PC 0x0c0c76a4 */
if(!s->budget--) { s->failed_pc=0x0c0c76a4u; return 0; }
r[4]=0x00000000u;
goto P_0c0c76a6;
P_0c0c76a6: /* original 4f26, guest PC 0x0c0c76a6 */
if(!s->budget--) { s->failed_pc=0x0c0c76a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c76a8;
P_0c0c76a8: /* original 0a46, guest PC 0x0c0c76a8 */
if(!s->budget--) { s->failed_pc=0x0c0c76a8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76aa;
P_0c0c76aa: /* original 70f8, guest PC 0x0c0c76aa */
if(!s->budget--) { s->failed_pc=0x0c0c76aau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c76ac;
P_0c0c76ac: /* original 0a46, guest PC 0x0c0c76ac */
if(!s->budget--) { s->failed_pc=0x0c0c76acu; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76ae;
P_0c0c76ae: /* original 7004, guest PC 0x0c0c76ae */
if(!s->budget--) { s->failed_pc=0x0c0c76aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c76b0;
P_0c0c76b0: /* original 0a46, guest PC 0x0c0c76b0 */
if(!s->budget--) { s->failed_pc=0x0c0c76b0u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76b2;
P_0c0c76b2: /* original 69f6, guest PC 0x0c0c76b2 */
if(!s->budget--) { s->failed_pc=0x0c0c76b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c76b4;
P_0c0c76b4: /* original 6af6, guest PC 0x0c0c76b4 */
if(!s->budget--) { s->failed_pc=0x0c0c76b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c76b6;
P_0c0c76b6: /* original 6bf6, guest PC 0x0c0c76b6 */
if(!s->budget--) { s->failed_pc=0x0c0c76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c76b8;
P_0c0c76b8: /* original 6cf6, guest PC 0x0c0c76b8 */
if(!s->budget--) { s->failed_pc=0x0c0c76b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c76ba;
P_0c0c76ba: /* original 6df6, guest PC 0x0c0c76ba */
if(!s->budget--) { s->failed_pc=0x0c0c76bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c76bc;
P_0c0c76bc: /* original 000b, guest PC 0x0c0c76bc */
if(!s->budget--) { s->failed_pc=0x0c0c76bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c76be: /* original 6ef6, guest PC 0x0c0c76be */
if(!s->budget--) { s->failed_pc=0x0c0c76beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c76c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c76c0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
