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
int vf3_away_batch11_adapter_42(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c081098u: goto P_0c081098;
case 0x0c08109au: goto P_0c08109a;
case 0x0c08109cu: goto P_0c08109c;
case 0x0c08109eu: goto P_0c08109e;
case 0x0c0810a0u: goto P_0c0810a0;
case 0x0c0810a2u: goto P_0c0810a2;
case 0x0c0810a4u: goto P_0c0810a4;
case 0x0c0810a6u: goto P_0c0810a6;
case 0x0c0810a8u: goto P_0c0810a8;
case 0x0c0810aau: goto P_0c0810aa;
case 0x0c0810acu: goto P_0c0810ac;
case 0x0c0810aeu: goto P_0c0810ae;
case 0x0c0810b0u: goto P_0c0810b0;
case 0x0c0810b2u: goto P_0c0810b2;
case 0x0c0810b4u: goto P_0c0810b4;
case 0x0c0810b6u: goto P_0c0810b6;
case 0x0c0810b8u: goto P_0c0810b8;
case 0x0c0810bau: goto P_0c0810ba;
case 0x0c0810bcu: goto P_0c0810bc;
case 0x0c0810beu: goto P_0c0810be;
case 0x0c0810c0u: goto P_0c0810c0;
case 0x0c0810c2u: goto P_0c0810c2;
case 0x0c0810c4u: goto P_0c0810c4;
case 0x0c0810c6u: goto P_0c0810c6;
case 0x0c0810c8u: goto P_0c0810c8;
case 0x0c0810cau: goto P_0c0810ca;
case 0x0c0810ccu: goto P_0c0810cc;
case 0x0c0810ceu: goto P_0c0810ce;
case 0x0c0810d0u: goto P_0c0810d0;
case 0x0c0810d2u: goto P_0c0810d2;
case 0x0c0810d4u: goto P_0c0810d4;
case 0x0c0810d6u: goto P_0c0810d6;
case 0x0c0810d8u: goto P_0c0810d8;
case 0x0c0810dau: goto P_0c0810da;
case 0x0c0810dcu: goto P_0c0810dc;
case 0x0c0810deu: goto P_0c0810de;
case 0x0c0810e0u: goto P_0c0810e0;
case 0x0c0810e2u: goto P_0c0810e2;
case 0x0c0810e4u: goto P_0c0810e4;
case 0x0c0810e6u: goto P_0c0810e6;
case 0x0c0810e8u: goto P_0c0810e8;
case 0x0c0810eau: goto P_0c0810ea;
case 0x0c0810ecu: goto P_0c0810ec;
case 0x0c0810eeu: goto P_0c0810ee;
case 0x0c0810f0u: goto P_0c0810f0;
case 0x0c0810f2u: goto P_0c0810f2;
case 0x0c0810f4u: goto P_0c0810f4;
case 0x0c0810f6u: goto P_0c0810f6;
case 0x0c0810f8u: goto P_0c0810f8;
case 0x0c0810fau: goto P_0c0810fa;
case 0x0c0810fcu: goto P_0c0810fc;
case 0x0c0810feu: goto P_0c0810fe;
case 0x0c081100u: goto P_0c081100;
case 0x0c081102u: goto P_0c081102;
case 0x0c081104u: goto P_0c081104;
case 0x0c081106u: goto P_0c081106;
case 0x0c081108u: goto P_0c081108;
case 0x0c08110au: goto P_0c08110a;
case 0x0c08110cu: goto P_0c08110c;
case 0x0c08110eu: goto P_0c08110e;
case 0x0c081110u: goto P_0c081110;
case 0x0c081112u: goto P_0c081112;
case 0x0c081114u: goto P_0c081114;
case 0x0c081116u: goto P_0c081116;
case 0x0c081118u: goto P_0c081118;
case 0x0c08111au: goto P_0c08111a;
case 0x0c08111cu: goto P_0c08111c;
case 0x0c08111eu: goto P_0c08111e;
case 0x0c081120u: goto P_0c081120;
case 0x0c081122u: goto P_0c081122;
case 0x0c081124u: goto P_0c081124;
case 0x0c081126u: goto P_0c081126;
case 0x0c081184u: goto P_0c081184;
case 0x0c081186u: goto P_0c081186;
case 0x0c081188u: goto P_0c081188;
case 0x0c08118au: goto P_0c08118a;
case 0x0c08118cu: goto P_0c08118c;
case 0x0c08118eu: goto P_0c08118e;
case 0x0c081190u: goto P_0c081190;
case 0x0c081192u: goto P_0c081192;
case 0x0c081194u: goto P_0c081194;
case 0x0c081196u: goto P_0c081196;
case 0x0c081198u: goto P_0c081198;
case 0x0c08119au: goto P_0c08119a;
case 0x0c08119cu: goto P_0c08119c;
case 0x0c08119eu: goto P_0c08119e;
case 0x0c0811a0u: goto P_0c0811a0;
case 0x0c0811a2u: goto P_0c0811a2;
case 0x0c0811a4u: goto P_0c0811a4;
case 0x0c0811a6u: goto P_0c0811a6;
case 0x0c0811a8u: goto P_0c0811a8;
case 0x0c0811aau: goto P_0c0811aa;
case 0x0c0811acu: goto P_0c0811ac;
case 0x0c0811aeu: goto P_0c0811ae;
case 0x0c0811b0u: goto P_0c0811b0;
case 0x0c0811b2u: goto P_0c0811b2;
case 0x0c0811b4u: goto P_0c0811b4;
case 0x0c0811b6u: goto P_0c0811b6;
case 0x0c0811b8u: goto P_0c0811b8;
case 0x0c0811bau: goto P_0c0811ba;
case 0x0c0811bcu: goto P_0c0811bc;
case 0x0c0811beu: goto P_0c0811be;
case 0x0c0811c0u: goto P_0c0811c0;
case 0x0c0811c2u: goto P_0c0811c2;
case 0x0c0811c4u: goto P_0c0811c4;
case 0x0c0811c6u: goto P_0c0811c6;
case 0x0c0811c8u: goto P_0c0811c8;
case 0x0c0811cau: goto P_0c0811ca;
case 0x0c0811ccu: goto P_0c0811cc;
case 0x0c0811ceu: goto P_0c0811ce;
case 0x0c0811d0u: goto P_0c0811d0;
case 0x0c0811d2u: goto P_0c0811d2;
case 0x0c0811d4u: goto P_0c0811d4;
case 0x0c0811d6u: goto P_0c0811d6;
case 0x0c0811d8u: goto P_0c0811d8;
case 0x0c0811dau: goto P_0c0811da;
case 0x0c0811dcu: goto P_0c0811dc;
case 0x0c0811deu: goto P_0c0811de;
case 0x0c0811e0u: goto P_0c0811e0;
case 0x0c0811e2u: goto P_0c0811e2;
case 0x0c0811e4u: goto P_0c0811e4;
case 0x0c0811e6u: goto P_0c0811e6;
case 0x0c0811e8u: goto P_0c0811e8;
case 0x0c0811eau: goto P_0c0811ea;
case 0x0c0811ecu: goto P_0c0811ec;
case 0x0c0811eeu: goto P_0c0811ee;
case 0x0c0811f0u: goto P_0c0811f0;
case 0x0c0811f2u: goto P_0c0811f2;
case 0x0c0811f4u: goto P_0c0811f4;
case 0x0c0811f6u: goto P_0c0811f6;
case 0x0c0811f8u: goto P_0c0811f8;
case 0x0c0811fau: goto P_0c0811fa;
case 0x0c0811fcu: goto P_0c0811fc;
case 0x0c0811feu: goto P_0c0811fe;
case 0x0c081200u: goto P_0c081200;
case 0x0c081202u: goto P_0c081202;
case 0x0c081204u: goto P_0c081204;
case 0x0c081206u: goto P_0c081206;
case 0x0c081208u: goto P_0c081208;
case 0x0c08120au: goto P_0c08120a;
case 0x0c08120cu: goto P_0c08120c;
case 0x0c08120eu: goto P_0c08120e;
case 0x0c081210u: goto P_0c081210;
case 0x0c081212u: goto P_0c081212;
case 0x0c081214u: goto P_0c081214;
case 0x0c081216u: goto P_0c081216;
case 0x0c081218u: goto P_0c081218;
case 0x0c08121au: goto P_0c08121a;
case 0x0c08121cu: goto P_0c08121c;
case 0x0c08121eu: goto P_0c08121e;
case 0x0c081220u: goto P_0c081220;
case 0x0c081222u: goto P_0c081222;
case 0x0c081224u: goto P_0c081224;
case 0x0c081226u: goto P_0c081226;
case 0x0c081228u: goto P_0c081228;
case 0x0c08122au: goto P_0c08122a;
case 0x0c08122cu: goto P_0c08122c;
case 0x0c08122eu: goto P_0c08122e;
case 0x0c081230u: goto P_0c081230;
case 0x0c081232u: goto P_0c081232;
case 0x0c081234u: goto P_0c081234;
case 0x0c081236u: goto P_0c081236;
case 0x0c081238u: goto P_0c081238;
case 0x0c08123au: goto P_0c08123a;
case 0x0c08123cu: goto P_0c08123c;
case 0x0c08123eu: goto P_0c08123e;
case 0x0c081240u: goto P_0c081240;
case 0x0c081242u: goto P_0c081242;
case 0x0c081244u: goto P_0c081244;
case 0x0c081246u: goto P_0c081246;
case 0x0c081248u: goto P_0c081248;
case 0x0c08124au: goto P_0c08124a;
case 0x0c081288u: goto P_0c081288;
case 0x0c08128au: goto P_0c08128a;
case 0x0c08128cu: goto P_0c08128c;
case 0x0c08128eu: goto P_0c08128e;
case 0x0c081290u: goto P_0c081290;
case 0x0c081292u: goto P_0c081292;
case 0x0c081294u: goto P_0c081294;
case 0x0c081296u: goto P_0c081296;
case 0x0c081298u: goto P_0c081298;
case 0x0c08129au: goto P_0c08129a;
case 0x0c08129cu: goto P_0c08129c;
case 0x0c08129eu: goto P_0c08129e;
case 0x0c0812a0u: goto P_0c0812a0;
case 0x0c0812a2u: goto P_0c0812a2;
case 0x0c0812a4u: goto P_0c0812a4;
case 0x0c0812a6u: goto P_0c0812a6;
case 0x0c0812a8u: goto P_0c0812a8;
case 0x0c0812aau: goto P_0c0812aa;
case 0x0c0812acu: goto P_0c0812ac;
case 0x0c0812aeu: goto P_0c0812ae;
case 0x0c0812b0u: goto P_0c0812b0;
case 0x0c0812b2u: goto P_0c0812b2;
case 0x0c0812b4u: goto P_0c0812b4;
case 0x0c0812b6u: goto P_0c0812b6;
case 0x0c0812b8u: goto P_0c0812b8;
case 0x0c0812bau: goto P_0c0812ba;
case 0x0c0812bcu: goto P_0c0812bc;
case 0x0c0812beu: goto P_0c0812be;
case 0x0c0812c0u: goto P_0c0812c0;
case 0x0c0812c2u: goto P_0c0812c2;
case 0x0c0812c4u: goto P_0c0812c4;
case 0x0c0812c6u: goto P_0c0812c6;
case 0x0c0812c8u: goto P_0c0812c8;
case 0x0c0812cau: goto P_0c0812ca;
case 0x0c0812ccu: goto P_0c0812cc;
case 0x0c0812ceu: goto P_0c0812ce;
case 0x0c0812d0u: goto P_0c0812d0;
case 0x0c0812d2u: goto P_0c0812d2;
case 0x0c0812d4u: goto P_0c0812d4;
case 0x0c0812d6u: goto P_0c0812d6;
case 0x0c0812d8u: goto P_0c0812d8;
case 0x0c0812dau: goto P_0c0812da;
case 0x0c0812dcu: goto P_0c0812dc;
case 0x0c0812deu: goto P_0c0812de;
case 0x0c0812e0u: goto P_0c0812e0;
case 0x0c0812e2u: goto P_0c0812e2;
case 0x0c0812e4u: goto P_0c0812e4;
case 0x0c0812e6u: goto P_0c0812e6;
case 0x0c0812e8u: goto P_0c0812e8;
case 0x0c0812eau: goto P_0c0812ea;
case 0x0c0812ecu: goto P_0c0812ec;
case 0x0c0812eeu: goto P_0c0812ee;
case 0x0c0812f0u: goto P_0c0812f0;
case 0x0c0812f2u: goto P_0c0812f2;
case 0x0c0812f4u: goto P_0c0812f4;
case 0x0c0812f6u: goto P_0c0812f6;
case 0x0c0812f8u: goto P_0c0812f8;
case 0x0c0812fau: goto P_0c0812fa;
case 0x0c0812fcu: goto P_0c0812fc;
case 0x0c0812feu: goto P_0c0812fe;
case 0x0c081300u: goto P_0c081300;
case 0x0c081302u: goto P_0c081302;
case 0x0c081304u: goto P_0c081304;
case 0x0c081306u: goto P_0c081306;
case 0x0c081308u: goto P_0c081308;
case 0x0c08130au: goto P_0c08130a;
case 0x0c08130cu: goto P_0c08130c;
case 0x0c08130eu: goto P_0c08130e;
case 0x0c081310u: goto P_0c081310;
case 0x0c081312u: goto P_0c081312;
case 0x0c081314u: goto P_0c081314;
case 0x0c081316u: goto P_0c081316;
case 0x0c081318u: goto P_0c081318;
case 0x0c08131au: goto P_0c08131a;
case 0x0c08131cu: goto P_0c08131c;
case 0x0c08131eu: goto P_0c08131e;
case 0x0c081320u: goto P_0c081320;
case 0x0c081322u: goto P_0c081322;
case 0x0c081324u: goto P_0c081324;
case 0x0c081326u: goto P_0c081326;
case 0x0c081328u: goto P_0c081328;
case 0x0c08132au: goto P_0c08132a;
case 0x0c08132cu: goto P_0c08132c;
case 0x0c08132eu: goto P_0c08132e;
case 0x0c081330u: goto P_0c081330;
case 0x0c081332u: goto P_0c081332;
case 0x0c081334u: goto P_0c081334;
case 0x0c081336u: goto P_0c081336;
case 0x0c081338u: goto P_0c081338;
case 0x0c08133au: goto P_0c08133a;
case 0x0c08133cu: goto P_0c08133c;
case 0x0c08133eu: goto P_0c08133e;
case 0x0c081340u: goto P_0c081340;
case 0x0c081342u: goto P_0c081342;
case 0x0c081344u: goto P_0c081344;
case 0x0c081346u: goto P_0c081346;
case 0x0c081348u: goto P_0c081348;
case 0x0c08134au: goto P_0c08134a;
case 0x0c08134cu: goto P_0c08134c;
case 0x0c08134eu: goto P_0c08134e;
case 0x0c081350u: goto P_0c081350;
case 0x0c081352u: goto P_0c081352;
case 0x0c081354u: goto P_0c081354;
case 0x0c081356u: goto P_0c081356;
case 0x0c081358u: goto P_0c081358;
case 0x0c08135au: goto P_0c08135a;
case 0x0c08135cu: goto P_0c08135c;
case 0x0c08135eu: goto P_0c08135e;
case 0x0c081360u: goto P_0c081360;
case 0x0c081362u: goto P_0c081362;
case 0x0c081364u: goto P_0c081364;
case 0x0c081366u: goto P_0c081366;
case 0x0c081368u: goto P_0c081368;
case 0x0c08136au: goto P_0c08136a;
case 0x0c08136cu: goto P_0c08136c;
case 0x0c08136eu: goto P_0c08136e;
case 0x0c081370u: goto P_0c081370;
case 0x0c081372u: goto P_0c081372;
case 0x0c081374u: goto P_0c081374;
case 0x0c081376u: goto P_0c081376;
case 0x0c081378u: goto P_0c081378;
case 0x0c08137au: goto P_0c08137a;
case 0x0c0813acu: goto P_0c0813ac;
case 0x0c0813aeu: goto P_0c0813ae;
case 0x0c0813b0u: goto P_0c0813b0;
case 0x0c0813b2u: goto P_0c0813b2;
case 0x0c0813b4u: goto P_0c0813b4;
case 0x0c0813b6u: goto P_0c0813b6;
case 0x0c0813b8u: goto P_0c0813b8;
case 0x0c0813bau: goto P_0c0813ba;
case 0x0c0813bcu: goto P_0c0813bc;
case 0x0c0813beu: goto P_0c0813be;
case 0x0c0813c0u: goto P_0c0813c0;
case 0x0c0813c2u: goto P_0c0813c2;
case 0x0c0813c4u: goto P_0c0813c4;
case 0x0c0813c6u: goto P_0c0813c6;
case 0x0c0813c8u: goto P_0c0813c8;
case 0x0c0813cau: goto P_0c0813ca;
case 0x0c0813ccu: goto P_0c0813cc;
case 0x0c0813ceu: goto P_0c0813ce;
case 0x0c0813d0u: goto P_0c0813d0;
case 0x0c0813d2u: goto P_0c0813d2;
case 0x0c0813d4u: goto P_0c0813d4;
case 0x0c0813d6u: goto P_0c0813d6;
case 0x0c0813d8u: goto P_0c0813d8;
case 0x0c0813dau: goto P_0c0813da;
case 0x0c0813dcu: goto P_0c0813dc;
case 0x0c0813deu: goto P_0c0813de;
case 0x0c0813e0u: goto P_0c0813e0;
case 0x0c0813e2u: goto P_0c0813e2;
case 0x0c0813e4u: goto P_0c0813e4;
case 0x0c0813e6u: goto P_0c0813e6;
case 0x0c0813e8u: goto P_0c0813e8;
case 0x0c0813eau: goto P_0c0813ea;
case 0x0c0813ecu: goto P_0c0813ec;
case 0x0c0813eeu: goto P_0c0813ee;
case 0x0c0813f0u: goto P_0c0813f0;
case 0x0c0813f2u: goto P_0c0813f2;
case 0x0c0813f4u: goto P_0c0813f4;
case 0x0c0813f6u: goto P_0c0813f6;
case 0x0c0813f8u: goto P_0c0813f8;
case 0x0c0813fau: goto P_0c0813fa;
case 0x0c0813fcu: goto P_0c0813fc;
case 0x0c0813feu: goto P_0c0813fe;
case 0x0c081400u: goto P_0c081400;
case 0x0c081402u: goto P_0c081402;
case 0x0c081404u: goto P_0c081404;
case 0x0c081406u: goto P_0c081406;
case 0x0c081408u: goto P_0c081408;
case 0x0c08140au: goto P_0c08140a;
case 0x0c08140cu: goto P_0c08140c;
case 0x0c08140eu: goto P_0c08140e;
case 0x0c081410u: goto P_0c081410;
case 0x0c081412u: goto P_0c081412;
case 0x0c081414u: goto P_0c081414;
case 0x0c081416u: goto P_0c081416;
case 0x0c081418u: goto P_0c081418;
case 0x0c08141au: goto P_0c08141a;
case 0x0c08141cu: goto P_0c08141c;
case 0x0c08141eu: goto P_0c08141e;
case 0x0c081420u: goto P_0c081420;
case 0x0c081422u: goto P_0c081422;
case 0x0c081424u: goto P_0c081424;
case 0x0c081426u: goto P_0c081426;
case 0x0c081428u: goto P_0c081428;
case 0x0c08142au: goto P_0c08142a;
case 0x0c08142cu: goto P_0c08142c;
case 0x0c08142eu: goto P_0c08142e;
case 0x0c081430u: goto P_0c081430;
case 0x0c081432u: goto P_0c081432;
case 0x0c081434u: goto P_0c081434;
case 0x0c081436u: goto P_0c081436;
case 0x0c081438u: goto P_0c081438;
case 0x0c08143au: goto P_0c08143a;
case 0x0c08143cu: goto P_0c08143c;
case 0x0c08143eu: goto P_0c08143e;
case 0x0c081440u: goto P_0c081440;
case 0x0c081442u: goto P_0c081442;
case 0x0c081444u: goto P_0c081444;
case 0x0c081446u: goto P_0c081446;
case 0x0c081448u: goto P_0c081448;
case 0x0c08144au: goto P_0c08144a;
case 0x0c08144cu: goto P_0c08144c;
case 0x0c08144eu: goto P_0c08144e;
case 0x0c081450u: goto P_0c081450;
case 0x0c081452u: goto P_0c081452;
case 0x0c081454u: goto P_0c081454;
case 0x0c081456u: goto P_0c081456;
case 0x0c081458u: goto P_0c081458;
case 0x0c08145au: goto P_0c08145a;
case 0x0c08145cu: goto P_0c08145c;
case 0x0c08145eu: goto P_0c08145e;
case 0x0c081460u: goto P_0c081460;
case 0x0c081462u: goto P_0c081462;
case 0x0c081464u: goto P_0c081464;
case 0x0c081466u: goto P_0c081466;
case 0x0c081468u: goto P_0c081468;
case 0x0c08146au: goto P_0c08146a;
case 0x0c08146cu: goto P_0c08146c;
case 0x0c08146eu: goto P_0c08146e;
case 0x0c081470u: goto P_0c081470;
case 0x0c081472u: goto P_0c081472;
case 0x0c081474u: goto P_0c081474;
case 0x0c081476u: goto P_0c081476;
case 0x0c081478u: goto P_0c081478;
case 0x0c08147au: goto P_0c08147a;
case 0x0c08147cu: goto P_0c08147c;
case 0x0c08147eu: goto P_0c08147e;
case 0x0c081480u: goto P_0c081480;
case 0x0c081482u: goto P_0c081482;
case 0x0c081484u: goto P_0c081484;
case 0x0c081486u: goto P_0c081486;
case 0x0c081488u: goto P_0c081488;
case 0x0c08148au: goto P_0c08148a;
case 0x0c08148cu: goto P_0c08148c;
case 0x0c08148eu: goto P_0c08148e;
case 0x0c081490u: goto P_0c081490;
case 0x0c081492u: goto P_0c081492;
case 0x0c081494u: goto P_0c081494;
case 0x0c081496u: goto P_0c081496;
case 0x0c081498u: goto P_0c081498;
case 0x0c08149au: goto P_0c08149a;
case 0x0c08149cu: goto P_0c08149c;
case 0x0c08149eu: goto P_0c08149e;
case 0x0c0814a0u: goto P_0c0814a0;
case 0x0c0814a2u: goto P_0c0814a2;
case 0x0c0814a4u: goto P_0c0814a4;
case 0x0c0814a6u: goto P_0c0814a6;
case 0x0c0814a8u: goto P_0c0814a8;
case 0x0c0814aau: goto P_0c0814aa;
case 0x0c0814acu: goto P_0c0814ac;
case 0x0c0814aeu: goto P_0c0814ae;
case 0x0c0814b0u: goto P_0c0814b0;
case 0x0c0814b2u: goto P_0c0814b2;
case 0x0c0814b4u: goto P_0c0814b4;
case 0x0c0814b6u: goto P_0c0814b6;
case 0x0c0814f4u: goto P_0c0814f4;
case 0x0c0814f6u: goto P_0c0814f6;
case 0x0c0814f8u: goto P_0c0814f8;
case 0x0c0814fau: goto P_0c0814fa;
case 0x0c0814fcu: goto P_0c0814fc;
case 0x0c0814feu: goto P_0c0814fe;
case 0x0c081500u: goto P_0c081500;
case 0x0c081502u: goto P_0c081502;
case 0x0c081504u: goto P_0c081504;
case 0x0c081506u: goto P_0c081506;
case 0x0c081508u: goto P_0c081508;
case 0x0c08150au: goto P_0c08150a;
case 0x0c08150cu: goto P_0c08150c;
case 0x0c08150eu: goto P_0c08150e;
case 0x0c081510u: goto P_0c081510;
case 0x0c081512u: goto P_0c081512;
case 0x0c081514u: goto P_0c081514;
case 0x0c081516u: goto P_0c081516;
case 0x0c081518u: goto P_0c081518;
case 0x0c08151au: goto P_0c08151a;
case 0x0c08151cu: goto P_0c08151c;
case 0x0c08151eu: goto P_0c08151e;
case 0x0c081520u: goto P_0c081520;
case 0x0c081522u: goto P_0c081522;
case 0x0c081524u: goto P_0c081524;
case 0x0c081526u: goto P_0c081526;
case 0x0c081528u: goto P_0c081528;
case 0x0c08152au: goto P_0c08152a;
case 0x0c08152cu: goto P_0c08152c;
case 0x0c08152eu: goto P_0c08152e;
case 0x0c081530u: goto P_0c081530;
case 0x0c081532u: goto P_0c081532;
case 0x0c081534u: goto P_0c081534;
case 0x0c081536u: goto P_0c081536;
case 0x0c081538u: goto P_0c081538;
case 0x0c08153au: goto P_0c08153a;
case 0x0c08153cu: goto P_0c08153c;
case 0x0c08153eu: goto P_0c08153e;
case 0x0c081540u: goto P_0c081540;
case 0x0c081542u: goto P_0c081542;
case 0x0c081544u: goto P_0c081544;
case 0x0c081546u: goto P_0c081546;
case 0x0c081548u: goto P_0c081548;
case 0x0c08154au: goto P_0c08154a;
case 0x0c08154cu: goto P_0c08154c;
case 0x0c08154eu: goto P_0c08154e;
case 0x0c081550u: goto P_0c081550;
case 0x0c081552u: goto P_0c081552;
case 0x0c081554u: goto P_0c081554;
case 0x0c081556u: goto P_0c081556;
case 0x0c081558u: goto P_0c081558;
case 0x0c08155au: goto P_0c08155a;
case 0x0c08155cu: goto P_0c08155c;
case 0x0c08155eu: goto P_0c08155e;
case 0x0c081560u: goto P_0c081560;
case 0x0c081562u: goto P_0c081562;
case 0x0c081564u: goto P_0c081564;
case 0x0c081566u: goto P_0c081566;
case 0x0c081568u: goto P_0c081568;
case 0x0c08156au: goto P_0c08156a;
case 0x0c08156cu: goto P_0c08156c;
case 0x0c08156eu: goto P_0c08156e;
case 0x0c081570u: goto P_0c081570;
case 0x0c081572u: goto P_0c081572;
case 0x0c081574u: goto P_0c081574;
case 0x0c081576u: goto P_0c081576;
case 0x0c081578u: goto P_0c081578;
case 0x0c08157au: goto P_0c08157a;
case 0x0c08157cu: goto P_0c08157c;
case 0x0c08157eu: goto P_0c08157e;
case 0x0c081580u: goto P_0c081580;
case 0x0c081582u: goto P_0c081582;
case 0x0c081584u: goto P_0c081584;
case 0x0c081586u: goto P_0c081586;
case 0x0c081588u: goto P_0c081588;
case 0x0c08158au: goto P_0c08158a;
case 0x0c08158cu: goto P_0c08158c;
case 0x0c08158eu: goto P_0c08158e;
case 0x0c081590u: goto P_0c081590;
case 0x0c081592u: goto P_0c081592;
case 0x0c081594u: goto P_0c081594;
case 0x0c081596u: goto P_0c081596;
case 0x0c081598u: goto P_0c081598;
case 0x0c08159au: goto P_0c08159a;
case 0x0c08159cu: goto P_0c08159c;
case 0x0c08159eu: goto P_0c08159e;
case 0x0c0815a0u: goto P_0c0815a0;
case 0x0c0815a2u: goto P_0c0815a2;
case 0x0c0815a4u: goto P_0c0815a4;
case 0x0c0815a6u: goto P_0c0815a6;
case 0x0c0815a8u: goto P_0c0815a8;
case 0x0c0815aau: goto P_0c0815aa;
case 0x0c0815acu: goto P_0c0815ac;
case 0x0c0815aeu: goto P_0c0815ae;
case 0x0c0815b0u: goto P_0c0815b0;
case 0x0c0815b2u: goto P_0c0815b2;
case 0x0c0815b4u: goto P_0c0815b4;
case 0x0c0815b6u: goto P_0c0815b6;
case 0x0c0815b8u: goto P_0c0815b8;
case 0x0c0815bau: goto P_0c0815ba;
case 0x0c0815bcu: goto P_0c0815bc;
case 0x0c0815beu: goto P_0c0815be;
case 0x0c0815c0u: goto P_0c0815c0;
case 0x0c0815c2u: goto P_0c0815c2;
case 0x0c0815c4u: goto P_0c0815c4;
case 0x0c0815c6u: goto P_0c0815c6;
case 0x0c0815c8u: goto P_0c0815c8;
case 0x0c0815cau: goto P_0c0815ca;
case 0x0c0815ccu: goto P_0c0815cc;
case 0x0c0815ceu: goto P_0c0815ce;
case 0x0c0815d0u: goto P_0c0815d0;
case 0x0c0815d2u: goto P_0c0815d2;
case 0x0c0815d4u: goto P_0c0815d4;
case 0x0c0815d6u: goto P_0c0815d6;
case 0x0c0815d8u: goto P_0c0815d8;
case 0x0c0815dau: goto P_0c0815da;
case 0x0c0815dcu: goto P_0c0815dc;
case 0x0c0815deu: goto P_0c0815de;
case 0x0c0815e0u: goto P_0c0815e0;
case 0x0c0815e2u: goto P_0c0815e2;
case 0x0c0815e4u: goto P_0c0815e4;
case 0x0c0815e6u: goto P_0c0815e6;
case 0x0c0815e8u: goto P_0c0815e8;
case 0x0c0815eau: goto P_0c0815ea;
case 0x0c0815ecu: goto P_0c0815ec;
case 0x0c0815eeu: goto P_0c0815ee;
case 0x0c0815f0u: goto P_0c0815f0;
case 0x0c0815f2u: goto P_0c0815f2;
case 0x0c0815f4u: goto P_0c0815f4;
case 0x0c0815f6u: goto P_0c0815f6;
case 0x0c0815f8u: goto P_0c0815f8;
case 0x0c0815fau: goto P_0c0815fa;
case 0x0c0815fcu: goto P_0c0815fc;
case 0x0c0815feu: goto P_0c0815fe;
case 0x0c081600u: goto P_0c081600;
case 0x0c081602u: goto P_0c081602;
case 0x0c081620u: goto P_0c081620;
case 0x0c081622u: goto P_0c081622;
case 0x0c081624u: goto P_0c081624;
case 0x0c081626u: goto P_0c081626;
case 0x0c081628u: goto P_0c081628;
case 0x0c08162au: goto P_0c08162a;
case 0x0c08162cu: goto P_0c08162c;
case 0x0c08162eu: goto P_0c08162e;
case 0x0c081630u: goto P_0c081630;
case 0x0c081632u: goto P_0c081632;
case 0x0c081634u: goto P_0c081634;
case 0x0c081636u: goto P_0c081636;
case 0x0c081638u: goto P_0c081638;
case 0x0c08163au: goto P_0c08163a;
case 0x0c08163cu: goto P_0c08163c;
case 0x0c08163eu: goto P_0c08163e;
case 0x0c081640u: goto P_0c081640;
case 0x0c081642u: goto P_0c081642;
case 0x0c081644u: goto P_0c081644;
case 0x0c081646u: goto P_0c081646;
case 0x0c081648u: goto P_0c081648;
case 0x0c08164au: goto P_0c08164a;
case 0x0c08164cu: goto P_0c08164c;
case 0x0c08164eu: goto P_0c08164e;
case 0x0c081650u: goto P_0c081650;
case 0x0c081652u: goto P_0c081652;
case 0x0c081654u: goto P_0c081654;
case 0x0c081656u: goto P_0c081656;
case 0x0c081658u: goto P_0c081658;
case 0x0c08165au: goto P_0c08165a;
case 0x0c08165cu: goto P_0c08165c;
case 0x0c08165eu: goto P_0c08165e;
case 0x0c081660u: goto P_0c081660;
case 0x0c081662u: goto P_0c081662;
case 0x0c081664u: goto P_0c081664;
case 0x0c081666u: goto P_0c081666;
case 0x0c081668u: goto P_0c081668;
case 0x0c08166au: goto P_0c08166a;
case 0x0c08166cu: goto P_0c08166c;
case 0x0c08166eu: goto P_0c08166e;
case 0x0c081670u: goto P_0c081670;
case 0x0c081672u: goto P_0c081672;
case 0x0c081674u: goto P_0c081674;
case 0x0c081676u: goto P_0c081676;
case 0x0c081678u: goto P_0c081678;
case 0x0c08167au: goto P_0c08167a;
case 0x0c08167cu: goto P_0c08167c;
case 0x0c08167eu: goto P_0c08167e;
case 0x0c081680u: goto P_0c081680;
case 0x0c081682u: goto P_0c081682;
case 0x0c081684u: goto P_0c081684;
case 0x0c081686u: goto P_0c081686;
case 0x0c081688u: goto P_0c081688;
case 0x0c08168au: goto P_0c08168a;
case 0x0c08168cu: goto P_0c08168c;
case 0x0c08168eu: goto P_0c08168e;
case 0x0c081690u: goto P_0c081690;
case 0x0c081692u: goto P_0c081692;
case 0x0c081694u: goto P_0c081694;
case 0x0c081696u: goto P_0c081696;
case 0x0c081698u: goto P_0c081698;
case 0x0c08169au: goto P_0c08169a;
case 0x0c08169cu: goto P_0c08169c;
case 0x0c08169eu: goto P_0c08169e;
case 0x0c0816a0u: goto P_0c0816a0;
case 0x0c0816a2u: goto P_0c0816a2;
case 0x0c0816a4u: goto P_0c0816a4;
case 0x0c0816a6u: goto P_0c0816a6;
case 0x0c0816a8u: goto P_0c0816a8;
case 0x0c0816aau: goto P_0c0816aa;
case 0x0c0816acu: goto P_0c0816ac;
case 0x0c0816aeu: goto P_0c0816ae;
case 0x0c0816b0u: goto P_0c0816b0;
case 0x0c0816b2u: goto P_0c0816b2;
case 0x0c0816b4u: goto P_0c0816b4;
case 0x0c0816b6u: goto P_0c0816b6;
case 0x0c0816b8u: goto P_0c0816b8;
case 0x0c0816bau: goto P_0c0816ba;
case 0x0c0816bcu: goto P_0c0816bc;
case 0x0c0816beu: goto P_0c0816be;
case 0x0c0816c0u: goto P_0c0816c0;
case 0x0c0816c2u: goto P_0c0816c2;
case 0x0c0816c4u: goto P_0c0816c4;
case 0x0c0816c6u: goto P_0c0816c6;
case 0x0c0816c8u: goto P_0c0816c8;
case 0x0c0816cau: goto P_0c0816ca;
case 0x0c0816ccu: goto P_0c0816cc;
case 0x0c0816ceu: goto P_0c0816ce;
case 0x0c0816d0u: goto P_0c0816d0;
case 0x0c0816d2u: goto P_0c0816d2;
case 0x0c0816d4u: goto P_0c0816d4;
case 0x0c0816d6u: goto P_0c0816d6;
case 0x0c0816d8u: goto P_0c0816d8;
case 0x0c0816dau: goto P_0c0816da;
case 0x0c0816dcu: goto P_0c0816dc;
case 0x0c0816deu: goto P_0c0816de;
case 0x0c0816e0u: goto P_0c0816e0;
case 0x0c0816e2u: goto P_0c0816e2;
case 0x0c0816e4u: goto P_0c0816e4;
case 0x0c0816e6u: goto P_0c0816e6;
case 0x0c0816e8u: goto P_0c0816e8;
case 0x0c0816eau: goto P_0c0816ea;
case 0x0c0816ecu: goto P_0c0816ec;
case 0x0c0816eeu: goto P_0c0816ee;
case 0x0c0816f0u: goto P_0c0816f0;
case 0x0c0816f2u: goto P_0c0816f2;
case 0x0c0816f4u: goto P_0c0816f4;
case 0x0c0816f6u: goto P_0c0816f6;
case 0x0c0816f8u: goto P_0c0816f8;
case 0x0c0816fau: goto P_0c0816fa;
case 0x0c0816fcu: goto P_0c0816fc;
case 0x0c0816feu: goto P_0c0816fe;
case 0x0c081700u: goto P_0c081700;
case 0x0c081702u: goto P_0c081702;
case 0x0c081704u: goto P_0c081704;
case 0x0c081706u: goto P_0c081706;
case 0x0c081708u: goto P_0c081708;
case 0x0c08170au: goto P_0c08170a;
case 0x0c08170cu: goto P_0c08170c;
case 0x0c08170eu: goto P_0c08170e;
case 0x0c081710u: goto P_0c081710;
case 0x0c081712u: goto P_0c081712;
case 0x0c081714u: goto P_0c081714;
case 0x0c081716u: goto P_0c081716;
case 0x0c081718u: goto P_0c081718;
case 0x0c08171au: goto P_0c08171a;
case 0x0c08171cu: goto P_0c08171c;
case 0x0c08171eu: goto P_0c08171e;
case 0x0c081720u: goto P_0c081720;
case 0x0c081722u: goto P_0c081722;
case 0x0c081724u: goto P_0c081724;
case 0x0c081726u: goto P_0c081726;
case 0x0c081728u: goto P_0c081728;
case 0x0c08172au: goto P_0c08172a;
case 0x0c08172cu: goto P_0c08172c;
case 0x0c08172eu: goto P_0c08172e;
case 0x0c081730u: goto P_0c081730;
case 0x0c081732u: goto P_0c081732;
case 0x0c081734u: goto P_0c081734;
case 0x0c081736u: goto P_0c081736;
case 0x0c081738u: goto P_0c081738;
case 0x0c08173au: goto P_0c08173a;
case 0x0c08173cu: goto P_0c08173c;
case 0x0c08173eu: goto P_0c08173e;
case 0x0c081740u: goto P_0c081740;
case 0x0c081742u: goto P_0c081742;
case 0x0c081770u: goto P_0c081770;
case 0x0c081772u: goto P_0c081772;
case 0x0c081774u: goto P_0c081774;
case 0x0c081776u: goto P_0c081776;
case 0x0c081778u: goto P_0c081778;
case 0x0c08177au: goto P_0c08177a;
case 0x0c08177cu: goto P_0c08177c;
case 0x0c08177eu: goto P_0c08177e;
case 0x0c081780u: goto P_0c081780;
case 0x0c081782u: goto P_0c081782;
case 0x0c081784u: goto P_0c081784;
case 0x0c081786u: goto P_0c081786;
case 0x0c081788u: goto P_0c081788;
case 0x0c08178au: goto P_0c08178a;
case 0x0c08178cu: goto P_0c08178c;
case 0x0c08178eu: goto P_0c08178e;
case 0x0c081790u: goto P_0c081790;
case 0x0c081792u: goto P_0c081792;
case 0x0c081794u: goto P_0c081794;
case 0x0c081796u: goto P_0c081796;
case 0x0c081798u: goto P_0c081798;
case 0x0c08179au: goto P_0c08179a;
case 0x0c08179cu: goto P_0c08179c;
case 0x0c08179eu: goto P_0c08179e;
case 0x0c0817a0u: goto P_0c0817a0;
case 0x0c0817a2u: goto P_0c0817a2;
case 0x0c0817a4u: goto P_0c0817a4;
case 0x0c0817a6u: goto P_0c0817a6;
case 0x0c0817a8u: goto P_0c0817a8;
case 0x0c0817aau: goto P_0c0817aa;
case 0x0c0817acu: goto P_0c0817ac;
case 0x0c0817aeu: goto P_0c0817ae;
case 0x0c0817b0u: goto P_0c0817b0;
case 0x0c0817b2u: goto P_0c0817b2;
case 0x0c0817b4u: goto P_0c0817b4;
case 0x0c0817b6u: goto P_0c0817b6;
case 0x0c0817b8u: goto P_0c0817b8;
case 0x0c0817bau: goto P_0c0817ba;
case 0x0c0817bcu: goto P_0c0817bc;
case 0x0c0817beu: goto P_0c0817be;
case 0x0c0817c0u: goto P_0c0817c0;
case 0x0c0817c2u: goto P_0c0817c2;
case 0x0c0817c4u: goto P_0c0817c4;
case 0x0c0817c6u: goto P_0c0817c6;
case 0x0c0817c8u: goto P_0c0817c8;
case 0x0c0817cau: goto P_0c0817ca;
case 0x0c0817ccu: goto P_0c0817cc;
case 0x0c0817ceu: goto P_0c0817ce;
case 0x0c0817d0u: goto P_0c0817d0;
case 0x0c0817d2u: goto P_0c0817d2;
case 0x0c0817d4u: goto P_0c0817d4;
case 0x0c0817d6u: goto P_0c0817d6;
case 0x0c0817d8u: goto P_0c0817d8;
case 0x0c0817dau: goto P_0c0817da;
case 0x0c0817dcu: goto P_0c0817dc;
case 0x0c0817deu: goto P_0c0817de;
case 0x0c0817e0u: goto P_0c0817e0;
case 0x0c0817e2u: goto P_0c0817e2;
case 0x0c0817e4u: goto P_0c0817e4;
case 0x0c0817e6u: goto P_0c0817e6;
case 0x0c0817e8u: goto P_0c0817e8;
case 0x0c0817eau: goto P_0c0817ea;
case 0x0c0817ecu: goto P_0c0817ec;
case 0x0c0817eeu: goto P_0c0817ee;
case 0x0c0817f0u: goto P_0c0817f0;
case 0x0c0817f2u: goto P_0c0817f2;
case 0x0c0817f4u: goto P_0c0817f4;
case 0x0c0817f6u: goto P_0c0817f6;
case 0x0c0817f8u: goto P_0c0817f8;
case 0x0c0817fau: goto P_0c0817fa;
case 0x0c0817fcu: goto P_0c0817fc;
case 0x0c0817feu: goto P_0c0817fe;
case 0x0c081800u: goto P_0c081800;
case 0x0c081802u: goto P_0c081802;
case 0x0c081804u: goto P_0c081804;
case 0x0c081806u: goto P_0c081806;
case 0x0c081808u: goto P_0c081808;
case 0x0c08180au: goto P_0c08180a;
case 0x0c08180cu: goto P_0c08180c;
case 0x0c08180eu: goto P_0c08180e;
case 0x0c081810u: goto P_0c081810;
case 0x0c081812u: goto P_0c081812;
case 0x0c081814u: goto P_0c081814;
case 0x0c081816u: goto P_0c081816;
case 0x0c081818u: goto P_0c081818;
case 0x0c08181au: goto P_0c08181a;
case 0x0c08181cu: goto P_0c08181c;
case 0x0c08181eu: goto P_0c08181e;
case 0x0c081820u: goto P_0c081820;
case 0x0c081822u: goto P_0c081822;
case 0x0c081824u: goto P_0c081824;
case 0x0c081826u: goto P_0c081826;
case 0x0c081828u: goto P_0c081828;
case 0x0c08182au: goto P_0c08182a;
case 0x0c08182cu: goto P_0c08182c;
case 0x0c08182eu: goto P_0c08182e;
case 0x0c081830u: goto P_0c081830;
case 0x0c081832u: goto P_0c081832;
case 0x0c081834u: goto P_0c081834;
case 0x0c081836u: goto P_0c081836;
case 0x0c081838u: goto P_0c081838;
case 0x0c08183au: goto P_0c08183a;
case 0x0c08183cu: goto P_0c08183c;
case 0x0c08183eu: goto P_0c08183e;
case 0x0c081840u: goto P_0c081840;
case 0x0c081842u: goto P_0c081842;
case 0x0c081844u: goto P_0c081844;
case 0x0c081846u: goto P_0c081846;
case 0x0c081848u: goto P_0c081848;
case 0x0c08184au: goto P_0c08184a;
case 0x0c08184cu: goto P_0c08184c;
case 0x0c08184eu: goto P_0c08184e;
case 0x0c081850u: goto P_0c081850;
case 0x0c081852u: goto P_0c081852;
case 0x0c081854u: goto P_0c081854;
case 0x0c081856u: goto P_0c081856;
case 0x0c081858u: goto P_0c081858;
case 0x0c08185au: goto P_0c08185a;
case 0x0c08185cu: goto P_0c08185c;
case 0x0c08185eu: goto P_0c08185e;
case 0x0c081860u: goto P_0c081860;
case 0x0c081862u: goto P_0c081862;
case 0x0c081864u: goto P_0c081864;
case 0x0c081866u: goto P_0c081866;
case 0x0c081868u: goto P_0c081868;
case 0x0c08186au: goto P_0c08186a;
case 0x0c08186cu: goto P_0c08186c;
case 0x0c08186eu: goto P_0c08186e;
case 0x0c081870u: goto P_0c081870;
case 0x0c081872u: goto P_0c081872;
case 0x0c081874u: goto P_0c081874;
case 0x0c081876u: goto P_0c081876;
case 0x0c081878u: goto P_0c081878;
case 0x0c08187au: goto P_0c08187a;
case 0x0c08187cu: goto P_0c08187c;
case 0x0c08187eu: goto P_0c08187e;
case 0x0c081880u: goto P_0c081880;
case 0x0c081882u: goto P_0c081882;
case 0x0c081884u: goto P_0c081884;
case 0x0c081886u: goto P_0c081886;
case 0x0c081888u: goto P_0c081888;
case 0x0c08188au: goto P_0c08188a;
case 0x0c0818b0u: goto P_0c0818b0;
case 0x0c0818b2u: goto P_0c0818b2;
case 0x0c0818b4u: goto P_0c0818b4;
case 0x0c0818b6u: goto P_0c0818b6;
case 0x0c0818b8u: goto P_0c0818b8;
case 0x0c0818bau: goto P_0c0818ba;
case 0x0c0818bcu: goto P_0c0818bc;
case 0x0c0818beu: goto P_0c0818be;
case 0x0c0818c0u: goto P_0c0818c0;
case 0x0c0818c2u: goto P_0c0818c2;
case 0x0c0818c4u: goto P_0c0818c4;
case 0x0c0818c6u: goto P_0c0818c6;
case 0x0c0818c8u: goto P_0c0818c8;
case 0x0c0818cau: goto P_0c0818ca;
case 0x0c0818ccu: goto P_0c0818cc;
case 0x0c0818ceu: goto P_0c0818ce;
case 0x0c0818d0u: goto P_0c0818d0;
case 0x0c0818d2u: goto P_0c0818d2;
case 0x0c0818d4u: goto P_0c0818d4;
case 0x0c0818d6u: goto P_0c0818d6;
case 0x0c0818d8u: goto P_0c0818d8;
case 0x0c0818dau: goto P_0c0818da;
case 0x0c0818dcu: goto P_0c0818dc;
case 0x0c0818deu: goto P_0c0818de;
case 0x0c0818e0u: goto P_0c0818e0;
case 0x0c0818e2u: goto P_0c0818e2;
case 0x0c0818e4u: goto P_0c0818e4;
case 0x0c0818e6u: goto P_0c0818e6;
case 0x0c0818e8u: goto P_0c0818e8;
case 0x0c0818eau: goto P_0c0818ea;
case 0x0c0818ecu: goto P_0c0818ec;
case 0x0c0818eeu: goto P_0c0818ee;
case 0x0c0818f0u: goto P_0c0818f0;
case 0x0c0818f2u: goto P_0c0818f2;
case 0x0c0818f4u: goto P_0c0818f4;
case 0x0c0818f6u: goto P_0c0818f6;
case 0x0c0818f8u: goto P_0c0818f8;
case 0x0c0818fau: goto P_0c0818fa;
case 0x0c0818fcu: goto P_0c0818fc;
case 0x0c0818feu: goto P_0c0818fe;
case 0x0c081900u: goto P_0c081900;
case 0x0c081902u: goto P_0c081902;
case 0x0c081904u: goto P_0c081904;
case 0x0c081906u: goto P_0c081906;
case 0x0c081908u: goto P_0c081908;
case 0x0c08190au: goto P_0c08190a;
case 0x0c08190cu: goto P_0c08190c;
case 0x0c08190eu: goto P_0c08190e;
case 0x0c081910u: goto P_0c081910;
case 0x0c081912u: goto P_0c081912;
case 0x0c081914u: goto P_0c081914;
case 0x0c081916u: goto P_0c081916;
case 0x0c081918u: goto P_0c081918;
case 0x0c08191au: goto P_0c08191a;
case 0x0c08191cu: goto P_0c08191c;
case 0x0c08191eu: goto P_0c08191e;
case 0x0c081920u: goto P_0c081920;
case 0x0c081922u: goto P_0c081922;
case 0x0c081924u: goto P_0c081924;
case 0x0c081926u: goto P_0c081926;
case 0x0c081928u: goto P_0c081928;
case 0x0c08192au: goto P_0c08192a;
case 0x0c08192cu: goto P_0c08192c;
case 0x0c08192eu: goto P_0c08192e;
case 0x0c081930u: goto P_0c081930;
case 0x0c081932u: goto P_0c081932;
case 0x0c081934u: goto P_0c081934;
case 0x0c081936u: goto P_0c081936;
case 0x0c081938u: goto P_0c081938;
case 0x0c08193au: goto P_0c08193a;
case 0x0c08193cu: goto P_0c08193c;
case 0x0c08193eu: goto P_0c08193e;
case 0x0c081940u: goto P_0c081940;
case 0x0c081942u: goto P_0c081942;
case 0x0c081944u: goto P_0c081944;
case 0x0c081946u: goto P_0c081946;
case 0x0c081948u: goto P_0c081948;
case 0x0c08194au: goto P_0c08194a;
case 0x0c08194cu: goto P_0c08194c;
case 0x0c08194eu: goto P_0c08194e;
case 0x0c081950u: goto P_0c081950;
case 0x0c081952u: goto P_0c081952;
case 0x0c081954u: goto P_0c081954;
case 0x0c081956u: goto P_0c081956;
case 0x0c081958u: goto P_0c081958;
case 0x0c08195au: goto P_0c08195a;
case 0x0c08195cu: goto P_0c08195c;
case 0x0c08195eu: goto P_0c08195e;
case 0x0c081960u: goto P_0c081960;
case 0x0c081962u: goto P_0c081962;
case 0x0c081964u: goto P_0c081964;
case 0x0c081966u: goto P_0c081966;
case 0x0c081968u: goto P_0c081968;
case 0x0c08196au: goto P_0c08196a;
case 0x0c08196cu: goto P_0c08196c;
case 0x0c08196eu: goto P_0c08196e;
case 0x0c081970u: goto P_0c081970;
case 0x0c081972u: goto P_0c081972;
case 0x0c081974u: goto P_0c081974;
case 0x0c081976u: goto P_0c081976;
default: return vf3_matrix_family(target,s,ram);
}
P_0c081098: /* original 4f22, guest PC 0x0c081098 */
if(!s->budget--) { s->failed_pc=0x0c081098u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08109a;
P_0c08109a: /* original 6742, guest PC 0x0c08109a */
if(!s->budget--) { s->failed_pc=0x0c08109au; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c08109c;
P_0c08109c: /* original d330, guest PC 0x0c08109c */
if(!s->budget--) { s->failed_pc=0x0c08109cu; return 0; }
r[3]=read(ram,0x0c081160u,4);
goto P_0c08109e;
P_0c08109e: /* original 4f12, guest PC 0x0c08109e */
if(!s->budget--) { s->failed_pc=0x0c08109eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0810a0;
P_0c0810a0: /* original 6173, guest PC 0x0c0810a0 */
if(!s->budget--) { s->failed_pc=0x0c0810a0u; return 0; }
r[1]=r[7];
goto P_0c0810a2;
P_0c0810a2: /* original 430b, guest PC 0x0c0810a2 */
if(!s->budget--) { s->failed_pc=0x0c0810a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0810a6u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0810a6u) { target=s->pc; goto dispatch; }
goto P_0c0810a6;
P_0c0810a4: /* original 6053, guest PC 0x0c0810a4 */
if(!s->budget--) { s->failed_pc=0x0c0810a4u; return 0; }
r[0]=r[5];
goto P_0c0810a6;
P_0c0810a6: /* original 6603, guest PC 0x0c0810a6 */
if(!s->budget--) { s->failed_pc=0x0c0810a6u; return 0; }
r[6]=r[0];
goto P_0c0810a8;
P_0c0810a8: /* original 6273, guest PC 0x0c0810a8 */
if(!s->budget--) { s->failed_pc=0x0c0810a8u; return 0; }
r[2]=r[7];
goto P_0c0810aa;
P_0c0810aa: /* original 0567, guest PC 0x0c0810aa */
if(!s->budget--) { s->failed_pc=0x0c0810aau; return 0; }
r[19]=r[5]*r[6];
goto P_0c0810ac;
P_0c0810ac: /* original 2462, guest PC 0x0c0810ac */
if(!s->budget--) { s->failed_pc=0x0c0810acu; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0810ae;
P_0c0810ae: /* original 051a, guest PC 0x0c0810ae */
if(!s->budget--) { s->failed_pc=0x0c0810aeu; return 0; }
r[5]=r[19];
goto P_0c0810b0;
P_0c0810b0: /* original 4f16, guest PC 0x0c0810b0 */
if(!s->budget--) { s->failed_pc=0x0c0810b0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810b2;
P_0c0810b2: /* original 3258, guest PC 0x0c0810b2 */
if(!s->budget--) { s->failed_pc=0x0c0810b2u; return 0; }
r[2]-=r[5];
goto P_0c0810b4;
P_0c0810b4: /* original 4f26, guest PC 0x0c0810b4 */
if(!s->budget--) { s->failed_pc=0x0c0810b4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810b6;
P_0c0810b6: /* original 6023, guest PC 0x0c0810b6 */
if(!s->budget--) { s->failed_pc=0x0c0810b6u; return 0; }
r[0]=r[2];
goto P_0c0810b8;
P_0c0810b8: /* original 000b, guest PC 0x0c0810b8 */
if(!s->budget--) { s->failed_pc=0x0c0810b8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0810ba: /* original 0009, guest PC 0x0c0810ba */
if(!s->budget--) { s->failed_pc=0x0c0810bau; return 0; }
goto P_0c0810bc;
P_0c0810bc: /* original 2fe6, guest PC 0x0c0810bc */
if(!s->budget--) { s->failed_pc=0x0c0810bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0810be;
P_0c0810be: /* original d329, guest PC 0x0c0810be */
if(!s->budget--) { s->failed_pc=0x0c0810beu; return 0; }
r[3]=read(ram,0x0c081164u,4);
goto P_0c0810c0;
P_0c0810c0: /* original 4f22, guest PC 0x0c0810c0 */
if(!s->budget--) { s->failed_pc=0x0c0810c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0810c2;
P_0c0810c2: /* original 6030, guest PC 0x0c0810c2 */
if(!s->budget--) { s->failed_pc=0x0c0810c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0810c4;
P_0c0810c4: /* original 600c, guest PC 0x0c0810c4 */
if(!s->budget--) { s->failed_pc=0x0c0810c4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0810c6;
P_0c0810c6: /* original 8803, guest PC 0x0c0810c6 */
if(!s->budget--) { s->failed_pc=0x0c0810c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0810c8;
P_0c0810c8: /* original 8b10, guest PC 0x0c0810c8 */
if(!s->budget--) { s->failed_pc=0x0c0810c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0810ec; }
goto P_0c0810ca;
P_0c0810ca: /* original d128, guest PC 0x0c0810ca */
if(!s->budget--) { s->failed_pc=0x0c0810cau; return 0; }
r[1]=read(ram,0x0c08116cu,4);
goto P_0c0810cc;
P_0c0810cc: /* original d326, guest PC 0x0c0810cc */
if(!s->budget--) { s->failed_pc=0x0c0810ccu; return 0; }
r[3]=read(ram,0x0c081168u,4);
goto P_0c0810ce;
P_0c0810ce: /* original 6212, guest PC 0x0c0810ce */
if(!s->budget--) { s->failed_pc=0x0c0810ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0810d0;
P_0c0810d0: /* original 2238, guest PC 0x0c0810d0 */
if(!s->budget--) { s->failed_pc=0x0c0810d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0810d2;
P_0c0810d2: /* original 8b0b, guest PC 0x0c0810d2 */
if(!s->budget--) { s->failed_pc=0x0c0810d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0810ec; }
goto P_0c0810d4;
P_0c0810d4: /* original d327, guest PC 0x0c0810d4 */
if(!s->budget--) { s->failed_pc=0x0c0810d4u; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c0810d6;
P_0c0810d6: /* original e500, guest PC 0x0c0810d6 */
if(!s->budget--) { s->failed_pc=0x0c0810d6u; return 0; }
r[5]=0x00000000u;
goto P_0c0810d8;
P_0c0810d8: /* original de25, guest PC 0x0c0810d8 */
if(!s->budget--) { s->failed_pc=0x0c0810d8u; return 0; }
r[14]=read(ram,0x0c081170u,4);
goto P_0c0810da;
P_0c0810da: /* original 430b, guest PC 0x0c0810da */
if(!s->budget--) { s->failed_pc=0x0c0810dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0810deu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0810deu) { target=s->pc; goto dispatch; }
goto P_0c0810de;
P_0c0810dc: /* original 64e3, guest PC 0x0c0810dc */
if(!s->budget--) { s->failed_pc=0x0c0810dcu; return 0; }
r[4]=r[14];
goto P_0c0810de;
P_0c0810de: /* original d226, guest PC 0x0c0810de */
if(!s->budget--) { s->failed_pc=0x0c0810deu; return 0; }
r[2]=read(ram,0x0c081178u,4);
goto P_0c0810e0;
P_0c0810e0: /* original 420b, guest PC 0x0c0810e0 */
if(!s->budget--) { s->failed_pc=0x0c0810e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0810e4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0810e4u) { target=s->pc; goto dispatch; }
goto P_0c0810e4;
P_0c0810e2: /* original 0009, guest PC 0x0c0810e2 */
if(!s->budget--) { s->failed_pc=0x0c0810e2u; return 0; }
goto P_0c0810e4;
P_0c0810e4: /* original d323, guest PC 0x0c0810e4 */
if(!s->budget--) { s->failed_pc=0x0c0810e4u; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c0810e6;
P_0c0810e6: /* original 9533, guest PC 0x0c0810e6 */
if(!s->budget--) { s->failed_pc=0x0c0810e6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081150u,2);
goto P_0c0810e8;
P_0c0810e8: /* original 430b, guest PC 0x0c0810e8 */
if(!s->budget--) { s->failed_pc=0x0c0810e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0810ecu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0810ecu) { target=s->pc; goto dispatch; }
goto P_0c0810ec;
P_0c0810ea: /* original 64e3, guest PC 0x0c0810ea */
if(!s->budget--) { s->failed_pc=0x0c0810eau; return 0; }
r[4]=r[14];
goto P_0c0810ec;
P_0c0810ec: /* original 4f26, guest PC 0x0c0810ec */
if(!s->budget--) { s->failed_pc=0x0c0810ecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810ee;
P_0c0810ee: /* original 000b, guest PC 0x0c0810ee */
if(!s->budget--) { s->failed_pc=0x0c0810eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0810f0: /* original 6ef6, guest PC 0x0c0810f0 */
if(!s->budget--) { s->failed_pc=0x0c0810f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0810f2;
P_0c0810f2: /* original 2fe6, guest PC 0x0c0810f2 */
if(!s->budget--) { s->failed_pc=0x0c0810f2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0810f4;
P_0c0810f4: /* original d31b, guest PC 0x0c0810f4 */
if(!s->budget--) { s->failed_pc=0x0c0810f4u; return 0; }
r[3]=read(ram,0x0c081164u,4);
goto P_0c0810f6;
P_0c0810f6: /* original 4f22, guest PC 0x0c0810f6 */
if(!s->budget--) { s->failed_pc=0x0c0810f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0810f8;
P_0c0810f8: /* original 6030, guest PC 0x0c0810f8 */
if(!s->budget--) { s->failed_pc=0x0c0810f8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0810fa;
P_0c0810fa: /* original 600c, guest PC 0x0c0810fa */
if(!s->budget--) { s->failed_pc=0x0c0810fau; return 0; }
r[0]=r[0]&255u;
goto P_0c0810fc;
P_0c0810fc: /* original 8803, guest PC 0x0c0810fc */
if(!s->budget--) { s->failed_pc=0x0c0810fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0810fe;
P_0c0810fe: /* original 8910, guest PC 0x0c0810fe */
if(!s->budget--) { s->failed_pc=0x0c0810feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081122; }
goto P_0c081100;
P_0c081100: /* original d11a, guest PC 0x0c081100 */
if(!s->budget--) { s->failed_pc=0x0c081100u; return 0; }
r[1]=read(ram,0x0c08116cu,4);
goto P_0c081102;
P_0c081102: /* original d319, guest PC 0x0c081102 */
if(!s->budget--) { s->failed_pc=0x0c081102u; return 0; }
r[3]=read(ram,0x0c081168u,4);
goto P_0c081104;
P_0c081104: /* original 6212, guest PC 0x0c081104 */
if(!s->budget--) { s->failed_pc=0x0c081104u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c081106;
P_0c081106: /* original 2238, guest PC 0x0c081106 */
if(!s->budget--) { s->failed_pc=0x0c081106u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c081108;
P_0c081108: /* original 8b0b, guest PC 0x0c081108 */
if(!s->budget--) { s->failed_pc=0x0c081108u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081122; }
goto P_0c08110a;
P_0c08110a: /* original d31a, guest PC 0x0c08110a */
if(!s->budget--) { s->failed_pc=0x0c08110au; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c08110c;
P_0c08110c: /* original e500, guest PC 0x0c08110c */
if(!s->budget--) { s->failed_pc=0x0c08110cu; return 0; }
r[5]=0x00000000u;
goto P_0c08110e;
P_0c08110e: /* original de18, guest PC 0x0c08110e */
if(!s->budget--) { s->failed_pc=0x0c08110eu; return 0; }
r[14]=read(ram,0x0c081170u,4);
goto P_0c081110;
P_0c081110: /* original 430b, guest PC 0x0c081110 */
if(!s->budget--) { s->failed_pc=0x0c081110u; return 0; }
target=r[3];
r[16]=code_base|0x0c081114u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081114u) { target=s->pc; goto dispatch; }
goto P_0c081114;
P_0c081112: /* original 64e3, guest PC 0x0c081112 */
if(!s->budget--) { s->failed_pc=0x0c081112u; return 0; }
r[4]=r[14];
goto P_0c081114;
P_0c081114: /* original d219, guest PC 0x0c081114 */
if(!s->budget--) { s->failed_pc=0x0c081114u; return 0; }
r[2]=read(ram,0x0c08117cu,4);
goto P_0c081116;
P_0c081116: /* original 420b, guest PC 0x0c081116 */
if(!s->budget--) { s->failed_pc=0x0c081116u; return 0; }
target=r[2];
r[16]=code_base|0x0c08111au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08111au) { target=s->pc; goto dispatch; }
goto P_0c08111a;
P_0c081118: /* original 0009, guest PC 0x0c081118 */
if(!s->budget--) { s->failed_pc=0x0c081118u; return 0; }
goto P_0c08111a;
P_0c08111a: /* original d316, guest PC 0x0c08111a */
if(!s->budget--) { s->failed_pc=0x0c08111au; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c08111c;
P_0c08111c: /* original 9518, guest PC 0x0c08111c */
if(!s->budget--) { s->failed_pc=0x0c08111cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081150u,2);
goto P_0c08111e;
P_0c08111e: /* original 430b, guest PC 0x0c08111e */
if(!s->budget--) { s->failed_pc=0x0c08111eu; return 0; }
target=r[3];
r[16]=code_base|0x0c081122u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081122u) { target=s->pc; goto dispatch; }
goto P_0c081122;
P_0c081120: /* original 64e3, guest PC 0x0c081120 */
if(!s->budget--) { s->failed_pc=0x0c081120u; return 0; }
r[4]=r[14];
goto P_0c081122;
P_0c081122: /* original 4f26, guest PC 0x0c081122 */
if(!s->budget--) { s->failed_pc=0x0c081122u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081124;
P_0c081124: /* original 000b, guest PC 0x0c081124 */
if(!s->budget--) { s->failed_pc=0x0c081124u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081126: /* original 6ef6, guest PC 0x0c081126 */
if(!s->budget--) { s->failed_pc=0x0c081126u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c081128u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081128u; return 0; } return 1;
P_0c081184: /* original 2fe6, guest PC 0x0c081184 */
if(!s->budget--) { s->failed_pc=0x0c081184u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081186;
P_0c081186: /* original 2fd6, guest PC 0x0c081186 */
if(!s->budget--) { s->failed_pc=0x0c081186u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081188;
P_0c081188: /* original 2fc6, guest PC 0x0c081188 */
if(!s->budget--) { s->failed_pc=0x0c081188u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08118a;
P_0c08118a: /* original 2fb6, guest PC 0x0c08118a */
if(!s->budget--) { s->failed_pc=0x0c08118au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08118c;
P_0c08118c: /* original 2fa6, guest PC 0x0c08118c */
if(!s->budget--) { s->failed_pc=0x0c08118cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08118e;
P_0c08118e: /* original 2f96, guest PC 0x0c08118e */
if(!s->budget--) { s->failed_pc=0x0c08118eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081190;
P_0c081190: /* original 2f86, guest PC 0x0c081190 */
if(!s->budget--) { s->failed_pc=0x0c081190u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081192;
P_0c081192: /* original d132, guest PC 0x0c081192 */
if(!s->budget--) { s->failed_pc=0x0c081192u; return 0; }
r[1]=read(ram,0x0c08125cu,4);
goto P_0c081194;
P_0c081194: /* original 4f22, guest PC 0x0c081194 */
if(!s->budget--) { s->failed_pc=0x0c081194u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081196;
P_0c081196: /* original 6212, guest PC 0x0c081196 */
if(!s->budget--) { s->failed_pc=0x0c081196u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c081198;
P_0c081198: /* original d32f, guest PC 0x0c081198 */
if(!s->budget--) { s->failed_pc=0x0c081198u; return 0; }
r[3]=read(ram,0x0c081258u,4);
goto P_0c08119a;
P_0c08119a: /* original 7fdc, guest PC 0x0c08119a */
if(!s->budget--) { s->failed_pc=0x0c08119au; return 0; }
r[15]+=0xffffffdcu;
goto P_0c08119c;
P_0c08119c: /* original 2238, guest PC 0x0c08119c */
if(!s->budget--) { s->failed_pc=0x0c08119cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08119e;
P_0c08119e: /* original 8d02, guest PC 0x0c08119e */
if(!s->budget--) { s->failed_pc=0x0c08119eu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c0811a6; }
goto P_0c0811a2;
P_0c0811a0: /* original 6e43, guest PC 0x0c0811a0 */
if(!s->budget--) { s->failed_pc=0x0c0811a0u; return 0; }
r[14]=r[4];
goto P_0c0811a2;
P_0c0811a2: /* original a3df, guest PC 0x0c0811a2 */
if(!s->budget--) { s->failed_pc=0x0c0811a2u; return 0; }
goto P_0c081964;
P_0c0811a4: /* original 0009, guest PC 0x0c0811a4 */
if(!s->budget--) { s->failed_pc=0x0c0811a4u; return 0; }
goto P_0c0811a6;
P_0c0811a6: /* original d22e, guest PC 0x0c0811a6 */
if(!s->budget--) { s->failed_pc=0x0c0811a6u; return 0; }
r[2]=read(ram,0x0c081260u,4);
goto P_0c0811a8;
P_0c0811a8: /* original 6be3, guest PC 0x0c0811a8 */
if(!s->budget--) { s->failed_pc=0x0c0811a8u; return 0; }
r[11]=r[14];
goto P_0c0811aa;
P_0c0811aa: /* original 6322, guest PC 0x0c0811aa */
if(!s->budget--) { s->failed_pc=0x0c0811aau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0811ac;
P_0c0811ac: /* original 1f33, guest PC 0x0c0811ac */
if(!s->budget--) { s->failed_pc=0x0c0811acu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0811ae;
P_0c0811ae: /* original d32d, guest PC 0x0c0811ae */
if(!s->budget--) { s->failed_pc=0x0c0811aeu; return 0; }
r[3]=read(ram,0x0c081264u,4);
goto P_0c0811b0;
P_0c0811b0: /* original 6132, guest PC 0x0c0811b0 */
if(!s->budget--) { s->failed_pc=0x0c0811b0u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0811b2;
P_0c0811b2: /* original 1f14, guest PC 0x0c0811b2 */
if(!s->budget--) { s->failed_pc=0x0c0811b2u; return 0; }
write(ram,r[15]+16,r[1],4);
goto P_0c0811b4;
P_0c0811b4: /* original 904a, guest PC 0x0c0811b4 */
if(!s->budget--) { s->failed_pc=0x0c0811b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08124cu,2);
goto P_0c0811b6;
P_0c0811b6: /* original 01bc, guest PC 0x0c0811b6 */
if(!s->budget--) { s->failed_pc=0x0c0811b6u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0811b8;
P_0c0811b8: /* original 2f10, guest PC 0x0c0811b8 */
if(!s->budget--) { s->failed_pc=0x0c0811b8u; return 0; }
write(ram,r[15],r[1],1);
goto P_0c0811ba;
P_0c0811ba: /* original 9048, guest PC 0x0c0811ba */
if(!s->budget--) { s->failed_pc=0x0c0811bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08124eu,2);
goto P_0c0811bc;
P_0c0811bc: /* original 02bc, guest PC 0x0c0811bc */
if(!s->budget--) { s->failed_pc=0x0c0811bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0811be;
P_0c0811be: /* original e01c, guest PC 0x0c0811be */
if(!s->budget--) { s->failed_pc=0x0c0811beu; return 0; }
r[0]=0x0000001cu;
goto P_0c0811c0;
P_0c0811c0: /* original 0f24, guest PC 0x0c0811c0 */
if(!s->budget--) { s->failed_pc=0x0c0811c0u; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c0811c2;
P_0c0811c2: /* original 9045, guest PC 0x0c0811c2 */
if(!s->budget--) { s->failed_pc=0x0c0811c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081250u,2);
goto P_0c0811c4;
P_0c0811c4: /* original 0dbe, guest PC 0x0c0811c4 */
if(!s->budget--) { s->failed_pc=0x0c0811c4u; return 0; }
r[13]=read(ram,r[11]+r[0],4);
goto P_0c0811c6;
P_0c0811c6: /* original 7016, guest PC 0x0c0811c6 */
if(!s->budget--) { s->failed_pc=0x0c0811c6u; return 0; }
r[0]+=0x00000016u;
goto P_0c0811c8;
P_0c0811c8: /* original 08bc, guest PC 0x0c0811c8 */
if(!s->budget--) { s->failed_pc=0x0c0811c8u; return 0; }
r[8]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0811ca;
P_0c0811ca: /* original 628e, guest PC 0x0c0811ca */
if(!s->budget--) { s->failed_pc=0x0c0811cau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c0811cc;
P_0c0811cc: /* original 6483, guest PC 0x0c0811cc */
if(!s->budget--) { s->failed_pc=0x0c0811ccu; return 0; }
r[4]=r[8];
goto P_0c0811ce;
P_0c0811ce: /* original 2228, guest PC 0x0c0811ce */
if(!s->budget--) { s->failed_pc=0x0c0811ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0811d0;
P_0c0811d0: /* original 8d02, guest PC 0x0c0811d0 */
if(!s->budget--) { s->failed_pc=0x0c0811d0u; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c0811d8; }
goto P_0c0811d4;
P_0c0811d2: /* original 74ff, guest PC 0x0c0811d2 */
if(!s->budget--) { s->failed_pc=0x0c0811d2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0811d4;
P_0c0811d4: /* original 903d, guest PC 0x0c0811d4 */
if(!s->budget--) { s->failed_pc=0x0c0811d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081252u,2);
goto P_0c0811d6;
P_0c0811d6: /* original 0b44, guest PC 0x0c0811d6 */
if(!s->budget--) { s->failed_pc=0x0c0811d6u; return 0; }
write(ram,r[11]+r[0],r[4],1);
goto P_0c0811d8;
P_0c0811d8: /* original 903c, guest PC 0x0c0811d8 */
if(!s->budget--) { s->failed_pc=0x0c0811d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081254u,2);
goto P_0c0811da;
P_0c0811da: /* original 09bc, guest PC 0x0c0811da */
if(!s->budget--) { s->failed_pc=0x0c0811dau; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0811dc;
P_0c0811dc: /* original 639e, guest PC 0x0c0811dc */
if(!s->budget--) { s->failed_pc=0x0c0811dcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[9];
goto P_0c0811de;
P_0c0811de: /* original 6493, guest PC 0x0c0811de */
if(!s->budget--) { s->failed_pc=0x0c0811deu; return 0; }
r[4]=r[9];
goto P_0c0811e0;
P_0c0811e0: /* original 2338, guest PC 0x0c0811e0 */
if(!s->budget--) { s->failed_pc=0x0c0811e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0811e2;
P_0c0811e2: /* original 8d01, guest PC 0x0c0811e2 */
if(!s->budget--) { s->failed_pc=0x0c0811e2u; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c0811e8; }
goto P_0c0811e6;
P_0c0811e4: /* original 74ff, guest PC 0x0c0811e4 */
if(!s->budget--) { s->failed_pc=0x0c0811e4u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0811e6;
P_0c0811e6: /* original 0b44, guest PC 0x0c0811e6 */
if(!s->budget--) { s->failed_pc=0x0c0811e6u; return 0; }
write(ram,r[11]+r[0],r[4],1);
goto P_0c0811e8;
P_0c0811e8: /* original d31f, guest PC 0x0c0811e8 */
if(!s->budget--) { s->failed_pc=0x0c0811e8u; return 0; }
r[3]=read(ram,0x0c081268u,4);
goto P_0c0811ea;
P_0c0811ea: /* original 9a34, guest PC 0x0c0811ea */
if(!s->budget--) { s->failed_pc=0x0c0811eau; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081256u,2);
goto P_0c0811ec;
P_0c0811ec: /* original 23d8, guest PC 0x0c0811ec */
if(!s->budget--) { s->failed_pc=0x0c0811ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0811ee;
P_0c0811ee: /* original 8b11, guest PC 0x0c0811ee */
if(!s->budget--) { s->failed_pc=0x0c0811eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081214; }
goto P_0c0811f0;
P_0c0811f0: /* original d11e, guest PC 0x0c0811f0 */
if(!s->budget--) { s->failed_pc=0x0c0811f0u; return 0; }
r[1]=read(ram,0x0c08126cu,4);
goto P_0c0811f2;
P_0c0811f2: /* original 2d19, guest PC 0x0c0811f2 */
if(!s->budget--) { s->failed_pc=0x0c0811f2u; return 0; }
r[13]&=r[1];
goto P_0c0811f4;
P_0c0811f4: /* original a006, guest PC 0x0c0811f4 */
if(!s->budget--) { s->failed_pc=0x0c0811f4u; return 0; }
r[12]=0x00000000u;
goto P_0c081204;
P_0c0811f6: /* original ec00, guest PC 0x0c0811f6 */
if(!s->budget--) { s->failed_pc=0x0c0811f6u; return 0; }
r[12]=0x00000000u;
goto P_0c0811f8;
P_0c0811f8: /* original 84f4, guest PC 0x0c0811f8 */
if(!s->budget--) { s->failed_pc=0x0c0811f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c0811fa;
P_0c0811fa: /* original 66f3, guest PC 0x0c0811fa */
if(!s->budget--) { s->failed_pc=0x0c0811fau; return 0; }
r[6]=r[15];
goto P_0c0811fc;
P_0c0811fc: /* original 6503, guest PC 0x0c0811fc */
if(!s->budget--) { s->failed_pc=0x0c0811fcu; return 0; }
r[5]=r[0];
goto P_0c0811fe;
P_0c0811fe: /* original b418, guest PC 0x0c0811fe */
if(!s->budget--) { s->failed_pc=0x0c0811feu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081202u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081202u) { target=s->pc; goto dispatch; }
goto P_0c081202;
P_0c081200: /* original 64e3, guest PC 0x0c081200 */
if(!s->budget--) { s->failed_pc=0x0c081200u; return 0; }
r[4]=r[14];
goto P_0c081202;
P_0c081202: /* original 7c01, guest PC 0x0c081202 */
if(!s->budget--) { s->failed_pc=0x0c081202u; return 0; }
r[12]+=0x00000001u;
goto P_0c081204;
P_0c081204: /* original d01a, guest PC 0x0c081204 */
if(!s->budget--) { s->failed_pc=0x0c081204u; return 0; }
r[0]=read(ram,0x0c081270u,4);
goto P_0c081206;
P_0c081206: /* original 62f3, guest PC 0x0c081206 */
if(!s->budget--) { s->failed_pc=0x0c081206u; return 0; }
r[2]=r[15];
goto P_0c081208;
P_0c081208: /* original 7204, guest PC 0x0c081208 */
if(!s->budget--) { s->failed_pc=0x0c081208u; return 0; }
r[2]+=0x00000004u;
goto P_0c08120a;
P_0c08120a: /* original 03cc, guest PC 0x0c08120a */
if(!s->budget--) { s->failed_pc=0x0c08120au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08120c;
P_0c08120c: /* original 2230, guest PC 0x0c08120c */
if(!s->budget--) { s->failed_pc=0x0c08120cu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c08120e;
P_0c08120e: /* original 633c, guest PC 0x0c08120e */
if(!s->budget--) { s->failed_pc=0x0c08120eu; return 0; }
r[3]=r[3]&255u;
goto P_0c081210;
P_0c081210: /* original 33a0, guest PC 0x0c081210 */
if(!s->budget--) { s->failed_pc=0x0c081210u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[10])!=0);
goto P_0c081212;
P_0c081212: /* original 8bf1, guest PC 0x0c081212 */
if(!s->budget--) { s->failed_pc=0x0c081212u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0811f8; }
goto P_0c081214;
P_0c081214: /* original d217, guest PC 0x0c081214 */
if(!s->budget--) { s->failed_pc=0x0c081214u; return 0; }
r[2]=read(ram,0x0c081274u,4);
goto P_0c081216;
P_0c081216: /* original 22d8, guest PC 0x0c081216 */
if(!s->budget--) { s->failed_pc=0x0c081216u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c081218;
P_0c081218: /* original 8911, guest PC 0x0c081218 */
if(!s->budget--) { s->failed_pc=0x0c081218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08123e; }
goto P_0c08121a;
P_0c08121a: /* original d117, guest PC 0x0c08121a */
if(!s->budget--) { s->failed_pc=0x0c08121au; return 0; }
r[1]=read(ram,0x0c081278u,4);
goto P_0c08121c;
P_0c08121c: /* original 2d19, guest PC 0x0c08121c */
if(!s->budget--) { s->failed_pc=0x0c08121cu; return 0; }
r[13]&=r[1];
goto P_0c08121e;
P_0c08121e: /* original a006, guest PC 0x0c08121e */
if(!s->budget--) { s->failed_pc=0x0c08121eu; return 0; }
r[12]=0x00000000u;
goto P_0c08122e;
P_0c081220: /* original ec00, guest PC 0x0c081220 */
if(!s->budget--) { s->failed_pc=0x0c081220u; return 0; }
r[12]=0x00000000u;
goto P_0c081222;
P_0c081222: /* original 84f4, guest PC 0x0c081222 */
if(!s->budget--) { s->failed_pc=0x0c081222u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c081224;
P_0c081224: /* original 66f3, guest PC 0x0c081224 */
if(!s->budget--) { s->failed_pc=0x0c081224u; return 0; }
r[6]=r[15];
goto P_0c081226;
P_0c081226: /* original 6503, guest PC 0x0c081226 */
if(!s->budget--) { s->failed_pc=0x0c081226u; return 0; }
r[5]=r[0];
goto P_0c081228;
P_0c081228: /* original b403, guest PC 0x0c081228 */
if(!s->budget--) { s->failed_pc=0x0c081228u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08122cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08122cu) { target=s->pc; goto dispatch; }
goto P_0c08122c;
P_0c08122a: /* original 64e3, guest PC 0x0c08122a */
if(!s->budget--) { s->failed_pc=0x0c08122au; return 0; }
r[4]=r[14];
goto P_0c08122c;
P_0c08122c: /* original 7c01, guest PC 0x0c08122c */
if(!s->budget--) { s->failed_pc=0x0c08122cu; return 0; }
r[12]+=0x00000001u;
goto P_0c08122e;
P_0c08122e: /* original d013, guest PC 0x0c08122e */
if(!s->budget--) { s->failed_pc=0x0c08122eu; return 0; }
r[0]=read(ram,0x0c08127cu,4);
goto P_0c081230;
P_0c081230: /* original 62f3, guest PC 0x0c081230 */
if(!s->budget--) { s->failed_pc=0x0c081230u; return 0; }
r[2]=r[15];
goto P_0c081232;
P_0c081232: /* original 7204, guest PC 0x0c081232 */
if(!s->budget--) { s->failed_pc=0x0c081232u; return 0; }
r[2]+=0x00000004u;
goto P_0c081234;
P_0c081234: /* original 03cc, guest PC 0x0c081234 */
if(!s->budget--) { s->failed_pc=0x0c081234u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c081236;
P_0c081236: /* original 2230, guest PC 0x0c081236 */
if(!s->budget--) { s->failed_pc=0x0c081236u; return 0; }
write(ram,r[2],r[3],1);
goto P_0c081238;
P_0c081238: /* original 633c, guest PC 0x0c081238 */
if(!s->budget--) { s->failed_pc=0x0c081238u; return 0; }
r[3]=r[3]&255u;
goto P_0c08123a;
P_0c08123a: /* original 33a0, guest PC 0x0c08123a */
if(!s->budget--) { s->failed_pc=0x0c08123au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[10])!=0);
goto P_0c08123c;
P_0c08123c: /* original 8bf1, guest PC 0x0c08123c */
if(!s->budget--) { s->failed_pc=0x0c08123cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081222; }
goto P_0c08123e;
P_0c08123e: /* original d210, guest PC 0x0c08123e */
if(!s->budget--) { s->failed_pc=0x0c08123eu; return 0; }
r[2]=read(ram,0x0c081280u,4);
goto P_0c081240;
P_0c081240: /* original 22d8, guest PC 0x0c081240 */
if(!s->budget--) { s->failed_pc=0x0c081240u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c081242;
P_0c081242: /* original 892f, guest PC 0x0c081242 */
if(!s->budget--) { s->failed_pc=0x0c081242u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0812a4; }
goto P_0c081244;
P_0c081244: /* original d10f, guest PC 0x0c081244 */
if(!s->budget--) { s->failed_pc=0x0c081244u; return 0; }
r[1]=read(ram,0x0c081284u,4);
goto P_0c081246;
P_0c081246: /* original 2d19, guest PC 0x0c081246 */
if(!s->budget--) { s->failed_pc=0x0c081246u; return 0; }
r[13]&=r[1];
goto P_0c081248;
P_0c081248: /* original a024, guest PC 0x0c081248 */
if(!s->budget--) { s->failed_pc=0x0c081248u; return 0; }
r[12]=0x00000000u;
goto P_0c081294;
P_0c08124a: /* original ec00, guest PC 0x0c08124a */
if(!s->budget--) { s->failed_pc=0x0c08124au; return 0; }
r[12]=0x00000000u;
if(!vf3_matrix_family(0x0c08124cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08124cu; return 0; } return 1;
P_0c081288: /* original 84f4, guest PC 0x0c081288 */
if(!s->budget--) { s->failed_pc=0x0c081288u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c08128a;
P_0c08128a: /* original 66f3, guest PC 0x0c08128a */
if(!s->budget--) { s->failed_pc=0x0c08128au; return 0; }
r[6]=r[15];
goto P_0c08128c;
P_0c08128c: /* original 6503, guest PC 0x0c08128c */
if(!s->budget--) { s->failed_pc=0x0c08128cu; return 0; }
r[5]=r[0];
goto P_0c08128e;
P_0c08128e: /* original b3d0, guest PC 0x0c08128e */
if(!s->budget--) { s->failed_pc=0x0c08128eu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081292u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081292u) { target=s->pc; goto dispatch; }
goto P_0c081292;
P_0c081290: /* original 64e3, guest PC 0x0c081290 */
if(!s->budget--) { s->failed_pc=0x0c081290u; return 0; }
r[4]=r[14];
goto P_0c081292;
P_0c081292: /* original 7c01, guest PC 0x0c081292 */
if(!s->budget--) { s->failed_pc=0x0c081292u; return 0; }
r[12]+=0x00000001u;
goto P_0c081294;
P_0c081294: /* original d03a, guest PC 0x0c081294 */
if(!s->budget--) { s->failed_pc=0x0c081294u; return 0; }
r[0]=read(ram,0x0c081380u,4);
goto P_0c081296;
P_0c081296: /* original 62f3, guest PC 0x0c081296 */
if(!s->budget--) { s->failed_pc=0x0c081296u; return 0; }
r[2]=r[15];
goto P_0c081298;
P_0c081298: /* original 7204, guest PC 0x0c081298 */
if(!s->budget--) { s->failed_pc=0x0c081298u; return 0; }
r[2]+=0x00000004u;
goto P_0c08129a;
P_0c08129a: /* original 03cc, guest PC 0x0c08129a */
if(!s->budget--) { s->failed_pc=0x0c08129au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08129c;
P_0c08129c: /* original 2230, guest PC 0x0c08129c */
if(!s->budget--) { s->failed_pc=0x0c08129cu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c08129e;
P_0c08129e: /* original 633c, guest PC 0x0c08129e */
if(!s->budget--) { s->failed_pc=0x0c08129eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0812a0;
P_0c0812a0: /* original 33a0, guest PC 0x0c0812a0 */
if(!s->budget--) { s->failed_pc=0x0c0812a0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[10])!=0);
goto P_0c0812a2;
P_0c0812a2: /* original 8bf1, guest PC 0x0c0812a2 */
if(!s->budget--) { s->failed_pc=0x0c0812a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081288; }
goto P_0c0812a4;
P_0c0812a4: /* original d237, guest PC 0x0c0812a4 */
if(!s->budget--) { s->failed_pc=0x0c0812a4u; return 0; }
r[2]=read(ram,0x0c081384u,4);
goto P_0c0812a6;
P_0c0812a6: /* original 22d8, guest PC 0x0c0812a6 */
if(!s->budget--) { s->failed_pc=0x0c0812a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0812a8;
P_0c0812a8: /* original 8909, guest PC 0x0c0812a8 */
if(!s->budget--) { s->failed_pc=0x0c0812a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0812be; }
goto P_0c0812aa;
P_0c0812aa: /* original d137, guest PC 0x0c0812aa */
if(!s->budget--) { s->failed_pc=0x0c0812aau; return 0; }
r[1]=read(ram,0x0c081388u,4);
goto P_0c0812ac;
P_0c0812ac: /* original e5a0, guest PC 0x0c0812ac */
if(!s->budget--) { s->failed_pc=0x0c0812acu; return 0; }
r[5]=0xffffffa0u;
goto P_0c0812ae;
P_0c0812ae: /* original 66f3, guest PC 0x0c0812ae */
if(!s->budget--) { s->failed_pc=0x0c0812aeu; return 0; }
r[6]=r[15];
goto P_0c0812b0;
P_0c0812b0: /* original 2d19, guest PC 0x0c0812b0 */
if(!s->budget--) { s->failed_pc=0x0c0812b0u; return 0; }
r[13]&=r[1];
goto P_0c0812b2;
P_0c0812b2: /* original b3be, guest PC 0x0c0812b2 */
if(!s->budget--) { s->failed_pc=0x0c0812b2u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0812b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0812b6u) { target=s->pc; goto dispatch; }
goto P_0c0812b6;
P_0c0812b4: /* original 64e3, guest PC 0x0c0812b4 */
if(!s->budget--) { s->failed_pc=0x0c0812b4u; return 0; }
r[4]=r[14];
goto P_0c0812b6;
P_0c0812b6: /* original e5a8, guest PC 0x0c0812b6 */
if(!s->budget--) { s->failed_pc=0x0c0812b6u; return 0; }
r[5]=0xffffffa8u;
goto P_0c0812b8;
P_0c0812b8: /* original 66f3, guest PC 0x0c0812b8 */
if(!s->budget--) { s->failed_pc=0x0c0812b8u; return 0; }
r[6]=r[15];
goto P_0c0812ba;
P_0c0812ba: /* original b3ba, guest PC 0x0c0812ba */
if(!s->budget--) { s->failed_pc=0x0c0812bau; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0812beu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0812beu) { target=s->pc; goto dispatch; }
goto P_0c0812be;
P_0c0812bc: /* original 64e3, guest PC 0x0c0812bc */
if(!s->budget--) { s->failed_pc=0x0c0812bcu; return 0; }
r[4]=r[14];
goto P_0c0812be;
P_0c0812be: /* original d334, guest PC 0x0c0812be */
if(!s->budget--) { s->failed_pc=0x0c0812beu; return 0; }
r[3]=read(ram,0x0c081390u,4);
goto P_0c0812c0;
P_0c0812c0: /* original dc32, guest PC 0x0c0812c0 */
if(!s->budget--) { s->failed_pc=0x0c0812c0u; return 0; }
r[12]=read(ram,0x0c08138cu,4);
goto P_0c0812c2;
P_0c0812c2: /* original 23d8, guest PC 0x0c0812c2 */
if(!s->budget--) { s->failed_pc=0x0c0812c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0812c4;
P_0c0812c4: /* original 8945, guest PC 0x0c0812c4 */
if(!s->budget--) { s->failed_pc=0x0c0812c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081352; }
goto P_0c0812c6;
P_0c0812c6: /* original d133, guest PC 0x0c0812c6 */
if(!s->budget--) { s->failed_pc=0x0c0812c6u; return 0; }
r[1]=read(ram,0x0c081394u,4);
goto P_0c0812c8;
P_0c0812c8: /* original 410b, guest PC 0x0c0812c8 */
if(!s->budget--) { s->failed_pc=0x0c0812c8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0812ccu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0812ccu) { target=s->pc; goto dispatch; }
goto P_0c0812cc;
P_0c0812ca: /* original 0009, guest PC 0x0c0812ca */
if(!s->budget--) { s->failed_pc=0x0c0812cau; return 0; }
goto P_0c0812cc;
P_0c0812cc: /* original 640c, guest PC 0x0c0812cc */
if(!s->budget--) { s->failed_pc=0x0c0812ccu; return 0; }
r[4]=r[0]&255u;
goto P_0c0812ce;
P_0c0812ce: /* original 1f41, guest PC 0x0c0812ce */
if(!s->budget--) { s->failed_pc=0x0c0812ceu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0812d0;
P_0c0812d0: /* original 9054, guest PC 0x0c0812d0 */
if(!s->budget--) { s->failed_pc=0x0c0812d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08137cu,2);
goto P_0c0812d2;
P_0c0812d2: /* original 04cc, guest PC 0x0c0812d2 */
if(!s->budget--) { s->failed_pc=0x0c0812d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0812d4;
P_0c0812d4: /* original 634c, guest PC 0x0c0812d4 */
if(!s->budget--) { s->failed_pc=0x0c0812d4u; return 0; }
r[3]=r[4]&255u;
goto P_0c0812d6;
P_0c0812d6: /* original 33a0, guest PC 0x0c0812d6 */
if(!s->budget--) { s->failed_pc=0x0c0812d6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[10])!=0);
goto P_0c0812d8;
P_0c0812d8: /* original 8b07, guest PC 0x0c0812d8 */
if(!s->budget--) { s->failed_pc=0x0c0812d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0812ea; }
goto P_0c0812da;
P_0c0812da: /* original d32f, guest PC 0x0c0812da */
if(!s->budget--) { s->failed_pc=0x0c0812dau; return 0; }
r[3]=read(ram,0x0c081398u,4);
goto P_0c0812dc;
P_0c0812dc: /* original e203, guest PC 0x0c0812dc */
if(!s->budget--) { s->failed_pc=0x0c0812dcu; return 0; }
r[2]=0x00000003u;
goto P_0c0812de;
P_0c0812de: /* original 6432, guest PC 0x0c0812de */
if(!s->budget--) { s->failed_pc=0x0c0812deu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0812e0;
P_0c0812e0: /* original 2429, guest PC 0x0c0812e0 */
if(!s->budget--) { s->failed_pc=0x0c0812e0u; return 0; }
r[4]&=r[2];
goto P_0c0812e2;
P_0c0812e2: /* original 2448, guest PC 0x0c0812e2 */
if(!s->budget--) { s->failed_pc=0x0c0812e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0812e4;
P_0c0812e4: /* original 891e, guest PC 0x0c0812e4 */
if(!s->budget--) { s->failed_pc=0x0c0812e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081324; }
goto P_0c0812e6;
P_0c0812e6: /* original a034, guest PC 0x0c0812e6 */
if(!s->budget--) { s->failed_pc=0x0c0812e6u; return 0; }
goto P_0c081352;
P_0c0812e8: /* original 0009, guest PC 0x0c0812e8 */
if(!s->budget--) { s->failed_pc=0x0c0812e8u; return 0; }
goto P_0c0812ea;
P_0c0812ea: /* original 9048, guest PC 0x0c0812ea */
if(!s->budget--) { s->failed_pc=0x0c0812eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08137eu,2);
goto P_0c0812ec;
P_0c0812ec: /* original d12b, guest PC 0x0c0812ec */
if(!s->budget--) { s->failed_pc=0x0c0812ecu; return 0; }
r[1]=read(ram,0x0c08139cu,4);
goto P_0c0812ee;
P_0c0812ee: /* original 03cc, guest PC 0x0c0812ee */
if(!s->budget--) { s->failed_pc=0x0c0812eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0812f0;
P_0c0812f0: /* original e011, guest PC 0x0c0812f0 */
if(!s->budget--) { s->failed_pc=0x0c0812f0u; return 0; }
r[0]=0x00000011u;
goto P_0c0812f2;
P_0c0812f2: /* original 2d19, guest PC 0x0c0812f2 */
if(!s->budget--) { s->failed_pc=0x0c0812f2u; return 0; }
r[13]&=r[1];
goto P_0c0812f4;
P_0c0812f4: /* original 1f31, guest PC 0x0c0812f4 */
if(!s->budget--) { s->failed_pc=0x0c0812f4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0812f6;
P_0c0812f6: /* original d22a, guest PC 0x0c0812f6 */
if(!s->budget--) { s->failed_pc=0x0c0812f6u; return 0; }
r[2]=read(ram,0x0c0813a0u,4);
goto P_0c0812f8;
P_0c0812f8: /* original 420b, guest PC 0x0c0812f8 */
if(!s->budget--) { s->failed_pc=0x0c0812f8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0812fcu;
r[1]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0812fcu) { target=s->pc; goto dispatch; }
goto P_0c0812fc;
P_0c0812fa: /* original 6133, guest PC 0x0c0812fa */
if(!s->budget--) { s->failed_pc=0x0c0812fau; return 0; }
r[1]=r[3];
goto P_0c0812fc;
P_0c0812fc: /* original 6503, guest PC 0x0c0812fc */
if(!s->budget--) { s->failed_pc=0x0c0812fcu; return 0; }
r[5]=r[0];
goto P_0c0812fe;
P_0c0812fe: /* original 4508, guest PC 0x0c0812fe */
if(!s->budget--) { s->failed_pc=0x0c0812feu; return 0; }
r[5]<<=2;
goto P_0c081300;
P_0c081300: /* original 4508, guest PC 0x0c081300 */
if(!s->budget--) { s->failed_pc=0x0c081300u; return 0; }
r[5]<<=2;
goto P_0c081302;
P_0c081302: /* original 6203, guest PC 0x0c081302 */
if(!s->budget--) { s->failed_pc=0x0c081302u; return 0; }
r[2]=r[0];
goto P_0c081304;
P_0c081304: /* original 6133, guest PC 0x0c081304 */
if(!s->budget--) { s->failed_pc=0x0c081304u; return 0; }
r[1]=r[3];
goto P_0c081306;
P_0c081306: /* original 352c, guest PC 0x0c081306 */
if(!s->budget--) { s->failed_pc=0x0c081306u; return 0; }
r[5]+=r[2];
goto P_0c081308;
P_0c081308: /* original 3158, guest PC 0x0c081308 */
if(!s->budget--) { s->failed_pc=0x0c081308u; return 0; }
r[1]-=r[5];
goto P_0c08130a;
P_0c08130a: /* original 6513, guest PC 0x0c08130a */
if(!s->budget--) { s->failed_pc=0x0c08130au; return 0; }
r[5]=r[1];
goto P_0c08130c;
P_0c08130c: /* original 2558, guest PC 0x0c08130c */
if(!s->budget--) { s->failed_pc=0x0c08130cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c08130e;
P_0c08130e: /* original 8b09, guest PC 0x0c08130e */
if(!s->budget--) { s->failed_pc=0x0c08130eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081324; }
goto P_0c081310;
P_0c081310: /* original e110, guest PC 0x0c081310 */
if(!s->budget--) { s->failed_pc=0x0c081310u; return 0; }
r[1]=0x00000010u;
goto P_0c081312;
P_0c081312: /* original 644c, guest PC 0x0c081312 */
if(!s->budget--) { s->failed_pc=0x0c081312u; return 0; }
r[4]=r[4]&255u;
goto P_0c081314;
P_0c081314: /* original 3413, guest PC 0x0c081314 */
if(!s->budget--) { s->failed_pc=0x0c081314u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[1])!=0);
goto P_0c081316;
P_0c081316: /* original 8b05, guest PC 0x0c081316 */
if(!s->budget--) { s->failed_pc=0x0c081316u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081324; }
goto P_0c081318;
P_0c081318: /* original e592, guest PC 0x0c081318 */
if(!s->budget--) { s->failed_pc=0x0c081318u; return 0; }
r[5]=0xffffff92u;
goto P_0c08131a;
P_0c08131a: /* original 66f3, guest PC 0x0c08131a */
if(!s->budget--) { s->failed_pc=0x0c08131au; return 0; }
r[6]=r[15];
goto P_0c08131c;
P_0c08131c: /* original b389, guest PC 0x0c08131c */
if(!s->budget--) { s->failed_pc=0x0c08131cu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081320u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081320u) { target=s->pc; goto dispatch; }
goto P_0c081320;
P_0c08131e: /* original 64e3, guest PC 0x0c08131e */
if(!s->budget--) { s->failed_pc=0x0c08131eu; return 0; }
r[4]=r[14];
goto P_0c081320;
P_0c081320: /* original d220, guest PC 0x0c081320 */
if(!s->budget--) { s->failed_pc=0x0c081320u; return 0; }
r[2]=read(ram,0x0c0813a4u,4);
goto P_0c081322;
P_0c081322: /* original 2d2b, guest PC 0x0c081322 */
if(!s->budget--) { s->failed_pc=0x0c081322u; return 0; }
r[13]|=r[2];
goto P_0c081324;
P_0c081324: /* original d31e, guest PC 0x0c081324 */
if(!s->budget--) { s->failed_pc=0x0c081324u; return 0; }
r[3]=read(ram,0x0c0813a0u,4);
goto P_0c081326;
P_0c081326: /* original e410, guest PC 0x0c081326 */
if(!s->budget--) { s->failed_pc=0x0c081326u; return 0; }
r[4]=0x00000010u;
goto P_0c081328;
P_0c081328: /* original 51f1, guest PC 0x0c081328 */
if(!s->budget--) { s->failed_pc=0x0c081328u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c08132a;
P_0c08132a: /* original 430b, guest PC 0x0c08132a */
if(!s->budget--) { s->failed_pc=0x0c08132au; return 0; }
target=r[3];
r[16]=code_base|0x0c08132eu;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08132eu) { target=s->pc; goto dispatch; }
goto P_0c08132e;
P_0c08132c: /* original 6043, guest PC 0x0c08132c */
if(!s->budget--) { s->failed_pc=0x0c08132cu; return 0; }
r[0]=r[4];
goto P_0c08132e;
P_0c08132e: /* original 1f05, guest PC 0x0c08132e */
if(!s->budget--) { s->failed_pc=0x0c08132eu; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c081330;
P_0c081330: /* original 7020, guest PC 0x0c081330 */
if(!s->budget--) { s->failed_pc=0x0c081330u; return 0; }
r[0]+=0x00000020u;
goto P_0c081332;
P_0c081332: /* original 80f8, guest PC 0x0c081332 */
if(!s->budget--) { s->failed_pc=0x0c081332u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c081334;
P_0c081334: /* original 66f3, guest PC 0x0c081334 */
if(!s->budget--) { s->failed_pc=0x0c081334u; return 0; }
r[6]=r[15];
goto P_0c081336;
P_0c081336: /* original 84f8, guest PC 0x0c081336 */
if(!s->budget--) { s->failed_pc=0x0c081336u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c081338;
P_0c081338: /* original 6503, guest PC 0x0c081338 */
if(!s->budget--) { s->failed_pc=0x0c081338u; return 0; }
r[5]=r[0];
goto P_0c08133a;
P_0c08133a: /* original b37a, guest PC 0x0c08133a */
if(!s->budget--) { s->failed_pc=0x0c08133au; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08133eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08133eu) { target=s->pc; goto dispatch; }
goto P_0c08133e;
P_0c08133c: /* original 64e3, guest PC 0x0c08133c */
if(!s->budget--) { s->failed_pc=0x0c08133cu; return 0; }
r[4]=r[14];
goto P_0c08133e;
P_0c08133e: /* original 54f5, guest PC 0x0c08133e */
if(!s->budget--) { s->failed_pc=0x0c08133eu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c081340;
P_0c081340: /* original 66f3, guest PC 0x0c081340 */
if(!s->budget--) { s->failed_pc=0x0c081340u; return 0; }
r[6]=r[15];
goto P_0c081342;
P_0c081342: /* original 84f4, guest PC 0x0c081342 */
if(!s->budget--) { s->failed_pc=0x0c081342u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c081344;
P_0c081344: /* original 4408, guest PC 0x0c081344 */
if(!s->budget--) { s->failed_pc=0x0c081344u; return 0; }
r[4]<<=2;
goto P_0c081346;
P_0c081346: /* original 4408, guest PC 0x0c081346 */
if(!s->budget--) { s->failed_pc=0x0c081346u; return 0; }
r[4]<<=2;
goto P_0c081348;
P_0c081348: /* original 3048, guest PC 0x0c081348 */
if(!s->budget--) { s->failed_pc=0x0c081348u; return 0; }
r[0]-=r[4];
goto P_0c08134a;
P_0c08134a: /* original 6503, guest PC 0x0c08134a */
if(!s->budget--) { s->failed_pc=0x0c08134au; return 0; }
r[5]=r[0];
goto P_0c08134c;
P_0c08134c: /* original 80f4, guest PC 0x0c08134c */
if(!s->budget--) { s->failed_pc=0x0c08134cu; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c08134e;
P_0c08134e: /* original b370, guest PC 0x0c08134e */
if(!s->budget--) { s->failed_pc=0x0c08134eu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081352u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081352u) { target=s->pc; goto dispatch; }
goto P_0c081352;
P_0c081350: /* original 64e3, guest PC 0x0c081350 */
if(!s->budget--) { s->failed_pc=0x0c081350u; return 0; }
r[4]=r[14];
goto P_0c081352;
P_0c081352: /* original d215, guest PC 0x0c081352 */
if(!s->budget--) { s->failed_pc=0x0c081352u; return 0; }
r[2]=read(ram,0x0c0813a8u,4);
goto P_0c081354;
P_0c081354: /* original 22d8, guest PC 0x0c081354 */
if(!s->budget--) { s->failed_pc=0x0c081354u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c081356;
P_0c081356: /* original 895e, guest PC 0x0c081356 */
if(!s->budget--) { s->failed_pc=0x0c081356u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081416; }
goto P_0c081358;
P_0c081358: /* original d10e, guest PC 0x0c081358 */
if(!s->budget--) { s->failed_pc=0x0c081358u; return 0; }
r[1]=read(ram,0x0c081394u,4);
goto P_0c08135a;
P_0c08135a: /* original 410b, guest PC 0x0c08135a */
if(!s->budget--) { s->failed_pc=0x0c08135au; return 0; }
target=r[1];
r[16]=code_base|0x0c08135eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08135eu) { target=s->pc; goto dispatch; }
goto P_0c08135e;
P_0c08135c: /* original 0009, guest PC 0x0c08135c */
if(!s->budget--) { s->failed_pc=0x0c08135cu; return 0; }
goto P_0c08135e;
P_0c08135e: /* original 640c, guest PC 0x0c08135e */
if(!s->budget--) { s->failed_pc=0x0c08135eu; return 0; }
r[4]=r[0]&255u;
goto P_0c081360;
P_0c081360: /* original 1f41, guest PC 0x0c081360 */
if(!s->budget--) { s->failed_pc=0x0c081360u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c081362;
P_0c081362: /* original 900b, guest PC 0x0c081362 */
if(!s->budget--) { s->failed_pc=0x0c081362u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08137cu,2);
goto P_0c081364;
P_0c081364: /* original 05cc, guest PC 0x0c081364 */
if(!s->budget--) { s->failed_pc=0x0c081364u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c081366;
P_0c081366: /* original 645c, guest PC 0x0c081366 */
if(!s->budget--) { s->failed_pc=0x0c081366u; return 0; }
r[4]=r[5]&255u;
goto P_0c081368;
P_0c081368: /* original 34a0, guest PC 0x0c081368 */
if(!s->budget--) { s->failed_pc=0x0c081368u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[10])!=0);
goto P_0c08136a;
P_0c08136a: /* original 8b1f, guest PC 0x0c08136a */
if(!s->budget--) { s->failed_pc=0x0c08136au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0813ac; }
goto P_0c08136c;
P_0c08136c: /* original d20a, guest PC 0x0c08136c */
if(!s->budget--) { s->failed_pc=0x0c08136cu; return 0; }
r[2]=read(ram,0x0c081398u,4);
goto P_0c08136e;
P_0c08136e: /* original e303, guest PC 0x0c08136e */
if(!s->budget--) { s->failed_pc=0x0c08136eu; return 0; }
r[3]=0x00000003u;
goto P_0c081370;
P_0c081370: /* original 6422, guest PC 0x0c081370 */
if(!s->budget--) { s->failed_pc=0x0c081370u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c081372;
P_0c081372: /* original 2439, guest PC 0x0c081372 */
if(!s->budget--) { s->failed_pc=0x0c081372u; return 0; }
r[4]&=r[3];
goto P_0c081374;
P_0c081374: /* original 2448, guest PC 0x0c081374 */
if(!s->budget--) { s->failed_pc=0x0c081374u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c081376;
P_0c081376: /* original 8935, guest PC 0x0c081376 */
if(!s->budget--) { s->failed_pc=0x0c081376u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0813e4; }
goto P_0c081378;
P_0c081378: /* original a04d, guest PC 0x0c081378 */
if(!s->budget--) { s->failed_pc=0x0c081378u; return 0; }
goto P_0c081416;
P_0c08137a: /* original 0009, guest PC 0x0c08137a */
if(!s->budget--) { s->failed_pc=0x0c08137au; return 0; }
if(!vf3_matrix_family(0x0c08137cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08137cu; return 0; } return 1;
P_0c0813ac: /* original 9084, guest PC 0x0c0813ac */
if(!s->budget--) { s->failed_pc=0x0c0813acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0814b8u,2);
goto P_0c0813ae;
P_0c0813ae: /* original d144, guest PC 0x0c0813ae */
if(!s->budget--) { s->failed_pc=0x0c0813aeu; return 0; }
r[1]=read(ram,0x0c0814c0u,4);
goto P_0c0813b0;
P_0c0813b0: /* original 03cc, guest PC 0x0c0813b0 */
if(!s->budget--) { s->failed_pc=0x0c0813b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0813b2;
P_0c0813b2: /* original e011, guest PC 0x0c0813b2 */
if(!s->budget--) { s->failed_pc=0x0c0813b2u; return 0; }
r[0]=0x00000011u;
goto P_0c0813b4;
P_0c0813b4: /* original 2d19, guest PC 0x0c0813b4 */
if(!s->budget--) { s->failed_pc=0x0c0813b4u; return 0; }
r[13]&=r[1];
goto P_0c0813b6;
P_0c0813b6: /* original 1f31, guest PC 0x0c0813b6 */
if(!s->budget--) { s->failed_pc=0x0c0813b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0813b8;
P_0c0813b8: /* original d242, guest PC 0x0c0813b8 */
if(!s->budget--) { s->failed_pc=0x0c0813b8u; return 0; }
r[2]=read(ram,0x0c0814c4u,4);
goto P_0c0813ba;
P_0c0813ba: /* original 420b, guest PC 0x0c0813ba */
if(!s->budget--) { s->failed_pc=0x0c0813bau; return 0; }
target=r[2];
r[16]=code_base|0x0c0813beu;
r[1]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0813beu) { target=s->pc; goto dispatch; }
goto P_0c0813be;
P_0c0813bc: /* original 6133, guest PC 0x0c0813bc */
if(!s->budget--) { s->failed_pc=0x0c0813bcu; return 0; }
r[1]=r[3];
goto P_0c0813be;
P_0c0813be: /* original 6503, guest PC 0x0c0813be */
if(!s->budget--) { s->failed_pc=0x0c0813beu; return 0; }
r[5]=r[0];
goto P_0c0813c0;
P_0c0813c0: /* original 4508, guest PC 0x0c0813c0 */
if(!s->budget--) { s->failed_pc=0x0c0813c0u; return 0; }
r[5]<<=2;
goto P_0c0813c2;
P_0c0813c2: /* original 4508, guest PC 0x0c0813c2 */
if(!s->budget--) { s->failed_pc=0x0c0813c2u; return 0; }
r[5]<<=2;
goto P_0c0813c4;
P_0c0813c4: /* original 6203, guest PC 0x0c0813c4 */
if(!s->budget--) { s->failed_pc=0x0c0813c4u; return 0; }
r[2]=r[0];
goto P_0c0813c6;
P_0c0813c6: /* original 6133, guest PC 0x0c0813c6 */
if(!s->budget--) { s->failed_pc=0x0c0813c6u; return 0; }
r[1]=r[3];
goto P_0c0813c8;
P_0c0813c8: /* original 352c, guest PC 0x0c0813c8 */
if(!s->budget--) { s->failed_pc=0x0c0813c8u; return 0; }
r[5]+=r[2];
goto P_0c0813ca;
P_0c0813ca: /* original 3158, guest PC 0x0c0813ca */
if(!s->budget--) { s->failed_pc=0x0c0813cau; return 0; }
r[1]-=r[5];
goto P_0c0813cc;
P_0c0813cc: /* original 6513, guest PC 0x0c0813cc */
if(!s->budget--) { s->failed_pc=0x0c0813ccu; return 0; }
r[5]=r[1];
goto P_0c0813ce;
P_0c0813ce: /* original 2558, guest PC 0x0c0813ce */
if(!s->budget--) { s->failed_pc=0x0c0813ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0813d0;
P_0c0813d0: /* original 8b08, guest PC 0x0c0813d0 */
if(!s->budget--) { s->failed_pc=0x0c0813d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0813e4; }
goto P_0c0813d2;
P_0c0813d2: /* original e010, guest PC 0x0c0813d2 */
if(!s->budget--) { s->failed_pc=0x0c0813d2u; return 0; }
r[0]=0x00000010u;
goto P_0c0813d4;
P_0c0813d4: /* original 3403, guest PC 0x0c0813d4 */
if(!s->budget--) { s->failed_pc=0x0c0813d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0813d6;
P_0c0813d6: /* original 8b05, guest PC 0x0c0813d6 */
if(!s->budget--) { s->failed_pc=0x0c0813d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0813e4; }
goto P_0c0813d8;
P_0c0813d8: /* original e59a, guest PC 0x0c0813d8 */
if(!s->budget--) { s->failed_pc=0x0c0813d8u; return 0; }
r[5]=0xffffff9au;
goto P_0c0813da;
P_0c0813da: /* original 66f3, guest PC 0x0c0813da */
if(!s->budget--) { s->failed_pc=0x0c0813dau; return 0; }
r[6]=r[15];
goto P_0c0813dc;
P_0c0813dc: /* original b329, guest PC 0x0c0813dc */
if(!s->budget--) { s->failed_pc=0x0c0813dcu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0813e0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0813e0u) { target=s->pc; goto dispatch; }
goto P_0c0813e0;
P_0c0813de: /* original 64e3, guest PC 0x0c0813de */
if(!s->budget--) { s->failed_pc=0x0c0813deu; return 0; }
r[4]=r[14];
goto P_0c0813e0;
P_0c0813e0: /* original d339, guest PC 0x0c0813e0 */
if(!s->budget--) { s->failed_pc=0x0c0813e0u; return 0; }
r[3]=read(ram,0x0c0814c8u,4);
goto P_0c0813e2;
P_0c0813e2: /* original 2d3b, guest PC 0x0c0813e2 */
if(!s->budget--) { s->failed_pc=0x0c0813e2u; return 0; }
r[13]|=r[3];
goto P_0c0813e4;
P_0c0813e4: /* original d237, guest PC 0x0c0813e4 */
if(!s->budget--) { s->failed_pc=0x0c0813e4u; return 0; }
r[2]=read(ram,0x0c0814c4u,4);
goto P_0c0813e6;
P_0c0813e6: /* original e410, guest PC 0x0c0813e6 */
if(!s->budget--) { s->failed_pc=0x0c0813e6u; return 0; }
r[4]=0x00000010u;
goto P_0c0813e8;
P_0c0813e8: /* original 51f1, guest PC 0x0c0813e8 */
if(!s->budget--) { s->failed_pc=0x0c0813e8u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0813ea;
P_0c0813ea: /* original 420b, guest PC 0x0c0813ea */
if(!s->budget--) { s->failed_pc=0x0c0813eau; return 0; }
target=r[2];
r[16]=code_base|0x0c0813eeu;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0813eeu) { target=s->pc; goto dispatch; }
goto P_0c0813ee;
P_0c0813ec: /* original 6043, guest PC 0x0c0813ec */
if(!s->budget--) { s->failed_pc=0x0c0813ecu; return 0; }
r[0]=r[4];
goto P_0c0813ee;
P_0c0813ee: /* original 61f3, guest PC 0x0c0813ee */
if(!s->budget--) { s->failed_pc=0x0c0813eeu; return 0; }
r[1]=r[15];
goto P_0c0813f0;
P_0c0813f0: /* original 1f02, guest PC 0x0c0813f0 */
if(!s->budget--) { s->failed_pc=0x0c0813f0u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0813f2;
P_0c0813f2: /* original 7114, guest PC 0x0c0813f2 */
if(!s->budget--) { s->failed_pc=0x0c0813f2u; return 0; }
r[1]+=0x00000014u;
goto P_0c0813f4;
P_0c0813f4: /* original 66f3, guest PC 0x0c0813f4 */
if(!s->budget--) { s->failed_pc=0x0c0813f4u; return 0; }
r[6]=r[15];
goto P_0c0813f6;
P_0c0813f6: /* original 7060, guest PC 0x0c0813f6 */
if(!s->budget--) { s->failed_pc=0x0c0813f6u; return 0; }
r[0]+=0x00000060u;
goto P_0c0813f8;
P_0c0813f8: /* original 2100, guest PC 0x0c0813f8 */
if(!s->budget--) { s->failed_pc=0x0c0813f8u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0813fa;
P_0c0813fa: /* original e014, guest PC 0x0c0813fa */
if(!s->budget--) { s->failed_pc=0x0c0813fau; return 0; }
r[0]=0x00000014u;
goto P_0c0813fc;
P_0c0813fc: /* original 05fc, guest PC 0x0c0813fc */
if(!s->budget--) { s->failed_pc=0x0c0813fcu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0813fe;
P_0c0813fe: /* original b318, guest PC 0x0c0813fe */
if(!s->budget--) { s->failed_pc=0x0c0813feu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081402u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081402u) { target=s->pc; goto dispatch; }
goto P_0c081402;
P_0c081400: /* original 64e3, guest PC 0x0c081400 */
if(!s->budget--) { s->failed_pc=0x0c081400u; return 0; }
r[4]=r[14];
goto P_0c081402;
P_0c081402: /* original 54f2, guest PC 0x0c081402 */
if(!s->budget--) { s->failed_pc=0x0c081402u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c081404;
P_0c081404: /* original 66f3, guest PC 0x0c081404 */
if(!s->budget--) { s->failed_pc=0x0c081404u; return 0; }
r[6]=r[15];
goto P_0c081406;
P_0c081406: /* original 5af1, guest PC 0x0c081406 */
if(!s->budget--) { s->failed_pc=0x0c081406u; return 0; }
r[10]=read(ram,r[15]+4,4);
goto P_0c081408;
P_0c081408: /* original 4408, guest PC 0x0c081408 */
if(!s->budget--) { s->failed_pc=0x0c081408u; return 0; }
r[4]<<=2;
goto P_0c08140a;
P_0c08140a: /* original 4408, guest PC 0x0c08140a */
if(!s->budget--) { s->failed_pc=0x0c08140au; return 0; }
r[4]<<=2;
goto P_0c08140c;
P_0c08140c: /* original 3a48, guest PC 0x0c08140c */
if(!s->budget--) { s->failed_pc=0x0c08140cu; return 0; }
r[10]-=r[4];
goto P_0c08140e;
P_0c08140e: /* original 7a40, guest PC 0x0c08140e */
if(!s->budget--) { s->failed_pc=0x0c08140eu; return 0; }
r[10]+=0x00000040u;
goto P_0c081410;
P_0c081410: /* original 65a3, guest PC 0x0c081410 */
if(!s->budget--) { s->failed_pc=0x0c081410u; return 0; }
r[5]=r[10];
goto P_0c081412;
P_0c081412: /* original b30e, guest PC 0x0c081412 */
if(!s->budget--) { s->failed_pc=0x0c081412u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081416u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081416u) { target=s->pc; goto dispatch; }
goto P_0c081416;
P_0c081414: /* original 64e3, guest PC 0x0c081414 */
if(!s->budget--) { s->failed_pc=0x0c081414u; return 0; }
r[4]=r[14];
goto P_0c081416;
P_0c081416: /* original d22d, guest PC 0x0c081416 */
if(!s->budget--) { s->failed_pc=0x0c081416u; return 0; }
r[2]=read(ram,0x0c0814ccu,4);
goto P_0c081418;
P_0c081418: /* original 22d8, guest PC 0x0c081418 */
if(!s->budget--) { s->failed_pc=0x0c081418u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c08141a;
P_0c08141a: /* original 8d14, guest PC 0x0c08141a */
if(!s->budget--) { s->failed_pc=0x0c08141au; return 0; }
cond=r[17]&1u;
r[10]=0x00000001u;
if(cond) { goto P_0c081446; }
goto P_0c08141e;
P_0c08141c: /* original ea01, guest PC 0x0c08141c */
if(!s->budget--) { s->failed_pc=0x0c08141cu; return 0; }
r[10]=0x00000001u;
goto P_0c08141e;
P_0c08141e: /* original d12c, guest PC 0x0c08141e */
if(!s->budget--) { s->failed_pc=0x0c08141eu; return 0; }
r[1]=read(ram,0x0c0814d0u,4);
goto P_0c081420;
P_0c081420: /* original d32c, guest PC 0x0c081420 */
if(!s->budget--) { s->failed_pc=0x0c081420u; return 0; }
r[3]=read(ram,0x0c0814d4u,4);
goto P_0c081422;
P_0c081422: /* original 6412, guest PC 0x0c081422 */
if(!s->budget--) { s->failed_pc=0x0c081422u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c081424;
P_0c081424: /* original 6532, guest PC 0x0c081424 */
if(!s->budget--) { s->failed_pc=0x0c081424u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c081426;
P_0c081426: /* original 6442, guest PC 0x0c081426 */
if(!s->budget--) { s->failed_pc=0x0c081426u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c081428;
P_0c081428: /* original 6552, guest PC 0x0c081428 */
if(!s->budget--) { s->failed_pc=0x0c081428u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c08142a;
P_0c08142a: /* original 6643, guest PC 0x0c08142a */
if(!s->budget--) { s->failed_pc=0x0c08142au; return 0; }
r[6]=r[4];
goto P_0c08142c;
P_0c08142c: /* original 265b, guest PC 0x0c08142c */
if(!s->budget--) { s->failed_pc=0x0c08142cu; return 0; }
r[6]|=r[5];
goto P_0c08142e;
P_0c08142e: /* original 26a8, guest PC 0x0c08142e */
if(!s->budget--) { s->failed_pc=0x0c08142eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[10])==0)!=0);
goto P_0c081430;
P_0c081430: /* original 8909, guest PC 0x0c081430 */
if(!s->budget--) { s->failed_pc=0x0c081430u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081446; }
goto P_0c081432;
P_0c081432: /* original d029, guest PC 0x0c081432 */
if(!s->budget--) { s->failed_pc=0x0c081432u; return 0; }
r[0]=read(ram,0x0c0814d8u,4);
goto P_0c081434;
P_0c081434: /* original 24a8, guest PC 0x0c081434 */
if(!s->budget--) { s->failed_pc=0x0c081434u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[10])==0)!=0);
goto P_0c081436;
P_0c081436: /* original 8d02, guest PC 0x0c081436 */
if(!s->budget--) { s->failed_pc=0x0c081436u; return 0; }
cond=r[17]&1u;
r[13]&=r[0];
if(cond) { goto P_0c08143e; }
goto P_0c08143a;
P_0c081438: /* original 2d09, guest PC 0x0c081438 */
if(!s->budget--) { s->failed_pc=0x0c081438u; return 0; }
r[13]&=r[0];
goto P_0c08143a;
P_0c08143a: /* original d128, guest PC 0x0c08143a */
if(!s->budget--) { s->failed_pc=0x0c08143au; return 0; }
r[1]=read(ram,0x0c0814dcu,4);
goto P_0c08143c;
P_0c08143c: /* original 2d1b, guest PC 0x0c08143c */
if(!s->budget--) { s->failed_pc=0x0c08143cu; return 0; }
r[13]|=r[1];
goto P_0c08143e;
P_0c08143e: /* original 25a8, guest PC 0x0c08143e */
if(!s->budget--) { s->failed_pc=0x0c08143eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[10])==0)!=0);
goto P_0c081440;
P_0c081440: /* original 8901, guest PC 0x0c081440 */
if(!s->budget--) { s->failed_pc=0x0c081440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081446; }
goto P_0c081442;
P_0c081442: /* original d227, guest PC 0x0c081442 */
if(!s->budget--) { s->failed_pc=0x0c081442u; return 0; }
r[2]=read(ram,0x0c0814e0u,4);
goto P_0c081444;
P_0c081444: /* original 2d2b, guest PC 0x0c081444 */
if(!s->budget--) { s->failed_pc=0x0c081444u; return 0; }
r[13]|=r[2];
goto P_0c081446;
P_0c081446: /* original d327, guest PC 0x0c081446 */
if(!s->budget--) { s->failed_pc=0x0c081446u; return 0; }
r[3]=read(ram,0x0c0814e4u,4);
goto P_0c081448;
P_0c081448: /* original 23d8, guest PC 0x0c081448 */
if(!s->budget--) { s->failed_pc=0x0c081448u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c08144a;
P_0c08144a: /* original 8929, guest PC 0x0c08144a */
if(!s->budget--) { s->failed_pc=0x0c08144au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0814a0; }
goto P_0c08144c;
P_0c08144c: /* original d321, guest PC 0x0c08144c */
if(!s->budget--) { s->failed_pc=0x0c08144cu; return 0; }
r[3]=read(ram,0x0c0814d4u,4);
goto P_0c08144e;
P_0c08144e: /* original d120, guest PC 0x0c08144e */
if(!s->budget--) { s->failed_pc=0x0c08144eu; return 0; }
r[1]=read(ram,0x0c0814d0u,4);
goto P_0c081450;
P_0c081450: /* original 6532, guest PC 0x0c081450 */
if(!s->budget--) { s->failed_pc=0x0c081450u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c081452;
P_0c081452: /* original 6412, guest PC 0x0c081452 */
if(!s->budget--) { s->failed_pc=0x0c081452u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c081454;
P_0c081454: /* original 6252, guest PC 0x0c081454 */
if(!s->budget--) { s->failed_pc=0x0c081454u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c081456;
P_0c081456: /* original 6442, guest PC 0x0c081456 */
if(!s->budget--) { s->failed_pc=0x0c081456u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c081458;
P_0c081458: /* original 6523, guest PC 0x0c081458 */
if(!s->budget--) { s->failed_pc=0x0c081458u; return 0; }
r[5]=r[2];
goto P_0c08145a;
P_0c08145a: /* original 1f21, guest PC 0x0c08145a */
if(!s->budget--) { s->failed_pc=0x0c08145au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c08145c;
P_0c08145c: /* original 254b, guest PC 0x0c08145c */
if(!s->budget--) { s->failed_pc=0x0c08145cu; return 0; }
r[5]|=r[4];
goto P_0c08145e;
P_0c08145e: /* original 25a8, guest PC 0x0c08145e */
if(!s->budget--) { s->failed_pc=0x0c08145eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[10])==0)!=0);
goto P_0c081460;
P_0c081460: /* original 891e, guest PC 0x0c081460 */
if(!s->budget--) { s->failed_pc=0x0c081460u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0814a0; }
goto P_0c081462;
P_0c081462: /* original d021, guest PC 0x0c081462 */
if(!s->budget--) { s->failed_pc=0x0c081462u; return 0; }
r[0]=read(ram,0x0c0814e8u,4);
goto P_0c081464;
P_0c081464: /* original 24a8, guest PC 0x0c081464 */
if(!s->budget--) { s->failed_pc=0x0c081464u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[10])==0)!=0);
goto P_0c081466;
P_0c081466: /* original 8d0c, guest PC 0x0c081466 */
if(!s->budget--) { s->failed_pc=0x0c081466u; return 0; }
cond=r[17]&1u;
r[13]&=r[0];
if(cond) { goto P_0c081482; }
goto P_0c08146a;
P_0c081468: /* original 2d09, guest PC 0x0c081468 */
if(!s->budget--) { s->failed_pc=0x0c081468u; return 0; }
r[13]&=r[0];
goto P_0c08146a;
P_0c08146a: /* original e5a6, guest PC 0x0c08146a */
if(!s->budget--) { s->failed_pc=0x0c08146au; return 0; }
r[5]=0xffffffa6u;
goto P_0c08146c;
P_0c08146c: /* original 66f3, guest PC 0x0c08146c */
if(!s->budget--) { s->failed_pc=0x0c08146cu; return 0; }
r[6]=r[15];
goto P_0c08146e;
P_0c08146e: /* original b2e0, guest PC 0x0c08146e */
if(!s->budget--) { s->failed_pc=0x0c08146eu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081472u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081472u) { target=s->pc; goto dispatch; }
goto P_0c081472;
P_0c081470: /* original 64e3, guest PC 0x0c081470 */
if(!s->budget--) { s->failed_pc=0x0c081470u; return 0; }
r[4]=r[14];
goto P_0c081472;
P_0c081472: /* original 9022, guest PC 0x0c081472 */
if(!s->budget--) { s->failed_pc=0x0c081472u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0814bau,2);
goto P_0c081474;
P_0c081474: /* original 04ce, guest PC 0x0c081474 */
if(!s->budget--) { s->failed_pc=0x0c081474u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c081476;
P_0c081476: /* original 2448, guest PC 0x0c081476 */
if(!s->budget--) { s->failed_pc=0x0c081476u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c081478;
P_0c081478: /* original 8903, guest PC 0x0c081478 */
if(!s->budget--) { s->failed_pc=0x0c081478u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081482; }
goto P_0c08147a;
P_0c08147a: /* original e59a, guest PC 0x0c08147a */
if(!s->budget--) { s->failed_pc=0x0c08147au; return 0; }
r[5]=0xffffff9au;
goto P_0c08147c;
P_0c08147c: /* original 66f3, guest PC 0x0c08147c */
if(!s->budget--) { s->failed_pc=0x0c08147cu; return 0; }
r[6]=r[15];
goto P_0c08147e;
P_0c08147e: /* original b2d8, guest PC 0x0c08147e */
if(!s->budget--) { s->failed_pc=0x0c08147eu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081482u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081482u) { target=s->pc; goto dispatch; }
goto P_0c081482;
P_0c081480: /* original 64e3, guest PC 0x0c081480 */
if(!s->budget--) { s->failed_pc=0x0c081480u; return 0; }
r[4]=r[14];
goto P_0c081482;
P_0c081482: /* original 53f1, guest PC 0x0c081482 */
if(!s->budget--) { s->failed_pc=0x0c081482u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c081484;
P_0c081484: /* original 2a38, guest PC 0x0c081484 */
if(!s->budget--) { s->failed_pc=0x0c081484u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c081486;
P_0c081486: /* original 890b, guest PC 0x0c081486 */
if(!s->budget--) { s->failed_pc=0x0c081486u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0814a0; }
goto P_0c081488;
P_0c081488: /* original e5ae, guest PC 0x0c081488 */
if(!s->budget--) { s->failed_pc=0x0c081488u; return 0; }
r[5]=0xffffffaeu;
goto P_0c08148a;
P_0c08148a: /* original 66f3, guest PC 0x0c08148a */
if(!s->budget--) { s->failed_pc=0x0c08148au; return 0; }
r[6]=r[15];
goto P_0c08148c;
P_0c08148c: /* original b2d1, guest PC 0x0c08148c */
if(!s->budget--) { s->failed_pc=0x0c08148cu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081490u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081490u) { target=s->pc; goto dispatch; }
goto P_0c081490;
P_0c08148e: /* original 64e3, guest PC 0x0c08148e */
if(!s->budget--) { s->failed_pc=0x0c08148eu; return 0; }
r[4]=r[14];
goto P_0c081490;
P_0c081490: /* original 9013, guest PC 0x0c081490 */
if(!s->budget--) { s->failed_pc=0x0c081490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0814bau,2);
goto P_0c081492;
P_0c081492: /* original 04ce, guest PC 0x0c081492 */
if(!s->budget--) { s->failed_pc=0x0c081492u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c081494;
P_0c081494: /* original 2448, guest PC 0x0c081494 */
if(!s->budget--) { s->failed_pc=0x0c081494u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c081496;
P_0c081496: /* original 8903, guest PC 0x0c081496 */
if(!s->budget--) { s->failed_pc=0x0c081496u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0814a0; }
goto P_0c081498;
P_0c081498: /* original e592, guest PC 0x0c081498 */
if(!s->budget--) { s->failed_pc=0x0c081498u; return 0; }
r[5]=0xffffff92u;
goto P_0c08149a;
P_0c08149a: /* original 66f3, guest PC 0x0c08149a */
if(!s->budget--) { s->failed_pc=0x0c08149au; return 0; }
r[6]=r[15];
goto P_0c08149c;
P_0c08149c: /* original b2c9, guest PC 0x0c08149c */
if(!s->budget--) { s->failed_pc=0x0c08149cu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0814a0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0814a0u) { target=s->pc; goto dispatch; }
goto P_0c0814a0;
P_0c08149e: /* original 64e3, guest PC 0x0c08149e */
if(!s->budget--) { s->failed_pc=0x0c08149eu; return 0; }
r[4]=r[14];
goto P_0c0814a0;
P_0c0814a0: /* original d312, guest PC 0x0c0814a0 */
if(!s->budget--) { s->failed_pc=0x0c0814a0u; return 0; }
r[3]=read(ram,0x0c0814ecu,4);
goto P_0c0814a2;
P_0c0814a2: /* original 23d8, guest PC 0x0c0814a2 */
if(!s->budget--) { s->failed_pc=0x0c0814a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0814a4;
P_0c0814a4: /* original 8939, guest PC 0x0c0814a4 */
if(!s->budget--) { s->failed_pc=0x0c0814a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08151a; }
goto P_0c0814a6;
P_0c0814a6: /* original e019, guest PC 0x0c0814a6 */
if(!s->budget--) { s->failed_pc=0x0c0814a6u; return 0; }
r[0]=0x00000019u;
goto P_0c0814a8;
P_0c0814a8: /* original 9a08, guest PC 0x0c0814a8 */
if(!s->budget--) { s->failed_pc=0x0c0814a8u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0814bcu,2);
goto P_0c0814aa;
P_0c0814aa: /* original 04cc, guest PC 0x0c0814aa */
if(!s->budget--) { s->failed_pc=0x0c0814aau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0814ac;
P_0c0814ac: /* original e029, guest PC 0x0c0814ac */
if(!s->budget--) { s->failed_pc=0x0c0814acu; return 0; }
r[0]=0x00000029u;
goto P_0c0814ae;
P_0c0814ae: /* original d310, guest PC 0x0c0814ae */
if(!s->budget--) { s->failed_pc=0x0c0814aeu; return 0; }
r[3]=read(ram,0x0c0814f0u,4);
goto P_0c0814b0;
P_0c0814b0: /* original 05cc, guest PC 0x0c0814b0 */
if(!s->budget--) { s->failed_pc=0x0c0814b0u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0814b2;
P_0c0814b2: /* original 624e, guest PC 0x0c0814b2 */
if(!s->budget--) { s->failed_pc=0x0c0814b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0814b4;
P_0c0814b4: /* original a01e, guest PC 0x0c0814b4 */
if(!s->budget--) { s->failed_pc=0x0c0814b4u; return 0; }
r[13]&=r[3];
goto P_0c0814f4;
P_0c0814b6: /* original 2d39, guest PC 0x0c0814b6 */
if(!s->budget--) { s->failed_pc=0x0c0814b6u; return 0; }
r[13]&=r[3];
if(!vf3_matrix_family(0x0c0814b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0814b8u; return 0; } return 1;
P_0c0814f4: /* original 2228, guest PC 0x0c0814f4 */
if(!s->budget--) { s->failed_pc=0x0c0814f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0814f6;
P_0c0814f6: /* original 8f05, guest PC 0x0c0814f6 */
if(!s->budget--) { s->failed_pc=0x0c0814f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081504; }
goto P_0c0814fa;
P_0c0814f8: /* original 0009, guest PC 0x0c0814f8 */
if(!s->budget--) { s->failed_pc=0x0c0814f8u; return 0; }
goto P_0c0814fa;
P_0c0814fa: /* original 605e, guest PC 0x0c0814fa */
if(!s->budget--) { s->failed_pc=0x0c0814fau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0814fc;
P_0c0814fc: /* original 8802, guest PC 0x0c0814fc */
if(!s->budget--) { s->failed_pc=0x0c0814fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0814fe;
P_0c0814fe: /* original 8b08, guest PC 0x0c0814fe */
if(!s->budget--) { s->failed_pc=0x0c0814feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081512; }
goto P_0c081500;
P_0c081500: /* original a00b, guest PC 0x0c081500 */
if(!s->budget--) { s->failed_pc=0x0c081500u; return 0; }
goto P_0c08151a;
P_0c081502: /* original 0009, guest PC 0x0c081502 */
if(!s->budget--) { s->failed_pc=0x0c081502u; return 0; }
goto P_0c081504;
P_0c081504: /* original 604e, guest PC 0x0c081504 */
if(!s->budget--) { s->failed_pc=0x0c081504u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c081506;
P_0c081506: /* original 8801, guest PC 0x0c081506 */
if(!s->budget--) { s->failed_pc=0x0c081506u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081508;
P_0c081508: /* original 8b07, guest PC 0x0c081508 */
if(!s->budget--) { s->failed_pc=0x0c081508u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08151a; }
goto P_0c08150a;
P_0c08150a: /* original 605e, guest PC 0x0c08150a */
if(!s->budget--) { s->failed_pc=0x0c08150au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c08150c;
P_0c08150c: /* original 9a7a, guest PC 0x0c08150c */
if(!s->budget--) { s->failed_pc=0x0c08150cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081604u,2);
goto P_0c08150e;
P_0c08150e: /* original 8801, guest PC 0x0c08150e */
if(!s->budget--) { s->failed_pc=0x0c08150eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081510;
P_0c081510: /* original 8903, guest PC 0x0c081510 */
if(!s->budget--) { s->failed_pc=0x0c081510u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08151a; }
goto P_0c081512;
P_0c081512: /* original 65a3, guest PC 0x0c081512 */
if(!s->budget--) { s->failed_pc=0x0c081512u; return 0; }
r[5]=r[10];
goto P_0c081514;
P_0c081514: /* original 66f3, guest PC 0x0c081514 */
if(!s->budget--) { s->failed_pc=0x0c081514u; return 0; }
r[6]=r[15];
goto P_0c081516;
P_0c081516: /* original b28c, guest PC 0x0c081516 */
if(!s->budget--) { s->failed_pc=0x0c081516u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08151au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08151au) { target=s->pc; goto dispatch; }
goto P_0c08151a;
P_0c081518: /* original 64e3, guest PC 0x0c081518 */
if(!s->budget--) { s->failed_pc=0x0c081518u; return 0; }
r[4]=r[14];
goto P_0c08151a;
P_0c08151a: /* original d33c, guest PC 0x0c08151a */
if(!s->budget--) { s->failed_pc=0x0c08151au; return 0; }
r[3]=read(ram,0x0c08160cu,4);
goto P_0c08151c;
P_0c08151c: /* original 23d8, guest PC 0x0c08151c */
if(!s->budget--) { s->failed_pc=0x0c08151cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c08151e;
P_0c08151e: /* original 890d, guest PC 0x0c08151e */
if(!s->budget--) { s->failed_pc=0x0c08151eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08153c; }
goto P_0c081520;
P_0c081520: /* original d13b, guest PC 0x0c081520 */
if(!s->budget--) { s->failed_pc=0x0c081520u; return 0; }
r[1]=read(ram,0x0c081610u,4);
goto P_0c081522;
P_0c081522: /* original e202, guest PC 0x0c081522 */
if(!s->budget--) { s->failed_pc=0x0c081522u; return 0; }
r[2]=0x00000002u;
goto P_0c081524;
P_0c081524: /* original 9a6f, guest PC 0x0c081524 */
if(!s->budget--) { s->failed_pc=0x0c081524u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081606u,2);
goto P_0c081526;
P_0c081526: /* original 6412, guest PC 0x0c081526 */
if(!s->budget--) { s->failed_pc=0x0c081526u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c081528;
P_0c081528: /* original d33a, guest PC 0x0c081528 */
if(!s->budget--) { s->failed_pc=0x0c081528u; return 0; }
r[3]=read(ram,0x0c081614u,4);
goto P_0c08152a;
P_0c08152a: /* original 6442, guest PC 0x0c08152a */
if(!s->budget--) { s->failed_pc=0x0c08152au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c08152c;
P_0c08152c: /* original 2428, guest PC 0x0c08152c */
if(!s->budget--) { s->failed_pc=0x0c08152cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08152e;
P_0c08152e: /* original 8d01, guest PC 0x0c08152e */
if(!s->budget--) { s->failed_pc=0x0c08152eu; return 0; }
cond=r[17]&1u;
r[13]&=r[3];
if(cond) { goto P_0c081534; }
goto P_0c081532;
P_0c081530: /* original 2d39, guest PC 0x0c081530 */
if(!s->budget--) { s->failed_pc=0x0c081530u; return 0; }
r[13]&=r[3];
goto P_0c081532;
P_0c081532: /* original 9a69, guest PC 0x0c081532 */
if(!s->budget--) { s->failed_pc=0x0c081532u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081608u,2);
goto P_0c081534;
P_0c081534: /* original 65a3, guest PC 0x0c081534 */
if(!s->budget--) { s->failed_pc=0x0c081534u; return 0; }
r[5]=r[10];
goto P_0c081536;
P_0c081536: /* original 66f3, guest PC 0x0c081536 */
if(!s->budget--) { s->failed_pc=0x0c081536u; return 0; }
r[6]=r[15];
goto P_0c081538;
P_0c081538: /* original b27b, guest PC 0x0c081538 */
if(!s->budget--) { s->failed_pc=0x0c081538u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08153cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08153cu) { target=s->pc; goto dispatch; }
goto P_0c08153c;
P_0c08153a: /* original 64e3, guest PC 0x0c08153a */
if(!s->budget--) { s->failed_pc=0x0c08153au; return 0; }
r[4]=r[14];
goto P_0c08153c;
P_0c08153c: /* original d236, guest PC 0x0c08153c */
if(!s->budget--) { s->failed_pc=0x0c08153cu; return 0; }
r[2]=read(ram,0x0c081618u,4);
goto P_0c08153e;
P_0c08153e: /* original 22d8, guest PC 0x0c08153e */
if(!s->budget--) { s->failed_pc=0x0c08153eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c081540;
P_0c081540: /* original 8f02, guest PC 0x0c081540 */
if(!s->budget--) { s->failed_pc=0x0c081540u; return 0; }
cond=r[17]&1u;
r[10]=0x0000000au;
if(!cond) { goto P_0c081548; }
goto P_0c081544;
P_0c081542: /* original ea0a, guest PC 0x0c081542 */
if(!s->budget--) { s->failed_pc=0x0c081542u; return 0; }
r[10]=0x0000000au;
goto P_0c081544;
P_0c081544: /* original a087, guest PC 0x0c081544 */
if(!s->budget--) { s->failed_pc=0x0c081544u; return 0; }
goto P_0c081656;
P_0c081546: /* original 0009, guest PC 0x0c081546 */
if(!s->budget--) { s->failed_pc=0x0c081546u; return 0; }
goto P_0c081548;
P_0c081548: /* original 905f, guest PC 0x0c081548 */
if(!s->budget--) { s->failed_pc=0x0c081548u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08160au,2);
goto P_0c08154a;
P_0c08154a: /* original 66f3, guest PC 0x0c08154a */
if(!s->budget--) { s->failed_pc=0x0c08154au; return 0; }
r[6]=r[15];
goto P_0c08154c;
P_0c08154c: /* original e51f, guest PC 0x0c08154c */
if(!s->budget--) { s->failed_pc=0x0c08154cu; return 0; }
r[5]=0x0000001fu;
goto P_0c08154e;
P_0c08154e: /* original 01ce, guest PC 0x0c08154e */
if(!s->budget--) { s->failed_pc=0x0c08154eu; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c081550;
P_0c081550: /* original e029, guest PC 0x0c081550 */
if(!s->budget--) { s->failed_pc=0x0c081550u; return 0; }
r[0]=0x00000029u;
goto P_0c081552;
P_0c081552: /* original 1f11, guest PC 0x0c081552 */
if(!s->budget--) { s->failed_pc=0x0c081552u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c081554;
P_0c081554: /* original 00cc, guest PC 0x0c081554 */
if(!s->budget--) { s->failed_pc=0x0c081554u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c081556;
P_0c081556: /* original 80f8, guest PC 0x0c081556 */
if(!s->budget--) { s->failed_pc=0x0c081556u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c081558;
P_0c081558: /* original e02a, guest PC 0x0c081558 */
if(!s->budget--) { s->failed_pc=0x0c081558u; return 0; }
r[0]=0x0000002au;
goto P_0c08155a;
P_0c08155a: /* original 03cc, guest PC 0x0c08155a */
if(!s->budget--) { s->failed_pc=0x0c08155au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08155c;
P_0c08155c: /* original e018, guest PC 0x0c08155c */
if(!s->budget--) { s->failed_pc=0x0c08155cu; return 0; }
r[0]=0x00000018u;
goto P_0c08155e;
P_0c08155e: /* original 0f34, guest PC 0x0c08155e */
if(!s->budget--) { s->failed_pc=0x0c08155eu; return 0; }
write(ram,r[15]+r[0],r[3],1);
goto P_0c081560;
P_0c081560: /* original b267, guest PC 0x0c081560 */
if(!s->budget--) { s->failed_pc=0x0c081560u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081564u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081564u) { target=s->pc; goto dispatch; }
goto P_0c081564;
P_0c081562: /* original 64e3, guest PC 0x0c081562 */
if(!s->budget--) { s->failed_pc=0x0c081562u; return 0; }
r[4]=r[14];
goto P_0c081564;
P_0c081564: /* original e53f, guest PC 0x0c081564 */
if(!s->budget--) { s->failed_pc=0x0c081564u; return 0; }
r[5]=0x0000003fu;
goto P_0c081566;
P_0c081566: /* original 66f3, guest PC 0x0c081566 */
if(!s->budget--) { s->failed_pc=0x0c081566u; return 0; }
r[6]=r[15];
goto P_0c081568;
P_0c081568: /* original b263, guest PC 0x0c081568 */
if(!s->budget--) { s->failed_pc=0x0c081568u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08156cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08156cu) { target=s->pc; goto dispatch; }
goto P_0c08156c;
P_0c08156a: /* original 64e3, guest PC 0x0c08156a */
if(!s->budget--) { s->failed_pc=0x0c08156au; return 0; }
r[4]=r[14];
goto P_0c08156c;
P_0c08156c: /* original e55f, guest PC 0x0c08156c */
if(!s->budget--) { s->failed_pc=0x0c08156cu; return 0; }
r[5]=0x0000005fu;
goto P_0c08156e;
P_0c08156e: /* original 66f3, guest PC 0x0c08156e */
if(!s->budget--) { s->failed_pc=0x0c08156eu; return 0; }
r[6]=r[15];
goto P_0c081570;
P_0c081570: /* original b25f, guest PC 0x0c081570 */
if(!s->budget--) { s->failed_pc=0x0c081570u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081574u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081574u) { target=s->pc; goto dispatch; }
goto P_0c081574;
P_0c081572: /* original 64e3, guest PC 0x0c081572 */
if(!s->budget--) { s->failed_pc=0x0c081572u; return 0; }
r[4]=r[14];
goto P_0c081574;
P_0c081574: /* original e57f, guest PC 0x0c081574 */
if(!s->budget--) { s->failed_pc=0x0c081574u; return 0; }
r[5]=0x0000007fu;
goto P_0c081576;
P_0c081576: /* original 66f3, guest PC 0x0c081576 */
if(!s->budget--) { s->failed_pc=0x0c081576u; return 0; }
r[6]=r[15];
goto P_0c081578;
P_0c081578: /* original b25b, guest PC 0x0c081578 */
if(!s->budget--) { s->failed_pc=0x0c081578u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08157cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08157cu) { target=s->pc; goto dispatch; }
goto P_0c08157c;
P_0c08157a: /* original 64e3, guest PC 0x0c08157a */
if(!s->budget--) { s->failed_pc=0x0c08157au; return 0; }
r[4]=r[14];
goto P_0c08157c;
P_0c08157c: /* original e018, guest PC 0x0c08157c */
if(!s->budget--) { s->failed_pc=0x0c08157cu; return 0; }
r[0]=0x00000018u;
goto P_0c08157e;
P_0c08157e: /* original 03fc, guest PC 0x0c08157e */
if(!s->budget--) { s->failed_pc=0x0c08157eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c081580;
P_0c081580: /* original 1f35, guest PC 0x0c081580 */
if(!s->budget--) { s->failed_pc=0x0c081580u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c081582;
P_0c081582: /* original 84f8, guest PC 0x0c081582 */
if(!s->budget--) { s->failed_pc=0x0c081582u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c081584;
P_0c081584: /* original 8802, guest PC 0x0c081584 */
if(!s->budget--) { s->failed_pc=0x0c081584u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c081586;
P_0c081586: /* original 8929, guest PC 0x0c081586 */
if(!s->budget--) { s->failed_pc=0x0c081586u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0815dc; }
goto P_0c081588;
P_0c081588: /* original 51f1, guest PC 0x0c081588 */
if(!s->budget--) { s->failed_pc=0x0c081588u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c08158a;
P_0c08158a: /* original 2118, guest PC 0x0c08158a */
if(!s->budget--) { s->failed_pc=0x0c08158au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c08158c;
P_0c08158c: /* original 8926, guest PC 0x0c08158c */
if(!s->budget--) { s->failed_pc=0x0c08158cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0815dc; }
goto P_0c08158e;
P_0c08158e: /* original 84f8, guest PC 0x0c08158e */
if(!s->budget--) { s->failed_pc=0x0c08158eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c081590;
P_0c081590: /* original 8801, guest PC 0x0c081590 */
if(!s->budget--) { s->failed_pc=0x0c081590u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081592;
P_0c081592: /* original 8902, guest PC 0x0c081592 */
if(!s->budget--) { s->failed_pc=0x0c081592u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08159a; }
goto P_0c081594;
P_0c081594: /* original 6033, guest PC 0x0c081594 */
if(!s->budget--) { s->failed_pc=0x0c081594u; return 0; }
r[0]=r[3];
goto P_0c081596;
P_0c081596: /* original 8801, guest PC 0x0c081596 */
if(!s->budget--) { s->failed_pc=0x0c081596u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081598;
P_0c081598: /* original 8b20, guest PC 0x0c081598 */
if(!s->budget--) { s->failed_pc=0x0c081598u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0815dc; }
goto P_0c08159a;
P_0c08159a: /* original 1fa6, guest PC 0x0c08159a */
if(!s->budget--) { s->failed_pc=0x0c08159au; return 0; }
write(ram,r[15]+24,r[10],4);
goto P_0c08159c;
P_0c08159c: /* original d31f, guest PC 0x0c08159c */
if(!s->budget--) { s->failed_pc=0x0c08159cu; return 0; }
r[3]=read(ram,0x0c08161cu,4);
goto P_0c08159e;
P_0c08159e: /* original 51f1, guest PC 0x0c08159e */
if(!s->budget--) { s->failed_pc=0x0c08159eu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0815a0;
P_0c0815a0: /* original 430b, guest PC 0x0c0815a0 */
if(!s->budget--) { s->failed_pc=0x0c0815a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0815a4u;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0815a4u) { target=s->pc; goto dispatch; }
goto P_0c0815a4;
P_0c0815a2: /* original 60a3, guest PC 0x0c0815a2 */
if(!s->budget--) { s->failed_pc=0x0c0815a2u; return 0; }
r[0]=r[10];
goto P_0c0815a4;
P_0c0815a4: /* original 6403, guest PC 0x0c0815a4 */
if(!s->budget--) { s->failed_pc=0x0c0815a4u; return 0; }
r[4]=r[0];
goto P_0c0815a6;
P_0c0815a6: /* original 2448, guest PC 0x0c0815a6 */
if(!s->budget--) { s->failed_pc=0x0c0815a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0815a8;
P_0c0815a8: /* original 8907, guest PC 0x0c0815a8 */
if(!s->budget--) { s->failed_pc=0x0c0815a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0815ba; }
goto P_0c0815aa;
P_0c0815aa: /* original e020, guest PC 0x0c0815aa */
if(!s->budget--) { s->failed_pc=0x0c0815aau; return 0; }
r[0]=0x00000020u;
goto P_0c0815ac;
P_0c0815ac: /* original 66f3, guest PC 0x0c0815ac */
if(!s->budget--) { s->failed_pc=0x0c0815acu; return 0; }
r[6]=r[15];
goto P_0c0815ae;
P_0c0815ae: /* original 7420, guest PC 0x0c0815ae */
if(!s->budget--) { s->failed_pc=0x0c0815aeu; return 0; }
r[4]+=0x00000020u;
goto P_0c0815b0;
P_0c0815b0: /* original 0f44, guest PC 0x0c0815b0 */
if(!s->budget--) { s->failed_pc=0x0c0815b0u; return 0; }
write(ram,r[15]+r[0],r[4],1);
goto P_0c0815b2;
P_0c0815b2: /* original e020, guest PC 0x0c0815b2 */
if(!s->budget--) { s->failed_pc=0x0c0815b2u; return 0; }
r[0]=0x00000020u;
goto P_0c0815b4;
P_0c0815b4: /* original 05fc, guest PC 0x0c0815b4 */
if(!s->budget--) { s->failed_pc=0x0c0815b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0815b6;
P_0c0815b6: /* original b23c, guest PC 0x0c0815b6 */
if(!s->budget--) { s->failed_pc=0x0c0815b6u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0815bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0815bau) { target=s->pc; goto dispatch; }
goto P_0c0815ba;
P_0c0815b8: /* original 64e3, guest PC 0x0c0815b8 */
if(!s->budget--) { s->failed_pc=0x0c0815b8u; return 0; }
r[4]=r[14];
goto P_0c0815ba;
P_0c0815ba: /* original d218, guest PC 0x0c0815ba */
if(!s->budget--) { s->failed_pc=0x0c0815bau; return 0; }
r[2]=read(ram,0x0c08161cu,4);
goto P_0c0815bc;
P_0c0815bc: /* original 51f1, guest PC 0x0c0815bc */
if(!s->budget--) { s->failed_pc=0x0c0815bcu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0815be;
P_0c0815be: /* original 420b, guest PC 0x0c0815be */
if(!s->budget--) { s->failed_pc=0x0c0815beu; return 0; }
target=r[2];
r[16]=code_base|0x0c0815c2u;
r[0]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0815c2u) { target=s->pc; goto dispatch; }
goto P_0c0815c2;
P_0c0815c0: /* original 50f6, guest PC 0x0c0815c0 */
if(!s->budget--) { s->failed_pc=0x0c0815c0u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0815c2;
P_0c0815c2: /* original 6403, guest PC 0x0c0815c2 */
if(!s->budget--) { s->failed_pc=0x0c0815c2u; return 0; }
r[4]=r[0];
goto P_0c0815c4;
P_0c0815c4: /* original 4408, guest PC 0x0c0815c4 */
if(!s->budget--) { s->failed_pc=0x0c0815c4u; return 0; }
r[4]<<=2;
goto P_0c0815c6;
P_0c0815c6: /* original 6303, guest PC 0x0c0815c6 */
if(!s->budget--) { s->failed_pc=0x0c0815c6u; return 0; }
r[3]=r[0];
goto P_0c0815c8;
P_0c0815c8: /* original 52f1, guest PC 0x0c0815c8 */
if(!s->budget--) { s->failed_pc=0x0c0815c8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0815ca;
P_0c0815ca: /* original 343c, guest PC 0x0c0815ca */
if(!s->budget--) { s->failed_pc=0x0c0815cau; return 0; }
r[4]+=r[3];
goto P_0c0815cc;
P_0c0815cc: /* original 66f3, guest PC 0x0c0815cc */
if(!s->budget--) { s->failed_pc=0x0c0815ccu; return 0; }
r[6]=r[15];
goto P_0c0815ce;
P_0c0815ce: /* original 4400, guest PC 0x0c0815ce */
if(!s->budget--) { s->failed_pc=0x0c0815ceu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0815d0;
P_0c0815d0: /* original e018, guest PC 0x0c0815d0 */
if(!s->budget--) { s->failed_pc=0x0c0815d0u; return 0; }
r[0]=0x00000018u;
goto P_0c0815d2;
P_0c0815d2: /* original 3248, guest PC 0x0c0815d2 */
if(!s->budget--) { s->failed_pc=0x0c0815d2u; return 0; }
r[2]-=r[4];
goto P_0c0815d4;
P_0c0815d4: /* original 6523, guest PC 0x0c0815d4 */
if(!s->budget--) { s->failed_pc=0x0c0815d4u; return 0; }
r[5]=r[2];
goto P_0c0815d6;
P_0c0815d6: /* original 0f24, guest PC 0x0c0815d6 */
if(!s->budget--) { s->failed_pc=0x0c0815d6u; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c0815d8;
P_0c0815d8: /* original b22b, guest PC 0x0c0815d8 */
if(!s->budget--) { s->failed_pc=0x0c0815d8u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0815dcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0815dcu) { target=s->pc; goto dispatch; }
goto P_0c0815dc;
P_0c0815da: /* original 64e3, guest PC 0x0c0815da */
if(!s->budget--) { s->failed_pc=0x0c0815dau; return 0; }
r[4]=r[14];
goto P_0c0815dc;
P_0c0815dc: /* original 84f8, guest PC 0x0c0815dc */
if(!s->budget--) { s->failed_pc=0x0c0815dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c0815de;
P_0c0815de: /* original 8801, guest PC 0x0c0815de */
if(!s->budget--) { s->failed_pc=0x0c0815deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0815e0;
P_0c0815e0: /* original 8937, guest PC 0x0c0815e0 */
if(!s->budget--) { s->failed_pc=0x0c0815e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081652; }
goto P_0c0815e2;
P_0c0815e2: /* original 52f1, guest PC 0x0c0815e2 */
if(!s->budget--) { s->failed_pc=0x0c0815e2u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0815e4;
P_0c0815e4: /* original 2228, guest PC 0x0c0815e4 */
if(!s->budget--) { s->failed_pc=0x0c0815e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0815e6;
P_0c0815e6: /* original 8934, guest PC 0x0c0815e6 */
if(!s->budget--) { s->failed_pc=0x0c0815e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081652; }
goto P_0c0815e8;
P_0c0815e8: /* original 84f8, guest PC 0x0c0815e8 */
if(!s->budget--) { s->failed_pc=0x0c0815e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c0815ea;
P_0c0815ea: /* original 8802, guest PC 0x0c0815ea */
if(!s->budget--) { s->failed_pc=0x0c0815eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0815ec;
P_0c0815ec: /* original 8902, guest PC 0x0c0815ec */
if(!s->budget--) { s->failed_pc=0x0c0815ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0815f4; }
goto P_0c0815ee;
P_0c0815ee: /* original 50f5, guest PC 0x0c0815ee */
if(!s->budget--) { s->failed_pc=0x0c0815eeu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c0815f0;
P_0c0815f0: /* original 8802, guest PC 0x0c0815f0 */
if(!s->budget--) { s->failed_pc=0x0c0815f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0815f2;
P_0c0815f2: /* original 8b2e, guest PC 0x0c0815f2 */
if(!s->budget--) { s->failed_pc=0x0c0815f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081652; }
goto P_0c0815f4;
P_0c0815f4: /* original d309, guest PC 0x0c0815f4 */
if(!s->budget--) { s->failed_pc=0x0c0815f4u; return 0; }
r[3]=read(ram,0x0c08161cu,4);
goto P_0c0815f6;
P_0c0815f6: /* original 64a3, guest PC 0x0c0815f6 */
if(!s->budget--) { s->failed_pc=0x0c0815f6u; return 0; }
r[4]=r[10];
goto P_0c0815f8;
P_0c0815f8: /* original 51f1, guest PC 0x0c0815f8 */
if(!s->budget--) { s->failed_pc=0x0c0815f8u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0815fa;
P_0c0815fa: /* original 430b, guest PC 0x0c0815fa */
if(!s->budget--) { s->failed_pc=0x0c0815fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0815feu;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0815feu) { target=s->pc; goto dispatch; }
goto P_0c0815fe;
P_0c0815fc: /* original 60a3, guest PC 0x0c0815fc */
if(!s->budget--) { s->failed_pc=0x0c0815fcu; return 0; }
r[0]=r[10];
goto P_0c0815fe;
P_0c0815fe: /* original 2008, guest PC 0x0c0815fe */
if(!s->budget--) { s->failed_pc=0x0c0815feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c081600;
P_0c081600: /* original a00e, guest PC 0x0c081600 */
if(!s->budget--) { s->failed_pc=0x0c081600u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c081620;
P_0c081602: /* original 1f02, guest PC 0x0c081602 */
if(!s->budget--) { s->failed_pc=0x0c081602u; return 0; }
write(ram,r[15]+8,r[0],4);
if(!vf3_matrix_family(0x0c081604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081604u; return 0; } return 1;
P_0c081620: /* original 8d09, guest PC 0x0c081620 */
if(!s->budget--) { s->failed_pc=0x0c081620u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081636; }
goto P_0c081624;
P_0c081622: /* original 0009, guest PC 0x0c081622 */
if(!s->budget--) { s->failed_pc=0x0c081622u; return 0; }
goto P_0c081624;
P_0c081624: /* original 61f3, guest PC 0x0c081624 */
if(!s->budget--) { s->failed_pc=0x0c081624u; return 0; }
r[1]=r[15];
goto P_0c081626;
P_0c081626: /* original 7114, guest PC 0x0c081626 */
if(!s->budget--) { s->failed_pc=0x0c081626u; return 0; }
r[1]+=0x00000014u;
goto P_0c081628;
P_0c081628: /* original 7060, guest PC 0x0c081628 */
if(!s->budget--) { s->failed_pc=0x0c081628u; return 0; }
r[0]+=0x00000060u;
goto P_0c08162a;
P_0c08162a: /* original 66f3, guest PC 0x0c08162a */
if(!s->budget--) { s->failed_pc=0x0c08162au; return 0; }
r[6]=r[15];
goto P_0c08162c;
P_0c08162c: /* original 2100, guest PC 0x0c08162c */
if(!s->budget--) { s->failed_pc=0x0c08162cu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c08162e;
P_0c08162e: /* original e014, guest PC 0x0c08162e */
if(!s->budget--) { s->failed_pc=0x0c08162eu; return 0; }
r[0]=0x00000014u;
goto P_0c081630;
P_0c081630: /* original 05fc, guest PC 0x0c081630 */
if(!s->budget--) { s->failed_pc=0x0c081630u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c081632;
P_0c081632: /* original b1fe, guest PC 0x0c081632 */
if(!s->budget--) { s->failed_pc=0x0c081632u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081636u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081636u) { target=s->pc; goto dispatch; }
goto P_0c081636;
P_0c081634: /* original 64e3, guest PC 0x0c081634 */
if(!s->budget--) { s->failed_pc=0x0c081634u; return 0; }
r[4]=r[14];
goto P_0c081636;
P_0c081636: /* original 54f2, guest PC 0x0c081636 */
if(!s->budget--) { s->failed_pc=0x0c081636u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c081638;
P_0c081638: /* original 66f3, guest PC 0x0c081638 */
if(!s->budget--) { s->failed_pc=0x0c081638u; return 0; }
r[6]=r[15];
goto P_0c08163a;
P_0c08163a: /* original 84f4, guest PC 0x0c08163a */
if(!s->budget--) { s->failed_pc=0x0c08163au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c08163c;
P_0c08163c: /* original 6343, guest PC 0x0c08163c */
if(!s->budget--) { s->failed_pc=0x0c08163cu; return 0; }
r[3]=r[4];
goto P_0c08163e;
P_0c08163e: /* original 4408, guest PC 0x0c08163e */
if(!s->budget--) { s->failed_pc=0x0c08163eu; return 0; }
r[4]<<=2;
goto P_0c081640;
P_0c081640: /* original 343c, guest PC 0x0c081640 */
if(!s->budget--) { s->failed_pc=0x0c081640u; return 0; }
r[4]+=r[3];
goto P_0c081642;
P_0c081642: /* original 4400, guest PC 0x0c081642 */
if(!s->budget--) { s->failed_pc=0x0c081642u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081644;
P_0c081644: /* original 3048, guest PC 0x0c081644 */
if(!s->budget--) { s->failed_pc=0x0c081644u; return 0; }
r[0]-=r[4];
goto P_0c081646;
P_0c081646: /* original 7040, guest PC 0x0c081646 */
if(!s->budget--) { s->failed_pc=0x0c081646u; return 0; }
r[0]+=0x00000040u;
goto P_0c081648;
P_0c081648: /* original 80f4, guest PC 0x0c081648 */
if(!s->budget--) { s->failed_pc=0x0c081648u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c08164a;
P_0c08164a: /* original 84f4, guest PC 0x0c08164a */
if(!s->budget--) { s->failed_pc=0x0c08164au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c08164c;
P_0c08164c: /* original 6503, guest PC 0x0c08164c */
if(!s->budget--) { s->failed_pc=0x0c08164cu; return 0; }
r[5]=r[0];
goto P_0c08164e;
P_0c08164e: /* original b1f0, guest PC 0x0c08164e */
if(!s->budget--) { s->failed_pc=0x0c08164eu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081652u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081652u) { target=s->pc; goto dispatch; }
goto P_0c081652;
P_0c081650: /* original 64e3, guest PC 0x0c081650 */
if(!s->budget--) { s->failed_pc=0x0c081650u; return 0; }
r[4]=r[14];
goto P_0c081652;
P_0c081652: /* original d23e, guest PC 0x0c081652 */
if(!s->budget--) { s->failed_pc=0x0c081652u; return 0; }
r[2]=read(ram,0x0c08174cu,4);
goto P_0c081654;
P_0c081654: /* original 2d29, guest PC 0x0c081654 */
if(!s->budget--) { s->failed_pc=0x0c081654u; return 0; }
r[13]&=r[2];
goto P_0c081656;
P_0c081656: /* original d43e, guest PC 0x0c081656 */
if(!s->budget--) { s->failed_pc=0x0c081656u; return 0; }
r[4]=read(ram,0x0c081750u,4);
goto P_0c081658;
P_0c081658: /* original d33e, guest PC 0x0c081658 */
if(!s->budget--) { s->failed_pc=0x0c081658u; return 0; }
r[3]=read(ram,0x0c081754u,4);
goto P_0c08165a;
P_0c08165a: /* original 6542, guest PC 0x0c08165a */
if(!s->budget--) { s->failed_pc=0x0c08165au; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c08165c;
P_0c08165c: /* original 2538, guest PC 0x0c08165c */
if(!s->budget--) { s->failed_pc=0x0c08165cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c08165e;
P_0c08165e: /* original 8901, guest PC 0x0c08165e */
if(!s->budget--) { s->failed_pc=0x0c08165eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081664; }
goto P_0c081660;
P_0c081660: /* original a167, guest PC 0x0c081660 */
if(!s->budget--) { s->failed_pc=0x0c081660u; return 0; }
goto P_0c081932;
P_0c081662: /* original 0009, guest PC 0x0c081662 */
if(!s->budget--) { s->failed_pc=0x0c081662u; return 0; }
goto P_0c081664;
P_0c081664: /* original d13c, guest PC 0x0c081664 */
if(!s->budget--) { s->failed_pc=0x0c081664u; return 0; }
r[1]=read(ram,0x0c081758u,4);
goto P_0c081666;
P_0c081666: /* original 5441, guest PC 0x0c081666 */
if(!s->budget--) { s->failed_pc=0x0c081666u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c081668;
P_0c081668: /* original 2418, guest PC 0x0c081668 */
if(!s->budget--) { s->failed_pc=0x0c081668u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c08166a;
P_0c08166a: /* original 8b01, guest PC 0x0c08166a */
if(!s->budget--) { s->failed_pc=0x0c08166au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081670; }
goto P_0c08166c;
P_0c08166c: /* original a161, guest PC 0x0c08166c */
if(!s->budget--) { s->failed_pc=0x0c08166cu; return 0; }
goto P_0c081932;
P_0c08166e: /* original 0009, guest PC 0x0c08166e */
if(!s->budget--) { s->failed_pc=0x0c08166eu; return 0; }
goto P_0c081670;
P_0c081670: /* original 9268, guest PC 0x0c081670 */
if(!s->budget--) { s->failed_pc=0x0c081670u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081744u,2);
goto P_0c081672;
P_0c081672: /* original 50f3, guest PC 0x0c081672 */
if(!s->budget--) { s->failed_pc=0x0c081672u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c081674;
P_0c081674: /* original 022d, guest PC 0x0c081674 */
if(!s->budget--) { s->failed_pc=0x0c081674u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c081676;
P_0c081676: /* original e029, guest PC 0x0c081676 */
if(!s->budget--) { s->failed_pc=0x0c081676u; return 0; }
r[0]=0x00000029u;
goto P_0c081678;
P_0c081678: /* original 1f21, guest PC 0x0c081678 */
if(!s->budget--) { s->failed_pc=0x0c081678u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c08167a;
P_0c08167a: /* original e200, guest PC 0x0c08167a */
if(!s->budget--) { s->failed_pc=0x0c08167au; return 0; }
r[2]=0x00000000u;
goto P_0c08167c;
P_0c08167c: /* original 04cc, guest PC 0x0c08167c */
if(!s->budget--) { s->failed_pc=0x0c08167cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08167e;
P_0c08167e: /* original 9061, guest PC 0x0c08167e */
if(!s->budget--) { s->failed_pc=0x0c08167eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081744u,2);
goto P_0c081680;
P_0c081680: /* original 53f3, guest PC 0x0c081680 */
if(!s->budget--) { s->failed_pc=0x0c081680u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c081682;
P_0c081682: /* original 0325, guest PC 0x0c081682 */
if(!s->budget--) { s->failed_pc=0x0c081682u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c081684;
P_0c081684: /* original 53f1, guest PC 0x0c081684 */
if(!s->budget--) { s->failed_pc=0x0c081684u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c081686;
P_0c081686: /* original 2338, guest PC 0x0c081686 */
if(!s->budget--) { s->failed_pc=0x0c081686u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c081688;
P_0c081688: /* original 8d4f, guest PC 0x0c081688 */
if(!s->budget--) { s->failed_pc=0x0c081688u; return 0; }
cond=r[17]&1u;
r[4]=r[4]&255u;
if(cond) { goto P_0c08172a; }
goto P_0c08168c;
P_0c08168a: /* original 644c, guest PC 0x0c08168a */
if(!s->budget--) { s->failed_pc=0x0c08168au; return 0; }
r[4]=r[4]&255u;
goto P_0c08168c;
P_0c08168c: /* original 6043, guest PC 0x0c08168c */
if(!s->budget--) { s->failed_pc=0x0c08168cu; return 0; }
r[0]=r[4];
goto P_0c08168e;
P_0c08168e: /* original 8802, guest PC 0x0c08168e */
if(!s->budget--) { s->failed_pc=0x0c08168eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c081690;
P_0c081690: /* original 894b, guest PC 0x0c081690 */
if(!s->budget--) { s->failed_pc=0x0c081690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08172a; }
goto P_0c081692;
P_0c081692: /* original e597, guest PC 0x0c081692 */
if(!s->budget--) { s->failed_pc=0x0c081692u; return 0; }
r[5]=0xffffff97u;
goto P_0c081694;
P_0c081694: /* original 66f3, guest PC 0x0c081694 */
if(!s->budget--) { s->failed_pc=0x0c081694u; return 0; }
r[6]=r[15];
goto P_0c081696;
P_0c081696: /* original b1cc, guest PC 0x0c081696 */
if(!s->budget--) { s->failed_pc=0x0c081696u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08169au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08169au) { target=s->pc; goto dispatch; }
goto P_0c08169a;
P_0c081698: /* original 64e3, guest PC 0x0c081698 */
if(!s->budget--) { s->failed_pc=0x0c081698u; return 0; }
r[4]=r[14];
goto P_0c08169a;
P_0c08169a: /* original e590, guest PC 0x0c08169a */
if(!s->budget--) { s->failed_pc=0x0c08169au; return 0; }
r[5]=0xffffff90u;
goto P_0c08169c;
P_0c08169c: /* original 66f3, guest PC 0x0c08169c */
if(!s->budget--) { s->failed_pc=0x0c08169cu; return 0; }
r[6]=r[15];
goto P_0c08169e;
P_0c08169e: /* original b1c8, guest PC 0x0c08169e */
if(!s->budget--) { s->failed_pc=0x0c08169eu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0816a2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0816a2u) { target=s->pc; goto dispatch; }
goto P_0c0816a2;
P_0c0816a0: /* original 64e3, guest PC 0x0c0816a0 */
if(!s->budget--) { s->failed_pc=0x0c0816a0u; return 0; }
r[4]=r[14];
goto P_0c0816a2;
P_0c0816a2: /* original d22e, guest PC 0x0c0816a2 */
if(!s->budget--) { s->failed_pc=0x0c0816a2u; return 0; }
r[2]=read(ram,0x0c08175cu,4);
goto P_0c0816a4;
P_0c0816a4: /* original e51f, guest PC 0x0c0816a4 */
if(!s->budget--) { s->failed_pc=0x0c0816a4u; return 0; }
r[5]=0x0000001fu;
goto P_0c0816a6;
P_0c0816a6: /* original 66f3, guest PC 0x0c0816a6 */
if(!s->budget--) { s->failed_pc=0x0c0816a6u; return 0; }
r[6]=r[15];
goto P_0c0816a8;
P_0c0816a8: /* original 2d2b, guest PC 0x0c0816a8 */
if(!s->budget--) { s->failed_pc=0x0c0816a8u; return 0; }
r[13]|=r[2];
goto P_0c0816aa;
P_0c0816aa: /* original b1c2, guest PC 0x0c0816aa */
if(!s->budget--) { s->failed_pc=0x0c0816aau; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0816aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0816aeu) { target=s->pc; goto dispatch; }
goto P_0c0816ae;
P_0c0816ac: /* original 64e3, guest PC 0x0c0816ac */
if(!s->budget--) { s->failed_pc=0x0c0816acu; return 0; }
r[4]=r[14];
goto P_0c0816ae;
P_0c0816ae: /* original e53f, guest PC 0x0c0816ae */
if(!s->budget--) { s->failed_pc=0x0c0816aeu; return 0; }
r[5]=0x0000003fu;
goto P_0c0816b0;
P_0c0816b0: /* original 66f3, guest PC 0x0c0816b0 */
if(!s->budget--) { s->failed_pc=0x0c0816b0u; return 0; }
r[6]=r[15];
goto P_0c0816b2;
P_0c0816b2: /* original b1be, guest PC 0x0c0816b2 */
if(!s->budget--) { s->failed_pc=0x0c0816b2u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0816b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0816b6u) { target=s->pc; goto dispatch; }
goto P_0c0816b6;
P_0c0816b4: /* original 64e3, guest PC 0x0c0816b4 */
if(!s->budget--) { s->failed_pc=0x0c0816b4u; return 0; }
r[4]=r[14];
goto P_0c0816b6;
P_0c0816b6: /* original d32a, guest PC 0x0c0816b6 */
if(!s->budget--) { s->failed_pc=0x0c0816b6u; return 0; }
r[3]=read(ram,0x0c081760u,4);
goto P_0c0816b8;
P_0c0816b8: /* original 68a3, guest PC 0x0c0816b8 */
if(!s->budget--) { s->failed_pc=0x0c0816b8u; return 0; }
r[8]=r[10];
goto P_0c0816ba;
P_0c0816ba: /* original 51f1, guest PC 0x0c0816ba */
if(!s->budget--) { s->failed_pc=0x0c0816bau; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0816bc;
P_0c0816bc: /* original 430b, guest PC 0x0c0816bc */
if(!s->budget--) { s->failed_pc=0x0c0816bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0816c0u;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0816c0u) { target=s->pc; goto dispatch; }
goto P_0c0816c0;
P_0c0816be: /* original 60a3, guest PC 0x0c0816be */
if(!s->budget--) { s->failed_pc=0x0c0816beu; return 0; }
r[0]=r[10];
goto P_0c0816c0;
P_0c0816c0: /* original 6403, guest PC 0x0c0816c0 */
if(!s->budget--) { s->failed_pc=0x0c0816c0u; return 0; }
r[4]=r[0];
goto P_0c0816c2;
P_0c0816c2: /* original 2448, guest PC 0x0c0816c2 */
if(!s->budget--) { s->failed_pc=0x0c0816c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0816c4;
P_0c0816c4: /* original 7020, guest PC 0x0c0816c4 */
if(!s->budget--) { s->failed_pc=0x0c0816c4u; return 0; }
r[0]+=0x00000020u;
goto P_0c0816c6;
P_0c0816c6: /* original 8d04, guest PC 0x0c0816c6 */
if(!s->budget--) { s->failed_pc=0x0c0816c6u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[0],1);
if(cond) { goto P_0c0816d2; }
goto P_0c0816ca;
P_0c0816c8: /* original 80f8, guest PC 0x0c0816c8 */
if(!s->budget--) { s->failed_pc=0x0c0816c8u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c0816ca;
P_0c0816ca: /* original 6503, guest PC 0x0c0816ca */
if(!s->budget--) { s->failed_pc=0x0c0816cau; return 0; }
r[5]=r[0];
goto P_0c0816cc;
P_0c0816cc: /* original 66f3, guest PC 0x0c0816cc */
if(!s->budget--) { s->failed_pc=0x0c0816ccu; return 0; }
r[6]=r[15];
goto P_0c0816ce;
P_0c0816ce: /* original b1b0, guest PC 0x0c0816ce */
if(!s->budget--) { s->failed_pc=0x0c0816ceu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0816d2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0816d2u) { target=s->pc; goto dispatch; }
goto P_0c0816d2;
P_0c0816d0: /* original 64e3, guest PC 0x0c0816d0 */
if(!s->budget--) { s->failed_pc=0x0c0816d0u; return 0; }
r[4]=r[14];
goto P_0c0816d2;
P_0c0816d2: /* original d323, guest PC 0x0c0816d2 */
if(!s->budget--) { s->failed_pc=0x0c0816d2u; return 0; }
r[3]=read(ram,0x0c081760u,4);
goto P_0c0816d4;
P_0c0816d4: /* original 51f1, guest PC 0x0c0816d4 */
if(!s->budget--) { s->failed_pc=0x0c0816d4u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0816d6;
P_0c0816d6: /* original 430b, guest PC 0x0c0816d6 */
if(!s->budget--) { s->failed_pc=0x0c0816d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0816dau;
r[0]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0816dau) { target=s->pc; goto dispatch; }
goto P_0c0816da;
P_0c0816d8: /* original 6083, guest PC 0x0c0816d8 */
if(!s->budget--) { s->failed_pc=0x0c0816d8u; return 0; }
r[0]=r[8];
goto P_0c0816da;
P_0c0816da: /* original 6403, guest PC 0x0c0816da */
if(!s->budget--) { s->failed_pc=0x0c0816dau; return 0; }
r[4]=r[0];
goto P_0c0816dc;
P_0c0816dc: /* original 4408, guest PC 0x0c0816dc */
if(!s->budget--) { s->failed_pc=0x0c0816dcu; return 0; }
r[4]<<=2;
goto P_0c0816de;
P_0c0816de: /* original 6303, guest PC 0x0c0816de */
if(!s->budget--) { s->failed_pc=0x0c0816deu; return 0; }
r[3]=r[0];
goto P_0c0816e0;
P_0c0816e0: /* original 84f4, guest PC 0x0c0816e0 */
if(!s->budget--) { s->failed_pc=0x0c0816e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c0816e2;
P_0c0816e2: /* original 343c, guest PC 0x0c0816e2 */
if(!s->budget--) { s->failed_pc=0x0c0816e2u; return 0; }
r[4]+=r[3];
goto P_0c0816e4;
P_0c0816e4: /* original 66f3, guest PC 0x0c0816e4 */
if(!s->budget--) { s->failed_pc=0x0c0816e4u; return 0; }
r[6]=r[15];
goto P_0c0816e6;
P_0c0816e6: /* original 4400, guest PC 0x0c0816e6 */
if(!s->budget--) { s->failed_pc=0x0c0816e6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0816e8;
P_0c0816e8: /* original 3048, guest PC 0x0c0816e8 */
if(!s->budget--) { s->failed_pc=0x0c0816e8u; return 0; }
r[0]-=r[4];
goto P_0c0816ea;
P_0c0816ea: /* original 6503, guest PC 0x0c0816ea */
if(!s->budget--) { s->failed_pc=0x0c0816eau; return 0; }
r[5]=r[0];
goto P_0c0816ec;
P_0c0816ec: /* original 80f8, guest PC 0x0c0816ec */
if(!s->budget--) { s->failed_pc=0x0c0816ecu; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c0816ee;
P_0c0816ee: /* original b1a0, guest PC 0x0c0816ee */
if(!s->budget--) { s->failed_pc=0x0c0816eeu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0816f2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0816f2u) { target=s->pc; goto dispatch; }
goto P_0c0816f2;
P_0c0816f0: /* original 64e3, guest PC 0x0c0816f0 */
if(!s->budget--) { s->failed_pc=0x0c0816f0u; return 0; }
r[4]=r[14];
goto P_0c0816f2;
P_0c0816f2: /* original 51f1, guest PC 0x0c0816f2 */
if(!s->budget--) { s->failed_pc=0x0c0816f2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0816f4;
P_0c0816f4: /* original e31e, guest PC 0x0c0816f4 */
if(!s->budget--) { s->failed_pc=0x0c0816f4u; return 0; }
r[3]=0x0000001eu;
goto P_0c0816f6;
P_0c0816f6: /* original d21b, guest PC 0x0c0816f6 */
if(!s->budget--) { s->failed_pc=0x0c0816f6u; return 0; }
r[2]=read(ram,0x0c081764u,4);
goto P_0c0816f8;
P_0c0816f8: /* original 3133, guest PC 0x0c0816f8 */
if(!s->budget--) { s->failed_pc=0x0c0816f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c0816fa;
P_0c0816fa: /* original 2d29, guest PC 0x0c0816fa */
if(!s->budget--) { s->failed_pc=0x0c0816fau; return 0; }
r[13]&=r[2];
goto P_0c0816fc;
P_0c0816fc: /* original 8d13, guest PC 0x0c0816fc */
if(!s->budget--) { s->failed_pc=0x0c0816fcu; return 0; }
cond=r[17]&1u;
r[8]=0x00000024u;
if(cond) { goto P_0c081726; }
goto P_0c081700;
P_0c0816fe: /* original e824, guest PC 0x0c0816fe */
if(!s->budget--) { s->failed_pc=0x0c0816feu; return 0; }
r[8]=0x00000024u;
goto P_0c081700;
P_0c081700: /* original 55f3, guest PC 0x0c081700 */
if(!s->budget--) { s->failed_pc=0x0c081700u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c081702;
P_0c081702: /* original e048, guest PC 0x0c081702 */
if(!s->budget--) { s->failed_pc=0x0c081702u; return 0; }
r[0]=0x00000048u;
goto P_0c081704;
P_0c081704: /* original 56f4, guest PC 0x0c081704 */
if(!s->budget--) { s->failed_pc=0x0c081704u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c081706;
P_0c081706: /* original 055e, guest PC 0x0c081706 */
if(!s->budget--) { s->failed_pc=0x0c081706u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c081708;
P_0c081708: /* original e048, guest PC 0x0c081708 */
if(!s->budget--) { s->failed_pc=0x0c081708u; return 0; }
r[0]=0x00000048u;
goto P_0c08170a;
P_0c08170a: /* original 921d, guest PC 0x0c08170a */
if(!s->budget--) { s->failed_pc=0x0c08170au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081748u,2);
goto P_0c08170c;
P_0c08170c: /* original 066e, guest PC 0x0c08170c */
if(!s->budget--) { s->failed_pc=0x0c08170cu; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c08170e;
P_0c08170e: /* original 901a, guest PC 0x0c08170e */
if(!s->budget--) { s->failed_pc=0x0c08170eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081746u,2);
goto P_0c081710;
P_0c081710: /* original 2528, guest PC 0x0c081710 */
if(!s->budget--) { s->failed_pc=0x0c081710u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c081712;
P_0c081712: /* original 54f3, guest PC 0x0c081712 */
if(!s->budget--) { s->failed_pc=0x0c081712u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c081714;
P_0c081714: /* original 8f07, guest PC 0x0c081714 */
if(!s->budget--) { s->failed_pc=0x0c081714u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[4]+r[0],4);
if(!cond) { goto P_0c081726; }
goto P_0c081718;
P_0c081716: /* original 044e, guest PC 0x0c081716 */
if(!s->budget--) { s->failed_pc=0x0c081716u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c081718;
P_0c081718: /* original d113, guest PC 0x0c081718 */
if(!s->budget--) { s->failed_pc=0x0c081718u; return 0; }
r[1]=read(ram,0x0c081768u,4);
goto P_0c08171a;
P_0c08171a: /* original 2618, guest PC 0x0c08171a */
if(!s->budget--) { s->failed_pc=0x0c08171au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[1])==0)!=0);
goto P_0c08171c;
P_0c08171c: /* original 8b03, guest PC 0x0c08171c */
if(!s->budget--) { s->failed_pc=0x0c08171cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081726; }
goto P_0c08171e;
P_0c08171e: /* original d013, guest PC 0x0c08171e */
if(!s->budget--) { s->failed_pc=0x0c08171eu; return 0; }
r[0]=read(ram,0x0c08176cu,4);
goto P_0c081720;
P_0c081720: /* original 2408, guest PC 0x0c081720 */
if(!s->budget--) { s->failed_pc=0x0c081720u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[0])==0)!=0);
goto P_0c081722;
P_0c081722: /* original 8b00, guest PC 0x0c081722 */
if(!s->budget--) { s->failed_pc=0x0c081722u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081726; }
goto P_0c081724;
P_0c081724: /* original e812, guest PC 0x0c081724 */
if(!s->budget--) { s->failed_pc=0x0c081724u; return 0; }
r[8]=0x00000012u;
goto P_0c081726;
P_0c081726: /* original 9010, guest PC 0x0c081726 */
if(!s->budget--) { s->failed_pc=0x0c081726u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08174au,2);
goto P_0c081728;
P_0c081728: /* original 0b84, guest PC 0x0c081728 */
if(!s->budget--) { s->failed_pc=0x0c081728u; return 0; }
write(ram,r[11]+r[0],r[8],1);
goto P_0c08172a;
P_0c08172a: /* original 900b, guest PC 0x0c08172a */
if(!s->budget--) { s->failed_pc=0x0c08172au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081744u,2);
goto P_0c08172c;
P_0c08172c: /* original 53f4, guest PC 0x0c08172c */
if(!s->budget--) { s->failed_pc=0x0c08172cu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c08172e;
P_0c08172e: /* original 023d, guest PC 0x0c08172e */
if(!s->budget--) { s->failed_pc=0x0c08172eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c081730;
P_0c081730: /* original 1f21, guest PC 0x0c081730 */
if(!s->budget--) { s->failed_pc=0x0c081730u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c081732;
P_0c081732: /* original e200, guest PC 0x0c081732 */
if(!s->budget--) { s->failed_pc=0x0c081732u; return 0; }
r[2]=0x00000000u;
goto P_0c081734;
P_0c081734: /* original 9006, guest PC 0x0c081734 */
if(!s->budget--) { s->failed_pc=0x0c081734u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081744u,2);
goto P_0c081736;
P_0c081736: /* original 53f4, guest PC 0x0c081736 */
if(!s->budget--) { s->failed_pc=0x0c081736u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c081738;
P_0c081738: /* original 0325, guest PC 0x0c081738 */
if(!s->budget--) { s->failed_pc=0x0c081738u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c08173a;
P_0c08173a: /* original 53f1, guest PC 0x0c08173a */
if(!s->budget--) { s->failed_pc=0x0c08173au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c08173c;
P_0c08173c: /* original 2338, guest PC 0x0c08173c */
if(!s->budget--) { s->failed_pc=0x0c08173cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08173e;
P_0c08173e: /* original 895f, guest PC 0x0c08173e */
if(!s->budget--) { s->failed_pc=0x0c08173eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081800; }
goto P_0c081740;
P_0c081740: /* original a016, guest PC 0x0c081740 */
if(!s->budget--) { s->failed_pc=0x0c081740u; return 0; }
goto P_0c081770;
P_0c081742: /* original 0009, guest PC 0x0c081742 */
if(!s->budget--) { s->failed_pc=0x0c081742u; return 0; }
if(!vf3_matrix_family(0x0c081744u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081744u; return 0; } return 1;
P_0c081770: /* original e59f, guest PC 0x0c081770 */
if(!s->budget--) { s->failed_pc=0x0c081770u; return 0; }
r[5]=0xffffff9fu;
goto P_0c081772;
P_0c081772: /* original 66f3, guest PC 0x0c081772 */
if(!s->budget--) { s->failed_pc=0x0c081772u; return 0; }
r[6]=r[15];
goto P_0c081774;
P_0c081774: /* original b15d, guest PC 0x0c081774 */
if(!s->budget--) { s->failed_pc=0x0c081774u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081778u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081778u) { target=s->pc; goto dispatch; }
goto P_0c081778;
P_0c081776: /* original 64e3, guest PC 0x0c081776 */
if(!s->budget--) { s->failed_pc=0x0c081776u; return 0; }
r[4]=r[14];
goto P_0c081778;
P_0c081778: /* original e598, guest PC 0x0c081778 */
if(!s->budget--) { s->failed_pc=0x0c081778u; return 0; }
r[5]=0xffffff98u;
goto P_0c08177a;
P_0c08177a: /* original 66f3, guest PC 0x0c08177a */
if(!s->budget--) { s->failed_pc=0x0c08177au; return 0; }
r[6]=r[15];
goto P_0c08177c;
P_0c08177c: /* original b159, guest PC 0x0c08177c */
if(!s->budget--) { s->failed_pc=0x0c08177cu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081780u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081780u) { target=s->pc; goto dispatch; }
goto P_0c081780;
P_0c08177e: /* original 64e3, guest PC 0x0c08177e */
if(!s->budget--) { s->failed_pc=0x0c08177eu; return 0; }
r[4]=r[14];
goto P_0c081780;
P_0c081780: /* original d344, guest PC 0x0c081780 */
if(!s->budget--) { s->failed_pc=0x0c081780u; return 0; }
r[3]=read(ram,0x0c081894u,4);
goto P_0c081782;
P_0c081782: /* original e55f, guest PC 0x0c081782 */
if(!s->budget--) { s->failed_pc=0x0c081782u; return 0; }
r[5]=0x0000005fu;
goto P_0c081784;
P_0c081784: /* original 66f3, guest PC 0x0c081784 */
if(!s->budget--) { s->failed_pc=0x0c081784u; return 0; }
r[6]=r[15];
goto P_0c081786;
P_0c081786: /* original 2d3b, guest PC 0x0c081786 */
if(!s->budget--) { s->failed_pc=0x0c081786u; return 0; }
r[13]|=r[3];
goto P_0c081788;
P_0c081788: /* original b153, guest PC 0x0c081788 */
if(!s->budget--) { s->failed_pc=0x0c081788u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08178cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08178cu) { target=s->pc; goto dispatch; }
goto P_0c08178c;
P_0c08178a: /* original 64e3, guest PC 0x0c08178a */
if(!s->budget--) { s->failed_pc=0x0c08178au; return 0; }
r[4]=r[14];
goto P_0c08178c;
P_0c08178c: /* original e57f, guest PC 0x0c08178c */
if(!s->budget--) { s->failed_pc=0x0c08178cu; return 0; }
r[5]=0x0000007fu;
goto P_0c08178e;
P_0c08178e: /* original 66f3, guest PC 0x0c08178e */
if(!s->budget--) { s->failed_pc=0x0c08178eu; return 0; }
r[6]=r[15];
goto P_0c081790;
P_0c081790: /* original b14f, guest PC 0x0c081790 */
if(!s->budget--) { s->failed_pc=0x0c081790u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081794u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081794u) { target=s->pc; goto dispatch; }
goto P_0c081794;
P_0c081792: /* original 64e3, guest PC 0x0c081792 */
if(!s->budget--) { s->failed_pc=0x0c081792u; return 0; }
r[4]=r[14];
goto P_0c081794;
P_0c081794: /* original d240, guest PC 0x0c081794 */
if(!s->budget--) { s->failed_pc=0x0c081794u; return 0; }
r[2]=read(ram,0x0c081898u,4);
goto P_0c081796;
P_0c081796: /* original 64a3, guest PC 0x0c081796 */
if(!s->budget--) { s->failed_pc=0x0c081796u; return 0; }
r[4]=r[10];
goto P_0c081798;
P_0c081798: /* original 51f1, guest PC 0x0c081798 */
if(!s->budget--) { s->failed_pc=0x0c081798u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c08179a;
P_0c08179a: /* original 420b, guest PC 0x0c08179a */
if(!s->budget--) { s->failed_pc=0x0c08179au; return 0; }
target=r[2];
r[16]=code_base|0x0c08179eu;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08179eu) { target=s->pc; goto dispatch; }
goto P_0c08179e;
P_0c08179c: /* original 60a3, guest PC 0x0c08179c */
if(!s->budget--) { s->failed_pc=0x0c08179cu; return 0; }
r[0]=r[10];
goto P_0c08179e;
P_0c08179e: /* original 6903, guest PC 0x0c08179e */
if(!s->budget--) { s->failed_pc=0x0c08179eu; return 0; }
r[9]=r[0];
goto P_0c0817a0;
P_0c0817a0: /* original 2998, guest PC 0x0c0817a0 */
if(!s->budget--) { s->failed_pc=0x0c0817a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0817a2;
P_0c0817a2: /* original 7060, guest PC 0x0c0817a2 */
if(!s->budget--) { s->failed_pc=0x0c0817a2u; return 0; }
r[0]+=0x00000060u;
goto P_0c0817a4;
P_0c0817a4: /* original 8d04, guest PC 0x0c0817a4 */
if(!s->budget--) { s->failed_pc=0x0c0817a4u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[0],1);
if(cond) { goto P_0c0817b0; }
goto P_0c0817a8;
P_0c0817a6: /* original 80f8, guest PC 0x0c0817a6 */
if(!s->budget--) { s->failed_pc=0x0c0817a6u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c0817a8;
P_0c0817a8: /* original 6503, guest PC 0x0c0817a8 */
if(!s->budget--) { s->failed_pc=0x0c0817a8u; return 0; }
r[5]=r[0];
goto P_0c0817aa;
P_0c0817aa: /* original 66f3, guest PC 0x0c0817aa */
if(!s->budget--) { s->failed_pc=0x0c0817aau; return 0; }
r[6]=r[15];
goto P_0c0817ac;
P_0c0817ac: /* original b141, guest PC 0x0c0817ac */
if(!s->budget--) { s->failed_pc=0x0c0817acu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0817b0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0817b0u) { target=s->pc; goto dispatch; }
goto P_0c0817b0;
P_0c0817ae: /* original 64e3, guest PC 0x0c0817ae */
if(!s->budget--) { s->failed_pc=0x0c0817aeu; return 0; }
r[4]=r[14];
goto P_0c0817b0;
P_0c0817b0: /* original 6493, guest PC 0x0c0817b0 */
if(!s->budget--) { s->failed_pc=0x0c0817b0u; return 0; }
r[4]=r[9];
goto P_0c0817b2;
P_0c0817b2: /* original 4408, guest PC 0x0c0817b2 */
if(!s->budget--) { s->failed_pc=0x0c0817b2u; return 0; }
r[4]<<=2;
goto P_0c0817b4;
P_0c0817b4: /* original 6393, guest PC 0x0c0817b4 */
if(!s->budget--) { s->failed_pc=0x0c0817b4u; return 0; }
r[3]=r[9];
goto P_0c0817b6;
P_0c0817b6: /* original 59f1, guest PC 0x0c0817b6 */
if(!s->budget--) { s->failed_pc=0x0c0817b6u; return 0; }
r[9]=read(ram,r[15]+4,4);
goto P_0c0817b8;
P_0c0817b8: /* original 343c, guest PC 0x0c0817b8 */
if(!s->budget--) { s->failed_pc=0x0c0817b8u; return 0; }
r[4]+=r[3];
goto P_0c0817ba;
P_0c0817ba: /* original 66f3, guest PC 0x0c0817ba */
if(!s->budget--) { s->failed_pc=0x0c0817bau; return 0; }
r[6]=r[15];
goto P_0c0817bc;
P_0c0817bc: /* original 4400, guest PC 0x0c0817bc */
if(!s->budget--) { s->failed_pc=0x0c0817bcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0817be;
P_0c0817be: /* original 3948, guest PC 0x0c0817be */
if(!s->budget--) { s->failed_pc=0x0c0817beu; return 0; }
r[9]-=r[4];
goto P_0c0817c0;
P_0c0817c0: /* original 7940, guest PC 0x0c0817c0 */
if(!s->budget--) { s->failed_pc=0x0c0817c0u; return 0; }
r[9]+=0x00000040u;
goto P_0c0817c2;
P_0c0817c2: /* original 6593, guest PC 0x0c0817c2 */
if(!s->budget--) { s->failed_pc=0x0c0817c2u; return 0; }
r[5]=r[9];
goto P_0c0817c4;
P_0c0817c4: /* original b135, guest PC 0x0c0817c4 */
if(!s->budget--) { s->failed_pc=0x0c0817c4u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0817c8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0817c8u) { target=s->pc; goto dispatch; }
goto P_0c0817c8;
P_0c0817c6: /* original 64e3, guest PC 0x0c0817c6 */
if(!s->budget--) { s->failed_pc=0x0c0817c6u; return 0; }
r[4]=r[14];
goto P_0c0817c8;
P_0c0817c8: /* original 51f1, guest PC 0x0c0817c8 */
if(!s->budget--) { s->failed_pc=0x0c0817c8u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0817ca;
P_0c0817ca: /* original e31e, guest PC 0x0c0817ca */
if(!s->budget--) { s->failed_pc=0x0c0817cau; return 0; }
r[3]=0x0000001eu;
goto P_0c0817cc;
P_0c0817cc: /* original d233, guest PC 0x0c0817cc */
if(!s->budget--) { s->failed_pc=0x0c0817ccu; return 0; }
r[2]=read(ram,0x0c08189cu,4);
goto P_0c0817ce;
P_0c0817ce: /* original 3133, guest PC 0x0c0817ce */
if(!s->budget--) { s->failed_pc=0x0c0817ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c0817d0;
P_0c0817d0: /* original 2d29, guest PC 0x0c0817d0 */
if(!s->budget--) { s->failed_pc=0x0c0817d0u; return 0; }
r[13]&=r[2];
goto P_0c0817d2;
P_0c0817d2: /* original 8d13, guest PC 0x0c0817d2 */
if(!s->budget--) { s->failed_pc=0x0c0817d2u; return 0; }
cond=r[17]&1u;
r[9]=0x00000024u;
if(cond) { goto P_0c0817fc; }
goto P_0c0817d6;
P_0c0817d4: /* original e924, guest PC 0x0c0817d4 */
if(!s->budget--) { s->failed_pc=0x0c0817d4u; return 0; }
r[9]=0x00000024u;
goto P_0c0817d6;
P_0c0817d6: /* original 55f4, guest PC 0x0c0817d6 */
if(!s->budget--) { s->failed_pc=0x0c0817d6u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c0817d8;
P_0c0817d8: /* original e048, guest PC 0x0c0817d8 */
if(!s->budget--) { s->failed_pc=0x0c0817d8u; return 0; }
r[0]=0x00000048u;
goto P_0c0817da;
P_0c0817da: /* original 54f3, guest PC 0x0c0817da */
if(!s->budget--) { s->failed_pc=0x0c0817dau; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0817dc;
P_0c0817dc: /* original 055e, guest PC 0x0c0817dc */
if(!s->budget--) { s->failed_pc=0x0c0817dcu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0817de;
P_0c0817de: /* original e048, guest PC 0x0c0817de */
if(!s->budget--) { s->failed_pc=0x0c0817deu; return 0; }
r[0]=0x00000048u;
goto P_0c0817e0;
P_0c0817e0: /* original 9255, guest PC 0x0c0817e0 */
if(!s->budget--) { s->failed_pc=0x0c0817e0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08188eu,2);
goto P_0c0817e2;
P_0c0817e2: /* original 044e, guest PC 0x0c0817e2 */
if(!s->budget--) { s->failed_pc=0x0c0817e2u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0817e4;
P_0c0817e4: /* original 9052, guest PC 0x0c0817e4 */
if(!s->budget--) { s->failed_pc=0x0c0817e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08188cu,2);
goto P_0c0817e6;
P_0c0817e6: /* original 2528, guest PC 0x0c0817e6 */
if(!s->budget--) { s->failed_pc=0x0c0817e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0817e8;
P_0c0817e8: /* original 56f4, guest PC 0x0c0817e8 */
if(!s->budget--) { s->failed_pc=0x0c0817e8u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c0817ea;
P_0c0817ea: /* original 8f07, guest PC 0x0c0817ea */
if(!s->budget--) { s->failed_pc=0x0c0817eau; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[6]+r[0],4);
if(!cond) { goto P_0c0817fc; }
goto P_0c0817ee;
P_0c0817ec: /* original 066e, guest PC 0x0c0817ec */
if(!s->budget--) { s->failed_pc=0x0c0817ecu; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c0817ee;
P_0c0817ee: /* original d12c, guest PC 0x0c0817ee */
if(!s->budget--) { s->failed_pc=0x0c0817eeu; return 0; }
r[1]=read(ram,0x0c0818a0u,4);
goto P_0c0817f0;
P_0c0817f0: /* original 2418, guest PC 0x0c0817f0 */
if(!s->budget--) { s->failed_pc=0x0c0817f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0817f2;
P_0c0817f2: /* original 8b03, guest PC 0x0c0817f2 */
if(!s->budget--) { s->failed_pc=0x0c0817f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0817fc; }
goto P_0c0817f4;
P_0c0817f4: /* original d02b, guest PC 0x0c0817f4 */
if(!s->budget--) { s->failed_pc=0x0c0817f4u; return 0; }
r[0]=read(ram,0x0c0818a4u,4);
goto P_0c0817f6;
P_0c0817f6: /* original 2608, guest PC 0x0c0817f6 */
if(!s->budget--) { s->failed_pc=0x0c0817f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[0])==0)!=0);
goto P_0c0817f8;
P_0c0817f8: /* original 8b00, guest PC 0x0c0817f8 */
if(!s->budget--) { s->failed_pc=0x0c0817f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0817fc; }
goto P_0c0817fa;
P_0c0817fa: /* original e912, guest PC 0x0c0817fa */
if(!s->budget--) { s->failed_pc=0x0c0817fau; return 0; }
r[9]=0x00000012u;
goto P_0c0817fc;
P_0c0817fc: /* original 9048, guest PC 0x0c0817fc */
if(!s->budget--) { s->failed_pc=0x0c0817fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081890u,2);
goto P_0c0817fe;
P_0c0817fe: /* original 0b94, guest PC 0x0c0817fe */
if(!s->budget--) { s->failed_pc=0x0c0817feu; return 0; }
write(ram,r[11]+r[0],r[9],1);
goto P_0c081800;
P_0c081800: /* original 9047, guest PC 0x0c081800 */
if(!s->budget--) { s->failed_pc=0x0c081800u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081892u,2);
goto P_0c081802;
P_0c081802: /* original 688e, guest PC 0x0c081802 */
if(!s->budget--) { s->failed_pc=0x0c081802u; return 0; }
r[8]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c081804;
P_0c081804: /* original 4815, guest PC 0x0c081804 */
if(!s->budget--) { s->failed_pc=0x0c081804u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c081806;
P_0c081806: /* original 03ce, guest PC 0x0c081806 */
if(!s->budget--) { s->failed_pc=0x0c081806u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c081808;
P_0c081808: /* original e029, guest PC 0x0c081808 */
if(!s->budget--) { s->failed_pc=0x0c081808u; return 0; }
r[0]=0x00000029u;
goto P_0c08180a;
P_0c08180a: /* original 1f33, guest PC 0x0c08180a */
if(!s->budget--) { s->failed_pc=0x0c08180au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c08180c;
P_0c08180c: /* original 02cc, guest PC 0x0c08180c */
if(!s->budget--) { s->failed_pc=0x0c08180cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08180e;
P_0c08180e: /* original e02a, guest PC 0x0c08180e */
if(!s->budget--) { s->failed_pc=0x0c08180eu; return 0; }
r[0]=0x0000002au;
goto P_0c081810;
P_0c081810: /* original 622c, guest PC 0x0c081810 */
if(!s->budget--) { s->failed_pc=0x0c081810u; return 0; }
r[2]=r[2]&255u;
goto P_0c081812;
P_0c081812: /* original 1f24, guest PC 0x0c081812 */
if(!s->budget--) { s->failed_pc=0x0c081812u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c081814;
P_0c081814: /* original 04cc, guest PC 0x0c081814 */
if(!s->budget--) { s->failed_pc=0x0c081814u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c081816;
P_0c081816: /* original 8d50, guest PC 0x0c081816 */
if(!s->budget--) { s->failed_pc=0x0c081816u; return 0; }
cond=r[17]&1u;
r[12]=(uint32_t)(int32_t)(int8_t)r[4];
if(cond) { goto P_0c0818ba; }
goto P_0c08181a;
P_0c081818: /* original 6c4e, guest PC 0x0c081818 */
if(!s->budget--) { s->failed_pc=0x0c081818u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08181a;
P_0c08181a: /* original d223, guest PC 0x0c08181a */
if(!s->budget--) { s->failed_pc=0x0c08181au; return 0; }
r[2]=read(ram,0x0c0818a8u,4);
goto P_0c08181c;
P_0c08181c: /* original 22d8, guest PC 0x0c08181c */
if(!s->budget--) { s->failed_pc=0x0c08181cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c08181e;
P_0c08181e: /* original 894c, guest PC 0x0c08181e */
if(!s->budget--) { s->failed_pc=0x0c08181eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0818ba; }
goto P_0c081820;
P_0c081820: /* original d122, guest PC 0x0c081820 */
if(!s->budget--) { s->failed_pc=0x0c081820u; return 0; }
r[1]=read(ram,0x0c0818acu,4);
goto P_0c081822;
P_0c081822: /* original e597, guest PC 0x0c081822 */
if(!s->budget--) { s->failed_pc=0x0c081822u; return 0; }
r[5]=0xffffff97u;
goto P_0c081824;
P_0c081824: /* original 66f3, guest PC 0x0c081824 */
if(!s->budget--) { s->failed_pc=0x0c081824u; return 0; }
r[6]=r[15];
goto P_0c081826;
P_0c081826: /* original 2d19, guest PC 0x0c081826 */
if(!s->budget--) { s->failed_pc=0x0c081826u; return 0; }
r[13]&=r[1];
goto P_0c081828;
P_0c081828: /* original b103, guest PC 0x0c081828 */
if(!s->budget--) { s->failed_pc=0x0c081828u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08182cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08182cu) { target=s->pc; goto dispatch; }
goto P_0c08182c;
P_0c08182a: /* original 64e3, guest PC 0x0c08182a */
if(!s->budget--) { s->failed_pc=0x0c08182au; return 0; }
r[4]=r[14];
goto P_0c08182c;
P_0c08182c: /* original e51f, guest PC 0x0c08182c */
if(!s->budget--) { s->failed_pc=0x0c08182cu; return 0; }
r[5]=0x0000001fu;
goto P_0c08182e;
P_0c08182e: /* original 66f3, guest PC 0x0c08182e */
if(!s->budget--) { s->failed_pc=0x0c08182eu; return 0; }
r[6]=r[15];
goto P_0c081830;
P_0c081830: /* original b0ff, guest PC 0x0c081830 */
if(!s->budget--) { s->failed_pc=0x0c081830u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081834u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081834u) { target=s->pc; goto dispatch; }
goto P_0c081834;
P_0c081832: /* original 64e3, guest PC 0x0c081832 */
if(!s->budget--) { s->failed_pc=0x0c081832u; return 0; }
r[4]=r[14];
goto P_0c081834;
P_0c081834: /* original e53f, guest PC 0x0c081834 */
if(!s->budget--) { s->failed_pc=0x0c081834u; return 0; }
r[5]=0x0000003fu;
goto P_0c081836;
P_0c081836: /* original 66f3, guest PC 0x0c081836 */
if(!s->budget--) { s->failed_pc=0x0c081836u; return 0; }
r[6]=r[15];
goto P_0c081838;
P_0c081838: /* original b0fb, guest PC 0x0c081838 */
if(!s->budget--) { s->failed_pc=0x0c081838u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08183cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08183cu) { target=s->pc; goto dispatch; }
goto P_0c08183c;
P_0c08183a: /* original 64e3, guest PC 0x0c08183a */
if(!s->budget--) { s->failed_pc=0x0c08183au; return 0; }
r[4]=r[14];
goto P_0c08183c;
P_0c08183c: /* original 50f4, guest PC 0x0c08183c */
if(!s->budget--) { s->failed_pc=0x0c08183cu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c08183e;
P_0c08183e: /* original 8802, guest PC 0x0c08183e */
if(!s->budget--) { s->failed_pc=0x0c08183eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c081840;
P_0c081840: /* original 893b, guest PC 0x0c081840 */
if(!s->budget--) { s->failed_pc=0x0c081840u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0818ba; }
goto P_0c081842;
P_0c081842: /* original 52f3, guest PC 0x0c081842 */
if(!s->budget--) { s->failed_pc=0x0c081842u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c081844;
P_0c081844: /* original 2228, guest PC 0x0c081844 */
if(!s->budget--) { s->failed_pc=0x0c081844u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c081846;
P_0c081846: /* original 8938, guest PC 0x0c081846 */
if(!s->budget--) { s->failed_pc=0x0c081846u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0818ba; }
goto P_0c081848;
P_0c081848: /* original 50f4, guest PC 0x0c081848 */
if(!s->budget--) { s->failed_pc=0x0c081848u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c08184a;
P_0c08184a: /* original 8801, guest PC 0x0c08184a */
if(!s->budget--) { s->failed_pc=0x0c08184au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08184c;
P_0c08184c: /* original 8902, guest PC 0x0c08184c */
if(!s->budget--) { s->failed_pc=0x0c08184cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081854; }
goto P_0c08184e;
P_0c08184e: /* original 60c3, guest PC 0x0c08184e */
if(!s->budget--) { s->failed_pc=0x0c08184eu; return 0; }
r[0]=r[12];
goto P_0c081850;
P_0c081850: /* original 8801, guest PC 0x0c081850 */
if(!s->budget--) { s->failed_pc=0x0c081850u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081852;
P_0c081852: /* original 8b32, guest PC 0x0c081852 */
if(!s->budget--) { s->failed_pc=0x0c081852u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0818ba; }
goto P_0c081854;
P_0c081854: /* original d210, guest PC 0x0c081854 */
if(!s->budget--) { s->failed_pc=0x0c081854u; return 0; }
r[2]=read(ram,0x0c081898u,4);
goto P_0c081856;
P_0c081856: /* original 68a3, guest PC 0x0c081856 */
if(!s->budget--) { s->failed_pc=0x0c081856u; return 0; }
r[8]=r[10];
goto P_0c081858;
P_0c081858: /* original 51f3, guest PC 0x0c081858 */
if(!s->budget--) { s->failed_pc=0x0c081858u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c08185a;
P_0c08185a: /* original 420b, guest PC 0x0c08185a */
if(!s->budget--) { s->failed_pc=0x0c08185au; return 0; }
target=r[2];
r[16]=code_base|0x0c08185eu;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08185eu) { target=s->pc; goto dispatch; }
goto P_0c08185e;
P_0c08185c: /* original 60a3, guest PC 0x0c08185c */
if(!s->budget--) { s->failed_pc=0x0c08185cu; return 0; }
r[0]=r[10];
goto P_0c08185e;
P_0c08185e: /* original 6403, guest PC 0x0c08185e */
if(!s->budget--) { s->failed_pc=0x0c08185eu; return 0; }
r[4]=r[0];
goto P_0c081860;
P_0c081860: /* original 2448, guest PC 0x0c081860 */
if(!s->budget--) { s->failed_pc=0x0c081860u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c081862;
P_0c081862: /* original 8906, guest PC 0x0c081862 */
if(!s->budget--) { s->failed_pc=0x0c081862u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081872; }
goto P_0c081864;
P_0c081864: /* original 6043, guest PC 0x0c081864 */
if(!s->budget--) { s->failed_pc=0x0c081864u; return 0; }
r[0]=r[4];
goto P_0c081866;
P_0c081866: /* original 7020, guest PC 0x0c081866 */
if(!s->budget--) { s->failed_pc=0x0c081866u; return 0; }
r[0]+=0x00000020u;
goto P_0c081868;
P_0c081868: /* original 6503, guest PC 0x0c081868 */
if(!s->budget--) { s->failed_pc=0x0c081868u; return 0; }
r[5]=r[0];
goto P_0c08186a;
P_0c08186a: /* original 66f3, guest PC 0x0c08186a */
if(!s->budget--) { s->failed_pc=0x0c08186au; return 0; }
r[6]=r[15];
goto P_0c08186c;
P_0c08186c: /* original 80f4, guest PC 0x0c08186c */
if(!s->budget--) { s->failed_pc=0x0c08186cu; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c08186e;
P_0c08186e: /* original b0e0, guest PC 0x0c08186e */
if(!s->budget--) { s->failed_pc=0x0c08186eu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081872u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081872u) { target=s->pc; goto dispatch; }
goto P_0c081872;
P_0c081870: /* original 64e3, guest PC 0x0c081870 */
if(!s->budget--) { s->failed_pc=0x0c081870u; return 0; }
r[4]=r[14];
goto P_0c081872;
P_0c081872: /* original d209, guest PC 0x0c081872 */
if(!s->budget--) { s->failed_pc=0x0c081872u; return 0; }
r[2]=read(ram,0x0c081898u,4);
goto P_0c081874;
P_0c081874: /* original 51f3, guest PC 0x0c081874 */
if(!s->budget--) { s->failed_pc=0x0c081874u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c081876;
P_0c081876: /* original 420b, guest PC 0x0c081876 */
if(!s->budget--) { s->failed_pc=0x0c081876u; return 0; }
target=r[2];
r[16]=code_base|0x0c08187au;
r[0]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08187au) { target=s->pc; goto dispatch; }
goto P_0c08187a;
P_0c081878: /* original 6083, guest PC 0x0c081878 */
if(!s->budget--) { s->failed_pc=0x0c081878u; return 0; }
r[0]=r[8];
goto P_0c08187a;
P_0c08187a: /* original 6403, guest PC 0x0c08187a */
if(!s->budget--) { s->failed_pc=0x0c08187au; return 0; }
r[4]=r[0];
goto P_0c08187c;
P_0c08187c: /* original 4408, guest PC 0x0c08187c */
if(!s->budget--) { s->failed_pc=0x0c08187cu; return 0; }
r[4]<<=2;
goto P_0c08187e;
P_0c08187e: /* original 6303, guest PC 0x0c08187e */
if(!s->budget--) { s->failed_pc=0x0c08187eu; return 0; }
r[3]=r[0];
goto P_0c081880;
P_0c081880: /* original 84fc, guest PC 0x0c081880 */
if(!s->budget--) { s->failed_pc=0x0c081880u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c081882;
P_0c081882: /* original 343c, guest PC 0x0c081882 */
if(!s->budget--) { s->failed_pc=0x0c081882u; return 0; }
r[4]+=r[3];
goto P_0c081884;
P_0c081884: /* original 4400, guest PC 0x0c081884 */
if(!s->budget--) { s->failed_pc=0x0c081884u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081886;
P_0c081886: /* original 3048, guest PC 0x0c081886 */
if(!s->budget--) { s->failed_pc=0x0c081886u; return 0; }
r[0]-=r[4];
goto P_0c081888;
P_0c081888: /* original a012, guest PC 0x0c081888 */
if(!s->budget--) { s->failed_pc=0x0c081888u; return 0; }
goto P_0c0818b0;
P_0c08188a: /* original 0009, guest PC 0x0c08188a */
if(!s->budget--) { s->failed_pc=0x0c08188au; return 0; }
if(!vf3_matrix_family(0x0c08188cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08188cu; return 0; } return 1;
P_0c0818b0: /* original 6503, guest PC 0x0c0818b0 */
if(!s->budget--) { s->failed_pc=0x0c0818b0u; return 0; }
r[5]=r[0];
goto P_0c0818b2;
P_0c0818b2: /* original 66f3, guest PC 0x0c0818b2 */
if(!s->budget--) { s->failed_pc=0x0c0818b2u; return 0; }
r[6]=r[15];
goto P_0c0818b4;
P_0c0818b4: /* original 80f4, guest PC 0x0c0818b4 */
if(!s->budget--) { s->failed_pc=0x0c0818b4u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c0818b6;
P_0c0818b6: /* original b0bc, guest PC 0x0c0818b6 */
if(!s->budget--) { s->failed_pc=0x0c0818b6u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0818bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0818bau) { target=s->pc; goto dispatch; }
goto P_0c0818ba;
P_0c0818b8: /* original 64e3, guest PC 0x0c0818b8 */
if(!s->budget--) { s->failed_pc=0x0c0818b8u; return 0; }
r[4]=r[14];
goto P_0c0818ba;
P_0c0818ba: /* original 699e, guest PC 0x0c0818ba */
if(!s->budget--) { s->failed_pc=0x0c0818bau; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)r[9];
goto P_0c0818bc;
P_0c0818bc: /* original 4915, guest PC 0x0c0818bc */
if(!s->budget--) { s->failed_pc=0x0c0818bcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>0)!=0);
goto P_0c0818be;
P_0c0818be: /* original 8938, guest PC 0x0c0818be */
if(!s->budget--) { s->failed_pc=0x0c0818beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081932; }
goto P_0c0818c0;
P_0c0818c0: /* original d345, guest PC 0x0c0818c0 */
if(!s->budget--) { s->failed_pc=0x0c0818c0u; return 0; }
r[3]=read(ram,0x0c0819d8u,4);
goto P_0c0818c2;
P_0c0818c2: /* original 23d8, guest PC 0x0c0818c2 */
if(!s->budget--) { s->failed_pc=0x0c0818c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0818c4;
P_0c0818c4: /* original 8935, guest PC 0x0c0818c4 */
if(!s->budget--) { s->failed_pc=0x0c0818c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081932; }
goto P_0c0818c6;
P_0c0818c6: /* original d145, guest PC 0x0c0818c6 */
if(!s->budget--) { s->failed_pc=0x0c0818c6u; return 0; }
r[1]=read(ram,0x0c0819dcu,4);
goto P_0c0818c8;
P_0c0818c8: /* original e59f, guest PC 0x0c0818c8 */
if(!s->budget--) { s->failed_pc=0x0c0818c8u; return 0; }
r[5]=0xffffff9fu;
goto P_0c0818ca;
P_0c0818ca: /* original 66f3, guest PC 0x0c0818ca */
if(!s->budget--) { s->failed_pc=0x0c0818cau; return 0; }
r[6]=r[15];
goto P_0c0818cc;
P_0c0818cc: /* original 2d19, guest PC 0x0c0818cc */
if(!s->budget--) { s->failed_pc=0x0c0818ccu; return 0; }
r[13]&=r[1];
goto P_0c0818ce;
P_0c0818ce: /* original b0b0, guest PC 0x0c0818ce */
if(!s->budget--) { s->failed_pc=0x0c0818ceu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0818d2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0818d2u) { target=s->pc; goto dispatch; }
goto P_0c0818d2;
P_0c0818d0: /* original 64e3, guest PC 0x0c0818d0 */
if(!s->budget--) { s->failed_pc=0x0c0818d0u; return 0; }
r[4]=r[14];
goto P_0c0818d2;
P_0c0818d2: /* original e55f, guest PC 0x0c0818d2 */
if(!s->budget--) { s->failed_pc=0x0c0818d2u; return 0; }
r[5]=0x0000005fu;
goto P_0c0818d4;
P_0c0818d4: /* original 66f3, guest PC 0x0c0818d4 */
if(!s->budget--) { s->failed_pc=0x0c0818d4u; return 0; }
r[6]=r[15];
goto P_0c0818d6;
P_0c0818d6: /* original b0ac, guest PC 0x0c0818d6 */
if(!s->budget--) { s->failed_pc=0x0c0818d6u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0818dau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0818dau) { target=s->pc; goto dispatch; }
goto P_0c0818da;
P_0c0818d8: /* original 64e3, guest PC 0x0c0818d8 */
if(!s->budget--) { s->failed_pc=0x0c0818d8u; return 0; }
r[4]=r[14];
goto P_0c0818da;
P_0c0818da: /* original e57f, guest PC 0x0c0818da */
if(!s->budget--) { s->failed_pc=0x0c0818dau; return 0; }
r[5]=0x0000007fu;
goto P_0c0818dc;
P_0c0818dc: /* original 66f3, guest PC 0x0c0818dc */
if(!s->budget--) { s->failed_pc=0x0c0818dcu; return 0; }
r[6]=r[15];
goto P_0c0818de;
P_0c0818de: /* original b0a8, guest PC 0x0c0818de */
if(!s->budget--) { s->failed_pc=0x0c0818deu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c0818e2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0818e2u) { target=s->pc; goto dispatch; }
goto P_0c0818e2;
P_0c0818e0: /* original 64e3, guest PC 0x0c0818e0 */
if(!s->budget--) { s->failed_pc=0x0c0818e0u; return 0; }
r[4]=r[14];
goto P_0c0818e2;
P_0c0818e2: /* original 50f4, guest PC 0x0c0818e2 */
if(!s->budget--) { s->failed_pc=0x0c0818e2u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0818e4;
P_0c0818e4: /* original 8801, guest PC 0x0c0818e4 */
if(!s->budget--) { s->failed_pc=0x0c0818e4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0818e6;
P_0c0818e6: /* original 8924, guest PC 0x0c0818e6 */
if(!s->budget--) { s->failed_pc=0x0c0818e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081932; }
goto P_0c0818e8;
P_0c0818e8: /* original 52f3, guest PC 0x0c0818e8 */
if(!s->budget--) { s->failed_pc=0x0c0818e8u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0818ea;
P_0c0818ea: /* original 2228, guest PC 0x0c0818ea */
if(!s->budget--) { s->failed_pc=0x0c0818eau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0818ec;
P_0c0818ec: /* original 8921, guest PC 0x0c0818ec */
if(!s->budget--) { s->failed_pc=0x0c0818ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081932; }
goto P_0c0818ee;
P_0c0818ee: /* original 50f4, guest PC 0x0c0818ee */
if(!s->budget--) { s->failed_pc=0x0c0818eeu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0818f0;
P_0c0818f0: /* original 8802, guest PC 0x0c0818f0 */
if(!s->budget--) { s->failed_pc=0x0c0818f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0818f2;
P_0c0818f2: /* original 8902, guest PC 0x0c0818f2 */
if(!s->budget--) { s->failed_pc=0x0c0818f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0818fa; }
goto P_0c0818f4;
P_0c0818f4: /* original 60c3, guest PC 0x0c0818f4 */
if(!s->budget--) { s->failed_pc=0x0c0818f4u; return 0; }
r[0]=r[12];
goto P_0c0818f6;
P_0c0818f6: /* original 8802, guest PC 0x0c0818f6 */
if(!s->budget--) { s->failed_pc=0x0c0818f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0818f8;
P_0c0818f8: /* original 8b1b, guest PC 0x0c0818f8 */
if(!s->budget--) { s->failed_pc=0x0c0818f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081932; }
goto P_0c0818fa;
P_0c0818fa: /* original d239, guest PC 0x0c0818fa */
if(!s->budget--) { s->failed_pc=0x0c0818fau; return 0; }
r[2]=read(ram,0x0c0819e0u,4);
goto P_0c0818fc;
P_0c0818fc: /* original 64a3, guest PC 0x0c0818fc */
if(!s->budget--) { s->failed_pc=0x0c0818fcu; return 0; }
r[4]=r[10];
goto P_0c0818fe;
P_0c0818fe: /* original 51f3, guest PC 0x0c0818fe */
if(!s->budget--) { s->failed_pc=0x0c0818feu; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c081900;
P_0c081900: /* original 420b, guest PC 0x0c081900 */
if(!s->budget--) { s->failed_pc=0x0c081900u; return 0; }
target=r[2];
r[16]=code_base|0x0c081904u;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081904u) { target=s->pc; goto dispatch; }
goto P_0c081904;
P_0c081902: /* original 60a3, guest PC 0x0c081902 */
if(!s->budget--) { s->failed_pc=0x0c081902u; return 0; }
r[0]=r[10];
goto P_0c081904;
P_0c081904: /* original 6c03, guest PC 0x0c081904 */
if(!s->budget--) { s->failed_pc=0x0c081904u; return 0; }
r[12]=r[0];
goto P_0c081906;
P_0c081906: /* original 2cc8, guest PC 0x0c081906 */
if(!s->budget--) { s->failed_pc=0x0c081906u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c081908;
P_0c081908: /* original 8907, guest PC 0x0c081908 */
if(!s->budget--) { s->failed_pc=0x0c081908u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08191a; }
goto P_0c08190a;
P_0c08190a: /* original 62c3, guest PC 0x0c08190a */
if(!s->budget--) { s->failed_pc=0x0c08190au; return 0; }
r[2]=r[12];
goto P_0c08190c;
P_0c08190c: /* original e010, guest PC 0x0c08190c */
if(!s->budget--) { s->failed_pc=0x0c08190cu; return 0; }
r[0]=0x00000010u;
goto P_0c08190e;
P_0c08190e: /* original 7260, guest PC 0x0c08190e */
if(!s->budget--) { s->failed_pc=0x0c08190eu; return 0; }
r[2]+=0x00000060u;
goto P_0c081910;
P_0c081910: /* original 66f3, guest PC 0x0c081910 */
if(!s->budget--) { s->failed_pc=0x0c081910u; return 0; }
r[6]=r[15];
goto P_0c081912;
P_0c081912: /* original 6523, guest PC 0x0c081912 */
if(!s->budget--) { s->failed_pc=0x0c081912u; return 0; }
r[5]=r[2];
goto P_0c081914;
P_0c081914: /* original 0f24, guest PC 0x0c081914 */
if(!s->budget--) { s->failed_pc=0x0c081914u; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c081916;
P_0c081916: /* original b08c, guest PC 0x0c081916 */
if(!s->budget--) { s->failed_pc=0x0c081916u; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c08191au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08191au) { target=s->pc; goto dispatch; }
goto P_0c08191a;
P_0c081918: /* original 64e3, guest PC 0x0c081918 */
if(!s->budget--) { s->failed_pc=0x0c081918u; return 0; }
r[4]=r[14];
goto P_0c08191a;
P_0c08191a: /* original 64c3, guest PC 0x0c08191a */
if(!s->budget--) { s->failed_pc=0x0c08191au; return 0; }
r[4]=r[12];
goto P_0c08191c;
P_0c08191c: /* original 4408, guest PC 0x0c08191c */
if(!s->budget--) { s->failed_pc=0x0c08191cu; return 0; }
r[4]<<=2;
goto P_0c08191e;
P_0c08191e: /* original 63c3, guest PC 0x0c08191e */
if(!s->budget--) { s->failed_pc=0x0c08191eu; return 0; }
r[3]=r[12];
goto P_0c081920;
P_0c081920: /* original 5cf3, guest PC 0x0c081920 */
if(!s->budget--) { s->failed_pc=0x0c081920u; return 0; }
r[12]=read(ram,r[15]+12,4);
goto P_0c081922;
P_0c081922: /* original 343c, guest PC 0x0c081922 */
if(!s->budget--) { s->failed_pc=0x0c081922u; return 0; }
r[4]+=r[3];
goto P_0c081924;
P_0c081924: /* original 66f3, guest PC 0x0c081924 */
if(!s->budget--) { s->failed_pc=0x0c081924u; return 0; }
r[6]=r[15];
goto P_0c081926;
P_0c081926: /* original 4400, guest PC 0x0c081926 */
if(!s->budget--) { s->failed_pc=0x0c081926u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081928;
P_0c081928: /* original 3c48, guest PC 0x0c081928 */
if(!s->budget--) { s->failed_pc=0x0c081928u; return 0; }
r[12]-=r[4];
goto P_0c08192a;
P_0c08192a: /* original 7c40, guest PC 0x0c08192a */
if(!s->budget--) { s->failed_pc=0x0c08192au; return 0; }
r[12]+=0x00000040u;
goto P_0c08192c;
P_0c08192c: /* original 65c3, guest PC 0x0c08192c */
if(!s->budget--) { s->failed_pc=0x0c08192cu; return 0; }
r[5]=r[12];
goto P_0c08192e;
P_0c08192e: /* original b080, guest PC 0x0c08192e */
if(!s->budget--) { s->failed_pc=0x0c08192eu; return 0; }
target=code_base|0x0c081a32u; r[16]=code_base|0x0c081932u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081932u) { target=s->pc; goto dispatch; }
goto P_0c081932;
P_0c081930: /* original 64e3, guest PC 0x0c081930 */
if(!s->budget--) { s->failed_pc=0x0c081930u; return 0; }
r[4]=r[14];
goto P_0c081932;
P_0c081932: /* original e01c, guest PC 0x0c081932 */
if(!s->budget--) { s->failed_pc=0x0c081932u; return 0; }
r[0]=0x0000001cu;
goto P_0c081934;
P_0c081934: /* original 62f0, guest PC 0x0c081934 */
if(!s->budget--) { s->failed_pc=0x0c081934u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[2]=tmp;
goto P_0c081936;
P_0c081936: /* original 03fc, guest PC 0x0c081936 */
if(!s->budget--) { s->failed_pc=0x0c081936u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c081938;
P_0c081938: /* original 3230, guest PC 0x0c081938 */
if(!s->budget--) { s->failed_pc=0x0c081938u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c08193a;
P_0c08193a: /* original 890a, guest PC 0x0c08193a */
if(!s->budget--) { s->failed_pc=0x0c08193au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081952; }
goto P_0c08193c;
P_0c08193c: /* original e01c, guest PC 0x0c08193c */
if(!s->budget--) { s->failed_pc=0x0c08193cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08193e;
P_0c08193e: /* original 61f3, guest PC 0x0c08193e */
if(!s->budget--) { s->failed_pc=0x0c08193eu; return 0; }
r[1]=r[15];
goto P_0c081940;
P_0c081940: /* original 02fc, guest PC 0x0c081940 */
if(!s->budget--) { s->failed_pc=0x0c081940u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c081942;
P_0c081942: /* original e01c, guest PC 0x0c081942 */
if(!s->budget--) { s->failed_pc=0x0c081942u; return 0; }
r[0]=0x0000001cu;
goto P_0c081944;
P_0c081944: /* original 711c, guest PC 0x0c081944 */
if(!s->budget--) { s->failed_pc=0x0c081944u; return 0; }
r[1]+=0x0000001cu;
goto P_0c081946;
P_0c081946: /* original 7201, guest PC 0x0c081946 */
if(!s->budget--) { s->failed_pc=0x0c081946u; return 0; }
r[2]+=0x00000001u;
goto P_0c081948;
P_0c081948: /* original 0f24, guest PC 0x0c081948 */
if(!s->budget--) { s->failed_pc=0x0c081948u; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c08194a;
P_0c08194a: /* original e01c, guest PC 0x0c08194a */
if(!s->budget--) { s->failed_pc=0x0c08194au; return 0; }
r[0]=0x0000001cu;
goto P_0c08194c;
P_0c08194c: /* original 00fc, guest PC 0x0c08194c */
if(!s->budget--) { s->failed_pc=0x0c08194cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c08194e;
P_0c08194e: /* original c90f, guest PC 0x0c08194e */
if(!s->budget--) { s->failed_pc=0x0c08194eu; return 0; }
r[0]&=15u;
goto P_0c081950;
P_0c081950: /* original 2100, guest PC 0x0c081950 */
if(!s->budget--) { s->failed_pc=0x0c081950u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c081952;
P_0c081952: /* original 903f, guest PC 0x0c081952 */
if(!s->budget--) { s->failed_pc=0x0c081952u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0819d4u,2);
goto P_0c081954;
P_0c081954: /* original 63f0, guest PC 0x0c081954 */
if(!s->budget--) { s->failed_pc=0x0c081954u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c081956;
P_0c081956: /* original 0b34, guest PC 0x0c081956 */
if(!s->budget--) { s->failed_pc=0x0c081956u; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c081958;
P_0c081958: /* original e01c, guest PC 0x0c081958 */
if(!s->budget--) { s->failed_pc=0x0c081958u; return 0; }
r[0]=0x0000001cu;
goto P_0c08195a;
P_0c08195a: /* original 02fc, guest PC 0x0c08195a */
if(!s->budget--) { s->failed_pc=0x0c08195au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c08195c;
P_0c08195c: /* original 903b, guest PC 0x0c08195c */
if(!s->budget--) { s->failed_pc=0x0c08195cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0819d6u,2);
goto P_0c08195e;
P_0c08195e: /* original 0b24, guest PC 0x0c08195e */
if(!s->budget--) { s->failed_pc=0x0c08195eu; return 0; }
write(ram,r[11]+r[0],r[2],1);
goto P_0c081960;
P_0c081960: /* original 70eb, guest PC 0x0c081960 */
if(!s->budget--) { s->failed_pc=0x0c081960u; return 0; }
r[0]+=0xffffffebu;
goto P_0c081962;
P_0c081962: /* original 0bd6, guest PC 0x0c081962 */
if(!s->budget--) { s->failed_pc=0x0c081962u; return 0; }
write(ram,r[11]+r[0],r[13],4);
goto P_0c081964;
P_0c081964: /* original 7f24, guest PC 0x0c081964 */
if(!s->budget--) { s->failed_pc=0x0c081964u; return 0; }
r[15]+=0x00000024u;
goto P_0c081966;
P_0c081966: /* original 4f26, guest PC 0x0c081966 */
if(!s->budget--) { s->failed_pc=0x0c081966u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081968;
P_0c081968: /* original 68f6, guest PC 0x0c081968 */
if(!s->budget--) { s->failed_pc=0x0c081968u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08196a;
P_0c08196a: /* original 69f6, guest PC 0x0c08196a */
if(!s->budget--) { s->failed_pc=0x0c08196au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08196c;
P_0c08196c: /* original 6af6, guest PC 0x0c08196c */
if(!s->budget--) { s->failed_pc=0x0c08196cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08196e;
P_0c08196e: /* original 6bf6, guest PC 0x0c08196e */
if(!s->budget--) { s->failed_pc=0x0c08196eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c081970;
P_0c081970: /* original 6cf6, guest PC 0x0c081970 */
if(!s->budget--) { s->failed_pc=0x0c081970u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c081972;
P_0c081972: /* original 6df6, guest PC 0x0c081972 */
if(!s->budget--) { s->failed_pc=0x0c081972u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c081974;
P_0c081974: /* original 000b, guest PC 0x0c081974 */
if(!s->budget--) { s->failed_pc=0x0c081974u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081976: /* original 6ef6, guest PC 0x0c081976 */
if(!s->budget--) { s->failed_pc=0x0c081976u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c081978u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081978u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
