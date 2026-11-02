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
int vf3_away_batch68_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c095036u: goto P_0c095036;
case 0x0c095038u: goto P_0c095038;
case 0x0c09503au: goto P_0c09503a;
case 0x0c09503cu: goto P_0c09503c;
case 0x0c09503eu: goto P_0c09503e;
case 0x0c095040u: goto P_0c095040;
case 0x0c095042u: goto P_0c095042;
case 0x0c095044u: goto P_0c095044;
case 0x0c095046u: goto P_0c095046;
case 0x0c095048u: goto P_0c095048;
case 0x0c09504au: goto P_0c09504a;
case 0x0c09504cu: goto P_0c09504c;
case 0x0c09504eu: goto P_0c09504e;
case 0x0c095050u: goto P_0c095050;
case 0x0c095052u: goto P_0c095052;
case 0x0c095054u: goto P_0c095054;
case 0x0c095056u: goto P_0c095056;
case 0x0c095058u: goto P_0c095058;
case 0x0c09505au: goto P_0c09505a;
case 0x0c09505cu: goto P_0c09505c;
case 0x0c09505eu: goto P_0c09505e;
case 0x0c095060u: goto P_0c095060;
case 0x0c095062u: goto P_0c095062;
case 0x0c095064u: goto P_0c095064;
case 0x0c095066u: goto P_0c095066;
case 0x0c095068u: goto P_0c095068;
case 0x0c09506au: goto P_0c09506a;
case 0x0c09506cu: goto P_0c09506c;
case 0x0c09506eu: goto P_0c09506e;
case 0x0c095070u: goto P_0c095070;
case 0x0c095072u: goto P_0c095072;
case 0x0c095074u: goto P_0c095074;
case 0x0c095076u: goto P_0c095076;
case 0x0c095078u: goto P_0c095078;
case 0x0c09507au: goto P_0c09507a;
case 0x0c09507cu: goto P_0c09507c;
case 0x0c09507eu: goto P_0c09507e;
case 0x0c095080u: goto P_0c095080;
case 0x0c095082u: goto P_0c095082;
case 0x0c095084u: goto P_0c095084;
case 0x0c095086u: goto P_0c095086;
case 0x0c095088u: goto P_0c095088;
case 0x0c09508au: goto P_0c09508a;
case 0x0c09508cu: goto P_0c09508c;
case 0x0c09508eu: goto P_0c09508e;
case 0x0c095090u: goto P_0c095090;
case 0x0c095092u: goto P_0c095092;
case 0x0c095094u: goto P_0c095094;
case 0x0c095096u: goto P_0c095096;
case 0x0c095098u: goto P_0c095098;
case 0x0c09509au: goto P_0c09509a;
case 0x0c09509cu: goto P_0c09509c;
case 0x0c09509eu: goto P_0c09509e;
case 0x0c0950a0u: goto P_0c0950a0;
case 0x0c0950a2u: goto P_0c0950a2;
case 0x0c0950a4u: goto P_0c0950a4;
case 0x0c0950a6u: goto P_0c0950a6;
case 0x0c0950a8u: goto P_0c0950a8;
case 0x0c0950aau: goto P_0c0950aa;
case 0x0c0950acu: goto P_0c0950ac;
case 0x0c0950aeu: goto P_0c0950ae;
case 0x0c0950b0u: goto P_0c0950b0;
case 0x0c0950b2u: goto P_0c0950b2;
case 0x0c0950b4u: goto P_0c0950b4;
case 0x0c0950b6u: goto P_0c0950b6;
case 0x0c0950b8u: goto P_0c0950b8;
case 0x0c0950bau: goto P_0c0950ba;
case 0x0c0950bcu: goto P_0c0950bc;
case 0x0c0950beu: goto P_0c0950be;
case 0x0c0950c0u: goto P_0c0950c0;
case 0x0c0950c2u: goto P_0c0950c2;
case 0x0c0950c4u: goto P_0c0950c4;
case 0x0c0950c6u: goto P_0c0950c6;
case 0x0c0950c8u: goto P_0c0950c8;
case 0x0c0950cau: goto P_0c0950ca;
case 0x0c0950ccu: goto P_0c0950cc;
case 0x0c0950ceu: goto P_0c0950ce;
case 0x0c0950d0u: goto P_0c0950d0;
case 0x0c0950d2u: goto P_0c0950d2;
case 0x0c0950d4u: goto P_0c0950d4;
case 0x0c0950d6u: goto P_0c0950d6;
case 0x0c0950d8u: goto P_0c0950d8;
case 0x0c0950dau: goto P_0c0950da;
case 0x0c0950dcu: goto P_0c0950dc;
case 0x0c0950deu: goto P_0c0950de;
case 0x0c0950e0u: goto P_0c0950e0;
case 0x0c0950e2u: goto P_0c0950e2;
case 0x0c0950e4u: goto P_0c0950e4;
case 0x0c0950e6u: goto P_0c0950e6;
case 0x0c0950e8u: goto P_0c0950e8;
case 0x0c0950eau: goto P_0c0950ea;
case 0x0c0950ecu: goto P_0c0950ec;
case 0x0c0950eeu: goto P_0c0950ee;
case 0x0c0950f0u: goto P_0c0950f0;
case 0x0c0950f2u: goto P_0c0950f2;
case 0x0c0950f4u: goto P_0c0950f4;
case 0x0c0950f6u: goto P_0c0950f6;
case 0x0c0950f8u: goto P_0c0950f8;
case 0x0c0950fau: goto P_0c0950fa;
case 0x0c0950fcu: goto P_0c0950fc;
case 0x0c0950feu: goto P_0c0950fe;
case 0x0c095100u: goto P_0c095100;
case 0x0c095102u: goto P_0c095102;
case 0x0c095104u: goto P_0c095104;
case 0x0c095106u: goto P_0c095106;
case 0x0c095108u: goto P_0c095108;
case 0x0c09510au: goto P_0c09510a;
case 0x0c09510cu: goto P_0c09510c;
case 0x0c09510eu: goto P_0c09510e;
case 0x0c095110u: goto P_0c095110;
case 0x0c095112u: goto P_0c095112;
case 0x0c095114u: goto P_0c095114;
case 0x0c0a7662u: goto P_0c0a7662;
case 0x0c0a7664u: goto P_0c0a7664;
case 0x0c0a7666u: goto P_0c0a7666;
case 0x0c0a7668u: goto P_0c0a7668;
case 0x0c0a766au: goto P_0c0a766a;
case 0x0c0a766cu: goto P_0c0a766c;
case 0x0c0a766eu: goto P_0c0a766e;
case 0x0c0a7670u: goto P_0c0a7670;
case 0x0c0a7672u: goto P_0c0a7672;
case 0x0c0a7674u: goto P_0c0a7674;
case 0x0c0a7676u: goto P_0c0a7676;
case 0x0c0a7678u: goto P_0c0a7678;
case 0x0c0a767au: goto P_0c0a767a;
case 0x0c0a767cu: goto P_0c0a767c;
case 0x0c0a767eu: goto P_0c0a767e;
case 0x0c0a7680u: goto P_0c0a7680;
case 0x0c0a7682u: goto P_0c0a7682;
case 0x0c0a7684u: goto P_0c0a7684;
case 0x0c0a7686u: goto P_0c0a7686;
case 0x0c0a7688u: goto P_0c0a7688;
case 0x0c0a768au: goto P_0c0a768a;
case 0x0c0a768cu: goto P_0c0a768c;
case 0x0c0a768eu: goto P_0c0a768e;
case 0x0c0a7690u: goto P_0c0a7690;
case 0x0c0a7692u: goto P_0c0a7692;
case 0x0c0a7694u: goto P_0c0a7694;
case 0x0c0a7696u: goto P_0c0a7696;
case 0x0c0a7698u: goto P_0c0a7698;
case 0x0c0a769au: goto P_0c0a769a;
case 0x0c0a769cu: goto P_0c0a769c;
case 0x0c0a769eu: goto P_0c0a769e;
case 0x0c0a76a0u: goto P_0c0a76a0;
case 0x0c0a76a2u: goto P_0c0a76a2;
case 0x0c0a76a4u: goto P_0c0a76a4;
case 0x0c0a76a6u: goto P_0c0a76a6;
case 0x0c0a76a8u: goto P_0c0a76a8;
case 0x0c0a76aau: goto P_0c0a76aa;
case 0x0c0a76acu: goto P_0c0a76ac;
case 0x0c0a76aeu: goto P_0c0a76ae;
case 0x0c0a76b0u: goto P_0c0a76b0;
case 0x0c0a76b2u: goto P_0c0a76b2;
case 0x0c0a76b4u: goto P_0c0a76b4;
case 0x0c0a76b6u: goto P_0c0a76b6;
case 0x0c0a76b8u: goto P_0c0a76b8;
case 0x0c0a76bau: goto P_0c0a76ba;
case 0x0c0a76bcu: goto P_0c0a76bc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c095036: /* original 2fe6, guest PC 0x0c095036 */
if(!s->budget--) { s->failed_pc=0x0c095036u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c095038;
P_0c095038: /* original 6e43, guest PC 0x0c095038 */
if(!s->budget--) { s->failed_pc=0x0c095038u; return 0; }
r[14]=r[4];
goto P_0c09503a;
P_0c09503a: /* original e301, guest PC 0x0c09503a */
if(!s->budget--) { s->failed_pc=0x0c09503au; return 0; }
r[3]=0x00000001u;
goto P_0c09503c;
P_0c09503c: /* original 2fd6, guest PC 0x0c09503c */
if(!s->budget--) { s->failed_pc=0x0c09503cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09503e;
P_0c09503e: /* original 906b, guest PC 0x0c09503e */
if(!s->budget--) { s->failed_pc=0x0c09503eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095118u,2);
goto P_0c095040;
P_0c095040: /* original 4f22, guest PC 0x0c095040 */
if(!s->budget--) { s->failed_pc=0x0c095040u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095042;
P_0c095042: /* original 0e36, guest PC 0x0c095042 */
if(!s->budget--) { s->failed_pc=0x0c095042u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c095044;
P_0c095044: /* original e024, guest PC 0x0c095044 */
if(!s->budget--) { s->failed_pc=0x0c095044u; return 0; }
r[0]=0x00000024u;
goto P_0c095046;
P_0c095046: /* original 54e4, guest PC 0x0c095046 */
if(!s->budget--) { s->failed_pc=0x0c095046u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c095048;
P_0c095048: /* original 6342, guest PC 0x0c095048 */
if(!s->budget--) { s->failed_pc=0x0c095048u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09504a;
P_0c09504a: /* original 0e35, guest PC 0x0c09504a */
if(!s->budget--) { s->failed_pc=0x0c09504au; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c09504c;
P_0c09504c: /* original 63e3, guest PC 0x0c09504c */
if(!s->budget--) { s->failed_pc=0x0c09504cu; return 0; }
r[3]=r[14];
goto P_0c09504e;
P_0c09504e: /* original 5241, guest PC 0x0c09504e */
if(!s->budget--) { s->failed_pc=0x0c09504eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c095050;
P_0c095050: /* original 7348, guest PC 0x0c095050 */
if(!s->budget--) { s->failed_pc=0x0c095050u; return 0; }
r[3]+=0x00000048u;
goto P_0c095052;
P_0c095052: /* original 1e2d, guest PC 0x0c095052 */
if(!s->budget--) { s->failed_pc=0x0c095052u; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c095054;
P_0c095054: /* original 5242, guest PC 0x0c095054 */
if(!s->budget--) { s->failed_pc=0x0c095054u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c095056;
P_0c095056: /* original 2321, guest PC 0x0c095056 */
if(!s->budget--) { s->failed_pc=0x0c095056u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c095058;
P_0c095058: /* original 905f, guest PC 0x0c095058 */
if(!s->budget--) { s->failed_pc=0x0c095058u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09511au,2);
goto P_0c09505a;
P_0c09505a: /* original 5244, guest PC 0x0c09505a */
if(!s->budget--) { s->failed_pc=0x0c09505au; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c09505c;
P_0c09505c: /* original 035c, guest PC 0x0c09505c */
if(!s->budget--) { s->failed_pc=0x0c09505cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c09505e;
P_0c09505e: /* original e500, guest PC 0x0c09505e */
if(!s->budget--) { s->failed_pc=0x0c09505eu; return 0; }
r[5]=0x00000000u;
goto P_0c095060;
P_0c095060: /* original 905c, guest PC 0x0c095060 */
if(!s->budget--) { s->failed_pc=0x0c095060u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09511cu,2);
goto P_0c095062;
P_0c095062: /* original 633c, guest PC 0x0c095062 */
if(!s->budget--) { s->failed_pc=0x0c095062u; return 0; }
r[3]=r[3]&255u;
goto P_0c095064;
P_0c095064: /* original 4308, guest PC 0x0c095064 */
if(!s->budget--) { s->failed_pc=0x0c095064u; return 0; }
r[3]<<=2;
goto P_0c095066;
P_0c095066: /* original 332c, guest PC 0x0c095066 */
if(!s->budget--) { s->failed_pc=0x0c095066u; return 0; }
r[3]+=r[2];
goto P_0c095068;
P_0c095068: /* original 0e36, guest PC 0x0c095068 */
if(!s->budget--) { s->failed_pc=0x0c095068u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09506a;
P_0c09506a: /* original 04ee, guest PC 0x0c09506a */
if(!s->budget--) { s->failed_pc=0x0c09506au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09506c;
P_0c09506c: /* original 70e8, guest PC 0x0c09506c */
if(!s->budget--) { s->failed_pc=0x0c09506cu; return 0; }
r[0]+=0xffffffe8u;
goto P_0c09506e;
P_0c09506e: /* original 6442, guest PC 0x0c09506e */
if(!s->budget--) { s->failed_pc=0x0c09506eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c095070;
P_0c095070: /* original 0e46, guest PC 0x0c095070 */
if(!s->budget--) { s->failed_pc=0x0c095070u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c095072;
P_0c095072: /* original e042, guest PC 0x0c095072 */
if(!s->budget--) { s->failed_pc=0x0c095072u; return 0; }
r[0]=0x00000042u;
goto P_0c095074;
P_0c095074: /* original 1e5f, guest PC 0x0c095074 */
if(!s->budget--) { s->failed_pc=0x0c095074u; return 0; }
write(ram,r[14]+60,r[5],4);
goto P_0c095076;
P_0c095076: /* original 0e55, guest PC 0x0c095076 */
if(!s->budget--) { s->failed_pc=0x0c095076u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c095078;
P_0c095078: /* original 7056, guest PC 0x0c095078 */
if(!s->budget--) { s->failed_pc=0x0c095078u; return 0; }
r[0]+=0x00000056u;
goto P_0c09507a;
P_0c09507a: /* original 1e5e, guest PC 0x0c09507a */
if(!s->budget--) { s->failed_pc=0x0c09507au; return 0; }
write(ram,r[14]+56,r[5],4);
goto P_0c09507c;
P_0c09507c: /* original 0e55, guest PC 0x0c09507c */
if(!s->budget--) { s->failed_pc=0x0c09507cu; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c09507e;
P_0c09507e: /* original 70f0, guest PC 0x0c09507e */
if(!s->budget--) { s->failed_pc=0x0c09507eu; return 0; }
r[0]+=0xfffffff0u;
goto P_0c095080;
P_0c095080: /* original 0e54, guest PC 0x0c095080 */
if(!s->budget--) { s->failed_pc=0x0c095080u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c095082;
P_0c095082: /* original 8441, guest PC 0x0c095082 */
if(!s->budget--) { s->failed_pc=0x0c095082u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c095084;
P_0c095084: /* original 6540, guest PC 0x0c095084 */
if(!s->budget--) { s->failed_pc=0x0c095084u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[5]=tmp;
goto P_0c095086;
P_0c095086: /* original 670c, guest PC 0x0c095086 */
if(!s->budget--) { s->failed_pc=0x0c095086u; return 0; }
r[7]=r[0]&255u;
goto P_0c095088;
P_0c095088: /* original 8541, guest PC 0x0c095088 */
if(!s->budget--) { s->failed_pc=0x0c095088u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c09508a;
P_0c09508a: /* original 6d5c, guest PC 0x0c09508a */
if(!s->budget--) { s->failed_pc=0x0c09508au; return 0; }
r[13]=r[5]&255u;
goto P_0c09508c;
P_0c09508c: /* original 6303, guest PC 0x0c09508c */
if(!s->budget--) { s->failed_pc=0x0c09508cu; return 0; }
r[3]=r[0];
goto P_0c09508e;
P_0c09508e: /* original 9046, guest PC 0x0c09508e */
if(!s->budget--) { s->failed_pc=0x0c09508eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09511eu,2);
goto P_0c095090;
P_0c095090: /* original 0e34, guest PC 0x0c095090 */
if(!s->budget--) { s->failed_pc=0x0c095090u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c095092;
P_0c095092: /* original 7003, guest PC 0x0c095092 */
if(!s->budget--) { s->failed_pc=0x0c095092u; return 0; }
r[0]+=0x00000003u;
goto P_0c095094;
P_0c095094: /* original 475a, guest PC 0x0c095094 */
if(!s->budget--) { s->failed_pc=0x0c095094u; return 0; }
r[53]=r[7];
goto P_0c095096;
P_0c095096: /* original 63e3, guest PC 0x0c095096 */
if(!s->budget--) { s->failed_pc=0x0c095096u; return 0; }
r[3]=r[14];
goto P_0c095098;
P_0c095098: /* original 734c, guest PC 0x0c095098 */
if(!s->budget--) { s->failed_pc=0x0c095098u; return 0; }
r[3]+=0x0000004cu;
goto P_0c09509a;
P_0c09509a: /* original f32d, guest PC 0x0c09509a */
if(!s->budget--) { s->failed_pc=0x0c09509au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09509c;
P_0c09509c: /* original f43c, guest PC 0x0c09509c */
if(!s->budget--) { s->failed_pc=0x0c09509cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09509e;
P_0c09509e: /* original f49d, guest PC 0x0c09509e */
if(!s->budget--) { s->failed_pc=0x0c09509eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c0950a0;
P_0c0950a0: /* original f433, guest PC 0x0c0950a0 */
if(!s->budget--) { s->failed_pc=0x0c0950a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0950a2;
P_0c0950a2: /* original fe47, guest PC 0x0c0950a2 */
if(!s->budget--) { s->failed_pc=0x0c0950a2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0950a4;
P_0c0950a4: /* original 7004, guest PC 0x0c0950a4 */
if(!s->budget--) { s->failed_pc=0x0c0950a4u; return 0; }
r[0]+=0x00000004u;
goto P_0c0950a6;
P_0c0950a6: /* original f38d, guest PC 0x0c0950a6 */
if(!s->budget--) { s->failed_pc=0x0c0950a6u; return 0; }
fr[3]=0;
goto P_0c0950a8;
P_0c0950a8: /* original fe37, guest PC 0x0c0950a8 */
if(!s->budget--) { s->failed_pc=0x0c0950a8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0950aa;
P_0c0950aa: /* original e068, guest PC 0x0c0950aa */
if(!s->budget--) { s->failed_pc=0x0c0950aau; return 0; }
r[0]=0x00000068u;
goto P_0c0950ac;
P_0c0950ac: /* original 5261, guest PC 0x0c0950ac */
if(!s->budget--) { s->failed_pc=0x0c0950acu; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c0950ae;
P_0c0950ae: /* original 5121, guest PC 0x0c0950ae */
if(!s->budget--) { s->failed_pc=0x0c0950aeu; return 0; }
r[1]=read(ram,r[2]+4,4);
goto P_0c0950b0;
P_0c0950b0: /* original 2312, guest PC 0x0c0950b0 */
if(!s->budget--) { s->failed_pc=0x0c0950b0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0950b2;
P_0c0950b2: /* original 03ee, guest PC 0x0c0950b2 */
if(!s->budget--) { s->failed_pc=0x0c0950b2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0950b4;
P_0c0950b4: /* original e074, guest PC 0x0c0950b4 */
if(!s->budget--) { s->failed_pc=0x0c0950b4u; return 0; }
r[0]=0x00000074u;
goto P_0c0950b6;
P_0c0950b6: /* original 0e36, guest PC 0x0c0950b6 */
if(!s->budget--) { s->failed_pc=0x0c0950b6u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0950b8;
P_0c0950b8: /* original 4d08, guest PC 0x0c0950b8 */
if(!s->budget--) { s->failed_pc=0x0c0950b8u; return 0; }
r[13]<<=2;
goto P_0c0950ba;
P_0c0950ba: /* original 85ef, guest PC 0x0c0950ba */
if(!s->budget--) { s->failed_pc=0x0c0950bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0950bc;
P_0c0950bc: /* original 9130, guest PC 0x0c0950bc */
if(!s->budget--) { s->failed_pc=0x0c0950bcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095120u,2);
goto P_0c0950be;
P_0c0950be: /* original 6303, guest PC 0x0c0950be */
if(!s->budget--) { s->failed_pc=0x0c0950beu; return 0; }
r[3]=r[0];
goto P_0c0950c0;
P_0c0950c0: /* original 4000, guest PC 0x0c0950c0 */
if(!s->budget--) { s->failed_pc=0x0c0950c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0950c2;
P_0c0950c2: /* original 303c, guest PC 0x0c0950c2 */
if(!s->budget--) { s->failed_pc=0x0c0950c2u; return 0; }
r[0]+=r[3];
goto P_0c0950c4;
P_0c0950c4: /* original 63e3, guest PC 0x0c0950c4 */
if(!s->budget--) { s->failed_pc=0x0c0950c4u; return 0; }
r[3]=r[14];
goto P_0c0950c6;
P_0c0950c6: /* original 734c, guest PC 0x0c0950c6 */
if(!s->budget--) { s->failed_pc=0x0c0950c6u; return 0; }
r[3]+=0x0000004cu;
goto P_0c0950c8;
P_0c0950c8: /* original 4008, guest PC 0x0c0950c8 */
if(!s->budget--) { s->failed_pc=0x0c0950c8u; return 0; }
r[0]<<=2;
goto P_0c0950ca;
P_0c0950ca: /* original 33dc, guest PC 0x0c0950ca */
if(!s->budget--) { s->failed_pc=0x0c0950cau; return 0; }
r[3]+=r[13];
goto P_0c0950cc;
P_0c0950cc: /* original 4000, guest PC 0x0c0950cc */
if(!s->budget--) { s->failed_pc=0x0c0950ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0950ce;
P_0c0950ce: /* original 31ec, guest PC 0x0c0950ce */
if(!s->budget--) { s->failed_pc=0x0c0950ceu; return 0; }
r[1]+=r[14];
goto P_0c0950d0;
P_0c0950d0: /* original 2102, guest PC 0x0c0950d0 */
if(!s->budget--) { s->failed_pc=0x0c0950d0u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0950d2;
P_0c0950d2: /* original e07c, guest PC 0x0c0950d2 */
if(!s->budget--) { s->failed_pc=0x0c0950d2u; return 0; }
r[0]=0x0000007cu;
goto P_0c0950d4;
P_0c0950d4: /* original 6232, guest PC 0x0c0950d4 */
if(!s->budget--) { s->failed_pc=0x0c0950d4u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0950d6;
P_0c0950d6: /* original 63e3, guest PC 0x0c0950d6 */
if(!s->budget--) { s->failed_pc=0x0c0950d6u; return 0; }
r[3]=r[14];
goto P_0c0950d8;
P_0c0950d8: /* original 734c, guest PC 0x0c0950d8 */
if(!s->budget--) { s->failed_pc=0x0c0950d8u; return 0; }
r[3]+=0x0000004cu;
goto P_0c0950da;
P_0c0950da: /* original 0e26, guest PC 0x0c0950da */
if(!s->budget--) { s->failed_pc=0x0c0950dau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0950dc;
P_0c0950dc: /* original e078, guest PC 0x0c0950dc */
if(!s->budget--) { s->failed_pc=0x0c0950dcu; return 0; }
r[0]=0x00000078u;
goto P_0c0950de;
P_0c0950de: /* original 6232, guest PC 0x0c0950de */
if(!s->budget--) { s->failed_pc=0x0c0950deu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0950e0;
P_0c0950e0: /* original 0e26, guest PC 0x0c0950e0 */
if(!s->budget--) { s->failed_pc=0x0c0950e0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0950e2;
P_0c0950e2: /* original 85ef, guest PC 0x0c0950e2 */
if(!s->budget--) { s->failed_pc=0x0c0950e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0950e4;
P_0c0950e4: /* original 6703, guest PC 0x0c0950e4 */
if(!s->budget--) { s->failed_pc=0x0c0950e4u; return 0; }
r[7]=r[0];
goto P_0c0950e6;
P_0c0950e6: /* original e074, guest PC 0x0c0950e6 */
if(!s->budget--) { s->failed_pc=0x0c0950e6u; return 0; }
r[0]=0x00000074u;
goto P_0c0950e8;
P_0c0950e8: /* original 06ee, guest PC 0x0c0950e8 */
if(!s->budget--) { s->failed_pc=0x0c0950e8u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0950ea;
P_0c0950ea: /* original e078, guest PC 0x0c0950ea */
if(!s->budget--) { s->failed_pc=0x0c0950eau; return 0; }
r[0]=0x00000078u;
goto P_0c0950ec;
P_0c0950ec: /* original 05ee, guest PC 0x0c0950ec */
if(!s->budget--) { s->failed_pc=0x0c0950ecu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0950ee;
P_0c0950ee: /* original bc25, guest PC 0x0c0950ee */
if(!s->budget--) { s->failed_pc=0x0c0950eeu; return 0; }
target=code_base|0x0c09493cu; r[16]=code_base|0x0c0950f2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0950f2u) { target=s->pc; goto dispatch; }
goto P_0c0950f2;
P_0c0950f0: /* original 64e3, guest PC 0x0c0950f0 */
if(!s->budget--) { s->failed_pc=0x0c0950f0u; return 0; }
r[4]=r[14];
goto P_0c0950f2;
P_0c0950f2: /* original 62e3, guest PC 0x0c0950f2 */
if(!s->budget--) { s->failed_pc=0x0c0950f2u; return 0; }
r[2]=r[14];
goto P_0c0950f4;
P_0c0950f4: /* original 724c, guest PC 0x0c0950f4 */
if(!s->budget--) { s->failed_pc=0x0c0950f4u; return 0; }
r[2]+=0x0000004cu;
goto P_0c0950f6;
P_0c0950f6: /* original 32dc, guest PC 0x0c0950f6 */
if(!s->budget--) { s->failed_pc=0x0c0950f6u; return 0; }
r[2]+=r[13];
goto P_0c0950f8;
P_0c0950f8: /* original 6322, guest PC 0x0c0950f8 */
if(!s->budget--) { s->failed_pc=0x0c0950f8u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0950fa;
P_0c0950fa: /* original 62e3, guest PC 0x0c0950fa */
if(!s->budget--) { s->failed_pc=0x0c0950fau; return 0; }
r[2]=r[14];
goto P_0c0950fc;
P_0c0950fc: /* original 724c, guest PC 0x0c0950fc */
if(!s->budget--) { s->failed_pc=0x0c0950fcu; return 0; }
r[2]+=0x0000004cu;
goto P_0c0950fe;
P_0c0950fe: /* original 4f26, guest PC 0x0c0950fe */
if(!s->budget--) { s->failed_pc=0x0c0950feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c095100;
P_0c095100: /* original e070, guest PC 0x0c095100 */
if(!s->budget--) { s->failed_pc=0x0c095100u; return 0; }
r[0]=0x00000070u;
goto P_0c095102;
P_0c095102: /* original 3d2c, guest PC 0x0c095102 */
if(!s->budget--) { s->failed_pc=0x0c095102u; return 0; }
r[13]+=r[2];
goto P_0c095104;
P_0c095104: /* original 0e36, guest PC 0x0c095104 */
if(!s->budget--) { s->failed_pc=0x0c095104u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c095106;
P_0c095106: /* original 63d2, guest PC 0x0c095106 */
if(!s->budget--) { s->failed_pc=0x0c095106u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c095108;
P_0c095108: /* original e06c, guest PC 0x0c095108 */
if(!s->budget--) { s->failed_pc=0x0c095108u; return 0; }
r[0]=0x0000006cu;
goto P_0c09510a;
P_0c09510a: /* original 0e36, guest PC 0x0c09510a */
if(!s->budget--) { s->failed_pc=0x0c09510au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09510c;
P_0c09510c: /* original d20b, guest PC 0x0c09510c */
if(!s->budget--) { s->failed_pc=0x0c09510cu; return 0; }
r[2]=read(ram,0x0c09513cu,4);
goto P_0c09510e;
P_0c09510e: /* original 1e23, guest PC 0x0c09510e */
if(!s->budget--) { s->failed_pc=0x0c09510eu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c095110;
P_0c095110: /* original 6df6, guest PC 0x0c095110 */
if(!s->budget--) { s->failed_pc=0x0c095110u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c095112;
P_0c095112: /* original 000b, guest PC 0x0c095112 */
if(!s->budget--) { s->failed_pc=0x0c095112u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c095114: /* original 6ef6, guest PC 0x0c095114 */
if(!s->budget--) { s->failed_pc=0x0c095114u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c095116u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095116u; return 0; } return 1;
P_0c0a7662: /* original 2fe6, guest PC 0x0c0a7662 */
if(!s->budget--) { s->failed_pc=0x0c0a7662u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7664;
P_0c0a7664: /* original 932b, guest PC 0x0c0a7664 */
if(!s->budget--) { s->failed_pc=0x0c0a7664u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a76beu,2);
goto P_0c0a7666;
P_0c0a7666: /* original 4f22, guest PC 0x0c0a7666 */
if(!s->budget--) { s->failed_pc=0x0c0a7666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7668;
P_0c0a7668: /* original 3433, guest PC 0x0c0a7668 */
if(!s->budget--) { s->failed_pc=0x0c0a7668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a766a;
P_0c0a766a: /* original 8925, guest PC 0x0c0a766a */
if(!s->budget--) { s->failed_pc=0x0c0a766au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a766c;
P_0c0a766c: /* original d014, guest PC 0x0c0a766c */
if(!s->budget--) { s->failed_pc=0x0c0a766cu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a766e;
P_0c0a766e: /* original 6e43, guest PC 0x0c0a766e */
if(!s->budget--) { s->failed_pc=0x0c0a766eu; return 0; }
r[14]=r[4];
goto P_0c0a7670;
P_0c0a7670: /* original 4e08, guest PC 0x0c0a7670 */
if(!s->budget--) { s->failed_pc=0x0c0a7670u; return 0; }
r[14]<<=2;
goto P_0c0a7672;
P_0c0a7672: /* original 0eee, guest PC 0x0c0a7672 */
if(!s->budget--) { s->failed_pc=0x0c0a7672u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7674;
P_0c0a7674: /* original 2ee8, guest PC 0x0c0a7674 */
if(!s->budget--) { s->failed_pc=0x0c0a7674u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7676;
P_0c0a7676: /* original 891f, guest PC 0x0c0a7676 */
if(!s->budget--) { s->failed_pc=0x0c0a7676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a7678;
P_0c0a7678: /* original 60e3, guest PC 0x0c0a7678 */
if(!s->budget--) { s->failed_pc=0x0c0a7678u; return 0; }
r[0]=r[14];
goto P_0c0a767a;
P_0c0a767a: /* original 88ff, guest PC 0x0c0a767a */
if(!s->budget--) { s->failed_pc=0x0c0a767au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a767c;
P_0c0a767c: /* original 891c, guest PC 0x0c0a767c */
if(!s->budget--) { s->failed_pc=0x0c0a767cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a767e;
P_0c0a767e: /* original d311, guest PC 0x0c0a767e */
if(!s->budget--) { s->failed_pc=0x0c0a767eu; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7680;
P_0c0a7680: /* original 430b, guest PC 0x0c0a7680 */
if(!s->budget--) { s->failed_pc=0x0c0a7680u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7684u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7684u) { target=s->pc; goto dispatch; }
goto P_0c0a7684;
P_0c0a7682: /* original e400, guest PC 0x0c0a7682 */
if(!s->budget--) { s->failed_pc=0x0c0a7682u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7684;
P_0c0a7684: /* original d211, guest PC 0x0c0a7684 */
if(!s->budget--) { s->failed_pc=0x0c0a7684u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7686;
P_0c0a7686: /* original d410, guest PC 0x0c0a7686 */
if(!s->budget--) { s->failed_pc=0x0c0a7686u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a7688;
P_0c0a7688: /* original 420b, guest PC 0x0c0a7688 */
if(!s->budget--) { s->failed_pc=0x0c0a7688u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a768cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a768cu) { target=s->pc; goto dispatch; }
goto P_0c0a768c;
P_0c0a768a: /* original 0009, guest PC 0x0c0a768a */
if(!s->budget--) { s->failed_pc=0x0c0a768au; return 0; }
goto P_0c0a768c;
P_0c0a768c: /* original 50e1, guest PC 0x0c0a768c */
if(!s->budget--) { s->failed_pc=0x0c0a768cu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a768e;
P_0c0a768e: /* original c801, guest PC 0x0c0a768e */
if(!s->budget--) { s->failed_pc=0x0c0a768eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7690;
P_0c0a7690: /* original 8904, guest PC 0x0c0a7690 */
if(!s->budget--) { s->failed_pc=0x0c0a7690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a769c; }
goto P_0c0a7692;
P_0c0a7692: /* original d213, guest PC 0x0c0a7692 */
if(!s->budget--) { s->failed_pc=0x0c0a7692u; return 0; }
r[2]=read(ram,0x0c0a76e0u,4);
goto P_0c0a7694;
P_0c0a7694: /* original 420b, guest PC 0x0c0a7694 */
if(!s->budget--) { s->failed_pc=0x0c0a7694u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7698u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7698u) { target=s->pc; goto dispatch; }
goto P_0c0a7698;
P_0c0a7696: /* original 64e3, guest PC 0x0c0a7696 */
if(!s->budget--) { s->failed_pc=0x0c0a7696u; return 0; }
r[4]=r[14];
goto P_0c0a7698;
P_0c0a7698: /* original a009, guest PC 0x0c0a7698 */
if(!s->budget--) { s->failed_pc=0x0c0a7698u; return 0; }
goto P_0c0a76ae;
P_0c0a769a: /* original 0009, guest PC 0x0c0a769a */
if(!s->budget--) { s->failed_pc=0x0c0a769au; return 0; }
goto P_0c0a769c;
P_0c0a769c: /* original d20d, guest PC 0x0c0a769c */
if(!s->budget--) { s->failed_pc=0x0c0a769cu; return 0; }
r[2]=read(ram,0x0c0a76d4u,4);
goto P_0c0a769e;
P_0c0a769e: /* original 420b, guest PC 0x0c0a769e */
if(!s->budget--) { s->failed_pc=0x0c0a769eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a76a2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76a2u) { target=s->pc; goto dispatch; }
goto P_0c0a76a2;
P_0c0a76a0: /* original 0009, guest PC 0x0c0a76a0 */
if(!s->budget--) { s->failed_pc=0x0c0a76a0u; return 0; }
goto P_0c0a76a2;
P_0c0a76a2: /* original d310, guest PC 0x0c0a76a2 */
if(!s->budget--) { s->failed_pc=0x0c0a76a2u; return 0; }
r[3]=read(ram,0x0c0a76e4u,4);
goto P_0c0a76a4;
P_0c0a76a4: /* original 23e8, guest PC 0x0c0a76a4 */
if(!s->budget--) { s->failed_pc=0x0c0a76a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a76a6;
P_0c0a76a6: /* original 8902, guest PC 0x0c0a76a6 */
if(!s->budget--) { s->failed_pc=0x0c0a76a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76ae; }
goto P_0c0a76a8;
P_0c0a76a8: /* original d30f, guest PC 0x0c0a76a8 */
if(!s->budget--) { s->failed_pc=0x0c0a76a8u; return 0; }
r[3]=read(ram,0x0c0a76e8u,4);
goto P_0c0a76aa;
P_0c0a76aa: /* original 430b, guest PC 0x0c0a76aa */
if(!s->budget--) { s->failed_pc=0x0c0a76aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76aeu) { target=s->pc; goto dispatch; }
goto P_0c0a76ae;
P_0c0a76ac: /* original 64e3, guest PC 0x0c0a76ac */
if(!s->budget--) { s->failed_pc=0x0c0a76acu; return 0; }
r[4]=r[14];
goto P_0c0a76ae;
P_0c0a76ae: /* original 4f26, guest PC 0x0c0a76ae */
if(!s->budget--) { s->failed_pc=0x0c0a76aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76b0;
P_0c0a76b0: /* original d30a, guest PC 0x0c0a76b0 */
if(!s->budget--) { s->failed_pc=0x0c0a76b0u; return 0; }
r[3]=read(ram,0x0c0a76dcu,4);
goto P_0c0a76b2;
P_0c0a76b2: /* original e401, guest PC 0x0c0a76b2 */
if(!s->budget--) { s->failed_pc=0x0c0a76b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a76b4;
P_0c0a76b4: /* original 432b, guest PC 0x0c0a76b4 */
if(!s->budget--) { s->failed_pc=0x0c0a76b4u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0a76b6: /* original 6ef6, guest PC 0x0c0a76b6 */
if(!s->budget--) { s->failed_pc=0x0c0a76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a76b8;
P_0c0a76b8: /* original 4f26, guest PC 0x0c0a76b8 */
if(!s->budget--) { s->failed_pc=0x0c0a76b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76ba;
P_0c0a76ba: /* original 000b, guest PC 0x0c0a76ba */
if(!s->budget--) { s->failed_pc=0x0c0a76bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a76bc: /* original 6ef6, guest PC 0x0c0a76bc */
if(!s->budget--) { s->failed_pc=0x0c0a76bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a76beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a76beu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
