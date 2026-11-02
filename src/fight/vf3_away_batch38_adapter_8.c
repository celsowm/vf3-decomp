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
int vf3_away_batch38_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0955b0u: goto P_0c0955b0;
case 0x0c0955b2u: goto P_0c0955b2;
case 0x0c0955b4u: goto P_0c0955b4;
case 0x0c0955b6u: goto P_0c0955b6;
case 0x0c0955b8u: goto P_0c0955b8;
case 0x0c0955bau: goto P_0c0955ba;
case 0x0c0955bcu: goto P_0c0955bc;
case 0x0c0955beu: goto P_0c0955be;
case 0x0c0955c0u: goto P_0c0955c0;
case 0x0c0955c2u: goto P_0c0955c2;
case 0x0c0955c4u: goto P_0c0955c4;
case 0x0c0955c6u: goto P_0c0955c6;
case 0x0c0955c8u: goto P_0c0955c8;
case 0x0c0955cau: goto P_0c0955ca;
case 0x0c0955ccu: goto P_0c0955cc;
case 0x0c0955ceu: goto P_0c0955ce;
case 0x0c0955d0u: goto P_0c0955d0;
case 0x0c0955d2u: goto P_0c0955d2;
case 0x0c0955d4u: goto P_0c0955d4;
case 0x0c0955d6u: goto P_0c0955d6;
case 0x0c0955d8u: goto P_0c0955d8;
case 0x0c0955dau: goto P_0c0955da;
case 0x0c0955dcu: goto P_0c0955dc;
case 0x0c0955deu: goto P_0c0955de;
case 0x0c0955e0u: goto P_0c0955e0;
case 0x0c0955e2u: goto P_0c0955e2;
case 0x0c0955e4u: goto P_0c0955e4;
case 0x0c0955e6u: goto P_0c0955e6;
case 0x0c0955e8u: goto P_0c0955e8;
case 0x0c0955eau: goto P_0c0955ea;
case 0x0c0955ecu: goto P_0c0955ec;
case 0x0c0955eeu: goto P_0c0955ee;
case 0x0c0955f0u: goto P_0c0955f0;
case 0x0c0955f2u: goto P_0c0955f2;
case 0x0c0955f4u: goto P_0c0955f4;
case 0x0c0955f6u: goto P_0c0955f6;
case 0x0c0955f8u: goto P_0c0955f8;
case 0x0c0955fau: goto P_0c0955fa;
case 0x0c0955fcu: goto P_0c0955fc;
case 0x0c0955feu: goto P_0c0955fe;
case 0x0c095600u: goto P_0c095600;
case 0x0c095602u: goto P_0c095602;
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
case 0x0c0a7850u: goto P_0c0a7850;
case 0x0c0a7852u: goto P_0c0a7852;
case 0x0c0a7854u: goto P_0c0a7854;
case 0x0c0a7856u: goto P_0c0a7856;
case 0x0c0a7858u: goto P_0c0a7858;
case 0x0c0a785au: goto P_0c0a785a;
case 0x0c0a785cu: goto P_0c0a785c;
case 0x0c0a785eu: goto P_0c0a785e;
case 0x0c0a7860u: goto P_0c0a7860;
case 0x0c0a7862u: goto P_0c0a7862;
case 0x0c0a7864u: goto P_0c0a7864;
case 0x0c0a7866u: goto P_0c0a7866;
case 0x0c0a7868u: goto P_0c0a7868;
case 0x0c0a786au: goto P_0c0a786a;
case 0x0c0a786cu: goto P_0c0a786c;
case 0x0c0a786eu: goto P_0c0a786e;
case 0x0c0a7870u: goto P_0c0a7870;
case 0x0c0a7872u: goto P_0c0a7872;
case 0x0c0a7874u: goto P_0c0a7874;
case 0x0c0a7876u: goto P_0c0a7876;
case 0x0c0a7878u: goto P_0c0a7878;
case 0x0c0a787au: goto P_0c0a787a;
case 0x0c0a787cu: goto P_0c0a787c;
case 0x0c0a787eu: goto P_0c0a787e;
case 0x0c0a7880u: goto P_0c0a7880;
case 0x0c0a7882u: goto P_0c0a7882;
case 0x0c0a7884u: goto P_0c0a7884;
case 0x0c0a7886u: goto P_0c0a7886;
case 0x0c0a7888u: goto P_0c0a7888;
case 0x0c0a788au: goto P_0c0a788a;
case 0x0c0a788cu: goto P_0c0a788c;
case 0x0c0a788eu: goto P_0c0a788e;
case 0x0c0a7890u: goto P_0c0a7890;
case 0x0c0a7892u: goto P_0c0a7892;
case 0x0c0a7894u: goto P_0c0a7894;
case 0x0c0a7896u: goto P_0c0a7896;
case 0x0c0a7898u: goto P_0c0a7898;
case 0x0c0a789au: goto P_0c0a789a;
case 0x0c0a789cu: goto P_0c0a789c;
case 0x0c0a789eu: goto P_0c0a789e;
case 0x0c0a78a0u: goto P_0c0a78a0;
case 0x0c0a78a2u: goto P_0c0a78a2;
case 0x0c0a78a4u: goto P_0c0a78a4;
case 0x0c0a78a6u: goto P_0c0a78a6;
case 0x0c0a78a8u: goto P_0c0a78a8;
case 0x0c0a78aau: goto P_0c0a78aa;
case 0x0c0c1208u: goto P_0c0c1208;
case 0x0c0c120au: goto P_0c0c120a;
case 0x0c0c120cu: goto P_0c0c120c;
case 0x0c0c120eu: goto P_0c0c120e;
case 0x0c0c1210u: goto P_0c0c1210;
case 0x0c0c1212u: goto P_0c0c1212;
case 0x0c0c1214u: goto P_0c0c1214;
case 0x0c0c1216u: goto P_0c0c1216;
case 0x0c0c1218u: goto P_0c0c1218;
case 0x0c0c121au: goto P_0c0c121a;
case 0x0c0c121cu: goto P_0c0c121c;
case 0x0c0c121eu: goto P_0c0c121e;
case 0x0c0c1220u: goto P_0c0c1220;
case 0x0c0c1222u: goto P_0c0c1222;
case 0x0c0c1224u: goto P_0c0c1224;
case 0x0c0c1226u: goto P_0c0c1226;
case 0x0c0c1228u: goto P_0c0c1228;
case 0x0c0c122au: goto P_0c0c122a;
case 0x0c0c122cu: goto P_0c0c122c;
case 0x0c0c122eu: goto P_0c0c122e;
case 0x0c0c1230u: goto P_0c0c1230;
case 0x0c0c1232u: goto P_0c0c1232;
case 0x0c0c1234u: goto P_0c0c1234;
case 0x0c0c1236u: goto P_0c0c1236;
case 0x0c0c1238u: goto P_0c0c1238;
case 0x0c0c123au: goto P_0c0c123a;
case 0x0c0c123cu: goto P_0c0c123c;
case 0x0c0c123eu: goto P_0c0c123e;
case 0x0c0c1240u: goto P_0c0c1240;
case 0x0c0c1242u: goto P_0c0c1242;
case 0x0c0c1244u: goto P_0c0c1244;
case 0x0c0c1246u: goto P_0c0c1246;
case 0x0c0c1248u: goto P_0c0c1248;
case 0x0c0c124au: goto P_0c0c124a;
case 0x0c0c124cu: goto P_0c0c124c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0955b0: /* original 4f22, guest PC 0x0c0955b0 */
if(!s->budget--) { s->failed_pc=0x0c0955b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0955b2;
P_0c0955b2: /* original 7ff0, guest PC 0x0c0955b2 */
if(!s->budget--) { s->failed_pc=0x0c0955b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0955b4;
P_0c0955b4: /* original 1f42, guest PC 0x0c0955b4 */
if(!s->budget--) { s->failed_pc=0x0c0955b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0955b6;
P_0c0955b6: /* original 1f51, guest PC 0x0c0955b6 */
if(!s->budget--) { s->failed_pc=0x0c0955b6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0955b8;
P_0c0955b8: /* original 2f62, guest PC 0x0c0955b8 */
if(!s->budget--) { s->failed_pc=0x0c0955b8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0955ba;
P_0c0955ba: /* original 1f73, guest PC 0x0c0955ba */
if(!s->budget--) { s->failed_pc=0x0c0955bau; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c0955bc;
P_0c0955bc: /* original d34e, guest PC 0x0c0955bc */
if(!s->budget--) { s->failed_pc=0x0c0955bcu; return 0; }
r[3]=read(ram,0x0c0956f8u,4);
goto P_0c0955be;
P_0c0955be: /* original 430b, guest PC 0x0c0955be */
if(!s->budget--) { s->failed_pc=0x0c0955beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0955c2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c2u) { target=s->pc; goto dispatch; }
goto P_0c0955c2;
P_0c0955c0: /* original e400, guest PC 0x0c0955c0 */
if(!s->budget--) { s->failed_pc=0x0c0955c0u; return 0; }
r[4]=0x00000000u;
goto P_0c0955c2;
P_0c0955c2: /* original d24e, guest PC 0x0c0955c2 */
if(!s->budget--) { s->failed_pc=0x0c0955c2u; return 0; }
r[2]=read(ram,0x0c0956fcu,4);
goto P_0c0955c4;
P_0c0955c4: /* original 420b, guest PC 0x0c0955c4 */
if(!s->budget--) { s->failed_pc=0x0c0955c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0955c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c8u) { target=s->pc; goto dispatch; }
goto P_0c0955c8;
P_0c0955c6: /* original 0009, guest PC 0x0c0955c6 */
if(!s->budget--) { s->failed_pc=0x0c0955c6u; return 0; }
goto P_0c0955c8;
P_0c0955c8: /* original d34d, guest PC 0x0c0955c8 */
if(!s->budget--) { s->failed_pc=0x0c0955c8u; return 0; }
r[3]=read(ram,0x0c095700u,4);
goto P_0c0955ca;
P_0c0955ca: /* original 430b, guest PC 0x0c0955ca */
if(!s->budget--) { s->failed_pc=0x0c0955cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0955ceu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955ceu) { target=s->pc; goto dispatch; }
goto P_0c0955ce;
P_0c0955cc: /* original 54f6, guest PC 0x0c0955cc */
if(!s->budget--) { s->failed_pc=0x0c0955ccu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0955ce;
P_0c0955ce: /* original d34d, guest PC 0x0c0955ce */
if(!s->budget--) { s->failed_pc=0x0c0955ceu; return 0; }
r[3]=read(ram,0x0c095704u,4);
goto P_0c0955d0;
P_0c0955d0: /* original 430b, guest PC 0x0c0955d0 */
if(!s->budget--) { s->failed_pc=0x0c0955d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955d4u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955d4u) { target=s->pc; goto dispatch; }
goto P_0c0955d4;
P_0c0955d2: /* original 54f5, guest PC 0x0c0955d2 */
if(!s->budget--) { s->failed_pc=0x0c0955d2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0955d4;
P_0c0955d4: /* original d34c, guest PC 0x0c0955d4 */
if(!s->budget--) { s->failed_pc=0x0c0955d4u; return 0; }
r[3]=read(ram,0x0c095708u,4);
goto P_0c0955d6;
P_0c0955d6: /* original 430b, guest PC 0x0c0955d6 */
if(!s->budget--) { s->failed_pc=0x0c0955d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955dau;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955dau) { target=s->pc; goto dispatch; }
goto P_0c0955da;
P_0c0955d8: /* original 54f3, guest PC 0x0c0955d8 */
if(!s->budget--) { s->failed_pc=0x0c0955d8u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0955da;
P_0c0955da: /* original d24c, guest PC 0x0c0955da */
if(!s->budget--) { s->failed_pc=0x0c0955dau; return 0; }
r[2]=read(ram,0x0c09570cu,4);
goto P_0c0955dc;
P_0c0955dc: /* original 420b, guest PC 0x0c0955dc */
if(!s->budget--) { s->failed_pc=0x0c0955dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0955e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955e0u) { target=s->pc; goto dispatch; }
goto P_0c0955e0;
P_0c0955de: /* original e400, guest PC 0x0c0955de */
if(!s->budget--) { s->failed_pc=0x0c0955deu; return 0; }
r[4]=0x00000000u;
goto P_0c0955e0;
P_0c0955e0: /* original 6403, guest PC 0x0c0955e0 */
if(!s->budget--) { s->failed_pc=0x0c0955e0u; return 0; }
r[4]=r[0];
goto P_0c0955e2;
P_0c0955e2: /* original e020, guest PC 0x0c0955e2 */
if(!s->budget--) { s->failed_pc=0x0c0955e2u; return 0; }
r[0]=0x00000020u;
goto P_0c0955e4;
P_0c0955e4: /* original f346, guest PC 0x0c0955e4 */
if(!s->budget--) { s->failed_pc=0x0c0955e4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955e6;
P_0c0955e6: /* original e024, guest PC 0x0c0955e6 */
if(!s->budget--) { s->failed_pc=0x0c0955e6u; return 0; }
r[0]=0x00000024u;
goto P_0c0955e8;
P_0c0955e8: /* original 53f2, guest PC 0x0c0955e8 */
if(!s->budget--) { s->failed_pc=0x0c0955e8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0955ea;
P_0c0955ea: /* original f33a, guest PC 0x0c0955ea */
if(!s->budget--) { s->failed_pc=0x0c0955eau; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955ec;
P_0c0955ec: /* original f346, guest PC 0x0c0955ec */
if(!s->budget--) { s->failed_pc=0x0c0955ecu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955ee;
P_0c0955ee: /* original e028, guest PC 0x0c0955ee */
if(!s->budget--) { s->failed_pc=0x0c0955eeu; return 0; }
r[0]=0x00000028u;
goto P_0c0955f0;
P_0c0955f0: /* original 53f1, guest PC 0x0c0955f0 */
if(!s->budget--) { s->failed_pc=0x0c0955f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0955f2;
P_0c0955f2: /* original f33a, guest PC 0x0c0955f2 */
if(!s->budget--) { s->failed_pc=0x0c0955f2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955f4;
P_0c0955f4: /* original f346, guest PC 0x0c0955f4 */
if(!s->budget--) { s->failed_pc=0x0c0955f4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955f6;
P_0c0955f6: /* original e401, guest PC 0x0c0955f6 */
if(!s->budget--) { s->failed_pc=0x0c0955f6u; return 0; }
r[4]=0x00000001u;
goto P_0c0955f8;
P_0c0955f8: /* original 63f2, guest PC 0x0c0955f8 */
if(!s->budget--) { s->failed_pc=0x0c0955f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0955fa;
P_0c0955fa: /* original 7f10, guest PC 0x0c0955fa */
if(!s->budget--) { s->failed_pc=0x0c0955fau; return 0; }
r[15]+=0x00000010u;
goto P_0c0955fc;
P_0c0955fc: /* original f33a, guest PC 0x0c0955fc */
if(!s->budget--) { s->failed_pc=0x0c0955fcu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955fe;
P_0c0955fe: /* original d344, guest PC 0x0c0955fe */
if(!s->budget--) { s->failed_pc=0x0c0955feu; return 0; }
r[3]=read(ram,0x0c095710u,4);
goto P_0c095600;
P_0c095600: /* original 432b, guest PC 0x0c095600 */
if(!s->budget--) { s->failed_pc=0x0c095600u; return 0; }
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
P_0c095602: /* original 4f26, guest PC 0x0c095602 */
if(!s->budget--) { s->failed_pc=0x0c095602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c095604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095604u; return 0; } return 1;
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
P_0c0a7850: /* original d43f, guest PC 0x0c0a7850 */
if(!s->budget--) { s->failed_pc=0x0c0a7850u; return 0; }
r[4]=read(ram,0x0c0a7950u,4);
goto P_0c0a7852;
P_0c0a7852: /* original e040, guest PC 0x0c0a7852 */
if(!s->budget--) { s->failed_pc=0x0c0a7852u; return 0; }
r[0]=0x00000040u;
goto P_0c0a7854;
P_0c0a7854: /* original f447, guest PC 0x0c0a7854 */
if(!s->budget--) { s->failed_pc=0x0c0a7854u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0a7856;
P_0c0a7856: /* original e044, guest PC 0x0c0a7856 */
if(!s->budget--) { s->failed_pc=0x0c0a7856u; return 0; }
r[0]=0x00000044u;
goto P_0c0a7858;
P_0c0a7858: /* original f457, guest PC 0x0c0a7858 */
if(!s->budget--) { s->failed_pc=0x0c0a7858u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0a785a;
P_0c0a785a: /* original e048, guest PC 0x0c0a785a */
if(!s->budget--) { s->failed_pc=0x0c0a785au; return 0; }
r[0]=0x00000048u;
goto P_0c0a785c;
P_0c0a785c: /* original a000, guest PC 0x0c0a785c */
if(!s->budget--) { s->failed_pc=0x0c0a785cu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a7860;
P_0c0a785e: /* original f467, guest PC 0x0c0a785e */
if(!s->budget--) { s->failed_pc=0x0c0a785eu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a7860;
P_0c0a7860: /* original 2fe6, guest PC 0x0c0a7860 */
if(!s->budget--) { s->failed_pc=0x0c0a7860u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7862;
P_0c0a7862: /* original e040, guest PC 0x0c0a7862 */
if(!s->budget--) { s->failed_pc=0x0c0a7862u; return 0; }
r[0]=0x00000040u;
goto P_0c0a7864;
P_0c0a7864: /* original de3a, guest PC 0x0c0a7864 */
if(!s->budget--) { s->failed_pc=0x0c0a7864u; return 0; }
r[14]=read(ram,0x0c0a7950u,4);
goto P_0c0a7866;
P_0c0a7866: /* original 4f22, guest PC 0x0c0a7866 */
if(!s->budget--) { s->failed_pc=0x0c0a7866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7868;
P_0c0a7868: /* original f4e6, guest PC 0x0c0a7868 */
if(!s->budget--) { s->failed_pc=0x0c0a7868u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a786a;
P_0c0a786a: /* original e044, guest PC 0x0c0a786a */
if(!s->budget--) { s->failed_pc=0x0c0a786au; return 0; }
r[0]=0x00000044u;
goto P_0c0a786c;
P_0c0a786c: /* original f5e6, guest PC 0x0c0a786c */
if(!s->budget--) { s->failed_pc=0x0c0a786cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a786e;
P_0c0a786e: /* original e048, guest PC 0x0c0a786e */
if(!s->budget--) { s->failed_pc=0x0c0a786eu; return 0; }
r[0]=0x00000048u;
goto P_0c0a7870;
P_0c0a7870: /* original d338, guest PC 0x0c0a7870 */
if(!s->budget--) { s->failed_pc=0x0c0a7870u; return 0; }
r[3]=read(ram,0x0c0a7954u,4);
goto P_0c0a7872;
P_0c0a7872: /* original 7ff4, guest PC 0x0c0a7872 */
if(!s->budget--) { s->failed_pc=0x0c0a7872u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7874;
P_0c0a7874: /* original f6e6, guest PC 0x0c0a7874 */
if(!s->budget--) { s->failed_pc=0x0c0a7874u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0a7876;
P_0c0a7876: /* original 430b, guest PC 0x0c0a7876 */
if(!s->budget--) { s->failed_pc=0x0c0a7876u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a787au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a787au) { target=s->pc; goto dispatch; }
goto P_0c0a787a;
P_0c0a7878: /* original e400, guest PC 0x0c0a7878 */
if(!s->budget--) { s->failed_pc=0x0c0a7878u; return 0; }
r[4]=0x00000000u;
goto P_0c0a787a;
P_0c0a787a: /* original d237, guest PC 0x0c0a787a */
if(!s->budget--) { s->failed_pc=0x0c0a787au; return 0; }
r[2]=read(ram,0x0c0a7958u,4);
goto P_0c0a787c;
P_0c0a787c: /* original 420b, guest PC 0x0c0a787c */
if(!s->budget--) { s->failed_pc=0x0c0a787cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7880u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7880u) { target=s->pc; goto dispatch; }
goto P_0c0a7880;
P_0c0a787e: /* original e400, guest PC 0x0c0a787e */
if(!s->budget--) { s->failed_pc=0x0c0a787eu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7880;
P_0c0a7880: /* original d336, guest PC 0x0c0a7880 */
if(!s->budget--) { s->failed_pc=0x0c0a7880u; return 0; }
r[3]=read(ram,0x0c0a795cu,4);
goto P_0c0a7882;
P_0c0a7882: /* original 9463, guest PC 0x0c0a7882 */
if(!s->budget--) { s->failed_pc=0x0c0a7882u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a794cu,2);
goto P_0c0a7884;
P_0c0a7884: /* original 430b, guest PC 0x0c0a7884 */
if(!s->budget--) { s->failed_pc=0x0c0a7884u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7888u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7888u) { target=s->pc; goto dispatch; }
goto P_0c0a7888;
P_0c0a7886: /* original 34ec, guest PC 0x0c0a7886 */
if(!s->budget--) { s->failed_pc=0x0c0a7886u; return 0; }
r[4]+=r[14];
goto P_0c0a7888;
P_0c0a7888: /* original d235, guest PC 0x0c0a7888 */
if(!s->budget--) { s->failed_pc=0x0c0a7888u; return 0; }
r[2]=read(ram,0x0c0a7960u,4);
goto P_0c0a788a;
P_0c0a788a: /* original 420b, guest PC 0x0c0a788a */
if(!s->budget--) { s->failed_pc=0x0c0a788au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a788eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a788eu) { target=s->pc; goto dispatch; }
goto P_0c0a788e;
P_0c0a788c: /* original 0009, guest PC 0x0c0a788c */
if(!s->budget--) { s->failed_pc=0x0c0a788cu; return 0; }
goto P_0c0a788e;
P_0c0a788e: /* original d335, guest PC 0x0c0a788e */
if(!s->budget--) { s->failed_pc=0x0c0a788eu; return 0; }
r[3]=read(ram,0x0c0a7964u,4);
goto P_0c0a7890;
P_0c0a7890: /* original 64e3, guest PC 0x0c0a7890 */
if(!s->budget--) { s->failed_pc=0x0c0a7890u; return 0; }
r[4]=r[14];
goto P_0c0a7892;
P_0c0a7892: /* original 65f3, guest PC 0x0c0a7892 */
if(!s->budget--) { s->failed_pc=0x0c0a7892u; return 0; }
r[5]=r[15];
goto P_0c0a7894;
P_0c0a7894: /* original 430b, guest PC 0x0c0a7894 */
if(!s->budget--) { s->failed_pc=0x0c0a7894u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7898u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7898u) { target=s->pc; goto dispatch; }
goto P_0c0a7898;
P_0c0a7896: /* original 7440, guest PC 0x0c0a7896 */
if(!s->budget--) { s->failed_pc=0x0c0a7896u; return 0; }
r[4]+=0x00000040u;
goto P_0c0a7898;
P_0c0a7898: /* original d233, guest PC 0x0c0a7898 */
if(!s->budget--) { s->failed_pc=0x0c0a7898u; return 0; }
r[2]=read(ram,0x0c0a7968u,4);
goto P_0c0a789a;
P_0c0a789a: /* original 420b, guest PC 0x0c0a789a */
if(!s->budget--) { s->failed_pc=0x0c0a789au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a789eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a789eu) { target=s->pc; goto dispatch; }
goto P_0c0a789e;
P_0c0a789c: /* original 64f3, guest PC 0x0c0a789c */
if(!s->budget--) { s->failed_pc=0x0c0a789cu; return 0; }
r[4]=r[15];
goto P_0c0a789e;
P_0c0a789e: /* original d333, guest PC 0x0c0a789e */
if(!s->budget--) { s->failed_pc=0x0c0a789eu; return 0; }
r[3]=read(ram,0x0c0a796cu,4);
goto P_0c0a78a0;
P_0c0a78a0: /* original 430b, guest PC 0x0c0a78a0 */
if(!s->budget--) { s->failed_pc=0x0c0a78a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a78a4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a78a4u) { target=s->pc; goto dispatch; }
goto P_0c0a78a4;
P_0c0a78a2: /* original e401, guest PC 0x0c0a78a2 */
if(!s->budget--) { s->failed_pc=0x0c0a78a2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a78a4;
P_0c0a78a4: /* original 7f0c, guest PC 0x0c0a78a4 */
if(!s->budget--) { s->failed_pc=0x0c0a78a4u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a78a6;
P_0c0a78a6: /* original 4f26, guest PC 0x0c0a78a6 */
if(!s->budget--) { s->failed_pc=0x0c0a78a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a78a8;
P_0c0a78a8: /* original 000b, guest PC 0x0c0a78a8 */
if(!s->budget--) { s->failed_pc=0x0c0a78a8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a78aa: /* original 6ef6, guest PC 0x0c0a78aa */
if(!s->budget--) { s->failed_pc=0x0c0a78aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a78acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a78acu; return 0; } return 1;
P_0c0c1208: /* original 2fe6, guest PC 0x0c0c1208 */
if(!s->budget--) { s->failed_pc=0x0c0c1208u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c120a;
P_0c0c120a: /* original e603, guest PC 0x0c0c120a */
if(!s->budget--) { s->failed_pc=0x0c0c120au; return 0; }
r[6]=0x00000003u;
goto P_0c0c120c;
P_0c0c120c: /* original 4f22, guest PC 0x0c0c120c */
if(!s->budget--) { s->failed_pc=0x0c0c120cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c120e;
P_0c0c120e: /* original 9063, guest PC 0x0c0c120e */
if(!s->budget--) { s->failed_pc=0x0c0c120eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12d8u,2);
goto P_0c0c1210;
P_0c0c1210: /* original 3f0c, guest PC 0x0c0c1210 */
if(!s->budget--) { s->failed_pc=0x0c0c1210u; return 0; }
r[15]+=r[0];
goto P_0c0c1212;
P_0c0c1212: /* original 2f42, guest PC 0x0c0c1212 */
if(!s->budget--) { s->failed_pc=0x0c0c1212u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c1214;
P_0c0c1214: /* original 6ef3, guest PC 0x0c0c1214 */
if(!s->budget--) { s->failed_pc=0x0c0c1214u; return 0; }
r[14]=r[15];
goto P_0c0c1216;
P_0c0c1216: /* original 9060, guest PC 0x0c0c1216 */
if(!s->budget--) { s->failed_pc=0x0c0c1216u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1218;
P_0c0c1218: /* original 30fc, guest PC 0x0c0c1218 */
if(!s->budget--) { s->failed_pc=0x0c0c1218u; return 0; }
r[0]+=r[15];
goto P_0c0c121a;
P_0c0c121a: /* original 7004, guest PC 0x0c0c121a */
if(!s->budget--) { s->failed_pc=0x0c0c121au; return 0; }
r[0]+=0x00000004u;
goto P_0c0c121c;
P_0c0c121c: /* original 2608, guest PC 0x0c0c121c */
if(!s->budget--) { s->failed_pc=0x0c0c121cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[0])==0)!=0);
goto P_0c0c121e;
P_0c0c121e: /* original 8d04, guest PC 0x0c0c121e */
if(!s->budget--) { s->failed_pc=0x0c0c121eu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000004u;
if(cond) { goto P_0c0c122a; }
goto P_0c0c1222;
P_0c0c1220: /* original 7e04, guest PC 0x0c0c1220 */
if(!s->budget--) { s->failed_pc=0x0c0c1220u; return 0; }
r[14]+=0x00000004u;
goto P_0c0c1222;
P_0c0c1222: /* original 965a, guest PC 0x0c0c1222 */
if(!s->budget--) { s->failed_pc=0x0c0c1222u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1224;
P_0c0c1224: /* original 36fc, guest PC 0x0c0c1224 */
if(!s->budget--) { s->failed_pc=0x0c0c1224u; return 0; }
r[6]+=r[15];
goto P_0c0c1226;
P_0c0c1226: /* original a003, guest PC 0x0c0c1226 */
if(!s->budget--) { s->failed_pc=0x0c0c1226u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c1230;
P_0c0c1228: /* original 7608, guest PC 0x0c0c1228 */
if(!s->budget--) { s->failed_pc=0x0c0c1228u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c122a;
P_0c0c122a: /* original 9656, guest PC 0x0c0c122a */
if(!s->budget--) { s->failed_pc=0x0c0c122au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c122c;
P_0c0c122c: /* original 36fc, guest PC 0x0c0c122c */
if(!s->budget--) { s->failed_pc=0x0c0c122cu; return 0; }
r[6]+=r[15];
goto P_0c0c122e;
P_0c0c122e: /* original 7604, guest PC 0x0c0c122e */
if(!s->budget--) { s->failed_pc=0x0c0c122eu; return 0; }
r[6]+=0x00000004u;
goto P_0c0c1230;
P_0c0c1230: /* original 9053, guest PC 0x0c0c1230 */
if(!s->budget--) { s->failed_pc=0x0c0c1230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1232;
P_0c0c1232: /* original d32d, guest PC 0x0c0c1232 */
if(!s->budget--) { s->failed_pc=0x0c0c1232u; return 0; }
r[3]=read(ram,0x0c0c12e8u,4);
goto P_0c0c1234;
P_0c0c1234: /* original 05fe, guest PC 0x0c0c1234 */
if(!s->budget--) { s->failed_pc=0x0c0c1234u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0c1236;
P_0c0c1236: /* original 430b, guest PC 0x0c0c1236 */
if(!s->budget--) { s->failed_pc=0x0c0c1236u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c123au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c123au) { target=s->pc; goto dispatch; }
goto P_0c0c123a;
P_0c0c1238: /* original 64e3, guest PC 0x0c0c1238 */
if(!s->budget--) { s->failed_pc=0x0c0c1238u; return 0; }
r[4]=r[14];
goto P_0c0c123a;
P_0c0c123a: /* original d42a, guest PC 0x0c0c123a */
if(!s->budget--) { s->failed_pc=0x0c0c123au; return 0; }
r[4]=read(ram,0x0c0c12e4u,4);
goto P_0c0c123c;
P_0c0c123c: /* original 66e3, guest PC 0x0c0c123c */
if(!s->budget--) { s->failed_pc=0x0c0c123cu; return 0; }
r[6]=r[14];
goto P_0c0c123e;
P_0c0c123e: /* original e701, guest PC 0x0c0c123e */
if(!s->budget--) { s->failed_pc=0x0c0c123eu; return 0; }
r[7]=0x00000001u;
goto P_0c0c1240;
P_0c0c1240: /* original b288, guest PC 0x0c0c1240 */
if(!s->budget--) { s->failed_pc=0x0c0c1240u; return 0; }
target=code_base|0x0c0c1754u; r[16]=code_base|0x0c0c1244u;
tmp=read(ram,r[15],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1244u) { target=s->pc; goto dispatch; }
goto P_0c0c1244;
P_0c0c1242: /* original 65f2, guest PC 0x0c0c1242 */
if(!s->budget--) { s->failed_pc=0x0c0c1242u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c1244;
P_0c0c1244: /* original 914a, guest PC 0x0c0c1244 */
if(!s->budget--) { s->failed_pc=0x0c0c1244u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dcu,2);
goto P_0c0c1246;
P_0c0c1246: /* original 3f1c, guest PC 0x0c0c1246 */
if(!s->budget--) { s->failed_pc=0x0c0c1246u; return 0; }
r[15]+=r[1];
goto P_0c0c1248;
P_0c0c1248: /* original 4f26, guest PC 0x0c0c1248 */
if(!s->budget--) { s->failed_pc=0x0c0c1248u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c124a;
P_0c0c124a: /* original 000b, guest PC 0x0c0c124a */
if(!s->budget--) { s->failed_pc=0x0c0c124au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c124c: /* original 6ef6, guest PC 0x0c0c124c */
if(!s->budget--) { s->failed_pc=0x0c0c124cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c124eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c124eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
