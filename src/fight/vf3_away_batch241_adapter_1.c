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
int vf3_away_batch241_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c1a66u: goto P_0c0c1a66;
case 0x0c0c1a68u: goto P_0c0c1a68;
case 0x0c0c1a6au: goto P_0c0c1a6a;
case 0x0c0c1a6cu: goto P_0c0c1a6c;
case 0x0c0c1a6eu: goto P_0c0c1a6e;
case 0x0c0c1a70u: goto P_0c0c1a70;
case 0x0c0c1a72u: goto P_0c0c1a72;
case 0x0c0c1a74u: goto P_0c0c1a74;
case 0x0c0c1a76u: goto P_0c0c1a76;
case 0x0c0c1a78u: goto P_0c0c1a78;
case 0x0c0c1a7au: goto P_0c0c1a7a;
case 0x0c0c1a7cu: goto P_0c0c1a7c;
case 0x0c0c1a7eu: goto P_0c0c1a7e;
case 0x0c0c1a80u: goto P_0c0c1a80;
case 0x0c0c1a82u: goto P_0c0c1a82;
case 0x0c0c1a84u: goto P_0c0c1a84;
case 0x0c0c1a86u: goto P_0c0c1a86;
case 0x0c0c1f32u: goto P_0c0c1f32;
case 0x0c0c1f34u: goto P_0c0c1f34;
case 0x0c0c1f94u: goto P_0c0c1f94;
case 0x0c0c1f96u: goto P_0c0c1f96;
case 0x0c0c2260u: goto P_0c0c2260;
case 0x0c0c2262u: goto P_0c0c2262;
case 0x0c0c2264u: goto P_0c0c2264;
case 0x0c0c2266u: goto P_0c0c2266;
case 0x0c0c2268u: goto P_0c0c2268;
case 0x0c0c226au: goto P_0c0c226a;
case 0x0c0c226cu: goto P_0c0c226c;
case 0x0c0c226eu: goto P_0c0c226e;
case 0x0c0c2270u: goto P_0c0c2270;
case 0x0c0c2272u: goto P_0c0c2272;
case 0x0c0c2274u: goto P_0c0c2274;
case 0x0c0c2276u: goto P_0c0c2276;
case 0x0c0c2278u: goto P_0c0c2278;
case 0x0c0c227au: goto P_0c0c227a;
case 0x0c0c227cu: goto P_0c0c227c;
case 0x0c0c227eu: goto P_0c0c227e;
case 0x0c0c2280u: goto P_0c0c2280;
case 0x0c0c2282u: goto P_0c0c2282;
case 0x0c0c2284u: goto P_0c0c2284;
case 0x0c0c2286u: goto P_0c0c2286;
case 0x0c0c2288u: goto P_0c0c2288;
case 0x0c0c228au: goto P_0c0c228a;
case 0x0c0c228cu: goto P_0c0c228c;
case 0x0c0c228eu: goto P_0c0c228e;
case 0x0c0c2290u: goto P_0c0c2290;
case 0x0c0c2292u: goto P_0c0c2292;
case 0x0c0c2294u: goto P_0c0c2294;
case 0x0c0c2296u: goto P_0c0c2296;
case 0x0c0c2298u: goto P_0c0c2298;
case 0x0c0c229au: goto P_0c0c229a;
case 0x0c0c229cu: goto P_0c0c229c;
case 0x0c0c229eu: goto P_0c0c229e;
case 0x0c0c22a0u: goto P_0c0c22a0;
case 0x0c0c22a2u: goto P_0c0c22a2;
case 0x0c0c22a4u: goto P_0c0c22a4;
case 0x0c0c22a6u: goto P_0c0c22a6;
case 0x0c0c22a8u: goto P_0c0c22a8;
case 0x0c0c22aau: goto P_0c0c22aa;
case 0x0c0c22acu: goto P_0c0c22ac;
case 0x0c0c22aeu: goto P_0c0c22ae;
case 0x0c0c22b0u: goto P_0c0c22b0;
case 0x0c0c22b2u: goto P_0c0c22b2;
case 0x0c0c22b4u: goto P_0c0c22b4;
case 0x0c0c22b6u: goto P_0c0c22b6;
case 0x0c0c22b8u: goto P_0c0c22b8;
case 0x0c0c22bau: goto P_0c0c22ba;
case 0x0c0c22bcu: goto P_0c0c22bc;
case 0x0c0c22beu: goto P_0c0c22be;
case 0x0c0c22c0u: goto P_0c0c22c0;
case 0x0c0c22c2u: goto P_0c0c22c2;
case 0x0c0c22c4u: goto P_0c0c22c4;
case 0x0c0c22c6u: goto P_0c0c22c6;
case 0x0c0c22c8u: goto P_0c0c22c8;
case 0x0c0c22cau: goto P_0c0c22ca;
case 0x0c0c22ccu: goto P_0c0c22cc;
case 0x0c0c22ceu: goto P_0c0c22ce;
case 0x0c0c22d0u: goto P_0c0c22d0;
case 0x0c0c22d2u: goto P_0c0c22d2;
case 0x0c0c22d4u: goto P_0c0c22d4;
case 0x0c0c22d6u: goto P_0c0c22d6;
case 0x0c0c22d8u: goto P_0c0c22d8;
case 0x0c0c22dau: goto P_0c0c22da;
case 0x0c0c22dcu: goto P_0c0c22dc;
case 0x0c0c22deu: goto P_0c0c22de;
case 0x0c0c22e0u: goto P_0c0c22e0;
case 0x0c0c22e2u: goto P_0c0c22e2;
case 0x0c0c22e4u: goto P_0c0c22e4;
case 0x0c0c22e6u: goto P_0c0c22e6;
case 0x0c0c22e8u: goto P_0c0c22e8;
case 0x0c0c22eau: goto P_0c0c22ea;
case 0x0c0c22ecu: goto P_0c0c22ec;
case 0x0c0c22eeu: goto P_0c0c22ee;
case 0x0c0c22f0u: goto P_0c0c22f0;
case 0x0c0c22f2u: goto P_0c0c22f2;
case 0x0c0c22f4u: goto P_0c0c22f4;
case 0x0c0c22f6u: goto P_0c0c22f6;
case 0x0c0c22f8u: goto P_0c0c22f8;
case 0x0c0c22fau: goto P_0c0c22fa;
case 0x0c0c22fcu: goto P_0c0c22fc;
case 0x0c0c22feu: goto P_0c0c22fe;
case 0x0c0c2300u: goto P_0c0c2300;
case 0x0c0c2302u: goto P_0c0c2302;
case 0x0c0c2304u: goto P_0c0c2304;
case 0x0c0c2306u: goto P_0c0c2306;
case 0x0c0c2308u: goto P_0c0c2308;
case 0x0c0c230au: goto P_0c0c230a;
case 0x0c0c230cu: goto P_0c0c230c;
case 0x0c0c230eu: goto P_0c0c230e;
case 0x0c0c2310u: goto P_0c0c2310;
case 0x0c0c2312u: goto P_0c0c2312;
case 0x0c0c2314u: goto P_0c0c2314;
case 0x0c0c2316u: goto P_0c0c2316;
case 0x0c0c2318u: goto P_0c0c2318;
case 0x0c0c2348u: goto P_0c0c2348;
case 0x0c0c234au: goto P_0c0c234a;
case 0x0c0c234cu: goto P_0c0c234c;
case 0x0c0c234eu: goto P_0c0c234e;
case 0x0c0c2350u: goto P_0c0c2350;
case 0x0c0c2352u: goto P_0c0c2352;
case 0x0c0c2354u: goto P_0c0c2354;
case 0x0c0c2356u: goto P_0c0c2356;
case 0x0c0c2358u: goto P_0c0c2358;
case 0x0c0c235au: goto P_0c0c235a;
case 0x0c0c235cu: goto P_0c0c235c;
case 0x0c0c235eu: goto P_0c0c235e;
case 0x0c0c2360u: goto P_0c0c2360;
case 0x0c0c2362u: goto P_0c0c2362;
case 0x0c0c2364u: goto P_0c0c2364;
case 0x0c0c2366u: goto P_0c0c2366;
case 0x0c0c2368u: goto P_0c0c2368;
case 0x0c0c236au: goto P_0c0c236a;
case 0x0c0c236cu: goto P_0c0c236c;
case 0x0c0c236eu: goto P_0c0c236e;
case 0x0c0c2370u: goto P_0c0c2370;
case 0x0c0c2372u: goto P_0c0c2372;
case 0x0c0c2374u: goto P_0c0c2374;
case 0x0c0c2376u: goto P_0c0c2376;
case 0x0c0c2378u: goto P_0c0c2378;
case 0x0c0c237au: goto P_0c0c237a;
case 0x0c0c237cu: goto P_0c0c237c;
case 0x0c0c237eu: goto P_0c0c237e;
case 0x0c0c2380u: goto P_0c0c2380;
case 0x0c0c2382u: goto P_0c0c2382;
case 0x0c0c2384u: goto P_0c0c2384;
case 0x0c0c2386u: goto P_0c0c2386;
case 0x0c0c2388u: goto P_0c0c2388;
case 0x0c0c238au: goto P_0c0c238a;
case 0x0c0c238cu: goto P_0c0c238c;
case 0x0c0c238eu: goto P_0c0c238e;
case 0x0c0c2390u: goto P_0c0c2390;
case 0x0c0c2392u: goto P_0c0c2392;
case 0x0c0c2394u: goto P_0c0c2394;
case 0x0c0c2396u: goto P_0c0c2396;
case 0x0c0c2398u: goto P_0c0c2398;
case 0x0c0c239au: goto P_0c0c239a;
case 0x0c0c239cu: goto P_0c0c239c;
case 0x0c0c239eu: goto P_0c0c239e;
case 0x0c0c23a0u: goto P_0c0c23a0;
case 0x0c0c23a2u: goto P_0c0c23a2;
case 0x0c0c23a4u: goto P_0c0c23a4;
case 0x0c0c23a6u: goto P_0c0c23a6;
case 0x0c0c23a8u: goto P_0c0c23a8;
case 0x0c0c23aau: goto P_0c0c23aa;
case 0x0c0c23acu: goto P_0c0c23ac;
case 0x0c0c23aeu: goto P_0c0c23ae;
case 0x0c0c23b0u: goto P_0c0c23b0;
case 0x0c0c23b2u: goto P_0c0c23b2;
case 0x0c0c23b4u: goto P_0c0c23b4;
case 0x0c0c23b6u: goto P_0c0c23b6;
case 0x0c0c23b8u: goto P_0c0c23b8;
case 0x0c0c23bau: goto P_0c0c23ba;
case 0x0c0c23bcu: goto P_0c0c23bc;
case 0x0c0c23beu: goto P_0c0c23be;
case 0x0c0c23c0u: goto P_0c0c23c0;
case 0x0c0c23c2u: goto P_0c0c23c2;
case 0x0c0c23c4u: goto P_0c0c23c4;
case 0x0c0c23c6u: goto P_0c0c23c6;
case 0x0c0c23c8u: goto P_0c0c23c8;
case 0x0c0c23cau: goto P_0c0c23ca;
case 0x0c0c23ccu: goto P_0c0c23cc;
case 0x0c0c23ceu: goto P_0c0c23ce;
case 0x0c0c23d0u: goto P_0c0c23d0;
case 0x0c0c23d2u: goto P_0c0c23d2;
case 0x0c0c23d4u: goto P_0c0c23d4;
case 0x0c0c23d6u: goto P_0c0c23d6;
case 0x0c0c23d8u: goto P_0c0c23d8;
case 0x0c0c23dau: goto P_0c0c23da;
case 0x0c0c23dcu: goto P_0c0c23dc;
case 0x0c0c23f4u: goto P_0c0c23f4;
case 0x0c0c23f6u: goto P_0c0c23f6;
case 0x0c0c23f8u: goto P_0c0c23f8;
case 0x0c0c23fau: goto P_0c0c23fa;
case 0x0c0c23fcu: goto P_0c0c23fc;
case 0x0c0c23feu: goto P_0c0c23fe;
case 0x0c0c2400u: goto P_0c0c2400;
case 0x0c0c2402u: goto P_0c0c2402;
case 0x0c0c2404u: goto P_0c0c2404;
case 0x0c0c2406u: goto P_0c0c2406;
case 0x0c0c2408u: goto P_0c0c2408;
case 0x0c0c240au: goto P_0c0c240a;
case 0x0c0c240cu: goto P_0c0c240c;
case 0x0c0c240eu: goto P_0c0c240e;
case 0x0c0c2410u: goto P_0c0c2410;
case 0x0c0c2412u: goto P_0c0c2412;
case 0x0c0c2414u: goto P_0c0c2414;
case 0x0c0c2416u: goto P_0c0c2416;
case 0x0c0c2418u: goto P_0c0c2418;
case 0x0c0c241au: goto P_0c0c241a;
case 0x0c0c241cu: goto P_0c0c241c;
case 0x0c0c241eu: goto P_0c0c241e;
case 0x0c0c2420u: goto P_0c0c2420;
case 0x0c0c2422u: goto P_0c0c2422;
case 0x0c0c2424u: goto P_0c0c2424;
case 0x0c0c2426u: goto P_0c0c2426;
case 0x0c0c2428u: goto P_0c0c2428;
case 0x0c0c242au: goto P_0c0c242a;
case 0x0c0c242cu: goto P_0c0c242c;
case 0x0c0c242eu: goto P_0c0c242e;
case 0x0c0c2430u: goto P_0c0c2430;
case 0x0c0c2432u: goto P_0c0c2432;
case 0x0c0c2434u: goto P_0c0c2434;
case 0x0c0c2436u: goto P_0c0c2436;
case 0x0c0c2438u: goto P_0c0c2438;
case 0x0c0c243au: goto P_0c0c243a;
case 0x0c0c243cu: goto P_0c0c243c;
case 0x0c0c243eu: goto P_0c0c243e;
case 0x0c0c2440u: goto P_0c0c2440;
case 0x0c0c2442u: goto P_0c0c2442;
case 0x0c0c2444u: goto P_0c0c2444;
case 0x0c0c2446u: goto P_0c0c2446;
case 0x0c0c2448u: goto P_0c0c2448;
case 0x0c0c244au: goto P_0c0c244a;
case 0x0c0c244cu: goto P_0c0c244c;
case 0x0c0c244eu: goto P_0c0c244e;
case 0x0c0c2450u: goto P_0c0c2450;
case 0x0c0c2452u: goto P_0c0c2452;
case 0x0c0c2454u: goto P_0c0c2454;
case 0x0c0c2456u: goto P_0c0c2456;
case 0x0c0c2458u: goto P_0c0c2458;
case 0x0c0c245au: goto P_0c0c245a;
case 0x0c0c245cu: goto P_0c0c245c;
case 0x0c0c245eu: goto P_0c0c245e;
case 0x0c0c2460u: goto P_0c0c2460;
case 0x0c0c2462u: goto P_0c0c2462;
case 0x0c0c2464u: goto P_0c0c2464;
case 0x0c0c2466u: goto P_0c0c2466;
case 0x0c0c2468u: goto P_0c0c2468;
case 0x0c0c246au: goto P_0c0c246a;
case 0x0c0c246cu: goto P_0c0c246c;
case 0x0c0c246eu: goto P_0c0c246e;
case 0x0c0c2470u: goto P_0c0c2470;
case 0x0c0c2472u: goto P_0c0c2472;
case 0x0c0c2474u: goto P_0c0c2474;
case 0x0c0c2476u: goto P_0c0c2476;
case 0x0c0c2478u: goto P_0c0c2478;
case 0x0c0c247au: goto P_0c0c247a;
case 0x0c0c247cu: goto P_0c0c247c;
case 0x0c0c247eu: goto P_0c0c247e;
case 0x0c0c2480u: goto P_0c0c2480;
case 0x0c0c2482u: goto P_0c0c2482;
case 0x0c0c2484u: goto P_0c0c2484;
case 0x0c0c2486u: goto P_0c0c2486;
case 0x0c0c2488u: goto P_0c0c2488;
case 0x0c0c248au: goto P_0c0c248a;
case 0x0c0c248cu: goto P_0c0c248c;
case 0x0c0c248eu: goto P_0c0c248e;
case 0x0c0c2490u: goto P_0c0c2490;
case 0x0c0c2492u: goto P_0c0c2492;
case 0x0c0c2494u: goto P_0c0c2494;
case 0x0c0c2496u: goto P_0c0c2496;
case 0x0c0c2498u: goto P_0c0c2498;
case 0x0c0c249au: goto P_0c0c249a;
case 0x0c0c249cu: goto P_0c0c249c;
case 0x0c0c249eu: goto P_0c0c249e;
case 0x0c0c24a0u: goto P_0c0c24a0;
case 0x0c0c24a2u: goto P_0c0c24a2;
case 0x0c0c24a4u: goto P_0c0c24a4;
case 0x0c0c24a6u: goto P_0c0c24a6;
case 0x0c0c24a8u: goto P_0c0c24a8;
case 0x0c0c24aau: goto P_0c0c24aa;
case 0x0c0c24acu: goto P_0c0c24ac;
case 0x0c0c24aeu: goto P_0c0c24ae;
case 0x0c0c24b0u: goto P_0c0c24b0;
case 0x0c0c24b2u: goto P_0c0c24b2;
case 0x0c0c24b4u: goto P_0c0c24b4;
case 0x0c0c24b6u: goto P_0c0c24b6;
case 0x0c0c24b8u: goto P_0c0c24b8;
case 0x0c0c24bau: goto P_0c0c24ba;
case 0x0c0c24bcu: goto P_0c0c24bc;
case 0x0c0c24beu: goto P_0c0c24be;
case 0x0c0c24c0u: goto P_0c0c24c0;
case 0x0c0c24c2u: goto P_0c0c24c2;
case 0x0c0c24c4u: goto P_0c0c24c4;
case 0x0c0c24c6u: goto P_0c0c24c6;
case 0x0c0c24c8u: goto P_0c0c24c8;
case 0x0c0c24cau: goto P_0c0c24ca;
case 0x0c0c24ccu: goto P_0c0c24cc;
case 0x0c0c24ceu: goto P_0c0c24ce;
case 0x0c0c24d0u: goto P_0c0c24d0;
case 0x0c0c24d2u: goto P_0c0c24d2;
case 0x0c0c24d4u: goto P_0c0c24d4;
case 0x0c0c24d6u: goto P_0c0c24d6;
case 0x0c0c24d8u: goto P_0c0c24d8;
case 0x0c0c24dau: goto P_0c0c24da;
case 0x0c0c24dcu: goto P_0c0c24dc;
case 0x0c0c24deu: goto P_0c0c24de;
case 0x0c0c24e0u: goto P_0c0c24e0;
case 0x0c0c24e2u: goto P_0c0c24e2;
case 0x0c0c24e4u: goto P_0c0c24e4;
case 0x0c0c24e6u: goto P_0c0c24e6;
case 0x0c0c24e8u: goto P_0c0c24e8;
case 0x0c0c24eau: goto P_0c0c24ea;
case 0x0c0c24ecu: goto P_0c0c24ec;
case 0x0c0c24eeu: goto P_0c0c24ee;
case 0x0c0c24f0u: goto P_0c0c24f0;
case 0x0c0c24f2u: goto P_0c0c24f2;
case 0x0c0c24f4u: goto P_0c0c24f4;
case 0x0c0c24f6u: goto P_0c0c24f6;
case 0x0c0c24f8u: goto P_0c0c24f8;
case 0x0c0c24fau: goto P_0c0c24fa;
case 0x0c0c24fcu: goto P_0c0c24fc;
case 0x0c0c24feu: goto P_0c0c24fe;
case 0x0c0c2500u: goto P_0c0c2500;
case 0x0c0c2502u: goto P_0c0c2502;
case 0x0c0c2504u: goto P_0c0c2504;
case 0x0c0c2506u: goto P_0c0c2506;
case 0x0c0c2508u: goto P_0c0c2508;
case 0x0c0c250au: goto P_0c0c250a;
case 0x0c0c250cu: goto P_0c0c250c;
case 0x0c0c250eu: goto P_0c0c250e;
case 0x0c0c2510u: goto P_0c0c2510;
case 0x0c0c2512u: goto P_0c0c2512;
case 0x0c0c2514u: goto P_0c0c2514;
case 0x0c0c2516u: goto P_0c0c2516;
case 0x0c0c2518u: goto P_0c0c2518;
case 0x0c0c251au: goto P_0c0c251a;
case 0x0c0c251cu: goto P_0c0c251c;
case 0x0c0c251eu: goto P_0c0c251e;
case 0x0c0c2520u: goto P_0c0c2520;
case 0x0c0c2522u: goto P_0c0c2522;
case 0x0c0c2524u: goto P_0c0c2524;
case 0x0c0c2554u: goto P_0c0c2554;
case 0x0c0c2556u: goto P_0c0c2556;
case 0x0c0c2558u: goto P_0c0c2558;
case 0x0c0c255au: goto P_0c0c255a;
case 0x0c0c255cu: goto P_0c0c255c;
case 0x0c0c255eu: goto P_0c0c255e;
case 0x0c0c2560u: goto P_0c0c2560;
case 0x0c0c2562u: goto P_0c0c2562;
case 0x0c0c2564u: goto P_0c0c2564;
case 0x0c0c2566u: goto P_0c0c2566;
case 0x0c0c2568u: goto P_0c0c2568;
case 0x0c0c256au: goto P_0c0c256a;
case 0x0c0c256cu: goto P_0c0c256c;
case 0x0c0c256eu: goto P_0c0c256e;
case 0x0c0c2570u: goto P_0c0c2570;
case 0x0c0c2572u: goto P_0c0c2572;
case 0x0c0c2574u: goto P_0c0c2574;
case 0x0c0c2576u: goto P_0c0c2576;
case 0x0c0c2578u: goto P_0c0c2578;
case 0x0c0c257au: goto P_0c0c257a;
case 0x0c0c257cu: goto P_0c0c257c;
case 0x0c0c257eu: goto P_0c0c257e;
case 0x0c0c2580u: goto P_0c0c2580;
case 0x0c0c2582u: goto P_0c0c2582;
case 0x0c0c2584u: goto P_0c0c2584;
case 0x0c0c2586u: goto P_0c0c2586;
case 0x0c0c2588u: goto P_0c0c2588;
case 0x0c0c258au: goto P_0c0c258a;
case 0x0c0c258cu: goto P_0c0c258c;
case 0x0c0c258eu: goto P_0c0c258e;
case 0x0c0c2590u: goto P_0c0c2590;
case 0x0c0c2592u: goto P_0c0c2592;
case 0x0c0c2594u: goto P_0c0c2594;
case 0x0c0c2596u: goto P_0c0c2596;
case 0x0c0c2598u: goto P_0c0c2598;
case 0x0c0c259au: goto P_0c0c259a;
case 0x0c0c259cu: goto P_0c0c259c;
case 0x0c0c259eu: goto P_0c0c259e;
case 0x0c0c25a0u: goto P_0c0c25a0;
case 0x0c0c25a2u: goto P_0c0c25a2;
case 0x0c0c25a4u: goto P_0c0c25a4;
case 0x0c0c25a6u: goto P_0c0c25a6;
case 0x0c0c25a8u: goto P_0c0c25a8;
case 0x0c0c25aau: goto P_0c0c25aa;
case 0x0c0c25acu: goto P_0c0c25ac;
case 0x0c0c25aeu: goto P_0c0c25ae;
case 0x0c0c25b0u: goto P_0c0c25b0;
case 0x0c0c25b2u: goto P_0c0c25b2;
case 0x0c0c25b4u: goto P_0c0c25b4;
case 0x0c0c25b6u: goto P_0c0c25b6;
case 0x0c0c25b8u: goto P_0c0c25b8;
case 0x0c0c25bau: goto P_0c0c25ba;
case 0x0c0c25bcu: goto P_0c0c25bc;
case 0x0c0c25beu: goto P_0c0c25be;
case 0x0c0c25c0u: goto P_0c0c25c0;
case 0x0c0c25c2u: goto P_0c0c25c2;
case 0x0c0c25c4u: goto P_0c0c25c4;
case 0x0c0c25c6u: goto P_0c0c25c6;
case 0x0c0c25c8u: goto P_0c0c25c8;
case 0x0c0c25cau: goto P_0c0c25ca;
case 0x0c0c25ccu: goto P_0c0c25cc;
case 0x0c0c25ceu: goto P_0c0c25ce;
case 0x0c0c25d0u: goto P_0c0c25d0;
case 0x0c0c25d2u: goto P_0c0c25d2;
case 0x0c0c25d4u: goto P_0c0c25d4;
case 0x0c0c25d6u: goto P_0c0c25d6;
case 0x0c0c25d8u: goto P_0c0c25d8;
case 0x0c0c25dau: goto P_0c0c25da;
case 0x0c0c25dcu: goto P_0c0c25dc;
case 0x0c0c25deu: goto P_0c0c25de;
case 0x0c0c25e0u: goto P_0c0c25e0;
case 0x0c0c25e2u: goto P_0c0c25e2;
case 0x0c0c25e4u: goto P_0c0c25e4;
case 0x0c0c25e6u: goto P_0c0c25e6;
case 0x0c0c25e8u: goto P_0c0c25e8;
case 0x0c0c25eau: goto P_0c0c25ea;
case 0x0c0c25ecu: goto P_0c0c25ec;
case 0x0c0c25eeu: goto P_0c0c25ee;
case 0x0c0c25f0u: goto P_0c0c25f0;
case 0x0c0c25f2u: goto P_0c0c25f2;
case 0x0c0c25f4u: goto P_0c0c25f4;
case 0x0c0c25f6u: goto P_0c0c25f6;
case 0x0c0c25f8u: goto P_0c0c25f8;
case 0x0c0c25fau: goto P_0c0c25fa;
case 0x0c0c25fcu: goto P_0c0c25fc;
case 0x0c0c25feu: goto P_0c0c25fe;
case 0x0c0c2600u: goto P_0c0c2600;
case 0x0c0c2602u: goto P_0c0c2602;
case 0x0c0c2604u: goto P_0c0c2604;
case 0x0c0c2606u: goto P_0c0c2606;
case 0x0c0c2608u: goto P_0c0c2608;
case 0x0c0c260au: goto P_0c0c260a;
case 0x0c0c260cu: goto P_0c0c260c;
case 0x0c0c260eu: goto P_0c0c260e;
case 0x0c0c2610u: goto P_0c0c2610;
case 0x0c0c2612u: goto P_0c0c2612;
case 0x0c0c2614u: goto P_0c0c2614;
case 0x0c0c2616u: goto P_0c0c2616;
case 0x0c0c2618u: goto P_0c0c2618;
case 0x0c0c261au: goto P_0c0c261a;
case 0x0c0c261cu: goto P_0c0c261c;
case 0x0c0c261eu: goto P_0c0c261e;
case 0x0c0c2620u: goto P_0c0c2620;
case 0x0c0c2622u: goto P_0c0c2622;
case 0x0c0c2624u: goto P_0c0c2624;
case 0x0c0c2626u: goto P_0c0c2626;
case 0x0c0c2628u: goto P_0c0c2628;
case 0x0c0c262au: goto P_0c0c262a;
case 0x0c0c262cu: goto P_0c0c262c;
case 0x0c0c262eu: goto P_0c0c262e;
case 0x0c0c2630u: goto P_0c0c2630;
case 0x0c0c2632u: goto P_0c0c2632;
case 0x0c0c2634u: goto P_0c0c2634;
case 0x0c0c2636u: goto P_0c0c2636;
case 0x0c0c2638u: goto P_0c0c2638;
case 0x0c0c263au: goto P_0c0c263a;
case 0x0c0c263cu: goto P_0c0c263c;
case 0x0c0c263eu: goto P_0c0c263e;
case 0x0c0c2640u: goto P_0c0c2640;
case 0x0c0c2642u: goto P_0c0c2642;
case 0x0c0c2644u: goto P_0c0c2644;
case 0x0c0c2646u: goto P_0c0c2646;
case 0x0c0c2648u: goto P_0c0c2648;
case 0x0c0c264au: goto P_0c0c264a;
case 0x0c0c264cu: goto P_0c0c264c;
case 0x0c0c264eu: goto P_0c0c264e;
case 0x0c0c2650u: goto P_0c0c2650;
case 0x0c0c2652u: goto P_0c0c2652;
case 0x0c0c2654u: goto P_0c0c2654;
case 0x0c0c2656u: goto P_0c0c2656;
case 0x0c0c2658u: goto P_0c0c2658;
case 0x0c0c265au: goto P_0c0c265a;
case 0x0c0c265cu: goto P_0c0c265c;
case 0x0c0c265eu: goto P_0c0c265e;
case 0x0c0c2660u: goto P_0c0c2660;
case 0x0c0c2662u: goto P_0c0c2662;
case 0x0c0c2664u: goto P_0c0c2664;
case 0x0c0c2666u: goto P_0c0c2666;
case 0x0c0c2668u: goto P_0c0c2668;
case 0x0c0c266au: goto P_0c0c266a;
case 0x0c0c266cu: goto P_0c0c266c;
case 0x0c0c266eu: goto P_0c0c266e;
case 0x0c0c2670u: goto P_0c0c2670;
case 0x0c0c2672u: goto P_0c0c2672;
case 0x0c0c2674u: goto P_0c0c2674;
case 0x0c0c2676u: goto P_0c0c2676;
case 0x0c0c2678u: goto P_0c0c2678;
case 0x0c0c267au: goto P_0c0c267a;
case 0x0c0c267cu: goto P_0c0c267c;
case 0x0c0c267eu: goto P_0c0c267e;
case 0x0c0c2680u: goto P_0c0c2680;
case 0x0c0c2682u: goto P_0c0c2682;
case 0x0c0c2684u: goto P_0c0c2684;
case 0x0c0c2686u: goto P_0c0c2686;
case 0x0c0c2688u: goto P_0c0c2688;
case 0x0c0c268au: goto P_0c0c268a;
case 0x0c0c268cu: goto P_0c0c268c;
case 0x0c0c268eu: goto P_0c0c268e;
case 0x0c0c2690u: goto P_0c0c2690;
case 0x0c0c2692u: goto P_0c0c2692;
case 0x0c0c2694u: goto P_0c0c2694;
case 0x0c0c2696u: goto P_0c0c2696;
case 0x0c0c2698u: goto P_0c0c2698;
case 0x0c0c269au: goto P_0c0c269a;
case 0x0c0c269cu: goto P_0c0c269c;
case 0x0c0c269eu: goto P_0c0c269e;
case 0x0c0c26a0u: goto P_0c0c26a0;
case 0x0c0c26a2u: goto P_0c0c26a2;
case 0x0c0c26a4u: goto P_0c0c26a4;
case 0x0c0c26a6u: goto P_0c0c26a6;
case 0x0c0c26a8u: goto P_0c0c26a8;
case 0x0c0c26aau: goto P_0c0c26aa;
case 0x0c0c26acu: goto P_0c0c26ac;
case 0x0c0c26aeu: goto P_0c0c26ae;
case 0x0c0c26b0u: goto P_0c0c26b0;
case 0x0c0c26b2u: goto P_0c0c26b2;
case 0x0c0c26b4u: goto P_0c0c26b4;
case 0x0c0c26b6u: goto P_0c0c26b6;
case 0x0c0c26b8u: goto P_0c0c26b8;
case 0x0c0c26bau: goto P_0c0c26ba;
case 0x0c0c26bcu: goto P_0c0c26bc;
case 0x0c0c26beu: goto P_0c0c26be;
case 0x0c0c26c0u: goto P_0c0c26c0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c1a66: /* original 4f22, guest PC 0x0c0c1a66 */
if(!s->budget--) { s->failed_pc=0x0c0c1a66u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1a68;
P_0c0c1a68: /* original 7ff8, guest PC 0x0c0c1a68 */
if(!s->budget--) { s->failed_pc=0x0c0c1a68u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c1a6a;
P_0c0c1a6a: /* original 2f62, guest PC 0x0c0c1a6a */
if(!s->budget--) { s->failed_pc=0x0c0c1a6au; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0c1a6c;
P_0c0c1a6c: /* original 1f71, guest PC 0x0c0c1a6c */
if(!s->budget--) { s->failed_pc=0x0c0c1a6cu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0c1a6e;
P_0c0c1a6e: /* original 53f4, guest PC 0x0c0c1a6e */
if(!s->budget--) { s->failed_pc=0x0c0c1a6eu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0c1a70;
P_0c0c1a70: /* original 2f36, guest PC 0x0c0c1a70 */
if(!s->budget--) { s->failed_pc=0x0c0c1a70u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1a72;
P_0c0c1a72: /* original 52f4, guest PC 0x0c0c1a72 */
if(!s->budget--) { s->failed_pc=0x0c0c1a72u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0c1a74;
P_0c0c1a74: /* original 2f26, guest PC 0x0c0c1a74 */
if(!s->budget--) { s->failed_pc=0x0c0c1a74u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1a76;
P_0c0c1a76: /* original 53f3, guest PC 0x0c0c1a76 */
if(!s->budget--) { s->failed_pc=0x0c0c1a76u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c1a78;
P_0c0c1a78: /* original 2f36, guest PC 0x0c0c1a78 */
if(!s->budget--) { s->failed_pc=0x0c0c1a78u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1a7a;
P_0c0c1a7a: /* original 9608, guest PC 0x0c0c1a7a */
if(!s->budget--) { s->failed_pc=0x0c0c1a7au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1a8eu,2);
goto P_0c0c1a7c;
P_0c0c1a7c: /* original bbe7, guest PC 0x0c0c1a7c */
if(!s->budget--) { s->failed_pc=0x0c0c1a7cu; return 0; }
target=code_base|0x0c0c124eu; r[16]=code_base|0x0c0c1a80u;
r[7]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1a80u) { target=s->pc; goto dispatch; }
goto P_0c0c1a80;
P_0c0c1a7e: /* original 57f3, guest PC 0x0c0c1a7e */
if(!s->budget--) { s->failed_pc=0x0c0c1a7eu; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c0c1a80;
P_0c0c1a80: /* original 7f14, guest PC 0x0c0c1a80 */
if(!s->budget--) { s->failed_pc=0x0c0c1a80u; return 0; }
r[15]+=0x00000014u;
goto P_0c0c1a82;
P_0c0c1a82: /* original 4f26, guest PC 0x0c0c1a82 */
if(!s->budget--) { s->failed_pc=0x0c0c1a82u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1a84;
P_0c0c1a84: /* original 000b, guest PC 0x0c0c1a84 */
if(!s->budget--) { s->failed_pc=0x0c0c1a84u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1a86: /* original 0009, guest PC 0x0c0c1a86 */
if(!s->budget--) { s->failed_pc=0x0c0c1a86u; return 0; }
if(!vf3_matrix_family(0x0c0c1a88u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1a88u; return 0; } return 1;
P_0c0c1f32: /* original 000b, guest PC 0x0c0c1f32 */
if(!s->budget--) { s->failed_pc=0x0c0c1f32u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1f34: /* original 0009, guest PC 0x0c0c1f34 */
if(!s->budget--) { s->failed_pc=0x0c0c1f34u; return 0; }
if(!vf3_matrix_family(0x0c0c1f36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1f36u; return 0; } return 1;
P_0c0c1f94: /* original 000b, guest PC 0x0c0c1f94 */
if(!s->budget--) { s->failed_pc=0x0c0c1f94u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1f96: /* original 0009, guest PC 0x0c0c1f96 */
if(!s->budget--) { s->failed_pc=0x0c0c1f96u; return 0; }
if(!vf3_matrix_family(0x0c0c1f98u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1f98u; return 0; } return 1;
P_0c0c2260: /* original 2fe6, guest PC 0x0c0c2260 */
if(!s->budget--) { s->failed_pc=0x0c0c2260u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2262;
P_0c0c2262: /* original e026, guest PC 0x0c0c2262 */
if(!s->budget--) { s->failed_pc=0x0c0c2262u; return 0; }
r[0]=0x00000026u;
goto P_0c0c2264;
P_0c0c2264: /* original 2fd6, guest PC 0x0c0c2264 */
if(!s->budget--) { s->failed_pc=0x0c0c2264u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2266;
P_0c0c2266: /* original 2fc6, guest PC 0x0c0c2266 */
if(!s->budget--) { s->failed_pc=0x0c0c2266u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2268;
P_0c0c2268: /* original 2fb6, guest PC 0x0c0c2268 */
if(!s->budget--) { s->failed_pc=0x0c0c2268u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c226a;
P_0c0c226a: /* original 2fa6, guest PC 0x0c0c226a */
if(!s->budget--) { s->failed_pc=0x0c0c226au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c226c;
P_0c0c226c: /* original 2f96, guest PC 0x0c0c226c */
if(!s->budget--) { s->failed_pc=0x0c0c226cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c226e;
P_0c0c226e: /* original 2f86, guest PC 0x0c0c226e */
if(!s->budget--) { s->failed_pc=0x0c0c226eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2270;
P_0c0c2270: /* original fffb, guest PC 0x0c0c2270 */
if(!s->budget--) { s->failed_pc=0x0c0c2270u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c2272;
P_0c0c2272: /* original ffeb, guest PC 0x0c0c2272 */
if(!s->budget--) { s->failed_pc=0x0c0c2272u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c2274;
P_0c0c2274: /* original ffdb, guest PC 0x0c0c2274 */
if(!s->budget--) { s->failed_pc=0x0c0c2274u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c2276;
P_0c0c2276: /* original ffcb, guest PC 0x0c0c2276 */
if(!s->budget--) { s->failed_pc=0x0c0c2276u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0c2278;
P_0c0c2278: /* original 4f22, guest PC 0x0c0c2278 */
if(!s->budget--) { s->failed_pc=0x0c0c2278u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c227a;
P_0c0c227a: /* original 4f12, guest PC 0x0c0c227a */
if(!s->budget--) { s->failed_pc=0x0c0c227au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c227c;
P_0c0c227c: /* original 7fb4, guest PC 0x0c0c227c */
if(!s->budget--) { s->failed_pc=0x0c0c227cu; return 0; }
r[15]+=0xffffffb4u;
goto P_0c0c227e;
P_0c0c227e: /* original 2f52, guest PC 0x0c0c227e */
if(!s->budget--) { s->failed_pc=0x0c0c227eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c2280;
P_0c0c2280: /* original 1f62, guest PC 0x0c0c2280 */
if(!s->budget--) { s->failed_pc=0x0c0c2280u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0c2282;
P_0c0c2282: /* original 1f77, guest PC 0x0c0c2282 */
if(!s->budget--) { s->failed_pc=0x0c0c2282u; return 0; }
write(ram,r[15]+28,r[7],4);
goto P_0c0c2284;
P_0c0c2284: /* original d528, guest PC 0x0c0c2284 */
if(!s->budget--) { s->failed_pc=0x0c0c2284u; return 0; }
r[5]=read(ram,0x0c0c2328u,4);
goto P_0c0c2286;
P_0c0c2286: /* original 6453, guest PC 0x0c0c2286 */
if(!s->budget--) { s->failed_pc=0x0c0c2286u; return 0; }
r[4]=r[5];
goto P_0c0c2288;
P_0c0c2288: /* original 034d, guest PC 0x0c0c2288 */
if(!s->budget--) { s->failed_pc=0x0c0c2288u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c228a;
P_0c0c228a: /* original d028, guest PC 0x0c0c228a */
if(!s->budget--) { s->failed_pc=0x0c0c228au; return 0; }
r[0]=read(ram,0x0c0c232cu,4);
goto P_0c0c228c;
P_0c0c228c: /* original 633d, guest PC 0x0c0c228c */
if(!s->budget--) { s->failed_pc=0x0c0c228cu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c228e;
P_0c0c228e: /* original 4308, guest PC 0x0c0c228e */
if(!s->budget--) { s->failed_pc=0x0c0c228eu; return 0; }
r[3]<<=2;
goto P_0c0c2290;
P_0c0c2290: /* original f336, guest PC 0x0c0c2290 */
if(!s->budget--) { s->failed_pc=0x0c0c2290u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0c2292;
P_0c0c2292: /* original e004, guest PC 0x0c0c2292 */
if(!s->budget--) { s->failed_pc=0x0c0c2292u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2294;
P_0c0c2294: /* original ff37, guest PC 0x0c0c2294 */
if(!s->budget--) { s->failed_pc=0x0c0c2294u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2296;
P_0c0c2296: /* original d426, guest PC 0x0c0c2296 */
if(!s->budget--) { s->failed_pc=0x0c0c2296u; return 0; }
r[4]=read(ram,0x0c0c2330u,4);
goto P_0c0c2298;
P_0c0c2298: /* original 8448, guest PC 0x0c0c2298 */
if(!s->budget--) { s->failed_pc=0x0c0c2298u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0c229a;
P_0c0c229a: /* original 660c, guest PC 0x0c0c229a */
if(!s->budget--) { s->failed_pc=0x0c0c229au; return 0; }
r[6]=r[0]&255u;
goto P_0c0c229c;
P_0c0c229c: /* original 8449, guest PC 0x0c0c229c */
if(!s->budget--) { s->failed_pc=0x0c0c229cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c0c229e;
P_0c0c229e: /* original 640c, guest PC 0x0c0c229e */
if(!s->budget--) { s->failed_pc=0x0c0c229eu; return 0; }
r[4]=r[0]&255u;
goto P_0c0c22a0;
P_0c0c22a0: /* original 6063, guest PC 0x0c0c22a0 */
if(!s->budget--) { s->failed_pc=0x0c0c22a0u; return 0; }
r[0]=r[6];
goto P_0c0c22a2;
P_0c0c22a2: /* original 8807, guest PC 0x0c0c22a2 */
if(!s->budget--) { s->failed_pc=0x0c0c22a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c22a4;
P_0c0c22a4: /* original 8b27, guest PC 0x0c0c22a4 */
if(!s->budget--) { s->failed_pc=0x0c0c22a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c22f6; }
goto P_0c0c22a6;
P_0c0c22a6: /* original 6043, guest PC 0x0c0c22a6 */
if(!s->budget--) { s->failed_pc=0x0c0c22a6u; return 0; }
r[0]=r[4];
goto P_0c0c22a8;
P_0c0c22a8: /* original 880b, guest PC 0x0c0c22a8 */
if(!s->budget--) { s->failed_pc=0x0c0c22a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0c22aa;
P_0c0c22aa: /* original 8902, guest PC 0x0c0c22aa */
if(!s->budget--) { s->failed_pc=0x0c0c22aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c22b2; }
goto P_0c0c22ac;
P_0c0c22ac: /* original 6043, guest PC 0x0c0c22ac */
if(!s->budget--) { s->failed_pc=0x0c0c22acu; return 0; }
r[0]=r[4];
goto P_0c0c22ae;
P_0c0c22ae: /* original 880f, guest PC 0x0c0c22ae */
if(!s->budget--) { s->failed_pc=0x0c0c22aeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0c22b0;
P_0c0c22b0: /* original 8b21, guest PC 0x0c0c22b0 */
if(!s->budget--) { s->failed_pc=0x0c0c22b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c22f6; }
goto P_0c0c22b2;
P_0c0c22b2: /* original d220, guest PC 0x0c0c22b2 */
if(!s->budget--) { s->failed_pc=0x0c0c22b2u; return 0; }
r[2]=read(ram,0x0c0c2334u,4);
goto P_0c0c22b4;
P_0c0c22b4: /* original e31b, guest PC 0x0c0c22b4 */
if(!s->budget--) { s->failed_pc=0x0c0c22b4u; return 0; }
r[3]=0x0000001bu;
goto P_0c0c22b6;
P_0c0c22b6: /* original d120, guest PC 0x0c0c22b6 */
if(!s->budget--) { s->failed_pc=0x0c0c22b6u; return 0; }
r[1]=read(ram,0x0c0c2338u,4);
goto P_0c0c22b8;
P_0c0c22b8: /* original 6422, guest PC 0x0c0c22b8 */
if(!s->budget--) { s->failed_pc=0x0c0c22b8u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c22ba;
P_0c0c22ba: /* original e207, guest PC 0x0c0c22ba */
if(!s->budget--) { s->failed_pc=0x0c0c22bau; return 0; }
r[2]=0x00000007u;
goto P_0c0c22bc;
P_0c0c22bc: /* original 6643, guest PC 0x0c0c22bc */
if(!s->budget--) { s->failed_pc=0x0c0c22bcu; return 0; }
r[6]=r[4];
goto P_0c0c22be;
P_0c0c22be: /* original 463c, guest PC 0x0c0c22be */
if(!s->budget--) { s->failed_pc=0x0c0c22beu; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c0c22c0;
P_0c0c22c0: /* original 2619, guest PC 0x0c0c22c0 */
if(!s->budget--) { s->failed_pc=0x0c0c22c0u; return 0; }
r[6]&=r[1];
goto P_0c0c22c2;
P_0c0c22c2: /* original 4421, guest PC 0x0c0c22c2 */
if(!s->budget--) { s->failed_pc=0x0c0c22c2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0c22c4;
P_0c0c22c4: /* original 2668, guest PC 0x0c0c22c4 */
if(!s->budget--) { s->failed_pc=0x0c0c22c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c22c6;
P_0c0c22c6: /* original 8d03, guest PC 0x0c0c22c6 */
if(!s->budget--) { s->failed_pc=0x0c0c22c6u; return 0; }
cond=r[17]&1u;
r[4]&=r[2];
if(cond) { goto P_0c0c22d0; }
goto P_0c0c22ca;
P_0c0c22c8: /* original 2429, guest PC 0x0c0c22c8 */
if(!s->budget--) { s->failed_pc=0x0c0c22c8u; return 0; }
r[4]&=r[2];
goto P_0c0c22ca;
P_0c0c22ca: /* original 6023, guest PC 0x0c0c22ca */
if(!s->budget--) { s->failed_pc=0x0c0c22cau; return 0; }
r[0]=r[2];
goto P_0c0c22cc;
P_0c0c22cc: /* original 3048, guest PC 0x0c0c22cc */
if(!s->budget--) { s->failed_pc=0x0c0c22ccu; return 0; }
r[0]-=r[4];
goto P_0c0c22ce;
P_0c0c22ce: /* original 6403, guest PC 0x0c0c22ce */
if(!s->budget--) { s->failed_pc=0x0c0c22ceu; return 0; }
r[4]=r[0];
goto P_0c0c22d0;
P_0c0c22d0: /* original 6743, guest PC 0x0c0c22d0 */
if(!s->budget--) { s->failed_pc=0x0c0c22d0u; return 0; }
r[7]=r[4];
goto P_0c0c22d2;
P_0c0c22d2: /* original 4708, guest PC 0x0c0c22d2 */
if(!s->budget--) { s->failed_pc=0x0c0c22d2u; return 0; }
r[7]<<=2;
goto P_0c0c22d4;
P_0c0c22d4: /* original 9222, guest PC 0x0c0c22d4 */
if(!s->budget--) { s->failed_pc=0x0c0c22d4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c231cu,2);
goto P_0c0c22d6;
P_0c0c22d6: /* original 4708, guest PC 0x0c0c22d6 */
if(!s->budget--) { s->failed_pc=0x0c0c22d6u; return 0; }
r[7]<<=2;
goto P_0c0c22d8;
P_0c0c22d8: /* original 931f, guest PC 0x0c0c22d8 */
if(!s->budget--) { s->failed_pc=0x0c0c22d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c231au,2);
goto P_0c0c22da;
P_0c0c22da: /* original 6643, guest PC 0x0c0c22da */
if(!s->budget--) { s->failed_pc=0x0c0c22dau; return 0; }
r[6]=r[4];
goto P_0c0c22dc;
P_0c0c22dc: /* original 7618, guest PC 0x0c0c22dc */
if(!s->budget--) { s->failed_pc=0x0c0c22dcu; return 0; }
r[6]+=0x00000018u;
goto P_0c0c22de;
P_0c0c22de: /* original 911f, guest PC 0x0c0c22de */
if(!s->budget--) { s->failed_pc=0x0c0c22deu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2320u,2);
goto P_0c0c22e0;
P_0c0c22e0: /* original 4700, guest PC 0x0c0c22e0 */
if(!s->budget--) { s->failed_pc=0x0c0c22e0u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c22e2;
P_0c0c22e2: /* original 2629, guest PC 0x0c0c22e2 */
if(!s->budget--) { s->failed_pc=0x0c0c22e2u; return 0; }
r[6]&=r[2];
goto P_0c0c22e4;
P_0c0c22e4: /* original 2739, guest PC 0x0c0c22e4 */
if(!s->budget--) { s->failed_pc=0x0c0c22e4u; return 0; }
r[7]&=r[3];
goto P_0c0c22e6;
P_0c0c22e6: /* original 276b, guest PC 0x0c0c22e6 */
if(!s->budget--) { s->failed_pc=0x0c0c22e6u; return 0; }
r[7]|=r[6];
goto P_0c0c22e8;
P_0c0c22e8: /* original 9619, guest PC 0x0c0c22e8 */
if(!s->budget--) { s->failed_pc=0x0c0c22e8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c231eu,2);
goto P_0c0c22ea;
P_0c0c22ea: /* original 4418, guest PC 0x0c0c22ea */
if(!s->budget--) { s->failed_pc=0x0c0c22eau; return 0; }
r[4]<<=8;
goto P_0c0c22ec;
P_0c0c22ec: /* original 4408, guest PC 0x0c0c22ec */
if(!s->budget--) { s->failed_pc=0x0c0c22ecu; return 0; }
r[4]<<=2;
goto P_0c0c22ee;
P_0c0c22ee: /* original 2719, guest PC 0x0c0c22ee */
if(!s->budget--) { s->failed_pc=0x0c0c22eeu; return 0; }
r[7]&=r[1];
goto P_0c0c22f0;
P_0c0c22f0: /* original 2649, guest PC 0x0c0c22f0 */
if(!s->budget--) { s->failed_pc=0x0c0c22f0u; return 0; }
r[6]&=r[4];
goto P_0c0c22f2;
P_0c0c22f2: /* original a001, guest PC 0x0c0c22f2 */
if(!s->budget--) { s->failed_pc=0x0c0c22f2u; return 0; }
r[6]|=r[7];
goto P_0c0c22f8;
P_0c0c22f4: /* original 267b, guest PC 0x0c0c22f4 */
if(!s->budget--) { s->failed_pc=0x0c0c22f4u; return 0; }
r[6]|=r[7];
goto P_0c0c22f6;
P_0c0c22f6: /* original e61d, guest PC 0x0c0c22f6 */
if(!s->budget--) { s->failed_pc=0x0c0c22f6u; return 0; }
r[6]=0x0000001du;
goto P_0c0c22f8;
P_0c0c22f8: /* original 9013, guest PC 0x0c0c22f8 */
if(!s->budget--) { s->failed_pc=0x0c0c22f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2322u,2);
goto P_0c0c22fa;
P_0c0c22fa: /* original 05f6, guest PC 0x0c0c22fa */
if(!s->budget--) { s->failed_pc=0x0c0c22fau; return 0; }
write(ram,r[5]+r[0],r[15],4);
goto P_0c0c22fc;
P_0c0c22fc: /* original 7004, guest PC 0x0c0c22fc */
if(!s->budget--) { s->failed_pc=0x0c0c22fcu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c22fe;
P_0c0c22fe: /* original 0566, guest PC 0x0c0c22fe */
if(!s->budget--) { s->failed_pc=0x0c0c22feu; return 0; }
write(ram,r[5]+r[0],r[6],4);
goto P_0c0c2300;
P_0c0c2300: /* original c70f, guest PC 0x0c0c2300 */
if(!s->budget--) { s->failed_pc=0x0c0c2300u; return 0; }
r[0]=code_base|0x000c2340u;
goto P_0c0c2302;
P_0c0c2302: /* original 53f2, guest PC 0x0c0c2302 */
if(!s->budget--) { s->failed_pc=0x0c0c2302u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c2304;
P_0c0c2304: /* original fc08, guest PC 0x0c0c2304 */
if(!s->budget--) { s->failed_pc=0x0c0c2304u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c0c2306;
P_0c0c2306: /* original d40d, guest PC 0x0c0c2306 */
if(!s->budget--) { s->failed_pc=0x0c0c2306u; return 0; }
r[4]=read(ram,0x0c0c233cu,4);
goto P_0c0c2308;
P_0c0c2308: /* original 2338, guest PC 0x0c0c2308 */
if(!s->budget--) { s->failed_pc=0x0c0c2308u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c230a;
P_0c0c230a: /* original 8b1d, guest PC 0x0c0c230a */
if(!s->budget--) { s->failed_pc=0x0c0c230au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2348; }
goto P_0c0c230c;
P_0c0c230c: /* original c70d, guest PC 0x0c0c230c */
if(!s->budget--) { s->failed_pc=0x0c0c230cu; return 0; }
r[0]=code_base|0x000c2344u;
goto P_0c0c230e;
P_0c0c230e: /* original 5544, guest PC 0x0c0c230e */
if(!s->budget--) { s->failed_pc=0x0c0c230eu; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c0c2310;
P_0c0c2310: /* original 9408, guest PC 0x0c0c2310 */
if(!s->budget--) { s->failed_pc=0x0c0c2310u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2324u,2);
goto P_0c0c2312;
P_0c0c2312: /* original f308, guest PC 0x0c0c2312 */
if(!s->budget--) { s->failed_pc=0x0c0c2312u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c2314;
P_0c0c2314: /* original e018, guest PC 0x0c0c2314 */
if(!s->budget--) { s->failed_pc=0x0c0c2314u; return 0; }
r[0]=0x00000018u;
goto P_0c0c2316;
P_0c0c2316: /* original a01b, guest PC 0x0c0c2316 */
if(!s->budget--) { s->failed_pc=0x0c0c2316u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2350;
P_0c0c2318: /* original ff37, guest PC 0x0c0c2318 */
if(!s->budget--) { s->failed_pc=0x0c0c2318u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!vf3_matrix_family(0x0c0c231au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c231au; return 0; } return 1;
P_0c0c2348: /* original 5545, guest PC 0x0c0c2348 */
if(!s->budget--) { s->failed_pc=0x0c0c2348u; return 0; }
r[5]=read(ram,r[4]+20,4);
goto P_0c0c234a;
P_0c0c234a: /* original e018, guest PC 0x0c0c234a */
if(!s->budget--) { s->failed_pc=0x0c0c234au; return 0; }
r[0]=0x00000018u;
goto P_0c0c234c;
P_0c0c234c: /* original ffc7, guest PC 0x0c0c234c */
if(!s->budget--) { s->failed_pc=0x0c0c234cu; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0c234e;
P_0c0c234e: /* original 9446, guest PC 0x0c0c234e */
if(!s->budget--) { s->failed_pc=0x0c0c234eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c23deu,2);
goto P_0c0c2350;
P_0c0c2350: /* original 9046, guest PC 0x0c0c2350 */
if(!s->budget--) { s->failed_pc=0x0c0c2350u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c23e0u,2);
goto P_0c0c2352;
P_0c0c2352: /* original d224, guest PC 0x0c0c2352 */
if(!s->budget--) { s->failed_pc=0x0c0c2352u; return 0; }
r[2]=read(ram,0x0c0c23e4u,4);
goto P_0c0c2354;
P_0c0c2354: /* original 095d, guest PC 0x0c0c2354 */
if(!s->budget--) { s->failed_pc=0x0c0c2354u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0c2356;
P_0c0c2356: /* original 9044, guest PC 0x0c0c2356 */
if(!s->budget--) { s->failed_pc=0x0c0c2356u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c23e2u,2);
goto P_0c0c2358;
P_0c0c2358: /* original 035d, guest PC 0x0c0c2358 */
if(!s->budget--) { s->failed_pc=0x0c0c2358u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0c235a;
P_0c0c235a: /* original 420b, guest PC 0x0c0c235a */
if(!s->budget--) { s->failed_pc=0x0c0c235au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c235eu;
write(ram,r[15]+60,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c235eu) { target=s->pc; goto dispatch; }
goto P_0c0c235e;
P_0c0c235c: /* original 1f3f, guest PC 0x0c0c235c */
if(!s->budget--) { s->failed_pc=0x0c0c235cu; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c0c235e;
P_0c0c235e: /* original 6e03, guest PC 0x0c0c235e */
if(!s->budget--) { s->failed_pc=0x0c0c235eu; return 0; }
r[14]=r[0];
goto P_0c0c2360;
P_0c0c2360: /* original f3e8, guest PC 0x0c0c2360 */
if(!s->budget--) { s->failed_pc=0x0c0c2360u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0c2362;
P_0c0c2362: /* original e010, guest PC 0x0c0c2362 */
if(!s->budget--) { s->failed_pc=0x0c0c2362u; return 0; }
r[0]=0x00000010u;
goto P_0c0c2364;
P_0c0c2364: /* original ff37, guest PC 0x0c0c2364 */
if(!s->budget--) { s->failed_pc=0x0c0c2364u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2366;
P_0c0c2366: /* original e004, guest PC 0x0c0c2366 */
if(!s->budget--) { s->failed_pc=0x0c0c2366u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2368;
P_0c0c2368: /* original f3e6, guest PC 0x0c0c2368 */
if(!s->budget--) { s->failed_pc=0x0c0c2368u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c236a;
P_0c0c236a: /* original e00c, guest PC 0x0c0c236a */
if(!s->budget--) { s->failed_pc=0x0c0c236au; return 0; }
r[0]=0x0000000cu;
goto P_0c0c236c;
P_0c0c236c: /* original ff37, guest PC 0x0c0c236c */
if(!s->budget--) { s->failed_pc=0x0c0c236cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c236e;
P_0c0c236e: /* original e010, guest PC 0x0c0c236e */
if(!s->budget--) { s->failed_pc=0x0c0c236eu; return 0; }
r[0]=0x00000010u;
goto P_0c0c2370;
P_0c0c2370: /* original fee6, guest PC 0x0c0c2370 */
if(!s->budget--) { s->failed_pc=0x0c0c2370u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0c2372;
P_0c0c2372: /* original e014, guest PC 0x0c0c2372 */
if(!s->budget--) { s->failed_pc=0x0c0c2372u; return 0; }
r[0]=0x00000014u;
goto P_0c0c2374;
P_0c0c2374: /* original f3e6, guest PC 0x0c0c2374 */
if(!s->budget--) { s->failed_pc=0x0c0c2374u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c2376;
P_0c0c2376: /* original e014, guest PC 0x0c0c2376 */
if(!s->budget--) { s->failed_pc=0x0c0c2376u; return 0; }
r[0]=0x00000014u;
goto P_0c0c2378;
P_0c0c2378: /* original ff37, guest PC 0x0c0c2378 */
if(!s->budget--) { s->failed_pc=0x0c0c2378u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c237a;
P_0c0c237a: /* original d31b, guest PC 0x0c0c237a */
if(!s->budget--) { s->failed_pc=0x0c0c237au; return 0; }
r[3]=read(ram,0x0c0c23e8u,4);
goto P_0c0c237c;
P_0c0c237c: /* original 430b, guest PC 0x0c0c237c */
if(!s->budget--) { s->failed_pc=0x0c0c237cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2380u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2380u) { target=s->pc; goto dispatch; }
goto P_0c0c2380;
P_0c0c237e: /* original 54e8, guest PC 0x0c0c237e */
if(!s->budget--) { s->failed_pc=0x0c0c237eu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c0c2380;
P_0c0c2380: /* original e43f, guest PC 0x0c0c2380 */
if(!s->budget--) { s->failed_pc=0x0c0c2380u; return 0; }
r[4]=0x0000003fu;
goto P_0c0c2382;
P_0c0c2382: /* original 61f3, guest PC 0x0c0c2382 */
if(!s->budget--) { s->failed_pc=0x0c0c2382u; return 0; }
r[1]=r[15];
goto P_0c0c2384;
P_0c0c2384: /* original 7148, guest PC 0x0c0c2384 */
if(!s->budget--) { s->failed_pc=0x0c0c2384u; return 0; }
r[1]+=0x00000048u;
goto P_0c0c2386;
P_0c0c2386: /* original 2101, guest PC 0x0c0c2386 */
if(!s->budget--) { s->failed_pc=0x0c0c2386u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0c2388;
P_0c0c2388: /* original e1f9, guest PC 0x0c0c2388 */
if(!s->budget--) { s->failed_pc=0x0c0c2388u; return 0; }
r[1]=0xfffffff9u;
goto P_0c0c238a;
P_0c0c238a: /* original 63f2, guest PC 0x0c0c238a */
if(!s->budget--) { s->failed_pc=0x0c0c238au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c238c;
P_0c0c238c: /* original e034, guest PC 0x0c0c238c */
if(!s->budget--) { s->failed_pc=0x0c0c238cu; return 0; }
r[0]=0x00000034u;
goto P_0c0c238e;
P_0c0c238e: /* original 52f7, guest PC 0x0c0c238e */
if(!s->budget--) { s->failed_pc=0x0c0c238eu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c0c2390;
P_0c0c2390: /* original ec00, guest PC 0x0c0c2390 */
if(!s->budget--) { s->failed_pc=0x0c0c2390u; return 0; }
r[12]=0x00000000u;
goto P_0c0c2392;
P_0c0c2392: /* original 4321, guest PC 0x0c0c2392 */
if(!s->budget--) { s->failed_pc=0x0c0c2392u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c2394;
P_0c0c2394: /* original 6dc3, guest PC 0x0c0c2394 */
if(!s->budget--) { s->failed_pc=0x0c0c2394u; return 0; }
r[13]=r[12];
goto P_0c0c2396;
P_0c0c2396: /* original 2349, guest PC 0x0c0c2396 */
if(!s->budget--) { s->failed_pc=0x0c0c2396u; return 0; }
r[3]&=r[4];
goto P_0c0c2398;
P_0c0c2398: /* original 332c, guest PC 0x0c0c2398 */
if(!s->budget--) { s->failed_pc=0x0c0c2398u; return 0; }
r[3]+=r[2];
goto P_0c0c239a;
P_0c0c239a: /* original 73ff, guest PC 0x0c0c239a */
if(!s->budget--) { s->failed_pc=0x0c0c239au; return 0; }
r[3]+=0xffffffffu;
goto P_0c0c239c;
P_0c0c239c: /* original 4308, guest PC 0x0c0c239c */
if(!s->budget--) { s->failed_pc=0x0c0c239cu; return 0; }
r[3]<<=2;
goto P_0c0c239e;
P_0c0c239e: /* original 4300, guest PC 0x0c0c239e */
if(!s->budget--) { s->failed_pc=0x0c0c239eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c23a0;
P_0c0c23a0: /* original 435a, guest PC 0x0c0c23a0 */
if(!s->budget--) { s->failed_pc=0x0c0c23a0u; return 0; }
r[53]=r[3];
goto P_0c0c23a2;
P_0c0c23a2: /* original 63f2, guest PC 0x0c0c23a2 */
if(!s->budget--) { s->failed_pc=0x0c0c23a2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c23a4;
P_0c0c23a4: /* original 431c, guest PC 0x0c0c23a4 */
if(!s->budget--) { s->failed_pc=0x0c0c23a4u; return 0; }
r[3]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[3]>>((-r[1])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[1]&31u);
goto P_0c0c23a6;
P_0c0c23a6: /* original f32d, guest PC 0x0c0c23a6 */
if(!s->budget--) { s->failed_pc=0x0c0c23a6u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c23a8;
P_0c0c23a8: /* original 2349, guest PC 0x0c0c23a8 */
if(!s->budget--) { s->failed_pc=0x0c0c23a8u; return 0; }
r[3]&=r[4];
goto P_0c0c23aa;
P_0c0c23aa: /* original 4308, guest PC 0x0c0c23aa */
if(!s->budget--) { s->failed_pc=0x0c0c23aau; return 0; }
r[3]<<=2;
goto P_0c0c23ac;
P_0c0c23ac: /* original 4300, guest PC 0x0c0c23ac */
if(!s->budget--) { s->failed_pc=0x0c0c23acu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c23ae;
P_0c0c23ae: /* original 435a, guest PC 0x0c0c23ae */
if(!s->budget--) { s->failed_pc=0x0c0c23aeu; return 0; }
r[53]=r[3];
goto P_0c0c23b0;
P_0c0c23b0: /* original ff3c, guest PC 0x0c0c23b0 */
if(!s->budget--) { s->failed_pc=0x0c0c23b0u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0c23b2;
P_0c0c23b2: /* original f32d, guest PC 0x0c0c23b2 */
if(!s->budget--) { s->failed_pc=0x0c0c23b2u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c23b4;
P_0c0c23b4: /* original ff37, guest PC 0x0c0c23b4 */
if(!s->budget--) { s->failed_pc=0x0c0c23b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c23b6;
P_0c0c23b6: /* original c70d, guest PC 0x0c0c23b6 */
if(!s->budget--) { s->failed_pc=0x0c0c23b6u; return 0; }
r[0]=code_base|0x000c23ecu;
goto P_0c0c23b8;
P_0c0c23b8: /* original f208, guest PC 0x0c0c23b8 */
if(!s->budget--) { s->failed_pc=0x0c0c23b8u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c23ba;
P_0c0c23ba: /* original e028, guest PC 0x0c0c23ba */
if(!s->budget--) { s->failed_pc=0x0c0c23bau; return 0; }
r[0]=0x00000028u;
goto P_0c0c23bc;
P_0c0c23bc: /* original fdcc, guest PC 0x0c0c23bc */
if(!s->budget--) { s->failed_pc=0x0c0c23bcu; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c0c23be;
P_0c0c23be: /* original ff27, guest PC 0x0c0c23be */
if(!s->budget--) { s->failed_pc=0x0c0c23beu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c23c0;
P_0c0c23c0: /* original c70b, guest PC 0x0c0c23c0 */
if(!s->budget--) { s->failed_pc=0x0c0c23c0u; return 0; }
r[0]=code_base|0x000c23f0u;
goto P_0c0c23c2;
P_0c0c23c2: /* original 6423, guest PC 0x0c0c23c2 */
if(!s->budget--) { s->failed_pc=0x0c0c23c2u; return 0; }
r[4]=r[2];
goto P_0c0c23c4;
P_0c0c23c4: /* original f208, guest PC 0x0c0c23c4 */
if(!s->budget--) { s->failed_pc=0x0c0c23c4u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c23c6;
P_0c0c23c6: /* original e010, guest PC 0x0c0c23c6 */
if(!s->budget--) { s->failed_pc=0x0c0c23c6u; return 0; }
r[0]=0x00000010u;
goto P_0c0c23c8;
P_0c0c23c8: /* original f1f6, guest PC 0x0c0c23c8 */
if(!s->budget--) { s->failed_pc=0x0c0c23c8u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c23ca;
P_0c0c23ca: /* original e044, guest PC 0x0c0c23ca */
if(!s->budget--) { s->failed_pc=0x0c0c23cau; return 0; }
r[0]=0x00000044u;
goto P_0c0c23cc;
P_0c0c23cc: /* original f120, guest PC 0x0c0c23cc */
if(!s->budget--) { s->failed_pc=0x0c0c23ccu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c0c23ce;
P_0c0c23ce: /* original ff17, guest PC 0x0c0c23ce */
if(!s->budget--) { s->failed_pc=0x0c0c23ceu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c23d0;
P_0c0c23d0: /* original 53f2, guest PC 0x0c0c23d0 */
if(!s->budget--) { s->failed_pc=0x0c0c23d0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c23d2;
P_0c0c23d2: /* original 2338, guest PC 0x0c0c23d2 */
if(!s->budget--) { s->failed_pc=0x0c0c23d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c23d4;
P_0c0c23d4: /* original 8f0e, guest PC 0x0c0c23d4 */
if(!s->budget--) { s->failed_pc=0x0c0c23d4u; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(!cond) { goto P_0c0c23f4; }
goto P_0c0c23d8;
P_0c0c23d6: /* original 74ff, guest PC 0x0c0c23d6 */
if(!s->budget--) { s->failed_pc=0x0c0c23d6u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c23d8;
P_0c0c23d8: /* original e040, guest PC 0x0c0c23d8 */
if(!s->budget--) { s->failed_pc=0x0c0c23d8u; return 0; }
r[0]=0x00000040u;
goto P_0c0c23da;
P_0c0c23da: /* original a013, guest PC 0x0c0c23da */
if(!s->budget--) { s->failed_pc=0x0c0c23dau; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c2404;
P_0c0c23dc: /* original ff17, guest PC 0x0c0c23dc */
if(!s->budget--) { s->failed_pc=0x0c0c23dcu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
if(!vf3_matrix_family(0x0c0c23deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c23deu; return 0; } return 1;
P_0c0c23f4: /* original 445a, guest PC 0x0c0c23f4 */
if(!s->budget--) { s->failed_pc=0x0c0c23f4u; return 0; }
r[53]=r[4];
goto P_0c0c23f6;
P_0c0c23f6: /* original e010, guest PC 0x0c0c23f6 */
if(!s->budget--) { s->failed_pc=0x0c0c23f6u; return 0; }
r[0]=0x00000010u;
goto P_0c0c23f8;
P_0c0c23f8: /* original f0f6, guest PC 0x0c0c23f8 */
if(!s->budget--) { s->failed_pc=0x0c0c23f8u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0c23fa;
P_0c0c23fa: /* original e040, guest PC 0x0c0c23fa */
if(!s->budget--) { s->failed_pc=0x0c0c23fau; return 0; }
r[0]=0x00000040u;
goto P_0c0c23fc;
P_0c0c23fc: /* original f32d, guest PC 0x0c0c23fc */
if(!s->budget--) { s->failed_pc=0x0c0c23fcu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c23fe;
P_0c0c23fe: /* original ff07, guest PC 0x0c0c23fe */
if(!s->budget--) { s->failed_pc=0x0c0c23feu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0c2400;
P_0c0c2400: /* original f3c2, guest PC 0x0c0c2400 */
if(!s->budget--) { s->failed_pc=0x0c0c2400u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0c2402;
P_0c0c2402: /* original ff31, guest PC 0x0c0c2402 */
if(!s->budget--) { s->failed_pc=0x0c0c2402u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c0c2404;
P_0c0c2404: /* original e030, guest PC 0x0c0c2404 */
if(!s->budget--) { s->failed_pc=0x0c0c2404u; return 0; }
r[0]=0x00000030u;
goto P_0c0c2406;
P_0c0c2406: /* original 938e, guest PC 0x0c0c2406 */
if(!s->budget--) { s->failed_pc=0x0c0c2406u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2526u,2);
goto P_0c0c2408;
P_0c0c2408: /* original 5ef2, guest PC 0x0c0c2408 */
if(!s->budget--) { s->failed_pc=0x0c0c2408u; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c0c240a;
P_0c0c240a: /* original 6a43, guest PC 0x0c0c240a */
if(!s->budget--) { s->failed_pc=0x0c0c240au; return 0; }
r[10]=r[4];
goto P_0c0c240c;
P_0c0c240c: /* original e100, guest PC 0x0c0c240c */
if(!s->budget--) { s->failed_pc=0x0c0c240cu; return 0; }
r[1]=0x00000000u;
goto P_0c0c240e;
P_0c0c240e: /* original 2e3f, guest PC 0x0c0c240e */
if(!s->budget--) { s->failed_pc=0x0c0c240eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c0c2410;
P_0c0c2410: /* original 0e1a, guest PC 0x0c0c2410 */
if(!s->budget--) { s->failed_pc=0x0c0c2410u; return 0; }
r[14]=r[19];
goto P_0c0c2412;
P_0c0c2412: /* original 6eef, guest PC 0x0c0c2412 */
if(!s->budget--) { s->failed_pc=0x0c0c2412u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c2414;
P_0c0c2414: /* original 1fe7, guest PC 0x0c0c2414 */
if(!s->budget--) { s->failed_pc=0x0c0c2414u; return 0; }
write(ram,r[15]+28,r[14],4);
goto P_0c0c2416;
P_0c0c2416: /* original d244, guest PC 0x0c0c2416 */
if(!s->budget--) { s->failed_pc=0x0c0c2416u; return 0; }
r[2]=read(ram,0x0c0c2528u,4);
goto P_0c0c2418;
P_0c0c2418: /* original 3e2c, guest PC 0x0c0c2418 */
if(!s->budget--) { s->failed_pc=0x0c0c2418u; return 0; }
r[14]+=r[2];
goto P_0c0c241a;
P_0c0c241a: /* original 64e3, guest PC 0x0c0c241a */
if(!s->budget--) { s->failed_pc=0x0c0c241au; return 0; }
r[4]=r[14];
goto P_0c0c241c;
P_0c0c241c: /* original 2e12, guest PC 0x0c0c241c */
if(!s->budget--) { s->failed_pc=0x0c0c241cu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0c241e;
P_0c0c241e: /* original f3dc, guest PC 0x0c0c241e */
if(!s->budget--) { s->failed_pc=0x0c0c241eu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0c2420;
P_0c0c2420: /* original f3e2, guest PC 0x0c0c2420 */
if(!s->budget--) { s->failed_pc=0x0c0c2420u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c0c2422;
P_0c0c2422: /* original ff37, guest PC 0x0c0c2422 */
if(!s->budget--) { s->failed_pc=0x0c0c2422u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2424;
P_0c0c2424: /* original e014, guest PC 0x0c0c2424 */
if(!s->budget--) { s->failed_pc=0x0c0c2424u; return 0; }
r[0]=0x00000014u;
goto P_0c0c2426;
P_0c0c2426: /* original f2f6, guest PC 0x0c0c2426 */
if(!s->budget--) { s->failed_pc=0x0c0c2426u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c2428;
P_0c0c2428: /* original e028, guest PC 0x0c0c2428 */
if(!s->budget--) { s->failed_pc=0x0c0c2428u; return 0; }
r[0]=0x00000028u;
goto P_0c0c242a;
P_0c0c242a: /* original f1f6, guest PC 0x0c0c242a */
if(!s->budget--) { s->failed_pc=0x0c0c242au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c242c;
P_0c0c242c: /* original e02c, guest PC 0x0c0c242c */
if(!s->budget--) { s->failed_pc=0x0c0c242cu; return 0; }
r[0]=0x0000002cu;
goto P_0c0c242e;
P_0c0c242e: /* original f122, guest PC 0x0c0c242e */
if(!s->budget--) { s->failed_pc=0x0c0c242eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0c2430;
P_0c0c2430: /* original ff17, guest PC 0x0c0c2430 */
if(!s->budget--) { s->failed_pc=0x0c0c2430u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c2432;
P_0c0c2432: /* original e004, guest PC 0x0c0c2432 */
if(!s->budget--) { s->failed_pc=0x0c0c2432u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2434;
P_0c0c2434: /* original f8f6, guest PC 0x0c0c2434 */
if(!s->budget--) { s->failed_pc=0x0c0c2434u; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c2436;
P_0c0c2436: /* original e030, guest PC 0x0c0c2436 */
if(!s->budget--) { s->failed_pc=0x0c0c2436u; return 0; }
r[0]=0x00000030u;
goto P_0c0c2438;
P_0c0c2438: /* original f6f6, guest PC 0x0c0c2438 */
if(!s->budget--) { s->failed_pc=0x0c0c2438u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c243a;
P_0c0c243a: /* original e034, guest PC 0x0c0c243a */
if(!s->budget--) { s->failed_pc=0x0c0c243au; return 0; }
r[0]=0x00000034u;
goto P_0c0c243c;
P_0c0c243c: /* original f5f6, guest PC 0x0c0c243c */
if(!s->budget--) { s->failed_pc=0x0c0c243cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c243e;
P_0c0c243e: /* original d83b, guest PC 0x0c0c243e */
if(!s->budget--) { s->failed_pc=0x0c0c243eu; return 0; }
r[8]=read(ram,0x0c0c252cu,4);
goto P_0c0c2440;
P_0c0c2440: /* original f4fc, guest PC 0x0c0c2440 */
if(!s->budget--) { s->failed_pc=0x0c0c2440u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c2442;
P_0c0c2442: /* original f71c, guest PC 0x0c0c2442 */
if(!s->budget--) { s->failed_pc=0x0c0c2442u; return 0; }
vf3_matrix_move(s,7,1);
goto P_0c0c2444;
P_0c0c2444: /* original 480b, guest PC 0x0c0c2444 */
if(!s->budget--) { s->failed_pc=0x0c0c2444u; return 0; }
target=r[8];
r[16]=code_base|0x0c0c2448u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2448u) { target=s->pc; goto dispatch; }
goto P_0c0c2448;
P_0c0c2446: /* original 7404, guest PC 0x0c0c2446 */
if(!s->budget--) { s->failed_pc=0x0c0c2446u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c2448;
P_0c0c2448: /* original e014, guest PC 0x0c0c2448 */
if(!s->budget--) { s->failed_pc=0x0c0c2448u; return 0; }
r[0]=0x00000014u;
goto P_0c0c244a;
P_0c0c244a: /* original d339, guest PC 0x0c0c244a */
if(!s->budget--) { s->failed_pc=0x0c0c244au; return 0; }
r[3]=read(ram,0x0c0c2530u,4);
goto P_0c0c244c;
P_0c0c244c: /* original f9f6, guest PC 0x0c0c244c */
if(!s->budget--) { s->failed_pc=0x0c0c244cu; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c0c244e;
P_0c0c244e: /* original e028, guest PC 0x0c0c244e */
if(!s->budget--) { s->failed_pc=0x0c0c244eu; return 0; }
r[0]=0x00000028u;
goto P_0c0c2450;
P_0c0c2450: /* original f7f6, guest PC 0x0c0c2450 */
if(!s->budget--) { s->failed_pc=0x0c0c2450u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0c2452;
P_0c0c2452: /* original e00c, guest PC 0x0c0c2452 */
if(!s->budget--) { s->failed_pc=0x0c0c2452u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c2454;
P_0c0c2454: /* original f5f6, guest PC 0x0c0c2454 */
if(!s->budget--) { s->failed_pc=0x0c0c2454u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c2456;
P_0c0c2456: /* original e040, guest PC 0x0c0c2456 */
if(!s->budget--) { s->failed_pc=0x0c0c2456u; return 0; }
r[0]=0x00000040u;
goto P_0c0c2458;
P_0c0c2458: /* original f4f6, guest PC 0x0c0c2458 */
if(!s->budget--) { s->failed_pc=0x0c0c2458u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c245a;
P_0c0c245a: /* original 64e3, guest PC 0x0c0c245a */
if(!s->budget--) { s->failed_pc=0x0c0c245au; return 0; }
r[4]=r[14];
goto P_0c0c245c;
P_0c0c245c: /* original f8ec, guest PC 0x0c0c245c */
if(!s->budget--) { s->failed_pc=0x0c0c245cu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c0c245e;
P_0c0c245e: /* original f6dc, guest PC 0x0c0c245e */
if(!s->budget--) { s->failed_pc=0x0c0c245eu; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0c2460;
P_0c0c2460: /* original 430b, guest PC 0x0c0c2460 */
if(!s->budget--) { s->failed_pc=0x0c0c2460u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2464u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2464u) { target=s->pc; goto dispatch; }
goto P_0c0c2464;
P_0c0c2462: /* original 7404, guest PC 0x0c0c2462 */
if(!s->budget--) { s->failed_pc=0x0c0c2462u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c2464;
P_0c0c2464: /* original c733, guest PC 0x0c0c2464 */
if(!s->budget--) { s->failed_pc=0x0c0c2464u; return 0; }
r[0]=code_base|0x000c2534u;
goto P_0c0c2466;
P_0c0c2466: /* original f308, guest PC 0x0c0c2466 */
if(!s->budget--) { s->failed_pc=0x0c0c2466u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c2468;
P_0c0c2468: /* original e040, guest PC 0x0c0c2468 */
if(!s->budget--) { s->failed_pc=0x0c0c2468u; return 0; }
r[0]=0x00000040u;
goto P_0c0c246a;
P_0c0c246a: /* original f2f6, guest PC 0x0c0c246a */
if(!s->budget--) { s->failed_pc=0x0c0c246au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c246c;
P_0c0c246c: /* original e01c, guest PC 0x0c0c246c */
if(!s->budget--) { s->failed_pc=0x0c0c246cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c246e;
P_0c0c246e: /* original f230, guest PC 0x0c0c246e */
if(!s->budget--) { s->failed_pc=0x0c0c246eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c2470;
P_0c0c2470: /* original f2e2, guest PC 0x0c0c2470 */
if(!s->budget--) { s->failed_pc=0x0c0c2470u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c0c2472;
P_0c0c2472: /* original fe27, guest PC 0x0c0c2472 */
if(!s->budget--) { s->failed_pc=0x0c0c2472u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c2474;
P_0c0c2474: /* original e014, guest PC 0x0c0c2474 */
if(!s->budget--) { s->failed_pc=0x0c0c2474u; return 0; }
r[0]=0x00000014u;
goto P_0c0c2476;
P_0c0c2476: /* original f2f6, guest PC 0x0c0c2476 */
if(!s->budget--) { s->failed_pc=0x0c0c2476u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c2478;
P_0c0c2478: /* original e00c, guest PC 0x0c0c2478 */
if(!s->budget--) { s->failed_pc=0x0c0c2478u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c247a;
P_0c0c247a: /* original f1f6, guest PC 0x0c0c247a */
if(!s->budget--) { s->failed_pc=0x0c0c247au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c247c;
P_0c0c247c: /* original e020, guest PC 0x0c0c247c */
if(!s->budget--) { s->failed_pc=0x0c0c247cu; return 0; }
r[0]=0x00000020u;
goto P_0c0c247e;
P_0c0c247e: /* original f122, guest PC 0x0c0c247e */
if(!s->budget--) { s->failed_pc=0x0c0c247eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0c2480;
P_0c0c2480: /* original ff17, guest PC 0x0c0c2480 */
if(!s->budget--) { s->failed_pc=0x0c0c2480u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c2482;
P_0c0c2482: /* original e020, guest PC 0x0c0c2482 */
if(!s->budget--) { s->failed_pc=0x0c0c2482u; return 0; }
r[0]=0x00000020u;
goto P_0c0c2484;
P_0c0c2484: /* original fe17, guest PC 0x0c0c2484 */
if(!s->budget--) { s->failed_pc=0x0c0c2484u; return 0; }
vf3_matrix_store(s,ram,1,r[14]+r[0]);
goto P_0c0c2486;
P_0c0c2486: /* original e040, guest PC 0x0c0c2486 */
if(!s->budget--) { s->failed_pc=0x0c0c2486u; return 0; }
r[0]=0x00000040u;
goto P_0c0c2488;
P_0c0c2488: /* original f3f6, guest PC 0x0c0c2488 */
if(!s->budget--) { s->failed_pc=0x0c0c2488u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c248a;
P_0c0c248a: /* original c72b, guest PC 0x0c0c248a */
if(!s->budget--) { s->failed_pc=0x0c0c248au; return 0; }
r[0]=code_base|0x000c2538u;
goto P_0c0c248c;
P_0c0c248c: /* original f208, guest PC 0x0c0c248c */
if(!s->budget--) { s->failed_pc=0x0c0c248cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c248e;
P_0c0c248e: /* original e024, guest PC 0x0c0c248e */
if(!s->budget--) { s->failed_pc=0x0c0c248eu; return 0; }
r[0]=0x00000024u;
goto P_0c0c2490;
P_0c0c2490: /* original f3d0, guest PC 0x0c0c2490 */
if(!s->budget--) { s->failed_pc=0x0c0c2490u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'+');
goto P_0c0c2492;
P_0c0c2492: /* original f320, guest PC 0x0c0c2492 */
if(!s->budget--) { s->failed_pc=0x0c0c2492u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c2494;
P_0c0c2494: /* original f3e2, guest PC 0x0c0c2494 */
if(!s->budget--) { s->failed_pc=0x0c0c2494u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c0c2496;
P_0c0c2496: /* original fe37, guest PC 0x0c0c2496 */
if(!s->budget--) { s->failed_pc=0x0c0c2496u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c2498;
P_0c0c2498: /* original e028, guest PC 0x0c0c2498 */
if(!s->budget--) { s->failed_pc=0x0c0c2498u; return 0; }
r[0]=0x00000028u;
goto P_0c0c249a;
P_0c0c249a: /* original f3f6, guest PC 0x0c0c249a */
if(!s->budget--) { s->failed_pc=0x0c0c249au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c249c;
P_0c0c249c: /* original e00c, guest PC 0x0c0c249c */
if(!s->budget--) { s->failed_pc=0x0c0c249cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c249e;
P_0c0c249e: /* original f1f6, guest PC 0x0c0c249e */
if(!s->budget--) { s->failed_pc=0x0c0c249eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c24a0;
P_0c0c24a0: /* original c726, guest PC 0x0c0c24a0 */
if(!s->budget--) { s->failed_pc=0x0c0c24a0u; return 0; }
r[0]=code_base|0x000c253cu;
goto P_0c0c24a2;
P_0c0c24a2: /* original f130, guest PC 0x0c0c24a2 */
if(!s->budget--) { s->failed_pc=0x0c0c24a2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0c24a4;
P_0c0c24a4: /* original f008, guest PC 0x0c0c24a4 */
if(!s->budget--) { s->failed_pc=0x0c0c24a4u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c0c24a6;
P_0c0c24a6: /* original e014, guest PC 0x0c0c24a6 */
if(!s->budget--) { s->failed_pc=0x0c0c24a6u; return 0; }
r[0]=0x00000014u;
goto P_0c0c24a8;
P_0c0c24a8: /* original f2f6, guest PC 0x0c0c24a8 */
if(!s->budget--) { s->failed_pc=0x0c0c24a8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c24aa;
P_0c0c24aa: /* original 7aff, guest PC 0x0c0c24aa */
if(!s->budget--) { s->failed_pc=0x0c0c24aau; return 0; }
r[10]+=0xffffffffu;
goto P_0c0c24ac;
P_0c0c24ac: /* original f100, guest PC 0x0c0c24ac */
if(!s->budget--) { s->failed_pc=0x0c0c24acu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'+');
goto P_0c0c24ae;
P_0c0c24ae: /* original 6ba3, guest PC 0x0c0c24ae */
if(!s->budget--) { s->failed_pc=0x0c0c24aeu; return 0; }
r[11]=r[10];
goto P_0c0c24b0;
P_0c0c24b0: /* original e024, guest PC 0x0c0c24b0 */
if(!s->budget--) { s->failed_pc=0x0c0c24b0u; return 0; }
r[0]=0x00000024u;
goto P_0c0c24b2;
P_0c0c24b2: /* original 4b08, guest PC 0x0c0c24b2 */
if(!s->budget--) { s->failed_pc=0x0c0c24b2u; return 0; }
r[11]<<=2;
goto P_0c0c24b4;
P_0c0c24b4: /* original 4b00, guest PC 0x0c0c24b4 */
if(!s->budget--) { s->failed_pc=0x0c0c24b4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c0c24b6;
P_0c0c24b6: /* original f122, guest PC 0x0c0c24b6 */
if(!s->budget--) { s->failed_pc=0x0c0c24b6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0c24b8;
P_0c0c24b8: /* original 7d01, guest PC 0x0c0c24b8 */
if(!s->budget--) { s->failed_pc=0x0c0c24b8u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c24ba;
P_0c0c24ba: /* original 09b7, guest PC 0x0c0c24ba */
if(!s->budget--) { s->failed_pc=0x0c0c24bau; return 0; }
r[19]=r[9]*r[11];
goto P_0c0c24bc;
P_0c0c24bc: /* original ff17, guest PC 0x0c0c24bc */
if(!s->budget--) { s->failed_pc=0x0c0c24bcu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c24be;
P_0c0c24be: /* original e028, guest PC 0x0c0c24be */
if(!s->budget--) { s->failed_pc=0x0c0c24beu; return 0; }
r[0]=0x00000028u;
goto P_0c0c24c0;
P_0c0c24c0: /* original fe17, guest PC 0x0c0c24c0 */
if(!s->budget--) { s->failed_pc=0x0c0c24c0u; return 0; }
vf3_matrix_store(s,ram,1,r[14]+r[0]);
goto P_0c0c24c2;
P_0c0c24c2: /* original e018, guest PC 0x0c0c24c2 */
if(!s->budget--) { s->failed_pc=0x0c0c24c2u; return 0; }
r[0]=0x00000018u;
goto P_0c0c24c4;
P_0c0c24c4: /* original f3fc, guest PC 0x0c0c24c4 */
if(!s->budget--) { s->failed_pc=0x0c0c24c4u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0c24c6;
P_0c0c24c6: /* original fff6, guest PC 0x0c0c24c6 */
if(!s->budget--) { s->failed_pc=0x0c0c24c6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0c24c8;
P_0c0c24c8: /* original 0b1a, guest PC 0x0c0c24c8 */
if(!s->budget--) { s->failed_pc=0x0c0c24c8u; return 0; }
r[11]=r[19];
goto P_0c0c24ca;
P_0c0c24ca: /* original ff30, guest PC 0x0c0c24ca */
if(!s->budget--) { s->failed_pc=0x0c0c24cau; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0c24cc;
P_0c0c24cc: /* original d31c, guest PC 0x0c0c24cc */
if(!s->budget--) { s->failed_pc=0x0c0c24ccu; return 0; }
r[3]=read(ram,0x0c0c2540u,4);
goto P_0c0c24ce;
P_0c0c24ce: /* original 61b3, guest PC 0x0c0c24ce */
if(!s->budget--) { s->failed_pc=0x0c0c24ceu; return 0; }
r[1]=r[11];
goto P_0c0c24d0;
P_0c0c24d0: /* original 430b, guest PC 0x0c0c24d0 */
if(!s->budget--) { s->failed_pc=0x0c0c24d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c24d4u;
r[0]=read(ram,r[15]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c24d4u) { target=s->pc; goto dispatch; }
goto P_0c0c24d4;
P_0c0c24d2: /* original 50ff, guest PC 0x0c0c24d2 */
if(!s->budget--) { s->failed_pc=0x0c0c24d2u; return 0; }
r[0]=read(ram,r[15]+60,4);
goto P_0c0c24d4;
P_0c0c24d4: /* original 2998, guest PC 0x0c0c24d4 */
if(!s->budget--) { s->failed_pc=0x0c0c24d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0c24d6;
P_0c0c24d6: /* original 8d03, guest PC 0x0c0c24d6 */
if(!s->budget--) { s->failed_pc=0x0c0c24d6u; return 0; }
cond=r[17]&1u;
r[11]=r[0];
if(cond) { goto P_0c0c24e0; }
goto P_0c0c24da;
P_0c0c24d8: /* original 6b03, guest PC 0x0c0c24d8 */
if(!s->budget--) { s->failed_pc=0x0c0c24d8u; return 0; }
r[11]=r[0];
goto P_0c0c24da;
P_0c0c24da: /* original 2bb8, guest PC 0x0c0c24da */
if(!s->budget--) { s->failed_pc=0x0c0c24dau; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c24dc;
P_0c0c24dc: /* original 8b00, guest PC 0x0c0c24dc */
if(!s->budget--) { s->failed_pc=0x0c0c24dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c24e0; }
goto P_0c0c24de;
P_0c0c24de: /* original eb01, guest PC 0x0c0c24de */
if(!s->budget--) { s->failed_pc=0x0c0c24deu; return 0; }
r[11]=0x00000001u;
goto P_0c0c24e0;
P_0c0c24e0: /* original 4a15, guest PC 0x0c0c24e0 */
if(!s->budget--) { s->failed_pc=0x0c0c24e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c0c24e2;
P_0c0c24e2: /* original 69c3, guest PC 0x0c0c24e2 */
if(!s->budget--) { s->failed_pc=0x0c0c24e2u; return 0; }
r[9]=r[12];
goto P_0c0c24e4;
P_0c0c24e4: /* original 2fc2, guest PC 0x0c0c24e4 */
if(!s->budget--) { s->failed_pc=0x0c0c24e4u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0c24e6;
P_0c0c24e6: /* original d310, guest PC 0x0c0c24e6 */
if(!s->budget--) { s->failed_pc=0x0c0c24e6u; return 0; }
r[3]=read(ram,0x0c0c2528u,4);
goto P_0c0c24e8;
P_0c0c24e8: /* original 52f7, guest PC 0x0c0c24e8 */
if(!s->budget--) { s->failed_pc=0x0c0c24e8u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c0c24ea;
P_0c0c24ea: /* original 323c, guest PC 0x0c0c24ea */
if(!s->budget--) { s->failed_pc=0x0c0c24eau; return 0; }
r[2]+=r[3];
goto P_0c0c24ec;
P_0c0c24ec: /* original 8f7c, guest PC 0x0c0c24ec */
if(!s->budget--) { s->failed_pc=0x0c0c24ecu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+60,r[2],4);
if(!cond) { goto P_0c0c25e8; }
goto P_0c0c24f0;
P_0c0c24ee: /* original 1f2f, guest PC 0x0c0c24ee */
if(!s->budget--) { s->failed_pc=0x0c0c24eeu; return 0; }
write(ram,r[15]+60,r[2],4);
goto P_0c0c24f0;
P_0c0c24f0: /* original 63b3, guest PC 0x0c0c24f0 */
if(!s->budget--) { s->failed_pc=0x0c0c24f0u; return 0; }
r[3]=r[11];
goto P_0c0c24f2;
P_0c0c24f2: /* original 6493, guest PC 0x0c0c24f2 */
if(!s->budget--) { s->failed_pc=0x0c0c24f2u; return 0; }
r[4]=r[9];
goto P_0c0c24f4;
P_0c0c24f4: /* original 3348, guest PC 0x0c0c24f4 */
if(!s->budget--) { s->failed_pc=0x0c0c24f4u; return 0; }
r[3]-=r[4];
goto P_0c0c24f6;
P_0c0c24f6: /* original 6433, guest PC 0x0c0c24f6 */
if(!s->budget--) { s->failed_pc=0x0c0c24f6u; return 0; }
r[4]=r[3];
goto P_0c0c24f8;
P_0c0c24f8: /* original 4411, guest PC 0x0c0c24f8 */
if(!s->budget--) { s->failed_pc=0x0c0c24f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c24fa;
P_0c0c24fa: /* original 8908, guest PC 0x0c0c24fa */
if(!s->budget--) { s->failed_pc=0x0c0c24fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c250e; }
goto P_0c0c24fc;
P_0c0c24fc: /* original 6043, guest PC 0x0c0c24fc */
if(!s->budget--) { s->failed_pc=0x0c0c24fcu; return 0; }
r[0]=r[4];
goto P_0c0c24fe;
P_0c0c24fe: /* original 88ff, guest PC 0x0c0c24fe */
if(!s->budget--) { s->failed_pc=0x0c0c24feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c2500;
P_0c0c2500: /* original 8b02, guest PC 0x0c0c2500 */
if(!s->budget--) { s->failed_pc=0x0c0c2500u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2508; }
goto P_0c0c2502;
P_0c0c2502: /* original c710, guest PC 0x0c0c2502 */
if(!s->budget--) { s->failed_pc=0x0c0c2502u; return 0; }
r[0]=code_base|0x000c2544u;
goto P_0c0c2504;
P_0c0c2504: /* original a02a, guest PC 0x0c0c2504 */
if(!s->budget--) { s->failed_pc=0x0c0c2504u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c255c;
P_0c0c2506: /* original f408, guest PC 0x0c0c2506 */
if(!s->budget--) { s->failed_pc=0x0c0c2506u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c2508;
P_0c0c2508: /* original c70f, guest PC 0x0c0c2508 */
if(!s->budget--) { s->failed_pc=0x0c0c2508u; return 0; }
r[0]=code_base|0x000c2548u;
goto P_0c0c250a;
P_0c0c250a: /* original a027, guest PC 0x0c0c250a */
if(!s->budget--) { s->failed_pc=0x0c0c250au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c255c;
P_0c0c250c: /* original f408, guest PC 0x0c0c250c */
if(!s->budget--) { s->failed_pc=0x0c0c250cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c250e;
P_0c0c250e: /* original e208, guest PC 0x0c0c250e */
if(!s->budget--) { s->failed_pc=0x0c0c250eu; return 0; }
r[2]=0x00000008u;
goto P_0c0c2510;
P_0c0c2510: /* original 3427, guest PC 0x0c0c2510 */
if(!s->budget--) { s->failed_pc=0x0c0c2510u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c0c2512;
P_0c0c2512: /* original 8b1f, guest PC 0x0c0c2512 */
if(!s->budget--) { s->failed_pc=0x0c0c2512u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2554; }
goto P_0c0c2514;
P_0c0c2514: /* original 6043, guest PC 0x0c0c2514 */
if(!s->budget--) { s->failed_pc=0x0c0c2514u; return 0; }
r[0]=r[4];
goto P_0c0c2516;
P_0c0c2516: /* original 8809, guest PC 0x0c0c2516 */
if(!s->budget--) { s->failed_pc=0x0c0c2516u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c2518;
P_0c0c2518: /* original 8b02, guest PC 0x0c0c2518 */
if(!s->budget--) { s->failed_pc=0x0c0c2518u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2520; }
goto P_0c0c251a;
P_0c0c251a: /* original c70c, guest PC 0x0c0c251a */
if(!s->budget--) { s->failed_pc=0x0c0c251au; return 0; }
r[0]=code_base|0x000c254cu;
goto P_0c0c251c;
P_0c0c251c: /* original a01e, guest PC 0x0c0c251c */
if(!s->budget--) { s->failed_pc=0x0c0c251cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c255c;
P_0c0c251e: /* original f408, guest PC 0x0c0c251e */
if(!s->budget--) { s->failed_pc=0x0c0c251eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c2520;
P_0c0c2520: /* original c70b, guest PC 0x0c0c2520 */
if(!s->budget--) { s->failed_pc=0x0c0c2520u; return 0; }
r[0]=code_base|0x000c2550u;
goto P_0c0c2522;
P_0c0c2522: /* original a01b, guest PC 0x0c0c2522 */
if(!s->budget--) { s->failed_pc=0x0c0c2522u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c255c;
P_0c0c2524: /* original f408, guest PC 0x0c0c2524 */
if(!s->budget--) { s->failed_pc=0x0c0c2524u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
if(!vf3_matrix_family(0x0c0c2526u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2526u; return 0; } return 1;
P_0c0c2554: /* original 7401, guest PC 0x0c0c2554 */
if(!s->budget--) { s->failed_pc=0x0c0c2554u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c2556;
P_0c0c2556: /* original 445a, guest PC 0x0c0c2556 */
if(!s->budget--) { s->failed_pc=0x0c0c2556u; return 0; }
r[53]=r[4];
goto P_0c0c2558;
P_0c0c2558: /* original f32d, guest PC 0x0c0c2558 */
if(!s->budget--) { s->failed_pc=0x0c0c2558u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c255a;
P_0c0c255a: /* original f43c, guest PC 0x0c0c255a */
if(!s->budget--) { s->failed_pc=0x0c0c255au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c255c;
P_0c0c255c: /* original e018, guest PC 0x0c0c255c */
if(!s->budget--) { s->failed_pc=0x0c0c255cu; return 0; }
r[0]=0x00000018u;
goto P_0c0c255e;
P_0c0c255e: /* original f28d, guest PC 0x0c0c255e */
if(!s->budget--) { s->failed_pc=0x0c0c255eu; return 0; }
fr[2]=0;
goto P_0c0c2560;
P_0c0c2560: /* original f3f6, guest PC 0x0c0c2560 */
if(!s->budget--) { s->failed_pc=0x0c0c2560u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c2562;
P_0c0c2562: /* original f325, guest PC 0x0c0c2562 */
if(!s->budget--) { s->failed_pc=0x0c0c2562u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0c2564;
P_0c0c2564: /* original 8b03, guest PC 0x0c0c2564 */
if(!s->budget--) { s->failed_pc=0x0c0c2564u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c256e; }
goto P_0c0c2566;
P_0c0c2566: /* original c757, guest PC 0x0c0c2566 */
if(!s->budget--) { s->failed_pc=0x0c0c2566u; return 0; }
r[0]=code_base|0x000c26c4u;
goto P_0c0c2568;
P_0c0c2568: /* original f24c, guest PC 0x0c0c2568 */
if(!s->budget--) { s->failed_pc=0x0c0c2568u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0c256a;
P_0c0c256a: /* original f408, guest PC 0x0c0c256a */
if(!s->budget--) { s->failed_pc=0x0c0c256au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c256c;
P_0c0c256c: /* original f421, guest PC 0x0c0c256c */
if(!s->budget--) { s->failed_pc=0x0c0c256cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0c256e;
P_0c0c256e: /* original e010, guest PC 0x0c0c256e */
if(!s->budget--) { s->failed_pc=0x0c0c256eu; return 0; }
r[0]=0x00000010u;
goto P_0c0c2570;
P_0c0c2570: /* original f0cc, guest PC 0x0c0c2570 */
if(!s->budget--) { s->failed_pc=0x0c0c2570u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c0c2572;
P_0c0c2572: /* original f3f6, guest PC 0x0c0c2572 */
if(!s->budget--) { s->failed_pc=0x0c0c2572u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c2574;
P_0c0c2574: /* original ee38, guest PC 0x0c0c2574 */
if(!s->budget--) { s->failed_pc=0x0c0c2574u; return 0; }
r[14]=0x00000038u;
goto P_0c0c2576;
P_0c0c2576: /* original e038, guest PC 0x0c0c2576 */
if(!s->budget--) { s->failed_pc=0x0c0c2576u; return 0; }
r[0]=0x00000038u;
goto P_0c0c2578;
P_0c0c2578: /* original f34e, guest PC 0x0c0c2578 */
if(!s->budget--) { s->failed_pc=0x0c0c2578u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0c257a;
P_0c0c257a: /* original 2def, guest PC 0x0c0c257a */
if(!s->budget--) { s->failed_pc=0x0c0c257au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[14]);
goto P_0c0c257c;
P_0c0c257c: /* original ff37, guest PC 0x0c0c257c */
if(!s->budget--) { s->failed_pc=0x0c0c257cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c257e;
P_0c0c257e: /* original e004, guest PC 0x0c0c257e */
if(!s->budget--) { s->failed_pc=0x0c0c257eu; return 0; }
r[0]=0x00000004u;
goto P_0c0c2580;
P_0c0c2580: /* original 0e1a, guest PC 0x0c0c2580 */
if(!s->budget--) { s->failed_pc=0x0c0c2580u; return 0; }
r[14]=r[19];
goto P_0c0c2582;
P_0c0c2582: /* original 53ff, guest PC 0x0c0c2582 */
if(!s->budget--) { s->failed_pc=0x0c0c2582u; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c0c2584;
P_0c0c2584: /* original 6eef, guest PC 0x0c0c2584 */
if(!s->budget--) { s->failed_pc=0x0c0c2584u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c2586;
P_0c0c2586: /* original 3e3c, guest PC 0x0c0c2586 */
if(!s->budget--) { s->failed_pc=0x0c0c2586u; return 0; }
r[14]+=r[3];
goto P_0c0c2588;
P_0c0c2588: /* original 64e3, guest PC 0x0c0c2588 */
if(!s->budget--) { s->failed_pc=0x0c0c2588u; return 0; }
r[4]=r[14];
goto P_0c0c258a;
P_0c0c258a: /* original 2ec2, guest PC 0x0c0c258a */
if(!s->budget--) { s->failed_pc=0x0c0c258au; return 0; }
write(ram,r[14],r[12],4);
goto P_0c0c258c;
P_0c0c258c: /* original f8f6, guest PC 0x0c0c258c */
if(!s->budget--) { s->failed_pc=0x0c0c258cu; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c258e;
P_0c0c258e: /* original e02c, guest PC 0x0c0c258e */
if(!s->budget--) { s->failed_pc=0x0c0c258eu; return 0; }
r[0]=0x0000002cu;
goto P_0c0c2590;
P_0c0c2590: /* original f7f6, guest PC 0x0c0c2590 */
if(!s->budget--) { s->failed_pc=0x0c0c2590u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0c2592;
P_0c0c2592: /* original e030, guest PC 0x0c0c2592 */
if(!s->budget--) { s->failed_pc=0x0c0c2592u; return 0; }
r[0]=0x00000030u;
goto P_0c0c2594;
P_0c0c2594: /* original f6f6, guest PC 0x0c0c2594 */
if(!s->budget--) { s->failed_pc=0x0c0c2594u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c2596;
P_0c0c2596: /* original e034, guest PC 0x0c0c2596 */
if(!s->budget--) { s->failed_pc=0x0c0c2596u; return 0; }
r[0]=0x00000034u;
goto P_0c0c2598;
P_0c0c2598: /* original f5f6, guest PC 0x0c0c2598 */
if(!s->budget--) { s->failed_pc=0x0c0c2598u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c259a;
P_0c0c259a: /* original f4fc, guest PC 0x0c0c259a */
if(!s->budget--) { s->failed_pc=0x0c0c259au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c259c;
P_0c0c259c: /* original 480b, guest PC 0x0c0c259c */
if(!s->budget--) { s->failed_pc=0x0c0c259cu; return 0; }
target=r[8];
r[16]=code_base|0x0c0c25a0u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c25a0u) { target=s->pc; goto dispatch; }
goto P_0c0c25a0;
P_0c0c259e: /* original 7404, guest PC 0x0c0c259e */
if(!s->budget--) { s->failed_pc=0x0c0c259eu; return 0; }
r[4]+=0x00000004u;
goto P_0c0c25a0;
P_0c0c25a0: /* original c749, guest PC 0x0c0c25a0 */
if(!s->budget--) { s->failed_pc=0x0c0c25a0u; return 0; }
r[0]=code_base|0x000c26c8u;
goto P_0c0c25a2;
P_0c0c25a2: /* original f308, guest PC 0x0c0c25a2 */
if(!s->budget--) { s->failed_pc=0x0c0c25a2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c25a4;
P_0c0c25a4: /* original e038, guest PC 0x0c0c25a4 */
if(!s->budget--) { s->failed_pc=0x0c0c25a4u; return 0; }
r[0]=0x00000038u;
goto P_0c0c25a6;
P_0c0c25a6: /* original f2f6, guest PC 0x0c0c25a6 */
if(!s->budget--) { s->failed_pc=0x0c0c25a6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c25a8;
P_0c0c25a8: /* original e01c, guest PC 0x0c0c25a8 */
if(!s->budget--) { s->failed_pc=0x0c0c25a8u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c25aa;
P_0c0c25aa: /* original 7d01, guest PC 0x0c0c25aa */
if(!s->budget--) { s->failed_pc=0x0c0c25aau; return 0; }
r[13]+=0x00000001u;
goto P_0c0c25ac;
P_0c0c25ac: /* original f230, guest PC 0x0c0c25ac */
if(!s->budget--) { s->failed_pc=0x0c0c25acu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c25ae;
P_0c0c25ae: /* original f2e2, guest PC 0x0c0c25ae */
if(!s->budget--) { s->failed_pc=0x0c0c25aeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c0c25b0;
P_0c0c25b0: /* original fe27, guest PC 0x0c0c25b0 */
if(!s->budget--) { s->failed_pc=0x0c0c25b0u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c25b2;
P_0c0c25b2: /* original e020, guest PC 0x0c0c25b2 */
if(!s->budget--) { s->failed_pc=0x0c0c25b2u; return 0; }
r[0]=0x00000020u;
goto P_0c0c25b4;
P_0c0c25b4: /* original f2f6, guest PC 0x0c0c25b4 */
if(!s->budget--) { s->failed_pc=0x0c0c25b4u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c25b6;
P_0c0c25b6: /* original e020, guest PC 0x0c0c25b6 */
if(!s->budget--) { s->failed_pc=0x0c0c25b6u; return 0; }
r[0]=0x00000020u;
goto P_0c0c25b8;
P_0c0c25b8: /* original fe27, guest PC 0x0c0c25b8 */
if(!s->budget--) { s->failed_pc=0x0c0c25b8u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c25ba;
P_0c0c25ba: /* original e038, guest PC 0x0c0c25ba */
if(!s->budget--) { s->failed_pc=0x0c0c25bau; return 0; }
r[0]=0x00000038u;
goto P_0c0c25bc;
P_0c0c25bc: /* original f2f6, guest PC 0x0c0c25bc */
if(!s->budget--) { s->failed_pc=0x0c0c25bcu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c25be;
P_0c0c25be: /* original c743, guest PC 0x0c0c25be */
if(!s->budget--) { s->failed_pc=0x0c0c25beu; return 0; }
r[0]=code_base|0x000c26ccu;
goto P_0c0c25c0;
P_0c0c25c0: /* original f108, guest PC 0x0c0c25c0 */
if(!s->budget--) { s->failed_pc=0x0c0c25c0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c25c2;
P_0c0c25c2: /* original e024, guest PC 0x0c0c25c2 */
if(!s->budget--) { s->failed_pc=0x0c0c25c2u; return 0; }
r[0]=0x00000024u;
goto P_0c0c25c4;
P_0c0c25c4: /* original f2d0, guest PC 0x0c0c25c4 */
if(!s->budget--) { s->failed_pc=0x0c0c25c4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'+');
goto P_0c0c25c6;
P_0c0c25c6: /* original f210, guest PC 0x0c0c25c6 */
if(!s->budget--) { s->failed_pc=0x0c0c25c6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'+');
goto P_0c0c25c8;
P_0c0c25c8: /* original f2e2, guest PC 0x0c0c25c8 */
if(!s->budget--) { s->failed_pc=0x0c0c25c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c0c25ca;
P_0c0c25ca: /* original fe27, guest PC 0x0c0c25ca */
if(!s->budget--) { s->failed_pc=0x0c0c25cau; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c25cc;
P_0c0c25cc: /* original e024, guest PC 0x0c0c25cc */
if(!s->budget--) { s->failed_pc=0x0c0c25ccu; return 0; }
r[0]=0x00000024u;
goto P_0c0c25ce;
P_0c0c25ce: /* original f2f6, guest PC 0x0c0c25ce */
if(!s->budget--) { s->failed_pc=0x0c0c25ceu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c25d0;
P_0c0c25d0: /* original e028, guest PC 0x0c0c25d0 */
if(!s->budget--) { s->failed_pc=0x0c0c25d0u; return 0; }
r[0]=0x00000028u;
goto P_0c0c25d2;
P_0c0c25d2: /* original fe27, guest PC 0x0c0c25d2 */
if(!s->budget--) { s->failed_pc=0x0c0c25d2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c25d4;
P_0c0c25d4: /* original e018, guest PC 0x0c0c25d4 */
if(!s->budget--) { s->failed_pc=0x0c0c25d4u; return 0; }
r[0]=0x00000018u;
goto P_0c0c25d6;
P_0c0c25d6: /* original f2fc, guest PC 0x0c0c25d6 */
if(!s->budget--) { s->failed_pc=0x0c0c25d6u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0c25d8;
P_0c0c25d8: /* original fff6, guest PC 0x0c0c25d8 */
if(!s->budget--) { s->failed_pc=0x0c0c25d8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0c25da;
P_0c0c25da: /* original 63f2, guest PC 0x0c0c25da */
if(!s->budget--) { s->failed_pc=0x0c0c25dau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c25dc;
P_0c0c25dc: /* original ff20, guest PC 0x0c0c25dc */
if(!s->budget--) { s->failed_pc=0x0c0c25dcu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'+');
goto P_0c0c25de;
P_0c0c25de: /* original 7301, guest PC 0x0c0c25de */
if(!s->budget--) { s->failed_pc=0x0c0c25deu; return 0; }
r[3]+=0x00000001u;
goto P_0c0c25e0;
P_0c0c25e0: /* original 33a3, guest PC 0x0c0c25e0 */
if(!s->budget--) { s->failed_pc=0x0c0c25e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c0c25e2;
P_0c0c25e2: /* original 2f32, guest PC 0x0c0c25e2 */
if(!s->budget--) { s->failed_pc=0x0c0c25e2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c25e4;
P_0c0c25e4: /* original 8f84, guest PC 0x0c0c25e4 */
if(!s->budget--) { s->failed_pc=0x0c0c25e4u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000008u;
if(!cond) { goto P_0c0c24f0; }
goto P_0c0c25e8;
P_0c0c25e6: /* original 7908, guest PC 0x0c0c25e6 */
if(!s->budget--) { s->failed_pc=0x0c0c25e6u; return 0; }
r[9]+=0x00000008u;
goto P_0c0c25e8;
P_0c0c25e8: /* original 53f2, guest PC 0x0c0c25e8 */
if(!s->budget--) { s->failed_pc=0x0c0c25e8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c25ea;
P_0c0c25ea: /* original 2338, guest PC 0x0c0c25ea */
if(!s->budget--) { s->failed_pc=0x0c0c25eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c25ec;
P_0c0c25ec: /* original 8b04, guest PC 0x0c0c25ec */
if(!s->budget--) { s->failed_pc=0x0c0c25ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c25f8; }
goto P_0c0c25ee;
P_0c0c25ee: /* original e010, guest PC 0x0c0c25ee */
if(!s->budget--) { s->failed_pc=0x0c0c25eeu; return 0; }
r[0]=0x00000010u;
goto P_0c0c25f0;
P_0c0c25f0: /* original f38d, guest PC 0x0c0c25f0 */
if(!s->budget--) { s->failed_pc=0x0c0c25f0u; return 0; }
fr[3]=0;
goto P_0c0c25f2;
P_0c0c25f2: /* original fcf6, guest PC 0x0c0c25f2 */
if(!s->budget--) { s->failed_pc=0x0c0c25f2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]+r[0]);
goto P_0c0c25f4;
P_0c0c25f4: /* original a002, guest PC 0x0c0c25f4 */
if(!s->budget--) { s->failed_pc=0x0c0c25f4u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
goto P_0c0c25fc;
P_0c0c25f6: /* original fc30, guest PC 0x0c0c25f6 */
if(!s->budget--) { s->failed_pc=0x0c0c25f6u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
goto P_0c0c25f8;
P_0c0c25f8: /* original e044, guest PC 0x0c0c25f8 */
if(!s->budget--) { s->failed_pc=0x0c0c25f8u; return 0; }
r[0]=0x00000044u;
goto P_0c0c25fa;
P_0c0c25fa: /* original fcf6, guest PC 0x0c0c25fa */
if(!s->budget--) { s->failed_pc=0x0c0c25fau; return 0; }
vf3_matrix_load(s,ram,12,r[15]+r[0]);
goto P_0c0c25fc;
P_0c0c25fc: /* original e238, guest PC 0x0c0c25fc */
if(!s->budget--) { s->failed_pc=0x0c0c25fcu; return 0; }
r[2]=0x00000038u;
goto P_0c0c25fe;
P_0c0c25fe: /* original 5ef7, guest PC 0x0c0c25fe */
if(!s->budget--) { s->failed_pc=0x0c0c25feu; return 0; }
r[14]=read(ram,r[15]+28,4);
goto P_0c0c2600;
P_0c0c2600: /* original 2d2f, guest PC 0x0c0c2600 */
if(!s->budget--) { s->failed_pc=0x0c0c2600u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[2]);
goto P_0c0c2602;
P_0c0c2602: /* original e004, guest PC 0x0c0c2602 */
if(!s->budget--) { s->failed_pc=0x0c0c2602u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2604;
P_0c0c2604: /* original d332, guest PC 0x0c0c2604 */
if(!s->budget--) { s->failed_pc=0x0c0c2604u; return 0; }
r[3]=read(ram,0x0c0c26d0u,4);
goto P_0c0c2606;
P_0c0c2606: /* original e101, guest PC 0x0c0c2606 */
if(!s->budget--) { s->failed_pc=0x0c0c2606u; return 0; }
r[1]=0x00000001u;
goto P_0c0c2608;
P_0c0c2608: /* original 3e3c, guest PC 0x0c0c2608 */
if(!s->budget--) { s->failed_pc=0x0c0c2608u; return 0; }
r[14]+=r[3];
goto P_0c0c260a;
P_0c0c260a: /* original 021a, guest PC 0x0c0c260a */
if(!s->budget--) { s->failed_pc=0x0c0c260au; return 0; }
r[2]=r[19];
goto P_0c0c260c;
P_0c0c260c: /* original 1fe2, guest PC 0x0c0c260c */
if(!s->budget--) { s->failed_pc=0x0c0c260cu; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c0c260e;
P_0c0c260e: /* original 622f, guest PC 0x0c0c260e */
if(!s->budget--) { s->failed_pc=0x0c0c260eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c0c2610;
P_0c0c2610: /* original 3e2c, guest PC 0x0c0c2610 */
if(!s->budget--) { s->failed_pc=0x0c0c2610u; return 0; }
r[14]+=r[2];
goto P_0c0c2612;
P_0c0c2612: /* original 64e3, guest PC 0x0c0c2612 */
if(!s->budget--) { s->failed_pc=0x0c0c2612u; return 0; }
r[4]=r[14];
goto P_0c0c2614;
P_0c0c2614: /* original 2e12, guest PC 0x0c0c2614 */
if(!s->budget--) { s->failed_pc=0x0c0c2614u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0c2616;
P_0c0c2616: /* original f8f6, guest PC 0x0c0c2616 */
if(!s->budget--) { s->failed_pc=0x0c0c2616u; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c2618;
P_0c0c2618: /* original e02c, guest PC 0x0c0c2618 */
if(!s->budget--) { s->failed_pc=0x0c0c2618u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c261a;
P_0c0c261a: /* original f7f6, guest PC 0x0c0c261a */
if(!s->budget--) { s->failed_pc=0x0c0c261au; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0c261c;
P_0c0c261c: /* original e030, guest PC 0x0c0c261c */
if(!s->budget--) { s->failed_pc=0x0c0c261cu; return 0; }
r[0]=0x00000030u;
goto P_0c0c261e;
P_0c0c261e: /* original f6f6, guest PC 0x0c0c261e */
if(!s->budget--) { s->failed_pc=0x0c0c261eu; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c2620;
P_0c0c2620: /* original e034, guest PC 0x0c0c2620 */
if(!s->budget--) { s->failed_pc=0x0c0c2620u; return 0; }
r[0]=0x00000034u;
goto P_0c0c2622;
P_0c0c2622: /* original f5f6, guest PC 0x0c0c2622 */
if(!s->budget--) { s->failed_pc=0x0c0c2622u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c2624;
P_0c0c2624: /* original f4fc, guest PC 0x0c0c2624 */
if(!s->budget--) { s->failed_pc=0x0c0c2624u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c2626;
P_0c0c2626: /* original 480b, guest PC 0x0c0c2626 */
if(!s->budget--) { s->failed_pc=0x0c0c2626u; return 0; }
target=r[8];
r[16]=code_base|0x0c0c262au;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c262au) { target=s->pc; goto dispatch; }
goto P_0c0c262a;
P_0c0c2628: /* original 7404, guest PC 0x0c0c2628 */
if(!s->budget--) { s->failed_pc=0x0c0c2628u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c262a;
P_0c0c262a: /* original e014, guest PC 0x0c0c262a */
if(!s->budget--) { s->failed_pc=0x0c0c262au; return 0; }
r[0]=0x00000014u;
goto P_0c0c262c;
P_0c0c262c: /* original d329, guest PC 0x0c0c262c */
if(!s->budget--) { s->failed_pc=0x0c0c262cu; return 0; }
r[3]=read(ram,0x0c0c26d4u,4);
goto P_0c0c262e;
P_0c0c262e: /* original f9f6, guest PC 0x0c0c262e */
if(!s->budget--) { s->failed_pc=0x0c0c262eu; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c0c2630;
P_0c0c2630: /* original e028, guest PC 0x0c0c2630 */
if(!s->budget--) { s->failed_pc=0x0c0c2630u; return 0; }
r[0]=0x00000028u;
goto P_0c0c2632;
P_0c0c2632: /* original f7f6, guest PC 0x0c0c2632 */
if(!s->budget--) { s->failed_pc=0x0c0c2632u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0c2634;
P_0c0c2634: /* original e00c, guest PC 0x0c0c2634 */
if(!s->budget--) { s->failed_pc=0x0c0c2634u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c2636;
P_0c0c2636: /* original f5f6, guest PC 0x0c0c2636 */
if(!s->budget--) { s->failed_pc=0x0c0c2636u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c2638;
P_0c0c2638: /* original 64e3, guest PC 0x0c0c2638 */
if(!s->budget--) { s->failed_pc=0x0c0c2638u; return 0; }
r[4]=r[14];
goto P_0c0c263a;
P_0c0c263a: /* original f4cc, guest PC 0x0c0c263a */
if(!s->budget--) { s->failed_pc=0x0c0c263au; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c0c263c;
P_0c0c263c: /* original f8ec, guest PC 0x0c0c263c */
if(!s->budget--) { s->failed_pc=0x0c0c263cu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c0c263e;
P_0c0c263e: /* original f6dc, guest PC 0x0c0c263e */
if(!s->budget--) { s->failed_pc=0x0c0c263eu; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0c2640;
P_0c0c2640: /* original 430b, guest PC 0x0c0c2640 */
if(!s->budget--) { s->failed_pc=0x0c0c2640u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2644u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2644u) { target=s->pc; goto dispatch; }
goto P_0c0c2644;
P_0c0c2642: /* original 7404, guest PC 0x0c0c2642 */
if(!s->budget--) { s->failed_pc=0x0c0c2642u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c2644;
P_0c0c2644: /* original c720, guest PC 0x0c0c2644 */
if(!s->budget--) { s->failed_pc=0x0c0c2644u; return 0; }
r[0]=code_base|0x000c26c8u;
goto P_0c0c2646;
P_0c0c2646: /* original f2cc, guest PC 0x0c0c2646 */
if(!s->budget--) { s->failed_pc=0x0c0c2646u; return 0; }
vf3_matrix_move(s,2,12);
goto P_0c0c2648;
P_0c0c2648: /* original f308, guest PC 0x0c0c2648 */
if(!s->budget--) { s->failed_pc=0x0c0c2648u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c264a;
P_0c0c264a: /* original e01c, guest PC 0x0c0c264a */
if(!s->budget--) { s->failed_pc=0x0c0c264au; return 0; }
r[0]=0x0000001cu;
goto P_0c0c264c;
P_0c0c264c: /* original fcd0, guest PC 0x0c0c264c */
if(!s->budget--) { s->failed_pc=0x0c0c264cu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'+');
goto P_0c0c264e;
P_0c0c264e: /* original 7d01, guest PC 0x0c0c264e */
if(!s->budget--) { s->failed_pc=0x0c0c264eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0c2650;
P_0c0c2650: /* original f230, guest PC 0x0c0c2650 */
if(!s->budget--) { s->failed_pc=0x0c0c2650u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c2652;
P_0c0c2652: /* original 4d11, guest PC 0x0c0c2652 */
if(!s->budget--) { s->failed_pc=0x0c0c2652u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c0c2654;
P_0c0c2654: /* original f2e2, guest PC 0x0c0c2654 */
if(!s->budget--) { s->failed_pc=0x0c0c2654u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c0c2656;
P_0c0c2656: /* original fe27, guest PC 0x0c0c2656 */
if(!s->budget--) { s->failed_pc=0x0c0c2656u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c2658;
P_0c0c2658: /* original e020, guest PC 0x0c0c2658 */
if(!s->budget--) { s->failed_pc=0x0c0c2658u; return 0; }
r[0]=0x00000020u;
goto P_0c0c265a;
P_0c0c265a: /* original f2f6, guest PC 0x0c0c265a */
if(!s->budget--) { s->failed_pc=0x0c0c265au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c265c;
P_0c0c265c: /* original e020, guest PC 0x0c0c265c */
if(!s->budget--) { s->failed_pc=0x0c0c265cu; return 0; }
r[0]=0x00000020u;
goto P_0c0c265e;
P_0c0c265e: /* original fe27, guest PC 0x0c0c265e */
if(!s->budget--) { s->failed_pc=0x0c0c265eu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c2660;
P_0c0c2660: /* original c71a, guest PC 0x0c0c2660 */
if(!s->budget--) { s->failed_pc=0x0c0c2660u; return 0; }
r[0]=code_base|0x000c26ccu;
goto P_0c0c2662;
P_0c0c2662: /* original f208, guest PC 0x0c0c2662 */
if(!s->budget--) { s->failed_pc=0x0c0c2662u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c2664;
P_0c0c2664: /* original e024, guest PC 0x0c0c2664 */
if(!s->budget--) { s->failed_pc=0x0c0c2664u; return 0; }
r[0]=0x00000024u;
goto P_0c0c2666;
P_0c0c2666: /* original fc20, guest PC 0x0c0c2666 */
if(!s->budget--) { s->failed_pc=0x0c0c2666u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[2],r[18],'+');
goto P_0c0c2668;
P_0c0c2668: /* original fce2, guest PC 0x0c0c2668 */
if(!s->budget--) { s->failed_pc=0x0c0c2668u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[14],r[18],'*');
goto P_0c0c266a;
P_0c0c266a: /* original fec7, guest PC 0x0c0c266a */
if(!s->budget--) { s->failed_pc=0x0c0c266au; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0c266c;
P_0c0c266c: /* original e024, guest PC 0x0c0c266c */
if(!s->budget--) { s->failed_pc=0x0c0c266cu; return 0; }
r[0]=0x00000024u;
goto P_0c0c266e;
P_0c0c266e: /* original f1f6, guest PC 0x0c0c266e */
if(!s->budget--) { s->failed_pc=0x0c0c266eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c2670;
P_0c0c2670: /* original e028, guest PC 0x0c0c2670 */
if(!s->budget--) { s->failed_pc=0x0c0c2670u; return 0; }
r[0]=0x00000028u;
goto P_0c0c2672;
P_0c0c2672: /* original fe17, guest PC 0x0c0c2672 */
if(!s->budget--) { s->failed_pc=0x0c0c2672u; return 0; }
vf3_matrix_store(s,ram,1,r[14]+r[0]);
goto P_0c0c2674;
P_0c0c2674: /* original 8f16, guest PC 0x0c0c2674 */
if(!s->budget--) { s->failed_pc=0x0c0c2674u; return 0; }
cond=r[17]&1u;
r[14]=read(ram,r[15]+8,4);
if(!cond) { goto P_0c0c26a4; }
goto P_0c0c2678;
P_0c0c2676: /* original 5ef2, guest PC 0x0c0c2676 */
if(!s->budget--) { s->failed_pc=0x0c0c2676u; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c0c2678;
P_0c0c2678: /* original 9b23, guest PC 0x0c0c2678 */
if(!s->budget--) { s->failed_pc=0x0c0c2678u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c26c2u,2);
goto P_0c0c267a;
P_0c0c267a: /* original da17, guest PC 0x0c0c267a */
if(!s->budget--) { s->failed_pc=0x0c0c267au; return 0; }
r[10]=read(ram,0x0c0c26d8u,4);
goto P_0c0c267c;
P_0c0c267c: /* original ff9d, guest PC 0x0c0c267c */
if(!s->budget--) { s->failed_pc=0x0c0c267cu; return 0; }
fr[15]=0x3f800000u;
goto P_0c0c267e;
P_0c0c267e: /* original e048, guest PC 0x0c0c267e */
if(!s->budget--) { s->failed_pc=0x0c0c267eu; return 0; }
r[0]=0x00000048u;
goto P_0c0c2680;
P_0c0c2680: /* original 64e3, guest PC 0x0c0c2680 */
if(!s->budget--) { s->failed_pc=0x0c0c2680u; return 0; }
r[4]=r[14];
goto P_0c0c2682;
P_0c0c2682: /* original 02fd, guest PC 0x0c0c2682 */
if(!s->budget--) { s->failed_pc=0x0c0c2682u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0c2684;
P_0c0c2684: /* original e034, guest PC 0x0c0c2684 */
if(!s->budget--) { s->failed_pc=0x0c0c2684u; return 0; }
r[0]=0x00000034u;
goto P_0c0c2686;
P_0c0c2686: /* original 622d, guest PC 0x0c0c2686 */
if(!s->budget--) { s->failed_pc=0x0c0c2686u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c2688;
P_0c0c2688: /* original 1e21, guest PC 0x0c0c2688 */
if(!s->budget--) { s->failed_pc=0x0c0c2688u; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c0c268a;
P_0c0c268a: /* original 1ecb, guest PC 0x0c0c268a */
if(!s->budget--) { s->failed_pc=0x0c0c268au; return 0; }
write(ram,r[14]+44,r[12],4);
goto P_0c0c268c;
P_0c0c268c: /* original 1ebc, guest PC 0x0c0c268c */
if(!s->budget--) { s->failed_pc=0x0c0c268cu; return 0; }
write(ram,r[14]+48,r[11],4);
goto P_0c0c268e;
P_0c0c268e: /* original fef7, guest PC 0x0c0c268e */
if(!s->budget--) { s->failed_pc=0x0c0c268eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c2690;
P_0c0c2690: /* original e004, guest PC 0x0c0c2690 */
if(!s->budget--) { s->failed_pc=0x0c0c2690u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2692;
P_0c0c2692: /* original f3f6, guest PC 0x0c0c2692 */
if(!s->budget--) { s->failed_pc=0x0c0c2692u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c2694;
P_0c0c2694: /* original e010, guest PC 0x0c0c2694 */
if(!s->budget--) { s->failed_pc=0x0c0c2694u; return 0; }
r[0]=0x00000010u;
goto P_0c0c2696;
P_0c0c2696: /* original fe37, guest PC 0x0c0c2696 */
if(!s->budget--) { s->failed_pc=0x0c0c2696u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c2698;
P_0c0c2698: /* original 4a0b, guest PC 0x0c0c2698 */
if(!s->budget--) { s->failed_pc=0x0c0c2698u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c269cu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c269cu) { target=s->pc; goto dispatch; }
goto P_0c0c269c;
P_0c0c269a: /* original 7404, guest PC 0x0c0c269a */
if(!s->budget--) { s->failed_pc=0x0c0c269au; return 0; }
r[4]+=0x00000004u;
goto P_0c0c269c;
P_0c0c269c: /* original 7dff, guest PC 0x0c0c269c */
if(!s->budget--) { s->failed_pc=0x0c0c269cu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0c269e;
P_0c0c269e: /* original 4d11, guest PC 0x0c0c269e */
if(!s->budget--) { s->failed_pc=0x0c0c269eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c0c26a0;
P_0c0c26a0: /* original 8ded, guest PC 0x0c0c26a0 */
if(!s->budget--) { s->failed_pc=0x0c0c26a0u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000038u;
if(cond) { goto P_0c0c267e; }
goto P_0c0c26a4;
P_0c0c26a2: /* original 7e38, guest PC 0x0c0c26a2 */
if(!s->budget--) { s->failed_pc=0x0c0c26a2u; return 0; }
r[14]+=0x00000038u;
goto P_0c0c26a4;
P_0c0c26a4: /* original 7f4c, guest PC 0x0c0c26a4 */
if(!s->budget--) { s->failed_pc=0x0c0c26a4u; return 0; }
r[15]+=0x0000004cu;
goto P_0c0c26a6;
P_0c0c26a6: /* original 4f16, guest PC 0x0c0c26a6 */
if(!s->budget--) { s->failed_pc=0x0c0c26a6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c26a8;
P_0c0c26a8: /* original 4f26, guest PC 0x0c0c26a8 */
if(!s->budget--) { s->failed_pc=0x0c0c26a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c26aa;
P_0c0c26aa: /* original fcf9, guest PC 0x0c0c26aa */
if(!s->budget--) { s->failed_pc=0x0c0c26aau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c26ac;
P_0c0c26ac: /* original fdf9, guest PC 0x0c0c26ac */
if(!s->budget--) { s->failed_pc=0x0c0c26acu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c26ae;
P_0c0c26ae: /* original fef9, guest PC 0x0c0c26ae */
if(!s->budget--) { s->failed_pc=0x0c0c26aeu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c26b0;
P_0c0c26b0: /* original fff9, guest PC 0x0c0c26b0 */
if(!s->budget--) { s->failed_pc=0x0c0c26b0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c26b2;
P_0c0c26b2: /* original 68f6, guest PC 0x0c0c26b2 */
if(!s->budget--) { s->failed_pc=0x0c0c26b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c26b4;
P_0c0c26b4: /* original 69f6, guest PC 0x0c0c26b4 */
if(!s->budget--) { s->failed_pc=0x0c0c26b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c26b6;
P_0c0c26b6: /* original 6af6, guest PC 0x0c0c26b6 */
if(!s->budget--) { s->failed_pc=0x0c0c26b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c26b8;
P_0c0c26b8: /* original 6bf6, guest PC 0x0c0c26b8 */
if(!s->budget--) { s->failed_pc=0x0c0c26b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c26ba;
P_0c0c26ba: /* original 6cf6, guest PC 0x0c0c26ba */
if(!s->budget--) { s->failed_pc=0x0c0c26bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c26bc;
P_0c0c26bc: /* original 6df6, guest PC 0x0c0c26bc */
if(!s->budget--) { s->failed_pc=0x0c0c26bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c26be;
P_0c0c26be: /* original 000b, guest PC 0x0c0c26be */
if(!s->budget--) { s->failed_pc=0x0c0c26beu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c26c0: /* original 6ef6, guest PC 0x0c0c26c0 */
if(!s->budget--) { s->failed_pc=0x0c0c26c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c26c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c26c2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
