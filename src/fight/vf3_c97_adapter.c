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
int vf3_c97_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0371c2u: goto P_0c0371c2;
case 0x0c0371c4u: goto P_0c0371c4;
case 0x0c0371c6u: goto P_0c0371c6;
case 0x0c0371c8u: goto P_0c0371c8;
case 0x0c0371cau: goto P_0c0371ca;
case 0x0c0371ccu: goto P_0c0371cc;
case 0x0c0371ceu: goto P_0c0371ce;
case 0x0c0371d0u: goto P_0c0371d0;
case 0x0c0371d2u: goto P_0c0371d2;
case 0x0c0371d4u: goto P_0c0371d4;
case 0x0c0371d6u: goto P_0c0371d6;
case 0x0c0371d8u: goto P_0c0371d8;
case 0x0c0371dau: goto P_0c0371da;
case 0x0c0371dcu: goto P_0c0371dc;
case 0x0c0371deu: goto P_0c0371de;
case 0x0c0371e0u: goto P_0c0371e0;
case 0x0c0371e2u: goto P_0c0371e2;
case 0x0c0371e4u: goto P_0c0371e4;
case 0x0c037248u: goto P_0c037248;
case 0x0c03724au: goto P_0c03724a;
case 0x0c03724cu: goto P_0c03724c;
case 0x0c03724eu: goto P_0c03724e;
case 0x0c037250u: goto P_0c037250;
case 0x0c037252u: goto P_0c037252;
case 0x0c037254u: goto P_0c037254;
case 0x0c037256u: goto P_0c037256;
case 0x0c037258u: goto P_0c037258;
case 0x0c03725au: goto P_0c03725a;
case 0x0c03725cu: goto P_0c03725c;
case 0x0c03725eu: goto P_0c03725e;
case 0x0c037260u: goto P_0c037260;
case 0x0c037262u: goto P_0c037262;
case 0x0c037264u: goto P_0c037264;
case 0x0c037266u: goto P_0c037266;
case 0x0c037268u: goto P_0c037268;
case 0x0c03726au: goto P_0c03726a;
case 0x0c03726cu: goto P_0c03726c;
case 0x0c03726eu: goto P_0c03726e;
case 0x0c037270u: goto P_0c037270;
case 0x0c037272u: goto P_0c037272;
case 0x0c037274u: goto P_0c037274;
case 0x0c037276u: goto P_0c037276;
case 0x0c037278u: goto P_0c037278;
case 0x0c03727au: goto P_0c03727a;
case 0x0c03727cu: goto P_0c03727c;
case 0x0c03727eu: goto P_0c03727e;
case 0x0c037280u: goto P_0c037280;
case 0x0c037282u: goto P_0c037282;
case 0x0c037284u: goto P_0c037284;
case 0x0c037286u: goto P_0c037286;
case 0x0c037288u: goto P_0c037288;
case 0x0c03728au: goto P_0c03728a;
case 0x0c03728cu: goto P_0c03728c;
case 0x0c03728eu: goto P_0c03728e;
case 0x0c037290u: goto P_0c037290;
case 0x0c037292u: goto P_0c037292;
case 0x0c037294u: goto P_0c037294;
case 0x0c037296u: goto P_0c037296;
case 0x0c037298u: goto P_0c037298;
case 0x0c03729au: goto P_0c03729a;
case 0x0c03729cu: goto P_0c03729c;
case 0x0c03729eu: goto P_0c03729e;
case 0x0c0372a0u: goto P_0c0372a0;
case 0x0c0372a2u: goto P_0c0372a2;
case 0x0c0372a4u: goto P_0c0372a4;
case 0x0c0372a6u: goto P_0c0372a6;
case 0x0c0372a8u: goto P_0c0372a8;
case 0x0c0372aau: goto P_0c0372aa;
case 0x0c0372acu: goto P_0c0372ac;
case 0x0c0372aeu: goto P_0c0372ae;
case 0x0c0372b0u: goto P_0c0372b0;
case 0x0c0372b2u: goto P_0c0372b2;
case 0x0c0372b4u: goto P_0c0372b4;
case 0x0c0372b6u: goto P_0c0372b6;
case 0x0c0372b8u: goto P_0c0372b8;
case 0x0c0372bau: goto P_0c0372ba;
case 0x0c0372bcu: goto P_0c0372bc;
case 0x0c0372beu: goto P_0c0372be;
case 0x0c0372c0u: goto P_0c0372c0;
case 0x0c0372c2u: goto P_0c0372c2;
case 0x0c0372c4u: goto P_0c0372c4;
case 0x0c0372c6u: goto P_0c0372c6;
case 0x0c0372c8u: goto P_0c0372c8;
case 0x0c0372cau: goto P_0c0372ca;
case 0x0c0372ccu: goto P_0c0372cc;
case 0x0c0372ceu: goto P_0c0372ce;
case 0x0c0372d0u: goto P_0c0372d0;
case 0x0c0372d2u: goto P_0c0372d2;
case 0x0c0372d4u: goto P_0c0372d4;
case 0x0c0372d6u: goto P_0c0372d6;
case 0x0c0372d8u: goto P_0c0372d8;
case 0x0c0372dau: goto P_0c0372da;
case 0x0c0372dcu: goto P_0c0372dc;
case 0x0c0372deu: goto P_0c0372de;
case 0x0c0372e0u: goto P_0c0372e0;
case 0x0c037502u: goto P_0c037502;
case 0x0c037504u: goto P_0c037504;
case 0x0c037506u: goto P_0c037506;
case 0x0c037508u: goto P_0c037508;
case 0x0c04631cu: goto P_0c04631c;
case 0x0c04631eu: goto P_0c04631e;
case 0x0c046320u: goto P_0c046320;
case 0x0c046322u: goto P_0c046322;
case 0x0c046324u: goto P_0c046324;
case 0x0c046326u: goto P_0c046326;
case 0x0c046328u: goto P_0c046328;
case 0x0c04632au: goto P_0c04632a;
case 0x0c04632cu: goto P_0c04632c;
case 0x0c04632eu: goto P_0c04632e;
case 0x0c046330u: goto P_0c046330;
case 0x0c046332u: goto P_0c046332;
case 0x0c046334u: goto P_0c046334;
case 0x0c046336u: goto P_0c046336;
case 0x0c046338u: goto P_0c046338;
case 0x0c04633au: goto P_0c04633a;
case 0x0c04633cu: goto P_0c04633c;
case 0x0c04633eu: goto P_0c04633e;
case 0x0c046340u: goto P_0c046340;
case 0x0c046342u: goto P_0c046342;
case 0x0c046344u: goto P_0c046344;
case 0x0c046346u: goto P_0c046346;
case 0x0c046348u: goto P_0c046348;
case 0x0c04634au: goto P_0c04634a;
case 0x0c04634cu: goto P_0c04634c;
case 0x0c04634eu: goto P_0c04634e;
case 0x0c046350u: goto P_0c046350;
case 0x0c046352u: goto P_0c046352;
case 0x0c046354u: goto P_0c046354;
case 0x0c046356u: goto P_0c046356;
case 0x0c046358u: goto P_0c046358;
case 0x0c04635au: goto P_0c04635a;
case 0x0c04635cu: goto P_0c04635c;
case 0x0c04635eu: goto P_0c04635e;
case 0x0c046360u: goto P_0c046360;
case 0x0c046362u: goto P_0c046362;
case 0x0c046364u: goto P_0c046364;
case 0x0c046366u: goto P_0c046366;
case 0x0c046368u: goto P_0c046368;
case 0x0c04636au: goto P_0c04636a;
case 0x0c04636cu: goto P_0c04636c;
case 0x0c04636eu: goto P_0c04636e;
case 0x0c046370u: goto P_0c046370;
case 0x0c046372u: goto P_0c046372;
case 0x0c046374u: goto P_0c046374;
case 0x0c046376u: goto P_0c046376;
case 0x0c046378u: goto P_0c046378;
case 0x0c04637au: goto P_0c04637a;
case 0x0c04637cu: goto P_0c04637c;
case 0x0c04637eu: goto P_0c04637e;
case 0x0c046380u: goto P_0c046380;
case 0x0c046382u: goto P_0c046382;
case 0x0c046384u: goto P_0c046384;
case 0x0c046386u: goto P_0c046386;
case 0x0c046388u: goto P_0c046388;
case 0x0c04638au: goto P_0c04638a;
case 0x0c04638cu: goto P_0c04638c;
case 0x0c04638eu: goto P_0c04638e;
case 0x0c046390u: goto P_0c046390;
case 0x0c046392u: goto P_0c046392;
case 0x0c046394u: goto P_0c046394;
case 0x0c046396u: goto P_0c046396;
case 0x0c046398u: goto P_0c046398;
case 0x0c04639au: goto P_0c04639a;
case 0x0c04639cu: goto P_0c04639c;
case 0x0c04639eu: goto P_0c04639e;
case 0x0c0463a0u: goto P_0c0463a0;
case 0x0c0463a2u: goto P_0c0463a2;
case 0x0c0463a4u: goto P_0c0463a4;
case 0x0c0463a6u: goto P_0c0463a6;
case 0x0c0463a8u: goto P_0c0463a8;
case 0x0c0463aau: goto P_0c0463aa;
case 0x0c0463acu: goto P_0c0463ac;
case 0x0c0463aeu: goto P_0c0463ae;
case 0x0c046c48u: goto P_0c046c48;
case 0x0c046c4au: goto P_0c046c4a;
case 0x0c046c4cu: goto P_0c046c4c;
case 0x0c046c4eu: goto P_0c046c4e;
case 0x0c046e54u: goto P_0c046e54;
case 0x0c046e56u: goto P_0c046e56;
case 0x0c046e58u: goto P_0c046e58;
case 0x0c046e5au: goto P_0c046e5a;
case 0x0c046e5cu: goto P_0c046e5c;
case 0x0c046e5eu: goto P_0c046e5e;
case 0x0c046e60u: goto P_0c046e60;
case 0x0c046e62u: goto P_0c046e62;
case 0x0c046e64u: goto P_0c046e64;
case 0x0c04b9fcu: goto P_0c04b9fc;
case 0x0c04b9feu: goto P_0c04b9fe;
case 0x0c04ba00u: goto P_0c04ba00;
case 0x0c04ba02u: goto P_0c04ba02;
case 0x0c04ba04u: goto P_0c04ba04;
case 0x0c04ba06u: goto P_0c04ba06;
case 0x0c04ba08u: goto P_0c04ba08;
case 0x0c04ba0au: goto P_0c04ba0a;
case 0x0c04ba0cu: goto P_0c04ba0c;
case 0x0c04ba0eu: goto P_0c04ba0e;
case 0x0c04ba10u: goto P_0c04ba10;
case 0x0c04ba12u: goto P_0c04ba12;
case 0x0c04ba14u: goto P_0c04ba14;
case 0x0c04ba16u: goto P_0c04ba16;
case 0x0c04ba18u: goto P_0c04ba18;
case 0x0c04ba1au: goto P_0c04ba1a;
case 0x0c04ba1cu: goto P_0c04ba1c;
case 0x0c04ba1eu: goto P_0c04ba1e;
case 0x0c04ba20u: goto P_0c04ba20;
case 0x0c04ba22u: goto P_0c04ba22;
case 0x0c04ba24u: goto P_0c04ba24;
case 0x0c04ba26u: goto P_0c04ba26;
case 0x0c04ba28u: goto P_0c04ba28;
case 0x0c04ba2au: goto P_0c04ba2a;
case 0x0c04ba2cu: goto P_0c04ba2c;
case 0x0c04ba2eu: goto P_0c04ba2e;
case 0x0c04ba30u: goto P_0c04ba30;
case 0x0c04ba32u: goto P_0c04ba32;
case 0x0c04ba34u: goto P_0c04ba34;
case 0x0c04ba36u: goto P_0c04ba36;
case 0x0c04ba38u: goto P_0c04ba38;
case 0x0c04ba3au: goto P_0c04ba3a;
case 0x0c04ba3cu: goto P_0c04ba3c;
case 0x0c04ba3eu: goto P_0c04ba3e;
case 0x0c04ba40u: goto P_0c04ba40;
case 0x0c04ba42u: goto P_0c04ba42;
case 0x0c04ba44u: goto P_0c04ba44;
case 0x0c04ba46u: goto P_0c04ba46;
case 0x0c04ba48u: goto P_0c04ba48;
case 0x0c04ba4au: goto P_0c04ba4a;
case 0x0c04ba4cu: goto P_0c04ba4c;
case 0x0c04ba4eu: goto P_0c04ba4e;
case 0x0c04c0f8u: goto P_0c04c0f8;
case 0x0c04c0fau: goto P_0c04c0fa;
case 0x0c04c0fcu: goto P_0c04c0fc;
case 0x0c04c60au: goto P_0c04c60a;
case 0x0c04c60cu: goto P_0c04c60c;
case 0x0c04c60eu: goto P_0c04c60e;
case 0x0c04c610u: goto P_0c04c610;
case 0x0c04c612u: goto P_0c04c612;
case 0x0c04c614u: goto P_0c04c614;
case 0x0c04c616u: goto P_0c04c616;
case 0x0c04c618u: goto P_0c04c618;
case 0x0c04c61au: goto P_0c04c61a;
case 0x0c04c61cu: goto P_0c04c61c;
case 0x0c053ddau: goto P_0c053dda;
case 0x0c053ddcu: goto P_0c053ddc;
case 0x0c053ddeu: goto P_0c053dde;
case 0x0c053de0u: goto P_0c053de0;
case 0x0c053de2u: goto P_0c053de2;
case 0x0c053de4u: goto P_0c053de4;
case 0x0c053de6u: goto P_0c053de6;
case 0x0c053de8u: goto P_0c053de8;
case 0x0c053deau: goto P_0c053dea;
case 0x0c053decu: goto P_0c053dec;
case 0x0c053deeu: goto P_0c053dee;
case 0x0c053df0u: goto P_0c053df0;
case 0x0c053df2u: goto P_0c053df2;
case 0x0c053df4u: goto P_0c053df4;
case 0x0c053df6u: goto P_0c053df6;
case 0x0c053df8u: goto P_0c053df8;
case 0x0c053dfau: goto P_0c053dfa;
case 0x0c053dfcu: goto P_0c053dfc;
case 0x0c053dfeu: goto P_0c053dfe;
case 0x0c053e00u: goto P_0c053e00;
case 0x0c053e02u: goto P_0c053e02;
case 0x0c053e04u: goto P_0c053e04;
case 0x0c053e06u: goto P_0c053e06;
case 0x0c053e08u: goto P_0c053e08;
case 0x0c053e0au: goto P_0c053e0a;
case 0x0c053e0cu: goto P_0c053e0c;
case 0x0c053e0eu: goto P_0c053e0e;
case 0x0c053e10u: goto P_0c053e10;
case 0x0c053e12u: goto P_0c053e12;
case 0x0c053e14u: goto P_0c053e14;
case 0x0c053e16u: goto P_0c053e16;
case 0x0c053e18u: goto P_0c053e18;
case 0x0c053e1au: goto P_0c053e1a;
case 0x0c053e1cu: goto P_0c053e1c;
case 0x0c053e1eu: goto P_0c053e1e;
case 0x0c053e20u: goto P_0c053e20;
case 0x0c053e22u: goto P_0c053e22;
case 0x0c053e24u: goto P_0c053e24;
case 0x0c053e26u: goto P_0c053e26;
case 0x0c053e28u: goto P_0c053e28;
case 0x0c053e2au: goto P_0c053e2a;
case 0x0c053e2cu: goto P_0c053e2c;
case 0x0c053e2eu: goto P_0c053e2e;
case 0x0c053e30u: goto P_0c053e30;
case 0x0c053e32u: goto P_0c053e32;
case 0x0c053e34u: goto P_0c053e34;
case 0x0c053e36u: goto P_0c053e36;
case 0x0c053e38u: goto P_0c053e38;
case 0x0c053e3au: goto P_0c053e3a;
case 0x0c053e3cu: goto P_0c053e3c;
case 0x0c053e3eu: goto P_0c053e3e;
case 0x0c053e40u: goto P_0c053e40;
case 0x0c053e42u: goto P_0c053e42;
case 0x0c053e44u: goto P_0c053e44;
case 0x0c053e46u: goto P_0c053e46;
case 0x0c053e48u: goto P_0c053e48;
case 0x0c053e4au: goto P_0c053e4a;
case 0x0c053e4cu: goto P_0c053e4c;
case 0x0c053e4eu: goto P_0c053e4e;
case 0x0c053e50u: goto P_0c053e50;
case 0x0c053e52u: goto P_0c053e52;
case 0x0c053e54u: goto P_0c053e54;
case 0x0c053e56u: goto P_0c053e56;
case 0x0c053e58u: goto P_0c053e58;
case 0x0c053e5au: goto P_0c053e5a;
case 0x0c053e5cu: goto P_0c053e5c;
case 0x0c053e5eu: goto P_0c053e5e;
case 0x0c053e60u: goto P_0c053e60;
case 0x0c053e62u: goto P_0c053e62;
case 0x0c053e64u: goto P_0c053e64;
case 0x0c053e66u: goto P_0c053e66;
case 0x0c053e68u: goto P_0c053e68;
case 0x0c053e6au: goto P_0c053e6a;
case 0x0c053e6cu: goto P_0c053e6c;
case 0x0c053e6eu: goto P_0c053e6e;
case 0x0c053e70u: goto P_0c053e70;
case 0x0c053e72u: goto P_0c053e72;
case 0x0c053e74u: goto P_0c053e74;
case 0x0c053e76u: goto P_0c053e76;
case 0x0c053e78u: goto P_0c053e78;
case 0x0c053e7au: goto P_0c053e7a;
case 0x0c053e7cu: goto P_0c053e7c;
case 0x0c053e7eu: goto P_0c053e7e;
case 0x0c053e80u: goto P_0c053e80;
case 0x0c053e82u: goto P_0c053e82;
case 0x0c053e84u: goto P_0c053e84;
case 0x0c053e86u: goto P_0c053e86;
case 0x0c053e88u: goto P_0c053e88;
case 0x0c053e8au: goto P_0c053e8a;
case 0x0c053e8cu: goto P_0c053e8c;
case 0x0c053e8eu: goto P_0c053e8e;
case 0x0c053e90u: goto P_0c053e90;
case 0x0c053e92u: goto P_0c053e92;
case 0x0c053e94u: goto P_0c053e94;
case 0x0c053e96u: goto P_0c053e96;
case 0x0c053e98u: goto P_0c053e98;
case 0x0c053e9au: goto P_0c053e9a;
case 0x0c053e9cu: goto P_0c053e9c;
case 0x0c053e9eu: goto P_0c053e9e;
case 0x0c053ea0u: goto P_0c053ea0;
case 0x0c053ea2u: goto P_0c053ea2;
case 0x0c053ea4u: goto P_0c053ea4;
case 0x0c053ea6u: goto P_0c053ea6;
case 0x0c053ea8u: goto P_0c053ea8;
case 0x0c053eaau: goto P_0c053eaa;
case 0x0c053eacu: goto P_0c053eac;
case 0x0c053eaeu: goto P_0c053eae;
case 0x0c053eb0u: goto P_0c053eb0;
case 0x0c053eb2u: goto P_0c053eb2;
case 0x0c054640u: goto P_0c054640;
case 0x0c054642u: goto P_0c054642;
case 0x0c054644u: goto P_0c054644;
case 0x0c054646u: goto P_0c054646;
case 0x0c054648u: goto P_0c054648;
case 0x0c05464au: goto P_0c05464a;
case 0x0c05464cu: goto P_0c05464c;
case 0x0c05464eu: goto P_0c05464e;
case 0x0c07caa8u: goto P_0c07caa8;
case 0x0c07caaau: goto P_0c07caaa;
case 0x0c07caacu: goto P_0c07caac;
case 0x0c07caaeu: goto P_0c07caae;
case 0x0c07cab0u: goto P_0c07cab0;
case 0x0c07cab2u: goto P_0c07cab2;
case 0x0c07cab4u: goto P_0c07cab4;
case 0x0c07cab6u: goto P_0c07cab6;
case 0x0c07cab8u: goto P_0c07cab8;
case 0x0c07cabau: goto P_0c07caba;
case 0x0c07cabcu: goto P_0c07cabc;
case 0x0c07cabeu: goto P_0c07cabe;
case 0x0c07cac0u: goto P_0c07cac0;
case 0x0c07cac2u: goto P_0c07cac2;
case 0x0c07cac4u: goto P_0c07cac4;
case 0x0c07cac6u: goto P_0c07cac6;
case 0x0c07cac8u: goto P_0c07cac8;
case 0x0c07cacau: goto P_0c07caca;
case 0x0c07caccu: goto P_0c07cacc;
case 0x0c07caceu: goto P_0c07cace;
case 0x0c07cad0u: goto P_0c07cad0;
case 0x0c07cad2u: goto P_0c07cad2;
case 0x0c07cad4u: goto P_0c07cad4;
case 0x0c07cad6u: goto P_0c07cad6;
case 0x0c07cad8u: goto P_0c07cad8;
case 0x0c07cadau: goto P_0c07cada;
case 0x0c07cadcu: goto P_0c07cadc;
case 0x0c07cadeu: goto P_0c07cade;
case 0x0c07cae0u: goto P_0c07cae0;
case 0x0c07cae2u: goto P_0c07cae2;
case 0x0c07cae4u: goto P_0c07cae4;
case 0x0c07cae6u: goto P_0c07cae6;
case 0x0c07cae8u: goto P_0c07cae8;
case 0x0c07caeau: goto P_0c07caea;
case 0x0c07caecu: goto P_0c07caec;
case 0x0c07caeeu: goto P_0c07caee;
case 0x0c07caf0u: goto P_0c07caf0;
case 0x0c07caf2u: goto P_0c07caf2;
case 0x0c07caf4u: goto P_0c07caf4;
case 0x0c07caf6u: goto P_0c07caf6;
case 0x0c07caf8u: goto P_0c07caf8;
case 0x0c07cafau: goto P_0c07cafa;
case 0x0c07cafcu: goto P_0c07cafc;
case 0x0c07cafeu: goto P_0c07cafe;
case 0x0c07cb00u: goto P_0c07cb00;
case 0x0c07cb02u: goto P_0c07cb02;
case 0x0c07cb04u: goto P_0c07cb04;
case 0x0c07cb06u: goto P_0c07cb06;
case 0x0c07cb08u: goto P_0c07cb08;
case 0x0c07cb0au: goto P_0c07cb0a;
case 0x0c07cb0cu: goto P_0c07cb0c;
case 0x0c07cb0eu: goto P_0c07cb0e;
case 0x0c07cb10u: goto P_0c07cb10;
case 0x0c07cb12u: goto P_0c07cb12;
case 0x0c07cb14u: goto P_0c07cb14;
case 0x0c07cb16u: goto P_0c07cb16;
case 0x0c07cb18u: goto P_0c07cb18;
case 0x0c07cb1au: goto P_0c07cb1a;
case 0x0c07cb1cu: goto P_0c07cb1c;
case 0x0c07cb1eu: goto P_0c07cb1e;
case 0x0c07cb20u: goto P_0c07cb20;
case 0x0c07cb22u: goto P_0c07cb22;
case 0x0c07cb24u: goto P_0c07cb24;
case 0x0c07cb26u: goto P_0c07cb26;
case 0x0c07cb28u: goto P_0c07cb28;
case 0x0c07cb2au: goto P_0c07cb2a;
case 0x0c07cb2cu: goto P_0c07cb2c;
case 0x0c07cb2eu: goto P_0c07cb2e;
case 0x0c07cb30u: goto P_0c07cb30;
case 0x0c07cb32u: goto P_0c07cb32;
case 0x0c07cb34u: goto P_0c07cb34;
case 0x0c07cb36u: goto P_0c07cb36;
case 0x0c07cb38u: goto P_0c07cb38;
case 0x0c07cb3au: goto P_0c07cb3a;
case 0x0c07cb3cu: goto P_0c07cb3c;
case 0x0c07cb3eu: goto P_0c07cb3e;
case 0x0c07cb40u: goto P_0c07cb40;
case 0x0c07cb42u: goto P_0c07cb42;
case 0x0c07cb44u: goto P_0c07cb44;
case 0x0c07cb46u: goto P_0c07cb46;
case 0x0c07cb48u: goto P_0c07cb48;
case 0x0c07cb4au: goto P_0c07cb4a;
case 0x0c07cb4cu: goto P_0c07cb4c;
case 0x0c07cb4eu: goto P_0c07cb4e;
case 0x0c07cb50u: goto P_0c07cb50;
case 0x0c07cb52u: goto P_0c07cb52;
case 0x0c07cb54u: goto P_0c07cb54;
case 0x0c07cb56u: goto P_0c07cb56;
case 0x0c07cb58u: goto P_0c07cb58;
case 0x0c07cb5au: goto P_0c07cb5a;
case 0x0c07cb5cu: goto P_0c07cb5c;
case 0x0c07cb5eu: goto P_0c07cb5e;
case 0x0c07cb60u: goto P_0c07cb60;
case 0x0c07cb62u: goto P_0c07cb62;
case 0x0c07cb64u: goto P_0c07cb64;
case 0x0c07cb66u: goto P_0c07cb66;
case 0x0c07cb68u: goto P_0c07cb68;
case 0x0c07cb6au: goto P_0c07cb6a;
case 0x0c07cb6cu: goto P_0c07cb6c;
case 0x0c07cb6eu: goto P_0c07cb6e;
case 0x0c07cb70u: goto P_0c07cb70;
case 0x0c07cb72u: goto P_0c07cb72;
case 0x0c07cb74u: goto P_0c07cb74;
case 0x0c07cb76u: goto P_0c07cb76;
case 0x0c07cb78u: goto P_0c07cb78;
case 0x0c07cb7au: goto P_0c07cb7a;
case 0x0c07cb7cu: goto P_0c07cb7c;
case 0x0c07cb7eu: goto P_0c07cb7e;
case 0x0c07cbc8u: goto P_0c07cbc8;
case 0x0c07cbcau: goto P_0c07cbca;
case 0x0c07cbccu: goto P_0c07cbcc;
case 0x0c07cbceu: goto P_0c07cbce;
case 0x0c07cbd0u: goto P_0c07cbd0;
case 0x0c07cbd2u: goto P_0c07cbd2;
case 0x0c07cbd4u: goto P_0c07cbd4;
case 0x0c07cbd6u: goto P_0c07cbd6;
case 0x0c07cbd8u: goto P_0c07cbd8;
case 0x0c07cbdau: goto P_0c07cbda;
case 0x0c07cbdcu: goto P_0c07cbdc;
case 0x0c07cbdeu: goto P_0c07cbde;
case 0x0c07cbe0u: goto P_0c07cbe0;
case 0x0c07cbe2u: goto P_0c07cbe2;
case 0x0c07cbe4u: goto P_0c07cbe4;
case 0x0c07cbe6u: goto P_0c07cbe6;
case 0x0c07cbe8u: goto P_0c07cbe8;
case 0x0c07cbeau: goto P_0c07cbea;
case 0x0c07cbecu: goto P_0c07cbec;
case 0x0c07cbeeu: goto P_0c07cbee;
case 0x0c07cbf0u: goto P_0c07cbf0;
case 0x0c07cbf2u: goto P_0c07cbf2;
case 0x0c07cbf4u: goto P_0c07cbf4;
case 0x0c07cbf6u: goto P_0c07cbf6;
case 0x0c07cbf8u: goto P_0c07cbf8;
case 0x0c07cbfau: goto P_0c07cbfa;
case 0x0c07cbfcu: goto P_0c07cbfc;
case 0x0c07cbfeu: goto P_0c07cbfe;
case 0x0c07cc00u: goto P_0c07cc00;
case 0x0c07cc02u: goto P_0c07cc02;
case 0x0c07cc04u: goto P_0c07cc04;
case 0x0c07cc06u: goto P_0c07cc06;
case 0x0c07cc08u: goto P_0c07cc08;
case 0x0c07cc0au: goto P_0c07cc0a;
case 0x0c07cc0cu: goto P_0c07cc0c;
case 0x0c07cc0eu: goto P_0c07cc0e;
case 0x0c07cc10u: goto P_0c07cc10;
case 0x0c07cc12u: goto P_0c07cc12;
case 0x0c07cc14u: goto P_0c07cc14;
case 0x0c07cc16u: goto P_0c07cc16;
case 0x0c07cc18u: goto P_0c07cc18;
case 0x0c07cc1au: goto P_0c07cc1a;
case 0x0c07cc1cu: goto P_0c07cc1c;
case 0x0c07cc1eu: goto P_0c07cc1e;
case 0x0c07cc20u: goto P_0c07cc20;
case 0x0c07cc22u: goto P_0c07cc22;
case 0x0c07cc24u: goto P_0c07cc24;
case 0x0c07cc26u: goto P_0c07cc26;
case 0x0c07cc28u: goto P_0c07cc28;
case 0x0c07cc2au: goto P_0c07cc2a;
case 0x0c07cc2cu: goto P_0c07cc2c;
case 0x0c07cc2eu: goto P_0c07cc2e;
case 0x0c07cc30u: goto P_0c07cc30;
case 0x0c07cc32u: goto P_0c07cc32;
case 0x0c07cc34u: goto P_0c07cc34;
case 0x0c07cc36u: goto P_0c07cc36;
case 0x0c07cc38u: goto P_0c07cc38;
case 0x0c07cc3au: goto P_0c07cc3a;
case 0x0c07cc3cu: goto P_0c07cc3c;
case 0x0c07cc3eu: goto P_0c07cc3e;
case 0x0c07cc40u: goto P_0c07cc40;
case 0x0c07cc42u: goto P_0c07cc42;
case 0x0c07cc44u: goto P_0c07cc44;
case 0x0c07cc46u: goto P_0c07cc46;
case 0x0c07cc48u: goto P_0c07cc48;
case 0x0c07cc4au: goto P_0c07cc4a;
case 0x0c07cc4cu: goto P_0c07cc4c;
case 0x0c07cc4eu: goto P_0c07cc4e;
case 0x0c07cc50u: goto P_0c07cc50;
case 0x0c07cc52u: goto P_0c07cc52;
case 0x0c07cc54u: goto P_0c07cc54;
case 0x0c07cc56u: goto P_0c07cc56;
case 0x0c07cc58u: goto P_0c07cc58;
case 0x0c07cc5au: goto P_0c07cc5a;
case 0x0c07cc5cu: goto P_0c07cc5c;
case 0x0c07cc5eu: goto P_0c07cc5e;
case 0x0c07cc60u: goto P_0c07cc60;
case 0x0c07cc62u: goto P_0c07cc62;
case 0x0c07cc64u: goto P_0c07cc64;
case 0x0c07cc66u: goto P_0c07cc66;
case 0x0c07cc68u: goto P_0c07cc68;
case 0x0c07cc6au: goto P_0c07cc6a;
case 0x0c07cc6cu: goto P_0c07cc6c;
case 0x0c07cc6eu: goto P_0c07cc6e;
case 0x0c07cc70u: goto P_0c07cc70;
case 0x0c07cc72u: goto P_0c07cc72;
case 0x0c07cc74u: goto P_0c07cc74;
case 0x0c07cc76u: goto P_0c07cc76;
case 0x0c07cc78u: goto P_0c07cc78;
case 0x0c07cc7au: goto P_0c07cc7a;
case 0x0c07cc7cu: goto P_0c07cc7c;
case 0x0c07cc7eu: goto P_0c07cc7e;
case 0x0c07cc80u: goto P_0c07cc80;
case 0x0c07cc82u: goto P_0c07cc82;
case 0x0c07cc84u: goto P_0c07cc84;
case 0x0c07cc86u: goto P_0c07cc86;
case 0x0c07cc88u: goto P_0c07cc88;
case 0x0c07cc8au: goto P_0c07cc8a;
case 0x0c07cc8cu: goto P_0c07cc8c;
case 0x0c07cc8eu: goto P_0c07cc8e;
case 0x0c07cc90u: goto P_0c07cc90;
case 0x0c07cc92u: goto P_0c07cc92;
case 0x0c07cc94u: goto P_0c07cc94;
case 0x0c07cc96u: goto P_0c07cc96;
case 0x0c07cc98u: goto P_0c07cc98;
case 0x0c07cc9au: goto P_0c07cc9a;
case 0x0c07cc9cu: goto P_0c07cc9c;
case 0x0c07cc9eu: goto P_0c07cc9e;
case 0x0c07cca0u: goto P_0c07cca0;
case 0x0c07cca2u: goto P_0c07cca2;
case 0x0c07cca4u: goto P_0c07cca4;
case 0x0c07cca6u: goto P_0c07cca6;
case 0x0c07cca8u: goto P_0c07cca8;
case 0x0c07ccaau: goto P_0c07ccaa;
case 0x0c07ccacu: goto P_0c07ccac;
case 0x0c07ccaeu: goto P_0c07ccae;
case 0x0c07ccb0u: goto P_0c07ccb0;
case 0x0c07ccb2u: goto P_0c07ccb2;
case 0x0c07ccb4u: goto P_0c07ccb4;
case 0x0c07ccb6u: goto P_0c07ccb6;
case 0x0c07ccb8u: goto P_0c07ccb8;
case 0x0c07ccbau: goto P_0c07ccba;
case 0x0c07ccbcu: goto P_0c07ccbc;
case 0x0c07ccbeu: goto P_0c07ccbe;
case 0x0c07ccc0u: goto P_0c07ccc0;
case 0x0c07ccc2u: goto P_0c07ccc2;
case 0x0c07ccc4u: goto P_0c07ccc4;
case 0x0c07ccc6u: goto P_0c07ccc6;
case 0x0c07ccc8u: goto P_0c07ccc8;
case 0x0c07cccau: goto P_0c07ccca;
case 0x0c07ccccu: goto P_0c07cccc;
case 0x0c07ccceu: goto P_0c07ccce;
case 0x0c07ccd0u: goto P_0c07ccd0;
case 0x0c07ccd2u: goto P_0c07ccd2;
case 0x0c07ccd4u: goto P_0c07ccd4;
case 0x0c07ccd6u: goto P_0c07ccd6;
case 0x0c07ccd8u: goto P_0c07ccd8;
case 0x0c07ccdau: goto P_0c07ccda;
case 0x0c07ccdcu: goto P_0c07ccdc;
case 0x0c07ccdeu: goto P_0c07ccde;
case 0x0c07cce0u: goto P_0c07cce0;
case 0x0c07cce2u: goto P_0c07cce2;
case 0x0c07cce4u: goto P_0c07cce4;
case 0x0c07cce6u: goto P_0c07cce6;
case 0x0c07cce8u: goto P_0c07cce8;
case 0x0c07cceau: goto P_0c07ccea;
case 0x0c07ccecu: goto P_0c07ccec;
case 0x0c07cceeu: goto P_0c07ccee;
case 0x0c07ccf0u: goto P_0c07ccf0;
case 0x0c07ccf2u: goto P_0c07ccf2;
case 0x0c07ccf4u: goto P_0c07ccf4;
case 0x0c07ccf6u: goto P_0c07ccf6;
case 0x0c07ccf8u: goto P_0c07ccf8;
case 0x0c07ccfau: goto P_0c07ccfa;
case 0x0c07ccfcu: goto P_0c07ccfc;
case 0x0c07ccfeu: goto P_0c07ccfe;
case 0x0c07cd00u: goto P_0c07cd00;
case 0x0c07cd02u: goto P_0c07cd02;
case 0x0c07cd04u: goto P_0c07cd04;
case 0x0c07cd06u: goto P_0c07cd06;
case 0x0c07cd08u: goto P_0c07cd08;
case 0x0c07cd0au: goto P_0c07cd0a;
case 0x0c07cd0cu: goto P_0c07cd0c;
case 0x0c07cd0eu: goto P_0c07cd0e;
case 0x0c07cd10u: goto P_0c07cd10;
case 0x0c07cd12u: goto P_0c07cd12;
case 0x0c07cd14u: goto P_0c07cd14;
case 0x0c07cd16u: goto P_0c07cd16;
case 0x0c07cd18u: goto P_0c07cd18;
case 0x0c07cd1au: goto P_0c07cd1a;
case 0x0c07cd1cu: goto P_0c07cd1c;
case 0x0c07cd1eu: goto P_0c07cd1e;
case 0x0c07cd20u: goto P_0c07cd20;
case 0x0c07cd22u: goto P_0c07cd22;
case 0x0c07cd24u: goto P_0c07cd24;
case 0x0c07cd26u: goto P_0c07cd26;
case 0x0c07cd28u: goto P_0c07cd28;
case 0x0c07cd80u: goto P_0c07cd80;
case 0x0c07cd82u: goto P_0c07cd82;
case 0x0c07cd84u: goto P_0c07cd84;
case 0x0c07cd86u: goto P_0c07cd86;
case 0x0c07cd88u: goto P_0c07cd88;
case 0x0c07cd8au: goto P_0c07cd8a;
case 0x0c07cd8cu: goto P_0c07cd8c;
case 0x0c07cd8eu: goto P_0c07cd8e;
case 0x0c07cd90u: goto P_0c07cd90;
case 0x0c07cd92u: goto P_0c07cd92;
case 0x0c07cd94u: goto P_0c07cd94;
case 0x0c07cd96u: goto P_0c07cd96;
case 0x0c07cd98u: goto P_0c07cd98;
case 0x0c07cd9au: goto P_0c07cd9a;
case 0x0c07cd9cu: goto P_0c07cd9c;
case 0x0c07cd9eu: goto P_0c07cd9e;
case 0x0c07cda0u: goto P_0c07cda0;
case 0x0c07cda2u: goto P_0c07cda2;
case 0x0c07cda4u: goto P_0c07cda4;
case 0x0c07cda6u: goto P_0c07cda6;
case 0x0c07cda8u: goto P_0c07cda8;
case 0x0c07cdaau: goto P_0c07cdaa;
case 0x0c07cdacu: goto P_0c07cdac;
case 0x0c07cdaeu: goto P_0c07cdae;
case 0x0c07cdb0u: goto P_0c07cdb0;
case 0x0c07cdb2u: goto P_0c07cdb2;
case 0x0c07cdb4u: goto P_0c07cdb4;
case 0x0c07cdb6u: goto P_0c07cdb6;
case 0x0c07cdb8u: goto P_0c07cdb8;
case 0x0c07cdbau: goto P_0c07cdba;
case 0x0c07cdbcu: goto P_0c07cdbc;
case 0x0c07cdbeu: goto P_0c07cdbe;
case 0x0c07cdc0u: goto P_0c07cdc0;
case 0x0c07cdc2u: goto P_0c07cdc2;
case 0x0c07cdc4u: goto P_0c07cdc4;
case 0x0c07cdc6u: goto P_0c07cdc6;
case 0x0c07cdc8u: goto P_0c07cdc8;
case 0x0c07cdcau: goto P_0c07cdca;
case 0x0c07cdccu: goto P_0c07cdcc;
case 0x0c07cdceu: goto P_0c07cdce;
case 0x0c07cdd0u: goto P_0c07cdd0;
case 0x0c07cdd2u: goto P_0c07cdd2;
case 0x0c07cdd4u: goto P_0c07cdd4;
case 0x0c07cdd6u: goto P_0c07cdd6;
case 0x0c07cdd8u: goto P_0c07cdd8;
case 0x0c07cddau: goto P_0c07cdda;
case 0x0c07cddcu: goto P_0c07cddc;
case 0x0c07cddeu: goto P_0c07cdde;
case 0x0c07cde0u: goto P_0c07cde0;
case 0x0c07cde2u: goto P_0c07cde2;
case 0x0c07cde4u: goto P_0c07cde4;
case 0x0c07cde6u: goto P_0c07cde6;
case 0x0c07cde8u: goto P_0c07cde8;
case 0x0c07cdeau: goto P_0c07cdea;
case 0x0c07cdecu: goto P_0c07cdec;
case 0x0c07cdeeu: goto P_0c07cdee;
case 0x0c07cdf0u: goto P_0c07cdf0;
case 0x0c07cdf2u: goto P_0c07cdf2;
case 0x0c07cdf4u: goto P_0c07cdf4;
case 0x0c07cdf6u: goto P_0c07cdf6;
case 0x0c07cdf8u: goto P_0c07cdf8;
case 0x0c07cdfau: goto P_0c07cdfa;
case 0x0c07cdfcu: goto P_0c07cdfc;
case 0x0c07cdfeu: goto P_0c07cdfe;
case 0x0c07ce00u: goto P_0c07ce00;
case 0x0c07ce02u: goto P_0c07ce02;
case 0x0c07ce04u: goto P_0c07ce04;
case 0x0c07ce06u: goto P_0c07ce06;
case 0x0c07ce08u: goto P_0c07ce08;
case 0x0c07ce0au: goto P_0c07ce0a;
case 0x0c07ce0cu: goto P_0c07ce0c;
case 0x0c07ce0eu: goto P_0c07ce0e;
case 0x0c07ce10u: goto P_0c07ce10;
case 0x0c07ce12u: goto P_0c07ce12;
case 0x0c07ce14u: goto P_0c07ce14;
case 0x0c07ce16u: goto P_0c07ce16;
case 0x0c07ce18u: goto P_0c07ce18;
case 0x0c07ce1au: goto P_0c07ce1a;
case 0x0c07ce1cu: goto P_0c07ce1c;
case 0x0c07ce1eu: goto P_0c07ce1e;
case 0x0c07ce20u: goto P_0c07ce20;
case 0x0c07ce22u: goto P_0c07ce22;
case 0x0c07ce24u: goto P_0c07ce24;
case 0x0c07ce26u: goto P_0c07ce26;
case 0x0c07ce28u: goto P_0c07ce28;
case 0x0c07ce2au: goto P_0c07ce2a;
case 0x0c07ce2cu: goto P_0c07ce2c;
case 0x0c07ce2eu: goto P_0c07ce2e;
case 0x0c07ce30u: goto P_0c07ce30;
case 0x0c07ce32u: goto P_0c07ce32;
case 0x0c07ce34u: goto P_0c07ce34;
case 0x0c07ce36u: goto P_0c07ce36;
case 0x0c07ce38u: goto P_0c07ce38;
case 0x0c07ce3au: goto P_0c07ce3a;
case 0x0c07ce3cu: goto P_0c07ce3c;
case 0x0c07ce3eu: goto P_0c07ce3e;
case 0x0c07ce40u: goto P_0c07ce40;
case 0x0c07ce42u: goto P_0c07ce42;
case 0x0c07ce44u: goto P_0c07ce44;
case 0x0c07ce46u: goto P_0c07ce46;
case 0x0c07ce48u: goto P_0c07ce48;
case 0x0c07ce4au: goto P_0c07ce4a;
case 0x0c07ce4cu: goto P_0c07ce4c;
case 0x0c07ce4eu: goto P_0c07ce4e;
case 0x0c07ce50u: goto P_0c07ce50;
case 0x0c07ce52u: goto P_0c07ce52;
case 0x0c07ce54u: goto P_0c07ce54;
case 0x0c07ce56u: goto P_0c07ce56;
case 0x0c07ce58u: goto P_0c07ce58;
case 0x0c07ce5au: goto P_0c07ce5a;
case 0x0c07ce5cu: goto P_0c07ce5c;
case 0x0c07ce5eu: goto P_0c07ce5e;
case 0x0c07ce60u: goto P_0c07ce60;
case 0x0c07ce62u: goto P_0c07ce62;
case 0x0c07ce64u: goto P_0c07ce64;
case 0x0c07ce66u: goto P_0c07ce66;
case 0x0c07ce68u: goto P_0c07ce68;
case 0x0c07ce6au: goto P_0c07ce6a;
case 0x0c07ce6cu: goto P_0c07ce6c;
case 0x0c07ce6eu: goto P_0c07ce6e;
case 0x0c07ce70u: goto P_0c07ce70;
case 0x0c07ce72u: goto P_0c07ce72;
case 0x0c07ce74u: goto P_0c07ce74;
case 0x0c07ce76u: goto P_0c07ce76;
case 0x0c07ce78u: goto P_0c07ce78;
case 0x0c07ce7au: goto P_0c07ce7a;
case 0x0c07ce7cu: goto P_0c07ce7c;
case 0x0c07ce7eu: goto P_0c07ce7e;
case 0x0c07ce80u: goto P_0c07ce80;
case 0x0c07ce82u: goto P_0c07ce82;
case 0x0c07ce84u: goto P_0c07ce84;
case 0x0c07ce86u: goto P_0c07ce86;
case 0x0c07ce88u: goto P_0c07ce88;
case 0x0c07ce8au: goto P_0c07ce8a;
case 0x0c07ce8cu: goto P_0c07ce8c;
case 0x0c07ce8eu: goto P_0c07ce8e;
case 0x0c07ce90u: goto P_0c07ce90;
case 0x0c07ce92u: goto P_0c07ce92;
case 0x0c07ce94u: goto P_0c07ce94;
case 0x0c07ce96u: goto P_0c07ce96;
case 0x0c07ce98u: goto P_0c07ce98;
case 0x0c07ce9au: goto P_0c07ce9a;
case 0x0c07ce9cu: goto P_0c07ce9c;
case 0x0c07ce9eu: goto P_0c07ce9e;
case 0x0c07cea0u: goto P_0c07cea0;
case 0x0c07cea2u: goto P_0c07cea2;
case 0x0c07cea4u: goto P_0c07cea4;
case 0x0c07cea6u: goto P_0c07cea6;
case 0x0c07cea8u: goto P_0c07cea8;
case 0x0c07ceaau: goto P_0c07ceaa;
case 0x0c07ceacu: goto P_0c07ceac;
case 0x0c07ceaeu: goto P_0c07ceae;
case 0x0c07ceb0u: goto P_0c07ceb0;
case 0x0c07ceb2u: goto P_0c07ceb2;
case 0x0c07ceb4u: goto P_0c07ceb4;
case 0x0c07ceb6u: goto P_0c07ceb6;
case 0x0c07ceb8u: goto P_0c07ceb8;
case 0x0c07cebau: goto P_0c07ceba;
case 0x0c07cebcu: goto P_0c07cebc;
case 0x0c07cebeu: goto P_0c07cebe;
case 0x0c07cec0u: goto P_0c07cec0;
case 0x0c07cec2u: goto P_0c07cec2;
case 0x0c07cec4u: goto P_0c07cec4;
case 0x0c07cec6u: goto P_0c07cec6;
case 0x0c07cec8u: goto P_0c07cec8;
case 0x0c07cecau: goto P_0c07ceca;
case 0x0c07ceccu: goto P_0c07cecc;
case 0x0c08a8c2u: goto P_0c08a8c2;
case 0x0c08a8c4u: goto P_0c08a8c4;
case 0x0c08a8c6u: goto P_0c08a8c6;
case 0x0c08a8c8u: goto P_0c08a8c8;
case 0x0c08a8cau: goto P_0c08a8ca;
case 0x0c08a8ccu: goto P_0c08a8cc;
case 0x0c08a8ceu: goto P_0c08a8ce;
case 0x0c08a8d0u: goto P_0c08a8d0;
case 0x0c08a942u: goto P_0c08a942;
case 0x0c08a944u: goto P_0c08a944;
case 0x0c08a946u: goto P_0c08a946;
case 0x0c08a948u: goto P_0c08a948;
case 0x0c08a94au: goto P_0c08a94a;
case 0x0c08a94cu: goto P_0c08a94c;
case 0x0c08a94eu: goto P_0c08a94e;
case 0x0c08a950u: goto P_0c08a950;
case 0x0c08a952u: goto P_0c08a952;
case 0x0c08a954u: goto P_0c08a954;
case 0x0c08a956u: goto P_0c08a956;
case 0x0c08a958u: goto P_0c08a958;
case 0x0c08a95au: goto P_0c08a95a;
case 0x0c08a95cu: goto P_0c08a95c;
case 0x0c08a95eu: goto P_0c08a95e;
case 0x0c08a960u: goto P_0c08a960;
case 0x0c08a962u: goto P_0c08a962;
case 0x0c08a964u: goto P_0c08a964;
case 0x0c08a966u: goto P_0c08a966;
case 0x0c08a968u: goto P_0c08a968;
case 0x0c08a96au: goto P_0c08a96a;
case 0x0c08a96cu: goto P_0c08a96c;
case 0x0c08a96eu: goto P_0c08a96e;
case 0x0c08a970u: goto P_0c08a970;
case 0x0c08a972u: goto P_0c08a972;
case 0x0c08a974u: goto P_0c08a974;
case 0x0c08a976u: goto P_0c08a976;
case 0x0c08a978u: goto P_0c08a978;
case 0x0c08a97au: goto P_0c08a97a;
case 0x0c08a97cu: goto P_0c08a97c;
case 0x0c08a97eu: goto P_0c08a97e;
case 0x0c08a980u: goto P_0c08a980;
case 0x0c08a982u: goto P_0c08a982;
case 0x0c08a984u: goto P_0c08a984;
case 0x0c08a986u: goto P_0c08a986;
case 0x0c08a988u: goto P_0c08a988;
case 0x0c08a98au: goto P_0c08a98a;
case 0x0c08a98cu: goto P_0c08a98c;
case 0x0c08a98eu: goto P_0c08a98e;
case 0x0c08a990u: goto P_0c08a990;
case 0x0c08a992u: goto P_0c08a992;
case 0x0c08a994u: goto P_0c08a994;
case 0x0c08a996u: goto P_0c08a996;
case 0x0c08a998u: goto P_0c08a998;
case 0x0c08a99au: goto P_0c08a99a;
case 0x0c08a99cu: goto P_0c08a99c;
case 0x0c08a99eu: goto P_0c08a99e;
case 0x0c08a9a0u: goto P_0c08a9a0;
case 0x0c08a9a2u: goto P_0c08a9a2;
case 0x0c08a9a4u: goto P_0c08a9a4;
case 0x0c08a9a6u: goto P_0c08a9a6;
case 0x0c08a9a8u: goto P_0c08a9a8;
case 0x0c08a9aau: goto P_0c08a9aa;
case 0x0c08a9acu: goto P_0c08a9ac;
case 0x0c08a9aeu: goto P_0c08a9ae;
case 0x0c08a9b0u: goto P_0c08a9b0;
case 0x0c08a9b2u: goto P_0c08a9b2;
case 0x0c08a9b4u: goto P_0c08a9b4;
case 0x0c08a9b6u: goto P_0c08a9b6;
case 0x0c08a9b8u: goto P_0c08a9b8;
case 0x0c08a9bau: goto P_0c08a9ba;
case 0x0c08a9bcu: goto P_0c08a9bc;
case 0x0c08a9beu: goto P_0c08a9be;
case 0x0c08a9c0u: goto P_0c08a9c0;
case 0x0c08a9c2u: goto P_0c08a9c2;
case 0x0c08a9c4u: goto P_0c08a9c4;
case 0x0c08a9c6u: goto P_0c08a9c6;
case 0x0c08a9c8u: goto P_0c08a9c8;
case 0x0c08a9cau: goto P_0c08a9ca;
case 0x0c08a9ccu: goto P_0c08a9cc;
case 0x0c08a9ceu: goto P_0c08a9ce;
case 0x0c08a9d0u: goto P_0c08a9d0;
case 0x0c08a9d2u: goto P_0c08a9d2;
case 0x0c08a9d4u: goto P_0c08a9d4;
case 0x0c08a9d6u: goto P_0c08a9d6;
case 0x0c08a9d8u: goto P_0c08a9d8;
case 0x0c08a9dau: goto P_0c08a9da;
case 0x0c08a9dcu: goto P_0c08a9dc;
case 0x0c08a9deu: goto P_0c08a9de;
case 0x0c08a9e0u: goto P_0c08a9e0;
case 0x0c08a9e2u: goto P_0c08a9e2;
case 0x0c08a9e4u: goto P_0c08a9e4;
case 0x0c08a9e6u: goto P_0c08a9e6;
case 0x0c08a9e8u: goto P_0c08a9e8;
case 0x0c08a9eau: goto P_0c08a9ea;
case 0x0c08a9ecu: goto P_0c08a9ec;
case 0x0c08a9eeu: goto P_0c08a9ee;
case 0x0c08a9f0u: goto P_0c08a9f0;
case 0x0c08a9f2u: goto P_0c08a9f2;
case 0x0c08a9f4u: goto P_0c08a9f4;
case 0x0c0a302eu: goto P_0c0a302e;
case 0x0c0a3030u: goto P_0c0a3030;
case 0x0c0a3032u: goto P_0c0a3032;
case 0x0c0a3034u: goto P_0c0a3034;
case 0x0c0a3036u: goto P_0c0a3036;
case 0x0c0a3038u: goto P_0c0a3038;
case 0x0c0a303au: goto P_0c0a303a;
case 0x0c0a303cu: goto P_0c0a303c;
case 0x0c0a303eu: goto P_0c0a303e;
case 0x0c0a3040u: goto P_0c0a3040;
case 0x0c0a3042u: goto P_0c0a3042;
case 0x0c0a3044u: goto P_0c0a3044;
case 0x0c0a3046u: goto P_0c0a3046;
case 0x0c0a3048u: goto P_0c0a3048;
case 0x0c0a304au: goto P_0c0a304a;
case 0x0c0a304cu: goto P_0c0a304c;
case 0x0c0a304eu: goto P_0c0a304e;
case 0x0c0a3050u: goto P_0c0a3050;
case 0x0c0a3052u: goto P_0c0a3052;
case 0x0c0a3054u: goto P_0c0a3054;
case 0x0c0a3056u: goto P_0c0a3056;
case 0x0c0c1f32u: goto P_0c0c1f32;
case 0x0c0c1f34u: goto P_0c0c1f34;
case 0x0c0c1f94u: goto P_0c0c1f94;
case 0x0c0c1f96u: goto P_0c0c1f96;
case 0x0c0c2706u: goto P_0c0c2706;
case 0x0c0c2708u: goto P_0c0c2708;
case 0x0c0c270au: goto P_0c0c270a;
case 0x0c0c270cu: goto P_0c0c270c;
case 0x0c0c270eu: goto P_0c0c270e;
case 0x0c0c2710u: goto P_0c0c2710;
case 0x0c0c2712u: goto P_0c0c2712;
case 0x0c0c2714u: goto P_0c0c2714;
case 0x0c0c2716u: goto P_0c0c2716;
case 0x0c0c2718u: goto P_0c0c2718;
case 0x0c0c271au: goto P_0c0c271a;
case 0x0c0c271cu: goto P_0c0c271c;
case 0x0c0c271eu: goto P_0c0c271e;
case 0x0c0c2720u: goto P_0c0c2720;
case 0x0c0c2722u: goto P_0c0c2722;
case 0x0c0c2724u: goto P_0c0c2724;
case 0x0c0c2726u: goto P_0c0c2726;
case 0x0c0c2728u: goto P_0c0c2728;
case 0x0c0c272au: goto P_0c0c272a;
case 0x0c0c272cu: goto P_0c0c272c;
case 0x0c0c272eu: goto P_0c0c272e;
case 0x0c0c2730u: goto P_0c0c2730;
case 0x0c0c2732u: goto P_0c0c2732;
case 0x0c0c2734u: goto P_0c0c2734;
case 0x0c0c2736u: goto P_0c0c2736;
case 0x0c0c2738u: goto P_0c0c2738;
case 0x0c0c273au: goto P_0c0c273a;
case 0x0c0c273cu: goto P_0c0c273c;
case 0x0c0c273eu: goto P_0c0c273e;
case 0x0c0c2740u: goto P_0c0c2740;
case 0x0c0c2742u: goto P_0c0c2742;
case 0x0c0c2744u: goto P_0c0c2744;
case 0x0c0c2746u: goto P_0c0c2746;
case 0x0c0c2748u: goto P_0c0c2748;
case 0x0c0c274au: goto P_0c0c274a;
case 0x0c0c274cu: goto P_0c0c274c;
case 0x0c0c274eu: goto P_0c0c274e;
case 0x0c0c2750u: goto P_0c0c2750;
case 0x0c0c2752u: goto P_0c0c2752;
case 0x0c0c2754u: goto P_0c0c2754;
case 0x0c0c2756u: goto P_0c0c2756;
case 0x0c0c2758u: goto P_0c0c2758;
case 0x0c0c275au: goto P_0c0c275a;
case 0x0c0c275cu: goto P_0c0c275c;
case 0x0c0c275eu: goto P_0c0c275e;
case 0x0c0c2760u: goto P_0c0c2760;
case 0x0c0c2762u: goto P_0c0c2762;
case 0x0c0c2764u: goto P_0c0c2764;
case 0x0c0c2766u: goto P_0c0c2766;
case 0x0c0c2768u: goto P_0c0c2768;
case 0x0c0c276au: goto P_0c0c276a;
case 0x0c0c276cu: goto P_0c0c276c;
case 0x0c0c276eu: goto P_0c0c276e;
case 0x0c0c2770u: goto P_0c0c2770;
case 0x0c0c2772u: goto P_0c0c2772;
case 0x0c0c2774u: goto P_0c0c2774;
case 0x0c0c2776u: goto P_0c0c2776;
case 0x0c0c2778u: goto P_0c0c2778;
case 0x0c0c277au: goto P_0c0c277a;
case 0x0c0c277cu: goto P_0c0c277c;
case 0x0c0c277eu: goto P_0c0c277e;
case 0x0c0c2780u: goto P_0c0c2780;
case 0x0c0c2782u: goto P_0c0c2782;
case 0x0c0c2784u: goto P_0c0c2784;
case 0x0c0c2786u: goto P_0c0c2786;
case 0x0c0c2788u: goto P_0c0c2788;
case 0x0c0c278au: goto P_0c0c278a;
case 0x0c0c278cu: goto P_0c0c278c;
case 0x0c0c278eu: goto P_0c0c278e;
case 0x0c0c2790u: goto P_0c0c2790;
case 0x0c0c2792u: goto P_0c0c2792;
case 0x0c0c2794u: goto P_0c0c2794;
case 0x0c0c2796u: goto P_0c0c2796;
case 0x0c0c2798u: goto P_0c0c2798;
case 0x0c0c279au: goto P_0c0c279a;
case 0x0c0c279cu: goto P_0c0c279c;
case 0x0c0c279eu: goto P_0c0c279e;
case 0x0c0c27a0u: goto P_0c0c27a0;
case 0x0c0c27a2u: goto P_0c0c27a2;
case 0x0c0c27a4u: goto P_0c0c27a4;
case 0x0c0c27a6u: goto P_0c0c27a6;
case 0x0c0c27a8u: goto P_0c0c27a8;
case 0x0c0c4e34u: goto P_0c0c4e34;
case 0x0c0c4e36u: goto P_0c0c4e36;
case 0x0c0c4e38u: goto P_0c0c4e38;
case 0x0c0c4e3au: goto P_0c0c4e3a;
case 0x0c0c4e3cu: goto P_0c0c4e3c;
case 0x0c0c4e3eu: goto P_0c0c4e3e;
case 0x0c0c4e40u: goto P_0c0c4e40;
case 0x0c0c4e42u: goto P_0c0c4e42;
case 0x0c0c4e44u: goto P_0c0c4e44;
case 0x0c0c4e46u: goto P_0c0c4e46;
case 0x0c0c4e48u: goto P_0c0c4e48;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0371c2: /* original 4f22, guest PC 0x0c0371c2 */
if(!s->budget--) { s->failed_pc=0x0c0371c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0371c4;
P_0c0371c4: /* original 2342, guest PC 0x0c0371c4 */
if(!s->budget--) { s->failed_pc=0x0c0371c4u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0371c6;
P_0c0371c6: /* original d216, guest PC 0x0c0371c6 */
if(!s->budget--) { s->failed_pc=0x0c0371c6u; return 0; }
r[2]=read(ram,0x0c037220u,4);
goto P_0c0371c8;
P_0c0371c8: /* original 2242, guest PC 0x0c0371c8 */
if(!s->budget--) { s->failed_pc=0x0c0371c8u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0371ca;
P_0c0371ca: /* original d116, guest PC 0x0c0371ca */
if(!s->budget--) { s->failed_pc=0x0c0371cau; return 0; }
r[1]=read(ram,0x0c037224u,4);
goto P_0c0371cc;
P_0c0371cc: /* original 2142, guest PC 0x0c0371cc */
if(!s->budget--) { s->failed_pc=0x0c0371ccu; return 0; }
write(ram,r[1],r[4],4);
goto P_0c0371ce;
P_0c0371ce: /* original d30e, guest PC 0x0c0371ce */
if(!s->budget--) { s->failed_pc=0x0c0371ceu; return 0; }
r[3]=read(ram,0x0c037208u,4);
goto P_0c0371d0;
P_0c0371d0: /* original d40b, guest PC 0x0c0371d0 */
if(!s->budget--) { s->failed_pc=0x0c0371d0u; return 0; }
r[4]=read(ram,0x0c037200u,4);
goto P_0c0371d2;
P_0c0371d2: /* original 9614, guest PC 0x0c0371d2 */
if(!s->budget--) { s->failed_pc=0x0c0371d2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0371feu,2);
goto P_0c0371d4;
P_0c0371d4: /* original 430b, guest PC 0x0c0371d4 */
if(!s->budget--) { s->failed_pc=0x0c0371d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0371d8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0371d8u) { target=s->pc; goto dispatch; }
goto P_0c0371d8;
P_0c0371d6: /* original 0009, guest PC 0x0c0371d6 */
if(!s->budget--) { s->failed_pc=0x0c0371d6u; return 0; }
goto P_0c0371d8;
P_0c0371d8: /* original d215, guest PC 0x0c0371d8 */
if(!s->budget--) { s->failed_pc=0x0c0371d8u; return 0; }
r[2]=read(ram,0x0c037230u,4);
goto P_0c0371da;
P_0c0371da: /* original e40f, guest PC 0x0c0371da */
if(!s->budget--) { s->failed_pc=0x0c0371dau; return 0; }
r[4]=0x0000000fu;
goto P_0c0371dc;
P_0c0371dc: /* original d613, guest PC 0x0c0371dc */
if(!s->budget--) { s->failed_pc=0x0c0371dcu; return 0; }
r[6]=read(ram,0x0c03722cu,4);
goto P_0c0371de;
P_0c0371de: /* original e501, guest PC 0x0c0371de */
if(!s->budget--) { s->failed_pc=0x0c0371deu; return 0; }
r[5]=0x00000001u;
goto P_0c0371e0;
P_0c0371e0: /* original d711, guest PC 0x0c0371e0 */
if(!s->budget--) { s->failed_pc=0x0c0371e0u; return 0; }
r[7]=read(ram,0x0c037228u,4);
goto P_0c0371e2;
P_0c0371e2: /* original 422b, guest PC 0x0c0371e2 */
if(!s->budget--) { s->failed_pc=0x0c0371e2u; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0371e4: /* original 4f26, guest PC 0x0c0371e4 */
if(!s->budget--) { s->failed_pc=0x0c0371e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0371e6u,s,ram);
P_0c037248: /* original 4f22, guest PC 0x0c037248 */
if(!s->budget--) { s->failed_pc=0x0c037248u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03724a;
P_0c03724a: /* original e660, guest PC 0x0c03724a */
if(!s->budget--) { s->failed_pc=0x0c03724au; return 0; }
r[6]=0x00000060u;
goto P_0c03724c;
P_0c03724c: /* original e500, guest PC 0x0c03724c */
if(!s->budget--) { s->failed_pc=0x0c03724cu; return 0; }
r[5]=0x00000000u;
goto P_0c03724e;
P_0c03724e: /* original 7f94, guest PC 0x0c03724e */
if(!s->budget--) { s->failed_pc=0x0c03724eu; return 0; }
r[15]+=0xffffff94u;
goto P_0c037250;
P_0c037250: /* original 2f42, guest PC 0x0c037250 */
if(!s->budget--) { s->failed_pc=0x0c037250u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c037252;
P_0c037252: /* original 64f3, guest PC 0x0c037252 */
if(!s->budget--) { s->failed_pc=0x0c037252u; return 0; }
r[4]=r[15];
goto P_0c037254;
P_0c037254: /* original d342, guest PC 0x0c037254 */
if(!s->budget--) { s->failed_pc=0x0c037254u; return 0; }
r[3]=read(ram,0x0c037360u,4);
goto P_0c037256;
P_0c037256: /* original 430b, guest PC 0x0c037256 */
if(!s->budget--) { s->failed_pc=0x0c037256u; return 0; }
target=r[3];
r[16]=code_base|0x0c03725au;
r[4]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03725au) { target=s->pc; goto dispatch; }
goto P_0c03725a;
P_0c037258: /* original 740c, guest PC 0x0c037258 */
if(!s->budget--) { s->failed_pc=0x0c037258u; return 0; }
r[4]+=0x0000000cu;
goto P_0c03725a;
P_0c03725a: /* original d243, guest PC 0x0c03725a */
if(!s->budget--) { s->failed_pc=0x0c03725au; return 0; }
r[2]=read(ram,0x0c037368u,4);
goto P_0c03725c;
P_0c03725c: /* original e610, guest PC 0x0c03725c */
if(!s->budget--) { s->failed_pc=0x0c03725cu; return 0; }
r[6]=0x00000010u;
goto P_0c03725e;
P_0c03725e: /* original d541, guest PC 0x0c03725e */
if(!s->budget--) { s->failed_pc=0x0c03725eu; return 0; }
r[5]=read(ram,0x0c037364u,4);
goto P_0c037260;
P_0c037260: /* original 64f3, guest PC 0x0c037260 */
if(!s->budget--) { s->failed_pc=0x0c037260u; return 0; }
r[4]=r[15];
goto P_0c037262;
P_0c037262: /* original 420b, guest PC 0x0c037262 */
if(!s->budget--) { s->failed_pc=0x0c037262u; return 0; }
target=r[2];
r[16]=code_base|0x0c037266u;
r[4]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037266u) { target=s->pc; goto dispatch; }
goto P_0c037266;
P_0c037264: /* original 740c, guest PC 0x0c037264 */
if(!s->budget--) { s->failed_pc=0x0c037264u; return 0; }
r[4]+=0x0000000cu;
goto P_0c037266;
P_0c037266: /* original d340, guest PC 0x0c037266 */
if(!s->budget--) { s->failed_pc=0x0c037266u; return 0; }
r[3]=read(ram,0x0c037368u,4);
goto P_0c037268;
P_0c037268: /* original e620, guest PC 0x0c037268 */
if(!s->budget--) { s->failed_pc=0x0c037268u; return 0; }
r[6]=0x00000020u;
goto P_0c03726a;
P_0c03726a: /* original d540, guest PC 0x0c03726a */
if(!s->budget--) { s->failed_pc=0x0c03726au; return 0; }
r[5]=read(ram,0x0c03736cu,4);
goto P_0c03726c;
P_0c03726c: /* original 64f3, guest PC 0x0c03726c */
if(!s->budget--) { s->failed_pc=0x0c03726cu; return 0; }
r[4]=r[15];
goto P_0c03726e;
P_0c03726e: /* original 430b, guest PC 0x0c03726e */
if(!s->budget--) { s->failed_pc=0x0c03726eu; return 0; }
target=r[3];
r[16]=code_base|0x0c037272u;
r[4]+=0x0000001eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037272u) { target=s->pc; goto dispatch; }
goto P_0c037272;
P_0c037270: /* original 741e, guest PC 0x0c037270 */
if(!s->budget--) { s->failed_pc=0x0c037270u; return 0; }
r[4]+=0x0000001eu;
goto P_0c037272;
P_0c037272: /* original d240, guest PC 0x0c037272 */
if(!s->budget--) { s->failed_pc=0x0c037272u; return 0; }
r[2]=read(ram,0x0c037374u,4);
goto P_0c037274;
P_0c037274: /* original e610, guest PC 0x0c037274 */
if(!s->budget--) { s->failed_pc=0x0c037274u; return 0; }
r[6]=0x00000010u;
goto P_0c037276;
P_0c037276: /* original d53e, guest PC 0x0c037276 */
if(!s->budget--) { s->failed_pc=0x0c037276u; return 0; }
r[5]=read(ram,0x0c037370u,4);
goto P_0c037278;
P_0c037278: /* original 64f3, guest PC 0x0c037278 */
if(!s->budget--) { s->failed_pc=0x0c037278u; return 0; }
r[4]=r[15];
goto P_0c03727a;
P_0c03727a: /* original 420b, guest PC 0x0c03727a */
if(!s->budget--) { s->failed_pc=0x0c03727au; return 0; }
target=r[2];
r[16]=code_base|0x0c03727eu;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03727eu) { target=s->pc; goto dispatch; }
goto P_0c03727e;
P_0c03727c: /* original 7440, guest PC 0x0c03727c */
if(!s->budget--) { s->failed_pc=0x0c03727cu; return 0; }
r[4]+=0x00000040u;
goto P_0c03727e;
P_0c03727e: /* original d33e, guest PC 0x0c03727e */
if(!s->budget--) { s->failed_pc=0x0c03727eu; return 0; }
r[3]=read(ram,0x0c037378u,4);
goto P_0c037280;
P_0c037280: /* original e050, guest PC 0x0c037280 */
if(!s->budget--) { s->failed_pc=0x0c037280u; return 0; }
r[0]=0x00000050u;
goto P_0c037282;
P_0c037282: /* original e401, guest PC 0x0c037282 */
if(!s->budget--) { s->failed_pc=0x0c037282u; return 0; }
r[4]=0x00000001u;
goto P_0c037284;
P_0c037284: /* original 65f3, guest PC 0x0c037284 */
if(!s->budget--) { s->failed_pc=0x0c037284u; return 0; }
r[5]=r[15];
goto P_0c037286;
P_0c037286: /* original 0f36, guest PC 0x0c037286 */
if(!s->budget--) { s->failed_pc=0x0c037286u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c037288;
P_0c037288: /* original e054, guest PC 0x0c037288 */
if(!s->budget--) { s->failed_pc=0x0c037288u; return 0; }
r[0]=0x00000054u;
goto P_0c03728a;
P_0c03728a: /* original d23c, guest PC 0x0c03728a */
if(!s->budget--) { s->failed_pc=0x0c03728au; return 0; }
r[2]=read(ram,0x0c03737cu,4);
goto P_0c03728c;
P_0c03728c: /* original 0f26, guest PC 0x0c03728c */
if(!s->budget--) { s->failed_pc=0x0c03728cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c03728e;
P_0c03728e: /* original e058, guest PC 0x0c03728e */
if(!s->budget--) { s->failed_pc=0x0c03728eu; return 0; }
r[0]=0x00000058u;
goto P_0c037290;
P_0c037290: /* original 0f45, guest PC 0x0c037290 */
if(!s->budget--) { s->failed_pc=0x0c037290u; return 0; }
write(ram,r[15]+r[0],r[4],2);
goto P_0c037292;
P_0c037292: /* original e05a, guest PC 0x0c037292 */
if(!s->budget--) { s->failed_pc=0x0c037292u; return 0; }
r[0]=0x0000005au;
goto P_0c037294;
P_0c037294: /* original 0f45, guest PC 0x0c037294 */
if(!s->budget--) { s->failed_pc=0x0c037294u; return 0; }
write(ram,r[15]+r[0],r[4],2);
goto P_0c037296;
P_0c037296: /* original e05c, guest PC 0x0c037296 */
if(!s->budget--) { s->failed_pc=0x0c037296u; return 0; }
r[0]=0x0000005cu;
goto P_0c037298;
P_0c037298: /* original e400, guest PC 0x0c037298 */
if(!s->budget--) { s->failed_pc=0x0c037298u; return 0; }
r[4]=0x00000000u;
goto P_0c03729a;
P_0c03729a: /* original 0f46, guest PC 0x0c03729a */
if(!s->budget--) { s->failed_pc=0x0c03729au; return 0; }
write(ram,r[15]+r[0],r[4],4);
goto P_0c03729c;
P_0c03729c: /* original e060, guest PC 0x0c03729c */
if(!s->budget--) { s->failed_pc=0x0c03729cu; return 0; }
r[0]=0x00000060u;
goto P_0c03729e;
P_0c03729e: /* original 0f45, guest PC 0x0c03729e */
if(!s->budget--) { s->failed_pc=0x0c03729eu; return 0; }
write(ram,r[15]+r[0],r[4],2);
goto P_0c0372a0;
P_0c0372a0: /* original e064, guest PC 0x0c0372a0 */
if(!s->budget--) { s->failed_pc=0x0c0372a0u; return 0; }
r[0]=0x00000064u;
goto P_0c0372a2;
P_0c0372a2: /* original 63f2, guest PC 0x0c0372a2 */
if(!s->budget--) { s->failed_pc=0x0c0372a2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0372a4;
P_0c0372a4: /* original 0f36, guest PC 0x0c0372a4 */
if(!s->budget--) { s->failed_pc=0x0c0372a4u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0372a6;
P_0c0372a6: /* original e068, guest PC 0x0c0372a6 */
if(!s->budget--) { s->failed_pc=0x0c0372a6u; return 0; }
r[0]=0x00000068u;
goto P_0c0372a8;
P_0c0372a8: /* original 9253, guest PC 0x0c0372a8 */
if(!s->budget--) { s->failed_pc=0x0c0372a8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c037352u,2);
goto P_0c0372aa;
P_0c0372aa: /* original 0f26, guest PC 0x0c0372aa */
if(!s->budget--) { s->failed_pc=0x0c0372aau; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0372ac;
P_0c0372ac: /* original d434, guest PC 0x0c0372ac */
if(!s->budget--) { s->failed_pc=0x0c0372acu; return 0; }
r[4]=read(ram,0x0c037380u,4);
goto P_0c0372ae;
P_0c0372ae: /* original d335, guest PC 0x0c0372ae */
if(!s->budget--) { s->failed_pc=0x0c0372aeu; return 0; }
r[3]=read(ram,0x0c037384u,4);
goto P_0c0372b0;
P_0c0372b0: /* original 430b, guest PC 0x0c0372b0 */
if(!s->budget--) { s->failed_pc=0x0c0372b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0372b4u;
r[5]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0372b4u) { target=s->pc; goto dispatch; }
goto P_0c0372b4;
P_0c0372b2: /* original 750c, guest PC 0x0c0372b2 */
if(!s->budget--) { s->failed_pc=0x0c0372b2u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0372b4;
P_0c0372b4: /* original 6403, guest PC 0x0c0372b4 */
if(!s->budget--) { s->failed_pc=0x0c0372b4u; return 0; }
r[4]=r[0];
goto P_0c0372b6;
P_0c0372b6: /* original 4411, guest PC 0x0c0372b6 */
if(!s->budget--) { s->failed_pc=0x0c0372b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0372b8;
P_0c0372b8: /* original 8b0f, guest PC 0x0c0372b8 */
if(!s->budget--) { s->failed_pc=0x0c0372b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0372da; }
goto P_0c0372ba;
P_0c0372ba: /* original 64f3, guest PC 0x0c0372ba */
if(!s->budget--) { s->failed_pc=0x0c0372bau; return 0; }
r[4]=r[15];
goto P_0c0372bc;
P_0c0372bc: /* original b121, guest PC 0x0c0372bc */
if(!s->budget--) { s->failed_pc=0x0c0372bcu; return 0; }
target=0x0c037502u; r[16]=code_base|0x0c0372c0u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0372c0u) { target=s->pc; goto dispatch; }
goto P_0c0372c0;
P_0c0372be: /* original 7404, guest PC 0x0c0372be */
if(!s->budget--) { s->failed_pc=0x0c0372beu; return 0; }
r[4]+=0x00000004u;
goto P_0c0372c0;
P_0c0372c0: /* original d731, guest PC 0x0c0372c0 */
if(!s->budget--) { s->failed_pc=0x0c0372c0u; return 0; }
r[7]=read(ram,0x0c037388u,4);
goto P_0c0372c2;
P_0c0372c2: /* original 2f76, guest PC 0x0c0372c2 */
if(!s->budget--) { s->failed_pc=0x0c0372c2u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0372c4;
P_0c0372c4: /* original e70c, guest PC 0x0c0372c4 */
if(!s->budget--) { s->failed_pc=0x0c0372c4u; return 0; }
r[7]=0x0000000cu;
goto P_0c0372c6;
P_0c0372c6: /* original 63f3, guest PC 0x0c0372c6 */
if(!s->budget--) { s->failed_pc=0x0c0372c6u; return 0; }
r[3]=r[15];
goto P_0c0372c8;
P_0c0372c8: /* original 7308, guest PC 0x0c0372c8 */
if(!s->budget--) { s->failed_pc=0x0c0372c8u; return 0; }
r[3]+=0x00000008u;
goto P_0c0372ca;
P_0c0372ca: /* original 2f36, guest PC 0x0c0372ca */
if(!s->budget--) { s->failed_pc=0x0c0372cau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0372cc;
P_0c0372cc: /* original d522, guest PC 0x0c0372cc */
if(!s->budget--) { s->failed_pc=0x0c0372ccu; return 0; }
r[5]=read(ram,0x0c037358u,4);
goto P_0c0372ce;
P_0c0372ce: /* original d62c, guest PC 0x0c0372ce */
if(!s->budget--) { s->failed_pc=0x0c0372ceu; return 0; }
r[6]=read(ram,0x0c037380u,4);
goto P_0c0372d0;
P_0c0372d0: /* original d22e, guest PC 0x0c0372d0 */
if(!s->budget--) { s->failed_pc=0x0c0372d0u; return 0; }
r[2]=read(ram,0x0c03738cu,4);
goto P_0c0372d2;
P_0c0372d2: /* original 420b, guest PC 0x0c0372d2 */
if(!s->budget--) { s->failed_pc=0x0c0372d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0372d6u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0372d6u) { target=s->pc; goto dispatch; }
goto P_0c0372d6;
P_0c0372d4: /* original e400, guest PC 0x0c0372d4 */
if(!s->budget--) { s->failed_pc=0x0c0372d4u; return 0; }
r[4]=0x00000000u;
goto P_0c0372d6;
P_0c0372d6: /* original 6403, guest PC 0x0c0372d6 */
if(!s->budget--) { s->failed_pc=0x0c0372d6u; return 0; }
r[4]=r[0];
goto P_0c0372d8;
P_0c0372d8: /* original 7f08, guest PC 0x0c0372d8 */
if(!s->budget--) { s->failed_pc=0x0c0372d8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0372da;
P_0c0372da: /* original 7f6c, guest PC 0x0c0372da */
if(!s->budget--) { s->failed_pc=0x0c0372dau; return 0; }
r[15]+=0x0000006cu;
goto P_0c0372dc;
P_0c0372dc: /* original 4f26, guest PC 0x0c0372dc */
if(!s->budget--) { s->failed_pc=0x0c0372dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0372de;
P_0c0372de: /* original 000b, guest PC 0x0c0372de */
if(!s->budget--) { s->failed_pc=0x0c0372deu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0372e0: /* original 6043, guest PC 0x0c0372e0 */
if(!s->budget--) { s->failed_pc=0x0c0372e0u; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c0372e2u,s,ram);
P_0c037502: /* original 2fe6, guest PC 0x0c037502 */
if(!s->budget--) { s->failed_pc=0x0c037502u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c037504;
P_0c037504: /* original ee00, guest PC 0x0c037504 */
if(!s->budget--) { s->failed_pc=0x0c037504u; return 0; }
r[14]=0x00000000u;
goto P_0c037506;
P_0c037506: /* original 2fd6, guest PC 0x0c037506 */
if(!s->budget--) { s->failed_pc=0x0c037506u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c037508;
P_0c037508: /* original ed0a, guest PC 0x0c037508 */
if(!s->budget--) { s->failed_pc=0x0c037508u; return 0; }
r[13]=0x0000000au;
return vf3_matrix_family(0x0c03750au,s,ram);
P_0c04631c: /* original 0002, guest PC 0x0c04631c */
if(!s->budget--) { s->failed_pc=0x0c04631cu; return 0; }
r[0]=r[17];
goto P_0c04631e;
P_0c04631e: /* original 2fe6, guest PC 0x0c04631e */
if(!s->budget--) { s->failed_pc=0x0c04631eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046320;
P_0c046320: /* original 4f22, guest PC 0x0c046320 */
if(!s->budget--) { s->failed_pc=0x0c046320u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046322;
P_0c046322: /* original 4009, guest PC 0x0c046322 */
if(!s->budget--) { s->failed_pc=0x0c046322u; return 0; }
r[0]>>=2;
goto P_0c046324;
P_0c046324: /* original 4009, guest PC 0x0c046324 */
if(!s->budget--) { s->failed_pc=0x0c046324u; return 0; }
r[0]>>=2;
goto P_0c046326;
P_0c046326: /* original 7fec, guest PC 0x0c046326 */
if(!s->budget--) { s->failed_pc=0x0c046326u; return 0; }
r[15]+=0xffffffecu;
goto P_0c046328;
P_0c046328: /* original c90f, guest PC 0x0c046328 */
if(!s->budget--) { s->failed_pc=0x0c046328u; return 0; }
r[0]&=15u;
goto P_0c04632a;
P_0c04632a: /* original 1f43, guest PC 0x0c04632a */
if(!s->budget--) { s->failed_pc=0x0c04632au; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c04632c;
P_0c04632c: /* original 1f52, guest PC 0x0c04632c */
if(!s->budget--) { s->failed_pc=0x0c04632cu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c04632e;
P_0c04632e: /* original 1f61, guest PC 0x0c04632e */
if(!s->budget--) { s->failed_pc=0x0c04632eu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c046330;
P_0c046330: /* original 2f72, guest PC 0x0c046330 */
if(!s->budget--) { s->failed_pc=0x0c046330u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c046332;
P_0c046332: /* original 1f04, guest PC 0x0c046332 */
if(!s->budget--) { s->failed_pc=0x0c046332u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c046334;
P_0c046334: /* original 0002, guest PC 0x0c046334 */
if(!s->budget--) { s->failed_pc=0x0c046334u; return 0; }
r[0]=r[17];
goto P_0c046336;
P_0c046336: /* original 937c, guest PC 0x0c046336 */
if(!s->budget--) { s->failed_pc=0x0c046336u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c046432u,2);
goto P_0c046338;
P_0c046338: /* original 2039, guest PC 0x0c046338 */
if(!s->budget--) { s->failed_pc=0x0c046338u; return 0; }
r[0]&=r[3];
goto P_0c04633a;
P_0c04633a: /* original cbf0, guest PC 0x0c04633a */
if(!s->budget--) { s->failed_pc=0x0c04633au; return 0; }
r[0]|=240u;
goto P_0c04633c;
P_0c04633c: /* original 400e, guest PC 0x0c04633c */
if(!s->budget--) { s->failed_pc=0x0c04633cu; return 0; }
r[17]=r[0];
goto P_0c04633e;
P_0c04633e: /* original d13e, guest PC 0x0c04633e */
if(!s->budget--) { s->failed_pc=0x0c04633eu; return 0; }
r[1]=read(ram,0x0c046438u,4);
goto P_0c046340;
P_0c046340: /* original e400, guest PC 0x0c046340 */
if(!s->budget--) { s->failed_pc=0x0c046340u; return 0; }
r[4]=0x00000000u;
goto P_0c046342;
P_0c046342: /* original 52f1, guest PC 0x0c046342 */
if(!s->budget--) { s->failed_pc=0x0c046342u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c046344;
P_0c046344: /* original 2122, guest PC 0x0c046344 */
if(!s->budget--) { s->failed_pc=0x0c046344u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c046346;
P_0c046346: /* original d33d, guest PC 0x0c046346 */
if(!s->budget--) { s->failed_pc=0x0c046346u; return 0; }
r[3]=read(ram,0x0c04643cu,4);
goto P_0c046348;
P_0c046348: /* original 2342, guest PC 0x0c046348 */
if(!s->budget--) { s->failed_pc=0x0c046348u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c04634a;
P_0c04634a: /* original d23d, guest PC 0x0c04634a */
if(!s->budget--) { s->failed_pc=0x0c04634au; return 0; }
r[2]=read(ram,0x0c046440u,4);
goto P_0c04634c;
P_0c04634c: /* original 2242, guest PC 0x0c04634c */
if(!s->budget--) { s->failed_pc=0x0c04634cu; return 0; }
write(ram,r[2],r[4],4);
goto P_0c04634e;
P_0c04634e: /* original d13d, guest PC 0x0c04634e */
if(!s->budget--) { s->failed_pc=0x0c04634eu; return 0; }
r[1]=read(ram,0x0c046444u,4);
goto P_0c046350;
P_0c046350: /* original 2142, guest PC 0x0c046350 */
if(!s->budget--) { s->failed_pc=0x0c046350u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c046352;
P_0c046352: /* original d33d, guest PC 0x0c046352 */
if(!s->budget--) { s->failed_pc=0x0c046352u; return 0; }
r[3]=read(ram,0x0c046448u,4);
goto P_0c046354;
P_0c046354: /* original d23d, guest PC 0x0c046354 */
if(!s->budget--) { s->failed_pc=0x0c046354u; return 0; }
r[2]=read(ram,0x0c04644cu,4);
goto P_0c046356;
P_0c046356: /* original 420b, guest PC 0x0c046356 */
if(!s->budget--) { s->failed_pc=0x0c046356u; return 0; }
target=r[2];
r[16]=code_base|0x0c04635au;
write(ram,r[3],r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04635au) { target=s->pc; goto dispatch; }
goto P_0c04635a;
P_0c046358: /* original 2342, guest PC 0x0c046358 */
if(!s->budget--) { s->failed_pc=0x0c046358u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c04635a;
P_0c04635a: /* original d13d, guest PC 0x0c04635a */
if(!s->budget--) { s->failed_pc=0x0c04635au; return 0; }
r[1]=read(ram,0x0c046450u,4);
goto P_0c04635c;
P_0c04635c: /* original 410b, guest PC 0x0c04635c */
if(!s->budget--) { s->failed_pc=0x0c04635cu; return 0; }
target=r[1];
r[16]=code_base|0x0c046360u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046360u) { target=s->pc; goto dispatch; }
goto P_0c046360;
P_0c04635e: /* original 0009, guest PC 0x0c04635e */
if(!s->budget--) { s->failed_pc=0x0c04635eu; return 0; }
goto P_0c046360;
P_0c046360: /* original d33c, guest PC 0x0c046360 */
if(!s->budget--) { s->failed_pc=0x0c046360u; return 0; }
r[3]=read(ram,0x0c046454u,4);
goto P_0c046362;
P_0c046362: /* original 55f2, guest PC 0x0c046362 */
if(!s->budget--) { s->failed_pc=0x0c046362u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c046364;
P_0c046364: /* original 56f1, guest PC 0x0c046364 */
if(!s->budget--) { s->failed_pc=0x0c046364u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c046366;
P_0c046366: /* original 430b, guest PC 0x0c046366 */
if(!s->budget--) { s->failed_pc=0x0c046366u; return 0; }
target=r[3];
r[16]=code_base|0x0c04636au;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04636au) { target=s->pc; goto dispatch; }
goto P_0c04636a;
P_0c046368: /* original 54f3, guest PC 0x0c046368 */
if(!s->budget--) { s->failed_pc=0x0c046368u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c04636a;
P_0c04636a: /* original d53c, guest PC 0x0c04636a */
if(!s->budget--) { s->failed_pc=0x0c04636au; return 0; }
r[5]=read(ram,0x0c04645cu,4);
goto P_0c04636c;
P_0c04636c: /* original 6e03, guest PC 0x0c04636c */
if(!s->budget--) { s->failed_pc=0x0c04636cu; return 0; }
r[14]=r[0];
goto P_0c04636e;
P_0c04636e: /* original 9461, guest PC 0x0c04636e */
if(!s->budget--) { s->failed_pc=0x0c04636eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c046434u,2);
goto P_0c046370;
P_0c046370: /* original e700, guest PC 0x0c046370 */
if(!s->budget--) { s->failed_pc=0x0c046370u; return 0; }
r[7]=0x00000000u;
goto P_0c046372;
P_0c046372: /* original d33b, guest PC 0x0c046372 */
if(!s->budget--) { s->failed_pc=0x0c046372u; return 0; }
r[3]=read(ram,0x0c046460u,4);
goto P_0c046374;
P_0c046374: /* original d238, guest PC 0x0c046374 */
if(!s->budget--) { s->failed_pc=0x0c046374u; return 0; }
r[2]=read(ram,0x0c046458u,4);
goto P_0c046376;
P_0c046376: /* original 430b, guest PC 0x0c046376 */
if(!s->budget--) { s->failed_pc=0x0c046376u; return 0; }
target=r[3];
r[16]=code_base|0x0c04637au;
tmp=read(ram,r[2],4);
r[6]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04637au) { target=s->pc; goto dispatch; }
goto P_0c04637a;
P_0c046378: /* original 6622, guest PC 0x0c046378 */
if(!s->budget--) { s->failed_pc=0x0c046378u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c04637a;
P_0c04637a: /* original d23a, guest PC 0x0c04637a */
if(!s->budget--) { s->failed_pc=0x0c04637au; return 0; }
r[2]=read(ram,0x0c046464u,4);
goto P_0c04637c;
P_0c04637c: /* original 2ee8, guest PC 0x0c04637c */
if(!s->budget--) { s->failed_pc=0x0c04637cu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04637e;
P_0c04637e: /* original 8f06, guest PC 0x0c04637e */
if(!s->budget--) { s->failed_pc=0x0c04637eu; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[0],4);
if(!cond) { goto P_0c04638e; }
goto P_0c046382;
P_0c046380: /* original 2202, guest PC 0x0c046380 */
if(!s->budget--) { s->failed_pc=0x0c046380u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c046382;
P_0c046382: /* original 61f2, guest PC 0x0c046382 */
if(!s->budget--) { s->failed_pc=0x0c046382u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c046384;
P_0c046384: /* original 2118, guest PC 0x0c046384 */
if(!s->budget--) { s->failed_pc=0x0c046384u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c046386;
P_0c046386: /* original 8902, guest PC 0x0c046386 */
if(!s->budget--) { s->failed_pc=0x0c046386u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04638e; }
goto P_0c046388;
P_0c046388: /* original 63f2, guest PC 0x0c046388 */
if(!s->budget--) { s->failed_pc=0x0c046388u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04638a;
P_0c04638a: /* original 430b, guest PC 0x0c04638a */
if(!s->budget--) { s->failed_pc=0x0c04638au; return 0; }
target=r[3];
r[16]=code_base|0x0c04638eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04638eu) { target=s->pc; goto dispatch; }
goto P_0c04638e;
P_0c04638c: /* original 0009, guest PC 0x0c04638c */
if(!s->budget--) { s->failed_pc=0x0c04638cu; return 0; }
goto P_0c04638e;
P_0c04638e: /* original d136, guest PC 0x0c04638e */
if(!s->budget--) { s->failed_pc=0x0c04638eu; return 0; }
r[1]=read(ram,0x0c046468u,4);
goto P_0c046390;
P_0c046390: /* original e201, guest PC 0x0c046390 */
if(!s->budget--) { s->failed_pc=0x0c046390u; return 0; }
r[2]=0x00000001u;
goto P_0c046392;
P_0c046392: /* original 0302, guest PC 0x0c046392 */
if(!s->budget--) { s->failed_pc=0x0c046392u; return 0; }
r[3]=r[17];
goto P_0c046394;
P_0c046394: /* original 2122, guest PC 0x0c046394 */
if(!s->budget--) { s->failed_pc=0x0c046394u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c046396;
P_0c046396: /* original 50f4, guest PC 0x0c046396 */
if(!s->budget--) { s->failed_pc=0x0c046396u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c046398;
P_0c046398: /* original 924b, guest PC 0x0c046398 */
if(!s->budget--) { s->failed_pc=0x0c046398u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c046432u,2);
goto P_0c04639a;
P_0c04639a: /* original c90f, guest PC 0x0c04639a */
if(!s->budget--) { s->failed_pc=0x0c04639au; return 0; }
r[0]&=15u;
goto P_0c04639c;
P_0c04639c: /* original 4008, guest PC 0x0c04639c */
if(!s->budget--) { s->failed_pc=0x0c04639cu; return 0; }
r[0]<<=2;
goto P_0c04639e;
P_0c04639e: /* original 2329, guest PC 0x0c04639e */
if(!s->budget--) { s->failed_pc=0x0c04639eu; return 0; }
r[3]&=r[2];
goto P_0c0463a0;
P_0c0463a0: /* original 4008, guest PC 0x0c0463a0 */
if(!s->budget--) { s->failed_pc=0x0c0463a0u; return 0; }
r[0]<<=2;
goto P_0c0463a2;
P_0c0463a2: /* original 203b, guest PC 0x0c0463a2 */
if(!s->budget--) { s->failed_pc=0x0c0463a2u; return 0; }
r[0]|=r[3];
goto P_0c0463a4;
P_0c0463a4: /* original 400e, guest PC 0x0c0463a4 */
if(!s->budget--) { s->failed_pc=0x0c0463a4u; return 0; }
r[17]=r[0];
goto P_0c0463a6;
P_0c0463a6: /* original 7f14, guest PC 0x0c0463a6 */
if(!s->budget--) { s->failed_pc=0x0c0463a6u; return 0; }
r[15]+=0x00000014u;
goto P_0c0463a8;
P_0c0463a8: /* original 60e3, guest PC 0x0c0463a8 */
if(!s->budget--) { s->failed_pc=0x0c0463a8u; return 0; }
r[0]=r[14];
goto P_0c0463aa;
P_0c0463aa: /* original 4f26, guest PC 0x0c0463aa */
if(!s->budget--) { s->failed_pc=0x0c0463aau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0463ac;
P_0c0463ac: /* original 000b, guest PC 0x0c0463ac */
if(!s->budget--) { s->failed_pc=0x0c0463acu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0463ae: /* original 6ef6, guest PC 0x0c0463ae */
if(!s->budget--) { s->failed_pc=0x0c0463aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0463b0u,s,ram);
P_0c046c48: /* original 2fe6, guest PC 0x0c046c48 */
if(!s->budget--) { s->failed_pc=0x0c046c48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c4a;
P_0c046c4a: /* original 6e43, guest PC 0x0c046c4a */
if(!s->budget--) { s->failed_pc=0x0c046c4au; return 0; }
r[14]=r[4];
goto P_0c046c4c;
P_0c046c4c: /* original 2fd6, guest PC 0x0c046c4c */
if(!s->budget--) { s->failed_pc=0x0c046c4cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c4e;
P_0c046c4e: /* original 6d53, guest PC 0x0c046c4e */
if(!s->budget--) { s->failed_pc=0x0c046c4eu; return 0; }
r[13]=r[5];
return vf3_matrix_family(0x0c046c50u,s,ram);
P_0c046e54: /* original 2fe6, guest PC 0x0c046e54 */
if(!s->budget--) { s->failed_pc=0x0c046e54u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046e56;
P_0c046e56: /* original 6e53, guest PC 0x0c046e56 */
if(!s->budget--) { s->failed_pc=0x0c046e56u; return 0; }
r[14]=r[5];
goto P_0c046e58;
P_0c046e58: /* original 2fd6, guest PC 0x0c046e58 */
if(!s->budget--) { s->failed_pc=0x0c046e58u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046e5a;
P_0c046e5a: /* original e04c, guest PC 0x0c046e5a */
if(!s->budget--) { s->failed_pc=0x0c046e5au; return 0; }
r[0]=0x0000004cu;
goto P_0c046e5c;
P_0c046e5c: /* original 2fc6, guest PC 0x0c046e5c */
if(!s->budget--) { s->failed_pc=0x0c046e5cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046e5e;
P_0c046e5e: /* original 2fb6, guest PC 0x0c046e5e */
if(!s->budget--) { s->failed_pc=0x0c046e5eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046e60;
P_0c046e60: /* original 2fa6, guest PC 0x0c046e60 */
if(!s->budget--) { s->failed_pc=0x0c046e60u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046e62;
P_0c046e62: /* original 2f96, guest PC 0x0c046e62 */
if(!s->budget--) { s->failed_pc=0x0c046e62u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046e64;
P_0c046e64: /* original 2f86, guest PC 0x0c046e64 */
if(!s->budget--) { s->failed_pc=0x0c046e64u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c046e66u,s,ram);
P_0c04b9fc: /* original 6743, guest PC 0x0c04b9fc */
if(!s->budget--) { s->failed_pc=0x0c04b9fcu; return 0; }
r[7]=r[4];
goto P_0c04b9fe;
P_0c04b9fe: /* original 6053, guest PC 0x0c04b9fe */
if(!s->budget--) { s->failed_pc=0x0c04b9feu; return 0; }
r[0]=r[5];
goto P_0c04ba00;
P_0c04ba00: /* original 0009, guest PC 0x0c04ba00 */
if(!s->budget--) { s->failed_pc=0x0c04ba00u; return 0; }
goto P_0c04ba02;
P_0c04ba02: /* original a004, guest PC 0x0c04ba02 */
if(!s->budget--) { s->failed_pc=0x0c04ba02u; return 0; }
r[5]=0x00000000u;
goto P_0c04ba0e;
P_0c04ba04: /* original e500, guest PC 0x0c04ba04 */
if(!s->budget--) { s->failed_pc=0x0c04ba04u; return 0; }
r[5]=0x00000000u;
goto P_0c04ba06;
P_0c04ba06: /* original 7501, guest PC 0x0c04ba06 */
if(!s->budget--) { s->failed_pc=0x0c04ba06u; return 0; }
r[5]+=0x00000001u;
goto P_0c04ba08;
P_0c04ba08: /* original 6304, guest PC 0x0c04ba08 */
if(!s->budget--) { s->failed_pc=0x0c04ba08u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[0]+=1;
r[3]=tmp;
goto P_0c04ba0a;
P_0c04ba0a: /* original 2730, guest PC 0x0c04ba0a */
if(!s->budget--) { s->failed_pc=0x0c04ba0au; return 0; }
write(ram,r[7],r[3],1);
goto P_0c04ba0c;
P_0c04ba0c: /* original 7701, guest PC 0x0c04ba0c */
if(!s->budget--) { s->failed_pc=0x0c04ba0cu; return 0; }
r[7]+=0x00000001u;
goto P_0c04ba0e;
P_0c04ba0e: /* original 3562, guest PC 0x0c04ba0e */
if(!s->budget--) { s->failed_pc=0x0c04ba0eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c04ba10;
P_0c04ba10: /* original 8d04, guest PC 0x0c04ba10 */
if(!s->budget--) { s->failed_pc=0x0c04ba10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ba1c; }
goto P_0c04ba14;
P_0c04ba12: /* original 0009, guest PC 0x0c04ba12 */
if(!s->budget--) { s->failed_pc=0x0c04ba12u; return 0; }
goto P_0c04ba14;
P_0c04ba14: /* original 6300, guest PC 0x0c04ba14 */
if(!s->budget--) { s->failed_pc=0x0c04ba14u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[3]=tmp;
goto P_0c04ba16;
P_0c04ba16: /* original 2338, guest PC 0x0c04ba16 */
if(!s->budget--) { s->failed_pc=0x0c04ba16u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04ba18;
P_0c04ba18: /* original 8ff5, guest PC 0x0c04ba18 */
if(!s->budget--) { s->failed_pc=0x0c04ba18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ba06; }
goto P_0c04ba1c;
P_0c04ba1a: /* original 0009, guest PC 0x0c04ba1a */
if(!s->budget--) { s->failed_pc=0x0c04ba1au; return 0; }
goto P_0c04ba1c;
P_0c04ba1c: /* original 3562, guest PC 0x0c04ba1c */
if(!s->budget--) { s->failed_pc=0x0c04ba1cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c04ba1e;
P_0c04ba1e: /* original 8d05, guest PC 0x0c04ba1e */
if(!s->budget--) { s->failed_pc=0x0c04ba1eu; return 0; }
cond=r[17]&1u;
r[0]=0x00000000u;
if(cond) { goto P_0c04ba2c; }
goto P_0c04ba22;
P_0c04ba20: /* original e000, guest PC 0x0c04ba20 */
if(!s->budget--) { s->failed_pc=0x0c04ba20u; return 0; }
r[0]=0x00000000u;
goto P_0c04ba22;
P_0c04ba22: /* original 7501, guest PC 0x0c04ba22 */
if(!s->budget--) { s->failed_pc=0x0c04ba22u; return 0; }
r[5]+=0x00000001u;
goto P_0c04ba24;
P_0c04ba24: /* original 2700, guest PC 0x0c04ba24 */
if(!s->budget--) { s->failed_pc=0x0c04ba24u; return 0; }
write(ram,r[7],r[0],1);
goto P_0c04ba26;
P_0c04ba26: /* original 3562, guest PC 0x0c04ba26 */
if(!s->budget--) { s->failed_pc=0x0c04ba26u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c04ba28;
P_0c04ba28: /* original 8ffb, guest PC 0x0c04ba28 */
if(!s->budget--) { s->failed_pc=0x0c04ba28u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c04ba22; }
goto P_0c04ba2c;
P_0c04ba2a: /* original 7701, guest PC 0x0c04ba2a */
if(!s->budget--) { s->failed_pc=0x0c04ba2au; return 0; }
r[7]+=0x00000001u;
goto P_0c04ba2c;
P_0c04ba2c: /* original 000b, guest PC 0x0c04ba2c */
if(!s->budget--) { s->failed_pc=0x0c04ba2cu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c04ba2e: /* original 6043, guest PC 0x0c04ba2e */
if(!s->budget--) { s->failed_pc=0x0c04ba2eu; return 0; }
r[0]=r[4];
goto P_0c04ba30;
P_0c04ba30: /* original 4f22, guest PC 0x0c04ba30 */
if(!s->budget--) { s->failed_pc=0x0c04ba30u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ba32;
P_0c04ba32: /* original d344, guest PC 0x0c04ba32 */
if(!s->budget--) { s->failed_pc=0x0c04ba32u; return 0; }
r[3]=read(ram,0x0c04bb44u,4);
goto P_0c04ba34;
P_0c04ba34: /* original d442, guest PC 0x0c04ba34 */
if(!s->budget--) { s->failed_pc=0x0c04ba34u; return 0; }
r[4]=read(ram,0x0c04bb40u,4);
goto P_0c04ba36;
P_0c04ba36: /* original d641, guest PC 0x0c04ba36 */
if(!s->budget--) { s->failed_pc=0x0c04ba36u; return 0; }
r[6]=read(ram,0x0c04bb3cu,4);
goto P_0c04ba38;
P_0c04ba38: /* original 430b, guest PC 0x0c04ba38 */
if(!s->budget--) { s->failed_pc=0x0c04ba38u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ba3cu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ba3cu) { target=s->pc; goto dispatch; }
goto P_0c04ba3c;
P_0c04ba3a: /* original e500, guest PC 0x0c04ba3a */
if(!s->budget--) { s->failed_pc=0x0c04ba3au; return 0; }
r[5]=0x00000000u;
goto P_0c04ba3c;
P_0c04ba3c: /* original 4f26, guest PC 0x0c04ba3c */
if(!s->budget--) { s->failed_pc=0x0c04ba3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ba3e;
P_0c04ba3e: /* original d242, guest PC 0x0c04ba3e */
if(!s->budget--) { s->failed_pc=0x0c04ba3eu; return 0; }
r[2]=read(ram,0x0c04bb48u,4);
goto P_0c04ba40;
P_0c04ba40: /* original e400, guest PC 0x0c04ba40 */
if(!s->budget--) { s->failed_pc=0x0c04ba40u; return 0; }
r[4]=0x00000000u;
goto P_0c04ba42;
P_0c04ba42: /* original 6143, guest PC 0x0c04ba42 */
if(!s->budget--) { s->failed_pc=0x0c04ba42u; return 0; }
r[1]=r[4];
goto P_0c04ba44;
P_0c04ba44: /* original 2242, guest PC 0x0c04ba44 */
if(!s->budget--) { s->failed_pc=0x0c04ba44u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c04ba46;
P_0c04ba46: /* original d341, guest PC 0x0c04ba46 */
if(!s->budget--) { s->failed_pc=0x0c04ba46u; return 0; }
r[3]=read(ram,0x0c04bb4cu,4);
goto P_0c04ba48;
P_0c04ba48: /* original 2342, guest PC 0x0c04ba48 */
if(!s->budget--) { s->failed_pc=0x0c04ba48u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c04ba4a;
P_0c04ba4a: /* original d041, guest PC 0x0c04ba4a */
if(!s->budget--) { s->failed_pc=0x0c04ba4au; return 0; }
r[0]=read(ram,0x0c04bb50u,4);
goto P_0c04ba4c;
P_0c04ba4c: /* original 000b, guest PC 0x0c04ba4c */
if(!s->budget--) { s->failed_pc=0x0c04ba4cu; return 0; }
target=r[16];
write(ram,r[0],r[4],4);
s->pc=target; return ram->oob==0;
P_0c04ba4e: /* original 2042, guest PC 0x0c04ba4e */
if(!s->budget--) { s->failed_pc=0x0c04ba4eu; return 0; }
write(ram,r[0],r[4],4);
return vf3_matrix_family(0x0c04ba50u,s,ram);
P_0c04c0f8: /* original 2fe6, guest PC 0x0c04c0f8 */
if(!s->budget--) { s->failed_pc=0x0c04c0f8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c0fa;
P_0c04c0fa: /* original ee00, guest PC 0x0c04c0fa */
if(!s->budget--) { s->failed_pc=0x0c04c0fau; return 0; }
r[14]=0x00000000u;
goto P_0c04c0fc;
P_0c04c0fc: /* original d41b, guest PC 0x0c04c0fc */
if(!s->budget--) { s->failed_pc=0x0c04c0fcu; return 0; }
r[4]=read(ram,0x0c04c16cu,4);
return vf3_matrix_family(0x0c04c0feu,s,ram);
P_0c04c60a: /* original 2fe6, guest PC 0x0c04c60a */
if(!s->budget--) { s->failed_pc=0x0c04c60au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c60c;
P_0c04c60c: /* original 2fd6, guest PC 0x0c04c60c */
if(!s->budget--) { s->failed_pc=0x0c04c60cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c60e;
P_0c04c60e: /* original 2fc6, guest PC 0x0c04c60e */
if(!s->budget--) { s->failed_pc=0x0c04c60eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c610;
P_0c04c610: /* original 6c53, guest PC 0x0c04c610 */
if(!s->budget--) { s->failed_pc=0x0c04c610u; return 0; }
r[12]=r[5];
goto P_0c04c612;
P_0c04c612: /* original 2fb6, guest PC 0x0c04c612 */
if(!s->budget--) { s->failed_pc=0x0c04c612u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c614;
P_0c04c614: /* original 6b63, guest PC 0x0c04c614 */
if(!s->budget--) { s->failed_pc=0x0c04c614u; return 0; }
r[11]=r[6];
goto P_0c04c616;
P_0c04c616: /* original 2fa6, guest PC 0x0c04c616 */
if(!s->budget--) { s->failed_pc=0x0c04c616u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c618;
P_0c04c618: /* original 2f96, guest PC 0x0c04c618 */
if(!s->budget--) { s->failed_pc=0x0c04c618u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c61a;
P_0c04c61a: /* original 2f86, guest PC 0x0c04c61a */
if(!s->budget--) { s->failed_pc=0x0c04c61au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c61c;
P_0c04c61c: /* original 6843, guest PC 0x0c04c61c */
if(!s->budget--) { s->failed_pc=0x0c04c61cu; return 0; }
r[8]=r[4];
return vf3_matrix_family(0x0c04c61eu,s,ram);
P_0c053dda: /* original 4f22, guest PC 0x0c053dda */
if(!s->budget--) { s->failed_pc=0x0c053ddau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053ddc;
P_0c053ddc: /* original 7fe0, guest PC 0x0c053ddc */
if(!s->budget--) { s->failed_pc=0x0c053ddcu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c053dde;
P_0c053dde: /* original 6043, guest PC 0x0c053dde */
if(!s->budget--) { s->failed_pc=0x0c053ddeu; return 0; }
r[0]=r[4];
goto P_0c053de0;
P_0c053de0: /* original 0009, guest PC 0x0c053de0 */
if(!s->budget--) { s->failed_pc=0x0c053de0u; return 0; }
goto P_0c053de2;
P_0c053de2: /* original 6d63, guest PC 0x0c053de2 */
if(!s->budget--) { s->failed_pc=0x0c053de2u; return 0; }
r[13]=r[6];
goto P_0c053de4;
P_0c053de4: /* original 81f4, guest PC 0x0c053de4 */
if(!s->budget--) { s->failed_pc=0x0c053de4u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c053de6;
P_0c053de6: /* original 6ef3, guest PC 0x0c053de6 */
if(!s->budget--) { s->failed_pc=0x0c053de6u; return 0; }
r[14]=r[15];
goto P_0c053de8;
P_0c053de8: /* original 1f51, guest PC 0x0c053de8 */
if(!s->budget--) { s->failed_pc=0x0c053de8u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c053dea;
P_0c053dea: /* original e008, guest PC 0x0c053dea */
if(!s->budget--) { s->failed_pc=0x0c053deau; return 0; }
r[0]=0x00000008u;
goto P_0c053dec;
P_0c053dec: /* original 1f73, guest PC 0x0c053dec */
if(!s->budget--) { s->failed_pc=0x0c053decu; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c053dee;
P_0c053dee: /* original 4d15, guest PC 0x0c053dee */
if(!s->budget--) { s->failed_pc=0x0c053deeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c053df0;
P_0c053df0: /* original 81f8, guest PC 0x0c053df0 */
if(!s->budget--) { s->failed_pc=0x0c053df0u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c053df2;
P_0c053df2: /* original 8f0e, guest PC 0x0c053df2 */
if(!s->budget--) { s->failed_pc=0x0c053df2u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000014u;
if(!cond) { goto P_0c053e12; }
goto P_0c053df6;
P_0c053df4: /* original 7e14, guest PC 0x0c053df4 */
if(!s->budget--) { s->failed_pc=0x0c053df4u; return 0; }
r[14]+=0x00000014u;
goto P_0c053df6;
P_0c053df6: /* original 66e3, guest PC 0x0c053df6 */
if(!s->budget--) { s->failed_pc=0x0c053df6u; return 0; }
r[6]=r[14];
goto P_0c053df8;
P_0c053df8: /* original d22e, guest PC 0x0c053df8 */
if(!s->budget--) { s->failed_pc=0x0c053df8u; return 0; }
r[2]=read(ram,0x0c053eb4u,4);
goto P_0c053dfa;
P_0c053dfa: /* original 65f3, guest PC 0x0c053dfa */
if(!s->budget--) { s->failed_pc=0x0c053dfau; return 0; }
r[5]=r[15];
goto P_0c053dfc;
P_0c053dfc: /* original 420b, guest PC 0x0c053dfc */
if(!s->budget--) { s->failed_pc=0x0c053dfcu; return 0; }
target=r[2];
r[16]=code_base|0x0c053e00u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053e00u) { target=s->pc; goto dispatch; }
goto P_0c053e00;
P_0c053dfe: /* original 64d3, guest PC 0x0c053dfe */
if(!s->budget--) { s->failed_pc=0x0c053dfeu; return 0; }
r[4]=r[13];
goto P_0c053e00;
P_0c053e00: /* original 57f1, guest PC 0x0c053e00 */
if(!s->budget--) { s->failed_pc=0x0c053e00u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c053e02;
P_0c053e02: /* original 65e3, guest PC 0x0c053e02 */
if(!s->budget--) { s->failed_pc=0x0c053e02u; return 0; }
r[5]=r[14];
goto P_0c053e04;
P_0c053e04: /* original d32c, guest PC 0x0c053e04 */
if(!s->budget--) { s->failed_pc=0x0c053e04u; return 0; }
r[3]=read(ram,0x0c053eb8u,4);
goto P_0c053e06;
P_0c053e06: /* original 85f4, guest PC 0x0c053e06 */
if(!s->budget--) { s->failed_pc=0x0c053e06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c053e08;
P_0c053e08: /* original 6603, guest PC 0x0c053e08 */
if(!s->budget--) { s->failed_pc=0x0c053e08u; return 0; }
r[6]=r[0];
goto P_0c053e0a;
P_0c053e0a: /* original 430b, guest PC 0x0c053e0a */
if(!s->budget--) { s->failed_pc=0x0c053e0au; return 0; }
target=r[3];
r[16]=code_base|0x0c053e0eu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053e0eu) { target=s->pc; goto dispatch; }
goto P_0c053e0e;
P_0c053e0c: /* original 64f3, guest PC 0x0c053e0c */
if(!s->budget--) { s->failed_pc=0x0c053e0cu; return 0; }
r[4]=r[15];
goto P_0c053e0e;
P_0c053e0e: /* original a00c, guest PC 0x0c053e0e */
if(!s->budget--) { s->failed_pc=0x0c053e0eu; return 0; }
goto P_0c053e2a;
P_0c053e10: /* original 0009, guest PC 0x0c053e10 */
if(!s->budget--) { s->failed_pc=0x0c053e10u; return 0; }
goto P_0c053e12;
P_0c053e12: /* original 66e3, guest PC 0x0c053e12 */
if(!s->budget--) { s->failed_pc=0x0c053e12u; return 0; }
r[6]=r[14];
goto P_0c053e14;
P_0c053e14: /* original d327, guest PC 0x0c053e14 */
if(!s->budget--) { s->failed_pc=0x0c053e14u; return 0; }
r[3]=read(ram,0x0c053eb4u,4);
goto P_0c053e16;
P_0c053e16: /* original 65f3, guest PC 0x0c053e16 */
if(!s->budget--) { s->failed_pc=0x0c053e16u; return 0; }
r[5]=r[15];
goto P_0c053e18;
P_0c053e18: /* original 430b, guest PC 0x0c053e18 */
if(!s->budget--) { s->failed_pc=0x0c053e18u; return 0; }
target=r[3];
r[16]=code_base|0x0c053e1cu;
r[4]=0u-r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053e1cu) { target=s->pc; goto dispatch; }
goto P_0c053e1c;
P_0c053e1a: /* original 64db, guest PC 0x0c053e1a */
if(!s->budget--) { s->failed_pc=0x0c053e1au; return 0; }
r[4]=0u-r[13];
goto P_0c053e1c;
P_0c053e1c: /* original 57f1, guest PC 0x0c053e1c */
if(!s->budget--) { s->failed_pc=0x0c053e1cu; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c053e1e;
P_0c053e1e: /* original 65e3, guest PC 0x0c053e1e */
if(!s->budget--) { s->failed_pc=0x0c053e1eu; return 0; }
r[5]=r[14];
goto P_0c053e20;
P_0c053e20: /* original d326, guest PC 0x0c053e20 */
if(!s->budget--) { s->failed_pc=0x0c053e20u; return 0; }
r[3]=read(ram,0x0c053ebcu,4);
goto P_0c053e22;
P_0c053e22: /* original 85f4, guest PC 0x0c053e22 */
if(!s->budget--) { s->failed_pc=0x0c053e22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c053e24;
P_0c053e24: /* original 6603, guest PC 0x0c053e24 */
if(!s->budget--) { s->failed_pc=0x0c053e24u; return 0; }
r[6]=r[0];
goto P_0c053e26;
P_0c053e26: /* original 430b, guest PC 0x0c053e26 */
if(!s->budget--) { s->failed_pc=0x0c053e26u; return 0; }
target=r[3];
r[16]=code_base|0x0c053e2au;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053e2au) { target=s->pc; goto dispatch; }
goto P_0c053e2a;
P_0c053e28: /* original 64f3, guest PC 0x0c053e28 */
if(!s->budget--) { s->failed_pc=0x0c053e28u; return 0; }
r[4]=r[15];
goto P_0c053e2a;
P_0c053e2a: /* original ed3f, guest PC 0x0c053e2a */
if(!s->budget--) { s->failed_pc=0x0c053e2au; return 0; }
r[13]=0x0000003fu;
goto P_0c053e2c;
P_0c053e2c: /* original d224, guest PC 0x0c053e2c */
if(!s->budget--) { s->failed_pc=0x0c053e2cu; return 0; }
r[2]=read(ram,0x0c053ec0u,4);
goto P_0c053e2e;
P_0c053e2e: /* original 63f1, guest PC 0x0c053e2e */
if(!s->budget--) { s->failed_pc=0x0c053e2eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c053e30;
P_0c053e30: /* original 3d38, guest PC 0x0c053e30 */
if(!s->budget--) { s->failed_pc=0x0c053e30u; return 0; }
r[13]-=r[3];
goto P_0c053e32;
P_0c053e32: /* original 61d3, guest PC 0x0c053e32 */
if(!s->budget--) { s->failed_pc=0x0c053e32u; return 0; }
r[1]=r[13];
goto P_0c053e34;
P_0c053e34: /* original 420b, guest PC 0x0c053e34 */
if(!s->budget--) { s->failed_pc=0x0c053e34u; return 0; }
target=r[2];
r[16]=code_base|0x0c053e38u;
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053e38u) { target=s->pc; goto dispatch; }
goto P_0c053e38;
P_0c053e36: /* original 85f8, guest PC 0x0c053e36 */
if(!s->budget--) { s->failed_pc=0x0c053e36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c053e38;
P_0c053e38: /* original d122, guest PC 0x0c053e38 */
if(!s->budget--) { s->failed_pc=0x0c053e38u; return 0; }
r[1]=read(ram,0x0c053ec4u,4);
goto P_0c053e3a;
P_0c053e3a: /* original 6c03, guest PC 0x0c053e3a */
if(!s->budget--) { s->failed_pc=0x0c053e3au; return 0; }
r[12]=r[0];
goto P_0c053e3c;
P_0c053e3c: /* original 62df, guest PC 0x0c053e3c */
if(!s->budget--) { s->failed_pc=0x0c053e3cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c053e3e;
P_0c053e3e: /* original e642, guest PC 0x0c053e3e */
if(!s->budget--) { s->failed_pc=0x0c053e3eu; return 0; }
r[6]=0x00000042u;
goto P_0c053e40;
P_0c053e40: /* original 3628, guest PC 0x0c053e40 */
if(!s->budget--) { s->failed_pc=0x0c053e40u; return 0; }
r[6]-=r[2];
goto P_0c053e42;
P_0c053e42: /* original e509, guest PC 0x0c053e42 */
if(!s->budget--) { s->failed_pc=0x0c053e42u; return 0; }
r[5]=0x00000009u;
goto P_0c053e44;
P_0c053e44: /* original 410b, guest PC 0x0c053e44 */
if(!s->budget--) { s->failed_pc=0x0c053e44u; return 0; }
target=r[1];
r[16]=code_base|0x0c053e48u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053e48u) { target=s->pc; goto dispatch; }
goto P_0c053e48;
P_0c053e46: /* original 64e3, guest PC 0x0c053e46 */
if(!s->budget--) { s->failed_pc=0x0c053e46u; return 0; }
r[4]=r[14];
goto P_0c053e48;
P_0c053e48: /* original e008, guest PC 0x0c053e48 */
if(!s->budget--) { s->failed_pc=0x0c053e48u; return 0; }
r[0]=0x00000008u;
goto P_0c053e4a;
P_0c053e4a: /* original 65cf, guest PC 0x0c053e4a */
if(!s->budget--) { s->failed_pc=0x0c053e4au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c053e4c;
P_0c053e4c: /* original 6303, guest PC 0x0c053e4c */
if(!s->budget--) { s->failed_pc=0x0c053e4cu; return 0; }
r[3]=r[0];
goto P_0c053e4e;
P_0c053e4e: /* original 3353, guest PC 0x0c053e4e */
if(!s->budget--) { s->failed_pc=0x0c053e4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c053e50;
P_0c053e50: /* original 8f0b, guest PC 0x0c053e50 */
if(!s->budget--) { s->failed_pc=0x0c053e50u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053e6a; }
goto P_0c053e54;
P_0c053e52: /* original 0009, guest PC 0x0c053e52 */
if(!s->budget--) { s->failed_pc=0x0c053e52u; return 0; }
goto P_0c053e54;
P_0c053e54: /* original 600f, guest PC 0x0c053e54 */
if(!s->budget--) { s->failed_pc=0x0c053e54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e56;
P_0c053e56: /* original 630f, guest PC 0x0c053e56 */
if(!s->budget--) { s->failed_pc=0x0c053e56u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e58;
P_0c053e58: /* original 3358, guest PC 0x0c053e58 */
if(!s->budget--) { s->failed_pc=0x0c053e58u; return 0; }
r[3]-=r[5];
goto P_0c053e5a;
P_0c053e5a: /* original 33ec, guest PC 0x0c053e5a */
if(!s->budget--) { s->failed_pc=0x0c053e5au; return 0; }
r[3]+=r[14];
goto P_0c053e5c;
P_0c053e5c: /* original 6330, guest PC 0x0c053e5c */
if(!s->budget--) { s->failed_pc=0x0c053e5cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c053e5e;
P_0c053e5e: /* original 0e34, guest PC 0x0c053e5e */
if(!s->budget--) { s->failed_pc=0x0c053e5eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c053e60;
P_0c053e60: /* original 70ff, guest PC 0x0c053e60 */
if(!s->budget--) { s->failed_pc=0x0c053e60u; return 0; }
r[0]+=0xffffffffu;
goto P_0c053e62;
P_0c053e62: /* original 620f, guest PC 0x0c053e62 */
if(!s->budget--) { s->failed_pc=0x0c053e62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e64;
P_0c053e64: /* original 3253, guest PC 0x0c053e64 */
if(!s->budget--) { s->failed_pc=0x0c053e64u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[5])!=0);
goto P_0c053e66;
P_0c053e66: /* original 8df5, guest PC 0x0c053e66 */
if(!s->budget--) { s->failed_pc=0x0c053e66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053e54; }
goto P_0c053e6a;
P_0c053e68: /* original 0009, guest PC 0x0c053e68 */
if(!s->budget--) { s->failed_pc=0x0c053e68u; return 0; }
goto P_0c053e6a;
P_0c053e6a: /* original 660f, guest PC 0x0c053e6a */
if(!s->budget--) { s->failed_pc=0x0c053e6au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e6c;
P_0c053e6c: /* original 36ec, guest PC 0x0c053e6c */
if(!s->budget--) { s->failed_pc=0x0c053e6cu; return 0; }
r[6]+=r[14];
goto P_0c053e6e;
P_0c053e6e: /* original 7601, guest PC 0x0c053e6e */
if(!s->budget--) { s->failed_pc=0x0c053e6eu; return 0; }
r[6]+=0x00000001u;
goto P_0c053e70;
P_0c053e70: /* original 630f, guest PC 0x0c053e70 */
if(!s->budget--) { s->failed_pc=0x0c053e70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e72;
P_0c053e72: /* original 4311, guest PC 0x0c053e72 */
if(!s->budget--) { s->failed_pc=0x0c053e72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c053e74;
P_0c053e74: /* original 8f05, guest PC 0x0c053e74 */
if(!s->budget--) { s->failed_pc=0x0c053e74u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c053e82; }
goto P_0c053e78;
P_0c053e76: /* original e500, guest PC 0x0c053e76 */
if(!s->budget--) { s->failed_pc=0x0c053e76u; return 0; }
r[5]=0x00000000u;
goto P_0c053e78;
P_0c053e78: /* original 70ff, guest PC 0x0c053e78 */
if(!s->budget--) { s->failed_pc=0x0c053e78u; return 0; }
r[0]+=0xffffffffu;
goto P_0c053e7a;
P_0c053e7a: /* original 630f, guest PC 0x0c053e7a */
if(!s->budget--) { s->failed_pc=0x0c053e7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c053e7c;
P_0c053e7c: /* original 4311, guest PC 0x0c053e7c */
if(!s->budget--) { s->failed_pc=0x0c053e7cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c053e7e;
P_0c053e7e: /* original 8dfb, guest PC 0x0c053e7e */
if(!s->budget--) { s->failed_pc=0x0c053e7eu; return 0; }
cond=r[17]&1u;
tmp=r[5]; r[6]-=1; write(ram,r[6],tmp,1);
if(cond) { goto P_0c053e78; }
goto P_0c053e82;
P_0c053e80: /* original 2654, guest PC 0x0c053e80 */
if(!s->budget--) { s->failed_pc=0x0c053e80u; return 0; }
tmp=r[5]; r[6]-=1; write(ram,r[6],tmp,1);
goto P_0c053e82;
P_0c053e82: /* original 4c08, guest PC 0x0c053e82 */
if(!s->budget--) { s->failed_pc=0x0c053e82u; return 0; }
r[12]<<=2;
goto P_0c053e84;
P_0c053e84: /* original d310, guest PC 0x0c053e84 */
if(!s->budget--) { s->failed_pc=0x0c053e84u; return 0; }
r[3]=read(ram,0x0c053ec8u,4);
goto P_0c053e86;
P_0c053e86: /* original 66d3, guest PC 0x0c053e86 */
if(!s->budget--) { s->failed_pc=0x0c053e86u; return 0; }
r[6]=r[13];
goto P_0c053e88;
P_0c053e88: /* original 4c00, guest PC 0x0c053e88 */
if(!s->budget--) { s->failed_pc=0x0c053e88u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c053e8a;
P_0c053e8a: /* original 36c8, guest PC 0x0c053e8a */
if(!s->budget--) { s->failed_pc=0x0c053e8au; return 0; }
r[6]-=r[12];
goto P_0c053e8c;
P_0c053e8c: /* original e509, guest PC 0x0c053e8c */
if(!s->budget--) { s->failed_pc=0x0c053e8cu; return 0; }
r[5]=0x00000009u;
goto P_0c053e8e;
P_0c053e8e: /* original 430b, guest PC 0x0c053e8e */
if(!s->budget--) { s->failed_pc=0x0c053e8eu; return 0; }
target=r[3];
r[16]=code_base|0x0c053e92u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053e92u) { target=s->pc; goto dispatch; }
goto P_0c053e92;
P_0c053e90: /* original 64e3, guest PC 0x0c053e90 */
if(!s->budget--) { s->failed_pc=0x0c053e90u; return 0; }
r[4]=r[14];
goto P_0c053e92;
P_0c053e92: /* original e23f, guest PC 0x0c053e92 */
if(!s->budget--) { s->failed_pc=0x0c053e92u; return 0; }
r[2]=0x0000003fu;
goto P_0c053e94;
P_0c053e94: /* original d30d, guest PC 0x0c053e94 */
if(!s->budget--) { s->failed_pc=0x0c053e94u; return 0; }
r[3]=read(ram,0x0c053eccu,4);
goto P_0c053e96;
P_0c053e96: /* original e540, guest PC 0x0c053e96 */
if(!s->budget--) { s->failed_pc=0x0c053e96u; return 0; }
r[5]=0x00000040u;
goto P_0c053e98;
P_0c053e98: /* original 2f21, guest PC 0x0c053e98 */
if(!s->budget--) { s->failed_pc=0x0c053e98u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c053e9a;
P_0c053e9a: /* original 430b, guest PC 0x0c053e9a */
if(!s->budget--) { s->failed_pc=0x0c053e9au; return 0; }
target=r[3];
r[16]=code_base|0x0c053e9eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053e9eu) { target=s->pc; goto dispatch; }
goto P_0c053e9e;
P_0c053e9c: /* original 64e3, guest PC 0x0c053e9c */
if(!s->budget--) { s->failed_pc=0x0c053e9cu; return 0; }
r[4]=r[14];
goto P_0c053e9e;
P_0c053e9e: /* original e608, guest PC 0x0c053e9e */
if(!s->budget--) { s->failed_pc=0x0c053e9eu; return 0; }
r[6]=0x00000008u;
goto P_0c053ea0;
P_0c053ea0: /* original d30b, guest PC 0x0c053ea0 */
if(!s->budget--) { s->failed_pc=0x0c053ea0u; return 0; }
r[3]=read(ram,0x0c053ed0u,4);
goto P_0c053ea2;
P_0c053ea2: /* original 65e3, guest PC 0x0c053ea2 */
if(!s->budget--) { s->failed_pc=0x0c053ea2u; return 0; }
r[5]=r[14];
goto P_0c053ea4;
P_0c053ea4: /* original 430b, guest PC 0x0c053ea4 */
if(!s->budget--) { s->failed_pc=0x0c053ea4u; return 0; }
target=r[3];
r[16]=code_base|0x0c053ea8u;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053ea8u) { target=s->pc; goto dispatch; }
goto P_0c053ea8;
P_0c053ea6: /* original 54f3, guest PC 0x0c053ea6 */
if(!s->budget--) { s->failed_pc=0x0c053ea6u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c053ea8;
P_0c053ea8: /* original 7f20, guest PC 0x0c053ea8 */
if(!s->budget--) { s->failed_pc=0x0c053ea8u; return 0; }
r[15]+=0x00000020u;
goto P_0c053eaa;
P_0c053eaa: /* original 4f26, guest PC 0x0c053eaa */
if(!s->budget--) { s->failed_pc=0x0c053eaau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053eac;
P_0c053eac: /* original 6cf6, guest PC 0x0c053eac */
if(!s->budget--) { s->failed_pc=0x0c053eacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c053eae;
P_0c053eae: /* original 6df6, guest PC 0x0c053eae */
if(!s->budget--) { s->failed_pc=0x0c053eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c053eb0;
P_0c053eb0: /* original 000b, guest PC 0x0c053eb0 */
if(!s->budget--) { s->failed_pc=0x0c053eb0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053eb2: /* original 6ef6, guest PC 0x0c053eb2 */
if(!s->budget--) { s->failed_pc=0x0c053eb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c053eb4u,s,ram);
P_0c054640: /* original 2fe6, guest PC 0x0c054640 */
if(!s->budget--) { s->failed_pc=0x0c054640u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054642;
P_0c054642: /* original 2fd6, guest PC 0x0c054642 */
if(!s->budget--) { s->failed_pc=0x0c054642u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054644;
P_0c054644: /* original 2fc6, guest PC 0x0c054644 */
if(!s->budget--) { s->failed_pc=0x0c054644u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054646;
P_0c054646: /* original 2fb6, guest PC 0x0c054646 */
if(!s->budget--) { s->failed_pc=0x0c054646u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054648;
P_0c054648: /* original 2fa6, guest PC 0x0c054648 */
if(!s->budget--) { s->failed_pc=0x0c054648u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05464a;
P_0c05464a: /* original 6a43, guest PC 0x0c05464a */
if(!s->budget--) { s->failed_pc=0x0c05464au; return 0; }
r[10]=r[4];
goto P_0c05464c;
P_0c05464c: /* original 2f96, guest PC 0x0c05464c */
if(!s->budget--) { s->failed_pc=0x0c05464cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05464e;
P_0c05464e: /* original 2f86, guest PC 0x0c05464e */
if(!s->budget--) { s->failed_pc=0x0c05464eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c054650u,s,ram);
P_0c07caa8: /* original 4f22, guest PC 0x0c07caa8 */
if(!s->budget--) { s->failed_pc=0x0c07caa8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07caaa;
P_0c07caaa: /* original 7ff4, guest PC 0x0c07caaa */
if(!s->budget--) { s->failed_pc=0x0c07caaau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07caac;
P_0c07caac: /* original 2f42, guest PC 0x0c07caac */
if(!s->budget--) { s->failed_pc=0x0c07caacu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07caae;
P_0c07caae: /* original 1f51, guest PC 0x0c07caae */
if(!s->budget--) { s->failed_pc=0x0c07caaeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07cab0;
P_0c07cab0: /* original 63f2, guest PC 0x0c07cab0 */
if(!s->budget--) { s->failed_pc=0x0c07cab0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07cab2;
P_0c07cab2: /* original d239, guest PC 0x0c07cab2 */
if(!s->budget--) { s->failed_pc=0x0c07cab2u; return 0; }
r[2]=read(ram,0x0c07cb98u,4);
goto P_0c07cab4;
P_0c07cab4: /* original 420b, guest PC 0x0c07cab4 */
if(!s->budget--) { s->failed_pc=0x0c07cab4u; return 0; }
target=r[2];
r[16]=code_base|0x0c07cab8u;
write(ram,r[15]+8,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cab8u) { target=s->pc; goto dispatch; }
goto P_0c07cab8;
P_0c07cab6: /* original 1f32, guest PC 0x0c07cab6 */
if(!s->budget--) { s->failed_pc=0x0c07cab6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07cab8;
P_0c07cab8: /* original d138, guest PC 0x0c07cab8 */
if(!s->budget--) { s->failed_pc=0x0c07cab8u; return 0; }
r[1]=read(ram,0x0c07cb9cu,4);
goto P_0c07caba;
P_0c07caba: /* original 410b, guest PC 0x0c07caba */
if(!s->budget--) { s->failed_pc=0x0c07cabau; return 0; }
target=r[1];
r[16]=code_base|0x0c07cabeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cabeu) { target=s->pc; goto dispatch; }
goto P_0c07cabe;
P_0c07cabc: /* original 0009, guest PC 0x0c07cabc */
if(!s->budget--) { s->failed_pc=0x0c07cabcu; return 0; }
goto P_0c07cabe;
P_0c07cabe: /* original d238, guest PC 0x0c07cabe */
if(!s->budget--) { s->failed_pc=0x0c07cabeu; return 0; }
r[2]=read(ram,0x0c07cba0u,4);
goto P_0c07cac0;
P_0c07cac0: /* original 420b, guest PC 0x0c07cac0 */
if(!s->budget--) { s->failed_pc=0x0c07cac0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07cac4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cac4u) { target=s->pc; goto dispatch; }
goto P_0c07cac4;
P_0c07cac2: /* original 0009, guest PC 0x0c07cac2 */
if(!s->budget--) { s->failed_pc=0x0c07cac2u; return 0; }
goto P_0c07cac4;
P_0c07cac4: /* original d137, guest PC 0x0c07cac4 */
if(!s->budget--) { s->failed_pc=0x0c07cac4u; return 0; }
r[1]=read(ram,0x0c07cba4u,4);
goto P_0c07cac6;
P_0c07cac6: /* original 410b, guest PC 0x0c07cac6 */
if(!s->budget--) { s->failed_pc=0x0c07cac6u; return 0; }
target=r[1];
r[16]=code_base|0x0c07cacau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cacau) { target=s->pc; goto dispatch; }
goto P_0c07caca;
P_0c07cac8: /* original 0009, guest PC 0x0c07cac8 */
if(!s->budget--) { s->failed_pc=0x0c07cac8u; return 0; }
goto P_0c07caca;
P_0c07caca: /* original d237, guest PC 0x0c07caca */
if(!s->budget--) { s->failed_pc=0x0c07cacau; return 0; }
r[2]=read(ram,0x0c07cba8u,4);
goto P_0c07cacc;
P_0c07cacc: /* original 420b, guest PC 0x0c07cacc */
if(!s->budget--) { s->failed_pc=0x0c07caccu; return 0; }
target=r[2];
r[16]=code_base|0x0c07cad0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cad0u) { target=s->pc; goto dispatch; }
goto P_0c07cad0;
P_0c07cace: /* original 0009, guest PC 0x0c07cace */
if(!s->budget--) { s->failed_pc=0x0c07caceu; return 0; }
goto P_0c07cad0;
P_0c07cad0: /* original dc36, guest PC 0x0c07cad0 */
if(!s->budget--) { s->failed_pc=0x0c07cad0u; return 0; }
r[12]=read(ram,0x0c07cbacu,4);
goto P_0c07cad2;
P_0c07cad2: /* original e07d, guest PC 0x0c07cad2 */
if(!s->budget--) { s->failed_pc=0x0c07cad2u; return 0; }
r[0]=0x0000007du;
goto P_0c07cad4;
P_0c07cad4: /* original eb00, guest PC 0x0c07cad4 */
if(!s->budget--) { s->failed_pc=0x0c07cad4u; return 0; }
r[11]=0x00000000u;
goto P_0c07cad6;
P_0c07cad6: /* original e2ff, guest PC 0x0c07cad6 */
if(!s->budget--) { s->failed_pc=0x0c07cad6u; return 0; }
r[2]=0xffffffffu;
goto P_0c07cad8;
P_0c07cad8: /* original 65b3, guest PC 0x0c07cad8 */
if(!s->budget--) { s->failed_pc=0x0c07cad8u; return 0; }
r[5]=r[11];
goto P_0c07cada;
P_0c07cada: /* original 66b3, guest PC 0x0c07cada */
if(!s->budget--) { s->failed_pc=0x0c07cadau; return 0; }
r[6]=r[11];
goto P_0c07cadc;
P_0c07cadc: /* original 1cb6, guest PC 0x0c07cadc */
if(!s->budget--) { s->failed_pc=0x0c07cadcu; return 0; }
write(ram,r[12]+24,r[11],4);
goto P_0c07cade;
P_0c07cade: /* original 0cb4, guest PC 0x0c07cade */
if(!s->budget--) { s->failed_pc=0x0c07cadeu; return 0; }
write(ram,r[12]+r[0],r[11],1);
goto P_0c07cae0;
P_0c07cae0: /* original 67b3, guest PC 0x0c07cae0 */
if(!s->budget--) { s->failed_pc=0x0c07cae0u; return 0; }
r[7]=r[11];
goto P_0c07cae2;
P_0c07cae2: /* original 1cb5, guest PC 0x0c07cae2 */
if(!s->budget--) { s->failed_pc=0x0c07cae2u; return 0; }
write(ram,r[12]+20,r[11],4);
goto P_0c07cae4;
P_0c07cae4: /* original d332, guest PC 0x0c07cae4 */
if(!s->budget--) { s->failed_pc=0x0c07cae4u; return 0; }
r[3]=read(ram,0x0c07cbb0u,4);
goto P_0c07cae6;
P_0c07cae6: /* original 904b, guest PC 0x0c07cae6 */
if(!s->budget--) { s->failed_pc=0x0c07cae6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb80u,2);
goto P_0c07cae8;
P_0c07cae8: /* original 6432, guest PC 0x0c07cae8 */
if(!s->budget--) { s->failed_pc=0x0c07cae8u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c07caea;
P_0c07caea: /* original f48d, guest PC 0x0c07caea */
if(!s->budget--) { s->failed_pc=0x0c07caeau; return 0; }
fr[4]=0;
goto P_0c07caec;
P_0c07caec: /* original f447, guest PC 0x0c07caec */
if(!s->budget--) { s->failed_pc=0x0c07caecu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07caee;
P_0c07caee: /* original 7004, guest PC 0x0c07caee */
if(!s->budget--) { s->failed_pc=0x0c07caeeu; return 0; }
r[0]+=0x00000004u;
goto P_0c07caf0;
P_0c07caf0: /* original f447, guest PC 0x0c07caf0 */
if(!s->budget--) { s->failed_pc=0x0c07caf0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07caf2;
P_0c07caf2: /* original 9046, guest PC 0x0c07caf2 */
if(!s->budget--) { s->failed_pc=0x0c07caf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb82u,2);
goto P_0c07caf4;
P_0c07caf4: /* original de2f, guest PC 0x0c07caf4 */
if(!s->budget--) { s->failed_pc=0x0c07caf4u; return 0; }
r[14]=read(ram,0x0c07cbb4u,4);
goto P_0c07caf6;
P_0c07caf6: /* original 0e26, guest PC 0x0c07caf6 */
if(!s->budget--) { s->failed_pc=0x0c07caf6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c07caf8;
P_0c07caf8: /* original 9444, guest PC 0x0c07caf8 */
if(!s->budget--) { s->failed_pc=0x0c07caf8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb84u,2);
goto P_0c07cafa;
P_0c07cafa: /* original d22f, guest PC 0x0c07cafa */
if(!s->budget--) { s->failed_pc=0x0c07cafau; return 0; }
r[2]=read(ram,0x0c07cbb8u,4);
goto P_0c07cafc;
P_0c07cafc: /* original 420b, guest PC 0x0c07cafc */
if(!s->budget--) { s->failed_pc=0x0c07cafcu; return 0; }
target=r[2];
r[16]=code_base|0x0c07cb00u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb00u) { target=s->pc; goto dispatch; }
goto P_0c07cb00;
P_0c07cafe: /* original 34ec, guest PC 0x0c07cafe */
if(!s->budget--) { s->failed_pc=0x0c07cafeu; return 0; }
r[4]+=r[14];
goto P_0c07cb00;
P_0c07cb00: /* original 9441, guest PC 0x0c07cb00 */
if(!s->budget--) { s->failed_pc=0x0c07cb00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb86u,2);
goto P_0c07cb02;
P_0c07cb02: /* original 65b3, guest PC 0x0c07cb02 */
if(!s->budget--) { s->failed_pc=0x0c07cb02u; return 0; }
r[5]=r[11];
goto P_0c07cb04;
P_0c07cb04: /* original d32c, guest PC 0x0c07cb04 */
if(!s->budget--) { s->failed_pc=0x0c07cb04u; return 0; }
r[3]=read(ram,0x0c07cbb8u,4);
goto P_0c07cb06;
P_0c07cb06: /* original 67b3, guest PC 0x0c07cb06 */
if(!s->budget--) { s->failed_pc=0x0c07cb06u; return 0; }
r[7]=r[11];
goto P_0c07cb08;
P_0c07cb08: /* original 66b3, guest PC 0x0c07cb08 */
if(!s->budget--) { s->failed_pc=0x0c07cb08u; return 0; }
r[6]=r[11];
goto P_0c07cb0a;
P_0c07cb0a: /* original 430b, guest PC 0x0c07cb0a */
if(!s->budget--) { s->failed_pc=0x0c07cb0au; return 0; }
target=r[3];
r[16]=code_base|0x0c07cb0eu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb0eu) { target=s->pc; goto dispatch; }
goto P_0c07cb0e;
P_0c07cb0c: /* original 34ec, guest PC 0x0c07cb0c */
if(!s->budget--) { s->failed_pc=0x0c07cb0cu; return 0; }
r[4]+=r[14];
goto P_0c07cb0e;
P_0c07cb0e: /* original 943b, guest PC 0x0c07cb0e */
if(!s->budget--) { s->failed_pc=0x0c07cb0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb88u,2);
goto P_0c07cb10;
P_0c07cb10: /* original 66b3, guest PC 0x0c07cb10 */
if(!s->budget--) { s->failed_pc=0x0c07cb10u; return 0; }
r[6]=r[11];
goto P_0c07cb12;
P_0c07cb12: /* original dd2a, guest PC 0x0c07cb12 */
if(!s->budget--) { s->failed_pc=0x0c07cb12u; return 0; }
r[13]=read(ram,0x0c07cbbcu,4);
goto P_0c07cb14;
P_0c07cb14: /* original 4d0b, guest PC 0x0c07cb14 */
if(!s->budget--) { s->failed_pc=0x0c07cb14u; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb18u;
r[5]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb18u) { target=s->pc; goto dispatch; }
goto P_0c07cb18;
P_0c07cb16: /* original 65b3, guest PC 0x0c07cb16 */
if(!s->budget--) { s->failed_pc=0x0c07cb16u; return 0; }
r[5]=r[11];
goto P_0c07cb18;
P_0c07cb18: /* original 9437, guest PC 0x0c07cb18 */
if(!s->budget--) { s->failed_pc=0x0c07cb18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb8au,2);
goto P_0c07cb1a;
P_0c07cb1a: /* original 66b3, guest PC 0x0c07cb1a */
if(!s->budget--) { s->failed_pc=0x0c07cb1au; return 0; }
r[6]=r[11];
goto P_0c07cb1c;
P_0c07cb1c: /* original 4d0b, guest PC 0x0c07cb1c */
if(!s->budget--) { s->failed_pc=0x0c07cb1cu; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb20u;
r[5]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb20u) { target=s->pc; goto dispatch; }
goto P_0c07cb20;
P_0c07cb1e: /* original 65b3, guest PC 0x0c07cb1e */
if(!s->budget--) { s->failed_pc=0x0c07cb1eu; return 0; }
r[5]=r[11];
goto P_0c07cb20;
P_0c07cb20: /* original 9434, guest PC 0x0c07cb20 */
if(!s->budget--) { s->failed_pc=0x0c07cb20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb8cu,2);
goto P_0c07cb22;
P_0c07cb22: /* original 66b3, guest PC 0x0c07cb22 */
if(!s->budget--) { s->failed_pc=0x0c07cb22u; return 0; }
r[6]=r[11];
goto P_0c07cb24;
P_0c07cb24: /* original 4d0b, guest PC 0x0c07cb24 */
if(!s->budget--) { s->failed_pc=0x0c07cb24u; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb28u;
r[5]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb28u) { target=s->pc; goto dispatch; }
goto P_0c07cb28;
P_0c07cb26: /* original 65b3, guest PC 0x0c07cb26 */
if(!s->budget--) { s->failed_pc=0x0c07cb26u; return 0; }
r[5]=r[11];
goto P_0c07cb28;
P_0c07cb28: /* original 9431, guest PC 0x0c07cb28 */
if(!s->budget--) { s->failed_pc=0x0c07cb28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb8eu,2);
goto P_0c07cb2a;
P_0c07cb2a: /* original 66b3, guest PC 0x0c07cb2a */
if(!s->budget--) { s->failed_pc=0x0c07cb2au; return 0; }
r[6]=r[11];
goto P_0c07cb2c;
P_0c07cb2c: /* original 4d0b, guest PC 0x0c07cb2c */
if(!s->budget--) { s->failed_pc=0x0c07cb2cu; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb30u;
r[5]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb30u) { target=s->pc; goto dispatch; }
goto P_0c07cb30;
P_0c07cb2e: /* original 65b3, guest PC 0x0c07cb2e */
if(!s->budget--) { s->failed_pc=0x0c07cb2eu; return 0; }
r[5]=r[11];
goto P_0c07cb30;
P_0c07cb30: /* original 942e, guest PC 0x0c07cb30 */
if(!s->budget--) { s->failed_pc=0x0c07cb30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb90u,2);
goto P_0c07cb32;
P_0c07cb32: /* original 66b3, guest PC 0x0c07cb32 */
if(!s->budget--) { s->failed_pc=0x0c07cb32u; return 0; }
r[6]=r[11];
goto P_0c07cb34;
P_0c07cb34: /* original 4d0b, guest PC 0x0c07cb34 */
if(!s->budget--) { s->failed_pc=0x0c07cb34u; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb38u;
r[5]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb38u) { target=s->pc; goto dispatch; }
goto P_0c07cb38;
P_0c07cb36: /* original 65b3, guest PC 0x0c07cb36 */
if(!s->budget--) { s->failed_pc=0x0c07cb36u; return 0; }
r[5]=r[11];
goto P_0c07cb38;
P_0c07cb38: /* original 942b, guest PC 0x0c07cb38 */
if(!s->budget--) { s->failed_pc=0x0c07cb38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb92u,2);
goto P_0c07cb3a;
P_0c07cb3a: /* original 66b3, guest PC 0x0c07cb3a */
if(!s->budget--) { s->failed_pc=0x0c07cb3au; return 0; }
r[6]=r[11];
goto P_0c07cb3c;
P_0c07cb3c: /* original 4d0b, guest PC 0x0c07cb3c */
if(!s->budget--) { s->failed_pc=0x0c07cb3cu; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb40u;
r[5]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb40u) { target=s->pc; goto dispatch; }
goto P_0c07cb40;
P_0c07cb3e: /* original 65b3, guest PC 0x0c07cb3e */
if(!s->budget--) { s->failed_pc=0x0c07cb3eu; return 0; }
r[5]=r[11];
goto P_0c07cb40;
P_0c07cb40: /* original 9428, guest PC 0x0c07cb40 */
if(!s->budget--) { s->failed_pc=0x0c07cb40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb94u,2);
goto P_0c07cb42;
P_0c07cb42: /* original 66b3, guest PC 0x0c07cb42 */
if(!s->budget--) { s->failed_pc=0x0c07cb42u; return 0; }
r[6]=r[11];
goto P_0c07cb44;
P_0c07cb44: /* original 4d0b, guest PC 0x0c07cb44 */
if(!s->budget--) { s->failed_pc=0x0c07cb44u; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb48u;
r[5]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb48u) { target=s->pc; goto dispatch; }
goto P_0c07cb48;
P_0c07cb46: /* original 65b3, guest PC 0x0c07cb46 */
if(!s->budget--) { s->failed_pc=0x0c07cb46u; return 0; }
r[5]=r[11];
goto P_0c07cb48;
P_0c07cb48: /* original e010, guest PC 0x0c07cb48 */
if(!s->budget--) { s->failed_pc=0x0c07cb48u; return 0; }
r[0]=0x00000010u;
goto P_0c07cb4a;
P_0c07cb4a: /* original 02cc, guest PC 0x0c07cb4a */
if(!s->budget--) { s->failed_pc=0x0c07cb4au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07cb4c;
P_0c07cb4c: /* original 7201, guest PC 0x0c07cb4c */
if(!s->budget--) { s->failed_pc=0x0c07cb4cu; return 0; }
r[2]+=0x00000001u;
goto P_0c07cb4e;
P_0c07cb4e: /* original 0c24, guest PC 0x0c07cb4e */
if(!s->budget--) { s->failed_pc=0x0c07cb4eu; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c07cb50;
P_0c07cb50: /* original d21b, guest PC 0x0c07cb50 */
if(!s->budget--) { s->failed_pc=0x0c07cb50u; return 0; }
r[2]=read(ram,0x0c07cbc0u,4);
goto P_0c07cb52;
P_0c07cb52: /* original 53f2, guest PC 0x0c07cb52 */
if(!s->budget--) { s->failed_pc=0x0c07cb52u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07cb54;
P_0c07cb54: /* original 1324, guest PC 0x0c07cb54 */
if(!s->budget--) { s->failed_pc=0x0c07cb54u; return 0; }
write(ram,r[3]+16,r[2],4);
goto P_0c07cb56;
P_0c07cb56: /* original dd1b, guest PC 0x0c07cb56 */
if(!s->budget--) { s->failed_pc=0x0c07cb56u; return 0; }
r[13]=read(ram,0x0c07cbc4u,4);
goto P_0c07cb58;
P_0c07cb58: /* original 4d0b, guest PC 0x0c07cb58 */
if(!s->budget--) { s->failed_pc=0x0c07cb58u; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb5cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb5cu) { target=s->pc; goto dispatch; }
goto P_0c07cb5c;
P_0c07cb5a: /* original 64e3, guest PC 0x0c07cb5a */
if(!s->budget--) { s->failed_pc=0x0c07cb5au; return 0; }
r[4]=r[14];
goto P_0c07cb5c;
P_0c07cb5c: /* original 64e3, guest PC 0x0c07cb5c */
if(!s->budget--) { s->failed_pc=0x0c07cb5cu; return 0; }
r[4]=r[14];
goto P_0c07cb5e;
P_0c07cb5e: /* original 4d0b, guest PC 0x0c07cb5e */
if(!s->budget--) { s->failed_pc=0x0c07cb5eu; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb62u;
r[4]+=0x00000058u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb62u) { target=s->pc; goto dispatch; }
goto P_0c07cb62;
P_0c07cb60: /* original 7458, guest PC 0x0c07cb60 */
if(!s->budget--) { s->failed_pc=0x0c07cb60u; return 0; }
r[4]+=0x00000058u;
goto P_0c07cb62;
P_0c07cb62: /* original 64e3, guest PC 0x0c07cb62 */
if(!s->budget--) { s->failed_pc=0x0c07cb62u; return 0; }
r[4]=r[14];
goto P_0c07cb64;
P_0c07cb64: /* original 4d0b, guest PC 0x0c07cb64 */
if(!s->budget--) { s->failed_pc=0x0c07cb64u; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb68u;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb68u) { target=s->pc; goto dispatch; }
goto P_0c07cb68;
P_0c07cb66: /* original 742c, guest PC 0x0c07cb66 */
if(!s->budget--) { s->failed_pc=0x0c07cb66u; return 0; }
r[4]+=0x0000002cu;
goto P_0c07cb68;
P_0c07cb68: /* original 9415, guest PC 0x0c07cb68 */
if(!s->budget--) { s->failed_pc=0x0c07cb68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cb96u,2);
goto P_0c07cb6a;
P_0c07cb6a: /* original 4d0b, guest PC 0x0c07cb6a */
if(!s->budget--) { s->failed_pc=0x0c07cb6au; return 0; }
target=r[13];
r[16]=code_base|0x0c07cb6eu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cb6eu) { target=s->pc; goto dispatch; }
goto P_0c07cb6e;
P_0c07cb6c: /* original 34ec, guest PC 0x0c07cb6c */
if(!s->budget--) { s->failed_pc=0x0c07cb6cu; return 0; }
r[4]+=r[14];
goto P_0c07cb6e;
P_0c07cb6e: /* original 64f2, guest PC 0x0c07cb6e */
if(!s->budget--) { s->failed_pc=0x0c07cb6eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07cb70;
P_0c07cb70: /* original 55f1, guest PC 0x0c07cb70 */
if(!s->budget--) { s->failed_pc=0x0c07cb70u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07cb72;
P_0c07cb72: /* original 7f0c, guest PC 0x0c07cb72 */
if(!s->budget--) { s->failed_pc=0x0c07cb72u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07cb74;
P_0c07cb74: /* original 4f26, guest PC 0x0c07cb74 */
if(!s->budget--) { s->failed_pc=0x0c07cb74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07cb76;
P_0c07cb76: /* original 6bf6, guest PC 0x0c07cb76 */
if(!s->budget--) { s->failed_pc=0x0c07cb76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07cb78;
P_0c07cb78: /* original 6cf6, guest PC 0x0c07cb78 */
if(!s->budget--) { s->failed_pc=0x0c07cb78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07cb7a;
P_0c07cb7a: /* original 6df6, guest PC 0x0c07cb7a */
if(!s->budget--) { s->failed_pc=0x0c07cb7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07cb7c;
P_0c07cb7c: /* original a024, guest PC 0x0c07cb7c */
if(!s->budget--) { s->failed_pc=0x0c07cb7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07cbc8;
P_0c07cb7e: /* original 6ef6, guest PC 0x0c07cb7e */
if(!s->budget--) { s->failed_pc=0x0c07cb7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07cb80u,s,ram);
P_0c07cbc8: /* original 2fe6, guest PC 0x0c07cbc8 */
if(!s->budget--) { s->failed_pc=0x0c07cbc8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cbca;
P_0c07cbca: /* original 2fd6, guest PC 0x0c07cbca */
if(!s->budget--) { s->failed_pc=0x0c07cbcau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cbcc;
P_0c07cbcc: /* original 2fc6, guest PC 0x0c07cbcc */
if(!s->budget--) { s->failed_pc=0x0c07cbccu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cbce;
P_0c07cbce: /* original 2fb6, guest PC 0x0c07cbce */
if(!s->budget--) { s->failed_pc=0x0c07cbceu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cbd0;
P_0c07cbd0: /* original 2fa6, guest PC 0x0c07cbd0 */
if(!s->budget--) { s->failed_pc=0x0c07cbd0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cbd2;
P_0c07cbd2: /* original 2f96, guest PC 0x0c07cbd2 */
if(!s->budget--) { s->failed_pc=0x0c07cbd2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cbd4;
P_0c07cbd4: /* original 2f86, guest PC 0x0c07cbd4 */
if(!s->budget--) { s->failed_pc=0x0c07cbd4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cbd6;
P_0c07cbd6: /* original fffb, guest PC 0x0c07cbd6 */
if(!s->budget--) { s->failed_pc=0x0c07cbd6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07cbd8;
P_0c07cbd8: /* original ffeb, guest PC 0x0c07cbd8 */
if(!s->budget--) { s->failed_pc=0x0c07cbd8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c07cbda;
P_0c07cbda: /* original 4f22, guest PC 0x0c07cbda */
if(!s->budget--) { s->failed_pc=0x0c07cbdau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07cbdc;
P_0c07cbdc: /* original db5b, guest PC 0x0c07cbdc */
if(!s->budget--) { s->failed_pc=0x0c07cbdcu; return 0; }
r[11]=read(ram,0x0c07cd4cu,4);
goto P_0c07cbde;
P_0c07cbde: /* original 7fdc, guest PC 0x0c07cbde */
if(!s->budget--) { s->failed_pc=0x0c07cbdeu; return 0; }
r[15]+=0xffffffdcu;
goto P_0c07cbe0;
P_0c07cbe0: /* original 1f44, guest PC 0x0c07cbe0 */
if(!s->budget--) { s->failed_pc=0x0c07cbe0u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c07cbe2;
P_0c07cbe2: /* original 64b3, guest PC 0x0c07cbe2 */
if(!s->budget--) { s->failed_pc=0x0c07cbe2u; return 0; }
r[4]=r[11];
goto P_0c07cbe4;
P_0c07cbe4: /* original 534b, guest PC 0x0c07cbe4 */
if(!s->budget--) { s->failed_pc=0x0c07cbe4u; return 0; }
r[3]=read(ram,r[4]+44,4);
goto P_0c07cbe6;
P_0c07cbe6: /* original 4315, guest PC 0x0c07cbe6 */
if(!s->budget--) { s->failed_pc=0x0c07cbe6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07cbe8;
P_0c07cbe8: /* original 8d02, guest PC 0x0c07cbe8 */
if(!s->budget--) { s->failed_pc=0x0c07cbe8u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c07cbf0; }
goto P_0c07cbec;
P_0c07cbea: /* original 6e53, guest PC 0x0c07cbea */
if(!s->budget--) { s->failed_pc=0x0c07cbeau; return 0; }
r[14]=r[5];
goto P_0c07cbec;
P_0c07cbec: /* original a15f, guest PC 0x0c07cbec */
if(!s->budget--) { s->failed_pc=0x0c07cbecu; return 0; }
goto P_0c07ceae;
P_0c07cbee: /* original 0009, guest PC 0x0c07cbee */
if(!s->budget--) { s->failed_pc=0x0c07cbeeu; return 0; }
goto P_0c07cbf0;
P_0c07cbf0: /* original 52f4, guest PC 0x0c07cbf0 */
if(!s->budget--) { s->failed_pc=0x0c07cbf0u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c07cbf2;
P_0c07cbf2: /* original e53e, guest PC 0x0c07cbf2 */
if(!s->budget--) { s->failed_pc=0x0c07cbf2u; return 0; }
r[5]=0x0000003eu;
goto P_0c07cbf4;
P_0c07cbf4: /* original 1f25, guest PC 0x0c07cbf4 */
if(!s->budget--) { s->failed_pc=0x0c07cbf4u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07cbf6;
P_0c07cbf6: /* original d156, guest PC 0x0c07cbf6 */
if(!s->budget--) { s->failed_pc=0x0c07cbf6u; return 0; }
r[1]=read(ram,0x0c07cd50u,4);
goto P_0c07cbf8;
P_0c07cbf8: /* original 6312, guest PC 0x0c07cbf8 */
if(!s->budget--) { s->failed_pc=0x0c07cbf8u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c07cbfa;
P_0c07cbfa: /* original 1f38, guest PC 0x0c07cbfa */
if(!s->budget--) { s->failed_pc=0x0c07cbfau; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c07cbfc;
P_0c07cbfc: /* original d455, guest PC 0x0c07cbfc */
if(!s->budget--) { s->failed_pc=0x0c07cbfcu; return 0; }
r[4]=read(ram,0x0c07cd54u,4);
goto P_0c07cbfe;
P_0c07cbfe: /* original 6343, guest PC 0x0c07cbfe */
if(!s->budget--) { s->failed_pc=0x0c07cbfeu; return 0; }
r[3]=r[4];
goto P_0c07cc00;
P_0c07cc00: /* original 6d43, guest PC 0x0c07cc00 */
if(!s->budget--) { s->failed_pc=0x0c07cc00u; return 0; }
r[13]=r[4];
goto P_0c07cc02;
P_0c07cc02: /* original 62d3, guest PC 0x0c07cc02 */
if(!s->budget--) { s->failed_pc=0x0c07cc02u; return 0; }
r[2]=r[13];
goto P_0c07cc04;
P_0c07cc04: /* original 7358, guest PC 0x0c07cc04 */
if(!s->budget--) { s->failed_pc=0x0c07cc04u; return 0; }
r[3]+=0x00000058u;
goto P_0c07cc06;
P_0c07cc06: /* original 722c, guest PC 0x0c07cc06 */
if(!s->budget--) { s->failed_pc=0x0c07cc06u; return 0; }
r[2]+=0x0000002cu;
goto P_0c07cc08;
P_0c07cc08: /* original 1f31, guest PC 0x0c07cc08 */
if(!s->budget--) { s->failed_pc=0x0c07cc08u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07cc0a;
P_0c07cc0a: /* original 1f26, guest PC 0x0c07cc0a */
if(!s->budget--) { s->failed_pc=0x0c07cc0au; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c07cc0c;
P_0c07cc0c: /* original 938d, guest PC 0x0c07cc0c */
if(!s->budget--) { s->failed_pc=0x0c07cc0cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd2au,2);
goto P_0c07cc0e;
P_0c07cc0e: /* original 334c, guest PC 0x0c07cc0e */
if(!s->budget--) { s->failed_pc=0x0c07cc0eu; return 0; }
r[3]+=r[4];
goto P_0c07cc10;
P_0c07cc10: /* original 1f37, guest PC 0x0c07cc10 */
if(!s->budget--) { s->failed_pc=0x0c07cc10u; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c07cc12;
P_0c07cc12: /* original d251, guest PC 0x0c07cc12 */
if(!s->budget--) { s->failed_pc=0x0c07cc12u; return 0; }
r[2]=read(ram,0x0c07cd58u,4);
goto P_0c07cc14;
P_0c07cc14: /* original 6422, guest PC 0x0c07cc14 */
if(!s->budget--) { s->failed_pc=0x0c07cc14u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c07cc16;
P_0c07cc16: /* original 3453, guest PC 0x0c07cc16 */
if(!s->budget--) { s->failed_pc=0x0c07cc16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c07cc18;
P_0c07cc18: /* original 8901, guest PC 0x0c07cc18 */
if(!s->budget--) { s->failed_pc=0x0c07cc18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07cc1e; }
goto P_0c07cc1a;
P_0c07cc1a: /* original a0e7, guest PC 0x0c07cc1a */
if(!s->budget--) { s->failed_pc=0x0c07cc1au; return 0; }
goto P_0c07cdec;
P_0c07cc1c: /* original 0009, guest PC 0x0c07cc1c */
if(!s->budget--) { s->failed_pc=0x0c07cc1cu; return 0; }
goto P_0c07cc1e;
P_0c07cc1e: /* original 3457, guest PC 0x0c07cc1e */
if(!s->budget--) { s->failed_pc=0x0c07cc1eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c07cc20;
P_0c07cc20: /* original 8b01, guest PC 0x0c07cc20 */
if(!s->budget--) { s->failed_pc=0x0c07cc20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07cc26; }
goto P_0c07cc22;
P_0c07cc22: /* original a144, guest PC 0x0c07cc22 */
if(!s->budget--) { s->failed_pc=0x0c07cc22u; return 0; }
goto P_0c07ceae;
P_0c07cc24: /* original 0009, guest PC 0x0c07cc24 */
if(!s->budget--) { s->failed_pc=0x0c07cc24u; return 0; }
goto P_0c07cc26;
P_0c07cc26: /* original ee00, guest PC 0x0c07cc26 */
if(!s->budget--) { s->failed_pc=0x0c07cc26u; return 0; }
r[14]=0x00000000u;
goto P_0c07cc28;
P_0c07cc28: /* original dc4c, guest PC 0x0c07cc28 */
if(!s->budget--) { s->failed_pc=0x0c07cc28u; return 0; }
r[12]=read(ram,0x0c07cd5cu,4);
goto P_0c07cc2a;
P_0c07cc2a: /* original 2fe6, guest PC 0x0c07cc2a */
if(!s->budget--) { s->failed_pc=0x0c07cc2au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cc2c;
P_0c07cc2c: /* original 67e3, guest PC 0x0c07cc2c */
if(!s->budget--) { s->failed_pc=0x0c07cc2cu; return 0; }
r[7]=r[14];
goto P_0c07cc2e;
P_0c07cc2e: /* original 56f2, guest PC 0x0c07cc2e */
if(!s->budget--) { s->failed_pc=0x0c07cc2eu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c07cc30;
P_0c07cc30: /* original 957c, guest PC 0x0c07cc30 */
if(!s->budget--) { s->failed_pc=0x0c07cc30u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd2cu,2);
goto P_0c07cc32;
P_0c07cc32: /* original 4c0b, guest PC 0x0c07cc32 */
if(!s->budget--) { s->failed_pc=0x0c07cc32u; return 0; }
target=r[12];
r[16]=code_base|0x0c07cc36u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cc36u) { target=s->pc; goto dispatch; }
goto P_0c07cc36;
P_0c07cc34: /* original 64e3, guest PC 0x0c07cc34 */
if(!s->budget--) { s->failed_pc=0x0c07cc34u; return 0; }
r[4]=r[14];
goto P_0c07cc36;
P_0c07cc36: /* original 937a, guest PC 0x0c07cc36 */
if(!s->budget--) { s->failed_pc=0x0c07cc36u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd2eu,2);
goto P_0c07cc38;
P_0c07cc38: /* original 67e3, guest PC 0x0c07cc38 */
if(!s->budget--) { s->failed_pc=0x0c07cc38u; return 0; }
r[7]=r[14];
goto P_0c07cc3a;
P_0c07cc3a: /* original 1f31, guest PC 0x0c07cc3a */
if(!s->budget--) { s->failed_pc=0x0c07cc3au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07cc3c;
P_0c07cc3c: /* original 2fe6, guest PC 0x0c07cc3c */
if(!s->budget--) { s->failed_pc=0x0c07cc3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cc3e;
P_0c07cc3e: /* original 9577, guest PC 0x0c07cc3e */
if(!s->budget--) { s->failed_pc=0x0c07cc3eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd30u,2);
goto P_0c07cc40;
P_0c07cc40: /* original 56f3, guest PC 0x0c07cc40 */
if(!s->budget--) { s->failed_pc=0x0c07cc40u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c07cc42;
P_0c07cc42: /* original 4c0b, guest PC 0x0c07cc42 */
if(!s->budget--) { s->failed_pc=0x0c07cc42u; return 0; }
target=r[12];
r[16]=code_base|0x0c07cc46u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cc46u) { target=s->pc; goto dispatch; }
goto P_0c07cc46;
P_0c07cc44: /* original 54f2, guest PC 0x0c07cc44 */
if(!s->budget--) { s->failed_pc=0x0c07cc44u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07cc46;
P_0c07cc46: /* original 9370, guest PC 0x0c07cc46 */
if(!s->budget--) { s->failed_pc=0x0c07cc46u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd2au,2);
goto P_0c07cc48;
P_0c07cc48: /* original 66d3, guest PC 0x0c07cc48 */
if(!s->budget--) { s->failed_pc=0x0c07cc48u; return 0; }
r[6]=r[13];
goto P_0c07cc4a;
P_0c07cc4a: /* original 67e3, guest PC 0x0c07cc4a */
if(!s->budget--) { s->failed_pc=0x0c07cc4au; return 0; }
r[7]=r[14];
goto P_0c07cc4c;
P_0c07cc4c: /* original 1f32, guest PC 0x0c07cc4c */
if(!s->budget--) { s->failed_pc=0x0c07cc4cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07cc4e;
P_0c07cc4e: /* original 2fe6, guest PC 0x0c07cc4e */
if(!s->budget--) { s->failed_pc=0x0c07cc4eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cc50;
P_0c07cc50: /* original 956f, guest PC 0x0c07cc50 */
if(!s->budget--) { s->failed_pc=0x0c07cc50u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd32u,2);
goto P_0c07cc52;
P_0c07cc52: /* original 4c0b, guest PC 0x0c07cc52 */
if(!s->budget--) { s->failed_pc=0x0c07cc52u; return 0; }
target=r[12];
r[16]=code_base|0x0c07cc56u;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cc56u) { target=s->pc; goto dispatch; }
goto P_0c07cc56;
P_0c07cc54: /* original 54f3, guest PC 0x0c07cc54 */
if(!s->budget--) { s->failed_pc=0x0c07cc54u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07cc56;
P_0c07cc56: /* original 936d, guest PC 0x0c07cc56 */
if(!s->budget--) { s->failed_pc=0x0c07cc56u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd34u,2);
goto P_0c07cc58;
P_0c07cc58: /* original 66d3, guest PC 0x0c07cc58 */
if(!s->budget--) { s->failed_pc=0x0c07cc58u; return 0; }
r[6]=r[13];
goto P_0c07cc5a;
P_0c07cc5a: /* original 67e3, guest PC 0x0c07cc5a */
if(!s->budget--) { s->failed_pc=0x0c07cc5au; return 0; }
r[7]=r[14];
goto P_0c07cc5c;
P_0c07cc5c: /* original 1f33, guest PC 0x0c07cc5c */
if(!s->budget--) { s->failed_pc=0x0c07cc5cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07cc5e;
P_0c07cc5e: /* original 2fe6, guest PC 0x0c07cc5e */
if(!s->budget--) { s->failed_pc=0x0c07cc5eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cc60;
P_0c07cc60: /* original 9569, guest PC 0x0c07cc60 */
if(!s->budget--) { s->failed_pc=0x0c07cc60u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd36u,2);
goto P_0c07cc62;
P_0c07cc62: /* original 4c0b, guest PC 0x0c07cc62 */
if(!s->budget--) { s->failed_pc=0x0c07cc62u; return 0; }
target=r[12];
r[16]=code_base|0x0c07cc66u;
r[4]=read(ram,r[15]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cc66u) { target=s->pc; goto dispatch; }
goto P_0c07cc66;
P_0c07cc64: /* original 54f4, guest PC 0x0c07cc64 */
if(!s->budget--) { s->failed_pc=0x0c07cc64u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07cc66;
P_0c07cc66: /* original 9367, guest PC 0x0c07cc66 */
if(!s->budget--) { s->failed_pc=0x0c07cc66u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd38u,2);
goto P_0c07cc68;
P_0c07cc68: /* original 66d3, guest PC 0x0c07cc68 */
if(!s->budget--) { s->failed_pc=0x0c07cc68u; return 0; }
r[6]=r[13];
goto P_0c07cc6a;
P_0c07cc6a: /* original 67e3, guest PC 0x0c07cc6a */
if(!s->budget--) { s->failed_pc=0x0c07cc6au; return 0; }
r[7]=r[14];
goto P_0c07cc6c;
P_0c07cc6c: /* original 1f34, guest PC 0x0c07cc6c */
if(!s->budget--) { s->failed_pc=0x0c07cc6cu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07cc6e;
P_0c07cc6e: /* original 9a64, guest PC 0x0c07cc6e */
if(!s->budget--) { s->failed_pc=0x0c07cc6eu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd3au,2);
goto P_0c07cc70;
P_0c07cc70: /* original 2fe6, guest PC 0x0c07cc70 */
if(!s->budget--) { s->failed_pc=0x0c07cc70u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cc72;
P_0c07cc72: /* original 65a3, guest PC 0x0c07cc72 */
if(!s->budget--) { s->failed_pc=0x0c07cc72u; return 0; }
r[5]=r[10];
goto P_0c07cc74;
P_0c07cc74: /* original 4c0b, guest PC 0x0c07cc74 */
if(!s->budget--) { s->failed_pc=0x0c07cc74u; return 0; }
target=r[12];
r[16]=code_base|0x0c07cc78u;
r[4]=read(ram,r[15]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cc78u) { target=s->pc; goto dispatch; }
goto P_0c07cc78;
P_0c07cc76: /* original 54f5, guest PC 0x0c07cc76 */
if(!s->budget--) { s->failed_pc=0x0c07cc76u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07cc78;
P_0c07cc78: /* original 54b2, guest PC 0x0c07cc78 */
if(!s->budget--) { s->failed_pc=0x0c07cc78u; return 0; }
r[4]=read(ram,r[11]+8,4);
goto P_0c07cc7a;
P_0c07cc7a: /* original e304, guest PC 0x0c07cc7a */
if(!s->budget--) { s->failed_pc=0x0c07cc7au; return 0; }
r[3]=0x00000004u;
goto P_0c07cc7c;
P_0c07cc7c: /* original 2438, guest PC 0x0c07cc7c */
if(!s->budget--) { s->failed_pc=0x0c07cc7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c07cc7e;
P_0c07cc7e: /* original 8f02, guest PC 0x0c07cc7e */
if(!s->budget--) { s->failed_pc=0x0c07cc7eu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000014u;
if(!cond) { goto P_0c07cc86; }
goto P_0c07cc82;
P_0c07cc80: /* original 7f14, guest PC 0x0c07cc80 */
if(!s->budget--) { s->failed_pc=0x0c07cc80u; return 0; }
r[15]+=0x00000014u;
goto P_0c07cc82;
P_0c07cc82: /* original a0aa, guest PC 0x0c07cc82 */
if(!s->budget--) { s->failed_pc=0x0c07cc82u; return 0; }
goto P_0c07cdda;
P_0c07cc84: /* original 0009, guest PC 0x0c07cc84 */
if(!s->budget--) { s->failed_pc=0x0c07cc84u; return 0; }
goto P_0c07cc86;
P_0c07cc86: /* original 66d3, guest PC 0x0c07cc86 */
if(!s->budget--) { s->failed_pc=0x0c07cc86u; return 0; }
r[6]=r[13];
goto P_0c07cc88;
P_0c07cc88: /* original 2fe6, guest PC 0x0c07cc88 */
if(!s->budget--) { s->failed_pc=0x0c07cc88u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cc8a;
P_0c07cc8a: /* original 9455, guest PC 0x0c07cc8a */
if(!s->budget--) { s->failed_pc=0x0c07cc8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd38u,2);
goto P_0c07cc8c;
P_0c07cc8c: /* original e700, guest PC 0x0c07cc8c */
if(!s->budget--) { s->failed_pc=0x0c07cc8cu; return 0; }
r[7]=0x00000000u;
goto P_0c07cc8e;
P_0c07cc8e: /* original d134, guest PC 0x0c07cc8e */
if(!s->budget--) { s->failed_pc=0x0c07cc8eu; return 0; }
r[1]=read(ram,0x0c07cd60u,4);
goto P_0c07cc90;
P_0c07cc90: /* original 410b, guest PC 0x0c07cc90 */
if(!s->budget--) { s->failed_pc=0x0c07cc90u; return 0; }
target=r[1];
r[16]=code_base|0x0c07cc94u;
r[5]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cc94u) { target=s->pc; goto dispatch; }
goto P_0c07cc94;
P_0c07cc92: /* original 65a3, guest PC 0x0c07cc92 */
if(!s->budget--) { s->failed_pc=0x0c07cc92u; return 0; }
r[5]=r[10];
goto P_0c07cc94;
P_0c07cc94: /* original 2fe6, guest PC 0x0c07cc94 */
if(!s->budget--) { s->failed_pc=0x0c07cc94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cc96;
P_0c07cc96: /* original e700, guest PC 0x0c07cc96 */
if(!s->budget--) { s->failed_pc=0x0c07cc96u; return 0; }
r[7]=0x00000000u;
goto P_0c07cc98;
P_0c07cc98: /* original 944c, guest PC 0x0c07cc98 */
if(!s->budget--) { s->failed_pc=0x0c07cc98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd34u,2);
goto P_0c07cc9a;
P_0c07cc9a: /* original d331, guest PC 0x0c07cc9a */
if(!s->budget--) { s->failed_pc=0x0c07cc9au; return 0; }
r[3]=read(ram,0x0c07cd60u,4);
goto P_0c07cc9c;
P_0c07cc9c: /* original 954b, guest PC 0x0c07cc9c */
if(!s->budget--) { s->failed_pc=0x0c07cc9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd36u,2);
goto P_0c07cc9e;
P_0c07cc9e: /* original 430b, guest PC 0x0c07cc9e */
if(!s->budget--) { s->failed_pc=0x0c07cc9eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07cca2u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cca2u) { target=s->pc; goto dispatch; }
goto P_0c07cca2;
P_0c07cca0: /* original 66d3, guest PC 0x0c07cca0 */
if(!s->budget--) { s->failed_pc=0x0c07cca0u; return 0; }
r[6]=r[13];
goto P_0c07cca2;
P_0c07cca2: /* original 924b, guest PC 0x0c07cca2 */
if(!s->budget--) { s->failed_pc=0x0c07cca2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd3cu,2);
goto P_0c07cca4;
P_0c07cca4: /* original 66d3, guest PC 0x0c07cca4 */
if(!s->budget--) { s->failed_pc=0x0c07cca4u; return 0; }
r[6]=r[13];
goto P_0c07cca6;
P_0c07cca6: /* original 65a3, guest PC 0x0c07cca6 */
if(!s->budget--) { s->failed_pc=0x0c07cca6u; return 0; }
r[5]=r[10];
goto P_0c07cca8;
P_0c07cca8: /* original e700, guest PC 0x0c07cca8 */
if(!s->budget--) { s->failed_pc=0x0c07cca8u; return 0; }
r[7]=0x00000000u;
goto P_0c07ccaa;
P_0c07ccaa: /* original 1f22, guest PC 0x0c07ccaa */
if(!s->budget--) { s->failed_pc=0x0c07ccaau; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c07ccac;
P_0c07ccac: /* original 2fe6, guest PC 0x0c07ccac */
if(!s->budget--) { s->failed_pc=0x0c07ccacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ccae;
P_0c07ccae: /* original 4c0b, guest PC 0x0c07ccae */
if(!s->budget--) { s->failed_pc=0x0c07ccaeu; return 0; }
target=r[12];
r[16]=code_base|0x0c07ccb2u;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ccb2u) { target=s->pc; goto dispatch; }
goto P_0c07ccb2;
P_0c07ccb0: /* original 54f3, guest PC 0x0c07ccb0 */
if(!s->budget--) { s->failed_pc=0x0c07ccb0u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07ccb2;
P_0c07ccb2: /* original 9344, guest PC 0x0c07ccb2 */
if(!s->budget--) { s->failed_pc=0x0c07ccb2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd3eu,2);
goto P_0c07ccb4;
P_0c07ccb4: /* original 66d3, guest PC 0x0c07ccb4 */
if(!s->budget--) { s->failed_pc=0x0c07ccb4u; return 0; }
r[6]=r[13];
goto P_0c07ccb6;
P_0c07ccb6: /* original e700, guest PC 0x0c07ccb6 */
if(!s->budget--) { s->failed_pc=0x0c07ccb6u; return 0; }
r[7]=0x00000000u;
goto P_0c07ccb8;
P_0c07ccb8: /* original 1f33, guest PC 0x0c07ccb8 */
if(!s->budget--) { s->failed_pc=0x0c07ccb8u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07ccba;
P_0c07ccba: /* original 2fe6, guest PC 0x0c07ccba */
if(!s->budget--) { s->failed_pc=0x0c07ccbau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ccbc;
P_0c07ccbc: /* original 9540, guest PC 0x0c07ccbc */
if(!s->budget--) { s->failed_pc=0x0c07ccbcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd40u,2);
goto P_0c07ccbe;
P_0c07ccbe: /* original 4c0b, guest PC 0x0c07ccbe */
if(!s->budget--) { s->failed_pc=0x0c07ccbeu; return 0; }
target=r[12];
r[16]=code_base|0x0c07ccc2u;
r[4]=read(ram,r[15]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ccc2u) { target=s->pc; goto dispatch; }
goto P_0c07ccc2;
P_0c07ccc0: /* original 54f4, guest PC 0x0c07ccc0 */
if(!s->budget--) { s->failed_pc=0x0c07ccc0u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07ccc2;
P_0c07ccc2: /* original 903e, guest PC 0x0c07ccc2 */
if(!s->budget--) { s->failed_pc=0x0c07ccc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd42u,2);
goto P_0c07ccc4;
P_0c07ccc4: /* original 03bc, guest PC 0x0c07ccc4 */
if(!s->budget--) { s->failed_pc=0x0c07ccc4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c07ccc6;
P_0c07ccc6: /* original 1f34, guest PC 0x0c07ccc6 */
if(!s->budget--) { s->failed_pc=0x0c07ccc6u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07ccc8;
P_0c07ccc8: /* original 6633, guest PC 0x0c07ccc8 */
if(!s->budget--) { s->failed_pc=0x0c07ccc8u; return 0; }
r[6]=r[3];
goto P_0c07ccca;
P_0c07ccca: /* original 973b, guest PC 0x0c07ccca */
if(!s->budget--) { s->failed_pc=0x0c07cccau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd44u,2);
goto P_0c07cccc;
P_0c07cccc: /* original d225, guest PC 0x0c07cccc */
if(!s->budget--) { s->failed_pc=0x0c07ccccu; return 0; }
r[2]=read(ram,0x0c07cd64u,4);
goto P_0c07ccce;
P_0c07ccce: /* original 9531, guest PC 0x0c07ccce */
if(!s->budget--) { s->failed_pc=0x0c07ccceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd34u,2);
goto P_0c07ccd0;
P_0c07ccd0: /* original 420b, guest PC 0x0c07ccd0 */
if(!s->budget--) { s->failed_pc=0x0c07ccd0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07ccd4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ccd4u) { target=s->pc; goto dispatch; }
goto P_0c07ccd4;
P_0c07ccd2: /* original 64d3, guest PC 0x0c07ccd2 */
if(!s->budget--) { s->failed_pc=0x0c07ccd2u; return 0; }
r[4]=r[13];
goto P_0c07ccd4;
P_0c07ccd4: /* original 9437, guest PC 0x0c07ccd4 */
if(!s->budget--) { s->failed_pc=0x0c07ccd4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd46u,2);
goto P_0c07ccd6;
P_0c07ccd6: /* original e600, guest PC 0x0c07ccd6 */
if(!s->budget--) { s->failed_pc=0x0c07ccd6u; return 0; }
r[6]=0x00000000u;
goto P_0c07ccd8;
P_0c07ccd8: /* original da23, guest PC 0x0c07ccd8 */
if(!s->budget--) { s->failed_pc=0x0c07ccd8u; return 0; }
r[10]=read(ram,0x0c07cd68u,4);
goto P_0c07ccda;
P_0c07ccda: /* original 4a0b, guest PC 0x0c07ccda */
if(!s->budget--) { s->failed_pc=0x0c07ccdau; return 0; }
target=r[10];
r[16]=code_base|0x0c07ccdeu;
r[5]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ccdeu) { target=s->pc; goto dispatch; }
goto P_0c07ccde;
P_0c07ccdc: /* original e501, guest PC 0x0c07ccdc */
if(!s->budget--) { s->failed_pc=0x0c07ccdcu; return 0; }
r[5]=0x00000001u;
goto P_0c07ccde;
P_0c07ccde: /* original 9433, guest PC 0x0c07ccde */
if(!s->budget--) { s->failed_pc=0x0c07ccdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd48u,2);
goto P_0c07cce0;
P_0c07cce0: /* original e600, guest PC 0x0c07cce0 */
if(!s->budget--) { s->failed_pc=0x0c07cce0u; return 0; }
r[6]=0x00000000u;
goto P_0c07cce2;
P_0c07cce2: /* original 4a0b, guest PC 0x0c07cce2 */
if(!s->budget--) { s->failed_pc=0x0c07cce2u; return 0; }
target=r[10];
r[16]=code_base|0x0c07cce6u;
r[5]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cce6u) { target=s->pc; goto dispatch; }
goto P_0c07cce6;
P_0c07cce4: /* original e501, guest PC 0x0c07cce4 */
if(!s->budget--) { s->failed_pc=0x0c07cce4u; return 0; }
r[5]=0x00000001u;
goto P_0c07cce6;
P_0c07cce6: /* original 9430, guest PC 0x0c07cce6 */
if(!s->budget--) { s->failed_pc=0x0c07cce6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd4au,2);
goto P_0c07cce8;
P_0c07cce8: /* original e600, guest PC 0x0c07cce8 */
if(!s->budget--) { s->failed_pc=0x0c07cce8u; return 0; }
r[6]=0x00000000u;
goto P_0c07ccea;
P_0c07ccea: /* original 4a0b, guest PC 0x0c07ccea */
if(!s->budget--) { s->failed_pc=0x0c07cceau; return 0; }
target=r[10];
r[16]=code_base|0x0c07cceeu;
r[5]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cceeu) { target=s->pc; goto dispatch; }
goto P_0c07ccee;
P_0c07ccec: /* original e501, guest PC 0x0c07ccec */
if(!s->budget--) { s->failed_pc=0x0c07ccecu; return 0; }
r[5]=0x00000001u;
goto P_0c07ccee;
P_0c07ccee: /* original c720, guest PC 0x0c07ccee */
if(!s->budget--) { s->failed_pc=0x0c07cceeu; return 0; }
r[0]=0x0c07cd70u;
goto P_0c07ccf0;
P_0c07ccf0: /* original da22, guest PC 0x0c07ccf0 */
if(!s->budget--) { s->failed_pc=0x0c07ccf0u; return 0; }
r[10]=read(ram,0x0c07cd7cu,4);
goto P_0c07ccf2;
P_0c07ccf2: /* original fe08, guest PC 0x0c07ccf2 */
if(!s->budget--) { s->failed_pc=0x0c07ccf2u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c07ccf4;
P_0c07ccf4: /* original c720, guest PC 0x0c07ccf4 */
if(!s->budget--) { s->failed_pc=0x0c07ccf4u; return 0; }
r[0]=0x0c07cd78u;
goto P_0c07ccf6;
P_0c07ccf6: /* original ff08, guest PC 0x0c07ccf6 */
if(!s->budget--) { s->failed_pc=0x0c07ccf6u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c07ccf8;
P_0c07ccf8: /* original 66a3, guest PC 0x0c07ccf8 */
if(!s->budget--) { s->failed_pc=0x0c07ccf8u; return 0; }
r[6]=r[10];
goto P_0c07ccfa;
P_0c07ccfa: /* original d91e, guest PC 0x0c07ccfa */
if(!s->budget--) { s->failed_pc=0x0c07ccfau; return 0; }
r[9]=read(ram,0x0c07cd74u,4);
goto P_0c07ccfc;
P_0c07ccfc: /* original d81b, guest PC 0x0c07ccfc */
if(!s->budget--) { s->failed_pc=0x0c07ccfcu; return 0; }
r[8]=read(ram,0x0c07cd6cu,4);
goto P_0c07ccfe;
P_0c07ccfe: /* original 6793, guest PC 0x0c07ccfe */
if(!s->budget--) { s->failed_pc=0x0c07ccfeu; return 0; }
r[7]=r[9];
goto P_0c07cd00;
P_0c07cd00: /* original 2fe6, guest PC 0x0c07cd00 */
if(!s->budget--) { s->failed_pc=0x0c07cd00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cd02;
P_0c07cd02: /* original 9413, guest PC 0x0c07cd02 */
if(!s->budget--) { s->failed_pc=0x0c07cd02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd2cu,2);
goto P_0c07cd04;
P_0c07cd04: /* original f5fc, guest PC 0x0c07cd04 */
if(!s->budget--) { s->failed_pc=0x0c07cd04u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c07cd06;
P_0c07cd06: /* original f4ec, guest PC 0x0c07cd06 */
if(!s->budget--) { s->failed_pc=0x0c07cd06u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07cd08;
P_0c07cd08: /* original 480b, guest PC 0x0c07cd08 */
if(!s->budget--) { s->failed_pc=0x0c07cd08u; return 0; }
target=r[8];
r[16]=code_base|0x0c07cd0cu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cd0cu) { target=s->pc; goto dispatch; }
goto P_0c07cd0c;
P_0c07cd0a: /* original e500, guest PC 0x0c07cd0a */
if(!s->budget--) { s->failed_pc=0x0c07cd0au; return 0; }
r[5]=0x00000000u;
goto P_0c07cd0c;
P_0c07cd0c: /* original 6793, guest PC 0x0c07cd0c */
if(!s->budget--) { s->failed_pc=0x0c07cd0cu; return 0; }
r[7]=r[9];
goto P_0c07cd0e;
P_0c07cd0e: /* original 66a3, guest PC 0x0c07cd0e */
if(!s->budget--) { s->failed_pc=0x0c07cd0eu; return 0; }
r[6]=r[10];
goto P_0c07cd10;
P_0c07cd10: /* original 2fe6, guest PC 0x0c07cd10 */
if(!s->budget--) { s->failed_pc=0x0c07cd10u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cd12;
P_0c07cd12: /* original 940d, guest PC 0x0c07cd12 */
if(!s->budget--) { s->failed_pc=0x0c07cd12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cd30u,2);
goto P_0c07cd14;
P_0c07cd14: /* original f5fc, guest PC 0x0c07cd14 */
if(!s->budget--) { s->failed_pc=0x0c07cd14u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c07cd16;
P_0c07cd16: /* original f4ec, guest PC 0x0c07cd16 */
if(!s->budget--) { s->failed_pc=0x0c07cd16u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07cd18;
P_0c07cd18: /* original 480b, guest PC 0x0c07cd18 */
if(!s->budget--) { s->failed_pc=0x0c07cd18u; return 0; }
target=r[8];
r[16]=code_base|0x0c07cd1cu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cd1cu) { target=s->pc; goto dispatch; }
goto P_0c07cd1c;
P_0c07cd1a: /* original e500, guest PC 0x0c07cd1a */
if(!s->budget--) { s->failed_pc=0x0c07cd1au; return 0; }
r[5]=0x00000000u;
goto P_0c07cd1c;
P_0c07cd1c: /* original 6793, guest PC 0x0c07cd1c */
if(!s->budget--) { s->failed_pc=0x0c07cd1cu; return 0; }
r[7]=r[9];
goto P_0c07cd1e;
P_0c07cd1e: /* original 66a3, guest PC 0x0c07cd1e */
if(!s->budget--) { s->failed_pc=0x0c07cd1eu; return 0; }
r[6]=r[10];
goto P_0c07cd20;
P_0c07cd20: /* original 2fe6, guest PC 0x0c07cd20 */
if(!s->budget--) { s->failed_pc=0x0c07cd20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cd22;
P_0c07cd22: /* original f4ec, guest PC 0x0c07cd22 */
if(!s->budget--) { s->failed_pc=0x0c07cd22u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07cd24;
P_0c07cd24: /* original f5fc, guest PC 0x0c07cd24 */
if(!s->budget--) { s->failed_pc=0x0c07cd24u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c07cd26;
P_0c07cd26: /* original a02b, guest PC 0x0c07cd26 */
if(!s->budget--) { s->failed_pc=0x0c07cd26u; return 0; }
r[5]=0x00000000u;
goto P_0c07cd80;
P_0c07cd28: /* original e500, guest PC 0x0c07cd28 */
if(!s->budget--) { s->failed_pc=0x0c07cd28u; return 0; }
r[5]=0x00000000u;
return vf3_matrix_family(0x0c07cd2au,s,ram);
P_0c07cd80: /* original 94a5, guest PC 0x0c07cd80 */
if(!s->budget--) { s->failed_pc=0x0c07cd80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ceceu,2);
goto P_0c07cd82;
P_0c07cd82: /* original 480b, guest PC 0x0c07cd82 */
if(!s->budget--) { s->failed_pc=0x0c07cd82u; return 0; }
target=r[8];
r[16]=code_base|0x0c07cd86u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cd86u) { target=s->pc; goto dispatch; }
goto P_0c07cd86;
P_0c07cd84: /* original 0009, guest PC 0x0c07cd84 */
if(!s->budget--) { s->failed_pc=0x0c07cd84u; return 0; }
goto P_0c07cd86;
P_0c07cd86: /* original 6793, guest PC 0x0c07cd86 */
if(!s->budget--) { s->failed_pc=0x0c07cd86u; return 0; }
r[7]=r[9];
goto P_0c07cd88;
P_0c07cd88: /* original 66a3, guest PC 0x0c07cd88 */
if(!s->budget--) { s->failed_pc=0x0c07cd88u; return 0; }
r[6]=r[10];
goto P_0c07cd8a;
P_0c07cd8a: /* original 2fe6, guest PC 0x0c07cd8a */
if(!s->budget--) { s->failed_pc=0x0c07cd8au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cd8c;
P_0c07cd8c: /* original 94a0, guest PC 0x0c07cd8c */
if(!s->budget--) { s->failed_pc=0x0c07cd8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ced0u,2);
goto P_0c07cd8e;
P_0c07cd8e: /* original f5fc, guest PC 0x0c07cd8e */
if(!s->budget--) { s->failed_pc=0x0c07cd8eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c07cd90;
P_0c07cd90: /* original f4ec, guest PC 0x0c07cd90 */
if(!s->budget--) { s->failed_pc=0x0c07cd90u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07cd92;
P_0c07cd92: /* original 480b, guest PC 0x0c07cd92 */
if(!s->budget--) { s->failed_pc=0x0c07cd92u; return 0; }
target=r[8];
r[16]=code_base|0x0c07cd96u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cd96u) { target=s->pc; goto dispatch; }
goto P_0c07cd96;
P_0c07cd94: /* original e500, guest PC 0x0c07cd94 */
if(!s->budget--) { s->failed_pc=0x0c07cd94u; return 0; }
r[5]=0x00000000u;
goto P_0c07cd96;
P_0c07cd96: /* original 6793, guest PC 0x0c07cd96 */
if(!s->budget--) { s->failed_pc=0x0c07cd96u; return 0; }
r[7]=r[9];
goto P_0c07cd98;
P_0c07cd98: /* original 66a3, guest PC 0x0c07cd98 */
if(!s->budget--) { s->failed_pc=0x0c07cd98u; return 0; }
r[6]=r[10];
goto P_0c07cd9a;
P_0c07cd9a: /* original 2fe6, guest PC 0x0c07cd9a */
if(!s->budget--) { s->failed_pc=0x0c07cd9au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cd9c;
P_0c07cd9c: /* original 9499, guest PC 0x0c07cd9c */
if(!s->budget--) { s->failed_pc=0x0c07cd9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ced2u,2);
goto P_0c07cd9e;
P_0c07cd9e: /* original f5fc, guest PC 0x0c07cd9e */
if(!s->budget--) { s->failed_pc=0x0c07cd9eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c07cda0;
P_0c07cda0: /* original f4ec, guest PC 0x0c07cda0 */
if(!s->budget--) { s->failed_pc=0x0c07cda0u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07cda2;
P_0c07cda2: /* original 480b, guest PC 0x0c07cda2 */
if(!s->budget--) { s->failed_pc=0x0c07cda2u; return 0; }
target=r[8];
r[16]=code_base|0x0c07cda6u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cda6u) { target=s->pc; goto dispatch; }
goto P_0c07cda6;
P_0c07cda4: /* original e500, guest PC 0x0c07cda4 */
if(!s->budget--) { s->failed_pc=0x0c07cda4u; return 0; }
r[5]=0x00000000u;
goto P_0c07cda6;
P_0c07cda6: /* original 6793, guest PC 0x0c07cda6 */
if(!s->budget--) { s->failed_pc=0x0c07cda6u; return 0; }
r[7]=r[9];
goto P_0c07cda8;
P_0c07cda8: /* original 66a3, guest PC 0x0c07cda8 */
if(!s->budget--) { s->failed_pc=0x0c07cda8u; return 0; }
r[6]=r[10];
goto P_0c07cdaa;
P_0c07cdaa: /* original 2fe6, guest PC 0x0c07cdaa */
if(!s->budget--) { s->failed_pc=0x0c07cdaau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cdac;
P_0c07cdac: /* original 9492, guest PC 0x0c07cdac */
if(!s->budget--) { s->failed_pc=0x0c07cdacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ced4u,2);
goto P_0c07cdae;
P_0c07cdae: /* original f5fc, guest PC 0x0c07cdae */
if(!s->budget--) { s->failed_pc=0x0c07cdaeu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c07cdb0;
P_0c07cdb0: /* original f4ec, guest PC 0x0c07cdb0 */
if(!s->budget--) { s->failed_pc=0x0c07cdb0u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07cdb2;
P_0c07cdb2: /* original 480b, guest PC 0x0c07cdb2 */
if(!s->budget--) { s->failed_pc=0x0c07cdb2u; return 0; }
target=r[8];
r[16]=code_base|0x0c07cdb6u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cdb6u) { target=s->pc; goto dispatch; }
goto P_0c07cdb6;
P_0c07cdb4: /* original e500, guest PC 0x0c07cdb4 */
if(!s->budget--) { s->failed_pc=0x0c07cdb4u; return 0; }
r[5]=0x00000000u;
goto P_0c07cdb6;
P_0c07cdb6: /* original 6793, guest PC 0x0c07cdb6 */
if(!s->budget--) { s->failed_pc=0x0c07cdb6u; return 0; }
r[7]=r[9];
goto P_0c07cdb8;
P_0c07cdb8: /* original 66a3, guest PC 0x0c07cdb8 */
if(!s->budget--) { s->failed_pc=0x0c07cdb8u; return 0; }
r[6]=r[10];
goto P_0c07cdba;
P_0c07cdba: /* original 2fe6, guest PC 0x0c07cdba */
if(!s->budget--) { s->failed_pc=0x0c07cdbau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cdbc;
P_0c07cdbc: /* original 948b, guest PC 0x0c07cdbc */
if(!s->budget--) { s->failed_pc=0x0c07cdbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ced6u,2);
goto P_0c07cdbe;
P_0c07cdbe: /* original f5fc, guest PC 0x0c07cdbe */
if(!s->budget--) { s->failed_pc=0x0c07cdbeu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c07cdc0;
P_0c07cdc0: /* original f4ec, guest PC 0x0c07cdc0 */
if(!s->budget--) { s->failed_pc=0x0c07cdc0u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07cdc2;
P_0c07cdc2: /* original 480b, guest PC 0x0c07cdc2 */
if(!s->budget--) { s->failed_pc=0x0c07cdc2u; return 0; }
target=r[8];
r[16]=code_base|0x0c07cdc6u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cdc6u) { target=s->pc; goto dispatch; }
goto P_0c07cdc6;
P_0c07cdc4: /* original e500, guest PC 0x0c07cdc4 */
if(!s->budget--) { s->failed_pc=0x0c07cdc4u; return 0; }
r[5]=0x00000000u;
goto P_0c07cdc6;
P_0c07cdc6: /* original 9387, guest PC 0x0c07cdc6 */
if(!s->budget--) { s->failed_pc=0x0c07cdc6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ced8u,2);
goto P_0c07cdc8;
P_0c07cdc8: /* original e201, guest PC 0x0c07cdc8 */
if(!s->budget--) { s->failed_pc=0x0c07cdc8u; return 0; }
r[2]=0x00000001u;
goto P_0c07cdca;
P_0c07cdca: /* original 1f3b, guest PC 0x0c07cdca */
if(!s->budget--) { s->failed_pc=0x0c07cdcau; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c07cdcc;
P_0c07cdcc: /* original 2f26, guest PC 0x0c07cdcc */
if(!s->budget--) { s->failed_pc=0x0c07cdccu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07cdce;
P_0c07cdce: /* original 9584, guest PC 0x0c07cdce */
if(!s->budget--) { s->failed_pc=0x0c07cdceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cedau,2);
goto P_0c07cdd0;
P_0c07cdd0: /* original 56fd, guest PC 0x0c07cdd0 */
if(!s->budget--) { s->failed_pc=0x0c07cdd0u; return 0; }
r[6]=read(ram,r[15]+52,4);
goto P_0c07cdd2;
P_0c07cdd2: /* original d745, guest PC 0x0c07cdd2 */
if(!s->budget--) { s->failed_pc=0x0c07cdd2u; return 0; }
r[7]=read(ram,0x0c07cee8u,4);
goto P_0c07cdd4;
P_0c07cdd4: /* original 4c0b, guest PC 0x0c07cdd4 */
if(!s->budget--) { s->failed_pc=0x0c07cdd4u; return 0; }
target=r[12];
r[16]=code_base|0x0c07cdd8u;
r[4]=read(ram,r[15]+48,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cdd8u) { target=s->pc; goto dispatch; }
goto P_0c07cdd8;
P_0c07cdd6: /* original 54fc, guest PC 0x0c07cdd6 */
if(!s->budget--) { s->failed_pc=0x0c07cdd6u; return 0; }
r[4]=read(ram,r[15]+48,4);
goto P_0c07cdd8;
P_0c07cdd8: /* original 7f30, guest PC 0x0c07cdd8 */
if(!s->budget--) { s->failed_pc=0x0c07cdd8u; return 0; }
r[15]+=0x00000030u;
goto P_0c07cdda;
P_0c07cdda: /* original b099, guest PC 0x0c07cdda */
if(!s->budget--) { s->failed_pc=0x0c07cddau; return 0; }
target=0x0c07cf10u; r[16]=code_base|0x0c07cddeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cddeu) { target=s->pc; goto dispatch; }
goto P_0c07cdde;
P_0c07cddc: /* original 0009, guest PC 0x0c07cddc */
if(!s->budget--) { s->failed_pc=0x0c07cddcu; return 0; }
goto P_0c07cdde;
P_0c07cdde: /* original d343, guest PC 0x0c07cdde */
if(!s->budget--) { s->failed_pc=0x0c07cddeu; return 0; }
r[3]=read(ram,0x0c07ceecu,4);
goto P_0c07cde0;
P_0c07cde0: /* original 430b, guest PC 0x0c07cde0 */
if(!s->budget--) { s->failed_pc=0x0c07cde0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07cde4u;
r[4]=read(ram,r[15]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cde4u) { target=s->pc; goto dispatch; }
goto P_0c07cde4;
P_0c07cde2: /* original 54f8, guest PC 0x0c07cde2 */
if(!s->budget--) { s->failed_pc=0x0c07cde2u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c07cde4;
P_0c07cde4: /* original 907a, guest PC 0x0c07cde4 */
if(!s->budget--) { s->failed_pc=0x0c07cde4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cedcu,2);
goto P_0c07cde6;
P_0c07cde6: /* original e33c, guest PC 0x0c07cde6 */
if(!s->budget--) { s->failed_pc=0x0c07cde6u; return 0; }
r[3]=0x0000003cu;
goto P_0c07cde8;
P_0c07cde8: /* original 52f5, guest PC 0x0c07cde8 */
if(!s->budget--) { s->failed_pc=0x0c07cde8u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07cdea;
P_0c07cdea: /* original 0236, guest PC 0x0c07cdea */
if(!s->budget--) { s->failed_pc=0x0c07cdeau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c07cdec;
P_0c07cdec: /* original d240, guest PC 0x0c07cdec */
if(!s->budget--) { s->failed_pc=0x0c07cdecu; return 0; }
r[2]=read(ram,0x0c07cef0u,4);
goto P_0c07cdee;
P_0c07cdee: /* original 420b, guest PC 0x0c07cdee */
if(!s->budget--) { s->failed_pc=0x0c07cdeeu; return 0; }
target=r[2];
r[16]=code_base|0x0c07cdf2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07cdf2u) { target=s->pc; goto dispatch; }
goto P_0c07cdf2;
P_0c07cdf0: /* original 0009, guest PC 0x0c07cdf0 */
if(!s->budget--) { s->failed_pc=0x0c07cdf0u; return 0; }
goto P_0c07cdf2;
P_0c07cdf2: /* original 9073, guest PC 0x0c07cdf2 */
if(!s->budget--) { s->failed_pc=0x0c07cdf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cedcu,2);
goto P_0c07cdf4;
P_0c07cdf4: /* original e308, guest PC 0x0c07cdf4 */
if(!s->budget--) { s->failed_pc=0x0c07cdf4u; return 0; }
r[3]=0x00000008u;
goto P_0c07cdf6;
P_0c07cdf6: /* original 54f5, guest PC 0x0c07cdf6 */
if(!s->budget--) { s->failed_pc=0x0c07cdf6u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07cdf8;
P_0c07cdf8: /* original 044e, guest PC 0x0c07cdf8 */
if(!s->budget--) { s->failed_pc=0x0c07cdf8u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07cdfa;
P_0c07cdfa: /* original 3436, guest PC 0x0c07cdfa */
if(!s->budget--) { s->failed_pc=0x0c07cdfau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c07cdfc;
P_0c07cdfc: /* original 890b, guest PC 0x0c07cdfc */
if(!s->budget--) { s->failed_pc=0x0c07cdfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ce16; }
goto P_0c07cdfe;
P_0c07cdfe: /* original 6043, guest PC 0x0c07cdfe */
if(!s->budget--) { s->failed_pc=0x0c07cdfeu; return 0; }
r[0]=r[4];
goto P_0c07ce00;
P_0c07ce00: /* original 8808, guest PC 0x0c07ce00 */
if(!s->budget--) { s->failed_pc=0x0c07ce00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c07ce02;
P_0c07ce02: /* original 8b08, guest PC 0x0c07ce02 */
if(!s->budget--) { s->failed_pc=0x0c07ce02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ce16; }
goto P_0c07ce04;
P_0c07ce04: /* original d23b, guest PC 0x0c07ce04 */
if(!s->budget--) { s->failed_pc=0x0c07ce04u; return 0; }
r[2]=read(ram,0x0c07cef4u,4);
goto P_0c07ce06;
P_0c07ce06: /* original 420b, guest PC 0x0c07ce06 */
if(!s->budget--) { s->failed_pc=0x0c07ce06u; return 0; }
target=r[2];
r[16]=code_base|0x0c07ce0au;
r[4]=read(ram,r[15]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce0au) { target=s->pc; goto dispatch; }
goto P_0c07ce0a;
P_0c07ce08: /* original 54f6, guest PC 0x0c07ce08 */
if(!s->budget--) { s->failed_pc=0x0c07ce08u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c07ce0a;
P_0c07ce0a: /* original d33a, guest PC 0x0c07ce0a */
if(!s->budget--) { s->failed_pc=0x0c07ce0au; return 0; }
r[3]=read(ram,0x0c07cef4u,4);
goto P_0c07ce0c;
P_0c07ce0c: /* original 430b, guest PC 0x0c07ce0c */
if(!s->budget--) { s->failed_pc=0x0c07ce0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07ce10u;
r[4]=read(ram,r[15]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce10u) { target=s->pc; goto dispatch; }
goto P_0c07ce10;
P_0c07ce0e: /* original 54f7, guest PC 0x0c07ce0e */
if(!s->budget--) { s->failed_pc=0x0c07ce0eu; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c07ce10;
P_0c07ce10: /* original d237, guest PC 0x0c07ce10 */
if(!s->budget--) { s->failed_pc=0x0c07ce10u; return 0; }
r[2]=read(ram,0x0c07cef0u,4);
goto P_0c07ce12;
P_0c07ce12: /* original 420b, guest PC 0x0c07ce12 */
if(!s->budget--) { s->failed_pc=0x0c07ce12u; return 0; }
target=r[2];
r[16]=code_base|0x0c07ce16u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce16u) { target=s->pc; goto dispatch; }
goto P_0c07ce16;
P_0c07ce14: /* original 0009, guest PC 0x0c07ce14 */
if(!s->budget--) { s->failed_pc=0x0c07ce14u; return 0; }
goto P_0c07ce16;
P_0c07ce16: /* original b092, guest PC 0x0c07ce16 */
if(!s->budget--) { s->failed_pc=0x0c07ce16u; return 0; }
target=0x0c07cf3eu; r[16]=code_base|0x0c07ce1au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce1au) { target=s->pc; goto dispatch; }
goto P_0c07ce1a;
P_0c07ce18: /* original 0009, guest PC 0x0c07ce18 */
if(!s->budget--) { s->failed_pc=0x0c07ce18u; return 0; }
goto P_0c07ce1a;
P_0c07ce1a: /* original 65f3, guest PC 0x0c07ce1a */
if(!s->budget--) { s->failed_pc=0x0c07ce1au; return 0; }
r[5]=r[15];
goto P_0c07ce1c;
P_0c07ce1c: /* original 64f3, guest PC 0x0c07ce1c */
if(!s->budget--) { s->failed_pc=0x0c07ce1cu; return 0; }
r[4]=r[15];
goto P_0c07ce1e;
P_0c07ce1e: /* original 750c, guest PC 0x0c07ce1e */
if(!s->budget--) { s->failed_pc=0x0c07ce1eu; return 0; }
r[5]+=0x0000000cu;
goto P_0c07ce20;
P_0c07ce20: /* original b3c7, guest PC 0x0c07ce20 */
if(!s->budget--) { s->failed_pc=0x0c07ce20u; return 0; }
target=0x0c07d5b2u; r[16]=code_base|0x0c07ce24u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce24u) { target=s->pc; goto dispatch; }
goto P_0c07ce24;
P_0c07ce22: /* original 7408, guest PC 0x0c07ce22 */
if(!s->budget--) { s->failed_pc=0x0c07ce22u; return 0; }
r[4]+=0x00000008u;
goto P_0c07ce24;
P_0c07ce24: /* original 55f3, guest PC 0x0c07ce24 */
if(!s->budget--) { s->failed_pc=0x0c07ce24u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07ce26;
P_0c07ce26: /* original b1f5, guest PC 0x0c07ce26 */
if(!s->budget--) { s->failed_pc=0x0c07ce26u; return 0; }
target=0x0c07d214u; r[16]=code_base|0x0c07ce2au;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce2au) { target=s->pc; goto dispatch; }
goto P_0c07ce2a;
P_0c07ce28: /* original 54f2, guest PC 0x0c07ce28 */
if(!s->budget--) { s->failed_pc=0x0c07ce28u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07ce2a;
P_0c07ce2a: /* original 50b2, guest PC 0x0c07ce2a */
if(!s->budget--) { s->failed_pc=0x0c07ce2au; return 0; }
r[0]=read(ram,r[11]+8,4);
goto P_0c07ce2c;
P_0c07ce2c: /* original c804, guest PC 0x0c07ce2c */
if(!s->budget--) { s->failed_pc=0x0c07ce2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c07ce2e;
P_0c07ce2e: /* original 8908, guest PC 0x0c07ce2e */
if(!s->budget--) { s->failed_pc=0x0c07ce2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ce42; }
goto P_0c07ce30;
P_0c07ce30: /* original 9055, guest PC 0x0c07ce30 */
if(!s->budget--) { s->failed_pc=0x0c07ce30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cedeu,2);
goto P_0c07ce32;
P_0c07ce32: /* original 03bc, guest PC 0x0c07ce32 */
if(!s->budget--) { s->failed_pc=0x0c07ce32u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c07ce34;
P_0c07ce34: /* original 1f31, guest PC 0x0c07ce34 */
if(!s->budget--) { s->failed_pc=0x0c07ce34u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07ce36;
P_0c07ce36: /* original 6633, guest PC 0x0c07ce36 */
if(!s->budget--) { s->failed_pc=0x0c07ce36u; return 0; }
r[6]=r[3];
goto P_0c07ce38;
P_0c07ce38: /* original 9753, guest PC 0x0c07ce38 */
if(!s->budget--) { s->failed_pc=0x0c07ce38u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cee2u,2);
goto P_0c07ce3a;
P_0c07ce3a: /* original d22f, guest PC 0x0c07ce3a */
if(!s->budget--) { s->failed_pc=0x0c07ce3au; return 0; }
r[2]=read(ram,0x0c07cef8u,4);
goto P_0c07ce3c;
P_0c07ce3c: /* original 9550, guest PC 0x0c07ce3c */
if(!s->budget--) { s->failed_pc=0x0c07ce3cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cee0u,2);
goto P_0c07ce3e;
P_0c07ce3e: /* original 420b, guest PC 0x0c07ce3e */
if(!s->budget--) { s->failed_pc=0x0c07ce3eu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ce42u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce42u) { target=s->pc; goto dispatch; }
goto P_0c07ce42;
P_0c07ce40: /* original 64d3, guest PC 0x0c07ce40 */
if(!s->budget--) { s->failed_pc=0x0c07ce40u; return 0; }
r[4]=r[13];
goto P_0c07ce42;
P_0c07ce42: /* original 54bb, guest PC 0x0c07ce42 */
if(!s->budget--) { s->failed_pc=0x0c07ce42u; return 0; }
r[4]=read(ram,r[11]+44,4);
goto P_0c07ce44;
P_0c07ce44: /* original e00a, guest PC 0x0c07ce44 */
if(!s->budget--) { s->failed_pc=0x0c07ce44u; return 0; }
r[0]=0x0000000au;
goto P_0c07ce46;
P_0c07ce46: /* original d32d, guest PC 0x0c07ce46 */
if(!s->budget--) { s->failed_pc=0x0c07ce46u; return 0; }
r[3]=read(ram,0x0c07cefcu,4);
goto P_0c07ce48;
P_0c07ce48: /* original 4409, guest PC 0x0c07ce48 */
if(!s->budget--) { s->failed_pc=0x0c07ce48u; return 0; }
r[4]>>=2;
goto P_0c07ce4a;
P_0c07ce4a: /* original 4409, guest PC 0x0c07ce4a */
if(!s->budget--) { s->failed_pc=0x0c07ce4au; return 0; }
r[4]>>=2;
goto P_0c07ce4c;
P_0c07ce4c: /* original 4409, guest PC 0x0c07ce4c */
if(!s->budget--) { s->failed_pc=0x0c07ce4cu; return 0; }
r[4]>>=2;
goto P_0c07ce4e;
P_0c07ce4e: /* original 430b, guest PC 0x0c07ce4e */
if(!s->budget--) { s->failed_pc=0x0c07ce4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07ce52u;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce52u) { target=s->pc; goto dispatch; }
goto P_0c07ce52;
P_0c07ce50: /* original 6143, guest PC 0x0c07ce50 */
if(!s->budget--) { s->failed_pc=0x0c07ce50u; return 0; }
r[1]=r[4];
goto P_0c07ce52;
P_0c07ce52: /* original 6503, guest PC 0x0c07ce52 */
if(!s->budget--) { s->failed_pc=0x0c07ce52u; return 0; }
r[5]=r[0];
goto P_0c07ce54;
P_0c07ce54: /* original 4508, guest PC 0x0c07ce54 */
if(!s->budget--) { s->failed_pc=0x0c07ce54u; return 0; }
r[5]<<=2;
goto P_0c07ce56;
P_0c07ce56: /* original 6303, guest PC 0x0c07ce56 */
if(!s->budget--) { s->failed_pc=0x0c07ce56u; return 0; }
r[3]=r[0];
goto P_0c07ce58;
P_0c07ce58: /* original 353c, guest PC 0x0c07ce58 */
if(!s->budget--) { s->failed_pc=0x0c07ce58u; return 0; }
r[5]+=r[3];
goto P_0c07ce5a;
P_0c07ce5a: /* original 4500, guest PC 0x0c07ce5a */
if(!s->budget--) { s->failed_pc=0x0c07ce5au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07ce5c;
P_0c07ce5c: /* original 6c03, guest PC 0x0c07ce5c */
if(!s->budget--) { s->failed_pc=0x0c07ce5cu; return 0; }
r[12]=r[0];
goto P_0c07ce5e;
P_0c07ce5e: /* original 3458, guest PC 0x0c07ce5e */
if(!s->budget--) { s->failed_pc=0x0c07ce5eu; return 0; }
r[4]-=r[5];
goto P_0c07ce60;
P_0c07ce60: /* original 55b2, guest PC 0x0c07ce60 */
if(!s->budget--) { s->failed_pc=0x0c07ce60u; return 0; }
r[5]=read(ram,r[11]+8,4);
goto P_0c07ce62;
P_0c07ce62: /* original e204, guest PC 0x0c07ce62 */
if(!s->budget--) { s->failed_pc=0x0c07ce62u; return 0; }
r[2]=0x00000004u;
goto P_0c07ce64;
P_0c07ce64: /* original 2528, guest PC 0x0c07ce64 */
if(!s->budget--) { s->failed_pc=0x0c07ce64u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c07ce66;
P_0c07ce66: /* original 8d06, guest PC 0x0c07ce66 */
if(!s->budget--) { s->failed_pc=0x0c07ce66u; return 0; }
cond=r[17]&1u;
r[14]=0x00000035u;
if(cond) { goto P_0c07ce76; }
goto P_0c07ce6a;
P_0c07ce68: /* original ee35, guest PC 0x0c07ce68 */
if(!s->budget--) { s->failed_pc=0x0c07ce68u; return 0; }
r[14]=0x00000035u;
goto P_0c07ce6a;
P_0c07ce6a: /* original 9038, guest PC 0x0c07ce6a */
if(!s->budget--) { s->failed_pc=0x0c07ce6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cedeu,2);
goto P_0c07ce6c;
P_0c07ce6c: /* original e301, guest PC 0x0c07ce6c */
if(!s->budget--) { s->failed_pc=0x0c07ce6cu; return 0; }
r[3]=0x00000001u;
goto P_0c07ce6e;
P_0c07ce6e: /* original 05bc, guest PC 0x0c07ce6e */
if(!s->budget--) { s->failed_pc=0x0c07ce6eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c07ce70;
P_0c07ce70: /* original 3536, guest PC 0x0c07ce70 */
if(!s->budget--) { s->failed_pc=0x0c07ce70u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[3])!=0);
goto P_0c07ce72;
P_0c07ce72: /* original 8b00, guest PC 0x0c07ce72 */
if(!s->budget--) { s->failed_pc=0x0c07ce72u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ce76; }
goto P_0c07ce74;
P_0c07ce74: /* original ee36, guest PC 0x0c07ce74 */
if(!s->budget--) { s->failed_pc=0x0c07ce74u; return 0; }
r[14]=0x00000036u;
goto P_0c07ce76;
P_0c07ce76: /* original 60e3, guest PC 0x0c07ce76 */
if(!s->budget--) { s->failed_pc=0x0c07ce76u; return 0; }
r[0]=r[14];
goto P_0c07ce78;
P_0c07ce78: /* original 4000, guest PC 0x0c07ce78 */
if(!s->budget--) { s->failed_pc=0x0c07ce78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07ce7a;
P_0c07ce7a: /* original 66c3, guest PC 0x0c07ce7a */
if(!s->budget--) { s->failed_pc=0x0c07ce7au; return 0; }
r[6]=r[12];
goto P_0c07ce7c;
P_0c07ce7c: /* original 1f41, guest PC 0x0c07ce7c */
if(!s->budget--) { s->failed_pc=0x0c07ce7cu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07ce7e;
P_0c07ce7e: /* original 9531, guest PC 0x0c07ce7e */
if(!s->budget--) { s->failed_pc=0x0c07ce7eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cee4u,2);
goto P_0c07ce80;
P_0c07ce80: /* original 972f, guest PC 0x0c07ce80 */
if(!s->budget--) { s->failed_pc=0x0c07ce80u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cee2u,2);
goto P_0c07ce82;
P_0c07ce82: /* original d31d, guest PC 0x0c07ce82 */
if(!s->budget--) { s->failed_pc=0x0c07ce82u; return 0; }
r[3]=read(ram,0x0c07cef8u,4);
goto P_0c07ce84;
P_0c07ce84: /* original 250b, guest PC 0x0c07ce84 */
if(!s->budget--) { s->failed_pc=0x0c07ce84u; return 0; }
r[5]|=r[0];
goto P_0c07ce86;
P_0c07ce86: /* original 430b, guest PC 0x0c07ce86 */
if(!s->budget--) { s->failed_pc=0x0c07ce86u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ce8au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce8au) { target=s->pc; goto dispatch; }
goto P_0c07ce8a;
P_0c07ce88: /* original 64d3, guest PC 0x0c07ce88 */
if(!s->budget--) { s->failed_pc=0x0c07ce88u; return 0; }
r[4]=r[13];
goto P_0c07ce8a;
P_0c07ce8a: /* original 922b, guest PC 0x0c07ce8a */
if(!s->budget--) { s->failed_pc=0x0c07ce8au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cee4u,2);
goto P_0c07ce8c;
P_0c07ce8c: /* original 7e03, guest PC 0x0c07ce8c */
if(!s->budget--) { s->failed_pc=0x0c07ce8cu; return 0; }
r[14]+=0x00000003u;
goto P_0c07ce8e;
P_0c07ce8e: /* original 4e00, guest PC 0x0c07ce8e */
if(!s->budget--) { s->failed_pc=0x0c07ce8eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07ce90;
P_0c07ce90: /* original 56f1, guest PC 0x0c07ce90 */
if(!s->budget--) { s->failed_pc=0x0c07ce90u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c07ce92;
P_0c07ce92: /* original d319, guest PC 0x0c07ce92 */
if(!s->budget--) { s->failed_pc=0x0c07ce92u; return 0; }
r[3]=read(ram,0x0c07cef8u,4);
goto P_0c07ce94;
P_0c07ce94: /* original 2e2b, guest PC 0x0c07ce94 */
if(!s->budget--) { s->failed_pc=0x0c07ce94u; return 0; }
r[14]|=r[2];
goto P_0c07ce96;
P_0c07ce96: /* original 9724, guest PC 0x0c07ce96 */
if(!s->budget--) { s->failed_pc=0x0c07ce96u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07cee2u,2);
goto P_0c07ce98;
P_0c07ce98: /* original 65e3, guest PC 0x0c07ce98 */
if(!s->budget--) { s->failed_pc=0x0c07ce98u; return 0; }
r[5]=r[14];
goto P_0c07ce9a;
P_0c07ce9a: /* original 430b, guest PC 0x0c07ce9a */
if(!s->budget--) { s->failed_pc=0x0c07ce9au; return 0; }
target=r[3];
r[16]=code_base|0x0c07ce9eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ce9eu) { target=s->pc; goto dispatch; }
goto P_0c07ce9e;
P_0c07ce9c: /* original 64d3, guest PC 0x0c07ce9c */
if(!s->budget--) { s->failed_pc=0x0c07ce9cu; return 0; }
r[4]=r[13];
goto P_0c07ce9e;
P_0c07ce9e: /* original d119, guest PC 0x0c07ce9e */
if(!s->budget--) { s->failed_pc=0x0c07ce9eu; return 0; }
r[1]=read(ram,0x0c07cf04u,4);
goto P_0c07cea0;
P_0c07cea0: /* original d317, guest PC 0x0c07cea0 */
if(!s->budget--) { s->failed_pc=0x0c07cea0u; return 0; }
r[3]=read(ram,0x0c07cf00u,4);
goto P_0c07cea2;
P_0c07cea2: /* original 6212, guest PC 0x0c07cea2 */
if(!s->budget--) { s->failed_pc=0x0c07cea2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c07cea4;
P_0c07cea4: /* original 2238, guest PC 0x0c07cea4 */
if(!s->budget--) { s->failed_pc=0x0c07cea4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07cea6;
P_0c07cea6: /* original 8b02, guest PC 0x0c07cea6 */
if(!s->budget--) { s->failed_pc=0x0c07cea6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ceae; }
goto P_0c07cea8;
P_0c07cea8: /* original d317, guest PC 0x0c07cea8 */
if(!s->budget--) { s->failed_pc=0x0c07cea8u; return 0; }
r[3]=read(ram,0x0c07cf08u,4);
goto P_0c07ceaa;
P_0c07ceaa: /* original 430b, guest PC 0x0c07ceaa */
if(!s->budget--) { s->failed_pc=0x0c07ceaau; return 0; }
target=r[3];
r[16]=code_base|0x0c07ceaeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ceaeu) { target=s->pc; goto dispatch; }
goto P_0c07ceae;
P_0c07ceac: /* original 0009, guest PC 0x0c07ceac */
if(!s->budget--) { s->failed_pc=0x0c07ceacu; return 0; }
goto P_0c07ceae;
P_0c07ceae: /* original d317, guest PC 0x0c07ceae */
if(!s->budget--) { s->failed_pc=0x0c07ceaeu; return 0; }
r[3]=read(ram,0x0c07cf0cu,4);
goto P_0c07ceb0;
P_0c07ceb0: /* original 65e3, guest PC 0x0c07ceb0 */
if(!s->budget--) { s->failed_pc=0x0c07ceb0u; return 0; }
r[5]=r[14];
goto P_0c07ceb2;
P_0c07ceb2: /* original 430b, guest PC 0x0c07ceb2 */
if(!s->budget--) { s->failed_pc=0x0c07ceb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ceb6u;
r[4]=read(ram,r[15]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ceb6u) { target=s->pc; goto dispatch; }
goto P_0c07ceb6;
P_0c07ceb4: /* original 54f4, guest PC 0x0c07ceb4 */
if(!s->budget--) { s->failed_pc=0x0c07ceb4u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07ceb6;
P_0c07ceb6: /* original 7f24, guest PC 0x0c07ceb6 */
if(!s->budget--) { s->failed_pc=0x0c07ceb6u; return 0; }
r[15]+=0x00000024u;
goto P_0c07ceb8;
P_0c07ceb8: /* original 4f26, guest PC 0x0c07ceb8 */
if(!s->budget--) { s->failed_pc=0x0c07ceb8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ceba;
P_0c07ceba: /* original fef9, guest PC 0x0c07ceba */
if(!s->budget--) { s->failed_pc=0x0c07cebau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07cebc;
P_0c07cebc: /* original fff9, guest PC 0x0c07cebc */
if(!s->budget--) { s->failed_pc=0x0c07cebcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07cebe;
P_0c07cebe: /* original 68f6, guest PC 0x0c07cebe */
if(!s->budget--) { s->failed_pc=0x0c07cebeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07cec0;
P_0c07cec0: /* original 69f6, guest PC 0x0c07cec0 */
if(!s->budget--) { s->failed_pc=0x0c07cec0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07cec2;
P_0c07cec2: /* original 6af6, guest PC 0x0c07cec2 */
if(!s->budget--) { s->failed_pc=0x0c07cec2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07cec4;
P_0c07cec4: /* original 6bf6, guest PC 0x0c07cec4 */
if(!s->budget--) { s->failed_pc=0x0c07cec4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07cec6;
P_0c07cec6: /* original 6cf6, guest PC 0x0c07cec6 */
if(!s->budget--) { s->failed_pc=0x0c07cec6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07cec8;
P_0c07cec8: /* original 6df6, guest PC 0x0c07cec8 */
if(!s->budget--) { s->failed_pc=0x0c07cec8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ceca;
P_0c07ceca: /* original 000b, guest PC 0x0c07ceca */
if(!s->budget--) { s->failed_pc=0x0c07cecau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07cecc: /* original 6ef6, guest PC 0x0c07cecc */
if(!s->budget--) { s->failed_pc=0x0c07ceccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ceceu,s,ram);
P_0c08a8c2: /* original 9532, guest PC 0x0c08a8c2 */
if(!s->budget--) { s->failed_pc=0x0c08a8c2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a92au,2);
goto P_0c08a8c4;
P_0c08a8c4: /* original e600, guest PC 0x0c08a8c4 */
if(!s->budget--) { s->failed_pc=0x0c08a8c4u; return 0; }
r[6]=0x00000000u;
goto P_0c08a8c6;
P_0c08a8c6: /* original 4510, guest PC 0x0c08a8c6 */
if(!s->budget--) { s->failed_pc=0x0c08a8c6u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c08a8c8;
P_0c08a8c8: /* original 2462, guest PC 0x0c08a8c8 */
if(!s->budget--) { s->failed_pc=0x0c08a8c8u; return 0; }
write(ram,r[4],r[6],4);
goto P_0c08a8ca;
P_0c08a8ca: /* original 8ffc, guest PC 0x0c08a8ca */
if(!s->budget--) { s->failed_pc=0x0c08a8cau; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c08a8c6; }
goto P_0c08a8ce;
P_0c08a8cc: /* original 7404, guest PC 0x0c08a8cc */
if(!s->budget--) { s->failed_pc=0x0c08a8ccu; return 0; }
r[4]+=0x00000004u;
goto P_0c08a8ce;
P_0c08a8ce: /* original 000b, guest PC 0x0c08a8ce */
if(!s->budget--) { s->failed_pc=0x0c08a8ceu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c08a8d0: /* original 0009, guest PC 0x0c08a8d0 */
if(!s->budget--) { s->failed_pc=0x0c08a8d0u; return 0; }
return vf3_matrix_family(0x0c08a8d2u,s,ram);
P_0c08a942: /* original 4f22, guest PC 0x0c08a942 */
if(!s->budget--) { s->failed_pc=0x0c08a942u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a944;
P_0c08a944: /* original 9c71, guest PC 0x0c08a944 */
if(!s->budget--) { s->failed_pc=0x0c08a944u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08aa2au,2);
goto P_0c08a946;
P_0c08a946: /* original 7fec, guest PC 0x0c08a946 */
if(!s->budget--) { s->failed_pc=0x0c08a946u; return 0; }
r[15]+=0xffffffecu;
goto P_0c08a948;
P_0c08a948: /* original bfbb, guest PC 0x0c08a948 */
if(!s->budget--) { s->failed_pc=0x0c08a948u; return 0; }
target=0x0c08a8c2u; r[16]=code_base|0x0c08a94cu;
r[12]+=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a94cu) { target=s->pc; goto dispatch; }
goto P_0c08a94c;
P_0c08a94a: /* original 3cdc, guest PC 0x0c08a94a */
if(!s->budget--) { s->failed_pc=0x0c08a94au; return 0; }
r[12]+=r[13];
goto P_0c08a94c;
P_0c08a94c: /* original d538, guest PC 0x0c08a94c */
if(!s->budget--) { s->failed_pc=0x0c08a94cu; return 0; }
r[5]=read(ram,0x0c08aa30u,4);
goto P_0c08a94e;
P_0c08a94e: /* original e060, guest PC 0x0c08a94e */
if(!s->budget--) { s->failed_pc=0x0c08a94eu; return 0; }
r[0]=0x00000060u;
goto P_0c08a950;
P_0c08a950: /* original 976c, guest PC 0x0c08a950 */
if(!s->budget--) { s->failed_pc=0x0c08a950u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08aa2cu,2);
goto P_0c08a952;
P_0c08a952: /* original 5454, guest PC 0x0c08a952 */
if(!s->budget--) { s->failed_pc=0x0c08a952u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c08a954;
P_0c08a954: /* original 5655, guest PC 0x0c08a954 */
if(!s->budget--) { s->failed_pc=0x0c08a954u; return 0; }
r[6]=read(ram,r[5]+20,4);
goto P_0c08a956;
P_0c08a956: /* original 044c, guest PC 0x0c08a956 */
if(!s->budget--) { s->failed_pc=0x0c08a956u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08a958;
P_0c08a958: /* original 066c, guest PC 0x0c08a958 */
if(!s->budget--) { s->failed_pc=0x0c08a958u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c08a95a;
P_0c08a95a: /* original d036, guest PC 0x0c08a95a */
if(!s->budget--) { s->failed_pc=0x0c08a95au; return 0; }
r[0]=read(ram,0x0c08aa34u,4);
goto P_0c08a95c;
P_0c08a95c: /* original 644c, guest PC 0x0c08a95c */
if(!s->budget--) { s->failed_pc=0x0c08a95cu; return 0; }
r[4]=r[4]&255u;
goto P_0c08a95e;
P_0c08a95e: /* original 4400, guest PC 0x0c08a95e */
if(!s->budget--) { s->failed_pc=0x0c08a95eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08a960;
P_0c08a960: /* original 034d, guest PC 0x0c08a960 */
if(!s->budget--) { s->failed_pc=0x0c08a960u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08a962;
P_0c08a962: /* original 666c, guest PC 0x0c08a962 */
if(!s->budget--) { s->failed_pc=0x0c08a962u; return 0; }
r[6]=r[6]&255u;
goto P_0c08a964;
P_0c08a964: /* original 4600, guest PC 0x0c08a964 */
if(!s->budget--) { s->failed_pc=0x0c08a964u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c08a966;
P_0c08a966: /* original 3738, guest PC 0x0c08a966 */
if(!s->budget--) { s->failed_pc=0x0c08a966u; return 0; }
r[7]-=r[3];
goto P_0c08a968;
P_0c08a968: /* original 026d, guest PC 0x0c08a968 */
if(!s->budget--) { s->failed_pc=0x0c08a968u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c08a96a;
P_0c08a96a: /* original 6473, guest PC 0x0c08a96a */
if(!s->budget--) { s->failed_pc=0x0c08a96au; return 0; }
r[4]=r[7];
goto P_0c08a96c;
P_0c08a96c: /* original 3428, guest PC 0x0c08a96c */
if(!s->budget--) { s->failed_pc=0x0c08a96cu; return 0; }
r[4]-=r[2];
goto P_0c08a96e;
P_0c08a96e: /* original 4411, guest PC 0x0c08a96e */
if(!s->budget--) { s->failed_pc=0x0c08a96eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c08a970;
P_0c08a970: /* original 8d01, guest PC 0x0c08a970 */
if(!s->budget--) { s->failed_pc=0x0c08a970u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c08a976; }
goto P_0c08a974;
P_0c08a972: /* original e600, guest PC 0x0c08a972 */
if(!s->budget--) { s->failed_pc=0x0c08a972u; return 0; }
r[6]=0x00000000u;
goto P_0c08a974;
P_0c08a974: /* original 6463, guest PC 0x0c08a974 */
if(!s->budget--) { s->failed_pc=0x0c08a974u; return 0; }
r[4]=r[6];
goto P_0c08a976;
P_0c08a976: /* original 2d41, guest PC 0x0c08a976 */
if(!s->budget--) { s->failed_pc=0x0c08a976u; return 0; }
write(ram,r[13],r[4],2);
goto P_0c08a978;
P_0c08a978: /* original 6063, guest PC 0x0c08a978 */
if(!s->budget--) { s->failed_pc=0x0c08a978u; return 0; }
r[0]=r[6];
goto P_0c08a97a;
P_0c08a97a: /* original e60a, guest PC 0x0c08a97a */
if(!s->budget--) { s->failed_pc=0x0c08a97au; return 0; }
r[6]=0x0000000au;
goto P_0c08a97c;
P_0c08a97c: /* original 81d1, guest PC 0x0c08a97c */
if(!s->budget--) { s->failed_pc=0x0c08a97cu; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c08a97e;
P_0c08a97e: /* original d42e, guest PC 0x0c08a97e */
if(!s->budget--) { s->failed_pc=0x0c08a97eu; return 0; }
r[4]=read(ram,0x0c08aa38u,4);
goto P_0c08a980;
P_0c08a980: /* original 6341, guest PC 0x0c08a980 */
if(!s->budget--) { s->failed_pc=0x0c08a980u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c08a982;
P_0c08a982: /* original 4610, guest PC 0x0c08a982 */
if(!s->budget--) { s->failed_pc=0x0c08a982u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c08a984;
P_0c08a984: /* original 2e31, guest PC 0x0c08a984 */
if(!s->budget--) { s->failed_pc=0x0c08a984u; return 0; }
write(ram,r[14],r[3],2);
goto P_0c08a986;
P_0c08a986: /* original 8541, guest PC 0x0c08a986 */
if(!s->budget--) { s->failed_pc=0x0c08a986u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c08a988;
P_0c08a988: /* original 81e1, guest PC 0x0c08a988 */
if(!s->budget--) { s->failed_pc=0x0c08a988u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c08a98a;
P_0c08a98a: /* original e004, guest PC 0x0c08a98a */
if(!s->budget--) { s->failed_pc=0x0c08a98au; return 0; }
r[0]=0x00000004u;
goto P_0c08a98c;
P_0c08a98c: /* original f346, guest PC 0x0c08a98c */
if(!s->budget--) { s->failed_pc=0x0c08a98cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c08a98e;
P_0c08a98e: /* original 7408, guest PC 0x0c08a98e */
if(!s->budget--) { s->failed_pc=0x0c08a98eu; return 0; }
r[4]+=0x00000008u;
goto P_0c08a990;
P_0c08a990: /* original fe37, guest PC 0x0c08a990 */
if(!s->budget--) { s->failed_pc=0x0c08a990u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08a992;
P_0c08a992: /* original 8ff5, guest PC 0x0c08a992 */
if(!s->budget--) { s->failed_pc=0x0c08a992u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000010u;
if(!cond) { goto P_0c08a980; }
goto P_0c08a996;
P_0c08a994: /* original 7e10, guest PC 0x0c08a994 */
if(!s->budget--) { s->failed_pc=0x0c08a994u; return 0; }
r[14]+=0x00000010u;
goto P_0c08a996;
P_0c08a996: /* original 5b58, guest PC 0x0c08a996 */
if(!s->budget--) { s->failed_pc=0x0c08a996u; return 0; }
r[11]=read(ram,r[5]+32,4);
goto P_0c08a998;
P_0c08a998: /* original 65f3, guest PC 0x0c08a998 */
if(!s->budget--) { s->failed_pc=0x0c08a998u; return 0; }
r[5]=r[15];
goto P_0c08a99a;
P_0c08a99a: /* original d328, guest PC 0x0c08a99a */
if(!s->budget--) { s->failed_pc=0x0c08a99au; return 0; }
r[3]=read(ram,0x0c08aa3cu,4);
goto P_0c08a99c;
P_0c08a99c: /* original 7504, guest PC 0x0c08a99c */
if(!s->budget--) { s->failed_pc=0x0c08a99cu; return 0; }
r[5]+=0x00000004u;
goto P_0c08a99e;
P_0c08a99e: /* original 85bf, guest PC 0x0c08a99e */
if(!s->budget--) { s->failed_pc=0x0c08a99eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+30,2);
goto P_0c08a9a0;
P_0c08a9a0: /* original 66f3, guest PC 0x0c08a9a0 */
if(!s->budget--) { s->failed_pc=0x0c08a9a0u; return 0; }
r[6]=r[15];
goto P_0c08a9a2;
P_0c08a9a2: /* original 6b03, guest PC 0x0c08a9a2 */
if(!s->budget--) { s->failed_pc=0x0c08a9a2u; return 0; }
r[11]=r[0];
goto P_0c08a9a4;
P_0c08a9a4: /* original c726, guest PC 0x0c08a9a4 */
if(!s->budget--) { s->failed_pc=0x0c08a9a4u; return 0; }
r[0]=0x0c08aa40u;
goto P_0c08a9a6;
P_0c08a9a6: /* original f308, guest PC 0x0c08a9a6 */
if(!s->budget--) { s->failed_pc=0x0c08a9a6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a9a8;
P_0c08a9a8: /* original e004, guest PC 0x0c08a9a8 */
if(!s->budget--) { s->failed_pc=0x0c08a9a8u; return 0; }
r[0]=0x00000004u;
goto P_0c08a9aa;
P_0c08a9aa: /* original 3b3c, guest PC 0x0c08a9aa */
if(!s->budget--) { s->failed_pc=0x0c08a9aau; return 0; }
r[11]+=r[3];
goto P_0c08a9ac;
P_0c08a9ac: /* original ff37, guest PC 0x0c08a9ac */
if(!s->budget--) { s->failed_pc=0x0c08a9acu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a9ae;
P_0c08a9ae: /* original c725, guest PC 0x0c08a9ae */
if(!s->budget--) { s->failed_pc=0x0c08a9aeu; return 0; }
r[0]=0x0c08aa44u;
goto P_0c08a9b0;
P_0c08a9b0: /* original f308, guest PC 0x0c08a9b0 */
if(!s->budget--) { s->failed_pc=0x0c08a9b0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a9b2;
P_0c08a9b2: /* original ff3a, guest PC 0x0c08a9b2 */
if(!s->budget--) { s->failed_pc=0x0c08a9b2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08a9b4;
P_0c08a9b4: /* original d224, guest PC 0x0c08a9b4 */
if(!s->budget--) { s->failed_pc=0x0c08a9b4u; return 0; }
r[2]=read(ram,0x0c08aa48u,4);
goto P_0c08a9b6;
P_0c08a9b6: /* original 420b, guest PC 0x0c08a9b6 */
if(!s->budget--) { s->failed_pc=0x0c08a9b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c08a9bau;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a9bau) { target=s->pc; goto dispatch; }
goto P_0c08a9ba;
P_0c08a9b8: /* original 64b3, guest PC 0x0c08a9b8 */
if(!s->budget--) { s->failed_pc=0x0c08a9b8u; return 0; }
r[4]=r[11];
goto P_0c08a9ba;
P_0c08a9ba: /* original e004, guest PC 0x0c08a9ba */
if(!s->budget--) { s->failed_pc=0x0c08a9bau; return 0; }
r[0]=0x00000004u;
goto P_0c08a9bc;
P_0c08a9bc: /* original f3f6, guest PC 0x0c08a9bc */
if(!s->budget--) { s->failed_pc=0x0c08a9bcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a9be;
P_0c08a9be: /* original e008, guest PC 0x0c08a9be */
if(!s->budget--) { s->failed_pc=0x0c08a9beu; return 0; }
r[0]=0x00000008u;
goto P_0c08a9c0;
P_0c08a9c0: /* original ff37, guest PC 0x0c08a9c0 */
if(!s->budget--) { s->failed_pc=0x0c08a9c0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a9c2;
P_0c08a9c2: /* original e00c, guest PC 0x0c08a9c2 */
if(!s->budget--) { s->failed_pc=0x0c08a9c2u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a9c4;
P_0c08a9c4: /* original f38d, guest PC 0x0c08a9c4 */
if(!s->budget--) { s->failed_pc=0x0c08a9c4u; return 0; }
fr[3]=0;
goto P_0c08a9c6;
P_0c08a9c6: /* original ff37, guest PC 0x0c08a9c6 */
if(!s->budget--) { s->failed_pc=0x0c08a9c6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a9c8;
P_0c08a9c8: /* original c720, guest PC 0x0c08a9c8 */
if(!s->budget--) { s->failed_pc=0x0c08a9c8u; return 0; }
r[0]=0x0c08aa4cu;
goto P_0c08a9ca;
P_0c08a9ca: /* original f3f8, guest PC 0x0c08a9ca */
if(!s->budget--) { s->failed_pc=0x0c08a9cau; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08a9cc;
P_0c08a9cc: /* original f408, guest PC 0x0c08a9cc */
if(!s->budget--) { s->failed_pc=0x0c08a9ccu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a9ce;
P_0c08a9ce: /* original e010, guest PC 0x0c08a9ce */
if(!s->budget--) { s->failed_pc=0x0c08a9ceu; return 0; }
r[0]=0x00000010u;
goto P_0c08a9d0;
P_0c08a9d0: /* original f340, guest PC 0x0c08a9d0 */
if(!s->budget--) { s->failed_pc=0x0c08a9d0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c08a9d2;
P_0c08a9d2: /* original ff37, guest PC 0x0c08a9d2 */
if(!s->budget--) { s->failed_pc=0x0c08a9d2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a9d4;
P_0c08a9d4: /* original 9e2a, guest PC 0x0c08a9d4 */
if(!s->budget--) { s->failed_pc=0x0c08a9d4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08aa2cu,2);
goto P_0c08a9d6;
P_0c08a9d6: /* original 66f3, guest PC 0x0c08a9d6 */
if(!s->budget--) { s->failed_pc=0x0c08a9d6u; return 0; }
r[6]=r[15];
goto P_0c08a9d8;
P_0c08a9d8: /* original 65c3, guest PC 0x0c08a9d8 */
if(!s->budget--) { s->failed_pc=0x0c08a9d8u; return 0; }
r[5]=r[12];
goto P_0c08a9da;
P_0c08a9da: /* original 7608, guest PC 0x0c08a9da */
if(!s->budget--) { s->failed_pc=0x0c08a9dau; return 0; }
r[6]+=0x00000008u;
goto P_0c08a9dc;
P_0c08a9dc: /* original 67b3, guest PC 0x0c08a9dc */
if(!s->budget--) { s->failed_pc=0x0c08a9dcu; return 0; }
r[7]=r[11];
goto P_0c08a9de;
P_0c08a9de: /* original be85, guest PC 0x0c08a9de */
if(!s->budget--) { s->failed_pc=0x0c08a9deu; return 0; }
target=0x0c08a6ecu; r[16]=code_base|0x0c08a9e2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a9e2u) { target=s->pc; goto dispatch; }
goto P_0c08a9e2;
P_0c08a9e0: /* original 64d3, guest PC 0x0c08a9e0 */
if(!s->budget--) { s->failed_pc=0x0c08a9e0u; return 0; }
r[4]=r[13];
goto P_0c08a9e2;
P_0c08a9e2: /* original 4e10, guest PC 0x0c08a9e2 */
if(!s->budget--) { s->failed_pc=0x0c08a9e2u; return 0; }
--r[14];
r[17]=(r[17]&~1u)|((r[14]==0)!=0);
goto P_0c08a9e4;
P_0c08a9e4: /* original 8ff7, guest PC 0x0c08a9e4 */
if(!s->budget--) { s->failed_pc=0x0c08a9e4u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000010u;
if(!cond) { goto P_0c08a9d6; }
goto P_0c08a9e8;
P_0c08a9e6: /* original 7c10, guest PC 0x0c08a9e6 */
if(!s->budget--) { s->failed_pc=0x0c08a9e6u; return 0; }
r[12]+=0x00000010u;
goto P_0c08a9e8;
P_0c08a9e8: /* original 7f14, guest PC 0x0c08a9e8 */
if(!s->budget--) { s->failed_pc=0x0c08a9e8u; return 0; }
r[15]+=0x00000014u;
goto P_0c08a9ea;
P_0c08a9ea: /* original 4f26, guest PC 0x0c08a9ea */
if(!s->budget--) { s->failed_pc=0x0c08a9eau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a9ec;
P_0c08a9ec: /* original 6bf6, guest PC 0x0c08a9ec */
if(!s->budget--) { s->failed_pc=0x0c08a9ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a9ee;
P_0c08a9ee: /* original 6cf6, guest PC 0x0c08a9ee */
if(!s->budget--) { s->failed_pc=0x0c08a9eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a9f0;
P_0c08a9f0: /* original 6df6, guest PC 0x0c08a9f0 */
if(!s->budget--) { s->failed_pc=0x0c08a9f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a9f2;
P_0c08a9f2: /* original 000b, guest PC 0x0c08a9f2 */
if(!s->budget--) { s->failed_pc=0x0c08a9f2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a9f4: /* original 6ef6, guest PC 0x0c08a9f4 */
if(!s->budget--) { s->failed_pc=0x0c08a9f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08a9f6u,s,ram);
P_0c0a302e: /* original e600, guest PC 0x0c0a302e */
if(!s->budget--) { s->failed_pc=0x0c0a302eu; return 0; }
r[6]=0x00000000u;
goto P_0c0a3030;
P_0c0a3030: /* original d018, guest PC 0x0c0a3030 */
if(!s->budget--) { s->failed_pc=0x0c0a3030u; return 0; }
r[0]=read(ram,0x0c0a3094u,4);
goto P_0c0a3032;
P_0c0a3032: /* original 6463, guest PC 0x0c0a3032 */
if(!s->budget--) { s->failed_pc=0x0c0a3032u; return 0; }
r[4]=r[6];
goto P_0c0a3034;
P_0c0a3034: /* original e719, guest PC 0x0c0a3034 */
if(!s->budget--) { s->failed_pc=0x0c0a3034u; return 0; }
r[7]=0x00000019u;
goto P_0c0a3036;
P_0c0a3036: /* original 6543, guest PC 0x0c0a3036 */
if(!s->budget--) { s->failed_pc=0x0c0a3036u; return 0; }
r[5]=r[4];
goto P_0c0a3038;
P_0c0a3038: /* original 4508, guest PC 0x0c0a3038 */
if(!s->budget--) { s->failed_pc=0x0c0a3038u; return 0; }
r[5]<<=2;
goto P_0c0a303a;
P_0c0a303a: /* original 4500, guest PC 0x0c0a303a */
if(!s->budget--) { s->failed_pc=0x0c0a303au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0a303c;
P_0c0a303c: /* original 6343, guest PC 0x0c0a303c */
if(!s->budget--) { s->failed_pc=0x0c0a303cu; return 0; }
r[3]=r[4];
goto P_0c0a303e;
P_0c0a303e: /* original 353c, guest PC 0x0c0a303e */
if(!s->budget--) { s->failed_pc=0x0c0a303eu; return 0; }
r[5]+=r[3];
goto P_0c0a3040;
P_0c0a3040: /* original 4508, guest PC 0x0c0a3040 */
if(!s->budget--) { s->failed_pc=0x0c0a3040u; return 0; }
r[5]<<=2;
goto P_0c0a3042;
P_0c0a3042: /* original 655f, guest PC 0x0c0a3042 */
if(!s->budget--) { s->failed_pc=0x0c0a3042u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a3044;
P_0c0a3044: /* original 350c, guest PC 0x0c0a3044 */
if(!s->budget--) { s->failed_pc=0x0c0a3044u; return 0; }
r[5]+=r[0];
goto P_0c0a3046;
P_0c0a3046: /* original 5556, guest PC 0x0c0a3046 */
if(!s->budget--) { s->failed_pc=0x0c0a3046u; return 0; }
r[5]=read(ram,r[5]+24,4);
goto P_0c0a3048;
P_0c0a3048: /* original 2558, guest PC 0x0c0a3048 */
if(!s->budget--) { s->failed_pc=0x0c0a3048u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a304a;
P_0c0a304a: /* original 8d01, guest PC 0x0c0a304a */
if(!s->budget--) { s->failed_pc=0x0c0a304au; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c0a3050; }
goto P_0c0a304e;
P_0c0a304c: /* original 7401, guest PC 0x0c0a304c */
if(!s->budget--) { s->failed_pc=0x0c0a304cu; return 0; }
r[4]+=0x00000001u;
goto P_0c0a304e;
P_0c0a304e: /* original 2562, guest PC 0x0c0a304e */
if(!s->budget--) { s->failed_pc=0x0c0a304eu; return 0; }
write(ram,r[5],r[6],4);
goto P_0c0a3050;
P_0c0a3050: /* original 3477, guest PC 0x0c0a3050 */
if(!s->budget--) { s->failed_pc=0x0c0a3050u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[7])!=0);
goto P_0c0a3052;
P_0c0a3052: /* original 8bf0, guest PC 0x0c0a3052 */
if(!s->budget--) { s->failed_pc=0x0c0a3052u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a3036; }
goto P_0c0a3054;
P_0c0a3054: /* original 000b, guest PC 0x0c0a3054 */
if(!s->budget--) { s->failed_pc=0x0c0a3054u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a3056: /* original 0009, guest PC 0x0c0a3056 */
if(!s->budget--) { s->failed_pc=0x0c0a3056u; return 0; }
return vf3_matrix_family(0x0c0a3058u,s,ram);
P_0c0c1f32: /* original 000b, guest PC 0x0c0c1f32 */
if(!s->budget--) { s->failed_pc=0x0c0c1f32u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1f34: /* original 0009, guest PC 0x0c0c1f34 */
if(!s->budget--) { s->failed_pc=0x0c0c1f34u; return 0; }
return vf3_matrix_family(0x0c0c1f36u,s,ram);
P_0c0c1f94: /* original 000b, guest PC 0x0c0c1f94 */
if(!s->budget--) { s->failed_pc=0x0c0c1f94u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1f96: /* original 0009, guest PC 0x0c0c1f96 */
if(!s->budget--) { s->failed_pc=0x0c0c1f96u; return 0; }
return vf3_matrix_family(0x0c0c1f98u,s,ram);
P_0c0c2706: /* original 4f22, guest PC 0x0c0c2706 */
if(!s->budget--) { s->failed_pc=0x0c0c2706u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2708;
P_0c0c2708: /* original 0e36, guest PC 0x0c0c2708 */
if(!s->budget--) { s->failed_pc=0x0c0c2708u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c270a;
P_0c0c270a: /* original 70f8, guest PC 0x0c0c270a */
if(!s->budget--) { s->failed_pc=0x0c0c270au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c270c;
P_0c0c270c: /* original 0e36, guest PC 0x0c0c270c */
if(!s->budget--) { s->failed_pc=0x0c0c270cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c270e;
P_0c0c270e: /* original 70e8, guest PC 0x0c0c270e */
if(!s->budget--) { s->failed_pc=0x0c0c270eu; return 0; }
r[0]+=0xffffffe8u;
goto P_0c0c2710;
P_0c0c2710: /* original 0e26, guest PC 0x0c0c2710 */
if(!s->budget--) { s->failed_pc=0x0c0c2710u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c2712;
P_0c0c2712: /* original 70f8, guest PC 0x0c0c2712 */
if(!s->budget--) { s->failed_pc=0x0c0c2712u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c2714;
P_0c0c2714: /* original 0e26, guest PC 0x0c0c2714 */
if(!s->budget--) { s->failed_pc=0x0c0c2714u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c2716;
P_0c0c2716: /* original 967a, guest PC 0x0c0c2716 */
if(!s->budget--) { s->failed_pc=0x0c0c2716u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c280eu,2);
goto P_0c0c2718;
P_0c0c2718: /* original 9477, guest PC 0x0c0c2718 */
if(!s->budget--) { s->failed_pc=0x0c0c2718u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c280au,2);
goto P_0c0c271a;
P_0c0c271a: /* original d345, guest PC 0x0c0c271a */
if(!s->budget--) { s->failed_pc=0x0c0c271au; return 0; }
r[3]=read(ram,0x0c0c2830u,4);
goto P_0c0c271c;
P_0c0c271c: /* original 36ec, guest PC 0x0c0c271c */
if(!s->budget--) { s->failed_pc=0x0c0c271cu; return 0; }
r[6]+=r[14];
goto P_0c0c271e;
P_0c0c271e: /* original 430b, guest PC 0x0c0c271e */
if(!s->budget--) { s->failed_pc=0x0c0c271eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2722u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2722u) { target=s->pc; goto dispatch; }
goto P_0c0c2722;
P_0c0c2720: /* original 65e3, guest PC 0x0c0c2720 */
if(!s->budget--) { s->failed_pc=0x0c0c2720u; return 0; }
r[5]=r[14];
goto P_0c0c2722;
P_0c0c2722: /* original 9d75, guest PC 0x0c0c2722 */
if(!s->budget--) { s->failed_pc=0x0c0c2722u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2810u,2);
goto P_0c0c2724;
P_0c0c2724: /* original e500, guest PC 0x0c0c2724 */
if(!s->budget--) { s->failed_pc=0x0c0c2724u; return 0; }
r[5]=0x00000000u;
goto P_0c0c2726;
P_0c0c2726: /* original e679, guest PC 0x0c0c2726 */
if(!s->budget--) { s->failed_pc=0x0c0c2726u; return 0; }
r[6]=0x00000079u;
goto P_0c0c2728;
P_0c0c2728: /* original 3dec, guest PC 0x0c0c2728 */
if(!s->budget--) { s->failed_pc=0x0c0c2728u; return 0; }
r[13]+=r[14];
goto P_0c0c272a;
P_0c0c272a: /* original bc02, guest PC 0x0c0c272a */
if(!s->budget--) { s->failed_pc=0x0c0c272au; return 0; }
target=0x0c0c1f32u; r[16]=code_base|0x0c0c272eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c272eu) { target=s->pc; goto dispatch; }
goto P_0c0c272e;
P_0c0c272c: /* original 64d3, guest PC 0x0c0c272c */
if(!s->budget--) { s->failed_pc=0x0c0c272cu; return 0; }
r[4]=r[13];
goto P_0c0c272e;
P_0c0c272e: /* original e700, guest PC 0x0c0c272e */
if(!s->budget--) { s->failed_pc=0x0c0c272eu; return 0; }
r[7]=0x00000000u;
goto P_0c0c2730;
P_0c0c2730: /* original 956f, guest PC 0x0c0c2730 */
if(!s->budget--) { s->failed_pc=0x0c0c2730u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2812u,2);
goto P_0c0c2732;
P_0c0c2732: /* original 6673, guest PC 0x0c0c2732 */
if(!s->budget--) { s->failed_pc=0x0c0c2732u; return 0; }
r[6]=r[7];
goto P_0c0c2734;
P_0c0c2734: /* original bc2e, guest PC 0x0c0c2734 */
if(!s->budget--) { s->failed_pc=0x0c0c2734u; return 0; }
target=0x0c0c1f94u; r[16]=code_base|0x0c0c2738u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2738u) { target=s->pc; goto dispatch; }
goto P_0c0c2738;
P_0c0c2736: /* original 64d3, guest PC 0x0c0c2736 */
if(!s->budget--) { s->failed_pc=0x0c0c2736u; return 0; }
r[4]=r[13];
goto P_0c0c2738;
P_0c0c2738: /* original e700, guest PC 0x0c0c2738 */
if(!s->budget--) { s->failed_pc=0x0c0c2738u; return 0; }
r[7]=0x00000000u;
goto P_0c0c273a;
P_0c0c273a: /* original 6573, guest PC 0x0c0c273a */
if(!s->budget--) { s->failed_pc=0x0c0c273au; return 0; }
r[5]=r[7];
goto P_0c0c273c;
P_0c0c273c: /* original 6673, guest PC 0x0c0c273c */
if(!s->budget--) { s->failed_pc=0x0c0c273cu; return 0; }
r[6]=r[7];
goto P_0c0c273e;
P_0c0c273e: /* original bc29, guest PC 0x0c0c273e */
if(!s->budget--) { s->failed_pc=0x0c0c273eu; return 0; }
target=0x0c0c1f94u; r[16]=code_base|0x0c0c2742u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2742u) { target=s->pc; goto dispatch; }
goto P_0c0c2742;
P_0c0c2740: /* original 64d3, guest PC 0x0c0c2740 */
if(!s->budget--) { s->failed_pc=0x0c0c2740u; return 0; }
r[4]=r[13];
goto P_0c0c2742;
P_0c0c2742: /* original e700, guest PC 0x0c0c2742 */
if(!s->budget--) { s->failed_pc=0x0c0c2742u; return 0; }
r[7]=0x00000000u;
goto P_0c0c2744;
P_0c0c2744: /* original 9566, guest PC 0x0c0c2744 */
if(!s->budget--) { s->failed_pc=0x0c0c2744u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2814u,2);
goto P_0c0c2746;
P_0c0c2746: /* original 6673, guest PC 0x0c0c2746 */
if(!s->budget--) { s->failed_pc=0x0c0c2746u; return 0; }
r[6]=r[7];
goto P_0c0c2748;
P_0c0c2748: /* original bc24, guest PC 0x0c0c2748 */
if(!s->budget--) { s->failed_pc=0x0c0c2748u; return 0; }
target=0x0c0c1f94u; r[16]=code_base|0x0c0c274cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c274cu) { target=s->pc; goto dispatch; }
goto P_0c0c274c;
P_0c0c274a: /* original 64d3, guest PC 0x0c0c274a */
if(!s->budget--) { s->failed_pc=0x0c0c274au; return 0; }
r[4]=r[13];
goto P_0c0c274c;
P_0c0c274c: /* original d339, guest PC 0x0c0c274c */
if(!s->budget--) { s->failed_pc=0x0c0c274cu; return 0; }
r[3]=read(ram,0x0c0c2834u,4);
goto P_0c0c274e;
P_0c0c274e: /* original e2ff, guest PC 0x0c0c274e */
if(!s->budget--) { s->failed_pc=0x0c0c274eu; return 0; }
r[2]=0xffffffffu;
goto P_0c0c2750;
P_0c0c2750: /* original 2321, guest PC 0x0c0c2750 */
if(!s->budget--) { s->failed_pc=0x0c0c2750u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c0c2752;
P_0c0c2752: /* original d239, guest PC 0x0c0c2752 */
if(!s->budget--) { s->failed_pc=0x0c0c2752u; return 0; }
r[2]=read(ram,0x0c0c2838u,4);
goto P_0c0c2754;
P_0c0c2754: /* original 945f, guest PC 0x0c0c2754 */
if(!s->budget--) { s->failed_pc=0x0c0c2754u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2816u,2);
goto P_0c0c2756;
P_0c0c2756: /* original 420b, guest PC 0x0c0c2756 */
if(!s->budget--) { s->failed_pc=0x0c0c2756u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c275au;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c275au) { target=s->pc; goto dispatch; }
goto P_0c0c275a;
P_0c0c2758: /* original 34ec, guest PC 0x0c0c2758 */
if(!s->budget--) { s->failed_pc=0x0c0c2758u; return 0; }
r[4]+=r[14];
goto P_0c0c275a;
P_0c0c275a: /* original dd38, guest PC 0x0c0c275a */
if(!s->budget--) { s->failed_pc=0x0c0c275au; return 0; }
r[13]=read(ram,0x0c0c283cu,4);
goto P_0c0c275c;
P_0c0c275c: /* original 64e3, guest PC 0x0c0c275c */
if(!s->budget--) { s->failed_pc=0x0c0c275cu; return 0; }
r[4]=r[14];
goto P_0c0c275e;
P_0c0c275e: /* original 2ff6, guest PC 0x0c0c275e */
if(!s->budget--) { s->failed_pc=0x0c0c275eu; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2760;
P_0c0c2760: /* original 2ff6, guest PC 0x0c0c2760 */
if(!s->budget--) { s->failed_pc=0x0c0c2760u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2762;
P_0c0c2762: /* original 67d3, guest PC 0x0c0c2762 */
if(!s->budget--) { s->failed_pc=0x0c0c2762u; return 0; }
r[7]=r[13];
goto P_0c0c2764;
P_0c0c2764: /* original 66f3, guest PC 0x0c0c2764 */
if(!s->budget--) { s->failed_pc=0x0c0c2764u; return 0; }
r[6]=r[15];
goto P_0c0c2766;
P_0c0c2766: /* original b97e, guest PC 0x0c0c2766 */
if(!s->budget--) { s->failed_pc=0x0c0c2766u; return 0; }
target=0x0c0c1a66u; r[16]=code_base|0x0c0c276au;
r[5]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c276au) { target=s->pc; goto dispatch; }
goto P_0c0c276a;
P_0c0c2768: /* original e518, guest PC 0x0c0c2768 */
if(!s->budget--) { s->failed_pc=0x0c0c2768u; return 0; }
r[5]=0x00000018u;
goto P_0c0c276a;
P_0c0c276a: /* original 9755, guest PC 0x0c0c276a */
if(!s->budget--) { s->failed_pc=0x0c0c276au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2818u,2);
goto P_0c0c276c;
P_0c0c276c: /* original 64e3, guest PC 0x0c0c276c */
if(!s->budget--) { s->failed_pc=0x0c0c276cu; return 0; }
r[4]=r[14];
goto P_0c0c276e;
P_0c0c276e: /* original 2ff6, guest PC 0x0c0c276e */
if(!s->budget--) { s->failed_pc=0x0c0c276eu; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2770;
P_0c0c2770: /* original 742c, guest PC 0x0c0c2770 */
if(!s->budget--) { s->failed_pc=0x0c0c2770u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0c2772;
P_0c0c2772: /* original 2ff6, guest PC 0x0c0c2772 */
if(!s->budget--) { s->failed_pc=0x0c0c2772u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2774;
P_0c0c2774: /* original 37dc, guest PC 0x0c0c2774 */
if(!s->budget--) { s->failed_pc=0x0c0c2774u; return 0; }
r[7]+=r[13];
goto P_0c0c2776;
P_0c0c2776: /* original 66f3, guest PC 0x0c0c2776 */
if(!s->budget--) { s->failed_pc=0x0c0c2776u; return 0; }
r[6]=r[15];
goto P_0c0c2778;
P_0c0c2778: /* original b975, guest PC 0x0c0c2778 */
if(!s->budget--) { s->failed_pc=0x0c0c2778u; return 0; }
target=0x0c0c1a66u; r[16]=code_base|0x0c0c277cu;
r[5]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c277cu) { target=s->pc; goto dispatch; }
goto P_0c0c277c;
P_0c0c277a: /* original e518, guest PC 0x0c0c277a */
if(!s->budget--) { s->failed_pc=0x0c0c277au; return 0; }
r[5]=0x00000018u;
goto P_0c0c277c;
P_0c0c277c: /* original 9749, guest PC 0x0c0c277c */
if(!s->budget--) { s->failed_pc=0x0c0c277cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2812u,2);
goto P_0c0c277e;
P_0c0c277e: /* original 64e3, guest PC 0x0c0c277e */
if(!s->budget--) { s->failed_pc=0x0c0c277eu; return 0; }
r[4]=r[14];
goto P_0c0c2780;
P_0c0c2780: /* original 2ff6, guest PC 0x0c0c2780 */
if(!s->budget--) { s->failed_pc=0x0c0c2780u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2782;
P_0c0c2782: /* original 7458, guest PC 0x0c0c2782 */
if(!s->budget--) { s->failed_pc=0x0c0c2782u; return 0; }
r[4]+=0x00000058u;
goto P_0c0c2784;
P_0c0c2784: /* original 2ff6, guest PC 0x0c0c2784 */
if(!s->budget--) { s->failed_pc=0x0c0c2784u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2786;
P_0c0c2786: /* original 37dc, guest PC 0x0c0c2786 */
if(!s->budget--) { s->failed_pc=0x0c0c2786u; return 0; }
r[7]+=r[13];
goto P_0c0c2788;
P_0c0c2788: /* original 66f3, guest PC 0x0c0c2788 */
if(!s->budget--) { s->failed_pc=0x0c0c2788u; return 0; }
r[6]=r[15];
goto P_0c0c278a;
P_0c0c278a: /* original b96c, guest PC 0x0c0c278a */
if(!s->budget--) { s->failed_pc=0x0c0c278au; return 0; }
target=0x0c0c1a66u; r[16]=code_base|0x0c0c278eu;
r[5]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c278eu) { target=s->pc; goto dispatch; }
goto P_0c0c278e;
P_0c0c278c: /* original e518, guest PC 0x0c0c278c */
if(!s->budget--) { s->failed_pc=0x0c0c278cu; return 0; }
r[5]=0x00000018u;
goto P_0c0c278e;
P_0c0c278e: /* original 943e, guest PC 0x0c0c278e */
if(!s->budget--) { s->failed_pc=0x0c0c278eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c280eu,2);
goto P_0c0c2790;
P_0c0c2790: /* original 9743, guest PC 0x0c0c2790 */
if(!s->budget--) { s->failed_pc=0x0c0c2790u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c281au,2);
goto P_0c0c2792;
P_0c0c2792: /* original 2ff6, guest PC 0x0c0c2792 */
if(!s->budget--) { s->failed_pc=0x0c0c2792u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2794;
P_0c0c2794: /* original 34ec, guest PC 0x0c0c2794 */
if(!s->budget--) { s->failed_pc=0x0c0c2794u; return 0; }
r[4]+=r[14];
goto P_0c0c2796;
P_0c0c2796: /* original 2ff6, guest PC 0x0c0c2796 */
if(!s->budget--) { s->failed_pc=0x0c0c2796u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2798;
P_0c0c2798: /* original 37dc, guest PC 0x0c0c2798 */
if(!s->budget--) { s->failed_pc=0x0c0c2798u; return 0; }
r[7]+=r[13];
goto P_0c0c279a;
P_0c0c279a: /* original 66f3, guest PC 0x0c0c279a */
if(!s->budget--) { s->failed_pc=0x0c0c279au; return 0; }
r[6]=r[15];
goto P_0c0c279c;
P_0c0c279c: /* original b963, guest PC 0x0c0c279c */
if(!s->budget--) { s->failed_pc=0x0c0c279cu; return 0; }
target=0x0c0c1a66u; r[16]=code_base|0x0c0c27a0u;
r[5]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c27a0u) { target=s->pc; goto dispatch; }
goto P_0c0c27a0;
P_0c0c279e: /* original e518, guest PC 0x0c0c279e */
if(!s->budget--) { s->failed_pc=0x0c0c279eu; return 0; }
r[5]=0x00000018u;
goto P_0c0c27a0;
P_0c0c27a0: /* original 7f20, guest PC 0x0c0c27a0 */
if(!s->budget--) { s->failed_pc=0x0c0c27a0u; return 0; }
r[15]+=0x00000020u;
goto P_0c0c27a2;
P_0c0c27a2: /* original 4f26, guest PC 0x0c0c27a2 */
if(!s->budget--) { s->failed_pc=0x0c0c27a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c27a4;
P_0c0c27a4: /* original 6df6, guest PC 0x0c0c27a4 */
if(!s->budget--) { s->failed_pc=0x0c0c27a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c27a6;
P_0c0c27a6: /* original 000b, guest PC 0x0c0c27a6 */
if(!s->budget--) { s->failed_pc=0x0c0c27a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c27a8: /* original 6ef6, guest PC 0x0c0c27a8 */
if(!s->budget--) { s->failed_pc=0x0c0c27a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c27aau,s,ram);
P_0c0c4e34: /* original 2fe6, guest PC 0x0c0c4e34 */
if(!s->budget--) { s->failed_pc=0x0c0c4e34u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e36;
P_0c0c4e36: /* original 2fd6, guest PC 0x0c0c4e36 */
if(!s->budget--) { s->failed_pc=0x0c0c4e36u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e38;
P_0c0c4e38: /* original ed00, guest PC 0x0c0c4e38 */
if(!s->budget--) { s->failed_pc=0x0c0c4e38u; return 0; }
r[13]=0x00000000u;
goto P_0c0c4e3a;
P_0c0c4e3a: /* original 2fc6, guest PC 0x0c0c4e3a */
if(!s->budget--) { s->failed_pc=0x0c0c4e3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e3c;
P_0c0c4e3c: /* original 6ed3, guest PC 0x0c0c4e3c */
if(!s->budget--) { s->failed_pc=0x0c0c4e3cu; return 0; }
r[14]=r[13];
goto P_0c0c4e3e;
P_0c0c4e3e: /* original 2fb6, guest PC 0x0c0c4e3e */
if(!s->budget--) { s->failed_pc=0x0c0c4e3eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e40;
P_0c0c4e40: /* original 2fa6, guest PC 0x0c0c4e40 */
if(!s->budget--) { s->failed_pc=0x0c0c4e40u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e42;
P_0c0c4e42: /* original 2f96, guest PC 0x0c0c4e42 */
if(!s->budget--) { s->failed_pc=0x0c0c4e42u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e44;
P_0c0c4e44: /* original 2f86, guest PC 0x0c0c4e44 */
if(!s->budget--) { s->failed_pc=0x0c0c4e44u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e46;
P_0c0c4e46: /* original fffb, guest PC 0x0c0c4e46 */
if(!s->budget--) { s->failed_pc=0x0c0c4e46u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c4e48;
P_0c0c4e48: /* original ffeb, guest PC 0x0c0c4e48 */
if(!s->budget--) { s->failed_pc=0x0c0c4e48u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
return vf3_matrix_family(0x0c0c4e4au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0371c2u,0x0c0371c4u,0x0c0371c6u,0x0c0371c8u,0x0c0371cau,0x0c0371ccu,0x0c0371ceu,0x0c0371d0u,0x0c0371d2u,0x0c0371d4u,0x0c0371d6u,0x0c0371d8u,0x0c0371dau,0x0c0371dcu,0x0c0371deu,0x0c0371e0u,
0x0c0371e2u,0x0c0371e4u,0x0c037248u,0x0c03724au,0x0c03724cu,0x0c03724eu,0x0c037250u,0x0c037252u,0x0c037254u,0x0c037256u,0x0c037258u,0x0c03725au,0x0c03725cu,0x0c03725eu,0x0c037260u,0x0c037262u,
0x0c037264u,0x0c037266u,0x0c037268u,0x0c03726au,0x0c03726cu,0x0c03726eu,0x0c037270u,0x0c037272u,0x0c037274u,0x0c037276u,0x0c037278u,0x0c03727au,0x0c03727cu,0x0c03727eu,0x0c037280u,0x0c037282u,
0x0c037284u,0x0c037286u,0x0c037288u,0x0c03728au,0x0c03728cu,0x0c03728eu,0x0c037290u,0x0c037292u,0x0c037294u,0x0c037296u,0x0c037298u,0x0c03729au,0x0c03729cu,0x0c03729eu,0x0c0372a0u,0x0c0372a2u,
0x0c0372a4u,0x0c0372a6u,0x0c0372a8u,0x0c0372aau,0x0c0372acu,0x0c0372aeu,0x0c0372b0u,0x0c0372b2u,0x0c0372b4u,0x0c0372b6u,0x0c0372b8u,0x0c0372bau,0x0c0372bcu,0x0c0372beu,0x0c0372c0u,0x0c0372c2u,
0x0c0372c4u,0x0c0372c6u,0x0c0372c8u,0x0c0372cau,0x0c0372ccu,0x0c0372ceu,0x0c0372d0u,0x0c0372d2u,0x0c0372d4u,0x0c0372d6u,0x0c0372d8u,0x0c0372dau,0x0c0372dcu,0x0c0372deu,0x0c0372e0u,0x0c037502u,
0x0c037504u,0x0c037506u,0x0c037508u,0x0c04631cu,0x0c04631eu,0x0c046320u,0x0c046322u,0x0c046324u,0x0c046326u,0x0c046328u,0x0c04632au,0x0c04632cu,0x0c04632eu,0x0c046330u,0x0c046332u,0x0c046334u,
0x0c046336u,0x0c046338u,0x0c04633au,0x0c04633cu,0x0c04633eu,0x0c046340u,0x0c046342u,0x0c046344u,0x0c046346u,0x0c046348u,0x0c04634au,0x0c04634cu,0x0c04634eu,0x0c046350u,0x0c046352u,0x0c046354u,
0x0c046356u,0x0c046358u,0x0c04635au,0x0c04635cu,0x0c04635eu,0x0c046360u,0x0c046362u,0x0c046364u,0x0c046366u,0x0c046368u,0x0c04636au,0x0c04636cu,0x0c04636eu,0x0c046370u,0x0c046372u,0x0c046374u,
0x0c046376u,0x0c046378u,0x0c04637au,0x0c04637cu,0x0c04637eu,0x0c046380u,0x0c046382u,0x0c046384u,0x0c046386u,0x0c046388u,0x0c04638au,0x0c04638cu,0x0c04638eu,0x0c046390u,0x0c046392u,0x0c046394u,
0x0c046396u,0x0c046398u,0x0c04639au,0x0c04639cu,0x0c04639eu,0x0c0463a0u,0x0c0463a2u,0x0c0463a4u,0x0c0463a6u,0x0c0463a8u,0x0c0463aau,0x0c0463acu,0x0c0463aeu,0x0c046c48u,0x0c046c4au,0x0c046c4cu,
0x0c046c4eu,0x0c046e54u,0x0c046e56u,0x0c046e58u,0x0c046e5au,0x0c046e5cu,0x0c046e5eu,0x0c046e60u,0x0c046e62u,0x0c046e64u,0x0c04b9fcu,0x0c04b9feu,0x0c04ba00u,0x0c04ba02u,0x0c04ba04u,0x0c04ba06u,
0x0c04ba08u,0x0c04ba0au,0x0c04ba0cu,0x0c04ba0eu,0x0c04ba10u,0x0c04ba12u,0x0c04ba14u,0x0c04ba16u,0x0c04ba18u,0x0c04ba1au,0x0c04ba1cu,0x0c04ba1eu,0x0c04ba20u,0x0c04ba22u,0x0c04ba24u,0x0c04ba26u,
0x0c04ba28u,0x0c04ba2au,0x0c04ba2cu,0x0c04ba2eu,0x0c04ba30u,0x0c04ba32u,0x0c04ba34u,0x0c04ba36u,0x0c04ba38u,0x0c04ba3au,0x0c04ba3cu,0x0c04ba3eu,0x0c04ba40u,0x0c04ba42u,0x0c04ba44u,0x0c04ba46u,
0x0c04ba48u,0x0c04ba4au,0x0c04ba4cu,0x0c04ba4eu,0x0c04c0f8u,0x0c04c0fau,0x0c04c0fcu,0x0c04c60au,0x0c04c60cu,0x0c04c60eu,0x0c04c610u,0x0c04c612u,0x0c04c614u,0x0c04c616u,0x0c04c618u,0x0c04c61au,
0x0c04c61cu,0x0c053ddau,0x0c053ddcu,0x0c053ddeu,0x0c053de0u,0x0c053de2u,0x0c053de4u,0x0c053de6u,0x0c053de8u,0x0c053deau,0x0c053decu,0x0c053deeu,0x0c053df0u,0x0c053df2u,0x0c053df4u,0x0c053df6u,
0x0c053df8u,0x0c053dfau,0x0c053dfcu,0x0c053dfeu,0x0c053e00u,0x0c053e02u,0x0c053e04u,0x0c053e06u,0x0c053e08u,0x0c053e0au,0x0c053e0cu,0x0c053e0eu,0x0c053e10u,0x0c053e12u,0x0c053e14u,0x0c053e16u,
0x0c053e18u,0x0c053e1au,0x0c053e1cu,0x0c053e1eu,0x0c053e20u,0x0c053e22u,0x0c053e24u,0x0c053e26u,0x0c053e28u,0x0c053e2au,0x0c053e2cu,0x0c053e2eu,0x0c053e30u,0x0c053e32u,0x0c053e34u,0x0c053e36u,
0x0c053e38u,0x0c053e3au,0x0c053e3cu,0x0c053e3eu,0x0c053e40u,0x0c053e42u,0x0c053e44u,0x0c053e46u,0x0c053e48u,0x0c053e4au,0x0c053e4cu,0x0c053e4eu,0x0c053e50u,0x0c053e52u,0x0c053e54u,0x0c053e56u,
0x0c053e58u,0x0c053e5au,0x0c053e5cu,0x0c053e5eu,0x0c053e60u,0x0c053e62u,0x0c053e64u,0x0c053e66u,0x0c053e68u,0x0c053e6au,0x0c053e6cu,0x0c053e6eu,0x0c053e70u,0x0c053e72u,0x0c053e74u,0x0c053e76u,
0x0c053e78u,0x0c053e7au,0x0c053e7cu,0x0c053e7eu,0x0c053e80u,0x0c053e82u,0x0c053e84u,0x0c053e86u,0x0c053e88u,0x0c053e8au,0x0c053e8cu,0x0c053e8eu,0x0c053e90u,0x0c053e92u,0x0c053e94u,0x0c053e96u,
0x0c053e98u,0x0c053e9au,0x0c053e9cu,0x0c053e9eu,0x0c053ea0u,0x0c053ea2u,0x0c053ea4u,0x0c053ea6u,0x0c053ea8u,0x0c053eaau,0x0c053eacu,0x0c053eaeu,0x0c053eb0u,0x0c053eb2u,0x0c054640u,0x0c054642u,
0x0c054644u,0x0c054646u,0x0c054648u,0x0c05464au,0x0c05464cu,0x0c05464eu,0x0c07caa8u,0x0c07caaau,0x0c07caacu,0x0c07caaeu,0x0c07cab0u,0x0c07cab2u,0x0c07cab4u,0x0c07cab6u,0x0c07cab8u,0x0c07cabau,
0x0c07cabcu,0x0c07cabeu,0x0c07cac0u,0x0c07cac2u,0x0c07cac4u,0x0c07cac6u,0x0c07cac8u,0x0c07cacau,0x0c07caccu,0x0c07caceu,0x0c07cad0u,0x0c07cad2u,0x0c07cad4u,0x0c07cad6u,0x0c07cad8u,0x0c07cadau,
0x0c07cadcu,0x0c07cadeu,0x0c07cae0u,0x0c07cae2u,0x0c07cae4u,0x0c07cae6u,0x0c07cae8u,0x0c07caeau,0x0c07caecu,0x0c07caeeu,0x0c07caf0u,0x0c07caf2u,0x0c07caf4u,0x0c07caf6u,0x0c07caf8u,0x0c07cafau,
0x0c07cafcu,0x0c07cafeu,0x0c07cb00u,0x0c07cb02u,0x0c07cb04u,0x0c07cb06u,0x0c07cb08u,0x0c07cb0au,0x0c07cb0cu,0x0c07cb0eu,0x0c07cb10u,0x0c07cb12u,0x0c07cb14u,0x0c07cb16u,0x0c07cb18u,0x0c07cb1au,
0x0c07cb1cu,0x0c07cb1eu,0x0c07cb20u,0x0c07cb22u,0x0c07cb24u,0x0c07cb26u,0x0c07cb28u,0x0c07cb2au,0x0c07cb2cu,0x0c07cb2eu,0x0c07cb30u,0x0c07cb32u,0x0c07cb34u,0x0c07cb36u,0x0c07cb38u,0x0c07cb3au,
0x0c07cb3cu,0x0c07cb3eu,0x0c07cb40u,0x0c07cb42u,0x0c07cb44u,0x0c07cb46u,0x0c07cb48u,0x0c07cb4au,0x0c07cb4cu,0x0c07cb4eu,0x0c07cb50u,0x0c07cb52u,0x0c07cb54u,0x0c07cb56u,0x0c07cb58u,0x0c07cb5au,
0x0c07cb5cu,0x0c07cb5eu,0x0c07cb60u,0x0c07cb62u,0x0c07cb64u,0x0c07cb66u,0x0c07cb68u,0x0c07cb6au,0x0c07cb6cu,0x0c07cb6eu,0x0c07cb70u,0x0c07cb72u,0x0c07cb74u,0x0c07cb76u,0x0c07cb78u,0x0c07cb7au,
0x0c07cb7cu,0x0c07cb7eu,0x0c07cbc8u,0x0c07cbcau,0x0c07cbccu,0x0c07cbceu,0x0c07cbd0u,0x0c07cbd2u,0x0c07cbd4u,0x0c07cbd6u,0x0c07cbd8u,0x0c07cbdau,0x0c07cbdcu,0x0c07cbdeu,0x0c07cbe0u,0x0c07cbe2u,
0x0c07cbe4u,0x0c07cbe6u,0x0c07cbe8u,0x0c07cbeau,0x0c07cbecu,0x0c07cbeeu,0x0c07cbf0u,0x0c07cbf2u,0x0c07cbf4u,0x0c07cbf6u,0x0c07cbf8u,0x0c07cbfau,0x0c07cbfcu,0x0c07cbfeu,0x0c07cc00u,0x0c07cc02u,
0x0c07cc04u,0x0c07cc06u,0x0c07cc08u,0x0c07cc0au,0x0c07cc0cu,0x0c07cc0eu,0x0c07cc10u,0x0c07cc12u,0x0c07cc14u,0x0c07cc16u,0x0c07cc18u,0x0c07cc1au,0x0c07cc1cu,0x0c07cc1eu,0x0c07cc20u,0x0c07cc22u,
0x0c07cc24u,0x0c07cc26u,0x0c07cc28u,0x0c07cc2au,0x0c07cc2cu,0x0c07cc2eu,0x0c07cc30u,0x0c07cc32u,0x0c07cc34u,0x0c07cc36u,0x0c07cc38u,0x0c07cc3au,0x0c07cc3cu,0x0c07cc3eu,0x0c07cc40u,0x0c07cc42u,
0x0c07cc44u,0x0c07cc46u,0x0c07cc48u,0x0c07cc4au,0x0c07cc4cu,0x0c07cc4eu,0x0c07cc50u,0x0c07cc52u,0x0c07cc54u,0x0c07cc56u,0x0c07cc58u,0x0c07cc5au,0x0c07cc5cu,0x0c07cc5eu,0x0c07cc60u,0x0c07cc62u,
0x0c07cc64u,0x0c07cc66u,0x0c07cc68u,0x0c07cc6au,0x0c07cc6cu,0x0c07cc6eu,0x0c07cc70u,0x0c07cc72u,0x0c07cc74u,0x0c07cc76u,0x0c07cc78u,0x0c07cc7au,0x0c07cc7cu,0x0c07cc7eu,0x0c07cc80u,0x0c07cc82u,
0x0c07cc84u,0x0c07cc86u,0x0c07cc88u,0x0c07cc8au,0x0c07cc8cu,0x0c07cc8eu,0x0c07cc90u,0x0c07cc92u,0x0c07cc94u,0x0c07cc96u,0x0c07cc98u,0x0c07cc9au,0x0c07cc9cu,0x0c07cc9eu,0x0c07cca0u,0x0c07cca2u,
0x0c07cca4u,0x0c07cca6u,0x0c07cca8u,0x0c07ccaau,0x0c07ccacu,0x0c07ccaeu,0x0c07ccb0u,0x0c07ccb2u,0x0c07ccb4u,0x0c07ccb6u,0x0c07ccb8u,0x0c07ccbau,0x0c07ccbcu,0x0c07ccbeu,0x0c07ccc0u,0x0c07ccc2u,
0x0c07ccc4u,0x0c07ccc6u,0x0c07ccc8u,0x0c07cccau,0x0c07ccccu,0x0c07ccceu,0x0c07ccd0u,0x0c07ccd2u,0x0c07ccd4u,0x0c07ccd6u,0x0c07ccd8u,0x0c07ccdau,0x0c07ccdcu,0x0c07ccdeu,0x0c07cce0u,0x0c07cce2u,
0x0c07cce4u,0x0c07cce6u,0x0c07cce8u,0x0c07cceau,0x0c07ccecu,0x0c07cceeu,0x0c07ccf0u,0x0c07ccf2u,0x0c07ccf4u,0x0c07ccf6u,0x0c07ccf8u,0x0c07ccfau,0x0c07ccfcu,0x0c07ccfeu,0x0c07cd00u,0x0c07cd02u,
0x0c07cd04u,0x0c07cd06u,0x0c07cd08u,0x0c07cd0au,0x0c07cd0cu,0x0c07cd0eu,0x0c07cd10u,0x0c07cd12u,0x0c07cd14u,0x0c07cd16u,0x0c07cd18u,0x0c07cd1au,0x0c07cd1cu,0x0c07cd1eu,0x0c07cd20u,0x0c07cd22u,
0x0c07cd24u,0x0c07cd26u,0x0c07cd28u,0x0c07cd80u,0x0c07cd82u,0x0c07cd84u,0x0c07cd86u,0x0c07cd88u,0x0c07cd8au,0x0c07cd8cu,0x0c07cd8eu,0x0c07cd90u,0x0c07cd92u,0x0c07cd94u,0x0c07cd96u,0x0c07cd98u,
0x0c07cd9au,0x0c07cd9cu,0x0c07cd9eu,0x0c07cda0u,0x0c07cda2u,0x0c07cda4u,0x0c07cda6u,0x0c07cda8u,0x0c07cdaau,0x0c07cdacu,0x0c07cdaeu,0x0c07cdb0u,0x0c07cdb2u,0x0c07cdb4u,0x0c07cdb6u,0x0c07cdb8u,
0x0c07cdbau,0x0c07cdbcu,0x0c07cdbeu,0x0c07cdc0u,0x0c07cdc2u,0x0c07cdc4u,0x0c07cdc6u,0x0c07cdc8u,0x0c07cdcau,0x0c07cdccu,0x0c07cdceu,0x0c07cdd0u,0x0c07cdd2u,0x0c07cdd4u,0x0c07cdd6u,0x0c07cdd8u,
0x0c07cddau,0x0c07cddcu,0x0c07cddeu,0x0c07cde0u,0x0c07cde2u,0x0c07cde4u,0x0c07cde6u,0x0c07cde8u,0x0c07cdeau,0x0c07cdecu,0x0c07cdeeu,0x0c07cdf0u,0x0c07cdf2u,0x0c07cdf4u,0x0c07cdf6u,0x0c07cdf8u,
0x0c07cdfau,0x0c07cdfcu,0x0c07cdfeu,0x0c07ce00u,0x0c07ce02u,0x0c07ce04u,0x0c07ce06u,0x0c07ce08u,0x0c07ce0au,0x0c07ce0cu,0x0c07ce0eu,0x0c07ce10u,0x0c07ce12u,0x0c07ce14u,0x0c07ce16u,0x0c07ce18u,
0x0c07ce1au,0x0c07ce1cu,0x0c07ce1eu,0x0c07ce20u,0x0c07ce22u,0x0c07ce24u,0x0c07ce26u,0x0c07ce28u,0x0c07ce2au,0x0c07ce2cu,0x0c07ce2eu,0x0c07ce30u,0x0c07ce32u,0x0c07ce34u,0x0c07ce36u,0x0c07ce38u,
0x0c07ce3au,0x0c07ce3cu,0x0c07ce3eu,0x0c07ce40u,0x0c07ce42u,0x0c07ce44u,0x0c07ce46u,0x0c07ce48u,0x0c07ce4au,0x0c07ce4cu,0x0c07ce4eu,0x0c07ce50u,0x0c07ce52u,0x0c07ce54u,0x0c07ce56u,0x0c07ce58u,
0x0c07ce5au,0x0c07ce5cu,0x0c07ce5eu,0x0c07ce60u,0x0c07ce62u,0x0c07ce64u,0x0c07ce66u,0x0c07ce68u,0x0c07ce6au,0x0c07ce6cu,0x0c07ce6eu,0x0c07ce70u,0x0c07ce72u,0x0c07ce74u,0x0c07ce76u,0x0c07ce78u,
0x0c07ce7au,0x0c07ce7cu,0x0c07ce7eu,0x0c07ce80u,0x0c07ce82u,0x0c07ce84u,0x0c07ce86u,0x0c07ce88u,0x0c07ce8au,0x0c07ce8cu,0x0c07ce8eu,0x0c07ce90u,0x0c07ce92u,0x0c07ce94u,0x0c07ce96u,0x0c07ce98u,
0x0c07ce9au,0x0c07ce9cu,0x0c07ce9eu,0x0c07cea0u,0x0c07cea2u,0x0c07cea4u,0x0c07cea6u,0x0c07cea8u,0x0c07ceaau,0x0c07ceacu,0x0c07ceaeu,0x0c07ceb0u,0x0c07ceb2u,0x0c07ceb4u,0x0c07ceb6u,0x0c07ceb8u,
0x0c07cebau,0x0c07cebcu,0x0c07cebeu,0x0c07cec0u,0x0c07cec2u,0x0c07cec4u,0x0c07cec6u,0x0c07cec8u,0x0c07cecau,0x0c07ceccu,0x0c08a8c2u,0x0c08a8c4u,0x0c08a8c6u,0x0c08a8c8u,0x0c08a8cau,0x0c08a8ccu,
0x0c08a8ceu,0x0c08a8d0u,0x0c08a942u,0x0c08a944u,0x0c08a946u,0x0c08a948u,0x0c08a94au,0x0c08a94cu,0x0c08a94eu,0x0c08a950u,0x0c08a952u,0x0c08a954u,0x0c08a956u,0x0c08a958u,0x0c08a95au,0x0c08a95cu,
0x0c08a95eu,0x0c08a960u,0x0c08a962u,0x0c08a964u,0x0c08a966u,0x0c08a968u,0x0c08a96au,0x0c08a96cu,0x0c08a96eu,0x0c08a970u,0x0c08a972u,0x0c08a974u,0x0c08a976u,0x0c08a978u,0x0c08a97au,0x0c08a97cu,
0x0c08a97eu,0x0c08a980u,0x0c08a982u,0x0c08a984u,0x0c08a986u,0x0c08a988u,0x0c08a98au,0x0c08a98cu,0x0c08a98eu,0x0c08a990u,0x0c08a992u,0x0c08a994u,0x0c08a996u,0x0c08a998u,0x0c08a99au,0x0c08a99cu,
0x0c08a99eu,0x0c08a9a0u,0x0c08a9a2u,0x0c08a9a4u,0x0c08a9a6u,0x0c08a9a8u,0x0c08a9aau,0x0c08a9acu,0x0c08a9aeu,0x0c08a9b0u,0x0c08a9b2u,0x0c08a9b4u,0x0c08a9b6u,0x0c08a9b8u,0x0c08a9bau,0x0c08a9bcu,
0x0c08a9beu,0x0c08a9c0u,0x0c08a9c2u,0x0c08a9c4u,0x0c08a9c6u,0x0c08a9c8u,0x0c08a9cau,0x0c08a9ccu,0x0c08a9ceu,0x0c08a9d0u,0x0c08a9d2u,0x0c08a9d4u,0x0c08a9d6u,0x0c08a9d8u,0x0c08a9dau,0x0c08a9dcu,
0x0c08a9deu,0x0c08a9e0u,0x0c08a9e2u,0x0c08a9e4u,0x0c08a9e6u,0x0c08a9e8u,0x0c08a9eau,0x0c08a9ecu,0x0c08a9eeu,0x0c08a9f0u,0x0c08a9f2u,0x0c08a9f4u,0x0c0a302eu,0x0c0a3030u,0x0c0a3032u,0x0c0a3034u,
0x0c0a3036u,0x0c0a3038u,0x0c0a303au,0x0c0a303cu,0x0c0a303eu,0x0c0a3040u,0x0c0a3042u,0x0c0a3044u,0x0c0a3046u,0x0c0a3048u,0x0c0a304au,0x0c0a304cu,0x0c0a304eu,0x0c0a3050u,0x0c0a3052u,0x0c0a3054u,
0x0c0a3056u,0x0c0c1f32u,0x0c0c1f34u,0x0c0c1f94u,0x0c0c1f96u,0x0c0c2706u,0x0c0c2708u,0x0c0c270au,0x0c0c270cu,0x0c0c270eu,0x0c0c2710u,0x0c0c2712u,0x0c0c2714u,0x0c0c2716u,0x0c0c2718u,0x0c0c271au,
0x0c0c271cu,0x0c0c271eu,0x0c0c2720u,0x0c0c2722u,0x0c0c2724u,0x0c0c2726u,0x0c0c2728u,0x0c0c272au,0x0c0c272cu,0x0c0c272eu,0x0c0c2730u,0x0c0c2732u,0x0c0c2734u,0x0c0c2736u,0x0c0c2738u,0x0c0c273au,
0x0c0c273cu,0x0c0c273eu,0x0c0c2740u,0x0c0c2742u,0x0c0c2744u,0x0c0c2746u,0x0c0c2748u,0x0c0c274au,0x0c0c274cu,0x0c0c274eu,0x0c0c2750u,0x0c0c2752u,0x0c0c2754u,0x0c0c2756u,0x0c0c2758u,0x0c0c275au,
0x0c0c275cu,0x0c0c275eu,0x0c0c2760u,0x0c0c2762u,0x0c0c2764u,0x0c0c2766u,0x0c0c2768u,0x0c0c276au,0x0c0c276cu,0x0c0c276eu,0x0c0c2770u,0x0c0c2772u,0x0c0c2774u,0x0c0c2776u,0x0c0c2778u,0x0c0c277au,
0x0c0c277cu,0x0c0c277eu,0x0c0c2780u,0x0c0c2782u,0x0c0c2784u,0x0c0c2786u,0x0c0c2788u,0x0c0c278au,0x0c0c278cu,0x0c0c278eu,0x0c0c2790u,0x0c0c2792u,0x0c0c2794u,0x0c0c2796u,0x0c0c2798u,0x0c0c279au,
0x0c0c279cu,0x0c0c279eu,0x0c0c27a0u,0x0c0c27a2u,0x0c0c27a4u,0x0c0c27a6u,0x0c0c27a8u,0x0c0c4e34u,0x0c0c4e36u,0x0c0c4e38u,0x0c0c4e3au,0x0c0c4e3cu,0x0c0c4e3eu,0x0c0c4e40u,0x0c0c4e42u,0x0c0c4e44u,
0x0c0c4e46u,0x0c0c4e48u,
};
static const uint32_t claim_pcs[]={
0x0c0371c2u,0x0c037248u,0x0c03724au,0x0c03724cu,0x0c03724eu,0x0c037250u,0x0c037252u,0x0c037254u,0x0c037256u,0x0c037258u,0x0c03725au,0x0c03725cu,0x0c03725eu,0x0c037260u,0x0c037262u,0x0c037264u,
0x0c037266u,0x0c037268u,0x0c03726au,0x0c03726cu,0x0c03726eu,0x0c037270u,0x0c037272u,0x0c037274u,0x0c037276u,0x0c037278u,0x0c03727au,0x0c03727cu,0x0c03727eu,0x0c037280u,0x0c037282u,0x0c037284u,
0x0c037286u,0x0c037288u,0x0c03728au,0x0c03728cu,0x0c03728eu,0x0c037290u,0x0c037292u,0x0c037294u,0x0c037296u,0x0c037298u,0x0c03729au,0x0c03729cu,0x0c03729eu,0x0c0372a0u,0x0c0372a2u,0x0c0372a4u,
0x0c0372a6u,0x0c0372a8u,0x0c0372aau,0x0c0372acu,0x0c0372aeu,0x0c0372b0u,0x0c0372b2u,0x0c0372b4u,0x0c0372b6u,0x0c0372b8u,0x0c0372bau,0x0c0372bcu,0x0c0372beu,0x0c0372c0u,0x0c0372c2u,0x0c0372c4u,
0x0c0372c6u,0x0c0372c8u,0x0c0372cau,0x0c0372ccu,0x0c0372ceu,0x0c0372d0u,0x0c0372d2u,0x0c0372d4u,0x0c0372d6u,0x0c0372d8u,0x0c0372dau,0x0c0372dcu,0x0c0372deu,0x0c0372e0u,0x0c037502u,0x0c037504u,
0x0c037506u,0x0c037508u,0x0c04631cu,0x0c04631eu,0x0c046320u,0x0c046322u,0x0c046324u,0x0c046326u,0x0c046328u,0x0c04632au,0x0c04632cu,0x0c04632eu,0x0c046330u,0x0c046332u,0x0c046334u,0x0c046336u,
0x0c046338u,0x0c04633au,0x0c04633cu,0x0c04633eu,0x0c046340u,0x0c046342u,0x0c046344u,0x0c046346u,0x0c046348u,0x0c04634au,0x0c04634cu,0x0c04634eu,0x0c046350u,0x0c046352u,0x0c046354u,0x0c046356u,
0x0c046358u,0x0c04635au,0x0c04635cu,0x0c04635eu,0x0c046360u,0x0c046362u,0x0c046364u,0x0c046366u,0x0c046368u,0x0c04636au,0x0c04636cu,0x0c04636eu,0x0c046370u,0x0c046372u,0x0c046374u,0x0c046376u,
0x0c046378u,0x0c04637au,0x0c04637cu,0x0c04637eu,0x0c046380u,0x0c046382u,0x0c046384u,0x0c046386u,0x0c046388u,0x0c04638au,0x0c04638cu,0x0c04638eu,0x0c046390u,0x0c046392u,0x0c046394u,0x0c046396u,
0x0c046398u,0x0c04639au,0x0c04639cu,0x0c04639eu,0x0c0463a0u,0x0c0463a2u,0x0c0463a4u,0x0c0463a6u,0x0c0463a8u,0x0c0463aau,0x0c0463acu,0x0c0463aeu,0x0c046c48u,0x0c046c4au,0x0c046c4cu,0x0c046c4eu,
0x0c046e54u,0x0c046e56u,0x0c046e58u,0x0c046e5au,0x0c046e5cu,0x0c046e5eu,0x0c046e60u,0x0c046e62u,0x0c046e64u,0x0c04b9fcu,0x0c04b9feu,0x0c04ba00u,0x0c04ba02u,0x0c04ba04u,0x0c04ba06u,0x0c04ba08u,
0x0c04ba0au,0x0c04ba0cu,0x0c04ba0eu,0x0c04ba10u,0x0c04ba12u,0x0c04ba14u,0x0c04ba16u,0x0c04ba18u,0x0c04ba1au,0x0c04ba1cu,0x0c04ba1eu,0x0c04ba20u,0x0c04ba22u,0x0c04ba24u,0x0c04ba26u,0x0c04ba28u,
0x0c04ba2au,0x0c04ba2cu,0x0c04ba2eu,0x0c04ba30u,0x0c04ba32u,0x0c04ba34u,0x0c04ba36u,0x0c04ba38u,0x0c04ba3au,0x0c04ba3cu,0x0c04ba3eu,0x0c04ba40u,0x0c04ba42u,0x0c04ba44u,0x0c04ba46u,0x0c04ba48u,
0x0c04ba4au,0x0c04ba4cu,0x0c04ba4eu,0x0c04c0f8u,0x0c04c0fau,0x0c04c0fcu,0x0c04c60au,0x0c04c60cu,0x0c04c60eu,0x0c04c610u,0x0c04c612u,0x0c04c614u,0x0c04c616u,0x0c04c618u,0x0c04c61au,0x0c04c61cu,
0x0c053ddau,0x0c054640u,0x0c054642u,0x0c054644u,0x0c054646u,0x0c054648u,0x0c05464au,0x0c05464cu,0x0c05464eu,0x0c07caa8u,0x0c07caaau,0x0c07caacu,0x0c07caaeu,0x0c07cab0u,0x0c07cab2u,0x0c07cab4u,
0x0c07cab6u,0x0c07cab8u,0x0c07cabau,0x0c07cabcu,0x0c07cabeu,0x0c07cac0u,0x0c07cac2u,0x0c07cac4u,0x0c07cac6u,0x0c07cac8u,0x0c07cacau,0x0c07caccu,0x0c07caceu,0x0c07cad0u,0x0c07cad2u,0x0c07cad4u,
0x0c07cad6u,0x0c07cad8u,0x0c07cadau,0x0c07cadcu,0x0c07cadeu,0x0c07cae0u,0x0c07cae2u,0x0c07cae4u,0x0c07cae6u,0x0c07cae8u,0x0c07caeau,0x0c07caecu,0x0c07caeeu,0x0c07caf0u,0x0c07caf2u,0x0c07caf4u,
0x0c07caf6u,0x0c07caf8u,0x0c07cafau,0x0c07cafcu,0x0c07cafeu,0x0c07cb00u,0x0c07cb02u,0x0c07cb04u,0x0c07cb06u,0x0c07cb08u,0x0c07cb0au,0x0c07cb0cu,0x0c07cb0eu,0x0c07cb10u,0x0c07cb12u,0x0c07cb14u,
0x0c07cb16u,0x0c07cb18u,0x0c07cb1au,0x0c07cb1cu,0x0c07cb1eu,0x0c07cb20u,0x0c07cb22u,0x0c07cb24u,0x0c07cb26u,0x0c07cb28u,0x0c07cb2au,0x0c07cb2cu,0x0c07cb2eu,0x0c07cb30u,0x0c07cb32u,0x0c07cb34u,
0x0c07cb36u,0x0c07cb38u,0x0c07cb3au,0x0c07cb3cu,0x0c07cb3eu,0x0c07cb40u,0x0c07cb42u,0x0c07cb44u,0x0c07cb46u,0x0c07cb48u,0x0c07cb4au,0x0c07cb4cu,0x0c07cb4eu,0x0c07cb50u,0x0c07cb52u,0x0c07cb54u,
0x0c07cb56u,0x0c07cb58u,0x0c07cb5au,0x0c07cb5cu,0x0c07cb5eu,0x0c07cb60u,0x0c07cb62u,0x0c07cb64u,0x0c07cb66u,0x0c07cb68u,0x0c07cb6au,0x0c07cb6cu,0x0c07cb6eu,0x0c07cb70u,0x0c07cb72u,0x0c07cb74u,
0x0c07cb76u,0x0c07cb78u,0x0c07cb7au,0x0c07cb7cu,0x0c07cb7eu,0x0c07cbc8u,0x0c07cbcau,0x0c07cbccu,0x0c07cbceu,0x0c07cbd0u,0x0c07cbd2u,0x0c07cbd4u,0x0c07cbd6u,0x0c07cbd8u,0x0c08a8c2u,0x0c08a8c4u,
0x0c08a8c6u,0x0c08a8c8u,0x0c08a8cau,0x0c08a8ccu,0x0c08a8ceu,0x0c08a8d0u,0x0c08a942u,0x0c08a944u,0x0c08a946u,0x0c08a948u,0x0c08a94au,0x0c08a94cu,0x0c08a94eu,0x0c08a950u,0x0c08a952u,0x0c08a954u,
0x0c08a956u,0x0c08a958u,0x0c08a95au,0x0c08a95cu,0x0c08a95eu,0x0c08a960u,0x0c08a962u,0x0c08a964u,0x0c08a966u,0x0c08a968u,0x0c08a96au,0x0c08a96cu,0x0c08a96eu,0x0c08a970u,0x0c08a972u,0x0c08a974u,
0x0c08a976u,0x0c08a978u,0x0c08a97au,0x0c08a97cu,0x0c08a97eu,0x0c08a980u,0x0c08a982u,0x0c08a984u,0x0c08a986u,0x0c08a988u,0x0c08a98au,0x0c08a98cu,0x0c08a98eu,0x0c08a990u,0x0c08a992u,0x0c08a994u,
0x0c08a996u,0x0c08a998u,0x0c08a99au,0x0c08a99cu,0x0c08a99eu,0x0c08a9a0u,0x0c08a9a2u,0x0c08a9a4u,0x0c08a9a6u,0x0c08a9a8u,0x0c08a9aau,0x0c08a9acu,0x0c08a9aeu,0x0c08a9b0u,0x0c08a9b2u,0x0c08a9b4u,
0x0c08a9b6u,0x0c08a9b8u,0x0c08a9bau,0x0c08a9bcu,0x0c08a9beu,0x0c08a9c0u,0x0c08a9c2u,0x0c08a9c4u,0x0c08a9c6u,0x0c08a9c8u,0x0c08a9cau,0x0c08a9ccu,0x0c08a9ceu,0x0c08a9d0u,0x0c08a9d2u,0x0c08a9d4u,
0x0c08a9d6u,0x0c08a9d8u,0x0c08a9dau,0x0c08a9dcu,0x0c08a9deu,0x0c08a9e0u,0x0c08a9e2u,0x0c08a9e4u,0x0c08a9e6u,0x0c08a9e8u,0x0c08a9eau,0x0c08a9ecu,0x0c08a9eeu,0x0c08a9f0u,0x0c08a9f2u,0x0c08a9f4u,
0x0c0a302eu,0x0c0a3030u,0x0c0a3032u,0x0c0a3034u,0x0c0a3036u,0x0c0a3038u,0x0c0a303au,0x0c0a303cu,0x0c0a303eu,0x0c0a3040u,0x0c0a3042u,0x0c0a3044u,0x0c0a3046u,0x0c0a3048u,0x0c0a304au,0x0c0a304cu,
0x0c0a304eu,0x0c0a3050u,0x0c0a3052u,0x0c0a3054u,0x0c0a3056u,0x0c0c1f32u,0x0c0c1f34u,0x0c0c1f94u,0x0c0c1f96u,0x0c0c2706u,0x0c0c2708u,0x0c0c270au,0x0c0c270cu,0x0c0c270eu,0x0c0c2710u,0x0c0c2712u,
0x0c0c2714u,0x0c0c2716u,0x0c0c2718u,0x0c0c271au,0x0c0c271cu,0x0c0c271eu,0x0c0c2720u,0x0c0c2722u,0x0c0c2724u,0x0c0c2726u,0x0c0c2728u,0x0c0c272au,0x0c0c272cu,0x0c0c272eu,0x0c0c2730u,0x0c0c2732u,
0x0c0c2734u,0x0c0c2736u,0x0c0c2738u,0x0c0c273au,0x0c0c273cu,0x0c0c273eu,0x0c0c2740u,0x0c0c2742u,0x0c0c2744u,0x0c0c2746u,0x0c0c2748u,0x0c0c274au,0x0c0c274cu,0x0c0c274eu,0x0c0c2750u,0x0c0c2752u,
0x0c0c2754u,0x0c0c2756u,0x0c0c2758u,0x0c0c275au,0x0c0c275cu,0x0c0c275eu,0x0c0c2760u,0x0c0c2762u,0x0c0c2764u,0x0c0c2766u,0x0c0c2768u,0x0c0c276au,0x0c0c276cu,0x0c0c276eu,0x0c0c2770u,0x0c0c2772u,
0x0c0c2774u,0x0c0c2776u,0x0c0c2778u,0x0c0c277au,0x0c0c277cu,0x0c0c277eu,0x0c0c2780u,0x0c0c2782u,0x0c0c2784u,0x0c0c2786u,0x0c0c2788u,0x0c0c278au,0x0c0c278cu,0x0c0c278eu,0x0c0c2790u,0x0c0c2792u,
0x0c0c2794u,0x0c0c2796u,0x0c0c2798u,0x0c0c279au,0x0c0c279cu,0x0c0c279eu,0x0c0c27a0u,0x0c0c27a2u,0x0c0c27a4u,0x0c0c27a6u,0x0c0c27a8u,0x0c0c4e34u,0x0c0c4e36u,0x0c0c4e38u,0x0c0c4e3au,0x0c0c4e3cu,
0x0c0c4e3eu,0x0c0c4e40u,0x0c0c4e42u,0x0c0c4e44u,0x0c0c4e46u,0x0c0c4e48u,
};
int vf3_c97_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
