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
int vf3_away_batch244_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03e680u: goto P_0c03e680;
case 0x0c03e682u: goto P_0c03e682;
case 0x0c03e684u: goto P_0c03e684;
case 0x0c03e686u: goto P_0c03e686;
case 0x0c03e688u: goto P_0c03e688;
case 0x0c03e68au: goto P_0c03e68a;
case 0x0c03e68cu: goto P_0c03e68c;
case 0x0c03e68eu: goto P_0c03e68e;
case 0x0c03e690u: goto P_0c03e690;
case 0x0c03e692u: goto P_0c03e692;
case 0x0c03e694u: goto P_0c03e694;
case 0x0c03e696u: goto P_0c03e696;
case 0x0c03e698u: goto P_0c03e698;
case 0x0c03e69au: goto P_0c03e69a;
case 0x0c03e69cu: goto P_0c03e69c;
case 0x0c03e69eu: goto P_0c03e69e;
case 0x0c03e6a0u: goto P_0c03e6a0;
case 0x0c03e6a2u: goto P_0c03e6a2;
case 0x0c03e6a4u: goto P_0c03e6a4;
case 0x0c03e6a6u: goto P_0c03e6a6;
case 0x0c03e6a8u: goto P_0c03e6a8;
case 0x0c03e7f0u: goto P_0c03e7f0;
case 0x0c03e7f2u: goto P_0c03e7f2;
case 0x0c03e7f4u: goto P_0c03e7f4;
case 0x0c03e7f6u: goto P_0c03e7f6;
case 0x0c03e7f8u: goto P_0c03e7f8;
case 0x0c03e7fau: goto P_0c03e7fa;
case 0x0c03e7fcu: goto P_0c03e7fc;
case 0x0c03e7feu: goto P_0c03e7fe;
case 0x0c03e800u: goto P_0c03e800;
case 0x0c03e802u: goto P_0c03e802;
case 0x0c03e804u: goto P_0c03e804;
case 0x0c03e860u: goto P_0c03e860;
case 0x0c03e862u: goto P_0c03e862;
case 0x0c03e864u: goto P_0c03e864;
case 0x0c03e866u: goto P_0c03e866;
case 0x0c03e868u: goto P_0c03e868;
case 0x0c03e86au: goto P_0c03e86a;
case 0x0c03e86cu: goto P_0c03e86c;
case 0x0c03e86eu: goto P_0c03e86e;
case 0x0c03e870u: goto P_0c03e870;
case 0x0c03e872u: goto P_0c03e872;
case 0x0c03e874u: goto P_0c03e874;
case 0x0c03e876u: goto P_0c03e876;
case 0x0c03e878u: goto P_0c03e878;
case 0x0c03e87au: goto P_0c03e87a;
case 0x0c03e87cu: goto P_0c03e87c;
case 0x0c03e87eu: goto P_0c03e87e;
case 0x0c03e880u: goto P_0c03e880;
case 0x0c03e882u: goto P_0c03e882;
case 0x0c03e884u: goto P_0c03e884;
case 0x0c03e886u: goto P_0c03e886;
case 0x0c03e888u: goto P_0c03e888;
case 0x0c03ecb0u: goto P_0c03ecb0;
case 0x0c03ecb2u: goto P_0c03ecb2;
case 0x0c03ecb4u: goto P_0c03ecb4;
case 0x0c03ecb6u: goto P_0c03ecb6;
case 0x0c03ecb8u: goto P_0c03ecb8;
case 0x0c03ecbau: goto P_0c03ecba;
case 0x0c03ecbcu: goto P_0c03ecbc;
case 0x0c03ecbeu: goto P_0c03ecbe;
case 0x0c03ecc0u: goto P_0c03ecc0;
case 0x0c03ecc2u: goto P_0c03ecc2;
case 0x0c03ecc4u: goto P_0c03ecc4;
case 0x0c03ecc6u: goto P_0c03ecc6;
case 0x0c03ecc8u: goto P_0c03ecc8;
case 0x0c03eccau: goto P_0c03ecca;
case 0x0c03ed50u: goto P_0c03ed50;
case 0x0c03ed52u: goto P_0c03ed52;
case 0x0c03ed54u: goto P_0c03ed54;
case 0x0c03ed56u: goto P_0c03ed56;
case 0x0c03ed58u: goto P_0c03ed58;
case 0x0c03ed60u: goto P_0c03ed60;
case 0x0c03ed62u: goto P_0c03ed62;
case 0x0c03ed64u: goto P_0c03ed64;
case 0x0c03ed66u: goto P_0c03ed66;
case 0x0c03ed68u: goto P_0c03ed68;
case 0x0c03ed6au: goto P_0c03ed6a;
case 0x0c03ed6cu: goto P_0c03ed6c;
case 0x0c03ed6eu: goto P_0c03ed6e;
case 0x0c03ed70u: goto P_0c03ed70;
case 0x0c03ed72u: goto P_0c03ed72;
case 0x0c03ed74u: goto P_0c03ed74;
case 0x0c03ed76u: goto P_0c03ed76;
case 0x0c03ed78u: goto P_0c03ed78;
case 0x0c03ed7au: goto P_0c03ed7a;
case 0x0c03ed7cu: goto P_0c03ed7c;
case 0x0c03eda0u: goto P_0c03eda0;
case 0x0c03eda2u: goto P_0c03eda2;
case 0x0c03eda4u: goto P_0c03eda4;
case 0x0c03eda6u: goto P_0c03eda6;
case 0x0c03eda8u: goto P_0c03eda8;
case 0x0c03edaau: goto P_0c03edaa;
case 0x0c03edacu: goto P_0c03edac;
case 0x0c03ee40u: goto P_0c03ee40;
case 0x0c03ee42u: goto P_0c03ee42;
case 0x0c03ee44u: goto P_0c03ee44;
case 0x0c03ee46u: goto P_0c03ee46;
case 0x0c03ee90u: goto P_0c03ee90;
case 0x0c03ee92u: goto P_0c03ee92;
case 0x0c03ee94u: goto P_0c03ee94;
case 0x0c03ee96u: goto P_0c03ee96;
case 0x0c03ee98u: goto P_0c03ee98;
case 0x0c03ee9au: goto P_0c03ee9a;
case 0x0c03ee9cu: goto P_0c03ee9c;
case 0x0c03ee9eu: goto P_0c03ee9e;
case 0x0c03eea0u: goto P_0c03eea0;
case 0x0c03eea2u: goto P_0c03eea2;
case 0x0c03eea4u: goto P_0c03eea4;
case 0x0c03eea6u: goto P_0c03eea6;
case 0x0c03eea8u: goto P_0c03eea8;
case 0x0c03eeaau: goto P_0c03eeaa;
case 0x0c03eeacu: goto P_0c03eeac;
case 0x0c03eeaeu: goto P_0c03eeae;
case 0x0c03eeb0u: goto P_0c03eeb0;
case 0x0c03eeb2u: goto P_0c03eeb2;
case 0x0c03eeb4u: goto P_0c03eeb4;
case 0x0c03eeb6u: goto P_0c03eeb6;
case 0x0c03eeb8u: goto P_0c03eeb8;
case 0x0c03eebau: goto P_0c03eeba;
case 0x0c03eebcu: goto P_0c03eebc;
case 0x0c03eebeu: goto P_0c03eebe;
case 0x0c03eec0u: goto P_0c03eec0;
case 0x0c03eec2u: goto P_0c03eec2;
case 0x0c03eec4u: goto P_0c03eec4;
case 0x0c03eec6u: goto P_0c03eec6;
case 0x0c03eec8u: goto P_0c03eec8;
case 0x0c03eecau: goto P_0c03eeca;
case 0x0c03eeccu: goto P_0c03eecc;
case 0x0c03eeceu: goto P_0c03eece;
case 0x0c03eed0u: goto P_0c03eed0;
case 0x0c03eed2u: goto P_0c03eed2;
case 0x0c03eed4u: goto P_0c03eed4;
case 0x0c03eed6u: goto P_0c03eed6;
case 0x0c03eed8u: goto P_0c03eed8;
case 0x0c03eedau: goto P_0c03eeda;
case 0x0c03eedcu: goto P_0c03eedc;
case 0x0c03eedeu: goto P_0c03eede;
case 0x0c03eee0u: goto P_0c03eee0;
case 0x0c03eee2u: goto P_0c03eee2;
case 0x0c03eee4u: goto P_0c03eee4;
case 0x0c03eee6u: goto P_0c03eee6;
case 0x0c03eee8u: goto P_0c03eee8;
case 0x0c03eeeau: goto P_0c03eeea;
case 0x0c03eeecu: goto P_0c03eeec;
case 0x0c03eeeeu: goto P_0c03eeee;
case 0x0c03eef0u: goto P_0c03eef0;
case 0x0c03eef2u: goto P_0c03eef2;
case 0x0c03eef4u: goto P_0c03eef4;
case 0x0c03eef6u: goto P_0c03eef6;
case 0x0c03eef8u: goto P_0c03eef8;
case 0x0c03eefau: goto P_0c03eefa;
case 0x0c03eefcu: goto P_0c03eefc;
case 0x0c03eefeu: goto P_0c03eefe;
case 0x0c03ef00u: goto P_0c03ef00;
case 0x0c03ef02u: goto P_0c03ef02;
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
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
P_0c03e680: /* original 2fe6, guest PC 0x0c03e680 */
if(!s->budget--) { s->failed_pc=0x0c03e680u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e682;
P_0c03e682: /* original e044, guest PC 0x0c03e682 */
if(!s->budget--) { s->failed_pc=0x0c03e682u; return 0; }
r[0]=0x00000044u;
goto P_0c03e684;
P_0c03e684: /* original 9e57, guest PC 0x0c03e684 */
if(!s->budget--) { s->failed_pc=0x0c03e684u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e736u,2);
goto P_0c03e686;
P_0c03e686: /* original 4f12, guest PC 0x0c03e686 */
if(!s->budget--) { s->failed_pc=0x0c03e686u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e688;
P_0c03e688: /* original 24ef, guest PC 0x0c03e688 */
if(!s->budget--) { s->failed_pc=0x0c03e688u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c03e68a;
P_0c03e68a: /* original d32c, guest PC 0x0c03e68a */
if(!s->budget--) { s->failed_pc=0x0c03e68au; return 0; }
r[3]=read(ram,0x0c03e73cu,4);
goto P_0c03e68c;
P_0c03e68c: /* original 0e1a, guest PC 0x0c03e68c */
if(!s->budget--) { s->failed_pc=0x0c03e68cu; return 0; }
r[14]=r[19];
goto P_0c03e68e;
P_0c03e68e: /* original 4f16, guest PC 0x0c03e68e */
if(!s->budget--) { s->failed_pc=0x0c03e68eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e690;
P_0c03e690: /* original 6eef, guest PC 0x0c03e690 */
if(!s->budget--) { s->failed_pc=0x0c03e690u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c03e692;
P_0c03e692: /* original 3e3c, guest PC 0x0c03e692 */
if(!s->budget--) { s->failed_pc=0x0c03e692u; return 0; }
r[14]+=r[3];
goto P_0c03e694;
P_0c03e694: /* original 62e3, guest PC 0x0c03e694 */
if(!s->budget--) { s->failed_pc=0x0c03e694u; return 0; }
r[2]=r[14];
goto P_0c03e696;
P_0c03e696: /* original 7240, guest PC 0x0c03e696 */
if(!s->budget--) { s->failed_pc=0x0c03e696u; return 0; }
r[2]+=0x00000040u;
goto P_0c03e698;
P_0c03e698: /* original f24a, guest PC 0x0c03e698 */
if(!s->budget--) { s->failed_pc=0x0c03e698u; return 0; }
vf3_matrix_store(s,ram,4,r[2]);
goto P_0c03e69a;
P_0c03e69a: /* original 64e3, guest PC 0x0c03e69a */
if(!s->budget--) { s->failed_pc=0x0c03e69au; return 0; }
r[4]=r[14];
goto P_0c03e69c;
P_0c03e69c: /* original fe57, guest PC 0x0c03e69c */
if(!s->budget--) { s->failed_pc=0x0c03e69cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c03e69e;
P_0c03e69e: /* original e048, guest PC 0x0c03e69e */
if(!s->budget--) { s->failed_pc=0x0c03e69eu; return 0; }
r[0]=0x00000048u;
goto P_0c03e6a0;
P_0c03e6a0: /* original fe67, guest PC 0x0c03e6a0 */
if(!s->budget--) { s->failed_pc=0x0c03e6a0u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c03e6a2;
P_0c03e6a2: /* original 7440, guest PC 0x0c03e6a2 */
if(!s->budget--) { s->failed_pc=0x0c03e6a2u; return 0; }
r[4]+=0x00000040u;
goto P_0c03e6a4;
P_0c03e6a4: /* original d22a, guest PC 0x0c03e6a4 */
if(!s->budget--) { s->failed_pc=0x0c03e6a4u; return 0; }
r[2]=read(ram,0x0c03e750u,4);
goto P_0c03e6a6;
P_0c03e6a6: /* original 422b, guest PC 0x0c03e6a6 */
if(!s->budget--) { s->failed_pc=0x0c03e6a6u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03d040u: return vf3_matrix_family(0x0c03d040u,s,ram);
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
P_0c03e6a8: /* original 6ef6, guest PC 0x0c03e6a8 */
if(!s->budget--) { s->failed_pc=0x0c03e6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e6aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e6aau; return 0; } return 1;
P_0c03e7f0: /* original 934b, guest PC 0x0c03e7f0 */
if(!s->budget--) { s->failed_pc=0x0c03e7f0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e88au,2);
goto P_0c03e7f2;
P_0c03e7f2: /* original 6053, guest PC 0x0c03e7f2 */
if(!s->budget--) { s->failed_pc=0x0c03e7f2u; return 0; }
r[0]=r[5];
goto P_0c03e7f4;
P_0c03e7f4: /* original 4f12, guest PC 0x0c03e7f4 */
if(!s->budget--) { s->failed_pc=0x0c03e7f4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e7f6;
P_0c03e7f6: /* original 243f, guest PC 0x0c03e7f6 */
if(!s->budget--) { s->failed_pc=0x0c03e7f6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c03e7f8;
P_0c03e7f8: /* original d225, guest PC 0x0c03e7f8 */
if(!s->budget--) { s->failed_pc=0x0c03e7f8u; return 0; }
r[2]=read(ram,0x0c03e890u,4);
goto P_0c03e7fa;
P_0c03e7fa: /* original 041a, guest PC 0x0c03e7fa */
if(!s->budget--) { s->failed_pc=0x0c03e7fau; return 0; }
r[4]=r[19];
goto P_0c03e7fc;
P_0c03e7fc: /* original 644f, guest PC 0x0c03e7fc */
if(!s->budget--) { s->failed_pc=0x0c03e7fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c03e7fe;
P_0c03e7fe: /* original 342c, guest PC 0x0c03e7fe */
if(!s->budget--) { s->failed_pc=0x0c03e7feu; return 0; }
r[4]+=r[2];
goto P_0c03e800;
P_0c03e800: /* original 8141, guest PC 0x0c03e800 */
if(!s->budget--) { s->failed_pc=0x0c03e800u; return 0; }
write(ram,r[4]+2,r[0],2);
goto P_0c03e802;
P_0c03e802: /* original 000b, guest PC 0x0c03e802 */
if(!s->budget--) { s->failed_pc=0x0c03e802u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c03e804: /* original 4f16, guest PC 0x0c03e804 */
if(!s->budget--) { s->failed_pc=0x0c03e804u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03e806u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e806u; return 0; } return 1;
P_0c03e860: /* original 9313, guest PC 0x0c03e860 */
if(!s->budget--) { s->failed_pc=0x0c03e860u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e88au,2);
goto P_0c03e862;
P_0c03e862: /* original e014, guest PC 0x0c03e862 */
if(!s->budget--) { s->failed_pc=0x0c03e862u; return 0; }
r[0]=0x00000014u;
goto P_0c03e864;
P_0c03e864: /* original 4f12, guest PC 0x0c03e864 */
if(!s->budget--) { s->failed_pc=0x0c03e864u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e866;
P_0c03e866: /* original 243f, guest PC 0x0c03e866 */
if(!s->budget--) { s->failed_pc=0x0c03e866u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c03e868;
P_0c03e868: /* original d209, guest PC 0x0c03e868 */
if(!s->budget--) { s->failed_pc=0x0c03e868u; return 0; }
r[2]=read(ram,0x0c03e890u,4);
goto P_0c03e86a;
P_0c03e86a: /* original f359, guest PC 0x0c03e86a */
if(!s->budget--) { s->failed_pc=0x0c03e86au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03e86c;
P_0c03e86c: /* original 041a, guest PC 0x0c03e86c */
if(!s->budget--) { s->failed_pc=0x0c03e86cu; return 0; }
r[4]=r[19];
goto P_0c03e86e;
P_0c03e86e: /* original 644f, guest PC 0x0c03e86e */
if(!s->budget--) { s->failed_pc=0x0c03e86eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c03e870;
P_0c03e870: /* original 342c, guest PC 0x0c03e870 */
if(!s->budget--) { s->failed_pc=0x0c03e870u; return 0; }
r[4]+=r[2];
goto P_0c03e872;
P_0c03e872: /* original f437, guest PC 0x0c03e872 */
if(!s->budget--) { s->failed_pc=0x0c03e872u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e874;
P_0c03e874: /* original e018, guest PC 0x0c03e874 */
if(!s->budget--) { s->failed_pc=0x0c03e874u; return 0; }
r[0]=0x00000018u;
goto P_0c03e876;
P_0c03e876: /* original f359, guest PC 0x0c03e876 */
if(!s->budget--) { s->failed_pc=0x0c03e876u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03e878;
P_0c03e878: /* original f437, guest PC 0x0c03e878 */
if(!s->budget--) { s->failed_pc=0x0c03e878u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e87a;
P_0c03e87a: /* original e01c, guest PC 0x0c03e87a */
if(!s->budget--) { s->failed_pc=0x0c03e87au; return 0; }
r[0]=0x0000001cu;
goto P_0c03e87c;
P_0c03e87c: /* original f359, guest PC 0x0c03e87c */
if(!s->budget--) { s->failed_pc=0x0c03e87cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03e87e;
P_0c03e87e: /* original f437, guest PC 0x0c03e87e */
if(!s->budget--) { s->failed_pc=0x0c03e87eu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e880;
P_0c03e880: /* original e020, guest PC 0x0c03e880 */
if(!s->budget--) { s->failed_pc=0x0c03e880u; return 0; }
r[0]=0x00000020u;
goto P_0c03e882;
P_0c03e882: /* original f358, guest PC 0x0c03e882 */
if(!s->budget--) { s->failed_pc=0x0c03e882u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c03e884;
P_0c03e884: /* original f437, guest PC 0x0c03e884 */
if(!s->budget--) { s->failed_pc=0x0c03e884u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e886;
P_0c03e886: /* original 000b, guest PC 0x0c03e886 */
if(!s->budget--) { s->failed_pc=0x0c03e886u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c03e888: /* original 4f16, guest PC 0x0c03e888 */
if(!s->budget--) { s->failed_pc=0x0c03e888u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03e88au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e88au; return 0; } return 1;
P_0c03ecb0: /* original 4f22, guest PC 0x0c03ecb0 */
if(!s->budget--) { s->failed_pc=0x0c03ecb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ecb2;
P_0c03ecb2: /* original 7ffc, guest PC 0x0c03ecb2 */
if(!s->budget--) { s->failed_pc=0x0c03ecb2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ecb4;
P_0c03ecb4: /* original 2f42, guest PC 0x0c03ecb4 */
if(!s->budget--) { s->failed_pc=0x0c03ecb4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03ecb6;
P_0c03ecb6: /* original d366, guest PC 0x0c03ecb6 */
if(!s->budget--) { s->failed_pc=0x0c03ecb6u; return 0; }
r[3]=read(ram,0x0c03ee50u,4);
goto P_0c03ecb8;
P_0c03ecb8: /* original f58d, guest PC 0x0c03ecb8 */
if(!s->budget--) { s->failed_pc=0x0c03ecb8u; return 0; }
fr[5]=0;
goto P_0c03ecba;
P_0c03ecba: /* original 430b, guest PC 0x0c03ecba */
if(!s->budget--) { s->failed_pc=0x0c03ecbau; return 0; }
target=r[3];
r[16]=code_base|0x0c03ecbeu;
fr[4]=0;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03ecbeu) { target=s->pc; goto dispatch; }
goto P_0c03ecbe;
P_0c03ecbc: /* original f48d, guest PC 0x0c03ecbc */
if(!s->budget--) { s->failed_pc=0x0c03ecbcu; return 0; }
fr[4]=0;
goto P_0c03ecbe;
P_0c03ecbe: /* original b0bf, guest PC 0x0c03ecbe */
if(!s->budget--) { s->failed_pc=0x0c03ecbeu; return 0; }
target=code_base|0x0c03ee40u; r[16]=code_base|0x0c03ecc2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03ecc2u) { target=s->pc; goto dispatch; }
goto P_0c03ecc2;
P_0c03ecc0: /* original 0009, guest PC 0x0c03ecc0 */
if(!s->budget--) { s->failed_pc=0x0c03ecc0u; return 0; }
goto P_0c03ecc2;
P_0c03ecc2: /* original d364, guest PC 0x0c03ecc2 */
if(!s->budget--) { s->failed_pc=0x0c03ecc2u; return 0; }
r[3]=read(ram,0x0c03ee54u,4);
goto P_0c03ecc4;
P_0c03ecc4: /* original 64f2, guest PC 0x0c03ecc4 */
if(!s->budget--) { s->failed_pc=0x0c03ecc4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03ecc6;
P_0c03ecc6: /* original 7f04, guest PC 0x0c03ecc6 */
if(!s->budget--) { s->failed_pc=0x0c03ecc6u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ecc8;
P_0c03ecc8: /* original 432b, guest PC 0x0c03ecc8 */
if(!s->budget--) { s->failed_pc=0x0c03ecc8u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03ecca: /* original 4f26, guest PC 0x0c03ecca */
if(!s->budget--) { s->failed_pc=0x0c03eccau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03ecccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ecccu; return 0; } return 1;
P_0c03ed50: /* original d33d, guest PC 0x0c03ed50 */
if(!s->budget--) { s->failed_pc=0x0c03ed50u; return 0; }
r[3]=read(ram,0x0c03ee48u,4);
goto P_0c03ed52;
P_0c03ed52: /* original f34a, guest PC 0x0c03ed52 */
if(!s->budget--) { s->failed_pc=0x0c03ed52u; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c03ed54;
P_0c03ed54: /* original d23d, guest PC 0x0c03ed54 */
if(!s->budget--) { s->failed_pc=0x0c03ed54u; return 0; }
r[2]=read(ram,0x0c03ee4cu,4);
goto P_0c03ed56;
P_0c03ed56: /* original 000b, guest PC 0x0c03ed56 */
if(!s->budget--) { s->failed_pc=0x0c03ed56u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[2]);
s->pc=target; return ram->oob==0;
P_0c03ed58: /* original f24a, guest PC 0x0c03ed58 */
if(!s->budget--) { s->failed_pc=0x0c03ed58u; return 0; }
vf3_matrix_store(s,ram,4,r[2]);
if(!vf3_matrix_family(0x0c03ed5au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ed5au; return 0; } return 1;
P_0c03ed60: /* original e004, guest PC 0x0c03ed60 */
if(!s->budget--) { s->failed_pc=0x0c03ed60u; return 0; }
r[0]=0x00000004u;
goto P_0c03ed62;
P_0c03ed62: /* original d540, guest PC 0x0c03ed62 */
if(!s->budget--) { s->failed_pc=0x0c03ed62u; return 0; }
r[5]=read(ram,0x0c03ee64u,4);
goto P_0c03ed64;
P_0c03ed64: /* original f348, guest PC 0x0c03ed64 */
if(!s->budget--) { s->failed_pc=0x0c03ed64u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c03ed66;
P_0c03ed66: /* original f53a, guest PC 0x0c03ed66 */
if(!s->budget--) { s->failed_pc=0x0c03ed66u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c03ed68;
P_0c03ed68: /* original f246, guest PC 0x0c03ed68 */
if(!s->budget--) { s->failed_pc=0x0c03ed68u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c03ed6a;
P_0c03ed6a: /* original f527, guest PC 0x0c03ed6a */
if(!s->budget--) { s->failed_pc=0x0c03ed6au; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c03ed6c;
P_0c03ed6c: /* original e008, guest PC 0x0c03ed6c */
if(!s->budget--) { s->failed_pc=0x0c03ed6cu; return 0; }
r[0]=0x00000008u;
goto P_0c03ed6e;
P_0c03ed6e: /* original f346, guest PC 0x0c03ed6e */
if(!s->budget--) { s->failed_pc=0x0c03ed6eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c03ed70;
P_0c03ed70: /* original f537, guest PC 0x0c03ed70 */
if(!s->budget--) { s->failed_pc=0x0c03ed70u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c03ed72;
P_0c03ed72: /* original f246, guest PC 0x0c03ed72 */
if(!s->budget--) { s->failed_pc=0x0c03ed72u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c03ed74;
P_0c03ed74: /* original e00c, guest PC 0x0c03ed74 */
if(!s->budget--) { s->failed_pc=0x0c03ed74u; return 0; }
r[0]=0x0000000cu;
goto P_0c03ed76;
P_0c03ed76: /* original f39d, guest PC 0x0c03ed76 */
if(!s->budget--) { s->failed_pc=0x0c03ed76u; return 0; }
fr[3]=0x3f800000u;
goto P_0c03ed78;
P_0c03ed78: /* original f230, guest PC 0x0c03ed78 */
if(!s->budget--) { s->failed_pc=0x0c03ed78u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03ed7a;
P_0c03ed7a: /* original 000b, guest PC 0x0c03ed7a */
if(!s->budget--) { s->failed_pc=0x0c03ed7au; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[5]+r[0]);
s->pc=target; return ram->oob==0;
P_0c03ed7c: /* original f527, guest PC 0x0c03ed7c */
if(!s->budget--) { s->failed_pc=0x0c03ed7cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
if(!vf3_matrix_family(0x0c03ed7eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ed7eu; return 0; } return 1;
P_0c03eda0: /* original d431, guest PC 0x0c03eda0 */
if(!s->budget--) { s->failed_pc=0x0c03eda0u; return 0; }
r[4]=read(ram,0x0c03ee68u,4);
goto P_0c03eda2;
P_0c03eda2: /* original e004, guest PC 0x0c03eda2 */
if(!s->budget--) { s->failed_pc=0x0c03eda2u; return 0; }
r[0]=0x00000004u;
goto P_0c03eda4;
P_0c03eda4: /* original f44a, guest PC 0x0c03eda4 */
if(!s->budget--) { s->failed_pc=0x0c03eda4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c03eda6;
P_0c03eda6: /* original f457, guest PC 0x0c03eda6 */
if(!s->budget--) { s->failed_pc=0x0c03eda6u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c03eda8;
P_0c03eda8: /* original e008, guest PC 0x0c03eda8 */
if(!s->budget--) { s->failed_pc=0x0c03eda8u; return 0; }
r[0]=0x00000008u;
goto P_0c03edaa;
P_0c03edaa: /* original 000b, guest PC 0x0c03edaa */
if(!s->budget--) { s->failed_pc=0x0c03edaau; return 0; }
target=r[16];
vf3_matrix_store(s,ram,6,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c03edac: /* original f467, guest PC 0x0c03edac */
if(!s->budget--) { s->failed_pc=0x0c03edacu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
if(!vf3_matrix_family(0x0c03edaeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03edaeu; return 0; } return 1;
P_0c03ee40: /* original d40f, guest PC 0x0c03ee40 */
if(!s->budget--) { s->failed_pc=0x0c03ee40u; return 0; }
r[4]=read(ram,0x0c03ee80u,4);
goto P_0c03ee42;
P_0c03ee42: /* original d508, guest PC 0x0c03ee42 */
if(!s->budget--) { s->failed_pc=0x0c03ee42u; return 0; }
r[5]=read(ram,0x0c03ee64u,4);
goto P_0c03ee44;
P_0c03ee44: /* original a024, guest PC 0x0c03ee44 */
if(!s->budget--) { s->failed_pc=0x0c03ee44u; return 0; }
goto P_0c03ee90;
P_0c03ee46: /* original 0009, guest PC 0x0c03ee46 */
if(!s->budget--) { s->failed_pc=0x0c03ee46u; return 0; }
if(!vf3_matrix_family(0x0c03ee48u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ee48u; return 0; } return 1;
P_0c03ee90: /* original f38d, guest PC 0x0c03ee90 */
if(!s->budget--) { s->failed_pc=0x0c03ee90u; return 0; }
fr[3]=0;
goto P_0c03ee92;
P_0c03ee92: /* original fbfd, guest PC 0x0c03ee92 */
if(!s->budget--) { s->failed_pc=0x0c03ee92u; return 0; }
vf3_matrix_swap(s);
goto P_0c03ee94;
P_0c03ee94: /* original f11d, guest PC 0x0c03ee94 */
if(!s->budget--) { s->failed_pc=0x0c03ee94u; return 0; }
r[53]=fr[1];
goto P_0c03ee96;
P_0c03ee96: /* original f14c, guest PC 0x0c03ee96 */
if(!s->budget--) { s->failed_pc=0x0c03ee96u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03ee98;
P_0c03ee98: /* original f40d, guest PC 0x0c03ee98 */
if(!s->budget--) { s->failed_pc=0x0c03ee98u; return 0; }
fr[4]=r[53];
goto P_0c03ee9a;
P_0c03ee9a: /* original f21d, guest PC 0x0c03ee9a */
if(!s->budget--) { s->failed_pc=0x0c03ee9au; return 0; }
r[53]=fr[2];
goto P_0c03ee9c;
P_0c03ee9c: /* original f28c, guest PC 0x0c03ee9c */
if(!s->budget--) { s->failed_pc=0x0c03ee9cu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03ee9e;
P_0c03ee9e: /* original f80d, guest PC 0x0c03ee9e */
if(!s->budget--) { s->failed_pc=0x0c03ee9eu; return 0; }
fr[8]=r[53];
goto P_0c03eea0;
P_0c03eea0: /* original f61d, guest PC 0x0c03eea0 */
if(!s->budget--) { s->failed_pc=0x0c03eea0u; return 0; }
r[53]=fr[6];
goto P_0c03eea2;
P_0c03eea2: /* original f69c, guest PC 0x0c03eea2 */
if(!s->budget--) { s->failed_pc=0x0c03eea2u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03eea4;
P_0c03eea4: /* original f90d, guest PC 0x0c03eea4 */
if(!s->budget--) { s->failed_pc=0x0c03eea4u; return 0; }
fr[9]=r[53];
goto P_0c03eea6;
P_0c03eea6: /* original fbfd, guest PC 0x0c03eea6 */
if(!s->budget--) { s->failed_pc=0x0c03eea6u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eea8;
P_0c03eea8: /* original f059, guest PC 0x0c03eea8 */
if(!s->budget--) { s->failed_pc=0x0c03eea8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeaa;
P_0c03eeaa: /* original f159, guest PC 0x0c03eeaa */
if(!s->budget--) { s->failed_pc=0x0c03eeaau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeac;
P_0c03eeac: /* original f259, guest PC 0x0c03eeac */
if(!s->budget--) { s->failed_pc=0x0c03eeacu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeae;
P_0c03eeae: /* original f658, guest PC 0x0c03eeae */
if(!s->budget--) { s->failed_pc=0x0c03eeaeu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
goto P_0c03eeb0;
P_0c03eeb0: /* original 75f4, guest PC 0x0c03eeb0 */
if(!s->budget--) { s->failed_pc=0x0c03eeb0u; return 0; }
r[5]+=0xfffffff4u;
goto P_0c03eeb2;
P_0c03eeb2: /* original f459, guest PC 0x0c03eeb2 */
if(!s->budget--) { s->failed_pc=0x0c03eeb2u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeb4;
P_0c03eeb4: /* original f78d, guest PC 0x0c03eeb4 */
if(!s->budget--) { s->failed_pc=0x0c03eeb4u; return 0; }
fr[7]=0;
goto P_0c03eeb6;
P_0c03eeb6: /* original f1fd, guest PC 0x0c03eeb6 */
if(!s->budget--) { s->failed_pc=0x0c03eeb6u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03eeb8;
P_0c03eeb8: /* original f559, guest PC 0x0c03eeb8 */
if(!s->budget--) { s->failed_pc=0x0c03eeb8u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeba;
P_0c03eeba: /* original e010, guest PC 0x0c03eeba */
if(!s->budget--) { s->failed_pc=0x0c03eebau; return 0; }
r[0]=0x00000010u;
goto P_0c03eebc;
P_0c03eebc: /* original f5fd, guest PC 0x0c03eebc */
if(!s->budget--) { s->failed_pc=0x0c03eebcu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03eebe;
P_0c03eebe: /* original f407, guest PC 0x0c03eebe */
if(!s->budget--) { s->failed_pc=0x0c03eebeu; return 0; }
vf3_matrix_store(s,ram,0,r[4]+r[0]);
goto P_0c03eec0;
P_0c03eec0: /* original e014, guest PC 0x0c03eec0 */
if(!s->budget--) { s->failed_pc=0x0c03eec0u; return 0; }
r[0]=0x00000014u;
goto P_0c03eec2;
P_0c03eec2: /* original f417, guest PC 0x0c03eec2 */
if(!s->budget--) { s->failed_pc=0x0c03eec2u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c03eec4;
P_0c03eec4: /* original e018, guest PC 0x0c03eec4 */
if(!s->budget--) { s->failed_pc=0x0c03eec4u; return 0; }
r[0]=0x00000018u;
goto P_0c03eec6;
P_0c03eec6: /* original f427, guest PC 0x0c03eec6 */
if(!s->budget--) { s->failed_pc=0x0c03eec6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03eec8;
P_0c03eec8: /* original fbfd, guest PC 0x0c03eec8 */
if(!s->budget--) { s->failed_pc=0x0c03eec8u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eeca;
P_0c03eeca: /* original f11d, guest PC 0x0c03eeca */
if(!s->budget--) { s->failed_pc=0x0c03eecau; return 0; }
r[53]=fr[1];
goto P_0c03eecc;
P_0c03eecc: /* original f14c, guest PC 0x0c03eecc */
if(!s->budget--) { s->failed_pc=0x0c03eeccu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03eece;
P_0c03eece: /* original f40d, guest PC 0x0c03eece */
if(!s->budget--) { s->failed_pc=0x0c03eeceu; return 0; }
fr[4]=r[53];
goto P_0c03eed0;
P_0c03eed0: /* original fbfd, guest PC 0x0c03eed0 */
if(!s->budget--) { s->failed_pc=0x0c03eed0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eed2;
P_0c03eed2: /* original f78d, guest PC 0x0c03eed2 */
if(!s->budget--) { s->failed_pc=0x0c03eed2u; return 0; }
fr[7]=0;
goto P_0c03eed4;
P_0c03eed4: /* original f5ed, guest PC 0x0c03eed4 */
if(!s->budget--) { s->failed_pc=0x0c03eed4u; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03eed6;
P_0c03eed6: /* original fbfd, guest PC 0x0c03eed6 */
if(!s->budget--) { s->failed_pc=0x0c03eed6u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eed8;
P_0c03eed8: /* original f21d, guest PC 0x0c03eed8 */
if(!s->budget--) { s->failed_pc=0x0c03eed8u; return 0; }
r[53]=fr[2];
goto P_0c03eeda;
P_0c03eeda: /* original f28c, guest PC 0x0c03eeda */
if(!s->budget--) { s->failed_pc=0x0c03eedau; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03eedc;
P_0c03eedc: /* original f80d, guest PC 0x0c03eedc */
if(!s->budget--) { s->failed_pc=0x0c03eedcu; return 0; }
fr[8]=r[53];
goto P_0c03eede;
P_0c03eede: /* original fbfd, guest PC 0x0c03eede */
if(!s->budget--) { s->failed_pc=0x0c03eedeu; return 0; }
vf3_matrix_swap(s);
goto P_0c03eee0;
P_0c03eee0: /* original f77d, guest PC 0x0c03eee0 */
if(!s->budget--) { s->failed_pc=0x0c03eee0u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03eee2;
P_0c03eee2: /* original fbfd, guest PC 0x0c03eee2 */
if(!s->budget--) { s->failed_pc=0x0c03eee2u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eee4;
P_0c03eee4: /* original f61d, guest PC 0x0c03eee4 */
if(!s->budget--) { s->failed_pc=0x0c03eee4u; return 0; }
r[53]=fr[6];
goto P_0c03eee6;
P_0c03eee6: /* original f69c, guest PC 0x0c03eee6 */
if(!s->budget--) { s->failed_pc=0x0c03eee6u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03eee8;
P_0c03eee8: /* original f90d, guest PC 0x0c03eee8 */
if(!s->budget--) { s->failed_pc=0x0c03eee8u; return 0; }
fr[9]=r[53];
goto P_0c03eeea;
P_0c03eeea: /* original fbfd, guest PC 0x0c03eeea */
if(!s->budget--) { s->failed_pc=0x0c03eeeau; return 0; }
vf3_matrix_swap(s);
goto P_0c03eeec;
P_0c03eeec: /* original f472, guest PC 0x0c03eeec */
if(!s->budget--) { s->failed_pc=0x0c03eeecu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03eeee;
P_0c03eeee: /* original f572, guest PC 0x0c03eeee */
if(!s->budget--) { s->failed_pc=0x0c03eeeeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03eef0;
P_0c03eef0: /* original f672, guest PC 0x0c03eef0 */
if(!s->budget--) { s->failed_pc=0x0c03eef0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03eef2;
P_0c03eef2: /* original e000, guest PC 0x0c03eef2 */
if(!s->budget--) { s->failed_pc=0x0c03eef2u; return 0; }
r[0]=0x00000000u;
goto P_0c03eef4;
P_0c03eef4: /* original f447, guest PC 0x0c03eef4 */
if(!s->budget--) { s->failed_pc=0x0c03eef4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03eef6;
P_0c03eef6: /* original e004, guest PC 0x0c03eef6 */
if(!s->budget--) { s->failed_pc=0x0c03eef6u; return 0; }
r[0]=0x00000004u;
goto P_0c03eef8;
P_0c03eef8: /* original f457, guest PC 0x0c03eef8 */
if(!s->budget--) { s->failed_pc=0x0c03eef8u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c03eefa;
P_0c03eefa: /* original e008, guest PC 0x0c03eefa */
if(!s->budget--) { s->failed_pc=0x0c03eefau; return 0; }
r[0]=0x00000008u;
goto P_0c03eefc;
P_0c03eefc: /* original f467, guest PC 0x0c03eefc */
if(!s->budget--) { s->failed_pc=0x0c03eefcu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c03eefe;
P_0c03eefe: /* original 0009, guest PC 0x0c03eefe */
if(!s->budget--) { s->failed_pc=0x0c03eefeu; return 0; }
goto P_0c03ef00;
P_0c03ef00: /* original 000b, guest PC 0x0c03ef00 */
if(!s->budget--) { s->failed_pc=0x0c03ef00u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03ef02: /* original 0009, guest PC 0x0c03ef02 */
if(!s->budget--) { s->failed_pc=0x0c03ef02u; return 0; }
if(!vf3_matrix_family(0x0c03ef04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ef04u; return 0; } return 1;
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
if(!vf3_matrix_family(0x0c040f68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040f68u; return 0; } return 1;
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
