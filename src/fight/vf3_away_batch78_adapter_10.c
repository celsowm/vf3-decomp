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
int vf3_away_batch78_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062bfau: goto P_0c062bfa;
case 0x0c062bfcu: goto P_0c062bfc;
case 0x0c062bfeu: goto P_0c062bfe;
case 0x0c062c00u: goto P_0c062c00;
case 0x0c062c02u: goto P_0c062c02;
case 0x0c062c04u: goto P_0c062c04;
case 0x0c062c06u: goto P_0c062c06;
case 0x0c062c08u: goto P_0c062c08;
case 0x0c062c0au: goto P_0c062c0a;
case 0x0c062c0cu: goto P_0c062c0c;
case 0x0c062c0eu: goto P_0c062c0e;
case 0x0c062c10u: goto P_0c062c10;
case 0x0c062c12u: goto P_0c062c12;
case 0x0c062c14u: goto P_0c062c14;
case 0x0c062c16u: goto P_0c062c16;
case 0x0c062c18u: goto P_0c062c18;
case 0x0c062c1au: goto P_0c062c1a;
case 0x0c062c1cu: goto P_0c062c1c;
case 0x0c062c1eu: goto P_0c062c1e;
case 0x0c062c20u: goto P_0c062c20;
case 0x0c062c22u: goto P_0c062c22;
case 0x0c062c24u: goto P_0c062c24;
case 0x0c062c26u: goto P_0c062c26;
case 0x0c062c28u: goto P_0c062c28;
case 0x0c062c2au: goto P_0c062c2a;
case 0x0c062c2cu: goto P_0c062c2c;
case 0x0c062c2eu: goto P_0c062c2e;
case 0x0c062c30u: goto P_0c062c30;
case 0x0c062c32u: goto P_0c062c32;
case 0x0c062c34u: goto P_0c062c34;
case 0x0c062c36u: goto P_0c062c36;
case 0x0c062c38u: goto P_0c062c38;
case 0x0c062c3au: goto P_0c062c3a;
case 0x0c062c3cu: goto P_0c062c3c;
case 0x0c062c3eu: goto P_0c062c3e;
case 0x0c062c40u: goto P_0c062c40;
case 0x0c062c42u: goto P_0c062c42;
case 0x0c062c44u: goto P_0c062c44;
case 0x0c062c46u: goto P_0c062c46;
case 0x0c062c48u: goto P_0c062c48;
case 0x0c062c4au: goto P_0c062c4a;
case 0x0c062c4cu: goto P_0c062c4c;
case 0x0c062c4eu: goto P_0c062c4e;
case 0x0c062c50u: goto P_0c062c50;
case 0x0c062c52u: goto P_0c062c52;
case 0x0c062c54u: goto P_0c062c54;
case 0x0c062c56u: goto P_0c062c56;
case 0x0c062c58u: goto P_0c062c58;
case 0x0c062c5au: goto P_0c062c5a;
case 0x0c062c5cu: goto P_0c062c5c;
case 0x0c062c5eu: goto P_0c062c5e;
case 0x0c062c60u: goto P_0c062c60;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
case 0x0c0644bcu: goto P_0c0644bc;
case 0x0c0644beu: goto P_0c0644be;
case 0x0c0644c0u: goto P_0c0644c0;
case 0x0c0644c2u: goto P_0c0644c2;
case 0x0c0644c4u: goto P_0c0644c4;
case 0x0c0644c6u: goto P_0c0644c6;
case 0x0c0644c8u: goto P_0c0644c8;
case 0x0c0644cau: goto P_0c0644ca;
case 0x0c0644ccu: goto P_0c0644cc;
case 0x0c0644ceu: goto P_0c0644ce;
case 0x0c0644d0u: goto P_0c0644d0;
case 0x0c0644d2u: goto P_0c0644d2;
case 0x0c0644d4u: goto P_0c0644d4;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c062bfa: /* original e700, guest PC 0x0c062bfa */
if(!s->budget--) { s->failed_pc=0x0c062bfau; return 0; }
r[7]=0x00000000u;
goto P_0c062bfc;
P_0c062bfc: /* original d526, guest PC 0x0c062bfc */
if(!s->budget--) { s->failed_pc=0x0c062bfcu; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062bfe;
P_0c062bfe: /* original 6453, guest PC 0x0c062bfe */
if(!s->budget--) { s->failed_pc=0x0c062bfeu; return 0; }
r[4]=r[5];
goto P_0c062c00;
P_0c062c00: /* original 9047, guest PC 0x0c062c00 */
if(!s->budget--) { s->failed_pc=0x0c062c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c02;
P_0c062c02: /* original 6653, guest PC 0x0c062c02 */
if(!s->budget--) { s->failed_pc=0x0c062c02u; return 0; }
r[6]=r[5];
goto P_0c062c04;
P_0c062c04: /* original e501, guest PC 0x0c062c04 */
if(!s->budget--) { s->failed_pc=0x0c062c04u; return 0; }
r[5]=0x00000001u;
goto P_0c062c06;
P_0c062c06: /* original 6361, guest PC 0x0c062c06 */
if(!s->budget--) { s->failed_pc=0x0c062c06u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c062c08;
P_0c062c08: /* original 633d, guest PC 0x0c062c08 */
if(!s->budget--) { s->failed_pc=0x0c062c08u; return 0; }
r[3]=r[3]&65535u;
goto P_0c062c0a;
P_0c062c0a: /* original 2358, guest PC 0x0c062c0a */
if(!s->budget--) { s->failed_pc=0x0c062c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c062c0c;
P_0c062c0c: /* original 8b02, guest PC 0x0c062c0c */
if(!s->budget--) { s->failed_pc=0x0c062c0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c14; }
goto P_0c062c0e;
P_0c062c0e: /* original 2451, guest PC 0x0c062c0e */
if(!s->budget--) { s->failed_pc=0x0c062c0eu; return 0; }
write(ram,r[4],r[5],2);
goto P_0c062c10;
P_0c062c10: /* original 000b, guest PC 0x0c062c10 */
if(!s->budget--) { s->failed_pc=0x0c062c10u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c062c12: /* original 6043, guest PC 0x0c062c12 */
if(!s->budget--) { s->failed_pc=0x0c062c12u; return 0; }
r[0]=r[4];
goto P_0c062c14;
P_0c062c14: /* original 7701, guest PC 0x0c062c14 */
if(!s->budget--) { s->failed_pc=0x0c062c14u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c16;
P_0c062c16: /* original 744c, guest PC 0x0c062c16 */
if(!s->budget--) { s->failed_pc=0x0c062c16u; return 0; }
r[4]+=0x0000004cu;
goto P_0c062c18;
P_0c062c18: /* original 3703, guest PC 0x0c062c18 */
if(!s->budget--) { s->failed_pc=0x0c062c18u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c062c1a;
P_0c062c1a: /* original 8ff4, guest PC 0x0c062c1a */
if(!s->budget--) { s->failed_pc=0x0c062c1au; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c06; }
goto P_0c062c1e;
P_0c062c1c: /* original 764c, guest PC 0x0c062c1c */
if(!s->budget--) { s->failed_pc=0x0c062c1cu; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c1e;
P_0c062c1e: /* original e000, guest PC 0x0c062c1e */
if(!s->budget--) { s->failed_pc=0x0c062c1eu; return 0; }
r[0]=0x00000000u;
goto P_0c062c20;
P_0c062c20: /* original 000b, guest PC 0x0c062c20 */
if(!s->budget--) { s->failed_pc=0x0c062c20u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062c22: /* original 0009, guest PC 0x0c062c22 */
if(!s->budget--) { s->failed_pc=0x0c062c22u; return 0; }
goto P_0c062c24;
P_0c062c24: /* original 2fd6, guest PC 0x0c062c24 */
if(!s->budget--) { s->failed_pc=0x0c062c24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062c26;
P_0c062c26: /* original e700, guest PC 0x0c062c26 */
if(!s->budget--) { s->failed_pc=0x0c062c26u; return 0; }
r[7]=0x00000000u;
goto P_0c062c28;
P_0c062c28: /* original d51b, guest PC 0x0c062c28 */
if(!s->budget--) { s->failed_pc=0x0c062c28u; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062c2a;
P_0c062c2a: /* original 7ffc, guest PC 0x0c062c2a */
if(!s->budget--) { s->failed_pc=0x0c062c2au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062c2c;
P_0c062c2c: /* original dd1b, guest PC 0x0c062c2c */
if(!s->budget--) { s->failed_pc=0x0c062c2cu; return 0; }
r[13]=read(ram,0x0c062c9cu,4);
goto P_0c062c2e;
P_0c062c2e: /* original 6653, guest PC 0x0c062c2e */
if(!s->budget--) { s->failed_pc=0x0c062c2eu; return 0; }
r[6]=r[5];
goto P_0c062c30;
P_0c062c30: /* original 912f, guest PC 0x0c062c30 */
if(!s->budget--) { s->failed_pc=0x0c062c30u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c32;
P_0c062c32: /* original 2f52, guest PC 0x0c062c32 */
if(!s->budget--) { s->failed_pc=0x0c062c32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062c34;
P_0c062c34: /* original 3640, guest PC 0x0c062c34 */
if(!s->budget--) { s->failed_pc=0x0c062c34u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c062c36;
P_0c062c36: /* original 8f03, guest PC 0x0c062c36 */
if(!s->budget--) { s->failed_pc=0x0c062c36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c062c40; }
goto P_0c062c3a;
P_0c062c38: /* original 7701, guest PC 0x0c062c38 */
if(!s->budget--) { s->failed_pc=0x0c062c38u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c3a;
P_0c062c3a: /* original 6251, guest PC 0x0c062c3a */
if(!s->budget--) { s->failed_pc=0x0c062c3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c062c3c;
P_0c062c3c: /* original 22d9, guest PC 0x0c062c3c */
if(!s->budget--) { s->failed_pc=0x0c062c3cu; return 0; }
r[2]&=r[13];
goto P_0c062c3e;
P_0c062c3e: /* original 2521, guest PC 0x0c062c3e */
if(!s->budget--) { s->failed_pc=0x0c062c3eu; return 0; }
write(ram,r[5],r[2],2);
goto P_0c062c40;
P_0c062c40: /* original 754c, guest PC 0x0c062c40 */
if(!s->budget--) { s->failed_pc=0x0c062c40u; return 0; }
r[5]+=0x0000004cu;
goto P_0c062c42;
P_0c062c42: /* original 3713, guest PC 0x0c062c42 */
if(!s->budget--) { s->failed_pc=0x0c062c42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c062c44;
P_0c062c44: /* original 8ff6, guest PC 0x0c062c44 */
if(!s->budget--) { s->failed_pc=0x0c062c44u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c34; }
goto P_0c062c48;
P_0c062c46: /* original 764c, guest PC 0x0c062c46 */
if(!s->budget--) { s->failed_pc=0x0c062c46u; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c48;
P_0c062c48: /* original 7f04, guest PC 0x0c062c48 */
if(!s->budget--) { s->failed_pc=0x0c062c48u; return 0; }
r[15]+=0x00000004u;
goto P_0c062c4a;
P_0c062c4a: /* original 000b, guest PC 0x0c062c4a */
if(!s->budget--) { s->failed_pc=0x0c062c4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c062c4c: /* original 6df6, guest PC 0x0c062c4c */
if(!s->budget--) { s->failed_pc=0x0c062c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062c4e;
P_0c062c4e: /* original 6342, guest PC 0x0c062c4e */
if(!s->budget--) { s->failed_pc=0x0c062c4eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c062c50;
P_0c062c50: /* original 2338, guest PC 0x0c062c50 */
if(!s->budget--) { s->failed_pc=0x0c062c50u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062c52;
P_0c062c52: /* original 8b02, guest PC 0x0c062c52 */
if(!s->budget--) { s->failed_pc=0x0c062c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c5a; }
goto P_0c062c54;
P_0c062c54: /* original e300, guest PC 0x0c062c54 */
if(!s->budget--) { s->failed_pc=0x0c062c54u; return 0; }
r[3]=0x00000000u;
goto P_0c062c56;
P_0c062c56: /* original a002, guest PC 0x0c062c56 */
if(!s->budget--) { s->failed_pc=0x0c062c56u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5e;
P_0c062c58: /* original 1531, guest PC 0x0c062c58 */
if(!s->budget--) { s->failed_pc=0x0c062c58u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5a;
P_0c062c5a: /* original 6242, guest PC 0x0c062c5a */
if(!s->budget--) { s->failed_pc=0x0c062c5au; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c062c5c;
P_0c062c5c: /* original 1521, guest PC 0x0c062c5c */
if(!s->budget--) { s->failed_pc=0x0c062c5cu; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c062c5e;
P_0c062c5e: /* original 000b, guest PC 0x0c062c5e */
if(!s->budget--) { s->failed_pc=0x0c062c5eu; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c062c60: /* original 2452, guest PC 0x0c062c60 */
if(!s->budget--) { s->failed_pc=0x0c062c60u; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c062c62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062c62u; return 0; } return 1;
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
P_0c0644bc: /* original d009, guest PC 0x0c0644bc */
if(!s->budget--) { s->failed_pc=0x0c0644bcu; return 0; }
r[0]=read(ram,0x0c0644e4u,4);
goto P_0c0644be;
P_0c0644be: /* original 7ff8, guest PC 0x0c0644be */
if(!s->budget--) { s->failed_pc=0x0c0644beu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0644c0;
P_0c0644c0: /* original 2f42, guest PC 0x0c0644c0 */
if(!s->budget--) { s->failed_pc=0x0c0644c0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0644c2;
P_0c0644c2: /* original 6343, guest PC 0x0c0644c2 */
if(!s->budget--) { s->failed_pc=0x0c0644c2u; return 0; }
r[3]=r[4];
goto P_0c0644c4;
P_0c0644c4: /* original 4308, guest PC 0x0c0644c4 */
if(!s->budget--) { s->failed_pc=0x0c0644c4u; return 0; }
r[3]<<=2;
goto P_0c0644c6;
P_0c0644c6: /* original 4300, guest PC 0x0c0644c6 */
if(!s->budget--) { s->failed_pc=0x0c0644c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0644c8;
P_0c0644c8: /* original 1f31, guest PC 0x0c0644c8 */
if(!s->budget--) { s->failed_pc=0x0c0644c8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0644ca;
P_0c0644ca: /* original 023e, guest PC 0x0c0644ca */
if(!s->budget--) { s->failed_pc=0x0c0644cau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0644cc;
P_0c0644cc: /* original 6403, guest PC 0x0c0644cc */
if(!s->budget--) { s->failed_pc=0x0c0644ccu; return 0; }
r[4]=r[0];
goto P_0c0644ce;
P_0c0644ce: /* original 343c, guest PC 0x0c0644ce */
if(!s->budget--) { s->failed_pc=0x0c0644ceu; return 0; }
r[4]+=r[3];
goto P_0c0644d0;
P_0c0644d0: /* original 5441, guest PC 0x0c0644d0 */
if(!s->budget--) { s->failed_pc=0x0c0644d0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0644d2;
P_0c0644d2: /* original 422b, guest PC 0x0c0644d2 */
if(!s->budget--) { s->failed_pc=0x0c0644d2u; return 0; }
target=r[2];
r[15]+=0x00000008u;
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
P_0c0644d4: /* original 7f08, guest PC 0x0c0644d4 */
if(!s->budget--) { s->failed_pc=0x0c0644d4u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0644d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0644d6u; return 0; } return 1;
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
