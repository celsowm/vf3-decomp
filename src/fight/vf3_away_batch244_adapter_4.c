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
int vf3_away_batch244_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c060d14u: goto P_0c060d14;
case 0x0c060d16u: goto P_0c060d16;
case 0x0c060d18u: goto P_0c060d18;
case 0x0c060d1au: goto P_0c060d1a;
case 0x0c060d1cu: goto P_0c060d1c;
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
case 0x0c0a7908u: goto P_0c0a7908;
case 0x0c0a790au: goto P_0c0a790a;
case 0x0c0a790cu: goto P_0c0a790c;
case 0x0c0a790eu: goto P_0c0a790e;
case 0x0c0a7910u: goto P_0c0a7910;
case 0x0c0a7912u: goto P_0c0a7912;
case 0x0c0a7914u: goto P_0c0a7914;
case 0x0c0a7916u: goto P_0c0a7916;
case 0x0c0a7918u: goto P_0c0a7918;
case 0x0c0a791au: goto P_0c0a791a;
case 0x0c0a791cu: goto P_0c0a791c;
case 0x0c0a791eu: goto P_0c0a791e;
case 0x0c0a7920u: goto P_0c0a7920;
case 0x0c0a7922u: goto P_0c0a7922;
case 0x0c0a7924u: goto P_0c0a7924;
case 0x0c0a7926u: goto P_0c0a7926;
case 0x0c0a7928u: goto P_0c0a7928;
case 0x0c0a792au: goto P_0c0a792a;
case 0x0c0a792cu: goto P_0c0a792c;
case 0x0c0a792eu: goto P_0c0a792e;
case 0x0c0a7930u: goto P_0c0a7930;
case 0x0c0a7932u: goto P_0c0a7932;
case 0x0c0a7934u: goto P_0c0a7934;
case 0x0c0a7936u: goto P_0c0a7936;
case 0x0c0a7938u: goto P_0c0a7938;
case 0x0c0a793au: goto P_0c0a793a;
case 0x0c0a793cu: goto P_0c0a793c;
case 0x0c0a793eu: goto P_0c0a793e;
case 0x0c0a7940u: goto P_0c0a7940;
case 0x0c0a7942u: goto P_0c0a7942;
case 0x0c0a7944u: goto P_0c0a7944;
case 0x0c0a7946u: goto P_0c0a7946;
case 0x0c0a7948u: goto P_0c0a7948;
case 0x0c0a794au: goto P_0c0a794a;
case 0x0c0a7978u: goto P_0c0a7978;
case 0x0c0a797au: goto P_0c0a797a;
case 0x0c0a797cu: goto P_0c0a797c;
case 0x0c0a797eu: goto P_0c0a797e;
case 0x0c0a7980u: goto P_0c0a7980;
case 0x0c0a7982u: goto P_0c0a7982;
case 0x0c0a7984u: goto P_0c0a7984;
case 0x0c0a7986u: goto P_0c0a7986;
case 0x0c0a7988u: goto P_0c0a7988;
case 0x0c0a798au: goto P_0c0a798a;
case 0x0c0a798cu: goto P_0c0a798c;
case 0x0c0a798eu: goto P_0c0a798e;
case 0x0c0a7990u: goto P_0c0a7990;
case 0x0c0a7992u: goto P_0c0a7992;
case 0x0c0a7994u: goto P_0c0a7994;
case 0x0c0a7996u: goto P_0c0a7996;
case 0x0c0a7998u: goto P_0c0a7998;
case 0x0c0a799au: goto P_0c0a799a;
case 0x0c0a799cu: goto P_0c0a799c;
case 0x0c0a799eu: goto P_0c0a799e;
case 0x0c0a79a0u: goto P_0c0a79a0;
case 0x0c0a79a2u: goto P_0c0a79a2;
case 0x0c0a79a4u: goto P_0c0a79a4;
case 0x0c0a79a6u: goto P_0c0a79a6;
case 0x0c0a79a8u: goto P_0c0a79a8;
case 0x0c0a79aau: goto P_0c0a79aa;
case 0x0c0a79acu: goto P_0c0a79ac;
case 0x0c0a79aeu: goto P_0c0a79ae;
case 0x0c0a79b0u: goto P_0c0a79b0;
case 0x0c0a79b2u: goto P_0c0a79b2;
case 0x0c0a79b4u: goto P_0c0a79b4;
case 0x0c0a79b6u: goto P_0c0a79b6;
case 0x0c0a79b8u: goto P_0c0a79b8;
case 0x0c0a79bau: goto P_0c0a79ba;
case 0x0c0a79bcu: goto P_0c0a79bc;
case 0x0c0a79beu: goto P_0c0a79be;
case 0x0c0a79c0u: goto P_0c0a79c0;
case 0x0c0a79c2u: goto P_0c0a79c2;
case 0x0c0a79c4u: goto P_0c0a79c4;
case 0x0c0a79c6u: goto P_0c0a79c6;
case 0x0c0a79c8u: goto P_0c0a79c8;
case 0x0c0a79cau: goto P_0c0a79ca;
case 0x0c0a79ccu: goto P_0c0a79cc;
case 0x0c0a79ceu: goto P_0c0a79ce;
case 0x0c0a79d0u: goto P_0c0a79d0;
case 0x0c0a79d2u: goto P_0c0a79d2;
case 0x0c0a79d4u: goto P_0c0a79d4;
case 0x0c0a79d6u: goto P_0c0a79d6;
case 0x0c0a79d8u: goto P_0c0a79d8;
case 0x0c0a79dau: goto P_0c0a79da;
case 0x0c0a79dcu: goto P_0c0a79dc;
case 0x0c0a79deu: goto P_0c0a79de;
case 0x0c0a79e0u: goto P_0c0a79e0;
case 0x0c0a79e2u: goto P_0c0a79e2;
case 0x0c0a79e4u: goto P_0c0a79e4;
case 0x0c0a79e6u: goto P_0c0a79e6;
case 0x0c0a79e8u: goto P_0c0a79e8;
case 0x0c0a79eau: goto P_0c0a79ea;
case 0x0c0a79ecu: goto P_0c0a79ec;
case 0x0c0a79eeu: goto P_0c0a79ee;
case 0x0c0a79f0u: goto P_0c0a79f0;
case 0x0c0a79f2u: goto P_0c0a79f2;
case 0x0c0a79f4u: goto P_0c0a79f4;
case 0x0c0a79f6u: goto P_0c0a79f6;
case 0x0c0a79f8u: goto P_0c0a79f8;
case 0x0c0a79fau: goto P_0c0a79fa;
case 0x0c0a79fcu: goto P_0c0a79fc;
case 0x0c0a79feu: goto P_0c0a79fe;
case 0x0c0a7a00u: goto P_0c0a7a00;
case 0x0c0a7a02u: goto P_0c0a7a02;
case 0x0c0a7a04u: goto P_0c0a7a04;
case 0x0c0a7a06u: goto P_0c0a7a06;
case 0x0c0a7a08u: goto P_0c0a7a08;
case 0x0c0a7a0au: goto P_0c0a7a0a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c060d14: /* original d344, guest PC 0x0c060d14 */
if(!s->budget--) { s->failed_pc=0x0c060d14u; return 0; }
r[3]=read(ram,0x0c060e28u,4);
goto P_0c060d16;
P_0c060d16: /* original 343c, guest PC 0x0c060d16 */
if(!s->budget--) { s->failed_pc=0x0c060d16u; return 0; }
r[4]+=r[3];
goto P_0c060d18;
P_0c060d18: /* original 2452, guest PC 0x0c060d18 */
if(!s->budget--) { s->failed_pc=0x0c060d18u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c060d1a;
P_0c060d1a: /* original 000b, guest PC 0x0c060d1a */
if(!s->budget--) { s->failed_pc=0x0c060d1au; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060d1c: /* original e001, guest PC 0x0c060d1c */
if(!s->budget--) { s->failed_pc=0x0c060d1cu; return 0; }
r[0]=0x00000001u;
if(!vf3_matrix_family(0x0c060d1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060d1eu; return 0; } return 1;
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
P_0c0a7908: /* original 2fe6, guest PC 0x0c0a7908 */
if(!s->budget--) { s->failed_pc=0x0c0a7908u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a790a;
P_0c0a790a: /* original c71a, guest PC 0x0c0a790a */
if(!s->budget--) { s->failed_pc=0x0c0a790au; return 0; }
r[0]=code_base|0x000a7974u;
goto P_0c0a790c;
P_0c0a790c: /* original 2fd6, guest PC 0x0c0a790c */
if(!s->budget--) { s->failed_pc=0x0c0a790cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a790e;
P_0c0a790e: /* original 2fc6, guest PC 0x0c0a790e */
if(!s->budget--) { s->failed_pc=0x0c0a790eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7910;
P_0c0a7910: /* original 2fb6, guest PC 0x0c0a7910 */
if(!s->budget--) { s->failed_pc=0x0c0a7910u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7912;
P_0c0a7912: /* original fffb, guest PC 0x0c0a7912 */
if(!s->budget--) { s->failed_pc=0x0c0a7912u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a7914;
P_0c0a7914: /* original ffeb, guest PC 0x0c0a7914 */
if(!s->budget--) { s->failed_pc=0x0c0a7914u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a7916;
P_0c0a7916: /* original ffdb, guest PC 0x0c0a7916 */
if(!s->budget--) { s->failed_pc=0x0c0a7916u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0a7918;
P_0c0a7918: /* original ffcb, guest PC 0x0c0a7918 */
if(!s->budget--) { s->failed_pc=0x0c0a7918u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0a791a;
P_0c0a791a: /* original 4f22, guest PC 0x0c0a791a */
if(!s->budget--) { s->failed_pc=0x0c0a791au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a791c;
P_0c0a791c: /* original ff5c, guest PC 0x0c0a791c */
if(!s->budget--) { s->failed_pc=0x0c0a791cu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a791e;
P_0c0a791e: /* original f508, guest PC 0x0c0a791e */
if(!s->budget--) { s->failed_pc=0x0c0a791eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a7920;
P_0c0a7920: /* original e004, guest PC 0x0c0a7920 */
if(!s->budget--) { s->failed_pc=0x0c0a7920u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7922;
P_0c0a7922: /* original 7fd8, guest PC 0x0c0a7922 */
if(!s->budget--) { s->failed_pc=0x0c0a7922u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0a7924;
P_0c0a7924: /* original fd5c, guest PC 0x0c0a7924 */
if(!s->budget--) { s->failed_pc=0x0c0a7924u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0a7926;
P_0c0a7926: /* original 65f3, guest PC 0x0c0a7926 */
if(!s->budget--) { s->failed_pc=0x0c0a7926u; return 0; }
r[5]=r[15];
goto P_0c0a7928;
P_0c0a7928: /* original ff57, guest PC 0x0c0a7928 */
if(!s->budget--) { s->failed_pc=0x0c0a7928u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a792a;
P_0c0a792a: /* original 7508, guest PC 0x0c0a792a */
if(!s->budget--) { s->failed_pc=0x0c0a792au; return 0; }
r[5]+=0x00000008u;
goto P_0c0a792c;
P_0c0a792c: /* original f59d, guest PC 0x0c0a792c */
if(!s->budget--) { s->failed_pc=0x0c0a792cu; return 0; }
fr[5]=0x3f800000u;
goto P_0c0a792e;
P_0c0a792e: /* original f455, guest PC 0x0c0a792e */
if(!s->budget--) { s->failed_pc=0x0c0a792eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a7930;
P_0c0a7930: /* original 6b53, guest PC 0x0c0a7930 */
if(!s->budget--) { s->failed_pc=0x0c0a7930u; return 0; }
r[11]=r[5];
goto P_0c0a7932;
P_0c0a7932: /* original 8f01, guest PC 0x0c0a7932 */
if(!s->budget--) { s->failed_pc=0x0c0a7932u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,12,13);
if(!cond) { goto P_0c0a7938; }
goto P_0c0a7936;
P_0c0a7934: /* original fcdc, guest PC 0x0c0a7934 */
if(!s->budget--) { s->failed_pc=0x0c0a7934u; return 0; }
vf3_matrix_move(s,12,13);
goto P_0c0a7936;
P_0c0a7936: /* original f45c, guest PC 0x0c0a7936 */
if(!s->budget--) { s->failed_pc=0x0c0a7936u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a7938;
P_0c0a7938: /* original ff55, guest PC 0x0c0a7938 */
if(!s->budget--) { s->failed_pc=0x0c0a7938u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[5]))!=0);
goto P_0c0a793a;
P_0c0a793a: /* original 8b00, guest PC 0x0c0a793a */
if(!s->budget--) { s->failed_pc=0x0c0a793au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a793e; }
goto P_0c0a793c;
P_0c0a793c: /* original ff5c, guest PC 0x0c0a793c */
if(!s->budget--) { s->failed_pc=0x0c0a793cu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a793e;
P_0c0a793e: /* original 2448, guest PC 0x0c0a793e */
if(!s->budget--) { s->failed_pc=0x0c0a793eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a7940;
P_0c0a7940: /* original 8b1a, guest PC 0x0c0a7940 */
if(!s->budget--) { s->failed_pc=0x0c0a7940u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7978; }
goto P_0c0a7942;
P_0c0a7942: /* original e004, guest PC 0x0c0a7942 */
if(!s->budget--) { s->failed_pc=0x0c0a7942u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7944;
P_0c0a7944: /* original fc5c, guest PC 0x0c0a7944 */
if(!s->budget--) { s->failed_pc=0x0c0a7944u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c0a7946;
P_0c0a7946: /* original ff57, guest PC 0x0c0a7946 */
if(!s->budget--) { s->failed_pc=0x0c0a7946u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a7948;
P_0c0a7948: /* original a023, guest PC 0x0c0a7948 */
if(!s->budget--) { s->failed_pc=0x0c0a7948u; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c0a7992;
P_0c0a794a: /* original fdcc, guest PC 0x0c0a794a */
if(!s->budget--) { s->failed_pc=0x0c0a794au; return 0; }
vf3_matrix_move(s,13,12);
if(!vf3_matrix_family(0x0c0a794cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a794cu; return 0; } return 1;
P_0c0a7978: /* original e201, guest PC 0x0c0a7978 */
if(!s->budget--) { s->failed_pc=0x0c0a7978u; return 0; }
r[2]=0x00000001u;
goto P_0c0a797a;
P_0c0a797a: /* original 2248, guest PC 0x0c0a797a */
if(!s->budget--) { s->failed_pc=0x0c0a797au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0a797c;
P_0c0a797c: /* original 8d01, guest PC 0x0c0a797c */
if(!s->budget--) { s->failed_pc=0x0c0a797cu; return 0; }
cond=r[17]&1u;
r[2]=0x00000002u;
if(cond) { goto P_0c0a7982; }
goto P_0c0a7980;
P_0c0a797e: /* original e202, guest PC 0x0c0a797e */
if(!s->budget--) { s->failed_pc=0x0c0a797eu; return 0; }
r[2]=0x00000002u;
goto P_0c0a7980;
P_0c0a7980: /* original fc5c, guest PC 0x0c0a7980 */
if(!s->budget--) { s->failed_pc=0x0c0a7980u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c0a7982;
P_0c0a7982: /* original 2248, guest PC 0x0c0a7982 */
if(!s->budget--) { s->failed_pc=0x0c0a7982u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0a7984;
P_0c0a7984: /* original 8901, guest PC 0x0c0a7984 */
if(!s->budget--) { s->failed_pc=0x0c0a7984u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a798a; }
goto P_0c0a7986;
P_0c0a7986: /* original e004, guest PC 0x0c0a7986 */
if(!s->budget--) { s->failed_pc=0x0c0a7986u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7988;
P_0c0a7988: /* original ff57, guest PC 0x0c0a7988 */
if(!s->budget--) { s->failed_pc=0x0c0a7988u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a798a;
P_0c0a798a: /* original e304, guest PC 0x0c0a798a */
if(!s->budget--) { s->failed_pc=0x0c0a798au; return 0; }
r[3]=0x00000004u;
goto P_0c0a798c;
P_0c0a798c: /* original 2438, guest PC 0x0c0a798c */
if(!s->budget--) { s->failed_pc=0x0c0a798cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0a798e;
P_0c0a798e: /* original 8900, guest PC 0x0c0a798e */
if(!s->budget--) { s->failed_pc=0x0c0a798eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7992; }
goto P_0c0a7990;
P_0c0a7990: /* original fd5c, guest PC 0x0c0a7990 */
if(!s->budget--) { s->failed_pc=0x0c0a7990u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0a7992;
P_0c0a7992: /* original 6353, guest PC 0x0c0a7992 */
if(!s->budget--) { s->failed_pc=0x0c0a7992u; return 0; }
r[3]=r[5];
goto P_0c0a7994;
P_0c0a7994: /* original 6d33, guest PC 0x0c0a7994 */
if(!s->budget--) { s->failed_pc=0x0c0a7994u; return 0; }
r[13]=r[3];
goto P_0c0a7996;
P_0c0a7996: /* original 6e33, guest PC 0x0c0a7996 */
if(!s->budget--) { s->failed_pc=0x0c0a7996u; return 0; }
r[14]=r[3];
goto P_0c0a7998;
P_0c0a7998: /* original 6c33, guest PC 0x0c0a7998 */
if(!s->budget--) { s->failed_pc=0x0c0a7998u; return 0; }
r[12]=r[3];
goto P_0c0a799a;
P_0c0a799a: /* original 7c0c, guest PC 0x0c0a799a */
if(!s->budget--) { s->failed_pc=0x0c0a799au; return 0; }
r[12]+=0x0000000cu;
goto P_0c0a799c;
P_0c0a799c: /* original fe4c, guest PC 0x0c0a799c */
if(!s->budget--) { s->failed_pc=0x0c0a799cu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0a799e;
P_0c0a799e: /* original 2f32, guest PC 0x0c0a799e */
if(!s->budget--) { s->failed_pc=0x0c0a799eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a79a0;
P_0c0a79a0: /* original 7e08, guest PC 0x0c0a79a0 */
if(!s->budget--) { s->failed_pc=0x0c0a79a0u; return 0; }
r[14]+=0x00000008u;
goto P_0c0a79a2;
P_0c0a79a2: /* original f38d, guest PC 0x0c0a79a2 */
if(!s->budget--) { s->failed_pc=0x0c0a79a2u; return 0; }
fr[3]=0;
goto P_0c0a79a4;
P_0c0a79a4: /* original 7d04, guest PC 0x0c0a79a4 */
if(!s->budget--) { s->failed_pc=0x0c0a79a4u; return 0; }
r[13]+=0x00000004u;
goto P_0c0a79a6;
P_0c0a79a6: /* original f33a, guest PC 0x0c0a79a6 */
if(!s->budget--) { s->failed_pc=0x0c0a79a6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a79a8;
P_0c0a79a8: /* original fdea, guest PC 0x0c0a79a8 */
if(!s->budget--) { s->failed_pc=0x0c0a79a8u; return 0; }
vf3_matrix_store(s,ram,14,r[13]);
goto P_0c0a79aa;
P_0c0a79aa: /* original feea, guest PC 0x0c0a79aa */
if(!s->budget--) { s->failed_pc=0x0c0a79aau; return 0; }
vf3_matrix_store(s,ram,14,r[14]);
goto P_0c0a79ac;
P_0c0a79ac: /* original fcea, guest PC 0x0c0a79ac */
if(!s->budget--) { s->failed_pc=0x0c0a79acu; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c0a79ae;
P_0c0a79ae: /* original d33f, guest PC 0x0c0a79ae */
if(!s->budget--) { s->failed_pc=0x0c0a79aeu; return 0; }
r[3]=read(ram,0x0c0a7aacu,4);
goto P_0c0a79b0;
P_0c0a79b0: /* original 430b, guest PC 0x0c0a79b0 */
if(!s->budget--) { s->failed_pc=0x0c0a79b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79b4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79b4u) { target=s->pc; goto dispatch; }
goto P_0c0a79b4;
P_0c0a79b2: /* original 64b3, guest PC 0x0c0a79b2 */
if(!s->budget--) { s->failed_pc=0x0c0a79b2u; return 0; }
r[4]=r[11];
goto P_0c0a79b4;
P_0c0a79b4: /* original d23e, guest PC 0x0c0a79b4 */
if(!s->budget--) { s->failed_pc=0x0c0a79b4u; return 0; }
r[2]=read(ram,0x0c0a7ab0u,4);
goto P_0c0a79b6;
P_0c0a79b6: /* original 420b, guest PC 0x0c0a79b6 */
if(!s->budget--) { s->failed_pc=0x0c0a79b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79bau;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79bau) { target=s->pc; goto dispatch; }
goto P_0c0a79ba;
P_0c0a79b8: /* original f4ec, guest PC 0x0c0a79b8 */
if(!s->budget--) { s->failed_pc=0x0c0a79b8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0a79ba;
P_0c0a79ba: /* original 63f2, guest PC 0x0c0a79ba */
if(!s->budget--) { s->failed_pc=0x0c0a79bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a79bc;
P_0c0a79bc: /* original e004, guest PC 0x0c0a79bc */
if(!s->budget--) { s->failed_pc=0x0c0a79bcu; return 0; }
r[0]=0x00000004u;
goto P_0c0a79be;
P_0c0a79be: /* original f38d, guest PC 0x0c0a79be */
if(!s->budget--) { s->failed_pc=0x0c0a79beu; return 0; }
fr[3]=0;
goto P_0c0a79c0;
P_0c0a79c0: /* original 65b3, guest PC 0x0c0a79c0 */
if(!s->budget--) { s->failed_pc=0x0c0a79c0u; return 0; }
r[5]=r[11];
goto P_0c0a79c2;
P_0c0a79c2: /* original f33a, guest PC 0x0c0a79c2 */
if(!s->budget--) { s->failed_pc=0x0c0a79c2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a79c4;
P_0c0a79c4: /* original f2fc, guest PC 0x0c0a79c4 */
if(!s->budget--) { s->failed_pc=0x0c0a79c4u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0a79c6;
P_0c0a79c6: /* original f2d2, guest PC 0x0c0a79c6 */
if(!s->budget--) { s->failed_pc=0x0c0a79c6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'*');
goto P_0c0a79c8;
P_0c0a79c8: /* original fd2a, guest PC 0x0c0a79c8 */
if(!s->budget--) { s->failed_pc=0x0c0a79c8u; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c0a79ca;
P_0c0a79ca: /* original f3f6, guest PC 0x0c0a79ca */
if(!s->budget--) { s->failed_pc=0x0c0a79cau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a79cc;
P_0c0a79cc: /* original f2fc, guest PC 0x0c0a79cc */
if(!s->budget--) { s->failed_pc=0x0c0a79ccu; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0a79ce;
P_0c0a79ce: /* original ffc2, guest PC 0x0c0a79ce */
if(!s->budget--) { s->failed_pc=0x0c0a79ceu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0a79d0;
P_0c0a79d0: /* original f232, guest PC 0x0c0a79d0 */
if(!s->budget--) { s->failed_pc=0x0c0a79d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a79d2;
P_0c0a79d2: /* original fe2a, guest PC 0x0c0a79d2 */
if(!s->budget--) { s->failed_pc=0x0c0a79d2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c0a79d4;
P_0c0a79d4: /* original fcfa, guest PC 0x0c0a79d4 */
if(!s->budget--) { s->failed_pc=0x0c0a79d4u; return 0; }
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c0a79d6;
P_0c0a79d6: /* original d337, guest PC 0x0c0a79d6 */
if(!s->budget--) { s->failed_pc=0x0c0a79d6u; return 0; }
r[3]=read(ram,0x0c0a7ab4u,4);
goto P_0c0a79d8;
P_0c0a79d8: /* original 430b, guest PC 0x0c0a79d8 */
if(!s->budget--) { s->failed_pc=0x0c0a79d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79dcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79dcu) { target=s->pc; goto dispatch; }
goto P_0c0a79dc;
P_0c0a79da: /* original e400, guest PC 0x0c0a79da */
if(!s->budget--) { s->failed_pc=0x0c0a79dau; return 0; }
r[4]=0x00000000u;
goto P_0c0a79dc;
P_0c0a79dc: /* original d236, guest PC 0x0c0a79dc */
if(!s->budget--) { s->failed_pc=0x0c0a79dcu; return 0; }
r[2]=read(ram,0x0c0a7ab8u,4);
goto P_0c0a79de;
P_0c0a79de: /* original f5e8, guest PC 0x0c0a79de */
if(!s->budget--) { s->failed_pc=0x0c0a79deu; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c0a79e0;
P_0c0a79e0: /* original f6c8, guest PC 0x0c0a79e0 */
if(!s->budget--) { s->failed_pc=0x0c0a79e0u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c0a79e2;
P_0c0a79e2: /* original 420b, guest PC 0x0c0a79e2 */
if(!s->budget--) { s->failed_pc=0x0c0a79e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79e6u;
vf3_matrix_load(s,ram,4,r[13]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79e6u) { target=s->pc; goto dispatch; }
goto P_0c0a79e6;
P_0c0a79e4: /* original f4d8, guest PC 0x0c0a79e4 */
if(!s->budget--) { s->failed_pc=0x0c0a79e4u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c0a79e6;
P_0c0a79e6: /* original d335, guest PC 0x0c0a79e6 */
if(!s->budget--) { s->failed_pc=0x0c0a79e6u; return 0; }
r[3]=read(ram,0x0c0a7abcu,4);
goto P_0c0a79e8;
P_0c0a79e8: /* original e502, guest PC 0x0c0a79e8 */
if(!s->budget--) { s->failed_pc=0x0c0a79e8u; return 0; }
r[5]=0x00000002u;
goto P_0c0a79ea;
P_0c0a79ea: /* original 430b, guest PC 0x0c0a79ea */
if(!s->budget--) { s->failed_pc=0x0c0a79eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79eeu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79eeu) { target=s->pc; goto dispatch; }
goto P_0c0a79ee;
P_0c0a79ec: /* original e400, guest PC 0x0c0a79ec */
if(!s->budget--) { s->failed_pc=0x0c0a79ecu; return 0; }
r[4]=0x00000000u;
goto P_0c0a79ee;
P_0c0a79ee: /* original d234, guest PC 0x0c0a79ee */
if(!s->budget--) { s->failed_pc=0x0c0a79eeu; return 0; }
r[2]=read(ram,0x0c0a7ac0u,4);
goto P_0c0a79f0;
P_0c0a79f0: /* original e501, guest PC 0x0c0a79f0 */
if(!s->budget--) { s->failed_pc=0x0c0a79f0u; return 0; }
r[5]=0x00000001u;
goto P_0c0a79f2;
P_0c0a79f2: /* original 420b, guest PC 0x0c0a79f2 */
if(!s->budget--) { s->failed_pc=0x0c0a79f2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79f6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79f6u) { target=s->pc; goto dispatch; }
goto P_0c0a79f6;
P_0c0a79f4: /* original e400, guest PC 0x0c0a79f4 */
if(!s->budget--) { s->failed_pc=0x0c0a79f4u; return 0; }
r[4]=0x00000000u;
goto P_0c0a79f6;
P_0c0a79f6: /* original 7f28, guest PC 0x0c0a79f6 */
if(!s->budget--) { s->failed_pc=0x0c0a79f6u; return 0; }
r[15]+=0x00000028u;
goto P_0c0a79f8;
P_0c0a79f8: /* original 4f26, guest PC 0x0c0a79f8 */
if(!s->budget--) { s->failed_pc=0x0c0a79f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a79fa;
P_0c0a79fa: /* original fcf9, guest PC 0x0c0a79fa */
if(!s->budget--) { s->failed_pc=0x0c0a79fau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a79fc;
P_0c0a79fc: /* original fdf9, guest PC 0x0c0a79fc */
if(!s->budget--) { s->failed_pc=0x0c0a79fcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a79fe;
P_0c0a79fe: /* original fef9, guest PC 0x0c0a79fe */
if(!s->budget--) { s->failed_pc=0x0c0a79feu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7a00;
P_0c0a7a00: /* original fff9, guest PC 0x0c0a7a00 */
if(!s->budget--) { s->failed_pc=0x0c0a7a00u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7a02;
P_0c0a7a02: /* original 6bf6, guest PC 0x0c0a7a02 */
if(!s->budget--) { s->failed_pc=0x0c0a7a02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a7a04;
P_0c0a7a04: /* original 6cf6, guest PC 0x0c0a7a04 */
if(!s->budget--) { s->failed_pc=0x0c0a7a04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a7a06;
P_0c0a7a06: /* original 6df6, guest PC 0x0c0a7a06 */
if(!s->budget--) { s->failed_pc=0x0c0a7a06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7a08;
P_0c0a7a08: /* original 000b, guest PC 0x0c0a7a08 */
if(!s->budget--) { s->failed_pc=0x0c0a7a08u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7a0a: /* original 6ef6, guest PC 0x0c0a7a0a */
if(!s->budget--) { s->failed_pc=0x0c0a7a0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a7a0cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
