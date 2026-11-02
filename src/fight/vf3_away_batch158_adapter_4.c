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
int vf3_away_batch158_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0bf154u: goto P_0c0bf154;
case 0x0c0bf156u: goto P_0c0bf156;
case 0x0c0bf158u: goto P_0c0bf158;
case 0x0c0bf15au: goto P_0c0bf15a;
case 0x0c0bf15cu: goto P_0c0bf15c;
case 0x0c0bf15eu: goto P_0c0bf15e;
case 0x0c0bf160u: goto P_0c0bf160;
case 0x0c0bf162u: goto P_0c0bf162;
case 0x0c0bf164u: goto P_0c0bf164;
case 0x0c0bf166u: goto P_0c0bf166;
case 0x0c0bf168u: goto P_0c0bf168;
case 0x0c0bf16au: goto P_0c0bf16a;
case 0x0c0bf16cu: goto P_0c0bf16c;
case 0x0c0bf16eu: goto P_0c0bf16e;
case 0x0c0bf170u: goto P_0c0bf170;
case 0x0c0bf172u: goto P_0c0bf172;
case 0x0c0bf174u: goto P_0c0bf174;
case 0x0c0bf176u: goto P_0c0bf176;
case 0x0c0bf178u: goto P_0c0bf178;
case 0x0c0bf17au: goto P_0c0bf17a;
case 0x0c0bf17cu: goto P_0c0bf17c;
case 0x0c0bf17eu: goto P_0c0bf17e;
case 0x0c0bf180u: goto P_0c0bf180;
case 0x0c0bf182u: goto P_0c0bf182;
case 0x0c0bf184u: goto P_0c0bf184;
case 0x0c0bf186u: goto P_0c0bf186;
case 0x0c0bf188u: goto P_0c0bf188;
case 0x0c0bf18au: goto P_0c0bf18a;
case 0x0c0bf18cu: goto P_0c0bf18c;
case 0x0c0bf18eu: goto P_0c0bf18e;
case 0x0c0bf190u: goto P_0c0bf190;
case 0x0c0bf192u: goto P_0c0bf192;
case 0x0c0bf194u: goto P_0c0bf194;
case 0x0c0bf196u: goto P_0c0bf196;
case 0x0c0bf198u: goto P_0c0bf198;
case 0x0c0bf19au: goto P_0c0bf19a;
case 0x0c0bf19cu: goto P_0c0bf19c;
case 0x0c0bf19eu: goto P_0c0bf19e;
case 0x0c0bf1a0u: goto P_0c0bf1a0;
case 0x0c0bf1a2u: goto P_0c0bf1a2;
case 0x0c0bf1a4u: goto P_0c0bf1a4;
case 0x0c0bf1a6u: goto P_0c0bf1a6;
case 0x0c0bf1a8u: goto P_0c0bf1a8;
case 0x0c0bf1aau: goto P_0c0bf1aa;
case 0x0c0bf1acu: goto P_0c0bf1ac;
case 0x0c0bf1aeu: goto P_0c0bf1ae;
case 0x0c0bf1b0u: goto P_0c0bf1b0;
case 0x0c0bf1b2u: goto P_0c0bf1b2;
case 0x0c0bf1b4u: goto P_0c0bf1b4;
case 0x0c0bf1b6u: goto P_0c0bf1b6;
case 0x0c0bf1b8u: goto P_0c0bf1b8;
case 0x0c0bf1bau: goto P_0c0bf1ba;
case 0x0c0bf1bcu: goto P_0c0bf1bc;
case 0x0c0bf1beu: goto P_0c0bf1be;
case 0x0c0bf1c0u: goto P_0c0bf1c0;
case 0x0c0bf1c2u: goto P_0c0bf1c2;
case 0x0c0bf1c4u: goto P_0c0bf1c4;
case 0x0c0bf1c6u: goto P_0c0bf1c6;
case 0x0c0bf1c8u: goto P_0c0bf1c8;
case 0x0c0bf1cau: goto P_0c0bf1ca;
case 0x0c0bf1ccu: goto P_0c0bf1cc;
case 0x0c0bf1ceu: goto P_0c0bf1ce;
case 0x0c0bf1d0u: goto P_0c0bf1d0;
case 0x0c0bf1d2u: goto P_0c0bf1d2;
case 0x0c0bf1d4u: goto P_0c0bf1d4;
case 0x0c0bf1d6u: goto P_0c0bf1d6;
case 0x0c0bf1d8u: goto P_0c0bf1d8;
case 0x0c0bf1dau: goto P_0c0bf1da;
case 0x0c0bf1dcu: goto P_0c0bf1dc;
case 0x0c0bf1deu: goto P_0c0bf1de;
case 0x0c0bf1e0u: goto P_0c0bf1e0;
case 0x0c0bf1e2u: goto P_0c0bf1e2;
case 0x0c0bf1e4u: goto P_0c0bf1e4;
case 0x0c0bf1e6u: goto P_0c0bf1e6;
case 0x0c0bf1e8u: goto P_0c0bf1e8;
case 0x0c0bf1eau: goto P_0c0bf1ea;
case 0x0c0bf1ecu: goto P_0c0bf1ec;
case 0x0c0bf1eeu: goto P_0c0bf1ee;
case 0x0c0bf1f0u: goto P_0c0bf1f0;
case 0x0c0bf1f2u: goto P_0c0bf1f2;
case 0x0c0bf1f4u: goto P_0c0bf1f4;
case 0x0c0bf1f6u: goto P_0c0bf1f6;
case 0x0c0bf1f8u: goto P_0c0bf1f8;
case 0x0c0bf1fau: goto P_0c0bf1fa;
case 0x0c0bf1fcu: goto P_0c0bf1fc;
case 0x0c0bf1feu: goto P_0c0bf1fe;
case 0x0c0bf200u: goto P_0c0bf200;
case 0x0c0bf202u: goto P_0c0bf202;
case 0x0c0bf234u: goto P_0c0bf234;
case 0x0c0bf236u: goto P_0c0bf236;
case 0x0c0bf238u: goto P_0c0bf238;
case 0x0c0bf23au: goto P_0c0bf23a;
case 0x0c0bf23cu: goto P_0c0bf23c;
case 0x0c0bf23eu: goto P_0c0bf23e;
case 0x0c0bf240u: goto P_0c0bf240;
case 0x0c0bf242u: goto P_0c0bf242;
case 0x0c0bf244u: goto P_0c0bf244;
case 0x0c0bf246u: goto P_0c0bf246;
case 0x0c0bf248u: goto P_0c0bf248;
case 0x0c0bf24au: goto P_0c0bf24a;
case 0x0c0bf24cu: goto P_0c0bf24c;
case 0x0c0bf24eu: goto P_0c0bf24e;
case 0x0c0bf250u: goto P_0c0bf250;
case 0x0c0bf252u: goto P_0c0bf252;
case 0x0c0bf254u: goto P_0c0bf254;
case 0x0c0bf256u: goto P_0c0bf256;
case 0x0c0bf258u: goto P_0c0bf258;
case 0x0c0bf25au: goto P_0c0bf25a;
case 0x0c0bf25cu: goto P_0c0bf25c;
case 0x0c0bf25eu: goto P_0c0bf25e;
case 0x0c0bf260u: goto P_0c0bf260;
case 0x0c0bf262u: goto P_0c0bf262;
case 0x0c0bf264u: goto P_0c0bf264;
case 0x0c0bf266u: goto P_0c0bf266;
case 0x0c0bf268u: goto P_0c0bf268;
case 0x0c0bf26au: goto P_0c0bf26a;
case 0x0c0bf26cu: goto P_0c0bf26c;
case 0x0c0bf26eu: goto P_0c0bf26e;
case 0x0c0bf270u: goto P_0c0bf270;
case 0x0c0bf272u: goto P_0c0bf272;
case 0x0c0bf274u: goto P_0c0bf274;
case 0x0c0bf276u: goto P_0c0bf276;
case 0x0c0bf278u: goto P_0c0bf278;
case 0x0c0bf27au: goto P_0c0bf27a;
case 0x0c0bf27cu: goto P_0c0bf27c;
case 0x0c0bf27eu: goto P_0c0bf27e;
case 0x0c0bf280u: goto P_0c0bf280;
case 0x0c0bf282u: goto P_0c0bf282;
case 0x0c0bf284u: goto P_0c0bf284;
case 0x0c0bf286u: goto P_0c0bf286;
case 0x0c0bf288u: goto P_0c0bf288;
case 0x0c0bf28au: goto P_0c0bf28a;
case 0x0c0bf28cu: goto P_0c0bf28c;
case 0x0c0bf28eu: goto P_0c0bf28e;
case 0x0c0bf290u: goto P_0c0bf290;
case 0x0c0bf292u: goto P_0c0bf292;
case 0x0c0bf294u: goto P_0c0bf294;
case 0x0c0bf296u: goto P_0c0bf296;
case 0x0c0bf298u: goto P_0c0bf298;
case 0x0c0bf29au: goto P_0c0bf29a;
case 0x0c0bf29cu: goto P_0c0bf29c;
case 0x0c0bf29eu: goto P_0c0bf29e;
case 0x0c0bf2a0u: goto P_0c0bf2a0;
case 0x0c0bf2a2u: goto P_0c0bf2a2;
case 0x0c0bf2a4u: goto P_0c0bf2a4;
case 0x0c0bf2a6u: goto P_0c0bf2a6;
case 0x0c0bf2a8u: goto P_0c0bf2a8;
case 0x0c0bf2aau: goto P_0c0bf2aa;
case 0x0c0bf2acu: goto P_0c0bf2ac;
case 0x0c0bf2aeu: goto P_0c0bf2ae;
case 0x0c0bf2b0u: goto P_0c0bf2b0;
case 0x0c0bf2b2u: goto P_0c0bf2b2;
case 0x0c0bf2b4u: goto P_0c0bf2b4;
case 0x0c0bf2b6u: goto P_0c0bf2b6;
case 0x0c0bf2f4u: goto P_0c0bf2f4;
case 0x0c0bf2f6u: goto P_0c0bf2f6;
case 0x0c0bf2f8u: goto P_0c0bf2f8;
case 0x0c0bf2fau: goto P_0c0bf2fa;
case 0x0c0bf2fcu: goto P_0c0bf2fc;
case 0x0c0bf2feu: goto P_0c0bf2fe;
case 0x0c0bf300u: goto P_0c0bf300;
case 0x0c0bf302u: goto P_0c0bf302;
case 0x0c0bf304u: goto P_0c0bf304;
case 0x0c0bf306u: goto P_0c0bf306;
case 0x0c0bf308u: goto P_0c0bf308;
case 0x0c0bf30au: goto P_0c0bf30a;
case 0x0c0bf30cu: goto P_0c0bf30c;
case 0x0c0bf30eu: goto P_0c0bf30e;
case 0x0c0bf310u: goto P_0c0bf310;
case 0x0c0bf312u: goto P_0c0bf312;
case 0x0c0bf314u: goto P_0c0bf314;
case 0x0c0bf316u: goto P_0c0bf316;
case 0x0c0bf318u: goto P_0c0bf318;
case 0x0c0bf31au: goto P_0c0bf31a;
case 0x0c0bf31cu: goto P_0c0bf31c;
case 0x0c0bf31eu: goto P_0c0bf31e;
case 0x0c0bf320u: goto P_0c0bf320;
case 0x0c0bf322u: goto P_0c0bf322;
case 0x0c0bf324u: goto P_0c0bf324;
case 0x0c0bf326u: goto P_0c0bf326;
case 0x0c0bf328u: goto P_0c0bf328;
case 0x0c0bf32au: goto P_0c0bf32a;
case 0x0c0bf32cu: goto P_0c0bf32c;
case 0x0c0bf32eu: goto P_0c0bf32e;
case 0x0c0bf330u: goto P_0c0bf330;
case 0x0c0bf332u: goto P_0c0bf332;
case 0x0c0bf334u: goto P_0c0bf334;
case 0x0c0bf336u: goto P_0c0bf336;
case 0x0c0bf338u: goto P_0c0bf338;
case 0x0c0bf33au: goto P_0c0bf33a;
case 0x0c0bf33cu: goto P_0c0bf33c;
case 0x0c0bf33eu: goto P_0c0bf33e;
case 0x0c0bf340u: goto P_0c0bf340;
case 0x0c0bf342u: goto P_0c0bf342;
case 0x0c0bf344u: goto P_0c0bf344;
case 0x0c0bf346u: goto P_0c0bf346;
case 0x0c0bf348u: goto P_0c0bf348;
case 0x0c0bf34au: goto P_0c0bf34a;
case 0x0c0bf34cu: goto P_0c0bf34c;
case 0x0c0bf34eu: goto P_0c0bf34e;
case 0x0c0bf350u: goto P_0c0bf350;
case 0x0c0bf352u: goto P_0c0bf352;
case 0x0c0bf354u: goto P_0c0bf354;
case 0x0c0bf356u: goto P_0c0bf356;
case 0x0c0bf358u: goto P_0c0bf358;
case 0x0c0bf35au: goto P_0c0bf35a;
case 0x0c0bf35cu: goto P_0c0bf35c;
case 0x0c0bf35eu: goto P_0c0bf35e;
case 0x0c0bf360u: goto P_0c0bf360;
case 0x0c0bf362u: goto P_0c0bf362;
case 0x0c0bf364u: goto P_0c0bf364;
case 0x0c0bf366u: goto P_0c0bf366;
case 0x0c0bf368u: goto P_0c0bf368;
case 0x0c0bf36au: goto P_0c0bf36a;
case 0x0c0bf36cu: goto P_0c0bf36c;
case 0x0c0bf36eu: goto P_0c0bf36e;
case 0x0c0bf370u: goto P_0c0bf370;
case 0x0c0bf372u: goto P_0c0bf372;
case 0x0c0bf374u: goto P_0c0bf374;
case 0x0c0bf376u: goto P_0c0bf376;
case 0x0c0bf378u: goto P_0c0bf378;
case 0x0c0bf37au: goto P_0c0bf37a;
case 0x0c0bf37cu: goto P_0c0bf37c;
case 0x0c0bf37eu: goto P_0c0bf37e;
case 0x0c0bf380u: goto P_0c0bf380;
case 0x0c0bf382u: goto P_0c0bf382;
case 0x0c0bf384u: goto P_0c0bf384;
case 0x0c0bf386u: goto P_0c0bf386;
case 0x0c0bf388u: goto P_0c0bf388;
case 0x0c0bf38au: goto P_0c0bf38a;
case 0x0c0bf38cu: goto P_0c0bf38c;
case 0x0c0bf38eu: goto P_0c0bf38e;
case 0x0c0bf390u: goto P_0c0bf390;
case 0x0c0bf392u: goto P_0c0bf392;
case 0x0c0bf394u: goto P_0c0bf394;
case 0x0c0bf396u: goto P_0c0bf396;
case 0x0c0bf398u: goto P_0c0bf398;
case 0x0c0bf39au: goto P_0c0bf39a;
case 0x0c0bf39cu: goto P_0c0bf39c;
case 0x0c0bf39eu: goto P_0c0bf39e;
case 0x0c0bf3a0u: goto P_0c0bf3a0;
case 0x0c0bf3a2u: goto P_0c0bf3a2;
case 0x0c0bf3a4u: goto P_0c0bf3a4;
case 0x0c0bf3a6u: goto P_0c0bf3a6;
case 0x0c0bf3a8u: goto P_0c0bf3a8;
case 0x0c0bf3aau: goto P_0c0bf3aa;
case 0x0c0bf3acu: goto P_0c0bf3ac;
case 0x0c0bf3aeu: goto P_0c0bf3ae;
case 0x0c0bf3b0u: goto P_0c0bf3b0;
case 0x0c0bf3b2u: goto P_0c0bf3b2;
case 0x0c0bf3b4u: goto P_0c0bf3b4;
case 0x0c0bf3b6u: goto P_0c0bf3b6;
case 0x0c0bf3b8u: goto P_0c0bf3b8;
case 0x0c0bf3bau: goto P_0c0bf3ba;
case 0x0c0bf3bcu: goto P_0c0bf3bc;
case 0x0c0bf3beu: goto P_0c0bf3be;
case 0x0c0bf3c0u: goto P_0c0bf3c0;
case 0x0c0bf3c2u: goto P_0c0bf3c2;
case 0x0c0bf3c4u: goto P_0c0bf3c4;
case 0x0c0bf3c6u: goto P_0c0bf3c6;
case 0x0c0bf3c8u: goto P_0c0bf3c8;
case 0x0c0bf3cau: goto P_0c0bf3ca;
case 0x0c0bf3ccu: goto P_0c0bf3cc;
case 0x0c0bf3ceu: goto P_0c0bf3ce;
case 0x0c0bf3d0u: goto P_0c0bf3d0;
case 0x0c0bf3d2u: goto P_0c0bf3d2;
case 0x0c0bf3d4u: goto P_0c0bf3d4;
case 0x0c0bf3d6u: goto P_0c0bf3d6;
case 0x0c0bf3d8u: goto P_0c0bf3d8;
case 0x0c0bf3dau: goto P_0c0bf3da;
case 0x0c0bf3dcu: goto P_0c0bf3dc;
case 0x0c0bf3deu: goto P_0c0bf3de;
case 0x0c0bf3e0u: goto P_0c0bf3e0;
case 0x0c0bf3e2u: goto P_0c0bf3e2;
case 0x0c0bf3e4u: goto P_0c0bf3e4;
case 0x0c0bf3e6u: goto P_0c0bf3e6;
case 0x0c0bf3e8u: goto P_0c0bf3e8;
case 0x0c0bf3eau: goto P_0c0bf3ea;
case 0x0c0bf3ecu: goto P_0c0bf3ec;
case 0x0c0bf3eeu: goto P_0c0bf3ee;
case 0x0c0bf3f0u: goto P_0c0bf3f0;
case 0x0c0bf3f2u: goto P_0c0bf3f2;
case 0x0c0bf3f4u: goto P_0c0bf3f4;
case 0x0c0bf3f6u: goto P_0c0bf3f6;
case 0x0c0bf3f8u: goto P_0c0bf3f8;
case 0x0c0bf42cu: goto P_0c0bf42c;
case 0x0c0bf42eu: goto P_0c0bf42e;
case 0x0c0bf430u: goto P_0c0bf430;
case 0x0c0bf432u: goto P_0c0bf432;
case 0x0c0bf434u: goto P_0c0bf434;
case 0x0c0bf436u: goto P_0c0bf436;
case 0x0c0bf438u: goto P_0c0bf438;
case 0x0c0bf43au: goto P_0c0bf43a;
case 0x0c0bf43cu: goto P_0c0bf43c;
case 0x0c0bf43eu: goto P_0c0bf43e;
case 0x0c0bf440u: goto P_0c0bf440;
case 0x0c0bf442u: goto P_0c0bf442;
case 0x0c0bf444u: goto P_0c0bf444;
case 0x0c0bf446u: goto P_0c0bf446;
case 0x0c0bf448u: goto P_0c0bf448;
case 0x0c0bf44au: goto P_0c0bf44a;
case 0x0c0bf44cu: goto P_0c0bf44c;
case 0x0c0bf44eu: goto P_0c0bf44e;
case 0x0c0bf450u: goto P_0c0bf450;
case 0x0c0bf452u: goto P_0c0bf452;
case 0x0c0bf454u: goto P_0c0bf454;
case 0x0c0bf456u: goto P_0c0bf456;
case 0x0c0bf458u: goto P_0c0bf458;
case 0x0c0bf45au: goto P_0c0bf45a;
case 0x0c0bf45cu: goto P_0c0bf45c;
case 0x0c0bf45eu: goto P_0c0bf45e;
case 0x0c0bf460u: goto P_0c0bf460;
case 0x0c0bf462u: goto P_0c0bf462;
case 0x0c0bf464u: goto P_0c0bf464;
case 0x0c0bf466u: goto P_0c0bf466;
case 0x0c0bf468u: goto P_0c0bf468;
case 0x0c0bf46au: goto P_0c0bf46a;
case 0x0c0bf46cu: goto P_0c0bf46c;
case 0x0c0bf46eu: goto P_0c0bf46e;
case 0x0c0bf470u: goto P_0c0bf470;
case 0x0c0bf472u: goto P_0c0bf472;
case 0x0c0bf474u: goto P_0c0bf474;
case 0x0c0bf476u: goto P_0c0bf476;
case 0x0c0bf478u: goto P_0c0bf478;
case 0x0c0bf47au: goto P_0c0bf47a;
case 0x0c0bf47cu: goto P_0c0bf47c;
case 0x0c0bf47eu: goto P_0c0bf47e;
case 0x0c0bf480u: goto P_0c0bf480;
case 0x0c0bf482u: goto P_0c0bf482;
case 0x0c0bf484u: goto P_0c0bf484;
case 0x0c0bf486u: goto P_0c0bf486;
case 0x0c0bf488u: goto P_0c0bf488;
case 0x0c0bf48au: goto P_0c0bf48a;
case 0x0c0bf48cu: goto P_0c0bf48c;
case 0x0c0bf48eu: goto P_0c0bf48e;
case 0x0c0bf490u: goto P_0c0bf490;
case 0x0c0bf492u: goto P_0c0bf492;
case 0x0c0bf494u: goto P_0c0bf494;
case 0x0c0bf496u: goto P_0c0bf496;
case 0x0c0bf498u: goto P_0c0bf498;
case 0x0c0bf49au: goto P_0c0bf49a;
case 0x0c0bf49cu: goto P_0c0bf49c;
case 0x0c0bf49eu: goto P_0c0bf49e;
case 0x0c0bf4a0u: goto P_0c0bf4a0;
case 0x0c0bf4a2u: goto P_0c0bf4a2;
case 0x0c0bf4a4u: goto P_0c0bf4a4;
case 0x0c0bf4a6u: goto P_0c0bf4a6;
case 0x0c0bf4a8u: goto P_0c0bf4a8;
case 0x0c0bf4aau: goto P_0c0bf4aa;
case 0x0c0bf4acu: goto P_0c0bf4ac;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0bf154: /* original 2fe6, guest PC 0x0c0bf154 */
if(!s->budget--) { s->failed_pc=0x0c0bf154u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bf156;
P_0c0bf156: /* original 6e43, guest PC 0x0c0bf156 */
if(!s->budget--) { s->failed_pc=0x0c0bf156u; return 0; }
r[14]=r[4];
goto P_0c0bf158;
P_0c0bf158: /* original 2fd6, guest PC 0x0c0bf158 */
if(!s->budget--) { s->failed_pc=0x0c0bf158u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bf15a;
P_0c0bf15a: /* original 2fc6, guest PC 0x0c0bf15a */
if(!s->budget--) { s->failed_pc=0x0c0bf15au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bf15c;
P_0c0bf15c: /* original 2fb6, guest PC 0x0c0bf15c */
if(!s->budget--) { s->failed_pc=0x0c0bf15cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bf15e;
P_0c0bf15e: /* original 2fa6, guest PC 0x0c0bf15e */
if(!s->budget--) { s->failed_pc=0x0c0bf15eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bf160;
P_0c0bf160: /* original 2f96, guest PC 0x0c0bf160 */
if(!s->budget--) { s->failed_pc=0x0c0bf160u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bf162;
P_0c0bf162: /* original fffb, guest PC 0x0c0bf162 */
if(!s->budget--) { s->failed_pc=0x0c0bf162u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0bf164;
P_0c0bf164: /* original ffeb, guest PC 0x0c0bf164 */
if(!s->budget--) { s->failed_pc=0x0c0bf164u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0bf166;
P_0c0bf166: /* original ffdb, guest PC 0x0c0bf166 */
if(!s->budget--) { s->failed_pc=0x0c0bf166u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0bf168;
P_0c0bf168: /* original ffcb, guest PC 0x0c0bf168 */
if(!s->budget--) { s->failed_pc=0x0c0bf168u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0bf16a;
P_0c0bf16a: /* original 4f22, guest PC 0x0c0bf16a */
if(!s->budget--) { s->failed_pc=0x0c0bf16au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bf16c;
P_0c0bf16c: /* original dd2b, guest PC 0x0c0bf16c */
if(!s->budget--) { s->failed_pc=0x0c0bf16cu; return 0; }
r[13]=read(ram,0x0c0bf21cu,4);
goto P_0c0bf16e;
P_0c0bf16e: /* original db2a, guest PC 0x0c0bf16e */
if(!s->budget--) { s->failed_pc=0x0c0bf16eu; return 0; }
r[11]=read(ram,0x0c0bf218u,4);
goto P_0c0bf170;
P_0c0bf170: /* original d32b, guest PC 0x0c0bf170 */
if(!s->budget--) { s->failed_pc=0x0c0bf170u; return 0; }
r[3]=read(ram,0x0c0bf220u,4);
goto P_0c0bf172;
P_0c0bf172: /* original 7ff0, guest PC 0x0c0bf172 */
if(!s->budget--) { s->failed_pc=0x0c0bf172u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0bf174;
P_0c0bf174: /* original 430b, guest PC 0x0c0bf174 */
if(!s->budget--) { s->failed_pc=0x0c0bf174u; return 0; }
target=r[3];
r[16]=code_base|0x0c0bf178u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bf178u) { target=s->pc; goto dispatch; }
goto P_0c0bf178;
P_0c0bf176: /* original e400, guest PC 0x0c0bf176 */
if(!s->budget--) { s->failed_pc=0x0c0bf176u; return 0; }
r[4]=0x00000000u;
goto P_0c0bf178;
P_0c0bf178: /* original 9044, guest PC 0x0c0bf178 */
if(!s->budget--) { s->failed_pc=0x0c0bf178u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf204u,2);
goto P_0c0bf17a;
P_0c0bf17a: /* original f6d8, guest PC 0x0c0bf17a */
if(!s->budget--) { s->failed_pc=0x0c0bf17au; return 0; }
vf3_matrix_load(s,ram,6,r[13]);
goto P_0c0bf17c;
P_0c0bf17c: /* original 0ade, guest PC 0x0c0bf17c */
if(!s->budget--) { s->failed_pc=0x0c0bf17cu; return 0; }
r[10]=read(ram,r[13]+r[0],4);
goto P_0c0bf17e;
P_0c0bf17e: /* original 9042, guest PC 0x0c0bf17e */
if(!s->budget--) { s->failed_pc=0x0c0bf17eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf206u,2);
goto P_0c0bf180;
P_0c0bf180: /* original 09ec, guest PC 0x0c0bf180 */
if(!s->budget--) { s->failed_pc=0x0c0bf180u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0bf182;
P_0c0bf182: /* original e024, guest PC 0x0c0bf182 */
if(!s->budget--) { s->failed_pc=0x0c0bf182u; return 0; }
r[0]=0x00000024u;
goto P_0c0bf184;
P_0c0bf184: /* original fee6, guest PC 0x0c0bf184 */
if(!s->budget--) { s->failed_pc=0x0c0bf184u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0bf186;
P_0c0bf186: /* original e028, guest PC 0x0c0bf186 */
if(!s->budget--) { s->failed_pc=0x0c0bf186u; return 0; }
r[0]=0x00000028u;
goto P_0c0bf188;
P_0c0bf188: /* original ffe6, guest PC 0x0c0bf188 */
if(!s->budget--) { s->failed_pc=0x0c0bf188u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0bf18a;
P_0c0bf18a: /* original e02c, guest PC 0x0c0bf18a */
if(!s->budget--) { s->failed_pc=0x0c0bf18au; return 0; }
r[0]=0x0000002cu;
goto P_0c0bf18c;
P_0c0bf18c: /* original fde6, guest PC 0x0c0bf18c */
if(!s->budget--) { s->failed_pc=0x0c0bf18cu; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0bf18e;
P_0c0bf18e: /* original 699c, guest PC 0x0c0bf18e */
if(!s->budget--) { s->failed_pc=0x0c0bf18eu; return 0; }
r[9]=r[9]&255u;
goto P_0c0bf190;
P_0c0bf190: /* original 903a, guest PC 0x0c0bf190 */
if(!s->budget--) { s->failed_pc=0x0c0bf190u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf208u,2);
goto P_0c0bf192;
P_0c0bf192: /* original f3e6, guest PC 0x0c0bf192 */
if(!s->budget--) { s->failed_pc=0x0c0bf192u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0bf194;
P_0c0bf194: /* original e00c, guest PC 0x0c0bf194 */
if(!s->budget--) { s->failed_pc=0x0c0bf194u; return 0; }
r[0]=0x0000000cu;
goto P_0c0bf196;
P_0c0bf196: /* original ff37, guest PC 0x0c0bf196 */
if(!s->budget--) { s->failed_pc=0x0c0bf196u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0bf198;
P_0c0bf198: /* original 9037, guest PC 0x0c0bf198 */
if(!s->budget--) { s->failed_pc=0x0c0bf198u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf20au,2);
goto P_0c0bf19a;
P_0c0bf19a: /* original fce6, guest PC 0x0c0bf19a */
if(!s->budget--) { s->failed_pc=0x0c0bf19au; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0bf19c;
P_0c0bf19c: /* original 7004, guest PC 0x0c0bf19c */
if(!s->budget--) { s->failed_pc=0x0c0bf19cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0bf19e;
P_0c0bf19e: /* original f3e6, guest PC 0x0c0bf19e */
if(!s->budget--) { s->failed_pc=0x0c0bf19eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0bf1a0;
P_0c0bf1a0: /* original e008, guest PC 0x0c0bf1a0 */
if(!s->budget--) { s->failed_pc=0x0c0bf1a0u; return 0; }
r[0]=0x00000008u;
goto P_0c0bf1a2;
P_0c0bf1a2: /* original ff37, guest PC 0x0c0bf1a2 */
if(!s->budget--) { s->failed_pc=0x0c0bf1a2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0bf1a4;
P_0c0bf1a4: /* original 9032, guest PC 0x0c0bf1a4 */
if(!s->budget--) { s->failed_pc=0x0c0bf1a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf20cu,2);
goto P_0c0bf1a6;
P_0c0bf1a6: /* original f3e6, guest PC 0x0c0bf1a6 */
if(!s->budget--) { s->failed_pc=0x0c0bf1a6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0bf1a8;
P_0c0bf1a8: /* original e004, guest PC 0x0c0bf1a8 */
if(!s->budget--) { s->failed_pc=0x0c0bf1a8u; return 0; }
r[0]=0x00000004u;
goto P_0c0bf1aa;
P_0c0bf1aa: /* original ff37, guest PC 0x0c0bf1aa */
if(!s->budget--) { s->failed_pc=0x0c0bf1aau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0bf1ac;
P_0c0bf1ac: /* original 902f, guest PC 0x0c0bf1ac */
if(!s->budget--) { s->failed_pc=0x0c0bf1acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf20eu,2);
goto P_0c0bf1ae;
P_0c0bf1ae: /* original f4e6, guest PC 0x0c0bf1ae */
if(!s->budget--) { s->failed_pc=0x0c0bf1aeu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0bf1b0;
P_0c0bf1b0: /* original 7004, guest PC 0x0c0bf1b0 */
if(!s->budget--) { s->failed_pc=0x0c0bf1b0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0bf1b2;
P_0c0bf1b2: /* original f7e6, guest PC 0x0c0bf1b2 */
if(!s->budget--) { s->failed_pc=0x0c0bf1b2u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0bf1b4;
P_0c0bf1b4: /* original 7004, guest PC 0x0c0bf1b4 */
if(!s->budget--) { s->failed_pc=0x0c0bf1b4u; return 0; }
r[0]+=0x00000004u;
goto P_0c0bf1b6;
P_0c0bf1b6: /* original f5e6, guest PC 0x0c0bf1b6 */
if(!s->budget--) { s->failed_pc=0x0c0bf1b6u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0bf1b8;
P_0c0bf1b8: /* original f9ec, guest PC 0x0c0bf1b8 */
if(!s->budget--) { s->failed_pc=0x0c0bf1b8u; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c0bf1ba;
P_0c0bf1ba: /* original f9c0, guest PC 0x0c0bf1ba */
if(!s->budget--) { s->failed_pc=0x0c0bf1bau; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'+');
goto P_0c0bf1bc;
P_0c0bf1bc: /* original f8dc, guest PC 0x0c0bf1bc */
if(!s->budget--) { s->failed_pc=0x0c0bf1bcu; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c0bf1be;
P_0c0bf1be: /* original f830, guest PC 0x0c0bf1be */
if(!s->budget--) { s->failed_pc=0x0c0bf1beu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'+');
goto P_0c0bf1c0;
P_0c0bf1c0: /* original 9026, guest PC 0x0c0bf1c0 */
if(!s->budget--) { s->failed_pc=0x0c0bf1c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf210u,2);
goto P_0c0bf1c2;
P_0c0bf1c2: /* original 9326, guest PC 0x0c0bf1c2 */
if(!s->budget--) { s->failed_pc=0x0c0bf1c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf212u,2);
goto P_0c0bf1c4;
P_0c0bf1c4: /* original 6de2, guest PC 0x0c0bf1c4 */
if(!s->budget--) { s->failed_pc=0x0c0bf1c4u; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c0bf1c6;
P_0c0bf1c6: /* original 0cee, guest PC 0x0c0bf1c6 */
if(!s->budget--) { s->failed_pc=0x0c0bf1c6u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0bf1c8;
P_0c0bf1c8: /* original 23a8, guest PC 0x0c0bf1c8 */
if(!s->budget--) { s->failed_pc=0x0c0bf1c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0bf1ca;
P_0c0bf1ca: /* original e048, guest PC 0x0c0bf1ca */
if(!s->budget--) { s->failed_pc=0x0c0bf1cau; return 0; }
r[0]=0x00000048u;
goto P_0c0bf1cc;
P_0c0bf1cc: /* original 8d43, guest PC 0x0c0bf1cc */
if(!s->budget--) { s->failed_pc=0x0c0bf1ccu; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+r[0],4);
if(cond) { goto P_0c0bf256; }
goto P_0c0bf1d0;
P_0c0bf1ce: /* original 04ee, guest PC 0x0c0bf1ce */
if(!s->budget--) { s->failed_pc=0x0c0bf1ceu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0bf1d0;
P_0c0bf1d0: /* original 901e, guest PC 0x0c0bf1d0 */
if(!s->budget--) { s->failed_pc=0x0c0bf1d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf210u,2);
goto P_0c0bf1d2;
P_0c0bf1d2: /* original e540, guest PC 0x0c0bf1d2 */
if(!s->budget--) { s->failed_pc=0x0c0bf1d2u; return 0; }
r[5]=0x00000040u;
goto P_0c0bf1d4;
P_0c0bf1d4: /* original 03ee, guest PC 0x0c0bf1d4 */
if(!s->budget--) { s->failed_pc=0x0c0bf1d4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0bf1d6;
P_0c0bf1d6: /* original 2358, guest PC 0x0c0bf1d6 */
if(!s->budget--) { s->failed_pc=0x0c0bf1d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0bf1d8;
P_0c0bf1d8: /* original 8b03, guest PC 0x0c0bf1d8 */
if(!s->budget--) { s->failed_pc=0x0c0bf1d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf1e2; }
goto P_0c0bf1da;
P_0c0bf1da: /* original 921b, guest PC 0x0c0bf1da */
if(!s->budget--) { s->failed_pc=0x0c0bf1dau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf214u,2);
goto P_0c0bf1dc;
P_0c0bf1dc: /* original 2d29, guest PC 0x0c0bf1dc */
if(!s->budget--) { s->failed_pc=0x0c0bf1dcu; return 0; }
r[13]&=r[2];
goto P_0c0bf1de;
P_0c0bf1de: /* original a03a, guest PC 0x0c0bf1de */
if(!s->budget--) { s->failed_pc=0x0c0bf1deu; return 0; }
write(ram,r[14],r[13],4);
goto P_0c0bf256;
P_0c0bf1e0: /* original 2ed2, guest PC 0x0c0bf1e0 */
if(!s->budget--) { s->failed_pc=0x0c0bf1e0u; return 0; }
write(ram,r[14],r[13],4);
goto P_0c0bf1e2;
P_0c0bf1e2: /* original 62d3, guest PC 0x0c0bf1e2 */
if(!s->budget--) { s->failed_pc=0x0c0bf1e2u; return 0; }
r[2]=r[13];
goto P_0c0bf1e4;
P_0c0bf1e4: /* original 22b8, guest PC 0x0c0bf1e4 */
if(!s->budget--) { s->failed_pc=0x0c0bf1e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0bf1e6;
P_0c0bf1e6: /* original 8b36, guest PC 0x0c0bf1e6 */
if(!s->budget--) { s->failed_pc=0x0c0bf1e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf256; }
goto P_0c0bf1e8;
P_0c0bf1e8: /* original d30e, guest PC 0x0c0bf1e8 */
if(!s->budget--) { s->failed_pc=0x0c0bf1e8u; return 0; }
r[3]=read(ram,0x0c0bf224u,4);
goto P_0c0bf1ea;
P_0c0bf1ea: /* original 2348, guest PC 0x0c0bf1ea */
if(!s->budget--) { s->failed_pc=0x0c0bf1eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0bf1ec;
P_0c0bf1ec: /* original 8b33, guest PC 0x0c0bf1ec */
if(!s->budget--) { s->failed_pc=0x0c0bf1ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf256; }
goto P_0c0bf1ee;
P_0c0bf1ee: /* original c70e, guest PC 0x0c0bf1ee */
if(!s->budget--) { s->failed_pc=0x0c0bf1eeu; return 0; }
r[0]=code_base|0x000bf228u;
goto P_0c0bf1f0;
P_0c0bf1f0: /* original f308, guest PC 0x0c0bf1f0 */
if(!s->budget--) { s->failed_pc=0x0c0bf1f0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0bf1f2;
P_0c0bf1f2: /* original 25c8, guest PC 0x0c0bf1f2 */
if(!s->budget--) { s->failed_pc=0x0c0bf1f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[12])==0)!=0);
goto P_0c0bf1f4;
P_0c0bf1f4: /* original 8d2f, guest PC 0x0c0bf1f4 */
if(!s->budget--) { s->failed_pc=0x0c0bf1f4u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]);
if(cond) { goto P_0c0bf256; }
goto P_0c0bf1f8;
P_0c0bf1f6: /* original ff3a, guest PC 0x0c0bf1f6 */
if(!s->budget--) { s->failed_pc=0x0c0bf1f6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0bf1f8;
P_0c0bf1f8: /* original d30c, guest PC 0x0c0bf1f8 */
if(!s->budget--) { s->failed_pc=0x0c0bf1f8u; return 0; }
r[3]=read(ram,0x0c0bf22cu,4);
goto P_0c0bf1fa;
P_0c0bf1fa: /* original 2348, guest PC 0x0c0bf1fa */
if(!s->budget--) { s->failed_pc=0x0c0bf1fau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0bf1fc;
P_0c0bf1fc: /* original 8b1a, guest PC 0x0c0bf1fc */
if(!s->budget--) { s->failed_pc=0x0c0bf1fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf234; }
goto P_0c0bf1fe;
P_0c0bf1fe: /* original c70c, guest PC 0x0c0bf1fe */
if(!s->budget--) { s->failed_pc=0x0c0bf1feu; return 0; }
r[0]=code_base|0x000bf230u;
goto P_0c0bf200;
P_0c0bf200: /* original a01a, guest PC 0x0c0bf200 */
if(!s->budget--) { s->failed_pc=0x0c0bf200u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0bf238;
P_0c0bf202: /* original f308, guest PC 0x0c0bf202 */
if(!s->budget--) { s->failed_pc=0x0c0bf202u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
if(!vf3_matrix_family(0x0c0bf204u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bf204u; return 0; } return 1;
P_0c0bf234: /* original c722, guest PC 0x0c0bf234 */
if(!s->budget--) { s->failed_pc=0x0c0bf234u; return 0; }
r[0]=code_base|0x000bf2c0u;
goto P_0c0bf236;
P_0c0bf236: /* original f308, guest PC 0x0c0bf236 */
if(!s->budget--) { s->failed_pc=0x0c0bf236u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0bf238;
P_0c0bf238: /* original ff3a, guest PC 0x0c0bf238 */
if(!s->budget--) { s->failed_pc=0x0c0bf238u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0bf23a;
P_0c0bf23a: /* original f34c, guest PC 0x0c0bf23a */
if(!s->budget--) { s->failed_pc=0x0c0bf23au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0bf23c;
P_0c0bf23c: /* original f46c, guest PC 0x0c0bf23c */
if(!s->budget--) { s->failed_pc=0x0c0bf23cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0bf23e;
P_0c0bf23e: /* original f432, guest PC 0x0c0bf23e */
if(!s->budget--) { s->failed_pc=0x0c0bf23eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0bf240;
P_0c0bf240: /* original f35c, guest PC 0x0c0bf240 */
if(!s->budget--) { s->failed_pc=0x0c0bf240u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0bf242;
P_0c0bf242: /* original f56c, guest PC 0x0c0bf242 */
if(!s->budget--) { s->failed_pc=0x0c0bf242u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0bf244;
P_0c0bf244: /* original f532, guest PC 0x0c0bf244 */
if(!s->budget--) { s->failed_pc=0x0c0bf244u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0bf246;
P_0c0bf246: /* original f34c, guest PC 0x0c0bf246 */
if(!s->budget--) { s->failed_pc=0x0c0bf246u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0bf248;
P_0c0bf248: /* original f4f8, guest PC 0x0c0bf248 */
if(!s->budget--) { s->failed_pc=0x0c0bf248u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0bf24a;
P_0c0bf24a: /* original f432, guest PC 0x0c0bf24a */
if(!s->budget--) { s->failed_pc=0x0c0bf24au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0bf24c;
P_0c0bf24c: /* original f35c, guest PC 0x0c0bf24c */
if(!s->budget--) { s->failed_pc=0x0c0bf24cu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0bf24e;
P_0c0bf24e: /* original f5f8, guest PC 0x0c0bf24e */
if(!s->budget--) { s->failed_pc=0x0c0bf24eu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c0bf250;
P_0c0bf250: /* original f532, guest PC 0x0c0bf250 */
if(!s->budget--) { s->failed_pc=0x0c0bf250u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0bf252;
P_0c0bf252: /* original fe40, guest PC 0x0c0bf252 */
if(!s->budget--) { s->failed_pc=0x0c0bf252u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'+');
goto P_0c0bf254;
P_0c0bf254: /* original fd50, guest PC 0x0c0bf254 */
if(!s->budget--) { s->failed_pc=0x0c0bf254u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'+');
goto P_0c0bf256;
P_0c0bf256: /* original d31b, guest PC 0x0c0bf256 */
if(!s->budget--) { s->failed_pc=0x0c0bf256u; return 0; }
r[3]=read(ram,0x0c0bf2c4u,4);
goto P_0c0bf258;
P_0c0bf258: /* original 2348, guest PC 0x0c0bf258 */
if(!s->budget--) { s->failed_pc=0x0c0bf258u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0bf25a;
P_0c0bf25a: /* original 8b6c, guest PC 0x0c0bf25a */
if(!s->budget--) { s->failed_pc=0x0c0bf25au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf336; }
goto P_0c0bf25c;
P_0c0bf25c: /* original d21a, guest PC 0x0c0bf25c */
if(!s->budget--) { s->failed_pc=0x0c0bf25cu; return 0; }
r[2]=read(ram,0x0c0bf2c8u,4);
goto P_0c0bf25e;
P_0c0bf25e: /* original 22d8, guest PC 0x0c0bf25e */
if(!s->budget--) { s->failed_pc=0x0c0bf25eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0bf260;
P_0c0bf260: /* original 8b05, guest PC 0x0c0bf260 */
if(!s->budget--) { s->failed_pc=0x0c0bf260u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf26e; }
goto P_0c0bf262;
P_0c0bf262: /* original 9329, guest PC 0x0c0bf262 */
if(!s->budget--) { s->failed_pc=0x0c0bf262u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf2b8u,2);
goto P_0c0bf264;
P_0c0bf264: /* original 2348, guest PC 0x0c0bf264 */
if(!s->budget--) { s->failed_pc=0x0c0bf264u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0bf266;
P_0c0bf266: /* original 8b66, guest PC 0x0c0bf266 */
if(!s->budget--) { s->failed_pc=0x0c0bf266u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf336; }
goto P_0c0bf268;
P_0c0bf268: /* original 9227, guest PC 0x0c0bf268 */
if(!s->budget--) { s->failed_pc=0x0c0bf268u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf2bau,2);
goto P_0c0bf26a;
P_0c0bf26a: /* original 2248, guest PC 0x0c0bf26a */
if(!s->budget--) { s->failed_pc=0x0c0bf26au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0bf26c;
P_0c0bf26c: /* original 8b63, guest PC 0x0c0bf26c */
if(!s->budget--) { s->failed_pc=0x0c0bf26cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf336; }
goto P_0c0bf26e;
P_0c0bf26e: /* original c717, guest PC 0x0c0bf26e */
if(!s->budget--) { s->failed_pc=0x0c0bf26eu; return 0; }
r[0]=code_base|0x000bf2ccu;
goto P_0c0bf270;
P_0c0bf270: /* original f95d, guest PC 0x0c0bf270 */
if(!s->budget--) { s->failed_pc=0x0c0bf270u; return 0; }
fr[9]&=0x7fffffffu;
goto P_0c0bf272;
P_0c0bf272: /* original f408, guest PC 0x0c0bf272 */
if(!s->budget--) { s->failed_pc=0x0c0bf272u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0bf274;
P_0c0bf274: /* original f59c, guest PC 0x0c0bf274 */
if(!s->budget--) { s->failed_pc=0x0c0bf274u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c0bf276;
P_0c0bf276: /* original f545, guest PC 0x0c0bf276 */
if(!s->budget--) { s->failed_pc=0x0c0bf276u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0bf278;
P_0c0bf278: /* original d515, guest PC 0x0c0bf278 */
if(!s->budget--) { s->failed_pc=0x0c0bf278u; return 0; }
r[5]=read(ram,0x0c0bf2d0u,4);
goto P_0c0bf27a;
P_0c0bf27a: /* original 8d09, guest PC 0x0c0bf27a */
if(!s->budget--) { s->failed_pc=0x0c0bf27au; return 0; }
cond=r[17]&1u;
fr[8]&=0x7fffffffu;
if(cond) { goto P_0c0bf290; }
goto P_0c0bf27e;
P_0c0bf27c: /* original f85d, guest PC 0x0c0bf27c */
if(!s->budget--) { s->failed_pc=0x0c0bf27cu; return 0; }
fr[8]&=0x7fffffffu;
goto P_0c0bf27e;
P_0c0bf27e: /* original f845, guest PC 0x0c0bf27e */
if(!s->budget--) { s->failed_pc=0x0c0bf27eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[4]))!=0);
goto P_0c0bf280;
P_0c0bf280: /* original 8906, guest PC 0x0c0bf280 */
if(!s->budget--) { s->failed_pc=0x0c0bf280u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bf290; }
goto P_0c0bf282;
P_0c0bf282: /* original 2458, guest PC 0x0c0bf282 */
if(!s->budget--) { s->failed_pc=0x0c0bf282u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c0bf284;
P_0c0bf284: /* original 8b06, guest PC 0x0c0bf284 */
if(!s->budget--) { s->failed_pc=0x0c0bf284u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf294; }
goto P_0c0bf286;
P_0c0bf286: /* original c713, guest PC 0x0c0bf286 */
if(!s->budget--) { s->failed_pc=0x0c0bf286u; return 0; }
r[0]=code_base|0x000bf2d4u;
goto P_0c0bf288;
P_0c0bf288: /* original f408, guest PC 0x0c0bf288 */
if(!s->budget--) { s->failed_pc=0x0c0bf288u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0bf28a;
P_0c0bf28a: /* original c713, guest PC 0x0c0bf28a */
if(!s->budget--) { s->failed_pc=0x0c0bf28au; return 0; }
r[0]=code_base|0x000bf2d8u;
goto P_0c0bf28c;
P_0c0bf28c: /* original a00b, guest PC 0x0c0bf28c */
if(!s->budget--) { s->failed_pc=0x0c0bf28cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0bf2a6;
P_0c0bf28e: /* original f508, guest PC 0x0c0bf28e */
if(!s->budget--) { s->failed_pc=0x0c0bf28eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0bf290;
P_0c0bf290: /* original 2458, guest PC 0x0c0bf290 */
if(!s->budget--) { s->failed_pc=0x0c0bf290u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c0bf292;
P_0c0bf292: /* original 8904, guest PC 0x0c0bf292 */
if(!s->budget--) { s->failed_pc=0x0c0bf292u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bf29e; }
goto P_0c0bf294;
P_0c0bf294: /* original c711, guest PC 0x0c0bf294 */
if(!s->budget--) { s->failed_pc=0x0c0bf294u; return 0; }
r[0]=code_base|0x000bf2dcu;
goto P_0c0bf296;
P_0c0bf296: /* original f408, guest PC 0x0c0bf296 */
if(!s->budget--) { s->failed_pc=0x0c0bf296u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0bf298;
P_0c0bf298: /* original c711, guest PC 0x0c0bf298 */
if(!s->budget--) { s->failed_pc=0x0c0bf298u; return 0; }
r[0]=code_base|0x000bf2e0u;
goto P_0c0bf29a;
P_0c0bf29a: /* original a004, guest PC 0x0c0bf29a */
if(!s->budget--) { s->failed_pc=0x0c0bf29au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0bf2a6;
P_0c0bf29c: /* original f508, guest PC 0x0c0bf29c */
if(!s->budget--) { s->failed_pc=0x0c0bf29cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0bf29e;
P_0c0bf29e: /* original c711, guest PC 0x0c0bf29e */
if(!s->budget--) { s->failed_pc=0x0c0bf29eu; return 0; }
r[0]=code_base|0x000bf2e4u;
goto P_0c0bf2a0;
P_0c0bf2a0: /* original f408, guest PC 0x0c0bf2a0 */
if(!s->budget--) { s->failed_pc=0x0c0bf2a0u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0bf2a2;
P_0c0bf2a2: /* original c711, guest PC 0x0c0bf2a2 */
if(!s->budget--) { s->failed_pc=0x0c0bf2a2u; return 0; }
r[0]=code_base|0x000bf2e8u;
goto P_0c0bf2a4;
P_0c0bf2a4: /* original f508, guest PC 0x0c0bf2a4 */
if(!s->budget--) { s->failed_pc=0x0c0bf2a4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0bf2a6;
P_0c0bf2a6: /* original d211, guest PC 0x0c0bf2a6 */
if(!s->budget--) { s->failed_pc=0x0c0bf2a6u; return 0; }
r[2]=read(ram,0x0c0bf2ecu,4);
goto P_0c0bf2a8;
P_0c0bf2a8: /* original 22c8, guest PC 0x0c0bf2a8 */
if(!s->budget--) { s->failed_pc=0x0c0bf2a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c0bf2aa;
P_0c0bf2aa: /* original 8b23, guest PC 0x0c0bf2aa */
if(!s->budget--) { s->failed_pc=0x0c0bf2aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf2f4; }
goto P_0c0bf2ac;
P_0c0bf2ac: /* original 9306, guest PC 0x0c0bf2ac */
if(!s->budget--) { s->failed_pc=0x0c0bf2acu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf2bcu,2);
goto P_0c0bf2ae;
P_0c0bf2ae: /* original 23c8, guest PC 0x0c0bf2ae */
if(!s->budget--) { s->failed_pc=0x0c0bf2aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0bf2b0;
P_0c0bf2b0: /* original 8924, guest PC 0x0c0bf2b0 */
if(!s->budget--) { s->failed_pc=0x0c0bf2b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bf2fc; }
goto P_0c0bf2b2;
P_0c0bf2b2: /* original c70f, guest PC 0x0c0bf2b2 */
if(!s->budget--) { s->failed_pc=0x0c0bf2b2u; return 0; }
r[0]=code_base|0x000bf2f0u;
goto P_0c0bf2b4;
P_0c0bf2b4: /* original a020, guest PC 0x0c0bf2b4 */
if(!s->budget--) { s->failed_pc=0x0c0bf2b4u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0bf2f8;
P_0c0bf2b6: /* original f808, guest PC 0x0c0bf2b6 */
if(!s->budget--) { s->failed_pc=0x0c0bf2b6u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
if(!vf3_matrix_family(0x0c0bf2b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bf2b8u; return 0; } return 1;
P_0c0bf2f4: /* original c744, guest PC 0x0c0bf2f4 */
if(!s->budget--) { s->failed_pc=0x0c0bf2f4u; return 0; }
r[0]=code_base|0x000bf408u;
goto P_0c0bf2f6;
P_0c0bf2f6: /* original f808, guest PC 0x0c0bf2f6 */
if(!s->budget--) { s->failed_pc=0x0c0bf2f6u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0bf2f8;
P_0c0bf2f8: /* original f582, guest PC 0x0c0bf2f8 */
if(!s->budget--) { s->failed_pc=0x0c0bf2f8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c0bf2fa;
P_0c0bf2fa: /* original f482, guest PC 0x0c0bf2fa */
if(!s->budget--) { s->failed_pc=0x0c0bf2fau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c0bf2fc;
P_0c0bf2fc: /* original f34c, guest PC 0x0c0bf2fc */
if(!s->budget--) { s->failed_pc=0x0c0bf2fcu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0bf2fe;
P_0c0bf2fe: /* original e004, guest PC 0x0c0bf2fe */
if(!s->budget--) { s->failed_pc=0x0c0bf2feu; return 0; }
r[0]=0x00000004u;
goto P_0c0bf300;
P_0c0bf300: /* original f47c, guest PC 0x0c0bf300 */
if(!s->budget--) { s->failed_pc=0x0c0bf300u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0bf302;
P_0c0bf302: /* original f432, guest PC 0x0c0bf302 */
if(!s->budget--) { s->failed_pc=0x0c0bf302u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0bf304;
P_0c0bf304: /* original f37c, guest PC 0x0c0bf304 */
if(!s->budget--) { s->failed_pc=0x0c0bf304u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0bf306;
P_0c0bf306: /* original f79d, guest PC 0x0c0bf306 */
if(!s->budget--) { s->failed_pc=0x0c0bf306u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0bf308;
P_0c0bf308: /* original f731, guest PC 0x0c0bf308 */
if(!s->budget--) { s->failed_pc=0x0c0bf308u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c0bf30a;
P_0c0bf30a: /* original f8dc, guest PC 0x0c0bf30a */
if(!s->budget--) { s->failed_pc=0x0c0bf30au; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c0bf30c;
P_0c0bf30c: /* original f34c, guest PC 0x0c0bf30c */
if(!s->budget--) { s->failed_pc=0x0c0bf30cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0bf30e;
P_0c0bf30e: /* original f842, guest PC 0x0c0bf30e */
if(!s->budget--) { s->failed_pc=0x0c0bf30eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c0bf310;
P_0c0bf310: /* original f572, guest PC 0x0c0bf310 */
if(!s->budget--) { s->failed_pc=0x0c0bf310u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0bf312;
P_0c0bf312: /* original f7ec, guest PC 0x0c0bf312 */
if(!s->budget--) { s->failed_pc=0x0c0bf312u; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c0bf314;
P_0c0bf314: /* original f742, guest PC 0x0c0bf314 */
if(!s->budget--) { s->failed_pc=0x0c0bf314u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0bf316;
P_0c0bf316: /* original f05c, guest PC 0x0c0bf316 */
if(!s->budget--) { s->failed_pc=0x0c0bf316u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0bf318;
P_0c0bf318: /* original f8de, guest PC 0x0c0bf318 */
if(!s->budget--) { s->failed_pc=0x0c0bf318u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[13],fr[8],r[18]);
goto P_0c0bf31a;
P_0c0bf31a: /* original f7ee, guest PC 0x0c0bf31a */
if(!s->budget--) { s->failed_pc=0x0c0bf31au; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[14],fr[7],r[18]);
goto P_0c0bf31c;
P_0c0bf31c: /* original fd8c, guest PC 0x0c0bf31c */
if(!s->budget--) { s->failed_pc=0x0c0bf31cu; return 0; }
vf3_matrix_move(s,13,8);
goto P_0c0bf31e;
P_0c0bf31e: /* original fe7c, guest PC 0x0c0bf31e */
if(!s->budget--) { s->failed_pc=0x0c0bf31eu; return 0; }
vf3_matrix_move(s,14,7);
goto P_0c0bf320;
P_0c0bf320: /* original f7cc, guest PC 0x0c0bf320 */
if(!s->budget--) { s->failed_pc=0x0c0bf320u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c0bf322;
P_0c0bf322: /* original f742, guest PC 0x0c0bf322 */
if(!s->budget--) { s->failed_pc=0x0c0bf322u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0bf324;
P_0c0bf324: /* original f4f6, guest PC 0x0c0bf324 */
if(!s->budget--) { s->failed_pc=0x0c0bf324u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0bf326;
P_0c0bf326: /* original e004, guest PC 0x0c0bf326 */
if(!s->budget--) { s->failed_pc=0x0c0bf326u; return 0; }
r[0]=0x00000004u;
goto P_0c0bf328;
P_0c0bf328: /* original f432, guest PC 0x0c0bf328 */
if(!s->budget--) { s->failed_pc=0x0c0bf328u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0bf32a;
P_0c0bf32a: /* original f3f6, guest PC 0x0c0bf32a */
if(!s->budget--) { s->failed_pc=0x0c0bf32au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0bf32c;
P_0c0bf32c: /* original f7ce, guest PC 0x0c0bf32c */
if(!s->budget--) { s->failed_pc=0x0c0bf32cu; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[12],fr[7],r[18]);
goto P_0c0bf32e;
P_0c0bf32e: /* original e004, guest PC 0x0c0bf32e */
if(!s->budget--) { s->failed_pc=0x0c0bf32eu; return 0; }
r[0]=0x00000004u;
goto P_0c0bf330;
P_0c0bf330: /* original f43e, guest PC 0x0c0bf330 */
if(!s->budget--) { s->failed_pc=0x0c0bf330u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[3],fr[4],r[18]);
goto P_0c0bf332;
P_0c0bf332: /* original fc7c, guest PC 0x0c0bf332 */
if(!s->budget--) { s->failed_pc=0x0c0bf332u; return 0; }
vf3_matrix_move(s,12,7);
goto P_0c0bf334;
P_0c0bf334: /* original ff47, guest PC 0x0c0bf334 */
if(!s->budget--) { s->failed_pc=0x0c0bf334u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0bf336;
P_0c0bf336: /* original e201, guest PC 0x0c0bf336 */
if(!s->budget--) { s->failed_pc=0x0c0bf336u; return 0; }
r[2]=0x00000001u;
goto P_0c0bf338;
P_0c0bf338: /* original d334, guest PC 0x0c0bf338 */
if(!s->budget--) { s->failed_pc=0x0c0bf338u; return 0; }
r[3]=read(ram,0x0c0bf40cu,4);
goto P_0c0bf33a;
P_0c0bf33a: /* original 22d8, guest PC 0x0c0bf33a */
if(!s->budget--) { s->failed_pc=0x0c0bf33au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0bf33c;
P_0c0bf33c: /* original 8d19, guest PC 0x0c0bf33c */
if(!s->budget--) { s->failed_pc=0x0c0bf33cu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(cond) { goto P_0c0bf372; }
goto P_0c0bf340;
P_0c0bf33e: /* original 6432, guest PC 0x0c0bf33e */
if(!s->budget--) { s->failed_pc=0x0c0bf33eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0bf340;
P_0c0bf340: /* original 63d3, guest PC 0x0c0bf340 */
if(!s->budget--) { s->failed_pc=0x0c0bf340u; return 0; }
r[3]=r[13];
goto P_0c0bf342;
P_0c0bf342: /* original 23b8, guest PC 0x0c0bf342 */
if(!s->budget--) { s->failed_pc=0x0c0bf342u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0bf344;
P_0c0bf344: /* original 8b17, guest PC 0x0c0bf344 */
if(!s->budget--) { s->failed_pc=0x0c0bf344u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf376; }
goto P_0c0bf346;
P_0c0bf346: /* original 9058, guest PC 0x0c0bf346 */
if(!s->budget--) { s->failed_pc=0x0c0bf346u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf3fau,2);
goto P_0c0bf348;
P_0c0bf348: /* original 02ee, guest PC 0x0c0bf348 */
if(!s->budget--) { s->failed_pc=0x0c0bf348u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0bf34a;
P_0c0bf34a: /* original 2228, guest PC 0x0c0bf34a */
if(!s->budget--) { s->failed_pc=0x0c0bf34au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0bf34c;
P_0c0bf34c: /* original 8904, guest PC 0x0c0bf34c */
if(!s->budget--) { s->failed_pc=0x0c0bf34cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bf358; }
goto P_0c0bf34e;
P_0c0bf34e: /* original f38d, guest PC 0x0c0bf34e */
if(!s->budget--) { s->failed_pc=0x0c0bf34eu; return 0; }
fr[3]=0;
goto P_0c0bf350;
P_0c0bf350: /* original f3f5, guest PC 0x0c0bf350 */
if(!s->budget--) { s->failed_pc=0x0c0bf350u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0bf352;
P_0c0bf352: /* original 8b71, guest PC 0x0c0bf352 */
if(!s->budget--) { s->failed_pc=0x0c0bf352u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf438; }
goto P_0c0bf354;
P_0c0bf354: /* original a00d, guest PC 0x0c0bf354 */
if(!s->budget--) { s->failed_pc=0x0c0bf354u; return 0; }
goto P_0c0bf372;
P_0c0bf356: /* original 0009, guest PC 0x0c0bf356 */
if(!s->budget--) { s->failed_pc=0x0c0bf356u; return 0; }
goto P_0c0bf358;
P_0c0bf358: /* original 9050, guest PC 0x0c0bf358 */
if(!s->budget--) { s->failed_pc=0x0c0bf358u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf3fcu,2);
goto P_0c0bf35a;
P_0c0bf35a: /* original f3e6, guest PC 0x0c0bf35a */
if(!s->budget--) { s->failed_pc=0x0c0bf35au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0bf35c;
P_0c0bf35c: /* original e048, guest PC 0x0c0bf35c */
if(!s->budget--) { s->failed_pc=0x0c0bf35cu; return 0; }
r[0]=0x00000048u;
goto P_0c0bf35e;
P_0c0bf35e: /* original ff3a, guest PC 0x0c0bf35e */
if(!s->budget--) { s->failed_pc=0x0c0bf35eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0bf360;
P_0c0bf360: /* original 02ee, guest PC 0x0c0bf360 */
if(!s->budget--) { s->failed_pc=0x0c0bf360u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0bf362;
P_0c0bf362: /* original 934c, guest PC 0x0c0bf362 */
if(!s->budget--) { s->failed_pc=0x0c0bf362u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf3feu,2);
goto P_0c0bf364;
P_0c0bf364: /* original 2238, guest PC 0x0c0bf364 */
if(!s->budget--) { s->failed_pc=0x0c0bf364u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0bf366;
P_0c0bf366: /* original 8b06, guest PC 0x0c0bf366 */
if(!s->budget--) { s->failed_pc=0x0c0bf366u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf376; }
goto P_0c0bf368;
P_0c0bf368: /* original e014, guest PC 0x0c0bf368 */
if(!s->budget--) { s->failed_pc=0x0c0bf368u; return 0; }
r[0]=0x00000014u;
goto P_0c0bf36a;
P_0c0bf36a: /* original f3f8, guest PC 0x0c0bf36a */
if(!s->budget--) { s->failed_pc=0x0c0bf36au; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0bf36c;
P_0c0bf36c: /* original f4e6, guest PC 0x0c0bf36c */
if(!s->budget--) { s->failed_pc=0x0c0bf36cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0bf36e;
P_0c0bf36e: /* original f435, guest PC 0x0c0bf36e */
if(!s->budget--) { s->failed_pc=0x0c0bf36eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0bf370;
P_0c0bf370: /* original 8901, guest PC 0x0c0bf370 */
if(!s->budget--) { s->failed_pc=0x0c0bf370u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bf376; }
goto P_0c0bf372;
P_0c0bf372: /* original a061, guest PC 0x0c0bf372 */
if(!s->budget--) { s->failed_pc=0x0c0bf372u; return 0; }
fr[15]=0;
goto P_0c0bf438;
P_0c0bf374: /* original ff8d, guest PC 0x0c0bf374 */
if(!s->budget--) { s->failed_pc=0x0c0bf374u; return 0; }
fr[15]=0;
goto P_0c0bf376;
P_0c0bf376: /* original e008, guest PC 0x0c0bf376 */
if(!s->budget--) { s->failed_pc=0x0c0bf376u; return 0; }
r[0]=0x00000008u;
goto P_0c0bf378;
P_0c0bf378: /* original ff61, guest PC 0x0c0bf378 */
if(!s->budget--) { s->failed_pc=0x0c0bf378u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'-');
goto P_0c0bf37a;
P_0c0bf37a: /* original f3f6, guest PC 0x0c0bf37a */
if(!s->budget--) { s->failed_pc=0x0c0bf37au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0bf37c;
P_0c0bf37c: /* original c724, guest PC 0x0c0bf37c */
if(!s->budget--) { s->failed_pc=0x0c0bf37cu; return 0; }
r[0]=code_base|0x000bf410u;
goto P_0c0bf37e;
P_0c0bf37e: /* original f508, guest PC 0x0c0bf37e */
if(!s->budget--) { s->failed_pc=0x0c0bf37eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0bf380;
P_0c0bf380: /* original 903e, guest PC 0x0c0bf380 */
if(!s->budget--) { s->failed_pc=0x0c0bf380u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf400u,2);
goto P_0c0bf382;
P_0c0bf382: /* original ff30, guest PC 0x0c0bf382 */
if(!s->budget--) { s->failed_pc=0x0c0bf382u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0bf384;
P_0c0bf384: /* original f4e6, guest PC 0x0c0bf384 */
if(!s->budget--) { s->failed_pc=0x0c0bf384u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0bf386;
P_0c0bf386: /* original f450, guest PC 0x0c0bf386 */
if(!s->budget--) { s->failed_pc=0x0c0bf386u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c0bf388;
P_0c0bf388: /* original b093, guest PC 0x0c0bf388 */
if(!s->budget--) { s->failed_pc=0x0c0bf388u; return 0; }
target=code_base|0x0c0bf4b2u; r[16]=code_base|0x0c0bf38cu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bf38cu) { target=s->pc; goto dispatch; }
goto P_0c0bf38c;
P_0c0bf38a: /* original 64f3, guest PC 0x0c0bf38a */
if(!s->budget--) { s->failed_pc=0x0c0bf38au; return 0; }
r[4]=r[15];
goto P_0c0bf38c;
P_0c0bf38c: /* original f38d, guest PC 0x0c0bf38c */
if(!s->budget--) { s->failed_pc=0x0c0bf38cu; return 0; }
fr[3]=0;
goto P_0c0bf38e;
P_0c0bf38e: /* original f035, guest PC 0x0c0bf38e */
if(!s->budget--) { s->failed_pc=0x0c0bf38eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0bf390;
P_0c0bf390: /* original 8952, guest PC 0x0c0bf390 */
if(!s->budget--) { s->failed_pc=0x0c0bf390u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bf438; }
goto P_0c0bf392;
P_0c0bf392: /* original 9336, guest PC 0x0c0bf392 */
if(!s->budget--) { s->failed_pc=0x0c0bf392u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf402u,2);
goto P_0c0bf394;
P_0c0bf394: /* original 2a38, guest PC 0x0c0bf394 */
if(!s->budget--) { s->failed_pc=0x0c0bf394u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c0bf396;
P_0c0bf396: /* original 894f, guest PC 0x0c0bf396 */
if(!s->budget--) { s->failed_pc=0x0c0bf396u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bf438; }
goto P_0c0bf398;
P_0c0bf398: /* original e061, guest PC 0x0c0bf398 */
if(!s->budget--) { s->failed_pc=0x0c0bf398u; return 0; }
r[0]=0x00000061u;
goto P_0c0bf39a;
P_0c0bf39a: /* original 00ec, guest PC 0x0c0bf39a */
if(!s->budget--) { s->failed_pc=0x0c0bf39au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0bf39c;
P_0c0bf39c: /* original 600c, guest PC 0x0c0bf39c */
if(!s->budget--) { s->failed_pc=0x0c0bf39cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0bf39e;
P_0c0bf39e: /* original 8809, guest PC 0x0c0bf39e */
if(!s->budget--) { s->failed_pc=0x0c0bf39eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0bf3a0;
P_0c0bf3a0: /* original 8944, guest PC 0x0c0bf3a0 */
if(!s->budget--) { s->failed_pc=0x0c0bf3a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bf42c; }
goto P_0c0bf3a2;
P_0c0bf3a2: /* original 2db8, guest PC 0x0c0bf3a2 */
if(!s->budget--) { s->failed_pc=0x0c0bf3a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[11])==0)!=0);
goto P_0c0bf3a4;
P_0c0bf3a4: /* original 8948, guest PC 0x0c0bf3a4 */
if(!s->budget--) { s->failed_pc=0x0c0bf3a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bf438; }
goto P_0c0bf3a6;
P_0c0bf3a6: /* original e304, guest PC 0x0c0bf3a6 */
if(!s->budget--) { s->failed_pc=0x0c0bf3a6u; return 0; }
r[3]=0x00000004u;
goto P_0c0bf3a8;
P_0c0bf3a8: /* original 2c38, guest PC 0x0c0bf3a8 */
if(!s->budget--) { s->failed_pc=0x0c0bf3a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c0bf3aa;
P_0c0bf3aa: /* original 8b45, guest PC 0x0c0bf3aa */
if(!s->budget--) { s->failed_pc=0x0c0bf3aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bf438; }
goto P_0c0bf3ac;
P_0c0bf3ac: /* original 64e3, guest PC 0x0c0bf3ac */
if(!s->budget--) { s->failed_pc=0x0c0bf3acu; return 0; }
r[4]=r[14];
goto P_0c0bf3ae;
P_0c0bf3ae: /* original 7438, guest PC 0x0c0bf3ae */
if(!s->budget--) { s->failed_pc=0x0c0bf3aeu; return 0; }
r[4]+=0x00000038u;
goto P_0c0bf3b0;
P_0c0bf3b0: /* original 8443, guest PC 0x0c0bf3b0 */
if(!s->budget--) { s->failed_pc=0x0c0bf3b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0bf3b2;
P_0c0bf3b2: /* original 600c, guest PC 0x0c0bf3b2 */
if(!s->budget--) { s->failed_pc=0x0c0bf3b2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0bf3b4;
P_0c0bf3b4: /* original 881d, guest PC 0x0c0bf3b4 */
if(!s->budget--) { s->failed_pc=0x0c0bf3b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001du)!=0);
goto P_0c0bf3b6;
P_0c0bf3b6: /* original 8d0a, guest PC 0x0c0bf3b6 */
if(!s->budget--) { s->failed_pc=0x0c0bf3b6u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0bf3ce; }
goto P_0c0bf3ba;
P_0c0bf3b8: /* original 6403, guest PC 0x0c0bf3b8 */
if(!s->budget--) { s->failed_pc=0x0c0bf3b8u; return 0; }
r[4]=r[0];
goto P_0c0bf3ba;
P_0c0bf3ba: /* original d316, guest PC 0x0c0bf3ba */
if(!s->budget--) { s->failed_pc=0x0c0bf3bau; return 0; }
r[3]=read(ram,0x0c0bf414u,4);
goto P_0c0bf3bc;
P_0c0bf3bc: /* original 430b, guest PC 0x0c0bf3bc */
if(!s->budget--) { s->failed_pc=0x0c0bf3bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0bf3c0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bf3c0u) { target=s->pc; goto dispatch; }
goto P_0c0bf3c0;
P_0c0bf3be: /* original 64e3, guest PC 0x0c0bf3be */
if(!s->budget--) { s->failed_pc=0x0c0bf3beu; return 0; }
r[4]=r[14];
goto P_0c0bf3c0;
P_0c0bf3c0: /* original d515, guest PC 0x0c0bf3c0 */
if(!s->budget--) { s->failed_pc=0x0c0bf3c0u; return 0; }
r[5]=read(ram,0x0c0bf418u,4);
goto P_0c0bf3c2;
P_0c0bf3c2: /* original b074, guest PC 0x0c0bf3c2 */
if(!s->budget--) { s->failed_pc=0x0c0bf3c2u; return 0; }
target=code_base|0x0c0bf4aeu; r[16]=code_base|0x0c0bf3c6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bf3c6u) { target=s->pc; goto dispatch; }
goto P_0c0bf3c6;
P_0c0bf3c4: /* original 64e3, guest PC 0x0c0bf3c4 */
if(!s->budget--) { s->failed_pc=0x0c0bf3c4u; return 0; }
r[4]=r[14];
goto P_0c0bf3c6;
P_0c0bf3c6: /* original 901d, guest PC 0x0c0bf3c6 */
if(!s->budget--) { s->failed_pc=0x0c0bf3c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf404u,2);
goto P_0c0bf3c8;
P_0c0bf3c8: /* original e3fe, guest PC 0x0c0bf3c8 */
if(!s->budget--) { s->failed_pc=0x0c0bf3c8u; return 0; }
r[3]=0xfffffffeu;
goto P_0c0bf3ca;
P_0c0bf3ca: /* original 2939, guest PC 0x0c0bf3ca */
if(!s->budget--) { s->failed_pc=0x0c0bf3cau; return 0; }
r[9]&=r[3];
goto P_0c0bf3cc;
P_0c0bf3cc: /* original 0e94, guest PC 0x0c0bf3cc */
if(!s->budget--) { s->failed_pc=0x0c0bf3ccu; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c0bf3ce;
P_0c0bf3ce: /* original e00c, guest PC 0x0c0bf3ce */
if(!s->budget--) { s->failed_pc=0x0c0bf3ceu; return 0; }
r[0]=0x0000000cu;
goto P_0c0bf3d0;
P_0c0bf3d0: /* original f2f8, guest PC 0x0c0bf3d0 */
if(!s->budget--) { s->failed_pc=0x0c0bf3d0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0bf3d2;
P_0c0bf3d2: /* original f3f6, guest PC 0x0c0bf3d2 */
if(!s->budget--) { s->failed_pc=0x0c0bf3d2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0bf3d4;
P_0c0bf3d4: /* original c711, guest PC 0x0c0bf3d4 */
if(!s->budget--) { s->failed_pc=0x0c0bf3d4u; return 0; }
r[0]=code_base|0x000bf41cu;
goto P_0c0bf3d6;
P_0c0bf3d6: /* original f231, guest PC 0x0c0bf3d6 */
if(!s->budget--) { s->failed_pc=0x0c0bf3d6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0bf3d8;
P_0c0bf3d8: /* original ff2a, guest PC 0x0c0bf3d8 */
if(!s->budget--) { s->failed_pc=0x0c0bf3d8u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0bf3da;
P_0c0bf3da: /* original f608, guest PC 0x0c0bf3da */
if(!s->budget--) { s->failed_pc=0x0c0bf3dau; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0bf3dc;
P_0c0bf3dc: /* original c710, guest PC 0x0c0bf3dc */
if(!s->budget--) { s->failed_pc=0x0c0bf3dcu; return 0; }
r[0]=code_base|0x000bf420u;
goto P_0c0bf3de;
P_0c0bf3de: /* original f508, guest PC 0x0c0bf3de */
if(!s->budget--) { s->failed_pc=0x0c0bf3deu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0bf3e0;
P_0c0bf3e0: /* original c710, guest PC 0x0c0bf3e0 */
if(!s->budget--) { s->failed_pc=0x0c0bf3e0u; return 0; }
r[0]=code_base|0x000bf424u;
goto P_0c0bf3e2;
P_0c0bf3e2: /* original f708, guest PC 0x0c0bf3e2 */
if(!s->budget--) { s->failed_pc=0x0c0bf3e2u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0bf3e4;
P_0c0bf3e4: /* original c710, guest PC 0x0c0bf3e4 */
if(!s->budget--) { s->failed_pc=0x0c0bf3e4u; return 0; }
r[0]=code_base|0x000bf428u;
goto P_0c0bf3e6;
P_0c0bf3e6: /* original f408, guest PC 0x0c0bf3e6 */
if(!s->budget--) { s->failed_pc=0x0c0bf3e6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0bf3e8;
P_0c0bf3e8: /* original f270, guest PC 0x0c0bf3e8 */
if(!s->budget--) { s->failed_pc=0x0c0bf3e8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'+');
goto P_0c0bf3ea;
P_0c0bf3ea: /* original fe42, guest PC 0x0c0bf3ea */
if(!s->budget--) { s->failed_pc=0x0c0bf3eau; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c0bf3ec;
P_0c0bf3ec: /* original f262, guest PC 0x0c0bf3ec */
if(!s->budget--) { s->failed_pc=0x0c0bf3ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c0bf3ee;
P_0c0bf3ee: /* original ff2a, guest PC 0x0c0bf3ee */
if(!s->budget--) { s->failed_pc=0x0c0bf3eeu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0bf3f0;
P_0c0bf3f0: /* original f05c, guest PC 0x0c0bf3f0 */
if(!s->budget--) { s->failed_pc=0x0c0bf3f0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0bf3f2;
P_0c0bf3f2: /* original f2fe, guest PC 0x0c0bf3f2 */
if(!s->budget--) { s->failed_pc=0x0c0bf3f2u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[15],fr[2],r[18]);
goto P_0c0bf3f4;
P_0c0bf3f4: /* original ff2c, guest PC 0x0c0bf3f4 */
if(!s->budget--) { s->failed_pc=0x0c0bf3f4u; return 0; }
vf3_matrix_move(s,15,2);
goto P_0c0bf3f6;
P_0c0bf3f6: /* original a01f, guest PC 0x0c0bf3f6 */
if(!s->budget--) { s->failed_pc=0x0c0bf3f6u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c0bf438;
P_0c0bf3f8: /* original fd42, guest PC 0x0c0bf3f8 */
if(!s->budget--) { s->failed_pc=0x0c0bf3f8u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
if(!vf3_matrix_family(0x0c0bf3fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bf3fau; return 0; } return 1;
P_0c0bf42c: /* original c746, guest PC 0x0c0bf42c */
if(!s->budget--) { s->failed_pc=0x0c0bf42cu; return 0; }
r[0]=code_base|0x000bf548u;
goto P_0c0bf42e;
P_0c0bf42e: /* original f308, guest PC 0x0c0bf42e */
if(!s->budget--) { s->failed_pc=0x0c0bf42eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0bf430;
P_0c0bf430: /* original ff32, guest PC 0x0c0bf430 */
if(!s->budget--) { s->failed_pc=0x0c0bf430u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c0bf432;
P_0c0bf432: /* original ff3a, guest PC 0x0c0bf432 */
if(!s->budget--) { s->failed_pc=0x0c0bf432u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0bf434;
P_0c0bf434: /* original fe32, guest PC 0x0c0bf434 */
if(!s->budget--) { s->failed_pc=0x0c0bf434u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c0bf436;
P_0c0bf436: /* original fd32, guest PC 0x0c0bf436 */
if(!s->budget--) { s->failed_pc=0x0c0bf436u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'*');
goto P_0c0bf438;
P_0c0bf438: /* original e024, guest PC 0x0c0bf438 */
if(!s->budget--) { s->failed_pc=0x0c0bf438u; return 0; }
r[0]=0x00000024u;
goto P_0c0bf43a;
P_0c0bf43a: /* original fee7, guest PC 0x0c0bf43a */
if(!s->budget--) { s->failed_pc=0x0c0bf43au; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0bf43c;
P_0c0bf43c: /* original e028, guest PC 0x0c0bf43c */
if(!s->budget--) { s->failed_pc=0x0c0bf43cu; return 0; }
r[0]=0x00000028u;
goto P_0c0bf43e;
P_0c0bf43e: /* original fef7, guest PC 0x0c0bf43e */
if(!s->budget--) { s->failed_pc=0x0c0bf43eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0bf440;
P_0c0bf440: /* original e02c, guest PC 0x0c0bf440 */
if(!s->budget--) { s->failed_pc=0x0c0bf440u; return 0; }
r[0]=0x0000002cu;
goto P_0c0bf442;
P_0c0bf442: /* original fed7, guest PC 0x0c0bf442 */
if(!s->budget--) { s->failed_pc=0x0c0bf442u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c0bf444;
P_0c0bf444: /* original 907a, guest PC 0x0c0bf444 */
if(!s->budget--) { s->failed_pc=0x0c0bf444u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf53cu,2);
goto P_0c0bf446;
P_0c0bf446: /* original fec7, guest PC 0x0c0bf446 */
if(!s->budget--) { s->failed_pc=0x0c0bf446u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0bf448;
P_0c0bf448: /* original e008, guest PC 0x0c0bf448 */
if(!s->budget--) { s->failed_pc=0x0c0bf448u; return 0; }
r[0]=0x00000008u;
goto P_0c0bf44a;
P_0c0bf44a: /* original f3f6, guest PC 0x0c0bf44a */
if(!s->budget--) { s->failed_pc=0x0c0bf44au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0bf44c;
P_0c0bf44c: /* original 9077, guest PC 0x0c0bf44c */
if(!s->budget--) { s->failed_pc=0x0c0bf44cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf53eu,2);
goto P_0c0bf44e;
P_0c0bf44e: /* original fe37, guest PC 0x0c0bf44e */
if(!s->budget--) { s->failed_pc=0x0c0bf44eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0bf450;
P_0c0bf450: /* original e004, guest PC 0x0c0bf450 */
if(!s->budget--) { s->failed_pc=0x0c0bf450u; return 0; }
r[0]=0x00000004u;
goto P_0c0bf452;
P_0c0bf452: /* original f3f6, guest PC 0x0c0bf452 */
if(!s->budget--) { s->failed_pc=0x0c0bf452u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0bf454;
P_0c0bf454: /* original 9074, guest PC 0x0c0bf454 */
if(!s->budget--) { s->failed_pc=0x0c0bf454u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bf540u,2);
goto P_0c0bf456;
P_0c0bf456: /* original fe37, guest PC 0x0c0bf456 */
if(!s->budget--) { s->failed_pc=0x0c0bf456u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0bf458;
P_0c0bf458: /* original e010, guest PC 0x0c0bf458 */
if(!s->budget--) { s->failed_pc=0x0c0bf458u; return 0; }
r[0]=0x00000010u;
goto P_0c0bf45a;
P_0c0bf45a: /* original f3e6, guest PC 0x0c0bf45a */
if(!s->budget--) { s->failed_pc=0x0c0bf45au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0bf45c;
P_0c0bf45c: /* original e014, guest PC 0x0c0bf45c */
if(!s->budget--) { s->failed_pc=0x0c0bf45cu; return 0; }
r[0]=0x00000014u;
goto P_0c0bf45e;
P_0c0bf45e: /* original f4ec, guest PC 0x0c0bf45e */
if(!s->budget--) { s->failed_pc=0x0c0bf45eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0bf460;
P_0c0bf460: /* original f6e6, guest PC 0x0c0bf460 */
if(!s->budget--) { s->failed_pc=0x0c0bf460u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0bf462;
P_0c0bf462: /* original f430, guest PC 0x0c0bf462 */
if(!s->budget--) { s->failed_pc=0x0c0bf462u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0bf464;
P_0c0bf464: /* original e018, guest PC 0x0c0bf464 */
if(!s->budget--) { s->failed_pc=0x0c0bf464u; return 0; }
r[0]=0x00000018u;
goto P_0c0bf466;
P_0c0bf466: /* original f36c, guest PC 0x0c0bf466 */
if(!s->budget--) { s->failed_pc=0x0c0bf466u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0bf468;
P_0c0bf468: /* original f6fc, guest PC 0x0c0bf468 */
if(!s->budget--) { s->failed_pc=0x0c0bf468u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0bf46a;
P_0c0bf46a: /* original f630, guest PC 0x0c0bf46a */
if(!s->budget--) { s->failed_pc=0x0c0bf46au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0bf46c;
P_0c0bf46c: /* original f5e6, guest PC 0x0c0bf46c */
if(!s->budget--) { s->failed_pc=0x0c0bf46cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0bf46e;
P_0c0bf46e: /* original f35c, guest PC 0x0c0bf46e */
if(!s->budget--) { s->failed_pc=0x0c0bf46eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0bf470;
P_0c0bf470: /* original f5dc, guest PC 0x0c0bf470 */
if(!s->budget--) { s->failed_pc=0x0c0bf470u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c0bf472;
P_0c0bf472: /* original f530, guest PC 0x0c0bf472 */
if(!s->budget--) { s->failed_pc=0x0c0bf472u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0bf474;
P_0c0bf474: /* original f34c, guest PC 0x0c0bf474 */
if(!s->budget--) { s->failed_pc=0x0c0bf474u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0bf476;
P_0c0bf476: /* original f4cc, guest PC 0x0c0bf476 */
if(!s->budget--) { s->failed_pc=0x0c0bf476u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c0bf478;
P_0c0bf478: /* original f430, guest PC 0x0c0bf478 */
if(!s->budget--) { s->failed_pc=0x0c0bf478u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0bf47a;
P_0c0bf47a: /* original e004, guest PC 0x0c0bf47a */
if(!s->budget--) { s->failed_pc=0x0c0bf47au; return 0; }
r[0]=0x00000004u;
goto P_0c0bf47c;
P_0c0bf47c: /* original f35c, guest PC 0x0c0bf47c */
if(!s->budget--) { s->failed_pc=0x0c0bf47cu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0bf47e;
P_0c0bf47e: /* original f5f6, guest PC 0x0c0bf47e */
if(!s->budget--) { s->failed_pc=0x0c0bf47eu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0bf480;
P_0c0bf480: /* original e010, guest PC 0x0c0bf480 */
if(!s->budget--) { s->failed_pc=0x0c0bf480u; return 0; }
r[0]=0x00000010u;
goto P_0c0bf482;
P_0c0bf482: /* original fe47, guest PC 0x0c0bf482 */
if(!s->budget--) { s->failed_pc=0x0c0bf482u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0bf484;
P_0c0bf484: /* original f530, guest PC 0x0c0bf484 */
if(!s->budget--) { s->failed_pc=0x0c0bf484u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0bf486;
P_0c0bf486: /* original e014, guest PC 0x0c0bf486 */
if(!s->budget--) { s->failed_pc=0x0c0bf486u; return 0; }
r[0]=0x00000014u;
goto P_0c0bf488;
P_0c0bf488: /* original fe67, guest PC 0x0c0bf488 */
if(!s->budget--) { s->failed_pc=0x0c0bf488u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0bf48a;
P_0c0bf48a: /* original e018, guest PC 0x0c0bf48a */
if(!s->budget--) { s->failed_pc=0x0c0bf48au; return 0; }
r[0]=0x00000018u;
goto P_0c0bf48c;
P_0c0bf48c: /* original fe57, guest PC 0x0c0bf48c */
if(!s->budget--) { s->failed_pc=0x0c0bf48cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0bf48e;
P_0c0bf48e: /* original d32f, guest PC 0x0c0bf48e */
if(!s->budget--) { s->failed_pc=0x0c0bf48eu; return 0; }
r[3]=read(ram,0x0c0bf54cu,4);
goto P_0c0bf490;
P_0c0bf490: /* original 430b, guest PC 0x0c0bf490 */
if(!s->budget--) { s->failed_pc=0x0c0bf490u; return 0; }
target=r[3];
r[16]=code_base|0x0c0bf494u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bf494u) { target=s->pc; goto dispatch; }
goto P_0c0bf494;
P_0c0bf492: /* original e401, guest PC 0x0c0bf492 */
if(!s->budget--) { s->failed_pc=0x0c0bf492u; return 0; }
r[4]=0x00000001u;
goto P_0c0bf494;
P_0c0bf494: /* original 7f10, guest PC 0x0c0bf494 */
if(!s->budget--) { s->failed_pc=0x0c0bf494u; return 0; }
r[15]+=0x00000010u;
goto P_0c0bf496;
P_0c0bf496: /* original 4f26, guest PC 0x0c0bf496 */
if(!s->budget--) { s->failed_pc=0x0c0bf496u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bf498;
P_0c0bf498: /* original fcf9, guest PC 0x0c0bf498 */
if(!s->budget--) { s->failed_pc=0x0c0bf498u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0bf49a;
P_0c0bf49a: /* original fdf9, guest PC 0x0c0bf49a */
if(!s->budget--) { s->failed_pc=0x0c0bf49au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0bf49c;
P_0c0bf49c: /* original fef9, guest PC 0x0c0bf49c */
if(!s->budget--) { s->failed_pc=0x0c0bf49cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0bf49e;
P_0c0bf49e: /* original fff9, guest PC 0x0c0bf49e */
if(!s->budget--) { s->failed_pc=0x0c0bf49eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0bf4a0;
P_0c0bf4a0: /* original 69f6, guest PC 0x0c0bf4a0 */
if(!s->budget--) { s->failed_pc=0x0c0bf4a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0bf4a2;
P_0c0bf4a2: /* original 6af6, guest PC 0x0c0bf4a2 */
if(!s->budget--) { s->failed_pc=0x0c0bf4a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bf4a4;
P_0c0bf4a4: /* original 6bf6, guest PC 0x0c0bf4a4 */
if(!s->budget--) { s->failed_pc=0x0c0bf4a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bf4a6;
P_0c0bf4a6: /* original 6cf6, guest PC 0x0c0bf4a6 */
if(!s->budget--) { s->failed_pc=0x0c0bf4a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bf4a8;
P_0c0bf4a8: /* original 6df6, guest PC 0x0c0bf4a8 */
if(!s->budget--) { s->failed_pc=0x0c0bf4a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bf4aa;
P_0c0bf4aa: /* original 000b, guest PC 0x0c0bf4aa */
if(!s->budget--) { s->failed_pc=0x0c0bf4aau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bf4ac: /* original 6ef6, guest PC 0x0c0bf4ac */
if(!s->budget--) { s->failed_pc=0x0c0bf4acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0bf4aeu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
