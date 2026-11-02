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
int vf3_away_batch25_adapter_37(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c5048u: goto P_0c0c5048;
case 0x0c0c504au: goto P_0c0c504a;
case 0x0c0c504cu: goto P_0c0c504c;
case 0x0c0c504eu: goto P_0c0c504e;
case 0x0c0c5050u: goto P_0c0c5050;
case 0x0c0c5052u: goto P_0c0c5052;
case 0x0c0c5054u: goto P_0c0c5054;
case 0x0c0c5056u: goto P_0c0c5056;
case 0x0c0c5058u: goto P_0c0c5058;
case 0x0c0c505au: goto P_0c0c505a;
case 0x0c0c505cu: goto P_0c0c505c;
case 0x0c0c505eu: goto P_0c0c505e;
case 0x0c0c5060u: goto P_0c0c5060;
case 0x0c0c5062u: goto P_0c0c5062;
case 0x0c0c5064u: goto P_0c0c5064;
case 0x0c0c5066u: goto P_0c0c5066;
case 0x0c0c5068u: goto P_0c0c5068;
case 0x0c0c506au: goto P_0c0c506a;
case 0x0c0c506cu: goto P_0c0c506c;
case 0x0c0c506eu: goto P_0c0c506e;
case 0x0c0c5070u: goto P_0c0c5070;
case 0x0c0c5072u: goto P_0c0c5072;
case 0x0c0c5074u: goto P_0c0c5074;
case 0x0c0c5076u: goto P_0c0c5076;
case 0x0c0c5078u: goto P_0c0c5078;
case 0x0c0c507au: goto P_0c0c507a;
case 0x0c0c507cu: goto P_0c0c507c;
case 0x0c0c507eu: goto P_0c0c507e;
case 0x0c0c5080u: goto P_0c0c5080;
case 0x0c0c5082u: goto P_0c0c5082;
case 0x0c0c5084u: goto P_0c0c5084;
case 0x0c0c5086u: goto P_0c0c5086;
case 0x0c0c5088u: goto P_0c0c5088;
case 0x0c0c508au: goto P_0c0c508a;
case 0x0c0c508cu: goto P_0c0c508c;
case 0x0c0c508eu: goto P_0c0c508e;
case 0x0c0c5090u: goto P_0c0c5090;
case 0x0c0c5092u: goto P_0c0c5092;
case 0x0c0c5094u: goto P_0c0c5094;
case 0x0c0c5096u: goto P_0c0c5096;
case 0x0c0c5098u: goto P_0c0c5098;
case 0x0c0c509au: goto P_0c0c509a;
case 0x0c0c509cu: goto P_0c0c509c;
case 0x0c0c509eu: goto P_0c0c509e;
case 0x0c0c50a0u: goto P_0c0c50a0;
case 0x0c0c50a2u: goto P_0c0c50a2;
case 0x0c0c50a4u: goto P_0c0c50a4;
case 0x0c0c50a6u: goto P_0c0c50a6;
case 0x0c0c50a8u: goto P_0c0c50a8;
case 0x0c0c50aau: goto P_0c0c50aa;
case 0x0c0c50acu: goto P_0c0c50ac;
case 0x0c0c50aeu: goto P_0c0c50ae;
case 0x0c0c50b0u: goto P_0c0c50b0;
case 0x0c0c50b2u: goto P_0c0c50b2;
case 0x0c0c50b4u: goto P_0c0c50b4;
case 0x0c0c50b6u: goto P_0c0c50b6;
case 0x0c0c50b8u: goto P_0c0c50b8;
case 0x0c0c50bau: goto P_0c0c50ba;
case 0x0c0c50bcu: goto P_0c0c50bc;
case 0x0c0c50beu: goto P_0c0c50be;
case 0x0c0c50c0u: goto P_0c0c50c0;
case 0x0c0c50c2u: goto P_0c0c50c2;
case 0x0c0c50c4u: goto P_0c0c50c4;
case 0x0c0c50c6u: goto P_0c0c50c6;
case 0x0c0c50c8u: goto P_0c0c50c8;
case 0x0c0c50cau: goto P_0c0c50ca;
case 0x0c0c50ccu: goto P_0c0c50cc;
case 0x0c0c50ceu: goto P_0c0c50ce;
case 0x0c0c50d0u: goto P_0c0c50d0;
case 0x0c0c50d2u: goto P_0c0c50d2;
case 0x0c0c50d4u: goto P_0c0c50d4;
case 0x0c0c50d6u: goto P_0c0c50d6;
case 0x0c0c50d8u: goto P_0c0c50d8;
case 0x0c0c50dau: goto P_0c0c50da;
case 0x0c0c50dcu: goto P_0c0c50dc;
case 0x0c0c50deu: goto P_0c0c50de;
case 0x0c0c50e0u: goto P_0c0c50e0;
case 0x0c0c50e2u: goto P_0c0c50e2;
case 0x0c0c50e4u: goto P_0c0c50e4;
case 0x0c0c50e6u: goto P_0c0c50e6;
case 0x0c0c50e8u: goto P_0c0c50e8;
case 0x0c0c50eau: goto P_0c0c50ea;
case 0x0c0c50ecu: goto P_0c0c50ec;
case 0x0c0c50eeu: goto P_0c0c50ee;
case 0x0c0c50f0u: goto P_0c0c50f0;
case 0x0c0c50f2u: goto P_0c0c50f2;
case 0x0c0c50f4u: goto P_0c0c50f4;
case 0x0c0c50f6u: goto P_0c0c50f6;
case 0x0c0c50f8u: goto P_0c0c50f8;
case 0x0c0c50fau: goto P_0c0c50fa;
case 0x0c0c50fcu: goto P_0c0c50fc;
case 0x0c0c50feu: goto P_0c0c50fe;
case 0x0c0c5100u: goto P_0c0c5100;
case 0x0c0c5102u: goto P_0c0c5102;
case 0x0c0c5104u: goto P_0c0c5104;
case 0x0c0c5106u: goto P_0c0c5106;
case 0x0c0c5108u: goto P_0c0c5108;
case 0x0c0c510au: goto P_0c0c510a;
case 0x0c0c510cu: goto P_0c0c510c;
case 0x0c0c510eu: goto P_0c0c510e;
case 0x0c0c5110u: goto P_0c0c5110;
case 0x0c0c5112u: goto P_0c0c5112;
case 0x0c0c5114u: goto P_0c0c5114;
case 0x0c0c5116u: goto P_0c0c5116;
case 0x0c0c5118u: goto P_0c0c5118;
case 0x0c0c511au: goto P_0c0c511a;
case 0x0c0c511cu: goto P_0c0c511c;
case 0x0c0c511eu: goto P_0c0c511e;
case 0x0c0c5120u: goto P_0c0c5120;
case 0x0c0c5122u: goto P_0c0c5122;
case 0x0c0c5124u: goto P_0c0c5124;
case 0x0c0c5126u: goto P_0c0c5126;
case 0x0c0c5128u: goto P_0c0c5128;
case 0x0c0c512au: goto P_0c0c512a;
case 0x0c0c512cu: goto P_0c0c512c;
case 0x0c0c512eu: goto P_0c0c512e;
case 0x0c0c5130u: goto P_0c0c5130;
case 0x0c0c5132u: goto P_0c0c5132;
case 0x0c0c5134u: goto P_0c0c5134;
case 0x0c0c5136u: goto P_0c0c5136;
case 0x0c0c5138u: goto P_0c0c5138;
case 0x0c0c513au: goto P_0c0c513a;
case 0x0c0c513cu: goto P_0c0c513c;
case 0x0c0c513eu: goto P_0c0c513e;
case 0x0c0c5140u: goto P_0c0c5140;
case 0x0c0c5142u: goto P_0c0c5142;
case 0x0c0c5144u: goto P_0c0c5144;
case 0x0c0c5146u: goto P_0c0c5146;
case 0x0c0c5148u: goto P_0c0c5148;
case 0x0c0c514au: goto P_0c0c514a;
case 0x0c0c514cu: goto P_0c0c514c;
case 0x0c0c514eu: goto P_0c0c514e;
case 0x0c0c5150u: goto P_0c0c5150;
case 0x0c0c5152u: goto P_0c0c5152;
case 0x0c0c5154u: goto P_0c0c5154;
case 0x0c0c5156u: goto P_0c0c5156;
case 0x0c0c5158u: goto P_0c0c5158;
case 0x0c0c515au: goto P_0c0c515a;
case 0x0c0c515cu: goto P_0c0c515c;
case 0x0c0c515eu: goto P_0c0c515e;
case 0x0c0c5160u: goto P_0c0c5160;
case 0x0c0c5162u: goto P_0c0c5162;
case 0x0c0c5164u: goto P_0c0c5164;
case 0x0c0c5166u: goto P_0c0c5166;
case 0x0c0c5168u: goto P_0c0c5168;
case 0x0c0c516au: goto P_0c0c516a;
case 0x0c0c516cu: goto P_0c0c516c;
case 0x0c0c516eu: goto P_0c0c516e;
case 0x0c0c5170u: goto P_0c0c5170;
case 0x0c0c5172u: goto P_0c0c5172;
case 0x0c0c5174u: goto P_0c0c5174;
case 0x0c0c5176u: goto P_0c0c5176;
case 0x0c0c5178u: goto P_0c0c5178;
case 0x0c0c517au: goto P_0c0c517a;
case 0x0c0c517cu: goto P_0c0c517c;
case 0x0c0c517eu: goto P_0c0c517e;
case 0x0c0c5180u: goto P_0c0c5180;
case 0x0c0c5182u: goto P_0c0c5182;
case 0x0c0c5184u: goto P_0c0c5184;
case 0x0c0c5186u: goto P_0c0c5186;
case 0x0c0c5188u: goto P_0c0c5188;
case 0x0c0c518au: goto P_0c0c518a;
case 0x0c0c518cu: goto P_0c0c518c;
case 0x0c0c518eu: goto P_0c0c518e;
case 0x0c0c5190u: goto P_0c0c5190;
case 0x0c0c5192u: goto P_0c0c5192;
case 0x0c0c5194u: goto P_0c0c5194;
case 0x0c0c5196u: goto P_0c0c5196;
case 0x0c0c5198u: goto P_0c0c5198;
case 0x0c0c519au: goto P_0c0c519a;
case 0x0c0c519cu: goto P_0c0c519c;
case 0x0c0c519eu: goto P_0c0c519e;
case 0x0c0c51a0u: goto P_0c0c51a0;
case 0x0c0c51a2u: goto P_0c0c51a2;
case 0x0c0c51a4u: goto P_0c0c51a4;
case 0x0c0c51a6u: goto P_0c0c51a6;
case 0x0c0c51a8u: goto P_0c0c51a8;
case 0x0c0c51aau: goto P_0c0c51aa;
case 0x0c0c51acu: goto P_0c0c51ac;
case 0x0c0c51aeu: goto P_0c0c51ae;
case 0x0c0c51b0u: goto P_0c0c51b0;
case 0x0c0c51b2u: goto P_0c0c51b2;
case 0x0c0c51b4u: goto P_0c0c51b4;
case 0x0c0c51b6u: goto P_0c0c51b6;
case 0x0c0c51b8u: goto P_0c0c51b8;
case 0x0c0c51bau: goto P_0c0c51ba;
case 0x0c0c51bcu: goto P_0c0c51bc;
case 0x0c0c51beu: goto P_0c0c51be;
case 0x0c0c51c0u: goto P_0c0c51c0;
case 0x0c0c51c2u: goto P_0c0c51c2;
case 0x0c0c51c4u: goto P_0c0c51c4;
case 0x0c0c51c6u: goto P_0c0c51c6;
case 0x0c0c51c8u: goto P_0c0c51c8;
case 0x0c0c51cau: goto P_0c0c51ca;
case 0x0c0c51ccu: goto P_0c0c51cc;
case 0x0c0c51ceu: goto P_0c0c51ce;
case 0x0c0c51d0u: goto P_0c0c51d0;
case 0x0c0c5204u: goto P_0c0c5204;
case 0x0c0c5206u: goto P_0c0c5206;
case 0x0c0c5208u: goto P_0c0c5208;
case 0x0c0c520au: goto P_0c0c520a;
case 0x0c0c520cu: goto P_0c0c520c;
case 0x0c0c520eu: goto P_0c0c520e;
case 0x0c0c5210u: goto P_0c0c5210;
case 0x0c0c5212u: goto P_0c0c5212;
case 0x0c0c5214u: goto P_0c0c5214;
case 0x0c0c5216u: goto P_0c0c5216;
case 0x0c0c5218u: goto P_0c0c5218;
case 0x0c0c521au: goto P_0c0c521a;
case 0x0c0c521cu: goto P_0c0c521c;
case 0x0c0c521eu: goto P_0c0c521e;
case 0x0c0c5220u: goto P_0c0c5220;
case 0x0c0c5222u: goto P_0c0c5222;
case 0x0c0c5224u: goto P_0c0c5224;
case 0x0c0c5226u: goto P_0c0c5226;
case 0x0c0c5228u: goto P_0c0c5228;
case 0x0c0c522au: goto P_0c0c522a;
case 0x0c0c522cu: goto P_0c0c522c;
case 0x0c0c522eu: goto P_0c0c522e;
case 0x0c0c5230u: goto P_0c0c5230;
case 0x0c0c5232u: goto P_0c0c5232;
case 0x0c0c5234u: goto P_0c0c5234;
case 0x0c0c5236u: goto P_0c0c5236;
case 0x0c0c5238u: goto P_0c0c5238;
case 0x0c0c523au: goto P_0c0c523a;
case 0x0c0c523cu: goto P_0c0c523c;
case 0x0c0c523eu: goto P_0c0c523e;
case 0x0c0c5240u: goto P_0c0c5240;
case 0x0c0c5242u: goto P_0c0c5242;
case 0x0c0c5244u: goto P_0c0c5244;
case 0x0c0c5246u: goto P_0c0c5246;
case 0x0c0c5248u: goto P_0c0c5248;
case 0x0c0c524au: goto P_0c0c524a;
case 0x0c0c524cu: goto P_0c0c524c;
case 0x0c0c524eu: goto P_0c0c524e;
case 0x0c0c5250u: goto P_0c0c5250;
case 0x0c0c5252u: goto P_0c0c5252;
case 0x0c0c5254u: goto P_0c0c5254;
case 0x0c0c5256u: goto P_0c0c5256;
case 0x0c0c5258u: goto P_0c0c5258;
case 0x0c0c525au: goto P_0c0c525a;
case 0x0c0c525cu: goto P_0c0c525c;
case 0x0c0c525eu: goto P_0c0c525e;
case 0x0c0c5260u: goto P_0c0c5260;
case 0x0c0c5262u: goto P_0c0c5262;
case 0x0c0c5264u: goto P_0c0c5264;
case 0x0c0c5266u: goto P_0c0c5266;
case 0x0c0c5268u: goto P_0c0c5268;
case 0x0c0c526au: goto P_0c0c526a;
case 0x0c0c526cu: goto P_0c0c526c;
case 0x0c0c526eu: goto P_0c0c526e;
case 0x0c0c5270u: goto P_0c0c5270;
case 0x0c0c5272u: goto P_0c0c5272;
case 0x0c0c5274u: goto P_0c0c5274;
case 0x0c0c5276u: goto P_0c0c5276;
case 0x0c0c5278u: goto P_0c0c5278;
case 0x0c0c527au: goto P_0c0c527a;
case 0x0c0c527cu: goto P_0c0c527c;
case 0x0c0c527eu: goto P_0c0c527e;
case 0x0c0c5280u: goto P_0c0c5280;
case 0x0c0c5282u: goto P_0c0c5282;
case 0x0c0c5284u: goto P_0c0c5284;
case 0x0c0c5286u: goto P_0c0c5286;
case 0x0c0c5288u: goto P_0c0c5288;
case 0x0c0c528au: goto P_0c0c528a;
case 0x0c0c528cu: goto P_0c0c528c;
case 0x0c0c528eu: goto P_0c0c528e;
case 0x0c0c5290u: goto P_0c0c5290;
case 0x0c0c5292u: goto P_0c0c5292;
case 0x0c0c5294u: goto P_0c0c5294;
case 0x0c0c5296u: goto P_0c0c5296;
case 0x0c0c5298u: goto P_0c0c5298;
case 0x0c0c529au: goto P_0c0c529a;
case 0x0c0c529cu: goto P_0c0c529c;
case 0x0c0c529eu: goto P_0c0c529e;
case 0x0c0c52a0u: goto P_0c0c52a0;
case 0x0c0c52a2u: goto P_0c0c52a2;
case 0x0c0c52a4u: goto P_0c0c52a4;
case 0x0c0c52a6u: goto P_0c0c52a6;
case 0x0c0c52a8u: goto P_0c0c52a8;
case 0x0c0c52aau: goto P_0c0c52aa;
case 0x0c0c52acu: goto P_0c0c52ac;
case 0x0c0c52aeu: goto P_0c0c52ae;
case 0x0c0c52b0u: goto P_0c0c52b0;
case 0x0c0c52b2u: goto P_0c0c52b2;
case 0x0c0c52b4u: goto P_0c0c52b4;
case 0x0c0c52b6u: goto P_0c0c52b6;
case 0x0c0c52b8u: goto P_0c0c52b8;
case 0x0c0c52bau: goto P_0c0c52ba;
case 0x0c0c52bcu: goto P_0c0c52bc;
case 0x0c0c52beu: goto P_0c0c52be;
case 0x0c0c52c0u: goto P_0c0c52c0;
case 0x0c0c52c2u: goto P_0c0c52c2;
case 0x0c0c52c4u: goto P_0c0c52c4;
case 0x0c0c52c6u: goto P_0c0c52c6;
case 0x0c0c52c8u: goto P_0c0c52c8;
case 0x0c0c52cau: goto P_0c0c52ca;
case 0x0c0c52ccu: goto P_0c0c52cc;
case 0x0c0c52ceu: goto P_0c0c52ce;
case 0x0c0c52d0u: goto P_0c0c52d0;
case 0x0c0c52d2u: goto P_0c0c52d2;
case 0x0c0c52d4u: goto P_0c0c52d4;
case 0x0c0c52d6u: goto P_0c0c52d6;
case 0x0c0c52d8u: goto P_0c0c52d8;
case 0x0c0c52dau: goto P_0c0c52da;
case 0x0c0c52dcu: goto P_0c0c52dc;
case 0x0c0c52deu: goto P_0c0c52de;
case 0x0c0c52e0u: goto P_0c0c52e0;
case 0x0c0c52e2u: goto P_0c0c52e2;
case 0x0c0c52e4u: goto P_0c0c52e4;
case 0x0c0c52e6u: goto P_0c0c52e6;
case 0x0c0c52e8u: goto P_0c0c52e8;
case 0x0c0c52eau: goto P_0c0c52ea;
case 0x0c0c52ecu: goto P_0c0c52ec;
case 0x0c0c52eeu: goto P_0c0c52ee;
case 0x0c0c52f0u: goto P_0c0c52f0;
case 0x0c0c52f2u: goto P_0c0c52f2;
case 0x0c0c52f4u: goto P_0c0c52f4;
case 0x0c0c52f6u: goto P_0c0c52f6;
case 0x0c0c52f8u: goto P_0c0c52f8;
case 0x0c0c52fau: goto P_0c0c52fa;
case 0x0c0c52fcu: goto P_0c0c52fc;
case 0x0c0c52feu: goto P_0c0c52fe;
case 0x0c0c5300u: goto P_0c0c5300;
case 0x0c0c5302u: goto P_0c0c5302;
case 0x0c0c5304u: goto P_0c0c5304;
case 0x0c0c5306u: goto P_0c0c5306;
case 0x0c0c5308u: goto P_0c0c5308;
case 0x0c0c530au: goto P_0c0c530a;
case 0x0c0c530cu: goto P_0c0c530c;
case 0x0c0c530eu: goto P_0c0c530e;
case 0x0c0c5310u: goto P_0c0c5310;
case 0x0c0c5312u: goto P_0c0c5312;
case 0x0c0c5314u: goto P_0c0c5314;
case 0x0c0c5316u: goto P_0c0c5316;
case 0x0c0c5318u: goto P_0c0c5318;
case 0x0c0c531au: goto P_0c0c531a;
case 0x0c0c531cu: goto P_0c0c531c;
case 0x0c0c531eu: goto P_0c0c531e;
case 0x0c0c5320u: goto P_0c0c5320;
case 0x0c0c5322u: goto P_0c0c5322;
case 0x0c0c5324u: goto P_0c0c5324;
case 0x0c0c5326u: goto P_0c0c5326;
case 0x0c0c5328u: goto P_0c0c5328;
case 0x0c0c532au: goto P_0c0c532a;
case 0x0c0c532cu: goto P_0c0c532c;
case 0x0c0c532eu: goto P_0c0c532e;
case 0x0c0c5330u: goto P_0c0c5330;
case 0x0c0c5332u: goto P_0c0c5332;
case 0x0c0c5334u: goto P_0c0c5334;
case 0x0c0c5336u: goto P_0c0c5336;
case 0x0c0c5338u: goto P_0c0c5338;
case 0x0c0c533au: goto P_0c0c533a;
case 0x0c0c533cu: goto P_0c0c533c;
case 0x0c0c533eu: goto P_0c0c533e;
case 0x0c0c5340u: goto P_0c0c5340;
case 0x0c0c5342u: goto P_0c0c5342;
case 0x0c0c5344u: goto P_0c0c5344;
case 0x0c0c5346u: goto P_0c0c5346;
case 0x0c0c5348u: goto P_0c0c5348;
case 0x0c0c534au: goto P_0c0c534a;
case 0x0c0c534cu: goto P_0c0c534c;
case 0x0c0c534eu: goto P_0c0c534e;
case 0x0c0c5350u: goto P_0c0c5350;
case 0x0c0c5352u: goto P_0c0c5352;
case 0x0c0c5354u: goto P_0c0c5354;
case 0x0c0c5356u: goto P_0c0c5356;
case 0x0c0c5358u: goto P_0c0c5358;
case 0x0c0c535au: goto P_0c0c535a;
case 0x0c0c535cu: goto P_0c0c535c;
case 0x0c0c535eu: goto P_0c0c535e;
case 0x0c0c5360u: goto P_0c0c5360;
case 0x0c0c5362u: goto P_0c0c5362;
case 0x0c0c5364u: goto P_0c0c5364;
case 0x0c0c5366u: goto P_0c0c5366;
case 0x0c0c5368u: goto P_0c0c5368;
case 0x0c0c536au: goto P_0c0c536a;
case 0x0c0c536cu: goto P_0c0c536c;
case 0x0c0c536eu: goto P_0c0c536e;
case 0x0c0c5370u: goto P_0c0c5370;
case 0x0c0c5372u: goto P_0c0c5372;
case 0x0c0c5374u: goto P_0c0c5374;
case 0x0c0c5376u: goto P_0c0c5376;
case 0x0c0c5378u: goto P_0c0c5378;
case 0x0c0c537au: goto P_0c0c537a;
case 0x0c0c537cu: goto P_0c0c537c;
case 0x0c0c53acu: goto P_0c0c53ac;
case 0x0c0c53aeu: goto P_0c0c53ae;
case 0x0c0c53b0u: goto P_0c0c53b0;
case 0x0c0c53b2u: goto P_0c0c53b2;
case 0x0c0c53b4u: goto P_0c0c53b4;
case 0x0c0c53b6u: goto P_0c0c53b6;
case 0x0c0c53b8u: goto P_0c0c53b8;
case 0x0c0c53bau: goto P_0c0c53ba;
case 0x0c0c53bcu: goto P_0c0c53bc;
case 0x0c0c53beu: goto P_0c0c53be;
case 0x0c0c53c0u: goto P_0c0c53c0;
case 0x0c0c53c2u: goto P_0c0c53c2;
case 0x0c0c53c4u: goto P_0c0c53c4;
case 0x0c0c53c6u: goto P_0c0c53c6;
case 0x0c0c53c8u: goto P_0c0c53c8;
case 0x0c0c53cau: goto P_0c0c53ca;
case 0x0c0c53ccu: goto P_0c0c53cc;
case 0x0c0c53ceu: goto P_0c0c53ce;
case 0x0c0c53d0u: goto P_0c0c53d0;
case 0x0c0c53d2u: goto P_0c0c53d2;
case 0x0c0c53d4u: goto P_0c0c53d4;
case 0x0c0c53d6u: goto P_0c0c53d6;
case 0x0c0c53d8u: goto P_0c0c53d8;
case 0x0c0c53dau: goto P_0c0c53da;
case 0x0c0c53dcu: goto P_0c0c53dc;
case 0x0c0c53deu: goto P_0c0c53de;
case 0x0c0c53e0u: goto P_0c0c53e0;
case 0x0c0c53e2u: goto P_0c0c53e2;
case 0x0c0c53e4u: goto P_0c0c53e4;
case 0x0c0c53e6u: goto P_0c0c53e6;
case 0x0c0c53e8u: goto P_0c0c53e8;
case 0x0c0c53eau: goto P_0c0c53ea;
case 0x0c0c53ecu: goto P_0c0c53ec;
case 0x0c0c53eeu: goto P_0c0c53ee;
case 0x0c0c53f0u: goto P_0c0c53f0;
case 0x0c0c53f2u: goto P_0c0c53f2;
case 0x0c0c53f4u: goto P_0c0c53f4;
case 0x0c0c53f6u: goto P_0c0c53f6;
case 0x0c0c53f8u: goto P_0c0c53f8;
case 0x0c0c53fau: goto P_0c0c53fa;
case 0x0c0c53fcu: goto P_0c0c53fc;
case 0x0c0c53feu: goto P_0c0c53fe;
case 0x0c0c5400u: goto P_0c0c5400;
case 0x0c0c5402u: goto P_0c0c5402;
case 0x0c0c5404u: goto P_0c0c5404;
case 0x0c0c5406u: goto P_0c0c5406;
case 0x0c0c5408u: goto P_0c0c5408;
case 0x0c0c540au: goto P_0c0c540a;
case 0x0c0c540cu: goto P_0c0c540c;
case 0x0c0c540eu: goto P_0c0c540e;
case 0x0c0c5410u: goto P_0c0c5410;
case 0x0c0c5412u: goto P_0c0c5412;
case 0x0c0c5414u: goto P_0c0c5414;
case 0x0c0c5416u: goto P_0c0c5416;
case 0x0c0c5418u: goto P_0c0c5418;
case 0x0c0c541au: goto P_0c0c541a;
case 0x0c0c541cu: goto P_0c0c541c;
case 0x0c0c541eu: goto P_0c0c541e;
case 0x0c0c5420u: goto P_0c0c5420;
case 0x0c0c5422u: goto P_0c0c5422;
case 0x0c0c5424u: goto P_0c0c5424;
case 0x0c0c5426u: goto P_0c0c5426;
case 0x0c0c5428u: goto P_0c0c5428;
case 0x0c0c542au: goto P_0c0c542a;
case 0x0c0c542cu: goto P_0c0c542c;
case 0x0c0c542eu: goto P_0c0c542e;
case 0x0c0c5430u: goto P_0c0c5430;
case 0x0c0c5432u: goto P_0c0c5432;
case 0x0c0c5434u: goto P_0c0c5434;
case 0x0c0c5436u: goto P_0c0c5436;
case 0x0c0c5438u: goto P_0c0c5438;
case 0x0c0c543au: goto P_0c0c543a;
case 0x0c0c543cu: goto P_0c0c543c;
case 0x0c0c543eu: goto P_0c0c543e;
case 0x0c0c5440u: goto P_0c0c5440;
case 0x0c0c5442u: goto P_0c0c5442;
case 0x0c0c5444u: goto P_0c0c5444;
case 0x0c0c5446u: goto P_0c0c5446;
case 0x0c0c5448u: goto P_0c0c5448;
case 0x0c0c544au: goto P_0c0c544a;
case 0x0c0c544cu: goto P_0c0c544c;
case 0x0c0c544eu: goto P_0c0c544e;
case 0x0c0c5450u: goto P_0c0c5450;
case 0x0c0c5452u: goto P_0c0c5452;
case 0x0c0c5454u: goto P_0c0c5454;
case 0x0c0c5456u: goto P_0c0c5456;
case 0x0c0c5458u: goto P_0c0c5458;
case 0x0c0c545au: goto P_0c0c545a;
case 0x0c0c545cu: goto P_0c0c545c;
case 0x0c0c545eu: goto P_0c0c545e;
case 0x0c0c5460u: goto P_0c0c5460;
case 0x0c0c5462u: goto P_0c0c5462;
case 0x0c0c5464u: goto P_0c0c5464;
case 0x0c0c5466u: goto P_0c0c5466;
case 0x0c0c5468u: goto P_0c0c5468;
case 0x0c0c546au: goto P_0c0c546a;
case 0x0c0c546cu: goto P_0c0c546c;
case 0x0c0c546eu: goto P_0c0c546e;
case 0x0c0c5470u: goto P_0c0c5470;
case 0x0c0c5472u: goto P_0c0c5472;
case 0x0c0c5474u: goto P_0c0c5474;
case 0x0c0c5476u: goto P_0c0c5476;
case 0x0c0c5478u: goto P_0c0c5478;
case 0x0c0c547au: goto P_0c0c547a;
case 0x0c0c547cu: goto P_0c0c547c;
case 0x0c0c547eu: goto P_0c0c547e;
case 0x0c0c5480u: goto P_0c0c5480;
case 0x0c0c5482u: goto P_0c0c5482;
case 0x0c0c5484u: goto P_0c0c5484;
case 0x0c0c5486u: goto P_0c0c5486;
case 0x0c0c5488u: goto P_0c0c5488;
case 0x0c0c548au: goto P_0c0c548a;
case 0x0c0c548cu: goto P_0c0c548c;
case 0x0c0c548eu: goto P_0c0c548e;
case 0x0c0c5490u: goto P_0c0c5490;
case 0x0c0c5492u: goto P_0c0c5492;
case 0x0c0c5494u: goto P_0c0c5494;
case 0x0c0c5496u: goto P_0c0c5496;
case 0x0c0c5498u: goto P_0c0c5498;
case 0x0c0c549au: goto P_0c0c549a;
case 0x0c0c549cu: goto P_0c0c549c;
case 0x0c0c549eu: goto P_0c0c549e;
case 0x0c0c54a0u: goto P_0c0c54a0;
case 0x0c0c54a2u: goto P_0c0c54a2;
case 0x0c0c54a4u: goto P_0c0c54a4;
case 0x0c0c54a6u: goto P_0c0c54a6;
case 0x0c0c54a8u: goto P_0c0c54a8;
case 0x0c0c54aau: goto P_0c0c54aa;
case 0x0c0c54acu: goto P_0c0c54ac;
case 0x0c0c54aeu: goto P_0c0c54ae;
case 0x0c0c54b0u: goto P_0c0c54b0;
case 0x0c0c54b2u: goto P_0c0c54b2;
case 0x0c0c54b4u: goto P_0c0c54b4;
case 0x0c0c54b6u: goto P_0c0c54b6;
case 0x0c0c54b8u: goto P_0c0c54b8;
case 0x0c0c54bau: goto P_0c0c54ba;
case 0x0c0c54bcu: goto P_0c0c54bc;
case 0x0c0c54beu: goto P_0c0c54be;
case 0x0c0c54c0u: goto P_0c0c54c0;
case 0x0c0c54c2u: goto P_0c0c54c2;
case 0x0c0c54c4u: goto P_0c0c54c4;
case 0x0c0c54c6u: goto P_0c0c54c6;
case 0x0c0c54c8u: goto P_0c0c54c8;
case 0x0c0c54cau: goto P_0c0c54ca;
case 0x0c0c54ccu: goto P_0c0c54cc;
case 0x0c0c54ceu: goto P_0c0c54ce;
case 0x0c0c54d0u: goto P_0c0c54d0;
case 0x0c0c54d2u: goto P_0c0c54d2;
case 0x0c0c54d4u: goto P_0c0c54d4;
case 0x0c0c54d6u: goto P_0c0c54d6;
case 0x0c0c54d8u: goto P_0c0c54d8;
case 0x0c0c54dau: goto P_0c0c54da;
case 0x0c0c54dcu: goto P_0c0c54dc;
case 0x0c0c54deu: goto P_0c0c54de;
case 0x0c0c54e0u: goto P_0c0c54e0;
case 0x0c0c54e2u: goto P_0c0c54e2;
case 0x0c0c54e4u: goto P_0c0c54e4;
case 0x0c0c54e6u: goto P_0c0c54e6;
case 0x0c0c54e8u: goto P_0c0c54e8;
case 0x0c0c54eau: goto P_0c0c54ea;
case 0x0c0c54ecu: goto P_0c0c54ec;
case 0x0c0c54eeu: goto P_0c0c54ee;
case 0x0c0c54f0u: goto P_0c0c54f0;
case 0x0c0c54f2u: goto P_0c0c54f2;
case 0x0c0c54f4u: goto P_0c0c54f4;
case 0x0c0c54f6u: goto P_0c0c54f6;
case 0x0c0c54f8u: goto P_0c0c54f8;
case 0x0c0c54fau: goto P_0c0c54fa;
case 0x0c0c54fcu: goto P_0c0c54fc;
case 0x0c0c54feu: goto P_0c0c54fe;
case 0x0c0c5500u: goto P_0c0c5500;
case 0x0c0c5502u: goto P_0c0c5502;
case 0x0c0c5504u: goto P_0c0c5504;
case 0x0c0c5506u: goto P_0c0c5506;
case 0x0c0c5508u: goto P_0c0c5508;
case 0x0c0c550au: goto P_0c0c550a;
case 0x0c0c550cu: goto P_0c0c550c;
case 0x0c0c550eu: goto P_0c0c550e;
case 0x0c0c5510u: goto P_0c0c5510;
case 0x0c0c5512u: goto P_0c0c5512;
case 0x0c0c5514u: goto P_0c0c5514;
case 0x0c0c5516u: goto P_0c0c5516;
case 0x0c0c5518u: goto P_0c0c5518;
case 0x0c0c551au: goto P_0c0c551a;
case 0x0c0c5558u: goto P_0c0c5558;
case 0x0c0c555au: goto P_0c0c555a;
case 0x0c0c555cu: goto P_0c0c555c;
case 0x0c0c555eu: goto P_0c0c555e;
case 0x0c0c5560u: goto P_0c0c5560;
case 0x0c0c5562u: goto P_0c0c5562;
case 0x0c0c5564u: goto P_0c0c5564;
case 0x0c0c5566u: goto P_0c0c5566;
case 0x0c0c5568u: goto P_0c0c5568;
case 0x0c0c556au: goto P_0c0c556a;
case 0x0c0c556cu: goto P_0c0c556c;
case 0x0c0c556eu: goto P_0c0c556e;
case 0x0c0c5570u: goto P_0c0c5570;
case 0x0c0c5572u: goto P_0c0c5572;
case 0x0c0c5574u: goto P_0c0c5574;
case 0x0c0c5576u: goto P_0c0c5576;
case 0x0c0c5578u: goto P_0c0c5578;
case 0x0c0c557au: goto P_0c0c557a;
case 0x0c0c557cu: goto P_0c0c557c;
case 0x0c0c557eu: goto P_0c0c557e;
case 0x0c0c5580u: goto P_0c0c5580;
case 0x0c0c5582u: goto P_0c0c5582;
case 0x0c0c5584u: goto P_0c0c5584;
case 0x0c0c5586u: goto P_0c0c5586;
case 0x0c0c5588u: goto P_0c0c5588;
case 0x0c0c558au: goto P_0c0c558a;
case 0x0c0c558cu: goto P_0c0c558c;
case 0x0c0c558eu: goto P_0c0c558e;
case 0x0c0c5590u: goto P_0c0c5590;
case 0x0c0c5592u: goto P_0c0c5592;
case 0x0c0c5594u: goto P_0c0c5594;
case 0x0c0c5596u: goto P_0c0c5596;
case 0x0c0c5598u: goto P_0c0c5598;
case 0x0c0c559au: goto P_0c0c559a;
case 0x0c0c559cu: goto P_0c0c559c;
case 0x0c0c559eu: goto P_0c0c559e;
case 0x0c0c55a0u: goto P_0c0c55a0;
case 0x0c0c55a2u: goto P_0c0c55a2;
case 0x0c0c55a4u: goto P_0c0c55a4;
case 0x0c0c55a6u: goto P_0c0c55a6;
case 0x0c0c55a8u: goto P_0c0c55a8;
case 0x0c0c55aau: goto P_0c0c55aa;
case 0x0c0c55acu: goto P_0c0c55ac;
case 0x0c0c55aeu: goto P_0c0c55ae;
case 0x0c0c55b0u: goto P_0c0c55b0;
case 0x0c0c55b2u: goto P_0c0c55b2;
case 0x0c0c55b4u: goto P_0c0c55b4;
case 0x0c0c55b6u: goto P_0c0c55b6;
case 0x0c0c55b8u: goto P_0c0c55b8;
case 0x0c0c55bau: goto P_0c0c55ba;
case 0x0c0c55bcu: goto P_0c0c55bc;
case 0x0c0c55beu: goto P_0c0c55be;
case 0x0c0c55c0u: goto P_0c0c55c0;
case 0x0c0c55c2u: goto P_0c0c55c2;
case 0x0c0c55c4u: goto P_0c0c55c4;
case 0x0c0c55c6u: goto P_0c0c55c6;
case 0x0c0c55c8u: goto P_0c0c55c8;
case 0x0c0c55cau: goto P_0c0c55ca;
case 0x0c0c55ccu: goto P_0c0c55cc;
case 0x0c0c55ceu: goto P_0c0c55ce;
case 0x0c0c55d0u: goto P_0c0c55d0;
case 0x0c0c55d2u: goto P_0c0c55d2;
case 0x0c0c55d4u: goto P_0c0c55d4;
case 0x0c0c55d6u: goto P_0c0c55d6;
case 0x0c0c55d8u: goto P_0c0c55d8;
case 0x0c0c55dau: goto P_0c0c55da;
case 0x0c0c55dcu: goto P_0c0c55dc;
case 0x0c0c55deu: goto P_0c0c55de;
case 0x0c0c55e0u: goto P_0c0c55e0;
case 0x0c0c55e2u: goto P_0c0c55e2;
case 0x0c0c55e4u: goto P_0c0c55e4;
case 0x0c0c55e6u: goto P_0c0c55e6;
case 0x0c0c55e8u: goto P_0c0c55e8;
case 0x0c0c5604u: goto P_0c0c5604;
case 0x0c0c5606u: goto P_0c0c5606;
case 0x0c0c5608u: goto P_0c0c5608;
case 0x0c0c560au: goto P_0c0c560a;
case 0x0c0c560cu: goto P_0c0c560c;
case 0x0c0c560eu: goto P_0c0c560e;
case 0x0c0c5610u: goto P_0c0c5610;
case 0x0c0c5612u: goto P_0c0c5612;
case 0x0c0c5614u: goto P_0c0c5614;
case 0x0c0c5616u: goto P_0c0c5616;
case 0x0c0c5618u: goto P_0c0c5618;
case 0x0c0c561au: goto P_0c0c561a;
case 0x0c0c561cu: goto P_0c0c561c;
case 0x0c0c561eu: goto P_0c0c561e;
case 0x0c0c5620u: goto P_0c0c5620;
case 0x0c0c5622u: goto P_0c0c5622;
case 0x0c0c5624u: goto P_0c0c5624;
case 0x0c0c5626u: goto P_0c0c5626;
case 0x0c0c5628u: goto P_0c0c5628;
case 0x0c0c562au: goto P_0c0c562a;
case 0x0c0c562cu: goto P_0c0c562c;
case 0x0c0c562eu: goto P_0c0c562e;
case 0x0c0c5630u: goto P_0c0c5630;
case 0x0c0c5632u: goto P_0c0c5632;
case 0x0c0c5634u: goto P_0c0c5634;
case 0x0c0c5636u: goto P_0c0c5636;
case 0x0c0c5638u: goto P_0c0c5638;
case 0x0c0c563au: goto P_0c0c563a;
case 0x0c0c563cu: goto P_0c0c563c;
case 0x0c0c563eu: goto P_0c0c563e;
case 0x0c0c5640u: goto P_0c0c5640;
case 0x0c0c5642u: goto P_0c0c5642;
case 0x0c0c5644u: goto P_0c0c5644;
case 0x0c0c5646u: goto P_0c0c5646;
case 0x0c0c5648u: goto P_0c0c5648;
case 0x0c0c564au: goto P_0c0c564a;
case 0x0c0c564cu: goto P_0c0c564c;
case 0x0c0c564eu: goto P_0c0c564e;
case 0x0c0c5650u: goto P_0c0c5650;
case 0x0c0c5652u: goto P_0c0c5652;
case 0x0c0c5654u: goto P_0c0c5654;
case 0x0c0c5656u: goto P_0c0c5656;
case 0x0c0c5658u: goto P_0c0c5658;
case 0x0c0c565au: goto P_0c0c565a;
case 0x0c0c565cu: goto P_0c0c565c;
case 0x0c0c565eu: goto P_0c0c565e;
case 0x0c0c5660u: goto P_0c0c5660;
case 0x0c0c5662u: goto P_0c0c5662;
case 0x0c0c5664u: goto P_0c0c5664;
case 0x0c0c5666u: goto P_0c0c5666;
case 0x0c0c5668u: goto P_0c0c5668;
case 0x0c0c566au: goto P_0c0c566a;
case 0x0c0c566cu: goto P_0c0c566c;
case 0x0c0c566eu: goto P_0c0c566e;
case 0x0c0c5670u: goto P_0c0c5670;
case 0x0c0c5672u: goto P_0c0c5672;
case 0x0c0c5674u: goto P_0c0c5674;
case 0x0c0c5676u: goto P_0c0c5676;
case 0x0c0c5678u: goto P_0c0c5678;
case 0x0c0c567au: goto P_0c0c567a;
case 0x0c0c567cu: goto P_0c0c567c;
case 0x0c0c567eu: goto P_0c0c567e;
case 0x0c0c5680u: goto P_0c0c5680;
case 0x0c0c5682u: goto P_0c0c5682;
case 0x0c0c5684u: goto P_0c0c5684;
case 0x0c0c5686u: goto P_0c0c5686;
case 0x0c0c5688u: goto P_0c0c5688;
case 0x0c0c568au: goto P_0c0c568a;
case 0x0c0c568cu: goto P_0c0c568c;
case 0x0c0c568eu: goto P_0c0c568e;
case 0x0c0c5690u: goto P_0c0c5690;
case 0x0c0c5692u: goto P_0c0c5692;
case 0x0c0c5694u: goto P_0c0c5694;
case 0x0c0c5696u: goto P_0c0c5696;
case 0x0c0c5698u: goto P_0c0c5698;
case 0x0c0c569au: goto P_0c0c569a;
case 0x0c0c569cu: goto P_0c0c569c;
case 0x0c0c569eu: goto P_0c0c569e;
case 0x0c0c56a0u: goto P_0c0c56a0;
case 0x0c0c56a2u: goto P_0c0c56a2;
case 0x0c0c56a4u: goto P_0c0c56a4;
case 0x0c0c56a6u: goto P_0c0c56a6;
case 0x0c0c56a8u: goto P_0c0c56a8;
case 0x0c0c56aau: goto P_0c0c56aa;
case 0x0c0c56acu: goto P_0c0c56ac;
case 0x0c0c56aeu: goto P_0c0c56ae;
case 0x0c0c56b0u: goto P_0c0c56b0;
case 0x0c0c56b2u: goto P_0c0c56b2;
case 0x0c0c56b4u: goto P_0c0c56b4;
case 0x0c0c56b6u: goto P_0c0c56b6;
case 0x0c0c56b8u: goto P_0c0c56b8;
case 0x0c0c56bau: goto P_0c0c56ba;
case 0x0c0c56bcu: goto P_0c0c56bc;
case 0x0c0c56beu: goto P_0c0c56be;
case 0x0c0c56c0u: goto P_0c0c56c0;
case 0x0c0c56c2u: goto P_0c0c56c2;
case 0x0c0c56c4u: goto P_0c0c56c4;
case 0x0c0c56c6u: goto P_0c0c56c6;
case 0x0c0c56c8u: goto P_0c0c56c8;
case 0x0c0c56cau: goto P_0c0c56ca;
case 0x0c0c56ccu: goto P_0c0c56cc;
case 0x0c0c56ceu: goto P_0c0c56ce;
case 0x0c0c56d0u: goto P_0c0c56d0;
case 0x0c0c56d2u: goto P_0c0c56d2;
case 0x0c0c56d4u: goto P_0c0c56d4;
case 0x0c0c56d6u: goto P_0c0c56d6;
case 0x0c0c56d8u: goto P_0c0c56d8;
case 0x0c0c56dau: goto P_0c0c56da;
case 0x0c0c56dcu: goto P_0c0c56dc;
case 0x0c0c56deu: goto P_0c0c56de;
case 0x0c0c56e0u: goto P_0c0c56e0;
case 0x0c0c56e2u: goto P_0c0c56e2;
case 0x0c0c56e4u: goto P_0c0c56e4;
case 0x0c0c56e6u: goto P_0c0c56e6;
case 0x0c0c56e8u: goto P_0c0c56e8;
case 0x0c0c56eau: goto P_0c0c56ea;
case 0x0c0c56ecu: goto P_0c0c56ec;
case 0x0c0c56eeu: goto P_0c0c56ee;
case 0x0c0c56f0u: goto P_0c0c56f0;
case 0x0c0c56f2u: goto P_0c0c56f2;
case 0x0c0c56f4u: goto P_0c0c56f4;
case 0x0c0c56f6u: goto P_0c0c56f6;
case 0x0c0c56f8u: goto P_0c0c56f8;
case 0x0c0c56fau: goto P_0c0c56fa;
case 0x0c0c56fcu: goto P_0c0c56fc;
case 0x0c0c56feu: goto P_0c0c56fe;
case 0x0c0c5700u: goto P_0c0c5700;
case 0x0c0c5702u: goto P_0c0c5702;
case 0x0c0c5704u: goto P_0c0c5704;
case 0x0c0c5706u: goto P_0c0c5706;
case 0x0c0c5708u: goto P_0c0c5708;
case 0x0c0c570au: goto P_0c0c570a;
case 0x0c0c570cu: goto P_0c0c570c;
case 0x0c0c570eu: goto P_0c0c570e;
case 0x0c0c5710u: goto P_0c0c5710;
case 0x0c0c5712u: goto P_0c0c5712;
case 0x0c0c5714u: goto P_0c0c5714;
case 0x0c0c5716u: goto P_0c0c5716;
case 0x0c0c5718u: goto P_0c0c5718;
case 0x0c0c571au: goto P_0c0c571a;
case 0x0c0c571cu: goto P_0c0c571c;
case 0x0c0c571eu: goto P_0c0c571e;
case 0x0c0c5720u: goto P_0c0c5720;
case 0x0c0c5722u: goto P_0c0c5722;
case 0x0c0c5724u: goto P_0c0c5724;
case 0x0c0c5726u: goto P_0c0c5726;
case 0x0c0c5728u: goto P_0c0c5728;
case 0x0c0c572au: goto P_0c0c572a;
case 0x0c0c572cu: goto P_0c0c572c;
case 0x0c0c572eu: goto P_0c0c572e;
case 0x0c0c5730u: goto P_0c0c5730;
case 0x0c0c5732u: goto P_0c0c5732;
case 0x0c0c5734u: goto P_0c0c5734;
case 0x0c0c5736u: goto P_0c0c5736;
case 0x0c0c5738u: goto P_0c0c5738;
case 0x0c0c573au: goto P_0c0c573a;
case 0x0c0c573cu: goto P_0c0c573c;
case 0x0c0c573eu: goto P_0c0c573e;
case 0x0c0c5740u: goto P_0c0c5740;
case 0x0c0c5742u: goto P_0c0c5742;
case 0x0c0c5744u: goto P_0c0c5744;
case 0x0c0c5746u: goto P_0c0c5746;
case 0x0c0c5748u: goto P_0c0c5748;
case 0x0c0c574au: goto P_0c0c574a;
case 0x0c0c574cu: goto P_0c0c574c;
case 0x0c0c574eu: goto P_0c0c574e;
case 0x0c0c5750u: goto P_0c0c5750;
case 0x0c0c5752u: goto P_0c0c5752;
case 0x0c0c5754u: goto P_0c0c5754;
case 0x0c0c5756u: goto P_0c0c5756;
case 0x0c0c5758u: goto P_0c0c5758;
case 0x0c0c575au: goto P_0c0c575a;
case 0x0c0c575cu: goto P_0c0c575c;
case 0x0c0c575eu: goto P_0c0c575e;
case 0x0c0c5760u: goto P_0c0c5760;
case 0x0c0c5762u: goto P_0c0c5762;
case 0x0c0c5764u: goto P_0c0c5764;
case 0x0c0c57b0u: goto P_0c0c57b0;
case 0x0c0c57b2u: goto P_0c0c57b2;
case 0x0c0c57b4u: goto P_0c0c57b4;
case 0x0c0c57b6u: goto P_0c0c57b6;
case 0x0c0c57b8u: goto P_0c0c57b8;
case 0x0c0c57bau: goto P_0c0c57ba;
case 0x0c0c57bcu: goto P_0c0c57bc;
case 0x0c0c57beu: goto P_0c0c57be;
case 0x0c0c57c0u: goto P_0c0c57c0;
case 0x0c0c57c2u: goto P_0c0c57c2;
case 0x0c0c57c4u: goto P_0c0c57c4;
case 0x0c0c57c6u: goto P_0c0c57c6;
case 0x0c0c57c8u: goto P_0c0c57c8;
case 0x0c0c57cau: goto P_0c0c57ca;
case 0x0c0c57ccu: goto P_0c0c57cc;
case 0x0c0c57ceu: goto P_0c0c57ce;
case 0x0c0c57d0u: goto P_0c0c57d0;
case 0x0c0c57d2u: goto P_0c0c57d2;
case 0x0c0c57d4u: goto P_0c0c57d4;
case 0x0c0c57d6u: goto P_0c0c57d6;
case 0x0c0c57d8u: goto P_0c0c57d8;
case 0x0c0c57dau: goto P_0c0c57da;
case 0x0c0c57dcu: goto P_0c0c57dc;
case 0x0c0c57deu: goto P_0c0c57de;
case 0x0c0c57e0u: goto P_0c0c57e0;
case 0x0c0c57e2u: goto P_0c0c57e2;
case 0x0c0c57e4u: goto P_0c0c57e4;
case 0x0c0c57e6u: goto P_0c0c57e6;
case 0x0c0c57e8u: goto P_0c0c57e8;
case 0x0c0c57eau: goto P_0c0c57ea;
case 0x0c0c57ecu: goto P_0c0c57ec;
case 0x0c0c57eeu: goto P_0c0c57ee;
case 0x0c0c57f0u: goto P_0c0c57f0;
case 0x0c0c57f2u: goto P_0c0c57f2;
case 0x0c0c57f4u: goto P_0c0c57f4;
case 0x0c0c57f6u: goto P_0c0c57f6;
case 0x0c0c57f8u: goto P_0c0c57f8;
case 0x0c0c57fau: goto P_0c0c57fa;
case 0x0c0c57fcu: goto P_0c0c57fc;
case 0x0c0c57feu: goto P_0c0c57fe;
case 0x0c0c5800u: goto P_0c0c5800;
case 0x0c0c5802u: goto P_0c0c5802;
case 0x0c0c5804u: goto P_0c0c5804;
case 0x0c0c5806u: goto P_0c0c5806;
case 0x0c0c5808u: goto P_0c0c5808;
case 0x0c0c580au: goto P_0c0c580a;
case 0x0c0c580cu: goto P_0c0c580c;
case 0x0c0c580eu: goto P_0c0c580e;
case 0x0c0c5810u: goto P_0c0c5810;
case 0x0c0c5812u: goto P_0c0c5812;
case 0x0c0c5814u: goto P_0c0c5814;
case 0x0c0c5816u: goto P_0c0c5816;
case 0x0c0c5818u: goto P_0c0c5818;
case 0x0c0c581au: goto P_0c0c581a;
case 0x0c0c581cu: goto P_0c0c581c;
case 0x0c0c581eu: goto P_0c0c581e;
case 0x0c0c5820u: goto P_0c0c5820;
case 0x0c0c5822u: goto P_0c0c5822;
case 0x0c0c5824u: goto P_0c0c5824;
case 0x0c0c5826u: goto P_0c0c5826;
case 0x0c0c5828u: goto P_0c0c5828;
case 0x0c0c582au: goto P_0c0c582a;
case 0x0c0c582cu: goto P_0c0c582c;
case 0x0c0c582eu: goto P_0c0c582e;
case 0x0c0c5830u: goto P_0c0c5830;
case 0x0c0c5832u: goto P_0c0c5832;
case 0x0c0c5834u: goto P_0c0c5834;
case 0x0c0c5836u: goto P_0c0c5836;
case 0x0c0c5838u: goto P_0c0c5838;
case 0x0c0c583au: goto P_0c0c583a;
case 0x0c0c583cu: goto P_0c0c583c;
case 0x0c0c583eu: goto P_0c0c583e;
case 0x0c0c5840u: goto P_0c0c5840;
case 0x0c0c5842u: goto P_0c0c5842;
case 0x0c0c5844u: goto P_0c0c5844;
case 0x0c0c5846u: goto P_0c0c5846;
case 0x0c0c5848u: goto P_0c0c5848;
case 0x0c0c584au: goto P_0c0c584a;
case 0x0c0c584cu: goto P_0c0c584c;
case 0x0c0c584eu: goto P_0c0c584e;
case 0x0c0c5850u: goto P_0c0c5850;
case 0x0c0c5852u: goto P_0c0c5852;
case 0x0c0c5854u: goto P_0c0c5854;
case 0x0c0c5856u: goto P_0c0c5856;
case 0x0c0c5858u: goto P_0c0c5858;
case 0x0c0c585au: goto P_0c0c585a;
case 0x0c0c585cu: goto P_0c0c585c;
case 0x0c0c585eu: goto P_0c0c585e;
case 0x0c0c5860u: goto P_0c0c5860;
case 0x0c0c5862u: goto P_0c0c5862;
case 0x0c0c5864u: goto P_0c0c5864;
case 0x0c0c5866u: goto P_0c0c5866;
case 0x0c0c5868u: goto P_0c0c5868;
case 0x0c0c586au: goto P_0c0c586a;
case 0x0c0c586cu: goto P_0c0c586c;
case 0x0c0c586eu: goto P_0c0c586e;
case 0x0c0c5870u: goto P_0c0c5870;
case 0x0c0c5872u: goto P_0c0c5872;
case 0x0c0c5874u: goto P_0c0c5874;
case 0x0c0c5876u: goto P_0c0c5876;
case 0x0c0c5878u: goto P_0c0c5878;
case 0x0c0c587au: goto P_0c0c587a;
case 0x0c0c587cu: goto P_0c0c587c;
case 0x0c0c587eu: goto P_0c0c587e;
case 0x0c0c5880u: goto P_0c0c5880;
case 0x0c0c5882u: goto P_0c0c5882;
case 0x0c0c5884u: goto P_0c0c5884;
case 0x0c0c5886u: goto P_0c0c5886;
case 0x0c0c5888u: goto P_0c0c5888;
case 0x0c0c588au: goto P_0c0c588a;
case 0x0c0c588cu: goto P_0c0c588c;
case 0x0c0c588eu: goto P_0c0c588e;
case 0x0c0c5890u: goto P_0c0c5890;
case 0x0c0c5892u: goto P_0c0c5892;
case 0x0c0c5894u: goto P_0c0c5894;
case 0x0c0c5896u: goto P_0c0c5896;
case 0x0c0c5898u: goto P_0c0c5898;
case 0x0c0c589au: goto P_0c0c589a;
case 0x0c0c589cu: goto P_0c0c589c;
case 0x0c0c589eu: goto P_0c0c589e;
case 0x0c0c58a0u: goto P_0c0c58a0;
case 0x0c0c58a2u: goto P_0c0c58a2;
case 0x0c0c58a4u: goto P_0c0c58a4;
case 0x0c0c58a6u: goto P_0c0c58a6;
case 0x0c0c58a8u: goto P_0c0c58a8;
case 0x0c0c58aau: goto P_0c0c58aa;
case 0x0c0c58acu: goto P_0c0c58ac;
case 0x0c0c58aeu: goto P_0c0c58ae;
case 0x0c0c58b0u: goto P_0c0c58b0;
case 0x0c0c58b2u: goto P_0c0c58b2;
case 0x0c0c58b4u: goto P_0c0c58b4;
case 0x0c0c58b6u: goto P_0c0c58b6;
case 0x0c0c58b8u: goto P_0c0c58b8;
case 0x0c0c58bau: goto P_0c0c58ba;
case 0x0c0c58bcu: goto P_0c0c58bc;
case 0x0c0c58beu: goto P_0c0c58be;
case 0x0c0c58c0u: goto P_0c0c58c0;
case 0x0c0c58c2u: goto P_0c0c58c2;
case 0x0c0c58c4u: goto P_0c0c58c4;
case 0x0c0c58c6u: goto P_0c0c58c6;
case 0x0c0c58c8u: goto P_0c0c58c8;
case 0x0c0c58cau: goto P_0c0c58ca;
case 0x0c0c58ccu: goto P_0c0c58cc;
case 0x0c0c58ceu: goto P_0c0c58ce;
case 0x0c0c58d0u: goto P_0c0c58d0;
case 0x0c0c58d2u: goto P_0c0c58d2;
case 0x0c0c58d4u: goto P_0c0c58d4;
case 0x0c0c58d6u: goto P_0c0c58d6;
case 0x0c0c58d8u: goto P_0c0c58d8;
case 0x0c0c58dau: goto P_0c0c58da;
case 0x0c0c58dcu: goto P_0c0c58dc;
case 0x0c0c58deu: goto P_0c0c58de;
case 0x0c0c58e0u: goto P_0c0c58e0;
case 0x0c0c58e2u: goto P_0c0c58e2;
case 0x0c0c58e4u: goto P_0c0c58e4;
case 0x0c0c58e6u: goto P_0c0c58e6;
case 0x0c0c58e8u: goto P_0c0c58e8;
case 0x0c0c58eau: goto P_0c0c58ea;
case 0x0c0c58ecu: goto P_0c0c58ec;
case 0x0c0c58eeu: goto P_0c0c58ee;
case 0x0c0c58f0u: goto P_0c0c58f0;
case 0x0c0c58f2u: goto P_0c0c58f2;
case 0x0c0c58f4u: goto P_0c0c58f4;
case 0x0c0c58f6u: goto P_0c0c58f6;
case 0x0c0c58f8u: goto P_0c0c58f8;
case 0x0c0c58fau: goto P_0c0c58fa;
case 0x0c0c58fcu: goto P_0c0c58fc;
case 0x0c0c5938u: goto P_0c0c5938;
case 0x0c0c593au: goto P_0c0c593a;
case 0x0c0c593cu: goto P_0c0c593c;
case 0x0c0c593eu: goto P_0c0c593e;
case 0x0c0c5940u: goto P_0c0c5940;
case 0x0c0c5942u: goto P_0c0c5942;
case 0x0c0c5944u: goto P_0c0c5944;
case 0x0c0c5946u: goto P_0c0c5946;
case 0x0c0c5948u: goto P_0c0c5948;
case 0x0c0c594au: goto P_0c0c594a;
case 0x0c0c594cu: goto P_0c0c594c;
case 0x0c0c594eu: goto P_0c0c594e;
case 0x0c0c5950u: goto P_0c0c5950;
case 0x0c0c5952u: goto P_0c0c5952;
case 0x0c0c5954u: goto P_0c0c5954;
case 0x0c0c5956u: goto P_0c0c5956;
case 0x0c0c5958u: goto P_0c0c5958;
case 0x0c0c595au: goto P_0c0c595a;
case 0x0c0c595cu: goto P_0c0c595c;
case 0x0c0c595eu: goto P_0c0c595e;
case 0x0c0c5960u: goto P_0c0c5960;
case 0x0c0c5962u: goto P_0c0c5962;
case 0x0c0c5964u: goto P_0c0c5964;
case 0x0c0c5966u: goto P_0c0c5966;
case 0x0c0c5968u: goto P_0c0c5968;
case 0x0c0c596au: goto P_0c0c596a;
case 0x0c0c596cu: goto P_0c0c596c;
case 0x0c0c596eu: goto P_0c0c596e;
case 0x0c0c5970u: goto P_0c0c5970;
case 0x0c0c5972u: goto P_0c0c5972;
case 0x0c0c5974u: goto P_0c0c5974;
case 0x0c0c5976u: goto P_0c0c5976;
case 0x0c0c5978u: goto P_0c0c5978;
case 0x0c0c597au: goto P_0c0c597a;
case 0x0c0c597cu: goto P_0c0c597c;
case 0x0c0c597eu: goto P_0c0c597e;
case 0x0c0c5980u: goto P_0c0c5980;
case 0x0c0c5982u: goto P_0c0c5982;
case 0x0c0c5984u: goto P_0c0c5984;
case 0x0c0c5986u: goto P_0c0c5986;
case 0x0c0c5988u: goto P_0c0c5988;
case 0x0c0c598au: goto P_0c0c598a;
case 0x0c0c598cu: goto P_0c0c598c;
case 0x0c0c598eu: goto P_0c0c598e;
case 0x0c0c5990u: goto P_0c0c5990;
case 0x0c0c5992u: goto P_0c0c5992;
case 0x0c0c5994u: goto P_0c0c5994;
case 0x0c0c5996u: goto P_0c0c5996;
case 0x0c0c5998u: goto P_0c0c5998;
case 0x0c0c599au: goto P_0c0c599a;
case 0x0c0c599cu: goto P_0c0c599c;
case 0x0c0c599eu: goto P_0c0c599e;
case 0x0c0c59a0u: goto P_0c0c59a0;
case 0x0c0c59a2u: goto P_0c0c59a2;
case 0x0c0c59a4u: goto P_0c0c59a4;
case 0x0c0c59a6u: goto P_0c0c59a6;
case 0x0c0c59a8u: goto P_0c0c59a8;
case 0x0c0c59aau: goto P_0c0c59aa;
case 0x0c0c59acu: goto P_0c0c59ac;
case 0x0c0c59aeu: goto P_0c0c59ae;
case 0x0c0c59b0u: goto P_0c0c59b0;
case 0x0c0c59b2u: goto P_0c0c59b2;
case 0x0c0c59b4u: goto P_0c0c59b4;
case 0x0c0c59b6u: goto P_0c0c59b6;
case 0x0c0c59b8u: goto P_0c0c59b8;
case 0x0c0c59bau: goto P_0c0c59ba;
case 0x0c0c59bcu: goto P_0c0c59bc;
case 0x0c0c59beu: goto P_0c0c59be;
case 0x0c0c59c0u: goto P_0c0c59c0;
case 0x0c0c59c2u: goto P_0c0c59c2;
case 0x0c0c59c4u: goto P_0c0c59c4;
case 0x0c0c59c6u: goto P_0c0c59c6;
case 0x0c0c59c8u: goto P_0c0c59c8;
case 0x0c0c59cau: goto P_0c0c59ca;
case 0x0c0c59ccu: goto P_0c0c59cc;
case 0x0c0c59ceu: goto P_0c0c59ce;
case 0x0c0c59d0u: goto P_0c0c59d0;
case 0x0c0c59d2u: goto P_0c0c59d2;
case 0x0c0c59d4u: goto P_0c0c59d4;
case 0x0c0c59d6u: goto P_0c0c59d6;
case 0x0c0c59d8u: goto P_0c0c59d8;
case 0x0c0c59dau: goto P_0c0c59da;
case 0x0c0c59dcu: goto P_0c0c59dc;
case 0x0c0c59deu: goto P_0c0c59de;
case 0x0c0c59e0u: goto P_0c0c59e0;
case 0x0c0c59e2u: goto P_0c0c59e2;
case 0x0c0c59e4u: goto P_0c0c59e4;
case 0x0c0c59e6u: goto P_0c0c59e6;
case 0x0c0c59e8u: goto P_0c0c59e8;
case 0x0c0c59eau: goto P_0c0c59ea;
case 0x0c0c59ecu: goto P_0c0c59ec;
case 0x0c0c59eeu: goto P_0c0c59ee;
case 0x0c0c59f0u: goto P_0c0c59f0;
case 0x0c0c59f2u: goto P_0c0c59f2;
case 0x0c0c59f4u: goto P_0c0c59f4;
case 0x0c0c59f6u: goto P_0c0c59f6;
case 0x0c0c59f8u: goto P_0c0c59f8;
case 0x0c0c59fau: goto P_0c0c59fa;
case 0x0c0c59fcu: goto P_0c0c59fc;
case 0x0c0c59feu: goto P_0c0c59fe;
case 0x0c0c5a00u: goto P_0c0c5a00;
case 0x0c0c5a02u: goto P_0c0c5a02;
case 0x0c0c5a04u: goto P_0c0c5a04;
case 0x0c0c5a06u: goto P_0c0c5a06;
case 0x0c0c5a08u: goto P_0c0c5a08;
case 0x0c0c5a0au: goto P_0c0c5a0a;
case 0x0c0c5a0cu: goto P_0c0c5a0c;
case 0x0c0c5a0eu: goto P_0c0c5a0e;
case 0x0c0c5a10u: goto P_0c0c5a10;
case 0x0c0c5a12u: goto P_0c0c5a12;
case 0x0c0c5a14u: goto P_0c0c5a14;
case 0x0c0c5a16u: goto P_0c0c5a16;
case 0x0c0c5a18u: goto P_0c0c5a18;
case 0x0c0c5a1au: goto P_0c0c5a1a;
case 0x0c0c5a1cu: goto P_0c0c5a1c;
case 0x0c0c5a1eu: goto P_0c0c5a1e;
case 0x0c0c5a20u: goto P_0c0c5a20;
case 0x0c0c5a22u: goto P_0c0c5a22;
case 0x0c0c5a24u: goto P_0c0c5a24;
case 0x0c0c5a26u: goto P_0c0c5a26;
case 0x0c0c5a28u: goto P_0c0c5a28;
case 0x0c0c5a2au: goto P_0c0c5a2a;
case 0x0c0c5a2cu: goto P_0c0c5a2c;
case 0x0c0c5a2eu: goto P_0c0c5a2e;
case 0x0c0c5a30u: goto P_0c0c5a30;
case 0x0c0c5a32u: goto P_0c0c5a32;
case 0x0c0c5a34u: goto P_0c0c5a34;
case 0x0c0c5a36u: goto P_0c0c5a36;
case 0x0c0c5a38u: goto P_0c0c5a38;
case 0x0c0c5a3au: goto P_0c0c5a3a;
case 0x0c0c5a3cu: goto P_0c0c5a3c;
case 0x0c0c5a3eu: goto P_0c0c5a3e;
case 0x0c0c5a40u: goto P_0c0c5a40;
case 0x0c0c5a42u: goto P_0c0c5a42;
case 0x0c0c5a44u: goto P_0c0c5a44;
case 0x0c0c5a46u: goto P_0c0c5a46;
case 0x0c0c5a48u: goto P_0c0c5a48;
case 0x0c0c5a4au: goto P_0c0c5a4a;
case 0x0c0c5a4cu: goto P_0c0c5a4c;
case 0x0c0c5a4eu: goto P_0c0c5a4e;
case 0x0c0c5a50u: goto P_0c0c5a50;
case 0x0c0c5a52u: goto P_0c0c5a52;
case 0x0c0c5a54u: goto P_0c0c5a54;
case 0x0c0c5a56u: goto P_0c0c5a56;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c5048: /* original 2fe6, guest PC 0x0c0c5048 */
if(!s->budget--) { s->failed_pc=0x0c0c5048u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c504a;
P_0c0c504a: /* original 2fd6, guest PC 0x0c0c504a */
if(!s->budget--) { s->failed_pc=0x0c0c504au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c504c;
P_0c0c504c: /* original 2fc6, guest PC 0x0c0c504c */
if(!s->budget--) { s->failed_pc=0x0c0c504cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c504e;
P_0c0c504e: /* original ec00, guest PC 0x0c0c504e */
if(!s->budget--) { s->failed_pc=0x0c0c504eu; return 0; }
r[12]=0x00000000u;
goto P_0c0c5050;
P_0c0c5050: /* original 2fb6, guest PC 0x0c0c5050 */
if(!s->budget--) { s->failed_pc=0x0c0c5050u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5052;
P_0c0c5052: /* original 2fa6, guest PC 0x0c0c5052 */
if(!s->budget--) { s->failed_pc=0x0c0c5052u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5054;
P_0c0c5054: /* original 2f96, guest PC 0x0c0c5054 */
if(!s->budget--) { s->failed_pc=0x0c0c5054u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5056;
P_0c0c5056: /* original 6973, guest PC 0x0c0c5056 */
if(!s->budget--) { s->failed_pc=0x0c0c5056u; return 0; }
r[9]=r[7];
goto P_0c0c5058;
P_0c0c5058: /* original 2f86, guest PC 0x0c0c5058 */
if(!s->budget--) { s->failed_pc=0x0c0c5058u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c505a;
P_0c0c505a: /* original fffb, guest PC 0x0c0c505a */
if(!s->budget--) { s->failed_pc=0x0c0c505au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c505c;
P_0c0c505c: /* original ffeb, guest PC 0x0c0c505c */
if(!s->budget--) { s->failed_pc=0x0c0c505cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c505e;
P_0c0c505e: /* original ffdb, guest PC 0x0c0c505e */
if(!s->budget--) { s->failed_pc=0x0c0c505eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c5060;
P_0c0c5060: /* original ffcb, guest PC 0x0c0c5060 */
if(!s->budget--) { s->failed_pc=0x0c0c5060u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0c5062;
P_0c0c5062: /* original 4f22, guest PC 0x0c0c5062 */
if(!s->budget--) { s->failed_pc=0x0c0c5062u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5064;
P_0c0c5064: /* original 90b5, guest PC 0x0c0c5064 */
if(!s->budget--) { s->failed_pc=0x0c0c5064u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d2u,2);
goto P_0c0c5066;
P_0c0c5066: /* original dd61, guest PC 0x0c0c5066 */
if(!s->budget--) { s->failed_pc=0x0c0c5066u; return 0; }
r[13]=read(ram,0x0c0c51ecu,4);
goto P_0c0c5068;
P_0c0c5068: /* original 3f0c, guest PC 0x0c0c5068 */
if(!s->budget--) { s->failed_pc=0x0c0c5068u; return 0; }
r[15]+=r[0];
goto P_0c0c506a;
P_0c0c506a: /* original c75f, guest PC 0x0c0c506a */
if(!s->budget--) { s->failed_pc=0x0c0c506au; return 0; }
r[0]=code_base|0x000c51e8u;
goto P_0c0c506c;
P_0c0c506c: /* original fc08, guest PC 0x0c0c506c */
if(!s->budget--) { s->failed_pc=0x0c0c506cu; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c0c506e;
P_0c0c506e: /* original 1f5f, guest PC 0x0c0c506e */
if(!s->budget--) { s->failed_pc=0x0c0c506eu; return 0; }
write(ram,r[15]+60,r[5],4);
goto P_0c0c5070;
P_0c0c5070: /* original 1f6c, guest PC 0x0c0c5070 */
if(!s->budget--) { s->failed_pc=0x0c0c5070u; return 0; }
write(ram,r[15]+48,r[6],4);
goto P_0c0c5072;
P_0c0c5072: /* original 90af, guest PC 0x0c0c5072 */
if(!s->budget--) { s->failed_pc=0x0c0c5072u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d4u,2);
goto P_0c0c5074;
P_0c0c5074: /* original d35e, guest PC 0x0c0c5074 */
if(!s->budget--) { s->failed_pc=0x0c0c5074u; return 0; }
r[3]=read(ram,0x0c0c51f0u,4);
goto P_0c0c5076;
P_0c0c5076: /* original 0afe, guest PC 0x0c0c5076 */
if(!s->budget--) { s->failed_pc=0x0c0c5076u; return 0; }
r[10]=read(ram,r[15]+r[0],4);
goto P_0c0c5078;
P_0c0c5078: /* original 430b, guest PC 0x0c0c5078 */
if(!s->budget--) { s->failed_pc=0x0c0c5078u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c507cu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c507cu) { target=s->pc; goto dispatch; }
goto P_0c0c507c;
P_0c0c507a: /* original 64a3, guest PC 0x0c0c507a */
if(!s->budget--) { s->failed_pc=0x0c0c507au; return 0; }
r[4]=r[10];
goto P_0c0c507c;
P_0c0c507c: /* original e026, guest PC 0x0c0c507c */
if(!s->budget--) { s->failed_pc=0x0c0c507cu; return 0; }
r[0]=0x00000026u;
goto P_0c0c507e;
P_0c0c507e: /* original 02ad, guest PC 0x0c0c507e */
if(!s->budget--) { s->failed_pc=0x0c0c507eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c5080;
P_0c0c5080: /* original e044, guest PC 0x0c0c5080 */
if(!s->budget--) { s->failed_pc=0x0c0c5080u; return 0; }
r[0]=0x00000044u;
goto P_0c0c5082;
P_0c0c5082: /* original 622d, guest PC 0x0c0c5082 */
if(!s->budget--) { s->failed_pc=0x0c0c5082u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c5084;
P_0c0c5084: /* original 0f26, guest PC 0x0c0c5084 */
if(!s->budget--) { s->failed_pc=0x0c0c5084u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c5086;
P_0c0c5086: /* original db5b, guest PC 0x0c0c5086 */
if(!s->budget--) { s->failed_pc=0x0c0c5086u; return 0; }
r[11]=read(ram,0x0c0c51f4u,4);
goto P_0c0c5088;
P_0c0c5088: /* original 4b0b, guest PC 0x0c0c5088 */
if(!s->budget--) { s->failed_pc=0x0c0c5088u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c508cu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c508cu) { target=s->pc; goto dispatch; }
goto P_0c0c508c;
P_0c0c508a: /* original 6493, guest PC 0x0c0c508a */
if(!s->budget--) { s->failed_pc=0x0c0c508au; return 0; }
r[4]=r[9];
goto P_0c0c508c;
P_0c0c508c: /* original 6393, guest PC 0x0c0c508c */
if(!s->budget--) { s->failed_pc=0x0c0c508cu; return 0; }
r[3]=r[9];
goto P_0c0c508e;
P_0c0c508e: /* original 6e03, guest PC 0x0c0c508e */
if(!s->budget--) { s->failed_pc=0x0c0c508eu; return 0; }
r[14]=r[0];
goto P_0c0c5090;
P_0c0c5090: /* original e020, guest PC 0x0c0c5090 */
if(!s->budget--) { s->failed_pc=0x0c0c5090u; return 0; }
r[0]=0x00000020u;
goto P_0c0c5092;
P_0c0c5092: /* original 7305, guest PC 0x0c0c5092 */
if(!s->budget--) { s->failed_pc=0x0c0c5092u; return 0; }
r[3]+=0x00000005u;
goto P_0c0c5094;
P_0c0c5094: /* original 0f35, guest PC 0x0c0c5094 */
if(!s->budget--) { s->failed_pc=0x0c0c5094u; return 0; }
write(ram,r[15]+r[0],r[3],2);
goto P_0c0c5096;
P_0c0c5096: /* original 50e8, guest PC 0x0c0c5096 */
if(!s->budget--) { s->failed_pc=0x0c0c5096u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c0c5098;
P_0c0c5098: /* original 882c, guest PC 0x0c0c5098 */
if(!s->budget--) { s->failed_pc=0x0c0c5098u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c0c509a;
P_0c0c509a: /* original 8d03, guest PC 0x0c0c509a */
if(!s->budget--) { s->failed_pc=0x0c0c509au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c50a4; }
goto P_0c0c509e;
P_0c0c509c: /* original 6403, guest PC 0x0c0c509c */
if(!s->budget--) { s->failed_pc=0x0c0c509cu; return 0; }
r[4]=r[0];
goto P_0c0c509e;
P_0c0c509e: /* original 6043, guest PC 0x0c0c509e */
if(!s->budget--) { s->failed_pc=0x0c0c509eu; return 0; }
r[0]=r[4];
goto P_0c0c50a0;
P_0c0c50a0: /* original 8834, guest PC 0x0c0c50a0 */
if(!s->budget--) { s->failed_pc=0x0c0c50a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c0c50a2;
P_0c0c50a2: /* original 8b70, guest PC 0x0c0c50a2 */
if(!s->budget--) { s->failed_pc=0x0c0c50a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5186; }
goto P_0c0c50a4;
P_0c0c50a4: /* original 9497, guest PC 0x0c0c50a4 */
if(!s->budget--) { s->failed_pc=0x0c0c50a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c50a6;
P_0c0c50a6: /* original 65e3, guest PC 0x0c0c50a6 */
if(!s->budget--) { s->failed_pc=0x0c0c50a6u; return 0; }
r[5]=r[14];
goto P_0c0c50a8;
P_0c0c50a8: /* original da53, guest PC 0x0c0c50a8 */
if(!s->budget--) { s->failed_pc=0x0c0c50a8u; return 0; }
r[10]=read(ram,0x0c0c51f8u,4);
goto P_0c0c50aa;
P_0c0c50aa: /* original e624, guest PC 0x0c0c50aa */
if(!s->budget--) { s->failed_pc=0x0c0c50aau; return 0; }
r[6]=0x00000024u;
goto P_0c0c50ac;
P_0c0c50ac: /* original 4a0b, guest PC 0x0c0c50ac */
if(!s->budget--) { s->failed_pc=0x0c0c50acu; return 0; }
target=r[10];
r[16]=code_base|0x0c0c50b0u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c50b0u) { target=s->pc; goto dispatch; }
goto P_0c0c50b0;
P_0c0c50ae: /* original 34fc, guest PC 0x0c0c50ae */
if(!s->budget--) { s->failed_pc=0x0c0c50aeu; return 0; }
r[4]+=r[15];
goto P_0c0c50b0;
P_0c0c50b0: /* original 6493, guest PC 0x0c0c50b0 */
if(!s->budget--) { s->failed_pc=0x0c0c50b0u; return 0; }
r[4]=r[9];
goto P_0c0c50b2;
P_0c0c50b2: /* original 4b0b, guest PC 0x0c0c50b2 */
if(!s->budget--) { s->failed_pc=0x0c0c50b2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c50b6u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c50b6u) { target=s->pc; goto dispatch; }
goto P_0c0c50b6;
P_0c0c50b4: /* original 7403, guest PC 0x0c0c50b4 */
if(!s->budget--) { s->failed_pc=0x0c0c50b4u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c50b6;
P_0c0c50b6: /* original 6503, guest PC 0x0c0c50b6 */
if(!s->budget--) { s->failed_pc=0x0c0c50b6u; return 0; }
r[5]=r[0];
goto P_0c0c50b8;
P_0c0c50b8: /* original 908d, guest PC 0x0c0c50b8 */
if(!s->budget--) { s->failed_pc=0x0c0c50b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c50ba;
P_0c0c50ba: /* original f258, guest PC 0x0c0c50ba */
if(!s->budget--) { s->failed_pc=0x0c0c50bau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0c50bc;
P_0c0c50bc: /* original e624, guest PC 0x0c0c50bc */
if(!s->budget--) { s->failed_pc=0x0c0c50bcu; return 0; }
r[6]=0x00000024u;
goto P_0c0c50be;
P_0c0c50be: /* original f3f6, guest PC 0x0c0c50be */
if(!s->budget--) { s->failed_pc=0x0c0c50beu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50c0;
P_0c0c50c0: /* original f230, guest PC 0x0c0c50c0 */
if(!s->budget--) { s->failed_pc=0x0c0c50c0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50c2;
P_0c0c50c2: /* original f52a, guest PC 0x0c0c50c2 */
if(!s->budget--) { s->failed_pc=0x0c0c50c2u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c0c50c4;
P_0c0c50c4: /* original 9088, guest PC 0x0c0c50c4 */
if(!s->budget--) { s->failed_pc=0x0c0c50c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d8u,2);
goto P_0c0c50c6;
P_0c0c50c6: /* original f3f6, guest PC 0x0c0c50c6 */
if(!s->budget--) { s->failed_pc=0x0c0c50c6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50c8;
P_0c0c50c8: /* original e004, guest PC 0x0c0c50c8 */
if(!s->budget--) { s->failed_pc=0x0c0c50c8u; return 0; }
r[0]=0x00000004u;
goto P_0c0c50ca;
P_0c0c50ca: /* original f256, guest PC 0x0c0c50ca */
if(!s->budget--) { s->failed_pc=0x0c0c50cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c50cc;
P_0c0c50cc: /* original f230, guest PC 0x0c0c50cc */
if(!s->budget--) { s->failed_pc=0x0c0c50ccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50ce;
P_0c0c50ce: /* original f527, guest PC 0x0c0c50ce */
if(!s->budget--) { s->failed_pc=0x0c0c50ceu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c50d0;
P_0c0c50d0: /* original 9083, guest PC 0x0c0c50d0 */
if(!s->budget--) { s->failed_pc=0x0c0c50d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dau,2);
goto P_0c0c50d2;
P_0c0c50d2: /* original f3f6, guest PC 0x0c0c50d2 */
if(!s->budget--) { s->failed_pc=0x0c0c50d2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50d4;
P_0c0c50d4: /* original e018, guest PC 0x0c0c50d4 */
if(!s->budget--) { s->failed_pc=0x0c0c50d4u; return 0; }
r[0]=0x00000018u;
goto P_0c0c50d6;
P_0c0c50d6: /* original f256, guest PC 0x0c0c50d6 */
if(!s->budget--) { s->failed_pc=0x0c0c50d6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c50d8;
P_0c0c50d8: /* original f230, guest PC 0x0c0c50d8 */
if(!s->budget--) { s->failed_pc=0x0c0c50d8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50da;
P_0c0c50da: /* original f527, guest PC 0x0c0c50da */
if(!s->budget--) { s->failed_pc=0x0c0c50dau; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c50dc;
P_0c0c50dc: /* original 907e, guest PC 0x0c0c50dc */
if(!s->budget--) { s->failed_pc=0x0c0c50dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dcu,2);
goto P_0c0c50de;
P_0c0c50de: /* original f3f6, guest PC 0x0c0c50de */
if(!s->budget--) { s->failed_pc=0x0c0c50deu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50e0;
P_0c0c50e0: /* original e01c, guest PC 0x0c0c50e0 */
if(!s->budget--) { s->failed_pc=0x0c0c50e0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c50e2;
P_0c0c50e2: /* original f256, guest PC 0x0c0c50e2 */
if(!s->budget--) { s->failed_pc=0x0c0c50e2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c50e4;
P_0c0c50e4: /* original f230, guest PC 0x0c0c50e4 */
if(!s->budget--) { s->failed_pc=0x0c0c50e4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50e6;
P_0c0c50e6: /* original f527, guest PC 0x0c0c50e6 */
if(!s->budget--) { s->failed_pc=0x0c0c50e6u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c50e8;
P_0c0c50e8: /* original 9079, guest PC 0x0c0c50e8 */
if(!s->budget--) { s->failed_pc=0x0c0c50e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51deu,2);
goto P_0c0c50ea;
P_0c0c50ea: /* original f3f6, guest PC 0x0c0c50ea */
if(!s->budget--) { s->failed_pc=0x0c0c50eau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50ec;
P_0c0c50ec: /* original e008, guest PC 0x0c0c50ec */
if(!s->budget--) { s->failed_pc=0x0c0c50ecu; return 0; }
r[0]=0x00000008u;
goto P_0c0c50ee;
P_0c0c50ee: /* original f256, guest PC 0x0c0c50ee */
if(!s->budget--) { s->failed_pc=0x0c0c50eeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c50f0;
P_0c0c50f0: /* original f230, guest PC 0x0c0c50f0 */
if(!s->budget--) { s->failed_pc=0x0c0c50f0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50f2;
P_0c0c50f2: /* original f527, guest PC 0x0c0c50f2 */
if(!s->budget--) { s->failed_pc=0x0c0c50f2u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c50f4;
P_0c0c50f4: /* original 946f, guest PC 0x0c0c50f4 */
if(!s->budget--) { s->failed_pc=0x0c0c50f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c50f6;
P_0c0c50f6: /* original 4a0b, guest PC 0x0c0c50f6 */
if(!s->budget--) { s->failed_pc=0x0c0c50f6u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c50fau;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c50fau) { target=s->pc; goto dispatch; }
goto P_0c0c50fa;
P_0c0c50f8: /* original 34fc, guest PC 0x0c0c50f8 */
if(!s->budget--) { s->failed_pc=0x0c0c50f8u; return 0; }
r[4]+=r[15];
goto P_0c0c50fa;
P_0c0c50fa: /* original 6493, guest PC 0x0c0c50fa */
if(!s->budget--) { s->failed_pc=0x0c0c50fau; return 0; }
r[4]=r[9];
goto P_0c0c50fc;
P_0c0c50fc: /* original 4b0b, guest PC 0x0c0c50fc */
if(!s->budget--) { s->failed_pc=0x0c0c50fcu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c5100u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5100u) { target=s->pc; goto dispatch; }
goto P_0c0c5100;
P_0c0c50fe: /* original 7404, guest PC 0x0c0c50fe */
if(!s->budget--) { s->failed_pc=0x0c0c50feu; return 0; }
r[4]+=0x00000004u;
goto P_0c0c5100;
P_0c0c5100: /* original 6503, guest PC 0x0c0c5100 */
if(!s->budget--) { s->failed_pc=0x0c0c5100u; return 0; }
r[5]=r[0];
goto P_0c0c5102;
P_0c0c5102: /* original 9068, guest PC 0x0c0c5102 */
if(!s->budget--) { s->failed_pc=0x0c0c5102u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c5104;
P_0c0c5104: /* original f258, guest PC 0x0c0c5104 */
if(!s->budget--) { s->failed_pc=0x0c0c5104u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0c5106;
P_0c0c5106: /* original e624, guest PC 0x0c0c5106 */
if(!s->budget--) { s->failed_pc=0x0c0c5106u; return 0; }
r[6]=0x00000024u;
goto P_0c0c5108;
P_0c0c5108: /* original f3f6, guest PC 0x0c0c5108 */
if(!s->budget--) { s->failed_pc=0x0c0c5108u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c510a;
P_0c0c510a: /* original f230, guest PC 0x0c0c510a */
if(!s->budget--) { s->failed_pc=0x0c0c510au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c510c;
P_0c0c510c: /* original f52a, guest PC 0x0c0c510c */
if(!s->budget--) { s->failed_pc=0x0c0c510cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c0c510e;
P_0c0c510e: /* original 9063, guest PC 0x0c0c510e */
if(!s->budget--) { s->failed_pc=0x0c0c510eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d8u,2);
goto P_0c0c5110;
P_0c0c5110: /* original f3f6, guest PC 0x0c0c5110 */
if(!s->budget--) { s->failed_pc=0x0c0c5110u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5112;
P_0c0c5112: /* original e004, guest PC 0x0c0c5112 */
if(!s->budget--) { s->failed_pc=0x0c0c5112u; return 0; }
r[0]=0x00000004u;
goto P_0c0c5114;
P_0c0c5114: /* original f256, guest PC 0x0c0c5114 */
if(!s->budget--) { s->failed_pc=0x0c0c5114u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c5116;
P_0c0c5116: /* original f230, guest PC 0x0c0c5116 */
if(!s->budget--) { s->failed_pc=0x0c0c5116u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5118;
P_0c0c5118: /* original f527, guest PC 0x0c0c5118 */
if(!s->budget--) { s->failed_pc=0x0c0c5118u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c511a;
P_0c0c511a: /* original 905e, guest PC 0x0c0c511a */
if(!s->budget--) { s->failed_pc=0x0c0c511au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dau,2);
goto P_0c0c511c;
P_0c0c511c: /* original f3f6, guest PC 0x0c0c511c */
if(!s->budget--) { s->failed_pc=0x0c0c511cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c511e;
P_0c0c511e: /* original e018, guest PC 0x0c0c511e */
if(!s->budget--) { s->failed_pc=0x0c0c511eu; return 0; }
r[0]=0x00000018u;
goto P_0c0c5120;
P_0c0c5120: /* original f256, guest PC 0x0c0c5120 */
if(!s->budget--) { s->failed_pc=0x0c0c5120u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c5122;
P_0c0c5122: /* original f230, guest PC 0x0c0c5122 */
if(!s->budget--) { s->failed_pc=0x0c0c5122u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5124;
P_0c0c5124: /* original f527, guest PC 0x0c0c5124 */
if(!s->budget--) { s->failed_pc=0x0c0c5124u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c5126;
P_0c0c5126: /* original 9059, guest PC 0x0c0c5126 */
if(!s->budget--) { s->failed_pc=0x0c0c5126u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dcu,2);
goto P_0c0c5128;
P_0c0c5128: /* original f3f6, guest PC 0x0c0c5128 */
if(!s->budget--) { s->failed_pc=0x0c0c5128u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c512a;
P_0c0c512a: /* original e01c, guest PC 0x0c0c512a */
if(!s->budget--) { s->failed_pc=0x0c0c512au; return 0; }
r[0]=0x0000001cu;
goto P_0c0c512c;
P_0c0c512c: /* original f256, guest PC 0x0c0c512c */
if(!s->budget--) { s->failed_pc=0x0c0c512cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c512e;
P_0c0c512e: /* original f230, guest PC 0x0c0c512e */
if(!s->budget--) { s->failed_pc=0x0c0c512eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5130;
P_0c0c5130: /* original f527, guest PC 0x0c0c5130 */
if(!s->budget--) { s->failed_pc=0x0c0c5130u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c5132;
P_0c0c5132: /* original 9054, guest PC 0x0c0c5132 */
if(!s->budget--) { s->failed_pc=0x0c0c5132u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51deu,2);
goto P_0c0c5134;
P_0c0c5134: /* original f3f6, guest PC 0x0c0c5134 */
if(!s->budget--) { s->failed_pc=0x0c0c5134u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5136;
P_0c0c5136: /* original e008, guest PC 0x0c0c5136 */
if(!s->budget--) { s->failed_pc=0x0c0c5136u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5138;
P_0c0c5138: /* original f256, guest PC 0x0c0c5138 */
if(!s->budget--) { s->failed_pc=0x0c0c5138u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c513a;
P_0c0c513a: /* original f230, guest PC 0x0c0c513a */
if(!s->budget--) { s->failed_pc=0x0c0c513au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c513c;
P_0c0c513c: /* original f527, guest PC 0x0c0c513c */
if(!s->budget--) { s->failed_pc=0x0c0c513cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c513e;
P_0c0c513e: /* original 944a, guest PC 0x0c0c513e */
if(!s->budget--) { s->failed_pc=0x0c0c513eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c5140;
P_0c0c5140: /* original 4a0b, guest PC 0x0c0c5140 */
if(!s->budget--) { s->failed_pc=0x0c0c5140u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c5144u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5144u) { target=s->pc; goto dispatch; }
goto P_0c0c5144;
P_0c0c5142: /* original 34fc, guest PC 0x0c0c5142 */
if(!s->budget--) { s->failed_pc=0x0c0c5142u; return 0; }
r[4]+=r[15];
goto P_0c0c5144;
P_0c0c5144: /* original e020, guest PC 0x0c0c5144 */
if(!s->budget--) { s->failed_pc=0x0c0c5144u; return 0; }
r[0]=0x00000020u;
goto P_0c0c5146;
P_0c0c5146: /* original 4b0b, guest PC 0x0c0c5146 */
if(!s->budget--) { s->failed_pc=0x0c0c5146u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c514au;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c514au) { target=s->pc; goto dispatch; }
goto P_0c0c514a;
P_0c0c5148: /* original 04fd, guest PC 0x0c0c5148 */
if(!s->budget--) { s->failed_pc=0x0c0c5148u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0c514a;
P_0c0c514a: /* original 6e03, guest PC 0x0c0c514a */
if(!s->budget--) { s->failed_pc=0x0c0c514au; return 0; }
r[14]=r[0];
goto P_0c0c514c;
P_0c0c514c: /* original 9043, guest PC 0x0c0c514c */
if(!s->budget--) { s->failed_pc=0x0c0c514cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c514e;
P_0c0c514e: /* original f2e8, guest PC 0x0c0c514e */
if(!s->budget--) { s->failed_pc=0x0c0c514eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
goto P_0c0c5150;
P_0c0c5150: /* original f3f6, guest PC 0x0c0c5150 */
if(!s->budget--) { s->failed_pc=0x0c0c5150u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5152;
P_0c0c5152: /* original f230, guest PC 0x0c0c5152 */
if(!s->budget--) { s->failed_pc=0x0c0c5152u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5154;
P_0c0c5154: /* original fe2a, guest PC 0x0c0c5154 */
if(!s->budget--) { s->failed_pc=0x0c0c5154u; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c0c5156;
P_0c0c5156: /* original 903f, guest PC 0x0c0c5156 */
if(!s->budget--) { s->failed_pc=0x0c0c5156u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d8u,2);
goto P_0c0c5158;
P_0c0c5158: /* original f3f6, guest PC 0x0c0c5158 */
if(!s->budget--) { s->failed_pc=0x0c0c5158u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c515a;
P_0c0c515a: /* original e004, guest PC 0x0c0c515a */
if(!s->budget--) { s->failed_pc=0x0c0c515au; return 0; }
r[0]=0x00000004u;
goto P_0c0c515c;
P_0c0c515c: /* original f2e6, guest PC 0x0c0c515c */
if(!s->budget--) { s->failed_pc=0x0c0c515cu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c515e;
P_0c0c515e: /* original f230, guest PC 0x0c0c515e */
if(!s->budget--) { s->failed_pc=0x0c0c515eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5160;
P_0c0c5160: /* original fe27, guest PC 0x0c0c5160 */
if(!s->budget--) { s->failed_pc=0x0c0c5160u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c5162;
P_0c0c5162: /* original 903a, guest PC 0x0c0c5162 */
if(!s->budget--) { s->failed_pc=0x0c0c5162u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dau,2);
goto P_0c0c5164;
P_0c0c5164: /* original f3f6, guest PC 0x0c0c5164 */
if(!s->budget--) { s->failed_pc=0x0c0c5164u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5166;
P_0c0c5166: /* original e018, guest PC 0x0c0c5166 */
if(!s->budget--) { s->failed_pc=0x0c0c5166u; return 0; }
r[0]=0x00000018u;
goto P_0c0c5168;
P_0c0c5168: /* original f2e6, guest PC 0x0c0c5168 */
if(!s->budget--) { s->failed_pc=0x0c0c5168u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c516a;
P_0c0c516a: /* original f230, guest PC 0x0c0c516a */
if(!s->budget--) { s->failed_pc=0x0c0c516au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c516c;
P_0c0c516c: /* original fe27, guest PC 0x0c0c516c */
if(!s->budget--) { s->failed_pc=0x0c0c516cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c516e;
P_0c0c516e: /* original 9035, guest PC 0x0c0c516e */
if(!s->budget--) { s->failed_pc=0x0c0c516eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dcu,2);
goto P_0c0c5170;
P_0c0c5170: /* original f3f6, guest PC 0x0c0c5170 */
if(!s->budget--) { s->failed_pc=0x0c0c5170u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5172;
P_0c0c5172: /* original e01c, guest PC 0x0c0c5172 */
if(!s->budget--) { s->failed_pc=0x0c0c5172u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5174;
P_0c0c5174: /* original f2e6, guest PC 0x0c0c5174 */
if(!s->budget--) { s->failed_pc=0x0c0c5174u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c5176;
P_0c0c5176: /* original f230, guest PC 0x0c0c5176 */
if(!s->budget--) { s->failed_pc=0x0c0c5176u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5178;
P_0c0c5178: /* original fe27, guest PC 0x0c0c5178 */
if(!s->budget--) { s->failed_pc=0x0c0c5178u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c517a;
P_0c0c517a: /* original 9030, guest PC 0x0c0c517a */
if(!s->budget--) { s->failed_pc=0x0c0c517au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51deu,2);
goto P_0c0c517c;
P_0c0c517c: /* original f3f6, guest PC 0x0c0c517c */
if(!s->budget--) { s->failed_pc=0x0c0c517cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c517e;
P_0c0c517e: /* original e008, guest PC 0x0c0c517e */
if(!s->budget--) { s->failed_pc=0x0c0c517eu; return 0; }
r[0]=0x00000008u;
goto P_0c0c5180;
P_0c0c5180: /* original f2e6, guest PC 0x0c0c5180 */
if(!s->budget--) { s->failed_pc=0x0c0c5180u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c5182;
P_0c0c5182: /* original f230, guest PC 0x0c0c5182 */
if(!s->budget--) { s->failed_pc=0x0c0c5182u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5184;
P_0c0c5184: /* original fe27, guest PC 0x0c0c5184 */
if(!s->budget--) { s->failed_pc=0x0c0c5184u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c5186;
P_0c0c5186: /* original e008, guest PC 0x0c0c5186 */
if(!s->budget--) { s->failed_pc=0x0c0c5186u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5188;
P_0c0c5188: /* original f3e6, guest PC 0x0c0c5188 */
if(!s->budget--) { s->failed_pc=0x0c0c5188u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c518a;
P_0c0c518a: /* original e048, guest PC 0x0c0c518a */
if(!s->budget--) { s->failed_pc=0x0c0c518au; return 0; }
r[0]=0x00000048u;
goto P_0c0c518c;
P_0c0c518c: /* original f33d, guest PC 0x0c0c518c */
if(!s->budget--) { s->failed_pc=0x0c0c518cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c518e;
P_0c0c518e: /* original 035a, guest PC 0x0c0c518e */
if(!s->budget--) { s->failed_pc=0x0c0c518eu; return 0; }
r[3]=r[53];
goto P_0c0c5190;
P_0c0c5190: /* original 4321, guest PC 0x0c0c5190 */
if(!s->budget--) { s->failed_pc=0x0c0c5190u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c5192;
P_0c0c5192: /* original 4321, guest PC 0x0c0c5192 */
if(!s->budget--) { s->failed_pc=0x0c0c5192u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c5194;
P_0c0c5194: /* original 4321, guest PC 0x0c0c5194 */
if(!s->budget--) { s->failed_pc=0x0c0c5194u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c5196;
P_0c0c5196: /* original 0f36, guest PC 0x0c0c5196 */
if(!s->budget--) { s->failed_pc=0x0c0c5196u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c5198;
P_0c0c5198: /* original e00c, guest PC 0x0c0c5198 */
if(!s->budget--) { s->failed_pc=0x0c0c5198u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c519a;
P_0c0c519a: /* original f3e6, guest PC 0x0c0c519a */
if(!s->budget--) { s->failed_pc=0x0c0c519au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c519c;
P_0c0c519c: /* original e050, guest PC 0x0c0c519c */
if(!s->budget--) { s->failed_pc=0x0c0c519cu; return 0; }
r[0]=0x00000050u;
goto P_0c0c519e;
P_0c0c519e: /* original f33d, guest PC 0x0c0c519e */
if(!s->budget--) { s->failed_pc=0x0c0c519eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c51a0;
P_0c0c51a0: /* original 025a, guest PC 0x0c0c51a0 */
if(!s->budget--) { s->failed_pc=0x0c0c51a0u; return 0; }
r[2]=r[53];
goto P_0c0c51a2;
P_0c0c51a2: /* original 4221, guest PC 0x0c0c51a2 */
if(!s->budget--) { s->failed_pc=0x0c0c51a2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0c51a4;
P_0c0c51a4: /* original 4221, guest PC 0x0c0c51a4 */
if(!s->budget--) { s->failed_pc=0x0c0c51a4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0c51a6;
P_0c0c51a6: /* original 4221, guest PC 0x0c0c51a6 */
if(!s->budget--) { s->failed_pc=0x0c0c51a6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0c51a8;
P_0c0c51a8: /* original 0f26, guest PC 0x0c0c51a8 */
if(!s->budget--) { s->failed_pc=0x0c0c51a8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c51aa;
P_0c0c51aa: /* original 9019, guest PC 0x0c0c51aa */
if(!s->budget--) { s->failed_pc=0x0c0c51aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51e0u,2);
goto P_0c0c51ac;
P_0c0c51ac: /* original 0fc6, guest PC 0x0c0c51ac */
if(!s->budget--) { s->failed_pc=0x0c0c51acu; return 0; }
write(ram,r[15]+r[0],r[12],4);
goto P_0c0c51ae;
P_0c0c51ae: /* original d114, guest PC 0x0c0c51ae */
if(!s->budget--) { s->failed_pc=0x0c0c51aeu; return 0; }
r[1]=read(ram,0x0c0c5200u,4);
goto P_0c0c51b0;
P_0c0c51b0: /* original d012, guest PC 0x0c0c51b0 */
if(!s->budget--) { s->failed_pc=0x0c0c51b0u; return 0; }
r[0]=read(ram,0x0c0c51fcu,4);
goto P_0c0c51b2;
P_0c0c51b2: /* original 6310, guest PC 0x0c0c51b2 */
if(!s->budget--) { s->failed_pc=0x0c0c51b2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c0c51b4;
P_0c0c51b4: /* original 9215, guest PC 0x0c0c51b4 */
if(!s->budget--) { s->failed_pc=0x0c0c51b4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51e2u,2);
goto P_0c0c51b6;
P_0c0c51b6: /* original 633c, guest PC 0x0c0c51b6 */
if(!s->budget--) { s->failed_pc=0x0c0c51b6u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c51b8;
P_0c0c51b8: /* original 4308, guest PC 0x0c0c51b8 */
if(!s->budget--) { s->failed_pc=0x0c0c51b8u; return 0; }
r[3]<<=2;
goto P_0c0c51ba;
P_0c0c51ba: /* original 033e, guest PC 0x0c0c51ba */
if(!s->budget--) { s->failed_pc=0x0c0c51bau; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c0c51bc;
P_0c0c51bc: /* original 9012, guest PC 0x0c0c51bc */
if(!s->budget--) { s->failed_pc=0x0c0c51bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51e4u,2);
goto P_0c0c51be;
P_0c0c51be: /* original 232b, guest PC 0x0c0c51be */
if(!s->budget--) { s->failed_pc=0x0c0c51beu; return 0; }
r[3]|=r[2];
goto P_0c0c51c0;
P_0c0c51c0: /* original 0f36, guest PC 0x0c0c51c0 */
if(!s->budget--) { s->failed_pc=0x0c0c51c0u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c51c2;
P_0c0c51c2: /* original 9010, guest PC 0x0c0c51c2 */
if(!s->budget--) { s->failed_pc=0x0c0c51c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51e6u,2);
goto P_0c0c51c4;
P_0c0c51c4: /* original f39d, guest PC 0x0c0c51c4 */
if(!s->budget--) { s->failed_pc=0x0c0c51c4u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c51c6;
P_0c0c51c6: /* original ff37, guest PC 0x0c0c51c6 */
if(!s->budget--) { s->failed_pc=0x0c0c51c6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c51c8;
P_0c0c51c8: /* original 53fc, guest PC 0x0c0c51c8 */
if(!s->budget--) { s->failed_pc=0x0c0c51c8u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c0c51ca;
P_0c0c51ca: /* original 4321, guest PC 0x0c0c51ca */
if(!s->budget--) { s->failed_pc=0x0c0c51cau; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c51cc;
P_0c0c51cc: /* original 4321, guest PC 0x0c0c51cc */
if(!s->budget--) { s->failed_pc=0x0c0c51ccu; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c51ce;
P_0c0c51ce: /* original a019, guest PC 0x0c0c51ce */
if(!s->budget--) { s->failed_pc=0x0c0c51ceu; return 0; }
goto P_0c0c5204;
P_0c0c51d0: /* original 0009, guest PC 0x0c0c51d0 */
if(!s->budget--) { s->failed_pc=0x0c0c51d0u; return 0; }
if(!vf3_matrix_family(0x0c0c51d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c51d2u; return 0; } return 1;
P_0c0c5204: /* original e130, guest PC 0x0c0c5204 */
if(!s->budget--) { s->failed_pc=0x0c0c5204u; return 0; }
r[1]=0x00000030u;
goto P_0c0c5206;
P_0c0c5206: /* original e04c, guest PC 0x0c0c5206 */
if(!s->budget--) { s->failed_pc=0x0c0c5206u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c5208;
P_0c0c5208: /* original 4321, guest PC 0x0c0c5208 */
if(!s->budget--) { s->failed_pc=0x0c0c5208u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c520a;
P_0c0c520a: /* original 3313, guest PC 0x0c0c520a */
if(!s->budget--) { s->failed_pc=0x0c0c520au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c0c520c;
P_0c0c520c: /* original 0f36, guest PC 0x0c0c520c */
if(!s->budget--) { s->failed_pc=0x0c0c520cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c520e;
P_0c0c520e: /* original 2f32, guest PC 0x0c0c520e */
if(!s->budget--) { s->failed_pc=0x0c0c520eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c5210;
P_0c0c5210: /* original 8f02, guest PC 0x0c0c5210 */
if(!s->budget--) { s->failed_pc=0x0c0c5210u; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(!cond) { goto P_0c0c5218; }
goto P_0c0c5214;
P_0c0c5212: /* original ff8d, guest PC 0x0c0c5212 */
if(!s->budget--) { s->failed_pc=0x0c0c5212u; return 0; }
fr[15]=0;
goto P_0c0c5214;
P_0c0c5214: /* original e130, guest PC 0x0c0c5214 */
if(!s->budget--) { s->failed_pc=0x0c0c5214u; return 0; }
r[1]=0x00000030u;
goto P_0c0c5216;
P_0c0c5216: /* original 2f12, guest PC 0x0c0c5216 */
if(!s->budget--) { s->failed_pc=0x0c0c5216u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c5218;
P_0c0c5218: /* original e044, guest PC 0x0c0c5218 */
if(!s->budget--) { s->failed_pc=0x0c0c5218u; return 0; }
r[0]=0x00000044u;
goto P_0c0c521a;
P_0c0c521a: /* original d85b, guest PC 0x0c0c521a */
if(!s->budget--) { s->failed_pc=0x0c0c521au; return 0; }
r[8]=read(ram,0x0c0c5388u,4);
goto P_0c0c521c;
P_0c0c521c: /* original 03fe, guest PC 0x0c0c521c */
if(!s->budget--) { s->failed_pc=0x0c0c521cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c521e;
P_0c0c521e: /* original 4308, guest PC 0x0c0c521e */
if(!s->budget--) { s->failed_pc=0x0c0c521eu; return 0; }
r[3]<<=2;
goto P_0c0c5220;
P_0c0c5220: /* original 1f36, guest PC 0x0c0c5220 */
if(!s->budget--) { s->failed_pc=0x0c0c5220u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0c5222;
P_0c0c5222: /* original 62f2, guest PC 0x0c0c5222 */
if(!s->budget--) { s->failed_pc=0x0c0c5222u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c5224;
P_0c0c5224: /* original 4211, guest PC 0x0c0c5224 */
if(!s->budget--) { s->failed_pc=0x0c0c5224u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c5226;
P_0c0c5226: /* original 8b32, guest PC 0x0c0c5226 */
if(!s->budget--) { s->failed_pc=0x0c0c5226u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c528e; }
goto P_0c0c5228;
P_0c0c5228: /* original 6493, guest PC 0x0c0c5228 */
if(!s->budget--) { s->failed_pc=0x0c0c5228u; return 0; }
r[4]=r[9];
goto P_0c0c522a;
P_0c0c522a: /* original 4b0b, guest PC 0x0c0c522a */
if(!s->budget--) { s->failed_pc=0x0c0c522au; return 0; }
target=r[11];
r[16]=code_base|0x0c0c522eu;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c522eu) { target=s->pc; goto dispatch; }
goto P_0c0c522e;
P_0c0c522c: /* original 7401, guest PC 0x0c0c522c */
if(!s->budget--) { s->failed_pc=0x0c0c522cu; return 0; }
r[4]+=0x00000001u;
goto P_0c0c522e;
P_0c0c522e: /* original 63f2, guest PC 0x0c0c522e */
if(!s->budget--) { s->failed_pc=0x0c0c522eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c5230;
P_0c0c5230: /* original 6a03, guest PC 0x0c0c5230 */
if(!s->budget--) { s->failed_pc=0x0c0c5230u; return 0; }
r[10]=r[0];
goto P_0c0c5232;
P_0c0c5232: /* original e01c, guest PC 0x0c0c5232 */
if(!s->budget--) { s->failed_pc=0x0c0c5232u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5234;
P_0c0c5234: /* original 94a3, guest PC 0x0c0c5234 */
if(!s->budget--) { s->failed_pc=0x0c0c5234u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c5236;
P_0c0c5236: /* original 7302, guest PC 0x0c0c5236 */
if(!s->budget--) { s->failed_pc=0x0c0c5236u; return 0; }
r[3]+=0x00000002u;
goto P_0c0c5238;
P_0c0c5238: /* original f7e6, guest PC 0x0c0c5238 */
if(!s->budget--) { s->failed_pc=0x0c0c5238u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c523a;
P_0c0c523a: /* original 435a, guest PC 0x0c0c523a */
if(!s->budget--) { s->failed_pc=0x0c0c523au; return 0; }
r[53]=r[3];
goto P_0c0c523c;
P_0c0c523c: /* original c753, guest PC 0x0c0c523c */
if(!s->budget--) { s->failed_pc=0x0c0c523cu; return 0; }
r[0]=code_base|0x000c538cu;
goto P_0c0c523e;
P_0c0c523e: /* original 53f6, guest PC 0x0c0c523e */
if(!s->budget--) { s->failed_pc=0x0c0c523eu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c5240;
P_0c0c5240: /* original f5fc, guest PC 0x0c0c5240 */
if(!s->budget--) { s->failed_pc=0x0c0c5240u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c5242;
P_0c0c5242: /* original f32d, guest PC 0x0c0c5242 */
if(!s->budget--) { s->failed_pc=0x0c0c5242u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c5244;
P_0c0c5244: /* original f4fc, guest PC 0x0c0c5244 */
if(!s->budget--) { s->failed_pc=0x0c0c5244u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c5246;
P_0c0c5246: /* original f732, guest PC 0x0c0c5246 */
if(!s->budget--) { s->failed_pc=0x0c0c5246u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0c5248;
P_0c0c5248: /* original f308, guest PC 0x0c0c5248 */
if(!s->budget--) { s->failed_pc=0x0c0c5248u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c524a;
P_0c0c524a: /* original d051, guest PC 0x0c0c524a */
if(!s->budget--) { s->failed_pc=0x0c0c524au; return 0; }
r[0]=read(ram,0x0c0c5390u,4);
goto P_0c0c524c;
P_0c0c524c: /* original f836, guest PC 0x0c0c524c */
if(!s->budget--) { s->failed_pc=0x0c0c524cu; return 0; }
vf3_matrix_load(s,ram,8,r[3]+r[0]);
goto P_0c0c524e;
P_0c0c524e: /* original e018, guest PC 0x0c0c524e */
if(!s->budget--) { s->failed_pc=0x0c0c524eu; return 0; }
r[0]=0x00000018u;
goto P_0c0c5250;
P_0c0c5250: /* original d350, guest PC 0x0c0c5250 */
if(!s->budget--) { s->failed_pc=0x0c0c5250u; return 0; }
r[3]=read(ram,0x0c0c5394u,4);
goto P_0c0c5252;
P_0c0c5252: /* original f830, guest PC 0x0c0c5252 */
if(!s->budget--) { s->failed_pc=0x0c0c5252u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'+');
goto P_0c0c5254;
P_0c0c5254: /* original f6a6, guest PC 0x0c0c5254 */
if(!s->budget--) { s->failed_pc=0x0c0c5254u; return 0; }
vf3_matrix_load(s,ram,6,r[10]+r[0]);
goto P_0c0c5256;
P_0c0c5256: /* original 430b, guest PC 0x0c0c5256 */
if(!s->budget--) { s->failed_pc=0x0c0c5256u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c525au;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c525au) { target=s->pc; goto dispatch; }
goto P_0c0c525a;
P_0c0c5258: /* original 34fc, guest PC 0x0c0c5258 */
if(!s->budget--) { s->failed_pc=0x0c0c5258u; return 0; }
r[4]+=r[15];
goto P_0c0c525a;
P_0c0c525a: /* original e014, guest PC 0x0c0c525a */
if(!s->budget--) { s->failed_pc=0x0c0c525au; return 0; }
r[0]=0x00000014u;
goto P_0c0c525c;
P_0c0c525c: /* original 948f, guest PC 0x0c0c525c */
if(!s->budget--) { s->failed_pc=0x0c0c525cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c525e;
P_0c0c525e: /* original f9a6, guest PC 0x0c0c525e */
if(!s->budget--) { s->failed_pc=0x0c0c525eu; return 0; }
vf3_matrix_load(s,ram,9,r[10]+r[0]);
goto P_0c0c5260;
P_0c0c5260: /* original e010, guest PC 0x0c0c5260 */
if(!s->budget--) { s->failed_pc=0x0c0c5260u; return 0; }
r[0]=0x00000010u;
goto P_0c0c5262;
P_0c0c5262: /* original f8a6, guest PC 0x0c0c5262 */
if(!s->budget--) { s->failed_pc=0x0c0c5262u; return 0; }
vf3_matrix_load(s,ram,8,r[10]+r[0]);
goto P_0c0c5264;
P_0c0c5264: /* original e00c, guest PC 0x0c0c5264 */
if(!s->budget--) { s->failed_pc=0x0c0c5264u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5266;
P_0c0c5266: /* original f7a6, guest PC 0x0c0c5266 */
if(!s->budget--) { s->failed_pc=0x0c0c5266u; return 0; }
vf3_matrix_load(s,ram,7,r[10]+r[0]);
goto P_0c0c5268;
P_0c0c5268: /* original e008, guest PC 0x0c0c5268 */
if(!s->budget--) { s->failed_pc=0x0c0c5268u; return 0; }
r[0]=0x00000008u;
goto P_0c0c526a;
P_0c0c526a: /* original f6a6, guest PC 0x0c0c526a */
if(!s->budget--) { s->failed_pc=0x0c0c526au; return 0; }
vf3_matrix_load(s,ram,6,r[10]+r[0]);
goto P_0c0c526c;
P_0c0c526c: /* original e004, guest PC 0x0c0c526c */
if(!s->budget--) { s->failed_pc=0x0c0c526cu; return 0; }
r[0]=0x00000004u;
goto P_0c0c526e;
P_0c0c526e: /* original f4a8, guest PC 0x0c0c526e */
if(!s->budget--) { s->failed_pc=0x0c0c526eu; return 0; }
vf3_matrix_load(s,ram,4,r[10]);
goto P_0c0c5270;
P_0c0c5270: /* original f5a6, guest PC 0x0c0c5270 */
if(!s->budget--) { s->failed_pc=0x0c0c5270u; return 0; }
vf3_matrix_load(s,ram,5,r[10]+r[0]);
goto P_0c0c5272;
P_0c0c5272: /* original 480b, guest PC 0x0c0c5272 */
if(!s->budget--) { s->failed_pc=0x0c0c5272u; return 0; }
target=r[8];
r[16]=code_base|0x0c0c5276u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5276u) { target=s->pc; goto dispatch; }
goto P_0c0c5276;
P_0c0c5274: /* original 34fc, guest PC 0x0c0c5274 */
if(!s->budget--) { s->failed_pc=0x0c0c5274u; return 0; }
r[4]+=r[15];
goto P_0c0c5276;
P_0c0c5276: /* original 53e8, guest PC 0x0c0c5276 */
if(!s->budget--) { s->failed_pc=0x0c0c5276u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c5278;
P_0c0c5278: /* original d047, guest PC 0x0c0c5278 */
if(!s->budget--) { s->failed_pc=0x0c0c5278u; return 0; }
r[0]=read(ram,0x0c0c5398u,4);
goto P_0c0c527a;
P_0c0c527a: /* original 4300, guest PC 0x0c0c527a */
if(!s->budget--) { s->failed_pc=0x0c0c527au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c527c;
P_0c0c527c: /* original 023d, guest PC 0x0c0c527c */
if(!s->budget--) { s->failed_pc=0x0c0c527cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c527e;
P_0c0c527e: /* original 907e, guest PC 0x0c0c527e */
if(!s->budget--) { s->failed_pc=0x0c0c527eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c5280;
P_0c0c5280: /* original 622d, guest PC 0x0c0c5280 */
if(!s->budget--) { s->failed_pc=0x0c0c5280u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c5282;
P_0c0c5282: /* original 0f26, guest PC 0x0c0c5282 */
if(!s->budget--) { s->failed_pc=0x0c0c5282u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c5284;
P_0c0c5284: /* original 907c, guest PC 0x0c0c5284 */
if(!s->budget--) { s->failed_pc=0x0c0c5284u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5380u,2);
goto P_0c0c5286;
P_0c0c5286: /* original fff7, guest PC 0x0c0c5286 */
if(!s->budget--) { s->failed_pc=0x0c0c5286u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c5288;
P_0c0c5288: /* original 9479, guest PC 0x0c0c5288 */
if(!s->budget--) { s->failed_pc=0x0c0c5288u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c528a;
P_0c0c528a: /* original 4d0b, guest PC 0x0c0c528a */
if(!s->budget--) { s->failed_pc=0x0c0c528au; return 0; }
target=r[13];
r[16]=code_base|0x0c0c528eu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c528eu) { target=s->pc; goto dispatch; }
goto P_0c0c528e;
P_0c0c528c: /* original 34fc, guest PC 0x0c0c528c */
if(!s->budget--) { s->failed_pc=0x0c0c528cu; return 0; }
r[4]+=r[15];
goto P_0c0c528e;
P_0c0c528e: /* original e050, guest PC 0x0c0c528e */
if(!s->budget--) { s->failed_pc=0x0c0c528eu; return 0; }
r[0]=0x00000050u;
goto P_0c0c5290;
P_0c0c5290: /* original 03fe, guest PC 0x0c0c5290 */
if(!s->budget--) { s->failed_pc=0x0c0c5290u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c5292;
P_0c0c5292: /* original e04c, guest PC 0x0c0c5292 */
if(!s->budget--) { s->failed_pc=0x0c0c5292u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c5294;
P_0c0c5294: /* original 02fe, guest PC 0x0c0c5294 */
if(!s->budget--) { s->failed_pc=0x0c0c5294u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0c5296;
P_0c0c5296: /* original e130, guest PC 0x0c0c5296 */
if(!s->budget--) { s->failed_pc=0x0c0c5296u; return 0; }
r[1]=0x00000030u;
goto P_0c0c5298;
P_0c0c5298: /* original 323c, guest PC 0x0c0c5298 */
if(!s->budget--) { s->failed_pc=0x0c0c5298u; return 0; }
r[2]+=r[3];
goto P_0c0c529a;
P_0c0c529a: /* original 3213, guest PC 0x0c0c529a */
if(!s->budget--) { s->failed_pc=0x0c0c529au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0c529c;
P_0c0c529c: /* original 2f22, guest PC 0x0c0c529c */
if(!s->budget--) { s->failed_pc=0x0c0c529cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c529e;
P_0c0c529e: /* original 8939, guest PC 0x0c0c529e */
if(!s->budget--) { s->failed_pc=0x0c0c529eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5314; }
goto P_0c0c52a0;
P_0c0c52a0: /* original 4211, guest PC 0x0c0c52a0 */
if(!s->budget--) { s->failed_pc=0x0c0c52a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c52a2;
P_0c0c52a2: /* original 8d01, guest PC 0x0c0c52a2 */
if(!s->budget--) { s->failed_pc=0x0c0c52a2u; return 0; }
cond=r[17]&1u;
r[4]=r[9];
if(cond) { goto P_0c0c52a8; }
goto P_0c0c52a6;
P_0c0c52a4: /* original 6493, guest PC 0x0c0c52a4 */
if(!s->budget--) { s->failed_pc=0x0c0c52a4u; return 0; }
r[4]=r[9];
goto P_0c0c52a6;
P_0c0c52a6: /* original 2fc2, guest PC 0x0c0c52a6 */
if(!s->budget--) { s->failed_pc=0x0c0c52a6u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0c52a8;
P_0c0c52a8: /* original 4b0b, guest PC 0x0c0c52a8 */
if(!s->budget--) { s->failed_pc=0x0c0c52a8u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c52acu;
r[4]+=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c52acu) { target=s->pc; goto dispatch; }
goto P_0c0c52ac;
P_0c0c52aa: /* original 7402, guest PC 0x0c0c52aa */
if(!s->budget--) { s->failed_pc=0x0c0c52aau; return 0; }
r[4]+=0x00000002u;
goto P_0c0c52ac;
P_0c0c52ac: /* original 63f2, guest PC 0x0c0c52ac */
if(!s->budget--) { s->failed_pc=0x0c0c52acu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c52ae;
P_0c0c52ae: /* original e231, guest PC 0x0c0c52ae */
if(!s->budget--) { s->failed_pc=0x0c0c52aeu; return 0; }
r[2]=0x00000031u;
goto P_0c0c52b0;
P_0c0c52b0: /* original 6a03, guest PC 0x0c0c52b0 */
if(!s->budget--) { s->failed_pc=0x0c0c52b0u; return 0; }
r[10]=r[0];
goto P_0c0c52b2;
P_0c0c52b2: /* original e01c, guest PC 0x0c0c52b2 */
if(!s->budget--) { s->failed_pc=0x0c0c52b2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c52b4;
P_0c0c52b4: /* original 3238, guest PC 0x0c0c52b4 */
if(!s->budget--) { s->failed_pc=0x0c0c52b4u; return 0; }
r[2]-=r[3];
goto P_0c0c52b6;
P_0c0c52b6: /* original f7a6, guest PC 0x0c0c52b6 */
if(!s->budget--) { s->failed_pc=0x0c0c52b6u; return 0; }
vf3_matrix_load(s,ram,7,r[10]+r[0]);
goto P_0c0c52b8;
P_0c0c52b8: /* original 425a, guest PC 0x0c0c52b8 */
if(!s->budget--) { s->failed_pc=0x0c0c52b8u; return 0; }
r[53]=r[2];
goto P_0c0c52ba;
P_0c0c52ba: /* original c734, guest PC 0x0c0c52ba */
if(!s->budget--) { s->failed_pc=0x0c0c52bau; return 0; }
r[0]=code_base|0x000c538cu;
goto P_0c0c52bc;
P_0c0c52bc: /* original 52f6, guest PC 0x0c0c52bc */
if(!s->budget--) { s->failed_pc=0x0c0c52bcu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0c52be;
P_0c0c52be: /* original 945e, guest PC 0x0c0c52be */
if(!s->budget--) { s->failed_pc=0x0c0c52beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c52c0;
P_0c0c52c0: /* original f32d, guest PC 0x0c0c52c0 */
if(!s->budget--) { s->failed_pc=0x0c0c52c0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c52c2;
P_0c0c52c2: /* original 435a, guest PC 0x0c0c52c2 */
if(!s->budget--) { s->failed_pc=0x0c0c52c2u; return 0; }
r[53]=r[3];
goto P_0c0c52c4;
P_0c0c52c4: /* original d333, guest PC 0x0c0c52c4 */
if(!s->budget--) { s->failed_pc=0x0c0c52c4u; return 0; }
r[3]=read(ram,0x0c0c5394u,4);
goto P_0c0c52c6;
P_0c0c52c6: /* original f4fc, guest PC 0x0c0c52c6 */
if(!s->budget--) { s->failed_pc=0x0c0c52c6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c52c8;
P_0c0c52c8: /* original f22d, guest PC 0x0c0c52c8 */
if(!s->budget--) { s->failed_pc=0x0c0c52c8u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c52ca;
P_0c0c52ca: /* original f732, guest PC 0x0c0c52ca */
if(!s->budget--) { s->failed_pc=0x0c0c52cau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0c52cc;
P_0c0c52cc: /* original f308, guest PC 0x0c0c52cc */
if(!s->budget--) { s->failed_pc=0x0c0c52ccu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c52ce;
P_0c0c52ce: /* original d030, guest PC 0x0c0c52ce */
if(!s->budget--) { s->failed_pc=0x0c0c52ceu; return 0; }
r[0]=read(ram,0x0c0c5390u,4);
goto P_0c0c52d0;
P_0c0c52d0: /* original f826, guest PC 0x0c0c52d0 */
if(!s->budget--) { s->failed_pc=0x0c0c52d0u; return 0; }
vf3_matrix_load(s,ram,8,r[2]+r[0]);
goto P_0c0c52d2;
P_0c0c52d2: /* original e018, guest PC 0x0c0c52d2 */
if(!s->budget--) { s->failed_pc=0x0c0c52d2u; return 0; }
r[0]=0x00000018u;
goto P_0c0c52d4;
P_0c0c52d4: /* original f6a6, guest PC 0x0c0c52d4 */
if(!s->budget--) { s->failed_pc=0x0c0c52d4u; return 0; }
vf3_matrix_load(s,ram,6,r[10]+r[0]);
goto P_0c0c52d6;
P_0c0c52d6: /* original c731, guest PC 0x0c0c52d6 */
if(!s->budget--) { s->failed_pc=0x0c0c52d6u; return 0; }
r[0]=code_base|0x000c539cu;
goto P_0c0c52d8;
P_0c0c52d8: /* original f108, guest PC 0x0c0c52d8 */
if(!s->budget--) { s->failed_pc=0x0c0c52d8u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c52da;
P_0c0c52da: /* original f830, guest PC 0x0c0c52da */
if(!s->budget--) { s->failed_pc=0x0c0c52dau; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'+');
goto P_0c0c52dc;
P_0c0c52dc: /* original f52c, guest PC 0x0c0c52dc */
if(!s->budget--) { s->failed_pc=0x0c0c52dcu; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0c52de;
P_0c0c52de: /* original f512, guest PC 0x0c0c52de */
if(!s->budget--) { s->failed_pc=0x0c0c52deu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'*');
goto P_0c0c52e0;
P_0c0c52e0: /* original 430b, guest PC 0x0c0c52e0 */
if(!s->budget--) { s->failed_pc=0x0c0c52e0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c52e4u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c52e4u) { target=s->pc; goto dispatch; }
goto P_0c0c52e4;
P_0c0c52e2: /* original 34fc, guest PC 0x0c0c52e2 */
if(!s->budget--) { s->failed_pc=0x0c0c52e2u; return 0; }
r[4]+=r[15];
goto P_0c0c52e4;
P_0c0c52e4: /* original e014, guest PC 0x0c0c52e4 */
if(!s->budget--) { s->failed_pc=0x0c0c52e4u; return 0; }
r[0]=0x00000014u;
goto P_0c0c52e6;
P_0c0c52e6: /* original 944a, guest PC 0x0c0c52e6 */
if(!s->budget--) { s->failed_pc=0x0c0c52e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c52e8;
P_0c0c52e8: /* original f9a6, guest PC 0x0c0c52e8 */
if(!s->budget--) { s->failed_pc=0x0c0c52e8u; return 0; }
vf3_matrix_load(s,ram,9,r[10]+r[0]);
goto P_0c0c52ea;
P_0c0c52ea: /* original e010, guest PC 0x0c0c52ea */
if(!s->budget--) { s->failed_pc=0x0c0c52eau; return 0; }
r[0]=0x00000010u;
goto P_0c0c52ec;
P_0c0c52ec: /* original f8a6, guest PC 0x0c0c52ec */
if(!s->budget--) { s->failed_pc=0x0c0c52ecu; return 0; }
vf3_matrix_load(s,ram,8,r[10]+r[0]);
goto P_0c0c52ee;
P_0c0c52ee: /* original e00c, guest PC 0x0c0c52ee */
if(!s->budget--) { s->failed_pc=0x0c0c52eeu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c52f0;
P_0c0c52f0: /* original f7a6, guest PC 0x0c0c52f0 */
if(!s->budget--) { s->failed_pc=0x0c0c52f0u; return 0; }
vf3_matrix_load(s,ram,7,r[10]+r[0]);
goto P_0c0c52f2;
P_0c0c52f2: /* original e008, guest PC 0x0c0c52f2 */
if(!s->budget--) { s->failed_pc=0x0c0c52f2u; return 0; }
r[0]=0x00000008u;
goto P_0c0c52f4;
P_0c0c52f4: /* original f6a6, guest PC 0x0c0c52f4 */
if(!s->budget--) { s->failed_pc=0x0c0c52f4u; return 0; }
vf3_matrix_load(s,ram,6,r[10]+r[0]);
goto P_0c0c52f6;
P_0c0c52f6: /* original e004, guest PC 0x0c0c52f6 */
if(!s->budget--) { s->failed_pc=0x0c0c52f6u; return 0; }
r[0]=0x00000004u;
goto P_0c0c52f8;
P_0c0c52f8: /* original f4a8, guest PC 0x0c0c52f8 */
if(!s->budget--) { s->failed_pc=0x0c0c52f8u; return 0; }
vf3_matrix_load(s,ram,4,r[10]);
goto P_0c0c52fa;
P_0c0c52fa: /* original f5a6, guest PC 0x0c0c52fa */
if(!s->budget--) { s->failed_pc=0x0c0c52fau; return 0; }
vf3_matrix_load(s,ram,5,r[10]+r[0]);
goto P_0c0c52fc;
P_0c0c52fc: /* original 480b, guest PC 0x0c0c52fc */
if(!s->budget--) { s->failed_pc=0x0c0c52fcu; return 0; }
target=r[8];
r[16]=code_base|0x0c0c5300u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5300u) { target=s->pc; goto dispatch; }
goto P_0c0c5300;
P_0c0c52fe: /* original 34fc, guest PC 0x0c0c52fe */
if(!s->budget--) { s->failed_pc=0x0c0c52feu; return 0; }
r[4]+=r[15];
goto P_0c0c5300;
P_0c0c5300: /* original 53e8, guest PC 0x0c0c5300 */
if(!s->budget--) { s->failed_pc=0x0c0c5300u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c5302;
P_0c0c5302: /* original d025, guest PC 0x0c0c5302 */
if(!s->budget--) { s->failed_pc=0x0c0c5302u; return 0; }
r[0]=read(ram,0x0c0c5398u,4);
goto P_0c0c5304;
P_0c0c5304: /* original 4300, guest PC 0x0c0c5304 */
if(!s->budget--) { s->failed_pc=0x0c0c5304u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c5306;
P_0c0c5306: /* original 023d, guest PC 0x0c0c5306 */
if(!s->budget--) { s->failed_pc=0x0c0c5306u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c5308;
P_0c0c5308: /* original 9039, guest PC 0x0c0c5308 */
if(!s->budget--) { s->failed_pc=0x0c0c5308u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c530a;
P_0c0c530a: /* original 622d, guest PC 0x0c0c530a */
if(!s->budget--) { s->failed_pc=0x0c0c530au; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c530c;
P_0c0c530c: /* original 0f26, guest PC 0x0c0c530c */
if(!s->budget--) { s->failed_pc=0x0c0c530cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c530e;
P_0c0c530e: /* original 9436, guest PC 0x0c0c530e */
if(!s->budget--) { s->failed_pc=0x0c0c530eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c5310;
P_0c0c5310: /* original 4d0b, guest PC 0x0c0c5310 */
if(!s->budget--) { s->failed_pc=0x0c0c5310u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c5314u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5314u) { target=s->pc; goto dispatch; }
goto P_0c0c5314;
P_0c0c5312: /* original 34fc, guest PC 0x0c0c5312 */
if(!s->budget--) { s->failed_pc=0x0c0c5312u; return 0; }
r[4]+=r[15];
goto P_0c0c5314;
P_0c0c5314: /* original d223, guest PC 0x0c0c5314 */
if(!s->budget--) { s->failed_pc=0x0c0c5314u; return 0; }
r[2]=read(ram,0x0c0c53a4u,4);
goto P_0c0c5316;
P_0c0c5316: /* original d022, guest PC 0x0c0c5316 */
if(!s->budget--) { s->failed_pc=0x0c0c5316u; return 0; }
r[0]=read(ram,0x0c0c53a0u,4);
goto P_0c0c5318;
P_0c0c5318: /* original 6320, guest PC 0x0c0c5318 */
if(!s->budget--) { s->failed_pc=0x0c0c5318u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0c531a;
P_0c0c531a: /* original 9132, guest PC 0x0c0c531a */
if(!s->budget--) { s->failed_pc=0x0c0c531au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5382u,2);
goto P_0c0c531c;
P_0c0c531c: /* original 633c, guest PC 0x0c0c531c */
if(!s->budget--) { s->failed_pc=0x0c0c531cu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c531e;
P_0c0c531e: /* original 4308, guest PC 0x0c0c531e */
if(!s->budget--) { s->failed_pc=0x0c0c531eu; return 0; }
r[3]<<=2;
goto P_0c0c5320;
P_0c0c5320: /* original 033e, guest PC 0x0c0c5320 */
if(!s->budget--) { s->failed_pc=0x0c0c5320u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c0c5322;
P_0c0c5322: /* original 902f, guest PC 0x0c0c5322 */
if(!s->budget--) { s->failed_pc=0x0c0c5322u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5384u,2);
goto P_0c0c5324;
P_0c0c5324: /* original 231b, guest PC 0x0c0c5324 */
if(!s->budget--) { s->failed_pc=0x0c0c5324u; return 0; }
r[3]|=r[1];
goto P_0c0c5326;
P_0c0c5326: /* original 0f36, guest PC 0x0c0c5326 */
if(!s->budget--) { s->failed_pc=0x0c0c5326u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c5328;
P_0c0c5328: /* original 4b0b, guest PC 0x0c0c5328 */
if(!s->budget--) { s->failed_pc=0x0c0c5328u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c532cu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c532cu) { target=s->pc; goto dispatch; }
goto P_0c0c532c;
P_0c0c532a: /* original 6493, guest PC 0x0c0c532a */
if(!s->budget--) { s->failed_pc=0x0c0c532au; return 0; }
r[4]=r[9];
goto P_0c0c532c;
P_0c0c532c: /* original 6e03, guest PC 0x0c0c532c */
if(!s->budget--) { s->failed_pc=0x0c0c532cu; return 0; }
r[14]=r[0];
goto P_0c0c532e;
P_0c0c532e: /* original e048, guest PC 0x0c0c532e */
if(!s->budget--) { s->failed_pc=0x0c0c532eu; return 0; }
r[0]=0x00000048u;
goto P_0c0c5330;
P_0c0c5330: /* original 00fe, guest PC 0x0c0c5330 */
if(!s->budget--) { s->failed_pc=0x0c0c5330u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0c5332;
P_0c0c5332: /* original d31d, guest PC 0x0c0c5332 */
if(!s->budget--) { s->failed_pc=0x0c0c5332u; return 0; }
r[3]=read(ram,0x0c0c53a8u,4);
goto P_0c0c5334;
P_0c0c5334: /* original 4008, guest PC 0x0c0c5334 */
if(!s->budget--) { s->failed_pc=0x0c0c5334u; return 0; }
r[0]<<=2;
goto P_0c0c5336;
P_0c0c5336: /* original 4000, guest PC 0x0c0c5336 */
if(!s->budget--) { s->failed_pc=0x0c0c5336u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c5338;
P_0c0c5338: /* original 430b, guest PC 0x0c0c5338 */
if(!s->budget--) { s->failed_pc=0x0c0c5338u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c533cu;
r[1]=read(ram,r[15]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c533cu) { target=s->pc; goto dispatch; }
goto P_0c0c533c;
P_0c0c533a: /* original 51ff, guest PC 0x0c0c533a */
if(!s->budget--) { s->failed_pc=0x0c0c533au; return 0; }
r[1]=read(ram,r[15]+60,4);
goto P_0c0c533c;
P_0c0c533c: /* original 650b, guest PC 0x0c0c533c */
if(!s->budget--) { s->failed_pc=0x0c0c533cu; return 0; }
r[5]=0u-r[0];
goto P_0c0c533e;
P_0c0c533e: /* original 53fc, guest PC 0x0c0c533e */
if(!s->budget--) { s->failed_pc=0x0c0c533eu; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c0c5340;
P_0c0c5340: /* original 455a, guest PC 0x0c0c5340 */
if(!s->budget--) { s->failed_pc=0x0c0c5340u; return 0; }
r[53]=r[5];
goto P_0c0c5342;
P_0c0c5342: /* original d013, guest PC 0x0c0c5342 */
if(!s->budget--) { s->failed_pc=0x0c0c5342u; return 0; }
r[0]=read(ram,0x0c0c5390u,4);
goto P_0c0c5344;
P_0c0c5344: /* original 941b, guest PC 0x0c0c5344 */
if(!s->budget--) { s->failed_pc=0x0c0c5344u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c5346;
P_0c0c5346: /* original f32d, guest PC 0x0c0c5346 */
if(!s->budget--) { s->failed_pc=0x0c0c5346u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c5348;
P_0c0c5348: /* original 435a, guest PC 0x0c0c5348 */
if(!s->budget--) { s->failed_pc=0x0c0c5348u; return 0; }
r[53]=r[3];
goto P_0c0c534a;
P_0c0c534a: /* original 53f6, guest PC 0x0c0c534a */
if(!s->budget--) { s->failed_pc=0x0c0c534au; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c534c;
P_0c0c534c: /* original f836, guest PC 0x0c0c534c */
if(!s->budget--) { s->failed_pc=0x0c0c534cu; return 0; }
vf3_matrix_load(s,ram,8,r[3]+r[0]);
goto P_0c0c534e;
P_0c0c534e: /* original e01c, guest PC 0x0c0c534e */
if(!s->budget--) { s->failed_pc=0x0c0c534eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5350;
P_0c0c5350: /* original f7e6, guest PC 0x0c0c5350 */
if(!s->budget--) { s->failed_pc=0x0c0c5350u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c5352;
P_0c0c5352: /* original e018, guest PC 0x0c0c5352 */
if(!s->budget--) { s->failed_pc=0x0c0c5352u; return 0; }
r[0]=0x00000018u;
goto P_0c0c5354;
P_0c0c5354: /* original fe3c, guest PC 0x0c0c5354 */
if(!s->budget--) { s->failed_pc=0x0c0c5354u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0c5356;
P_0c0c5356: /* original f32d, guest PC 0x0c0c5356 */
if(!s->budget--) { s->failed_pc=0x0c0c5356u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c5358;
P_0c0c5358: /* original f6e6, guest PC 0x0c0c5358 */
if(!s->budget--) { s->failed_pc=0x0c0c5358u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c535a;
P_0c0c535a: /* original d30e, guest PC 0x0c0c535a */
if(!s->budget--) { s->failed_pc=0x0c0c535au; return 0; }
r[3]=read(ram,0x0c0c5394u,4);
goto P_0c0c535c;
P_0c0c535c: /* original f4ec, guest PC 0x0c0c535c */
if(!s->budget--) { s->failed_pc=0x0c0c535cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c535e;
P_0c0c535e: /* original fd3c, guest PC 0x0c0c535e */
if(!s->budget--) { s->failed_pc=0x0c0c535eu; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c0c5360;
P_0c0c5360: /* original f53c, guest PC 0x0c0c5360 */
if(!s->budget--) { s->failed_pc=0x0c0c5360u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c5362;
P_0c0c5362: /* original 430b, guest PC 0x0c0c5362 */
if(!s->budget--) { s->failed_pc=0x0c0c5362u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5366u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5366u) { target=s->pc; goto dispatch; }
goto P_0c0c5366;
P_0c0c5364: /* original 34fc, guest PC 0x0c0c5364 */
if(!s->budget--) { s->failed_pc=0x0c0c5364u; return 0; }
r[4]+=r[15];
goto P_0c0c5366;
P_0c0c5366: /* original e014, guest PC 0x0c0c5366 */
if(!s->budget--) { s->failed_pc=0x0c0c5366u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5368;
P_0c0c5368: /* original f39d, guest PC 0x0c0c5368 */
if(!s->budget--) { s->failed_pc=0x0c0c5368u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c536a;
P_0c0c536a: /* original f9e6, guest PC 0x0c0c536a */
if(!s->budget--) { s->failed_pc=0x0c0c536au; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c536c;
P_0c0c536c: /* original e010, guest PC 0x0c0c536c */
if(!s->budget--) { s->failed_pc=0x0c0c536cu; return 0; }
r[0]=0x00000010u;
goto P_0c0c536e;
P_0c0c536e: /* original f8e6, guest PC 0x0c0c536e */
if(!s->budget--) { s->failed_pc=0x0c0c536eu; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c5370;
P_0c0c5370: /* original e00c, guest PC 0x0c0c5370 */
if(!s->budget--) { s->failed_pc=0x0c0c5370u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5372;
P_0c0c5372: /* original f7e6, guest PC 0x0c0c5372 */
if(!s->budget--) { s->failed_pc=0x0c0c5372u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c5374;
P_0c0c5374: /* original e008, guest PC 0x0c0c5374 */
if(!s->budget--) { s->failed_pc=0x0c0c5374u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5376;
P_0c0c5376: /* original f6e6, guest PC 0x0c0c5376 */
if(!s->budget--) { s->failed_pc=0x0c0c5376u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c5378;
P_0c0c5378: /* original f630, guest PC 0x0c0c5378 */
if(!s->budget--) { s->failed_pc=0x0c0c5378u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0c537a;
P_0c0c537a: /* original a017, guest PC 0x0c0c537a */
if(!s->budget--) { s->failed_pc=0x0c0c537au; return 0; }
goto P_0c0c53ac;
P_0c0c537c: /* original 0009, guest PC 0x0c0c537c */
if(!s->budget--) { s->failed_pc=0x0c0c537cu; return 0; }
if(!vf3_matrix_family(0x0c0c537eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c537eu; return 0; } return 1;
P_0c0c53ac: /* original e004, guest PC 0x0c0c53ac */
if(!s->budget--) { s->failed_pc=0x0c0c53acu; return 0; }
r[0]=0x00000004u;
goto P_0c0c53ae;
P_0c0c53ae: /* original 94b5, guest PC 0x0c0c53ae */
if(!s->budget--) { s->failed_pc=0x0c0c53aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c53b0;
P_0c0c53b0: /* original f4e8, guest PC 0x0c0c53b0 */
if(!s->budget--) { s->failed_pc=0x0c0c53b0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c53b2;
P_0c0c53b2: /* original f5e6, guest PC 0x0c0c53b2 */
if(!s->budget--) { s->failed_pc=0x0c0c53b2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c53b4;
P_0c0c53b4: /* original 480b, guest PC 0x0c0c53b4 */
if(!s->budget--) { s->failed_pc=0x0c0c53b4u; return 0; }
target=r[8];
r[16]=code_base|0x0c0c53b8u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c53b8u) { target=s->pc; goto dispatch; }
goto P_0c0c53b8;
P_0c0c53b6: /* original 34fc, guest PC 0x0c0c53b6 */
if(!s->budget--) { s->failed_pc=0x0c0c53b6u; return 0; }
r[4]+=r[15];
goto P_0c0c53b8;
P_0c0c53b8: /* original e008, guest PC 0x0c0c53b8 */
if(!s->budget--) { s->failed_pc=0x0c0c53b8u; return 0; }
r[0]=0x00000008u;
goto P_0c0c53ba;
P_0c0c53ba: /* original f39d, guest PC 0x0c0c53ba */
if(!s->budget--) { s->failed_pc=0x0c0c53bau; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c53bc;
P_0c0c53bc: /* original f2e6, guest PC 0x0c0c53bc */
if(!s->budget--) { s->failed_pc=0x0c0c53bcu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c53be;
P_0c0c53be: /* original f231, guest PC 0x0c0c53be */
if(!s->budget--) { s->failed_pc=0x0c0c53beu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c53c0;
P_0c0c53c0: /* original fe27, guest PC 0x0c0c53c0 */
if(!s->budget--) { s->failed_pc=0x0c0c53c0u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c53c2;
P_0c0c53c2: /* original 53e8, guest PC 0x0c0c53c2 */
if(!s->budget--) { s->failed_pc=0x0c0c53c2u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c53c4;
P_0c0c53c4: /* original d05a, guest PC 0x0c0c53c4 */
if(!s->budget--) { s->failed_pc=0x0c0c53c4u; return 0; }
r[0]=read(ram,0x0c0c5530u,4);
goto P_0c0c53c6;
P_0c0c53c6: /* original 4300, guest PC 0x0c0c53c6 */
if(!s->budget--) { s->failed_pc=0x0c0c53c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c53c8;
P_0c0c53c8: /* original 023d, guest PC 0x0c0c53c8 */
if(!s->budget--) { s->failed_pc=0x0c0c53c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c53ca;
P_0c0c53ca: /* original 90a7, guest PC 0x0c0c53ca */
if(!s->budget--) { s->failed_pc=0x0c0c53cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c53cc;
P_0c0c53cc: /* original 622d, guest PC 0x0c0c53cc */
if(!s->budget--) { s->failed_pc=0x0c0c53ccu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c53ce;
P_0c0c53ce: /* original 0f26, guest PC 0x0c0c53ce */
if(!s->budget--) { s->failed_pc=0x0c0c53ceu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c53d0;
P_0c0c53d0: /* original d359, guest PC 0x0c0c53d0 */
if(!s->budget--) { s->failed_pc=0x0c0c53d0u; return 0; }
r[3]=read(ram,0x0c0c5538u,4);
goto P_0c0c53d2;
P_0c0c53d2: /* original da58, guest PC 0x0c0c53d2 */
if(!s->budget--) { s->failed_pc=0x0c0c53d2u; return 0; }
r[10]=read(ram,0x0c0c5534u,4);
goto P_0c0c53d4;
P_0c0c53d4: /* original 6030, guest PC 0x0c0c53d4 */
if(!s->budget--) { s->failed_pc=0x0c0c53d4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0c53d6;
P_0c0c53d6: /* original 94a2, guest PC 0x0c0c53d6 */
if(!s->budget--) { s->failed_pc=0x0c0c53d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551eu,2);
goto P_0c0c53d8;
P_0c0c53d8: /* original 600c, guest PC 0x0c0c53d8 */
if(!s->budget--) { s->failed_pc=0x0c0c53d8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c53da;
P_0c0c53da: /* original c90f, guest PC 0x0c0c53da */
if(!s->budget--) { s->failed_pc=0x0c0c53dau; return 0; }
r[0]&=15u;
goto P_0c0c53dc;
P_0c0c53dc: /* original 880d, guest PC 0x0c0c53dc */
if(!s->budget--) { s->failed_pc=0x0c0c53dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0c53de;
P_0c0c53de: /* original 8b01, guest PC 0x0c0c53de */
if(!s->budget--) { s->failed_pc=0x0c0c53deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c53e4; }
goto P_0c0c53e0;
P_0c0c53e0: /* original a110, guest PC 0x0c0c53e0 */
if(!s->budget--) { s->failed_pc=0x0c0c53e0u; return 0; }
goto P_0c0c5604;
P_0c0c53e2: /* original 0009, guest PC 0x0c0c53e2 */
if(!s->budget--) { s->failed_pc=0x0c0c53e2u; return 0; }
goto P_0c0c53e4;
P_0c0c53e4: /* original 50e8, guest PC 0x0c0c53e4 */
if(!s->budget--) { s->failed_pc=0x0c0c53e4u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c0c53e6;
P_0c0c53e6: /* original 882c, guest PC 0x0c0c53e6 */
if(!s->budget--) { s->failed_pc=0x0c0c53e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c0c53e8;
P_0c0c53e8: /* original 8d05, guest PC 0x0c0c53e8 */
if(!s->budget--) { s->failed_pc=0x0c0c53e8u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c0c53f6; }
goto P_0c0c53ec;
P_0c0c53ea: /* original 6503, guest PC 0x0c0c53ea */
if(!s->budget--) { s->failed_pc=0x0c0c53eau; return 0; }
r[5]=r[0];
goto P_0c0c53ec;
P_0c0c53ec: /* original 6053, guest PC 0x0c0c53ec */
if(!s->budget--) { s->failed_pc=0x0c0c53ecu; return 0; }
r[0]=r[5];
goto P_0c0c53ee;
P_0c0c53ee: /* original 8834, guest PC 0x0c0c53ee */
if(!s->budget--) { s->failed_pc=0x0c0c53eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c0c53f0;
P_0c0c53f0: /* original 8901, guest PC 0x0c0c53f0 */
if(!s->budget--) { s->failed_pc=0x0c0c53f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c53f6; }
goto P_0c0c53f2;
P_0c0c53f2: /* original a0d4, guest PC 0x0c0c53f2 */
if(!s->budget--) { s->failed_pc=0x0c0c53f2u; return 0; }
goto P_0c0c559e;
P_0c0c53f4: /* original 0009, guest PC 0x0c0c53f4 */
if(!s->budget--) { s->failed_pc=0x0c0c53f4u; return 0; }
goto P_0c0c53f6;
P_0c0c53f6: /* original 9093, guest PC 0x0c0c53f6 */
if(!s->budget--) { s->failed_pc=0x0c0c53f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5520u,2);
goto P_0c0c53f8;
P_0c0c53f8: /* original 03fe, guest PC 0x0c0c53f8 */
if(!s->budget--) { s->failed_pc=0x0c0c53f8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c53fa;
P_0c0c53fa: /* original 9091, guest PC 0x0c0c53fa */
if(!s->budget--) { s->failed_pc=0x0c0c53fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5520u,2);
goto P_0c0c53fc;
P_0c0c53fc: /* original 2349, guest PC 0x0c0c53fc */
if(!s->budget--) { s->failed_pc=0x0c0c53fcu; return 0; }
r[3]&=r[4];
goto P_0c0c53fe;
P_0c0c53fe: /* original 0f36, guest PC 0x0c0c53fe */
if(!s->budget--) { s->failed_pc=0x0c0c53feu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c5400;
P_0c0c5400: /* original e008, guest PC 0x0c0c5400 */
if(!s->budget--) { s->failed_pc=0x0c0c5400u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5402;
P_0c0c5402: /* original fde6, guest PC 0x0c0c5402 */
if(!s->budget--) { s->failed_pc=0x0c0c5402u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0c5404;
P_0c0c5404: /* original e014, guest PC 0x0c0c5404 */
if(!s->budget--) { s->failed_pc=0x0c0c5404u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5406;
P_0c0c5406: /* original 9489, guest PC 0x0c0c5406 */
if(!s->budget--) { s->failed_pc=0x0c0c5406u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c5408;
P_0c0c5408: /* original fee6, guest PC 0x0c0c5408 */
if(!s->budget--) { s->failed_pc=0x0c0c5408u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0c540a;
P_0c0c540a: /* original 4d0b, guest PC 0x0c0c540a */
if(!s->budget--) { s->failed_pc=0x0c0c540au; return 0; }
target=r[13];
r[16]=code_base|0x0c0c540eu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c540eu) { target=s->pc; goto dispatch; }
goto P_0c0c540e;
P_0c0c540c: /* original 34fc, guest PC 0x0c0c540c */
if(!s->budget--) { s->failed_pc=0x0c0c540cu; return 0; }
r[4]+=r[15];
goto P_0c0c540e;
P_0c0c540e: /* original 9285, guest PC 0x0c0c540e */
if(!s->budget--) { s->failed_pc=0x0c0c540eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c5410;
P_0c0c5410: /* original 9187, guest PC 0x0c0c5410 */
if(!s->budget--) { s->failed_pc=0x0c0c5410u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5522u,2);
goto P_0c0c5412;
P_0c0c5412: /* original d34a, guest PC 0x0c0c5412 */
if(!s->budget--) { s->failed_pc=0x0c0c5412u; return 0; }
r[3]=read(ram,0x0c0c553cu,4);
goto P_0c0c5414;
P_0c0c5414: /* original 32fc, guest PC 0x0c0c5414 */
if(!s->budget--) { s->failed_pc=0x0c0c5414u; return 0; }
r[2]+=r[15];
goto P_0c0c5416;
P_0c0c5416: /* original 31fc, guest PC 0x0c0c5416 */
if(!s->budget--) { s->failed_pc=0x0c0c5416u; return 0; }
r[1]+=r[15];
goto P_0c0c5418;
P_0c0c5418: /* original 430b, guest PC 0x0c0c5418 */
if(!s->budget--) { s->failed_pc=0x0c0c5418u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c541cu;
r[0]=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c541cu) { target=s->pc; goto dispatch; }
goto P_0c0c541c;
P_0c0c541a: /* original e034, guest PC 0x0c0c541a */
if(!s->budget--) { s->failed_pc=0x0c0c541au; return 0; }
r[0]=0x00000034u;
goto P_0c0c541c;
P_0c0c541c: /* original 9082, guest PC 0x0c0c541c */
if(!s->budget--) { s->failed_pc=0x0c0c541cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c541e;
P_0c0c541e: /* original f2a8, guest PC 0x0c0c541e */
if(!s->budget--) { s->failed_pc=0x0c0c541eu; return 0; }
vf3_matrix_load(s,ram,2,r[10]);
goto P_0c0c5420;
P_0c0c5420: /* original f3f6, guest PC 0x0c0c5420 */
if(!s->budget--) { s->failed_pc=0x0c0c5420u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5422;
P_0c0c5422: /* original f0dc, guest PC 0x0c0c5422 */
if(!s->budget--) { s->failed_pc=0x0c0c5422u; return 0; }
vf3_matrix_move(s,0,13);
goto P_0c0c5424;
P_0c0c5424: /* original f32e, guest PC 0x0c0c5424 */
if(!s->budget--) { s->failed_pc=0x0c0c5424u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0c5426;
P_0c0c5426: /* original 907d, guest PC 0x0c0c5426 */
if(!s->budget--) { s->failed_pc=0x0c0c5426u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c5428;
P_0c0c5428: /* original ff37, guest PC 0x0c0c5428 */
if(!s->budget--) { s->failed_pc=0x0c0c5428u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c542a;
P_0c0c542a: /* original c745, guest PC 0x0c0c542a */
if(!s->budget--) { s->failed_pc=0x0c0c542au; return 0; }
r[0]=code_base|0x000c5540u;
goto P_0c0c542c;
P_0c0c542c: /* original ff08, guest PC 0x0c0c542c */
if(!s->budget--) { s->failed_pc=0x0c0c542cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c542e;
P_0c0c542e: /* original f3f5, guest PC 0x0c0c542e */
if(!s->budget--) { s->failed_pc=0x0c0c542eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c5430;
P_0c0c5430: /* original 8b01, guest PC 0x0c0c5430 */
if(!s->budget--) { s->failed_pc=0x0c0c5430u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5436; }
goto P_0c0c5432;
P_0c0c5432: /* original a302, guest PC 0x0c0c5432 */
if(!s->budget--) { s->failed_pc=0x0c0c5432u; return 0; }
goto P_0c0c5a3a;
P_0c0c5434: /* original 0009, guest PC 0x0c0c5434 */
if(!s->budget--) { s->failed_pc=0x0c0c5434u; return 0; }
goto P_0c0c5436;
P_0c0c5436: /* original c743, guest PC 0x0c0c5436 */
if(!s->budget--) { s->failed_pc=0x0c0c5436u; return 0; }
r[0]=code_base|0x000c5544u;
goto P_0c0c5438;
P_0c0c5438: /* original f2ec, guest PC 0x0c0c5438 */
if(!s->budget--) { s->failed_pc=0x0c0c5438u; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0c543a;
P_0c0c543a: /* original f308, guest PC 0x0c0c543a */
if(!s->budget--) { s->failed_pc=0x0c0c543au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c543c;
P_0c0c543c: /* original 9073, guest PC 0x0c0c543c */
if(!s->budget--) { s->failed_pc=0x0c0c543cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5526u,2);
goto P_0c0c543e;
P_0c0c543e: /* original f232, guest PC 0x0c0c543e */
if(!s->budget--) { s->failed_pc=0x0c0c543eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c5440;
P_0c0c5440: /* original ff27, guest PC 0x0c0c5440 */
if(!s->budget--) { s->failed_pc=0x0c0c5440u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5442;
P_0c0c5442: /* original c741, guest PC 0x0c0c5442 */
if(!s->budget--) { s->failed_pc=0x0c0c5442u; return 0; }
r[0]=code_base|0x000c5548u;
goto P_0c0c5444;
P_0c0c5444: /* original f208, guest PC 0x0c0c5444 */
if(!s->budget--) { s->failed_pc=0x0c0c5444u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c5446;
P_0c0c5446: /* original e038, guest PC 0x0c0c5446 */
if(!s->budget--) { s->failed_pc=0x0c0c5446u; return 0; }
r[0]=0x00000038u;
goto P_0c0c5448;
P_0c0c5448: /* original f1ec, guest PC 0x0c0c5448 */
if(!s->budget--) { s->failed_pc=0x0c0c5448u; return 0; }
vf3_matrix_move(s,1,14);
goto P_0c0c544a;
P_0c0c544a: /* original f122, guest PC 0x0c0c544a */
if(!s->budget--) { s->failed_pc=0x0c0c544au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0c544c;
P_0c0c544c: /* original ff17, guest PC 0x0c0c544c */
if(!s->budget--) { s->failed_pc=0x0c0c544cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c544e;
P_0c0c544e: /* original 906b, guest PC 0x0c0c544e */
if(!s->budget--) { s->failed_pc=0x0c0c544eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5528u,2);
goto P_0c0c5450;
P_0c0c5450: /* original ff17, guest PC 0x0c0c5450 */
if(!s->budget--) { s->failed_pc=0x0c0c5450u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c5452;
P_0c0c5452: /* original c73e, guest PC 0x0c0c5452 */
if(!s->budget--) { s->failed_pc=0x0c0c5452u; return 0; }
r[0]=code_base|0x000c554cu;
goto P_0c0c5454;
P_0c0c5454: /* original f308, guest PC 0x0c0c5454 */
if(!s->budget--) { s->failed_pc=0x0c0c5454u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5456;
P_0c0c5456: /* original 9068, guest PC 0x0c0c5456 */
if(!s->budget--) { s->failed_pc=0x0c0c5456u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c5458;
P_0c0c5458: /* original f1f6, guest PC 0x0c0c5458 */
if(!s->budget--) { s->failed_pc=0x0c0c5458u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c545a;
P_0c0c545a: /* original 9066, guest PC 0x0c0c545a */
if(!s->budget--) { s->failed_pc=0x0c0c545au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c545c;
P_0c0c545c: /* original f130, guest PC 0x0c0c545c */
if(!s->budget--) { s->failed_pc=0x0c0c545cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0c545e;
P_0c0c545e: /* original ff17, guest PC 0x0c0c545e */
if(!s->budget--) { s->failed_pc=0x0c0c545eu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c5460;
P_0c0c5460: /* original 945c, guest PC 0x0c0c5460 */
if(!s->budget--) { s->failed_pc=0x0c0c5460u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c5462;
P_0c0c5462: /* original 4d0b, guest PC 0x0c0c5462 */
if(!s->budget--) { s->failed_pc=0x0c0c5462u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c5466u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5466u) { target=s->pc; goto dispatch; }
goto P_0c0c5466;
P_0c0c5464: /* original 34fc, guest PC 0x0c0c5464 */
if(!s->budget--) { s->failed_pc=0x0c0c5464u; return 0; }
r[4]+=r[15];
goto P_0c0c5466;
P_0c0c5466: /* original 905d, guest PC 0x0c0c5466 */
if(!s->budget--) { s->failed_pc=0x0c0c5466u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c5468;
P_0c0c5468: /* original f2a8, guest PC 0x0c0c5468 */
if(!s->budget--) { s->failed_pc=0x0c0c5468u; return 0; }
vf3_matrix_load(s,ram,2,r[10]);
goto P_0c0c546a;
P_0c0c546a: /* original f3f6, guest PC 0x0c0c546a */
if(!s->budget--) { s->failed_pc=0x0c0c546au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c546c;
P_0c0c546c: /* original f0dc, guest PC 0x0c0c546c */
if(!s->budget--) { s->failed_pc=0x0c0c546cu; return 0; }
vf3_matrix_move(s,0,13);
goto P_0c0c546e;
P_0c0c546e: /* original f32e, guest PC 0x0c0c546e */
if(!s->budget--) { s->failed_pc=0x0c0c546eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0c5470;
P_0c0c5470: /* original 9058, guest PC 0x0c0c5470 */
if(!s->budget--) { s->failed_pc=0x0c0c5470u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c5472;
P_0c0c5472: /* original f3f5, guest PC 0x0c0c5472 */
if(!s->budget--) { s->failed_pc=0x0c0c5472u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c5474;
P_0c0c5474: /* original 8f02, guest PC 0x0c0c5474 */
if(!s->budget--) { s->failed_pc=0x0c0c5474u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c0c547c; }
goto P_0c0c5478;
P_0c0c5476: /* original ff37, guest PC 0x0c0c5476 */
if(!s->budget--) { s->failed_pc=0x0c0c5476u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5478;
P_0c0c5478: /* original a2df, guest PC 0x0c0c5478 */
if(!s->budget--) { s->failed_pc=0x0c0c5478u; return 0; }
goto P_0c0c5a3a;
P_0c0c547a: /* original 0009, guest PC 0x0c0c547a */
if(!s->budget--) { s->failed_pc=0x0c0c547au; return 0; }
goto P_0c0c547c;
P_0c0c547c: /* original e038, guest PC 0x0c0c547c */
if(!s->budget--) { s->failed_pc=0x0c0c547cu; return 0; }
r[0]=0x00000038u;
goto P_0c0c547e;
P_0c0c547e: /* original f3f6, guest PC 0x0c0c547e */
if(!s->budget--) { s->failed_pc=0x0c0c547eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5480;
P_0c0c5480: /* original 9051, guest PC 0x0c0c5480 */
if(!s->budget--) { s->failed_pc=0x0c0c5480u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5526u,2);
goto P_0c0c5482;
P_0c0c5482: /* original ff37, guest PC 0x0c0c5482 */
if(!s->budget--) { s->failed_pc=0x0c0c5482u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5484;
P_0c0c5484: /* original c732, guest PC 0x0c0c5484 */
if(!s->budget--) { s->failed_pc=0x0c0c5484u; return 0; }
r[0]=code_base|0x000c5550u;
goto P_0c0c5486;
P_0c0c5486: /* original f308, guest PC 0x0c0c5486 */
if(!s->budget--) { s->failed_pc=0x0c0c5486u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5488;
P_0c0c5488: /* original 904e, guest PC 0x0c0c5488 */
if(!s->budget--) { s->failed_pc=0x0c0c5488u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5528u,2);
goto P_0c0c548a;
P_0c0c548a: /* original fe32, guest PC 0x0c0c548a */
if(!s->budget--) { s->failed_pc=0x0c0c548au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c0c548c;
P_0c0c548c: /* original ffe7, guest PC 0x0c0c548c */
if(!s->budget--) { s->failed_pc=0x0c0c548cu; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c548e;
P_0c0c548e: /* original c72f, guest PC 0x0c0c548e */
if(!s->budget--) { s->failed_pc=0x0c0c548eu; return 0; }
r[0]=code_base|0x000c554cu;
goto P_0c0c5490;
P_0c0c5490: /* original f208, guest PC 0x0c0c5490 */
if(!s->budget--) { s->failed_pc=0x0c0c5490u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c5492;
P_0c0c5492: /* original 904a, guest PC 0x0c0c5492 */
if(!s->budget--) { s->failed_pc=0x0c0c5492u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c5494;
P_0c0c5494: /* original f1f6, guest PC 0x0c0c5494 */
if(!s->budget--) { s->failed_pc=0x0c0c5494u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c5496;
P_0c0c5496: /* original 9048, guest PC 0x0c0c5496 */
if(!s->budget--) { s->failed_pc=0x0c0c5496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c5498;
P_0c0c5498: /* original f120, guest PC 0x0c0c5498 */
if(!s->budget--) { s->failed_pc=0x0c0c5498u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c0c549a;
P_0c0c549a: /* original ff17, guest PC 0x0c0c549a */
if(!s->budget--) { s->failed_pc=0x0c0c549au; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c549c;
P_0c0c549c: /* original 943e, guest PC 0x0c0c549c */
if(!s->budget--) { s->failed_pc=0x0c0c549cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c549e;
P_0c0c549e: /* original 4d0b, guest PC 0x0c0c549e */
if(!s->budget--) { s->failed_pc=0x0c0c549eu; return 0; }
target=r[13];
r[16]=code_base|0x0c0c54a2u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c54a2u) { target=s->pc; goto dispatch; }
goto P_0c0c54a2;
P_0c0c54a0: /* original 34fc, guest PC 0x0c0c54a0 */
if(!s->budget--) { s->failed_pc=0x0c0c54a0u; return 0; }
r[4]+=r[15];
goto P_0c0c54a2;
P_0c0c54a2: /* original 903f, guest PC 0x0c0c54a2 */
if(!s->budget--) { s->failed_pc=0x0c0c54a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c54a4;
P_0c0c54a4: /* original f0a8, guest PC 0x0c0c54a4 */
if(!s->budget--) { s->failed_pc=0x0c0c54a4u; return 0; }
vf3_matrix_load(s,ram,0,r[10]);
goto P_0c0c54a6;
P_0c0c54a6: /* original f3f6, guest PC 0x0c0c54a6 */
if(!s->budget--) { s->failed_pc=0x0c0c54a6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c54a8;
P_0c0c54a8: /* original e008, guest PC 0x0c0c54a8 */
if(!s->budget--) { s->failed_pc=0x0c0c54a8u; return 0; }
r[0]=0x00000008u;
goto P_0c0c54aa;
P_0c0c54aa: /* original f2e6, guest PC 0x0c0c54aa */
if(!s->budget--) { s->failed_pc=0x0c0c54aau; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c54ac;
P_0c0c54ac: /* original 903a, guest PC 0x0c0c54ac */
if(!s->budget--) { s->failed_pc=0x0c0c54acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c54ae;
P_0c0c54ae: /* original f32e, guest PC 0x0c0c54ae */
if(!s->budget--) { s->failed_pc=0x0c0c54aeu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0c54b0;
P_0c0c54b0: /* original f3f5, guest PC 0x0c0c54b0 */
if(!s->budget--) { s->failed_pc=0x0c0c54b0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c54b2;
P_0c0c54b2: /* original 8f02, guest PC 0x0c0c54b2 */
if(!s->budget--) { s->failed_pc=0x0c0c54b2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c0c54ba; }
goto P_0c0c54b6;
P_0c0c54b4: /* original ff37, guest PC 0x0c0c54b4 */
if(!s->budget--) { s->failed_pc=0x0c0c54b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c54b6;
P_0c0c54b6: /* original a2c0, guest PC 0x0c0c54b6 */
if(!s->budget--) { s->failed_pc=0x0c0c54b6u; return 0; }
goto P_0c0c5a3a;
P_0c0c54b8: /* original 0009, guest PC 0x0c0c54b8 */
if(!s->budget--) { s->failed_pc=0x0c0c54b8u; return 0; }
goto P_0c0c54ba;
P_0c0c54ba: /* original 9033, guest PC 0x0c0c54ba */
if(!s->budget--) { s->failed_pc=0x0c0c54bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c54bc;
P_0c0c54bc: /* original fdf6, guest PC 0x0c0c54bc */
if(!s->budget--) { s->failed_pc=0x0c0c54bcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0c54be;
P_0c0c54be: /* original 9035, guest PC 0x0c0c54be */
if(!s->budget--) { s->failed_pc=0x0c0c54beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552cu,2);
goto P_0c0c54c0;
P_0c0c54c0: /* original fef6, guest PC 0x0c0c54c0 */
if(!s->budget--) { s->failed_pc=0x0c0c54c0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c54c2;
P_0c0c54c2: /* original 9032, guest PC 0x0c0c54c2 */
if(!s->budget--) { s->failed_pc=0x0c0c54c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c54c4;
P_0c0c54c4: /* original f3f6, guest PC 0x0c0c54c4 */
if(!s->budget--) { s->failed_pc=0x0c0c54c4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c54c6;
P_0c0c54c6: /* original e040, guest PC 0x0c0c54c6 */
if(!s->budget--) { s->failed_pc=0x0c0c54c6u; return 0; }
r[0]=0x00000040u;
goto P_0c0c54c8;
P_0c0c54c8: /* original ff37, guest PC 0x0c0c54c8 */
if(!s->budget--) { s->failed_pc=0x0c0c54c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c54ca;
P_0c0c54ca: /* original e020, guest PC 0x0c0c54ca */
if(!s->budget--) { s->failed_pc=0x0c0c54cau; return 0; }
r[0]=0x00000020u;
goto P_0c0c54cc;
P_0c0c54cc: /* original 4b0b, guest PC 0x0c0c54cc */
if(!s->budget--) { s->failed_pc=0x0c0c54ccu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c54d0u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c54d0u) { target=s->pc; goto dispatch; }
goto P_0c0c54d0;
P_0c0c54ce: /* original 04fd, guest PC 0x0c0c54ce */
if(!s->budget--) { s->failed_pc=0x0c0c54ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0c54d0;
P_0c0c54d0: /* original 6e03, guest PC 0x0c0c54d0 */
if(!s->budget--) { s->failed_pc=0x0c0c54d0u; return 0; }
r[14]=r[0];
goto P_0c0c54d2;
P_0c0c54d2: /* original e040, guest PC 0x0c0c54d2 */
if(!s->budget--) { s->failed_pc=0x0c0c54d2u; return 0; }
r[0]=0x00000040u;
goto P_0c0c54d4;
P_0c0c54d4: /* original f8f6, guest PC 0x0c0c54d4 */
if(!s->budget--) { s->failed_pc=0x0c0c54d4u; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c54d6;
P_0c0c54d6: /* original e01c, guest PC 0x0c0c54d6 */
if(!s->budget--) { s->failed_pc=0x0c0c54d6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c54d8;
P_0c0c54d8: /* original f7e6, guest PC 0x0c0c54d8 */
if(!s->budget--) { s->failed_pc=0x0c0c54d8u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c54da;
P_0c0c54da: /* original e018, guest PC 0x0c0c54da */
if(!s->budget--) { s->failed_pc=0x0c0c54dau; return 0; }
r[0]=0x00000018u;
goto P_0c0c54dc;
P_0c0c54dc: /* original 941e, guest PC 0x0c0c54dc */
if(!s->budget--) { s->failed_pc=0x0c0c54dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c54de;
P_0c0c54de: /* original d31d, guest PC 0x0c0c54de */
if(!s->budget--) { s->failed_pc=0x0c0c54deu; return 0; }
r[3]=read(ram,0x0c0c5554u,4);
goto P_0c0c54e0;
P_0c0c54e0: /* original f6e6, guest PC 0x0c0c54e0 */
if(!s->budget--) { s->failed_pc=0x0c0c54e0u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c54e2;
P_0c0c54e2: /* original f5ec, guest PC 0x0c0c54e2 */
if(!s->budget--) { s->failed_pc=0x0c0c54e2u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0c54e4;
P_0c0c54e4: /* original f4dc, guest PC 0x0c0c54e4 */
if(!s->budget--) { s->failed_pc=0x0c0c54e4u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c54e6;
P_0c0c54e6: /* original 430b, guest PC 0x0c0c54e6 */
if(!s->budget--) { s->failed_pc=0x0c0c54e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c54eau;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c54eau) { target=s->pc; goto dispatch; }
goto P_0c0c54ea;
P_0c0c54e8: /* original 34fc, guest PC 0x0c0c54e8 */
if(!s->budget--) { s->failed_pc=0x0c0c54e8u; return 0; }
r[4]+=r[15];
goto P_0c0c54ea;
P_0c0c54ea: /* original e014, guest PC 0x0c0c54ea */
if(!s->budget--) { s->failed_pc=0x0c0c54eau; return 0; }
r[0]=0x00000014u;
goto P_0c0c54ec;
P_0c0c54ec: /* original 9416, guest PC 0x0c0c54ec */
if(!s->budget--) { s->failed_pc=0x0c0c54ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c54ee;
P_0c0c54ee: /* original f9e6, guest PC 0x0c0c54ee */
if(!s->budget--) { s->failed_pc=0x0c0c54eeu; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c54f0;
P_0c0c54f0: /* original e010, guest PC 0x0c0c54f0 */
if(!s->budget--) { s->failed_pc=0x0c0c54f0u; return 0; }
r[0]=0x00000010u;
goto P_0c0c54f2;
P_0c0c54f2: /* original f8e6, guest PC 0x0c0c54f2 */
if(!s->budget--) { s->failed_pc=0x0c0c54f2u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c54f4;
P_0c0c54f4: /* original e00c, guest PC 0x0c0c54f4 */
if(!s->budget--) { s->failed_pc=0x0c0c54f4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c54f6;
P_0c0c54f6: /* original f7e6, guest PC 0x0c0c54f6 */
if(!s->budget--) { s->failed_pc=0x0c0c54f6u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c54f8;
P_0c0c54f8: /* original e008, guest PC 0x0c0c54f8 */
if(!s->budget--) { s->failed_pc=0x0c0c54f8u; return 0; }
r[0]=0x00000008u;
goto P_0c0c54fa;
P_0c0c54fa: /* original f6e6, guest PC 0x0c0c54fa */
if(!s->budget--) { s->failed_pc=0x0c0c54fau; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c54fc;
P_0c0c54fc: /* original e004, guest PC 0x0c0c54fc */
if(!s->budget--) { s->failed_pc=0x0c0c54fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0c54fe;
P_0c0c54fe: /* original f4e8, guest PC 0x0c0c54fe */
if(!s->budget--) { s->failed_pc=0x0c0c54feu; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c5500;
P_0c0c5500: /* original f5e6, guest PC 0x0c0c5500 */
if(!s->budget--) { s->failed_pc=0x0c0c5500u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c5502;
P_0c0c5502: /* original 480b, guest PC 0x0c0c5502 */
if(!s->budget--) { s->failed_pc=0x0c0c5502u; return 0; }
target=r[8];
r[16]=code_base|0x0c0c5506u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5506u) { target=s->pc; goto dispatch; }
goto P_0c0c5506;
P_0c0c5504: /* original 34fc, guest PC 0x0c0c5504 */
if(!s->budget--) { s->failed_pc=0x0c0c5504u; return 0; }
r[4]+=r[15];
goto P_0c0c5506;
P_0c0c5506: /* original 53e8, guest PC 0x0c0c5506 */
if(!s->budget--) { s->failed_pc=0x0c0c5506u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c5508;
P_0c0c5508: /* original d009, guest PC 0x0c0c5508 */
if(!s->budget--) { s->failed_pc=0x0c0c5508u; return 0; }
r[0]=read(ram,0x0c0c5530u,4);
goto P_0c0c550a;
P_0c0c550a: /* original 4300, guest PC 0x0c0c550a */
if(!s->budget--) { s->failed_pc=0x0c0c550au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c550c;
P_0c0c550c: /* original 023d, guest PC 0x0c0c550c */
if(!s->budget--) { s->failed_pc=0x0c0c550cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c550e;
P_0c0c550e: /* original 9005, guest PC 0x0c0c550e */
if(!s->budget--) { s->failed_pc=0x0c0c550eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c5510;
P_0c0c5510: /* original 622d, guest PC 0x0c0c5510 */
if(!s->budget--) { s->failed_pc=0x0c0c5510u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c5512;
P_0c0c5512: /* original 0f26, guest PC 0x0c0c5512 */
if(!s->budget--) { s->failed_pc=0x0c0c5512u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c5514;
P_0c0c5514: /* original 9006, guest PC 0x0c0c5514 */
if(!s->budget--) { s->failed_pc=0x0c0c5514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c5516;
P_0c0c5516: /* original ffd7, guest PC 0x0c0c5516 */
if(!s->budget--) { s->failed_pc=0x0c0c5516u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c5518;
P_0c0c5518: /* original a01e, guest PC 0x0c0c5518 */
if(!s->budget--) { s->failed_pc=0x0c0c5518u; return 0; }
goto P_0c0c5558;
P_0c0c551a: /* original 0009, guest PC 0x0c0c551a */
if(!s->budget--) { s->failed_pc=0x0c0c551au; return 0; }
if(!vf3_matrix_family(0x0c0c551cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c551cu; return 0; } return 1;
P_0c0c5558: /* original 9047, guest PC 0x0c0c5558 */
if(!s->budget--) { s->failed_pc=0x0c0c5558u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55eau,2);
goto P_0c0c555a;
P_0c0c555a: /* original ffe7, guest PC 0x0c0c555a */
if(!s->budget--) { s->failed_pc=0x0c0c555au; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c555c;
P_0c0c555c: /* original 9046, guest PC 0x0c0c555c */
if(!s->budget--) { s->failed_pc=0x0c0c555cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55ecu,2);
goto P_0c0c555e;
P_0c0c555e: /* original f3f6, guest PC 0x0c0c555e */
if(!s->budget--) { s->failed_pc=0x0c0c555eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5560;
P_0c0c5560: /* original f3f5, guest PC 0x0c0c5560 */
if(!s->budget--) { s->failed_pc=0x0c0c5560u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c5562;
P_0c0c5562: /* original 8b01, guest PC 0x0c0c5562 */
if(!s->budget--) { s->failed_pc=0x0c0c5562u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5568; }
goto P_0c0c5564;
P_0c0c5564: /* original a269, guest PC 0x0c0c5564 */
if(!s->budget--) { s->failed_pc=0x0c0c5564u; return 0; }
goto P_0c0c5a3a;
P_0c0c5566: /* original 0009, guest PC 0x0c0c5566 */
if(!s->budget--) { s->failed_pc=0x0c0c5566u; return 0; }
goto P_0c0c5568;
P_0c0c5568: /* original c723, guest PC 0x0c0c5568 */
if(!s->budget--) { s->failed_pc=0x0c0c5568u; return 0; }
r[0]=code_base|0x000c55f8u;
goto P_0c0c556a;
P_0c0c556a: /* original f308, guest PC 0x0c0c556a */
if(!s->budget--) { s->failed_pc=0x0c0c556au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c556c;
P_0c0c556c: /* original 903f, guest PC 0x0c0c556c */
if(!s->budget--) { s->failed_pc=0x0c0c556cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55eeu,2);
goto P_0c0c556e;
P_0c0c556e: /* original f2f6, guest PC 0x0c0c556e */
if(!s->budget--) { s->failed_pc=0x0c0c556eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5570;
P_0c0c5570: /* original 903d, guest PC 0x0c0c5570 */
if(!s->budget--) { s->failed_pc=0x0c0c5570u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55eeu,2);
goto P_0c0c5572;
P_0c0c5572: /* original f230, guest PC 0x0c0c5572 */
if(!s->budget--) { s->failed_pc=0x0c0c5572u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5574;
P_0c0c5574: /* original ff27, guest PC 0x0c0c5574 */
if(!s->budget--) { s->failed_pc=0x0c0c5574u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5576;
P_0c0c5576: /* original 943b, guest PC 0x0c0c5576 */
if(!s->budget--) { s->failed_pc=0x0c0c5576u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c5578;
P_0c0c5578: /* original 4d0b, guest PC 0x0c0c5578 */
if(!s->budget--) { s->failed_pc=0x0c0c5578u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c557cu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c557cu) { target=s->pc; goto dispatch; }
goto P_0c0c557c;
P_0c0c557a: /* original 34fc, guest PC 0x0c0c557a */
if(!s->budget--) { s->failed_pc=0x0c0c557au; return 0; }
r[4]+=r[15];
goto P_0c0c557c;
P_0c0c557c: /* original 9036, guest PC 0x0c0c557c */
if(!s->budget--) { s->failed_pc=0x0c0c557cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55ecu,2);
goto P_0c0c557e;
P_0c0c557e: /* original f0a8, guest PC 0x0c0c557e */
if(!s->budget--) { s->failed_pc=0x0c0c557eu; return 0; }
vf3_matrix_load(s,ram,0,r[10]);
goto P_0c0c5580;
P_0c0c5580: /* original f3f6, guest PC 0x0c0c5580 */
if(!s->budget--) { s->failed_pc=0x0c0c5580u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5582;
P_0c0c5582: /* original e008, guest PC 0x0c0c5582 */
if(!s->budget--) { s->failed_pc=0x0c0c5582u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5584;
P_0c0c5584: /* original f2e6, guest PC 0x0c0c5584 */
if(!s->budget--) { s->failed_pc=0x0c0c5584u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c5586;
P_0c0c5586: /* original 9034, guest PC 0x0c0c5586 */
if(!s->budget--) { s->failed_pc=0x0c0c5586u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f2u,2);
goto P_0c0c5588;
P_0c0c5588: /* original f32e, guest PC 0x0c0c5588 */
if(!s->budget--) { s->failed_pc=0x0c0c5588u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0c558a;
P_0c0c558a: /* original f3f5, guest PC 0x0c0c558a */
if(!s->budget--) { s->failed_pc=0x0c0c558au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c558c;
P_0c0c558c: /* original 8f02, guest PC 0x0c0c558c */
if(!s->budget--) { s->failed_pc=0x0c0c558cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c0c5594; }
goto P_0c0c5590;
P_0c0c558e: /* original ff37, guest PC 0x0c0c558e */
if(!s->budget--) { s->failed_pc=0x0c0c558eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5590;
P_0c0c5590: /* original a253, guest PC 0x0c0c5590 */
if(!s->budget--) { s->failed_pc=0x0c0c5590u; return 0; }
goto P_0c0c5a3a;
P_0c0c5592: /* original 0009, guest PC 0x0c0c5592 */
if(!s->budget--) { s->failed_pc=0x0c0c5592u; return 0; }
goto P_0c0c5594;
P_0c0c5594: /* original 942e, guest PC 0x0c0c5594 */
if(!s->budget--) { s->failed_pc=0x0c0c5594u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f4u,2);
goto P_0c0c5596;
P_0c0c5596: /* original 4d0b, guest PC 0x0c0c5596 */
if(!s->budget--) { s->failed_pc=0x0c0c5596u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c559au;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c559au) { target=s->pc; goto dispatch; }
goto P_0c0c559a;
P_0c0c5598: /* original 34fc, guest PC 0x0c0c5598 */
if(!s->budget--) { s->failed_pc=0x0c0c5598u; return 0; }
r[4]+=r[15];
goto P_0c0c559a;
P_0c0c559a: /* original a24e, guest PC 0x0c0c559a */
if(!s->budget--) { s->failed_pc=0x0c0c559au; return 0; }
goto P_0c0c5a3a;
P_0c0c559c: /* original 0009, guest PC 0x0c0c559c */
if(!s->budget--) { s->failed_pc=0x0c0c559cu; return 0; }
goto P_0c0c559e;
P_0c0c559e: /* original 9427, guest PC 0x0c0c559e */
if(!s->budget--) { s->failed_pc=0x0c0c559eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c55a0;
P_0c0c55a0: /* original 4d0b, guest PC 0x0c0c55a0 */
if(!s->budget--) { s->failed_pc=0x0c0c55a0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c55a4u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c55a4u) { target=s->pc; goto dispatch; }
goto P_0c0c55a4;
P_0c0c55a2: /* original 34fc, guest PC 0x0c0c55a2 */
if(!s->budget--) { s->failed_pc=0x0c0c55a2u; return 0; }
r[4]+=r[15];
goto P_0c0c55a4;
P_0c0c55a4: /* original e008, guest PC 0x0c0c55a4 */
if(!s->budget--) { s->failed_pc=0x0c0c55a4u; return 0; }
r[0]=0x00000008u;
goto P_0c0c55a6;
P_0c0c55a6: /* original 53f6, guest PC 0x0c0c55a6 */
if(!s->budget--) { s->failed_pc=0x0c0c55a6u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c55a8;
P_0c0c55a8: /* original f3e6, guest PC 0x0c0c55a8 */
if(!s->budget--) { s->failed_pc=0x0c0c55a8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c55aa;
P_0c0c55aa: /* original d014, guest PC 0x0c0c55aa */
if(!s->budget--) { s->failed_pc=0x0c0c55aau; return 0; }
r[0]=read(ram,0x0c0c55fcu,4);
goto P_0c0c55ac;
P_0c0c55ac: /* original fe30, guest PC 0x0c0c55ac */
if(!s->budget--) { s->failed_pc=0x0c0c55acu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'+');
goto P_0c0c55ae;
P_0c0c55ae: /* original 941f, guest PC 0x0c0c55ae */
if(!s->budget--) { s->failed_pc=0x0c0c55aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c55b0;
P_0c0c55b0: /* original f836, guest PC 0x0c0c55b0 */
if(!s->budget--) { s->failed_pc=0x0c0c55b0u; return 0; }
vf3_matrix_load(s,ram,8,r[3]+r[0]);
goto P_0c0c55b2;
P_0c0c55b2: /* original e01c, guest PC 0x0c0c55b2 */
if(!s->budget--) { s->failed_pc=0x0c0c55b2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c55b4;
P_0c0c55b4: /* original f7e6, guest PC 0x0c0c55b4 */
if(!s->budget--) { s->failed_pc=0x0c0c55b4u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c55b6;
P_0c0c55b6: /* original e018, guest PC 0x0c0c55b6 */
if(!s->budget--) { s->failed_pc=0x0c0c55b6u; return 0; }
r[0]=0x00000018u;
goto P_0c0c55b8;
P_0c0c55b8: /* original d311, guest PC 0x0c0c55b8 */
if(!s->budget--) { s->failed_pc=0x0c0c55b8u; return 0; }
r[3]=read(ram,0x0c0c5600u,4);
goto P_0c0c55ba;
P_0c0c55ba: /* original f6e6, guest PC 0x0c0c55ba */
if(!s->budget--) { s->failed_pc=0x0c0c55bau; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c55bc;
P_0c0c55bc: /* original f5dc, guest PC 0x0c0c55bc */
if(!s->budget--) { s->failed_pc=0x0c0c55bcu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c0c55be;
P_0c0c55be: /* original f4ec, guest PC 0x0c0c55be */
if(!s->budget--) { s->failed_pc=0x0c0c55beu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c55c0;
P_0c0c55c0: /* original 430b, guest PC 0x0c0c55c0 */
if(!s->budget--) { s->failed_pc=0x0c0c55c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c55c4u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c55c4u) { target=s->pc; goto dispatch; }
goto P_0c0c55c4;
P_0c0c55c2: /* original 34fc, guest PC 0x0c0c55c2 */
if(!s->budget--) { s->failed_pc=0x0c0c55c2u; return 0; }
r[4]+=r[15];
goto P_0c0c55c4;
P_0c0c55c4: /* original e014, guest PC 0x0c0c55c4 */
if(!s->budget--) { s->failed_pc=0x0c0c55c4u; return 0; }
r[0]=0x00000014u;
goto P_0c0c55c6;
P_0c0c55c6: /* original 9413, guest PC 0x0c0c55c6 */
if(!s->budget--) { s->failed_pc=0x0c0c55c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c55c8;
P_0c0c55c8: /* original f9e6, guest PC 0x0c0c55c8 */
if(!s->budget--) { s->failed_pc=0x0c0c55c8u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c55ca;
P_0c0c55ca: /* original e010, guest PC 0x0c0c55ca */
if(!s->budget--) { s->failed_pc=0x0c0c55cau; return 0; }
r[0]=0x00000010u;
goto P_0c0c55cc;
P_0c0c55cc: /* original f8e6, guest PC 0x0c0c55cc */
if(!s->budget--) { s->failed_pc=0x0c0c55ccu; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c55ce;
P_0c0c55ce: /* original e00c, guest PC 0x0c0c55ce */
if(!s->budget--) { s->failed_pc=0x0c0c55ceu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c55d0;
P_0c0c55d0: /* original f7e6, guest PC 0x0c0c55d0 */
if(!s->budget--) { s->failed_pc=0x0c0c55d0u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c55d2;
P_0c0c55d2: /* original e008, guest PC 0x0c0c55d2 */
if(!s->budget--) { s->failed_pc=0x0c0c55d2u; return 0; }
r[0]=0x00000008u;
goto P_0c0c55d4;
P_0c0c55d4: /* original f6e6, guest PC 0x0c0c55d4 */
if(!s->budget--) { s->failed_pc=0x0c0c55d4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c55d6;
P_0c0c55d6: /* original e004, guest PC 0x0c0c55d6 */
if(!s->budget--) { s->failed_pc=0x0c0c55d6u; return 0; }
r[0]=0x00000004u;
goto P_0c0c55d8;
P_0c0c55d8: /* original f4e8, guest PC 0x0c0c55d8 */
if(!s->budget--) { s->failed_pc=0x0c0c55d8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c55da;
P_0c0c55da: /* original f5e6, guest PC 0x0c0c55da */
if(!s->budget--) { s->failed_pc=0x0c0c55dau; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c55dc;
P_0c0c55dc: /* original 480b, guest PC 0x0c0c55dc */
if(!s->budget--) { s->failed_pc=0x0c0c55dcu; return 0; }
target=r[8];
r[16]=code_base|0x0c0c55e0u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c55e0u) { target=s->pc; goto dispatch; }
goto P_0c0c55e0;
P_0c0c55de: /* original 34fc, guest PC 0x0c0c55de */
if(!s->budget--) { s->failed_pc=0x0c0c55deu; return 0; }
r[4]+=r[15];
goto P_0c0c55e0;
P_0c0c55e0: /* original 9406, guest PC 0x0c0c55e0 */
if(!s->budget--) { s->failed_pc=0x0c0c55e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c55e2;
P_0c0c55e2: /* original 4d0b, guest PC 0x0c0c55e2 */
if(!s->budget--) { s->failed_pc=0x0c0c55e2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c55e6u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c55e6u) { target=s->pc; goto dispatch; }
goto P_0c0c55e6;
P_0c0c55e4: /* original 34fc, guest PC 0x0c0c55e4 */
if(!s->budget--) { s->failed_pc=0x0c0c55e4u; return 0; }
r[4]+=r[15];
goto P_0c0c55e6;
P_0c0c55e6: /* original a221, guest PC 0x0c0c55e6 */
if(!s->budget--) { s->failed_pc=0x0c0c55e6u; return 0; }
goto P_0c0c5a2c;
P_0c0c55e8: /* original 0009, guest PC 0x0c0c55e8 */
if(!s->budget--) { s->failed_pc=0x0c0c55e8u; return 0; }
if(!vf3_matrix_family(0x0c0c55eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c55eau; return 0; } return 1;
P_0c0c5604: /* original c75d, guest PC 0x0c0c5604 */
if(!s->budget--) { s->failed_pc=0x0c0c5604u; return 0; }
r[0]=code_base|0x000c577cu;
goto P_0c0c5606;
P_0c0c5606: /* original d360, guest PC 0x0c0c5606 */
if(!s->budget--) { s->failed_pc=0x0c0c5606u; return 0; }
r[3]=read(ram,0x0c0c5788u,4);
goto P_0c0c5608;
P_0c0c5608: /* original f708, guest PC 0x0c0c5608 */
if(!s->budget--) { s->failed_pc=0x0c0c5608u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0c560a;
P_0c0c560a: /* original c75d, guest PC 0x0c0c560a */
if(!s->budget--) { s->failed_pc=0x0c0c560au; return 0; }
r[0]=code_base|0x000c5780u;
goto P_0c0c560c;
P_0c0c560c: /* original f408, guest PC 0x0c0c560c */
if(!s->budget--) { s->failed_pc=0x0c0c560cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c560e;
P_0c0c560e: /* original 90aa, guest PC 0x0c0c560e */
if(!s->budget--) { s->failed_pc=0x0c0c560eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5766u,2);
goto P_0c0c5610;
P_0c0c5610: /* original f538, guest PC 0x0c0c5610 */
if(!s->budget--) { s->failed_pc=0x0c0c5610u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c0c5612;
P_0c0c5612: /* original fef6, guest PC 0x0c0c5612 */
if(!s->budget--) { s->failed_pc=0x0c0c5612u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c5614;
P_0c0c5614: /* original 50e8, guest PC 0x0c0c5614 */
if(!s->budget--) { s->failed_pc=0x0c0c5614u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c0c5616;
P_0c0c5616: /* original d95b, guest PC 0x0c0c5616 */
if(!s->budget--) { s->failed_pc=0x0c0c5616u; return 0; }
r[9]=read(ram,0x0c0c5784u,4);
goto P_0c0c5618;
P_0c0c5618: /* original f6a8, guest PC 0x0c0c5618 */
if(!s->budget--) { s->failed_pc=0x0c0c5618u; return 0; }
vf3_matrix_load(s,ram,6,r[10]);
goto P_0c0c561a;
P_0c0c561a: /* original 882c, guest PC 0x0c0c561a */
if(!s->budget--) { s->failed_pc=0x0c0c561au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c0c561c;
P_0c0c561c: /* original 8d05, guest PC 0x0c0c561c */
if(!s->budget--) { s->failed_pc=0x0c0c561cu; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c0c562a; }
goto P_0c0c5620;
P_0c0c561e: /* original 6503, guest PC 0x0c0c561e */
if(!s->budget--) { s->failed_pc=0x0c0c561eu; return 0; }
r[5]=r[0];
goto P_0c0c5620;
P_0c0c5620: /* original 6053, guest PC 0x0c0c5620 */
if(!s->budget--) { s->failed_pc=0x0c0c5620u; return 0; }
r[0]=r[5];
goto P_0c0c5622;
P_0c0c5622: /* original 8834, guest PC 0x0c0c5622 */
if(!s->budget--) { s->failed_pc=0x0c0c5622u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c0c5624;
P_0c0c5624: /* original 8901, guest PC 0x0c0c5624 */
if(!s->budget--) { s->failed_pc=0x0c0c5624u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c562a; }
goto P_0c0c5626;
P_0c0c5626: /* original a187, guest PC 0x0c0c5626 */
if(!s->budget--) { s->failed_pc=0x0c0c5626u; return 0; }
goto P_0c0c5938;
P_0c0c5628: /* original 0009, guest PC 0x0c0c5628 */
if(!s->budget--) { s->failed_pc=0x0c0c5628u; return 0; }
goto P_0c0c562a;
P_0c0c562a: /* original e008, guest PC 0x0c0c562a */
if(!s->budget--) { s->failed_pc=0x0c0c562au; return 0; }
r[0]=0x00000008u;
goto P_0c0c562c;
P_0c0c562c: /* original f3e6, guest PC 0x0c0c562c */
if(!s->budget--) { s->failed_pc=0x0c0c562cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c562e;
P_0c0c562e: /* original e010, guest PC 0x0c0c562e */
if(!s->budget--) { s->failed_pc=0x0c0c562eu; return 0; }
r[0]=0x00000010u;
goto P_0c0c5630;
P_0c0c5630: /* original f362, guest PC 0x0c0c5630 */
if(!s->budget--) { s->failed_pc=0x0c0c5630u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0c5632;
P_0c0c5632: /* original ff37, guest PC 0x0c0c5632 */
if(!s->budget--) { s->failed_pc=0x0c0c5632u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5634;
P_0c0c5634: /* original e014, guest PC 0x0c0c5634 */
if(!s->budget--) { s->failed_pc=0x0c0c5634u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5636;
P_0c0c5636: /* original f8e6, guest PC 0x0c0c5636 */
if(!s->budget--) { s->failed_pc=0x0c0c5636u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c5638;
P_0c0c5638: /* original e00c, guest PC 0x0c0c5638 */
if(!s->budget--) { s->failed_pc=0x0c0c5638u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c563a;
P_0c0c563a: /* original f6e6, guest PC 0x0c0c563a */
if(!s->budget--) { s->failed_pc=0x0c0c563au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c563c;
P_0c0c563c: /* original f3ec, guest PC 0x0c0c563c */
if(!s->budget--) { s->failed_pc=0x0c0c563cu; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0c563e;
P_0c0c563e: /* original f06c, guest PC 0x0c0c563e */
if(!s->budget--) { s->failed_pc=0x0c0c563eu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0c5640;
P_0c0c5640: /* original f35e, guest PC 0x0c0c5640 */
if(!s->budget--) { s->failed_pc=0x0c0c5640u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0c5642;
P_0c0c5642: /* original 9091, guest PC 0x0c0c5642 */
if(!s->budget--) { s->failed_pc=0x0c0c5642u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5768u,2);
goto P_0c0c5644;
P_0c0c5644: /* original 03fe, guest PC 0x0c0c5644 */
if(!s->budget--) { s->failed_pc=0x0c0c5644u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c5646;
P_0c0c5646: /* original f53c, guest PC 0x0c0c5646 */
if(!s->budget--) { s->failed_pc=0x0c0c5646u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c5648;
P_0c0c5648: /* original 908e, guest PC 0x0c0c5648 */
if(!s->budget--) { s->failed_pc=0x0c0c5648u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5768u,2);
goto P_0c0c564a;
P_0c0c564a: /* original 2349, guest PC 0x0c0c564a */
if(!s->budget--) { s->failed_pc=0x0c0c564au; return 0; }
r[3]&=r[4];
goto P_0c0c564c;
P_0c0c564c: /* original 0f36, guest PC 0x0c0c564c */
if(!s->budget--) { s->failed_pc=0x0c0c564cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c564e;
P_0c0c564e: /* original e004, guest PC 0x0c0c564e */
if(!s->budget--) { s->failed_pc=0x0c0c564eu; return 0; }
r[0]=0x00000004u;
goto P_0c0c5650;
P_0c0c5650: /* original f35c, guest PC 0x0c0c5650 */
if(!s->budget--) { s->failed_pc=0x0c0c5650u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0c5652;
P_0c0c5652: /* original f3e1, guest PC 0x0c0c5652 */
if(!s->budget--) { s->failed_pc=0x0c0c5652u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'-');
goto P_0c0c5654;
P_0c0c5654: /* original f20c, guest PC 0x0c0c5654 */
if(!s->budget--) { s->failed_pc=0x0c0c5654u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0c5656;
P_0c0c5656: /* original f370, guest PC 0x0c0c5656 */
if(!s->budget--) { s->failed_pc=0x0c0c5656u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c0c5658;
P_0c0c5658: /* original f233, guest PC 0x0c0c5658 */
if(!s->budget--) { s->failed_pc=0x0c0c5658u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c0c565a;
P_0c0c565a: /* original f282, guest PC 0x0c0c565a */
if(!s->budget--) { s->failed_pc=0x0c0c565au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c0c565c;
P_0c0c565c: /* original ff27, guest PC 0x0c0c565c */
if(!s->budget--) { s->failed_pc=0x0c0c565cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c565e;
P_0c0c565e: /* original e01c, guest PC 0x0c0c565e */
if(!s->budget--) { s->failed_pc=0x0c0c565eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5660;
P_0c0c5660: /* original f3e6, guest PC 0x0c0c5660 */
if(!s->budget--) { s->failed_pc=0x0c0c5660u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c5662;
P_0c0c5662: /* original 9082, guest PC 0x0c0c5662 */
if(!s->budget--) { s->failed_pc=0x0c0c5662u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576au,2);
goto P_0c0c5664;
P_0c0c5664: /* original f363, guest PC 0x0c0c5664 */
if(!s->budget--) { s->failed_pc=0x0c0c5664u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'/');
goto P_0c0c5666;
P_0c0c5666: /* original ff37, guest PC 0x0c0c5666 */
if(!s->budget--) { s->failed_pc=0x0c0c5666u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5668;
P_0c0c5668: /* original 9080, guest PC 0x0c0c5668 */
if(!s->budget--) { s->failed_pc=0x0c0c5668u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576cu,2);
goto P_0c0c566a;
P_0c0c566a: /* original fdf6, guest PC 0x0c0c566a */
if(!s->budget--) { s->failed_pc=0x0c0c566au; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0c566c;
P_0c0c566c: /* original e014, guest PC 0x0c0c566c */
if(!s->budget--) { s->failed_pc=0x0c0c566cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c566e;
P_0c0c566e: /* original f6e6, guest PC 0x0c0c566e */
if(!s->budget--) { s->failed_pc=0x0c0c566eu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c5670;
P_0c0c5670: /* original c746, guest PC 0x0c0c5670 */
if(!s->budget--) { s->failed_pc=0x0c0c5670u; return 0; }
r[0]=code_base|0x000c578cu;
goto P_0c0c5672;
P_0c0c5672: /* original f308, guest PC 0x0c0c5672 */
if(!s->budget--) { s->failed_pc=0x0c0c5672u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5674;
P_0c0c5674: /* original e00c, guest PC 0x0c0c5674 */
if(!s->budget--) { s->failed_pc=0x0c0c5674u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5676;
P_0c0c5676: /* original f26c, guest PC 0x0c0c5676 */
if(!s->budget--) { s->failed_pc=0x0c0c5676u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0c5678;
P_0c0c5678: /* original fe45, guest PC 0x0c0c5678 */
if(!s->budget--) { s->failed_pc=0x0c0c5678u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0c567a;
P_0c0c567a: /* original f232, guest PC 0x0c0c567a */
if(!s->budget--) { s->failed_pc=0x0c0c567au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c567c;
P_0c0c567c: /* original ff27, guest PC 0x0c0c567c */
if(!s->budget--) { s->failed_pc=0x0c0c567cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c567e;
P_0c0c567e: /* original c744, guest PC 0x0c0c567e */
if(!s->budget--) { s->failed_pc=0x0c0c567eu; return 0; }
r[0]=code_base|0x000c5790u;
goto P_0c0c5680;
P_0c0c5680: /* original f108, guest PC 0x0c0c5680 */
if(!s->budget--) { s->failed_pc=0x0c0c5680u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c5682;
P_0c0c5682: /* original e008, guest PC 0x0c0c5682 */
if(!s->budget--) { s->failed_pc=0x0c0c5682u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5684;
P_0c0c5684: /* original f612, guest PC 0x0c0c5684 */
if(!s->budget--) { s->failed_pc=0x0c0c5684u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'*');
goto P_0c0c5686;
P_0c0c5686: /* original 8f02, guest PC 0x0c0c5686 */
if(!s->budget--) { s->failed_pc=0x0c0c5686u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,6,r[15]+r[0]);
if(!cond) { goto P_0c0c568e; }
goto P_0c0c568a;
P_0c0c5688: /* original ff67, guest PC 0x0c0c5688 */
if(!s->budget--) { s->failed_pc=0x0c0c5688u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0c568a;
P_0c0c568a: /* original a1cf, guest PC 0x0c0c568a */
if(!s->budget--) { s->failed_pc=0x0c0c568au; return 0; }
goto P_0c0c5a2c;
P_0c0c568c: /* original 0009, guest PC 0x0c0c568c */
if(!s->budget--) { s->failed_pc=0x0c0c568cu; return 0; }
goto P_0c0c568e;
P_0c0c568e: /* original f39d, guest PC 0x0c0c568e */
if(!s->budget--) { s->failed_pc=0x0c0c568eu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c5690;
P_0c0c5690: /* original f355, guest PC 0x0c0c5690 */
if(!s->budget--) { s->failed_pc=0x0c0c5690u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0c5692;
P_0c0c5692: /* original 8b01, guest PC 0x0c0c5692 */
if(!s->budget--) { s->failed_pc=0x0c0c5692u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5698; }
goto P_0c0c5694;
P_0c0c5694: /* original a1ca, guest PC 0x0c0c5694 */
if(!s->budget--) { s->failed_pc=0x0c0c5694u; return 0; }
goto P_0c0c5a2c;
P_0c0c5696: /* original 0009, guest PC 0x0c0c5696 */
if(!s->budget--) { s->failed_pc=0x0c0c5696u; return 0; }
goto P_0c0c5698;
P_0c0c5698: /* original f35c, guest PC 0x0c0c5698 */
if(!s->budget--) { s->failed_pc=0x0c0c5698u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0c569a;
P_0c0c569a: /* original f345, guest PC 0x0c0c569a */
if(!s->budget--) { s->failed_pc=0x0c0c569au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0c569c;
P_0c0c569c: /* original e01c, guest PC 0x0c0c569c */
if(!s->budget--) { s->failed_pc=0x0c0c569cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c569e;
P_0c0c569e: /* original 8f02, guest PC 0x0c0c569e */
if(!s->budget--) { s->failed_pc=0x0c0c569eu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,5,r[15]+r[0]);
if(!cond) { goto P_0c0c56a6; }
goto P_0c0c56a2;
P_0c0c56a0: /* original ff57, guest PC 0x0c0c56a0 */
if(!s->budget--) { s->failed_pc=0x0c0c56a0u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0c56a2;
P_0c0c56a2: /* original e01c, guest PC 0x0c0c56a2 */
if(!s->budget--) { s->failed_pc=0x0c0c56a2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c56a4;
P_0c0c56a4: /* original ff47, guest PC 0x0c0c56a4 */
if(!s->budget--) { s->failed_pc=0x0c0c56a4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c56a6;
P_0c0c56a6: /* original c73b, guest PC 0x0c0c56a6 */
if(!s->budget--) { s->failed_pc=0x0c0c56a6u; return 0; }
r[0]=code_base|0x000c5794u;
goto P_0c0c56a8;
P_0c0c56a8: /* original f308, guest PC 0x0c0c56a8 */
if(!s->budget--) { s->failed_pc=0x0c0c56a8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c56aa;
P_0c0c56aa: /* original e004, guest PC 0x0c0c56aa */
if(!s->budget--) { s->failed_pc=0x0c0c56aau; return 0; }
r[0]=0x00000004u;
goto P_0c0c56ac;
P_0c0c56ac: /* original f2f6, guest PC 0x0c0c56ac */
if(!s->budget--) { s->failed_pc=0x0c0c56acu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c56ae;
P_0c0c56ae: /* original e004, guest PC 0x0c0c56ae */
if(!s->budget--) { s->failed_pc=0x0c0c56aeu; return 0; }
r[0]=0x00000004u;
goto P_0c0c56b0;
P_0c0c56b0: /* original f232, guest PC 0x0c0c56b0 */
if(!s->budget--) { s->failed_pc=0x0c0c56b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c56b2;
P_0c0c56b2: /* original ff27, guest PC 0x0c0c56b2 */
if(!s->budget--) { s->failed_pc=0x0c0c56b2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c56b4;
P_0c0c56b4: /* original 9059, guest PC 0x0c0c56b4 */
if(!s->budget--) { s->failed_pc=0x0c0c56b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576au,2);
goto P_0c0c56b6;
P_0c0c56b6: /* original f1f6, guest PC 0x0c0c56b6 */
if(!s->budget--) { s->failed_pc=0x0c0c56b6u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c56b8;
P_0c0c56b8: /* original 9057, guest PC 0x0c0c56b8 */
if(!s->budget--) { s->failed_pc=0x0c0c56b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576au,2);
goto P_0c0c56ba;
P_0c0c56ba: /* original f132, guest PC 0x0c0c56ba */
if(!s->budget--) { s->failed_pc=0x0c0c56bau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0c56bc;
P_0c0c56bc: /* original ff17, guest PC 0x0c0c56bc */
if(!s->budget--) { s->failed_pc=0x0c0c56bcu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c56be;
P_0c0c56be: /* original 9156, guest PC 0x0c0c56be */
if(!s->budget--) { s->failed_pc=0x0c0c56beu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576eu,2);
goto P_0c0c56c0;
P_0c0c56c0: /* original 9256, guest PC 0x0c0c56c0 */
if(!s->budget--) { s->failed_pc=0x0c0c56c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5770u,2);
goto P_0c0c56c2;
P_0c0c56c2: /* original d335, guest PC 0x0c0c56c2 */
if(!s->budget--) { s->failed_pc=0x0c0c56c2u; return 0; }
r[3]=read(ram,0x0c0c5798u,4);
goto P_0c0c56c4;
P_0c0c56c4: /* original 31fc, guest PC 0x0c0c56c4 */
if(!s->budget--) { s->failed_pc=0x0c0c56c4u; return 0; }
r[1]+=r[15];
goto P_0c0c56c6;
P_0c0c56c6: /* original 32fc, guest PC 0x0c0c56c6 */
if(!s->budget--) { s->failed_pc=0x0c0c56c6u; return 0; }
r[2]+=r[15];
goto P_0c0c56c8;
P_0c0c56c8: /* original 430b, guest PC 0x0c0c56c8 */
if(!s->budget--) { s->failed_pc=0x0c0c56c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c56ccu;
r[0]=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c56ccu) { target=s->pc; goto dispatch; }
goto P_0c0c56cc;
P_0c0c56ca: /* original e034, guest PC 0x0c0c56ca */
if(!s->budget--) { s->failed_pc=0x0c0c56cau; return 0; }
r[0]=0x00000034u;
goto P_0c0c56cc;
P_0c0c56cc: /* original c733, guest PC 0x0c0c56cc */
if(!s->budget--) { s->failed_pc=0x0c0c56ccu; return 0; }
r[0]=code_base|0x000c579cu;
goto P_0c0c56ce;
P_0c0c56ce: /* original f308, guest PC 0x0c0c56ce */
if(!s->budget--) { s->failed_pc=0x0c0c56ceu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c56d0;
P_0c0c56d0: /* original 904f, guest PC 0x0c0c56d0 */
if(!s->budget--) { s->failed_pc=0x0c0c56d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5772u,2);
goto P_0c0c56d2;
P_0c0c56d2: /* original f1f6, guest PC 0x0c0c56d2 */
if(!s->budget--) { s->failed_pc=0x0c0c56d2u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c56d4;
P_0c0c56d4: /* original 904d, guest PC 0x0c0c56d4 */
if(!s->budget--) { s->failed_pc=0x0c0c56d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5772u,2);
goto P_0c0c56d6;
P_0c0c56d6: /* original f130, guest PC 0x0c0c56d6 */
if(!s->budget--) { s->failed_pc=0x0c0c56d6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0c56d8;
P_0c0c56d8: /* original ff17, guest PC 0x0c0c56d8 */
if(!s->budget--) { s->failed_pc=0x0c0c56d8u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c56da;
P_0c0c56da: /* original 914b, guest PC 0x0c0c56da */
if(!s->budget--) { s->failed_pc=0x0c0c56dau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5774u,2);
goto P_0c0c56dc;
P_0c0c56dc: /* original 9248, guest PC 0x0c0c56dc */
if(!s->budget--) { s->failed_pc=0x0c0c56dcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5770u,2);
goto P_0c0c56de;
P_0c0c56de: /* original d32e, guest PC 0x0c0c56de */
if(!s->budget--) { s->failed_pc=0x0c0c56deu; return 0; }
r[3]=read(ram,0x0c0c5798u,4);
goto P_0c0c56e0;
P_0c0c56e0: /* original 31fc, guest PC 0x0c0c56e0 */
if(!s->budget--) { s->failed_pc=0x0c0c56e0u; return 0; }
r[1]+=r[15];
goto P_0c0c56e2;
P_0c0c56e2: /* original 32fc, guest PC 0x0c0c56e2 */
if(!s->budget--) { s->failed_pc=0x0c0c56e2u; return 0; }
r[2]+=r[15];
goto P_0c0c56e4;
P_0c0c56e4: /* original 430b, guest PC 0x0c0c56e4 */
if(!s->budget--) { s->failed_pc=0x0c0c56e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c56e8u;
r[0]=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c56e8u) { target=s->pc; goto dispatch; }
goto P_0c0c56e8;
P_0c0c56e6: /* original e034, guest PC 0x0c0c56e6 */
if(!s->budget--) { s->failed_pc=0x0c0c56e6u; return 0; }
r[0]=0x00000034u;
goto P_0c0c56e8;
P_0c0c56e8: /* original c72d, guest PC 0x0c0c56e8 */
if(!s->budget--) { s->failed_pc=0x0c0c56e8u; return 0; }
r[0]=code_base|0x000c57a0u;
goto P_0c0c56ea;
P_0c0c56ea: /* original f108, guest PC 0x0c0c56ea */
if(!s->budget--) { s->failed_pc=0x0c0c56eau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c56ec;
P_0c0c56ec: /* original 9043, guest PC 0x0c0c56ec */
if(!s->budget--) { s->failed_pc=0x0c0c56ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5776u,2);
goto P_0c0c56ee;
P_0c0c56ee: /* original f0f6, guest PC 0x0c0c56ee */
if(!s->budget--) { s->failed_pc=0x0c0c56eeu; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0c56f0;
P_0c0c56f0: /* original 9041, guest PC 0x0c0c56f0 */
if(!s->budget--) { s->failed_pc=0x0c0c56f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5776u,2);
goto P_0c0c56f2;
P_0c0c56f2: /* original f011, guest PC 0x0c0c56f2 */
if(!s->budget--) { s->failed_pc=0x0c0c56f2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c0c56f4;
P_0c0c56f4: /* original ff07, guest PC 0x0c0c56f4 */
if(!s->budget--) { s->failed_pc=0x0c0c56f4u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0c56f6;
P_0c0c56f6: /* original 913f, guest PC 0x0c0c56f6 */
if(!s->budget--) { s->failed_pc=0x0c0c56f6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5778u,2);
goto P_0c0c56f8;
P_0c0c56f8: /* original 923a, guest PC 0x0c0c56f8 */
if(!s->budget--) { s->failed_pc=0x0c0c56f8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5770u,2);
goto P_0c0c56fa;
P_0c0c56fa: /* original d327, guest PC 0x0c0c56fa */
if(!s->budget--) { s->failed_pc=0x0c0c56fau; return 0; }
r[3]=read(ram,0x0c0c5798u,4);
goto P_0c0c56fc;
P_0c0c56fc: /* original 31fc, guest PC 0x0c0c56fc */
if(!s->budget--) { s->failed_pc=0x0c0c56fcu; return 0; }
r[1]+=r[15];
goto P_0c0c56fe;
P_0c0c56fe: /* original 32fc, guest PC 0x0c0c56fe */
if(!s->budget--) { s->failed_pc=0x0c0c56feu; return 0; }
r[2]+=r[15];
goto P_0c0c5700;
P_0c0c5700: /* original 430b, guest PC 0x0c0c5700 */
if(!s->budget--) { s->failed_pc=0x0c0c5700u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5704u;
r[0]=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5704u) { target=s->pc; goto dispatch; }
goto P_0c0c5704;
P_0c0c5702: /* original e034, guest PC 0x0c0c5702 */
if(!s->budget--) { s->failed_pc=0x0c0c5702u; return 0; }
r[0]=0x00000034u;
goto P_0c0c5704;
P_0c0c5704: /* original c727, guest PC 0x0c0c5704 */
if(!s->budget--) { s->failed_pc=0x0c0c5704u; return 0; }
r[0]=code_base|0x000c57a4u;
goto P_0c0c5706;
P_0c0c5706: /* original 61f3, guest PC 0x0c0c5706 */
if(!s->budget--) { s->failed_pc=0x0c0c5706u; return 0; }
r[1]=r[15];
goto P_0c0c5708;
P_0c0c5708: /* original f208, guest PC 0x0c0c5708 */
if(!s->budget--) { s->failed_pc=0x0c0c5708u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c570a;
P_0c0c570a: /* original 7154, guest PC 0x0c0c570a */
if(!s->budget--) { s->failed_pc=0x0c0c570au; return 0; }
r[1]+=0x00000054u;
goto P_0c0c570c;
P_0c0c570c: /* original 9035, guest PC 0x0c0c570c */
if(!s->budget--) { s->failed_pc=0x0c0c570cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c577au,2);
goto P_0c0c570e;
P_0c0c570e: /* original f0f6, guest PC 0x0c0c570e */
if(!s->budget--) { s->failed_pc=0x0c0c570eu; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0c5710;
P_0c0c5710: /* original 9033, guest PC 0x0c0c5710 */
if(!s->budget--) { s->failed_pc=0x0c0c5710u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c577au,2);
goto P_0c0c5712;
P_0c0c5712: /* original f021, guest PC 0x0c0c5712 */
if(!s->budget--) { s->failed_pc=0x0c0c5712u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'-');
goto P_0c0c5714;
P_0c0c5714: /* original ff07, guest PC 0x0c0c5714 */
if(!s->budget--) { s->failed_pc=0x0c0c5714u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0c5716;
P_0c0c5716: /* original 922b, guest PC 0x0c0c5716 */
if(!s->budget--) { s->failed_pc=0x0c0c5716u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5770u,2);
goto P_0c0c5718;
P_0c0c5718: /* original d31f, guest PC 0x0c0c5718 */
if(!s->budget--) { s->failed_pc=0x0c0c5718u; return 0; }
r[3]=read(ram,0x0c0c5798u,4);
goto P_0c0c571a;
P_0c0c571a: /* original 32fc, guest PC 0x0c0c571a */
if(!s->budget--) { s->failed_pc=0x0c0c571au; return 0; }
r[2]+=r[15];
goto P_0c0c571c;
P_0c0c571c: /* original 430b, guest PC 0x0c0c571c */
if(!s->budget--) { s->failed_pc=0x0c0c571cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5720u;
r[0]=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5720u) { target=s->pc; goto dispatch; }
goto P_0c0c5720;
P_0c0c571e: /* original e034, guest PC 0x0c0c571e */
if(!s->budget--) { s->failed_pc=0x0c0c571eu; return 0; }
r[0]=0x00000034u;
goto P_0c0c5720;
P_0c0c5720: /* original c721, guest PC 0x0c0c5720 */
if(!s->budget--) { s->failed_pc=0x0c0c5720u; return 0; }
r[0]=code_base|0x000c57a8u;
goto P_0c0c5722;
P_0c0c5722: /* original f308, guest PC 0x0c0c5722 */
if(!s->budget--) { s->failed_pc=0x0c0c5722u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5724;
P_0c0c5724: /* original e060, guest PC 0x0c0c5724 */
if(!s->budget--) { s->failed_pc=0x0c0c5724u; return 0; }
r[0]=0x00000060u;
goto P_0c0c5726;
P_0c0c5726: /* original f0f6, guest PC 0x0c0c5726 */
if(!s->budget--) { s->failed_pc=0x0c0c5726u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0c5728;
P_0c0c5728: /* original e060, guest PC 0x0c0c5728 */
if(!s->budget--) { s->failed_pc=0x0c0c5728u; return 0; }
r[0]=0x00000060u;
goto P_0c0c572a;
P_0c0c572a: /* original f031, guest PC 0x0c0c572a */
if(!s->budget--) { s->failed_pc=0x0c0c572au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0c572c;
P_0c0c572c: /* original ff07, guest PC 0x0c0c572c */
if(!s->budget--) { s->failed_pc=0x0c0c572cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0c572e;
P_0c0c572e: /* original e020, guest PC 0x0c0c572e */
if(!s->budget--) { s->failed_pc=0x0c0c572eu; return 0; }
r[0]=0x00000020u;
goto P_0c0c5730;
P_0c0c5730: /* original 4b0b, guest PC 0x0c0c5730 */
if(!s->budget--) { s->failed_pc=0x0c0c5730u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c5734u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5734u) { target=s->pc; goto dispatch; }
goto P_0c0c5734;
P_0c0c5732: /* original 04fd, guest PC 0x0c0c5732 */
if(!s->budget--) { s->failed_pc=0x0c0c5732u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0c5734;
P_0c0c5734: /* original 6e03, guest PC 0x0c0c5734 */
if(!s->budget--) { s->failed_pc=0x0c0c5734u; return 0; }
r[14]=r[0];
goto P_0c0c5736;
P_0c0c5736: /* original 9020, guest PC 0x0c0c5736 */
if(!s->budget--) { s->failed_pc=0x0c0c5736u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c577au,2);
goto P_0c0c5738;
P_0c0c5738: /* original 941e, guest PC 0x0c0c5738 */
if(!s->budget--) { s->failed_pc=0x0c0c5738u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5778u,2);
goto P_0c0c573a;
P_0c0c573a: /* original f8f6, guest PC 0x0c0c573a */
if(!s->budget--) { s->failed_pc=0x0c0c573au; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c573c;
P_0c0c573c: /* original e01c, guest PC 0x0c0c573c */
if(!s->budget--) { s->failed_pc=0x0c0c573cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c573e;
P_0c0c573e: /* original f7e6, guest PC 0x0c0c573e */
if(!s->budget--) { s->failed_pc=0x0c0c573eu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c5740;
P_0c0c5740: /* original e018, guest PC 0x0c0c5740 */
if(!s->budget--) { s->failed_pc=0x0c0c5740u; return 0; }
r[0]=0x00000018u;
goto P_0c0c5742;
P_0c0c5742: /* original d31a, guest PC 0x0c0c5742 */
if(!s->budget--) { s->failed_pc=0x0c0c5742u; return 0; }
r[3]=read(ram,0x0c0c57acu,4);
goto P_0c0c5744;
P_0c0c5744: /* original f6e6, guest PC 0x0c0c5744 */
if(!s->budget--) { s->failed_pc=0x0c0c5744u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c5746;
P_0c0c5746: /* original f5fc, guest PC 0x0c0c5746 */
if(!s->budget--) { s->failed_pc=0x0c0c5746u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c5748;
P_0c0c5748: /* original f4fc, guest PC 0x0c0c5748 */
if(!s->budget--) { s->failed_pc=0x0c0c5748u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c574a;
P_0c0c574a: /* original 430b, guest PC 0x0c0c574a */
if(!s->budget--) { s->failed_pc=0x0c0c574au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c574eu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c574eu) { target=s->pc; goto dispatch; }
goto P_0c0c574e;
P_0c0c574c: /* original 34fc, guest PC 0x0c0c574c */
if(!s->budget--) { s->failed_pc=0x0c0c574cu; return 0; }
r[4]+=r[15];
goto P_0c0c574e;
P_0c0c574e: /* original e014, guest PC 0x0c0c574e */
if(!s->budget--) { s->failed_pc=0x0c0c574eu; return 0; }
r[0]=0x00000014u;
goto P_0c0c5750;
P_0c0c5750: /* original f9e6, guest PC 0x0c0c5750 */
if(!s->budget--) { s->failed_pc=0x0c0c5750u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c5752;
P_0c0c5752: /* original e010, guest PC 0x0c0c5752 */
if(!s->budget--) { s->failed_pc=0x0c0c5752u; return 0; }
r[0]=0x00000010u;
goto P_0c0c5754;
P_0c0c5754: /* original f8e6, guest PC 0x0c0c5754 */
if(!s->budget--) { s->failed_pc=0x0c0c5754u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c5756;
P_0c0c5756: /* original e00c, guest PC 0x0c0c5756 */
if(!s->budget--) { s->failed_pc=0x0c0c5756u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5758;
P_0c0c5758: /* original f7e6, guest PC 0x0c0c5758 */
if(!s->budget--) { s->failed_pc=0x0c0c5758u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c575a;
P_0c0c575a: /* original e008, guest PC 0x0c0c575a */
if(!s->budget--) { s->failed_pc=0x0c0c575au; return 0; }
r[0]=0x00000008u;
goto P_0c0c575c;
P_0c0c575c: /* original f6e6, guest PC 0x0c0c575c */
if(!s->budget--) { s->failed_pc=0x0c0c575cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c575e;
P_0c0c575e: /* original e004, guest PC 0x0c0c575e */
if(!s->budget--) { s->failed_pc=0x0c0c575eu; return 0; }
r[0]=0x00000004u;
goto P_0c0c5760;
P_0c0c5760: /* original f5e6, guest PC 0x0c0c5760 */
if(!s->budget--) { s->failed_pc=0x0c0c5760u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c5762;
P_0c0c5762: /* original a025, guest PC 0x0c0c5762 */
if(!s->budget--) { s->failed_pc=0x0c0c5762u; return 0; }
goto P_0c0c57b0;
P_0c0c5764: /* original 0009, guest PC 0x0c0c5764 */
if(!s->budget--) { s->failed_pc=0x0c0c5764u; return 0; }
if(!vf3_matrix_family(0x0c0c5766u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5766u; return 0; } return 1;
P_0c0c57b0: /* original 94a5, guest PC 0x0c0c57b0 */
if(!s->budget--) { s->failed_pc=0x0c0c57b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c58feu,2);
goto P_0c0c57b2;
P_0c0c57b2: /* original f4e8, guest PC 0x0c0c57b2 */
if(!s->budget--) { s->failed_pc=0x0c0c57b2u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c57b4;
P_0c0c57b4: /* original 480b, guest PC 0x0c0c57b4 */
if(!s->budget--) { s->failed_pc=0x0c0c57b4u; return 0; }
target=r[8];
r[16]=code_base|0x0c0c57b8u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c57b8u) { target=s->pc; goto dispatch; }
goto P_0c0c57b8;
P_0c0c57b6: /* original 34fc, guest PC 0x0c0c57b6 */
if(!s->budget--) { s->failed_pc=0x0c0c57b6u; return 0; }
r[4]+=r[15];
goto P_0c0c57b8;
P_0c0c57b8: /* original e00c, guest PC 0x0c0c57b8 */
if(!s->budget--) { s->failed_pc=0x0c0c57b8u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c57ba;
P_0c0c57ba: /* original f3e6, guest PC 0x0c0c57ba */
if(!s->budget--) { s->failed_pc=0x0c0c57bau; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c57bc;
P_0c0c57bc: /* original e01c, guest PC 0x0c0c57bc */
if(!s->budget--) { s->failed_pc=0x0c0c57bcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c57be;
P_0c0c57be: /* original f2e6, guest PC 0x0c0c57be */
if(!s->budget--) { s->failed_pc=0x0c0c57beu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c57c0;
P_0c0c57c0: /* original 909e, guest PC 0x0c0c57c0 */
if(!s->budget--) { s->failed_pc=0x0c0c57c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5900u,2);
goto P_0c0c57c2;
P_0c0c57c2: /* original f233, guest PC 0x0c0c57c2 */
if(!s->budget--) { s->failed_pc=0x0c0c57c2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c0c57c4;
P_0c0c57c4: /* original ff27, guest PC 0x0c0c57c4 */
if(!s->budget--) { s->failed_pc=0x0c0c57c4u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c57c6;
P_0c0c57c6: /* original e008, guest PC 0x0c0c57c6 */
if(!s->budget--) { s->failed_pc=0x0c0c57c6u; return 0; }
r[0]=0x00000008u;
goto P_0c0c57c8;
P_0c0c57c8: /* original f2e6, guest PC 0x0c0c57c8 */
if(!s->budget--) { s->failed_pc=0x0c0c57c8u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c57ca;
P_0c0c57ca: /* original e028, guest PC 0x0c0c57ca */
if(!s->budget--) { s->failed_pc=0x0c0c57cau; return 0; }
r[0]=0x00000028u;
goto P_0c0c57cc;
P_0c0c57cc: /* original f3a8, guest PC 0x0c0c57cc */
if(!s->budget--) { s->failed_pc=0x0c0c57ccu; return 0; }
vf3_matrix_load(s,ram,3,r[10]);
goto P_0c0c57ce;
P_0c0c57ce: /* original f232, guest PC 0x0c0c57ce */
if(!s->budget--) { s->failed_pc=0x0c0c57ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c57d0;
P_0c0c57d0: /* original ff27, guest PC 0x0c0c57d0 */
if(!s->budget--) { s->failed_pc=0x0c0c57d0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c57d2;
P_0c0c57d2: /* original c755, guest PC 0x0c0c57d2 */
if(!s->budget--) { s->failed_pc=0x0c0c57d2u; return 0; }
r[0]=code_base|0x000c5928u;
goto P_0c0c57d4;
P_0c0c57d4: /* original f308, guest PC 0x0c0c57d4 */
if(!s->budget--) { s->failed_pc=0x0c0c57d4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c57d6;
P_0c0c57d6: /* original 9093, guest PC 0x0c0c57d6 */
if(!s->budget--) { s->failed_pc=0x0c0c57d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5900u,2);
goto P_0c0c57d8;
P_0c0c57d8: /* original f1f6, guest PC 0x0c0c57d8 */
if(!s->budget--) { s->failed_pc=0x0c0c57d8u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c57da;
P_0c0c57da: /* original 9091, guest PC 0x0c0c57da */
if(!s->budget--) { s->failed_pc=0x0c0c57dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5900u,2);
goto P_0c0c57dc;
P_0c0c57dc: /* original f132, guest PC 0x0c0c57dc */
if(!s->budget--) { s->failed_pc=0x0c0c57dcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0c57de;
P_0c0c57de: /* original ff17, guest PC 0x0c0c57de */
if(!s->budget--) { s->failed_pc=0x0c0c57deu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c57e0;
P_0c0c57e0: /* original 53e8, guest PC 0x0c0c57e0 */
if(!s->budget--) { s->failed_pc=0x0c0c57e0u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c57e2;
P_0c0c57e2: /* original d052, guest PC 0x0c0c57e2 */
if(!s->budget--) { s->failed_pc=0x0c0c57e2u; return 0; }
r[0]=read(ram,0x0c0c592cu,4);
goto P_0c0c57e4;
P_0c0c57e4: /* original 4300, guest PC 0x0c0c57e4 */
if(!s->budget--) { s->failed_pc=0x0c0c57e4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c57e6;
P_0c0c57e6: /* original 023d, guest PC 0x0c0c57e6 */
if(!s->budget--) { s->failed_pc=0x0c0c57e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c57e8;
P_0c0c57e8: /* original 9089, guest PC 0x0c0c57e8 */
if(!s->budget--) { s->failed_pc=0x0c0c57e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c58feu,2);
goto P_0c0c57ea;
P_0c0c57ea: /* original 622d, guest PC 0x0c0c57ea */
if(!s->budget--) { s->failed_pc=0x0c0c57eau; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c57ec;
P_0c0c57ec: /* original 0f26, guest PC 0x0c0c57ec */
if(!s->budget--) { s->failed_pc=0x0c0c57ecu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c57ee;
P_0c0c57ee: /* original c750, guest PC 0x0c0c57ee */
if(!s->budget--) { s->failed_pc=0x0c0c57eeu; return 0; }
r[0]=code_base|0x000c5930u;
goto P_0c0c57f0;
P_0c0c57f0: /* original ffec, guest PC 0x0c0c57f0 */
if(!s->budget--) { s->failed_pc=0x0c0c57f0u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0c57f2;
P_0c0c57f2: /* original a07c, guest PC 0x0c0c57f2 */
if(!s->budget--) { s->failed_pc=0x0c0c57f2u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c58ee;
P_0c0c57f4: /* original fe08, guest PC 0x0c0c57f4 */
if(!s->budget--) { s->failed_pc=0x0c0c57f4u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c57f6;
P_0c0c57f6: /* original 9084, guest PC 0x0c0c57f6 */
if(!s->budget--) { s->failed_pc=0x0c0c57f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5902u,2);
goto P_0c0c57f8;
P_0c0c57f8: /* original ffd7, guest PC 0x0c0c57f8 */
if(!s->budget--) { s->failed_pc=0x0c0c57f8u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c57fa;
P_0c0c57fa: /* original e00c, guest PC 0x0c0c57fa */
if(!s->budget--) { s->failed_pc=0x0c0c57fau; return 0; }
r[0]=0x0000000cu;
goto P_0c0c57fc;
P_0c0c57fc: /* original f3f6, guest PC 0x0c0c57fc */
if(!s->budget--) { s->failed_pc=0x0c0c57fcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c57fe;
P_0c0c57fe: /* original 9081, guest PC 0x0c0c57fe */
if(!s->budget--) { s->failed_pc=0x0c0c57feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5904u,2);
goto P_0c0c5800;
P_0c0c5800: /* original ff37, guest PC 0x0c0c5800 */
if(!s->budget--) { s->failed_pc=0x0c0c5800u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5802;
P_0c0c5802: /* original e008, guest PC 0x0c0c5802 */
if(!s->budget--) { s->failed_pc=0x0c0c5802u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5804;
P_0c0c5804: /* original f3f6, guest PC 0x0c0c5804 */
if(!s->budget--) { s->failed_pc=0x0c0c5804u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5806;
P_0c0c5806: /* original 907e, guest PC 0x0c0c5806 */
if(!s->budget--) { s->failed_pc=0x0c0c5806u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5906u,2);
goto P_0c0c5808;
P_0c0c5808: /* original ff37, guest PC 0x0c0c5808 */
if(!s->budget--) { s->failed_pc=0x0c0c5808u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c580a;
P_0c0c580a: /* original 907d, guest PC 0x0c0c580a */
if(!s->budget--) { s->failed_pc=0x0c0c580au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5908u,2);
goto P_0c0c580c;
P_0c0c580c: /* original ffd7, guest PC 0x0c0c580c */
if(!s->budget--) { s->failed_pc=0x0c0c580cu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c580e;
P_0c0c580e: /* original e070, guest PC 0x0c0c580e */
if(!s->budget--) { s->failed_pc=0x0c0c580eu; return 0; }
r[0]=0x00000070u;
goto P_0c0c5810;
P_0c0c5810: /* original ffd7, guest PC 0x0c0c5810 */
if(!s->budget--) { s->failed_pc=0x0c0c5810u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c5812;
P_0c0c5812: /* original e004, guest PC 0x0c0c5812 */
if(!s->budget--) { s->failed_pc=0x0c0c5812u; return 0; }
r[0]=0x00000004u;
goto P_0c0c5814;
P_0c0c5814: /* original f4f6, guest PC 0x0c0c5814 */
if(!s->budget--) { s->failed_pc=0x0c0c5814u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c5816;
P_0c0c5816: /* original e00c, guest PC 0x0c0c5816 */
if(!s->budget--) { s->failed_pc=0x0c0c5816u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5818;
P_0c0c5818: /* original f3f6, guest PC 0x0c0c5818 */
if(!s->budget--) { s->failed_pc=0x0c0c5818u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c581a;
P_0c0c581a: /* original e00c, guest PC 0x0c0c581a */
if(!s->budget--) { s->failed_pc=0x0c0c581au; return 0; }
r[0]=0x0000000cu;
goto P_0c0c581c;
P_0c0c581c: /* original f340, guest PC 0x0c0c581c */
if(!s->budget--) { s->failed_pc=0x0c0c581cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c0c581e;
P_0c0c581e: /* original ff37, guest PC 0x0c0c581e */
if(!s->budget--) { s->failed_pc=0x0c0c581eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5820;
P_0c0c5820: /* original e008, guest PC 0x0c0c5820 */
if(!s->budget--) { s->failed_pc=0x0c0c5820u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5822;
P_0c0c5822: /* original f2f6, guest PC 0x0c0c5822 */
if(!s->budget--) { s->failed_pc=0x0c0c5822u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5824;
P_0c0c5824: /* original e008, guest PC 0x0c0c5824 */
if(!s->budget--) { s->failed_pc=0x0c0c5824u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5826;
P_0c0c5826: /* original f240, guest PC 0x0c0c5826 */
if(!s->budget--) { s->failed_pc=0x0c0c5826u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0c5828;
P_0c0c5828: /* original ff27, guest PC 0x0c0c5828 */
if(!s->budget--) { s->failed_pc=0x0c0c5828u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c582a;
P_0c0c582a: /* original c742, guest PC 0x0c0c582a */
if(!s->budget--) { s->failed_pc=0x0c0c582au; return 0; }
r[0]=code_base|0x000c5934u;
goto P_0c0c582c;
P_0c0c582c: /* original f108, guest PC 0x0c0c582c */
if(!s->budget--) { s->failed_pc=0x0c0c582cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c582e;
P_0c0c582e: /* original f1f5, guest PC 0x0c0c582e */
if(!s->budget--) { s->failed_pc=0x0c0c582eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[15]))!=0);
goto P_0c0c5830;
P_0c0c5830: /* original 8d5a, guest PC 0x0c0c5830 */
if(!s->budget--) { s->failed_pc=0x0c0c5830u; return 0; }
cond=r[17]&1u;
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'+');
if(cond) { goto P_0c0c58e8; }
goto P_0c0c5834;
P_0c0c5832: /* original fd40, guest PC 0x0c0c5832 */
if(!s->budget--) { s->failed_pc=0x0c0c5832u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'+');
goto P_0c0c5834;
P_0c0c5834: /* original f38d, guest PC 0x0c0c5834 */
if(!s->budget--) { s->failed_pc=0x0c0c5834u; return 0; }
fr[3]=0;
goto P_0c0c5836;
P_0c0c5836: /* original f3f5, guest PC 0x0c0c5836 */
if(!s->budget--) { s->failed_pc=0x0c0c5836u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c5838;
P_0c0c5838: /* original 8b01, guest PC 0x0c0c5838 */
if(!s->budget--) { s->failed_pc=0x0c0c5838u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c583e; }
goto P_0c0c583a;
P_0c0c583a: /* original a004, guest PC 0x0c0c583a */
if(!s->budget--) { s->failed_pc=0x0c0c583au; return 0; }
r[4]=r[12];
goto P_0c0c5846;
P_0c0c583c: /* original 64c3, guest PC 0x0c0c583c */
if(!s->budget--) { s->failed_pc=0x0c0c583cu; return 0; }
r[4]=r[12];
goto P_0c0c583e;
P_0c0c583e: /* original f3fc, guest PC 0x0c0c583e */
if(!s->budget--) { s->failed_pc=0x0c0c583eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0c5840;
P_0c0c5840: /* original f3c2, guest PC 0x0c0c5840 */
if(!s->budget--) { s->failed_pc=0x0c0c5840u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0c5842;
P_0c0c5842: /* original f33d, guest PC 0x0c0c5842 */
if(!s->budget--) { s->failed_pc=0x0c0c5842u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c5844;
P_0c0c5844: /* original 045a, guest PC 0x0c0c5844 */
if(!s->budget--) { s->failed_pc=0x0c0c5844u; return 0; }
r[4]=r[53];
goto P_0c0c5846;
P_0c0c5846: /* original 9060, guest PC 0x0c0c5846 */
if(!s->budget--) { s->failed_pc=0x0c0c5846u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c590au,2);
goto P_0c0c5848;
P_0c0c5848: /* original ffd7, guest PC 0x0c0c5848 */
if(!s->budget--) { s->failed_pc=0x0c0c5848u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c584a;
P_0c0c584a: /* original e00c, guest PC 0x0c0c584a */
if(!s->budget--) { s->failed_pc=0x0c0c584au; return 0; }
r[0]=0x0000000cu;
goto P_0c0c584c;
P_0c0c584c: /* original f3f6, guest PC 0x0c0c584c */
if(!s->budget--) { s->failed_pc=0x0c0c584cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c584e;
P_0c0c584e: /* original 905d, guest PC 0x0c0c584e */
if(!s->budget--) { s->failed_pc=0x0c0c584eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c590cu,2);
goto P_0c0c5850;
P_0c0c5850: /* original ff37, guest PC 0x0c0c5850 */
if(!s->budget--) { s->failed_pc=0x0c0c5850u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5852;
P_0c0c5852: /* original e008, guest PC 0x0c0c5852 */
if(!s->budget--) { s->failed_pc=0x0c0c5852u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5854;
P_0c0c5854: /* original f3f6, guest PC 0x0c0c5854 */
if(!s->budget--) { s->failed_pc=0x0c0c5854u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5856;
P_0c0c5856: /* original 905a, guest PC 0x0c0c5856 */
if(!s->budget--) { s->failed_pc=0x0c0c5856u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c590eu,2);
goto P_0c0c5858;
P_0c0c5858: /* original ff37, guest PC 0x0c0c5858 */
if(!s->budget--) { s->failed_pc=0x0c0c5858u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c585a;
P_0c0c585a: /* original 9059, guest PC 0x0c0c585a */
if(!s->budget--) { s->failed_pc=0x0c0c585au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5910u,2);
goto P_0c0c585c;
P_0c0c585c: /* original ffd7, guest PC 0x0c0c585c */
if(!s->budget--) { s->failed_pc=0x0c0c585cu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c585e;
P_0c0c585e: /* original e078, guest PC 0x0c0c585e */
if(!s->budget--) { s->failed_pc=0x0c0c585eu; return 0; }
r[0]=0x00000078u;
goto P_0c0c5860;
P_0c0c5860: /* original ffd7, guest PC 0x0c0c5860 */
if(!s->budget--) { s->failed_pc=0x0c0c5860u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c5862;
P_0c0c5862: /* original 9056, guest PC 0x0c0c5862 */
if(!s->budget--) { s->failed_pc=0x0c0c5862u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5912u,2);
goto P_0c0c5864;
P_0c0c5864: /* original f3f6, guest PC 0x0c0c5864 */
if(!s->budget--) { s->failed_pc=0x0c0c5864u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5866;
P_0c0c5866: /* original e02c, guest PC 0x0c0c5866 */
if(!s->budget--) { s->failed_pc=0x0c0c5866u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c5868;
P_0c0c5868: /* original ff37, guest PC 0x0c0c5868 */
if(!s->budget--) { s->failed_pc=0x0c0c5868u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c586a;
P_0c0c586a: /* original 6043, guest PC 0x0c0c586a */
if(!s->budget--) { s->failed_pc=0x0c0c586au; return 0; }
r[0]=r[4];
goto P_0c0c586c;
P_0c0c586c: /* original 4000, guest PC 0x0c0c586c */
if(!s->budget--) { s->failed_pc=0x0c0c586cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c586e;
P_0c0c586e: /* original 039d, guest PC 0x0c0c586e */
if(!s->budget--) { s->failed_pc=0x0c0c586eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[9]+r[0],2);
goto P_0c0c5870;
P_0c0c5870: /* original 904f, guest PC 0x0c0c5870 */
if(!s->budget--) { s->failed_pc=0x0c0c5870u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5912u,2);
goto P_0c0c5872;
P_0c0c5872: /* original 435a, guest PC 0x0c0c5872 */
if(!s->budget--) { s->failed_pc=0x0c0c5872u; return 0; }
r[53]=r[3];
goto P_0c0c5874;
P_0c0c5874: /* original f2f6, guest PC 0x0c0c5874 */
if(!s->budget--) { s->failed_pc=0x0c0c5874u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5876;
P_0c0c5876: /* original 904c, guest PC 0x0c0c5876 */
if(!s->budget--) { s->failed_pc=0x0c0c5876u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5912u,2);
goto P_0c0c5878;
P_0c0c5878: /* original f32d, guest PC 0x0c0c5878 */
if(!s->budget--) { s->failed_pc=0x0c0c5878u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c587a;
P_0c0c587a: /* original f230, guest PC 0x0c0c587a */
if(!s->budget--) { s->failed_pc=0x0c0c587au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c587c;
P_0c0c587c: /* original ff27, guest PC 0x0c0c587c */
if(!s->budget--) { s->failed_pc=0x0c0c587cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c587e;
P_0c0c587e: /* original e010, guest PC 0x0c0c587e */
if(!s->budget--) { s->failed_pc=0x0c0c587eu; return 0; }
r[0]=0x00000010u;
goto P_0c0c5880;
P_0c0c5880: /* original f3f6, guest PC 0x0c0c5880 */
if(!s->budget--) { s->failed_pc=0x0c0c5880u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5882;
P_0c0c5882: /* original f230, guest PC 0x0c0c5882 */
if(!s->budget--) { s->failed_pc=0x0c0c5882u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5884;
P_0c0c5884: /* original f2e0, guest PC 0x0c0c5884 */
if(!s->budget--) { s->failed_pc=0x0c0c5884u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'+');
goto P_0c0c5886;
P_0c0c5886: /* original 9045, guest PC 0x0c0c5886 */
if(!s->budget--) { s->failed_pc=0x0c0c5886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5914u,2);
goto P_0c0c5888;
P_0c0c5888: /* original ff27, guest PC 0x0c0c5888 */
if(!s->budget--) { s->failed_pc=0x0c0c5888u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c588a;
P_0c0c588a: /* original f230, guest PC 0x0c0c588a */
if(!s->budget--) { s->failed_pc=0x0c0c588au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c588c;
P_0c0c588c: /* original 9043, guest PC 0x0c0c588c */
if(!s->budget--) { s->failed_pc=0x0c0c588cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5916u,2);
goto P_0c0c588e;
P_0c0c588e: /* original f2e0, guest PC 0x0c0c588e */
if(!s->budget--) { s->failed_pc=0x0c0c588eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'+');
goto P_0c0c5890;
P_0c0c5890: /* original ff27, guest PC 0x0c0c5890 */
if(!s->budget--) { s->failed_pc=0x0c0c5890u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5892;
P_0c0c5892: /* original e010, guest PC 0x0c0c5892 */
if(!s->budget--) { s->failed_pc=0x0c0c5892u; return 0; }
r[0]=0x00000010u;
goto P_0c0c5894;
P_0c0c5894: /* original f3f6, guest PC 0x0c0c5894 */
if(!s->budget--) { s->failed_pc=0x0c0c5894u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5896;
P_0c0c5896: /* original 903f, guest PC 0x0c0c5896 */
if(!s->budget--) { s->failed_pc=0x0c0c5896u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5918u,2);
goto P_0c0c5898;
P_0c0c5898: /* original f230, guest PC 0x0c0c5898 */
if(!s->budget--) { s->failed_pc=0x0c0c5898u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c589a;
P_0c0c589a: /* original f2e0, guest PC 0x0c0c589a */
if(!s->budget--) { s->failed_pc=0x0c0c589au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'+');
goto P_0c0c589c;
P_0c0c589c: /* original ff27, guest PC 0x0c0c589c */
if(!s->budget--) { s->failed_pc=0x0c0c589cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c589e;
P_0c0c589e: /* original e028, guest PC 0x0c0c589e */
if(!s->budget--) { s->failed_pc=0x0c0c589eu; return 0; }
r[0]=0x00000028u;
goto P_0c0c58a0;
P_0c0c58a0: /* original f2f6, guest PC 0x0c0c58a0 */
if(!s->budget--) { s->failed_pc=0x0c0c58a0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c58a2;
P_0c0c58a2: /* original 9039, guest PC 0x0c0c58a2 */
if(!s->budget--) { s->failed_pc=0x0c0c58a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5918u,2);
goto P_0c0c58a4;
P_0c0c58a4: /* original f1f6, guest PC 0x0c0c58a4 */
if(!s->budget--) { s->failed_pc=0x0c0c58a4u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c58a6;
P_0c0c58a6: /* original e058, guest PC 0x0c0c58a6 */
if(!s->budget--) { s->failed_pc=0x0c0c58a6u; return 0; }
r[0]=0x00000058u;
goto P_0c0c58a8;
P_0c0c58a8: /* original f120, guest PC 0x0c0c58a8 */
if(!s->budget--) { s->failed_pc=0x0c0c58a8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c0c58aa;
P_0c0c58aa: /* original f1e0, guest PC 0x0c0c58aa */
if(!s->budget--) { s->failed_pc=0x0c0c58aau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[14],r[18],'+');
goto P_0c0c58ac;
P_0c0c58ac: /* original ff17, guest PC 0x0c0c58ac */
if(!s->budget--) { s->failed_pc=0x0c0c58acu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c58ae;
P_0c0c58ae: /* original 9034, guest PC 0x0c0c58ae */
if(!s->budget--) { s->failed_pc=0x0c0c58aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c591au,2);
goto P_0c0c58b0;
P_0c0c58b0: /* original fff7, guest PC 0x0c0c58b0 */
if(!s->budget--) { s->failed_pc=0x0c0c58b0u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58b2;
P_0c0c58b2: /* original 9033, guest PC 0x0c0c58b2 */
if(!s->budget--) { s->failed_pc=0x0c0c58b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c591cu,2);
goto P_0c0c58b4;
P_0c0c58b4: /* original fff7, guest PC 0x0c0c58b4 */
if(!s->budget--) { s->failed_pc=0x0c0c58b4u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58b6;
P_0c0c58b6: /* original 9032, guest PC 0x0c0c58b6 */
if(!s->budget--) { s->failed_pc=0x0c0c58b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c591eu,2);
goto P_0c0c58b8;
P_0c0c58b8: /* original fff7, guest PC 0x0c0c58b8 */
if(!s->budget--) { s->failed_pc=0x0c0c58b8u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58ba;
P_0c0c58ba: /* original 9031, guest PC 0x0c0c58ba */
if(!s->budget--) { s->failed_pc=0x0c0c58bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5920u,2);
goto P_0c0c58bc;
P_0c0c58bc: /* original fff7, guest PC 0x0c0c58bc */
if(!s->budget--) { s->failed_pc=0x0c0c58bcu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58be;
P_0c0c58be: /* original e05c, guest PC 0x0c0c58be */
if(!s->budget--) { s->failed_pc=0x0c0c58beu; return 0; }
r[0]=0x0000005cu;
goto P_0c0c58c0;
P_0c0c58c0: /* original fff7, guest PC 0x0c0c58c0 */
if(!s->budget--) { s->failed_pc=0x0c0c58c0u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58c2;
P_0c0c58c2: /* original 942e, guest PC 0x0c0c58c2 */
if(!s->budget--) { s->failed_pc=0x0c0c58c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5922u,2);
goto P_0c0c58c4;
P_0c0c58c4: /* original 4d0b, guest PC 0x0c0c58c4 */
if(!s->budget--) { s->failed_pc=0x0c0c58c4u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c58c8u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c58c8u) { target=s->pc; goto dispatch; }
goto P_0c0c58c8;
P_0c0c58c6: /* original 34fc, guest PC 0x0c0c58c6 */
if(!s->budget--) { s->failed_pc=0x0c0c58c6u; return 0; }
r[4]+=r[15];
goto P_0c0c58c8;
P_0c0c58c8: /* original 942c, guest PC 0x0c0c58c8 */
if(!s->budget--) { s->failed_pc=0x0c0c58c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5924u,2);
goto P_0c0c58ca;
P_0c0c58ca: /* original 4d0b, guest PC 0x0c0c58ca */
if(!s->budget--) { s->failed_pc=0x0c0c58cau; return 0; }
target=r[13];
r[16]=code_base|0x0c0c58ceu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c58ceu) { target=s->pc; goto dispatch; }
goto P_0c0c58ce;
P_0c0c58cc: /* original 34fc, guest PC 0x0c0c58cc */
if(!s->budget--) { s->failed_pc=0x0c0c58ccu; return 0; }
r[4]+=r[15];
goto P_0c0c58ce;
P_0c0c58ce: /* original 942a, guest PC 0x0c0c58ce */
if(!s->budget--) { s->failed_pc=0x0c0c58ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5926u,2);
goto P_0c0c58d0;
P_0c0c58d0: /* original 4d0b, guest PC 0x0c0c58d0 */
if(!s->budget--) { s->failed_pc=0x0c0c58d0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c58d4u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c58d4u) { target=s->pc; goto dispatch; }
goto P_0c0c58d4;
P_0c0c58d2: /* original 34fc, guest PC 0x0c0c58d2 */
if(!s->budget--) { s->failed_pc=0x0c0c58d2u; return 0; }
r[4]+=r[15];
goto P_0c0c58d4;
P_0c0c58d4: /* original 9413, guest PC 0x0c0c58d4 */
if(!s->budget--) { s->failed_pc=0x0c0c58d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c58feu,2);
goto P_0c0c58d6;
P_0c0c58d6: /* original 4d0b, guest PC 0x0c0c58d6 */
if(!s->budget--) { s->failed_pc=0x0c0c58d6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c58dau;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c58dau) { target=s->pc; goto dispatch; }
goto P_0c0c58da;
P_0c0c58d8: /* original 34fc, guest PC 0x0c0c58d8 */
if(!s->budget--) { s->failed_pc=0x0c0c58d8u; return 0; }
r[4]+=r[15];
goto P_0c0c58da;
P_0c0c58da: /* original 64f3, guest PC 0x0c0c58da */
if(!s->budget--) { s->failed_pc=0x0c0c58dau; return 0; }
r[4]=r[15];
goto P_0c0c58dc;
P_0c0c58dc: /* original 4d0b, guest PC 0x0c0c58dc */
if(!s->budget--) { s->failed_pc=0x0c0c58dcu; return 0; }
target=r[13];
r[16]=code_base|0x0c0c58e0u;
r[4]+=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c58e0u) { target=s->pc; goto dispatch; }
goto P_0c0c58e0;
P_0c0c58de: /* original 7454, guest PC 0x0c0c58de */
if(!s->budget--) { s->failed_pc=0x0c0c58deu; return 0; }
r[4]+=0x00000054u;
goto P_0c0c58e0;
P_0c0c58e0: /* original e02c, guest PC 0x0c0c58e0 */
if(!s->budget--) { s->failed_pc=0x0c0c58e0u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c58e2;
P_0c0c58e2: /* original f3f6, guest PC 0x0c0c58e2 */
if(!s->budget--) { s->failed_pc=0x0c0c58e2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c58e4;
P_0c0c58e4: /* original 9015, guest PC 0x0c0c58e4 */
if(!s->budget--) { s->failed_pc=0x0c0c58e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5912u,2);
goto P_0c0c58e6;
P_0c0c58e6: /* original ff37, guest PC 0x0c0c58e6 */
if(!s->budget--) { s->failed_pc=0x0c0c58e6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c58e8;
P_0c0c58e8: /* original c70f, guest PC 0x0c0c58e8 */
if(!s->budget--) { s->failed_pc=0x0c0c58e8u; return 0; }
r[0]=code_base|0x000c5928u;
goto P_0c0c58ea;
P_0c0c58ea: /* original f308, guest PC 0x0c0c58ea */
if(!s->budget--) { s->failed_pc=0x0c0c58eau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c58ec;
P_0c0c58ec: /* original ff30, guest PC 0x0c0c58ec */
if(!s->budget--) { s->failed_pc=0x0c0c58ecu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0c58ee;
P_0c0c58ee: /* original e01c, guest PC 0x0c0c58ee */
if(!s->budget--) { s->failed_pc=0x0c0c58eeu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c58f0;
P_0c0c58f0: /* original f3f6, guest PC 0x0c0c58f0 */
if(!s->budget--) { s->failed_pc=0x0c0c58f0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c58f2;
P_0c0c58f2: /* original ff35, guest PC 0x0c0c58f2 */
if(!s->budget--) { s->failed_pc=0x0c0c58f2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0c58f4;
P_0c0c58f4: /* original 8901, guest PC 0x0c0c58f4 */
if(!s->budget--) { s->failed_pc=0x0c0c58f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c58fa; }
goto P_0c0c58f6;
P_0c0c58f6: /* original af7e, guest PC 0x0c0c58f6 */
if(!s->budget--) { s->failed_pc=0x0c0c58f6u; return 0; }
goto P_0c0c57f6;
P_0c0c58f8: /* original 0009, guest PC 0x0c0c58f8 */
if(!s->budget--) { s->failed_pc=0x0c0c58f8u; return 0; }
goto P_0c0c58fa;
P_0c0c58fa: /* original a097, guest PC 0x0c0c58fa */
if(!s->budget--) { s->failed_pc=0x0c0c58fau; return 0; }
goto P_0c0c5a2c;
P_0c0c58fc: /* original 0009, guest PC 0x0c0c58fc */
if(!s->budget--) { s->failed_pc=0x0c0c58fcu; return 0; }
if(!vf3_matrix_family(0x0c0c58feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c58feu; return 0; } return 1;
P_0c0c5938: /* original e008, guest PC 0x0c0c5938 */
if(!s->budget--) { s->failed_pc=0x0c0c5938u; return 0; }
r[0]=0x00000008u;
goto P_0c0c593a;
P_0c0c593a: /* original fe45, guest PC 0x0c0c593a */
if(!s->budget--) { s->failed_pc=0x0c0c593au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0c593c;
P_0c0c593c: /* original f3e6, guest PC 0x0c0c593c */
if(!s->budget--) { s->failed_pc=0x0c0c593cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c593e;
P_0c0c593e: /* original e024, guest PC 0x0c0c593e */
if(!s->budget--) { s->failed_pc=0x0c0c593eu; return 0; }
r[0]=0x00000024u;
goto P_0c0c5940;
P_0c0c5940: /* original f362, guest PC 0x0c0c5940 */
if(!s->budget--) { s->failed_pc=0x0c0c5940u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0c5942;
P_0c0c5942: /* original ff37, guest PC 0x0c0c5942 */
if(!s->budget--) { s->failed_pc=0x0c0c5942u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5944;
P_0c0c5944: /* original e014, guest PC 0x0c0c5944 */
if(!s->budget--) { s->failed_pc=0x0c0c5944u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5946;
P_0c0c5946: /* original f8e6, guest PC 0x0c0c5946 */
if(!s->budget--) { s->failed_pc=0x0c0c5946u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c5948;
P_0c0c5948: /* original e00c, guest PC 0x0c0c5948 */
if(!s->budget--) { s->failed_pc=0x0c0c5948u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c594a;
P_0c0c594a: /* original f6e6, guest PC 0x0c0c594a */
if(!s->budget--) { s->failed_pc=0x0c0c594au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c594c;
P_0c0c594c: /* original e014, guest PC 0x0c0c594c */
if(!s->budget--) { s->failed_pc=0x0c0c594cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c594e;
P_0c0c594e: /* original f3ec, guest PC 0x0c0c594e */
if(!s->budget--) { s->failed_pc=0x0c0c594eu; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0c5950;
P_0c0c5950: /* original f06c, guest PC 0x0c0c5950 */
if(!s->budget--) { s->failed_pc=0x0c0c5950u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0c5952;
P_0c0c5952: /* original f35e, guest PC 0x0c0c5952 */
if(!s->budget--) { s->failed_pc=0x0c0c5952u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0c5954;
P_0c0c5954: /* original ff37, guest PC 0x0c0c5954 */
if(!s->budget--) { s->failed_pc=0x0c0c5954u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5956;
P_0c0c5956: /* original f3e1, guest PC 0x0c0c5956 */
if(!s->budget--) { s->failed_pc=0x0c0c5956u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'-');
goto P_0c0c5958;
P_0c0c5958: /* original f20c, guest PC 0x0c0c5958 */
if(!s->budget--) { s->failed_pc=0x0c0c5958u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0c595a;
P_0c0c595a: /* original e034, guest PC 0x0c0c595a */
if(!s->budget--) { s->failed_pc=0x0c0c595au; return 0; }
r[0]=0x00000034u;
goto P_0c0c595c;
P_0c0c595c: /* original f370, guest PC 0x0c0c595c */
if(!s->budget--) { s->failed_pc=0x0c0c595cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c0c595e;
P_0c0c595e: /* original f233, guest PC 0x0c0c595e */
if(!s->budget--) { s->failed_pc=0x0c0c595eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c0c5960;
P_0c0c5960: /* original f282, guest PC 0x0c0c5960 */
if(!s->budget--) { s->failed_pc=0x0c0c5960u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c0c5962;
P_0c0c5962: /* original ff27, guest PC 0x0c0c5962 */
if(!s->budget--) { s->failed_pc=0x0c0c5962u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5964;
P_0c0c5964: /* original e01c, guest PC 0x0c0c5964 */
if(!s->budget--) { s->failed_pc=0x0c0c5964u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5966;
P_0c0c5966: /* original f3e6, guest PC 0x0c0c5966 */
if(!s->budget--) { s->failed_pc=0x0c0c5966u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c5968;
P_0c0c5968: /* original 9076, guest PC 0x0c0c5968 */
if(!s->budget--) { s->failed_pc=0x0c0c5968u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a58u,2);
goto P_0c0c596a;
P_0c0c596a: /* original f363, guest PC 0x0c0c596a */
if(!s->budget--) { s->failed_pc=0x0c0c596au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'/');
goto P_0c0c596c;
P_0c0c596c: /* original ff37, guest PC 0x0c0c596c */
if(!s->budget--) { s->failed_pc=0x0c0c596cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c596e;
P_0c0c596e: /* original 9074, guest PC 0x0c0c596e */
if(!s->budget--) { s->failed_pc=0x0c0c596eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5au,2);
goto P_0c0c5970;
P_0c0c5970: /* original 8d5c, guest PC 0x0c0c5970 */
if(!s->budget--) { s->failed_pc=0x0c0c5970u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,13,r[15]+r[0]);
if(cond) { goto P_0c0c5a2c; }
goto P_0c0c5974;
P_0c0c5972: /* original fdf6, guest PC 0x0c0c5972 */
if(!s->budget--) { s->failed_pc=0x0c0c5972u; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0c5974;
P_0c0c5974: /* original e014, guest PC 0x0c0c5974 */
if(!s->budget--) { s->failed_pc=0x0c0c5974u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5976;
P_0c0c5976: /* original f39d, guest PC 0x0c0c5976 */
if(!s->budget--) { s->failed_pc=0x0c0c5976u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c5978;
P_0c0c5978: /* original f2f6, guest PC 0x0c0c5978 */
if(!s->budget--) { s->failed_pc=0x0c0c5978u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c597a;
P_0c0c597a: /* original f325, guest PC 0x0c0c597a */
if(!s->budget--) { s->failed_pc=0x0c0c597au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0c597c;
P_0c0c597c: /* original 8956, guest PC 0x0c0c597c */
if(!s->budget--) { s->failed_pc=0x0c0c597cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5a2c; }
goto P_0c0c597e;
P_0c0c597e: /* original c73a, guest PC 0x0c0c597e */
if(!s->budget--) { s->failed_pc=0x0c0c597eu; return 0; }
r[0]=code_base|0x000c5a68u;
goto P_0c0c5980;
P_0c0c5980: /* original f308, guest PC 0x0c0c5980 */
if(!s->budget--) { s->failed_pc=0x0c0c5980u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5982;
P_0c0c5982: /* original e034, guest PC 0x0c0c5982 */
if(!s->budget--) { s->failed_pc=0x0c0c5982u; return 0; }
r[0]=0x00000034u;
goto P_0c0c5984;
P_0c0c5984: /* original f2f6, guest PC 0x0c0c5984 */
if(!s->budget--) { s->failed_pc=0x0c0c5984u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5986;
P_0c0c5986: /* original e034, guest PC 0x0c0c5986 */
if(!s->budget--) { s->failed_pc=0x0c0c5986u; return 0; }
r[0]=0x00000034u;
goto P_0c0c5988;
P_0c0c5988: /* original f232, guest PC 0x0c0c5988 */
if(!s->budget--) { s->failed_pc=0x0c0c5988u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c598a;
P_0c0c598a: /* original ff27, guest PC 0x0c0c598a */
if(!s->budget--) { s->failed_pc=0x0c0c598au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c598c;
P_0c0c598c: /* original 9064, guest PC 0x0c0c598c */
if(!s->budget--) { s->failed_pc=0x0c0c598cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a58u,2);
goto P_0c0c598e;
P_0c0c598e: /* original f1f6, guest PC 0x0c0c598e */
if(!s->budget--) { s->failed_pc=0x0c0c598eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c5990;
P_0c0c5990: /* original 9062, guest PC 0x0c0c5990 */
if(!s->budget--) { s->failed_pc=0x0c0c5990u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a58u,2);
goto P_0c0c5992;
P_0c0c5992: /* original f132, guest PC 0x0c0c5992 */
if(!s->budget--) { s->failed_pc=0x0c0c5992u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0c5994;
P_0c0c5994: /* original ff17, guest PC 0x0c0c5994 */
if(!s->budget--) { s->failed_pc=0x0c0c5994u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c5996;
P_0c0c5996: /* original a045, guest PC 0x0c0c5996 */
if(!s->budget--) { s->failed_pc=0x0c0c5996u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0c5a24;
P_0c0c5998: /* original ffec, guest PC 0x0c0c5998 */
if(!s->budget--) { s->failed_pc=0x0c0c5998u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0c599a;
P_0c0c599a: /* original 905e, guest PC 0x0c0c599a */
if(!s->budget--) { s->failed_pc=0x0c0c599au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5au,2);
goto P_0c0c599c;
P_0c0c599c: /* original ffd7, guest PC 0x0c0c599c */
if(!s->budget--) { s->failed_pc=0x0c0c599cu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c599e;
P_0c0c599e: /* original e034, guest PC 0x0c0c599e */
if(!s->budget--) { s->failed_pc=0x0c0c599eu; return 0; }
r[0]=0x00000034u;
goto P_0c0c59a0;
P_0c0c59a0: /* original f3f6, guest PC 0x0c0c59a0 */
if(!s->budget--) { s->failed_pc=0x0c0c59a0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c59a2;
P_0c0c59a2: /* original c732, guest PC 0x0c0c59a2 */
if(!s->budget--) { s->failed_pc=0x0c0c59a2u; return 0; }
r[0]=code_base|0x000c5a6cu;
goto P_0c0c59a4;
P_0c0c59a4: /* original f408, guest PC 0x0c0c59a4 */
if(!s->budget--) { s->failed_pc=0x0c0c59a4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c59a6;
P_0c0c59a6: /* original f4f5, guest PC 0x0c0c59a6 */
if(!s->budget--) { s->failed_pc=0x0c0c59a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c0c59a8;
P_0c0c59a8: /* original 8d39, guest PC 0x0c0c59a8 */
if(!s->budget--) { s->failed_pc=0x0c0c59a8u; return 0; }
cond=r[17]&1u;
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
if(cond) { goto P_0c0c5a1e; }
goto P_0c0c59ac;
P_0c0c59aa: /* original fd30, guest PC 0x0c0c59aa */
if(!s->budget--) { s->failed_pc=0x0c0c59aau; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c0c59ac;
P_0c0c59ac: /* original f38d, guest PC 0x0c0c59ac */
if(!s->budget--) { s->failed_pc=0x0c0c59acu; return 0; }
fr[3]=0;
goto P_0c0c59ae;
P_0c0c59ae: /* original f3f5, guest PC 0x0c0c59ae */
if(!s->budget--) { s->failed_pc=0x0c0c59aeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c59b0;
P_0c0c59b0: /* original 8b01, guest PC 0x0c0c59b0 */
if(!s->budget--) { s->failed_pc=0x0c0c59b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c59b6; }
goto P_0c0c59b2;
P_0c0c59b2: /* original a004, guest PC 0x0c0c59b2 */
if(!s->budget--) { s->failed_pc=0x0c0c59b2u; return 0; }
r[4]=r[12];
goto P_0c0c59be;
P_0c0c59b4: /* original 64c3, guest PC 0x0c0c59b4 */
if(!s->budget--) { s->failed_pc=0x0c0c59b4u; return 0; }
r[4]=r[12];
goto P_0c0c59b6;
P_0c0c59b6: /* original f3fc, guest PC 0x0c0c59b6 */
if(!s->budget--) { s->failed_pc=0x0c0c59b6u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0c59b8;
P_0c0c59b8: /* original f3c2, guest PC 0x0c0c59b8 */
if(!s->budget--) { s->failed_pc=0x0c0c59b8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0c59ba;
P_0c0c59ba: /* original f33d, guest PC 0x0c0c59ba */
if(!s->budget--) { s->failed_pc=0x0c0c59bau; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c59bc;
P_0c0c59bc: /* original 045a, guest PC 0x0c0c59bc */
if(!s->budget--) { s->failed_pc=0x0c0c59bcu; return 0; }
r[4]=r[53];
goto P_0c0c59be;
P_0c0c59be: /* original 904d, guest PC 0x0c0c59be */
if(!s->budget--) { s->failed_pc=0x0c0c59beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5cu,2);
goto P_0c0c59c0;
P_0c0c59c0: /* original ffd7, guest PC 0x0c0c59c0 */
if(!s->budget--) { s->failed_pc=0x0c0c59c0u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c59c2;
P_0c0c59c2: /* original 904c, guest PC 0x0c0c59c2 */
if(!s->budget--) { s->failed_pc=0x0c0c59c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c59c4;
P_0c0c59c4: /* original fef6, guest PC 0x0c0c59c4 */
if(!s->budget--) { s->failed_pc=0x0c0c59c4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c59c6;
P_0c0c59c6: /* original 6043, guest PC 0x0c0c59c6 */
if(!s->budget--) { s->failed_pc=0x0c0c59c6u; return 0; }
r[0]=r[4];
goto P_0c0c59c8;
P_0c0c59c8: /* original 4000, guest PC 0x0c0c59c8 */
if(!s->budget--) { s->failed_pc=0x0c0c59c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c59ca;
P_0c0c59ca: /* original 039d, guest PC 0x0c0c59ca */
if(!s->budget--) { s->failed_pc=0x0c0c59cau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[9]+r[0],2);
goto P_0c0c59cc;
P_0c0c59cc: /* original f2ec, guest PC 0x0c0c59cc */
if(!s->budget--) { s->failed_pc=0x0c0c59ccu; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0c59ce;
P_0c0c59ce: /* original 435a, guest PC 0x0c0c59ce */
if(!s->budget--) { s->failed_pc=0x0c0c59ceu; return 0; }
r[53]=r[3];
goto P_0c0c59d0;
P_0c0c59d0: /* original 9045, guest PC 0x0c0c59d0 */
if(!s->budget--) { s->failed_pc=0x0c0c59d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c59d2;
P_0c0c59d2: /* original f32d, guest PC 0x0c0c59d2 */
if(!s->budget--) { s->failed_pc=0x0c0c59d2u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c59d4;
P_0c0c59d4: /* original f230, guest PC 0x0c0c59d4 */
if(!s->budget--) { s->failed_pc=0x0c0c59d4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c59d6;
P_0c0c59d6: /* original ff27, guest PC 0x0c0c59d6 */
if(!s->budget--) { s->failed_pc=0x0c0c59d6u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c59d8;
P_0c0c59d8: /* original 9042, guest PC 0x0c0c59d8 */
if(!s->budget--) { s->failed_pc=0x0c0c59d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a60u,2);
goto P_0c0c59da;
P_0c0c59da: /* original fff7, guest PC 0x0c0c59da */
if(!s->budget--) { s->failed_pc=0x0c0c59dau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c59dc;
P_0c0c59dc: /* original 9441, guest PC 0x0c0c59dc */
if(!s->budget--) { s->failed_pc=0x0c0c59dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a62u,2);
goto P_0c0c59de;
P_0c0c59de: /* original 4d0b, guest PC 0x0c0c59de */
if(!s->budget--) { s->failed_pc=0x0c0c59deu; return 0; }
target=r[13];
r[16]=code_base|0x0c0c59e2u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c59e2u) { target=s->pc; goto dispatch; }
goto P_0c0c59e2;
P_0c0c59e0: /* original 34fc, guest PC 0x0c0c59e0 */
if(!s->budget--) { s->failed_pc=0x0c0c59e0u; return 0; }
r[4]+=r[15];
goto P_0c0c59e2;
P_0c0c59e2: /* original 903c, guest PC 0x0c0c59e2 */
if(!s->budget--) { s->failed_pc=0x0c0c59e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c59e4;
P_0c0c59e4: /* original f38d, guest PC 0x0c0c59e4 */
if(!s->budget--) { s->failed_pc=0x0c0c59e4u; return 0; }
fr[3]=0;
goto P_0c0c59e6;
P_0c0c59e6: /* original f2f6, guest PC 0x0c0c59e6 */
if(!s->budget--) { s->failed_pc=0x0c0c59e6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c59e8;
P_0c0c59e8: /* original f235, guest PC 0x0c0c59e8 */
if(!s->budget--) { s->failed_pc=0x0c0c59e8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0c59ea;
P_0c0c59ea: /* original 8b05, guest PC 0x0c0c59ea */
if(!s->budget--) { s->failed_pc=0x0c0c59eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c59f8; }
goto P_0c0c59ec;
P_0c0c59ec: /* original e024, guest PC 0x0c0c59ec */
if(!s->budget--) { s->failed_pc=0x0c0c59ecu; return 0; }
r[0]=0x00000024u;
goto P_0c0c59ee;
P_0c0c59ee: /* original f3f6, guest PC 0x0c0c59ee */
if(!s->budget--) { s->failed_pc=0x0c0c59eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c59f0;
P_0c0c59f0: /* original 9035, guest PC 0x0c0c59f0 */
if(!s->budget--) { s->failed_pc=0x0c0c59f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c59f2;
P_0c0c59f2: /* original f2f6, guest PC 0x0c0c59f2 */
if(!s->budget--) { s->failed_pc=0x0c0c59f2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c59f4;
P_0c0c59f4: /* original a00c, guest PC 0x0c0c59f4 */
if(!s->budget--) { s->failed_pc=0x0c0c59f4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c5a10;
P_0c0c59f6: /* original f231, guest PC 0x0c0c59f6 */
if(!s->budget--) { s->failed_pc=0x0c0c59f6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c59f8;
P_0c0c59f8: /* original c71d, guest PC 0x0c0c59f8 */
if(!s->budget--) { s->failed_pc=0x0c0c59f8u; return 0; }
r[0]=code_base|0x000c5a70u;
goto P_0c0c59fa;
P_0c0c59fa: /* original f408, guest PC 0x0c0c59fa */
if(!s->budget--) { s->failed_pc=0x0c0c59fau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c59fc;
P_0c0c59fc: /* original e024, guest PC 0x0c0c59fc */
if(!s->budget--) { s->failed_pc=0x0c0c59fcu; return 0; }
r[0]=0x00000024u;
goto P_0c0c59fe;
P_0c0c59fe: /* original f3f6, guest PC 0x0c0c59fe */
if(!s->budget--) { s->failed_pc=0x0c0c59feu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5a00;
P_0c0c5a00: /* original 902d, guest PC 0x0c0c5a00 */
if(!s->budget--) { s->failed_pc=0x0c0c5a00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c5a02;
P_0c0c5a02: /* original f2f6, guest PC 0x0c0c5a02 */
if(!s->budget--) { s->failed_pc=0x0c0c5a02u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5a04;
P_0c0c5a04: /* original f230, guest PC 0x0c0c5a04 */
if(!s->budget--) { s->failed_pc=0x0c0c5a04u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5a06;
P_0c0c5a06: /* original f425, guest PC 0x0c0c5a06 */
if(!s->budget--) { s->failed_pc=0x0c0c5a06u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c0c5a08;
P_0c0c5a08: /* original 8b07, guest PC 0x0c0c5a08 */
if(!s->budget--) { s->failed_pc=0x0c0c5a08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5a1a; }
goto P_0c0c5a0a;
P_0c0c5a0a: /* original 9028, guest PC 0x0c0c5a0a */
if(!s->budget--) { s->failed_pc=0x0c0c5a0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c5a0c;
P_0c0c5a0c: /* original f2f6, guest PC 0x0c0c5a0c */
if(!s->budget--) { s->failed_pc=0x0c0c5a0cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5a0e;
P_0c0c5a0e: /* original f230, guest PC 0x0c0c5a0e */
if(!s->budget--) { s->failed_pc=0x0c0c5a0eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5a10;
P_0c0c5a10: /* original 9025, guest PC 0x0c0c5a10 */
if(!s->budget--) { s->failed_pc=0x0c0c5a10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c5a12;
P_0c0c5a12: /* original ff27, guest PC 0x0c0c5a12 */
if(!s->budget--) { s->failed_pc=0x0c0c5a12u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5a14;
P_0c0c5a14: /* original 9425, guest PC 0x0c0c5a14 */
if(!s->budget--) { s->failed_pc=0x0c0c5a14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a62u,2);
goto P_0c0c5a16;
P_0c0c5a16: /* original 4d0b, guest PC 0x0c0c5a16 */
if(!s->budget--) { s->failed_pc=0x0c0c5a16u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c5a1au;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5a1au) { target=s->pc; goto dispatch; }
goto P_0c0c5a1a;
P_0c0c5a18: /* original 34fc, guest PC 0x0c0c5a18 */
if(!s->budget--) { s->failed_pc=0x0c0c5a18u; return 0; }
r[4]+=r[15];
goto P_0c0c5a1a;
P_0c0c5a1a: /* original 9020, guest PC 0x0c0c5a1a */
if(!s->budget--) { s->failed_pc=0x0c0c5a1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c5a1c;
P_0c0c5a1c: /* original ffe7, guest PC 0x0c0c5a1c */
if(!s->budget--) { s->failed_pc=0x0c0c5a1cu; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c5a1e;
P_0c0c5a1e: /* original c712, guest PC 0x0c0c5a1e */
if(!s->budget--) { s->failed_pc=0x0c0c5a1eu; return 0; }
r[0]=code_base|0x000c5a68u;
goto P_0c0c5a20;
P_0c0c5a20: /* original f308, guest PC 0x0c0c5a20 */
if(!s->budget--) { s->failed_pc=0x0c0c5a20u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5a22;
P_0c0c5a22: /* original ff30, guest PC 0x0c0c5a22 */
if(!s->budget--) { s->failed_pc=0x0c0c5a22u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0c5a24;
P_0c0c5a24: /* original e014, guest PC 0x0c0c5a24 */
if(!s->budget--) { s->failed_pc=0x0c0c5a24u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5a26;
P_0c0c5a26: /* original f3f6, guest PC 0x0c0c5a26 */
if(!s->budget--) { s->failed_pc=0x0c0c5a26u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5a28;
P_0c0c5a28: /* original ff35, guest PC 0x0c0c5a28 */
if(!s->budget--) { s->failed_pc=0x0c0c5a28u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0c5a2a;
P_0c0c5a2a: /* original 8bb6, guest PC 0x0c0c5a2a */
if(!s->budget--) { s->failed_pc=0x0c0c5a2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c599a; }
goto P_0c0c5a2c;
P_0c0c5a2c: /* original 901a, guest PC 0x0c0c5a2c */
if(!s->budget--) { s->failed_pc=0x0c0c5a2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a64u,2);
goto P_0c0c5a2e;
P_0c0c5a2e: /* original e201, guest PC 0x0c0c5a2e */
if(!s->budget--) { s->failed_pc=0x0c0c5a2eu; return 0; }
r[2]=0x00000001u;
goto P_0c0c5a30;
P_0c0c5a30: /* original 03fe, guest PC 0x0c0c5a30 */
if(!s->budget--) { s->failed_pc=0x0c0c5a30u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c5a32;
P_0c0c5a32: /* original e022, guest PC 0x0c0c5a32 */
if(!s->budget--) { s->failed_pc=0x0c0c5a32u; return 0; }
r[0]=0x00000022u;
goto P_0c0c5a34;
P_0c0c5a34: /* original 013d, guest PC 0x0c0c5a34 */
if(!s->budget--) { s->failed_pc=0x0c0c5a34u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c5a36;
P_0c0c5a36: /* original 212b, guest PC 0x0c0c5a36 */
if(!s->budget--) { s->failed_pc=0x0c0c5a36u; return 0; }
r[1]|=r[2];
goto P_0c0c5a38;
P_0c0c5a38: /* original 0315, guest PC 0x0c0c5a38 */
if(!s->budget--) { s->failed_pc=0x0c0c5a38u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c5a3a;
P_0c0c5a3a: /* original 9114, guest PC 0x0c0c5a3a */
if(!s->budget--) { s->failed_pc=0x0c0c5a3au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a66u,2);
goto P_0c0c5a3c;
P_0c0c5a3c: /* original 3f1c, guest PC 0x0c0c5a3c */
if(!s->budget--) { s->failed_pc=0x0c0c5a3cu; return 0; }
r[15]+=r[1];
goto P_0c0c5a3e;
P_0c0c5a3e: /* original 4f26, guest PC 0x0c0c5a3e */
if(!s->budget--) { s->failed_pc=0x0c0c5a3eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5a40;
P_0c0c5a40: /* original fcf9, guest PC 0x0c0c5a40 */
if(!s->budget--) { s->failed_pc=0x0c0c5a40u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c5a42;
P_0c0c5a42: /* original fdf9, guest PC 0x0c0c5a42 */
if(!s->budget--) { s->failed_pc=0x0c0c5a42u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c5a44;
P_0c0c5a44: /* original fef9, guest PC 0x0c0c5a44 */
if(!s->budget--) { s->failed_pc=0x0c0c5a44u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c5a46;
P_0c0c5a46: /* original fff9, guest PC 0x0c0c5a46 */
if(!s->budget--) { s->failed_pc=0x0c0c5a46u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c5a48;
P_0c0c5a48: /* original 68f6, guest PC 0x0c0c5a48 */
if(!s->budget--) { s->failed_pc=0x0c0c5a48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c5a4a;
P_0c0c5a4a: /* original 69f6, guest PC 0x0c0c5a4a */
if(!s->budget--) { s->failed_pc=0x0c0c5a4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c5a4c;
P_0c0c5a4c: /* original 6af6, guest PC 0x0c0c5a4c */
if(!s->budget--) { s->failed_pc=0x0c0c5a4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c5a4e;
P_0c0c5a4e: /* original 6bf6, guest PC 0x0c0c5a4e */
if(!s->budget--) { s->failed_pc=0x0c0c5a4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5a50;
P_0c0c5a50: /* original 6cf6, guest PC 0x0c0c5a50 */
if(!s->budget--) { s->failed_pc=0x0c0c5a50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5a52;
P_0c0c5a52: /* original 6df6, guest PC 0x0c0c5a52 */
if(!s->budget--) { s->failed_pc=0x0c0c5a52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5a54;
P_0c0c5a54: /* original 000b, guest PC 0x0c0c5a54 */
if(!s->budget--) { s->failed_pc=0x0c0c5a54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5a56: /* original 6ef6, guest PC 0x0c0c5a56 */
if(!s->budget--) { s->failed_pc=0x0c0c5a56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5a58u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5a58u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
