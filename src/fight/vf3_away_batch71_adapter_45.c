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
int vf3_away_batch71_adapter_45(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b10a8u: goto P_0c0b10a8;
case 0x0c0b10aau: goto P_0c0b10aa;
case 0x0c0b10acu: goto P_0c0b10ac;
case 0x0c0b10aeu: goto P_0c0b10ae;
case 0x0c0b10b0u: goto P_0c0b10b0;
case 0x0c0b10b2u: goto P_0c0b10b2;
case 0x0c0b10b4u: goto P_0c0b10b4;
case 0x0c0b10b6u: goto P_0c0b10b6;
case 0x0c0b10b8u: goto P_0c0b10b8;
case 0x0c0b10bau: goto P_0c0b10ba;
case 0x0c0b10bcu: goto P_0c0b10bc;
case 0x0c0b10beu: goto P_0c0b10be;
case 0x0c0b10c0u: goto P_0c0b10c0;
case 0x0c0b10c2u: goto P_0c0b10c2;
case 0x0c0b10c4u: goto P_0c0b10c4;
case 0x0c0b10c6u: goto P_0c0b10c6;
case 0x0c0b10c8u: goto P_0c0b10c8;
case 0x0c0b10cau: goto P_0c0b10ca;
case 0x0c0b10ccu: goto P_0c0b10cc;
case 0x0c0b10ceu: goto P_0c0b10ce;
case 0x0c0b10d0u: goto P_0c0b10d0;
case 0x0c0b10d2u: goto P_0c0b10d2;
case 0x0c0b10d4u: goto P_0c0b10d4;
case 0x0c0b10d6u: goto P_0c0b10d6;
case 0x0c0b10d8u: goto P_0c0b10d8;
case 0x0c0b10dau: goto P_0c0b10da;
case 0x0c0b10dcu: goto P_0c0b10dc;
case 0x0c0b10deu: goto P_0c0b10de;
case 0x0c0b10e0u: goto P_0c0b10e0;
case 0x0c0b10e2u: goto P_0c0b10e2;
case 0x0c0b10e4u: goto P_0c0b10e4;
case 0x0c0b10e6u: goto P_0c0b10e6;
case 0x0c0b10e8u: goto P_0c0b10e8;
case 0x0c0b10eau: goto P_0c0b10ea;
case 0x0c0b10ecu: goto P_0c0b10ec;
case 0x0c0b10eeu: goto P_0c0b10ee;
case 0x0c0b10f0u: goto P_0c0b10f0;
case 0x0c0b10f2u: goto P_0c0b10f2;
case 0x0c0b10f4u: goto P_0c0b10f4;
case 0x0c0b10f6u: goto P_0c0b10f6;
case 0x0c0b10f8u: goto P_0c0b10f8;
case 0x0c0b10fau: goto P_0c0b10fa;
case 0x0c0b10fcu: goto P_0c0b10fc;
case 0x0c0b10feu: goto P_0c0b10fe;
case 0x0c0b1100u: goto P_0c0b1100;
case 0x0c0b1102u: goto P_0c0b1102;
case 0x0c0b1104u: goto P_0c0b1104;
case 0x0c0b1106u: goto P_0c0b1106;
case 0x0c0b1108u: goto P_0c0b1108;
case 0x0c0b110au: goto P_0c0b110a;
case 0x0c0b110cu: goto P_0c0b110c;
case 0x0c0b110eu: goto P_0c0b110e;
case 0x0c0b1110u: goto P_0c0b1110;
case 0x0c0b1112u: goto P_0c0b1112;
case 0x0c0b1114u: goto P_0c0b1114;
case 0x0c0b1116u: goto P_0c0b1116;
case 0x0c0b1118u: goto P_0c0b1118;
case 0x0c0b111au: goto P_0c0b111a;
case 0x0c0b111cu: goto P_0c0b111c;
case 0x0c0b111eu: goto P_0c0b111e;
case 0x0c0b1120u: goto P_0c0b1120;
case 0x0c0b1122u: goto P_0c0b1122;
case 0x0c0b1124u: goto P_0c0b1124;
case 0x0c0b1126u: goto P_0c0b1126;
case 0x0c0b1128u: goto P_0c0b1128;
case 0x0c0b112au: goto P_0c0b112a;
case 0x0c0b112cu: goto P_0c0b112c;
case 0x0c0b112eu: goto P_0c0b112e;
case 0x0c0b1130u: goto P_0c0b1130;
case 0x0c0b1132u: goto P_0c0b1132;
case 0x0c0b2088u: goto P_0c0b2088;
case 0x0c0b208au: goto P_0c0b208a;
case 0x0c0b208cu: goto P_0c0b208c;
case 0x0c0b208eu: goto P_0c0b208e;
case 0x0c0b2090u: goto P_0c0b2090;
case 0x0c0b2092u: goto P_0c0b2092;
case 0x0c0b2094u: goto P_0c0b2094;
case 0x0c0b2096u: goto P_0c0b2096;
case 0x0c0b2098u: goto P_0c0b2098;
case 0x0c0b209au: goto P_0c0b209a;
case 0x0c0b209cu: goto P_0c0b209c;
case 0x0c0b209eu: goto P_0c0b209e;
case 0x0c0b20a0u: goto P_0c0b20a0;
case 0x0c0b20a2u: goto P_0c0b20a2;
case 0x0c0b20a4u: goto P_0c0b20a4;
case 0x0c0b20a6u: goto P_0c0b20a6;
case 0x0c0b20a8u: goto P_0c0b20a8;
case 0x0c0b20aau: goto P_0c0b20aa;
case 0x0c0b20acu: goto P_0c0b20ac;
case 0x0c0b20aeu: goto P_0c0b20ae;
case 0x0c0b20b0u: goto P_0c0b20b0;
case 0x0c0b20b2u: goto P_0c0b20b2;
case 0x0c0b20b4u: goto P_0c0b20b4;
case 0x0c0b20b6u: goto P_0c0b20b6;
case 0x0c0b20b8u: goto P_0c0b20b8;
case 0x0c0b20bau: goto P_0c0b20ba;
case 0x0c0b20bcu: goto P_0c0b20bc;
case 0x0c0b20beu: goto P_0c0b20be;
case 0x0c0b20c0u: goto P_0c0b20c0;
case 0x0c0b20c2u: goto P_0c0b20c2;
case 0x0c0b20c4u: goto P_0c0b20c4;
case 0x0c0b20c6u: goto P_0c0b20c6;
case 0x0c0b20c8u: goto P_0c0b20c8;
case 0x0c0b20cau: goto P_0c0b20ca;
case 0x0c0b20ccu: goto P_0c0b20cc;
case 0x0c0b20ceu: goto P_0c0b20ce;
case 0x0c0b20d0u: goto P_0c0b20d0;
case 0x0c0b20d2u: goto P_0c0b20d2;
case 0x0c0b20d4u: goto P_0c0b20d4;
case 0x0c0b20d6u: goto P_0c0b20d6;
case 0x0c0b20d8u: goto P_0c0b20d8;
case 0x0c0b20dau: goto P_0c0b20da;
case 0x0c0b20dcu: goto P_0c0b20dc;
case 0x0c0b20deu: goto P_0c0b20de;
case 0x0c0b20e0u: goto P_0c0b20e0;
case 0x0c0b20e2u: goto P_0c0b20e2;
case 0x0c0b20e4u: goto P_0c0b20e4;
case 0x0c0b20e6u: goto P_0c0b20e6;
case 0x0c0b20e8u: goto P_0c0b20e8;
case 0x0c0b20eau: goto P_0c0b20ea;
case 0x0c0b20ecu: goto P_0c0b20ec;
case 0x0c0b20eeu: goto P_0c0b20ee;
case 0x0c0b20f0u: goto P_0c0b20f0;
case 0x0c0b20f2u: goto P_0c0b20f2;
case 0x0c0b20f4u: goto P_0c0b20f4;
case 0x0c0b20f6u: goto P_0c0b20f6;
case 0x0c0b20f8u: goto P_0c0b20f8;
case 0x0c0b20fau: goto P_0c0b20fa;
case 0x0c0b20fcu: goto P_0c0b20fc;
case 0x0c0b20feu: goto P_0c0b20fe;
case 0x0c0b2100u: goto P_0c0b2100;
case 0x0c0b2102u: goto P_0c0b2102;
case 0x0c0b2104u: goto P_0c0b2104;
case 0x0c0b2106u: goto P_0c0b2106;
case 0x0c0b2108u: goto P_0c0b2108;
case 0x0c0b210au: goto P_0c0b210a;
case 0x0c0b210cu: goto P_0c0b210c;
case 0x0c0b210eu: goto P_0c0b210e;
case 0x0c0b2110u: goto P_0c0b2110;
case 0x0c0b2112u: goto P_0c0b2112;
case 0x0c0b2114u: goto P_0c0b2114;
case 0x0c0b2116u: goto P_0c0b2116;
case 0x0c0b2118u: goto P_0c0b2118;
case 0x0c0b211au: goto P_0c0b211a;
case 0x0c0b211cu: goto P_0c0b211c;
case 0x0c0b211eu: goto P_0c0b211e;
case 0x0c0b2120u: goto P_0c0b2120;
case 0x0c0b2122u: goto P_0c0b2122;
case 0x0c0b2124u: goto P_0c0b2124;
case 0x0c0b2126u: goto P_0c0b2126;
case 0x0c0b2128u: goto P_0c0b2128;
case 0x0c0b212au: goto P_0c0b212a;
case 0x0c0b212cu: goto P_0c0b212c;
case 0x0c0b212eu: goto P_0c0b212e;
case 0x0c0b2130u: goto P_0c0b2130;
case 0x0c0b2132u: goto P_0c0b2132;
case 0x0c0b2134u: goto P_0c0b2134;
case 0x0c0b2136u: goto P_0c0b2136;
case 0x0c0b2138u: goto P_0c0b2138;
case 0x0c0b213au: goto P_0c0b213a;
case 0x0c0b213cu: goto P_0c0b213c;
case 0x0c0b213eu: goto P_0c0b213e;
case 0x0c0b2140u: goto P_0c0b2140;
case 0x0c0b2142u: goto P_0c0b2142;
case 0x0c0b2144u: goto P_0c0b2144;
case 0x0c0b2146u: goto P_0c0b2146;
case 0x0c0b2148u: goto P_0c0b2148;
case 0x0c0b214au: goto P_0c0b214a;
case 0x0c0b214cu: goto P_0c0b214c;
case 0x0c0b214eu: goto P_0c0b214e;
case 0x0c0b2150u: goto P_0c0b2150;
case 0x0c0b2152u: goto P_0c0b2152;
case 0x0c0b2154u: goto P_0c0b2154;
case 0x0c0b2156u: goto P_0c0b2156;
case 0x0c0b2158u: goto P_0c0b2158;
case 0x0c0b215au: goto P_0c0b215a;
case 0x0c0b215cu: goto P_0c0b215c;
case 0x0c0b215eu: goto P_0c0b215e;
case 0x0c0b2160u: goto P_0c0b2160;
case 0x0c0b2162u: goto P_0c0b2162;
case 0x0c0b2164u: goto P_0c0b2164;
case 0x0c0b2166u: goto P_0c0b2166;
case 0x0c0b2168u: goto P_0c0b2168;
case 0x0c0b216au: goto P_0c0b216a;
case 0x0c0b216cu: goto P_0c0b216c;
case 0x0c0b216eu: goto P_0c0b216e;
case 0x0c0b2170u: goto P_0c0b2170;
case 0x0c0b2172u: goto P_0c0b2172;
case 0x0c0b2174u: goto P_0c0b2174;
case 0x0c0b2176u: goto P_0c0b2176;
case 0x0c0b2178u: goto P_0c0b2178;
case 0x0c0b217au: goto P_0c0b217a;
case 0x0c0b217cu: goto P_0c0b217c;
case 0x0c0b217eu: goto P_0c0b217e;
case 0x0c0b2180u: goto P_0c0b2180;
case 0x0c0b2182u: goto P_0c0b2182;
case 0x0c0b2184u: goto P_0c0b2184;
case 0x0c0b2186u: goto P_0c0b2186;
case 0x0c0b2188u: goto P_0c0b2188;
case 0x0c0b218au: goto P_0c0b218a;
case 0x0c0b218cu: goto P_0c0b218c;
case 0x0c0b218eu: goto P_0c0b218e;
case 0x0c0b2190u: goto P_0c0b2190;
case 0x0c0b2192u: goto P_0c0b2192;
case 0x0c0b2194u: goto P_0c0b2194;
case 0x0c0b2196u: goto P_0c0b2196;
case 0x0c0b2198u: goto P_0c0b2198;
case 0x0c0b219au: goto P_0c0b219a;
case 0x0c0b219cu: goto P_0c0b219c;
case 0x0c0b219eu: goto P_0c0b219e;
case 0x0c0b21a0u: goto P_0c0b21a0;
case 0x0c0b21a2u: goto P_0c0b21a2;
case 0x0c0b21a4u: goto P_0c0b21a4;
case 0x0c0b21a6u: goto P_0c0b21a6;
case 0x0c0b21a8u: goto P_0c0b21a8;
case 0x0c0b21aau: goto P_0c0b21aa;
case 0x0c0b21acu: goto P_0c0b21ac;
case 0x0c0b21aeu: goto P_0c0b21ae;
case 0x0c0b21b0u: goto P_0c0b21b0;
case 0x0c0b21b2u: goto P_0c0b21b2;
case 0x0c0b21b4u: goto P_0c0b21b4;
case 0x0c0b21b6u: goto P_0c0b21b6;
case 0x0c0b21b8u: goto P_0c0b21b8;
case 0x0c0b21bau: goto P_0c0b21ba;
case 0x0c0b21bcu: goto P_0c0b21bc;
case 0x0c0b21beu: goto P_0c0b21be;
case 0x0c0b21c0u: goto P_0c0b21c0;
case 0x0c0b21c2u: goto P_0c0b21c2;
case 0x0c0b21c4u: goto P_0c0b21c4;
case 0x0c0b21c6u: goto P_0c0b21c6;
case 0x0c0b21c8u: goto P_0c0b21c8;
case 0x0c0b21cau: goto P_0c0b21ca;
case 0x0c0b21ccu: goto P_0c0b21cc;
case 0x0c0b21ecu: goto P_0c0b21ec;
case 0x0c0b21eeu: goto P_0c0b21ee;
case 0x0c0b21f0u: goto P_0c0b21f0;
case 0x0c0b21f2u: goto P_0c0b21f2;
case 0x0c0b21f4u: goto P_0c0b21f4;
case 0x0c0b21f6u: goto P_0c0b21f6;
case 0x0c0b21f8u: goto P_0c0b21f8;
case 0x0c0b21fau: goto P_0c0b21fa;
case 0x0c0b21fcu: goto P_0c0b21fc;
case 0x0c0b21feu: goto P_0c0b21fe;
case 0x0c0b2200u: goto P_0c0b2200;
case 0x0c0b2202u: goto P_0c0b2202;
case 0x0c0b2204u: goto P_0c0b2204;
case 0x0c0b2206u: goto P_0c0b2206;
case 0x0c0b2208u: goto P_0c0b2208;
case 0x0c0b220au: goto P_0c0b220a;
case 0x0c0b220cu: goto P_0c0b220c;
case 0x0c0b220eu: goto P_0c0b220e;
case 0x0c0b2210u: goto P_0c0b2210;
case 0x0c0b2212u: goto P_0c0b2212;
case 0x0c0b2214u: goto P_0c0b2214;
case 0x0c0b2216u: goto P_0c0b2216;
case 0x0c0b2218u: goto P_0c0b2218;
case 0x0c0b221au: goto P_0c0b221a;
case 0x0c0b221cu: goto P_0c0b221c;
case 0x0c0b221eu: goto P_0c0b221e;
case 0x0c0b2220u: goto P_0c0b2220;
case 0x0c0b2222u: goto P_0c0b2222;
case 0x0c0b2224u: goto P_0c0b2224;
case 0x0c0b2226u: goto P_0c0b2226;
case 0x0c0b2228u: goto P_0c0b2228;
case 0x0c0b222au: goto P_0c0b222a;
case 0x0c0b222cu: goto P_0c0b222c;
case 0x0c0b222eu: goto P_0c0b222e;
case 0x0c0b2230u: goto P_0c0b2230;
case 0x0c0b2232u: goto P_0c0b2232;
case 0x0c0b2234u: goto P_0c0b2234;
case 0x0c0b2236u: goto P_0c0b2236;
case 0x0c0b2238u: goto P_0c0b2238;
case 0x0c0b223au: goto P_0c0b223a;
case 0x0c0b223cu: goto P_0c0b223c;
case 0x0c0b223eu: goto P_0c0b223e;
case 0x0c0b2240u: goto P_0c0b2240;
case 0x0c0b2242u: goto P_0c0b2242;
case 0x0c0b2244u: goto P_0c0b2244;
case 0x0c0b2246u: goto P_0c0b2246;
case 0x0c0b2248u: goto P_0c0b2248;
case 0x0c0b224au: goto P_0c0b224a;
case 0x0c0b224cu: goto P_0c0b224c;
case 0x0c0b224eu: goto P_0c0b224e;
case 0x0c0b2250u: goto P_0c0b2250;
case 0x0c0b2252u: goto P_0c0b2252;
case 0x0c0b2254u: goto P_0c0b2254;
case 0x0c0b2256u: goto P_0c0b2256;
case 0x0c0b2258u: goto P_0c0b2258;
case 0x0c0b225au: goto P_0c0b225a;
case 0x0c0b225cu: goto P_0c0b225c;
case 0x0c0b225eu: goto P_0c0b225e;
case 0x0c0b2260u: goto P_0c0b2260;
case 0x0c0b2262u: goto P_0c0b2262;
case 0x0c0b2264u: goto P_0c0b2264;
case 0x0c0b2266u: goto P_0c0b2266;
case 0x0c0b2268u: goto P_0c0b2268;
case 0x0c0b226au: goto P_0c0b226a;
case 0x0c0b226cu: goto P_0c0b226c;
case 0x0c0b226eu: goto P_0c0b226e;
case 0x0c0b2270u: goto P_0c0b2270;
case 0x0c0b2272u: goto P_0c0b2272;
case 0x0c0b2274u: goto P_0c0b2274;
case 0x0c0b2276u: goto P_0c0b2276;
case 0x0c0b2278u: goto P_0c0b2278;
case 0x0c0b227au: goto P_0c0b227a;
case 0x0c0b227cu: goto P_0c0b227c;
case 0x0c0b227eu: goto P_0c0b227e;
case 0x0c0b2280u: goto P_0c0b2280;
case 0x0c0b2282u: goto P_0c0b2282;
case 0x0c0b2284u: goto P_0c0b2284;
case 0x0c0b2286u: goto P_0c0b2286;
case 0x0c0b2288u: goto P_0c0b2288;
case 0x0c0b228au: goto P_0c0b228a;
case 0x0c0b228cu: goto P_0c0b228c;
case 0x0c0b228eu: goto P_0c0b228e;
case 0x0c0b2290u: goto P_0c0b2290;
case 0x0c0b2292u: goto P_0c0b2292;
case 0x0c0b2294u: goto P_0c0b2294;
case 0x0c0b2296u: goto P_0c0b2296;
case 0x0c0b2298u: goto P_0c0b2298;
case 0x0c0b229au: goto P_0c0b229a;
case 0x0c0b229cu: goto P_0c0b229c;
case 0x0c0b229eu: goto P_0c0b229e;
case 0x0c0b22a0u: goto P_0c0b22a0;
case 0x0c0b22a2u: goto P_0c0b22a2;
case 0x0c0b22a4u: goto P_0c0b22a4;
case 0x0c0b22a6u: goto P_0c0b22a6;
case 0x0c0b22a8u: goto P_0c0b22a8;
case 0x0c0b22aau: goto P_0c0b22aa;
case 0x0c0b22acu: goto P_0c0b22ac;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b10a8: /* original 2fe6, guest PC 0x0c0b10a8 */
if(!s->budget--) { s->failed_pc=0x0c0b10a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b10aa;
P_0c0b10aa: /* original 4f22, guest PC 0x0c0b10aa */
if(!s->budget--) { s->failed_pc=0x0c0b10aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b10ac;
P_0c0b10ac: /* original 7ff0, guest PC 0x0c0b10ac */
if(!s->budget--) { s->failed_pc=0x0c0b10acu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0b10ae;
P_0c0b10ae: /* original 1f52, guest PC 0x0c0b10ae */
if(!s->budget--) { s->failed_pc=0x0c0b10aeu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0b10b0;
P_0c0b10b0: /* original 1f63, guest PC 0x0c0b10b0 */
if(!s->budget--) { s->failed_pc=0x0c0b10b0u; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c0b10b2;
P_0c0b10b2: /* original 53f2, guest PC 0x0c0b10b2 */
if(!s->budget--) { s->failed_pc=0x0c0b10b2u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0b10b4;
P_0c0b10b4: /* original d24a, guest PC 0x0c0b10b4 */
if(!s->budget--) { s->failed_pc=0x0c0b10b4u; return 0; }
r[2]=read(ram,0x0c0b11e0u,4);
goto P_0c0b10b6;
P_0c0b10b6: /* original 6132, guest PC 0x0c0b10b6 */
if(!s->budget--) { s->failed_pc=0x0c0b10b6u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0b10b8;
P_0c0b10b8: /* original 2128, guest PC 0x0c0b10b8 */
if(!s->budget--) { s->failed_pc=0x0c0b10b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0b10ba;
P_0c0b10ba: /* original 8d37, guest PC 0x0c0b10ba */
if(!s->budget--) { s->failed_pc=0x0c0b10bau; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c0b112c; }
goto P_0c0b10be;
P_0c0b10bc: /* original 6e43, guest PC 0x0c0b10bc */
if(!s->budget--) { s->failed_pc=0x0c0b10bcu; return 0; }
r[14]=r[4];
goto P_0c0b10be;
P_0c0b10be: /* original 9087, guest PC 0x0c0b10be */
if(!s->budget--) { s->failed_pc=0x0c0b10beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d0u,2);
goto P_0c0b10c0;
P_0c0b10c0: /* original 00ec, guest PC 0x0c0b10c0 */
if(!s->budget--) { s->failed_pc=0x0c0b10c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b10c2;
P_0c0b10c2: /* original 600c, guest PC 0x0c0b10c2 */
if(!s->budget--) { s->failed_pc=0x0c0b10c2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0b10c4;
P_0c0b10c4: /* original c801, guest PC 0x0c0b10c4 */
if(!s->budget--) { s->failed_pc=0x0c0b10c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0b10c6;
P_0c0b10c6: /* original 8b1a, guest PC 0x0c0b10c6 */
if(!s->budget--) { s->failed_pc=0x0c0b10c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b10fe; }
goto P_0c0b10c8;
P_0c0b10c8: /* original 85ef, guest PC 0x0c0b10c8 */
if(!s->budget--) { s->failed_pc=0x0c0b10c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0b10ca;
P_0c0b10ca: /* original 66f3, guest PC 0x0c0b10ca */
if(!s->budget--) { s->failed_pc=0x0c0b10cau; return 0; }
r[6]=r[15];
goto P_0c0b10cc;
P_0c0b10cc: /* original 7604, guest PC 0x0c0b10cc */
if(!s->budget--) { s->failed_pc=0x0c0b10ccu; return 0; }
r[6]+=0x00000004u;
goto P_0c0b10ce;
P_0c0b10ce: /* original 6403, guest PC 0x0c0b10ce */
if(!s->budget--) { s->failed_pc=0x0c0b10ceu; return 0; }
r[4]=r[0];
goto P_0c0b10d0;
P_0c0b10d0: /* original 907f, guest PC 0x0c0b10d0 */
if(!s->budget--) { s->failed_pc=0x0c0b10d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d2u,2);
goto P_0c0b10d2;
P_0c0b10d2: /* original f3e6, guest PC 0x0c0b10d2 */
if(!s->budget--) { s->failed_pc=0x0c0b10d2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0b10d4;
P_0c0b10d4: /* original ff3a, guest PC 0x0c0b10d4 */
if(!s->budget--) { s->failed_pc=0x0c0b10d4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0b10d6;
P_0c0b10d6: /* original 907d, guest PC 0x0c0b10d6 */
if(!s->budget--) { s->failed_pc=0x0c0b10d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d4u,2);
goto P_0c0b10d8;
P_0c0b10d8: /* original f3e6, guest PC 0x0c0b10d8 */
if(!s->budget--) { s->failed_pc=0x0c0b10d8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0b10da;
P_0c0b10da: /* original e004, guest PC 0x0c0b10da */
if(!s->budget--) { s->failed_pc=0x0c0b10dau; return 0; }
r[0]=0x00000004u;
goto P_0c0b10dc;
P_0c0b10dc: /* original ff37, guest PC 0x0c0b10dc */
if(!s->budget--) { s->failed_pc=0x0c0b10dcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0b10de;
P_0c0b10de: /* original d341, guest PC 0x0c0b10de */
if(!s->budget--) { s->failed_pc=0x0c0b10deu; return 0; }
r[3]=read(ram,0x0c0b11e4u,4);
goto P_0c0b10e0;
P_0c0b10e0: /* original 430b, guest PC 0x0c0b10e0 */
if(!s->budget--) { s->failed_pc=0x0c0b10e0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b10e4u;
r[5]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b10e4u) { target=s->pc; goto dispatch; }
goto P_0c0b10e4;
P_0c0b10e2: /* original 65f3, guest PC 0x0c0b10e2 */
if(!s->budget--) { s->failed_pc=0x0c0b10e2u; return 0; }
r[5]=r[15];
goto P_0c0b10e4;
P_0c0b10e4: /* original e010, guest PC 0x0c0b10e4 */
if(!s->budget--) { s->failed_pc=0x0c0b10e4u; return 0; }
r[0]=0x00000010u;
goto P_0c0b10e6;
P_0c0b10e6: /* original f3f8, guest PC 0x0c0b10e6 */
if(!s->budget--) { s->failed_pc=0x0c0b10e6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0b10e8;
P_0c0b10e8: /* original f4e6, guest PC 0x0c0b10e8 */
if(!s->budget--) { s->failed_pc=0x0c0b10e8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0b10ea;
P_0c0b10ea: /* original e018, guest PC 0x0c0b10ea */
if(!s->budget--) { s->failed_pc=0x0c0b10eau; return 0; }
r[0]=0x00000018u;
goto P_0c0b10ec;
P_0c0b10ec: /* original f5e6, guest PC 0x0c0b10ec */
if(!s->budget--) { s->failed_pc=0x0c0b10ecu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0b10ee;
P_0c0b10ee: /* original e004, guest PC 0x0c0b10ee */
if(!s->budget--) { s->failed_pc=0x0c0b10eeu; return 0; }
r[0]=0x00000004u;
goto P_0c0b10f0;
P_0c0b10f0: /* original f2f6, guest PC 0x0c0b10f0 */
if(!s->budget--) { s->failed_pc=0x0c0b10f0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0b10f2;
P_0c0b10f2: /* original f431, guest PC 0x0c0b10f2 */
if(!s->budget--) { s->failed_pc=0x0c0b10f2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0b10f4;
P_0c0b10f4: /* original e010, guest PC 0x0c0b10f4 */
if(!s->budget--) { s->failed_pc=0x0c0b10f4u; return 0; }
r[0]=0x00000010u;
goto P_0c0b10f6;
P_0c0b10f6: /* original f521, guest PC 0x0c0b10f6 */
if(!s->budget--) { s->failed_pc=0x0c0b10f6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0b10f8;
P_0c0b10f8: /* original fe47, guest PC 0x0c0b10f8 */
if(!s->budget--) { s->failed_pc=0x0c0b10f8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0b10fa;
P_0c0b10fa: /* original e018, guest PC 0x0c0b10fa */
if(!s->budget--) { s->failed_pc=0x0c0b10fau; return 0; }
r[0]=0x00000018u;
goto P_0c0b10fc;
P_0c0b10fc: /* original fe57, guest PC 0x0c0b10fc */
if(!s->budget--) { s->failed_pc=0x0c0b10fcu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0b10fe;
P_0c0b10fe: /* original 906a, guest PC 0x0c0b10fe */
if(!s->budget--) { s->failed_pc=0x0c0b10feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d6u,2);
goto P_0c0b1100;
P_0c0b1100: /* original f3e6, guest PC 0x0c0b1100 */
if(!s->budget--) { s->failed_pc=0x0c0b1100u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0b1102;
P_0c0b1102: /* original e014, guest PC 0x0c0b1102 */
if(!s->budget--) { s->failed_pc=0x0c0b1102u; return 0; }
r[0]=0x00000014u;
goto P_0c0b1104;
P_0c0b1104: /* original ff3a, guest PC 0x0c0b1104 */
if(!s->budget--) { s->failed_pc=0x0c0b1104u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0b1106;
P_0c0b1106: /* original f3e6, guest PC 0x0c0b1106 */
if(!s->budget--) { s->failed_pc=0x0c0b1106u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0b1108;
P_0c0b1108: /* original e004, guest PC 0x0c0b1108 */
if(!s->budget--) { s->failed_pc=0x0c0b1108u; return 0; }
r[0]=0x00000004u;
goto P_0c0b110a;
P_0c0b110a: /* original ff37, guest PC 0x0c0b110a */
if(!s->budget--) { s->failed_pc=0x0c0b110au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0b110c;
P_0c0b110c: /* original f2f8, guest PC 0x0c0b110c */
if(!s->budget--) { s->failed_pc=0x0c0b110cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0b110e;
P_0c0b110e: /* original f231, guest PC 0x0c0b110e */
if(!s->budget--) { s->failed_pc=0x0c0b110eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0b1110;
P_0c0b1110: /* original ff2a, guest PC 0x0c0b1110 */
if(!s->budget--) { s->failed_pc=0x0c0b1110u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0b1112;
P_0c0b1112: /* original 9061, guest PC 0x0c0b1112 */
if(!s->budget--) { s->failed_pc=0x0c0b1112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b11d8u,2);
goto P_0c0b1114;
P_0c0b1114: /* original f32c, guest PC 0x0c0b1114 */
if(!s->budget--) { s->failed_pc=0x0c0b1114u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0b1116;
P_0c0b1116: /* original fe37, guest PC 0x0c0b1116 */
if(!s->budget--) { s->failed_pc=0x0c0b1116u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0b1118;
P_0c0b1118: /* original 53f2, guest PC 0x0c0b1118 */
if(!s->budget--) { s->failed_pc=0x0c0b1118u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0b111a;
P_0c0b111a: /* original d233, guest PC 0x0c0b111a */
if(!s->budget--) { s->failed_pc=0x0c0b111au; return 0; }
r[2]=read(ram,0x0c0b11e8u,4);
goto P_0c0b111c;
P_0c0b111c: /* original 6132, guest PC 0x0c0b111c */
if(!s->budget--) { s->failed_pc=0x0c0b111cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0b111e;
P_0c0b111e: /* original 2129, guest PC 0x0c0b111e */
if(!s->budget--) { s->failed_pc=0x0c0b111eu; return 0; }
r[1]&=r[2];
goto P_0c0b1120;
P_0c0b1120: /* original 2312, guest PC 0x0c0b1120 */
if(!s->budget--) { s->failed_pc=0x0c0b1120u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0b1122;
P_0c0b1122: /* original 53f3, guest PC 0x0c0b1122 */
if(!s->budget--) { s->failed_pc=0x0c0b1122u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0b1124;
P_0c0b1124: /* original d131, guest PC 0x0c0b1124 */
if(!s->budget--) { s->failed_pc=0x0c0b1124u; return 0; }
r[1]=read(ram,0x0c0b11ecu,4);
goto P_0c0b1126;
P_0c0b1126: /* original 6032, guest PC 0x0c0b1126 */
if(!s->budget--) { s->failed_pc=0x0c0b1126u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0b1128;
P_0c0b1128: /* original 2019, guest PC 0x0c0b1128 */
if(!s->budget--) { s->failed_pc=0x0c0b1128u; return 0; }
r[0]&=r[1];
goto P_0c0b112a;
P_0c0b112a: /* original 2302, guest PC 0x0c0b112a */
if(!s->budget--) { s->failed_pc=0x0c0b112au; return 0; }
write(ram,r[3],r[0],4);
goto P_0c0b112c;
P_0c0b112c: /* original 7f10, guest PC 0x0c0b112c */
if(!s->budget--) { s->failed_pc=0x0c0b112cu; return 0; }
r[15]+=0x00000010u;
goto P_0c0b112e;
P_0c0b112e: /* original 4f26, guest PC 0x0c0b112e */
if(!s->budget--) { s->failed_pc=0x0c0b112eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1130;
P_0c0b1130: /* original 000b, guest PC 0x0c0b1130 */
if(!s->budget--) { s->failed_pc=0x0c0b1130u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1132: /* original 6ef6, guest PC 0x0c0b1132 */
if(!s->budget--) { s->failed_pc=0x0c0b1132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b1134u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1134u; return 0; } return 1;
P_0c0b2088: /* original 2fe6, guest PC 0x0c0b2088 */
if(!s->budget--) { s->failed_pc=0x0c0b2088u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b208a;
P_0c0b208a: /* original 2fd6, guest PC 0x0c0b208a */
if(!s->budget--) { s->failed_pc=0x0c0b208au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b208c;
P_0c0b208c: /* original 2fc6, guest PC 0x0c0b208c */
if(!s->budget--) { s->failed_pc=0x0c0b208cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b208e;
P_0c0b208e: /* original 6c43, guest PC 0x0c0b208e */
if(!s->budget--) { s->failed_pc=0x0c0b208eu; return 0; }
r[12]=r[4];
goto P_0c0b2090;
P_0c0b2090: /* original 2fb6, guest PC 0x0c0b2090 */
if(!s->budget--) { s->failed_pc=0x0c0b2090u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2092;
P_0c0b2092: /* original 2fa6, guest PC 0x0c0b2092 */
if(!s->budget--) { s->failed_pc=0x0c0b2092u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2094;
P_0c0b2094: /* original 2f96, guest PC 0x0c0b2094 */
if(!s->budget--) { s->failed_pc=0x0c0b2094u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2096;
P_0c0b2096: /* original 84c4, guest PC 0x0c0b2096 */
if(!s->budget--) { s->failed_pc=0x0c0b2096u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+4,1);
goto P_0c0b2098;
P_0c0b2098: /* original de50, guest PC 0x0c0b2098 */
if(!s->budget--) { s->failed_pc=0x0c0b2098u; return 0; }
r[14]=read(ram,0x0c0b21dcu,4);
goto P_0c0b209a;
P_0c0b209a: /* original 690c, guest PC 0x0c0b209a */
if(!s->budget--) { s->failed_pc=0x0c0b209au; return 0; }
r[9]=r[0]&255u;
goto P_0c0b209c;
P_0c0b209c: /* original 9297, guest PC 0x0c0b209c */
if(!s->budget--) { s->failed_pc=0x0c0b209cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21ceu,2);
goto P_0c0b209e;
P_0c0b209e: /* original 6d93, guest PC 0x0c0b209e */
if(!s->budget--) { s->failed_pc=0x0c0b209eu; return 0; }
r[13]=r[9];
goto P_0c0b20a0;
P_0c0b20a0: /* original e060, guest PC 0x0c0b20a0 */
if(!s->budget--) { s->failed_pc=0x0c0b20a0u; return 0; }
r[0]=0x00000060u;
goto P_0c0b20a2;
P_0c0b20a2: /* original 32ec, guest PC 0x0c0b20a2 */
if(!s->budget--) { s->failed_pc=0x0c0b20a2u; return 0; }
r[2]+=r[14];
goto P_0c0b20a4;
P_0c0b20a4: /* original 03cc, guest PC 0x0c0b20a4 */
if(!s->budget--) { s->failed_pc=0x0c0b20a4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0b20a6;
P_0c0b20a6: /* original 4d08, guest PC 0x0c0b20a6 */
if(!s->budget--) { s->failed_pc=0x0c0b20a6u; return 0; }
r[13]<<=2;
goto P_0c0b20a8;
P_0c0b20a8: /* original 4f22, guest PC 0x0c0b20a8 */
if(!s->budget--) { s->failed_pc=0x0c0b20a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b20aa;
P_0c0b20aa: /* original 32dc, guest PC 0x0c0b20aa */
if(!s->budget--) { s->failed_pc=0x0c0b20aau; return 0; }
r[2]+=r[13];
goto P_0c0b20ac;
P_0c0b20ac: /* original 6122, guest PC 0x0c0b20ac */
if(!s->budget--) { s->failed_pc=0x0c0b20acu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0b20ae;
P_0c0b20ae: /* original 633c, guest PC 0x0c0b20ae */
if(!s->budget--) { s->failed_pc=0x0c0b20aeu; return 0; }
r[3]=r[3]&255u;
goto P_0c0b20b0;
P_0c0b20b0: /* original 7ffc, guest PC 0x0c0b20b0 */
if(!s->budget--) { s->failed_pc=0x0c0b20b0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0b20b2;
P_0c0b20b2: /* original 3310, guest PC 0x0c0b20b2 */
if(!s->budget--) { s->failed_pc=0x0c0b20b2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0b20b4;
P_0c0b20b4: /* original 8b01, guest PC 0x0c0b20b4 */
if(!s->budget--) { s->failed_pc=0x0c0b20b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b20ba; }
goto P_0c0b20b6;
P_0c0b20b6: /* original a0f1, guest PC 0x0c0b20b6 */
if(!s->budget--) { s->failed_pc=0x0c0b20b6u; return 0; }
goto P_0c0b229c;
P_0c0b20b8: /* original 0009, guest PC 0x0c0b20b8 */
if(!s->budget--) { s->failed_pc=0x0c0b20b8u; return 0; }
goto P_0c0b20ba;
P_0c0b20ba: /* original 9388, guest PC 0x0c0b20ba */
if(!s->budget--) { s->failed_pc=0x0c0b20bau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21ceu,2);
goto P_0c0b20bc;
P_0c0b20bc: /* original e21a, guest PC 0x0c0b20bc */
if(!s->budget--) { s->failed_pc=0x0c0b20bcu; return 0; }
r[2]=0x0000001au;
goto P_0c0b20be;
P_0c0b20be: /* original db48, guest PC 0x0c0b20be */
if(!s->budget--) { s->failed_pc=0x0c0b20beu; return 0; }
r[11]=read(ram,0x0c0b21e0u,4);
goto P_0c0b20c0;
P_0c0b20c0: /* original 33ec, guest PC 0x0c0b20c0 */
if(!s->budget--) { s->failed_pc=0x0c0b20c0u; return 0; }
r[3]+=r[14];
goto P_0c0b20c2;
P_0c0b20c2: /* original 33dc, guest PC 0x0c0b20c2 */
if(!s->budget--) { s->failed_pc=0x0c0b20c2u; return 0; }
r[3]+=r[13];
goto P_0c0b20c4;
P_0c0b20c4: /* original 6132, guest PC 0x0c0b20c4 */
if(!s->budget--) { s->failed_pc=0x0c0b20c4u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0b20c6;
P_0c0b20c6: /* original 3126, guest PC 0x0c0b20c6 */
if(!s->budget--) { s->failed_pc=0x0c0b20c6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c0b20c8;
P_0c0b20c8: /* original 8969, guest PC 0x0c0b20c8 */
if(!s->budget--) { s->failed_pc=0x0c0b20c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b219e; }
goto P_0c0b20ca;
P_0c0b20ca: /* original 9380, guest PC 0x0c0b20ca */
if(!s->budget--) { s->failed_pc=0x0c0b20cau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21ceu,2);
goto P_0c0b20cc;
P_0c0b20cc: /* original 33ec, guest PC 0x0c0b20cc */
if(!s->budget--) { s->failed_pc=0x0c0b20ccu; return 0; }
r[3]+=r[14];
goto P_0c0b20ce;
P_0c0b20ce: /* original 33dc, guest PC 0x0c0b20ce */
if(!s->budget--) { s->failed_pc=0x0c0b20ceu; return 0; }
r[3]+=r[13];
goto P_0c0b20d0;
P_0c0b20d0: /* original 6332, guest PC 0x0c0b20d0 */
if(!s->budget--) { s->failed_pc=0x0c0b20d0u; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c0b20d2;
P_0c0b20d2: /* original 6233, guest PC 0x0c0b20d2 */
if(!s->budget--) { s->failed_pc=0x0c0b20d2u; return 0; }
r[2]=r[3];
goto P_0c0b20d4;
P_0c0b20d4: /* original 4308, guest PC 0x0c0b20d4 */
if(!s->budget--) { s->failed_pc=0x0c0b20d4u; return 0; }
r[3]<<=2;
goto P_0c0b20d6;
P_0c0b20d6: /* original 4300, guest PC 0x0c0b20d6 */
if(!s->budget--) { s->failed_pc=0x0c0b20d6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0b20d8;
P_0c0b20d8: /* original 332c, guest PC 0x0c0b20d8 */
if(!s->budget--) { s->failed_pc=0x0c0b20d8u; return 0; }
r[3]+=r[2];
goto P_0c0b20da;
P_0c0b20da: /* original 4308, guest PC 0x0c0b20da */
if(!s->budget--) { s->failed_pc=0x0c0b20dau; return 0; }
r[3]<<=2;
goto P_0c0b20dc;
P_0c0b20dc: /* original 33bc, guest PC 0x0c0b20dc */
if(!s->budget--) { s->failed_pc=0x0c0b20dcu; return 0; }
r[3]+=r[11];
goto P_0c0b20de;
P_0c0b20de: /* original 5133, guest PC 0x0c0b20de */
if(!s->budget--) { s->failed_pc=0x0c0b20deu; return 0; }
r[1]=read(ram,r[3]+12,4);
goto P_0c0b20e0;
P_0c0b20e0: /* original 6313, guest PC 0x0c0b20e0 */
if(!s->budget--) { s->failed_pc=0x0c0b20e0u; return 0; }
r[3]=r[1];
goto P_0c0b20e2;
P_0c0b20e2: /* original 430b, guest PC 0x0c0b20e2 */
if(!s->budget--) { s->failed_pc=0x0c0b20e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b20e6u;
write(ram,r[15],r[1],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b20e6u) { target=s->pc; goto dispatch; }
goto P_0c0b20e6;
P_0c0b20e4: /* original 2f12, guest PC 0x0c0b20e4 */
if(!s->budget--) { s->failed_pc=0x0c0b20e4u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0b20e6;
P_0c0b20e6: /* original 9a72, guest PC 0x0c0b20e6 */
if(!s->budget--) { s->failed_pc=0x0c0b20e6u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21ceu,2);
goto P_0c0b20e8;
P_0c0b20e8: /* original 3aec, guest PC 0x0c0b20e8 */
if(!s->budget--) { s->failed_pc=0x0c0b20e8u; return 0; }
r[10]+=r[14];
goto P_0c0b20ea;
P_0c0b20ea: /* original 3adc, guest PC 0x0c0b20ea */
if(!s->budget--) { s->failed_pc=0x0c0b20eau; return 0; }
r[10]+=r[13];
goto P_0c0b20ec;
P_0c0b20ec: /* original 6aa2, guest PC 0x0c0b20ec */
if(!s->budget--) { s->failed_pc=0x0c0b20ecu; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c0b20ee;
P_0c0b20ee: /* original 63a3, guest PC 0x0c0b20ee */
if(!s->budget--) { s->failed_pc=0x0c0b20eeu; return 0; }
r[3]=r[10];
goto P_0c0b20f0;
P_0c0b20f0: /* original 4a08, guest PC 0x0c0b20f0 */
if(!s->budget--) { s->failed_pc=0x0c0b20f0u; return 0; }
r[10]<<=2;
goto P_0c0b20f2;
P_0c0b20f2: /* original 4a00, guest PC 0x0c0b20f2 */
if(!s->budget--) { s->failed_pc=0x0c0b20f2u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c0b20f4;
P_0c0b20f4: /* original 3a3c, guest PC 0x0c0b20f4 */
if(!s->budget--) { s->failed_pc=0x0c0b20f4u; return 0; }
r[10]+=r[3];
goto P_0c0b20f6;
P_0c0b20f6: /* original 4a08, guest PC 0x0c0b20f6 */
if(!s->budget--) { s->failed_pc=0x0c0b20f6u; return 0; }
r[10]<<=2;
goto P_0c0b20f8;
P_0c0b20f8: /* original 3abc, guest PC 0x0c0b20f8 */
if(!s->budget--) { s->failed_pc=0x0c0b20f8u; return 0; }
r[10]+=r[11];
goto P_0c0b20fa;
P_0c0b20fa: /* original 5aa8, guest PC 0x0c0b20fa */
if(!s->budget--) { s->failed_pc=0x0c0b20fau; return 0; }
r[10]=read(ram,r[10]+32,4);
goto P_0c0b20fc;
P_0c0b20fc: /* original 2aa8, guest PC 0x0c0b20fc */
if(!s->budget--) { s->failed_pc=0x0c0b20fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0b20fe;
P_0c0b20fe: /* original 8901, guest PC 0x0c0b20fe */
if(!s->budget--) { s->failed_pc=0x0c0b20feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b2104; }
goto P_0c0b2100;
P_0c0b2100: /* original 4a0b, guest PC 0x0c0b2100 */
if(!s->budget--) { s->failed_pc=0x0c0b2100u; return 0; }
target=r[10];
r[16]=code_base|0x0c0b2104u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2104u) { target=s->pc; goto dispatch; }
goto P_0c0b2104;
P_0c0b2102: /* original 0009, guest PC 0x0c0b2102 */
if(!s->budget--) { s->failed_pc=0x0c0b2102u; return 0; }
goto P_0c0b2104;
P_0c0b2104: /* original da37, guest PC 0x0c0b2104 */
if(!s->budget--) { s->failed_pc=0x0c0b2104u; return 0; }
r[10]=read(ram,0x0c0b21e4u,4);
goto P_0c0b2106;
P_0c0b2106: /* original 2998, guest PC 0x0c0b2106 */
if(!s->budget--) { s->failed_pc=0x0c0b2106u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0b2108;
P_0c0b2108: /* original 8b33, guest PC 0x0c0b2108 */
if(!s->budget--) { s->failed_pc=0x0c0b2108u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b2172; }
goto P_0c0b210a;
P_0c0b210a: /* original e060, guest PC 0x0c0b210a */
if(!s->budget--) { s->failed_pc=0x0c0b210au; return 0; }
r[0]=0x00000060u;
goto P_0c0b210c;
P_0c0b210c: /* original 02cc, guest PC 0x0c0b210c */
if(!s->budget--) { s->failed_pc=0x0c0b210cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0b210e;
P_0c0b210e: /* original 905f, guest PC 0x0c0b210e */
if(!s->budget--) { s->failed_pc=0x0c0b210eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d0u,2);
goto P_0c0b2110;
P_0c0b2110: /* original 622c, guest PC 0x0c0b2110 */
if(!s->budget--) { s->failed_pc=0x0c0b2110u; return 0; }
r[2]=r[2]&255u;
goto P_0c0b2112;
P_0c0b2112: /* original 03ee, guest PC 0x0c0b2112 */
if(!s->budget--) { s->failed_pc=0x0c0b2112u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0b2114;
P_0c0b2114: /* original 3230, guest PC 0x0c0b2114 */
if(!s->budget--) { s->failed_pc=0x0c0b2114u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0b2116;
P_0c0b2116: /* original 8b2c, guest PC 0x0c0b2116 */
if(!s->budget--) { s->failed_pc=0x0c0b2116u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b2172; }
goto P_0c0b2118;
P_0c0b2118: /* original 01ee, guest PC 0x0c0b2118 */
if(!s->budget--) { s->failed_pc=0x0c0b2118u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0b211a;
P_0c0b211a: /* original 6313, guest PC 0x0c0b211a */
if(!s->budget--) { s->failed_pc=0x0c0b211au; return 0; }
r[3]=r[1];
goto P_0c0b211c;
P_0c0b211c: /* original 4108, guest PC 0x0c0b211c */
if(!s->budget--) { s->failed_pc=0x0c0b211cu; return 0; }
r[1]<<=2;
goto P_0c0b211e;
P_0c0b211e: /* original 4100, guest PC 0x0c0b211e */
if(!s->budget--) { s->failed_pc=0x0c0b211eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0b2120;
P_0c0b2120: /* original 313c, guest PC 0x0c0b2120 */
if(!s->budget--) { s->failed_pc=0x0c0b2120u; return 0; }
r[1]+=r[3];
goto P_0c0b2122;
P_0c0b2122: /* original 4108, guest PC 0x0c0b2122 */
if(!s->budget--) { s->failed_pc=0x0c0b2122u; return 0; }
r[1]<<=2;
goto P_0c0b2124;
P_0c0b2124: /* original 31bc, guest PC 0x0c0b2124 */
if(!s->budget--) { s->failed_pc=0x0c0b2124u; return 0; }
r[1]+=r[11];
goto P_0c0b2126;
P_0c0b2126: /* original 5313, guest PC 0x0c0b2126 */
if(!s->budget--) { s->failed_pc=0x0c0b2126u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0b2128;
P_0c0b2128: /* original 6233, guest PC 0x0c0b2128 */
if(!s->budget--) { s->failed_pc=0x0c0b2128u; return 0; }
r[2]=r[3];
goto P_0c0b212a;
P_0c0b212a: /* original 420b, guest PC 0x0c0b212a */
if(!s->budget--) { s->failed_pc=0x0c0b212au; return 0; }
target=r[2];
r[16]=code_base|0x0c0b212eu;
write(ram,r[15],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b212eu) { target=s->pc; goto dispatch; }
goto P_0c0b212e;
P_0c0b212c: /* original 2f32, guest PC 0x0c0b212c */
if(!s->budget--) { s->failed_pc=0x0c0b212cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0b212e;
P_0c0b212e: /* original 904f, guest PC 0x0c0b212e */
if(!s->budget--) { s->failed_pc=0x0c0b212eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d0u,2);
goto P_0c0b2130;
P_0c0b2130: /* original 09ee, guest PC 0x0c0b2130 */
if(!s->budget--) { s->failed_pc=0x0c0b2130u; return 0; }
r[9]=read(ram,r[14]+r[0],4);
goto P_0c0b2132;
P_0c0b2132: /* original 6393, guest PC 0x0c0b2132 */
if(!s->budget--) { s->failed_pc=0x0c0b2132u; return 0; }
r[3]=r[9];
goto P_0c0b2134;
P_0c0b2134: /* original 4908, guest PC 0x0c0b2134 */
if(!s->budget--) { s->failed_pc=0x0c0b2134u; return 0; }
r[9]<<=2;
goto P_0c0b2136;
P_0c0b2136: /* original 4900, guest PC 0x0c0b2136 */
if(!s->budget--) { s->failed_pc=0x0c0b2136u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0b2138;
P_0c0b2138: /* original 393c, guest PC 0x0c0b2138 */
if(!s->budget--) { s->failed_pc=0x0c0b2138u; return 0; }
r[9]+=r[3];
goto P_0c0b213a;
P_0c0b213a: /* original 4908, guest PC 0x0c0b213a */
if(!s->budget--) { s->failed_pc=0x0c0b213au; return 0; }
r[9]<<=2;
goto P_0c0b213c;
P_0c0b213c: /* original 39bc, guest PC 0x0c0b213c */
if(!s->budget--) { s->failed_pc=0x0c0b213cu; return 0; }
r[9]+=r[11];
goto P_0c0b213e;
P_0c0b213e: /* original 5998, guest PC 0x0c0b213e */
if(!s->budget--) { s->failed_pc=0x0c0b213eu; return 0; }
r[9]=read(ram,r[9]+32,4);
goto P_0c0b2140;
P_0c0b2140: /* original 2998, guest PC 0x0c0b2140 */
if(!s->budget--) { s->failed_pc=0x0c0b2140u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0b2142;
P_0c0b2142: /* original 8901, guest PC 0x0c0b2142 */
if(!s->budget--) { s->failed_pc=0x0c0b2142u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b2148; }
goto P_0c0b2144;
P_0c0b2144: /* original 490b, guest PC 0x0c0b2144 */
if(!s->budget--) { s->failed_pc=0x0c0b2144u; return 0; }
target=r[9];
r[16]=code_base|0x0c0b2148u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2148u) { target=s->pc; goto dispatch; }
goto P_0c0b2148;
P_0c0b2146: /* original 0009, guest PC 0x0c0b2146 */
if(!s->budget--) { s->failed_pc=0x0c0b2146u; return 0; }
goto P_0c0b2148;
P_0c0b2148: /* original 9042, guest PC 0x0c0b2148 */
if(!s->budget--) { s->failed_pc=0x0c0b2148u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d0u,2);
goto P_0c0b214a;
P_0c0b214a: /* original e2ff, guest PC 0x0c0b214a */
if(!s->budget--) { s->failed_pc=0x0c0b214au; return 0; }
r[2]=0xffffffffu;
goto P_0c0b214c;
P_0c0b214c: /* original 0e26, guest PC 0x0c0b214c */
if(!s->budget--) { s->failed_pc=0x0c0b214cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0b214e;
P_0c0b214e: /* original 7008, guest PC 0x0c0b214e */
if(!s->budget--) { s->failed_pc=0x0c0b214eu; return 0; }
r[0]+=0x00000008u;
goto P_0c0b2150;
P_0c0b2150: /* original 03ee, guest PC 0x0c0b2150 */
if(!s->budget--) { s->failed_pc=0x0c0b2150u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0b2152;
P_0c0b2152: /* original 2338, guest PC 0x0c0b2152 */
if(!s->budget--) { s->failed_pc=0x0c0b2152u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b2154;
P_0c0b2154: /* original 8902, guest PC 0x0c0b2154 */
if(!s->budget--) { s->failed_pc=0x0c0b2154u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b215c; }
goto P_0c0b2156;
P_0c0b2156: /* original 903c, guest PC 0x0c0b2156 */
if(!s->budget--) { s->failed_pc=0x0c0b2156u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d2u,2);
goto P_0c0b2158;
P_0c0b2158: /* original 4a0b, guest PC 0x0c0b2158 */
if(!s->budget--) { s->failed_pc=0x0c0b2158u; return 0; }
target=r[10];
r[16]=code_base|0x0c0b215cu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b215cu) { target=s->pc; goto dispatch; }
goto P_0c0b215c;
P_0c0b215a: /* original 04ee, guest PC 0x0c0b215a */
if(!s->budget--) { s->failed_pc=0x0c0b215au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0b215c;
P_0c0b215c: /* original 903a, guest PC 0x0c0b215c */
if(!s->budget--) { s->failed_pc=0x0c0b215cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d4u,2);
goto P_0c0b215e;
P_0c0b215e: /* original 03ee, guest PC 0x0c0b215e */
if(!s->budget--) { s->failed_pc=0x0c0b215eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0b2160;
P_0c0b2160: /* original 2338, guest PC 0x0c0b2160 */
if(!s->budget--) { s->failed_pc=0x0c0b2160u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b2162;
P_0c0b2162: /* original 8901, guest PC 0x0c0b2162 */
if(!s->budget--) { s->failed_pc=0x0c0b2162u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b2168; }
goto P_0c0b2164;
P_0c0b2164: /* original 4a0b, guest PC 0x0c0b2164 */
if(!s->budget--) { s->failed_pc=0x0c0b2164u; return 0; }
target=r[10];
r[16]=code_base|0x0c0b2168u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2168u) { target=s->pc; goto dispatch; }
goto P_0c0b2168;
P_0c0b2166: /* original 04ee, guest PC 0x0c0b2166 */
if(!s->budget--) { s->failed_pc=0x0c0b2166u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0b2168;
P_0c0b2168: /* original 9034, guest PC 0x0c0b2168 */
if(!s->budget--) { s->failed_pc=0x0c0b2168u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d4u,2);
goto P_0c0b216a;
P_0c0b216a: /* original e300, guest PC 0x0c0b216a */
if(!s->budget--) { s->failed_pc=0x0c0b216au; return 0; }
r[3]=0x00000000u;
goto P_0c0b216c;
P_0c0b216c: /* original 0e36, guest PC 0x0c0b216c */
if(!s->budget--) { s->failed_pc=0x0c0b216cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0b216e;
P_0c0b216e: /* original 70f8, guest PC 0x0c0b216e */
if(!s->budget--) { s->failed_pc=0x0c0b216eu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0b2170;
P_0c0b2170: /* original 0e36, guest PC 0x0c0b2170 */
if(!s->budget--) { s->failed_pc=0x0c0b2170u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0b2172;
P_0c0b2172: /* original 9230, guest PC 0x0c0b2172 */
if(!s->budget--) { s->failed_pc=0x0c0b2172u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d6u,2);
goto P_0c0b2174;
P_0c0b2174: /* original 32ec, guest PC 0x0c0b2174 */
if(!s->budget--) { s->failed_pc=0x0c0b2174u; return 0; }
r[2]+=r[14];
goto P_0c0b2176;
P_0c0b2176: /* original 32dc, guest PC 0x0c0b2176 */
if(!s->budget--) { s->failed_pc=0x0c0b2176u; return 0; }
r[2]+=r[13];
goto P_0c0b2178;
P_0c0b2178: /* original 6322, guest PC 0x0c0b2178 */
if(!s->budget--) { s->failed_pc=0x0c0b2178u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0b217a;
P_0c0b217a: /* original 2338, guest PC 0x0c0b217a */
if(!s->budget--) { s->failed_pc=0x0c0b217au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b217c;
P_0c0b217c: /* original 8904, guest PC 0x0c0b217c */
if(!s->budget--) { s->failed_pc=0x0c0b217cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b2188; }
goto P_0c0b217e;
P_0c0b217e: /* original 942a, guest PC 0x0c0b217e */
if(!s->budget--) { s->failed_pc=0x0c0b217eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d6u,2);
goto P_0c0b2180;
P_0c0b2180: /* original 34ec, guest PC 0x0c0b2180 */
if(!s->budget--) { s->failed_pc=0x0c0b2180u; return 0; }
r[4]+=r[14];
goto P_0c0b2182;
P_0c0b2182: /* original 34dc, guest PC 0x0c0b2182 */
if(!s->budget--) { s->failed_pc=0x0c0b2182u; return 0; }
r[4]+=r[13];
goto P_0c0b2184;
P_0c0b2184: /* original 4a0b, guest PC 0x0c0b2184 */
if(!s->budget--) { s->failed_pc=0x0c0b2184u; return 0; }
target=r[10];
r[16]=code_base|0x0c0b2188u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2188u) { target=s->pc; goto dispatch; }
goto P_0c0b2188;
P_0c0b2186: /* original 6442, guest PC 0x0c0b2186 */
if(!s->budget--) { s->failed_pc=0x0c0b2186u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0b2188;
P_0c0b2188: /* original 9326, guest PC 0x0c0b2188 */
if(!s->budget--) { s->failed_pc=0x0c0b2188u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d8u,2);
goto P_0c0b218a;
P_0c0b218a: /* original 33ec, guest PC 0x0c0b218a */
if(!s->budget--) { s->failed_pc=0x0c0b218au; return 0; }
r[3]+=r[14];
goto P_0c0b218c;
P_0c0b218c: /* original 33dc, guest PC 0x0c0b218c */
if(!s->budget--) { s->failed_pc=0x0c0b218cu; return 0; }
r[3]+=r[13];
goto P_0c0b218e;
P_0c0b218e: /* original 6232, guest PC 0x0c0b218e */
if(!s->budget--) { s->failed_pc=0x0c0b218eu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0b2190;
P_0c0b2190: /* original 2228, guest PC 0x0c0b2190 */
if(!s->budget--) { s->failed_pc=0x0c0b2190u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b2192;
P_0c0b2192: /* original 8904, guest PC 0x0c0b2192 */
if(!s->budget--) { s->failed_pc=0x0c0b2192u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b219e; }
goto P_0c0b2194;
P_0c0b2194: /* original 9420, guest PC 0x0c0b2194 */
if(!s->budget--) { s->failed_pc=0x0c0b2194u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d8u,2);
goto P_0c0b2196;
P_0c0b2196: /* original 34ec, guest PC 0x0c0b2196 */
if(!s->budget--) { s->failed_pc=0x0c0b2196u; return 0; }
r[4]+=r[14];
goto P_0c0b2198;
P_0c0b2198: /* original 34dc, guest PC 0x0c0b2198 */
if(!s->budget--) { s->failed_pc=0x0c0b2198u; return 0; }
r[4]+=r[13];
goto P_0c0b219a;
P_0c0b219a: /* original 4a0b, guest PC 0x0c0b219a */
if(!s->budget--) { s->failed_pc=0x0c0b219au; return 0; }
target=r[10];
r[16]=code_base|0x0c0b219eu;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b219eu) { target=s->pc; goto dispatch; }
goto P_0c0b219e;
P_0c0b219c: /* original 6442, guest PC 0x0c0b219c */
if(!s->budget--) { s->failed_pc=0x0c0b219cu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0b219e;
P_0c0b219e: /* original 931a, guest PC 0x0c0b219e */
if(!s->budget--) { s->failed_pc=0x0c0b219eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d6u,2);
goto P_0c0b21a0;
P_0c0b21a0: /* original e100, guest PC 0x0c0b21a0 */
if(!s->budget--) { s->failed_pc=0x0c0b21a0u; return 0; }
r[1]=0x00000000u;
goto P_0c0b21a2;
P_0c0b21a2: /* original 9219, guest PC 0x0c0b21a2 */
if(!s->budget--) { s->failed_pc=0x0c0b21a2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d8u,2);
goto P_0c0b21a4;
P_0c0b21a4: /* original 33ec, guest PC 0x0c0b21a4 */
if(!s->budget--) { s->failed_pc=0x0c0b21a4u; return 0; }
r[3]+=r[14];
goto P_0c0b21a6;
P_0c0b21a6: /* original 33dc, guest PC 0x0c0b21a6 */
if(!s->budget--) { s->failed_pc=0x0c0b21a6u; return 0; }
r[3]+=r[13];
goto P_0c0b21a8;
P_0c0b21a8: /* original 32ec, guest PC 0x0c0b21a8 */
if(!s->budget--) { s->failed_pc=0x0c0b21a8u; return 0; }
r[2]+=r[14];
goto P_0c0b21aa;
P_0c0b21aa: /* original 32dc, guest PC 0x0c0b21aa */
if(!s->budget--) { s->failed_pc=0x0c0b21aau; return 0; }
r[2]+=r[13];
goto P_0c0b21ac;
P_0c0b21ac: /* original 2212, guest PC 0x0c0b21ac */
if(!s->budget--) { s->failed_pc=0x0c0b21acu; return 0; }
write(ram,r[2],r[1],4);
goto P_0c0b21ae;
P_0c0b21ae: /* original 2312, guest PC 0x0c0b21ae */
if(!s->budget--) { s->failed_pc=0x0c0b21aeu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0b21b0;
P_0c0b21b0: /* original 9311, guest PC 0x0c0b21b0 */
if(!s->budget--) { s->failed_pc=0x0c0b21b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21d6u,2);
goto P_0c0b21b2;
P_0c0b21b2: /* original d00d, guest PC 0x0c0b21b2 */
if(!s->budget--) { s->failed_pc=0x0c0b21b2u; return 0; }
r[0]=read(ram,0x0c0b21e8u,4);
goto P_0c0b21b4;
P_0c0b21b4: /* original 33ec, guest PC 0x0c0b21b4 */
if(!s->budget--) { s->failed_pc=0x0c0b21b4u; return 0; }
r[3]+=r[14];
goto P_0c0b21b6;
P_0c0b21b6: /* original 0ade, guest PC 0x0c0b21b6 */
if(!s->budget--) { s->failed_pc=0x0c0b21b6u; return 0; }
r[10]=read(ram,r[13]+r[0],4);
goto P_0c0b21b8;
P_0c0b21b8: /* original 33dc, guest PC 0x0c0b21b8 */
if(!s->budget--) { s->failed_pc=0x0c0b21b8u; return 0; }
r[3]+=r[13];
goto P_0c0b21ba;
P_0c0b21ba: /* original e060, guest PC 0x0c0b21ba */
if(!s->budget--) { s->failed_pc=0x0c0b21bau; return 0; }
r[0]=0x00000060u;
goto P_0c0b21bc;
P_0c0b21bc: /* original 23a2, guest PC 0x0c0b21bc */
if(!s->budget--) { s->failed_pc=0x0c0b21bcu; return 0; }
write(ram,r[3],r[10],4);
goto P_0c0b21be;
P_0c0b21be: /* original 9206, guest PC 0x0c0b21be */
if(!s->budget--) { s->failed_pc=0x0c0b21beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b21ceu,2);
goto P_0c0b21c0;
P_0c0b21c0: /* original 03cc, guest PC 0x0c0b21c0 */
if(!s->budget--) { s->failed_pc=0x0c0b21c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0b21c2;
P_0c0b21c2: /* original 32ec, guest PC 0x0c0b21c2 */
if(!s->budget--) { s->failed_pc=0x0c0b21c2u; return 0; }
r[2]+=r[14];
goto P_0c0b21c4;
P_0c0b21c4: /* original 633c, guest PC 0x0c0b21c4 */
if(!s->budget--) { s->failed_pc=0x0c0b21c4u; return 0; }
r[3]=r[3]&255u;
goto P_0c0b21c6;
P_0c0b21c6: /* original 32dc, guest PC 0x0c0b21c6 */
if(!s->budget--) { s->failed_pc=0x0c0b21c6u; return 0; }
r[2]+=r[13];
goto P_0c0b21c8;
P_0c0b21c8: /* original 2232, guest PC 0x0c0b21c8 */
if(!s->budget--) { s->failed_pc=0x0c0b21c8u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0b21ca;
P_0c0b21ca: /* original a00f, guest PC 0x0c0b21ca */
if(!s->budget--) { s->failed_pc=0x0c0b21cau; return 0; }
goto P_0c0b21ec;
P_0c0b21cc: /* original 0009, guest PC 0x0c0b21cc */
if(!s->budget--) { s->failed_pc=0x0c0b21ccu; return 0; }
if(!vf3_matrix_family(0x0c0b21ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b21ceu; return 0; } return 1;
P_0c0b21ec: /* original d032, guest PC 0x0c0b21ec */
if(!s->budget--) { s->failed_pc=0x0c0b21ecu; return 0; }
r[0]=read(ram,0x0c0b22b8u,4);
goto P_0c0b21ee;
P_0c0b21ee: /* original 66a3, guest PC 0x0c0b21ee */
if(!s->budget--) { s->failed_pc=0x0c0b21eeu; return 0; }
r[6]=r[10];
goto P_0c0b21f0;
P_0c0b21f0: /* original 07dd, guest PC 0x0c0b21f0 */
if(!s->budget--) { s->failed_pc=0x0c0b21f0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0b21f2;
P_0c0b21f2: /* original e060, guest PC 0x0c0b21f2 */
if(!s->budget--) { s->failed_pc=0x0c0b21f2u; return 0; }
r[0]=0x00000060u;
goto P_0c0b21f4;
P_0c0b21f4: /* original 05cc, guest PC 0x0c0b21f4 */
if(!s->budget--) { s->failed_pc=0x0c0b21f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0b21f6;
P_0c0b21f6: /* original 655c, guest PC 0x0c0b21f6 */
if(!s->budget--) { s->failed_pc=0x0c0b21f6u; return 0; }
r[5]=r[5]&255u;
goto P_0c0b21f8;
P_0c0b21f8: /* original 6353, guest PC 0x0c0b21f8 */
if(!s->budget--) { s->failed_pc=0x0c0b21f8u; return 0; }
r[3]=r[5];
goto P_0c0b21fa;
P_0c0b21fa: /* original 4508, guest PC 0x0c0b21fa */
if(!s->budget--) { s->failed_pc=0x0c0b21fau; return 0; }
r[5]<<=2;
goto P_0c0b21fc;
P_0c0b21fc: /* original 4500, guest PC 0x0c0b21fc */
if(!s->budget--) { s->failed_pc=0x0c0b21fcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0b21fe;
P_0c0b21fe: /* original 353c, guest PC 0x0c0b21fe */
if(!s->budget--) { s->failed_pc=0x0c0b21feu; return 0; }
r[5]+=r[3];
goto P_0c0b2200;
P_0c0b2200: /* original 4508, guest PC 0x0c0b2200 */
if(!s->budget--) { s->failed_pc=0x0c0b2200u; return 0; }
r[5]<<=2;
goto P_0c0b2202;
P_0c0b2202: /* original 35bc, guest PC 0x0c0b2202 */
if(!s->budget--) { s->failed_pc=0x0c0b2202u; return 0; }
r[5]+=r[11];
goto P_0c0b2204;
P_0c0b2204: /* original 2f52, guest PC 0x0c0b2204 */
if(!s->budget--) { s->failed_pc=0x0c0b2204u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b2206;
P_0c0b2206: /* original 64f2, guest PC 0x0c0b2206 */
if(!s->budget--) { s->failed_pc=0x0c0b2206u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b2208;
P_0c0b2208: /* original d32c, guest PC 0x0c0b2208 */
if(!s->budget--) { s->failed_pc=0x0c0b2208u; return 0; }
r[3]=read(ram,0x0c0b22bcu,4);
goto P_0c0b220a;
P_0c0b220a: /* original 5551, guest PC 0x0c0b220a */
if(!s->budget--) { s->failed_pc=0x0c0b220au; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c0b220c;
P_0c0b220c: /* original 430b, guest PC 0x0c0b220c */
if(!s->budget--) { s->failed_pc=0x0c0b220cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b2210u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2210u) { target=s->pc; goto dispatch; }
goto P_0c0b2210;
P_0c0b220e: /* original 6442, guest PC 0x0c0b220e */
if(!s->budget--) { s->failed_pc=0x0c0b220eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0b2210;
P_0c0b2210: /* original e060, guest PC 0x0c0b2210 */
if(!s->budget--) { s->failed_pc=0x0c0b2210u; return 0; }
r[0]=0x00000060u;
goto P_0c0b2212;
P_0c0b2212: /* original 04cc, guest PC 0x0c0b2212 */
if(!s->budget--) { s->failed_pc=0x0c0b2212u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0b2214;
P_0c0b2214: /* original 604c, guest PC 0x0c0b2214 */
if(!s->budget--) { s->failed_pc=0x0c0b2214u; return 0; }
r[0]=r[4]&255u;
goto P_0c0b2216;
P_0c0b2216: /* original 8809, guest PC 0x0c0b2216 */
if(!s->budget--) { s->failed_pc=0x0c0b2216u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b2218;
P_0c0b2218: /* original 8d1f, guest PC 0x0c0b2218 */
if(!s->budget--) { s->failed_pc=0x0c0b2218u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0b225a; }
goto P_0c0b221c;
P_0c0b221a: /* original 6403, guest PC 0x0c0b221a */
if(!s->budget--) { s->failed_pc=0x0c0b221au; return 0; }
r[4]=r[0];
goto P_0c0b221c;
P_0c0b221c: /* original 6043, guest PC 0x0c0b221c */
if(!s->budget--) { s->failed_pc=0x0c0b221cu; return 0; }
r[0]=r[4];
goto P_0c0b221e;
P_0c0b221e: /* original 8816, guest PC 0x0c0b221e */
if(!s->budget--) { s->failed_pc=0x0c0b221eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c0b2220;
P_0c0b2220: /* original 891b, guest PC 0x0c0b2220 */
if(!s->budget--) { s->failed_pc=0x0c0b2220u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b225a; }
goto P_0c0b2222;
P_0c0b2222: /* original d027, guest PC 0x0c0b2222 */
if(!s->budget--) { s->failed_pc=0x0c0b2222u; return 0; }
r[0]=read(ram,0x0c0b22c0u,4);
goto P_0c0b2224;
P_0c0b2224: /* original 59a6, guest PC 0x0c0b2224 */
if(!s->budget--) { s->failed_pc=0x0c0b2224u; return 0; }
r[9]=read(ram,r[10]+24,4);
goto P_0c0b2226;
P_0c0b2226: /* original 07dd, guest PC 0x0c0b2226 */
if(!s->budget--) { s->failed_pc=0x0c0b2226u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0b2228;
P_0c0b2228: /* original e060, guest PC 0x0c0b2228 */
if(!s->budget--) { s->failed_pc=0x0c0b2228u; return 0; }
r[0]=0x00000060u;
goto P_0c0b222a;
P_0c0b222a: /* original 05cc, guest PC 0x0c0b222a */
if(!s->budget--) { s->failed_pc=0x0c0b222au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0b222c;
P_0c0b222c: /* original 39ac, guest PC 0x0c0b222c */
if(!s->budget--) { s->failed_pc=0x0c0b222cu; return 0; }
r[9]+=r[10];
goto P_0c0b222e;
P_0c0b222e: /* original 9340, guest PC 0x0c0b222e */
if(!s->budget--) { s->failed_pc=0x0c0b222eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b22b2u,2);
goto P_0c0b2230;
P_0c0b2230: /* original 655c, guest PC 0x0c0b2230 */
if(!s->budget--) { s->failed_pc=0x0c0b2230u; return 0; }
r[5]=r[5]&255u;
goto P_0c0b2232;
P_0c0b2232: /* original 923f, guest PC 0x0c0b2232 */
if(!s->budget--) { s->failed_pc=0x0c0b2232u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b22b4u,2);
goto P_0c0b2234;
P_0c0b2234: /* original 393c, guest PC 0x0c0b2234 */
if(!s->budget--) { s->failed_pc=0x0c0b2234u; return 0; }
r[9]+=r[3];
goto P_0c0b2236;
P_0c0b2236: /* original 6353, guest PC 0x0c0b2236 */
if(!s->budget--) { s->failed_pc=0x0c0b2236u; return 0; }
r[3]=r[5];
goto P_0c0b2238;
P_0c0b2238: /* original 4508, guest PC 0x0c0b2238 */
if(!s->budget--) { s->failed_pc=0x0c0b2238u; return 0; }
r[5]<<=2;
goto P_0c0b223a;
P_0c0b223a: /* original 4500, guest PC 0x0c0b223a */
if(!s->budget--) { s->failed_pc=0x0c0b223au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0b223c;
P_0c0b223c: /* original 353c, guest PC 0x0c0b223c */
if(!s->budget--) { s->failed_pc=0x0c0b223cu; return 0; }
r[5]+=r[3];
goto P_0c0b223e;
P_0c0b223e: /* original 4508, guest PC 0x0c0b223e */
if(!s->budget--) { s->failed_pc=0x0c0b223eu; return 0; }
r[5]<<=2;
goto P_0c0b2240;
P_0c0b2240: /* original 35bc, guest PC 0x0c0b2240 */
if(!s->budget--) { s->failed_pc=0x0c0b2240u; return 0; }
r[5]+=r[11];
goto P_0c0b2242;
P_0c0b2242: /* original 2f52, guest PC 0x0c0b2242 */
if(!s->budget--) { s->failed_pc=0x0c0b2242u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b2244;
P_0c0b2244: /* original 2929, guest PC 0x0c0b2244 */
if(!s->budget--) { s->failed_pc=0x0c0b2244u; return 0; }
r[9]&=r[2];
goto P_0c0b2246;
P_0c0b2246: /* original 64f2, guest PC 0x0c0b2246 */
if(!s->budget--) { s->failed_pc=0x0c0b2246u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b2248;
P_0c0b2248: /* original 6693, guest PC 0x0c0b2248 */
if(!s->budget--) { s->failed_pc=0x0c0b2248u; return 0; }
r[6]=r[9];
goto P_0c0b224a;
P_0c0b224a: /* original d31c, guest PC 0x0c0b224a */
if(!s->budget--) { s->failed_pc=0x0c0b224au; return 0; }
r[3]=read(ram,0x0c0b22bcu,4);
goto P_0c0b224c;
P_0c0b224c: /* original 5555, guest PC 0x0c0b224c */
if(!s->budget--) { s->failed_pc=0x0c0b224cu; return 0; }
r[5]=read(ram,r[5]+20,4);
goto P_0c0b224e;
P_0c0b224e: /* original 430b, guest PC 0x0c0b224e */
if(!s->budget--) { s->failed_pc=0x0c0b224eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b2252u;
r[4]=read(ram,r[4]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2252u) { target=s->pc; goto dispatch; }
goto P_0c0b2252;
P_0c0b2250: /* original 5444, guest PC 0x0c0b2250 */
if(!s->budget--) { s->failed_pc=0x0c0b2250u; return 0; }
r[4]=read(ram,r[4]+16,4);
goto P_0c0b2252;
P_0c0b2252: /* original 9230, guest PC 0x0c0b2252 */
if(!s->budget--) { s->failed_pc=0x0c0b2252u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b22b6u,2);
goto P_0c0b2254;
P_0c0b2254: /* original 32ec, guest PC 0x0c0b2254 */
if(!s->budget--) { s->failed_pc=0x0c0b2254u; return 0; }
r[2]+=r[14];
goto P_0c0b2256;
P_0c0b2256: /* original 32dc, guest PC 0x0c0b2256 */
if(!s->budget--) { s->failed_pc=0x0c0b2256u; return 0; }
r[2]+=r[13];
goto P_0c0b2258;
P_0c0b2258: /* original 2292, guest PC 0x0c0b2258 */
if(!s->budget--) { s->failed_pc=0x0c0b2258u; return 0; }
write(ram,r[2],r[9],4);
goto P_0c0b225a;
P_0c0b225a: /* original e060, guest PC 0x0c0b225a */
if(!s->budget--) { s->failed_pc=0x0c0b225au; return 0; }
r[0]=0x00000060u;
goto P_0c0b225c;
P_0c0b225c: /* original 03cc, guest PC 0x0c0b225c */
if(!s->budget--) { s->failed_pc=0x0c0b225cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0b225e;
P_0c0b225e: /* original 633c, guest PC 0x0c0b225e */
if(!s->budget--) { s->failed_pc=0x0c0b225eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0b2260;
P_0c0b2260: /* original 6233, guest PC 0x0c0b2260 */
if(!s->budget--) { s->failed_pc=0x0c0b2260u; return 0; }
r[2]=r[3];
goto P_0c0b2262;
P_0c0b2262: /* original 4308, guest PC 0x0c0b2262 */
if(!s->budget--) { s->failed_pc=0x0c0b2262u; return 0; }
r[3]<<=2;
goto P_0c0b2264;
P_0c0b2264: /* original 4300, guest PC 0x0c0b2264 */
if(!s->budget--) { s->failed_pc=0x0c0b2264u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0b2266;
P_0c0b2266: /* original 332c, guest PC 0x0c0b2266 */
if(!s->budget--) { s->failed_pc=0x0c0b2266u; return 0; }
r[3]+=r[2];
goto P_0c0b2268;
P_0c0b2268: /* original 4308, guest PC 0x0c0b2268 */
if(!s->budget--) { s->failed_pc=0x0c0b2268u; return 0; }
r[3]<<=2;
goto P_0c0b226a;
P_0c0b226a: /* original 33bc, guest PC 0x0c0b226a */
if(!s->budget--) { s->failed_pc=0x0c0b226au; return 0; }
r[3]+=r[11];
goto P_0c0b226c;
P_0c0b226c: /* original 5132, guest PC 0x0c0b226c */
if(!s->budget--) { s->failed_pc=0x0c0b226cu; return 0; }
r[1]=read(ram,r[3]+8,4);
goto P_0c0b226e;
P_0c0b226e: /* original 6313, guest PC 0x0c0b226e */
if(!s->budget--) { s->failed_pc=0x0c0b226eu; return 0; }
r[3]=r[1];
goto P_0c0b2270;
P_0c0b2270: /* original 2f12, guest PC 0x0c0b2270 */
if(!s->budget--) { s->failed_pc=0x0c0b2270u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0b2272;
P_0c0b2272: /* original 430b, guest PC 0x0c0b2272 */
if(!s->budget--) { s->failed_pc=0x0c0b2272u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b2276u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2276u) { target=s->pc; goto dispatch; }
goto P_0c0b2276;
P_0c0b2274: /* original 64a3, guest PC 0x0c0b2274 */
if(!s->budget--) { s->failed_pc=0x0c0b2274u; return 0; }
r[4]=r[10];
goto P_0c0b2276;
P_0c0b2276: /* original e060, guest PC 0x0c0b2276 */
if(!s->budget--) { s->failed_pc=0x0c0b2276u; return 0; }
r[0]=0x00000060u;
goto P_0c0b2278;
P_0c0b2278: /* original 0ecc, guest PC 0x0c0b2278 */
if(!s->budget--) { s->failed_pc=0x0c0b2278u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0b227a;
P_0c0b227a: /* original 6eec, guest PC 0x0c0b227a */
if(!s->budget--) { s->failed_pc=0x0c0b227au; return 0; }
r[14]=r[14]&255u;
goto P_0c0b227c;
P_0c0b227c: /* original 63e3, guest PC 0x0c0b227c */
if(!s->budget--) { s->failed_pc=0x0c0b227cu; return 0; }
r[3]=r[14];
goto P_0c0b227e;
P_0c0b227e: /* original 4e08, guest PC 0x0c0b227e */
if(!s->budget--) { s->failed_pc=0x0c0b227eu; return 0; }
r[14]<<=2;
goto P_0c0b2280;
P_0c0b2280: /* original 4e00, guest PC 0x0c0b2280 */
if(!s->budget--) { s->failed_pc=0x0c0b2280u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0b2282;
P_0c0b2282: /* original 3e3c, guest PC 0x0c0b2282 */
if(!s->budget--) { s->failed_pc=0x0c0b2282u; return 0; }
r[14]+=r[3];
goto P_0c0b2284;
P_0c0b2284: /* original 4e08, guest PC 0x0c0b2284 */
if(!s->budget--) { s->failed_pc=0x0c0b2284u; return 0; }
r[14]<<=2;
goto P_0c0b2286;
P_0c0b2286: /* original 3ebc, guest PC 0x0c0b2286 */
if(!s->budget--) { s->failed_pc=0x0c0b2286u; return 0; }
r[14]+=r[11];
goto P_0c0b2288;
P_0c0b2288: /* original 5ee7, guest PC 0x0c0b2288 */
if(!s->budget--) { s->failed_pc=0x0c0b2288u; return 0; }
r[14]=read(ram,r[14]+28,4);
goto P_0c0b228a;
P_0c0b228a: /* original 2ee8, guest PC 0x0c0b228a */
if(!s->budget--) { s->failed_pc=0x0c0b228au; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0b228c;
P_0c0b228c: /* original 8906, guest PC 0x0c0b228c */
if(!s->budget--) { s->failed_pc=0x0c0b228cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b229c; }
goto P_0c0b228e;
P_0c0b228e: /* original e061, guest PC 0x0c0b228e */
if(!s->budget--) { s->failed_pc=0x0c0b228eu; return 0; }
r[0]=0x00000061u;
goto P_0c0b2290;
P_0c0b2290: /* original 00cc, guest PC 0x0c0b2290 */
if(!s->budget--) { s->failed_pc=0x0c0b2290u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0b2292;
P_0c0b2292: /* original 600c, guest PC 0x0c0b2292 */
if(!s->budget--) { s->failed_pc=0x0c0b2292u; return 0; }
r[0]=r[0]&255u;
goto P_0c0b2294;
P_0c0b2294: /* original 8809, guest PC 0x0c0b2294 */
if(!s->budget--) { s->failed_pc=0x0c0b2294u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b2296;
P_0c0b2296: /* original 8901, guest PC 0x0c0b2296 */
if(!s->budget--) { s->failed_pc=0x0c0b2296u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b229c; }
goto P_0c0b2298;
P_0c0b2298: /* original 4e0b, guest PC 0x0c0b2298 */
if(!s->budget--) { s->failed_pc=0x0c0b2298u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b229cu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b229cu) { target=s->pc; goto dispatch; }
goto P_0c0b229c;
P_0c0b229a: /* original 6493, guest PC 0x0c0b229a */
if(!s->budget--) { s->failed_pc=0x0c0b229au; return 0; }
r[4]=r[9];
goto P_0c0b229c;
P_0c0b229c: /* original 7f04, guest PC 0x0c0b229c */
if(!s->budget--) { s->failed_pc=0x0c0b229cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0b229e;
P_0c0b229e: /* original 4f26, guest PC 0x0c0b229e */
if(!s->budget--) { s->failed_pc=0x0c0b229eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b22a0;
P_0c0b22a0: /* original 69f6, guest PC 0x0c0b22a0 */
if(!s->budget--) { s->failed_pc=0x0c0b22a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b22a2;
P_0c0b22a2: /* original 6af6, guest PC 0x0c0b22a2 */
if(!s->budget--) { s->failed_pc=0x0c0b22a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b22a4;
P_0c0b22a4: /* original 6bf6, guest PC 0x0c0b22a4 */
if(!s->budget--) { s->failed_pc=0x0c0b22a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b22a6;
P_0c0b22a6: /* original 6cf6, guest PC 0x0c0b22a6 */
if(!s->budget--) { s->failed_pc=0x0c0b22a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b22a8;
P_0c0b22a8: /* original 6df6, guest PC 0x0c0b22a8 */
if(!s->budget--) { s->failed_pc=0x0c0b22a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b22aa;
P_0c0b22aa: /* original 000b, guest PC 0x0c0b22aa */
if(!s->budget--) { s->failed_pc=0x0c0b22aau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b22ac: /* original 6ef6, guest PC 0x0c0b22ac */
if(!s->budget--) { s->failed_pc=0x0c0b22acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b22aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b22aeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
