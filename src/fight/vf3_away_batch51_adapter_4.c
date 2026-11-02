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
int vf3_away_batch51_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c084c48u: goto P_0c084c48;
case 0x0c084c4au: goto P_0c084c4a;
case 0x0c084c4cu: goto P_0c084c4c;
case 0x0c084c4eu: goto P_0c084c4e;
case 0x0c084c50u: goto P_0c084c50;
case 0x0c084c52u: goto P_0c084c52;
case 0x0c084c54u: goto P_0c084c54;
case 0x0c084c56u: goto P_0c084c56;
case 0x0c084c58u: goto P_0c084c58;
case 0x0c084c5au: goto P_0c084c5a;
case 0x0c084c5cu: goto P_0c084c5c;
case 0x0c084c5eu: goto P_0c084c5e;
case 0x0c084c60u: goto P_0c084c60;
case 0x0c084c62u: goto P_0c084c62;
case 0x0c084c64u: goto P_0c084c64;
case 0x0c084c66u: goto P_0c084c66;
case 0x0c084c68u: goto P_0c084c68;
case 0x0c084c6au: goto P_0c084c6a;
case 0x0c084c6cu: goto P_0c084c6c;
case 0x0c084c6eu: goto P_0c084c6e;
case 0x0c084c70u: goto P_0c084c70;
case 0x0c084c72u: goto P_0c084c72;
case 0x0c084c74u: goto P_0c084c74;
case 0x0c084c76u: goto P_0c084c76;
case 0x0c084c78u: goto P_0c084c78;
case 0x0c084c7au: goto P_0c084c7a;
case 0x0c084c7cu: goto P_0c084c7c;
case 0x0c084c7eu: goto P_0c084c7e;
case 0x0c084c80u: goto P_0c084c80;
case 0x0c084c82u: goto P_0c084c82;
case 0x0c084c84u: goto P_0c084c84;
case 0x0c084c86u: goto P_0c084c86;
case 0x0c084c88u: goto P_0c084c88;
case 0x0c084c8au: goto P_0c084c8a;
case 0x0c084c8cu: goto P_0c084c8c;
case 0x0c084c8eu: goto P_0c084c8e;
case 0x0c084c90u: goto P_0c084c90;
case 0x0c084c92u: goto P_0c084c92;
case 0x0c084c94u: goto P_0c084c94;
case 0x0c084c96u: goto P_0c084c96;
case 0x0c084c98u: goto P_0c084c98;
case 0x0c084c9au: goto P_0c084c9a;
case 0x0c084c9cu: goto P_0c084c9c;
case 0x0c084c9eu: goto P_0c084c9e;
case 0x0c084ca0u: goto P_0c084ca0;
case 0x0c084ca2u: goto P_0c084ca2;
case 0x0c084ca4u: goto P_0c084ca4;
case 0x0c084ca6u: goto P_0c084ca6;
case 0x0c084ca8u: goto P_0c084ca8;
case 0x0c084caau: goto P_0c084caa;
case 0x0c084cacu: goto P_0c084cac;
case 0x0c084caeu: goto P_0c084cae;
case 0x0c084cb0u: goto P_0c084cb0;
case 0x0c084cb2u: goto P_0c084cb2;
case 0x0c084cb4u: goto P_0c084cb4;
case 0x0c084cb6u: goto P_0c084cb6;
case 0x0c084cb8u: goto P_0c084cb8;
case 0x0c084cbau: goto P_0c084cba;
case 0x0c084cbcu: goto P_0c084cbc;
case 0x0c084cbeu: goto P_0c084cbe;
case 0x0c084cc0u: goto P_0c084cc0;
case 0x0c084cc2u: goto P_0c084cc2;
case 0x0c084cc4u: goto P_0c084cc4;
case 0x0c084cc6u: goto P_0c084cc6;
case 0x0c084cc8u: goto P_0c084cc8;
case 0x0c084ccau: goto P_0c084cca;
case 0x0c084cccu: goto P_0c084ccc;
case 0x0c084cceu: goto P_0c084cce;
case 0x0c084cd0u: goto P_0c084cd0;
case 0x0c084cd2u: goto P_0c084cd2;
case 0x0c084cd4u: goto P_0c084cd4;
case 0x0c084cd6u: goto P_0c084cd6;
case 0x0c084cd8u: goto P_0c084cd8;
case 0x0c084cdau: goto P_0c084cda;
case 0x0c084cdcu: goto P_0c084cdc;
case 0x0c084cdeu: goto P_0c084cde;
case 0x0c084ce0u: goto P_0c084ce0;
case 0x0c084ce2u: goto P_0c084ce2;
case 0x0c084ce4u: goto P_0c084ce4;
case 0x0c084ce6u: goto P_0c084ce6;
case 0x0c084ce8u: goto P_0c084ce8;
case 0x0c084ceau: goto P_0c084cea;
case 0x0c084cecu: goto P_0c084cec;
case 0x0c084ceeu: goto P_0c084cee;
case 0x0c084cf0u: goto P_0c084cf0;
case 0x0c084cf2u: goto P_0c084cf2;
case 0x0c084cf4u: goto P_0c084cf4;
case 0x0c084cf6u: goto P_0c084cf6;
case 0x0c084cf8u: goto P_0c084cf8;
case 0x0c084cfau: goto P_0c084cfa;
case 0x0c084cfcu: goto P_0c084cfc;
case 0x0c084cfeu: goto P_0c084cfe;
case 0x0c084d00u: goto P_0c084d00;
case 0x0c084d02u: goto P_0c084d02;
case 0x0c084d04u: goto P_0c084d04;
case 0x0c084d06u: goto P_0c084d06;
case 0x0c084d08u: goto P_0c084d08;
case 0x0c084d0au: goto P_0c084d0a;
case 0x0c084d0cu: goto P_0c084d0c;
case 0x0c084d0eu: goto P_0c084d0e;
case 0x0c084d10u: goto P_0c084d10;
case 0x0c084d12u: goto P_0c084d12;
case 0x0c084d4cu: goto P_0c084d4c;
case 0x0c084d4eu: goto P_0c084d4e;
case 0x0c084d50u: goto P_0c084d50;
case 0x0c084d52u: goto P_0c084d52;
case 0x0c084d54u: goto P_0c084d54;
case 0x0c084d56u: goto P_0c084d56;
case 0x0c084d58u: goto P_0c084d58;
case 0x0c084d5au: goto P_0c084d5a;
case 0x0c084d5cu: goto P_0c084d5c;
case 0x0c084d5eu: goto P_0c084d5e;
case 0x0c084d60u: goto P_0c084d60;
case 0x0c084d62u: goto P_0c084d62;
case 0x0c084d64u: goto P_0c084d64;
case 0x0c084d66u: goto P_0c084d66;
case 0x0c084d68u: goto P_0c084d68;
case 0x0c084d6au: goto P_0c084d6a;
case 0x0c084d6cu: goto P_0c084d6c;
case 0x0c084d6eu: goto P_0c084d6e;
case 0x0c084d70u: goto P_0c084d70;
case 0x0c084d72u: goto P_0c084d72;
case 0x0c084d74u: goto P_0c084d74;
case 0x0c084d76u: goto P_0c084d76;
case 0x0c084d78u: goto P_0c084d78;
case 0x0c084d7au: goto P_0c084d7a;
case 0x0c084d7cu: goto P_0c084d7c;
case 0x0c084d7eu: goto P_0c084d7e;
case 0x0c084d80u: goto P_0c084d80;
case 0x0c084d82u: goto P_0c084d82;
case 0x0c084d84u: goto P_0c084d84;
case 0x0c084d86u: goto P_0c084d86;
case 0x0c084d88u: goto P_0c084d88;
case 0x0c084d8au: goto P_0c084d8a;
case 0x0c084d8cu: goto P_0c084d8c;
case 0x0c084d8eu: goto P_0c084d8e;
case 0x0c084d90u: goto P_0c084d90;
case 0x0c084d92u: goto P_0c084d92;
case 0x0c084d94u: goto P_0c084d94;
case 0x0c084d96u: goto P_0c084d96;
case 0x0c084d98u: goto P_0c084d98;
case 0x0c084d9au: goto P_0c084d9a;
case 0x0c084d9cu: goto P_0c084d9c;
case 0x0c084d9eu: goto P_0c084d9e;
case 0x0c084da0u: goto P_0c084da0;
case 0x0c084da2u: goto P_0c084da2;
case 0x0c084da4u: goto P_0c084da4;
case 0x0c084da6u: goto P_0c084da6;
case 0x0c084da8u: goto P_0c084da8;
case 0x0c084daau: goto P_0c084daa;
case 0x0c084dacu: goto P_0c084dac;
case 0x0c084daeu: goto P_0c084dae;
case 0x0c084db0u: goto P_0c084db0;
case 0x0c084db2u: goto P_0c084db2;
case 0x0c084db4u: goto P_0c084db4;
case 0x0c084db6u: goto P_0c084db6;
case 0x0c084db8u: goto P_0c084db8;
case 0x0c084dbau: goto P_0c084dba;
case 0x0c084dbcu: goto P_0c084dbc;
case 0x0c084dbeu: goto P_0c084dbe;
case 0x0c085044u: goto P_0c085044;
case 0x0c085046u: goto P_0c085046;
case 0x0c085048u: goto P_0c085048;
case 0x0c08504au: goto P_0c08504a;
case 0x0c08504cu: goto P_0c08504c;
case 0x0c08504eu: goto P_0c08504e;
case 0x0c085050u: goto P_0c085050;
case 0x0c085052u: goto P_0c085052;
case 0x0c085054u: goto P_0c085054;
case 0x0c085056u: goto P_0c085056;
case 0x0c085058u: goto P_0c085058;
case 0x0c08505au: goto P_0c08505a;
case 0x0c08505cu: goto P_0c08505c;
case 0x0c08505eu: goto P_0c08505e;
case 0x0c085060u: goto P_0c085060;
case 0x0c085062u: goto P_0c085062;
case 0x0c085064u: goto P_0c085064;
case 0x0c085066u: goto P_0c085066;
case 0x0c085068u: goto P_0c085068;
case 0x0c08506au: goto P_0c08506a;
case 0x0c08506cu: goto P_0c08506c;
case 0x0c08506eu: goto P_0c08506e;
case 0x0c085070u: goto P_0c085070;
case 0x0c085072u: goto P_0c085072;
case 0x0c085074u: goto P_0c085074;
case 0x0c085076u: goto P_0c085076;
case 0x0c085078u: goto P_0c085078;
case 0x0c08507au: goto P_0c08507a;
case 0x0c08507cu: goto P_0c08507c;
case 0x0c08507eu: goto P_0c08507e;
case 0x0c085080u: goto P_0c085080;
case 0x0c085082u: goto P_0c085082;
case 0x0c085084u: goto P_0c085084;
case 0x0c085086u: goto P_0c085086;
case 0x0c085088u: goto P_0c085088;
case 0x0c08508au: goto P_0c08508a;
case 0x0c08508cu: goto P_0c08508c;
case 0x0c08508eu: goto P_0c08508e;
case 0x0c085090u: goto P_0c085090;
case 0x0c085092u: goto P_0c085092;
case 0x0c085094u: goto P_0c085094;
case 0x0c085096u: goto P_0c085096;
case 0x0c085098u: goto P_0c085098;
case 0x0c08509au: goto P_0c08509a;
case 0x0c08509cu: goto P_0c08509c;
case 0x0c08509eu: goto P_0c08509e;
case 0x0c0850a0u: goto P_0c0850a0;
case 0x0c0850a2u: goto P_0c0850a2;
case 0x0c0850a4u: goto P_0c0850a4;
case 0x0c0850a6u: goto P_0c0850a6;
case 0x0c0850a8u: goto P_0c0850a8;
case 0x0c0850aau: goto P_0c0850aa;
case 0x0c0850acu: goto P_0c0850ac;
case 0x0c0850aeu: goto P_0c0850ae;
case 0x0c0850b0u: goto P_0c0850b0;
case 0x0c0850b2u: goto P_0c0850b2;
case 0x0c0850b4u: goto P_0c0850b4;
case 0x0c0850b6u: goto P_0c0850b6;
case 0x0c0850b8u: goto P_0c0850b8;
case 0x0c0850bau: goto P_0c0850ba;
case 0x0c0850bcu: goto P_0c0850bc;
case 0x0c0850beu: goto P_0c0850be;
case 0x0c0850c0u: goto P_0c0850c0;
case 0x0c0850c2u: goto P_0c0850c2;
case 0x0c0850c4u: goto P_0c0850c4;
case 0x0c0850c6u: goto P_0c0850c6;
case 0x0c0850c8u: goto P_0c0850c8;
case 0x0c0850cau: goto P_0c0850ca;
case 0x0c0850ccu: goto P_0c0850cc;
case 0x0c0850ceu: goto P_0c0850ce;
case 0x0c0850d0u: goto P_0c0850d0;
case 0x0c0850d2u: goto P_0c0850d2;
case 0x0c0850d4u: goto P_0c0850d4;
case 0x0c0850d6u: goto P_0c0850d6;
case 0x0c0850d8u: goto P_0c0850d8;
case 0x0c0850dau: goto P_0c0850da;
case 0x0c0850dcu: goto P_0c0850dc;
case 0x0c0850deu: goto P_0c0850de;
case 0x0c0850e0u: goto P_0c0850e0;
case 0x0c0850e2u: goto P_0c0850e2;
case 0x0c0850e4u: goto P_0c0850e4;
case 0x0c0850e6u: goto P_0c0850e6;
case 0x0c0850e8u: goto P_0c0850e8;
case 0x0c0850eau: goto P_0c0850ea;
case 0x0c0850ecu: goto P_0c0850ec;
case 0x0c085118u: goto P_0c085118;
case 0x0c08511au: goto P_0c08511a;
case 0x0c08511cu: goto P_0c08511c;
case 0x0c08511eu: goto P_0c08511e;
case 0x0c085120u: goto P_0c085120;
case 0x0c085122u: goto P_0c085122;
case 0x0c085124u: goto P_0c085124;
case 0x0c085126u: goto P_0c085126;
case 0x0c085128u: goto P_0c085128;
case 0x0c08512au: goto P_0c08512a;
case 0x0c08512cu: goto P_0c08512c;
case 0x0c08512eu: goto P_0c08512e;
case 0x0c085130u: goto P_0c085130;
case 0x0c085132u: goto P_0c085132;
case 0x0c085134u: goto P_0c085134;
case 0x0c085136u: goto P_0c085136;
case 0x0c085138u: goto P_0c085138;
case 0x0c08513au: goto P_0c08513a;
case 0x0c08513cu: goto P_0c08513c;
case 0x0c08513eu: goto P_0c08513e;
case 0x0c085140u: goto P_0c085140;
case 0x0c085142u: goto P_0c085142;
case 0x0c085144u: goto P_0c085144;
case 0x0c085146u: goto P_0c085146;
case 0x0c085148u: goto P_0c085148;
case 0x0c08514au: goto P_0c08514a;
case 0x0c08514cu: goto P_0c08514c;
case 0x0c08514eu: goto P_0c08514e;
case 0x0c085150u: goto P_0c085150;
case 0x0c085152u: goto P_0c085152;
case 0x0c085154u: goto P_0c085154;
case 0x0c085156u: goto P_0c085156;
case 0x0c085158u: goto P_0c085158;
case 0x0c08515au: goto P_0c08515a;
case 0x0c08515cu: goto P_0c08515c;
case 0x0c08515eu: goto P_0c08515e;
case 0x0c085160u: goto P_0c085160;
case 0x0c085162u: goto P_0c085162;
case 0x0c085164u: goto P_0c085164;
case 0x0c085166u: goto P_0c085166;
case 0x0c085168u: goto P_0c085168;
case 0x0c08516au: goto P_0c08516a;
case 0x0c08516cu: goto P_0c08516c;
case 0x0c08516eu: goto P_0c08516e;
case 0x0c085170u: goto P_0c085170;
case 0x0c085172u: goto P_0c085172;
case 0x0c085174u: goto P_0c085174;
case 0x0c085176u: goto P_0c085176;
case 0x0c085178u: goto P_0c085178;
case 0x0c08517au: goto P_0c08517a;
case 0x0c08517cu: goto P_0c08517c;
case 0x0c08517eu: goto P_0c08517e;
case 0x0c085180u: goto P_0c085180;
case 0x0c085182u: goto P_0c085182;
case 0x0c085184u: goto P_0c085184;
case 0x0c085186u: goto P_0c085186;
case 0x0c085188u: goto P_0c085188;
case 0x0c08518au: goto P_0c08518a;
case 0x0c08518cu: goto P_0c08518c;
case 0x0c08518eu: goto P_0c08518e;
case 0x0c085190u: goto P_0c085190;
case 0x0c085192u: goto P_0c085192;
case 0x0c085194u: goto P_0c085194;
case 0x0c085196u: goto P_0c085196;
case 0x0c085198u: goto P_0c085198;
case 0x0c08519au: goto P_0c08519a;
case 0x0c08519cu: goto P_0c08519c;
case 0x0c08519eu: goto P_0c08519e;
case 0x0c0851a0u: goto P_0c0851a0;
case 0x0c0851a2u: goto P_0c0851a2;
case 0x0c0851a4u: goto P_0c0851a4;
case 0x0c0851a6u: goto P_0c0851a6;
case 0x0c0851a8u: goto P_0c0851a8;
case 0x0c0851aau: goto P_0c0851aa;
case 0x0c0851acu: goto P_0c0851ac;
case 0x0c0851aeu: goto P_0c0851ae;
case 0x0c0851b0u: goto P_0c0851b0;
case 0x0c0851b2u: goto P_0c0851b2;
case 0x0c0851b4u: goto P_0c0851b4;
case 0x0c0851b6u: goto P_0c0851b6;
case 0x0c0851b8u: goto P_0c0851b8;
case 0x0c0851bau: goto P_0c0851ba;
case 0x0c0851bcu: goto P_0c0851bc;
case 0x0c0851beu: goto P_0c0851be;
case 0x0c0851c0u: goto P_0c0851c0;
case 0x0c0851c2u: goto P_0c0851c2;
case 0x0c0851c4u: goto P_0c0851c4;
case 0x0c0851c6u: goto P_0c0851c6;
case 0x0c0851c8u: goto P_0c0851c8;
case 0x0c0851cau: goto P_0c0851ca;
case 0x0c0851ccu: goto P_0c0851cc;
case 0x0c0851ceu: goto P_0c0851ce;
case 0x0c0851d0u: goto P_0c0851d0;
case 0x0c0851d2u: goto P_0c0851d2;
case 0x0c0851d4u: goto P_0c0851d4;
case 0x0c0851d6u: goto P_0c0851d6;
case 0x0c0851d8u: goto P_0c0851d8;
case 0x0c0851dau: goto P_0c0851da;
case 0x0c0851dcu: goto P_0c0851dc;
case 0x0c0851deu: goto P_0c0851de;
case 0x0c0851e0u: goto P_0c0851e0;
case 0x0c0851e2u: goto P_0c0851e2;
case 0x0c0851e4u: goto P_0c0851e4;
case 0x0c0851e6u: goto P_0c0851e6;
case 0x0c0851e8u: goto P_0c0851e8;
case 0x0c0851eau: goto P_0c0851ea;
case 0x0c0851ecu: goto P_0c0851ec;
case 0x0c0851eeu: goto P_0c0851ee;
case 0x0c0851f0u: goto P_0c0851f0;
case 0x0c0851f2u: goto P_0c0851f2;
case 0x0c0851f4u: goto P_0c0851f4;
case 0x0c0851f6u: goto P_0c0851f6;
case 0x0c0851f8u: goto P_0c0851f8;
case 0x0c0851fau: goto P_0c0851fa;
case 0x0c0851fcu: goto P_0c0851fc;
case 0x0c0851feu: goto P_0c0851fe;
case 0x0c085200u: goto P_0c085200;
case 0x0c085202u: goto P_0c085202;
case 0x0c085204u: goto P_0c085204;
case 0x0c085206u: goto P_0c085206;
case 0x0c085208u: goto P_0c085208;
case 0x0c08520au: goto P_0c08520a;
case 0x0c08520cu: goto P_0c08520c;
case 0x0c08520eu: goto P_0c08520e;
case 0x0c085210u: goto P_0c085210;
case 0x0c085212u: goto P_0c085212;
case 0x0c085214u: goto P_0c085214;
case 0x0c085216u: goto P_0c085216;
case 0x0c085218u: goto P_0c085218;
case 0x0c08521au: goto P_0c08521a;
case 0x0c08521cu: goto P_0c08521c;
case 0x0c08521eu: goto P_0c08521e;
case 0x0c085220u: goto P_0c085220;
case 0x0c085222u: goto P_0c085222;
case 0x0c085224u: goto P_0c085224;
case 0x0c085226u: goto P_0c085226;
case 0x0c085228u: goto P_0c085228;
case 0x0c08522au: goto P_0c08522a;
case 0x0c08522cu: goto P_0c08522c;
case 0x0c08522eu: goto P_0c08522e;
case 0x0c085230u: goto P_0c085230;
case 0x0c085232u: goto P_0c085232;
case 0x0c085234u: goto P_0c085234;
case 0x0c085236u: goto P_0c085236;
case 0x0c085238u: goto P_0c085238;
default: return vf3_matrix_family(target,s,ram);
}
P_0c084c48: /* original 2fe6, guest PC 0x0c084c48 */
if(!s->budget--) { s->failed_pc=0x0c084c48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c4a;
P_0c084c4a: /* original c735, guest PC 0x0c084c4a */
if(!s->budget--) { s->failed_pc=0x0c084c4au; return 0; }
r[0]=code_base|0x00084d20u;
goto P_0c084c4c;
P_0c084c4c: /* original 2fd6, guest PC 0x0c084c4c */
if(!s->budget--) { s->failed_pc=0x0c084c4cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c4e;
P_0c084c4e: /* original 6e43, guest PC 0x0c084c4e */
if(!s->budget--) { s->failed_pc=0x0c084c4eu; return 0; }
r[14]=r[4];
goto P_0c084c50;
P_0c084c50: /* original 2fc6, guest PC 0x0c084c50 */
if(!s->budget--) { s->failed_pc=0x0c084c50u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c52;
P_0c084c52: /* original 7e14, guest PC 0x0c084c52 */
if(!s->budget--) { s->failed_pc=0x0c084c52u; return 0; }
r[14]+=0x00000014u;
goto P_0c084c54;
P_0c084c54: /* original 2fb6, guest PC 0x0c084c54 */
if(!s->budget--) { s->failed_pc=0x0c084c54u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c56;
P_0c084c56: /* original 2fa6, guest PC 0x0c084c56 */
if(!s->budget--) { s->failed_pc=0x0c084c56u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c58;
P_0c084c58: /* original 2f96, guest PC 0x0c084c58 */
if(!s->budget--) { s->failed_pc=0x0c084c58u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c5a;
P_0c084c5a: /* original 2f86, guest PC 0x0c084c5a */
if(!s->budget--) { s->failed_pc=0x0c084c5au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084c5c;
P_0c084c5c: /* original fffb, guest PC 0x0c084c5c */
if(!s->budget--) { s->failed_pc=0x0c084c5cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c084c5e;
P_0c084c5e: /* original ffeb, guest PC 0x0c084c5e */
if(!s->budget--) { s->failed_pc=0x0c084c5eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c084c60;
P_0c084c60: /* original ffdb, guest PC 0x0c084c60 */
if(!s->budget--) { s->failed_pc=0x0c084c60u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c084c62;
P_0c084c62: /* original ffcb, guest PC 0x0c084c62 */
if(!s->budget--) { s->failed_pc=0x0c084c62u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c084c64;
P_0c084c64: /* original 4f22, guest PC 0x0c084c64 */
if(!s->budget--) { s->failed_pc=0x0c084c64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084c66;
P_0c084c66: /* original 7fd8, guest PC 0x0c084c66 */
if(!s->budget--) { s->failed_pc=0x0c084c66u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c084c68;
P_0c084c68: /* original 1f43, guest PC 0x0c084c68 */
if(!s->budget--) { s->failed_pc=0x0c084c68u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c084c6a;
P_0c084c6a: /* original f308, guest PC 0x0c084c6a */
if(!s->budget--) { s->failed_pc=0x0c084c6au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c084c6c;
P_0c084c6c: /* original e008, guest PC 0x0c084c6c */
if(!s->budget--) { s->failed_pc=0x0c084c6cu; return 0; }
r[0]=0x00000008u;
goto P_0c084c6e;
P_0c084c6e: /* original d32b, guest PC 0x0c084c6e */
if(!s->budget--) { s->failed_pc=0x0c084c6eu; return 0; }
r[3]=read(ram,0x0c084d1cu,4);
goto P_0c084c70;
P_0c084c70: /* original 6d32, guest PC 0x0c084c70 */
if(!s->budget--) { s->failed_pc=0x0c084c70u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c084c72;
P_0c084c72: /* original ff37, guest PC 0x0c084c72 */
if(!s->budget--) { s->failed_pc=0x0c084c72u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084c74;
P_0c084c74: /* original c72b, guest PC 0x0c084c74 */
if(!s->budget--) { s->failed_pc=0x0c084c74u; return 0; }
r[0]=code_base|0x00084d24u;
goto P_0c084c76;
P_0c084c76: /* original f308, guest PC 0x0c084c76 */
if(!s->budget--) { s->failed_pc=0x0c084c76u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c084c78;
P_0c084c78: /* original c72b, guest PC 0x0c084c78 */
if(!s->budget--) { s->failed_pc=0x0c084c78u; return 0; }
r[0]=code_base|0x00084d28u;
goto P_0c084c7a;
P_0c084c7a: /* original ff3a, guest PC 0x0c084c7a */
if(!s->budget--) { s->failed_pc=0x0c084c7au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c084c7c;
P_0c084c7c: /* original f308, guest PC 0x0c084c7c */
if(!s->budget--) { s->failed_pc=0x0c084c7cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c084c7e;
P_0c084c7e: /* original e004, guest PC 0x0c084c7e */
if(!s->budget--) { s->failed_pc=0x0c084c7eu; return 0; }
r[0]=0x00000004u;
goto P_0c084c80;
P_0c084c80: /* original ff37, guest PC 0x0c084c80 */
if(!s->budget--) { s->failed_pc=0x0c084c80u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084c82;
P_0c084c82: /* original d22a, guest PC 0x0c084c82 */
if(!s->budget--) { s->failed_pc=0x0c084c82u; return 0; }
r[2]=read(ram,0x0c084d2cu,4);
goto P_0c084c84;
P_0c084c84: /* original 420b, guest PC 0x0c084c84 */
if(!s->budget--) { s->failed_pc=0x0c084c84u; return 0; }
target=r[2];
r[16]=code_base|0x0c084c88u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084c88u) { target=s->pc; goto dispatch; }
goto P_0c084c88;
P_0c084c86: /* original e400, guest PC 0x0c084c86 */
if(!s->budget--) { s->failed_pc=0x0c084c86u; return 0; }
r[4]=0x00000000u;
goto P_0c084c88;
P_0c084c88: /* original da2b, guest PC 0x0c084c88 */
if(!s->budget--) { s->failed_pc=0x0c084c88u; return 0; }
r[10]=read(ram,0x0c084d38u,4);
goto P_0c084c8a;
P_0c084c8a: /* original ec0a, guest PC 0x0c084c8a */
if(!s->budget--) { s->failed_pc=0x0c084c8au; return 0; }
r[12]=0x0000000au;
goto P_0c084c8c;
P_0c084c8c: /* original d929, guest PC 0x0c084c8c */
if(!s->budget--) { s->failed_pc=0x0c084c8cu; return 0; }
r[9]=read(ram,0x0c084d34u,4);
goto P_0c084c8e;
P_0c084c8e: /* original d828, guest PC 0x0c084c8e */
if(!s->budget--) { s->failed_pc=0x0c084c8eu; return 0; }
r[8]=read(ram,0x0c084d30u,4);
goto P_0c084c90;
P_0c084c90: /* original e004, guest PC 0x0c084c90 */
if(!s->budget--) { s->failed_pc=0x0c084c90u; return 0; }
r[0]=0x00000004u;
goto P_0c084c92;
P_0c084c92: /* original fde8, guest PC 0x0c084c92 */
if(!s->budget--) { s->failed_pc=0x0c084c92u; return 0; }
vf3_matrix_load(s,ram,13,r[14]);
goto P_0c084c94;
P_0c084c94: /* original f3e6, guest PC 0x0c084c94 */
if(!s->budget--) { s->failed_pc=0x0c084c94u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c084c96;
P_0c084c96: /* original e010, guest PC 0x0c084c96 */
if(!s->budget--) { s->failed_pc=0x0c084c96u; return 0; }
r[0]=0x00000010u;
goto P_0c084c98;
P_0c084c98: /* original ff37, guest PC 0x0c084c98 */
if(!s->budget--) { s->failed_pc=0x0c084c98u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084c9a;
P_0c084c9a: /* original e008, guest PC 0x0c084c9a */
if(!s->budget--) { s->failed_pc=0x0c084c9au; return 0; }
r[0]=0x00000008u;
goto P_0c084c9c;
P_0c084c9c: /* original f2e6, guest PC 0x0c084c9c */
if(!s->budget--) { s->failed_pc=0x0c084c9cu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c084c9e;
P_0c084c9e: /* original e010, guest PC 0x0c084c9e */
if(!s->budget--) { s->failed_pc=0x0c084c9eu; return 0; }
r[0]=0x00000010u;
goto P_0c084ca0;
P_0c084ca0: /* original f39d, guest PC 0x0c084ca0 */
if(!s->budget--) { s->failed_pc=0x0c084ca0u; return 0; }
fr[3]=0x3f800000u;
goto P_0c084ca2;
P_0c084ca2: /* original f232, guest PC 0x0c084ca2 */
if(!s->budget--) { s->failed_pc=0x0c084ca2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c084ca4;
P_0c084ca4: /* original f4d6, guest PC 0x0c084ca4 */
if(!s->budget--) { s->failed_pc=0x0c084ca4u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c084ca6;
P_0c084ca6: /* original e018, guest PC 0x0c084ca6 */
if(!s->budget--) { s->failed_pc=0x0c084ca6u; return 0; }
r[0]=0x00000018u;
goto P_0c084ca8;
P_0c084ca8: /* original fcd6, guest PC 0x0c084ca8 */
if(!s->budget--) { s->failed_pc=0x0c084ca8u; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c084caa;
P_0c084caa: /* original fe2c, guest PC 0x0c084caa */
if(!s->budget--) { s->failed_pc=0x0c084caau; return 0; }
vf3_matrix_move(s,14,2);
goto P_0c084cac;
P_0c084cac: /* original f5cc, guest PC 0x0c084cac */
if(!s->budget--) { s->failed_pc=0x0c084cacu; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c084cae;
P_0c084cae: /* original fe4d, guest PC 0x0c084cae */
if(!s->budget--) { s->failed_pc=0x0c084caeu; return 0; }
fr[14]^=0x80000000u;
goto P_0c084cb0;
P_0c084cb0: /* original f5e1, guest PC 0x0c084cb0 */
if(!s->budget--) { s->failed_pc=0x0c084cb0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c084cb2;
P_0c084cb2: /* original 490b, guest PC 0x0c084cb2 */
if(!s->budget--) { s->failed_pc=0x0c084cb2u; return 0; }
target=r[9];
r[16]=code_base|0x0c084cb6u;
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084cb6u) { target=s->pc; goto dispatch; }
goto P_0c084cb6;
P_0c084cb4: /* original f4d1, guest PC 0x0c084cb4 */
if(!s->budget--) { s->failed_pc=0x0c084cb4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c084cb6;
P_0c084cb6: /* original d321, guest PC 0x0c084cb6 */
if(!s->budget--) { s->failed_pc=0x0c084cb6u; return 0; }
r[3]=read(ram,0x0c084d3cu,4);
goto P_0c084cb8;
P_0c084cb8: /* original 6b0f, guest PC 0x0c084cb8 */
if(!s->budget--) { s->failed_pc=0x0c084cb8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c084cba;
P_0c084cba: /* original e014, guest PC 0x0c084cba */
if(!s->budget--) { s->failed_pc=0x0c084cbau; return 0; }
r[0]=0x00000014u;
goto P_0c084cbc;
P_0c084cbc: /* original 430b, guest PC 0x0c084cbc */
if(!s->budget--) { s->failed_pc=0x0c084cbcu; return 0; }
target=r[3];
r[16]=code_base|0x0c084cc0u;
vf3_matrix_load(s,ram,15,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084cc0u) { target=s->pc; goto dispatch; }
goto P_0c084cc0;
P_0c084cbe: /* original ffe6, guest PC 0x0c084cbe */
if(!s->budget--) { s->failed_pc=0x0c084cbeu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c084cc0;
P_0c084cc0: /* original d21f, guest PC 0x0c084cc0 */
if(!s->budget--) { s->failed_pc=0x0c084cc0u; return 0; }
r[2]=read(ram,0x0c084d40u,4);
goto P_0c084cc2;
P_0c084cc2: /* original f5fc, guest PC 0x0c084cc2 */
if(!s->budget--) { s->failed_pc=0x0c084cc2u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c084cc4;
P_0c084cc4: /* original f6fc, guest PC 0x0c084cc4 */
if(!s->budget--) { s->failed_pc=0x0c084cc4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c084cc6;
P_0c084cc6: /* original 420b, guest PC 0x0c084cc6 */
if(!s->budget--) { s->failed_pc=0x0c084cc6u; return 0; }
target=r[2];
r[16]=code_base|0x0c084ccau;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084ccau) { target=s->pc; goto dispatch; }
goto P_0c084cca;
P_0c084cc8: /* original f4fc, guest PC 0x0c084cc8 */
if(!s->budget--) { s->failed_pc=0x0c084cc8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c084cca;
P_0c084cca: /* original e01c, guest PC 0x0c084cca */
if(!s->budget--) { s->failed_pc=0x0c084ccau; return 0; }
r[0]=0x0000001cu;
goto P_0c084ccc;
P_0c084ccc: /* original 64f3, guest PC 0x0c084ccc */
if(!s->budget--) { s->failed_pc=0x0c084cccu; return 0; }
r[4]=r[15];
goto P_0c084cce;
P_0c084cce: /* original ffd7, guest PC 0x0c084cce */
if(!s->budget--) { s->failed_pc=0x0c084cceu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c084cd0;
P_0c084cd0: /* original e010, guest PC 0x0c084cd0 */
if(!s->budget--) { s->failed_pc=0x0c084cd0u; return 0; }
r[0]=0x00000010u;
goto P_0c084cd2;
P_0c084cd2: /* original f3f6, guest PC 0x0c084cd2 */
if(!s->budget--) { s->failed_pc=0x0c084cd2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084cd4;
P_0c084cd4: /* original e020, guest PC 0x0c084cd4 */
if(!s->budget--) { s->failed_pc=0x0c084cd4u; return 0; }
r[0]=0x00000020u;
goto P_0c084cd6;
P_0c084cd6: /* original ff37, guest PC 0x0c084cd6 */
if(!s->budget--) { s->failed_pc=0x0c084cd6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084cd8;
P_0c084cd8: /* original e024, guest PC 0x0c084cd8 */
if(!s->budget--) { s->failed_pc=0x0c084cd8u; return 0; }
r[0]=0x00000024u;
goto P_0c084cda;
P_0c084cda: /* original ffe7, guest PC 0x0c084cda */
if(!s->budget--) { s->failed_pc=0x0c084cdau; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c084cdc;
P_0c084cdc: /* original d319, guest PC 0x0c084cdc */
if(!s->budget--) { s->failed_pc=0x0c084cdcu; return 0; }
r[3]=read(ram,0x0c084d44u,4);
goto P_0c084cde;
P_0c084cde: /* original 430b, guest PC 0x0c084cde */
if(!s->budget--) { s->failed_pc=0x0c084cdeu; return 0; }
target=r[3];
r[16]=code_base|0x0c084ce2u;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084ce2u) { target=s->pc; goto dispatch; }
goto P_0c084ce2;
P_0c084ce0: /* original 741c, guest PC 0x0c084ce0 */
if(!s->budget--) { s->failed_pc=0x0c084ce0u; return 0; }
r[4]+=0x0000001cu;
goto P_0c084ce2;
P_0c084ce2: /* original d219, guest PC 0x0c084ce2 */
if(!s->budget--) { s->failed_pc=0x0c084ce2u; return 0; }
r[2]=read(ram,0x0c084d48u,4);
goto P_0c084ce4;
P_0c084ce4: /* original 420b, guest PC 0x0c084ce4 */
if(!s->budget--) { s->failed_pc=0x0c084ce4u; return 0; }
target=r[2];
r[16]=code_base|0x0c084ce8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084ce8u) { target=s->pc; goto dispatch; }
goto P_0c084ce8;
P_0c084ce6: /* original f4fc, guest PC 0x0c084ce6 */
if(!s->budget--) { s->failed_pc=0x0c084ce6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c084ce8;
P_0c084ce8: /* original 4a0b, guest PC 0x0c084ce8 */
if(!s->budget--) { s->failed_pc=0x0c084ce8u; return 0; }
target=r[10];
r[16]=code_base|0x0c084cecu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084cecu) { target=s->pc; goto dispatch; }
goto P_0c084cec;
P_0c084cea: /* original 64b3, guest PC 0x0c084cea */
if(!s->budget--) { s->failed_pc=0x0c084ceau; return 0; }
r[4]=r[11];
goto P_0c084cec;
P_0c084cec: /* original e008, guest PC 0x0c084cec */
if(!s->budget--) { s->failed_pc=0x0c084cecu; return 0; }
r[0]=0x00000008u;
goto P_0c084cee;
P_0c084cee: /* original f3f6, guest PC 0x0c084cee */
if(!s->budget--) { s->failed_pc=0x0c084ceeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084cf0;
P_0c084cf0: /* original f3f5, guest PC 0x0c084cf0 */
if(!s->budget--) { s->failed_pc=0x0c084cf0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c084cf2;
P_0c084cf2: /* original 8902, guest PC 0x0c084cf2 */
if(!s->budget--) { s->failed_pc=0x0c084cf2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084cfa; }
goto P_0c084cf4;
P_0c084cf4: /* original 940e, guest PC 0x0c084cf4 */
if(!s->budget--) { s->failed_pc=0x0c084cf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084d14u,2);
goto P_0c084cf6;
P_0c084cf6: /* original a02a, guest PC 0x0c084cf6 */
if(!s->budget--) { s->failed_pc=0x0c084cf6u; return 0; }
goto P_0c084d4e;
P_0c084cf8: /* original 0009, guest PC 0x0c084cf8 */
if(!s->budget--) { s->failed_pc=0x0c084cf8u; return 0; }
goto P_0c084cfa;
P_0c084cfa: /* original f3f8, guest PC 0x0c084cfa */
if(!s->budget--) { s->failed_pc=0x0c084cfau; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c084cfc;
P_0c084cfc: /* original f3f5, guest PC 0x0c084cfc */
if(!s->budget--) { s->failed_pc=0x0c084cfcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c084cfe;
P_0c084cfe: /* original 8902, guest PC 0x0c084cfe */
if(!s->budget--) { s->failed_pc=0x0c084cfeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084d06; }
goto P_0c084d00;
P_0c084d00: /* original 9409, guest PC 0x0c084d00 */
if(!s->budget--) { s->failed_pc=0x0c084d00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084d16u,2);
goto P_0c084d02;
P_0c084d02: /* original a024, guest PC 0x0c084d02 */
if(!s->budget--) { s->failed_pc=0x0c084d02u; return 0; }
goto P_0c084d4e;
P_0c084d04: /* original 0009, guest PC 0x0c084d04 */
if(!s->budget--) { s->failed_pc=0x0c084d04u; return 0; }
goto P_0c084d06;
P_0c084d06: /* original e004, guest PC 0x0c084d06 */
if(!s->budget--) { s->failed_pc=0x0c084d06u; return 0; }
r[0]=0x00000004u;
goto P_0c084d08;
P_0c084d08: /* original f3f6, guest PC 0x0c084d08 */
if(!s->budget--) { s->failed_pc=0x0c084d08u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084d0a;
P_0c084d0a: /* original f3f5, guest PC 0x0c084d0a */
if(!s->budget--) { s->failed_pc=0x0c084d0au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c084d0c;
P_0c084d0c: /* original 891e, guest PC 0x0c084d0c */
if(!s->budget--) { s->failed_pc=0x0c084d0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084d4c; }
goto P_0c084d0e;
P_0c084d0e: /* original 9403, guest PC 0x0c084d0e */
if(!s->budget--) { s->failed_pc=0x0c084d0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084d18u,2);
goto P_0c084d10;
P_0c084d10: /* original a01d, guest PC 0x0c084d10 */
if(!s->budget--) { s->failed_pc=0x0c084d10u; return 0; }
goto P_0c084d4e;
P_0c084d12: /* original 0009, guest PC 0x0c084d12 */
if(!s->budget--) { s->failed_pc=0x0c084d12u; return 0; }
if(!vf3_matrix_family(0x0c084d14u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084d14u; return 0; } return 1;
P_0c084d4c: /* original 9438, guest PC 0x0c084d4c */
if(!s->budget--) { s->failed_pc=0x0c084d4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084dc0u,2);
goto P_0c084d4e;
P_0c084d4e: /* original f38d, guest PC 0x0c084d4e */
if(!s->budget--) { s->failed_pc=0x0c084d4eu; return 0; }
fr[3]=0;
goto P_0c084d50;
P_0c084d50: /* original ff35, guest PC 0x0c084d50 */
if(!s->budget--) { s->failed_pc=0x0c084d50u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c084d52;
P_0c084d52: /* original 8b01, guest PC 0x0c084d52 */
if(!s->budget--) { s->failed_pc=0x0c084d52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084d58; }
goto P_0c084d54;
P_0c084d54: /* original 480b, guest PC 0x0c084d54 */
if(!s->budget--) { s->failed_pc=0x0c084d54u; return 0; }
target=r[8];
r[16]=code_base|0x0c084d58u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d58u) { target=s->pc; goto dispatch; }
goto P_0c084d58;
P_0c084d56: /* original 0009, guest PC 0x0c084d56 */
if(!s->budget--) { s->failed_pc=0x0c084d56u; return 0; }
goto P_0c084d58;
P_0c084d58: /* original 4c10, guest PC 0x0c084d58 */
if(!s->budget--) { s->failed_pc=0x0c084d58u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c084d5a;
P_0c084d5a: /* original 8f99, guest PC 0x0c084d5a */
if(!s->budget--) { s->failed_pc=0x0c084d5au; return 0; }
cond=r[17]&1u;
r[14]+=0x0000002cu;
if(!cond) { goto P_0c084c90; }
goto P_0c084d5e;
P_0c084d5c: /* original 7e2c, guest PC 0x0c084d5c */
if(!s->budget--) { s->failed_pc=0x0c084d5cu; return 0; }
r[14]+=0x0000002cu;
goto P_0c084d5e;
P_0c084d5e: /* original c719, guest PC 0x0c084d5e */
if(!s->budget--) { s->failed_pc=0x0c084d5eu; return 0; }
r[0]=code_base|0x00084dc4u;
goto P_0c084d60;
P_0c084d60: /* original fe08, guest PC 0x0c084d60 */
if(!s->budget--) { s->failed_pc=0x0c084d60u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c084d62;
P_0c084d62: /* original c719, guest PC 0x0c084d62 */
if(!s->budget--) { s->failed_pc=0x0c084d62u; return 0; }
r[0]=code_base|0x00084dc8u;
goto P_0c084d64;
P_0c084d64: /* original f308, guest PC 0x0c084d64 */
if(!s->budget--) { s->failed_pc=0x0c084d64u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c084d66;
P_0c084d66: /* original e014, guest PC 0x0c084d66 */
if(!s->budget--) { s->failed_pc=0x0c084d66u; return 0; }
r[0]=0x00000014u;
goto P_0c084d68;
P_0c084d68: /* original ff37, guest PC 0x0c084d68 */
if(!s->budget--) { s->failed_pc=0x0c084d68u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084d6a;
P_0c084d6a: /* original c718, guest PC 0x0c084d6a */
if(!s->budget--) { s->failed_pc=0x0c084d6au; return 0; }
r[0]=code_base|0x00084dccu;
goto P_0c084d6c;
P_0c084d6c: /* original ff08, guest PC 0x0c084d6c */
if(!s->budget--) { s->failed_pc=0x0c084d6cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c084d6e;
P_0c084d6e: /* original e018, guest PC 0x0c084d6e */
if(!s->budget--) { s->failed_pc=0x0c084d6eu; return 0; }
r[0]=0x00000018u;
goto P_0c084d70;
P_0c084d70: /* original f5d6, guest PC 0x0c084d70 */
if(!s->budget--) { s->failed_pc=0x0c084d70u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c084d72;
P_0c084d72: /* original e010, guest PC 0x0c084d72 */
if(!s->budget--) { s->failed_pc=0x0c084d72u; return 0; }
r[0]=0x00000010u;
goto P_0c084d74;
P_0c084d74: /* original f4d6, guest PC 0x0c084d74 */
if(!s->budget--) { s->failed_pc=0x0c084d74u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c084d76;
P_0c084d76: /* original f5f1, guest PC 0x0c084d76 */
if(!s->budget--) { s->failed_pc=0x0c084d76u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c084d78;
P_0c084d78: /* original 490b, guest PC 0x0c084d78 */
if(!s->budget--) { s->failed_pc=0x0c084d78u; return 0; }
target=r[9];
r[16]=code_base|0x0c084d7cu;
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d7cu) { target=s->pc; goto dispatch; }
goto P_0c084d7c;
P_0c084d7a: /* original f4e1, guest PC 0x0c084d7a */
if(!s->budget--) { s->failed_pc=0x0c084d7au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c084d7c;
P_0c084d7c: /* original d314, guest PC 0x0c084d7c */
if(!s->budget--) { s->failed_pc=0x0c084d7cu; return 0; }
r[3]=read(ram,0x0c084dd0u,4);
goto P_0c084d7e;
P_0c084d7e: /* original 600f, guest PC 0x0c084d7e */
if(!s->budget--) { s->failed_pc=0x0c084d7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c084d80;
P_0c084d80: /* original 430b, guest PC 0x0c084d80 */
if(!s->budget--) { s->failed_pc=0x0c084d80u; return 0; }
target=r[3];
r[16]=code_base|0x0c084d84u;
write(ram,r[15]+24,r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d84u) { target=s->pc; goto dispatch; }
goto P_0c084d84;
P_0c084d82: /* original 1f06, guest PC 0x0c084d82 */
if(!s->budget--) { s->failed_pc=0x0c084d82u; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c084d84;
P_0c084d84: /* original e014, guest PC 0x0c084d84 */
if(!s->budget--) { s->failed_pc=0x0c084d84u; return 0; }
r[0]=0x00000014u;
goto P_0c084d86;
P_0c084d86: /* original d313, guest PC 0x0c084d86 */
if(!s->budget--) { s->failed_pc=0x0c084d86u; return 0; }
r[3]=read(ram,0x0c084dd4u,4);
goto P_0c084d88;
P_0c084d88: /* original f5f6, guest PC 0x0c084d88 */
if(!s->budget--) { s->failed_pc=0x0c084d88u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c084d8a;
P_0c084d8a: /* original f6fc, guest PC 0x0c084d8a */
if(!s->budget--) { s->failed_pc=0x0c084d8au; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c084d8c;
P_0c084d8c: /* original 430b, guest PC 0x0c084d8c */
if(!s->budget--) { s->failed_pc=0x0c084d8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c084d90u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d90u) { target=s->pc; goto dispatch; }
goto P_0c084d90;
P_0c084d8e: /* original f4ec, guest PC 0x0c084d8e */
if(!s->budget--) { s->failed_pc=0x0c084d8eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c084d90;
P_0c084d90: /* original 4a0b, guest PC 0x0c084d90 */
if(!s->budget--) { s->failed_pc=0x0c084d90u; return 0; }
target=r[10];
r[16]=code_base|0x0c084d94u;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d94u) { target=s->pc; goto dispatch; }
goto P_0c084d94;
P_0c084d92: /* original 54f6, guest PC 0x0c084d92 */
if(!s->budget--) { s->failed_pc=0x0c084d92u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c084d94;
P_0c084d94: /* original 54f3, guest PC 0x0c084d94 */
if(!s->budget--) { s->failed_pc=0x0c084d94u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c084d96;
P_0c084d96: /* original 9314, guest PC 0x0c084d96 */
if(!s->budget--) { s->failed_pc=0x0c084d96u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084dc2u,2);
goto P_0c084d98;
P_0c084d98: /* original 5442, guest PC 0x0c084d98 */
if(!s->budget--) { s->failed_pc=0x0c084d98u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c084d9a;
P_0c084d9a: /* original 480b, guest PC 0x0c084d9a */
if(!s->budget--) { s->failed_pc=0x0c084d9au; return 0; }
target=r[8];
r[16]=code_base|0x0c084d9eu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084d9eu) { target=s->pc; goto dispatch; }
goto P_0c084d9e;
P_0c084d9c: /* original 343c, guest PC 0x0c084d9c */
if(!s->budget--) { s->failed_pc=0x0c084d9cu; return 0; }
r[4]+=r[3];
goto P_0c084d9e;
P_0c084d9e: /* original d20e, guest PC 0x0c084d9e */
if(!s->budget--) { s->failed_pc=0x0c084d9eu; return 0; }
r[2]=read(ram,0x0c084dd8u,4);
goto P_0c084da0;
P_0c084da0: /* original 420b, guest PC 0x0c084da0 */
if(!s->budget--) { s->failed_pc=0x0c084da0u; return 0; }
target=r[2];
r[16]=code_base|0x0c084da4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084da4u) { target=s->pc; goto dispatch; }
goto P_0c084da4;
P_0c084da2: /* original e401, guest PC 0x0c084da2 */
if(!s->budget--) { s->failed_pc=0x0c084da2u; return 0; }
r[4]=0x00000001u;
goto P_0c084da4;
P_0c084da4: /* original 7f28, guest PC 0x0c084da4 */
if(!s->budget--) { s->failed_pc=0x0c084da4u; return 0; }
r[15]+=0x00000028u;
goto P_0c084da6;
P_0c084da6: /* original 4f26, guest PC 0x0c084da6 */
if(!s->budget--) { s->failed_pc=0x0c084da6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084da8;
P_0c084da8: /* original fcf9, guest PC 0x0c084da8 */
if(!s->budget--) { s->failed_pc=0x0c084da8u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084daa;
P_0c084daa: /* original fdf9, guest PC 0x0c084daa */
if(!s->budget--) { s->failed_pc=0x0c084daau; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084dac;
P_0c084dac: /* original fef9, guest PC 0x0c084dac */
if(!s->budget--) { s->failed_pc=0x0c084dacu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084dae;
P_0c084dae: /* original fff9, guest PC 0x0c084dae */
if(!s->budget--) { s->failed_pc=0x0c084daeu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084db0;
P_0c084db0: /* original 68f6, guest PC 0x0c084db0 */
if(!s->budget--) { s->failed_pc=0x0c084db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c084db2;
P_0c084db2: /* original 69f6, guest PC 0x0c084db2 */
if(!s->budget--) { s->failed_pc=0x0c084db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c084db4;
P_0c084db4: /* original 6af6, guest PC 0x0c084db4 */
if(!s->budget--) { s->failed_pc=0x0c084db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c084db6;
P_0c084db6: /* original 6bf6, guest PC 0x0c084db6 */
if(!s->budget--) { s->failed_pc=0x0c084db6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c084db8;
P_0c084db8: /* original 6cf6, guest PC 0x0c084db8 */
if(!s->budget--) { s->failed_pc=0x0c084db8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084dba;
P_0c084dba: /* original 6df6, guest PC 0x0c084dba */
if(!s->budget--) { s->failed_pc=0x0c084dbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084dbc;
P_0c084dbc: /* original 000b, guest PC 0x0c084dbc */
if(!s->budget--) { s->failed_pc=0x0c084dbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084dbe: /* original 6ef6, guest PC 0x0c084dbe */
if(!s->budget--) { s->failed_pc=0x0c084dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c084dc0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084dc0u; return 0; } return 1;
P_0c085044: /* original 2fe6, guest PC 0x0c085044 */
if(!s->budget--) { s->failed_pc=0x0c085044u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085046;
P_0c085046: /* original 2fd6, guest PC 0x0c085046 */
if(!s->budget--) { s->failed_pc=0x0c085046u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085048;
P_0c085048: /* original 2fc6, guest PC 0x0c085048 */
if(!s->budget--) { s->failed_pc=0x0c085048u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08504a;
P_0c08504a: /* original 2fb6, guest PC 0x0c08504a */
if(!s->budget--) { s->failed_pc=0x0c08504au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08504c;
P_0c08504c: /* original 2fa6, guest PC 0x0c08504c */
if(!s->budget--) { s->failed_pc=0x0c08504cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08504e;
P_0c08504e: /* original 2f96, guest PC 0x0c08504e */
if(!s->budget--) { s->failed_pc=0x0c08504eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085050;
P_0c085050: /* original 2f86, guest PC 0x0c085050 */
if(!s->budget--) { s->failed_pc=0x0c085050u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085052;
P_0c085052: /* original fffb, guest PC 0x0c085052 */
if(!s->budget--) { s->failed_pc=0x0c085052u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085054;
P_0c085054: /* original ffeb, guest PC 0x0c085054 */
if(!s->budget--) { s->failed_pc=0x0c085054u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c085056;
P_0c085056: /* original ffdb, guest PC 0x0c085056 */
if(!s->budget--) { s->failed_pc=0x0c085056u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c085058;
P_0c085058: /* original ffcb, guest PC 0x0c085058 */
if(!s->budget--) { s->failed_pc=0x0c085058u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08505a;
P_0c08505a: /* original d12a, guest PC 0x0c08505a */
if(!s->budget--) { s->failed_pc=0x0c08505au; return 0; }
r[1]=read(ram,0x0c085104u,4);
goto P_0c08505c;
P_0c08505c: /* original 4f22, guest PC 0x0c08505c */
if(!s->budget--) { s->failed_pc=0x0c08505cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08505e;
P_0c08505e: /* original d328, guest PC 0x0c08505e */
if(!s->budget--) { s->failed_pc=0x0c08505eu; return 0; }
r[3]=read(ram,0x0c085100u,4);
goto P_0c085060;
P_0c085060: /* original 6212, guest PC 0x0c085060 */
if(!s->budget--) { s->failed_pc=0x0c085060u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c085062;
P_0c085062: /* original 7fd8, guest PC 0x0c085062 */
if(!s->budget--) { s->failed_pc=0x0c085062u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c085064;
P_0c085064: /* original 2238, guest PC 0x0c085064 */
if(!s->budget--) { s->failed_pc=0x0c085064u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c085066;
P_0c085066: /* original 8d02, guest PC 0x0c085066 */
if(!s->budget--) { s->failed_pc=0x0c085066u; return 0; }
cond=r[17]&1u;
r[8]=r[4];
if(cond) { goto P_0c08506e; }
goto P_0c08506a;
P_0c085068: /* original 6843, guest PC 0x0c085068 */
if(!s->budget--) { s->failed_pc=0x0c085068u; return 0; }
r[8]=r[4];
goto P_0c08506a;
P_0c08506a: /* original a0d8, guest PC 0x0c08506a */
if(!s->budget--) { s->failed_pc=0x0c08506au; return 0; }
goto P_0c08521e;
P_0c08506c: /* original 0009, guest PC 0x0c08506c */
if(!s->budget--) { s->failed_pc=0x0c08506cu; return 0; }
goto P_0c08506e;
P_0c08506e: /* original 9e3e, guest PC 0x0c08506e */
if(!s->budget--) { s->failed_pc=0x0c08506eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0850eeu,2);
goto P_0c085070;
P_0c085070: /* original e302, guest PC 0x0c085070 */
if(!s->budget--) { s->failed_pc=0x0c085070u; return 0; }
r[3]=0x00000002u;
goto P_0c085072;
P_0c085072: /* original d025, guest PC 0x0c085072 */
if(!s->budget--) { s->failed_pc=0x0c085072u; return 0; }
r[0]=read(ram,0x0c085108u,4);
goto P_0c085074;
P_0c085074: /* original 6b83, guest PC 0x0c085074 */
if(!s->budget--) { s->failed_pc=0x0c085074u; return 0; }
r[11]=r[8];
goto P_0c085076;
P_0c085076: /* original 3e8c, guest PC 0x0c085076 */
if(!s->budget--) { s->failed_pc=0x0c085076u; return 0; }
r[14]+=r[8];
goto P_0c085078;
P_0c085078: /* original 6c02, guest PC 0x0c085078 */
if(!s->budget--) { s->failed_pc=0x0c085078u; return 0; }
tmp=read(ram,r[0],4);
r[12]=tmp;
goto P_0c08507a;
P_0c08507a: /* original 1fe8, guest PC 0x0c08507a */
if(!s->budget--) { s->failed_pc=0x0c08507au; return 0; }
write(ram,r[15]+32,r[14],4);
goto P_0c08507c;
P_0c08507c: /* original a0ca, guest PC 0x0c08507c */
if(!s->budget--) { s->failed_pc=0x0c08507cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c085214;
P_0c08507e: /* original 1f31, guest PC 0x0c08507e */
if(!s->budget--) { s->failed_pc=0x0c08507eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c085080;
P_0c085080: /* original 9037, guest PC 0x0c085080 */
if(!s->budget--) { s->failed_pc=0x0c085080u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0850f2u,2);
goto P_0c085082;
P_0c085082: /* original e90f, guest PC 0x0c085082 */
if(!s->budget--) { s->failed_pc=0x0c085082u; return 0; }
r[9]=0x0000000fu;
goto P_0c085084;
P_0c085084: /* original 0dcc, guest PC 0x0c085084 */
if(!s->budget--) { s->failed_pc=0x0c085084u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c085086;
P_0c085086: /* original 9035, guest PC 0x0c085086 */
if(!s->budget--) { s->failed_pc=0x0c085086u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0850f4u,2);
goto P_0c085088;
P_0c085088: /* original 6ddc, guest PC 0x0c085088 */
if(!s->budget--) { s->failed_pc=0x0c085088u; return 0; }
r[13]=r[13]&255u;
goto P_0c08508a;
P_0c08508a: /* original 05ce, guest PC 0x0c08508a */
if(!s->budget--) { s->failed_pc=0x0c08508au; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c08508c;
P_0c08508c: /* original 60d3, guest PC 0x0c08508c */
if(!s->budget--) { s->failed_pc=0x0c08508cu; return 0; }
r[0]=r[13];
goto P_0c08508e;
P_0c08508e: /* original 8801, guest PC 0x0c08508e */
if(!s->budget--) { s->failed_pc=0x0c08508eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c085090;
P_0c085090: /* original 8d02, guest PC 0x0c085090 */
if(!s->budget--) { s->failed_pc=0x0c085090u; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(cond) { goto P_0c085098; }
goto P_0c085094;
P_0c085092: /* original ea00, guest PC 0x0c085092 */
if(!s->budget--) { s->failed_pc=0x0c085092u; return 0; }
r[10]=0x00000000u;
goto P_0c085094;
P_0c085094: /* original a081, guest PC 0x0c085094 */
if(!s->budget--) { s->failed_pc=0x0c085094u; return 0; }
goto P_0c08519a;
P_0c085096: /* original 0009, guest PC 0x0c085096 */
if(!s->budget--) { s->failed_pc=0x0c085096u; return 0; }
goto P_0c085098;
P_0c085098: /* original d41c, guest PC 0x0c085098 */
if(!s->budget--) { s->failed_pc=0x0c085098u; return 0; }
r[4]=read(ram,0x0c08510cu,4);
goto P_0c08509a;
P_0c08509a: /* original 2548, guest PC 0x0c08509a */
if(!s->budget--) { s->failed_pc=0x0c08509au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[4])==0)!=0);
goto P_0c08509c;
P_0c08509c: /* original 8b02, guest PC 0x0c08509c */
if(!s->budget--) { s->failed_pc=0x0c08509cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0850a4; }
goto P_0c08509e;
P_0c08509e: /* original 9028, guest PC 0x0c08509e */
if(!s->budget--) { s->failed_pc=0x0c08509eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0850f2u,2);
goto P_0c0850a0;
P_0c0850a0: /* original a07b, guest PC 0x0c0850a0 */
if(!s->budget--) { s->failed_pc=0x0c0850a0u; return 0; }
write(ram,r[12]+r[0],r[10],1);
goto P_0c08519a;
P_0c0850a2: /* original 0ca4, guest PC 0x0c0850a2 */
if(!s->budget--) { s->failed_pc=0x0c0850a2u; return 0; }
write(ram,r[12]+r[0],r[10],1);
goto P_0c0850a4;
P_0c0850a4: /* original 62b1, guest PC 0x0c0850a4 */
if(!s->budget--) { s->failed_pc=0x0c0850a4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[2]=tmp;
goto P_0c0850a6;
P_0c0850a6: /* original e024, guest PC 0x0c0850a6 */
if(!s->budget--) { s->failed_pc=0x0c0850a6u; return 0; }
r[0]=0x00000024u;
goto P_0c0850a8;
P_0c0850a8: /* original 2f21, guest PC 0x0c0850a8 */
if(!s->budget--) { s->failed_pc=0x0c0850a8u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c0850aa;
P_0c0850aa: /* original d319, guest PC 0x0c0850aa */
if(!s->budget--) { s->failed_pc=0x0c0850aau; return 0; }
r[3]=read(ram,0x0c085110u,4);
goto P_0c0850ac;
P_0c0850ac: /* original 430b, guest PC 0x0c0850ac */
if(!s->budget--) { s->failed_pc=0x0c0850acu; return 0; }
target=r[3];
r[16]=code_base|0x0c0850b0u;
write(ram,r[15]+r[0],r[10],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0850b0u) { target=s->pc; goto dispatch; }
goto P_0c0850b0;
P_0c0850ae: /* original 0fa5, guest PC 0x0c0850ae */
if(!s->budget--) { s->failed_pc=0x0c0850aeu; return 0; }
write(ram,r[15]+r[0],r[10],2);
goto P_0c0850b0;
P_0c0850b0: /* original e403, guest PC 0x0c0850b0 */
if(!s->budget--) { s->failed_pc=0x0c0850b0u; return 0; }
r[4]=0x00000003u;
goto P_0c0850b2;
P_0c0850b2: /* original d518, guest PC 0x0c0850b2 */
if(!s->budget--) { s->failed_pc=0x0c0850b2u; return 0; }
r[5]=read(ram,0x0c085114u,4);
goto P_0c0850b4;
P_0c0850b4: /* original 2409, guest PC 0x0c0850b4 */
if(!s->budget--) { s->failed_pc=0x0c0850b4u; return 0; }
r[4]&=r[0];
goto P_0c0850b6;
P_0c0850b6: /* original 901e, guest PC 0x0c0850b6 */
if(!s->budget--) { s->failed_pc=0x0c0850b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0850f6u,2);
goto P_0c0850b8;
P_0c0850b8: /* original 4d21, guest PC 0x0c0850b8 */
if(!s->budget--) { s->failed_pc=0x0c0850b8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]=(uint32_t)((int32_t)r[13]>>1);
goto P_0c0850ba;
P_0c0850ba: /* original f3c6, guest PC 0x0c0850ba */
if(!s->budget--) { s->failed_pc=0x0c0850bau; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0850bc;
P_0c0850bc: /* original e008, guest PC 0x0c0850bc */
if(!s->budget--) { s->failed_pc=0x0c0850bcu; return 0; }
r[0]=0x00000008u;
goto P_0c0850be;
P_0c0850be: /* original 4d21, guest PC 0x0c0850be */
if(!s->budget--) { s->failed_pc=0x0c0850beu; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]=(uint32_t)((int32_t)r[13]>>1);
goto P_0c0850c0;
P_0c0850c0: /* original ff37, guest PC 0x0c0850c0 */
if(!s->budget--) { s->failed_pc=0x0c0850c0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0850c2;
P_0c0850c2: /* original 24d9, guest PC 0x0c0850c2 */
if(!s->budget--) { s->failed_pc=0x0c0850c2u; return 0; }
r[4]&=r[13];
goto P_0c0850c4;
P_0c0850c4: /* original 9018, guest PC 0x0c0850c4 */
if(!s->budget--) { s->failed_pc=0x0c0850c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0850f8u,2);
goto P_0c0850c6;
P_0c0850c6: /* original 6d43, guest PC 0x0c0850c6 */
if(!s->budget--) { s->failed_pc=0x0c0850c6u; return 0; }
r[13]=r[4];
goto P_0c0850c8;
P_0c0850c8: /* original 4d08, guest PC 0x0c0850c8 */
if(!s->budget--) { s->failed_pc=0x0c0850c8u; return 0; }
r[13]<<=2;
goto P_0c0850ca;
P_0c0850ca: /* original 6343, guest PC 0x0c0850ca */
if(!s->budget--) { s->failed_pc=0x0c0850cau; return 0; }
r[3]=r[4];
goto P_0c0850cc;
P_0c0850cc: /* original f3c6, guest PC 0x0c0850cc */
if(!s->budget--) { s->failed_pc=0x0c0850ccu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0850ce;
P_0c0850ce: /* original 3d3c, guest PC 0x0c0850ce */
if(!s->budget--) { s->failed_pc=0x0c0850ceu; return 0; }
r[13]+=r[3];
goto P_0c0850d0;
P_0c0850d0: /* original 4d08, guest PC 0x0c0850d0 */
if(!s->budget--) { s->failed_pc=0x0c0850d0u; return 0; }
r[13]<<=2;
goto P_0c0850d2;
P_0c0850d2: /* original e00c, guest PC 0x0c0850d2 */
if(!s->budget--) { s->failed_pc=0x0c0850d2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0850d4;
P_0c0850d4: /* original f34d, guest PC 0x0c0850d4 */
if(!s->budget--) { s->failed_pc=0x0c0850d4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0850d6;
P_0c0850d6: /* original 6ddf, guest PC 0x0c0850d6 */
if(!s->budget--) { s->failed_pc=0x0c0850d6u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0850d8;
P_0c0850d8: /* original ff37, guest PC 0x0c0850d8 */
if(!s->budget--) { s->failed_pc=0x0c0850d8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0850da;
P_0c0850da: /* original 63f1, guest PC 0x0c0850da */
if(!s->budget--) { s->failed_pc=0x0c0850dau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0850dc;
P_0c0850dc: /* original 3d5c, guest PC 0x0c0850dc */
if(!s->budget--) { s->failed_pc=0x0c0850dcu; return 0; }
r[13]+=r[5];
goto P_0c0850de;
P_0c0850de: /* original f48d, guest PC 0x0c0850de */
if(!s->budget--) { s->failed_pc=0x0c0850deu; return 0; }
fr[4]=0;
goto P_0c0850e0;
P_0c0850e0: /* original 2338, guest PC 0x0c0850e0 */
if(!s->budget--) { s->failed_pc=0x0c0850e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0850e2;
P_0c0850e2: /* original 8f5a, guest PC 0x0c0850e2 */
if(!s->budget--) { s->failed_pc=0x0c0850e2u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,12,4);
if(!cond) { goto P_0c08519a; }
goto P_0c0850e6;
P_0c0850e4: /* original fc4c, guest PC 0x0c0850e4 */
if(!s->budget--) { s->failed_pc=0x0c0850e4u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0850e6;
P_0c0850e6: /* original 9408, guest PC 0x0c0850e6 */
if(!s->budget--) { s->failed_pc=0x0c0850e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0850fau,2);
goto P_0c0850e8;
P_0c0850e8: /* original 2b41, guest PC 0x0c0850e8 */
if(!s->budget--) { s->failed_pc=0x0c0850e8u; return 0; }
write(ram,r[11],r[4],2);
goto P_0c0850ea;
P_0c0850ea: /* original a053, guest PC 0x0c0850ea */
if(!s->budget--) { s->failed_pc=0x0c0850eau; return 0; }
write(ram,r[15],r[9],4);
goto P_0c085194;
P_0c0850ec: /* original 2f92, guest PC 0x0c0850ec */
if(!s->budget--) { s->failed_pc=0x0c0850ecu; return 0; }
write(ram,r[15],r[9],4);
if(!vf3_matrix_family(0x0c0850eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0850eeu; return 0; } return 1;
P_0c085118: /* original 60d2, guest PC 0x0c085118 */
if(!s->budget--) { s->failed_pc=0x0c085118u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08511a;
P_0c08511a: /* original 81fe, guest PC 0x0c08511a */
if(!s->budget--) { s->failed_pc=0x0c08511au; return 0; }
write(ram,r[15]+28,r[0],2);
goto P_0c08511c;
P_0c08511c: /* original e004, guest PC 0x0c08511c */
if(!s->budget--) { s->failed_pc=0x0c08511cu; return 0; }
r[0]=0x00000004u;
goto P_0c08511e;
P_0c08511e: /* original ffd6, guest PC 0x0c08511e */
if(!s->budget--) { s->failed_pc=0x0c08511eu; return 0; }
vf3_matrix_load(s,ram,15,r[13]+r[0]);
goto P_0c085120;
P_0c085120: /* original e008, guest PC 0x0c085120 */
if(!s->budget--) { s->failed_pc=0x0c085120u; return 0; }
r[0]=0x00000008u;
goto P_0c085122;
P_0c085122: /* original fdd6, guest PC 0x0c085122 */
if(!s->budget--) { s->failed_pc=0x0c085122u; return 0; }
vf3_matrix_load(s,ram,13,r[13]+r[0]);
goto P_0c085124;
P_0c085124: /* original e00c, guest PC 0x0c085124 */
if(!s->budget--) { s->failed_pc=0x0c085124u; return 0; }
r[0]=0x0000000cu;
goto P_0c085126;
P_0c085126: /* original fed6, guest PC 0x0c085126 */
if(!s->budget--) { s->failed_pc=0x0c085126u; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c085128;
P_0c085128: /* original e010, guest PC 0x0c085128 */
if(!s->budget--) { s->failed_pc=0x0c085128u; return 0; }
r[0]=0x00000010u;
goto P_0c08512a;
P_0c08512a: /* original f3d6, guest PC 0x0c08512a */
if(!s->budget--) { s->failed_pc=0x0c08512au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08512c;
P_0c08512c: /* original e010, guest PC 0x0c08512c */
if(!s->budget--) { s->failed_pc=0x0c08512cu; return 0; }
r[0]=0x00000010u;
goto P_0c08512e;
P_0c08512e: /* original fdc0, guest PC 0x0c08512e */
if(!s->budget--) { s->failed_pc=0x0c08512eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[12],r[18],'+');
goto P_0c085130;
P_0c085130: /* original 7d14, guest PC 0x0c085130 */
if(!s->budget--) { s->failed_pc=0x0c085130u; return 0; }
r[13]+=0x00000014u;
goto P_0c085132;
P_0c085132: /* original ff37, guest PC 0x0c085132 */
if(!s->budget--) { s->failed_pc=0x0c085132u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085134;
P_0c085134: /* original c742, guest PC 0x0c085134 */
if(!s->budget--) { s->failed_pc=0x0c085134u; return 0; }
r[0]=code_base|0x00085240u;
goto P_0c085136;
P_0c085136: /* original f408, guest PC 0x0c085136 */
if(!s->budget--) { s->failed_pc=0x0c085136u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c085138;
P_0c085138: /* original e018, guest PC 0x0c085138 */
if(!s->budget--) { s->failed_pc=0x0c085138u; return 0; }
r[0]=0x00000018u;
goto P_0c08513a;
P_0c08513a: /* original f3fc, guest PC 0x0c08513a */
if(!s->budget--) { s->failed_pc=0x0c08513au; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c08513c;
P_0c08513c: /* original f342, guest PC 0x0c08513c */
if(!s->budget--) { s->failed_pc=0x0c08513cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c08513e;
P_0c08513e: /* original ff37, guest PC 0x0c08513e */
if(!s->budget--) { s->failed_pc=0x0c08513eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085140;
P_0c085140: /* original e014, guest PC 0x0c085140 */
if(!s->budget--) { s->failed_pc=0x0c085140u; return 0; }
r[0]=0x00000014u;
goto P_0c085142;
P_0c085142: /* original f2ec, guest PC 0x0c085142 */
if(!s->budget--) { s->failed_pc=0x0c085142u; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c085144;
P_0c085144: /* original f242, guest PC 0x0c085144 */
if(!s->budget--) { s->failed_pc=0x0c085144u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c085146;
P_0c085146: /* original ff27, guest PC 0x0c085146 */
if(!s->budget--) { s->failed_pc=0x0c085146u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c085148;
P_0c085148: /* original e008, guest PC 0x0c085148 */
if(!s->budget--) { s->failed_pc=0x0c085148u; return 0; }
r[0]=0x00000008u;
goto P_0c08514a;
P_0c08514a: /* original f1f6, guest PC 0x0c08514a */
if(!s->budget--) { s->failed_pc=0x0c08514au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08514c;
P_0c08514c: /* original e00c, guest PC 0x0c08514c */
if(!s->budget--) { s->failed_pc=0x0c08514cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08514e;
P_0c08514e: /* original f3f6, guest PC 0x0c08514e */
if(!s->budget--) { s->failed_pc=0x0c08514eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085150;
P_0c085150: /* original ff10, guest PC 0x0c085150 */
if(!s->budget--) { s->failed_pc=0x0c085150u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'+');
goto P_0c085152;
P_0c085152: /* original d33c, guest PC 0x0c085152 */
if(!s->budget--) { s->failed_pc=0x0c085152u; return 0; }
r[3]=read(ram,0x0c085244u,4);
goto P_0c085154;
P_0c085154: /* original fe30, guest PC 0x0c085154 */
if(!s->budget--) { s->failed_pc=0x0c085154u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'+');
goto P_0c085156;
P_0c085156: /* original f5ec, guest PC 0x0c085156 */
if(!s->budget--) { s->failed_pc=0x0c085156u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c085158;
P_0c085158: /* original 430b, guest PC 0x0c085158 */
if(!s->budget--) { s->failed_pc=0x0c085158u; return 0; }
target=r[3];
r[16]=code_base|0x0c08515cu;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08515cu) { target=s->pc; goto dispatch; }
goto P_0c08515c;
P_0c08515a: /* original f4fc, guest PC 0x0c08515a */
if(!s->budget--) { s->failed_pc=0x0c08515au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08515c;
P_0c08515c: /* original e024, guest PC 0x0c08515c */
if(!s->budget--) { s->failed_pc=0x0c08515cu; return 0; }
r[0]=0x00000024u;
goto P_0c08515e;
P_0c08515e: /* original f40c, guest PC 0x0c08515e */
if(!s->budget--) { s->failed_pc=0x0c08515eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c085160;
P_0c085160: /* original 00fd, guest PC 0x0c085160 */
if(!s->budget--) { s->failed_pc=0x0c085160u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c085162;
P_0c085162: /* original fd40, guest PC 0x0c085162 */
if(!s->budget--) { s->failed_pc=0x0c085162u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'+');
goto P_0c085164;
P_0c085164: /* original 81ec, guest PC 0x0c085164 */
if(!s->budget--) { s->failed_pc=0x0c085164u; return 0; }
write(ram,r[14]+24,r[0],2);
goto P_0c085166;
P_0c085166: /* original 85fe, guest PC 0x0c085166 */
if(!s->budget--) { s->failed_pc=0x0c085166u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+28,2);
goto P_0c085168;
P_0c085168: /* original 81ed, guest PC 0x0c085168 */
if(!s->budget--) { s->failed_pc=0x0c085168u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c08516a;
P_0c08516a: /* original e004, guest PC 0x0c08516a */
if(!s->budget--) { s->failed_pc=0x0c08516au; return 0; }
r[0]=0x00000004u;
goto P_0c08516c;
P_0c08516c: /* original fefa, guest PC 0x0c08516c */
if(!s->budget--) { s->failed_pc=0x0c08516cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c08516e;
P_0c08516e: /* original fed7, guest PC 0x0c08516e */
if(!s->budget--) { s->failed_pc=0x0c08516eu; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c085170;
P_0c085170: /* original e008, guest PC 0x0c085170 */
if(!s->budget--) { s->failed_pc=0x0c085170u; return 0; }
r[0]=0x00000008u;
goto P_0c085172;
P_0c085172: /* original fee7, guest PC 0x0c085172 */
if(!s->budget--) { s->failed_pc=0x0c085172u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c085174;
P_0c085174: /* original e018, guest PC 0x0c085174 */
if(!s->budget--) { s->failed_pc=0x0c085174u; return 0; }
r[0]=0x00000018u;
goto P_0c085176;
P_0c085176: /* original f3f6, guest PC 0x0c085176 */
if(!s->budget--) { s->failed_pc=0x0c085176u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085178;
P_0c085178: /* original e00c, guest PC 0x0c085178 */
if(!s->budget--) { s->failed_pc=0x0c085178u; return 0; }
r[0]=0x0000000cu;
goto P_0c08517a;
P_0c08517a: /* original fe37, guest PC 0x0c08517a */
if(!s->budget--) { s->failed_pc=0x0c08517au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08517c;
P_0c08517c: /* original e014, guest PC 0x0c08517c */
if(!s->budget--) { s->failed_pc=0x0c08517cu; return 0; }
r[0]=0x00000014u;
goto P_0c08517e;
P_0c08517e: /* original f3f6, guest PC 0x0c08517e */
if(!s->budget--) { s->failed_pc=0x0c08517eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085180;
P_0c085180: /* original e010, guest PC 0x0c085180 */
if(!s->budget--) { s->failed_pc=0x0c085180u; return 0; }
r[0]=0x00000010u;
goto P_0c085182;
P_0c085182: /* original fe37, guest PC 0x0c085182 */
if(!s->budget--) { s->failed_pc=0x0c085182u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c085184;
P_0c085184: /* original e010, guest PC 0x0c085184 */
if(!s->budget--) { s->failed_pc=0x0c085184u; return 0; }
r[0]=0x00000010u;
goto P_0c085186;
P_0c085186: /* original f3f6, guest PC 0x0c085186 */
if(!s->budget--) { s->failed_pc=0x0c085186u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085188;
P_0c085188: /* original e014, guest PC 0x0c085188 */
if(!s->budget--) { s->failed_pc=0x0c085188u; return 0; }
r[0]=0x00000014u;
goto P_0c08518a;
P_0c08518a: /* original fe37, guest PC 0x0c08518a */
if(!s->budget--) { s->failed_pc=0x0c08518au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08518c;
P_0c08518c: /* original 7e1c, guest PC 0x0c08518c */
if(!s->budget--) { s->failed_pc=0x0c08518cu; return 0; }
r[14]+=0x0000001cu;
goto P_0c08518e;
P_0c08518e: /* original 63f2, guest PC 0x0c08518e */
if(!s->budget--) { s->failed_pc=0x0c08518eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085190;
P_0c085190: /* original 73ff, guest PC 0x0c085190 */
if(!s->budget--) { s->failed_pc=0x0c085190u; return 0; }
r[3]+=0xffffffffu;
goto P_0c085192;
P_0c085192: /* original 2f32, guest PC 0x0c085192 */
if(!s->budget--) { s->failed_pc=0x0c085192u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085194;
P_0c085194: /* original 62f2, guest PC 0x0c085194 */
if(!s->budget--) { s->failed_pc=0x0c085194u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c085196;
P_0c085196: /* original 2228, guest PC 0x0c085196 */
if(!s->budget--) { s->failed_pc=0x0c085196u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c085198;
P_0c085198: /* original 8bbe, guest PC 0x0c085198 */
if(!s->budget--) { s->failed_pc=0x0c085198u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085118; }
goto P_0c08519a;
P_0c08519a: /* original 64b1, guest PC 0x0c08519a */
if(!s->budget--) { s->failed_pc=0x0c08519au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[4]=tmp;
goto P_0c08519c;
P_0c08519c: /* original 644d, guest PC 0x0c08519c */
if(!s->budget--) { s->failed_pc=0x0c08519cu; return 0; }
r[4]=r[4]&65535u;
goto P_0c08519e;
P_0c08519e: /* original 2448, guest PC 0x0c08519e */
if(!s->budget--) { s->failed_pc=0x0c08519eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0851a0;
P_0c0851a0: /* original 892e, guest PC 0x0c0851a0 */
if(!s->budget--) { s->failed_pc=0x0c0851a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085200; }
goto P_0c0851a2;
P_0c0851a2: /* original 54f8, guest PC 0x0c0851a2 */
if(!s->budget--) { s->failed_pc=0x0c0851a2u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c0851a4;
P_0c0851a4: /* original a02a, guest PC 0x0c0851a4 */
if(!s->budget--) { s->failed_pc=0x0c0851a4u; return 0; }
r[6]=r[9];
goto P_0c0851fc;
P_0c0851a6: /* original 6693, guest PC 0x0c0851a6 */
if(!s->budget--) { s->failed_pc=0x0c0851a6u; return 0; }
r[6]=r[9];
goto P_0c0851a8;
P_0c0851a8: /* original 854c, guest PC 0x0c0851a8 */
if(!s->budget--) { s->failed_pc=0x0c0851a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c0851aa;
P_0c0851aa: /* original 6503, guest PC 0x0c0851aa */
if(!s->budget--) { s->failed_pc=0x0c0851aau; return 0; }
r[5]=r[0];
goto P_0c0851ac;
P_0c0851ac: /* original 854d, guest PC 0x0c0851ac */
if(!s->budget--) { s->failed_pc=0x0c0851acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+26,2);
goto P_0c0851ae;
P_0c0851ae: /* original 6703, guest PC 0x0c0851ae */
if(!s->budget--) { s->failed_pc=0x0c0851aeu; return 0; }
r[7]=r[0];
goto P_0c0851b0;
P_0c0851b0: /* original 637f, guest PC 0x0c0851b0 */
if(!s->budget--) { s->failed_pc=0x0c0851b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c0851b2;
P_0c0851b2: /* original 4311, guest PC 0x0c0851b2 */
if(!s->budget--) { s->failed_pc=0x0c0851b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0851b4;
P_0c0851b4: /* original 8b03, guest PC 0x0c0851b4 */
if(!s->budget--) { s->failed_pc=0x0c0851b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0851be; }
goto P_0c0851b6;
P_0c0851b6: /* original 77ff, guest PC 0x0c0851b6 */
if(!s->budget--) { s->failed_pc=0x0c0851b6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0851b8;
P_0c0851b8: /* original 6073, guest PC 0x0c0851b8 */
if(!s->budget--) { s->failed_pc=0x0c0851b8u; return 0; }
r[0]=r[7];
goto P_0c0851ba;
P_0c0851ba: /* original a01d, guest PC 0x0c0851ba */
if(!s->budget--) { s->failed_pc=0x0c0851bau; return 0; }
write(ram,r[4]+26,r[0],2);
goto P_0c0851f8;
P_0c0851bc: /* original 814d, guest PC 0x0c0851bc */
if(!s->budget--) { s->failed_pc=0x0c0851bcu; return 0; }
write(ram,r[4]+26,r[0],2);
goto P_0c0851be;
P_0c0851be: /* original 625f, guest PC 0x0c0851be */
if(!s->budget--) { s->failed_pc=0x0c0851beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0851c0;
P_0c0851c0: /* original e710, guest PC 0x0c0851c0 */
if(!s->budget--) { s->failed_pc=0x0c0851c0u; return 0; }
r[7]=0x00000010u;
goto P_0c0851c2;
P_0c0851c2: /* original 3273, guest PC 0x0c0851c2 */
if(!s->budget--) { s->failed_pc=0x0c0851c2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[7])!=0);
goto P_0c0851c4;
P_0c0851c4: /* original 8918, guest PC 0x0c0851c4 */
if(!s->budget--) { s->failed_pc=0x0c0851c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0851f8; }
goto P_0c0851c6;
P_0c0851c6: /* original 7501, guest PC 0x0c0851c6 */
if(!s->budget--) { s->failed_pc=0x0c0851c6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0851c8;
P_0c0851c8: /* original 6053, guest PC 0x0c0851c8 */
if(!s->budget--) { s->failed_pc=0x0c0851c8u; return 0; }
r[0]=r[5];
goto P_0c0851ca;
P_0c0851ca: /* original 655f, guest PC 0x0c0851ca */
if(!s->budget--) { s->failed_pc=0x0c0851cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0851cc;
P_0c0851cc: /* original 3573, guest PC 0x0c0851cc */
if(!s->budget--) { s->failed_pc=0x0c0851ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[7])!=0);
goto P_0c0851ce;
P_0c0851ce: /* original 8f13, guest PC 0x0c0851ce */
if(!s->budget--) { s->failed_pc=0x0c0851ceu; return 0; }
cond=r[17]&1u;
write(ram,r[4]+24,r[0],2);
if(!cond) { goto P_0c0851f8; }
goto P_0c0851d2;
P_0c0851d0: /* original 814c, guest PC 0x0c0851d0 */
if(!s->budget--) { s->failed_pc=0x0c0851d0u; return 0; }
write(ram,r[4]+24,r[0],2);
goto P_0c0851d2;
P_0c0851d2: /* original 6563, guest PC 0x0c0851d2 */
if(!s->budget--) { s->failed_pc=0x0c0851d2u; return 0; }
r[5]=r[6];
goto P_0c0851d4;
P_0c0851d4: /* original 75ff, guest PC 0x0c0851d4 */
if(!s->budget--) { s->failed_pc=0x0c0851d4u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0851d6;
P_0c0851d6: /* original e31f, guest PC 0x0c0851d6 */
if(!s->budget--) { s->failed_pc=0x0c0851d6u; return 0; }
r[3]=0x0000001fu;
goto P_0c0851d8;
P_0c0851d8: /* original de1b, guest PC 0x0c0851d8 */
if(!s->budget--) { s->failed_pc=0x0c0851d8u; return 0; }
r[14]=read(ram,0x0c085248u,4);
goto P_0c0851da;
P_0c0851da: /* original 3358, guest PC 0x0c0851da */
if(!s->budget--) { s->failed_pc=0x0c0851dau; return 0; }
r[3]-=r[5];
goto P_0c0851dc;
P_0c0851dc: /* original 67b1, guest PC 0x0c0851dc */
if(!s->budget--) { s->failed_pc=0x0c0851dcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[7]=tmp;
goto P_0c0851de;
P_0c0851de: /* original 6533, guest PC 0x0c0851de */
if(!s->budget--) { s->failed_pc=0x0c0851deu; return 0; }
r[5]=r[3];
goto P_0c0851e0;
P_0c0851e0: /* original 655b, guest PC 0x0c0851e0 */
if(!s->budget--) { s->failed_pc=0x0c0851e0u; return 0; }
r[5]=0u-r[5];
goto P_0c0851e2;
P_0c0851e2: /* original 62e3, guest PC 0x0c0851e2 */
if(!s->budget--) { s->failed_pc=0x0c0851e2u; return 0; }
r[2]=r[14];
goto P_0c0851e4;
P_0c0851e4: /* original 425d, guest PC 0x0c0851e4 */
if(!s->budget--) { s->failed_pc=0x0c0851e4u; return 0; }
r[2]=(r[5]&0x80000000u)?((r[5]&31u)?r[2]>>((-r[5])&31u):0):r[2]<<(r[5]&31u);
goto P_0c0851e6;
P_0c0851e6: /* original 6227, guest PC 0x0c0851e6 */
if(!s->budget--) { s->failed_pc=0x0c0851e6u; return 0; }
r[2]=~r[2];
goto P_0c0851e8;
P_0c0851e8: /* original 6523, guest PC 0x0c0851e8 */
if(!s->budget--) { s->failed_pc=0x0c0851e8u; return 0; }
r[5]=r[2];
goto P_0c0851ea;
P_0c0851ea: /* original 677d, guest PC 0x0c0851ea */
if(!s->budget--) { s->failed_pc=0x0c0851eau; return 0; }
r[7]=r[7]&65535u;
goto P_0c0851ec;
P_0c0851ec: /* original 2579, guest PC 0x0c0851ec */
if(!s->budget--) { s->failed_pc=0x0c0851ecu; return 0; }
r[5]&=r[7];
goto P_0c0851ee;
P_0c0851ee: /* original 2558, guest PC 0x0c0851ee */
if(!s->budget--) { s->failed_pc=0x0c0851eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0851f0;
P_0c0851f0: /* original 8f02, guest PC 0x0c0851f0 */
if(!s->budget--) { s->failed_pc=0x0c0851f0u; return 0; }
cond=r[17]&1u;
write(ram,r[11],r[5],2);
if(!cond) { goto P_0c0851f8; }
goto P_0c0851f4;
P_0c0851f2: /* original 2b51, guest PC 0x0c0851f2 */
if(!s->budget--) { s->failed_pc=0x0c0851f2u; return 0; }
write(ram,r[11],r[5],2);
goto P_0c0851f4;
P_0c0851f4: /* original 9021, guest PC 0x0c0851f4 */
if(!s->budget--) { s->failed_pc=0x0c0851f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08523au,2);
goto P_0c0851f6;
P_0c0851f6: /* original 0ca4, guest PC 0x0c0851f6 */
if(!s->budget--) { s->failed_pc=0x0c0851f6u; return 0; }
write(ram,r[12]+r[0],r[10],1);
goto P_0c0851f8;
P_0c0851f8: /* original 76ff, guest PC 0x0c0851f8 */
if(!s->budget--) { s->failed_pc=0x0c0851f8u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0851fa;
P_0c0851fa: /* original 741c, guest PC 0x0c0851fa */
if(!s->budget--) { s->failed_pc=0x0c0851fau; return 0; }
r[4]+=0x0000001cu;
goto P_0c0851fc;
P_0c0851fc: /* original 2668, guest PC 0x0c0851fc */
if(!s->budget--) { s->failed_pc=0x0c0851fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0851fe;
P_0c0851fe: /* original 8bd3, guest PC 0x0c0851fe */
if(!s->budget--) { s->failed_pc=0x0c0851feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0851a8; }
goto P_0c085200;
P_0c085200: /* original 9e1c, guest PC 0x0c085200 */
if(!s->budget--) { s->failed_pc=0x0c085200u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08523cu,2);
goto P_0c085202;
P_0c085202: /* original 6b83, guest PC 0x0c085202 */
if(!s->budget--) { s->failed_pc=0x0c085202u; return 0; }
r[11]=r[8];
goto P_0c085204;
P_0c085204: /* original 7b02, guest PC 0x0c085204 */
if(!s->budget--) { s->failed_pc=0x0c085204u; return 0; }
r[11]+=0x00000002u;
goto P_0c085206;
P_0c085206: /* original 3e8c, guest PC 0x0c085206 */
if(!s->budget--) { s->failed_pc=0x0c085206u; return 0; }
r[14]+=r[8];
goto P_0c085208;
P_0c085208: /* original 1fe8, guest PC 0x0c085208 */
if(!s->budget--) { s->failed_pc=0x0c085208u; return 0; }
write(ram,r[15]+32,r[14],4);
goto P_0c08520a;
P_0c08520a: /* original d310, guest PC 0x0c08520a */
if(!s->budget--) { s->failed_pc=0x0c08520au; return 0; }
r[3]=read(ram,0x0c08524cu,4);
goto P_0c08520c;
P_0c08520c: /* original 52f1, guest PC 0x0c08520c */
if(!s->budget--) { s->failed_pc=0x0c08520cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08520e;
P_0c08520e: /* original 6c32, guest PC 0x0c08520e */
if(!s->budget--) { s->failed_pc=0x0c08520eu; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c085210;
P_0c085210: /* original 72ff, guest PC 0x0c085210 */
if(!s->budget--) { s->failed_pc=0x0c085210u; return 0; }
r[2]+=0xffffffffu;
goto P_0c085212;
P_0c085212: /* original 1f21, guest PC 0x0c085212 */
if(!s->budget--) { s->failed_pc=0x0c085212u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c085214;
P_0c085214: /* original 53f1, guest PC 0x0c085214 */
if(!s->budget--) { s->failed_pc=0x0c085214u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c085216;
P_0c085216: /* original 2338, guest PC 0x0c085216 */
if(!s->budget--) { s->failed_pc=0x0c085216u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c085218;
P_0c085218: /* original 8901, guest PC 0x0c085218 */
if(!s->budget--) { s->failed_pc=0x0c085218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08521e; }
goto P_0c08521a;
P_0c08521a: /* original af31, guest PC 0x0c08521a */
if(!s->budget--) { s->failed_pc=0x0c08521au; return 0; }
goto P_0c085080;
P_0c08521c: /* original 0009, guest PC 0x0c08521c */
if(!s->budget--) { s->failed_pc=0x0c08521cu; return 0; }
goto P_0c08521e;
P_0c08521e: /* original 7f28, guest PC 0x0c08521e */
if(!s->budget--) { s->failed_pc=0x0c08521eu; return 0; }
r[15]+=0x00000028u;
goto P_0c085220;
P_0c085220: /* original 4f26, guest PC 0x0c085220 */
if(!s->budget--) { s->failed_pc=0x0c085220u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085222;
P_0c085222: /* original fcf9, guest PC 0x0c085222 */
if(!s->budget--) { s->failed_pc=0x0c085222u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085224;
P_0c085224: /* original fdf9, guest PC 0x0c085224 */
if(!s->budget--) { s->failed_pc=0x0c085224u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085226;
P_0c085226: /* original fef9, guest PC 0x0c085226 */
if(!s->budget--) { s->failed_pc=0x0c085226u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085228;
P_0c085228: /* original fff9, guest PC 0x0c085228 */
if(!s->budget--) { s->failed_pc=0x0c085228u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08522a;
P_0c08522a: /* original 68f6, guest PC 0x0c08522a */
if(!s->budget--) { s->failed_pc=0x0c08522au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08522c;
P_0c08522c: /* original 69f6, guest PC 0x0c08522c */
if(!s->budget--) { s->failed_pc=0x0c08522cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08522e;
P_0c08522e: /* original 6af6, guest PC 0x0c08522e */
if(!s->budget--) { s->failed_pc=0x0c08522eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c085230;
P_0c085230: /* original 6bf6, guest PC 0x0c085230 */
if(!s->budget--) { s->failed_pc=0x0c085230u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085232;
P_0c085232: /* original 6cf6, guest PC 0x0c085232 */
if(!s->budget--) { s->failed_pc=0x0c085232u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085234;
P_0c085234: /* original 6df6, guest PC 0x0c085234 */
if(!s->budget--) { s->failed_pc=0x0c085234u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085236;
P_0c085236: /* original 000b, guest PC 0x0c085236 */
if(!s->budget--) { s->failed_pc=0x0c085236u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085238: /* original 6ef6, guest PC 0x0c085238 */
if(!s->budget--) { s->failed_pc=0x0c085238u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08523au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08523au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
