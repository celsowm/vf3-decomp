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
int vf3_away_batch153_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b763eu: goto P_0c0b763e;
case 0x0c0b7640u: goto P_0c0b7640;
case 0x0c0b7642u: goto P_0c0b7642;
case 0x0c0b7644u: goto P_0c0b7644;
case 0x0c0b7646u: goto P_0c0b7646;
case 0x0c0b7648u: goto P_0c0b7648;
case 0x0c0b764au: goto P_0c0b764a;
case 0x0c0b764cu: goto P_0c0b764c;
case 0x0c0b764eu: goto P_0c0b764e;
case 0x0c0b7650u: goto P_0c0b7650;
case 0x0c0b7652u: goto P_0c0b7652;
case 0x0c0b7654u: goto P_0c0b7654;
case 0x0c0b7656u: goto P_0c0b7656;
case 0x0c0b7658u: goto P_0c0b7658;
case 0x0c0b765au: goto P_0c0b765a;
case 0x0c0b765cu: goto P_0c0b765c;
case 0x0c0b765eu: goto P_0c0b765e;
case 0x0c0b7660u: goto P_0c0b7660;
case 0x0c0b7662u: goto P_0c0b7662;
case 0x0c0b7664u: goto P_0c0b7664;
case 0x0c0b7666u: goto P_0c0b7666;
case 0x0c0b7668u: goto P_0c0b7668;
case 0x0c0b766au: goto P_0c0b766a;
case 0x0c0b766cu: goto P_0c0b766c;
case 0x0c0b766eu: goto P_0c0b766e;
case 0x0c0b7670u: goto P_0c0b7670;
case 0x0c0b7672u: goto P_0c0b7672;
case 0x0c0b7674u: goto P_0c0b7674;
case 0x0c0b7676u: goto P_0c0b7676;
case 0x0c0b7678u: goto P_0c0b7678;
case 0x0c0b767au: goto P_0c0b767a;
case 0x0c0b767cu: goto P_0c0b767c;
case 0x0c0b767eu: goto P_0c0b767e;
case 0x0c0b7680u: goto P_0c0b7680;
case 0x0c0b7682u: goto P_0c0b7682;
case 0x0c0b7684u: goto P_0c0b7684;
case 0x0c0b7686u: goto P_0c0b7686;
case 0x0c0b7688u: goto P_0c0b7688;
case 0x0c0b768au: goto P_0c0b768a;
case 0x0c0b768cu: goto P_0c0b768c;
case 0x0c0b768eu: goto P_0c0b768e;
case 0x0c0b7690u: goto P_0c0b7690;
case 0x0c0b7692u: goto P_0c0b7692;
case 0x0c0b7694u: goto P_0c0b7694;
case 0x0c0b7696u: goto P_0c0b7696;
case 0x0c0b7698u: goto P_0c0b7698;
case 0x0c0b769au: goto P_0c0b769a;
case 0x0c0b769cu: goto P_0c0b769c;
case 0x0c0b769eu: goto P_0c0b769e;
case 0x0c0b76a0u: goto P_0c0b76a0;
case 0x0c0b76a2u: goto P_0c0b76a2;
case 0x0c0b76a4u: goto P_0c0b76a4;
case 0x0c0b76a6u: goto P_0c0b76a6;
case 0x0c0b76a8u: goto P_0c0b76a8;
case 0x0c0b76aau: goto P_0c0b76aa;
case 0x0c0b76acu: goto P_0c0b76ac;
case 0x0c0b76aeu: goto P_0c0b76ae;
case 0x0c0b76b0u: goto P_0c0b76b0;
case 0x0c0b76b2u: goto P_0c0b76b2;
case 0x0c0b76b4u: goto P_0c0b76b4;
case 0x0c0b76b6u: goto P_0c0b76b6;
case 0x0c0b76b8u: goto P_0c0b76b8;
case 0x0c0b76bau: goto P_0c0b76ba;
case 0x0c0b76bcu: goto P_0c0b76bc;
case 0x0c0b76beu: goto P_0c0b76be;
case 0x0c0b76c0u: goto P_0c0b76c0;
case 0x0c0b76c2u: goto P_0c0b76c2;
case 0x0c0b76c4u: goto P_0c0b76c4;
case 0x0c0b76c6u: goto P_0c0b76c6;
case 0x0c0b76c8u: goto P_0c0b76c8;
case 0x0c0b76cau: goto P_0c0b76ca;
case 0x0c0b76ccu: goto P_0c0b76cc;
case 0x0c0b76ceu: goto P_0c0b76ce;
case 0x0c0b76d0u: goto P_0c0b76d0;
case 0x0c0b76d2u: goto P_0c0b76d2;
case 0x0c0b76d4u: goto P_0c0b76d4;
case 0x0c0b76d6u: goto P_0c0b76d6;
case 0x0c0b76d8u: goto P_0c0b76d8;
case 0x0c0b76dau: goto P_0c0b76da;
case 0x0c0b76dcu: goto P_0c0b76dc;
case 0x0c0b76deu: goto P_0c0b76de;
case 0x0c0b76e0u: goto P_0c0b76e0;
case 0x0c0b76e2u: goto P_0c0b76e2;
case 0x0c0b76e4u: goto P_0c0b76e4;
case 0x0c0b76e6u: goto P_0c0b76e6;
case 0x0c0b76e8u: goto P_0c0b76e8;
case 0x0c0b76eau: goto P_0c0b76ea;
case 0x0c0b76ecu: goto P_0c0b76ec;
case 0x0c0b76eeu: goto P_0c0b76ee;
case 0x0c0b76f0u: goto P_0c0b76f0;
case 0x0c0b76f2u: goto P_0c0b76f2;
case 0x0c0b76f4u: goto P_0c0b76f4;
case 0x0c0b76f6u: goto P_0c0b76f6;
case 0x0c0b76f8u: goto P_0c0b76f8;
case 0x0c0b76fau: goto P_0c0b76fa;
case 0x0c0b76fcu: goto P_0c0b76fc;
case 0x0c0b76feu: goto P_0c0b76fe;
case 0x0c0b7700u: goto P_0c0b7700;
case 0x0c0b7702u: goto P_0c0b7702;
case 0x0c0b7704u: goto P_0c0b7704;
case 0x0c0b7706u: goto P_0c0b7706;
case 0x0c0b7708u: goto P_0c0b7708;
case 0x0c0b770au: goto P_0c0b770a;
case 0x0c0b770cu: goto P_0c0b770c;
case 0x0c0b770eu: goto P_0c0b770e;
case 0x0c0b7710u: goto P_0c0b7710;
case 0x0c0b7712u: goto P_0c0b7712;
case 0x0c0b7714u: goto P_0c0b7714;
case 0x0c0b7716u: goto P_0c0b7716;
case 0x0c0b7718u: goto P_0c0b7718;
case 0x0c0b771au: goto P_0c0b771a;
case 0x0c0b771cu: goto P_0c0b771c;
case 0x0c0b771eu: goto P_0c0b771e;
case 0x0c0b7720u: goto P_0c0b7720;
case 0x0c0b7722u: goto P_0c0b7722;
case 0x0c0b7724u: goto P_0c0b7724;
case 0x0c0b7726u: goto P_0c0b7726;
case 0x0c0b7728u: goto P_0c0b7728;
case 0x0c0b772au: goto P_0c0b772a;
case 0x0c0b772cu: goto P_0c0b772c;
case 0x0c0b772eu: goto P_0c0b772e;
case 0x0c0b7730u: goto P_0c0b7730;
case 0x0c0b7732u: goto P_0c0b7732;
case 0x0c0b7734u: goto P_0c0b7734;
case 0x0c0b7736u: goto P_0c0b7736;
case 0x0c0b7738u: goto P_0c0b7738;
case 0x0c0b773au: goto P_0c0b773a;
case 0x0c0b773cu: goto P_0c0b773c;
case 0x0c0b773eu: goto P_0c0b773e;
case 0x0c0b7740u: goto P_0c0b7740;
case 0x0c0b7742u: goto P_0c0b7742;
case 0x0c0b7744u: goto P_0c0b7744;
case 0x0c0b7746u: goto P_0c0b7746;
case 0x0c0b7748u: goto P_0c0b7748;
case 0x0c0b774au: goto P_0c0b774a;
case 0x0c0b774cu: goto P_0c0b774c;
case 0x0c0b774eu: goto P_0c0b774e;
case 0x0c0b7750u: goto P_0c0b7750;
case 0x0c0b7752u: goto P_0c0b7752;
case 0x0c0b7754u: goto P_0c0b7754;
case 0x0c0b7756u: goto P_0c0b7756;
case 0x0c0b7758u: goto P_0c0b7758;
case 0x0c0b775au: goto P_0c0b775a;
case 0x0c0b775cu: goto P_0c0b775c;
case 0x0c0b775eu: goto P_0c0b775e;
case 0x0c0b7760u: goto P_0c0b7760;
case 0x0c0b7762u: goto P_0c0b7762;
case 0x0c0b7764u: goto P_0c0b7764;
case 0x0c0b7766u: goto P_0c0b7766;
case 0x0c0b7768u: goto P_0c0b7768;
case 0x0c0b776au: goto P_0c0b776a;
case 0x0c0b776cu: goto P_0c0b776c;
case 0x0c0b776eu: goto P_0c0b776e;
case 0x0c0b7770u: goto P_0c0b7770;
case 0x0c0b7772u: goto P_0c0b7772;
case 0x0c0b7774u: goto P_0c0b7774;
case 0x0c0b7776u: goto P_0c0b7776;
case 0x0c0b7778u: goto P_0c0b7778;
case 0x0c0b777au: goto P_0c0b777a;
case 0x0c0b777cu: goto P_0c0b777c;
case 0x0c0b777eu: goto P_0c0b777e;
case 0x0c0b7780u: goto P_0c0b7780;
case 0x0c0b7782u: goto P_0c0b7782;
case 0x0c0b7784u: goto P_0c0b7784;
case 0x0c0b7786u: goto P_0c0b7786;
case 0x0c0b7788u: goto P_0c0b7788;
case 0x0c0b778au: goto P_0c0b778a;
case 0x0c0b778cu: goto P_0c0b778c;
case 0x0c0b778eu: goto P_0c0b778e;
case 0x0c0b7790u: goto P_0c0b7790;
case 0x0c0b7792u: goto P_0c0b7792;
case 0x0c0b7794u: goto P_0c0b7794;
case 0x0c0b7796u: goto P_0c0b7796;
case 0x0c0b7798u: goto P_0c0b7798;
case 0x0c0b779au: goto P_0c0b779a;
case 0x0c0b779cu: goto P_0c0b779c;
case 0x0c0b779eu: goto P_0c0b779e;
case 0x0c0b77a0u: goto P_0c0b77a0;
case 0x0c0b7810u: goto P_0c0b7810;
case 0x0c0b7812u: goto P_0c0b7812;
case 0x0c0b7814u: goto P_0c0b7814;
case 0x0c0b7816u: goto P_0c0b7816;
case 0x0c0b7818u: goto P_0c0b7818;
case 0x0c0b781au: goto P_0c0b781a;
case 0x0c0b781cu: goto P_0c0b781c;
case 0x0c0b781eu: goto P_0c0b781e;
case 0x0c0b7820u: goto P_0c0b7820;
case 0x0c0b7822u: goto P_0c0b7822;
case 0x0c0b7824u: goto P_0c0b7824;
case 0x0c0b7826u: goto P_0c0b7826;
case 0x0c0b7828u: goto P_0c0b7828;
case 0x0c0b782au: goto P_0c0b782a;
case 0x0c0b782cu: goto P_0c0b782c;
case 0x0c0b782eu: goto P_0c0b782e;
case 0x0c0b7830u: goto P_0c0b7830;
case 0x0c0b7832u: goto P_0c0b7832;
case 0x0c0b7834u: goto P_0c0b7834;
case 0x0c0b7836u: goto P_0c0b7836;
case 0x0c0b7838u: goto P_0c0b7838;
case 0x0c0b783au: goto P_0c0b783a;
case 0x0c0b783cu: goto P_0c0b783c;
case 0x0c0b783eu: goto P_0c0b783e;
case 0x0c0b7840u: goto P_0c0b7840;
case 0x0c0b7842u: goto P_0c0b7842;
case 0x0c0b7844u: goto P_0c0b7844;
case 0x0c0b7846u: goto P_0c0b7846;
case 0x0c0b7848u: goto P_0c0b7848;
case 0x0c0b784au: goto P_0c0b784a;
case 0x0c0b784cu: goto P_0c0b784c;
case 0x0c0b784eu: goto P_0c0b784e;
case 0x0c0b7850u: goto P_0c0b7850;
case 0x0c0b7852u: goto P_0c0b7852;
case 0x0c0b7854u: goto P_0c0b7854;
case 0x0c0b7856u: goto P_0c0b7856;
case 0x0c0b7858u: goto P_0c0b7858;
case 0x0c0b785au: goto P_0c0b785a;
case 0x0c0b785cu: goto P_0c0b785c;
case 0x0c0b785eu: goto P_0c0b785e;
case 0x0c0b7860u: goto P_0c0b7860;
case 0x0c0b7862u: goto P_0c0b7862;
case 0x0c0b7864u: goto P_0c0b7864;
case 0x0c0b7866u: goto P_0c0b7866;
case 0x0c0b7868u: goto P_0c0b7868;
case 0x0c0b786au: goto P_0c0b786a;
case 0x0c0b786cu: goto P_0c0b786c;
case 0x0c0b786eu: goto P_0c0b786e;
case 0x0c0b7870u: goto P_0c0b7870;
case 0x0c0b7872u: goto P_0c0b7872;
case 0x0c0b7874u: goto P_0c0b7874;
case 0x0c0b7876u: goto P_0c0b7876;
case 0x0c0b7878u: goto P_0c0b7878;
case 0x0c0b787au: goto P_0c0b787a;
case 0x0c0b787cu: goto P_0c0b787c;
case 0x0c0b787eu: goto P_0c0b787e;
case 0x0c0b7880u: goto P_0c0b7880;
case 0x0c0b7882u: goto P_0c0b7882;
case 0x0c0b7884u: goto P_0c0b7884;
case 0x0c0b7886u: goto P_0c0b7886;
case 0x0c0b7888u: goto P_0c0b7888;
case 0x0c0b788au: goto P_0c0b788a;
case 0x0c0b788cu: goto P_0c0b788c;
case 0x0c0b788eu: goto P_0c0b788e;
case 0x0c0b7890u: goto P_0c0b7890;
case 0x0c0b7892u: goto P_0c0b7892;
case 0x0c0b7894u: goto P_0c0b7894;
case 0x0c0b7896u: goto P_0c0b7896;
case 0x0c0b7898u: goto P_0c0b7898;
case 0x0c0b789au: goto P_0c0b789a;
case 0x0c0b789cu: goto P_0c0b789c;
case 0x0c0b789eu: goto P_0c0b789e;
case 0x0c0b78a0u: goto P_0c0b78a0;
case 0x0c0b78a2u: goto P_0c0b78a2;
case 0x0c0b78a4u: goto P_0c0b78a4;
case 0x0c0b78a6u: goto P_0c0b78a6;
case 0x0c0b78a8u: goto P_0c0b78a8;
case 0x0c0b78aau: goto P_0c0b78aa;
case 0x0c0b78acu: goto P_0c0b78ac;
case 0x0c0b78aeu: goto P_0c0b78ae;
case 0x0c0b78b0u: goto P_0c0b78b0;
case 0x0c0b78b2u: goto P_0c0b78b2;
case 0x0c0b78b4u: goto P_0c0b78b4;
case 0x0c0b78b6u: goto P_0c0b78b6;
case 0x0c0b78b8u: goto P_0c0b78b8;
case 0x0c0b78bau: goto P_0c0b78ba;
case 0x0c0b78bcu: goto P_0c0b78bc;
case 0x0c0b78beu: goto P_0c0b78be;
case 0x0c0b78c0u: goto P_0c0b78c0;
case 0x0c0b78c2u: goto P_0c0b78c2;
case 0x0c0b78c4u: goto P_0c0b78c4;
case 0x0c0b78c6u: goto P_0c0b78c6;
case 0x0c0b78c8u: goto P_0c0b78c8;
case 0x0c0b78cau: goto P_0c0b78ca;
case 0x0c0b78ccu: goto P_0c0b78cc;
case 0x0c0b78ceu: goto P_0c0b78ce;
case 0x0c0b78d0u: goto P_0c0b78d0;
case 0x0c0b78d2u: goto P_0c0b78d2;
case 0x0c0b78d4u: goto P_0c0b78d4;
case 0x0c0b78d6u: goto P_0c0b78d6;
case 0x0c0b78d8u: goto P_0c0b78d8;
case 0x0c0b78dau: goto P_0c0b78da;
case 0x0c0b78dcu: goto P_0c0b78dc;
case 0x0c0b78deu: goto P_0c0b78de;
case 0x0c0b78e0u: goto P_0c0b78e0;
case 0x0c0b78e2u: goto P_0c0b78e2;
case 0x0c0b78e4u: goto P_0c0b78e4;
case 0x0c0b78e6u: goto P_0c0b78e6;
case 0x0c0b78e8u: goto P_0c0b78e8;
case 0x0c0b78eau: goto P_0c0b78ea;
case 0x0c0b78ecu: goto P_0c0b78ec;
case 0x0c0b78eeu: goto P_0c0b78ee;
case 0x0c0b78f0u: goto P_0c0b78f0;
case 0x0c0b78f2u: goto P_0c0b78f2;
case 0x0c0b78f4u: goto P_0c0b78f4;
case 0x0c0b78f6u: goto P_0c0b78f6;
case 0x0c0b78f8u: goto P_0c0b78f8;
case 0x0c0b78fau: goto P_0c0b78fa;
case 0x0c0b78fcu: goto P_0c0b78fc;
case 0x0c0b78feu: goto P_0c0b78fe;
case 0x0c0b7900u: goto P_0c0b7900;
case 0x0c0b7902u: goto P_0c0b7902;
case 0x0c0b7904u: goto P_0c0b7904;
case 0x0c0b7906u: goto P_0c0b7906;
case 0x0c0b7908u: goto P_0c0b7908;
case 0x0c0b790au: goto P_0c0b790a;
case 0x0c0b790cu: goto P_0c0b790c;
case 0x0c0b790eu: goto P_0c0b790e;
case 0x0c0b7910u: goto P_0c0b7910;
case 0x0c0b7912u: goto P_0c0b7912;
case 0x0c0b7914u: goto P_0c0b7914;
case 0x0c0b7916u: goto P_0c0b7916;
case 0x0c0b7918u: goto P_0c0b7918;
case 0x0c0b791au: goto P_0c0b791a;
case 0x0c0b791cu: goto P_0c0b791c;
case 0x0c0b791eu: goto P_0c0b791e;
case 0x0c0b7920u: goto P_0c0b7920;
case 0x0c0b7922u: goto P_0c0b7922;
case 0x0c0b7924u: goto P_0c0b7924;
case 0x0c0b7926u: goto P_0c0b7926;
case 0x0c0b7928u: goto P_0c0b7928;
case 0x0c0b792au: goto P_0c0b792a;
case 0x0c0b792cu: goto P_0c0b792c;
case 0x0c0b792eu: goto P_0c0b792e;
case 0x0c0b7930u: goto P_0c0b7930;
case 0x0c0b7932u: goto P_0c0b7932;
case 0x0c0b7934u: goto P_0c0b7934;
case 0x0c0b7936u: goto P_0c0b7936;
case 0x0c0b7938u: goto P_0c0b7938;
case 0x0c0b793au: goto P_0c0b793a;
case 0x0c0b793cu: goto P_0c0b793c;
case 0x0c0b793eu: goto P_0c0b793e;
case 0x0c0b7940u: goto P_0c0b7940;
case 0x0c0b7942u: goto P_0c0b7942;
case 0x0c0b7944u: goto P_0c0b7944;
case 0x0c0b7946u: goto P_0c0b7946;
case 0x0c0b7948u: goto P_0c0b7948;
case 0x0c0b794au: goto P_0c0b794a;
case 0x0c0b794cu: goto P_0c0b794c;
case 0x0c0b794eu: goto P_0c0b794e;
case 0x0c0b7950u: goto P_0c0b7950;
case 0x0c0b7952u: goto P_0c0b7952;
case 0x0c0b7954u: goto P_0c0b7954;
case 0x0c0b7956u: goto P_0c0b7956;
case 0x0c0b7958u: goto P_0c0b7958;
case 0x0c0b795au: goto P_0c0b795a;
case 0x0c0b795cu: goto P_0c0b795c;
case 0x0c0b795eu: goto P_0c0b795e;
case 0x0c0b7960u: goto P_0c0b7960;
case 0x0c0b7962u: goto P_0c0b7962;
case 0x0c0b7964u: goto P_0c0b7964;
case 0x0c0b7966u: goto P_0c0b7966;
case 0x0c0b7968u: goto P_0c0b7968;
case 0x0c0b79e2u: goto P_0c0b79e2;
case 0x0c0b79e4u: goto P_0c0b79e4;
case 0x0c0b79e6u: goto P_0c0b79e6;
case 0x0c0b79e8u: goto P_0c0b79e8;
case 0x0c0b79eau: goto P_0c0b79ea;
case 0x0c0b79ecu: goto P_0c0b79ec;
case 0x0c0b79eeu: goto P_0c0b79ee;
case 0x0c0b79f0u: goto P_0c0b79f0;
case 0x0c0b79f2u: goto P_0c0b79f2;
case 0x0c0b79f4u: goto P_0c0b79f4;
case 0x0c0b79f6u: goto P_0c0b79f6;
case 0x0c0b79f8u: goto P_0c0b79f8;
case 0x0c0b79fau: goto P_0c0b79fa;
case 0x0c0b79fcu: goto P_0c0b79fc;
case 0x0c0b79feu: goto P_0c0b79fe;
case 0x0c0b7a00u: goto P_0c0b7a00;
case 0x0c0b7a02u: goto P_0c0b7a02;
case 0x0c0b7a04u: goto P_0c0b7a04;
case 0x0c0b7a06u: goto P_0c0b7a06;
case 0x0c0b7a08u: goto P_0c0b7a08;
case 0x0c0b7a0au: goto P_0c0b7a0a;
case 0x0c0b7a0cu: goto P_0c0b7a0c;
case 0x0c0b7a0eu: goto P_0c0b7a0e;
case 0x0c0b7a10u: goto P_0c0b7a10;
case 0x0c0b7a12u: goto P_0c0b7a12;
case 0x0c0b7a14u: goto P_0c0b7a14;
case 0x0c0b7a16u: goto P_0c0b7a16;
case 0x0c0b7a18u: goto P_0c0b7a18;
case 0x0c0b7a1au: goto P_0c0b7a1a;
case 0x0c0b7a1cu: goto P_0c0b7a1c;
case 0x0c0b7a1eu: goto P_0c0b7a1e;
case 0x0c0b7a20u: goto P_0c0b7a20;
case 0x0c0b7a22u: goto P_0c0b7a22;
case 0x0c0b7a24u: goto P_0c0b7a24;
case 0x0c0b7a26u: goto P_0c0b7a26;
case 0x0c0b7a28u: goto P_0c0b7a28;
case 0x0c0b7a2au: goto P_0c0b7a2a;
case 0x0c0b7a2cu: goto P_0c0b7a2c;
case 0x0c0b7a2eu: goto P_0c0b7a2e;
case 0x0c0b7a30u: goto P_0c0b7a30;
case 0x0c0b7a32u: goto P_0c0b7a32;
case 0x0c0b7a34u: goto P_0c0b7a34;
case 0x0c0b7a36u: goto P_0c0b7a36;
case 0x0c0b7a38u: goto P_0c0b7a38;
case 0x0c0b7a3au: goto P_0c0b7a3a;
case 0x0c0b7a3cu: goto P_0c0b7a3c;
case 0x0c0b7a3eu: goto P_0c0b7a3e;
case 0x0c0b7a40u: goto P_0c0b7a40;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b763e: /* original 2fe6, guest PC 0x0c0b763e */
if(!s->budget--) { s->failed_pc=0x0c0b763eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7640;
P_0c0b7640: /* original 2fd6, guest PC 0x0c0b7640 */
if(!s->budget--) { s->failed_pc=0x0c0b7640u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7642;
P_0c0b7642: /* original 2fc6, guest PC 0x0c0b7642 */
if(!s->budget--) { s->failed_pc=0x0c0b7642u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7644;
P_0c0b7644: /* original 2fb6, guest PC 0x0c0b7644 */
if(!s->budget--) { s->failed_pc=0x0c0b7644u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7646;
P_0c0b7646: /* original 2fa6, guest PC 0x0c0b7646 */
if(!s->budget--) { s->failed_pc=0x0c0b7646u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b7648;
P_0c0b7648: /* original 2f96, guest PC 0x0c0b7648 */
if(!s->budget--) { s->failed_pc=0x0c0b7648u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b764a;
P_0c0b764a: /* original 4f22, guest PC 0x0c0b764a */
if(!s->budget--) { s->failed_pc=0x0c0b764au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b764c;
P_0c0b764c: /* original 5d44, guest PC 0x0c0b764c */
if(!s->budget--) { s->failed_pc=0x0c0b764cu; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b764e;
P_0c0b764e: /* original 94a8, guest PC 0x0c0b764e */
if(!s->budget--) { s->failed_pc=0x0c0b764eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77a2u,2);
goto P_0c0b7650;
P_0c0b7650: /* original de6e, guest PC 0x0c0b7650 */
if(!s->budget--) { s->failed_pc=0x0c0b7650u; return 0; }
r[14]=read(ram,0x0c0b780cu,4);
goto P_0c0b7652;
P_0c0b7652: /* original 7ff8, guest PC 0x0c0b7652 */
if(!s->budget--) { s->failed_pc=0x0c0b7652u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b7654;
P_0c0b7654: /* original 4e0b, guest PC 0x0c0b7654 */
if(!s->budget--) { s->failed_pc=0x0c0b7654u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7658u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7658u) { target=s->pc; goto dispatch; }
goto P_0c0b7658;
P_0c0b7656: /* original 65d2, guest PC 0x0c0b7656 */
if(!s->budget--) { s->failed_pc=0x0c0b7656u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b7658;
P_0c0b7658: /* original 94a4, guest PC 0x0c0b7658 */
if(!s->budget--) { s->failed_pc=0x0c0b7658u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77a4u,2);
goto P_0c0b765a;
P_0c0b765a: /* original 4e0b, guest PC 0x0c0b765a */
if(!s->budget--) { s->failed_pc=0x0c0b765au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b765eu;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b765eu) { target=s->pc; goto dispatch; }
goto P_0c0b765e;
P_0c0b765c: /* original 55d1, guest PC 0x0c0b765c */
if(!s->budget--) { s->failed_pc=0x0c0b765cu; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b765e;
P_0c0b765e: /* original 94a2, guest PC 0x0c0b765e */
if(!s->budget--) { s->failed_pc=0x0c0b765eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77a6u,2);
goto P_0c0b7660;
P_0c0b7660: /* original 4e0b, guest PC 0x0c0b7660 */
if(!s->budget--) { s->failed_pc=0x0c0b7660u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7664u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7664u) { target=s->pc; goto dispatch; }
goto P_0c0b7664;
P_0c0b7662: /* original 55d2, guest PC 0x0c0b7662 */
if(!s->budget--) { s->failed_pc=0x0c0b7662u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b7664;
P_0c0b7664: /* original 94a0, guest PC 0x0c0b7664 */
if(!s->budget--) { s->failed_pc=0x0c0b7664u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77a8u,2);
goto P_0c0b7666;
P_0c0b7666: /* original 4e0b, guest PC 0x0c0b7666 */
if(!s->budget--) { s->failed_pc=0x0c0b7666u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b766au;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b766au) { target=s->pc; goto dispatch; }
goto P_0c0b766a;
P_0c0b7668: /* original 55d3, guest PC 0x0c0b7668 */
if(!s->budget--) { s->failed_pc=0x0c0b7668u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b766a;
P_0c0b766a: /* original 949e, guest PC 0x0c0b766a */
if(!s->budget--) { s->failed_pc=0x0c0b766au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77aau,2);
goto P_0c0b766c;
P_0c0b766c: /* original 4e0b, guest PC 0x0c0b766c */
if(!s->budget--) { s->failed_pc=0x0c0b766cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7670u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7670u) { target=s->pc; goto dispatch; }
goto P_0c0b7670;
P_0c0b766e: /* original 55d4, guest PC 0x0c0b766e */
if(!s->budget--) { s->failed_pc=0x0c0b766eu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b7670;
P_0c0b7670: /* original 949c, guest PC 0x0c0b7670 */
if(!s->budget--) { s->failed_pc=0x0c0b7670u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77acu,2);
goto P_0c0b7672;
P_0c0b7672: /* original 4e0b, guest PC 0x0c0b7672 */
if(!s->budget--) { s->failed_pc=0x0c0b7672u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7676u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7676u) { target=s->pc; goto dispatch; }
goto P_0c0b7676;
P_0c0b7674: /* original 55d5, guest PC 0x0c0b7674 */
if(!s->budget--) { s->failed_pc=0x0c0b7674u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b7676;
P_0c0b7676: /* original 949a, guest PC 0x0c0b7676 */
if(!s->budget--) { s->failed_pc=0x0c0b7676u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77aeu,2);
goto P_0c0b7678;
P_0c0b7678: /* original 4e0b, guest PC 0x0c0b7678 */
if(!s->budget--) { s->failed_pc=0x0c0b7678u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b767cu;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b767cu) { target=s->pc; goto dispatch; }
goto P_0c0b767c;
P_0c0b767a: /* original 55d6, guest PC 0x0c0b767a */
if(!s->budget--) { s->failed_pc=0x0c0b767au; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b767c;
P_0c0b767c: /* original 9498, guest PC 0x0c0b767c */
if(!s->budget--) { s->failed_pc=0x0c0b767cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77b0u,2);
goto P_0c0b767e;
P_0c0b767e: /* original 4e0b, guest PC 0x0c0b767e */
if(!s->budget--) { s->failed_pc=0x0c0b767eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7682u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7682u) { target=s->pc; goto dispatch; }
goto P_0c0b7682;
P_0c0b7680: /* original 55d7, guest PC 0x0c0b7680 */
if(!s->budget--) { s->failed_pc=0x0c0b7680u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b7682;
P_0c0b7682: /* original 9496, guest PC 0x0c0b7682 */
if(!s->budget--) { s->failed_pc=0x0c0b7682u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77b2u,2);
goto P_0c0b7684;
P_0c0b7684: /* original 4e0b, guest PC 0x0c0b7684 */
if(!s->budget--) { s->failed_pc=0x0c0b7684u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7688u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7688u) { target=s->pc; goto dispatch; }
goto P_0c0b7688;
P_0c0b7686: /* original 55d8, guest PC 0x0c0b7686 */
if(!s->budget--) { s->failed_pc=0x0c0b7686u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b7688;
P_0c0b7688: /* original 9494, guest PC 0x0c0b7688 */
if(!s->budget--) { s->failed_pc=0x0c0b7688u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77b4u,2);
goto P_0c0b768a;
P_0c0b768a: /* original 4e0b, guest PC 0x0c0b768a */
if(!s->budget--) { s->failed_pc=0x0c0b768au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b768eu;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b768eu) { target=s->pc; goto dispatch; }
goto P_0c0b768e;
P_0c0b768c: /* original 55d9, guest PC 0x0c0b768c */
if(!s->budget--) { s->failed_pc=0x0c0b768cu; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b768e;
P_0c0b768e: /* original 9492, guest PC 0x0c0b768e */
if(!s->budget--) { s->failed_pc=0x0c0b768eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77b6u,2);
goto P_0c0b7690;
P_0c0b7690: /* original 4e0b, guest PC 0x0c0b7690 */
if(!s->budget--) { s->failed_pc=0x0c0b7690u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7694u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7694u) { target=s->pc; goto dispatch; }
goto P_0c0b7694;
P_0c0b7692: /* original 55da, guest PC 0x0c0b7692 */
if(!s->budget--) { s->failed_pc=0x0c0b7692u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b7694;
P_0c0b7694: /* original 9490, guest PC 0x0c0b7694 */
if(!s->budget--) { s->failed_pc=0x0c0b7694u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77b8u,2);
goto P_0c0b7696;
P_0c0b7696: /* original 4e0b, guest PC 0x0c0b7696 */
if(!s->budget--) { s->failed_pc=0x0c0b7696u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b769au;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b769au) { target=s->pc; goto dispatch; }
goto P_0c0b769a;
P_0c0b7698: /* original 55db, guest PC 0x0c0b7698 */
if(!s->budget--) { s->failed_pc=0x0c0b7698u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b769a;
P_0c0b769a: /* original 948e, guest PC 0x0c0b769a */
if(!s->budget--) { s->failed_pc=0x0c0b769au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77bau,2);
goto P_0c0b769c;
P_0c0b769c: /* original 4e0b, guest PC 0x0c0b769c */
if(!s->budget--) { s->failed_pc=0x0c0b769cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76a0u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76a0u) { target=s->pc; goto dispatch; }
goto P_0c0b76a0;
P_0c0b769e: /* original 55dc, guest PC 0x0c0b769e */
if(!s->budget--) { s->failed_pc=0x0c0b769eu; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b76a0;
P_0c0b76a0: /* original 948c, guest PC 0x0c0b76a0 */
if(!s->budget--) { s->failed_pc=0x0c0b76a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77bcu,2);
goto P_0c0b76a2;
P_0c0b76a2: /* original 4e0b, guest PC 0x0c0b76a2 */
if(!s->budget--) { s->failed_pc=0x0c0b76a2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76a6u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76a6u) { target=s->pc; goto dispatch; }
goto P_0c0b76a6;
P_0c0b76a4: /* original 55dd, guest PC 0x0c0b76a4 */
if(!s->budget--) { s->failed_pc=0x0c0b76a4u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b76a6;
P_0c0b76a6: /* original 948a, guest PC 0x0c0b76a6 */
if(!s->budget--) { s->failed_pc=0x0c0b76a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77beu,2);
goto P_0c0b76a8;
P_0c0b76a8: /* original 4e0b, guest PC 0x0c0b76a8 */
if(!s->budget--) { s->failed_pc=0x0c0b76a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76acu;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76acu) { target=s->pc; goto dispatch; }
goto P_0c0b76ac;
P_0c0b76aa: /* original 55de, guest PC 0x0c0b76aa */
if(!s->budget--) { s->failed_pc=0x0c0b76aau; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b76ac;
P_0c0b76ac: /* original 9488, guest PC 0x0c0b76ac */
if(!s->budget--) { s->failed_pc=0x0c0b76acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77c0u,2);
goto P_0c0b76ae;
P_0c0b76ae: /* original 4e0b, guest PC 0x0c0b76ae */
if(!s->budget--) { s->failed_pc=0x0c0b76aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76b2u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76b2u) { target=s->pc; goto dispatch; }
goto P_0c0b76b2;
P_0c0b76b0: /* original 55df, guest PC 0x0c0b76b0 */
if(!s->budget--) { s->failed_pc=0x0c0b76b0u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b76b2;
P_0c0b76b2: /* original 9486, guest PC 0x0c0b76b2 */
if(!s->budget--) { s->failed_pc=0x0c0b76b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77c2u,2);
goto P_0c0b76b4;
P_0c0b76b4: /* original e040, guest PC 0x0c0b76b4 */
if(!s->budget--) { s->failed_pc=0x0c0b76b4u; return 0; }
r[0]=0x00000040u;
goto P_0c0b76b6;
P_0c0b76b6: /* original 4e0b, guest PC 0x0c0b76b6 */
if(!s->budget--) { s->failed_pc=0x0c0b76b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76bau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76bau) { target=s->pc; goto dispatch; }
goto P_0c0b76ba;
P_0c0b76b8: /* original 05de, guest PC 0x0c0b76b8 */
if(!s->budget--) { s->failed_pc=0x0c0b76b8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b76ba;
P_0c0b76ba: /* original 9483, guest PC 0x0c0b76ba */
if(!s->budget--) { s->failed_pc=0x0c0b76bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77c4u,2);
goto P_0c0b76bc;
P_0c0b76bc: /* original e044, guest PC 0x0c0b76bc */
if(!s->budget--) { s->failed_pc=0x0c0b76bcu; return 0; }
r[0]=0x00000044u;
goto P_0c0b76be;
P_0c0b76be: /* original 4e0b, guest PC 0x0c0b76be */
if(!s->budget--) { s->failed_pc=0x0c0b76beu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76c2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76c2u) { target=s->pc; goto dispatch; }
goto P_0c0b76c2;
P_0c0b76c0: /* original 05de, guest PC 0x0c0b76c0 */
if(!s->budget--) { s->failed_pc=0x0c0b76c0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b76c2;
P_0c0b76c2: /* original 9480, guest PC 0x0c0b76c2 */
if(!s->budget--) { s->failed_pc=0x0c0b76c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77c6u,2);
goto P_0c0b76c4;
P_0c0b76c4: /* original e048, guest PC 0x0c0b76c4 */
if(!s->budget--) { s->failed_pc=0x0c0b76c4u; return 0; }
r[0]=0x00000048u;
goto P_0c0b76c6;
P_0c0b76c6: /* original 4e0b, guest PC 0x0c0b76c6 */
if(!s->budget--) { s->failed_pc=0x0c0b76c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76cau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76cau) { target=s->pc; goto dispatch; }
goto P_0c0b76ca;
P_0c0b76c8: /* original 05de, guest PC 0x0c0b76c8 */
if(!s->budget--) { s->failed_pc=0x0c0b76c8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b76ca;
P_0c0b76ca: /* original 947d, guest PC 0x0c0b76ca */
if(!s->budget--) { s->failed_pc=0x0c0b76cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77c8u,2);
goto P_0c0b76cc;
P_0c0b76cc: /* original e04c, guest PC 0x0c0b76cc */
if(!s->budget--) { s->failed_pc=0x0c0b76ccu; return 0; }
r[0]=0x0000004cu;
goto P_0c0b76ce;
P_0c0b76ce: /* original 4e0b, guest PC 0x0c0b76ce */
if(!s->budget--) { s->failed_pc=0x0c0b76ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76d2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76d2u) { target=s->pc; goto dispatch; }
goto P_0c0b76d2;
P_0c0b76d0: /* original 05de, guest PC 0x0c0b76d0 */
if(!s->budget--) { s->failed_pc=0x0c0b76d0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b76d2;
P_0c0b76d2: /* original 947a, guest PC 0x0c0b76d2 */
if(!s->budget--) { s->failed_pc=0x0c0b76d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77cau,2);
goto P_0c0b76d4;
P_0c0b76d4: /* original e050, guest PC 0x0c0b76d4 */
if(!s->budget--) { s->failed_pc=0x0c0b76d4u; return 0; }
r[0]=0x00000050u;
goto P_0c0b76d6;
P_0c0b76d6: /* original 4e0b, guest PC 0x0c0b76d6 */
if(!s->budget--) { s->failed_pc=0x0c0b76d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76dau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76dau) { target=s->pc; goto dispatch; }
goto P_0c0b76da;
P_0c0b76d8: /* original 05de, guest PC 0x0c0b76d8 */
if(!s->budget--) { s->failed_pc=0x0c0b76d8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b76da;
P_0c0b76da: /* original 9477, guest PC 0x0c0b76da */
if(!s->budget--) { s->failed_pc=0x0c0b76dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77ccu,2);
goto P_0c0b76dc;
P_0c0b76dc: /* original e054, guest PC 0x0c0b76dc */
if(!s->budget--) { s->failed_pc=0x0c0b76dcu; return 0; }
r[0]=0x00000054u;
goto P_0c0b76de;
P_0c0b76de: /* original 4e0b, guest PC 0x0c0b76de */
if(!s->budget--) { s->failed_pc=0x0c0b76deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76e2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76e2u) { target=s->pc; goto dispatch; }
goto P_0c0b76e2;
P_0c0b76e0: /* original 05de, guest PC 0x0c0b76e0 */
if(!s->budget--) { s->failed_pc=0x0c0b76e0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b76e2;
P_0c0b76e2: /* original 9474, guest PC 0x0c0b76e2 */
if(!s->budget--) { s->failed_pc=0x0c0b76e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77ceu,2);
goto P_0c0b76e4;
P_0c0b76e4: /* original e058, guest PC 0x0c0b76e4 */
if(!s->budget--) { s->failed_pc=0x0c0b76e4u; return 0; }
r[0]=0x00000058u;
goto P_0c0b76e6;
P_0c0b76e6: /* original 4e0b, guest PC 0x0c0b76e6 */
if(!s->budget--) { s->failed_pc=0x0c0b76e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76eau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76eau) { target=s->pc; goto dispatch; }
goto P_0c0b76ea;
P_0c0b76e8: /* original 05de, guest PC 0x0c0b76e8 */
if(!s->budget--) { s->failed_pc=0x0c0b76e8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b76ea;
P_0c0b76ea: /* original 9471, guest PC 0x0c0b76ea */
if(!s->budget--) { s->failed_pc=0x0c0b76eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77d0u,2);
goto P_0c0b76ec;
P_0c0b76ec: /* original e05c, guest PC 0x0c0b76ec */
if(!s->budget--) { s->failed_pc=0x0c0b76ecu; return 0; }
r[0]=0x0000005cu;
goto P_0c0b76ee;
P_0c0b76ee: /* original 4e0b, guest PC 0x0c0b76ee */
if(!s->budget--) { s->failed_pc=0x0c0b76eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76f2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76f2u) { target=s->pc; goto dispatch; }
goto P_0c0b76f2;
P_0c0b76f0: /* original 05de, guest PC 0x0c0b76f0 */
if(!s->budget--) { s->failed_pc=0x0c0b76f0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b76f2;
P_0c0b76f2: /* original 946e, guest PC 0x0c0b76f2 */
if(!s->budget--) { s->failed_pc=0x0c0b76f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77d2u,2);
goto P_0c0b76f4;
P_0c0b76f4: /* original e060, guest PC 0x0c0b76f4 */
if(!s->budget--) { s->failed_pc=0x0c0b76f4u; return 0; }
r[0]=0x00000060u;
goto P_0c0b76f6;
P_0c0b76f6: /* original 4e0b, guest PC 0x0c0b76f6 */
if(!s->budget--) { s->failed_pc=0x0c0b76f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b76fau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b76fau) { target=s->pc; goto dispatch; }
goto P_0c0b76fa;
P_0c0b76f8: /* original 05de, guest PC 0x0c0b76f8 */
if(!s->budget--) { s->failed_pc=0x0c0b76f8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b76fa;
P_0c0b76fa: /* original 946b, guest PC 0x0c0b76fa */
if(!s->budget--) { s->failed_pc=0x0c0b76fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77d4u,2);
goto P_0c0b76fc;
P_0c0b76fc: /* original e064, guest PC 0x0c0b76fc */
if(!s->budget--) { s->failed_pc=0x0c0b76fcu; return 0; }
r[0]=0x00000064u;
goto P_0c0b76fe;
P_0c0b76fe: /* original 4e0b, guest PC 0x0c0b76fe */
if(!s->budget--) { s->failed_pc=0x0c0b76feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7702u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7702u) { target=s->pc; goto dispatch; }
goto P_0c0b7702;
P_0c0b7700: /* original 05de, guest PC 0x0c0b7700 */
if(!s->budget--) { s->failed_pc=0x0c0b7700u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7702;
P_0c0b7702: /* original 9468, guest PC 0x0c0b7702 */
if(!s->budget--) { s->failed_pc=0x0c0b7702u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77d6u,2);
goto P_0c0b7704;
P_0c0b7704: /* original e068, guest PC 0x0c0b7704 */
if(!s->budget--) { s->failed_pc=0x0c0b7704u; return 0; }
r[0]=0x00000068u;
goto P_0c0b7706;
P_0c0b7706: /* original 4e0b, guest PC 0x0c0b7706 */
if(!s->budget--) { s->failed_pc=0x0c0b7706u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b770au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b770au) { target=s->pc; goto dispatch; }
goto P_0c0b770a;
P_0c0b7708: /* original 05de, guest PC 0x0c0b7708 */
if(!s->budget--) { s->failed_pc=0x0c0b7708u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b770a;
P_0c0b770a: /* original 9465, guest PC 0x0c0b770a */
if(!s->budget--) { s->failed_pc=0x0c0b770au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77d8u,2);
goto P_0c0b770c;
P_0c0b770c: /* original e06c, guest PC 0x0c0b770c */
if(!s->budget--) { s->failed_pc=0x0c0b770cu; return 0; }
r[0]=0x0000006cu;
goto P_0c0b770e;
P_0c0b770e: /* original 4e0b, guest PC 0x0c0b770e */
if(!s->budget--) { s->failed_pc=0x0c0b770eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7712u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7712u) { target=s->pc; goto dispatch; }
goto P_0c0b7712;
P_0c0b7710: /* original 05de, guest PC 0x0c0b7710 */
if(!s->budget--) { s->failed_pc=0x0c0b7710u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7712;
P_0c0b7712: /* original 9462, guest PC 0x0c0b7712 */
if(!s->budget--) { s->failed_pc=0x0c0b7712u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77dau,2);
goto P_0c0b7714;
P_0c0b7714: /* original e070, guest PC 0x0c0b7714 */
if(!s->budget--) { s->failed_pc=0x0c0b7714u; return 0; }
r[0]=0x00000070u;
goto P_0c0b7716;
P_0c0b7716: /* original 4e0b, guest PC 0x0c0b7716 */
if(!s->budget--) { s->failed_pc=0x0c0b7716u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b771au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b771au) { target=s->pc; goto dispatch; }
goto P_0c0b771a;
P_0c0b7718: /* original 05de, guest PC 0x0c0b7718 */
if(!s->budget--) { s->failed_pc=0x0c0b7718u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b771a;
P_0c0b771a: /* original 945f, guest PC 0x0c0b771a */
if(!s->budget--) { s->failed_pc=0x0c0b771au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77dcu,2);
goto P_0c0b771c;
P_0c0b771c: /* original e074, guest PC 0x0c0b771c */
if(!s->budget--) { s->failed_pc=0x0c0b771cu; return 0; }
r[0]=0x00000074u;
goto P_0c0b771e;
P_0c0b771e: /* original 4e0b, guest PC 0x0c0b771e */
if(!s->budget--) { s->failed_pc=0x0c0b771eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7722u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7722u) { target=s->pc; goto dispatch; }
goto P_0c0b7722;
P_0c0b7720: /* original 05de, guest PC 0x0c0b7720 */
if(!s->budget--) { s->failed_pc=0x0c0b7720u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7722;
P_0c0b7722: /* original 945c, guest PC 0x0c0b7722 */
if(!s->budget--) { s->failed_pc=0x0c0b7722u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77deu,2);
goto P_0c0b7724;
P_0c0b7724: /* original e078, guest PC 0x0c0b7724 */
if(!s->budget--) { s->failed_pc=0x0c0b7724u; return 0; }
r[0]=0x00000078u;
goto P_0c0b7726;
P_0c0b7726: /* original 4e0b, guest PC 0x0c0b7726 */
if(!s->budget--) { s->failed_pc=0x0c0b7726u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b772au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b772au) { target=s->pc; goto dispatch; }
goto P_0c0b772a;
P_0c0b7728: /* original 05de, guest PC 0x0c0b7728 */
if(!s->budget--) { s->failed_pc=0x0c0b7728u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b772a;
P_0c0b772a: /* original 9459, guest PC 0x0c0b772a */
if(!s->budget--) { s->failed_pc=0x0c0b772au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77e0u,2);
goto P_0c0b772c;
P_0c0b772c: /* original e07c, guest PC 0x0c0b772c */
if(!s->budget--) { s->failed_pc=0x0c0b772cu; return 0; }
r[0]=0x0000007cu;
goto P_0c0b772e;
P_0c0b772e: /* original 4e0b, guest PC 0x0c0b772e */
if(!s->budget--) { s->failed_pc=0x0c0b772eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7732u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7732u) { target=s->pc; goto dispatch; }
goto P_0c0b7732;
P_0c0b7730: /* original 05de, guest PC 0x0c0b7730 */
if(!s->budget--) { s->failed_pc=0x0c0b7730u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7732;
P_0c0b7732: /* original 9457, guest PC 0x0c0b7732 */
if(!s->budget--) { s->failed_pc=0x0c0b7732u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77e4u,2);
goto P_0c0b7734;
P_0c0b7734: /* original 9055, guest PC 0x0c0b7734 */
if(!s->budget--) { s->failed_pc=0x0c0b7734u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77e2u,2);
goto P_0c0b7736;
P_0c0b7736: /* original 4e0b, guest PC 0x0c0b7736 */
if(!s->budget--) { s->failed_pc=0x0c0b7736u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b773au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b773au) { target=s->pc; goto dispatch; }
goto P_0c0b773a;
P_0c0b7738: /* original 05de, guest PC 0x0c0b7738 */
if(!s->budget--) { s->failed_pc=0x0c0b7738u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b773a;
P_0c0b773a: /* original 9554, guest PC 0x0c0b773a */
if(!s->budget--) { s->failed_pc=0x0c0b773au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77e6u,2);
goto P_0c0b773c;
P_0c0b773c: /* original 35dc, guest PC 0x0c0b773c */
if(!s->budget--) { s->failed_pc=0x0c0b773cu; return 0; }
r[5]+=r[13];
goto P_0c0b773e;
P_0c0b773e: /* original 2f52, guest PC 0x0c0b773e */
if(!s->budget--) { s->failed_pc=0x0c0b773eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b7740;
P_0c0b7740: /* original 9452, guest PC 0x0c0b7740 */
if(!s->budget--) { s->failed_pc=0x0c0b7740u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77e8u,2);
goto P_0c0b7742;
P_0c0b7742: /* original 4e0b, guest PC 0x0c0b7742 */
if(!s->budget--) { s->failed_pc=0x0c0b7742u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7746u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7746u) { target=s->pc; goto dispatch; }
goto P_0c0b7746;
P_0c0b7744: /* original 6552, guest PC 0x0c0b7744 */
if(!s->budget--) { s->failed_pc=0x0c0b7744u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7746;
P_0c0b7746: /* original 9550, guest PC 0x0c0b7746 */
if(!s->budget--) { s->failed_pc=0x0c0b7746u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77eau,2);
goto P_0c0b7748;
P_0c0b7748: /* original 35dc, guest PC 0x0c0b7748 */
if(!s->budget--) { s->failed_pc=0x0c0b7748u; return 0; }
r[5]+=r[13];
goto P_0c0b774a;
P_0c0b774a: /* original 1f51, guest PC 0x0c0b774a */
if(!s->budget--) { s->failed_pc=0x0c0b774au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b774c;
P_0c0b774c: /* original 944e, guest PC 0x0c0b774c */
if(!s->budget--) { s->failed_pc=0x0c0b774cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77ecu,2);
goto P_0c0b774e;
P_0c0b774e: /* original 4e0b, guest PC 0x0c0b774e */
if(!s->budget--) { s->failed_pc=0x0c0b774eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7752u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7752u) { target=s->pc; goto dispatch; }
goto P_0c0b7752;
P_0c0b7750: /* original 6552, guest PC 0x0c0b7750 */
if(!s->budget--) { s->failed_pc=0x0c0b7750u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7752;
P_0c0b7752: /* original 944d, guest PC 0x0c0b7752 */
if(!s->budget--) { s->failed_pc=0x0c0b7752u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77f0u,2);
goto P_0c0b7754;
P_0c0b7754: /* original 904b, guest PC 0x0c0b7754 */
if(!s->budget--) { s->failed_pc=0x0c0b7754u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77eeu,2);
goto P_0c0b7756;
P_0c0b7756: /* original 4e0b, guest PC 0x0c0b7756 */
if(!s->budget--) { s->failed_pc=0x0c0b7756u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b775au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b775au) { target=s->pc; goto dispatch; }
goto P_0c0b775a;
P_0c0b7758: /* original 05de, guest PC 0x0c0b7758 */
if(!s->budget--) { s->failed_pc=0x0c0b7758u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b775a;
P_0c0b775a: /* original 944b, guest PC 0x0c0b775a */
if(!s->budget--) { s->failed_pc=0x0c0b775au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77f4u,2);
goto P_0c0b775c;
P_0c0b775c: /* original 9049, guest PC 0x0c0b775c */
if(!s->budget--) { s->failed_pc=0x0c0b775cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77f2u,2);
goto P_0c0b775e;
P_0c0b775e: /* original 4e0b, guest PC 0x0c0b775e */
if(!s->budget--) { s->failed_pc=0x0c0b775eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7762u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7762u) { target=s->pc; goto dispatch; }
goto P_0c0b7762;
P_0c0b7760: /* original 05de, guest PC 0x0c0b7760 */
if(!s->budget--) { s->failed_pc=0x0c0b7760u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7762;
P_0c0b7762: /* original 9948, guest PC 0x0c0b7762 */
if(!s->budget--) { s->failed_pc=0x0c0b7762u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77f6u,2);
goto P_0c0b7764;
P_0c0b7764: /* original 9448, guest PC 0x0c0b7764 */
if(!s->budget--) { s->failed_pc=0x0c0b7764u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77f8u,2);
goto P_0c0b7766;
P_0c0b7766: /* original 39dc, guest PC 0x0c0b7766 */
if(!s->budget--) { s->failed_pc=0x0c0b7766u; return 0; }
r[9]+=r[13];
goto P_0c0b7768;
P_0c0b7768: /* original 4e0b, guest PC 0x0c0b7768 */
if(!s->budget--) { s->failed_pc=0x0c0b7768u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b776cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b776cu) { target=s->pc; goto dispatch; }
goto P_0c0b776c;
P_0c0b776a: /* original 6592, guest PC 0x0c0b776a */
if(!s->budget--) { s->failed_pc=0x0c0b776au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b776c;
P_0c0b776c: /* original 9445, guest PC 0x0c0b776c */
if(!s->budget--) { s->failed_pc=0x0c0b776cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77fau,2);
goto P_0c0b776e;
P_0c0b776e: /* original 4e0b, guest PC 0x0c0b776e */
if(!s->budget--) { s->failed_pc=0x0c0b776eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7772u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7772u) { target=s->pc; goto dispatch; }
goto P_0c0b7772;
P_0c0b7770: /* original 6592, guest PC 0x0c0b7770 */
if(!s->budget--) { s->failed_pc=0x0c0b7770u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7772;
P_0c0b7772: /* original 9443, guest PC 0x0c0b7772 */
if(!s->budget--) { s->failed_pc=0x0c0b7772u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77fcu,2);
goto P_0c0b7774;
P_0c0b7774: /* original 4e0b, guest PC 0x0c0b7774 */
if(!s->budget--) { s->failed_pc=0x0c0b7774u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7778u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7778u) { target=s->pc; goto dispatch; }
goto P_0c0b7778;
P_0c0b7776: /* original 6592, guest PC 0x0c0b7776 */
if(!s->budget--) { s->failed_pc=0x0c0b7776u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7778;
P_0c0b7778: /* original 9441, guest PC 0x0c0b7778 */
if(!s->budget--) { s->failed_pc=0x0c0b7778u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b77feu,2);
goto P_0c0b777a;
P_0c0b777a: /* original 4e0b, guest PC 0x0c0b777a */
if(!s->budget--) { s->failed_pc=0x0c0b777au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b777eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b777eu) { target=s->pc; goto dispatch; }
goto P_0c0b777e;
P_0c0b777c: /* original 6592, guest PC 0x0c0b777c */
if(!s->budget--) { s->failed_pc=0x0c0b777cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b777e;
P_0c0b777e: /* original 9c3f, guest PC 0x0c0b777e */
if(!s->budget--) { s->failed_pc=0x0c0b777eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7800u,2);
goto P_0c0b7780;
P_0c0b7780: /* original 943f, guest PC 0x0c0b7780 */
if(!s->budget--) { s->failed_pc=0x0c0b7780u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7802u,2);
goto P_0c0b7782;
P_0c0b7782: /* original 3cdc, guest PC 0x0c0b7782 */
if(!s->budget--) { s->failed_pc=0x0c0b7782u; return 0; }
r[12]+=r[13];
goto P_0c0b7784;
P_0c0b7784: /* original 4e0b, guest PC 0x0c0b7784 */
if(!s->budget--) { s->failed_pc=0x0c0b7784u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7788u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7788u) { target=s->pc; goto dispatch; }
goto P_0c0b7788;
P_0c0b7786: /* original 65c2, guest PC 0x0c0b7786 */
if(!s->budget--) { s->failed_pc=0x0c0b7786u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7788;
P_0c0b7788: /* original 943c, guest PC 0x0c0b7788 */
if(!s->budget--) { s->failed_pc=0x0c0b7788u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7804u,2);
goto P_0c0b778a;
P_0c0b778a: /* original 4e0b, guest PC 0x0c0b778a */
if(!s->budget--) { s->failed_pc=0x0c0b778au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b778eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b778eu) { target=s->pc; goto dispatch; }
goto P_0c0b778e;
P_0c0b778c: /* original 65c2, guest PC 0x0c0b778c */
if(!s->budget--) { s->failed_pc=0x0c0b778cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b778e;
P_0c0b778e: /* original 943a, guest PC 0x0c0b778e */
if(!s->budget--) { s->failed_pc=0x0c0b778eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7806u,2);
goto P_0c0b7790;
P_0c0b7790: /* original 4e0b, guest PC 0x0c0b7790 */
if(!s->budget--) { s->failed_pc=0x0c0b7790u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7794u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7794u) { target=s->pc; goto dispatch; }
goto P_0c0b7794;
P_0c0b7792: /* original 65c2, guest PC 0x0c0b7792 */
if(!s->budget--) { s->failed_pc=0x0c0b7792u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7794;
P_0c0b7794: /* original 9438, guest PC 0x0c0b7794 */
if(!s->budget--) { s->failed_pc=0x0c0b7794u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7808u,2);
goto P_0c0b7796;
P_0c0b7796: /* original 4e0b, guest PC 0x0c0b7796 */
if(!s->budget--) { s->failed_pc=0x0c0b7796u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b779au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b779au) { target=s->pc; goto dispatch; }
goto P_0c0b779a;
P_0c0b7798: /* original 65c2, guest PC 0x0c0b7798 */
if(!s->budget--) { s->failed_pc=0x0c0b7798u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b779a;
P_0c0b779a: /* original 9b36, guest PC 0x0c0b779a */
if(!s->budget--) { s->failed_pc=0x0c0b779au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b780au,2);
goto P_0c0b779c;
P_0c0b779c: /* original 3bdc, guest PC 0x0c0b779c */
if(!s->budget--) { s->failed_pc=0x0c0b779cu; return 0; }
r[11]+=r[13];
goto P_0c0b779e;
P_0c0b779e: /* original a037, guest PC 0x0c0b779e */
if(!s->budget--) { s->failed_pc=0x0c0b779eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7810;
P_0c0b77a0: /* original 65b2, guest PC 0x0c0b77a0 */
if(!s->budget--) { s->failed_pc=0x0c0b77a0u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b77a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b77a2u; return 0; } return 1;
P_0c0b7810: /* original 94ab, guest PC 0x0c0b7810 */
if(!s->budget--) { s->failed_pc=0x0c0b7810u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b796au,2);
goto P_0c0b7812;
P_0c0b7812: /* original 4e0b, guest PC 0x0c0b7812 */
if(!s->budget--) { s->failed_pc=0x0c0b7812u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7816u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7816u) { target=s->pc; goto dispatch; }
goto P_0c0b7816;
P_0c0b7814: /* original 0009, guest PC 0x0c0b7814 */
if(!s->budget--) { s->failed_pc=0x0c0b7814u; return 0; }
goto P_0c0b7816;
P_0c0b7816: /* original 94a9, guest PC 0x0c0b7816 */
if(!s->budget--) { s->failed_pc=0x0c0b7816u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b796cu,2);
goto P_0c0b7818;
P_0c0b7818: /* original 4e0b, guest PC 0x0c0b7818 */
if(!s->budget--) { s->failed_pc=0x0c0b7818u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b781cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b781cu) { target=s->pc; goto dispatch; }
goto P_0c0b781c;
P_0c0b781a: /* original 65b2, guest PC 0x0c0b781a */
if(!s->budget--) { s->failed_pc=0x0c0b781au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b781c;
P_0c0b781c: /* original 94a7, guest PC 0x0c0b781c */
if(!s->budget--) { s->failed_pc=0x0c0b781cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b796eu,2);
goto P_0c0b781e;
P_0c0b781e: /* original 4e0b, guest PC 0x0c0b781e */
if(!s->budget--) { s->failed_pc=0x0c0b781eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7822u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7822u) { target=s->pc; goto dispatch; }
goto P_0c0b7822;
P_0c0b7820: /* original 65b2, guest PC 0x0c0b7820 */
if(!s->budget--) { s->failed_pc=0x0c0b7820u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7822;
P_0c0b7822: /* original 94a5, guest PC 0x0c0b7822 */
if(!s->budget--) { s->failed_pc=0x0c0b7822u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7970u,2);
goto P_0c0b7824;
P_0c0b7824: /* original 4e0b, guest PC 0x0c0b7824 */
if(!s->budget--) { s->failed_pc=0x0c0b7824u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7828u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7828u) { target=s->pc; goto dispatch; }
goto P_0c0b7828;
P_0c0b7826: /* original 65b2, guest PC 0x0c0b7826 */
if(!s->budget--) { s->failed_pc=0x0c0b7826u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7828;
P_0c0b7828: /* original 9aa3, guest PC 0x0c0b7828 */
if(!s->budget--) { s->failed_pc=0x0c0b7828u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7972u,2);
goto P_0c0b782a;
P_0c0b782a: /* original 94a3, guest PC 0x0c0b782a */
if(!s->budget--) { s->failed_pc=0x0c0b782au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7974u,2);
goto P_0c0b782c;
P_0c0b782c: /* original 3adc, guest PC 0x0c0b782c */
if(!s->budget--) { s->failed_pc=0x0c0b782cu; return 0; }
r[10]+=r[13];
goto P_0c0b782e;
P_0c0b782e: /* original 4e0b, guest PC 0x0c0b782e */
if(!s->budget--) { s->failed_pc=0x0c0b782eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7832u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7832u) { target=s->pc; goto dispatch; }
goto P_0c0b7832;
P_0c0b7830: /* original 65a2, guest PC 0x0c0b7830 */
if(!s->budget--) { s->failed_pc=0x0c0b7830u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7832;
P_0c0b7832: /* original 94a0, guest PC 0x0c0b7832 */
if(!s->budget--) { s->failed_pc=0x0c0b7832u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7976u,2);
goto P_0c0b7834;
P_0c0b7834: /* original 4e0b, guest PC 0x0c0b7834 */
if(!s->budget--) { s->failed_pc=0x0c0b7834u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7838u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7838u) { target=s->pc; goto dispatch; }
goto P_0c0b7838;
P_0c0b7836: /* original 65a2, guest PC 0x0c0b7836 */
if(!s->budget--) { s->failed_pc=0x0c0b7836u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7838;
P_0c0b7838: /* original 949e, guest PC 0x0c0b7838 */
if(!s->budget--) { s->failed_pc=0x0c0b7838u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7978u,2);
goto P_0c0b783a;
P_0c0b783a: /* original 4e0b, guest PC 0x0c0b783a */
if(!s->budget--) { s->failed_pc=0x0c0b783au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b783eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b783eu) { target=s->pc; goto dispatch; }
goto P_0c0b783e;
P_0c0b783c: /* original 65a2, guest PC 0x0c0b783c */
if(!s->budget--) { s->failed_pc=0x0c0b783cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b783e;
P_0c0b783e: /* original 949c, guest PC 0x0c0b783e */
if(!s->budget--) { s->failed_pc=0x0c0b783eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b797au,2);
goto P_0c0b7840;
P_0c0b7840: /* original 4e0b, guest PC 0x0c0b7840 */
if(!s->budget--) { s->failed_pc=0x0c0b7840u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7844u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7844u) { target=s->pc; goto dispatch; }
goto P_0c0b7844;
P_0c0b7842: /* original 65a2, guest PC 0x0c0b7842 */
if(!s->budget--) { s->failed_pc=0x0c0b7842u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b7844;
P_0c0b7844: /* original 949a, guest PC 0x0c0b7844 */
if(!s->budget--) { s->failed_pc=0x0c0b7844u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b797cu,2);
goto P_0c0b7846;
P_0c0b7846: /* original 65f2, guest PC 0x0c0b7846 */
if(!s->budget--) { s->failed_pc=0x0c0b7846u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b7848;
P_0c0b7848: /* original 4e0b, guest PC 0x0c0b7848 */
if(!s->budget--) { s->failed_pc=0x0c0b7848u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b784cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b784cu) { target=s->pc; goto dispatch; }
goto P_0c0b784c;
P_0c0b784a: /* original 6552, guest PC 0x0c0b784a */
if(!s->budget--) { s->failed_pc=0x0c0b784au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b784c;
P_0c0b784c: /* original 9497, guest PC 0x0c0b784c */
if(!s->budget--) { s->failed_pc=0x0c0b784cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b797eu,2);
goto P_0c0b784e;
P_0c0b784e: /* original 55f1, guest PC 0x0c0b784e */
if(!s->budget--) { s->failed_pc=0x0c0b784eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b7850;
P_0c0b7850: /* original 4e0b, guest PC 0x0c0b7850 */
if(!s->budget--) { s->failed_pc=0x0c0b7850u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7854u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7854u) { target=s->pc; goto dispatch; }
goto P_0c0b7854;
P_0c0b7852: /* original 6552, guest PC 0x0c0b7852 */
if(!s->budget--) { s->failed_pc=0x0c0b7852u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7854;
P_0c0b7854: /* original 9494, guest PC 0x0c0b7854 */
if(!s->budget--) { s->failed_pc=0x0c0b7854u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7980u,2);
goto P_0c0b7856;
P_0c0b7856: /* original 4e0b, guest PC 0x0c0b7856 */
if(!s->budget--) { s->failed_pc=0x0c0b7856u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b785au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b785au) { target=s->pc; goto dispatch; }
goto P_0c0b785a;
P_0c0b7858: /* original 6592, guest PC 0x0c0b7858 */
if(!s->budget--) { s->failed_pc=0x0c0b7858u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b785a;
P_0c0b785a: /* original 9492, guest PC 0x0c0b785a */
if(!s->budget--) { s->failed_pc=0x0c0b785au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7982u,2);
goto P_0c0b785c;
P_0c0b785c: /* original 4e0b, guest PC 0x0c0b785c */
if(!s->budget--) { s->failed_pc=0x0c0b785cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7860u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7860u) { target=s->pc; goto dispatch; }
goto P_0c0b7860;
P_0c0b785e: /* original 6592, guest PC 0x0c0b785e */
if(!s->budget--) { s->failed_pc=0x0c0b785eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7860;
P_0c0b7860: /* original 9490, guest PC 0x0c0b7860 */
if(!s->budget--) { s->failed_pc=0x0c0b7860u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7984u,2);
goto P_0c0b7862;
P_0c0b7862: /* original 4e0b, guest PC 0x0c0b7862 */
if(!s->budget--) { s->failed_pc=0x0c0b7862u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7866u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7866u) { target=s->pc; goto dispatch; }
goto P_0c0b7866;
P_0c0b7864: /* original 6592, guest PC 0x0c0b7864 */
if(!s->budget--) { s->failed_pc=0x0c0b7864u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b7866;
P_0c0b7866: /* original 948e, guest PC 0x0c0b7866 */
if(!s->budget--) { s->failed_pc=0x0c0b7866u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7986u,2);
goto P_0c0b7868;
P_0c0b7868: /* original 4e0b, guest PC 0x0c0b7868 */
if(!s->budget--) { s->failed_pc=0x0c0b7868u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b786cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b786cu) { target=s->pc; goto dispatch; }
goto P_0c0b786c;
P_0c0b786a: /* original 6592, guest PC 0x0c0b786a */
if(!s->budget--) { s->failed_pc=0x0c0b786au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b786c;
P_0c0b786c: /* original 948c, guest PC 0x0c0b786c */
if(!s->budget--) { s->failed_pc=0x0c0b786cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7988u,2);
goto P_0c0b786e;
P_0c0b786e: /* original 4e0b, guest PC 0x0c0b786e */
if(!s->budget--) { s->failed_pc=0x0c0b786eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7872u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7872u) { target=s->pc; goto dispatch; }
goto P_0c0b7872;
P_0c0b7870: /* original 65c2, guest PC 0x0c0b7870 */
if(!s->budget--) { s->failed_pc=0x0c0b7870u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7872;
P_0c0b7872: /* original 948a, guest PC 0x0c0b7872 */
if(!s->budget--) { s->failed_pc=0x0c0b7872u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b798au,2);
goto P_0c0b7874;
P_0c0b7874: /* original 4e0b, guest PC 0x0c0b7874 */
if(!s->budget--) { s->failed_pc=0x0c0b7874u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7878u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7878u) { target=s->pc; goto dispatch; }
goto P_0c0b7878;
P_0c0b7876: /* original 65c2, guest PC 0x0c0b7876 */
if(!s->budget--) { s->failed_pc=0x0c0b7876u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7878;
P_0c0b7878: /* original 9488, guest PC 0x0c0b7878 */
if(!s->budget--) { s->failed_pc=0x0c0b7878u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b798cu,2);
goto P_0c0b787a;
P_0c0b787a: /* original 4e0b, guest PC 0x0c0b787a */
if(!s->budget--) { s->failed_pc=0x0c0b787au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b787eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b787eu) { target=s->pc; goto dispatch; }
goto P_0c0b787e;
P_0c0b787c: /* original 65c2, guest PC 0x0c0b787c */
if(!s->budget--) { s->failed_pc=0x0c0b787cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b787e;
P_0c0b787e: /* original 9486, guest PC 0x0c0b787e */
if(!s->budget--) { s->failed_pc=0x0c0b787eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b798eu,2);
goto P_0c0b7880;
P_0c0b7880: /* original 4e0b, guest PC 0x0c0b7880 */
if(!s->budget--) { s->failed_pc=0x0c0b7880u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7884u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7884u) { target=s->pc; goto dispatch; }
goto P_0c0b7884;
P_0c0b7882: /* original 65c2, guest PC 0x0c0b7882 */
if(!s->budget--) { s->failed_pc=0x0c0b7882u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b7884;
P_0c0b7884: /* original 9484, guest PC 0x0c0b7884 */
if(!s->budget--) { s->failed_pc=0x0c0b7884u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7990u,2);
goto P_0c0b7886;
P_0c0b7886: /* original 4e0b, guest PC 0x0c0b7886 */
if(!s->budget--) { s->failed_pc=0x0c0b7886u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b788au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b788au) { target=s->pc; goto dispatch; }
goto P_0c0b788a;
P_0c0b7888: /* original 65b2, guest PC 0x0c0b7888 */
if(!s->budget--) { s->failed_pc=0x0c0b7888u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b788a;
P_0c0b788a: /* original 9482, guest PC 0x0c0b788a */
if(!s->budget--) { s->failed_pc=0x0c0b788au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7992u,2);
goto P_0c0b788c;
P_0c0b788c: /* original 4e0b, guest PC 0x0c0b788c */
if(!s->budget--) { s->failed_pc=0x0c0b788cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7890u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7890u) { target=s->pc; goto dispatch; }
goto P_0c0b7890;
P_0c0b788e: /* original 65b2, guest PC 0x0c0b788e */
if(!s->budget--) { s->failed_pc=0x0c0b788eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7890;
P_0c0b7890: /* original 9480, guest PC 0x0c0b7890 */
if(!s->budget--) { s->failed_pc=0x0c0b7890u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7994u,2);
goto P_0c0b7892;
P_0c0b7892: /* original 4e0b, guest PC 0x0c0b7892 */
if(!s->budget--) { s->failed_pc=0x0c0b7892u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7896u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7896u) { target=s->pc; goto dispatch; }
goto P_0c0b7896;
P_0c0b7894: /* original 65b2, guest PC 0x0c0b7894 */
if(!s->budget--) { s->failed_pc=0x0c0b7894u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b7896;
P_0c0b7896: /* original 947e, guest PC 0x0c0b7896 */
if(!s->budget--) { s->failed_pc=0x0c0b7896u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7996u,2);
goto P_0c0b7898;
P_0c0b7898: /* original 4e0b, guest PC 0x0c0b7898 */
if(!s->budget--) { s->failed_pc=0x0c0b7898u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b789cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b789cu) { target=s->pc; goto dispatch; }
goto P_0c0b789c;
P_0c0b789a: /* original 65b2, guest PC 0x0c0b789a */
if(!s->budget--) { s->failed_pc=0x0c0b789au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b789c;
P_0c0b789c: /* original 947c, guest PC 0x0c0b789c */
if(!s->budget--) { s->failed_pc=0x0c0b789cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7998u,2);
goto P_0c0b789e;
P_0c0b789e: /* original 4e0b, guest PC 0x0c0b789e */
if(!s->budget--) { s->failed_pc=0x0c0b789eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78a2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78a2u) { target=s->pc; goto dispatch; }
goto P_0c0b78a2;
P_0c0b78a0: /* original 65a2, guest PC 0x0c0b78a0 */
if(!s->budget--) { s->failed_pc=0x0c0b78a0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b78a2;
P_0c0b78a2: /* original 947a, guest PC 0x0c0b78a2 */
if(!s->budget--) { s->failed_pc=0x0c0b78a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b799au,2);
goto P_0c0b78a4;
P_0c0b78a4: /* original 4e0b, guest PC 0x0c0b78a4 */
if(!s->budget--) { s->failed_pc=0x0c0b78a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78a8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78a8u) { target=s->pc; goto dispatch; }
goto P_0c0b78a8;
P_0c0b78a6: /* original 65a2, guest PC 0x0c0b78a6 */
if(!s->budget--) { s->failed_pc=0x0c0b78a6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b78a8;
P_0c0b78a8: /* original 9478, guest PC 0x0c0b78a8 */
if(!s->budget--) { s->failed_pc=0x0c0b78a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b799cu,2);
goto P_0c0b78aa;
P_0c0b78aa: /* original 4e0b, guest PC 0x0c0b78aa */
if(!s->budget--) { s->failed_pc=0x0c0b78aau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78aeu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78aeu) { target=s->pc; goto dispatch; }
goto P_0c0b78ae;
P_0c0b78ac: /* original 65a2, guest PC 0x0c0b78ac */
if(!s->budget--) { s->failed_pc=0x0c0b78acu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b78ae;
P_0c0b78ae: /* original 9476, guest PC 0x0c0b78ae */
if(!s->budget--) { s->failed_pc=0x0c0b78aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b799eu,2);
goto P_0c0b78b0;
P_0c0b78b0: /* original 4e0b, guest PC 0x0c0b78b0 */
if(!s->budget--) { s->failed_pc=0x0c0b78b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78b4u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78b4u) { target=s->pc; goto dispatch; }
goto P_0c0b78b4;
P_0c0b78b2: /* original 65a2, guest PC 0x0c0b78b2 */
if(!s->budget--) { s->failed_pc=0x0c0b78b2u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b78b4;
P_0c0b78b4: /* original 9574, guest PC 0x0c0b78b4 */
if(!s->budget--) { s->failed_pc=0x0c0b78b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79a0u,2);
goto P_0c0b78b6;
P_0c0b78b6: /* original 35dc, guest PC 0x0c0b78b6 */
if(!s->budget--) { s->failed_pc=0x0c0b78b6u; return 0; }
r[5]+=r[13];
goto P_0c0b78b8;
P_0c0b78b8: /* original 2f52, guest PC 0x0c0b78b8 */
if(!s->budget--) { s->failed_pc=0x0c0b78b8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b78ba;
P_0c0b78ba: /* original 9472, guest PC 0x0c0b78ba */
if(!s->budget--) { s->failed_pc=0x0c0b78bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79a2u,2);
goto P_0c0b78bc;
P_0c0b78bc: /* original 4e0b, guest PC 0x0c0b78bc */
if(!s->budget--) { s->failed_pc=0x0c0b78bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78c0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78c0u) { target=s->pc; goto dispatch; }
goto P_0c0b78c0;
P_0c0b78be: /* original 6552, guest PC 0x0c0b78be */
if(!s->budget--) { s->failed_pc=0x0c0b78beu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b78c0;
P_0c0b78c0: /* original 9470, guest PC 0x0c0b78c0 */
if(!s->budget--) { s->failed_pc=0x0c0b78c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79a4u,2);
goto P_0c0b78c2;
P_0c0b78c2: /* original 65f2, guest PC 0x0c0b78c2 */
if(!s->budget--) { s->failed_pc=0x0c0b78c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b78c4;
P_0c0b78c4: /* original 4e0b, guest PC 0x0c0b78c4 */
if(!s->budget--) { s->failed_pc=0x0c0b78c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78c8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78c8u) { target=s->pc; goto dispatch; }
goto P_0c0b78c8;
P_0c0b78c6: /* original 6552, guest PC 0x0c0b78c6 */
if(!s->budget--) { s->failed_pc=0x0c0b78c6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b78c8;
P_0c0b78c8: /* original 956d, guest PC 0x0c0b78c8 */
if(!s->budget--) { s->failed_pc=0x0c0b78c8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79a6u,2);
goto P_0c0b78ca;
P_0c0b78ca: /* original 35dc, guest PC 0x0c0b78ca */
if(!s->budget--) { s->failed_pc=0x0c0b78cau; return 0; }
r[5]+=r[13];
goto P_0c0b78cc;
P_0c0b78cc: /* original 2f52, guest PC 0x0c0b78cc */
if(!s->budget--) { s->failed_pc=0x0c0b78ccu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b78ce;
P_0c0b78ce: /* original 946b, guest PC 0x0c0b78ce */
if(!s->budget--) { s->failed_pc=0x0c0b78ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79a8u,2);
goto P_0c0b78d0;
P_0c0b78d0: /* original 4e0b, guest PC 0x0c0b78d0 */
if(!s->budget--) { s->failed_pc=0x0c0b78d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78d4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78d4u) { target=s->pc; goto dispatch; }
goto P_0c0b78d4;
P_0c0b78d2: /* original 6552, guest PC 0x0c0b78d2 */
if(!s->budget--) { s->failed_pc=0x0c0b78d2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b78d4;
P_0c0b78d4: /* original 9469, guest PC 0x0c0b78d4 */
if(!s->budget--) { s->failed_pc=0x0c0b78d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79aau,2);
goto P_0c0b78d6;
P_0c0b78d6: /* original 65f2, guest PC 0x0c0b78d6 */
if(!s->budget--) { s->failed_pc=0x0c0b78d6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b78d8;
P_0c0b78d8: /* original 4e0b, guest PC 0x0c0b78d8 */
if(!s->budget--) { s->failed_pc=0x0c0b78d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78dcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78dcu) { target=s->pc; goto dispatch; }
goto P_0c0b78dc;
P_0c0b78da: /* original 6552, guest PC 0x0c0b78da */
if(!s->budget--) { s->failed_pc=0x0c0b78dau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b78dc;
P_0c0b78dc: /* original 9467, guest PC 0x0c0b78dc */
if(!s->budget--) { s->failed_pc=0x0c0b78dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79aeu,2);
goto P_0c0b78de;
P_0c0b78de: /* original 9065, guest PC 0x0c0b78de */
if(!s->budget--) { s->failed_pc=0x0c0b78deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79acu,2);
goto P_0c0b78e0;
P_0c0b78e0: /* original 4e0b, guest PC 0x0c0b78e0 */
if(!s->budget--) { s->failed_pc=0x0c0b78e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78e4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78e4u) { target=s->pc; goto dispatch; }
goto P_0c0b78e4;
P_0c0b78e2: /* original 05de, guest PC 0x0c0b78e2 */
if(!s->budget--) { s->failed_pc=0x0c0b78e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b78e4;
P_0c0b78e4: /* original 9564, guest PC 0x0c0b78e4 */
if(!s->budget--) { s->failed_pc=0x0c0b78e4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79b0u,2);
goto P_0c0b78e6;
P_0c0b78e6: /* original 35dc, guest PC 0x0c0b78e6 */
if(!s->budget--) { s->failed_pc=0x0c0b78e6u; return 0; }
r[5]+=r[13];
goto P_0c0b78e8;
P_0c0b78e8: /* original 2f52, guest PC 0x0c0b78e8 */
if(!s->budget--) { s->failed_pc=0x0c0b78e8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b78ea;
P_0c0b78ea: /* original 9462, guest PC 0x0c0b78ea */
if(!s->budget--) { s->failed_pc=0x0c0b78eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79b2u,2);
goto P_0c0b78ec;
P_0c0b78ec: /* original 4e0b, guest PC 0x0c0b78ec */
if(!s->budget--) { s->failed_pc=0x0c0b78ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78f0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78f0u) { target=s->pc; goto dispatch; }
goto P_0c0b78f0;
P_0c0b78ee: /* original 6552, guest PC 0x0c0b78ee */
if(!s->budget--) { s->failed_pc=0x0c0b78eeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b78f0;
P_0c0b78f0: /* original 9460, guest PC 0x0c0b78f0 */
if(!s->budget--) { s->failed_pc=0x0c0b78f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79b4u,2);
goto P_0c0b78f2;
P_0c0b78f2: /* original 65f2, guest PC 0x0c0b78f2 */
if(!s->budget--) { s->failed_pc=0x0c0b78f2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b78f4;
P_0c0b78f4: /* original 4e0b, guest PC 0x0c0b78f4 */
if(!s->budget--) { s->failed_pc=0x0c0b78f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b78f8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b78f8u) { target=s->pc; goto dispatch; }
goto P_0c0b78f8;
P_0c0b78f6: /* original 6552, guest PC 0x0c0b78f6 */
if(!s->budget--) { s->failed_pc=0x0c0b78f6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b78f8;
P_0c0b78f8: /* original 945e, guest PC 0x0c0b78f8 */
if(!s->budget--) { s->failed_pc=0x0c0b78f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79b8u,2);
goto P_0c0b78fa;
P_0c0b78fa: /* original 905c, guest PC 0x0c0b78fa */
if(!s->budget--) { s->failed_pc=0x0c0b78fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79b6u,2);
goto P_0c0b78fc;
P_0c0b78fc: /* original 4e0b, guest PC 0x0c0b78fc */
if(!s->budget--) { s->failed_pc=0x0c0b78fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7900u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7900u) { target=s->pc; goto dispatch; }
goto P_0c0b7900;
P_0c0b78fe: /* original 05de, guest PC 0x0c0b78fe */
if(!s->budget--) { s->failed_pc=0x0c0b78feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7900;
P_0c0b7900: /* original 955b, guest PC 0x0c0b7900 */
if(!s->budget--) { s->failed_pc=0x0c0b7900u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79bau,2);
goto P_0c0b7902;
P_0c0b7902: /* original 35dc, guest PC 0x0c0b7902 */
if(!s->budget--) { s->failed_pc=0x0c0b7902u; return 0; }
r[5]+=r[13];
goto P_0c0b7904;
P_0c0b7904: /* original 2f52, guest PC 0x0c0b7904 */
if(!s->budget--) { s->failed_pc=0x0c0b7904u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b7906;
P_0c0b7906: /* original 9459, guest PC 0x0c0b7906 */
if(!s->budget--) { s->failed_pc=0x0c0b7906u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79bcu,2);
goto P_0c0b7908;
P_0c0b7908: /* original 4e0b, guest PC 0x0c0b7908 */
if(!s->budget--) { s->failed_pc=0x0c0b7908u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b790cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b790cu) { target=s->pc; goto dispatch; }
goto P_0c0b790c;
P_0c0b790a: /* original 6552, guest PC 0x0c0b790a */
if(!s->budget--) { s->failed_pc=0x0c0b790au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b790c;
P_0c0b790c: /* original 9457, guest PC 0x0c0b790c */
if(!s->budget--) { s->failed_pc=0x0c0b790cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79beu,2);
goto P_0c0b790e;
P_0c0b790e: /* original 65f2, guest PC 0x0c0b790e */
if(!s->budget--) { s->failed_pc=0x0c0b790eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b7910;
P_0c0b7910: /* original 4e0b, guest PC 0x0c0b7910 */
if(!s->budget--) { s->failed_pc=0x0c0b7910u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7914u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7914u) { target=s->pc; goto dispatch; }
goto P_0c0b7914;
P_0c0b7912: /* original 6552, guest PC 0x0c0b7912 */
if(!s->budget--) { s->failed_pc=0x0c0b7912u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7914;
P_0c0b7914: /* original 9455, guest PC 0x0c0b7914 */
if(!s->budget--) { s->failed_pc=0x0c0b7914u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79c2u,2);
goto P_0c0b7916;
P_0c0b7916: /* original 9053, guest PC 0x0c0b7916 */
if(!s->budget--) { s->failed_pc=0x0c0b7916u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79c0u,2);
goto P_0c0b7918;
P_0c0b7918: /* original 4e0b, guest PC 0x0c0b7918 */
if(!s->budget--) { s->failed_pc=0x0c0b7918u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b791cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b791cu) { target=s->pc; goto dispatch; }
goto P_0c0b791c;
P_0c0b791a: /* original 05de, guest PC 0x0c0b791a */
if(!s->budget--) { s->failed_pc=0x0c0b791au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b791c;
P_0c0b791c: /* original 9552, guest PC 0x0c0b791c */
if(!s->budget--) { s->failed_pc=0x0c0b791cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79c4u,2);
goto P_0c0b791e;
P_0c0b791e: /* original 35dc, guest PC 0x0c0b791e */
if(!s->budget--) { s->failed_pc=0x0c0b791eu; return 0; }
r[5]+=r[13];
goto P_0c0b7920;
P_0c0b7920: /* original 2f52, guest PC 0x0c0b7920 */
if(!s->budget--) { s->failed_pc=0x0c0b7920u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b7922;
P_0c0b7922: /* original 9450, guest PC 0x0c0b7922 */
if(!s->budget--) { s->failed_pc=0x0c0b7922u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79c6u,2);
goto P_0c0b7924;
P_0c0b7924: /* original 4e0b, guest PC 0x0c0b7924 */
if(!s->budget--) { s->failed_pc=0x0c0b7924u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7928u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7928u) { target=s->pc; goto dispatch; }
goto P_0c0b7928;
P_0c0b7926: /* original 6552, guest PC 0x0c0b7926 */
if(!s->budget--) { s->failed_pc=0x0c0b7926u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7928;
P_0c0b7928: /* original 944e, guest PC 0x0c0b7928 */
if(!s->budget--) { s->failed_pc=0x0c0b7928u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79c8u,2);
goto P_0c0b792a;
P_0c0b792a: /* original 65f2, guest PC 0x0c0b792a */
if(!s->budget--) { s->failed_pc=0x0c0b792au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b792c;
P_0c0b792c: /* original 4e0b, guest PC 0x0c0b792c */
if(!s->budget--) { s->failed_pc=0x0c0b792cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7930u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7930u) { target=s->pc; goto dispatch; }
goto P_0c0b7930;
P_0c0b792e: /* original 6552, guest PC 0x0c0b792e */
if(!s->budget--) { s->failed_pc=0x0c0b792eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7930;
P_0c0b7930: /* original 954b, guest PC 0x0c0b7930 */
if(!s->budget--) { s->failed_pc=0x0c0b7930u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79cau,2);
goto P_0c0b7932;
P_0c0b7932: /* original 35dc, guest PC 0x0c0b7932 */
if(!s->budget--) { s->failed_pc=0x0c0b7932u; return 0; }
r[5]+=r[13];
goto P_0c0b7934;
P_0c0b7934: /* original 2f52, guest PC 0x0c0b7934 */
if(!s->budget--) { s->failed_pc=0x0c0b7934u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b7936;
P_0c0b7936: /* original 9449, guest PC 0x0c0b7936 */
if(!s->budget--) { s->failed_pc=0x0c0b7936u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79ccu,2);
goto P_0c0b7938;
P_0c0b7938: /* original 4e0b, guest PC 0x0c0b7938 */
if(!s->budget--) { s->failed_pc=0x0c0b7938u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b793cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b793cu) { target=s->pc; goto dispatch; }
goto P_0c0b793c;
P_0c0b793a: /* original 6552, guest PC 0x0c0b793a */
if(!s->budget--) { s->failed_pc=0x0c0b793au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b793c;
P_0c0b793c: /* original 9447, guest PC 0x0c0b793c */
if(!s->budget--) { s->failed_pc=0x0c0b793cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79ceu,2);
goto P_0c0b793e;
P_0c0b793e: /* original 65f2, guest PC 0x0c0b793e */
if(!s->budget--) { s->failed_pc=0x0c0b793eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b7940;
P_0c0b7940: /* original 4e0b, guest PC 0x0c0b7940 */
if(!s->budget--) { s->failed_pc=0x0c0b7940u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7944u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7944u) { target=s->pc; goto dispatch; }
goto P_0c0b7944;
P_0c0b7942: /* original 6552, guest PC 0x0c0b7942 */
if(!s->budget--) { s->failed_pc=0x0c0b7942u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b7944;
P_0c0b7944: /* original 9445, guest PC 0x0c0b7944 */
if(!s->budget--) { s->failed_pc=0x0c0b7944u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79d2u,2);
goto P_0c0b7946;
P_0c0b7946: /* original 9043, guest PC 0x0c0b7946 */
if(!s->budget--) { s->failed_pc=0x0c0b7946u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79d0u,2);
goto P_0c0b7948;
P_0c0b7948: /* original 4e0b, guest PC 0x0c0b7948 */
if(!s->budget--) { s->failed_pc=0x0c0b7948u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b794cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b794cu) { target=s->pc; goto dispatch; }
goto P_0c0b794c;
P_0c0b794a: /* original 05de, guest PC 0x0c0b794a */
if(!s->budget--) { s->failed_pc=0x0c0b794au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b794c;
P_0c0b794c: /* original 9443, guest PC 0x0c0b794c */
if(!s->budget--) { s->failed_pc=0x0c0b794cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79d6u,2);
goto P_0c0b794e;
P_0c0b794e: /* original 9041, guest PC 0x0c0b794e */
if(!s->budget--) { s->failed_pc=0x0c0b794eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79d4u,2);
goto P_0c0b7950;
P_0c0b7950: /* original 4e0b, guest PC 0x0c0b7950 */
if(!s->budget--) { s->failed_pc=0x0c0b7950u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7954u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7954u) { target=s->pc; goto dispatch; }
goto P_0c0b7954;
P_0c0b7952: /* original 05de, guest PC 0x0c0b7952 */
if(!s->budget--) { s->failed_pc=0x0c0b7952u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7954;
P_0c0b7954: /* original 9441, guest PC 0x0c0b7954 */
if(!s->budget--) { s->failed_pc=0x0c0b7954u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79dau,2);
goto P_0c0b7956;
P_0c0b7956: /* original 903f, guest PC 0x0c0b7956 */
if(!s->budget--) { s->failed_pc=0x0c0b7956u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79d8u,2);
goto P_0c0b7958;
P_0c0b7958: /* original 4e0b, guest PC 0x0c0b7958 */
if(!s->budget--) { s->failed_pc=0x0c0b7958u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b795cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b795cu) { target=s->pc; goto dispatch; }
goto P_0c0b795c;
P_0c0b795a: /* original 05de, guest PC 0x0c0b795a */
if(!s->budget--) { s->failed_pc=0x0c0b795au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b795c;
P_0c0b795c: /* original 943f, guest PC 0x0c0b795c */
if(!s->budget--) { s->failed_pc=0x0c0b795cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79deu,2);
goto P_0c0b795e;
P_0c0b795e: /* original 903d, guest PC 0x0c0b795e */
if(!s->budget--) { s->failed_pc=0x0c0b795eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79dcu,2);
goto P_0c0b7960;
P_0c0b7960: /* original 4e0b, guest PC 0x0c0b7960 */
if(!s->budget--) { s->failed_pc=0x0c0b7960u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7964u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7964u) { target=s->pc; goto dispatch; }
goto P_0c0b7964;
P_0c0b7962: /* original 05de, guest PC 0x0c0b7962 */
if(!s->budget--) { s->failed_pc=0x0c0b7962u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7964;
P_0c0b7964: /* original 903c, guest PC 0x0c0b7964 */
if(!s->budget--) { s->failed_pc=0x0c0b7964u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b79e0u,2);
goto P_0c0b7966;
P_0c0b7966: /* original a03c, guest PC 0x0c0b7966 */
if(!s->budget--) { s->failed_pc=0x0c0b7966u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b79e2;
P_0c0b7968: /* original 05de, guest PC 0x0c0b7968 */
if(!s->budget--) { s->failed_pc=0x0c0b7968u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b796au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b796au; return 0; } return 1;
P_0c0b79e2: /* original 942e, guest PC 0x0c0b79e2 */
if(!s->budget--) { s->failed_pc=0x0c0b79e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a42u,2);
goto P_0c0b79e4;
P_0c0b79e4: /* original 4e0b, guest PC 0x0c0b79e4 */
if(!s->budget--) { s->failed_pc=0x0c0b79e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b79e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b79e8u) { target=s->pc; goto dispatch; }
goto P_0c0b79e8;
P_0c0b79e6: /* original 0009, guest PC 0x0c0b79e6 */
if(!s->budget--) { s->failed_pc=0x0c0b79e6u; return 0; }
goto P_0c0b79e8;
P_0c0b79e8: /* original 942d, guest PC 0x0c0b79e8 */
if(!s->budget--) { s->failed_pc=0x0c0b79e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a46u,2);
goto P_0c0b79ea;
P_0c0b79ea: /* original 902b, guest PC 0x0c0b79ea */
if(!s->budget--) { s->failed_pc=0x0c0b79eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a44u,2);
goto P_0c0b79ec;
P_0c0b79ec: /* original 4e0b, guest PC 0x0c0b79ec */
if(!s->budget--) { s->failed_pc=0x0c0b79ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b79f0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b79f0u) { target=s->pc; goto dispatch; }
goto P_0c0b79f0;
P_0c0b79ee: /* original 05de, guest PC 0x0c0b79ee */
if(!s->budget--) { s->failed_pc=0x0c0b79eeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b79f0;
P_0c0b79f0: /* original 942b, guest PC 0x0c0b79f0 */
if(!s->budget--) { s->failed_pc=0x0c0b79f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a4au,2);
goto P_0c0b79f2;
P_0c0b79f2: /* original 9029, guest PC 0x0c0b79f2 */
if(!s->budget--) { s->failed_pc=0x0c0b79f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a48u,2);
goto P_0c0b79f4;
P_0c0b79f4: /* original 4e0b, guest PC 0x0c0b79f4 */
if(!s->budget--) { s->failed_pc=0x0c0b79f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b79f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b79f8u) { target=s->pc; goto dispatch; }
goto P_0c0b79f8;
P_0c0b79f6: /* original 05de, guest PC 0x0c0b79f6 */
if(!s->budget--) { s->failed_pc=0x0c0b79f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b79f8;
P_0c0b79f8: /* original 9429, guest PC 0x0c0b79f8 */
if(!s->budget--) { s->failed_pc=0x0c0b79f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a4eu,2);
goto P_0c0b79fa;
P_0c0b79fa: /* original 9027, guest PC 0x0c0b79fa */
if(!s->budget--) { s->failed_pc=0x0c0b79fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a4cu,2);
goto P_0c0b79fc;
P_0c0b79fc: /* original 4e0b, guest PC 0x0c0b79fc */
if(!s->budget--) { s->failed_pc=0x0c0b79fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7a00u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7a00u) { target=s->pc; goto dispatch; }
goto P_0c0b7a00;
P_0c0b79fe: /* original 05de, guest PC 0x0c0b79fe */
if(!s->budget--) { s->failed_pc=0x0c0b79feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7a00;
P_0c0b7a00: /* original 9427, guest PC 0x0c0b7a00 */
if(!s->budget--) { s->failed_pc=0x0c0b7a00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a52u,2);
goto P_0c0b7a02;
P_0c0b7a02: /* original 9025, guest PC 0x0c0b7a02 */
if(!s->budget--) { s->failed_pc=0x0c0b7a02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a50u,2);
goto P_0c0b7a04;
P_0c0b7a04: /* original 4e0b, guest PC 0x0c0b7a04 */
if(!s->budget--) { s->failed_pc=0x0c0b7a04u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7a08u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7a08u) { target=s->pc; goto dispatch; }
goto P_0c0b7a08;
P_0c0b7a06: /* original 05de, guest PC 0x0c0b7a06 */
if(!s->budget--) { s->failed_pc=0x0c0b7a06u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7a08;
P_0c0b7a08: /* original 9425, guest PC 0x0c0b7a08 */
if(!s->budget--) { s->failed_pc=0x0c0b7a08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a56u,2);
goto P_0c0b7a0a;
P_0c0b7a0a: /* original 9023, guest PC 0x0c0b7a0a */
if(!s->budget--) { s->failed_pc=0x0c0b7a0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a54u,2);
goto P_0c0b7a0c;
P_0c0b7a0c: /* original 4e0b, guest PC 0x0c0b7a0c */
if(!s->budget--) { s->failed_pc=0x0c0b7a0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7a10u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7a10u) { target=s->pc; goto dispatch; }
goto P_0c0b7a10;
P_0c0b7a0e: /* original 05de, guest PC 0x0c0b7a0e */
if(!s->budget--) { s->failed_pc=0x0c0b7a0eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7a10;
P_0c0b7a10: /* original 9423, guest PC 0x0c0b7a10 */
if(!s->budget--) { s->failed_pc=0x0c0b7a10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a5au,2);
goto P_0c0b7a12;
P_0c0b7a12: /* original 9021, guest PC 0x0c0b7a12 */
if(!s->budget--) { s->failed_pc=0x0c0b7a12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a58u,2);
goto P_0c0b7a14;
P_0c0b7a14: /* original 4e0b, guest PC 0x0c0b7a14 */
if(!s->budget--) { s->failed_pc=0x0c0b7a14u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7a18u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7a18u) { target=s->pc; goto dispatch; }
goto P_0c0b7a18;
P_0c0b7a16: /* original 05de, guest PC 0x0c0b7a16 */
if(!s->budget--) { s->failed_pc=0x0c0b7a16u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7a18;
P_0c0b7a18: /* original 9421, guest PC 0x0c0b7a18 */
if(!s->budget--) { s->failed_pc=0x0c0b7a18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a5eu,2);
goto P_0c0b7a1a;
P_0c0b7a1a: /* original 901f, guest PC 0x0c0b7a1a */
if(!s->budget--) { s->failed_pc=0x0c0b7a1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a5cu,2);
goto P_0c0b7a1c;
P_0c0b7a1c: /* original 4e0b, guest PC 0x0c0b7a1c */
if(!s->budget--) { s->failed_pc=0x0c0b7a1cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7a20u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7a20u) { target=s->pc; goto dispatch; }
goto P_0c0b7a20;
P_0c0b7a1e: /* original 05de, guest PC 0x0c0b7a1e */
if(!s->budget--) { s->failed_pc=0x0c0b7a1eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7a20;
P_0c0b7a20: /* original 941f, guest PC 0x0c0b7a20 */
if(!s->budget--) { s->failed_pc=0x0c0b7a20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a62u,2);
goto P_0c0b7a22;
P_0c0b7a22: /* original 901d, guest PC 0x0c0b7a22 */
if(!s->budget--) { s->failed_pc=0x0c0b7a22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a60u,2);
goto P_0c0b7a24;
P_0c0b7a24: /* original 4e0b, guest PC 0x0c0b7a24 */
if(!s->budget--) { s->failed_pc=0x0c0b7a24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7a28u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7a28u) { target=s->pc; goto dispatch; }
goto P_0c0b7a28;
P_0c0b7a26: /* original 05de, guest PC 0x0c0b7a26 */
if(!s->budget--) { s->failed_pc=0x0c0b7a26u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7a28;
P_0c0b7a28: /* original 941d, guest PC 0x0c0b7a28 */
if(!s->budget--) { s->failed_pc=0x0c0b7a28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a66u,2);
goto P_0c0b7a2a;
P_0c0b7a2a: /* original 901b, guest PC 0x0c0b7a2a */
if(!s->budget--) { s->failed_pc=0x0c0b7a2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b7a64u,2);
goto P_0c0b7a2c;
P_0c0b7a2c: /* original 4e0b, guest PC 0x0c0b7a2c */
if(!s->budget--) { s->failed_pc=0x0c0b7a2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b7a30u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b7a30u) { target=s->pc; goto dispatch; }
goto P_0c0b7a30;
P_0c0b7a2e: /* original 05de, guest PC 0x0c0b7a2e */
if(!s->budget--) { s->failed_pc=0x0c0b7a2eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b7a30;
P_0c0b7a30: /* original 7f08, guest PC 0x0c0b7a30 */
if(!s->budget--) { s->failed_pc=0x0c0b7a30u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b7a32;
P_0c0b7a32: /* original 4f26, guest PC 0x0c0b7a32 */
if(!s->budget--) { s->failed_pc=0x0c0b7a32u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b7a34;
P_0c0b7a34: /* original 69f6, guest PC 0x0c0b7a34 */
if(!s->budget--) { s->failed_pc=0x0c0b7a34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b7a36;
P_0c0b7a36: /* original 6af6, guest PC 0x0c0b7a36 */
if(!s->budget--) { s->failed_pc=0x0c0b7a36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b7a38;
P_0c0b7a38: /* original 6bf6, guest PC 0x0c0b7a38 */
if(!s->budget--) { s->failed_pc=0x0c0b7a38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b7a3a;
P_0c0b7a3a: /* original 6cf6, guest PC 0x0c0b7a3a */
if(!s->budget--) { s->failed_pc=0x0c0b7a3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b7a3c;
P_0c0b7a3c: /* original 6df6, guest PC 0x0c0b7a3c */
if(!s->budget--) { s->failed_pc=0x0c0b7a3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b7a3e;
P_0c0b7a3e: /* original 000b, guest PC 0x0c0b7a3e */
if(!s->budget--) { s->failed_pc=0x0c0b7a3eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b7a40: /* original 6ef6, guest PC 0x0c0b7a40 */
if(!s->budget--) { s->failed_pc=0x0c0b7a40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b7a42u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b7a42u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
