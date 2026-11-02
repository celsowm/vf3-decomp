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
int vf3_away_batch48_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c1fbau: goto P_0c0c1fba;
case 0x0c0c1fbcu: goto P_0c0c1fbc;
case 0x0c0c1fbeu: goto P_0c0c1fbe;
case 0x0c0c1fc0u: goto P_0c0c1fc0;
case 0x0c0c1fc2u: goto P_0c0c1fc2;
case 0x0c0c1fc4u: goto P_0c0c1fc4;
case 0x0c0c1fc6u: goto P_0c0c1fc6;
case 0x0c0c1fc8u: goto P_0c0c1fc8;
case 0x0c0c1fcau: goto P_0c0c1fca;
case 0x0c0c1fccu: goto P_0c0c1fcc;
case 0x0c0c1fceu: goto P_0c0c1fce;
case 0x0c0c1fd0u: goto P_0c0c1fd0;
case 0x0c0c1fd2u: goto P_0c0c1fd2;
case 0x0c0c1fd4u: goto P_0c0c1fd4;
case 0x0c0c1fd6u: goto P_0c0c1fd6;
case 0x0c0c1fd8u: goto P_0c0c1fd8;
case 0x0c0c1fdau: goto P_0c0c1fda;
case 0x0c0c1fdcu: goto P_0c0c1fdc;
case 0x0c0c1fdeu: goto P_0c0c1fde;
case 0x0c0c1fe0u: goto P_0c0c1fe0;
case 0x0c0c1fe2u: goto P_0c0c1fe2;
case 0x0c0c1fe4u: goto P_0c0c1fe4;
case 0x0c0c1fe6u: goto P_0c0c1fe6;
case 0x0c0c1fe8u: goto P_0c0c1fe8;
case 0x0c0c1feau: goto P_0c0c1fea;
case 0x0c0c1fecu: goto P_0c0c1fec;
case 0x0c0c1feeu: goto P_0c0c1fee;
case 0x0c0c1ff0u: goto P_0c0c1ff0;
case 0x0c0c1ff2u: goto P_0c0c1ff2;
case 0x0c0c1ff4u: goto P_0c0c1ff4;
case 0x0c0c1ff6u: goto P_0c0c1ff6;
case 0x0c0c1ff8u: goto P_0c0c1ff8;
case 0x0c0c1ffau: goto P_0c0c1ffa;
case 0x0c0c1ffcu: goto P_0c0c1ffc;
case 0x0c0c1ffeu: goto P_0c0c1ffe;
case 0x0c0c2000u: goto P_0c0c2000;
case 0x0c0c2002u: goto P_0c0c2002;
case 0x0c0c2004u: goto P_0c0c2004;
case 0x0c0c2006u: goto P_0c0c2006;
case 0x0c0c2008u: goto P_0c0c2008;
case 0x0c0c200au: goto P_0c0c200a;
case 0x0c0c200cu: goto P_0c0c200c;
case 0x0c0c200eu: goto P_0c0c200e;
case 0x0c0c2010u: goto P_0c0c2010;
case 0x0c0c2012u: goto P_0c0c2012;
case 0x0c0c2014u: goto P_0c0c2014;
case 0x0c0c2016u: goto P_0c0c2016;
case 0x0c0c2018u: goto P_0c0c2018;
case 0x0c0c201au: goto P_0c0c201a;
case 0x0c0c201cu: goto P_0c0c201c;
case 0x0c0c201eu: goto P_0c0c201e;
case 0x0c0c2020u: goto P_0c0c2020;
case 0x0c0c2022u: goto P_0c0c2022;
case 0x0c0c2024u: goto P_0c0c2024;
case 0x0c0c2026u: goto P_0c0c2026;
case 0x0c0c2028u: goto P_0c0c2028;
case 0x0c0c202au: goto P_0c0c202a;
case 0x0c0c202cu: goto P_0c0c202c;
case 0x0c0c202eu: goto P_0c0c202e;
case 0x0c0c2030u: goto P_0c0c2030;
case 0x0c0c2032u: goto P_0c0c2032;
case 0x0c0c2034u: goto P_0c0c2034;
case 0x0c0c2036u: goto P_0c0c2036;
case 0x0c0c2038u: goto P_0c0c2038;
case 0x0c0c203au: goto P_0c0c203a;
case 0x0c0c203cu: goto P_0c0c203c;
case 0x0c0c203eu: goto P_0c0c203e;
case 0x0c0c2040u: goto P_0c0c2040;
case 0x0c0c2042u: goto P_0c0c2042;
case 0x0c0c2044u: goto P_0c0c2044;
case 0x0c0c2046u: goto P_0c0c2046;
case 0x0c0c2048u: goto P_0c0c2048;
case 0x0c0c204au: goto P_0c0c204a;
case 0x0c0c204cu: goto P_0c0c204c;
case 0x0c0c204eu: goto P_0c0c204e;
case 0x0c0c2050u: goto P_0c0c2050;
case 0x0c0c2052u: goto P_0c0c2052;
case 0x0c0c2054u: goto P_0c0c2054;
case 0x0c0c2056u: goto P_0c0c2056;
case 0x0c0c2058u: goto P_0c0c2058;
case 0x0c0c205au: goto P_0c0c205a;
case 0x0c0c205cu: goto P_0c0c205c;
case 0x0c0c205eu: goto P_0c0c205e;
case 0x0c0c2060u: goto P_0c0c2060;
case 0x0c0c2062u: goto P_0c0c2062;
case 0x0c0c2064u: goto P_0c0c2064;
case 0x0c0c2066u: goto P_0c0c2066;
case 0x0c0c2068u: goto P_0c0c2068;
case 0x0c0c206au: goto P_0c0c206a;
case 0x0c0c206cu: goto P_0c0c206c;
case 0x0c0c206eu: goto P_0c0c206e;
case 0x0c0c2070u: goto P_0c0c2070;
case 0x0c0c2072u: goto P_0c0c2072;
case 0x0c0c2074u: goto P_0c0c2074;
case 0x0c0c2076u: goto P_0c0c2076;
case 0x0c0c2078u: goto P_0c0c2078;
case 0x0c0c207au: goto P_0c0c207a;
case 0x0c0c207cu: goto P_0c0c207c;
case 0x0c0c207eu: goto P_0c0c207e;
case 0x0c0c2080u: goto P_0c0c2080;
case 0x0c0c2082u: goto P_0c0c2082;
case 0x0c0c2084u: goto P_0c0c2084;
case 0x0c0c2086u: goto P_0c0c2086;
case 0x0c0c2088u: goto P_0c0c2088;
case 0x0c0c208au: goto P_0c0c208a;
case 0x0c0c208cu: goto P_0c0c208c;
case 0x0c0c208eu: goto P_0c0c208e;
case 0x0c0c2090u: goto P_0c0c2090;
case 0x0c0c2092u: goto P_0c0c2092;
case 0x0c0c2094u: goto P_0c0c2094;
case 0x0c0c2096u: goto P_0c0c2096;
case 0x0c0c2098u: goto P_0c0c2098;
case 0x0c0c209au: goto P_0c0c209a;
case 0x0c0c209cu: goto P_0c0c209c;
case 0x0c0c209eu: goto P_0c0c209e;
case 0x0c0c20a0u: goto P_0c0c20a0;
case 0x0c0c20a2u: goto P_0c0c20a2;
case 0x0c0c20a4u: goto P_0c0c20a4;
case 0x0c0c20a6u: goto P_0c0c20a6;
case 0x0c0c20a8u: goto P_0c0c20a8;
case 0x0c0c20aau: goto P_0c0c20aa;
case 0x0c0c20acu: goto P_0c0c20ac;
case 0x0c0c20aeu: goto P_0c0c20ae;
case 0x0c0c20b0u: goto P_0c0c20b0;
case 0x0c0c20b2u: goto P_0c0c20b2;
case 0x0c0c20b4u: goto P_0c0c20b4;
case 0x0c0c20b6u: goto P_0c0c20b6;
case 0x0c0c20b8u: goto P_0c0c20b8;
case 0x0c0c20bau: goto P_0c0c20ba;
case 0x0c0c20bcu: goto P_0c0c20bc;
case 0x0c0c20beu: goto P_0c0c20be;
case 0x0c0c20c0u: goto P_0c0c20c0;
case 0x0c0c20c2u: goto P_0c0c20c2;
case 0x0c0c20c4u: goto P_0c0c20c4;
case 0x0c0c20c6u: goto P_0c0c20c6;
case 0x0c0c20c8u: goto P_0c0c20c8;
case 0x0c0c20cau: goto P_0c0c20ca;
case 0x0c0c20ccu: goto P_0c0c20cc;
case 0x0c0c20ceu: goto P_0c0c20ce;
case 0x0c0c20d0u: goto P_0c0c20d0;
case 0x0c0c20d2u: goto P_0c0c20d2;
case 0x0c0c20d4u: goto P_0c0c20d4;
case 0x0c0c20d6u: goto P_0c0c20d6;
case 0x0c0c20d8u: goto P_0c0c20d8;
case 0x0c0c20dau: goto P_0c0c20da;
case 0x0c0c20dcu: goto P_0c0c20dc;
case 0x0c0c20deu: goto P_0c0c20de;
case 0x0c0c20e0u: goto P_0c0c20e0;
case 0x0c0c20e2u: goto P_0c0c20e2;
case 0x0c0c20e4u: goto P_0c0c20e4;
case 0x0c0c20e6u: goto P_0c0c20e6;
case 0x0c0c20e8u: goto P_0c0c20e8;
case 0x0c0c20eau: goto P_0c0c20ea;
case 0x0c0c20ecu: goto P_0c0c20ec;
case 0x0c0c20eeu: goto P_0c0c20ee;
case 0x0c0c20f0u: goto P_0c0c20f0;
case 0x0c0c20f2u: goto P_0c0c20f2;
case 0x0c0c20f4u: goto P_0c0c20f4;
case 0x0c0c20f6u: goto P_0c0c20f6;
case 0x0c0c20f8u: goto P_0c0c20f8;
case 0x0c0c20fau: goto P_0c0c20fa;
case 0x0c0c20fcu: goto P_0c0c20fc;
case 0x0c0c20feu: goto P_0c0c20fe;
case 0x0c0c2100u: goto P_0c0c2100;
case 0x0c0c2102u: goto P_0c0c2102;
case 0x0c0c2104u: goto P_0c0c2104;
case 0x0c0c2106u: goto P_0c0c2106;
case 0x0c0c2108u: goto P_0c0c2108;
case 0x0c0c210au: goto P_0c0c210a;
case 0x0c0c210cu: goto P_0c0c210c;
case 0x0c0c210eu: goto P_0c0c210e;
case 0x0c0c2110u: goto P_0c0c2110;
case 0x0c0c2112u: goto P_0c0c2112;
case 0x0c0c2114u: goto P_0c0c2114;
case 0x0c0c2116u: goto P_0c0c2116;
case 0x0c0c2118u: goto P_0c0c2118;
case 0x0c0c211au: goto P_0c0c211a;
case 0x0c0c211cu: goto P_0c0c211c;
case 0x0c0c211eu: goto P_0c0c211e;
case 0x0c0c2120u: goto P_0c0c2120;
case 0x0c0c2122u: goto P_0c0c2122;
case 0x0c0c2124u: goto P_0c0c2124;
case 0x0c0c2126u: goto P_0c0c2126;
case 0x0c0c2128u: goto P_0c0c2128;
case 0x0c0c212au: goto P_0c0c212a;
case 0x0c0c212cu: goto P_0c0c212c;
case 0x0c0c212eu: goto P_0c0c212e;
case 0x0c0c2130u: goto P_0c0c2130;
case 0x0c0c2132u: goto P_0c0c2132;
case 0x0c0c2134u: goto P_0c0c2134;
case 0x0c0c2136u: goto P_0c0c2136;
case 0x0c0c2138u: goto P_0c0c2138;
case 0x0c0c213au: goto P_0c0c213a;
case 0x0c0c213cu: goto P_0c0c213c;
case 0x0c0c213eu: goto P_0c0c213e;
case 0x0c0c2140u: goto P_0c0c2140;
case 0x0c0c2142u: goto P_0c0c2142;
case 0x0c0c2144u: goto P_0c0c2144;
case 0x0c0c2146u: goto P_0c0c2146;
case 0x0c0c2148u: goto P_0c0c2148;
case 0x0c0c214au: goto P_0c0c214a;
case 0x0c0c214cu: goto P_0c0c214c;
case 0x0c0c214eu: goto P_0c0c214e;
case 0x0c0c2150u: goto P_0c0c2150;
case 0x0c0c2152u: goto P_0c0c2152;
case 0x0c0c2154u: goto P_0c0c2154;
case 0x0c0c2156u: goto P_0c0c2156;
case 0x0c0c2158u: goto P_0c0c2158;
case 0x0c0c215au: goto P_0c0c215a;
case 0x0c0c215cu: goto P_0c0c215c;
case 0x0c0c215eu: goto P_0c0c215e;
case 0x0c0c2160u: goto P_0c0c2160;
case 0x0c0c2162u: goto P_0c0c2162;
case 0x0c0c2164u: goto P_0c0c2164;
case 0x0c0c2166u: goto P_0c0c2166;
case 0x0c0c2168u: goto P_0c0c2168;
case 0x0c0c216au: goto P_0c0c216a;
case 0x0c0c216cu: goto P_0c0c216c;
case 0x0c0c216eu: goto P_0c0c216e;
case 0x0c0c2170u: goto P_0c0c2170;
case 0x0c0c2172u: goto P_0c0c2172;
case 0x0c0c2184u: goto P_0c0c2184;
case 0x0c0c2186u: goto P_0c0c2186;
case 0x0c0c2188u: goto P_0c0c2188;
case 0x0c0c218au: goto P_0c0c218a;
case 0x0c0c218cu: goto P_0c0c218c;
case 0x0c0c218eu: goto P_0c0c218e;
case 0x0c0c2190u: goto P_0c0c2190;
case 0x0c0c2192u: goto P_0c0c2192;
case 0x0c0c2194u: goto P_0c0c2194;
case 0x0c0c2196u: goto P_0c0c2196;
case 0x0c0c2198u: goto P_0c0c2198;
case 0x0c0c219au: goto P_0c0c219a;
case 0x0c0c219cu: goto P_0c0c219c;
case 0x0c0c219eu: goto P_0c0c219e;
case 0x0c0c21a0u: goto P_0c0c21a0;
case 0x0c0c21a2u: goto P_0c0c21a2;
case 0x0c0c21a4u: goto P_0c0c21a4;
case 0x0c0c21a6u: goto P_0c0c21a6;
case 0x0c0c21a8u: goto P_0c0c21a8;
case 0x0c0c21aau: goto P_0c0c21aa;
case 0x0c0c21acu: goto P_0c0c21ac;
case 0x0c0c21aeu: goto P_0c0c21ae;
case 0x0c0c21b0u: goto P_0c0c21b0;
case 0x0c0c21b2u: goto P_0c0c21b2;
case 0x0c0c21b4u: goto P_0c0c21b4;
case 0x0c0c21b6u: goto P_0c0c21b6;
case 0x0c0c21b8u: goto P_0c0c21b8;
case 0x0c0c21bau: goto P_0c0c21ba;
case 0x0c0c21bcu: goto P_0c0c21bc;
case 0x0c0c21beu: goto P_0c0c21be;
case 0x0c0c21c0u: goto P_0c0c21c0;
case 0x0c0c21c2u: goto P_0c0c21c2;
case 0x0c0c21c4u: goto P_0c0c21c4;
case 0x0c0c21c6u: goto P_0c0c21c6;
case 0x0c0c21c8u: goto P_0c0c21c8;
case 0x0c0c21cau: goto P_0c0c21ca;
case 0x0c0c21ccu: goto P_0c0c21cc;
case 0x0c0c21ceu: goto P_0c0c21ce;
case 0x0c0c21d0u: goto P_0c0c21d0;
case 0x0c0c21d2u: goto P_0c0c21d2;
case 0x0c0c21d4u: goto P_0c0c21d4;
case 0x0c0c21d6u: goto P_0c0c21d6;
case 0x0c0c21d8u: goto P_0c0c21d8;
case 0x0c0c21dau: goto P_0c0c21da;
case 0x0c0c21dcu: goto P_0c0c21dc;
case 0x0c0c21deu: goto P_0c0c21de;
case 0x0c0c21e0u: goto P_0c0c21e0;
case 0x0c0c21e2u: goto P_0c0c21e2;
case 0x0c0c21e4u: goto P_0c0c21e4;
case 0x0c0c21e6u: goto P_0c0c21e6;
case 0x0c0c21e8u: goto P_0c0c21e8;
case 0x0c0c21eau: goto P_0c0c21ea;
case 0x0c0c21ecu: goto P_0c0c21ec;
case 0x0c0c21eeu: goto P_0c0c21ee;
case 0x0c0c21f0u: goto P_0c0c21f0;
case 0x0c0c21f2u: goto P_0c0c21f2;
case 0x0c0c21f4u: goto P_0c0c21f4;
case 0x0c0c21f6u: goto P_0c0c21f6;
case 0x0c0c21f8u: goto P_0c0c21f8;
case 0x0c0c21fau: goto P_0c0c21fa;
case 0x0c0c21fcu: goto P_0c0c21fc;
case 0x0c0c21feu: goto P_0c0c21fe;
case 0x0c0c2200u: goto P_0c0c2200;
case 0x0c0c2202u: goto P_0c0c2202;
case 0x0c0c2204u: goto P_0c0c2204;
case 0x0c0c2206u: goto P_0c0c2206;
case 0x0c0c2208u: goto P_0c0c2208;
case 0x0c0c220au: goto P_0c0c220a;
case 0x0c0c220cu: goto P_0c0c220c;
case 0x0c0c220eu: goto P_0c0c220e;
case 0x0c0c2210u: goto P_0c0c2210;
case 0x0c0c2212u: goto P_0c0c2212;
case 0x0c0c2214u: goto P_0c0c2214;
case 0x0c0c2216u: goto P_0c0c2216;
case 0x0c0c2218u: goto P_0c0c2218;
case 0x0c0c221au: goto P_0c0c221a;
case 0x0c0c221cu: goto P_0c0c221c;
case 0x0c0c221eu: goto P_0c0c221e;
case 0x0c0c2220u: goto P_0c0c2220;
case 0x0c0c2222u: goto P_0c0c2222;
case 0x0c0c2224u: goto P_0c0c2224;
case 0x0c0c2226u: goto P_0c0c2226;
case 0x0c0c2228u: goto P_0c0c2228;
case 0x0c0c222au: goto P_0c0c222a;
case 0x0c0c222cu: goto P_0c0c222c;
case 0x0c0c222eu: goto P_0c0c222e;
case 0x0c0c2230u: goto P_0c0c2230;
case 0x0c0c2232u: goto P_0c0c2232;
case 0x0c0c2234u: goto P_0c0c2234;
case 0x0c0c2236u: goto P_0c0c2236;
case 0x0c0c2238u: goto P_0c0c2238;
case 0x0c0c223au: goto P_0c0c223a;
case 0x0c0c223cu: goto P_0c0c223c;
case 0x0c0c223eu: goto P_0c0c223e;
case 0x0c0c2240u: goto P_0c0c2240;
case 0x0c0c2242u: goto P_0c0c2242;
case 0x0c0c2244u: goto P_0c0c2244;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c1fba: /* original 2fe6, guest PC 0x0c0c1fba */
if(!s->budget--) { s->failed_pc=0x0c0c1fbau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1fbc;
P_0c0c1fbc: /* original e044, guest PC 0x0c0c1fbc */
if(!s->budget--) { s->failed_pc=0x0c0c1fbcu; return 0; }
r[0]=0x00000044u;
goto P_0c0c1fbe;
P_0c0c1fbe: /* original 2fd6, guest PC 0x0c0c1fbe */
if(!s->budget--) { s->failed_pc=0x0c0c1fbeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1fc0;
P_0c0c1fc0: /* original 2fc6, guest PC 0x0c0c1fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1fc2;
P_0c0c1fc2: /* original 6c53, guest PC 0x0c0c1fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc2u; return 0; }
r[12]=r[5];
goto P_0c0c1fc4;
P_0c0c1fc4: /* original 2fb6, guest PC 0x0c0c1fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1fc6;
P_0c0c1fc6: /* original 2fa6, guest PC 0x0c0c1fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1fc8;
P_0c0c1fc8: /* original 6a63, guest PC 0x0c0c1fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c1fc8u; return 0; }
r[10]=r[6];
goto P_0c0c1fca;
P_0c0c1fca: /* original 2f96, guest PC 0x0c0c1fca */
if(!s->budget--) { s->failed_pc=0x0c0c1fcau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1fcc;
P_0c0c1fcc: /* original 6943, guest PC 0x0c0c1fcc */
if(!s->budget--) { s->failed_pc=0x0c0c1fccu; return 0; }
r[9]=r[4];
goto P_0c0c1fce;
P_0c0c1fce: /* original 2f86, guest PC 0x0c0c1fce */
if(!s->budget--) { s->failed_pc=0x0c0c1fceu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1fd0;
P_0c0c1fd0: /* original fffb, guest PC 0x0c0c1fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c1fd2;
P_0c0c1fd2: /* original ffeb, guest PC 0x0c0c1fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c1fd4;
P_0c0c1fd4: /* original ffdb, guest PC 0x0c0c1fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c1fd6;
P_0c0c1fd6: /* original ffcb, guest PC 0x0c0c1fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0c1fd8;
P_0c0c1fd8: /* original 4f22, guest PC 0x0c0c1fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c1fd8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1fda;
P_0c0c1fda: /* original 7fec, guest PC 0x0c0c1fda */
if(!s->budget--) { s->failed_pc=0x0c0c1fdau; return 0; }
r[15]+=0xffffffecu;
goto P_0c0c1fdc;
P_0c0c1fdc: /* original 2f72, guest PC 0x0c0c1fdc */
if(!s->budget--) { s->failed_pc=0x0c0c1fdcu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0c1fde;
P_0c0c1fde: /* original 0bfe, guest PC 0x0c0c1fde */
if(!s->budget--) { s->failed_pc=0x0c0c1fdeu; return 0; }
r[11]=read(ram,r[15]+r[0],4);
goto P_0c0c1fe0;
P_0c0c1fe0: /* original e048, guest PC 0x0c0c1fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe0u; return 0; }
r[0]=0x00000048u;
goto P_0c0c1fe2;
P_0c0c1fe2: /* original d364, guest PC 0x0c0c1fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe2u; return 0; }
r[3]=read(ram,0x0c0c2174u,4);
goto P_0c0c1fe4;
P_0c0c1fe4: /* original 54a3, guest PC 0x0c0c1fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe4u; return 0; }
r[4]=read(ram,r[10]+12,4);
goto P_0c0c1fe6;
P_0c0c1fe6: /* original 0dfe, guest PC 0x0c0c1fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe6u; return 0; }
r[13]=read(ram,r[15]+r[0],4);
goto P_0c0c1fe8;
P_0c0c1fe8: /* original 23c8, guest PC 0x0c0c1fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c1fe8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0c1fea;
P_0c0c1fea: /* original 8d20, guest PC 0x0c0c1fea */
if(!s->budget--) { s->failed_pc=0x0c0c1feau; return 0; }
cond=r[17]&1u;
r[8]=0x0000003fu;
if(cond) { goto P_0c0c202e; }
goto P_0c0c1fee;
P_0c0c1fec: /* original e83f, guest PC 0x0c0c1fec */
if(!s->budget--) { s->failed_pc=0x0c0c1fecu; return 0; }
r[8]=0x0000003fu;
goto P_0c0c1fee;
P_0c0c1fee: /* original e3f9, guest PC 0x0c0c1fee */
if(!s->budget--) { s->failed_pc=0x0c0c1feeu; return 0; }
r[3]=0xfffffff9u;
goto P_0c0c1ff0;
P_0c0c1ff0: /* original 6d93, guest PC 0x0c0c1ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff0u; return 0; }
r[13]=r[9];
goto P_0c0c1ff2;
P_0c0c1ff2: /* original 493d, guest PC 0x0c0c1ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff2u; return 0; }
r[9]=(r[3]&0x80000000u)?((r[3]&31u)?r[9]>>((-r[3])&31u):0):r[9]<<(r[3]&31u);
goto P_0c0c1ff4;
P_0c0c1ff4: /* original d25f, guest PC 0x0c0c1ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff4u; return 0; }
r[2]=read(ram,0x0c0c2174u,4);
goto P_0c0c1ff6;
P_0c0c1ff6: /* original e500, guest PC 0x0c0c1ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff6u; return 0; }
r[5]=0x00000000u;
goto P_0c0c1ff8;
P_0c0c1ff8: /* original 6e93, guest PC 0x0c0c1ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ff8u; return 0; }
r[14]=r[9];
goto P_0c0c1ffa;
P_0c0c1ffa: /* original 4d01, guest PC 0x0c0c1ffa */
if(!s->budget--) { s->failed_pc=0x0c0c1ffau; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]>>=1;
goto P_0c0c1ffc;
P_0c0c1ffc: /* original 6653, guest PC 0x0c0c1ffc */
if(!s->budget--) { s->failed_pc=0x0c0c1ffcu; return 0; }
r[6]=r[5];
goto P_0c0c1ffe;
P_0c0c1ffe: /* original 2c2a, guest PC 0x0c0c1ffe */
if(!s->budget--) { s->failed_pc=0x0c0c1ffeu; return 0; }
r[12]^=r[2];
goto P_0c0c2000;
P_0c0c2000: /* original 2e89, guest PC 0x0c0c2000 */
if(!s->budget--) { s->failed_pc=0x0c0c2000u; return 0; }
r[14]&=r[8];
goto P_0c0c2002;
P_0c0c2002: /* original 2d89, guest PC 0x0c0c2002 */
if(!s->budget--) { s->failed_pc=0x0c0c2002u; return 0; }
r[13]&=r[8];
goto P_0c0c2004;
P_0c0c2004: /* original a00f, guest PC 0x0c0c2004 */
if(!s->budget--) { s->failed_pc=0x0c0c2004u; return 0; }
r[7]=0x00000078u;
goto P_0c0c2026;
P_0c0c2006: /* original e778, guest PC 0x0c0c2006 */
if(!s->budget--) { s->failed_pc=0x0c0c2006u; return 0; }
r[7]=0x00000078u;
goto P_0c0c2008;
P_0c0c2008: /* original 8543, guest PC 0x0c0c2008 */
if(!s->budget--) { s->failed_pc=0x0c0c2008u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c0c200a;
P_0c0c200a: /* original 600d, guest PC 0x0c0c200a */
if(!s->budget--) { s->failed_pc=0x0c0c200au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c200c;
P_0c0c200c: /* original 30d0, guest PC 0x0c0c200c */
if(!s->budget--) { s->failed_pc=0x0c0c200cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c0c200e;
P_0c0c200e: /* original 8b08, guest PC 0x0c0c200e */
if(!s->budget--) { s->failed_pc=0x0c0c200eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2022; }
goto P_0c0c2010;
P_0c0c2010: /* original 8544, guest PC 0x0c0c2010 */
if(!s->budget--) { s->failed_pc=0x0c0c2010u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+8,2);
goto P_0c0c2012;
P_0c0c2012: /* original 600d, guest PC 0x0c0c2012 */
if(!s->budget--) { s->failed_pc=0x0c0c2012u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c2014;
P_0c0c2014: /* original 30e0, guest PC 0x0c0c2014 */
if(!s->budget--) { s->failed_pc=0x0c0c2014u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[14])!=0);
goto P_0c0c2016;
P_0c0c2016: /* original 8b04, guest PC 0x0c0c2016 */
if(!s->budget--) { s->failed_pc=0x0c0c2016u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2022; }
goto P_0c0c2018;
P_0c0c2018: /* original 8541, guest PC 0x0c0c2018 */
if(!s->budget--) { s->failed_pc=0x0c0c2018u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c0c201a;
P_0c0c201a: /* original 600d, guest PC 0x0c0c201a */
if(!s->budget--) { s->failed_pc=0x0c0c201au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c201c;
P_0c0c201c: /* original 30c0, guest PC 0x0c0c201c */
if(!s->budget--) { s->failed_pc=0x0c0c201cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[12])!=0);
goto P_0c0c201e;
P_0c0c201e: /* original 8b00, guest PC 0x0c0c201e */
if(!s->budget--) { s->failed_pc=0x0c0c201eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2022; }
goto P_0c0c2020;
P_0c0c2020: /* original 2451, guest PC 0x0c0c2020 */
if(!s->budget--) { s->failed_pc=0x0c0c2020u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0c2022;
P_0c0c2022: /* original 7601, guest PC 0x0c0c2022 */
if(!s->budget--) { s->failed_pc=0x0c0c2022u; return 0; }
r[6]+=0x00000001u;
goto P_0c0c2024;
P_0c0c2024: /* original 7444, guest PC 0x0c0c2024 */
if(!s->budget--) { s->failed_pc=0x0c0c2024u; return 0; }
r[4]+=0x00000044u;
goto P_0c0c2026;
P_0c0c2026: /* original 3672, guest PC 0x0c0c2026 */
if(!s->budget--) { s->failed_pc=0x0c0c2026u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c0c2028;
P_0c0c2028: /* original 8bee, guest PC 0x0c0c2028 */
if(!s->budget--) { s->failed_pc=0x0c0c2028u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2008; }
goto P_0c0c202a;
P_0c0c202a: /* original a00f, guest PC 0x0c0c202a */
if(!s->budget--) { s->failed_pc=0x0c0c202au; return 0; }
goto P_0c0c204c;
P_0c0c202c: /* original 0009, guest PC 0x0c0c202c */
if(!s->budget--) { s->failed_pc=0x0c0c202cu; return 0; }
goto P_0c0c202e;
P_0c0c202e: /* original 2fd6, guest PC 0x0c0c202e */
if(!s->budget--) { s->failed_pc=0x0c0c202eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2030;
P_0c0c2030: /* original 66a3, guest PC 0x0c0c2030 */
if(!s->budget--) { s->failed_pc=0x0c0c2030u; return 0; }
r[6]=r[10];
goto P_0c0c2032;
P_0c0c2032: /* original 2fb6, guest PC 0x0c0c2032 */
if(!s->budget--) { s->failed_pc=0x0c0c2032u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2034;
P_0c0c2034: /* original d54f, guest PC 0x0c0c2034 */
if(!s->budget--) { s->failed_pc=0x0c0c2034u; return 0; }
r[5]=read(ram,0x0c0c2174u,4);
goto P_0c0c2036;
P_0c0c2036: /* original 57f2, guest PC 0x0c0c2036 */
if(!s->budget--) { s->failed_pc=0x0c0c2036u; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c0c2038;
P_0c0c2038: /* original 25cb, guest PC 0x0c0c2038 */
if(!s->budget--) { s->failed_pc=0x0c0c2038u; return 0; }
r[5]|=r[12];
goto P_0c0c203a;
P_0c0c203a: /* original bfbe, guest PC 0x0c0c203a */
if(!s->budget--) { s->failed_pc=0x0c0c203au; return 0; }
target=code_base|0x0c0c1fbau; r[16]=code_base|0x0c0c203eu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c203eu) { target=s->pc; goto dispatch; }
goto P_0c0c203e;
P_0c0c203c: /* original 6493, guest PC 0x0c0c203c */
if(!s->budget--) { s->failed_pc=0x0c0c203cu; return 0; }
r[4]=r[9];
goto P_0c0c203e;
P_0c0c203e: /* original d24e, guest PC 0x0c0c203e */
if(!s->budget--) { s->failed_pc=0x0c0c203eu; return 0; }
r[2]=read(ram,0x0c0c2178u,4);
goto P_0c0c2040;
P_0c0c2040: /* original 7f08, guest PC 0x0c0c2040 */
if(!s->budget--) { s->failed_pc=0x0c0c2040u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c2042;
P_0c0c2042: /* original 420b, guest PC 0x0c0c2042 */
if(!s->budget--) { s->failed_pc=0x0c0c2042u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c2046u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2046u) { target=s->pc; goto dispatch; }
goto P_0c0c2046;
P_0c0c2044: /* original 64a3, guest PC 0x0c0c2044 */
if(!s->budget--) { s->failed_pc=0x0c0c2044u; return 0; }
r[4]=r[10];
goto P_0c0c2046;
P_0c0c2046: /* original 6e03, guest PC 0x0c0c2046 */
if(!s->budget--) { s->failed_pc=0x0c0c2046u; return 0; }
r[14]=r[0];
goto P_0c0c2048;
P_0c0c2048: /* original 2ee8, guest PC 0x0c0c2048 */
if(!s->budget--) { s->failed_pc=0x0c0c2048u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c204a;
P_0c0c204a: /* original 8b01, guest PC 0x0c0c204a */
if(!s->budget--) { s->failed_pc=0x0c0c204au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2050; }
goto P_0c0c204c;
P_0c0c204c: /* original a0ed, guest PC 0x0c0c204c */
if(!s->budget--) { s->failed_pc=0x0c0c204cu; return 0; }
r[0]=0x00000000u;
goto P_0c0c222a;
P_0c0c204e: /* original e000, guest PC 0x0c0c204e */
if(!s->budget--) { s->failed_pc=0x0c0c204eu; return 0; }
r[0]=0x00000000u;
goto P_0c0c2050;
P_0c0c2050: /* original 63f2, guest PC 0x0c0c2050 */
if(!s->budget--) { s->failed_pc=0x0c0c2050u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c2052;
P_0c0c2052: /* original 2338, guest PC 0x0c0c2052 */
if(!s->budget--) { s->failed_pc=0x0c0c2052u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c2054;
P_0c0c2054: /* original 8905, guest PC 0x0c0c2054 */
if(!s->budget--) { s->failed_pc=0x0c0c2054u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2062; }
goto P_0c0c2056;
P_0c0c2056: /* original 64f2, guest PC 0x0c0c2056 */
if(!s->budget--) { s->failed_pc=0x0c0c2056u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c2058;
P_0c0c2058: /* original 65f2, guest PC 0x0c0c2058 */
if(!s->budget--) { s->failed_pc=0x0c0c2058u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c205a;
P_0c0c205a: /* original 4429, guest PC 0x0c0c205a */
if(!s->budget--) { s->failed_pc=0x0c0c205au; return 0; }
r[4]>>=16;
goto P_0c0c205c;
P_0c0c205c: /* original 655f, guest PC 0x0c0c205c */
if(!s->budget--) { s->failed_pc=0x0c0c205cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0c205e;
P_0c0c205e: /* original a007, guest PC 0x0c0c205e */
if(!s->budget--) { s->failed_pc=0x0c0c205eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c2070;
P_0c0c2060: /* original 644f, guest PC 0x0c0c2060 */
if(!s->budget--) { s->failed_pc=0x0c0c2060u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c2062;
P_0c0c2062: /* original e3f9, guest PC 0x0c0c2062 */
if(!s->budget--) { s->failed_pc=0x0c0c2062u; return 0; }
r[3]=0xfffffff9u;
goto P_0c0c2064;
P_0c0c2064: /* original 6593, guest PC 0x0c0c2064 */
if(!s->budget--) { s->failed_pc=0x0c0c2064u; return 0; }
r[5]=r[9];
goto P_0c0c2066;
P_0c0c2066: /* original 493d, guest PC 0x0c0c2066 */
if(!s->budget--) { s->failed_pc=0x0c0c2066u; return 0; }
r[9]=(r[3]&0x80000000u)?((r[3]&31u)?r[9]>>((-r[3])&31u):0):r[9]<<(r[3]&31u);
goto P_0c0c2068;
P_0c0c2068: /* original 6493, guest PC 0x0c0c2068 */
if(!s->budget--) { s->failed_pc=0x0c0c2068u; return 0; }
r[4]=r[9];
goto P_0c0c206a;
P_0c0c206a: /* original 4501, guest PC 0x0c0c206a */
if(!s->budget--) { s->failed_pc=0x0c0c206au; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0c206c;
P_0c0c206c: /* original 2489, guest PC 0x0c0c206c */
if(!s->budget--) { s->failed_pc=0x0c0c206cu; return 0; }
r[4]&=r[8];
goto P_0c0c206e;
P_0c0c206e: /* original 2589, guest PC 0x0c0c206e */
if(!s->budget--) { s->failed_pc=0x0c0c206eu; return 0; }
r[5]&=r[8];
goto P_0c0c2070;
P_0c0c2070: /* original 6053, guest PC 0x0c0c2070 */
if(!s->budget--) { s->failed_pc=0x0c0c2070u; return 0; }
r[0]=r[5];
goto P_0c0c2072;
P_0c0c2072: /* original 4508, guest PC 0x0c0c2072 */
if(!s->budget--) { s->failed_pc=0x0c0c2072u; return 0; }
r[5]<<=2;
goto P_0c0c2074;
P_0c0c2074: /* original 4500, guest PC 0x0c0c2074 */
if(!s->budget--) { s->failed_pc=0x0c0c2074u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c2076;
P_0c0c2076: /* original 81e3, guest PC 0x0c0c2076 */
if(!s->budget--) { s->failed_pc=0x0c0c2076u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c0c2078;
P_0c0c2078: /* original 6043, guest PC 0x0c0c2078 */
if(!s->budget--) { s->failed_pc=0x0c0c2078u; return 0; }
r[0]=r[4];
goto P_0c0c207a;
P_0c0c207a: /* original 4408, guest PC 0x0c0c207a */
if(!s->budget--) { s->failed_pc=0x0c0c207au; return 0; }
r[4]<<=2;
goto P_0c0c207c;
P_0c0c207c: /* original 4400, guest PC 0x0c0c207c */
if(!s->budget--) { s->failed_pc=0x0c0c207cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c207e;
P_0c0c207e: /* original 81e4, guest PC 0x0c0c207e */
if(!s->budget--) { s->failed_pc=0x0c0c207eu; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c0c2080;
P_0c0c2080: /* original 60c3, guest PC 0x0c0c2080 */
if(!s->budget--) { s->failed_pc=0x0c0c2080u; return 0; }
r[0]=r[12];
goto P_0c0c2082;
P_0c0c2082: /* original 81e1, guest PC 0x0c0c2082 */
if(!s->budget--) { s->failed_pc=0x0c0c2082u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c0c2084;
P_0c0c2084: /* original 455a, guest PC 0x0c0c2084 */
if(!s->budget--) { s->failed_pc=0x0c0c2084u; return 0; }
r[53]=r[5];
goto P_0c0c2086;
P_0c0c2086: /* original e010, guest PC 0x0c0c2086 */
if(!s->budget--) { s->failed_pc=0x0c0c2086u; return 0; }
r[0]=0x00000010u;
goto P_0c0c2088;
P_0c0c2088: /* original f32d, guest PC 0x0c0c2088 */
if(!s->budget--) { s->failed_pc=0x0c0c2088u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c208a;
P_0c0c208a: /* original ff37, guest PC 0x0c0c208a */
if(!s->budget--) { s->failed_pc=0x0c0c208au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c208c;
P_0c0c208c: /* original e00c, guest PC 0x0c0c208c */
if(!s->budget--) { s->failed_pc=0x0c0c208cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c208e;
P_0c0c208e: /* original 445a, guest PC 0x0c0c208e */
if(!s->budget--) { s->failed_pc=0x0c0c208eu; return 0; }
r[53]=r[4];
goto P_0c0c2090;
P_0c0c2090: /* original f22d, guest PC 0x0c0c2090 */
if(!s->budget--) { s->failed_pc=0x0c0c2090u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c2092;
P_0c0c2092: /* original ff27, guest PC 0x0c0c2092 */
if(!s->budget--) { s->failed_pc=0x0c0c2092u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c2094;
P_0c0c2094: /* original d339, guest PC 0x0c0c2094 */
if(!s->budget--) { s->failed_pc=0x0c0c2094u; return 0; }
r[3]=read(ram,0x0c0c217cu,4);
goto P_0c0c2096;
P_0c0c2096: /* original 430b, guest PC 0x0c0c2096 */
if(!s->budget--) { s->failed_pc=0x0c0c2096u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c209au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c209au) { target=s->pc; goto dispatch; }
goto P_0c0c209a;
P_0c0c2098: /* original 64c3, guest PC 0x0c0c2098 */
if(!s->budget--) { s->failed_pc=0x0c0c2098u; return 0; }
r[4]=r[12];
goto P_0c0c209a;
P_0c0c209a: /* original 6c03, guest PC 0x0c0c209a */
if(!s->budget--) { s->failed_pc=0x0c0c209au; return 0; }
r[12]=r[0];
goto P_0c0c209c;
P_0c0c209c: /* original e004, guest PC 0x0c0c209c */
if(!s->budget--) { s->failed_pc=0x0c0c209cu; return 0; }
r[0]=0x00000004u;
goto P_0c0c209e;
P_0c0c209e: /* original fec6, guest PC 0x0c0c209e */
if(!s->budget--) { s->failed_pc=0x0c0c209eu; return 0; }
vf3_matrix_load(s,ram,14,r[12]+r[0]);
goto P_0c0c20a0;
P_0c0c20a0: /* original e008, guest PC 0x0c0c20a0 */
if(!s->budget--) { s->failed_pc=0x0c0c20a0u; return 0; }
r[0]=0x00000008u;
goto P_0c0c20a2;
P_0c0c20a2: /* original f3c6, guest PC 0x0c0c20a2 */
if(!s->budget--) { s->failed_pc=0x0c0c20a2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c20a4;
P_0c0c20a4: /* original e004, guest PC 0x0c0c20a4 */
if(!s->budget--) { s->failed_pc=0x0c0c20a4u; return 0; }
r[0]=0x00000004u;
goto P_0c0c20a6;
P_0c0c20a6: /* original fdc8, guest PC 0x0c0c20a6 */
if(!s->budget--) { s->failed_pc=0x0c0c20a6u; return 0; }
vf3_matrix_load(s,ram,13,r[12]);
goto P_0c0c20a8;
P_0c0c20a8: /* original 2bb8, guest PC 0x0c0c20a8 */
if(!s->budget--) { s->failed_pc=0x0c0c20a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c20aa;
P_0c0c20aa: /* original ff37, guest PC 0x0c0c20aa */
if(!s->budget--) { s->failed_pc=0x0c0c20aau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c20ac;
P_0c0c20ac: /* original e00c, guest PC 0x0c0c20ac */
if(!s->budget--) { s->failed_pc=0x0c0c20acu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c20ae;
P_0c0c20ae: /* original ffc6, guest PC 0x0c0c20ae */
if(!s->budget--) { s->failed_pc=0x0c0c20aeu; return 0; }
vf3_matrix_load(s,ram,15,r[12]+r[0]);
goto P_0c0c20b0;
P_0c0c20b0: /* original e010, guest PC 0x0c0c20b0 */
if(!s->budget--) { s->failed_pc=0x0c0c20b0u; return 0; }
r[0]=0x00000010u;
goto P_0c0c20b2;
P_0c0c20b2: /* original f3c6, guest PC 0x0c0c20b2 */
if(!s->budget--) { s->failed_pc=0x0c0c20b2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c20b4;
P_0c0c20b4: /* original e008, guest PC 0x0c0c20b4 */
if(!s->budget--) { s->failed_pc=0x0c0c20b4u; return 0; }
r[0]=0x00000008u;
goto P_0c0c20b6;
P_0c0c20b6: /* original ff37, guest PC 0x0c0c20b6 */
if(!s->budget--) { s->failed_pc=0x0c0c20b6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c20b8;
P_0c0c20b8: /* original e014, guest PC 0x0c0c20b8 */
if(!s->budget--) { s->failed_pc=0x0c0c20b8u; return 0; }
r[0]=0x00000014u;
goto P_0c0c20ba;
P_0c0c20ba: /* original 8d43, guest PC 0x0c0c20ba */
if(!s->budget--) { s->failed_pc=0x0c0c20bau; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,12,r[12]+r[0]);
if(cond) { goto P_0c0c2144; }
goto P_0c0c20be;
P_0c0c20bc: /* original fcc6, guest PC 0x0c0c20bc */
if(!s->budget--) { s->failed_pc=0x0c0c20bcu; return 0; }
vf3_matrix_load(s,ram,12,r[12]+r[0]);
goto P_0c0c20be;
P_0c0c20be: /* original 67b3, guest PC 0x0c0c20be */
if(!s->budget--) { s->failed_pc=0x0c0c20beu; return 0; }
r[7]=r[11];
goto P_0c0c20c0;
P_0c0c20c0: /* original 4729, guest PC 0x0c0c20c0 */
if(!s->budget--) { s->failed_pc=0x0c0c20c0u; return 0; }
r[7]>>=16;
goto P_0c0c20c2;
P_0c0c20c2: /* original 4719, guest PC 0x0c0c20c2 */
if(!s->budget--) { s->failed_pc=0x0c0c20c2u; return 0; }
r[7]>>=8;
goto P_0c0c20c4;
P_0c0c20c4: /* original 64b3, guest PC 0x0c0c20c4 */
if(!s->budget--) { s->failed_pc=0x0c0c20c4u; return 0; }
r[4]=r[11];
goto P_0c0c20c6;
P_0c0c20c6: /* original 677c, guest PC 0x0c0c20c6 */
if(!s->budget--) { s->failed_pc=0x0c0c20c6u; return 0; }
r[7]=r[7]&255u;
goto P_0c0c20c8;
P_0c0c20c8: /* original 66b3, guest PC 0x0c0c20c8 */
if(!s->budget--) { s->failed_pc=0x0c0c20c8u; return 0; }
r[6]=r[11];
goto P_0c0c20ca;
P_0c0c20ca: /* original 4708, guest PC 0x0c0c20ca */
if(!s->budget--) { s->failed_pc=0x0c0c20cau; return 0; }
r[7]<<=2;
goto P_0c0c20cc;
P_0c0c20cc: /* original 4700, guest PC 0x0c0c20cc */
if(!s->budget--) { s->failed_pc=0x0c0c20ccu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c20ce;
P_0c0c20ce: /* original 475a, guest PC 0x0c0c20ce */
if(!s->budget--) { s->failed_pc=0x0c0c20ceu; return 0; }
r[53]=r[7];
goto P_0c0c20d0;
P_0c0c20d0: /* original 4629, guest PC 0x0c0c20d0 */
if(!s->budget--) { s->failed_pc=0x0c0c20d0u; return 0; }
r[6]>>=16;
goto P_0c0c20d2;
P_0c0c20d2: /* original 4419, guest PC 0x0c0c20d2 */
if(!s->budget--) { s->failed_pc=0x0c0c20d2u; return 0; }
r[4]>>=8;
goto P_0c0c20d4;
P_0c0c20d4: /* original 4711, guest PC 0x0c0c20d4 */
if(!s->budget--) { s->failed_pc=0x0c0c20d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c0c20d6;
P_0c0c20d6: /* original 644c, guest PC 0x0c0c20d6 */
if(!s->budget--) { s->failed_pc=0x0c0c20d6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c20d8;
P_0c0c20d8: /* original 65bc, guest PC 0x0c0c20d8 */
if(!s->budget--) { s->failed_pc=0x0c0c20d8u; return 0; }
r[5]=r[11]&255u;
goto P_0c0c20da;
P_0c0c20da: /* original 666c, guest PC 0x0c0c20da */
if(!s->budget--) { s->failed_pc=0x0c0c20dau; return 0; }
r[6]=r[6]&255u;
goto P_0c0c20dc;
P_0c0c20dc: /* original 8d04, guest PC 0x0c0c20dc */
if(!s->budget--) { s->failed_pc=0x0c0c20dcu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c20e8; }
goto P_0c0c20e0;
P_0c0c20de: /* original f32d, guest PC 0x0c0c20de */
if(!s->budget--) { s->failed_pc=0x0c0c20deu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c20e0;
P_0c0c20e0: /* original d327, guest PC 0x0c0c20e0 */
if(!s->budget--) { s->failed_pc=0x0c0c20e0u; return 0; }
r[3]=read(ram,0x0c0c2180u,4);
goto P_0c0c20e2;
P_0c0c20e2: /* original 435a, guest PC 0x0c0c20e2 */
if(!s->budget--) { s->failed_pc=0x0c0c20e2u; return 0; }
r[53]=r[3];
goto P_0c0c20e4;
P_0c0c20e4: /* original f20d, guest PC 0x0c0c20e4 */
if(!s->budget--) { s->failed_pc=0x0c0c20e4u; return 0; }
fr[2]=r[53];
goto P_0c0c20e6;
P_0c0c20e6: /* original f320, guest PC 0x0c0c20e6 */
if(!s->budget--) { s->failed_pc=0x0c0c20e6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c20e8;
P_0c0c20e8: /* original f2dc, guest PC 0x0c0c20e8 */
if(!s->budget--) { s->failed_pc=0x0c0c20e8u; return 0; }
vf3_matrix_move(s,2,13);
goto P_0c0c20ea;
P_0c0c20ea: /* original 4608, guest PC 0x0c0c20ea */
if(!s->budget--) { s->failed_pc=0x0c0c20eau; return 0; }
r[6]<<=2;
goto P_0c0c20ec;
P_0c0c20ec: /* original fd3c, guest PC 0x0c0c20ec */
if(!s->budget--) { s->failed_pc=0x0c0c20ecu; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c0c20ee;
P_0c0c20ee: /* original 4600, guest PC 0x0c0c20ee */
if(!s->budget--) { s->failed_pc=0x0c0c20eeu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0c20f0;
P_0c0c20f0: /* original fd20, guest PC 0x0c0c20f0 */
if(!s->budget--) { s->failed_pc=0x0c0c20f0u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[2],r[18],'+');
goto P_0c0c20f2;
P_0c0c20f2: /* original 465a, guest PC 0x0c0c20f2 */
if(!s->budget--) { s->failed_pc=0x0c0c20f2u; return 0; }
r[53]=r[6];
goto P_0c0c20f4;
P_0c0c20f4: /* original 4611, guest PC 0x0c0c20f4 */
if(!s->budget--) { s->failed_pc=0x0c0c20f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0c20f6;
P_0c0c20f6: /* original 8d04, guest PC 0x0c0c20f6 */
if(!s->budget--) { s->failed_pc=0x0c0c20f6u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c2102; }
goto P_0c0c20fa;
P_0c0c20f8: /* original f32d, guest PC 0x0c0c20f8 */
if(!s->budget--) { s->failed_pc=0x0c0c20f8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c20fa;
P_0c0c20fa: /* original d321, guest PC 0x0c0c20fa */
if(!s->budget--) { s->failed_pc=0x0c0c20fau; return 0; }
r[3]=read(ram,0x0c0c2180u,4);
goto P_0c0c20fc;
P_0c0c20fc: /* original 435a, guest PC 0x0c0c20fc */
if(!s->budget--) { s->failed_pc=0x0c0c20fcu; return 0; }
r[53]=r[3];
goto P_0c0c20fe;
P_0c0c20fe: /* original f20d, guest PC 0x0c0c20fe */
if(!s->budget--) { s->failed_pc=0x0c0c20feu; return 0; }
fr[2]=r[53];
goto P_0c0c2100;
P_0c0c2100: /* original f320, guest PC 0x0c0c2100 */
if(!s->budget--) { s->failed_pc=0x0c0c2100u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c2102;
P_0c0c2102: /* original 4408, guest PC 0x0c0c2102 */
if(!s->budget--) { s->failed_pc=0x0c0c2102u; return 0; }
r[4]<<=2;
goto P_0c0c2104;
P_0c0c2104: /* original f2ec, guest PC 0x0c0c2104 */
if(!s->budget--) { s->failed_pc=0x0c0c2104u; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0c2106;
P_0c0c2106: /* original 4400, guest PC 0x0c0c2106 */
if(!s->budget--) { s->failed_pc=0x0c0c2106u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c2108;
P_0c0c2108: /* original fe3c, guest PC 0x0c0c2108 */
if(!s->budget--) { s->failed_pc=0x0c0c2108u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0c210a;
P_0c0c210a: /* original 445a, guest PC 0x0c0c210a */
if(!s->budget--) { s->failed_pc=0x0c0c210au; return 0; }
r[53]=r[4];
goto P_0c0c210c;
P_0c0c210c: /* original fe20, guest PC 0x0c0c210c */
if(!s->budget--) { s->failed_pc=0x0c0c210cu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
goto P_0c0c210e;
P_0c0c210e: /* original f38d, guest PC 0x0c0c210e */
if(!s->budget--) { s->failed_pc=0x0c0c210eu; return 0; }
fr[3]=0;
goto P_0c0c2110;
P_0c0c2110: /* original f22d, guest PC 0x0c0c2110 */
if(!s->budget--) { s->failed_pc=0x0c0c2110u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c2112;
P_0c0c2112: /* original f325, guest PC 0x0c0c2112 */
if(!s->budget--) { s->failed_pc=0x0c0c2112u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0c2114;
P_0c0c2114: /* original 8f05, guest PC 0x0c0c2114 */
if(!s->budget--) { s->failed_pc=0x0c0c2114u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,2);
if(!cond) { goto P_0c0c2122; }
goto P_0c0c2118;
P_0c0c2116: /* original f42c, guest PC 0x0c0c2116 */
if(!s->budget--) { s->failed_pc=0x0c0c2116u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0c2118;
P_0c0c2118: /* original c719, guest PC 0x0c0c2118 */
if(!s->budget--) { s->failed_pc=0x0c0c2118u; return 0; }
r[0]=code_base|0x000c2180u;
goto P_0c0c211a;
P_0c0c211a: /* original f34c, guest PC 0x0c0c211a */
if(!s->budget--) { s->failed_pc=0x0c0c211au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0c211c;
P_0c0c211c: /* original f208, guest PC 0x0c0c211c */
if(!s->budget--) { s->failed_pc=0x0c0c211cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c211e;
P_0c0c211e: /* original a001, guest PC 0x0c0c211e */
if(!s->budget--) { s->failed_pc=0x0c0c211eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c2124;
P_0c0c2120: /* original f320, guest PC 0x0c0c2120 */
if(!s->budget--) { s->failed_pc=0x0c0c2120u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c2122;
P_0c0c2122: /* original f34c, guest PC 0x0c0c2122 */
if(!s->budget--) { s->failed_pc=0x0c0c2122u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0c2124;
P_0c0c2124: /* original 4508, guest PC 0x0c0c2124 */
if(!s->budget--) { s->failed_pc=0x0c0c2124u; return 0; }
r[5]<<=2;
goto P_0c0c2126;
P_0c0c2126: /* original 4500, guest PC 0x0c0c2126 */
if(!s->budget--) { s->failed_pc=0x0c0c2126u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c2128;
P_0c0c2128: /* original e004, guest PC 0x0c0c2128 */
if(!s->budget--) { s->failed_pc=0x0c0c2128u; return 0; }
r[0]=0x00000004u;
goto P_0c0c212a;
P_0c0c212a: /* original ff37, guest PC 0x0c0c212a */
if(!s->budget--) { s->failed_pc=0x0c0c212au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c212c;
P_0c0c212c: /* original 455a, guest PC 0x0c0c212c */
if(!s->budget--) { s->failed_pc=0x0c0c212cu; return 0; }
r[53]=r[5];
goto P_0c0c212e;
P_0c0c212e: /* original f18d, guest PC 0x0c0c212e */
if(!s->budget--) { s->failed_pc=0x0c0c212eu; return 0; }
fr[1]=0;
goto P_0c0c2130;
P_0c0c2130: /* original f22d, guest PC 0x0c0c2130 */
if(!s->budget--) { s->failed_pc=0x0c0c2130u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c2132;
P_0c0c2132: /* original f125, guest PC 0x0c0c2132 */
if(!s->budget--) { s->failed_pc=0x0c0c2132u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c0c2134;
P_0c0c2134: /* original 8f05, guest PC 0x0c0c2134 */
if(!s->budget--) { s->failed_pc=0x0c0c2134u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,2);
if(!cond) { goto P_0c0c2142; }
goto P_0c0c2138;
P_0c0c2136: /* original f42c, guest PC 0x0c0c2136 */
if(!s->budget--) { s->failed_pc=0x0c0c2136u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0c2138;
P_0c0c2138: /* original c711, guest PC 0x0c0c2138 */
if(!s->budget--) { s->failed_pc=0x0c0c2138u; return 0; }
r[0]=code_base|0x000c2180u;
goto P_0c0c213a;
P_0c0c213a: /* original ff4c, guest PC 0x0c0c213a */
if(!s->budget--) { s->failed_pc=0x0c0c213au; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0c213c;
P_0c0c213c: /* original f208, guest PC 0x0c0c213c */
if(!s->budget--) { s->failed_pc=0x0c0c213cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c213e;
P_0c0c213e: /* original a001, guest PC 0x0c0c213e */
if(!s->budget--) { s->failed_pc=0x0c0c213eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'+');
goto P_0c0c2144;
P_0c0c2140: /* original ff20, guest PC 0x0c0c2140 */
if(!s->budget--) { s->failed_pc=0x0c0c2140u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'+');
goto P_0c0c2142;
P_0c0c2142: /* original ff4c, guest PC 0x0c0c2142 */
if(!s->budget--) { s->failed_pc=0x0c0c2142u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0c2144;
P_0c0c2144: /* original e004, guest PC 0x0c0c2144 */
if(!s->budget--) { s->failed_pc=0x0c0c2144u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2146;
P_0c0c2146: /* original f3f6, guest PC 0x0c0c2146 */
if(!s->budget--) { s->failed_pc=0x0c0c2146u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c2148;
P_0c0c2148: /* original e340, guest PC 0x0c0c2148 */
if(!s->budget--) { s->failed_pc=0x0c0c2148u; return 0; }
r[3]=0x00000040u;
goto P_0c0c214a;
P_0c0c214a: /* original f33d, guest PC 0x0c0c214a */
if(!s->budget--) { s->failed_pc=0x0c0c214au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c214c;
P_0c0c214c: /* original 005a, guest PC 0x0c0c214c */
if(!s->budget--) { s->failed_pc=0x0c0c214cu; return 0; }
r[0]=r[53];
goto P_0c0c214e;
P_0c0c214e: /* original ff3d, guest PC 0x0c0c214e */
if(!s->budget--) { s->failed_pc=0x0c0c214eu; return 0; }
r[53]=truncate_float(fr[15]);
goto P_0c0c2150;
P_0c0c2150: /* original 600d, guest PC 0x0c0c2150 */
if(!s->budget--) { s->failed_pc=0x0c0c2150u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c2152;
P_0c0c2152: /* original 4009, guest PC 0x0c0c2152 */
if(!s->budget--) { s->failed_pc=0x0c0c2152u; return 0; }
r[0]>>=2;
goto P_0c0c2154;
P_0c0c2154: /* original 4001, guest PC 0x0c0c2154 */
if(!s->budget--) { s->failed_pc=0x0c0c2154u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c2156;
P_0c0c2156: /* original 81e5, guest PC 0x0c0c2156 */
if(!s->budget--) { s->failed_pc=0x0c0c2156u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c0c2158;
P_0c0c2158: /* original 005a, guest PC 0x0c0c2158 */
if(!s->budget--) { s->failed_pc=0x0c0c2158u; return 0; }
r[0]=r[53];
goto P_0c0c215a;
P_0c0c215a: /* original 600d, guest PC 0x0c0c215a */
if(!s->budget--) { s->failed_pc=0x0c0c215au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c215c;
P_0c0c215c: /* original 4009, guest PC 0x0c0c215c */
if(!s->budget--) { s->failed_pc=0x0c0c215cu; return 0; }
r[0]>>=2;
goto P_0c0c215e;
P_0c0c215e: /* original 4001, guest PC 0x0c0c215e */
if(!s->budget--) { s->failed_pc=0x0c0c215eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c2160;
P_0c0c2160: /* original 81e6, guest PC 0x0c0c2160 */
if(!s->budget--) { s->failed_pc=0x0c0c2160u; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c0c2162;
P_0c0c2162: /* original e008, guest PC 0x0c0c2162 */
if(!s->budget--) { s->failed_pc=0x0c0c2162u; return 0; }
r[0]=0x00000008u;
goto P_0c0c2164;
P_0c0c2164: /* original f3f6, guest PC 0x0c0c2164 */
if(!s->budget--) { s->failed_pc=0x0c0c2164u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c2166;
P_0c0c2166: /* original e004, guest PC 0x0c0c2166 */
if(!s->budget--) { s->failed_pc=0x0c0c2166u; return 0; }
r[0]=0x00000004u;
goto P_0c0c2168;
P_0c0c2168: /* original f6f6, guest PC 0x0c0c2168 */
if(!s->budget--) { s->failed_pc=0x0c0c2168u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c216a;
P_0c0c216a: /* original 23d8, guest PC 0x0c0c216a */
if(!s->budget--) { s->failed_pc=0x0c0c216au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c216c;
P_0c0c216c: /* original 8d0a, guest PC 0x0c0c216c */
if(!s->budget--) { s->failed_pc=0x0c0c216cu; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
if(cond) { goto P_0c0c2184; }
goto P_0c0c2170;
P_0c0c216e: /* original f632, guest PC 0x0c0c216e */
if(!s->budget--) { s->failed_pc=0x0c0c216eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0c2170;
P_0c0c2170: /* original a00d, guest PC 0x0c0c2170 */
if(!s->budget--) { s->failed_pc=0x0c0c2170u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c218e;
P_0c0c2172: /* original f7fc, guest PC 0x0c0c2172 */
if(!s->budget--) { s->failed_pc=0x0c0c2172u; return 0; }
vf3_matrix_move(s,7,15);
if(!vf3_matrix_family(0x0c0c2174u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2174u; return 0; } return 1;
P_0c0c2184: /* original c731, guest PC 0x0c0c2184 */
if(!s->budget--) { s->failed_pc=0x0c0c2184u; return 0; }
r[0]=code_base|0x000c224cu;
goto P_0c0c2186;
P_0c0c2186: /* original f1fc, guest PC 0x0c0c2186 */
if(!s->budget--) { s->failed_pc=0x0c0c2186u; return 0; }
vf3_matrix_move(s,1,15);
goto P_0c0c2188;
P_0c0c2188: /* original f208, guest PC 0x0c0c2188 */
if(!s->budget--) { s->failed_pc=0x0c0c2188u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c218a;
P_0c0c218a: /* original f120, guest PC 0x0c0c218a */
if(!s->budget--) { s->failed_pc=0x0c0c218au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c0c218c;
P_0c0c218c: /* original f71c, guest PC 0x0c0c218c */
if(!s->budget--) { s->failed_pc=0x0c0c218cu; return 0; }
vf3_matrix_move(s,7,1);
goto P_0c0c218e;
P_0c0c218e: /* original e026, guest PC 0x0c0c218e */
if(!s->budget--) { s->failed_pc=0x0c0c218eu; return 0; }
r[0]=0x00000026u;
goto P_0c0c2190;
P_0c0c2190: /* original f7c2, guest PC 0x0c0c2190 */
if(!s->budget--) { s->failed_pc=0x0c0c2190u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[12],r[18],'*');
goto P_0c0c2192;
P_0c0c2192: /* original 03ad, guest PC 0x0c0c2192 */
if(!s->budget--) { s->failed_pc=0x0c0c2192u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c2194;
P_0c0c2194: /* original 64e3, guest PC 0x0c0c2194 */
if(!s->budget--) { s->failed_pc=0x0c0c2194u; return 0; }
r[4]=r[14];
goto P_0c0c2196;
P_0c0c2196: /* original d02e, guest PC 0x0c0c2196 */
if(!s->budget--) { s->failed_pc=0x0c0c2196u; return 0; }
r[0]=read(ram,0x0c0c2250u,4);
goto P_0c0c2198;
P_0c0c2198: /* original 633d, guest PC 0x0c0c2198 */
if(!s->budget--) { s->failed_pc=0x0c0c2198u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c219a;
P_0c0c219a: /* original 4308, guest PC 0x0c0c219a */
if(!s->budget--) { s->failed_pc=0x0c0c219au; return 0; }
r[3]<<=2;
goto P_0c0c219c;
P_0c0c219c: /* original f836, guest PC 0x0c0c219c */
if(!s->budget--) { s->failed_pc=0x0c0c219cu; return 0; }
vf3_matrix_load(s,ram,8,r[3]+r[0]);
goto P_0c0c219e;
P_0c0c219e: /* original e00c, guest PC 0x0c0c219e */
if(!s->budget--) { s->failed_pc=0x0c0c219eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c21a0;
P_0c0c21a0: /* original f5f6, guest PC 0x0c0c21a0 */
if(!s->budget--) { s->failed_pc=0x0c0c21a0u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c21a2;
P_0c0c21a2: /* original e010, guest PC 0x0c0c21a2 */
if(!s->budget--) { s->failed_pc=0x0c0c21a2u; return 0; }
r[0]=0x00000010u;
goto P_0c0c21a4;
P_0c0c21a4: /* original d32b, guest PC 0x0c0c21a4 */
if(!s->budget--) { s->failed_pc=0x0c0c21a4u; return 0; }
r[3]=read(ram,0x0c0c2254u,4);
goto P_0c0c21a6;
P_0c0c21a6: /* original f4f6, guest PC 0x0c0c21a6 */
if(!s->budget--) { s->failed_pc=0x0c0c21a6u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c21a8;
P_0c0c21a8: /* original 430b, guest PC 0x0c0c21a8 */
if(!s->budget--) { s->failed_pc=0x0c0c21a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c21acu;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c21acu) { target=s->pc; goto dispatch; }
goto P_0c0c21ac;
P_0c0c21aa: /* original 7410, guest PC 0x0c0c21aa */
if(!s->budget--) { s->failed_pc=0x0c0c21aau; return 0; }
r[4]+=0x00000010u;
goto P_0c0c21ac;
P_0c0c21ac: /* original e008, guest PC 0x0c0c21ac */
if(!s->budget--) { s->failed_pc=0x0c0c21acu; return 0; }
r[0]=0x00000008u;
goto P_0c0c21ae;
P_0c0c21ae: /* original d32a, guest PC 0x0c0c21ae */
if(!s->budget--) { s->failed_pc=0x0c0c21aeu; return 0; }
r[3]=read(ram,0x0c0c2258u,4);
goto P_0c0c21b0;
P_0c0c21b0: /* original f8f6, guest PC 0x0c0c21b0 */
if(!s->budget--) { s->failed_pc=0x0c0c21b0u; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c21b2;
P_0c0c21b2: /* original e004, guest PC 0x0c0c21b2 */
if(!s->budget--) { s->failed_pc=0x0c0c21b2u; return 0; }
r[0]=0x00000004u;
goto P_0c0c21b4;
P_0c0c21b4: /* original f6f6, guest PC 0x0c0c21b4 */
if(!s->budget--) { s->failed_pc=0x0c0c21b4u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c21b6;
P_0c0c21b6: /* original 64e3, guest PC 0x0c0c21b6 */
if(!s->budget--) { s->failed_pc=0x0c0c21b6u; return 0; }
r[4]=r[14];
goto P_0c0c21b8;
P_0c0c21b8: /* original f4dc, guest PC 0x0c0c21b8 */
if(!s->budget--) { s->failed_pc=0x0c0c21b8u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c21ba;
P_0c0c21ba: /* original f7fc, guest PC 0x0c0c21ba */
if(!s->budget--) { s->failed_pc=0x0c0c21bau; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c21bc;
P_0c0c21bc: /* original f9cc, guest PC 0x0c0c21bc */
if(!s->budget--) { s->failed_pc=0x0c0c21bcu; return 0; }
vf3_matrix_move(s,9,12);
goto P_0c0c21be;
P_0c0c21be: /* original f5ec, guest PC 0x0c0c21be */
if(!s->budget--) { s->failed_pc=0x0c0c21beu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0c21c0;
P_0c0c21c0: /* original 430b, guest PC 0x0c0c21c0 */
if(!s->budget--) { s->failed_pc=0x0c0c21c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c21c4u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c21c4u) { target=s->pc; goto dispatch; }
goto P_0c0c21c4;
P_0c0c21c2: /* original 7410, guest PC 0x0c0c21c2 */
if(!s->budget--) { s->failed_pc=0x0c0c21c2u; return 0; }
r[4]+=0x00000010u;
goto P_0c0c21c4;
P_0c0c21c4: /* original 50c8, guest PC 0x0c0c21c4 */
if(!s->budget--) { s->failed_pc=0x0c0c21c4u; return 0; }
r[0]=read(ram,r[12]+32,4);
goto P_0c0c21c6;
P_0c0c21c6: /* original e501, guest PC 0x0c0c21c6 */
if(!s->budget--) { s->failed_pc=0x0c0c21c6u; return 0; }
r[5]=0x00000001u;
goto P_0c0c21c8;
P_0c0c21c8: /* original d124, guest PC 0x0c0c21c8 */
if(!s->budget--) { s->failed_pc=0x0c0c21c8u; return 0; }
r[1]=read(ram,0x0c0c225cu,4);
goto P_0c0c21ca;
P_0c0c21ca: /* original 4000, guest PC 0x0c0c21ca */
if(!s->budget--) { s->failed_pc=0x0c0c21cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c21cc;
P_0c0c21cc: /* original 001d, guest PC 0x0c0c21cc */
if(!s->budget--) { s->failed_pc=0x0c0c21ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c0c21ce;
P_0c0c21ce: /* original 25d8, guest PC 0x0c0c21ce */
if(!s->budget--) { s->failed_pc=0x0c0c21ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[13])==0)!=0);
goto P_0c0c21d0;
P_0c0c21d0: /* original 81e2, guest PC 0x0c0c21d0 */
if(!s->budget--) { s->failed_pc=0x0c0c21d0u; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c0c21d2;
P_0c0c21d2: /* original 600d, guest PC 0x0c0c21d2 */
if(!s->budget--) { s->failed_pc=0x0c0c21d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c21d4;
P_0c0c21d4: /* original 1e04, guest PC 0x0c0c21d4 */
if(!s->budget--) { s->failed_pc=0x0c0c21d4u; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c0c21d6;
P_0c0c21d6: /* original e040, guest PC 0x0c0c21d6 */
if(!s->budget--) { s->failed_pc=0x0c0c21d6u; return 0; }
r[0]=0x00000040u;
goto P_0c0c21d8;
P_0c0c21d8: /* original f39d, guest PC 0x0c0c21d8 */
if(!s->budget--) { s->failed_pc=0x0c0c21d8u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c21da;
P_0c0c21da: /* original fe37, guest PC 0x0c0c21da */
if(!s->budget--) { s->failed_pc=0x0c0c21dau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c21dc;
P_0c0c21dc: /* original 9433, guest PC 0x0c0c21dc */
if(!s->budget--) { s->failed_pc=0x0c0c21dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2246u,2);
goto P_0c0c21de;
P_0c0c21de: /* original 8d04, guest PC 0x0c0c21de */
if(!s->budget--) { s->failed_pc=0x0c0c21deu; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[5],2);
if(cond) { goto P_0c0c21ea; }
goto P_0c0c21e2;
P_0c0c21e0: /* original 2e51, guest PC 0x0c0c21e0 */
if(!s->budget--) { s->failed_pc=0x0c0c21e0u; return 0; }
write(ram,r[14],r[5],2);
goto P_0c0c21e2;
P_0c0c21e2: /* original 60e1, guest PC 0x0c0c21e2 */
if(!s->budget--) { s->failed_pc=0x0c0c21e2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c21e4;
P_0c0c21e4: /* original cb02, guest PC 0x0c0c21e4 */
if(!s->budget--) { s->failed_pc=0x0c0c21e4u; return 0; }
r[0]|=2u;
goto P_0c0c21e6;
P_0c0c21e6: /* original 2e01, guest PC 0x0c0c21e6 */
if(!s->budget--) { s->failed_pc=0x0c0c21e6u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0c21e8;
P_0c0c21e8: /* original 942e, guest PC 0x0c0c21e8 */
if(!s->budget--) { s->failed_pc=0x0c0c21e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2248u,2);
goto P_0c0c21ea;
P_0c0c21ea: /* original e202, guest PC 0x0c0c21ea */
if(!s->budget--) { s->failed_pc=0x0c0c21eau; return 0; }
r[2]=0x00000002u;
goto P_0c0c21ec;
P_0c0c21ec: /* original 22d8, guest PC 0x0c0c21ec */
if(!s->budget--) { s->failed_pc=0x0c0c21ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c21ee;
P_0c0c21ee: /* original 8d03, guest PC 0x0c0c21ee */
if(!s->budget--) { s->failed_pc=0x0c0c21eeu; return 0; }
cond=r[17]&1u;
r[2]=0x00000004u;
if(cond) { goto P_0c0c21f8; }
goto P_0c0c21f2;
P_0c0c21f0: /* original e204, guest PC 0x0c0c21f0 */
if(!s->budget--) { s->failed_pc=0x0c0c21f0u; return 0; }
r[2]=0x00000004u;
goto P_0c0c21f2;
P_0c0c21f2: /* original 60e1, guest PC 0x0c0c21f2 */
if(!s->budget--) { s->failed_pc=0x0c0c21f2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c21f4;
P_0c0c21f4: /* original cb04, guest PC 0x0c0c21f4 */
if(!s->budget--) { s->failed_pc=0x0c0c21f4u; return 0; }
r[0]|=4u;
goto P_0c0c21f6;
P_0c0c21f6: /* original 2e01, guest PC 0x0c0c21f6 */
if(!s->budget--) { s->failed_pc=0x0c0c21f6u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0c21f8;
P_0c0c21f8: /* original 22d8, guest PC 0x0c0c21f8 */
if(!s->budget--) { s->failed_pc=0x0c0c21f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c21fa;
P_0c0c21fa: /* original 8d03, guest PC 0x0c0c21fa */
if(!s->budget--) { s->failed_pc=0x0c0c21fau; return 0; }
cond=r[17]&1u;
r[2]=0x00000008u;
if(cond) { goto P_0c0c2204; }
goto P_0c0c21fe;
P_0c0c21fc: /* original e208, guest PC 0x0c0c21fc */
if(!s->budget--) { s->failed_pc=0x0c0c21fcu; return 0; }
r[2]=0x00000008u;
goto P_0c0c21fe;
P_0c0c21fe: /* original 60e1, guest PC 0x0c0c21fe */
if(!s->budget--) { s->failed_pc=0x0c0c21feu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c2200;
P_0c0c2200: /* original cb08, guest PC 0x0c0c2200 */
if(!s->budget--) { s->failed_pc=0x0c0c2200u; return 0; }
r[0]|=8u;
goto P_0c0c2202;
P_0c0c2202: /* original 2e01, guest PC 0x0c0c2202 */
if(!s->budget--) { s->failed_pc=0x0c0c2202u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0c2204;
P_0c0c2204: /* original 22d8, guest PC 0x0c0c2204 */
if(!s->budget--) { s->failed_pc=0x0c0c2204u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c2206;
P_0c0c2206: /* original 8901, guest PC 0x0c0c2206 */
if(!s->budget--) { s->failed_pc=0x0c0c2206u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c220c; }
goto P_0c0c2208;
P_0c0c2208: /* original 911f, guest PC 0x0c0c2208 */
if(!s->budget--) { s->failed_pc=0x0c0c2208u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c224au,2);
goto P_0c0c220a;
P_0c0c220a: /* original 241b, guest PC 0x0c0c220a */
if(!s->budget--) { s->failed_pc=0x0c0c220au; return 0; }
r[4]|=r[1];
goto P_0c0c220c;
P_0c0c220c: /* original e310, guest PC 0x0c0c220c */
if(!s->budget--) { s->failed_pc=0x0c0c220cu; return 0; }
r[3]=0x00000010u;
goto P_0c0c220e;
P_0c0c220e: /* original 23d8, guest PC 0x0c0c220e */
if(!s->budget--) { s->failed_pc=0x0c0c220eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c2210;
P_0c0c2210: /* original 8d03, guest PC 0x0c0c2210 */
if(!s->budget--) { s->failed_pc=0x0c0c2210u; return 0; }
cond=r[17]&1u;
r[3]=0x00000020u;
if(cond) { goto P_0c0c221a; }
goto P_0c0c2214;
P_0c0c2212: /* original e320, guest PC 0x0c0c2212 */
if(!s->budget--) { s->failed_pc=0x0c0c2212u; return 0; }
r[3]=0x00000020u;
goto P_0c0c2214;
P_0c0c2214: /* original 60e1, guest PC 0x0c0c2214 */
if(!s->budget--) { s->failed_pc=0x0c0c2214u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c2216;
P_0c0c2216: /* original cb10, guest PC 0x0c0c2216 */
if(!s->budget--) { s->failed_pc=0x0c0c2216u; return 0; }
r[0]|=16u;
goto P_0c0c2218;
P_0c0c2218: /* original 2e01, guest PC 0x0c0c2218 */
if(!s->budget--) { s->failed_pc=0x0c0c2218u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0c221a;
P_0c0c221a: /* original 2d38, guest PC 0x0c0c221a */
if(!s->budget--) { s->failed_pc=0x0c0c221au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c0c221c;
P_0c0c221c: /* original 8902, guest PC 0x0c0c221c */
if(!s->budget--) { s->failed_pc=0x0c0c221cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2224; }
goto P_0c0c221e;
P_0c0c221e: /* original 61e1, guest PC 0x0c0c221e */
if(!s->budget--) { s->failed_pc=0x0c0c221eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c0c2220;
P_0c0c2220: /* original 213b, guest PC 0x0c0c2220 */
if(!s->budget--) { s->failed_pc=0x0c0c2220u; return 0; }
r[1]|=r[3];
goto P_0c0c2222;
P_0c0c2222: /* original 2e11, guest PC 0x0c0c2222 */
if(!s->budget--) { s->failed_pc=0x0c0c2222u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c0c2224;
P_0c0c2224: /* original 60e3, guest PC 0x0c0c2224 */
if(!s->budget--) { s->failed_pc=0x0c0c2224u; return 0; }
r[0]=r[14];
goto P_0c0c2226;
P_0c0c2226: /* original 7010, guest PC 0x0c0c2226 */
if(!s->budget--) { s->failed_pc=0x0c0c2226u; return 0; }
r[0]+=0x00000010u;
goto P_0c0c2228;
P_0c0c2228: /* original 1e4f, guest PC 0x0c0c2228 */
if(!s->budget--) { s->failed_pc=0x0c0c2228u; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c0c222a;
P_0c0c222a: /* original 7f14, guest PC 0x0c0c222a */
if(!s->budget--) { s->failed_pc=0x0c0c222au; return 0; }
r[15]+=0x00000014u;
goto P_0c0c222c;
P_0c0c222c: /* original 4f26, guest PC 0x0c0c222c */
if(!s->budget--) { s->failed_pc=0x0c0c222cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c222e;
P_0c0c222e: /* original fcf9, guest PC 0x0c0c222e */
if(!s->budget--) { s->failed_pc=0x0c0c222eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2230;
P_0c0c2230: /* original fdf9, guest PC 0x0c0c2230 */
if(!s->budget--) { s->failed_pc=0x0c0c2230u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2232;
P_0c0c2232: /* original fef9, guest PC 0x0c0c2232 */
if(!s->budget--) { s->failed_pc=0x0c0c2232u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2234;
P_0c0c2234: /* original fff9, guest PC 0x0c0c2234 */
if(!s->budget--) { s->failed_pc=0x0c0c2234u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2236;
P_0c0c2236: /* original 68f6, guest PC 0x0c0c2236 */
if(!s->budget--) { s->failed_pc=0x0c0c2236u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c2238;
P_0c0c2238: /* original 69f6, guest PC 0x0c0c2238 */
if(!s->budget--) { s->failed_pc=0x0c0c2238u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c223a;
P_0c0c223a: /* original 6af6, guest PC 0x0c0c223a */
if(!s->budget--) { s->failed_pc=0x0c0c223au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c223c;
P_0c0c223c: /* original 6bf6, guest PC 0x0c0c223c */
if(!s->budget--) { s->failed_pc=0x0c0c223cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c223e;
P_0c0c223e: /* original 6cf6, guest PC 0x0c0c223e */
if(!s->budget--) { s->failed_pc=0x0c0c223eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2240;
P_0c0c2240: /* original 6df6, guest PC 0x0c0c2240 */
if(!s->budget--) { s->failed_pc=0x0c0c2240u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2242;
P_0c0c2242: /* original 000b, guest PC 0x0c0c2242 */
if(!s->budget--) { s->failed_pc=0x0c0c2242u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2244: /* original 6ef6, guest PC 0x0c0c2244 */
if(!s->budget--) { s->failed_pc=0x0c0c2244u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c2246u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2246u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
