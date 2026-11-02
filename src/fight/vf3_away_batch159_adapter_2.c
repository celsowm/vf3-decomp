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
int vf3_away_batch159_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c075cu: goto P_0c0c075c;
case 0x0c0c075eu: goto P_0c0c075e;
case 0x0c0c0760u: goto P_0c0c0760;
case 0x0c0c0762u: goto P_0c0c0762;
case 0x0c0c0764u: goto P_0c0c0764;
case 0x0c0c0766u: goto P_0c0c0766;
case 0x0c0c0768u: goto P_0c0c0768;
case 0x0c0c076au: goto P_0c0c076a;
case 0x0c0c076cu: goto P_0c0c076c;
case 0x0c0c076eu: goto P_0c0c076e;
case 0x0c0c0770u: goto P_0c0c0770;
case 0x0c0c0772u: goto P_0c0c0772;
case 0x0c0c0774u: goto P_0c0c0774;
case 0x0c0c0776u: goto P_0c0c0776;
case 0x0c0c0778u: goto P_0c0c0778;
case 0x0c0c077au: goto P_0c0c077a;
case 0x0c0c077cu: goto P_0c0c077c;
case 0x0c0c077eu: goto P_0c0c077e;
case 0x0c0c0780u: goto P_0c0c0780;
case 0x0c0c0782u: goto P_0c0c0782;
case 0x0c0c0784u: goto P_0c0c0784;
case 0x0c0c0786u: goto P_0c0c0786;
case 0x0c0c0788u: goto P_0c0c0788;
case 0x0c0c078au: goto P_0c0c078a;
case 0x0c0c078cu: goto P_0c0c078c;
case 0x0c0c078eu: goto P_0c0c078e;
case 0x0c0c0790u: goto P_0c0c0790;
case 0x0c0c0792u: goto P_0c0c0792;
case 0x0c0c0794u: goto P_0c0c0794;
case 0x0c0c0796u: goto P_0c0c0796;
case 0x0c0c0798u: goto P_0c0c0798;
case 0x0c0c079au: goto P_0c0c079a;
case 0x0c0c079cu: goto P_0c0c079c;
case 0x0c0c079eu: goto P_0c0c079e;
case 0x0c0c07a0u: goto P_0c0c07a0;
case 0x0c0c07a2u: goto P_0c0c07a2;
case 0x0c0c07a4u: goto P_0c0c07a4;
case 0x0c0c07a6u: goto P_0c0c07a6;
case 0x0c0c07a8u: goto P_0c0c07a8;
case 0x0c0c07aau: goto P_0c0c07aa;
case 0x0c0c07acu: goto P_0c0c07ac;
case 0x0c0c07aeu: goto P_0c0c07ae;
case 0x0c0c07b0u: goto P_0c0c07b0;
case 0x0c0c07b2u: goto P_0c0c07b2;
case 0x0c0c07b4u: goto P_0c0c07b4;
case 0x0c0c07b6u: goto P_0c0c07b6;
case 0x0c0c07b8u: goto P_0c0c07b8;
case 0x0c0c07bau: goto P_0c0c07ba;
case 0x0c0c07bcu: goto P_0c0c07bc;
case 0x0c0c07beu: goto P_0c0c07be;
case 0x0c0c07c0u: goto P_0c0c07c0;
case 0x0c0c07c2u: goto P_0c0c07c2;
case 0x0c0c07c4u: goto P_0c0c07c4;
case 0x0c0c07c6u: goto P_0c0c07c6;
case 0x0c0c07c8u: goto P_0c0c07c8;
case 0x0c0c07cau: goto P_0c0c07ca;
case 0x0c0c07ccu: goto P_0c0c07cc;
case 0x0c0c07ceu: goto P_0c0c07ce;
case 0x0c0c07d0u: goto P_0c0c07d0;
case 0x0c0c07d2u: goto P_0c0c07d2;
case 0x0c0c07d4u: goto P_0c0c07d4;
case 0x0c0c07d6u: goto P_0c0c07d6;
case 0x0c0c07d8u: goto P_0c0c07d8;
case 0x0c0c07dau: goto P_0c0c07da;
case 0x0c0c07dcu: goto P_0c0c07dc;
case 0x0c0c07deu: goto P_0c0c07de;
case 0x0c0c07e0u: goto P_0c0c07e0;
case 0x0c0c07e2u: goto P_0c0c07e2;
case 0x0c0c07e4u: goto P_0c0c07e4;
case 0x0c0c07e6u: goto P_0c0c07e6;
case 0x0c0c07e8u: goto P_0c0c07e8;
case 0x0c0c080cu: goto P_0c0c080c;
case 0x0c0c080eu: goto P_0c0c080e;
case 0x0c0c0810u: goto P_0c0c0810;
case 0x0c0c0812u: goto P_0c0c0812;
case 0x0c0c0814u: goto P_0c0c0814;
case 0x0c0c0816u: goto P_0c0c0816;
case 0x0c0c0818u: goto P_0c0c0818;
case 0x0c0c081au: goto P_0c0c081a;
case 0x0c0c081cu: goto P_0c0c081c;
case 0x0c0c081eu: goto P_0c0c081e;
case 0x0c0c0820u: goto P_0c0c0820;
case 0x0c0c0822u: goto P_0c0c0822;
case 0x0c0c0824u: goto P_0c0c0824;
case 0x0c0c0826u: goto P_0c0c0826;
case 0x0c0c0828u: goto P_0c0c0828;
case 0x0c0c082au: goto P_0c0c082a;
case 0x0c0c082cu: goto P_0c0c082c;
case 0x0c0c082eu: goto P_0c0c082e;
case 0x0c0c0830u: goto P_0c0c0830;
case 0x0c0c0832u: goto P_0c0c0832;
case 0x0c0c0834u: goto P_0c0c0834;
case 0x0c0c0836u: goto P_0c0c0836;
case 0x0c0c0838u: goto P_0c0c0838;
case 0x0c0c083au: goto P_0c0c083a;
case 0x0c0c083cu: goto P_0c0c083c;
case 0x0c0c083eu: goto P_0c0c083e;
case 0x0c0c0840u: goto P_0c0c0840;
case 0x0c0c0842u: goto P_0c0c0842;
case 0x0c0c0844u: goto P_0c0c0844;
case 0x0c0c0846u: goto P_0c0c0846;
case 0x0c0c0848u: goto P_0c0c0848;
case 0x0c0c084au: goto P_0c0c084a;
case 0x0c0c084cu: goto P_0c0c084c;
case 0x0c0c084eu: goto P_0c0c084e;
case 0x0c0c0850u: goto P_0c0c0850;
case 0x0c0c0852u: goto P_0c0c0852;
case 0x0c0c0854u: goto P_0c0c0854;
case 0x0c0c0856u: goto P_0c0c0856;
case 0x0c0c0858u: goto P_0c0c0858;
case 0x0c0c085au: goto P_0c0c085a;
case 0x0c0c085cu: goto P_0c0c085c;
case 0x0c0c085eu: goto P_0c0c085e;
case 0x0c0c0860u: goto P_0c0c0860;
case 0x0c0c0862u: goto P_0c0c0862;
case 0x0c0c0864u: goto P_0c0c0864;
case 0x0c0c0866u: goto P_0c0c0866;
case 0x0c0c0868u: goto P_0c0c0868;
case 0x0c0c086au: goto P_0c0c086a;
case 0x0c0c086cu: goto P_0c0c086c;
case 0x0c0c086eu: goto P_0c0c086e;
case 0x0c0c0870u: goto P_0c0c0870;
case 0x0c0c0872u: goto P_0c0c0872;
case 0x0c0c0874u: goto P_0c0c0874;
case 0x0c0c0876u: goto P_0c0c0876;
case 0x0c0c0878u: goto P_0c0c0878;
case 0x0c0c087au: goto P_0c0c087a;
case 0x0c0c087cu: goto P_0c0c087c;
case 0x0c0c087eu: goto P_0c0c087e;
case 0x0c0c0880u: goto P_0c0c0880;
case 0x0c0c0882u: goto P_0c0c0882;
case 0x0c0c0884u: goto P_0c0c0884;
case 0x0c0c0886u: goto P_0c0c0886;
case 0x0c0c0888u: goto P_0c0c0888;
case 0x0c0c088au: goto P_0c0c088a;
case 0x0c0c088cu: goto P_0c0c088c;
case 0x0c0c088eu: goto P_0c0c088e;
case 0x0c0c0890u: goto P_0c0c0890;
case 0x0c0c0892u: goto P_0c0c0892;
case 0x0c0c0894u: goto P_0c0c0894;
case 0x0c0c0896u: goto P_0c0c0896;
case 0x0c0c0898u: goto P_0c0c0898;
case 0x0c0c089au: goto P_0c0c089a;
case 0x0c0c089cu: goto P_0c0c089c;
case 0x0c0c089eu: goto P_0c0c089e;
case 0x0c0c08a0u: goto P_0c0c08a0;
case 0x0c0c08a2u: goto P_0c0c08a2;
case 0x0c0c08a4u: goto P_0c0c08a4;
case 0x0c0c08a6u: goto P_0c0c08a6;
case 0x0c0c08a8u: goto P_0c0c08a8;
case 0x0c0c08aau: goto P_0c0c08aa;
case 0x0c0c08acu: goto P_0c0c08ac;
case 0x0c0c08aeu: goto P_0c0c08ae;
case 0x0c0c08ccu: goto P_0c0c08cc;
case 0x0c0c08ceu: goto P_0c0c08ce;
case 0x0c0c08d0u: goto P_0c0c08d0;
case 0x0c0c08d2u: goto P_0c0c08d2;
case 0x0c0c08d4u: goto P_0c0c08d4;
case 0x0c0c08d6u: goto P_0c0c08d6;
case 0x0c0c08d8u: goto P_0c0c08d8;
case 0x0c0c08dau: goto P_0c0c08da;
case 0x0c0c08dcu: goto P_0c0c08dc;
case 0x0c0c08deu: goto P_0c0c08de;
case 0x0c0c08e0u: goto P_0c0c08e0;
case 0x0c0c08e2u: goto P_0c0c08e2;
case 0x0c0c08e4u: goto P_0c0c08e4;
case 0x0c0c08e6u: goto P_0c0c08e6;
case 0x0c0c08e8u: goto P_0c0c08e8;
case 0x0c0c08eau: goto P_0c0c08ea;
case 0x0c0c08ecu: goto P_0c0c08ec;
case 0x0c0c08eeu: goto P_0c0c08ee;
case 0x0c0c08f0u: goto P_0c0c08f0;
case 0x0c0c08f2u: goto P_0c0c08f2;
case 0x0c0c08f4u: goto P_0c0c08f4;
case 0x0c0c08f6u: goto P_0c0c08f6;
case 0x0c0c08f8u: goto P_0c0c08f8;
case 0x0c0c08fau: goto P_0c0c08fa;
case 0x0c0c08fcu: goto P_0c0c08fc;
case 0x0c0c08feu: goto P_0c0c08fe;
case 0x0c0c0900u: goto P_0c0c0900;
case 0x0c0c0902u: goto P_0c0c0902;
case 0x0c0c0904u: goto P_0c0c0904;
case 0x0c0c0906u: goto P_0c0c0906;
case 0x0c0c0908u: goto P_0c0c0908;
case 0x0c0c090au: goto P_0c0c090a;
case 0x0c0c090cu: goto P_0c0c090c;
case 0x0c0c090eu: goto P_0c0c090e;
case 0x0c0c0910u: goto P_0c0c0910;
case 0x0c0c0912u: goto P_0c0c0912;
case 0x0c0c0914u: goto P_0c0c0914;
case 0x0c0c0916u: goto P_0c0c0916;
case 0x0c0c0918u: goto P_0c0c0918;
case 0x0c0c091au: goto P_0c0c091a;
case 0x0c0c091cu: goto P_0c0c091c;
case 0x0c0c091eu: goto P_0c0c091e;
case 0x0c0c0920u: goto P_0c0c0920;
case 0x0c0c0922u: goto P_0c0c0922;
case 0x0c0c0924u: goto P_0c0c0924;
case 0x0c0c0926u: goto P_0c0c0926;
case 0x0c0c0928u: goto P_0c0c0928;
case 0x0c0c092au: goto P_0c0c092a;
case 0x0c0c092cu: goto P_0c0c092c;
case 0x0c0c092eu: goto P_0c0c092e;
case 0x0c0c0930u: goto P_0c0c0930;
case 0x0c0c0932u: goto P_0c0c0932;
case 0x0c0c0934u: goto P_0c0c0934;
case 0x0c0c0936u: goto P_0c0c0936;
case 0x0c0c0938u: goto P_0c0c0938;
case 0x0c0c093au: goto P_0c0c093a;
case 0x0c0c093cu: goto P_0c0c093c;
case 0x0c0c093eu: goto P_0c0c093e;
case 0x0c0c0940u: goto P_0c0c0940;
case 0x0c0c0942u: goto P_0c0c0942;
case 0x0c0c0944u: goto P_0c0c0944;
case 0x0c0c0946u: goto P_0c0c0946;
case 0x0c0c0948u: goto P_0c0c0948;
case 0x0c0c094au: goto P_0c0c094a;
case 0x0c0c094cu: goto P_0c0c094c;
case 0x0c0c094eu: goto P_0c0c094e;
case 0x0c0c0950u: goto P_0c0c0950;
case 0x0c0c0960u: goto P_0c0c0960;
case 0x0c0c0962u: goto P_0c0c0962;
case 0x0c0c0964u: goto P_0c0c0964;
case 0x0c0c0966u: goto P_0c0c0966;
case 0x0c0c0968u: goto P_0c0c0968;
case 0x0c0c096au: goto P_0c0c096a;
case 0x0c0c096cu: goto P_0c0c096c;
case 0x0c0c096eu: goto P_0c0c096e;
case 0x0c0c0970u: goto P_0c0c0970;
case 0x0c0c0972u: goto P_0c0c0972;
case 0x0c0c0974u: goto P_0c0c0974;
case 0x0c0c0976u: goto P_0c0c0976;
case 0x0c0c0978u: goto P_0c0c0978;
case 0x0c0c097au: goto P_0c0c097a;
case 0x0c0c097cu: goto P_0c0c097c;
case 0x0c0c097eu: goto P_0c0c097e;
case 0x0c0c0980u: goto P_0c0c0980;
case 0x0c0c0982u: goto P_0c0c0982;
case 0x0c0c0984u: goto P_0c0c0984;
case 0x0c0c0986u: goto P_0c0c0986;
case 0x0c0c0988u: goto P_0c0c0988;
case 0x0c0c098au: goto P_0c0c098a;
case 0x0c0c098cu: goto P_0c0c098c;
case 0x0c0c098eu: goto P_0c0c098e;
case 0x0c0c0990u: goto P_0c0c0990;
case 0x0c0c0992u: goto P_0c0c0992;
case 0x0c0c0994u: goto P_0c0c0994;
case 0x0c0c0996u: goto P_0c0c0996;
case 0x0c0c0998u: goto P_0c0c0998;
case 0x0c0c099au: goto P_0c0c099a;
case 0x0c0c099cu: goto P_0c0c099c;
case 0x0c0c099eu: goto P_0c0c099e;
case 0x0c0c09a0u: goto P_0c0c09a0;
case 0x0c0c09a2u: goto P_0c0c09a2;
case 0x0c0c09a4u: goto P_0c0c09a4;
case 0x0c0c09a6u: goto P_0c0c09a6;
case 0x0c0c09a8u: goto P_0c0c09a8;
case 0x0c0c09aau: goto P_0c0c09aa;
case 0x0c0c09acu: goto P_0c0c09ac;
case 0x0c0c09aeu: goto P_0c0c09ae;
case 0x0c0c09b0u: goto P_0c0c09b0;
case 0x0c0c09b2u: goto P_0c0c09b2;
case 0x0c0c09b4u: goto P_0c0c09b4;
case 0x0c0c09b6u: goto P_0c0c09b6;
case 0x0c0c09b8u: goto P_0c0c09b8;
case 0x0c0c09bau: goto P_0c0c09ba;
case 0x0c0c09bcu: goto P_0c0c09bc;
case 0x0c0c09beu: goto P_0c0c09be;
case 0x0c0c09c0u: goto P_0c0c09c0;
case 0x0c0c09c2u: goto P_0c0c09c2;
case 0x0c0c09c4u: goto P_0c0c09c4;
case 0x0c0c09c6u: goto P_0c0c09c6;
case 0x0c0c09c8u: goto P_0c0c09c8;
case 0x0c0c09cau: goto P_0c0c09ca;
case 0x0c0c09ccu: goto P_0c0c09cc;
case 0x0c0c09ceu: goto P_0c0c09ce;
case 0x0c0c09d0u: goto P_0c0c09d0;
case 0x0c0c09d2u: goto P_0c0c09d2;
case 0x0c0c09d4u: goto P_0c0c09d4;
case 0x0c0c09d6u: goto P_0c0c09d6;
case 0x0c0c09d8u: goto P_0c0c09d8;
case 0x0c0c09dau: goto P_0c0c09da;
case 0x0c0c09dcu: goto P_0c0c09dc;
case 0x0c0c09deu: goto P_0c0c09de;
case 0x0c0c09e0u: goto P_0c0c09e0;
case 0x0c0c09e2u: goto P_0c0c09e2;
case 0x0c0c09e4u: goto P_0c0c09e4;
case 0x0c0c09e6u: goto P_0c0c09e6;
case 0x0c0c09e8u: goto P_0c0c09e8;
case 0x0c0c09eau: goto P_0c0c09ea;
case 0x0c0c09ecu: goto P_0c0c09ec;
case 0x0c0c09eeu: goto P_0c0c09ee;
case 0x0c0c09f0u: goto P_0c0c09f0;
case 0x0c0c09f2u: goto P_0c0c09f2;
case 0x0c0c09f4u: goto P_0c0c09f4;
case 0x0c0c09f6u: goto P_0c0c09f6;
case 0x0c0c09f8u: goto P_0c0c09f8;
case 0x0c0c09fau: goto P_0c0c09fa;
case 0x0c0c09fcu: goto P_0c0c09fc;
case 0x0c0c09feu: goto P_0c0c09fe;
case 0x0c0c0a00u: goto P_0c0c0a00;
case 0x0c0c0a02u: goto P_0c0c0a02;
case 0x0c0c0a04u: goto P_0c0c0a04;
case 0x0c0c0a06u: goto P_0c0c0a06;
case 0x0c0c0a08u: goto P_0c0c0a08;
case 0x0c0c0a0au: goto P_0c0c0a0a;
case 0x0c0c0a0cu: goto P_0c0c0a0c;
case 0x0c0c0a0eu: goto P_0c0c0a0e;
case 0x0c0c0a10u: goto P_0c0c0a10;
case 0x0c0c0a12u: goto P_0c0c0a12;
case 0x0c0c0a14u: goto P_0c0c0a14;
case 0x0c0c0a16u: goto P_0c0c0a16;
case 0x0c0c0a18u: goto P_0c0c0a18;
case 0x0c0c0a1au: goto P_0c0c0a1a;
case 0x0c0c0a1cu: goto P_0c0c0a1c;
case 0x0c0c0a1eu: goto P_0c0c0a1e;
case 0x0c0c0a20u: goto P_0c0c0a20;
case 0x0c0c0a22u: goto P_0c0c0a22;
case 0x0c0c0a24u: goto P_0c0c0a24;
case 0x0c0c0a26u: goto P_0c0c0a26;
case 0x0c0c0a28u: goto P_0c0c0a28;
case 0x0c0c0a2au: goto P_0c0c0a2a;
case 0x0c0c0a2cu: goto P_0c0c0a2c;
case 0x0c0c0a2eu: goto P_0c0c0a2e;
case 0x0c0c0a30u: goto P_0c0c0a30;
case 0x0c0c0a32u: goto P_0c0c0a32;
case 0x0c0c0a34u: goto P_0c0c0a34;
case 0x0c0c0a36u: goto P_0c0c0a36;
case 0x0c0c0a38u: goto P_0c0c0a38;
case 0x0c0c0a3au: goto P_0c0c0a3a;
case 0x0c0c0a3cu: goto P_0c0c0a3c;
case 0x0c0c0a3eu: goto P_0c0c0a3e;
case 0x0c0c0a40u: goto P_0c0c0a40;
case 0x0c0c0a42u: goto P_0c0c0a42;
case 0x0c0c0a44u: goto P_0c0c0a44;
case 0x0c0c0a46u: goto P_0c0c0a46;
case 0x0c0c0a48u: goto P_0c0c0a48;
case 0x0c0c0a4au: goto P_0c0c0a4a;
case 0x0c0c0a4cu: goto P_0c0c0a4c;
case 0x0c0c0a4eu: goto P_0c0c0a4e;
case 0x0c0c0a50u: goto P_0c0c0a50;
case 0x0c0c0a52u: goto P_0c0c0a52;
case 0x0c0c0a54u: goto P_0c0c0a54;
case 0x0c0c0a56u: goto P_0c0c0a56;
case 0x0c0c0a58u: goto P_0c0c0a58;
case 0x0c0c0a5au: goto P_0c0c0a5a;
case 0x0c0c0a5cu: goto P_0c0c0a5c;
case 0x0c0c0a5eu: goto P_0c0c0a5e;
case 0x0c0c0a60u: goto P_0c0c0a60;
case 0x0c0c0a62u: goto P_0c0c0a62;
case 0x0c0c0a64u: goto P_0c0c0a64;
case 0x0c0c0a66u: goto P_0c0c0a66;
case 0x0c0c0a68u: goto P_0c0c0a68;
case 0x0c0c0a6au: goto P_0c0c0a6a;
case 0x0c0c0a6cu: goto P_0c0c0a6c;
case 0x0c0c0a94u: goto P_0c0c0a94;
case 0x0c0c0a96u: goto P_0c0c0a96;
case 0x0c0c0a98u: goto P_0c0c0a98;
case 0x0c0c0a9au: goto P_0c0c0a9a;
case 0x0c0c0a9cu: goto P_0c0c0a9c;
case 0x0c0c0a9eu: goto P_0c0c0a9e;
case 0x0c0c0aa0u: goto P_0c0c0aa0;
case 0x0c0c0aa2u: goto P_0c0c0aa2;
case 0x0c0c0aa4u: goto P_0c0c0aa4;
case 0x0c0c0aa6u: goto P_0c0c0aa6;
case 0x0c0c0aa8u: goto P_0c0c0aa8;
case 0x0c0c0aaau: goto P_0c0c0aaa;
case 0x0c0c0aacu: goto P_0c0c0aac;
case 0x0c0c0aaeu: goto P_0c0c0aae;
case 0x0c0c0ab0u: goto P_0c0c0ab0;
case 0x0c0c0ab2u: goto P_0c0c0ab2;
case 0x0c0c0ab4u: goto P_0c0c0ab4;
case 0x0c0c0ab6u: goto P_0c0c0ab6;
case 0x0c0c0ab8u: goto P_0c0c0ab8;
case 0x0c0c0abau: goto P_0c0c0aba;
case 0x0c0c0ac4u: goto P_0c0c0ac4;
case 0x0c0c0ac6u: goto P_0c0c0ac6;
case 0x0c0c0ac8u: goto P_0c0c0ac8;
case 0x0c0c0acau: goto P_0c0c0aca;
case 0x0c0c0accu: goto P_0c0c0acc;
case 0x0c0c0aceu: goto P_0c0c0ace;
case 0x0c0c0ad0u: goto P_0c0c0ad0;
case 0x0c0c0ad2u: goto P_0c0c0ad2;
case 0x0c0c0ad4u: goto P_0c0c0ad4;
case 0x0c0c0ad6u: goto P_0c0c0ad6;
case 0x0c0c0ad8u: goto P_0c0c0ad8;
case 0x0c0c0adau: goto P_0c0c0ada;
case 0x0c0c0adcu: goto P_0c0c0adc;
case 0x0c0c0adeu: goto P_0c0c0ade;
case 0x0c0c0ae0u: goto P_0c0c0ae0;
case 0x0c0c0ae2u: goto P_0c0c0ae2;
case 0x0c0c0ae4u: goto P_0c0c0ae4;
case 0x0c0c0ae6u: goto P_0c0c0ae6;
case 0x0c0c0ae8u: goto P_0c0c0ae8;
case 0x0c0c0aeau: goto P_0c0c0aea;
case 0x0c0c0aecu: goto P_0c0c0aec;
case 0x0c0c0aeeu: goto P_0c0c0aee;
case 0x0c0c0af0u: goto P_0c0c0af0;
case 0x0c0c0af2u: goto P_0c0c0af2;
case 0x0c0c0af4u: goto P_0c0c0af4;
case 0x0c0c0af6u: goto P_0c0c0af6;
case 0x0c0c0af8u: goto P_0c0c0af8;
case 0x0c0c0afau: goto P_0c0c0afa;
case 0x0c0c0afcu: goto P_0c0c0afc;
case 0x0c0c0afeu: goto P_0c0c0afe;
case 0x0c0c0b00u: goto P_0c0c0b00;
case 0x0c0c0b02u: goto P_0c0c0b02;
case 0x0c0c0b04u: goto P_0c0c0b04;
case 0x0c0c0b06u: goto P_0c0c0b06;
case 0x0c0c0b08u: goto P_0c0c0b08;
case 0x0c0c0b0au: goto P_0c0c0b0a;
case 0x0c0c0b0cu: goto P_0c0c0b0c;
case 0x0c0c0b0eu: goto P_0c0c0b0e;
case 0x0c0c0b10u: goto P_0c0c0b10;
case 0x0c0c0b12u: goto P_0c0c0b12;
case 0x0c0c0b14u: goto P_0c0c0b14;
case 0x0c0c0b16u: goto P_0c0c0b16;
case 0x0c0c0b18u: goto P_0c0c0b18;
case 0x0c0c0b1au: goto P_0c0c0b1a;
case 0x0c0c0b1cu: goto P_0c0c0b1c;
case 0x0c0c0b1eu: goto P_0c0c0b1e;
case 0x0c0c0b20u: goto P_0c0c0b20;
case 0x0c0c0b22u: goto P_0c0c0b22;
case 0x0c0c0b24u: goto P_0c0c0b24;
case 0x0c0c0b26u: goto P_0c0c0b26;
case 0x0c0c0b28u: goto P_0c0c0b28;
case 0x0c0c0b2au: goto P_0c0c0b2a;
case 0x0c0c0b2cu: goto P_0c0c0b2c;
case 0x0c0c0b2eu: goto P_0c0c0b2e;
case 0x0c0c0b30u: goto P_0c0c0b30;
case 0x0c0c0b32u: goto P_0c0c0b32;
case 0x0c0c0b34u: goto P_0c0c0b34;
case 0x0c0c0b36u: goto P_0c0c0b36;
case 0x0c0c0b38u: goto P_0c0c0b38;
case 0x0c0c0b3au: goto P_0c0c0b3a;
case 0x0c0c0b3cu: goto P_0c0c0b3c;
case 0x0c0c0b3eu: goto P_0c0c0b3e;
case 0x0c0c0b40u: goto P_0c0c0b40;
case 0x0c0c0b42u: goto P_0c0c0b42;
case 0x0c0c0b44u: goto P_0c0c0b44;
case 0x0c0c0b46u: goto P_0c0c0b46;
case 0x0c0c0b48u: goto P_0c0c0b48;
case 0x0c0c0b4au: goto P_0c0c0b4a;
case 0x0c0c0b4cu: goto P_0c0c0b4c;
case 0x0c0c0b4eu: goto P_0c0c0b4e;
case 0x0c0c0b50u: goto P_0c0c0b50;
case 0x0c0c0b52u: goto P_0c0c0b52;
case 0x0c0c0b54u: goto P_0c0c0b54;
case 0x0c0c0b56u: goto P_0c0c0b56;
case 0x0c0c0b58u: goto P_0c0c0b58;
case 0x0c0c0b5au: goto P_0c0c0b5a;
case 0x0c0c0b5cu: goto P_0c0c0b5c;
case 0x0c0c0b5eu: goto P_0c0c0b5e;
case 0x0c0c0b60u: goto P_0c0c0b60;
case 0x0c0c0b62u: goto P_0c0c0b62;
case 0x0c0c0b64u: goto P_0c0c0b64;
case 0x0c0c0b66u: goto P_0c0c0b66;
case 0x0c0c0b68u: goto P_0c0c0b68;
case 0x0c0c0b6au: goto P_0c0c0b6a;
case 0x0c0c0b6cu: goto P_0c0c0b6c;
case 0x0c0c0b6eu: goto P_0c0c0b6e;
case 0x0c0c0b70u: goto P_0c0c0b70;
case 0x0c0c0b72u: goto P_0c0c0b72;
case 0x0c0c0b74u: goto P_0c0c0b74;
case 0x0c0c0b76u: goto P_0c0c0b76;
case 0x0c0c0b78u: goto P_0c0c0b78;
case 0x0c0c0b7au: goto P_0c0c0b7a;
case 0x0c0c0b7cu: goto P_0c0c0b7c;
case 0x0c0c0b7eu: goto P_0c0c0b7e;
case 0x0c0c0b80u: goto P_0c0c0b80;
case 0x0c0c0b82u: goto P_0c0c0b82;
case 0x0c0c0b84u: goto P_0c0c0b84;
case 0x0c0c0b86u: goto P_0c0c0b86;
case 0x0c0c0b88u: goto P_0c0c0b88;
case 0x0c0c0b8au: goto P_0c0c0b8a;
case 0x0c0c0b8cu: goto P_0c0c0b8c;
case 0x0c0c0b8eu: goto P_0c0c0b8e;
case 0x0c0c0b90u: goto P_0c0c0b90;
case 0x0c0c0b92u: goto P_0c0c0b92;
case 0x0c0c0b94u: goto P_0c0c0b94;
case 0x0c0c0b96u: goto P_0c0c0b96;
case 0x0c0c0b98u: goto P_0c0c0b98;
case 0x0c0c0b9au: goto P_0c0c0b9a;
case 0x0c0c0b9cu: goto P_0c0c0b9c;
case 0x0c0c0b9eu: goto P_0c0c0b9e;
case 0x0c0c0ba0u: goto P_0c0c0ba0;
case 0x0c0c0ba2u: goto P_0c0c0ba2;
case 0x0c0c0ba4u: goto P_0c0c0ba4;
case 0x0c0c0ba6u: goto P_0c0c0ba6;
case 0x0c0c0ba8u: goto P_0c0c0ba8;
case 0x0c0c0baau: goto P_0c0c0baa;
case 0x0c0c0bacu: goto P_0c0c0bac;
case 0x0c0c0baeu: goto P_0c0c0bae;
case 0x0c0c0bb0u: goto P_0c0c0bb0;
case 0x0c0c0bb2u: goto P_0c0c0bb2;
case 0x0c0c0bb4u: goto P_0c0c0bb4;
case 0x0c0c0bb6u: goto P_0c0c0bb6;
case 0x0c0c0bb8u: goto P_0c0c0bb8;
case 0x0c0c0bbau: goto P_0c0c0bba;
case 0x0c0c0bbcu: goto P_0c0c0bbc;
case 0x0c0c0bbeu: goto P_0c0c0bbe;
case 0x0c0c0bc0u: goto P_0c0c0bc0;
case 0x0c0c0bc2u: goto P_0c0c0bc2;
case 0x0c0c0bc4u: goto P_0c0c0bc4;
case 0x0c0c0bc6u: goto P_0c0c0bc6;
case 0x0c0c0bc8u: goto P_0c0c0bc8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c075c: /* original 2fe6, guest PC 0x0c0c075c */
if(!s->budget--) { s->failed_pc=0x0c0c075cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c075e;
P_0c0c075e: /* original e05c, guest PC 0x0c0c075e */
if(!s->budget--) { s->failed_pc=0x0c0c075eu; return 0; }
r[0]=0x0000005cu;
goto P_0c0c0760;
P_0c0c0760: /* original 2fd6, guest PC 0x0c0c0760 */
if(!s->budget--) { s->failed_pc=0x0c0c0760u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0762;
P_0c0c0762: /* original 2fc6, guest PC 0x0c0c0762 */
if(!s->budget--) { s->failed_pc=0x0c0c0762u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0764;
P_0c0c0764: /* original ec01, guest PC 0x0c0c0764 */
if(!s->budget--) { s->failed_pc=0x0c0c0764u; return 0; }
r[12]=0x00000001u;
goto P_0c0c0766;
P_0c0c0766: /* original 2fb6, guest PC 0x0c0c0766 */
if(!s->budget--) { s->failed_pc=0x0c0c0766u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0768;
P_0c0c0768: /* original 2fa6, guest PC 0x0c0c0768 */
if(!s->budget--) { s->failed_pc=0x0c0c0768u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c076a;
P_0c0c076a: /* original 2f96, guest PC 0x0c0c076a */
if(!s->budget--) { s->failed_pc=0x0c0c076au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c076c;
P_0c0c076c: /* original 2f86, guest PC 0x0c0c076c */
if(!s->budget--) { s->failed_pc=0x0c0c076cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c076e;
P_0c0c076e: /* original f456, guest PC 0x0c0c076e */
if(!s->budget--) { s->failed_pc=0x0c0c076eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c0c0770;
P_0c0c0770: /* original 903e, guest PC 0x0c0c0770 */
if(!s->budget--) { s->failed_pc=0x0c0c0770u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07f0u,2);
goto P_0c0c0772;
P_0c0c0772: /* original 4f22, guest PC 0x0c0c0772 */
if(!s->budget--) { s->failed_pc=0x0c0c0772u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c0774;
P_0c0c0774: /* original f546, guest PC 0x0c0c0774 */
if(!s->budget--) { s->failed_pc=0x0c0c0774u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0c0776;
P_0c0c0776: /* original d821, guest PC 0x0c0c0776 */
if(!s->budget--) { s->failed_pc=0x0c0c0776u; return 0; }
r[8]=read(ram,0x0c0c07fcu,4);
goto P_0c0c0778;
P_0c0c0778: /* original f455, guest PC 0x0c0c0778 */
if(!s->budget--) { s->failed_pc=0x0c0c0778u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0c077a;
P_0c0c077a: /* original db21, guest PC 0x0c0c077a */
if(!s->budget--) { s->failed_pc=0x0c0c077au; return 0; }
r[11]=read(ram,0x0c0c0800u,4);
goto P_0c0c077c;
P_0c0c077c: /* original 4f12, guest PC 0x0c0c077c */
if(!s->budget--) { s->failed_pc=0x0c0c077cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c077e;
P_0c0c077e: /* original 7ff0, guest PC 0x0c0c077e */
if(!s->budget--) { s->failed_pc=0x0c0c077eu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c0780;
P_0c0c0780: /* original 8f03, guest PC 0x0c0c0780 */
if(!s->budget--) { s->failed_pc=0x0c0c0780u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(!cond) { goto P_0c0c078a; }
goto P_0c0c0784;
P_0c0c0782: /* original ed00, guest PC 0x0c0c0782 */
if(!s->budget--) { s->failed_pc=0x0c0c0782u; return 0; }
r[13]=0x00000000u;
goto P_0c0c0784;
P_0c0c0784: /* original 9035, guest PC 0x0c0c0784 */
if(!s->budget--) { s->failed_pc=0x0c0c0784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07f2u,2);
goto P_0c0c0786;
P_0c0c0786: /* original a01d, guest PC 0x0c0c0786 */
if(!s->budget--) { s->failed_pc=0x0c0c0786u; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c0c07c4;
P_0c0c0788: /* original 04d4, guest PC 0x0c0c0788 */
if(!s->budget--) { s->failed_pc=0x0c0c0788u; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c0c078a;
P_0c0c078a: /* original 9032, guest PC 0x0c0c078a */
if(!s->budget--) { s->failed_pc=0x0c0c078au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07f2u,2);
goto P_0c0c078c;
P_0c0c078c: /* original 0e4c, guest PC 0x0c0c078c */
if(!s->budget--) { s->failed_pc=0x0c0c078cu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c078e;
P_0c0c078e: /* original 2ee8, guest PC 0x0c0c078e */
if(!s->budget--) { s->failed_pc=0x0c0c078eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c0790;
P_0c0c0790: /* original 8b05, guest PC 0x0c0c0790 */
if(!s->budget--) { s->failed_pc=0x0c0c0790u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c079e; }
goto P_0c0c0792;
P_0c0c0792: /* original 5072, guest PC 0x0c0c0792 */
if(!s->budget--) { s->failed_pc=0x0c0c0792u; return 0; }
r[0]=read(ram,r[7]+8,4);
goto P_0c0c0794;
P_0c0c0794: /* original 4029, guest PC 0x0c0c0794 */
if(!s->budget--) { s->failed_pc=0x0c0c0794u; return 0; }
r[0]>>=16;
goto P_0c0c0796;
P_0c0c0796: /* original 4019, guest PC 0x0c0c0796 */
if(!s->budget--) { s->failed_pc=0x0c0c0796u; return 0; }
r[0]>>=8;
goto P_0c0c0798;
P_0c0c0798: /* original 600e, guest PC 0x0c0c0798 */
if(!s->budget--) { s->failed_pc=0x0c0c0798u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0c079a;
P_0c0c079a: /* original 8807, guest PC 0x0c0c079a */
if(!s->budget--) { s->failed_pc=0x0c0c079au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c079c;
P_0c0c079c: /* original 8912, guest PC 0x0c0c079c */
if(!s->budget--) { s->failed_pc=0x0c0c079cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c07c4; }
goto P_0c0c079e;
P_0c0c079e: /* original 9028, guest PC 0x0c0c079e */
if(!s->budget--) { s->failed_pc=0x0c0c079eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07f2u,2);
goto P_0c0c07a0;
P_0c0c07a0: /* original e940, guest PC 0x0c0c07a0 */
if(!s->budget--) { s->failed_pc=0x0c0c07a0u; return 0; }
r[9]=0x00000040u;
goto P_0c0c07a2;
P_0c0c07a2: /* original 7e01, guest PC 0x0c0c07a2 */
if(!s->budget--) { s->failed_pc=0x0c0c07a2u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c07a4;
P_0c0c07a4: /* original 3e93, guest PC 0x0c0c07a4 */
if(!s->budget--) { s->failed_pc=0x0c0c07a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[9])!=0);
goto P_0c0c07a6;
P_0c0c07a6: /* original 04e4, guest PC 0x0c0c07a6 */
if(!s->budget--) { s->failed_pc=0x0c0c07a6u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0c07a8;
P_0c0c07a8: /* original 8f0c, guest PC 0x0c0c07a8 */
if(!s->budget--) { s->failed_pc=0x0c0c07a8u; return 0; }
cond=r[17]&1u;
r[10]=r[9];
if(!cond) { goto P_0c0c07c4; }
goto P_0c0c07ac;
P_0c0c07aa: /* original 6a93, guest PC 0x0c0c07aa */
if(!s->budget--) { s->failed_pc=0x0c0c07aau; return 0; }
r[10]=r[9];
goto P_0c0c07ac;
P_0c0c07ac: /* original 0494, guest PC 0x0c0c07ac */
if(!s->budget--) { s->failed_pc=0x0c0c07acu; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c07ae;
P_0c0c07ae: /* original 60e3, guest PC 0x0c0c07ae */
if(!s->budget--) { s->failed_pc=0x0c0c07aeu; return 0; }
r[0]=r[14];
goto P_0c0c07b0;
P_0c0c07b0: /* original 5373, guest PC 0x0c0c07b0 */
if(!s->budget--) { s->failed_pc=0x0c0c07b0u; return 0; }
r[3]=read(ram,r[7]+12,4);
goto P_0c0c07b2;
P_0c0c07b2: /* original 8840, guest PC 0x0c0c07b2 */
if(!s->budget--) { s->failed_pc=0x0c0c07b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0c07b4;
P_0c0c07b4: /* original 238b, guest PC 0x0c0c07b4 */
if(!s->budget--) { s->failed_pc=0x0c0c07b4u; return 0; }
r[3]|=r[8];
goto P_0c0c07b6;
P_0c0c07b6: /* original 8d01, guest PC 0x0c0c07b6 */
if(!s->budget--) { s->failed_pc=0x0c0c07b6u; return 0; }
cond=r[17]&1u;
write(ram,r[7]+12,r[3],4);
if(cond) { goto P_0c0c07bc; }
goto P_0c0c07ba;
P_0c0c07b8: /* original 1733, guest PC 0x0c0c07b8 */
if(!s->budget--) { s->failed_pc=0x0c0c07b8u; return 0; }
write(ram,r[7]+12,r[3],4);
goto P_0c0c07ba;
P_0c0c07ba: /* original 6ac3, guest PC 0x0c0c07ba */
if(!s->budget--) { s->failed_pc=0x0c0c07bau; return 0; }
r[10]=r[12];
goto P_0c0c07bc;
P_0c0c07bc: /* original 901a, guest PC 0x0c0c07bc */
if(!s->budget--) { s->failed_pc=0x0c0c07bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07f4u,2);
goto P_0c0c07be;
P_0c0c07be: /* original 024d, guest PC 0x0c0c07be */
if(!s->budget--) { s->failed_pc=0x0c0c07beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c07c0;
P_0c0c07c0: /* original 32ac, guest PC 0x0c0c07c0 */
if(!s->budget--) { s->failed_pc=0x0c0c07c0u; return 0; }
r[2]+=r[10];
goto P_0c0c07c2;
P_0c0c07c2: /* original 0425, guest PC 0x0c0c07c2 */
if(!s->budget--) { s->failed_pc=0x0c0c07c2u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0c07c4;
P_0c0c07c4: /* original 9017, guest PC 0x0c0c07c4 */
if(!s->budget--) { s->failed_pc=0x0c0c07c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07f6u,2);
goto P_0c0c07c6;
P_0c0c07c6: /* original f546, guest PC 0x0c0c07c6 */
if(!s->budget--) { s->failed_pc=0x0c0c07c6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0c07c8;
P_0c0c07c8: /* original f455, guest PC 0x0c0c07c8 */
if(!s->budget--) { s->failed_pc=0x0c0c07c8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0c07ca;
P_0c0c07ca: /* original 8b03, guest PC 0x0c0c07ca */
if(!s->budget--) { s->failed_pc=0x0c0c07cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c07d4; }
goto P_0c0c07cc;
P_0c0c07cc: /* original 5273, guest PC 0x0c0c07cc */
if(!s->budget--) { s->failed_pc=0x0c0c07ccu; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c0c07ce;
P_0c0c07ce: /* original d30d, guest PC 0x0c0c07ce */
if(!s->budget--) { s->failed_pc=0x0c0c07ceu; return 0; }
r[3]=read(ram,0x0c0c0804u,4);
goto P_0c0c07d0;
P_0c0c07d0: /* original 223b, guest PC 0x0c0c07d0 */
if(!s->budget--) { s->failed_pc=0x0c0c07d0u; return 0; }
r[2]|=r[3];
goto P_0c0c07d2;
P_0c0c07d2: /* original 1723, guest PC 0x0c0c07d2 */
if(!s->budget--) { s->failed_pc=0x0c0c07d2u; return 0; }
write(ram,r[7]+12,r[2],4);
goto P_0c0c07d4;
P_0c0c07d4: /* original 5178, guest PC 0x0c0c07d4 */
if(!s->budget--) { s->failed_pc=0x0c0c07d4u; return 0; }
r[1]=read(ram,r[7]+32,4);
goto P_0c0c07d6;
P_0c0c07d6: /* original d30c, guest PC 0x0c0c07d6 */
if(!s->budget--) { s->failed_pc=0x0c0c07d6u; return 0; }
r[3]=read(ram,0x0c0c0808u,4);
goto P_0c0c07d8;
P_0c0c07d8: /* original 2138, guest PC 0x0c0c07d8 */
if(!s->budget--) { s->failed_pc=0x0c0c07d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c07da;
P_0c0c07da: /* original 8b03, guest PC 0x0c0c07da */
if(!s->budget--) { s->failed_pc=0x0c0c07dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c07e4; }
goto P_0c0c07dc;
P_0c0c07dc: /* original 5273, guest PC 0x0c0c07dc */
if(!s->budget--) { s->failed_pc=0x0c0c07dcu; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c0c07de;
P_0c0c07de: /* original 930b, guest PC 0x0c0c07de */
if(!s->budget--) { s->failed_pc=0x0c0c07deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07f8u,2);
goto P_0c0c07e0;
P_0c0c07e0: /* original 2238, guest PC 0x0c0c07e0 */
if(!s->budget--) { s->failed_pc=0x0c0c07e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c07e2;
P_0c0c07e2: /* original 8913, guest PC 0x0c0c07e2 */
if(!s->budget--) { s->failed_pc=0x0c0c07e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c080c; }
goto P_0c0c07e4;
P_0c0c07e4: /* original 9009, guest PC 0x0c0c07e4 */
if(!s->budget--) { s->failed_pc=0x0c0c07e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07fau,2);
goto P_0c0c07e6;
P_0c0c07e6: /* original a032, guest PC 0x0c0c07e6 */
if(!s->budget--) { s->failed_pc=0x0c0c07e6u; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c0c084e;
P_0c0c07e8: /* original 04d4, guest PC 0x0c0c07e8 */
if(!s->budget--) { s->failed_pc=0x0c0c07e8u; return 0; }
write(ram,r[4]+r[0],r[13],1);
if(!vf3_matrix_family(0x0c0c07eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c07eau; return 0; } return 1;
P_0c0c080c: /* original 5279, guest PC 0x0c0c080c */
if(!s->budget--) { s->failed_pc=0x0c0c080cu; return 0; }
r[2]=read(ram,r[7]+36,4);
goto P_0c0c080e;
P_0c0c080e: /* original d32a, guest PC 0x0c0c080e */
if(!s->budget--) { s->failed_pc=0x0c0c080eu; return 0; }
r[3]=read(ram,0x0c0c08b8u,4);
goto P_0c0c0810;
P_0c0c0810: /* original 2238, guest PC 0x0c0c0810 */
if(!s->budget--) { s->failed_pc=0x0c0c0810u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c0812;
P_0c0c0812: /* original 8b1c, guest PC 0x0c0c0812 */
if(!s->budget--) { s->failed_pc=0x0c0c0812u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c084e; }
goto P_0c0c0814;
P_0c0c0814: /* original 904c, guest PC 0x0c0c0814 */
if(!s->budget--) { s->failed_pc=0x0c0c0814u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c08b0u,2);
goto P_0c0c0816;
P_0c0c0816: /* original ea64, guest PC 0x0c0c0816 */
if(!s->budget--) { s->failed_pc=0x0c0c0816u; return 0; }
r[10]=0x00000064u;
goto P_0c0c0818;
P_0c0c0818: /* original 0e4c, guest PC 0x0c0c0818 */
if(!s->budget--) { s->failed_pc=0x0c0c0818u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c081a;
P_0c0c081a: /* original 7e01, guest PC 0x0c0c081a */
if(!s->budget--) { s->failed_pc=0x0c0c081au; return 0; }
r[14]+=0x00000001u;
goto P_0c0c081c;
P_0c0c081c: /* original 69e3, guest PC 0x0c0c081c */
if(!s->budget--) { s->failed_pc=0x0c0c081cu; return 0; }
r[9]=r[14];
goto P_0c0c081e;
P_0c0c081e: /* original 39a3, guest PC 0x0c0c081e */
if(!s->budget--) { s->failed_pc=0x0c0c081eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[10])!=0);
goto P_0c0c0820;
P_0c0c0820: /* original 04e4, guest PC 0x0c0c0820 */
if(!s->budget--) { s->failed_pc=0x0c0c0820u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0c0822;
P_0c0c0822: /* original 8f14, guest PC 0x0c0c0822 */
if(!s->budget--) { s->failed_pc=0x0c0c0822u; return 0; }
cond=r[17]&1u;
r[14]=r[10];
if(!cond) { goto P_0c0c084e; }
goto P_0c0c0826;
P_0c0c0824: /* original 6ea3, guest PC 0x0c0c0824 */
if(!s->budget--) { s->failed_pc=0x0c0c0824u; return 0; }
r[14]=r[10];
goto P_0c0c0826;
P_0c0c0826: /* original 04a4, guest PC 0x0c0c0826 */
if(!s->budget--) { s->failed_pc=0x0c0c0826u; return 0; }
write(ram,r[4]+r[0],r[10],1);
goto P_0c0c0828;
P_0c0c0828: /* original 6093, guest PC 0x0c0c0828 */
if(!s->budget--) { s->failed_pc=0x0c0c0828u; return 0; }
r[0]=r[9];
goto P_0c0c082a;
P_0c0c082a: /* original 8864, guest PC 0x0c0c082a */
if(!s->budget--) { s->failed_pc=0x0c0c082au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000064u)!=0);
goto P_0c0c082c;
P_0c0c082c: /* original 8900, guest PC 0x0c0c082c */
if(!s->budget--) { s->failed_pc=0x0c0c082cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0830; }
goto P_0c0c082e;
P_0c0c082e: /* original 6ec3, guest PC 0x0c0c082e */
if(!s->budget--) { s->failed_pc=0x0c0c082eu; return 0; }
r[14]=r[12];
goto P_0c0c0830;
P_0c0c0830: /* original 903f, guest PC 0x0c0c0830 */
if(!s->budget--) { s->failed_pc=0x0c0c0830u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c08b2u,2);
goto P_0c0c0832;
P_0c0c0832: /* original 034d, guest PC 0x0c0c0832 */
if(!s->budget--) { s->failed_pc=0x0c0c0832u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c0834;
P_0c0c0834: /* original 33ec, guest PC 0x0c0c0834 */
if(!s->budget--) { s->failed_pc=0x0c0c0834u; return 0; }
r[3]+=r[14];
goto P_0c0c0836;
P_0c0c0836: /* original 0435, guest PC 0x0c0c0836 */
if(!s->budget--) { s->failed_pc=0x0c0c0836u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0c0838;
P_0c0c0838: /* original 5278, guest PC 0x0c0c0838 */
if(!s->budget--) { s->failed_pc=0x0c0c0838u; return 0; }
r[2]=read(ram,r[7]+32,4);
goto P_0c0c083a;
P_0c0c083a: /* original d320, guest PC 0x0c0c083a */
if(!s->budget--) { s->failed_pc=0x0c0c083au; return 0; }
r[3]=read(ram,0x0c0c08bcu,4);
goto P_0c0c083c;
P_0c0c083c: /* original 2238, guest PC 0x0c0c083c */
if(!s->budget--) { s->failed_pc=0x0c0c083cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c083e;
P_0c0c083e: /* original 8902, guest PC 0x0c0c083e */
if(!s->budget--) { s->failed_pc=0x0c0c083eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0846; }
goto P_0c0c0840;
P_0c0c0840: /* original 9038, guest PC 0x0c0c0840 */
if(!s->budget--) { s->failed_pc=0x0c0c0840u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c08b4u,2);
goto P_0c0c0842;
P_0c0c0842: /* original a001, guest PC 0x0c0c0842 */
if(!s->budget--) { s->failed_pc=0x0c0c0842u; return 0; }
goto P_0c0c0848;
P_0c0c0844: /* original 0009, guest PC 0x0c0c0844 */
if(!s->budget--) { s->failed_pc=0x0c0c0844u; return 0; }
goto P_0c0c0846;
P_0c0c0846: /* original 9036, guest PC 0x0c0c0846 */
if(!s->budget--) { s->failed_pc=0x0c0c0846u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c08b6u,2);
goto P_0c0c0848;
P_0c0c0848: /* original 034d, guest PC 0x0c0c0848 */
if(!s->budget--) { s->failed_pc=0x0c0c0848u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c084a;
P_0c0c084a: /* original 33ec, guest PC 0x0c0c084a */
if(!s->budget--) { s->failed_pc=0x0c0c084au; return 0; }
r[3]+=r[14];
goto P_0c0c084c;
P_0c0c084c: /* original 0435, guest PC 0x0c0c084c */
if(!s->budget--) { s->failed_pc=0x0c0c084cu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0c084e;
P_0c0c084e: /* original 69d3, guest PC 0x0c0c084e */
if(!s->budget--) { s->failed_pc=0x0c0c084eu; return 0; }
r[9]=r[13];
goto P_0c0c0850;
P_0c0c0850: /* original 6ed3, guest PC 0x0c0c0850 */
if(!s->budget--) { s->failed_pc=0x0c0c0850u; return 0; }
r[14]=r[13];
goto P_0c0c0852;
P_0c0c0852: /* original 1fd1, guest PC 0x0c0c0852 */
if(!s->budget--) { s->failed_pc=0x0c0c0852u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c0c0854;
P_0c0c0854: /* original 5a72, guest PC 0x0c0c0854 */
if(!s->budget--) { s->failed_pc=0x0c0c0854u; return 0; }
r[10]=read(ram,r[7]+8,4);
goto P_0c0c0856;
P_0c0c0856: /* original 5273, guest PC 0x0c0c0856 */
if(!s->budget--) { s->failed_pc=0x0c0c0856u; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c0c0858;
P_0c0c0858: /* original 4a29, guest PC 0x0c0c0858 */
if(!s->budget--) { s->failed_pc=0x0c0c0858u; return 0; }
r[10]>>=16;
goto P_0c0c085a;
P_0c0c085a: /* original d319, guest PC 0x0c0c085a */
if(!s->budget--) { s->failed_pc=0x0c0c085au; return 0; }
r[3]=read(ram,0x0c0c08c0u,4);
goto P_0c0c085c;
P_0c0c085c: /* original 4a19, guest PC 0x0c0c085c */
if(!s->budget--) { s->failed_pc=0x0c0c085cu; return 0; }
r[10]>>=8;
goto P_0c0c085e;
P_0c0c085e: /* original 2238, guest PC 0x0c0c085e */
if(!s->budget--) { s->failed_pc=0x0c0c085eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c0860;
P_0c0c0860: /* original 6aae, guest PC 0x0c0c0860 */
if(!s->budget--) { s->failed_pc=0x0c0c0860u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)r[10];
goto P_0c0c0862;
P_0c0c0862: /* original 8f02, guest PC 0x0c0c0862 */
if(!s->budget--) { s->failed_pc=0x0c0c0862u; return 0; }
cond=r[17]&1u;
r[10]=r[10]&255u;
if(!cond) { goto P_0c0c086a; }
goto P_0c0c0866;
P_0c0c0864: /* original 6aac, guest PC 0x0c0c0864 */
if(!s->budget--) { s->failed_pc=0x0c0c0864u; return 0; }
r[10]=r[10]&255u;
goto P_0c0c0866;
P_0c0c0866: /* original a09d, guest PC 0x0c0c0866 */
if(!s->budget--) { s->failed_pc=0x0c0c0866u; return 0; }
goto P_0c0c09a4;
P_0c0c0868: /* original 0009, guest PC 0x0c0c0868 */
if(!s->budget--) { s->failed_pc=0x0c0c0868u; return 0; }
goto P_0c0c086a;
P_0c0c086a: /* original 517a, guest PC 0x0c0c086a */
if(!s->budget--) { s->failed_pc=0x0c0c086au; return 0; }
r[1]=read(ram,r[7]+40,4);
goto P_0c0c086c;
P_0c0c086c: /* original d315, guest PC 0x0c0c086c */
if(!s->budget--) { s->failed_pc=0x0c0c086cu; return 0; }
r[3]=read(ram,0x0c0c08c4u,4);
goto P_0c0c086e;
P_0c0c086e: /* original 2138, guest PC 0x0c0c086e */
if(!s->budget--) { s->failed_pc=0x0c0c086eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c0870;
P_0c0c0870: /* original 894f, guest PC 0x0c0c0870 */
if(!s->budget--) { s->failed_pc=0x0c0c0870u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0912; }
goto P_0c0c0872;
P_0c0c0872: /* original 60a3, guest PC 0x0c0c0872 */
if(!s->budget--) { s->failed_pc=0x0c0c0872u; return 0; }
r[0]=r[10];
goto P_0c0c0874;
P_0c0c0874: /* original 8807, guest PC 0x0c0c0874 */
if(!s->budget--) { s->failed_pc=0x0c0c0874u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c0876;
P_0c0c0876: /* original 8b03, guest PC 0x0c0c0876 */
if(!s->budget--) { s->failed_pc=0x0c0c0876u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0880; }
goto P_0c0c0878;
P_0c0c0878: /* original 5272, guest PC 0x0c0c0878 */
if(!s->budget--) { s->failed_pc=0x0c0c0878u; return 0; }
r[2]=read(ram,r[7]+8,4);
goto P_0c0c087a;
P_0c0c087a: /* original d313, guest PC 0x0c0c087a */
if(!s->budget--) { s->failed_pc=0x0c0c087au; return 0; }
r[3]=read(ram,0x0c0c08c8u,4);
goto P_0c0c087c;
P_0c0c087c: /* original 2238, guest PC 0x0c0c087c */
if(!s->budget--) { s->failed_pc=0x0c0c087cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c087e;
P_0c0c087e: /* original 8b4f, guest PC 0x0c0c087e */
if(!s->budget--) { s->failed_pc=0x0c0c087eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0920; }
goto P_0c0c0880;
P_0c0c0880: /* original 60a3, guest PC 0x0c0c0880 */
if(!s->budget--) { s->failed_pc=0x0c0c0880u; return 0; }
r[0]=r[10];
goto P_0c0c0882;
P_0c0c0882: /* original 8810, guest PC 0x0c0c0882 */
if(!s->budget--) { s->failed_pc=0x0c0c0882u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0c0884;
P_0c0c0884: /* original 8b01, guest PC 0x0c0c0884 */
if(!s->budget--) { s->failed_pc=0x0c0c0884u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c088a; }
goto P_0c0c0886;
P_0c0c0886: /* original a001, guest PC 0x0c0c0886 */
if(!s->budget--) { s->failed_pc=0x0c0c0886u; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0c088c;
P_0c0c0888: /* original 1fd3, guest PC 0x0c0c0888 */
if(!s->budget--) { s->failed_pc=0x0c0c0888u; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0c088a;
P_0c0c088a: /* original 1fc3, guest PC 0x0c0c088a */
if(!s->budget--) { s->failed_pc=0x0c0c088au; return 0; }
write(ram,r[15]+12,r[12],4);
goto P_0c0c088c;
P_0c0c088c: /* original 60a3, guest PC 0x0c0c088c */
if(!s->budget--) { s->failed_pc=0x0c0c088cu; return 0; }
r[0]=r[10];
goto P_0c0c088e;
P_0c0c088e: /* original 8812, guest PC 0x0c0c088e */
if(!s->budget--) { s->failed_pc=0x0c0c088eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0c0890;
P_0c0c0890: /* original 8b01, guest PC 0x0c0c0890 */
if(!s->budget--) { s->failed_pc=0x0c0c0890u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0896; }
goto P_0c0c0892;
P_0c0c0892: /* original a001, guest PC 0x0c0c0892 */
if(!s->budget--) { s->failed_pc=0x0c0c0892u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0c0898;
P_0c0c0894: /* original 2fd2, guest PC 0x0c0c0894 */
if(!s->budget--) { s->failed_pc=0x0c0c0894u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0c0896;
P_0c0c0896: /* original 2fc2, guest PC 0x0c0c0896 */
if(!s->budget--) { s->failed_pc=0x0c0c0896u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0c0898;
P_0c0c0898: /* original 60a3, guest PC 0x0c0c0898 */
if(!s->budget--) { s->failed_pc=0x0c0c0898u; return 0; }
r[0]=r[10];
goto P_0c0c089a;
P_0c0c089a: /* original 8803, guest PC 0x0c0c089a */
if(!s->budget--) { s->failed_pc=0x0c0c089au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c089c;
P_0c0c089c: /* original 8b01, guest PC 0x0c0c089c */
if(!s->budget--) { s->failed_pc=0x0c0c089cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c08a2; }
goto P_0c0c089e;
P_0c0c089e: /* original a001, guest PC 0x0c0c089e */
if(!s->budget--) { s->failed_pc=0x0c0c089eu; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0c08a4;
P_0c0c08a0: /* original 1fd2, guest PC 0x0c0c08a0 */
if(!s->budget--) { s->failed_pc=0x0c0c08a0u; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0c08a2;
P_0c0c08a2: /* original 1fc2, guest PC 0x0c0c08a2 */
if(!s->budget--) { s->failed_pc=0x0c0c08a2u; return 0; }
write(ram,r[15]+8,r[12],4);
goto P_0c0c08a4;
P_0c0c08a4: /* original 60a3, guest PC 0x0c0c08a4 */
if(!s->budget--) { s->failed_pc=0x0c0c08a4u; return 0; }
r[0]=r[10];
goto P_0c0c08a6;
P_0c0c08a6: /* original 8805, guest PC 0x0c0c08a6 */
if(!s->budget--) { s->failed_pc=0x0c0c08a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c08a8;
P_0c0c08a8: /* original 8f10, guest PC 0x0c0c08a8 */
if(!s->budget--) { s->failed_pc=0x0c0c08a8u; return 0; }
cond=r[17]&1u;
r[14]=0x00000003u;
if(!cond) { goto P_0c0c08cc; }
goto P_0c0c08ac;
P_0c0c08aa: /* original ee03, guest PC 0x0c0c08aa */
if(!s->budget--) { s->failed_pc=0x0c0c08aau; return 0; }
r[14]=0x00000003u;
goto P_0c0c08ac;
P_0c0c08ac: /* original a00f, guest PC 0x0c0c08ac */
if(!s->budget--) { s->failed_pc=0x0c0c08acu; return 0; }
r[10]=r[13];
goto P_0c0c08ce;
P_0c0c08ae: /* original 6ad3, guest PC 0x0c0c08ae */
if(!s->budget--) { s->failed_pc=0x0c0c08aeu; return 0; }
r[10]=r[13];
if(!vf3_matrix_family(0x0c0c08b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c08b0u; return 0; } return 1;
P_0c0c08cc: /* original 6ac3, guest PC 0x0c0c08cc */
if(!s->budget--) { s->failed_pc=0x0c0c08ccu; return 0; }
r[10]=r[12];
goto P_0c0c08ce;
P_0c0c08ce: /* original 53f3, guest PC 0x0c0c08ce */
if(!s->budget--) { s->failed_pc=0x0c0c08ceu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c08d0;
P_0c0c08d0: /* original 2338, guest PC 0x0c0c08d0 */
if(!s->budget--) { s->failed_pc=0x0c0c08d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c08d2;
P_0c0c08d2: /* original 8967, guest PC 0x0c0c08d2 */
if(!s->budget--) { s->failed_pc=0x0c0c08d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09a4; }
goto P_0c0c08d4;
P_0c0c08d4: /* original 62f2, guest PC 0x0c0c08d4 */
if(!s->budget--) { s->failed_pc=0x0c0c08d4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c08d6;
P_0c0c08d6: /* original 2228, guest PC 0x0c0c08d6 */
if(!s->budget--) { s->failed_pc=0x0c0c08d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c08d8;
P_0c0c08d8: /* original 8d64, guest PC 0x0c0c08d8 */
if(!s->budget--) { s->failed_pc=0x0c0c08d8u; return 0; }
cond=r[17]&1u;
r[14]=0x00000002u;
if(cond) { goto P_0c0c09a4; }
goto P_0c0c08dc;
P_0c0c08da: /* original ee02, guest PC 0x0c0c08da */
if(!s->budget--) { s->failed_pc=0x0c0c08dau; return 0; }
r[14]=0x00000002u;
goto P_0c0c08dc;
P_0c0c08dc: /* original 9039, guest PC 0x0c0c08dc */
if(!s->budget--) { s->failed_pc=0x0c0c08dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0952u,2);
goto P_0c0c08de;
P_0c0c08de: /* original 0ebe, guest PC 0x0c0c08de */
if(!s->budget--) { s->failed_pc=0x0c0c08deu; return 0; }
r[14]=read(ram,r[11]+r[0],4);
goto P_0c0c08e0;
P_0c0c08e0: /* original 7004, guest PC 0x0c0c08e0 */
if(!s->budget--) { s->failed_pc=0x0c0c08e0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c08e2;
P_0c0c08e2: /* original 03be, guest PC 0x0c0c08e2 */
if(!s->budget--) { s->failed_pc=0x0c0c08e2u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c0c08e4;
P_0c0c08e4: /* original 7004, guest PC 0x0c0c08e4 */
if(!s->budget--) { s->failed_pc=0x0c0c08e4u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c08e6;
P_0c0c08e6: /* original 02bd, guest PC 0x0c0c08e6 */
if(!s->budget--) { s->failed_pc=0x0c0c08e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0c08e8;
P_0c0c08e8: /* original 70f8, guest PC 0x0c0c08e8 */
if(!s->budget--) { s->failed_pc=0x0c0c08e8u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c08ea;
P_0c0c08ea: /* original 0e37, guest PC 0x0c0c08ea */
if(!s->budget--) { s->failed_pc=0x0c0c08eau; return 0; }
r[19]=r[14]*r[3];
goto P_0c0c08ec;
P_0c0c08ec: /* original 0e1a, guest PC 0x0c0c08ec */
if(!s->budget--) { s->failed_pc=0x0c0c08ecu; return 0; }
r[14]=r[19];
goto P_0c0c08ee;
P_0c0c08ee: /* original 3e2c, guest PC 0x0c0c08ee */
if(!s->budget--) { s->failed_pc=0x0c0c08eeu; return 0; }
r[14]+=r[2];
goto P_0c0c08f0;
P_0c0c08f0: /* original 0be6, guest PC 0x0c0c08f0 */
if(!s->budget--) { s->failed_pc=0x0c0c08f0u; return 0; }
write(ram,r[11]+r[0],r[14],4);
goto P_0c0c08f2;
P_0c0c08f2: /* original 4e29, guest PC 0x0c0c08f2 */
if(!s->budget--) { s->failed_pc=0x0c0c08f2u; return 0; }
r[14]>>=16;
goto P_0c0c08f4;
P_0c0c08f4: /* original 932e, guest PC 0x0c0c08f4 */
if(!s->budget--) { s->failed_pc=0x0c0c08f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0954u,2);
goto P_0c0c08f6;
P_0c0c08f6: /* original 6eef, guest PC 0x0c0c08f6 */
if(!s->budget--) { s->failed_pc=0x0c0c08f6u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c08f8;
P_0c0c08f8: /* original d217, guest PC 0x0c0c08f8 */
if(!s->budget--) { s->failed_pc=0x0c0c08f8u; return 0; }
r[2]=read(ram,0x0c0c0958u,4);
goto P_0c0c08fa;
P_0c0c08fa: /* original e002, guest PC 0x0c0c08fa */
if(!s->budget--) { s->failed_pc=0x0c0c08fau; return 0; }
r[0]=0x00000002u;
goto P_0c0c08fc;
P_0c0c08fc: /* original 2e39, guest PC 0x0c0c08fc */
if(!s->budget--) { s->failed_pc=0x0c0c08fcu; return 0; }
r[14]&=r[3];
goto P_0c0c08fe;
P_0c0c08fe: /* original 420b, guest PC 0x0c0c08fe */
if(!s->budget--) { s->failed_pc=0x0c0c08feu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c0902u;
r[1]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c0902u) { target=s->pc; goto dispatch; }
goto P_0c0c0902;
P_0c0c0900: /* original 61e3, guest PC 0x0c0c0900 */
if(!s->budget--) { s->failed_pc=0x0c0c0900u; return 0; }
r[1]=r[14];
goto P_0c0c0902;
P_0c0c0902: /* original 51f2, guest PC 0x0c0c0902 */
if(!s->budget--) { s->failed_pc=0x0c0c0902u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0c0904;
P_0c0c0904: /* original 6e03, guest PC 0x0c0c0904 */
if(!s->budget--) { s->failed_pc=0x0c0c0904u; return 0; }
r[14]=r[0];
goto P_0c0c0906;
P_0c0c0906: /* original 2118, guest PC 0x0c0c0906 */
if(!s->budget--) { s->failed_pc=0x0c0c0906u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c0908;
P_0c0c0908: /* original 894c, guest PC 0x0c0c0908 */
if(!s->budget--) { s->failed_pc=0x0c0c0908u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09a4; }
goto P_0c0c090a;
P_0c0c090a: /* original 2aa8, guest PC 0x0c0c090a */
if(!s->budget--) { s->failed_pc=0x0c0c090au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c090c;
P_0c0c090c: /* original 894a, guest PC 0x0c0c090c */
if(!s->budget--) { s->failed_pc=0x0c0c090cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09a4; }
goto P_0c0c090e;
P_0c0c090e: /* original a049, guest PC 0x0c0c090e */
if(!s->budget--) { s->failed_pc=0x0c0c090eu; return 0; }
r[14]=r[13];
goto P_0c0c09a4;
P_0c0c0910: /* original 6ed3, guest PC 0x0c0c0910 */
if(!s->budget--) { s->failed_pc=0x0c0c0910u; return 0; }
r[14]=r[13];
goto P_0c0c0912;
P_0c0c0912: /* original 60a3, guest PC 0x0c0c0912 */
if(!s->budget--) { s->failed_pc=0x0c0c0912u; return 0; }
r[0]=r[10];
goto P_0c0c0914;
P_0c0c0914: /* original 8807, guest PC 0x0c0c0914 */
if(!s->budget--) { s->failed_pc=0x0c0c0914u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c0916;
P_0c0c0916: /* original 8b05, guest PC 0x0c0c0916 */
if(!s->budget--) { s->failed_pc=0x0c0c0916u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0924; }
goto P_0c0c0918;
P_0c0c0918: /* original 5272, guest PC 0x0c0c0918 */
if(!s->budget--) { s->failed_pc=0x0c0c0918u; return 0; }
r[2]=read(ram,r[7]+8,4);
goto P_0c0c091a;
P_0c0c091a: /* original d310, guest PC 0x0c0c091a */
if(!s->budget--) { s->failed_pc=0x0c0c091au; return 0; }
r[3]=read(ram,0x0c0c095cu,4);
goto P_0c0c091c;
P_0c0c091c: /* original 2238, guest PC 0x0c0c091c */
if(!s->budget--) { s->failed_pc=0x0c0c091cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c091e;
P_0c0c091e: /* original 8941, guest PC 0x0c0c091e */
if(!s->budget--) { s->failed_pc=0x0c0c091eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09a4; }
goto P_0c0c0920;
P_0c0c0920: /* original a040, guest PC 0x0c0c0920 */
if(!s->budget--) { s->failed_pc=0x0c0c0920u; return 0; }
r[9]=r[12];
goto P_0c0c09a4;
P_0c0c0922: /* original 69c3, guest PC 0x0c0c0922 */
if(!s->budget--) { s->failed_pc=0x0c0c0922u; return 0; }
r[9]=r[12];
goto P_0c0c0924;
P_0c0c0924: /* original 8811, guest PC 0x0c0c0924 */
if(!s->budget--) { s->failed_pc=0x0c0c0924u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000011u)!=0);
goto P_0c0c0926;
P_0c0c0926: /* original 8b01, guest PC 0x0c0c0926 */
if(!s->budget--) { s->failed_pc=0x0c0c0926u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c092c; }
goto P_0c0c0928;
P_0c0c0928: /* original a001, guest PC 0x0c0c0928 */
if(!s->budget--) { s->failed_pc=0x0c0c0928u; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0c092e;
P_0c0c092a: /* original 1fd2, guest PC 0x0c0c092a */
if(!s->budget--) { s->failed_pc=0x0c0c092au; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0c092c;
P_0c0c092c: /* original 1fc2, guest PC 0x0c0c092c */
if(!s->budget--) { s->failed_pc=0x0c0c092cu; return 0; }
write(ram,r[15]+8,r[12],4);
goto P_0c0c092e;
P_0c0c092e: /* original 60a3, guest PC 0x0c0c092e */
if(!s->budget--) { s->failed_pc=0x0c0c092eu; return 0; }
r[0]=r[10];
goto P_0c0c0930;
P_0c0c0930: /* original 8813, guest PC 0x0c0c0930 */
if(!s->budget--) { s->failed_pc=0x0c0c0930u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000013u)!=0);
goto P_0c0c0932;
P_0c0c0932: /* original 8b01, guest PC 0x0c0c0932 */
if(!s->budget--) { s->failed_pc=0x0c0c0932u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0938; }
goto P_0c0c0934;
P_0c0c0934: /* original a001, guest PC 0x0c0c0934 */
if(!s->budget--) { s->failed_pc=0x0c0c0934u; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0c093a;
P_0c0c0936: /* original 1fd3, guest PC 0x0c0c0936 */
if(!s->budget--) { s->failed_pc=0x0c0c0936u; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0c0938;
P_0c0c0938: /* original 1fc3, guest PC 0x0c0c0938 */
if(!s->budget--) { s->failed_pc=0x0c0c0938u; return 0; }
write(ram,r[15]+12,r[12],4);
goto P_0c0c093a;
P_0c0c093a: /* original 60a3, guest PC 0x0c0c093a */
if(!s->budget--) { s->failed_pc=0x0c0c093au; return 0; }
r[0]=r[10];
goto P_0c0c093c;
P_0c0c093c: /* original 8804, guest PC 0x0c0c093c */
if(!s->budget--) { s->failed_pc=0x0c0c093cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c093e;
P_0c0c093e: /* original 8b01, guest PC 0x0c0c093e */
if(!s->budget--) { s->failed_pc=0x0c0c093eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0944; }
goto P_0c0c0940;
P_0c0c0940: /* original a001, guest PC 0x0c0c0940 */
if(!s->budget--) { s->failed_pc=0x0c0c0940u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0c0946;
P_0c0c0942: /* original 2fd2, guest PC 0x0c0c0942 */
if(!s->budget--) { s->failed_pc=0x0c0c0942u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0c0944;
P_0c0c0944: /* original 2fc2, guest PC 0x0c0c0944 */
if(!s->budget--) { s->failed_pc=0x0c0c0944u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0c0946;
P_0c0c0946: /* original 60a3, guest PC 0x0c0c0946 */
if(!s->budget--) { s->failed_pc=0x0c0c0946u; return 0; }
r[0]=r[10];
goto P_0c0c0948;
P_0c0c0948: /* original 8806, guest PC 0x0c0c0948 */
if(!s->budget--) { s->failed_pc=0x0c0c0948u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c094a;
P_0c0c094a: /* original 8f09, guest PC 0x0c0c094a */
if(!s->budget--) { s->failed_pc=0x0c0c094au; return 0; }
cond=r[17]&1u;
r[14]=0x00000003u;
if(!cond) { goto P_0c0c0960; }
goto P_0c0c094e;
P_0c0c094c: /* original ee03, guest PC 0x0c0c094c */
if(!s->budget--) { s->failed_pc=0x0c0c094cu; return 0; }
r[14]=0x00000003u;
goto P_0c0c094e;
P_0c0c094e: /* original a008, guest PC 0x0c0c094e */
if(!s->budget--) { s->failed_pc=0x0c0c094eu; return 0; }
r[10]=r[13];
goto P_0c0c0962;
P_0c0c0950: /* original 6ad3, guest PC 0x0c0c0950 */
if(!s->budget--) { s->failed_pc=0x0c0c0950u; return 0; }
r[10]=r[13];
if(!vf3_matrix_family(0x0c0c0952u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c0952u; return 0; } return 1;
P_0c0c0960: /* original 6ac3, guest PC 0x0c0c0960 */
if(!s->budget--) { s->failed_pc=0x0c0c0960u; return 0; }
r[10]=r[12];
goto P_0c0c0962;
P_0c0c0962: /* original 53f2, guest PC 0x0c0c0962 */
if(!s->budget--) { s->failed_pc=0x0c0c0962u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c0964;
P_0c0c0964: /* original 2338, guest PC 0x0c0c0964 */
if(!s->budget--) { s->failed_pc=0x0c0c0964u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c0966;
P_0c0c0966: /* original 891d, guest PC 0x0c0c0966 */
if(!s->budget--) { s->failed_pc=0x0c0c0966u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09a4; }
goto P_0c0c0968;
P_0c0c0968: /* original 52f3, guest PC 0x0c0c0968 */
if(!s->budget--) { s->failed_pc=0x0c0c0968u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0c096a;
P_0c0c096a: /* original 2228, guest PC 0x0c0c096a */
if(!s->budget--) { s->failed_pc=0x0c0c096au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c096c;
P_0c0c096c: /* original 8d1a, guest PC 0x0c0c096c */
if(!s->budget--) { s->failed_pc=0x0c0c096cu; return 0; }
cond=r[17]&1u;
r[14]=0x00000002u;
if(cond) { goto P_0c0c09a4; }
goto P_0c0c0970;
P_0c0c096e: /* original ee02, guest PC 0x0c0c096e */
if(!s->budget--) { s->failed_pc=0x0c0c096eu; return 0; }
r[14]=0x00000002u;
goto P_0c0c0970;
P_0c0c0970: /* original 907d, guest PC 0x0c0c0970 */
if(!s->budget--) { s->failed_pc=0x0c0c0970u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a6eu,2);
goto P_0c0c0972;
P_0c0c0972: /* original 0ebe, guest PC 0x0c0c0972 */
if(!s->budget--) { s->failed_pc=0x0c0c0972u; return 0; }
r[14]=read(ram,r[11]+r[0],4);
goto P_0c0c0974;
P_0c0c0974: /* original 7004, guest PC 0x0c0c0974 */
if(!s->budget--) { s->failed_pc=0x0c0c0974u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0976;
P_0c0c0976: /* original 03be, guest PC 0x0c0c0976 */
if(!s->budget--) { s->failed_pc=0x0c0c0976u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c0c0978;
P_0c0c0978: /* original 7004, guest PC 0x0c0c0978 */
if(!s->budget--) { s->failed_pc=0x0c0c0978u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c097a;
P_0c0c097a: /* original 02bd, guest PC 0x0c0c097a */
if(!s->budget--) { s->failed_pc=0x0c0c097au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0c097c;
P_0c0c097c: /* original 70f8, guest PC 0x0c0c097c */
if(!s->budget--) { s->failed_pc=0x0c0c097cu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c097e;
P_0c0c097e: /* original 0e37, guest PC 0x0c0c097e */
if(!s->budget--) { s->failed_pc=0x0c0c097eu; return 0; }
r[19]=r[14]*r[3];
goto P_0c0c0980;
P_0c0c0980: /* original 0e1a, guest PC 0x0c0c0980 */
if(!s->budget--) { s->failed_pc=0x0c0c0980u; return 0; }
r[14]=r[19];
goto P_0c0c0982;
P_0c0c0982: /* original 3e2c, guest PC 0x0c0c0982 */
if(!s->budget--) { s->failed_pc=0x0c0c0982u; return 0; }
r[14]+=r[2];
goto P_0c0c0984;
P_0c0c0984: /* original 0be6, guest PC 0x0c0c0984 */
if(!s->budget--) { s->failed_pc=0x0c0c0984u; return 0; }
write(ram,r[11]+r[0],r[14],4);
goto P_0c0c0986;
P_0c0c0986: /* original 4e29, guest PC 0x0c0c0986 */
if(!s->budget--) { s->failed_pc=0x0c0c0986u; return 0; }
r[14]>>=16;
goto P_0c0c0988;
P_0c0c0988: /* original 9372, guest PC 0x0c0c0988 */
if(!s->budget--) { s->failed_pc=0x0c0c0988u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a70u,2);
goto P_0c0c098a;
P_0c0c098a: /* original 6eef, guest PC 0x0c0c098a */
if(!s->budget--) { s->failed_pc=0x0c0c098au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c098c;
P_0c0c098c: /* original d23e, guest PC 0x0c0c098c */
if(!s->budget--) { s->failed_pc=0x0c0c098cu; return 0; }
r[2]=read(ram,0x0c0c0a88u,4);
goto P_0c0c098e;
P_0c0c098e: /* original e002, guest PC 0x0c0c098e */
if(!s->budget--) { s->failed_pc=0x0c0c098eu; return 0; }
r[0]=0x00000002u;
goto P_0c0c0990;
P_0c0c0990: /* original 2e39, guest PC 0x0c0c0990 */
if(!s->budget--) { s->failed_pc=0x0c0c0990u; return 0; }
r[14]&=r[3];
goto P_0c0c0992;
P_0c0c0992: /* original 420b, guest PC 0x0c0c0992 */
if(!s->budget--) { s->failed_pc=0x0c0c0992u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c0996u;
r[1]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c0996u) { target=s->pc; goto dispatch; }
goto P_0c0c0996;
P_0c0c0994: /* original 61e3, guest PC 0x0c0c0994 */
if(!s->budget--) { s->failed_pc=0x0c0c0994u; return 0; }
r[1]=r[14];
goto P_0c0c0996;
P_0c0c0996: /* original 61f2, guest PC 0x0c0c0996 */
if(!s->budget--) { s->failed_pc=0x0c0c0996u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0c0998;
P_0c0c0998: /* original 6e03, guest PC 0x0c0c0998 */
if(!s->budget--) { s->failed_pc=0x0c0c0998u; return 0; }
r[14]=r[0];
goto P_0c0c099a;
P_0c0c099a: /* original 2118, guest PC 0x0c0c099a */
if(!s->budget--) { s->failed_pc=0x0c0c099au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c099c;
P_0c0c099c: /* original 8902, guest PC 0x0c0c099c */
if(!s->budget--) { s->failed_pc=0x0c0c099cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09a4; }
goto P_0c0c099e;
P_0c0c099e: /* original 2aa8, guest PC 0x0c0c099e */
if(!s->budget--) { s->failed_pc=0x0c0c099eu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c09a0;
P_0c0c09a0: /* original 8900, guest PC 0x0c0c09a0 */
if(!s->budget--) { s->failed_pc=0x0c0c09a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09a4; }
goto P_0c0c09a2;
P_0c0c09a2: /* original 6ed3, guest PC 0x0c0c09a2 */
if(!s->budget--) { s->failed_pc=0x0c0c09a2u; return 0; }
r[14]=r[13];
goto P_0c0c09a4;
P_0c0c09a4: /* original 53b5, guest PC 0x0c0c09a4 */
if(!s->budget--) { s->failed_pc=0x0c0c09a4u; return 0; }
r[3]=read(ram,r[11]+20,4);
goto P_0c0c09a6;
P_0c0c09a6: /* original 6133, guest PC 0x0c0c09a6 */
if(!s->budget--) { s->failed_pc=0x0c0c09a6u; return 0; }
r[1]=r[3];
goto P_0c0c09a8;
P_0c0c09a8: /* original 2f32, guest PC 0x0c0c09a8 */
if(!s->budget--) { s->failed_pc=0x0c0c09a8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c09aa;
P_0c0c09aa: /* original 9262, guest PC 0x0c0c09aa */
if(!s->budget--) { s->failed_pc=0x0c0c09aau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a72u,2);
goto P_0c0c09ac;
P_0c0c09ac: /* original 3127, guest PC 0x0c0c09ac */
if(!s->budget--) { s->failed_pc=0x0c0c09acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c0c09ae;
P_0c0c09ae: /* original 8917, guest PC 0x0c0c09ae */
if(!s->budget--) { s->failed_pc=0x0c0c09aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09e0; }
goto P_0c0c09b0;
P_0c0c09b0: /* original e046, guest PC 0x0c0c09b0 */
if(!s->budget--) { s->failed_pc=0x0c0c09b0u; return 0; }
r[0]=0x00000046u;
goto P_0c0c09b2;
P_0c0c09b2: /* original 066d, guest PC 0x0c0c09b2 */
if(!s->budget--) { s->failed_pc=0x0c0c09b2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c0c09b4;
P_0c0c09b4: /* original 0d5d, guest PC 0x0c0c09b4 */
if(!s->budget--) { s->failed_pc=0x0c0c09b4u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0c09b6;
P_0c0c09b6: /* original 666d, guest PC 0x0c0c09b6 */
if(!s->budget--) { s->failed_pc=0x0c0c09b6u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0c09b8;
P_0c0c09b8: /* original 6ddd, guest PC 0x0c0c09b8 */
if(!s->budget--) { s->failed_pc=0x0c0c09b8u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0c09ba;
P_0c0c09ba: /* original 3d67, guest PC 0x0c0c09ba */
if(!s->budget--) { s->failed_pc=0x0c0c09bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[6])!=0);
goto P_0c0c09bc;
P_0c0c09bc: /* original 8905, guest PC 0x0c0c09bc */
if(!s->budget--) { s->failed_pc=0x0c0c09bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09ca; }
goto P_0c0c09be;
P_0c0c09be: /* original 6363, guest PC 0x0c0c09be */
if(!s->budget--) { s->failed_pc=0x0c0c09beu; return 0; }
r[3]=r[6];
goto P_0c0c09c0;
P_0c0c09c0: /* original 33d8, guest PC 0x0c0c09c0 */
if(!s->budget--) { s->failed_pc=0x0c0c09c0u; return 0; }
r[3]-=r[13];
goto P_0c0c09c2;
P_0c0c09c2: /* original e20a, guest PC 0x0c0c09c2 */
if(!s->budget--) { s->failed_pc=0x0c0c09c2u; return 0; }
r[2]=0x0000000au;
goto P_0c0c09c4;
P_0c0c09c4: /* original 6d33, guest PC 0x0c0c09c4 */
if(!s->budget--) { s->failed_pc=0x0c0c09c4u; return 0; }
r[13]=r[3];
goto P_0c0c09c6;
P_0c0c09c6: /* original 3d23, guest PC 0x0c0c09c6 */
if(!s->budget--) { s->failed_pc=0x0c0c09c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[2])!=0);
goto P_0c0c09c8;
P_0c0c09c8: /* original 890a, guest PC 0x0c0c09c8 */
if(!s->budget--) { s->failed_pc=0x0c0c09c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09e0; }
goto P_0c0c09ca;
P_0c0c09ca: /* original 1fc1, guest PC 0x0c0c09ca */
if(!s->budget--) { s->failed_pc=0x0c0c09cau; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c0c09cc;
P_0c0c09cc: /* original 5378, guest PC 0x0c0c09cc */
if(!s->budget--) { s->failed_pc=0x0c0c09ccu; return 0; }
r[3]=read(ram,r[7]+32,4);
goto P_0c0c09ce;
P_0c0c09ce: /* original 23c8, guest PC 0x0c0c09ce */
if(!s->budget--) { s->failed_pc=0x0c0c09ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0c09d0;
P_0c0c09d0: /* original 8902, guest PC 0x0c0c09d0 */
if(!s->budget--) { s->failed_pc=0x0c0c09d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09d8; }
goto P_0c0c09d2;
P_0c0c09d2: /* original e202, guest PC 0x0c0c09d2 */
if(!s->budget--) { s->failed_pc=0x0c0c09d2u; return 0; }
r[2]=0x00000002u;
goto P_0c0c09d4;
P_0c0c09d4: /* original 7e01, guest PC 0x0c0c09d4 */
if(!s->budget--) { s->failed_pc=0x0c0c09d4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c09d6;
P_0c0c09d6: /* original 1f21, guest PC 0x0c0c09d6 */
if(!s->budget--) { s->failed_pc=0x0c0c09d6u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0c09d8;
P_0c0c09d8: /* original 5373, guest PC 0x0c0c09d8 */
if(!s->budget--) { s->failed_pc=0x0c0c09d8u; return 0; }
r[3]=read(ram,r[7]+12,4);
goto P_0c0c09da;
P_0c0c09da: /* original 2388, guest PC 0x0c0c09da */
if(!s->budget--) { s->failed_pc=0x0c0c09dau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0c09dc;
P_0c0c09dc: /* original 8904, guest PC 0x0c0c09dc */
if(!s->budget--) { s->failed_pc=0x0c0c09dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09e8; }
goto P_0c0c09de;
P_0c0c09de: /* original 7e01, guest PC 0x0c0c09de */
if(!s->budget--) { s->failed_pc=0x0c0c09deu; return 0; }
r[14]+=0x00000001u;
goto P_0c0c09e0;
P_0c0c09e0: /* original 5373, guest PC 0x0c0c09e0 */
if(!s->budget--) { s->failed_pc=0x0c0c09e0u; return 0; }
r[3]=read(ram,r[7]+12,4);
goto P_0c0c09e2;
P_0c0c09e2: /* original 2388, guest PC 0x0c0c09e2 */
if(!s->budget--) { s->failed_pc=0x0c0c09e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0c09e4;
P_0c0c09e4: /* original 8900, guest PC 0x0c0c09e4 */
if(!s->budget--) { s->failed_pc=0x0c0c09e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c09e8; }
goto P_0c0c09e6;
P_0c0c09e6: /* original 7e01, guest PC 0x0c0c09e6 */
if(!s->budget--) { s->failed_pc=0x0c0c09e6u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c09e8;
P_0c0c09e8: /* original 53f1, guest PC 0x0c0c09e8 */
if(!s->budget--) { s->failed_pc=0x0c0c09e8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c09ea;
P_0c0c09ea: /* original 39ec, guest PC 0x0c0c09ea */
if(!s->budget--) { s->failed_pc=0x0c0c09eau; return 0; }
r[9]+=r[14];
goto P_0c0c09ec;
P_0c0c09ec: /* original 9042, guest PC 0x0c0c09ec */
if(!s->budget--) { s->failed_pc=0x0c0c09ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a74u,2);
goto P_0c0c09ee;
P_0c0c09ee: /* original 493c, guest PC 0x0c0c09ee */
if(!s->budget--) { s->failed_pc=0x0c0c09eeu; return 0; }
r[9]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[9]>>((-r[3])&31u)):((int32_t)r[9]<0?0xffffffffu:0)):r[9]<<(r[3]&31u);
goto P_0c0c09f0;
P_0c0c09f0: /* original 034d, guest PC 0x0c0c09f0 */
if(!s->budget--) { s->failed_pc=0x0c0c09f0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c09f2;
P_0c0c09f2: /* original 339c, guest PC 0x0c0c09f2 */
if(!s->budget--) { s->failed_pc=0x0c0c09f2u; return 0; }
r[3]+=r[9];
goto P_0c0c09f4;
P_0c0c09f4: /* original 0435, guest PC 0x0c0c09f4 */
if(!s->budget--) { s->failed_pc=0x0c0c09f4u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0c09f6;
P_0c0c09f6: /* original 5273, guest PC 0x0c0c09f6 */
if(!s->budget--) { s->failed_pc=0x0c0c09f6u; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c0c09f8;
P_0c0c09f8: /* original d324, guest PC 0x0c0c09f8 */
if(!s->budget--) { s->failed_pc=0x0c0c09f8u; return 0; }
r[3]=read(ram,0x0c0c0a8cu,4);
goto P_0c0c09fa;
P_0c0c09fa: /* original 2238, guest PC 0x0c0c09fa */
if(!s->budget--) { s->failed_pc=0x0c0c09fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c09fc;
P_0c0c09fc: /* original 890e, guest PC 0x0c0c09fc */
if(!s->budget--) { s->failed_pc=0x0c0c09fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0a1c; }
goto P_0c0c09fe;
P_0c0c09fe: /* original 903a, guest PC 0x0c0c09fe */
if(!s->budget--) { s->failed_pc=0x0c0c09feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a76u,2);
goto P_0c0c0a00;
P_0c0c0a00: /* original f29d, guest PC 0x0c0c0a00 */
if(!s->budget--) { s->failed_pc=0x0c0c0a00u; return 0; }
fr[2]=0x3f800000u;
goto P_0c0c0a02;
P_0c0c0a02: /* original f346, guest PC 0x0c0c0a02 */
if(!s->budget--) { s->failed_pc=0x0c0c0a02u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c0a04;
P_0c0c0a04: /* original f320, guest PC 0x0c0c0a04 */
if(!s->budget--) { s->failed_pc=0x0c0c0a04u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0a06;
P_0c0c0a06: /* original f437, guest PC 0x0c0c0a06 */
if(!s->budget--) { s->failed_pc=0x0c0c0a06u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0c0a08;
P_0c0c0a08: /* original 9036, guest PC 0x0c0c0a08 */
if(!s->budget--) { s->failed_pc=0x0c0c0a08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a78u,2);
goto P_0c0c0a0a;
P_0c0c0a0a: /* original 9236, guest PC 0x0c0c0a0a */
if(!s->budget--) { s->failed_pc=0x0c0c0a0au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a7au,2);
goto P_0c0c0a0c;
P_0c0c0a0c: /* original 035c, guest PC 0x0c0c0a0c */
if(!s->budget--) { s->failed_pc=0x0c0c0a0cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c0a0e;
P_0c0c0a0e: /* original 324c, guest PC 0x0c0c0a0e */
if(!s->budget--) { s->failed_pc=0x0c0c0a0eu; return 0; }
r[2]+=r[4];
goto P_0c0c0a10;
P_0c0c0a10: /* original 633c, guest PC 0x0c0c0a10 */
if(!s->budget--) { s->failed_pc=0x0c0c0a10u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c0a12;
P_0c0c0a12: /* original 4308, guest PC 0x0c0c0a12 */
if(!s->budget--) { s->failed_pc=0x0c0c0a12u; return 0; }
r[3]<<=2;
goto P_0c0c0a14;
P_0c0c0a14: /* original 332c, guest PC 0x0c0c0a14 */
if(!s->budget--) { s->failed_pc=0x0c0c0a14u; return 0; }
r[3]+=r[2];
goto P_0c0c0a16;
P_0c0c0a16: /* original f338, guest PC 0x0c0c0a16 */
if(!s->budget--) { s->failed_pc=0x0c0c0a16u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0c0a18;
P_0c0c0a18: /* original f320, guest PC 0x0c0c0a18 */
if(!s->budget--) { s->failed_pc=0x0c0c0a18u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0a1a;
P_0c0c0a1a: /* original f33a, guest PC 0x0c0c0a1a */
if(!s->budget--) { s->failed_pc=0x0c0c0a1au; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0c0a1c;
P_0c0c0a1c: /* original 5273, guest PC 0x0c0c0a1c */
if(!s->budget--) { s->failed_pc=0x0c0c0a1cu; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c0c0a1e;
P_0c0c0a1e: /* original d31c, guest PC 0x0c0c0a1e */
if(!s->budget--) { s->failed_pc=0x0c0c0a1eu; return 0; }
r[3]=read(ram,0x0c0c0a90u,4);
goto P_0c0c0a20;
P_0c0c0a20: /* original 2238, guest PC 0x0c0c0a20 */
if(!s->budget--) { s->failed_pc=0x0c0c0a20u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c0a22;
P_0c0c0a22: /* original 894f, guest PC 0x0c0c0a22 */
if(!s->budget--) { s->failed_pc=0x0c0c0a22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0ac4; }
goto P_0c0c0a24;
P_0c0c0a24: /* original 902a, guest PC 0x0c0c0a24 */
if(!s->budget--) { s->failed_pc=0x0c0c0a24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a7cu,2);
goto P_0c0c0a26;
P_0c0c0a26: /* original f29d, guest PC 0x0c0c0a26 */
if(!s->budget--) { s->failed_pc=0x0c0c0a26u; return 0; }
fr[2]=0x3f800000u;
goto P_0c0c0a28;
P_0c0c0a28: /* original 065e, guest PC 0x0c0c0a28 */
if(!s->budget--) { s->failed_pc=0x0c0c0a28u; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c0c0a2a;
P_0c0c0a2a: /* original 9028, guest PC 0x0c0c0a2a */
if(!s->budget--) { s->failed_pc=0x0c0c0a2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a7eu,2);
goto P_0c0c0a2c;
P_0c0c0a2c: /* original f346, guest PC 0x0c0c0a2c */
if(!s->budget--) { s->failed_pc=0x0c0c0a2cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c0a2e;
P_0c0c0a2e: /* original f320, guest PC 0x0c0c0a2e */
if(!s->budget--) { s->failed_pc=0x0c0c0a2eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0a30;
P_0c0c0a30: /* original f437, guest PC 0x0c0c0a30 */
if(!s->budget--) { s->failed_pc=0x0c0c0a30u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0c0a32;
P_0c0c0a32: /* original 9021, guest PC 0x0c0c0a32 */
if(!s->budget--) { s->failed_pc=0x0c0c0a32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a78u,2);
goto P_0c0c0a34;
P_0c0c0a34: /* original 9224, guest PC 0x0c0c0a34 */
if(!s->budget--) { s->failed_pc=0x0c0c0a34u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a80u,2);
goto P_0c0c0a36;
P_0c0c0a36: /* original 035c, guest PC 0x0c0c0a36 */
if(!s->budget--) { s->failed_pc=0x0c0c0a36u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c0a38;
P_0c0c0a38: /* original 324c, guest PC 0x0c0c0a38 */
if(!s->budget--) { s->failed_pc=0x0c0c0a38u; return 0; }
r[2]+=r[4];
goto P_0c0c0a3a;
P_0c0c0a3a: /* original 633c, guest PC 0x0c0c0a3a */
if(!s->budget--) { s->failed_pc=0x0c0c0a3au; return 0; }
r[3]=r[3]&255u;
goto P_0c0c0a3c;
P_0c0c0a3c: /* original 4308, guest PC 0x0c0c0a3c */
if(!s->budget--) { s->failed_pc=0x0c0c0a3cu; return 0; }
r[3]<<=2;
goto P_0c0c0a3e;
P_0c0c0a3e: /* original 332c, guest PC 0x0c0c0a3e */
if(!s->budget--) { s->failed_pc=0x0c0c0a3eu; return 0; }
r[3]+=r[2];
goto P_0c0c0a40;
P_0c0c0a40: /* original f338, guest PC 0x0c0c0a40 */
if(!s->budget--) { s->failed_pc=0x0c0c0a40u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0c0a42;
P_0c0c0a42: /* original f320, guest PC 0x0c0c0a42 */
if(!s->budget--) { s->failed_pc=0x0c0c0a42u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0a44;
P_0c0c0a44: /* original f33a, guest PC 0x0c0c0a44 */
if(!s->budget--) { s->failed_pc=0x0c0c0a44u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0c0a46;
P_0c0c0a46: /* original e304, guest PC 0x0c0c0a46 */
if(!s->budget--) { s->failed_pc=0x0c0c0a46u; return 0; }
r[3]=0x00000004u;
goto P_0c0c0a48;
P_0c0c0a48: /* original 2368, guest PC 0x0c0c0a48 */
if(!s->budget--) { s->failed_pc=0x0c0c0a48u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c0a4a;
P_0c0c0a4a: /* original 8923, guest PC 0x0c0c0a4a */
if(!s->budget--) { s->failed_pc=0x0c0c0a4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0a94; }
goto P_0c0c0a4c;
P_0c0c0a4c: /* original 9019, guest PC 0x0c0c0a4c */
if(!s->budget--) { s->failed_pc=0x0c0c0a4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a82u,2);
goto P_0c0c0a4e;
P_0c0c0a4e: /* original f29d, guest PC 0x0c0c0a4e */
if(!s->budget--) { s->failed_pc=0x0c0c0a4eu; return 0; }
fr[2]=0x3f800000u;
goto P_0c0c0a50;
P_0c0c0a50: /* original f346, guest PC 0x0c0c0a50 */
if(!s->budget--) { s->failed_pc=0x0c0c0a50u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c0a52;
P_0c0c0a52: /* original f320, guest PC 0x0c0c0a52 */
if(!s->budget--) { s->failed_pc=0x0c0c0a52u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0a54;
P_0c0c0a54: /* original f437, guest PC 0x0c0c0a54 */
if(!s->budget--) { s->failed_pc=0x0c0c0a54u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0c0a56;
P_0c0c0a56: /* original 900f, guest PC 0x0c0c0a56 */
if(!s->budget--) { s->failed_pc=0x0c0c0a56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a78u,2);
goto P_0c0c0a58;
P_0c0c0a58: /* original 9214, guest PC 0x0c0c0a58 */
if(!s->budget--) { s->failed_pc=0x0c0c0a58u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0a84u,2);
goto P_0c0c0a5a;
P_0c0c0a5a: /* original 035c, guest PC 0x0c0c0a5a */
if(!s->budget--) { s->failed_pc=0x0c0c0a5au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c0a5c;
P_0c0c0a5c: /* original 324c, guest PC 0x0c0c0a5c */
if(!s->budget--) { s->failed_pc=0x0c0c0a5cu; return 0; }
r[2]+=r[4];
goto P_0c0c0a5e;
P_0c0c0a5e: /* original 633c, guest PC 0x0c0c0a5e */
if(!s->budget--) { s->failed_pc=0x0c0c0a5eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c0a60;
P_0c0c0a60: /* original 4308, guest PC 0x0c0c0a60 */
if(!s->budget--) { s->failed_pc=0x0c0c0a60u; return 0; }
r[3]<<=2;
goto P_0c0c0a62;
P_0c0c0a62: /* original 332c, guest PC 0x0c0c0a62 */
if(!s->budget--) { s->failed_pc=0x0c0c0a62u; return 0; }
r[3]+=r[2];
goto P_0c0c0a64;
P_0c0c0a64: /* original f338, guest PC 0x0c0c0a64 */
if(!s->budget--) { s->failed_pc=0x0c0c0a64u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0c0a66;
P_0c0c0a66: /* original f320, guest PC 0x0c0c0a66 */
if(!s->budget--) { s->failed_pc=0x0c0c0a66u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0a68;
P_0c0c0a68: /* original f33a, guest PC 0x0c0c0a68 */
if(!s->budget--) { s->failed_pc=0x0c0c0a68u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0c0a6a;
P_0c0c0a6a: /* original a04f, guest PC 0x0c0c0a6a */
if(!s->budget--) { s->failed_pc=0x0c0c0a6au; return 0; }
goto P_0c0c0b0c;
P_0c0c0a6c: /* original 0009, guest PC 0x0c0c0a6c */
if(!s->budget--) { s->failed_pc=0x0c0c0a6cu; return 0; }
if(!vf3_matrix_family(0x0c0c0a6eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c0a6eu; return 0; } return 1;
P_0c0c0a94: /* original 9312, guest PC 0x0c0c0a94 */
if(!s->budget--) { s->failed_pc=0x0c0c0a94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0abcu,2);
goto P_0c0c0a96;
P_0c0c0a96: /* original 2638, guest PC 0x0c0c0a96 */
if(!s->budget--) { s->failed_pc=0x0c0c0a96u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0c0a98;
P_0c0c0a98: /* original 8938, guest PC 0x0c0c0a98 */
if(!s->budget--) { s->failed_pc=0x0c0c0a98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0b0c; }
goto P_0c0c0a9a;
P_0c0c0a9a: /* original 9010, guest PC 0x0c0c0a9a */
if(!s->budget--) { s->failed_pc=0x0c0c0a9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0abeu,2);
goto P_0c0c0a9c;
P_0c0c0a9c: /* original f29d, guest PC 0x0c0c0a9c */
if(!s->budget--) { s->failed_pc=0x0c0c0a9cu; return 0; }
fr[2]=0x3f800000u;
goto P_0c0c0a9e;
P_0c0c0a9e: /* original f346, guest PC 0x0c0c0a9e */
if(!s->budget--) { s->failed_pc=0x0c0c0a9eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c0aa0;
P_0c0c0aa0: /* original f320, guest PC 0x0c0c0aa0 */
if(!s->budget--) { s->failed_pc=0x0c0c0aa0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0aa2;
P_0c0c0aa2: /* original f437, guest PC 0x0c0c0aa2 */
if(!s->budget--) { s->failed_pc=0x0c0c0aa2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0c0aa4;
P_0c0c0aa4: /* original 900c, guest PC 0x0c0c0aa4 */
if(!s->budget--) { s->failed_pc=0x0c0c0aa4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0ac0u,2);
goto P_0c0c0aa6;
P_0c0c0aa6: /* original 920c, guest PC 0x0c0c0aa6 */
if(!s->budget--) { s->failed_pc=0x0c0c0aa6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0ac2u,2);
goto P_0c0c0aa8;
P_0c0c0aa8: /* original 035c, guest PC 0x0c0c0aa8 */
if(!s->budget--) { s->failed_pc=0x0c0c0aa8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c0aaa;
P_0c0c0aaa: /* original 324c, guest PC 0x0c0c0aaa */
if(!s->budget--) { s->failed_pc=0x0c0c0aaau; return 0; }
r[2]+=r[4];
goto P_0c0c0aac;
P_0c0c0aac: /* original 633c, guest PC 0x0c0c0aac */
if(!s->budget--) { s->failed_pc=0x0c0c0aacu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c0aae;
P_0c0c0aae: /* original 4308, guest PC 0x0c0c0aae */
if(!s->budget--) { s->failed_pc=0x0c0c0aaeu; return 0; }
r[3]<<=2;
goto P_0c0c0ab0;
P_0c0c0ab0: /* original 332c, guest PC 0x0c0c0ab0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ab0u; return 0; }
r[3]+=r[2];
goto P_0c0c0ab2;
P_0c0c0ab2: /* original f338, guest PC 0x0c0c0ab2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ab2u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0c0ab4;
P_0c0c0ab4: /* original f320, guest PC 0x0c0c0ab4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ab4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0ab6;
P_0c0c0ab6: /* original f33a, guest PC 0x0c0c0ab6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ab6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0c0ab8;
P_0c0c0ab8: /* original a028, guest PC 0x0c0c0ab8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ab8u; return 0; }
goto P_0c0c0b0c;
P_0c0c0aba: /* original 0009, guest PC 0x0c0c0aba */
if(!s->budget--) { s->failed_pc=0x0c0c0abau; return 0; }
if(!vf3_matrix_family(0x0c0c0abcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c0abcu; return 0; } return 1;
P_0c0c0ac4: /* original 5273, guest PC 0x0c0c0ac4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ac4u; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c0c0ac6;
P_0c0c0ac6: /* original d346, guest PC 0x0c0c0ac6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ac6u; return 0; }
r[3]=read(ram,0x0c0c0be0u,4);
goto P_0c0c0ac8;
P_0c0c0ac8: /* original 2238, guest PC 0x0c0c0ac8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ac8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c0aca;
P_0c0c0aca: /* original 890c, guest PC 0x0c0c0aca */
if(!s->budget--) { s->failed_pc=0x0c0c0acau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0ae6; }
goto P_0c0c0acc;
P_0c0c0acc: /* original 907d, guest PC 0x0c0c0acc */
if(!s->budget--) { s->failed_pc=0x0c0c0accu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bcau,2);
goto P_0c0c0ace;
P_0c0c0ace: /* original e304, guest PC 0x0c0c0ace */
if(!s->budget--) { s->failed_pc=0x0c0c0aceu; return 0; }
r[3]=0x00000004u;
goto P_0c0c0ad0;
P_0c0c0ad0: /* original f29d, guest PC 0x0c0c0ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ad0u; return 0; }
fr[2]=0x3f800000u;
goto P_0c0c0ad2;
P_0c0c0ad2: /* original 23f8, guest PC 0x0c0c0ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ad2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[15])==0)!=0);
goto P_0c0c0ad4;
P_0c0c0ad4: /* original f346, guest PC 0x0c0c0ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ad4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c0ad6;
P_0c0c0ad6: /* original f320, guest PC 0x0c0c0ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ad6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0ad8;
P_0c0c0ad8: /* original 8d18, guest PC 0x0c0c0ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ad8u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[4]+r[0]);
if(cond) { goto P_0c0c0b0c; }
goto P_0c0c0adc;
P_0c0c0ada: /* original f437, guest PC 0x0c0c0ada */
if(!s->budget--) { s->failed_pc=0x0c0c0adau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0c0adc;
P_0c0c0adc: /* original 9076, guest PC 0x0c0c0adc */
if(!s->budget--) { s->failed_pc=0x0c0c0adcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bccu,2);
goto P_0c0c0ade;
P_0c0c0ade: /* original f29d, guest PC 0x0c0c0ade */
if(!s->budget--) { s->failed_pc=0x0c0c0adeu; return 0; }
fr[2]=0x3f800000u;
goto P_0c0c0ae0;
P_0c0c0ae0: /* original f346, guest PC 0x0c0c0ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ae0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c0ae2;
P_0c0c0ae2: /* original f320, guest PC 0x0c0c0ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ae2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0ae4;
P_0c0c0ae4: /* original f437, guest PC 0x0c0c0ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ae4u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0c0ae6;
P_0c0c0ae6: /* original 5273, guest PC 0x0c0c0ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ae6u; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c0c0ae8;
P_0c0c0ae8: /* original d33e, guest PC 0x0c0c0ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ae8u; return 0; }
r[3]=read(ram,0x0c0c0be4u,4);
goto P_0c0c0aea;
P_0c0c0aea: /* original 2238, guest PC 0x0c0c0aea */
if(!s->budget--) { s->failed_pc=0x0c0c0aeau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c0aec;
P_0c0c0aec: /* original 890e, guest PC 0x0c0c0aec */
if(!s->budget--) { s->failed_pc=0x0c0c0aecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0b0c; }
goto P_0c0c0aee;
P_0c0c0aee: /* original 906e, guest PC 0x0c0c0aee */
if(!s->budget--) { s->failed_pc=0x0c0c0aeeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bceu,2);
goto P_0c0c0af0;
P_0c0c0af0: /* original f29d, guest PC 0x0c0c0af0 */
if(!s->budget--) { s->failed_pc=0x0c0c0af0u; return 0; }
fr[2]=0x3f800000u;
goto P_0c0c0af2;
P_0c0c0af2: /* original f346, guest PC 0x0c0c0af2 */
if(!s->budget--) { s->failed_pc=0x0c0c0af2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c0af4;
P_0c0c0af4: /* original f320, guest PC 0x0c0c0af4 */
if(!s->budget--) { s->failed_pc=0x0c0c0af4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0af6;
P_0c0c0af6: /* original f437, guest PC 0x0c0c0af6 */
if(!s->budget--) { s->failed_pc=0x0c0c0af6u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0c0af8;
P_0c0c0af8: /* original 906a, guest PC 0x0c0c0af8 */
if(!s->budget--) { s->failed_pc=0x0c0c0af8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bd0u,2);
goto P_0c0c0afa;
P_0c0c0afa: /* original 926a, guest PC 0x0c0c0afa */
if(!s->budget--) { s->failed_pc=0x0c0c0afau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bd2u,2);
goto P_0c0c0afc;
P_0c0c0afc: /* original 035c, guest PC 0x0c0c0afc */
if(!s->budget--) { s->failed_pc=0x0c0c0afcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c0afe;
P_0c0c0afe: /* original 324c, guest PC 0x0c0c0afe */
if(!s->budget--) { s->failed_pc=0x0c0c0afeu; return 0; }
r[2]+=r[4];
goto P_0c0c0b00;
P_0c0c0b00: /* original 633c, guest PC 0x0c0c0b00 */
if(!s->budget--) { s->failed_pc=0x0c0c0b00u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c0b02;
P_0c0c0b02: /* original 4308, guest PC 0x0c0c0b02 */
if(!s->budget--) { s->failed_pc=0x0c0c0b02u; return 0; }
r[3]<<=2;
goto P_0c0c0b04;
P_0c0c0b04: /* original 332c, guest PC 0x0c0c0b04 */
if(!s->budget--) { s->failed_pc=0x0c0c0b04u; return 0; }
r[3]+=r[2];
goto P_0c0c0b06;
P_0c0c0b06: /* original f338, guest PC 0x0c0c0b06 */
if(!s->budget--) { s->failed_pc=0x0c0c0b06u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0c0b08;
P_0c0c0b08: /* original f320, guest PC 0x0c0c0b08 */
if(!s->budget--) { s->failed_pc=0x0c0c0b08u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c0b0a;
P_0c0c0b0a: /* original f33a, guest PC 0x0c0c0b0a */
if(!s->budget--) { s->failed_pc=0x0c0c0b0au; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0c0b0c;
P_0c0c0b0c: /* original 9062, guest PC 0x0c0c0b0c */
if(!s->budget--) { s->failed_pc=0x0c0c0b0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bd4u,2);
goto P_0c0c0b0e;
P_0c0c0b0e: /* original f38d, guest PC 0x0c0c0b0e */
if(!s->budget--) { s->failed_pc=0x0c0c0b0eu; return 0; }
fr[3]=0;
goto P_0c0c0b10;
P_0c0c0b10: /* original f446, guest PC 0x0c0c0b10 */
if(!s->budget--) { s->failed_pc=0x0c0c0b10u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0c0b12;
P_0c0c0b12: /* original f434, guest PC 0x0c0c0b12 */
if(!s->budget--) { s->failed_pc=0x0c0c0b12u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c0c0b14;
P_0c0c0b14: /* original 890a, guest PC 0x0c0c0b14 */
if(!s->budget--) { s->failed_pc=0x0c0c0b14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0b2c; }
goto P_0c0c0b16;
P_0c0c0b16: /* original 905e, guest PC 0x0c0c0b16 */
if(!s->budget--) { s->failed_pc=0x0c0c0b16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bd6u,2);
goto P_0c0c0b18;
P_0c0c0b18: /* original f546, guest PC 0x0c0c0b18 */
if(!s->budget--) { s->failed_pc=0x0c0c0b18u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0c0b1a;
P_0c0c0b1a: /* original 7004, guest PC 0x0c0c0b1a */
if(!s->budget--) { s->failed_pc=0x0c0c0b1au; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0b1c;
P_0c0c0b1c: /* original f646, guest PC 0x0c0c0b1c */
if(!s->budget--) { s->failed_pc=0x0c0c0b1cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0c0b1e;
P_0c0c0b1e: /* original 7014, guest PC 0x0c0c0b1e */
if(!s->budget--) { s->failed_pc=0x0c0c0b1eu; return 0; }
r[0]+=0x00000014u;
goto P_0c0c0b20;
P_0c0c0b20: /* original f746, guest PC 0x0c0c0b20 */
if(!s->budget--) { s->failed_pc=0x0c0c0b20u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0c0b22;
P_0c0c0b22: /* original 7014, guest PC 0x0c0c0b22 */
if(!s->budget--) { s->failed_pc=0x0c0c0b22u; return 0; }
r[0]+=0x00000014u;
goto P_0c0c0b24;
P_0c0c0b24: /* original f560, guest PC 0x0c0c0b24 */
if(!s->budget--) { s->failed_pc=0x0c0c0b24u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c0c0b26;
P_0c0c0b26: /* original f570, guest PC 0x0c0c0b26 */
if(!s->budget--) { s->failed_pc=0x0c0c0b26u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c0c0b28;
P_0c0c0b28: /* original f543, guest PC 0x0c0c0b28 */
if(!s->budget--) { s->failed_pc=0x0c0c0b28u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c0c0b2a;
P_0c0c0b2a: /* original f457, guest PC 0x0c0c0b2a */
if(!s->budget--) { s->failed_pc=0x0c0c0b2au; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0c0b2c;
P_0c0c0b2c: /* original 9054, guest PC 0x0c0c0b2c */
if(!s->budget--) { s->failed_pc=0x0c0c0b2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bd8u,2);
goto P_0c0c0b2e;
P_0c0c0b2e: /* original f38d, guest PC 0x0c0c0b2e */
if(!s->budget--) { s->failed_pc=0x0c0c0b2eu; return 0; }
fr[3]=0;
goto P_0c0c0b30;
P_0c0c0b30: /* original f546, guest PC 0x0c0c0b30 */
if(!s->budget--) { s->failed_pc=0x0c0c0b30u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0c0b32;
P_0c0c0b32: /* original 701c, guest PC 0x0c0c0b32 */
if(!s->budget--) { s->failed_pc=0x0c0c0b32u; return 0; }
r[0]+=0x0000001cu;
goto P_0c0c0b34;
P_0c0c0b34: /* original f646, guest PC 0x0c0c0b34 */
if(!s->budget--) { s->failed_pc=0x0c0c0b34u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0c0b36;
P_0c0c0b36: /* original f561, guest PC 0x0c0c0b36 */
if(!s->budget--) { s->failed_pc=0x0c0c0b36u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0c0b38;
P_0c0c0b38: /* original f534, guest PC 0x0c0c0b38 */
if(!s->budget--) { s->failed_pc=0x0c0c0b38u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c0c0b3a;
P_0c0c0b3a: /* original 8d08, guest PC 0x0c0c0b3a */
if(!s->budget--) { s->failed_pc=0x0c0c0b3au; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
if(cond) { goto P_0c0c0b4e; }
goto P_0c0c0b3e;
P_0c0c0b3c: /* original f461, guest PC 0x0c0c0b3c */
if(!s->budget--) { s->failed_pc=0x0c0c0b3cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0c0b3e;
P_0c0c0b3e: /* original 9046, guest PC 0x0c0c0b3e */
if(!s->budget--) { s->failed_pc=0x0c0c0b3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bceu,2);
goto P_0c0c0b40;
P_0c0c0b40: /* original f453, guest PC 0x0c0c0b40 */
if(!s->budget--) { s->failed_pc=0x0c0c0b40u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c0c0b42;
P_0c0c0b42: /* original f646, guest PC 0x0c0c0b42 */
if(!s->budget--) { s->failed_pc=0x0c0c0b42u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0c0b44;
P_0c0c0b44: /* original 7020, guest PC 0x0c0c0b44 */
if(!s->budget--) { s->failed_pc=0x0c0c0b44u; return 0; }
r[0]+=0x00000020u;
goto P_0c0c0b46;
P_0c0c0b46: /* original f653, guest PC 0x0c0c0b46 */
if(!s->budget--) { s->failed_pc=0x0c0c0b46u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'/');
goto P_0c0c0b48;
P_0c0c0b48: /* original f447, guest PC 0x0c0c0b48 */
if(!s->budget--) { s->failed_pc=0x0c0c0b48u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0c0b4a;
P_0c0c0b4a: /* original 7008, guest PC 0x0c0c0b4a */
if(!s->budget--) { s->failed_pc=0x0c0c0b4au; return 0; }
r[0]+=0x00000008u;
goto P_0c0c0b4c;
P_0c0c0b4c: /* original f467, guest PC 0x0c0c0b4c */
if(!s->budget--) { s->failed_pc=0x0c0c0b4cu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0c0b4e;
P_0c0c0b4e: /* original 5273, guest PC 0x0c0c0b4e */
if(!s->budget--) { s->failed_pc=0x0c0c0b4eu; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c0c0b50;
P_0c0c0b50: /* original d325, guest PC 0x0c0c0b50 */
if(!s->budget--) { s->failed_pc=0x0c0c0b50u; return 0; }
r[3]=read(ram,0x0c0c0be8u,4);
goto P_0c0c0b52;
P_0c0c0b52: /* original 2239, guest PC 0x0c0c0b52 */
if(!s->budget--) { s->failed_pc=0x0c0c0b52u; return 0; }
r[2]&=r[3];
goto P_0c0c0b54;
P_0c0c0b54: /* original 1723, guest PC 0x0c0c0b54 */
if(!s->budget--) { s->failed_pc=0x0c0c0b54u; return 0; }
write(ram,r[7]+12,r[2],4);
goto P_0c0c0b56;
P_0c0c0b56: /* original 9040, guest PC 0x0c0c0b56 */
if(!s->budget--) { s->failed_pc=0x0c0c0b56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bdau,2);
goto P_0c0c0b58;
P_0c0c0b58: /* original f546, guest PC 0x0c0c0b58 */
if(!s->budget--) { s->failed_pc=0x0c0c0b58u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0c0b5a;
P_0c0c0b5a: /* original c724, guest PC 0x0c0c0b5a */
if(!s->budget--) { s->failed_pc=0x0c0c0b5au; return 0; }
r[0]=code_base|0x000c0becu;
goto P_0c0c0b5c;
P_0c0c0b5c: /* original f408, guest PC 0x0c0c0b5c */
if(!s->budget--) { s->failed_pc=0x0c0c0b5cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c0b5e;
P_0c0c0b5e: /* original f455, guest PC 0x0c0c0b5e */
if(!s->budget--) { s->failed_pc=0x0c0c0b5eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0c0b60;
P_0c0c0b60: /* original 8d04, guest PC 0x0c0c0b60 */
if(!s->budget--) { s->failed_pc=0x0c0c0b60u; return 0; }
cond=r[17]&1u;
r[0]=0x00000051u;
if(cond) { goto P_0c0c0b6c; }
goto P_0c0c0b64;
P_0c0c0b62: /* original e051, guest PC 0x0c0c0b62 */
if(!s->budget--) { s->failed_pc=0x0c0c0b62u; return 0; }
r[0]=0x00000051u;
goto P_0c0c0b64;
P_0c0c0b64: /* original 5273, guest PC 0x0c0c0b64 */
if(!s->budget--) { s->failed_pc=0x0c0c0b64u; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c0c0b66;
P_0c0c0b66: /* original d322, guest PC 0x0c0c0b66 */
if(!s->budget--) { s->failed_pc=0x0c0c0b66u; return 0; }
r[3]=read(ram,0x0c0c0bf0u,4);
goto P_0c0c0b68;
P_0c0c0b68: /* original 223b, guest PC 0x0c0c0b68 */
if(!s->budget--) { s->failed_pc=0x0c0c0b68u; return 0; }
r[2]|=r[3];
goto P_0c0c0b6a;
P_0c0c0b6a: /* original 1723, guest PC 0x0c0c0b6a */
if(!s->budget--) { s->failed_pc=0x0c0c0b6au; return 0; }
write(ram,r[7]+12,r[2],4);
goto P_0c0c0b6c;
P_0c0c0b6c: /* original 5277, guest PC 0x0c0c0b6c */
if(!s->budget--) { s->failed_pc=0x0c0c0b6cu; return 0; }
r[2]=read(ram,r[7]+28,4);
goto P_0c0c0b6e;
P_0c0c0b6e: /* original 6543, guest PC 0x0c0c0b6e */
if(!s->budget--) { s->failed_pc=0x0c0c0b6eu; return 0; }
r[5]=r[4];
goto P_0c0c0b70;
P_0c0c0b70: /* original 9334, guest PC 0x0c0c0b70 */
if(!s->budget--) { s->failed_pc=0x0c0c0b70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bdcu,2);
goto P_0c0c0b72;
P_0c0c0b72: /* original 7554, guest PC 0x0c0c0b72 */
if(!s->budget--) { s->failed_pc=0x0c0c0b72u; return 0; }
r[5]+=0x00000054u;
goto P_0c0c0b74;
P_0c0c0b74: /* original 064c, guest PC 0x0c0c0b74 */
if(!s->budget--) { s->failed_pc=0x0c0c0b74u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c0b76;
P_0c0c0b76: /* original 3233, guest PC 0x0c0c0b76 */
if(!s->budget--) { s->failed_pc=0x0c0c0b76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0c0b78;
P_0c0c0b78: /* original 8d1c, guest PC 0x0c0c0b78 */
if(!s->budget--) { s->failed_pc=0x0c0c0b78u; return 0; }
cond=r[17]&1u;
r[13]=r[6];
if(cond) { goto P_0c0c0bb4; }
goto P_0c0c0b7c;
P_0c0c0b7a: /* original 6d63, guest PC 0x0c0c0b7a */
if(!s->budget--) { s->failed_pc=0x0c0c0b7au; return 0; }
r[13]=r[6];
goto P_0c0c0b7c;
P_0c0c0b7c: /* original 9e2f, guest PC 0x0c0c0b7c */
if(!s->budget--) { s->failed_pc=0x0c0c0b7cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bdeu,2);
goto P_0c0c0b7e;
P_0c0c0b7e: /* original 2668, guest PC 0x0c0c0b7e */
if(!s->budget--) { s->failed_pc=0x0c0c0b7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c0b80;
P_0c0c0b80: /* original 8908, guest PC 0x0c0c0b80 */
if(!s->budget--) { s->failed_pc=0x0c0c0b80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0b94; }
goto P_0c0c0b82;
P_0c0c0b82: /* original 6354, guest PC 0x0c0c0b82 */
if(!s->budget--) { s->failed_pc=0x0c0c0b82u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c0c0b84;
P_0c0c0b84: /* original 1f31, guest PC 0x0c0c0b84 */
if(!s->budget--) { s->failed_pc=0x0c0c0b84u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c0b86;
P_0c0c0b86: /* original 5277, guest PC 0x0c0c0b86 */
if(!s->budget--) { s->failed_pc=0x0c0c0b86u; return 0; }
r[2]=read(ram,r[7]+28,4);
goto P_0c0c0b88;
P_0c0c0b88: /* original 3230, guest PC 0x0c0c0b88 */
if(!s->budget--) { s->failed_pc=0x0c0c0b88u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0c0b8a;
P_0c0c0b8a: /* original 8909, guest PC 0x0c0c0b8a */
if(!s->budget--) { s->failed_pc=0x0c0c0b8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0ba0; }
goto P_0c0c0b8c;
P_0c0c0b8c: /* original 4d10, guest PC 0x0c0c0b8c */
if(!s->budget--) { s->failed_pc=0x0c0c0b8cu; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c0c0b8e;
P_0c0c0b8e: /* original 8bf8, guest PC 0x0c0c0b8e */
if(!s->budget--) { s->failed_pc=0x0c0c0b8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0b82; }
goto P_0c0c0b90;
P_0c0c0b90: /* original 36e3, guest PC 0x0c0c0b90 */
if(!s->budget--) { s->failed_pc=0x0c0c0b90u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[14])!=0);
goto P_0c0c0b92;
P_0c0c0b92: /* original 890f, guest PC 0x0c0c0b92 */
if(!s->budget--) { s->failed_pc=0x0c0c0b92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0bb4; }
goto P_0c0c0b94;
P_0c0c0b94: /* original 7601, guest PC 0x0c0c0b94 */
if(!s->budget--) { s->failed_pc=0x0c0c0b94u; return 0; }
r[6]+=0x00000001u;
goto P_0c0c0b96;
P_0c0c0b96: /* original e051, guest PC 0x0c0c0b96 */
if(!s->budget--) { s->failed_pc=0x0c0c0b96u; return 0; }
r[0]=0x00000051u;
goto P_0c0c0b98;
P_0c0c0b98: /* original 0464, guest PC 0x0c0c0b98 */
if(!s->budget--) { s->failed_pc=0x0c0c0b98u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0c0b9a;
P_0c0c0b9a: /* original 5377, guest PC 0x0c0c0b9a */
if(!s->budget--) { s->failed_pc=0x0c0c0b9au; return 0; }
r[3]=read(ram,r[7]+28,4);
goto P_0c0c0b9c;
P_0c0c0b9c: /* original 2530, guest PC 0x0c0c0b9c */
if(!s->budget--) { s->failed_pc=0x0c0c0b9cu; return 0; }
write(ram,r[5],r[3],1);
goto P_0c0c0b9e;
P_0c0c0b9e: /* original 7501, guest PC 0x0c0c0b9e */
if(!s->budget--) { s->failed_pc=0x0c0c0b9eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0c0ba0;
P_0c0c0ba0: /* original 6453, guest PC 0x0c0c0ba0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ba0u; return 0; }
r[4]=r[5];
goto P_0c0c0ba2;
P_0c0c0ba2: /* original 34ec, guest PC 0x0c0c0ba2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ba2u; return 0; }
r[4]+=r[14];
goto P_0c0c0ba4;
P_0c0c0ba4: /* original 6440, guest PC 0x0c0c0ba4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ba4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0c0ba6;
P_0c0c0ba6: /* original 9319, guest PC 0x0c0c0ba6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ba6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0bdcu,2);
goto P_0c0c0ba8;
P_0c0c0ba8: /* original 644c, guest PC 0x0c0c0ba8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ba8u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c0baa;
P_0c0c0baa: /* original 3430, guest PC 0x0c0c0baa */
if(!s->budget--) { s->failed_pc=0x0c0c0baau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0c0bac;
P_0c0c0bac: /* original 8902, guest PC 0x0c0c0bac */
if(!s->budget--) { s->failed_pc=0x0c0c0bacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0bb4; }
goto P_0c0c0bae;
P_0c0c0bae: /* original 35ec, guest PC 0x0c0c0bae */
if(!s->budget--) { s->failed_pc=0x0c0c0baeu; return 0; }
r[5]+=r[14];
goto P_0c0c0bb0;
P_0c0c0bb0: /* original 7401, guest PC 0x0c0c0bb0 */
if(!s->budget--) { s->failed_pc=0x0c0c0bb0u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c0bb2;
P_0c0c0bb2: /* original 2540, guest PC 0x0c0c0bb2 */
if(!s->budget--) { s->failed_pc=0x0c0c0bb2u; return 0; }
write(ram,r[5],r[4],1);
goto P_0c0c0bb4;
P_0c0c0bb4: /* original 7f10, guest PC 0x0c0c0bb4 */
if(!s->budget--) { s->failed_pc=0x0c0c0bb4u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c0bb6;
P_0c0c0bb6: /* original 4f16, guest PC 0x0c0c0bb6 */
if(!s->budget--) { s->failed_pc=0x0c0c0bb6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c0bb8;
P_0c0c0bb8: /* original 4f26, guest PC 0x0c0c0bb8 */
if(!s->budget--) { s->failed_pc=0x0c0c0bb8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c0bba;
P_0c0c0bba: /* original 68f6, guest PC 0x0c0c0bba */
if(!s->budget--) { s->failed_pc=0x0c0c0bbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c0bbc;
P_0c0c0bbc: /* original 69f6, guest PC 0x0c0c0bbc */
if(!s->budget--) { s->failed_pc=0x0c0c0bbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c0bbe;
P_0c0c0bbe: /* original 6af6, guest PC 0x0c0c0bbe */
if(!s->budget--) { s->failed_pc=0x0c0c0bbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c0bc0;
P_0c0c0bc0: /* original 6bf6, guest PC 0x0c0c0bc0 */
if(!s->budget--) { s->failed_pc=0x0c0c0bc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c0bc2;
P_0c0c0bc2: /* original 6cf6, guest PC 0x0c0c0bc2 */
if(!s->budget--) { s->failed_pc=0x0c0c0bc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c0bc4;
P_0c0c0bc4: /* original 6df6, guest PC 0x0c0c0bc4 */
if(!s->budget--) { s->failed_pc=0x0c0c0bc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c0bc6;
P_0c0c0bc6: /* original 000b, guest PC 0x0c0c0bc6 */
if(!s->budget--) { s->failed_pc=0x0c0c0bc6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c0bc8: /* original 6ef6, guest PC 0x0c0c0bc8 */
if(!s->budget--) { s->failed_pc=0x0c0c0bc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c0bcau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c0bcau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
