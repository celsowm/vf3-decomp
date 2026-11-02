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
int vf3_away_batch242_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b71cu: goto P_0c07b71c;
case 0x0c07b71eu: goto P_0c07b71e;
case 0x0c0c124eu: goto P_0c0c124e;
case 0x0c0c1250u: goto P_0c0c1250;
case 0x0c0c1252u: goto P_0c0c1252;
case 0x0c0c1254u: goto P_0c0c1254;
case 0x0c0c1256u: goto P_0c0c1256;
case 0x0c0c1258u: goto P_0c0c1258;
case 0x0c0c125au: goto P_0c0c125a;
case 0x0c0c125cu: goto P_0c0c125c;
case 0x0c0c125eu: goto P_0c0c125e;
case 0x0c0c1260u: goto P_0c0c1260;
case 0x0c0c1262u: goto P_0c0c1262;
case 0x0c0c1264u: goto P_0c0c1264;
case 0x0c0c1266u: goto P_0c0c1266;
case 0x0c0c1268u: goto P_0c0c1268;
case 0x0c0c126au: goto P_0c0c126a;
case 0x0c0c126cu: goto P_0c0c126c;
case 0x0c0c126eu: goto P_0c0c126e;
case 0x0c0c1270u: goto P_0c0c1270;
case 0x0c0c1272u: goto P_0c0c1272;
case 0x0c0c1274u: goto P_0c0c1274;
case 0x0c0c1276u: goto P_0c0c1276;
case 0x0c0c1278u: goto P_0c0c1278;
case 0x0c0c127au: goto P_0c0c127a;
case 0x0c0c127cu: goto P_0c0c127c;
case 0x0c0c127eu: goto P_0c0c127e;
case 0x0c0c1280u: goto P_0c0c1280;
case 0x0c0c1282u: goto P_0c0c1282;
case 0x0c0c1284u: goto P_0c0c1284;
case 0x0c0c1286u: goto P_0c0c1286;
case 0x0c0c1288u: goto P_0c0c1288;
case 0x0c0c128au: goto P_0c0c128a;
case 0x0c0c128cu: goto P_0c0c128c;
case 0x0c0c128eu: goto P_0c0c128e;
case 0x0c0c1290u: goto P_0c0c1290;
case 0x0c0c1292u: goto P_0c0c1292;
case 0x0c0c1294u: goto P_0c0c1294;
case 0x0c0c1296u: goto P_0c0c1296;
case 0x0c0c1298u: goto P_0c0c1298;
case 0x0c0c129au: goto P_0c0c129a;
case 0x0c0c129cu: goto P_0c0c129c;
case 0x0c0c129eu: goto P_0c0c129e;
case 0x0c0c12a0u: goto P_0c0c12a0;
case 0x0c0c12a2u: goto P_0c0c12a2;
case 0x0c0c12a4u: goto P_0c0c12a4;
case 0x0c0c12a6u: goto P_0c0c12a6;
case 0x0c0c12a8u: goto P_0c0c12a8;
case 0x0c0c12aau: goto P_0c0c12aa;
case 0x0c0c12acu: goto P_0c0c12ac;
case 0x0c0c12aeu: goto P_0c0c12ae;
case 0x0c0c12b0u: goto P_0c0c12b0;
case 0x0c0c12b2u: goto P_0c0c12b2;
case 0x0c0c12b4u: goto P_0c0c12b4;
case 0x0c0c12b6u: goto P_0c0c12b6;
case 0x0c0c12b8u: goto P_0c0c12b8;
case 0x0c0c12bau: goto P_0c0c12ba;
case 0x0c0c12bcu: goto P_0c0c12bc;
case 0x0c0c12beu: goto P_0c0c12be;
case 0x0c0c12c0u: goto P_0c0c12c0;
case 0x0c0c12c2u: goto P_0c0c12c2;
case 0x0c0c12c4u: goto P_0c0c12c4;
case 0x0c0c12c6u: goto P_0c0c12c6;
case 0x0c0c12c8u: goto P_0c0c12c8;
case 0x0c0c12cau: goto P_0c0c12ca;
case 0x0c0c12ccu: goto P_0c0c12cc;
case 0x0c0c12ceu: goto P_0c0c12ce;
case 0x0c0c12d0u: goto P_0c0c12d0;
case 0x0c0c12d2u: goto P_0c0c12d2;
case 0x0c0c12d4u: goto P_0c0c12d4;
case 0x0c0c12d6u: goto P_0c0c12d6;
case 0x0c0c285cu: goto P_0c0c285c;
case 0x0c0c285eu: goto P_0c0c285e;
case 0x0c0c2860u: goto P_0c0c2860;
case 0x0c0c2862u: goto P_0c0c2862;
case 0x0c0c2864u: goto P_0c0c2864;
case 0x0c0c2866u: goto P_0c0c2866;
case 0x0c0c2868u: goto P_0c0c2868;
case 0x0c0c286au: goto P_0c0c286a;
case 0x0c0c286cu: goto P_0c0c286c;
case 0x0c0c286eu: goto P_0c0c286e;
case 0x0c0c2870u: goto P_0c0c2870;
case 0x0c0c2872u: goto P_0c0c2872;
case 0x0c0c2874u: goto P_0c0c2874;
case 0x0c0c2876u: goto P_0c0c2876;
case 0x0c0c2878u: goto P_0c0c2878;
case 0x0c0c287au: goto P_0c0c287a;
case 0x0c0c287cu: goto P_0c0c287c;
case 0x0c0c287eu: goto P_0c0c287e;
case 0x0c0c2880u: goto P_0c0c2880;
case 0x0c0c2882u: goto P_0c0c2882;
case 0x0c0c2884u: goto P_0c0c2884;
case 0x0c0c2886u: goto P_0c0c2886;
case 0x0c0c2888u: goto P_0c0c2888;
case 0x0c0c288au: goto P_0c0c288a;
case 0x0c0c288cu: goto P_0c0c288c;
case 0x0c0c288eu: goto P_0c0c288e;
case 0x0c0c2890u: goto P_0c0c2890;
case 0x0c0c2892u: goto P_0c0c2892;
case 0x0c0c2894u: goto P_0c0c2894;
case 0x0c0c2896u: goto P_0c0c2896;
case 0x0c0c2898u: goto P_0c0c2898;
case 0x0c0c289au: goto P_0c0c289a;
case 0x0c0c289cu: goto P_0c0c289c;
case 0x0c0c289eu: goto P_0c0c289e;
case 0x0c0c28a0u: goto P_0c0c28a0;
case 0x0c0c28a2u: goto P_0c0c28a2;
case 0x0c0c28a4u: goto P_0c0c28a4;
case 0x0c0c28a6u: goto P_0c0c28a6;
case 0x0c0c28a8u: goto P_0c0c28a8;
case 0x0c0c28aau: goto P_0c0c28aa;
case 0x0c0c28acu: goto P_0c0c28ac;
case 0x0c0c28aeu: goto P_0c0c28ae;
case 0x0c0c28b0u: goto P_0c0c28b0;
case 0x0c0c28b2u: goto P_0c0c28b2;
case 0x0c0c28b4u: goto P_0c0c28b4;
case 0x0c0c28b6u: goto P_0c0c28b6;
case 0x0c0c28b8u: goto P_0c0c28b8;
case 0x0c0c28bau: goto P_0c0c28ba;
case 0x0c0c28bcu: goto P_0c0c28bc;
case 0x0c0c28beu: goto P_0c0c28be;
case 0x0c0c28c0u: goto P_0c0c28c0;
case 0x0c0c28c2u: goto P_0c0c28c2;
case 0x0c0c28c4u: goto P_0c0c28c4;
case 0x0c0c28c6u: goto P_0c0c28c6;
case 0x0c0c28c8u: goto P_0c0c28c8;
case 0x0c0c28cau: goto P_0c0c28ca;
case 0x0c0c28ccu: goto P_0c0c28cc;
case 0x0c0c28ceu: goto P_0c0c28ce;
case 0x0c0c28d0u: goto P_0c0c28d0;
case 0x0c0c28d2u: goto P_0c0c28d2;
case 0x0c0c28d4u: goto P_0c0c28d4;
case 0x0c0c28d6u: goto P_0c0c28d6;
case 0x0c0c28d8u: goto P_0c0c28d8;
case 0x0c0c28dau: goto P_0c0c28da;
case 0x0c0c28dcu: goto P_0c0c28dc;
case 0x0c0c28deu: goto P_0c0c28de;
case 0x0c0c28e0u: goto P_0c0c28e0;
case 0x0c0c28e2u: goto P_0c0c28e2;
case 0x0c0c28e4u: goto P_0c0c28e4;
case 0x0c0c28e6u: goto P_0c0c28e6;
case 0x0c0c28e8u: goto P_0c0c28e8;
case 0x0c0c28eau: goto P_0c0c28ea;
case 0x0c0c28ecu: goto P_0c0c28ec;
case 0x0c0c28eeu: goto P_0c0c28ee;
case 0x0c0c28f0u: goto P_0c0c28f0;
case 0x0c0c28f2u: goto P_0c0c28f2;
case 0x0c0c28f4u: goto P_0c0c28f4;
case 0x0c0c28f6u: goto P_0c0c28f6;
case 0x0c0c28f8u: goto P_0c0c28f8;
case 0x0c0c28fau: goto P_0c0c28fa;
case 0x0c0c28fcu: goto P_0c0c28fc;
case 0x0c0c28feu: goto P_0c0c28fe;
case 0x0c0c2900u: goto P_0c0c2900;
case 0x0c0c2902u: goto P_0c0c2902;
case 0x0c0c2904u: goto P_0c0c2904;
case 0x0c0c2906u: goto P_0c0c2906;
case 0x0c0c2908u: goto P_0c0c2908;
case 0x0c0c290au: goto P_0c0c290a;
case 0x0c0c290cu: goto P_0c0c290c;
case 0x0c0c290eu: goto P_0c0c290e;
case 0x0c0c2910u: goto P_0c0c2910;
case 0x0c0c2912u: goto P_0c0c2912;
case 0x0c0c2914u: goto P_0c0c2914;
case 0x0c0c2916u: goto P_0c0c2916;
case 0x0c0c2918u: goto P_0c0c2918;
case 0x0c0c291au: goto P_0c0c291a;
case 0x0c0c291cu: goto P_0c0c291c;
case 0x0c0c291eu: goto P_0c0c291e;
case 0x0c0c2920u: goto P_0c0c2920;
case 0x0c0c2922u: goto P_0c0c2922;
case 0x0c0c2924u: goto P_0c0c2924;
case 0x0c0c2926u: goto P_0c0c2926;
case 0x0c0c2928u: goto P_0c0c2928;
case 0x0c0c292au: goto P_0c0c292a;
case 0x0c0c292cu: goto P_0c0c292c;
case 0x0c0c292eu: goto P_0c0c292e;
case 0x0c0c2930u: goto P_0c0c2930;
case 0x0c0c2932u: goto P_0c0c2932;
case 0x0c0c2934u: goto P_0c0c2934;
case 0x0c0c2936u: goto P_0c0c2936;
case 0x0c0c2938u: goto P_0c0c2938;
case 0x0c0c293au: goto P_0c0c293a;
case 0x0c0c293cu: goto P_0c0c293c;
case 0x0c0c293eu: goto P_0c0c293e;
case 0x0c0c2940u: goto P_0c0c2940;
case 0x0c0c2942u: goto P_0c0c2942;
case 0x0c0c2944u: goto P_0c0c2944;
case 0x0c0c2946u: goto P_0c0c2946;
case 0x0c0c2948u: goto P_0c0c2948;
case 0x0c0c294au: goto P_0c0c294a;
case 0x0c0c294cu: goto P_0c0c294c;
case 0x0c0c294eu: goto P_0c0c294e;
case 0x0c0c2950u: goto P_0c0c2950;
case 0x0c0c2952u: goto P_0c0c2952;
case 0x0c0c2954u: goto P_0c0c2954;
case 0x0c0c2d06u: goto P_0c0c2d06;
case 0x0c0c2d08u: goto P_0c0c2d08;
case 0x0c0c2d0au: goto P_0c0c2d0a;
case 0x0c0c2d0cu: goto P_0c0c2d0c;
case 0x0c0c2d0eu: goto P_0c0c2d0e;
case 0x0c0c2d10u: goto P_0c0c2d10;
case 0x0c0c2d12u: goto P_0c0c2d12;
case 0x0c0c2d14u: goto P_0c0c2d14;
case 0x0c0c2d16u: goto P_0c0c2d16;
case 0x0c0c2d18u: goto P_0c0c2d18;
case 0x0c0c2d1au: goto P_0c0c2d1a;
case 0x0c0c2d1cu: goto P_0c0c2d1c;
case 0x0c0c2d1eu: goto P_0c0c2d1e;
case 0x0c0c2d20u: goto P_0c0c2d20;
case 0x0c0c2d22u: goto P_0c0c2d22;
case 0x0c0c2d24u: goto P_0c0c2d24;
case 0x0c0c2d26u: goto P_0c0c2d26;
case 0x0c0c2d28u: goto P_0c0c2d28;
case 0x0c0c2d2au: goto P_0c0c2d2a;
case 0x0c0c2d2cu: goto P_0c0c2d2c;
case 0x0c0c2d2eu: goto P_0c0c2d2e;
case 0x0c0c2d30u: goto P_0c0c2d30;
case 0x0c0c2d32u: goto P_0c0c2d32;
case 0x0c0c2d34u: goto P_0c0c2d34;
case 0x0c0c2d36u: goto P_0c0c2d36;
case 0x0c0c2d38u: goto P_0c0c2d38;
case 0x0c0c2d3au: goto P_0c0c2d3a;
case 0x0c0c2d3cu: goto P_0c0c2d3c;
case 0x0c0c2d3eu: goto P_0c0c2d3e;
case 0x0c0c2d40u: goto P_0c0c2d40;
case 0x0c0c2d42u: goto P_0c0c2d42;
case 0x0c0c2d44u: goto P_0c0c2d44;
case 0x0c0c2d46u: goto P_0c0c2d46;
case 0x0c0c2d48u: goto P_0c0c2d48;
case 0x0c0c2d4au: goto P_0c0c2d4a;
case 0x0c0c2d4cu: goto P_0c0c2d4c;
case 0x0c0c2d4eu: goto P_0c0c2d4e;
case 0x0c0c2d50u: goto P_0c0c2d50;
case 0x0c0c2d52u: goto P_0c0c2d52;
case 0x0c0c2d54u: goto P_0c0c2d54;
case 0x0c0c2d56u: goto P_0c0c2d56;
case 0x0c0c2d58u: goto P_0c0c2d58;
case 0x0c0c2d5au: goto P_0c0c2d5a;
case 0x0c0c2d5cu: goto P_0c0c2d5c;
case 0x0c0c2d5eu: goto P_0c0c2d5e;
case 0x0c0c2d60u: goto P_0c0c2d60;
case 0x0c0c2d62u: goto P_0c0c2d62;
case 0x0c0c2d64u: goto P_0c0c2d64;
case 0x0c0c2d66u: goto P_0c0c2d66;
case 0x0c0c2d68u: goto P_0c0c2d68;
case 0x0c0c2d6au: goto P_0c0c2d6a;
case 0x0c0c2d6cu: goto P_0c0c2d6c;
case 0x0c0c2d6eu: goto P_0c0c2d6e;
case 0x0c0c2d70u: goto P_0c0c2d70;
case 0x0c0c2d72u: goto P_0c0c2d72;
case 0x0c0c2d74u: goto P_0c0c2d74;
case 0x0c0c2d76u: goto P_0c0c2d76;
case 0x0c0c2d78u: goto P_0c0c2d78;
case 0x0c0c2d7au: goto P_0c0c2d7a;
case 0x0c0c2d7cu: goto P_0c0c2d7c;
case 0x0c0c2d7eu: goto P_0c0c2d7e;
case 0x0c0c2d80u: goto P_0c0c2d80;
case 0x0c0c2d82u: goto P_0c0c2d82;
case 0x0c0c2d84u: goto P_0c0c2d84;
case 0x0c0c2d86u: goto P_0c0c2d86;
case 0x0c0c2dccu: goto P_0c0c2dcc;
case 0x0c0c2dceu: goto P_0c0c2dce;
case 0x0c0c2dd0u: goto P_0c0c2dd0;
case 0x0c0c2dd2u: goto P_0c0c2dd2;
case 0x0c0c2dd4u: goto P_0c0c2dd4;
case 0x0c0c2dd6u: goto P_0c0c2dd6;
case 0x0c0c2dd8u: goto P_0c0c2dd8;
case 0x0c0c2ddau: goto P_0c0c2dda;
case 0x0c0c2ddcu: goto P_0c0c2ddc;
case 0x0c0c2ddeu: goto P_0c0c2dde;
case 0x0c0c2de0u: goto P_0c0c2de0;
case 0x0c0c2de2u: goto P_0c0c2de2;
case 0x0c0c2de4u: goto P_0c0c2de4;
case 0x0c0c2de6u: goto P_0c0c2de6;
case 0x0c0c2de8u: goto P_0c0c2de8;
case 0x0c0c2deau: goto P_0c0c2dea;
case 0x0c0c2decu: goto P_0c0c2dec;
case 0x0c0c2deeu: goto P_0c0c2dee;
case 0x0c0c2df0u: goto P_0c0c2df0;
case 0x0c0c2df2u: goto P_0c0c2df2;
case 0x0c0c2df4u: goto P_0c0c2df4;
case 0x0c0c2df6u: goto P_0c0c2df6;
case 0x0c0c2df8u: goto P_0c0c2df8;
case 0x0c0c2dfau: goto P_0c0c2dfa;
case 0x0c0c2dfcu: goto P_0c0c2dfc;
case 0x0c0c2dfeu: goto P_0c0c2dfe;
case 0x0c0c2e00u: goto P_0c0c2e00;
case 0x0c0c2e02u: goto P_0c0c2e02;
case 0x0c0c2e04u: goto P_0c0c2e04;
case 0x0c0c2e06u: goto P_0c0c2e06;
case 0x0c0c2e08u: goto P_0c0c2e08;
case 0x0c0c2e0au: goto P_0c0c2e0a;
case 0x0c0c2e0cu: goto P_0c0c2e0c;
case 0x0c0c2e0eu: goto P_0c0c2e0e;
case 0x0c0c2e10u: goto P_0c0c2e10;
case 0x0c0c2e12u: goto P_0c0c2e12;
case 0x0c0c2e14u: goto P_0c0c2e14;
case 0x0c0c2e16u: goto P_0c0c2e16;
case 0x0c0c2e18u: goto P_0c0c2e18;
case 0x0c0c2e1au: goto P_0c0c2e1a;
case 0x0c0c2e1cu: goto P_0c0c2e1c;
case 0x0c0c2e1eu: goto P_0c0c2e1e;
case 0x0c0c2e20u: goto P_0c0c2e20;
case 0x0c0c2e22u: goto P_0c0c2e22;
case 0x0c0c2e24u: goto P_0c0c2e24;
case 0x0c0c2e26u: goto P_0c0c2e26;
case 0x0c0c2e28u: goto P_0c0c2e28;
case 0x0c0c2e2au: goto P_0c0c2e2a;
case 0x0c0c2e2cu: goto P_0c0c2e2c;
case 0x0c0c2e2eu: goto P_0c0c2e2e;
case 0x0c0c2e30u: goto P_0c0c2e30;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b71c: /* original 000b, guest PC 0x0c07b71c */
if(!s->budget--) { s->failed_pc=0x0c07b71cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b71e: /* original 0009, guest PC 0x0c07b71e */
if(!s->budget--) { s->failed_pc=0x0c07b71eu; return 0; }
if(!vf3_matrix_family(0x0c07b720u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b720u; return 0; } return 1;
P_0c0c124e: /* original e100, guest PC 0x0c0c124e */
if(!s->budget--) { s->failed_pc=0x0c0c124eu; return 0; }
r[1]=0x00000000u;
goto P_0c0c1250;
P_0c0c1250: /* original d324, guest PC 0x0c0c1250 */
if(!s->budget--) { s->failed_pc=0x0c0c1250u; return 0; }
r[3]=read(ram,0x0c0c12e4u,4);
goto P_0c0c1252;
P_0c0c1252: /* original e022, guest PC 0x0c0c1252 */
if(!s->budget--) { s->failed_pc=0x0c0c1252u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1254;
P_0c0c1254: /* original 7ffc, guest PC 0x0c0c1254 */
if(!s->budget--) { s->failed_pc=0x0c0c1254u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c1256;
P_0c0c1256: /* original 2f32, guest PC 0x0c0c1256 */
if(!s->budget--) { s->failed_pc=0x0c0c1256u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c1258;
P_0c0c1258: /* original 0415, guest PC 0x0c0c1258 */
if(!s->budget--) { s->failed_pc=0x0c0c1258u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c0c125a;
P_0c0c125a: /* original 6063, guest PC 0x0c0c125a */
if(!s->budget--) { s->failed_pc=0x0c0c125au; return 0; }
r[0]=r[6];
goto P_0c0c125c;
P_0c0c125c: /* original 1474, guest PC 0x0c0c125c */
if(!s->budget--) { s->failed_pc=0x0c0c125cu; return 0; }
write(ram,r[4]+16,r[7],4);
goto P_0c0c125e;
P_0c0c125e: /* original 53f1, guest PC 0x0c0c125e */
if(!s->budget--) { s->failed_pc=0x0c0c125eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1260;
P_0c0c1260: /* original 1433, guest PC 0x0c0c1260 */
if(!s->budget--) { s->failed_pc=0x0c0c1260u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0c1262;
P_0c0c1262: /* original 2451, guest PC 0x0c0c1262 */
if(!s->budget--) { s->failed_pc=0x0c0c1262u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0c1264;
P_0c0c1264: /* original 8141, guest PC 0x0c0c1264 */
if(!s->budget--) { s->failed_pc=0x0c0c1264u; return 0; }
write(ram,r[4]+2,r[0],2);
goto P_0c0c1266;
P_0c0c1266: /* original e040, guest PC 0x0c0c1266 */
if(!s->budget--) { s->failed_pc=0x0c0c1266u; return 0; }
r[0]=0x00000040u;
goto P_0c0c1268;
P_0c0c1268: /* original 53f2, guest PC 0x0c0c1268 */
if(!s->budget--) { s->failed_pc=0x0c0c1268u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c126a;
P_0c0c126a: /* original 1436, guest PC 0x0c0c126a */
if(!s->budget--) { s->failed_pc=0x0c0c126au; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0c126c;
P_0c0c126c: /* original 52f3, guest PC 0x0c0c126c */
if(!s->budget--) { s->failed_pc=0x0c0c126cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0c126e;
P_0c0c126e: /* original 1427, guest PC 0x0c0c126e */
if(!s->budget--) { s->failed_pc=0x0c0c126eu; return 0; }
write(ram,r[4]+28,r[2],4);
goto P_0c0c1270;
P_0c0c1270: /* original 8142, guest PC 0x0c0c1270 */
if(!s->budget--) { s->failed_pc=0x0c0c1270u; return 0; }
write(ram,r[4]+4,r[0],2);
goto P_0c0c1272;
P_0c0c1272: /* original e030, guest PC 0x0c0c1272 */
if(!s->budget--) { s->failed_pc=0x0c0c1272u; return 0; }
r[0]=0x00000030u;
goto P_0c0c1274;
P_0c0c1274: /* original 8143, guest PC 0x0c0c1274 */
if(!s->budget--) { s->failed_pc=0x0c0c1274u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0c1276;
P_0c0c1276: /* original e03e, guest PC 0x0c0c1276 */
if(!s->budget--) { s->failed_pc=0x0c0c1276u; return 0; }
r[0]=0x0000003eu;
goto P_0c0c1278;
P_0c0c1278: /* original 8144, guest PC 0x0c0c1278 */
if(!s->budget--) { s->failed_pc=0x0c0c1278u; return 0; }
write(ram,r[4]+8,r[0],2);
goto P_0c0c127a;
P_0c0c127a: /* original e02e, guest PC 0x0c0c127a */
if(!s->budget--) { s->failed_pc=0x0c0c127au; return 0; }
r[0]=0x0000002eu;
goto P_0c0c127c;
P_0c0c127c: /* original 8145, guest PC 0x0c0c127c */
if(!s->budget--) { s->failed_pc=0x0c0c127cu; return 0; }
write(ram,r[4]+10,r[0],2);
goto P_0c0c127e;
P_0c0c127e: /* original 6013, guest PC 0x0c0c127e */
if(!s->budget--) { s->failed_pc=0x0c0c127eu; return 0; }
r[0]=r[1];
goto P_0c0c1280;
P_0c0c1280: /* original 814a, guest PC 0x0c0c1280 */
if(!s->budget--) { s->failed_pc=0x0c0c1280u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c0c1282;
P_0c0c1282: /* original 814b, guest PC 0x0c0c1282 */
if(!s->budget--) { s->failed_pc=0x0c0c1282u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c0c1284;
P_0c0c1284: /* original e020, guest PC 0x0c0c1284 */
if(!s->budget--) { s->failed_pc=0x0c0c1284u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1286;
P_0c0c1286: /* original 932a, guest PC 0x0c0c1286 */
if(!s->budget--) { s->failed_pc=0x0c0c1286u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12deu,2);
goto P_0c0c1288;
P_0c0c1288: /* original 0435, guest PC 0x0c0c1288 */
if(!s->budget--) { s->failed_pc=0x0c0c1288u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0c128a;
P_0c0c128a: /* original e3ff, guest PC 0x0c0c128a */
if(!s->budget--) { s->failed_pc=0x0c0c128au; return 0; }
r[3]=0xffffffffu;
goto P_0c0c128c;
P_0c0c128c: /* original 62f2, guest PC 0x0c0c128c */
if(!s->budget--) { s->failed_pc=0x0c0c128cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c128e;
P_0c0c128e: /* original 9027, guest PC 0x0c0c128e */
if(!s->budget--) { s->failed_pc=0x0c0c128eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12e0u,2);
goto P_0c0c1290;
P_0c0c1290: /* original 0236, guest PC 0x0c0c1290 */
if(!s->budget--) { s->failed_pc=0x0c0c1290u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c1292;
P_0c0c1292: /* original a000, guest PC 0x0c0c1292 */
if(!s->budget--) { s->failed_pc=0x0c0c1292u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1294: /* original 7f04, guest PC 0x0c0c1294 */
if(!s->budget--) { s->failed_pc=0x0c0c1294u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1296: /* original 2fe6, guest PC 0x0c0c1296 */
if(!s->budget--) { s->failed_pc=0x0c0c1296u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1298;
P_0c0c1298: /* original 6e43, guest PC 0x0c0c1298 */
if(!s->budget--) { s->failed_pc=0x0c0c1298u; return 0; }
r[14]=r[4];
goto P_0c0c129a;
P_0c0c129a: /* original 2fd6, guest PC 0x0c0c129a */
if(!s->budget--) { s->failed_pc=0x0c0c129au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c129c;
P_0c0c129c: /* original ed00, guest PC 0x0c0c129c */
if(!s->budget--) { s->failed_pc=0x0c0c129cu; return 0; }
r[13]=0x00000000u;
goto P_0c0c129e;
P_0c0c129e: /* original 2fc6, guest PC 0x0c0c129e */
if(!s->budget--) { s->failed_pc=0x0c0c129eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12a0;
P_0c0c12a0: /* original ec78, guest PC 0x0c0c12a0 */
if(!s->budget--) { s->failed_pc=0x0c0c12a0u; return 0; }
r[12]=0x00000078u;
goto P_0c0c12a2;
P_0c0c12a2: /* original 2fb6, guest PC 0x0c0c12a2 */
if(!s->budget--) { s->failed_pc=0x0c0c12a2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12a4;
P_0c0c12a4: /* original 4f22, guest PC 0x0c0c12a4 */
if(!s->budget--) { s->failed_pc=0x0c0c12a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c12a6;
P_0c0c12a6: /* original 7ffc, guest PC 0x0c0c12a6 */
if(!s->budget--) { s->failed_pc=0x0c0c12a6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c12a8;
P_0c0c12a8: /* original 2f42, guest PC 0x0c0c12a8 */
if(!s->budget--) { s->failed_pc=0x0c0c12a8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c12aa;
P_0c0c12aa: /* original 5ee3, guest PC 0x0c0c12aa */
if(!s->budget--) { s->failed_pc=0x0c0c12aau; return 0; }
r[14]=read(ram,r[14]+12,4);
goto P_0c0c12ac;
P_0c0c12ac: /* original db0f, guest PC 0x0c0c12ac */
if(!s->budget--) { s->failed_pc=0x0c0c12acu; return 0; }
r[11]=read(ram,0x0c0c12ecu,4);
goto P_0c0c12ae;
P_0c0c12ae: /* original e500, guest PC 0x0c0c12ae */
if(!s->budget--) { s->failed_pc=0x0c0c12aeu; return 0; }
r[5]=0x00000000u;
goto P_0c0c12b0;
P_0c0c12b0: /* original e644, guest PC 0x0c0c12b0 */
if(!s->budget--) { s->failed_pc=0x0c0c12b0u; return 0; }
r[6]=0x00000044u;
goto P_0c0c12b2;
P_0c0c12b2: /* original 4b0b, guest PC 0x0c0c12b2 */
if(!s->budget--) { s->failed_pc=0x0c0c12b2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c12b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c12b6u) { target=s->pc; goto dispatch; }
goto P_0c0c12b6;
P_0c0c12b4: /* original 64e3, guest PC 0x0c0c12b4 */
if(!s->budget--) { s->failed_pc=0x0c0c12b4u; return 0; }
r[4]=r[14];
goto P_0c0c12b6;
P_0c0c12b6: /* original 7d01, guest PC 0x0c0c12b6 */
if(!s->budget--) { s->failed_pc=0x0c0c12b6u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c12b8;
P_0c0c12b8: /* original 3dc2, guest PC 0x0c0c12b8 */
if(!s->budget--) { s->failed_pc=0x0c0c12b8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[12])!=0);
goto P_0c0c12ba;
P_0c0c12ba: /* original 8ff8, guest PC 0x0c0c12ba */
if(!s->budget--) { s->failed_pc=0x0c0c12bau; return 0; }
cond=r[17]&1u;
r[14]+=0x00000044u;
if(!cond) { goto P_0c0c12ae; }
goto P_0c0c12be;
P_0c0c12bc: /* original 7e44, guest PC 0x0c0c12bc */
if(!s->budget--) { s->failed_pc=0x0c0c12bcu; return 0; }
r[14]+=0x00000044u;
goto P_0c0c12be;
P_0c0c12be: /* original 63f2, guest PC 0x0c0c12be */
if(!s->budget--) { s->failed_pc=0x0c0c12beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c12c0;
P_0c0c12c0: /* original 7f04, guest PC 0x0c0c12c0 */
if(!s->budget--) { s->failed_pc=0x0c0c12c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c12c2;
P_0c0c12c2: /* original 4f26, guest PC 0x0c0c12c2 */
if(!s->budget--) { s->failed_pc=0x0c0c12c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c12c4;
P_0c0c12c4: /* original e022, guest PC 0x0c0c12c4 */
if(!s->budget--) { s->failed_pc=0x0c0c12c4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c12c6;
P_0c0c12c6: /* original 013d, guest PC 0x0c0c12c6 */
if(!s->budget--) { s->failed_pc=0x0c0c12c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c12c8;
P_0c0c12c8: /* original e201, guest PC 0x0c0c12c8 */
if(!s->budget--) { s->failed_pc=0x0c0c12c8u; return 0; }
r[2]=0x00000001u;
goto P_0c0c12ca;
P_0c0c12ca: /* original 212b, guest PC 0x0c0c12ca */
if(!s->budget--) { s->failed_pc=0x0c0c12cau; return 0; }
r[1]|=r[2];
goto P_0c0c12cc;
P_0c0c12cc: /* original 0315, guest PC 0x0c0c12cc */
if(!s->budget--) { s->failed_pc=0x0c0c12ccu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c12ce;
P_0c0c12ce: /* original 6bf6, guest PC 0x0c0c12ce */
if(!s->budget--) { s->failed_pc=0x0c0c12ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c12d0;
P_0c0c12d0: /* original 6cf6, guest PC 0x0c0c12d0 */
if(!s->budget--) { s->failed_pc=0x0c0c12d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c12d2;
P_0c0c12d2: /* original 6df6, guest PC 0x0c0c12d2 */
if(!s->budget--) { s->failed_pc=0x0c0c12d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c12d4;
P_0c0c12d4: /* original 000b, guest PC 0x0c0c12d4 */
if(!s->budget--) { s->failed_pc=0x0c0c12d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c12d6: /* original 6ef6, guest PC 0x0c0c12d6 */
if(!s->budget--) { s->failed_pc=0x0c0c12d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c12d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c12d8u; return 0; } return 1;
P_0c0c285c: /* original 2fe6, guest PC 0x0c0c285c */
if(!s->budget--) { s->failed_pc=0x0c0c285cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c285e;
P_0c0c285e: /* original 2fd6, guest PC 0x0c0c285e */
if(!s->budget--) { s->failed_pc=0x0c0c285eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2860;
P_0c0c2860: /* original 2fc6, guest PC 0x0c0c2860 */
if(!s->budget--) { s->failed_pc=0x0c0c2860u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2862;
P_0c0c2862: /* original 2fb6, guest PC 0x0c0c2862 */
if(!s->budget--) { s->failed_pc=0x0c0c2862u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2864;
P_0c0c2864: /* original 2fa6, guest PC 0x0c0c2864 */
if(!s->budget--) { s->failed_pc=0x0c0c2864u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2866;
P_0c0c2866: /* original 2f96, guest PC 0x0c0c2866 */
if(!s->budget--) { s->failed_pc=0x0c0c2866u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2868;
P_0c0c2868: /* original 2f86, guest PC 0x0c0c2868 */
if(!s->budget--) { s->failed_pc=0x0c0c2868u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c286a;
P_0c0c286a: /* original 9074, guest PC 0x0c0c286a */
if(!s->budget--) { s->failed_pc=0x0c0c286au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2956u,2);
goto P_0c0c286c;
P_0c0c286c: /* original d83f, guest PC 0x0c0c286c */
if(!s->budget--) { s->failed_pc=0x0c0c286cu; return 0; }
r[8]=read(ram,0x0c0c296cu,4);
goto P_0c0c286e;
P_0c0c286e: /* original 9373, guest PC 0x0c0c286e */
if(!s->budget--) { s->failed_pc=0x0c0c286eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2958u,2);
goto P_0c0c2870;
P_0c0c2870: /* original 048e, guest PC 0x0c0c2870 */
if(!s->budget--) { s->failed_pc=0x0c0c2870u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c0c2872;
P_0c0c2872: /* original 4f22, guest PC 0x0c0c2872 */
if(!s->budget--) { s->failed_pc=0x0c0c2872u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2874;
P_0c0c2874: /* original dc41, guest PC 0x0c0c2874 */
if(!s->budget--) { s->failed_pc=0x0c0c2874u; return 0; }
r[12]=read(ram,0x0c0c297cu,4);
goto P_0c0c2876;
P_0c0c2876: /* original 3430, guest PC 0x0c0c2876 */
if(!s->budget--) { s->failed_pc=0x0c0c2876u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0c2878;
P_0c0c2878: /* original dd41, guest PC 0x0c0c2878 */
if(!s->budget--) { s->failed_pc=0x0c0c2878u; return 0; }
r[13]=read(ram,0x0c0c2980u,4);
goto P_0c0c287a;
P_0c0c287a: /* original d93d, guest PC 0x0c0c287a */
if(!s->budget--) { s->failed_pc=0x0c0c287au; return 0; }
r[9]=read(ram,0x0c0c2970u,4);
goto P_0c0c287c;
P_0c0c287c: /* original da3d, guest PC 0x0c0c287c */
if(!s->budget--) { s->failed_pc=0x0c0c287cu; return 0; }
r[10]=read(ram,0x0c0c2974u,4);
goto P_0c0c287e;
P_0c0c287e: /* original db3e, guest PC 0x0c0c287e */
if(!s->budget--) { s->failed_pc=0x0c0c287eu; return 0; }
r[11]=read(ram,0x0c0c2978u,4);
goto P_0c0c2880;
P_0c0c2880: /* original 8b08, guest PC 0x0c0c2880 */
if(!s->budget--) { s->failed_pc=0x0c0c2880u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2894; }
goto P_0c0c2882;
P_0c0c2882: /* original 4c0b, guest PC 0x0c0c2882 */
if(!s->budget--) { s->failed_pc=0x0c0c2882u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c2886u;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2886u) { target=s->pc; goto dispatch; }
goto P_0c0c2886;
P_0c0c2884: /* original e41d, guest PC 0x0c0c2884 */
if(!s->budget--) { s->failed_pc=0x0c0c2884u; return 0; }
r[4]=0x0000001du;
goto P_0c0c2886;
P_0c0c2886: /* original 65a2, guest PC 0x0c0c2886 */
if(!s->budget--) { s->failed_pc=0x0c0c2886u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c2888;
P_0c0c2888: /* original 6493, guest PC 0x0c0c2888 */
if(!s->budget--) { s->failed_pc=0x0c0c2888u; return 0; }
r[4]=r[9];
goto P_0c0c288a;
P_0c0c288a: /* original 4b0b, guest PC 0x0c0c288a */
if(!s->budget--) { s->failed_pc=0x0c0c288au; return 0; }
target=r[11];
r[16]=code_base|0x0c0c288eu;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c288eu) { target=s->pc; goto dispatch; }
goto P_0c0c288e;
P_0c0c288c: /* original 7410, guest PC 0x0c0c288c */
if(!s->budget--) { s->failed_pc=0x0c0c288cu; return 0; }
r[4]+=0x00000010u;
goto P_0c0c288e;
P_0c0c288e: /* original 7d3a, guest PC 0x0c0c288e */
if(!s->budget--) { s->failed_pc=0x0c0c288eu; return 0; }
r[13]+=0x0000003au;
goto P_0c0c2890;
P_0c0c2890: /* original a039, guest PC 0x0c0c2890 */
if(!s->budget--) { s->failed_pc=0x0c0c2890u; return 0; }
r[3]=0x0000001du;
goto P_0c0c2906;
P_0c0c2892: /* original e31d, guest PC 0x0c0c2892 */
if(!s->budget--) { s->failed_pc=0x0c0c2892u; return 0; }
r[3]=0x0000001du;
goto P_0c0c2894;
P_0c0c2894: /* original 9161, guest PC 0x0c0c2894 */
if(!s->budget--) { s->failed_pc=0x0c0c2894u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c295au,2);
goto P_0c0c2896;
P_0c0c2896: /* original 3410, guest PC 0x0c0c2896 */
if(!s->budget--) { s->failed_pc=0x0c0c2896u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c0c2898;
P_0c0c2898: /* original 8b09, guest PC 0x0c0c2898 */
if(!s->budget--) { s->failed_pc=0x0c0c2898u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c28ae; }
goto P_0c0c289a;
P_0c0c289a: /* original 4c0b, guest PC 0x0c0c289a */
if(!s->budget--) { s->failed_pc=0x0c0c289au; return 0; }
target=r[12];
r[16]=code_base|0x0c0c289eu;
r[4]=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c289eu) { target=s->pc; goto dispatch; }
goto P_0c0c289e;
P_0c0c289c: /* original e41e, guest PC 0x0c0c289c */
if(!s->budget--) { s->failed_pc=0x0c0c289cu; return 0; }
r[4]=0x0000001eu;
goto P_0c0c289e;
P_0c0c289e: /* original 65a2, guest PC 0x0c0c289e */
if(!s->budget--) { s->failed_pc=0x0c0c289eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c28a0;
P_0c0c28a0: /* original 6493, guest PC 0x0c0c28a0 */
if(!s->budget--) { s->failed_pc=0x0c0c28a0u; return 0; }
r[4]=r[9];
goto P_0c0c28a2;
P_0c0c28a2: /* original 4b0b, guest PC 0x0c0c28a2 */
if(!s->budget--) { s->failed_pc=0x0c0c28a2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c28a6u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28a6u) { target=s->pc; goto dispatch; }
goto P_0c0c28a6;
P_0c0c28a4: /* original 7420, guest PC 0x0c0c28a4 */
if(!s->budget--) { s->failed_pc=0x0c0c28a4u; return 0; }
r[4]+=0x00000020u;
goto P_0c0c28a6;
P_0c0c28a6: /* original e31e, guest PC 0x0c0c28a6 */
if(!s->budget--) { s->failed_pc=0x0c0c28a6u; return 0; }
r[3]=0x0000001eu;
goto P_0c0c28a8;
P_0c0c28a8: /* original 7d3c, guest PC 0x0c0c28a8 */
if(!s->budget--) { s->failed_pc=0x0c0c28a8u; return 0; }
r[13]+=0x0000003cu;
goto P_0c0c28aa;
P_0c0c28aa: /* original a02c, guest PC 0x0c0c28aa */
if(!s->budget--) { s->failed_pc=0x0c0c28aau; return 0; }
goto P_0c0c2906;
P_0c0c28ac: /* original 0009, guest PC 0x0c0c28ac */
if(!s->budget--) { s->failed_pc=0x0c0c28acu; return 0; }
goto P_0c0c28ae;
P_0c0c28ae: /* original 9055, guest PC 0x0c0c28ae */
if(!s->budget--) { s->failed_pc=0x0c0c28aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c295cu,2);
goto P_0c0c28b0;
P_0c0c28b0: /* original de34, guest PC 0x0c0c28b0 */
if(!s->budget--) { s->failed_pc=0x0c0c28b0u; return 0; }
r[14]=read(ram,0x0c0c2984u,4);
goto P_0c0c28b2;
P_0c0c28b2: /* original 3400, guest PC 0x0c0c28b2 */
if(!s->budget--) { s->failed_pc=0x0c0c28b2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[0])!=0);
goto P_0c0c28b4;
P_0c0c28b4: /* original 8b0b, guest PC 0x0c0c28b4 */
if(!s->budget--) { s->failed_pc=0x0c0c28b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c28ce; }
goto P_0c0c28b6;
P_0c0c28b6: /* original 4e0b, guest PC 0x0c0c28b6 */
if(!s->budget--) { s->failed_pc=0x0c0c28b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c28bau;
r[4]=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28bau) { target=s->pc; goto dispatch; }
goto P_0c0c28ba;
P_0c0c28b8: /* original e415, guest PC 0x0c0c28b8 */
if(!s->budget--) { s->failed_pc=0x0c0c28b8u; return 0; }
r[4]=0x00000015u;
goto P_0c0c28ba;
P_0c0c28ba: /* original 4c0b, guest PC 0x0c0c28ba */
if(!s->budget--) { s->failed_pc=0x0c0c28bau; return 0; }
target=r[12];
r[16]=code_base|0x0c0c28beu;
r[4]=0x0000001fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28beu) { target=s->pc; goto dispatch; }
goto P_0c0c28be;
P_0c0c28bc: /* original e41f, guest PC 0x0c0c28bc */
if(!s->budget--) { s->failed_pc=0x0c0c28bcu; return 0; }
r[4]=0x0000001fu;
goto P_0c0c28be;
P_0c0c28be: /* original 65a2, guest PC 0x0c0c28be */
if(!s->budget--) { s->failed_pc=0x0c0c28beu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c28c0;
P_0c0c28c0: /* original 6493, guest PC 0x0c0c28c0 */
if(!s->budget--) { s->failed_pc=0x0c0c28c0u; return 0; }
r[4]=r[9];
goto P_0c0c28c2;
P_0c0c28c2: /* original 4b0b, guest PC 0x0c0c28c2 */
if(!s->budget--) { s->failed_pc=0x0c0c28c2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c28c6u;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28c6u) { target=s->pc; goto dispatch; }
goto P_0c0c28c6;
P_0c0c28c4: /* original 7430, guest PC 0x0c0c28c4 */
if(!s->budget--) { s->failed_pc=0x0c0c28c4u; return 0; }
r[4]+=0x00000030u;
goto P_0c0c28c6;
P_0c0c28c6: /* original e21f, guest PC 0x0c0c28c6 */
if(!s->budget--) { s->failed_pc=0x0c0c28c6u; return 0; }
r[2]=0x0000001fu;
goto P_0c0c28c8;
P_0c0c28c8: /* original 7d3e, guest PC 0x0c0c28c8 */
if(!s->budget--) { s->failed_pc=0x0c0c28c8u; return 0; }
r[13]+=0x0000003eu;
goto P_0c0c28ca;
P_0c0c28ca: /* original a030, guest PC 0x0c0c28ca */
if(!s->budget--) { s->failed_pc=0x0c0c28cau; return 0; }
write(ram,r[13],r[2],2);
goto P_0c0c292e;
P_0c0c28cc: /* original 2d21, guest PC 0x0c0c28cc */
if(!s->budget--) { s->failed_pc=0x0c0c28ccu; return 0; }
write(ram,r[13],r[2],2);
goto P_0c0c28ce;
P_0c0c28ce: /* original 9346, guest PC 0x0c0c28ce */
if(!s->budget--) { s->failed_pc=0x0c0c28ceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c295eu,2);
goto P_0c0c28d0;
P_0c0c28d0: /* original 3430, guest PC 0x0c0c28d0 */
if(!s->budget--) { s->failed_pc=0x0c0c28d0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0c28d2;
P_0c0c28d2: /* original 8b0b, guest PC 0x0c0c28d2 */
if(!s->budget--) { s->failed_pc=0x0c0c28d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c28ec; }
goto P_0c0c28d4;
P_0c0c28d4: /* original 4e0b, guest PC 0x0c0c28d4 */
if(!s->budget--) { s->failed_pc=0x0c0c28d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c28d8u;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28d8u) { target=s->pc; goto dispatch; }
goto P_0c0c28d8;
P_0c0c28d6: /* original e41d, guest PC 0x0c0c28d6 */
if(!s->budget--) { s->failed_pc=0x0c0c28d6u; return 0; }
r[4]=0x0000001du;
goto P_0c0c28d8;
P_0c0c28d8: /* original 4c0b, guest PC 0x0c0c28d8 */
if(!s->budget--) { s->failed_pc=0x0c0c28d8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c28dcu;
r[4]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28dcu) { target=s->pc; goto dispatch; }
goto P_0c0c28dc;
P_0c0c28da: /* original e420, guest PC 0x0c0c28da */
if(!s->budget--) { s->failed_pc=0x0c0c28dau; return 0; }
r[4]=0x00000020u;
goto P_0c0c28dc;
P_0c0c28dc: /* original 65a2, guest PC 0x0c0c28dc */
if(!s->budget--) { s->failed_pc=0x0c0c28dcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c28de;
P_0c0c28de: /* original 6493, guest PC 0x0c0c28de */
if(!s->budget--) { s->failed_pc=0x0c0c28deu; return 0; }
r[4]=r[9];
goto P_0c0c28e0;
P_0c0c28e0: /* original 4b0b, guest PC 0x0c0c28e0 */
if(!s->budget--) { s->failed_pc=0x0c0c28e0u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c28e4u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28e4u) { target=s->pc; goto dispatch; }
goto P_0c0c28e4;
P_0c0c28e2: /* original 7440, guest PC 0x0c0c28e2 */
if(!s->budget--) { s->failed_pc=0x0c0c28e2u; return 0; }
r[4]+=0x00000040u;
goto P_0c0c28e4;
P_0c0c28e4: /* original e320, guest PC 0x0c0c28e4 */
if(!s->budget--) { s->failed_pc=0x0c0c28e4u; return 0; }
r[3]=0x00000020u;
goto P_0c0c28e6;
P_0c0c28e6: /* original 7d40, guest PC 0x0c0c28e6 */
if(!s->budget--) { s->failed_pc=0x0c0c28e6u; return 0; }
r[13]+=0x00000040u;
goto P_0c0c28e8;
P_0c0c28e8: /* original a00d, guest PC 0x0c0c28e8 */
if(!s->budget--) { s->failed_pc=0x0c0c28e8u; return 0; }
goto P_0c0c2906;
P_0c0c28ea: /* original 0009, guest PC 0x0c0c28ea */
if(!s->budget--) { s->failed_pc=0x0c0c28eau; return 0; }
goto P_0c0c28ec;
P_0c0c28ec: /* original 9138, guest PC 0x0c0c28ec */
if(!s->budget--) { s->failed_pc=0x0c0c28ecu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2960u,2);
goto P_0c0c28ee;
P_0c0c28ee: /* original 3410, guest PC 0x0c0c28ee */
if(!s->budget--) { s->failed_pc=0x0c0c28eeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c0c28f0;
P_0c0c28f0: /* original 8b0b, guest PC 0x0c0c28f0 */
if(!s->budget--) { s->failed_pc=0x0c0c28f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c290a; }
goto P_0c0c28f2;
P_0c0c28f2: /* original 4e0b, guest PC 0x0c0c28f2 */
if(!s->budget--) { s->failed_pc=0x0c0c28f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c28f6u;
r[4]=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28f6u) { target=s->pc; goto dispatch; }
goto P_0c0c28f6;
P_0c0c28f4: /* original e41e, guest PC 0x0c0c28f4 */
if(!s->budget--) { s->failed_pc=0x0c0c28f4u; return 0; }
r[4]=0x0000001eu;
goto P_0c0c28f6;
P_0c0c28f6: /* original 4c0b, guest PC 0x0c0c28f6 */
if(!s->budget--) { s->failed_pc=0x0c0c28f6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c28fau;
r[4]=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28fau) { target=s->pc; goto dispatch; }
goto P_0c0c28fa;
P_0c0c28f8: /* original e421, guest PC 0x0c0c28f8 */
if(!s->budget--) { s->failed_pc=0x0c0c28f8u; return 0; }
r[4]=0x00000021u;
goto P_0c0c28fa;
P_0c0c28fa: /* original 65a2, guest PC 0x0c0c28fa */
if(!s->budget--) { s->failed_pc=0x0c0c28fau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c28fc;
P_0c0c28fc: /* original 6493, guest PC 0x0c0c28fc */
if(!s->budget--) { s->failed_pc=0x0c0c28fcu; return 0; }
r[4]=r[9];
goto P_0c0c28fe;
P_0c0c28fe: /* original 4b0b, guest PC 0x0c0c28fe */
if(!s->budget--) { s->failed_pc=0x0c0c28feu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2902u;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2902u) { target=s->pc; goto dispatch; }
goto P_0c0c2902;
P_0c0c2900: /* original 7450, guest PC 0x0c0c2900 */
if(!s->budget--) { s->failed_pc=0x0c0c2900u; return 0; }
r[4]+=0x00000050u;
goto P_0c0c2902;
P_0c0c2902: /* original e321, guest PC 0x0c0c2902 */
if(!s->budget--) { s->failed_pc=0x0c0c2902u; return 0; }
r[3]=0x00000021u;
goto P_0c0c2904;
P_0c0c2904: /* original 7d42, guest PC 0x0c0c2904 */
if(!s->budget--) { s->failed_pc=0x0c0c2904u; return 0; }
r[13]+=0x00000042u;
goto P_0c0c2906;
P_0c0c2906: /* original a012, guest PC 0x0c0c2906 */
if(!s->budget--) { s->failed_pc=0x0c0c2906u; return 0; }
write(ram,r[13],r[3],2);
goto P_0c0c292e;
P_0c0c2908: /* original 2d31, guest PC 0x0c0c2908 */
if(!s->budget--) { s->failed_pc=0x0c0c2908u; return 0; }
write(ram,r[13],r[3],2);
goto P_0c0c290a;
P_0c0c290a: /* original 902a, guest PC 0x0c0c290a */
if(!s->budget--) { s->failed_pc=0x0c0c290au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2962u,2);
goto P_0c0c290c;
P_0c0c290c: /* original 3400, guest PC 0x0c0c290c */
if(!s->budget--) { s->failed_pc=0x0c0c290cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[0])!=0);
goto P_0c0c290e;
P_0c0c290e: /* original 8b01, guest PC 0x0c0c290e */
if(!s->budget--) { s->failed_pc=0x0c0c290eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2914; }
goto P_0c0c2910;
P_0c0c2910: /* original a004, guest PC 0x0c0c2910 */
if(!s->budget--) { s->failed_pc=0x0c0c2910u; return 0; }
r[4]=0x0000001fu;
goto P_0c0c291c;
P_0c0c2912: /* original e41f, guest PC 0x0c0c2912 */
if(!s->budget--) { s->failed_pc=0x0c0c2912u; return 0; }
r[4]=0x0000001fu;
goto P_0c0c2914;
P_0c0c2914: /* original 9326, guest PC 0x0c0c2914 */
if(!s->budget--) { s->failed_pc=0x0c0c2914u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2964u,2);
goto P_0c0c2916;
P_0c0c2916: /* original 3430, guest PC 0x0c0c2916 */
if(!s->budget--) { s->failed_pc=0x0c0c2916u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0c2918;
P_0c0c2918: /* original 8b04, guest PC 0x0c0c2918 */
if(!s->budget--) { s->failed_pc=0x0c0c2918u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2924; }
goto P_0c0c291a;
P_0c0c291a: /* original e420, guest PC 0x0c0c291a */
if(!s->budget--) { s->failed_pc=0x0c0c291au; return 0; }
r[4]=0x00000020u;
goto P_0c0c291c;
P_0c0c291c: /* original 4e0b, guest PC 0x0c0c291c */
if(!s->budget--) { s->failed_pc=0x0c0c291cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c2920u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2920u) { target=s->pc; goto dispatch; }
goto P_0c0c2920;
P_0c0c291e: /* original 0009, guest PC 0x0c0c291e */
if(!s->budget--) { s->failed_pc=0x0c0c291eu; return 0; }
goto P_0c0c2920;
P_0c0c2920: /* original a005, guest PC 0x0c0c2920 */
if(!s->budget--) { s->failed_pc=0x0c0c2920u; return 0; }
goto P_0c0c292e;
P_0c0c2922: /* original 0009, guest PC 0x0c0c2922 */
if(!s->budget--) { s->failed_pc=0x0c0c2922u; return 0; }
goto P_0c0c2924;
P_0c0c2924: /* original 921f, guest PC 0x0c0c2924 */
if(!s->budget--) { s->failed_pc=0x0c0c2924u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2966u,2);
goto P_0c0c2926;
P_0c0c2926: /* original 3420, guest PC 0x0c0c2926 */
if(!s->budget--) { s->failed_pc=0x0c0c2926u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c2928;
P_0c0c2928: /* original 8b01, guest PC 0x0c0c2928 */
if(!s->budget--) { s->failed_pc=0x0c0c2928u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c292e; }
goto P_0c0c292a;
P_0c0c292a: /* original 4e0b, guest PC 0x0c0c292a */
if(!s->budget--) { s->failed_pc=0x0c0c292au; return 0; }
target=r[14];
r[16]=code_base|0x0c0c292eu;
r[4]=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c292eu) { target=s->pc; goto dispatch; }
goto P_0c0c292e;
P_0c0c292c: /* original e421, guest PC 0x0c0c292c */
if(!s->budget--) { s->failed_pc=0x0c0c292cu; return 0; }
r[4]=0x00000021u;
goto P_0c0c292e;
P_0c0c292e: /* original 901b, guest PC 0x0c0c292e */
if(!s->budget--) { s->failed_pc=0x0c0c292eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2968u,2);
goto P_0c0c2930;
P_0c0c2930: /* original 048e, guest PC 0x0c0c2930 */
if(!s->budget--) { s->failed_pc=0x0c0c2930u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c0c2932;
P_0c0c2932: /* original 3f40, guest PC 0x0c0c2932 */
if(!s->budget--) { s->failed_pc=0x0c0c2932u; return 0; }
r[17]=(r[17]&~1u)|((r[15]==r[4])!=0);
goto P_0c0c2934;
P_0c0c2934: /* original 8906, guest PC 0x0c0c2934 */
if(!s->budget--) { s->failed_pc=0x0c0c2934u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2944; }
goto P_0c0c2936;
P_0c0c2936: /* original d214, guest PC 0x0c0c2936 */
if(!s->budget--) { s->failed_pc=0x0c0c2936u; return 0; }
r[2]=read(ram,0x0c0c2988u,4);
goto P_0c0c2938;
P_0c0c2938: /* original e501, guest PC 0x0c0c2938 */
if(!s->budget--) { s->failed_pc=0x0c0c2938u; return 0; }
r[5]=0x00000001u;
goto P_0c0c293a;
P_0c0c293a: /* original e600, guest PC 0x0c0c293a */
if(!s->budget--) { s->failed_pc=0x0c0c293au; return 0; }
r[6]=0x00000000u;
goto P_0c0c293c;
P_0c0c293c: /* original 420b, guest PC 0x0c0c293c */
if(!s->budget--) { s->failed_pc=0x0c0c293cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c2940u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2940u) { target=s->pc; goto dispatch; }
goto P_0c0c2940;
P_0c0c293e: /* original 64f3, guest PC 0x0c0c293e */
if(!s->budget--) { s->failed_pc=0x0c0c293eu; return 0; }
r[4]=r[15];
goto P_0c0c2940;
P_0c0c2940: /* original 9012, guest PC 0x0c0c2940 */
if(!s->budget--) { s->failed_pc=0x0c0c2940u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2968u,2);
goto P_0c0c2942;
P_0c0c2942: /* original 08f6, guest PC 0x0c0c2942 */
if(!s->budget--) { s->failed_pc=0x0c0c2942u; return 0; }
write(ram,r[8]+r[0],r[15],4);
goto P_0c0c2944;
P_0c0c2944: /* original 4f26, guest PC 0x0c0c2944 */
if(!s->budget--) { s->failed_pc=0x0c0c2944u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2946;
P_0c0c2946: /* original 68f6, guest PC 0x0c0c2946 */
if(!s->budget--) { s->failed_pc=0x0c0c2946u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c2948;
P_0c0c2948: /* original 69f6, guest PC 0x0c0c2948 */
if(!s->budget--) { s->failed_pc=0x0c0c2948u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c294a;
P_0c0c294a: /* original 6af6, guest PC 0x0c0c294a */
if(!s->budget--) { s->failed_pc=0x0c0c294au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c294c;
P_0c0c294c: /* original 6bf6, guest PC 0x0c0c294c */
if(!s->budget--) { s->failed_pc=0x0c0c294cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c294e;
P_0c0c294e: /* original 6cf6, guest PC 0x0c0c294e */
if(!s->budget--) { s->failed_pc=0x0c0c294eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2950;
P_0c0c2950: /* original 6df6, guest PC 0x0c0c2950 */
if(!s->budget--) { s->failed_pc=0x0c0c2950u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2952;
P_0c0c2952: /* original 000b, guest PC 0x0c0c2952 */
if(!s->budget--) { s->failed_pc=0x0c0c2952u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2954: /* original 6ef6, guest PC 0x0c0c2954 */
if(!s->budget--) { s->failed_pc=0x0c0c2954u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c2956u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2956u; return 0; } return 1;
P_0c0c2d06: /* original 2fe6, guest PC 0x0c0c2d06 */
if(!s->budget--) { s->failed_pc=0x0c0c2d06u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d08;
P_0c0c2d08: /* original 2fd6, guest PC 0x0c0c2d08 */
if(!s->budget--) { s->failed_pc=0x0c0c2d08u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0a;
P_0c0c2d0a: /* original 2fc6, guest PC 0x0c0c2d0a */
if(!s->budget--) { s->failed_pc=0x0c0c2d0au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0c;
P_0c0c2d0c: /* original 2fb6, guest PC 0x0c0c2d0c */
if(!s->budget--) { s->failed_pc=0x0c0c2d0cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0e;
P_0c0c2d0e: /* original fffb, guest PC 0x0c0c2d0e */
if(!s->budget--) { s->failed_pc=0x0c0c2d0eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c2d10;
P_0c0c2d10: /* original 4f22, guest PC 0x0c0c2d10 */
if(!s->budget--) { s->failed_pc=0x0c0c2d10u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2d12;
P_0c0c2d12: /* original de28, guest PC 0x0c0c2d12 */
if(!s->budget--) { s->failed_pc=0x0c0c2d12u; return 0; }
r[14]=read(ram,0x0c0c2db4u,4);
goto P_0c0c2d14;
P_0c0c2d14: /* original d328, guest PC 0x0c0c2d14 */
if(!s->budget--) { s->failed_pc=0x0c0c2d14u; return 0; }
r[3]=read(ram,0x0c0c2db8u,4);
goto P_0c0c2d16;
P_0c0c2d16: /* original 65e3, guest PC 0x0c0c2d16 */
if(!s->budget--) { s->failed_pc=0x0c0c2d16u; return 0; }
r[5]=r[14];
goto P_0c0c2d18;
P_0c0c2d18: /* original 7ff8, guest PC 0x0c0c2d18 */
if(!s->budget--) { s->failed_pc=0x0c0c2d18u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c2d1a;
P_0c0c2d1a: /* original 66e3, guest PC 0x0c0c2d1a */
if(!s->budget--) { s->failed_pc=0x0c0c2d1au; return 0; }
r[6]=r[14];
goto P_0c0c2d1c;
P_0c0c2d1c: /* original 430b, guest PC 0x0c0c2d1c */
if(!s->budget--) { s->failed_pc=0x0c0c2d1cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2d20u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2d20u) { target=s->pc; goto dispatch; }
goto P_0c0c2d20;
P_0c0c2d1e: /* original 64e3, guest PC 0x0c0c2d1e */
if(!s->budget--) { s->failed_pc=0x0c0c2d1eu; return 0; }
r[4]=r[14];
goto P_0c0c2d20;
P_0c0c2d20: /* original de22, guest PC 0x0c0c2d20 */
if(!s->budget--) { s->failed_pc=0x0c0c2d20u; return 0; }
r[14]=read(ram,0x0c0c2dacu,4);
goto P_0c0c2d22;
P_0c0c2d22: /* original db20, guest PC 0x0c0c2d22 */
if(!s->budget--) { s->failed_pc=0x0c0c2d22u; return 0; }
r[11]=read(ram,0x0c0c2da4u,4);
goto P_0c0c2d24;
P_0c0c2d24: /* original 54e2, guest PC 0x0c0c2d24 */
if(!s->budget--) { s->failed_pc=0x0c0c2d24u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c0c2d26;
P_0c0c2d26: /* original dc1e, guest PC 0x0c0c2d26 */
if(!s->budget--) { s->failed_pc=0x0c0c2d26u; return 0; }
r[12]=read(ram,0x0c0c2da0u,4);
goto P_0c0c2d28;
P_0c0c2d28: /* original 6243, guest PC 0x0c0c2d28 */
if(!s->budget--) { s->failed_pc=0x0c0c2d28u; return 0; }
r[2]=r[4];
goto P_0c0c2d2a;
P_0c0c2d2a: /* original 2448, guest PC 0x0c0c2d2a */
if(!s->budget--) { s->failed_pc=0x0c0c2d2au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c2d2c;
P_0c0c2d2c: /* original 7201, guest PC 0x0c0c2d2c */
if(!s->budget--) { s->failed_pc=0x0c0c2d2cu; return 0; }
r[2]+=0x00000001u;
goto P_0c0c2d2e;
P_0c0c2d2e: /* original 8f08, guest PC 0x0c0c2d2e */
if(!s->budget--) { s->failed_pc=0x0c0c2d2eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+8,r[2],4);
if(!cond) { goto P_0c0c2d42; }
goto P_0c0c2d32;
P_0c0c2d30: /* original 1e22, guest PC 0x0c0c2d30 */
if(!s->budget--) { s->failed_pc=0x0c0c2d30u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0c2d32;
P_0c0c2d32: /* original 942c, guest PC 0x0c0c2d32 */
if(!s->budget--) { s->failed_pc=0x0c0c2d32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d8eu,2);
goto P_0c0c2d34;
P_0c0c2d34: /* original e700, guest PC 0x0c0c2d34 */
if(!s->budget--) { s->failed_pc=0x0c0c2d34u; return 0; }
r[7]=0x00000000u;
goto P_0c0c2d36;
P_0c0c2d36: /* original 6573, guest PC 0x0c0c2d36 */
if(!s->budget--) { s->failed_pc=0x0c0c2d36u; return 0; }
r[5]=r[7];
goto P_0c0c2d38;
P_0c0c2d38: /* original 6673, guest PC 0x0c0c2d38 */
if(!s->budget--) { s->failed_pc=0x0c0c2d38u; return 0; }
r[6]=r[7];
goto P_0c0c2d3a;
P_0c0c2d3a: /* original 4b0b, guest PC 0x0c0c2d3a */
if(!s->budget--) { s->failed_pc=0x0c0c2d3au; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2d3eu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2d3eu) { target=s->pc; goto dispatch; }
goto P_0c0c2d3e;
P_0c0c2d3c: /* original 34cc, guest PC 0x0c0c2d3c */
if(!s->budget--) { s->failed_pc=0x0c0c2d3cu; return 0; }
r[4]+=r[12];
goto P_0c0c2d3e;
P_0c0c2d3e: /* original a070, guest PC 0x0c0c2d3e */
if(!s->budget--) { s->failed_pc=0x0c0c2d3eu; return 0; }
goto P_0c0c2e22;
P_0c0c2d40: /* original 0009, guest PC 0x0c0c2d40 */
if(!s->budget--) { s->failed_pc=0x0c0c2d40u; return 0; }
goto P_0c0c2d42;
P_0c0c2d42: /* original e308, guest PC 0x0c0c2d42 */
if(!s->budget--) { s->failed_pc=0x0c0c2d42u; return 0; }
r[3]=0x00000008u;
goto P_0c0c2d44;
P_0c0c2d44: /* original 3433, guest PC 0x0c0c2d44 */
if(!s->budget--) { s->failed_pc=0x0c0c2d44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c2d46;
P_0c0c2d46: /* original 8941, guest PC 0x0c0c2d46 */
if(!s->budget--) { s->failed_pc=0x0c0c2d46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2dcc; }
goto P_0c0c2d48;
P_0c0c2d48: /* original c71c, guest PC 0x0c0c2d48 */
if(!s->budget--) { s->failed_pc=0x0c0c2d48u; return 0; }
r[0]=code_base|0x000c2dbcu;
goto P_0c0c2d4a;
P_0c0c2d4a: /* original ffe8, guest PC 0x0c0c2d4a */
if(!s->budget--) { s->failed_pc=0x0c0c2d4au; return 0; }
vf3_matrix_load(s,ram,15,r[14]);
goto P_0c0c2d4c;
P_0c0c2d4c: /* original f408, guest PC 0x0c0c2d4c */
if(!s->budget--) { s->failed_pc=0x0c0c2d4cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c2d4e;
P_0c0c2d4e: /* original 52e1, guest PC 0x0c0c2d4e */
if(!s->budget--) { s->failed_pc=0x0c0c2d4eu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c2d50;
P_0c0c2d50: /* original ff45, guest PC 0x0c0c2d50 */
if(!s->budget--) { s->failed_pc=0x0c0c2d50u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c0c2d52;
P_0c0c2d52: /* original 1f21, guest PC 0x0c0c2d52 */
if(!s->budget--) { s->failed_pc=0x0c0c2d52u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0c2d54;
P_0c0c2d54: /* original 8b65, guest PC 0x0c0c2d54 */
if(!s->budget--) { s->failed_pc=0x0c0c2d54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2e22; }
goto P_0c0c2d56;
P_0c0c2d56: /* original f39d, guest PC 0x0c0c2d56 */
if(!s->budget--) { s->failed_pc=0x0c0c2d56u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c2d58;
P_0c0c2d58: /* original f3f1, guest PC 0x0c0c2d58 */
if(!s->budget--) { s->failed_pc=0x0c0c2d58u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'-');
goto P_0c0c2d5a;
P_0c0c2d5a: /* original c719, guest PC 0x0c0c2d5a */
if(!s->budget--) { s->failed_pc=0x0c0c2d5au; return 0; }
r[0]=code_base|0x000c2dc0u;
goto P_0c0c2d5c;
P_0c0c2d5c: /* original 64c3, guest PC 0x0c0c2d5c */
if(!s->budget--) { s->failed_pc=0x0c0c2d5cu; return 0; }
r[4]=r[12];
goto P_0c0c2d5e;
P_0c0c2d5e: /* original f6fc, guest PC 0x0c0c2d5e */
if(!s->budget--) { s->failed_pc=0x0c0c2d5eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0c2d60;
P_0c0c2d60: /* original e600, guest PC 0x0c0c2d60 */
if(!s->budget--) { s->failed_pc=0x0c0c2d60u; return 0; }
r[6]=0x00000000u;
goto P_0c0c2d62;
P_0c0c2d62: /* original ff3a, guest PC 0x0c0c2d62 */
if(!s->budget--) { s->failed_pc=0x0c0c2d62u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0c2d64;
P_0c0c2d64: /* original f208, guest PC 0x0c0c2d64 */
if(!s->budget--) { s->failed_pc=0x0c0c2d64u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c2d66;
P_0c0c2d66: /* original c717, guest PC 0x0c0c2d66 */
if(!s->budget--) { s->failed_pc=0x0c0c2d66u; return 0; }
r[0]=code_base|0x000c2dc4u;
goto P_0c0c2d68;
P_0c0c2d68: /* original f108, guest PC 0x0c0c2d68 */
if(!s->budget--) { s->failed_pc=0x0c0c2d68u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c2d6a;
P_0c0c2d6a: /* original f43c, guest PC 0x0c0c2d6a */
if(!s->budget--) { s->failed_pc=0x0c0c2d6au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c2d6c;
P_0c0c2d6c: /* original f53c, guest PC 0x0c0c2d6c */
if(!s->budget--) { s->failed_pc=0x0c0c2d6cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c2d6e;
P_0c0c2d6e: /* original f412, guest PC 0x0c0c2d6e */
if(!s->budget--) { s->failed_pc=0x0c0c2d6eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'*');
goto P_0c0c2d70;
P_0c0c2d70: /* original f522, guest PC 0x0c0c2d70 */
if(!s->budget--) { s->failed_pc=0x0c0c2d70u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c0c2d72;
P_0c0c2d72: /* original 950e, guest PC 0x0c0c2d72 */
if(!s->budget--) { s->failed_pc=0x0c0c2d72u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d92u,2);
goto P_0c0c2d74;
P_0c0c2d74: /* original b05d, guest PC 0x0c0c2d74 */
if(!s->budget--) { s->failed_pc=0x0c0c2d74u; return 0; }
target=code_base|0x0c0c2e32u; r[16]=code_base|0x0c0c2d78u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2d78u) { target=s->pc; goto dispatch; }
goto P_0c0c2d78;
P_0c0c2d76: /* original 7458, guest PC 0x0c0c2d76 */
if(!s->budget--) { s->failed_pc=0x0c0c2d76u; return 0; }
r[4]+=0x00000058u;
goto P_0c0c2d78;
P_0c0c2d78: /* original c713, guest PC 0x0c0c2d78 */
if(!s->budget--) { s->failed_pc=0x0c0c2d78u; return 0; }
r[0]=code_base|0x000c2dc8u;
goto P_0c0c2d7a;
P_0c0c2d7a: /* original f308, guest PC 0x0c0c2d7a */
if(!s->budget--) { s->failed_pc=0x0c0c2d7au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c2d7c;
P_0c0c2d7c: /* original ff30, guest PC 0x0c0c2d7c */
if(!s->budget--) { s->failed_pc=0x0c0c2d7cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0c2d7e;
P_0c0c2d7e: /* original fefa, guest PC 0x0c0c2d7e */
if(!s->budget--) { s->failed_pc=0x0c0c2d7eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c0c2d80;
P_0c0c2d80: /* original 53f1, guest PC 0x0c0c2d80 */
if(!s->budget--) { s->failed_pc=0x0c0c2d80u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c2d82;
P_0c0c2d82: /* original 73ff, guest PC 0x0c0c2d82 */
if(!s->budget--) { s->failed_pc=0x0c0c2d82u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0c2d84;
P_0c0c2d84: /* original a04d, guest PC 0x0c0c2d84 */
if(!s->budget--) { s->failed_pc=0x0c0c2d84u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2e22;
P_0c0c2d86: /* original 1e31, guest PC 0x0c0c2d86 */
if(!s->budget--) { s->failed_pc=0x0c0c2d86u; return 0; }
write(ram,r[14]+4,r[3],4);
if(!vf3_matrix_family(0x0c0c2d88u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2d88u; return 0; } return 1;
P_0c0c2dcc: /* original 6043, guest PC 0x0c0c2dcc */
if(!s->budget--) { s->failed_pc=0x0c0c2dccu; return 0; }
r[0]=r[4];
goto P_0c0c2dce;
P_0c0c2dce: /* original 8808, guest PC 0x0c0c2dce */
if(!s->budget--) { s->failed_pc=0x0c0c2dceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0c2dd0;
P_0c0c2dd0: /* original 8b0c, guest PC 0x0c0c2dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2dec; }
goto P_0c0c2dd2;
P_0c0c2dd2: /* original d252, guest PC 0x0c0c2dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd2u; return 0; }
r[2]=read(ram,0x0c0c2f1cu,4);
goto P_0c0c2dd4;
P_0c0c2dd4: /* original 64c3, guest PC 0x0c0c2dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd4u; return 0; }
r[4]=r[12];
goto P_0c0c2dd6;
P_0c0c2dd6: /* original 420b, guest PC 0x0c0c2dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c2ddau;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2ddau) { target=s->pc; goto dispatch; }
goto P_0c0c2dda;
P_0c0c2dd8: /* original 7458, guest PC 0x0c0c2dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd8u; return 0; }
r[4]+=0x00000058u;
goto P_0c0c2dda;
P_0c0c2dda: /* original 949b, guest PC 0x0c0c2dda */
if(!s->budget--) { s->failed_pc=0x0c0c2ddau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f14u,2);
goto P_0c0c2ddc;
P_0c0c2ddc: /* original e71f, guest PC 0x0c0c2ddc */
if(!s->budget--) { s->failed_pc=0x0c0c2ddcu; return 0; }
r[7]=0x0000001fu;
goto P_0c0c2dde;
P_0c0c2dde: /* original 6573, guest PC 0x0c0c2dde */
if(!s->budget--) { s->failed_pc=0x0c0c2ddeu; return 0; }
r[5]=r[7];
goto P_0c0c2de0;
P_0c0c2de0: /* original 6673, guest PC 0x0c0c2de0 */
if(!s->budget--) { s->failed_pc=0x0c0c2de0u; return 0; }
r[6]=r[7];
goto P_0c0c2de2;
P_0c0c2de2: /* original 4b0b, guest PC 0x0c0c2de2 */
if(!s->budget--) { s->failed_pc=0x0c0c2de2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2de6u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2de6u) { target=s->pc; goto dispatch; }
goto P_0c0c2de6;
P_0c0c2de4: /* original 34cc, guest PC 0x0c0c2de4 */
if(!s->budget--) { s->failed_pc=0x0c0c2de4u; return 0; }
r[4]+=r[12];
goto P_0c0c2de6;
P_0c0c2de6: /* original e31f, guest PC 0x0c0c2de6 */
if(!s->budget--) { s->failed_pc=0x0c0c2de6u; return 0; }
r[3]=0x0000001fu;
goto P_0c0c2de8;
P_0c0c2de8: /* original a01b, guest PC 0x0c0c2de8 */
if(!s->budget--) { s->failed_pc=0x0c0c2de8u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2e22;
P_0c0c2dea: /* original 1e31, guest PC 0x0c0c2dea */
if(!s->budget--) { s->failed_pc=0x0c0c2deau; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2dec;
P_0c0c2dec: /* original 8809, guest PC 0x0c0c2dec */
if(!s->budget--) { s->failed_pc=0x0c0c2decu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c2dee;
P_0c0c2dee: /* original 8b0a, guest PC 0x0c0c2dee */
if(!s->budget--) { s->failed_pc=0x0c0c2deeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2e06; }
goto P_0c0c2df0;
P_0c0c2df0: /* original 66c3, guest PC 0x0c0c2df0 */
if(!s->budget--) { s->failed_pc=0x0c0c2df0u; return 0; }
r[6]=r[12];
goto P_0c0c2df2;
P_0c0c2df2: /* original e201, guest PC 0x0c0c2df2 */
if(!s->budget--) { s->failed_pc=0x0c0c2df2u; return 0; }
r[2]=0x00000001u;
goto P_0c0c2df4;
P_0c0c2df4: /* original 2f26, guest PC 0x0c0c2df4 */
if(!s->budget--) { s->failed_pc=0x0c0c2df4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2df6;
P_0c0c2df6: /* original e700, guest PC 0x0c0c2df6 */
if(!s->budget--) { s->failed_pc=0x0c0c2df6u; return 0; }
r[7]=0x00000000u;
goto P_0c0c2df8;
P_0c0c2df8: /* original 958d, guest PC 0x0c0c2df8 */
if(!s->budget--) { s->failed_pc=0x0c0c2df8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f16u,2);
goto P_0c0c2dfa;
P_0c0c2dfa: /* original 7658, guest PC 0x0c0c2dfa */
if(!s->budget--) { s->failed_pc=0x0c0c2dfau; return 0; }
r[6]+=0x00000058u;
goto P_0c0c2dfc;
P_0c0c2dfc: /* original d148, guest PC 0x0c0c2dfc */
if(!s->budget--) { s->failed_pc=0x0c0c2dfcu; return 0; }
r[1]=read(ram,0x0c0c2f20u,4);
goto P_0c0c2dfe;
P_0c0c2dfe: /* original 410b, guest PC 0x0c0c2dfe */
if(!s->budget--) { s->failed_pc=0x0c0c2dfeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0c2e02u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2e02u) { target=s->pc; goto dispatch; }
goto P_0c0c2e02;
P_0c0c2e00: /* original 6473, guest PC 0x0c0c2e00 */
if(!s->budget--) { s->failed_pc=0x0c0c2e00u; return 0; }
r[4]=r[7];
goto P_0c0c2e02;
P_0c0c2e02: /* original a00e, guest PC 0x0c0c2e02 */
if(!s->budget--) { s->failed_pc=0x0c0c2e02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c2e22;
P_0c0c2e04: /* original 7f04, guest PC 0x0c0c2e04 */
if(!s->budget--) { s->failed_pc=0x0c0c2e04u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c2e06;
P_0c0c2e06: /* original e229, guest PC 0x0c0c2e06 */
if(!s->budget--) { s->failed_pc=0x0c0c2e06u; return 0; }
r[2]=0x00000029u;
goto P_0c0c2e08;
P_0c0c2e08: /* original 3423, guest PC 0x0c0c2e08 */
if(!s->budget--) { s->failed_pc=0x0c0c2e08u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c2e0a;
P_0c0c2e0a: /* original 890a, guest PC 0x0c0c2e0a */
if(!s->budget--) { s->failed_pc=0x0c0c2e0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2e22; }
goto P_0c0c2e0c;
P_0c0c2e0c: /* original 5de1, guest PC 0x0c0c2e0c */
if(!s->budget--) { s->failed_pc=0x0c0c2e0cu; return 0; }
r[13]=read(ram,r[14]+4,4);
goto P_0c0c2e0e;
P_0c0c2e0e: /* original 2dd8, guest PC 0x0c0c2e0e */
if(!s->budget--) { s->failed_pc=0x0c0c2e0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0c2e10;
P_0c0c2e10: /* original 8907, guest PC 0x0c0c2e10 */
if(!s->budget--) { s->failed_pc=0x0c0c2e10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2e22; }
goto P_0c0c2e12;
P_0c0c2e12: /* original 947f, guest PC 0x0c0c2e12 */
if(!s->budget--) { s->failed_pc=0x0c0c2e12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f14u,2);
goto P_0c0c2e14;
P_0c0c2e14: /* original 65d3, guest PC 0x0c0c2e14 */
if(!s->budget--) { s->failed_pc=0x0c0c2e14u; return 0; }
r[5]=r[13];
goto P_0c0c2e16;
P_0c0c2e16: /* original 67d3, guest PC 0x0c0c2e16 */
if(!s->budget--) { s->failed_pc=0x0c0c2e16u; return 0; }
r[7]=r[13];
goto P_0c0c2e18;
P_0c0c2e18: /* original 66d3, guest PC 0x0c0c2e18 */
if(!s->budget--) { s->failed_pc=0x0c0c2e18u; return 0; }
r[6]=r[13];
goto P_0c0c2e1a;
P_0c0c2e1a: /* original 4b0b, guest PC 0x0c0c2e1a */
if(!s->budget--) { s->failed_pc=0x0c0c2e1au; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2e1eu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2e1eu) { target=s->pc; goto dispatch; }
goto P_0c0c2e1e;
P_0c0c2e1c: /* original 34cc, guest PC 0x0c0c2e1c */
if(!s->budget--) { s->failed_pc=0x0c0c2e1cu; return 0; }
r[4]+=r[12];
goto P_0c0c2e1e;
P_0c0c2e1e: /* original 7dff, guest PC 0x0c0c2e1e */
if(!s->budget--) { s->failed_pc=0x0c0c2e1eu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0c2e20;
P_0c0c2e20: /* original 1ed1, guest PC 0x0c0c2e20 */
if(!s->budget--) { s->failed_pc=0x0c0c2e20u; return 0; }
write(ram,r[14]+4,r[13],4);
goto P_0c0c2e22;
P_0c0c2e22: /* original 7f08, guest PC 0x0c0c2e22 */
if(!s->budget--) { s->failed_pc=0x0c0c2e22u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c2e24;
P_0c0c2e24: /* original 4f26, guest PC 0x0c0c2e24 */
if(!s->budget--) { s->failed_pc=0x0c0c2e24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2e26;
P_0c0c2e26: /* original fff9, guest PC 0x0c0c2e26 */
if(!s->budget--) { s->failed_pc=0x0c0c2e26u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2e28;
P_0c0c2e28: /* original 6bf6, guest PC 0x0c0c2e28 */
if(!s->budget--) { s->failed_pc=0x0c0c2e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c2e2a;
P_0c0c2e2a: /* original 6cf6, guest PC 0x0c0c2e2a */
if(!s->budget--) { s->failed_pc=0x0c0c2e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2e2c;
P_0c0c2e2c: /* original 6df6, guest PC 0x0c0c2e2c */
if(!s->budget--) { s->failed_pc=0x0c0c2e2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2e2e;
P_0c0c2e2e: /* original 000b, guest PC 0x0c0c2e2e */
if(!s->budget--) { s->failed_pc=0x0c0c2e2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2e30: /* original 6ef6, guest PC 0x0c0c2e30 */
if(!s->budget--) { s->failed_pc=0x0c0c2e30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c2e32u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
