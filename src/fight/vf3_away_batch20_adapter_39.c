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
int vf3_away_batch20_adapter_39(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2164u: goto P_0c0a2164;
case 0x0c0a2166u: goto P_0c0a2166;
case 0x0c0a2168u: goto P_0c0a2168;
case 0x0c0a216au: goto P_0c0a216a;
case 0x0c0a216cu: goto P_0c0a216c;
case 0x0c0a216eu: goto P_0c0a216e;
case 0x0c0a2170u: goto P_0c0a2170;
case 0x0c0a2172u: goto P_0c0a2172;
case 0x0c0a2174u: goto P_0c0a2174;
case 0x0c0a2176u: goto P_0c0a2176;
case 0x0c0a2178u: goto P_0c0a2178;
case 0x0c0a217au: goto P_0c0a217a;
case 0x0c0a217cu: goto P_0c0a217c;
case 0x0c0a217eu: goto P_0c0a217e;
case 0x0c0a2180u: goto P_0c0a2180;
case 0x0c0a2182u: goto P_0c0a2182;
case 0x0c0a2184u: goto P_0c0a2184;
case 0x0c0a2186u: goto P_0c0a2186;
case 0x0c0a2188u: goto P_0c0a2188;
case 0x0c0a218au: goto P_0c0a218a;
case 0x0c0a218cu: goto P_0c0a218c;
case 0x0c0a218eu: goto P_0c0a218e;
case 0x0c0a2190u: goto P_0c0a2190;
case 0x0c0a2192u: goto P_0c0a2192;
case 0x0c0a2194u: goto P_0c0a2194;
case 0x0c0a2196u: goto P_0c0a2196;
case 0x0c0a2198u: goto P_0c0a2198;
case 0x0c0a219au: goto P_0c0a219a;
case 0x0c0a219cu: goto P_0c0a219c;
case 0x0c0a219eu: goto P_0c0a219e;
case 0x0c0a21a0u: goto P_0c0a21a0;
case 0x0c0a21a2u: goto P_0c0a21a2;
case 0x0c0a21a4u: goto P_0c0a21a4;
case 0x0c0a21a6u: goto P_0c0a21a6;
case 0x0c0a21a8u: goto P_0c0a21a8;
case 0x0c0a21aau: goto P_0c0a21aa;
case 0x0c0a21acu: goto P_0c0a21ac;
case 0x0c0a21aeu: goto P_0c0a21ae;
case 0x0c0a21b0u: goto P_0c0a21b0;
case 0x0c0a21b2u: goto P_0c0a21b2;
case 0x0c0a21b4u: goto P_0c0a21b4;
case 0x0c0a21b6u: goto P_0c0a21b6;
case 0x0c0a21b8u: goto P_0c0a21b8;
case 0x0c0a21bau: goto P_0c0a21ba;
case 0x0c0a21bcu: goto P_0c0a21bc;
case 0x0c0a21beu: goto P_0c0a21be;
case 0x0c0a21c0u: goto P_0c0a21c0;
case 0x0c0a21c2u: goto P_0c0a21c2;
case 0x0c0a21c4u: goto P_0c0a21c4;
case 0x0c0a21c6u: goto P_0c0a21c6;
case 0x0c0a21c8u: goto P_0c0a21c8;
case 0x0c0a21cau: goto P_0c0a21ca;
case 0x0c0a21ccu: goto P_0c0a21cc;
case 0x0c0a21ceu: goto P_0c0a21ce;
case 0x0c0a21d0u: goto P_0c0a21d0;
case 0x0c0a21d2u: goto P_0c0a21d2;
case 0x0c0a21d4u: goto P_0c0a21d4;
case 0x0c0a21d6u: goto P_0c0a21d6;
case 0x0c0a21d8u: goto P_0c0a21d8;
case 0x0c0a21dau: goto P_0c0a21da;
case 0x0c0a21dcu: goto P_0c0a21dc;
case 0x0c0a21deu: goto P_0c0a21de;
case 0x0c0a21e0u: goto P_0c0a21e0;
case 0x0c0a21e2u: goto P_0c0a21e2;
case 0x0c0a21e4u: goto P_0c0a21e4;
case 0x0c0a21e6u: goto P_0c0a21e6;
case 0x0c0a21e8u: goto P_0c0a21e8;
case 0x0c0a21eau: goto P_0c0a21ea;
case 0x0c0a21ecu: goto P_0c0a21ec;
case 0x0c0a21eeu: goto P_0c0a21ee;
case 0x0c0a21f0u: goto P_0c0a21f0;
case 0x0c0a21f2u: goto P_0c0a21f2;
case 0x0c0a21f4u: goto P_0c0a21f4;
case 0x0c0a21f6u: goto P_0c0a21f6;
case 0x0c0a21f8u: goto P_0c0a21f8;
case 0x0c0a21fau: goto P_0c0a21fa;
case 0x0c0a21fcu: goto P_0c0a21fc;
case 0x0c0a21feu: goto P_0c0a21fe;
case 0x0c0a2200u: goto P_0c0a2200;
case 0x0c0a2202u: goto P_0c0a2202;
case 0x0c0a2204u: goto P_0c0a2204;
case 0x0c0a2206u: goto P_0c0a2206;
case 0x0c0a2208u: goto P_0c0a2208;
case 0x0c0a220au: goto P_0c0a220a;
case 0x0c0a220cu: goto P_0c0a220c;
case 0x0c0a220eu: goto P_0c0a220e;
case 0x0c0a2210u: goto P_0c0a2210;
case 0x0c0a2212u: goto P_0c0a2212;
case 0x0c0a2214u: goto P_0c0a2214;
case 0x0c0a2216u: goto P_0c0a2216;
case 0x0c0a2218u: goto P_0c0a2218;
case 0x0c0a221au: goto P_0c0a221a;
case 0x0c0a221cu: goto P_0c0a221c;
case 0x0c0a221eu: goto P_0c0a221e;
case 0x0c0a2220u: goto P_0c0a2220;
case 0x0c0a2222u: goto P_0c0a2222;
case 0x0c0a2224u: goto P_0c0a2224;
case 0x0c0a2226u: goto P_0c0a2226;
case 0x0c0a2228u: goto P_0c0a2228;
case 0x0c0a222au: goto P_0c0a222a;
case 0x0c0a222cu: goto P_0c0a222c;
case 0x0c0a222eu: goto P_0c0a222e;
case 0x0c0a2230u: goto P_0c0a2230;
case 0x0c0a2232u: goto P_0c0a2232;
case 0x0c0a2234u: goto P_0c0a2234;
case 0x0c0a2236u: goto P_0c0a2236;
case 0x0c0a2238u: goto P_0c0a2238;
case 0x0c0a223au: goto P_0c0a223a;
case 0x0c0a223cu: goto P_0c0a223c;
case 0x0c0a223eu: goto P_0c0a223e;
case 0x0c0a2240u: goto P_0c0a2240;
case 0x0c0a2242u: goto P_0c0a2242;
case 0x0c0a2244u: goto P_0c0a2244;
case 0x0c0a2246u: goto P_0c0a2246;
case 0x0c0a2248u: goto P_0c0a2248;
case 0x0c0a224au: goto P_0c0a224a;
case 0x0c0a224cu: goto P_0c0a224c;
case 0x0c0a224eu: goto P_0c0a224e;
case 0x0c0a2250u: goto P_0c0a2250;
case 0x0c0a2252u: goto P_0c0a2252;
case 0x0c0a2254u: goto P_0c0a2254;
case 0x0c0a2256u: goto P_0c0a2256;
case 0x0c0a2258u: goto P_0c0a2258;
case 0x0c0a225au: goto P_0c0a225a;
case 0x0c0a225cu: goto P_0c0a225c;
case 0x0c0a225eu: goto P_0c0a225e;
case 0x0c0a2260u: goto P_0c0a2260;
case 0x0c0a2262u: goto P_0c0a2262;
case 0x0c0a2264u: goto P_0c0a2264;
case 0x0c0a2266u: goto P_0c0a2266;
case 0x0c0a2268u: goto P_0c0a2268;
case 0x0c0a226au: goto P_0c0a226a;
case 0x0c0a226cu: goto P_0c0a226c;
case 0x0c0a226eu: goto P_0c0a226e;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2164: /* original 2fe6, guest PC 0x0c0a2164 */
if(!s->budget--) { s->failed_pc=0x0c0a2164u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2166;
P_0c0a2166: /* original 2fd6, guest PC 0x0c0a2166 */
if(!s->budget--) { s->failed_pc=0x0c0a2166u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2168;
P_0c0a2168: /* original 2fc6, guest PC 0x0c0a2168 */
if(!s->budget--) { s->failed_pc=0x0c0a2168u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a216a;
P_0c0a216a: /* original 2fb6, guest PC 0x0c0a216a */
if(!s->budget--) { s->failed_pc=0x0c0a216au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a216c;
P_0c0a216c: /* original 2fa6, guest PC 0x0c0a216c */
if(!s->budget--) { s->failed_pc=0x0c0a216cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a216e;
P_0c0a216e: /* original 2f96, guest PC 0x0c0a216e */
if(!s->budget--) { s->failed_pc=0x0c0a216eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2170;
P_0c0a2170: /* original 2f86, guest PC 0x0c0a2170 */
if(!s->budget--) { s->failed_pc=0x0c0a2170u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2172;
P_0c0a2172: /* original 4f22, guest PC 0x0c0a2172 */
if(!s->budget--) { s->failed_pc=0x0c0a2172u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2174;
P_0c0a2174: /* original db41, guest PC 0x0c0a2174 */
if(!s->budget--) { s->failed_pc=0x0c0a2174u; return 0; }
r[11]=read(ram,0x0c0a227cu,4);
goto P_0c0a2176;
P_0c0a2176: /* original 7ff4, guest PC 0x0c0a2176 */
if(!s->budget--) { s->failed_pc=0x0c0a2176u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a2178;
P_0c0a2178: /* original 4b0b, guest PC 0x0c0a2178 */
if(!s->budget--) { s->failed_pc=0x0c0a2178u; return 0; }
target=r[11];
r[16]=code_base|0x0c0a217cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a217cu) { target=s->pc; goto dispatch; }
goto P_0c0a217c;
P_0c0a217a: /* original e400, guest PC 0x0c0a217a */
if(!s->budget--) { s->failed_pc=0x0c0a217au; return 0; }
r[4]=0x00000000u;
goto P_0c0a217c;
P_0c0a217c: /* original d340, guest PC 0x0c0a217c */
if(!s->budget--) { s->failed_pc=0x0c0a217cu; return 0; }
r[3]=read(ram,0x0c0a2280u,4);
goto P_0c0a217e;
P_0c0a217e: /* original 430b, guest PC 0x0c0a217e */
if(!s->budget--) { s->failed_pc=0x0c0a217eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2182u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2182u) { target=s->pc; goto dispatch; }
goto P_0c0a2182;
P_0c0a2180: /* original 0009, guest PC 0x0c0a2180 */
if(!s->budget--) { s->failed_pc=0x0c0a2180u; return 0; }
goto P_0c0a2182;
P_0c0a2182: /* original 9c75, guest PC 0x0c0a2182 */
if(!s->budget--) { s->failed_pc=0x0c0a2182u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2270u,2);
goto P_0c0a2184;
P_0c0a2184: /* original dd42, guest PC 0x0c0a2184 */
if(!s->budget--) { s->failed_pc=0x0c0a2184u; return 0; }
r[13]=read(ram,0x0c0a2290u,4);
goto P_0c0a2186;
P_0c0a2186: /* original de43, guest PC 0x0c0a2186 */
if(!s->budget--) { s->failed_pc=0x0c0a2186u; return 0; }
r[14]=read(ram,0x0c0a2294u,4);
goto P_0c0a2188;
P_0c0a2188: /* original d83e, guest PC 0x0c0a2188 */
if(!s->budget--) { s->failed_pc=0x0c0a2188u; return 0; }
r[8]=read(ram,0x0c0a2284u,4);
goto P_0c0a218a;
P_0c0a218a: /* original d93f, guest PC 0x0c0a218a */
if(!s->budget--) { s->failed_pc=0x0c0a218au; return 0; }
r[9]=read(ram,0x0c0a2288u,4);
goto P_0c0a218c;
P_0c0a218c: /* original da3f, guest PC 0x0c0a218c */
if(!s->budget--) { s->failed_pc=0x0c0a218cu; return 0; }
r[10]=read(ram,0x0c0a228cu,4);
goto P_0c0a218e;
P_0c0a218e: /* original d342, guest PC 0x0c0a218e */
if(!s->budget--) { s->failed_pc=0x0c0a218eu; return 0; }
r[3]=read(ram,0x0c0a2298u,4);
goto P_0c0a2190;
P_0c0a2190: /* original 430b, guest PC 0x0c0a2190 */
if(!s->budget--) { s->failed_pc=0x0c0a2190u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2194u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2194u) { target=s->pc; goto dispatch; }
goto P_0c0a2194;
P_0c0a2192: /* original e400, guest PC 0x0c0a2192 */
if(!s->budget--) { s->failed_pc=0x0c0a2192u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2194;
P_0c0a2194: /* original d241, guest PC 0x0c0a2194 */
if(!s->budget--) { s->failed_pc=0x0c0a2194u; return 0; }
r[2]=read(ram,0x0c0a229cu,4);
goto P_0c0a2196;
P_0c0a2196: /* original 420b, guest PC 0x0c0a2196 */
if(!s->budget--) { s->failed_pc=0x0c0a2196u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a219au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a219au) { target=s->pc; goto dispatch; }
goto P_0c0a219a;
P_0c0a2198: /* original e401, guest PC 0x0c0a2198 */
if(!s->budget--) { s->failed_pc=0x0c0a2198u; return 0; }
r[4]=0x00000001u;
goto P_0c0a219a;
P_0c0a219a: /* original 480b, guest PC 0x0c0a219a */
if(!s->budget--) { s->failed_pc=0x0c0a219au; return 0; }
target=r[8];
r[16]=code_base|0x0c0a219eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a219eu) { target=s->pc; goto dispatch; }
goto P_0c0a219e;
P_0c0a219c: /* original e400, guest PC 0x0c0a219c */
if(!s->budget--) { s->failed_pc=0x0c0a219cu; return 0; }
r[4]=0x00000000u;
goto P_0c0a219e;
P_0c0a219e: /* original d340, guest PC 0x0c0a219e */
if(!s->budget--) { s->failed_pc=0x0c0a219eu; return 0; }
r[3]=read(ram,0x0c0a22a0u,4);
goto P_0c0a21a0;
P_0c0a21a0: /* original e500, guest PC 0x0c0a21a0 */
if(!s->budget--) { s->failed_pc=0x0c0a21a0u; return 0; }
r[5]=0x00000000u;
goto P_0c0a21a2;
P_0c0a21a2: /* original 430b, guest PC 0x0c0a21a2 */
if(!s->budget--) { s->failed_pc=0x0c0a21a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a21a6u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21a6u) { target=s->pc; goto dispatch; }
goto P_0c0a21a6;
P_0c0a21a4: /* original e403, guest PC 0x0c0a21a4 */
if(!s->budget--) { s->failed_pc=0x0c0a21a4u; return 0; }
r[4]=0x00000003u;
goto P_0c0a21a6;
P_0c0a21a6: /* original e560, guest PC 0x0c0a21a6 */
if(!s->budget--) { s->failed_pc=0x0c0a21a6u; return 0; }
r[5]=0x00000060u;
goto P_0c0a21a8;
P_0c0a21a8: /* original 4e0b, guest PC 0x0c0a21a8 */
if(!s->budget--) { s->failed_pc=0x0c0a21a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a21acu;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21acu) { target=s->pc; goto dispatch; }
goto P_0c0a21ac;
P_0c0a21aa: /* original e40c, guest PC 0x0c0a21aa */
if(!s->budget--) { s->failed_pc=0x0c0a21aau; return 0; }
r[4]=0x0000000cu;
goto P_0c0a21ac;
P_0c0a21ac: /* original d23d, guest PC 0x0c0a21ac */
if(!s->budget--) { s->failed_pc=0x0c0a21acu; return 0; }
r[2]=read(ram,0x0c0a22a4u,4);
goto P_0c0a21ae;
P_0c0a21ae: /* original 4d0b, guest PC 0x0c0a21ae */
if(!s->budget--) { s->failed_pc=0x0c0a21aeu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a21b2u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21b2u) { target=s->pc; goto dispatch; }
goto P_0c0a21b2;
P_0c0a21b0: /* original 2f26, guest PC 0x0c0a21b0 */
if(!s->budget--) { s->failed_pc=0x0c0a21b0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a21b2;
P_0c0a21b2: /* original 65c3, guest PC 0x0c0a21b2 */
if(!s->budget--) { s->failed_pc=0x0c0a21b2u; return 0; }
r[5]=r[12];
goto P_0c0a21b4;
P_0c0a21b4: /* original 4e0b, guest PC 0x0c0a21b4 */
if(!s->budget--) { s->failed_pc=0x0c0a21b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a21b8u;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21b8u) { target=s->pc; goto dispatch; }
goto P_0c0a21b8;
P_0c0a21b6: /* original e40c, guest PC 0x0c0a21b6 */
if(!s->budget--) { s->failed_pc=0x0c0a21b6u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a21b8;
P_0c0a21b8: /* original d33b, guest PC 0x0c0a21b8 */
if(!s->budget--) { s->failed_pc=0x0c0a21b8u; return 0; }
r[3]=read(ram,0x0c0a22a8u,4);
goto P_0c0a21ba;
P_0c0a21ba: /* original 4d0b, guest PC 0x0c0a21ba */
if(!s->budget--) { s->failed_pc=0x0c0a21bau; return 0; }
target=r[13];
r[16]=code_base|0x0c0a21beu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21beu) { target=s->pc; goto dispatch; }
goto P_0c0a21be;
P_0c0a21bc: /* original 2f36, guest PC 0x0c0a21bc */
if(!s->budget--) { s->failed_pc=0x0c0a21bcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a21be;
P_0c0a21be: /* original 7f08, guest PC 0x0c0a21be */
if(!s->budget--) { s->failed_pc=0x0c0a21beu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a21c0;
P_0c0a21c0: /* original 4a0b, guest PC 0x0c0a21c0 */
if(!s->budget--) { s->failed_pc=0x0c0a21c0u; return 0; }
target=r[10];
r[16]=code_base|0x0c0a21c4u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21c4u) { target=s->pc; goto dispatch; }
goto P_0c0a21c4;
P_0c0a21c2: /* original e403, guest PC 0x0c0a21c2 */
if(!s->budget--) { s->failed_pc=0x0c0a21c2u; return 0; }
r[4]=0x00000003u;
goto P_0c0a21c4;
P_0c0a21c4: /* original 490b, guest PC 0x0c0a21c4 */
if(!s->budget--) { s->failed_pc=0x0c0a21c4u; return 0; }
target=r[9];
r[16]=code_base|0x0c0a21c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21c8u) { target=s->pc; goto dispatch; }
goto P_0c0a21c8;
P_0c0a21c6: /* original 0009, guest PC 0x0c0a21c6 */
if(!s->budget--) { s->failed_pc=0x0c0a21c6u; return 0; }
goto P_0c0a21c8;
P_0c0a21c8: /* original d238, guest PC 0x0c0a21c8 */
if(!s->budget--) { s->failed_pc=0x0c0a21c8u; return 0; }
r[2]=read(ram,0x0c0a22acu,4);
goto P_0c0a21ca;
P_0c0a21ca: /* original 420b, guest PC 0x0c0a21ca */
if(!s->budget--) { s->failed_pc=0x0c0a21cau; return 0; }
target=r[2];
r[16]=code_base|0x0c0a21ceu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21ceu) { target=s->pc; goto dispatch; }
goto P_0c0a21ce;
P_0c0a21cc: /* original 0009, guest PC 0x0c0a21cc */
if(!s->budget--) { s->failed_pc=0x0c0a21ccu; return 0; }
goto P_0c0a21ce;
P_0c0a21ce: /* original 2008, guest PC 0x0c0a21ce */
if(!s->budget--) { s->failed_pc=0x0c0a21ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a21d0;
P_0c0a21d0: /* original 8903, guest PC 0x0c0a21d0 */
if(!s->budget--) { s->failed_pc=0x0c0a21d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a21da; }
goto P_0c0a21d2;
P_0c0a21d2: /* original 4b0b, guest PC 0x0c0a21d2 */
if(!s->budget--) { s->failed_pc=0x0c0a21d2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0a21d6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21d6u) { target=s->pc; goto dispatch; }
goto P_0c0a21d6;
P_0c0a21d4: /* original e400, guest PC 0x0c0a21d4 */
if(!s->budget--) { s->failed_pc=0x0c0a21d4u; return 0; }
r[4]=0x00000000u;
goto P_0c0a21d6;
P_0c0a21d6: /* original afda, guest PC 0x0c0a21d6 */
if(!s->budget--) { s->failed_pc=0x0c0a21d6u; return 0; }
goto P_0c0a218e;
P_0c0a21d8: /* original 0009, guest PC 0x0c0a21d8 */
if(!s->budget--) { s->failed_pc=0x0c0a21d8u; return 0; }
goto P_0c0a21da;
P_0c0a21da: /* original d329, guest PC 0x0c0a21da */
if(!s->budget--) { s->failed_pc=0x0c0a21dau; return 0; }
r[3]=read(ram,0x0c0a2280u,4);
goto P_0c0a21dc;
P_0c0a21dc: /* original 430b, guest PC 0x0c0a21dc */
if(!s->budget--) { s->failed_pc=0x0c0a21dcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a21e0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21e0u) { target=s->pc; goto dispatch; }
goto P_0c0a21e0;
P_0c0a21de: /* original 0009, guest PC 0x0c0a21de */
if(!s->budget--) { s->failed_pc=0x0c0a21deu; return 0; }
goto P_0c0a21e0;
P_0c0a21e0: /* original d233, guest PC 0x0c0a21e0 */
if(!s->budget--) { s->failed_pc=0x0c0a21e0u; return 0; }
r[2]=read(ram,0x0c0a22b0u,4);
goto P_0c0a21e2;
P_0c0a21e2: /* original 420b, guest PC 0x0c0a21e2 */
if(!s->budget--) { s->failed_pc=0x0c0a21e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a21e6u;
r[8]=0x0000003cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a21e6u) { target=s->pc; goto dispatch; }
goto P_0c0a21e6;
P_0c0a21e4: /* original e83c, guest PC 0x0c0a21e4 */
if(!s->budget--) { s->failed_pc=0x0c0a21e4u; return 0; }
r[8]=0x0000003cu;
goto P_0c0a21e6;
P_0c0a21e6: /* original 2008, guest PC 0x0c0a21e6 */
if(!s->budget--) { s->failed_pc=0x0c0a21e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a21e8;
P_0c0a21e8: /* original 8d01, guest PC 0x0c0a21e8 */
if(!s->budget--) { s->failed_pc=0x0c0a21e8u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(cond) { goto P_0c0a21ee; }
goto P_0c0a21ec;
P_0c0a21ea: /* original 2f02, guest PC 0x0c0a21ea */
if(!s->budget--) { s->failed_pc=0x0c0a21eau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0a21ec;
P_0c0a21ec: /* original 9841, guest PC 0x0c0a21ec */
if(!s->budget--) { s->failed_pc=0x0c0a21ecu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2272u,2);
goto P_0c0a21ee;
P_0c0a21ee: /* original d431, guest PC 0x0c0a21ee */
if(!s->budget--) { s->failed_pc=0x0c0a21eeu; return 0; }
r[4]=read(ram,0x0c0a22b4u,4);
goto P_0c0a21f0;
P_0c0a21f0: /* original 6243, guest PC 0x0c0a21f0 */
if(!s->budget--) { s->failed_pc=0x0c0a21f0u; return 0; }
r[2]=r[4];
goto P_0c0a21f2;
P_0c0a21f2: /* original 7410, guest PC 0x0c0a21f2 */
if(!s->budget--) { s->failed_pc=0x0c0a21f2u; return 0; }
r[4]+=0x00000010u;
goto P_0c0a21f4;
P_0c0a21f4: /* original 1f21, guest PC 0x0c0a21f4 */
if(!s->budget--) { s->failed_pc=0x0c0a21f4u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a21f6;
P_0c0a21f6: /* original a02e, guest PC 0x0c0a21f6 */
if(!s->budget--) { s->failed_pc=0x0c0a21f6u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0a2256;
P_0c0a21f8: /* original 1f42, guest PC 0x0c0a21f8 */
if(!s->budget--) { s->failed_pc=0x0c0a21f8u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0a21fa;
P_0c0a21fa: /* original 913b, guest PC 0x0c0a21fa */
if(!s->budget--) { s->failed_pc=0x0c0a21fau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2274u,2);
goto P_0c0a21fc;
P_0c0a21fc: /* original 60f2, guest PC 0x0c0a21fc */
if(!s->budget--) { s->failed_pc=0x0c0a21fcu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0a21fe;
P_0c0a21fe: /* original 3010, guest PC 0x0c0a21fe */
if(!s->budget--) { s->failed_pc=0x0c0a21feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0a2200;
P_0c0a2200: /* original 8907, guest PC 0x0c0a2200 */
if(!s->budget--) { s->failed_pc=0x0c0a2200u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2212; }
goto P_0c0a2202;
P_0c0a2202: /* original 8800, guest PC 0x0c0a2202 */
if(!s->budget--) { s->failed_pc=0x0c0a2202u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0a2204;
P_0c0a2204: /* original 8b0c, guest PC 0x0c0a2204 */
if(!s->budget--) { s->failed_pc=0x0c0a2204u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2220; }
goto P_0c0a2206;
P_0c0a2206: /* original e560, guest PC 0x0c0a2206 */
if(!s->budget--) { s->failed_pc=0x0c0a2206u; return 0; }
r[5]=0x00000060u;
goto P_0c0a2208;
P_0c0a2208: /* original 4e0b, guest PC 0x0c0a2208 */
if(!s->budget--) { s->failed_pc=0x0c0a2208u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a220cu;
r[4]=0x0000007cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a220cu) { target=s->pc; goto dispatch; }
goto P_0c0a220c;
P_0c0a220a: /* original e47c, guest PC 0x0c0a220a */
if(!s->budget--) { s->failed_pc=0x0c0a220au; return 0; }
r[4]=0x0000007cu;
goto P_0c0a220c;
P_0c0a220c: /* original d32a, guest PC 0x0c0a220c */
if(!s->budget--) { s->failed_pc=0x0c0a220cu; return 0; }
r[3]=read(ram,0x0c0a22b8u,4);
goto P_0c0a220e;
P_0c0a220e: /* original a00c, guest PC 0x0c0a220e */
if(!s->budget--) { s->failed_pc=0x0c0a220eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a222a;
P_0c0a2210: /* original 2f36, guest PC 0x0c0a2210 */
if(!s->budget--) { s->failed_pc=0x0c0a2210u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2212;
P_0c0a2212: /* original e560, guest PC 0x0c0a2212 */
if(!s->budget--) { s->failed_pc=0x0c0a2212u; return 0; }
r[5]=0x00000060u;
goto P_0c0a2214;
P_0c0a2214: /* original 4e0b, guest PC 0x0c0a2214 */
if(!s->budget--) { s->failed_pc=0x0c0a2214u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2218u;
r[4]=0x0000004cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2218u) { target=s->pc; goto dispatch; }
goto P_0c0a2218;
P_0c0a2216: /* original e44c, guest PC 0x0c0a2216 */
if(!s->budget--) { s->failed_pc=0x0c0a2216u; return 0; }
r[4]=0x0000004cu;
goto P_0c0a2218;
P_0c0a2218: /* original d328, guest PC 0x0c0a2218 */
if(!s->budget--) { s->failed_pc=0x0c0a2218u; return 0; }
r[3]=read(ram,0x0c0a22bcu,4);
goto P_0c0a221a;
P_0c0a221a: /* original 4d0b, guest PC 0x0c0a221a */
if(!s->budget--) { s->failed_pc=0x0c0a221au; return 0; }
target=r[13];
r[16]=code_base|0x0c0a221eu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a221eu) { target=s->pc; goto dispatch; }
goto P_0c0a221e;
P_0c0a221c: /* original 2f36, guest PC 0x0c0a221c */
if(!s->budget--) { s->failed_pc=0x0c0a221cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a221e;
P_0c0a221e: /* original 7f04, guest PC 0x0c0a221e */
if(!s->budget--) { s->failed_pc=0x0c0a221eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a2220;
P_0c0a2220: /* original 65c3, guest PC 0x0c0a2220 */
if(!s->budget--) { s->failed_pc=0x0c0a2220u; return 0; }
r[5]=r[12];
goto P_0c0a2222;
P_0c0a2222: /* original 4e0b, guest PC 0x0c0a2222 */
if(!s->budget--) { s->failed_pc=0x0c0a2222u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2226u;
r[4]=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2226u) { target=s->pc; goto dispatch; }
goto P_0c0a2226;
P_0c0a2224: /* original e470, guest PC 0x0c0a2224 */
if(!s->budget--) { s->failed_pc=0x0c0a2224u; return 0; }
r[4]=0x00000070u;
goto P_0c0a2226;
P_0c0a2226: /* original d226, guest PC 0x0c0a2226 */
if(!s->budget--) { s->failed_pc=0x0c0a2226u; return 0; }
r[2]=read(ram,0x0c0a22c0u,4);
goto P_0c0a2228;
P_0c0a2228: /* original 2f26, guest PC 0x0c0a2228 */
if(!s->budget--) { s->failed_pc=0x0c0a2228u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a222a;
P_0c0a222a: /* original 4d0b, guest PC 0x0c0a222a */
if(!s->budget--) { s->failed_pc=0x0c0a222au; return 0; }
target=r[13];
r[16]=code_base|0x0c0a222eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a222eu) { target=s->pc; goto dispatch; }
goto P_0c0a222e;
P_0c0a222c: /* original 0009, guest PC 0x0c0a222c */
if(!s->budget--) { s->failed_pc=0x0c0a222cu; return 0; }
goto P_0c0a222e;
P_0c0a222e: /* original 7f04, guest PC 0x0c0a222e */
if(!s->budget--) { s->failed_pc=0x0c0a222eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a2230;
P_0c0a2230: /* original 4a0b, guest PC 0x0c0a2230 */
if(!s->budget--) { s->failed_pc=0x0c0a2230u; return 0; }
target=r[10];
r[16]=code_base|0x0c0a2234u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2234u) { target=s->pc; goto dispatch; }
goto P_0c0a2234;
P_0c0a2232: /* original e403, guest PC 0x0c0a2232 */
if(!s->budget--) { s->failed_pc=0x0c0a2232u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2234;
P_0c0a2234: /* original 490b, guest PC 0x0c0a2234 */
if(!s->budget--) { s->failed_pc=0x0c0a2234u; return 0; }
target=r[9];
r[16]=code_base|0x0c0a2238u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2238u) { target=s->pc; goto dispatch; }
goto P_0c0a2238;
P_0c0a2236: /* original 0009, guest PC 0x0c0a2236 */
if(!s->budget--) { s->failed_pc=0x0c0a2236u; return 0; }
goto P_0c0a2238;
P_0c0a2238: /* original 921d, guest PC 0x0c0a2238 */
if(!s->budget--) { s->failed_pc=0x0c0a2238u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2276u,2);
goto P_0c0a223a;
P_0c0a223a: /* original 3823, guest PC 0x0c0a223a */
if(!s->budget--) { s->failed_pc=0x0c0a223au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[2])!=0);
goto P_0c0a223c;
P_0c0a223c: /* original 8909, guest PC 0x0c0a223c */
if(!s->budget--) { s->failed_pc=0x0c0a223cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2252; }
goto P_0c0a223e;
P_0c0a223e: /* original 51f1, guest PC 0x0c0a223e */
if(!s->budget--) { s->failed_pc=0x0c0a223eu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0a2240;
P_0c0a2240: /* original 53f2, guest PC 0x0c0a2240 */
if(!s->budget--) { s->failed_pc=0x0c0a2240u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0a2242;
P_0c0a2242: /* original 8513, guest PC 0x0c0a2242 */
if(!s->budget--) { s->failed_pc=0x0c0a2242u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+6,2);
goto P_0c0a2244;
P_0c0a2244: /* original 620d, guest PC 0x0c0a2244 */
if(!s->budget--) { s->failed_pc=0x0c0a2244u; return 0; }
r[2]=r[0]&65535u;
goto P_0c0a2246;
P_0c0a2246: /* original 8533, guest PC 0x0c0a2246 */
if(!s->budget--) { s->failed_pc=0x0c0a2246u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+6,2);
goto P_0c0a2248;
P_0c0a2248: /* original 9316, guest PC 0x0c0a2248 */
if(!s->budget--) { s->failed_pc=0x0c0a2248u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2278u,2);
goto P_0c0a224a;
P_0c0a224a: /* original 600d, guest PC 0x0c0a224a */
if(!s->budget--) { s->failed_pc=0x0c0a224au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a224c;
P_0c0a224c: /* original 220b, guest PC 0x0c0a224c */
if(!s->budget--) { s->failed_pc=0x0c0a224cu; return 0; }
r[2]|=r[0];
goto P_0c0a224e;
P_0c0a224e: /* original 2238, guest PC 0x0c0a224e */
if(!s->budget--) { s->failed_pc=0x0c0a224eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a2250;
P_0c0a2250: /* original 8b04, guest PC 0x0c0a2250 */
if(!s->budget--) { s->failed_pc=0x0c0a2250u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a225c; }
goto P_0c0a2252;
P_0c0a2252: /* original 4b0b, guest PC 0x0c0a2252 */
if(!s->budget--) { s->failed_pc=0x0c0a2252u; return 0; }
target=r[11];
r[16]=code_base|0x0c0a2256u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2256u) { target=s->pc; goto dispatch; }
goto P_0c0a2256;
P_0c0a2254: /* original e400, guest PC 0x0c0a2254 */
if(!s->budget--) { s->failed_pc=0x0c0a2254u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2256;
P_0c0a2256: /* original 2888, guest PC 0x0c0a2256 */
if(!s->budget--) { s->failed_pc=0x0c0a2256u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0a2258;
P_0c0a2258: /* original 8fcf, guest PC 0x0c0a2258 */
if(!s->budget--) { s->failed_pc=0x0c0a2258u; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(!cond) { goto P_0c0a21fa; }
goto P_0c0a225c;
P_0c0a225a: /* original 78ff, guest PC 0x0c0a225a */
if(!s->budget--) { s->failed_pc=0x0c0a225au; return 0; }
r[8]+=0xffffffffu;
goto P_0c0a225c;
P_0c0a225c: /* original 7f0c, guest PC 0x0c0a225c */
if(!s->budget--) { s->failed_pc=0x0c0a225cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a225e;
P_0c0a225e: /* original 4f26, guest PC 0x0c0a225e */
if(!s->budget--) { s->failed_pc=0x0c0a225eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2260;
P_0c0a2260: /* original 68f6, guest PC 0x0c0a2260 */
if(!s->budget--) { s->failed_pc=0x0c0a2260u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2262;
P_0c0a2262: /* original 69f6, guest PC 0x0c0a2262 */
if(!s->budget--) { s->failed_pc=0x0c0a2262u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2264;
P_0c0a2264: /* original 6af6, guest PC 0x0c0a2264 */
if(!s->budget--) { s->failed_pc=0x0c0a2264u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2266;
P_0c0a2266: /* original 6bf6, guest PC 0x0c0a2266 */
if(!s->budget--) { s->failed_pc=0x0c0a2266u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2268;
P_0c0a2268: /* original 6cf6, guest PC 0x0c0a2268 */
if(!s->budget--) { s->failed_pc=0x0c0a2268u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a226a;
P_0c0a226a: /* original 6df6, guest PC 0x0c0a226a */
if(!s->budget--) { s->failed_pc=0x0c0a226au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a226c;
P_0c0a226c: /* original 000b, guest PC 0x0c0a226c */
if(!s->budget--) { s->failed_pc=0x0c0a226cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a226e: /* original 6ef6, guest PC 0x0c0a226e */
if(!s->budget--) { s->failed_pc=0x0c0a226eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2270u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2270u; return 0; } return 1;
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
return vf3_matrix_family(0x0c0a2386u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
