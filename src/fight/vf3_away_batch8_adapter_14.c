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
int vf3_away_batch8_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0633e0u: goto P_0c0633e0;
case 0x0c0633e2u: goto P_0c0633e2;
case 0x0c0633e4u: goto P_0c0633e4;
case 0x0c0633e6u: goto P_0c0633e6;
case 0x0c0633e8u: goto P_0c0633e8;
case 0x0c0633eau: goto P_0c0633ea;
case 0x0c0633ecu: goto P_0c0633ec;
case 0x0c0633eeu: goto P_0c0633ee;
case 0x0c0633f0u: goto P_0c0633f0;
case 0x0c0633f2u: goto P_0c0633f2;
case 0x0c0633f4u: goto P_0c0633f4;
case 0x0c0633f6u: goto P_0c0633f6;
case 0x0c0633f8u: goto P_0c0633f8;
case 0x0c0633fau: goto P_0c0633fa;
case 0x0c0633fcu: goto P_0c0633fc;
case 0x0c0633feu: goto P_0c0633fe;
case 0x0c063400u: goto P_0c063400;
case 0x0c063402u: goto P_0c063402;
case 0x0c063404u: goto P_0c063404;
case 0x0c063406u: goto P_0c063406;
case 0x0c063408u: goto P_0c063408;
case 0x0c06340au: goto P_0c06340a;
case 0x0c063418u: goto P_0c063418;
case 0x0c06341au: goto P_0c06341a;
case 0x0c06341cu: goto P_0c06341c;
case 0x0c06341eu: goto P_0c06341e;
case 0x0c063420u: goto P_0c063420;
case 0x0c063422u: goto P_0c063422;
case 0x0c063424u: goto P_0c063424;
case 0x0c063426u: goto P_0c063426;
case 0x0c063428u: goto P_0c063428;
case 0x0c06342au: goto P_0c06342a;
case 0x0c06342cu: goto P_0c06342c;
case 0x0c06342eu: goto P_0c06342e;
case 0x0c063430u: goto P_0c063430;
case 0x0c063432u: goto P_0c063432;
case 0x0c063434u: goto P_0c063434;
case 0x0c0636a0u: goto P_0c0636a0;
case 0x0c0636a2u: goto P_0c0636a2;
case 0x0c0636a4u: goto P_0c0636a4;
case 0x0c0636a6u: goto P_0c0636a6;
case 0x0c0636a8u: goto P_0c0636a8;
case 0x0c0636aau: goto P_0c0636aa;
case 0x0c0636acu: goto P_0c0636ac;
case 0x0c0636aeu: goto P_0c0636ae;
case 0x0c0636b0u: goto P_0c0636b0;
case 0x0c0636b2u: goto P_0c0636b2;
case 0x0c0636b4u: goto P_0c0636b4;
case 0x0c0636b6u: goto P_0c0636b6;
case 0x0c0636b8u: goto P_0c0636b8;
case 0x0c0636bau: goto P_0c0636ba;
case 0x0c0636bcu: goto P_0c0636bc;
case 0x0c0636beu: goto P_0c0636be;
case 0x0c0636c0u: goto P_0c0636c0;
case 0x0c0636c2u: goto P_0c0636c2;
case 0x0c0636c4u: goto P_0c0636c4;
case 0x0c0636c6u: goto P_0c0636c6;
case 0x0c0636c8u: goto P_0c0636c8;
case 0x0c0636cau: goto P_0c0636ca;
case 0x0c0636ccu: goto P_0c0636cc;
case 0x0c0636ceu: goto P_0c0636ce;
case 0x0c0636d0u: goto P_0c0636d0;
case 0x0c0636d2u: goto P_0c0636d2;
case 0x0c0636d4u: goto P_0c0636d4;
case 0x0c0636d6u: goto P_0c0636d6;
case 0x0c0636d8u: goto P_0c0636d8;
case 0x0c0636dau: goto P_0c0636da;
case 0x0c0636dcu: goto P_0c0636dc;
case 0x0c0636deu: goto P_0c0636de;
case 0x0c0636e0u: goto P_0c0636e0;
case 0x0c0636e2u: goto P_0c0636e2;
case 0x0c0636e4u: goto P_0c0636e4;
case 0x0c0636e6u: goto P_0c0636e6;
case 0x0c0636e8u: goto P_0c0636e8;
case 0x0c0636eau: goto P_0c0636ea;
case 0x0c0636ecu: goto P_0c0636ec;
case 0x0c0636eeu: goto P_0c0636ee;
case 0x0c0636f0u: goto P_0c0636f0;
case 0x0c0636f2u: goto P_0c0636f2;
case 0x0c0636f4u: goto P_0c0636f4;
case 0x0c0636f6u: goto P_0c0636f6;
case 0x0c0636f8u: goto P_0c0636f8;
case 0x0c0636fau: goto P_0c0636fa;
case 0x0c0636fcu: goto P_0c0636fc;
case 0x0c06376cu: goto P_0c06376c;
case 0x0c06376eu: goto P_0c06376e;
case 0x0c063770u: goto P_0c063770;
case 0x0c063772u: goto P_0c063772;
case 0x0c063774u: goto P_0c063774;
case 0x0c063776u: goto P_0c063776;
case 0x0c063778u: goto P_0c063778;
case 0x0c06377au: goto P_0c06377a;
case 0x0c06377cu: goto P_0c06377c;
case 0x0c06377eu: goto P_0c06377e;
case 0x0c063780u: goto P_0c063780;
case 0x0c063782u: goto P_0c063782;
case 0x0c063784u: goto P_0c063784;
case 0x0c063786u: goto P_0c063786;
case 0x0c063788u: goto P_0c063788;
case 0x0c06378au: goto P_0c06378a;
case 0x0c06378cu: goto P_0c06378c;
case 0x0c06378eu: goto P_0c06378e;
case 0x0c063790u: goto P_0c063790;
case 0x0c063792u: goto P_0c063792;
case 0x0c063794u: goto P_0c063794;
case 0x0c063796u: goto P_0c063796;
case 0x0c063798u: goto P_0c063798;
case 0x0c06379au: goto P_0c06379a;
case 0x0c06379cu: goto P_0c06379c;
case 0x0c06379eu: goto P_0c06379e;
case 0x0c0637a0u: goto P_0c0637a0;
case 0x0c0637a2u: goto P_0c0637a2;
case 0x0c0637a4u: goto P_0c0637a4;
case 0x0c0637a6u: goto P_0c0637a6;
case 0x0c0637a8u: goto P_0c0637a8;
case 0x0c0637aau: goto P_0c0637aa;
case 0x0c0637acu: goto P_0c0637ac;
case 0x0c0637aeu: goto P_0c0637ae;
case 0x0c0637b0u: goto P_0c0637b0;
case 0x0c0637b2u: goto P_0c0637b2;
case 0x0c0637b4u: goto P_0c0637b4;
case 0x0c0637b6u: goto P_0c0637b6;
case 0x0c0637b8u: goto P_0c0637b8;
case 0x0c0637bau: goto P_0c0637ba;
case 0x0c0637bcu: goto P_0c0637bc;
case 0x0c0637beu: goto P_0c0637be;
case 0x0c0637c0u: goto P_0c0637c0;
case 0x0c0637c2u: goto P_0c0637c2;
case 0x0c0637c4u: goto P_0c0637c4;
case 0x0c0637c6u: goto P_0c0637c6;
case 0x0c0637c8u: goto P_0c0637c8;
case 0x0c0637cau: goto P_0c0637ca;
case 0x0c0637ccu: goto P_0c0637cc;
case 0x0c0637ceu: goto P_0c0637ce;
case 0x0c0637d0u: goto P_0c0637d0;
case 0x0c0637d2u: goto P_0c0637d2;
case 0x0c0637d4u: goto P_0c0637d4;
case 0x0c0637d6u: goto P_0c0637d6;
case 0x0c0637d8u: goto P_0c0637d8;
case 0x0c0637dau: goto P_0c0637da;
case 0x0c0637dcu: goto P_0c0637dc;
case 0x0c0637deu: goto P_0c0637de;
case 0x0c0637e0u: goto P_0c0637e0;
case 0x0c0637e2u: goto P_0c0637e2;
case 0x0c0637e4u: goto P_0c0637e4;
case 0x0c0637e6u: goto P_0c0637e6;
case 0x0c0637e8u: goto P_0c0637e8;
case 0x0c0637eau: goto P_0c0637ea;
case 0x0c0637ecu: goto P_0c0637ec;
case 0x0c0637eeu: goto P_0c0637ee;
case 0x0c0637f0u: goto P_0c0637f0;
case 0x0c0637f2u: goto P_0c0637f2;
case 0x0c0637f4u: goto P_0c0637f4;
case 0x0c0637f6u: goto P_0c0637f6;
case 0x0c0637f8u: goto P_0c0637f8;
case 0x0c0637fau: goto P_0c0637fa;
case 0x0c0637fcu: goto P_0c0637fc;
case 0x0c0637feu: goto P_0c0637fe;
case 0x0c063800u: goto P_0c063800;
case 0x0c063802u: goto P_0c063802;
case 0x0c063804u: goto P_0c063804;
case 0x0c063806u: goto P_0c063806;
case 0x0c063808u: goto P_0c063808;
case 0x0c06380au: goto P_0c06380a;
case 0x0c06380cu: goto P_0c06380c;
case 0x0c06380eu: goto P_0c06380e;
case 0x0c063810u: goto P_0c063810;
case 0x0c063812u: goto P_0c063812;
case 0x0c063814u: goto P_0c063814;
case 0x0c063816u: goto P_0c063816;
case 0x0c063818u: goto P_0c063818;
case 0x0c06381au: goto P_0c06381a;
case 0x0c06381cu: goto P_0c06381c;
case 0x0c06381eu: goto P_0c06381e;
case 0x0c063820u: goto P_0c063820;
case 0x0c063822u: goto P_0c063822;
case 0x0c063824u: goto P_0c063824;
case 0x0c063826u: goto P_0c063826;
case 0x0c063828u: goto P_0c063828;
case 0x0c06382au: goto P_0c06382a;
case 0x0c06382cu: goto P_0c06382c;
case 0x0c06382eu: goto P_0c06382e;
case 0x0c063884u: goto P_0c063884;
case 0x0c063886u: goto P_0c063886;
case 0x0c063888u: goto P_0c063888;
case 0x0c06388au: goto P_0c06388a;
case 0x0c06388cu: goto P_0c06388c;
case 0x0c06388eu: goto P_0c06388e;
case 0x0c063890u: goto P_0c063890;
case 0x0c063892u: goto P_0c063892;
case 0x0c063894u: goto P_0c063894;
case 0x0c063896u: goto P_0c063896;
case 0x0c063898u: goto P_0c063898;
case 0x0c06389au: goto P_0c06389a;
case 0x0c06389cu: goto P_0c06389c;
case 0x0c06389eu: goto P_0c06389e;
case 0x0c0638a0u: goto P_0c0638a0;
case 0x0c0638a2u: goto P_0c0638a2;
case 0x0c0638a4u: goto P_0c0638a4;
case 0x0c0638a6u: goto P_0c0638a6;
case 0x0c0638a8u: goto P_0c0638a8;
case 0x0c0638aau: goto P_0c0638aa;
case 0x0c0638acu: goto P_0c0638ac;
case 0x0c0638aeu: goto P_0c0638ae;
case 0x0c0638b0u: goto P_0c0638b0;
case 0x0c0638b2u: goto P_0c0638b2;
case 0x0c0638b4u: goto P_0c0638b4;
case 0x0c0638b6u: goto P_0c0638b6;
case 0x0c0638b8u: goto P_0c0638b8;
case 0x0c0638bau: goto P_0c0638ba;
case 0x0c0638bcu: goto P_0c0638bc;
case 0x0c0638beu: goto P_0c0638be;
case 0x0c0638c0u: goto P_0c0638c0;
case 0x0c0638c2u: goto P_0c0638c2;
case 0x0c0638c4u: goto P_0c0638c4;
case 0x0c0638c6u: goto P_0c0638c6;
case 0x0c0638c8u: goto P_0c0638c8;
case 0x0c0638cau: goto P_0c0638ca;
case 0x0c0638ccu: goto P_0c0638cc;
case 0x0c0638ceu: goto P_0c0638ce;
case 0x0c0638d0u: goto P_0c0638d0;
case 0x0c0638d2u: goto P_0c0638d2;
case 0x0c0638d4u: goto P_0c0638d4;
case 0x0c0638d6u: goto P_0c0638d6;
case 0x0c0638d8u: goto P_0c0638d8;
case 0x0c0638dau: goto P_0c0638da;
case 0x0c0638dcu: goto P_0c0638dc;
case 0x0c0638deu: goto P_0c0638de;
case 0x0c0638e0u: goto P_0c0638e0;
case 0x0c0638e2u: goto P_0c0638e2;
case 0x0c0638e4u: goto P_0c0638e4;
case 0x0c0638e6u: goto P_0c0638e6;
case 0x0c0638e8u: goto P_0c0638e8;
case 0x0c0638eau: goto P_0c0638ea;
case 0x0c0638ecu: goto P_0c0638ec;
case 0x0c0638eeu: goto P_0c0638ee;
case 0x0c0638f0u: goto P_0c0638f0;
case 0x0c0638f2u: goto P_0c0638f2;
case 0x0c0638f4u: goto P_0c0638f4;
case 0x0c0638f6u: goto P_0c0638f6;
case 0x0c0638f8u: goto P_0c0638f8;
case 0x0c0638fau: goto P_0c0638fa;
case 0x0c0638fcu: goto P_0c0638fc;
case 0x0c0638feu: goto P_0c0638fe;
case 0x0c063900u: goto P_0c063900;
case 0x0c063902u: goto P_0c063902;
case 0x0c063904u: goto P_0c063904;
case 0x0c063906u: goto P_0c063906;
case 0x0c063908u: goto P_0c063908;
case 0x0c06390au: goto P_0c06390a;
case 0x0c06390cu: goto P_0c06390c;
case 0x0c06390eu: goto P_0c06390e;
case 0x0c063910u: goto P_0c063910;
case 0x0c063912u: goto P_0c063912;
case 0x0c063914u: goto P_0c063914;
case 0x0c063916u: goto P_0c063916;
case 0x0c063918u: goto P_0c063918;
case 0x0c06391au: goto P_0c06391a;
case 0x0c06391cu: goto P_0c06391c;
case 0x0c06391eu: goto P_0c06391e;
case 0x0c063920u: goto P_0c063920;
case 0x0c063922u: goto P_0c063922;
case 0x0c063924u: goto P_0c063924;
case 0x0c063926u: goto P_0c063926;
case 0x0c063928u: goto P_0c063928;
case 0x0c06392au: goto P_0c06392a;
case 0x0c06392cu: goto P_0c06392c;
case 0x0c06392eu: goto P_0c06392e;
case 0x0c063930u: goto P_0c063930;
case 0x0c063932u: goto P_0c063932;
case 0x0c063934u: goto P_0c063934;
case 0x0c063936u: goto P_0c063936;
case 0x0c063938u: goto P_0c063938;
case 0x0c06393au: goto P_0c06393a;
case 0x0c06393cu: goto P_0c06393c;
case 0x0c06393eu: goto P_0c06393e;
case 0x0c063940u: goto P_0c063940;
case 0x0c063942u: goto P_0c063942;
case 0x0c063944u: goto P_0c063944;
case 0x0c063946u: goto P_0c063946;
case 0x0c063948u: goto P_0c063948;
case 0x0c06394au: goto P_0c06394a;
case 0x0c06394cu: goto P_0c06394c;
case 0x0c06394eu: goto P_0c06394e;
case 0x0c063950u: goto P_0c063950;
case 0x0c063952u: goto P_0c063952;
case 0x0c063954u: goto P_0c063954;
case 0x0c063956u: goto P_0c063956;
case 0x0c063958u: goto P_0c063958;
case 0x0c06395au: goto P_0c06395a;
case 0x0c06395cu: goto P_0c06395c;
case 0x0c06395eu: goto P_0c06395e;
case 0x0c063960u: goto P_0c063960;
case 0x0c063962u: goto P_0c063962;
case 0x0c063964u: goto P_0c063964;
case 0x0c063966u: goto P_0c063966;
case 0x0c063968u: goto P_0c063968;
case 0x0c06396au: goto P_0c06396a;
case 0x0c06396cu: goto P_0c06396c;
case 0x0c06396eu: goto P_0c06396e;
case 0x0c063970u: goto P_0c063970;
case 0x0c063972u: goto P_0c063972;
case 0x0c063974u: goto P_0c063974;
case 0x0c063976u: goto P_0c063976;
case 0x0c063978u: goto P_0c063978;
case 0x0c06397au: goto P_0c06397a;
case 0x0c06397cu: goto P_0c06397c;
case 0x0c06397eu: goto P_0c06397e;
case 0x0c063980u: goto P_0c063980;
case 0x0c063982u: goto P_0c063982;
case 0x0c063984u: goto P_0c063984;
case 0x0c063986u: goto P_0c063986;
case 0x0c063988u: goto P_0c063988;
case 0x0c06398au: goto P_0c06398a;
case 0x0c06398cu: goto P_0c06398c;
case 0x0c06398eu: goto P_0c06398e;
case 0x0c063990u: goto P_0c063990;
case 0x0c063992u: goto P_0c063992;
case 0x0c063994u: goto P_0c063994;
case 0x0c063996u: goto P_0c063996;
case 0x0c063998u: goto P_0c063998;
case 0x0c06399au: goto P_0c06399a;
case 0x0c06399cu: goto P_0c06399c;
case 0x0c06399eu: goto P_0c06399e;
case 0x0c0639a0u: goto P_0c0639a0;
case 0x0c0639a2u: goto P_0c0639a2;
case 0x0c0639a4u: goto P_0c0639a4;
case 0x0c0639a6u: goto P_0c0639a6;
case 0x0c0639a8u: goto P_0c0639a8;
case 0x0c0639aau: goto P_0c0639aa;
case 0x0c0639acu: goto P_0c0639ac;
case 0x0c0639aeu: goto P_0c0639ae;
case 0x0c0639b0u: goto P_0c0639b0;
case 0x0c0639b2u: goto P_0c0639b2;
case 0x0c0639b4u: goto P_0c0639b4;
case 0x0c063a18u: goto P_0c063a18;
case 0x0c063a1au: goto P_0c063a1a;
case 0x0c063a1cu: goto P_0c063a1c;
case 0x0c063a1eu: goto P_0c063a1e;
case 0x0c063a20u: goto P_0c063a20;
case 0x0c063a22u: goto P_0c063a22;
case 0x0c063a24u: goto P_0c063a24;
case 0x0c063a26u: goto P_0c063a26;
case 0x0c063a28u: goto P_0c063a28;
case 0x0c063a2au: goto P_0c063a2a;
case 0x0c063a2cu: goto P_0c063a2c;
case 0x0c063a2eu: goto P_0c063a2e;
case 0x0c063a30u: goto P_0c063a30;
case 0x0c063a32u: goto P_0c063a32;
case 0x0c063a34u: goto P_0c063a34;
case 0x0c063a36u: goto P_0c063a36;
case 0x0c063a38u: goto P_0c063a38;
case 0x0c063a3au: goto P_0c063a3a;
case 0x0c063a3cu: goto P_0c063a3c;
case 0x0c063a3eu: goto P_0c063a3e;
case 0x0c063a40u: goto P_0c063a40;
case 0x0c063a42u: goto P_0c063a42;
case 0x0c063a44u: goto P_0c063a44;
case 0x0c063a46u: goto P_0c063a46;
case 0x0c063a48u: goto P_0c063a48;
case 0x0c063a4au: goto P_0c063a4a;
case 0x0c063a4cu: goto P_0c063a4c;
case 0x0c063a4eu: goto P_0c063a4e;
case 0x0c063a50u: goto P_0c063a50;
case 0x0c063a52u: goto P_0c063a52;
case 0x0c063a54u: goto P_0c063a54;
case 0x0c063a56u: goto P_0c063a56;
case 0x0c063a58u: goto P_0c063a58;
case 0x0c063a5au: goto P_0c063a5a;
case 0x0c063a5cu: goto P_0c063a5c;
case 0x0c063a5eu: goto P_0c063a5e;
case 0x0c063a60u: goto P_0c063a60;
case 0x0c063a62u: goto P_0c063a62;
case 0x0c063a64u: goto P_0c063a64;
case 0x0c063a66u: goto P_0c063a66;
case 0x0c063a68u: goto P_0c063a68;
case 0x0c063a6au: goto P_0c063a6a;
case 0x0c063a6cu: goto P_0c063a6c;
case 0x0c063a6eu: goto P_0c063a6e;
case 0x0c063a70u: goto P_0c063a70;
case 0x0c063a72u: goto P_0c063a72;
case 0x0c063a74u: goto P_0c063a74;
case 0x0c063a76u: goto P_0c063a76;
case 0x0c063a78u: goto P_0c063a78;
case 0x0c063a7au: goto P_0c063a7a;
case 0x0c063a7cu: goto P_0c063a7c;
case 0x0c063a7eu: goto P_0c063a7e;
case 0x0c063a80u: goto P_0c063a80;
case 0x0c063a82u: goto P_0c063a82;
case 0x0c063a84u: goto P_0c063a84;
case 0x0c063a86u: goto P_0c063a86;
case 0x0c063a88u: goto P_0c063a88;
case 0x0c063a8au: goto P_0c063a8a;
case 0x0c063a8cu: goto P_0c063a8c;
case 0x0c063a8eu: goto P_0c063a8e;
case 0x0c063a90u: goto P_0c063a90;
case 0x0c063a92u: goto P_0c063a92;
case 0x0c063a94u: goto P_0c063a94;
case 0x0c063a96u: goto P_0c063a96;
case 0x0c063a98u: goto P_0c063a98;
case 0x0c063a9au: goto P_0c063a9a;
case 0x0c063a9cu: goto P_0c063a9c;
case 0x0c063a9eu: goto P_0c063a9e;
case 0x0c063aa0u: goto P_0c063aa0;
case 0x0c063aa2u: goto P_0c063aa2;
case 0x0c063aa4u: goto P_0c063aa4;
case 0x0c063aa6u: goto P_0c063aa6;
case 0x0c063aa8u: goto P_0c063aa8;
case 0x0c063aaau: goto P_0c063aaa;
case 0x0c063aacu: goto P_0c063aac;
case 0x0c063aaeu: goto P_0c063aae;
case 0x0c063ab0u: goto P_0c063ab0;
case 0x0c063ab2u: goto P_0c063ab2;
case 0x0c063ab4u: goto P_0c063ab4;
case 0x0c063ab6u: goto P_0c063ab6;
case 0x0c063ab8u: goto P_0c063ab8;
case 0x0c063abau: goto P_0c063aba;
case 0x0c063abcu: goto P_0c063abc;
case 0x0c063abeu: goto P_0c063abe;
case 0x0c063ac0u: goto P_0c063ac0;
case 0x0c063ac2u: goto P_0c063ac2;
case 0x0c063ac4u: goto P_0c063ac4;
case 0x0c063ac6u: goto P_0c063ac6;
case 0x0c063ac8u: goto P_0c063ac8;
case 0x0c063acau: goto P_0c063aca;
case 0x0c063accu: goto P_0c063acc;
case 0x0c063aceu: goto P_0c063ace;
case 0x0c063ad0u: goto P_0c063ad0;
case 0x0c063ad2u: goto P_0c063ad2;
case 0x0c063ad4u: goto P_0c063ad4;
case 0x0c063ad6u: goto P_0c063ad6;
case 0x0c063ad8u: goto P_0c063ad8;
case 0x0c063adau: goto P_0c063ada;
case 0x0c063adcu: goto P_0c063adc;
case 0x0c063adeu: goto P_0c063ade;
case 0x0c063ae0u: goto P_0c063ae0;
case 0x0c063ae2u: goto P_0c063ae2;
case 0x0c063ae4u: goto P_0c063ae4;
case 0x0c063ae6u: goto P_0c063ae6;
case 0x0c063ae8u: goto P_0c063ae8;
case 0x0c063aeau: goto P_0c063aea;
case 0x0c063aecu: goto P_0c063aec;
case 0x0c063aeeu: goto P_0c063aee;
case 0x0c063af0u: goto P_0c063af0;
case 0x0c063af2u: goto P_0c063af2;
case 0x0c063af4u: goto P_0c063af4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0633e0: /* original 4f22, guest PC 0x0c0633e0 */
if(!s->budget--) { s->failed_pc=0x0c0633e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0633e2;
P_0c0633e2: /* original 7ff8, guest PC 0x0c0633e2 */
if(!s->budget--) { s->failed_pc=0x0c0633e2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0633e4;
P_0c0633e4: /* original d30a, guest PC 0x0c0633e4 */
if(!s->budget--) { s->failed_pc=0x0c0633e4u; return 0; }
r[3]=read(ram,0x0c063410u,4);
goto P_0c0633e6;
P_0c0633e6: /* original 2f52, guest PC 0x0c0633e6 */
if(!s->budget--) { s->failed_pc=0x0c0633e6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0633e8;
P_0c0633e8: /* original d508, guest PC 0x0c0633e8 */
if(!s->budget--) { s->failed_pc=0x0c0633e8u; return 0; }
r[5]=read(ram,0x0c06340cu,4);
goto P_0c0633ea;
P_0c0633ea: /* original 430b, guest PC 0x0c0633ea */
if(!s->budget--) { s->failed_pc=0x0c0633eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0633eeu;
write(ram,r[15]+4,r[6],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0633eeu) { target=s->pc; goto dispatch; }
goto P_0c0633ee;
P_0c0633ec: /* original 1f61, guest PC 0x0c0633ec */
if(!s->budget--) { s->failed_pc=0x0c0633ecu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0633ee;
P_0c0633ee: /* original 2008, guest PC 0x0c0633ee */
if(!s->budget--) { s->failed_pc=0x0c0633eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0633f0;
P_0c0633f0: /* original 8b07, guest PC 0x0c0633f0 */
if(!s->budget--) { s->failed_pc=0x0c0633f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063402; }
goto P_0c0633f2;
P_0c0633f2: /* original d508, guest PC 0x0c0633f2 */
if(!s->budget--) { s->failed_pc=0x0c0633f2u; return 0; }
r[5]=read(ram,0x0c063414u,4);
goto P_0c0633f4;
P_0c0633f4: /* original d306, guest PC 0x0c0633f4 */
if(!s->budget--) { s->failed_pc=0x0c0633f4u; return 0; }
r[3]=read(ram,0x0c063410u,4);
goto P_0c0633f6;
P_0c0633f6: /* original 430b, guest PC 0x0c0633f6 */
if(!s->budget--) { s->failed_pc=0x0c0633f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0633fau;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0633fau) { target=s->pc; goto dispatch; }
goto P_0c0633fa;
P_0c0633f8: /* original 64f2, guest PC 0x0c0633f8 */
if(!s->budget--) { s->failed_pc=0x0c0633f8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0633fa;
P_0c0633fa: /* original 2008, guest PC 0x0c0633fa */
if(!s->budget--) { s->failed_pc=0x0c0633fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0633fc;
P_0c0633fc: /* original 8b02, guest PC 0x0c0633fc */
if(!s->budget--) { s->failed_pc=0x0c0633fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063404; }
goto P_0c0633fe;
P_0c0633fe: /* original a001, guest PC 0x0c0633fe */
if(!s->budget--) { s->failed_pc=0x0c0633feu; return 0; }
r[4]=0x00000000u;
goto P_0c063404;
P_0c063400: /* original e400, guest PC 0x0c063400 */
if(!s->budget--) { s->failed_pc=0x0c063400u; return 0; }
r[4]=0x00000000u;
goto P_0c063402;
P_0c063402: /* original 54f1, guest PC 0x0c063402 */
if(!s->budget--) { s->failed_pc=0x0c063402u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c063404;
P_0c063404: /* original 7f08, guest PC 0x0c063404 */
if(!s->budget--) { s->failed_pc=0x0c063404u; return 0; }
r[15]+=0x00000008u;
goto P_0c063406;
P_0c063406: /* original 4f26, guest PC 0x0c063406 */
if(!s->budget--) { s->failed_pc=0x0c063406u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063408;
P_0c063408: /* original 000b, guest PC 0x0c063408 */
if(!s->budget--) { s->failed_pc=0x0c063408u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c06340a: /* original 6043, guest PC 0x0c06340a */
if(!s->budget--) { s->failed_pc=0x0c06340au; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c06340cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06340cu; return 0; } return 1;
P_0c063418: /* original 2fe6, guest PC 0x0c063418 */
if(!s->budget--) { s->failed_pc=0x0c063418u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06341a;
P_0c06341a: /* original e503, guest PC 0x0c06341a */
if(!s->budget--) { s->failed_pc=0x0c06341au; return 0; }
r[5]=0x00000003u;
goto P_0c06341c;
P_0c06341c: /* original 4f22, guest PC 0x0c06341c */
if(!s->budget--) { s->failed_pc=0x0c06341cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06341e;
P_0c06341e: /* original de34, guest PC 0x0c06341e */
if(!s->budget--) { s->failed_pc=0x0c06341eu; return 0; }
r[14]=read(ram,0x0c0634f0u,4);
goto P_0c063420;
P_0c063420: /* original 4e0b, guest PC 0x0c063420 */
if(!s->budget--) { s->failed_pc=0x0c063420u; return 0; }
target=r[14];
r[16]=code_base|0x0c063424u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063424u) { target=s->pc; goto dispatch; }
goto P_0c063424;
P_0c063422: /* original e408, guest PC 0x0c063422 */
if(!s->budget--) { s->failed_pc=0x0c063422u; return 0; }
r[4]=0x00000008u;
goto P_0c063424;
P_0c063424: /* original e500, guest PC 0x0c063424 */
if(!s->budget--) { s->failed_pc=0x0c063424u; return 0; }
r[5]=0x00000000u;
goto P_0c063426;
P_0c063426: /* original 4e0b, guest PC 0x0c063426 */
if(!s->budget--) { s->failed_pc=0x0c063426u; return 0; }
target=r[14];
r[16]=code_base|0x0c06342au;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06342au) { target=s->pc; goto dispatch; }
goto P_0c06342a;
P_0c063428: /* original 6453, guest PC 0x0c063428 */
if(!s->budget--) { s->failed_pc=0x0c063428u; return 0; }
r[4]=r[5];
goto P_0c06342a;
P_0c06342a: /* original e500, guest PC 0x0c06342a */
if(!s->budget--) { s->failed_pc=0x0c06342au; return 0; }
r[5]=0x00000000u;
goto P_0c06342c;
P_0c06342c: /* original 4e0b, guest PC 0x0c06342c */
if(!s->budget--) { s->failed_pc=0x0c06342cu; return 0; }
target=r[14];
r[16]=code_base|0x0c063430u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063430u) { target=s->pc; goto dispatch; }
goto P_0c063430;
P_0c06342e: /* original e408, guest PC 0x0c06342e */
if(!s->budget--) { s->failed_pc=0x0c06342eu; return 0; }
r[4]=0x00000008u;
goto P_0c063430;
P_0c063430: /* original 4f26, guest PC 0x0c063430 */
if(!s->budget--) { s->failed_pc=0x0c063430u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063432;
P_0c063432: /* original 000b, guest PC 0x0c063432 */
if(!s->budget--) { s->failed_pc=0x0c063432u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c063434: /* original 6ef6, guest PC 0x0c063434 */
if(!s->budget--) { s->failed_pc=0x0c063434u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c063436u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c063436u; return 0; } return 1;
P_0c0636a0: /* original 2fe6, guest PC 0x0c0636a0 */
if(!s->budget--) { s->failed_pc=0x0c0636a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0636a2;
P_0c0636a2: /* original 2fd6, guest PC 0x0c0636a2 */
if(!s->budget--) { s->failed_pc=0x0c0636a2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0636a4;
P_0c0636a4: /* original 2fc6, guest PC 0x0c0636a4 */
if(!s->budget--) { s->failed_pc=0x0c0636a4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0636a6;
P_0c0636a6: /* original 2fb6, guest PC 0x0c0636a6 */
if(!s->budget--) { s->failed_pc=0x0c0636a6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0636a8;
P_0c0636a8: /* original 2fa6, guest PC 0x0c0636a8 */
if(!s->budget--) { s->failed_pc=0x0c0636a8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0636aa;
P_0c0636aa: /* original 2f96, guest PC 0x0c0636aa */
if(!s->budget--) { s->failed_pc=0x0c0636aau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0636ac;
P_0c0636ac: /* original 4f22, guest PC 0x0c0636ac */
if(!s->budget--) { s->failed_pc=0x0c0636acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0636ae;
P_0c0636ae: /* original db18, guest PC 0x0c0636ae */
if(!s->budget--) { s->failed_pc=0x0c0636aeu; return 0; }
r[11]=read(ram,0x0c063710u,4);
goto P_0c0636b0;
P_0c0636b0: /* original d518, guest PC 0x0c0636b0 */
if(!s->budget--) { s->failed_pc=0x0c0636b0u; return 0; }
r[5]=read(ram,0x0c063714u,4);
goto P_0c0636b2;
P_0c0636b2: /* original 9426, guest PC 0x0c0636b2 */
if(!s->budget--) { s->failed_pc=0x0c0636b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063702u,2);
goto P_0c0636b4;
P_0c0636b4: /* original 4b0b, guest PC 0x0c0636b4 */
if(!s->budget--) { s->failed_pc=0x0c0636b4u; return 0; }
target=r[11];
r[16]=code_base|0x0c0636b8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0636b8u) { target=s->pc; goto dispatch; }
goto P_0c0636b8;
P_0c0636b6: /* original 0009, guest PC 0x0c0636b6 */
if(!s->budget--) { s->failed_pc=0x0c0636b6u; return 0; }
goto P_0c0636b8;
P_0c0636b8: /* original d517, guest PC 0x0c0636b8 */
if(!s->budget--) { s->failed_pc=0x0c0636b8u; return 0; }
r[5]=read(ram,0x0c063718u,4);
goto P_0c0636ba;
P_0c0636ba: /* original 9423, guest PC 0x0c0636ba */
if(!s->budget--) { s->failed_pc=0x0c0636bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063704u,2);
goto P_0c0636bc;
P_0c0636bc: /* original 4b0b, guest PC 0x0c0636bc */
if(!s->budget--) { s->failed_pc=0x0c0636bcu; return 0; }
target=r[11];
r[16]=code_base|0x0c0636c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0636c0u) { target=s->pc; goto dispatch; }
goto P_0c0636c0;
P_0c0636be: /* original 0009, guest PC 0x0c0636be */
if(!s->budget--) { s->failed_pc=0x0c0636beu; return 0; }
goto P_0c0636c0;
P_0c0636c0: /* original d515, guest PC 0x0c0636c0 */
if(!s->budget--) { s->failed_pc=0x0c0636c0u; return 0; }
r[5]=read(ram,0x0c063718u,4);
goto P_0c0636c2;
P_0c0636c2: /* original 9420, guest PC 0x0c0636c2 */
if(!s->budget--) { s->failed_pc=0x0c0636c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063706u,2);
goto P_0c0636c4;
P_0c0636c4: /* original 4b0b, guest PC 0x0c0636c4 */
if(!s->budget--) { s->failed_pc=0x0c0636c4u; return 0; }
target=r[11];
r[16]=code_base|0x0c0636c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0636c8u) { target=s->pc; goto dispatch; }
goto P_0c0636c8;
P_0c0636c6: /* original 0009, guest PC 0x0c0636c6 */
if(!s->budget--) { s->failed_pc=0x0c0636c6u; return 0; }
goto P_0c0636c8;
P_0c0636c8: /* original 9e1e, guest PC 0x0c0636c8 */
if(!s->budget--) { s->failed_pc=0x0c0636c8u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063708u,2);
goto P_0c0636ca;
P_0c0636ca: /* original ea00, guest PC 0x0c0636ca */
if(!s->budget--) { s->failed_pc=0x0c0636cau; return 0; }
r[10]=0x00000000u;
goto P_0c0636cc;
P_0c0636cc: /* original 9c1d, guest PC 0x0c0636cc */
if(!s->budget--) { s->failed_pc=0x0c0636ccu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06370au,2);
goto P_0c0636ce;
P_0c0636ce: /* original 69c3, guest PC 0x0c0636ce */
if(!s->budget--) { s->failed_pc=0x0c0636ceu; return 0; }
r[9]=r[12];
goto P_0c0636d0;
P_0c0636d0: /* original 9d1c, guest PC 0x0c0636d0 */
if(!s->budget--) { s->failed_pc=0x0c0636d0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06370cu,2);
goto P_0c0636d2;
P_0c0636d2: /* original 7982, guest PC 0x0c0636d2 */
if(!s->budget--) { s->failed_pc=0x0c0636d2u; return 0; }
r[9]+=0xffffff82u;
goto P_0c0636d4;
P_0c0636d4: /* original 65dc, guest PC 0x0c0636d4 */
if(!s->budget--) { s->failed_pc=0x0c0636d4u; return 0; }
r[5]=r[13]&255u;
goto P_0c0636d6;
P_0c0636d6: /* original 4518, guest PC 0x0c0636d6 */
if(!s->budget--) { s->failed_pc=0x0c0636d6u; return 0; }
r[5]<<=8;
goto P_0c0636d8;
P_0c0636d8: /* original 63cc, guest PC 0x0c0636d8 */
if(!s->budget--) { s->failed_pc=0x0c0636d8u; return 0; }
r[3]=r[12]&255u;
goto P_0c0636da;
P_0c0636da: /* original 253b, guest PC 0x0c0636da */
if(!s->budget--) { s->failed_pc=0x0c0636dau; return 0; }
r[5]|=r[3];
goto P_0c0636dc;
P_0c0636dc: /* original 655d, guest PC 0x0c0636dc */
if(!s->budget--) { s->failed_pc=0x0c0636dcu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0636de;
P_0c0636de: /* original 4b0b, guest PC 0x0c0636de */
if(!s->budget--) { s->failed_pc=0x0c0636deu; return 0; }
target=r[11];
r[16]=code_base|0x0c0636e2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0636e2u) { target=s->pc; goto dispatch; }
goto P_0c0636e2;
P_0c0636e0: /* original 64e3, guest PC 0x0c0636e0 */
if(!s->budget--) { s->failed_pc=0x0c0636e0u; return 0; }
r[4]=r[14];
goto P_0c0636e2;
P_0c0636e2: /* original 7a01, guest PC 0x0c0636e2 */
if(!s->budget--) { s->failed_pc=0x0c0636e2u; return 0; }
r[10]+=0x00000001u;
goto P_0c0636e4;
P_0c0636e4: /* original 7e04, guest PC 0x0c0636e4 */
if(!s->budget--) { s->failed_pc=0x0c0636e4u; return 0; }
r[14]+=0x00000004u;
goto P_0c0636e6;
P_0c0636e6: /* original 7cff, guest PC 0x0c0636e6 */
if(!s->budget--) { s->failed_pc=0x0c0636e6u; return 0; }
r[12]+=0xffffffffu;
goto P_0c0636e8;
P_0c0636e8: /* original 3a93, guest PC 0x0c0636e8 */
if(!s->budget--) { s->failed_pc=0x0c0636e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c0636ea;
P_0c0636ea: /* original 8ff3, guest PC 0x0c0636ea */
if(!s->budget--) { s->failed_pc=0x0c0636eau; return 0; }
cond=r[17]&1u;
r[13]+=0xffffffffu;
if(!cond) { goto P_0c0636d4; }
goto P_0c0636ee;
P_0c0636ec: /* original 7dff, guest PC 0x0c0636ec */
if(!s->budget--) { s->failed_pc=0x0c0636ecu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0636ee;
P_0c0636ee: /* original 4f26, guest PC 0x0c0636ee */
if(!s->budget--) { s->failed_pc=0x0c0636eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0636f0;
P_0c0636f0: /* original 69f6, guest PC 0x0c0636f0 */
if(!s->budget--) { s->failed_pc=0x0c0636f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0636f2;
P_0c0636f2: /* original 6af6, guest PC 0x0c0636f2 */
if(!s->budget--) { s->failed_pc=0x0c0636f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0636f4;
P_0c0636f4: /* original 6bf6, guest PC 0x0c0636f4 */
if(!s->budget--) { s->failed_pc=0x0c0636f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0636f6;
P_0c0636f6: /* original 6cf6, guest PC 0x0c0636f6 */
if(!s->budget--) { s->failed_pc=0x0c0636f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0636f8;
P_0c0636f8: /* original 6df6, guest PC 0x0c0636f8 */
if(!s->budget--) { s->failed_pc=0x0c0636f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0636fa;
P_0c0636fa: /* original 000b, guest PC 0x0c0636fa */
if(!s->budget--) { s->failed_pc=0x0c0636fau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0636fc: /* original 6ef6, guest PC 0x0c0636fc */
if(!s->budget--) { s->failed_pc=0x0c0636fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0636feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0636feu; return 0; } return 1;
P_0c06376c: /* original 2fe6, guest PC 0x0c06376c */
if(!s->budget--) { s->failed_pc=0x0c06376cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06376e;
P_0c06376e: /* original e500, guest PC 0x0c06376e */
if(!s->budget--) { s->failed_pc=0x0c06376eu; return 0; }
r[5]=0x00000000u;
goto P_0c063770;
P_0c063770: /* original d639, guest PC 0x0c063770 */
if(!s->budget--) { s->failed_pc=0x0c063770u; return 0; }
r[6]=read(ram,0x0c063858u,4);
goto P_0c063772;
P_0c063772: /* original e401, guest PC 0x0c063772 */
if(!s->budget--) { s->failed_pc=0x0c063772u; return 0; }
r[4]=0x00000001u;
goto P_0c063774;
P_0c063774: /* original 2fd6, guest PC 0x0c063774 */
if(!s->budget--) { s->failed_pc=0x0c063774u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063776;
P_0c063776: /* original e107, guest PC 0x0c063776 */
if(!s->budget--) { s->failed_pc=0x0c063776u; return 0; }
r[1]=0x00000007u;
goto P_0c063778;
P_0c063778: /* original 2fb6, guest PC 0x0c063778 */
if(!s->budget--) { s->failed_pc=0x0c063778u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06377a;
P_0c06377a: /* original ed04, guest PC 0x0c06377a */
if(!s->budget--) { s->failed_pc=0x0c06377au; return 0; }
r[13]=0x00000004u;
goto P_0c06377c;
P_0c06377c: /* original 2fa6, guest PC 0x0c06377c */
if(!s->budget--) { s->failed_pc=0x0c06377cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06377e;
P_0c06377e: /* original 6a53, guest PC 0x0c06377e */
if(!s->budget--) { s->failed_pc=0x0c06377eu; return 0; }
r[10]=r[5];
goto P_0c063780;
P_0c063780: /* original db34, guest PC 0x0c063780 */
if(!s->budget--) { s->failed_pc=0x0c063780u; return 0; }
r[11]=read(ram,0x0c063854u,4);
goto P_0c063782;
P_0c063782: /* original 2f96, guest PC 0x0c063782 */
if(!s->budget--) { s->failed_pc=0x0c063782u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063784;
P_0c063784: /* original d932, guest PC 0x0c063784 */
if(!s->budget--) { s->failed_pc=0x0c063784u; return 0; }
r[9]=read(ram,0x0c063850u,4);
goto P_0c063786;
P_0c063786: /* original 67b3, guest PC 0x0c063786 */
if(!s->budget--) { s->failed_pc=0x0c063786u; return 0; }
r[7]=r[11];
goto P_0c063788;
P_0c063788: /* original 7710, guest PC 0x0c063788 */
if(!s->budget--) { s->failed_pc=0x0c063788u; return 0; }
r[7]+=0x00000010u;
goto P_0c06378a;
P_0c06378a: /* original 6e53, guest PC 0x0c06378a */
if(!s->budget--) { s->failed_pc=0x0c06378au; return 0; }
r[14]=r[5];
goto P_0c06378c;
P_0c06378c: /* original d033, guest PC 0x0c06378c */
if(!s->budget--) { s->failed_pc=0x0c06378cu; return 0; }
r[0]=read(ram,0x0c06385cu,4);
goto P_0c06378e;
P_0c06378e: /* original 4e08, guest PC 0x0c06378e */
if(!s->budget--) { s->failed_pc=0x0c06378eu; return 0; }
r[14]<<=2;
goto P_0c063790;
P_0c063790: /* original 00ee, guest PC 0x0c063790 */
if(!s->budget--) { s->failed_pc=0x0c063790u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c063792;
P_0c063792: /* original 8805, guest PC 0x0c063792 */
if(!s->budget--) { s->failed_pc=0x0c063792u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c063794;
P_0c063794: /* original 8903, guest PC 0x0c063794 */
if(!s->budget--) { s->failed_pc=0x0c063794u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06379e; }
goto P_0c063796;
P_0c063796: /* original d031, guest PC 0x0c063796 */
if(!s->budget--) { s->failed_pc=0x0c063796u; return 0; }
r[0]=read(ram,0x0c06385cu,4);
goto P_0c063798;
P_0c063798: /* original 00ee, guest PC 0x0c063798 */
if(!s->budget--) { s->failed_pc=0x0c063798u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c06379a;
P_0c06379a: /* original 88fd, guest PC 0x0c06379a */
if(!s->budget--) { s->failed_pc=0x0c06379au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffdu)!=0);
goto P_0c06379c;
P_0c06379c: /* original 8b3f, guest PC 0x0c06379c */
if(!s->budget--) { s->failed_pc=0x0c06379cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06381e; }
goto P_0c06379e;
P_0c06379e: /* original 6d53, guest PC 0x0c06379e */
if(!s->budget--) { s->failed_pc=0x0c06379eu; return 0; }
r[13]=r[5];
goto P_0c0637a0;
P_0c0637a0: /* original d02e, guest PC 0x0c0637a0 */
if(!s->budget--) { s->failed_pc=0x0c0637a0u; return 0; }
r[0]=read(ram,0x0c06385cu,4);
goto P_0c0637a2;
P_0c0637a2: /* original 4d08, guest PC 0x0c0637a2 */
if(!s->budget--) { s->failed_pc=0x0c0637a2u; return 0; }
r[13]<<=2;
goto P_0c0637a4;
P_0c0637a4: /* original 0d16, guest PC 0x0c0637a4 */
if(!s->budget--) { s->failed_pc=0x0c0637a4u; return 0; }
write(ram,r[13]+r[0],r[1],4);
goto P_0c0637a6;
P_0c0637a6: /* original d32e, guest PC 0x0c0637a6 */
if(!s->budget--) { s->failed_pc=0x0c0637a6u; return 0; }
r[3]=read(ram,0x0c063860u,4);
goto P_0c0637a8;
P_0c0637a8: /* original 6032, guest PC 0x0c0637a8 */
if(!s->budget--) { s->failed_pc=0x0c0637a8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0637aa;
P_0c0637aa: /* original 2049, guest PC 0x0c0637aa */
if(!s->budget--) { s->failed_pc=0x0c0637aau; return 0; }
r[0]&=r[4];
goto P_0c0637ac;
P_0c0637ac: /* original 8801, guest PC 0x0c0637ac */
if(!s->budget--) { s->failed_pc=0x0c0637acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0637ae;
P_0c0637ae: /* original 8913, guest PC 0x0c0637ae */
if(!s->budget--) { s->failed_pc=0x0c0637aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0637d8; }
goto P_0c0637b0;
P_0c0637b0: /* original d22b, guest PC 0x0c0637b0 */
if(!s->budget--) { s->failed_pc=0x0c0637b0u; return 0; }
r[2]=read(ram,0x0c063860u,4);
goto P_0c0637b2;
P_0c0637b2: /* original 6022, guest PC 0x0c0637b2 */
if(!s->budget--) { s->failed_pc=0x0c0637b2u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0637b4;
P_0c0637b4: /* original c92c, guest PC 0x0c0637b4 */
if(!s->budget--) { s->failed_pc=0x0c0637b4u; return 0; }
r[0]&=44u;
goto P_0c0637b6;
P_0c0637b6: /* original 8820, guest PC 0x0c0637b6 */
if(!s->budget--) { s->failed_pc=0x0c0637b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0637b8;
P_0c0637b8: /* original 8b0e, guest PC 0x0c0637b8 */
if(!s->budget--) { s->failed_pc=0x0c0637b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0637d8; }
goto P_0c0637ba;
P_0c0637ba: /* original 2448, guest PC 0x0c0637ba */
if(!s->budget--) { s->failed_pc=0x0c0637bau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0637bc;
P_0c0637bc: /* original 890c, guest PC 0x0c0637bc */
if(!s->budget--) { s->failed_pc=0x0c0637bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0637d8; }
goto P_0c0637be;
P_0c0637be: /* original d329, guest PC 0x0c0637be */
if(!s->budget--) { s->failed_pc=0x0c0637beu; return 0; }
r[3]=read(ram,0x0c063864u,4);
goto P_0c0637c0;
P_0c0637c0: /* original d229, guest PC 0x0c0637c0 */
if(!s->budget--) { s->failed_pc=0x0c0637c0u; return 0; }
r[2]=read(ram,0x0c063868u,4);
goto P_0c0637c2;
P_0c0637c2: /* original 6122, guest PC 0x0c0637c2 */
if(!s->budget--) { s->failed_pc=0x0c0637c2u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0637c4;
P_0c0637c4: /* original 6032, guest PC 0x0c0637c4 */
if(!s->budget--) { s->failed_pc=0x0c0637c4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0637c6;
P_0c0637c6: /* original 301c, guest PC 0x0c0637c6 */
if(!s->budget--) { s->failed_pc=0x0c0637c6u; return 0; }
r[0]+=r[1];
goto P_0c0637c8;
P_0c0637c8: /* original 2602, guest PC 0x0c0637c8 */
if(!s->budget--) { s->failed_pc=0x0c0637c8u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c0637ca;
P_0c0637ca: /* original d128, guest PC 0x0c0637ca */
if(!s->budget--) { s->failed_pc=0x0c0637cau; return 0; }
r[1]=read(ram,0x0c06386cu,4);
goto P_0c0637cc;
P_0c0637cc: /* original d328, guest PC 0x0c0637cc */
if(!s->budget--) { s->failed_pc=0x0c0637ccu; return 0; }
r[3]=read(ram,0x0c063870u,4);
goto P_0c0637ce;
P_0c0637ce: /* original 6232, guest PC 0x0c0637ce */
if(!s->budget--) { s->failed_pc=0x0c0637ceu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0637d0;
P_0c0637d0: /* original 6012, guest PC 0x0c0637d0 */
if(!s->budget--) { s->failed_pc=0x0c0637d0u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0637d2;
P_0c0637d2: /* original 302c, guest PC 0x0c0637d2 */
if(!s->budget--) { s->failed_pc=0x0c0637d2u; return 0; }
r[0]+=r[2];
goto P_0c0637d4;
P_0c0637d4: /* original a012, guest PC 0x0c0637d4 */
if(!s->budget--) { s->failed_pc=0x0c0637d4u; return 0; }
write(ram,r[7],r[0],4);
goto P_0c0637fc;
P_0c0637d6: /* original 2702, guest PC 0x0c0637d6 */
if(!s->budget--) { s->failed_pc=0x0c0637d6u; return 0; }
write(ram,r[7],r[0],4);
goto P_0c0637d8;
P_0c0637d8: /* original d326, guest PC 0x0c0637d8 */
if(!s->budget--) { s->failed_pc=0x0c0637d8u; return 0; }
r[3]=read(ram,0x0c063874u,4);
goto P_0c0637da;
P_0c0637da: /* original 6032, guest PC 0x0c0637da */
if(!s->budget--) { s->failed_pc=0x0c0637dau; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0637dc;
P_0c0637dc: /* original 8801, guest PC 0x0c0637dc */
if(!s->budget--) { s->failed_pc=0x0c0637dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0637de;
P_0c0637de: /* original 890d, guest PC 0x0c0637de */
if(!s->budget--) { s->failed_pc=0x0c0637deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0637fc; }
goto P_0c0637e0;
P_0c0637e0: /* original d020, guest PC 0x0c0637e0 */
if(!s->budget--) { s->failed_pc=0x0c0637e0u; return 0; }
r[0]=read(ram,0x0c063864u,4);
goto P_0c0637e2;
P_0c0637e2: /* original 6e53, guest PC 0x0c0637e2 */
if(!s->budget--) { s->failed_pc=0x0c0637e2u; return 0; }
r[14]=r[5];
goto P_0c0637e4;
P_0c0637e4: /* original d120, guest PC 0x0c0637e4 */
if(!s->budget--) { s->failed_pc=0x0c0637e4u; return 0; }
r[1]=read(ram,0x0c063868u,4);
goto P_0c0637e6;
P_0c0637e6: /* original 2e49, guest PC 0x0c0637e6 */
if(!s->budget--) { s->failed_pc=0x0c0637e6u; return 0; }
r[14]&=r[4];
goto P_0c0637e8;
P_0c0637e8: /* original 4e08, guest PC 0x0c0637e8 */
if(!s->budget--) { s->failed_pc=0x0c0637e8u; return 0; }
r[14]<<=2;
goto P_0c0637ea;
P_0c0637ea: /* original 02ee, guest PC 0x0c0637ea */
if(!s->budget--) { s->failed_pc=0x0c0637eau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0637ec;
P_0c0637ec: /* original 6312, guest PC 0x0c0637ec */
if(!s->budget--) { s->failed_pc=0x0c0637ecu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0637ee;
P_0c0637ee: /* original 323c, guest PC 0x0c0637ee */
if(!s->budget--) { s->failed_pc=0x0c0637eeu; return 0; }
r[2]+=r[3];
goto P_0c0637f0;
P_0c0637f0: /* original 2622, guest PC 0x0c0637f0 */
if(!s->budget--) { s->failed_pc=0x0c0637f0u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c0637f2;
P_0c0637f2: /* original 03ee, guest PC 0x0c0637f2 */
if(!s->budget--) { s->failed_pc=0x0c0637f2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0637f4;
P_0c0637f4: /* original d21e, guest PC 0x0c0637f4 */
if(!s->budget--) { s->failed_pc=0x0c0637f4u; return 0; }
r[2]=read(ram,0x0c063870u,4);
goto P_0c0637f6;
P_0c0637f6: /* original 6222, guest PC 0x0c0637f6 */
if(!s->budget--) { s->failed_pc=0x0c0637f6u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c0637f8;
P_0c0637f8: /* original 332c, guest PC 0x0c0637f8 */
if(!s->budget--) { s->failed_pc=0x0c0637f8u; return 0; }
r[3]+=r[2];
goto P_0c0637fa;
P_0c0637fa: /* original 2732, guest PC 0x0c0637fa */
if(!s->budget--) { s->failed_pc=0x0c0637fau; return 0; }
write(ram,r[7],r[3],4);
goto P_0c0637fc;
P_0c0637fc: /* original d017, guest PC 0x0c0637fc */
if(!s->budget--) { s->failed_pc=0x0c0637fcu; return 0; }
r[0]=read(ram,0x0c06385cu,4);
goto P_0c0637fe;
P_0c0637fe: /* original 00de, guest PC 0x0c0637fe */
if(!s->budget--) { s->failed_pc=0x0c0637feu; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c063800;
P_0c063800: /* original 88fd, guest PC 0x0c063800 */
if(!s->budget--) { s->failed_pc=0x0c063800u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffdu)!=0);
goto P_0c063802;
P_0c063802: /* original 890f, guest PC 0x0c063802 */
if(!s->budget--) { s->failed_pc=0x0c063802u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063824; }
goto P_0c063804;
P_0c063804: /* original d21c, guest PC 0x0c063804 */
if(!s->budget--) { s->failed_pc=0x0c063804u; return 0; }
r[2]=read(ram,0x0c063878u,4);
goto P_0c063806;
P_0c063806: /* original 6022, guest PC 0x0c063806 */
if(!s->budget--) { s->failed_pc=0x0c063806u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c063808;
P_0c063808: /* original 8801, guest PC 0x0c063808 */
if(!s->budget--) { s->failed_pc=0x0c063808u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06380a;
P_0c06380a: /* original 8b0b, guest PC 0x0c06380a */
if(!s->budget--) { s->failed_pc=0x0c06380au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063824; }
goto P_0c06380c;
P_0c06380c: /* original d31b, guest PC 0x0c06380c */
if(!s->budget--) { s->failed_pc=0x0c06380cu; return 0; }
r[3]=read(ram,0x0c06387cu,4);
goto P_0c06380e;
P_0c06380e: /* original 6132, guest PC 0x0c06380e */
if(!s->budget--) { s->failed_pc=0x0c06380eu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c063810;
P_0c063810: /* original 2912, guest PC 0x0c063810 */
if(!s->budget--) { s->failed_pc=0x0c063810u; return 0; }
write(ram,r[9],r[1],4);
goto P_0c063812;
P_0c063812: /* original d01b, guest PC 0x0c063812 */
if(!s->budget--) { s->failed_pc=0x0c063812u; return 0; }
r[0]=read(ram,0x0c063880u,4);
goto P_0c063814;
P_0c063814: /* original 6202, guest PC 0x0c063814 */
if(!s->budget--) { s->failed_pc=0x0c063814u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c063816;
P_0c063816: /* original 2b22, guest PC 0x0c063816 */
if(!s->budget--) { s->failed_pc=0x0c063816u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c063818;
P_0c063818: /* original d117, guest PC 0x0c063818 */
if(!s->budget--) { s->failed_pc=0x0c063818u; return 0; }
r[1]=read(ram,0x0c063878u,4);
goto P_0c06381a;
P_0c06381a: /* original a003, guest PC 0x0c06381a */
if(!s->budget--) { s->failed_pc=0x0c06381au; return 0; }
write(ram,r[1],r[10],4);
goto P_0c063824;
P_0c06381c: /* original 21a2, guest PC 0x0c06381c */
if(!s->budget--) { s->failed_pc=0x0c06381cu; return 0; }
write(ram,r[1],r[10],4);
goto P_0c06381e;
P_0c06381e: /* original 7501, guest PC 0x0c06381e */
if(!s->budget--) { s->failed_pc=0x0c06381eu; return 0; }
r[5]+=0x00000001u;
goto P_0c063820;
P_0c063820: /* original 35d3, guest PC 0x0c063820 */
if(!s->budget--) { s->failed_pc=0x0c063820u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[13])!=0);
goto P_0c063822;
P_0c063822: /* original 8bb2, guest PC 0x0c063822 */
if(!s->budget--) { s->failed_pc=0x0c063822u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06378a; }
goto P_0c063824;
P_0c063824: /* original 69f6, guest PC 0x0c063824 */
if(!s->budget--) { s->failed_pc=0x0c063824u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c063826;
P_0c063826: /* original 6af6, guest PC 0x0c063826 */
if(!s->budget--) { s->failed_pc=0x0c063826u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c063828;
P_0c063828: /* original 6bf6, guest PC 0x0c063828 */
if(!s->budget--) { s->failed_pc=0x0c063828u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06382a;
P_0c06382a: /* original 6df6, guest PC 0x0c06382a */
if(!s->budget--) { s->failed_pc=0x0c06382au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06382c;
P_0c06382c: /* original 000b, guest PC 0x0c06382c */
if(!s->budget--) { s->failed_pc=0x0c06382cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06382e: /* original 6ef6, guest PC 0x0c06382e */
if(!s->budget--) { s->failed_pc=0x0c06382eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c063830u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c063830u; return 0; } return 1;
P_0c063884: /* original 2fe6, guest PC 0x0c063884 */
if(!s->budget--) { s->failed_pc=0x0c063884u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063886;
P_0c063886: /* original e400, guest PC 0x0c063886 */
if(!s->budget--) { s->failed_pc=0x0c063886u; return 0; }
r[4]=0x00000000u;
goto P_0c063888;
P_0c063888: /* original 2fd6, guest PC 0x0c063888 */
if(!s->budget--) { s->failed_pc=0x0c063888u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06388a;
P_0c06388a: /* original 2fc6, guest PC 0x0c06388a */
if(!s->budget--) { s->failed_pc=0x0c06388au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06388c;
P_0c06388c: /* original 2fb6, guest PC 0x0c06388c */
if(!s->budget--) { s->failed_pc=0x0c06388cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06388e;
P_0c06388e: /* original 2fa6, guest PC 0x0c06388e */
if(!s->budget--) { s->failed_pc=0x0c06388eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063890;
P_0c063890: /* original 2f96, guest PC 0x0c063890 */
if(!s->budget--) { s->failed_pc=0x0c063890u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063892;
P_0c063892: /* original 2f86, guest PC 0x0c063892 */
if(!s->budget--) { s->failed_pc=0x0c063892u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063894;
P_0c063894: /* original 4f22, guest PC 0x0c063894 */
if(!s->budget--) { s->failed_pc=0x0c063894u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c063896;
P_0c063896: /* original 7ffc, guest PC 0x0c063896 */
if(!s->budget--) { s->failed_pc=0x0c063896u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c063898;
P_0c063898: /* original d047, guest PC 0x0c063898 */
if(!s->budget--) { s->failed_pc=0x0c063898u; return 0; }
r[0]=read(ram,0x0c0639b8u,4);
goto P_0c06389a;
P_0c06389a: /* original 6e43, guest PC 0x0c06389a */
if(!s->budget--) { s->failed_pc=0x0c06389au; return 0; }
r[14]=r[4];
goto P_0c06389c;
P_0c06389c: /* original 4e08, guest PC 0x0c06389c */
if(!s->budget--) { s->failed_pc=0x0c06389cu; return 0; }
r[14]<<=2;
goto P_0c06389e;
P_0c06389e: /* original 00ee, guest PC 0x0c06389e */
if(!s->budget--) { s->failed_pc=0x0c06389eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0638a0;
P_0c0638a0: /* original 8801, guest PC 0x0c0638a0 */
if(!s->budget--) { s->failed_pc=0x0c0638a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0638a2;
P_0c0638a2: /* original 8d02, guest PC 0x0c0638a2 */
if(!s->budget--) { s->failed_pc=0x0c0638a2u; return 0; }
cond=r[17]&1u;
r[10]=0x00000004u;
if(cond) { goto P_0c0638aa; }
goto P_0c0638a6;
P_0c0638a4: /* original ea04, guest PC 0x0c0638a4 */
if(!s->budget--) { s->failed_pc=0x0c0638a4u; return 0; }
r[10]=0x00000004u;
goto P_0c0638a6;
P_0c0638a6: /* original a116, guest PC 0x0c0638a6 */
if(!s->budget--) { s->failed_pc=0x0c0638a6u; return 0; }
goto P_0c063ad6;
P_0c0638a8: /* original 0009, guest PC 0x0c0638a8 */
if(!s->budget--) { s->failed_pc=0x0c0638a8u; return 0; }
goto P_0c0638aa;
P_0c0638aa: /* original d344, guest PC 0x0c0638aa */
if(!s->budget--) { s->failed_pc=0x0c0638aau; return 0; }
r[3]=read(ram,0x0c0639bcu,4);
goto P_0c0638ac;
P_0c0638ac: /* original 6232, guest PC 0x0c0638ac */
if(!s->budget--) { s->failed_pc=0x0c0638acu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0638ae;
P_0c0638ae: /* original 2228, guest PC 0x0c0638ae */
if(!s->budget--) { s->failed_pc=0x0c0638aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0638b0;
P_0c0638b0: /* original 8901, guest PC 0x0c0638b0 */
if(!s->budget--) { s->failed_pc=0x0c0638b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0638b6; }
goto P_0c0638b2;
P_0c0638b2: /* original a110, guest PC 0x0c0638b2 */
if(!s->budget--) { s->failed_pc=0x0c0638b2u; return 0; }
goto P_0c063ad6;
P_0c0638b4: /* original 0009, guest PC 0x0c0638b4 */
if(!s->budget--) { s->failed_pc=0x0c0638b4u; return 0; }
goto P_0c0638b6;
P_0c0638b6: /* original e501, guest PC 0x0c0638b6 */
if(!s->budget--) { s->failed_pc=0x0c0638b6u; return 0; }
r[5]=0x00000001u;
goto P_0c0638b8;
P_0c0638b8: /* original d240, guest PC 0x0c0638b8 */
if(!s->budget--) { s->failed_pc=0x0c0638b8u; return 0; }
r[2]=read(ram,0x0c0639bcu,4);
goto P_0c0638ba;
P_0c0638ba: /* original 2252, guest PC 0x0c0638ba */
if(!s->budget--) { s->failed_pc=0x0c0638bau; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0638bc;
P_0c0638bc: /* original d03e, guest PC 0x0c0638bc */
if(!s->budget--) { s->failed_pc=0x0c0638bcu; return 0; }
r[0]=read(ram,0x0c0639b8u,4);
goto P_0c0638be;
P_0c0638be: /* original e902, guest PC 0x0c0638be */
if(!s->budget--) { s->failed_pc=0x0c0638beu; return 0; }
r[9]=0x00000002u;
goto P_0c0638c0;
P_0c0638c0: /* original 0e96, guest PC 0x0c0638c0 */
if(!s->budget--) { s->failed_pc=0x0c0638c0u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c0638c2;
P_0c0638c2: /* original d33f, guest PC 0x0c0638c2 */
if(!s->budget--) { s->failed_pc=0x0c0638c2u; return 0; }
r[3]=read(ram,0x0c0639c0u,4);
goto P_0c0638c4;
P_0c0638c4: /* original 2342, guest PC 0x0c0638c4 */
if(!s->budget--) { s->failed_pc=0x0c0638c4u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0638c6;
P_0c0638c6: /* original 6d43, guest PC 0x0c0638c6 */
if(!s->budget--) { s->failed_pc=0x0c0638c6u; return 0; }
r[13]=r[4];
goto P_0c0638c8;
P_0c0638c8: /* original d73f, guest PC 0x0c0638c8 */
if(!s->budget--) { s->failed_pc=0x0c0638c8u; return 0; }
r[7]=read(ram,0x0c0639c8u,4);
goto P_0c0638ca;
P_0c0638ca: /* original e048, guest PC 0x0c0638ca */
if(!s->budget--) { s->failed_pc=0x0c0638cau; return 0; }
r[0]=0x00000048u;
goto P_0c0638cc;
P_0c0638cc: /* original d63f, guest PC 0x0c0638cc */
if(!s->budget--) { s->failed_pc=0x0c0638ccu; return 0; }
r[6]=read(ram,0x0c0639ccu,4);
goto P_0c0638ce;
P_0c0638ce: /* original 2d59, guest PC 0x0c0638ce */
if(!s->budget--) { s->failed_pc=0x0c0638ceu; return 0; }
r[13]&=r[5];
goto P_0c0638d0;
P_0c0638d0: /* original d43c, guest PC 0x0c0638d0 */
if(!s->budget--) { s->failed_pc=0x0c0638d0u; return 0; }
r[4]=read(ram,0x0c0639c4u,4);
goto P_0c0638d2;
P_0c0638d2: /* original 6242, guest PC 0x0c0638d2 */
if(!s->budget--) { s->failed_pc=0x0c0638d2u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0638d4;
P_0c0638d4: /* original 0726, guest PC 0x0c0638d4 */
if(!s->budget--) { s->failed_pc=0x0c0638d4u; return 0; }
write(ram,r[7]+r[0],r[2],4);
goto P_0c0638d6;
P_0c0638d6: /* original 2652, guest PC 0x0c0638d6 */
if(!s->budget--) { s->failed_pc=0x0c0638d6u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0638d8;
P_0c0638d8: /* original e400, guest PC 0x0c0638d8 */
if(!s->budget--) { s->failed_pc=0x0c0638d8u; return 0; }
r[4]=0x00000000u;
goto P_0c0638da;
P_0c0638da: /* original 2642, guest PC 0x0c0638da */
if(!s->budget--) { s->failed_pc=0x0c0638dau; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0638dc;
P_0c0638dc: /* original dc3c, guest PC 0x0c0638dc */
if(!s->budget--) { s->failed_pc=0x0c0638dcu; return 0; }
r[12]=read(ram,0x0c0639d0u,4);
goto P_0c0638de;
P_0c0638de: /* original 66d3, guest PC 0x0c0638de */
if(!s->budget--) { s->failed_pc=0x0c0638deu; return 0; }
r[6]=r[13];
goto P_0c0638e0;
P_0c0638e0: /* original d03c, guest PC 0x0c0638e0 */
if(!s->budget--) { s->failed_pc=0x0c0638e0u; return 0; }
r[0]=read(ram,0x0c0639d4u,4);
goto P_0c0638e2;
P_0c0638e2: /* original 4608, guest PC 0x0c0638e2 */
if(!s->budget--) { s->failed_pc=0x0c0638e2u; return 0; }
r[6]<<=2;
goto P_0c0638e4;
P_0c0638e4: /* original 4608, guest PC 0x0c0638e4 */
if(!s->budget--) { s->failed_pc=0x0c0638e4u; return 0; }
r[6]<<=2;
goto P_0c0638e6;
P_0c0638e6: /* original 4600, guest PC 0x0c0638e6 */
if(!s->budget--) { s->failed_pc=0x0c0638e6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0638e8;
P_0c0638e8: /* original 026e, guest PC 0x0c0638e8 */
if(!s->budget--) { s->failed_pc=0x0c0638e8u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c0638ea;
P_0c0638ea: /* original 2c22, guest PC 0x0c0638ea */
if(!s->budget--) { s->failed_pc=0x0c0638eau; return 0; }
write(ram,r[12],r[2],4);
goto P_0c0638ec;
P_0c0638ec: /* original dd3a, guest PC 0x0c0638ec */
if(!s->budget--) { s->failed_pc=0x0c0638ecu; return 0; }
r[13]=read(ram,0x0c0639d8u,4);
goto P_0c0638ee;
P_0c0638ee: /* original 7004, guest PC 0x0c0638ee */
if(!s->budget--) { s->failed_pc=0x0c0638eeu; return 0; }
r[0]+=0x00000004u;
goto P_0c0638f0;
P_0c0638f0: /* original 026e, guest PC 0x0c0638f0 */
if(!s->budget--) { s->failed_pc=0x0c0638f0u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c0638f2;
P_0c0638f2: /* original 2d22, guest PC 0x0c0638f2 */
if(!s->budget--) { s->failed_pc=0x0c0638f2u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0638f4;
P_0c0638f4: /* original dd39, guest PC 0x0c0638f4 */
if(!s->budget--) { s->failed_pc=0x0c0638f4u; return 0; }
r[13]=read(ram,0x0c0639dcu,4);
goto P_0c0638f6;
P_0c0638f6: /* original 7008, guest PC 0x0c0638f6 */
if(!s->budget--) { s->failed_pc=0x0c0638f6u; return 0; }
r[0]+=0x00000008u;
goto P_0c0638f8;
P_0c0638f8: /* original 026e, guest PC 0x0c0638f8 */
if(!s->budget--) { s->failed_pc=0x0c0638f8u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c0638fa;
P_0c0638fa: /* original 2d22, guest PC 0x0c0638fa */
if(!s->budget--) { s->failed_pc=0x0c0638fau; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0638fc;
P_0c0638fc: /* original dd38, guest PC 0x0c0638fc */
if(!s->budget--) { s->failed_pc=0x0c0638fcu; return 0; }
r[13]=read(ram,0x0c0639e0u,4);
goto P_0c0638fe;
P_0c0638fe: /* original 7004, guest PC 0x0c0638fe */
if(!s->budget--) { s->failed_pc=0x0c0638feu; return 0; }
r[0]+=0x00000004u;
goto P_0c063900;
P_0c063900: /* original 026e, guest PC 0x0c063900 */
if(!s->budget--) { s->failed_pc=0x0c063900u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c063902;
P_0c063902: /* original 2d22, guest PC 0x0c063902 */
if(!s->budget--) { s->failed_pc=0x0c063902u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c063904;
P_0c063904: /* original 7d34, guest PC 0x0c063904 */
if(!s->budget--) { s->failed_pc=0x0c063904u; return 0; }
r[13]+=0x00000034u;
goto P_0c063906;
P_0c063906: /* original 70f8, guest PC 0x0c063906 */
if(!s->budget--) { s->failed_pc=0x0c063906u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c063908;
P_0c063908: /* original 026e, guest PC 0x0c063908 */
if(!s->budget--) { s->failed_pc=0x0c063908u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c06390a;
P_0c06390a: /* original 2d22, guest PC 0x0c06390a */
if(!s->budget--) { s->failed_pc=0x0c06390au; return 0; }
write(ram,r[13],r[2],4);
goto P_0c06390c;
P_0c06390c: /* original dd35, guest PC 0x0c06390c */
if(!s->budget--) { s->failed_pc=0x0c06390cu; return 0; }
r[13]=read(ram,0x0c0639e4u,4);
goto P_0c06390e;
P_0c06390e: /* original d636, guest PC 0x0c06390e */
if(!s->budget--) { s->failed_pc=0x0c06390eu; return 0; }
r[6]=read(ram,0x0c0639e8u,4);
goto P_0c063910;
P_0c063910: /* original 26d2, guest PC 0x0c063910 */
if(!s->budget--) { s->failed_pc=0x0c063910u; return 0; }
write(ram,r[6],r[13],4);
goto P_0c063912;
P_0c063912: /* original 6262, guest PC 0x0c063912 */
if(!s->budget--) { s->failed_pc=0x0c063912u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c063914;
P_0c063914: /* original d135, guest PC 0x0c063914 */
if(!s->budget--) { s->failed_pc=0x0c063914u; return 0; }
r[1]=read(ram,0x0c0639ecu,4);
goto P_0c063916;
P_0c063916: /* original 2142, guest PC 0x0c063916 */
if(!s->budget--) { s->failed_pc=0x0c063916u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c063918;
P_0c063918: /* original 7308, guest PC 0x0c063918 */
if(!s->budget--) { s->failed_pc=0x0c063918u; return 0; }
r[3]+=0x00000008u;
goto P_0c06391a;
P_0c06391a: /* original 2342, guest PC 0x0c06391a */
if(!s->budget--) { s->failed_pc=0x0c06391au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06391c;
P_0c06391c: /* original 1741, guest PC 0x0c06391c */
if(!s->budget--) { s->failed_pc=0x0c06391cu; return 0; }
write(ram,r[7]+4,r[4],4);
goto P_0c06391e;
P_0c06391e: /* original db34, guest PC 0x0c06391e */
if(!s->budget--) { s->failed_pc=0x0c06391eu; return 0; }
r[11]=read(ram,0x0c0639f0u,4);
goto P_0c063920;
P_0c063920: /* original dc34, guest PC 0x0c063920 */
if(!s->budget--) { s->failed_pc=0x0c063920u; return 0; }
r[12]=read(ram,0x0c0639f4u,4);
goto P_0c063922;
P_0c063922: /* original 9d48, guest PC 0x0c063922 */
if(!s->budget--) { s->failed_pc=0x0c063922u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0639b6u,2);
goto P_0c063924;
P_0c063924: /* original d034, guest PC 0x0c063924 */
if(!s->budget--) { s->failed_pc=0x0c063924u; return 0; }
r[0]=read(ram,0x0c0639f8u,4);
goto P_0c063926;
P_0c063926: /* original 02ee, guest PC 0x0c063926 */
if(!s->budget--) { s->failed_pc=0x0c063926u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c063928;
P_0c063928: /* original 2228, guest PC 0x0c063928 */
if(!s->budget--) { s->failed_pc=0x0c063928u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06392a;
P_0c06392a: /* original 8912, guest PC 0x0c06392a */
if(!s->budget--) { s->failed_pc=0x0c06392au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063952; }
goto P_0c06392c;
P_0c06392c: /* original d22f, guest PC 0x0c06392c */
if(!s->budget--) { s->failed_pc=0x0c06392cu; return 0; }
r[2]=read(ram,0x0c0639ecu,4);
goto P_0c06392e;
P_0c06392e: /* original 6122, guest PC 0x0c06392e */
if(!s->budget--) { s->failed_pc=0x0c06392eu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c063930;
P_0c063930: /* original 215b, guest PC 0x0c063930 */
if(!s->budget--) { s->failed_pc=0x0c063930u; return 0; }
r[1]|=r[5];
goto P_0c063932;
P_0c063932: /* original 2212, guest PC 0x0c063932 */
if(!s->budget--) { s->failed_pc=0x0c063932u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c063934;
P_0c063934: /* original 62f3, guest PC 0x0c063934 */
if(!s->budget--) { s->failed_pc=0x0c063934u; return 0; }
r[2]=r[15];
goto P_0c063936;
P_0c063936: /* original e710, guest PC 0x0c063936 */
if(!s->budget--) { s->failed_pc=0x0c063936u; return 0; }
r[7]=0x00000010u;
goto P_0c063938;
P_0c063938: /* original 2f26, guest PC 0x0c063938 */
if(!s->budget--) { s->failed_pc=0x0c063938u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06393a;
P_0c06393a: /* original 06ee, guest PC 0x0c06393a */
if(!s->budget--) { s->failed_pc=0x0c06393au; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c06393c;
P_0c06393c: /* original d02f, guest PC 0x0c06393c */
if(!s->budget--) { s->failed_pc=0x0c06393cu; return 0; }
r[0]=read(ram,0x0c0639fcu,4);
goto P_0c06393e;
P_0c06393e: /* original 7620, guest PC 0x0c06393e */
if(!s->budget--) { s->failed_pc=0x0c06393eu; return 0; }
r[6]+=0x00000020u;
goto P_0c063940;
P_0c063940: /* original 05ee, guest PC 0x0c063940 */
if(!s->budget--) { s->failed_pc=0x0c063940u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c063942;
P_0c063942: /* original 4b0b, guest PC 0x0c063942 */
if(!s->budget--) { s->failed_pc=0x0c063942u; return 0; }
target=r[11];
r[16]=code_base|0x0c063946u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063946u) { target=s->pc; goto dispatch; }
goto P_0c063946;
P_0c063944: /* original 64c3, guest PC 0x0c063944 */
if(!s->budget--) { s->failed_pc=0x0c063944u; return 0; }
r[4]=r[12];
goto P_0c063946;
P_0c063946: /* original 6403, guest PC 0x0c063946 */
if(!s->budget--) { s->failed_pc=0x0c063946u; return 0; }
r[4]=r[0];
goto P_0c063948;
P_0c063948: /* original 34d0, guest PC 0x0c063948 */
if(!s->budget--) { s->failed_pc=0x0c063948u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c06394a;
P_0c06394a: /* original 8f02, guest PC 0x0c06394a */
if(!s->budget--) { s->failed_pc=0x0c06394au; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c063952; }
goto P_0c06394e;
P_0c06394c: /* original 7f04, guest PC 0x0c06394c */
if(!s->budget--) { s->failed_pc=0x0c06394cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06394e;
P_0c06394e: /* original a0c0, guest PC 0x0c06394e */
if(!s->budget--) { s->failed_pc=0x0c06394eu; return 0; }
goto P_0c063ad2;
P_0c063950: /* original 0009, guest PC 0x0c063950 */
if(!s->budget--) { s->failed_pc=0x0c063950u; return 0; }
goto P_0c063952;
P_0c063952: /* original d82b, guest PC 0x0c063952 */
if(!s->budget--) { s->failed_pc=0x0c063952u; return 0; }
r[8]=read(ram,0x0c063a00u,4);
goto P_0c063954;
P_0c063954: /* original d02b, guest PC 0x0c063954 */
if(!s->budget--) { s->failed_pc=0x0c063954u; return 0; }
r[0]=read(ram,0x0c063a04u,4);
goto P_0c063956;
P_0c063956: /* original 02ee, guest PC 0x0c063956 */
if(!s->budget--) { s->failed_pc=0x0c063956u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c063958;
P_0c063958: /* original 2228, guest PC 0x0c063958 */
if(!s->budget--) { s->failed_pc=0x0c063958u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06395a;
P_0c06395a: /* original 895f, guest PC 0x0c06395a */
if(!s->budget--) { s->failed_pc=0x0c06395au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063a1c; }
goto P_0c06395c;
P_0c06395c: /* original d323, guest PC 0x0c06395c */
if(!s->budget--) { s->failed_pc=0x0c06395cu; return 0; }
r[3]=read(ram,0x0c0639ecu,4);
goto P_0c06395e;
P_0c06395e: /* original 6132, guest PC 0x0c06395e */
if(!s->budget--) { s->failed_pc=0x0c06395eu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c063960;
P_0c063960: /* original 219b, guest PC 0x0c063960 */
if(!s->budget--) { s->failed_pc=0x0c063960u; return 0; }
r[1]|=r[9];
goto P_0c063962;
P_0c063962: /* original 2312, guest PC 0x0c063962 */
if(!s->budget--) { s->failed_pc=0x0c063962u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c063964;
P_0c063964: /* original d328, guest PC 0x0c063964 */
if(!s->budget--) { s->failed_pc=0x0c063964u; return 0; }
r[3]=read(ram,0x0c063a08u,4);
goto P_0c063966;
P_0c063966: /* original 6032, guest PC 0x0c063966 */
if(!s->budget--) { s->failed_pc=0x0c063966u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063968;
P_0c063968: /* original 8801, guest PC 0x0c063968 */
if(!s->budget--) { s->failed_pc=0x0c063968u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06396a;
P_0c06396a: /* original 8b16, guest PC 0x0c06396a */
if(!s->budget--) { s->failed_pc=0x0c06396au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06399a; }
goto P_0c06396c;
P_0c06396c: /* original d427, guest PC 0x0c06396c */
if(!s->budget--) { s->failed_pc=0x0c06396cu; return 0; }
r[4]=read(ram,0x0c063a0cu,4);
goto P_0c06396e;
P_0c06396e: /* original d228, guest PC 0x0c06396e */
if(!s->budget--) { s->failed_pc=0x0c06396eu; return 0; }
r[2]=read(ram,0x0c063a10u,4);
goto P_0c063970;
P_0c063970: /* original 6122, guest PC 0x0c063970 */
if(!s->budget--) { s->failed_pc=0x0c063970u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c063972;
P_0c063972: /* original 6323, guest PC 0x0c063972 */
if(!s->budget--) { s->failed_pc=0x0c063972u; return 0; }
r[3]=r[2];
goto P_0c063974;
P_0c063974: /* original 6032, guest PC 0x0c063974 */
if(!s->budget--) { s->failed_pc=0x0c063974u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063976;
P_0c063976: /* original 6002, guest PC 0x0c063976 */
if(!s->budget--) { s->failed_pc=0x0c063976u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c063978;
P_0c063978: /* original 2089, guest PC 0x0c063978 */
if(!s->budget--) { s->failed_pc=0x0c063978u; return 0; }
r[0]&=r[8];
goto P_0c06397a;
P_0c06397a: /* original 204b, guest PC 0x0c06397a */
if(!s->budget--) { s->failed_pc=0x0c06397au; return 0; }
r[0]|=r[4];
goto P_0c06397c;
P_0c06397c: /* original 2102, guest PC 0x0c06397c */
if(!s->budget--) { s->failed_pc=0x0c06397cu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c06397e;
P_0c06397e: /* original e710, guest PC 0x0c06397e */
if(!s->budget--) { s->failed_pc=0x0c06397eu; return 0; }
r[7]=0x00000010u;
goto P_0c063980;
P_0c063980: /* original d024, guest PC 0x0c063980 */
if(!s->budget--) { s->failed_pc=0x0c063980u; return 0; }
r[0]=read(ram,0x0c063a14u,4);
goto P_0c063982;
P_0c063982: /* original 61f3, guest PC 0x0c063982 */
if(!s->budget--) { s->failed_pc=0x0c063982u; return 0; }
r[1]=r[15];
goto P_0c063984;
P_0c063984: /* original 2f16, guest PC 0x0c063984 */
if(!s->budget--) { s->failed_pc=0x0c063984u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063986;
P_0c063986: /* original 6602, guest PC 0x0c063986 */
if(!s->budget--) { s->failed_pc=0x0c063986u; return 0; }
tmp=read(ram,r[0],4);
r[6]=tmp;
goto P_0c063988;
P_0c063988: /* original 6532, guest PC 0x0c063988 */
if(!s->budget--) { s->failed_pc=0x0c063988u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06398a;
P_0c06398a: /* original 4b0b, guest PC 0x0c06398a */
if(!s->budget--) { s->failed_pc=0x0c06398au; return 0; }
target=r[11];
r[16]=code_base|0x0c06398eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06398eu) { target=s->pc; goto dispatch; }
goto P_0c06398e;
P_0c06398c: /* original 64c3, guest PC 0x0c06398c */
if(!s->budget--) { s->failed_pc=0x0c06398cu; return 0; }
r[4]=r[12];
goto P_0c06398e;
P_0c06398e: /* original 6403, guest PC 0x0c06398e */
if(!s->budget--) { s->failed_pc=0x0c06398eu; return 0; }
r[4]=r[0];
goto P_0c063990;
P_0c063990: /* original 34d0, guest PC 0x0c063990 */
if(!s->budget--) { s->failed_pc=0x0c063990u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c063992;
P_0c063992: /* original 8f02, guest PC 0x0c063992 */
if(!s->budget--) { s->failed_pc=0x0c063992u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c06399a; }
goto P_0c063996;
P_0c063994: /* original 7f04, guest PC 0x0c063994 */
if(!s->budget--) { s->failed_pc=0x0c063994u; return 0; }
r[15]+=0x00000004u;
goto P_0c063996;
P_0c063996: /* original a09c, guest PC 0x0c063996 */
if(!s->budget--) { s->failed_pc=0x0c063996u; return 0; }
goto P_0c063ad2;
P_0c063998: /* original 0009, guest PC 0x0c063998 */
if(!s->budget--) { s->failed_pc=0x0c063998u; return 0; }
goto P_0c06399a;
P_0c06399a: /* original 62f3, guest PC 0x0c06399a */
if(!s->budget--) { s->failed_pc=0x0c06399au; return 0; }
r[2]=r[15];
goto P_0c06399c;
P_0c06399c: /* original d019, guest PC 0x0c06399c */
if(!s->budget--) { s->failed_pc=0x0c06399cu; return 0; }
r[0]=read(ram,0x0c063a04u,4);
goto P_0c06399e;
P_0c06399e: /* original e710, guest PC 0x0c06399e */
if(!s->budget--) { s->failed_pc=0x0c06399eu; return 0; }
r[7]=0x00000010u;
goto P_0c0639a0;
P_0c0639a0: /* original 2f26, guest PC 0x0c0639a0 */
if(!s->budget--) { s->failed_pc=0x0c0639a0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0639a2;
P_0c0639a2: /* original 06ee, guest PC 0x0c0639a2 */
if(!s->budget--) { s->failed_pc=0x0c0639a2u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0639a4;
P_0c0639a4: /* original 7620, guest PC 0x0c0639a4 */
if(!s->budget--) { s->failed_pc=0x0c0639a4u; return 0; }
r[6]+=0x00000020u;
goto P_0c0639a6;
P_0c0639a6: /* original 70b0, guest PC 0x0c0639a6 */
if(!s->budget--) { s->failed_pc=0x0c0639a6u; return 0; }
r[0]+=0xffffffb0u;
goto P_0c0639a8;
P_0c0639a8: /* original 05ee, guest PC 0x0c0639a8 */
if(!s->budget--) { s->failed_pc=0x0c0639a8u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0639aa;
P_0c0639aa: /* original 4b0b, guest PC 0x0c0639aa */
if(!s->budget--) { s->failed_pc=0x0c0639aau; return 0; }
target=r[11];
r[16]=code_base|0x0c0639aeu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0639aeu) { target=s->pc; goto dispatch; }
goto P_0c0639ae;
P_0c0639ac: /* original 64c3, guest PC 0x0c0639ac */
if(!s->budget--) { s->failed_pc=0x0c0639acu; return 0; }
r[4]=r[12];
goto P_0c0639ae;
P_0c0639ae: /* original 6403, guest PC 0x0c0639ae */
if(!s->budget--) { s->failed_pc=0x0c0639aeu; return 0; }
r[4]=r[0];
goto P_0c0639b0;
P_0c0639b0: /* original 34d0, guest PC 0x0c0639b0 */
if(!s->budget--) { s->failed_pc=0x0c0639b0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c0639b2;
P_0c0639b2: /* original a031, guest PC 0x0c0639b2 */
if(!s->budget--) { s->failed_pc=0x0c0639b2u; return 0; }
r[15]+=0x00000004u;
goto P_0c063a18;
P_0c0639b4: /* original 7f04, guest PC 0x0c0639b4 */
if(!s->budget--) { s->failed_pc=0x0c0639b4u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0639b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0639b6u; return 0; } return 1;
P_0c063a18: /* original 8d5b, guest PC 0x0c063a18 */
if(!s->budget--) { s->failed_pc=0x0c063a18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063ad2; }
goto P_0c063a1c;
P_0c063a1a: /* original 0009, guest PC 0x0c063a1a */
if(!s->budget--) { s->failed_pc=0x0c063a1au; return 0; }
goto P_0c063a1c;
P_0c063a1c: /* original d08d, guest PC 0x0c063a1c */
if(!s->budget--) { s->failed_pc=0x0c063a1cu; return 0; }
r[0]=read(ram,0x0c063c54u,4);
goto P_0c063a1e;
P_0c063a1e: /* original 02ee, guest PC 0x0c063a1e */
if(!s->budget--) { s->failed_pc=0x0c063a1eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c063a20;
P_0c063a20: /* original 2228, guest PC 0x0c063a20 */
if(!s->budget--) { s->failed_pc=0x0c063a20u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c063a22;
P_0c063a22: /* original 8910, guest PC 0x0c063a22 */
if(!s->budget--) { s->failed_pc=0x0c063a22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063a46; }
goto P_0c063a24;
P_0c063a24: /* original d38c, guest PC 0x0c063a24 */
if(!s->budget--) { s->failed_pc=0x0c063a24u; return 0; }
r[3]=read(ram,0x0c063c58u,4);
goto P_0c063a26;
P_0c063a26: /* original 6132, guest PC 0x0c063a26 */
if(!s->budget--) { s->failed_pc=0x0c063a26u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c063a28;
P_0c063a28: /* original 21ab, guest PC 0x0c063a28 */
if(!s->budget--) { s->failed_pc=0x0c063a28u; return 0; }
r[1]|=r[10];
goto P_0c063a2a;
P_0c063a2a: /* original 2312, guest PC 0x0c063a2a */
if(!s->budget--) { s->failed_pc=0x0c063a2au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c063a2c;
P_0c063a2c: /* original 63f3, guest PC 0x0c063a2c */
if(!s->budget--) { s->failed_pc=0x0c063a2cu; return 0; }
r[3]=r[15];
goto P_0c063a2e;
P_0c063a2e: /* original e710, guest PC 0x0c063a2e */
if(!s->budget--) { s->failed_pc=0x0c063a2eu; return 0; }
r[7]=0x00000010u;
goto P_0c063a30;
P_0c063a30: /* original 2f36, guest PC 0x0c063a30 */
if(!s->budget--) { s->failed_pc=0x0c063a30u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063a32;
P_0c063a32: /* original 06ee, guest PC 0x0c063a32 */
if(!s->budget--) { s->failed_pc=0x0c063a32u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c063a34;
P_0c063a34: /* original d089, guest PC 0x0c063a34 */
if(!s->budget--) { s->failed_pc=0x0c063a34u; return 0; }
r[0]=read(ram,0x0c063c5cu,4);
goto P_0c063a36;
P_0c063a36: /* original 7620, guest PC 0x0c063a36 */
if(!s->budget--) { s->failed_pc=0x0c063a36u; return 0; }
r[6]+=0x00000020u;
goto P_0c063a38;
P_0c063a38: /* original 05ee, guest PC 0x0c063a38 */
if(!s->budget--) { s->failed_pc=0x0c063a38u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c063a3a;
P_0c063a3a: /* original 4b0b, guest PC 0x0c063a3a */
if(!s->budget--) { s->failed_pc=0x0c063a3au; return 0; }
target=r[11];
r[16]=code_base|0x0c063a3eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063a3eu) { target=s->pc; goto dispatch; }
goto P_0c063a3e;
P_0c063a3c: /* original 64c3, guest PC 0x0c063a3c */
if(!s->budget--) { s->failed_pc=0x0c063a3cu; return 0; }
r[4]=r[12];
goto P_0c063a3e;
P_0c063a3e: /* original 6403, guest PC 0x0c063a3e */
if(!s->budget--) { s->failed_pc=0x0c063a3eu; return 0; }
r[4]=r[0];
goto P_0c063a40;
P_0c063a40: /* original 34d0, guest PC 0x0c063a40 */
if(!s->budget--) { s->failed_pc=0x0c063a40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c063a42;
P_0c063a42: /* original 8d46, guest PC 0x0c063a42 */
if(!s->budget--) { s->failed_pc=0x0c063a42u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c063ad2; }
goto P_0c063a46;
P_0c063a44: /* original 7f04, guest PC 0x0c063a44 */
if(!s->budget--) { s->failed_pc=0x0c063a44u; return 0; }
r[15]+=0x00000004u;
goto P_0c063a46;
P_0c063a46: /* original d086, guest PC 0x0c063a46 */
if(!s->budget--) { s->failed_pc=0x0c063a46u; return 0; }
r[0]=read(ram,0x0c063c60u,4);
goto P_0c063a48;
P_0c063a48: /* original 03ee, guest PC 0x0c063a48 */
if(!s->budget--) { s->failed_pc=0x0c063a48u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c063a4a;
P_0c063a4a: /* original 2338, guest PC 0x0c063a4a */
if(!s->budget--) { s->failed_pc=0x0c063a4au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c063a4c;
P_0c063a4c: /* original 892b, guest PC 0x0c063a4c */
if(!s->budget--) { s->failed_pc=0x0c063a4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063aa6; }
goto P_0c063a4e;
P_0c063a4e: /* original e408, guest PC 0x0c063a4e */
if(!s->budget--) { s->failed_pc=0x0c063a4eu; return 0; }
r[4]=0x00000008u;
goto P_0c063a50;
P_0c063a50: /* original d381, guest PC 0x0c063a50 */
if(!s->budget--) { s->failed_pc=0x0c063a50u; return 0; }
r[3]=read(ram,0x0c063c58u,4);
goto P_0c063a52;
P_0c063a52: /* original 6232, guest PC 0x0c063a52 */
if(!s->budget--) { s->failed_pc=0x0c063a52u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c063a54;
P_0c063a54: /* original 224b, guest PC 0x0c063a54 */
if(!s->budget--) { s->failed_pc=0x0c063a54u; return 0; }
r[2]|=r[4];
goto P_0c063a56;
P_0c063a56: /* original 2322, guest PC 0x0c063a56 */
if(!s->budget--) { s->failed_pc=0x0c063a56u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c063a58;
P_0c063a58: /* original d382, guest PC 0x0c063a58 */
if(!s->budget--) { s->failed_pc=0x0c063a58u; return 0; }
r[3]=read(ram,0x0c063c64u,4);
goto P_0c063a5a;
P_0c063a5a: /* original 6032, guest PC 0x0c063a5a */
if(!s->budget--) { s->failed_pc=0x0c063a5au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063a5c;
P_0c063a5c: /* original 8801, guest PC 0x0c063a5c */
if(!s->budget--) { s->failed_pc=0x0c063a5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c063a5e;
P_0c063a5e: /* original 8b14, guest PC 0x0c063a5e */
if(!s->budget--) { s->failed_pc=0x0c063a5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063a8a; }
goto P_0c063a60;
P_0c063a60: /* original d481, guest PC 0x0c063a60 */
if(!s->budget--) { s->failed_pc=0x0c063a60u; return 0; }
r[4]=read(ram,0x0c063c68u,4);
goto P_0c063a62;
P_0c063a62: /* original d282, guest PC 0x0c063a62 */
if(!s->budget--) { s->failed_pc=0x0c063a62u; return 0; }
r[2]=read(ram,0x0c063c6cu,4);
goto P_0c063a64;
P_0c063a64: /* original 6122, guest PC 0x0c063a64 */
if(!s->budget--) { s->failed_pc=0x0c063a64u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c063a66;
P_0c063a66: /* original 6323, guest PC 0x0c063a66 */
if(!s->budget--) { s->failed_pc=0x0c063a66u; return 0; }
r[3]=r[2];
goto P_0c063a68;
P_0c063a68: /* original 6032, guest PC 0x0c063a68 */
if(!s->budget--) { s->failed_pc=0x0c063a68u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063a6a;
P_0c063a6a: /* original 6002, guest PC 0x0c063a6a */
if(!s->budget--) { s->failed_pc=0x0c063a6au; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c063a6c;
P_0c063a6c: /* original 2809, guest PC 0x0c063a6c */
if(!s->budget--) { s->failed_pc=0x0c063a6cu; return 0; }
r[8]&=r[0];
goto P_0c063a6e;
P_0c063a6e: /* original 284b, guest PC 0x0c063a6e */
if(!s->budget--) { s->failed_pc=0x0c063a6eu; return 0; }
r[8]|=r[4];
goto P_0c063a70;
P_0c063a70: /* original d07f, guest PC 0x0c063a70 */
if(!s->budget--) { s->failed_pc=0x0c063a70u; return 0; }
r[0]=read(ram,0x0c063c70u,4);
goto P_0c063a72;
P_0c063a72: /* original e710, guest PC 0x0c063a72 */
if(!s->budget--) { s->failed_pc=0x0c063a72u; return 0; }
r[7]=0x00000010u;
goto P_0c063a74;
P_0c063a74: /* original 2182, guest PC 0x0c063a74 */
if(!s->budget--) { s->failed_pc=0x0c063a74u; return 0; }
write(ram,r[1],r[8],4);
goto P_0c063a76;
P_0c063a76: /* original 61f3, guest PC 0x0c063a76 */
if(!s->budget--) { s->failed_pc=0x0c063a76u; return 0; }
r[1]=r[15];
goto P_0c063a78;
P_0c063a78: /* original 2f16, guest PC 0x0c063a78 */
if(!s->budget--) { s->failed_pc=0x0c063a78u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063a7a;
P_0c063a7a: /* original 6602, guest PC 0x0c063a7a */
if(!s->budget--) { s->failed_pc=0x0c063a7au; return 0; }
tmp=read(ram,r[0],4);
r[6]=tmp;
goto P_0c063a7c;
P_0c063a7c: /* original 6532, guest PC 0x0c063a7c */
if(!s->budget--) { s->failed_pc=0x0c063a7cu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c063a7e;
P_0c063a7e: /* original 4b0b, guest PC 0x0c063a7e */
if(!s->budget--) { s->failed_pc=0x0c063a7eu; return 0; }
target=r[11];
r[16]=code_base|0x0c063a82u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063a82u) { target=s->pc; goto dispatch; }
goto P_0c063a82;
P_0c063a80: /* original 64c3, guest PC 0x0c063a80 */
if(!s->budget--) { s->failed_pc=0x0c063a80u; return 0; }
r[4]=r[12];
goto P_0c063a82;
P_0c063a82: /* original 6403, guest PC 0x0c063a82 */
if(!s->budget--) { s->failed_pc=0x0c063a82u; return 0; }
r[4]=r[0];
goto P_0c063a84;
P_0c063a84: /* original 34d0, guest PC 0x0c063a84 */
if(!s->budget--) { s->failed_pc=0x0c063a84u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c063a86;
P_0c063a86: /* original 8d24, guest PC 0x0c063a86 */
if(!s->budget--) { s->failed_pc=0x0c063a86u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c063ad2; }
goto P_0c063a8a;
P_0c063a88: /* original 7f04, guest PC 0x0c063a88 */
if(!s->budget--) { s->failed_pc=0x0c063a88u; return 0; }
r[15]+=0x00000004u;
goto P_0c063a8a;
P_0c063a8a: /* original 63f3, guest PC 0x0c063a8a */
if(!s->budget--) { s->failed_pc=0x0c063a8au; return 0; }
r[3]=r[15];
goto P_0c063a8c;
P_0c063a8c: /* original d074, guest PC 0x0c063a8c */
if(!s->budget--) { s->failed_pc=0x0c063a8cu; return 0; }
r[0]=read(ram,0x0c063c60u,4);
goto P_0c063a8e;
P_0c063a8e: /* original e710, guest PC 0x0c063a8e */
if(!s->budget--) { s->failed_pc=0x0c063a8eu; return 0; }
r[7]=0x00000010u;
goto P_0c063a90;
P_0c063a90: /* original 2f36, guest PC 0x0c063a90 */
if(!s->budget--) { s->failed_pc=0x0c063a90u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063a92;
P_0c063a92: /* original 06ee, guest PC 0x0c063a92 */
if(!s->budget--) { s->failed_pc=0x0c063a92u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c063a94;
P_0c063a94: /* original 7620, guest PC 0x0c063a94 */
if(!s->budget--) { s->failed_pc=0x0c063a94u; return 0; }
r[6]+=0x00000020u;
goto P_0c063a96;
P_0c063a96: /* original 70b0, guest PC 0x0c063a96 */
if(!s->budget--) { s->failed_pc=0x0c063a96u; return 0; }
r[0]+=0xffffffb0u;
goto P_0c063a98;
P_0c063a98: /* original 05ee, guest PC 0x0c063a98 */
if(!s->budget--) { s->failed_pc=0x0c063a98u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c063a9a;
P_0c063a9a: /* original 4b0b, guest PC 0x0c063a9a */
if(!s->budget--) { s->failed_pc=0x0c063a9au; return 0; }
target=r[11];
r[16]=code_base|0x0c063a9eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063a9eu) { target=s->pc; goto dispatch; }
goto P_0c063a9e;
P_0c063a9c: /* original 64c3, guest PC 0x0c063a9c */
if(!s->budget--) { s->failed_pc=0x0c063a9cu; return 0; }
r[4]=r[12];
goto P_0c063a9e;
P_0c063a9e: /* original 6403, guest PC 0x0c063a9e */
if(!s->budget--) { s->failed_pc=0x0c063a9eu; return 0; }
r[4]=r[0];
goto P_0c063aa0;
P_0c063aa0: /* original 34d0, guest PC 0x0c063aa0 */
if(!s->budget--) { s->failed_pc=0x0c063aa0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c063aa2;
P_0c063aa2: /* original 8d16, guest PC 0x0c063aa2 */
if(!s->budget--) { s->failed_pc=0x0c063aa2u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c063ad2; }
goto P_0c063aa6;
P_0c063aa4: /* original 7f04, guest PC 0x0c063aa4 */
if(!s->budget--) { s->failed_pc=0x0c063aa4u; return 0; }
r[15]+=0x00000004u;
goto P_0c063aa6;
P_0c063aa6: /* original d073, guest PC 0x0c063aa6 */
if(!s->budget--) { s->failed_pc=0x0c063aa6u; return 0; }
r[0]=read(ram,0x0c063c74u,4);
goto P_0c063aa8;
P_0c063aa8: /* original 03ee, guest PC 0x0c063aa8 */
if(!s->budget--) { s->failed_pc=0x0c063aa8u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c063aaa;
P_0c063aaa: /* original 2338, guest PC 0x0c063aaa */
if(!s->budget--) { s->failed_pc=0x0c063aaau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c063aac;
P_0c063aac: /* original 8918, guest PC 0x0c063aac */
if(!s->budget--) { s->failed_pc=0x0c063aacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063ae0; }
goto P_0c063aae;
P_0c063aae: /* original ea10, guest PC 0x0c063aae */
if(!s->budget--) { s->failed_pc=0x0c063aaeu; return 0; }
r[10]=0x00000010u;
goto P_0c063ab0;
P_0c063ab0: /* original d369, guest PC 0x0c063ab0 */
if(!s->budget--) { s->failed_pc=0x0c063ab0u; return 0; }
r[3]=read(ram,0x0c063c58u,4);
goto P_0c063ab2;
P_0c063ab2: /* original 6232, guest PC 0x0c063ab2 */
if(!s->budget--) { s->failed_pc=0x0c063ab2u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c063ab4;
P_0c063ab4: /* original 22ab, guest PC 0x0c063ab4 */
if(!s->budget--) { s->failed_pc=0x0c063ab4u; return 0; }
r[2]|=r[10];
goto P_0c063ab6;
P_0c063ab6: /* original 2322, guest PC 0x0c063ab6 */
if(!s->budget--) { s->failed_pc=0x0c063ab6u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c063ab8;
P_0c063ab8: /* original 63f3, guest PC 0x0c063ab8 */
if(!s->budget--) { s->failed_pc=0x0c063ab8u; return 0; }
r[3]=r[15];
goto P_0c063aba;
P_0c063aba: /* original 67a3, guest PC 0x0c063aba */
if(!s->budget--) { s->failed_pc=0x0c063abau; return 0; }
r[7]=r[10];
goto P_0c063abc;
P_0c063abc: /* original 2f36, guest PC 0x0c063abc */
if(!s->budget--) { s->failed_pc=0x0c063abcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063abe;
P_0c063abe: /* original 06ee, guest PC 0x0c063abe */
if(!s->budget--) { s->failed_pc=0x0c063abeu; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c063ac0;
P_0c063ac0: /* original d06d, guest PC 0x0c063ac0 */
if(!s->budget--) { s->failed_pc=0x0c063ac0u; return 0; }
r[0]=read(ram,0x0c063c78u,4);
goto P_0c063ac2;
P_0c063ac2: /* original 7620, guest PC 0x0c063ac2 */
if(!s->budget--) { s->failed_pc=0x0c063ac2u; return 0; }
r[6]+=0x00000020u;
goto P_0c063ac4;
P_0c063ac4: /* original 05ee, guest PC 0x0c063ac4 */
if(!s->budget--) { s->failed_pc=0x0c063ac4u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c063ac6;
P_0c063ac6: /* original 4b0b, guest PC 0x0c063ac6 */
if(!s->budget--) { s->failed_pc=0x0c063ac6u; return 0; }
target=r[11];
r[16]=code_base|0x0c063acau;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063acau) { target=s->pc; goto dispatch; }
goto P_0c063aca;
P_0c063ac8: /* original 64c3, guest PC 0x0c063ac8 */
if(!s->budget--) { s->failed_pc=0x0c063ac8u; return 0; }
r[4]=r[12];
goto P_0c063aca;
P_0c063aca: /* original 6403, guest PC 0x0c063aca */
if(!s->budget--) { s->failed_pc=0x0c063acau; return 0; }
r[4]=r[0];
goto P_0c063acc;
P_0c063acc: /* original 34d0, guest PC 0x0c063acc */
if(!s->budget--) { s->failed_pc=0x0c063accu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c063ace;
P_0c063ace: /* original 8f07, guest PC 0x0c063ace */
if(!s->budget--) { s->failed_pc=0x0c063aceu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c063ae0; }
goto P_0c063ad2;
P_0c063ad0: /* original 7f04, guest PC 0x0c063ad0 */
if(!s->budget--) { s->failed_pc=0x0c063ad0u; return 0; }
r[15]+=0x00000004u;
goto P_0c063ad2;
P_0c063ad2: /* original a006, guest PC 0x0c063ad2 */
if(!s->budget--) { s->failed_pc=0x0c063ad2u; return 0; }
r[0]=0x00000000u;
goto P_0c063ae2;
P_0c063ad4: /* original e000, guest PC 0x0c063ad4 */
if(!s->budget--) { s->failed_pc=0x0c063ad4u; return 0; }
r[0]=0x00000000u;
goto P_0c063ad6;
P_0c063ad6: /* original 7401, guest PC 0x0c063ad6 */
if(!s->budget--) { s->failed_pc=0x0c063ad6u; return 0; }
r[4]+=0x00000001u;
goto P_0c063ad8;
P_0c063ad8: /* original 34a3, guest PC 0x0c063ad8 */
if(!s->budget--) { s->failed_pc=0x0c063ad8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[10])!=0);
goto P_0c063ada;
P_0c063ada: /* original 8901, guest PC 0x0c063ada */
if(!s->budget--) { s->failed_pc=0x0c063adau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063ae0; }
goto P_0c063adc;
P_0c063adc: /* original aedc, guest PC 0x0c063adc */
if(!s->budget--) { s->failed_pc=0x0c063adcu; return 0; }
goto P_0c063898;
P_0c063ade: /* original 0009, guest PC 0x0c063ade */
if(!s->budget--) { s->failed_pc=0x0c063adeu; return 0; }
goto P_0c063ae0;
P_0c063ae0: /* original e001, guest PC 0x0c063ae0 */
if(!s->budget--) { s->failed_pc=0x0c063ae0u; return 0; }
r[0]=0x00000001u;
goto P_0c063ae2;
P_0c063ae2: /* original 7f04, guest PC 0x0c063ae2 */
if(!s->budget--) { s->failed_pc=0x0c063ae2u; return 0; }
r[15]+=0x00000004u;
goto P_0c063ae4;
P_0c063ae4: /* original 4f26, guest PC 0x0c063ae4 */
if(!s->budget--) { s->failed_pc=0x0c063ae4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063ae6;
P_0c063ae6: /* original 68f6, guest PC 0x0c063ae6 */
if(!s->budget--) { s->failed_pc=0x0c063ae6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c063ae8;
P_0c063ae8: /* original 69f6, guest PC 0x0c063ae8 */
if(!s->budget--) { s->failed_pc=0x0c063ae8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c063aea;
P_0c063aea: /* original 6af6, guest PC 0x0c063aea */
if(!s->budget--) { s->failed_pc=0x0c063aeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c063aec;
P_0c063aec: /* original 6bf6, guest PC 0x0c063aec */
if(!s->budget--) { s->failed_pc=0x0c063aecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c063aee;
P_0c063aee: /* original 6cf6, guest PC 0x0c063aee */
if(!s->budget--) { s->failed_pc=0x0c063aeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c063af0;
P_0c063af0: /* original 6df6, guest PC 0x0c063af0 */
if(!s->budget--) { s->failed_pc=0x0c063af0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c063af2;
P_0c063af2: /* original 000b, guest PC 0x0c063af2 */
if(!s->budget--) { s->failed_pc=0x0c063af2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c063af4: /* original 6ef6, guest PC 0x0c063af4 */
if(!s->budget--) { s->failed_pc=0x0c063af4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c063af6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
