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
int vf3_away_batch90_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b243au: goto P_0c0b243a;
case 0x0c0b243cu: goto P_0c0b243c;
case 0x0c0b243eu: goto P_0c0b243e;
case 0x0c0b2440u: goto P_0c0b2440;
case 0x0c0b2442u: goto P_0c0b2442;
case 0x0c0b2444u: goto P_0c0b2444;
case 0x0c0b2446u: goto P_0c0b2446;
case 0x0c0b2448u: goto P_0c0b2448;
case 0x0c0b244au: goto P_0c0b244a;
case 0x0c0b244cu: goto P_0c0b244c;
case 0x0c0b244eu: goto P_0c0b244e;
case 0x0c0b2450u: goto P_0c0b2450;
case 0x0c0b2452u: goto P_0c0b2452;
case 0x0c0b2454u: goto P_0c0b2454;
case 0x0c0b2456u: goto P_0c0b2456;
case 0x0c0b2458u: goto P_0c0b2458;
case 0x0c0b245au: goto P_0c0b245a;
case 0x0c0b245cu: goto P_0c0b245c;
case 0x0c0b245eu: goto P_0c0b245e;
case 0x0c0b2460u: goto P_0c0b2460;
case 0x0c0b2462u: goto P_0c0b2462;
case 0x0c0b2464u: goto P_0c0b2464;
case 0x0c0b2466u: goto P_0c0b2466;
case 0x0c0b2468u: goto P_0c0b2468;
case 0x0c0b246au: goto P_0c0b246a;
case 0x0c0b246cu: goto P_0c0b246c;
case 0x0c0b246eu: goto P_0c0b246e;
case 0x0c0b2470u: goto P_0c0b2470;
case 0x0c0b2472u: goto P_0c0b2472;
case 0x0c0b2474u: goto P_0c0b2474;
case 0x0c0b2476u: goto P_0c0b2476;
case 0x0c0b2478u: goto P_0c0b2478;
case 0x0c0b247au: goto P_0c0b247a;
case 0x0c0b247cu: goto P_0c0b247c;
case 0x0c0b247eu: goto P_0c0b247e;
case 0x0c0b2480u: goto P_0c0b2480;
case 0x0c0b2482u: goto P_0c0b2482;
case 0x0c0b2484u: goto P_0c0b2484;
case 0x0c0b2486u: goto P_0c0b2486;
case 0x0c0b2488u: goto P_0c0b2488;
case 0x0c0b248au: goto P_0c0b248a;
case 0x0c0b248cu: goto P_0c0b248c;
case 0x0c0b248eu: goto P_0c0b248e;
case 0x0c0b2490u: goto P_0c0b2490;
case 0x0c0b2492u: goto P_0c0b2492;
case 0x0c0b2494u: goto P_0c0b2494;
case 0x0c0b2496u: goto P_0c0b2496;
case 0x0c0b2498u: goto P_0c0b2498;
case 0x0c0b249au: goto P_0c0b249a;
case 0x0c0b249cu: goto P_0c0b249c;
case 0x0c0b249eu: goto P_0c0b249e;
case 0x0c0b24a0u: goto P_0c0b24a0;
case 0x0c0b24a2u: goto P_0c0b24a2;
case 0x0c0b24a4u: goto P_0c0b24a4;
case 0x0c0b24a6u: goto P_0c0b24a6;
case 0x0c0b24a8u: goto P_0c0b24a8;
case 0x0c0b24aau: goto P_0c0b24aa;
case 0x0c0b24acu: goto P_0c0b24ac;
case 0x0c0b24aeu: goto P_0c0b24ae;
case 0x0c0b24b0u: goto P_0c0b24b0;
case 0x0c0b24b2u: goto P_0c0b24b2;
case 0x0c0b24b4u: goto P_0c0b24b4;
case 0x0c0b24b6u: goto P_0c0b24b6;
case 0x0c0b24b8u: goto P_0c0b24b8;
case 0x0c0b2628u: goto P_0c0b2628;
case 0x0c0b262au: goto P_0c0b262a;
case 0x0c0b262cu: goto P_0c0b262c;
case 0x0c0b262eu: goto P_0c0b262e;
case 0x0c0b2630u: goto P_0c0b2630;
case 0x0c0b2632u: goto P_0c0b2632;
case 0x0c0b2634u: goto P_0c0b2634;
case 0x0c0b2636u: goto P_0c0b2636;
case 0x0c0b2638u: goto P_0c0b2638;
case 0x0c0b263au: goto P_0c0b263a;
case 0x0c0b263cu: goto P_0c0b263c;
case 0x0c0b263eu: goto P_0c0b263e;
case 0x0c0b2640u: goto P_0c0b2640;
case 0x0c0b2642u: goto P_0c0b2642;
case 0x0c0b2644u: goto P_0c0b2644;
case 0x0c0b2646u: goto P_0c0b2646;
case 0x0c0b2648u: goto P_0c0b2648;
case 0x0c0b264au: goto P_0c0b264a;
case 0x0c0b264cu: goto P_0c0b264c;
case 0x0c0b264eu: goto P_0c0b264e;
case 0x0c0b2650u: goto P_0c0b2650;
case 0x0c0b2652u: goto P_0c0b2652;
case 0x0c0b2654u: goto P_0c0b2654;
case 0x0c0b2656u: goto P_0c0b2656;
case 0x0c0b2658u: goto P_0c0b2658;
case 0x0c0b265au: goto P_0c0b265a;
case 0x0c0b265cu: goto P_0c0b265c;
case 0x0c0b265eu: goto P_0c0b265e;
case 0x0c0b2660u: goto P_0c0b2660;
case 0x0c0b2662u: goto P_0c0b2662;
case 0x0c0b2664u: goto P_0c0b2664;
case 0x0c0b2666u: goto P_0c0b2666;
case 0x0c0b2668u: goto P_0c0b2668;
case 0x0c0b266au: goto P_0c0b266a;
case 0x0c0b266cu: goto P_0c0b266c;
case 0x0c0b266eu: goto P_0c0b266e;
case 0x0c0b2670u: goto P_0c0b2670;
case 0x0c0b2672u: goto P_0c0b2672;
case 0x0c0b2674u: goto P_0c0b2674;
case 0x0c0b2676u: goto P_0c0b2676;
case 0x0c0b2678u: goto P_0c0b2678;
case 0x0c0b267au: goto P_0c0b267a;
case 0x0c0b267cu: goto P_0c0b267c;
case 0x0c0b267eu: goto P_0c0b267e;
case 0x0c0b2680u: goto P_0c0b2680;
case 0x0c0b2682u: goto P_0c0b2682;
case 0x0c0b2684u: goto P_0c0b2684;
case 0x0c0b2686u: goto P_0c0b2686;
case 0x0c0b2688u: goto P_0c0b2688;
case 0x0c0b268au: goto P_0c0b268a;
case 0x0c0b268cu: goto P_0c0b268c;
case 0x0c0b268eu: goto P_0c0b268e;
case 0x0c0b2690u: goto P_0c0b2690;
case 0x0c0b2692u: goto P_0c0b2692;
case 0x0c0b2694u: goto P_0c0b2694;
case 0x0c0b2696u: goto P_0c0b2696;
case 0x0c0b2698u: goto P_0c0b2698;
case 0x0c0b269au: goto P_0c0b269a;
case 0x0c0b269cu: goto P_0c0b269c;
case 0x0c0b269eu: goto P_0c0b269e;
case 0x0c0b26a0u: goto P_0c0b26a0;
case 0x0c0b26a2u: goto P_0c0b26a2;
case 0x0c0b26a4u: goto P_0c0b26a4;
case 0x0c0b26a6u: goto P_0c0b26a6;
case 0x0c0b26a8u: goto P_0c0b26a8;
case 0x0c0b26aau: goto P_0c0b26aa;
case 0x0c0b26acu: goto P_0c0b26ac;
case 0x0c0b26aeu: goto P_0c0b26ae;
case 0x0c0b26b0u: goto P_0c0b26b0;
case 0x0c0b26b2u: goto P_0c0b26b2;
case 0x0c0b26b4u: goto P_0c0b26b4;
case 0x0c0b26b6u: goto P_0c0b26b6;
case 0x0c0b26b8u: goto P_0c0b26b8;
case 0x0c0b26bau: goto P_0c0b26ba;
case 0x0c0b26bcu: goto P_0c0b26bc;
case 0x0c0b26beu: goto P_0c0b26be;
case 0x0c0b26c0u: goto P_0c0b26c0;
case 0x0c0b26c2u: goto P_0c0b26c2;
case 0x0c0b26c4u: goto P_0c0b26c4;
case 0x0c0b26c6u: goto P_0c0b26c6;
case 0x0c0b26c8u: goto P_0c0b26c8;
case 0x0c0b26cau: goto P_0c0b26ca;
case 0x0c0b26ccu: goto P_0c0b26cc;
case 0x0c0b26ceu: goto P_0c0b26ce;
case 0x0c0b26d0u: goto P_0c0b26d0;
case 0x0c0b26d2u: goto P_0c0b26d2;
case 0x0c0b26d4u: goto P_0c0b26d4;
case 0x0c0b26d6u: goto P_0c0b26d6;
case 0x0c0b26d8u: goto P_0c0b26d8;
case 0x0c0b26dau: goto P_0c0b26da;
case 0x0c0b26dcu: goto P_0c0b26dc;
case 0x0c0b26deu: goto P_0c0b26de;
case 0x0c0b26e0u: goto P_0c0b26e0;
case 0x0c0b26e2u: goto P_0c0b26e2;
case 0x0c0b26e4u: goto P_0c0b26e4;
case 0x0c0b26e6u: goto P_0c0b26e6;
case 0x0c0b26e8u: goto P_0c0b26e8;
case 0x0c0b26eau: goto P_0c0b26ea;
case 0x0c0b26ecu: goto P_0c0b26ec;
case 0x0c0b26eeu: goto P_0c0b26ee;
case 0x0c0b26f0u: goto P_0c0b26f0;
case 0x0c0b26f2u: goto P_0c0b26f2;
case 0x0c0b26f4u: goto P_0c0b26f4;
case 0x0c0b26f6u: goto P_0c0b26f6;
case 0x0c0b26f8u: goto P_0c0b26f8;
case 0x0c0b26fau: goto P_0c0b26fa;
case 0x0c0b26fcu: goto P_0c0b26fc;
case 0x0c0b26feu: goto P_0c0b26fe;
case 0x0c0b2700u: goto P_0c0b2700;
case 0x0c0b2702u: goto P_0c0b2702;
case 0x0c0b2704u: goto P_0c0b2704;
case 0x0c0b2706u: goto P_0c0b2706;
case 0x0c0b2708u: goto P_0c0b2708;
case 0x0c0b270au: goto P_0c0b270a;
case 0x0c0b270cu: goto P_0c0b270c;
case 0x0c0b270eu: goto P_0c0b270e;
case 0x0c0b2710u: goto P_0c0b2710;
case 0x0c0b2712u: goto P_0c0b2712;
case 0x0c0b2714u: goto P_0c0b2714;
case 0x0c0b2716u: goto P_0c0b2716;
case 0x0c0b2718u: goto P_0c0b2718;
case 0x0c0b271au: goto P_0c0b271a;
case 0x0c0b271cu: goto P_0c0b271c;
case 0x0c0b271eu: goto P_0c0b271e;
case 0x0c0b2720u: goto P_0c0b2720;
case 0x0c0b2722u: goto P_0c0b2722;
case 0x0c0b2724u: goto P_0c0b2724;
case 0x0c0b2726u: goto P_0c0b2726;
case 0x0c0b2728u: goto P_0c0b2728;
case 0x0c0b272au: goto P_0c0b272a;
case 0x0c0b272cu: goto P_0c0b272c;
case 0x0c0b272eu: goto P_0c0b272e;
case 0x0c0b2730u: goto P_0c0b2730;
case 0x0c0b2732u: goto P_0c0b2732;
case 0x0c0b2734u: goto P_0c0b2734;
case 0x0c0b2736u: goto P_0c0b2736;
case 0x0c0b2738u: goto P_0c0b2738;
case 0x0c0b273au: goto P_0c0b273a;
case 0x0c0b273cu: goto P_0c0b273c;
case 0x0c0b273eu: goto P_0c0b273e;
case 0x0c0b2740u: goto P_0c0b2740;
case 0x0c0b2742u: goto P_0c0b2742;
case 0x0c0b2744u: goto P_0c0b2744;
case 0x0c0b2746u: goto P_0c0b2746;
case 0x0c0b2748u: goto P_0c0b2748;
case 0x0c0b274au: goto P_0c0b274a;
case 0x0c0b274cu: goto P_0c0b274c;
case 0x0c0b274eu: goto P_0c0b274e;
case 0x0c0b2750u: goto P_0c0b2750;
case 0x0c0b2752u: goto P_0c0b2752;
case 0x0c0b2754u: goto P_0c0b2754;
case 0x0c0b2756u: goto P_0c0b2756;
case 0x0c0b2758u: goto P_0c0b2758;
case 0x0c0b275au: goto P_0c0b275a;
case 0x0c0b275cu: goto P_0c0b275c;
case 0x0c0b275eu: goto P_0c0b275e;
case 0x0c0b2760u: goto P_0c0b2760;
case 0x0c0b2762u: goto P_0c0b2762;
case 0x0c0b2764u: goto P_0c0b2764;
case 0x0c0b2766u: goto P_0c0b2766;
case 0x0c0b2768u: goto P_0c0b2768;
case 0x0c0b276au: goto P_0c0b276a;
case 0x0c0b276cu: goto P_0c0b276c;
case 0x0c0b276eu: goto P_0c0b276e;
case 0x0c0b2770u: goto P_0c0b2770;
case 0x0c0b2772u: goto P_0c0b2772;
case 0x0c0b2774u: goto P_0c0b2774;
case 0x0c0b2776u: goto P_0c0b2776;
case 0x0c0b2778u: goto P_0c0b2778;
case 0x0c0b277au: goto P_0c0b277a;
case 0x0c0b277cu: goto P_0c0b277c;
case 0x0c0b277eu: goto P_0c0b277e;
case 0x0c0b2780u: goto P_0c0b2780;
case 0x0c0b2782u: goto P_0c0b2782;
case 0x0c0b2784u: goto P_0c0b2784;
case 0x0c0b2786u: goto P_0c0b2786;
case 0x0c0b2788u: goto P_0c0b2788;
case 0x0c0b278au: goto P_0c0b278a;
case 0x0c0b27fcu: goto P_0c0b27fc;
case 0x0c0b27feu: goto P_0c0b27fe;
case 0x0c0b2800u: goto P_0c0b2800;
case 0x0c0b2802u: goto P_0c0b2802;
case 0x0c0b2804u: goto P_0c0b2804;
case 0x0c0b2806u: goto P_0c0b2806;
case 0x0c0b2808u: goto P_0c0b2808;
case 0x0c0b280au: goto P_0c0b280a;
case 0x0c0b280cu: goto P_0c0b280c;
case 0x0c0b280eu: goto P_0c0b280e;
case 0x0c0b2810u: goto P_0c0b2810;
case 0x0c0b2812u: goto P_0c0b2812;
case 0x0c0b2814u: goto P_0c0b2814;
case 0x0c0b2816u: goto P_0c0b2816;
case 0x0c0b2818u: goto P_0c0b2818;
case 0x0c0b281au: goto P_0c0b281a;
case 0x0c0b281cu: goto P_0c0b281c;
case 0x0c0b281eu: goto P_0c0b281e;
case 0x0c0b2820u: goto P_0c0b2820;
case 0x0c0b2822u: goto P_0c0b2822;
case 0x0c0b2824u: goto P_0c0b2824;
case 0x0c0b2826u: goto P_0c0b2826;
case 0x0c0b2828u: goto P_0c0b2828;
case 0x0c0b282au: goto P_0c0b282a;
case 0x0c0b282cu: goto P_0c0b282c;
case 0x0c0b282eu: goto P_0c0b282e;
case 0x0c0b2830u: goto P_0c0b2830;
case 0x0c0b2832u: goto P_0c0b2832;
case 0x0c0b2834u: goto P_0c0b2834;
case 0x0c0b2836u: goto P_0c0b2836;
case 0x0c0b2838u: goto P_0c0b2838;
case 0x0c0b283au: goto P_0c0b283a;
case 0x0c0b283cu: goto P_0c0b283c;
case 0x0c0b283eu: goto P_0c0b283e;
case 0x0c0b2840u: goto P_0c0b2840;
case 0x0c0b2842u: goto P_0c0b2842;
case 0x0c0b2844u: goto P_0c0b2844;
case 0x0c0b2846u: goto P_0c0b2846;
case 0x0c0b2848u: goto P_0c0b2848;
case 0x0c0b284au: goto P_0c0b284a;
case 0x0c0b284cu: goto P_0c0b284c;
case 0x0c0b284eu: goto P_0c0b284e;
case 0x0c0b2850u: goto P_0c0b2850;
case 0x0c0b2852u: goto P_0c0b2852;
case 0x0c0b2854u: goto P_0c0b2854;
case 0x0c0b2856u: goto P_0c0b2856;
case 0x0c0b2858u: goto P_0c0b2858;
case 0x0c0b285au: goto P_0c0b285a;
case 0x0c0b285cu: goto P_0c0b285c;
case 0x0c0b285eu: goto P_0c0b285e;
case 0x0c0b2860u: goto P_0c0b2860;
case 0x0c0b2862u: goto P_0c0b2862;
case 0x0c0b2864u: goto P_0c0b2864;
case 0x0c0b2866u: goto P_0c0b2866;
case 0x0c0b2868u: goto P_0c0b2868;
case 0x0c0b286au: goto P_0c0b286a;
case 0x0c0b286cu: goto P_0c0b286c;
case 0x0c0b286eu: goto P_0c0b286e;
case 0x0c0b2870u: goto P_0c0b2870;
case 0x0c0b2872u: goto P_0c0b2872;
case 0x0c0b2874u: goto P_0c0b2874;
case 0x0c0b2876u: goto P_0c0b2876;
case 0x0c0b2878u: goto P_0c0b2878;
case 0x0c0b287au: goto P_0c0b287a;
case 0x0c0b287cu: goto P_0c0b287c;
case 0x0c0b287eu: goto P_0c0b287e;
case 0x0c0b2880u: goto P_0c0b2880;
case 0x0c0b2882u: goto P_0c0b2882;
case 0x0c0b2884u: goto P_0c0b2884;
case 0x0c0b2886u: goto P_0c0b2886;
case 0x0c0b2888u: goto P_0c0b2888;
case 0x0c0b288au: goto P_0c0b288a;
case 0x0c0b288cu: goto P_0c0b288c;
case 0x0c0b288eu: goto P_0c0b288e;
case 0x0c0b2890u: goto P_0c0b2890;
case 0x0c0b2892u: goto P_0c0b2892;
case 0x0c0b2894u: goto P_0c0b2894;
case 0x0c0b2896u: goto P_0c0b2896;
case 0x0c0b2898u: goto P_0c0b2898;
case 0x0c0b289au: goto P_0c0b289a;
case 0x0c0b289cu: goto P_0c0b289c;
case 0x0c0b289eu: goto P_0c0b289e;
case 0x0c0b28a0u: goto P_0c0b28a0;
case 0x0c0b28a2u: goto P_0c0b28a2;
case 0x0c0b28a4u: goto P_0c0b28a4;
case 0x0c0b28a6u: goto P_0c0b28a6;
case 0x0c0b28a8u: goto P_0c0b28a8;
case 0x0c0b28aau: goto P_0c0b28aa;
case 0x0c0b28acu: goto P_0c0b28ac;
case 0x0c0b28aeu: goto P_0c0b28ae;
case 0x0c0b28b0u: goto P_0c0b28b0;
case 0x0c0b28b2u: goto P_0c0b28b2;
case 0x0c0b28b4u: goto P_0c0b28b4;
case 0x0c0b28b6u: goto P_0c0b28b6;
case 0x0c0b28b8u: goto P_0c0b28b8;
case 0x0c0b28bau: goto P_0c0b28ba;
case 0x0c0b28bcu: goto P_0c0b28bc;
case 0x0c0b28beu: goto P_0c0b28be;
case 0x0c0b28c0u: goto P_0c0b28c0;
case 0x0c0b28c2u: goto P_0c0b28c2;
case 0x0c0b28c4u: goto P_0c0b28c4;
case 0x0c0b28c6u: goto P_0c0b28c6;
case 0x0c0b28c8u: goto P_0c0b28c8;
case 0x0c0b28cau: goto P_0c0b28ca;
case 0x0c0b28ccu: goto P_0c0b28cc;
case 0x0c0b28ceu: goto P_0c0b28ce;
case 0x0c0b28d0u: goto P_0c0b28d0;
case 0x0c0b28d2u: goto P_0c0b28d2;
case 0x0c0b28d4u: goto P_0c0b28d4;
case 0x0c0b28d6u: goto P_0c0b28d6;
case 0x0c0b28d8u: goto P_0c0b28d8;
case 0x0c0b28dau: goto P_0c0b28da;
case 0x0c0b28dcu: goto P_0c0b28dc;
case 0x0c0b28deu: goto P_0c0b28de;
case 0x0c0b28e0u: goto P_0c0b28e0;
case 0x0c0b28e2u: goto P_0c0b28e2;
case 0x0c0b28e4u: goto P_0c0b28e4;
case 0x0c0b28e6u: goto P_0c0b28e6;
case 0x0c0b28e8u: goto P_0c0b28e8;
case 0x0c0b28eau: goto P_0c0b28ea;
case 0x0c0b28ecu: goto P_0c0b28ec;
case 0x0c0b28eeu: goto P_0c0b28ee;
case 0x0c0b28f0u: goto P_0c0b28f0;
case 0x0c0b28f2u: goto P_0c0b28f2;
case 0x0c0b28f4u: goto P_0c0b28f4;
case 0x0c0b28f6u: goto P_0c0b28f6;
case 0x0c0b28f8u: goto P_0c0b28f8;
case 0x0c0b28fau: goto P_0c0b28fa;
case 0x0c0b28fcu: goto P_0c0b28fc;
case 0x0c0b28feu: goto P_0c0b28fe;
case 0x0c0b2900u: goto P_0c0b2900;
case 0x0c0b2902u: goto P_0c0b2902;
case 0x0c0b2904u: goto P_0c0b2904;
case 0x0c0b2906u: goto P_0c0b2906;
case 0x0c0b2908u: goto P_0c0b2908;
case 0x0c0b290au: goto P_0c0b290a;
case 0x0c0b290cu: goto P_0c0b290c;
case 0x0c0b290eu: goto P_0c0b290e;
case 0x0c0b2910u: goto P_0c0b2910;
case 0x0c0b2912u: goto P_0c0b2912;
case 0x0c0b2914u: goto P_0c0b2914;
case 0x0c0b2916u: goto P_0c0b2916;
case 0x0c0b2918u: goto P_0c0b2918;
case 0x0c0b291au: goto P_0c0b291a;
case 0x0c0b291cu: goto P_0c0b291c;
case 0x0c0b291eu: goto P_0c0b291e;
case 0x0c0b2920u: goto P_0c0b2920;
case 0x0c0b2922u: goto P_0c0b2922;
case 0x0c0b2924u: goto P_0c0b2924;
case 0x0c0b2926u: goto P_0c0b2926;
case 0x0c0b2928u: goto P_0c0b2928;
case 0x0c0b292au: goto P_0c0b292a;
case 0x0c0b292cu: goto P_0c0b292c;
case 0x0c0b292eu: goto P_0c0b292e;
case 0x0c0b2930u: goto P_0c0b2930;
case 0x0c0b2932u: goto P_0c0b2932;
case 0x0c0b2934u: goto P_0c0b2934;
case 0x0c0b2936u: goto P_0c0b2936;
case 0x0c0b2938u: goto P_0c0b2938;
case 0x0c0b293au: goto P_0c0b293a;
case 0x0c0b293cu: goto P_0c0b293c;
case 0x0c0b293eu: goto P_0c0b293e;
case 0x0c0b2940u: goto P_0c0b2940;
case 0x0c0b2942u: goto P_0c0b2942;
case 0x0c0b2944u: goto P_0c0b2944;
case 0x0c0b2946u: goto P_0c0b2946;
case 0x0c0b2948u: goto P_0c0b2948;
case 0x0c0b294au: goto P_0c0b294a;
case 0x0c0b294cu: goto P_0c0b294c;
case 0x0c0b294eu: goto P_0c0b294e;
case 0x0c0b2950u: goto P_0c0b2950;
case 0x0c0b2952u: goto P_0c0b2952;
case 0x0c0b2954u: goto P_0c0b2954;
case 0x0c0b29ceu: goto P_0c0b29ce;
case 0x0c0b29d0u: goto P_0c0b29d0;
case 0x0c0b29d2u: goto P_0c0b29d2;
case 0x0c0b29d4u: goto P_0c0b29d4;
case 0x0c0b29d6u: goto P_0c0b29d6;
case 0x0c0b29d8u: goto P_0c0b29d8;
case 0x0c0b29dau: goto P_0c0b29da;
case 0x0c0b29dcu: goto P_0c0b29dc;
case 0x0c0b29deu: goto P_0c0b29de;
case 0x0c0b29e0u: goto P_0c0b29e0;
case 0x0c0b29e2u: goto P_0c0b29e2;
case 0x0c0b29e4u: goto P_0c0b29e4;
case 0x0c0b29e6u: goto P_0c0b29e6;
case 0x0c0b29e8u: goto P_0c0b29e8;
case 0x0c0b29eau: goto P_0c0b29ea;
case 0x0c0b29ecu: goto P_0c0b29ec;
case 0x0c0b29eeu: goto P_0c0b29ee;
case 0x0c0b29f0u: goto P_0c0b29f0;
case 0x0c0b29f2u: goto P_0c0b29f2;
case 0x0c0b29f4u: goto P_0c0b29f4;
case 0x0c0b29f6u: goto P_0c0b29f6;
case 0x0c0b29f8u: goto P_0c0b29f8;
case 0x0c0b29fau: goto P_0c0b29fa;
case 0x0c0b29fcu: goto P_0c0b29fc;
case 0x0c0b29feu: goto P_0c0b29fe;
case 0x0c0b2a00u: goto P_0c0b2a00;
case 0x0c0b2a02u: goto P_0c0b2a02;
case 0x0c0b2a04u: goto P_0c0b2a04;
case 0x0c0b2a06u: goto P_0c0b2a06;
case 0x0c0b2a08u: goto P_0c0b2a08;
case 0x0c0b2a0au: goto P_0c0b2a0a;
case 0x0c0b2a0cu: goto P_0c0b2a0c;
case 0x0c0b2a0eu: goto P_0c0b2a0e;
case 0x0c0b2a10u: goto P_0c0b2a10;
case 0x0c0b2a12u: goto P_0c0b2a12;
case 0x0c0b2a14u: goto P_0c0b2a14;
case 0x0c0b2a16u: goto P_0c0b2a16;
case 0x0c0b2a18u: goto P_0c0b2a18;
case 0x0c0b2a1au: goto P_0c0b2a1a;
case 0x0c0b2a1cu: goto P_0c0b2a1c;
case 0x0c0b2a1eu: goto P_0c0b2a1e;
case 0x0c0b2a20u: goto P_0c0b2a20;
case 0x0c0b2a22u: goto P_0c0b2a22;
case 0x0c0b2a24u: goto P_0c0b2a24;
case 0x0c0b2a26u: goto P_0c0b2a26;
case 0x0c0b2a28u: goto P_0c0b2a28;
case 0x0c0b2a2au: goto P_0c0b2a2a;
case 0x0c0b2a2cu: goto P_0c0b2a2c;
case 0x0c0b2a2eu: goto P_0c0b2a2e;
case 0x0c0b2a30u: goto P_0c0b2a30;
case 0x0c0b2a32u: goto P_0c0b2a32;
case 0x0c0b2a34u: goto P_0c0b2a34;
case 0x0c0b2a36u: goto P_0c0b2a36;
case 0x0c0b2a38u: goto P_0c0b2a38;
case 0x0c0b2a3au: goto P_0c0b2a3a;
case 0x0c0b2a3cu: goto P_0c0b2a3c;
case 0x0c0b2a3eu: goto P_0c0b2a3e;
case 0x0c0b2a40u: goto P_0c0b2a40;
case 0x0c0b2a42u: goto P_0c0b2a42;
case 0x0c0b2a44u: goto P_0c0b2a44;
case 0x0c0b2a46u: goto P_0c0b2a46;
case 0x0c0b2a48u: goto P_0c0b2a48;
case 0x0c0b2a4au: goto P_0c0b2a4a;
case 0x0c0b2a4cu: goto P_0c0b2a4c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b243a: /* original 2fe6, guest PC 0x0c0b243a */
if(!s->budget--) { s->failed_pc=0x0c0b243au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b243c;
P_0c0b243c: /* original e061, guest PC 0x0c0b243c */
if(!s->budget--) { s->failed_pc=0x0c0b243cu; return 0; }
r[0]=0x00000061u;
goto P_0c0b243e;
P_0c0b243e: /* original 2fd6, guest PC 0x0c0b243e */
if(!s->budget--) { s->failed_pc=0x0c0b243eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2440;
P_0c0b2440: /* original 2fc6, guest PC 0x0c0b2440 */
if(!s->budget--) { s->failed_pc=0x0c0b2440u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2442;
P_0c0b2442: /* original 2fb6, guest PC 0x0c0b2442 */
if(!s->budget--) { s->failed_pc=0x0c0b2442u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2444;
P_0c0b2444: /* original 2fa6, guest PC 0x0c0b2444 */
if(!s->budget--) { s->failed_pc=0x0c0b2444u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2446;
P_0c0b2446: /* original d52d, guest PC 0x0c0b2446 */
if(!s->budget--) { s->failed_pc=0x0c0b2446u; return 0; }
r[5]=read(ram,0x0c0b24fcu,4);
goto P_0c0b2448;
P_0c0b2448: /* original d32d, guest PC 0x0c0b2448 */
if(!s->budget--) { s->failed_pc=0x0c0b2448u; return 0; }
r[3]=read(ram,0x0c0b2500u,4);
goto P_0c0b244a;
P_0c0b244a: /* original 5454, guest PC 0x0c0b244a */
if(!s->budget--) { s->failed_pc=0x0c0b244au; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0b244c;
P_0c0b244c: /* original 4f22, guest PC 0x0c0b244c */
if(!s->budget--) { s->failed_pc=0x0c0b244cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b244e;
P_0c0b244e: /* original 074c, guest PC 0x0c0b244e */
if(!s->budget--) { s->failed_pc=0x0c0b244eu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b2450;
P_0c0b2450: /* original 6c32, guest PC 0x0c0b2450 */
if(!s->budget--) { s->failed_pc=0x0c0b2450u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c0b2452;
P_0c0b2452: /* original e334, guest PC 0x0c0b2452 */
if(!s->budget--) { s->failed_pc=0x0c0b2452u; return 0; }
r[3]=0x00000034u;
goto P_0c0b2454;
P_0c0b2454: /* original 607c, guest PC 0x0c0b2454 */
if(!s->budget--) { s->failed_pc=0x0c0b2454u; return 0; }
r[0]=r[7]&255u;
goto P_0c0b2456;
P_0c0b2456: /* original 5655, guest PC 0x0c0b2456 */
if(!s->budget--) { s->failed_pc=0x0c0b2456u; return 0; }
r[6]=read(ram,r[5]+20,4);
goto P_0c0b2458;
P_0c0b2458: /* original 4f12, guest PC 0x0c0b2458 */
if(!s->budget--) { s->failed_pc=0x0c0b2458u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0b245a;
P_0c0b245a: /* original 203f, guest PC 0x0c0b245a */
if(!s->budget--) { s->failed_pc=0x0c0b245au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[3]);
goto P_0c0b245c;
P_0c0b245c: /* original e561, guest PC 0x0c0b245c */
if(!s->budget--) { s->failed_pc=0x0c0b245cu; return 0; }
r[5]=0x00000061u;
goto P_0c0b245e;
P_0c0b245e: /* original d229, guest PC 0x0c0b245e */
if(!s->budget--) { s->failed_pc=0x0c0b245eu; return 0; }
r[2]=read(ram,0x0c0b2504u,4);
goto P_0c0b2460;
P_0c0b2460: /* original 356c, guest PC 0x0c0b2460 */
if(!s->budget--) { s->failed_pc=0x0c0b2460u; return 0; }
r[5]+=r[6];
goto P_0c0b2462;
P_0c0b2462: /* original d129, guest PC 0x0c0b2462 */
if(!s->budget--) { s->failed_pc=0x0c0b2462u; return 0; }
r[1]=read(ram,0x0c0b2508u,4);
goto P_0c0b2464;
P_0c0b2464: /* original 6550, guest PC 0x0c0b2464 */
if(!s->budget--) { s->failed_pc=0x0c0b2464u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c0b2466;
P_0c0b2466: /* original 6b7c, guest PC 0x0c0b2466 */
if(!s->budget--) { s->failed_pc=0x0c0b2466u; return 0; }
r[11]=r[7]&255u;
goto P_0c0b2468;
P_0c0b2468: /* original 001a, guest PC 0x0c0b2468 */
if(!s->budget--) { s->failed_pc=0x0c0b2468u; return 0; }
r[0]=r[19];
goto P_0c0b246a;
P_0c0b246a: /* original 6a5c, guest PC 0x0c0b246a */
if(!s->budget--) { s->failed_pc=0x0c0b246au; return 0; }
r[10]=r[5]&255u;
goto P_0c0b246c;
P_0c0b246c: /* original 6d22, guest PC 0x0c0b246c */
if(!s->budget--) { s->failed_pc=0x0c0b246cu; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c0b246e;
P_0c0b246e: /* original de1d, guest PC 0x0c0b246e */
if(!s->budget--) { s->failed_pc=0x0c0b246eu; return 0; }
r[14]=read(ram,0x0c0b24e4u,4);
goto P_0c0b2470;
P_0c0b2470: /* original 4a08, guest PC 0x0c0b2470 */
if(!s->budget--) { s->failed_pc=0x0c0b2470u; return 0; }
r[10]<<=2;
goto P_0c0b2472;
P_0c0b2472: /* original 600f, guest PC 0x0c0b2472 */
if(!s->budget--) { s->failed_pc=0x0c0b2472u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0b2474;
P_0c0b2474: /* original 310c, guest PC 0x0c0b2474 */
if(!s->budget--) { s->failed_pc=0x0c0b2474u; return 0; }
r[1]+=r[0];
goto P_0c0b2476;
P_0c0b2476: /* original 4b08, guest PC 0x0c0b2476 */
if(!s->budget--) { s->failed_pc=0x0c0b2476u; return 0; }
r[11]<<=2;
goto P_0c0b2478;
P_0c0b2478: /* original 3a1c, guest PC 0x0c0b2478 */
if(!s->budget--) { s->failed_pc=0x0c0b2478u; return 0; }
r[10]+=r[1];
goto P_0c0b247a;
P_0c0b247a: /* original 902f, guest PC 0x0c0b247a */
if(!s->budget--) { s->failed_pc=0x0c0b247au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b24dcu,2);
goto P_0c0b247c;
P_0c0b247c: /* original 4b08, guest PC 0x0c0b247c */
if(!s->budget--) { s->failed_pc=0x0c0b247cu; return 0; }
r[11]<<=2;
goto P_0c0b247e;
P_0c0b247e: /* original 655c, guest PC 0x0c0b247e */
if(!s->budget--) { s->failed_pc=0x0c0b247eu; return 0; }
r[5]=r[5]&255u;
goto P_0c0b2480;
P_0c0b2480: /* original 01ee, guest PC 0x0c0b2480 */
if(!s->budget--) { s->failed_pc=0x0c0b2480u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0b2482;
P_0c0b2482: /* original 2b5b, guest PC 0x0c0b2482 */
if(!s->budget--) { s->failed_pc=0x0c0b2482u; return 0; }
r[11]|=r[5];
goto P_0c0b2484;
P_0c0b2484: /* original 3b10, guest PC 0x0c0b2484 */
if(!s->budget--) { s->failed_pc=0x0c0b2484u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[1])!=0);
goto P_0c0b2486;
P_0c0b2486: /* original 8d10, guest PC 0x0c0b2486 */
if(!s->budget--) { s->failed_pc=0x0c0b2486u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[10],4);
r[10]=tmp;
if(cond) { goto P_0c0b24aa; }
goto P_0c0b248a;
P_0c0b2488: /* original 6aa2, guest PC 0x0c0b2488 */
if(!s->budget--) { s->failed_pc=0x0c0b2488u; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c0b248a;
P_0c0b248a: /* original 9028, guest PC 0x0c0b248a */
if(!s->budget--) { s->failed_pc=0x0c0b248au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b24deu,2);
goto P_0c0b248c;
P_0c0b248c: /* original 65c3, guest PC 0x0c0b248c */
if(!s->budget--) { s->failed_pc=0x0c0b248cu; return 0; }
r[5]=r[12];
goto P_0c0b248e;
P_0c0b248e: /* original 0ec6, guest PC 0x0c0b248e */
if(!s->budget--) { s->failed_pc=0x0c0b248eu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0b2490;
P_0c0b2490: /* original d31e, guest PC 0x0c0b2490 */
if(!s->budget--) { s->failed_pc=0x0c0b2490u; return 0; }
r[3]=read(ram,0x0c0b250cu,4);
goto P_0c0b2492;
P_0c0b2492: /* original 430b, guest PC 0x0c0b2492 */
if(!s->budget--) { s->failed_pc=0x0c0b2492u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b2496u;
r[4]=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2496u) { target=s->pc; goto dispatch; }
goto P_0c0b2496;
P_0c0b2494: /* original e444, guest PC 0x0c0b2494 */
if(!s->budget--) { s->failed_pc=0x0c0b2494u; return 0; }
r[4]=0x00000044u;
goto P_0c0b2496;
P_0c0b2496: /* original 9023, guest PC 0x0c0b2496 */
if(!s->budget--) { s->failed_pc=0x0c0b2496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b24e0u,2);
goto P_0c0b2498;
P_0c0b2498: /* original 65d3, guest PC 0x0c0b2498 */
if(!s->budget--) { s->failed_pc=0x0c0b2498u; return 0; }
r[5]=r[13];
goto P_0c0b249a;
P_0c0b249a: /* original 0ed6, guest PC 0x0c0b249a */
if(!s->budget--) { s->failed_pc=0x0c0b249au; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0b249c;
P_0c0b249c: /* original 7004, guest PC 0x0c0b249c */
if(!s->budget--) { s->failed_pc=0x0c0b249cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0b249e;
P_0c0b249e: /* original 0ea6, guest PC 0x0c0b249e */
if(!s->budget--) { s->failed_pc=0x0c0b249eu; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0b24a0;
P_0c0b24a0: /* original d31a, guest PC 0x0c0b24a0 */
if(!s->budget--) { s->failed_pc=0x0c0b24a0u; return 0; }
r[3]=read(ram,0x0c0b250cu,4);
goto P_0c0b24a2;
P_0c0b24a2: /* original 430b, guest PC 0x0c0b24a2 */
if(!s->budget--) { s->failed_pc=0x0c0b24a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b24a6u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b24a6u) { target=s->pc; goto dispatch; }
goto P_0c0b24a6;
P_0c0b24a4: /* original 64a3, guest PC 0x0c0b24a4 */
if(!s->budget--) { s->failed_pc=0x0c0b24a4u; return 0; }
r[4]=r[10];
goto P_0c0b24a6;
P_0c0b24a6: /* original 9019, guest PC 0x0c0b24a6 */
if(!s->budget--) { s->failed_pc=0x0c0b24a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b24dcu,2);
goto P_0c0b24a8;
P_0c0b24a8: /* original 0eb6, guest PC 0x0c0b24a8 */
if(!s->budget--) { s->failed_pc=0x0c0b24a8u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c0b24aa;
P_0c0b24aa: /* original 4f16, guest PC 0x0c0b24aa */
if(!s->budget--) { s->failed_pc=0x0c0b24aau; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b24ac;
P_0c0b24ac: /* original 4f26, guest PC 0x0c0b24ac */
if(!s->budget--) { s->failed_pc=0x0c0b24acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b24ae;
P_0c0b24ae: /* original 6af6, guest PC 0x0c0b24ae */
if(!s->budget--) { s->failed_pc=0x0c0b24aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b24b0;
P_0c0b24b0: /* original 6bf6, guest PC 0x0c0b24b0 */
if(!s->budget--) { s->failed_pc=0x0c0b24b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b24b2;
P_0c0b24b2: /* original 6cf6, guest PC 0x0c0b24b2 */
if(!s->budget--) { s->failed_pc=0x0c0b24b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b24b4;
P_0c0b24b4: /* original 6df6, guest PC 0x0c0b24b4 */
if(!s->budget--) { s->failed_pc=0x0c0b24b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b24b6;
P_0c0b24b6: /* original 000b, guest PC 0x0c0b24b6 */
if(!s->budget--) { s->failed_pc=0x0c0b24b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b24b8: /* original 6ef6, guest PC 0x0c0b24b8 */
if(!s->budget--) { s->failed_pc=0x0c0b24b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b24bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b24bau; return 0; } return 1;
P_0c0b2628: /* original 2fe6, guest PC 0x0c0b2628 */
if(!s->budget--) { s->failed_pc=0x0c0b2628u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b262a;
P_0c0b262a: /* original 2fd6, guest PC 0x0c0b262a */
if(!s->budget--) { s->failed_pc=0x0c0b262au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b262c;
P_0c0b262c: /* original 2fc6, guest PC 0x0c0b262c */
if(!s->budget--) { s->failed_pc=0x0c0b262cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b262e;
P_0c0b262e: /* original 2fb6, guest PC 0x0c0b262e */
if(!s->budget--) { s->failed_pc=0x0c0b262eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2630;
P_0c0b2630: /* original 2fa6, guest PC 0x0c0b2630 */
if(!s->budget--) { s->failed_pc=0x0c0b2630u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2632;
P_0c0b2632: /* original 2f96, guest PC 0x0c0b2632 */
if(!s->budget--) { s->failed_pc=0x0c0b2632u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2634;
P_0c0b2634: /* original 4f22, guest PC 0x0c0b2634 */
if(!s->budget--) { s->failed_pc=0x0c0b2634u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b2636;
P_0c0b2636: /* original 5d44, guest PC 0x0c0b2636 */
if(!s->budget--) { s->failed_pc=0x0c0b2636u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b2638;
P_0c0b2638: /* original 94a8, guest PC 0x0c0b2638 */
if(!s->budget--) { s->failed_pc=0x0c0b2638u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b278cu,2);
goto P_0c0b263a;
P_0c0b263a: /* original de6f, guest PC 0x0c0b263a */
if(!s->budget--) { s->failed_pc=0x0c0b263au; return 0; }
r[14]=read(ram,0x0c0b27f8u,4);
goto P_0c0b263c;
P_0c0b263c: /* original 7ff8, guest PC 0x0c0b263c */
if(!s->budget--) { s->failed_pc=0x0c0b263cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b263e;
P_0c0b263e: /* original 4e0b, guest PC 0x0c0b263e */
if(!s->budget--) { s->failed_pc=0x0c0b263eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2642u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2642u) { target=s->pc; goto dispatch; }
goto P_0c0b2642;
P_0c0b2640: /* original 65d2, guest PC 0x0c0b2640 */
if(!s->budget--) { s->failed_pc=0x0c0b2640u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b2642;
P_0c0b2642: /* original 94a4, guest PC 0x0c0b2642 */
if(!s->budget--) { s->failed_pc=0x0c0b2642u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b278eu,2);
goto P_0c0b2644;
P_0c0b2644: /* original 4e0b, guest PC 0x0c0b2644 */
if(!s->budget--) { s->failed_pc=0x0c0b2644u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2648u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2648u) { target=s->pc; goto dispatch; }
goto P_0c0b2648;
P_0c0b2646: /* original 55d1, guest PC 0x0c0b2646 */
if(!s->budget--) { s->failed_pc=0x0c0b2646u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b2648;
P_0c0b2648: /* original 94a2, guest PC 0x0c0b2648 */
if(!s->budget--) { s->failed_pc=0x0c0b2648u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2790u,2);
goto P_0c0b264a;
P_0c0b264a: /* original 4e0b, guest PC 0x0c0b264a */
if(!s->budget--) { s->failed_pc=0x0c0b264au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b264eu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b264eu) { target=s->pc; goto dispatch; }
goto P_0c0b264e;
P_0c0b264c: /* original 55d2, guest PC 0x0c0b264c */
if(!s->budget--) { s->failed_pc=0x0c0b264cu; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b264e;
P_0c0b264e: /* original 94a0, guest PC 0x0c0b264e */
if(!s->budget--) { s->failed_pc=0x0c0b264eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2792u,2);
goto P_0c0b2650;
P_0c0b2650: /* original 4e0b, guest PC 0x0c0b2650 */
if(!s->budget--) { s->failed_pc=0x0c0b2650u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2654u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2654u) { target=s->pc; goto dispatch; }
goto P_0c0b2654;
P_0c0b2652: /* original 55d3, guest PC 0x0c0b2652 */
if(!s->budget--) { s->failed_pc=0x0c0b2652u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b2654;
P_0c0b2654: /* original 949e, guest PC 0x0c0b2654 */
if(!s->budget--) { s->failed_pc=0x0c0b2654u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2794u,2);
goto P_0c0b2656;
P_0c0b2656: /* original 4e0b, guest PC 0x0c0b2656 */
if(!s->budget--) { s->failed_pc=0x0c0b2656u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b265au;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b265au) { target=s->pc; goto dispatch; }
goto P_0c0b265a;
P_0c0b2658: /* original 55d4, guest PC 0x0c0b2658 */
if(!s->budget--) { s->failed_pc=0x0c0b2658u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b265a;
P_0c0b265a: /* original 949c, guest PC 0x0c0b265a */
if(!s->budget--) { s->failed_pc=0x0c0b265au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2796u,2);
goto P_0c0b265c;
P_0c0b265c: /* original 4e0b, guest PC 0x0c0b265c */
if(!s->budget--) { s->failed_pc=0x0c0b265cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2660u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2660u) { target=s->pc; goto dispatch; }
goto P_0c0b2660;
P_0c0b265e: /* original 55d5, guest PC 0x0c0b265e */
if(!s->budget--) { s->failed_pc=0x0c0b265eu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b2660;
P_0c0b2660: /* original 949a, guest PC 0x0c0b2660 */
if(!s->budget--) { s->failed_pc=0x0c0b2660u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2798u,2);
goto P_0c0b2662;
P_0c0b2662: /* original 4e0b, guest PC 0x0c0b2662 */
if(!s->budget--) { s->failed_pc=0x0c0b2662u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2666u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2666u) { target=s->pc; goto dispatch; }
goto P_0c0b2666;
P_0c0b2664: /* original 55d6, guest PC 0x0c0b2664 */
if(!s->budget--) { s->failed_pc=0x0c0b2664u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b2666;
P_0c0b2666: /* original 9498, guest PC 0x0c0b2666 */
if(!s->budget--) { s->failed_pc=0x0c0b2666u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b279au,2);
goto P_0c0b2668;
P_0c0b2668: /* original 4e0b, guest PC 0x0c0b2668 */
if(!s->budget--) { s->failed_pc=0x0c0b2668u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b266cu;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b266cu) { target=s->pc; goto dispatch; }
goto P_0c0b266c;
P_0c0b266a: /* original 55d7, guest PC 0x0c0b266a */
if(!s->budget--) { s->failed_pc=0x0c0b266au; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b266c;
P_0c0b266c: /* original 9496, guest PC 0x0c0b266c */
if(!s->budget--) { s->failed_pc=0x0c0b266cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b279cu,2);
goto P_0c0b266e;
P_0c0b266e: /* original 4e0b, guest PC 0x0c0b266e */
if(!s->budget--) { s->failed_pc=0x0c0b266eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2672u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2672u) { target=s->pc; goto dispatch; }
goto P_0c0b2672;
P_0c0b2670: /* original 55d8, guest PC 0x0c0b2670 */
if(!s->budget--) { s->failed_pc=0x0c0b2670u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b2672;
P_0c0b2672: /* original 9494, guest PC 0x0c0b2672 */
if(!s->budget--) { s->failed_pc=0x0c0b2672u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b279eu,2);
goto P_0c0b2674;
P_0c0b2674: /* original 4e0b, guest PC 0x0c0b2674 */
if(!s->budget--) { s->failed_pc=0x0c0b2674u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2678u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2678u) { target=s->pc; goto dispatch; }
goto P_0c0b2678;
P_0c0b2676: /* original 55d9, guest PC 0x0c0b2676 */
if(!s->budget--) { s->failed_pc=0x0c0b2676u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b2678;
P_0c0b2678: /* original 9492, guest PC 0x0c0b2678 */
if(!s->budget--) { s->failed_pc=0x0c0b2678u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27a0u,2);
goto P_0c0b267a;
P_0c0b267a: /* original 4e0b, guest PC 0x0c0b267a */
if(!s->budget--) { s->failed_pc=0x0c0b267au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b267eu;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b267eu) { target=s->pc; goto dispatch; }
goto P_0c0b267e;
P_0c0b267c: /* original 55da, guest PC 0x0c0b267c */
if(!s->budget--) { s->failed_pc=0x0c0b267cu; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b267e;
P_0c0b267e: /* original 9490, guest PC 0x0c0b267e */
if(!s->budget--) { s->failed_pc=0x0c0b267eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27a2u,2);
goto P_0c0b2680;
P_0c0b2680: /* original 4e0b, guest PC 0x0c0b2680 */
if(!s->budget--) { s->failed_pc=0x0c0b2680u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2684u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2684u) { target=s->pc; goto dispatch; }
goto P_0c0b2684;
P_0c0b2682: /* original 55db, guest PC 0x0c0b2682 */
if(!s->budget--) { s->failed_pc=0x0c0b2682u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b2684;
P_0c0b2684: /* original 948e, guest PC 0x0c0b2684 */
if(!s->budget--) { s->failed_pc=0x0c0b2684u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27a4u,2);
goto P_0c0b2686;
P_0c0b2686: /* original 4e0b, guest PC 0x0c0b2686 */
if(!s->budget--) { s->failed_pc=0x0c0b2686u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b268au;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b268au) { target=s->pc; goto dispatch; }
goto P_0c0b268a;
P_0c0b2688: /* original 55dc, guest PC 0x0c0b2688 */
if(!s->budget--) { s->failed_pc=0x0c0b2688u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b268a;
P_0c0b268a: /* original 948c, guest PC 0x0c0b268a */
if(!s->budget--) { s->failed_pc=0x0c0b268au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27a6u,2);
goto P_0c0b268c;
P_0c0b268c: /* original 4e0b, guest PC 0x0c0b268c */
if(!s->budget--) { s->failed_pc=0x0c0b268cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2690u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2690u) { target=s->pc; goto dispatch; }
goto P_0c0b2690;
P_0c0b268e: /* original 55dd, guest PC 0x0c0b268e */
if(!s->budget--) { s->failed_pc=0x0c0b268eu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b2690;
P_0c0b2690: /* original 948a, guest PC 0x0c0b2690 */
if(!s->budget--) { s->failed_pc=0x0c0b2690u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27a8u,2);
goto P_0c0b2692;
P_0c0b2692: /* original 4e0b, guest PC 0x0c0b2692 */
if(!s->budget--) { s->failed_pc=0x0c0b2692u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2696u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2696u) { target=s->pc; goto dispatch; }
goto P_0c0b2696;
P_0c0b2694: /* original 55de, guest PC 0x0c0b2694 */
if(!s->budget--) { s->failed_pc=0x0c0b2694u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b2696;
P_0c0b2696: /* original 9488, guest PC 0x0c0b2696 */
if(!s->budget--) { s->failed_pc=0x0c0b2696u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27aau,2);
goto P_0c0b2698;
P_0c0b2698: /* original 4e0b, guest PC 0x0c0b2698 */
if(!s->budget--) { s->failed_pc=0x0c0b2698u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b269cu;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b269cu) { target=s->pc; goto dispatch; }
goto P_0c0b269c;
P_0c0b269a: /* original 55df, guest PC 0x0c0b269a */
if(!s->budget--) { s->failed_pc=0x0c0b269au; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b269c;
P_0c0b269c: /* original 9486, guest PC 0x0c0b269c */
if(!s->budget--) { s->failed_pc=0x0c0b269cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27acu,2);
goto P_0c0b269e;
P_0c0b269e: /* original e040, guest PC 0x0c0b269e */
if(!s->budget--) { s->failed_pc=0x0c0b269eu; return 0; }
r[0]=0x00000040u;
goto P_0c0b26a0;
P_0c0b26a0: /* original 4e0b, guest PC 0x0c0b26a0 */
if(!s->budget--) { s->failed_pc=0x0c0b26a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26a4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26a4u) { target=s->pc; goto dispatch; }
goto P_0c0b26a4;
P_0c0b26a2: /* original 05de, guest PC 0x0c0b26a2 */
if(!s->budget--) { s->failed_pc=0x0c0b26a2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26a4;
P_0c0b26a4: /* original 9483, guest PC 0x0c0b26a4 */
if(!s->budget--) { s->failed_pc=0x0c0b26a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27aeu,2);
goto P_0c0b26a6;
P_0c0b26a6: /* original e044, guest PC 0x0c0b26a6 */
if(!s->budget--) { s->failed_pc=0x0c0b26a6u; return 0; }
r[0]=0x00000044u;
goto P_0c0b26a8;
P_0c0b26a8: /* original 4e0b, guest PC 0x0c0b26a8 */
if(!s->budget--) { s->failed_pc=0x0c0b26a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26acu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26acu) { target=s->pc; goto dispatch; }
goto P_0c0b26ac;
P_0c0b26aa: /* original 05de, guest PC 0x0c0b26aa */
if(!s->budget--) { s->failed_pc=0x0c0b26aau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26ac;
P_0c0b26ac: /* original 9480, guest PC 0x0c0b26ac */
if(!s->budget--) { s->failed_pc=0x0c0b26acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27b0u,2);
goto P_0c0b26ae;
P_0c0b26ae: /* original e048, guest PC 0x0c0b26ae */
if(!s->budget--) { s->failed_pc=0x0c0b26aeu; return 0; }
r[0]=0x00000048u;
goto P_0c0b26b0;
P_0c0b26b0: /* original 4e0b, guest PC 0x0c0b26b0 */
if(!s->budget--) { s->failed_pc=0x0c0b26b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26b4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26b4u) { target=s->pc; goto dispatch; }
goto P_0c0b26b4;
P_0c0b26b2: /* original 05de, guest PC 0x0c0b26b2 */
if(!s->budget--) { s->failed_pc=0x0c0b26b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26b4;
P_0c0b26b4: /* original 947d, guest PC 0x0c0b26b4 */
if(!s->budget--) { s->failed_pc=0x0c0b26b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27b2u,2);
goto P_0c0b26b6;
P_0c0b26b6: /* original e04c, guest PC 0x0c0b26b6 */
if(!s->budget--) { s->failed_pc=0x0c0b26b6u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b26b8;
P_0c0b26b8: /* original 4e0b, guest PC 0x0c0b26b8 */
if(!s->budget--) { s->failed_pc=0x0c0b26b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26bcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26bcu) { target=s->pc; goto dispatch; }
goto P_0c0b26bc;
P_0c0b26ba: /* original 05de, guest PC 0x0c0b26ba */
if(!s->budget--) { s->failed_pc=0x0c0b26bau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26bc;
P_0c0b26bc: /* original 947a, guest PC 0x0c0b26bc */
if(!s->budget--) { s->failed_pc=0x0c0b26bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27b4u,2);
goto P_0c0b26be;
P_0c0b26be: /* original e050, guest PC 0x0c0b26be */
if(!s->budget--) { s->failed_pc=0x0c0b26beu; return 0; }
r[0]=0x00000050u;
goto P_0c0b26c0;
P_0c0b26c0: /* original 4e0b, guest PC 0x0c0b26c0 */
if(!s->budget--) { s->failed_pc=0x0c0b26c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26c4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26c4u) { target=s->pc; goto dispatch; }
goto P_0c0b26c4;
P_0c0b26c2: /* original 05de, guest PC 0x0c0b26c2 */
if(!s->budget--) { s->failed_pc=0x0c0b26c2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26c4;
P_0c0b26c4: /* original 9477, guest PC 0x0c0b26c4 */
if(!s->budget--) { s->failed_pc=0x0c0b26c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27b6u,2);
goto P_0c0b26c6;
P_0c0b26c6: /* original e054, guest PC 0x0c0b26c6 */
if(!s->budget--) { s->failed_pc=0x0c0b26c6u; return 0; }
r[0]=0x00000054u;
goto P_0c0b26c8;
P_0c0b26c8: /* original 4e0b, guest PC 0x0c0b26c8 */
if(!s->budget--) { s->failed_pc=0x0c0b26c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26ccu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26ccu) { target=s->pc; goto dispatch; }
goto P_0c0b26cc;
P_0c0b26ca: /* original 05de, guest PC 0x0c0b26ca */
if(!s->budget--) { s->failed_pc=0x0c0b26cau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26cc;
P_0c0b26cc: /* original 9474, guest PC 0x0c0b26cc */
if(!s->budget--) { s->failed_pc=0x0c0b26ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27b8u,2);
goto P_0c0b26ce;
P_0c0b26ce: /* original e058, guest PC 0x0c0b26ce */
if(!s->budget--) { s->failed_pc=0x0c0b26ceu; return 0; }
r[0]=0x00000058u;
goto P_0c0b26d0;
P_0c0b26d0: /* original 4e0b, guest PC 0x0c0b26d0 */
if(!s->budget--) { s->failed_pc=0x0c0b26d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26d4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26d4u) { target=s->pc; goto dispatch; }
goto P_0c0b26d4;
P_0c0b26d2: /* original 05de, guest PC 0x0c0b26d2 */
if(!s->budget--) { s->failed_pc=0x0c0b26d2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26d4;
P_0c0b26d4: /* original 9471, guest PC 0x0c0b26d4 */
if(!s->budget--) { s->failed_pc=0x0c0b26d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27bau,2);
goto P_0c0b26d6;
P_0c0b26d6: /* original e05c, guest PC 0x0c0b26d6 */
if(!s->budget--) { s->failed_pc=0x0c0b26d6u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b26d8;
P_0c0b26d8: /* original 4e0b, guest PC 0x0c0b26d8 */
if(!s->budget--) { s->failed_pc=0x0c0b26d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26dcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26dcu) { target=s->pc; goto dispatch; }
goto P_0c0b26dc;
P_0c0b26da: /* original 05de, guest PC 0x0c0b26da */
if(!s->budget--) { s->failed_pc=0x0c0b26dau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26dc;
P_0c0b26dc: /* original 946e, guest PC 0x0c0b26dc */
if(!s->budget--) { s->failed_pc=0x0c0b26dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27bcu,2);
goto P_0c0b26de;
P_0c0b26de: /* original e060, guest PC 0x0c0b26de */
if(!s->budget--) { s->failed_pc=0x0c0b26deu; return 0; }
r[0]=0x00000060u;
goto P_0c0b26e0;
P_0c0b26e0: /* original 4e0b, guest PC 0x0c0b26e0 */
if(!s->budget--) { s->failed_pc=0x0c0b26e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26e4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26e4u) { target=s->pc; goto dispatch; }
goto P_0c0b26e4;
P_0c0b26e2: /* original 05de, guest PC 0x0c0b26e2 */
if(!s->budget--) { s->failed_pc=0x0c0b26e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26e4;
P_0c0b26e4: /* original 946b, guest PC 0x0c0b26e4 */
if(!s->budget--) { s->failed_pc=0x0c0b26e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27beu,2);
goto P_0c0b26e6;
P_0c0b26e6: /* original e064, guest PC 0x0c0b26e6 */
if(!s->budget--) { s->failed_pc=0x0c0b26e6u; return 0; }
r[0]=0x00000064u;
goto P_0c0b26e8;
P_0c0b26e8: /* original 4e0b, guest PC 0x0c0b26e8 */
if(!s->budget--) { s->failed_pc=0x0c0b26e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26ecu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26ecu) { target=s->pc; goto dispatch; }
goto P_0c0b26ec;
P_0c0b26ea: /* original 05de, guest PC 0x0c0b26ea */
if(!s->budget--) { s->failed_pc=0x0c0b26eau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26ec;
P_0c0b26ec: /* original 9468, guest PC 0x0c0b26ec */
if(!s->budget--) { s->failed_pc=0x0c0b26ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27c0u,2);
goto P_0c0b26ee;
P_0c0b26ee: /* original e068, guest PC 0x0c0b26ee */
if(!s->budget--) { s->failed_pc=0x0c0b26eeu; return 0; }
r[0]=0x00000068u;
goto P_0c0b26f0;
P_0c0b26f0: /* original 4e0b, guest PC 0x0c0b26f0 */
if(!s->budget--) { s->failed_pc=0x0c0b26f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26f4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26f4u) { target=s->pc; goto dispatch; }
goto P_0c0b26f4;
P_0c0b26f2: /* original 05de, guest PC 0x0c0b26f2 */
if(!s->budget--) { s->failed_pc=0x0c0b26f2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26f4;
P_0c0b26f4: /* original 9465, guest PC 0x0c0b26f4 */
if(!s->budget--) { s->failed_pc=0x0c0b26f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27c2u,2);
goto P_0c0b26f6;
P_0c0b26f6: /* original e06c, guest PC 0x0c0b26f6 */
if(!s->budget--) { s->failed_pc=0x0c0b26f6u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b26f8;
P_0c0b26f8: /* original 4e0b, guest PC 0x0c0b26f8 */
if(!s->budget--) { s->failed_pc=0x0c0b26f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b26fcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b26fcu) { target=s->pc; goto dispatch; }
goto P_0c0b26fc;
P_0c0b26fa: /* original 05de, guest PC 0x0c0b26fa */
if(!s->budget--) { s->failed_pc=0x0c0b26fau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b26fc;
P_0c0b26fc: /* original 9462, guest PC 0x0c0b26fc */
if(!s->budget--) { s->failed_pc=0x0c0b26fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27c4u,2);
goto P_0c0b26fe;
P_0c0b26fe: /* original e070, guest PC 0x0c0b26fe */
if(!s->budget--) { s->failed_pc=0x0c0b26feu; return 0; }
r[0]=0x00000070u;
goto P_0c0b2700;
P_0c0b2700: /* original 4e0b, guest PC 0x0c0b2700 */
if(!s->budget--) { s->failed_pc=0x0c0b2700u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2704u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2704u) { target=s->pc; goto dispatch; }
goto P_0c0b2704;
P_0c0b2702: /* original 05de, guest PC 0x0c0b2702 */
if(!s->budget--) { s->failed_pc=0x0c0b2702u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2704;
P_0c0b2704: /* original 945f, guest PC 0x0c0b2704 */
if(!s->budget--) { s->failed_pc=0x0c0b2704u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27c6u,2);
goto P_0c0b2706;
P_0c0b2706: /* original e074, guest PC 0x0c0b2706 */
if(!s->budget--) { s->failed_pc=0x0c0b2706u; return 0; }
r[0]=0x00000074u;
goto P_0c0b2708;
P_0c0b2708: /* original 4e0b, guest PC 0x0c0b2708 */
if(!s->budget--) { s->failed_pc=0x0c0b2708u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b270cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b270cu) { target=s->pc; goto dispatch; }
goto P_0c0b270c;
P_0c0b270a: /* original 05de, guest PC 0x0c0b270a */
if(!s->budget--) { s->failed_pc=0x0c0b270au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b270c;
P_0c0b270c: /* original 945c, guest PC 0x0c0b270c */
if(!s->budget--) { s->failed_pc=0x0c0b270cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27c8u,2);
goto P_0c0b270e;
P_0c0b270e: /* original e078, guest PC 0x0c0b270e */
if(!s->budget--) { s->failed_pc=0x0c0b270eu; return 0; }
r[0]=0x00000078u;
goto P_0c0b2710;
P_0c0b2710: /* original 4e0b, guest PC 0x0c0b2710 */
if(!s->budget--) { s->failed_pc=0x0c0b2710u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2714u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2714u) { target=s->pc; goto dispatch; }
goto P_0c0b2714;
P_0c0b2712: /* original 05de, guest PC 0x0c0b2712 */
if(!s->budget--) { s->failed_pc=0x0c0b2712u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2714;
P_0c0b2714: /* original 9459, guest PC 0x0c0b2714 */
if(!s->budget--) { s->failed_pc=0x0c0b2714u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27cau,2);
goto P_0c0b2716;
P_0c0b2716: /* original e07c, guest PC 0x0c0b2716 */
if(!s->budget--) { s->failed_pc=0x0c0b2716u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b2718;
P_0c0b2718: /* original 4e0b, guest PC 0x0c0b2718 */
if(!s->budget--) { s->failed_pc=0x0c0b2718u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b271cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b271cu) { target=s->pc; goto dispatch; }
goto P_0c0b271c;
P_0c0b271a: /* original 05de, guest PC 0x0c0b271a */
if(!s->budget--) { s->failed_pc=0x0c0b271au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b271c;
P_0c0b271c: /* original 9457, guest PC 0x0c0b271c */
if(!s->budget--) { s->failed_pc=0x0c0b271cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27ceu,2);
goto P_0c0b271e;
P_0c0b271e: /* original 9055, guest PC 0x0c0b271e */
if(!s->budget--) { s->failed_pc=0x0c0b271eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27ccu,2);
goto P_0c0b2720;
P_0c0b2720: /* original 4e0b, guest PC 0x0c0b2720 */
if(!s->budget--) { s->failed_pc=0x0c0b2720u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2724u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2724u) { target=s->pc; goto dispatch; }
goto P_0c0b2724;
P_0c0b2722: /* original 05de, guest PC 0x0c0b2722 */
if(!s->budget--) { s->failed_pc=0x0c0b2722u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2724;
P_0c0b2724: /* original 9554, guest PC 0x0c0b2724 */
if(!s->budget--) { s->failed_pc=0x0c0b2724u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27d0u,2);
goto P_0c0b2726;
P_0c0b2726: /* original 35dc, guest PC 0x0c0b2726 */
if(!s->budget--) { s->failed_pc=0x0c0b2726u; return 0; }
r[5]+=r[13];
goto P_0c0b2728;
P_0c0b2728: /* original 2f52, guest PC 0x0c0b2728 */
if(!s->budget--) { s->failed_pc=0x0c0b2728u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b272a;
P_0c0b272a: /* original 9452, guest PC 0x0c0b272a */
if(!s->budget--) { s->failed_pc=0x0c0b272au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27d2u,2);
goto P_0c0b272c;
P_0c0b272c: /* original 4e0b, guest PC 0x0c0b272c */
if(!s->budget--) { s->failed_pc=0x0c0b272cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2730u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2730u) { target=s->pc; goto dispatch; }
goto P_0c0b2730;
P_0c0b272e: /* original 6552, guest PC 0x0c0b272e */
if(!s->budget--) { s->failed_pc=0x0c0b272eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2730;
P_0c0b2730: /* original 9550, guest PC 0x0c0b2730 */
if(!s->budget--) { s->failed_pc=0x0c0b2730u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27d4u,2);
goto P_0c0b2732;
P_0c0b2732: /* original 35dc, guest PC 0x0c0b2732 */
if(!s->budget--) { s->failed_pc=0x0c0b2732u; return 0; }
r[5]+=r[13];
goto P_0c0b2734;
P_0c0b2734: /* original 1f51, guest PC 0x0c0b2734 */
if(!s->budget--) { s->failed_pc=0x0c0b2734u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b2736;
P_0c0b2736: /* original 944e, guest PC 0x0c0b2736 */
if(!s->budget--) { s->failed_pc=0x0c0b2736u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27d6u,2);
goto P_0c0b2738;
P_0c0b2738: /* original 4e0b, guest PC 0x0c0b2738 */
if(!s->budget--) { s->failed_pc=0x0c0b2738u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b273cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b273cu) { target=s->pc; goto dispatch; }
goto P_0c0b273c;
P_0c0b273a: /* original 6552, guest PC 0x0c0b273a */
if(!s->budget--) { s->failed_pc=0x0c0b273au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b273c;
P_0c0b273c: /* original 944d, guest PC 0x0c0b273c */
if(!s->budget--) { s->failed_pc=0x0c0b273cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27dau,2);
goto P_0c0b273e;
P_0c0b273e: /* original 904b, guest PC 0x0c0b273e */
if(!s->budget--) { s->failed_pc=0x0c0b273eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27d8u,2);
goto P_0c0b2740;
P_0c0b2740: /* original 4e0b, guest PC 0x0c0b2740 */
if(!s->budget--) { s->failed_pc=0x0c0b2740u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2744u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2744u) { target=s->pc; goto dispatch; }
goto P_0c0b2744;
P_0c0b2742: /* original 05de, guest PC 0x0c0b2742 */
if(!s->budget--) { s->failed_pc=0x0c0b2742u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2744;
P_0c0b2744: /* original 944b, guest PC 0x0c0b2744 */
if(!s->budget--) { s->failed_pc=0x0c0b2744u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27deu,2);
goto P_0c0b2746;
P_0c0b2746: /* original 9049, guest PC 0x0c0b2746 */
if(!s->budget--) { s->failed_pc=0x0c0b2746u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27dcu,2);
goto P_0c0b2748;
P_0c0b2748: /* original 4e0b, guest PC 0x0c0b2748 */
if(!s->budget--) { s->failed_pc=0x0c0b2748u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b274cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b274cu) { target=s->pc; goto dispatch; }
goto P_0c0b274c;
P_0c0b274a: /* original 05de, guest PC 0x0c0b274a */
if(!s->budget--) { s->failed_pc=0x0c0b274au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b274c;
P_0c0b274c: /* original 9948, guest PC 0x0c0b274c */
if(!s->budget--) { s->failed_pc=0x0c0b274cu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27e0u,2);
goto P_0c0b274e;
P_0c0b274e: /* original 9448, guest PC 0x0c0b274e */
if(!s->budget--) { s->failed_pc=0x0c0b274eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27e2u,2);
goto P_0c0b2750;
P_0c0b2750: /* original 39dc, guest PC 0x0c0b2750 */
if(!s->budget--) { s->failed_pc=0x0c0b2750u; return 0; }
r[9]+=r[13];
goto P_0c0b2752;
P_0c0b2752: /* original 4e0b, guest PC 0x0c0b2752 */
if(!s->budget--) { s->failed_pc=0x0c0b2752u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2756u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2756u) { target=s->pc; goto dispatch; }
goto P_0c0b2756;
P_0c0b2754: /* original 6592, guest PC 0x0c0b2754 */
if(!s->budget--) { s->failed_pc=0x0c0b2754u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2756;
P_0c0b2756: /* original 9445, guest PC 0x0c0b2756 */
if(!s->budget--) { s->failed_pc=0x0c0b2756u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27e4u,2);
goto P_0c0b2758;
P_0c0b2758: /* original 4e0b, guest PC 0x0c0b2758 */
if(!s->budget--) { s->failed_pc=0x0c0b2758u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b275cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b275cu) { target=s->pc; goto dispatch; }
goto P_0c0b275c;
P_0c0b275a: /* original 6592, guest PC 0x0c0b275a */
if(!s->budget--) { s->failed_pc=0x0c0b275au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b275c;
P_0c0b275c: /* original 9443, guest PC 0x0c0b275c */
if(!s->budget--) { s->failed_pc=0x0c0b275cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27e6u,2);
goto P_0c0b275e;
P_0c0b275e: /* original 4e0b, guest PC 0x0c0b275e */
if(!s->budget--) { s->failed_pc=0x0c0b275eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2762u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2762u) { target=s->pc; goto dispatch; }
goto P_0c0b2762;
P_0c0b2760: /* original 6592, guest PC 0x0c0b2760 */
if(!s->budget--) { s->failed_pc=0x0c0b2760u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2762;
P_0c0b2762: /* original 9441, guest PC 0x0c0b2762 */
if(!s->budget--) { s->failed_pc=0x0c0b2762u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27e8u,2);
goto P_0c0b2764;
P_0c0b2764: /* original 4e0b, guest PC 0x0c0b2764 */
if(!s->budget--) { s->failed_pc=0x0c0b2764u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2768u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2768u) { target=s->pc; goto dispatch; }
goto P_0c0b2768;
P_0c0b2766: /* original 6592, guest PC 0x0c0b2766 */
if(!s->budget--) { s->failed_pc=0x0c0b2766u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2768;
P_0c0b2768: /* original 9c3f, guest PC 0x0c0b2768 */
if(!s->budget--) { s->failed_pc=0x0c0b2768u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27eau,2);
goto P_0c0b276a;
P_0c0b276a: /* original 943f, guest PC 0x0c0b276a */
if(!s->budget--) { s->failed_pc=0x0c0b276au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27ecu,2);
goto P_0c0b276c;
P_0c0b276c: /* original 3cdc, guest PC 0x0c0b276c */
if(!s->budget--) { s->failed_pc=0x0c0b276cu; return 0; }
r[12]+=r[13];
goto P_0c0b276e;
P_0c0b276e: /* original 4e0b, guest PC 0x0c0b276e */
if(!s->budget--) { s->failed_pc=0x0c0b276eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2772u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2772u) { target=s->pc; goto dispatch; }
goto P_0c0b2772;
P_0c0b2770: /* original 65c2, guest PC 0x0c0b2770 */
if(!s->budget--) { s->failed_pc=0x0c0b2770u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b2772;
P_0c0b2772: /* original 943c, guest PC 0x0c0b2772 */
if(!s->budget--) { s->failed_pc=0x0c0b2772u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27eeu,2);
goto P_0c0b2774;
P_0c0b2774: /* original 4e0b, guest PC 0x0c0b2774 */
if(!s->budget--) { s->failed_pc=0x0c0b2774u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2778u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2778u) { target=s->pc; goto dispatch; }
goto P_0c0b2778;
P_0c0b2776: /* original 65c2, guest PC 0x0c0b2776 */
if(!s->budget--) { s->failed_pc=0x0c0b2776u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b2778;
P_0c0b2778: /* original 943a, guest PC 0x0c0b2778 */
if(!s->budget--) { s->failed_pc=0x0c0b2778u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27f0u,2);
goto P_0c0b277a;
P_0c0b277a: /* original 4e0b, guest PC 0x0c0b277a */
if(!s->budget--) { s->failed_pc=0x0c0b277au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b277eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b277eu) { target=s->pc; goto dispatch; }
goto P_0c0b277e;
P_0c0b277c: /* original 65c2, guest PC 0x0c0b277c */
if(!s->budget--) { s->failed_pc=0x0c0b277cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b277e;
P_0c0b277e: /* original 9438, guest PC 0x0c0b277e */
if(!s->budget--) { s->failed_pc=0x0c0b277eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27f2u,2);
goto P_0c0b2780;
P_0c0b2780: /* original 4e0b, guest PC 0x0c0b2780 */
if(!s->budget--) { s->failed_pc=0x0c0b2780u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2784u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2784u) { target=s->pc; goto dispatch; }
goto P_0c0b2784;
P_0c0b2782: /* original 65c2, guest PC 0x0c0b2782 */
if(!s->budget--) { s->failed_pc=0x0c0b2782u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b2784;
P_0c0b2784: /* original 9b36, guest PC 0x0c0b2784 */
if(!s->budget--) { s->failed_pc=0x0c0b2784u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b27f4u,2);
goto P_0c0b2786;
P_0c0b2786: /* original 3bdc, guest PC 0x0c0b2786 */
if(!s->budget--) { s->failed_pc=0x0c0b2786u; return 0; }
r[11]+=r[13];
goto P_0c0b2788;
P_0c0b2788: /* original a038, guest PC 0x0c0b2788 */
if(!s->budget--) { s->failed_pc=0x0c0b2788u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b27fc;
P_0c0b278a: /* original 65b2, guest PC 0x0c0b278a */
if(!s->budget--) { s->failed_pc=0x0c0b278au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b278cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b278cu; return 0; } return 1;
P_0c0b27fc: /* original 94ab, guest PC 0x0c0b27fc */
if(!s->budget--) { s->failed_pc=0x0c0b27fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2956u,2);
goto P_0c0b27fe;
P_0c0b27fe: /* original 4e0b, guest PC 0x0c0b27fe */
if(!s->budget--) { s->failed_pc=0x0c0b27feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2802u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2802u) { target=s->pc; goto dispatch; }
goto P_0c0b2802;
P_0c0b2800: /* original 0009, guest PC 0x0c0b2800 */
if(!s->budget--) { s->failed_pc=0x0c0b2800u; return 0; }
goto P_0c0b2802;
P_0c0b2802: /* original 94a9, guest PC 0x0c0b2802 */
if(!s->budget--) { s->failed_pc=0x0c0b2802u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2958u,2);
goto P_0c0b2804;
P_0c0b2804: /* original 4e0b, guest PC 0x0c0b2804 */
if(!s->budget--) { s->failed_pc=0x0c0b2804u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2808u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2808u) { target=s->pc; goto dispatch; }
goto P_0c0b2808;
P_0c0b2806: /* original 65b2, guest PC 0x0c0b2806 */
if(!s->budget--) { s->failed_pc=0x0c0b2806u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b2808;
P_0c0b2808: /* original 94a7, guest PC 0x0c0b2808 */
if(!s->budget--) { s->failed_pc=0x0c0b2808u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b295au,2);
goto P_0c0b280a;
P_0c0b280a: /* original 4e0b, guest PC 0x0c0b280a */
if(!s->budget--) { s->failed_pc=0x0c0b280au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b280eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b280eu) { target=s->pc; goto dispatch; }
goto P_0c0b280e;
P_0c0b280c: /* original 65b2, guest PC 0x0c0b280c */
if(!s->budget--) { s->failed_pc=0x0c0b280cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b280e;
P_0c0b280e: /* original 94a5, guest PC 0x0c0b280e */
if(!s->budget--) { s->failed_pc=0x0c0b280eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b295cu,2);
goto P_0c0b2810;
P_0c0b2810: /* original 4e0b, guest PC 0x0c0b2810 */
if(!s->budget--) { s->failed_pc=0x0c0b2810u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2814u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2814u) { target=s->pc; goto dispatch; }
goto P_0c0b2814;
P_0c0b2812: /* original 65b2, guest PC 0x0c0b2812 */
if(!s->budget--) { s->failed_pc=0x0c0b2812u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b2814;
P_0c0b2814: /* original 9aa3, guest PC 0x0c0b2814 */
if(!s->budget--) { s->failed_pc=0x0c0b2814u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b295eu,2);
goto P_0c0b2816;
P_0c0b2816: /* original 94a3, guest PC 0x0c0b2816 */
if(!s->budget--) { s->failed_pc=0x0c0b2816u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2960u,2);
goto P_0c0b2818;
P_0c0b2818: /* original 3adc, guest PC 0x0c0b2818 */
if(!s->budget--) { s->failed_pc=0x0c0b2818u; return 0; }
r[10]+=r[13];
goto P_0c0b281a;
P_0c0b281a: /* original 4e0b, guest PC 0x0c0b281a */
if(!s->budget--) { s->failed_pc=0x0c0b281au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b281eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b281eu) { target=s->pc; goto dispatch; }
goto P_0c0b281e;
P_0c0b281c: /* original 65a2, guest PC 0x0c0b281c */
if(!s->budget--) { s->failed_pc=0x0c0b281cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b281e;
P_0c0b281e: /* original 94a0, guest PC 0x0c0b281e */
if(!s->budget--) { s->failed_pc=0x0c0b281eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2962u,2);
goto P_0c0b2820;
P_0c0b2820: /* original 4e0b, guest PC 0x0c0b2820 */
if(!s->budget--) { s->failed_pc=0x0c0b2820u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2824u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2824u) { target=s->pc; goto dispatch; }
goto P_0c0b2824;
P_0c0b2822: /* original 65a2, guest PC 0x0c0b2822 */
if(!s->budget--) { s->failed_pc=0x0c0b2822u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b2824;
P_0c0b2824: /* original 949e, guest PC 0x0c0b2824 */
if(!s->budget--) { s->failed_pc=0x0c0b2824u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2964u,2);
goto P_0c0b2826;
P_0c0b2826: /* original 4e0b, guest PC 0x0c0b2826 */
if(!s->budget--) { s->failed_pc=0x0c0b2826u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b282au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b282au) { target=s->pc; goto dispatch; }
goto P_0c0b282a;
P_0c0b2828: /* original 65a2, guest PC 0x0c0b2828 */
if(!s->budget--) { s->failed_pc=0x0c0b2828u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b282a;
P_0c0b282a: /* original 949c, guest PC 0x0c0b282a */
if(!s->budget--) { s->failed_pc=0x0c0b282au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2966u,2);
goto P_0c0b282c;
P_0c0b282c: /* original 4e0b, guest PC 0x0c0b282c */
if(!s->budget--) { s->failed_pc=0x0c0b282cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2830u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2830u) { target=s->pc; goto dispatch; }
goto P_0c0b2830;
P_0c0b282e: /* original 65a2, guest PC 0x0c0b282e */
if(!s->budget--) { s->failed_pc=0x0c0b282eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b2830;
P_0c0b2830: /* original 949a, guest PC 0x0c0b2830 */
if(!s->budget--) { s->failed_pc=0x0c0b2830u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2968u,2);
goto P_0c0b2832;
P_0c0b2832: /* original 65f2, guest PC 0x0c0b2832 */
if(!s->budget--) { s->failed_pc=0x0c0b2832u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b2834;
P_0c0b2834: /* original 4e0b, guest PC 0x0c0b2834 */
if(!s->budget--) { s->failed_pc=0x0c0b2834u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2838u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2838u) { target=s->pc; goto dispatch; }
goto P_0c0b2838;
P_0c0b2836: /* original 6552, guest PC 0x0c0b2836 */
if(!s->budget--) { s->failed_pc=0x0c0b2836u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2838;
P_0c0b2838: /* original 9497, guest PC 0x0c0b2838 */
if(!s->budget--) { s->failed_pc=0x0c0b2838u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b296au,2);
goto P_0c0b283a;
P_0c0b283a: /* original 55f1, guest PC 0x0c0b283a */
if(!s->budget--) { s->failed_pc=0x0c0b283au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b283c;
P_0c0b283c: /* original 4e0b, guest PC 0x0c0b283c */
if(!s->budget--) { s->failed_pc=0x0c0b283cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2840u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2840u) { target=s->pc; goto dispatch; }
goto P_0c0b2840;
P_0c0b283e: /* original 6552, guest PC 0x0c0b283e */
if(!s->budget--) { s->failed_pc=0x0c0b283eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2840;
P_0c0b2840: /* original 9494, guest PC 0x0c0b2840 */
if(!s->budget--) { s->failed_pc=0x0c0b2840u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b296cu,2);
goto P_0c0b2842;
P_0c0b2842: /* original 4e0b, guest PC 0x0c0b2842 */
if(!s->budget--) { s->failed_pc=0x0c0b2842u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2846u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2846u) { target=s->pc; goto dispatch; }
goto P_0c0b2846;
P_0c0b2844: /* original 6592, guest PC 0x0c0b2844 */
if(!s->budget--) { s->failed_pc=0x0c0b2844u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2846;
P_0c0b2846: /* original 9492, guest PC 0x0c0b2846 */
if(!s->budget--) { s->failed_pc=0x0c0b2846u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b296eu,2);
goto P_0c0b2848;
P_0c0b2848: /* original 4e0b, guest PC 0x0c0b2848 */
if(!s->budget--) { s->failed_pc=0x0c0b2848u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b284cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b284cu) { target=s->pc; goto dispatch; }
goto P_0c0b284c;
P_0c0b284a: /* original 6592, guest PC 0x0c0b284a */
if(!s->budget--) { s->failed_pc=0x0c0b284au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b284c;
P_0c0b284c: /* original 9490, guest PC 0x0c0b284c */
if(!s->budget--) { s->failed_pc=0x0c0b284cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2970u,2);
goto P_0c0b284e;
P_0c0b284e: /* original 4e0b, guest PC 0x0c0b284e */
if(!s->budget--) { s->failed_pc=0x0c0b284eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2852u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2852u) { target=s->pc; goto dispatch; }
goto P_0c0b2852;
P_0c0b2850: /* original 6592, guest PC 0x0c0b2850 */
if(!s->budget--) { s->failed_pc=0x0c0b2850u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2852;
P_0c0b2852: /* original 948e, guest PC 0x0c0b2852 */
if(!s->budget--) { s->failed_pc=0x0c0b2852u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2972u,2);
goto P_0c0b2854;
P_0c0b2854: /* original 4e0b, guest PC 0x0c0b2854 */
if(!s->budget--) { s->failed_pc=0x0c0b2854u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2858u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2858u) { target=s->pc; goto dispatch; }
goto P_0c0b2858;
P_0c0b2856: /* original 6592, guest PC 0x0c0b2856 */
if(!s->budget--) { s->failed_pc=0x0c0b2856u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2858;
P_0c0b2858: /* original 948c, guest PC 0x0c0b2858 */
if(!s->budget--) { s->failed_pc=0x0c0b2858u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2974u,2);
goto P_0c0b285a;
P_0c0b285a: /* original 4e0b, guest PC 0x0c0b285a */
if(!s->budget--) { s->failed_pc=0x0c0b285au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b285eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b285eu) { target=s->pc; goto dispatch; }
goto P_0c0b285e;
P_0c0b285c: /* original 65c2, guest PC 0x0c0b285c */
if(!s->budget--) { s->failed_pc=0x0c0b285cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b285e;
P_0c0b285e: /* original 948a, guest PC 0x0c0b285e */
if(!s->budget--) { s->failed_pc=0x0c0b285eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2976u,2);
goto P_0c0b2860;
P_0c0b2860: /* original 4e0b, guest PC 0x0c0b2860 */
if(!s->budget--) { s->failed_pc=0x0c0b2860u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2864u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2864u) { target=s->pc; goto dispatch; }
goto P_0c0b2864;
P_0c0b2862: /* original 65c2, guest PC 0x0c0b2862 */
if(!s->budget--) { s->failed_pc=0x0c0b2862u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b2864;
P_0c0b2864: /* original 9488, guest PC 0x0c0b2864 */
if(!s->budget--) { s->failed_pc=0x0c0b2864u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2978u,2);
goto P_0c0b2866;
P_0c0b2866: /* original 4e0b, guest PC 0x0c0b2866 */
if(!s->budget--) { s->failed_pc=0x0c0b2866u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b286au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b286au) { target=s->pc; goto dispatch; }
goto P_0c0b286a;
P_0c0b2868: /* original 65c2, guest PC 0x0c0b2868 */
if(!s->budget--) { s->failed_pc=0x0c0b2868u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b286a;
P_0c0b286a: /* original 9486, guest PC 0x0c0b286a */
if(!s->budget--) { s->failed_pc=0x0c0b286au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b297au,2);
goto P_0c0b286c;
P_0c0b286c: /* original 4e0b, guest PC 0x0c0b286c */
if(!s->budget--) { s->failed_pc=0x0c0b286cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2870u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2870u) { target=s->pc; goto dispatch; }
goto P_0c0b2870;
P_0c0b286e: /* original 65c2, guest PC 0x0c0b286e */
if(!s->budget--) { s->failed_pc=0x0c0b286eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b2870;
P_0c0b2870: /* original 9484, guest PC 0x0c0b2870 */
if(!s->budget--) { s->failed_pc=0x0c0b2870u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b297cu,2);
goto P_0c0b2872;
P_0c0b2872: /* original 4e0b, guest PC 0x0c0b2872 */
if(!s->budget--) { s->failed_pc=0x0c0b2872u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2876u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2876u) { target=s->pc; goto dispatch; }
goto P_0c0b2876;
P_0c0b2874: /* original 65b2, guest PC 0x0c0b2874 */
if(!s->budget--) { s->failed_pc=0x0c0b2874u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b2876;
P_0c0b2876: /* original 9482, guest PC 0x0c0b2876 */
if(!s->budget--) { s->failed_pc=0x0c0b2876u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b297eu,2);
goto P_0c0b2878;
P_0c0b2878: /* original 4e0b, guest PC 0x0c0b2878 */
if(!s->budget--) { s->failed_pc=0x0c0b2878u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b287cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b287cu) { target=s->pc; goto dispatch; }
goto P_0c0b287c;
P_0c0b287a: /* original 65b2, guest PC 0x0c0b287a */
if(!s->budget--) { s->failed_pc=0x0c0b287au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b287c;
P_0c0b287c: /* original 9480, guest PC 0x0c0b287c */
if(!s->budget--) { s->failed_pc=0x0c0b287cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2980u,2);
goto P_0c0b287e;
P_0c0b287e: /* original 4e0b, guest PC 0x0c0b287e */
if(!s->budget--) { s->failed_pc=0x0c0b287eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2882u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2882u) { target=s->pc; goto dispatch; }
goto P_0c0b2882;
P_0c0b2880: /* original 65b2, guest PC 0x0c0b2880 */
if(!s->budget--) { s->failed_pc=0x0c0b2880u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b2882;
P_0c0b2882: /* original 947e, guest PC 0x0c0b2882 */
if(!s->budget--) { s->failed_pc=0x0c0b2882u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2982u,2);
goto P_0c0b2884;
P_0c0b2884: /* original 4e0b, guest PC 0x0c0b2884 */
if(!s->budget--) { s->failed_pc=0x0c0b2884u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2888u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2888u) { target=s->pc; goto dispatch; }
goto P_0c0b2888;
P_0c0b2886: /* original 65b2, guest PC 0x0c0b2886 */
if(!s->budget--) { s->failed_pc=0x0c0b2886u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b2888;
P_0c0b2888: /* original 947c, guest PC 0x0c0b2888 */
if(!s->budget--) { s->failed_pc=0x0c0b2888u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2984u,2);
goto P_0c0b288a;
P_0c0b288a: /* original 4e0b, guest PC 0x0c0b288a */
if(!s->budget--) { s->failed_pc=0x0c0b288au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b288eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b288eu) { target=s->pc; goto dispatch; }
goto P_0c0b288e;
P_0c0b288c: /* original 65a2, guest PC 0x0c0b288c */
if(!s->budget--) { s->failed_pc=0x0c0b288cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b288e;
P_0c0b288e: /* original 947a, guest PC 0x0c0b288e */
if(!s->budget--) { s->failed_pc=0x0c0b288eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2986u,2);
goto P_0c0b2890;
P_0c0b2890: /* original 4e0b, guest PC 0x0c0b2890 */
if(!s->budget--) { s->failed_pc=0x0c0b2890u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2894u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2894u) { target=s->pc; goto dispatch; }
goto P_0c0b2894;
P_0c0b2892: /* original 65a2, guest PC 0x0c0b2892 */
if(!s->budget--) { s->failed_pc=0x0c0b2892u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b2894;
P_0c0b2894: /* original 9478, guest PC 0x0c0b2894 */
if(!s->budget--) { s->failed_pc=0x0c0b2894u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2988u,2);
goto P_0c0b2896;
P_0c0b2896: /* original 4e0b, guest PC 0x0c0b2896 */
if(!s->budget--) { s->failed_pc=0x0c0b2896u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b289au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b289au) { target=s->pc; goto dispatch; }
goto P_0c0b289a;
P_0c0b2898: /* original 65a2, guest PC 0x0c0b2898 */
if(!s->budget--) { s->failed_pc=0x0c0b2898u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b289a;
P_0c0b289a: /* original 9476, guest PC 0x0c0b289a */
if(!s->budget--) { s->failed_pc=0x0c0b289au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b298au,2);
goto P_0c0b289c;
P_0c0b289c: /* original 4e0b, guest PC 0x0c0b289c */
if(!s->budget--) { s->failed_pc=0x0c0b289cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28a0u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28a0u) { target=s->pc; goto dispatch; }
goto P_0c0b28a0;
P_0c0b289e: /* original 65a2, guest PC 0x0c0b289e */
if(!s->budget--) { s->failed_pc=0x0c0b289eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b28a0;
P_0c0b28a0: /* original 9574, guest PC 0x0c0b28a0 */
if(!s->budget--) { s->failed_pc=0x0c0b28a0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b298cu,2);
goto P_0c0b28a2;
P_0c0b28a2: /* original 35dc, guest PC 0x0c0b28a2 */
if(!s->budget--) { s->failed_pc=0x0c0b28a2u; return 0; }
r[5]+=r[13];
goto P_0c0b28a4;
P_0c0b28a4: /* original 2f52, guest PC 0x0c0b28a4 */
if(!s->budget--) { s->failed_pc=0x0c0b28a4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b28a6;
P_0c0b28a6: /* original 9472, guest PC 0x0c0b28a6 */
if(!s->budget--) { s->failed_pc=0x0c0b28a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b298eu,2);
goto P_0c0b28a8;
P_0c0b28a8: /* original 4e0b, guest PC 0x0c0b28a8 */
if(!s->budget--) { s->failed_pc=0x0c0b28a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28acu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28acu) { target=s->pc; goto dispatch; }
goto P_0c0b28ac;
P_0c0b28aa: /* original 6552, guest PC 0x0c0b28aa */
if(!s->budget--) { s->failed_pc=0x0c0b28aau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b28ac;
P_0c0b28ac: /* original 9470, guest PC 0x0c0b28ac */
if(!s->budget--) { s->failed_pc=0x0c0b28acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2990u,2);
goto P_0c0b28ae;
P_0c0b28ae: /* original 65f2, guest PC 0x0c0b28ae */
if(!s->budget--) { s->failed_pc=0x0c0b28aeu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b28b0;
P_0c0b28b0: /* original 4e0b, guest PC 0x0c0b28b0 */
if(!s->budget--) { s->failed_pc=0x0c0b28b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28b4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28b4u) { target=s->pc; goto dispatch; }
goto P_0c0b28b4;
P_0c0b28b2: /* original 6552, guest PC 0x0c0b28b2 */
if(!s->budget--) { s->failed_pc=0x0c0b28b2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b28b4;
P_0c0b28b4: /* original 956d, guest PC 0x0c0b28b4 */
if(!s->budget--) { s->failed_pc=0x0c0b28b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2992u,2);
goto P_0c0b28b6;
P_0c0b28b6: /* original 35dc, guest PC 0x0c0b28b6 */
if(!s->budget--) { s->failed_pc=0x0c0b28b6u; return 0; }
r[5]+=r[13];
goto P_0c0b28b8;
P_0c0b28b8: /* original 2f52, guest PC 0x0c0b28b8 */
if(!s->budget--) { s->failed_pc=0x0c0b28b8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b28ba;
P_0c0b28ba: /* original 946b, guest PC 0x0c0b28ba */
if(!s->budget--) { s->failed_pc=0x0c0b28bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2994u,2);
goto P_0c0b28bc;
P_0c0b28bc: /* original 4e0b, guest PC 0x0c0b28bc */
if(!s->budget--) { s->failed_pc=0x0c0b28bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28c0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28c0u) { target=s->pc; goto dispatch; }
goto P_0c0b28c0;
P_0c0b28be: /* original 6552, guest PC 0x0c0b28be */
if(!s->budget--) { s->failed_pc=0x0c0b28beu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b28c0;
P_0c0b28c0: /* original 9469, guest PC 0x0c0b28c0 */
if(!s->budget--) { s->failed_pc=0x0c0b28c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2996u,2);
goto P_0c0b28c2;
P_0c0b28c2: /* original 65f2, guest PC 0x0c0b28c2 */
if(!s->budget--) { s->failed_pc=0x0c0b28c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b28c4;
P_0c0b28c4: /* original 4e0b, guest PC 0x0c0b28c4 */
if(!s->budget--) { s->failed_pc=0x0c0b28c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28c8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28c8u) { target=s->pc; goto dispatch; }
goto P_0c0b28c8;
P_0c0b28c6: /* original 6552, guest PC 0x0c0b28c6 */
if(!s->budget--) { s->failed_pc=0x0c0b28c6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b28c8;
P_0c0b28c8: /* original 9467, guest PC 0x0c0b28c8 */
if(!s->budget--) { s->failed_pc=0x0c0b28c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b299au,2);
goto P_0c0b28ca;
P_0c0b28ca: /* original 9065, guest PC 0x0c0b28ca */
if(!s->budget--) { s->failed_pc=0x0c0b28cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2998u,2);
goto P_0c0b28cc;
P_0c0b28cc: /* original 4e0b, guest PC 0x0c0b28cc */
if(!s->budget--) { s->failed_pc=0x0c0b28ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28d0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28d0u) { target=s->pc; goto dispatch; }
goto P_0c0b28d0;
P_0c0b28ce: /* original 05de, guest PC 0x0c0b28ce */
if(!s->budget--) { s->failed_pc=0x0c0b28ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b28d0;
P_0c0b28d0: /* original 9564, guest PC 0x0c0b28d0 */
if(!s->budget--) { s->failed_pc=0x0c0b28d0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b299cu,2);
goto P_0c0b28d2;
P_0c0b28d2: /* original 35dc, guest PC 0x0c0b28d2 */
if(!s->budget--) { s->failed_pc=0x0c0b28d2u; return 0; }
r[5]+=r[13];
goto P_0c0b28d4;
P_0c0b28d4: /* original 2f52, guest PC 0x0c0b28d4 */
if(!s->budget--) { s->failed_pc=0x0c0b28d4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b28d6;
P_0c0b28d6: /* original 9462, guest PC 0x0c0b28d6 */
if(!s->budget--) { s->failed_pc=0x0c0b28d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b299eu,2);
goto P_0c0b28d8;
P_0c0b28d8: /* original 4e0b, guest PC 0x0c0b28d8 */
if(!s->budget--) { s->failed_pc=0x0c0b28d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28dcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28dcu) { target=s->pc; goto dispatch; }
goto P_0c0b28dc;
P_0c0b28da: /* original 6552, guest PC 0x0c0b28da */
if(!s->budget--) { s->failed_pc=0x0c0b28dau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b28dc;
P_0c0b28dc: /* original 9460, guest PC 0x0c0b28dc */
if(!s->budget--) { s->failed_pc=0x0c0b28dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29a0u,2);
goto P_0c0b28de;
P_0c0b28de: /* original 65f2, guest PC 0x0c0b28de */
if(!s->budget--) { s->failed_pc=0x0c0b28deu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b28e0;
P_0c0b28e0: /* original 4e0b, guest PC 0x0c0b28e0 */
if(!s->budget--) { s->failed_pc=0x0c0b28e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28e4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28e4u) { target=s->pc; goto dispatch; }
goto P_0c0b28e4;
P_0c0b28e2: /* original 6552, guest PC 0x0c0b28e2 */
if(!s->budget--) { s->failed_pc=0x0c0b28e2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b28e4;
P_0c0b28e4: /* original 945e, guest PC 0x0c0b28e4 */
if(!s->budget--) { s->failed_pc=0x0c0b28e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29a4u,2);
goto P_0c0b28e6;
P_0c0b28e6: /* original 905c, guest PC 0x0c0b28e6 */
if(!s->budget--) { s->failed_pc=0x0c0b28e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29a2u,2);
goto P_0c0b28e8;
P_0c0b28e8: /* original 4e0b, guest PC 0x0c0b28e8 */
if(!s->budget--) { s->failed_pc=0x0c0b28e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28ecu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28ecu) { target=s->pc; goto dispatch; }
goto P_0c0b28ec;
P_0c0b28ea: /* original 05de, guest PC 0x0c0b28ea */
if(!s->budget--) { s->failed_pc=0x0c0b28eau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b28ec;
P_0c0b28ec: /* original 955b, guest PC 0x0c0b28ec */
if(!s->budget--) { s->failed_pc=0x0c0b28ecu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29a6u,2);
goto P_0c0b28ee;
P_0c0b28ee: /* original 35dc, guest PC 0x0c0b28ee */
if(!s->budget--) { s->failed_pc=0x0c0b28eeu; return 0; }
r[5]+=r[13];
goto P_0c0b28f0;
P_0c0b28f0: /* original 2f52, guest PC 0x0c0b28f0 */
if(!s->budget--) { s->failed_pc=0x0c0b28f0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b28f2;
P_0c0b28f2: /* original 9459, guest PC 0x0c0b28f2 */
if(!s->budget--) { s->failed_pc=0x0c0b28f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29a8u,2);
goto P_0c0b28f4;
P_0c0b28f4: /* original 4e0b, guest PC 0x0c0b28f4 */
if(!s->budget--) { s->failed_pc=0x0c0b28f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b28f8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b28f8u) { target=s->pc; goto dispatch; }
goto P_0c0b28f8;
P_0c0b28f6: /* original 6552, guest PC 0x0c0b28f6 */
if(!s->budget--) { s->failed_pc=0x0c0b28f6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b28f8;
P_0c0b28f8: /* original 9457, guest PC 0x0c0b28f8 */
if(!s->budget--) { s->failed_pc=0x0c0b28f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29aau,2);
goto P_0c0b28fa;
P_0c0b28fa: /* original 65f2, guest PC 0x0c0b28fa */
if(!s->budget--) { s->failed_pc=0x0c0b28fau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b28fc;
P_0c0b28fc: /* original 4e0b, guest PC 0x0c0b28fc */
if(!s->budget--) { s->failed_pc=0x0c0b28fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2900u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2900u) { target=s->pc; goto dispatch; }
goto P_0c0b2900;
P_0c0b28fe: /* original 6552, guest PC 0x0c0b28fe */
if(!s->budget--) { s->failed_pc=0x0c0b28feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2900;
P_0c0b2900: /* original 9455, guest PC 0x0c0b2900 */
if(!s->budget--) { s->failed_pc=0x0c0b2900u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29aeu,2);
goto P_0c0b2902;
P_0c0b2902: /* original 9053, guest PC 0x0c0b2902 */
if(!s->budget--) { s->failed_pc=0x0c0b2902u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29acu,2);
goto P_0c0b2904;
P_0c0b2904: /* original 4e0b, guest PC 0x0c0b2904 */
if(!s->budget--) { s->failed_pc=0x0c0b2904u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2908u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2908u) { target=s->pc; goto dispatch; }
goto P_0c0b2908;
P_0c0b2906: /* original 05de, guest PC 0x0c0b2906 */
if(!s->budget--) { s->failed_pc=0x0c0b2906u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2908;
P_0c0b2908: /* original 9552, guest PC 0x0c0b2908 */
if(!s->budget--) { s->failed_pc=0x0c0b2908u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29b0u,2);
goto P_0c0b290a;
P_0c0b290a: /* original 35dc, guest PC 0x0c0b290a */
if(!s->budget--) { s->failed_pc=0x0c0b290au; return 0; }
r[5]+=r[13];
goto P_0c0b290c;
P_0c0b290c: /* original 2f52, guest PC 0x0c0b290c */
if(!s->budget--) { s->failed_pc=0x0c0b290cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b290e;
P_0c0b290e: /* original 9450, guest PC 0x0c0b290e */
if(!s->budget--) { s->failed_pc=0x0c0b290eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29b2u,2);
goto P_0c0b2910;
P_0c0b2910: /* original 4e0b, guest PC 0x0c0b2910 */
if(!s->budget--) { s->failed_pc=0x0c0b2910u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2914u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2914u) { target=s->pc; goto dispatch; }
goto P_0c0b2914;
P_0c0b2912: /* original 6552, guest PC 0x0c0b2912 */
if(!s->budget--) { s->failed_pc=0x0c0b2912u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2914;
P_0c0b2914: /* original 944e, guest PC 0x0c0b2914 */
if(!s->budget--) { s->failed_pc=0x0c0b2914u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29b4u,2);
goto P_0c0b2916;
P_0c0b2916: /* original 65f2, guest PC 0x0c0b2916 */
if(!s->budget--) { s->failed_pc=0x0c0b2916u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b2918;
P_0c0b2918: /* original 4e0b, guest PC 0x0c0b2918 */
if(!s->budget--) { s->failed_pc=0x0c0b2918u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b291cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b291cu) { target=s->pc; goto dispatch; }
goto P_0c0b291c;
P_0c0b291a: /* original 6552, guest PC 0x0c0b291a */
if(!s->budget--) { s->failed_pc=0x0c0b291au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b291c;
P_0c0b291c: /* original 954b, guest PC 0x0c0b291c */
if(!s->budget--) { s->failed_pc=0x0c0b291cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29b6u,2);
goto P_0c0b291e;
P_0c0b291e: /* original 35dc, guest PC 0x0c0b291e */
if(!s->budget--) { s->failed_pc=0x0c0b291eu; return 0; }
r[5]+=r[13];
goto P_0c0b2920;
P_0c0b2920: /* original 2f52, guest PC 0x0c0b2920 */
if(!s->budget--) { s->failed_pc=0x0c0b2920u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b2922;
P_0c0b2922: /* original 9449, guest PC 0x0c0b2922 */
if(!s->budget--) { s->failed_pc=0x0c0b2922u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29b8u,2);
goto P_0c0b2924;
P_0c0b2924: /* original 4e0b, guest PC 0x0c0b2924 */
if(!s->budget--) { s->failed_pc=0x0c0b2924u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2928u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2928u) { target=s->pc; goto dispatch; }
goto P_0c0b2928;
P_0c0b2926: /* original 6552, guest PC 0x0c0b2926 */
if(!s->budget--) { s->failed_pc=0x0c0b2926u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2928;
P_0c0b2928: /* original 9447, guest PC 0x0c0b2928 */
if(!s->budget--) { s->failed_pc=0x0c0b2928u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29bau,2);
goto P_0c0b292a;
P_0c0b292a: /* original 65f2, guest PC 0x0c0b292a */
if(!s->budget--) { s->failed_pc=0x0c0b292au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b292c;
P_0c0b292c: /* original 4e0b, guest PC 0x0c0b292c */
if(!s->budget--) { s->failed_pc=0x0c0b292cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2930u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2930u) { target=s->pc; goto dispatch; }
goto P_0c0b2930;
P_0c0b292e: /* original 6552, guest PC 0x0c0b292e */
if(!s->budget--) { s->failed_pc=0x0c0b292eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2930;
P_0c0b2930: /* original 9445, guest PC 0x0c0b2930 */
if(!s->budget--) { s->failed_pc=0x0c0b2930u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29beu,2);
goto P_0c0b2932;
P_0c0b2932: /* original 9043, guest PC 0x0c0b2932 */
if(!s->budget--) { s->failed_pc=0x0c0b2932u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29bcu,2);
goto P_0c0b2934;
P_0c0b2934: /* original 4e0b, guest PC 0x0c0b2934 */
if(!s->budget--) { s->failed_pc=0x0c0b2934u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2938u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2938u) { target=s->pc; goto dispatch; }
goto P_0c0b2938;
P_0c0b2936: /* original 05de, guest PC 0x0c0b2936 */
if(!s->budget--) { s->failed_pc=0x0c0b2936u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2938;
P_0c0b2938: /* original 9443, guest PC 0x0c0b2938 */
if(!s->budget--) { s->failed_pc=0x0c0b2938u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29c2u,2);
goto P_0c0b293a;
P_0c0b293a: /* original 9041, guest PC 0x0c0b293a */
if(!s->budget--) { s->failed_pc=0x0c0b293au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29c0u,2);
goto P_0c0b293c;
P_0c0b293c: /* original 4e0b, guest PC 0x0c0b293c */
if(!s->budget--) { s->failed_pc=0x0c0b293cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2940u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2940u) { target=s->pc; goto dispatch; }
goto P_0c0b2940;
P_0c0b293e: /* original 05de, guest PC 0x0c0b293e */
if(!s->budget--) { s->failed_pc=0x0c0b293eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2940;
P_0c0b2940: /* original 9441, guest PC 0x0c0b2940 */
if(!s->budget--) { s->failed_pc=0x0c0b2940u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29c6u,2);
goto P_0c0b2942;
P_0c0b2942: /* original 903f, guest PC 0x0c0b2942 */
if(!s->budget--) { s->failed_pc=0x0c0b2942u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29c4u,2);
goto P_0c0b2944;
P_0c0b2944: /* original 4e0b, guest PC 0x0c0b2944 */
if(!s->budget--) { s->failed_pc=0x0c0b2944u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2948u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2948u) { target=s->pc; goto dispatch; }
goto P_0c0b2948;
P_0c0b2946: /* original 05de, guest PC 0x0c0b2946 */
if(!s->budget--) { s->failed_pc=0x0c0b2946u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2948;
P_0c0b2948: /* original 943f, guest PC 0x0c0b2948 */
if(!s->budget--) { s->failed_pc=0x0c0b2948u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29cau,2);
goto P_0c0b294a;
P_0c0b294a: /* original 903d, guest PC 0x0c0b294a */
if(!s->budget--) { s->failed_pc=0x0c0b294au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29c8u,2);
goto P_0c0b294c;
P_0c0b294c: /* original 4e0b, guest PC 0x0c0b294c */
if(!s->budget--) { s->failed_pc=0x0c0b294cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2950u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2950u) { target=s->pc; goto dispatch; }
goto P_0c0b2950;
P_0c0b294e: /* original 05de, guest PC 0x0c0b294e */
if(!s->budget--) { s->failed_pc=0x0c0b294eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2950;
P_0c0b2950: /* original 903c, guest PC 0x0c0b2950 */
if(!s->budget--) { s->failed_pc=0x0c0b2950u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b29ccu,2);
goto P_0c0b2952;
P_0c0b2952: /* original a03c, guest PC 0x0c0b2952 */
if(!s->budget--) { s->failed_pc=0x0c0b2952u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b29ce;
P_0c0b2954: /* original 05de, guest PC 0x0c0b2954 */
if(!s->budget--) { s->failed_pc=0x0c0b2954u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b2956u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b2956u; return 0; } return 1;
P_0c0b29ce: /* original 943e, guest PC 0x0c0b29ce */
if(!s->budget--) { s->failed_pc=0x0c0b29ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a4eu,2);
goto P_0c0b29d0;
P_0c0b29d0: /* original 4e0b, guest PC 0x0c0b29d0 */
if(!s->budget--) { s->failed_pc=0x0c0b29d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b29d4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b29d4u) { target=s->pc; goto dispatch; }
goto P_0c0b29d4;
P_0c0b29d2: /* original 0009, guest PC 0x0c0b29d2 */
if(!s->budget--) { s->failed_pc=0x0c0b29d2u; return 0; }
goto P_0c0b29d4;
P_0c0b29d4: /* original 943d, guest PC 0x0c0b29d4 */
if(!s->budget--) { s->failed_pc=0x0c0b29d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a52u,2);
goto P_0c0b29d6;
P_0c0b29d6: /* original 903b, guest PC 0x0c0b29d6 */
if(!s->budget--) { s->failed_pc=0x0c0b29d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a50u,2);
goto P_0c0b29d8;
P_0c0b29d8: /* original 4e0b, guest PC 0x0c0b29d8 */
if(!s->budget--) { s->failed_pc=0x0c0b29d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b29dcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b29dcu) { target=s->pc; goto dispatch; }
goto P_0c0b29dc;
P_0c0b29da: /* original 05de, guest PC 0x0c0b29da */
if(!s->budget--) { s->failed_pc=0x0c0b29dau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b29dc;
P_0c0b29dc: /* original 943b, guest PC 0x0c0b29dc */
if(!s->budget--) { s->failed_pc=0x0c0b29dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a56u,2);
goto P_0c0b29de;
P_0c0b29de: /* original 9039, guest PC 0x0c0b29de */
if(!s->budget--) { s->failed_pc=0x0c0b29deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a54u,2);
goto P_0c0b29e0;
P_0c0b29e0: /* original 4e0b, guest PC 0x0c0b29e0 */
if(!s->budget--) { s->failed_pc=0x0c0b29e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b29e4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b29e4u) { target=s->pc; goto dispatch; }
goto P_0c0b29e4;
P_0c0b29e2: /* original 05de, guest PC 0x0c0b29e2 */
if(!s->budget--) { s->failed_pc=0x0c0b29e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b29e4;
P_0c0b29e4: /* original 9439, guest PC 0x0c0b29e4 */
if(!s->budget--) { s->failed_pc=0x0c0b29e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a5au,2);
goto P_0c0b29e6;
P_0c0b29e6: /* original 9037, guest PC 0x0c0b29e6 */
if(!s->budget--) { s->failed_pc=0x0c0b29e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a58u,2);
goto P_0c0b29e8;
P_0c0b29e8: /* original 4e0b, guest PC 0x0c0b29e8 */
if(!s->budget--) { s->failed_pc=0x0c0b29e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b29ecu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b29ecu) { target=s->pc; goto dispatch; }
goto P_0c0b29ec;
P_0c0b29ea: /* original 05de, guest PC 0x0c0b29ea */
if(!s->budget--) { s->failed_pc=0x0c0b29eau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b29ec;
P_0c0b29ec: /* original 9437, guest PC 0x0c0b29ec */
if(!s->budget--) { s->failed_pc=0x0c0b29ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a5eu,2);
goto P_0c0b29ee;
P_0c0b29ee: /* original 9035, guest PC 0x0c0b29ee */
if(!s->budget--) { s->failed_pc=0x0c0b29eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a5cu,2);
goto P_0c0b29f0;
P_0c0b29f0: /* original 4e0b, guest PC 0x0c0b29f0 */
if(!s->budget--) { s->failed_pc=0x0c0b29f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b29f4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b29f4u) { target=s->pc; goto dispatch; }
goto P_0c0b29f4;
P_0c0b29f2: /* original 05de, guest PC 0x0c0b29f2 */
if(!s->budget--) { s->failed_pc=0x0c0b29f2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b29f4;
P_0c0b29f4: /* original 9435, guest PC 0x0c0b29f4 */
if(!s->budget--) { s->failed_pc=0x0c0b29f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a62u,2);
goto P_0c0b29f6;
P_0c0b29f6: /* original 9033, guest PC 0x0c0b29f6 */
if(!s->budget--) { s->failed_pc=0x0c0b29f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a60u,2);
goto P_0c0b29f8;
P_0c0b29f8: /* original 4e0b, guest PC 0x0c0b29f8 */
if(!s->budget--) { s->failed_pc=0x0c0b29f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b29fcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b29fcu) { target=s->pc; goto dispatch; }
goto P_0c0b29fc;
P_0c0b29fa: /* original 05de, guest PC 0x0c0b29fa */
if(!s->budget--) { s->failed_pc=0x0c0b29fau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b29fc;
P_0c0b29fc: /* original 9433, guest PC 0x0c0b29fc */
if(!s->budget--) { s->failed_pc=0x0c0b29fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a66u,2);
goto P_0c0b29fe;
P_0c0b29fe: /* original 9031, guest PC 0x0c0b29fe */
if(!s->budget--) { s->failed_pc=0x0c0b29feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a64u,2);
goto P_0c0b2a00;
P_0c0b2a00: /* original 4e0b, guest PC 0x0c0b2a00 */
if(!s->budget--) { s->failed_pc=0x0c0b2a00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2a04u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2a04u) { target=s->pc; goto dispatch; }
goto P_0c0b2a04;
P_0c0b2a02: /* original 05de, guest PC 0x0c0b2a02 */
if(!s->budget--) { s->failed_pc=0x0c0b2a02u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2a04;
P_0c0b2a04: /* original 9431, guest PC 0x0c0b2a04 */
if(!s->budget--) { s->failed_pc=0x0c0b2a04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a6au,2);
goto P_0c0b2a06;
P_0c0b2a06: /* original 902f, guest PC 0x0c0b2a06 */
if(!s->budget--) { s->failed_pc=0x0c0b2a06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a68u,2);
goto P_0c0b2a08;
P_0c0b2a08: /* original 4e0b, guest PC 0x0c0b2a08 */
if(!s->budget--) { s->failed_pc=0x0c0b2a08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2a0cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2a0cu) { target=s->pc; goto dispatch; }
goto P_0c0b2a0c;
P_0c0b2a0a: /* original 05de, guest PC 0x0c0b2a0a */
if(!s->budget--) { s->failed_pc=0x0c0b2a0au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2a0c;
P_0c0b2a0c: /* original 942f, guest PC 0x0c0b2a0c */
if(!s->budget--) { s->failed_pc=0x0c0b2a0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a6eu,2);
goto P_0c0b2a0e;
P_0c0b2a0e: /* original 902d, guest PC 0x0c0b2a0e */
if(!s->budget--) { s->failed_pc=0x0c0b2a0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a6cu,2);
goto P_0c0b2a10;
P_0c0b2a10: /* original 4e0b, guest PC 0x0c0b2a10 */
if(!s->budget--) { s->failed_pc=0x0c0b2a10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2a14u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2a14u) { target=s->pc; goto dispatch; }
goto P_0c0b2a14;
P_0c0b2a12: /* original 05de, guest PC 0x0c0b2a12 */
if(!s->budget--) { s->failed_pc=0x0c0b2a12u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2a14;
P_0c0b2a14: /* original 942d, guest PC 0x0c0b2a14 */
if(!s->budget--) { s->failed_pc=0x0c0b2a14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a72u,2);
goto P_0c0b2a16;
P_0c0b2a16: /* original 902b, guest PC 0x0c0b2a16 */
if(!s->budget--) { s->failed_pc=0x0c0b2a16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a70u,2);
goto P_0c0b2a18;
P_0c0b2a18: /* original 4e0b, guest PC 0x0c0b2a18 */
if(!s->budget--) { s->failed_pc=0x0c0b2a18u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2a1cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2a1cu) { target=s->pc; goto dispatch; }
goto P_0c0b2a1c;
P_0c0b2a1a: /* original 05de, guest PC 0x0c0b2a1a */
if(!s->budget--) { s->failed_pc=0x0c0b2a1au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2a1c;
P_0c0b2a1c: /* original 942b, guest PC 0x0c0b2a1c */
if(!s->budget--) { s->failed_pc=0x0c0b2a1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a76u,2);
goto P_0c0b2a1e;
P_0c0b2a1e: /* original 9029, guest PC 0x0c0b2a1e */
if(!s->budget--) { s->failed_pc=0x0c0b2a1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a74u,2);
goto P_0c0b2a20;
P_0c0b2a20: /* original 4e0b, guest PC 0x0c0b2a20 */
if(!s->budget--) { s->failed_pc=0x0c0b2a20u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2a24u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2a24u) { target=s->pc; goto dispatch; }
goto P_0c0b2a24;
P_0c0b2a22: /* original 05de, guest PC 0x0c0b2a22 */
if(!s->budget--) { s->failed_pc=0x0c0b2a22u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2a24;
P_0c0b2a24: /* original 9429, guest PC 0x0c0b2a24 */
if(!s->budget--) { s->failed_pc=0x0c0b2a24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a7au,2);
goto P_0c0b2a26;
P_0c0b2a26: /* original 9027, guest PC 0x0c0b2a26 */
if(!s->budget--) { s->failed_pc=0x0c0b2a26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a78u,2);
goto P_0c0b2a28;
P_0c0b2a28: /* original 4e0b, guest PC 0x0c0b2a28 */
if(!s->budget--) { s->failed_pc=0x0c0b2a28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2a2cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2a2cu) { target=s->pc; goto dispatch; }
goto P_0c0b2a2c;
P_0c0b2a2a: /* original 05de, guest PC 0x0c0b2a2a */
if(!s->budget--) { s->failed_pc=0x0c0b2a2au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2a2c;
P_0c0b2a2c: /* original 9427, guest PC 0x0c0b2a2c */
if(!s->budget--) { s->failed_pc=0x0c0b2a2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a7eu,2);
goto P_0c0b2a2e;
P_0c0b2a2e: /* original 9025, guest PC 0x0c0b2a2e */
if(!s->budget--) { s->failed_pc=0x0c0b2a2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a7cu,2);
goto P_0c0b2a30;
P_0c0b2a30: /* original 4e0b, guest PC 0x0c0b2a30 */
if(!s->budget--) { s->failed_pc=0x0c0b2a30u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2a34u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2a34u) { target=s->pc; goto dispatch; }
goto P_0c0b2a34;
P_0c0b2a32: /* original 05de, guest PC 0x0c0b2a32 */
if(!s->budget--) { s->failed_pc=0x0c0b2a32u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2a34;
P_0c0b2a34: /* original 9425, guest PC 0x0c0b2a34 */
if(!s->budget--) { s->failed_pc=0x0c0b2a34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a82u,2);
goto P_0c0b2a36;
P_0c0b2a36: /* original 9023, guest PC 0x0c0b2a36 */
if(!s->budget--) { s->failed_pc=0x0c0b2a36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2a80u,2);
goto P_0c0b2a38;
P_0c0b2a38: /* original 4e0b, guest PC 0x0c0b2a38 */
if(!s->budget--) { s->failed_pc=0x0c0b2a38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2a3cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2a3cu) { target=s->pc; goto dispatch; }
goto P_0c0b2a3c;
P_0c0b2a3a: /* original 05de, guest PC 0x0c0b2a3a */
if(!s->budget--) { s->failed_pc=0x0c0b2a3au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2a3c;
P_0c0b2a3c: /* original 7f08, guest PC 0x0c0b2a3c */
if(!s->budget--) { s->failed_pc=0x0c0b2a3cu; return 0; }
r[15]+=0x00000008u;
goto P_0c0b2a3e;
P_0c0b2a3e: /* original 4f26, guest PC 0x0c0b2a3e */
if(!s->budget--) { s->failed_pc=0x0c0b2a3eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b2a40;
P_0c0b2a40: /* original 69f6, guest PC 0x0c0b2a40 */
if(!s->budget--) { s->failed_pc=0x0c0b2a40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b2a42;
P_0c0b2a42: /* original 6af6, guest PC 0x0c0b2a42 */
if(!s->budget--) { s->failed_pc=0x0c0b2a42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b2a44;
P_0c0b2a44: /* original 6bf6, guest PC 0x0c0b2a44 */
if(!s->budget--) { s->failed_pc=0x0c0b2a44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b2a46;
P_0c0b2a46: /* original 6cf6, guest PC 0x0c0b2a46 */
if(!s->budget--) { s->failed_pc=0x0c0b2a46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b2a48;
P_0c0b2a48: /* original 6df6, guest PC 0x0c0b2a48 */
if(!s->budget--) { s->failed_pc=0x0c0b2a48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b2a4a;
P_0c0b2a4a: /* original 000b, guest PC 0x0c0b2a4a */
if(!s->budget--) { s->failed_pc=0x0c0b2a4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b2a4c: /* original 6ef6, guest PC 0x0c0b2a4c */
if(!s->budget--) { s->failed_pc=0x0c0b2a4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b2a4eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b2a4eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
