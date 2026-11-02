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
int vf3_away_batch121_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c061910u: goto P_0c061910;
case 0x0c061912u: goto P_0c061912;
case 0x0c061914u: goto P_0c061914;
case 0x0c061916u: goto P_0c061916;
case 0x0c061918u: goto P_0c061918;
case 0x0c06191au: goto P_0c06191a;
case 0x0c06191cu: goto P_0c06191c;
case 0x0c06191eu: goto P_0c06191e;
case 0x0c061920u: goto P_0c061920;
case 0x0c061922u: goto P_0c061922;
case 0x0c061924u: goto P_0c061924;
case 0x0c061926u: goto P_0c061926;
case 0x0c061928u: goto P_0c061928;
case 0x0c06192au: goto P_0c06192a;
case 0x0c06192cu: goto P_0c06192c;
case 0x0c06192eu: goto P_0c06192e;
case 0x0c061930u: goto P_0c061930;
case 0x0c061932u: goto P_0c061932;
case 0x0c061934u: goto P_0c061934;
case 0x0c061936u: goto P_0c061936;
case 0x0c061938u: goto P_0c061938;
case 0x0c06193au: goto P_0c06193a;
case 0x0c06193cu: goto P_0c06193c;
case 0x0c06193eu: goto P_0c06193e;
case 0x0c061940u: goto P_0c061940;
case 0x0c061942u: goto P_0c061942;
case 0x0c061944u: goto P_0c061944;
case 0x0c061946u: goto P_0c061946;
case 0x0c061948u: goto P_0c061948;
case 0x0c06194au: goto P_0c06194a;
case 0x0c06194cu: goto P_0c06194c;
case 0x0c06194eu: goto P_0c06194e;
case 0x0c061950u: goto P_0c061950;
case 0x0c061952u: goto P_0c061952;
case 0x0c061954u: goto P_0c061954;
case 0x0c061956u: goto P_0c061956;
case 0x0c061958u: goto P_0c061958;
case 0x0c06195au: goto P_0c06195a;
case 0x0c06195cu: goto P_0c06195c;
case 0x0c06195eu: goto P_0c06195e;
case 0x0c061960u: goto P_0c061960;
case 0x0c061962u: goto P_0c061962;
case 0x0c061964u: goto P_0c061964;
case 0x0c061966u: goto P_0c061966;
case 0x0c061968u: goto P_0c061968;
case 0x0c06196au: goto P_0c06196a;
case 0x0c06196cu: goto P_0c06196c;
case 0x0c06196eu: goto P_0c06196e;
case 0x0c061970u: goto P_0c061970;
case 0x0c061972u: goto P_0c061972;
case 0x0c061974u: goto P_0c061974;
case 0x0c061976u: goto P_0c061976;
case 0x0c061978u: goto P_0c061978;
case 0x0c06197au: goto P_0c06197a;
case 0x0c06197cu: goto P_0c06197c;
case 0x0c06197eu: goto P_0c06197e;
case 0x0c061980u: goto P_0c061980;
case 0x0c061982u: goto P_0c061982;
case 0x0c061984u: goto P_0c061984;
case 0x0c061986u: goto P_0c061986;
case 0x0c061988u: goto P_0c061988;
case 0x0c06198au: goto P_0c06198a;
case 0x0c06198cu: goto P_0c06198c;
case 0x0c06198eu: goto P_0c06198e;
case 0x0c061990u: goto P_0c061990;
case 0x0c061992u: goto P_0c061992;
case 0x0c061994u: goto P_0c061994;
case 0x0c061996u: goto P_0c061996;
case 0x0c061998u: goto P_0c061998;
case 0x0c06199au: goto P_0c06199a;
case 0x0c06199cu: goto P_0c06199c;
case 0x0c06199eu: goto P_0c06199e;
case 0x0c0619a0u: goto P_0c0619a0;
case 0x0c0619a2u: goto P_0c0619a2;
case 0x0c0619a4u: goto P_0c0619a4;
case 0x0c0619a6u: goto P_0c0619a6;
case 0x0c0619a8u: goto P_0c0619a8;
case 0x0c0619aau: goto P_0c0619aa;
case 0x0c0619acu: goto P_0c0619ac;
case 0x0c0619aeu: goto P_0c0619ae;
case 0x0c0619b0u: goto P_0c0619b0;
case 0x0c0619b2u: goto P_0c0619b2;
case 0x0c0619b4u: goto P_0c0619b4;
case 0x0c0619b6u: goto P_0c0619b6;
case 0x0c0619b8u: goto P_0c0619b8;
case 0x0c0619bau: goto P_0c0619ba;
case 0x0c0619bcu: goto P_0c0619bc;
case 0x0c0619beu: goto P_0c0619be;
case 0x0c0619c0u: goto P_0c0619c0;
case 0x0c0619c2u: goto P_0c0619c2;
case 0x0c0619c4u: goto P_0c0619c4;
case 0x0c0619c6u: goto P_0c0619c6;
case 0x0c0619c8u: goto P_0c0619c8;
case 0x0c0619cau: goto P_0c0619ca;
case 0x0c0619ccu: goto P_0c0619cc;
case 0x0c0619ceu: goto P_0c0619ce;
case 0x0c0619d0u: goto P_0c0619d0;
case 0x0c0619d2u: goto P_0c0619d2;
case 0x0c0619d4u: goto P_0c0619d4;
case 0x0c0619d6u: goto P_0c0619d6;
case 0x0c0619d8u: goto P_0c0619d8;
case 0x0c0619dau: goto P_0c0619da;
case 0x0c0619dcu: goto P_0c0619dc;
case 0x0c0619deu: goto P_0c0619de;
case 0x0c0619e0u: goto P_0c0619e0;
case 0x0c0619e2u: goto P_0c0619e2;
case 0x0c0619e4u: goto P_0c0619e4;
case 0x0c0619e6u: goto P_0c0619e6;
case 0x0c0619e8u: goto P_0c0619e8;
case 0x0c0619eau: goto P_0c0619ea;
case 0x0c0619ecu: goto P_0c0619ec;
case 0x0c0619eeu: goto P_0c0619ee;
case 0x0c0619f0u: goto P_0c0619f0;
case 0x0c0619f2u: goto P_0c0619f2;
case 0x0c0619f4u: goto P_0c0619f4;
case 0x0c0619f6u: goto P_0c0619f6;
case 0x0c0619f8u: goto P_0c0619f8;
case 0x0c0619fau: goto P_0c0619fa;
case 0x0c0619fcu: goto P_0c0619fc;
case 0x0c0619feu: goto P_0c0619fe;
case 0x0c061a00u: goto P_0c061a00;
case 0x0c061a02u: goto P_0c061a02;
case 0x0c061a04u: goto P_0c061a04;
case 0x0c061a06u: goto P_0c061a06;
case 0x0c061a08u: goto P_0c061a08;
case 0x0c0620e4u: goto P_0c0620e4;
case 0x0c0620e6u: goto P_0c0620e6;
case 0x0c0620e8u: goto P_0c0620e8;
case 0x0c0620eau: goto P_0c0620ea;
case 0x0c0620ecu: goto P_0c0620ec;
case 0x0c0620eeu: goto P_0c0620ee;
case 0x0c0620f0u: goto P_0c0620f0;
case 0x0c0620f2u: goto P_0c0620f2;
case 0x0c0620f4u: goto P_0c0620f4;
case 0x0c0620f6u: goto P_0c0620f6;
case 0x0c0620f8u: goto P_0c0620f8;
case 0x0c0620fau: goto P_0c0620fa;
case 0x0c0620fcu: goto P_0c0620fc;
case 0x0c0620feu: goto P_0c0620fe;
case 0x0c062100u: goto P_0c062100;
case 0x0c062102u: goto P_0c062102;
case 0x0c062104u: goto P_0c062104;
case 0x0c062106u: goto P_0c062106;
case 0x0c062108u: goto P_0c062108;
case 0x0c06210au: goto P_0c06210a;
case 0x0c06210cu: goto P_0c06210c;
case 0x0c06210eu: goto P_0c06210e;
case 0x0c062110u: goto P_0c062110;
case 0x0c062112u: goto P_0c062112;
case 0x0c062114u: goto P_0c062114;
case 0x0c062116u: goto P_0c062116;
case 0x0c062118u: goto P_0c062118;
case 0x0c06211au: goto P_0c06211a;
case 0x0c06211cu: goto P_0c06211c;
case 0x0c06211eu: goto P_0c06211e;
case 0x0c062120u: goto P_0c062120;
case 0x0c062122u: goto P_0c062122;
case 0x0c062124u: goto P_0c062124;
case 0x0c062126u: goto P_0c062126;
case 0x0c062128u: goto P_0c062128;
case 0x0c06212au: goto P_0c06212a;
case 0x0c06212cu: goto P_0c06212c;
case 0x0c06212eu: goto P_0c06212e;
case 0x0c062130u: goto P_0c062130;
case 0x0c062132u: goto P_0c062132;
case 0x0c062134u: goto P_0c062134;
case 0x0c062136u: goto P_0c062136;
case 0x0c062138u: goto P_0c062138;
case 0x0c06213au: goto P_0c06213a;
case 0x0c06213cu: goto P_0c06213c;
case 0x0c06213eu: goto P_0c06213e;
case 0x0c062140u: goto P_0c062140;
case 0x0c062142u: goto P_0c062142;
case 0x0c062144u: goto P_0c062144;
case 0x0c062146u: goto P_0c062146;
case 0x0c062148u: goto P_0c062148;
case 0x0c06214au: goto P_0c06214a;
case 0x0c06214cu: goto P_0c06214c;
case 0x0c06214eu: goto P_0c06214e;
case 0x0c062150u: goto P_0c062150;
case 0x0c062152u: goto P_0c062152;
case 0x0c062154u: goto P_0c062154;
case 0x0c062156u: goto P_0c062156;
case 0x0c062158u: goto P_0c062158;
case 0x0c06215au: goto P_0c06215a;
case 0x0c06215cu: goto P_0c06215c;
case 0x0c06215eu: goto P_0c06215e;
case 0x0c062160u: goto P_0c062160;
case 0x0c062162u: goto P_0c062162;
case 0x0c062164u: goto P_0c062164;
case 0x0c062166u: goto P_0c062166;
case 0x0c062168u: goto P_0c062168;
case 0x0c06216au: goto P_0c06216a;
case 0x0c06216cu: goto P_0c06216c;
case 0x0c06216eu: goto P_0c06216e;
case 0x0c062170u: goto P_0c062170;
case 0x0c062172u: goto P_0c062172;
case 0x0c062174u: goto P_0c062174;
case 0x0c062176u: goto P_0c062176;
case 0x0c062178u: goto P_0c062178;
case 0x0c06217au: goto P_0c06217a;
case 0x0c06217cu: goto P_0c06217c;
case 0x0c06217eu: goto P_0c06217e;
case 0x0c062180u: goto P_0c062180;
case 0x0c062182u: goto P_0c062182;
case 0x0c062184u: goto P_0c062184;
case 0x0c062186u: goto P_0c062186;
case 0x0c062188u: goto P_0c062188;
case 0x0c06218au: goto P_0c06218a;
case 0x0c06218cu: goto P_0c06218c;
case 0x0c06218eu: goto P_0c06218e;
case 0x0c062190u: goto P_0c062190;
case 0x0c062192u: goto P_0c062192;
case 0x0c062194u: goto P_0c062194;
case 0x0c062196u: goto P_0c062196;
case 0x0c062198u: goto P_0c062198;
case 0x0c06219au: goto P_0c06219a;
case 0x0c06219cu: goto P_0c06219c;
case 0x0c06219eu: goto P_0c06219e;
case 0x0c0621a0u: goto P_0c0621a0;
case 0x0c0621a2u: goto P_0c0621a2;
case 0x0c0621a4u: goto P_0c0621a4;
case 0x0c0621a6u: goto P_0c0621a6;
case 0x0c0621b4u: goto P_0c0621b4;
case 0x0c0621b6u: goto P_0c0621b6;
case 0x0c0621b8u: goto P_0c0621b8;
case 0x0c0621bau: goto P_0c0621ba;
case 0x0c0621bcu: goto P_0c0621bc;
case 0x0c0621beu: goto P_0c0621be;
case 0x0c0621c0u: goto P_0c0621c0;
case 0x0c0621c2u: goto P_0c0621c2;
case 0x0c0621c4u: goto P_0c0621c4;
case 0x0c0621c6u: goto P_0c0621c6;
case 0x0c0621c8u: goto P_0c0621c8;
case 0x0c0621cau: goto P_0c0621ca;
case 0x0c0621ccu: goto P_0c0621cc;
case 0x0c0621ceu: goto P_0c0621ce;
case 0x0c0621d0u: goto P_0c0621d0;
case 0x0c0621d2u: goto P_0c0621d2;
case 0x0c0621d4u: goto P_0c0621d4;
case 0x0c0621d6u: goto P_0c0621d6;
case 0x0c0621d8u: goto P_0c0621d8;
case 0x0c0621dau: goto P_0c0621da;
case 0x0c0621dcu: goto P_0c0621dc;
case 0x0c0621deu: goto P_0c0621de;
case 0x0c0621e0u: goto P_0c0621e0;
case 0x0c0621e2u: goto P_0c0621e2;
case 0x0c0621e4u: goto P_0c0621e4;
case 0x0c0621e6u: goto P_0c0621e6;
case 0x0c0621e8u: goto P_0c0621e8;
case 0x0c0621eau: goto P_0c0621ea;
case 0x0c0621ecu: goto P_0c0621ec;
case 0x0c0621eeu: goto P_0c0621ee;
case 0x0c0621f0u: goto P_0c0621f0;
case 0x0c0621f2u: goto P_0c0621f2;
case 0x0c0621f4u: goto P_0c0621f4;
case 0x0c0621f6u: goto P_0c0621f6;
case 0x0c0621f8u: goto P_0c0621f8;
case 0x0c0621fau: goto P_0c0621fa;
case 0x0c0621fcu: goto P_0c0621fc;
case 0x0c0621feu: goto P_0c0621fe;
case 0x0c062200u: goto P_0c062200;
case 0x0c062202u: goto P_0c062202;
case 0x0c062204u: goto P_0c062204;
case 0x0c062206u: goto P_0c062206;
case 0x0c062208u: goto P_0c062208;
case 0x0c06220au: goto P_0c06220a;
case 0x0c06220cu: goto P_0c06220c;
case 0x0c06220eu: goto P_0c06220e;
case 0x0c062210u: goto P_0c062210;
case 0x0c062212u: goto P_0c062212;
case 0x0c062214u: goto P_0c062214;
case 0x0c062216u: goto P_0c062216;
case 0x0c062218u: goto P_0c062218;
case 0x0c06221au: goto P_0c06221a;
case 0x0c06221cu: goto P_0c06221c;
case 0x0c06221eu: goto P_0c06221e;
case 0x0c062220u: goto P_0c062220;
case 0x0c062222u: goto P_0c062222;
case 0x0c062224u: goto P_0c062224;
case 0x0c062226u: goto P_0c062226;
case 0x0c062228u: goto P_0c062228;
case 0x0c06222au: goto P_0c06222a;
case 0x0c06222cu: goto P_0c06222c;
case 0x0c06222eu: goto P_0c06222e;
case 0x0c062230u: goto P_0c062230;
case 0x0c062232u: goto P_0c062232;
case 0x0c062234u: goto P_0c062234;
case 0x0c062236u: goto P_0c062236;
case 0x0c062238u: goto P_0c062238;
case 0x0c06223au: goto P_0c06223a;
case 0x0c06223cu: goto P_0c06223c;
case 0x0c06223eu: goto P_0c06223e;
case 0x0c062240u: goto P_0c062240;
case 0x0c062242u: goto P_0c062242;
case 0x0c062244u: goto P_0c062244;
case 0x0c062246u: goto P_0c062246;
case 0x0c062248u: goto P_0c062248;
case 0x0c06224au: goto P_0c06224a;
case 0x0c06224cu: goto P_0c06224c;
case 0x0c06224eu: goto P_0c06224e;
case 0x0c062250u: goto P_0c062250;
case 0x0c062252u: goto P_0c062252;
case 0x0c062254u: goto P_0c062254;
case 0x0c062256u: goto P_0c062256;
case 0x0c062258u: goto P_0c062258;
case 0x0c06225au: goto P_0c06225a;
case 0x0c06225cu: goto P_0c06225c;
case 0x0c06225eu: goto P_0c06225e;
case 0x0c062260u: goto P_0c062260;
case 0x0c062262u: goto P_0c062262;
case 0x0c062264u: goto P_0c062264;
case 0x0c062266u: goto P_0c062266;
case 0x0c062268u: goto P_0c062268;
case 0x0c06226au: goto P_0c06226a;
case 0x0c06226cu: goto P_0c06226c;
case 0x0c06226eu: goto P_0c06226e;
case 0x0c062270u: goto P_0c062270;
case 0x0c062272u: goto P_0c062272;
case 0x0c062274u: goto P_0c062274;
case 0x0c062276u: goto P_0c062276;
case 0x0c062278u: goto P_0c062278;
case 0x0c06227au: goto P_0c06227a;
case 0x0c06227cu: goto P_0c06227c;
case 0x0c06227eu: goto P_0c06227e;
case 0x0c062280u: goto P_0c062280;
case 0x0c062282u: goto P_0c062282;
case 0x0c062284u: goto P_0c062284;
case 0x0c062286u: goto P_0c062286;
case 0x0c062288u: goto P_0c062288;
case 0x0c06228au: goto P_0c06228a;
case 0x0c06228cu: goto P_0c06228c;
case 0x0c06228eu: goto P_0c06228e;
case 0x0c062290u: goto P_0c062290;
case 0x0c062292u: goto P_0c062292;
case 0x0c062294u: goto P_0c062294;
case 0x0c062296u: goto P_0c062296;
case 0x0c062298u: goto P_0c062298;
default: return vf3_matrix_family(target,s,ram);
}
P_0c061910: /* original 2fe6, guest PC 0x0c061910 */
if(!s->budget--) { s->failed_pc=0x0c061910u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061912;
P_0c061912: /* original ee00, guest PC 0x0c061912 */
if(!s->budget--) { s->failed_pc=0x0c061912u; return 0; }
r[14]=0x00000000u;
goto P_0c061914;
P_0c061914: /* original 2fd6, guest PC 0x0c061914 */
if(!s->budget--) { s->failed_pc=0x0c061914u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061916;
P_0c061916: /* original 2fc6, guest PC 0x0c061916 */
if(!s->budget--) { s->failed_pc=0x0c061916u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061918;
P_0c061918: /* original dc3c, guest PC 0x0c061918 */
if(!s->budget--) { s->failed_pc=0x0c061918u; return 0; }
r[12]=read(ram,0x0c061a0cu,4);
goto P_0c06191a;
P_0c06191a: /* original 7ffc, guest PC 0x0c06191a */
if(!s->budget--) { s->failed_pc=0x0c06191au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06191c;
P_0c06191c: /* original 56c2, guest PC 0x0c06191c */
if(!s->budget--) { s->failed_pc=0x0c06191cu; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c06191e;
P_0c06191e: /* original 2668, guest PC 0x0c06191e */
if(!s->budget--) { s->failed_pc=0x0c06191eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061920;
P_0c061920: /* original 8d07, guest PC 0x0c061920 */
if(!s->budget--) { s->failed_pc=0x0c061920u; return 0; }
cond=r[17]&1u;
r[7]=r[14];
if(cond) { goto P_0c061932; }
goto P_0c061924;
P_0c061922: /* original 67e3, guest PC 0x0c061922 */
if(!s->budget--) { s->failed_pc=0x0c061922u; return 0; }
r[7]=r[14];
goto P_0c061924;
P_0c061924: /* original 5264, guest PC 0x0c061924 */
if(!s->budget--) { s->failed_pc=0x0c061924u; return 0; }
r[2]=read(ram,r[6]+16,4);
goto P_0c061926;
P_0c061926: /* original 3277, guest PC 0x0c061926 */
if(!s->budget--) { s->failed_pc=0x0c061926u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[7])!=0);
goto P_0c061928;
P_0c061928: /* original 8b00, guest PC 0x0c061928 */
if(!s->budget--) { s->failed_pc=0x0c061928u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06192c; }
goto P_0c06192a;
P_0c06192a: /* original 5764, guest PC 0x0c06192a */
if(!s->budget--) { s->failed_pc=0x0c06192au; return 0; }
r[7]=read(ram,r[6]+16,4);
goto P_0c06192c;
P_0c06192c: /* original 5662, guest PC 0x0c06192c */
if(!s->budget--) { s->failed_pc=0x0c06192cu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c06192e;
P_0c06192e: /* original 2668, guest PC 0x0c06192e */
if(!s->budget--) { s->failed_pc=0x0c06192eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061930;
P_0c061930: /* original 8bf8, guest PC 0x0c061930 */
if(!s->budget--) { s->failed_pc=0x0c061930u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061924; }
goto P_0c061932;
P_0c061932: /* original 66c2, guest PC 0x0c061932 */
if(!s->budget--) { s->failed_pc=0x0c061932u; return 0; }
tmp=read(ram,r[12],4);
r[6]=tmp;
goto P_0c061934;
P_0c061934: /* original 2668, guest PC 0x0c061934 */
if(!s->budget--) { s->failed_pc=0x0c061934u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061936;
P_0c061936: /* original 8d0b, guest PC 0x0c061936 */
if(!s->budget--) { s->failed_pc=0x0c061936u; return 0; }
cond=r[17]&1u;
r[13]=0x00000004u;
if(cond) { goto P_0c061950; }
goto P_0c06193a;
P_0c061938: /* original ed04, guest PC 0x0c061938 */
if(!s->budget--) { s->failed_pc=0x0c061938u; return 0; }
r[13]=0x00000004u;
goto P_0c06193a;
P_0c06193a: /* original 6261, guest PC 0x0c06193a */
if(!s->budget--) { s->failed_pc=0x0c06193au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[2]=tmp;
goto P_0c06193c;
P_0c06193c: /* original 622d, guest PC 0x0c06193c */
if(!s->budget--) { s->failed_pc=0x0c06193cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c06193e;
P_0c06193e: /* original 22d8, guest PC 0x0c06193e */
if(!s->budget--) { s->failed_pc=0x0c06193eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c061940;
P_0c061940: /* original 8b03, guest PC 0x0c061940 */
if(!s->budget--) { s->failed_pc=0x0c061940u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06194a; }
goto P_0c061942;
P_0c061942: /* original 5164, guest PC 0x0c061942 */
if(!s->budget--) { s->failed_pc=0x0c061942u; return 0; }
r[1]=read(ram,r[6]+16,4);
goto P_0c061944;
P_0c061944: /* original 3177, guest PC 0x0c061944 */
if(!s->budget--) { s->failed_pc=0x0c061944u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[7])!=0);
goto P_0c061946;
P_0c061946: /* original 8b00, guest PC 0x0c061946 */
if(!s->budget--) { s->failed_pc=0x0c061946u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06194a; }
goto P_0c061948;
P_0c061948: /* original 5764, guest PC 0x0c061948 */
if(!s->budget--) { s->failed_pc=0x0c061948u; return 0; }
r[7]=read(ram,r[6]+16,4);
goto P_0c06194a;
P_0c06194a: /* original 5662, guest PC 0x0c06194a */
if(!s->budget--) { s->failed_pc=0x0c06194au; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c06194c;
P_0c06194c: /* original 2668, guest PC 0x0c06194c */
if(!s->budget--) { s->failed_pc=0x0c06194cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06194e;
P_0c06194e: /* original 8bf4, guest PC 0x0c06194e */
if(!s->budget--) { s->failed_pc=0x0c06194eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06193a; }
goto P_0c061950;
P_0c061950: /* original 66c3, guest PC 0x0c061950 */
if(!s->budget--) { s->failed_pc=0x0c061950u; return 0; }
r[6]=r[12];
goto P_0c061952;
P_0c061952: /* original 7614, guest PC 0x0c061952 */
if(!s->budget--) { s->failed_pc=0x0c061952u; return 0; }
r[6]+=0x00000014u;
goto P_0c061954;
P_0c061954: /* original 2f62, guest PC 0x0c061954 */
if(!s->budget--) { s->failed_pc=0x0c061954u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c061956;
P_0c061956: /* original 5662, guest PC 0x0c061956 */
if(!s->budget--) { s->failed_pc=0x0c061956u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c061958;
P_0c061958: /* original 2668, guest PC 0x0c061958 */
if(!s->budget--) { s->failed_pc=0x0c061958u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06195a;
P_0c06195a: /* original 8906, guest PC 0x0c06195a */
if(!s->budget--) { s->failed_pc=0x0c06195au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06196a; }
goto P_0c06195c;
P_0c06195c: /* original 5264, guest PC 0x0c06195c */
if(!s->budget--) { s->failed_pc=0x0c06195cu; return 0; }
r[2]=read(ram,r[6]+16,4);
goto P_0c06195e;
P_0c06195e: /* original 32e7, guest PC 0x0c06195e */
if(!s->budget--) { s->failed_pc=0x0c06195eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[14])!=0);
goto P_0c061960;
P_0c061960: /* original 8b00, guest PC 0x0c061960 */
if(!s->budget--) { s->failed_pc=0x0c061960u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061964; }
goto P_0c061962;
P_0c061962: /* original 5e64, guest PC 0x0c061962 */
if(!s->budget--) { s->failed_pc=0x0c061962u; return 0; }
r[14]=read(ram,r[6]+16,4);
goto P_0c061964;
P_0c061964: /* original 5662, guest PC 0x0c061964 */
if(!s->budget--) { s->failed_pc=0x0c061964u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c061966;
P_0c061966: /* original 2668, guest PC 0x0c061966 */
if(!s->budget--) { s->failed_pc=0x0c061966u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061968;
P_0c061968: /* original 8bf8, guest PC 0x0c061968 */
if(!s->budget--) { s->failed_pc=0x0c061968u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06195c; }
goto P_0c06196a;
P_0c06196a: /* original 66f2, guest PC 0x0c06196a */
if(!s->budget--) { s->failed_pc=0x0c06196au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c06196c;
P_0c06196c: /* original 6662, guest PC 0x0c06196c */
if(!s->budget--) { s->failed_pc=0x0c06196cu; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c06196e;
P_0c06196e: /* original 2668, guest PC 0x0c06196e */
if(!s->budget--) { s->failed_pc=0x0c06196eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061970;
P_0c061970: /* original 890a, guest PC 0x0c061970 */
if(!s->budget--) { s->failed_pc=0x0c061970u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061988; }
goto P_0c061972;
P_0c061972: /* original 6261, guest PC 0x0c061972 */
if(!s->budget--) { s->failed_pc=0x0c061972u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[2]=tmp;
goto P_0c061974;
P_0c061974: /* original 622d, guest PC 0x0c061974 */
if(!s->budget--) { s->failed_pc=0x0c061974u; return 0; }
r[2]=r[2]&65535u;
goto P_0c061976;
P_0c061976: /* original 22d8, guest PC 0x0c061976 */
if(!s->budget--) { s->failed_pc=0x0c061976u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c061978;
P_0c061978: /* original 8b03, guest PC 0x0c061978 */
if(!s->budget--) { s->failed_pc=0x0c061978u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061982; }
goto P_0c06197a;
P_0c06197a: /* original 5164, guest PC 0x0c06197a */
if(!s->budget--) { s->failed_pc=0x0c06197au; return 0; }
r[1]=read(ram,r[6]+16,4);
goto P_0c06197c;
P_0c06197c: /* original 31e7, guest PC 0x0c06197c */
if(!s->budget--) { s->failed_pc=0x0c06197cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[14])!=0);
goto P_0c06197e;
P_0c06197e: /* original 8b00, guest PC 0x0c06197e */
if(!s->budget--) { s->failed_pc=0x0c06197eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061982; }
goto P_0c061980;
P_0c061980: /* original 5e64, guest PC 0x0c061980 */
if(!s->budget--) { s->failed_pc=0x0c061980u; return 0; }
r[14]=read(ram,r[6]+16,4);
goto P_0c061982;
P_0c061982: /* original 5662, guest PC 0x0c061982 */
if(!s->budget--) { s->failed_pc=0x0c061982u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c061984;
P_0c061984: /* original 2668, guest PC 0x0c061984 */
if(!s->budget--) { s->failed_pc=0x0c061984u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061986;
P_0c061986: /* original 8bf4, guest PC 0x0c061986 */
if(!s->budget--) { s->failed_pc=0x0c061986u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061972; }
goto P_0c061988;
P_0c061988: /* original 2472, guest PC 0x0c061988 */
if(!s->budget--) { s->failed_pc=0x0c061988u; return 0; }
write(ram,r[4],r[7],4);
goto P_0c06198a;
P_0c06198a: /* original e000, guest PC 0x0c06198a */
if(!s->budget--) { s->failed_pc=0x0c06198au; return 0; }
r[0]=0x00000000u;
goto P_0c06198c;
P_0c06198c: /* original 25e2, guest PC 0x0c06198c */
if(!s->budget--) { s->failed_pc=0x0c06198cu; return 0; }
write(ram,r[5],r[14],4);
goto P_0c06198e;
P_0c06198e: /* original 7f04, guest PC 0x0c06198e */
if(!s->budget--) { s->failed_pc=0x0c06198eu; return 0; }
r[15]+=0x00000004u;
goto P_0c061990;
P_0c061990: /* original 6cf6, guest PC 0x0c061990 */
if(!s->budget--) { s->failed_pc=0x0c061990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c061992;
P_0c061992: /* original 6df6, guest PC 0x0c061992 */
if(!s->budget--) { s->failed_pc=0x0c061992u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061994;
P_0c061994: /* original 000b, guest PC 0x0c061994 */
if(!s->budget--) { s->failed_pc=0x0c061994u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061996: /* original 6ef6, guest PC 0x0c061996 */
if(!s->budget--) { s->failed_pc=0x0c061996u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c061998;
P_0c061998: /* original 2fe6, guest PC 0x0c061998 */
if(!s->budget--) { s->failed_pc=0x0c061998u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06199a;
P_0c06199a: /* original 2fd6, guest PC 0x0c06199a */
if(!s->budget--) { s->failed_pc=0x0c06199au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06199c;
P_0c06199c: /* original 4f22, guest PC 0x0c06199c */
if(!s->budget--) { s->failed_pc=0x0c06199cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06199e;
P_0c06199e: /* original de1b, guest PC 0x0c06199e */
if(!s->budget--) { s->failed_pc=0x0c06199eu; return 0; }
r[14]=read(ram,0x0c061a0cu,4);
goto P_0c0619a0;
P_0c0619a0: /* original 65e3, guest PC 0x0c0619a0 */
if(!s->budget--) { s->failed_pc=0x0c0619a0u; return 0; }
r[5]=r[14];
goto P_0c0619a2;
P_0c0619a2: /* original 7504, guest PC 0x0c0619a2 */
if(!s->budget--) { s->failed_pc=0x0c0619a2u; return 0; }
r[5]+=0x00000004u;
goto P_0c0619a4;
P_0c0619a4: /* original b62e, guest PC 0x0c0619a4 */
if(!s->budget--) { s->failed_pc=0x0c0619a4u; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619a8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619a8u) { target=s->pc; goto dispatch; }
goto P_0c0619a8;
P_0c0619a6: /* original 64e3, guest PC 0x0c0619a6 */
if(!s->budget--) { s->failed_pc=0x0c0619a6u; return 0; }
r[4]=r[14];
goto P_0c0619a8;
P_0c0619a8: /* original dd19, guest PC 0x0c0619a8 */
if(!s->budget--) { s->failed_pc=0x0c0619a8u; return 0; }
r[13]=read(ram,0x0c061a10u,4);
goto P_0c0619aa;
P_0c0619aa: /* original 65d3, guest PC 0x0c0619aa */
if(!s->budget--) { s->failed_pc=0x0c0619aau; return 0; }
r[5]=r[13];
goto P_0c0619ac;
P_0c0619ac: /* original 7504, guest PC 0x0c0619ac */
if(!s->budget--) { s->failed_pc=0x0c0619acu; return 0; }
r[5]+=0x00000004u;
goto P_0c0619ae;
P_0c0619ae: /* original b629, guest PC 0x0c0619ae */
if(!s->budget--) { s->failed_pc=0x0c0619aeu; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619b2u) { target=s->pc; goto dispatch; }
goto P_0c0619b2;
P_0c0619b0: /* original 64d3, guest PC 0x0c0619b0 */
if(!s->budget--) { s->failed_pc=0x0c0619b0u; return 0; }
r[4]=r[13];
goto P_0c0619b2;
P_0c0619b2: /* original 65e3, guest PC 0x0c0619b2 */
if(!s->budget--) { s->failed_pc=0x0c0619b2u; return 0; }
r[5]=r[14];
goto P_0c0619b4;
P_0c0619b4: /* original 750c, guest PC 0x0c0619b4 */
if(!s->budget--) { s->failed_pc=0x0c0619b4u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619b6;
P_0c0619b6: /* original 64e3, guest PC 0x0c0619b6 */
if(!s->budget--) { s->failed_pc=0x0c0619b6u; return 0; }
r[4]=r[14];
goto P_0c0619b8;
P_0c0619b8: /* original b624, guest PC 0x0c0619b8 */
if(!s->budget--) { s->failed_pc=0x0c0619b8u; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619bcu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619bcu) { target=s->pc; goto dispatch; }
goto P_0c0619bc;
P_0c0619ba: /* original 7408, guest PC 0x0c0619ba */
if(!s->budget--) { s->failed_pc=0x0c0619bau; return 0; }
r[4]+=0x00000008u;
goto P_0c0619bc;
P_0c0619bc: /* original 65d3, guest PC 0x0c0619bc */
if(!s->budget--) { s->failed_pc=0x0c0619bcu; return 0; }
r[5]=r[13];
goto P_0c0619be;
P_0c0619be: /* original 750c, guest PC 0x0c0619be */
if(!s->budget--) { s->failed_pc=0x0c0619beu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619c0;
P_0c0619c0: /* original 64d3, guest PC 0x0c0619c0 */
if(!s->budget--) { s->failed_pc=0x0c0619c0u; return 0; }
r[4]=r[13];
goto P_0c0619c2;
P_0c0619c2: /* original b61f, guest PC 0x0c0619c2 */
if(!s->budget--) { s->failed_pc=0x0c0619c2u; return 0; }
target=code_base|0x0c062604u; r[16]=code_base|0x0c0619c6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619c6u) { target=s->pc; goto dispatch; }
goto P_0c0619c6;
P_0c0619c4: /* original 7408, guest PC 0x0c0619c4 */
if(!s->budget--) { s->failed_pc=0x0c0619c4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0619c6;
P_0c0619c6: /* original e000, guest PC 0x0c0619c6 */
if(!s->budget--) { s->failed_pc=0x0c0619c6u; return 0; }
r[0]=0x00000000u;
goto P_0c0619c8;
P_0c0619c8: /* original 4f26, guest PC 0x0c0619c8 */
if(!s->budget--) { s->failed_pc=0x0c0619c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0619ca;
P_0c0619ca: /* original 6df6, guest PC 0x0c0619ca */
if(!s->budget--) { s->failed_pc=0x0c0619cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0619cc;
P_0c0619cc: /* original 000b, guest PC 0x0c0619cc */
if(!s->budget--) { s->failed_pc=0x0c0619ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0619ce: /* original 6ef6, guest PC 0x0c0619ce */
if(!s->budget--) { s->failed_pc=0x0c0619ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0619d0;
P_0c0619d0: /* original 2fe6, guest PC 0x0c0619d0 */
if(!s->budget--) { s->failed_pc=0x0c0619d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0619d2;
P_0c0619d2: /* original 4f22, guest PC 0x0c0619d2 */
if(!s->budget--) { s->failed_pc=0x0c0619d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0619d4;
P_0c0619d4: /* original de0d, guest PC 0x0c0619d4 */
if(!s->budget--) { s->failed_pc=0x0c0619d4u; return 0; }
r[14]=read(ram,0x0c061a0cu,4);
goto P_0c0619d6;
P_0c0619d6: /* original 67e3, guest PC 0x0c0619d6 */
if(!s->budget--) { s->failed_pc=0x0c0619d6u; return 0; }
r[7]=r[14];
goto P_0c0619d8;
P_0c0619d8: /* original 7704, guest PC 0x0c0619d8 */
if(!s->budget--) { s->failed_pc=0x0c0619d8u; return 0; }
r[7]+=0x00000004u;
goto P_0c0619da;
P_0c0619da: /* original 66e3, guest PC 0x0c0619da */
if(!s->budget--) { s->failed_pc=0x0c0619dau; return 0; }
r[6]=r[14];
goto P_0c0619dc;
P_0c0619dc: /* original 65e3, guest PC 0x0c0619dc */
if(!s->budget--) { s->failed_pc=0x0c0619dcu; return 0; }
r[5]=r[14];
goto P_0c0619de;
P_0c0619de: /* original 750c, guest PC 0x0c0619de */
if(!s->budget--) { s->failed_pc=0x0c0619deu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619e0;
P_0c0619e0: /* original 64e3, guest PC 0x0c0619e0 */
if(!s->budget--) { s->failed_pc=0x0c0619e0u; return 0; }
r[4]=r[14];
goto P_0c0619e2;
P_0c0619e2: /* original b665, guest PC 0x0c0619e2 */
if(!s->budget--) { s->failed_pc=0x0c0619e2u; return 0; }
target=code_base|0x0c0626b0u; r[16]=code_base|0x0c0619e6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619e6u) { target=s->pc; goto dispatch; }
goto P_0c0619e6;
P_0c0619e4: /* original 7408, guest PC 0x0c0619e4 */
if(!s->budget--) { s->failed_pc=0x0c0619e4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0619e6;
P_0c0619e6: /* original 6403, guest PC 0x0c0619e6 */
if(!s->budget--) { s->failed_pc=0x0c0619e6u; return 0; }
r[4]=r[0];
goto P_0c0619e8;
P_0c0619e8: /* original 2448, guest PC 0x0c0619e8 */
if(!s->budget--) { s->failed_pc=0x0c0619e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0619ea;
P_0c0619ea: /* original 8b09, guest PC 0x0c0619ea */
if(!s->budget--) { s->failed_pc=0x0c0619eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061a00; }
goto P_0c0619ec;
P_0c0619ec: /* original de08, guest PC 0x0c0619ec */
if(!s->budget--) { s->failed_pc=0x0c0619ecu; return 0; }
r[14]=read(ram,0x0c061a10u,4);
goto P_0c0619ee;
P_0c0619ee: /* original 67e3, guest PC 0x0c0619ee */
if(!s->budget--) { s->failed_pc=0x0c0619eeu; return 0; }
r[7]=r[14];
goto P_0c0619f0;
P_0c0619f0: /* original 7704, guest PC 0x0c0619f0 */
if(!s->budget--) { s->failed_pc=0x0c0619f0u; return 0; }
r[7]+=0x00000004u;
goto P_0c0619f2;
P_0c0619f2: /* original 66e3, guest PC 0x0c0619f2 */
if(!s->budget--) { s->failed_pc=0x0c0619f2u; return 0; }
r[6]=r[14];
goto P_0c0619f4;
P_0c0619f4: /* original 65e3, guest PC 0x0c0619f4 */
if(!s->budget--) { s->failed_pc=0x0c0619f4u; return 0; }
r[5]=r[14];
goto P_0c0619f6;
P_0c0619f6: /* original 750c, guest PC 0x0c0619f6 */
if(!s->budget--) { s->failed_pc=0x0c0619f6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619f8;
P_0c0619f8: /* original 64e3, guest PC 0x0c0619f8 */
if(!s->budget--) { s->failed_pc=0x0c0619f8u; return 0; }
r[4]=r[14];
goto P_0c0619fa;
P_0c0619fa: /* original b659, guest PC 0x0c0619fa */
if(!s->budget--) { s->failed_pc=0x0c0619fau; return 0; }
target=code_base|0x0c0626b0u; r[16]=code_base|0x0c0619feu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0619feu) { target=s->pc; goto dispatch; }
goto P_0c0619fe;
P_0c0619fc: /* original 7408, guest PC 0x0c0619fc */
if(!s->budget--) { s->failed_pc=0x0c0619fcu; return 0; }
r[4]+=0x00000008u;
goto P_0c0619fe;
P_0c0619fe: /* original 6403, guest PC 0x0c0619fe */
if(!s->budget--) { s->failed_pc=0x0c0619feu; return 0; }
r[4]=r[0];
goto P_0c061a00;
P_0c061a00: /* original 6043, guest PC 0x0c061a00 */
if(!s->budget--) { s->failed_pc=0x0c061a00u; return 0; }
r[0]=r[4];
goto P_0c061a02;
P_0c061a02: /* original 0009, guest PC 0x0c061a02 */
if(!s->budget--) { s->failed_pc=0x0c061a02u; return 0; }
goto P_0c061a04;
P_0c061a04: /* original 4f26, guest PC 0x0c061a04 */
if(!s->budget--) { s->failed_pc=0x0c061a04u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c061a06;
P_0c061a06: /* original 000b, guest PC 0x0c061a06 */
if(!s->budget--) { s->failed_pc=0x0c061a06u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061a08: /* original 6ef6, guest PC 0x0c061a08 */
if(!s->budget--) { s->failed_pc=0x0c061a08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c061a0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061a0au; return 0; } return 1;
P_0c0620e4: /* original 2fe6, guest PC 0x0c0620e4 */
if(!s->budget--) { s->failed_pc=0x0c0620e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0620e6;
P_0c0620e6: /* original 6153, guest PC 0x0c0620e6 */
if(!s->budget--) { s->failed_pc=0x0c0620e6u; return 0; }
r[1]=r[5];
goto P_0c0620e8;
P_0c0620e8: /* original d331, guest PC 0x0c0620e8 */
if(!s->budget--) { s->failed_pc=0x0c0620e8u; return 0; }
r[3]=read(ram,0x0c0621b0u,4);
goto P_0c0620ea;
P_0c0620ea: /* original 2fd6, guest PC 0x0c0620ea */
if(!s->budget--) { s->failed_pc=0x0c0620eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0620ec;
P_0c0620ec: /* original 2fc6, guest PC 0x0c0620ec */
if(!s->budget--) { s->failed_pc=0x0c0620ecu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0620ee;
P_0c0620ee: /* original 6d53, guest PC 0x0c0620ee */
if(!s->budget--) { s->failed_pc=0x0c0620eeu; return 0; }
r[13]=r[5];
goto P_0c0620f0;
P_0c0620f0: /* original 2fb6, guest PC 0x0c0620f0 */
if(!s->budget--) { s->failed_pc=0x0c0620f0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0620f2;
P_0c0620f2: /* original 6b43, guest PC 0x0c0620f2 */
if(!s->budget--) { s->failed_pc=0x0c0620f2u; return 0; }
r[11]=r[4];
goto P_0c0620f4;
P_0c0620f4: /* original 2fa6, guest PC 0x0c0620f4 */
if(!s->budget--) { s->failed_pc=0x0c0620f4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0620f6;
P_0c0620f6: /* original 2f96, guest PC 0x0c0620f6 */
if(!s->budget--) { s->failed_pc=0x0c0620f6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0620f8;
P_0c0620f8: /* original 4f22, guest PC 0x0c0620f8 */
if(!s->budget--) { s->failed_pc=0x0c0620f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0620fa;
P_0c0620fa: /* original 6963, guest PC 0x0c0620fa */
if(!s->budget--) { s->failed_pc=0x0c0620fau; return 0; }
r[9]=r[6];
goto P_0c0620fc;
P_0c0620fc: /* original da2b, guest PC 0x0c0620fc */
if(!s->budget--) { s->failed_pc=0x0c0620fcu; return 0; }
r[10]=read(ram,0x0c0621acu,4);
goto P_0c0620fe;
P_0c0620fe: /* original 7ffc, guest PC 0x0c0620fe */
if(!s->budget--) { s->failed_pc=0x0c0620feu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062100;
P_0c062100: /* original e600, guest PC 0x0c062100 */
if(!s->budget--) { s->failed_pc=0x0c062100u; return 0; }
r[6]=0x00000000u;
goto P_0c062102;
P_0c062102: /* original 430b, guest PC 0x0c062102 */
if(!s->budget--) { s->failed_pc=0x0c062102u; return 0; }
target=r[3];
r[16]=code_base|0x0c062106u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062106u) { target=s->pc; goto dispatch; }
goto P_0c062106;
P_0c062104: /* original e020, guest PC 0x0c062104 */
if(!s->budget--) { s->failed_pc=0x0c062104u; return 0; }
r[0]=0x00000020u;
goto P_0c062106;
P_0c062106: /* original 6403, guest PC 0x0c062106 */
if(!s->budget--) { s->failed_pc=0x0c062106u; return 0; }
r[4]=r[0];
goto P_0c062108;
P_0c062108: /* original 2448, guest PC 0x0c062108 */
if(!s->budget--) { s->failed_pc=0x0c062108u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06210a;
P_0c06210a: /* original 8d03, guest PC 0x0c06210a */
if(!s->budget--) { s->failed_pc=0x0c06210au; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c062114; }
goto P_0c06210e;
P_0c06210c: /* original e700, guest PC 0x0c06210c */
if(!s->budget--) { s->failed_pc=0x0c06210cu; return 0; }
r[7]=0x00000000u;
goto P_0c06210e;
P_0c06210e: /* original e320, guest PC 0x0c06210e */
if(!s->budget--) { s->failed_pc=0x0c06210eu; return 0; }
r[3]=0x00000020u;
goto P_0c062110;
P_0c062110: /* original 3348, guest PC 0x0c062110 */
if(!s->budget--) { s->failed_pc=0x0c062110u; return 0; }
r[3]-=r[4];
goto P_0c062112;
P_0c062112: /* original 3d3c, guest PC 0x0c062112 */
if(!s->budget--) { s->failed_pc=0x0c062112u; return 0; }
r[13]+=r[3];
goto P_0c062114;
P_0c062114: /* original 64b3, guest PC 0x0c062114 */
if(!s->budget--) { s->failed_pc=0x0c062114u; return 0; }
r[4]=r[11];
goto P_0c062116;
P_0c062116: /* original 63b3, guest PC 0x0c062116 */
if(!s->budget--) { s->failed_pc=0x0c062116u; return 0; }
r[3]=r[11];
goto P_0c062118;
P_0c062118: /* original 4408, guest PC 0x0c062118 */
if(!s->budget--) { s->failed_pc=0x0c062118u; return 0; }
r[4]<<=2;
goto P_0c06211a;
P_0c06211a: /* original 343c, guest PC 0x0c06211a */
if(!s->budget--) { s->failed_pc=0x0c06211au; return 0; }
r[4]+=r[3];
goto P_0c06211c;
P_0c06211c: /* original 4408, guest PC 0x0c06211c */
if(!s->budget--) { s->failed_pc=0x0c06211cu; return 0; }
r[4]<<=2;
goto P_0c06211e;
P_0c06211e: /* original 644e, guest PC 0x0c06211e */
if(!s->budget--) { s->failed_pc=0x0c06211eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c062120;
P_0c062120: /* original 34ac, guest PC 0x0c062120 */
if(!s->budget--) { s->failed_pc=0x0c062120u; return 0; }
r[4]+=r[10];
goto P_0c062122;
P_0c062122: /* original 5442, guest PC 0x0c062122 */
if(!s->budget--) { s->failed_pc=0x0c062122u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c062124;
P_0c062124: /* original 2448, guest PC 0x0c062124 */
if(!s->budget--) { s->failed_pc=0x0c062124u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c062126;
P_0c062126: /* original 8d29, guest PC 0x0c062126 */
if(!s->budget--) { s->failed_pc=0x0c062126u; return 0; }
cond=r[17]&1u;
r[14]=r[7];
if(cond) { goto P_0c06217c; }
goto P_0c06212a;
P_0c062128: /* original 6e73, guest PC 0x0c062128 */
if(!s->budget--) { s->failed_pc=0x0c062128u; return 0; }
r[14]=r[7];
goto P_0c06212a;
P_0c06212a: /* original 5344, guest PC 0x0c06212a */
if(!s->budget--) { s->failed_pc=0x0c06212au; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c06212c;
P_0c06212c: /* original 33d3, guest PC 0x0c06212c */
if(!s->budget--) { s->failed_pc=0x0c06212cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[13])!=0);
goto P_0c06212e;
P_0c06212e: /* original 8b22, guest PC 0x0c06212e */
if(!s->budget--) { s->failed_pc=0x0c06212eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062176; }
goto P_0c062130;
P_0c062130: /* original 2778, guest PC 0x0c062130 */
if(!s->budget--) { s->failed_pc=0x0c062130u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c062132;
P_0c062132: /* original 8b00, guest PC 0x0c062132 */
if(!s->budget--) { s->failed_pc=0x0c062132u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062136; }
goto P_0c062134;
P_0c062134: /* original 6743, guest PC 0x0c062134 */
if(!s->budget--) { s->failed_pc=0x0c062134u; return 0; }
r[7]=r[4];
goto P_0c062136;
P_0c062136: /* original 9537, guest PC 0x0c062136 */
if(!s->budget--) { s->failed_pc=0x0c062136u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0621a8u,2);
goto P_0c062138;
P_0c062138: /* original 5143, guest PC 0x0c062138 */
if(!s->budget--) { s->failed_pc=0x0c062138u; return 0; }
r[1]=read(ram,r[4]+12,4);
goto P_0c06213a;
P_0c06213a: /* original 6053, guest PC 0x0c06213a */
if(!s->budget--) { s->failed_pc=0x0c06213au; return 0; }
r[0]=r[5];
goto P_0c06213c;
P_0c06213c: /* original 0009, guest PC 0x0c06213c */
if(!s->budget--) { s->failed_pc=0x0c06213cu; return 0; }
goto P_0c06213e;
P_0c06213e: /* original d31c, guest PC 0x0c06213e */
if(!s->budget--) { s->failed_pc=0x0c06213eu; return 0; }
r[3]=read(ram,0x0c0621b0u,4);
goto P_0c062140;
P_0c062140: /* original 430b, guest PC 0x0c062140 */
if(!s->budget--) { s->failed_pc=0x0c062140u; return 0; }
target=r[3];
r[16]=code_base|0x0c062144u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062144u) { target=s->pc; goto dispatch; }
goto P_0c062144;
P_0c062142: /* original 0009, guest PC 0x0c062142 */
if(!s->budget--) { s->failed_pc=0x0c062142u; return 0; }
goto P_0c062144;
P_0c062144: /* original 2008, guest PC 0x0c062144 */
if(!s->budget--) { s->failed_pc=0x0c062144u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c062146;
P_0c062146: /* original 8911, guest PC 0x0c062146 */
if(!s->budget--) { s->failed_pc=0x0c062146u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06216c; }
goto P_0c062148;
P_0c062148: /* original 902f, guest PC 0x0c062148 */
if(!s->budget--) { s->failed_pc=0x0c062148u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0621aau,2);
goto P_0c06214a;
P_0c06214a: /* original 5c43, guest PC 0x0c06214a */
if(!s->budget--) { s->failed_pc=0x0c06214au; return 0; }
r[12]=read(ram,r[4]+12,4);
goto P_0c06214c;
P_0c06214c: /* original 5344, guest PC 0x0c06214c */
if(!s->budget--) { s->failed_pc=0x0c06214cu; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c06214e;
P_0c06214e: /* original 35cc, guest PC 0x0c06214e */
if(!s->budget--) { s->failed_pc=0x0c06214eu; return 0; }
r[5]+=r[12];
goto P_0c062150;
P_0c062150: /* original 2509, guest PC 0x0c062150 */
if(!s->budget--) { s->failed_pc=0x0c062150u; return 0; }
r[5]&=r[0];
goto P_0c062152;
P_0c062152: /* original 3c3c, guest PC 0x0c062152 */
if(!s->budget--) { s->failed_pc=0x0c062152u; return 0; }
r[12]+=r[3];
goto P_0c062154;
P_0c062154: /* original 35c3, guest PC 0x0c062154 */
if(!s->budget--) { s->failed_pc=0x0c062154u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[12])!=0);
goto P_0c062156;
P_0c062156: /* original 890a, guest PC 0x0c062156 */
if(!s->budget--) { s->failed_pc=0x0c062156u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06216e; }
goto P_0c062158;
P_0c062158: /* original 5343, guest PC 0x0c062158 */
if(!s->budget--) { s->failed_pc=0x0c062158u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c06215a;
P_0c06215a: /* original 6253, guest PC 0x0c06215a */
if(!s->budget--) { s->failed_pc=0x0c06215au; return 0; }
r[2]=r[5];
goto P_0c06215c;
P_0c06215c: /* original 3238, guest PC 0x0c06215c */
if(!s->budget--) { s->failed_pc=0x0c06215cu; return 0; }
r[2]-=r[3];
goto P_0c06215e;
P_0c06215e: /* original 32d3, guest PC 0x0c06215e */
if(!s->budget--) { s->failed_pc=0x0c06215eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[13])!=0);
goto P_0c062160;
P_0c062160: /* original 8905, guest PC 0x0c062160 */
if(!s->budget--) { s->failed_pc=0x0c062160u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06216e; }
goto P_0c062162;
P_0c062162: /* original 3c58, guest PC 0x0c062162 */
if(!s->budget--) { s->failed_pc=0x0c062162u; return 0; }
r[12]-=r[5];
goto P_0c062164;
P_0c062164: /* original 3cd3, guest PC 0x0c062164 */
if(!s->budget--) { s->failed_pc=0x0c062164u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[13])!=0);
goto P_0c062166;
P_0c062166: /* original 8b06, guest PC 0x0c062166 */
if(!s->budget--) { s->failed_pc=0x0c062166u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062176; }
goto P_0c062168;
P_0c062168: /* original a002, guest PC 0x0c062168 */
if(!s->budget--) { s->failed_pc=0x0c062168u; return 0; }
r[6]=0x00000002u;
goto P_0c062170;
P_0c06216a: /* original e602, guest PC 0x0c06216a */
if(!s->budget--) { s->failed_pc=0x0c06216au; return 0; }
r[6]=0x00000002u;
goto P_0c06216c;
P_0c06216c: /* original 5543, guest PC 0x0c06216c */
if(!s->budget--) { s->failed_pc=0x0c06216cu; return 0; }
r[5]=read(ram,r[4]+12,4);
goto P_0c06216e;
P_0c06216e: /* original e601, guest PC 0x0c06216e */
if(!s->budget--) { s->failed_pc=0x0c06216eu; return 0; }
r[6]=0x00000001u;
goto P_0c062170;
P_0c062170: /* original 6e43, guest PC 0x0c062170 */
if(!s->budget--) { s->failed_pc=0x0c062170u; return 0; }
r[14]=r[4];
goto P_0c062172;
P_0c062172: /* original a001, guest PC 0x0c062172 */
if(!s->budget--) { s->failed_pc=0x0c062172u; return 0; }
r[4]=0x00000000u;
goto P_0c062178;
P_0c062174: /* original e400, guest PC 0x0c062174 */
if(!s->budget--) { s->failed_pc=0x0c062174u; return 0; }
r[4]=0x00000000u;
goto P_0c062176;
P_0c062176: /* original 5442, guest PC 0x0c062176 */
if(!s->budget--) { s->failed_pc=0x0c062176u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c062178;
P_0c062178: /* original 2448, guest PC 0x0c062178 */
if(!s->budget--) { s->failed_pc=0x0c062178u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06217a;
P_0c06217a: /* original 8bd6, guest PC 0x0c06217a */
if(!s->budget--) { s->failed_pc=0x0c06217au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06212a; }
goto P_0c06217c;
P_0c06217c: /* original 2668, guest PC 0x0c06217c */
if(!s->budget--) { s->failed_pc=0x0c06217cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06217e;
P_0c06217e: /* original 8b03, guest PC 0x0c06217e */
if(!s->budget--) { s->failed_pc=0x0c06217eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062188; }
goto P_0c062180;
P_0c062180: /* original 2778, guest PC 0x0c062180 */
if(!s->budget--) { s->failed_pc=0x0c062180u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c062182;
P_0c062182: /* original 8901, guest PC 0x0c062182 */
if(!s->budget--) { s->failed_pc=0x0c062182u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062188; }
goto P_0c062184;
P_0c062184: /* original e601, guest PC 0x0c062184 */
if(!s->budget--) { s->failed_pc=0x0c062184u; return 0; }
r[6]=0x00000001u;
goto P_0c062186;
P_0c062186: /* original 6e73, guest PC 0x0c062186 */
if(!s->budget--) { s->failed_pc=0x0c062186u; return 0; }
r[14]=r[7];
goto P_0c062188;
P_0c062188: /* original 2ee8, guest PC 0x0c062188 */
if(!s->budget--) { s->failed_pc=0x0c062188u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06218a;
P_0c06218a: /* original 8949, guest PC 0x0c06218a */
if(!s->budget--) { s->failed_pc=0x0c06218au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062220; }
goto P_0c06218c;
P_0c06218c: /* original 6063, guest PC 0x0c06218c */
if(!s->budget--) { s->failed_pc=0x0c06218cu; return 0; }
r[0]=r[6];
goto P_0c06218e;
P_0c06218e: /* original 0009, guest PC 0x0c06218e */
if(!s->budget--) { s->failed_pc=0x0c06218eu; return 0; }
goto P_0c062190;
P_0c062190: /* original 8802, guest PC 0x0c062190 */
if(!s->budget--) { s->failed_pc=0x0c062190u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c062192;
P_0c062192: /* original 8b0f, guest PC 0x0c062192 */
if(!s->budget--) { s->failed_pc=0x0c062192u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0621b4; }
goto P_0c062194;
P_0c062194: /* original e301, guest PC 0x0c062194 */
if(!s->budget--) { s->failed_pc=0x0c062194u; return 0; }
r[3]=0x00000001u;
goto P_0c062196;
P_0c062196: /* original e200, guest PC 0x0c062196 */
if(!s->budget--) { s->failed_pc=0x0c062196u; return 0; }
r[2]=0x00000000u;
goto P_0c062198;
P_0c062198: /* original 2f36, guest PC 0x0c062198 */
if(!s->budget--) { s->failed_pc=0x0c062198u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06219a;
P_0c06219a: /* original 6793, guest PC 0x0c06219a */
if(!s->budget--) { s->failed_pc=0x0c06219au; return 0; }
r[7]=r[9];
goto P_0c06219c;
P_0c06219c: /* original 2f26, guest PC 0x0c06219c */
if(!s->budget--) { s->failed_pc=0x0c06219cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06219e;
P_0c06219e: /* original 66d3, guest PC 0x0c06219e */
if(!s->budget--) { s->failed_pc=0x0c06219eu; return 0; }
r[6]=r[13];
goto P_0c0621a0;
P_0c0621a0: /* original b374, guest PC 0x0c0621a0 */
if(!s->budget--) { s->failed_pc=0x0c0621a0u; return 0; }
target=code_base|0x0c06288cu; r[16]=code_base|0x0c0621a4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0621a4u) { target=s->pc; goto dispatch; }
goto P_0c0621a4;
P_0c0621a2: /* original 64b3, guest PC 0x0c0621a2 */
if(!s->budget--) { s->failed_pc=0x0c0621a2u; return 0; }
r[4]=r[11];
goto P_0c0621a4;
P_0c0621a4: /* original a070, guest PC 0x0c0621a4 */
if(!s->budget--) { s->failed_pc=0x0c0621a4u; return 0; }
r[15]+=0x00000008u;
goto P_0c062288;
P_0c0621a6: /* original 7f08, guest PC 0x0c0621a6 */
if(!s->budget--) { s->failed_pc=0x0c0621a6u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0621a8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0621a8u; return 0; } return 1;
P_0c0621b4: /* original 53e4, guest PC 0x0c0621b4 */
if(!s->budget--) { s->failed_pc=0x0c0621b4u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0621b6;
P_0c0621b6: /* original 33d0, guest PC 0x0c0621b6 */
if(!s->budget--) { s->failed_pc=0x0c0621b6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[13])!=0);
goto P_0c0621b8;
P_0c0621b8: /* original 8b2d, guest PC 0x0c0621b8 */
if(!s->budget--) { s->failed_pc=0x0c0621b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062216; }
goto P_0c0621ba;
P_0c0621ba: /* original 66e3, guest PC 0x0c0621ba */
if(!s->budget--) { s->failed_pc=0x0c0621bau; return 0; }
r[6]=r[14];
goto P_0c0621bc;
P_0c0621bc: /* original 6db3, guest PC 0x0c0621bc */
if(!s->budget--) { s->failed_pc=0x0c0621bcu; return 0; }
r[13]=r[11];
goto P_0c0621be;
P_0c0621be: /* original 63b3, guest PC 0x0c0621be */
if(!s->budget--) { s->failed_pc=0x0c0621beu; return 0; }
r[3]=r[11];
goto P_0c0621c0;
P_0c0621c0: /* original 4d08, guest PC 0x0c0621c0 */
if(!s->budget--) { s->failed_pc=0x0c0621c0u; return 0; }
r[13]<<=2;
goto P_0c0621c2;
P_0c0621c2: /* original 3d3c, guest PC 0x0c0621c2 */
if(!s->budget--) { s->failed_pc=0x0c0621c2u; return 0; }
r[13]+=r[3];
goto P_0c0621c4;
P_0c0621c4: /* original 4d08, guest PC 0x0c0621c4 */
if(!s->budget--) { s->failed_pc=0x0c0621c4u; return 0; }
r[13]<<=2;
goto P_0c0621c6;
P_0c0621c6: /* original 6dde, guest PC 0x0c0621c6 */
if(!s->budget--) { s->failed_pc=0x0c0621c6u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)r[13];
goto P_0c0621c8;
P_0c0621c8: /* original 3dac, guest PC 0x0c0621c8 */
if(!s->budget--) { s->failed_pc=0x0c0621c8u; return 0; }
r[13]+=r[10];
goto P_0c0621ca;
P_0c0621ca: /* original 65d3, guest PC 0x0c0621ca */
if(!s->budget--) { s->failed_pc=0x0c0621cau; return 0; }
r[5]=r[13];
goto P_0c0621cc;
P_0c0621cc: /* original 750c, guest PC 0x0c0621cc */
if(!s->budget--) { s->failed_pc=0x0c0621ccu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0621ce;
P_0c0621ce: /* original 64d3, guest PC 0x0c0621ce */
if(!s->budget--) { s->failed_pc=0x0c0621ceu; return 0; }
r[4]=r[13];
goto P_0c0621d0;
P_0c0621d0: /* original b1a8, guest PC 0x0c0621d0 */
if(!s->budget--) { s->failed_pc=0x0c0621d0u; return 0; }
target=code_base|0x0c062524u; r[16]=code_base|0x0c0621d4u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0621d4u) { target=s->pc; goto dispatch; }
goto P_0c0621d4;
P_0c0621d2: /* original 7408, guest PC 0x0c0621d2 */
if(!s->budget--) { s->failed_pc=0x0c0621d2u; return 0; }
r[4]+=0x00000008u;
goto P_0c0621d4;
P_0c0621d4: /* original 66e3, guest PC 0x0c0621d4 */
if(!s->budget--) { s->failed_pc=0x0c0621d4u; return 0; }
r[6]=r[14];
goto P_0c0621d6;
P_0c0621d6: /* original 65d3, guest PC 0x0c0621d6 */
if(!s->budget--) { s->failed_pc=0x0c0621d6u; return 0; }
r[5]=r[13];
goto P_0c0621d8;
P_0c0621d8: /* original 7504, guest PC 0x0c0621d8 */
if(!s->budget--) { s->failed_pc=0x0c0621d8u; return 0; }
r[5]+=0x00000004u;
goto P_0c0621da;
P_0c0621da: /* original b183, guest PC 0x0c0621da */
if(!s->budget--) { s->failed_pc=0x0c0621dau; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c0621deu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0621deu) { target=s->pc; goto dispatch; }
goto P_0c0621de;
P_0c0621dc: /* original 64d3, guest PC 0x0c0621dc */
if(!s->budget--) { s->failed_pc=0x0c0621dcu; return 0; }
r[4]=r[13];
goto P_0c0621de;
P_0c0621de: /* original e301, guest PC 0x0c0621de */
if(!s->budget--) { s->failed_pc=0x0c0621deu; return 0; }
r[3]=0x00000001u;
goto P_0c0621e0;
P_0c0621e0: /* original 52e3, guest PC 0x0c0621e0 */
if(!s->budget--) { s->failed_pc=0x0c0621e0u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0621e2;
P_0c0621e2: /* original 1922, guest PC 0x0c0621e2 */
if(!s->budget--) { s->failed_pc=0x0c0621e2u; return 0; }
write(ram,r[9]+8,r[2],4);
goto P_0c0621e4;
P_0c0621e4: /* original 1e95, guest PC 0x0c0621e4 */
if(!s->budget--) { s->failed_pc=0x0c0621e4u; return 0; }
write(ram,r[14]+20,r[9],4);
goto P_0c0621e6;
P_0c0621e6: /* original 62bf, guest PC 0x0c0621e6 */
if(!s->budget--) { s->failed_pc=0x0c0621e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c0621e8;
P_0c0621e8: /* original 2e31, guest PC 0x0c0621e8 */
if(!s->budget--) { s->failed_pc=0x0c0621e8u; return 0; }
write(ram,r[14],r[3],2);
goto P_0c0621ea;
P_0c0621ea: /* original 2228, guest PC 0x0c0621ea */
if(!s->budget--) { s->failed_pc=0x0c0621eau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0621ec;
P_0c0621ec: /* original 8b04, guest PC 0x0c0621ec */
if(!s->budget--) { s->failed_pc=0x0c0621ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0621f8; }
goto P_0c0621ee;
P_0c0621ee: /* original 9354, guest PC 0x0c0621ee */
if(!s->budget--) { s->failed_pc=0x0c0621eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06229au,2);
goto P_0c0621f0;
P_0c0621f0: /* original 61e1, guest PC 0x0c0621f0 */
if(!s->budget--) { s->failed_pc=0x0c0621f0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c0621f2;
P_0c0621f2: /* original 213b, guest PC 0x0c0621f2 */
if(!s->budget--) { s->failed_pc=0x0c0621f2u; return 0; }
r[1]|=r[3];
goto P_0c0621f4;
P_0c0621f4: /* original a004, guest PC 0x0c0621f4 */
if(!s->budget--) { s->failed_pc=0x0c0621f4u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c062200;
P_0c0621f6: /* original 2e11, guest PC 0x0c0621f6 */
if(!s->budget--) { s->failed_pc=0x0c0621f6u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c0621f8;
P_0c0621f8: /* original 9350, guest PC 0x0c0621f8 */
if(!s->budget--) { s->failed_pc=0x0c0621f8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06229cu,2);
goto P_0c0621fa;
P_0c0621fa: /* original 62e1, guest PC 0x0c0621fa */
if(!s->budget--) { s->failed_pc=0x0c0621fau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0621fc;
P_0c0621fc: /* original 223b, guest PC 0x0c0621fc */
if(!s->budget--) { s->failed_pc=0x0c0621fcu; return 0; }
r[2]|=r[3];
goto P_0c0621fe;
P_0c0621fe: /* original 2e21, guest PC 0x0c0621fe */
if(!s->budget--) { s->failed_pc=0x0c0621feu; return 0; }
write(ram,r[14],r[2],2);
goto P_0c062200;
P_0c062200: /* original 60e1, guest PC 0x0c062200 */
if(!s->budget--) { s->failed_pc=0x0c062200u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c062202;
P_0c062202: /* original 63b3, guest PC 0x0c062202 */
if(!s->budget--) { s->failed_pc=0x0c062202u; return 0; }
r[3]=r[11];
goto P_0c062204;
P_0c062204: /* original cb04, guest PC 0x0c062204 */
if(!s->budget--) { s->failed_pc=0x0c062204u; return 0; }
r[0]|=4u;
goto P_0c062206;
P_0c062206: /* original 4b08, guest PC 0x0c062206 */
if(!s->budget--) { s->failed_pc=0x0c062206u; return 0; }
r[11]<<=2;
goto P_0c062208;
P_0c062208: /* original 2e01, guest PC 0x0c062208 */
if(!s->budget--) { s->failed_pc=0x0c062208u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c06220a;
P_0c06220a: /* original 3b3c, guest PC 0x0c06220a */
if(!s->budget--) { s->failed_pc=0x0c06220au; return 0; }
r[11]+=r[3];
goto P_0c06220c;
P_0c06220c: /* original 4b08, guest PC 0x0c06220c */
if(!s->budget--) { s->failed_pc=0x0c06220cu; return 0; }
r[11]<<=2;
goto P_0c06220e;
P_0c06220e: /* original 6bbe, guest PC 0x0c06220e */
if(!s->budget--) { s->failed_pc=0x0c06220eu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c062210;
P_0c062210: /* original 3bac, guest PC 0x0c062210 */
if(!s->budget--) { s->failed_pc=0x0c062210u; return 0; }
r[11]+=r[10];
goto P_0c062212;
P_0c062212: /* original a035, guest PC 0x0c062212 */
if(!s->budget--) { s->failed_pc=0x0c062212u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062280;
P_0c062214: /* original 53e4, guest PC 0x0c062214 */
if(!s->budget--) { s->failed_pc=0x0c062214u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062216;
P_0c062216: /* original b13b, guest PC 0x0c062216 */
if(!s->budget--) { s->failed_pc=0x0c062216u; return 0; }
target=code_base|0x0c062490u; r[16]=code_base|0x0c06221au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06221au) { target=s->pc; goto dispatch; }
goto P_0c06221a;
P_0c062218: /* original 0009, guest PC 0x0c062218 */
if(!s->budget--) { s->failed_pc=0x0c062218u; return 0; }
goto P_0c06221a;
P_0c06221a: /* original 6c03, guest PC 0x0c06221a */
if(!s->budget--) { s->failed_pc=0x0c06221au; return 0; }
r[12]=r[0];
goto P_0c06221c;
P_0c06221c: /* original 2cc8, guest PC 0x0c06221c */
if(!s->budget--) { s->failed_pc=0x0c06221cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c06221e;
P_0c06221e: /* original 8b01, guest PC 0x0c06221e */
if(!s->budget--) { s->failed_pc=0x0c06221eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062224; }
goto P_0c062220;
P_0c062220: /* original a032, guest PC 0x0c062220 */
if(!s->budget--) { s->failed_pc=0x0c062220u; return 0; }
r[0]=0x00000003u;
goto P_0c062288;
P_0c062222: /* original e003, guest PC 0x0c062222 */
if(!s->budget--) { s->failed_pc=0x0c062222u; return 0; }
r[0]=0x00000003u;
goto P_0c062224;
P_0c062224: /* original 53e3, guest PC 0x0c062224 */
if(!s->budget--) { s->failed_pc=0x0c062224u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c062226;
P_0c062226: /* original 66c3, guest PC 0x0c062226 */
if(!s->budget--) { s->failed_pc=0x0c062226u; return 0; }
r[6]=r[12];
goto P_0c062228;
P_0c062228: /* original 1c33, guest PC 0x0c062228 */
if(!s->budget--) { s->failed_pc=0x0c062228u; return 0; }
write(ram,r[12]+12,r[3],4);
goto P_0c06222a;
P_0c06222a: /* original 65b3, guest PC 0x0c06222a */
if(!s->budget--) { s->failed_pc=0x0c06222au; return 0; }
r[5]=r[11];
goto P_0c06222c;
P_0c06222c: /* original 1cd4, guest PC 0x0c06222c */
if(!s->budget--) { s->failed_pc=0x0c06222cu; return 0; }
write(ram,r[12]+16,r[13],4);
goto P_0c06222e;
P_0c06222e: /* original 63b3, guest PC 0x0c06222e */
if(!s->budget--) { s->failed_pc=0x0c06222eu; return 0; }
r[3]=r[11];
goto P_0c062230;
P_0c062230: /* original 54e4, guest PC 0x0c062230 */
if(!s->budget--) { s->failed_pc=0x0c062230u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c062232;
P_0c062232: /* original 4508, guest PC 0x0c062232 */
if(!s->budget--) { s->failed_pc=0x0c062232u; return 0; }
r[5]<<=2;
goto P_0c062234;
P_0c062234: /* original 34d8, guest PC 0x0c062234 */
if(!s->budget--) { s->failed_pc=0x0c062234u; return 0; }
r[4]-=r[13];
goto P_0c062236;
P_0c062236: /* original 353c, guest PC 0x0c062236 */
if(!s->budget--) { s->failed_pc=0x0c062236u; return 0; }
r[5]+=r[3];
goto P_0c062238;
P_0c062238: /* original 1e44, guest PC 0x0c062238 */
if(!s->budget--) { s->failed_pc=0x0c062238u; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c06223a;
P_0c06223a: /* original 4508, guest PC 0x0c06223a */
if(!s->budget--) { s->failed_pc=0x0c06223au; return 0; }
r[5]<<=2;
goto P_0c06223c;
P_0c06223c: /* original 52e3, guest PC 0x0c06223c */
if(!s->budget--) { s->failed_pc=0x0c06223cu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c06223e;
P_0c06223e: /* original 655e, guest PC 0x0c06223e */
if(!s->budget--) { s->failed_pc=0x0c06223eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c062240;
P_0c062240: /* original 32dc, guest PC 0x0c062240 */
if(!s->budget--) { s->failed_pc=0x0c062240u; return 0; }
r[2]+=r[13];
goto P_0c062242;
P_0c062242: /* original 35ac, guest PC 0x0c062242 */
if(!s->budget--) { s->failed_pc=0x0c062242u; return 0; }
r[5]+=r[10];
goto P_0c062244;
P_0c062244: /* original 1e23, guest PC 0x0c062244 */
if(!s->budget--) { s->failed_pc=0x0c062244u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c062246;
P_0c062246: /* original 2f52, guest PC 0x0c062246 */
if(!s->budget--) { s->failed_pc=0x0c062246u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062248;
P_0c062248: /* original 7504, guest PC 0x0c062248 */
if(!s->budget--) { s->failed_pc=0x0c062248u; return 0; }
r[5]+=0x00000004u;
goto P_0c06224a;
P_0c06224a: /* original b14b, guest PC 0x0c06224a */
if(!s->budget--) { s->failed_pc=0x0c06224au; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c06224eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06224eu) { target=s->pc; goto dispatch; }
goto P_0c06224e;
P_0c06224c: /* original 64f2, guest PC 0x0c06224c */
if(!s->budget--) { s->failed_pc=0x0c06224cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06224e;
P_0c06224e: /* original 63bf, guest PC 0x0c06224e */
if(!s->budget--) { s->failed_pc=0x0c06224eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c062250;
P_0c062250: /* original 52c3, guest PC 0x0c062250 */
if(!s->budget--) { s->failed_pc=0x0c062250u; return 0; }
r[2]=read(ram,r[12]+12,4);
goto P_0c062252;
P_0c062252: /* original 2338, guest PC 0x0c062252 */
if(!s->budget--) { s->failed_pc=0x0c062252u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062254;
P_0c062254: /* original 1922, guest PC 0x0c062254 */
if(!s->budget--) { s->failed_pc=0x0c062254u; return 0; }
write(ram,r[9]+8,r[2],4);
goto P_0c062256;
P_0c062256: /* original 8f05, guest PC 0x0c062256 */
if(!s->budget--) { s->failed_pc=0x0c062256u; return 0; }
cond=r[17]&1u;
write(ram,r[12]+20,r[9],4);
if(!cond) { goto P_0c062264; }
goto P_0c06225a;
P_0c062258: /* original 1c95, guest PC 0x0c062258 */
if(!s->budget--) { s->failed_pc=0x0c062258u; return 0; }
write(ram,r[12]+20,r[9],4);
goto P_0c06225a;
P_0c06225a: /* original 931e, guest PC 0x0c06225a */
if(!s->budget--) { s->failed_pc=0x0c06225au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06229au,2);
goto P_0c06225c;
P_0c06225c: /* original 62c1, guest PC 0x0c06225c */
if(!s->budget--) { s->failed_pc=0x0c06225cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[2]=tmp;
goto P_0c06225e;
P_0c06225e: /* original 223b, guest PC 0x0c06225e */
if(!s->budget--) { s->failed_pc=0x0c06225eu; return 0; }
r[2]|=r[3];
goto P_0c062260;
P_0c062260: /* original a004, guest PC 0x0c062260 */
if(!s->budget--) { s->failed_pc=0x0c062260u; return 0; }
write(ram,r[12],r[2],2);
goto P_0c06226c;
P_0c062262: /* original 2c21, guest PC 0x0c062262 */
if(!s->budget--) { s->failed_pc=0x0c062262u; return 0; }
write(ram,r[12],r[2],2);
goto P_0c062264;
P_0c062264: /* original 931a, guest PC 0x0c062264 */
if(!s->budget--) { s->failed_pc=0x0c062264u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06229cu,2);
goto P_0c062266;
P_0c062266: /* original 61c1, guest PC 0x0c062266 */
if(!s->budget--) { s->failed_pc=0x0c062266u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[1]=tmp;
goto P_0c062268;
P_0c062268: /* original 213b, guest PC 0x0c062268 */
if(!s->budget--) { s->failed_pc=0x0c062268u; return 0; }
r[1]|=r[3];
goto P_0c06226a;
P_0c06226a: /* original 2c11, guest PC 0x0c06226a */
if(!s->budget--) { s->failed_pc=0x0c06226au; return 0; }
write(ram,r[12],r[1],2);
goto P_0c06226c;
P_0c06226c: /* original 60c1, guest PC 0x0c06226c */
if(!s->budget--) { s->failed_pc=0x0c06226cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[0]=tmp;
goto P_0c06226e;
P_0c06226e: /* original 63b3, guest PC 0x0c06226e */
if(!s->budget--) { s->failed_pc=0x0c06226eu; return 0; }
r[3]=r[11];
goto P_0c062270;
P_0c062270: /* original cb04, guest PC 0x0c062270 */
if(!s->budget--) { s->failed_pc=0x0c062270u; return 0; }
r[0]|=4u;
goto P_0c062272;
P_0c062272: /* original 4b08, guest PC 0x0c062272 */
if(!s->budget--) { s->failed_pc=0x0c062272u; return 0; }
r[11]<<=2;
goto P_0c062274;
P_0c062274: /* original 2c01, guest PC 0x0c062274 */
if(!s->budget--) { s->failed_pc=0x0c062274u; return 0; }
write(ram,r[12],r[0],2);
goto P_0c062276;
P_0c062276: /* original 3b3c, guest PC 0x0c062276 */
if(!s->budget--) { s->failed_pc=0x0c062276u; return 0; }
r[11]+=r[3];
goto P_0c062278;
P_0c062278: /* original 53c4, guest PC 0x0c062278 */
if(!s->budget--) { s->failed_pc=0x0c062278u; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c06227a;
P_0c06227a: /* original 4b08, guest PC 0x0c06227a */
if(!s->budget--) { s->failed_pc=0x0c06227au; return 0; }
r[11]<<=2;
goto P_0c06227c;
P_0c06227c: /* original 6bbe, guest PC 0x0c06227c */
if(!s->budget--) { s->failed_pc=0x0c06227cu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c06227e;
P_0c06227e: /* original 3bac, guest PC 0x0c06227e */
if(!s->budget--) { s->failed_pc=0x0c06227eu; return 0; }
r[11]+=r[10];
goto P_0c062280;
P_0c062280: /* original 52b4, guest PC 0x0c062280 */
if(!s->budget--) { s->failed_pc=0x0c062280u; return 0; }
r[2]=read(ram,r[11]+16,4);
goto P_0c062282;
P_0c062282: /* original e000, guest PC 0x0c062282 */
if(!s->budget--) { s->failed_pc=0x0c062282u; return 0; }
r[0]=0x00000000u;
goto P_0c062284;
P_0c062284: /* original 3238, guest PC 0x0c062284 */
if(!s->budget--) { s->failed_pc=0x0c062284u; return 0; }
r[2]-=r[3];
goto P_0c062286;
P_0c062286: /* original 1b24, guest PC 0x0c062286 */
if(!s->budget--) { s->failed_pc=0x0c062286u; return 0; }
write(ram,r[11]+16,r[2],4);
goto P_0c062288;
P_0c062288: /* original 7f04, guest PC 0x0c062288 */
if(!s->budget--) { s->failed_pc=0x0c062288u; return 0; }
r[15]+=0x00000004u;
goto P_0c06228a;
P_0c06228a: /* original 4f26, guest PC 0x0c06228a */
if(!s->budget--) { s->failed_pc=0x0c06228au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06228c;
P_0c06228c: /* original 69f6, guest PC 0x0c06228c */
if(!s->budget--) { s->failed_pc=0x0c06228cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06228e;
P_0c06228e: /* original 6af6, guest PC 0x0c06228e */
if(!s->budget--) { s->failed_pc=0x0c06228eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c062290;
P_0c062290: /* original 6bf6, guest PC 0x0c062290 */
if(!s->budget--) { s->failed_pc=0x0c062290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c062292;
P_0c062292: /* original 6cf6, guest PC 0x0c062292 */
if(!s->budget--) { s->failed_pc=0x0c062292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c062294;
P_0c062294: /* original 6df6, guest PC 0x0c062294 */
if(!s->budget--) { s->failed_pc=0x0c062294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062296;
P_0c062296: /* original 000b, guest PC 0x0c062296 */
if(!s->budget--) { s->failed_pc=0x0c062296u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c062298: /* original 6ef6, guest PC 0x0c062298 */
if(!s->budget--) { s->failed_pc=0x0c062298u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06229au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06229au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
