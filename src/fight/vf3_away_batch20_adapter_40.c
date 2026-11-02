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
int vf3_away_batch20_adapter_40(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0a2760u: goto P_0c0a2760;
case 0x0c0a2762u: goto P_0c0a2762;
case 0x0c0a2764u: goto P_0c0a2764;
case 0x0c0a2766u: goto P_0c0a2766;
case 0x0c0a2768u: goto P_0c0a2768;
case 0x0c0a276au: goto P_0c0a276a;
case 0x0c0a276cu: goto P_0c0a276c;
case 0x0c0a276eu: goto P_0c0a276e;
case 0x0c0a2770u: goto P_0c0a2770;
case 0x0c0a2772u: goto P_0c0a2772;
case 0x0c0a2774u: goto P_0c0a2774;
case 0x0c0a2776u: goto P_0c0a2776;
case 0x0c0a2778u: goto P_0c0a2778;
case 0x0c0a277au: goto P_0c0a277a;
case 0x0c0a277cu: goto P_0c0a277c;
case 0x0c0a277eu: goto P_0c0a277e;
case 0x0c0a2780u: goto P_0c0a2780;
case 0x0c0a2782u: goto P_0c0a2782;
case 0x0c0a2784u: goto P_0c0a2784;
case 0x0c0a2786u: goto P_0c0a2786;
case 0x0c0a2788u: goto P_0c0a2788;
case 0x0c0a278au: goto P_0c0a278a;
case 0x0c0a278cu: goto P_0c0a278c;
case 0x0c0a278eu: goto P_0c0a278e;
case 0x0c0a2790u: goto P_0c0a2790;
case 0x0c0a2792u: goto P_0c0a2792;
case 0x0c0a2794u: goto P_0c0a2794;
case 0x0c0a2796u: goto P_0c0a2796;
case 0x0c0a2798u: goto P_0c0a2798;
case 0x0c0a279au: goto P_0c0a279a;
case 0x0c0a279cu: goto P_0c0a279c;
case 0x0c0a279eu: goto P_0c0a279e;
case 0x0c0a27a0u: goto P_0c0a27a0;
case 0x0c0a27a2u: goto P_0c0a27a2;
case 0x0c0a27a4u: goto P_0c0a27a4;
case 0x0c0a27a6u: goto P_0c0a27a6;
case 0x0c0a27a8u: goto P_0c0a27a8;
case 0x0c0a27aau: goto P_0c0a27aa;
case 0x0c0a27acu: goto P_0c0a27ac;
case 0x0c0a27aeu: goto P_0c0a27ae;
case 0x0c0a27b0u: goto P_0c0a27b0;
case 0x0c0a27b2u: goto P_0c0a27b2;
case 0x0c0a27b4u: goto P_0c0a27b4;
case 0x0c0a27b6u: goto P_0c0a27b6;
case 0x0c0a27b8u: goto P_0c0a27b8;
case 0x0c0a27bau: goto P_0c0a27ba;
case 0x0c0a27bcu: goto P_0c0a27bc;
case 0x0c0a27beu: goto P_0c0a27be;
case 0x0c0a27c0u: goto P_0c0a27c0;
case 0x0c0a27c2u: goto P_0c0a27c2;
case 0x0c0a27c4u: goto P_0c0a27c4;
case 0x0c0a27c6u: goto P_0c0a27c6;
case 0x0c0a27c8u: goto P_0c0a27c8;
case 0x0c0a27cau: goto P_0c0a27ca;
case 0x0c0a27ccu: goto P_0c0a27cc;
case 0x0c0a27ceu: goto P_0c0a27ce;
case 0x0c0a27d0u: goto P_0c0a27d0;
case 0x0c0a27d2u: goto P_0c0a27d2;
case 0x0c0a27d4u: goto P_0c0a27d4;
case 0x0c0a27d6u: goto P_0c0a27d6;
case 0x0c0a27d8u: goto P_0c0a27d8;
case 0x0c0a27dau: goto P_0c0a27da;
case 0x0c0a27dcu: goto P_0c0a27dc;
case 0x0c0a27deu: goto P_0c0a27de;
case 0x0c0a27e0u: goto P_0c0a27e0;
case 0x0c0a27e2u: goto P_0c0a27e2;
case 0x0c0a27e4u: goto P_0c0a27e4;
case 0x0c0a27e6u: goto P_0c0a27e6;
case 0x0c0a27e8u: goto P_0c0a27e8;
case 0x0c0a27eau: goto P_0c0a27ea;
case 0x0c0a27ecu: goto P_0c0a27ec;
case 0x0c0a2984u: goto P_0c0a2984;
case 0x0c0a2986u: goto P_0c0a2986;
case 0x0c0a2988u: goto P_0c0a2988;
case 0x0c0a298au: goto P_0c0a298a;
case 0x0c0a298cu: goto P_0c0a298c;
case 0x0c0a298eu: goto P_0c0a298e;
case 0x0c0a2990u: goto P_0c0a2990;
case 0x0c0a2992u: goto P_0c0a2992;
case 0x0c0a2994u: goto P_0c0a2994;
case 0x0c0a2996u: goto P_0c0a2996;
case 0x0c0a2998u: goto P_0c0a2998;
case 0x0c0a299au: goto P_0c0a299a;
case 0x0c0a299cu: goto P_0c0a299c;
case 0x0c0a299eu: goto P_0c0a299e;
case 0x0c0a29a0u: goto P_0c0a29a0;
case 0x0c0a29a2u: goto P_0c0a29a2;
case 0x0c0a29a4u: goto P_0c0a29a4;
case 0x0c0a29a6u: goto P_0c0a29a6;
case 0x0c0a29a8u: goto P_0c0a29a8;
case 0x0c0a29aau: goto P_0c0a29aa;
case 0x0c0a29acu: goto P_0c0a29ac;
case 0x0c0a29aeu: goto P_0c0a29ae;
case 0x0c0a29b0u: goto P_0c0a29b0;
case 0x0c0a29b2u: goto P_0c0a29b2;
case 0x0c0a29b4u: goto P_0c0a29b4;
case 0x0c0a29b6u: goto P_0c0a29b6;
case 0x0c0a29b8u: goto P_0c0a29b8;
case 0x0c0a29bau: goto P_0c0a29ba;
case 0x0c0a29bcu: goto P_0c0a29bc;
case 0x0c0a29beu: goto P_0c0a29be;
case 0x0c0a29c0u: goto P_0c0a29c0;
case 0x0c0a29c2u: goto P_0c0a29c2;
case 0x0c0a29c4u: goto P_0c0a29c4;
case 0x0c0a29c6u: goto P_0c0a29c6;
case 0x0c0a29c8u: goto P_0c0a29c8;
case 0x0c0a29cau: goto P_0c0a29ca;
case 0x0c0a29ccu: goto P_0c0a29cc;
case 0x0c0a29ceu: goto P_0c0a29ce;
case 0x0c0a29d0u: goto P_0c0a29d0;
case 0x0c0a29d2u: goto P_0c0a29d2;
case 0x0c0a29d4u: goto P_0c0a29d4;
case 0x0c0a29d6u: goto P_0c0a29d6;
case 0x0c0a29d8u: goto P_0c0a29d8;
case 0x0c0a29dau: goto P_0c0a29da;
case 0x0c0a29dcu: goto P_0c0a29dc;
case 0x0c0a29deu: goto P_0c0a29de;
case 0x0c0a29e0u: goto P_0c0a29e0;
case 0x0c0a29e2u: goto P_0c0a29e2;
case 0x0c0a29e4u: goto P_0c0a29e4;
case 0x0c0a29e6u: goto P_0c0a29e6;
case 0x0c0a29e8u: goto P_0c0a29e8;
case 0x0c0a29eau: goto P_0c0a29ea;
case 0x0c0a29ecu: goto P_0c0a29ec;
case 0x0c0a29eeu: goto P_0c0a29ee;
case 0x0c0a29f0u: goto P_0c0a29f0;
case 0x0c0a29f2u: goto P_0c0a29f2;
case 0x0c0a29f4u: goto P_0c0a29f4;
case 0x0c0a29f6u: goto P_0c0a29f6;
case 0x0c0a29f8u: goto P_0c0a29f8;
case 0x0c0a29fau: goto P_0c0a29fa;
case 0x0c0a29fcu: goto P_0c0a29fc;
case 0x0c0a29feu: goto P_0c0a29fe;
case 0x0c0a2a00u: goto P_0c0a2a00;
case 0x0c0a2a02u: goto P_0c0a2a02;
case 0x0c0a2a04u: goto P_0c0a2a04;
case 0x0c0a2a06u: goto P_0c0a2a06;
case 0x0c0a2a08u: goto P_0c0a2a08;
case 0x0c0a2a0au: goto P_0c0a2a0a;
case 0x0c0a2a0cu: goto P_0c0a2a0c;
case 0x0c0a2a0eu: goto P_0c0a2a0e;
case 0x0c0a2a10u: goto P_0c0a2a10;
case 0x0c0a2a12u: goto P_0c0a2a12;
case 0x0c0a2a14u: goto P_0c0a2a14;
case 0x0c0a2a16u: goto P_0c0a2a16;
case 0x0c0a2a18u: goto P_0c0a2a18;
case 0x0c0a2a1au: goto P_0c0a2a1a;
case 0x0c0a2a1cu: goto P_0c0a2a1c;
case 0x0c0a2a1eu: goto P_0c0a2a1e;
case 0x0c0a2a20u: goto P_0c0a2a20;
case 0x0c0a2a22u: goto P_0c0a2a22;
case 0x0c0a2a24u: goto P_0c0a2a24;
case 0x0c0a2a26u: goto P_0c0a2a26;
case 0x0c0a2a28u: goto P_0c0a2a28;
case 0x0c0a2a2au: goto P_0c0a2a2a;
case 0x0c0a2a2cu: goto P_0c0a2a2c;
case 0x0c0a2a2eu: goto P_0c0a2a2e;
case 0x0c0a2a30u: goto P_0c0a2a30;
case 0x0c0a2a32u: goto P_0c0a2a32;
case 0x0c0a2a34u: goto P_0c0a2a34;
case 0x0c0a2a36u: goto P_0c0a2a36;
case 0x0c0a2a38u: goto P_0c0a2a38;
case 0x0c0a2a3au: goto P_0c0a2a3a;
case 0x0c0a2a3cu: goto P_0c0a2a3c;
case 0x0c0a2a3eu: goto P_0c0a2a3e;
case 0x0c0a2a40u: goto P_0c0a2a40;
case 0x0c0a2a42u: goto P_0c0a2a42;
case 0x0c0a2a44u: goto P_0c0a2a44;
case 0x0c0a2a46u: goto P_0c0a2a46;
case 0x0c0a2a48u: goto P_0c0a2a48;
case 0x0c0a2a4au: goto P_0c0a2a4a;
case 0x0c0a2a4cu: goto P_0c0a2a4c;
case 0x0c0a2a4eu: goto P_0c0a2a4e;
case 0x0c0a2a50u: goto P_0c0a2a50;
case 0x0c0a2a52u: goto P_0c0a2a52;
case 0x0c0a2a54u: goto P_0c0a2a54;
case 0x0c0a2a56u: goto P_0c0a2a56;
case 0x0c0a2a58u: goto P_0c0a2a58;
case 0x0c0a2a5au: goto P_0c0a2a5a;
case 0x0c0a2a5cu: goto P_0c0a2a5c;
case 0x0c0a2a5eu: goto P_0c0a2a5e;
case 0x0c0a2a60u: goto P_0c0a2a60;
case 0x0c0a2a62u: goto P_0c0a2a62;
case 0x0c0a2a64u: goto P_0c0a2a64;
case 0x0c0a2a66u: goto P_0c0a2a66;
case 0x0c0a2a68u: goto P_0c0a2a68;
case 0x0c0a2a6au: goto P_0c0a2a6a;
case 0x0c0a2a6cu: goto P_0c0a2a6c;
case 0x0c0a2a6eu: goto P_0c0a2a6e;
case 0x0c0a2a70u: goto P_0c0a2a70;
case 0x0c0a2a72u: goto P_0c0a2a72;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0a2760: /* original 2fe6, guest PC 0x0c0a2760 */
if(!s->budget--) { s->failed_pc=0x0c0a2760u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2762;
P_0c0a2762: /* original 2fd6, guest PC 0x0c0a2762 */
if(!s->budget--) { s->failed_pc=0x0c0a2762u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2764;
P_0c0a2764: /* original 6d43, guest PC 0x0c0a2764 */
if(!s->budget--) { s->failed_pc=0x0c0a2764u; return 0; }
r[13]=r[4];
goto P_0c0a2766;
P_0c0a2766: /* original 2fc6, guest PC 0x0c0a2766 */
if(!s->budget--) { s->failed_pc=0x0c0a2766u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2768;
P_0c0a2768: /* original 2fb6, guest PC 0x0c0a2768 */
if(!s->budget--) { s->failed_pc=0x0c0a2768u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a276a;
P_0c0a276a: /* original 2fa6, guest PC 0x0c0a276a */
if(!s->budget--) { s->failed_pc=0x0c0a276au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a276c;
P_0c0a276c: /* original 2f96, guest PC 0x0c0a276c */
if(!s->budget--) { s->failed_pc=0x0c0a276cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a276e;
P_0c0a276e: /* original e900, guest PC 0x0c0a276e */
if(!s->budget--) { s->failed_pc=0x0c0a276eu; return 0; }
r[9]=0x00000000u;
goto P_0c0a2770;
P_0c0a2770: /* original 2f86, guest PC 0x0c0a2770 */
if(!s->budget--) { s->failed_pc=0x0c0a2770u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2772;
P_0c0a2772: /* original 6042, guest PC 0x0c0a2772 */
if(!s->budget--) { s->failed_pc=0x0c0a2772u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0a2774;
P_0c0a2774: /* original 4f22, guest PC 0x0c0a2774 */
if(!s->budget--) { s->failed_pc=0x0c0a2774u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2776;
P_0c0a2776: /* original c880, guest PC 0x0c0a2776 */
if(!s->budget--) { s->failed_pc=0x0c0a2776u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2778;
P_0c0a2778: /* original 8d2f, guest PC 0x0c0a2778 */
if(!s->budget--) { s->failed_pc=0x0c0a2778u; return 0; }
cond=r[17]&1u;
r[5]=r[9];
if(cond) { goto P_0c0a27da; }
goto P_0c0a277c;
P_0c0a277a: /* original 6593, guest PC 0x0c0a277a */
if(!s->budget--) { s->failed_pc=0x0c0a277au; return 0; }
r[5]=r[9];
goto P_0c0a277c;
P_0c0a277c: /* original 6242, guest PC 0x0c0a277c */
if(!s->budget--) { s->failed_pc=0x0c0a277cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0a277e;
P_0c0a277e: /* original e020, guest PC 0x0c0a277e */
if(!s->budget--) { s->failed_pc=0x0c0a277eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2780;
P_0c0a2780: /* original d337, guest PC 0x0c0a2780 */
if(!s->budget--) { s->failed_pc=0x0c0a2780u; return 0; }
r[3]=read(ram,0x0c0a2860u,4);
goto P_0c0a2782;
P_0c0a2782: /* original 9169, guest PC 0x0c0a2782 */
if(!s->budget--) { s->failed_pc=0x0c0a2782u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2858u,2);
goto P_0c0a2784;
P_0c0a2784: /* original 2239, guest PC 0x0c0a2784 */
if(!s->budget--) { s->failed_pc=0x0c0a2784u; return 0; }
r[2]&=r[3];
goto P_0c0a2786;
P_0c0a2786: /* original 03dd, guest PC 0x0c0a2786 */
if(!s->budget--) { s->failed_pc=0x0c0a2786u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a2788;
P_0c0a2788: /* original e022, guest PC 0x0c0a2788 */
if(!s->budget--) { s->failed_pc=0x0c0a2788u; return 0; }
r[0]=0x00000022u;
goto P_0c0a278a;
P_0c0a278a: /* original 3210, guest PC 0x0c0a278a */
if(!s->budget--) { s->failed_pc=0x0c0a278au; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a278c;
P_0c0a278c: /* original 02dd, guest PC 0x0c0a278c */
if(!s->budget--) { s->failed_pc=0x0c0a278cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a278e;
P_0c0a278e: /* original 633d, guest PC 0x0c0a278e */
if(!s->budget--) { s->failed_pc=0x0c0a278eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2790;
P_0c0a2790: /* original 622d, guest PC 0x0c0a2790 */
if(!s->budget--) { s->failed_pc=0x0c0a2790u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a2792;
P_0c0a2792: /* original 232b, guest PC 0x0c0a2792 */
if(!s->budget--) { s->failed_pc=0x0c0a2792u; return 0; }
r[3]|=r[2];
goto P_0c0a2794;
P_0c0a2794: /* original 2338, guest PC 0x0c0a2794 */
if(!s->budget--) { s->failed_pc=0x0c0a2794u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2796;
P_0c0a2796: /* original 8920, guest PC 0x0c0a2796 */
if(!s->budget--) { s->failed_pc=0x0c0a2796u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a27da; }
goto P_0c0a2798;
P_0c0a2798: /* original e020, guest PC 0x0c0a2798 */
if(!s->budget--) { s->failed_pc=0x0c0a2798u; return 0; }
r[0]=0x00000020u;
goto P_0c0a279a;
P_0c0a279a: /* original d332, guest PC 0x0c0a279a */
if(!s->budget--) { s->failed_pc=0x0c0a279au; return 0; }
r[3]=read(ram,0x0c0a2864u,4);
goto P_0c0a279c;
P_0c0a279c: /* original 04dd, guest PC 0x0c0a279c */
if(!s->budget--) { s->failed_pc=0x0c0a279cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a279e;
P_0c0a279e: /* original 58d4, guest PC 0x0c0a279e */
if(!s->budget--) { s->failed_pc=0x0c0a279eu; return 0; }
r[8]=read(ram,r[13]+16,4);
goto P_0c0a27a0;
P_0c0a27a0: /* original 430b, guest PC 0x0c0a27a0 */
if(!s->budget--) { s->failed_pc=0x0c0a27a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a27a4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a27a4u) { target=s->pc; goto dispatch; }
goto P_0c0a27a4;
P_0c0a27a2: /* original 644d, guest PC 0x0c0a27a2 */
if(!s->budget--) { s->failed_pc=0x0c0a27a2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a27a4;
P_0c0a27a4: /* original ea01, guest PC 0x0c0a27a4 */
if(!s->budget--) { s->failed_pc=0x0c0a27a4u; return 0; }
r[10]=0x00000001u;
goto P_0c0a27a6;
P_0c0a27a6: /* original a013, guest PC 0x0c0a27a6 */
if(!s->budget--) { s->failed_pc=0x0c0a27a6u; return 0; }
r[12]=r[9];
goto P_0c0a27d0;
P_0c0a27a8: /* original 6c93, guest PC 0x0c0a27a8 */
if(!s->budget--) { s->failed_pc=0x0c0a27a8u; return 0; }
r[12]=r[9];
goto P_0c0a27aa;
P_0c0a27aa: /* original 6ec3, guest PC 0x0c0a27aa */
if(!s->budget--) { s->failed_pc=0x0c0a27aau; return 0; }
r[14]=r[12];
goto P_0c0a27ac;
P_0c0a27ac: /* original 4e08, guest PC 0x0c0a27ac */
if(!s->budget--) { s->failed_pc=0x0c0a27acu; return 0; }
r[14]<<=2;
goto P_0c0a27ae;
P_0c0a27ae: /* original 3e8c, guest PC 0x0c0a27ae */
if(!s->budget--) { s->failed_pc=0x0c0a27aeu; return 0; }
r[14]+=r[8];
goto P_0c0a27b0;
P_0c0a27b0: /* original 63e2, guest PC 0x0c0a27b0 */
if(!s->budget--) { s->failed_pc=0x0c0a27b0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a27b2;
P_0c0a27b2: /* original 5231, guest PC 0x0c0a27b2 */
if(!s->budget--) { s->failed_pc=0x0c0a27b2u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a27b4;
P_0c0a27b4: /* original 22a8, guest PC 0x0c0a27b4 */
if(!s->budget--) { s->failed_pc=0x0c0a27b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c0a27b6;
P_0c0a27b6: /* original 8904, guest PC 0x0c0a27b6 */
if(!s->budget--) { s->failed_pc=0x0c0a27b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a27c2; }
goto P_0c0a27b8;
P_0c0a27b8: /* original d22b, guest PC 0x0c0a27b8 */
if(!s->budget--) { s->failed_pc=0x0c0a27b8u; return 0; }
r[2]=read(ram,0x0c0a2868u,4);
goto P_0c0a27ba;
P_0c0a27ba: /* original 420b, guest PC 0x0c0a27ba */
if(!s->budget--) { s->failed_pc=0x0c0a27bau; return 0; }
target=r[2];
r[16]=code_base|0x0c0a27beu;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a27beu) { target=s->pc; goto dispatch; }
goto P_0c0a27be;
P_0c0a27bc: /* original 64e2, guest PC 0x0c0a27bc */
if(!s->budget--) { s->failed_pc=0x0c0a27bcu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a27be;
P_0c0a27be: /* original a006, guest PC 0x0c0a27be */
if(!s->budget--) { s->failed_pc=0x0c0a27beu; return 0; }
goto P_0c0a27ce;
P_0c0a27c0: /* original 0009, guest PC 0x0c0a27c0 */
if(!s->budget--) { s->failed_pc=0x0c0a27c0u; return 0; }
goto P_0c0a27c2;
P_0c0a27c2: /* original 6be2, guest PC 0x0c0a27c2 */
if(!s->budget--) { s->failed_pc=0x0c0a27c2u; return 0; }
tmp=read(ram,r[14],4);
r[11]=tmp;
goto P_0c0a27c4;
P_0c0a27c4: /* original d229, guest PC 0x0c0a27c4 */
if(!s->budget--) { s->failed_pc=0x0c0a27c4u; return 0; }
r[2]=read(ram,0x0c0a286cu,4);
goto P_0c0a27c6;
P_0c0a27c6: /* original 55b1, guest PC 0x0c0a27c6 */
if(!s->budget--) { s->failed_pc=0x0c0a27c6u; return 0; }
r[5]=read(ram,r[11]+4,4);
goto P_0c0a27c8;
P_0c0a27c8: /* original 56b2, guest PC 0x0c0a27c8 */
if(!s->budget--) { s->failed_pc=0x0c0a27c8u; return 0; }
r[6]=read(ram,r[11]+8,4);
goto P_0c0a27ca;
P_0c0a27ca: /* original 420b, guest PC 0x0c0a27ca */
if(!s->budget--) { s->failed_pc=0x0c0a27cau; return 0; }
target=r[2];
r[16]=code_base|0x0c0a27ceu;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a27ceu) { target=s->pc; goto dispatch; }
goto P_0c0a27ce;
P_0c0a27cc: /* original 64b2, guest PC 0x0c0a27cc */
if(!s->budget--) { s->failed_pc=0x0c0a27ccu; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0a27ce;
P_0c0a27ce: /* original 7c01, guest PC 0x0c0a27ce */
if(!s->budget--) { s->failed_pc=0x0c0a27ceu; return 0; }
r[12]+=0x00000001u;
goto P_0c0a27d0;
P_0c0a27d0: /* original 85d6, guest PC 0x0c0a27d0 */
if(!s->budget--) { s->failed_pc=0x0c0a27d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+12,2);
goto P_0c0a27d2;
P_0c0a27d2: /* original 600d, guest PC 0x0c0a27d2 */
if(!s->budget--) { s->failed_pc=0x0c0a27d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a27d4;
P_0c0a27d4: /* original 3c03, guest PC 0x0c0a27d4 */
if(!s->budget--) { s->failed_pc=0x0c0a27d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0a27d6;
P_0c0a27d6: /* original 8be8, guest PC 0x0c0a27d6 */
if(!s->budget--) { s->failed_pc=0x0c0a27d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a27aa; }
goto P_0c0a27d8;
P_0c0a27d8: /* original 6593, guest PC 0x0c0a27d8 */
if(!s->budget--) { s->failed_pc=0x0c0a27d8u; return 0; }
r[5]=r[9];
goto P_0c0a27da;
P_0c0a27da: /* original 4f26, guest PC 0x0c0a27da */
if(!s->budget--) { s->failed_pc=0x0c0a27dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a27dc;
P_0c0a27dc: /* original 6053, guest PC 0x0c0a27dc */
if(!s->budget--) { s->failed_pc=0x0c0a27dcu; return 0; }
r[0]=r[5];
goto P_0c0a27de;
P_0c0a27de: /* original 68f6, guest PC 0x0c0a27de */
if(!s->budget--) { s->failed_pc=0x0c0a27deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a27e0;
P_0c0a27e0: /* original 69f6, guest PC 0x0c0a27e0 */
if(!s->budget--) { s->failed_pc=0x0c0a27e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a27e2;
P_0c0a27e2: /* original 6af6, guest PC 0x0c0a27e2 */
if(!s->budget--) { s->failed_pc=0x0c0a27e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a27e4;
P_0c0a27e4: /* original 6bf6, guest PC 0x0c0a27e4 */
if(!s->budget--) { s->failed_pc=0x0c0a27e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a27e6;
P_0c0a27e6: /* original 6cf6, guest PC 0x0c0a27e6 */
if(!s->budget--) { s->failed_pc=0x0c0a27e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a27e8;
P_0c0a27e8: /* original 6df6, guest PC 0x0c0a27e8 */
if(!s->budget--) { s->failed_pc=0x0c0a27e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a27ea;
P_0c0a27ea: /* original 000b, guest PC 0x0c0a27ea */
if(!s->budget--) { s->failed_pc=0x0c0a27eau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a27ec: /* original 6ef6, guest PC 0x0c0a27ec */
if(!s->budget--) { s->failed_pc=0x0c0a27ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a27eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a27eeu; return 0; } return 1;
P_0c0a2984: /* original 2fe6, guest PC 0x0c0a2984 */
if(!s->budget--) { s->failed_pc=0x0c0a2984u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2986;
P_0c0a2986: /* original 6e43, guest PC 0x0c0a2986 */
if(!s->budget--) { s->failed_pc=0x0c0a2986u; return 0; }
r[14]=r[4];
goto P_0c0a2988;
P_0c0a2988: /* original 2fd6, guest PC 0x0c0a2988 */
if(!s->budget--) { s->failed_pc=0x0c0a2988u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298a;
P_0c0a298a: /* original 2fc6, guest PC 0x0c0a298a */
if(!s->budget--) { s->failed_pc=0x0c0a298au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298c;
P_0c0a298c: /* original 2fb6, guest PC 0x0c0a298c */
if(!s->budget--) { s->failed_pc=0x0c0a298cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298e;
P_0c0a298e: /* original 2fa6, guest PC 0x0c0a298e */
if(!s->budget--) { s->failed_pc=0x0c0a298eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2990;
P_0c0a2990: /* original 2f96, guest PC 0x0c0a2990 */
if(!s->budget--) { s->failed_pc=0x0c0a2990u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2992;
P_0c0a2992: /* original 2f86, guest PC 0x0c0a2992 */
if(!s->budget--) { s->failed_pc=0x0c0a2992u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2994;
P_0c0a2994: /* original 4f22, guest PC 0x0c0a2994 */
if(!s->budget--) { s->failed_pc=0x0c0a2994u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2996;
P_0c0a2996: /* original 7ff8, guest PC 0x0c0a2996 */
if(!s->budget--) { s->failed_pc=0x0c0a2996u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2998;
P_0c0a2998: /* original 2f61, guest PC 0x0c0a2998 */
if(!s->budget--) { s->failed_pc=0x0c0a2998u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c0a299a;
P_0c0a299a: /* original b14c, guest PC 0x0c0a299a */
if(!s->budget--) { s->failed_pc=0x0c0a299au; return 0; }
target=code_base|0x0c0a2c36u; r[16]=code_base|0x0c0a299eu;
r[10]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a299eu) { target=s->pc; goto dispatch; }
goto P_0c0a299e;
P_0c0a299c: /* original 6a53, guest PC 0x0c0a299c */
if(!s->budget--) { s->failed_pc=0x0c0a299cu; return 0; }
r[10]=r[5];
goto P_0c0a299e;
P_0c0a299e: /* original 6403, guest PC 0x0c0a299e */
if(!s->budget--) { s->failed_pc=0x0c0a299eu; return 0; }
r[4]=r[0];
goto P_0c0a29a0;
P_0c0a29a0: /* original 2448, guest PC 0x0c0a29a0 */
if(!s->budget--) { s->failed_pc=0x0c0a29a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a29a2;
P_0c0a29a2: /* original 8902, guest PC 0x0c0a29a2 */
if(!s->budget--) { s->failed_pc=0x0c0a29a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a29aa; }
goto P_0c0a29a4;
P_0c0a29a4: /* original d375, guest PC 0x0c0a29a4 */
if(!s->budget--) { s->failed_pc=0x0c0a29a4u; return 0; }
r[3]=read(ram,0x0c0a2b7cu,4);
goto P_0c0a29a6;
P_0c0a29a6: /* original 3430, guest PC 0x0c0a29a6 */
if(!s->budget--) { s->failed_pc=0x0c0a29a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0a29a8;
P_0c0a29a8: /* original 8b59, guest PC 0x0c0a29a8 */
if(!s->budget--) { s->failed_pc=0x0c0a29a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29aa;
P_0c0a29aa: /* original e020, guest PC 0x0c0a29aa */
if(!s->budget--) { s->failed_pc=0x0c0a29aau; return 0; }
r[0]=0x00000020u;
goto P_0c0a29ac;
P_0c0a29ac: /* original 01ed, guest PC 0x0c0a29ac */
if(!s->budget--) { s->failed_pc=0x0c0a29acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ae;
P_0c0a29ae: /* original e022, guest PC 0x0c0a29ae */
if(!s->budget--) { s->failed_pc=0x0c0a29aeu; return 0; }
r[0]=0x00000022u;
goto P_0c0a29b0;
P_0c0a29b0: /* original 03ed, guest PC 0x0c0a29b0 */
if(!s->budget--) { s->failed_pc=0x0c0a29b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29b2;
P_0c0a29b2: /* original 611d, guest PC 0x0c0a29b2 */
if(!s->budget--) { s->failed_pc=0x0c0a29b2u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a29b4;
P_0c0a29b4: /* original 633d, guest PC 0x0c0a29b4 */
if(!s->budget--) { s->failed_pc=0x0c0a29b4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a29b6;
P_0c0a29b6: /* original 213b, guest PC 0x0c0a29b6 */
if(!s->budget--) { s->failed_pc=0x0c0a29b6u; return 0; }
r[1]|=r[3];
goto P_0c0a29b8;
P_0c0a29b8: /* original 2118, guest PC 0x0c0a29b8 */
if(!s->budget--) { s->failed_pc=0x0c0a29b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a29ba;
P_0c0a29ba: /* original 8b50, guest PC 0x0c0a29ba */
if(!s->budget--) { s->failed_pc=0x0c0a29bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29bc;
P_0c0a29bc: /* original e020, guest PC 0x0c0a29bc */
if(!s->budget--) { s->failed_pc=0x0c0a29bcu; return 0; }
r[0]=0x00000020u;
goto P_0c0a29be;
P_0c0a29be: /* original 52e4, guest PC 0x0c0a29be */
if(!s->budget--) { s->failed_pc=0x0c0a29beu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0a29c0;
P_0c0a29c0: /* original 1f21, guest PC 0x0c0a29c0 */
if(!s->budget--) { s->failed_pc=0x0c0a29c0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a29c2;
P_0c0a29c2: /* original 63f1, guest PC 0x0c0a29c2 */
if(!s->budget--) { s->failed_pc=0x0c0a29c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a29c4;
P_0c0a29c4: /* original 5ce5, guest PC 0x0c0a29c4 */
if(!s->budget--) { s->failed_pc=0x0c0a29c4u; return 0; }
r[12]=read(ram,r[14]+20,4);
goto P_0c0a29c6;
P_0c0a29c6: /* original 0e35, guest PC 0x0c0a29c6 */
if(!s->budget--) { s->failed_pc=0x0c0a29c6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a29c8;
P_0c0a29c8: /* original 04ed, guest PC 0x0c0a29c8 */
if(!s->budget--) { s->failed_pc=0x0c0a29c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ca;
P_0c0a29ca: /* original d36d, guest PC 0x0c0a29ca */
if(!s->budget--) { s->failed_pc=0x0c0a29cau; return 0; }
r[3]=read(ram,0x0c0a2b80u,4);
goto P_0c0a29cc;
P_0c0a29cc: /* original 430b, guest PC 0x0c0a29cc */
if(!s->budget--) { s->failed_pc=0x0c0a29ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a29d0u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a29d0u) { target=s->pc; goto dispatch; }
goto P_0c0a29d0;
P_0c0a29ce: /* original 644d, guest PC 0x0c0a29ce */
if(!s->budget--) { s->failed_pc=0x0c0a29ceu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a29d0;
P_0c0a29d0: /* original eb00, guest PC 0x0c0a29d0 */
if(!s->budget--) { s->failed_pc=0x0c0a29d0u; return 0; }
r[11]=0x00000000u;
goto P_0c0a29d2;
P_0c0a29d2: /* original a039, guest PC 0x0c0a29d2 */
if(!s->budget--) { s->failed_pc=0x0c0a29d2u; return 0; }
r[8]=r[11];
goto P_0c0a2a48;
P_0c0a29d4: /* original 68b3, guest PC 0x0c0a29d4 */
if(!s->budget--) { s->failed_pc=0x0c0a29d4u; return 0; }
r[8]=r[11];
goto P_0c0a29d6;
P_0c0a29d6: /* original 53f1, guest PC 0x0c0a29d6 */
if(!s->budget--) { s->failed_pc=0x0c0a29d6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a29d8;
P_0c0a29d8: /* original 6d83, guest PC 0x0c0a29d8 */
if(!s->budget--) { s->failed_pc=0x0c0a29d8u; return 0; }
r[13]=r[8];
goto P_0c0a29da;
P_0c0a29da: /* original 4d08, guest PC 0x0c0a29da */
if(!s->budget--) { s->failed_pc=0x0c0a29dau; return 0; }
r[13]<<=2;
goto P_0c0a29dc;
P_0c0a29dc: /* original 3d3c, guest PC 0x0c0a29dc */
if(!s->budget--) { s->failed_pc=0x0c0a29dcu; return 0; }
r[13]+=r[3];
goto P_0c0a29de;
P_0c0a29de: /* original 60d2, guest PC 0x0c0a29de */
if(!s->budget--) { s->failed_pc=0x0c0a29deu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a29e0;
P_0c0a29e0: /* original 5001, guest PC 0x0c0a29e0 */
if(!s->budget--) { s->failed_pc=0x0c0a29e0u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0a29e2;
P_0c0a29e2: /* original c801, guest PC 0x0c0a29e2 */
if(!s->budget--) { s->failed_pc=0x0c0a29e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a29e4;
P_0c0a29e4: /* original 8922, guest PC 0x0c0a29e4 */
if(!s->budget--) { s->failed_pc=0x0c0a29e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2a2c; }
goto P_0c0a29e6;
P_0c0a29e6: /* original a008, guest PC 0x0c0a29e6 */
if(!s->budget--) { s->failed_pc=0x0c0a29e6u; return 0; }
r[4]=r[11];
goto P_0c0a29fa;
P_0c0a29e8: /* original 64b3, guest PC 0x0c0a29e8 */
if(!s->budget--) { s->failed_pc=0x0c0a29e8u; return 0; }
r[4]=r[11];
goto P_0c0a29ea;
P_0c0a29ea: /* original 6343, guest PC 0x0c0a29ea */
if(!s->budget--) { s->failed_pc=0x0c0a29eau; return 0; }
r[3]=r[4];
goto P_0c0a29ec;
P_0c0a29ec: /* original 4308, guest PC 0x0c0a29ec */
if(!s->budget--) { s->failed_pc=0x0c0a29ecu; return 0; }
r[3]<<=2;
goto P_0c0a29ee;
P_0c0a29ee: /* original 4308, guest PC 0x0c0a29ee */
if(!s->budget--) { s->failed_pc=0x0c0a29eeu; return 0; }
r[3]<<=2;
goto P_0c0a29f0;
P_0c0a29f0: /* original 33cc, guest PC 0x0c0a29f0 */
if(!s->budget--) { s->failed_pc=0x0c0a29f0u; return 0; }
r[3]+=r[12];
goto P_0c0a29f2;
P_0c0a29f2: /* original 5232, guest PC 0x0c0a29f2 */
if(!s->budget--) { s->failed_pc=0x0c0a29f2u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a29f4;
P_0c0a29f4: /* original 7401, guest PC 0x0c0a29f4 */
if(!s->budget--) { s->failed_pc=0x0c0a29f4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a29f6;
P_0c0a29f6: /* original 32ac, guest PC 0x0c0a29f6 */
if(!s->budget--) { s->failed_pc=0x0c0a29f6u; return 0; }
r[2]+=r[10];
goto P_0c0a29f8;
P_0c0a29f8: /* original 1322, guest PC 0x0c0a29f8 */
if(!s->budget--) { s->failed_pc=0x0c0a29f8u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a29fa;
P_0c0a29fa: /* original 85e7, guest PC 0x0c0a29fa */
if(!s->budget--) { s->failed_pc=0x0c0a29fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a29fc;
P_0c0a29fc: /* original 600d, guest PC 0x0c0a29fc */
if(!s->budget--) { s->failed_pc=0x0c0a29fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a29fe;
P_0c0a29fe: /* original 3403, guest PC 0x0c0a29fe */
if(!s->budget--) { s->failed_pc=0x0c0a29feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a00;
P_0c0a2a00: /* original 8bf3, guest PC 0x0c0a2a00 */
if(!s->budget--) { s->failed_pc=0x0c0a2a00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29ea; }
goto P_0c0a2a02;
P_0c0a2a02: /* original d260, guest PC 0x0c0a2a02 */
if(!s->budget--) { s->failed_pc=0x0c0a2a02u; return 0; }
r[2]=read(ram,0x0c0a2b84u,4);
goto P_0c0a2a04;
P_0c0a2a04: /* original 65c3, guest PC 0x0c0a2a04 */
if(!s->budget--) { s->failed_pc=0x0c0a2a04u; return 0; }
r[5]=r[12];
goto P_0c0a2a06;
P_0c0a2a06: /* original 420b, guest PC 0x0c0a2a06 */
if(!s->budget--) { s->failed_pc=0x0c0a2a06u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2a0au;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a0au) { target=s->pc; goto dispatch; }
goto P_0c0a2a0a;
P_0c0a2a08: /* original 64d2, guest PC 0x0c0a2a08 */
if(!s->budget--) { s->failed_pc=0x0c0a2a08u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a0a;
P_0c0a2a0a: /* original 2008, guest PC 0x0c0a2a0a */
if(!s->budget--) { s->failed_pc=0x0c0a2a0au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a0c;
P_0c0a2a0c: /* original a008, guest PC 0x0c0a2a0c */
if(!s->budget--) { s->failed_pc=0x0c0a2a0cu; return 0; }
r[4]=r[11];
goto P_0c0a2a20;
P_0c0a2a0e: /* original 64b3, guest PC 0x0c0a2a0e */
if(!s->budget--) { s->failed_pc=0x0c0a2a0eu; return 0; }
r[4]=r[11];
goto P_0c0a2a10;
P_0c0a2a10: /* original 6343, guest PC 0x0c0a2a10 */
if(!s->budget--) { s->failed_pc=0x0c0a2a10u; return 0; }
r[3]=r[4];
goto P_0c0a2a12;
P_0c0a2a12: /* original 4308, guest PC 0x0c0a2a12 */
if(!s->budget--) { s->failed_pc=0x0c0a2a12u; return 0; }
r[3]<<=2;
goto P_0c0a2a14;
P_0c0a2a14: /* original 4308, guest PC 0x0c0a2a14 */
if(!s->budget--) { s->failed_pc=0x0c0a2a14u; return 0; }
r[3]<<=2;
goto P_0c0a2a16;
P_0c0a2a16: /* original 33cc, guest PC 0x0c0a2a16 */
if(!s->budget--) { s->failed_pc=0x0c0a2a16u; return 0; }
r[3]+=r[12];
goto P_0c0a2a18;
P_0c0a2a18: /* original 5232, guest PC 0x0c0a2a18 */
if(!s->budget--) { s->failed_pc=0x0c0a2a18u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2a1a;
P_0c0a2a1a: /* original 7401, guest PC 0x0c0a2a1a */
if(!s->budget--) { s->failed_pc=0x0c0a2a1au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2a1c;
P_0c0a2a1c: /* original 32a8, guest PC 0x0c0a2a1c */
if(!s->budget--) { s->failed_pc=0x0c0a2a1cu; return 0; }
r[2]-=r[10];
goto P_0c0a2a1e;
P_0c0a2a1e: /* original 1322, guest PC 0x0c0a2a1e */
if(!s->budget--) { s->failed_pc=0x0c0a2a1eu; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2a20;
P_0c0a2a20: /* original 85e7, guest PC 0x0c0a2a20 */
if(!s->budget--) { s->failed_pc=0x0c0a2a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a22;
P_0c0a2a22: /* original 600d, guest PC 0x0c0a2a22 */
if(!s->budget--) { s->failed_pc=0x0c0a2a22u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a24;
P_0c0a2a24: /* original 3403, guest PC 0x0c0a2a24 */
if(!s->budget--) { s->failed_pc=0x0c0a2a24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a26;
P_0c0a2a26: /* original 8bf3, guest PC 0x0c0a2a26 */
if(!s->budget--) { s->failed_pc=0x0c0a2a26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a10; }
goto P_0c0a2a28;
P_0c0a2a28: /* original a00d, guest PC 0x0c0a2a28 */
if(!s->budget--) { s->failed_pc=0x0c0a2a28u; return 0; }
goto P_0c0a2a46;
P_0c0a2a2a: /* original 0009, guest PC 0x0c0a2a2a */
if(!s->budget--) { s->failed_pc=0x0c0a2a2au; return 0; }
goto P_0c0a2a2c;
P_0c0a2a2c: /* original 64d2, guest PC 0x0c0a2a2c */
if(!s->budget--) { s->failed_pc=0x0c0a2a2cu; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a2e;
P_0c0a2a2e: /* original 66a3, guest PC 0x0c0a2a2e */
if(!s->budget--) { s->failed_pc=0x0c0a2a2eu; return 0; }
r[6]=r[10];
goto P_0c0a2a30;
P_0c0a2a30: /* original d355, guest PC 0x0c0a2a30 */
if(!s->budget--) { s->failed_pc=0x0c0a2a30u; return 0; }
r[3]=read(ram,0x0c0a2b88u,4);
goto P_0c0a2a32;
P_0c0a2a32: /* original 65c3, guest PC 0x0c0a2a32 */
if(!s->budget--) { s->failed_pc=0x0c0a2a32u; return 0; }
r[5]=r[12];
goto P_0c0a2a34;
P_0c0a2a34: /* original 430b, guest PC 0x0c0a2a34 */
if(!s->budget--) { s->failed_pc=0x0c0a2a34u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a38u;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a38u) { target=s->pc; goto dispatch; }
goto P_0c0a2a38;
P_0c0a2a36: /* original 5441, guest PC 0x0c0a2a36 */
if(!s->budget--) { s->failed_pc=0x0c0a2a36u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2a38;
P_0c0a2a38: /* original 69d2, guest PC 0x0c0a2a38 */
if(!s->budget--) { s->failed_pc=0x0c0a2a38u; return 0; }
tmp=read(ram,r[13],4);
r[9]=tmp;
goto P_0c0a2a3a;
P_0c0a2a3a: /* original 2008, guest PC 0x0c0a2a3a */
if(!s->budget--) { s->failed_pc=0x0c0a2a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a3c;
P_0c0a2a3c: /* original d353, guest PC 0x0c0a2a3c */
if(!s->budget--) { s->failed_pc=0x0c0a2a3cu; return 0; }
r[3]=read(ram,0x0c0a2b8cu,4);
goto P_0c0a2a3e;
P_0c0a2a3e: /* original 5591, guest PC 0x0c0a2a3e */
if(!s->budget--) { s->failed_pc=0x0c0a2a3eu; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0a2a40;
P_0c0a2a40: /* original 5692, guest PC 0x0c0a2a40 */
if(!s->budget--) { s->failed_pc=0x0c0a2a40u; return 0; }
r[6]=read(ram,r[9]+8,4);
goto P_0c0a2a42;
P_0c0a2a42: /* original 430b, guest PC 0x0c0a2a42 */
if(!s->budget--) { s->failed_pc=0x0c0a2a42u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a46u;
tmp=read(ram,r[9],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a46u) { target=s->pc; goto dispatch; }
goto P_0c0a2a46;
P_0c0a2a44: /* original 6492, guest PC 0x0c0a2a44 */
if(!s->budget--) { s->failed_pc=0x0c0a2a44u; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0a2a46;
P_0c0a2a46: /* original 7801, guest PC 0x0c0a2a46 */
if(!s->budget--) { s->failed_pc=0x0c0a2a46u; return 0; }
r[8]+=0x00000001u;
goto P_0c0a2a48;
P_0c0a2a48: /* original 85e6, guest PC 0x0c0a2a48 */
if(!s->budget--) { s->failed_pc=0x0c0a2a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2a4a;
P_0c0a2a4a: /* original 600d, guest PC 0x0c0a2a4a */
if(!s->budget--) { s->failed_pc=0x0c0a2a4au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a4c;
P_0c0a2a4c: /* original 3803, guest PC 0x0c0a2a4c */
if(!s->budget--) { s->failed_pc=0x0c0a2a4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[0])!=0);
goto P_0c0a2a4e;
P_0c0a2a4e: /* original 8bc2, guest PC 0x0c0a2a4e */
if(!s->budget--) { s->failed_pc=0x0c0a2a4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29d6; }
goto P_0c0a2a50;
P_0c0a2a50: /* original 63f1, guest PC 0x0c0a2a50 */
if(!s->budget--) { s->failed_pc=0x0c0a2a50u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2a52;
P_0c0a2a52: /* original e222, guest PC 0x0c0a2a52 */
if(!s->budget--) { s->failed_pc=0x0c0a2a52u; return 0; }
r[2]=0x00000022u;
goto P_0c0a2a54;
P_0c0a2a54: /* original 85e7, guest PC 0x0c0a2a54 */
if(!s->budget--) { s->failed_pc=0x0c0a2a54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a56;
P_0c0a2a56: /* original 32ec, guest PC 0x0c0a2a56 */
if(!s->budget--) { s->failed_pc=0x0c0a2a56u; return 0; }
r[2]+=r[14];
goto P_0c0a2a58;
P_0c0a2a58: /* original 64b3, guest PC 0x0c0a2a58 */
if(!s->budget--) { s->failed_pc=0x0c0a2a58u; return 0; }
r[4]=r[11];
goto P_0c0a2a5a;
P_0c0a2a5a: /* original 303c, guest PC 0x0c0a2a5a */
if(!s->budget--) { s->failed_pc=0x0c0a2a5au; return 0; }
r[0]+=r[3];
goto P_0c0a2a5c;
P_0c0a2a5c: /* original 2201, guest PC 0x0c0a2a5c */
if(!s->budget--) { s->failed_pc=0x0c0a2a5cu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a2a5e;
P_0c0a2a5e: /* original 7f08, guest PC 0x0c0a2a5e */
if(!s->budget--) { s->failed_pc=0x0c0a2a5eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a2a60;
P_0c0a2a60: /* original 6043, guest PC 0x0c0a2a60 */
if(!s->budget--) { s->failed_pc=0x0c0a2a60u; return 0; }
r[0]=r[4];
goto P_0c0a2a62;
P_0c0a2a62: /* original 4f26, guest PC 0x0c0a2a62 */
if(!s->budget--) { s->failed_pc=0x0c0a2a62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2a64;
P_0c0a2a64: /* original 68f6, guest PC 0x0c0a2a64 */
if(!s->budget--) { s->failed_pc=0x0c0a2a64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2a66;
P_0c0a2a66: /* original 69f6, guest PC 0x0c0a2a66 */
if(!s->budget--) { s->failed_pc=0x0c0a2a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2a68;
P_0c0a2a68: /* original 6af6, guest PC 0x0c0a2a68 */
if(!s->budget--) { s->failed_pc=0x0c0a2a68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2a6a;
P_0c0a2a6a: /* original 6bf6, guest PC 0x0c0a2a6a */
if(!s->budget--) { s->failed_pc=0x0c0a2a6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2a6c;
P_0c0a2a6c: /* original 6cf6, guest PC 0x0c0a2a6c */
if(!s->budget--) { s->failed_pc=0x0c0a2a6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2a6e;
P_0c0a2a6e: /* original 6df6, guest PC 0x0c0a2a6e */
if(!s->budget--) { s->failed_pc=0x0c0a2a6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2a70;
P_0c0a2a70: /* original 000b, guest PC 0x0c0a2a70 */
if(!s->budget--) { s->failed_pc=0x0c0a2a70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2a72: /* original 6ef6, guest PC 0x0c0a2a72 */
if(!s->budget--) { s->failed_pc=0x0c0a2a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a2a74u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
