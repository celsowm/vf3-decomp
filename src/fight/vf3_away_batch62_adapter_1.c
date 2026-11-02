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
int vf3_away_batch62_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
case 0x0c042cc0u: goto P_0c042cc0;
case 0x0c042cc2u: goto P_0c042cc2;
case 0x0c042cc4u: goto P_0c042cc4;
case 0x0c042cc6u: goto P_0c042cc6;
case 0x0c042cc8u: goto P_0c042cc8;
case 0x0c042ccau: goto P_0c042cca;
case 0x0c0556a0u: goto P_0c0556a0;
case 0x0c0556a2u: goto P_0c0556a2;
case 0x0c0556a4u: goto P_0c0556a4;
case 0x0c0556a6u: goto P_0c0556a6;
case 0x0c0556a8u: goto P_0c0556a8;
case 0x0c0556aau: goto P_0c0556aa;
case 0x0c0556acu: goto P_0c0556ac;
case 0x0c0556aeu: goto P_0c0556ae;
case 0x0c0556b0u: goto P_0c0556b0;
case 0x0c0556b2u: goto P_0c0556b2;
case 0x0c0556b4u: goto P_0c0556b4;
case 0x0c0556b6u: goto P_0c0556b6;
case 0x0c0556b8u: goto P_0c0556b8;
case 0x0c0556bau: goto P_0c0556ba;
case 0x0c0556bcu: goto P_0c0556bc;
case 0x0c0556beu: goto P_0c0556be;
case 0x0c0556c0u: goto P_0c0556c0;
case 0x0c0556c2u: goto P_0c0556c2;
case 0x0c0556c4u: goto P_0c0556c4;
case 0x0c0556c6u: goto P_0c0556c6;
case 0x0c0556c8u: goto P_0c0556c8;
case 0x0c0556cau: goto P_0c0556ca;
case 0x0c0556ccu: goto P_0c0556cc;
case 0x0c0556ceu: goto P_0c0556ce;
case 0x0c0556d0u: goto P_0c0556d0;
case 0x0c0556d2u: goto P_0c0556d2;
case 0x0c0556d4u: goto P_0c0556d4;
case 0x0c0556d6u: goto P_0c0556d6;
case 0x0c0556d8u: goto P_0c0556d8;
case 0x0c0556dau: goto P_0c0556da;
case 0x0c0556dcu: goto P_0c0556dc;
case 0x0c0556deu: goto P_0c0556de;
case 0x0c0556e0u: goto P_0c0556e0;
case 0x0c0556e2u: goto P_0c0556e2;
case 0x0c0556e4u: goto P_0c0556e4;
case 0x0c0556e6u: goto P_0c0556e6;
case 0x0c0556e8u: goto P_0c0556e8;
case 0x0c0556eau: goto P_0c0556ea;
case 0x0c0556ecu: goto P_0c0556ec;
case 0x0c0556eeu: goto P_0c0556ee;
case 0x0c0556f0u: goto P_0c0556f0;
case 0x0c0556f2u: goto P_0c0556f2;
case 0x0c0556f4u: goto P_0c0556f4;
case 0x0c0556f6u: goto P_0c0556f6;
case 0x0c0556f8u: goto P_0c0556f8;
case 0x0c0556fau: goto P_0c0556fa;
case 0x0c055704u: goto P_0c055704;
case 0x0c055706u: goto P_0c055706;
case 0x0c055708u: goto P_0c055708;
case 0x0c05570au: goto P_0c05570a;
case 0x0c05570cu: goto P_0c05570c;
case 0x0c05570eu: goto P_0c05570e;
case 0x0c055710u: goto P_0c055710;
case 0x0c055712u: goto P_0c055712;
case 0x0c055714u: goto P_0c055714;
case 0x0c055716u: goto P_0c055716;
case 0x0c055718u: goto P_0c055718;
case 0x0c05571au: goto P_0c05571a;
case 0x0c05571cu: goto P_0c05571c;
case 0x0c05571eu: goto P_0c05571e;
case 0x0c055720u: goto P_0c055720;
case 0x0c055722u: goto P_0c055722;
case 0x0c055724u: goto P_0c055724;
case 0x0c055726u: goto P_0c055726;
case 0x0c055728u: goto P_0c055728;
case 0x0c05572au: goto P_0c05572a;
case 0x0c05572cu: goto P_0c05572c;
case 0x0c05572eu: goto P_0c05572e;
case 0x0c055730u: goto P_0c055730;
case 0x0c055732u: goto P_0c055732;
case 0x0c055734u: goto P_0c055734;
case 0x0c055736u: goto P_0c055736;
case 0x0c055738u: goto P_0c055738;
case 0x0c05573au: goto P_0c05573a;
case 0x0c05573cu: goto P_0c05573c;
case 0x0c05573eu: goto P_0c05573e;
case 0x0c055740u: goto P_0c055740;
case 0x0c055742u: goto P_0c055742;
case 0x0c055744u: goto P_0c055744;
case 0x0c055746u: goto P_0c055746;
case 0x0c055748u: goto P_0c055748;
case 0x0c05574au: goto P_0c05574a;
case 0x0c05574cu: goto P_0c05574c;
case 0x0c05574eu: goto P_0c05574e;
case 0x0c055750u: goto P_0c055750;
case 0x0c055752u: goto P_0c055752;
case 0x0c055754u: goto P_0c055754;
case 0x0c055756u: goto P_0c055756;
case 0x0c055758u: goto P_0c055758;
case 0x0c05575au: goto P_0c05575a;
case 0x0c05575cu: goto P_0c05575c;
case 0x0c05575eu: goto P_0c05575e;
case 0x0c055760u: goto P_0c055760;
case 0x0c055762u: goto P_0c055762;
case 0x0c055764u: goto P_0c055764;
case 0x0c055766u: goto P_0c055766;
case 0x0c055768u: goto P_0c055768;
case 0x0c05576au: goto P_0c05576a;
case 0x0c05576cu: goto P_0c05576c;
case 0x0c05576eu: goto P_0c05576e;
case 0x0c055770u: goto P_0c055770;
case 0x0c055772u: goto P_0c055772;
case 0x0c055774u: goto P_0c055774;
case 0x0c055776u: goto P_0c055776;
case 0x0c055778u: goto P_0c055778;
case 0x0c05577au: goto P_0c05577a;
case 0x0c05577cu: goto P_0c05577c;
case 0x0c05577eu: goto P_0c05577e;
case 0x0c055780u: goto P_0c055780;
case 0x0c055782u: goto P_0c055782;
case 0x0c055784u: goto P_0c055784;
case 0x0c055786u: goto P_0c055786;
case 0x0c055788u: goto P_0c055788;
case 0x0c05578au: goto P_0c05578a;
case 0x0c05578cu: goto P_0c05578c;
case 0x0c05578eu: goto P_0c05578e;
case 0x0c055790u: goto P_0c055790;
case 0x0c055792u: goto P_0c055792;
case 0x0c055794u: goto P_0c055794;
case 0x0c055796u: goto P_0c055796;
case 0x0c055798u: goto P_0c055798;
case 0x0c05579au: goto P_0c05579a;
case 0x0c0557a0u: goto P_0c0557a0;
case 0x0c0557a2u: goto P_0c0557a2;
case 0x0c0557a4u: goto P_0c0557a4;
case 0x0c0557a6u: goto P_0c0557a6;
case 0x0c0557a8u: goto P_0c0557a8;
case 0x0c0557aau: goto P_0c0557aa;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042cc0; }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042cc0;
P_0c042cc0: /* original d102, guest PC 0x0c042cc0 */
if(!s->budget--) { s->failed_pc=0x0c042cc0u; return 0; }
r[1]=read(ram,0x0c042cccu,4);
goto P_0c042cc2;
P_0c042cc2: /* original d203, guest PC 0x0c042cc2 */
if(!s->budget--) { s->failed_pc=0x0c042cc2u; return 0; }
r[2]=read(ram,0x0c042cd0u,4);
goto P_0c042cc4;
P_0c042cc4: /* original e000, guest PC 0x0c042cc4 */
if(!s->budget--) { s->failed_pc=0x0c042cc4u; return 0; }
r[0]=0x00000000u;
goto P_0c042cc6;
P_0c042cc6: /* original 2122, guest PC 0x0c042cc6 */
if(!s->budget--) { s->failed_pc=0x0c042cc6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042cc8;
P_0c042cc8: /* original 000b, guest PC 0x0c042cc8 */
if(!s->budget--) { s->failed_pc=0x0c042cc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cca: /* original 62f6, guest PC 0x0c042cca */
if(!s->budget--) { s->failed_pc=0x0c042ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042cccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042cccu; return 0; } return 1;
P_0c0556a0: /* original 6d43, guest PC 0x0c0556a0 */
if(!s->budget--) { s->failed_pc=0x0c0556a0u; return 0; }
r[13]=r[4];
goto P_0c0556a2;
P_0c0556a2: /* original 7410, guest PC 0x0c0556a2 */
if(!s->budget--) { s->failed_pc=0x0c0556a2u; return 0; }
r[4]+=0x00000010u;
goto P_0c0556a4;
P_0c0556a4: /* original c60a, guest PC 0x0c0556a4 */
if(!s->budget--) { s->failed_pc=0x0c0556a4u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+40,4);
goto P_0c0556a6;
P_0c0556a6: /* original f049, guest PC 0x0c0556a6 */
if(!s->budget--) { s->failed_pc=0x0c0556a6u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0556a8;
P_0c0556a8: /* original f149, guest PC 0x0c0556a8 */
if(!s->budget--) { s->failed_pc=0x0c0556a8u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0556aa;
P_0c0556aa: /* original f249, guest PC 0x0c0556aa */
if(!s->budget--) { s->failed_pc=0x0c0556aau; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0556ac;
P_0c0556ac: /* original f39d, guest PC 0x0c0556ac */
if(!s->budget--) { s->failed_pc=0x0c0556acu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0556ae;
P_0c0556ae: /* original d33f, guest PC 0x0c0556ae */
if(!s->budget--) { s->failed_pc=0x0c0556aeu; return 0; }
r[3]=read(ram,0x0c0557acu,4);
goto P_0c0556b0;
P_0c0556b0: /* original f1fd, guest PC 0x0c0556b0 */
if(!s->budget--) { s->failed_pc=0x0c0556b0u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c0556b2;
P_0c0556b2: /* original 405a, guest PC 0x0c0556b2 */
if(!s->budget--) { s->failed_pc=0x0c0556b2u; return 0; }
r[53]=r[0];
goto P_0c0556b4;
P_0c0556b4: /* original f60d, guest PC 0x0c0556b4 */
if(!s->budget--) { s->failed_pc=0x0c0556b4u; return 0; }
fr[6]=r[53];
goto P_0c0556b6;
P_0c0556b6: /* original f448, guest PC 0x0c0556b6 */
if(!s->budget--) { s->failed_pc=0x0c0556b6u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0556b8;
P_0c0556b8: /* original f538, guest PC 0x0c0556b8 */
if(!s->budget--) { s->failed_pc=0x0c0556b8u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c0556ba;
P_0c0556ba: /* original f24d, guest PC 0x0c0556ba */
if(!s->budget--) { s->failed_pc=0x0c0556bau; return 0; }
fr[2]^=0x80000000u;
goto P_0c0556bc;
P_0c0556bc: /* original f462, guest PC 0x0c0556bc */
if(!s->budget--) { s->failed_pc=0x0c0556bcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0556be;
P_0c0556be: /* original f72c, guest PC 0x0c0556be */
if(!s->budget--) { s->failed_pc=0x0c0556beu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c0556c0;
P_0c0556c0: /* original f82c, guest PC 0x0c0556c0 */
if(!s->budget--) { s->failed_pc=0x0c0556c0u; return 0; }
vf3_matrix_move(s,8,2);
goto P_0c0556c2;
P_0c0556c2: /* original f740, guest PC 0x0c0556c2 */
if(!s->budget--) { s->failed_pc=0x0c0556c2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'+');
goto P_0c0556c4;
P_0c0556c4: /* original f98d, guest PC 0x0c0556c4 */
if(!s->budget--) { s->failed_pc=0x0c0556c4u; return 0; }
fr[9]=0;
goto P_0c0556c6;
P_0c0556c6: /* original f841, guest PC 0x0c0556c6 */
if(!s->budget--) { s->failed_pc=0x0c0556c6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0556c8;
P_0c0556c8: /* original f975, guest PC 0x0c0556c8 */
if(!s->budget--) { s->failed_pc=0x0c0556c8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[7]))!=0);
goto P_0c0556ca;
P_0c0556ca: /* original d339, guest PC 0x0c0556ca */
if(!s->budget--) { s->failed_pc=0x0c0556cau; return 0; }
r[3]=read(ram,0x0c0557b0u,4);
goto P_0c0556cc;
P_0c0556cc: /* original 8b01, guest PC 0x0c0556cc */
if(!s->budget--) { s->failed_pc=0x0c0556ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0556d2; }
goto P_0c0556ce;
P_0c0556ce: /* original a06b, guest PC 0x0c0556ce */
if(!s->budget--) { s->failed_pc=0x0c0556ceu; return 0; }
goto P_0c0557a8;
P_0c0556d0: /* original 0009, guest PC 0x0c0556d0 */
if(!s->budget--) { s->failed_pc=0x0c0556d0u; return 0; }
goto P_0c0556d2;
P_0c0556d2: /* original f855, guest PC 0x0c0556d2 */
if(!s->budget--) { s->failed_pc=0x0c0556d2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c0556d4;
P_0c0556d4: /* original 8b01, guest PC 0x0c0556d4 */
if(!s->budget--) { s->failed_pc=0x0c0556d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0556da; }
goto P_0c0556d6;
P_0c0556d6: /* original a067, guest PC 0x0c0556d6 */
if(!s->budget--) { s->failed_pc=0x0c0556d6u; return 0; }
goto P_0c0557a8;
P_0c0556d8: /* original 0009, guest PC 0x0c0556d8 */
if(!s->budget--) { s->failed_pc=0x0c0556d8u; return 0; }
goto P_0c0556da;
P_0c0556da: /* original 4f22, guest PC 0x0c0556da */
if(!s->budget--) { s->failed_pc=0x0c0556dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0556dc;
P_0c0556dc: /* original 430b, guest PC 0x0c0556dc */
if(!s->budget--) { s->failed_pc=0x0c0556dcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0556e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0556e0u) { target=s->pc; goto dispatch; }
goto P_0c0556e0;
P_0c0556de: /* original e400, guest PC 0x0c0556de */
if(!s->budget--) { s->failed_pc=0x0c0556deu; return 0; }
r[4]=0x00000000u;
goto P_0c0556e0;
P_0c0556e0: /* original c605, guest PC 0x0c0556e0 */
if(!s->budget--) { s->failed_pc=0x0c0556e0u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+20,4);
goto P_0c0556e2;
P_0c0556e2: /* original 400b, guest PC 0x0c0556e2 */
if(!s->budget--) { s->failed_pc=0x0c0556e2u; return 0; }
target=r[0];
r[16]=code_base|0x0c0556e6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0556e6u) { target=s->pc; goto dispatch; }
goto P_0c0556e6;
P_0c0556e4: /* original 0009, guest PC 0x0c0556e4 */
if(!s->budget--) { s->failed_pc=0x0c0556e4u; return 0; }
goto P_0c0556e6;
P_0c0556e6: /* original 50d0, guest PC 0x0c0556e6 */
if(!s->budget--) { s->failed_pc=0x0c0556e6u; return 0; }
r[0]=read(ram,r[13]+0,4);
goto P_0c0556e8;
P_0c0556e8: /* original e120, guest PC 0x0c0556e8 */
if(!s->budget--) { s->failed_pc=0x0c0556e8u; return 0; }
r[1]=0x00000020u;
goto P_0c0556ea;
P_0c0556ea: /* original 2108, guest PC 0x0c0556ea */
if(!s->budget--) { s->failed_pc=0x0c0556eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[0])==0)!=0);
goto P_0c0556ec;
P_0c0556ec: /* original 890e, guest PC 0x0c0556ec */
if(!s->budget--) { s->failed_pc=0x0c0556ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05570c; }
goto P_0c0556ee;
P_0c0556ee: /* original d003, guest PC 0x0c0556ee */
if(!s->budget--) { s->failed_pc=0x0c0556eeu; return 0; }
r[0]=read(ram,0x0c0556fcu,4);
goto P_0c0556f0;
P_0c0556f0: /* original 6002, guest PC 0x0c0556f0 */
if(!s->budget--) { s->failed_pc=0x0c0556f0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0556f2;
P_0c0556f2: /* original 2008, guest PC 0x0c0556f2 */
if(!s->budget--) { s->failed_pc=0x0c0556f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0556f4;
P_0c0556f4: /* original 8b06, guest PC 0x0c0556f4 */
if(!s->budget--) { s->failed_pc=0x0c0556f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055704; }
goto P_0c0556f6;
P_0c0556f6: /* original d002, guest PC 0x0c0556f6 */
if(!s->budget--) { s->failed_pc=0x0c0556f6u; return 0; }
r[0]=read(ram,0x0c055700u,4);
goto P_0c0556f8;
P_0c0556f8: /* original a005, guest PC 0x0c0556f8 */
if(!s->budget--) { s->failed_pc=0x0c0556f8u; return 0; }
goto P_0c055706;
P_0c0556fa: /* original 0009, guest PC 0x0c0556fa */
if(!s->budget--) { s->failed_pc=0x0c0556fau; return 0; }
if(!vf3_matrix_family(0x0c0556fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0556fcu; return 0; } return 1;
P_0c055704: /* original d025, guest PC 0x0c055704 */
if(!s->budget--) { s->failed_pc=0x0c055704u; return 0; }
r[0]=read(ram,0x0c05579cu,4);
goto P_0c055706;
P_0c055706: /* original 54d1, guest PC 0x0c055706 */
if(!s->budget--) { s->failed_pc=0x0c055706u; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c055708;
P_0c055708: /* original 400b, guest PC 0x0c055708 */
if(!s->budget--) { s->failed_pc=0x0c055708u; return 0; }
target=r[0];
r[16]=code_base|0x0c05570cu;
r[6]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05570cu) { target=s->pc; goto dispatch; }
goto P_0c05570c;
P_0c05570a: /* original 56d2, guest PC 0x0c05570a */
if(!s->budget--) { s->failed_pc=0x0c05570au; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c05570c;
P_0c05570c: /* original 64d3, guest PC 0x0c05570c */
if(!s->budget--) { s->failed_pc=0x0c05570cu; return 0; }
r[4]=r[13];
goto P_0c05570e;
P_0c05570e: /* original 7410, guest PC 0x0c05570e */
if(!s->budget--) { s->failed_pc=0x0c05570eu; return 0; }
r[4]+=0x00000010u;
goto P_0c055710;
P_0c055710: /* original c60a, guest PC 0x0c055710 */
if(!s->budget--) { s->failed_pc=0x0c055710u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+40,4);
goto P_0c055712;
P_0c055712: /* original f049, guest PC 0x0c055712 */
if(!s->budget--) { s->failed_pc=0x0c055712u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055714;
P_0c055714: /* original f149, guest PC 0x0c055714 */
if(!s->budget--) { s->failed_pc=0x0c055714u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055716;
P_0c055716: /* original f249, guest PC 0x0c055716 */
if(!s->budget--) { s->failed_pc=0x0c055716u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055718;
P_0c055718: /* original f39d, guest PC 0x0c055718 */
if(!s->budget--) { s->failed_pc=0x0c055718u; return 0; }
fr[3]=0x3f800000u;
goto P_0c05571a;
P_0c05571a: /* original f1fd, guest PC 0x0c05571a */
if(!s->budget--) { s->failed_pc=0x0c05571au; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c05571c;
P_0c05571c: /* original 405a, guest PC 0x0c05571c */
if(!s->budget--) { s->failed_pc=0x0c05571cu; return 0; }
r[53]=r[0];
goto P_0c05571e;
P_0c05571e: /* original f60d, guest PC 0x0c05571e */
if(!s->budget--) { s->failed_pc=0x0c05571eu; return 0; }
fr[6]=r[53];
goto P_0c055720;
P_0c055720: /* original c727, guest PC 0x0c055720 */
if(!s->budget--) { s->failed_pc=0x0c055720u; return 0; }
r[0]=code_base|0x000557c0u;
goto P_0c055722;
P_0c055722: /* original 6002, guest PC 0x0c055722 */
if(!s->budget--) { s->failed_pc=0x0c055722u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c055724;
P_0c055724: /* original e302, guest PC 0x0c055724 */
if(!s->budget--) { s->failed_pc=0x0c055724u; return 0; }
r[3]=0x00000002u;
goto P_0c055726;
P_0c055726: /* original ff49, guest PC 0x0c055726 */
if(!s->budget--) { s->failed_pc=0x0c055726u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055728;
P_0c055728: /* original ff62, guest PC 0x0c055728 */
if(!s->budget--) { s->failed_pc=0x0c055728u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c05572a;
P_0c05572a: /* original f3fd, guest PC 0x0c05572a */
if(!s->budget--) { s->failed_pc=0x0c05572au; return 0; }
r[18]^=0x100000u;
goto P_0c05572c;
P_0c05572c: /* original f409, guest PC 0x0c05572c */
if(!s->budget--) { s->failed_pc=0x0c05572cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c05572e;
P_0c05572e: /* original f609, guest PC 0x0c05572e */
if(!s->budget--) { s->failed_pc=0x0c05572eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c055730;
P_0c055730: /* original f809, guest PC 0x0c055730 */
if(!s->budget--) { s->failed_pc=0x0c055730u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c055732;
P_0c055732: /* original fa09, guest PC 0x0c055732 */
if(!s->budget--) { s->failed_pc=0x0c055732u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c055734;
P_0c055734: /* original f4ed, guest PC 0x0c055734 */
if(!s->budget--) { s->failed_pc=0x0c055734u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c055736;
P_0c055736: /* original f8ed, guest PC 0x0c055736 */
if(!s->budget--) { s->failed_pc=0x0c055736u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c055738;
P_0c055738: /* original ff75, guest PC 0x0c055738 */
if(!s->budget--) { s->failed_pc=0x0c055738u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[7]))!=0);
goto P_0c05573a;
P_0c05573a: /* original f3fd, guest PC 0x0c05573a */
if(!s->budget--) { s->failed_pc=0x0c05573au; return 0; }
r[18]^=0x100000u;
goto P_0c05573c;
P_0c05573c: /* original 8b30, guest PC 0x0c05573c */
if(!s->budget--) { s->failed_pc=0x0c05573cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0557a0; }
goto P_0c05573e;
P_0c05573e: /* original ffb5, guest PC 0x0c05573e */
if(!s->budget--) { s->failed_pc=0x0c05573eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[11]))!=0);
goto P_0c055740;
P_0c055740: /* original 8b2e, guest PC 0x0c055740 */
if(!s->budget--) { s->failed_pc=0x0c055740u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0557a0; }
goto P_0c055742;
P_0c055742: /* original 4310, guest PC 0x0c055742 */
if(!s->budget--) { s->failed_pc=0x0c055742u; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c055744;
P_0c055744: /* original 8bf1, guest PC 0x0c055744 */
if(!s->budget--) { s->failed_pc=0x0c055744u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05572a; }
goto P_0c055746;
P_0c055746: /* original c71c, guest PC 0x0c055746 */
if(!s->budget--) { s->failed_pc=0x0c055746u; return 0; }
r[0]=code_base|0x000557b8u;
goto P_0c055748;
P_0c055748: /* original d31a, guest PC 0x0c055748 */
if(!s->budget--) { s->failed_pc=0x0c055748u; return 0; }
r[3]=read(ram,0x0c0557b4u,4);
goto P_0c05574a;
P_0c05574a: /* original 6106, guest PC 0x0c05574a */
if(!s->budget--) { s->failed_pc=0x0c05574au; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c05574c;
P_0c05574c: /* original f418, guest PC 0x0c05574c */
if(!s->budget--) { s->failed_pc=0x0c05574cu; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
goto P_0c05574e;
P_0c05574e: /* original 6106, guest PC 0x0c05574e */
if(!s->budget--) { s->failed_pc=0x0c05574eu; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055750;
P_0c055750: /* original 430b, guest PC 0x0c055750 */
if(!s->budget--) { s->failed_pc=0x0c055750u; return 0; }
target=r[3];
r[16]=code_base|0x0c055754u;
vf3_matrix_load(s,ram,5,r[1]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055754u) { target=s->pc; goto dispatch; }
goto P_0c055754;
P_0c055752: /* original f518, guest PC 0x0c055752 */
if(!s->budget--) { s->failed_pc=0x0c055752u; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
goto P_0c055754;
P_0c055754: /* original d11b, guest PC 0x0c055754 */
if(!s->budget--) { s->failed_pc=0x0c055754u; return 0; }
r[1]=read(ram,0x0c0557c4u,4);
goto P_0c055756;
P_0c055756: /* original c611, guest PC 0x0c055756 */
if(!s->budget--) { s->failed_pc=0x0c055756u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+68,4);
goto P_0c055758;
P_0c055758: /* original 6303, guest PC 0x0c055758 */
if(!s->budget--) { s->failed_pc=0x0c055758u; return 0; }
r[3]=r[0];
goto P_0c05575a;
P_0c05575a: /* original c604, guest PC 0x0c05575a */
if(!s->budget--) { s->failed_pc=0x0c05575au; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+16,4);
goto P_0c05575c;
P_0c05575c: /* original 54d1, guest PC 0x0c05575c */
if(!s->budget--) { s->failed_pc=0x0c05575cu; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c05575e;
P_0c05575e: /* original 56d2, guest PC 0x0c05575e */
if(!s->budget--) { s->failed_pc=0x0c05575eu; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c055760;
P_0c055760: /* original 4315, guest PC 0x0c055760 */
if(!s->budget--) { s->failed_pc=0x0c055760u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c055762;
P_0c055762: /* original 67d3, guest PC 0x0c055762 */
if(!s->budget--) { s->failed_pc=0x0c055762u; return 0; }
r[7]=r[13];
goto P_0c055764;
P_0c055764: /* original 8901, guest PC 0x0c055764 */
if(!s->budget--) { s->failed_pc=0x0c055764u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05576a; }
goto P_0c055766;
P_0c055766: /* original 400b, guest PC 0x0c055766 */
if(!s->budget--) { s->failed_pc=0x0c055766u; return 0; }
target=r[0];
r[16]=code_base|0x0c05576au;
tmp=read(ram,r[1],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05576au) { target=s->pc; goto dispatch; }
goto P_0c05576a;
P_0c055768: /* original 6512, guest PC 0x0c055768 */
if(!s->budget--) { s->failed_pc=0x0c055768u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c05576a;
P_0c05576a: /* original c719, guest PC 0x0c05576a */
if(!s->budget--) { s->failed_pc=0x0c05576au; return 0; }
r[0]=code_base|0x000557d0u;
goto P_0c05576c;
P_0c05576c: /* original da19, guest PC 0x0c05576c */
if(!s->budget--) { s->failed_pc=0x0c05576cu; return 0; }
r[10]=read(ram,0x0c0557d4u,4);
goto P_0c05576e;
P_0c05576e: /* original f308, guest PC 0x0c05576e */
if(!s->budget--) { s->failed_pc=0x0c05576eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c055770;
P_0c055770: /* original d314, guest PC 0x0c055770 */
if(!s->budget--) { s->failed_pc=0x0c055770u; return 0; }
r[3]=read(ram,0x0c0557c4u,4);
goto P_0c055772;
P_0c055772: /* original e1f0, guest PC 0x0c055772 */
if(!s->budget--) { s->failed_pc=0x0c055772u; return 0; }
r[1]=0xfffffff0u;
goto P_0c055774;
P_0c055774: /* original c603, guest PC 0x0c055774 */
if(!s->budget--) { s->failed_pc=0x0c055774u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+12,4);
goto P_0c055776;
P_0c055776: /* original 4128, guest PC 0x0c055776 */
if(!s->budget--) { s->failed_pc=0x0c055776u; return 0; }
r[1]<<=16;
goto P_0c055778;
P_0c055778: /* original 54d3, guest PC 0x0c055778 */
if(!s->budget--) { s->failed_pc=0x0c055778u; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c05577a;
P_0c05577a: /* original 4118, guest PC 0x0c05577a */
if(!s->budget--) { s->failed_pc=0x0c05577au; return 0; }
r[1]<<=8;
goto P_0c05577c;
P_0c05577c: /* original 6aa2, guest PC 0x0c05577c */
if(!s->budget--) { s->failed_pc=0x0c05577cu; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c05577e;
P_0c05577e: /* original e200, guest PC 0x0c05577e */
if(!s->budget--) { s->failed_pc=0x0c05577eu; return 0; }
r[2]=0x00000000u;
goto P_0c055780;
P_0c055780: /* original 6e03, guest PC 0x0c055780 */
if(!s->budget--) { s->failed_pc=0x0c055780u; return 0; }
r[14]=r[0];
goto P_0c055782;
P_0c055782: /* original 42be, guest PC 0x0c055782 */
if(!s->budget--) { s->failed_pc=0x0c055782u; return 0; }
if(!s->bank_known) goto unsupported;
s->bank[3]=r[2];
goto P_0c055784;
P_0c055784: /* original 6d32, guest PC 0x0c055784 */
if(!s->budget--) { s->failed_pc=0x0c055784u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c055786;
P_0c055786: /* original 41ce, guest PC 0x0c055786 */
if(!s->budget--) { s->failed_pc=0x0c055786u; return 0; }
if(!s->bank_known) goto unsupported;
s->bank[4]=r[1];
goto P_0c055788;
P_0c055788: /* original 6041, guest PC 0x0c055788 */
if(!s->budget--) { s->failed_pc=0x0c055788u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c05578a;
P_0c05578a: /* original 4011, guest PC 0x0c05578a */
if(!s->budget--) { s->failed_pc=0x0c05578au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c05578c;
P_0c05578c: /* original 600c, guest PC 0x0c05578c */
if(!s->budget--) { s->failed_pc=0x0c05578cu; return 0; }
r[0]=r[0]&255u;
goto P_0c05578e;
P_0c05578e: /* original 8f07, guest PC 0x0c05578e */
if(!s->budget--) { s->failed_pc=0x0c05578eu; return 0; }
cond=r[17]&1u;
r[0]<<=2;
if(!cond) { goto P_0c0557a0; }
goto P_0c055792;
P_0c055790: /* original 4008, guest PC 0x0c055790 */
if(!s->budget--) { s->failed_pc=0x0c055790u; return 0; }
r[0]<<=2;
goto P_0c055792;
P_0c055792: /* original 03ee, guest PC 0x0c055792 */
if(!s->budget--) { s->failed_pc=0x0c055792u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c055794;
P_0c055794: /* original 430b, guest PC 0x0c055794 */
if(!s->budget--) { s->failed_pc=0x0c055794u; return 0; }
target=r[3];
r[16]=code_base|0x0c055798u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055798u) { target=s->pc; goto dispatch; }
goto P_0c055798;
P_0c055796: /* original 0009, guest PC 0x0c055796 */
if(!s->budget--) { s->failed_pc=0x0c055796u; return 0; }
goto P_0c055798;
P_0c055798: /* original aff7, guest PC 0x0c055798 */
if(!s->budget--) { s->failed_pc=0x0c055798u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c05578a;
P_0c05579a: /* original 6041, guest PC 0x0c05579a */
if(!s->budget--) { s->failed_pc=0x0c05579au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
if(!vf3_matrix_family(0x0c05579cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05579cu; return 0; } return 1;
P_0c0557a0: /* original d30d, guest PC 0x0c0557a0 */
if(!s->budget--) { s->failed_pc=0x0c0557a0u; return 0; }
r[3]=read(ram,0x0c0557d8u,4);
goto P_0c0557a2;
P_0c0557a2: /* original 4f26, guest PC 0x0c0557a2 */
if(!s->budget--) { s->failed_pc=0x0c0557a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0557a4;
P_0c0557a4: /* original 432b, guest PC 0x0c0557a4 */
if(!s->budget--) { s->failed_pc=0x0c0557a4u; return 0; }
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
P_0c0557a6: /* original e401, guest PC 0x0c0557a6 */
if(!s->budget--) { s->failed_pc=0x0c0557a6u; return 0; }
r[4]=0x00000001u;
goto P_0c0557a8;
P_0c0557a8: /* original 000b, guest PC 0x0c0557a8 */
if(!s->budget--) { s->failed_pc=0x0c0557a8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0557aa: /* original 0009, guest PC 0x0c0557aa */
if(!s->budget--) { s->failed_pc=0x0c0557aau; return 0; }
if(!vf3_matrix_family(0x0c0557acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0557acu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
