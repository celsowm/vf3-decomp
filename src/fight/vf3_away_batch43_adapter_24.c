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
int vf3_away_batch43_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0a24a6u: goto P_0c0a24a6;
case 0x0c0a24a8u: goto P_0c0a24a8;
case 0x0c0a24aau: goto P_0c0a24aa;
case 0x0c0a24acu: goto P_0c0a24ac;
case 0x0c0a24aeu: goto P_0c0a24ae;
case 0x0c0a24b0u: goto P_0c0a24b0;
case 0x0c0a24b2u: goto P_0c0a24b2;
case 0x0c0a24b4u: goto P_0c0a24b4;
case 0x0c0a24b6u: goto P_0c0a24b6;
case 0x0c0a24b8u: goto P_0c0a24b8;
case 0x0c0a24bau: goto P_0c0a24ba;
case 0x0c0a24bcu: goto P_0c0a24bc;
case 0x0c0a24beu: goto P_0c0a24be;
case 0x0c0a24c0u: goto P_0c0a24c0;
case 0x0c0a24c2u: goto P_0c0a24c2;
case 0x0c0a24c4u: goto P_0c0a24c4;
case 0x0c0a24c6u: goto P_0c0a24c6;
case 0x0c0a24c8u: goto P_0c0a24c8;
case 0x0c0a24cau: goto P_0c0a24ca;
case 0x0c0a24ccu: goto P_0c0a24cc;
case 0x0c0a24ceu: goto P_0c0a24ce;
case 0x0c0a24d0u: goto P_0c0a24d0;
case 0x0c0a24d2u: goto P_0c0a24d2;
case 0x0c0a24d4u: goto P_0c0a24d4;
case 0x0c0a24d6u: goto P_0c0a24d6;
case 0x0c0a24d8u: goto P_0c0a24d8;
case 0x0c0a24dau: goto P_0c0a24da;
case 0x0c0a24dcu: goto P_0c0a24dc;
case 0x0c0a24deu: goto P_0c0a24de;
case 0x0c0a24e0u: goto P_0c0a24e0;
case 0x0c0a24e2u: goto P_0c0a24e2;
case 0x0c0a24e4u: goto P_0c0a24e4;
case 0x0c0a24e6u: goto P_0c0a24e6;
case 0x0c0a2514u: goto P_0c0a2514;
case 0x0c0a2516u: goto P_0c0a2516;
case 0x0c0a2518u: goto P_0c0a2518;
case 0x0c0a251au: goto P_0c0a251a;
case 0x0c0a251cu: goto P_0c0a251c;
case 0x0c0a251eu: goto P_0c0a251e;
case 0x0c0a2520u: goto P_0c0a2520;
case 0x0c0a2522u: goto P_0c0a2522;
case 0x0c0a2524u: goto P_0c0a2524;
case 0x0c0a2526u: goto P_0c0a2526;
case 0x0c0a2528u: goto P_0c0a2528;
case 0x0c0a252au: goto P_0c0a252a;
case 0x0c0a252cu: goto P_0c0a252c;
case 0x0c0a252eu: goto P_0c0a252e;
case 0x0c0a2530u: goto P_0c0a2530;
case 0x0c0a2532u: goto P_0c0a2532;
case 0x0c0a2534u: goto P_0c0a2534;
case 0x0c0a2536u: goto P_0c0a2536;
case 0x0c0a2538u: goto P_0c0a2538;
case 0x0c0a253au: goto P_0c0a253a;
case 0x0c0a253cu: goto P_0c0a253c;
case 0x0c0a253eu: goto P_0c0a253e;
case 0x0c0a2540u: goto P_0c0a2540;
case 0x0c0a2542u: goto P_0c0a2542;
case 0x0c0a2544u: goto P_0c0a2544;
case 0x0c0a2546u: goto P_0c0a2546;
case 0x0c0a2548u: goto P_0c0a2548;
case 0x0c0a254au: goto P_0c0a254a;
case 0x0c0a254cu: goto P_0c0a254c;
case 0x0c0a254eu: goto P_0c0a254e;
case 0x0c0a2550u: goto P_0c0a2550;
case 0x0c0a2552u: goto P_0c0a2552;
case 0x0c0a2554u: goto P_0c0a2554;
case 0x0c0a2556u: goto P_0c0a2556;
case 0x0c0a2558u: goto P_0c0a2558;
case 0x0c0a255au: goto P_0c0a255a;
case 0x0c0a255cu: goto P_0c0a255c;
case 0x0c0a255eu: goto P_0c0a255e;
case 0x0c0a2560u: goto P_0c0a2560;
case 0x0c0a2562u: goto P_0c0a2562;
case 0x0c0a2564u: goto P_0c0a2564;
case 0x0c0a2566u: goto P_0c0a2566;
case 0x0c0a2568u: goto P_0c0a2568;
case 0x0c0a256au: goto P_0c0a256a;
case 0x0c0a256cu: goto P_0c0a256c;
case 0x0c0a256eu: goto P_0c0a256e;
case 0x0c0a2570u: goto P_0c0a2570;
case 0x0c0a2572u: goto P_0c0a2572;
case 0x0c0a2574u: goto P_0c0a2574;
case 0x0c0a2576u: goto P_0c0a2576;
case 0x0c0a2578u: goto P_0c0a2578;
case 0x0c0a257au: goto P_0c0a257a;
case 0x0c0a257cu: goto P_0c0a257c;
case 0x0c0a257eu: goto P_0c0a257e;
case 0x0c0a2580u: goto P_0c0a2580;
case 0x0c0a2582u: goto P_0c0a2582;
case 0x0c0a2584u: goto P_0c0a2584;
case 0x0c0a2586u: goto P_0c0a2586;
case 0x0c0a2588u: goto P_0c0a2588;
case 0x0c0a258au: goto P_0c0a258a;
case 0x0c0a258cu: goto P_0c0a258c;
case 0x0c0a258eu: goto P_0c0a258e;
case 0x0c0a2590u: goto P_0c0a2590;
case 0x0c0a2592u: goto P_0c0a2592;
case 0x0c0a2594u: goto P_0c0a2594;
case 0x0c0a2596u: goto P_0c0a2596;
case 0x0c0a2598u: goto P_0c0a2598;
case 0x0c0a259au: goto P_0c0a259a;
case 0x0c0a259cu: goto P_0c0a259c;
case 0x0c0a259eu: goto P_0c0a259e;
case 0x0c0a25a0u: goto P_0c0a25a0;
case 0x0c0a25a2u: goto P_0c0a25a2;
case 0x0c0a25a4u: goto P_0c0a25a4;
case 0x0c0a25a6u: goto P_0c0a25a6;
case 0x0c0a25a8u: goto P_0c0a25a8;
case 0x0c0a25aau: goto P_0c0a25aa;
case 0x0c0a25acu: goto P_0c0a25ac;
case 0x0c0a25aeu: goto P_0c0a25ae;
case 0x0c0a25b0u: goto P_0c0a25b0;
case 0x0c0a25b2u: goto P_0c0a25b2;
case 0x0c0a25b4u: goto P_0c0a25b4;
case 0x0c0a25b6u: goto P_0c0a25b6;
case 0x0c0a25b8u: goto P_0c0a25b8;
case 0x0c0a25bau: goto P_0c0a25ba;
case 0x0c0a25bcu: goto P_0c0a25bc;
case 0x0c0a25beu: goto P_0c0a25be;
case 0x0c0a25c0u: goto P_0c0a25c0;
case 0x0c0a25c2u: goto P_0c0a25c2;
case 0x0c0a25c4u: goto P_0c0a25c4;
case 0x0c0a25c6u: goto P_0c0a25c6;
case 0x0c0a25c8u: goto P_0c0a25c8;
case 0x0c0a25cau: goto P_0c0a25ca;
case 0x0c0a25ccu: goto P_0c0a25cc;
case 0x0c0a25ceu: goto P_0c0a25ce;
case 0x0c0a25d0u: goto P_0c0a25d0;
case 0x0c0a25d2u: goto P_0c0a25d2;
case 0x0c0a25d4u: goto P_0c0a25d4;
case 0x0c0a25d6u: goto P_0c0a25d6;
case 0x0c0a25d8u: goto P_0c0a25d8;
case 0x0c0a25dau: goto P_0c0a25da;
case 0x0c0a25dcu: goto P_0c0a25dc;
case 0x0c0a25deu: goto P_0c0a25de;
case 0x0c0a25e0u: goto P_0c0a25e0;
case 0x0c0a25e2u: goto P_0c0a25e2;
case 0x0c0a25e4u: goto P_0c0a25e4;
case 0x0c0a25e6u: goto P_0c0a25e6;
case 0x0c0a25e8u: goto P_0c0a25e8;
case 0x0c0a25eau: goto P_0c0a25ea;
case 0x0c0a25ecu: goto P_0c0a25ec;
case 0x0c0a25eeu: goto P_0c0a25ee;
case 0x0c0a25f0u: goto P_0c0a25f0;
case 0x0c0a25f2u: goto P_0c0a25f2;
case 0x0c0a25f4u: goto P_0c0a25f4;
case 0x0c0a25f6u: goto P_0c0a25f6;
case 0x0c0a25f8u: goto P_0c0a25f8;
case 0x0c0a25fau: goto P_0c0a25fa;
case 0x0c0a25fcu: goto P_0c0a25fc;
case 0x0c0a25feu: goto P_0c0a25fe;
case 0x0c0a2600u: goto P_0c0a2600;
case 0x0c0a2602u: goto P_0c0a2602;
case 0x0c0a2604u: goto P_0c0a2604;
case 0x0c0a2606u: goto P_0c0a2606;
case 0x0c0a2608u: goto P_0c0a2608;
case 0x0c0a260au: goto P_0c0a260a;
case 0x0c0a260cu: goto P_0c0a260c;
case 0x0c0a260eu: goto P_0c0a260e;
case 0x0c0a2670u: goto P_0c0a2670;
case 0x0c0a2672u: goto P_0c0a2672;
case 0x0c0a2674u: goto P_0c0a2674;
case 0x0c0a2676u: goto P_0c0a2676;
case 0x0c0a2678u: goto P_0c0a2678;
case 0x0c0a267au: goto P_0c0a267a;
case 0x0c0a267cu: goto P_0c0a267c;
case 0x0c0a267eu: goto P_0c0a267e;
case 0x0c0a2680u: goto P_0c0a2680;
case 0x0c0a2682u: goto P_0c0a2682;
case 0x0c0a2684u: goto P_0c0a2684;
case 0x0c0a2686u: goto P_0c0a2686;
case 0x0c0a2688u: goto P_0c0a2688;
case 0x0c0a268au: goto P_0c0a268a;
case 0x0c0a268cu: goto P_0c0a268c;
case 0x0c0a268eu: goto P_0c0a268e;
case 0x0c0a2690u: goto P_0c0a2690;
case 0x0c0a2692u: goto P_0c0a2692;
case 0x0c0a2694u: goto P_0c0a2694;
case 0x0c0a2696u: goto P_0c0a2696;
case 0x0c0a2698u: goto P_0c0a2698;
case 0x0c0a269au: goto P_0c0a269a;
case 0x0c0a269cu: goto P_0c0a269c;
case 0x0c0a269eu: goto P_0c0a269e;
case 0x0c0a26a0u: goto P_0c0a26a0;
case 0x0c0a26a2u: goto P_0c0a26a2;
case 0x0c0a26a4u: goto P_0c0a26a4;
case 0x0c0a26a6u: goto P_0c0a26a6;
case 0x0c0a26a8u: goto P_0c0a26a8;
case 0x0c0a26aau: goto P_0c0a26aa;
case 0x0c0a26acu: goto P_0c0a26ac;
case 0x0c0a26aeu: goto P_0c0a26ae;
case 0x0c0a26b0u: goto P_0c0a26b0;
case 0x0c0a26b2u: goto P_0c0a26b2;
case 0x0c0a26b4u: goto P_0c0a26b4;
case 0x0c0a26b6u: goto P_0c0a26b6;
case 0x0c0a26b8u: goto P_0c0a26b8;
case 0x0c0a26bau: goto P_0c0a26ba;
case 0x0c0a26bcu: goto P_0c0a26bc;
case 0x0c0a26beu: goto P_0c0a26be;
case 0x0c0a26c0u: goto P_0c0a26c0;
case 0x0c0a26c2u: goto P_0c0a26c2;
case 0x0c0a26c4u: goto P_0c0a26c4;
case 0x0c0a26c6u: goto P_0c0a26c6;
case 0x0c0a26c8u: goto P_0c0a26c8;
case 0x0c0a26cau: goto P_0c0a26ca;
case 0x0c0a26ccu: goto P_0c0a26cc;
case 0x0c0a26ceu: goto P_0c0a26ce;
case 0x0c0a26d0u: goto P_0c0a26d0;
case 0x0c0a26d2u: goto P_0c0a26d2;
case 0x0c0a26d4u: goto P_0c0a26d4;
case 0x0c0a26d6u: goto P_0c0a26d6;
case 0x0c0a26d8u: goto P_0c0a26d8;
case 0x0c0a26dau: goto P_0c0a26da;
case 0x0c0a26dcu: goto P_0c0a26dc;
case 0x0c0a26deu: goto P_0c0a26de;
case 0x0c0a26e0u: goto P_0c0a26e0;
case 0x0c0a26e2u: goto P_0c0a26e2;
case 0x0c0a26e4u: goto P_0c0a26e4;
case 0x0c0a26e6u: goto P_0c0a26e6;
case 0x0c0a26e8u: goto P_0c0a26e8;
case 0x0c0a26eau: goto P_0c0a26ea;
case 0x0c0a26ecu: goto P_0c0a26ec;
case 0x0c0a26eeu: goto P_0c0a26ee;
case 0x0c0a26f0u: goto P_0c0a26f0;
case 0x0c0a26f2u: goto P_0c0a26f2;
case 0x0c0a26f4u: goto P_0c0a26f4;
case 0x0c0a26f6u: goto P_0c0a26f6;
case 0x0c0a26f8u: goto P_0c0a26f8;
case 0x0c0a26fau: goto P_0c0a26fa;
case 0x0c0a26fcu: goto P_0c0a26fc;
case 0x0c0a26feu: goto P_0c0a26fe;
case 0x0c0a2700u: goto P_0c0a2700;
case 0x0c0a2702u: goto P_0c0a2702;
case 0x0c0a2704u: goto P_0c0a2704;
case 0x0c0a2706u: goto P_0c0a2706;
case 0x0c0a2708u: goto P_0c0a2708;
case 0x0c0a270au: goto P_0c0a270a;
case 0x0c0a7f5au: goto P_0c0a7f5a;
case 0x0c0a7f5cu: goto P_0c0a7f5c;
case 0x0c0a7f5eu: goto P_0c0a7f5e;
case 0x0c0a7f60u: goto P_0c0a7f60;
case 0x0c0a7f62u: goto P_0c0a7f62;
case 0x0c0a7f64u: goto P_0c0a7f64;
case 0x0c0a7f66u: goto P_0c0a7f66;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0a24a6: /* original 2fe6, guest PC 0x0c0a24a6 */
if(!s->budget--) { s->failed_pc=0x0c0a24a6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a24a8;
P_0c0a24a8: /* original 4f22, guest PC 0x0c0a24a8 */
if(!s->budget--) { s->failed_pc=0x0c0a24a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a24aa;
P_0c0a24aa: /* original bd51, guest PC 0x0c0a24aa */
if(!s->budget--) { s->failed_pc=0x0c0a24aau; return 0; }
target=code_base|0x0c0a1f50u; r[16]=code_base|0x0c0a24aeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a24aeu) { target=s->pc; goto dispatch; }
goto P_0c0a24ae;
P_0c0a24ac: /* original 0009, guest PC 0x0c0a24ac */
if(!s->budget--) { s->failed_pc=0x0c0a24acu; return 0; }
goto P_0c0a24ae;
P_0c0a24ae: /* original 6e03, guest PC 0x0c0a24ae */
if(!s->budget--) { s->failed_pc=0x0c0a24aeu; return 0; }
r[14]=r[0];
goto P_0c0a24b0;
P_0c0a24b0: /* original 2ee8, guest PC 0x0c0a24b0 */
if(!s->budget--) { s->failed_pc=0x0c0a24b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a24b2;
P_0c0a24b2: /* original 8915, guest PC 0x0c0a24b2 */
if(!s->budget--) { s->failed_pc=0x0c0a24b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a24e0; }
goto P_0c0a24b4;
P_0c0a24b4: /* original 60e3, guest PC 0x0c0a24b4 */
if(!s->budget--) { s->failed_pc=0x0c0a24b4u; return 0; }
r[0]=r[14];
goto P_0c0a24b6;
P_0c0a24b6: /* original 8804, guest PC 0x0c0a24b6 */
if(!s->budget--) { s->failed_pc=0x0c0a24b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0a24b8;
P_0c0a24b8: /* original 8b03, guest PC 0x0c0a24b8 */
if(!s->budget--) { s->failed_pc=0x0c0a24b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a24c2; }
goto P_0c0a24ba;
P_0c0a24ba: /* original b05b, guest PC 0x0c0a24ba */
if(!s->budget--) { s->failed_pc=0x0c0a24bau; return 0; }
target=code_base|0x0c0a2574u; r[16]=code_base|0x0c0a24beu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a24beu) { target=s->pc; goto dispatch; }
goto P_0c0a24be;
P_0c0a24bc: /* original 0009, guest PC 0x0c0a24bc */
if(!s->budget--) { s->failed_pc=0x0c0a24bcu; return 0; }
goto P_0c0a24be;
P_0c0a24be: /* original a00b, guest PC 0x0c0a24be */
if(!s->budget--) { s->failed_pc=0x0c0a24beu; return 0; }
goto P_0c0a24d8;
P_0c0a24c0: /* original 0009, guest PC 0x0c0a24c0 */
if(!s->budget--) { s->failed_pc=0x0c0a24c0u; return 0; }
goto P_0c0a24c2;
P_0c0a24c2: /* original 8802, guest PC 0x0c0a24c2 */
if(!s->budget--) { s->failed_pc=0x0c0a24c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a24c4;
P_0c0a24c4: /* original 8b03, guest PC 0x0c0a24c4 */
if(!s->budget--) { s->failed_pc=0x0c0a24c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a24ce; }
goto P_0c0a24c6;
P_0c0a24c6: /* original b025, guest PC 0x0c0a24c6 */
if(!s->budget--) { s->failed_pc=0x0c0a24c6u; return 0; }
target=code_base|0x0c0a2514u; r[16]=code_base|0x0c0a24cau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a24cau) { target=s->pc; goto dispatch; }
goto P_0c0a24ca;
P_0c0a24c8: /* original 0009, guest PC 0x0c0a24c8 */
if(!s->budget--) { s->failed_pc=0x0c0a24c8u; return 0; }
goto P_0c0a24ca;
P_0c0a24ca: /* original a005, guest PC 0x0c0a24ca */
if(!s->budget--) { s->failed_pc=0x0c0a24cau; return 0; }
goto P_0c0a24d8;
P_0c0a24cc: /* original 0009, guest PC 0x0c0a24cc */
if(!s->budget--) { s->failed_pc=0x0c0a24ccu; return 0; }
goto P_0c0a24ce;
P_0c0a24ce: /* original 60e3, guest PC 0x0c0a24ce */
if(!s->budget--) { s->failed_pc=0x0c0a24ceu; return 0; }
r[0]=r[14];
goto P_0c0a24d0;
P_0c0a24d0: /* original 8808, guest PC 0x0c0a24d0 */
if(!s->budget--) { s->failed_pc=0x0c0a24d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0a24d2;
P_0c0a24d2: /* original 8b05, guest PC 0x0c0a24d2 */
if(!s->budget--) { s->failed_pc=0x0c0a24d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a24e0; }
goto P_0c0a24d4;
P_0c0a24d4: /* original b0cc, guest PC 0x0c0a24d4 */
if(!s->budget--) { s->failed_pc=0x0c0a24d4u; return 0; }
target=code_base|0x0c0a2670u; r[16]=code_base|0x0c0a24d8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a24d8u) { target=s->pc; goto dispatch; }
goto P_0c0a24d8;
P_0c0a24d6: /* original 0009, guest PC 0x0c0a24d6 */
if(!s->budget--) { s->failed_pc=0x0c0a24d6u; return 0; }
goto P_0c0a24d8;
P_0c0a24d8: /* original 4f26, guest PC 0x0c0a24d8 */
if(!s->budget--) { s->failed_pc=0x0c0a24d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a24da;
P_0c0a24da: /* original 60e3, guest PC 0x0c0a24da */
if(!s->budget--) { s->failed_pc=0x0c0a24dau; return 0; }
r[0]=r[14];
goto P_0c0a24dc;
P_0c0a24dc: /* original 000b, guest PC 0x0c0a24dc */
if(!s->budget--) { s->failed_pc=0x0c0a24dcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a24de: /* original 6ef6, guest PC 0x0c0a24de */
if(!s->budget--) { s->failed_pc=0x0c0a24deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a24e0;
P_0c0a24e0: /* original e000, guest PC 0x0c0a24e0 */
if(!s->budget--) { s->failed_pc=0x0c0a24e0u; return 0; }
r[0]=0x00000000u;
goto P_0c0a24e2;
P_0c0a24e2: /* original 4f26, guest PC 0x0c0a24e2 */
if(!s->budget--) { s->failed_pc=0x0c0a24e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a24e4;
P_0c0a24e4: /* original 000b, guest PC 0x0c0a24e4 */
if(!s->budget--) { s->failed_pc=0x0c0a24e4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a24e6: /* original 6ef6, guest PC 0x0c0a24e6 */
if(!s->budget--) { s->failed_pc=0x0c0a24e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a24e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a24e8u; return 0; } return 1;
P_0c0a2514: /* original 2fe6, guest PC 0x0c0a2514 */
if(!s->budget--) { s->failed_pc=0x0c0a2514u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2516;
P_0c0a2516: /* original 2fd6, guest PC 0x0c0a2516 */
if(!s->budget--) { s->failed_pc=0x0c0a2516u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2518;
P_0c0a2518: /* original 4f22, guest PC 0x0c0a2518 */
if(!s->budget--) { s->failed_pc=0x0c0a2518u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a251a;
P_0c0a251a: /* original d341, guest PC 0x0c0a251a */
if(!s->budget--) { s->failed_pc=0x0c0a251au; return 0; }
r[3]=read(ram,0x0c0a2620u,4);
goto P_0c0a251c;
P_0c0a251c: /* original 430b, guest PC 0x0c0a251c */
if(!s->budget--) { s->failed_pc=0x0c0a251cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2520u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2520u) { target=s->pc; goto dispatch; }
goto P_0c0a2520;
P_0c0a251e: /* original 0009, guest PC 0x0c0a251e */
if(!s->budget--) { s->failed_pc=0x0c0a251eu; return 0; }
goto P_0c0a2520;
P_0c0a2520: /* original d240, guest PC 0x0c0a2520 */
if(!s->budget--) { s->failed_pc=0x0c0a2520u; return 0; }
r[2]=read(ram,0x0c0a2624u,4);
goto P_0c0a2522;
P_0c0a2522: /* original 420b, guest PC 0x0c0a2522 */
if(!s->budget--) { s->failed_pc=0x0c0a2522u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2526u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2526u) { target=s->pc; goto dispatch; }
goto P_0c0a2526;
P_0c0a2524: /* original e400, guest PC 0x0c0a2524 */
if(!s->budget--) { s->failed_pc=0x0c0a2524u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2526;
P_0c0a2526: /* original d340, guest PC 0x0c0a2526 */
if(!s->budget--) { s->failed_pc=0x0c0a2526u; return 0; }
r[3]=read(ram,0x0c0a2628u,4);
goto P_0c0a2528;
P_0c0a2528: /* original 430b, guest PC 0x0c0a2528 */
if(!s->budget--) { s->failed_pc=0x0c0a2528u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a252cu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a252cu) { target=s->pc; goto dispatch; }
goto P_0c0a252c;
P_0c0a252a: /* original e401, guest PC 0x0c0a252a */
if(!s->budget--) { s->failed_pc=0x0c0a252au; return 0; }
r[4]=0x00000001u;
goto P_0c0a252c;
P_0c0a252c: /* original d23f, guest PC 0x0c0a252c */
if(!s->budget--) { s->failed_pc=0x0c0a252cu; return 0; }
r[2]=read(ram,0x0c0a262cu,4);
goto P_0c0a252e;
P_0c0a252e: /* original 420b, guest PC 0x0c0a252e */
if(!s->budget--) { s->failed_pc=0x0c0a252eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2532u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2532u) { target=s->pc; goto dispatch; }
goto P_0c0a2532;
P_0c0a2530: /* original e400, guest PC 0x0c0a2530 */
if(!s->budget--) { s->failed_pc=0x0c0a2530u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2532;
P_0c0a2532: /* original d33f, guest PC 0x0c0a2532 */
if(!s->budget--) { s->failed_pc=0x0c0a2532u; return 0; }
r[3]=read(ram,0x0c0a2630u,4);
goto P_0c0a2534;
P_0c0a2534: /* original e500, guest PC 0x0c0a2534 */
if(!s->budget--) { s->failed_pc=0x0c0a2534u; return 0; }
r[5]=0x00000000u;
goto P_0c0a2536;
P_0c0a2536: /* original 430b, guest PC 0x0c0a2536 */
if(!s->budget--) { s->failed_pc=0x0c0a2536u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a253au;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a253au) { target=s->pc; goto dispatch; }
goto P_0c0a253a;
P_0c0a2538: /* original e403, guest PC 0x0c0a2538 */
if(!s->budget--) { s->failed_pc=0x0c0a2538u; return 0; }
r[4]=0x00000003u;
goto P_0c0a253a;
P_0c0a253a: /* original 9569, guest PC 0x0c0a253a */
if(!s->budget--) { s->failed_pc=0x0c0a253au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2610u,2);
goto P_0c0a253c;
P_0c0a253c: /* original de3d, guest PC 0x0c0a253c */
if(!s->budget--) { s->failed_pc=0x0c0a253cu; return 0; }
r[14]=read(ram,0x0c0a2634u,4);
goto P_0c0a253e;
P_0c0a253e: /* original 4e0b, guest PC 0x0c0a253e */
if(!s->budget--) { s->failed_pc=0x0c0a253eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2542u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2542u) { target=s->pc; goto dispatch; }
goto P_0c0a2542;
P_0c0a2540: /* original e410, guest PC 0x0c0a2540 */
if(!s->budget--) { s->failed_pc=0x0c0a2540u; return 0; }
r[4]=0x00000010u;
goto P_0c0a2542;
P_0c0a2542: /* original d23e, guest PC 0x0c0a2542 */
if(!s->budget--) { s->failed_pc=0x0c0a2542u; return 0; }
r[2]=read(ram,0x0c0a263cu,4);
goto P_0c0a2544;
P_0c0a2544: /* original dd3c, guest PC 0x0c0a2544 */
if(!s->budget--) { s->failed_pc=0x0c0a2544u; return 0; }
r[13]=read(ram,0x0c0a2638u,4);
goto P_0c0a2546;
P_0c0a2546: /* original 4d0b, guest PC 0x0c0a2546 */
if(!s->budget--) { s->failed_pc=0x0c0a2546u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a254au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a254au) { target=s->pc; goto dispatch; }
goto P_0c0a254a;
P_0c0a2548: /* original 2f26, guest PC 0x0c0a2548 */
if(!s->budget--) { s->failed_pc=0x0c0a2548u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a254a;
P_0c0a254a: /* original 9562, guest PC 0x0c0a254a */
if(!s->budget--) { s->failed_pc=0x0c0a254au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2612u,2);
goto P_0c0a254c;
P_0c0a254c: /* original 4e0b, guest PC 0x0c0a254c */
if(!s->budget--) { s->failed_pc=0x0c0a254cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2550u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2550u) { target=s->pc; goto dispatch; }
goto P_0c0a2550;
P_0c0a254e: /* original e410, guest PC 0x0c0a254e */
if(!s->budget--) { s->failed_pc=0x0c0a254eu; return 0; }
r[4]=0x00000010u;
goto P_0c0a2550;
P_0c0a2550: /* original d33b, guest PC 0x0c0a2550 */
if(!s->budget--) { s->failed_pc=0x0c0a2550u; return 0; }
r[3]=read(ram,0x0c0a2640u,4);
goto P_0c0a2552;
P_0c0a2552: /* original 4d0b, guest PC 0x0c0a2552 */
if(!s->budget--) { s->failed_pc=0x0c0a2552u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2556u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2556u) { target=s->pc; goto dispatch; }
goto P_0c0a2556;
P_0c0a2554: /* original 2f36, guest PC 0x0c0a2554 */
if(!s->budget--) { s->failed_pc=0x0c0a2554u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2556;
P_0c0a2556: /* original 955c, guest PC 0x0c0a2556 */
if(!s->budget--) { s->failed_pc=0x0c0a2556u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2612u,2);
goto P_0c0a2558;
P_0c0a2558: /* original 4e0b, guest PC 0x0c0a2558 */
if(!s->budget--) { s->failed_pc=0x0c0a2558u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a255cu;
r[4]=0x00000011u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a255cu) { target=s->pc; goto dispatch; }
goto P_0c0a255c;
P_0c0a255a: /* original e411, guest PC 0x0c0a255a */
if(!s->budget--) { s->failed_pc=0x0c0a255au; return 0; }
r[4]=0x00000011u;
goto P_0c0a255c;
P_0c0a255c: /* original d239, guest PC 0x0c0a255c */
if(!s->budget--) { s->failed_pc=0x0c0a255cu; return 0; }
r[2]=read(ram,0x0c0a2644u,4);
goto P_0c0a255e;
P_0c0a255e: /* original 4d0b, guest PC 0x0c0a255e */
if(!s->budget--) { s->failed_pc=0x0c0a255eu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2562u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2562u) { target=s->pc; goto dispatch; }
goto P_0c0a2562;
P_0c0a2560: /* original 2f26, guest PC 0x0c0a2560 */
if(!s->budget--) { s->failed_pc=0x0c0a2560u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2562;
P_0c0a2562: /* original d339, guest PC 0x0c0a2562 */
if(!s->budget--) { s->failed_pc=0x0c0a2562u; return 0; }
r[3]=read(ram,0x0c0a2648u,4);
goto P_0c0a2564;
P_0c0a2564: /* original 7f0c, guest PC 0x0c0a2564 */
if(!s->budget--) { s->failed_pc=0x0c0a2564u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a2566;
P_0c0a2566: /* original 430b, guest PC 0x0c0a2566 */
if(!s->budget--) { s->failed_pc=0x0c0a2566u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a256au;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a256au) { target=s->pc; goto dispatch; }
goto P_0c0a256a;
P_0c0a2568: /* original e403, guest PC 0x0c0a2568 */
if(!s->budget--) { s->failed_pc=0x0c0a2568u; return 0; }
r[4]=0x00000003u;
goto P_0c0a256a;
P_0c0a256a: /* original 4f26, guest PC 0x0c0a256a */
if(!s->budget--) { s->failed_pc=0x0c0a256au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a256c;
P_0c0a256c: /* original d237, guest PC 0x0c0a256c */
if(!s->budget--) { s->failed_pc=0x0c0a256cu; return 0; }
r[2]=read(ram,0x0c0a264cu,4);
goto P_0c0a256e;
P_0c0a256e: /* original 6df6, guest PC 0x0c0a256e */
if(!s->budget--) { s->failed_pc=0x0c0a256eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2570;
P_0c0a2570: /* original 422b, guest PC 0x0c0a2570 */
if(!s->budget--) { s->failed_pc=0x0c0a2570u; return 0; }
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
P_0c0a2572: /* original 6ef6, guest PC 0x0c0a2572 */
if(!s->budget--) { s->failed_pc=0x0c0a2572u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a2574;
P_0c0a2574: /* original 2fe6, guest PC 0x0c0a2574 */
if(!s->budget--) { s->failed_pc=0x0c0a2574u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2576;
P_0c0a2576: /* original 2fd6, guest PC 0x0c0a2576 */
if(!s->budget--) { s->failed_pc=0x0c0a2576u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2578;
P_0c0a2578: /* original 4f22, guest PC 0x0c0a2578 */
if(!s->budget--) { s->failed_pc=0x0c0a2578u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a257a;
P_0c0a257a: /* original d329, guest PC 0x0c0a257a */
if(!s->budget--) { s->failed_pc=0x0c0a257au; return 0; }
r[3]=read(ram,0x0c0a2620u,4);
goto P_0c0a257c;
P_0c0a257c: /* original 430b, guest PC 0x0c0a257c */
if(!s->budget--) { s->failed_pc=0x0c0a257cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2580u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2580u) { target=s->pc; goto dispatch; }
goto P_0c0a2580;
P_0c0a257e: /* original 0009, guest PC 0x0c0a257e */
if(!s->budget--) { s->failed_pc=0x0c0a257eu; return 0; }
goto P_0c0a2580;
P_0c0a2580: /* original d228, guest PC 0x0c0a2580 */
if(!s->budget--) { s->failed_pc=0x0c0a2580u; return 0; }
r[2]=read(ram,0x0c0a2624u,4);
goto P_0c0a2582;
P_0c0a2582: /* original 420b, guest PC 0x0c0a2582 */
if(!s->budget--) { s->failed_pc=0x0c0a2582u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2586u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2586u) { target=s->pc; goto dispatch; }
goto P_0c0a2586;
P_0c0a2584: /* original e400, guest PC 0x0c0a2584 */
if(!s->budget--) { s->failed_pc=0x0c0a2584u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2586;
P_0c0a2586: /* original d328, guest PC 0x0c0a2586 */
if(!s->budget--) { s->failed_pc=0x0c0a2586u; return 0; }
r[3]=read(ram,0x0c0a2628u,4);
goto P_0c0a2588;
P_0c0a2588: /* original 430b, guest PC 0x0c0a2588 */
if(!s->budget--) { s->failed_pc=0x0c0a2588u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a258cu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a258cu) { target=s->pc; goto dispatch; }
goto P_0c0a258c;
P_0c0a258a: /* original e401, guest PC 0x0c0a258a */
if(!s->budget--) { s->failed_pc=0x0c0a258au; return 0; }
r[4]=0x00000001u;
goto P_0c0a258c;
P_0c0a258c: /* original d227, guest PC 0x0c0a258c */
if(!s->budget--) { s->failed_pc=0x0c0a258cu; return 0; }
r[2]=read(ram,0x0c0a262cu,4);
goto P_0c0a258e;
P_0c0a258e: /* original 420b, guest PC 0x0c0a258e */
if(!s->budget--) { s->failed_pc=0x0c0a258eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2592u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2592u) { target=s->pc; goto dispatch; }
goto P_0c0a2592;
P_0c0a2590: /* original e400, guest PC 0x0c0a2590 */
if(!s->budget--) { s->failed_pc=0x0c0a2590u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2592;
P_0c0a2592: /* original d327, guest PC 0x0c0a2592 */
if(!s->budget--) { s->failed_pc=0x0c0a2592u; return 0; }
r[3]=read(ram,0x0c0a2630u,4);
goto P_0c0a2594;
P_0c0a2594: /* original e500, guest PC 0x0c0a2594 */
if(!s->budget--) { s->failed_pc=0x0c0a2594u; return 0; }
r[5]=0x00000000u;
goto P_0c0a2596;
P_0c0a2596: /* original 430b, guest PC 0x0c0a2596 */
if(!s->budget--) { s->failed_pc=0x0c0a2596u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a259au;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a259au) { target=s->pc; goto dispatch; }
goto P_0c0a259a;
P_0c0a2598: /* original e403, guest PC 0x0c0a2598 */
if(!s->budget--) { s->failed_pc=0x0c0a2598u; return 0; }
r[4]=0x00000003u;
goto P_0c0a259a;
P_0c0a259a: /* original 953b, guest PC 0x0c0a259a */
if(!s->budget--) { s->failed_pc=0x0c0a259au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2614u,2);
goto P_0c0a259c;
P_0c0a259c: /* original de25, guest PC 0x0c0a259c */
if(!s->budget--) { s->failed_pc=0x0c0a259cu; return 0; }
r[14]=read(ram,0x0c0a2634u,4);
goto P_0c0a259e;
P_0c0a259e: /* original 4e0b, guest PC 0x0c0a259e */
if(!s->budget--) { s->failed_pc=0x0c0a259eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a25a2u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25a2u) { target=s->pc; goto dispatch; }
goto P_0c0a25a2;
P_0c0a25a0: /* original e406, guest PC 0x0c0a25a0 */
if(!s->budget--) { s->failed_pc=0x0c0a25a0u; return 0; }
r[4]=0x00000006u;
goto P_0c0a25a2;
P_0c0a25a2: /* original d22b, guest PC 0x0c0a25a2 */
if(!s->budget--) { s->failed_pc=0x0c0a25a2u; return 0; }
r[2]=read(ram,0x0c0a2650u,4);
goto P_0c0a25a4;
P_0c0a25a4: /* original dd24, guest PC 0x0c0a25a4 */
if(!s->budget--) { s->failed_pc=0x0c0a25a4u; return 0; }
r[13]=read(ram,0x0c0a2638u,4);
goto P_0c0a25a6;
P_0c0a25a6: /* original 4d0b, guest PC 0x0c0a25a6 */
if(!s->budget--) { s->failed_pc=0x0c0a25a6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a25aau;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25aau) { target=s->pc; goto dispatch; }
goto P_0c0a25aa;
P_0c0a25a8: /* original 2f26, guest PC 0x0c0a25a8 */
if(!s->budget--) { s->failed_pc=0x0c0a25a8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a25aa;
P_0c0a25aa: /* original 9534, guest PC 0x0c0a25aa */
if(!s->budget--) { s->failed_pc=0x0c0a25aau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2616u,2);
goto P_0c0a25ac;
P_0c0a25ac: /* original 4e0b, guest PC 0x0c0a25ac */
if(!s->budget--) { s->failed_pc=0x0c0a25acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a25b0u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25b0u) { target=s->pc; goto dispatch; }
goto P_0c0a25b0;
P_0c0a25ae: /* original e406, guest PC 0x0c0a25ae */
if(!s->budget--) { s->failed_pc=0x0c0a25aeu; return 0; }
r[4]=0x00000006u;
goto P_0c0a25b0;
P_0c0a25b0: /* original d328, guest PC 0x0c0a25b0 */
if(!s->budget--) { s->failed_pc=0x0c0a25b0u; return 0; }
r[3]=read(ram,0x0c0a2654u,4);
goto P_0c0a25b2;
P_0c0a25b2: /* original 4d0b, guest PC 0x0c0a25b2 */
if(!s->budget--) { s->failed_pc=0x0c0a25b2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a25b6u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25b6u) { target=s->pc; goto dispatch; }
goto P_0c0a25b6;
P_0c0a25b4: /* original 2f36, guest PC 0x0c0a25b4 */
if(!s->budget--) { s->failed_pc=0x0c0a25b4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a25b6;
P_0c0a25b6: /* original 952b, guest PC 0x0c0a25b6 */
if(!s->budget--) { s->failed_pc=0x0c0a25b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2610u,2);
goto P_0c0a25b8;
P_0c0a25b8: /* original 4e0b, guest PC 0x0c0a25b8 */
if(!s->budget--) { s->failed_pc=0x0c0a25b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a25bcu;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25bcu) { target=s->pc; goto dispatch; }
goto P_0c0a25bc;
P_0c0a25ba: /* original e406, guest PC 0x0c0a25ba */
if(!s->budget--) { s->failed_pc=0x0c0a25bau; return 0; }
r[4]=0x00000006u;
goto P_0c0a25bc;
P_0c0a25bc: /* original d226, guest PC 0x0c0a25bc */
if(!s->budget--) { s->failed_pc=0x0c0a25bcu; return 0; }
r[2]=read(ram,0x0c0a2658u,4);
goto P_0c0a25be;
P_0c0a25be: /* original 4d0b, guest PC 0x0c0a25be */
if(!s->budget--) { s->failed_pc=0x0c0a25beu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a25c2u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25c2u) { target=s->pc; goto dispatch; }
goto P_0c0a25c2;
P_0c0a25c0: /* original 2f26, guest PC 0x0c0a25c0 */
if(!s->budget--) { s->failed_pc=0x0c0a25c0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a25c2;
P_0c0a25c2: /* original 9526, guest PC 0x0c0a25c2 */
if(!s->budget--) { s->failed_pc=0x0c0a25c2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2612u,2);
goto P_0c0a25c4;
P_0c0a25c4: /* original 4e0b, guest PC 0x0c0a25c4 */
if(!s->budget--) { s->failed_pc=0x0c0a25c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a25c8u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25c8u) { target=s->pc; goto dispatch; }
goto P_0c0a25c8;
P_0c0a25c6: /* original e406, guest PC 0x0c0a25c6 */
if(!s->budget--) { s->failed_pc=0x0c0a25c6u; return 0; }
r[4]=0x00000006u;
goto P_0c0a25c8;
P_0c0a25c8: /* original d324, guest PC 0x0c0a25c8 */
if(!s->budget--) { s->failed_pc=0x0c0a25c8u; return 0; }
r[3]=read(ram,0x0c0a265cu,4);
goto P_0c0a25ca;
P_0c0a25ca: /* original 4d0b, guest PC 0x0c0a25ca */
if(!s->budget--) { s->failed_pc=0x0c0a25cau; return 0; }
target=r[13];
r[16]=code_base|0x0c0a25ceu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25ceu) { target=s->pc; goto dispatch; }
goto P_0c0a25ce;
P_0c0a25cc: /* original 2f36, guest PC 0x0c0a25cc */
if(!s->budget--) { s->failed_pc=0x0c0a25ccu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a25ce;
P_0c0a25ce: /* original 9523, guest PC 0x0c0a25ce */
if(!s->budget--) { s->failed_pc=0x0c0a25ceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2618u,2);
goto P_0c0a25d0;
P_0c0a25d0: /* original 4e0b, guest PC 0x0c0a25d0 */
if(!s->budget--) { s->failed_pc=0x0c0a25d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a25d4u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25d4u) { target=s->pc; goto dispatch; }
goto P_0c0a25d4;
P_0c0a25d2: /* original e406, guest PC 0x0c0a25d2 */
if(!s->budget--) { s->failed_pc=0x0c0a25d2u; return 0; }
r[4]=0x00000006u;
goto P_0c0a25d4;
P_0c0a25d4: /* original d222, guest PC 0x0c0a25d4 */
if(!s->budget--) { s->failed_pc=0x0c0a25d4u; return 0; }
r[2]=read(ram,0x0c0a2660u,4);
goto P_0c0a25d6;
P_0c0a25d6: /* original 4d0b, guest PC 0x0c0a25d6 */
if(!s->budget--) { s->failed_pc=0x0c0a25d6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a25dau;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25dau) { target=s->pc; goto dispatch; }
goto P_0c0a25da;
P_0c0a25d8: /* original 2f26, guest PC 0x0c0a25d8 */
if(!s->budget--) { s->failed_pc=0x0c0a25d8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a25da;
P_0c0a25da: /* original 951e, guest PC 0x0c0a25da */
if(!s->budget--) { s->failed_pc=0x0c0a25dau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a261au,2);
goto P_0c0a25dc;
P_0c0a25dc: /* original 4e0b, guest PC 0x0c0a25dc */
if(!s->budget--) { s->failed_pc=0x0c0a25dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a25e0u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25e0u) { target=s->pc; goto dispatch; }
goto P_0c0a25e0;
P_0c0a25de: /* original e406, guest PC 0x0c0a25de */
if(!s->budget--) { s->failed_pc=0x0c0a25deu; return 0; }
r[4]=0x00000006u;
goto P_0c0a25e0;
P_0c0a25e0: /* original d320, guest PC 0x0c0a25e0 */
if(!s->budget--) { s->failed_pc=0x0c0a25e0u; return 0; }
r[3]=read(ram,0x0c0a2664u,4);
goto P_0c0a25e2;
P_0c0a25e2: /* original 4d0b, guest PC 0x0c0a25e2 */
if(!s->budget--) { s->failed_pc=0x0c0a25e2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a25e6u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25e6u) { target=s->pc; goto dispatch; }
goto P_0c0a25e6;
P_0c0a25e4: /* original 2f36, guest PC 0x0c0a25e4 */
if(!s->budget--) { s->failed_pc=0x0c0a25e4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a25e6;
P_0c0a25e6: /* original 9519, guest PC 0x0c0a25e6 */
if(!s->budget--) { s->failed_pc=0x0c0a25e6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a261cu,2);
goto P_0c0a25e8;
P_0c0a25e8: /* original 4e0b, guest PC 0x0c0a25e8 */
if(!s->budget--) { s->failed_pc=0x0c0a25e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a25ecu;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25ecu) { target=s->pc; goto dispatch; }
goto P_0c0a25ec;
P_0c0a25ea: /* original e406, guest PC 0x0c0a25ea */
if(!s->budget--) { s->failed_pc=0x0c0a25eau; return 0; }
r[4]=0x00000006u;
goto P_0c0a25ec;
P_0c0a25ec: /* original d21e, guest PC 0x0c0a25ec */
if(!s->budget--) { s->failed_pc=0x0c0a25ecu; return 0; }
r[2]=read(ram,0x0c0a2668u,4);
goto P_0c0a25ee;
P_0c0a25ee: /* original 4d0b, guest PC 0x0c0a25ee */
if(!s->budget--) { s->failed_pc=0x0c0a25eeu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a25f2u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25f2u) { target=s->pc; goto dispatch; }
goto P_0c0a25f2;
P_0c0a25f0: /* original 2f26, guest PC 0x0c0a25f0 */
if(!s->budget--) { s->failed_pc=0x0c0a25f0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a25f2;
P_0c0a25f2: /* original 9514, guest PC 0x0c0a25f2 */
if(!s->budget--) { s->failed_pc=0x0c0a25f2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a261eu,2);
goto P_0c0a25f4;
P_0c0a25f4: /* original 4e0b, guest PC 0x0c0a25f4 */
if(!s->budget--) { s->failed_pc=0x0c0a25f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a25f8u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25f8u) { target=s->pc; goto dispatch; }
goto P_0c0a25f8;
P_0c0a25f6: /* original e406, guest PC 0x0c0a25f6 */
if(!s->budget--) { s->failed_pc=0x0c0a25f6u; return 0; }
r[4]=0x00000006u;
goto P_0c0a25f8;
P_0c0a25f8: /* original d31c, guest PC 0x0c0a25f8 */
if(!s->budget--) { s->failed_pc=0x0c0a25f8u; return 0; }
r[3]=read(ram,0x0c0a266cu,4);
goto P_0c0a25fa;
P_0c0a25fa: /* original 4d0b, guest PC 0x0c0a25fa */
if(!s->budget--) { s->failed_pc=0x0c0a25fau; return 0; }
target=r[13];
r[16]=code_base|0x0c0a25feu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a25feu) { target=s->pc; goto dispatch; }
goto P_0c0a25fe;
P_0c0a25fc: /* original 2f36, guest PC 0x0c0a25fc */
if(!s->budget--) { s->failed_pc=0x0c0a25fcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a25fe;
P_0c0a25fe: /* original d212, guest PC 0x0c0a25fe */
if(!s->budget--) { s->failed_pc=0x0c0a25feu; return 0; }
r[2]=read(ram,0x0c0a2648u,4);
goto P_0c0a2600;
P_0c0a2600: /* original 7f20, guest PC 0x0c0a2600 */
if(!s->budget--) { s->failed_pc=0x0c0a2600u; return 0; }
r[15]+=0x00000020u;
goto P_0c0a2602;
P_0c0a2602: /* original 420b, guest PC 0x0c0a2602 */
if(!s->budget--) { s->failed_pc=0x0c0a2602u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2606u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2606u) { target=s->pc; goto dispatch; }
goto P_0c0a2606;
P_0c0a2604: /* original e403, guest PC 0x0c0a2604 */
if(!s->budget--) { s->failed_pc=0x0c0a2604u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2606;
P_0c0a2606: /* original 4f26, guest PC 0x0c0a2606 */
if(!s->budget--) { s->failed_pc=0x0c0a2606u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2608;
P_0c0a2608: /* original d310, guest PC 0x0c0a2608 */
if(!s->budget--) { s->failed_pc=0x0c0a2608u; return 0; }
r[3]=read(ram,0x0c0a264cu,4);
goto P_0c0a260a;
P_0c0a260a: /* original 6df6, guest PC 0x0c0a260a */
if(!s->budget--) { s->failed_pc=0x0c0a260au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a260c;
P_0c0a260c: /* original 432b, guest PC 0x0c0a260c */
if(!s->budget--) { s->failed_pc=0x0c0a260cu; return 0; }
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
P_0c0a260e: /* original 6ef6, guest PC 0x0c0a260e */
if(!s->budget--) { s->failed_pc=0x0c0a260eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2610u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2610u; return 0; } return 1;
P_0c0a2670: /* original 2fe6, guest PC 0x0c0a2670 */
if(!s->budget--) { s->failed_pc=0x0c0a2670u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2672;
P_0c0a2672: /* original 2fd6, guest PC 0x0c0a2672 */
if(!s->budget--) { s->failed_pc=0x0c0a2672u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2674;
P_0c0a2674: /* original 4f22, guest PC 0x0c0a2674 */
if(!s->budget--) { s->failed_pc=0x0c0a2674u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2676;
P_0c0a2676: /* original d329, guest PC 0x0c0a2676 */
if(!s->budget--) { s->failed_pc=0x0c0a2676u; return 0; }
r[3]=read(ram,0x0c0a271cu,4);
goto P_0c0a2678;
P_0c0a2678: /* original 430b, guest PC 0x0c0a2678 */
if(!s->budget--) { s->failed_pc=0x0c0a2678u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a267cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a267cu) { target=s->pc; goto dispatch; }
goto P_0c0a267c;
P_0c0a267a: /* original 0009, guest PC 0x0c0a267a */
if(!s->budget--) { s->failed_pc=0x0c0a267au; return 0; }
goto P_0c0a267c;
P_0c0a267c: /* original d228, guest PC 0x0c0a267c */
if(!s->budget--) { s->failed_pc=0x0c0a267cu; return 0; }
r[2]=read(ram,0x0c0a2720u,4);
goto P_0c0a267e;
P_0c0a267e: /* original 420b, guest PC 0x0c0a267e */
if(!s->budget--) { s->failed_pc=0x0c0a267eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2682u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2682u) { target=s->pc; goto dispatch; }
goto P_0c0a2682;
P_0c0a2680: /* original e400, guest PC 0x0c0a2680 */
if(!s->budget--) { s->failed_pc=0x0c0a2680u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2682;
P_0c0a2682: /* original d328, guest PC 0x0c0a2682 */
if(!s->budget--) { s->failed_pc=0x0c0a2682u; return 0; }
r[3]=read(ram,0x0c0a2724u,4);
goto P_0c0a2684;
P_0c0a2684: /* original 430b, guest PC 0x0c0a2684 */
if(!s->budget--) { s->failed_pc=0x0c0a2684u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2688u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2688u) { target=s->pc; goto dispatch; }
goto P_0c0a2688;
P_0c0a2686: /* original e401, guest PC 0x0c0a2686 */
if(!s->budget--) { s->failed_pc=0x0c0a2686u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2688;
P_0c0a2688: /* original d227, guest PC 0x0c0a2688 */
if(!s->budget--) { s->failed_pc=0x0c0a2688u; return 0; }
r[2]=read(ram,0x0c0a2728u,4);
goto P_0c0a268a;
P_0c0a268a: /* original 420b, guest PC 0x0c0a268a */
if(!s->budget--) { s->failed_pc=0x0c0a268au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a268eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a268eu) { target=s->pc; goto dispatch; }
goto P_0c0a268e;
P_0c0a268c: /* original e400, guest PC 0x0c0a268c */
if(!s->budget--) { s->failed_pc=0x0c0a268cu; return 0; }
r[4]=0x00000000u;
goto P_0c0a268e;
P_0c0a268e: /* original d327, guest PC 0x0c0a268e */
if(!s->budget--) { s->failed_pc=0x0c0a268eu; return 0; }
r[3]=read(ram,0x0c0a272cu,4);
goto P_0c0a2690;
P_0c0a2690: /* original e500, guest PC 0x0c0a2690 */
if(!s->budget--) { s->failed_pc=0x0c0a2690u; return 0; }
r[5]=0x00000000u;
goto P_0c0a2692;
P_0c0a2692: /* original 430b, guest PC 0x0c0a2692 */
if(!s->budget--) { s->failed_pc=0x0c0a2692u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2696u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2696u) { target=s->pc; goto dispatch; }
goto P_0c0a2696;
P_0c0a2694: /* original e403, guest PC 0x0c0a2694 */
if(!s->budget--) { s->failed_pc=0x0c0a2694u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2696;
P_0c0a2696: /* original 9539, guest PC 0x0c0a2696 */
if(!s->budget--) { s->failed_pc=0x0c0a2696u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a270cu,2);
goto P_0c0a2698;
P_0c0a2698: /* original de25, guest PC 0x0c0a2698 */
if(!s->budget--) { s->failed_pc=0x0c0a2698u; return 0; }
r[14]=read(ram,0x0c0a2730u,4);
goto P_0c0a269a;
P_0c0a269a: /* original 4e0b, guest PC 0x0c0a269a */
if(!s->budget--) { s->failed_pc=0x0c0a269au; return 0; }
target=r[14];
r[16]=code_base|0x0c0a269eu;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a269eu) { target=s->pc; goto dispatch; }
goto P_0c0a269e;
P_0c0a269c: /* original e406, guest PC 0x0c0a269c */
if(!s->budget--) { s->failed_pc=0x0c0a269cu; return 0; }
r[4]=0x00000006u;
goto P_0c0a269e;
P_0c0a269e: /* original d226, guest PC 0x0c0a269e */
if(!s->budget--) { s->failed_pc=0x0c0a269eu; return 0; }
r[2]=read(ram,0x0c0a2738u,4);
goto P_0c0a26a0;
P_0c0a26a0: /* original dd24, guest PC 0x0c0a26a0 */
if(!s->budget--) { s->failed_pc=0x0c0a26a0u; return 0; }
r[13]=read(ram,0x0c0a2734u,4);
goto P_0c0a26a2;
P_0c0a26a2: /* original 4d0b, guest PC 0x0c0a26a2 */
if(!s->budget--) { s->failed_pc=0x0c0a26a2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a26a6u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26a6u) { target=s->pc; goto dispatch; }
goto P_0c0a26a6;
P_0c0a26a4: /* original 2f26, guest PC 0x0c0a26a4 */
if(!s->budget--) { s->failed_pc=0x0c0a26a4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a26a6;
P_0c0a26a6: /* original 9532, guest PC 0x0c0a26a6 */
if(!s->budget--) { s->failed_pc=0x0c0a26a6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a270eu,2);
goto P_0c0a26a8;
P_0c0a26a8: /* original 4e0b, guest PC 0x0c0a26a8 */
if(!s->budget--) { s->failed_pc=0x0c0a26a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a26acu;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26acu) { target=s->pc; goto dispatch; }
goto P_0c0a26ac;
P_0c0a26aa: /* original e406, guest PC 0x0c0a26aa */
if(!s->budget--) { s->failed_pc=0x0c0a26aau; return 0; }
r[4]=0x00000006u;
goto P_0c0a26ac;
P_0c0a26ac: /* original d323, guest PC 0x0c0a26ac */
if(!s->budget--) { s->failed_pc=0x0c0a26acu; return 0; }
r[3]=read(ram,0x0c0a273cu,4);
goto P_0c0a26ae;
P_0c0a26ae: /* original 4d0b, guest PC 0x0c0a26ae */
if(!s->budget--) { s->failed_pc=0x0c0a26aeu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a26b2u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26b2u) { target=s->pc; goto dispatch; }
goto P_0c0a26b2;
P_0c0a26b0: /* original 2f36, guest PC 0x0c0a26b0 */
if(!s->budget--) { s->failed_pc=0x0c0a26b0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a26b2;
P_0c0a26b2: /* original 952d, guest PC 0x0c0a26b2 */
if(!s->budget--) { s->failed_pc=0x0c0a26b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2710u,2);
goto P_0c0a26b4;
P_0c0a26b4: /* original 4e0b, guest PC 0x0c0a26b4 */
if(!s->budget--) { s->failed_pc=0x0c0a26b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a26b8u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26b8u) { target=s->pc; goto dispatch; }
goto P_0c0a26b8;
P_0c0a26b6: /* original e406, guest PC 0x0c0a26b6 */
if(!s->budget--) { s->failed_pc=0x0c0a26b6u; return 0; }
r[4]=0x00000006u;
goto P_0c0a26b8;
P_0c0a26b8: /* original d221, guest PC 0x0c0a26b8 */
if(!s->budget--) { s->failed_pc=0x0c0a26b8u; return 0; }
r[2]=read(ram,0x0c0a2740u,4);
goto P_0c0a26ba;
P_0c0a26ba: /* original 4d0b, guest PC 0x0c0a26ba */
if(!s->budget--) { s->failed_pc=0x0c0a26bau; return 0; }
target=r[13];
r[16]=code_base|0x0c0a26beu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26beu) { target=s->pc; goto dispatch; }
goto P_0c0a26be;
P_0c0a26bc: /* original 2f26, guest PC 0x0c0a26bc */
if(!s->budget--) { s->failed_pc=0x0c0a26bcu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a26be;
P_0c0a26be: /* original 9528, guest PC 0x0c0a26be */
if(!s->budget--) { s->failed_pc=0x0c0a26beu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2712u,2);
goto P_0c0a26c0;
P_0c0a26c0: /* original 4e0b, guest PC 0x0c0a26c0 */
if(!s->budget--) { s->failed_pc=0x0c0a26c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a26c4u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26c4u) { target=s->pc; goto dispatch; }
goto P_0c0a26c4;
P_0c0a26c2: /* original e406, guest PC 0x0c0a26c2 */
if(!s->budget--) { s->failed_pc=0x0c0a26c2u; return 0; }
r[4]=0x00000006u;
goto P_0c0a26c4;
P_0c0a26c4: /* original d31f, guest PC 0x0c0a26c4 */
if(!s->budget--) { s->failed_pc=0x0c0a26c4u; return 0; }
r[3]=read(ram,0x0c0a2744u,4);
goto P_0c0a26c6;
P_0c0a26c6: /* original 4d0b, guest PC 0x0c0a26c6 */
if(!s->budget--) { s->failed_pc=0x0c0a26c6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a26cau;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26cau) { target=s->pc; goto dispatch; }
goto P_0c0a26ca;
P_0c0a26c8: /* original 2f36, guest PC 0x0c0a26c8 */
if(!s->budget--) { s->failed_pc=0x0c0a26c8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a26ca;
P_0c0a26ca: /* original 9523, guest PC 0x0c0a26ca */
if(!s->budget--) { s->failed_pc=0x0c0a26cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2714u,2);
goto P_0c0a26cc;
P_0c0a26cc: /* original 4e0b, guest PC 0x0c0a26cc */
if(!s->budget--) { s->failed_pc=0x0c0a26ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a26d0u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26d0u) { target=s->pc; goto dispatch; }
goto P_0c0a26d0;
P_0c0a26ce: /* original e406, guest PC 0x0c0a26ce */
if(!s->budget--) { s->failed_pc=0x0c0a26ceu; return 0; }
r[4]=0x00000006u;
goto P_0c0a26d0;
P_0c0a26d0: /* original d21d, guest PC 0x0c0a26d0 */
if(!s->budget--) { s->failed_pc=0x0c0a26d0u; return 0; }
r[2]=read(ram,0x0c0a2748u,4);
goto P_0c0a26d2;
P_0c0a26d2: /* original 4d0b, guest PC 0x0c0a26d2 */
if(!s->budget--) { s->failed_pc=0x0c0a26d2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a26d6u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26d6u) { target=s->pc; goto dispatch; }
goto P_0c0a26d6;
P_0c0a26d4: /* original 2f26, guest PC 0x0c0a26d4 */
if(!s->budget--) { s->failed_pc=0x0c0a26d4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a26d6;
P_0c0a26d6: /* original 951e, guest PC 0x0c0a26d6 */
if(!s->budget--) { s->failed_pc=0x0c0a26d6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2716u,2);
goto P_0c0a26d8;
P_0c0a26d8: /* original 4e0b, guest PC 0x0c0a26d8 */
if(!s->budget--) { s->failed_pc=0x0c0a26d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a26dcu;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26dcu) { target=s->pc; goto dispatch; }
goto P_0c0a26dc;
P_0c0a26da: /* original e406, guest PC 0x0c0a26da */
if(!s->budget--) { s->failed_pc=0x0c0a26dau; return 0; }
r[4]=0x00000006u;
goto P_0c0a26dc;
P_0c0a26dc: /* original d31b, guest PC 0x0c0a26dc */
if(!s->budget--) { s->failed_pc=0x0c0a26dcu; return 0; }
r[3]=read(ram,0x0c0a274cu,4);
goto P_0c0a26de;
P_0c0a26de: /* original 4d0b, guest PC 0x0c0a26de */
if(!s->budget--) { s->failed_pc=0x0c0a26deu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a26e2u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26e2u) { target=s->pc; goto dispatch; }
goto P_0c0a26e2;
P_0c0a26e0: /* original 2f36, guest PC 0x0c0a26e0 */
if(!s->budget--) { s->failed_pc=0x0c0a26e0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a26e2;
P_0c0a26e2: /* original 9519, guest PC 0x0c0a26e2 */
if(!s->budget--) { s->failed_pc=0x0c0a26e2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2718u,2);
goto P_0c0a26e4;
P_0c0a26e4: /* original 4e0b, guest PC 0x0c0a26e4 */
if(!s->budget--) { s->failed_pc=0x0c0a26e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a26e8u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26e8u) { target=s->pc; goto dispatch; }
goto P_0c0a26e8;
P_0c0a26e6: /* original e406, guest PC 0x0c0a26e6 */
if(!s->budget--) { s->failed_pc=0x0c0a26e6u; return 0; }
r[4]=0x00000006u;
goto P_0c0a26e8;
P_0c0a26e8: /* original d219, guest PC 0x0c0a26e8 */
if(!s->budget--) { s->failed_pc=0x0c0a26e8u; return 0; }
r[2]=read(ram,0x0c0a2750u,4);
goto P_0c0a26ea;
P_0c0a26ea: /* original 4d0b, guest PC 0x0c0a26ea */
if(!s->budget--) { s->failed_pc=0x0c0a26eau; return 0; }
target=r[13];
r[16]=code_base|0x0c0a26eeu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26eeu) { target=s->pc; goto dispatch; }
goto P_0c0a26ee;
P_0c0a26ec: /* original 2f26, guest PC 0x0c0a26ec */
if(!s->budget--) { s->failed_pc=0x0c0a26ecu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a26ee;
P_0c0a26ee: /* original 9514, guest PC 0x0c0a26ee */
if(!s->budget--) { s->failed_pc=0x0c0a26eeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a271au,2);
goto P_0c0a26f0;
P_0c0a26f0: /* original 4e0b, guest PC 0x0c0a26f0 */
if(!s->budget--) { s->failed_pc=0x0c0a26f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a26f4u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26f4u) { target=s->pc; goto dispatch; }
goto P_0c0a26f4;
P_0c0a26f2: /* original e406, guest PC 0x0c0a26f2 */
if(!s->budget--) { s->failed_pc=0x0c0a26f2u; return 0; }
r[4]=0x00000006u;
goto P_0c0a26f4;
P_0c0a26f4: /* original d317, guest PC 0x0c0a26f4 */
if(!s->budget--) { s->failed_pc=0x0c0a26f4u; return 0; }
r[3]=read(ram,0x0c0a2754u,4);
goto P_0c0a26f6;
P_0c0a26f6: /* original 4d0b, guest PC 0x0c0a26f6 */
if(!s->budget--) { s->failed_pc=0x0c0a26f6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a26fau;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a26fau) { target=s->pc; goto dispatch; }
goto P_0c0a26fa;
P_0c0a26f8: /* original 2f36, guest PC 0x0c0a26f8 */
if(!s->budget--) { s->failed_pc=0x0c0a26f8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a26fa;
P_0c0a26fa: /* original d217, guest PC 0x0c0a26fa */
if(!s->budget--) { s->failed_pc=0x0c0a26fau; return 0; }
r[2]=read(ram,0x0c0a2758u,4);
goto P_0c0a26fc;
P_0c0a26fc: /* original 7f20, guest PC 0x0c0a26fc */
if(!s->budget--) { s->failed_pc=0x0c0a26fcu; return 0; }
r[15]+=0x00000020u;
goto P_0c0a26fe;
P_0c0a26fe: /* original 420b, guest PC 0x0c0a26fe */
if(!s->budget--) { s->failed_pc=0x0c0a26feu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2702u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2702u) { target=s->pc; goto dispatch; }
goto P_0c0a2702;
P_0c0a2700: /* original e403, guest PC 0x0c0a2700 */
if(!s->budget--) { s->failed_pc=0x0c0a2700u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2702;
P_0c0a2702: /* original 4f26, guest PC 0x0c0a2702 */
if(!s->budget--) { s->failed_pc=0x0c0a2702u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2704;
P_0c0a2704: /* original d315, guest PC 0x0c0a2704 */
if(!s->budget--) { s->failed_pc=0x0c0a2704u; return 0; }
r[3]=read(ram,0x0c0a275cu,4);
goto P_0c0a2706;
P_0c0a2706: /* original 6df6, guest PC 0x0c0a2706 */
if(!s->budget--) { s->failed_pc=0x0c0a2706u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2708;
P_0c0a2708: /* original 432b, guest PC 0x0c0a2708 */
if(!s->budget--) { s->failed_pc=0x0c0a2708u; return 0; }
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
P_0c0a270a: /* original 6ef6, guest PC 0x0c0a270a */
if(!s->budget--) { s->failed_pc=0x0c0a270au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a270cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a270cu; return 0; } return 1;
P_0c0a7f5a: /* original 2fe6, guest PC 0x0c0a7f5a */
if(!s->budget--) { s->failed_pc=0x0c0a7f5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5c;
P_0c0a7f5c: /* original 2fd6, guest PC 0x0c0a7f5c */
if(!s->budget--) { s->failed_pc=0x0c0a7f5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5e;
P_0c0a7f5e: /* original 2fc6, guest PC 0x0c0a7f5e */
if(!s->budget--) { s->failed_pc=0x0c0a7f5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f60;
P_0c0a7f60: /* original 2fb6, guest PC 0x0c0a7f60 */
if(!s->budget--) { s->failed_pc=0x0c0a7f60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f62;
P_0c0a7f62: /* original 6b43, guest PC 0x0c0a7f62 */
if(!s->budget--) { s->failed_pc=0x0c0a7f62u; return 0; }
r[11]=r[4];
goto P_0c0a7f64;
P_0c0a7f64: /* original 2fa6, guest PC 0x0c0a7f64 */
if(!s->budget--) { s->failed_pc=0x0c0a7f64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f66;
P_0c0a7f66: /* original e400, guest PC 0x0c0a7f66 */
if(!s->budget--) { s->failed_pc=0x0c0a7f66u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7f68;
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
if(!vf3_matrix_family(0x0c0a7fa6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7fa6u; return 0; } return 1;
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7fc8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a7fd6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7ff6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8000u;
r[5]=0x00000072u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8006u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a801au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8024u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a802au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a803cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a803cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
