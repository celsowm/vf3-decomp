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
int vf3_away_batch179_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0626b0u: goto P_0c0626b0;
case 0x0c0626b2u: goto P_0c0626b2;
case 0x0c0626b4u: goto P_0c0626b4;
case 0x0c0626b6u: goto P_0c0626b6;
case 0x0c0626b8u: goto P_0c0626b8;
case 0x0c0626bau: goto P_0c0626ba;
case 0x0c0626bcu: goto P_0c0626bc;
case 0x0c0626beu: goto P_0c0626be;
case 0x0c0626c0u: goto P_0c0626c0;
case 0x0c0626c2u: goto P_0c0626c2;
case 0x0c0626c4u: goto P_0c0626c4;
case 0x0c0626c6u: goto P_0c0626c6;
case 0x0c0626c8u: goto P_0c0626c8;
case 0x0c0626cau: goto P_0c0626ca;
case 0x0c0626ccu: goto P_0c0626cc;
case 0x0c0626ceu: goto P_0c0626ce;
case 0x0c0626d0u: goto P_0c0626d0;
case 0x0c0626d2u: goto P_0c0626d2;
case 0x0c0626d4u: goto P_0c0626d4;
case 0x0c0626d6u: goto P_0c0626d6;
case 0x0c0626d8u: goto P_0c0626d8;
case 0x0c0626dau: goto P_0c0626da;
case 0x0c0626dcu: goto P_0c0626dc;
case 0x0c0626deu: goto P_0c0626de;
case 0x0c0626e0u: goto P_0c0626e0;
case 0x0c0626e2u: goto P_0c0626e2;
case 0x0c0626e4u: goto P_0c0626e4;
case 0x0c0626e6u: goto P_0c0626e6;
case 0x0c0626e8u: goto P_0c0626e8;
case 0x0c0626eau: goto P_0c0626ea;
case 0x0c0626ecu: goto P_0c0626ec;
case 0x0c0626eeu: goto P_0c0626ee;
case 0x0c0626f0u: goto P_0c0626f0;
case 0x0c0626f2u: goto P_0c0626f2;
case 0x0c0626f4u: goto P_0c0626f4;
case 0x0c0626f6u: goto P_0c0626f6;
case 0x0c0626f8u: goto P_0c0626f8;
case 0x0c0626fau: goto P_0c0626fa;
case 0x0c0626fcu: goto P_0c0626fc;
case 0x0c0626feu: goto P_0c0626fe;
case 0x0c062700u: goto P_0c062700;
case 0x0c062702u: goto P_0c062702;
case 0x0c062704u: goto P_0c062704;
case 0x0c062706u: goto P_0c062706;
case 0x0c062708u: goto P_0c062708;
case 0x0c06270au: goto P_0c06270a;
case 0x0c06270cu: goto P_0c06270c;
case 0x0c06270eu: goto P_0c06270e;
case 0x0c062710u: goto P_0c062710;
case 0x0c062712u: goto P_0c062712;
case 0x0c062714u: goto P_0c062714;
case 0x0c062716u: goto P_0c062716;
case 0x0c062718u: goto P_0c062718;
case 0x0c06271au: goto P_0c06271a;
case 0x0c06271cu: goto P_0c06271c;
case 0x0c06271eu: goto P_0c06271e;
case 0x0c062720u: goto P_0c062720;
case 0x0c062722u: goto P_0c062722;
case 0x0c062724u: goto P_0c062724;
case 0x0c062726u: goto P_0c062726;
case 0x0c062728u: goto P_0c062728;
case 0x0c06272au: goto P_0c06272a;
case 0x0c06272cu: goto P_0c06272c;
case 0x0c06272eu: goto P_0c06272e;
case 0x0c062730u: goto P_0c062730;
case 0x0c062732u: goto P_0c062732;
case 0x0c062734u: goto P_0c062734;
case 0x0c062736u: goto P_0c062736;
case 0x0c062738u: goto P_0c062738;
case 0x0c06273au: goto P_0c06273a;
case 0x0c06273cu: goto P_0c06273c;
case 0x0c06273eu: goto P_0c06273e;
case 0x0c062740u: goto P_0c062740;
case 0x0c062742u: goto P_0c062742;
case 0x0c062744u: goto P_0c062744;
case 0x0c062746u: goto P_0c062746;
case 0x0c062748u: goto P_0c062748;
case 0x0c06274au: goto P_0c06274a;
case 0x0c06274cu: goto P_0c06274c;
case 0x0c06274eu: goto P_0c06274e;
case 0x0c062750u: goto P_0c062750;
case 0x0c062752u: goto P_0c062752;
case 0x0c062754u: goto P_0c062754;
case 0x0c062756u: goto P_0c062756;
case 0x0c062758u: goto P_0c062758;
case 0x0c06275au: goto P_0c06275a;
case 0x0c06275cu: goto P_0c06275c;
case 0x0c06275eu: goto P_0c06275e;
case 0x0c062760u: goto P_0c062760;
case 0x0c062762u: goto P_0c062762;
case 0x0c062764u: goto P_0c062764;
case 0x0c062766u: goto P_0c062766;
case 0x0c062768u: goto P_0c062768;
case 0x0c06276au: goto P_0c06276a;
case 0x0c06276cu: goto P_0c06276c;
case 0x0c06276eu: goto P_0c06276e;
case 0x0c062770u: goto P_0c062770;
case 0x0c062772u: goto P_0c062772;
case 0x0c062774u: goto P_0c062774;
case 0x0c062776u: goto P_0c062776;
case 0x0c062778u: goto P_0c062778;
case 0x0c06277au: goto P_0c06277a;
case 0x0c06277cu: goto P_0c06277c;
case 0x0c06277eu: goto P_0c06277e;
case 0x0c062780u: goto P_0c062780;
case 0x0c062782u: goto P_0c062782;
case 0x0c062784u: goto P_0c062784;
case 0x0c062786u: goto P_0c062786;
case 0x0c062788u: goto P_0c062788;
case 0x0c06278au: goto P_0c06278a;
case 0x0c06278cu: goto P_0c06278c;
case 0x0c0627a0u: goto P_0c0627a0;
case 0x0c0627a2u: goto P_0c0627a2;
case 0x0c0627a4u: goto P_0c0627a4;
case 0x0c0627a6u: goto P_0c0627a6;
case 0x0c0627a8u: goto P_0c0627a8;
case 0x0c0627aau: goto P_0c0627aa;
case 0x0c0627acu: goto P_0c0627ac;
case 0x0c0627aeu: goto P_0c0627ae;
case 0x0c0627b0u: goto P_0c0627b0;
case 0x0c0627b2u: goto P_0c0627b2;
case 0x0c0627b4u: goto P_0c0627b4;
case 0x0c0627b6u: goto P_0c0627b6;
case 0x0c0627b8u: goto P_0c0627b8;
case 0x0c0627bau: goto P_0c0627ba;
case 0x0c0627bcu: goto P_0c0627bc;
case 0x0c0627beu: goto P_0c0627be;
case 0x0c0627c0u: goto P_0c0627c0;
case 0x0c0627c2u: goto P_0c0627c2;
case 0x0c0627c4u: goto P_0c0627c4;
case 0x0c0627c6u: goto P_0c0627c6;
case 0x0c0627c8u: goto P_0c0627c8;
case 0x0c0627cau: goto P_0c0627ca;
case 0x0c0627ccu: goto P_0c0627cc;
case 0x0c0627ceu: goto P_0c0627ce;
case 0x0c0627d0u: goto P_0c0627d0;
case 0x0c0627d2u: goto P_0c0627d2;
case 0x0c0627d4u: goto P_0c0627d4;
case 0x0c0627d6u: goto P_0c0627d6;
case 0x0c0627d8u: goto P_0c0627d8;
case 0x0c0627dau: goto P_0c0627da;
case 0x0c0627dcu: goto P_0c0627dc;
case 0x0c0627deu: goto P_0c0627de;
case 0x0c0627e0u: goto P_0c0627e0;
case 0x0c0627e2u: goto P_0c0627e2;
case 0x0c0627e4u: goto P_0c0627e4;
case 0x0c0627e6u: goto P_0c0627e6;
case 0x0c0627e8u: goto P_0c0627e8;
case 0x0c0627eau: goto P_0c0627ea;
case 0x0c0627ecu: goto P_0c0627ec;
case 0x0c0627eeu: goto P_0c0627ee;
case 0x0c0627f0u: goto P_0c0627f0;
case 0x0c0627f2u: goto P_0c0627f2;
case 0x0c0627f4u: goto P_0c0627f4;
case 0x0c0627f6u: goto P_0c0627f6;
case 0x0c0627f8u: goto P_0c0627f8;
case 0x0c0627fau: goto P_0c0627fa;
case 0x0c0627fcu: goto P_0c0627fc;
case 0x0c0627feu: goto P_0c0627fe;
case 0x0c062800u: goto P_0c062800;
case 0x0c062802u: goto P_0c062802;
case 0x0c062804u: goto P_0c062804;
case 0x0c062806u: goto P_0c062806;
case 0x0c062808u: goto P_0c062808;
case 0x0c06280au: goto P_0c06280a;
case 0x0c06280cu: goto P_0c06280c;
case 0x0c06280eu: goto P_0c06280e;
case 0x0c062810u: goto P_0c062810;
case 0x0c062812u: goto P_0c062812;
case 0x0c062814u: goto P_0c062814;
case 0x0c062816u: goto P_0c062816;
case 0x0c062818u: goto P_0c062818;
case 0x0c06281au: goto P_0c06281a;
case 0x0c06281cu: goto P_0c06281c;
case 0x0c06281eu: goto P_0c06281e;
case 0x0c062820u: goto P_0c062820;
case 0x0c062822u: goto P_0c062822;
case 0x0c062824u: goto P_0c062824;
case 0x0c062826u: goto P_0c062826;
case 0x0c062828u: goto P_0c062828;
case 0x0c06282au: goto P_0c06282a;
case 0x0c06282cu: goto P_0c06282c;
case 0x0c06282eu: goto P_0c06282e;
case 0x0c062830u: goto P_0c062830;
case 0x0c062832u: goto P_0c062832;
case 0x0c062834u: goto P_0c062834;
case 0x0c062836u: goto P_0c062836;
case 0x0c062838u: goto P_0c062838;
case 0x0c06283au: goto P_0c06283a;
case 0x0c06283cu: goto P_0c06283c;
case 0x0c06283eu: goto P_0c06283e;
case 0x0c062840u: goto P_0c062840;
case 0x0c062842u: goto P_0c062842;
case 0x0c062844u: goto P_0c062844;
case 0x0c062846u: goto P_0c062846;
case 0x0c062848u: goto P_0c062848;
case 0x0c06284au: goto P_0c06284a;
case 0x0c06284cu: goto P_0c06284c;
case 0x0c06284eu: goto P_0c06284e;
case 0x0c062850u: goto P_0c062850;
case 0x0c062852u: goto P_0c062852;
case 0x0c062854u: goto P_0c062854;
case 0x0c062856u: goto P_0c062856;
case 0x0c062858u: goto P_0c062858;
case 0x0c06285au: goto P_0c06285a;
case 0x0c06285cu: goto P_0c06285c;
case 0x0c06285eu: goto P_0c06285e;
case 0x0c062860u: goto P_0c062860;
case 0x0c062862u: goto P_0c062862;
case 0x0c062864u: goto P_0c062864;
case 0x0c062866u: goto P_0c062866;
case 0x0c062868u: goto P_0c062868;
case 0x0c06286au: goto P_0c06286a;
case 0x0c06286cu: goto P_0c06286c;
case 0x0c06286eu: goto P_0c06286e;
case 0x0c062870u: goto P_0c062870;
case 0x0c062872u: goto P_0c062872;
case 0x0c062874u: goto P_0c062874;
case 0x0c062876u: goto P_0c062876;
case 0x0c062878u: goto P_0c062878;
case 0x0c06287au: goto P_0c06287a;
case 0x0c06287cu: goto P_0c06287c;
case 0x0c06287eu: goto P_0c06287e;
case 0x0c062880u: goto P_0c062880;
case 0x0c062882u: goto P_0c062882;
case 0x0c062884u: goto P_0c062884;
case 0x0c062886u: goto P_0c062886;
case 0x0c062888u: goto P_0c062888;
case 0x0c06288au: goto P_0c06288a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0626b0: /* original 2fe6, guest PC 0x0c0626b0 */
if(!s->budget--) { s->failed_pc=0x0c0626b0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0626b2;
P_0c0626b2: /* original 2fd6, guest PC 0x0c0626b2 */
if(!s->budget--) { s->failed_pc=0x0c0626b2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0626b4;
P_0c0626b4: /* original 2fc6, guest PC 0x0c0626b4 */
if(!s->budget--) { s->failed_pc=0x0c0626b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0626b6;
P_0c0626b6: /* original 2fb6, guest PC 0x0c0626b6 */
if(!s->budget--) { s->failed_pc=0x0c0626b6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0626b8;
P_0c0626b8: /* original 2fa6, guest PC 0x0c0626b8 */
if(!s->budget--) { s->failed_pc=0x0c0626b8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0626ba;
P_0c0626ba: /* original 6b53, guest PC 0x0c0626ba */
if(!s->budget--) { s->failed_pc=0x0c0626bau; return 0; }
r[11]=r[5];
goto P_0c0626bc;
P_0c0626bc: /* original 2f96, guest PC 0x0c0626bc */
if(!s->budget--) { s->failed_pc=0x0c0626bcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0626be;
P_0c0626be: /* original 6943, guest PC 0x0c0626be */
if(!s->budget--) { s->failed_pc=0x0c0626beu; return 0; }
r[9]=r[4];
goto P_0c0626c0;
P_0c0626c0: /* original 4f22, guest PC 0x0c0626c0 */
if(!s->budget--) { s->failed_pc=0x0c0626c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0626c2;
P_0c0626c2: /* original 6e92, guest PC 0x0c0626c2 */
if(!s->budget--) { s->failed_pc=0x0c0626c2u; return 0; }
tmp=read(ram,r[9],4);
r[14]=tmp;
goto P_0c0626c4;
P_0c0626c4: /* original 2ee8, guest PC 0x0c0626c4 */
if(!s->budget--) { s->failed_pc=0x0c0626c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0626c6;
P_0c0626c6: /* original 8f02, guest PC 0x0c0626c6 */
if(!s->budget--) { s->failed_pc=0x0c0626c6u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[6],4);
r[13]=tmp;
if(!cond) { goto P_0c0626ce; }
goto P_0c0626ca;
P_0c0626c8: /* original 6d62, guest PC 0x0c0626c8 */
if(!s->budget--) { s->failed_pc=0x0c0626c8u; return 0; }
tmp=read(ram,r[6],4);
r[13]=tmp;
goto P_0c0626ca;
P_0c0626ca: /* original a0d6, guest PC 0x0c0626ca */
if(!s->budget--) { s->failed_pc=0x0c0626cau; return 0; }
goto P_0c06287a;
P_0c0626cc: /* original 0009, guest PC 0x0c0626cc */
if(!s->budget--) { s->failed_pc=0x0c0626ccu; return 0; }
goto P_0c0626ce;
P_0c0626ce: /* original 2dd8, guest PC 0x0c0626ce */
if(!s->budget--) { s->failed_pc=0x0c0626ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0626d0;
P_0c0626d0: /* original 8b01, guest PC 0x0c0626d0 */
if(!s->budget--) { s->failed_pc=0x0c0626d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0626d6; }
goto P_0c0626d2;
P_0c0626d2: /* original a0d2, guest PC 0x0c0626d2 */
if(!s->budget--) { s->failed_pc=0x0c0626d2u; return 0; }
goto P_0c06287a;
P_0c0626d4: /* original 0009, guest PC 0x0c0626d4 */
if(!s->budget--) { s->failed_pc=0x0c0626d4u; return 0; }
goto P_0c0626d6;
P_0c0626d6: /* original e520, guest PC 0x0c0626d6 */
if(!s->budget--) { s->failed_pc=0x0c0626d6u; return 0; }
r[5]=0x00000020u;
goto P_0c0626d8;
P_0c0626d8: /* original 64d1, guest PC 0x0c0626d8 */
if(!s->budget--) { s->failed_pc=0x0c0626d8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[4]=tmp;
goto P_0c0626da;
P_0c0626da: /* original 644d, guest PC 0x0c0626da */
if(!s->budget--) { s->failed_pc=0x0c0626dau; return 0; }
r[4]=r[4]&65535u;
goto P_0c0626dc;
P_0c0626dc: /* original 6243, guest PC 0x0c0626dc */
if(!s->budget--) { s->failed_pc=0x0c0626dcu; return 0; }
r[2]=r[4];
goto P_0c0626de;
P_0c0626de: /* original 2258, guest PC 0x0c0626de */
if(!s->budget--) { s->failed_pc=0x0c0626deu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0626e0;
P_0c0626e0: /* original 8f0f, guest PC 0x0c0626e0 */
if(!s->budget--) { s->failed_pc=0x0c0626e0u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c062702; }
goto P_0c0626e4;
P_0c0626e2: /* original ec00, guest PC 0x0c0626e2 */
if(!s->budget--) { s->failed_pc=0x0c0626e2u; return 0; }
r[12]=0x00000000u;
goto P_0c0626e4;
P_0c0626e4: /* original e140, guest PC 0x0c0626e4 */
if(!s->budget--) { s->failed_pc=0x0c0626e4u; return 0; }
r[1]=0x00000040u;
goto P_0c0626e6;
P_0c0626e6: /* original 2148, guest PC 0x0c0626e6 */
if(!s->budget--) { s->failed_pc=0x0c0626e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0626e8;
P_0c0626e8: /* original 8b0b, guest PC 0x0c0626e8 */
if(!s->budget--) { s->failed_pc=0x0c0626e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062702; }
goto P_0c0626ea;
P_0c0626ea: /* original e202, guest PC 0x0c0626ea */
if(!s->budget--) { s->failed_pc=0x0c0626eau; return 0; }
r[2]=0x00000002u;
goto P_0c0626ec;
P_0c0626ec: /* original 2248, guest PC 0x0c0626ec */
if(!s->budget--) { s->failed_pc=0x0c0626ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0626ee;
P_0c0626ee: /* original 8b09, guest PC 0x0c0626ee */
if(!s->budget--) { s->failed_pc=0x0c0626eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062704; }
goto P_0c0626f0;
P_0c0626f0: /* original 914d, guest PC 0x0c0626f0 */
if(!s->budget--) { s->failed_pc=0x0c0626f0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06278eu,2);
goto P_0c0626f2;
P_0c0626f2: /* original 2148, guest PC 0x0c0626f2 */
if(!s->budget--) { s->failed_pc=0x0c0626f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0626f4;
P_0c0626f4: /* original 8b05, guest PC 0x0c0626f4 */
if(!s->budget--) { s->failed_pc=0x0c0626f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062702; }
goto P_0c0626f6;
P_0c0626f6: /* original e202, guest PC 0x0c0626f6 */
if(!s->budget--) { s->failed_pc=0x0c0626f6u; return 0; }
r[2]=0x00000002u;
goto P_0c0626f8;
P_0c0626f8: /* original 2248, guest PC 0x0c0626f8 */
if(!s->budget--) { s->failed_pc=0x0c0626f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0626fa;
P_0c0626fa: /* original 8b03, guest PC 0x0c0626fa */
if(!s->budget--) { s->failed_pc=0x0c0626fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062704; }
goto P_0c0626fc;
P_0c0626fc: /* original 9148, guest PC 0x0c0626fc */
if(!s->budget--) { s->failed_pc=0x0c0626fcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062790u,2);
goto P_0c0626fe;
P_0c0626fe: /* original 2148, guest PC 0x0c0626fe */
if(!s->budget--) { s->failed_pc=0x0c0626feu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c062700;
P_0c062700: /* original 8900, guest PC 0x0c062700 */
if(!s->budget--) { s->failed_pc=0x0c062700u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062704; }
goto P_0c062702;
P_0c062702: /* original ec01, guest PC 0x0c062702 */
if(!s->budget--) { s->failed_pc=0x0c062702u; return 0; }
r[12]=0x00000001u;
goto P_0c062704;
P_0c062704: /* original 9545, guest PC 0x0c062704 */
if(!s->budget--) { s->failed_pc=0x0c062704u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062792u,2);
goto P_0c062706;
P_0c062706: /* original 64d1, guest PC 0x0c062706 */
if(!s->budget--) { s->failed_pc=0x0c062706u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[4]=tmp;
goto P_0c062708;
P_0c062708: /* original 644d, guest PC 0x0c062708 */
if(!s->budget--) { s->failed_pc=0x0c062708u; return 0; }
r[4]=r[4]&65535u;
goto P_0c06270a;
P_0c06270a: /* original 6243, guest PC 0x0c06270a */
if(!s->budget--) { s->failed_pc=0x0c06270au; return 0; }
r[2]=r[4];
goto P_0c06270c;
P_0c06270c: /* original 2258, guest PC 0x0c06270c */
if(!s->budget--) { s->failed_pc=0x0c06270cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c06270e;
P_0c06270e: /* original 8b0e, guest PC 0x0c06270e */
if(!s->budget--) { s->failed_pc=0x0c06270eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06272e; }
goto P_0c062710;
P_0c062710: /* original 9140, guest PC 0x0c062710 */
if(!s->budget--) { s->failed_pc=0x0c062710u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062794u,2);
goto P_0c062712;
P_0c062712: /* original 2148, guest PC 0x0c062712 */
if(!s->budget--) { s->failed_pc=0x0c062712u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c062714;
P_0c062714: /* original 8b0b, guest PC 0x0c062714 */
if(!s->budget--) { s->failed_pc=0x0c062714u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06272e; }
goto P_0c062716;
P_0c062716: /* original e202, guest PC 0x0c062716 */
if(!s->budget--) { s->failed_pc=0x0c062716u; return 0; }
r[2]=0x00000002u;
goto P_0c062718;
P_0c062718: /* original 2248, guest PC 0x0c062718 */
if(!s->budget--) { s->failed_pc=0x0c062718u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c06271a;
P_0c06271a: /* original 8b09, guest PC 0x0c06271a */
if(!s->budget--) { s->failed_pc=0x0c06271au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062730; }
goto P_0c06271c;
P_0c06271c: /* original 913b, guest PC 0x0c06271c */
if(!s->budget--) { s->failed_pc=0x0c06271cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062796u,2);
goto P_0c06271e;
P_0c06271e: /* original 2148, guest PC 0x0c06271e */
if(!s->budget--) { s->failed_pc=0x0c06271eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c062720;
P_0c062720: /* original 8b05, guest PC 0x0c062720 */
if(!s->budget--) { s->failed_pc=0x0c062720u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06272e; }
goto P_0c062722;
P_0c062722: /* original e202, guest PC 0x0c062722 */
if(!s->budget--) { s->failed_pc=0x0c062722u; return 0; }
r[2]=0x00000002u;
goto P_0c062724;
P_0c062724: /* original 2248, guest PC 0x0c062724 */
if(!s->budget--) { s->failed_pc=0x0c062724u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c062726;
P_0c062726: /* original 8b03, guest PC 0x0c062726 */
if(!s->budget--) { s->failed_pc=0x0c062726u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062730; }
goto P_0c062728;
P_0c062728: /* original 9136, guest PC 0x0c062728 */
if(!s->budget--) { s->failed_pc=0x0c062728u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062798u,2);
goto P_0c06272a;
P_0c06272a: /* original 2148, guest PC 0x0c06272a */
if(!s->budget--) { s->failed_pc=0x0c06272au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c06272c;
P_0c06272c: /* original 8900, guest PC 0x0c06272c */
if(!s->budget--) { s->failed_pc=0x0c06272cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062730; }
goto P_0c06272e;
P_0c06272e: /* original ec02, guest PC 0x0c06272e */
if(!s->budget--) { s->failed_pc=0x0c06272eu; return 0; }
r[12]=0x00000002u;
goto P_0c062730;
P_0c062730: /* original 2cc8, guest PC 0x0c062730 */
if(!s->budget--) { s->failed_pc=0x0c062730u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c062732;
P_0c062732: /* original 8b01, guest PC 0x0c062732 */
if(!s->budget--) { s->failed_pc=0x0c062732u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062738; }
goto P_0c062734;
P_0c062734: /* original a08a, guest PC 0x0c062734 */
if(!s->budget--) { s->failed_pc=0x0c062734u; return 0; }
goto P_0c06284c;
P_0c062736: /* original 0009, guest PC 0x0c062736 */
if(!s->budget--) { s->failed_pc=0x0c062736u; return 0; }
goto P_0c062738;
P_0c062738: /* original 53e4, guest PC 0x0c062738 */
if(!s->budget--) { s->failed_pc=0x0c062738u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c06273a;
P_0c06273a: /* original 52e3, guest PC 0x0c06273a */
if(!s->budget--) { s->failed_pc=0x0c06273au; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c06273c;
P_0c06273c: /* original 51d3, guest PC 0x0c06273c */
if(!s->budget--) { s->failed_pc=0x0c06273cu; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c06273e;
P_0c06273e: /* original 323c, guest PC 0x0c06273e */
if(!s->budget--) { s->failed_pc=0x0c06273eu; return 0; }
r[2]+=r[3];
goto P_0c062740;
P_0c062740: /* original 3210, guest PC 0x0c062740 */
if(!s->budget--) { s->failed_pc=0x0c062740u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c062742;
P_0c062742: /* original 8b7a, guest PC 0x0c062742 */
if(!s->budget--) { s->failed_pc=0x0c062742u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06283a; }
goto P_0c062744;
P_0c062744: /* original 51e3, guest PC 0x0c062744 */
if(!s->budget--) { s->failed_pc=0x0c062744u; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c062746;
P_0c062746: /* original d215, guest PC 0x0c062746 */
if(!s->budget--) { s->failed_pc=0x0c062746u; return 0; }
r[2]=read(ram,0x0c06279cu,4);
goto P_0c062748;
P_0c062748: /* original 420b, guest PC 0x0c062748 */
if(!s->budget--) { s->failed_pc=0x0c062748u; return 0; }
target=r[2];
r[16]=code_base|0x0c06274cu;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06274cu) { target=s->pc; goto dispatch; }
goto P_0c06274c;
P_0c06274a: /* original e020, guest PC 0x0c06274a */
if(!s->budget--) { s->failed_pc=0x0c06274au; return 0; }
r[0]=0x00000020u;
goto P_0c06274c;
P_0c06274c: /* original 2008, guest PC 0x0c06274c */
if(!s->budget--) { s->failed_pc=0x0c06274cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06274e;
P_0c06274e: /* original 892a, guest PC 0x0c06274e */
if(!s->budget--) { s->failed_pc=0x0c06274eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0627a6; }
goto P_0c062750;
P_0c062750: /* original be9e, guest PC 0x0c062750 */
if(!s->budget--) { s->failed_pc=0x0c062750u; return 0; }
target=code_base|0x0c062490u; r[16]=code_base|0x0c062754u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062754u) { target=s->pc; goto dispatch; }
goto P_0c062754;
P_0c062752: /* original 0009, guest PC 0x0c062752 */
if(!s->budget--) { s->failed_pc=0x0c062752u; return 0; }
goto P_0c062754;
P_0c062754: /* original 6a03, guest PC 0x0c062754 */
if(!s->budget--) { s->failed_pc=0x0c062754u; return 0; }
r[10]=r[0];
goto P_0c062756;
P_0c062756: /* original 2aa8, guest PC 0x0c062756 */
if(!s->budget--) { s->failed_pc=0x0c062756u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c062758;
P_0c062758: /* original 8b01, guest PC 0x0c062758 */
if(!s->budget--) { s->failed_pc=0x0c062758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06275e; }
goto P_0c06275a;
P_0c06275a: /* original a08f, guest PC 0x0c06275a */
if(!s->budget--) { s->failed_pc=0x0c06275au; return 0; }
r[0]=0x00000003u;
goto P_0c06287c;
P_0c06275c: /* original e003, guest PC 0x0c06275c */
if(!s->budget--) { s->failed_pc=0x0c06275cu; return 0; }
r[0]=0x00000003u;
goto P_0c06275e;
P_0c06275e: /* original e4e0, guest PC 0x0c06275e */
if(!s->budget--) { s->failed_pc=0x0c06275eu; return 0; }
r[4]=0xffffffe0u;
goto P_0c062760;
P_0c062760: /* original 52e3, guest PC 0x0c062760 */
if(!s->budget--) { s->failed_pc=0x0c062760u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062762;
P_0c062762: /* original 1a23, guest PC 0x0c062762 */
if(!s->budget--) { s->failed_pc=0x0c062762u; return 0; }
write(ram,r[10]+12,r[2],4);
goto P_0c062764;
P_0c062764: /* original 53e3, guest PC 0x0c062764 */
if(!s->budget--) { s->failed_pc=0x0c062764u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c062766;
P_0c062766: /* original 731f, guest PC 0x0c062766 */
if(!s->budget--) { s->failed_pc=0x0c062766u; return 0; }
r[3]+=0x0000001fu;
goto P_0c062768;
P_0c062768: /* original 2349, guest PC 0x0c062768 */
if(!s->budget--) { s->failed_pc=0x0c062768u; return 0; }
r[3]&=r[4];
goto P_0c06276a;
P_0c06276a: /* original 1e33, guest PC 0x0c06276a */
if(!s->budget--) { s->failed_pc=0x0c06276au; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c06276c;
P_0c06276c: /* original 53a3, guest PC 0x0c06276c */
if(!s->budget--) { s->failed_pc=0x0c06276cu; return 0; }
r[3]=read(ram,r[10]+12,4);
goto P_0c06276e;
P_0c06276e: /* original 52e3, guest PC 0x0c06276e */
if(!s->budget--) { s->failed_pc=0x0c06276eu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062770;
P_0c062770: /* original 3238, guest PC 0x0c062770 */
if(!s->budget--) { s->failed_pc=0x0c062770u; return 0; }
r[2]-=r[3];
goto P_0c062772;
P_0c062772: /* original 6323, guest PC 0x0c062772 */
if(!s->budget--) { s->failed_pc=0x0c062772u; return 0; }
r[3]=r[2];
goto P_0c062774;
P_0c062774: /* original 1a24, guest PC 0x0c062774 */
if(!s->budget--) { s->failed_pc=0x0c062774u; return 0; }
write(ram,r[10]+16,r[2],4);
goto P_0c062776;
P_0c062776: /* original 51e4, guest PC 0x0c062776 */
if(!s->budget--) { s->failed_pc=0x0c062776u; return 0; }
r[1]=read(ram,r[14]+16,4);
goto P_0c062778;
P_0c062778: /* original 3138, guest PC 0x0c062778 */
if(!s->budget--) { s->failed_pc=0x0c062778u; return 0; }
r[1]-=r[3];
goto P_0c06277a;
P_0c06277a: /* original 1e14, guest PC 0x0c06277a */
if(!s->budget--) { s->failed_pc=0x0c06277au; return 0; }
write(ram,r[14]+16,r[1],4);
goto P_0c06277c;
P_0c06277c: /* original 56e1, guest PC 0x0c06277c */
if(!s->budget--) { s->failed_pc=0x0c06277cu; return 0; }
r[6]=read(ram,r[14]+4,4);
goto P_0c06277e;
P_0c06277e: /* original 2668, guest PC 0x0c06277e */
if(!s->budget--) { s->failed_pc=0x0c06277eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c062780;
P_0c062780: /* original 8b0e, guest PC 0x0c062780 */
if(!s->budget--) { s->failed_pc=0x0c062780u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0627a0; }
goto P_0c062782;
P_0c062782: /* original 66a3, guest PC 0x0c062782 */
if(!s->budget--) { s->failed_pc=0x0c062782u; return 0; }
r[6]=r[10];
goto P_0c062784;
P_0c062784: /* original 65b3, guest PC 0x0c062784 */
if(!s->budget--) { s->failed_pc=0x0c062784u; return 0; }
r[5]=r[11];
goto P_0c062786;
P_0c062786: /* original bead, guest PC 0x0c062786 */
if(!s->budget--) { s->failed_pc=0x0c062786u; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c06278au;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06278au) { target=s->pc; goto dispatch; }
goto P_0c06278a;
P_0c062788: /* original 6493, guest PC 0x0c062788 */
if(!s->budget--) { s->failed_pc=0x0c062788u; return 0; }
r[4]=r[9];
goto P_0c06278a;
P_0c06278a: /* original a00c, guest PC 0x0c06278a */
if(!s->budget--) { s->failed_pc=0x0c06278au; return 0; }
goto P_0c0627a6;
P_0c06278c: /* original 0009, guest PC 0x0c06278c */
if(!s->budget--) { s->failed_pc=0x0c06278cu; return 0; }
if(!vf3_matrix_family(0x0c06278eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06278eu; return 0; } return 1;
P_0c0627a0: /* original 65a3, guest PC 0x0c0627a0 */
if(!s->budget--) { s->failed_pc=0x0c0627a0u; return 0; }
r[5]=r[10];
goto P_0c0627a2;
P_0c0627a2: /* original beb1, guest PC 0x0c0627a2 */
if(!s->budget--) { s->failed_pc=0x0c0627a2u; return 0; }
target=code_base|0x0c062508u; r[16]=code_base|0x0c0627a6u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0627a6u) { target=s->pc; goto dispatch; }
goto P_0c0627a6;
P_0c0627a4: /* original 64b3, guest PC 0x0c0627a4 */
if(!s->budget--) { s->failed_pc=0x0c0627a4u; return 0; }
r[4]=r[11];
goto P_0c0627a6;
P_0c0627a6: /* original 56d4, guest PC 0x0c0627a6 */
if(!s->budget--) { s->failed_pc=0x0c0627a6u; return 0; }
r[6]=read(ram,r[13]+16,4);
goto P_0c0627a8;
P_0c0627a8: /* original 55d3, guest PC 0x0c0627a8 */
if(!s->budget--) { s->failed_pc=0x0c0627a8u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0627aa;
P_0c0627aa: /* original bed3, guest PC 0x0c0627aa */
if(!s->budget--) { s->failed_pc=0x0c0627aau; return 0; }
target=code_base|0x0c062554u; r[16]=code_base|0x0c0627aeu;
r[4]=read(ram,r[14]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0627aeu) { target=s->pc; goto dispatch; }
goto P_0c0627ae;
P_0c0627ac: /* original 54e3, guest PC 0x0c0627ac */
if(!s->budget--) { s->failed_pc=0x0c0627acu; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0627ae;
P_0c0627ae: /* original 54e3, guest PC 0x0c0627ae */
if(!s->budget--) { s->failed_pc=0x0c0627aeu; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0627b0;
P_0c0627b0: /* original 57d3, guest PC 0x0c0627b0 */
if(!s->budget--) { s->failed_pc=0x0c0627b0u; return 0; }
r[7]=read(ram,r[13]+12,4);
goto P_0c0627b2;
P_0c0627b2: /* original 3748, guest PC 0x0c0627b2 */
if(!s->budget--) { s->failed_pc=0x0c0627b2u; return 0; }
r[7]-=r[4];
goto P_0c0627b4;
P_0c0627b4: /* original 1d43, guest PC 0x0c0627b4 */
if(!s->budget--) { s->failed_pc=0x0c0627b4u; return 0; }
write(ram,r[13]+12,r[4],4);
goto P_0c0627b6;
P_0c0627b6: /* original 53d4, guest PC 0x0c0627b6 */
if(!s->budget--) { s->failed_pc=0x0c0627b6u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c0627b8;
P_0c0627b8: /* original 52e3, guest PC 0x0c0627b8 */
if(!s->budget--) { s->failed_pc=0x0c0627b8u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0627ba;
P_0c0627ba: /* original 323c, guest PC 0x0c0627ba */
if(!s->budget--) { s->failed_pc=0x0c0627bau; return 0; }
r[2]+=r[3];
goto P_0c0627bc;
P_0c0627bc: /* original 60c3, guest PC 0x0c0627bc */
if(!s->budget--) { s->failed_pc=0x0c0627bcu; return 0; }
r[0]=r[12];
goto P_0c0627be;
P_0c0627be: /* original 0009, guest PC 0x0c0627be */
if(!s->budget--) { s->failed_pc=0x0c0627beu; return 0; }
goto P_0c0627c0;
P_0c0627c0: /* original 8801, guest PC 0x0c0627c0 */
if(!s->budget--) { s->failed_pc=0x0c0627c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0627c2;
P_0c0627c2: /* original 8f05, guest PC 0x0c0627c2 */
if(!s->budget--) { s->failed_pc=0x0c0627c2u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+12,r[2],4);
if(!cond) { goto P_0c0627d0; }
goto P_0c0627c6;
P_0c0627c4: /* original 1e23, guest PC 0x0c0627c4 */
if(!s->budget--) { s->failed_pc=0x0c0627c4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0627c6;
P_0c0627c6: /* original 52d5, guest PC 0x0c0627c6 */
if(!s->budget--) { s->failed_pc=0x0c0627c6u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0627c8;
P_0c0627c8: /* original 53d3, guest PC 0x0c0627c8 */
if(!s->budget--) { s->failed_pc=0x0c0627c8u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c0627ca;
P_0c0627ca: /* original 1237, guest PC 0x0c0627ca */
if(!s->budget--) { s->failed_pc=0x0c0627cau; return 0; }
write(ram,r[2]+28,r[3],4);
goto P_0c0627cc;
P_0c0627cc: /* original a01f, guest PC 0x0c0627cc */
if(!s->budget--) { s->failed_pc=0x0c0627ccu; return 0; }
goto P_0c06280e;
P_0c0627ce: /* original 0009, guest PC 0x0c0627ce */
if(!s->budget--) { s->failed_pc=0x0c0627ceu; return 0; }
goto P_0c0627d0;
P_0c0627d0: /* original 51d5, guest PC 0x0c0627d0 */
if(!s->budget--) { s->failed_pc=0x0c0627d0u; return 0; }
r[1]=read(ram,r[13]+20,4);
goto P_0c0627d2;
P_0c0627d2: /* original e600, guest PC 0x0c0627d2 */
if(!s->budget--) { s->failed_pc=0x0c0627d2u; return 0; }
r[6]=0x00000000u;
goto P_0c0627d4;
P_0c0627d4: /* original 53d3, guest PC 0x0c0627d4 */
if(!s->budget--) { s->failed_pc=0x0c0627d4u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c0627d6;
P_0c0627d6: /* original 4709, guest PC 0x0c0627d6 */
if(!s->budget--) { s->failed_pc=0x0c0627d6u; return 0; }
r[7]>>=2;
goto P_0c0627d8;
P_0c0627d8: /* original 1132, guest PC 0x0c0627d8 */
if(!s->budget--) { s->failed_pc=0x0c0627d8u; return 0; }
write(ram,r[1]+8,r[3],4);
goto P_0c0627da;
P_0c0627da: /* original 6563, guest PC 0x0c0627da */
if(!s->budget--) { s->failed_pc=0x0c0627dau; return 0; }
r[5]=r[6];
goto P_0c0627dc;
P_0c0627dc: /* original 6463, guest PC 0x0c0627dc */
if(!s->budget--) { s->failed_pc=0x0c0627dcu; return 0; }
r[4]=r[6];
goto P_0c0627de;
P_0c0627de: /* original 6c73, guest PC 0x0c0627de */
if(!s->budget--) { s->failed_pc=0x0c0627deu; return 0; }
r[12]=r[7];
goto P_0c0627e0;
P_0c0627e0: /* original a012, guest PC 0x0c0627e0 */
if(!s->budget--) { s->failed_pc=0x0c0627e0u; return 0; }
r[12]<<=2;
goto P_0c062808;
P_0c0627e2: /* original 4c08, guest PC 0x0c0627e2 */
if(!s->budget--) { s->failed_pc=0x0c0627e2u; return 0; }
r[12]<<=2;
goto P_0c0627e4;
P_0c0627e4: /* original 50d5, guest PC 0x0c0627e4 */
if(!s->budget--) { s->failed_pc=0x0c0627e4u; return 0; }
r[0]=read(ram,r[13]+20,4);
goto P_0c0627e6;
P_0c0627e6: /* original 6303, guest PC 0x0c0627e6 */
if(!s->budget--) { s->failed_pc=0x0c0627e6u; return 0; }
r[3]=r[0];
goto P_0c0627e8;
P_0c0627e8: /* original 730c, guest PC 0x0c0627e8 */
if(!s->budget--) { s->failed_pc=0x0c0627e8u; return 0; }
r[3]+=0x0000000cu;
goto P_0c0627ea;
P_0c0627ea: /* original 335c, guest PC 0x0c0627ea */
if(!s->budget--) { s->failed_pc=0x0c0627eau; return 0; }
r[3]+=r[5];
goto P_0c0627ec;
P_0c0627ec: /* original 6232, guest PC 0x0c0627ec */
if(!s->budget--) { s->failed_pc=0x0c0627ecu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0627ee;
P_0c0627ee: /* original 2228, guest PC 0x0c0627ee */
if(!s->budget--) { s->failed_pc=0x0c0627eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0627f0;
P_0c0627f0: /* original 8d08, guest PC 0x0c0627f0 */
if(!s->budget--) { s->failed_pc=0x0c0627f0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(cond) { goto P_0c062804; }
goto P_0c0627f4;
P_0c0627f2: /* original 7601, guest PC 0x0c0627f2 */
if(!s->budget--) { s->failed_pc=0x0c0627f2u; return 0; }
r[6]+=0x00000001u;
goto P_0c0627f4;
P_0c0627f4: /* original 50d5, guest PC 0x0c0627f4 */
if(!s->budget--) { s->failed_pc=0x0c0627f4u; return 0; }
r[0]=read(ram,r[13]+20,4);
goto P_0c0627f6;
P_0c0627f6: /* original 6303, guest PC 0x0c0627f6 */
if(!s->budget--) { s->failed_pc=0x0c0627f6u; return 0; }
r[3]=r[0];
goto P_0c0627f8;
P_0c0627f8: /* original 730c, guest PC 0x0c0627f8 */
if(!s->budget--) { s->failed_pc=0x0c0627f8u; return 0; }
r[3]+=0x0000000cu;
goto P_0c0627fa;
P_0c0627fa: /* original 334c, guest PC 0x0c0627fa */
if(!s->budget--) { s->failed_pc=0x0c0627fau; return 0; }
r[3]+=r[4];
goto P_0c0627fc;
P_0c0627fc: /* original 6232, guest PC 0x0c0627fc */
if(!s->budget--) { s->failed_pc=0x0c0627fcu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0627fe;
P_0c0627fe: /* original 5127, guest PC 0x0c0627fe */
if(!s->budget--) { s->failed_pc=0x0c0627feu; return 0; }
r[1]=read(ram,r[2]+28,4);
goto P_0c062800;
P_0c062800: /* original 31c8, guest PC 0x0c062800 */
if(!s->budget--) { s->failed_pc=0x0c062800u; return 0; }
r[1]-=r[12];
goto P_0c062802;
P_0c062802: /* original 1217, guest PC 0x0c062802 */
if(!s->budget--) { s->failed_pc=0x0c062802u; return 0; }
write(ram,r[2]+28,r[1],4);
goto P_0c062804;
P_0c062804: /* original 7404, guest PC 0x0c062804 */
if(!s->budget--) { s->failed_pc=0x0c062804u; return 0; }
r[4]+=0x00000004u;
goto P_0c062806;
P_0c062806: /* original 7504, guest PC 0x0c062806 */
if(!s->budget--) { s->failed_pc=0x0c062806u; return 0; }
r[5]+=0x00000004u;
goto P_0c062808;
P_0c062808: /* original e710, guest PC 0x0c062808 */
if(!s->budget--) { s->failed_pc=0x0c062808u; return 0; }
r[7]=0x00000010u;
goto P_0c06280a;
P_0c06280a: /* original 3673, guest PC 0x0c06280a */
if(!s->budget--) { s->failed_pc=0x0c06280au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c06280c;
P_0c06280c: /* original 8bea, guest PC 0x0c06280c */
if(!s->budget--) { s->failed_pc=0x0c06280cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0627e4; }
goto P_0c06280e;
P_0c06280e: /* original 5ce2, guest PC 0x0c06280e */
if(!s->budget--) { s->failed_pc=0x0c06280eu; return 0; }
r[12]=read(ram,r[14]+8,4);
goto P_0c062810;
P_0c062810: /* original 2cc8, guest PC 0x0c062810 */
if(!s->budget--) { s->failed_pc=0x0c062810u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c062812;
P_0c062812: /* original 8912, guest PC 0x0c062812 */
if(!s->budget--) { s->failed_pc=0x0c062812u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06283a; }
goto P_0c062814;
P_0c062814: /* original 53e4, guest PC 0x0c062814 */
if(!s->budget--) { s->failed_pc=0x0c062814u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062816;
P_0c062816: /* original 52e3, guest PC 0x0c062816 */
if(!s->budget--) { s->failed_pc=0x0c062816u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062818;
P_0c062818: /* original 51c3, guest PC 0x0c062818 */
if(!s->budget--) { s->failed_pc=0x0c062818u; return 0; }
r[1]=read(ram,r[12]+12,4);
goto P_0c06281a;
P_0c06281a: /* original 323c, guest PC 0x0c06281a */
if(!s->budget--) { s->failed_pc=0x0c06281au; return 0; }
r[2]+=r[3];
goto P_0c06281c;
P_0c06281c: /* original 3210, guest PC 0x0c06281c */
if(!s->budget--) { s->failed_pc=0x0c06281cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c06281e;
P_0c06281e: /* original 8b0c, guest PC 0x0c06281e */
if(!s->budget--) { s->failed_pc=0x0c06281eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06283a; }
goto P_0c062820;
P_0c062820: /* original 53c4, guest PC 0x0c062820 */
if(!s->budget--) { s->failed_pc=0x0c062820u; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c062822;
P_0c062822: /* original 66c3, guest PC 0x0c062822 */
if(!s->budget--) { s->failed_pc=0x0c062822u; return 0; }
r[6]=r[12];
goto P_0c062824;
P_0c062824: /* original 52e4, guest PC 0x0c062824 */
if(!s->budget--) { s->failed_pc=0x0c062824u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c062826;
P_0c062826: /* original 65b3, guest PC 0x0c062826 */
if(!s->budget--) { s->failed_pc=0x0c062826u; return 0; }
r[5]=r[11];
goto P_0c062828;
P_0c062828: /* original 323c, guest PC 0x0c062828 */
if(!s->budget--) { s->failed_pc=0x0c062828u; return 0; }
r[2]+=r[3];
goto P_0c06282a;
P_0c06282a: /* original 1e24, guest PC 0x0c06282a */
if(!s->budget--) { s->failed_pc=0x0c06282au; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c06282c;
P_0c06282c: /* original be7a, guest PC 0x0c06282c */
if(!s->budget--) { s->failed_pc=0x0c06282cu; return 0; }
target=code_base|0x0c062524u; r[16]=code_base|0x0c062830u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062830u) { target=s->pc; goto dispatch; }
goto P_0c062830;
P_0c06282e: /* original 6493, guest PC 0x0c06282e */
if(!s->budget--) { s->failed_pc=0x0c06282eu; return 0; }
r[4]=r[9];
goto P_0c062830;
P_0c062830: /* original be43, guest PC 0x0c062830 */
if(!s->budget--) { s->failed_pc=0x0c062830u; return 0; }
target=code_base|0x0c0624bau; r[16]=code_base|0x0c062834u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062834u) { target=s->pc; goto dispatch; }
goto P_0c062834;
P_0c062832: /* original 64c3, guest PC 0x0c062832 */
if(!s->budget--) { s->failed_pc=0x0c062832u; return 0; }
r[4]=r[12];
goto P_0c062834;
P_0c062834: /* original a001, guest PC 0x0c062834 */
if(!s->budget--) { s->failed_pc=0x0c062834u; return 0; }
goto P_0c06283a;
P_0c062836: /* original 0009, guest PC 0x0c062836 */
if(!s->budget--) { s->failed_pc=0x0c062836u; return 0; }
goto P_0c062838;
P_0c062838: /* original 5dd2, guest PC 0x0c062838 */
if(!s->budget--) { s->failed_pc=0x0c062838u; return 0; }
r[13]=read(ram,r[13]+8,4);
goto P_0c06283a;
P_0c06283a: /* original 2dd8, guest PC 0x0c06283a */
if(!s->budget--) { s->failed_pc=0x0c06283au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c06283c;
P_0c06283c: /* original 891d, guest PC 0x0c06283c */
if(!s->budget--) { s->failed_pc=0x0c06283cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06287a; }
goto P_0c06283e;
P_0c06283e: /* original 53d3, guest PC 0x0c06283e */
if(!s->budget--) { s->failed_pc=0x0c06283eu; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c062840;
P_0c062840: /* original 52e3, guest PC 0x0c062840 */
if(!s->budget--) { s->failed_pc=0x0c062840u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062842;
P_0c062842: /* original 3237, guest PC 0x0c062842 */
if(!s->budget--) { s->failed_pc=0x0c062842u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c062844;
P_0c062844: /* original 89f8, guest PC 0x0c062844 */
if(!s->budget--) { s->failed_pc=0x0c062844u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062838; }
goto P_0c062846;
P_0c062846: /* original a012, guest PC 0x0c062846 */
if(!s->budget--) { s->failed_pc=0x0c062846u; return 0; }
goto P_0c06286e;
P_0c062848: /* original 0009, guest PC 0x0c062848 */
if(!s->budget--) { s->failed_pc=0x0c062848u; return 0; }
goto P_0c06284a;
P_0c06284a: /* original 5ee2, guest PC 0x0c06284a */
if(!s->budget--) { s->failed_pc=0x0c06284au; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c06284c;
P_0c06284c: /* original 2ee8, guest PC 0x0c06284c */
if(!s->budget--) { s->failed_pc=0x0c06284cu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06284e;
P_0c06284e: /* original 8903, guest PC 0x0c06284e */
if(!s->budget--) { s->failed_pc=0x0c06284eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062858; }
goto P_0c062850;
P_0c062850: /* original 52d3, guest PC 0x0c062850 */
if(!s->budget--) { s->failed_pc=0x0c062850u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c062852;
P_0c062852: /* original 53e3, guest PC 0x0c062852 */
if(!s->budget--) { s->failed_pc=0x0c062852u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c062854;
P_0c062854: /* original 3323, guest PC 0x0c062854 */
if(!s->budget--) { s->failed_pc=0x0c062854u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c062856;
P_0c062856: /* original 8bf8, guest PC 0x0c062856 */
if(!s->budget--) { s->failed_pc=0x0c062856u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06284a; }
goto P_0c062858;
P_0c062858: /* original 2ee8, guest PC 0x0c062858 */
if(!s->budget--) { s->failed_pc=0x0c062858u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06285a;
P_0c06285a: /* original 8b02, guest PC 0x0c06285a */
if(!s->budget--) { s->failed_pc=0x0c06285au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062862; }
goto P_0c06285c;
P_0c06285c: /* original a00d, guest PC 0x0c06285c */
if(!s->budget--) { s->failed_pc=0x0c06285cu; return 0; }
goto P_0c06287a;
P_0c06285e: /* original 0009, guest PC 0x0c06285e */
if(!s->budget--) { s->failed_pc=0x0c06285eu; return 0; }
goto P_0c062860;
P_0c062860: /* original 5dd2, guest PC 0x0c062860 */
if(!s->budget--) { s->failed_pc=0x0c062860u; return 0; }
r[13]=read(ram,r[13]+8,4);
goto P_0c062862;
P_0c062862: /* original 2dd8, guest PC 0x0c062862 */
if(!s->budget--) { s->failed_pc=0x0c062862u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c062864;
P_0c062864: /* original 8909, guest PC 0x0c062864 */
if(!s->budget--) { s->failed_pc=0x0c062864u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06287a; }
goto P_0c062866;
P_0c062866: /* original 53d3, guest PC 0x0c062866 */
if(!s->budget--) { s->failed_pc=0x0c062866u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c062868;
P_0c062868: /* original 52e3, guest PC 0x0c062868 */
if(!s->budget--) { s->failed_pc=0x0c062868u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c06286a;
P_0c06286a: /* original 3237, guest PC 0x0c06286a */
if(!s->budget--) { s->failed_pc=0x0c06286au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c06286c;
P_0c06286c: /* original 89f8, guest PC 0x0c06286c */
if(!s->budget--) { s->failed_pc=0x0c06286cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062860; }
goto P_0c06286e;
P_0c06286e: /* original 2dd8, guest PC 0x0c06286e */
if(!s->budget--) { s->failed_pc=0x0c06286eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c062870;
P_0c062870: /* original 8903, guest PC 0x0c062870 */
if(!s->budget--) { s->failed_pc=0x0c062870u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06287a; }
goto P_0c062872;
P_0c062872: /* original 2ee8, guest PC 0x0c062872 */
if(!s->budget--) { s->failed_pc=0x0c062872u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c062874;
P_0c062874: /* original 8901, guest PC 0x0c062874 */
if(!s->budget--) { s->failed_pc=0x0c062874u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06287a; }
goto P_0c062876;
P_0c062876: /* original af2e, guest PC 0x0c062876 */
if(!s->budget--) { s->failed_pc=0x0c062876u; return 0; }
goto P_0c0626d6;
P_0c062878: /* original 0009, guest PC 0x0c062878 */
if(!s->budget--) { s->failed_pc=0x0c062878u; return 0; }
goto P_0c06287a;
P_0c06287a: /* original e000, guest PC 0x0c06287a */
if(!s->budget--) { s->failed_pc=0x0c06287au; return 0; }
r[0]=0x00000000u;
goto P_0c06287c;
P_0c06287c: /* original 4f26, guest PC 0x0c06287c */
if(!s->budget--) { s->failed_pc=0x0c06287cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06287e;
P_0c06287e: /* original 69f6, guest PC 0x0c06287e */
if(!s->budget--) { s->failed_pc=0x0c06287eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c062880;
P_0c062880: /* original 6af6, guest PC 0x0c062880 */
if(!s->budget--) { s->failed_pc=0x0c062880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c062882;
P_0c062882: /* original 6bf6, guest PC 0x0c062882 */
if(!s->budget--) { s->failed_pc=0x0c062882u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c062884;
P_0c062884: /* original 6cf6, guest PC 0x0c062884 */
if(!s->budget--) { s->failed_pc=0x0c062884u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c062886;
P_0c062886: /* original 6df6, guest PC 0x0c062886 */
if(!s->budget--) { s->failed_pc=0x0c062886u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062888;
P_0c062888: /* original 000b, guest PC 0x0c062888 */
if(!s->budget--) { s->failed_pc=0x0c062888u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06288a: /* original 6ef6, guest PC 0x0c06288a */
if(!s->budget--) { s->failed_pc=0x0c06288au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06288cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
