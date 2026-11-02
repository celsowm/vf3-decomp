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
int vf3_away_batch13_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
