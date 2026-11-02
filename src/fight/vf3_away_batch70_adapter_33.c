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
int vf3_away_batch70_adapter_33(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a81eeu: goto P_0c0a81ee;
case 0x0c0a81f0u: goto P_0c0a81f0;
case 0x0c0a81f2u: goto P_0c0a81f2;
case 0x0c0a81f4u: goto P_0c0a81f4;
case 0x0c0a81f6u: goto P_0c0a81f6;
case 0x0c0a81f8u: goto P_0c0a81f8;
case 0x0c0a81fau: goto P_0c0a81fa;
case 0x0c0a81fcu: goto P_0c0a81fc;
case 0x0c0a81feu: goto P_0c0a81fe;
case 0x0c0a8200u: goto P_0c0a8200;
case 0x0c0a8202u: goto P_0c0a8202;
case 0x0c0a8204u: goto P_0c0a8204;
case 0x0c0a8206u: goto P_0c0a8206;
case 0x0c0a8208u: goto P_0c0a8208;
case 0x0c0a820au: goto P_0c0a820a;
case 0x0c0a820cu: goto P_0c0a820c;
case 0x0c0a820eu: goto P_0c0a820e;
case 0x0c0a8210u: goto P_0c0a8210;
case 0x0c0a8212u: goto P_0c0a8212;
case 0x0c0a8214u: goto P_0c0a8214;
case 0x0c0a8216u: goto P_0c0a8216;
case 0x0c0a8218u: goto P_0c0a8218;
case 0x0c0a821au: goto P_0c0a821a;
case 0x0c0a821cu: goto P_0c0a821c;
case 0x0c0a821eu: goto P_0c0a821e;
case 0x0c0a8220u: goto P_0c0a8220;
case 0x0c0a8222u: goto P_0c0a8222;
case 0x0c0a8224u: goto P_0c0a8224;
case 0x0c0a8226u: goto P_0c0a8226;
case 0x0c0a8228u: goto P_0c0a8228;
case 0x0c0a822au: goto P_0c0a822a;
case 0x0c0a822cu: goto P_0c0a822c;
case 0x0c0a822eu: goto P_0c0a822e;
case 0x0c0a8230u: goto P_0c0a8230;
case 0x0c0a8232u: goto P_0c0a8232;
case 0x0c0a8234u: goto P_0c0a8234;
case 0x0c0a8236u: goto P_0c0a8236;
case 0x0c0a8238u: goto P_0c0a8238;
case 0x0c0a823au: goto P_0c0a823a;
case 0x0c0a823cu: goto P_0c0a823c;
case 0x0c0a823eu: goto P_0c0a823e;
case 0x0c0a8240u: goto P_0c0a8240;
case 0x0c0a8242u: goto P_0c0a8242;
case 0x0c0a8244u: goto P_0c0a8244;
case 0x0c0a8246u: goto P_0c0a8246;
case 0x0c0a8248u: goto P_0c0a8248;
case 0x0c0a824au: goto P_0c0a824a;
case 0x0c0a824cu: goto P_0c0a824c;
case 0x0c0a824eu: goto P_0c0a824e;
case 0x0c0a8250u: goto P_0c0a8250;
case 0x0c0a8252u: goto P_0c0a8252;
case 0x0c0a8254u: goto P_0c0a8254;
case 0x0c0a8256u: goto P_0c0a8256;
case 0x0c0a8258u: goto P_0c0a8258;
case 0x0c0a825au: goto P_0c0a825a;
case 0x0c0a825cu: goto P_0c0a825c;
case 0x0c0a825eu: goto P_0c0a825e;
case 0x0c0a8260u: goto P_0c0a8260;
case 0x0c0a8262u: goto P_0c0a8262;
case 0x0c0a8264u: goto P_0c0a8264;
case 0x0c0a8266u: goto P_0c0a8266;
case 0x0c0a8268u: goto P_0c0a8268;
case 0x0c0a826au: goto P_0c0a826a;
case 0x0c0a826cu: goto P_0c0a826c;
case 0x0c0a826eu: goto P_0c0a826e;
case 0x0c0a8270u: goto P_0c0a8270;
case 0x0c0a8272u: goto P_0c0a8272;
case 0x0c0a8274u: goto P_0c0a8274;
case 0x0c0a8276u: goto P_0c0a8276;
case 0x0c0a8278u: goto P_0c0a8278;
case 0x0c0a827au: goto P_0c0a827a;
case 0x0c0a827cu: goto P_0c0a827c;
case 0x0c0a827eu: goto P_0c0a827e;
case 0x0c0a8280u: goto P_0c0a8280;
case 0x0c0a8282u: goto P_0c0a8282;
case 0x0c0a8284u: goto P_0c0a8284;
case 0x0c0a8286u: goto P_0c0a8286;
case 0x0c0a8288u: goto P_0c0a8288;
case 0x0c0a828au: goto P_0c0a828a;
case 0x0c0a828cu: goto P_0c0a828c;
case 0x0c0a828eu: goto P_0c0a828e;
case 0x0c0a8290u: goto P_0c0a8290;
case 0x0c0a8292u: goto P_0c0a8292;
case 0x0c0a8294u: goto P_0c0a8294;
case 0x0c0a8296u: goto P_0c0a8296;
case 0x0c0a8298u: goto P_0c0a8298;
case 0x0c0a829au: goto P_0c0a829a;
case 0x0c0a82c0u: goto P_0c0a82c0;
case 0x0c0a82c2u: goto P_0c0a82c2;
case 0x0c0a82c4u: goto P_0c0a82c4;
case 0x0c0a82c6u: goto P_0c0a82c6;
case 0x0c0a82c8u: goto P_0c0a82c8;
case 0x0c0a82cau: goto P_0c0a82ca;
case 0x0c0a82ccu: goto P_0c0a82cc;
case 0x0c0a82ceu: goto P_0c0a82ce;
case 0x0c0a82d0u: goto P_0c0a82d0;
case 0x0c0a82d2u: goto P_0c0a82d2;
case 0x0c0a82d4u: goto P_0c0a82d4;
case 0x0c0a82d6u: goto P_0c0a82d6;
case 0x0c0a82d8u: goto P_0c0a82d8;
case 0x0c0a82dau: goto P_0c0a82da;
case 0x0c0a82dcu: goto P_0c0a82dc;
case 0x0c0a82deu: goto P_0c0a82de;
case 0x0c0a82e0u: goto P_0c0a82e0;
case 0x0c0a82e2u: goto P_0c0a82e2;
case 0x0c0a82e4u: goto P_0c0a82e4;
case 0x0c0a82e6u: goto P_0c0a82e6;
case 0x0c0a82e8u: goto P_0c0a82e8;
case 0x0c0a82eau: goto P_0c0a82ea;
case 0x0c0a82ecu: goto P_0c0a82ec;
case 0x0c0a82eeu: goto P_0c0a82ee;
case 0x0c0a82f0u: goto P_0c0a82f0;
case 0x0c0a82f2u: goto P_0c0a82f2;
case 0x0c0a82f4u: goto P_0c0a82f4;
case 0x0c0a82f6u: goto P_0c0a82f6;
case 0x0c0a82f8u: goto P_0c0a82f8;
case 0x0c0a82fau: goto P_0c0a82fa;
case 0x0c0a82fcu: goto P_0c0a82fc;
case 0x0c0a82feu: goto P_0c0a82fe;
case 0x0c0a8300u: goto P_0c0a8300;
case 0x0c0a8302u: goto P_0c0a8302;
case 0x0c0a8304u: goto P_0c0a8304;
case 0x0c0a8306u: goto P_0c0a8306;
case 0x0c0a8308u: goto P_0c0a8308;
case 0x0c0a830au: goto P_0c0a830a;
case 0x0c0a830cu: goto P_0c0a830c;
case 0x0c0a830eu: goto P_0c0a830e;
case 0x0c0a8310u: goto P_0c0a8310;
case 0x0c0a8312u: goto P_0c0a8312;
case 0x0c0a8314u: goto P_0c0a8314;
case 0x0c0a8316u: goto P_0c0a8316;
case 0x0c0a8318u: goto P_0c0a8318;
case 0x0c0a831au: goto P_0c0a831a;
case 0x0c0a831cu: goto P_0c0a831c;
case 0x0c0a831eu: goto P_0c0a831e;
case 0x0c0a8320u: goto P_0c0a8320;
case 0x0c0a8322u: goto P_0c0a8322;
case 0x0c0a8324u: goto P_0c0a8324;
case 0x0c0a8326u: goto P_0c0a8326;
case 0x0c0a8328u: goto P_0c0a8328;
case 0x0c0a832au: goto P_0c0a832a;
case 0x0c0a832cu: goto P_0c0a832c;
case 0x0c0a832eu: goto P_0c0a832e;
case 0x0c0a8330u: goto P_0c0a8330;
case 0x0c0a8332u: goto P_0c0a8332;
case 0x0c0a8334u: goto P_0c0a8334;
case 0x0c0a8336u: goto P_0c0a8336;
case 0x0c0a8338u: goto P_0c0a8338;
case 0x0c0a833au: goto P_0c0a833a;
case 0x0c0a833cu: goto P_0c0a833c;
case 0x0c0a833eu: goto P_0c0a833e;
case 0x0c0a8340u: goto P_0c0a8340;
case 0x0c0a8342u: goto P_0c0a8342;
case 0x0c0a8344u: goto P_0c0a8344;
case 0x0c0a8346u: goto P_0c0a8346;
case 0x0c0a8348u: goto P_0c0a8348;
case 0x0c0a834au: goto P_0c0a834a;
case 0x0c0a834cu: goto P_0c0a834c;
case 0x0c0a834eu: goto P_0c0a834e;
case 0x0c0a8350u: goto P_0c0a8350;
case 0x0c0a8352u: goto P_0c0a8352;
case 0x0c0a8354u: goto P_0c0a8354;
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
P_0c0a81ee: /* original 2fe6, guest PC 0x0c0a81ee */
if(!s->budget--) { s->failed_pc=0x0c0a81eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f0;
P_0c0a81f0: /* original 2fd6, guest PC 0x0c0a81f0 */
if(!s->budget--) { s->failed_pc=0x0c0a81f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f2;
P_0c0a81f2: /* original 2fc6, guest PC 0x0c0a81f2 */
if(!s->budget--) { s->failed_pc=0x0c0a81f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f4;
P_0c0a81f4: /* original 2fb6, guest PC 0x0c0a81f4 */
if(!s->budget--) { s->failed_pc=0x0c0a81f4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f6;
P_0c0a81f6: /* original 6b43, guest PC 0x0c0a81f6 */
if(!s->budget--) { s->failed_pc=0x0c0a81f6u; return 0; }
r[11]=r[4];
goto P_0c0a81f8;
P_0c0a81f8: /* original 2fa6, guest PC 0x0c0a81f8 */
if(!s->budget--) { s->failed_pc=0x0c0a81f8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81fa;
P_0c0a81fa: /* original eaff, guest PC 0x0c0a81fa */
if(!s->budget--) { s->failed_pc=0x0c0a81fau; return 0; }
r[10]=0xffffffffu;
goto P_0c0a81fc;
P_0c0a81fc: /* original 4f22, guest PC 0x0c0a81fc */
if(!s->budget--) { s->failed_pc=0x0c0a81fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a81fe;
P_0c0a81fe: /* original 4f12, guest PC 0x0c0a81fe */
if(!s->budget--) { s->failed_pc=0x0c0a81feu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8200;
P_0c0a8200: /* original 7ff0, guest PC 0x0c0a8200 */
if(!s->budget--) { s->failed_pc=0x0c0a8200u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8202;
P_0c0a8202: /* original 1f51, guest PC 0x0c0a8202 */
if(!s->budget--) { s->failed_pc=0x0c0a8202u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a8204;
P_0c0a8204: /* original 2f62, guest PC 0x0c0a8204 */
if(!s->budget--) { s->failed_pc=0x0c0a8204u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a8206;
P_0c0a8206: /* original 1f72, guest PC 0x0c0a8206 */
if(!s->budget--) { s->failed_pc=0x0c0a8206u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a8208;
P_0c0a8208: /* original d32a, guest PC 0x0c0a8208 */
if(!s->budget--) { s->failed_pc=0x0c0a8208u; return 0; }
r[3]=read(ram,0x0c0a82b4u,4);
goto P_0c0a820a;
P_0c0a820a: /* original 9249, guest PC 0x0c0a820a */
if(!s->budget--) { s->failed_pc=0x0c0a820au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a82a0u,2);
goto P_0c0a820c;
P_0c0a820c: /* original 6e32, guest PC 0x0c0a820c */
if(!s->budget--) { s->failed_pc=0x0c0a820cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a820e;
P_0c0a820e: /* original 3b23, guest PC 0x0c0a820e */
if(!s->budget--) { s->failed_pc=0x0c0a820eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c0a8210;
P_0c0a8210: /* original 8f03, guest PC 0x0c0a8210 */
if(!s->budget--) { s->failed_pc=0x0c0a8210u; return 0; }
cond=r[17]&1u;
r[12]=r[10];
if(!cond) { goto P_0c0a821a; }
goto P_0c0a8214;
P_0c0a8212: /* original 6ca3, guest PC 0x0c0a8212 */
if(!s->budget--) { s->failed_pc=0x0c0a8212u; return 0; }
r[12]=r[10];
goto P_0c0a8214;
P_0c0a8214: /* original dc28, guest PC 0x0c0a8214 */
if(!s->budget--) { s->failed_pc=0x0c0a8214u; return 0; }
r[12]=read(ram,0x0c0a82b8u,4);
goto P_0c0a8216;
P_0c0a8216: /* original a037, guest PC 0x0c0a8216 */
if(!s->budget--) { s->failed_pc=0x0c0a8216u; return 0; }
goto P_0c0a8288;
P_0c0a8218: /* original 0009, guest PC 0x0c0a8218 */
if(!s->budget--) { s->failed_pc=0x0c0a8218u; return 0; }
goto P_0c0a821a;
P_0c0a821a: /* original d028, guest PC 0x0c0a821a */
if(!s->budget--) { s->failed_pc=0x0c0a821au; return 0; }
r[0]=read(ram,0x0c0a82bcu,4);
goto P_0c0a821c;
P_0c0a821c: /* original 63b3, guest PC 0x0c0a821c */
if(!s->budget--) { s->failed_pc=0x0c0a821cu; return 0; }
r[3]=r[11];
goto P_0c0a821e;
P_0c0a821e: /* original 4308, guest PC 0x0c0a821e */
if(!s->budget--) { s->failed_pc=0x0c0a821eu; return 0; }
r[3]<<=2;
goto P_0c0a8220;
P_0c0a8220: /* original 023e, guest PC 0x0c0a8220 */
if(!s->budget--) { s->failed_pc=0x0c0a8220u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a8222;
P_0c0a8222: /* original 1f23, guest PC 0x0c0a8222 */
if(!s->budget--) { s->failed_pc=0x0c0a8222u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0a8224;
P_0c0a8224: /* original 63f2, guest PC 0x0c0a8224 */
if(!s->budget--) { s->failed_pc=0x0c0a8224u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a8226;
P_0c0a8226: /* original 2338, guest PC 0x0c0a8226 */
if(!s->budget--) { s->failed_pc=0x0c0a8226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a8228;
P_0c0a8228: /* original 892e, guest PC 0x0c0a8228 */
if(!s->budget--) { s->failed_pc=0x0c0a8228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a822a;
P_0c0a822a: /* original 50f1, guest PC 0x0c0a822a */
if(!s->budget--) { s->failed_pc=0x0c0a822au; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a822c;
P_0c0a822c: /* original c803, guest PC 0x0c0a822c */
if(!s->budget--) { s->failed_pc=0x0c0a822cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&3u)==0)!=0);
goto P_0c0a822e;
P_0c0a822e: /* original 8b2b, guest PC 0x0c0a822e */
if(!s->budget--) { s->failed_pc=0x0c0a822eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a8230;
P_0c0a8230: /* original 85ed, guest PC 0x0c0a8230 */
if(!s->budget--) { s->failed_pc=0x0c0a8230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8232;
P_0c0a8232: /* original ed1f, guest PC 0x0c0a8232 */
if(!s->budget--) { s->failed_pc=0x0c0a8232u; return 0; }
r[13]=0x0000001fu;
goto P_0c0a8234;
P_0c0a8234: /* original 600d, guest PC 0x0c0a8234 */
if(!s->budget--) { s->failed_pc=0x0c0a8234u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a8236;
P_0c0a8236: /* original 7001, guest PC 0x0c0a8236 */
if(!s->budget--) { s->failed_pc=0x0c0a8236u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8238;
P_0c0a8238: /* original 2d09, guest PC 0x0c0a8238 */
if(!s->budget--) { s->failed_pc=0x0c0a8238u; return 0; }
r[13]&=r[0];
goto P_0c0a823a;
P_0c0a823a: /* original 85eb, guest PC 0x0c0a823a */
if(!s->budget--) { s->failed_pc=0x0c0a823au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a823c;
P_0c0a823c: /* original 600d, guest PC 0x0c0a823c */
if(!s->budget--) { s->failed_pc=0x0c0a823cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a823e;
P_0c0a823e: /* original 3d00, guest PC 0x0c0a823e */
if(!s->budget--) { s->failed_pc=0x0c0a823eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0a8240;
P_0c0a8240: /* original 8922, guest PC 0x0c0a8240 */
if(!s->budget--) { s->failed_pc=0x0c0a8240u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a8242;
P_0c0a8242: /* original be67, guest PC 0x0c0a8242 */
if(!s->budget--) { s->failed_pc=0x0c0a8242u; return 0; }
target=code_base|0x0c0a7f14u; r[16]=code_base|0x0c0a8246u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8246u) { target=s->pc; goto dispatch; }
goto P_0c0a8246;
P_0c0a8244: /* original 64b3, guest PC 0x0c0a8244 */
if(!s->budget--) { s->failed_pc=0x0c0a8244u; return 0; }
r[4]=r[11];
goto P_0c0a8246;
P_0c0a8246: /* original 2008, guest PC 0x0c0a8246 */
if(!s->budget--) { s->failed_pc=0x0c0a8246u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8248;
P_0c0a8248: /* original 8b1e, guest PC 0x0c0a8248 */
if(!s->budget--) { s->failed_pc=0x0c0a8248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a824a;
P_0c0a824a: /* original e434, guest PC 0x0c0a824a */
if(!s->budget--) { s->failed_pc=0x0c0a824au; return 0; }
r[4]=0x00000034u;
goto P_0c0a824c;
P_0c0a824c: /* original 63e3, guest PC 0x0c0a824c */
if(!s->budget--) { s->failed_pc=0x0c0a824cu; return 0; }
r[3]=r[14];
goto P_0c0a824e;
P_0c0a824e: /* original 2d4f, guest PC 0x0c0a824e */
if(!s->budget--) { s->failed_pc=0x0c0a824eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[4]);
goto P_0c0a8250;
P_0c0a8250: /* original 731c, guest PC 0x0c0a8250 */
if(!s->budget--) { s->failed_pc=0x0c0a8250u; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8252;
P_0c0a8252: /* original 60d3, guest PC 0x0c0a8252 */
if(!s->budget--) { s->failed_pc=0x0c0a8252u; return 0; }
r[0]=r[13];
goto P_0c0a8254;
P_0c0a8254: /* original 81ed, guest PC 0x0c0a8254 */
if(!s->budget--) { s->failed_pc=0x0c0a8254u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0a8256;
P_0c0a8256: /* original e030, guest PC 0x0c0a8256 */
if(!s->budget--) { s->failed_pc=0x0c0a8256u; return 0; }
r[0]=0x00000030u;
goto P_0c0a8258;
P_0c0a8258: /* original 62f2, guest PC 0x0c0a8258 */
if(!s->budget--) { s->failed_pc=0x0c0a8258u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a825a;
P_0c0a825a: /* original 6cd3, guest PC 0x0c0a825a */
if(!s->budget--) { s->failed_pc=0x0c0a825au; return 0; }
r[12]=r[13];
goto P_0c0a825c;
P_0c0a825c: /* original 041a, guest PC 0x0c0a825c */
if(!s->budget--) { s->failed_pc=0x0c0a825cu; return 0; }
r[4]=r[19];
goto P_0c0a825e;
P_0c0a825e: /* original 644f, guest PC 0x0c0a825e */
if(!s->budget--) { s->failed_pc=0x0c0a825eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8260;
P_0c0a8260: /* original 343c, guest PC 0x0c0a8260 */
if(!s->budget--) { s->failed_pc=0x0c0a8260u; return 0; }
r[4]+=r[3];
goto P_0c0a8262;
P_0c0a8262: /* original 6323, guest PC 0x0c0a8262 */
if(!s->budget--) { s->failed_pc=0x0c0a8262u; return 0; }
r[3]=r[2];
goto P_0c0a8264;
P_0c0a8264: /* original 2422, guest PC 0x0c0a8264 */
if(!s->budget--) { s->failed_pc=0x0c0a8264u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0a8266;
P_0c0a8266: /* original e200, guest PC 0x0c0a8266 */
if(!s->budget--) { s->failed_pc=0x0c0a8266u; return 0; }
r[2]=0x00000000u;
goto P_0c0a8268;
P_0c0a8268: /* original 2322, guest PC 0x0c0a8268 */
if(!s->budget--) { s->failed_pc=0x0c0a8268u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0a826a;
P_0c0a826a: /* original 53f1, guest PC 0x0c0a826a */
if(!s->budget--) { s->failed_pc=0x0c0a826au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a826c;
P_0c0a826c: /* original 1431, guest PC 0x0c0a826c */
if(!s->budget--) { s->failed_pc=0x0c0a826cu; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a826e;
P_0c0a826e: /* original 14a7, guest PC 0x0c0a826e */
if(!s->budget--) { s->failed_pc=0x0c0a826eu; return 0; }
write(ram,r[4]+28,r[10],4);
goto P_0c0a8270;
P_0c0a8270: /* original 14a2, guest PC 0x0c0a8270 */
if(!s->budget--) { s->failed_pc=0x0c0a8270u; return 0; }
write(ram,r[4]+8,r[10],4);
goto P_0c0a8272;
P_0c0a8272: /* original 53f3, guest PC 0x0c0a8272 */
if(!s->budget--) { s->failed_pc=0x0c0a8272u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a8274;
P_0c0a8274: /* original 1434, guest PC 0x0c0a8274 */
if(!s->budget--) { s->failed_pc=0x0c0a8274u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0a8276;
P_0c0a8276: /* original 52f2, guest PC 0x0c0a8276 */
if(!s->budget--) { s->failed_pc=0x0c0a8276u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a8278;
P_0c0a8278: /* original 1425, guest PC 0x0c0a8278 */
if(!s->budget--) { s->failed_pc=0x0c0a8278u; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c0a827a;
P_0c0a827a: /* original 53fb, guest PC 0x0c0a827a */
if(!s->budget--) { s->failed_pc=0x0c0a827au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0a827c;
P_0c0a827c: /* original 1436, guest PC 0x0c0a827c */
if(!s->budget--) { s->failed_pc=0x0c0a827cu; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0a827e;
P_0c0a827e: /* original 52fc, guest PC 0x0c0a827e */
if(!s->budget--) { s->failed_pc=0x0c0a827eu; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c0a8280;
P_0c0a8280: /* original 142a, guest PC 0x0c0a8280 */
if(!s->budget--) { s->failed_pc=0x0c0a8280u; return 0; }
write(ram,r[4]+40,r[2],4);
goto P_0c0a8282;
P_0c0a8282: /* original 53fd, guest PC 0x0c0a8282 */
if(!s->budget--) { s->failed_pc=0x0c0a8282u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0a8284;
P_0c0a8284: /* original 143b, guest PC 0x0c0a8284 */
if(!s->budget--) { s->failed_pc=0x0c0a8284u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0a8286;
P_0c0a8286: /* original 04b5, guest PC 0x0c0a8286 */
if(!s->budget--) { s->failed_pc=0x0c0a8286u; return 0; }
write(ram,r[4]+r[0],r[11],2);
goto P_0c0a8288;
P_0c0a8288: /* original 7f10, guest PC 0x0c0a8288 */
if(!s->budget--) { s->failed_pc=0x0c0a8288u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a828a;
P_0c0a828a: /* original 60c3, guest PC 0x0c0a828a */
if(!s->budget--) { s->failed_pc=0x0c0a828au; return 0; }
r[0]=r[12];
goto P_0c0a828c;
P_0c0a828c: /* original 4f16, guest PC 0x0c0a828c */
if(!s->budget--) { s->failed_pc=0x0c0a828cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a828e;
P_0c0a828e: /* original 4f26, guest PC 0x0c0a828e */
if(!s->budget--) { s->failed_pc=0x0c0a828eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8290;
P_0c0a8290: /* original 6af6, guest PC 0x0c0a8290 */
if(!s->budget--) { s->failed_pc=0x0c0a8290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8292;
P_0c0a8292: /* original 6bf6, guest PC 0x0c0a8292 */
if(!s->budget--) { s->failed_pc=0x0c0a8292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8294;
P_0c0a8294: /* original 6cf6, guest PC 0x0c0a8294 */
if(!s->budget--) { s->failed_pc=0x0c0a8294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8296;
P_0c0a8296: /* original 6df6, guest PC 0x0c0a8296 */
if(!s->budget--) { s->failed_pc=0x0c0a8296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8298;
P_0c0a8298: /* original 000b, guest PC 0x0c0a8298 */
if(!s->budget--) { s->failed_pc=0x0c0a8298u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a829a: /* original 6ef6, guest PC 0x0c0a829a */
if(!s->budget--) { s->failed_pc=0x0c0a829au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a829cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a829cu; return 0; } return 1;
P_0c0a82c0: /* original 2fe6, guest PC 0x0c0a82c0 */
if(!s->budget--) { s->failed_pc=0x0c0a82c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c2;
P_0c0a82c2: /* original 2fd6, guest PC 0x0c0a82c2 */
if(!s->budget--) { s->failed_pc=0x0c0a82c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c4;
P_0c0a82c4: /* original 2fc6, guest PC 0x0c0a82c4 */
if(!s->budget--) { s->failed_pc=0x0c0a82c4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c6;
P_0c0a82c6: /* original d324, guest PC 0x0c0a82c6 */
if(!s->budget--) { s->failed_pc=0x0c0a82c6u; return 0; }
r[3]=read(ram,0x0c0a8358u,4);
goto P_0c0a82c8;
P_0c0a82c8: /* original 4f22, guest PC 0x0c0a82c8 */
if(!s->budget--) { s->failed_pc=0x0c0a82c8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a82ca;
P_0c0a82ca: /* original 6e32, guest PC 0x0c0a82ca */
if(!s->budget--) { s->failed_pc=0x0c0a82cau; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a82cc;
P_0c0a82cc: /* original d223, guest PC 0x0c0a82cc */
if(!s->budget--) { s->failed_pc=0x0c0a82ccu; return 0; }
r[2]=read(ram,0x0c0a835cu,4);
goto P_0c0a82ce;
P_0c0a82ce: /* original 61e2, guest PC 0x0c0a82ce */
if(!s->budget--) { s->failed_pc=0x0c0a82ceu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0a82d0;
P_0c0a82d0: /* original 4f12, guest PC 0x0c0a82d0 */
if(!s->budget--) { s->failed_pc=0x0c0a82d0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a82d2;
P_0c0a82d2: /* original 2128, guest PC 0x0c0a82d2 */
if(!s->budget--) { s->failed_pc=0x0c0a82d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0a82d4;
P_0c0a82d4: /* original 8934, guest PC 0x0c0a82d4 */
if(!s->budget--) { s->failed_pc=0x0c0a82d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8340; }
goto P_0c0a82d6;
P_0c0a82d6: /* original 85eb, guest PC 0x0c0a82d6 */
if(!s->budget--) { s->failed_pc=0x0c0a82d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a82d8;
P_0c0a82d8: /* original ed34, guest PC 0x0c0a82d8 */
if(!s->budget--) { s->failed_pc=0x0c0a82d8u; return 0; }
r[13]=0x00000034u;
goto P_0c0a82da;
P_0c0a82da: /* original 61e3, guest PC 0x0c0a82da */
if(!s->budget--) { s->failed_pc=0x0c0a82dau; return 0; }
r[1]=r[14];
goto P_0c0a82dc;
P_0c0a82dc: /* original 711c, guest PC 0x0c0a82dc */
if(!s->budget--) { s->failed_pc=0x0c0a82dcu; return 0; }
r[1]+=0x0000001cu;
goto P_0c0a82de;
P_0c0a82de: /* original 20df, guest PC 0x0c0a82de */
if(!s->budget--) { s->failed_pc=0x0c0a82deu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[13]);
goto P_0c0a82e0;
P_0c0a82e0: /* original 0d1a, guest PC 0x0c0a82e0 */
if(!s->budget--) { s->failed_pc=0x0c0a82e0u; return 0; }
r[13]=r[19];
goto P_0c0a82e2;
P_0c0a82e2: /* original 6ddf, guest PC 0x0c0a82e2 */
if(!s->budget--) { s->failed_pc=0x0c0a82e2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0a82e4;
P_0c0a82e4: /* original 3d1c, guest PC 0x0c0a82e4 */
if(!s->budget--) { s->failed_pc=0x0c0a82e4u; return 0; }
r[13]+=r[1];
goto P_0c0a82e6;
P_0c0a82e6: /* original d11e, guest PC 0x0c0a82e6 */
if(!s->budget--) { s->failed_pc=0x0c0a82e6u; return 0; }
r[1]=read(ram,0x0c0a8360u,4);
goto P_0c0a82e8;
P_0c0a82e8: /* original 410b, guest PC 0x0c0a82e8 */
if(!s->budget--) { s->failed_pc=0x0c0a82e8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a82ecu;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a82ecu) { target=s->pc; goto dispatch; }
goto P_0c0a82ec;
P_0c0a82ea: /* original 54d3, guest PC 0x0c0a82ea */
if(!s->budget--) { s->failed_pc=0x0c0a82eau; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a82ec;
P_0c0a82ec: /* original dc1d, guest PC 0x0c0a82ec */
if(!s->budget--) { s->failed_pc=0x0c0a82ecu; return 0; }
r[12]=read(ram,0x0c0a8364u,4);
goto P_0c0a82ee;
P_0c0a82ee: /* original 4c0b, guest PC 0x0c0a82ee */
if(!s->budget--) { s->failed_pc=0x0c0a82eeu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a82f2u;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a82f2u) { target=s->pc; goto dispatch; }
goto P_0c0a82f2;
P_0c0a82f0: /* original 54d3, guest PC 0x0c0a82f0 */
if(!s->budget--) { s->failed_pc=0x0c0a82f0u; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a82f2;
P_0c0a82f2: /* original 8802, guest PC 0x0c0a82f2 */
if(!s->budget--) { s->failed_pc=0x0c0a82f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a82f4;
P_0c0a82f4: /* original 8dfb, guest PC 0x0c0a82f4 */
if(!s->budget--) { s->failed_pc=0x0c0a82f4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0a82ee; }
goto P_0c0a82f8;
P_0c0a82f6: /* original 6403, guest PC 0x0c0a82f6 */
if(!s->budget--) { s->failed_pc=0x0c0a82f6u; return 0; }
r[4]=r[0];
goto P_0c0a82f8;
P_0c0a82f8: /* original 53d5, guest PC 0x0c0a82f8 */
if(!s->budget--) { s->failed_pc=0x0c0a82f8u; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0a82fa;
P_0c0a82fa: /* original 2338, guest PC 0x0c0a82fa */
if(!s->budget--) { s->failed_pc=0x0c0a82fau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a82fc;
P_0c0a82fc: /* original 8904, guest PC 0x0c0a82fc */
if(!s->budget--) { s->failed_pc=0x0c0a82fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8308; }
goto P_0c0a82fe;
P_0c0a82fe: /* original 53d5, guest PC 0x0c0a82fe */
if(!s->budget--) { s->failed_pc=0x0c0a82feu; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0a8300;
P_0c0a8300: /* original e5ff, guest PC 0x0c0a8300 */
if(!s->budget--) { s->failed_pc=0x0c0a8300u; return 0; }
r[5]=0xffffffffu;
goto P_0c0a8302;
P_0c0a8302: /* original 430b, guest PC 0x0c0a8302 */
if(!s->budget--) { s->failed_pc=0x0c0a8302u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8306u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8306u) { target=s->pc; goto dispatch; }
goto P_0c0a8306;
P_0c0a8304: /* original 64d3, guest PC 0x0c0a8304 */
if(!s->budget--) { s->failed_pc=0x0c0a8304u; return 0; }
r[4]=r[13];
goto P_0c0a8306;
P_0c0a8306: /* original 2008, guest PC 0x0c0a8306 */
if(!s->budget--) { s->failed_pc=0x0c0a8306u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8308;
P_0c0a8308: /* original d317, guest PC 0x0c0a8308 */
if(!s->budget--) { s->failed_pc=0x0c0a8308u; return 0; }
r[3]=read(ram,0x0c0a8368u,4);
goto P_0c0a830a;
P_0c0a830a: /* original 430b, guest PC 0x0c0a830a */
if(!s->budget--) { s->failed_pc=0x0c0a830au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a830eu;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a830eu) { target=s->pc; goto dispatch; }
goto P_0c0a830e;
P_0c0a830c: /* original 54d3, guest PC 0x0c0a830c */
if(!s->budget--) { s->failed_pc=0x0c0a830cu; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a830e;
P_0c0a830e: /* original 62e2, guest PC 0x0c0a830e */
if(!s->budget--) { s->failed_pc=0x0c0a830eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a8310;
P_0c0a8310: /* original d316, guest PC 0x0c0a8310 */
if(!s->budget--) { s->failed_pc=0x0c0a8310u; return 0; }
r[3]=read(ram,0x0c0a836cu,4);
goto P_0c0a8312;
P_0c0a8312: /* original 2239, guest PC 0x0c0a8312 */
if(!s->budget--) { s->failed_pc=0x0c0a8312u; return 0; }
r[2]&=r[3];
goto P_0c0a8314;
P_0c0a8314: /* original a014, guest PC 0x0c0a8314 */
if(!s->budget--) { s->failed_pc=0x0c0a8314u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8340;
P_0c0a8316: /* original 2e22, guest PC 0x0c0a8316 */
if(!s->budget--) { s->failed_pc=0x0c0a8316u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8318;
P_0c0a8318: /* original 85eb, guest PC 0x0c0a8318 */
if(!s->budget--) { s->failed_pc=0x0c0a8318u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a831a;
P_0c0a831a: /* original ed34, guest PC 0x0c0a831a */
if(!s->budget--) { s->failed_pc=0x0c0a831au; return 0; }
r[13]=0x00000034u;
goto P_0c0a831c;
P_0c0a831c: /* original 63e3, guest PC 0x0c0a831c */
if(!s->budget--) { s->failed_pc=0x0c0a831cu; return 0; }
r[3]=r[14];
goto P_0c0a831e;
P_0c0a831e: /* original 731c, guest PC 0x0c0a831e */
if(!s->budget--) { s->failed_pc=0x0c0a831eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8320;
P_0c0a8320: /* original 7001, guest PC 0x0c0a8320 */
if(!s->budget--) { s->failed_pc=0x0c0a8320u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8322;
P_0c0a8322: /* original c91f, guest PC 0x0c0a8322 */
if(!s->budget--) { s->failed_pc=0x0c0a8322u; return 0; }
r[0]&=31u;
goto P_0c0a8324;
P_0c0a8324: /* original 81eb, guest PC 0x0c0a8324 */
if(!s->budget--) { s->failed_pc=0x0c0a8324u; return 0; }
write(ram,r[14]+22,r[0],2);
goto P_0c0a8326;
P_0c0a8326: /* original 85eb, guest PC 0x0c0a8326 */
if(!s->budget--) { s->failed_pc=0x0c0a8326u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a8328;
P_0c0a8328: /* original 20df, guest PC 0x0c0a8328 */
if(!s->budget--) { s->failed_pc=0x0c0a8328u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[13]);
goto P_0c0a832a;
P_0c0a832a: /* original 0d1a, guest PC 0x0c0a832a */
if(!s->budget--) { s->failed_pc=0x0c0a832au; return 0; }
r[13]=r[19];
goto P_0c0a832c;
P_0c0a832c: /* original 6ddf, guest PC 0x0c0a832c */
if(!s->budget--) { s->failed_pc=0x0c0a832cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0a832e;
P_0c0a832e: /* original 3d3c, guest PC 0x0c0a832e */
if(!s->budget--) { s->failed_pc=0x0c0a832eu; return 0; }
r[13]+=r[3];
goto P_0c0a8330;
P_0c0a8330: /* original 52d5, guest PC 0x0c0a8330 */
if(!s->budget--) { s->failed_pc=0x0c0a8330u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0a8332;
P_0c0a8332: /* original 2228, guest PC 0x0c0a8332 */
if(!s->budget--) { s->failed_pc=0x0c0a8332u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a8334;
P_0c0a8334: /* original 8904, guest PC 0x0c0a8334 */
if(!s->budget--) { s->failed_pc=0x0c0a8334u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8340; }
goto P_0c0a8336;
P_0c0a8336: /* original 52d5, guest PC 0x0c0a8336 */
if(!s->budget--) { s->failed_pc=0x0c0a8336u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0a8338;
P_0c0a8338: /* original e5ff, guest PC 0x0c0a8338 */
if(!s->budget--) { s->failed_pc=0x0c0a8338u; return 0; }
r[5]=0xffffffffu;
goto P_0c0a833a;
P_0c0a833a: /* original 420b, guest PC 0x0c0a833a */
if(!s->budget--) { s->failed_pc=0x0c0a833au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a833eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a833eu) { target=s->pc; goto dispatch; }
goto P_0c0a833e;
P_0c0a833c: /* original 64d3, guest PC 0x0c0a833c */
if(!s->budget--) { s->failed_pc=0x0c0a833cu; return 0; }
r[4]=r[13];
goto P_0c0a833e;
P_0c0a833e: /* original 2008, guest PC 0x0c0a833e */
if(!s->budget--) { s->failed_pc=0x0c0a833eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8340;
P_0c0a8340: /* original 85eb, guest PC 0x0c0a8340 */
if(!s->budget--) { s->failed_pc=0x0c0a8340u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a8342;
P_0c0a8342: /* original 6303, guest PC 0x0c0a8342 */
if(!s->budget--) { s->failed_pc=0x0c0a8342u; return 0; }
r[3]=r[0];
goto P_0c0a8344;
P_0c0a8344: /* original 85ed, guest PC 0x0c0a8344 */
if(!s->budget--) { s->failed_pc=0x0c0a8344u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8346;
P_0c0a8346: /* original 3300, guest PC 0x0c0a8346 */
if(!s->budget--) { s->failed_pc=0x0c0a8346u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c0a8348;
P_0c0a8348: /* original 8be6, guest PC 0x0c0a8348 */
if(!s->budget--) { s->failed_pc=0x0c0a8348u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8318; }
goto P_0c0a834a;
P_0c0a834a: /* original 4f16, guest PC 0x0c0a834a */
if(!s->budget--) { s->failed_pc=0x0c0a834au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a834c;
P_0c0a834c: /* original 4f26, guest PC 0x0c0a834c */
if(!s->budget--) { s->failed_pc=0x0c0a834cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a834e;
P_0c0a834e: /* original 6cf6, guest PC 0x0c0a834e */
if(!s->budget--) { s->failed_pc=0x0c0a834eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8350;
P_0c0a8350: /* original 6df6, guest PC 0x0c0a8350 */
if(!s->budget--) { s->failed_pc=0x0c0a8350u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8352;
P_0c0a8352: /* original 000b, guest PC 0x0c0a8352 */
if(!s->budget--) { s->failed_pc=0x0c0a8352u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8354: /* original 6ef6, guest PC 0x0c0a8354 */
if(!s->budget--) { s->failed_pc=0x0c0a8354u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8356u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8356u; return 0; } return 1;
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
