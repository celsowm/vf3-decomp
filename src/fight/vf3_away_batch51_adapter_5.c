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
int vf3_away_batch51_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c085250u: goto P_0c085250;
case 0x0c085252u: goto P_0c085252;
case 0x0c085254u: goto P_0c085254;
case 0x0c085256u: goto P_0c085256;
case 0x0c085258u: goto P_0c085258;
case 0x0c08525au: goto P_0c08525a;
case 0x0c08525cu: goto P_0c08525c;
case 0x0c08525eu: goto P_0c08525e;
case 0x0c085260u: goto P_0c085260;
case 0x0c085262u: goto P_0c085262;
case 0x0c085264u: goto P_0c085264;
case 0x0c085266u: goto P_0c085266;
case 0x0c085268u: goto P_0c085268;
case 0x0c08526au: goto P_0c08526a;
case 0x0c08526cu: goto P_0c08526c;
case 0x0c08526eu: goto P_0c08526e;
case 0x0c085270u: goto P_0c085270;
case 0x0c085272u: goto P_0c085272;
case 0x0c085274u: goto P_0c085274;
case 0x0c085276u: goto P_0c085276;
case 0x0c085278u: goto P_0c085278;
case 0x0c08527au: goto P_0c08527a;
case 0x0c08527cu: goto P_0c08527c;
case 0x0c08527eu: goto P_0c08527e;
case 0x0c085280u: goto P_0c085280;
case 0x0c085282u: goto P_0c085282;
case 0x0c085284u: goto P_0c085284;
case 0x0c085286u: goto P_0c085286;
case 0x0c085288u: goto P_0c085288;
case 0x0c08528au: goto P_0c08528a;
case 0x0c08528cu: goto P_0c08528c;
case 0x0c08528eu: goto P_0c08528e;
case 0x0c085290u: goto P_0c085290;
case 0x0c085292u: goto P_0c085292;
case 0x0c085294u: goto P_0c085294;
case 0x0c085296u: goto P_0c085296;
case 0x0c085298u: goto P_0c085298;
case 0x0c08529au: goto P_0c08529a;
case 0x0c08529cu: goto P_0c08529c;
case 0x0c08529eu: goto P_0c08529e;
case 0x0c0852a0u: goto P_0c0852a0;
case 0x0c0852a2u: goto P_0c0852a2;
case 0x0c0852a4u: goto P_0c0852a4;
case 0x0c0852a6u: goto P_0c0852a6;
case 0x0c0852a8u: goto P_0c0852a8;
case 0x0c0852aau: goto P_0c0852aa;
case 0x0c0852acu: goto P_0c0852ac;
case 0x0c0852aeu: goto P_0c0852ae;
case 0x0c0852b0u: goto P_0c0852b0;
case 0x0c0852b2u: goto P_0c0852b2;
case 0x0c0852b4u: goto P_0c0852b4;
case 0x0c0852b6u: goto P_0c0852b6;
case 0x0c0852b8u: goto P_0c0852b8;
case 0x0c0852bau: goto P_0c0852ba;
case 0x0c0852bcu: goto P_0c0852bc;
case 0x0c0852beu: goto P_0c0852be;
case 0x0c0852c0u: goto P_0c0852c0;
case 0x0c0852c2u: goto P_0c0852c2;
case 0x0c0852c4u: goto P_0c0852c4;
case 0x0c0852c6u: goto P_0c0852c6;
case 0x0c0852c8u: goto P_0c0852c8;
case 0x0c0852cau: goto P_0c0852ca;
case 0x0c0852ccu: goto P_0c0852cc;
case 0x0c0852ceu: goto P_0c0852ce;
case 0x0c0852d0u: goto P_0c0852d0;
case 0x0c0852d2u: goto P_0c0852d2;
case 0x0c0852d4u: goto P_0c0852d4;
case 0x0c0852d6u: goto P_0c0852d6;
case 0x0c0852d8u: goto P_0c0852d8;
case 0x0c0852dau: goto P_0c0852da;
case 0x0c0852dcu: goto P_0c0852dc;
case 0x0c0852deu: goto P_0c0852de;
case 0x0c0852e0u: goto P_0c0852e0;
case 0x0c0852e2u: goto P_0c0852e2;
case 0x0c0852e4u: goto P_0c0852e4;
case 0x0c0852e6u: goto P_0c0852e6;
case 0x0c0852e8u: goto P_0c0852e8;
case 0x0c0852eau: goto P_0c0852ea;
case 0x0c0852ecu: goto P_0c0852ec;
case 0x0c0852eeu: goto P_0c0852ee;
case 0x0c0852f0u: goto P_0c0852f0;
case 0x0c0852f2u: goto P_0c0852f2;
case 0x0c0852f4u: goto P_0c0852f4;
case 0x0c0852f6u: goto P_0c0852f6;
case 0x0c0852f8u: goto P_0c0852f8;
case 0x0c0852fau: goto P_0c0852fa;
case 0x0c0852fcu: goto P_0c0852fc;
case 0x0c0852feu: goto P_0c0852fe;
case 0x0c085300u: goto P_0c085300;
case 0x0c085302u: goto P_0c085302;
case 0x0c085304u: goto P_0c085304;
case 0x0c085306u: goto P_0c085306;
case 0x0c085308u: goto P_0c085308;
case 0x0c08530au: goto P_0c08530a;
case 0x0c08530cu: goto P_0c08530c;
case 0x0c08530eu: goto P_0c08530e;
case 0x0c085310u: goto P_0c085310;
case 0x0c085312u: goto P_0c085312;
case 0x0c085314u: goto P_0c085314;
case 0x0c085316u: goto P_0c085316;
case 0x0c085318u: goto P_0c085318;
case 0x0c08531au: goto P_0c08531a;
case 0x0c08531cu: goto P_0c08531c;
case 0x0c08531eu: goto P_0c08531e;
case 0x0c085320u: goto P_0c085320;
case 0x0c085322u: goto P_0c085322;
case 0x0c085324u: goto P_0c085324;
case 0x0c085326u: goto P_0c085326;
case 0x0c085328u: goto P_0c085328;
case 0x0c08532au: goto P_0c08532a;
case 0x0c08532cu: goto P_0c08532c;
case 0x0c08532eu: goto P_0c08532e;
case 0x0c085330u: goto P_0c085330;
case 0x0c085332u: goto P_0c085332;
case 0x0c085334u: goto P_0c085334;
case 0x0c085336u: goto P_0c085336;
case 0x0c085338u: goto P_0c085338;
case 0x0c08533au: goto P_0c08533a;
case 0x0c08533cu: goto P_0c08533c;
case 0x0c08533eu: goto P_0c08533e;
case 0x0c085340u: goto P_0c085340;
case 0x0c085342u: goto P_0c085342;
case 0x0c085344u: goto P_0c085344;
case 0x0c085346u: goto P_0c085346;
case 0x0c085348u: goto P_0c085348;
case 0x0c08534au: goto P_0c08534a;
case 0x0c08534cu: goto P_0c08534c;
case 0x0c08534eu: goto P_0c08534e;
case 0x0c085350u: goto P_0c085350;
case 0x0c085352u: goto P_0c085352;
case 0x0c085354u: goto P_0c085354;
case 0x0c08538cu: goto P_0c08538c;
case 0x0c08538eu: goto P_0c08538e;
case 0x0c085390u: goto P_0c085390;
case 0x0c085392u: goto P_0c085392;
case 0x0c085394u: goto P_0c085394;
case 0x0c085396u: goto P_0c085396;
case 0x0c085398u: goto P_0c085398;
case 0x0c08539au: goto P_0c08539a;
case 0x0c08539cu: goto P_0c08539c;
case 0x0c08539eu: goto P_0c08539e;
case 0x0c0853a0u: goto P_0c0853a0;
case 0x0c0853a2u: goto P_0c0853a2;
case 0x0c0853a4u: goto P_0c0853a4;
case 0x0c0853a6u: goto P_0c0853a6;
case 0x0c0853a8u: goto P_0c0853a8;
case 0x0c0853aau: goto P_0c0853aa;
case 0x0c0853acu: goto P_0c0853ac;
case 0x0c0853aeu: goto P_0c0853ae;
case 0x0c0853b0u: goto P_0c0853b0;
case 0x0c0853b2u: goto P_0c0853b2;
case 0x0c0853b4u: goto P_0c0853b4;
case 0x0c0853b6u: goto P_0c0853b6;
case 0x0c0853b8u: goto P_0c0853b8;
case 0x0c0853bau: goto P_0c0853ba;
case 0x0c0853bcu: goto P_0c0853bc;
case 0x0c0853beu: goto P_0c0853be;
case 0x0c0853c0u: goto P_0c0853c0;
case 0x0c0853c2u: goto P_0c0853c2;
case 0x0c0853c4u: goto P_0c0853c4;
case 0x0c0853c6u: goto P_0c0853c6;
case 0x0c0853c8u: goto P_0c0853c8;
case 0x0c0853cau: goto P_0c0853ca;
case 0x0c0853ccu: goto P_0c0853cc;
case 0x0c0853ceu: goto P_0c0853ce;
case 0x0c0853d0u: goto P_0c0853d0;
case 0x0c0853d2u: goto P_0c0853d2;
case 0x0c0853d4u: goto P_0c0853d4;
case 0x0c0853d6u: goto P_0c0853d6;
case 0x0c0853d8u: goto P_0c0853d8;
case 0x0c0853dau: goto P_0c0853da;
case 0x0c0853dcu: goto P_0c0853dc;
case 0x0c0853deu: goto P_0c0853de;
case 0x0c0853e0u: goto P_0c0853e0;
case 0x0c0853e2u: goto P_0c0853e2;
case 0x0c0853e4u: goto P_0c0853e4;
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
P_0c085250: /* original 2fe6, guest PC 0x0c085250 */
if(!s->budget--) { s->failed_pc=0x0c085250u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085252;
P_0c085252: /* original 2fd6, guest PC 0x0c085252 */
if(!s->budget--) { s->failed_pc=0x0c085252u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085254;
P_0c085254: /* original 2fc6, guest PC 0x0c085254 */
if(!s->budget--) { s->failed_pc=0x0c085254u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085256;
P_0c085256: /* original 2fb6, guest PC 0x0c085256 */
if(!s->budget--) { s->failed_pc=0x0c085256u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085258;
P_0c085258: /* original 2fa6, guest PC 0x0c085258 */
if(!s->budget--) { s->failed_pc=0x0c085258u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08525a;
P_0c08525a: /* original 6a43, guest PC 0x0c08525a */
if(!s->budget--) { s->failed_pc=0x0c08525au; return 0; }
r[10]=r[4];
goto P_0c08525c;
P_0c08525c: /* original 2f96, guest PC 0x0c08525c */
if(!s->budget--) { s->failed_pc=0x0c08525cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08525e;
P_0c08525e: /* original 2f86, guest PC 0x0c08525e */
if(!s->budget--) { s->failed_pc=0x0c08525eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085260;
P_0c085260: /* original fffb, guest PC 0x0c085260 */
if(!s->budget--) { s->failed_pc=0x0c085260u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085262;
P_0c085262: /* original ffeb, guest PC 0x0c085262 */
if(!s->budget--) { s->failed_pc=0x0c085262u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c085264;
P_0c085264: /* original ffdb, guest PC 0x0c085264 */
if(!s->budget--) { s->failed_pc=0x0c085264u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c085266;
P_0c085266: /* original ffcb, guest PC 0x0c085266 */
if(!s->budget--) { s->failed_pc=0x0c085266u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c085268;
P_0c085268: /* original d33d, guest PC 0x0c085268 */
if(!s->budget--) { s->failed_pc=0x0c085268u; return 0; }
r[3]=read(ram,0x0c085360u,4);
goto P_0c08526a;
P_0c08526a: /* original 4f22, guest PC 0x0c08526a */
if(!s->budget--) { s->failed_pc=0x0c08526au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08526c;
P_0c08526c: /* original 6030, guest PC 0x0c08526c */
if(!s->budget--) { s->failed_pc=0x0c08526cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c08526e;
P_0c08526e: /* original 9e72, guest PC 0x0c08526e */
if(!s->budget--) { s->failed_pc=0x0c08526eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085356u,2);
goto P_0c085270;
P_0c085270: /* original 600c, guest PC 0x0c085270 */
if(!s->budget--) { s->failed_pc=0x0c085270u; return 0; }
r[0]=r[0]&255u;
goto P_0c085272;
P_0c085272: /* original 6da1, guest PC 0x0c085272 */
if(!s->budget--) { s->failed_pc=0x0c085272u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[13]=tmp;
goto P_0c085274;
P_0c085274: /* original c90f, guest PC 0x0c085274 */
if(!s->budget--) { s->failed_pc=0x0c085274u; return 0; }
r[0]&=15u;
goto P_0c085276;
P_0c085276: /* original d439, guest PC 0x0c085276 */
if(!s->budget--) { s->failed_pc=0x0c085276u; return 0; }
r[4]=read(ram,0x0c08535cu,4);
goto P_0c085278;
P_0c085278: /* original 880c, guest PC 0x0c085278 */
if(!s->budget--) { s->failed_pc=0x0c085278u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c08527a;
P_0c08527a: /* original 3eac, guest PC 0x0c08527a */
if(!s->budget--) { s->failed_pc=0x0c08527au; return 0; }
r[14]+=r[10];
goto P_0c08527c;
P_0c08527c: /* original 7ff8, guest PC 0x0c08527c */
if(!s->budget--) { s->failed_pc=0x0c08527cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08527e;
P_0c08527e: /* original 8f02, guest PC 0x0c08527e */
if(!s->budget--) { s->failed_pc=0x0c08527eu; return 0; }
cond=r[17]&1u;
r[13]=r[13]&65535u;
if(!cond) { goto P_0c085286; }
goto P_0c085282;
P_0c085280: /* original 6ddd, guest PC 0x0c085280 */
if(!s->budget--) { s->failed_pc=0x0c085280u; return 0; }
r[13]=r[13]&65535u;
goto P_0c085282;
P_0c085282: /* original a001, guest PC 0x0c085282 */
if(!s->budget--) { s->failed_pc=0x0c085282u; return 0; }
tmp=read(ram,r[4],4);
r[11]=tmp;
goto P_0c085288;
P_0c085284: /* original 6b42, guest PC 0x0c085284 */
if(!s->budget--) { s->failed_pc=0x0c085284u; return 0; }
tmp=read(ram,r[4],4);
r[11]=tmp;
goto P_0c085286;
P_0c085286: /* original 5b41, guest PC 0x0c085286 */
if(!s->budget--) { s->failed_pc=0x0c085286u; return 0; }
r[11]=read(ram,r[4]+4,4);
goto P_0c085288;
P_0c085288: /* original d336, guest PC 0x0c085288 */
if(!s->budget--) { s->failed_pc=0x0c085288u; return 0; }
r[3]=read(ram,0x0c085364u,4);
goto P_0c08528a;
P_0c08528a: /* original 430b, guest PC 0x0c08528a */
if(!s->budget--) { s->failed_pc=0x0c08528au; return 0; }
target=r[3];
r[16]=code_base|0x0c08528eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08528eu) { target=s->pc; goto dispatch; }
goto P_0c08528e;
P_0c08528c: /* original e400, guest PC 0x0c08528c */
if(!s->budget--) { s->failed_pc=0x0c08528cu; return 0; }
r[4]=0x00000000u;
goto P_0c08528e;
P_0c08528e: /* original a050, guest PC 0x0c08528e */
if(!s->budget--) { s->failed_pc=0x0c08528eu; return 0; }
r[9]=0x00000002u;
goto P_0c085332;
P_0c085290: /* original e902, guest PC 0x0c085290 */
if(!s->budget--) { s->failed_pc=0x0c085290u; return 0; }
r[9]=0x00000002u;
goto P_0c085292;
P_0c085292: /* original 2dd8, guest PC 0x0c085292 */
if(!s->budget--) { s->failed_pc=0x0c085292u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c085294;
P_0c085294: /* original 8948, guest PC 0x0c085294 */
if(!s->budget--) { s->failed_pc=0x0c085294u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085328; }
goto P_0c085296;
P_0c085296: /* original 6cb3, guest PC 0x0c085296 */
if(!s->budget--) { s->failed_pc=0x0c085296u; return 0; }
r[12]=r[11];
goto P_0c085298;
P_0c085298: /* original a044, guest PC 0x0c085298 */
if(!s->budget--) { s->failed_pc=0x0c085298u; return 0; }
r[13]=0x0000000fu;
goto P_0c085324;
P_0c08529a: /* original ed0f, guest PC 0x0c08529a */
if(!s->budget--) { s->failed_pc=0x0c08529au; return 0; }
r[13]=0x0000000fu;
goto P_0c08529c;
P_0c08529c: /* original e004, guest PC 0x0c08529c */
if(!s->budget--) { s->failed_pc=0x0c08529cu; return 0; }
r[0]=0x00000004u;
goto P_0c08529e;
P_0c08529e: /* original f2e8, guest PC 0x0c08529e */
if(!s->budget--) { s->failed_pc=0x0c08529eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
goto P_0c0852a0;
P_0c0852a0: /* original fce6, guest PC 0x0c0852a0 */
if(!s->budget--) { s->failed_pc=0x0c0852a0u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0852a2;
P_0c0852a2: /* original e008, guest PC 0x0c0852a2 */
if(!s->budget--) { s->failed_pc=0x0c0852a2u; return 0; }
r[0]=0x00000008u;
goto P_0c0852a4;
P_0c0852a4: /* original fde6, guest PC 0x0c0852a4 */
if(!s->budget--) { s->failed_pc=0x0c0852a4u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0852a6;
P_0c0852a6: /* original e00c, guest PC 0x0c0852a6 */
if(!s->budget--) { s->failed_pc=0x0c0852a6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0852a8;
P_0c0852a8: /* original f5e6, guest PC 0x0c0852a8 */
if(!s->budget--) { s->failed_pc=0x0c0852a8u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0852aa;
P_0c0852aa: /* original e010, guest PC 0x0c0852aa */
if(!s->budget--) { s->failed_pc=0x0c0852aau; return 0; }
r[0]=0x00000010u;
goto P_0c0852ac;
P_0c0852ac: /* original f6e6, guest PC 0x0c0852ac */
if(!s->budget--) { s->failed_pc=0x0c0852acu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0852ae;
P_0c0852ae: /* original e014, guest PC 0x0c0852ae */
if(!s->budget--) { s->failed_pc=0x0c0852aeu; return 0; }
r[0]=0x00000014u;
goto P_0c0852b0;
P_0c0852b0: /* original ffe6, guest PC 0x0c0852b0 */
if(!s->budget--) { s->failed_pc=0x0c0852b0u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0852b2;
P_0c0852b2: /* original e510, guest PC 0x0c0852b2 */
if(!s->budget--) { s->failed_pc=0x0c0852b2u; return 0; }
r[5]=0x00000010u;
goto P_0c0852b4;
P_0c0852b4: /* original 85ec, guest PC 0x0c0852b4 */
if(!s->budget--) { s->failed_pc=0x0c0852b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c0852b6;
P_0c0852b6: /* original 6403, guest PC 0x0c0852b6 */
if(!s->budget--) { s->failed_pc=0x0c0852b6u; return 0; }
r[4]=r[0];
goto P_0c0852b8;
P_0c0852b8: /* original 445a, guest PC 0x0c0852b8 */
if(!s->budget--) { s->failed_pc=0x0c0852b8u; return 0; }
r[53]=r[4];
goto P_0c0852ba;
P_0c0852ba: /* original c72b, guest PC 0x0c0852ba */
if(!s->budget--) { s->failed_pc=0x0c0852bau; return 0; }
r[0]=code_base|0x00085368u;
goto P_0c0852bc;
P_0c0852bc: /* original 6343, guest PC 0x0c0852bc */
if(!s->budget--) { s->failed_pc=0x0c0852bcu; return 0; }
r[3]=r[4];
goto P_0c0852be;
P_0c0852be: /* original 2358, guest PC 0x0c0852be */
if(!s->budget--) { s->failed_pc=0x0c0852beu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0852c0;
P_0c0852c0: /* original f32d, guest PC 0x0c0852c0 */
if(!s->budget--) { s->failed_pc=0x0c0852c0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0852c2;
P_0c0852c2: /* original f03c, guest PC 0x0c0852c2 */
if(!s->budget--) { s->failed_pc=0x0c0852c2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0852c4;
P_0c0852c4: /* original f25e, guest PC 0x0c0852c4 */
if(!s->budget--) { s->failed_pc=0x0c0852c4u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c0852c6;
P_0c0852c6: /* original f43c, guest PC 0x0c0852c6 */
if(!s->budget--) { s->failed_pc=0x0c0852c6u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0852c8;
P_0c0852c8: /* original f3dc, guest PC 0x0c0852c8 */
if(!s->budget--) { s->failed_pc=0x0c0852c8u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0852ca;
P_0c0852ca: /* original f36e, guest PC 0x0c0852ca */
if(!s->budget--) { s->failed_pc=0x0c0852cau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c0852cc;
P_0c0852cc: /* original f508, guest PC 0x0c0852cc */
if(!s->budget--) { s->failed_pc=0x0c0852ccu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0852ce;
P_0c0852ce: /* original fe2c, guest PC 0x0c0852ce */
if(!s->budget--) { s->failed_pc=0x0c0852ceu; return 0; }
vf3_matrix_move(s,14,2);
goto P_0c0852d0;
P_0c0852d0: /* original fd3c, guest PC 0x0c0852d0 */
if(!s->budget--) { s->failed_pc=0x0c0852d0u; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c0852d2;
P_0c0852d2: /* original 8f21, guest PC 0x0c0852d2 */
if(!s->budget--) { s->failed_pc=0x0c0852d2u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
if(!cond) { goto P_0c085318; }
goto P_0c0852d6;
P_0c0852d4: /* original f452, guest PC 0x0c0852d4 */
if(!s->budget--) { s->failed_pc=0x0c0852d4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0852d6;
P_0c0852d6: /* original 6043, guest PC 0x0c0852d6 */
if(!s->budget--) { s->failed_pc=0x0c0852d6u; return 0; }
r[0]=r[4];
goto P_0c0852d8;
P_0c0852d8: /* original 4000, guest PC 0x0c0852d8 */
if(!s->budget--) { s->failed_pc=0x0c0852d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0852da;
P_0c0852da: /* original 03cd, guest PC 0x0c0852da */
if(!s->budget--) { s->failed_pc=0x0c0852dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0852dc;
P_0c0852dc: /* original 1f31, guest PC 0x0c0852dc */
if(!s->budget--) { s->failed_pc=0x0c0852dcu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0852de;
P_0c0852de: /* original d423, guest PC 0x0c0852de */
if(!s->budget--) { s->failed_pc=0x0c0852deu; return 0; }
r[4]=read(ram,0x0c08536cu,4);
goto P_0c0852e0;
P_0c0852e0: /* original 5448, guest PC 0x0c0852e0 */
if(!s->budget--) { s->failed_pc=0x0c0852e0u; return 0; }
r[4]=read(ram,r[4]+32,4);
goto P_0c0852e2;
P_0c0852e2: /* original 854f, guest PC 0x0c0852e2 */
if(!s->budget--) { s->failed_pc=0x0c0852e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0852e4;
P_0c0852e4: /* original 2f02, guest PC 0x0c0852e4 */
if(!s->budget--) { s->failed_pc=0x0c0852e4u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0852e6;
P_0c0852e6: /* original 854e, guest PC 0x0c0852e6 */
if(!s->budget--) { s->failed_pc=0x0c0852e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c0852e8;
P_0c0852e8: /* original d321, guest PC 0x0c0852e8 */
if(!s->budget--) { s->failed_pc=0x0c0852e8u; return 0; }
r[3]=read(ram,0x0c085370u,4);
goto P_0c0852ea;
P_0c0852ea: /* original 6803, guest PC 0x0c0852ea */
if(!s->budget--) { s->failed_pc=0x0c0852eau; return 0; }
r[8]=r[0];
goto P_0c0852ec;
P_0c0852ec: /* original 430b, guest PC 0x0c0852ec */
if(!s->budget--) { s->failed_pc=0x0c0852ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0852f0u;
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'+');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0852f0u) { target=s->pc; goto dispatch; }
goto P_0c0852f0;
P_0c0852ee: /* original fc40, guest PC 0x0c0852ee */
if(!s->budget--) { s->failed_pc=0x0c0852eeu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'+');
goto P_0c0852f0;
P_0c0852f0: /* original d220, guest PC 0x0c0852f0 */
if(!s->budget--) { s->failed_pc=0x0c0852f0u; return 0; }
r[2]=read(ram,0x0c085374u,4);
goto P_0c0852f2;
P_0c0852f2: /* original f6dc, guest PC 0x0c0852f2 */
if(!s->budget--) { s->failed_pc=0x0c0852f2u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0852f4;
P_0c0852f4: /* original f5cc, guest PC 0x0c0852f4 */
if(!s->budget--) { s->failed_pc=0x0c0852f4u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c0852f6;
P_0c0852f6: /* original f64d, guest PC 0x0c0852f6 */
if(!s->budget--) { s->failed_pc=0x0c0852f6u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0852f8;
P_0c0852f8: /* original 420b, guest PC 0x0c0852f8 */
if(!s->budget--) { s->failed_pc=0x0c0852f8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0852fcu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0852fcu) { target=s->pc; goto dispatch; }
goto P_0c0852fc;
P_0c0852fa: /* original f4ec, guest PC 0x0c0852fa */
if(!s->budget--) { s->failed_pc=0x0c0852fau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0852fc;
P_0c0852fc: /* original d31e, guest PC 0x0c0852fc */
if(!s->budget--) { s->failed_pc=0x0c0852fcu; return 0; }
r[3]=read(ram,0x0c085378u,4);
goto P_0c0852fe;
P_0c0852fe: /* original 430b, guest PC 0x0c0852fe */
if(!s->budget--) { s->failed_pc=0x0c0852feu; return 0; }
target=r[3];
r[16]=code_base|0x0c085302u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085302u) { target=s->pc; goto dispatch; }
goto P_0c085302;
P_0c085300: /* original 64f2, guest PC 0x0c085300 */
if(!s->budget--) { s->failed_pc=0x0c085300u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c085302;
P_0c085302: /* original d21e, guest PC 0x0c085302 */
if(!s->budget--) { s->failed_pc=0x0c085302u; return 0; }
r[2]=read(ram,0x0c08537cu,4);
goto P_0c085304;
P_0c085304: /* original 420b, guest PC 0x0c085304 */
if(!s->budget--) { s->failed_pc=0x0c085304u; return 0; }
target=r[2];
r[16]=code_base|0x0c085308u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085308u) { target=s->pc; goto dispatch; }
goto P_0c085308;
P_0c085306: /* original 6483, guest PC 0x0c085306 */
if(!s->budget--) { s->failed_pc=0x0c085306u; return 0; }
r[4]=r[8];
goto P_0c085308;
P_0c085308: /* original d81d, guest PC 0x0c085308 */
if(!s->budget--) { s->failed_pc=0x0c085308u; return 0; }
r[8]=read(ram,0x0c085380u,4);
goto P_0c08530a;
P_0c08530a: /* original f5fc, guest PC 0x0c08530a */
if(!s->budget--) { s->failed_pc=0x0c08530au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08530c;
P_0c08530c: /* original f6fc, guest PC 0x0c08530c */
if(!s->budget--) { s->failed_pc=0x0c08530cu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08530e;
P_0c08530e: /* original 480b, guest PC 0x0c08530e */
if(!s->budget--) { s->failed_pc=0x0c08530eu; return 0; }
target=r[8];
r[16]=code_base|0x0c085312u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085312u) { target=s->pc; goto dispatch; }
goto P_0c085312;
P_0c085310: /* original f4fc, guest PC 0x0c085310 */
if(!s->budget--) { s->failed_pc=0x0c085310u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c085312;
P_0c085312: /* original d81c, guest PC 0x0c085312 */
if(!s->budget--) { s->failed_pc=0x0c085312u; return 0; }
r[8]=read(ram,0x0c085384u,4);
goto P_0c085314;
P_0c085314: /* original 480b, guest PC 0x0c085314 */
if(!s->budget--) { s->failed_pc=0x0c085314u; return 0; }
target=r[8];
r[16]=code_base|0x0c085318u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085318u) { target=s->pc; goto dispatch; }
goto P_0c085318;
P_0c085316: /* original 54f1, guest PC 0x0c085316 */
if(!s->budget--) { s->failed_pc=0x0c085316u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c085318;
P_0c085318: /* original 60d3, guest PC 0x0c085318 */
if(!s->budget--) { s->failed_pc=0x0c085318u; return 0; }
r[0]=r[13];
goto P_0c08531a;
P_0c08531a: /* original 880f, guest PC 0x0c08531a */
if(!s->budget--) { s->failed_pc=0x0c08531au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c08531c;
P_0c08531c: /* original 8f01, guest PC 0x0c08531c */
if(!s->budget--) { s->failed_pc=0x0c08531cu; return 0; }
cond=r[17]&1u;
r[14]+=0x0000001cu;
if(!cond) { goto P_0c085322; }
goto P_0c085320;
P_0c08531e: /* original 7e1c, guest PC 0x0c08531e */
if(!s->budget--) { s->failed_pc=0x0c08531eu; return 0; }
r[14]+=0x0000001cu;
goto P_0c085320;
P_0c085320: /* original 6cb3, guest PC 0x0c085320 */
if(!s->budget--) { s->failed_pc=0x0c085320u; return 0; }
r[12]=r[11];
goto P_0c085322;
P_0c085322: /* original 7dff, guest PC 0x0c085322 */
if(!s->budget--) { s->failed_pc=0x0c085322u; return 0; }
r[13]+=0xffffffffu;
goto P_0c085324;
P_0c085324: /* original 2dd8, guest PC 0x0c085324 */
if(!s->budget--) { s->failed_pc=0x0c085324u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c085326;
P_0c085326: /* original 8bb9, guest PC 0x0c085326 */
if(!s->budget--) { s->failed_pc=0x0c085326u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08529c; }
goto P_0c085328;
P_0c085328: /* original 9e16, guest PC 0x0c085328 */
if(!s->budget--) { s->failed_pc=0x0c085328u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085358u,2);
goto P_0c08532a;
P_0c08532a: /* original 79ff, guest PC 0x0c08532a */
if(!s->budget--) { s->failed_pc=0x0c08532au; return 0; }
r[9]+=0xffffffffu;
goto P_0c08532c;
P_0c08532c: /* original 85a1, guest PC 0x0c08532c */
if(!s->budget--) { s->failed_pc=0x0c08532cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+2,2);
goto P_0c08532e;
P_0c08532e: /* original 3eac, guest PC 0x0c08532e */
if(!s->budget--) { s->failed_pc=0x0c08532eu; return 0; }
r[14]+=r[10];
goto P_0c085330;
P_0c085330: /* original 6d0d, guest PC 0x0c085330 */
if(!s->budget--) { s->failed_pc=0x0c085330u; return 0; }
r[13]=r[0]&65535u;
goto P_0c085332;
P_0c085332: /* original 2998, guest PC 0x0c085332 */
if(!s->budget--) { s->failed_pc=0x0c085332u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c085334;
P_0c085334: /* original 8bad, guest PC 0x0c085334 */
if(!s->budget--) { s->failed_pc=0x0c085334u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085292; }
goto P_0c085336;
P_0c085336: /* original 7f08, guest PC 0x0c085336 */
if(!s->budget--) { s->failed_pc=0x0c085336u; return 0; }
r[15]+=0x00000008u;
goto P_0c085338;
P_0c085338: /* original d213, guest PC 0x0c085338 */
if(!s->budget--) { s->failed_pc=0x0c085338u; return 0; }
r[2]=read(ram,0x0c085388u,4);
goto P_0c08533a;
P_0c08533a: /* original 4f26, guest PC 0x0c08533a */
if(!s->budget--) { s->failed_pc=0x0c08533au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08533c;
P_0c08533c: /* original e401, guest PC 0x0c08533c */
if(!s->budget--) { s->failed_pc=0x0c08533cu; return 0; }
r[4]=0x00000001u;
goto P_0c08533e;
P_0c08533e: /* original fcf9, guest PC 0x0c08533e */
if(!s->budget--) { s->failed_pc=0x0c08533eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085340;
P_0c085340: /* original fdf9, guest PC 0x0c085340 */
if(!s->budget--) { s->failed_pc=0x0c085340u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085342;
P_0c085342: /* original fef9, guest PC 0x0c085342 */
if(!s->budget--) { s->failed_pc=0x0c085342u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085344;
P_0c085344: /* original fff9, guest PC 0x0c085344 */
if(!s->budget--) { s->failed_pc=0x0c085344u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085346;
P_0c085346: /* original 68f6, guest PC 0x0c085346 */
if(!s->budget--) { s->failed_pc=0x0c085346u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085348;
P_0c085348: /* original 69f6, guest PC 0x0c085348 */
if(!s->budget--) { s->failed_pc=0x0c085348u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08534a;
P_0c08534a: /* original 6af6, guest PC 0x0c08534a */
if(!s->budget--) { s->failed_pc=0x0c08534au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08534c;
P_0c08534c: /* original 6bf6, guest PC 0x0c08534c */
if(!s->budget--) { s->failed_pc=0x0c08534cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08534e;
P_0c08534e: /* original 6cf6, guest PC 0x0c08534e */
if(!s->budget--) { s->failed_pc=0x0c08534eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085350;
P_0c085350: /* original 6df6, guest PC 0x0c085350 */
if(!s->budget--) { s->failed_pc=0x0c085350u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085352;
P_0c085352: /* original 422b, guest PC 0x0c085352 */
if(!s->budget--) { s->failed_pc=0x0c085352u; return 0; }
target=r[2];
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
P_0c085354: /* original 6ef6, guest PC 0x0c085354 */
if(!s->budget--) { s->failed_pc=0x0c085354u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c085356u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085356u; return 0; } return 1;
P_0c08538c: /* original 2fe6, guest PC 0x0c08538c */
if(!s->budget--) { s->failed_pc=0x0c08538cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08538e;
P_0c08538e: /* original 6e43, guest PC 0x0c08538e */
if(!s->budget--) { s->failed_pc=0x0c08538eu; return 0; }
r[14]=r[4];
goto P_0c085390;
P_0c085390: /* original 2fd6, guest PC 0x0c085390 */
if(!s->budget--) { s->failed_pc=0x0c085390u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085392;
P_0c085392: /* original 2fc6, guest PC 0x0c085392 */
if(!s->budget--) { s->failed_pc=0x0c085392u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085394;
P_0c085394: /* original ec0d, guest PC 0x0c085394 */
if(!s->budget--) { s->failed_pc=0x0c085394u; return 0; }
r[12]=0x0000000du;
goto P_0c085396;
P_0c085396: /* original 2fb6, guest PC 0x0c085396 */
if(!s->budget--) { s->failed_pc=0x0c085396u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085398;
P_0c085398: /* original 2fa6, guest PC 0x0c085398 */
if(!s->budget--) { s->failed_pc=0x0c085398u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08539a;
P_0c08539a: /* original 2f96, guest PC 0x0c08539a */
if(!s->budget--) { s->failed_pc=0x0c08539au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08539c;
P_0c08539c: /* original fffb, guest PC 0x0c08539c */
if(!s->budget--) { s->failed_pc=0x0c08539cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08539e;
P_0c08539e: /* original ffeb, guest PC 0x0c08539e */
if(!s->budget--) { s->failed_pc=0x0c08539eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0853a0;
P_0c0853a0: /* original ffdb, guest PC 0x0c0853a0 */
if(!s->budget--) { s->failed_pc=0x0c0853a0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0853a2;
P_0c0853a2: /* original 4f22, guest PC 0x0c0853a2 */
if(!s->budget--) { s->failed_pc=0x0c0853a2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0853a4;
P_0c0853a4: /* original da2d, guest PC 0x0c0853a4 */
if(!s->budget--) { s->failed_pc=0x0c0853a4u; return 0; }
r[10]=read(ram,0x0c08545cu,4);
goto P_0c0853a6;
P_0c0853a6: /* original d92e, guest PC 0x0c0853a6 */
if(!s->budget--) { s->failed_pc=0x0c0853a6u; return 0; }
r[9]=read(ram,0x0c085460u,4);
goto P_0c0853a8;
P_0c0853a8: /* original dd2b, guest PC 0x0c0853a8 */
if(!s->budget--) { s->failed_pc=0x0c0853a8u; return 0; }
r[13]=read(ram,0x0c085458u,4);
goto P_0c0853aa;
P_0c0853aa: /* original fe8d, guest PC 0x0c0853aa */
if(!s->budget--) { s->failed_pc=0x0c0853aau; return 0; }
fr[14]=0;
goto P_0c0853ac;
P_0c0853ac: /* original e010, guest PC 0x0c0853ac */
if(!s->budget--) { s->failed_pc=0x0c0853acu; return 0; }
r[0]=0x00000010u;
goto P_0c0853ae;
P_0c0853ae: /* original fdd6, guest PC 0x0c0853ae */
if(!s->budget--) { s->failed_pc=0x0c0853aeu; return 0; }
vf3_matrix_load(s,ram,13,r[13]+r[0]);
goto P_0c0853b0;
P_0c0853b0: /* original e014, guest PC 0x0c0853b0 */
if(!s->budget--) { s->failed_pc=0x0c0853b0u; return 0; }
r[0]=0x00000014u;
goto P_0c0853b2;
P_0c0853b2: /* original ffd6, guest PC 0x0c0853b2 */
if(!s->budget--) { s->failed_pc=0x0c0853b2u; return 0; }
vf3_matrix_load(s,ram,15,r[13]+r[0]);
goto P_0c0853b4;
P_0c0853b4: /* original 7d20, guest PC 0x0c0853b4 */
if(!s->budget--) { s->failed_pc=0x0c0853b4u; return 0; }
r[13]+=0x00000020u;
goto P_0c0853b6;
P_0c0853b6: /* original 490b, guest PC 0x0c0853b6 */
if(!s->budget--) { s->failed_pc=0x0c0853b6u; return 0; }
target=r[9];
r[16]=code_base|0x0c0853bau;
tmp=read(ram,r[10],4);
r[10]+=4;
r[11]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0853bau) { target=s->pc; goto dispatch; }
goto P_0c0853ba;
P_0c0853b8: /* original 6ba6, guest PC 0x0c0853b8 */
if(!s->budget--) { s->failed_pc=0x0c0853b8u; return 0; }
tmp=read(ram,r[10],4);
r[10]+=4;
r[11]=tmp;
goto P_0c0853ba;
P_0c0853ba: /* original 81e6, guest PC 0x0c0853ba */
if(!s->budget--) { s->failed_pc=0x0c0853bau; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c0853bc;
P_0c0853bc: /* original 6403, guest PC 0x0c0853bc */
if(!s->budget--) { s->failed_pc=0x0c0853bcu; return 0; }
r[4]=r[0];
goto P_0c0853be;
P_0c0853be: /* original e004, guest PC 0x0c0853be */
if(!s->budget--) { s->failed_pc=0x0c0853beu; return 0; }
r[0]=0x00000004u;
goto P_0c0853c0;
P_0c0853c0: /* original 1eb5, guest PC 0x0c0853c0 */
if(!s->budget--) { s->failed_pc=0x0c0853c0u; return 0; }
write(ram,r[14]+20,r[11],4);
goto P_0c0853c2;
P_0c0853c2: /* original 4c10, guest PC 0x0c0853c2 */
if(!s->budget--) { s->failed_pc=0x0c0853c2u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c0853c4;
P_0c0853c4: /* original feda, guest PC 0x0c0853c4 */
if(!s->budget--) { s->failed_pc=0x0c0853c4u; return 0; }
vf3_matrix_store(s,ram,13,r[14]);
goto P_0c0853c6;
P_0c0853c6: /* original fee7, guest PC 0x0c0853c6 */
if(!s->budget--) { s->failed_pc=0x0c0853c6u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0853c8;
P_0c0853c8: /* original e008, guest PC 0x0c0853c8 */
if(!s->budget--) { s->failed_pc=0x0c0853c8u; return 0; }
r[0]=0x00000008u;
goto P_0c0853ca;
P_0c0853ca: /* original fef7, guest PC 0x0c0853ca */
if(!s->budget--) { s->failed_pc=0x0c0853cau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0853cc;
P_0c0853cc: /* original 8fee, guest PC 0x0c0853cc */
if(!s->budget--) { s->failed_pc=0x0c0853ccu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c0853ac; }
goto P_0c0853d0;
P_0c0853ce: /* original 7e18, guest PC 0x0c0853ce */
if(!s->budget--) { s->failed_pc=0x0c0853ceu; return 0; }
r[14]+=0x00000018u;
goto P_0c0853d0;
P_0c0853d0: /* original 4f26, guest PC 0x0c0853d0 */
if(!s->budget--) { s->failed_pc=0x0c0853d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0853d2;
P_0c0853d2: /* original fdf9, guest PC 0x0c0853d2 */
if(!s->budget--) { s->failed_pc=0x0c0853d2u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0853d4;
P_0c0853d4: /* original fef9, guest PC 0x0c0853d4 */
if(!s->budget--) { s->failed_pc=0x0c0853d4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0853d6;
P_0c0853d6: /* original fff9, guest PC 0x0c0853d6 */
if(!s->budget--) { s->failed_pc=0x0c0853d6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0853d8;
P_0c0853d8: /* original 69f6, guest PC 0x0c0853d8 */
if(!s->budget--) { s->failed_pc=0x0c0853d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0853da;
P_0c0853da: /* original 6af6, guest PC 0x0c0853da */
if(!s->budget--) { s->failed_pc=0x0c0853dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0853dc;
P_0c0853dc: /* original 6bf6, guest PC 0x0c0853dc */
if(!s->budget--) { s->failed_pc=0x0c0853dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0853de;
P_0c0853de: /* original 6cf6, guest PC 0x0c0853de */
if(!s->budget--) { s->failed_pc=0x0c0853deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0853e0;
P_0c0853e0: /* original 6df6, guest PC 0x0c0853e0 */
if(!s->budget--) { s->failed_pc=0x0c0853e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0853e2;
P_0c0853e2: /* original 000b, guest PC 0x0c0853e2 */
if(!s->budget--) { s->failed_pc=0x0c0853e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0853e4: /* original 6ef6, guest PC 0x0c0853e4 */
if(!s->budget--) { s->failed_pc=0x0c0853e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0853e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0853e6u; return 0; } return 1;
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
