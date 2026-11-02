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
int vf3_away_batch71_adapter_48(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c5eaeu: goto P_0c0c5eae;
case 0x0c0c5eb0u: goto P_0c0c5eb0;
case 0x0c0c5eb2u: goto P_0c0c5eb2;
case 0x0c0c5eb4u: goto P_0c0c5eb4;
case 0x0c0c5eb6u: goto P_0c0c5eb6;
case 0x0c0c5eb8u: goto P_0c0c5eb8;
case 0x0c0c5ebau: goto P_0c0c5eba;
case 0x0c0c5ebcu: goto P_0c0c5ebc;
case 0x0c0c5ebeu: goto P_0c0c5ebe;
case 0x0c0c5ec0u: goto P_0c0c5ec0;
case 0x0c0c5ec2u: goto P_0c0c5ec2;
case 0x0c0c5ec4u: goto P_0c0c5ec4;
case 0x0c0c5ec6u: goto P_0c0c5ec6;
case 0x0c0c5ec8u: goto P_0c0c5ec8;
case 0x0c0c5ecau: goto P_0c0c5eca;
case 0x0c0c5eccu: goto P_0c0c5ecc;
case 0x0c0c5eceu: goto P_0c0c5ece;
case 0x0c0c5ed0u: goto P_0c0c5ed0;
case 0x0c0c5ed2u: goto P_0c0c5ed2;
case 0x0c0c5ed4u: goto P_0c0c5ed4;
case 0x0c0c5ed6u: goto P_0c0c5ed6;
case 0x0c0c5ed8u: goto P_0c0c5ed8;
case 0x0c0c5edau: goto P_0c0c5eda;
case 0x0c0c5edcu: goto P_0c0c5edc;
case 0x0c0c5edeu: goto P_0c0c5ede;
case 0x0c0c5ee0u: goto P_0c0c5ee0;
case 0x0c0c5ee2u: goto P_0c0c5ee2;
case 0x0c0c5ee4u: goto P_0c0c5ee4;
case 0x0c0c5ee6u: goto P_0c0c5ee6;
case 0x0c0c5ee8u: goto P_0c0c5ee8;
case 0x0c0c5eeau: goto P_0c0c5eea;
case 0x0c0c5eecu: goto P_0c0c5eec;
case 0x0c0c5eeeu: goto P_0c0c5eee;
case 0x0c0c5ef0u: goto P_0c0c5ef0;
case 0x0c0c5ef2u: goto P_0c0c5ef2;
case 0x0c0c5ef4u: goto P_0c0c5ef4;
case 0x0c0c5ef6u: goto P_0c0c5ef6;
case 0x0c0c5ef8u: goto P_0c0c5ef8;
case 0x0c0c5efau: goto P_0c0c5efa;
case 0x0c0c5efcu: goto P_0c0c5efc;
case 0x0c0c5efeu: goto P_0c0c5efe;
case 0x0c0c5f00u: goto P_0c0c5f00;
case 0x0c0c5f02u: goto P_0c0c5f02;
case 0x0c0c5f04u: goto P_0c0c5f04;
case 0x0c0c5f06u: goto P_0c0c5f06;
case 0x0c0c5f08u: goto P_0c0c5f08;
case 0x0c0c5f0au: goto P_0c0c5f0a;
case 0x0c0c5f0cu: goto P_0c0c5f0c;
case 0x0c0c5f0eu: goto P_0c0c5f0e;
case 0x0c0c5f10u: goto P_0c0c5f10;
case 0x0c0c61a8u: goto P_0c0c61a8;
case 0x0c0c61aau: goto P_0c0c61aa;
case 0x0c0c61acu: goto P_0c0c61ac;
case 0x0c0c61aeu: goto P_0c0c61ae;
case 0x0c0c61b0u: goto P_0c0c61b0;
case 0x0c0c61b2u: goto P_0c0c61b2;
case 0x0c0c61b4u: goto P_0c0c61b4;
case 0x0c0c61b6u: goto P_0c0c61b6;
case 0x0c0c61b8u: goto P_0c0c61b8;
case 0x0c0c61bau: goto P_0c0c61ba;
case 0x0c0c61bcu: goto P_0c0c61bc;
case 0x0c0c61beu: goto P_0c0c61be;
case 0x0c0c61c0u: goto P_0c0c61c0;
case 0x0c0c61c2u: goto P_0c0c61c2;
case 0x0c0c61c4u: goto P_0c0c61c4;
case 0x0c0c61c6u: goto P_0c0c61c6;
case 0x0c0c61c8u: goto P_0c0c61c8;
case 0x0c0c61cau: goto P_0c0c61ca;
case 0x0c0c61ccu: goto P_0c0c61cc;
case 0x0c0c61ceu: goto P_0c0c61ce;
case 0x0c0c61d0u: goto P_0c0c61d0;
case 0x0c0c61d2u: goto P_0c0c61d2;
case 0x0c0c61d4u: goto P_0c0c61d4;
case 0x0c0c61d6u: goto P_0c0c61d6;
case 0x0c0c61d8u: goto P_0c0c61d8;
case 0x0c0c61dau: goto P_0c0c61da;
case 0x0c0c61dcu: goto P_0c0c61dc;
case 0x0c0c61deu: goto P_0c0c61de;
case 0x0c0c61e0u: goto P_0c0c61e0;
case 0x0c0c61e2u: goto P_0c0c61e2;
case 0x0c0c61e4u: goto P_0c0c61e4;
case 0x0c0c61e6u: goto P_0c0c61e6;
case 0x0c0c61e8u: goto P_0c0c61e8;
case 0x0c0c61eau: goto P_0c0c61ea;
case 0x0c0c61ecu: goto P_0c0c61ec;
case 0x0c0c61eeu: goto P_0c0c61ee;
case 0x0c0c61f0u: goto P_0c0c61f0;
case 0x0c0c61f2u: goto P_0c0c61f2;
case 0x0c0c61f4u: goto P_0c0c61f4;
case 0x0c0c61f6u: goto P_0c0c61f6;
case 0x0c0c61f8u: goto P_0c0c61f8;
case 0x0c0c61fau: goto P_0c0c61fa;
case 0x0c0c61fcu: goto P_0c0c61fc;
case 0x0c0c61feu: goto P_0c0c61fe;
case 0x0c0c6200u: goto P_0c0c6200;
case 0x0c0c6202u: goto P_0c0c6202;
case 0x0c0c6204u: goto P_0c0c6204;
case 0x0c0c6206u: goto P_0c0c6206;
case 0x0c0c6208u: goto P_0c0c6208;
case 0x0c0c620au: goto P_0c0c620a;
case 0x0c0c620cu: goto P_0c0c620c;
case 0x0c0c620eu: goto P_0c0c620e;
case 0x0c0c6210u: goto P_0c0c6210;
case 0x0c0c6212u: goto P_0c0c6212;
case 0x0c0c6214u: goto P_0c0c6214;
case 0x0c0c6216u: goto P_0c0c6216;
case 0x0c0c6218u: goto P_0c0c6218;
case 0x0c0c621au: goto P_0c0c621a;
case 0x0c0c621cu: goto P_0c0c621c;
case 0x0c0c621eu: goto P_0c0c621e;
case 0x0c0c6220u: goto P_0c0c6220;
case 0x0c0c6222u: goto P_0c0c6222;
case 0x0c0c6224u: goto P_0c0c6224;
case 0x0c0c6226u: goto P_0c0c6226;
case 0x0c0c6228u: goto P_0c0c6228;
case 0x0c0c622au: goto P_0c0c622a;
case 0x0c0c622cu: goto P_0c0c622c;
case 0x0c0c622eu: goto P_0c0c622e;
case 0x0c0c6230u: goto P_0c0c6230;
case 0x0c0c6232u: goto P_0c0c6232;
case 0x0c0c6234u: goto P_0c0c6234;
case 0x0c0c6236u: goto P_0c0c6236;
case 0x0c0c6238u: goto P_0c0c6238;
case 0x0c0c623au: goto P_0c0c623a;
case 0x0c0c623cu: goto P_0c0c623c;
case 0x0c0c623eu: goto P_0c0c623e;
case 0x0c0c6240u: goto P_0c0c6240;
case 0x0c0c6242u: goto P_0c0c6242;
case 0x0c0c6244u: goto P_0c0c6244;
case 0x0c0c6246u: goto P_0c0c6246;
case 0x0c0c6248u: goto P_0c0c6248;
case 0x0c0c624au: goto P_0c0c624a;
case 0x0c0c624cu: goto P_0c0c624c;
case 0x0c0c624eu: goto P_0c0c624e;
case 0x0c0c6250u: goto P_0c0c6250;
case 0x0c0c6252u: goto P_0c0c6252;
case 0x0c0c6254u: goto P_0c0c6254;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c70a4u: goto P_0c0c70a4;
case 0x0c0c70a6u: goto P_0c0c70a6;
case 0x0c0c70a8u: goto P_0c0c70a8;
case 0x0c0c70aau: goto P_0c0c70aa;
case 0x0c0c70acu: goto P_0c0c70ac;
case 0x0c0c70aeu: goto P_0c0c70ae;
case 0x0c0c70b0u: goto P_0c0c70b0;
case 0x0c0c70b2u: goto P_0c0c70b2;
case 0x0c0c70b4u: goto P_0c0c70b4;
case 0x0c0c70b6u: goto P_0c0c70b6;
case 0x0c0c70b8u: goto P_0c0c70b8;
case 0x0c0c70bau: goto P_0c0c70ba;
case 0x0c0c70bcu: goto P_0c0c70bc;
case 0x0c0c70beu: goto P_0c0c70be;
case 0x0c0c70c0u: goto P_0c0c70c0;
case 0x0c0c70c2u: goto P_0c0c70c2;
case 0x0c0c70c4u: goto P_0c0c70c4;
case 0x0c0c70c6u: goto P_0c0c70c6;
case 0x0c0c70c8u: goto P_0c0c70c8;
case 0x0c0c70cau: goto P_0c0c70ca;
case 0x0c0c70ccu: goto P_0c0c70cc;
case 0x0c0c70ceu: goto P_0c0c70ce;
case 0x0c0c70d0u: goto P_0c0c70d0;
case 0x0c0c70d2u: goto P_0c0c70d2;
case 0x0c0c70d4u: goto P_0c0c70d4;
case 0x0c0c70d6u: goto P_0c0c70d6;
case 0x0c0c70d8u: goto P_0c0c70d8;
case 0x0c0c70dau: goto P_0c0c70da;
case 0x0c0c70dcu: goto P_0c0c70dc;
case 0x0c0c70deu: goto P_0c0c70de;
case 0x0c0c70e0u: goto P_0c0c70e0;
case 0x0c0c70e2u: goto P_0c0c70e2;
case 0x0c0c70e4u: goto P_0c0c70e4;
case 0x0c0c7648u: goto P_0c0c7648;
case 0x0c0c764au: goto P_0c0c764a;
case 0x0c0c764cu: goto P_0c0c764c;
case 0x0c0c764eu: goto P_0c0c764e;
case 0x0c0c7650u: goto P_0c0c7650;
case 0x0c0c7652u: goto P_0c0c7652;
case 0x0c0c7654u: goto P_0c0c7654;
case 0x0c0c7656u: goto P_0c0c7656;
case 0x0c0c7658u: goto P_0c0c7658;
case 0x0c0c765au: goto P_0c0c765a;
case 0x0c0c765cu: goto P_0c0c765c;
case 0x0c0c765eu: goto P_0c0c765e;
case 0x0c0c7660u: goto P_0c0c7660;
case 0x0c0c7662u: goto P_0c0c7662;
case 0x0c0c7664u: goto P_0c0c7664;
case 0x0c0c7666u: goto P_0c0c7666;
case 0x0c0c7668u: goto P_0c0c7668;
case 0x0c0c766au: goto P_0c0c766a;
case 0x0c0c766cu: goto P_0c0c766c;
case 0x0c0c766eu: goto P_0c0c766e;
case 0x0c0c7670u: goto P_0c0c7670;
case 0x0c0c7672u: goto P_0c0c7672;
case 0x0c0c7674u: goto P_0c0c7674;
case 0x0c0c7676u: goto P_0c0c7676;
case 0x0c0c7678u: goto P_0c0c7678;
case 0x0c0c767au: goto P_0c0c767a;
case 0x0c0c767cu: goto P_0c0c767c;
case 0x0c0c767eu: goto P_0c0c767e;
case 0x0c0c7680u: goto P_0c0c7680;
case 0x0c0c7682u: goto P_0c0c7682;
case 0x0c0c7684u: goto P_0c0c7684;
case 0x0c0c7686u: goto P_0c0c7686;
case 0x0c0c7688u: goto P_0c0c7688;
case 0x0c0c768au: goto P_0c0c768a;
case 0x0c0c768cu: goto P_0c0c768c;
case 0x0c0c768eu: goto P_0c0c768e;
case 0x0c0c7690u: goto P_0c0c7690;
case 0x0c0c7692u: goto P_0c0c7692;
case 0x0c0c7694u: goto P_0c0c7694;
case 0x0c0c7696u: goto P_0c0c7696;
case 0x0c0c7698u: goto P_0c0c7698;
case 0x0c0c769au: goto P_0c0c769a;
case 0x0c0c769cu: goto P_0c0c769c;
case 0x0c0c769eu: goto P_0c0c769e;
case 0x0c0c76a0u: goto P_0c0c76a0;
case 0x0c0c76a2u: goto P_0c0c76a2;
case 0x0c0c76a4u: goto P_0c0c76a4;
case 0x0c0c76a6u: goto P_0c0c76a6;
case 0x0c0c76a8u: goto P_0c0c76a8;
case 0x0c0c76aau: goto P_0c0c76aa;
case 0x0c0c76acu: goto P_0c0c76ac;
case 0x0c0c76aeu: goto P_0c0c76ae;
case 0x0c0c76b0u: goto P_0c0c76b0;
case 0x0c0c76b2u: goto P_0c0c76b2;
case 0x0c0c76b4u: goto P_0c0c76b4;
case 0x0c0c76b6u: goto P_0c0c76b6;
case 0x0c0c76b8u: goto P_0c0c76b8;
case 0x0c0c76bau: goto P_0c0c76ba;
case 0x0c0c76bcu: goto P_0c0c76bc;
case 0x0c0c76beu: goto P_0c0c76be;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c5eae: /* original 2fe6, guest PC 0x0c0c5eae */
if(!s->budget--) { s->failed_pc=0x0c0c5eaeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb0;
P_0c0c5eb0: /* original 2fd6, guest PC 0x0c0c5eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb2;
P_0c0c5eb2: /* original ed1f, guest PC 0x0c0c5eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb2u; return 0; }
r[13]=0x0000001fu;
goto P_0c0c5eb4;
P_0c0c5eb4: /* original 2d49, guest PC 0x0c0c5eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb4u; return 0; }
r[13]&=r[4];
goto P_0c0c5eb6;
P_0c0c5eb6: /* original d31b, guest PC 0x0c0c5eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb6u; return 0; }
r[3]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5eb8;
P_0c0c5eb8: /* original 4d00, guest PC 0x0c0c5eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0c5eba;
P_0c0c5eba: /* original 6ed3, guest PC 0x0c0c5eba */
if(!s->budget--) { s->failed_pc=0x0c0c5ebau; return 0; }
r[14]=r[13];
goto P_0c0c5ebc;
P_0c0c5ebc: /* original 4e08, guest PC 0x0c0c5ebc */
if(!s->budget--) { s->failed_pc=0x0c0c5ebcu; return 0; }
r[14]<<=2;
goto P_0c0c5ebe;
P_0c0c5ebe: /* original 3e3c, guest PC 0x0c0c5ebe */
if(!s->budget--) { s->failed_pc=0x0c0c5ebeu; return 0; }
r[14]+=r[3];
goto P_0c0c5ec0;
P_0c0c5ec0: /* original 62e2, guest PC 0x0c0c5ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0c5ec2;
P_0c0c5ec2: /* original 4f22, guest PC 0x0c0c5ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ec4;
P_0c0c5ec4: /* original 2228, guest PC 0x0c0c5ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c5ec6;
P_0c0c5ec6: /* original 8920, guest PC 0x0c0c5ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ec8;
P_0c0c5ec8: /* original d217, guest PC 0x0c0c5ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec8u; return 0; }
r[2]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5eca;
P_0c0c5eca: /* original 61e2, guest PC 0x0c0c5eca */
if(!s->budget--) { s->failed_pc=0x0c0c5ecau; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c5ecc;
P_0c0c5ecc: /* original 6022, guest PC 0x0c0c5ecc */
if(!s->budget--) { s->failed_pc=0x0c0c5eccu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0c5ece;
P_0c0c5ece: /* original 3010, guest PC 0x0c0c5ece */
if(!s->budget--) { s->failed_pc=0x0c0c5eceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0c5ed0;
P_0c0c5ed0: /* original 891b, guest PC 0x0c0c5ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ed2;
P_0c0c5ed2: /* original d317, guest PC 0x0c0c5ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed2u; return 0; }
r[3]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ed4;
P_0c0c5ed4: /* original d115, guest PC 0x0c0c5ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed4u; return 0; }
r[1]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ed6;
P_0c0c5ed6: /* original 6532, guest PC 0x0c0c5ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c5ed8;
P_0c0c5ed8: /* original d216, guest PC 0x0c0c5ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed8u; return 0; }
r[2]=read(ram,0x0c0c5f34u,4);
goto P_0c0c5eda;
P_0c0c5eda: /* original 351c, guest PC 0x0c0c5eda */
if(!s->budget--) { s->failed_pc=0x0c0c5edau; return 0; }
r[5]+=r[1];
goto P_0c0c5edc;
P_0c0c5edc: /* original 420b, guest PC 0x0c0c5edc */
if(!s->budget--) { s->failed_pc=0x0c0c5edcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5ee0u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee0u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee0;
P_0c0c5ede: /* original 64e2, guest PC 0x0c0c5ede */
if(!s->budget--) { s->failed_pc=0x0c0c5edeu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c5ee0;
P_0c0c5ee0: /* original d30e, guest PC 0x0c0c5ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee0u; return 0; }
r[3]=read(ram,0x0c0c5f1cu,4);
goto P_0c0c5ee2;
P_0c0c5ee2: /* original 430b, guest PC 0x0c0c5ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5ee6u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee6u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee6;
P_0c0c5ee4: /* original e404, guest PC 0x0c0c5ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee4u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5ee6;
P_0c0c5ee6: /* original d212, guest PC 0x0c0c5ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee6u; return 0; }
r[2]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ee8;
P_0c0c5ee8: /* original e504, guest PC 0x0c0c5ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee8u; return 0; }
r[5]=0x00000004u;
goto P_0c0c5eea;
P_0c0c5eea: /* original d113, guest PC 0x0c0c5eea */
if(!s->budget--) { s->failed_pc=0x0c0c5eeau; return 0; }
r[1]=read(ram,0x0c0c5f38u,4);
goto P_0c0c5eec;
P_0c0c5eec: /* original 6422, guest PC 0x0c0c5eec */
if(!s->budget--) { s->failed_pc=0x0c0c5eecu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c5eee;
P_0c0c5eee: /* original d30f, guest PC 0x0c0c5eee */
if(!s->budget--) { s->failed_pc=0x0c0c5eeeu; return 0; }
r[3]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ef0;
P_0c0c5ef0: /* original 410b, guest PC 0x0c0c5ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef0u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c5ef4u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ef4u) { target=s->pc; goto dispatch; }
goto P_0c0c5ef4;
P_0c0c5ef2: /* original 343c, guest PC 0x0c0c5ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef2u; return 0; }
r[4]+=r[3];
goto P_0c0c5ef4;
P_0c0c5ef4: /* original 2008, guest PC 0x0c0c5ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c5ef6;
P_0c0c5ef6: /* original 8903, guest PC 0x0c0c5ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f00; }
goto P_0c0c5ef8;
P_0c0c5ef8: /* original d210, guest PC 0x0c0c5ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef8u; return 0; }
r[2]=read(ram,0x0c0c5f3cu,4);
goto P_0c0c5efa;
P_0c0c5efa: /* original 950a, guest PC 0x0c0c5efa */
if(!s->budget--) { s->failed_pc=0x0c0c5efau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5f12u,2);
goto P_0c0c5efc;
P_0c0c5efc: /* original 420b, guest PC 0x0c0c5efc */
if(!s->budget--) { s->failed_pc=0x0c0c5efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5f00u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5f00u) { target=s->pc; goto dispatch; }
goto P_0c0c5f00;
P_0c0c5efe: /* original e401, guest PC 0x0c0c5efe */
if(!s->budget--) { s->failed_pc=0x0c0c5efeu; return 0; }
r[4]=0x00000001u;
goto P_0c0c5f00;
P_0c0c5f00: /* original d008, guest PC 0x0c0c5f00 */
if(!s->budget--) { s->failed_pc=0x0c0c5f00u; return 0; }
r[0]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5f02;
P_0c0c5f02: /* original 4d08, guest PC 0x0c0c5f02 */
if(!s->budget--) { s->failed_pc=0x0c0c5f02u; return 0; }
r[13]<<=2;
goto P_0c0c5f04;
P_0c0c5f04: /* original d308, guest PC 0x0c0c5f04 */
if(!s->budget--) { s->failed_pc=0x0c0c5f04u; return 0; }
r[3]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5f06;
P_0c0c5f06: /* original 02de, guest PC 0x0c0c5f06 */
if(!s->budget--) { s->failed_pc=0x0c0c5f06u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0c5f08;
P_0c0c5f08: /* original 2322, guest PC 0x0c0c5f08 */
if(!s->budget--) { s->failed_pc=0x0c0c5f08u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0c5f0a;
P_0c0c5f0a: /* original 4f26, guest PC 0x0c0c5f0a */
if(!s->budget--) { s->failed_pc=0x0c0c5f0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5f0c;
P_0c0c5f0c: /* original 6df6, guest PC 0x0c0c5f0c */
if(!s->budget--) { s->failed_pc=0x0c0c5f0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5f0e;
P_0c0c5f0e: /* original 000b, guest PC 0x0c0c5f0e */
if(!s->budget--) { s->failed_pc=0x0c0c5f0eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5f10: /* original 6ef6, guest PC 0x0c0c5f10 */
if(!s->budget--) { s->failed_pc=0x0c0c5f10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5f12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5f12u; return 0; } return 1;
P_0c0c61a8: /* original 2fe6, guest PC 0x0c0c61a8 */
if(!s->budget--) { s->failed_pc=0x0c0c61a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61aa;
P_0c0c61aa: /* original 4411, guest PC 0x0c0c61aa */
if(!s->budget--) { s->failed_pc=0x0c0c61aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c61ac;
P_0c0c61ac: /* original 2fd6, guest PC 0x0c0c61ac */
if(!s->budget--) { s->failed_pc=0x0c0c61acu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61ae;
P_0c0c61ae: /* original 2fc6, guest PC 0x0c0c61ae */
if(!s->budget--) { s->failed_pc=0x0c0c61aeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b0;
P_0c0c61b0: /* original 2fb6, guest PC 0x0c0c61b0 */
if(!s->budget--) { s->failed_pc=0x0c0c61b0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b2;
P_0c0c61b2: /* original 2fa6, guest PC 0x0c0c61b2 */
if(!s->budget--) { s->failed_pc=0x0c0c61b2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b4;
P_0c0c61b4: /* original 2f96, guest PC 0x0c0c61b4 */
if(!s->budget--) { s->failed_pc=0x0c0c61b4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b6;
P_0c0c61b6: /* original 2f86, guest PC 0x0c0c61b6 */
if(!s->budget--) { s->failed_pc=0x0c0c61b6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b8;
P_0c0c61b8: /* original 4f22, guest PC 0x0c0c61b8 */
if(!s->budget--) { s->failed_pc=0x0c0c61b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c61ba;
P_0c0c61ba: /* original 7ffc, guest PC 0x0c0c61ba */
if(!s->budget--) { s->failed_pc=0x0c0c61bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c61bc;
P_0c0c61bc: /* original 8b41, guest PC 0x0c0c61bc */
if(!s->budget--) { s->failed_pc=0x0c0c61bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6242; }
goto P_0c0c61be;
P_0c0c61be: /* original 924a, guest PC 0x0c0c61be */
if(!s->budget--) { s->failed_pc=0x0c0c61beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6256u,2);
goto P_0c0c61c0;
P_0c0c61c0: /* original 3423, guest PC 0x0c0c61c0 */
if(!s->budget--) { s->failed_pc=0x0c0c61c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c61c2;
P_0c0c61c2: /* original 893e, guest PC 0x0c0c61c2 */
if(!s->budget--) { s->failed_pc=0x0c0c61c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6242; }
goto P_0c0c61c4;
P_0c0c61c4: /* original d325, guest PC 0x0c0c61c4 */
if(!s->budget--) { s->failed_pc=0x0c0c61c4u; return 0; }
r[3]=read(ram,0x0c0c625cu,4);
goto P_0c0c61c6;
P_0c0c61c6: /* original 6143, guest PC 0x0c0c61c6 */
if(!s->budget--) { s->failed_pc=0x0c0c61c6u; return 0; }
r[1]=r[4];
goto P_0c0c61c8;
P_0c0c61c8: /* original 4108, guest PC 0x0c0c61c8 */
if(!s->budget--) { s->failed_pc=0x0c0c61c8u; return 0; }
r[1]<<=2;
goto P_0c0c61ca;
P_0c0c61ca: /* original 313c, guest PC 0x0c0c61ca */
if(!s->budget--) { s->failed_pc=0x0c0c61cau; return 0; }
r[1]+=r[3];
goto P_0c0c61cc;
P_0c0c61cc: /* original 2f12, guest PC 0x0c0c61cc */
if(!s->budget--) { s->failed_pc=0x0c0c61ccu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c61ce;
P_0c0c61ce: /* original 6212, guest PC 0x0c0c61ce */
if(!s->budget--) { s->failed_pc=0x0c0c61ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c61d0;
P_0c0c61d0: /* original 4211, guest PC 0x0c0c61d0 */
if(!s->budget--) { s->failed_pc=0x0c0c61d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c61d2;
P_0c0c61d2: /* original 8b36, guest PC 0x0c0c61d2 */
if(!s->budget--) { s->failed_pc=0x0c0c61d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6242; }
goto P_0c0c61d4;
P_0c0c61d4: /* original da23, guest PC 0x0c0c61d4 */
if(!s->budget--) { s->failed_pc=0x0c0c61d4u; return 0; }
r[10]=read(ram,0x0c0c6264u,4);
goto P_0c0c61d6;
P_0c0c61d6: /* original ec00, guest PC 0x0c0c61d6 */
if(!s->budget--) { s->failed_pc=0x0c0c61d6u; return 0; }
r[12]=0x00000000u;
goto P_0c0c61d8;
P_0c0c61d8: /* original db23, guest PC 0x0c0c61d8 */
if(!s->budget--) { s->failed_pc=0x0c0c61d8u; return 0; }
r[11]=read(ram,0x0c0c6268u,4);
goto P_0c0c61da;
P_0c0c61da: /* original dd24, guest PC 0x0c0c61da */
if(!s->budget--) { s->failed_pc=0x0c0c61dau; return 0; }
r[13]=read(ram,0x0c0c626cu,4);
goto P_0c0c61dc;
P_0c0c61dc: /* original d920, guest PC 0x0c0c61dc */
if(!s->budget--) { s->failed_pc=0x0c0c61dcu; return 0; }
r[9]=read(ram,0x0c0c6260u,4);
goto P_0c0c61de;
P_0c0c61de: /* original 983b, guest PC 0x0c0c61de */
if(!s->budget--) { s->failed_pc=0x0c0c61deu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6258u,2);
goto P_0c0c61e0;
P_0c0c61e0: /* original 6ec3, guest PC 0x0c0c61e0 */
if(!s->budget--) { s->failed_pc=0x0c0c61e0u; return 0; }
r[14]=r[12];
goto P_0c0c61e2;
P_0c0c61e2: /* original 4e08, guest PC 0x0c0c61e2 */
if(!s->budget--) { s->failed_pc=0x0c0c61e2u; return 0; }
r[14]<<=2;
goto P_0c0c61e4;
P_0c0c61e4: /* original 4e00, guest PC 0x0c0c61e4 */
if(!s->budget--) { s->failed_pc=0x0c0c61e4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c61e6;
P_0c0c61e6: /* original 3ebc, guest PC 0x0c0c61e6 */
if(!s->budget--) { s->failed_pc=0x0c0c61e6u; return 0; }
r[14]+=r[11];
goto P_0c0c61e8;
P_0c0c61e8: /* original 53e1, guest PC 0x0c0c61e8 */
if(!s->budget--) { s->failed_pc=0x0c0c61e8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c61ea;
P_0c0c61ea: /* original 2338, guest PC 0x0c0c61ea */
if(!s->budget--) { s->failed_pc=0x0c0c61eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c61ec;
P_0c0c61ec: /* original 8929, guest PC 0x0c0c61ec */
if(!s->budget--) { s->failed_pc=0x0c0c61ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6242; }
goto P_0c0c61ee;
P_0c0c61ee: /* original 52e1, guest PC 0x0c0c61ee */
if(!s->budget--) { s->failed_pc=0x0c0c61eeu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c61f0;
P_0c0c61f0: /* original 3420, guest PC 0x0c0c61f0 */
if(!s->budget--) { s->failed_pc=0x0c0c61f0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c61f2;
P_0c0c61f2: /* original 8b24, guest PC 0x0c0c61f2 */
if(!s->budget--) { s->failed_pc=0x0c0c61f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c623e; }
goto P_0c0c61f4;
P_0c0c61f4: /* original 6392, guest PC 0x0c0c61f4 */
if(!s->budget--) { s->failed_pc=0x0c0c61f4u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0c61f6;
P_0c0c61f6: /* original 61e2, guest PC 0x0c0c61f6 */
if(!s->budget--) { s->failed_pc=0x0c0c61f6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c61f8;
P_0c0c61f8: /* original 3310, guest PC 0x0c0c61f8 */
if(!s->budget--) { s->failed_pc=0x0c0c61f8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0c61fa;
P_0c0c61fa: /* original 891a, guest PC 0x0c0c61fa */
if(!s->budget--) { s->failed_pc=0x0c0c61fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6232; }
goto P_0c0c61fc;
P_0c0c61fc: /* original 65a2, guest PC 0x0c0c61fc */
if(!s->budget--) { s->failed_pc=0x0c0c61fcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c61fe;
P_0c0c61fe: /* original d31c, guest PC 0x0c0c61fe */
if(!s->budget--) { s->failed_pc=0x0c0c61feu; return 0; }
r[3]=read(ram,0x0c0c6270u,4);
goto P_0c0c6200;
P_0c0c6200: /* original 35dc, guest PC 0x0c0c6200 */
if(!s->budget--) { s->failed_pc=0x0c0c6200u; return 0; }
r[5]+=r[13];
goto P_0c0c6202;
P_0c0c6202: /* original 430b, guest PC 0x0c0c6202 */
if(!s->budget--) { s->failed_pc=0x0c0c6202u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6206u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6206u) { target=s->pc; goto dispatch; }
goto P_0c0c6206;
P_0c0c6204: /* original 64e2, guest PC 0x0c0c6204 */
if(!s->budget--) { s->failed_pc=0x0c0c6204u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c6206;
P_0c0c6206: /* original d41b, guest PC 0x0c0c6206 */
if(!s->budget--) { s->failed_pc=0x0c0c6206u; return 0; }
r[4]=read(ram,0x0c0c6274u,4);
goto P_0c0c6208;
P_0c0c6208: /* original bd44, guest PC 0x0c0c6208 */
if(!s->budget--) { s->failed_pc=0x0c0c6208u; return 0; }
target=code_base|0x0c0c5c94u; r[16]=code_base|0x0c0c620cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c620cu) { target=s->pc; goto dispatch; }
goto P_0c0c620c;
P_0c0c620a: /* original e500, guest PC 0x0c0c620a */
if(!s->budget--) { s->failed_pc=0x0c0c620au; return 0; }
r[5]=0x00000000u;
goto P_0c0c620c;
P_0c0c620c: /* original d31a, guest PC 0x0c0c620c */
if(!s->budget--) { s->failed_pc=0x0c0c620cu; return 0; }
r[3]=read(ram,0x0c0c6278u,4);
goto P_0c0c620e;
P_0c0c620e: /* original 430b, guest PC 0x0c0c620e */
if(!s->budget--) { s->failed_pc=0x0c0c620eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6212u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6212u) { target=s->pc; goto dispatch; }
goto P_0c0c6212;
P_0c0c6210: /* original e403, guest PC 0x0c0c6210 */
if(!s->budget--) { s->failed_pc=0x0c0c6210u; return 0; }
r[4]=0x00000003u;
goto P_0c0c6212;
P_0c0c6212: /* original d21a, guest PC 0x0c0c6212 */
if(!s->budget--) { s->failed_pc=0x0c0c6212u; return 0; }
r[2]=read(ram,0x0c0c627cu,4);
goto P_0c0c6214;
P_0c0c6214: /* original e503, guest PC 0x0c0c6214 */
if(!s->budget--) { s->failed_pc=0x0c0c6214u; return 0; }
r[5]=0x00000003u;
goto P_0c0c6216;
P_0c0c6216: /* original 64a2, guest PC 0x0c0c6216 */
if(!s->budget--) { s->failed_pc=0x0c0c6216u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c6218;
P_0c0c6218: /* original 420b, guest PC 0x0c0c6218 */
if(!s->budget--) { s->failed_pc=0x0c0c6218u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c621cu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c621cu) { target=s->pc; goto dispatch; }
goto P_0c0c621c;
P_0c0c621a: /* original 34dc, guest PC 0x0c0c621a */
if(!s->budget--) { s->failed_pc=0x0c0c621au; return 0; }
r[4]+=r[13];
goto P_0c0c621c;
P_0c0c621c: /* original 2008, guest PC 0x0c0c621c */
if(!s->budget--) { s->failed_pc=0x0c0c621cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c621e;
P_0c0c621e: /* original 8903, guest PC 0x0c0c621e */
if(!s->budget--) { s->failed_pc=0x0c0c621eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6228; }
goto P_0c0c6220;
P_0c0c6220: /* original d217, guest PC 0x0c0c6220 */
if(!s->budget--) { s->failed_pc=0x0c0c6220u; return 0; }
r[2]=read(ram,0x0c0c6280u,4);
goto P_0c0c6222;
P_0c0c6222: /* original 6583, guest PC 0x0c0c6222 */
if(!s->budget--) { s->failed_pc=0x0c0c6222u; return 0; }
r[5]=r[8];
goto P_0c0c6224;
P_0c0c6224: /* original 420b, guest PC 0x0c0c6224 */
if(!s->budget--) { s->failed_pc=0x0c0c6224u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6228u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6228u) { target=s->pc; goto dispatch; }
goto P_0c0c6228;
P_0c0c6226: /* original e401, guest PC 0x0c0c6226 */
if(!s->budget--) { s->failed_pc=0x0c0c6226u; return 0; }
r[4]=0x00000001u;
goto P_0c0c6228;
P_0c0c6228: /* original 4c08, guest PC 0x0c0c6228 */
if(!s->budget--) { s->failed_pc=0x0c0c6228u; return 0; }
r[12]<<=2;
goto P_0c0c622a;
P_0c0c622a: /* original 4c00, guest PC 0x0c0c622a */
if(!s->budget--) { s->failed_pc=0x0c0c622au; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c622c;
P_0c0c622c: /* original 3cbc, guest PC 0x0c0c622c */
if(!s->budget--) { s->failed_pc=0x0c0c622cu; return 0; }
r[12]+=r[11];
goto P_0c0c622e;
P_0c0c622e: /* original 63c2, guest PC 0x0c0c622e */
if(!s->budget--) { s->failed_pc=0x0c0c622eu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0c6230;
P_0c0c6230: /* original 2932, guest PC 0x0c0c6230 */
if(!s->budget--) { s->failed_pc=0x0c0c6230u; return 0; }
write(ram,r[9],r[3],4);
goto P_0c0c6232;
P_0c0c6232: /* original d314, guest PC 0x0c0c6232 */
if(!s->budget--) { s->failed_pc=0x0c0c6232u; return 0; }
r[3]=read(ram,0x0c0c6284u,4);
goto P_0c0c6234;
P_0c0c6234: /* original 64f2, guest PC 0x0c0c6234 */
if(!s->budget--) { s->failed_pc=0x0c0c6234u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c6236;
P_0c0c6236: /* original 430b, guest PC 0x0c0c6236 */
if(!s->budget--) { s->failed_pc=0x0c0c6236u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c623au;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c623au) { target=s->pc; goto dispatch; }
goto P_0c0c623a;
P_0c0c6238: /* original 6442, guest PC 0x0c0c6238 */
if(!s->budget--) { s->failed_pc=0x0c0c6238u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c623a;
P_0c0c623a: /* original a002, guest PC 0x0c0c623a */
if(!s->budget--) { s->failed_pc=0x0c0c623au; return 0; }
goto P_0c0c6242;
P_0c0c623c: /* original 0009, guest PC 0x0c0c623c */
if(!s->budget--) { s->failed_pc=0x0c0c623cu; return 0; }
goto P_0c0c623e;
P_0c0c623e: /* original afcf, guest PC 0x0c0c623e */
if(!s->budget--) { s->failed_pc=0x0c0c623eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0c61e0;
P_0c0c6240: /* original 7c01, guest PC 0x0c0c6240 */
if(!s->budget--) { s->failed_pc=0x0c0c6240u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c6242;
P_0c0c6242: /* original 7f04, guest PC 0x0c0c6242 */
if(!s->budget--) { s->failed_pc=0x0c0c6242u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c6244;
P_0c0c6244: /* original 4f26, guest PC 0x0c0c6244 */
if(!s->budget--) { s->failed_pc=0x0c0c6244u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c6246;
P_0c0c6246: /* original 68f6, guest PC 0x0c0c6246 */
if(!s->budget--) { s->failed_pc=0x0c0c6246u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c6248;
P_0c0c6248: /* original 69f6, guest PC 0x0c0c6248 */
if(!s->budget--) { s->failed_pc=0x0c0c6248u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c624a;
P_0c0c624a: /* original 6af6, guest PC 0x0c0c624a */
if(!s->budget--) { s->failed_pc=0x0c0c624au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c624c;
P_0c0c624c: /* original 6bf6, guest PC 0x0c0c624c */
if(!s->budget--) { s->failed_pc=0x0c0c624cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c624e;
P_0c0c624e: /* original 6cf6, guest PC 0x0c0c624e */
if(!s->budget--) { s->failed_pc=0x0c0c624eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c6250;
P_0c0c6250: /* original 6df6, guest PC 0x0c0c6250 */
if(!s->budget--) { s->failed_pc=0x0c0c6250u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c6252;
P_0c0c6252: /* original 000b, guest PC 0x0c0c6252 */
if(!s->budget--) { s->failed_pc=0x0c0c6252u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c6254: /* original 6ef6, guest PC 0x0c0c6254 */
if(!s->budget--) { s->failed_pc=0x0c0c6254u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c6256u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6256u; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c70a4: /* original d413, guest PC 0x0c0c70a4 */
if(!s->budget--) { s->failed_pc=0x0c0c70a4u; return 0; }
r[4]=read(ram,0x0c0c70f4u,4);
goto P_0c0c70a6;
P_0c0c70a6: /* original e01c, guest PC 0x0c0c70a6 */
if(!s->budget--) { s->failed_pc=0x0c0c70a6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c70a8;
P_0c0c70a8: /* original e50f, guest PC 0x0c0c70a8 */
if(!s->budget--) { s->failed_pc=0x0c0c70a8u; return 0; }
r[5]=0x0000000fu;
goto P_0c0c70aa;
P_0c0c70aa: /* original 044c, guest PC 0x0c0c70aa */
if(!s->budget--) { s->failed_pc=0x0c0c70aau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c70ac;
P_0c0c70ac: /* original d012, guest PC 0x0c0c70ac */
if(!s->budget--) { s->failed_pc=0x0c0c70acu; return 0; }
r[0]=read(ram,0x0c0c70f8u,4);
goto P_0c0c70ae;
P_0c0c70ae: /* original 644c, guest PC 0x0c0c70ae */
if(!s->budget--) { s->failed_pc=0x0c0c70aeu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c70b0;
P_0c0c70b0: /* original 2459, guest PC 0x0c0c70b0 */
if(!s->budget--) { s->failed_pc=0x0c0c70b0u; return 0; }
r[4]&=r[5];
goto P_0c0c70b2;
P_0c0c70b2: /* original 4408, guest PC 0x0c0c70b2 */
if(!s->budget--) { s->failed_pc=0x0c0c70b2u; return 0; }
r[4]<<=2;
goto P_0c0c70b4;
P_0c0c70b4: /* original 4408, guest PC 0x0c0c70b4 */
if(!s->budget--) { s->failed_pc=0x0c0c70b4u; return 0; }
r[4]<<=2;
goto P_0c0c70b6;
P_0c0c70b6: /* original 4408, guest PC 0x0c0c70b6 */
if(!s->budget--) { s->failed_pc=0x0c0c70b6u; return 0; }
r[4]<<=2;
goto P_0c0c70b8;
P_0c0c70b8: /* original 044c, guest PC 0x0c0c70b8 */
if(!s->budget--) { s->failed_pc=0x0c0c70b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c70ba;
P_0c0c70ba: /* original 644c, guest PC 0x0c0c70ba */
if(!s->budget--) { s->failed_pc=0x0c0c70bau; return 0; }
r[4]=r[4]&255u;
goto P_0c0c70bc;
P_0c0c70bc: /* original 3457, guest PC 0x0c0c70bc */
if(!s->budget--) { s->failed_pc=0x0c0c70bcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c0c70be;
P_0c0c70be: /* original 8b01, guest PC 0x0c0c70be */
if(!s->budget--) { s->failed_pc=0x0c0c70beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c70c4; }
goto P_0c0c70c0;
P_0c0c70c0: /* original a003, guest PC 0x0c0c70c0 */
if(!s->budget--) { s->failed_pc=0x0c0c70c0u; return 0; }
r[4]=r[5];
goto P_0c0c70ca;
P_0c0c70c2: /* original 6453, guest PC 0x0c0c70c2 */
if(!s->budget--) { s->failed_pc=0x0c0c70c2u; return 0; }
r[4]=r[5];
goto P_0c0c70c4;
P_0c0c70c4: /* original 4411, guest PC 0x0c0c70c4 */
if(!s->budget--) { s->failed_pc=0x0c0c70c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c70c6;
P_0c0c70c6: /* original 8900, guest PC 0x0c0c70c6 */
if(!s->budget--) { s->failed_pc=0x0c0c70c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c70ca; }
goto P_0c0c70c8;
P_0c0c70c8: /* original e400, guest PC 0x0c0c70c8 */
if(!s->budget--) { s->failed_pc=0x0c0c70c8u; return 0; }
r[4]=0x00000000u;
goto P_0c0c70ca;
P_0c0c70ca: /* original d20c, guest PC 0x0c0c70ca */
if(!s->budget--) { s->failed_pc=0x0c0c70cau; return 0; }
r[2]=read(ram,0x0c0c70fcu,4);
goto P_0c0c70cc;
P_0c0c70cc: /* original 4400, guest PC 0x0c0c70cc */
if(!s->budget--) { s->failed_pc=0x0c0c70ccu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c70ce;
P_0c0c70ce: /* original d60c, guest PC 0x0c0c70ce */
if(!s->budget--) { s->failed_pc=0x0c0c70ceu; return 0; }
r[6]=read(ram,0x0c0c7100u,4);
goto P_0c0c70d0;
P_0c0c70d0: /* original 6043, guest PC 0x0c0c70d0 */
if(!s->budget--) { s->failed_pc=0x0c0c70d0u; return 0; }
r[0]=r[4];
goto P_0c0c70d2;
P_0c0c70d2: /* original 910a, guest PC 0x0c0c70d2 */
if(!s->budget--) { s->failed_pc=0x0c0c70d2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c70eau,2);
goto P_0c0c70d4;
P_0c0c70d4: /* original 6522, guest PC 0x0c0c70d4 */
if(!s->budget--) { s->failed_pc=0x0c0c70d4u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c70d6;
P_0c0c70d6: /* original 036c, guest PC 0x0c0c70d6 */
if(!s->budget--) { s->failed_pc=0x0c0c70d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c70d8;
P_0c0c70d8: /* original 7001, guest PC 0x0c0c70d8 */
if(!s->budget--) { s->failed_pc=0x0c0c70d8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c70da;
P_0c0c70da: /* original 315c, guest PC 0x0c0c70da */
if(!s->budget--) { s->failed_pc=0x0c0c70dau; return 0; }
r[1]+=r[5];
goto P_0c0c70dc;
P_0c0c70dc: /* original 2130, guest PC 0x0c0c70dc */
if(!s->budget--) { s->failed_pc=0x0c0c70dcu; return 0; }
write(ram,r[1],r[3],1);
goto P_0c0c70de;
P_0c0c70de: /* original 036c, guest PC 0x0c0c70de */
if(!s->budget--) { s->failed_pc=0x0c0c70deu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c70e0;
P_0c0c70e0: /* original 9004, guest PC 0x0c0c70e0 */
if(!s->budget--) { s->failed_pc=0x0c0c70e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c70ecu,2);
goto P_0c0c70e2;
P_0c0c70e2: /* original 000b, guest PC 0x0c0c70e2 */
if(!s->budget--) { s->failed_pc=0x0c0c70e2u; return 0; }
target=r[16];
write(ram,r[5]+r[0],r[3],1);
s->pc=target; return ram->oob==0;
P_0c0c70e4: /* original 0534, guest PC 0x0c0c70e4 */
if(!s->budget--) { s->failed_pc=0x0c0c70e4u; return 0; }
write(ram,r[5]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c0c70e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c70e6u; return 0; } return 1;
P_0c0c7648: /* original 2fe6, guest PC 0x0c0c7648 */
if(!s->budget--) { s->failed_pc=0x0c0c7648u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764a;
P_0c0c764a: /* original 2fd6, guest PC 0x0c0c764a */
if(!s->budget--) { s->failed_pc=0x0c0c764au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764c;
P_0c0c764c: /* original 2fc6, guest PC 0x0c0c764c */
if(!s->budget--) { s->failed_pc=0x0c0c764cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764e;
P_0c0c764e: /* original 2fb6, guest PC 0x0c0c764e */
if(!s->budget--) { s->failed_pc=0x0c0c764eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7650;
P_0c0c7650: /* original 2fa6, guest PC 0x0c0c7650 */
if(!s->budget--) { s->failed_pc=0x0c0c7650u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7652;
P_0c0c7652: /* original 2f96, guest PC 0x0c0c7652 */
if(!s->budget--) { s->failed_pc=0x0c0c7652u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7654;
P_0c0c7654: /* original da40, guest PC 0x0c0c7654 */
if(!s->budget--) { s->failed_pc=0x0c0c7654u; return 0; }
r[10]=read(ram,0x0c0c7758u,4);
goto P_0c0c7656;
P_0c0c7656: /* original 9077, guest PC 0x0c0c7656 */
if(!s->budget--) { s->failed_pc=0x0c0c7656u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7748u,2);
goto P_0c0c7658;
P_0c0c7658: /* original 4f22, guest PC 0x0c0c7658 */
if(!s->budget--) { s->failed_pc=0x0c0c7658u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c765a;
P_0c0c765a: /* original 0cae, guest PC 0x0c0c765a */
if(!s->budget--) { s->failed_pc=0x0c0c765au; return 0; }
r[12]=read(ram,r[10]+r[0],4);
goto P_0c0c765c;
P_0c0c765c: /* original 7004, guest PC 0x0c0c765c */
if(!s->budget--) { s->failed_pc=0x0c0c765cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c765e;
P_0c0c765e: /* original dd3f, guest PC 0x0c0c765e */
if(!s->budget--) { s->failed_pc=0x0c0c765eu; return 0; }
r[13]=read(ram,0x0c0c775cu,4);
goto P_0c0c7660;
P_0c0c7660: /* original 2cc8, guest PC 0x0c0c7660 */
if(!s->budget--) { s->failed_pc=0x0c0c7660u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c7662;
P_0c0c7662: /* original 8d0e, guest PC 0x0c0c7662 */
if(!s->budget--) { s->failed_pc=0x0c0c7662u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c0c7682; }
goto P_0c0c7666;
P_0c0c7664: /* original 0bae, guest PC 0x0c0c7664 */
if(!s->budget--) { s->failed_pc=0x0c0c7664u; return 0; }
r[11]=read(ram,r[10]+r[0],4);
goto P_0c0c7666;
P_0c0c7666: /* original 85c6, guest PC 0x0c0c7666 */
if(!s->budget--) { s->failed_pc=0x0c0c7666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7668;
P_0c0c7668: /* original 996f, guest PC 0x0c0c7668 */
if(!s->budget--) { s->failed_pc=0x0c0c7668u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774au,2);
goto P_0c0c766a;
P_0c0c766a: /* original 6e0d, guest PC 0x0c0c766a */
if(!s->budget--) { s->failed_pc=0x0c0c766au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c766c;
P_0c0c766c: /* original 4e15, guest PC 0x0c0c766c */
if(!s->budget--) { s->failed_pc=0x0c0c766cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c766e;
P_0c0c766e: /* original 8b05, guest PC 0x0c0c766e */
if(!s->budget--) { s->failed_pc=0x0c0c766eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c767c; }
goto P_0c0c7670;
P_0c0c7670: /* original 6493, guest PC 0x0c0c7670 */
if(!s->budget--) { s->failed_pc=0x0c0c7670u; return 0; }
r[4]=r[9];
goto P_0c0c7672;
P_0c0c7672: /* original 4d0b, guest PC 0x0c0c7672 */
if(!s->budget--) { s->failed_pc=0x0c0c7672u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7676u;
r[9]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7676u) { target=s->pc; goto dispatch; }
goto P_0c0c7676;
P_0c0c7674: /* original 7901, guest PC 0x0c0c7674 */
if(!s->budget--) { s->failed_pc=0x0c0c7674u; return 0; }
r[9]+=0x00000001u;
goto P_0c0c7676;
P_0c0c7676: /* original 7eff, guest PC 0x0c0c7676 */
if(!s->budget--) { s->failed_pc=0x0c0c7676u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7678;
P_0c0c7678: /* original 4e15, guest PC 0x0c0c7678 */
if(!s->budget--) { s->failed_pc=0x0c0c7678u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c767a;
P_0c0c767a: /* original 89f9, guest PC 0x0c0c767a */
if(!s->budget--) { s->failed_pc=0x0c0c767au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7670; }
goto P_0c0c767c;
P_0c0c767c: /* original d338, guest PC 0x0c0c767c */
if(!s->budget--) { s->failed_pc=0x0c0c767cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c767e;
P_0c0c767e: /* original 430b, guest PC 0x0c0c767e */
if(!s->budget--) { s->failed_pc=0x0c0c767eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7682u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7682u) { target=s->pc; goto dispatch; }
goto P_0c0c7682;
P_0c0c7680: /* original 64c3, guest PC 0x0c0c7680 */
if(!s->budget--) { s->failed_pc=0x0c0c7680u; return 0; }
r[4]=r[12];
goto P_0c0c7682;
P_0c0c7682: /* original 2bb8, guest PC 0x0c0c7682 */
if(!s->budget--) { s->failed_pc=0x0c0c7682u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c7684;
P_0c0c7684: /* original 890d, guest PC 0x0c0c7684 */
if(!s->budget--) { s->failed_pc=0x0c0c7684u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c76a2; }
goto P_0c0c7686;
P_0c0c7686: /* original 85b6, guest PC 0x0c0c7686 */
if(!s->budget--) { s->failed_pc=0x0c0c7686u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+12,2);
goto P_0c0c7688;
P_0c0c7688: /* original 9c60, guest PC 0x0c0c7688 */
if(!s->budget--) { s->failed_pc=0x0c0c7688u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774cu,2);
goto P_0c0c768a;
P_0c0c768a: /* original 6e0d, guest PC 0x0c0c768a */
if(!s->budget--) { s->failed_pc=0x0c0c768au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c768c;
P_0c0c768c: /* original 4e15, guest PC 0x0c0c768c */
if(!s->budget--) { s->failed_pc=0x0c0c768cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c768e;
P_0c0c768e: /* original 8b05, guest PC 0x0c0c768e */
if(!s->budget--) { s->failed_pc=0x0c0c768eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c769c; }
goto P_0c0c7690;
P_0c0c7690: /* original 64c3, guest PC 0x0c0c7690 */
if(!s->budget--) { s->failed_pc=0x0c0c7690u; return 0; }
r[4]=r[12];
goto P_0c0c7692;
P_0c0c7692: /* original 4d0b, guest PC 0x0c0c7692 */
if(!s->budget--) { s->failed_pc=0x0c0c7692u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7696u;
r[12]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7696u) { target=s->pc; goto dispatch; }
goto P_0c0c7696;
P_0c0c7694: /* original 7c01, guest PC 0x0c0c7694 */
if(!s->budget--) { s->failed_pc=0x0c0c7694u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c7696;
P_0c0c7696: /* original 7eff, guest PC 0x0c0c7696 */
if(!s->budget--) { s->failed_pc=0x0c0c7696u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7698;
P_0c0c7698: /* original 4e15, guest PC 0x0c0c7698 */
if(!s->budget--) { s->failed_pc=0x0c0c7698u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c769a;
P_0c0c769a: /* original 89f9, guest PC 0x0c0c769a */
if(!s->budget--) { s->failed_pc=0x0c0c769au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7690; }
goto P_0c0c769c;
P_0c0c769c: /* original d330, guest PC 0x0c0c769c */
if(!s->budget--) { s->failed_pc=0x0c0c769cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c769e;
P_0c0c769e: /* original 430b, guest PC 0x0c0c769e */
if(!s->budget--) { s->failed_pc=0x0c0c769eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c76a2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c76a2u) { target=s->pc; goto dispatch; }
goto P_0c0c76a2;
P_0c0c76a0: /* original 64b3, guest PC 0x0c0c76a0 */
if(!s->budget--) { s->failed_pc=0x0c0c76a0u; return 0; }
r[4]=r[11];
goto P_0c0c76a2;
P_0c0c76a2: /* original 9054, guest PC 0x0c0c76a2 */
if(!s->budget--) { s->failed_pc=0x0c0c76a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774eu,2);
goto P_0c0c76a4;
P_0c0c76a4: /* original e400, guest PC 0x0c0c76a4 */
if(!s->budget--) { s->failed_pc=0x0c0c76a4u; return 0; }
r[4]=0x00000000u;
goto P_0c0c76a6;
P_0c0c76a6: /* original 4f26, guest PC 0x0c0c76a6 */
if(!s->budget--) { s->failed_pc=0x0c0c76a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c76a8;
P_0c0c76a8: /* original 0a46, guest PC 0x0c0c76a8 */
if(!s->budget--) { s->failed_pc=0x0c0c76a8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76aa;
P_0c0c76aa: /* original 70f8, guest PC 0x0c0c76aa */
if(!s->budget--) { s->failed_pc=0x0c0c76aau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c76ac;
P_0c0c76ac: /* original 0a46, guest PC 0x0c0c76ac */
if(!s->budget--) { s->failed_pc=0x0c0c76acu; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76ae;
P_0c0c76ae: /* original 7004, guest PC 0x0c0c76ae */
if(!s->budget--) { s->failed_pc=0x0c0c76aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c76b0;
P_0c0c76b0: /* original 0a46, guest PC 0x0c0c76b0 */
if(!s->budget--) { s->failed_pc=0x0c0c76b0u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76b2;
P_0c0c76b2: /* original 69f6, guest PC 0x0c0c76b2 */
if(!s->budget--) { s->failed_pc=0x0c0c76b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c76b4;
P_0c0c76b4: /* original 6af6, guest PC 0x0c0c76b4 */
if(!s->budget--) { s->failed_pc=0x0c0c76b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c76b6;
P_0c0c76b6: /* original 6bf6, guest PC 0x0c0c76b6 */
if(!s->budget--) { s->failed_pc=0x0c0c76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c76b8;
P_0c0c76b8: /* original 6cf6, guest PC 0x0c0c76b8 */
if(!s->budget--) { s->failed_pc=0x0c0c76b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c76ba;
P_0c0c76ba: /* original 6df6, guest PC 0x0c0c76ba */
if(!s->budget--) { s->failed_pc=0x0c0c76bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c76bc;
P_0c0c76bc: /* original 000b, guest PC 0x0c0c76bc */
if(!s->budget--) { s->failed_pc=0x0c0c76bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c76be: /* original 6ef6, guest PC 0x0c0c76be */
if(!s->budget--) { s->failed_pc=0x0c0c76beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c76c0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
