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
int vf3_away_batch151_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b50d2u: goto P_0c0b50d2;
case 0x0c0b50d4u: goto P_0c0b50d4;
case 0x0c0b50d6u: goto P_0c0b50d6;
case 0x0c0b50d8u: goto P_0c0b50d8;
case 0x0c0b50dau: goto P_0c0b50da;
case 0x0c0b50dcu: goto P_0c0b50dc;
case 0x0c0b50deu: goto P_0c0b50de;
case 0x0c0b50e0u: goto P_0c0b50e0;
case 0x0c0b50e2u: goto P_0c0b50e2;
case 0x0c0b50e4u: goto P_0c0b50e4;
case 0x0c0b50e6u: goto P_0c0b50e6;
case 0x0c0b50e8u: goto P_0c0b50e8;
case 0x0c0b50eau: goto P_0c0b50ea;
case 0x0c0b50ecu: goto P_0c0b50ec;
case 0x0c0b50eeu: goto P_0c0b50ee;
case 0x0c0b50f0u: goto P_0c0b50f0;
case 0x0c0b50f2u: goto P_0c0b50f2;
case 0x0c0b50f4u: goto P_0c0b50f4;
case 0x0c0b50f6u: goto P_0c0b50f6;
case 0x0c0b50f8u: goto P_0c0b50f8;
case 0x0c0b50fau: goto P_0c0b50fa;
case 0x0c0b50fcu: goto P_0c0b50fc;
case 0x0c0b50feu: goto P_0c0b50fe;
case 0x0c0b5100u: goto P_0c0b5100;
case 0x0c0b5102u: goto P_0c0b5102;
case 0x0c0b5104u: goto P_0c0b5104;
case 0x0c0b5106u: goto P_0c0b5106;
case 0x0c0b5108u: goto P_0c0b5108;
case 0x0c0b510au: goto P_0c0b510a;
case 0x0c0b510cu: goto P_0c0b510c;
case 0x0c0b510eu: goto P_0c0b510e;
case 0x0c0b5110u: goto P_0c0b5110;
case 0x0c0b5112u: goto P_0c0b5112;
case 0x0c0b5114u: goto P_0c0b5114;
case 0x0c0b5116u: goto P_0c0b5116;
case 0x0c0b5118u: goto P_0c0b5118;
case 0x0c0b511au: goto P_0c0b511a;
case 0x0c0b511cu: goto P_0c0b511c;
case 0x0c0b511eu: goto P_0c0b511e;
case 0x0c0b5120u: goto P_0c0b5120;
case 0x0c0b5122u: goto P_0c0b5122;
case 0x0c0b5124u: goto P_0c0b5124;
case 0x0c0b5126u: goto P_0c0b5126;
case 0x0c0b5128u: goto P_0c0b5128;
case 0x0c0b512au: goto P_0c0b512a;
case 0x0c0b512cu: goto P_0c0b512c;
case 0x0c0b512eu: goto P_0c0b512e;
case 0x0c0b5130u: goto P_0c0b5130;
case 0x0c0b5132u: goto P_0c0b5132;
case 0x0c0b5134u: goto P_0c0b5134;
case 0x0c0b5136u: goto P_0c0b5136;
case 0x0c0b5138u: goto P_0c0b5138;
case 0x0c0b513au: goto P_0c0b513a;
case 0x0c0b513cu: goto P_0c0b513c;
case 0x0c0b513eu: goto P_0c0b513e;
case 0x0c0b5140u: goto P_0c0b5140;
case 0x0c0b5142u: goto P_0c0b5142;
case 0x0c0b5144u: goto P_0c0b5144;
case 0x0c0b5146u: goto P_0c0b5146;
case 0x0c0b5148u: goto P_0c0b5148;
case 0x0c0b514au: goto P_0c0b514a;
case 0x0c0b514cu: goto P_0c0b514c;
case 0x0c0b514eu: goto P_0c0b514e;
case 0x0c0b5150u: goto P_0c0b5150;
case 0x0c0b5152u: goto P_0c0b5152;
case 0x0c0b5154u: goto P_0c0b5154;
case 0x0c0b5156u: goto P_0c0b5156;
case 0x0c0b5158u: goto P_0c0b5158;
case 0x0c0b515au: goto P_0c0b515a;
case 0x0c0b515cu: goto P_0c0b515c;
case 0x0c0b515eu: goto P_0c0b515e;
case 0x0c0b5160u: goto P_0c0b5160;
case 0x0c0b5162u: goto P_0c0b5162;
case 0x0c0b5164u: goto P_0c0b5164;
case 0x0c0b5166u: goto P_0c0b5166;
case 0x0c0b5168u: goto P_0c0b5168;
case 0x0c0b516au: goto P_0c0b516a;
case 0x0c0b516cu: goto P_0c0b516c;
case 0x0c0b516eu: goto P_0c0b516e;
case 0x0c0b5170u: goto P_0c0b5170;
case 0x0c0b5172u: goto P_0c0b5172;
case 0x0c0b5174u: goto P_0c0b5174;
case 0x0c0b5176u: goto P_0c0b5176;
case 0x0c0b5178u: goto P_0c0b5178;
case 0x0c0b517au: goto P_0c0b517a;
case 0x0c0b517cu: goto P_0c0b517c;
case 0x0c0b517eu: goto P_0c0b517e;
case 0x0c0b5180u: goto P_0c0b5180;
case 0x0c0b5182u: goto P_0c0b5182;
case 0x0c0b5184u: goto P_0c0b5184;
case 0x0c0b5186u: goto P_0c0b5186;
case 0x0c0b5188u: goto P_0c0b5188;
case 0x0c0b518au: goto P_0c0b518a;
case 0x0c0b518cu: goto P_0c0b518c;
case 0x0c0b518eu: goto P_0c0b518e;
case 0x0c0b5190u: goto P_0c0b5190;
case 0x0c0b5192u: goto P_0c0b5192;
case 0x0c0b5194u: goto P_0c0b5194;
case 0x0c0b5196u: goto P_0c0b5196;
case 0x0c0b5198u: goto P_0c0b5198;
case 0x0c0b519au: goto P_0c0b519a;
case 0x0c0b519cu: goto P_0c0b519c;
case 0x0c0b519eu: goto P_0c0b519e;
case 0x0c0b51a0u: goto P_0c0b51a0;
case 0x0c0b51a2u: goto P_0c0b51a2;
case 0x0c0b51a4u: goto P_0c0b51a4;
case 0x0c0b51a6u: goto P_0c0b51a6;
case 0x0c0b51a8u: goto P_0c0b51a8;
case 0x0c0b51aau: goto P_0c0b51aa;
case 0x0c0b51acu: goto P_0c0b51ac;
case 0x0c0b51aeu: goto P_0c0b51ae;
case 0x0c0b51b0u: goto P_0c0b51b0;
case 0x0c0b51b2u: goto P_0c0b51b2;
case 0x0c0b51b4u: goto P_0c0b51b4;
case 0x0c0b51b6u: goto P_0c0b51b6;
case 0x0c0b51b8u: goto P_0c0b51b8;
case 0x0c0b51bau: goto P_0c0b51ba;
case 0x0c0b51bcu: goto P_0c0b51bc;
case 0x0c0b51beu: goto P_0c0b51be;
case 0x0c0b51c0u: goto P_0c0b51c0;
case 0x0c0b51c2u: goto P_0c0b51c2;
case 0x0c0b51c4u: goto P_0c0b51c4;
case 0x0c0b51c6u: goto P_0c0b51c6;
case 0x0c0b51c8u: goto P_0c0b51c8;
case 0x0c0b51cau: goto P_0c0b51ca;
case 0x0c0b51ccu: goto P_0c0b51cc;
case 0x0c0b51ceu: goto P_0c0b51ce;
case 0x0c0b51d0u: goto P_0c0b51d0;
case 0x0c0b51d2u: goto P_0c0b51d2;
case 0x0c0b51d4u: goto P_0c0b51d4;
case 0x0c0b51d6u: goto P_0c0b51d6;
case 0x0c0b51d8u: goto P_0c0b51d8;
case 0x0c0b51dau: goto P_0c0b51da;
case 0x0c0b51dcu: goto P_0c0b51dc;
case 0x0c0b51deu: goto P_0c0b51de;
case 0x0c0b51e0u: goto P_0c0b51e0;
case 0x0c0b51e2u: goto P_0c0b51e2;
case 0x0c0b51e4u: goto P_0c0b51e4;
case 0x0c0b51e6u: goto P_0c0b51e6;
case 0x0c0b51e8u: goto P_0c0b51e8;
case 0x0c0b51eau: goto P_0c0b51ea;
case 0x0c0b51ecu: goto P_0c0b51ec;
case 0x0c0b51eeu: goto P_0c0b51ee;
case 0x0c0b51f0u: goto P_0c0b51f0;
case 0x0c0b51f2u: goto P_0c0b51f2;
case 0x0c0b51f4u: goto P_0c0b51f4;
case 0x0c0b51f6u: goto P_0c0b51f6;
case 0x0c0b51f8u: goto P_0c0b51f8;
case 0x0c0b51fau: goto P_0c0b51fa;
case 0x0c0b51fcu: goto P_0c0b51fc;
case 0x0c0b51feu: goto P_0c0b51fe;
case 0x0c0b5200u: goto P_0c0b5200;
case 0x0c0b5202u: goto P_0c0b5202;
case 0x0c0b5204u: goto P_0c0b5204;
case 0x0c0b5206u: goto P_0c0b5206;
case 0x0c0b5208u: goto P_0c0b5208;
case 0x0c0b520au: goto P_0c0b520a;
case 0x0c0b520cu: goto P_0c0b520c;
case 0x0c0b520eu: goto P_0c0b520e;
case 0x0c0b5210u: goto P_0c0b5210;
case 0x0c0b5212u: goto P_0c0b5212;
case 0x0c0b5214u: goto P_0c0b5214;
case 0x0c0b5216u: goto P_0c0b5216;
case 0x0c0b5218u: goto P_0c0b5218;
case 0x0c0b521au: goto P_0c0b521a;
case 0x0c0b521cu: goto P_0c0b521c;
case 0x0c0b521eu: goto P_0c0b521e;
case 0x0c0b5220u: goto P_0c0b5220;
case 0x0c0b5222u: goto P_0c0b5222;
case 0x0c0b5224u: goto P_0c0b5224;
case 0x0c0b5226u: goto P_0c0b5226;
case 0x0c0b5228u: goto P_0c0b5228;
case 0x0c0b522au: goto P_0c0b522a;
case 0x0c0b522cu: goto P_0c0b522c;
case 0x0c0b522eu: goto P_0c0b522e;
case 0x0c0b5230u: goto P_0c0b5230;
case 0x0c0b5232u: goto P_0c0b5232;
case 0x0c0b5234u: goto P_0c0b5234;
case 0x0c0b52a4u: goto P_0c0b52a4;
case 0x0c0b52a6u: goto P_0c0b52a6;
case 0x0c0b52a8u: goto P_0c0b52a8;
case 0x0c0b52aau: goto P_0c0b52aa;
case 0x0c0b52acu: goto P_0c0b52ac;
case 0x0c0b52aeu: goto P_0c0b52ae;
case 0x0c0b52b0u: goto P_0c0b52b0;
case 0x0c0b52b2u: goto P_0c0b52b2;
case 0x0c0b52b4u: goto P_0c0b52b4;
case 0x0c0b52b6u: goto P_0c0b52b6;
case 0x0c0b52b8u: goto P_0c0b52b8;
case 0x0c0b52bau: goto P_0c0b52ba;
case 0x0c0b52bcu: goto P_0c0b52bc;
case 0x0c0b52beu: goto P_0c0b52be;
case 0x0c0b52c0u: goto P_0c0b52c0;
case 0x0c0b52c2u: goto P_0c0b52c2;
case 0x0c0b52c4u: goto P_0c0b52c4;
case 0x0c0b52c6u: goto P_0c0b52c6;
case 0x0c0b52c8u: goto P_0c0b52c8;
case 0x0c0b52cau: goto P_0c0b52ca;
case 0x0c0b52ccu: goto P_0c0b52cc;
case 0x0c0b52ceu: goto P_0c0b52ce;
case 0x0c0b52d0u: goto P_0c0b52d0;
case 0x0c0b52d2u: goto P_0c0b52d2;
case 0x0c0b52d4u: goto P_0c0b52d4;
case 0x0c0b52d6u: goto P_0c0b52d6;
case 0x0c0b52d8u: goto P_0c0b52d8;
case 0x0c0b52dau: goto P_0c0b52da;
case 0x0c0b52dcu: goto P_0c0b52dc;
case 0x0c0b52deu: goto P_0c0b52de;
case 0x0c0b52e0u: goto P_0c0b52e0;
case 0x0c0b52e2u: goto P_0c0b52e2;
case 0x0c0b52e4u: goto P_0c0b52e4;
case 0x0c0b52e6u: goto P_0c0b52e6;
case 0x0c0b52e8u: goto P_0c0b52e8;
case 0x0c0b52eau: goto P_0c0b52ea;
case 0x0c0b52ecu: goto P_0c0b52ec;
case 0x0c0b52eeu: goto P_0c0b52ee;
case 0x0c0b52f0u: goto P_0c0b52f0;
case 0x0c0b52f2u: goto P_0c0b52f2;
case 0x0c0b52f4u: goto P_0c0b52f4;
case 0x0c0b52f6u: goto P_0c0b52f6;
case 0x0c0b52f8u: goto P_0c0b52f8;
case 0x0c0b52fau: goto P_0c0b52fa;
case 0x0c0b52fcu: goto P_0c0b52fc;
case 0x0c0b52feu: goto P_0c0b52fe;
case 0x0c0b5300u: goto P_0c0b5300;
case 0x0c0b5302u: goto P_0c0b5302;
case 0x0c0b5304u: goto P_0c0b5304;
case 0x0c0b5306u: goto P_0c0b5306;
case 0x0c0b5308u: goto P_0c0b5308;
case 0x0c0b530au: goto P_0c0b530a;
case 0x0c0b530cu: goto P_0c0b530c;
case 0x0c0b530eu: goto P_0c0b530e;
case 0x0c0b5310u: goto P_0c0b5310;
case 0x0c0b5312u: goto P_0c0b5312;
case 0x0c0b5314u: goto P_0c0b5314;
case 0x0c0b5316u: goto P_0c0b5316;
case 0x0c0b5318u: goto P_0c0b5318;
case 0x0c0b531au: goto P_0c0b531a;
case 0x0c0b531cu: goto P_0c0b531c;
case 0x0c0b531eu: goto P_0c0b531e;
case 0x0c0b5320u: goto P_0c0b5320;
case 0x0c0b5322u: goto P_0c0b5322;
case 0x0c0b5324u: goto P_0c0b5324;
case 0x0c0b5326u: goto P_0c0b5326;
case 0x0c0b5328u: goto P_0c0b5328;
case 0x0c0b532au: goto P_0c0b532a;
case 0x0c0b532cu: goto P_0c0b532c;
case 0x0c0b532eu: goto P_0c0b532e;
case 0x0c0b5330u: goto P_0c0b5330;
case 0x0c0b5332u: goto P_0c0b5332;
case 0x0c0b5334u: goto P_0c0b5334;
case 0x0c0b5336u: goto P_0c0b5336;
case 0x0c0b5338u: goto P_0c0b5338;
case 0x0c0b533au: goto P_0c0b533a;
case 0x0c0b533cu: goto P_0c0b533c;
case 0x0c0b533eu: goto P_0c0b533e;
case 0x0c0b5340u: goto P_0c0b5340;
case 0x0c0b5342u: goto P_0c0b5342;
case 0x0c0b5344u: goto P_0c0b5344;
case 0x0c0b5346u: goto P_0c0b5346;
case 0x0c0b5348u: goto P_0c0b5348;
case 0x0c0b534au: goto P_0c0b534a;
case 0x0c0b534cu: goto P_0c0b534c;
case 0x0c0b534eu: goto P_0c0b534e;
case 0x0c0b5350u: goto P_0c0b5350;
case 0x0c0b5352u: goto P_0c0b5352;
case 0x0c0b5354u: goto P_0c0b5354;
case 0x0c0b5356u: goto P_0c0b5356;
case 0x0c0b5358u: goto P_0c0b5358;
case 0x0c0b535au: goto P_0c0b535a;
case 0x0c0b535cu: goto P_0c0b535c;
case 0x0c0b535eu: goto P_0c0b535e;
case 0x0c0b5360u: goto P_0c0b5360;
case 0x0c0b5362u: goto P_0c0b5362;
case 0x0c0b5364u: goto P_0c0b5364;
case 0x0c0b5366u: goto P_0c0b5366;
case 0x0c0b5368u: goto P_0c0b5368;
case 0x0c0b536au: goto P_0c0b536a;
case 0x0c0b536cu: goto P_0c0b536c;
case 0x0c0b536eu: goto P_0c0b536e;
case 0x0c0b5370u: goto P_0c0b5370;
case 0x0c0b5372u: goto P_0c0b5372;
case 0x0c0b5374u: goto P_0c0b5374;
case 0x0c0b5376u: goto P_0c0b5376;
case 0x0c0b5378u: goto P_0c0b5378;
case 0x0c0b537au: goto P_0c0b537a;
case 0x0c0b537cu: goto P_0c0b537c;
case 0x0c0b537eu: goto P_0c0b537e;
case 0x0c0b5380u: goto P_0c0b5380;
case 0x0c0b5382u: goto P_0c0b5382;
case 0x0c0b5384u: goto P_0c0b5384;
case 0x0c0b5386u: goto P_0c0b5386;
case 0x0c0b5388u: goto P_0c0b5388;
case 0x0c0b538au: goto P_0c0b538a;
case 0x0c0b538cu: goto P_0c0b538c;
case 0x0c0b538eu: goto P_0c0b538e;
case 0x0c0b5390u: goto P_0c0b5390;
case 0x0c0b5392u: goto P_0c0b5392;
case 0x0c0b5394u: goto P_0c0b5394;
case 0x0c0b5396u: goto P_0c0b5396;
case 0x0c0b5398u: goto P_0c0b5398;
case 0x0c0b539au: goto P_0c0b539a;
case 0x0c0b539cu: goto P_0c0b539c;
case 0x0c0b539eu: goto P_0c0b539e;
case 0x0c0b53a0u: goto P_0c0b53a0;
case 0x0c0b53a2u: goto P_0c0b53a2;
case 0x0c0b53a4u: goto P_0c0b53a4;
case 0x0c0b53a6u: goto P_0c0b53a6;
case 0x0c0b53a8u: goto P_0c0b53a8;
case 0x0c0b53aau: goto P_0c0b53aa;
case 0x0c0b53acu: goto P_0c0b53ac;
case 0x0c0b53aeu: goto P_0c0b53ae;
case 0x0c0b53b0u: goto P_0c0b53b0;
case 0x0c0b53b2u: goto P_0c0b53b2;
case 0x0c0b53b4u: goto P_0c0b53b4;
case 0x0c0b53b6u: goto P_0c0b53b6;
case 0x0c0b53b8u: goto P_0c0b53b8;
case 0x0c0b53bau: goto P_0c0b53ba;
case 0x0c0b53bcu: goto P_0c0b53bc;
case 0x0c0b53beu: goto P_0c0b53be;
case 0x0c0b53c0u: goto P_0c0b53c0;
case 0x0c0b53c2u: goto P_0c0b53c2;
case 0x0c0b53c4u: goto P_0c0b53c4;
case 0x0c0b53c6u: goto P_0c0b53c6;
case 0x0c0b53c8u: goto P_0c0b53c8;
case 0x0c0b53cau: goto P_0c0b53ca;
case 0x0c0b53ccu: goto P_0c0b53cc;
case 0x0c0b53ceu: goto P_0c0b53ce;
case 0x0c0b53d0u: goto P_0c0b53d0;
case 0x0c0b53d2u: goto P_0c0b53d2;
case 0x0c0b53d4u: goto P_0c0b53d4;
case 0x0c0b53d6u: goto P_0c0b53d6;
case 0x0c0b53d8u: goto P_0c0b53d8;
case 0x0c0b53dau: goto P_0c0b53da;
case 0x0c0b53dcu: goto P_0c0b53dc;
case 0x0c0b53deu: goto P_0c0b53de;
case 0x0c0b53e0u: goto P_0c0b53e0;
case 0x0c0b53e2u: goto P_0c0b53e2;
case 0x0c0b53e4u: goto P_0c0b53e4;
case 0x0c0b53e6u: goto P_0c0b53e6;
case 0x0c0b53e8u: goto P_0c0b53e8;
case 0x0c0b53eau: goto P_0c0b53ea;
case 0x0c0b53ecu: goto P_0c0b53ec;
case 0x0c0b53eeu: goto P_0c0b53ee;
case 0x0c0b53f0u: goto P_0c0b53f0;
case 0x0c0b53f2u: goto P_0c0b53f2;
case 0x0c0b53f4u: goto P_0c0b53f4;
case 0x0c0b53f6u: goto P_0c0b53f6;
case 0x0c0b53f8u: goto P_0c0b53f8;
case 0x0c0b53fau: goto P_0c0b53fa;
case 0x0c0b53fcu: goto P_0c0b53fc;
case 0x0c0b5476u: goto P_0c0b5476;
case 0x0c0b5478u: goto P_0c0b5478;
case 0x0c0b547au: goto P_0c0b547a;
case 0x0c0b547cu: goto P_0c0b547c;
case 0x0c0b547eu: goto P_0c0b547e;
case 0x0c0b5480u: goto P_0c0b5480;
case 0x0c0b5482u: goto P_0c0b5482;
case 0x0c0b5484u: goto P_0c0b5484;
case 0x0c0b5486u: goto P_0c0b5486;
case 0x0c0b5488u: goto P_0c0b5488;
case 0x0c0b548au: goto P_0c0b548a;
case 0x0c0b548cu: goto P_0c0b548c;
case 0x0c0b548eu: goto P_0c0b548e;
case 0x0c0b5490u: goto P_0c0b5490;
case 0x0c0b5492u: goto P_0c0b5492;
case 0x0c0b5494u: goto P_0c0b5494;
case 0x0c0b5496u: goto P_0c0b5496;
case 0x0c0b5498u: goto P_0c0b5498;
case 0x0c0b549au: goto P_0c0b549a;
case 0x0c0b549cu: goto P_0c0b549c;
case 0x0c0b549eu: goto P_0c0b549e;
case 0x0c0b54a0u: goto P_0c0b54a0;
case 0x0c0b54a2u: goto P_0c0b54a2;
case 0x0c0b54a4u: goto P_0c0b54a4;
case 0x0c0b54a6u: goto P_0c0b54a6;
case 0x0c0b54a8u: goto P_0c0b54a8;
case 0x0c0b54aau: goto P_0c0b54aa;
case 0x0c0b54acu: goto P_0c0b54ac;
case 0x0c0b54aeu: goto P_0c0b54ae;
case 0x0c0b54b0u: goto P_0c0b54b0;
case 0x0c0b54b2u: goto P_0c0b54b2;
case 0x0c0b54b4u: goto P_0c0b54b4;
case 0x0c0b54b6u: goto P_0c0b54b6;
case 0x0c0b54b8u: goto P_0c0b54b8;
case 0x0c0b54bau: goto P_0c0b54ba;
case 0x0c0b54bcu: goto P_0c0b54bc;
case 0x0c0b54beu: goto P_0c0b54be;
case 0x0c0b54c0u: goto P_0c0b54c0;
case 0x0c0b54c2u: goto P_0c0b54c2;
case 0x0c0b54c4u: goto P_0c0b54c4;
case 0x0c0b54c6u: goto P_0c0b54c6;
case 0x0c0b54c8u: goto P_0c0b54c8;
case 0x0c0b54cau: goto P_0c0b54ca;
case 0x0c0b54ccu: goto P_0c0b54cc;
case 0x0c0b54ceu: goto P_0c0b54ce;
case 0x0c0b54d0u: goto P_0c0b54d0;
case 0x0c0b54d2u: goto P_0c0b54d2;
case 0x0c0b54d4u: goto P_0c0b54d4;
case 0x0c0b54d6u: goto P_0c0b54d6;
case 0x0c0b54d8u: goto P_0c0b54d8;
case 0x0c0b54dau: goto P_0c0b54da;
case 0x0c0b54dcu: goto P_0c0b54dc;
case 0x0c0b54deu: goto P_0c0b54de;
case 0x0c0b54e0u: goto P_0c0b54e0;
case 0x0c0b54e2u: goto P_0c0b54e2;
case 0x0c0b54e4u: goto P_0c0b54e4;
case 0x0c0b54e6u: goto P_0c0b54e6;
case 0x0c0b54e8u: goto P_0c0b54e8;
case 0x0c0b54eau: goto P_0c0b54ea;
case 0x0c0b54ecu: goto P_0c0b54ec;
case 0x0c0b54eeu: goto P_0c0b54ee;
case 0x0c0b54f0u: goto P_0c0b54f0;
case 0x0c0b54f2u: goto P_0c0b54f2;
case 0x0c0b54f4u: goto P_0c0b54f4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b50d2: /* original 2fe6, guest PC 0x0c0b50d2 */
if(!s->budget--) { s->failed_pc=0x0c0b50d2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b50d4;
P_0c0b50d4: /* original 2fd6, guest PC 0x0c0b50d4 */
if(!s->budget--) { s->failed_pc=0x0c0b50d4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b50d6;
P_0c0b50d6: /* original 2fc6, guest PC 0x0c0b50d6 */
if(!s->budget--) { s->failed_pc=0x0c0b50d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b50d8;
P_0c0b50d8: /* original 2fb6, guest PC 0x0c0b50d8 */
if(!s->budget--) { s->failed_pc=0x0c0b50d8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b50da;
P_0c0b50da: /* original 2fa6, guest PC 0x0c0b50da */
if(!s->budget--) { s->failed_pc=0x0c0b50dau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b50dc;
P_0c0b50dc: /* original 2f96, guest PC 0x0c0b50dc */
if(!s->budget--) { s->failed_pc=0x0c0b50dcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b50de;
P_0c0b50de: /* original 4f22, guest PC 0x0c0b50de */
if(!s->budget--) { s->failed_pc=0x0c0b50deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b50e0;
P_0c0b50e0: /* original 5d44, guest PC 0x0c0b50e0 */
if(!s->budget--) { s->failed_pc=0x0c0b50e0u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b50e2;
P_0c0b50e2: /* original 94a8, guest PC 0x0c0b50e2 */
if(!s->budget--) { s->failed_pc=0x0c0b50e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5236u,2);
goto P_0c0b50e4;
P_0c0b50e4: /* original de6e, guest PC 0x0c0b50e4 */
if(!s->budget--) { s->failed_pc=0x0c0b50e4u; return 0; }
r[14]=read(ram,0x0c0b52a0u,4);
goto P_0c0b50e6;
P_0c0b50e6: /* original 7ff8, guest PC 0x0c0b50e6 */
if(!s->budget--) { s->failed_pc=0x0c0b50e6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b50e8;
P_0c0b50e8: /* original 4e0b, guest PC 0x0c0b50e8 */
if(!s->budget--) { s->failed_pc=0x0c0b50e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b50ecu;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b50ecu) { target=s->pc; goto dispatch; }
goto P_0c0b50ec;
P_0c0b50ea: /* original 65d2, guest PC 0x0c0b50ea */
if(!s->budget--) { s->failed_pc=0x0c0b50eau; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b50ec;
P_0c0b50ec: /* original 94a4, guest PC 0x0c0b50ec */
if(!s->budget--) { s->failed_pc=0x0c0b50ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5238u,2);
goto P_0c0b50ee;
P_0c0b50ee: /* original 4e0b, guest PC 0x0c0b50ee */
if(!s->budget--) { s->failed_pc=0x0c0b50eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b50f2u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b50f2u) { target=s->pc; goto dispatch; }
goto P_0c0b50f2;
P_0c0b50f0: /* original 55d1, guest PC 0x0c0b50f0 */
if(!s->budget--) { s->failed_pc=0x0c0b50f0u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b50f2;
P_0c0b50f2: /* original 94a2, guest PC 0x0c0b50f2 */
if(!s->budget--) { s->failed_pc=0x0c0b50f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b523au,2);
goto P_0c0b50f4;
P_0c0b50f4: /* original 4e0b, guest PC 0x0c0b50f4 */
if(!s->budget--) { s->failed_pc=0x0c0b50f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b50f8u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b50f8u) { target=s->pc; goto dispatch; }
goto P_0c0b50f8;
P_0c0b50f6: /* original 55d2, guest PC 0x0c0b50f6 */
if(!s->budget--) { s->failed_pc=0x0c0b50f6u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b50f8;
P_0c0b50f8: /* original 94a0, guest PC 0x0c0b50f8 */
if(!s->budget--) { s->failed_pc=0x0c0b50f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b523cu,2);
goto P_0c0b50fa;
P_0c0b50fa: /* original 4e0b, guest PC 0x0c0b50fa */
if(!s->budget--) { s->failed_pc=0x0c0b50fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b50feu;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b50feu) { target=s->pc; goto dispatch; }
goto P_0c0b50fe;
P_0c0b50fc: /* original 55d3, guest PC 0x0c0b50fc */
if(!s->budget--) { s->failed_pc=0x0c0b50fcu; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b50fe;
P_0c0b50fe: /* original 949e, guest PC 0x0c0b50fe */
if(!s->budget--) { s->failed_pc=0x0c0b50feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b523eu,2);
goto P_0c0b5100;
P_0c0b5100: /* original 4e0b, guest PC 0x0c0b5100 */
if(!s->budget--) { s->failed_pc=0x0c0b5100u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5104u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5104u) { target=s->pc; goto dispatch; }
goto P_0c0b5104;
P_0c0b5102: /* original 55d4, guest PC 0x0c0b5102 */
if(!s->budget--) { s->failed_pc=0x0c0b5102u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b5104;
P_0c0b5104: /* original 949c, guest PC 0x0c0b5104 */
if(!s->budget--) { s->failed_pc=0x0c0b5104u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5240u,2);
goto P_0c0b5106;
P_0c0b5106: /* original 4e0b, guest PC 0x0c0b5106 */
if(!s->budget--) { s->failed_pc=0x0c0b5106u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b510au;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b510au) { target=s->pc; goto dispatch; }
goto P_0c0b510a;
P_0c0b5108: /* original 55d5, guest PC 0x0c0b5108 */
if(!s->budget--) { s->failed_pc=0x0c0b5108u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b510a;
P_0c0b510a: /* original 949a, guest PC 0x0c0b510a */
if(!s->budget--) { s->failed_pc=0x0c0b510au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5242u,2);
goto P_0c0b510c;
P_0c0b510c: /* original 4e0b, guest PC 0x0c0b510c */
if(!s->budget--) { s->failed_pc=0x0c0b510cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5110u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5110u) { target=s->pc; goto dispatch; }
goto P_0c0b5110;
P_0c0b510e: /* original 55d6, guest PC 0x0c0b510e */
if(!s->budget--) { s->failed_pc=0x0c0b510eu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b5110;
P_0c0b5110: /* original 9498, guest PC 0x0c0b5110 */
if(!s->budget--) { s->failed_pc=0x0c0b5110u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5244u,2);
goto P_0c0b5112;
P_0c0b5112: /* original 4e0b, guest PC 0x0c0b5112 */
if(!s->budget--) { s->failed_pc=0x0c0b5112u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5116u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5116u) { target=s->pc; goto dispatch; }
goto P_0c0b5116;
P_0c0b5114: /* original 55d7, guest PC 0x0c0b5114 */
if(!s->budget--) { s->failed_pc=0x0c0b5114u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b5116;
P_0c0b5116: /* original 9496, guest PC 0x0c0b5116 */
if(!s->budget--) { s->failed_pc=0x0c0b5116u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5246u,2);
goto P_0c0b5118;
P_0c0b5118: /* original 4e0b, guest PC 0x0c0b5118 */
if(!s->budget--) { s->failed_pc=0x0c0b5118u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b511cu;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b511cu) { target=s->pc; goto dispatch; }
goto P_0c0b511c;
P_0c0b511a: /* original 55d8, guest PC 0x0c0b511a */
if(!s->budget--) { s->failed_pc=0x0c0b511au; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b511c;
P_0c0b511c: /* original 9494, guest PC 0x0c0b511c */
if(!s->budget--) { s->failed_pc=0x0c0b511cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5248u,2);
goto P_0c0b511e;
P_0c0b511e: /* original 4e0b, guest PC 0x0c0b511e */
if(!s->budget--) { s->failed_pc=0x0c0b511eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5122u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5122u) { target=s->pc; goto dispatch; }
goto P_0c0b5122;
P_0c0b5120: /* original 55d9, guest PC 0x0c0b5120 */
if(!s->budget--) { s->failed_pc=0x0c0b5120u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b5122;
P_0c0b5122: /* original 9492, guest PC 0x0c0b5122 */
if(!s->budget--) { s->failed_pc=0x0c0b5122u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b524au,2);
goto P_0c0b5124;
P_0c0b5124: /* original 4e0b, guest PC 0x0c0b5124 */
if(!s->budget--) { s->failed_pc=0x0c0b5124u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5128u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5128u) { target=s->pc; goto dispatch; }
goto P_0c0b5128;
P_0c0b5126: /* original 55da, guest PC 0x0c0b5126 */
if(!s->budget--) { s->failed_pc=0x0c0b5126u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b5128;
P_0c0b5128: /* original 9490, guest PC 0x0c0b5128 */
if(!s->budget--) { s->failed_pc=0x0c0b5128u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b524cu,2);
goto P_0c0b512a;
P_0c0b512a: /* original 4e0b, guest PC 0x0c0b512a */
if(!s->budget--) { s->failed_pc=0x0c0b512au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b512eu;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b512eu) { target=s->pc; goto dispatch; }
goto P_0c0b512e;
P_0c0b512c: /* original 55db, guest PC 0x0c0b512c */
if(!s->budget--) { s->failed_pc=0x0c0b512cu; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b512e;
P_0c0b512e: /* original 948e, guest PC 0x0c0b512e */
if(!s->budget--) { s->failed_pc=0x0c0b512eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b524eu,2);
goto P_0c0b5130;
P_0c0b5130: /* original 4e0b, guest PC 0x0c0b5130 */
if(!s->budget--) { s->failed_pc=0x0c0b5130u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5134u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5134u) { target=s->pc; goto dispatch; }
goto P_0c0b5134;
P_0c0b5132: /* original 55dc, guest PC 0x0c0b5132 */
if(!s->budget--) { s->failed_pc=0x0c0b5132u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b5134;
P_0c0b5134: /* original 948c, guest PC 0x0c0b5134 */
if(!s->budget--) { s->failed_pc=0x0c0b5134u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5250u,2);
goto P_0c0b5136;
P_0c0b5136: /* original 4e0b, guest PC 0x0c0b5136 */
if(!s->budget--) { s->failed_pc=0x0c0b5136u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b513au;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b513au) { target=s->pc; goto dispatch; }
goto P_0c0b513a;
P_0c0b5138: /* original 55dd, guest PC 0x0c0b5138 */
if(!s->budget--) { s->failed_pc=0x0c0b5138u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b513a;
P_0c0b513a: /* original 948a, guest PC 0x0c0b513a */
if(!s->budget--) { s->failed_pc=0x0c0b513au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5252u,2);
goto P_0c0b513c;
P_0c0b513c: /* original 4e0b, guest PC 0x0c0b513c */
if(!s->budget--) { s->failed_pc=0x0c0b513cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5140u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5140u) { target=s->pc; goto dispatch; }
goto P_0c0b5140;
P_0c0b513e: /* original 55de, guest PC 0x0c0b513e */
if(!s->budget--) { s->failed_pc=0x0c0b513eu; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b5140;
P_0c0b5140: /* original 9488, guest PC 0x0c0b5140 */
if(!s->budget--) { s->failed_pc=0x0c0b5140u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5254u,2);
goto P_0c0b5142;
P_0c0b5142: /* original 4e0b, guest PC 0x0c0b5142 */
if(!s->budget--) { s->failed_pc=0x0c0b5142u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5146u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5146u) { target=s->pc; goto dispatch; }
goto P_0c0b5146;
P_0c0b5144: /* original 55df, guest PC 0x0c0b5144 */
if(!s->budget--) { s->failed_pc=0x0c0b5144u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b5146;
P_0c0b5146: /* original 9486, guest PC 0x0c0b5146 */
if(!s->budget--) { s->failed_pc=0x0c0b5146u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5256u,2);
goto P_0c0b5148;
P_0c0b5148: /* original e040, guest PC 0x0c0b5148 */
if(!s->budget--) { s->failed_pc=0x0c0b5148u; return 0; }
r[0]=0x00000040u;
goto P_0c0b514a;
P_0c0b514a: /* original 4e0b, guest PC 0x0c0b514a */
if(!s->budget--) { s->failed_pc=0x0c0b514au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b514eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b514eu) { target=s->pc; goto dispatch; }
goto P_0c0b514e;
P_0c0b514c: /* original 05de, guest PC 0x0c0b514c */
if(!s->budget--) { s->failed_pc=0x0c0b514cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b514e;
P_0c0b514e: /* original 9483, guest PC 0x0c0b514e */
if(!s->budget--) { s->failed_pc=0x0c0b514eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5258u,2);
goto P_0c0b5150;
P_0c0b5150: /* original e044, guest PC 0x0c0b5150 */
if(!s->budget--) { s->failed_pc=0x0c0b5150u; return 0; }
r[0]=0x00000044u;
goto P_0c0b5152;
P_0c0b5152: /* original 4e0b, guest PC 0x0c0b5152 */
if(!s->budget--) { s->failed_pc=0x0c0b5152u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5156u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5156u) { target=s->pc; goto dispatch; }
goto P_0c0b5156;
P_0c0b5154: /* original 05de, guest PC 0x0c0b5154 */
if(!s->budget--) { s->failed_pc=0x0c0b5154u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5156;
P_0c0b5156: /* original 9480, guest PC 0x0c0b5156 */
if(!s->budget--) { s->failed_pc=0x0c0b5156u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b525au,2);
goto P_0c0b5158;
P_0c0b5158: /* original e048, guest PC 0x0c0b5158 */
if(!s->budget--) { s->failed_pc=0x0c0b5158u; return 0; }
r[0]=0x00000048u;
goto P_0c0b515a;
P_0c0b515a: /* original 4e0b, guest PC 0x0c0b515a */
if(!s->budget--) { s->failed_pc=0x0c0b515au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b515eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b515eu) { target=s->pc; goto dispatch; }
goto P_0c0b515e;
P_0c0b515c: /* original 05de, guest PC 0x0c0b515c */
if(!s->budget--) { s->failed_pc=0x0c0b515cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b515e;
P_0c0b515e: /* original 947d, guest PC 0x0c0b515e */
if(!s->budget--) { s->failed_pc=0x0c0b515eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b525cu,2);
goto P_0c0b5160;
P_0c0b5160: /* original e04c, guest PC 0x0c0b5160 */
if(!s->budget--) { s->failed_pc=0x0c0b5160u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b5162;
P_0c0b5162: /* original 4e0b, guest PC 0x0c0b5162 */
if(!s->budget--) { s->failed_pc=0x0c0b5162u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5166u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5166u) { target=s->pc; goto dispatch; }
goto P_0c0b5166;
P_0c0b5164: /* original 05de, guest PC 0x0c0b5164 */
if(!s->budget--) { s->failed_pc=0x0c0b5164u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5166;
P_0c0b5166: /* original 947a, guest PC 0x0c0b5166 */
if(!s->budget--) { s->failed_pc=0x0c0b5166u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b525eu,2);
goto P_0c0b5168;
P_0c0b5168: /* original e050, guest PC 0x0c0b5168 */
if(!s->budget--) { s->failed_pc=0x0c0b5168u; return 0; }
r[0]=0x00000050u;
goto P_0c0b516a;
P_0c0b516a: /* original 4e0b, guest PC 0x0c0b516a */
if(!s->budget--) { s->failed_pc=0x0c0b516au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b516eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b516eu) { target=s->pc; goto dispatch; }
goto P_0c0b516e;
P_0c0b516c: /* original 05de, guest PC 0x0c0b516c */
if(!s->budget--) { s->failed_pc=0x0c0b516cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b516e;
P_0c0b516e: /* original 9477, guest PC 0x0c0b516e */
if(!s->budget--) { s->failed_pc=0x0c0b516eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5260u,2);
goto P_0c0b5170;
P_0c0b5170: /* original e054, guest PC 0x0c0b5170 */
if(!s->budget--) { s->failed_pc=0x0c0b5170u; return 0; }
r[0]=0x00000054u;
goto P_0c0b5172;
P_0c0b5172: /* original 4e0b, guest PC 0x0c0b5172 */
if(!s->budget--) { s->failed_pc=0x0c0b5172u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5176u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5176u) { target=s->pc; goto dispatch; }
goto P_0c0b5176;
P_0c0b5174: /* original 05de, guest PC 0x0c0b5174 */
if(!s->budget--) { s->failed_pc=0x0c0b5174u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5176;
P_0c0b5176: /* original 9474, guest PC 0x0c0b5176 */
if(!s->budget--) { s->failed_pc=0x0c0b5176u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5262u,2);
goto P_0c0b5178;
P_0c0b5178: /* original e058, guest PC 0x0c0b5178 */
if(!s->budget--) { s->failed_pc=0x0c0b5178u; return 0; }
r[0]=0x00000058u;
goto P_0c0b517a;
P_0c0b517a: /* original 4e0b, guest PC 0x0c0b517a */
if(!s->budget--) { s->failed_pc=0x0c0b517au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b517eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b517eu) { target=s->pc; goto dispatch; }
goto P_0c0b517e;
P_0c0b517c: /* original 05de, guest PC 0x0c0b517c */
if(!s->budget--) { s->failed_pc=0x0c0b517cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b517e;
P_0c0b517e: /* original 9471, guest PC 0x0c0b517e */
if(!s->budget--) { s->failed_pc=0x0c0b517eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5264u,2);
goto P_0c0b5180;
P_0c0b5180: /* original e05c, guest PC 0x0c0b5180 */
if(!s->budget--) { s->failed_pc=0x0c0b5180u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b5182;
P_0c0b5182: /* original 4e0b, guest PC 0x0c0b5182 */
if(!s->budget--) { s->failed_pc=0x0c0b5182u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5186u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5186u) { target=s->pc; goto dispatch; }
goto P_0c0b5186;
P_0c0b5184: /* original 05de, guest PC 0x0c0b5184 */
if(!s->budget--) { s->failed_pc=0x0c0b5184u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5186;
P_0c0b5186: /* original 946e, guest PC 0x0c0b5186 */
if(!s->budget--) { s->failed_pc=0x0c0b5186u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5266u,2);
goto P_0c0b5188;
P_0c0b5188: /* original e060, guest PC 0x0c0b5188 */
if(!s->budget--) { s->failed_pc=0x0c0b5188u; return 0; }
r[0]=0x00000060u;
goto P_0c0b518a;
P_0c0b518a: /* original 4e0b, guest PC 0x0c0b518a */
if(!s->budget--) { s->failed_pc=0x0c0b518au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b518eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b518eu) { target=s->pc; goto dispatch; }
goto P_0c0b518e;
P_0c0b518c: /* original 05de, guest PC 0x0c0b518c */
if(!s->budget--) { s->failed_pc=0x0c0b518cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b518e;
P_0c0b518e: /* original 946b, guest PC 0x0c0b518e */
if(!s->budget--) { s->failed_pc=0x0c0b518eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5268u,2);
goto P_0c0b5190;
P_0c0b5190: /* original e064, guest PC 0x0c0b5190 */
if(!s->budget--) { s->failed_pc=0x0c0b5190u; return 0; }
r[0]=0x00000064u;
goto P_0c0b5192;
P_0c0b5192: /* original 4e0b, guest PC 0x0c0b5192 */
if(!s->budget--) { s->failed_pc=0x0c0b5192u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5196u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5196u) { target=s->pc; goto dispatch; }
goto P_0c0b5196;
P_0c0b5194: /* original 05de, guest PC 0x0c0b5194 */
if(!s->budget--) { s->failed_pc=0x0c0b5194u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5196;
P_0c0b5196: /* original 9468, guest PC 0x0c0b5196 */
if(!s->budget--) { s->failed_pc=0x0c0b5196u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b526au,2);
goto P_0c0b5198;
P_0c0b5198: /* original e068, guest PC 0x0c0b5198 */
if(!s->budget--) { s->failed_pc=0x0c0b5198u; return 0; }
r[0]=0x00000068u;
goto P_0c0b519a;
P_0c0b519a: /* original 4e0b, guest PC 0x0c0b519a */
if(!s->budget--) { s->failed_pc=0x0c0b519au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b519eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b519eu) { target=s->pc; goto dispatch; }
goto P_0c0b519e;
P_0c0b519c: /* original 05de, guest PC 0x0c0b519c */
if(!s->budget--) { s->failed_pc=0x0c0b519cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b519e;
P_0c0b519e: /* original 9465, guest PC 0x0c0b519e */
if(!s->budget--) { s->failed_pc=0x0c0b519eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b526cu,2);
goto P_0c0b51a0;
P_0c0b51a0: /* original e06c, guest PC 0x0c0b51a0 */
if(!s->budget--) { s->failed_pc=0x0c0b51a0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b51a2;
P_0c0b51a2: /* original 4e0b, guest PC 0x0c0b51a2 */
if(!s->budget--) { s->failed_pc=0x0c0b51a2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51a6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51a6u) { target=s->pc; goto dispatch; }
goto P_0c0b51a6;
P_0c0b51a4: /* original 05de, guest PC 0x0c0b51a4 */
if(!s->budget--) { s->failed_pc=0x0c0b51a4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b51a6;
P_0c0b51a6: /* original 9462, guest PC 0x0c0b51a6 */
if(!s->budget--) { s->failed_pc=0x0c0b51a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b526eu,2);
goto P_0c0b51a8;
P_0c0b51a8: /* original e070, guest PC 0x0c0b51a8 */
if(!s->budget--) { s->failed_pc=0x0c0b51a8u; return 0; }
r[0]=0x00000070u;
goto P_0c0b51aa;
P_0c0b51aa: /* original 4e0b, guest PC 0x0c0b51aa */
if(!s->budget--) { s->failed_pc=0x0c0b51aau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51aeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51aeu) { target=s->pc; goto dispatch; }
goto P_0c0b51ae;
P_0c0b51ac: /* original 05de, guest PC 0x0c0b51ac */
if(!s->budget--) { s->failed_pc=0x0c0b51acu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b51ae;
P_0c0b51ae: /* original 945f, guest PC 0x0c0b51ae */
if(!s->budget--) { s->failed_pc=0x0c0b51aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5270u,2);
goto P_0c0b51b0;
P_0c0b51b0: /* original e074, guest PC 0x0c0b51b0 */
if(!s->budget--) { s->failed_pc=0x0c0b51b0u; return 0; }
r[0]=0x00000074u;
goto P_0c0b51b2;
P_0c0b51b2: /* original 4e0b, guest PC 0x0c0b51b2 */
if(!s->budget--) { s->failed_pc=0x0c0b51b2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51b6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51b6u) { target=s->pc; goto dispatch; }
goto P_0c0b51b6;
P_0c0b51b4: /* original 05de, guest PC 0x0c0b51b4 */
if(!s->budget--) { s->failed_pc=0x0c0b51b4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b51b6;
P_0c0b51b6: /* original 945c, guest PC 0x0c0b51b6 */
if(!s->budget--) { s->failed_pc=0x0c0b51b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5272u,2);
goto P_0c0b51b8;
P_0c0b51b8: /* original e078, guest PC 0x0c0b51b8 */
if(!s->budget--) { s->failed_pc=0x0c0b51b8u; return 0; }
r[0]=0x00000078u;
goto P_0c0b51ba;
P_0c0b51ba: /* original 4e0b, guest PC 0x0c0b51ba */
if(!s->budget--) { s->failed_pc=0x0c0b51bau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51beu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51beu) { target=s->pc; goto dispatch; }
goto P_0c0b51be;
P_0c0b51bc: /* original 05de, guest PC 0x0c0b51bc */
if(!s->budget--) { s->failed_pc=0x0c0b51bcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b51be;
P_0c0b51be: /* original 9459, guest PC 0x0c0b51be */
if(!s->budget--) { s->failed_pc=0x0c0b51beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5274u,2);
goto P_0c0b51c0;
P_0c0b51c0: /* original e07c, guest PC 0x0c0b51c0 */
if(!s->budget--) { s->failed_pc=0x0c0b51c0u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b51c2;
P_0c0b51c2: /* original 4e0b, guest PC 0x0c0b51c2 */
if(!s->budget--) { s->failed_pc=0x0c0b51c2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51c6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51c6u) { target=s->pc; goto dispatch; }
goto P_0c0b51c6;
P_0c0b51c4: /* original 05de, guest PC 0x0c0b51c4 */
if(!s->budget--) { s->failed_pc=0x0c0b51c4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b51c6;
P_0c0b51c6: /* original 9457, guest PC 0x0c0b51c6 */
if(!s->budget--) { s->failed_pc=0x0c0b51c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5278u,2);
goto P_0c0b51c8;
P_0c0b51c8: /* original 9055, guest PC 0x0c0b51c8 */
if(!s->budget--) { s->failed_pc=0x0c0b51c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5276u,2);
goto P_0c0b51ca;
P_0c0b51ca: /* original 4e0b, guest PC 0x0c0b51ca */
if(!s->budget--) { s->failed_pc=0x0c0b51cau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51ceu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51ceu) { target=s->pc; goto dispatch; }
goto P_0c0b51ce;
P_0c0b51cc: /* original 05de, guest PC 0x0c0b51cc */
if(!s->budget--) { s->failed_pc=0x0c0b51ccu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b51ce;
P_0c0b51ce: /* original 9554, guest PC 0x0c0b51ce */
if(!s->budget--) { s->failed_pc=0x0c0b51ceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b527au,2);
goto P_0c0b51d0;
P_0c0b51d0: /* original 35dc, guest PC 0x0c0b51d0 */
if(!s->budget--) { s->failed_pc=0x0c0b51d0u; return 0; }
r[5]+=r[13];
goto P_0c0b51d2;
P_0c0b51d2: /* original 2f52, guest PC 0x0c0b51d2 */
if(!s->budget--) { s->failed_pc=0x0c0b51d2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b51d4;
P_0c0b51d4: /* original 9452, guest PC 0x0c0b51d4 */
if(!s->budget--) { s->failed_pc=0x0c0b51d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b527cu,2);
goto P_0c0b51d6;
P_0c0b51d6: /* original 4e0b, guest PC 0x0c0b51d6 */
if(!s->budget--) { s->failed_pc=0x0c0b51d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51dau;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51dau) { target=s->pc; goto dispatch; }
goto P_0c0b51da;
P_0c0b51d8: /* original 6552, guest PC 0x0c0b51d8 */
if(!s->budget--) { s->failed_pc=0x0c0b51d8u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b51da;
P_0c0b51da: /* original 9550, guest PC 0x0c0b51da */
if(!s->budget--) { s->failed_pc=0x0c0b51dau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b527eu,2);
goto P_0c0b51dc;
P_0c0b51dc: /* original 35dc, guest PC 0x0c0b51dc */
if(!s->budget--) { s->failed_pc=0x0c0b51dcu; return 0; }
r[5]+=r[13];
goto P_0c0b51de;
P_0c0b51de: /* original 1f51, guest PC 0x0c0b51de */
if(!s->budget--) { s->failed_pc=0x0c0b51deu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b51e0;
P_0c0b51e0: /* original 944e, guest PC 0x0c0b51e0 */
if(!s->budget--) { s->failed_pc=0x0c0b51e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5280u,2);
goto P_0c0b51e2;
P_0c0b51e2: /* original 4e0b, guest PC 0x0c0b51e2 */
if(!s->budget--) { s->failed_pc=0x0c0b51e2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51e6u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51e6u) { target=s->pc; goto dispatch; }
goto P_0c0b51e6;
P_0c0b51e4: /* original 6552, guest PC 0x0c0b51e4 */
if(!s->budget--) { s->failed_pc=0x0c0b51e4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b51e6;
P_0c0b51e6: /* original 944d, guest PC 0x0c0b51e6 */
if(!s->budget--) { s->failed_pc=0x0c0b51e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5284u,2);
goto P_0c0b51e8;
P_0c0b51e8: /* original 904b, guest PC 0x0c0b51e8 */
if(!s->budget--) { s->failed_pc=0x0c0b51e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5282u,2);
goto P_0c0b51ea;
P_0c0b51ea: /* original 4e0b, guest PC 0x0c0b51ea */
if(!s->budget--) { s->failed_pc=0x0c0b51eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51eeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51eeu) { target=s->pc; goto dispatch; }
goto P_0c0b51ee;
P_0c0b51ec: /* original 05de, guest PC 0x0c0b51ec */
if(!s->budget--) { s->failed_pc=0x0c0b51ecu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b51ee;
P_0c0b51ee: /* original 944b, guest PC 0x0c0b51ee */
if(!s->budget--) { s->failed_pc=0x0c0b51eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5288u,2);
goto P_0c0b51f0;
P_0c0b51f0: /* original 9049, guest PC 0x0c0b51f0 */
if(!s->budget--) { s->failed_pc=0x0c0b51f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5286u,2);
goto P_0c0b51f2;
P_0c0b51f2: /* original 4e0b, guest PC 0x0c0b51f2 */
if(!s->budget--) { s->failed_pc=0x0c0b51f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b51f6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b51f6u) { target=s->pc; goto dispatch; }
goto P_0c0b51f6;
P_0c0b51f4: /* original 05de, guest PC 0x0c0b51f4 */
if(!s->budget--) { s->failed_pc=0x0c0b51f4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b51f6;
P_0c0b51f6: /* original 9948, guest PC 0x0c0b51f6 */
if(!s->budget--) { s->failed_pc=0x0c0b51f6u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b528au,2);
goto P_0c0b51f8;
P_0c0b51f8: /* original 9448, guest PC 0x0c0b51f8 */
if(!s->budget--) { s->failed_pc=0x0c0b51f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b528cu,2);
goto P_0c0b51fa;
P_0c0b51fa: /* original 39dc, guest PC 0x0c0b51fa */
if(!s->budget--) { s->failed_pc=0x0c0b51fau; return 0; }
r[9]+=r[13];
goto P_0c0b51fc;
P_0c0b51fc: /* original 4e0b, guest PC 0x0c0b51fc */
if(!s->budget--) { s->failed_pc=0x0c0b51fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5200u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5200u) { target=s->pc; goto dispatch; }
goto P_0c0b5200;
P_0c0b51fe: /* original 6592, guest PC 0x0c0b51fe */
if(!s->budget--) { s->failed_pc=0x0c0b51feu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5200;
P_0c0b5200: /* original 9445, guest PC 0x0c0b5200 */
if(!s->budget--) { s->failed_pc=0x0c0b5200u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b528eu,2);
goto P_0c0b5202;
P_0c0b5202: /* original 4e0b, guest PC 0x0c0b5202 */
if(!s->budget--) { s->failed_pc=0x0c0b5202u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5206u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5206u) { target=s->pc; goto dispatch; }
goto P_0c0b5206;
P_0c0b5204: /* original 6592, guest PC 0x0c0b5204 */
if(!s->budget--) { s->failed_pc=0x0c0b5204u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5206;
P_0c0b5206: /* original 9443, guest PC 0x0c0b5206 */
if(!s->budget--) { s->failed_pc=0x0c0b5206u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5290u,2);
goto P_0c0b5208;
P_0c0b5208: /* original 4e0b, guest PC 0x0c0b5208 */
if(!s->budget--) { s->failed_pc=0x0c0b5208u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b520cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b520cu) { target=s->pc; goto dispatch; }
goto P_0c0b520c;
P_0c0b520a: /* original 6592, guest PC 0x0c0b520a */
if(!s->budget--) { s->failed_pc=0x0c0b520au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b520c;
P_0c0b520c: /* original 9441, guest PC 0x0c0b520c */
if(!s->budget--) { s->failed_pc=0x0c0b520cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5292u,2);
goto P_0c0b520e;
P_0c0b520e: /* original 4e0b, guest PC 0x0c0b520e */
if(!s->budget--) { s->failed_pc=0x0c0b520eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5212u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5212u) { target=s->pc; goto dispatch; }
goto P_0c0b5212;
P_0c0b5210: /* original 6592, guest PC 0x0c0b5210 */
if(!s->budget--) { s->failed_pc=0x0c0b5210u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5212;
P_0c0b5212: /* original 9c3f, guest PC 0x0c0b5212 */
if(!s->budget--) { s->failed_pc=0x0c0b5212u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5294u,2);
goto P_0c0b5214;
P_0c0b5214: /* original 943f, guest PC 0x0c0b5214 */
if(!s->budget--) { s->failed_pc=0x0c0b5214u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5296u,2);
goto P_0c0b5216;
P_0c0b5216: /* original 3cdc, guest PC 0x0c0b5216 */
if(!s->budget--) { s->failed_pc=0x0c0b5216u; return 0; }
r[12]+=r[13];
goto P_0c0b5218;
P_0c0b5218: /* original 4e0b, guest PC 0x0c0b5218 */
if(!s->budget--) { s->failed_pc=0x0c0b5218u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b521cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b521cu) { target=s->pc; goto dispatch; }
goto P_0c0b521c;
P_0c0b521a: /* original 65c2, guest PC 0x0c0b521a */
if(!s->budget--) { s->failed_pc=0x0c0b521au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b521c;
P_0c0b521c: /* original 943c, guest PC 0x0c0b521c */
if(!s->budget--) { s->failed_pc=0x0c0b521cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5298u,2);
goto P_0c0b521e;
P_0c0b521e: /* original 4e0b, guest PC 0x0c0b521e */
if(!s->budget--) { s->failed_pc=0x0c0b521eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5222u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5222u) { target=s->pc; goto dispatch; }
goto P_0c0b5222;
P_0c0b5220: /* original 65c2, guest PC 0x0c0b5220 */
if(!s->budget--) { s->failed_pc=0x0c0b5220u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5222;
P_0c0b5222: /* original 943a, guest PC 0x0c0b5222 */
if(!s->budget--) { s->failed_pc=0x0c0b5222u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b529au,2);
goto P_0c0b5224;
P_0c0b5224: /* original 4e0b, guest PC 0x0c0b5224 */
if(!s->budget--) { s->failed_pc=0x0c0b5224u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5228u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5228u) { target=s->pc; goto dispatch; }
goto P_0c0b5228;
P_0c0b5226: /* original 65c2, guest PC 0x0c0b5226 */
if(!s->budget--) { s->failed_pc=0x0c0b5226u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5228;
P_0c0b5228: /* original 9438, guest PC 0x0c0b5228 */
if(!s->budget--) { s->failed_pc=0x0c0b5228u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b529cu,2);
goto P_0c0b522a;
P_0c0b522a: /* original 4e0b, guest PC 0x0c0b522a */
if(!s->budget--) { s->failed_pc=0x0c0b522au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b522eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b522eu) { target=s->pc; goto dispatch; }
goto P_0c0b522e;
P_0c0b522c: /* original 65c2, guest PC 0x0c0b522c */
if(!s->budget--) { s->failed_pc=0x0c0b522cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b522e;
P_0c0b522e: /* original 9b36, guest PC 0x0c0b522e */
if(!s->budget--) { s->failed_pc=0x0c0b522eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b529eu,2);
goto P_0c0b5230;
P_0c0b5230: /* original 3bdc, guest PC 0x0c0b5230 */
if(!s->budget--) { s->failed_pc=0x0c0b5230u; return 0; }
r[11]+=r[13];
goto P_0c0b5232;
P_0c0b5232: /* original a037, guest PC 0x0c0b5232 */
if(!s->budget--) { s->failed_pc=0x0c0b5232u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b52a4;
P_0c0b5234: /* original 65b2, guest PC 0x0c0b5234 */
if(!s->budget--) { s->failed_pc=0x0c0b5234u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b5236u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b5236u; return 0; } return 1;
P_0c0b52a4: /* original 94ab, guest PC 0x0c0b52a4 */
if(!s->budget--) { s->failed_pc=0x0c0b52a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b53feu,2);
goto P_0c0b52a6;
P_0c0b52a6: /* original 4e0b, guest PC 0x0c0b52a6 */
if(!s->budget--) { s->failed_pc=0x0c0b52a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52aau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52aau) { target=s->pc; goto dispatch; }
goto P_0c0b52aa;
P_0c0b52a8: /* original 0009, guest PC 0x0c0b52a8 */
if(!s->budget--) { s->failed_pc=0x0c0b52a8u; return 0; }
goto P_0c0b52aa;
P_0c0b52aa: /* original 94a9, guest PC 0x0c0b52aa */
if(!s->budget--) { s->failed_pc=0x0c0b52aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5400u,2);
goto P_0c0b52ac;
P_0c0b52ac: /* original 4e0b, guest PC 0x0c0b52ac */
if(!s->budget--) { s->failed_pc=0x0c0b52acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52b0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52b0u) { target=s->pc; goto dispatch; }
goto P_0c0b52b0;
P_0c0b52ae: /* original 65b2, guest PC 0x0c0b52ae */
if(!s->budget--) { s->failed_pc=0x0c0b52aeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b52b0;
P_0c0b52b0: /* original 94a7, guest PC 0x0c0b52b0 */
if(!s->budget--) { s->failed_pc=0x0c0b52b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5402u,2);
goto P_0c0b52b2;
P_0c0b52b2: /* original 4e0b, guest PC 0x0c0b52b2 */
if(!s->budget--) { s->failed_pc=0x0c0b52b2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52b6u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52b6u) { target=s->pc; goto dispatch; }
goto P_0c0b52b6;
P_0c0b52b4: /* original 65b2, guest PC 0x0c0b52b4 */
if(!s->budget--) { s->failed_pc=0x0c0b52b4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b52b6;
P_0c0b52b6: /* original 94a5, guest PC 0x0c0b52b6 */
if(!s->budget--) { s->failed_pc=0x0c0b52b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5404u,2);
goto P_0c0b52b8;
P_0c0b52b8: /* original 4e0b, guest PC 0x0c0b52b8 */
if(!s->budget--) { s->failed_pc=0x0c0b52b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52bcu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52bcu) { target=s->pc; goto dispatch; }
goto P_0c0b52bc;
P_0c0b52ba: /* original 65b2, guest PC 0x0c0b52ba */
if(!s->budget--) { s->failed_pc=0x0c0b52bau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b52bc;
P_0c0b52bc: /* original 9aa3, guest PC 0x0c0b52bc */
if(!s->budget--) { s->failed_pc=0x0c0b52bcu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5406u,2);
goto P_0c0b52be;
P_0c0b52be: /* original 94a3, guest PC 0x0c0b52be */
if(!s->budget--) { s->failed_pc=0x0c0b52beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5408u,2);
goto P_0c0b52c0;
P_0c0b52c0: /* original 3adc, guest PC 0x0c0b52c0 */
if(!s->budget--) { s->failed_pc=0x0c0b52c0u; return 0; }
r[10]+=r[13];
goto P_0c0b52c2;
P_0c0b52c2: /* original 4e0b, guest PC 0x0c0b52c2 */
if(!s->budget--) { s->failed_pc=0x0c0b52c2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52c6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52c6u) { target=s->pc; goto dispatch; }
goto P_0c0b52c6;
P_0c0b52c4: /* original 65a2, guest PC 0x0c0b52c4 */
if(!s->budget--) { s->failed_pc=0x0c0b52c4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b52c6;
P_0c0b52c6: /* original 94a0, guest PC 0x0c0b52c6 */
if(!s->budget--) { s->failed_pc=0x0c0b52c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b540au,2);
goto P_0c0b52c8;
P_0c0b52c8: /* original 4e0b, guest PC 0x0c0b52c8 */
if(!s->budget--) { s->failed_pc=0x0c0b52c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52ccu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52ccu) { target=s->pc; goto dispatch; }
goto P_0c0b52cc;
P_0c0b52ca: /* original 65a2, guest PC 0x0c0b52ca */
if(!s->budget--) { s->failed_pc=0x0c0b52cau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b52cc;
P_0c0b52cc: /* original 949e, guest PC 0x0c0b52cc */
if(!s->budget--) { s->failed_pc=0x0c0b52ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b540cu,2);
goto P_0c0b52ce;
P_0c0b52ce: /* original 4e0b, guest PC 0x0c0b52ce */
if(!s->budget--) { s->failed_pc=0x0c0b52ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52d2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52d2u) { target=s->pc; goto dispatch; }
goto P_0c0b52d2;
P_0c0b52d0: /* original 65a2, guest PC 0x0c0b52d0 */
if(!s->budget--) { s->failed_pc=0x0c0b52d0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b52d2;
P_0c0b52d2: /* original 949c, guest PC 0x0c0b52d2 */
if(!s->budget--) { s->failed_pc=0x0c0b52d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b540eu,2);
goto P_0c0b52d4;
P_0c0b52d4: /* original 4e0b, guest PC 0x0c0b52d4 */
if(!s->budget--) { s->failed_pc=0x0c0b52d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52d8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52d8u) { target=s->pc; goto dispatch; }
goto P_0c0b52d8;
P_0c0b52d6: /* original 65a2, guest PC 0x0c0b52d6 */
if(!s->budget--) { s->failed_pc=0x0c0b52d6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b52d8;
P_0c0b52d8: /* original 949a, guest PC 0x0c0b52d8 */
if(!s->budget--) { s->failed_pc=0x0c0b52d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5410u,2);
goto P_0c0b52da;
P_0c0b52da: /* original 65f2, guest PC 0x0c0b52da */
if(!s->budget--) { s->failed_pc=0x0c0b52dau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b52dc;
P_0c0b52dc: /* original 4e0b, guest PC 0x0c0b52dc */
if(!s->budget--) { s->failed_pc=0x0c0b52dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52e0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52e0u) { target=s->pc; goto dispatch; }
goto P_0c0b52e0;
P_0c0b52de: /* original 6552, guest PC 0x0c0b52de */
if(!s->budget--) { s->failed_pc=0x0c0b52deu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b52e0;
P_0c0b52e0: /* original 9497, guest PC 0x0c0b52e0 */
if(!s->budget--) { s->failed_pc=0x0c0b52e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5412u,2);
goto P_0c0b52e2;
P_0c0b52e2: /* original 55f1, guest PC 0x0c0b52e2 */
if(!s->budget--) { s->failed_pc=0x0c0b52e2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b52e4;
P_0c0b52e4: /* original 4e0b, guest PC 0x0c0b52e4 */
if(!s->budget--) { s->failed_pc=0x0c0b52e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52e8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52e8u) { target=s->pc; goto dispatch; }
goto P_0c0b52e8;
P_0c0b52e6: /* original 6552, guest PC 0x0c0b52e6 */
if(!s->budget--) { s->failed_pc=0x0c0b52e6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b52e8;
P_0c0b52e8: /* original 9494, guest PC 0x0c0b52e8 */
if(!s->budget--) { s->failed_pc=0x0c0b52e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5414u,2);
goto P_0c0b52ea;
P_0c0b52ea: /* original 4e0b, guest PC 0x0c0b52ea */
if(!s->budget--) { s->failed_pc=0x0c0b52eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52eeu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52eeu) { target=s->pc; goto dispatch; }
goto P_0c0b52ee;
P_0c0b52ec: /* original 6592, guest PC 0x0c0b52ec */
if(!s->budget--) { s->failed_pc=0x0c0b52ecu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b52ee;
P_0c0b52ee: /* original 9492, guest PC 0x0c0b52ee */
if(!s->budget--) { s->failed_pc=0x0c0b52eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5416u,2);
goto P_0c0b52f0;
P_0c0b52f0: /* original 4e0b, guest PC 0x0c0b52f0 */
if(!s->budget--) { s->failed_pc=0x0c0b52f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52f4u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52f4u) { target=s->pc; goto dispatch; }
goto P_0c0b52f4;
P_0c0b52f2: /* original 6592, guest PC 0x0c0b52f2 */
if(!s->budget--) { s->failed_pc=0x0c0b52f2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b52f4;
P_0c0b52f4: /* original 9490, guest PC 0x0c0b52f4 */
if(!s->budget--) { s->failed_pc=0x0c0b52f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5418u,2);
goto P_0c0b52f6;
P_0c0b52f6: /* original 4e0b, guest PC 0x0c0b52f6 */
if(!s->budget--) { s->failed_pc=0x0c0b52f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b52fau;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b52fau) { target=s->pc; goto dispatch; }
goto P_0c0b52fa;
P_0c0b52f8: /* original 6592, guest PC 0x0c0b52f8 */
if(!s->budget--) { s->failed_pc=0x0c0b52f8u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b52fa;
P_0c0b52fa: /* original 948e, guest PC 0x0c0b52fa */
if(!s->budget--) { s->failed_pc=0x0c0b52fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b541au,2);
goto P_0c0b52fc;
P_0c0b52fc: /* original 4e0b, guest PC 0x0c0b52fc */
if(!s->budget--) { s->failed_pc=0x0c0b52fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5300u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5300u) { target=s->pc; goto dispatch; }
goto P_0c0b5300;
P_0c0b52fe: /* original 6592, guest PC 0x0c0b52fe */
if(!s->budget--) { s->failed_pc=0x0c0b52feu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5300;
P_0c0b5300: /* original 948c, guest PC 0x0c0b5300 */
if(!s->budget--) { s->failed_pc=0x0c0b5300u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b541cu,2);
goto P_0c0b5302;
P_0c0b5302: /* original 4e0b, guest PC 0x0c0b5302 */
if(!s->budget--) { s->failed_pc=0x0c0b5302u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5306u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5306u) { target=s->pc; goto dispatch; }
goto P_0c0b5306;
P_0c0b5304: /* original 65c2, guest PC 0x0c0b5304 */
if(!s->budget--) { s->failed_pc=0x0c0b5304u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5306;
P_0c0b5306: /* original 948a, guest PC 0x0c0b5306 */
if(!s->budget--) { s->failed_pc=0x0c0b5306u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b541eu,2);
goto P_0c0b5308;
P_0c0b5308: /* original 4e0b, guest PC 0x0c0b5308 */
if(!s->budget--) { s->failed_pc=0x0c0b5308u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b530cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b530cu) { target=s->pc; goto dispatch; }
goto P_0c0b530c;
P_0c0b530a: /* original 65c2, guest PC 0x0c0b530a */
if(!s->budget--) { s->failed_pc=0x0c0b530au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b530c;
P_0c0b530c: /* original 9488, guest PC 0x0c0b530c */
if(!s->budget--) { s->failed_pc=0x0c0b530cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5420u,2);
goto P_0c0b530e;
P_0c0b530e: /* original 4e0b, guest PC 0x0c0b530e */
if(!s->budget--) { s->failed_pc=0x0c0b530eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5312u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5312u) { target=s->pc; goto dispatch; }
goto P_0c0b5312;
P_0c0b5310: /* original 65c2, guest PC 0x0c0b5310 */
if(!s->budget--) { s->failed_pc=0x0c0b5310u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5312;
P_0c0b5312: /* original 9486, guest PC 0x0c0b5312 */
if(!s->budget--) { s->failed_pc=0x0c0b5312u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5422u,2);
goto P_0c0b5314;
P_0c0b5314: /* original 4e0b, guest PC 0x0c0b5314 */
if(!s->budget--) { s->failed_pc=0x0c0b5314u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5318u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5318u) { target=s->pc; goto dispatch; }
goto P_0c0b5318;
P_0c0b5316: /* original 65c2, guest PC 0x0c0b5316 */
if(!s->budget--) { s->failed_pc=0x0c0b5316u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5318;
P_0c0b5318: /* original 9484, guest PC 0x0c0b5318 */
if(!s->budget--) { s->failed_pc=0x0c0b5318u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5424u,2);
goto P_0c0b531a;
P_0c0b531a: /* original 4e0b, guest PC 0x0c0b531a */
if(!s->budget--) { s->failed_pc=0x0c0b531au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b531eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b531eu) { target=s->pc; goto dispatch; }
goto P_0c0b531e;
P_0c0b531c: /* original 65b2, guest PC 0x0c0b531c */
if(!s->budget--) { s->failed_pc=0x0c0b531cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b531e;
P_0c0b531e: /* original 9482, guest PC 0x0c0b531e */
if(!s->budget--) { s->failed_pc=0x0c0b531eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5426u,2);
goto P_0c0b5320;
P_0c0b5320: /* original 4e0b, guest PC 0x0c0b5320 */
if(!s->budget--) { s->failed_pc=0x0c0b5320u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5324u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5324u) { target=s->pc; goto dispatch; }
goto P_0c0b5324;
P_0c0b5322: /* original 65b2, guest PC 0x0c0b5322 */
if(!s->budget--) { s->failed_pc=0x0c0b5322u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5324;
P_0c0b5324: /* original 9480, guest PC 0x0c0b5324 */
if(!s->budget--) { s->failed_pc=0x0c0b5324u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5428u,2);
goto P_0c0b5326;
P_0c0b5326: /* original 4e0b, guest PC 0x0c0b5326 */
if(!s->budget--) { s->failed_pc=0x0c0b5326u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b532au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b532au) { target=s->pc; goto dispatch; }
goto P_0c0b532a;
P_0c0b5328: /* original 65b2, guest PC 0x0c0b5328 */
if(!s->budget--) { s->failed_pc=0x0c0b5328u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b532a;
P_0c0b532a: /* original 947e, guest PC 0x0c0b532a */
if(!s->budget--) { s->failed_pc=0x0c0b532au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b542au,2);
goto P_0c0b532c;
P_0c0b532c: /* original 4e0b, guest PC 0x0c0b532c */
if(!s->budget--) { s->failed_pc=0x0c0b532cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5330u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5330u) { target=s->pc; goto dispatch; }
goto P_0c0b5330;
P_0c0b532e: /* original 65b2, guest PC 0x0c0b532e */
if(!s->budget--) { s->failed_pc=0x0c0b532eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5330;
P_0c0b5330: /* original 947c, guest PC 0x0c0b5330 */
if(!s->budget--) { s->failed_pc=0x0c0b5330u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b542cu,2);
goto P_0c0b5332;
P_0c0b5332: /* original 4e0b, guest PC 0x0c0b5332 */
if(!s->budget--) { s->failed_pc=0x0c0b5332u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5336u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5336u) { target=s->pc; goto dispatch; }
goto P_0c0b5336;
P_0c0b5334: /* original 65a2, guest PC 0x0c0b5334 */
if(!s->budget--) { s->failed_pc=0x0c0b5334u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5336;
P_0c0b5336: /* original 947a, guest PC 0x0c0b5336 */
if(!s->budget--) { s->failed_pc=0x0c0b5336u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b542eu,2);
goto P_0c0b5338;
P_0c0b5338: /* original 4e0b, guest PC 0x0c0b5338 */
if(!s->budget--) { s->failed_pc=0x0c0b5338u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b533cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b533cu) { target=s->pc; goto dispatch; }
goto P_0c0b533c;
P_0c0b533a: /* original 65a2, guest PC 0x0c0b533a */
if(!s->budget--) { s->failed_pc=0x0c0b533au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b533c;
P_0c0b533c: /* original 9478, guest PC 0x0c0b533c */
if(!s->budget--) { s->failed_pc=0x0c0b533cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5430u,2);
goto P_0c0b533e;
P_0c0b533e: /* original 4e0b, guest PC 0x0c0b533e */
if(!s->budget--) { s->failed_pc=0x0c0b533eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5342u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5342u) { target=s->pc; goto dispatch; }
goto P_0c0b5342;
P_0c0b5340: /* original 65a2, guest PC 0x0c0b5340 */
if(!s->budget--) { s->failed_pc=0x0c0b5340u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5342;
P_0c0b5342: /* original 9476, guest PC 0x0c0b5342 */
if(!s->budget--) { s->failed_pc=0x0c0b5342u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5432u,2);
goto P_0c0b5344;
P_0c0b5344: /* original 4e0b, guest PC 0x0c0b5344 */
if(!s->budget--) { s->failed_pc=0x0c0b5344u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5348u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5348u) { target=s->pc; goto dispatch; }
goto P_0c0b5348;
P_0c0b5346: /* original 65a2, guest PC 0x0c0b5346 */
if(!s->budget--) { s->failed_pc=0x0c0b5346u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5348;
P_0c0b5348: /* original 9574, guest PC 0x0c0b5348 */
if(!s->budget--) { s->failed_pc=0x0c0b5348u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5434u,2);
goto P_0c0b534a;
P_0c0b534a: /* original 35dc, guest PC 0x0c0b534a */
if(!s->budget--) { s->failed_pc=0x0c0b534au; return 0; }
r[5]+=r[13];
goto P_0c0b534c;
P_0c0b534c: /* original 2f52, guest PC 0x0c0b534c */
if(!s->budget--) { s->failed_pc=0x0c0b534cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b534e;
P_0c0b534e: /* original 9472, guest PC 0x0c0b534e */
if(!s->budget--) { s->failed_pc=0x0c0b534eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5436u,2);
goto P_0c0b5350;
P_0c0b5350: /* original 4e0b, guest PC 0x0c0b5350 */
if(!s->budget--) { s->failed_pc=0x0c0b5350u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5354u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5354u) { target=s->pc; goto dispatch; }
goto P_0c0b5354;
P_0c0b5352: /* original 6552, guest PC 0x0c0b5352 */
if(!s->budget--) { s->failed_pc=0x0c0b5352u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5354;
P_0c0b5354: /* original 9470, guest PC 0x0c0b5354 */
if(!s->budget--) { s->failed_pc=0x0c0b5354u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5438u,2);
goto P_0c0b5356;
P_0c0b5356: /* original 65f2, guest PC 0x0c0b5356 */
if(!s->budget--) { s->failed_pc=0x0c0b5356u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5358;
P_0c0b5358: /* original 4e0b, guest PC 0x0c0b5358 */
if(!s->budget--) { s->failed_pc=0x0c0b5358u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b535cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b535cu) { target=s->pc; goto dispatch; }
goto P_0c0b535c;
P_0c0b535a: /* original 6552, guest PC 0x0c0b535a */
if(!s->budget--) { s->failed_pc=0x0c0b535au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b535c;
P_0c0b535c: /* original 956d, guest PC 0x0c0b535c */
if(!s->budget--) { s->failed_pc=0x0c0b535cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b543au,2);
goto P_0c0b535e;
P_0c0b535e: /* original 35dc, guest PC 0x0c0b535e */
if(!s->budget--) { s->failed_pc=0x0c0b535eu; return 0; }
r[5]+=r[13];
goto P_0c0b5360;
P_0c0b5360: /* original 2f52, guest PC 0x0c0b5360 */
if(!s->budget--) { s->failed_pc=0x0c0b5360u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5362;
P_0c0b5362: /* original 946b, guest PC 0x0c0b5362 */
if(!s->budget--) { s->failed_pc=0x0c0b5362u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b543cu,2);
goto P_0c0b5364;
P_0c0b5364: /* original 4e0b, guest PC 0x0c0b5364 */
if(!s->budget--) { s->failed_pc=0x0c0b5364u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5368u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5368u) { target=s->pc; goto dispatch; }
goto P_0c0b5368;
P_0c0b5366: /* original 6552, guest PC 0x0c0b5366 */
if(!s->budget--) { s->failed_pc=0x0c0b5366u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5368;
P_0c0b5368: /* original 9469, guest PC 0x0c0b5368 */
if(!s->budget--) { s->failed_pc=0x0c0b5368u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b543eu,2);
goto P_0c0b536a;
P_0c0b536a: /* original 65f2, guest PC 0x0c0b536a */
if(!s->budget--) { s->failed_pc=0x0c0b536au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b536c;
P_0c0b536c: /* original 4e0b, guest PC 0x0c0b536c */
if(!s->budget--) { s->failed_pc=0x0c0b536cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5370u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5370u) { target=s->pc; goto dispatch; }
goto P_0c0b5370;
P_0c0b536e: /* original 6552, guest PC 0x0c0b536e */
if(!s->budget--) { s->failed_pc=0x0c0b536eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5370;
P_0c0b5370: /* original 9467, guest PC 0x0c0b5370 */
if(!s->budget--) { s->failed_pc=0x0c0b5370u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5442u,2);
goto P_0c0b5372;
P_0c0b5372: /* original 9065, guest PC 0x0c0b5372 */
if(!s->budget--) { s->failed_pc=0x0c0b5372u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5440u,2);
goto P_0c0b5374;
P_0c0b5374: /* original 4e0b, guest PC 0x0c0b5374 */
if(!s->budget--) { s->failed_pc=0x0c0b5374u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5378u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5378u) { target=s->pc; goto dispatch; }
goto P_0c0b5378;
P_0c0b5376: /* original 05de, guest PC 0x0c0b5376 */
if(!s->budget--) { s->failed_pc=0x0c0b5376u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5378;
P_0c0b5378: /* original 9564, guest PC 0x0c0b5378 */
if(!s->budget--) { s->failed_pc=0x0c0b5378u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5444u,2);
goto P_0c0b537a;
P_0c0b537a: /* original 35dc, guest PC 0x0c0b537a */
if(!s->budget--) { s->failed_pc=0x0c0b537au; return 0; }
r[5]+=r[13];
goto P_0c0b537c;
P_0c0b537c: /* original 2f52, guest PC 0x0c0b537c */
if(!s->budget--) { s->failed_pc=0x0c0b537cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b537e;
P_0c0b537e: /* original 9462, guest PC 0x0c0b537e */
if(!s->budget--) { s->failed_pc=0x0c0b537eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5446u,2);
goto P_0c0b5380;
P_0c0b5380: /* original 4e0b, guest PC 0x0c0b5380 */
if(!s->budget--) { s->failed_pc=0x0c0b5380u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5384u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5384u) { target=s->pc; goto dispatch; }
goto P_0c0b5384;
P_0c0b5382: /* original 6552, guest PC 0x0c0b5382 */
if(!s->budget--) { s->failed_pc=0x0c0b5382u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5384;
P_0c0b5384: /* original 9460, guest PC 0x0c0b5384 */
if(!s->budget--) { s->failed_pc=0x0c0b5384u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5448u,2);
goto P_0c0b5386;
P_0c0b5386: /* original 65f2, guest PC 0x0c0b5386 */
if(!s->budget--) { s->failed_pc=0x0c0b5386u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5388;
P_0c0b5388: /* original 4e0b, guest PC 0x0c0b5388 */
if(!s->budget--) { s->failed_pc=0x0c0b5388u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b538cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b538cu) { target=s->pc; goto dispatch; }
goto P_0c0b538c;
P_0c0b538a: /* original 6552, guest PC 0x0c0b538a */
if(!s->budget--) { s->failed_pc=0x0c0b538au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b538c;
P_0c0b538c: /* original 945e, guest PC 0x0c0b538c */
if(!s->budget--) { s->failed_pc=0x0c0b538cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b544cu,2);
goto P_0c0b538e;
P_0c0b538e: /* original 905c, guest PC 0x0c0b538e */
if(!s->budget--) { s->failed_pc=0x0c0b538eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b544au,2);
goto P_0c0b5390;
P_0c0b5390: /* original 4e0b, guest PC 0x0c0b5390 */
if(!s->budget--) { s->failed_pc=0x0c0b5390u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5394u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5394u) { target=s->pc; goto dispatch; }
goto P_0c0b5394;
P_0c0b5392: /* original 05de, guest PC 0x0c0b5392 */
if(!s->budget--) { s->failed_pc=0x0c0b5392u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5394;
P_0c0b5394: /* original 955b, guest PC 0x0c0b5394 */
if(!s->budget--) { s->failed_pc=0x0c0b5394u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b544eu,2);
goto P_0c0b5396;
P_0c0b5396: /* original 35dc, guest PC 0x0c0b5396 */
if(!s->budget--) { s->failed_pc=0x0c0b5396u; return 0; }
r[5]+=r[13];
goto P_0c0b5398;
P_0c0b5398: /* original 2f52, guest PC 0x0c0b5398 */
if(!s->budget--) { s->failed_pc=0x0c0b5398u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b539a;
P_0c0b539a: /* original 9459, guest PC 0x0c0b539a */
if(!s->budget--) { s->failed_pc=0x0c0b539au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5450u,2);
goto P_0c0b539c;
P_0c0b539c: /* original 4e0b, guest PC 0x0c0b539c */
if(!s->budget--) { s->failed_pc=0x0c0b539cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53a0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53a0u) { target=s->pc; goto dispatch; }
goto P_0c0b53a0;
P_0c0b539e: /* original 6552, guest PC 0x0c0b539e */
if(!s->budget--) { s->failed_pc=0x0c0b539eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b53a0;
P_0c0b53a0: /* original 9457, guest PC 0x0c0b53a0 */
if(!s->budget--) { s->failed_pc=0x0c0b53a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5452u,2);
goto P_0c0b53a2;
P_0c0b53a2: /* original 65f2, guest PC 0x0c0b53a2 */
if(!s->budget--) { s->failed_pc=0x0c0b53a2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b53a4;
P_0c0b53a4: /* original 4e0b, guest PC 0x0c0b53a4 */
if(!s->budget--) { s->failed_pc=0x0c0b53a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53a8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53a8u) { target=s->pc; goto dispatch; }
goto P_0c0b53a8;
P_0c0b53a6: /* original 6552, guest PC 0x0c0b53a6 */
if(!s->budget--) { s->failed_pc=0x0c0b53a6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b53a8;
P_0c0b53a8: /* original 9455, guest PC 0x0c0b53a8 */
if(!s->budget--) { s->failed_pc=0x0c0b53a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5456u,2);
goto P_0c0b53aa;
P_0c0b53aa: /* original 9053, guest PC 0x0c0b53aa */
if(!s->budget--) { s->failed_pc=0x0c0b53aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5454u,2);
goto P_0c0b53ac;
P_0c0b53ac: /* original 4e0b, guest PC 0x0c0b53ac */
if(!s->budget--) { s->failed_pc=0x0c0b53acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53b0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53b0u) { target=s->pc; goto dispatch; }
goto P_0c0b53b0;
P_0c0b53ae: /* original 05de, guest PC 0x0c0b53ae */
if(!s->budget--) { s->failed_pc=0x0c0b53aeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b53b0;
P_0c0b53b0: /* original 9552, guest PC 0x0c0b53b0 */
if(!s->budget--) { s->failed_pc=0x0c0b53b0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5458u,2);
goto P_0c0b53b2;
P_0c0b53b2: /* original 35dc, guest PC 0x0c0b53b2 */
if(!s->budget--) { s->failed_pc=0x0c0b53b2u; return 0; }
r[5]+=r[13];
goto P_0c0b53b4;
P_0c0b53b4: /* original 2f52, guest PC 0x0c0b53b4 */
if(!s->budget--) { s->failed_pc=0x0c0b53b4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b53b6;
P_0c0b53b6: /* original 9450, guest PC 0x0c0b53b6 */
if(!s->budget--) { s->failed_pc=0x0c0b53b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b545au,2);
goto P_0c0b53b8;
P_0c0b53b8: /* original 4e0b, guest PC 0x0c0b53b8 */
if(!s->budget--) { s->failed_pc=0x0c0b53b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53bcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53bcu) { target=s->pc; goto dispatch; }
goto P_0c0b53bc;
P_0c0b53ba: /* original 6552, guest PC 0x0c0b53ba */
if(!s->budget--) { s->failed_pc=0x0c0b53bau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b53bc;
P_0c0b53bc: /* original 944e, guest PC 0x0c0b53bc */
if(!s->budget--) { s->failed_pc=0x0c0b53bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b545cu,2);
goto P_0c0b53be;
P_0c0b53be: /* original 65f2, guest PC 0x0c0b53be */
if(!s->budget--) { s->failed_pc=0x0c0b53beu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b53c0;
P_0c0b53c0: /* original 4e0b, guest PC 0x0c0b53c0 */
if(!s->budget--) { s->failed_pc=0x0c0b53c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53c4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53c4u) { target=s->pc; goto dispatch; }
goto P_0c0b53c4;
P_0c0b53c2: /* original 6552, guest PC 0x0c0b53c2 */
if(!s->budget--) { s->failed_pc=0x0c0b53c2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b53c4;
P_0c0b53c4: /* original 954b, guest PC 0x0c0b53c4 */
if(!s->budget--) { s->failed_pc=0x0c0b53c4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b545eu,2);
goto P_0c0b53c6;
P_0c0b53c6: /* original 35dc, guest PC 0x0c0b53c6 */
if(!s->budget--) { s->failed_pc=0x0c0b53c6u; return 0; }
r[5]+=r[13];
goto P_0c0b53c8;
P_0c0b53c8: /* original 2f52, guest PC 0x0c0b53c8 */
if(!s->budget--) { s->failed_pc=0x0c0b53c8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b53ca;
P_0c0b53ca: /* original 9449, guest PC 0x0c0b53ca */
if(!s->budget--) { s->failed_pc=0x0c0b53cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5460u,2);
goto P_0c0b53cc;
P_0c0b53cc: /* original 4e0b, guest PC 0x0c0b53cc */
if(!s->budget--) { s->failed_pc=0x0c0b53ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53d0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53d0u) { target=s->pc; goto dispatch; }
goto P_0c0b53d0;
P_0c0b53ce: /* original 6552, guest PC 0x0c0b53ce */
if(!s->budget--) { s->failed_pc=0x0c0b53ceu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b53d0;
P_0c0b53d0: /* original 9447, guest PC 0x0c0b53d0 */
if(!s->budget--) { s->failed_pc=0x0c0b53d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5462u,2);
goto P_0c0b53d2;
P_0c0b53d2: /* original 65f2, guest PC 0x0c0b53d2 */
if(!s->budget--) { s->failed_pc=0x0c0b53d2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b53d4;
P_0c0b53d4: /* original 4e0b, guest PC 0x0c0b53d4 */
if(!s->budget--) { s->failed_pc=0x0c0b53d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53d8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53d8u) { target=s->pc; goto dispatch; }
goto P_0c0b53d8;
P_0c0b53d6: /* original 6552, guest PC 0x0c0b53d6 */
if(!s->budget--) { s->failed_pc=0x0c0b53d6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b53d8;
P_0c0b53d8: /* original 9445, guest PC 0x0c0b53d8 */
if(!s->budget--) { s->failed_pc=0x0c0b53d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5466u,2);
goto P_0c0b53da;
P_0c0b53da: /* original 9043, guest PC 0x0c0b53da */
if(!s->budget--) { s->failed_pc=0x0c0b53dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5464u,2);
goto P_0c0b53dc;
P_0c0b53dc: /* original 4e0b, guest PC 0x0c0b53dc */
if(!s->budget--) { s->failed_pc=0x0c0b53dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53e0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53e0u) { target=s->pc; goto dispatch; }
goto P_0c0b53e0;
P_0c0b53de: /* original 05de, guest PC 0x0c0b53de */
if(!s->budget--) { s->failed_pc=0x0c0b53deu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b53e0;
P_0c0b53e0: /* original 9443, guest PC 0x0c0b53e0 */
if(!s->budget--) { s->failed_pc=0x0c0b53e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b546au,2);
goto P_0c0b53e2;
P_0c0b53e2: /* original 9041, guest PC 0x0c0b53e2 */
if(!s->budget--) { s->failed_pc=0x0c0b53e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5468u,2);
goto P_0c0b53e4;
P_0c0b53e4: /* original 4e0b, guest PC 0x0c0b53e4 */
if(!s->budget--) { s->failed_pc=0x0c0b53e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53e8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53e8u) { target=s->pc; goto dispatch; }
goto P_0c0b53e8;
P_0c0b53e6: /* original 05de, guest PC 0x0c0b53e6 */
if(!s->budget--) { s->failed_pc=0x0c0b53e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b53e8;
P_0c0b53e8: /* original 9441, guest PC 0x0c0b53e8 */
if(!s->budget--) { s->failed_pc=0x0c0b53e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b546eu,2);
goto P_0c0b53ea;
P_0c0b53ea: /* original 903f, guest PC 0x0c0b53ea */
if(!s->budget--) { s->failed_pc=0x0c0b53eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b546cu,2);
goto P_0c0b53ec;
P_0c0b53ec: /* original 4e0b, guest PC 0x0c0b53ec */
if(!s->budget--) { s->failed_pc=0x0c0b53ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53f0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53f0u) { target=s->pc; goto dispatch; }
goto P_0c0b53f0;
P_0c0b53ee: /* original 05de, guest PC 0x0c0b53ee */
if(!s->budget--) { s->failed_pc=0x0c0b53eeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b53f0;
P_0c0b53f0: /* original 943f, guest PC 0x0c0b53f0 */
if(!s->budget--) { s->failed_pc=0x0c0b53f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5472u,2);
goto P_0c0b53f2;
P_0c0b53f2: /* original 903d, guest PC 0x0c0b53f2 */
if(!s->budget--) { s->failed_pc=0x0c0b53f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5470u,2);
goto P_0c0b53f4;
P_0c0b53f4: /* original 4e0b, guest PC 0x0c0b53f4 */
if(!s->budget--) { s->failed_pc=0x0c0b53f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b53f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b53f8u) { target=s->pc; goto dispatch; }
goto P_0c0b53f8;
P_0c0b53f6: /* original 05de, guest PC 0x0c0b53f6 */
if(!s->budget--) { s->failed_pc=0x0c0b53f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b53f8;
P_0c0b53f8: /* original 903c, guest PC 0x0c0b53f8 */
if(!s->budget--) { s->failed_pc=0x0c0b53f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5474u,2);
goto P_0c0b53fa;
P_0c0b53fa: /* original a03c, guest PC 0x0c0b53fa */
if(!s->budget--) { s->failed_pc=0x0c0b53fau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5476;
P_0c0b53fc: /* original 05de, guest PC 0x0c0b53fc */
if(!s->budget--) { s->failed_pc=0x0c0b53fcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b53feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b53feu; return 0; } return 1;
P_0c0b5476: /* original 943e, guest PC 0x0c0b5476 */
if(!s->budget--) { s->failed_pc=0x0c0b5476u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b54f6u,2);
goto P_0c0b5478;
P_0c0b5478: /* original 4e0b, guest PC 0x0c0b5478 */
if(!s->budget--) { s->failed_pc=0x0c0b5478u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b547cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b547cu) { target=s->pc; goto dispatch; }
goto P_0c0b547c;
P_0c0b547a: /* original 0009, guest PC 0x0c0b547a */
if(!s->budget--) { s->failed_pc=0x0c0b547au; return 0; }
goto P_0c0b547c;
P_0c0b547c: /* original 943d, guest PC 0x0c0b547c */
if(!s->budget--) { s->failed_pc=0x0c0b547cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b54fau,2);
goto P_0c0b547e;
P_0c0b547e: /* original 903b, guest PC 0x0c0b547e */
if(!s->budget--) { s->failed_pc=0x0c0b547eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b54f8u,2);
goto P_0c0b5480;
P_0c0b5480: /* original 4e0b, guest PC 0x0c0b5480 */
if(!s->budget--) { s->failed_pc=0x0c0b5480u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5484u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5484u) { target=s->pc; goto dispatch; }
goto P_0c0b5484;
P_0c0b5482: /* original 05de, guest PC 0x0c0b5482 */
if(!s->budget--) { s->failed_pc=0x0c0b5482u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5484;
P_0c0b5484: /* original 943b, guest PC 0x0c0b5484 */
if(!s->budget--) { s->failed_pc=0x0c0b5484u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b54feu,2);
goto P_0c0b5486;
P_0c0b5486: /* original 9039, guest PC 0x0c0b5486 */
if(!s->budget--) { s->failed_pc=0x0c0b5486u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b54fcu,2);
goto P_0c0b5488;
P_0c0b5488: /* original 4e0b, guest PC 0x0c0b5488 */
if(!s->budget--) { s->failed_pc=0x0c0b5488u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b548cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b548cu) { target=s->pc; goto dispatch; }
goto P_0c0b548c;
P_0c0b548a: /* original 05de, guest PC 0x0c0b548a */
if(!s->budget--) { s->failed_pc=0x0c0b548au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b548c;
P_0c0b548c: /* original 9439, guest PC 0x0c0b548c */
if(!s->budget--) { s->failed_pc=0x0c0b548cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5502u,2);
goto P_0c0b548e;
P_0c0b548e: /* original 9037, guest PC 0x0c0b548e */
if(!s->budget--) { s->failed_pc=0x0c0b548eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5500u,2);
goto P_0c0b5490;
P_0c0b5490: /* original 4e0b, guest PC 0x0c0b5490 */
if(!s->budget--) { s->failed_pc=0x0c0b5490u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b5494u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b5494u) { target=s->pc; goto dispatch; }
goto P_0c0b5494;
P_0c0b5492: /* original 05de, guest PC 0x0c0b5492 */
if(!s->budget--) { s->failed_pc=0x0c0b5492u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5494;
P_0c0b5494: /* original 9437, guest PC 0x0c0b5494 */
if(!s->budget--) { s->failed_pc=0x0c0b5494u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5506u,2);
goto P_0c0b5496;
P_0c0b5496: /* original 9035, guest PC 0x0c0b5496 */
if(!s->budget--) { s->failed_pc=0x0c0b5496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5504u,2);
goto P_0c0b5498;
P_0c0b5498: /* original 4e0b, guest PC 0x0c0b5498 */
if(!s->budget--) { s->failed_pc=0x0c0b5498u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b549cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b549cu) { target=s->pc; goto dispatch; }
goto P_0c0b549c;
P_0c0b549a: /* original 05de, guest PC 0x0c0b549a */
if(!s->budget--) { s->failed_pc=0x0c0b549au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b549c;
P_0c0b549c: /* original 9435, guest PC 0x0c0b549c */
if(!s->budget--) { s->failed_pc=0x0c0b549cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b550au,2);
goto P_0c0b549e;
P_0c0b549e: /* original 9033, guest PC 0x0c0b549e */
if(!s->budget--) { s->failed_pc=0x0c0b549eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5508u,2);
goto P_0c0b54a0;
P_0c0b54a0: /* original 4e0b, guest PC 0x0c0b54a0 */
if(!s->budget--) { s->failed_pc=0x0c0b54a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b54a4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b54a4u) { target=s->pc; goto dispatch; }
goto P_0c0b54a4;
P_0c0b54a2: /* original 05de, guest PC 0x0c0b54a2 */
if(!s->budget--) { s->failed_pc=0x0c0b54a2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b54a4;
P_0c0b54a4: /* original 9433, guest PC 0x0c0b54a4 */
if(!s->budget--) { s->failed_pc=0x0c0b54a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b550eu,2);
goto P_0c0b54a6;
P_0c0b54a6: /* original 9031, guest PC 0x0c0b54a6 */
if(!s->budget--) { s->failed_pc=0x0c0b54a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b550cu,2);
goto P_0c0b54a8;
P_0c0b54a8: /* original 4e0b, guest PC 0x0c0b54a8 */
if(!s->budget--) { s->failed_pc=0x0c0b54a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b54acu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b54acu) { target=s->pc; goto dispatch; }
goto P_0c0b54ac;
P_0c0b54aa: /* original 05de, guest PC 0x0c0b54aa */
if(!s->budget--) { s->failed_pc=0x0c0b54aau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b54ac;
P_0c0b54ac: /* original 9431, guest PC 0x0c0b54ac */
if(!s->budget--) { s->failed_pc=0x0c0b54acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5512u,2);
goto P_0c0b54ae;
P_0c0b54ae: /* original 902f, guest PC 0x0c0b54ae */
if(!s->budget--) { s->failed_pc=0x0c0b54aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5510u,2);
goto P_0c0b54b0;
P_0c0b54b0: /* original 4e0b, guest PC 0x0c0b54b0 */
if(!s->budget--) { s->failed_pc=0x0c0b54b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b54b4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b54b4u) { target=s->pc; goto dispatch; }
goto P_0c0b54b4;
P_0c0b54b2: /* original 05de, guest PC 0x0c0b54b2 */
if(!s->budget--) { s->failed_pc=0x0c0b54b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b54b4;
P_0c0b54b4: /* original 942f, guest PC 0x0c0b54b4 */
if(!s->budget--) { s->failed_pc=0x0c0b54b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5516u,2);
goto P_0c0b54b6;
P_0c0b54b6: /* original 902d, guest PC 0x0c0b54b6 */
if(!s->budget--) { s->failed_pc=0x0c0b54b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5514u,2);
goto P_0c0b54b8;
P_0c0b54b8: /* original 4e0b, guest PC 0x0c0b54b8 */
if(!s->budget--) { s->failed_pc=0x0c0b54b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b54bcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b54bcu) { target=s->pc; goto dispatch; }
goto P_0c0b54bc;
P_0c0b54ba: /* original 05de, guest PC 0x0c0b54ba */
if(!s->budget--) { s->failed_pc=0x0c0b54bau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b54bc;
P_0c0b54bc: /* original 942d, guest PC 0x0c0b54bc */
if(!s->budget--) { s->failed_pc=0x0c0b54bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b551au,2);
goto P_0c0b54be;
P_0c0b54be: /* original 902b, guest PC 0x0c0b54be */
if(!s->budget--) { s->failed_pc=0x0c0b54beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5518u,2);
goto P_0c0b54c0;
P_0c0b54c0: /* original 4e0b, guest PC 0x0c0b54c0 */
if(!s->budget--) { s->failed_pc=0x0c0b54c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b54c4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b54c4u) { target=s->pc; goto dispatch; }
goto P_0c0b54c4;
P_0c0b54c2: /* original 05de, guest PC 0x0c0b54c2 */
if(!s->budget--) { s->failed_pc=0x0c0b54c2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b54c4;
P_0c0b54c4: /* original 942b, guest PC 0x0c0b54c4 */
if(!s->budget--) { s->failed_pc=0x0c0b54c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b551eu,2);
goto P_0c0b54c6;
P_0c0b54c6: /* original 9029, guest PC 0x0c0b54c6 */
if(!s->budget--) { s->failed_pc=0x0c0b54c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b551cu,2);
goto P_0c0b54c8;
P_0c0b54c8: /* original 4e0b, guest PC 0x0c0b54c8 */
if(!s->budget--) { s->failed_pc=0x0c0b54c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b54ccu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b54ccu) { target=s->pc; goto dispatch; }
goto P_0c0b54cc;
P_0c0b54ca: /* original 05de, guest PC 0x0c0b54ca */
if(!s->budget--) { s->failed_pc=0x0c0b54cau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b54cc;
P_0c0b54cc: /* original 9429, guest PC 0x0c0b54cc */
if(!s->budget--) { s->failed_pc=0x0c0b54ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5522u,2);
goto P_0c0b54ce;
P_0c0b54ce: /* original 9027, guest PC 0x0c0b54ce */
if(!s->budget--) { s->failed_pc=0x0c0b54ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5520u,2);
goto P_0c0b54d0;
P_0c0b54d0: /* original 4e0b, guest PC 0x0c0b54d0 */
if(!s->budget--) { s->failed_pc=0x0c0b54d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b54d4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b54d4u) { target=s->pc; goto dispatch; }
goto P_0c0b54d4;
P_0c0b54d2: /* original 05de, guest PC 0x0c0b54d2 */
if(!s->budget--) { s->failed_pc=0x0c0b54d2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b54d4;
P_0c0b54d4: /* original 9427, guest PC 0x0c0b54d4 */
if(!s->budget--) { s->failed_pc=0x0c0b54d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5526u,2);
goto P_0c0b54d6;
P_0c0b54d6: /* original 9025, guest PC 0x0c0b54d6 */
if(!s->budget--) { s->failed_pc=0x0c0b54d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5524u,2);
goto P_0c0b54d8;
P_0c0b54d8: /* original 4e0b, guest PC 0x0c0b54d8 */
if(!s->budget--) { s->failed_pc=0x0c0b54d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b54dcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b54dcu) { target=s->pc; goto dispatch; }
goto P_0c0b54dc;
P_0c0b54da: /* original 05de, guest PC 0x0c0b54da */
if(!s->budget--) { s->failed_pc=0x0c0b54dau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b54dc;
P_0c0b54dc: /* original 9425, guest PC 0x0c0b54dc */
if(!s->budget--) { s->failed_pc=0x0c0b54dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b552au,2);
goto P_0c0b54de;
P_0c0b54de: /* original 9023, guest PC 0x0c0b54de */
if(!s->budget--) { s->failed_pc=0x0c0b54deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5528u,2);
goto P_0c0b54e0;
P_0c0b54e0: /* original 4e0b, guest PC 0x0c0b54e0 */
if(!s->budget--) { s->failed_pc=0x0c0b54e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b54e4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b54e4u) { target=s->pc; goto dispatch; }
goto P_0c0b54e4;
P_0c0b54e2: /* original 05de, guest PC 0x0c0b54e2 */
if(!s->budget--) { s->failed_pc=0x0c0b54e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b54e4;
P_0c0b54e4: /* original 7f08, guest PC 0x0c0b54e4 */
if(!s->budget--) { s->failed_pc=0x0c0b54e4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b54e6;
P_0c0b54e6: /* original 4f26, guest PC 0x0c0b54e6 */
if(!s->budget--) { s->failed_pc=0x0c0b54e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b54e8;
P_0c0b54e8: /* original 69f6, guest PC 0x0c0b54e8 */
if(!s->budget--) { s->failed_pc=0x0c0b54e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b54ea;
P_0c0b54ea: /* original 6af6, guest PC 0x0c0b54ea */
if(!s->budget--) { s->failed_pc=0x0c0b54eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b54ec;
P_0c0b54ec: /* original 6bf6, guest PC 0x0c0b54ec */
if(!s->budget--) { s->failed_pc=0x0c0b54ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b54ee;
P_0c0b54ee: /* original 6cf6, guest PC 0x0c0b54ee */
if(!s->budget--) { s->failed_pc=0x0c0b54eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b54f0;
P_0c0b54f0: /* original 6df6, guest PC 0x0c0b54f0 */
if(!s->budget--) { s->failed_pc=0x0c0b54f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b54f2;
P_0c0b54f2: /* original 000b, guest PC 0x0c0b54f2 */
if(!s->budget--) { s->failed_pc=0x0c0b54f2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b54f4: /* original 6ef6, guest PC 0x0c0b54f4 */
if(!s->budget--) { s->failed_pc=0x0c0b54f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b54f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b54f6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
