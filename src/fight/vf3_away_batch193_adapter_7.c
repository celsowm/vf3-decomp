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
int vf3_away_batch193_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05fcc4u: goto P_0c05fcc4;
case 0x0c05fcc6u: goto P_0c05fcc6;
case 0x0c05fcc8u: goto P_0c05fcc8;
case 0x0c05fccau: goto P_0c05fcca;
case 0x0c05fcccu: goto P_0c05fccc;
case 0x0c05fcceu: goto P_0c05fcce;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
case 0x0c0a13c2u: goto P_0c0a13c2;
case 0x0c0a13c4u: goto P_0c0a13c4;
case 0x0c0a13c6u: goto P_0c0a13c6;
case 0x0c0a13c8u: goto P_0c0a13c8;
case 0x0c0a13cau: goto P_0c0a13ca;
case 0x0c0a13ccu: goto P_0c0a13cc;
case 0x0c0a13ceu: goto P_0c0a13ce;
case 0x0c0a13d0u: goto P_0c0a13d0;
case 0x0c0a13d2u: goto P_0c0a13d2;
case 0x0c0a13d4u: goto P_0c0a13d4;
case 0x0c0a1f50u: goto P_0c0a1f50;
case 0x0c0a1f52u: goto P_0c0a1f52;
case 0x0c0a1f54u: goto P_0c0a1f54;
case 0x0c0a1f56u: goto P_0c0a1f56;
case 0x0c0a1f58u: goto P_0c0a1f58;
case 0x0c0a1f5au: goto P_0c0a1f5a;
case 0x0c0a1f5cu: goto P_0c0a1f5c;
case 0x0c0a1f5eu: goto P_0c0a1f5e;
case 0x0c0a1f60u: goto P_0c0a1f60;
case 0x0c0a1f62u: goto P_0c0a1f62;
case 0x0c0a1f64u: goto P_0c0a1f64;
case 0x0c0a1f66u: goto P_0c0a1f66;
case 0x0c0a1f68u: goto P_0c0a1f68;
case 0x0c0a1f6au: goto P_0c0a1f6a;
case 0x0c0a1f6cu: goto P_0c0a1f6c;
case 0x0c0a1f6eu: goto P_0c0a1f6e;
case 0x0c0a1f70u: goto P_0c0a1f70;
case 0x0c0a1f72u: goto P_0c0a1f72;
case 0x0c0a1f74u: goto P_0c0a1f74;
case 0x0c0a1f76u: goto P_0c0a1f76;
case 0x0c0a1f78u: goto P_0c0a1f78;
case 0x0c0a1f7au: goto P_0c0a1f7a;
case 0x0c0a1f7cu: goto P_0c0a1f7c;
case 0x0c0a1f7eu: goto P_0c0a1f7e;
case 0x0c0a1f80u: goto P_0c0a1f80;
case 0x0c0a1f82u: goto P_0c0a1f82;
case 0x0c0a1f84u: goto P_0c0a1f84;
case 0x0c0a1f86u: goto P_0c0a1f86;
case 0x0c0a1f88u: goto P_0c0a1f88;
case 0x0c0a1f8au: goto P_0c0a1f8a;
case 0x0c0a1f8cu: goto P_0c0a1f8c;
case 0x0c0a1f8eu: goto P_0c0a1f8e;
case 0x0c0a1f90u: goto P_0c0a1f90;
case 0x0c0a1f92u: goto P_0c0a1f92;
case 0x0c0a1f94u: goto P_0c0a1f94;
case 0x0c0a1f96u: goto P_0c0a1f96;
case 0x0c0a1f98u: goto P_0c0a1f98;
case 0x0c0a1f9au: goto P_0c0a1f9a;
case 0x0c0a1f9cu: goto P_0c0a1f9c;
case 0x0c0a1f9eu: goto P_0c0a1f9e;
case 0x0c0a1fa0u: goto P_0c0a1fa0;
case 0x0c0a1fa2u: goto P_0c0a1fa2;
case 0x0c0a1fa4u: goto P_0c0a1fa4;
case 0x0c0a1fa6u: goto P_0c0a1fa6;
case 0x0c0a1fa8u: goto P_0c0a1fa8;
case 0x0c0a1faau: goto P_0c0a1faa;
case 0x0c0a1facu: goto P_0c0a1fac;
case 0x0c0a1faeu: goto P_0c0a1fae;
case 0x0c0a1fb0u: goto P_0c0a1fb0;
case 0x0c0a1fb2u: goto P_0c0a1fb2;
case 0x0c0a1fb4u: goto P_0c0a1fb4;
case 0x0c0a1fb6u: goto P_0c0a1fb6;
case 0x0c0a1fb8u: goto P_0c0a1fb8;
case 0x0c0a1fbau: goto P_0c0a1fba;
case 0x0c0a1fbcu: goto P_0c0a1fbc;
case 0x0c0a1fbeu: goto P_0c0a1fbe;
case 0x0c0a1fc0u: goto P_0c0a1fc0;
case 0x0c0a1fc2u: goto P_0c0a1fc2;
case 0x0c0a1fc4u: goto P_0c0a1fc4;
case 0x0c0a1fc6u: goto P_0c0a1fc6;
case 0x0c0a1fc8u: goto P_0c0a1fc8;
case 0x0c0a1fcau: goto P_0c0a1fca;
case 0x0c0a1fccu: goto P_0c0a1fcc;
case 0x0c0a1fceu: goto P_0c0a1fce;
case 0x0c0a1fd0u: goto P_0c0a1fd0;
case 0x0c0a22c4u: goto P_0c0a22c4;
case 0x0c0a22c6u: goto P_0c0a22c6;
case 0x0c0a22c8u: goto P_0c0a22c8;
case 0x0c0a22cau: goto P_0c0a22ca;
case 0x0c0a22ccu: goto P_0c0a22cc;
case 0x0c0a22ceu: goto P_0c0a22ce;
case 0x0c0a22d0u: goto P_0c0a22d0;
case 0x0c0a22d2u: goto P_0c0a22d2;
case 0x0c0a22d4u: goto P_0c0a22d4;
case 0x0c0a22d6u: goto P_0c0a22d6;
case 0x0c0a22d8u: goto P_0c0a22d8;
case 0x0c0a22dau: goto P_0c0a22da;
case 0x0c0a22dcu: goto P_0c0a22dc;
case 0x0c0a22deu: goto P_0c0a22de;
case 0x0c0a22e0u: goto P_0c0a22e0;
case 0x0c0a22e2u: goto P_0c0a22e2;
case 0x0c0a22e4u: goto P_0c0a22e4;
case 0x0c0a22e6u: goto P_0c0a22e6;
case 0x0c0a22e8u: goto P_0c0a22e8;
case 0x0c0a22eau: goto P_0c0a22ea;
case 0x0c0a22ecu: goto P_0c0a22ec;
case 0x0c0a22eeu: goto P_0c0a22ee;
case 0x0c0a22f0u: goto P_0c0a22f0;
case 0x0c0a22f2u: goto P_0c0a22f2;
case 0x0c0a22f4u: goto P_0c0a22f4;
case 0x0c0a22f6u: goto P_0c0a22f6;
case 0x0c0a22f8u: goto P_0c0a22f8;
case 0x0c0a22fau: goto P_0c0a22fa;
case 0x0c0a22fcu: goto P_0c0a22fc;
case 0x0c0a22feu: goto P_0c0a22fe;
case 0x0c0a2300u: goto P_0c0a2300;
case 0x0c0a2302u: goto P_0c0a2302;
case 0x0c0a2304u: goto P_0c0a2304;
case 0x0c0a2306u: goto P_0c0a2306;
case 0x0c0a2308u: goto P_0c0a2308;
case 0x0c0a230au: goto P_0c0a230a;
case 0x0c0a230cu: goto P_0c0a230c;
case 0x0c0a230eu: goto P_0c0a230e;
case 0x0c0a2310u: goto P_0c0a2310;
case 0x0c0a2312u: goto P_0c0a2312;
case 0x0c0a2314u: goto P_0c0a2314;
case 0x0c0a2316u: goto P_0c0a2316;
case 0x0c0a2318u: goto P_0c0a2318;
case 0x0c0a231au: goto P_0c0a231a;
case 0x0c0a231cu: goto P_0c0a231c;
case 0x0c0a231eu: goto P_0c0a231e;
case 0x0c0a2320u: goto P_0c0a2320;
case 0x0c0a2322u: goto P_0c0a2322;
case 0x0c0a2324u: goto P_0c0a2324;
case 0x0c0a2326u: goto P_0c0a2326;
case 0x0c0a2328u: goto P_0c0a2328;
case 0x0c0a232au: goto P_0c0a232a;
case 0x0c0a232cu: goto P_0c0a232c;
case 0x0c0a232eu: goto P_0c0a232e;
case 0x0c0a2330u: goto P_0c0a2330;
case 0x0c0a2332u: goto P_0c0a2332;
case 0x0c0a2334u: goto P_0c0a2334;
case 0x0c0a2336u: goto P_0c0a2336;
case 0x0c0a2338u: goto P_0c0a2338;
case 0x0c0a233au: goto P_0c0a233a;
case 0x0c0a233cu: goto P_0c0a233c;
case 0x0c0a233eu: goto P_0c0a233e;
case 0x0c0a2340u: goto P_0c0a2340;
case 0x0c0a2342u: goto P_0c0a2342;
case 0x0c0a2344u: goto P_0c0a2344;
case 0x0c0a2346u: goto P_0c0a2346;
case 0x0c0a2348u: goto P_0c0a2348;
case 0x0c0a234au: goto P_0c0a234a;
case 0x0c0a234cu: goto P_0c0a234c;
case 0x0c0a234eu: goto P_0c0a234e;
case 0x0c0a2350u: goto P_0c0a2350;
case 0x0c0a2352u: goto P_0c0a2352;
case 0x0c0a2354u: goto P_0c0a2354;
case 0x0c0a2356u: goto P_0c0a2356;
case 0x0c0a2358u: goto P_0c0a2358;
case 0x0c0a235au: goto P_0c0a235a;
case 0x0c0a235cu: goto P_0c0a235c;
case 0x0c0a235eu: goto P_0c0a235e;
case 0x0c0a2360u: goto P_0c0a2360;
case 0x0c0a2362u: goto P_0c0a2362;
case 0x0c0a2364u: goto P_0c0a2364;
case 0x0c0a2366u: goto P_0c0a2366;
case 0x0c0a2368u: goto P_0c0a2368;
case 0x0c0a236au: goto P_0c0a236a;
case 0x0c0a236cu: goto P_0c0a236c;
case 0x0c0a236eu: goto P_0c0a236e;
case 0x0c0a2370u: goto P_0c0a2370;
case 0x0c0a2372u: goto P_0c0a2372;
case 0x0c0a2374u: goto P_0c0a2374;
case 0x0c0a2376u: goto P_0c0a2376;
case 0x0c0a2378u: goto P_0c0a2378;
case 0x0c0a237au: goto P_0c0a237a;
case 0x0c0a237cu: goto P_0c0a237c;
case 0x0c0a237eu: goto P_0c0a237e;
case 0x0c0a2380u: goto P_0c0a2380;
case 0x0c0a2382u: goto P_0c0a2382;
case 0x0c0a2384u: goto P_0c0a2384;
case 0x0c0a2386u: goto P_0c0a2386;
case 0x0c0a2388u: goto P_0c0a2388;
case 0x0c0a238au: goto P_0c0a238a;
case 0x0c0a238cu: goto P_0c0a238c;
case 0x0c0a238eu: goto P_0c0a238e;
case 0x0c0a2390u: goto P_0c0a2390;
case 0x0c0a2392u: goto P_0c0a2392;
case 0x0c0a2394u: goto P_0c0a2394;
case 0x0c0a2396u: goto P_0c0a2396;
case 0x0c0a2398u: goto P_0c0a2398;
case 0x0c0a239au: goto P_0c0a239a;
case 0x0c0a239cu: goto P_0c0a239c;
case 0x0c0a239eu: goto P_0c0a239e;
case 0x0c0a23a0u: goto P_0c0a23a0;
case 0x0c0a23a2u: goto P_0c0a23a2;
case 0x0c0a23a4u: goto P_0c0a23a4;
case 0x0c0a23a6u: goto P_0c0a23a6;
case 0x0c0a23a8u: goto P_0c0a23a8;
case 0x0c0a23aau: goto P_0c0a23aa;
case 0x0c0a23acu: goto P_0c0a23ac;
case 0x0c0a23aeu: goto P_0c0a23ae;
case 0x0c0a23b0u: goto P_0c0a23b0;
case 0x0c0a23b2u: goto P_0c0a23b2;
case 0x0c0a23b4u: goto P_0c0a23b4;
case 0x0c0a23b6u: goto P_0c0a23b6;
case 0x0c0a23b8u: goto P_0c0a23b8;
case 0x0c0a23bau: goto P_0c0a23ba;
case 0x0c0a23bcu: goto P_0c0a23bc;
case 0x0c0a240cu: goto P_0c0a240c;
case 0x0c0a240eu: goto P_0c0a240e;
case 0x0c0a2410u: goto P_0c0a2410;
case 0x0c0a2412u: goto P_0c0a2412;
case 0x0c0a2414u: goto P_0c0a2414;
case 0x0c0a2416u: goto P_0c0a2416;
case 0x0c0a2418u: goto P_0c0a2418;
case 0x0c0a241au: goto P_0c0a241a;
case 0x0c0a241cu: goto P_0c0a241c;
case 0x0c0a241eu: goto P_0c0a241e;
case 0x0c0a2420u: goto P_0c0a2420;
case 0x0c0a2422u: goto P_0c0a2422;
case 0x0c0a2424u: goto P_0c0a2424;
case 0x0c0a2426u: goto P_0c0a2426;
case 0x0c0a2428u: goto P_0c0a2428;
case 0x0c0a242au: goto P_0c0a242a;
case 0x0c0a242cu: goto P_0c0a242c;
case 0x0c0a242eu: goto P_0c0a242e;
case 0x0c0a2430u: goto P_0c0a2430;
case 0x0c0a2432u: goto P_0c0a2432;
case 0x0c0a2434u: goto P_0c0a2434;
case 0x0c0a2436u: goto P_0c0a2436;
case 0x0c0a2438u: goto P_0c0a2438;
case 0x0c0a243au: goto P_0c0a243a;
case 0x0c0a243cu: goto P_0c0a243c;
case 0x0c0a243eu: goto P_0c0a243e;
case 0x0c0a2440u: goto P_0c0a2440;
case 0x0c0a2442u: goto P_0c0a2442;
case 0x0c0a2444u: goto P_0c0a2444;
case 0x0c0a2446u: goto P_0c0a2446;
case 0x0c0a2448u: goto P_0c0a2448;
case 0x0c0a244au: goto P_0c0a244a;
case 0x0c0a244cu: goto P_0c0a244c;
case 0x0c0a244eu: goto P_0c0a244e;
case 0x0c0a2450u: goto P_0c0a2450;
case 0x0c0a2452u: goto P_0c0a2452;
case 0x0c0a2454u: goto P_0c0a2454;
case 0x0c0a2456u: goto P_0c0a2456;
case 0x0c0a2458u: goto P_0c0a2458;
case 0x0c0a245au: goto P_0c0a245a;
case 0x0c0a245cu: goto P_0c0a245c;
case 0x0c0a245eu: goto P_0c0a245e;
case 0x0c0a2460u: goto P_0c0a2460;
case 0x0c0a2462u: goto P_0c0a2462;
case 0x0c0a2464u: goto P_0c0a2464;
case 0x0c0a2466u: goto P_0c0a2466;
case 0x0c0a2468u: goto P_0c0a2468;
case 0x0c0a246au: goto P_0c0a246a;
case 0x0c0a246cu: goto P_0c0a246c;
case 0x0c0a246eu: goto P_0c0a246e;
case 0x0c0a2470u: goto P_0c0a2470;
case 0x0c0a2472u: goto P_0c0a2472;
case 0x0c0a2474u: goto P_0c0a2474;
case 0x0c0a2476u: goto P_0c0a2476;
case 0x0c0a2478u: goto P_0c0a2478;
case 0x0c0a247au: goto P_0c0a247a;
case 0x0c0a247cu: goto P_0c0a247c;
case 0x0c0a247eu: goto P_0c0a247e;
case 0x0c0a2480u: goto P_0c0a2480;
case 0x0c0a2482u: goto P_0c0a2482;
case 0x0c0a2484u: goto P_0c0a2484;
case 0x0c0a2486u: goto P_0c0a2486;
case 0x0c0a2488u: goto P_0c0a2488;
case 0x0c0a248au: goto P_0c0a248a;
case 0x0c0a248cu: goto P_0c0a248c;
case 0x0c0a248eu: goto P_0c0a248e;
case 0x0c0a2490u: goto P_0c0a2490;
case 0x0c0a2492u: goto P_0c0a2492;
case 0x0c0a2494u: goto P_0c0a2494;
case 0x0c0a2496u: goto P_0c0a2496;
case 0x0c0a2498u: goto P_0c0a2498;
case 0x0c0a249au: goto P_0c0a249a;
case 0x0c0a249cu: goto P_0c0a249c;
case 0x0c0a249eu: goto P_0c0a249e;
case 0x0c0a24a0u: goto P_0c0a24a0;
case 0x0c0a24a2u: goto P_0c0a24a2;
case 0x0c0a24a4u: goto P_0c0a24a4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05fcc4: /* original d330, guest PC 0x0c05fcc4 */
if(!s->budget--) { s->failed_pc=0x0c05fcc4u; return 0; }
r[3]=read(ram,0x0c05fd88u,4);
goto P_0c05fcc6;
P_0c05fcc6: /* original 7ffc, guest PC 0x0c05fcc6 */
if(!s->budget--) { s->failed_pc=0x0c05fcc6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05fcc8;
P_0c05fcc8: /* original 2f42, guest PC 0x0c05fcc8 */
if(!s->budget--) { s->failed_pc=0x0c05fcc8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05fcca;
P_0c05fcca: /* original 6232, guest PC 0x0c05fcca */
if(!s->budget--) { s->failed_pc=0x0c05fccau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05fccc;
P_0c05fccc: /* original 422b, guest PC 0x0c05fccc */
if(!s->budget--) { s->failed_pc=0x0c05fcccu; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c05fcce: /* original 7f04, guest PC 0x0c05fcce */
if(!s->budget--) { s->failed_pc=0x0c05fcceu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c05fcd0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fcd0u; return 0; } return 1;
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
if(!vf3_matrix_family(0x0c062e8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062e8eu; return 0; } return 1;
P_0c0a13c2: /* original 4f22, guest PC 0x0c0a13c2 */
if(!s->budget--) { s->failed_pc=0x0c0a13c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a13c4;
P_0c0a13c4: /* original d31f, guest PC 0x0c0a13c4 */
if(!s->budget--) { s->failed_pc=0x0c0a13c4u; return 0; }
r[3]=read(ram,0x0c0a1444u,4);
goto P_0c0a13c6;
P_0c0a13c6: /* original 430b, guest PC 0x0c0a13c6 */
if(!s->budget--) { s->failed_pc=0x0c0a13c6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a13cau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a13cau) { target=s->pc; goto dispatch; }
goto P_0c0a13ca;
P_0c0a13c8: /* original 0009, guest PC 0x0c0a13c8 */
if(!s->budget--) { s->failed_pc=0x0c0a13c8u; return 0; }
goto P_0c0a13ca;
P_0c0a13ca: /* original d21f, guest PC 0x0c0a13ca */
if(!s->budget--) { s->failed_pc=0x0c0a13cau; return 0; }
r[2]=read(ram,0x0c0a1448u,4);
goto P_0c0a13cc;
P_0c0a13cc: /* original 420b, guest PC 0x0c0a13cc */
if(!s->budget--) { s->failed_pc=0x0c0a13ccu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a13d0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a13d0u) { target=s->pc; goto dispatch; }
goto P_0c0a13d0;
P_0c0a13ce: /* original 0009, guest PC 0x0c0a13ce */
if(!s->budget--) { s->failed_pc=0x0c0a13ceu; return 0; }
goto P_0c0a13d0;
P_0c0a13d0: /* original d31e, guest PC 0x0c0a13d0 */
if(!s->budget--) { s->failed_pc=0x0c0a13d0u; return 0; }
r[3]=read(ram,0x0c0a144cu,4);
goto P_0c0a13d2;
P_0c0a13d2: /* original 432b, guest PC 0x0c0a13d2 */
if(!s->budget--) { s->failed_pc=0x0c0a13d2u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c038cb0u: return vf3_matrix_family(0x0c038cb0u,s,ram);
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
P_0c0a13d4: /* original 4f26, guest PC 0x0c0a13d4 */
if(!s->budget--) { s->failed_pc=0x0c0a13d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0a13d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a13d6u; return 0; } return 1;
P_0c0a1f50: /* original 2fe6, guest PC 0x0c0a1f50 */
if(!s->budget--) { s->failed_pc=0x0c0a1f50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a1f52;
P_0c0a1f52: /* original 2fd6, guest PC 0x0c0a1f52 */
if(!s->budget--) { s->failed_pc=0x0c0a1f52u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a1f54;
P_0c0a1f54: /* original 4f22, guest PC 0x0c0a1f54 */
if(!s->budget--) { s->failed_pc=0x0c0a1f54u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a1f56;
P_0c0a1f56: /* original d328, guest PC 0x0c0a1f56 */
if(!s->budget--) { s->failed_pc=0x0c0a1f56u; return 0; }
r[3]=read(ram,0x0c0a1ff8u,4);
goto P_0c0a1f58;
P_0c0a1f58: /* original 430b, guest PC 0x0c0a1f58 */
if(!s->budget--) { s->failed_pc=0x0c0a1f58u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a1f5cu;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a1f5cu) { target=s->pc; goto dispatch; }
goto P_0c0a1f5c;
P_0c0a1f5a: /* original 6e43, guest PC 0x0c0a1f5a */
if(!s->budget--) { s->failed_pc=0x0c0a1f5au; return 0; }
r[14]=r[4];
goto P_0c0a1f5c;
P_0c0a1f5c: /* original 6d03, guest PC 0x0c0a1f5c */
if(!s->budget--) { s->failed_pc=0x0c0a1f5cu; return 0; }
r[13]=r[0];
goto P_0c0a1f5e;
P_0c0a1f5e: /* original 62d1, guest PC 0x0c0a1f5e */
if(!s->budget--) { s->failed_pc=0x0c0a1f5eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[2]=tmp;
goto P_0c0a1f60;
P_0c0a1f60: /* original 2228, guest PC 0x0c0a1f60 */
if(!s->budget--) { s->failed_pc=0x0c0a1f60u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a1f62;
P_0c0a1f62: /* original 8931, guest PC 0x0c0a1f62 */
if(!s->budget--) { s->failed_pc=0x0c0a1f62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc8; }
goto P_0c0a1f64;
P_0c0a1f64: /* original 85d1, guest PC 0x0c0a1f64 */
if(!s->budget--) { s->failed_pc=0x0c0a1f64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c0a1f66;
P_0c0a1f66: /* original 2008, guest PC 0x0c0a1f66 */
if(!s->budget--) { s->failed_pc=0x0c0a1f66u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a1f68;
P_0c0a1f68: /* original 892c, guest PC 0x0c0a1f68 */
if(!s->budget--) { s->failed_pc=0x0c0a1f68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc4; }
goto P_0c0a1f6a;
P_0c0a1f6a: /* original d324, guest PC 0x0c0a1f6a */
if(!s->budget--) { s->failed_pc=0x0c0a1f6au; return 0; }
r[3]=read(ram,0x0c0a1ffcu,4);
goto P_0c0a1f6c;
P_0c0a1f6c: /* original 430b, guest PC 0x0c0a1f6c */
if(!s->budget--) { s->failed_pc=0x0c0a1f6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a1f70u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a1f70u) { target=s->pc; goto dispatch; }
goto P_0c0a1f70;
P_0c0a1f6e: /* original 0009, guest PC 0x0c0a1f6e */
if(!s->budget--) { s->failed_pc=0x0c0a1f6eu; return 0; }
goto P_0c0a1f70;
P_0c0a1f70: /* original 2008, guest PC 0x0c0a1f70 */
if(!s->budget--) { s->failed_pc=0x0c0a1f70u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a1f72;
P_0c0a1f72: /* original 8b0b, guest PC 0x0c0a1f72 */
if(!s->budget--) { s->failed_pc=0x0c0a1f72u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1f8c; }
goto P_0c0a1f74;
P_0c0a1f74: /* original 60e3, guest PC 0x0c0a1f74 */
if(!s->budget--) { s->failed_pc=0x0c0a1f74u; return 0; }
r[0]=r[14];
goto P_0c0a1f76;
P_0c0a1f76: /* original 8801, guest PC 0x0c0a1f76 */
if(!s->budget--) { s->failed_pc=0x0c0a1f76u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a1f78;
P_0c0a1f78: /* original 8b01, guest PC 0x0c0a1f78 */
if(!s->budget--) { s->failed_pc=0x0c0a1f78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1f7e; }
goto P_0c0a1f7a;
P_0c0a1f7a: /* original a026, guest PC 0x0c0a1f7a */
if(!s->budget--) { s->failed_pc=0x0c0a1f7au; return 0; }
r[0]=0x00000010u;
goto P_0c0a1fca;
P_0c0a1f7c: /* original e010, guest PC 0x0c0a1f7c */
if(!s->budget--) { s->failed_pc=0x0c0a1f7cu; return 0; }
r[0]=0x00000010u;
goto P_0c0a1f7e;
P_0c0a1f7e: /* original 8802, guest PC 0x0c0a1f7e */
if(!s->budget--) { s->failed_pc=0x0c0a1f7eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a1f80;
P_0c0a1f80: /* original 8902, guest PC 0x0c0a1f80 */
if(!s->budget--) { s->failed_pc=0x0c0a1f80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1f88; }
goto P_0c0a1f82;
P_0c0a1f82: /* original 60e3, guest PC 0x0c0a1f82 */
if(!s->budget--) { s->failed_pc=0x0c0a1f82u; return 0; }
r[0]=r[14];
goto P_0c0a1f84;
P_0c0a1f84: /* original 8803, guest PC 0x0c0a1f84 */
if(!s->budget--) { s->failed_pc=0x0c0a1f84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a1f86;
P_0c0a1f86: /* original 8b1f, guest PC 0x0c0a1f86 */
if(!s->budget--) { s->failed_pc=0x0c0a1f86u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1fc8; }
goto P_0c0a1f88;
P_0c0a1f88: /* original a01f, guest PC 0x0c0a1f88 */
if(!s->budget--) { s->failed_pc=0x0c0a1f88u; return 0; }
r[0]=0x00000000u;
goto P_0c0a1fca;
P_0c0a1f8a: /* original e000, guest PC 0x0c0a1f8a */
if(!s->budget--) { s->failed_pc=0x0c0a1f8au; return 0; }
r[0]=0x00000000u;
goto P_0c0a1f8c;
P_0c0a1f8c: /* original e038, guest PC 0x0c0a1f8c */
if(!s->budget--) { s->failed_pc=0x0c0a1f8cu; return 0; }
r[0]=0x00000038u;
goto P_0c0a1f8e;
P_0c0a1f8e: /* original 02dd, guest PC 0x0c0a1f8e */
if(!s->budget--) { s->failed_pc=0x0c0a1f8eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a1f90;
P_0c0a1f90: /* original e30c, guest PC 0x0c0a1f90 */
if(!s->budget--) { s->failed_pc=0x0c0a1f90u; return 0; }
r[3]=0x0000000cu;
goto P_0c0a1f92;
P_0c0a1f92: /* original 622d, guest PC 0x0c0a1f92 */
if(!s->budget--) { s->failed_pc=0x0c0a1f92u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a1f94;
P_0c0a1f94: /* original 3233, guest PC 0x0c0a1f94 */
if(!s->budget--) { s->failed_pc=0x0c0a1f94u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0a1f96;
P_0c0a1f96: /* original 890a, guest PC 0x0c0a1f96 */
if(!s->budget--) { s->failed_pc=0x0c0a1f96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fae; }
goto P_0c0a1f98;
P_0c0a1f98: /* original 60e3, guest PC 0x0c0a1f98 */
if(!s->budget--) { s->failed_pc=0x0c0a1f98u; return 0; }
r[0]=r[14];
goto P_0c0a1f9a;
P_0c0a1f9a: /* original 8801, guest PC 0x0c0a1f9a */
if(!s->budget--) { s->failed_pc=0x0c0a1f9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a1f9c;
P_0c0a1f9c: /* original 8905, guest PC 0x0c0a1f9c */
if(!s->budget--) { s->failed_pc=0x0c0a1f9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1faa; }
goto P_0c0a1f9e;
P_0c0a1f9e: /* original 60e3, guest PC 0x0c0a1f9e */
if(!s->budget--) { s->failed_pc=0x0c0a1f9eu; return 0; }
r[0]=r[14];
goto P_0c0a1fa0;
P_0c0a1fa0: /* original 8802, guest PC 0x0c0a1fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a1fa2;
P_0c0a1fa2: /* original 890d, guest PC 0x0c0a1fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc0; }
goto P_0c0a1fa4;
P_0c0a1fa4: /* original 60e3, guest PC 0x0c0a1fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa4u; return 0; }
r[0]=r[14];
goto P_0c0a1fa6;
P_0c0a1fa6: /* original 8803, guest PC 0x0c0a1fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a1fa8;
P_0c0a1fa8: /* original 8b0e, guest PC 0x0c0a1fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1fc8; }
goto P_0c0a1faa;
P_0c0a1faa: /* original a00e, guest PC 0x0c0a1faa */
if(!s->budget--) { s->failed_pc=0x0c0a1faau; return 0; }
r[0]=0x00000008u;
goto P_0c0a1fca;
P_0c0a1fac: /* original e008, guest PC 0x0c0a1fac */
if(!s->budget--) { s->failed_pc=0x0c0a1facu; return 0; }
r[0]=0x00000008u;
goto P_0c0a1fae;
P_0c0a1fae: /* original 60e3, guest PC 0x0c0a1fae */
if(!s->budget--) { s->failed_pc=0x0c0a1faeu; return 0; }
r[0]=r[14];
goto P_0c0a1fb0;
P_0c0a1fb0: /* original 8801, guest PC 0x0c0a1fb0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a1fb2;
P_0c0a1fb2: /* original 8905, guest PC 0x0c0a1fb2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc0; }
goto P_0c0a1fb4;
P_0c0a1fb4: /* original 60e3, guest PC 0x0c0a1fb4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb4u; return 0; }
r[0]=r[14];
goto P_0c0a1fb6;
P_0c0a1fb6: /* original 8802, guest PC 0x0c0a1fb6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a1fb8;
P_0c0a1fb8: /* original 8902, guest PC 0x0c0a1fb8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc0; }
goto P_0c0a1fba;
P_0c0a1fba: /* original 60e3, guest PC 0x0c0a1fba */
if(!s->budget--) { s->failed_pc=0x0c0a1fbau; return 0; }
r[0]=r[14];
goto P_0c0a1fbc;
P_0c0a1fbc: /* original 8803, guest PC 0x0c0a1fbc */
if(!s->budget--) { s->failed_pc=0x0c0a1fbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a1fbe;
P_0c0a1fbe: /* original 8b03, guest PC 0x0c0a1fbe */
if(!s->budget--) { s->failed_pc=0x0c0a1fbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1fc8; }
goto P_0c0a1fc0;
P_0c0a1fc0: /* original a003, guest PC 0x0c0a1fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc0u; return 0; }
r[0]=0x00000011u;
goto P_0c0a1fca;
P_0c0a1fc2: /* original e011, guest PC 0x0c0a1fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc2u; return 0; }
r[0]=0x00000011u;
goto P_0c0a1fc4;
P_0c0a1fc4: /* original a001, guest PC 0x0c0a1fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc4u; return 0; }
r[0]=0x00000002u;
goto P_0c0a1fca;
P_0c0a1fc6: /* original e002, guest PC 0x0c0a1fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc6u; return 0; }
r[0]=0x00000002u;
goto P_0c0a1fc8;
P_0c0a1fc8: /* original e004, guest PC 0x0c0a1fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc8u; return 0; }
r[0]=0x00000004u;
goto P_0c0a1fca;
P_0c0a1fca: /* original 4f26, guest PC 0x0c0a1fca */
if(!s->budget--) { s->failed_pc=0x0c0a1fcau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a1fcc;
P_0c0a1fcc: /* original 6df6, guest PC 0x0c0a1fcc */
if(!s->budget--) { s->failed_pc=0x0c0a1fccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a1fce;
P_0c0a1fce: /* original 000b, guest PC 0x0c0a1fce */
if(!s->budget--) { s->failed_pc=0x0c0a1fceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a1fd0: /* original 6ef6, guest PC 0x0c0a1fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a1fd2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a1fd2u; return 0; } return 1;
P_0c0a22c4: /* original 2fe6, guest PC 0x0c0a22c4 */
if(!s->budget--) { s->failed_pc=0x0c0a22c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22c6;
P_0c0a22c6: /* original 2fd6, guest PC 0x0c0a22c6 */
if(!s->budget--) { s->failed_pc=0x0c0a22c6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22c8;
P_0c0a22c8: /* original 2fc6, guest PC 0x0c0a22c8 */
if(!s->budget--) { s->failed_pc=0x0c0a22c8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22ca;
P_0c0a22ca: /* original 2fb6, guest PC 0x0c0a22ca */
if(!s->budget--) { s->failed_pc=0x0c0a22cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22cc;
P_0c0a22cc: /* original 2fa6, guest PC 0x0c0a22cc */
if(!s->budget--) { s->failed_pc=0x0c0a22ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22ce;
P_0c0a22ce: /* original 2f96, guest PC 0x0c0a22ce */
if(!s->budget--) { s->failed_pc=0x0c0a22ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22d0;
P_0c0a22d0: /* original 4f22, guest PC 0x0c0a22d0 */
if(!s->budget--) { s->failed_pc=0x0c0a22d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a22d2;
P_0c0a22d2: /* original db3f, guest PC 0x0c0a22d2 */
if(!s->budget--) { s->failed_pc=0x0c0a22d2u; return 0; }
r[11]=read(ram,0x0c0a23d0u,4);
goto P_0c0a22d4;
P_0c0a22d4: /* original 4b0b, guest PC 0x0c0a22d4 */
if(!s->budget--) { s->failed_pc=0x0c0a22d4u; return 0; }
target=r[11];
r[16]=code_base|0x0c0a22d8u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a22d8u) { target=s->pc; goto dispatch; }
goto P_0c0a22d8;
P_0c0a22d6: /* original e400, guest PC 0x0c0a22d6 */
if(!s->budget--) { s->failed_pc=0x0c0a22d6u; return 0; }
r[4]=0x00000000u;
goto P_0c0a22d8;
P_0c0a22d8: /* original d33e, guest PC 0x0c0a22d8 */
if(!s->budget--) { s->failed_pc=0x0c0a22d8u; return 0; }
r[3]=read(ram,0x0c0a23d4u,4);
goto P_0c0a22da;
P_0c0a22da: /* original 430b, guest PC 0x0c0a22da */
if(!s->budget--) { s->failed_pc=0x0c0a22dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a22deu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a22deu) { target=s->pc; goto dispatch; }
goto P_0c0a22de;
P_0c0a22dc: /* original 0009, guest PC 0x0c0a22dc */
if(!s->budget--) { s->failed_pc=0x0c0a22dcu; return 0; }
goto P_0c0a22de;
P_0c0a22de: /* original d43e, guest PC 0x0c0a22de */
if(!s->budget--) { s->failed_pc=0x0c0a22deu; return 0; }
r[4]=read(ram,0x0c0a23d8u,4);
goto P_0c0a22e0;
P_0c0a22e0: /* original 6a43, guest PC 0x0c0a22e0 */
if(!s->budget--) { s->failed_pc=0x0c0a22e0u; return 0; }
r[10]=r[4];
goto P_0c0a22e2;
P_0c0a22e2: /* original 7a10, guest PC 0x0c0a22e2 */
if(!s->budget--) { s->failed_pc=0x0c0a22e2u; return 0; }
r[10]+=0x00000010u;
goto P_0c0a22e4;
P_0c0a22e4: /* original 6c43, guest PC 0x0c0a22e4 */
if(!s->budget--) { s->failed_pc=0x0c0a22e4u; return 0; }
r[12]=r[4];
goto P_0c0a22e6;
P_0c0a22e6: /* original de3d, guest PC 0x0c0a22e6 */
if(!s->budget--) { s->failed_pc=0x0c0a22e6u; return 0; }
r[14]=read(ram,0x0c0a23dcu,4);
goto P_0c0a22e8;
P_0c0a22e8: /* original 4e0b, guest PC 0x0c0a22e8 */
if(!s->budget--) { s->failed_pc=0x0c0a22e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a22ecu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a22ecu) { target=s->pc; goto dispatch; }
goto P_0c0a22ec;
P_0c0a22ea: /* original e400, guest PC 0x0c0a22ea */
if(!s->budget--) { s->failed_pc=0x0c0a22eau; return 0; }
r[4]=0x00000000u;
goto P_0c0a22ec;
P_0c0a22ec: /* original de3c, guest PC 0x0c0a22ec */
if(!s->budget--) { s->failed_pc=0x0c0a22ecu; return 0; }
r[14]=read(ram,0x0c0a23e0u,4);
goto P_0c0a22ee;
P_0c0a22ee: /* original 4e0b, guest PC 0x0c0a22ee */
if(!s->budget--) { s->failed_pc=0x0c0a22eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a22f2u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a22f2u) { target=s->pc; goto dispatch; }
goto P_0c0a22f2;
P_0c0a22f0: /* original e401, guest PC 0x0c0a22f0 */
if(!s->budget--) { s->failed_pc=0x0c0a22f0u; return 0; }
r[4]=0x00000001u;
goto P_0c0a22f2;
P_0c0a22f2: /* original de3c, guest PC 0x0c0a22f2 */
if(!s->budget--) { s->failed_pc=0x0c0a22f2u; return 0; }
r[14]=read(ram,0x0c0a23e4u,4);
goto P_0c0a22f4;
P_0c0a22f4: /* original 4e0b, guest PC 0x0c0a22f4 */
if(!s->budget--) { s->failed_pc=0x0c0a22f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a22f8u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a22f8u) { target=s->pc; goto dispatch; }
goto P_0c0a22f8;
P_0c0a22f6: /* original e400, guest PC 0x0c0a22f6 */
if(!s->budget--) { s->failed_pc=0x0c0a22f6u; return 0; }
r[4]=0x00000000u;
goto P_0c0a22f8;
P_0c0a22f8: /* original de3b, guest PC 0x0c0a22f8 */
if(!s->budget--) { s->failed_pc=0x0c0a22f8u; return 0; }
r[14]=read(ram,0x0c0a23e8u,4);
goto P_0c0a22fa;
P_0c0a22fa: /* original e500, guest PC 0x0c0a22fa */
if(!s->budget--) { s->failed_pc=0x0c0a22fau; return 0; }
r[5]=0x00000000u;
goto P_0c0a22fc;
P_0c0a22fc: /* original 4e0b, guest PC 0x0c0a22fc */
if(!s->budget--) { s->failed_pc=0x0c0a22fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2300u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2300u) { target=s->pc; goto dispatch; }
goto P_0c0a2300;
P_0c0a22fe: /* original e403, guest PC 0x0c0a22fe */
if(!s->budget--) { s->failed_pc=0x0c0a22feu; return 0; }
r[4]=0x00000003u;
goto P_0c0a2300;
P_0c0a2300: /* original de3a, guest PC 0x0c0a2300 */
if(!s->budget--) { s->failed_pc=0x0c0a2300u; return 0; }
r[14]=read(ram,0x0c0a23ecu,4);
goto P_0c0a2302;
P_0c0a2302: /* original e560, guest PC 0x0c0a2302 */
if(!s->budget--) { s->failed_pc=0x0c0a2302u; return 0; }
r[5]=0x00000060u;
goto P_0c0a2304;
P_0c0a2304: /* original 4e0b, guest PC 0x0c0a2304 */
if(!s->budget--) { s->failed_pc=0x0c0a2304u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2308u;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2308u) { target=s->pc; goto dispatch; }
goto P_0c0a2308;
P_0c0a2306: /* original e40c, guest PC 0x0c0a2306 */
if(!s->budget--) { s->failed_pc=0x0c0a2306u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2308;
P_0c0a2308: /* original dd3a, guest PC 0x0c0a2308 */
if(!s->budget--) { s->failed_pc=0x0c0a2308u; return 0; }
r[13]=read(ram,0x0c0a23f4u,4);
goto P_0c0a230a;
P_0c0a230a: /* original d939, guest PC 0x0c0a230a */
if(!s->budget--) { s->failed_pc=0x0c0a230au; return 0; }
r[9]=read(ram,0x0c0a23f0u,4);
goto P_0c0a230c;
P_0c0a230c: /* original 4d0b, guest PC 0x0c0a230c */
if(!s->budget--) { s->failed_pc=0x0c0a230cu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2310u;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2310u) { target=s->pc; goto dispatch; }
goto P_0c0a2310;
P_0c0a230e: /* original 2f96, guest PC 0x0c0a230e */
if(!s->budget--) { s->failed_pc=0x0c0a230eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2310;
P_0c0a2310: /* original 9555, guest PC 0x0c0a2310 */
if(!s->budget--) { s->failed_pc=0x0c0a2310u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23beu,2);
goto P_0c0a2312;
P_0c0a2312: /* original 4e0b, guest PC 0x0c0a2312 */
if(!s->budget--) { s->failed_pc=0x0c0a2312u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2316u;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2316u) { target=s->pc; goto dispatch; }
goto P_0c0a2316;
P_0c0a2314: /* original e40c, guest PC 0x0c0a2314 */
if(!s->budget--) { s->failed_pc=0x0c0a2314u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2316;
P_0c0a2316: /* original d938, guest PC 0x0c0a2316 */
if(!s->budget--) { s->failed_pc=0x0c0a2316u; return 0; }
r[9]=read(ram,0x0c0a23f8u,4);
goto P_0c0a2318;
P_0c0a2318: /* original 4d0b, guest PC 0x0c0a2318 */
if(!s->budget--) { s->failed_pc=0x0c0a2318u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a231cu;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a231cu) { target=s->pc; goto dispatch; }
goto P_0c0a231c;
P_0c0a231a: /* original 2f96, guest PC 0x0c0a231a */
if(!s->budget--) { s->failed_pc=0x0c0a231au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a231c;
P_0c0a231c: /* original 9550, guest PC 0x0c0a231c */
if(!s->budget--) { s->failed_pc=0x0c0a231cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c0u,2);
goto P_0c0a231e;
P_0c0a231e: /* original 4e0b, guest PC 0x0c0a231e */
if(!s->budget--) { s->failed_pc=0x0c0a231eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2322u;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2322u) { target=s->pc; goto dispatch; }
goto P_0c0a2322;
P_0c0a2320: /* original e40c, guest PC 0x0c0a2320 */
if(!s->budget--) { s->failed_pc=0x0c0a2320u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2322;
P_0c0a2322: /* original d936, guest PC 0x0c0a2322 */
if(!s->budget--) { s->failed_pc=0x0c0a2322u; return 0; }
r[9]=read(ram,0x0c0a23fcu,4);
goto P_0c0a2324;
P_0c0a2324: /* original 4d0b, guest PC 0x0c0a2324 */
if(!s->budget--) { s->failed_pc=0x0c0a2324u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2328u;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2328u) { target=s->pc; goto dispatch; }
goto P_0c0a2328;
P_0c0a2326: /* original 2f96, guest PC 0x0c0a2326 */
if(!s->budget--) { s->failed_pc=0x0c0a2326u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2328;
P_0c0a2328: /* original 994b, guest PC 0x0c0a2328 */
if(!s->budget--) { s->failed_pc=0x0c0a2328u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c2u,2);
goto P_0c0a232a;
P_0c0a232a: /* original 6593, guest PC 0x0c0a232a */
if(!s->budget--) { s->failed_pc=0x0c0a232au; return 0; }
r[5]=r[9];
goto P_0c0a232c;
P_0c0a232c: /* original 4e0b, guest PC 0x0c0a232c */
if(!s->budget--) { s->failed_pc=0x0c0a232cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2330u;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2330u) { target=s->pc; goto dispatch; }
goto P_0c0a2330;
P_0c0a232e: /* original e40c, guest PC 0x0c0a232e */
if(!s->budget--) { s->failed_pc=0x0c0a232eu; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2330;
P_0c0a2330: /* original de33, guest PC 0x0c0a2330 */
if(!s->budget--) { s->failed_pc=0x0c0a2330u; return 0; }
r[14]=read(ram,0x0c0a2400u,4);
goto P_0c0a2332;
P_0c0a2332: /* original 4d0b, guest PC 0x0c0a2332 */
if(!s->budget--) { s->failed_pc=0x0c0a2332u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2336u;
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2336u) { target=s->pc; goto dispatch; }
goto P_0c0a2336;
P_0c0a2334: /* original 2fe6, guest PC 0x0c0a2334 */
if(!s->budget--) { s->failed_pc=0x0c0a2334u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2336;
P_0c0a2336: /* original de33, guest PC 0x0c0a2336 */
if(!s->budget--) { s->failed_pc=0x0c0a2336u; return 0; }
r[14]=read(ram,0x0c0a2404u,4);
goto P_0c0a2338;
P_0c0a2338: /* original 7f10, guest PC 0x0c0a2338 */
if(!s->budget--) { s->failed_pc=0x0c0a2338u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a233a;
P_0c0a233a: /* original 4e0b, guest PC 0x0c0a233a */
if(!s->budget--) { s->failed_pc=0x0c0a233au; return 0; }
target=r[14];
r[16]=code_base|0x0c0a233eu;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a233eu) { target=s->pc; goto dispatch; }
goto P_0c0a233e;
P_0c0a233c: /* original e403, guest PC 0x0c0a233c */
if(!s->budget--) { s->failed_pc=0x0c0a233cu; return 0; }
r[4]=0x00000003u;
goto P_0c0a233e;
P_0c0a233e: /* original de32, guest PC 0x0c0a233e */
if(!s->budget--) { s->failed_pc=0x0c0a233eu; return 0; }
r[14]=read(ram,0x0c0a2408u,4);
goto P_0c0a2340;
P_0c0a2340: /* original 4e0b, guest PC 0x0c0a2340 */
if(!s->budget--) { s->failed_pc=0x0c0a2340u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2344u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2344u) { target=s->pc; goto dispatch; }
goto P_0c0a2344;
P_0c0a2342: /* original 0009, guest PC 0x0c0a2342 */
if(!s->budget--) { s->failed_pc=0x0c0a2342u; return 0; }
goto P_0c0a2344;
P_0c0a2344: /* original 85c3, guest PC 0x0c0a2344 */
if(!s->budget--) { s->failed_pc=0x0c0a2344u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c0a2346;
P_0c0a2346: /* original 943d, guest PC 0x0c0a2346 */
if(!s->budget--) { s->failed_pc=0x0c0a2346u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c4u,2);
goto P_0c0a2348;
P_0c0a2348: /* original 630d, guest PC 0x0c0a2348 */
if(!s->budget--) { s->failed_pc=0x0c0a2348u; return 0; }
r[3]=r[0]&65535u;
goto P_0c0a234a;
P_0c0a234a: /* original 85a3, guest PC 0x0c0a234a */
if(!s->budget--) { s->failed_pc=0x0c0a234au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+6,2);
goto P_0c0a234c;
P_0c0a234c: /* original 600d, guest PC 0x0c0a234c */
if(!s->budget--) { s->failed_pc=0x0c0a234cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a234e;
P_0c0a234e: /* original 230b, guest PC 0x0c0a234e */
if(!s->budget--) { s->failed_pc=0x0c0a234eu; return 0; }
r[3]|=r[0];
goto P_0c0a2350;
P_0c0a2350: /* original 2348, guest PC 0x0c0a2350 */
if(!s->budget--) { s->failed_pc=0x0c0a2350u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0a2352;
P_0c0a2352: /* original 8901, guest PC 0x0c0a2352 */
if(!s->budget--) { s->failed_pc=0x0c0a2352u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2358; }
goto P_0c0a2354;
P_0c0a2354: /* original a00f, guest PC 0x0c0a2354 */
if(!s->budget--) { s->failed_pc=0x0c0a2354u; return 0; }
r[0]=0x00000001u;
goto P_0c0a2376;
P_0c0a2356: /* original e001, guest PC 0x0c0a2356 */
if(!s->budget--) { s->failed_pc=0x0c0a2356u; return 0; }
r[0]=0x00000001u;
goto P_0c0a2358;
P_0c0a2358: /* original 85c3, guest PC 0x0c0a2358 */
if(!s->budget--) { s->failed_pc=0x0c0a2358u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c0a235a;
P_0c0a235a: /* original 9434, guest PC 0x0c0a235a */
if(!s->budget--) { s->failed_pc=0x0c0a235au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c6u,2);
goto P_0c0a235c;
P_0c0a235c: /* original 630d, guest PC 0x0c0a235c */
if(!s->budget--) { s->failed_pc=0x0c0a235cu; return 0; }
r[3]=r[0]&65535u;
goto P_0c0a235e;
P_0c0a235e: /* original 85a3, guest PC 0x0c0a235e */
if(!s->budget--) { s->failed_pc=0x0c0a235eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+6,2);
goto P_0c0a2360;
P_0c0a2360: /* original 600d, guest PC 0x0c0a2360 */
if(!s->budget--) { s->failed_pc=0x0c0a2360u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2362;
P_0c0a2362: /* original 230b, guest PC 0x0c0a2362 */
if(!s->budget--) { s->failed_pc=0x0c0a2362u; return 0; }
r[3]|=r[0];
goto P_0c0a2364;
P_0c0a2364: /* original 2348, guest PC 0x0c0a2364 */
if(!s->budget--) { s->failed_pc=0x0c0a2364u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0a2366;
P_0c0a2366: /* original 8b05, guest PC 0x0c0a2366 */
if(!s->budget--) { s->failed_pc=0x0c0a2366u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2374; }
goto P_0c0a2368;
P_0c0a2368: /* original 4b0b, guest PC 0x0c0a2368 */
if(!s->budget--) { s->failed_pc=0x0c0a2368u; return 0; }
target=r[11];
r[16]=code_base|0x0c0a236cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a236cu) { target=s->pc; goto dispatch; }
goto P_0c0a236c;
P_0c0a236a: /* original e400, guest PC 0x0c0a236a */
if(!s->budget--) { s->failed_pc=0x0c0a236au; return 0; }
r[4]=0x00000000u;
goto P_0c0a236c;
P_0c0a236c: /* original bdf0, guest PC 0x0c0a236c */
if(!s->budget--) { s->failed_pc=0x0c0a236cu; return 0; }
target=code_base|0x0c0a1f50u; r[16]=code_base|0x0c0a2370u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2370u) { target=s->pc; goto dispatch; }
goto P_0c0a2370;
P_0c0a236e: /* original e401, guest PC 0x0c0a236e */
if(!s->budget--) { s->failed_pc=0x0c0a236eu; return 0; }
r[4]=0x00000001u;
goto P_0c0a2370;
P_0c0a2370: /* original 8810, guest PC 0x0c0a2370 */
if(!s->budget--) { s->failed_pc=0x0c0a2370u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0a2372;
P_0c0a2372: /* original 89b8, guest PC 0x0c0a2372 */
if(!s->budget--) { s->failed_pc=0x0c0a2372u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a22e6; }
goto P_0c0a2374;
P_0c0a2374: /* original e000, guest PC 0x0c0a2374 */
if(!s->budget--) { s->failed_pc=0x0c0a2374u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2376;
P_0c0a2376: /* original 4f26, guest PC 0x0c0a2376 */
if(!s->budget--) { s->failed_pc=0x0c0a2376u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2378;
P_0c0a2378: /* original 69f6, guest PC 0x0c0a2378 */
if(!s->budget--) { s->failed_pc=0x0c0a2378u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a237a;
P_0c0a237a: /* original 6af6, guest PC 0x0c0a237a */
if(!s->budget--) { s->failed_pc=0x0c0a237au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a237c;
P_0c0a237c: /* original 6bf6, guest PC 0x0c0a237c */
if(!s->budget--) { s->failed_pc=0x0c0a237cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a237e;
P_0c0a237e: /* original 6cf6, guest PC 0x0c0a237e */
if(!s->budget--) { s->failed_pc=0x0c0a237eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2380;
P_0c0a2380: /* original 6df6, guest PC 0x0c0a2380 */
if(!s->budget--) { s->failed_pc=0x0c0a2380u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2382;
P_0c0a2382: /* original 000b, guest PC 0x0c0a2382 */
if(!s->budget--) { s->failed_pc=0x0c0a2382u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2384: /* original 6ef6, guest PC 0x0c0a2384 */
if(!s->budget--) { s->failed_pc=0x0c0a2384u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a2386;
P_0c0a2386: /* original 2fe6, guest PC 0x0c0a2386 */
if(!s->budget--) { s->failed_pc=0x0c0a2386u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2388;
P_0c0a2388: /* original 2fd6, guest PC 0x0c0a2388 */
if(!s->budget--) { s->failed_pc=0x0c0a2388u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a238a;
P_0c0a238a: /* original 2fc6, guest PC 0x0c0a238a */
if(!s->budget--) { s->failed_pc=0x0c0a238au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a238c;
P_0c0a238c: /* original 2fb6, guest PC 0x0c0a238c */
if(!s->budget--) { s->failed_pc=0x0c0a238cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a238e;
P_0c0a238e: /* original 2fa6, guest PC 0x0c0a238e */
if(!s->budget--) { s->failed_pc=0x0c0a238eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2390;
P_0c0a2390: /* original 2f96, guest PC 0x0c0a2390 */
if(!s->budget--) { s->failed_pc=0x0c0a2390u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2392;
P_0c0a2392: /* original 2f86, guest PC 0x0c0a2392 */
if(!s->budget--) { s->failed_pc=0x0c0a2392u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2394;
P_0c0a2394: /* original 4f22, guest PC 0x0c0a2394 */
if(!s->budget--) { s->failed_pc=0x0c0a2394u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2396;
P_0c0a2396: /* original 7ff4, guest PC 0x0c0a2396 */
if(!s->budget--) { s->failed_pc=0x0c0a2396u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a2398;
P_0c0a2398: /* original 2f42, guest PC 0x0c0a2398 */
if(!s->budget--) { s->failed_pc=0x0c0a2398u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a239a;
P_0c0a239a: /* original 9a15, guest PC 0x0c0a239a */
if(!s->budget--) { s->failed_pc=0x0c0a239au; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c8u,2);
goto P_0c0a239c;
P_0c0a239c: /* original d80c, guest PC 0x0c0a239c */
if(!s->budget--) { s->failed_pc=0x0c0a239cu; return 0; }
r[8]=read(ram,0x0c0a23d0u,4);
goto P_0c0a239e;
P_0c0a239e: /* original 480b, guest PC 0x0c0a239e */
if(!s->budget--) { s->failed_pc=0x0c0a239eu; return 0; }
target=r[8];
r[16]=code_base|0x0c0a23a2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a23a2u) { target=s->pc; goto dispatch; }
goto P_0c0a23a2;
P_0c0a23a0: /* original e400, guest PC 0x0c0a23a0 */
if(!s->budget--) { s->failed_pc=0x0c0a23a0u; return 0; }
r[4]=0x00000000u;
goto P_0c0a23a2;
P_0c0a23a2: /* original d30c, guest PC 0x0c0a23a2 */
if(!s->budget--) { s->failed_pc=0x0c0a23a2u; return 0; }
r[3]=read(ram,0x0c0a23d4u,4);
goto P_0c0a23a4;
P_0c0a23a4: /* original 430b, guest PC 0x0c0a23a4 */
if(!s->budget--) { s->failed_pc=0x0c0a23a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a23a8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a23a8u) { target=s->pc; goto dispatch; }
goto P_0c0a23a8;
P_0c0a23a6: /* original 0009, guest PC 0x0c0a23a6 */
if(!s->budget--) { s->failed_pc=0x0c0a23a6u; return 0; }
goto P_0c0a23a8;
P_0c0a23a8: /* original d40b, guest PC 0x0c0a23a8 */
if(!s->budget--) { s->failed_pc=0x0c0a23a8u; return 0; }
r[4]=read(ram,0x0c0a23d8u,4);
goto P_0c0a23aa;
P_0c0a23aa: /* original 6243, guest PC 0x0c0a23aa */
if(!s->budget--) { s->failed_pc=0x0c0a23aau; return 0; }
r[2]=r[4];
goto P_0c0a23ac;
P_0c0a23ac: /* original 7410, guest PC 0x0c0a23ac */
if(!s->budget--) { s->failed_pc=0x0c0a23acu; return 0; }
r[4]+=0x00000010u;
goto P_0c0a23ae;
P_0c0a23ae: /* original 1f21, guest PC 0x0c0a23ae */
if(!s->budget--) { s->failed_pc=0x0c0a23aeu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a23b0;
P_0c0a23b0: /* original 9c0c, guest PC 0x0c0a23b0 */
if(!s->budget--) { s->failed_pc=0x0c0a23b0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23ccu,2);
goto P_0c0a23b2;
P_0c0a23b2: /* original dd0e, guest PC 0x0c0a23b2 */
if(!s->budget--) { s->failed_pc=0x0c0a23b2u; return 0; }
r[13]=read(ram,0x0c0a23ecu,4);
goto P_0c0a23b4;
P_0c0a23b4: /* original de0f, guest PC 0x0c0a23b4 */
if(!s->budget--) { s->failed_pc=0x0c0a23b4u; return 0; }
r[14]=read(ram,0x0c0a23f4u,4);
goto P_0c0a23b6;
P_0c0a23b6: /* original 9b02, guest PC 0x0c0a23b6 */
if(!s->budget--) { s->failed_pc=0x0c0a23b6u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23beu,2);
goto P_0c0a23b8;
P_0c0a23b8: /* original 9907, guest PC 0x0c0a23b8 */
if(!s->budget--) { s->failed_pc=0x0c0a23b8u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23cau,2);
goto P_0c0a23ba;
P_0c0a23ba: /* original a067, guest PC 0x0c0a23ba */
if(!s->budget--) { s->failed_pc=0x0c0a23bau; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0a248c;
P_0c0a23bc: /* original 1f42, guest PC 0x0c0a23bc */
if(!s->budget--) { s->failed_pc=0x0c0a23bcu; return 0; }
write(ram,r[15]+8,r[4],4);
if(!vf3_matrix_family(0x0c0a23beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a23beu; return 0; } return 1;
P_0c0a240c: /* original d237, guest PC 0x0c0a240c */
if(!s->budget--) { s->failed_pc=0x0c0a240cu; return 0; }
r[2]=read(ram,0x0c0a24ecu,4);
goto P_0c0a240e;
P_0c0a240e: /* original 420b, guest PC 0x0c0a240e */
if(!s->budget--) { s->failed_pc=0x0c0a240eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2412u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2412u) { target=s->pc; goto dispatch; }
goto P_0c0a2412;
P_0c0a2410: /* original e400, guest PC 0x0c0a2410 */
if(!s->budget--) { s->failed_pc=0x0c0a2410u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2412;
P_0c0a2412: /* original d337, guest PC 0x0c0a2412 */
if(!s->budget--) { s->failed_pc=0x0c0a2412u; return 0; }
r[3]=read(ram,0x0c0a24f0u,4);
goto P_0c0a2414;
P_0c0a2414: /* original 430b, guest PC 0x0c0a2414 */
if(!s->budget--) { s->failed_pc=0x0c0a2414u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2418u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2418u) { target=s->pc; goto dispatch; }
goto P_0c0a2418;
P_0c0a2416: /* original e401, guest PC 0x0c0a2416 */
if(!s->budget--) { s->failed_pc=0x0c0a2416u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2418;
P_0c0a2418: /* original d236, guest PC 0x0c0a2418 */
if(!s->budget--) { s->failed_pc=0x0c0a2418u; return 0; }
r[2]=read(ram,0x0c0a24f4u,4);
goto P_0c0a241a;
P_0c0a241a: /* original 420b, guest PC 0x0c0a241a */
if(!s->budget--) { s->failed_pc=0x0c0a241au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a241eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a241eu) { target=s->pc; goto dispatch; }
goto P_0c0a241e;
P_0c0a241c: /* original e400, guest PC 0x0c0a241c */
if(!s->budget--) { s->failed_pc=0x0c0a241cu; return 0; }
r[4]=0x00000000u;
goto P_0c0a241e;
P_0c0a241e: /* original d336, guest PC 0x0c0a241e */
if(!s->budget--) { s->failed_pc=0x0c0a241eu; return 0; }
r[3]=read(ram,0x0c0a24f8u,4);
goto P_0c0a2420;
P_0c0a2420: /* original e500, guest PC 0x0c0a2420 */
if(!s->budget--) { s->failed_pc=0x0c0a2420u; return 0; }
r[5]=0x00000000u;
goto P_0c0a2422;
P_0c0a2422: /* original 430b, guest PC 0x0c0a2422 */
if(!s->budget--) { s->failed_pc=0x0c0a2422u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2426u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2426u) { target=s->pc; goto dispatch; }
goto P_0c0a2426;
P_0c0a2424: /* original e403, guest PC 0x0c0a2424 */
if(!s->budget--) { s->failed_pc=0x0c0a2424u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2426;
P_0c0a2426: /* original e560, guest PC 0x0c0a2426 */
if(!s->budget--) { s->failed_pc=0x0c0a2426u; return 0; }
r[5]=0x00000060u;
goto P_0c0a2428;
P_0c0a2428: /* original 4d0b, guest PC 0x0c0a2428 */
if(!s->budget--) { s->failed_pc=0x0c0a2428u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a242cu;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a242cu) { target=s->pc; goto dispatch; }
goto P_0c0a242c;
P_0c0a242a: /* original e40c, guest PC 0x0c0a242a */
if(!s->budget--) { s->failed_pc=0x0c0a242au; return 0; }
r[4]=0x0000000cu;
goto P_0c0a242c;
P_0c0a242c: /* original d233, guest PC 0x0c0a242c */
if(!s->budget--) { s->failed_pc=0x0c0a242cu; return 0; }
r[2]=read(ram,0x0c0a24fcu,4);
goto P_0c0a242e;
P_0c0a242e: /* original 4e0b, guest PC 0x0c0a242e */
if(!s->budget--) { s->failed_pc=0x0c0a242eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2432u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2432u) { target=s->pc; goto dispatch; }
goto P_0c0a2432;
P_0c0a2430: /* original 2f26, guest PC 0x0c0a2430 */
if(!s->budget--) { s->failed_pc=0x0c0a2430u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2432;
P_0c0a2432: /* original 7f04, guest PC 0x0c0a2432 */
if(!s->budget--) { s->failed_pc=0x0c0a2432u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a2434;
P_0c0a2434: /* original 60f2, guest PC 0x0c0a2434 */
if(!s->budget--) { s->failed_pc=0x0c0a2434u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0a2436;
P_0c0a2436: /* original 880b, guest PC 0x0c0a2436 */
if(!s->budget--) { s->failed_pc=0x0c0a2436u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0a2438;
P_0c0a2438: /* original 8b05, guest PC 0x0c0a2438 */
if(!s->budget--) { s->failed_pc=0x0c0a2438u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2446; }
goto P_0c0a243a;
P_0c0a243a: /* original 65b3, guest PC 0x0c0a243a */
if(!s->budget--) { s->failed_pc=0x0c0a243au; return 0; }
r[5]=r[11];
goto P_0c0a243c;
P_0c0a243c: /* original 4d0b, guest PC 0x0c0a243c */
if(!s->budget--) { s->failed_pc=0x0c0a243cu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2440u;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2440u) { target=s->pc; goto dispatch; }
goto P_0c0a2440;
P_0c0a243e: /* original e40c, guest PC 0x0c0a243e */
if(!s->budget--) { s->failed_pc=0x0c0a243eu; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2440;
P_0c0a2440: /* original d22f, guest PC 0x0c0a2440 */
if(!s->budget--) { s->failed_pc=0x0c0a2440u; return 0; }
r[2]=read(ram,0x0c0a2500u,4);
goto P_0c0a2442;
P_0c0a2442: /* original a004, guest PC 0x0c0a2442 */
if(!s->budget--) { s->failed_pc=0x0c0a2442u; return 0; }
goto P_0c0a244e;
P_0c0a2444: /* original 0009, guest PC 0x0c0a2444 */
if(!s->budget--) { s->failed_pc=0x0c0a2444u; return 0; }
goto P_0c0a2446;
P_0c0a2446: /* original 65b3, guest PC 0x0c0a2446 */
if(!s->budget--) { s->failed_pc=0x0c0a2446u; return 0; }
r[5]=r[11];
goto P_0c0a2448;
P_0c0a2448: /* original 4d0b, guest PC 0x0c0a2448 */
if(!s->budget--) { s->failed_pc=0x0c0a2448u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a244cu;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a244cu) { target=s->pc; goto dispatch; }
goto P_0c0a244c;
P_0c0a244a: /* original e40c, guest PC 0x0c0a244a */
if(!s->budget--) { s->failed_pc=0x0c0a244au; return 0; }
r[4]=0x0000000cu;
goto P_0c0a244c;
P_0c0a244c: /* original d22d, guest PC 0x0c0a244c */
if(!s->budget--) { s->failed_pc=0x0c0a244cu; return 0; }
r[2]=read(ram,0x0c0a2504u,4);
goto P_0c0a244e;
P_0c0a244e: /* original 4e0b, guest PC 0x0c0a244e */
if(!s->budget--) { s->failed_pc=0x0c0a244eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2452u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2452u) { target=s->pc; goto dispatch; }
goto P_0c0a2452;
P_0c0a2450: /* original 2f26, guest PC 0x0c0a2450 */
if(!s->budget--) { s->failed_pc=0x0c0a2450u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2452;
P_0c0a2452: /* original 9349, guest PC 0x0c0a2452 */
if(!s->budget--) { s->failed_pc=0x0c0a2452u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a24e8u,2);
goto P_0c0a2454;
P_0c0a2454: /* original 3a33, guest PC 0x0c0a2454 */
if(!s->budget--) { s->failed_pc=0x0c0a2454u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a2456;
P_0c0a2456: /* original 8d07, guest PC 0x0c0a2456 */
if(!s->budget--) { s->failed_pc=0x0c0a2456u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c0a2468; }
goto P_0c0a245a;
P_0c0a2458: /* original 7f04, guest PC 0x0c0a2458 */
if(!s->budget--) { s->failed_pc=0x0c0a2458u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a245a;
P_0c0a245a: /* original 6593, guest PC 0x0c0a245a */
if(!s->budget--) { s->failed_pc=0x0c0a245au; return 0; }
r[5]=r[9];
goto P_0c0a245c;
P_0c0a245c: /* original 4d0b, guest PC 0x0c0a245c */
if(!s->budget--) { s->failed_pc=0x0c0a245cu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2460u;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2460u) { target=s->pc; goto dispatch; }
goto P_0c0a2460;
P_0c0a245e: /* original e40c, guest PC 0x0c0a245e */
if(!s->budget--) { s->failed_pc=0x0c0a245eu; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2460;
P_0c0a2460: /* original d329, guest PC 0x0c0a2460 */
if(!s->budget--) { s->failed_pc=0x0c0a2460u; return 0; }
r[3]=read(ram,0x0c0a2508u,4);
goto P_0c0a2462;
P_0c0a2462: /* original 4e0b, guest PC 0x0c0a2462 */
if(!s->budget--) { s->failed_pc=0x0c0a2462u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2466u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2466u) { target=s->pc; goto dispatch; }
goto P_0c0a2466;
P_0c0a2464: /* original 2f36, guest PC 0x0c0a2464 */
if(!s->budget--) { s->failed_pc=0x0c0a2464u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2466;
P_0c0a2466: /* original 7f04, guest PC 0x0c0a2466 */
if(!s->budget--) { s->failed_pc=0x0c0a2466u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a2468;
P_0c0a2468: /* original 52f1, guest PC 0x0c0a2468 */
if(!s->budget--) { s->failed_pc=0x0c0a2468u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0a246a;
P_0c0a246a: /* original 8523, guest PC 0x0c0a246a */
if(!s->budget--) { s->failed_pc=0x0c0a246au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+6,2);
goto P_0c0a246c;
P_0c0a246c: /* original 600d, guest PC 0x0c0a246c */
if(!s->budget--) { s->failed_pc=0x0c0a246cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a246e;
P_0c0a246e: /* original 20c8, guest PC 0x0c0a246e */
if(!s->budget--) { s->failed_pc=0x0c0a246eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[12])==0)!=0);
goto P_0c0a2470;
P_0c0a2470: /* original 8b0f, guest PC 0x0c0a2470 */
if(!s->budget--) { s->failed_pc=0x0c0a2470u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2492; }
goto P_0c0a2472;
P_0c0a2472: /* original 53f2, guest PC 0x0c0a2472 */
if(!s->budget--) { s->failed_pc=0x0c0a2472u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0a2474;
P_0c0a2474: /* original 8533, guest PC 0x0c0a2474 */
if(!s->budget--) { s->failed_pc=0x0c0a2474u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+6,2);
goto P_0c0a2476;
P_0c0a2476: /* original 600d, guest PC 0x0c0a2476 */
if(!s->budget--) { s->failed_pc=0x0c0a2476u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2478;
P_0c0a2478: /* original 20c8, guest PC 0x0c0a2478 */
if(!s->budget--) { s->failed_pc=0x0c0a2478u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[12])==0)!=0);
goto P_0c0a247a;
P_0c0a247a: /* original 8b0a, guest PC 0x0c0a247a */
if(!s->budget--) { s->failed_pc=0x0c0a247au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2492; }
goto P_0c0a247c;
P_0c0a247c: /* original d323, guest PC 0x0c0a247c */
if(!s->budget--) { s->failed_pc=0x0c0a247cu; return 0; }
r[3]=read(ram,0x0c0a250cu,4);
goto P_0c0a247e;
P_0c0a247e: /* original 430b, guest PC 0x0c0a247e */
if(!s->budget--) { s->failed_pc=0x0c0a247eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2482u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2482u) { target=s->pc; goto dispatch; }
goto P_0c0a2482;
P_0c0a2480: /* original e403, guest PC 0x0c0a2480 */
if(!s->budget--) { s->failed_pc=0x0c0a2480u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2482;
P_0c0a2482: /* original d223, guest PC 0x0c0a2482 */
if(!s->budget--) { s->failed_pc=0x0c0a2482u; return 0; }
r[2]=read(ram,0x0c0a2510u,4);
goto P_0c0a2484;
P_0c0a2484: /* original 420b, guest PC 0x0c0a2484 */
if(!s->budget--) { s->failed_pc=0x0c0a2484u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2488u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2488u) { target=s->pc; goto dispatch; }
goto P_0c0a2488;
P_0c0a2486: /* original 0009, guest PC 0x0c0a2486 */
if(!s->budget--) { s->failed_pc=0x0c0a2486u; return 0; }
goto P_0c0a2488;
P_0c0a2488: /* original 480b, guest PC 0x0c0a2488 */
if(!s->budget--) { s->failed_pc=0x0c0a2488u; return 0; }
target=r[8];
r[16]=code_base|0x0c0a248cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a248cu) { target=s->pc; goto dispatch; }
goto P_0c0a248c;
P_0c0a248a: /* original e400, guest PC 0x0c0a248a */
if(!s->budget--) { s->failed_pc=0x0c0a248au; return 0; }
r[4]=0x00000000u;
goto P_0c0a248c;
P_0c0a248c: /* original 2aa8, guest PC 0x0c0a248c */
if(!s->budget--) { s->failed_pc=0x0c0a248cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0a248e;
P_0c0a248e: /* original 8fbd, guest PC 0x0c0a248e */
if(!s->budget--) { s->failed_pc=0x0c0a248eu; return 0; }
cond=r[17]&1u;
r[10]+=0xffffffffu;
if(!cond) { goto P_0c0a240c; }
goto P_0c0a2492;
P_0c0a2490: /* original 7aff, guest PC 0x0c0a2490 */
if(!s->budget--) { s->failed_pc=0x0c0a2490u; return 0; }
r[10]+=0xffffffffu;
goto P_0c0a2492;
P_0c0a2492: /* original 7f0c, guest PC 0x0c0a2492 */
if(!s->budget--) { s->failed_pc=0x0c0a2492u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a2494;
P_0c0a2494: /* original 4f26, guest PC 0x0c0a2494 */
if(!s->budget--) { s->failed_pc=0x0c0a2494u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2496;
P_0c0a2496: /* original 68f6, guest PC 0x0c0a2496 */
if(!s->budget--) { s->failed_pc=0x0c0a2496u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2498;
P_0c0a2498: /* original 69f6, guest PC 0x0c0a2498 */
if(!s->budget--) { s->failed_pc=0x0c0a2498u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a249a;
P_0c0a249a: /* original 6af6, guest PC 0x0c0a249a */
if(!s->budget--) { s->failed_pc=0x0c0a249au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a249c;
P_0c0a249c: /* original 6bf6, guest PC 0x0c0a249c */
if(!s->budget--) { s->failed_pc=0x0c0a249cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a249e;
P_0c0a249e: /* original 6cf6, guest PC 0x0c0a249e */
if(!s->budget--) { s->failed_pc=0x0c0a249eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a24a0;
P_0c0a24a0: /* original 6df6, guest PC 0x0c0a24a0 */
if(!s->budget--) { s->failed_pc=0x0c0a24a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a24a2;
P_0c0a24a2: /* original 000b, guest PC 0x0c0a24a2 */
if(!s->budget--) { s->failed_pc=0x0c0a24a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a24a4: /* original 6ef6, guest PC 0x0c0a24a4 */
if(!s->budget--) { s->failed_pc=0x0c0a24a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a24a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a24a6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
