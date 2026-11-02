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
int vf3_away_batch25_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2e86u: goto P_0c0a2e86;
case 0x0c0a2e88u: goto P_0c0a2e88;
case 0x0c0a2e8au: goto P_0c0a2e8a;
case 0x0c0a2e8cu: goto P_0c0a2e8c;
case 0x0c0a2e8eu: goto P_0c0a2e8e;
case 0x0c0a2e90u: goto P_0c0a2e90;
case 0x0c0a2e92u: goto P_0c0a2e92;
case 0x0c0a2e94u: goto P_0c0a2e94;
case 0x0c0a2e96u: goto P_0c0a2e96;
case 0x0c0a2e98u: goto P_0c0a2e98;
case 0x0c0a2e9au: goto P_0c0a2e9a;
case 0x0c0a2e9cu: goto P_0c0a2e9c;
case 0x0c0a2e9eu: goto P_0c0a2e9e;
case 0x0c0a2ea0u: goto P_0c0a2ea0;
case 0x0c0a2ea2u: goto P_0c0a2ea2;
case 0x0c0a2ea4u: goto P_0c0a2ea4;
case 0x0c0a2ea6u: goto P_0c0a2ea6;
case 0x0c0a2ea8u: goto P_0c0a2ea8;
case 0x0c0a2eaau: goto P_0c0a2eaa;
case 0x0c0a2eacu: goto P_0c0a2eac;
case 0x0c0a2eaeu: goto P_0c0a2eae;
case 0x0c0a2eb0u: goto P_0c0a2eb0;
case 0x0c0a2eb2u: goto P_0c0a2eb2;
case 0x0c0a2eb4u: goto P_0c0a2eb4;
case 0x0c0a2eb6u: goto P_0c0a2eb6;
case 0x0c0a2eb8u: goto P_0c0a2eb8;
case 0x0c0a2ebau: goto P_0c0a2eba;
case 0x0c0a2ebcu: goto P_0c0a2ebc;
case 0x0c0a2ebeu: goto P_0c0a2ebe;
case 0x0c0a2ec0u: goto P_0c0a2ec0;
case 0x0c0a2ec2u: goto P_0c0a2ec2;
case 0x0c0a2ec4u: goto P_0c0a2ec4;
case 0x0c0a2ec6u: goto P_0c0a2ec6;
case 0x0c0a2ec8u: goto P_0c0a2ec8;
case 0x0c0a2ecau: goto P_0c0a2eca;
case 0x0c0a2eccu: goto P_0c0a2ecc;
case 0x0c0a2eceu: goto P_0c0a2ece;
case 0x0c0a2ed0u: goto P_0c0a2ed0;
case 0x0c0a71acu: goto P_0c0a71ac;
case 0x0c0a71aeu: goto P_0c0a71ae;
case 0x0c0a71b0u: goto P_0c0a71b0;
case 0x0c0a71b2u: goto P_0c0a71b2;
case 0x0c0a71b4u: goto P_0c0a71b4;
case 0x0c0a71b6u: goto P_0c0a71b6;
case 0x0c0a71b8u: goto P_0c0a71b8;
case 0x0c0a71bau: goto P_0c0a71ba;
case 0x0c0a71bcu: goto P_0c0a71bc;
case 0x0c0a71beu: goto P_0c0a71be;
case 0x0c0a71c0u: goto P_0c0a71c0;
case 0x0c0a71c2u: goto P_0c0a71c2;
case 0x0c0a71c4u: goto P_0c0a71c4;
case 0x0c0a71c6u: goto P_0c0a71c6;
case 0x0c0a71c8u: goto P_0c0a71c8;
case 0x0c0a71cau: goto P_0c0a71ca;
case 0x0c0a71ccu: goto P_0c0a71cc;
case 0x0c0a71ceu: goto P_0c0a71ce;
case 0x0c0a71d0u: goto P_0c0a71d0;
case 0x0c0a71d2u: goto P_0c0a71d2;
case 0x0c0a7204u: goto P_0c0a7204;
case 0x0c0a7206u: goto P_0c0a7206;
case 0x0c0a7208u: goto P_0c0a7208;
case 0x0c0a720au: goto P_0c0a720a;
case 0x0c0a720cu: goto P_0c0a720c;
case 0x0c0a720eu: goto P_0c0a720e;
case 0x0c0a7210u: goto P_0c0a7210;
case 0x0c0a7212u: goto P_0c0a7212;
case 0x0c0a7214u: goto P_0c0a7214;
case 0x0c0a7216u: goto P_0c0a7216;
case 0x0c0a7218u: goto P_0c0a7218;
case 0x0c0a7250u: goto P_0c0a7250;
case 0x0c0a7252u: goto P_0c0a7252;
case 0x0c0a7254u: goto P_0c0a7254;
case 0x0c0a7256u: goto P_0c0a7256;
case 0x0c0a7258u: goto P_0c0a7258;
case 0x0c0a725au: goto P_0c0a725a;
case 0x0c0a725cu: goto P_0c0a725c;
case 0x0c0a725eu: goto P_0c0a725e;
case 0x0c0a7260u: goto P_0c0a7260;
case 0x0c0a7262u: goto P_0c0a7262;
case 0x0c0a7442u: goto P_0c0a7442;
case 0x0c0a7444u: goto P_0c0a7444;
case 0x0c0a7446u: goto P_0c0a7446;
case 0x0c0a7448u: goto P_0c0a7448;
case 0x0c0a744au: goto P_0c0a744a;
case 0x0c0a744cu: goto P_0c0a744c;
case 0x0c0a744eu: goto P_0c0a744e;
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
case 0x0c0a7794u: goto P_0c0a7794;
case 0x0c0a7796u: goto P_0c0a7796;
case 0x0c0a7798u: goto P_0c0a7798;
case 0x0c0a779au: goto P_0c0a779a;
case 0x0c0a779cu: goto P_0c0a779c;
case 0x0c0a779eu: goto P_0c0a779e;
case 0x0c0a77a0u: goto P_0c0a77a0;
case 0x0c0a77a2u: goto P_0c0a77a2;
case 0x0c0a77a4u: goto P_0c0a77a4;
case 0x0c0a77a6u: goto P_0c0a77a6;
case 0x0c0a77a8u: goto P_0c0a77a8;
case 0x0c0a77aau: goto P_0c0a77aa;
case 0x0c0a77acu: goto P_0c0a77ac;
case 0x0c0a77aeu: goto P_0c0a77ae;
case 0x0c0a77b0u: goto P_0c0a77b0;
case 0x0c0a77b2u: goto P_0c0a77b2;
case 0x0c0a77b4u: goto P_0c0a77b4;
case 0x0c0a77b6u: goto P_0c0a77b6;
case 0x0c0a77b8u: goto P_0c0a77b8;
case 0x0c0a77bau: goto P_0c0a77ba;
case 0x0c0a77bcu: goto P_0c0a77bc;
case 0x0c0a77beu: goto P_0c0a77be;
case 0x0c0a77c0u: goto P_0c0a77c0;
case 0x0c0a77c2u: goto P_0c0a77c2;
case 0x0c0a77c4u: goto P_0c0a77c4;
case 0x0c0a77c6u: goto P_0c0a77c6;
case 0x0c0a77c8u: goto P_0c0a77c8;
case 0x0c0a77cau: goto P_0c0a77ca;
case 0x0c0a77ccu: goto P_0c0a77cc;
case 0x0c0a77ceu: goto P_0c0a77ce;
case 0x0c0a77d0u: goto P_0c0a77d0;
case 0x0c0a77d2u: goto P_0c0a77d2;
case 0x0c0a77d4u: goto P_0c0a77d4;
case 0x0c0a77d6u: goto P_0c0a77d6;
case 0x0c0a77d8u: goto P_0c0a77d8;
case 0x0c0a77dau: goto P_0c0a77da;
case 0x0c0a77dcu: goto P_0c0a77dc;
case 0x0c0a77e2u: goto P_0c0a77e2;
case 0x0c0a77e4u: goto P_0c0a77e4;
case 0x0c0a77e6u: goto P_0c0a77e6;
case 0x0c0a77e8u: goto P_0c0a77e8;
case 0x0c0a77eau: goto P_0c0a77ea;
case 0x0c0a77ecu: goto P_0c0a77ec;
case 0x0c0a77eeu: goto P_0c0a77ee;
case 0x0c0a77f0u: goto P_0c0a77f0;
case 0x0c0a77f2u: goto P_0c0a77f2;
case 0x0c0a77f4u: goto P_0c0a77f4;
case 0x0c0a77f6u: goto P_0c0a77f6;
case 0x0c0a77f8u: goto P_0c0a77f8;
case 0x0c0a77fau: goto P_0c0a77fa;
case 0x0c0a77fcu: goto P_0c0a77fc;
case 0x0c0a77feu: goto P_0c0a77fe;
case 0x0c0a7800u: goto P_0c0a7800;
case 0x0c0a7802u: goto P_0c0a7802;
case 0x0c0a7804u: goto P_0c0a7804;
case 0x0c0a7806u: goto P_0c0a7806;
case 0x0c0a7808u: goto P_0c0a7808;
case 0x0c0a780au: goto P_0c0a780a;
case 0x0c0a780cu: goto P_0c0a780c;
case 0x0c0a780eu: goto P_0c0a780e;
case 0x0c0a7810u: goto P_0c0a7810;
case 0x0c0a7812u: goto P_0c0a7812;
case 0x0c0a7814u: goto P_0c0a7814;
case 0x0c0a7816u: goto P_0c0a7816;
case 0x0c0a7818u: goto P_0c0a7818;
case 0x0c0a781au: goto P_0c0a781a;
case 0x0c0a781cu: goto P_0c0a781c;
case 0x0c0a781eu: goto P_0c0a781e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2e86: /* original 2fe6, guest PC 0x0c0a2e86 */
if(!s->budget--) { s->failed_pc=0x0c0a2e86u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2e88;
P_0c0a2e88: /* original 4411, guest PC 0x0c0a2e88 */
if(!s->budget--) { s->failed_pc=0x0c0a2e88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a2e8a;
P_0c0a2e8a: /* original 2fd6, guest PC 0x0c0a2e8a */
if(!s->budget--) { s->failed_pc=0x0c0a2e8au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2e8c;
P_0c0a2e8c: /* original 4f22, guest PC 0x0c0a2e8c */
if(!s->budget--) { s->failed_pc=0x0c0a2e8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2e8e;
P_0c0a2e8e: /* original 8b1c, guest PC 0x0c0a2e8e */
if(!s->budget--) { s->failed_pc=0x0c0a2e8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2eca; }
goto P_0c0a2e90;
P_0c0a2e90: /* original e21a, guest PC 0x0c0a2e90 */
if(!s->budget--) { s->failed_pc=0x0c0a2e90u; return 0; }
r[2]=0x0000001au;
goto P_0c0a2e92;
P_0c0a2e92: /* original 3423, guest PC 0x0c0a2e92 */
if(!s->budget--) { s->failed_pc=0x0c0a2e92u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0a2e94;
P_0c0a2e94: /* original 8919, guest PC 0x0c0a2e94 */
if(!s->budget--) { s->failed_pc=0x0c0a2e94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2eca; }
goto P_0c0a2e96;
P_0c0a2e96: /* original 6e43, guest PC 0x0c0a2e96 */
if(!s->budget--) { s->failed_pc=0x0c0a2e96u; return 0; }
r[14]=r[4];
goto P_0c0a2e98;
P_0c0a2e98: /* original 4e08, guest PC 0x0c0a2e98 */
if(!s->budget--) { s->failed_pc=0x0c0a2e98u; return 0; }
r[14]<<=2;
goto P_0c0a2e9a;
P_0c0a2e9a: /* original 4e00, guest PC 0x0c0a2e9a */
if(!s->budget--) { s->failed_pc=0x0c0a2e9au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0a2e9c;
P_0c0a2e9c: /* original 6343, guest PC 0x0c0a2e9c */
if(!s->budget--) { s->failed_pc=0x0c0a2e9cu; return 0; }
r[3]=r[4];
goto P_0c0a2e9e;
P_0c0a2e9e: /* original 3e3c, guest PC 0x0c0a2e9e */
if(!s->budget--) { s->failed_pc=0x0c0a2e9eu; return 0; }
r[14]+=r[3];
goto P_0c0a2ea0;
P_0c0a2ea0: /* original d233, guest PC 0x0c0a2ea0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea0u; return 0; }
r[2]=read(ram,0x0c0a2f70u,4);
goto P_0c0a2ea2;
P_0c0a2ea2: /* original 4e08, guest PC 0x0c0a2ea2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea2u; return 0; }
r[14]<<=2;
goto P_0c0a2ea4;
P_0c0a2ea4: /* original 6eef, guest PC 0x0c0a2ea4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0a2ea6;
P_0c0a2ea6: /* original 3e2c, guest PC 0x0c0a2ea6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea6u; return 0; }
r[14]+=r[2];
goto P_0c0a2ea8;
P_0c0a2ea8: /* original 53e6, guest PC 0x0c0a2ea8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea8u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c0a2eaa;
P_0c0a2eaa: /* original 2338, guest PC 0x0c0a2eaa */
if(!s->budget--) { s->failed_pc=0x0c0a2eaau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2eac;
P_0c0a2eac: /* original 890d, guest PC 0x0c0a2eac */
if(!s->budget--) { s->failed_pc=0x0c0a2eacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2eca; }
goto P_0c0a2eae;
P_0c0a2eae: /* original 5de6, guest PC 0x0c0a2eae */
if(!s->budget--) { s->failed_pc=0x0c0a2eaeu; return 0; }
r[13]=read(ram,r[14]+24,4);
goto P_0c0a2eb0;
P_0c0a2eb0: /* original d330, guest PC 0x0c0a2eb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb0u; return 0; }
r[3]=read(ram,0x0c0a2f74u,4);
goto P_0c0a2eb2;
P_0c0a2eb2: /* original 2d3b, guest PC 0x0c0a2eb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb2u; return 0; }
r[13]|=r[3];
goto P_0c0a2eb4;
P_0c0a2eb4: /* original 62d2, guest PC 0x0c0a2eb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb4u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0a2eb6;
P_0c0a2eb6: /* original 2228, guest PC 0x0c0a2eb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2eb8;
P_0c0a2eb8: /* original 8905, guest PC 0x0c0a2eb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2ec6; }
goto P_0c0a2eba;
P_0c0a2eba: /* original 52e8, guest PC 0x0c0a2eba */
if(!s->budget--) { s->failed_pc=0x0c0a2ebau; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c0a2ebc;
P_0c0a2ebc: /* original 420b, guest PC 0x0c0a2ebc */
if(!s->budget--) { s->failed_pc=0x0c0a2ebcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2ec0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ec0u) { target=s->pc; goto dispatch; }
goto P_0c0a2ec0;
P_0c0a2ebe: /* original 0009, guest PC 0x0c0a2ebe */
if(!s->budget--) { s->failed_pc=0x0c0a2ebeu; return 0; }
goto P_0c0a2ec0;
P_0c0a2ec0: /* original d32d, guest PC 0x0c0a2ec0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec0u; return 0; }
r[3]=read(ram,0x0c0a2f78u,4);
goto P_0c0a2ec2;
P_0c0a2ec2: /* original 430b, guest PC 0x0c0a2ec2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ec6u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ec6u) { target=s->pc; goto dispatch; }
goto P_0c0a2ec6;
P_0c0a2ec4: /* original 54e6, guest PC 0x0c0a2ec4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec4u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c0a2ec6;
P_0c0a2ec6: /* original e200, guest PC 0x0c0a2ec6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec6u; return 0; }
r[2]=0x00000000u;
goto P_0c0a2ec8;
P_0c0a2ec8: /* original 2d22, guest PC 0x0c0a2ec8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec8u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0a2eca;
P_0c0a2eca: /* original 4f26, guest PC 0x0c0a2eca */
if(!s->budget--) { s->failed_pc=0x0c0a2ecau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2ecc;
P_0c0a2ecc: /* original 6df6, guest PC 0x0c0a2ecc */
if(!s->budget--) { s->failed_pc=0x0c0a2eccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2ece;
P_0c0a2ece: /* original 000b, guest PC 0x0c0a2ece */
if(!s->budget--) { s->failed_pc=0x0c0a2eceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2ed0: /* original 6ef6, guest PC 0x0c0a2ed0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ed0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2ed2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2ed2u; return 0; } return 1;
P_0c0a71ac: /* original 4f22, guest PC 0x0c0a71ac */
if(!s->budget--) { s->failed_pc=0x0c0a71acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a71ae;
P_0c0a71ae: /* original d31e, guest PC 0x0c0a71ae */
if(!s->budget--) { s->failed_pc=0x0c0a71aeu; return 0; }
r[3]=read(ram,0x0c0a7228u,4);
goto P_0c0a71b0;
P_0c0a71b0: /* original 430b, guest PC 0x0c0a71b0 */
if(!s->budget--) { s->failed_pc=0x0c0a71b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a71b4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a71b4u) { target=s->pc; goto dispatch; }
goto P_0c0a71b4;
P_0c0a71b2: /* original e400, guest PC 0x0c0a71b2 */
if(!s->budget--) { s->failed_pc=0x0c0a71b2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a71b4;
P_0c0a71b4: /* original d31d, guest PC 0x0c0a71b4 */
if(!s->budget--) { s->failed_pc=0x0c0a71b4u; return 0; }
r[3]=read(ram,0x0c0a722cu,4);
goto P_0c0a71b6;
P_0c0a71b6: /* original d21e, guest PC 0x0c0a71b6 */
if(!s->budget--) { s->failed_pc=0x0c0a71b6u; return 0; }
r[2]=read(ram,0x0c0a7230u,4);
goto P_0c0a71b8;
P_0c0a71b8: /* original 6132, guest PC 0x0c0a71b8 */
if(!s->budget--) { s->failed_pc=0x0c0a71b8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0a71ba;
P_0c0a71ba: /* original 212b, guest PC 0x0c0a71ba */
if(!s->budget--) { s->failed_pc=0x0c0a71bau; return 0; }
r[1]|=r[2];
goto P_0c0a71bc;
P_0c0a71bc: /* original 2312, guest PC 0x0c0a71bc */
if(!s->budget--) { s->failed_pc=0x0c0a71bcu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0a71be;
P_0c0a71be: /* original d31e, guest PC 0x0c0a71be */
if(!s->budget--) { s->failed_pc=0x0c0a71beu; return 0; }
r[3]=read(ram,0x0c0a7238u,4);
goto P_0c0a71c0;
P_0c0a71c0: /* original d41c, guest PC 0x0c0a71c0 */
if(!s->budget--) { s->failed_pc=0x0c0a71c0u; return 0; }
r[4]=read(ram,0x0c0a7234u,4);
goto P_0c0a71c2;
P_0c0a71c2: /* original 430b, guest PC 0x0c0a71c2 */
if(!s->budget--) { s->failed_pc=0x0c0a71c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a71c6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a71c6u) { target=s->pc; goto dispatch; }
goto P_0c0a71c6;
P_0c0a71c4: /* original 0009, guest PC 0x0c0a71c4 */
if(!s->budget--) { s->failed_pc=0x0c0a71c4u; return 0; }
goto P_0c0a71c6;
P_0c0a71c6: /* original d21d, guest PC 0x0c0a71c6 */
if(!s->budget--) { s->failed_pc=0x0c0a71c6u; return 0; }
r[2]=read(ram,0x0c0a723cu,4);
goto P_0c0a71c8;
P_0c0a71c8: /* original 420b, guest PC 0x0c0a71c8 */
if(!s->budget--) { s->failed_pc=0x0c0a71c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a71ccu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a71ccu) { target=s->pc; goto dispatch; }
goto P_0c0a71cc;
P_0c0a71ca: /* original 0009, guest PC 0x0c0a71ca */
if(!s->budget--) { s->failed_pc=0x0c0a71cau; return 0; }
goto P_0c0a71cc;
P_0c0a71cc: /* original d31c, guest PC 0x0c0a71cc */
if(!s->budget--) { s->failed_pc=0x0c0a71ccu; return 0; }
r[3]=read(ram,0x0c0a7240u,4);
goto P_0c0a71ce;
P_0c0a71ce: /* original e401, guest PC 0x0c0a71ce */
if(!s->budget--) { s->failed_pc=0x0c0a71ceu; return 0; }
r[4]=0x00000001u;
goto P_0c0a71d0;
P_0c0a71d0: /* original 432b, guest PC 0x0c0a71d0 */
if(!s->budget--) { s->failed_pc=0x0c0a71d0u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c0a71d2: /* original 4f26, guest PC 0x0c0a71d2 */
if(!s->budget--) { s->failed_pc=0x0c0a71d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0a71d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a71d4u; return 0; } return 1;
P_0c0a7204: /* original d509, guest PC 0x0c0a7204 */
if(!s->budget--) { s->failed_pc=0x0c0a7204u; return 0; }
r[5]=read(ram,0x0c0a722cu,4);
goto P_0c0a7206;
P_0c0a7206: /* original d30f, guest PC 0x0c0a7206 */
if(!s->budget--) { s->failed_pc=0x0c0a7206u; return 0; }
r[3]=read(ram,0x0c0a7244u,4);
goto P_0c0a7208;
P_0c0a7208: /* original 6252, guest PC 0x0c0a7208 */
if(!s->budget--) { s->failed_pc=0x0c0a7208u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0a720a;
P_0c0a720a: /* original 223b, guest PC 0x0c0a720a */
if(!s->budget--) { s->failed_pc=0x0c0a720au; return 0; }
r[2]|=r[3];
goto P_0c0a720c;
P_0c0a720c: /* original 2522, guest PC 0x0c0a720c */
if(!s->budget--) { s->failed_pc=0x0c0a720cu; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0a720e;
P_0c0a720e: /* original 6152, guest PC 0x0c0a720e */
if(!s->budget--) { s->failed_pc=0x0c0a720eu; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0a7210;
P_0c0a7210: /* original d20d, guest PC 0x0c0a7210 */
if(!s->budget--) { s->failed_pc=0x0c0a7210u; return 0; }
r[2]=read(ram,0x0c0a7248u,4);
goto P_0c0a7212;
P_0c0a7212: /* original 2129, guest PC 0x0c0a7212 */
if(!s->budget--) { s->failed_pc=0x0c0a7212u; return 0; }
r[1]&=r[2];
goto P_0c0a7214;
P_0c0a7214: /* original 2512, guest PC 0x0c0a7214 */
if(!s->budget--) { s->failed_pc=0x0c0a7214u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c0a7216;
P_0c0a7216: /* original 000b, guest PC 0x0c0a7216 */
if(!s->budget--) { s->failed_pc=0x0c0a7216u; return 0; }
target=r[16];
write(ram,r[5]+24,r[4],4);
s->pc=target; return ram->oob==0;
P_0c0a7218: /* original 1546, guest PC 0x0c0a7218 */
if(!s->budget--) { s->failed_pc=0x0c0a7218u; return 0; }
write(ram,r[5]+24,r[4],4);
if(!vf3_matrix_family(0x0c0a721au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a721au; return 0; } return 1;
P_0c0a7250: /* original 4615, guest PC 0x0c0a7250 */
if(!s->budget--) { s->failed_pc=0x0c0a7250u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0a7252;
P_0c0a7252: /* original 8b05, guest PC 0x0c0a7252 */
if(!s->budget--) { s->failed_pc=0x0c0a7252u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7260; }
goto P_0c0a7254;
P_0c0a7254: /* original 6756, guest PC 0x0c0a7254 */
if(!s->budget--) { s->failed_pc=0x0c0a7254u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[7]=tmp;
goto P_0c0a7256;
P_0c0a7256: /* original 76ff, guest PC 0x0c0a7256 */
if(!s->budget--) { s->failed_pc=0x0c0a7256u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0a7258;
P_0c0a7258: /* original 4615, guest PC 0x0c0a7258 */
if(!s->budget--) { s->failed_pc=0x0c0a7258u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0a725a;
P_0c0a725a: /* original 2472, guest PC 0x0c0a725a */
if(!s->budget--) { s->failed_pc=0x0c0a725au; return 0; }
write(ram,r[4],r[7],4);
goto P_0c0a725c;
P_0c0a725c: /* original 8dfa, guest PC 0x0c0a725c */
if(!s->budget--) { s->failed_pc=0x0c0a725cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c0a7254; }
goto P_0c0a7260;
P_0c0a725e: /* original 7404, guest PC 0x0c0a725e */
if(!s->budget--) { s->failed_pc=0x0c0a725eu; return 0; }
r[4]+=0x00000004u;
goto P_0c0a7260;
P_0c0a7260: /* original 000b, guest PC 0x0c0a7260 */
if(!s->budget--) { s->failed_pc=0x0c0a7260u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a7262: /* original 0009, guest PC 0x0c0a7262 */
if(!s->budget--) { s->failed_pc=0x0c0a7262u; return 0; }
if(!vf3_matrix_family(0x0c0a7264u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7264u; return 0; } return 1;
P_0c0a7442: /* original d024, guest PC 0x0c0a7442 */
if(!s->budget--) { s->failed_pc=0x0c0a7442u; return 0; }
r[0]=read(ram,0x0c0a74d4u,4);
goto P_0c0a7444;
P_0c0a7444: /* original 7ffc, guest PC 0x0c0a7444 */
if(!s->budget--) { s->failed_pc=0x0c0a7444u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7446;
P_0c0a7446: /* original e635, guest PC 0x0c0a7446 */
if(!s->budget--) { s->failed_pc=0x0c0a7446u; return 0; }
r[6]=0x00000035u;
goto P_0c0a7448;
P_0c0a7448: /* original 6503, guest PC 0x0c0a7448 */
if(!s->budget--) { s->failed_pc=0x0c0a7448u; return 0; }
r[5]=r[0];
goto P_0c0a744a;
P_0c0a744a: /* original 2f02, guest PC 0x0c0a744a */
if(!s->budget--) { s->failed_pc=0x0c0a744au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0a744c;
P_0c0a744c: /* original af00, guest PC 0x0c0a744c */
if(!s->budget--) { s->failed_pc=0x0c0a744cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7250;
P_0c0a744e: /* original 7f04, guest PC 0x0c0a744e */
if(!s->budget--) { s->failed_pc=0x0c0a744eu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0a7450u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7450u; return 0; } return 1;
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
P_0c0a7794: /* original 2fe6, guest PC 0x0c0a7794 */
if(!s->budget--) { s->failed_pc=0x0c0a7794u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7796;
P_0c0a7796: /* original 6e43, guest PC 0x0c0a7796 */
if(!s->budget--) { s->failed_pc=0x0c0a7796u; return 0; }
r[14]=r[4];
goto P_0c0a7798;
P_0c0a7798: /* original 4f22, guest PC 0x0c0a7798 */
if(!s->budget--) { s->failed_pc=0x0c0a7798u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a779a;
P_0c0a779a: /* original 2ee8, guest PC 0x0c0a779a */
if(!s->budget--) { s->failed_pc=0x0c0a779au; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a779c;
P_0c0a779c: /* original 7ffc, guest PC 0x0c0a779c */
if(!s->budget--) { s->failed_pc=0x0c0a779cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a779e;
P_0c0a779e: /* original 8d1a, guest PC 0x0c0a779e */
if(!s->budget--) { s->failed_pc=0x0c0a779eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[5],4);
if(cond) { goto P_0c0a77d6; }
goto P_0c0a77a2;
P_0c0a77a0: /* original 2f52, guest PC 0x0c0a77a0 */
if(!s->budget--) { s->failed_pc=0x0c0a77a0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0a77a2;
P_0c0a77a2: /* original e024, guest PC 0x0c0a77a2 */
if(!s->budget--) { s->failed_pc=0x0c0a77a2u; return 0; }
r[0]=0x00000024u;
goto P_0c0a77a4;
P_0c0a77a4: /* original f5e6, guest PC 0x0c0a77a4 */
if(!s->budget--) { s->failed_pc=0x0c0a77a4u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a77a6;
P_0c0a77a6: /* original e01c, guest PC 0x0c0a77a6 */
if(!s->budget--) { s->failed_pc=0x0c0a77a6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a77a8;
P_0c0a77a8: /* original f4e6, guest PC 0x0c0a77a8 */
if(!s->budget--) { s->failed_pc=0x0c0a77a8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a77aa;
P_0c0a77aa: /* original 84e7, guest PC 0x0c0a77aa */
if(!s->budget--) { s->failed_pc=0x0c0a77aau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c0a77ac;
P_0c0a77ac: /* original 660c, guest PC 0x0c0a77ac */
if(!s->budget--) { s->failed_pc=0x0c0a77acu; return 0; }
r[6]=r[0]&255u;
goto P_0c0a77ae;
P_0c0a77ae: /* original 84e6, guest PC 0x0c0a77ae */
if(!s->budget--) { s->failed_pc=0x0c0a77aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+6,1);
goto P_0c0a77b0;
P_0c0a77b0: /* original 650c, guest PC 0x0c0a77b0 */
if(!s->budget--) { s->failed_pc=0x0c0a77b0u; return 0; }
r[5]=r[0]&255u;
goto P_0c0a77b2;
P_0c0a77b2: /* original 84e5, guest PC 0x0c0a77b2 */
if(!s->budget--) { s->failed_pc=0x0c0a77b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+5,1);
goto P_0c0a77b4;
P_0c0a77b4: /* original b12a, guest PC 0x0c0a77b4 */
if(!s->budget--) { s->failed_pc=0x0c0a77b4u; return 0; }
target=code_base|0x0c0a7a0cu; r[16]=code_base|0x0c0a77b8u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a77b8u) { target=s->pc; goto dispatch; }
goto P_0c0a77b8;
P_0c0a77b6: /* original 640c, guest PC 0x0c0a77b6 */
if(!s->budget--) { s->failed_pc=0x0c0a77b6u; return 0; }
r[4]=r[0]&255u;
goto P_0c0a77b8;
P_0c0a77b8: /* original 64f2, guest PC 0x0c0a77b8 */
if(!s->budget--) { s->failed_pc=0x0c0a77b8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a77ba;
P_0c0a77ba: /* original e010, guest PC 0x0c0a77ba */
if(!s->budget--) { s->failed_pc=0x0c0a77bau; return 0; }
r[0]=0x00000010u;
goto P_0c0a77bc;
P_0c0a77bc: /* original f5e6, guest PC 0x0c0a77bc */
if(!s->budget--) { s->failed_pc=0x0c0a77bcu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a77be;
P_0c0a77be: /* original 044c, guest PC 0x0c0a77be */
if(!s->budget--) { s->failed_pc=0x0c0a77beu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a77c0;
P_0c0a77c0: /* original e014, guest PC 0x0c0a77c0 */
if(!s->budget--) { s->failed_pc=0x0c0a77c0u; return 0; }
r[0]=0x00000014u;
goto P_0c0a77c2;
P_0c0a77c2: /* original b0a1, guest PC 0x0c0a77c2 */
if(!s->budget--) { s->failed_pc=0x0c0a77c2u; return 0; }
target=code_base|0x0c0a7908u; r[16]=code_base|0x0c0a77c6u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a77c6u) { target=s->pc; goto dispatch; }
goto P_0c0a77c6;
P_0c0a77c4: /* original f4e6, guest PC 0x0c0a77c4 */
if(!s->budget--) { s->failed_pc=0x0c0a77c4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a77c6;
P_0c0a77c6: /* original 85e7, guest PC 0x0c0a77c6 */
if(!s->budget--) { s->failed_pc=0x0c0a77c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a77c8;
P_0c0a77c8: /* original 7f04, guest PC 0x0c0a77c8 */
if(!s->budget--) { s->failed_pc=0x0c0a77c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a77ca;
P_0c0a77ca: /* original 4f26, guest PC 0x0c0a77ca */
if(!s->budget--) { s->failed_pc=0x0c0a77cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a77cc;
P_0c0a77cc: /* original 6503, guest PC 0x0c0a77cc */
if(!s->budget--) { s->failed_pc=0x0c0a77ccu; return 0; }
r[5]=r[0];
goto P_0c0a77ce;
P_0c0a77ce: /* original 85e6, guest PC 0x0c0a77ce */
if(!s->budget--) { s->failed_pc=0x0c0a77ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a77d0;
P_0c0a77d0: /* original 6403, guest PC 0x0c0a77d0 */
if(!s->budget--) { s->failed_pc=0x0c0a77d0u; return 0; }
r[4]=r[0];
goto P_0c0a77d2;
P_0c0a77d2: /* original a006, guest PC 0x0c0a77d2 */
if(!s->budget--) { s->failed_pc=0x0c0a77d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a77e2;
P_0c0a77d4: /* original 6ef6, guest PC 0x0c0a77d4 */
if(!s->budget--) { s->failed_pc=0x0c0a77d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a77d6;
P_0c0a77d6: /* original 7f04, guest PC 0x0c0a77d6 */
if(!s->budget--) { s->failed_pc=0x0c0a77d6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a77d8;
P_0c0a77d8: /* original 4f26, guest PC 0x0c0a77d8 */
if(!s->budget--) { s->failed_pc=0x0c0a77d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a77da;
P_0c0a77da: /* original 000b, guest PC 0x0c0a77da */
if(!s->budget--) { s->failed_pc=0x0c0a77dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a77dc: /* original 6ef6, guest PC 0x0c0a77dc */
if(!s->budget--) { s->failed_pc=0x0c0a77dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a77deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a77deu; return 0; } return 1;
P_0c0a77e2: /* original 4f22, guest PC 0x0c0a77e2 */
if(!s->budget--) { s->failed_pc=0x0c0a77e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a77e4;
P_0c0a77e4: /* original 6043, guest PC 0x0c0a77e4 */
if(!s->budget--) { s->failed_pc=0x0c0a77e4u; return 0; }
r[0]=r[4];
goto P_0c0a77e6;
P_0c0a77e6: /* original e300, guest PC 0x0c0a77e6 */
if(!s->budget--) { s->failed_pc=0x0c0a77e6u; return 0; }
r[3]=0x00000000u;
goto P_0c0a77e8;
P_0c0a77e8: /* original 7fec, guest PC 0x0c0a77e8 */
if(!s->budget--) { s->failed_pc=0x0c0a77e8u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0a77ea;
P_0c0a77ea: /* original 81f6, guest PC 0x0c0a77ea */
if(!s->budget--) { s->failed_pc=0x0c0a77eau; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0a77ec;
P_0c0a77ec: /* original 6053, guest PC 0x0c0a77ec */
if(!s->budget--) { s->failed_pc=0x0c0a77ecu; return 0; }
r[0]=r[5];
goto P_0c0a77ee;
P_0c0a77ee: /* original 81f8, guest PC 0x0c0a77ee */
if(!s->budget--) { s->failed_pc=0x0c0a77eeu; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0a77f0;
P_0c0a77f0: /* original 2f36, guest PC 0x0c0a77f0 */
if(!s->budget--) { s->failed_pc=0x0c0a77f0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a77f2;
P_0c0a77f2: /* original 85fa, guest PC 0x0c0a77f2 */
if(!s->budget--) { s->failed_pc=0x0c0a77f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c0a77f4;
P_0c0a77f4: /* original 2f06, guest PC 0x0c0a77f4 */
if(!s->budget--) { s->failed_pc=0x0c0a77f4u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a77f6;
P_0c0a77f6: /* original 85fa, guest PC 0x0c0a77f6 */
if(!s->budget--) { s->failed_pc=0x0c0a77f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c0a77f8;
P_0c0a77f8: /* original 65f3, guest PC 0x0c0a77f8 */
if(!s->budget--) { s->failed_pc=0x0c0a77f8u; return 0; }
r[5]=r[15];
goto P_0c0a77fa;
P_0c0a77fa: /* original 66f3, guest PC 0x0c0a77fa */
if(!s->budget--) { s->failed_pc=0x0c0a77fau; return 0; }
r[6]=r[15];
goto P_0c0a77fc;
P_0c0a77fc: /* original d213, guest PC 0x0c0a77fc */
if(!s->budget--) { s->failed_pc=0x0c0a77fcu; return 0; }
r[2]=read(ram,0x0c0a784cu,4);
goto P_0c0a77fe;
P_0c0a77fe: /* original 64f3, guest PC 0x0c0a77fe */
if(!s->budget--) { s->failed_pc=0x0c0a77feu; return 0; }
r[4]=r[15];
goto P_0c0a7800;
P_0c0a7800: /* original 750c, guest PC 0x0c0a7800 */
if(!s->budget--) { s->failed_pc=0x0c0a7800u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0a7802;
P_0c0a7802: /* original 6703, guest PC 0x0c0a7802 */
if(!s->budget--) { s->failed_pc=0x0c0a7802u; return 0; }
r[7]=r[0];
goto P_0c0a7804;
P_0c0a7804: /* original 7610, guest PC 0x0c0a7804 */
if(!s->budget--) { s->failed_pc=0x0c0a7804u; return 0; }
r[6]+=0x00000010u;
goto P_0c0a7806;
P_0c0a7806: /* original 420b, guest PC 0x0c0a7806 */
if(!s->budget--) { s->failed_pc=0x0c0a7806u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a780au;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a780au) { target=s->pc; goto dispatch; }
goto P_0c0a780a;
P_0c0a7808: /* original 7408, guest PC 0x0c0a7808 */
if(!s->budget--) { s->failed_pc=0x0c0a7808u; return 0; }
r[4]+=0x00000008u;
goto P_0c0a780a;
P_0c0a780a: /* original e010, guest PC 0x0c0a780a */
if(!s->budget--) { s->failed_pc=0x0c0a780au; return 0; }
r[0]=0x00000010u;
goto P_0c0a780c;
P_0c0a780c: /* original f6f6, guest PC 0x0c0a780c */
if(!s->budget--) { s->failed_pc=0x0c0a780cu; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0a780e;
P_0c0a780e: /* original e00c, guest PC 0x0c0a780e */
if(!s->budget--) { s->failed_pc=0x0c0a780eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a7810;
P_0c0a7810: /* original f5f6, guest PC 0x0c0a7810 */
if(!s->budget--) { s->failed_pc=0x0c0a7810u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a7812;
P_0c0a7812: /* original e008, guest PC 0x0c0a7812 */
if(!s->budget--) { s->failed_pc=0x0c0a7812u; return 0; }
r[0]=0x00000008u;
goto P_0c0a7814;
P_0c0a7814: /* original b01c, guest PC 0x0c0a7814 */
if(!s->budget--) { s->failed_pc=0x0c0a7814u; return 0; }
target=code_base|0x0c0a7850u; r[16]=code_base|0x0c0a7818u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7818u) { target=s->pc; goto dispatch; }
goto P_0c0a7818;
P_0c0a7816: /* original f4f6, guest PC 0x0c0a7816 */
if(!s->budget--) { s->failed_pc=0x0c0a7816u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0a7818;
P_0c0a7818: /* original 7f1c, guest PC 0x0c0a7818 */
if(!s->budget--) { s->failed_pc=0x0c0a7818u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0a781a;
P_0c0a781a: /* original 4f26, guest PC 0x0c0a781a */
if(!s->budget--) { s->failed_pc=0x0c0a781au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a781c;
P_0c0a781c: /* original 000b, guest PC 0x0c0a781c */
if(!s->budget--) { s->failed_pc=0x0c0a781cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a781e: /* original 0009, guest PC 0x0c0a781e */
if(!s->budget--) { s->failed_pc=0x0c0a781eu; return 0; }
if(!vf3_matrix_family(0x0c0a7820u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7820u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
