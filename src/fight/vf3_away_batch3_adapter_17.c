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
int vf3_away_batch3_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04503cu: goto P_0c04503c;
case 0x0c04503eu: goto P_0c04503e;
case 0x0c045040u: goto P_0c045040;
case 0x0c045042u: goto P_0c045042;
case 0x0c045044u: goto P_0c045044;
case 0x0c045046u: goto P_0c045046;
case 0x0c045048u: goto P_0c045048;
case 0x0c04504au: goto P_0c04504a;
case 0x0c04504cu: goto P_0c04504c;
case 0x0c04504eu: goto P_0c04504e;
case 0x0c045050u: goto P_0c045050;
case 0x0c045052u: goto P_0c045052;
case 0x0c045054u: goto P_0c045054;
case 0x0c045056u: goto P_0c045056;
case 0x0c045058u: goto P_0c045058;
case 0x0c04505au: goto P_0c04505a;
case 0x0c04505cu: goto P_0c04505c;
case 0x0c04505eu: goto P_0c04505e;
case 0x0c045060u: goto P_0c045060;
case 0x0c045062u: goto P_0c045062;
case 0x0c045064u: goto P_0c045064;
case 0x0c045066u: goto P_0c045066;
case 0x0c045068u: goto P_0c045068;
case 0x0c04506au: goto P_0c04506a;
case 0x0c04506cu: goto P_0c04506c;
case 0x0c04506eu: goto P_0c04506e;
case 0x0c045070u: goto P_0c045070;
case 0x0c045072u: goto P_0c045072;
case 0x0c045074u: goto P_0c045074;
case 0x0c045076u: goto P_0c045076;
case 0x0c045078u: goto P_0c045078;
case 0x0c04507au: goto P_0c04507a;
case 0x0c04507cu: goto P_0c04507c;
case 0x0c04507eu: goto P_0c04507e;
case 0x0c045080u: goto P_0c045080;
case 0x0c045082u: goto P_0c045082;
case 0x0c045084u: goto P_0c045084;
case 0x0c045086u: goto P_0c045086;
case 0x0c045088u: goto P_0c045088;
case 0x0c04508au: goto P_0c04508a;
case 0x0c04508cu: goto P_0c04508c;
case 0x0c04508eu: goto P_0c04508e;
case 0x0c045090u: goto P_0c045090;
case 0x0c045092u: goto P_0c045092;
case 0x0c045094u: goto P_0c045094;
case 0x0c045096u: goto P_0c045096;
case 0x0c045098u: goto P_0c045098;
case 0x0c04509au: goto P_0c04509a;
case 0x0c04509cu: goto P_0c04509c;
case 0x0c04509eu: goto P_0c04509e;
case 0x0c0450a0u: goto P_0c0450a0;
case 0x0c0450a2u: goto P_0c0450a2;
case 0x0c0450a4u: goto P_0c0450a4;
case 0x0c0450a6u: goto P_0c0450a6;
case 0x0c0450a8u: goto P_0c0450a8;
case 0x0c0450aau: goto P_0c0450aa;
case 0x0c0450acu: goto P_0c0450ac;
case 0x0c0450aeu: goto P_0c0450ae;
case 0x0c0450b0u: goto P_0c0450b0;
case 0x0c0450b2u: goto P_0c0450b2;
case 0x0c0450b4u: goto P_0c0450b4;
case 0x0c0450b6u: goto P_0c0450b6;
case 0x0c0450b8u: goto P_0c0450b8;
case 0x0c0450bau: goto P_0c0450ba;
case 0x0c0450bcu: goto P_0c0450bc;
case 0x0c0450beu: goto P_0c0450be;
case 0x0c0450c0u: goto P_0c0450c0;
case 0x0c0450c2u: goto P_0c0450c2;
case 0x0c0450c4u: goto P_0c0450c4;
case 0x0c0450c6u: goto P_0c0450c6;
case 0x0c0450c8u: goto P_0c0450c8;
case 0x0c0450cau: goto P_0c0450ca;
case 0x0c0450ccu: goto P_0c0450cc;
case 0x0c0450ceu: goto P_0c0450ce;
case 0x0c0450d0u: goto P_0c0450d0;
case 0x0c0450d2u: goto P_0c0450d2;
case 0x0c0450d4u: goto P_0c0450d4;
case 0x0c0450d6u: goto P_0c0450d6;
case 0x0c0450d8u: goto P_0c0450d8;
case 0x0c0450dau: goto P_0c0450da;
case 0x0c0450dcu: goto P_0c0450dc;
case 0x0c0450deu: goto P_0c0450de;
case 0x0c0450e0u: goto P_0c0450e0;
case 0x0c0450e2u: goto P_0c0450e2;
case 0x0c0450e4u: goto P_0c0450e4;
case 0x0c0450e6u: goto P_0c0450e6;
case 0x0c0450e8u: goto P_0c0450e8;
case 0x0c0450eau: goto P_0c0450ea;
case 0x0c0450ecu: goto P_0c0450ec;
case 0x0c0450eeu: goto P_0c0450ee;
case 0x0c0450f0u: goto P_0c0450f0;
case 0x0c0450f2u: goto P_0c0450f2;
case 0x0c0450f4u: goto P_0c0450f4;
case 0x0c0450f6u: goto P_0c0450f6;
case 0x0c0450f8u: goto P_0c0450f8;
case 0x0c0450fau: goto P_0c0450fa;
case 0x0c0450fcu: goto P_0c0450fc;
case 0x0c0450feu: goto P_0c0450fe;
case 0x0c045100u: goto P_0c045100;
case 0x0c045102u: goto P_0c045102;
case 0x0c045104u: goto P_0c045104;
case 0x0c045106u: goto P_0c045106;
case 0x0c045108u: goto P_0c045108;
case 0x0c04510au: goto P_0c04510a;
case 0x0c04510cu: goto P_0c04510c;
case 0x0c04510eu: goto P_0c04510e;
case 0x0c045110u: goto P_0c045110;
case 0x0c045112u: goto P_0c045112;
case 0x0c045114u: goto P_0c045114;
case 0x0c045116u: goto P_0c045116;
case 0x0c045118u: goto P_0c045118;
case 0x0c04511au: goto P_0c04511a;
case 0x0c04511cu: goto P_0c04511c;
case 0x0c045138u: goto P_0c045138;
case 0x0c04513au: goto P_0c04513a;
case 0x0c04513cu: goto P_0c04513c;
case 0x0c04513eu: goto P_0c04513e;
case 0x0c045140u: goto P_0c045140;
case 0x0c045142u: goto P_0c045142;
case 0x0c045144u: goto P_0c045144;
case 0x0c045146u: goto P_0c045146;
case 0x0c045148u: goto P_0c045148;
case 0x0c04514au: goto P_0c04514a;
case 0x0c04514cu: goto P_0c04514c;
case 0x0c04514eu: goto P_0c04514e;
case 0x0c045150u: goto P_0c045150;
case 0x0c045152u: goto P_0c045152;
case 0x0c045154u: goto P_0c045154;
case 0x0c045156u: goto P_0c045156;
case 0x0c045158u: goto P_0c045158;
case 0x0c04515au: goto P_0c04515a;
case 0x0c04515cu: goto P_0c04515c;
case 0x0c04515eu: goto P_0c04515e;
case 0x0c045160u: goto P_0c045160;
case 0x0c045162u: goto P_0c045162;
case 0x0c045164u: goto P_0c045164;
case 0x0c045166u: goto P_0c045166;
case 0x0c045168u: goto P_0c045168;
case 0x0c04516au: goto P_0c04516a;
case 0x0c04516cu: goto P_0c04516c;
case 0x0c04516eu: goto P_0c04516e;
case 0x0c045170u: goto P_0c045170;
case 0x0c045172u: goto P_0c045172;
case 0x0c045174u: goto P_0c045174;
case 0x0c045176u: goto P_0c045176;
case 0x0c045178u: goto P_0c045178;
case 0x0c04517au: goto P_0c04517a;
case 0x0c04517cu: goto P_0c04517c;
case 0x0c04517eu: goto P_0c04517e;
case 0x0c045180u: goto P_0c045180;
case 0x0c045182u: goto P_0c045182;
case 0x0c045184u: goto P_0c045184;
case 0x0c045186u: goto P_0c045186;
case 0x0c045188u: goto P_0c045188;
case 0x0c04518au: goto P_0c04518a;
case 0x0c04518cu: goto P_0c04518c;
case 0x0c04518eu: goto P_0c04518e;
case 0x0c045190u: goto P_0c045190;
case 0x0c045192u: goto P_0c045192;
case 0x0c045194u: goto P_0c045194;
case 0x0c045196u: goto P_0c045196;
case 0x0c045198u: goto P_0c045198;
case 0x0c04519au: goto P_0c04519a;
case 0x0c04519cu: goto P_0c04519c;
case 0x0c04519eu: goto P_0c04519e;
case 0x0c0451a0u: goto P_0c0451a0;
case 0x0c0451a2u: goto P_0c0451a2;
case 0x0c0451a4u: goto P_0c0451a4;
case 0x0c0451a6u: goto P_0c0451a6;
case 0x0c0451a8u: goto P_0c0451a8;
case 0x0c0451aau: goto P_0c0451aa;
case 0x0c0451acu: goto P_0c0451ac;
case 0x0c0451aeu: goto P_0c0451ae;
case 0x0c0451b0u: goto P_0c0451b0;
case 0x0c0451b2u: goto P_0c0451b2;
case 0x0c0451b4u: goto P_0c0451b4;
case 0x0c0451b6u: goto P_0c0451b6;
case 0x0c0451b8u: goto P_0c0451b8;
case 0x0c0451bau: goto P_0c0451ba;
case 0x0c0451bcu: goto P_0c0451bc;
case 0x0c0451beu: goto P_0c0451be;
case 0x0c0451c0u: goto P_0c0451c0;
case 0x0c0451c2u: goto P_0c0451c2;
case 0x0c0451c4u: goto P_0c0451c4;
case 0x0c0451c6u: goto P_0c0451c6;
case 0x0c0451c8u: goto P_0c0451c8;
case 0x0c0451cau: goto P_0c0451ca;
case 0x0c0451ccu: goto P_0c0451cc;
case 0x0c0451ceu: goto P_0c0451ce;
case 0x0c0451d0u: goto P_0c0451d0;
case 0x0c0451d2u: goto P_0c0451d2;
case 0x0c0451d4u: goto P_0c0451d4;
case 0x0c0451d6u: goto P_0c0451d6;
case 0x0c0451d8u: goto P_0c0451d8;
case 0x0c0451dau: goto P_0c0451da;
case 0x0c0451dcu: goto P_0c0451dc;
case 0x0c0451deu: goto P_0c0451de;
case 0x0c0451e0u: goto P_0c0451e0;
case 0x0c0451e2u: goto P_0c0451e2;
case 0x0c0451e4u: goto P_0c0451e4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04503c: /* original d23c, guest PC 0x0c04503c */
if(!s->budget--) { s->failed_pc=0x0c04503cu; return 0; }
r[2]=read(ram,0x0c045130u,4);
goto P_0c04503e;
P_0c04503e: /* original 4408, guest PC 0x0c04503e */
if(!s->budget--) { s->failed_pc=0x0c04503eu; return 0; }
r[4]<<=2;
goto P_0c045040;
P_0c045040: /* original 4400, guest PC 0x0c045040 */
if(!s->budget--) { s->failed_pc=0x0c045040u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c045042;
P_0c045042: /* original 6322, guest PC 0x0c045042 */
if(!s->budget--) { s->failed_pc=0x0c045042u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c045044;
P_0c045044: /* original 7304, guest PC 0x0c045044 */
if(!s->budget--) { s->failed_pc=0x0c045044u; return 0; }
r[3]+=0x00000004u;
goto P_0c045046;
P_0c045046: /* original 343c, guest PC 0x0c045046 */
if(!s->budget--) { s->failed_pc=0x0c045046u; return 0; }
r[4]+=r[3];
goto P_0c045048;
P_0c045048: /* original 6040, guest PC 0x0c045048 */
if(!s->budget--) { s->failed_pc=0x0c045048u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c04504a;
P_0c04504a: /* original e300, guest PC 0x0c04504a */
if(!s->budget--) { s->failed_pc=0x0c04504au; return 0; }
r[3]=0x00000000u;
goto P_0c04504c;
P_0c04504c: /* original 8041, guest PC 0x0c04504c */
if(!s->budget--) { s->failed_pc=0x0c04504cu; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c04504e;
P_0c04504e: /* original 2430, guest PC 0x0c04504e */
if(!s->budget--) { s->failed_pc=0x0c04504eu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c045050;
P_0c045050: /* original 6540, guest PC 0x0c045050 */
if(!s->budget--) { s->failed_pc=0x0c045050u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[5]=tmp;
goto P_0c045052;
P_0c045052: /* original 8441, guest PC 0x0c045052 */
if(!s->budget--) { s->failed_pc=0x0c045052u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c045054;
P_0c045054: /* original 205a, guest PC 0x0c045054 */
if(!s->budget--) { s->failed_pc=0x0c045054u; return 0; }
r[0]^=r[5];
goto P_0c045056;
P_0c045056: /* original 2059, guest PC 0x0c045056 */
if(!s->budget--) { s->failed_pc=0x0c045056u; return 0; }
r[0]&=r[5];
goto P_0c045058;
P_0c045058: /* original 8042, guest PC 0x0c045058 */
if(!s->budget--) { s->failed_pc=0x0c045058u; return 0; }
write(ram,r[4]+2,r[0],1);
goto P_0c04505a;
P_0c04505a: /* original 6540, guest PC 0x0c04505a */
if(!s->budget--) { s->failed_pc=0x0c04505au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[5]=tmp;
goto P_0c04505c;
P_0c04505c: /* original 6057, guest PC 0x0c04505c */
if(!s->budget--) { s->failed_pc=0x0c04505cu; return 0; }
r[0]=~r[5];
goto P_0c04505e;
P_0c04505e: /* original 6303, guest PC 0x0c04505e */
if(!s->budget--) { s->failed_pc=0x0c04505eu; return 0; }
r[3]=r[0];
goto P_0c045060;
P_0c045060: /* original 8441, guest PC 0x0c045060 */
if(!s->budget--) { s->failed_pc=0x0c045060u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c045062;
P_0c045062: /* original 205a, guest PC 0x0c045062 */
if(!s->budget--) { s->failed_pc=0x0c045062u; return 0; }
r[0]^=r[5];
goto P_0c045064;
P_0c045064: /* original 2039, guest PC 0x0c045064 */
if(!s->budget--) { s->failed_pc=0x0c045064u; return 0; }
r[0]&=r[3];
goto P_0c045066;
P_0c045066: /* original 8043, guest PC 0x0c045066 */
if(!s->budget--) { s->failed_pc=0x0c045066u; return 0; }
write(ram,r[4]+3,r[0],1);
goto P_0c045068;
P_0c045068: /* original 000b, guest PC 0x0c045068 */
if(!s->budget--) { s->failed_pc=0x0c045068u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04506a: /* original e000, guest PC 0x0c04506a */
if(!s->budget--) { s->failed_pc=0x0c04506au; return 0; }
r[0]=0x00000000u;
goto P_0c04506c;
P_0c04506c: /* original d630, guest PC 0x0c04506c */
if(!s->budget--) { s->failed_pc=0x0c04506cu; return 0; }
r[6]=read(ram,0x0c045130u,4);
goto P_0c04506e;
P_0c04506e: /* original 6343, guest PC 0x0c04506e */
if(!s->budget--) { s->failed_pc=0x0c04506eu; return 0; }
r[3]=r[4];
goto P_0c045070;
P_0c045070: /* original 4308, guest PC 0x0c045070 */
if(!s->budget--) { s->failed_pc=0x0c045070u; return 0; }
r[3]<<=2;
goto P_0c045072;
P_0c045072: /* original 9257, guest PC 0x0c045072 */
if(!s->budget--) { s->failed_pc=0x0c045072u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045124u,2);
goto P_0c045074;
P_0c045074: /* original 6562, guest PC 0x0c045074 */
if(!s->budget--) { s->failed_pc=0x0c045074u; return 0; }
tmp=read(ram,r[6],4);
r[5]=tmp;
goto P_0c045076;
P_0c045076: /* original 4300, guest PC 0x0c045076 */
if(!s->budget--) { s->failed_pc=0x0c045076u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c045078;
P_0c045078: /* original 6062, guest PC 0x0c045078 */
if(!s->budget--) { s->failed_pc=0x0c045078u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c04507a;
P_0c04507a: /* original 4408, guest PC 0x0c04507a */
if(!s->budget--) { s->failed_pc=0x0c04507au; return 0; }
r[4]<<=2;
goto P_0c04507c;
P_0c04507c: /* original 7504, guest PC 0x0c04507c */
if(!s->budget--) { s->failed_pc=0x0c04507cu; return 0; }
r[5]+=0x00000004u;
goto P_0c04507e;
P_0c04507e: /* original 353c, guest PC 0x0c04507e */
if(!s->budget--) { s->failed_pc=0x0c04507eu; return 0; }
r[5]+=r[3];
goto P_0c045080;
P_0c045080: /* original 6303, guest PC 0x0c045080 */
if(!s->budget--) { s->failed_pc=0x0c045080u; return 0; }
r[3]=r[0];
goto P_0c045082;
P_0c045082: /* original 323c, guest PC 0x0c045082 */
if(!s->budget--) { s->failed_pc=0x0c045082u; return 0; }
r[2]+=r[3];
goto P_0c045084;
P_0c045084: /* original 6220, guest PC 0x0c045084 */
if(!s->budget--) { s->failed_pc=0x0c045084u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c045086;
P_0c045086: /* original 7ffc, guest PC 0x0c045086 */
if(!s->budget--) { s->failed_pc=0x0c045086u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c045088;
P_0c045088: /* original 622b, guest PC 0x0c045088 */
if(!s->budget--) { s->failed_pc=0x0c045088u; return 0; }
r[2]=0u-r[2];
goto P_0c04508a;
P_0c04508a: /* original 7201, guest PC 0x0c04508a */
if(!s->budget--) { s->failed_pc=0x0c04508au; return 0; }
r[2]+=0x00000001u;
goto P_0c04508c;
P_0c04508c: /* original 6323, guest PC 0x0c04508c */
if(!s->budget--) { s->failed_pc=0x0c04508cu; return 0; }
r[3]=r[2];
goto P_0c04508e;
P_0c04508e: /* original 4200, guest PC 0x0c04508e */
if(!s->budget--) { s->failed_pc=0x0c04508eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c045090;
P_0c045090: /* original 323c, guest PC 0x0c045090 */
if(!s->budget--) { s->failed_pc=0x0c045090u; return 0; }
r[2]+=r[3];
goto P_0c045092;
P_0c045092: /* original 9348, guest PC 0x0c045092 */
if(!s->budget--) { s->failed_pc=0x0c045092u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045126u,2);
goto P_0c045094;
P_0c045094: /* original 4208, guest PC 0x0c045094 */
if(!s->budget--) { s->failed_pc=0x0c045094u; return 0; }
r[2]<<=2;
goto P_0c045096;
P_0c045096: /* original 4208, guest PC 0x0c045096 */
if(!s->budget--) { s->failed_pc=0x0c045096u; return 0; }
r[2]<<=2;
goto P_0c045098;
P_0c045098: /* original 4200, guest PC 0x0c045098 */
if(!s->budget--) { s->failed_pc=0x0c045098u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c04509a;
P_0c04509a: /* original 303c, guest PC 0x0c04509a */
if(!s->budget--) { s->failed_pc=0x0c04509au; return 0; }
r[0]+=r[3];
goto P_0c04509c;
P_0c04509c: /* original 622c, guest PC 0x0c04509c */
if(!s->budget--) { s->failed_pc=0x0c04509cu; return 0; }
r[2]=r[2]&255u;
goto P_0c04509e;
P_0c04509e: /* original 302c, guest PC 0x0c04509e */
if(!s->budget--) { s->failed_pc=0x0c04509eu; return 0; }
r[0]+=r[2];
goto P_0c0450a0;
P_0c0450a0: /* original 6103, guest PC 0x0c0450a0 */
if(!s->budget--) { s->failed_pc=0x0c0450a0u; return 0; }
r[1]=r[0];
goto P_0c0450a2;
P_0c0450a2: /* original d024, guest PC 0x0c0450a2 */
if(!s->budget--) { s->failed_pc=0x0c0450a2u; return 0; }
r[0]=read(ram,0x0c045134u,4);
goto P_0c0450a4;
P_0c0450a4: /* original 024e, guest PC 0x0c0450a4 */
if(!s->budget--) { s->failed_pc=0x0c0450a4u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0450a6;
P_0c0450a6: /* original 4208, guest PC 0x0c0450a6 */
if(!s->budget--) { s->failed_pc=0x0c0450a6u; return 0; }
r[2]<<=2;
goto P_0c0450a8;
P_0c0450a8: /* original 312c, guest PC 0x0c0450a8 */
if(!s->budget--) { s->failed_pc=0x0c0450a8u; return 0; }
r[1]+=r[2];
goto P_0c0450aa;
P_0c0450aa: /* original 6412, guest PC 0x0c0450aa */
if(!s->budget--) { s->failed_pc=0x0c0450aau; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c0450ac;
P_0c0450ac: /* original 6242, guest PC 0x0c0450ac */
if(!s->budget--) { s->failed_pc=0x0c0450acu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0450ae;
P_0c0450ae: /* original 6023, guest PC 0x0c0450ae */
if(!s->budget--) { s->failed_pc=0x0c0450aeu; return 0; }
r[0]=r[2];
goto P_0c0450b0;
P_0c0450b0: /* original 2f22, guest PC 0x0c0450b0 */
if(!s->budget--) { s->failed_pc=0x0c0450b0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0450b2;
P_0c0450b2: /* original 9139, guest PC 0x0c0450b2 */
if(!s->budget--) { s->failed_pc=0x0c0450b2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045128u,2);
goto P_0c0450b4;
P_0c0450b4: /* original 3010, guest PC 0x0c0450b4 */
if(!s->budget--) { s->failed_pc=0x0c0450b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0450b6;
P_0c0450b6: /* original 8d02, guest PC 0x0c0450b6 */
if(!s->budget--) { s->failed_pc=0x0c0450b6u; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c0450be; }
goto P_0c0450ba;
P_0c0450b8: /* original e700, guest PC 0x0c0450b8 */
if(!s->budget--) { s->failed_pc=0x0c0450b8u; return 0; }
r[7]=0x00000000u;
goto P_0c0450ba;
P_0c0450ba: /* original 88ff, guest PC 0x0c0450ba */
if(!s->budget--) { s->failed_pc=0x0c0450bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0450bc;
P_0c0450bc: /* original 8b0e, guest PC 0x0c0450bc */
if(!s->budget--) { s->failed_pc=0x0c0450bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0450dc; }
goto P_0c0450be;
P_0c0450be: /* original 5251, guest PC 0x0c0450be */
if(!s->budget--) { s->failed_pc=0x0c0450beu; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c0450c0;
P_0c0450c0: /* original 7201, guest PC 0x0c0450c0 */
if(!s->budget--) { s->failed_pc=0x0c0450c0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0450c2;
P_0c0450c2: /* original 1521, guest PC 0x0c0450c2 */
if(!s->budget--) { s->failed_pc=0x0c0450c2u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c0450c4;
P_0c0450c4: /* original 6162, guest PC 0x0c0450c4 */
if(!s->budget--) { s->failed_pc=0x0c0450c4u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c0450c6;
P_0c0450c6: /* original 9030, guest PC 0x0c0450c6 */
if(!s->budget--) { s->failed_pc=0x0c0450c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04512au,2);
goto P_0c0450c8;
P_0c0450c8: /* original 021e, guest PC 0x0c0450c8 */
if(!s->budget--) { s->failed_pc=0x0c0450c8u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c0450ca;
P_0c0450ca: /* original 5051, guest PC 0x0c0450ca */
if(!s->budget--) { s->failed_pc=0x0c0450cau; return 0; }
r[0]=read(ram,r[5]+4,4);
goto P_0c0450cc;
P_0c0450cc: /* original 3026, guest PC 0x0c0450cc */
if(!s->budget--) { s->failed_pc=0x0c0450ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[2])!=0);
goto P_0c0450ce;
P_0c0450ce: /* original 8b02, guest PC 0x0c0450ce */
if(!s->budget--) { s->failed_pc=0x0c0450ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0450d6; }
goto P_0c0450d0;
P_0c0450d0: /* original 6673, guest PC 0x0c0450d0 */
if(!s->budget--) { s->failed_pc=0x0c0450d0u; return 0; }
r[6]=r[7];
goto P_0c0450d2;
P_0c0450d2: /* original a010, guest PC 0x0c0450d2 */
if(!s->budget--) { s->failed_pc=0x0c0450d2u; return 0; }
r[4]=0xffffffffu;
goto P_0c0450f6;
P_0c0450d4: /* original e4ff, guest PC 0x0c0450d4 */
if(!s->budget--) { s->failed_pc=0x0c0450d4u; return 0; }
r[4]=0xffffffffu;
goto P_0c0450d6;
P_0c0450d6: /* original e000, guest PC 0x0c0450d6 */
if(!s->budget--) { s->failed_pc=0x0c0450d6u; return 0; }
r[0]=0x00000000u;
goto P_0c0450d8;
P_0c0450d8: /* original 000b, guest PC 0x0c0450d8 */
if(!s->budget--) { s->failed_pc=0x0c0450d8u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c0450da: /* original 7f04, guest PC 0x0c0450da */
if(!s->budget--) { s->failed_pc=0x0c0450dau; return 0; }
r[15]+=0x00000004u;
goto P_0c0450dc;
P_0c0450dc: /* original 9126, guest PC 0x0c0450dc */
if(!s->budget--) { s->failed_pc=0x0c0450dcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04512cu,2);
goto P_0c0450de;
P_0c0450de: /* original 6062, guest PC 0x0c0450de */
if(!s->budget--) { s->failed_pc=0x0c0450deu; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c0450e0;
P_0c0450e0: /* original 001e, guest PC 0x0c0450e0 */
if(!s->budget--) { s->failed_pc=0x0c0450e0u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0450e2;
P_0c0450e2: /* original 8801, guest PC 0x0c0450e2 */
if(!s->budget--) { s->failed_pc=0x0c0450e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0450e4;
P_0c0450e4: /* original 8b02, guest PC 0x0c0450e4 */
if(!s->budget--) { s->failed_pc=0x0c0450e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0450ec; }
goto P_0c0450e6;
P_0c0450e6: /* original 64f3, guest PC 0x0c0450e6 */
if(!s->budget--) { s->failed_pc=0x0c0450e6u; return 0; }
r[4]=r[15];
goto P_0c0450e8;
P_0c0450e8: /* original a002, guest PC 0x0c0450e8 */
if(!s->budget--) { s->failed_pc=0x0c0450e8u; return 0; }
r[4]+=0x00000001u;
goto P_0c0450f0;
P_0c0450ea: /* original 7401, guest PC 0x0c0450ea */
if(!s->budget--) { s->failed_pc=0x0c0450eau; return 0; }
r[4]+=0x00000001u;
goto P_0c0450ec;
P_0c0450ec: /* original 64f3, guest PC 0x0c0450ec */
if(!s->budget--) { s->failed_pc=0x0c0450ecu; return 0; }
r[4]=r[15];
goto P_0c0450ee;
P_0c0450ee: /* original 7402, guest PC 0x0c0450ee */
if(!s->budget--) { s->failed_pc=0x0c0450eeu; return 0; }
r[4]+=0x00000002u;
goto P_0c0450f0;
P_0c0450f0: /* original 6640, guest PC 0x0c0450f0 */
if(!s->budget--) { s->failed_pc=0x0c0450f0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[6]=tmp;
goto P_0c0450f2;
P_0c0450f2: /* original 6473, guest PC 0x0c0450f2 */
if(!s->budget--) { s->failed_pc=0x0c0450f2u; return 0; }
r[4]=r[7];
goto P_0c0450f4;
P_0c0450f4: /* original 1571, guest PC 0x0c0450f4 */
if(!s->budget--) { s->failed_pc=0x0c0450f4u; return 0; }
write(ram,r[5]+4,r[7],4);
goto P_0c0450f6;
P_0c0450f6: /* original 6050, guest PC 0x0c0450f6 */
if(!s->budget--) { s->failed_pc=0x0c0450f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c0450f8;
P_0c0450f8: /* original 8051, guest PC 0x0c0450f8 */
if(!s->budget--) { s->failed_pc=0x0c0450f8u; return 0; }
write(ram,r[5]+1,r[0],1);
goto P_0c0450fa;
P_0c0450fa: /* original 9318, guest PC 0x0c0450fa */
if(!s->budget--) { s->failed_pc=0x0c0450fau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04512eu,2);
goto P_0c0450fc;
P_0c0450fc: /* original 2639, guest PC 0x0c0450fc */
if(!s->budget--) { s->failed_pc=0x0c0450fcu; return 0; }
r[6]&=r[3];
goto P_0c0450fe;
P_0c0450fe: /* original 2560, guest PC 0x0c0450fe */
if(!s->budget--) { s->failed_pc=0x0c0450feu; return 0; }
write(ram,r[5],r[6],1);
goto P_0c045100;
P_0c045100: /* original 8451, guest PC 0x0c045100 */
if(!s->budget--) { s->failed_pc=0x0c045100u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+1,1);
goto P_0c045102;
P_0c045102: /* original 6650, guest PC 0x0c045102 */
if(!s->budget--) { s->failed_pc=0x0c045102u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[6]=tmp;
goto P_0c045104;
P_0c045104: /* original 206a, guest PC 0x0c045104 */
if(!s->budget--) { s->failed_pc=0x0c045104u; return 0; }
r[0]^=r[6];
goto P_0c045106;
P_0c045106: /* original 2069, guest PC 0x0c045106 */
if(!s->budget--) { s->failed_pc=0x0c045106u; return 0; }
r[0]&=r[6];
goto P_0c045108;
P_0c045108: /* original 8052, guest PC 0x0c045108 */
if(!s->budget--) { s->failed_pc=0x0c045108u; return 0; }
write(ram,r[5]+2,r[0],1);
goto P_0c04510a;
P_0c04510a: /* original 6650, guest PC 0x0c04510a */
if(!s->budget--) { s->failed_pc=0x0c04510au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[6]=tmp;
goto P_0c04510c;
P_0c04510c: /* original 6067, guest PC 0x0c04510c */
if(!s->budget--) { s->failed_pc=0x0c04510cu; return 0; }
r[0]=~r[6];
goto P_0c04510e;
P_0c04510e: /* original 6203, guest PC 0x0c04510e */
if(!s->budget--) { s->failed_pc=0x0c04510eu; return 0; }
r[2]=r[0];
goto P_0c045110;
P_0c045110: /* original 8451, guest PC 0x0c045110 */
if(!s->budget--) { s->failed_pc=0x0c045110u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+1,1);
goto P_0c045112;
P_0c045112: /* original 206a, guest PC 0x0c045112 */
if(!s->budget--) { s->failed_pc=0x0c045112u; return 0; }
r[0]^=r[6];
goto P_0c045114;
P_0c045114: /* original 2029, guest PC 0x0c045114 */
if(!s->budget--) { s->failed_pc=0x0c045114u; return 0; }
r[0]&=r[2];
goto P_0c045116;
P_0c045116: /* original 8053, guest PC 0x0c045116 */
if(!s->budget--) { s->failed_pc=0x0c045116u; return 0; }
write(ram,r[5]+3,r[0],1);
goto P_0c045118;
P_0c045118: /* original 6043, guest PC 0x0c045118 */
if(!s->budget--) { s->failed_pc=0x0c045118u; return 0; }
r[0]=r[4];
goto P_0c04511a;
P_0c04511a: /* original 000b, guest PC 0x0c04511a */
if(!s->budget--) { s->failed_pc=0x0c04511au; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c04511c: /* original 7f04, guest PC 0x0c04511c */
if(!s->budget--) { s->failed_pc=0x0c04511cu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c04511eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04511eu; return 0; } return 1;
P_0c045138: /* original d62d, guest PC 0x0c045138 */
if(!s->budget--) { s->failed_pc=0x0c045138u; return 0; }
r[6]=read(ram,0x0c0451f0u,4);
goto P_0c04513a;
P_0c04513a: /* original 6343, guest PC 0x0c04513a */
if(!s->budget--) { s->failed_pc=0x0c04513au; return 0; }
r[3]=r[4];
goto P_0c04513c;
P_0c04513c: /* original 4308, guest PC 0x0c04513c */
if(!s->budget--) { s->failed_pc=0x0c04513cu; return 0; }
r[3]<<=2;
goto P_0c04513e;
P_0c04513e: /* original 9252, guest PC 0x0c04513e */
if(!s->budget--) { s->failed_pc=0x0c04513eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0451e6u,2);
goto P_0c045140;
P_0c045140: /* original 6562, guest PC 0x0c045140 */
if(!s->budget--) { s->failed_pc=0x0c045140u; return 0; }
tmp=read(ram,r[6],4);
r[5]=tmp;
goto P_0c045142;
P_0c045142: /* original 4300, guest PC 0x0c045142 */
if(!s->budget--) { s->failed_pc=0x0c045142u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c045144;
P_0c045144: /* original 6062, guest PC 0x0c045144 */
if(!s->budget--) { s->failed_pc=0x0c045144u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c045146;
P_0c045146: /* original 4408, guest PC 0x0c045146 */
if(!s->budget--) { s->failed_pc=0x0c045146u; return 0; }
r[4]<<=2;
goto P_0c045148;
P_0c045148: /* original 7504, guest PC 0x0c045148 */
if(!s->budget--) { s->failed_pc=0x0c045148u; return 0; }
r[5]+=0x00000004u;
goto P_0c04514a;
P_0c04514a: /* original 353c, guest PC 0x0c04514a */
if(!s->budget--) { s->failed_pc=0x0c04514au; return 0; }
r[5]+=r[3];
goto P_0c04514c;
P_0c04514c: /* original 6303, guest PC 0x0c04514c */
if(!s->budget--) { s->failed_pc=0x0c04514cu; return 0; }
r[3]=r[0];
goto P_0c04514e;
P_0c04514e: /* original 323c, guest PC 0x0c04514e */
if(!s->budget--) { s->failed_pc=0x0c04514eu; return 0; }
r[2]+=r[3];
goto P_0c045150;
P_0c045150: /* original 6220, guest PC 0x0c045150 */
if(!s->budget--) { s->failed_pc=0x0c045150u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c045152;
P_0c045152: /* original 7ffc, guest PC 0x0c045152 */
if(!s->budget--) { s->failed_pc=0x0c045152u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c045154;
P_0c045154: /* original 622b, guest PC 0x0c045154 */
if(!s->budget--) { s->failed_pc=0x0c045154u; return 0; }
r[2]=0u-r[2];
goto P_0c045156;
P_0c045156: /* original 7201, guest PC 0x0c045156 */
if(!s->budget--) { s->failed_pc=0x0c045156u; return 0; }
r[2]+=0x00000001u;
goto P_0c045158;
P_0c045158: /* original 6323, guest PC 0x0c045158 */
if(!s->budget--) { s->failed_pc=0x0c045158u; return 0; }
r[3]=r[2];
goto P_0c04515a;
P_0c04515a: /* original 4200, guest PC 0x0c04515a */
if(!s->budget--) { s->failed_pc=0x0c04515au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c04515c;
P_0c04515c: /* original 323c, guest PC 0x0c04515c */
if(!s->budget--) { s->failed_pc=0x0c04515cu; return 0; }
r[2]+=r[3];
goto P_0c04515e;
P_0c04515e: /* original 9343, guest PC 0x0c04515e */
if(!s->budget--) { s->failed_pc=0x0c04515eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0451e8u,2);
goto P_0c045160;
P_0c045160: /* original 4208, guest PC 0x0c045160 */
if(!s->budget--) { s->failed_pc=0x0c045160u; return 0; }
r[2]<<=2;
goto P_0c045162;
P_0c045162: /* original 4208, guest PC 0x0c045162 */
if(!s->budget--) { s->failed_pc=0x0c045162u; return 0; }
r[2]<<=2;
goto P_0c045164;
P_0c045164: /* original 4200, guest PC 0x0c045164 */
if(!s->budget--) { s->failed_pc=0x0c045164u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c045166;
P_0c045166: /* original 303c, guest PC 0x0c045166 */
if(!s->budget--) { s->failed_pc=0x0c045166u; return 0; }
r[0]+=r[3];
goto P_0c045168;
P_0c045168: /* original 622c, guest PC 0x0c045168 */
if(!s->budget--) { s->failed_pc=0x0c045168u; return 0; }
r[2]=r[2]&255u;
goto P_0c04516a;
P_0c04516a: /* original 302c, guest PC 0x0c04516a */
if(!s->budget--) { s->failed_pc=0x0c04516au; return 0; }
r[0]+=r[2];
goto P_0c04516c;
P_0c04516c: /* original 6103, guest PC 0x0c04516c */
if(!s->budget--) { s->failed_pc=0x0c04516cu; return 0; }
r[1]=r[0];
goto P_0c04516e;
P_0c04516e: /* original d021, guest PC 0x0c04516e */
if(!s->budget--) { s->failed_pc=0x0c04516eu; return 0; }
r[0]=read(ram,0x0c0451f4u,4);
goto P_0c045170;
P_0c045170: /* original 024e, guest PC 0x0c045170 */
if(!s->budget--) { s->failed_pc=0x0c045170u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c045172;
P_0c045172: /* original 4208, guest PC 0x0c045172 */
if(!s->budget--) { s->failed_pc=0x0c045172u; return 0; }
r[2]<<=2;
goto P_0c045174;
P_0c045174: /* original 312c, guest PC 0x0c045174 */
if(!s->budget--) { s->failed_pc=0x0c045174u; return 0; }
r[1]+=r[2];
goto P_0c045176;
P_0c045176: /* original 6412, guest PC 0x0c045176 */
if(!s->budget--) { s->failed_pc=0x0c045176u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c045178;
P_0c045178: /* original 6242, guest PC 0x0c045178 */
if(!s->budget--) { s->failed_pc=0x0c045178u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c04517a;
P_0c04517a: /* original 6023, guest PC 0x0c04517a */
if(!s->budget--) { s->failed_pc=0x0c04517au; return 0; }
r[0]=r[2];
goto P_0c04517c;
P_0c04517c: /* original 2f22, guest PC 0x0c04517c */
if(!s->budget--) { s->failed_pc=0x0c04517cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04517e;
P_0c04517e: /* original 9134, guest PC 0x0c04517e */
if(!s->budget--) { s->failed_pc=0x0c04517eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0451eau,2);
goto P_0c045180;
P_0c045180: /* original 3010, guest PC 0x0c045180 */
if(!s->budget--) { s->failed_pc=0x0c045180u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c045182;
P_0c045182: /* original 8d02, guest PC 0x0c045182 */
if(!s->budget--) { s->failed_pc=0x0c045182u; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c04518a; }
goto P_0c045186;
P_0c045184: /* original e700, guest PC 0x0c045184 */
if(!s->budget--) { s->failed_pc=0x0c045184u; return 0; }
r[7]=0x00000000u;
goto P_0c045186;
P_0c045186: /* original 88ff, guest PC 0x0c045186 */
if(!s->budget--) { s->failed_pc=0x0c045186u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c045188;
P_0c045188: /* original 8b0e, guest PC 0x0c045188 */
if(!s->budget--) { s->failed_pc=0x0c045188u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0451a8; }
goto P_0c04518a;
P_0c04518a: /* original 5251, guest PC 0x0c04518a */
if(!s->budget--) { s->failed_pc=0x0c04518au; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c04518c;
P_0c04518c: /* original 7201, guest PC 0x0c04518c */
if(!s->budget--) { s->failed_pc=0x0c04518cu; return 0; }
r[2]+=0x00000001u;
goto P_0c04518e;
P_0c04518e: /* original 1521, guest PC 0x0c04518e */
if(!s->budget--) { s->failed_pc=0x0c04518eu; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c045190;
P_0c045190: /* original 6162, guest PC 0x0c045190 */
if(!s->budget--) { s->failed_pc=0x0c045190u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c045192;
P_0c045192: /* original 902b, guest PC 0x0c045192 */
if(!s->budget--) { s->failed_pc=0x0c045192u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0451ecu,2);
goto P_0c045194;
P_0c045194: /* original 021e, guest PC 0x0c045194 */
if(!s->budget--) { s->failed_pc=0x0c045194u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c045196;
P_0c045196: /* original 5051, guest PC 0x0c045196 */
if(!s->budget--) { s->failed_pc=0x0c045196u; return 0; }
r[0]=read(ram,r[5]+4,4);
goto P_0c045198;
P_0c045198: /* original 3026, guest PC 0x0c045198 */
if(!s->budget--) { s->failed_pc=0x0c045198u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[2])!=0);
goto P_0c04519a;
P_0c04519a: /* original 8b02, guest PC 0x0c04519a */
if(!s->budget--) { s->failed_pc=0x0c04519au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0451a2; }
goto P_0c04519c;
P_0c04519c: /* original 6673, guest PC 0x0c04519c */
if(!s->budget--) { s->failed_pc=0x0c04519cu; return 0; }
r[6]=r[7];
goto P_0c04519e;
P_0c04519e: /* original a010, guest PC 0x0c04519e */
if(!s->budget--) { s->failed_pc=0x0c04519eu; return 0; }
r[4]=0xffffffffu;
goto P_0c0451c2;
P_0c0451a0: /* original e4ff, guest PC 0x0c0451a0 */
if(!s->budget--) { s->failed_pc=0x0c0451a0u; return 0; }
r[4]=0xffffffffu;
goto P_0c0451a2;
P_0c0451a2: /* original e000, guest PC 0x0c0451a2 */
if(!s->budget--) { s->failed_pc=0x0c0451a2u; return 0; }
r[0]=0x00000000u;
goto P_0c0451a4;
P_0c0451a4: /* original 000b, guest PC 0x0c0451a4 */
if(!s->budget--) { s->failed_pc=0x0c0451a4u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c0451a6: /* original 7f04, guest PC 0x0c0451a6 */
if(!s->budget--) { s->failed_pc=0x0c0451a6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0451a8;
P_0c0451a8: /* original 9121, guest PC 0x0c0451a8 */
if(!s->budget--) { s->failed_pc=0x0c0451a8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0451eeu,2);
goto P_0c0451aa;
P_0c0451aa: /* original 6062, guest PC 0x0c0451aa */
if(!s->budget--) { s->failed_pc=0x0c0451aau; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c0451ac;
P_0c0451ac: /* original 001e, guest PC 0x0c0451ac */
if(!s->budget--) { s->failed_pc=0x0c0451acu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0451ae;
P_0c0451ae: /* original 8801, guest PC 0x0c0451ae */
if(!s->budget--) { s->failed_pc=0x0c0451aeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0451b0;
P_0c0451b0: /* original 8b02, guest PC 0x0c0451b0 */
if(!s->budget--) { s->failed_pc=0x0c0451b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0451b8; }
goto P_0c0451b2;
P_0c0451b2: /* original 64f3, guest PC 0x0c0451b2 */
if(!s->budget--) { s->failed_pc=0x0c0451b2u; return 0; }
r[4]=r[15];
goto P_0c0451b4;
P_0c0451b4: /* original a002, guest PC 0x0c0451b4 */
if(!s->budget--) { s->failed_pc=0x0c0451b4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0451bc;
P_0c0451b6: /* original 7401, guest PC 0x0c0451b6 */
if(!s->budget--) { s->failed_pc=0x0c0451b6u; return 0; }
r[4]+=0x00000001u;
goto P_0c0451b8;
P_0c0451b8: /* original 64f3, guest PC 0x0c0451b8 */
if(!s->budget--) { s->failed_pc=0x0c0451b8u; return 0; }
r[4]=r[15];
goto P_0c0451ba;
P_0c0451ba: /* original 7402, guest PC 0x0c0451ba */
if(!s->budget--) { s->failed_pc=0x0c0451bau; return 0; }
r[4]+=0x00000002u;
goto P_0c0451bc;
P_0c0451bc: /* original 6640, guest PC 0x0c0451bc */
if(!s->budget--) { s->failed_pc=0x0c0451bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[6]=tmp;
goto P_0c0451be;
P_0c0451be: /* original 6473, guest PC 0x0c0451be */
if(!s->budget--) { s->failed_pc=0x0c0451beu; return 0; }
r[4]=r[7];
goto P_0c0451c0;
P_0c0451c0: /* original 1571, guest PC 0x0c0451c0 */
if(!s->budget--) { s->failed_pc=0x0c0451c0u; return 0; }
write(ram,r[5]+4,r[7],4);
goto P_0c0451c2;
P_0c0451c2: /* original 6050, guest PC 0x0c0451c2 */
if(!s->budget--) { s->failed_pc=0x0c0451c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c0451c4;
P_0c0451c4: /* original 8051, guest PC 0x0c0451c4 */
if(!s->budget--) { s->failed_pc=0x0c0451c4u; return 0; }
write(ram,r[5]+1,r[0],1);
goto P_0c0451c6;
P_0c0451c6: /* original 2560, guest PC 0x0c0451c6 */
if(!s->budget--) { s->failed_pc=0x0c0451c6u; return 0; }
write(ram,r[5],r[6],1);
goto P_0c0451c8;
P_0c0451c8: /* original 8451, guest PC 0x0c0451c8 */
if(!s->budget--) { s->failed_pc=0x0c0451c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+1,1);
goto P_0c0451ca;
P_0c0451ca: /* original 6650, guest PC 0x0c0451ca */
if(!s->budget--) { s->failed_pc=0x0c0451cau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[6]=tmp;
goto P_0c0451cc;
P_0c0451cc: /* original 206a, guest PC 0x0c0451cc */
if(!s->budget--) { s->failed_pc=0x0c0451ccu; return 0; }
r[0]^=r[6];
goto P_0c0451ce;
P_0c0451ce: /* original 2069, guest PC 0x0c0451ce */
if(!s->budget--) { s->failed_pc=0x0c0451ceu; return 0; }
r[0]&=r[6];
goto P_0c0451d0;
P_0c0451d0: /* original 8052, guest PC 0x0c0451d0 */
if(!s->budget--) { s->failed_pc=0x0c0451d0u; return 0; }
write(ram,r[5]+2,r[0],1);
goto P_0c0451d2;
P_0c0451d2: /* original 6650, guest PC 0x0c0451d2 */
if(!s->budget--) { s->failed_pc=0x0c0451d2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[6]=tmp;
goto P_0c0451d4;
P_0c0451d4: /* original 6067, guest PC 0x0c0451d4 */
if(!s->budget--) { s->failed_pc=0x0c0451d4u; return 0; }
r[0]=~r[6];
goto P_0c0451d6;
P_0c0451d6: /* original 6303, guest PC 0x0c0451d6 */
if(!s->budget--) { s->failed_pc=0x0c0451d6u; return 0; }
r[3]=r[0];
goto P_0c0451d8;
P_0c0451d8: /* original 8451, guest PC 0x0c0451d8 */
if(!s->budget--) { s->failed_pc=0x0c0451d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+1,1);
goto P_0c0451da;
P_0c0451da: /* original 206a, guest PC 0x0c0451da */
if(!s->budget--) { s->failed_pc=0x0c0451dau; return 0; }
r[0]^=r[6];
goto P_0c0451dc;
P_0c0451dc: /* original 2039, guest PC 0x0c0451dc */
if(!s->budget--) { s->failed_pc=0x0c0451dcu; return 0; }
r[0]&=r[3];
goto P_0c0451de;
P_0c0451de: /* original 8053, guest PC 0x0c0451de */
if(!s->budget--) { s->failed_pc=0x0c0451deu; return 0; }
write(ram,r[5]+3,r[0],1);
goto P_0c0451e0;
P_0c0451e0: /* original 6043, guest PC 0x0c0451e0 */
if(!s->budget--) { s->failed_pc=0x0c0451e0u; return 0; }
r[0]=r[4];
goto P_0c0451e2;
P_0c0451e2: /* original 000b, guest PC 0x0c0451e2 */
if(!s->budget--) { s->failed_pc=0x0c0451e2u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c0451e4: /* original 7f04, guest PC 0x0c0451e4 */
if(!s->budget--) { s->failed_pc=0x0c0451e4u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0451e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0451e6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
